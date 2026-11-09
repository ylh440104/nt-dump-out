
===== __report_gsfailure @ 140001010 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== CrashVscEstablishCommunications @ 140001020 =====

int CrashVscEstablishCommunications(longlong param_1,int *param_2)

{
  short sVar1;
  code *pcVar2;
  int iVar3;
  uint uVar4;
  ulonglong uVar5;
  short *psVar6;
  int local_58 [3];
  short local_4c;
  int local_40;
  
  memset(local_58,0,0x40);
  local_58[1] = 1;
  local_58[0] = 7;
  iVar3 = CrashVscSendPacketSync(param_1,local_58);
  if (-1 < iVar3) {
    uVar5 = 0;
    psVar6 = &g_StorChannelSupportedVersions;
    do {
      sVar1 = *psVar6;
      memset(local_58,0,0x40);
      local_58[1] = 1;
      local_58[0] = 9;
      local_4c = sVar1;
      iVar3 = CrashVscSendPacketSync(param_1,local_58);
      if (-1 < iVar3) {
        if (local_4c == sVar1) {
          *(undefined2 *)(param_1 + 0x10) = (&DAT_1400095f2)[uVar5 * 4];
          *(undefined2 *)(param_1 + 0x12) = (&DAT_1400095f4)[uVar5 * 4];
          *(undefined1 *)(param_1 + 0x14) = (&DAT_1400095f6)[uVar5 * 8];
          memset(local_58,0,0x40);
          local_58[1] = 1;
          local_58[0] = 10;
          iVar3 = CrashVscSendPacketSync(param_1,local_58);
          if (iVar3 < 0) {
            return iVar3;
          }
          if (local_40 - 1U < 0x800000) {
            *param_2 = local_40;
            memset(local_58,0,0x40);
            local_58[1] = 1;
            local_58[0] = 8;
            iVar3 = CrashVscSendPacketSync(param_1,local_58);
            if (iVar3 < 0) {
              return iVar3;
            }
            return 0;
          }
        }
        pcVar2 = (code *)swi(0x29);
        (*pcVar2)(0x3a);
        pcVar2 = (code *)swi(3);
        iVar3 = (*pcVar2)();
        return iVar3;
      }
      if (iVar3 != -0x3fffffa7) {
        return iVar3;
      }
      uVar4 = (int)uVar5 + 1;
      uVar5 = (ulonglong)uVar4;
      psVar6 = psVar6 + 4;
      iVar3 = -0x3fffffa7;
    } while (uVar4 < 6);
  }
  return iVar3;
}



===== CrashVscGetSrbOriginalMdl @ 140001194 =====

undefined8 * CrashVscGetSrbOriginalMdl(undefined8 param_1,longlong param_2)

{
  ulonglong uVar1;
  longlong lVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  undefined8 *puVar5;
  uint uVar6;
  undefined4 local_res10 [2];
  
  local_res10[0] = 0;
  puVar5 = (undefined8 *)0x0;
  if (*(char *)(param_2 + 2) == '(') {
    uVar4 = *(ulonglong *)(param_2 + 0x40);
    uVar6 = *(uint *)(param_2 + 0x3c);
  }
  else {
    uVar4 = *(ulonglong *)(param_2 + 0x18);
    uVar6 = *(uint *)(param_2 + 0x10);
  }
  if (uVar4 != 0) {
    if (*(char *)(param_2 + 2) == '(') {
      puVar5 = *(undefined8 **)(param_2 + 0x68);
    }
    else {
      puVar5 = *(undefined8 **)(param_2 + 0x38);
    }
    *puVar5 = 0;
    *(uint *)(puVar5 + 5) = uVar6;
    *(undefined2 *)((longlong)puVar5 + 10) = 3;
    uVar1 = uVar6 + uVar4;
    puVar5[4] = uVar4 & 0xfffffffffffff000;
    *(short *)(puVar5 + 1) = ((short)((uVar4 & 0xfff) + 0xfff + (ulonglong)uVar6 >> 0xc) + 6) * 8;
    *(uint *)((longlong)puVar5 + 0x2c) = (uint)uVar4 & 0xfff;
    uVar3 = 0;
    for (; uVar4 < uVar1; uVar4 = uVar4 + 0x1000) {
      lVar2 = StorPortGetPhysicalAddress(param_1,param_2,uVar4,local_res10);
      puVar5[uVar3 + 6] = lVar2 >> 0xc;
      uVar3 = (ulonglong)((int)uVar3 + 1);
    }
  }
  return puVar5;
}



===== CrashVscHwFindAdapter @ 140001290 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 CrashVscHwFindAdapter(char *param_1)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  longlong in_stack_00000030;
  undefined1 *in_stack_00000038;
  
  iVar2 = 0;
  uVar3 = 1;
  if (*param_1 == '\0') {
    *(undefined8 *)(param_1 + 8) = *(undefined8 *)(in_stack_00000030 + 0x40);
    param_1[0x10] = '0';
    param_1[0x11] = '\0';
    param_1[0x12] = '$';
    param_1[0x13] = '\0';
    param_1[0x14] = '\x12';
    if (*(char *)(in_stack_00000030 + 0xc5) != '\x04') {
      memset(param_1 + 0x18,0,8000);
    }
    if (*(char *)(in_stack_00000030 + 0xc5) == '\x03') {
      StorPortExtendedFunction(0x2d,param_1,param_1,0x1f58,0);
      StorPortExtendedFunction(0x2d,param_1,*(undefined8 *)(param_1 + 8),0x30,0);
      StorPortExtendedFunction(0x2d,param_1,*(undefined8 *)(*(longlong *)(param_1 + 8) + 0x10),0,0);
      StorPortExtendedFunction(0x2d,param_1,*(undefined8 *)(*(longlong *)(param_1 + 8) + 0x18),0,0);
      StorPortExtendedFunction(0x2d,param_1,*(undefined8 *)(*(longlong *)(param_1 + 8) + 8),0,0);
      StorPortExtendedFunction(0x2d,param_1,*(undefined8 *)(*(longlong *)(param_1 + 8) + 0x28),0,0);
      (*(code *)(*(undefined8 **)(param_1 + 8))[4])(**(undefined8 **)(param_1 + 8));
LAB_140001415:
      if ((*(char *)(in_stack_00000030 + 0xc5) == '\x03') ||
         ((cVar1 = (*(code *)(*(undefined8 **)(param_1 + 8))[1])(**(undefined8 **)(param_1 + 8)),
          cVar1 != '\0' &&
          (iVar2 = CrashVscEstablishCommunications
                             ((longlong)param_1,(int *)(in_stack_00000030 + 0x18)), -1 < iVar2)))) {
        *(undefined2 *)(in_stack_00000030 + 0x59) = 0x103;
        *(undefined4 *)(in_stack_00000030 + 0x1c) = 0x81;
        *(undefined1 *)(in_stack_00000030 + 0x48) = 8;
        *(undefined1 *)(in_stack_00000030 + 0x61) = 0x80;
        *(undefined2 *)(in_stack_00000030 + 0x92) = 0xff;
        *(undefined2 *)(in_stack_00000030 + 0x52) = 1;
        *(undefined4 *)(in_stack_00000030 + 0x30) = 1;
        *(undefined1 *)(in_stack_00000030 + 0x51) = 1;
        *(undefined1 *)(in_stack_00000030 + 0x5b) = 1;
        *(undefined4 *)(in_stack_00000030 + 0x94) = 1;
        *(undefined1 *)(in_stack_00000030 + 0xc4) = 1;
        *(undefined1 *)(in_stack_00000030 + 0x90) = 1;
        *(undefined4 *)(in_stack_00000030 + 0x8c) = 0x48;
        *param_1 = '\x01';
        goto LAB_140001494;
      }
    }
    else if ((*(char *)(in_stack_00000030 + 0xc5) != '\x04') ||
            (iVar2 = (*(code *)(*(undefined8 **)(param_1 + 8))[5])(**(undefined8 **)(param_1 + 8)),
            -1 < iVar2)) goto LAB_140001415;
    uVar3 = 2;
  }
  else {
    if (*(longlong *)(param_1 + 8) == 0) {
      uVar3 = 2;
      goto LAB_14000149c;
    }
LAB_140001494:
    if (-1 < iVar2) goto LAB_14000149c;
  }
  param_1[8] = '\0';
  param_1[9] = '\0';
  param_1[10] = '\0';
  param_1[0xb] = '\0';
  param_1[0xc] = '\0';
  param_1[0xd] = '\0';
  param_1[0xe] = '\0';
  param_1[0xf] = '\0';
LAB_14000149c:
  *in_stack_00000038 = 0;
  return uVar3;
}



===== CrashVscHwResetBus @ 1400014d0 =====

undefined1 CrashVscHwResetBus(void)

{
  return 1;
}



===== CrashVscHwInterrupt @ 1400014e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 CrashVscHwInterrupt(longlong param_1)

{
  longlong lVar1;
  code *pcVar2;
  uint uVar3;
  undefined8 uVar4;
  int local_res10 [2];
  longlong local_res18 [2];
  int local_58 [6];
  uint local_40;
  
  local_res10[0] = 0;
  local_res18[0] = 0;
  do {
    while( true ) {
      memset(local_58,0,0x40);
      uVar4 = (*(code *)(*(undefined8 **)(param_1 + 8))[3])
                        (**(undefined8 **)(param_1 + 8),local_res10,local_res18,local_58);
      if ((char)uVar4 == '\0') goto LAB_1400015d8;
      if (local_res10[0] == 1) break;
      if (local_res10[0] != 3) goto LAB_1400015a1;
      if (999 < local_res18[0] - 2U) goto LAB_1400015d1;
      lVar1 = *(longlong *)(param_1 + 8 + local_res18[0] * 8);
      *(undefined8 *)(param_1 + 8 + local_res18[0] * 8) = 0;
      if (lVar1 == 0) goto LAB_1400015d1;
      if (*(char *)(lVar1 + 2) == '(') {
        uVar3 = *(uint *)(lVar1 + 0x3c);
      }
      else {
        uVar3 = *(uint *)(lVar1 + 0x10);
      }
      if (uVar3 < local_40) goto LAB_1400015d1;
      CrashVscSrbCompletion(param_1,lVar1,(longlong)local_58);
    }
  } while (local_58[0] == 0xb);
LAB_1400015a1:
  StorPortLogError(param_1,0,0,0);
  pcVar2 = (code *)swi(0x29);
  (*pcVar2)(0x3a);
LAB_1400015d1:
  pcVar2 = (code *)swi(0x29);
  uVar4 = (*pcVar2)(0x3a);
LAB_1400015d8:
  return CONCAT71((int7)((ulonglong)uVar4 >> 8),1);
}



===== CrashVscHwStartIO @ 1400015f0 =====

undefined8 CrashVscHwStartIO(longlong param_1,longlong param_2)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  bool bVar5;
  char cVar6;
  undefined8 *puVar7;
  undefined8 uVar8;
  undefined1 uVar9;
  undefined1 uVar10;
  ulonglong uVar11;
  uint uVar12;
  short *psVar13;
  ulonglong uVar14;
  
  bVar1 = *(byte *)(param_2 + 2);
  if (bVar1 == 0x28) {
    if (((*(uint *)(param_2 + 0x34) != 0) &&
        (psVar13 = (short *)((ulonglong)*(uint *)(param_2 + 0x34) + param_2),
        psVar13 != (short *)0x0)) && (*psVar13 == 1)) {
      bVar2 = *(byte *)((longlong)psVar13 + 9);
      cVar6 = (char)psVar13[5];
      goto LAB_14000162f;
    }
LAB_140001645:
    uVar12 = *(uint *)(param_2 + 0x14);
LAB_14000164c:
    if (uVar12 == 0) {
      puVar7 = CrashVscGetSrbOriginalMdl(param_1,param_2);
      uVar8 = CrashVscSendSrbRequest(param_1,param_2,puVar7);
      if ((int)uVar8 < 0) {
        if (*(char *)(param_2 + 2) == '(') {
          cVar6 = (*(char *)(param_2 + 3) >> 7 & 0x80U) + 2;
          goto LAB_140001668;
        }
        uVar10 = 2;
        if (*(char *)(param_2 + 3) < '\0') {
          uVar10 = 0x82;
        }
        *(undefined1 *)(param_2 + 3) = uVar10;
      }
      else if ((int)uVar8 == 0x103) goto LAB_14000184a;
    }
    else if (uVar12 == 7) {
      if (bVar1 == 0x28) {
        cVar6 = (*(char *)(param_2 + 3) >> 7 & 0x80U) + 1;
      }
      else {
        cVar6 = '\x01';
        if (*(char *)(param_2 + 3) < '\0') {
          cVar6 = -0x7f;
        }
      }
      *(char *)(param_2 + 3) = cVar6;
      if (*(char *)(param_2 + 2) == '(') {
        bVar5 = false;
        if ((*(int *)(param_2 + 0x14) == 0) && (uVar14 = 0, *(int *)(param_2 + 0x38) != 0)) {
          do {
            uVar12 = *(uint *)(param_2 + 0x78 + uVar14 * 4);
            if ((0x7f < uVar12) && (uVar3 = *(uint *)(param_2 + 0x10), uVar12 < uVar3)) {
              uVar11 = (ulonglong)uVar12;
              iVar4 = *(int *)((ulonglong)uVar12 + param_2);
              if (iVar4 == 0x40) {
LAB_1400016f3:
                if (uVar11 + 0x28 <= (ulonglong)uVar3) {
                  *(undefined1 *)(uVar11 + 8 + param_2) = 0;
                  break;
                }
              }
              else if (iVar4 == 0x41) {
                if (uVar11 + 0x38 <= (ulonglong)uVar3) {
                  bVar5 = true;
                  *(undefined1 *)(uVar11 + 8 + param_2) = 0;
                }
              }
              else if (iVar4 == 0x42) goto LAB_1400016f3;
              if (bVar5) break;
            }
            uVar12 = (int)uVar14 + 1;
            uVar14 = (ulonglong)uVar12;
          } while (uVar12 < *(uint *)(param_2 + 0x38));
        }
      }
      else {
        *(undefined1 *)(param_2 + 4) = 0;
      }
    }
    else {
      cVar6 = *(char *)(param_2 + 3);
      if (bVar1 != 0x28) {
        uVar10 = 6;
        uVar9 = 0x86;
        goto LAB_14000182e;
      }
      cVar6 = (cVar6 >> 7 & 0x80U) + 6;
LAB_140001668:
      *(char *)(param_2 + 3) = cVar6;
    }
  }
  else {
    bVar2 = *(byte *)(param_2 + 6);
    cVar6 = *(char *)(param_2 + 7);
LAB_14000162f:
    if ((bVar2 < 0x80) && (cVar6 != -1)) {
      if (bVar1 == 0x28) goto LAB_140001645;
      uVar12 = (uint)bVar1;
      goto LAB_14000164c;
    }
    if (bVar1 == 0x28) {
      bVar5 = false;
      if ((*(int *)(param_2 + 0x14) == 0) && (uVar14 = 0, *(int *)(param_2 + 0x38) != 0)) {
        do {
          uVar12 = *(uint *)(param_2 + 0x78 + uVar14 * 4);
          if ((0x7f < uVar12) && (uVar3 = *(uint *)(param_2 + 0x10), uVar12 < uVar3)) {
            uVar11 = (ulonglong)uVar12;
            iVar4 = *(int *)((ulonglong)uVar12 + param_2);
            if (iVar4 == 0x40) {
LAB_1400017d8:
              if (uVar11 + 0x28 <= (ulonglong)uVar3) {
                *(undefined1 *)(uVar11 + 8 + param_2) = 2;
                break;
              }
            }
            else if (iVar4 == 0x41) {
              if (uVar11 + 0x38 <= (ulonglong)uVar3) {
                bVar5 = true;
                *(undefined1 *)(uVar11 + 8 + param_2) = 2;
              }
            }
            else if (iVar4 == 0x42) goto LAB_1400017d8;
            if (bVar5) break;
          }
          uVar12 = (int)uVar14 + 1;
          uVar14 = (ulonglong)uVar12;
        } while (uVar12 < *(uint *)(param_2 + 0x38));
      }
    }
    else {
      *(undefined1 *)(param_2 + 4) = 2;
    }
    cVar6 = *(char *)(param_2 + 3);
    if (*(char *)(param_2 + 2) == '(') {
      cVar6 = (cVar6 >> 7 & 0x80U) + 0x21;
      goto LAB_140001668;
    }
    uVar10 = 0x21;
    uVar9 = 0xa1;
LAB_14000182e:
    if (cVar6 < '\0') {
      uVar10 = uVar9;
    }
    *(undefined1 *)(param_2 + 3) = uVar10;
  }
  uVar8 = StorPortNotification(0,param_1,param_2);
LAB_14000184a:
  return CONCAT71((int7)((ulonglong)uVar8 >> 8),1);
}



===== CrashVscSendPacketSync @ 140001860 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int CrashVscSendPacketSync(longlong param_1,int *param_2)

{
  code *pcVar1;
  char cVar2;
  int iVar3;
  int local_res8 [4];
  uint local_res18 [2];
  longlong local_res20;
  
  local_res8[0] = 0;
  local_res20 = 0;
  iVar3 = 5;
  local_res18[0] = (uint)*(ushort *)(param_1 + 0x10);
  while (cVar2 = (*(code *)(*(undefined8 **)(param_1 + 8))[2])
                           (**(undefined8 **)(param_1 + 8),2,1,param_2,
                            *(undefined2 *)(param_1 + 0x10),0,0), cVar2 == '\0') {
    if (iVar3 < 1) {
      return -0x3fffffff;
    }
    iVar3 = iVar3 + -1;
    StorPortStallExecution(0x32);
  }
  while( true ) {
    cVar2 = (*(code *)(*(undefined8 **)(param_1 + 8))[3])
                      (**(undefined8 **)(param_1 + 8),local_res8,&local_res20,param_2,local_res18);
    if (cVar2 != '\0') {
      if (local_res20 != 1) {
        pcVar1 = (code *)swi(0x29);
        (*pcVar1)(0x3a);
      }
      iVar3 = -0x3fffff63;
      if (*param_2 == 1) {
        iVar3 = param_2[2];
      }
      return iVar3;
    }
    if (local_res8[0] != 0) break;
    StorPortStallExecution(0x32);
    local_res18[0] = (uint)*(ushort *)(param_1 + 0x10);
  }
  return -0x3fffffff;
}



===== CrashVscSendSrbRequest @ 140001954 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 CrashVscSendSrbRequest(longlong param_1,longlong param_2,undefined8 param_3)

{
  longlong lVar1;
  char cVar2;
  ulonglong uVar3;
  longlong *plVar4;
  uint uVar5;
  int iVar6;
  undefined4 local_58 [3];
  ushort local_4c;
  byte local_43;
  
  memset(local_58,0,0x40);
  iVar6 = 5;
  StorChannelCopySrbToPacket(param_2,local_58);
  if (*(ushort *)(param_1 + 0x12) < local_4c) {
    local_4c = *(ushort *)(param_1 + 0x12);
  }
  if (*(byte *)(param_1 + 0x14) < local_43) {
    local_43 = *(byte *)(param_1 + 0x14);
  }
  if (*(char *)(param_2 + 2) == '(') {
    uVar5 = *(uint *)(param_2 + 0x18);
  }
  else {
    uVar5 = *(uint *)(param_2 + 0xc);
  }
  if (((byte)uVar5 & 0xc0) == 0xc0) {
    uVar5 = 0;
  }
  else if ((uVar5 & 0x40) == 0) {
    uVar5 = (uVar5 & 0xff) >> 3 & 0x10;
  }
  else {
    uVar5 = 8;
  }
  uVar3 = 0;
  plVar4 = (longlong *)(param_1 + 0x18);
  while (*plVar4 != 0) {
    uVar3 = uVar3 + 1;
    plVar4 = plVar4 + 1;
    if (999 < uVar3) {
      return 0xc0000001;
    }
  }
  lVar1 = uVar3 + 2;
  *(longlong *)(param_1 + 0x18 + uVar3 * 8) = param_2;
  if (lVar1 == -1) {
    return 0xc0000001;
  }
  while( true ) {
    cVar2 = (*(code *)(*(undefined8 **)(param_1 + 8))[2])
                      (**(undefined8 **)(param_1 + 8),2,lVar1,local_58,0x40,param_3,uVar5);
    if (cVar2 != '\0') {
      return 0x103;
    }
    if (iVar6 < 1) break;
    iVar6 = iVar6 + -1;
    StorPortStallExecution(0x32);
  }
  if (uVar3 < 1000) {
    *(undefined8 *)(param_1 + 8 + lVar1 * 8) = 0;
    return 0xc0000001;
  }
  return 0xc0000001;
}



===== CrashVscSrbCompletion @ 140001ac8 =====

void CrashVscSrbCompletion(undefined8 param_1,longlong param_2,longlong param_3)

{
  byte *_Src;
  char cVar1;
  undefined1 uVar2;
  byte bVar3;
  int iVar4;
  code *pcVar5;
  bool bVar6;
  byte bVar7;
  uint uVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  undefined1 *puVar11;
  ulonglong uVar12;
  byte *_Dst;
  uint uVar13;
  byte bVar14;
  byte bVar15;
  byte bVar16;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  
  puVar11 = auStack_48;
  cVar1 = *(char *)(param_2 + 2);
  if (cVar1 != '(') {
    *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(param_3 + 0x18);
  }
  else {
    *(undefined4 *)(param_2 + 0x3c) = *(undefined4 *)(param_3 + 0x18);
  }
  bVar7 = *(byte *)(param_3 + 0xe);
  if (cVar1 != '(') {
    if (*(char *)(param_2 + 3) < '\0') {
      bVar7 = bVar7 | 0x80;
    }
  }
  else {
    bVar3 = bVar7 | 0x80;
    if (-1 < *(char *)(param_2 + 3)) {
      bVar3 = bVar7;
    }
    bVar7 = bVar3;
  }
  *(byte *)(param_2 + 3) = bVar7;
  uVar2 = *(undefined1 *)(param_3 + 0xf);
  if (cVar1 == '(') {
    bVar6 = false;
    if ((*(int *)(param_2 + 0x14) == 0) && (uVar12 = 0, *(int *)(param_2 + 0x38) != 0)) {
      do {
        uVar13 = *(uint *)(param_2 + 0x78 + uVar12 * 4);
        if ((0x7f < uVar13) && (uVar8 = *(uint *)(param_2 + 0x10), uVar13 < uVar8)) {
          uVar9 = (ulonglong)uVar13;
          iVar4 = *(int *)((ulonglong)uVar13 + param_2);
          if (iVar4 == 0x40) {
LAB_140001b72:
            if (uVar9 + 0x28 <= (ulonglong)uVar8) {
              *(undefined1 *)(uVar9 + 8 + param_2) = uVar2;
              break;
            }
          }
          else if (iVar4 == 0x41) {
            if (uVar9 + 0x38 <= (ulonglong)uVar8) {
              bVar6 = true;
              *(undefined1 *)(uVar9 + 8 + param_2) = uVar2;
            }
          }
          else if (iVar4 == 0x42) goto LAB_140001b72;
          if (bVar6) break;
        }
        uVar13 = (int)uVar12 + 1;
        uVar12 = (ulonglong)uVar13;
      } while (uVar13 < *(uint *)(param_2 + 0x38));
    }
  }
  else {
    *(undefined1 *)(param_2 + 4) = uVar2;
  }
  if (*(char *)(param_3 + 0xf) != '\x02') goto LAB_140001f13;
  puVar11 = auStack_48;
  if (0x14 < *(byte *)(param_3 + 0x15)) {
    pcVar5 = (code *)swi(0x29);
    (*pcVar5)(0x3a);
    puVar11 = auStack_40;
  }
  _Dst = (byte *)0x0;
  if (*(char *)(param_2 + 2) == '(') {
    bVar6 = false;
    if (*(int *)(param_2 + 0x14) == 0) {
      uVar12 = 0;
      if (*(uint *)(param_2 + 0x38) != 0) {
        do {
          uVar13 = *(uint *)(param_2 + 0x78 + uVar12 * 4);
          if ((0x7f < uVar13) &&
             (uVar9 = (ulonglong)*(uint *)(param_2 + 0x10), uVar13 < *(uint *)(param_2 + 0x10))) {
            uVar10 = (ulonglong)uVar13;
            iVar4 = *(int *)((ulonglong)uVar13 + param_2);
            if (iVar4 == 0x40) {
              if (uVar10 + 0x28 <= uVar9) {
                _Dst = *(byte **)(uVar10 + 0x10 + param_2);
                break;
              }
            }
            else if (iVar4 == 0x41) {
              if (uVar10 + 0x38 <= uVar9) {
                _Dst = *(byte **)(uVar10 + 0x10 + param_2);
                bVar6 = true;
              }
            }
            else if ((iVar4 == 0x42) && (uVar10 + 0x28 <= uVar9)) {
              _Dst = *(byte **)(uVar10 + 0x18 + param_2);
              break;
            }
            if (bVar6) break;
          }
          uVar13 = (int)uVar12 + 1;
          uVar12 = (ulonglong)uVar13;
        } while (uVar13 < *(uint *)(param_2 + 0x38));
      }
    }
    bVar6 = false;
    bVar7 = 0;
    if (*(int *)(param_2 + 0x14) == 0) {
      uVar12 = 0;
      bVar3 = 0;
      if (*(uint *)(param_2 + 0x38) != 0) {
        do {
          bVar7 = bVar3;
          uVar13 = *(uint *)(param_2 + 0x78 + uVar12 * 4);
          if ((0x7f < uVar13) && (uVar8 = *(uint *)(param_2 + 0x10), uVar13 < uVar8)) {
            uVar9 = (ulonglong)uVar13;
            iVar4 = *(int *)((ulonglong)uVar13 + param_2);
            if (iVar4 == 0x40) {
LAB_140001c86:
              if (uVar9 + 0x28 <= (ulonglong)uVar8) {
                bVar7 = *(byte *)(uVar9 + 9 + param_2);
                break;
              }
            }
            else if (iVar4 == 0x41) {
              if (uVar9 + 0x38 <= (ulonglong)uVar8) {
                bVar7 = *(byte *)(uVar9 + 9 + param_2);
                bVar6 = true;
              }
            }
            else if (iVar4 == 0x42) goto LAB_140001c86;
            if (bVar6) break;
          }
          uVar13 = (int)uVar12 + 1;
          uVar12 = (ulonglong)uVar13;
          bVar3 = bVar7;
        } while (uVar13 < *(uint *)(param_2 + 0x38));
      }
    }
  }
  else {
    _Dst = *(byte **)(param_2 + 0x20);
    bVar7 = *(byte *)(param_2 + 0xb);
  }
  if ((_Dst == (byte *)0x0) || (bVar7 == 0)) goto LAB_140001f13;
  bVar3 = *(byte *)(param_3 + 0x15);
  uVar12 = (ulonglong)bVar3;
  _Src = (byte *)(param_3 + 0x1c);
  if (1 < (byte)((*_Src & 0x7f) + 0x8e)) {
    if (bVar3 <= bVar7) {
      *(undefined8 *)(puVar11 + -8) = 0x140001e99;
      memcpy(_Dst,_Src,uVar12);
      uVar2 = *(undefined1 *)(param_3 + 0x15);
      if (*(char *)(param_2 + 2) == '(') {
        bVar6 = false;
        if ((*(int *)(param_2 + 0x14) == 0) && (uVar12 = 0, *(int *)(param_2 + 0x38) != 0)) {
          do {
            uVar13 = *(uint *)(param_2 + 0x78 + uVar12 * 4);
            if ((0x7f < uVar13) && (uVar8 = *(uint *)(param_2 + 0x10), uVar13 < uVar8)) {
              uVar9 = (ulonglong)uVar13;
              iVar4 = *(int *)((ulonglong)uVar13 + param_2);
              if (iVar4 == 0x40) {
LAB_140001edc:
                if (uVar9 + 0x28 <= (ulonglong)uVar8) {
                  *(undefined1 *)(uVar9 + 9 + param_2) = uVar2;
                  break;
                }
              }
              else if (iVar4 == 0x41) {
                if (uVar9 + 0x38 <= (ulonglong)uVar8) {
                  bVar6 = true;
                  *(undefined1 *)(uVar9 + 9 + param_2) = uVar2;
                }
              }
              else if (iVar4 == 0x42) goto LAB_140001edc;
              if (bVar6) break;
            }
            uVar13 = (int)uVar12 + 1;
            uVar12 = (ulonglong)uVar13;
          } while (uVar13 < *(uint *)(param_2 + 0x38));
        }
      }
      else {
        *(undefined1 *)(param_2 + 0xb) = uVar2;
      }
    }
    goto LAB_140001f13;
  }
  bVar16 = 0;
  bVar15 = 0;
  bVar14 = 0;
  if ((((_Src != (byte *)0x0) && (bVar3 != 0)) && (0x11 < bVar7)) &&
     ((byte)((*_Src & 0x7f) + 0x8e) < 2)) {
    *(undefined8 *)(puVar11 + -8) = 0x140001d30;
    memset(_Dst,0,(ulonglong)bVar7);
    bVar7 = *_Src & 0x7f;
    if ((byte)(bVar7 + 0x8e) < 2) {
      bVar6 = false;
      if ((byte *)(param_3 + 0x24) <= _Src + uVar12) {
        bVar16 = *(byte *)(param_3 + 0x1d);
        bVar15 = *(byte *)(param_3 + 0x1e);
        bVar14 = *(byte *)(param_3 + 0x1f);
LAB_140001db3:
        bVar6 = true;
      }
    }
    else {
      if (1 < (byte)((*_Src & 0x7f) + 0x90)) goto LAB_140001dee;
      bVar6 = false;
      if ((byte *)(param_3 + 0x24) <= _Src + uVar12) {
        bVar16 = *(byte *)(param_3 + 0x1e);
        uVar8 = *(byte *)(param_3 + 0x23) + 8;
        uVar13 = (uint)bVar3;
        if (uVar8 <= bVar3) {
          uVar13 = uVar8;
        }
        if ((byte *)(param_3 + 0x29) <= _Src + uVar13) {
          bVar15 = *(byte *)(param_3 + 0x28);
        }
        if (_Src + uVar13 < (byte *)(param_3 + 0x2a)) {
          bVar14 = 0;
        }
        else {
          bVar14 = *(byte *)(param_3 + 0x29);
        }
        goto LAB_140001db3;
      }
    }
    if (bVar6) {
      if ((bVar7 + 0x90 & 0xfd) == 0) {
        bVar7 = *_Dst & 0xf0 | 0x70;
      }
      else {
        bVar7 = *_Dst & 0xf1 | 0x71;
      }
      *_Dst = bVar7;
      _Dst[7] = 10;
      _Dst[0xc] = bVar15;
      _Dst[0xd] = bVar14;
      _Dst[2] = (bVar16 ^ _Dst[2]) & 0xf ^ _Dst[2];
    }
  }
LAB_140001dee:
  if (*(char *)(param_2 + 2) == '(') {
    bVar6 = false;
    if ((*(int *)(param_2 + 0x14) == 0) && (uVar12 = 0, *(int *)(param_2 + 0x38) != 0)) {
      do {
        uVar13 = *(uint *)(param_2 + 0x78 + uVar12 * 4);
        if ((0x7f < uVar13) && (uVar8 = *(uint *)(param_2 + 0x10), uVar13 < uVar8)) {
          uVar9 = (ulonglong)uVar13;
          iVar4 = *(int *)((ulonglong)uVar13 + param_2);
          if (iVar4 == 0x40) {
LAB_140001e3c:
            if (uVar9 + 0x28 <= (ulonglong)uVar8) {
              *(undefined1 *)(uVar9 + 9 + param_2) = 0x12;
              break;
            }
          }
          else if (iVar4 == 0x41) {
            if (uVar9 + 0x38 <= (ulonglong)uVar8) {
              bVar6 = true;
              *(undefined1 *)(uVar9 + 9 + param_2) = 0x12;
            }
          }
          else if (iVar4 == 0x42) goto LAB_140001e3c;
          if (bVar6) break;
        }
        uVar13 = (int)uVar12 + 1;
        uVar12 = (ulonglong)uVar13;
      } while (uVar13 < *(uint *)(param_2 + 0x38));
    }
  }
  else {
    *(undefined1 *)(param_2 + 0xb) = 0x12;
  }
LAB_140001f13:
  *(undefined8 *)(puVar11 + -8) = 0x140001f24;
  StorPortNotification(0,*(undefined8 *)(puVar11 + 0x50),param_2);
  return;
}



===== DumpPreInitialize @ 140001f50 =====

undefined8 DumpPreInitialize(void)

{
  ulonglong uVar1;
  
                    /* 0x1f50  1  DumpPreInitialize */
  g_DumpPreInitializeInvoked = 1;
  wil_InitializeFeatureStaging();
  uVar1 = Feature_CrashDumpOneMBTransferSize__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar1 != 0) {
    InitializeMultiphaseResumeRegKey();
  }
  return 0;
}



===== DumpUninitialize @ 140001f80 =====

void DumpUninitialize(void)

{
                    /* 0x1f80  2  DumpUninitialize */
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



===== Feature_CrashDumpOneMBTransferSize__private_IsEnabledDeviceUsageNoInline @ 140001fd8 =====

ulonglong Feature_CrashDumpOneMBTransferSize__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  undefined4 *local_res8;
  
  local_res8 = (undefined4 *)(ulonglong)Feature_CrashDumpOneMBTransferSize__private_featureState;
  if ((Feature_CrashDumpOneMBTransferSize__private_featureState & 0x10) == 0) {
    uVar1 = Feature_CrashDumpOneMBTransferSize__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_CrashDumpOneMBTransferSize__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_CrashDumpOneMBTransferSize__private_IsEnabledFallback @ 140002010 =====

void Feature_CrashDumpOneMBTransferSize__private_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2);
  return;
}



===== Feature_CrashDumpOneMBTransferSize__private_IsEnabledNoReportingNoInline @ 140002028 =====

ulonglong Feature_CrashDumpOneMBTransferSize__private_IsEnabledNoReportingNoInline(void)

{
  ulonglong uVar1;
  undefined4 *local_res8;
  
  local_res8 = (undefined4 *)(ulonglong)Feature_CrashDumpOneMBTransferSize__private_featureState;
  if ((Feature_CrashDumpOneMBTransferSize__private_featureState & 2) == 0) {
    uVar1 = Feature_CrashDumpOneMBTransferSize__private_IsEnabledFallback(local_res8,0);
  }
  else {
    uVar1 = (ulonglong)(Feature_CrashDumpOneMBTransferSize__private_featureState & 1);
  }
  return uVar1;
}



===== InitializeMultiphaseResumeRegKey @ 140002060 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void InitializeMultiphaseResumeRegKey(void)

{
  int iVar1;
  uint uVar2;
  undefined1 auStack_d8 [32];
  undefined4 local_b8;
  undefined4 *local_b0;
  undefined8 local_a8;
  undefined4 local_a0 [2];
  undefined8 local_98;
  wchar_t *local_90;
  undefined8 local_88;
  wchar_t *local_80;
  undefined8 local_78;
  wchar_t *local_70;
  undefined8 local_68;
  wchar_t *local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined1 local_28 [4];
  int local_24;
  int local_20;
  uint local_1c;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_d8;
  local_a8 = 0;
  local_3c = 0;
  local_a0[0] = 0;
  local_70 = 
  L"\\REGISTRY\\MACHINE\\System\\CurrentControlSet\\Services\\storvsc\\Parameters\\Device";
  local_58 = 0x30;
  local_50 = 0;
  local_60 = L"MultiPhaseResumeEnabled";
  local_78 = 0x9c009a;
  local_90 = L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\CrashControl";
  local_80 = L"MaximumTransferSize";
  local_48 = &local_98;
  local_68 = 0x30002e;
  local_98 = 0x80007e;
  local_88 = 0x280026;
  local_40 = 0x240;
  local_38 = 0;
  uStack_30 = 0;
  iVar1 = ZwOpenKey(&local_a8,0x20019,&local_58);
  if (-1 < iVar1) {
    local_b0 = local_a0;
    local_b8 = 0x14;
    iVar1 = ZwQueryValueKey(local_a8,&local_88,2,local_28);
    uVar2 = 0;
    if ((-1 < iVar1) && (local_24 == 4)) {
      uVar2 = 0;
      if (local_20 == 4) {
        uVar2 = local_1c;
      }
    }
    ZwClose(local_a8);
    if (0xfffff < uVar2) {
      local_50 = 0;
      local_48 = &local_78;
      local_58 = CONCAT44(local_58._4_4_,0x30);
      local_40 = 0x240;
      local_38 = 0;
      uStack_30 = 0;
      iVar1 = ZwOpenKey(&local_a8,0x20019,&local_58);
      if (-1 < iVar1) {
        local_b0 = local_a0;
        local_b8 = 0x14;
        iVar1 = ZwQueryValueKey(local_a8,&local_68,2,local_28);
        if (-1 < iVar1) {
          g_isMultiPhaseEnabledInStorVsc = local_1c != 0;
        }
      }
      ZwClose(local_a8);
    }
  }
  return;
}



===== McGenControlCallbackV2 @ 140002240 =====

void McGenControlCallbackV2
               (undefined8 param_1,int param_2,undefined1 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6,longlong param_7)

{
  uint *puVar1;
  ulonglong uVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  ulonglong uVar7;
  
  if (param_7 != 0) {
    if (param_2 == 0) {
      *(undefined4 *)(param_7 + 0x24) = 0;
      *(undefined1 *)(param_7 + 0x28) = 0;
      *(undefined8 *)(param_7 + 0x10) = 0;
      *(undefined8 *)(param_7 + 0x18) = 0;
      if (*(ushort *)(param_7 + 0x2a) != 0) {
        iVar4 = *(ushort *)(param_7 + 0x2a) - 1;
        memset(*(void **)(param_7 + 0x30),0,
               (longlong)(((int)(iVar4 + (iVar4 >> 0x1f & 0x1fU)) >> 5) + 1) << 2);
      }
    }
    else if (param_2 == 1) {
      *(undefined1 *)(param_7 + 0x28) = param_3;
      uVar7 = 0;
      *(undefined8 *)(param_7 + 0x18) = param_5;
      *(undefined8 *)(param_7 + 0x10) = param_4;
      *(undefined4 *)(param_7 + 0x24) = 1;
      if (*(short *)(param_7 + 0x2a) != 0) {
        do {
          uVar2 = *(ulonglong *)(*(longlong *)(param_7 + 0x38) + uVar7 * 8);
          if (((*(byte *)(param_7 + 0x28) < *(byte *)(uVar7 + *(longlong *)(param_7 + 0x40))) &&
              (*(byte *)(param_7 + 0x28) != 0)) ||
             ((uVar2 != 0 &&
              (((*(ulonglong *)(param_7 + 0x10) & uVar2) == 0 ||
               ((*(ulonglong *)(param_7 + 0x18) & uVar2) != *(ulonglong *)(param_7 + 0x18))))))) {
            bVar3 = false;
          }
          else {
            bVar3 = true;
          }
          uVar5 = 1 << ((byte)uVar7 & 0x1f);
          puVar1 = (uint *)(*(longlong *)(param_7 + 0x30) + (uVar7 >> 5) * 4);
          uVar6 = *puVar1;
          if (bVar3) {
            uVar5 = uVar5 | uVar6;
          }
          else {
            uVar5 = ~uVar5 & uVar6;
          }
          *puVar1 = uVar5;
          uVar6 = (int)uVar7 + 1;
          uVar7 = (ulonglong)uVar6;
        } while (uVar6 < *(ushort *)(param_7 + 0x2a));
      }
    }
  }
  return;
}



===== McGenEventRegister_EtwRegister @ 140002350 =====

void McGenEventRegister_EtwRegister(void)

{
  if (STORVSC_PROVIDER_Context == 0) {
    EtwRegister(&STORVSC_PROVIDER,McGenControlCallbackV2,&STORVSC_PROVIDER_Context,
                &STORVSC_PROVIDER_Context);
  }
  return;
}



===== McGenEventUnregister_EtwUnregister @ 140002390 =====

undefined8 McGenEventUnregister_EtwUnregister(void)

{
  undefined8 uVar1;
  
  if (STORVSC_PROVIDER_Context == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = EtwUnregister();
    STORVSC_PROVIDER_Context = 0;
  }
  return uVar1;
}



===== McGenEventWrite_EtwWriteTransfer @ 1400023c4 =====

void McGenEventWrite_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 *param_5)

{
  ushort *puVar1;
  undefined4 uVar2;
  uint uVar3;
  
  puVar1 = DAT_14000b018;
  uVar2 = 0;
  if (DAT_14000b018 == (ushort *)0x0) {
    *param_5 = 0;
    uVar3 = 0;
  }
  else {
    *param_5 = DAT_14000b018;
    uVar2 = 2;
    uVar3 = (uint)*puVar1;
  }
  *(uint *)(param_5 + 1) = uVar3;
  *(undefined4 *)((longlong)param_5 + 0xc) = uVar2;
  EtwWriteTransfer(STORVSC_PROVIDER_Context,param_2,param_3,0,6,param_5);
  return;
}



===== McTemplateK0qttjq_EtwWriteTransfer @ 140002428 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0qttjq_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6,undefined8 param_7,undefined1 param_8)

{
  undefined4 local_res20 [2];
  undefined1 auStackY_a8 [32];
  undefined8 local_78 [2];
  undefined4 *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_res20[0] = (undefined4)param_4;
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_68 = local_res20;
  local_60 = 4;
  local_58 = &param_5;
  local_48 = &param_6;
  local_38 = param_7;
  local_28 = &param_8;
  local_50 = 4;
  local_40 = 4;
  local_30 = 0x10;
  local_20 = 4;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,param_3,param_4,local_78);
  return;
}



===== QueryWmiDataBlock @ 1400024d0 =====

char QueryWmiDataBlock(longlong param_1,longlong param_2,int param_3,undefined8 param_4,
                      undefined8 param_5,undefined4 *param_6,uint param_7,longlong *param_8)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  char cVar5;
  undefined8 uVar6;
  uint *puVar7;
  ulonglong uVar8;
  uint uVar9;
  uint uVar10;
  ulonglong uVar11;
  char cVar12;
  uint uVar13;
  
  uVar10 = 0;
  if (param_3 == 0) {
    uVar10 = 0x1338;
    uVar6 = Request_MSFC_FCAdapterHBAAttributes(param_1,param_6,param_7,param_8);
    cVar5 = (char)uVar6;
  }
  else if (param_3 == 1) {
    uVar10 = 0x88;
    cVar5 = Request_MSFC_FibrePortHBAAttributes(param_1,param_6,param_7,param_8);
  }
  else if (param_3 == 2) {
    uVar10 = 0x88;
    cVar5 = '\x01';
    if (param_7 < 0x88) {
      cVar5 = '\x12';
    }
    else {
      memset(param_8,0,(ulonglong)param_7);
      *(undefined4 *)(param_8 + 1) = 0;
      *param_8 = param_1 + 1;
      param_8[2] = -1;
      param_8[3] = -1;
      param_8[4] = -1;
      param_8[5] = -1;
      param_8[6] = -1;
      param_8[7] = -1;
      param_8[8] = -1;
      param_8[9] = -1;
      param_8[10] = -1;
      param_8[0xb] = -1;
      param_8[0xc] = -1;
      param_8[0xd] = -1;
      param_8[0xe] = -1;
      param_8[0xf] = -1;
      param_8[0x10] = -1;
      *param_6 = 0x88;
    }
  }
  else {
    cVar5 = '\x04';
  }
  cVar1 = *(char *)(param_2 + 0x18);
  uVar9 = 0;
  uVar2 = *(uint *)(param_2 + 8);
  puVar4 = *(uint **)(param_2 + 0x10);
  cVar12 = cVar5;
  if (cVar1 == '\0') {
    uVar13 = puVar4[0xc];
    uVar3 = puVar4[0xd];
    uVar8 = (ulonglong)uVar3;
    uVar10 = uVar13 + uVar10;
    if (cVar5 != '\x01') goto LAB_1400026fe;
    if (uVar10 <= uVar2) {
      if (0x2f < uVar2) {
        *puVar4 = uVar10;
        uVar9 = uVar10;
        if ((char)puVar4[0xb] < '\0') {
          puVar7 = puVar4 + 0xf;
          uVar10 = uVar3;
          if (uVar3 != 0) {
            do {
              uVar10 = uVar10 - 1;
              if ((ulonglong)uVar10 * 8 + 0x48 <= (ulonglong)uVar2) {
                puVar4[(ulonglong)uVar10 * 2 + 0x10] = puVar7[uVar10];
              }
            } while (uVar10 != 0);
            if (uVar3 != 0) {
              uVar11 = 0x48;
              do {
                if (uVar11 <= uVar2) {
                  *puVar7 = uVar13;
                  uVar13 = uVar13 + 7 + puVar7[1] & 0xfffffff8;
                }
                uVar11 = uVar11 + 8;
                puVar7 = puVar7 + 2;
                uVar8 = uVar8 - 1;
              } while (uVar8 != 0);
            }
          }
        }
      }
      goto LAB_140002720;
    }
    cVar12 = '\x12';
LAB_140002704:
    if (uVar2 < 0x38) goto LAB_140002720;
    puVar4[0xc] = uVar10;
  }
  else {
    if (cVar1 == '\x01') {
      uVar10 = puVar4[0xe] + uVar10;
      if (cVar5 == '\x01') {
        if (0x2f < uVar2) {
          *puVar4 = uVar10;
          uVar9 = uVar10;
        }
        goto LAB_140002720;
      }
LAB_1400026fe:
      if (cVar5 != '\x12') goto LAB_140002720;
      goto LAB_140002704;
    }
    if (cVar1 != '\t') goto LAB_140002720;
    uVar13 = puVar4[0xf] + uVar10;
    if (cVar5 == '\x01') {
      if (0x47 < uVar2) {
        *puVar4 = uVar13;
        puVar4[0x10] = uVar10;
        uVar9 = uVar13;
      }
      goto LAB_140002720;
    }
    if ((cVar5 != '\x12') || (uVar2 < 0x38)) goto LAB_140002720;
    puVar4[0xc] = uVar13;
  }
  *puVar4 = 0x38;
  puVar4[0xb] = 0x20;
  cVar12 = '\x01';
  uVar9 = 0x38;
LAB_140002720:
  *(uint *)(param_2 + 0x1c) = uVar9;
  *(char *)(param_2 + 0x19) = cVar12;
  return cVar5;
}



===== QueryWmiRegInfo @ 140002750 =====

undefined8 QueryWmiRegInfo(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  *param_3 = L"";
  return 0x140009101;
}



===== Request_MSFC_FCAdapterHBAAttributes @ 140002764 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
Request_MSFC_FCAdapterHBAAttributes
          (longlong param_1,undefined4 *param_2,uint param_3,longlong *param_4)

{
  short sVar1;
  longlong *plVar2;
  undefined8 uVar3;
  longlong *plVar4;
  longlong lVar5;
  undefined1 uVar6;
  longlong lVar7;
  longlong lVar8;
  undefined1 auStack_198 [32];
  undefined4 local_178;
  undefined4 local_170;
  undefined8 local_168;
  undefined4 local_158;
  uint local_154;
  undefined4 local_150;
  undefined4 local_14c;
  longlong *local_38;
  
  plVar2 = (longlong *)(__security_cookie ^ (ulonglong)auStack_198);
  uVar6 = 1;
  if (0x1337 < param_3) {
    local_38 = plVar2;
    memset((void *)((longlong)param_4 + 0xc),0,0x132c);
    *param_4 = param_1;
    *(undefined4 *)(param_4 + 1) = 0;
    if (*(char *)(param_1 + 0x99) == '\0') {
      uVar3 = *(undefined8 *)(param_1 + 0xf8);
    }
    else {
      uVar3 = *(undefined8 *)(param_1 + 0xe8);
    }
    *(undefined8 *)((longlong)param_4 + 0xc) = uVar3;
    plVar4 = (longlong *)((longlong)param_4 + 0x1e);
    *(undefined4 *)((longlong)param_4 + 0x14) = 0;
    lVar7 = (longlong)L"Microsoft" - (longlong)plVar4;
    *(undefined4 *)(param_4 + 3) = 1;
    lVar5 = 0x40;
    do {
      if ((lVar5 == -0x7fffffbe) || (sVar1 = *(short *)(lVar7 + (longlong)plVar4), sVar1 == 0))
      break;
      *(short *)plVar4 = sVar1;
      plVar4 = (longlong *)((longlong)plVar4 + 2);
      lVar5 = lVar5 + -1;
    } while (lVar5 != 0);
    plVar2 = (longlong *)((longlong)plVar4 + -2);
    if (lVar5 != 0) {
      plVar2 = plVar4;
    }
    *(short *)plVar2 = 0;
    if (lVar5 != 0) {
      plVar4 = (longlong *)((longlong)param_4 + 0x122);
      lVar7 = 0x100;
      *(undefined2 *)((longlong)param_4 + 0x1c) = 0x80;
      *(undefined2 *)((longlong)param_4 + 0x9e) = 0x80;
      lVar5 = 0x100;
      lVar8 = (longlong)L"Virtual Fibre Channel HBA" - (longlong)plVar4;
      do {
        if ((lVar5 == -0x7ffffefe) || (sVar1 = *(short *)(lVar8 + (longlong)plVar4), sVar1 == 0))
        break;
        *(short *)plVar4 = sVar1;
        plVar4 = (longlong *)((longlong)plVar4 + 2);
        lVar5 = lVar5 + -1;
      } while (lVar5 != 0);
      plVar2 = (longlong *)((longlong)plVar4 + -2);
      if (lVar5 != 0) {
        plVar2 = plVar4;
      }
      *(short *)plVar2 = 0;
      if (lVar5 != 0) {
        plVar4 = (longlong *)((longlong)param_4 + 0x324);
        *(undefined2 *)(param_4 + 0x24) = 0x200;
        lVar8 = (longlong)L"Virtual Fibre Channel HBA Miniport" - (longlong)plVar4;
        lVar5 = 0x100;
        do {
          if ((lVar5 == -0x7ffffefe) || (sVar1 = *(short *)(lVar8 + (longlong)plVar4), sVar1 == 0))
          break;
          *(short *)plVar4 = sVar1;
          plVar4 = (longlong *)((longlong)plVar4 + 2);
          lVar5 = lVar5 + -1;
        } while (lVar5 != 0);
        plVar2 = (longlong *)((longlong)plVar4 + -2);
        if (lVar5 != 0) {
          plVar2 = plVar4;
        }
        *(short *)plVar2 = 0;
        if (lVar5 != 0) {
          *(undefined2 *)((longlong)param_4 + 0x322) = 0x200;
          *(undefined2 *)((longlong)param_4 + 0x524) = 0x200;
          *(undefined2 *)((longlong)param_4 + 0x726) = 0x200;
          memset(&local_154,0,0x118);
          local_158 = 0x11c;
          RtlGetVersion(&local_158);
          local_168 = 0;
          local_170 = local_14c;
          local_178 = local_150;
          plVar2 = (longlong *)
                   RtlStringCchPrintfW((wchar_t *)((longlong)param_4 + 0x92a),0x100,L"%u.%u.%u.%u",
                                       (ulonglong)local_154);
          if (-1 < (int)plVar2) {
            plVar4 = param_4 + 0x1e6;
            *(undefined2 *)(param_4 + 0x125) = 0x200;
            *(undefined2 *)((longlong)param_4 + 0xb2a) = 0x200;
            lVar8 = (longlong)L"fcvsc.sys" - (longlong)plVar4;
            *(undefined2 *)((longlong)param_4 + 0xd2c) = 0x200;
            lVar5 = 0x100;
            do {
              if ((lVar5 == -0x7ffffefe) ||
                 (sVar1 = *(short *)(lVar8 + (longlong)plVar4), sVar1 == 0)) break;
              *(short *)plVar4 = sVar1;
              plVar4 = (longlong *)((longlong)plVar4 + 2);
              lVar5 = lVar5 + -1;
            } while (lVar5 != 0);
            plVar2 = (longlong *)((longlong)plVar4 + -2);
            if (lVar5 != 0) {
              plVar2 = plVar4;
            }
            *(short *)plVar2 = 0;
            if (lVar5 != 0) {
              plVar4 = (longlong *)((longlong)param_4 + 0x1132);
              *(undefined2 *)((longlong)param_4 + 0xf2e) = 0x200;
              lVar5 = (longlong)L"com.microsoft" - (longlong)plVar4;
              do {
                if ((lVar7 == -0x7ffffefe) ||
                   (sVar1 = *(short *)(lVar5 + (longlong)plVar4), sVar1 == 0)) break;
                *(short *)plVar4 = sVar1;
                plVar4 = (longlong *)((longlong)plVar4 + 2);
                lVar7 = lVar7 + -1;
              } while (lVar7 != 0);
              plVar2 = (longlong *)((longlong)plVar4 + -2);
              if (lVar7 != 0) {
                plVar2 = plVar4;
              }
              *(short *)plVar2 = 0;
              if (lVar7 != 0) {
                *(undefined2 *)(param_4 + 0x226) = 0x200;
                *param_2 = 0x1338;
                goto LAB_140002a1c;
              }
            }
          }
        }
      }
    }
  }
  uVar6 = 0x12;
LAB_140002a1c:
  return CONCAT71((int7)((ulonglong)plVar2 >> 8),uVar6);
}



===== Request_MSFC_FibrePortHBAAttributes @ 140002a4c =====

undefined1
Request_MSFC_FibrePortHBAAttributes
          (longlong param_1,undefined4 *param_2,uint param_3,longlong *param_4)

{
  undefined8 uVar1;
  undefined1 uVar2;
  
  uVar2 = 1;
  if (param_3 < 0x88) {
    uVar2 = 0x12;
  }
  else {
    memset(param_4,0,(ulonglong)param_3);
    *param_4 = param_1 + 1;
    *(undefined4 *)(param_4 + 1) = 0;
    if (*(char *)(param_1 + 0x99) == '\0') {
      *(undefined8 *)((longlong)param_4 + 0xc) = *(undefined8 *)(param_1 + 0xf8);
      uVar1 = *(undefined8 *)(param_1 + 0xf0);
    }
    else {
      *(undefined8 *)((longlong)param_4 + 0xc) = *(undefined8 *)(param_1 + 0xe8);
      uVar1 = *(undefined8 *)(param_1 + 0xe0);
    }
    *(undefined8 *)((longlong)param_4 + 0x14) = uVar1;
    *(undefined4 *)((longlong)param_4 + 0x1c) = 0xffffffff;
    *(undefined4 *)(param_4 + 4) = 5;
    *(undefined4 *)((longlong)param_4 + 0x24) = 2;
    *(undefined4 *)(param_4 + 5) = 8;
    *(undefined8 *)((longlong)param_4 + 0x6c) = 0;
    *(undefined4 *)((longlong)param_4 + 0x74) = 0x800;
    *(undefined4 *)(param_4 + 0x10) = 0;
    *param_2 = 0x88;
  }
  return uVar2;
}



===== RtlStringCchPrintfW @ 140002b18 =====

undefined8
RtlStringCchPrintfW(wchar_t *param_1,longlong param_2,wchar_t *param_3,undefined8 param_4)

{
  ulonglong _Count;
  int iVar1;
  undefined8 uVar2;
  undefined8 local_res20;
  
  if (param_2 - 1U < 0x7fffffff) {
    _Count = param_2 - 1;
    uVar2 = 0;
    local_res20 = param_4;
    iVar1 = _vsnwprintf(param_1,_Count,param_3,(va_list)&local_res20);
    if ((iVar1 < 0) || (_Count < (ulonglong)(longlong)iVar1)) {
      uVar2 = 0x80000005;
    }
    else if ((longlong)iVar1 != _Count) {
      return 0;
    }
    param_1[_Count] = L'\0';
  }
  else {
    uVar2 = 0xc000000d;
    if (param_2 != 0) {
      *param_1 = L'\0';
    }
  }
  return uVar2;
}



===== VscAdapterControl @ 140002ba0 =====

bool VscAdapterControl(undefined8 param_1,int param_2,longlong param_3)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
             &WPP_95fe66d195233e1c089bc08587e1594c_Traceguids,param_2);
  }
  if (param_2 == 0) {
    *(undefined2 *)(param_3 + 5) = 0x101;
    *(undefined1 *)(param_3 + 4) = 1;
  }
  return param_2 != 0;
}



===== VscChannelEventNotification @ 140002c20 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 VscChannelEventNotification(undefined8 param_1,int *param_2)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  undefined8 uVar4;
  longlong lVar5;
  undefined1 auStackY_58 [32];
  undefined4 local_28;
  undefined8 local_20;
  undefined8 uStack_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_58;
  local_28 = 0;
  local_20 = 0;
  uStack_18 = 0;
  lVar5 = VmbChannelGetPointer();
  uVar4 = uStack_18;
  iVar3 = *param_2;
  lVar5 = *(longlong *)(lVar5 + 0x40);
  if (iVar3 == 0xb) {
    StorPortNotification(7,lVar5);
  }
  else if (iVar3 == 0xc) {
    VscUpdateHbaData(lVar5,(longlong)param_2);
  }
  else if (iVar3 == 0xe) {
    bVar1 = *(byte *)((longlong)param_2 + 0xe);
    bVar2 = *(byte *)((longlong)param_2 + 0xd);
    local_20 = CONCAT62(local_20._2_6_,1);
    uStack_18._3_5_ = SUB85(uVar4,3);
    uStack_18._0_3_ = CONCAT12((char)param_2[3],CONCAT11(bVar2,bVar1));
    local_20 = CONCAT44(4,(undefined4)local_20);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_DDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(ulonglong)bVar2,(ulonglong)bVar1,
                 (uint)bVar1,bVar2,(char)param_2[3]);
    }
    StorPortNotification(0x1007,lVar5,&local_20,*(undefined1 *)((longlong)param_2 + 0xf));
  }
  else {
    local_28 = 0xc000000d;
  }
  return local_28;
}



===== VscDriverUnload @ 140002d60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void VscDriverUnload(void)

{
  (*StorPortDriverUnload)();
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



===== VscPmEventDispatcher @ 140002dd0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void VscPmEventDispatcher(longlong param_1)

{
  bool bVar1;
  bool bVar2;
  short sVar3;
  int iVar4;
  longlong *plVar5;
  int *piVar6;
  undefined8 *puVar7;
  ulonglong uVar8;
  byte bVar9;
  longlong lVar10;
  undefined8 *puVar11;
  uint uVar12;
  longlong lVar13;
  byte bVar14;
  undefined1 auStack_128 [32];
  undefined1 local_108;
  undefined1 local_100;
  undefined8 local_f8;
  undefined1 *local_f0;
  longlong local_e8 [4];
  undefined1 local_c8 [144];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_128;
  lVar13 = param_1 + 0x40;
  plVar5 = local_e8;
  bVar2 = false;
  local_e8[1] = 0;
  local_e8[2] = 0;
  bVar14 = 1;
  lVar10 = 3;
  do {
    *plVar5 = lVar13;
    lVar13 = lVar13 + 0x18;
    plVar5 = plVar5 + 1;
    lVar10 = lVar10 + -1;
  } while (lVar10 != 0);
  do {
    local_f0 = local_c8;
    plVar5 = local_e8;
    local_f8 = 0;
    local_100 = 0;
    local_108 = 0;
    iVar4 = KeWaitForMultipleObjects(3,plVar5,1);
    if (iVar4 == 0) {
      puVar7 = (undefined8 *)VmbChannelGetPointer(*(undefined8 *)(param_1 + 0x18));
      iVar4 = VmbChannelEnable(*puVar7);
      if (-1 < iVar4) {
        uVar8 = StorChannelEstablishCommunications(*puVar7,plVar5);
        iVar4 = (int)uVar8;
        if (-1 < iVar4) {
          iVar4 = 0;
        }
      }
      *(undefined2 *)((longlong)puVar7 + 0x82) = 0;
      if (iVar4 < 0) {
        bVar14 = 4;
      }
      *(undefined1 *)((longlong)puVar7 + 0x84) = 0;
    }
    else if (iVar4 == 1) {
      lVar13 = *(longlong *)(param_1 + 0x88);
      bVar1 = false;
      if (lVar13 != 0) {
        if (*(char *)(lVar13 + 2) == '(') {
          if (*(uint *)(lVar13 + 0x38) != 0) {
            uVar8 = 0;
            do {
              uVar12 = *(uint *)(lVar13 + 0x78 + uVar8 * 4);
              if (((0x7f < uVar12) && (uVar12 < *(uint *)(lVar13 + 0x10))) &&
                 (piVar6 = (int *)(lVar13 + (ulonglong)uVar12), *piVar6 == 0x61))
              goto LAB_140002ed3;
              uVar12 = (int)uVar8 + 1;
              uVar8 = (ulonglong)uVar12;
            } while (uVar12 < *(uint *)(lVar13 + 0x38));
          }
        }
        piVar6 = (int *)0x0;
LAB_140002ed3:
        bVar1 = false;
        if (piVar6[4] == 3) {
          bVar1 = true;
        }
      }
      puVar7 = (undefined8 *)VmbChannelGetPointer(*(undefined8 *)(param_1 + 0x18));
      VmbChannelDisable(*puVar7);
      if (bVar1) {
        sVar3 = 0;
        puVar11 = puVar7 + 0x13;
        lVar13 = 0x3f;
        do {
          if (puVar11[-1] != 0) {
            sVar3 = sVar3 + 1;
            *(undefined1 *)puVar11 = 0;
          }
          puVar11 = puVar11 + 2;
          lVar13 = lVar13 + -1;
        } while (lVar13 != 0);
        *(short *)((longlong)puVar7 + 0x82) = sVar3;
        *(undefined1 *)((longlong)puVar7 + 0x84) = 1;
      }
      else {
        lVar13 = 0x3f;
        plVar5 = puVar7 + 0x12;
        do {
          if (*plVar5 != 0) {
            VmbChannelCleanup();
          }
          plVar5 = plVar5 + 2;
          lVar13 = lVar13 + -1;
        } while (lVar13 != 0);
        memset(puVar7 + 0x12,0,0x3f0);
      }
      StorChannelReevaluateSubChannels(puVar7);
    }
    else if (iVar4 == 2) {
      bVar2 = true;
    }
    lVar13 = *(longlong *)(param_1 + 0x88);
    if (lVar13 != 0) {
      if (*(char *)(lVar13 + 2) == '(') {
        bVar9 = bVar14 | 0x80;
        if (-1 < *(char *)(lVar13 + 3)) {
          bVar9 = bVar14;
        }
      }
      else {
        bVar9 = bVar14;
        if (*(char *)(lVar13 + 3) < '\0') {
          bVar9 = bVar14 | 0x80;
        }
      }
      *(byte *)(lVar13 + 3) = bVar9;
      StorPortNotification(0,param_1,*(undefined8 *)(param_1 + 0x88));
    }
    if (bVar2) {
      PsTerminateSystemThread(0);
      return;
    }
  } while( true );
}



===== VscSrbCompletion @ 140003080 =====

void VscSrbCompletion(undefined8 param_1,int param_2,longlong param_3,longlong param_4)

{
  longlong lVar1;
  longlong lVar2;
  char cVar3;
  undefined1 uVar4;
  byte bVar5;
  longlong lVar6;
  uint in_stack_ffffffffffffffc8;
  ulonglong in_stack_ffffffffffffffd8;
  
  lVar6 = VmbChannelGetPointer();
  lVar1 = *(longlong *)(param_4 + 0x18);
  lVar6 = *(longlong *)(lVar6 + 0x40);
  if (param_2 == 1) {
    StorChannelCopyPacketDataToSrb(param_1,param_3,lVar1);
    if ((Microsoft_Windows_Hyper_V_Virtual_Storage_ConsumerEnableBits & 2) != 0) {
      if (*(char *)(lVar1 + 2) == '(') {
        uVar4 = (undefined1)*(undefined4 *)(lVar1 + 0x20);
      }
      else {
        uVar4 = *(undefined1 *)(lVar1 + 8);
      }
      lVar2 = *(longlong *)(param_4 + 0x10);
      McTemplateK0qttjq_EtwWriteTransfer
                ((ulonglong)*(byte *)(lVar2 + 0x15),&STORVSC_COMPLETE_IO,lVar2,
                 (ulonglong)*(uint *)(lVar2 + 0x10),*(undefined1 *)(lVar2 + 0x14),
                 *(byte *)(lVar2 + 0x15),lVar6 + 0x20,uVar4);
    }
    bVar5 = KeGetCurrentIrql();
    if (bVar5 < 3) {
      StorPortNotification(0x1008,lVar6,lVar1);
      return;
    }
  }
  else {
    if (param_2 != 2) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
                 &WPP_95fe66d195233e1c089bc08587e1594c_Traceguids,param_2);
      }
      StorPortLogError(lVar6,0,0,0,in_stack_ffffffffffffffc8 & 0xffffff00,5,
                       in_stack_ffffffffffffffd8 & 0xffffffff00000000);
      return;
    }
    if (*(char *)(lVar1 + 2) == '(') {
      cVar3 = (*(char *)(lVar1 + 3) >> 7 & 0x80U) + 2;
    }
    else {
      cVar3 = '\x02';
      if (*(char *)(lVar1 + 3) < '\0') {
        cVar3 = -0x7e;
      }
    }
    *(char *)(lVar1 + 3) = cVar3;
  }
  StorPortNotification(0,lVar6,lVar1);
  return;
}



===== VscStartIO @ 140003260 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x000140003fcd) */

undefined8 VscStartIO(longlong *param_1,longlong param_2)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  uint uVar4;
  bool bVar5;
  int iVar6;
  undefined4 *puVar7;
  longlong lVar8;
  undefined8 *puVar9;
  int *piVar10;
  undefined8 uVar11;
  char cVar12;
  char cVar13;
  longlong *plVar14;
  ushort uVar15;
  ulonglong uVar16;
  int *piVar17;
  uint uVar18;
  short *psVar19;
  ulonglong uVar20;
  undefined1 uVar21;
  undefined1 auStackY_c8 [32];
  undefined8 in_stack_ffffffffffffff58;
  undefined8 local_80;
  longlong lStack_78;
  longlong local_70 [2];
  undefined8 local_60;
  undefined8 uStack_58;
  undefined4 local_50 [2];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_c8;
  piVar17 = (int *)0x0;
  local_70[0] = 0;
  bVar1 = *(byte *)(param_2 + 2);
  local_50[0] = 0;
  local_80 = 0;
  lStack_78 = 0;
  local_60 = 0;
  uStack_58 = 0;
  if (bVar1 == 0x28) {
    if (((*(uint *)(param_2 + 0x34) != 0) &&
        (psVar19 = (short *)((ulonglong)*(uint *)(param_2 + 0x34) + param_2),
        psVar19 != (short *)0x0)) && (*psVar19 == 1)) {
      bVar2 = *(byte *)((longlong)psVar19 + 9);
      cVar12 = (char)psVar19[5];
      goto LAB_1400032e6;
    }
LAB_1400032fc:
    uVar18 = *(uint *)(param_2 + 0x14);
LAB_140003303:
    if (0x20 < uVar18) {
      if (uVar18 == 0x24) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
                  &WPP_95fe66d195233e1c089bc08587e1594c_Traceguids);
        }
        if (*(char *)(param_2 + 2) == '(') {
          iVar6 = *(int *)(param_2 + 0x14);
          if (iVar6 == 0) {
            uVar18 = 0;
            if (*(uint *)(param_2 + 0x38) != 0) {
              do {
                uVar4 = *(uint *)(param_2 + 0x78 + (ulonglong)uVar18 * 4);
                if (((0x7f < uVar4) && (uVar4 < *(uint *)(param_2 + 0x10))) &&
                   (*(int *)((ulonglong)uVar4 + param_2) - 0x40U < 3)) {
                  piVar17 = (int *)((ulonglong)uVar4 + param_2);
                  break;
                }
                uVar18 = uVar18 + 1;
              } while (uVar18 < *(uint *)(param_2 + 0x38));
            }
          }
          else if (iVar6 == 10) {
            if (*(uint *)(param_2 + 0x38) != 0) {
              uVar18 = 0;
              do {
                uVar4 = *(uint *)(param_2 + 0x78 + (ulonglong)uVar18 * 4);
                if (((0x7f < uVar4) && (uVar4 < *(uint *)(param_2 + 0x10))) &&
                   (piVar10 = (int *)(param_2 + (ulonglong)uVar4), *piVar10 == 0x43))
                goto LAB_140003dc8;
                uVar18 = uVar18 + 1;
              } while (uVar18 < *(uint *)(param_2 + 0x38));
            }
          }
          else if (iVar6 == 0x17) {
            if (*(uint *)(param_2 + 0x38) != 0) {
              uVar18 = 0;
              do {
                uVar4 = *(uint *)(param_2 + 0x78 + (ulonglong)uVar18 * 4);
                if (((0x7f < uVar4) && (uVar4 < *(uint *)(param_2 + 0x10))) &&
                   (piVar10 = (int *)(param_2 + (ulonglong)uVar4), *piVar10 == 0x60))
                goto LAB_140003dc8;
                uVar18 = uVar18 + 1;
              } while (uVar18 < *(uint *)(param_2 + 0x38));
            }
          }
          else if (iVar6 == 0x24) {
            if (*(uint *)(param_2 + 0x38) != 0) {
              uVar18 = 0;
              do {
                uVar4 = *(uint *)(param_2 + 0x78 + (ulonglong)uVar18 * 4);
                if (((0x7f < uVar4) && (uVar4 < *(uint *)(param_2 + 0x10))) &&
                   (piVar10 = (int *)(param_2 + (ulonglong)uVar4), *piVar10 == 0x61))
                goto LAB_140003dc8;
                uVar18 = uVar18 + 1;
              } while (uVar18 < *(uint *)(param_2 + 0x38));
            }
          }
          else if (iVar6 == 0x25) {
            if (*(uint *)(param_2 + 0x38) != 0) {
              uVar18 = 0;
              do {
                uVar4 = *(uint *)(param_2 + 0x78 + (ulonglong)uVar18 * 4);
                if (((0x7f < uVar4) && (uVar4 < *(uint *)(param_2 + 0x10))) &&
                   (piVar10 = (int *)(param_2 + (ulonglong)uVar4), *piVar10 == 0x62))
                goto LAB_140003dc8;
                uVar18 = uVar18 + 1;
              } while (uVar18 < *(uint *)(param_2 + 0x38));
            }
          }
          else if (iVar6 == 0x2c) {
            if (*(uint *)(param_2 + 0x38) != 0) {
              uVar18 = 0;
              do {
                uVar4 = *(uint *)(param_2 + 0x78 + (ulonglong)uVar18 * 4);
                if (((0x7f < uVar4) && (uVar4 < *(uint *)(param_2 + 0x10))) &&
                   (piVar10 = (int *)(param_2 + (ulonglong)uVar4), *piVar10 == 0x44))
                goto LAB_140003dc8;
                uVar18 = uVar18 + 1;
              } while (uVar18 < *(uint *)(param_2 + 0x38));
            }
          }
        }
        goto LAB_140003ed7;
      }
      if (uVar18 == 0x25) {
        if (bVar1 == 0x28) {
          iVar6 = *(int *)(param_2 + 0x14);
          if (iVar6 == 0) {
            uVar18 = 0;
            if (*(uint *)(param_2 + 0x38) != 0) {
              do {
                uVar4 = *(uint *)(param_2 + 0x78 + (ulonglong)uVar18 * 4);
                if (((0x7f < uVar4) && (uVar4 < *(uint *)(param_2 + 0x10))) &&
                   (piVar17 = (int *)(param_2 + (ulonglong)uVar4), *piVar17 - 0x40U < 3))
                goto LAB_140003c89;
                uVar18 = uVar18 + 1;
              } while (uVar18 < *(uint *)(param_2 + 0x38));
            }
          }
          else if (iVar6 == 10) {
            if (*(uint *)(param_2 + 0x38) != 0) {
              uVar18 = 0;
              do {
                uVar4 = *(uint *)(param_2 + 0x78 + (ulonglong)uVar18 * 4);
                if (((0x7f < uVar4) && (uVar4 < *(uint *)(param_2 + 0x10))) &&
                   (piVar17 = (int *)(param_2 + (ulonglong)uVar4), *piVar17 == 0x43))
                goto LAB_140003c89;
                uVar18 = uVar18 + 1;
              } while (uVar18 < *(uint *)(param_2 + 0x38));
            }
          }
          else if (iVar6 == 0x17) {
            if (*(uint *)(param_2 + 0x38) != 0) {
              uVar18 = 0;
              do {
                uVar4 = *(uint *)(param_2 + 0x78 + (ulonglong)uVar18 * 4);
                if (((0x7f < uVar4) && (uVar4 < *(uint *)(param_2 + 0x10))) &&
                   (piVar17 = (int *)(param_2 + (ulonglong)uVar4), *piVar17 == 0x60))
                goto LAB_140003c89;
                uVar18 = uVar18 + 1;
              } while (uVar18 < *(uint *)(param_2 + 0x38));
            }
          }
          else if (iVar6 == 0x24) {
            if (*(uint *)(param_2 + 0x38) != 0) {
              uVar18 = 0;
              do {
                uVar4 = *(uint *)(param_2 + 0x78 + (ulonglong)uVar18 * 4);
                if (((0x7f < uVar4) && (uVar4 < *(uint *)(param_2 + 0x10))) &&
                   (piVar17 = (int *)(param_2 + (ulonglong)uVar4), *piVar17 == 0x61))
                goto LAB_140003c89;
                uVar18 = uVar18 + 1;
              } while (uVar18 < *(uint *)(param_2 + 0x38));
            }
          }
          else if (iVar6 == 0x25) {
            if (*(uint *)(param_2 + 0x38) != 0) {
              uVar18 = 0;
              do {
                uVar4 = *(uint *)(param_2 + 0x78 + (ulonglong)uVar18 * 4);
                if (((0x7f < uVar4) && (uVar4 < *(uint *)(param_2 + 0x10))) &&
                   (piVar17 = (int *)(param_2 + (ulonglong)uVar4), *piVar17 == 0x62))
                goto LAB_140003c89;
                uVar18 = uVar18 + 1;
              } while (uVar18 < *(uint *)(param_2 + 0x38));
            }
          }
          else if ((iVar6 == 0x2c) && (*(uint *)(param_2 + 0x38) != 0)) {
            uVar18 = 0;
            do {
              uVar4 = *(uint *)(param_2 + 0x78 + (ulonglong)uVar18 * 4);
              if (((0x7f < uVar4) && (uVar4 < *(uint *)(param_2 + 0x10))) &&
                 (piVar17 = (int *)(param_2 + (ulonglong)uVar4), *piVar17 == 0x44))
              goto LAB_140003c89;
              uVar18 = uVar18 + 1;
            } while (uVar18 < *(uint *)(param_2 + 0x38));
          }
        }
        piVar17 = (int *)0x0;
LAB_140003c89:
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
                   &WPP_95fe66d195233e1c089bc08587e1594c_Traceguids,piVar17[3]);
        }
        bVar1 = *(byte *)(param_2 + 2);
        if (piVar17[3] != 9) goto LAB_140003502;
        if (bVar1 == 0x28) {
          puVar9 = *(undefined8 **)(param_2 + 0x40);
        }
        else {
          puVar9 = *(undefined8 **)(param_2 + 0x18);
        }
        *puVar9 = 0;
        cVar3 = *(char *)(param_2 + 3);
        if (*(char *)(param_2 + 2) == '(') {
          cVar12 = (cVar3 >> 7 & 0x80U) + 1;
LAB_14000386b:
          *(char *)(param_2 + 3) = cVar12;
          goto LAB_140003faa;
        }
        cVar12 = '\x01';
        cVar13 = -0x7f;
      }
      else if (uVar18 == 0x26) {
        if (bVar1 == 0x28) {
          puVar7 = *(undefined4 **)(param_2 + 0x40);
        }
        else {
          puVar7 = *(undefined4 **)(param_2 + 0x18);
        }
        memset(puVar7 + 1,0,0x6c);
        *puVar7 = 0x700100;
        lVar8 = *(longlong *)(*param_1 + 8);
        uVar15 = *(ushort *)(lVar8 + 0x38) >> 1;
        if (uVar15 != 0) {
          do {
            if (*(short *)(*(longlong *)(lVar8 + 0x40) + -2 + (ulonglong)uVar15 * 2) == 0x5c) break;
            uVar15 = uVar15 - 1;
          } while (uVar15 != 0);
        }
        lStack_78 = *(longlong *)(lVar8 + 0x40) + (ulonglong)uVar15 * 2;
        local_80._0_4_ =
             CONCAT22(*(short *)(lVar8 + 0x3a) + uVar15 * -2,*(short *)(lVar8 + 0x38) + uVar15 * -2)
        ;
        uVar11 = RtlStringCchPrintfW((wchar_t *)(puVar7 + 1),0xf,L"%wZ.sys",&local_80);
        lStack_78 = 0;
        local_80 = (ulonglong)local_80._4_4_ << 0x20;
        if ((int)uVar11 < 0) {
LAB_140003859:
          cVar3 = *(char *)(param_2 + 3);
          cVar12 = *(char *)(param_2 + 2);
        }
        else {
          *(undefined8 *)(puVar7 + 10) = 0;
          *(undefined8 *)(puVar7 + 0xc) = 0;
          lVar8 = VmbChannelGetPointer(param_1[3]);
          puVar7[0x14] = *(undefined4 *)(lVar8 + 0x54);
          Feature_CrashDumpOneMBTransferSize__private_IsEnabledDeviceUsageNoInline();
          puVar7[0xe] = 0x8000;
          if (0x8000 < (uint)puVar7[0x14]) {
            puVar7[0x14] = 0x8000;
          }
          *(undefined8 *)(puVar7 + 0x16) = 1;
          puVar7[0x15] = 0x81;
          *(undefined1 *)(puVar7 + 0x1a) = 8;
          *(undefined2 *)((longlong)puVar7 + 0x6a) = 0x8003;
          if (param_1[6] != 0) {
            *(longlong *)(puVar7 + 0x10) = param_1[6];
            if (*(char *)(param_2 + 2) == '(') {
              cVar12 = (*(char *)(param_2 + 3) >> 7 & 0x80U) + 1;
            }
            else {
              cVar12 = -0x7f;
              if (-1 < *(char *)(param_2 + 3)) {
                cVar12 = '\x01';
              }
            }
            *(char *)(param_2 + 3) = cVar12;
            if (*(char *)(param_2 + 2) != '(') goto LAB_140003a82;
            bVar5 = false;
            if ((*(int *)(param_2 + 0x14) == 0) && (uVar20 = 0, *(int *)(param_2 + 0x38) != 0)) {
              do {
                uVar18 = *(uint *)(param_2 + 0x78 + uVar20 * 4);
                if ((0x7f < uVar18) && (uVar4 = *(uint *)(param_2 + 0x10), uVar18 < uVar4)) {
                  uVar16 = (ulonglong)uVar18;
                  iVar6 = *(int *)(param_2 + (ulonglong)uVar18);
                  if (iVar6 == 0x40) {
LAB_140003a4b:
                    if (uVar16 + 0x28 <= (ulonglong)uVar4) goto LAB_14000340d;
                  }
                  else if (iVar6 == 0x41) {
                    if (uVar16 + 0x38 <= (ulonglong)uVar4) {
                      bVar5 = true;
                      *(undefined1 *)(param_2 + 8 + uVar16) = 0;
                    }
                  }
                  else if (iVar6 == 0x42) goto LAB_140003a4b;
                  if (bVar5) break;
                }
                uVar18 = (int)uVar20 + 1;
                uVar20 = (ulonglong)uVar18;
              } while (uVar18 < *(uint *)(param_2 + 0x38));
            }
            goto LAB_140003faa;
          }
          iVar6 = StorPortExtendedFunction(0,param_1,0x18,0x48636656);
          if (iVar6 == 0) {
            lRam0000000000000008 = param_2;
            lRam0000000000000010 = IoAllocateWorkItem(*param_1);
            plRam0000000000000000 = param_1;
            if (lRam0000000000000010 != 0) {
LAB_1400038bb:
              uVar11 = IoQueueWorkItem(lRam0000000000000010,VscGetCrashInterfaceWorker,1);
              plRam0000000000000000 = param_1;
              goto LAB_140003fdf;
            }
          }
          cVar3 = *(char *)(param_2 + 3);
          cVar12 = *(char *)(param_2 + 2);
        }
        if (cVar12 == '(') {
          cVar12 = (cVar3 >> 7 & 0x80U) + 4;
          goto LAB_14000386b;
        }
        cVar12 = '\x04';
        cVar13 = -0x7c;
      }
      else {
        if (uVar18 != 0x27) {
          if (uVar18 == 0x2a) {
            if (bVar1 == 0x28) {
              puVar7 = *(undefined4 **)(param_2 + 0x40);
            }
            else {
              puVar7 = *(undefined4 **)(param_2 + 0x18);
            }
            *(undefined8 *)(puVar7 + 3) = 0;
            puVar7[5] = 0;
            *puVar7 = 0x18;
            puVar7[1] = 0x18;
            puVar7[2] = 0x4d504449;
            if (param_1[6] != 0) {
              *(longlong *)(puVar7 + 4) = param_1[6];
              if (*(char *)(param_2 + 2) == '(') {
                cVar12 = (*(char *)(param_2 + 3) >> 7 & 0x80U) + 1;
              }
              else if (*(char *)(param_2 + 3) < '\0') {
                cVar12 = -0x7f;
              }
              else {
                cVar12 = '\x01';
              }
              *(char *)(param_2 + 3) = cVar12;
              if (*(char *)(param_2 + 2) != '(') goto LAB_140003a82;
              bVar5 = false;
              if ((*(int *)(param_2 + 0x14) == 0) && (uVar20 = 0, *(int *)(param_2 + 0x38) != 0)) {
                do {
                  uVar18 = *(uint *)(param_2 + 0x78 + uVar20 * 4);
                  if ((0x7f < uVar18) && (uVar4 = *(uint *)(param_2 + 0x10), uVar18 < uVar4)) {
                    uVar16 = (ulonglong)uVar18;
                    iVar6 = *(int *)((ulonglong)uVar18 + param_2);
                    if (iVar6 == 0x40) {
LAB_1400037f8:
                      if (uVar16 + 0x28 <= (ulonglong)uVar4) {
                        *(undefined1 *)(uVar16 + 8 + param_2) = 0;
                        break;
                      }
                    }
                    else if (iVar6 == 0x41) {
                      if (uVar16 + 0x38 <= (ulonglong)uVar4) {
                        bVar5 = true;
                        *(undefined1 *)(uVar16 + 8 + param_2) = 0;
                      }
                    }
                    else if (iVar6 == 0x42) goto LAB_1400037f8;
                    if (bVar5) break;
                  }
                  uVar18 = (int)uVar20 + 1;
                  uVar20 = (ulonglong)uVar18;
                } while (uVar18 < *(uint *)(param_2 + 0x38));
              }
              goto LAB_140003faa;
            }
            iVar6 = StorPortExtendedFunction(0,param_1,0x18,0x48636656);
            if (iVar6 == 0) {
              lRam0000000000000008 = param_2;
              lRam0000000000000010 = IoAllocateWorkItem(*param_1);
              plRam0000000000000000 = param_1;
              if (lRam0000000000000010 != 0) goto LAB_1400038bb;
            }
            goto LAB_140003859;
          }
          if (uVar18 != 0x2b) goto LAB_140003502;
        }
        cVar3 = *(char *)(param_2 + 3);
        if (bVar1 == 0x28) {
          *(byte *)(param_2 + 3) = (cVar3 >> 7 & 0x80U) + 1;
          goto LAB_140003faa;
        }
        cVar12 = '\x01';
        cVar13 = -0x7f;
      }
      if (cVar3 < '\0') {
        cVar12 = cVar13;
      }
      goto LAB_140003524;
    }
    if (uVar18 == 0x20) {
LAB_140003658:
      if (bVar1 == 0x28) {
        cVar12 = (*(char *)(param_2 + 3) >> 7 & 0x80U) + 1;
      }
      else if (*(char *)(param_2 + 3) < '\0') {
        cVar12 = -0x7f;
      }
      else {
        cVar12 = '\x01';
      }
      *(char *)(param_2 + 3) = cVar12;
      if (*(char *)(param_2 + 2) != '(') goto LAB_140003a82;
      bVar5 = false;
      if ((*(int *)(param_2 + 0x14) == 0) && (uVar20 = 0, *(int *)(param_2 + 0x38) != 0)) {
        do {
          uVar18 = *(uint *)(param_2 + 0x78 + uVar20 * 4);
          if ((0x7f < uVar18) && (uVar4 = *(uint *)(param_2 + 0x10), uVar18 < uVar4)) {
            uVar16 = (ulonglong)uVar18;
            iVar6 = *(int *)(param_2 + (ulonglong)uVar18);
            if (iVar6 == 0x40) {
LAB_1400036c7:
              if (uVar16 + 0x28 <= (ulonglong)uVar4) goto LAB_14000340d;
            }
            else if (iVar6 == 0x41) {
              if (uVar16 + 0x38 <= (ulonglong)uVar4) {
                bVar5 = true;
                *(undefined1 *)(param_2 + 8 + uVar16) = 0;
              }
            }
            else if (iVar6 == 0x42) goto LAB_1400036c7;
            if (bVar5) break;
          }
          uVar18 = (int)uVar20 + 1;
          uVar20 = (ulonglong)uVar18;
        } while (uVar18 < *(uint *)(param_2 + 0x38));
      }
      goto LAB_140003faa;
    }
    if (uVar18 == 0) {
      if (bVar1 == 0x28) {
        lVar8 = *(longlong *)(param_2 + 0x68);
      }
      else {
        lVar8 = *(longlong *)(param_2 + 0x38);
      }
      StorPortExtendedFunction(6,param_1,param_2,local_70);
      if ((Microsoft_Windows_Hyper_V_Virtual_Storage_ConsumerEnableBits & 1) != 0) {
        VscStartIOTrace((longlong)param_1,param_2,lVar8 + 0x40);
      }
      local_60 = 0x1400000002;
      iVar6 = StorPortExtendedFunction(0xf,param_1,param_2,&local_60);
      if (iVar6 == 0) {
        uVar18 = KeGetProcessorIndexFromNumber(local_50);
        if (uVar18 == 0xffffffff) goto LAB_1400035b5;
      }
      else {
LAB_1400035b5:
        uVar18 = SystemReserved1[0x12]._4_4_;
      }
      uVar11 = StorChannelSendSrbRequest
                         (param_1[3],uVar18,param_2,local_70[0],in_stack_ffffffffffffff58,
                          (longlong *)(lVar8 + 0x20),lVar8 + 0x60,lVar8 + 0x40);
      if (-1 < (int)uVar11) goto LAB_140003fdf;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
                 &WPP_95fe66d195233e1c089bc08587e1594c_Traceguids,(int)uVar11);
      }
      if (*(char *)(param_2 + 2) == '(') {
        cVar12 = (*(char *)(param_2 + 3) >> 7 & 0x80U) + 2;
        goto LAB_140003524;
      }
      uVar21 = 2;
      if (*(char *)(param_2 + 3) < '\0') {
        uVar21 = 0x82;
      }
      *(undefined1 *)(param_2 + 3) = uVar21;
    }
    else {
      if (uVar18 == 2) {
LAB_140003502:
        if (bVar1 == 0x28) {
          cVar12 = (*(char *)(param_2 + 3) >> 7 & 0x80U) + 6;
          goto LAB_140003fa7;
        }
        cVar12 = '\x06';
        if (*(char *)(param_2 + 3) < '\0') {
          cVar12 = -0x7a;
        }
        goto LAB_140003524;
      }
      if (uVar18 == 7) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
                  &WPP_95fe66d195233e1c089bc08587e1594c_Traceguids);
        }
        if (*(char *)(param_2 + 2) == '(') {
          cVar12 = (*(char *)(param_2 + 3) >> 7 & 0x80U) + 1;
        }
        else {
          cVar12 = '\x01';
          if (*(char *)(param_2 + 3) < '\0') {
            cVar12 = -0x7f;
          }
        }
        *(char *)(param_2 + 3) = cVar12;
        if (*(char *)(param_2 + 2) == '(') {
          bVar5 = false;
          if ((*(int *)(param_2 + 0x14) == 0) && (uVar20 = 0, *(int *)(param_2 + 0x38) != 0)) {
            do {
              uVar18 = *(uint *)(param_2 + 0x78 + uVar20 * 4);
              if ((0x7f < uVar18) && (uVar4 = *(uint *)(param_2 + 0x10), uVar18 < uVar4)) {
                uVar16 = (ulonglong)uVar18;
                iVar6 = *(int *)(param_2 + (ulonglong)uVar18);
                if (iVar6 == 0x40) {
LAB_1400034c8:
                  if (uVar16 + 0x28 <= (ulonglong)uVar4) goto LAB_14000340d;
                }
                else if (iVar6 == 0x41) {
                  if (uVar16 + 0x38 <= (ulonglong)uVar4) {
                    bVar5 = true;
                    *(undefined1 *)(param_2 + 8 + uVar16) = 0;
                  }
                }
                else if (iVar6 == 0x42) goto LAB_1400034c8;
                if (bVar5) break;
              }
              uVar18 = (int)uVar20 + 1;
              uVar20 = (ulonglong)uVar18;
            } while (uVar18 < *(uint *)(param_2 + 0x38));
          }
        }
        else {
LAB_140003a82:
          *(undefined1 *)(param_2 + 4) = 0;
        }
      }
      else if (uVar18 == 8) {
        if (bVar1 == 0x28) {
          cVar12 = (*(char *)(param_2 + 3) >> 7 & 0x80U) + 1;
        }
        else {
          cVar12 = '\x01';
          if (*(char *)(param_2 + 3) < '\0') {
            cVar12 = -0x7f;
          }
        }
        *(char *)(param_2 + 3) = cVar12;
        if (*(char *)(param_2 + 2) != '(') goto LAB_140003a82;
        bVar5 = false;
        if ((*(int *)(param_2 + 0x14) == 0) && (uVar20 = 0, *(int *)(param_2 + 0x38) != 0)) {
          do {
            uVar18 = *(uint *)(param_2 + 0x78 + uVar20 * 4);
            if ((0x7f < uVar18) && (uVar4 = *(uint *)(param_2 + 0x10), uVar18 < uVar4)) {
              uVar16 = (ulonglong)uVar18;
              iVar6 = *(int *)(param_2 + (ulonglong)uVar18);
              if (iVar6 == 0x40) {
LAB_1400033da:
                if (uVar16 + 0x28 <= (ulonglong)uVar4) goto LAB_14000340d;
              }
              else if (iVar6 == 0x41) {
                if (uVar16 + 0x38 <= (ulonglong)uVar4) {
                  bVar5 = true;
                  *(undefined1 *)(param_2 + 8 + uVar16) = 0;
                }
              }
              else if (iVar6 == 0x42) goto LAB_1400033da;
              if (bVar5) break;
            }
            uVar18 = (int)uVar20 + 1;
            uVar20 = (ulonglong)uVar18;
          } while (uVar18 < *(uint *)(param_2 + 0x38));
        }
      }
      else {
        if ((uVar18 == 0x12) || (uVar18 == 0x13)) goto LAB_140003658;
        if (uVar18 != 0x17) goto LAB_140003502;
        VscWmiSrb((longlong)param_1,param_2);
      }
    }
  }
  else {
    bVar2 = *(byte *)(param_2 + 6);
    cVar12 = *(char *)(param_2 + 7);
LAB_1400032e6:
    if ((bVar2 < 0x80) && (cVar12 != -1)) {
      if (bVar1 == 0x28) goto LAB_1400032fc;
      uVar18 = (uint)bVar1;
      goto LAB_140003303;
    }
    if (bVar1 == 0x28) {
      bVar5 = false;
      if ((*(int *)(param_2 + 0x14) == 0) && (uVar20 = 0, *(int *)(param_2 + 0x38) != 0)) {
        do {
          uVar18 = *(uint *)(param_2 + 0x78 + uVar20 * 4);
          if ((0x7f < uVar18) && (uVar4 = *(uint *)(param_2 + 0x10), uVar18 < uVar4)) {
            uVar16 = (ulonglong)uVar18;
            iVar6 = *(int *)(param_2 + (ulonglong)uVar18);
            if (iVar6 == 0x40) {
LAB_140003f4b:
              if (uVar16 + 0x28 <= (ulonglong)uVar4) {
                *(undefined1 *)(param_2 + 8 + uVar16) = 2;
                break;
              }
            }
            else if (iVar6 == 0x41) {
              if (uVar16 + 0x38 <= (ulonglong)uVar4) {
                bVar5 = true;
                *(undefined1 *)(param_2 + 8 + uVar16) = 2;
              }
            }
            else if (iVar6 == 0x42) goto LAB_140003f4b;
            if (bVar5) break;
          }
          uVar18 = (int)uVar20 + 1;
          uVar20 = (ulonglong)uVar18;
        } while (uVar18 < *(uint *)(param_2 + 0x38));
      }
    }
    else {
      *(undefined1 *)(param_2 + 4) = 2;
    }
    if (*(char *)(param_2 + 2) != '(') {
      cVar12 = '!';
      if (*(char *)(param_2 + 3) < '\0') {
        cVar12 = -0x5f;
      }
LAB_140003fa7:
      *(char *)(param_2 + 3) = cVar12;
      goto LAB_140003faa;
    }
    cVar12 = (*(char *)(param_2 + 3) >> 7 & 0x80U) + 0x21;
LAB_140003524:
    *(char *)(param_2 + 3) = cVar12;
  }
LAB_140003faa:
  uVar11 = StorPortNotification(0,param_1,param_2);
LAB_140003fdf:
  return CONCAT71((int7)((ulonglong)uVar11 >> 8),1);
LAB_140003dc8:
  piVar17 = piVar10;
LAB_140003ed7:
  param_1[0x11] = param_2;
  if (piVar17[3] == 1) {
    plVar14 = param_1 + 8;
  }
  else {
    plVar14 = param_1 + 0xb;
  }
  uVar11 = KeSetEvent(plVar14,0,0);
  goto LAB_140003fdf;
LAB_14000340d:
  *(undefined1 *)(param_2 + 8 + uVar16) = 0;
  goto LAB_140003faa;
}



===== VscStartIOTrace @ 140004010 =====

void VscStartIOTrace(longlong param_1,longlong param_2,longlong param_3)

{
  char cVar1;
  bool bVar2;
  undefined1 uVar3;
  int iVar4;
  ulonglong uVar5;
  short *psVar6;
  char *pcVar7;
  char *pcVar8;
  uint uVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  
  if (*(char *)(param_2 + 2) == '(') {
    pcVar7 = (char *)0x0;
    bVar2 = false;
    pcVar8 = pcVar7;
    if (*(int *)(param_2 + 0x14) == 0) {
      uVar10 = 0;
      if (*(uint *)(param_2 + 0x38) != 0) {
        do {
          uVar9 = *(uint *)(param_2 + 0x78 + uVar10 * 4);
          if ((0x7f < uVar9) &&
             (uVar11 = (ulonglong)*(uint *)(param_2 + 0x10), uVar9 < *(uint *)(param_2 + 0x10))) {
            uVar5 = (ulonglong)uVar9;
            iVar4 = *(int *)((ulonglong)uVar9 + param_2);
            pcVar8 = pcVar7;
            if (iVar4 == 0x40) {
              if (uVar5 + 0x28 <= uVar11) {
                if (*(char *)(uVar5 + 10 + param_2) != '\0') {
                  pcVar8 = (char *)(param_2 + 0x18 + uVar5);
                }
                break;
              }
            }
            else if (iVar4 == 0x41) {
              if (uVar5 + 0x38 <= uVar11) {
                bVar2 = true;
                if (*(char *)(uVar5 + 10 + param_2) == '\0') break;
                pcVar7 = (char *)(param_2 + 0x18 + uVar5);
              }
            }
            else if ((iVar4 == 0x42) && (uVar5 + 0x28 <= uVar11)) {
              pcVar8 = (char *)(param_2 + 0x20 + uVar5);
              if (*(int *)(uVar5 + 0xc + param_2) == 0) {
                pcVar8 = pcVar7;
              }
              break;
            }
            pcVar8 = pcVar7;
            if (bVar2) break;
          }
          uVar9 = (int)uVar10 + 1;
          uVar10 = (ulonglong)uVar9;
          pcVar8 = pcVar7;
        } while (uVar9 < *(uint *)(param_2 + 0x38));
      }
    }
    if (((*(uint *)(param_2 + 0x34) != 0) &&
        (psVar6 = (short *)((ulonglong)*(uint *)(param_2 + 0x34) + param_2), psVar6 != (short *)0x0)
        ) && (*psVar6 == 1)) {
    }
  }
  else {
    pcVar8 = (char *)(param_2 + 0x48);
  }
  iVar4 = StorPortExtendedFunction(0x28,param_1,param_2,param_3);
  if (iVar4 < 0) {
    EtwActivityIdControl(3,param_3);
  }
  if (*(char *)(param_2 + 2) == '(') {
    uVar9 = *(uint *)(param_2 + 0x3c);
  }
  else {
    uVar9 = *(uint *)(param_2 + 0x10);
  }
  *(uint *)(param_3 + 0x10) = uVar9;
  if (pcVar8 == (char *)0x0) goto LAB_140004187;
  cVar1 = *pcVar8;
  if (cVar1 == '\b') {
LAB_140004183:
    *(undefined1 *)(param_3 + 0x14) = 1;
  }
  else {
    if (cVar1 != '\n') {
      if (cVar1 == '(') goto LAB_140004183;
      if (cVar1 != '*') {
        if (cVar1 == -0x78) goto LAB_140004183;
        if (cVar1 != -0x76) {
          if (cVar1 == -0x58) goto LAB_140004183;
          if (cVar1 != -0x56) goto LAB_140004187;
        }
      }
    }
    *(undefined1 *)(param_3 + 0x15) = 1;
  }
LAB_140004187:
  if ((Microsoft_Windows_Hyper_V_Virtual_Storage_ConsumerEnableBits & 1) != 0) {
    if (*(char *)(param_2 + 2) == '(') {
      uVar3 = (undefined1)*(undefined4 *)(param_2 + 0x20);
    }
    else {
      uVar3 = *(undefined1 *)(param_2 + 8);
    }
    McTemplateK0qttjq_EtwWriteTransfer
              ((ulonglong)*(byte *)(param_3 + 0x15),&STORVSC_START_IO,param_3,(ulonglong)uVar9,
               *(undefined1 *)(param_3 + 0x14),*(byte *)(param_3 + 0x15),param_1 + 0x20,uVar3);
  }
  return;
}



===== VscWmiSrb @ 1400041fc =====

void VscWmiSrb(longlong param_1,longlong param_2)

{
  int iVar1;
  uint uVar2;
  byte bVar3;
  char cVar4;
  uint *puVar5;
  int *piVar6;
  uint uVar7;
  longlong lVar8;
  byte bVar9;
  longlong *plVar10;
  bool bVar11;
  int local_res10 [2];
  uint local_res18 [2];
  
  cVar4 = *(char *)(param_2 + 2);
  if (cVar4 == '(') {
    iVar1 = *(int *)(param_2 + 0x14);
    if (iVar1 == 0) {
      uVar7 = 0;
      if (*(uint *)(param_2 + 0x38) != 0) {
        do {
          uVar2 = *(uint *)(param_2 + 0x78 + (ulonglong)uVar7 * 4);
          if (((0x7f < uVar2) && (uVar2 < *(uint *)(param_2 + 0x10))) &&
             (piVar6 = (int *)((ulonglong)uVar2 + param_2), *piVar6 - 0x40U < 3))
          goto LAB_1400042e1;
          uVar7 = uVar7 + 1;
        } while (uVar7 < *(uint *)(param_2 + 0x38));
      }
      goto LAB_140004384;
    }
    if (iVar1 == 10) {
      if (*(uint *)(param_2 + 0x38) != 0) {
        uVar7 = 0;
        do {
          uVar2 = *(uint *)(param_2 + 0x78 + (ulonglong)uVar7 * 4);
          if (((0x7f < uVar2) && (uVar2 < *(uint *)(param_2 + 0x10))) &&
             (piVar6 = (int *)((ulonglong)uVar2 + param_2), *piVar6 == 0x43)) goto LAB_1400042e1;
          uVar7 = uVar7 + 1;
        } while (uVar7 < *(uint *)(param_2 + 0x38));
      }
    }
    else if (iVar1 == 0x17) {
      if (*(uint *)(param_2 + 0x38) != 0) {
        uVar7 = 0;
        do {
          uVar2 = *(uint *)(param_2 + 0x78 + (ulonglong)uVar7 * 4);
          if (((0x7f < uVar2) && (uVar2 < *(uint *)(param_2 + 0x10))) &&
             (piVar6 = (int *)((ulonglong)uVar2 + param_2), *piVar6 == 0x60)) goto LAB_1400042e1;
          uVar7 = uVar7 + 1;
        } while (uVar7 < *(uint *)(param_2 + 0x38));
      }
    }
    else if (iVar1 == 0x24) {
      if (*(uint *)(param_2 + 0x38) != 0) {
        uVar7 = 0;
        do {
          uVar2 = *(uint *)(param_2 + 0x78 + (ulonglong)uVar7 * 4);
          if (((0x7f < uVar2) && (uVar2 < *(uint *)(param_2 + 0x10))) &&
             (piVar6 = (int *)((ulonglong)uVar2 + param_2), *piVar6 == 0x61)) goto LAB_1400042e1;
          uVar7 = uVar7 + 1;
        } while (uVar7 < *(uint *)(param_2 + 0x38));
      }
    }
    else if (iVar1 == 0x25) {
      if (*(uint *)(param_2 + 0x38) != 0) {
        uVar7 = 0;
        do {
          uVar2 = *(uint *)(param_2 + 0x78 + (ulonglong)uVar7 * 4);
          if (((0x7f < uVar2) && (uVar2 < *(uint *)(param_2 + 0x10))) &&
             (piVar6 = (int *)((ulonglong)uVar2 + param_2), *piVar6 == 0x62)) goto LAB_1400042e1;
          uVar7 = uVar7 + 1;
        } while (uVar7 < *(uint *)(param_2 + 0x38));
      }
    }
    else {
      if (iVar1 != 0x2c) goto LAB_140004384;
      if (*(uint *)(param_2 + 0x38) != 0) {
        uVar7 = 0;
        do {
          uVar2 = *(uint *)(param_2 + 0x78 + (ulonglong)uVar7 * 4);
          if (((0x7f < uVar2) && (uVar2 < *(uint *)(param_2 + 0x10))) &&
             (piVar6 = (int *)((ulonglong)uVar2 + param_2), *piVar6 == 0x44)) goto LAB_1400042e1;
          uVar7 = uVar7 + 1;
        } while (uVar7 < *(uint *)(param_2 + 0x38));
      }
    }
    piVar6 = (int *)0x0;
LAB_1400042e1:
    if (piVar6 == (int *)0x0) goto LAB_140004384;
    bVar3 = *(byte *)((longlong)piVar6 + 9);
    bVar9 = *(byte *)(piVar6 + 2);
    plVar10 = *(longlong **)(piVar6 + 4);
  }
  else {
LAB_140004384:
    bVar3 = *(byte *)(param_2 + 9);
    bVar9 = *(byte *)(param_2 + 4);
    plVar10 = *(longlong **)(param_2 + 0x20);
  }
  if ((bVar3 & 1) != 0) {
    if (cVar4 == '(') {
      lVar8 = *(longlong *)(param_2 + 0x68);
    }
    else {
      lVar8 = *(longlong *)(param_2 + 0x38);
    }
    if (*(longlong *)(param_1 + 0xb0) != 0) {
      if (cVar4 == '(') {
        puVar5 = *(uint **)(param_2 + 0x40);
        uVar7 = *(uint *)(param_2 + 0x3c);
      }
      else {
        puVar5 = *(uint **)(param_2 + 0x18);
        uVar7 = *(uint *)(param_2 + 0x10);
      }
      local_res10[0] = 0;
      local_res18[0] = 0;
      *(undefined4 *)(lVar8 + 0x1c) = 0;
      if (bVar9 < 10) {
        *(uint *)(lVar8 + 8) = uVar7;
        *(byte *)(lVar8 + 0x18) = bVar9;
        *(uint **)(lVar8 + 0x10) = puVar5;
        cVar4 = ScsiWmipProcessRequest
                          ((uint *)(param_1 + 0xa0),bVar9,param_1,lVar8,plVar10,uVar7,puVar5,
                           local_res18,local_res10);
        if (local_res10[0] == 1) {
          *(char *)(lVar8 + 0x19) = cVar4;
          if (cVar4 != '\x01') {
            local_res18[0] = 0;
          }
          *(uint *)(lVar8 + 0x1c) = local_res18[0];
        }
        if (cVar4 == '\0') {
          if (*(char *)(param_2 + 2) == '(') {
            bVar3 = *(char *)(param_2 + 3) >> 7 & 0x80;
          }
          else if (*(char *)(param_2 + 3) < '\0') {
            bVar3 = 0x80;
          }
          else {
            bVar3 = 0;
          }
          goto LAB_1400044d6;
        }
      }
      else {
        *(undefined1 *)(lVar8 + 0x19) = 4;
      }
      bVar11 = *(char *)(param_2 + 2) != '(';
      if (bVar11) {
        *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(lVar8 + 0x1c);
      }
      else {
        *(undefined4 *)(param_2 + 0x3c) = *(undefined4 *)(lVar8 + 0x1c);
      }
      bVar9 = *(byte *)(lVar8 + 0x19);
      if (bVar11) {
        if (*(char *)(param_2 + 3) < '\0') {
          bVar9 = bVar9 | 0x80;
        }
        bVar3 = bVar9;
      }
      else {
        bVar3 = bVar9 | 0x80;
        if (-1 < *(char *)(param_2 + 3)) {
          bVar3 = bVar9;
        }
      }
      goto LAB_1400044d6;
    }
  }
  if (cVar4 != '(') {
    *(undefined4 *)(param_2 + 0x10) = 0;
  }
  else {
    *(undefined4 *)(param_2 + 0x3c) = 0;
  }
  if (cVar4 != '(') {
    bVar3 = 1;
    if (*(char *)(param_2 + 3) < '\0') {
      bVar3 = 0x81;
    }
  }
  else {
    bVar3 = (*(char *)(param_2 + 3) >> 7 & 0x80U) + 1;
  }
LAB_1400044d6:
  *(byte *)(param_2 + 3) = bVar3;
  return;
}



===== WPP_SF_ @ 1400044f4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_(undefined8 param_1,undefined2 param_2,undefined8 param_3)

{
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,0);
  return;
}



===== WPP_SF_D @ 140004520 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_D(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,0);
  return;
}



===== WPP_SF_DDD @ 140004564 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DDD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_95fe66d195233e1c089bc08587e1594c_Traceguids,10,local_res20,4,&param_5
             ,4,&param_6,4,0);
  return;
}



===== WPP_SF_q @ 1400045c8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_q(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,0xb,&local_res20,8,0);
  return;
}



===== WppClassicProviderCallback @ 140004610 =====

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



===== wil_details_FeatureReporting_RecordUsageInCache @ 140004644 =====

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
LAB_140004859:
    uVar6 = *param_2;
    do {
      uVar4 = uVar6;
      param_1[1] = 0;
      uVar6 = uVar4 | 1;
      if ((uVar4 >> 0xe & 1) != (uint)(param_3 == 4)) {
        uVar3 = uVar4 >> 5 & 0x1ff;
        if (uVar3 != 0) {
          param_1[1] = uVar3;
          param_1[2] = ~-(uint)(param_3 != 0) & 4;
          uVar6 = uVar4 & 0xffffc01f | 1;
        }
        uVar3 = 0;
        if (param_3 == 4) {
          uVar3 = 0x4000;
        }
        uVar6 = uVar3 | uVar6 & 0xffffbfff;
      }
      uVar5 = uVar6 >> 5 & 0x1ff;
      uVar3 = uVar5 + param_5;
      if ((0x1ff < uVar3) || (uVar3 < uVar5)) {
        param_1[2] = param_3;
        param_1[1] = uVar5;
        uVar3 = param_5;
      }
      LOCK();
      uVar5 = *param_2;
      if (uVar4 == uVar5) {
        *param_2 = (uVar3 << 5 ^ uVar6) & 0x3fe0 ^ uVar6;
        uVar6 = uVar4;
      }
      else {
        uVar6 = uVar5;
      }
      UNLOCK();
    } while (uVar4 != uVar5);
    *param_1 = ~uVar4 & 1;
  }
  else {
    if (param_3 != 1) {
      if ((param_3 == 2) || (param_3 == 3)) {
LAB_140004727:
        uVar6 = 0;
        if (param_3 == 2) {
          uVar6 = 2;
        }
        else if (param_3 == 3) {
          uVar6 = 8;
        }
        else if (param_3 == 6) {
          uVar6 = 4;
        }
        else if (param_3 == 7) {
          uVar6 = 0x10;
        }
        uVar3 = 1;
        uVar4 = *param_2;
        do {
          uVar2 = uVar4;
          uVar4 = uVar6 | uVar2;
          param_1[4] = (uint)(uVar4 == uVar2);
          uVar5 = uVar4 | 1;
          if (uVar4 == uVar2) {
            uVar5 = uVar4;
          }
          LOCK();
          uVar1 = *param_2;
          if (uVar2 == uVar1) {
            *param_2 = uVar5;
            uVar4 = uVar2;
          }
          else {
            uVar4 = uVar1;
          }
          UNLOCK();
        } while (uVar2 != uVar1);
        if (((uVar5 & 1) == 0) || ((uVar2 & 1) != 0)) {
          uVar3 = 0;
        }
        *param_1 = uVar3;
        return param_1;
      }
      if (param_3 == 4) goto LAB_140004859;
      if (param_3 != 5) {
        if ((param_3 != 6) && (param_3 != 7)) {
          uVar6 = param_3 - 0x140;
          if ((int)uVar6 < 0x40) {
            uVar4 = param_2[1];
            do {
              if (((uVar4 & 0x10) == 0) || ((uVar4 >> 5 & 0x3f) != uVar6)) {
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
                param_2[1] = (uVar6 * 0x20 ^ uVar4) & 0x7e0 ^ uVar4 | 0x10;
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
        goto LAB_140004727;
      }
    }
    uVar6 = *param_2;
    do {
      uVar4 = uVar6;
      param_1[1] = 0;
      uVar6 = uVar4 | 1;
      if ((uVar4 >> 0x16 & 1) != (uint)(param_3 == 5)) {
        uVar3 = uVar4 >> 0xf & 0x7f;
        if (uVar3 != 0) {
          param_1[1] = uVar3;
          uVar3 = 5;
          if (param_3 != 1) {
            uVar3 = 1;
          }
          uVar6 = uVar4 & 0xffc07fff | 1;
          param_1[2] = uVar3;
        }
        uVar3 = 0;
        if (param_3 == 5) {
          uVar3 = 0x400000;
        }
        uVar6 = uVar3 | uVar6 & 0xffbfffff;
      }
      uVar5 = uVar6 >> 0xf & 0x7f;
      uVar3 = uVar5 + param_5;
      if ((0x7f < uVar3) || (uVar3 < uVar5)) {
        param_1[2] = param_3;
        param_1[1] = uVar5;
        uVar3 = param_5;
      }
      LOCK();
      uVar5 = *param_2;
      if (uVar4 == uVar5) {
        *param_2 = (uVar3 << 0xf ^ uVar6) & 0x3f8000 ^ uVar6;
        uVar6 = uVar4;
      }
      else {
        uVar6 = uVar5;
      }
      UNLOCK();
    } while (uVar4 != uVar5);
    *param_1 = ~uVar4 & 1;
  }
  param_1[4] = 0;
  return param_1;
}



===== wil_details_FeatureReporting_ReportUsageToService @ 14000494c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void wil_details_FeatureReporting_ReportUsageToService
               (undefined8 param_1,ulonglong param_2,uint param_3,undefined8 param_4)

{
  bool bVar1;
  undefined7 extraout_var;
  uint uVar2;
  ulonglong uVar3;
  uint uVar4;
  byte bVar5;
  uint local_res18 [4];
  
  uVar4 = (uint)param_2 & 1;
  uVar3 = (ulonglong)param_3;
  if (param_3 != 0) {
    if (param_3 == 1) {
      uVar2 = (uVar4 ^ 1) << 2;
      uVar3 = 0;
      goto LAB_140004a1c;
    }
    if (param_3 == 2) {
      uVar2 = (uVar4 ^ 1) * 4 + 1;
      uVar3 = 0;
      goto LAB_140004a1c;
    }
    if (param_3 == 3) {
      uVar2 = (uVar4 ^ 1) * 4 + 2;
      uVar3 = 0;
      goto LAB_140004a1c;
    }
    if (param_3 == 4) {
      uVar2 = (uVar4 ^ 1) * 4 + 3;
      uVar3 = 0;
      goto LAB_140004a1c;
    }
    uVar2 = param_3 - 5;
    uVar3 = (ulonglong)uVar2;
    if (uVar2 == 0) {
      uVar2 = (uVar4 ^ 1) * 2 + 8;
      goto LAB_140004a1c;
    }
    if (uVar2 == 1) {
      uVar2 = (uVar4 ^ 1) * 2 + 9;
      goto LAB_140004a1c;
    }
    bVar5 = (char)param_3 + 0x9c;
    if (bVar5 < 0x32) {
      uVar2 = (-(uint)((param_2 & 1) != 0) & 0xffffffce) + 0x96 + (uint)bVar5;
      goto LAB_140004a1c;
    }
  }
  uVar2 = 0xff;
LAB_140004a1c:
  local_res18[0] = param_3;
  bVar1 = wil_details_FeatureReporting_ReportUsageToServiceDirect(uVar3,param_2,uVar2,(uint)param_4)
  ;
  if (((int)CONCAT71(extraout_var,bVar1) != 0) &&
     (g_wil_details_pfnFeatureLoggingHook != (code *)0x0)) {
    (*g_wil_details_pfnFeatureLoggingHook)
              (0x31ac728,&Feature_Standalone_Future_logged_traits,0,uVar4,local_res18,0,0,param_4);
  }
  return;
}



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 140004a78 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool wil_details_FeatureReporting_ReportUsageToServiceDirect
               (undefined8 param_1,undefined8 param_2,uint param_3,uint param_4)

{
  uint6 uVar1;
  uint *puVar2;
  undefined1 auStackY_88 [32];
  undefined8 local_58;
  uint local_50 [6];
  uint local_38;
  uint uStack_34;
  uint uStack_30;
  uint uStack_2c;
  undefined8 local_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStackY_88;
  puVar2 = wil_details_FeatureReporting_RecordUsageInCache
                     (local_50,&Feature_CrashDumpOneMBTransferSize__private_reporting,param_3,
                      (uint)((ulonglong)param_2 >> 0x20),param_4);
  local_38 = *puVar2;
  uStack_34 = puVar2[1];
  uStack_30 = puVar2[2];
  uStack_2c = puVar2[3];
  local_28 = *(undefined8 *)(puVar2 + 4);
  if (g_wil_details_recordFeatureUsage != (code *)0x0) {
    (*g_wil_details_recordFeatureUsage)
              (0x31ac728,param_3,param_4,&Feature_CrashDumpOneMBTransferSize__private_reporting);
  }
  if ((((uint)param_2 >> 10 & 1) != 0) && (param_3 != 0xfe)) {
    local_58._0_6_ = CONCAT24((short)param_3,0x31ac728);
    uVar1 = (uint6)local_58;
    local_58 = (ulonglong)(uint6)local_58;
    if (((uint)param_2 >> 0xb & 1) != 0) {
      local_58 = CONCAT26(1,uVar1);
    }
    RtlNotifyFeatureUsage(&local_58);
  }
  return (int)local_28 == 0;
}



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 140004b64 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                    (uint *param_1,ulonglong param_2,longlong param_3)

{
  undefined8 *puVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  ulonglong uVar7;
  uint uVar8;
  uint uVar9;
  longlong *plVar10;
  uint uVar11;
  bool bVar12;
  bool bVar13;
  undefined1 auStack_a8 [32];
  undefined8 local_88;
  ulonglong local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined4 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_a8;
  iVar3 = 0;
  local_88 = param_2;
  if (g_wil_details_ensureSubscribedToFeatureConfigurationChanges != (code *)0x0) {
    iVar3 = (*g_wil_details_ensureSubscribedToFeatureConfigurationChanges)();
  }
  local_70 = 0;
  uStack_68 = 0;
  local_78 = 0;
  bVar2 = 0;
  local_60 = 0;
  local_58 = 0;
  local_50 = 0;
  iVar4 = RtlQueryFeatureConfiguration
                    (*(undefined4 *)(param_3 + 0x18),1 < (byte)(*(char *)(param_3 + 0x1c) - 2U),
                     &local_78,&local_58);
  if (iVar4 == 0) {
    bVar2 = 1;
    uVar8 = local_58._4_4_ >> 7 & 1;
    local_70 = CONCAT44(local_70._4_4_,local_58._4_4_ >> 4) & 0xffffffff00000003;
    uVar5 = local_58._4_4_ >> 6 & 1;
    uVar11 = local_58._4_4_ >> 4 & 3;
LAB_140004c17:
    uVar8 = uVar8 << 10;
    if (uVar5 != 0) {
      uVar5 = 0x800;
      goto LAB_140004c45;
    }
  }
  else {
    uVar8 = 0;
    uVar5 = 0;
    uVar11 = (uint)local_70;
    if (iVar4 != 0x117) goto LAB_140004c17;
    bVar2 = 1;
    uVar8 = (local_58._4_4_ >> 7 & 1) << 10;
  }
  uVar5 = 0;
LAB_140004c45:
  uVar6 = -(uint)bVar2 & uVar11 & 3;
  if (uVar6 == 0) {
    uVar9 = -(uint)(*(char *)(param_3 + 0x1f) != '\0') & 0x40;
  }
  else {
    uVar9 = 0;
    if (uVar11 == 2) {
      uVar9 = 0x40;
    }
  }
  uVar11 = uVar9 >> 6 ^ (uVar9 | uVar6 << 7 | uVar8 | uVar5);
  if ((uVar9 != 0) && (plVar10 = *(longlong **)(param_3 + 0x20), plVar10 != (longlong *)0x0)) {
    do {
      puVar1 = (undefined8 *)*plVar10;
      if (puVar1 == (undefined8 *)0x0) break;
      if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
         (*(char *)((longlong)puVar1 + 0x1d) == '\0')) {
        uVar8 = *(uint *)*puVar1;
        local_80 = (ulonglong)uVar8;
        if ((uVar8 & 2) == 0) {
          uVar7 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                            ((uint *)*puVar1,local_80,(longlong)puVar1);
          uVar8 = (uint)uVar7;
        }
        uVar5 = uVar11 & 0xfffffffe;
        uVar11 = (uint)((uVar8 & uVar11 & 1) != 0);
      }
      else {
        if (((uVar11 & 1) == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
          uVar5 = 0;
        }
        else {
          uVar5 = 1;
        }
        uVar11 = uVar11 & 0xfffffffe;
      }
      uVar11 = uVar11 | uVar5;
      plVar10 = plVar10 + 1;
    } while ((uVar11 & 1) != 0);
  }
  bVar12 = *(char *)(param_3 + 0x1c) == '\0';
  uVar7 = param_2 & 0xffffffff;
  while( true ) {
    uVar5 = (uint)uVar7;
    local_88 = CONCAT44(local_88._4_4_,uVar5);
    if ((!bVar12 || iVar3 != 0) && (local_88 = CONCAT44(local_88._4_4_,uVar5), (uVar7 & 2) == 0)) {
      uVar8 = (uVar11 ^ uVar5) & 0x9c1 ^ uVar5;
      uVar5 = uVar8 | 2;
      local_88 = CONCAT44(local_88._4_4_,uVar8) | 2;
    }
    if ((param_2 & 4) == 0) {
      uVar8 = (uVar5 ^ uVar11) & 0x400 ^ uVar5;
      uVar5 = uVar8 | 4;
      local_88 = CONCAT44(local_88._4_4_,uVar8) | 4;
    }
    uVar7 = param_2 & 0xffffffff;
    LOCK();
    uVar8 = *param_1;
    bVar13 = (uint)param_2 == uVar8;
    if (bVar13) {
      *param_1 = uVar5;
    }
    else {
      uVar7 = (ulonglong)uVar8;
    }
    UNLOCK();
    if (bVar13) break;
    param_2 = uVar7;
  }
  if (((param_2 & 4) == 0) &&
     (g_wil_details_subscribeFeatureStateCacheToConfigurationChanges != (code *)0x0)) {
    (*g_wil_details_subscribeFeatureStateCacheToConfigurationChanges)
              (param_1,*(undefined1 *)(param_3 + 0x1c),iVar3);
  }
  if (bVar12 && iVar3 == 0) {
    local_88 = CONCAT44(local_88._4_4_,(uVar11 ^ uVar5) & 0x9c1 ^ uVar5);
  }
  return local_88;
}



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 140004dd0 =====

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
  if ((Feature_CrashDumpOneMBTransferSize__private_featureState & 2) != 0) {
    uVar1 = Feature_CrashDumpOneMBTransferSize__private_featureState;
    while ((uVar1 & 1) == (param_1 & 1)) {
      LOCK();
      bVar3 = uVar1 == Feature_CrashDumpOneMBTransferSize__private_featureState;
      if (bVar3) {
        Feature_CrashDumpOneMBTransferSize__private_featureState = uVar2 | uVar1;
      }
      else {
        uVar1 = Feature_CrashDumpOneMBTransferSize__private_featureState;
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



===== wil_details_IsEnabledFallback @ 140004e24 =====

uint wil_details_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  undefined4 *puVar1;
  ulonglong local_res18;
  
  local_res18 = (ulonglong)param_1 & 0xffffffff;
  if (((ulonglong)param_1 & 2) == 0) {
    puVar1 = &Feature_CrashDumpOneMBTransferSize__private_featureState;
    local_res18 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                            (&Feature_CrashDumpOneMBTransferSize__private_featureState,
                             (ulonglong)param_1,0x14000a0c8);
    param_1 = puVar1;
    puVar1 = (undefined4 *)(local_res18 & 0xffffffff);
  }
  else {
    puVar1 = param_1;
  }
  if (param_2 != 0) {
    wil_details_FeatureReporting_ReportUsageToService(param_1,local_res18,param_2,1);
    if (param_2 - 3 < 2) {
      wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath((uint)local_res18,param_2);
    }
  }
  return (uint)puVar1 & 1;
}



===== wil_details_RecordCachedUsage @ 140004eb8 =====

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



===== wil_details_RecordFeatureUsageReporting @ 140005010 =====

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



===== StorChannelCompareChannelByProcessorIndex @ 1400050a0 =====

ulonglong StorChannelCompareChannelByProcessorIndex(longlong param_1,longlong param_2)

{
  if (*(uint *)(param_1 + 8) < *(uint *)(param_2 + 8)) {
    return 0xffffffff;
  }
  return (ulonglong)(*(uint *)(param_1 + 8) != *(uint *)(param_2 + 8));
}



===== StorChannelCompareProcessorByDistanceDescending @ 1400050d0 =====

ulonglong StorChannelCompareProcessorByDistanceDescending(ushort *param_1,ushort *param_2)

{
  if (param_1[2] <= param_2[2]) {
    if (param_1[2] < param_2[2]) {
      return 1;
    }
    if (*param_2 <= *param_1) {
      return (ulonglong)(*param_2 < *param_1);
    }
  }
  return 0xffffffff;
}



===== StorChannelCopyPacketDataToSrb @ 140005104 =====

void StorChannelCopyPacketDataToSrb(undefined8 param_1,longlong param_2,longlong param_3)

{
  uint *puVar1;
  byte *pbVar2;
  char cVar3;
  undefined1 uVar4;
  byte bVar5;
  int iVar6;
  code *pcVar7;
  bool bVar8;
  byte bVar9;
  longlong lVar10;
  uint uVar11;
  ulonglong uVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  uint uVar15;
  byte bVar16;
  byte bVar17;
  byte *_Dst;
  byte bVar18;
  
  cVar3 = *(char *)(param_3 + 2);
  puVar1 = (uint *)(param_3 + 0x10);
  if (cVar3 == '(') {
    uVar15 = *(uint *)(param_3 + 0x3c);
  }
  else {
    uVar15 = *puVar1;
  }
  uVar11 = *(uint *)(param_2 + 0x18);
  if (uVar15 < uVar11) {
LAB_1400055ba:
    pcVar7 = (code *)swi(0x29);
    (*pcVar7)(0x3a);
    pcVar7 = (code *)swi(3);
    (*pcVar7)();
    return;
  }
  if (cVar3 != '(') {
    *puVar1 = uVar11;
  }
  else {
    *(uint *)(param_3 + 0x3c) = uVar11;
  }
  bVar9 = *(byte *)(param_2 + 0xe);
  if (cVar3 != '(') {
    if (*(char *)(param_3 + 3) < '\0') {
      bVar9 = bVar9 | 0x80;
    }
  }
  else {
    bVar5 = bVar9 | 0x80;
    if (-1 < *(char *)(param_3 + 3)) {
      bVar5 = bVar9;
    }
    bVar9 = bVar5;
  }
  *(byte *)(param_3 + 3) = bVar9;
  uVar4 = *(undefined1 *)(param_2 + 0xf);
  if (cVar3 == '(') {
    bVar8 = false;
    if ((*(int *)(param_3 + 0x14) == 0) && (uVar14 = 0, *(int *)(param_3 + 0x38) != 0)) {
      do {
        uVar15 = *(uint *)(param_3 + 0x78 + uVar14 * 4);
        if ((0x7f < uVar15) && (uVar11 = *puVar1, uVar15 < uVar11)) {
          uVar12 = (ulonglong)uVar15;
          iVar6 = *(int *)((ulonglong)uVar15 + param_3);
          if (iVar6 == 0x40) {
LAB_1400051cb:
            if (uVar12 + 0x28 <= (ulonglong)uVar11) {
              *(undefined1 *)(uVar12 + 8 + param_3) = uVar4;
              break;
            }
          }
          else if (iVar6 == 0x41) {
            if (uVar12 + 0x38 <= (ulonglong)uVar11) {
              bVar8 = true;
              *(undefined1 *)(uVar12 + 8 + param_3) = uVar4;
            }
          }
          else if (iVar6 == 0x42) goto LAB_1400051cb;
          if (bVar8) break;
        }
        uVar15 = (int)uVar14 + 1;
        uVar14 = (ulonglong)uVar15;
      } while (uVar15 < *(uint *)(param_3 + 0x38));
    }
  }
  else {
    *(undefined1 *)(param_3 + 4) = uVar4;
  }
  if (*(char *)(param_2 + 0xf) != '\x02') {
    return;
  }
  lVar10 = VmbChannelGetPointer(param_1);
  if (0x14 < *(byte *)(param_2 + 0x15)) goto LAB_1400055ba;
  _Dst = (byte *)0x0;
  if (*(char *)(param_3 + 2) == '(') {
    bVar8 = false;
    if (*(int *)(param_3 + 0x14) == 0) {
      uVar14 = 0;
      if (*(uint *)(param_3 + 0x38) != 0) {
        do {
          uVar15 = *(uint *)(param_3 + 0x78 + uVar14 * 4);
          if ((0x7f < uVar15) && (uVar12 = (ulonglong)*puVar1, uVar15 < *puVar1)) {
            uVar13 = (ulonglong)uVar15;
            iVar6 = *(int *)((ulonglong)uVar15 + param_3);
            if (iVar6 == 0x40) {
              if (uVar13 + 0x28 <= uVar12) {
                _Dst = *(byte **)(uVar13 + 0x10 + param_3);
                break;
              }
            }
            else if (iVar6 == 0x41) {
              if (uVar13 + 0x38 <= uVar12) {
                _Dst = *(byte **)(uVar13 + 0x10 + param_3);
                bVar8 = true;
              }
            }
            else if ((iVar6 == 0x42) && (uVar13 + 0x28 <= uVar12)) {
              _Dst = *(byte **)(uVar13 + 0x18 + param_3);
              break;
            }
            if (bVar8) break;
          }
          uVar15 = (int)uVar14 + 1;
          uVar14 = (ulonglong)uVar15;
        } while (uVar15 < *(uint *)(param_3 + 0x38));
      }
    }
    bVar8 = false;
    bVar9 = 0;
    if (*(int *)(param_3 + 0x14) == 0) {
      uVar14 = 0;
      bVar5 = 0;
      if (*(uint *)(param_3 + 0x38) != 0) {
        do {
          bVar9 = bVar5;
          uVar15 = *(uint *)(param_3 + 0x78 + uVar14 * 4);
          if ((0x7f < uVar15) && (uVar11 = *puVar1, uVar15 < uVar11)) {
            uVar12 = (ulonglong)uVar15;
            iVar6 = *(int *)((ulonglong)uVar15 + param_3);
            if (iVar6 == 0x40) {
LAB_1400052fa:
              if (uVar12 + 0x28 <= (ulonglong)uVar11) {
                bVar9 = *(byte *)(uVar12 + 9 + param_3);
                break;
              }
            }
            else if (iVar6 == 0x41) {
              if (uVar12 + 0x38 <= (ulonglong)uVar11) {
                bVar9 = *(byte *)(uVar12 + 9 + param_3);
                bVar8 = true;
              }
            }
            else if (iVar6 == 0x42) goto LAB_1400052fa;
            if (bVar8) break;
          }
          uVar15 = (int)uVar14 + 1;
          uVar14 = (ulonglong)uVar15;
          bVar5 = bVar9;
        } while (uVar15 < *(uint *)(param_3 + 0x38));
      }
    }
  }
  else {
    _Dst = *(byte **)(param_3 + 0x20);
    bVar9 = *(byte *)(param_3 + 0xb);
  }
  if (_Dst == (byte *)0x0) {
    return;
  }
  if (bVar9 == 0) {
    return;
  }
  if (((byte)((*(byte *)(param_2 + 0x1c) & 0x7f) + 0x8e) < 2) &&
     ((*(char *)(lVar10 + 0x75) == '\0' || ((bVar9 < *(byte *)(param_2 + 0x15) && (0x11 < bVar9)))))
     ) {
    bVar8 = true;
  }
  else {
    bVar8 = false;
  }
  bVar5 = *(byte *)(param_2 + 0x15);
  uVar14 = (ulonglong)bVar5;
  if (!bVar8) {
    if (bVar9 < bVar5) {
      return;
    }
    memcpy(_Dst,(void *)(param_2 + 0x1c),uVar14);
    uVar4 = *(undefined1 *)(param_2 + 0x15);
    if (*(char *)(param_3 + 2) != '(') {
      *(undefined1 *)(param_3 + 0xb) = uVar4;
      return;
    }
    bVar8 = false;
    if (*(int *)(param_3 + 0x14) != 0) {
      return;
    }
    uVar14 = 0;
    if (*(int *)(param_3 + 0x38) == 0) {
      return;
    }
    do {
      uVar15 = *(uint *)(param_3 + 0x78 + uVar14 * 4);
      if ((0x7f < uVar15) && (uVar11 = *(uint *)(param_3 + 0x10), uVar15 < uVar11)) {
        uVar12 = (ulonglong)uVar15;
        iVar6 = *(int *)((ulonglong)uVar15 + param_3);
        if (iVar6 == 0x40) {
LAB_140005574:
          if (uVar12 + 0x28 <= (ulonglong)uVar11) {
            *(undefined1 *)(uVar12 + 9 + param_3) = uVar4;
            return;
          }
        }
        else if (iVar6 == 0x41) {
          if (uVar12 + 0x38 <= (ulonglong)uVar11) {
            bVar8 = true;
            *(undefined1 *)(uVar12 + 9 + param_3) = uVar4;
          }
        }
        else if (iVar6 == 0x42) goto LAB_140005574;
        if (bVar8) {
          return;
        }
      }
      uVar15 = (int)uVar14 + 1;
      uVar14 = (ulonglong)uVar15;
      if (*(uint *)(param_3 + 0x38) <= uVar15) {
        return;
      }
    } while( true );
  }
  pbVar2 = (byte *)(param_2 + 0x1c);
  bVar17 = 0;
  bVar18 = 0;
  bVar16 = 0;
  if ((((pbVar2 == (byte *)0x0) || (bVar5 == 0)) || (bVar9 < 0x12)) ||
     (1 < (byte)((*pbVar2 & 0x7f) + 0x8e))) goto LAB_14000547e;
  memset(_Dst,0,(ulonglong)bVar9);
  if ((byte)((*pbVar2 & 0x7f) + 0x8e) < 2) {
    bVar8 = false;
    if ((byte *)(param_2 + 0x24U) <= pbVar2 + uVar14) {
      bVar18 = *(byte *)(param_2 + 0x1d);
      bVar17 = *(byte *)(param_2 + 0x1e);
      bVar16 = *(byte *)(param_2 + 0x1f);
LAB_14000543d:
      bVar8 = true;
    }
  }
  else {
    if (1 < (byte)((*pbVar2 & 0x7f) + 0x90)) goto LAB_14000547e;
    bVar8 = false;
    if ((byte *)(param_2 + 0x24U) <= pbVar2 + uVar14) {
      bVar18 = *(byte *)(param_2 + 0x1e);
      uVar11 = *(byte *)(param_2 + 0x23) + 8;
      uVar15 = (uint)bVar5;
      if (uVar11 <= bVar5) {
        uVar15 = uVar11;
      }
      if ((byte *)(param_2 + 0x29U) <= pbVar2 + uVar15) {
        bVar17 = *(byte *)(param_2 + 0x28);
      }
      if (pbVar2 + uVar15 < (byte *)(param_2 + 0x2aU)) {
        bVar16 = 0;
      }
      else {
        bVar16 = *(byte *)(param_2 + 0x29U);
      }
      goto LAB_14000543d;
    }
  }
  if (bVar8) {
    if (((*pbVar2 & 0x7f) + 0x90 & 0xfd) == 0) {
      bVar9 = *_Dst & 0xf0 | 0x70;
    }
    else {
      bVar9 = *_Dst & 0xf1 | 0x71;
    }
    *_Dst = bVar9;
    _Dst[7] = 10;
    _Dst[0xc] = bVar17;
    _Dst[0xd] = bVar16;
    _Dst[2] = (bVar18 ^ _Dst[2]) & 0xf ^ _Dst[2];
  }
LAB_14000547e:
  if (*(char *)(param_3 + 2) == '(') {
    bVar8 = false;
    if ((*(int *)(param_3 + 0x14) == 0) && (uVar14 = 0, *(int *)(param_3 + 0x38) != 0)) {
      do {
        uVar15 = *(uint *)(param_3 + 0x78 + uVar14 * 4);
        if ((0x7f < uVar15) && (uVar11 = *(uint *)(param_3 + 0x10), uVar15 < uVar11)) {
          uVar12 = (ulonglong)uVar15;
          iVar6 = *(int *)((ulonglong)uVar15 + param_3);
          if (iVar6 == 0x40) {
LAB_1400054c4:
            if (uVar12 + 0x28 <= (ulonglong)uVar11) {
              *(undefined1 *)(uVar12 + 9 + param_3) = 0x12;
              return;
            }
          }
          else if (iVar6 == 0x41) {
            if (uVar12 + 0x38 <= (ulonglong)uVar11) {
              bVar8 = true;
              *(undefined1 *)(uVar12 + 9 + param_3) = 0x12;
            }
          }
          else if (iVar6 == 0x42) goto LAB_1400054c4;
          if (bVar8) {
            return;
          }
        }
        uVar15 = (int)uVar14 + 1;
        uVar14 = (ulonglong)uVar15;
      } while (uVar15 < *(uint *)(param_3 + 0x38));
    }
  }
  else {
    *(undefined1 *)(param_3 + 0xb) = 0x12;
  }
  return;
}



===== StorChannelCopySrbToPacket @ 1400055c8 =====

void StorChannelCopySrbToPacket(longlong param_1,undefined4 *param_2)

{
  int iVar1;
  uint uVar2;
  bool bVar3;
  undefined4 uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  short *psVar7;
  byte bVar8;
  undefined4 uVar9;
  undefined1 uVar10;
  size_t _Size;
  longlong lVar11;
  void *_Src;
  uint uVar12;
  ulonglong uVar13;
  int *piVar14;
  byte bVar15;
  
  uVar9 = 0;
  piVar14 = (int *)(param_1 + 0x14);
  if (*(char *)(param_1 + 2) == '(') {
    _Src = (void *)0x0;
    bVar3 = false;
    if (*piVar14 == 0) {
      uVar13 = 0;
      if (*(uint *)(param_1 + 0x38) != 0) {
        do {
          uVar12 = *(uint *)(param_1 + 0x78 + uVar13 * 4);
          if ((0x7f < uVar12) &&
             (uVar6 = (ulonglong)*(uint *)(param_1 + 0x10), uVar12 < *(uint *)(param_1 + 0x10))) {
            uVar5 = (ulonglong)uVar12;
            iVar1 = *(int *)((ulonglong)uVar12 + param_1);
            if (iVar1 == 0x40) {
              if (uVar5 + 0x28 <= uVar6) {
                if (*(char *)(uVar5 + 10 + param_1) != '\0') {
                  lVar11 = param_1 + 0x18;
LAB_14000569e:
                  _Src = (void *)(lVar11 + uVar5);
                }
                break;
              }
            }
            else if (iVar1 == 0x41) {
              if (uVar5 + 0x38 <= uVar6) {
                bVar3 = true;
                if (*(char *)(uVar5 + 10 + param_1) == '\0') break;
                _Src = (void *)(param_1 + 0x18 + uVar5);
              }
            }
            else if ((iVar1 == 0x42) && (uVar5 + 0x28 <= uVar6)) {
              if (*(int *)(uVar5 + 0xc + param_1) != 0) {
                lVar11 = param_1 + 0x20;
                goto LAB_14000569e;
              }
              break;
            }
            if (bVar3) break;
          }
          uVar12 = (int)uVar13 + 1;
          uVar13 = (ulonglong)uVar12;
        } while (uVar12 < *(uint *)(param_1 + 0x38));
      }
    }
    bVar3 = false;
    bVar8 = 0;
    if (*piVar14 == 0) {
      uVar13 = 0;
      if (*(uint *)(param_1 + 0x38) != 0) {
        do {
          uVar12 = *(uint *)(param_1 + 0x78 + uVar13 * 4);
          if ((0x7f < uVar12) &&
             (uVar6 = (ulonglong)*(uint *)(param_1 + 0x10), uVar12 < *(uint *)(param_1 + 0x10))) {
            uVar5 = (ulonglong)uVar12;
            iVar1 = *(int *)((ulonglong)uVar12 + param_1);
            if (iVar1 == 0x40) {
              if (uVar5 + 0x28 <= uVar6) {
                bVar8 = *(byte *)(uVar5 + 10 + param_1);
                break;
              }
            }
            else if (iVar1 == 0x41) {
              if (uVar5 + 0x38 <= uVar6) {
                bVar8 = *(byte *)(uVar5 + 10 + param_1);
                bVar3 = true;
              }
            }
            else if ((iVar1 == 0x42) && (uVar5 + 0x28 <= uVar6)) break;
            if (bVar3) break;
          }
          uVar12 = (int)uVar13 + 1;
          uVar13 = (ulonglong)uVar12;
        } while (uVar12 < *(uint *)(param_1 + 0x38));
      }
    }
    bVar3 = false;
    bVar15 = 0;
    if (*piVar14 == 0) {
      uVar13 = 0;
      if (*(uint *)(param_1 + 0x38) != 0) {
        do {
          uVar12 = *(uint *)(param_1 + 0x78 + uVar13 * 4);
          if ((0x7f < uVar12) && (uVar2 = *(uint *)(param_1 + 0x10), uVar12 < uVar2)) {
            uVar6 = (ulonglong)uVar12;
            iVar1 = *(int *)((ulonglong)uVar12 + param_1);
            if (iVar1 == 0x40) {
LAB_140005761:
              if (uVar6 + 0x28 <= (ulonglong)uVar2) {
                bVar15 = *(byte *)(uVar6 + 9 + param_1);
                break;
              }
            }
            else if (iVar1 == 0x41) {
              if (uVar6 + 0x38 <= (ulonglong)uVar2) {
                bVar15 = *(byte *)(uVar6 + 9 + param_1);
                bVar3 = true;
              }
            }
            else if (iVar1 == 0x42) goto LAB_140005761;
            if (bVar3) break;
          }
          uVar12 = (int)uVar13 + 1;
          uVar13 = (ulonglong)uVar12;
        } while (uVar12 < *(uint *)(param_1 + 0x38));
      }
    }
  }
  else {
    bVar8 = *(byte *)(param_1 + 10);
    _Src = (void *)(param_1 + 0x48);
    bVar15 = *(byte *)(param_1 + 0xb);
  }
  if (_Src != (void *)0x0) {
    _Size = 0x10;
    if (bVar8 < 0x10) {
      _Size = (size_t)bVar8;
    }
    memcpy(param_2 + 7,_Src,_Size);
  }
  *param_2 = 3;
  uVar10 = 0;
  *(undefined2 *)(param_2 + 3) = 0x34;
  if (*(char *)(param_1 + 2) == '(') {
    if (((*(uint *)(param_1 + 0x34) != 0) &&
        (psVar7 = (short *)((ulonglong)*(uint *)(param_1 + 0x34) + param_1), psVar7 != (short *)0x0)
        ) && (*psVar7 == 1)) {
      uVar10 = (undefined1)psVar7[4];
    }
  }
  else {
    uVar10 = *(undefined1 *)(param_1 + 5);
  }
  *(undefined1 *)((longlong)param_2 + 0x11) = uVar10;
  uVar10 = 0;
  if (*(char *)(param_1 + 2) == '(') {
    if (((*(uint *)(param_1 + 0x34) != 0) &&
        (psVar7 = (short *)((ulonglong)*(uint *)(param_1 + 0x34) + param_1), psVar7 != (short *)0x0)
        ) && (*psVar7 == 1)) {
      uVar10 = *(undefined1 *)((longlong)psVar7 + 9);
    }
  }
  else {
    uVar10 = *(undefined1 *)(param_1 + 6);
  }
  *(undefined1 *)((longlong)param_2 + 0x12) = uVar10;
  uVar10 = 0;
  if (*(char *)(param_1 + 2) == '(') {
    if (((*(uint *)(param_1 + 0x34) != 0) &&
        (psVar7 = (short *)((ulonglong)*(uint *)(param_1 + 0x34) + param_1), psVar7 != (short *)0x0)
        ) && (*psVar7 == 1)) {
      uVar10 = (undefined1)psVar7[5];
    }
  }
  else {
    uVar10 = *(undefined1 *)(param_1 + 7);
  }
  *(undefined1 *)((longlong)param_2 + 0x13) = uVar10;
  *(byte *)(param_2 + 5) = bVar8;
  bVar8 = 0x14;
  if (bVar15 < 0x14) {
    bVar8 = bVar15;
  }
  *(byte *)((longlong)param_2 + 0x15) = bVar8;
  if (*(char *)(param_1 + 2) == '(') {
    uVar4 = *(undefined4 *)(param_1 + 0x3c);
  }
  else {
    uVar4 = *(undefined4 *)(param_1 + 0x10);
  }
  param_2[1] = param_2[1] | 1;
  param_2[6] = uVar4;
  if (*(char *)(param_1 + 2) == '(') {
    uVar12 = *(uint *)(param_1 + 0x18);
  }
  else {
    uVar12 = *(uint *)(param_1 + 0xc);
  }
  if ((uVar12 & 0x40) == 0) {
    *(byte *)((longlong)param_2 + 0x16) = ~((byte)uVar12 >> 6) & 2;
  }
  else {
    *(undefined1 *)((longlong)param_2 + 0x16) = 1;
  }
  if (*(char *)(param_1 + 2) == '(') {
    uVar10 = (undefined1)*(undefined4 *)(param_1 + 0x20);
  }
  else {
    uVar10 = *(undefined1 *)(param_1 + 8);
  }
  *(undefined1 *)((longlong)param_2 + 0x32) = uVar10;
  if (*(char *)(param_1 + 2) == '(') {
    uVar10 = *(undefined1 *)(param_1 + 0x26);
  }
  else {
    uVar10 = *(undefined1 *)(param_1 + 9);
  }
  *(undefined1 *)((longlong)param_2 + 0x33) = uVar10;
  param_2[0xd] = uVar12;
  if (*(char *)(param_1 + 2) == '(') {
    piVar14 = (int *)(param_1 + 0x28);
  }
  param_2[0xe] = *piVar14;
  if (*(char *)(param_1 + 2) == '\0') {
    uVar9 = *(undefined4 *)(param_1 + 0x40);
  }
  param_2[0xf] = uVar9;
  return;
}



===== StorChannelEnableSubChannels @ 140005908 =====

ulonglong StorChannelEnableSubChannels(undefined8 *param_1)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  longlong lVar5;
  int iVar6;
  ushort uVar7;
  ulonglong local_res8;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  code *local_78;
  undefined8 uStack_70;
  int local_68 [3];
  undefined2 local_5c;
  
  local_res8 = local_res8 & 0xffffffff00000000;
  memset(local_68,0,0x40);
  local_68[1] = 1;
  local_5c = *(undefined2 *)(param_1 + 0x10);
  local_68[0] = 0xd;
  uVar2 = StorChannelSendSyntheticVstorPacket(*param_1,local_68);
  uVar3 = uVar2 & 0xffffffff;
  if (-1 < (int)uVar2) {
    uVar3 = 0;
    uVar2 = param_1[0x11];
    if (*(short *)(param_1 + 0x10) != 0) {
      do {
        if (uVar2 == 0) {
          iVar6 = -1;
        }
        else {
          uVar4 = 0;
          if (uVar2 != 0) {
            for (; (uVar2 >> uVar4 & 1) == 0; uVar4 = uVar4 + 1) {
            }
          }
          iVar6 = (int)uVar4;
          uVar2 = uVar2 & ~(1L << (uVar4 & 0x3f));
        }
        lVar5 = uVar3 + 9;
        local_98 = 0;
        uStack_90 = 0;
        local_88 = 0;
        uStack_80 = 0;
        local_res8 = param_1[lVar5 * 2];
        local_78 = (code *)0x0;
        uStack_70 = 0;
        if (local_res8 == 0) {
          uVar1 = VmbChannelAllocate(param_1[0xf],0,&local_res8);
          uVar4 = (ulonglong)uVar1;
          if (-1 < (int)uVar1) {
            uVar1 = VmbChannelAllocateForStorage(local_res8);
            uVar4 = (ulonglong)uVar1;
            if (-1 < (int)uVar1) {
              VmbChannelInitSetMaximumPacketSize(local_res8,0x40);
              VmbClientChannelInitSetRingBufferPageCount(local_res8,10,10);
              local_78 = StorChannelKmclEvtSubChannelStarted;
              uStack_80 = 0;
              uStack_70 = 0;
              uStack_90 = 0;
              local_88 = 0;
              local_98 = 0x3000000001;
              VmbChannelInitSetStateChangeCallbacks(local_res8,&local_98);
              VmbChannelInitSetPrimaryChannel(local_res8,*param_1,(int)uVar3 + 1);
              VmbChannelSetPointer(local_res8,param_1);
              VmbChannelSetAllowableDpcCpuUsage(local_res8);
              if (iVar6 != -1) {
                VmbClientChannelInitSetTargetProcessorIndex(local_res8);
              }
              param_1[lVar5 * 2] = local_res8;
              goto LAB_140005ad1;
            }
          }
        }
        else {
LAB_140005ad1:
          uVar1 = VmbChannelEnable();
          uVar4 = (ulonglong)uVar1;
          if ((int)uVar1 < 0) {
            param_1[lVar5 * 2] = 0;
          }
          else {
            uVar4 = 0;
            local_res8 = 0;
          }
        }
        if (local_res8 != 0) {
          VmbChannelCleanup();
        }
        if ((int)uVar4 < 0) {
          return uVar4;
        }
        uVar7 = (short)uVar3 + 1;
        uVar3 = (ulonglong)uVar7;
      } while (uVar7 < *(ushort *)(param_1 + 0x10));
    }
    uVar3 = 0;
  }
  return uVar3;
}



===== StorChannelEstablishCommunications @ 140005b4c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x000140005e63) */

ulonglong StorChannelEstablishCommunications(undefined8 param_1,undefined8 param_2)

{
  short sVar1;
  ulonglong *puVar2;
  code *pcVar3;
  ushort uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined8 *puVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  undefined2 uVar11;
  uint uVar12;
  short *psVar13;
  undefined1 auStack_b8 [32];
  ulonglong local_98;
  int local_88 [3];
  uint local_7c;
  ushort local_78;
  byte local_74;
  int local_70;
  ulonglong local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_b8;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),param_2,
             &WPP_fae18269a3c73a60ae52ad52de4ed304_Traceguids,param_1);
  }
  puVar7 = (undefined8 *)VmbChannelGetPointer(param_1);
  memset(local_88,0,0x40);
  local_88[1] = 1;
  local_88[0] = 7;
  uVar8 = StorChannelSendSyntheticVstorPacket(param_1,local_88);
  iVar5 = (int)uVar8;
  uVar8 = uVar8 & 0xffffffff;
  if (iVar5 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return uVar8;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      uVar11 = 0xc;
LAB_140005c2d:
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar11,
               &WPP_fae18269a3c73a60ae52ad52de4ed304_Traceguids,iVar5);
    }
  }
  else {
    uVar10 = 0;
    psVar13 = &g_StorChannelSupportedVersions;
    do {
      sVar1 = *psVar13;
      memset(local_88,0,0x40);
      local_88[1] = 1;
      local_88[0] = 9;
      local_7c = CONCAT22(local_7c._2_2_,sVar1);
      uVar9 = StorChannelSendSyntheticVstorPacket(param_1,local_88);
      uVar8 = uVar9 & 0xffffffff;
      if (-1 < (int)uVar9) {
        if ((short)local_7c != sVar1) {
LAB_140006003:
          pcVar3 = (code *)swi(0x29);
          (*pcVar3)(0x3a);
          pcVar3 = (code *)swi(3);
          uVar8 = (*pcVar3)();
          return uVar8;
        }
        *(short *)(puVar7 + 0xc) = (short)local_7c;
        *(undefined2 *)(puVar7 + 0xe) = (&DAT_1400095f2)[uVar10 * 4];
        *(undefined2 *)((longlong)puVar7 + 0x72) = (&DAT_1400095f4)[uVar10 * 4];
        *(undefined1 *)((longlong)puVar7 + 0x74) = (&DAT_1400095f6)[uVar10 * 8];
        memset(local_88,0,0x40);
        local_88[1] = 1;
        local_88[0] = 10;
        if (0x5ff < *(ushort *)(puVar7 + 0xc)) {
          local_7c = local_7c | 1;
        }
        uVar10 = StorChannelSendSyntheticVstorPacket(param_1,local_88);
        uVar8 = uVar10 & 0xffffffff;
        if ((int)uVar10 < 0) {
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return uVar8;
          }
          if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar11 = 0xf;
            goto LAB_140005d12;
          }
          goto LAB_140005fa1;
        }
        if (0x7fffff < local_70 - 1U) goto LAB_140006003;
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
                   &WPP_fae18269a3c73a60ae52ad52de4ed304_Traceguids,local_70);
        }
        *(int *)((longlong)puVar7 + 0x54) = local_70;
        if ((*(ushort *)(puVar7 + 0xc) < 0x501) || ((local_74 & 1) == 0)) {
          uVar4 = 0;
        }
        else {
          *(uint *)(puVar7 + 10) = *(uint *)(puVar7 + 10) | 1;
          uVar4 = 0x3f;
          if (local_78 < 0x3f) {
            uVar4 = local_78;
          }
        }
        *(ushort *)((longlong)puVar7 + 0x4c) = uVar4;
        local_48 = 0;
        uStack_40 = 0;
        uVar6 = HviIsHypervisorMicrosoftCompatible();
        if ((char)uVar6 != '\0') {
          puVar2 = (ulonglong *)cpuid(0x40000003);
          local_48 = *puVar2;
        }
        if ((local_48 & 0x40000000000000) == 0) {
LAB_140005edd:
          uVar4 = *(ushort *)(puVar7 + 0x10);
          if (*(ushort *)((longlong)puVar7 + 0x4c) <= *(ushort *)(puVar7 + 0x10)) {
            uVar4 = *(ushort *)((longlong)puVar7 + 0x4c);
          }
          *(ushort *)(puVar7 + 0x10) = uVar4;
          if ((*(char *)((longlong)puVar7 + 0x84) != '\0') &&
             (local_98 = (ulonglong)*(ushort *)((longlong)puVar7 + 0x82),
             uVar4 != *(ushort *)((longlong)puVar7 + 0x82))) {
                    /* WARNING: Subroutine does not return */
            KeBugCheckEx(0xbd,param_1,puVar7,uVar4);
          }
          if (uVar4 != 0) {
            uVar10 = StorChannelEnableSubChannels(puVar7);
            uVar8 = uVar10 & 0xffffffff;
            if ((int)uVar10 < 0) goto LAB_140005fa1;
          }
          memset(local_88,0,0x40);
          local_88[1] = 1;
          local_88[0] = 8;
          uVar10 = StorChannelSendSyntheticVstorPacket(param_1,local_88);
          uVar8 = uVar10 & 0xffffffff;
          if (-1 < (int)uVar10) {
            uVar8 = 0;
            goto LAB_140005fa1;
          }
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return uVar8;
          }
          if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_140005fa1;
          uVar11 = 0x12;
        }
        else {
          uVar12 = VmbChannelAllocateBounceBuffer(param_1);
          uVar8 = (ulonglong)uVar12;
          if (-1 < (int)uVar12) goto LAB_140005edd;
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return uVar8;
          }
          if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_140005fa1;
          uVar11 = 0x11;
        }
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar11,
                 &WPP_fae18269a3c73a60ae52ad52de4ed304_Traceguids,(int)uVar8);
        goto LAB_140005fa1;
      }
      if ((int)uVar9 != -0x3fffffa7) {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return uVar8;
        }
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_140005fa1;
        uVar11 = 0xd;
LAB_140005d12:
        iVar5 = (int)uVar8;
        goto LAB_140005c2d;
      }
      uVar12 = (int)uVar10 + 1;
      uVar10 = (ulonglong)uVar12;
      psVar13 = psVar13 + 4;
    } while (uVar12 < 6);
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return uVar8;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
              &WPP_fae18269a3c73a60ae52ad52de4ed304_Traceguids);
    }
  }
LAB_140005fa1:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
             &WPP_fae18269a3c73a60ae52ad52de4ed304_Traceguids,(int)uVar8);
  }
  return uVar8;
}



===== StorChannelGetProperties @ 140006010 =====

longlong StorChannelGetProperties(void)

{
  longlong lVar1;
  
  lVar1 = VmbChannelGetPointer();
  return lVar1 + 0x48;
}



===== StorChannelInitSyntheticVstorPacket @ 140006030 =====

void StorChannelInitSyntheticVstorPacket(void *param_1)

{
  memset(param_1,0,0x40);
  *(undefined4 *)((longlong)param_1 + 4) = 1;
  return;
}



===== StorChannelKmclEvtProcessPacket @ 140006060 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void StorChannelKmclEvtProcessPacket
               (undefined8 param_1,undefined8 param_2,int *param_3,uint param_4)

{
  int iVar1;
  char cVar2;
  longlong lVar3;
  int local_48 [16];
  
  memset(local_48,0,0x40);
  if (param_4 < 0x40) {
    memcpy(local_48,param_3,(ulonglong)param_4);
    param_3 = local_48;
  }
  iVar1 = *param_3;
  if (iVar1 != 0xb) {
    if (iVar1 == 0xc) {
      cVar2 = KeGetCurrentIrql();
      if (cVar2 == '\x02') {
        VmbChannelPacketDeferToPassive(param_2);
        return;
      }
    }
    else if (iVar1 != 0xe) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (2 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
                 &WPP_fae18269a3c73a60ae52ad52de4ed304_Traceguids,iVar1);
      }
      goto LAB_140006143;
    }
  }
  lVar3 = VmbChannelGetPointer(param_1);
  if (*(code **)(lVar3 + 0x68) != (code *)0x0) {
    (**(code **)(lVar3 + 0x68))(param_1,param_3);
  }
LAB_140006143:
  VmbChannelPacketComplete(param_2,0,0);
  return;
}



===== StorChannelKmclEvtSubChannelStarted @ 140006180 =====

void StorChannelKmclEvtSubChannelStarted(longlong param_1)

{
  undefined8 *puVar1;
  uint uVar2;
  longlong *plVar3;
  
  puVar1 = (undefined8 *)VmbChannelGetPointer();
  ExAcquireFastMutex(puVar1 + 1);
  uVar2 = 0;
  plVar3 = puVar1 + 0x12;
  do {
    if (*plVar3 == param_1) {
      *(undefined1 *)(puVar1 + (ulonglong)uVar2 * 2 + 0x13) = 1;
      StorChannelReevaluateSubChannels(puVar1);
      break;
    }
    uVar2 = uVar2 + 1;
    plVar3 = plVar3 + 2;
  } while (uVar2 < 0x3f);
  ExReleaseFastMutex(puVar1 + 1);
  return;
}



===== StorChannelKmclPacketCompletionRoutine @ 140006210 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void StorChannelKmclPacketCompletionRoutine
               (undefined8 param_1,int param_2,undefined4 *param_3,uint param_4)

{
  code *pcVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  undefined4 uVar5;
  undefined1 *puVar6;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [40];
  
  puVar6 = auStack_38;
  if ((-1 < param_2) && ((param_3 == (undefined4 *)0x0 || (puVar6 = auStack_38, param_4 < 0x30)))) {
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(0x3a);
    puVar6 = auStack_30;
  }
  *(undefined8 *)(puVar6 + -8) = 0x140006249;
  lVar2 = VmbPacketGetPointer();
  *(undefined8 *)(puVar6 + -8) = 0x14000625b;
  uVar3 = VmbPacketGetChannel(param_1);
  *(undefined8 *)(puVar6 + -8) = 0x14000626a;
  puVar4 = (undefined8 *)VmbChannelGetPointer(uVar3);
  pcVar1 = *(code **)(lVar2 + 8);
  if (pcVar1 != (code *)0x0) {
    uVar3 = *puVar4;
    if (param_2 < 0) {
      param_3 = (undefined4 *)0x0;
      uVar5 = 2;
    }
    else {
      uVar5 = *param_3;
    }
    *(undefined8 *)(puVar6 + -8) = 0x140006298;
    (*pcVar1)(uVar3,uVar5,param_3,lVar2);
  }
  return;
}



===== StorChannelReevaluateSubChannels @ 1400062b4 =====

void StorChannelReevaluateSubChannels(undefined8 *param_1)

{
  undefined8 *_Base;
  undefined8 *_Dst;
  short *psVar1;
  ushort uVar2;
  ushort uVar3;
  undefined4 uVar4;
  uint uVar5;
  ulonglong uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  size_t _Size;
  uint uVar11;
  uint uVar12;
  ulonglong uVar13;
  uint uVar14;
  longlong lVar15;
  ushort *_Base_00;
  
  _Base = param_1 + 0xa2;
  _Dst = param_1 + 0x92;
  *_Base = *param_1;
  uVar4 = VmbChannelGetTargetProcessorIndex();
  uVar9 = 0;
  *(undefined4 *)(param_1 + 0xa3) = uVar4;
  uVar13 = 0;
  uVar8 = 1;
  if (*(short *)(param_1 + 0x10) != 0) {
    do {
      if (*(char *)(param_1 + uVar13 * 2 + 0x13) != '\0') {
        _Base[(ulonglong)uVar8 * 2] = param_1[(uVar13 + 9) * 2];
        uVar4 = VmbChannelGetTargetProcessorIndex();
        *(undefined4 *)(param_1 + (ulonglong)uVar8 * 2 + 0xa3) = uVar4;
        uVar8 = uVar8 + 1;
      }
      uVar14 = (int)uVar13 + 1;
      uVar13 = (ulonglong)uVar14;
    } while (uVar14 < *(ushort *)(param_1 + 0x10));
  }
  qsort(_Base,(ulonglong)uVar8,0x10,StorChannelCompareChannelByProcessorIndex);
  uVar14 = KeQueryMaximumProcessorCountEx(0xffff);
  uVar13 = (ulonglong)uVar14;
  if (param_1[0x11] == 0) {
    if (uVar14 != 0) {
      lVar15 = 0;
      do {
        uVar6 = (uVar9 * uVar8) / uVar13;
        *(undefined8 *)(lVar15 + param_1[0x90]) = _Base[uVar6 * 2];
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,&WPP_GLOBAL_Control,
                    *(undefined4 *)(param_1 + uVar6 * 2 + 0xa3),(char)uVar9);
        }
        uVar9 = uVar9 + 1;
        lVar15 = lVar15 + 8;
      } while (uVar9 < uVar14);
    }
  }
  else {
    _Base_00 = (ushort *)param_1[0x91];
    uVar9 = 0;
    uVar12 = 0;
    if (uVar14 != 0) {
      do {
        uVar11 = uVar9;
        while (uVar11 = uVar11 + 1, uVar11 < uVar8) {
          uVar7 = uVar12 - *(int *)(param_1 + (ulonglong)uVar11 * 2 + 0xa3);
          uVar5 = uVar12 - *(int *)(param_1 + (ulonglong)uVar9 * 2 + 0xa3);
          uVar10 = *(int *)(param_1 + (ulonglong)uVar11 * 2 + 0xa3) - uVar12;
          if (-1 < (int)uVar7) {
            uVar10 = uVar7;
          }
          uVar7 = *(int *)(param_1 + (ulonglong)uVar9 * 2 + 0xa3) - uVar12;
          if (-1 < (int)uVar5) {
            uVar7 = uVar5;
          }
          if (uVar7 <= uVar10) break;
          uVar9 = uVar9 + 1;
        }
        uVar6 = (ulonglong)uVar12;
        _Base_00[uVar6 * 3] = (ushort)uVar12;
        _Base_00[uVar6 * 3 + 1] = (ushort)uVar9;
        uVar2 = (ushort)(uVar12 - *(int *)(param_1 + (ulonglong)uVar9 * 2 + 0xa3));
        uVar3 = -uVar2;
        if (-1 < (int)(uVar12 - *(int *)(param_1 + (ulonglong)uVar9 * 2 + 0xa3))) {
          uVar3 = uVar2;
        }
        uVar12 = uVar12 + 1;
        _Base_00[uVar6 * 3 + 2] = uVar3;
      } while (uVar12 < uVar14);
    }
    qsort(_Base_00,uVar13,6,StorChannelCompareProcessorByDistanceDescending);
    _Size = (ulonglong)uVar8 * 2;
    memset(_Dst,0,_Size);
    if (uVar14 != 0) {
      do {
        uVar6 = (ulonglong)_Base_00[1];
        uVar3 = *_Base_00;
        uVar9 = (uint)_Base_00[1];
        while (uVar9 = uVar9 + 1, uVar9 < uVar8) {
          uVar12 = (uint)uVar3 - *(int *)(param_1 + uVar6 * 2 + 0xa3);
          _Size = (size_t)uVar12;
          uVar14 = -((uint)uVar3 - *(int *)(param_1 + (ulonglong)uVar9 * 2 + 0xa3));
          if ((int)uVar14 < 0) {
            uVar14 = (uint)uVar3 - *(int *)(param_1 + (ulonglong)uVar9 * 2 + 0xa3);
          }
          uVar11 = -uVar12;
          if ((int)-uVar12 < 0) {
            uVar11 = uVar12;
          }
          if ((uVar11 < uVar14) ||
             (*(ushort *)((longlong)_Dst + uVar6 * 2) <=
              *(ushort *)((longlong)_Dst + (ulonglong)uVar9 * 2))) break;
          uVar6 = (ulonglong)((int)uVar6 + 1);
        }
        psVar1 = (short *)((longlong)_Dst + uVar6 * 2);
        *psVar1 = *psVar1 + 1;
        *(undefined8 *)(param_1[0x90] + (ulonglong)uVar3 * 8) = _Base[uVar6 * 2];
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,_Size,
                    *(undefined4 *)(param_1 + uVar6 * 2 + 0xa3),(char)uVar3);
        }
        _Base_00 = _Base_00 + 3;
        uVar13 = uVar13 - 1;
      } while (uVar13 != 0);
    }
  }
  return;
}



===== StorChannelSendSrbRequest @ 1400065cc =====

void StorChannelSendSrbRequest
               (undefined8 param_1,uint param_2,longlong param_3,longlong param_4,undefined8 param_5
               ,longlong *param_6,undefined8 param_7,longlong param_8)

{
  undefined2 uVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  longlong lVar4;
  int iVar5;
  longlong lVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined4 local_68 [3];
  ushort local_5c;
  byte local_53;
  char local_4c;
  
  memset(local_68,0,0x40);
  if (*(char *)(param_3 + 2) == '(') {
    lVar6 = *(longlong *)(param_3 + 0x40);
    uVar8 = *(undefined4 *)(param_3 + 0x3c);
    uVar7 = *(uint *)(param_3 + 0x18);
  }
  else {
    lVar6 = *(longlong *)(param_3 + 0x18);
    uVar8 = *(undefined4 *)(param_3 + 0x10);
    uVar7 = *(uint *)(param_3 + 0xc);
  }
  lVar4 = VmbChannelGetPointer(param_1);
  uVar2 = *(undefined8 *)(*(longlong *)(lVar4 + 0x480) + (ulonglong)param_2 * 8);
  StorChannelCopySrbToPacket(param_3,local_68);
  param_6[1] = (longlong)VscSrbCompletion;
  param_6[2] = param_8;
  param_6[3] = param_3;
  *param_6 = param_4;
  uVar1 = *(undefined2 *)(lVar4 + 0x70);
  if (*(ushort *)(lVar4 + 0x72) < local_5c) {
    local_5c = *(ushort *)(lVar4 + 0x72);
  }
  if (*(byte *)(lVar4 + 0x74) < local_53) {
    local_53 = *(byte *)(lVar4 + 0x74);
  }
  uVar3 = VmbChannelSizeofPacket(uVar2);
  VmbPacketInitialize(uVar2,param_7,uVar3);
  VmbPacketSetCompletionRoutine(param_7,StorChannelKmclPacketCompletionRoutine);
  VmbPacketSetPointer(param_7);
  iVar5 = 0;
  if (param_4 == 0) {
    VmbPacketSend(param_7,local_68,uVar1,0,1);
  }
  else {
    if ((((((local_4c == '\b') || (local_4c == '\n')) || (local_4c == '(')) ||
         ((local_4c == '*' || (local_4c == -0x78)))) ||
        ((local_4c == -0x76 || ((local_4c == -0x58 || (local_4c == -0x56)))))) &&
       (((ulonglong)*(uint *)(param_4 + 0x2c) + *(longlong *)(param_4 + 0x20) != lVar6 &&
        (((*(byte *)(param_4 + 10) & 1) == 0 || (*(longlong *)(param_4 + 0x18) != lVar6)))))) {
      iVar5 = ((int)lVar6 - *(int *)(param_4 + 0x20)) - *(uint *)(param_4 + 0x2c);
    }
    if ((uVar7 & 0x40) == 0) {
      uVar3 = 3;
      if ((uVar7 & 0x80) != 0) {
        uVar3 = 0x13;
      }
    }
    else {
      uVar3 = 0xb;
    }
    VmbPacketSendWithExternalMdl(param_7,local_68,uVar1,param_4,iVar5,uVar8,uVar3);
  }
  return;
}



===== StorChannelSendSyntheticVstorPacket @ 1400067e8 =====

ulonglong StorChannelSendSyntheticVstorPacket(undefined8 param_1,int *param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  uint local_res18 [4];
  
  lVar1 = VmbChannelGetPointer();
  local_res18[0] = (uint)*(ushort *)(lVar1 + 0x70);
  uVar2 = VmbChannelSendSynchronousRequest
                    (param_1,param_2,*(ushort *)(lVar1 + 0x70),0,1,param_2,local_res18,0);
  if (-1 < (int)uVar2) {
    if (local_res18[0] == *(ushort *)(lVar1 + 0x70)) {
      uVar2 = 0xc000009d;
      if (*param_2 == 1) {
        uVar2 = (ulonglong)(uint)param_2[2];
      }
    }
    else {
      uVar2 = 0xc0000001;
    }
  }
  return uVar2;
}



===== WPP_SF_dd @ 140006884 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_fae18269a3c73a60ae52ad52de4ed304_Traceguids,param_2,local_res20,4,
             &param_5,4,0);
  return;
}



===== StorChannelEnableStorPortNumaMode @ 1400068dc =====

bool StorChannelEnableStorPortNumaMode(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  longlong lVar2;
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  undefined8 uStack_18;
  
  lVar2 = VmbChannelGetPointer(param_2);
  if ((*(byte *)(lVar2 + 0x50) & 1) != 0) {
    local_38 = 4;
    local_34 = 0x28;
    local_30 = 0;
    uStack_28 = 0;
    local_20 = 0;
    uStack_18 = 0;
    iVar1 = StorPortExtendedFunction(0xe,param_1,1,&local_38);
    if (iVar1 != 0) {
      return false;
    }
    if (((byte)local_30 & 0x21) == 0x21) {
      local_30 = CONCAT44(local_30._4_4_,0x21);
      iVar1 = StorPortExtendedFunction(0xe,param_1,0,&local_38);
      return iVar1 == 0;
    }
  }
  return true;
}



===== StorChannelGetChannelRequirements @ 140006988 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int StorChannelGetChannelRequirements(undefined8 param_1,undefined2 *param_2,undefined8 *param_3)

{
  longlong lVar1;
  int iVar2;
  code *pcVar3;
  undefined1 auStack_178 [32];
  undefined8 local_158;
  uint local_148;
  uint local_144;
  undefined8 local_140;
  longlong local_138;
  undefined8 local_130;
  undefined8 local_128;
  undefined8 uStack_120;
  undefined8 local_118;
  undefined4 local_110;
  wchar_t *local_108;
  undefined8 local_100;
  undefined8 uStack_f8;
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined8 local_e0;
  undefined4 local_d8;
  wchar_t *local_d0;
  uint *local_c8;
  undefined4 local_c0;
  uint *local_b8;
  undefined4 local_b0;
  undefined8 local_a8;
  undefined4 local_a0;
  wchar_t *local_98;
  undefined8 *local_90;
  undefined4 local_88;
  undefined8 *local_80;
  undefined4 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_178;
  local_148 = 0;
  local_144 = 0;
  local_140 = 0;
  local_130 = 0;
  local_138 = 0;
  *param_2 = 1;
  *param_3 = 0;
  iVar2 = IoOpenDeviceRegistryKey(param_1,1,0x20019,&local_138);
  lVar1 = local_138;
  if (-1 < iVar2) {
    local_118 = 0;
    local_e0 = 0;
    local_a8 = 0;
    local_70 = 0;
    local_108 = L"StorChannel";
    local_d0 = L"ChannelCount";
    local_c8 = &local_148;
    local_b8 = &local_144;
    local_98 = L"ChannelMask";
    local_90 = &local_140;
    local_80 = &local_130;
    local_d8 = 0x120;
    local_a0 = 0x120;
    local_144 = 0x40;
    local_110 = 1;
    local_100 = 0;
    uStack_f8 = 0;
    local_c0 = 0x4000004;
    local_f0 = 0;
    uStack_e8 = 0;
    local_b0 = 4;
    local_88 = 0xb00000b;
    local_78 = 8;
    local_68 = 0;
    uStack_60 = 0;
    local_140 = 0xfffffffffffffff8;
    local_58 = 0;
    uStack_50 = 0;
    local_48 = 0;
    uStack_40 = 0;
    local_128 = 0;
    uStack_120 = 0;
    RtlInitUnicodeString(&local_128,L"RtlQueryRegistryValuesEx");
    pcVar3 = (code *)MmGetSystemRoutineAddress(&local_128);
    if (pcVar3 == (code *)0x0) {
      pcVar3 = RtlQueryRegistryValues_exref;
    }
    local_158 = 0;
    iVar2 = (*pcVar3)(0x40000000,lVar1,&local_118,0);
    if (iVar2 == -0x3fffffcc) {
      local_140 = local_130;
      local_148 = local_144;
    }
    else if (iVar2 < 0) goto LAB_140006b7f;
    if (0x3f < local_148 - 1) {
      iVar2 = KeQueryMaximumProcessorCountEx(0xffff);
      if ((iVar2 + 0xfU & 0xfffffff0) < 0x400) {
        iVar2 = KeQueryMaximumProcessorCountEx(0xffff);
        local_148 = iVar2 + 0xfU >> 4;
      }
      else {
        local_148 = 0x40;
      }
    }
    iVar2 = 0;
    *param_2 = (short)local_148;
    *param_3 = local_140;
  }
LAB_140006b7f:
  if (local_138 != 0) {
    ZwClose();
  }
  return iVar2;
}



===== HviIsAnyHypervisorPresent @ 140006bb8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x000140006bec) */
/* WARNING: Removing unreachable block (ram,0x000140006bdb) */

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



===== HviIsHypervisorMicrosoftCompatible @ 140006c14 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x000140006c41) */

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



===== ScsiWmipProcessRequest @ 140006c6c =====

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
  int *piVar13;
  uint *puVar14;
  ushort uVar15;
  uint uVar16;
  uint uVar17;
  undefined8 uVar18;
  ulonglong uVar19;
  undefined4 uVar20;
  short *local_38 [2];
  
  puVar14 = (uint *)0x0;
  uVar19 = 0;
  uVar16 = 0;
  *param_9 = 0;
  uVar5 = 0;
  if (param_2 != 8) {
    if (*param_1 != 0) {
      plVar8 = *(longlong **)(param_1 + 2);
      do {
        if ((*param_5 == *(longlong *)*plVar8) && (param_5[1] == ((longlong *)*plVar8)[1])) {
          uVar16 = *(uint *)(*(longlong **)(param_1 + 2) + uVar19 * 2 + 1);
          if (((2 < (byte)(param_2 - 1)) && (param_2 != 9)) ||
             ((uVar5 = param_7[0xd], -1 < (char)param_7[0xb] || (uVar5 < uVar16))))
          goto LAB_140006d3f;
          break;
        }
        uVar16 = (int)uVar19 + 1;
        uVar19 = (ulonglong)uVar16;
        plVar8 = plVar8 + 2;
      } while (uVar16 < *param_1);
    }
    *param_8 = 0;
    cVar4 = '\x04';
    goto LAB_1400070ae;
  }
LAB_140006d3f:
  if (param_2 < 6) {
    if (param_2 != 5) {
      if (param_2 == 0) {
        if (param_6 < 0x48) goto LAB_140006dbe;
        param_7[0xb] = param_7[0xb] & 0xffffffef;
        uVar5 = uVar16 * 8 + 0x40;
        param_7[0xd] = uVar16;
        param_7[0xc] = uVar5;
        if (param_6 < uVar5) {
          lVar12 = 0;
          iVar11 = 0;
        }
        else {
          puVar14 = param_7 + 0xf;
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
                                (param_3,param_4,uVar19,uVar5,param_7[0xf],
                                 (ulonglong)param_7[0xe] + (longlong)param_7);
              return cVar4;
            }
          }
          else if (param_2 == 3) {
            if (*(code **)(param_1 + 10) != (code *)0x0) {
              cVar4 = (**(code **)(param_1 + 10))
                                (param_3,param_4,uVar19,uVar5,param_7[0xe],param_7[0x10],
                                 (ulonglong)param_7[0xf] + (longlong)param_7);
              return cVar4;
            }
          }
          else if (param_2 == 4) {
            pcVar6 = *(code **)(param_1 + 0xe);
            if (pcVar6 != (code *)0x0) {
              uVar18 = 0;
              goto LAB_1400070d1;
            }
            goto LAB_1400070e5;
          }
LAB_140006dbe:
          cVar4 = '\x04';
          goto LAB_1400070e8;
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
        puVar14 = param_7 + 0xf;
        uVar16 = 1;
      }
      pcVar6 = *(code **)(param_1 + 6);
LAB_140006e9e:
      cVar4 = (*pcVar6)(param_3,param_4,uVar19,uVar5,uVar16,puVar14,iVar11,lVar12);
      return cVar4;
    }
    pcVar6 = *(code **)(param_1 + 0xe);
    if (pcVar6 != (code *)0x0) {
      uVar20 = 0;
      uVar18 = 0;
      goto LAB_1400070d6;
    }
  }
  else if (param_2 == 6) {
    pcVar6 = *(code **)(param_1 + 0xe);
    if (pcVar6 != (code *)0x0) {
      uVar18 = 1;
LAB_1400070d1:
      uVar20 = 1;
LAB_1400070d6:
      cVar4 = (*pcVar6)(param_3,param_4,uVar19,uVar18,uVar20);
      return cVar4;
    }
  }
  else {
    if (param_2 != 7) {
      if (param_2 != 8) {
        if (((param_2 == 9) && (pcVar6 = *(code **)(param_1 + 0xc), pcVar6 != (code *)0x0)) &&
           (0x47 < param_6)) {
          uVar16 = param_7[0xf];
          if (uVar16 <= param_6) {
            lVar12 = (longlong)param_7 + (ulonglong)uVar16;
            iVar11 = param_6 - uVar16;
            puVar14 = (uint *)(ulonglong)param_7[0x10];
            uVar16 = param_7[0xe];
            goto LAB_140006e9e;
          }
        }
        goto LAB_140006dbe;
      }
      local_38[0] = (short *)0x0;
      cVar4 = (**(code **)(param_1 + 4))(param_3,param_4,local_38);
      if (cVar4 == '\x01') {
        uVar16 = *param_1;
        uVar19 = (ulonglong)uVar16;
        lVar12 = *(longlong *)(param_1 + 2);
        uVar17 = uVar16 * 0x20 + 0x18;
        uVar5 = uVar16 * 0x20 + 0x34;
        if (local_38[0] == (short *)0x0) {
          uVar15 = 0;
        }
        else {
          uVar15 = 0;
          sVar2 = *local_38[0];
          while (sVar2 != 0) {
            uVar15 = uVar15 + 1;
            sVar2 = local_38[0][uVar15];
          }
          uVar15 = uVar15 * 2;
        }
        uVar7 = uVar15 + uVar5;
        if ((uVar7 < uVar5) || (uVar1 = uVar7 + 2, uVar1 < uVar7)) {
          cVar4 = '\x04';
          goto LAB_14000709f;
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
          param_7[4] = uVar16;
          if (uVar16 != 0) {
            piVar13 = (int *)(lVar12 + 8);
            puVar9 = (ulonglong *)(param_7 + 0xc);
            do {
              uVar3 = (*(ulonglong **)(piVar13 + -2))[1];
              puVar9[-3] = **(ulonglong **)(piVar13 + -2);
              puVar9[-2] = uVar3;
              if (*piVar13 == -1) {
                *(int *)(puVar9 + -1) = piVar13[1];
                iVar11 = 0;
                *puVar9 = 0;
              }
              else {
                *(uint *)(puVar9 + -1) = piVar13[1] | 8;
                *puVar9 = (ulonglong)uVar17;
                iVar11 = *piVar13;
              }
              *(int *)((longlong)puVar9 + -4) = iVar11;
              piVar13 = piVar13 + 4;
              puVar9 = puVar9 + 4;
              uVar19 = uVar19 - 1;
            } while (uVar19 != 0);
          }
          puVar10 = (undefined2 *)((ulonglong)uVar17 + (longlong)param_7);
          *puVar10 = 0x1a;
          memcpy(puVar10 + 1,L"ScsiMiniPort",0x1a);
          *(ushort *)((ulonglong)uVar5 + (longlong)param_7) = uVar15;
          memcpy((ushort *)((ulonglong)uVar5 + (longlong)param_7) + 1,local_38[0],(ulonglong)uVar15)
          ;
          param_6 = uVar1;
        }
      }
      else {
LAB_14000709f:
        param_6 = 0;
      }
      *param_8 = param_6;
LAB_1400070ae:
      *param_9 = 1;
      return cVar4;
    }
    pcVar6 = *(code **)(param_1 + 0xe);
    if (pcVar6 != (code *)0x0) {
      uVar20 = 0;
      uVar18 = 1;
      goto LAB_1400070d6;
    }
  }
LAB_1400070e5:
  cVar4 = '\x01';
LAB_1400070e8:
  *param_9 = 1;
  return cVar4;
}



===== _guard_check_icall @ 140007120 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 140007138 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 14000715c =====

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



===== __cpu_features_init @ 1400071d0 =====

/* WARNING: Removing unreachable block (ram,0x00014000723a) */
/* WARNING: Removing unreachable block (ram,0x0001400071e9) */
/* WARNING: Removing unreachable block (ram,0x0001400071da) */

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



===== __security_check_cookie @ 1400072a0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1400072e0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 140007310 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140007310. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140007340 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcpy @ 1400073c0 =====

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



===== memset @ 1400076c0 =====

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



===== __memset_repmovs @ 140007800 =====

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



===== __memset_query @ 140007880 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140007900 =====

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



===== __memset_spec_ermsb_repmovsb @ 140007a40 =====

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



===== __memset_spec_plain @ 140007ac0 =====

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



===== VscCleanupTracing @ 14000e010 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void VscCleanupTracing(void)

{
  undefined *puVar1;
  
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
              &WPP_95fe66d195233e1c089bc08587e1594c_Traceguids);
    }
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
  }
  McGenEventUnregister_EtwUnregister();
  return;
}



===== VscFindAdapter @ 14000e0d0 =====

undefined8
VscFindAdapter(longlong *param_1,longlong param_2,longlong param_3,longlong param_4,
              undefined8 param_5,longlong param_6,undefined1 *param_7)

{
  int iVar1;
  ulonglong uVar2;
  longlong *plVar3;
  longlong lVar4;
  undefined2 uVar5;
  undefined2 *puVar6;
  undefined8 uVar7;
  undefined2 local_48 [4];
  undefined8 local_40;
  
  local_48[0] = 0;
  local_40 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),param_2,
             &WPP_95fe66d195233e1c089bc08587e1594c_Traceguids,param_3);
  }
  param_1[0x12] = param_2;
  if ((char)param_1[2] == '\0') {
    puVar6 = local_48;
    iVar1 = StorChannelGetChannelRequirements(param_2,puVar6,&local_40);
    if (iVar1 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                 &WPP_95fe66d195233e1c089bc08587e1594c_Traceguids,iVar1);
      }
    }
    else {
      uVar2 = StorChannelOpen(param_3,puVar6,(longlong)param_1);
      iVar1 = (int)uVar2;
      if (iVar1 < 0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar5 = 0xe;
LAB_14000e285:
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,
                   &WPP_95fe66d195233e1c089bc08587e1594c_Traceguids,iVar1);
        }
      }
      else {
        uVar2 = VscQueryFcHbaData((longlong)param_1);
        iVar1 = (int)uVar2;
        if (-1 < iVar1) {
          *param_1 = param_3;
          param_1[1] = param_4;
          param_1[6] = 0;
          VmbChannelGetInterfaceInstance(param_1[3]);
          *(undefined1 *)(param_1 + 2) = 1;
          goto LAB_14000e2df;
        }
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar5 = 0xf;
          goto LAB_14000e285;
        }
      }
    }
    uVar7 = 2;
    if (param_1[3] != 0) {
      plVar3 = (longlong *)VmbChannelGetPointer();
      StorChannelCloseInternal(plVar3);
      param_1[3] = 0;
    }
  }
  else {
    if (param_1[3] == 0) {
      uVar7 = 2;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                &WPP_95fe66d195233e1c089bc08587e1594c_Traceguids);
      }
      goto LAB_14000e3a8;
    }
LAB_14000e2df:
    lVar4 = StorChannelGetProperties();
    *(undefined4 *)(param_6 + 0x18) = *(undefined4 *)(lVar4 + 0xc);
    *(undefined4 *)(param_6 + 0x1c) = 0x81;
    *(undefined1 *)(param_6 + 0x48) = 8;
    *(undefined1 *)(param_6 + 0x61) = 0x80;
    *(undefined2 *)(param_6 + 0x91) = 0xff01;
    *(undefined2 *)(param_6 + 0x59) = 0x100;
    *(undefined2 *)(param_6 + 0x52) = 0x101;
    *(undefined4 *)(param_6 + 0x30) = 1;
    *(undefined1 *)(param_6 + 0x51) = 1;
    *(undefined1 *)(param_6 + 0x5b) = 1;
    *(undefined4 *)(param_6 + 0x94) = 1;
    *(undefined1 *)(param_6 + 0xc4) = 1;
    *(undefined1 *)(param_6 + 0x93) = 1;
    memset(param_1 + 0x14,0,0x40);
    *(undefined4 *)(param_1 + 0x14) = 3;
    param_1[0x15] = (longlong)&HbaapiGuidList;
    param_1[0x16] = (longlong)QueryWmiRegInfo;
    param_1[0x17] = (longlong)QueryWmiDataBlock;
    param_1[0x1b] = 0;
    param_1[0x18] = 0;
    param_1[0x19] = 0;
    param_1[0x1a] = 0;
    *(undefined1 *)(param_6 + 0x90) = 2;
    iVar1 = VmbChannelSizeofPacket(param_1[3]);
    uVar7 = 1;
    *(int *)(param_6 + 0x8c) = iVar1 + 0x60;
  }
LAB_14000e3a8:
  *param_7 = 0;
  return uVar7;
}



===== VscFreeAdapterResources @ 14000e3d0 =====

void VscFreeAdapterResources(longlong param_1)

{
  longlong *plVar1;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
            &WPP_95fe66d195233e1c089bc08587e1594c_Traceguids);
  }
  if (*(longlong *)(param_1 + 0x38) != 0) {
    KeSetEvent(param_1 + 0x70,0,0);
    KeWaitForSingleObject(*(undefined8 *)(param_1 + 0x38),0,0,0,0);
    ObfDereferenceObject(*(undefined8 *)(param_1 + 0x38));
  }
  if (*(longlong *)(param_1 + 0x18) != 0) {
    plVar1 = (longlong *)VmbChannelGetPointer();
    StorChannelCloseInternal(plVar1);
    *(undefined8 *)(param_1 + 0x18) = 0;
  }
  if (*(longlong *)(param_1 + 0x30) != 0) {
    StorPortExtendedFunction(1,param_1);
    *(undefined8 *)(param_1 + 0x30) = 0;
  }
  return;
}



===== VscGetCrashInterfaceWorker @ 14000e4b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void VscGetCrashInterfaceWorker(undefined8 param_1,longlong *param_2)

{
  byte bVar1;
  longlong lVar2;
  longlong lVar3;
  int iVar4;
  uint uVar5;
  longlong lVar6;
  char cVar7;
  undefined1 auStack_a8 [32];
  undefined8 ***local_88;
  undefined4 local_80;
  undefined1 local_78;
  undefined8 *local_70;
  undefined8 *local_68;
  undefined8 ***local_58 [2];
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  undefined8 uStack_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_a8;
  lVar2 = *param_2;
  local_58[0] = (undefined8 ***)0x0;
  lVar3 = param_2[1];
  local_38 = 0;
  local_88 = local_58;
  local_48 = 0;
  uStack_40 = 0;
  local_20 = 0;
  uStack_18 = 0;
  local_30 = 0;
  uStack_28 = 0;
  iVar4 = StorPortExtendedFunction(0,lVar2,0x30,0x48636656);
  if (iVar4 == 0) {
    uStack_18 = CONCAT44(uStack_18._4_4_,1);
    local_20 = 0x200000002;
    Feature_CrashDumpOneMBTransferSize__private_IsEnabledDeviceUsageNoInline();
    uStack_18 = CONCAT44(8,(undefined4)uStack_18);
    KeInitializeEvent(&local_48,0,0);
    local_68 = &local_30;
    local_70 = &local_48;
    local_78 = 0;
    local_80 = 0x30;
    local_88 = local_58[0];
    lVar6 = IoBuildDeviceIoControlRequest(0x3ec080,*(undefined8 *)(lVar2 + 8),&local_20,0x10);
    if (lVar6 != 0) {
      iVar4 = IofCallDriver(*(undefined8 *)(lVar2 + 8),lVar6);
      if (iVar4 == 0x103) {
        local_88 = (undefined8 ***)0x0;
        KeWaitForSingleObject(&local_48,0,0,0);
        iVar4 = (int)local_30;
      }
      if (-1 < iVar4) {
        bVar1 = *(byte *)(lVar3 + 2);
        if (bVar1 == 0x28) {
          uVar5 = *(uint *)(lVar3 + 0x14);
        }
        else {
          uVar5 = (uint)bVar1;
        }
        if (uVar5 == 0x26) {
          if (bVar1 == 0x28) {
            uVar5 = *(uint *)(lVar3 + 0x3c);
          }
          else {
            uVar5 = *(uint *)(lVar3 + 0x10);
          }
          if (0x6f < uVar5) {
            if (bVar1 == 0x28) {
              lVar6 = *(longlong *)(lVar3 + 0x40);
            }
            else {
              lVar6 = *(longlong *)(lVar3 + 0x18);
            }
            *(undefined8 ****)(lVar6 + 0x40) = local_58[0];
            goto LAB_14000e657;
          }
        }
        else {
          if (bVar1 == 0x28) {
            uVar5 = *(uint *)(lVar3 + 0x3c);
          }
          else {
            uVar5 = *(uint *)(lVar3 + 0x10);
          }
          if (0x17 < uVar5) {
            if (bVar1 == 0x28) {
              lVar6 = *(longlong *)(lVar3 + 0x40);
            }
            else {
              lVar6 = *(longlong *)(lVar3 + 0x18);
            }
            *(undefined8 ****)(lVar6 + 0x10) = local_58[0];
LAB_14000e657:
            *(undefined8 ****)(lVar2 + 0x30) = local_58[0];
            if (*(char *)(lVar3 + 2) == '(') {
              cVar7 = (*(char *)(lVar3 + 3) >> 7 & 0x80U) + 1;
            }
            else {
              cVar7 = '\x01';
              if (*(char *)(lVar3 + 3) < '\0') {
                cVar7 = -0x7f;
              }
            }
            *(char *)(lVar3 + 3) = cVar7;
            goto LAB_14000e6cb;
          }
        }
      }
    }
  }
  if (*(char *)(lVar3 + 2) == '(') {
    cVar7 = (*(char *)(lVar3 + 3) >> 7 & 0x80U) + 4;
  }
  else {
    cVar7 = '\x04';
    if (*(char *)(lVar3 + 3) < '\0') {
      cVar7 = -0x7c;
    }
  }
  *(char *)(lVar3 + 3) = cVar7;
  if (local_58[0] != (undefined8 ***)0x0) {
    StorPortExtendedFunction(1,lVar2);
  }
LAB_14000e6cb:
  StorPortNotification(0,lVar2,lVar3);
  IoFreeWorkItem(param_2[2]);
  StorPortExtendedFunction(1,lVar2,param_2);
  return;
}



===== VscHwInitialize @ 14000e740 =====

bool VscHwInitialize(longlong param_1)

{
  bool bVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  undefined8 local_res10;
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 uStack_10;
  
  lVar3 = param_1 + 0x40;
  local_1c = 0;
  local_34 = 0;
  local_res10 = 0;
  lVar4 = 3;
  do {
    KeInitializeEvent(lVar3,1);
    lVar3 = lVar3 + 0x18;
    lVar4 = lVar4 + -1;
  } while (lVar4 != 0);
  local_30 = 0;
  local_28 = 0;
  local_38 = 0x30;
  local_20 = 0x200;
  local_18 = 0;
  uStack_10 = 0;
  iVar2 = PsCreateSystemThread(&local_res10,0,&local_38,0,0,VscPmEventDispatcher,param_1);
  if (-1 < iVar2) {
    iVar2 = ObReferenceObjectByHandle(local_res10,0x1fffff,0,0,param_1 + 0x38,0);
    ZwClose(local_res10);
    if (-1 < iVar2) {
      bVar1 = StorChannelEnableStorPortNumaMode(param_1,*(undefined8 *)(param_1 + 0x18));
      return bVar1;
    }
  }
  return false;
}



===== VscInitializeTracing @ 14000e850 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void VscInitializeTracing(undefined8 param_1,ulonglong param_2)

{
  code *pcVar1;
  undefined *puVar2;
  ulonglong local_res10;
  undefined8 local_18;
  undefined8 uStack_10;
  
  _DAT_14000b1e8 = 1;
  _WPP_MAIN_CB = (code *)0x0;
  DAT_14000b1c8 = &WPP_ThisDir_CTLGUID_SynthfcVscDriverTraceGuid;
  DAT_14000b1d0 = 0;
  _DAT_14000b1e0 = 0;
  local_res10 = param_2 & 0xffffffff00000000;
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
    (*pfnWppGetVersion)(&local_res10,0,0,0);
  }
  if (5 < (uint)local_res10) {
    RtlInitUnicodeString(&local_18,L"EtwRegisterClassicProvider");
    pfnEtwRegisterClassicProvider = (code *)MmGetSystemRoutineAddress(&local_18);
    if (pfnEtwRegisterClassicProvider != (code *)0x0) {
      RtlInitUnicodeString(&local_18,L"EtwUnregister");
      pfnEtwUnregister = MmGetSystemRoutineAddress(&local_18);
      WPPTraceSuite = 4;
    }
  }
  puVar2 = &WPP_MAIN_CB;
  _DAT_14000b1e0 = 0;
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
  McGenEventRegister_EtwRegister();
  return;
}



===== VscQueryFcHbaData @ 14000ea68 =====

ulonglong VscQueryFcHbaData(longlong param_1)

{
  ulonglong uVar1;
  int local_48 [3];
  undefined1 local_3c;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  
  memset(local_48,0,0x40);
  StorChannelInitSyntheticVstorPacket(local_48);
  local_48[0] = 0xc;
  uVar1 = StorChannelSendSyntheticVstorPacket(*(undefined8 *)(param_1 + 0x18),local_48);
  if ((int)uVar1 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
               &WPP_95fe66d195233e1c089bc08587e1594c_Traceguids,(int)uVar1);
    }
  }
  else {
    *(undefined1 *)(param_1 + 0x99) = local_3c;
    *(undefined8 *)(param_1 + 0xe0) = local_38;
    *(undefined8 *)(param_1 + 0xe8) = local_30;
    *(undefined8 *)(param_1 + 0xf0) = local_28;
    *(undefined8 *)(param_1 + 0xf8) = local_20;
    VscSetHbaAddress(param_1);
  }
  return uVar1 & 0xffffffff;
}



===== VscSetHbaAddress @ 14000eb3c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int VscSetHbaAddress(longlong param_1)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 auStack_168 [32];
  wchar_t *local_148;
  uint local_140;
  undefined8 local_138;
  uint local_130;
  uint local_128;
  uint local_120;
  uint local_118;
  longlong local_108;
  longlong local_100;
  undefined8 local_f8;
  longlong lStack_f0;
  undefined8 *local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  ulonglong uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  wchar_t local_b8 [64];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_168;
  iVar1 = 0;
  local_100 = 0;
  local_108 = 0;
  local_f8 = 0;
  lStack_f0 = 0;
  local_d8 = 0;
  local_e8 = (undefined8 *)0x0;
  uStack_e0 = 0;
  uStack_d0 = uStack_d0 & 0xffffffff00000000;
  local_c8 = 0;
  uStack_c0 = 0;
  if (*(char *)(param_1 + 0x98) == '\0') {
    iVar1 = IoOpenDeviceRegistryKey(*(undefined8 *)(param_1 + 0x90),1,0x2001f,&local_100);
    if (-1 < iVar1) {
      RtlInitUnicodeString(&local_c8,L"VirtualHba");
      lStack_f0 = local_100;
      local_e8 = &local_c8;
      local_138 = 0;
      local_140 = 0;
      local_f8 = CONCAT44(local_f8._4_4_,0x30);
      uStack_e0 = CONCAT44(uStack_e0._4_4_,0x240);
      local_d8 = 0;
      uStack_d0 = 0;
      local_148 = (wchar_t *)0x0;
      iVar1 = ZwCreateKey(&local_108,0x2001f,&local_f8,0);
      if (-1 < iVar1) {
        local_118 = (uint)*(byte *)(param_1 + 0xe7);
        local_120 = (uint)*(byte *)(param_1 + 0xe6);
        local_128 = (uint)*(byte *)(param_1 + 0xe5);
        local_130 = (uint)*(byte *)(param_1 + 0xe4);
        local_138 = CONCAT44(local_138._4_4_,(uint)*(byte *)(param_1 + 0xe3));
        local_140 = (uint)*(byte *)(param_1 + 0xe2);
        local_148 = (wchar_t *)CONCAT44(local_148._4_4_,(uint)*(byte *)(param_1 + 0xe1));
        RtlStringCchPrintfW(local_b8,0x40,L"%02X%02X%02X%02X%02X%02X%02X%02X",
                            (ulonglong)*(byte *)(param_1 + 0xe0));
        lVar3 = -1;
        lVar2 = -1;
        do {
          lVar2 = lVar2 + 1;
        } while (local_b8[lVar2] != L'\0');
        local_140 = (int)lVar2 * 2 + 2;
        local_148 = local_b8;
        iVar1 = RtlWriteRegistryValue(0x40000000,local_108,L"WWPN Set A",1);
        if (-1 < iVar1) {
          local_118 = (uint)*(byte *)(param_1 + 0xef);
          local_120 = (uint)*(byte *)(param_1 + 0xee);
          local_128 = (uint)*(byte *)(param_1 + 0xed);
          local_130 = (uint)*(byte *)(param_1 + 0xec);
          local_138 = CONCAT44(local_138._4_4_,(uint)*(byte *)(param_1 + 0xeb));
          local_140 = (uint)*(byte *)(param_1 + 0xea);
          local_148 = (wchar_t *)CONCAT44(local_148._4_4_,(uint)*(byte *)(param_1 + 0xe9));
          RtlStringCchPrintfW(local_b8,0x40,L"%02X%02X%02X%02X%02X%02X%02X%02X",
                              (ulonglong)*(byte *)(param_1 + 0xe8));
          lVar2 = -1;
          do {
            lVar2 = lVar2 + 1;
          } while (local_b8[lVar2] != L'\0');
          local_140 = (int)lVar2 * 2 + 2;
          local_148 = local_b8;
          iVar1 = RtlWriteRegistryValue(0x40000000,local_108,L"WWNN Set A",1);
          if (-1 < iVar1) {
            local_118 = (uint)*(byte *)(param_1 + 0xf7);
            local_120 = (uint)*(byte *)(param_1 + 0xf6);
            local_128 = (uint)*(byte *)(param_1 + 0xf5);
            local_130 = (uint)*(byte *)(param_1 + 0xf4);
            local_138 = CONCAT44(local_138._4_4_,(uint)*(byte *)(param_1 + 0xf3));
            local_140 = (uint)*(byte *)(param_1 + 0xf2);
            local_148 = (wchar_t *)CONCAT44(local_148._4_4_,(uint)*(byte *)(param_1 + 0xf1));
            RtlStringCchPrintfW(local_b8,0x40,L"%02X%02X%02X%02X%02X%02X%02X%02X",
                                (ulonglong)*(byte *)(param_1 + 0xf0));
            lVar2 = -1;
            do {
              lVar2 = lVar2 + 1;
            } while (local_b8[lVar2] != L'\0');
            local_140 = (int)lVar2 * 2 + 2;
            local_148 = local_b8;
            iVar1 = RtlWriteRegistryValue(0x40000000,local_108,L"WWPN Set B",1);
            if (-1 < iVar1) {
              local_118 = (uint)*(byte *)(param_1 + 0xff);
              local_120 = (uint)*(byte *)(param_1 + 0xfe);
              local_128 = (uint)*(byte *)(param_1 + 0xfd);
              local_130 = (uint)*(byte *)(param_1 + 0xfc);
              local_138 = CONCAT44(local_138._4_4_,(uint)*(byte *)(param_1 + 0xfb));
              local_140 = (uint)*(byte *)(param_1 + 0xfa);
              local_148 = (wchar_t *)CONCAT44(local_148._4_4_,(uint)*(byte *)(param_1 + 0xf9));
              RtlStringCchPrintfW(local_b8,0x40,L"%02X%02X%02X%02X%02X%02X%02X%02X",
                                  (ulonglong)*(byte *)(param_1 + 0xf8));
              do {
                lVar3 = lVar3 + 1;
              } while (local_b8[lVar3] != L'\0');
              local_140 = (int)lVar3 * 2 + 2;
              local_148 = local_b8;
              iVar1 = RtlWriteRegistryValue(0x40000000,local_108,L"WWNN Set B",1);
              if (-1 < iVar1) {
                *(undefined1 *)(param_1 + 0x98) = 1;
              }
            }
          }
        }
      }
    }
    if (local_108 != 0) {
      ZwClose();
    }
    if (local_100 != 0) {
      ZwClose();
    }
  }
  return iVar1;
}



===== VscUpdateHbaData @ 14000efb8 =====

undefined8 VscUpdateHbaData(longlong param_1,longlong param_2)

{
  *(undefined1 *)(param_1 + 0x99) = *(undefined1 *)(param_2 + 0xc);
  *(undefined8 *)(param_1 + 0xe0) = *(undefined8 *)(param_2 + 0x10);
  *(undefined8 *)(param_1 + 0xe8) = *(undefined8 *)(param_2 + 0x18);
  *(undefined8 *)(param_1 + 0xf0) = *(undefined8 *)(param_2 + 0x20);
  *(undefined8 *)(param_1 + 0xf8) = *(undefined8 *)(param_2 + 0x28);
  VscSetHbaAddress(param_1);
  return 0;
}



===== WppTraceCallback @ 14000f010 =====

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



===== wil_details_EvaluateFeatureDependencies @ 14000f298 =====

void wil_details_EvaluateFeatureDependencies(void)

{
  uint uVar1;
  undefined **ppuVar2;
  undefined **ppuVar3;
  undefined *puVar4;
  bool bVar5;
  
  puVar4 = (undefined *)0x0;
  ppuVar3 = &Feature_CrashDumpOneMBTransferSize__private_descriptor;
  ppuVar2 = &Feature_CrashDumpOneMBTransferSize__private_descriptor;
  do {
    if (*ppuVar2 != (undefined *)0x0) goto joined_r0x00014000f2d3;
    ppuVar2 = ppuVar2 + 1;
  } while (ppuVar2 < &wil_details_featureDescriptors_z);
LAB_14000f34d:
  while( true ) {
    if (&UNK_14000a16f < ppuVar3) {
      return;
    }
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  do {
    if (ppuVar3 == (undefined **)0x0) {
      return;
    }
    wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
              ((uint *)*ppuVar3,(longlong)ppuVar3);
    ppuVar3 = ppuVar3 + 7;
    while( true ) {
      if (&UNK_14000a16f < ppuVar3) {
        return;
      }
      if (*ppuVar3 != puVar4) break;
      ppuVar3 = ppuVar3 + 1;
    }
  } while( true );
joined_r0x00014000f2d3:
  while (ppuVar2 != (undefined **)0x0) {
    uVar1 = *(uint *)*ppuVar2;
    if ((uVar1 >> 9 & 1) != 0) {
      if ((uVar1 & 0x180) == 0) {
        bVar5 = *(char *)((longlong)ppuVar2 + 0x1f) != '\0';
      }
      else {
        bVar5 = (uVar1 & 0x180) == 0x100;
      }
      LOCK();
      *(uint *)*ppuVar2 = *(uint *)*ppuVar2 ^ uVar1 & 0x40 ^ (uint)bVar5 << 6;
      UNLOCK();
    }
    ppuVar2 = ppuVar2 + 7;
    while( true ) {
      if (&UNK_14000a16f < ppuVar2) goto LAB_14000f34d;
      if (*ppuVar2 != (undefined *)0x0) break;
      ppuVar2 = ppuVar2 + 1;
    }
  }
  goto LAB_14000f34d;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 14000f388 =====

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
          if (puVar1 == (undefined8 *)0x0) goto LAB_14000f420;
          if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
             (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
          if ((uVar4 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
            uVar4 = 0;
            goto LAB_14000f420;
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
LAB_14000f420:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 14000f470 =====

void wil_details_OnFeatureUsageProviderFlushNotification(int param_1)

{
  int iVar1;
  undefined **ppuVar2;
  
  iVar1 = g_wil_details_featureUsageCached;
  if (param_1 == 1) {
    LOCK();
    g_wil_details_featureUsageCached = 0;
    UNLOCK();
    if (iVar1 != 0) {
      for (ppuVar2 = &Feature_CrashDumpOneMBTransferSize__private_descriptor;
          ppuVar2 < &wil_details_featureDescriptors_z; ppuVar2 = ppuVar2 + 1) {
        if (*ppuVar2 != (undefined *)0x0) {
          do {
            if (ppuVar2 == (undefined **)0x0) {
              return;
            }
            if ((*(uint *)ppuVar2[1] & 1) != 0) {
              wil_details_RecordCachedUsage(*(undefined4 *)(ppuVar2 + 3),(uint *)ppuVar2[1]);
            }
            ppuVar2 = ppuVar2 + 7;
            while( true ) {
              if (&UNK_14000a16f < ppuVar2) {
                return;
              }
              if (*ppuVar2 != (undefined *)0x0) break;
              ppuVar2 = ppuVar2 + 1;
            }
          } while( true );
        }
      }
    }
  }
  return;
}



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 14000f4f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_ReevaluateOnFeatureConfigurationChange(void)

{
  int iVar1;
  uint uVar2;
  undefined **ppuVar3;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined8 local_20;
  undefined4 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  for (ppuVar3 = &Feature_CrashDumpOneMBTransferSize__private_descriptor;
      ppuVar3 < &wil_details_featureDescriptors_z; ppuVar3 = ppuVar3 + 1) {
    if (*ppuVar3 != (undefined *)0x0) goto LAB_14000f5ed;
  }
LAB_14000f5f6:
  wil_details_EvaluateFeatureDependencies();
  return;
LAB_14000f5ed:
  if (ppuVar3 == (undefined **)0x0) goto LAB_14000f5f6;
  if (((*(char *)((longlong)ppuVar3 + 0x1d) == '\0') &&
      (*(char *)((longlong)ppuVar3 + 0x1e) == '\0')) &&
     (*(char *)((longlong)ppuVar3 + 0x1c) == '\0')) {
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    iVar1 = RtlQueryFeatureConfiguration(*(undefined4 *)(ppuVar3 + 3),1,&local_28,&local_20);
    if ((iVar1 == -0x7fffffde) || (iVar1 == -0x3ffffddb)) {
LAB_14000f5be:
      uVar2 = 0x206;
    }
    else {
      if (iVar1 == 0) {
        uVar2 = (local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0;
      }
      else {
        if (iVar1 != 0x117) goto LAB_14000f5be;
        uVar2 = local_20._4_4_ & 0x80;
      }
      uVar2 = uVar2 << 3 | 0x206;
    }
    LOCK();
    *(uint *)*ppuVar3 = *(uint *)*ppuVar3 ^ (*(uint *)*ppuVar3 ^ uVar2) & 0xf80;
    UNLOCK();
  }
  ppuVar3 = ppuVar3 + 7;
  while( true ) {
    if (&UNK_14000a16f < ppuVar3) goto LAB_14000f5f6;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_14000f5ed;
}



===== StorChannelCloseInternal @ 14000f61c =====

void StorChannelCloseInternal(longlong *param_1)

{
  longlong lVar1;
  longlong *plVar2;
  
  if (*param_1 != 0) {
    VmbChannelDisable();
    plVar2 = param_1 + 0x12;
    lVar1 = 0x3f;
    do {
      if (*plVar2 != 0) {
        VmbChannelCleanup();
      }
      plVar2 = plVar2 + 2;
      lVar1 = lVar1 + -1;
    } while (lVar1 != 0);
    VmbChannelCleanup(*param_1);
  }
  ExFreePoolWithTag(param_1,0x63736d56);
  return;
}



===== StorChannelOpen @ 14000f6a8 =====

ulonglong StorChannelOpen(longlong param_1,undefined8 param_2,longlong param_3)

{
  uint uVar1;
  longlong *plVar2;
  ulonglong uVar3;
  longlong *plVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  longlong local_res10;
  short in_stack_00000038;
  ulonglong in_stack_00000040;
  longlong *in_stack_00000048;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  
  local_res10 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  if ((ushort)(in_stack_00000038 - 1U) < 0x40) {
    uVar1 = KeQueryMaximumProcessorCountEx(0xffff);
    plVar2 = (longlong *)ExAllocatePool2(0x40,uVar1 * 0xe + 0x910,0x63736d56);
    if (plVar2 == (longlong *)0x0) {
      uVar6 = 0xc000009a;
    }
    else {
      plVar2[2] = 0;
      *(undefined4 *)(plVar2 + 3) = 0;
      plVar2[0x90] = (longlong)(plVar2 + 0x122);
      *(undefined4 *)(plVar2 + 1) = 1;
      plVar2[0x91] = (longlong)(plVar2 + 0x122 + uVar1);
      KeInitializeEvent(plVar2 + 4,1,0);
      uVar1 = VmbChannelAllocate(param_1,0,&local_res10);
      uVar6 = (ulonglong)uVar1;
      if (-1 < (int)uVar1) {
        uVar1 = VmbChannelAllocateForStorage(local_res10);
        uVar6 = (ulonglong)uVar1;
        if (-1 < (int)uVar1) {
          VmbChannelInitSetBounceBufferSizes(local_res10,0,0x200000,0);
          VmbChannelInitSetMaximumPacketSize(local_res10,0x40);
          VmbClientChannelInitSetRingBufferPageCount(local_res10,10,10);
          VmbChannelInitSetProcessPacketCallbacks(local_res10,StorChannelKmclEvtProcessPacket,0);
          uStack_30 = 0;
          uStack_50 = 0;
          local_48 = 0;
          local_58 = 0x3000000001;
          uStack_40 = 0;
          local_38 = 0;
          VmbChannelInitSetStateChangeCallbacks(local_res10,&local_58);
          VmbChannelInitSetFlags(local_res10,2);
          uVar6 = 0;
          if (in_stack_00000040 != 0) {
            uVar6 = 0;
            if (in_stack_00000040 != 0) {
              for (; (in_stack_00000040 >> uVar6 & 1) == 0; uVar6 = uVar6 + 1) {
              }
            }
            VmbClientChannelInitSetTargetProcessorIndex(local_res10,uVar6 & 0xffffffff);
            uVar6 = in_stack_00000040 & ~(1L << (uVar6 & 0x3f));
          }
          plVar2[0xf] = param_1;
          *plVar2 = local_res10;
          *(short *)(plVar2 + 0x10) = in_stack_00000038 + -1;
          plVar2[8] = param_3;
          plVar2[0xd] = (longlong)VscChannelEventNotification;
          *(undefined4 *)(plVar2 + 0xe) = 0x240030;
          *(undefined1 *)((longlong)plVar2 + 0x74) = 0x12;
          plVar2[0x11] = uVar6;
          StorChannelReevaluateSubChannels(plVar2);
          plVar4 = plVar2;
          VmbChannelSetPointer(local_res10,plVar2);
          uVar5 = CONCAT71((int7)((ulonglong)plVar4 >> 8),100);
          VmbChannelSetAllowableDpcCpuUsage(local_res10);
          *(undefined1 *)((longlong)plVar2 + 0x75) = 1;
          uVar1 = VmbChannelEnable(local_res10);
          uVar6 = (ulonglong)uVar1;
          if ((int)uVar1 < 0) {
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
               (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
                       &WPP_fae18269a3c73a60ae52ad52de4ed304_Traceguids,uVar1);
            }
          }
          else {
            uVar3 = StorChannelEstablishCommunications(local_res10,uVar5);
            uVar6 = uVar3 & 0xffffffff;
            if (-1 < (int)uVar3) {
              *in_stack_00000048 = local_res10;
              return 0;
            }
          }
        }
      }
      StorChannelCloseInternal(plVar2);
    }
  }
  else {
    uVar6 = 0xc000000d;
  }
  return uVar6;
}



===== entry @ 140011010 =====

void entry(longlong param_1,undefined8 param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 140011044 =====

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



===== DriverEntry @ 140011078 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int DriverEntry(longlong param_1,undefined8 param_2)

{
  int iVar1;
  ulonglong uVar2;
  undefined1 auStack_228 [32];
  undefined4 local_208;
  undefined4 local_204;
  code *local_200;
  code *local_1f8;
  code *local_1f0;
  code *local_1e8;
  code *local_1e0;
  undefined4 local_1c8;
  code *local_190;
  code *local_180;
  code *local_168;
  code *local_160;
  uint local_150;
  undefined4 local_14c;
  undefined4 local_148;
  undefined4 local_138;
  undefined1 local_134 [284];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_228;
  memset(&local_208,0,0xd0);
  local_208 = 0xd0;
  if (g_DumpPreInitializeInvoked == '\0') {
    wil_InitializeFeatureStaging();
    uVar2 = Feature_CrashDumpOneMBTransferSize__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar2 != 0) {
      InitializeMultiphaseResumeRegKey();
    }
  }
  if (param_1 == 0) {
    local_1c8 = 0x1f58;
    local_200 = CrashVscHwResetBus;
    local_1f8 = CrashVscHwStartIO;
    local_1f0 = CrashVscHwInterrupt;
    local_1e8 = CrashVscHwFindAdapter;
  }
  else {
    memset(local_134,0,0x110);
    local_138 = 0x114;
    RtlGetVersion(&local_138);
    local_1c8 = 0x100;
    local_200 = VscHwInitialize;
    local_1f8 = VscStartIO;
    local_1e8 = VscFindAdapter;
    local_190 = VscAdapterControl;
    local_180 = VscFreeAdapterResources;
    local_168 = VscInitializeTracing;
    local_160 = VscCleanupTracing;
  }
  local_1e0 = CrashVscHwResetBus;
  local_150 = 1;
  uVar2 = Feature_CrashDumpOneMBTransferSize__private_IsEnabledNoReportingNoInline();
  if (((int)uVar2 != 0) && (g_isMultiPhaseEnabledInStorVsc != '\0')) {
    local_150 = local_150 | 0x20;
  }
  local_204 = 0;
  local_14c = 2;
  local_148 = 1;
  iVar1 = StorPortInitialize(param_1,param_2,&local_208,0);
  if (g_DumpPreInitializeInvoked == '\0') {
    if (iVar1 == 0) {
      StorPortDriverUnload = *(longlong *)(param_1 + 0x68);
      if (StorPortDriverUnload != 0) {
        *(code **)(param_1 + 0x68) = VscDriverUnload;
      }
    }
    else {
      if (g_wil_details_featureChangeNotification != 0) {
        RtlUnregisterFeatureConfigurationChangeNotification();
        g_wil_details_featureChangeNotification = 0;
      }
      if (g_wil_details_featureUsageProvider != 0) {
        RtlUnregisterFeatureUsageProvider();
        g_wil_details_featureUsageProvider = 0;
      }
      g_wil_details_isFeatureStagingInitialized = 0;
    }
  }
  return iVar1;
}



===== wil_InitializeFeatureStaging @ 1400112a4 =====

int wil_InitializeFeatureStaging(void)

{
  bool bVar1;
  int iVar2;
  undefined **ppuVar3;
  undefined8 local_res8;
  
  bVar1 = false;
  if (g_wil_details_isFeatureStagingInitialized == 0) {
    g_wil_details_isFeatureStagingInitialized = 1;
    local_res8 = RtlQueryFeatureConfigurationChangeStamp();
    wil_details_PopulateInitialConfiguredFeatureStates();
    wil_details_EvaluateFeatureDependencies();
    for (ppuVar3 = &Feature_CrashDumpOneMBTransferSize__private_descriptor;
        ppuVar3 < &wil_details_featureDescriptors_z; ppuVar3 = ppuVar3 + 1) {
      if (*ppuVar3 != (undefined *)0x0) goto LAB_14001132b;
    }
LAB_140011365:
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
LAB_14001132b:
  if (ppuVar3 == (undefined **)0x0) goto LAB_140011365;
  if (((*(char *)((longlong)ppuVar3 + 0x1d) == '\0') &&
      (*(char *)((longlong)ppuVar3 + 0x1e) == '\0')) &&
     (*(char *)((longlong)ppuVar3 + 0x1c) == '\0')) {
    iVar2 = RtlRegisterFeatureConfigurationChangeNotification
                      (wil_details_ReevaluateOnFeatureConfigurationChange,0,&local_res8,
                       &g_wil_details_featureChangeNotification);
    if (iVar2 == 0) {
      bVar1 = true;
    }
    else {
      g_wil_details_featureChangeNotification = 0;
    }
    goto LAB_140011365;
  }
  ppuVar3 = ppuVar3 + 7;
  while( true ) {
    if (&UNK_14000a16f < ppuVar3) goto LAB_140011365;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_14001132b;
}



===== wil_details_PopulateInitialConfiguredFeatureStates @ 1400113b8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_PopulateInitialConfiguredFeatureStates(void)

{
  ulonglong *puVar1;
  undefined8 *puVar2;
  int iVar3;
  undefined **ppuVar4;
  undefined1 auStack_48 [32];
  ulonglong local_28;
  undefined8 local_20;
  undefined4 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  ppuVar4 = &Feature_CrashDumpOneMBTransferSize__private_descriptor;
  while( true ) {
    if (&wil_details_featureDescriptors_z <= ppuVar4) {
      return;
    }
    if (*ppuVar4 != (undefined *)0x0) break;
    ppuVar4 = ppuVar4 + 1;
  }
  do {
    if (ppuVar4 == (undefined **)0x0) {
      return;
    }
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    if ((*(char *)((longlong)ppuVar4 + 0x1d) == '\0') &&
       (*(char *)((longlong)ppuVar4 + 0x1e) == '\0')) {
      iVar3 = RtlQueryFeatureConfiguration
                        (*(undefined4 *)(ppuVar4 + 3),
                         1 < (byte)(*(char *)((longlong)ppuVar4 + 0x1c) - 2U),&local_28,&local_20);
      if (iVar3 == -0x7fffffde) {
        do {
          puVar2 = (undefined8 *)*ppuVar4;
          ppuVar4 = ppuVar4 + 7;
          *puVar2 = 0x206;
          while( true ) {
            if (&UNK_14000a16f < ppuVar4) {
              return;
            }
            if (*ppuVar4 != (undefined *)0x0) break;
            ppuVar4 = ppuVar4 + 1;
          }
        } while (ppuVar4 != (undefined **)0x0);
        return;
      }
      if (iVar3 == -0x3ffffddb) goto LAB_1400114a2;
      if (iVar3 == 0) {
        local_28 = (ulonglong)(((local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0) << 3 | 0x206);
      }
      else {
        if (iVar3 != 0x117) goto LAB_1400114a2;
        local_28 = (ulonglong)((local_20._4_4_ & 0x80) << 3 | 0x206);
      }
    }
    else {
LAB_1400114a2:
      local_28 = 0x206;
    }
    puVar1 = (ulonglong *)*ppuVar4;
    ppuVar4 = ppuVar4 + 7;
    *puVar1 = local_28;
    while( true ) {
      if (&UNK_14000a16f < ppuVar4) {
        return;
      }
      if (*ppuVar4 != (undefined *)0x0) break;
      ppuVar4 = ppuVar4 + 1;
    }
  } while( true );
}


