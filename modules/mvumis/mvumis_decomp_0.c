
===== MV_PRINT @ 00011000 =====

void MV_PRINT(char *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res10;
  undefined8 local_res18;
  undefined8 local_res20;
  
  local_res10 = param_2;
  local_res18 = param_3;
  local_res20 = param_4;
  vsprintf_s(&DAT_00017060,0x400,param_1,(va_list)&local_res10);
  DbgPrintEx(0x65,0,&DAT_00017060);
  return;
}



===== Tag_GetOne @ 00011048 =====

undefined2 Tag_GetOne(longlong *param_1)

{
  undefined2 uVar1;
  ushort uVar2;
  
  if (*(char *)((longlong)param_1 + 0xe) != '\x01') {
    *(short *)(param_1 + 1) = (short)param_1[1] + -1;
    return *(undefined2 *)(*param_1 + (ulonglong)*(ushort *)(param_1 + 1) * 2);
  }
  uVar1 = *(undefined2 *)(*param_1 + (ulonglong)*(ushort *)((longlong)param_1 + 0xc) * 2);
  uVar2 = *(ushort *)((longlong)param_1 + 0xc) + 1;
  *(ushort *)((longlong)param_1 + 0xc) = uVar2;
  if (*(ushort *)((longlong)param_1 + 10) <= uVar2) {
    *(undefined2 *)((longlong)param_1 + 0xc) = 0;
  }
  *(short *)(param_1 + 1) = (short)param_1[1] + -1;
  return uVar1;
}



===== sgdt_clear_eot @ 00011094 =====

void sgdt_clear_eot(longlong param_1)

{
  longlong lVar1;
  
  if (*(byte *)(param_1 + 1) != 0) {
    lVar1 = *(longlong *)(param_1 + 8) + -0x10 + (ulonglong)*(byte *)(param_1 + 1) * 0x10;
    if ((*(uint *)(lVar1 + 8) & 0x1000000) != 0) {
      lVar1 = lVar1 + -0x10;
    }
    *(uint *)(lVar1 + 8) = *(uint *)(lVar1 + 8) & 0xf7ffffff;
  }
  return;
}



===== mu_initialize @ 000110c0 =====

void mu_initialize(longlong param_1,undefined8 *param_2,undefined8 param_3,ushort param_4)

{
  longlong *plVar1;
  undefined8 *puVar2;
  undefined8 *_Dst;
  void *_Dst_00;
  int iVar3;
  uint uVar4;
  ulonglong uVar5;
  longlong *plVar6;
  longlong lVar7;
  longlong lVar8;
  longlong lVar9;
  short sVar10;
  
  _Dst = *(undefined8 **)(param_1 + 0x178);
  memset(_Dst,0,0xc0);
  uVar4 = *(uint *)(param_2 + 2);
  *_Dst = param_3;
  _Dst_00 = (void *)*param_2;
  *(uint *)(_Dst + 0x12) = (uint)param_4;
  lVar7 = param_2[1];
  _Dst[1] = param_1;
  *(undefined4 *)(_Dst + 10) = 0x400400;
  *(undefined2 *)(_Dst + 8) = 0x408;
  *(undefined1 *)((longlong)_Dst + 0x43) = 0xff;
  *(undefined8 *)((longlong)_Dst + 0x44) = 0;
  memset(_Dst_00,0,(ulonglong)uVar4);
  plVar1 = _Dst + 0x13;
  _Dst[0x14] = plVar1;
  *plVar1 = (longlong)plVar1;
  plVar6 = _Dst + 0x18;
  for (sVar10 = *(short *)(param_1 + 0xa2); sVar10 != 0; sVar10 = sVar10 + -1) {
    lVar9 = *plVar1;
    *plVar1 = (longlong)plVar6;
    plVar6[1] = (longlong)plVar1;
    *plVar6 = lVar9;
    *(longlong **)(lVar9 + 8) = plVar6;
    plVar6 = plVar6 + 10;
  }
  puVar2 = _Dst + 0x15;
  _Dst[0x16] = puVar2;
  *puVar2 = puVar2;
  iVar3 = (int)lVar7;
  uVar5 = (ulonglong)((iVar3 + 0x7fU & 0xffffff80) - iVar3);
  lVar7 = lVar7 + uVar5;
  lVar9 = (longlong)_Dst_00 + uVar5;
  _Dst[2] = lVar9;
  _Dst[0xb] = lVar7;
  lVar9 = lVar9 + (int)((uint)param_4 << 10);
  lVar7 = lVar7 + (int)((uint)param_4 << 10);
  if ((*(byte *)(param_1 + 0xaa) & 8) != 0) {
    lVar9 = lVar9 + 0x400;
    lVar7 = lVar7 + 0x400;
  }
  uVar5 = (ulonglong)(((int)lVar7 + 7U & 0xfffffff8) - (int)lVar7);
  lVar7 = lVar7 + uVar5;
  lVar9 = lVar9 + uVar5;
  _Dst[5] = lVar9;
  _Dst[0xd] = lVar7;
  lVar9 = lVar9 + 4;
  lVar8 = lVar7 + 4;
  if (*(short *)(_Dst[1] + 0xb6) == -0x7b80) {
    uVar5 = (ulonglong)(((int)lVar7 + 7U & 0xfffffffc) - (int)lVar8);
    lVar8 = lVar8 + uVar5;
    lVar9 = lVar9 + uVar5;
    _Dst[0xe] = lVar8;
    lVar8 = lVar8 + 4;
    _Dst[6] = lVar9;
    lVar9 = lVar9 + 4;
  }
  else {
    uVar5 = (ulonglong)(((int)lVar7 + 0xbU & 0xfffffff8) - (int)lVar8);
    lVar8 = lVar8 + uVar5;
    lVar9 = lVar9 + uVar5;
    _Dst[0xe] = lVar8;
    lVar8 = lVar8 + 8;
    _Dst[6] = lVar9;
    lVar9 = lVar9 + 8;
  }
  uVar5 = (ulonglong)(((int)lVar8 + 0x7fU & 0xffffff80) - (int)lVar8);
  lVar8 = lVar8 + uVar5;
  lVar9 = lVar9 + uVar5;
  _Dst[0xc] = lVar8;
  _Dst[3] = lVar9;
  lVar8 = lVar8 + (int)((uint)param_4 * 0x40 + 4);
  lVar9 = (longlong)(int)((uint)param_4 * 0x40) + 4 + lVar9;
  if ((*(byte *)(param_1 + 0xaa) & 8) != 0) {
    lVar9 = lVar9 + 0x40;
    lVar8 = lVar8 + 0x40;
  }
  uVar4 = ((int)lVar8 + 7U & 0xfffffff8) - (int)lVar8;
  _Dst[7] = (ulonglong)uVar4 + lVar9;
  _Dst[0xf] = (ulonglong)uVar4 + lVar8;
  return;
}



===== mu_hs_build_page @ 000112bc =====

void mu_hs_build_page(longlong param_1,char *param_2)

{
  char cVar1;
  uint uVar2;
  longlong lVar3;
  code *pcVar4;
  uint uVar5;
  int iVar6;
  ulonglong uVar7;
  byte bVar8;
  byte bVar9;
  byte *pbVar10;
  
  lVar3 = *(longlong *)(param_1 + 8);
  cVar1 = *param_2;
  if (cVar1 == '\x02') {
    pbVar10 = (byte *)(param_2 + 4);
    param_2[2] = ',';
    param_2[3] = '\0';
    memset(pbVar10,0,0x2c);
    bVar9 = 0;
    *pbVar10 = 2;
    param_2[0x1c] = '\0';
    param_2[0x1d] = '\0';
    param_2[0x1e] = '\0';
    param_2[0x1f] = '\0';
    param_2[0x20] = '\0';
    param_2[0x21] = '\0';
    param_2[0x22] = '\0';
    param_2[0x23] = '\0';
    param_2[0x24] = '\0';
    param_2[0x25] = '\0';
    param_2[0x26] = '\0';
    param_2[0x27] = '\0';
    param_2[8] = '\x01';
    param_2[9] = '\0';
    param_2[10] = '\0';
    param_2[0xb] = '\0';
    param_2[0xc] = '\0';
    param_2[0xd] = '\0';
    param_2[0xe] = '\0';
    param_2[0xf] = '\0';
    param_2[0x10] = '\x05';
    param_2[0x11] = '\0';
    param_2[0x12] = '\0';
    param_2[0x13] = '\0';
    param_2[0x14] = -8;
    param_2[0x15] = '\x03';
    param_2[0x16] = '\0';
    param_2[0x17] = '\0';
    param_2[0x18] = '\0';
    param_2[0x19] = '\0';
    param_2[0x1a] = '\0';
    param_2[0x1b] = '\0';
    uVar7 = hba_get_time_in_second();
    bVar8 = 0;
    *(ulonglong *)(param_2 + 0x28) = uVar7 & 0xffffffff;
    if (*(ushort *)(param_2 + 2) != 0) {
      do {
        bVar9 = bVar9 ^ *pbVar10;
        bVar8 = bVar8 + 1;
        pbVar10 = pbVar10 + 1;
      } while ((ushort)bVar8 < *(ushort *)(param_2 + 2));
    }
  }
  else if (cVar1 == '\x03') {
    pbVar10 = (byte *)(param_2 + 4);
    bVar9 = 0;
    param_2[2] = '\x14';
    param_2[3] = '\0';
    bVar8 = 0;
    pbVar10[0] = 0;
    pbVar10[1] = 0;
    pbVar10[2] = 0;
    pbVar10[3] = 0;
    pbVar10[4] = 0;
    pbVar10[5] = 0;
    pbVar10[6] = 0;
    pbVar10[7] = 0;
    param_2[0xc] = '\0';
    param_2[0xd] = '\0';
    param_2[0xe] = '\0';
    param_2[0xf] = '\0';
    param_2[0x10] = '\0';
    param_2[0x11] = '\0';
    param_2[0x12] = '\0';
    param_2[0x13] = '\0';
    param_2[0x14] = '\0';
    param_2[0x15] = '\0';
    param_2[0x16] = '\0';
    param_2[0x17] = '\0';
    if (*(ushort *)(param_2 + 2) != 0) {
      do {
        bVar9 = bVar9 ^ *pbVar10;
        bVar8 = bVar8 + 1;
        pbVar10 = pbVar10 + 1;
      } while ((ushort)bVar8 < *(ushort *)(param_2 + 2));
    }
  }
  else {
    if (cVar1 != '\x04') {
      return;
    }
    pbVar10 = (byte *)(param_2 + 4);
    param_2[2] = '\x14';
    param_2[3] = '\0';
    pbVar10[0] = 0;
    pbVar10[1] = 0;
    pbVar10[2] = 0;
    pbVar10[3] = 0;
    pbVar10[4] = 0;
    pbVar10[5] = 0;
    pbVar10[6] = 0;
    pbVar10[7] = 0;
    param_2[0xc] = '\0';
    param_2[0xd] = '\0';
    param_2[0xe] = '\0';
    param_2[0xf] = '\0';
    param_2[0x10] = '\0';
    param_2[0x11] = '\0';
    param_2[0x12] = '\0';
    param_2[0x13] = '\0';
    param_2[0x14] = '\0';
    param_2[0x15] = '\0';
    param_2[0x16] = '\0';
    param_2[0x17] = '\0';
    *(undefined4 *)pbVar10 = *(undefined4 *)(param_1 + 0x58);
    iVar6 = *(int *)(param_1 + 0x60);
    if (*(short *)(*(longlong *)(param_1 + 8) + 0xb6) == -0x7b80) {
      iVar6 = iVar6 + -4;
    }
    *(int *)(param_2 + 0xc) = iVar6;
    *(undefined4 *)(param_2 + 8) = *(undefined4 *)(param_1 + 0x5c);
    bVar9 = 0;
    *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(param_1 + 100);
    param_2[0x14] = *(char *)(param_1 + 0x40);
    param_2[0x15] = *(char *)(param_1 + 0x41);
    if ((*(ushort *)(lVar3 + 0xaa) & 0x4000) == 0) {
      param_2[0x16] = *(char *)(param_1 + 0x90);
      param_2[0x17] = *(char *)(param_1 + 0x90);
    }
    else {
      uVar2 = *(uint *)(param_1 + 0x90);
      bVar8 = 0;
      uVar5 = uVar2;
      if (uVar2 == 0) {
        pcVar4 = (code *)swi(3);
        (*pcVar4)();
        return;
      }
      while (uVar5 != 1) {
        bVar8 = bVar8 + 1;
        uVar5 = uVar2 >> (bVar8 & 0x1f);
      }
      if (1 << (bVar8 & 0x1f) != uVar2) {
        pcVar4 = (code *)swi(3);
        (*pcVar4)();
        return;
      }
      param_2[0x16] = bVar8;
      uVar2 = *(uint *)(param_1 + 0x90);
      bVar8 = 0;
      uVar5 = uVar2;
      if (uVar2 == 0) {
        pcVar4 = (code *)swi(3);
        (*pcVar4)();
        return;
      }
      while (uVar5 != 1) {
        bVar8 = bVar8 + 1;
        uVar5 = uVar2 >> (bVar8 & 0x1f);
      }
      if (1 << (bVar8 & 0x1f) != uVar2) {
        pcVar4 = (code *)swi(3);
        (*pcVar4)();
        return;
      }
      param_2[0x17] = bVar8;
    }
    bVar8 = 0;
    if (*(ushort *)(param_2 + 2) != 0) {
      do {
        bVar9 = bVar9 ^ *pbVar10;
        bVar8 = bVar8 + 1;
        pbVar10 = pbVar10 + 1;
      } while ((ushort)bVar8 < *(ushort *)(param_2 + 2));
    }
  }
  param_2[1] = bVar9;
  return;
}



===== mu_hs_process_page @ 000114a4 =====

ulonglong mu_hs_process_page(longlong param_1,char *param_2)

{
  longlong lVar1;
  uint uVar2;
  ulonglong in_RAX;
  ulonglong uVar3;
  byte bVar4;
  byte *pbVar5;
  byte bVar6;
  
  lVar1 = *(longlong *)(param_1 + 8);
  bVar4 = 0;
  pbVar5 = (byte *)(param_2 + 4);
  bVar6 = 0;
  if (*(ushort *)(param_2 + 2) != 0) {
    do {
      bVar4 = bVar4 ^ *pbVar5;
      bVar6 = bVar6 + 1;
      pbVar5 = pbVar5 + 1;
      in_RAX = 0;
    } while ((ushort)bVar6 < *(ushort *)(param_2 + 2));
  }
  if ((bVar4 == param_2[1]) && (*param_2 == '\x01')) {
    if ((*(ushort *)(param_2 + 0x24) & 0x4000) == 0) {
      uVar2 = (uint)(byte)param_2[0x22];
    }
    else {
      uVar2 = 1 << (param_2[0x22] & 0x1fU);
    }
    if (uVar2 < *(uint *)(param_1 + 0x90)) {
      *(uint *)(param_1 + 0x90) = uVar2;
    }
    if ((byte)param_2[0x20] < 8) {
      *(char *)(param_1 + 0x40) = param_2[0x20];
      *(short *)(param_1 + 0x50) = (1 << (param_2[0x20] & 0x1fU)) << 2;
    }
    if ((byte)param_2[0x21] < 4) {
      *(char *)(param_1 + 0x41) = param_2[0x21];
      *(short *)(param_1 + 0x52) = (1 << (param_2[0x21] & 0x1fU)) << 2;
    }
    if (*(uint *)(param_2 + 0xc) < g_max_transfersize) {
      *(uint *)(lVar1 + 0xa4) = *(uint *)(param_2 + 0xc);
    }
    if (*(ushort *)(param_2 + 6) < 0x80) {
      *(ushort *)(lVar1 + 0xa8) = *(ushort *)(param_2 + 6);
    }
    if (*(ushort *)(param_2 + 8) < *(ushort *)(lVar1 + 0xa2)) {
      *(ushort *)(lVar1 + 0xa2) = *(ushort *)(param_2 + 8);
    }
    uVar2 = *(ushort *)(lVar1 + 0xb6) + 0x6ebe;
    if ((((uVar2 & 0xfffc) == 0) && (*(ushort *)(lVar1 + 0xb6) != 0x9144)) &&
       (0x7e1 < *(uint *)(param_2 + 0x1c))) {
      *(undefined1 *)(lVar1 + 0x9e) = 1;
    }
    uVar3 = CONCAT71((uint7)(uint3)(uVar2 >> 8),1);
    *(undefined2 *)(lVar1 + 0xaa) = *(undefined2 *)(param_2 + 0x24);
  }
  else {
    uVar3 = in_RAX & 0xffffffffffffff00;
  }
  return uVar3;
}



===== mu_handshake @ 000115dc =====

void mu_handshake(longlong *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  short sVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  int *piVar5;
  undefined8 *puVar6;
  longlong lVar7;
  uint uVar8;
  ulonglong uVar9;
  byte *pbVar10;
  uint uVar11;
  byte bVar12;
  uint uVar13;
  ulonglong uVar14;
  
  lVar3 = param_1[1];
  uVar11 = 0;
  if (*(int *)((longlong)param_1 + 0x94) != 1) {
    if ((((*(short *)(lVar3 + 0xb6) + 0x6ebeU & 0xfffc) == 0) &&
        (*(short *)(lVar3 + 0xb6) != -0x6ebc)) && (*(char *)(lVar3 + 0xb8) == '\0')) {
      StorPortStallExecution(10);
    }
    uVar8 = *(uint *)((ulonglong)*(uint *)(lVar3 + 0x1b8) + *param_1);
    uVar13 = uVar8 & 0xffff;
    if ((uVar8 & 0xffff0000) != 0x10000) {
      *(undefined4 *)((longlong)param_1 + 0x94) = 1;
      return;
    }
    if (uVar13 != 1) {
      if (uVar13 == 2) {
        iVar2 = (int)param_1[0xb];
        if (((param_1[0xb] + 0x80U ^ param_1[0xb]) >> 0x13 & 1) == 0) {
          lVar4 = *param_1;
          param_1[4] = param_1[2];
          uVar11 = *(uint *)(lVar3 + 0x1b4);
          do {
            *(int *)((ulonglong)uVar11 + lVar4) = iVar2;
            LOCK();
            UNLOCK();
          } while (*(int *)((ulonglong)uVar11 + lVar4) != iVar2);
        }
        else {
          lVar4 = *param_1;
          param_1[4] = param_1[2] + 0x80;
          uVar11 = *(uint *)(lVar3 + 0x1b4);
          do {
            *(int *)((ulonglong)uVar11 + lVar4) = iVar2 + 0x80;
            LOCK();
            UNLOCK();
          } while (*(int *)((ulonglong)uVar11 + lVar4) != iVar2 + 0x80);
        }
        iVar2 = *(int *)((longlong)param_1 + 0x5c);
        uVar11 = *(uint *)(lVar3 + 0x1bc);
        lVar4 = *param_1;
        do {
          *(int *)((ulonglong)uVar11 + lVar4) = iVar2;
          LOCK();
          UNLOCK();
        } while (*(int *)((ulonglong)uVar11 + lVar4) != iVar2);
        uVar11 = *(uint *)(lVar3 + 0x1b0);
        lVar4 = *param_1;
        do {
          *(undefined4 *)((ulonglong)uVar11 + lVar4) = 0x10003;
          LOCK();
          UNLOCK();
        } while (*(int *)((ulonglong)uVar11 + lVar4) != 0x10003);
      }
      else {
        if (uVar13 < 3) {
          return;
        }
        uVar8 = 5;
        if (5 < uVar13) {
          if (uVar13 != 6) {
            return;
          }
          *(undefined4 *)((longlong)param_1 + 0x94) = 3;
          *(uint *)(lVar3 + 0x5c) = *(uint *)(lVar3 + 0x5c) | *(uint *)(lVar3 + 0x1f0) | 0x40;
          uVar8 = *(uint *)(lVar3 + 0x184);
          lVar4 = *param_1;
          uVar13 = *(uint *)((ulonglong)*(uint *)(lVar3 + 0x184) + *param_1) |
                   *(uint *)(lVar3 + 0x1f0) | 0x40;
          do {
            *(uint *)((ulonglong)uVar8 + lVar4) = uVar13;
            LOCK();
            UNLOCK();
          } while (*(uint *)((ulonglong)uVar8 + lVar4) != uVar13);
          lVar4 = param_1[0x12];
          piVar5 = (int *)param_1[5];
          do {
            *piVar5 = (int)lVar4;
            LOCK();
            UNLOCK();
          } while (*piVar5 != (int)lVar4);
          lVar7 = param_1[0xd];
          uVar8 = *(uint *)(lVar3 + 0x1c0);
          lVar4 = *param_1;
          do {
            *(int *)((ulonglong)uVar8 + lVar4) = (int)lVar7;
            LOCK();
            UNLOCK();
          } while (*(int *)((ulonglong)uVar8 + lVar4) != (int)lVar7);
          iVar2 = *(int *)((longlong)param_1 + 0x6c);
          uVar14 = (ulonglong)*(uint *)(lVar3 + 0x1c4);
          lVar4 = *param_1;
          do {
            *(int *)(uVar14 + lVar4) = iVar2;
            LOCK();
            UNLOCK();
          } while (*(int *)(uVar14 + lVar4) != iVar2);
          sVar1 = *(short *)(param_1[1] + 0xb6);
          if (((((ushort)(sVar1 + 0x6ebeU) < 2) || (sVar1 == -0x6ebb)) ||
              ((sVar1 == -0x6b80 || ((sVar1 == -0x6a80 || (sVar1 == -0x6a78)))))) ||
             (sVar1 == -0x6ab8)) {
            *(uint *)param_1[6] = (int)param_1[0x12] - 1U | *(uint *)(lVar3 + 0x1fc);
            LOCK();
            UNLOCK();
            *(int *)((ulonglong)*(uint *)(lVar3 + 0x1d0) + *param_1) = (int)param_1[0xe];
            LOCK();
            UNLOCK();
            *(undefined4 *)((ulonglong)*(uint *)(lVar3 + 0x1d4) + *param_1) =
                 *(undefined4 *)((longlong)param_1 + 0x74);
            LOCK();
            UNLOCK();
          }
          uVar8 = *(uint *)(param_1 + 0x12);
          uVar9 = (ulonglong)uVar8;
          *(uint *)(param_1 + 0x10) = *(uint *)(lVar3 + 0x1fc) | uVar8 - 1;
          *(uint *)(param_1 + 0x11) = *(uint *)(lVar3 + 0x1fc) | uVar8 - 1;
          if ((*(byte *)(param_1[1] + 0xaa) & 8) != 0) {
            *(undefined4 *)(param_1 + 0x17) = 0;
          }
          if (uVar8 != 0) {
            do {
              uVar9 = 0xff5a;
              uVar8 = *(ushort *)((longlong)param_1 + 0x52) * uVar11;
              uVar11 = uVar11 + 1;
              *(undefined2 *)((ulonglong)uVar8 + 2 + param_1[3]) = 0xff5a;
            } while (uVar11 < *(uint *)(param_1 + 0x12));
          }
          puVar6 = (undefined8 *)param_1[1];
          *(undefined4 *)(puVar6 + 0x13) = 3;
          hba_handle_waiting_list(puVar6,uVar9,uVar14,param_4);
          return;
        }
        pbVar10 = (byte *)param_1[4];
        if (*pbVar10 == 1) {
          bVar12 = pbVar10[0x23];
          if (pbVar10[0x23] == 0) {
            bVar12 = 4;
          }
          *(byte *)((longlong)param_1 + 0x42) = bVar12;
        }
        if (uVar13 == 4) {
          mu_hs_process_page((longlong)param_1,(char *)pbVar10);
        }
        else if (uVar13 == 3) {
          *pbVar10 = 0;
          *(undefined1 *)((longlong)param_1 + 0x42) = 4;
        }
        if ((uint)*(byte *)((longlong)param_1 + 0x42) < *pbVar10 + 1) {
          uVar8 = 6;
        }
        else {
          bVar12 = *pbVar10 + 1;
          *pbVar10 = bVar12;
          if (bVar12 == 1) {
            uVar8 = 4;
          }
          else {
            mu_hs_build_page((longlong)param_1,(char *)pbVar10);
          }
        }
        uVar11 = *(uint *)(lVar3 + 0x1b0);
        lVar4 = *param_1;
        do {
          *(uint *)((ulonglong)uVar11 + lVar4) = uVar8 | 0x10000;
          LOCK();
          UNLOCK();
        } while (*(uint *)((ulonglong)uVar11 + lVar4) != (uVar8 | 0x10000));
      }
      goto LAB_000119a4;
    }
  }
  lVar4 = *param_1;
  *(undefined4 *)((longlong)param_1 + 0x94) = 2;
  uVar11 = *(uint *)(lVar3 + 0x1b4);
  do {
    *(undefined4 *)((ulonglong)uVar11 + lVar4) = 0x5a5a5a5a;
    LOCK();
    UNLOCK();
  } while (*(int *)((ulonglong)uVar11 + lVar4) != 0x5a5a5a5a);
  uVar11 = *(uint *)(lVar3 + 0x1b0);
  lVar4 = *param_1;
  do {
    *(undefined4 *)((ulonglong)uVar11 + lVar4) = 0x10002;
    LOCK();
    UNLOCK();
  } while (*(int *)((ulonglong)uVar11 + lVar4) != 0x10002);
LAB_000119a4:
  *(undefined4 *)((ulonglong)*(uint *)(lVar3 + 0x1a4) + *param_1) = 1;
  LOCK();
  UNLOCK();
  return;
}



===== mu_check_handshake @ 000119d0 =====

ulonglong mu_check_handshake(undefined8 *param_1,undefined8 param_2,undefined8 param_3,
                            undefined8 param_4)

{
  ushort uVar1;
  int iVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined2 uVar5;
  uint uVar6;
  ulonglong uVar7;
  longlong *plVar8;
  undefined8 uVar9;
  
  plVar8 = (longlong *)param_1[0x2f];
  if (*(int *)((longlong)plVar8 + 0x94) == 4) {
    uVar7 = 1;
  }
  else {
    iVar2 = *(int *)((ulonglong)*(uint *)((longlong)param_1 + 0x1bc) + *plVar8);
    if ((iVar2 == 0x55aa5aa5) || (iVar2 == 0x55aaa55a)) {
      *(undefined4 *)((longlong)plVar8 + 0x94) = 1;
      uVar9 = mu_handshake(plVar8,plVar8,param_3,param_4);
      uVar7 = CONCAT71((int7)((ulonglong)uVar9 >> 8),1);
    }
    else {
      *(undefined4 *)((ulonglong)*(uint *)((longlong)param_1 + 0x1a4) + *plVar8) = 0x10;
      LOCK();
      UNLOCK();
      uVar1 = *(ushort *)((longlong)plVar8 + 0x4c);
      uVar9 = 0xf0;
      uVar6 = uVar1 + 1;
      uVar7 = (ulonglong)uVar6;
      *(short *)((longlong)plVar8 + 0x4c) = (short)uVar6;
      if (uVar1 < 0xf0) {
        if (*(short *)(param_1 + 0x1c) != 0) {
          uVar5 = Tag_GetOne(param_1 + 0x1b);
          lVar3 = *(longlong *)(param_1[0x19] + (ulonglong)(byte)uVar5 * 8);
          *(code **)(lVar3 + 0x28) = mu_check_handshake;
          *(undefined1 *)(lVar3 + 0x30) = 1;
          *(undefined8 **)(lVar3 + 0x10) = param_1;
          *(undefined8 *)(lVar3 + 0x18) = 0;
          uVar7 = param_1[0x1d] + 500;
          *(ulonglong *)(lVar3 + 0x38) = uVar7;
        }
      }
      else {
        uVar7 = param_1[0x2f];
        *(undefined4 *)(uVar7 + 0x94) = 4;
        *(undefined4 *)(param_1 + 0x13) = 4;
        while ((longlong *)param_1[0x24] != param_1 + 0x23) {
          plVar8 = (longlong *)param_1[0x24];
          if (plVar8 == param_1 + 0x23) {
            plVar8 = (longlong *)0x0;
          }
          else {
            plVar4 = (longlong *)plVar8[1];
            lVar3 = *plVar8;
            *plVar4 = lVar3;
            *(longlong **)(lVar3 + 8) = plVar4;
            plVar8[1] = 0;
            *plVar8 = 0;
          }
          lVar3 = plVar8[3];
          *(undefined1 *)(lVar3 + 4) = 4;
          uVar7 = hba_request_callback(param_1,lVar3,uVar9,param_4);
        }
      }
      uVar7 = uVar7 & 0xffffffffffffff00;
    }
  }
  return uVar7;
}



===== mu_send_getevent_reqest @ 00011b28 =====

ulonglong mu_send_getevent_reqest
                    (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 *puVar1;
  ulonglong uVar2;
  ulonglong *puVar3;
  ulonglong in_RAX;
  undefined8 uVar4;
  ulonglong *puVar5;
  
  puVar1 = *(undefined8 **)(param_1 + 8);
  if (*(int *)(param_1 + 0x94) == 3) {
    if (((ulonglong *)puVar1[0x43] == puVar1 + 0x42) ||
       (puVar5 = (ulonglong *)puVar1[0x43], puVar5 == puVar1 + 0x42)) {
      puVar5 = (ulonglong *)0x0;
    }
    else {
      uVar2 = *puVar5;
      puVar3 = (ulonglong *)puVar5[1];
      *puVar3 = uVar2;
      *(ulonglong **)(uVar2 + 8) = puVar3;
      puVar5[1] = 0;
      *puVar5 = 0;
    }
    in_RAX = 0;
    if (puVar5 != (ulonglong *)0x0) {
      *(undefined4 *)((longlong)puVar5 + 0x3d) = 0x184;
      *(undefined2 *)((longlong)puVar5 + 0x35) = 0;
      *(undefined4 *)((longlong)puVar5 + 0x39) = 0x1100108;
      *(undefined8 *)((longlong)puVar5 + 0x45) = 0;
      *(undefined8 *)((longlong)puVar5 + 0x4d) = 0;
      *(undefined2 *)((longlong)puVar5 + 0x45) = 0xf4;
      *(undefined4 *)((longlong)puVar5 + 0x61) = *(undefined4 *)((longlong)puVar5 + 0x3d);
      memset((void *)puVar5[5],0,0x200);
      puVar3 = puVar1 + 0x23;
      uVar2 = *puVar3;
      *puVar3 = (ulonglong)puVar5;
      puVar5[1] = (ulonglong)puVar3;
      *puVar5 = uVar2;
      *(ulonglong **)(uVar2 + 8) = puVar5;
      uVar4 = hba_handle_waiting_list(puVar1,puVar3,uVar2,param_4);
      return CONCAT71((int7)((ulonglong)uVar4 >> 8),1);
    }
  }
  return in_RAX & 0xffffffffffffff00;
}



===== mu_get_inb_list_entry @ 00011be4 =====

ulonglong mu_get_inb_list_entry(longlong *param_1,longlong *param_2)

{
  byte bVar1;
  ushort uVar2;
  uint uVar3;
  longlong lVar4;
  longlong lVar5;
  uint uVar6;
  uint *puVar7;
  uint uVar8;
  
  lVar4 = param_1[1];
  uVar2 = *(ushort *)(lVar4 + 0xb6);
  puVar7 = (uint *)(ulonglong)uVar2;
  if ((((uVar2 == 0x8180) || (uVar2 == 0x9480)) || (uVar2 == 0x9580)) ||
     ((uVar2 == 0x9588 || (uVar2 == 0x9548)))) {
    uVar6 = *(uint *)(param_1 + 0x12);
    if (uVar6 <= *(uint *)((longlong)param_1 + 0x84)) {
      puVar7 = (uint *)param_1[5];
      uVar6 = *(uint *)(param_1 + 0x12);
      if (*puVar7 != uVar6) goto LAB_00011c86;
      *(undefined4 *)((longlong)param_1 + 0x84) = 0;
    }
    if (param_2 == (longlong *)0x0) {
      return CONCAT71((int7)((ulonglong)puVar7 >> 8),
                      (char)uVar6 - (char)*(undefined4 *)((longlong)param_1 + 0x84));
    }
    *(int *)((longlong)param_1 + 0x84) = *(int *)((longlong)param_1 + 0x84) + 1;
    if (uVar6 <= *(uint *)((longlong)param_1 + 0x84)) {
      *(undefined4 *)param_1[5] = 0xfff;
      LOCK();
      UNLOCK();
    }
  }
  else {
    uVar6 = *(uint *)((ulonglong)*(uint *)(lVar4 + 0x1cc) + *param_1);
    if (((*(uint *)(lVar4 + 0x200) & uVar6) ==
         (*(uint *)(param_1 + 0x10) & *(uint *)(lVar4 + 0x200))) &&
       (uVar6 = *(uint *)(lVar4 + 0x1fc) & uVar6, puVar7 = (uint *)(ulonglong)uVar6,
       uVar6 != (*(uint *)(param_1 + 0x10) & *(uint *)(lVar4 + 0x1fc)))) {
LAB_00011c86:
      return (ulonglong)puVar7 & 0xffffffffffffff00;
    }
  }
  uVar6 = *(uint *)(param_1 + 0x12);
  uVar8 = (*(uint *)(lVar4 + 0x200) & *(uint *)(param_1 + 0x10)) + 1;
  if (uVar6 <= uVar8) {
    uVar8 = uVar8 - uVar6;
    *(uint *)(param_1 + 0x10) = *(uint *)(lVar4 + 0x1fc) ^ *(uint *)(param_1 + 0x10);
  }
  lVar5 = param_1[2];
  *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) & ~*(uint *)(lVar4 + 0x200);
  uVar3 = *(uint *)(lVar4 + 0x200);
  uVar2 = *(ushort *)(param_1 + 10);
  lVar4 = param_1[1];
  *(int *)((longlong)param_1 + 0x8c) = *(int *)((longlong)param_1 + 0x8c) + 1;
  *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | uVar3 & uVar8;
  bVar1 = *(byte *)(lVar4 + 0xaa);
  *param_2 = (ulonglong)(uVar2 * uVar8) + lVar5;
  if ((bVar1 & 8) != 0) {
    if ((uVar8 == 0) && ((*(uint *)(param_1 + 0x17) & 1) != 0)) {
      *param_2 = (ulonglong)(uVar2 * uVar6) + lVar5;
    }
    *(uint *)(param_1 + 0x17) = *(uint *)(param_1 + 0x17) | 1;
  }
  return CONCAT71((int7)((ulonglong)lVar4 >> 8),1);
}



===== mu_receive_outb_list_entry @ 00011d70 =====

ulonglong mu_receive_outb_list_entry(undefined8 *param_1)

{
  int iVar1;
  uint uVar2;
  longlong lVar3;
  longlong *plVar4;
  longlong lVar5;
  uint uVar6;
  longlong *plVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  void *_Src;
  
  lVar3 = param_1[1];
  plVar7 = (longlong *)
           (ulonglong)*(uint *)((ulonglong)*(uint *)(lVar3 + 0x1ec) + *(longlong *)(lVar3 + 0x170));
  iVar1 = *(int *)(param_1 + 0x12);
  uVar9 = *(uint *)(param_1 + 0x11) & *(uint *)(lVar3 + 0x200);
  iVar10 = iVar1;
  if (iVar1 != 0) {
    do {
      uVar2 = *(uint *)(param_1 + 0x12);
      uVar8 = uVar9 + 1;
      if (uVar2 <= uVar8) {
        uVar8 = uVar8 - uVar2;
      }
      uVar6 = uVar8;
      if ((*(byte *)(param_1[1] + 0xaa) & 8) != 0) {
        if ((uVar8 == 0) && ((*(byte *)(param_1 + 0x17) & 2) != 0)) {
          uVar6 = uVar2;
        }
        *(uint *)(param_1 + 0x17) = *(uint *)(param_1 + 0x17) | 2;
      }
      uVar6 = *(ushort *)((longlong)param_1 + 0x52) * uVar6;
      plVar7 = (longlong *)(ulonglong)uVar6;
      _Src = (void *)((ulonglong)uVar6 + param_1[3]);
      if (*(short *)((longlong)_Src + 2) == -0xa6) break;
      plVar7 = param_1 + 0x13;
      plVar4 = (longlong *)param_1[0x14];
      if (plVar4 == plVar7) break;
      plVar7 = (longlong *)plVar4[1];
      lVar5 = *plVar4;
      *plVar7 = lVar5;
      *(longlong **)(lVar5 + 8) = plVar7;
      plVar4[1] = 0;
      *plVar4 = 0;
      memcpy(plVar4 + 2,_Src,(ulonglong)*(ushort *)((longlong)param_1 + 0x52));
      plVar7 = param_1 + 0x15;
      *(undefined2 *)((longlong)_Src + 2) = 0xff5a;
      lVar5 = *plVar7;
      *plVar7 = (longlong)plVar4;
      plVar4[1] = (longlong)plVar7;
      *plVar4 = lVar5;
      *(longlong **)(lVar5 + 8) = plVar4;
      if (uVar8 < uVar9) {
        plVar7 = (longlong *)(ulonglong)*(uint *)(lVar3 + 0x1fc);
        *(uint *)(param_1 + 0x11) = *(uint *)(param_1 + 0x11) ^ *(uint *)(lVar3 + 0x1fc);
      }
      iVar10 = iVar10 + -1;
      uVar9 = uVar8;
    } while (iVar10 != 0);
    if (iVar10 != iVar1) {
      *(uint *)(param_1 + 0x11) = *(uint *)(param_1 + 0x11) & *(uint *)(lVar3 + 0x1fc);
      plVar7 = (longlong *)*param_1;
      uVar9 = uVar9 & *(uint *)(lVar3 + 0x200) | *(uint *)(param_1 + 0x11);
      *(uint *)(param_1 + 0x11) = uVar9;
      *(uint *)((ulonglong)*(uint *)(lVar3 + 0x1dc) + (longlong)plVar7) = uVar9;
      LOCK();
      UNLOCK();
    }
  }
  return (ulonglong)plVar7 & 0xffffffffffffff00;
}



===== mu_handle_drbl_int @ 00011ee0 =====

void mu_handle_drbl_int(longlong *param_1,ulonglong param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  ulonglong uVar2;
  
  uVar2 = param_2;
  if ((param_2 & 1) != 0) {
    mu_handshake(param_1,param_2,param_3,param_4);
  }
  if ((param_2 & 4) != 0) {
    uVar2 = 0;
    param_3 = 2;
    hba_module_notification((undefined8 *)param_1[1],(undefined8 *)0x0,2,param_4);
  }
  if ((((param_2 & 8) != 0) && (gRunningMode != '\x01')) &&
     (uVar1 = mu_send_getevent_reqest((longlong)param_1,uVar2,param_3,param_4), (char)uVar1 == '\0')
     ) {
    return;
  }
  if (((param_2 & 0x20) != 0) && (*(int *)((longlong)param_1 + 0x94) == 3)) {
    mu_receive_outb_list_entry(param_1);
  }
  return;
}



===== mu_isr @ 00011f68 =====

undefined8 mu_isr(longlong *param_1,uint param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  longlong lVar2;
  uint *in_RAX;
  uint uVar3;
  
  lVar2 = param_1[1];
  if ((*(uint *)(lVar2 + 500) & param_2) != 0) {
    uVar3 = *(uint *)((ulonglong)*(uint *)(lVar2 + 0x1a8) + *param_1);
    uVar1 = *(uint *)(lVar2 + 0x1a8);
    *(uint *)((ulonglong)uVar1 + *param_1) = uVar3;
    LOCK();
    UNLOCK();
    in_RAX = (uint *)mu_handle_drbl_int(param_1,(ulonglong)uVar3,(ulonglong)uVar1,param_4);
  }
  if ((param_2 & 0x40) != 0) {
    in_RAX = (uint *)((ulonglong)*(uint *)(lVar2 + 0x1e4) + *param_1);
    uVar3 = (*(uint *)(lVar2 + 0x208) | 0x100) & *in_RAX;
    if (uVar3 != 0) {
      in_RAX = (uint *)*param_1;
      *(uint *)((ulonglong)*(uint *)(lVar2 + 0x1e4) + (longlong)in_RAX) = uVar3;
      LOCK();
      UNLOCK();
    }
  }
  if ((*(uint *)(lVar2 + 0x1f0) & param_2) != 0) {
    in_RAX = (uint *)((ulonglong)*(uint *)(lVar2 + 0x1e4) + *param_1);
    uVar3 = (*(uint *)(lVar2 + 0x204) | 0x10) & *in_RAX;
    if (uVar3 != 0) {
      in_RAX = (uint *)*param_1;
      *(uint *)((ulonglong)*(uint *)(lVar2 + 0x1e4) + (longlong)in_RAX) = uVar3;
      LOCK();
      UNLOCK();
    }
    if (*(int *)((longlong)param_1 + 0x94) == 3) {
      in_RAX = (uint *)mu_receive_outb_list_entry(param_1);
    }
  }
  return CONCAT71((int7)((ulonglong)in_RAX >> 8),1);
}



===== DriverEntry @ 00012030 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 DriverEntry(longlong param_1,longlong param_2,undefined1 *param_3,undefined8 param_4)

{
  undefined4 uVar1;
  ulonglong uVar2;
  char *pcVar3;
  ushort uVar4;
  undefined4 *puVar5;
  longlong lVar6;
  undefined *puVar7;
  undefined1 auStack_368 [32];
  undefined4 *local_348;
  undefined4 local_340;
  undefined4 local_338 [2];
  undefined4 *local_330;
  undefined4 local_328;
  undefined4 local_324 [3];
  undefined4 local_318;
  undefined4 local_314;
  code *local_310;
  code *local_308;
  code *local_300;
  code *local_2f8;
  code *local_2f0;
  undefined4 local_2d8;
  undefined4 local_2d4;
  undefined4 local_2d0;
  undefined4 local_2cc;
  undefined1 local_2c0;
  undefined4 local_2bf;
  code *local_2a0;
  code *local_298;
  undefined4 local_248 [128];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_368;
  local_330 = local_248;
  local_338[0] = 0x4000000;
  local_324[0] = 1;
  local_248[0] = 0;
  if (param_2 != 0) {
    RtlAppendUnicodeStringToString(local_338);
    RtlAppendUnicodeToString(local_338,L"\\Parameters");
    *(undefined4 *)((longlong)local_248 + (ulonglong)(ushort)local_338[0]) = 0;
    RtlCreateRegistryKey(0,local_330);
    RtlAppendUnicodeToString(local_338,L"\\PnpInterface");
    *(undefined4 *)((longlong)local_248 + (ulonglong)(ushort)local_338[0]) = 0;
    RtlCreateRegistryKey(0,local_330);
    *(undefined4 *)((longlong)local_248 + (ulonglong)(ushort)local_338[0]) = 0;
    param_4 = 4;
    local_348 = &local_328;
    local_340 = 4;
    param_3 = &u_5;
    local_328 = 1;
    RtlWriteRegistryValue(0,local_330);
  }
  gRunningMode = param_1 == 0;
  pcVar3 = "normal";
  uVar4 = 0x100;
  if ((bool)gRunningMode) {
    pcVar3 = "dump";
    uVar4 = 1;
  }
  _gDriverObject = param_1;
  MV_PRINT("We are running at %s mode.\n",pcVar3,param_3,param_4);
  memset(&local_318,0,0xd0);
  local_318 = 0xd0;
  local_310 = mv_hwinitialize;
  local_2bf = 0x1010101;
  local_2f0 = mv_resetbus;
  local_2c0 = 1;
  local_308 = mv_startio;
  local_300 = (code *)&mv_isr_no_dpc;
  local_314 = 5;
  if (gRunningMode != '\x01') {
    local_300 = mv_isr_dpc;
  }
  local_2cc = 6;
  local_2f8 = mv_findadapter;
  local_2a0 = mv_adaptercontrol;
  local_298 = mv_buildio;
  uVar2 = hba_module_get_resourcequota(0,uVar4);
  local_2d8 = (undefined4)uVar2;
  local_2d4 = 0xc;
  local_2d0 = 0x658;
  uVar1 = StorPortInitialize(param_1,param_2,&local_318,local_324);
  if (param_1 != 0) {
    puVar5 = &DAT_00017460;
    puVar7 = &DAT_00017468;
    lVar6 = 0x14;
    do {
      *puVar5 = 0;
      KeInitializeDpc(puVar7,FUN_00014e44,param_1);
      puVar7 = puVar7 + 0x78;
      puVar5 = puVar5 + 0x1e;
      lVar6 = lVar6 + -1;
    } while (lVar6 != 0);
  }
  return uVar1;
}



===== mv_findadapter @ 00012298 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 mv_findadapter(longlong param_1)

{
  char cVar1;
  ushort uVar2;
  ulonglong uVar3;
  longlong lVar4;
  undefined8 uVar5;
  byte bVar6;
  int iVar7;
  undefined8 uVar8;
  int iVar9;
  ushort uVar10;
  undefined1 *puVar11;
  bool bVar12;
  undefined1 local_res8 [8];
  longlong in_stack_00000028;
  undefined1 *in_stack_00000030;
  
  uVar3 = 0;
  do {
    bVar6 = (byte)uVar3;
    if ((&gHBA)[uVar3] == 0) break;
    bVar6 = bVar6 + 1;
    uVar3 = (ulonglong)bVar6;
  } while (bVar6 < 3);
  if (bVar6 < 3) {
    (&gHBA)[bVar6] = param_1;
  }
  cVar1 = gRunningMode;
  bVar12 = gRunningMode == '\x01';
  _g_cur_hba = param_1;
  *(bool *)(param_1 + 0x9c) = bVar12;
  if (bVar12) {
    bVar12 = DAT_00017030 != '\0';
    *in_stack_00000030 = 0;
    if (bVar12) {
      return 0;
    }
    DAT_00017030 = '\x01';
  }
  else {
    *in_stack_00000030 = 1;
  }
  uVar10 = 0x100;
  if (cVar1 == '\x01') {
    uVar10 = 1;
  }
  uVar2 = 2;
  if (2 < uVar10) {
    uVar2 = uVar10;
  }
  *(undefined4 *)(param_1 + 0xc0) = 0x7878764d;
  *(longlong *)param_1 = param_1;
  iVar9 = (uint)uVar2 * 0x440 + 0x6568;
  StorPortNotification(0xf,param_1,param_1 + 8);
  uVar3 = read_configuration_space(param_1,in_stack_00000028);
  if ((char)uVar3 != '\0') {
    cVar1 = *(char *)(param_1 + 0x9c);
    *(undefined1 *)(in_stack_00000028 + 0x48) = 1;
    *(undefined4 *)(in_stack_00000028 + 0x18) = 0x20000;
    g_max_transfersize = 0x20000;
    *(undefined2 *)(in_stack_00000028 + 0x51) = 0x101;
    *(undefined2 *)(in_stack_00000028 + 0x59) = 0x102;
    *(undefined1 *)(in_stack_00000028 + 0x57) = 1;
    *(undefined2 *)(in_stack_00000028 + 0x91) = 0x200;
    *(undefined2 *)(in_stack_00000028 + 0x60) = 0x8001;
    *(undefined4 *)(in_stack_00000028 + 0x30) = 3;
    *(uint *)(in_stack_00000028 + 0x1c) = (-(uint)(cVar1 != '\0') & 0xffffffee) + 0x21;
    *(undefined1 *)(in_stack_00000028 + 0x93) = 0;
    if ((char)*(byte *)(in_stack_00000028 + 0x90) < '\0') {
      *(byte *)(in_stack_00000028 + 0x90) = *(byte *)(in_stack_00000028 + 0x90) | 1;
    }
    *(undefined1 *)(in_stack_00000028 + 0x53) = 1;
    *(undefined4 *)(in_stack_00000028 + 0x94) = 1;
    *(code **)(in_stack_00000028 + 0x98) = mvHwMSInterruptRoutine;
    *(undefined4 *)(in_stack_00000028 + 0xa0) = 1;
    lVar4 = StorPortGetUncachedExtension(param_1,in_stack_00000028,iVar9);
    *(longlong *)(param_1 + 0xf0) = lVar4;
    if (lVar4 != 0) {
      puVar11 = local_res8;
      uVar8 = 0;
      uVar5 = StorPortGetPhysicalAddress(param_1);
      iVar7 = (int)((ulonglong)uVar5 >> 0x20);
      if ((iVar7 != 0) || ((int)uVar5 != 0)) {
        *(int *)(param_1 + 0xf8) = (int)uVar5;
        *(int *)(param_1 + 0xfc) = iVar7;
        *(ushort *)(param_1 + 0xa2) = uVar10;
        *(int *)(param_1 + 0x100) = iVar9;
        hba_module_initialize(param_1,uVar10);
        return 1;
      }
      MV_PRINT("ScsiPortGetPhysicalAddress get phyAddress is 0.!!!\n",uVar8,lVar4,puVar11);
    }
  }
  return 2;
}



===== read_configuration_space @ 000124bc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong read_configuration_space(longlong param_1,longlong param_2)

{
  ushort uVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  byte bVar5;
  undefined1 auStack_188 [32];
  undefined2 *local_168;
  uint local_160;
  undefined2 local_148;
  short local_146;
  undefined1 local_140;
  undefined2 local_11c;
  undefined2 local_11a;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_188;
  local_168 = &local_148;
  local_160 = 0x100;
  uVar3 = StorPortGetBusData(param_1,4,*(undefined4 *)(param_2 + 4),*(undefined4 *)(param_2 + 100));
  if ((int)uVar3 != 0) {
    *(undefined2 *)(param_1 + 0xb4) = local_148;
    *(short *)(param_1 + 0xb6) = local_146;
    *(undefined1 *)(param_1 + 0xb8) = local_140;
    *(undefined4 *)(param_1 + 0xac) = *(undefined4 *)(param_2 + 4);
    *(undefined4 *)(param_1 + 0xb0) = *(undefined4 *)(param_2 + 100);
    *(undefined2 *)(param_1 + 0xba) = local_11c;
    *(undefined2 *)(param_1 + 0xbc) = local_11a;
    if ((((((local_146 == 0x6440) || (local_146 == -0x7b80)) || (local_146 == -0x7e80)) ||
         (((local_146 == -0x7ef0 || (local_146 == -0x7ee0)) ||
          (((ushort)(local_146 + 0x6ebeU) < 2 ||
           ((uVar3 = 0x9145, local_146 == -0x6ebb || (local_146 == -0x6b80)))))))) ||
        (local_146 == -0x6a80)) || ((local_146 == -0x6a78 || (local_146 == -0x6ab8)))) {
      bVar5 = 0;
      if (*(int *)(param_2 + 0x34) != 0) {
        do {
          lVar2 = *(longlong *)(param_2 + 0x38);
          uVar3 = (ulonglong)bVar5;
          if ((*(int *)(lVar2 + uVar3 * 0x10) != 0) && (*(int *)(lVar2 + 8 + uVar3 * 0x10) != 0)) {
            *(undefined1 *)(lVar2 + 0xc + uVar3 * 0x10) = 1;
            local_160 = local_160 & 0xffffff00;
            local_168 = (undefined2 *)
                        CONCAT44(local_168._4_4_,
                                 *(undefined4 *)(*(longlong *)(param_2 + 0x38) + 8 + uVar3 * 0x10));
            uVar4 = StorPortGetDeviceBase
                              (param_1,*(undefined4 *)(param_2 + 8),*(undefined4 *)(param_2 + 4),
                               *(undefined8 *)(*(longlong *)(param_2 + 0x38) + uVar3 * 0x10));
            *(undefined8 *)(param_1 + 0x68 + uVar3 * 8) = uVar4;
          }
          bVar5 = bVar5 + 1;
        } while ((uint)bVar5 < *(uint *)(param_2 + 0x34));
      }
      uVar1 = *(ushort *)(param_1 + 0xb6);
      uVar3 = (ulonglong)uVar1;
      if ((((uVar1 == 0x9480) || (uVar1 == 0x9580)) || (uVar1 == 0x9588)) || (uVar1 == 0x9548)) {
        *(undefined4 *)(param_1 + 0x180) = 0x10200;
        *(undefined4 *)(param_1 + 0x184) = 0x1020c;
        *(undefined4 *)(param_1 + 0x188) = 0x10210;
        *(undefined4 *)(param_1 + 0x194) = 0x1010c;
        *(undefined4 *)(param_1 + 0x198) = 0x10108;
        *(undefined4 *)(param_1 + 0x19c) = 0x10130;
        *(undefined4 *)(param_1 + 0x1a0) = 0x10114;
        *(undefined4 *)(param_1 + 0x1a4) = 0x10460;
        *(undefined4 *)(param_1 + 0x1a8) = 0x10480;
        *(undefined4 *)(param_1 + 0x1ac) = 0x10484;
        *(undefined4 *)(param_1 + 0x1b0) = 0x10400;
        *(undefined4 *)(param_1 + 0x1b4) = 0x10404;
        *(undefined4 *)(param_1 + 0x1b8) = 0x10420;
        *(undefined4 *)(param_1 + 0x1bc) = 0x10424;
        *(undefined4 *)(param_1 + 0x1c0) = 0x4008;
        *(undefined4 *)(param_1 + 0x1c4) = 0x400c;
        *(undefined4 *)(param_1 + 0x1c8) = 0x4018;
        *(undefined4 *)(param_1 + 0x1cc) = 0x401c;
        *(undefined4 *)(param_1 + 0x1d0) = 0x4058;
        *(undefined4 *)(param_1 + 0x1d4) = 0x405c;
        *(undefined4 *)(param_1 + 0x1d8) = 0x406c;
        *(undefined4 *)(param_1 + 0x1dc) = 0x4070;
        *(undefined4 *)(param_1 + 0x1e0) = 0x4038;
        *(undefined4 *)(param_1 + 0x1e8) = 0x4080;
        *(undefined4 *)(param_1 + 0x1ec) = 0x4084;
        *(undefined4 *)(param_1 + 0x1e4) = 0x4088;
        *(undefined4 *)(param_1 + 0x1f0) = 0x10;
        *(undefined4 *)(param_1 + 500) = 0x1000;
        *(undefined4 *)(param_1 + 0x1fc) = 0x4000;
        *(undefined4 *)(param_1 + 0x200) = 0x3fff;
        *(undefined4 *)(param_1 + 0x204) = 1;
        *(undefined4 *)(param_1 + 0x208) = 6;
      }
      else {
        uVar3 = 0;
        *(undefined4 *)(param_1 + 0x180) = 0x20200;
        *(undefined4 *)(param_1 + 0x184) = 0x2020c;
        *(undefined4 *)(param_1 + 0x188) = 0x20210;
        *(undefined4 *)(param_1 + 0x194) = 0x20108;
        *(undefined4 *)(param_1 + 0x198) = 0x2010c;
        *(undefined4 *)(param_1 + 500) = 2;
        *(undefined4 *)(param_1 + 0x204) = 2;
        *(undefined4 *)(param_1 + 0x1a4) = 0x20400;
        *(undefined4 *)(param_1 + 0x1a8) = 0x20408;
        *(undefined4 *)(param_1 + 0x1ac) = 0x2040c;
        *(undefined4 *)(param_1 + 0x1b0) = 0x20430;
        *(undefined4 *)(param_1 + 0x1b4) = 0x20434;
        *(undefined4 *)(param_1 + 0x1b8) = 0x20438;
        *(undefined4 *)(param_1 + 0x1bc) = 0x2043c;
        *(undefined4 *)(param_1 + 0x1c0) = 0x508;
        *(undefined4 *)(param_1 + 0x1c4) = 0x50c;
        *(undefined4 *)(param_1 + 0x1c8) = 0x518;
        *(undefined4 *)(param_1 + 0x1cc) = 0x51c;
        *(undefined4 *)(param_1 + 0x1d0) = 0x5b0;
        *(undefined4 *)(param_1 + 0x1d4) = 0x5b4;
        *(undefined4 *)(param_1 + 0x1d8) = 0x544;
        *(undefined8 *)(param_1 + 0x1dc) = 0x548;
        *(undefined4 *)(param_1 + 0x1e4) = 0x560;
        *(undefined4 *)(param_1 + 0x1e8) = 0x568;
        *(undefined4 *)(param_1 + 0x1ec) = 0x56c;
        *(undefined4 *)(param_1 + 0x1f0) = 0x140;
        *(undefined4 *)(param_1 + 0x1f8) = 1;
        *(undefined4 *)(param_1 + 0x1fc) = 0x1000;
        *(undefined4 *)(param_1 + 0x200) = 0xfff;
        *(undefined4 *)(param_1 + 0x208) = 0x1000;
      }
      *(undefined4 *)(param_1 + 0x18c) = 0xf1400;
      *(undefined4 *)(param_1 + 400) = 0x20104;
      return CONCAT71((int7)(uVar3 >> 8),1);
    }
  }
  return uVar3 & 0xffffffffffffff00;
}



===== StorPassiveInitializeRoutine @ 0001293c =====

undefined1 StorPassiveInitializeRoutine(undefined8 *param_1)

{
  StorPortNotification(0x1001,param_1,param_1 + 2,hba_isr_dpc_routine);
  if (*(char *)((longlong)param_1 + 0x9c) == '\0') {
    *(undefined4 *)(param_1 + 0x13) = 2;
    hba_module_start(param_1);
  }
  return 1;
}



===== mv_hwinitialize @ 00012984 =====

undefined1 mv_hwinitialize(undefined8 *param_1)

{
  undefined4 local_res8 [8];
  
  if (*(char *)((longlong)param_1 + 0x9c) == '\0') {
    local_res8[0] = 0;
    StorPortNotification(0x1000,param_1,StorPassiveInitializeRoutine,local_res8);
    if ((char)local_res8[0] == '\0') {
      *(undefined4 *)(param_1 + 0x13) = 2;
      hba_module_start(param_1);
    }
  }
  return 1;
}



===== execute_shutdown_synchronous @ 000129d8 =====

void execute_shutdown_synchronous
               (undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  longlong *plVar2;
  longlong lVar3;
  code *pcVar4;
  bool bVar5;
  ulonglong uVar6;
  undefined4 *local_res8;
  
  plVar2 = (longlong *)param_1[0x2f];
  uVar1 = *(uint *)((longlong)param_1 + 0x184);
  lVar3 = *plVar2;
  local_res8 = (undefined4 *)0x0;
  do {
    *(undefined4 *)((ulonglong)uVar1 + lVar3) = 0;
    LOCK();
    UNLOCK();
  } while (*(int *)((ulonglong)uVar1 + lVar3) != 0);
  *(undefined1 *)(param_1 + 0xb) = 1;
  if (*(int *)(param_1 + 0x13) != 3) {
    pcVar4 = (code *)swi(3);
    (*pcVar4)();
    return;
  }
  if (*(short *)(param_1 + 0x45) == 0) {
    pcVar4 = (code *)swi(3);
    (*pcVar4)();
    return;
  }
  if (*(int *)((longlong)plVar2 + 0x8c) != 0) {
    pcVar4 = (code *)swi(3);
    (*pcVar4)();
    return;
  }
  mu_get_inb_list_entry(plVar2,(longlong *)&local_res8);
  if (local_res8 == (undefined4 *)0x0) {
    pcVar4 = (code *)swi(3);
    (*pcVar4)();
    return;
  }
  *local_res8 = 0xffff0000;
  *(undefined1 *)(local_res8 + 1) = 1;
  local_res8[2] = 0;
  *(undefined1 *)((longlong)local_res8 + 6) = 6;
  *(undefined2 *)(local_res8 + 4) = 0x1e1;
  *(undefined1 *)((longlong)local_res8 + 0x12) = 0xb;
  uVar6 = (ulonglong)*(uint *)(plVar2 + 0x10);
  *(undefined4 *)((longlong)plVar2 + 0x84) = 0;
  *(uint *)((ulonglong)*(uint *)(plVar2[1] + 0x1c8) + *plVar2) = *(uint *)(plVar2 + 0x10);
  LOCK();
  UNLOCK();
  do {
    do {
      bVar5 = hba_interrupt_service_routine(param_1,uVar6,param_3,param_4);
    } while (!bVar5);
  } while (*(int *)((longlong)plVar2 + 0x8c) != 0);
  return;
}



===== hba_handle_waiting_list @ 00012aa8 =====

void hba_handle_waiting_list
               (undefined8 *param_1,undefined8 param_2,ulonglong param_3,undefined8 param_4)

{
  char cVar1;
  int iVar2;
  longlong lVar3;
  longlong *plVar4;
  longlong lVar5;
  undefined8 *puVar6;
  longlong *plVar7;
  undefined2 uVar8;
  ulonglong uVar9;
  longlong *plVar10;
  short sVar11;
  void *local_res8;
  
  plVar7 = param_1 + 0x23;
  sVar11 = 0;
  if ((longlong *)param_1[0x24] != plVar7) {
    do {
      plVar10 = (longlong *)param_1[0x24];
      if (plVar10 == plVar7) {
        plVar10 = (longlong *)0x0;
      }
      else {
        plVar4 = (longlong *)plVar10[1];
        lVar3 = *plVar10;
        *plVar4 = lVar3;
        *(longlong **)(lVar3 + 8) = plVar4;
        plVar10[1] = 0;
        *plVar10 = 0;
      }
      lVar3 = plVar10[3];
      if (lVar3 == 0) {
LAB_00012b3a:
        plVar4 = (longlong *)param_1[0x2f];
        if ((((*(int *)(param_1 + 0x13) != 3) || (*(short *)(param_1 + 0x45) == 0)) ||
            ((uint)*(ushort *)((longlong)param_1 + 0xa2) <= *(uint *)((longlong)plVar4 + 0x8c))) ||
           (uVar9 = mu_get_inb_list_entry(plVar4,(longlong *)&local_res8), (char)uVar9 == '\0')) {
          puVar6 = (undefined8 *)param_1[0x24];
          *puVar6 = plVar10;
          plVar10[1] = (longlong)puVar6;
          *plVar10 = (longlong)plVar7;
          param_1[0x24] = plVar10;
          break;
        }
        uVar8 = Tag_GetOne(param_1 + 0x44);
        *(undefined2 *)((longlong)plVar10 + 0x37) = uVar8;
        uVar8 = *(undefined2 *)(param_1 + 0x14);
        *(undefined2 *)((longlong)plVar10 + 0x41) = uVar8;
        *(undefined2 *)((longlong)plVar10 + 0x32) = uVar8;
        param_1[(ulonglong)*(ushort *)((longlong)plVar10 + 0x37) + 0x46] = plVar10;
        *(short *)(param_1 + 0x14) = *(short *)(param_1 + 0x14) + 1;
        param_3 = (ulonglong)*(ushort *)(plVar4 + 10);
        memcpy(local_res8,(void *)((longlong)plVar10 + 0x35),param_3);
        *(int *)(plVar10 + 2) = gSeqId;
        gSeqId = gSeqId + 1;
        sVar11 = sVar11 + 1;
      }
      else {
        cVar1 = *(char *)(lVar3 + 2);
        param_3 = CONCAT71((int7)(param_3 >> 8),cVar1);
        if (cVar1 == '\x02') {
          iVar2 = *(int *)(*(longlong *)(lVar3 + 0x18) + 0x10);
          if (iVar2 != 0x4e400) {
            if (iVar2 == 0x4e404) {
              *(undefined2 *)((longlong)plVar10 + 0x35) = 0;
              *(undefined2 *)((longlong)plVar10 + 0x45) = 0x4f0;
              *(undefined1 *)((longlong)plVar10 + 0x47) = 0;
            }
            goto LAB_00012b3a;
          }
        }
        else if (*(char *)(lVar3 + 0x48) != -0xc) goto LAB_00012b3a;
        if (cVar1 == '\x02') {
          lVar5 = *(longlong *)(lVar3 + 0x18);
          if (*(int *)(lVar5 + 0x10) == 0x4e400) {
            *(undefined4 *)(lVar5 + 0x14) = 0;
            *(undefined1 *)(lVar5 + 0x1c) = 0;
            *(undefined1 *)(lVar3 + 4) = 0;
          }
          else {
LAB_00012c38:
            *(undefined1 *)(lVar3 + 4) = 4;
          }
        }
        else {
          if ((*(char *)(lVar3 + 0x48) != -0xc) || (*(char *)(lVar3 + 0x49) != '\0'))
          goto LAB_00012c38;
          mvGetEvent((longlong)param_1,lVar3);
        }
        hba_request_callback(param_1,lVar3,param_3,param_4);
      }
    } while ((longlong *)param_1[0x24] != plVar7);
    if (sVar11 != 0) {
      plVar7 = (longlong *)param_1[0x2f];
      *(undefined4 *)((longlong)plVar7 + 0x84) = 0;
      *(int *)((ulonglong)*(uint *)(plVar7[1] + 0x1c8) + *plVar7) = (int)plVar7[0x10];
      LOCK();
      UNLOCK();
    }
  }
  return;
}



===== mv_buildio @ 00012ca4 =====

ulonglong mv_buildio(undefined8 *param_1,longlong param_2,undefined8 param_3,longlong param_4)

{
  longlong lVar1;
  int iVar2;
  ulonglong uVar3;
  undefined8 *puVar4;
  
  lVar1 = *(longlong *)(param_2 + 0x38);
  if (((*(char *)(param_2 + 2) == '\0') && (*(int *)(param_2 + 0x10) != 0)) &&
     ((*(char *)(param_2 + 0x48) - 8U & 0x5d) == 0)) {
    param_4 = param_2 + 0x18;
    iVar2 = StorPortExtendedFunction(5,param_1,param_2);
    if (gRunningMode == '\x01') {
      iVar2 = 0;
    }
    if (iVar2 != 0) {
      *(undefined2 *)(param_2 + 3) = 5;
      goto LAB_00012cff;
    }
  }
  puVar4 = param_1;
  uVar3 = translate_os_request(param_1,param_2,(ushort *)(lVar1 + 0x35),param_4);
  if ((char)uVar3 != '\0') {
    return CONCAT71((int7)(uVar3 >> 8),1);
  }
  hba_translate_req_status_to_os_status(puVar4,param_2);
LAB_00012cff:
  uVar3 = StorPortNotification(0,param_1,param_2);
  return uVar3 & 0xffffffffffffff00;
}



===== mv_startio @ 00012d48 =====

undefined1 mv_startio(undefined8 *param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  ulonglong *puVar4;
  ulonglong uVar5;
  ulonglong *puVar6;
  undefined1 uVar7;
  
  if (*(int *)(param_1 + 0x13) == 4) {
    *(undefined1 *)(param_2 + 4) = 4;
    uVar7 = 1;
  }
  else {
    if (*(char *)(param_2 + 2) != '%') {
      *(char *)((longlong)param_1 + 0x9d) = *(char *)((longlong)param_1 + 0x9d) + '\x01';
      if (*(int *)(param_1 + 0x13) == 3) {
        puVar4 = *(ulonglong **)(param_2 + 0x38);
        puVar6 = param_1 + 0x23;
        uVar5 = *puVar6;
        *puVar6 = (ulonglong)puVar4;
        puVar4[1] = (ulonglong)puVar6;
        *puVar4 = uVar5;
        *(ulonglong **)(uVar5 + 8) = puVar4;
        hba_handle_waiting_list(param_1,uVar5,(ulonglong)puVar4,param_4);
        return 1;
      }
      plVar2 = *(longlong **)(param_2 + 0x38);
      plVar1 = param_1 + 0x23;
      lVar3 = *plVar1;
      *plVar1 = (longlong)plVar2;
      plVar2[1] = (longlong)plVar1;
      *plVar2 = lVar3;
      *(longlong **)(lVar3 + 8) = plVar2;
      if (*(int *)(param_1 + 0x13) == 1) {
        *(undefined4 *)(param_1 + 0x13) = 2;
        hba_module_start(param_1);
        return 1;
      }
      return 1;
    }
    *(undefined1 *)(param_2 + 4) = 0;
    uVar7 = 0;
  }
  hba_translate_req_status_to_os_status(param_1,param_2);
  StorPortNotification(0,*param_1,param_2);
  return uVar7;
}



===== mv_isr_dpc @ 00012e1c =====

ulonglong mv_isr_dpc(undefined8 *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  longlong lVar4;
  ulonglong in_RAX;
  undefined8 uVar5;
  undefined4 local_res8 [8];
  
  if (*(char *)(param_1 + 0xb) == '\0') {
    uVar1 = *(uint *)((longlong)param_1 + 0x184);
    lVar4 = *(longlong *)param_1[0x2f];
    do {
      *(undefined4 *)((ulonglong)uVar1 + lVar4) = 0;
      LOCK();
      UNLOCK();
    } while (*(int *)((ulonglong)uVar1 + lVar4) != 0);
    *(undefined1 *)(param_1 + 0xb) = 1;
    uVar5 = hba_clear_int((longlong)param_1);
    if ((char)uVar5 != '\0') {
      local_res8[0] = 0;
      uVar5 = StorPortNotification(0x1002,*param_1,param_1 + 2,0,0,local_res8);
      return CONCAT71((int7)((ulonglong)uVar5 >> 8),1);
    }
    uVar1 = *(uint *)((longlong)param_1 + 0x5c);
    uVar2 = *(uint *)((longlong)param_1 + 0x184);
    lVar4 = *(longlong *)param_1[0x2f];
    do {
      *(uint *)((ulonglong)uVar2 + lVar4) = uVar1;
      LOCK();
      UNLOCK();
      uVar3 = *(uint *)((ulonglong)uVar2 + lVar4);
      in_RAX = (ulonglong)uVar3;
    } while (uVar3 != uVar1);
    *(undefined1 *)(param_1 + 0xb) = 0;
  }
  return in_RAX & 0xffffffffffffff00;
}



===== mvHwMSInterruptRoutine @ 00012ec4 =====

ulonglong mvHwMSInterruptRoutine(undefined8 *param_1)

{
  uint uVar1;
  longlong lVar2;
  code *pcVar3;
  ulonglong in_RAX;
  ulonglong uVar4;
  undefined8 uVar5;
  undefined4 local_res8 [8];
  
  if (*(char *)(param_1 + 0xb) == '\0') {
    uVar1 = *(uint *)((longlong)param_1 + 0x184);
    lVar2 = *(longlong *)param_1[0x2f];
    do {
      *(undefined4 *)((ulonglong)uVar1 + lVar2) = 0;
      LOCK();
      UNLOCK();
    } while (*(int *)((ulonglong)uVar1 + lVar2) != 0);
    *(undefined1 *)(param_1 + 0xb) = 1;
    uVar5 = hba_clear_int((longlong)param_1);
    if ((char)uVar5 == '\0') {
      pcVar3 = (code *)swi(3);
      uVar5 = (*pcVar3)();
      return uVar5;
    }
    local_res8[0] = 0;
    uVar5 = StorPortNotification(0x1002,*param_1,param_1 + 2,0,0,local_res8);
    uVar4 = CONCAT71((int7)((ulonglong)uVar5 >> 8),1);
  }
  else {
    uVar4 = in_RAX & 0xffffffffffffff00;
  }
  return uVar4;
}



===== mv_adaptercontrol @ 00012f6c =====

undefined8 mv_adaptercontrol(undefined8 *param_1,int param_2,longlong param_3)

{
  undefined8 uVar1;
  code *pcVar2;
  undefined8 uVar3;
  
  if (param_2 == 0) {
    *(undefined2 *)(param_3 + 4) = 0x101;
    *(undefined1 *)(param_3 + 6) = 0;
  }
  else {
    if (param_2 != 1) {
      return 1;
    }
    if (*(int *)(param_1 + 0x13) == 3) {
      if (*(char *)((longlong)param_1 + 0x9d) != '\0') {
        pcVar2 = (code *)swi(3);
        uVar1 = (*pcVar2)();
        return uVar1;
      }
      uVar1 = *param_1;
      uVar3 = 0;
      pcVar2 = timer_check_request;
      StorPortNotification(6);
      execute_shutdown_synchronous(param_1,uVar1,pcVar2,uVar3);
    }
  }
  return 0;
}



===== mv_resetbus @ 00012fcc =====

BADSPACEBASE * mv_resetbus(undefined8 *param_1,int param_2,undefined8 param_3,undefined8 param_4)

{
  longlong *plVar1;
  uint uVar2;
  longlong lVar3;
  undefined8 uVar4;
  char *pcVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  
  plVar1 = (longlong *)param_1[0x2f];
  if (param_2 == 0) {
    if ((*(int *)(param_1 + 0x13) != 2) && (*(byte *)((longlong)param_1 + 0x9d) != 0)) {
      uVar6 = (ulonglong)*(uint *)((longlong)plVar1 + 0x8c);
      MV_PRINT("Overloading:%d %d \n",(ulonglong)*(byte *)((longlong)param_1 + 0x9d),uVar6,param_4);
      lVar3 = hba_get_time_in_second();
      uVar2 = (uint)lVar3;
      if (*(int *)((longlong)param_1 + 0x10c) == 0) {
        *(uint *)((longlong)param_1 + 0x10c) = uVar2 + 0x3c;
      }
      if (*(uint *)((longlong)param_1 + 0x10c) <= uVar2) {
        *(uint *)((longlong)param_1 + 0x10c) = uVar2 + 0x3c;
        if (*(uint *)(param_1 + 0x21) == (uint)*(byte *)((longlong)param_1 + 0x9d)) {
          *(char *)(param_1 + 0x22) = *(char *)(param_1 + 0x22) + '\x01';
          if (*(byte *)(param_1 + 0x22) < 3) {
            uVar4 = MV_PRINT("Reset count down %d......\n",
                             (ulonglong)(3 - *(byte *)(param_1 + 0x22)),uVar6,param_4);
          }
          else {
            MV_PRINT("F/W seems to be dead, ready to decide reset procedure.\n",3,uVar6,param_4);
            *(undefined1 *)(param_1 + 0x22) = 0;
            if (*(char *)((longlong)param_1 + 0x9c) == '\0') {
              uVar2 = *(uint *)((ulonglong)*(uint *)(param_1 + 0x3b) + *plVar1);
              uVar8 = (ulonglong)*(byte *)((longlong)param_1 + 0x9d);
              uVar6 = (ulonglong)*(uint *)(plVar1 + 0x11);
              uVar7 = (ulonglong)uVar2;
              MV_PRINT("Reset Bus! HBA Ext. outbound slot 0x%x hardware outbout slot 0x%x outstanding IO %d\n"
                       ,uVar6,uVar7,uVar8);
              if (*(uint *)(plVar1 + 0x11) == uVar2) {
                uVar4 = MV_PRINT("Reset bus without outbound pointer mismatch\n",uVar6,uVar7,uVar8);
                *(short *)((longlong)param_1 + 0x106) = *(short *)((longlong)param_1 + 0x106) + 1;
              }
              else {
                uVar4 = mv_isr_dpc(param_1);
                pcVar5 = "DPC issued\n";
                if ((char)uVar4 == '\0') {
                  pcVar5 = "Cannot issue DPC!\n";
                }
                uVar4 = MV_PRINT(pcVar5,uVar6,uVar7,uVar8);
              }
            }
            else {
              uVar4 = StorPortCompleteRequest(param_1,0xff,0xff,0xff,0xe);
            }
          }
          return (BADSPACEBASE *)CONCAT71((int7)((ulonglong)uVar4 >> 8),1);
        }
        MV_PRINT("Reset Bus is called but F/W is still working......last iocnt %d - rstcnt %d\n",
                 (ulonglong)*(uint *)(param_1 + 0x21),
                 (ulonglong)*(ushort *)((longlong)param_1 + 0x106),param_4);
        *(undefined1 *)(param_1 + 0x22) = 0;
        *(uint *)(param_1 + 0x21) = (uint)*(byte *)((longlong)param_1 + 0x9d);
        *(undefined2 *)((longlong)param_1 + 0x106) = 0;
      }
    }
    register0x00000020 = (BADSPACEBASE *)0x1;
  }
  return register0x00000020;
}



===== hba_request_callback @ 00013188 =====

void hba_request_callback
               (undefined8 *param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  byte bVar5;
  undefined1 *puVar6;
  undefined8 uVar7;
  longlong lVar8;
  undefined1 uVar9;
  undefined7 uVar10;
  
  uVar9 = (undefined1)param_4;
  uVar10 = (undefined7)((ulonglong)param_4 >> 8);
  *(char *)((longlong)param_1 + 0x9d) = *(char *)((longlong)param_1 + 0x9d) + -1;
  hba_translate_req_status_to_os_status(param_1,param_2);
  if (((*(char *)(param_2 + 0x48) == '\x12') && ((*(byte *)(param_2 + 0x49) & 1) == 0)) &&
     (*(char *)(param_2 + 3) == '\x01')) {
    uVar9 = *(undefined1 *)(param_2 + 7);
    StorPortSetDeviceQueueDepth
              (*param_1,*(undefined1 *)(param_2 + 5),*(undefined1 *)(param_2 + 6),uVar9,0x80);
  }
  if (((*(short *)((longlong)param_1 + 0xb6) + 0x6ebeU & 0xfffc) == 0) &&
     (*(short *)((longlong)param_1 + 0xb6) != -0x6ebc)) {
    if (*(char *)(param_2 + 0x48) == '%') {
      puVar6 = *(undefined1 **)(param_2 + 0x18);
      uVar1 = puVar6[1];
      uVar2 = *puVar6;
      uVar3 = puVar6[2];
      uVar4 = puVar6[3];
      *(undefined1 *)(param_1 + 0x150) = 1;
      param_1[0x14f] = (ulonglong)CONCAT31(CONCAT21(CONCAT11(uVar2,uVar1),uVar3),uVar4);
    }
    if (((*(char *)(param_2 + 0x48) == '/') && (*(char *)(param_1 + 0x150) == '\x01')) &&
       ((ulonglong)param_1[0x14f] <=
        (ulonglong)
        CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(param_2 + 0x4a),*(undefined1 *)(param_2 + 0x4b)),
                          *(undefined1 *)(param_2 + 0x4c)),*(undefined1 *)(param_2 + 0x4d)))) {
      *(undefined2 *)(param_2 + 3) = 0x284;
    }
  }
  uVar7 = *param_1;
  lVar8 = param_2;
  StorPortNotification(0);
  bVar5 = *(byte *)(param_2 + 0x48);
  if ((((bVar5 < 0x30) &&
       (uVar7 = 0x850000000500, (0x850000000500U >> ((ulonglong)bVar5 & 0x3f) & 1) != 0)) ||
      (((byte)(bVar5 + 0x78) < 0x23 &&
       ((0x500000085U >> ((ulonglong)(byte)(bVar5 + 0x78) & 0x3f) & 1) != 0)))) &&
     ((*(int *)(param_1 + 0x21) != 0xff && (*(int *)(param_1 + 0x21) != 0)))) {
    *(undefined1 *)(param_1 + 0x22) = 0;
    *(undefined2 *)((longlong)param_1 + 0x106) = 0;
    *(undefined4 *)(param_1 + 0x21) = 0xff;
    MV_PRINT("Io still flows, discard old reset record......\n",uVar7,lVar8,CONCAT71(uVar10,uVar9));
  }
  return;
}



===== generate_sg_table @ 000132e8 =====

undefined8 generate_sg_table(longlong param_1,byte *param_2,uint *param_3)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  code *pcVar4;
  uint *in_RAX;
  undefined8 uVar5;
  uint uVar6;
  ulonglong uVar7;
  uint *puVar8;
  
  uVar7 = 0;
  if (*param_3 != 0) {
    do {
      if ((*(byte *)(param_1 + 0xaa) & 0x10) == 0) {
        uVar6 = param_3[uVar7 * 6 + 6];
        uVar2 = param_3[uVar7 * 6 + 5];
        uVar3 = param_3[uVar7 * 6 + 4];
        puVar8 = (uint *)((ulonglong)(uint)param_2[1] * 0x10 + *(longlong *)(param_2 + 8));
        if ((uint)*param_2 < param_2[1] + 1) {
          pcVar4 = (code *)swi(3);
          uVar5 = (*pcVar4)();
          return uVar5;
        }
        in_RAX = (uint *)sgdt_clear_eot((longlong)param_2);
        param_2[1] = param_2[1] + 1;
        *(uint *)(param_2 + 4) = *(int *)(param_2 + 4) + uVar6;
        *puVar8 = uVar3;
        puVar8[1] = uVar2;
        puVar8[3] = uVar6;
        puVar8[2] = 0x8000000;
      }
      else {
        bVar1 = param_2[1];
        uVar6 = param_3[uVar7 * 6 + 6];
        uVar2 = param_3[uVar7 * 6 + 5];
        uVar3 = param_3[uVar7 * 6 + 4];
        if (bVar1 != 0) {
          puVar8 = (uint *)((longlong)(int)((uint)bVar1 * 0xc + -0xc) + *(longlong *)(param_2 + 8) +
                           8);
          *puVar8 = *puVar8 & 0xf7ffffff;
        }
        *(uint *)(param_2 + 4) = *(int *)(param_2 + 4) + uVar6;
        param_2[1] = bVar1 + 1;
        in_RAX = (uint *)((longlong)(int)((uint)bVar1 * 0xc) + *(longlong *)(param_2 + 8));
        *in_RAX = uVar3;
        in_RAX[1] = uVar2;
        in_RAX[2] = uVar6 & 0xfbffffff;
      }
      uVar6 = (int)uVar7 + 1;
      uVar7 = (ulonglong)uVar6;
    } while (uVar6 < *param_3);
  }
  return CONCAT71((int7)((ulonglong)in_RAX >> 8),1);
}



===== translate_scsi_request @ 000133e4 =====

undefined8 translate_scsi_request(undefined8 *param_1,longlong param_2,undefined2 *param_3)

{
  undefined2 uVar1;
  undefined8 uVar2;
  undefined1 uVar3;
  uint uVar4;
  void *pvVar5;
  uint *puVar6;
  undefined8 *puVar7;
  ulonglong uVar8;
  undefined8 *puVar9;
  byte bVar10;
  undefined2 *puVar11;
  byte local_18 [4];
  undefined4 local_14;
  undefined2 *local_10;
  
  if ((*(byte *)((longlong)param_1 + 0xaa) & 0x10) == 0) {
    puVar11 = (undefined2 *)(*(longlong *)(param_2 + 0x38) + 0x438);
  }
  else {
    puVar11 = param_3 + 0x10;
  }
  uVar1 = *(undefined2 *)(param_2 + 6);
  *(undefined1 *)(param_3 + 2) = 0;
  *param_3 = uVar1;
  if (*(int *)(param_2 + 0x10) == 0) {
    *(undefined1 *)(param_3 + 2) = 1;
  }
  else {
    uVar3 = *(undefined1 *)(param_3 + 2);
    if ((*(byte *)(param_2 + 0xc) & 0x40) != 0) {
      uVar3 = 8;
    }
    *(undefined1 *)(param_3 + 2) = uVar3;
    if ((char)*(undefined4 *)(param_2 + 0xc) < '\0') {
      *(byte *)(param_3 + 2) = *(byte *)(param_3 + 2) | 0x10;
    }
  }
  *(undefined4 *)(param_3 + 4) = *(undefined4 *)(param_2 + 0x10);
  *(undefined1 *)(param_3 + 3) = *(undefined1 *)(param_2 + 10);
  local_10 = puVar11;
  pvVar5 = memcpy(param_3 + 8,(void *)(param_2 + 0x48),(ulonglong)*(byte *)(param_2 + 10));
  local_14 = 0;
  bVar10 = 0;
  local_18[2] = 0;
  local_18[0] = 0x22;
  local_18[1] = 0;
  if (*(int *)(param_2 + 0x10) != 0) {
    puVar6 = (uint *)StorPortGetScatterGatherList(*param_1,param_2);
    pvVar5 = (void *)0x0;
    if (puVar6 != (uint *)0x0) {
      pvVar5 = (void *)generate_sg_table((longlong)param_1,local_18,puVar6);
      puVar11 = local_10;
      bVar10 = local_18[1];
    }
    *(byte *)((longlong)param_3 + 7) = bVar10;
  }
  puVar9 = (undefined8 *)(param_3 + 0x10);
  if ((((*(byte *)((longlong)param_1 + 0xaa) & 0x10) == 0) && (*(int *)(param_2 + 0x10) != 0)) &&
     (uVar8 = (ulonglong)bVar10, uVar8 != 0)) {
    puVar7 = (undefined8 *)(param_3 + 0x18);
    puVar6 = (uint *)(puVar11 + 6);
    do {
      uVar2 = *(undefined8 *)(puVar6 + -1);
      *puVar9 = *(undefined8 *)(puVar6 + -3);
      puVar9[1] = uVar2;
      if ((puVar6[-1] & 0x2000000) != 0) {
        uVar2 = *(undefined8 *)(puVar6 + 3);
        *puVar7 = *(undefined8 *)(puVar6 + 1);
        puVar7[1] = uVar2;
      }
      if ((*(byte *)((longlong)param_1 + 0xaa) & 0x10) != 0) {
        *(uint *)(puVar9 + 1) = *(uint *)(puVar9 + 1) | 0x4000000;
        if ((*(uint *)(puVar9 + 1) & 0x4000000) == 0) {
          *(uint *)((longlong)puVar9 + 0xc) = *puVar6;
        }
        else {
          uVar4 = *(uint *)(puVar9 + 1) & 0xffc00000;
          *(uint *)(puVar9 + 1) = uVar4;
          *(uint *)(puVar9 + 1) = uVar4 | *puVar6;
        }
      }
      uVar4 = *(uint *)(puVar9 + 1);
      pvVar5 = (void *)(ulonglong)uVar4;
      if ((uVar4 & 0x4000000) == 0) {
        if ((uVar4 & 0x2000000) == 0) {
          puVar9 = puVar9 + 2;
          puVar7 = puVar7 + 2;
        }
        else {
          puVar9 = puVar9 + 4;
          puVar7 = puVar7 + 4;
        }
      }
      else {
        puVar9 = (undefined8 *)((longlong)puVar9 + 0xc);
        puVar7 = (undefined8 *)((longlong)puVar7 + 0xc);
      }
      puVar6 = puVar6 + 4;
      uVar8 = uVar8 - 1;
    } while (uVar8 != 0);
  }
  *(undefined1 *)(param_2 + 4) = 0x80;
  return CONCAT71((int7)((ulonglong)pvVar5 >> 8),1);
}



===== translate_ioctl_request @ 000135a4 =====

ulonglong translate_ioctl_request(undefined8 *param_1,longlong param_2,ushort *param_3)

{
  undefined4 uVar1;
  longlong lVar2;
  undefined8 uVar3;
  uint uVar4;
  ulonglong uVar5;
  uint *puVar6;
  undefined8 uVar7;
  ushort *puVar8;
  ushort *puVar9;
  ushort *puVar10;
  byte bVar11;
  ulonglong uVar12;
  undefined1 uStackX_11;
  undefined1 uStackX_12;
  undefined1 uStackX_13;
  undefined1 uStackX_21;
  byte local_28 [4];
  undefined4 local_24;
  ushort *local_20;
  
  lVar2 = *(longlong *)(param_2 + 0x18);
  local_20 = (ushort *)(*(longlong *)(param_2 + 0x38) + 0x438);
  if (*(int *)(param_2 + 0x10) == 0) {
    *(byte *)(param_3 + 2) = (byte)param_3[2] | 1;
  }
  else {
    if ((*(uint *)(param_2 + 0xc) & 0x40) != 0) {
      *(byte *)(param_3 + 2) = (byte)param_3[2] | 8;
    }
    if ((char)*(undefined4 *)(param_2 + 0xc) < '\0') {
      *(byte *)(param_3 + 2) = (byte)param_3[2] | 0x10;
    }
  }
  uVar5 = *(ulonglong *)(lVar2 + 4);
  if (uVar5 == 0x4b53494449534353) {
    uVar5 = mvAdapterSmartTranslator(lVar2,param_2,param_3);
  }
  else if (uVar5 == 0x677331647373766d) {
    if (*(int *)(lVar2 + 0x10) == 0x4e408) {
      uVar5 = translate_shutdown_function((longlong)param_1,param_2,param_3);
    }
    else {
      if (*(int *)(lVar2 + 0x10) == 0x4a414) {
        lVar2 = *(longlong *)(param_2 + 0x18);
        *(undefined4 *)(lVar2 + 0x14) = 0;
        param_3[8] = 0x1ec;
        param_3[4] = 0;
        param_3[5] = 0;
        *(undefined1 *)(param_3 + 2) = 1;
        *(undefined1 *)(param_3 + 3) = 9;
        *(undefined1 *)(param_2 + 4) = 0x80;
        uVar5 = 0;
        *param_3 = *(ushort *)(lVar2 + 0x2d);
        uVar7 = *(undefined8 *)(lVar2 + 0x1c);
        uVar3 = *(undefined8 *)(lVar2 + 0x24);
        *(char *)((longlong)param_3 + 0x15) = (char)uVar7;
        uStackX_11 = (undefined1)((ulonglong)uVar7 >> 8);
        *(undefined1 *)(param_3 + 10) = uStackX_11;
        uStackX_12 = (undefined1)((ulonglong)uVar7 >> 0x10);
        *(undefined1 *)((longlong)param_3 + 0x13) = uStackX_12;
        uStackX_13 = (undefined1)((ulonglong)uVar7 >> 0x18);
        *(undefined1 *)(param_3 + 9) = uStackX_13;
        uStackX_21 = (undefined1)((ulonglong)uVar3 >> 8);
        *(char *)(param_3 + 0xc) = (char)uVar3;
        *(undefined1 *)((longlong)param_3 + 0x17) = uStackX_21;
      }
      else {
        uVar1 = *(undefined4 *)(param_2 + 0x10);
        *(undefined4 *)(param_3 + 4) = uVar1;
        uVar5 = (ulonglong)CONCAT31((int3)((uint)uVar1 >> 8),*(byte *)((longlong)param_1 + 0xaa));
        if ((*(byte *)((longlong)param_1 + 0xaa) & 0x10) != 0) {
          local_20 = param_3 + 0x10;
        }
        puVar10 = local_20;
        local_24 = 0;
        local_28[2] = 0;
        local_28[0] = 0x22;
        local_28[1] = 0;
        if (*(int *)(param_2 + 0x10) != 0) {
          puVar6 = (uint *)StorPortGetScatterGatherList(*param_1);
          uVar7 = 0;
          bVar11 = 0;
          if (puVar6 != (uint *)0x0) {
            uVar7 = generate_sg_table((longlong)param_1,local_28,puVar6);
            puVar10 = local_20;
            bVar11 = local_28[1];
          }
          *(byte *)((longlong)param_3 + 7) = bVar11;
          uVar5 = CONCAT71((int7)((ulonglong)uVar7 >> 8),*(byte *)((longlong)param_1 + 0xaa));
          if ((*(byte *)((longlong)param_1 + 0xaa) & 0x10) == 0) {
            uVar12 = (ulonglong)bVar11;
            puVar9 = param_3 + 0x10;
            if (uVar12 != 0) {
              puVar8 = param_3 + 0x18;
              puVar6 = (uint *)(puVar10 + 6);
              do {
                uVar7 = *(undefined8 *)(puVar6 + -1);
                *(undefined8 *)puVar9 = *(undefined8 *)(puVar6 + -3);
                *(undefined8 *)(puVar9 + 4) = uVar7;
                if ((puVar6[-1] & 0x2000000) != 0) {
                  uVar7 = *(undefined8 *)(puVar6 + 3);
                  *(undefined8 *)puVar8 = *(undefined8 *)(puVar6 + 1);
                  *(undefined8 *)(puVar8 + 4) = uVar7;
                }
                if ((*(byte *)((longlong)param_1 + 0xaa) & 0x10) != 0) {
                  *(uint *)(puVar9 + 4) = *(uint *)(puVar9 + 4) | 0x4000000;
                  if ((*(uint *)(puVar9 + 4) & 0x4000000) == 0) {
                    *(uint *)(puVar9 + 6) = *puVar6;
                  }
                  else {
                    uVar4 = *(uint *)(puVar9 + 4) & 0xffc00000;
                    *(uint *)(puVar9 + 4) = uVar4;
                    *(uint *)(puVar9 + 4) = uVar4 | *puVar6;
                  }
                }
                uVar4 = *(uint *)(puVar9 + 4);
                uVar5 = (ulonglong)uVar4;
                if ((uVar4 & 0x4000000) == 0) {
                  if ((uVar4 & 0x2000000) == 0) {
                    puVar9 = puVar9 + 8;
                    puVar8 = puVar8 + 8;
                  }
                  else {
                    puVar9 = puVar9 + 0x10;
                    puVar8 = puVar8 + 0x10;
                  }
                }
                else {
                  puVar9 = puVar9 + 6;
                  puVar8 = puVar8 + 6;
                }
                puVar6 = puVar6 + 4;
                uVar12 = uVar12 - 1;
              } while (uVar12 != 0);
            }
          }
        }
      }
      uVar5 = CONCAT71((int7)(uVar5 >> 8),1);
    }
  }
  else {
    *(undefined1 *)(param_2 + 3) = 6;
    uVar5 = uVar5 & 0xffffffffffffff00;
  }
  return uVar5;
}



===== translate_shutdown_function @ 000137cc =====

undefined8 translate_shutdown_function(longlong param_1,longlong param_2,undefined2 *param_3)

{
  void *pvVar1;
  
  if ((*(char *)(param_1 + 0x9c) == '\0') && (*(char *)(param_2 + 2) != '\x02')) {
    *param_3 = *(undefined2 *)(param_2 + 6);
  }
  else {
    *param_3 = 0;
  }
  *(undefined4 *)(param_3 + 4) = 0;
  *(undefined1 *)(param_3 + 2) = 1;
  *(undefined1 *)(param_3 + 3) = *(undefined1 *)(param_2 + 10);
  pvVar1 = memcpy(param_3 + 8,(void *)(param_2 + 0x48),(ulonglong)*(byte *)(param_2 + 10));
  *(undefined1 *)(param_2 + 4) = 0x80;
  param_3[8] = 0x1e1;
  *(undefined1 *)(param_3 + 9) = 0xb;
  return CONCAT71((int7)((ulonglong)pvVar1 >> 8),1);
}



===== translate_pnp_function @ 0001384c =====

ulonglong translate_pnp_function(longlong param_1,longlong param_2)

{
  ushort uVar1;
  int iVar2;
  longlong lVar3;
  uint uVar4;
  
  iVar2 = *(int *)(param_2 + 8);
  if (((iVar2 != 0) &&
      (register0x00000020 = (BADSPACEBASE *)(ulonglong)(iVar2 - 2U), (iVar2 - 2U & 0xfffffffd) != 0)
      ) && (iVar2 == 9)) {
    lVar3 = *(longlong *)(param_2 + 0x18);
    *(uint *)(lVar3 + 4) = *(uint *)(lVar3 + 4) & 0xfffffff3;
    uVar1 = *(ushort *)(param_1 + 0xb6);
    if (((uVar1 == 0x8110) || (uVar1 == 0x8120)) ||
       ((register0x00000020 = (BADSPACEBASE *)(ulonglong)(uVar1 + 0x6ebe),
        (ushort)(uVar1 + 0x6ebe) < 2 || (uVar1 == 0x9145)))) {
      uVar4 = *(uint *)(lVar3 + 4) | 0x10;
    }
    else {
      uVar4 = *(uint *)(lVar3 + 4) & 0xffffffef;
    }
    *(uint *)(lVar3 + 4) = uVar4;
    *(uint *)(lVar3 + 4) = *(uint *)(lVar3 + 4) & 0xffffff1f;
    uVar1 = *(ushort *)(param_1 + 0xb6);
    if (((uVar1 == 0x8110) || (uVar1 == 0x8120)) ||
       ((register0x00000020 = (BADSPACEBASE *)(ulonglong)(uVar1 + 0x6ebe),
        (ushort)(uVar1 + 0x6ebe) < 2 || (uVar1 == 0x9145)))) {
      uVar4 = *(uint *)(lVar3 + 4) | 0x100;
    }
    else {
      uVar4 = *(uint *)(lVar3 + 4) & 0xfffffeff;
    }
    *(uint *)(lVar3 + 4) = uVar4;
    *(uint *)(lVar3 + 4) = *(uint *)(lVar3 + 4) & 0xfffffdff;
  }
  *(undefined1 *)(param_2 + 4) = 0;
  return (ulonglong)register0x00000020 & 0xffffffffffffff00;
}



===== translate_os_request @ 0001393c =====

ulonglong translate_os_request
                    (undefined8 *param_1,longlong param_2,ushort *param_3,undefined8 param_4)

{
  byte bVar1;
  ushort uVar2;
  longlong lVar3;
  undefined2 uVar4;
  ulonglong uVar5;
  uint uVar6;
  undefined1 uVar7;
  
  lVar3 = *(longlong *)(param_2 + 0x38);
  memset((void *)(lVar3 + 0x35),0,(ulonglong)*(ushort *)(param_1[0x2f] + 0x50));
  *(undefined1 *)((longlong)param_3 + 5) = 1;
  *(longlong *)(lVar3 + 0x18) = param_2;
  bVar1 = *(byte *)(param_2 + 2);
  uVar7 = 0;
  *(undefined1 *)(param_2 + 4) = 4;
  if (bVar1 == 0) {
    uVar5 = translate_scsi_request(param_1,param_2,param_3);
  }
  else if (bVar1 == 2) {
    uVar5 = translate_ioctl_request(param_1,param_2,param_3);
  }
  else if (bVar1 == 7) {
    uVar5 = translate_shutdown_function((longlong)param_1,param_2,param_3);
  }
  else if (bVar1 == 8) {
    uVar2 = *(ushort *)((longlong)param_1 + 0xb6);
    uVar5 = (ulonglong)uVar2;
    lVar3 = *(longlong *)(param_2 + 0x38);
    if ((((uVar2 == 0x9480) || (uVar2 == 0x9580)) || (uVar2 == 0x9588)) || (uVar2 == 0x9548)) {
      uVar4 = *(undefined2 *)(param_2 + 6);
      *(undefined8 *)(lVar3 + 0x39) = 0x100101;
      uVar5 = 0;
      *(undefined2 *)(lVar3 + 0x35) = uVar4;
      *(undefined1 *)(lVar3 + 0x45) = 0x35;
      if ((*(uint *)(lVar3 + 0x5d) >> 0x1a & 1) == 0) {
        *(undefined4 *)(lVar3 + 0x61) = 0;
      }
      else {
        uVar6 = *(uint *)(lVar3 + 0x5d) & 0xffc00000;
        uVar5 = (ulonglong)uVar6;
        *(uint *)(lVar3 + 0x5d) = uVar6;
      }
      *(undefined1 *)(param_2 + 4) = 0x80;
      uVar7 = 1;
    }
    else {
      *(undefined1 *)(param_2 + 4) = 0;
    }
    uVar5 = CONCAT71((int7)(uVar5 >> 8),uVar7);
  }
  else if (bVar1 == 0x25) {
    uVar5 = translate_pnp_function((longlong)param_1,param_2);
  }
  else {
    uVar5 = MV_PRINT("unhandled srb function 0x%x.\n",(ulonglong)bVar1,0,param_4);
    uVar5 = uVar5 & 0xffffffffffffff00;
  }
  return uVar5;
}



===== mvAdapterSmartTranslator @ 00013a94 =====

ulonglong mvAdapterSmartTranslator(undefined8 param_1,longlong param_2,ushort *param_3)

{
  byte bVar1;
  char cVar2;
  uint uVar3;
  uint *puVar4;
  undefined2 *puVar5;
  ulonglong uVar6;
  
  puVar4 = *(uint **)(param_2 + 0x18);
  uVar6 = (ulonglong)*puVar4;
  bVar1 = *(byte *)(uVar6 + 0xc + (longlong)puVar4);
  *(undefined1 *)(param_3 + 2) = 0;
  param_3[4] = 0;
  param_3[5] = 0;
  *param_3 = (ushort)bVar1;
  param_3[1] = (ushort)*(byte *)(param_2 + 8);
  param_3[8] = 0;
  param_3[9] = 0;
  param_3[10] = 0;
  param_3[0xb] = 0;
  param_3[0xc] = 0;
  param_3[0xd] = 0;
  param_3[0xe] = 0;
  param_3[0xf] = 0;
  param_3[8] = 0x1e1;
  *(undefined1 *)(param_3 + 9) = 0x15;
  cVar2 = *(char *)(uVar6 + 10 + (longlong)puVar4);
  *(char *)((longlong)param_3 + 0x13) = cVar2;
  *(undefined1 *)(param_3 + 10) = *(undefined1 *)(uVar6 + 4 + (longlong)puVar4);
  *(undefined1 *)(param_3 + 0xb) = *(undefined1 *)(uVar6 + 7 + (longlong)puVar4);
  *(undefined1 *)((longlong)param_3 + 0x17) = *(undefined1 *)(uVar6 + 8 + (longlong)puVar4);
  if (((cVar2 == -0x14) || (cVar2 == -0x5f)) || (cVar2 == -0x50)) {
    uVar3 = puVar4[4];
    if (uVar3 < 0x1b0502) {
LAB_00013b3b:
      *(undefined1 *)((longlong)param_3 + 0x15) = *(undefined1 *)(uVar6 + 6 + (longlong)puVar4);
      *(undefined1 *)((longlong)param_3 + 0x19) = *(undefined1 *)(uVar6 + 9 + (longlong)puVar4);
      *(undefined1 *)(param_3 + 0xc) = *(undefined1 *)(uVar6 + 5 + (longlong)puVar4);
    }
    else {
      if (uVar3 < 0x1b0509) {
        *(undefined1 *)((longlong)param_3 + 0x15) = 0;
      }
      else {
        if (uVar3 != 0x1b0509) goto LAB_00013b3b;
        *(undefined1 *)((longlong)param_3 + 0x15) = *(undefined1 *)(uVar6 + 6 + (longlong)puVar4);
        *(undefined1 *)((longlong)param_3 + 0x19) = *(undefined1 *)(uVar6 + 9 + (longlong)puVar4);
      }
      *(undefined1 *)(param_3 + 0xc) = 0;
    }
  }
  uVar3 = puVar4[4];
  puVar5 = (undefined2 *)(ulonglong)uVar3;
  if (uVar3 == 0x1b0500) {
    puVar5 = (undefined2 *)((ulonglong)*puVar4 + *(longlong *)(param_2 + 0x18));
    if (puVar4[6] < 0x18) goto LAB_00013bc5;
    *puVar5 = 0;
    *(undefined4 *)(puVar5 + 2) = 0;
    *(undefined1 *)((longlong)puVar5 + 3) = 0xff;
    puVar4[5] = 0;
    param_3[4] = 0x18;
    param_3[5] = 0;
LAB_00013c0a:
    *(undefined1 *)(param_2 + 4) = 4;
  }
  else {
    if (uVar3 == 0x1b0501) {
LAB_00013bb0:
      uVar3 = puVar4[6];
      puVar5 = (undefined2 *)(ulonglong)uVar3;
      if (0x20f < uVar3) {
LAB_00013ba1:
        *(undefined1 *)(uVar6 + 4 + (longlong)puVar4) = 9;
        puVar4[5] = 2;
        goto LAB_00013c0a;
      }
      if (0x10 < uVar3) {
        *(undefined1 *)(uVar6 + 4 + (longlong)puVar4) = 4;
      }
    }
    else if (uVar3 == 0x1b0502) {
      uVar3 = puVar4[6];
      puVar5 = (undefined2 *)(ulonglong)uVar3;
      if (0x20f < uVar3) goto LAB_00013ba1;
      if (0x10 < uVar3) {
        *(undefined1 *)(uVar6 + 4 + (longlong)puVar4) = 4;
        *(undefined1 *)(param_2 + 4) = 5;
      }
    }
    else {
      if (uVar3 == 0x1b0503) goto LAB_00013bb0;
      if (0x1b0503 < uVar3) {
        if (0x1b0509 < uVar3) {
          if (uVar3 == 0x1b050b) goto LAB_00013ba1;
          if (uVar3 != 0x1b050c) goto LAB_00013bc5;
        }
        *(undefined1 *)(param_2 + 4) = 4;
        puVar4[5] = 2;
        goto LAB_00013c0e;
      }
    }
LAB_00013bc5:
    *(undefined1 *)(param_2 + 4) = 5;
  }
LAB_00013c0e:
  return (ulonglong)puVar5 & 0xffffffffffffff00;
}



===== FUN_00013c14 @ 00013c14 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
FUN_00013c14(longlong param_1,uint param_2,ulonglong param_3,undefined8 param_4,byte param_5,
            undefined4 *param_6,byte param_7,void *param_8)

{
  longlong *plVar1;
  code *pcVar2;
  void *pvVar3;
  undefined8 uVar4;
  longlong lVar5;
  longlong lVar6;
  longlong *plVar7;
  longlong *plVar8;
  ushort uVar9;
  ushort uVar10;
  ulonglong uVar11;
  undefined1 uVar12;
  byte bVar13;
  undefined1 auStackY_b8 [32];
  uint local_68 [8];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_b8;
  uVar12 = (undefined1)param_4;
  uVar10 = (ushort)param_3;
  bVar13 = 0;
  pvVar3 = param_8;
  if (4 < param_5) {
LAB_00013c73:
    return (ulonglong)pvVar3 & 0xffffffffffffff00;
  }
  plVar7 = (longlong *)(param_1 + 0x158);
  if (*(longlong **)(param_1 + 0x160) == plVar7) {
    pvVar3 = (void *)(param_1 + 0x138);
    if (*(void **)(param_1 + 0x140) == pvVar3) goto LAB_00013c73;
    if (*(longlong **)(param_1 + 0x160) != plVar7) goto LAB_00013cd2;
    if (*(longlong **)(param_1 + 0x140) == (longlong *)(param_1 + 0x138)) {
      pcVar2 = (code *)swi(3);
      uVar4 = (*pcVar2)();
      return uVar4;
    }
    if (*(char *)(param_1 + 0x16c) != '\x14') {
      pcVar2 = (code *)swi(3);
      uVar4 = (*pcVar2)();
      return uVar4;
    }
    plVar8 = *(longlong **)(param_1 + 0x140);
    if (plVar8 == (longlong *)(param_1 + 0x138)) goto LAB_00013d0b;
    plVar7 = (longlong *)plVar8[1];
    lVar5 = *plVar8;
    *plVar7 = lVar5;
    *(longlong **)(lVar5 + 8) = plVar7;
    plVar8[1] = 0;
    *plVar8 = 0;
  }
  else {
LAB_00013cd2:
    plVar8 = *(longlong **)(param_1 + 0x160);
    if (plVar8 == plVar7) {
      plVar8 = (longlong *)0x0;
    }
    else {
      plVar7 = (longlong *)plVar8[1];
      lVar5 = *plVar8;
      *plVar7 = lVar5;
      *(longlong **)(lVar5 + 8) = plVar7;
      plVar8[1] = 0;
      *plVar8 = 0;
    }
    *(char *)(param_1 + 0x16c) = *(char *)(param_1 + 0x16c) + '\x01';
    if (0x14 < *(byte *)(param_1 + 0x16c)) {
      pcVar2 = (code *)swi(3);
      uVar4 = (*pcVar2)();
      return uVar4;
    }
  }
  if (plVar8 == (longlong *)0x0) {
LAB_00013d0b:
    pcVar2 = (code *)swi(3);
    uVar4 = (*pcVar2)();
    return uVar4;
  }
  *(byte *)((longlong)plVar8 + 0x1d) = param_5;
  *(uint *)(plVar8 + 3) = param_2;
  *(undefined4 *)((longlong)plVar8 + 0x14) = *(undefined4 *)(param_1 + 0x168);
  *(int *)(param_1 + 0x168) = *(int *)(param_1 + 0x168) + 1;
  *(undefined1 *)((longlong)plVar8 + 0x1c) = uVar12;
  *(ushort *)((longlong)plVar8 + 0x1e) = uVar10;
  uVar11 = param_3;
  lVar5 = hba_get_time_in_second();
  *(int *)(plVar8 + 2) = (int)lVar5;
  if ((param_5 != 0) && (param_6 != (undefined4 *)0x0)) {
    uVar11 = (ulonglong)(int)((uint)param_5 << 2);
    memcpy(plVar8 + 4,param_6,uVar11);
  }
  uVar9 = 0x1e;
  if ((param_7 == 0) || (param_8 == (void *)0x0)) {
    *(undefined1 *)(plVar8 + 6) = 0;
  }
  else {
    if (0x1e < param_7) {
      param_7 = 0x1e;
    }
    uVar11 = (ulonglong)param_7;
    *(byte *)(plVar8 + 6) = param_7;
    memcpy((void *)((longlong)plVar8 + 0x32),param_8,uVar11);
  }
  if (param_2 == 0x10064) {
LAB_00013dbd:
    uVar9 = 6;
  }
  else if (param_2 != 0x20024) {
    if (param_2 - 0x20025 < 2) goto LAB_00013dbd;
    uVar9 = 0;
  }
  if (*(char *)(param_1 + 0x9c) == '\0') {
    uVar4 = CONCAT71((int7)(uVar11 >> 8),uVar12);
    uVar11 = param_3 & 0xffff;
    MvGenerateSysMsg(param_2,uVar10,uVar4,CONCAT71((int7)((ulonglong)param_4 >> 8),param_5),param_6,
                     param_7,(longlong)param_8,local_68);
    plVar7 = (longlong *)MvLogEvent(local_68,uVar11,uVar4,(ulonglong)uVar9);
    if ((char)plVar7 == '\0') {
      *(char *)(param_1 + 0x16d) = *(char *)(param_1 + 0x16d) + '\x01';
      if (0x10 < *(byte *)(param_1 + 0x16d)) {
        *(byte *)(param_1 + 0x16d) = *(byte *)(param_1 + 0x16d) - 1;
        plVar1 = (longlong *)(param_1 + 0x138);
        lVar5 = *plVar1;
        *plVar1 = (longlong)plVar8;
        plVar8[1] = (longlong)plVar1;
        *plVar8 = lVar5;
        *(longlong **)(lVar5 + 8) = plVar8;
        goto LAB_00013ecc;
      }
      lVar5 = *(longlong *)(param_1 + 0x150);
      if (*(longlong *)(param_1 + 0x150) != param_1 + 0x148) {
        do {
          lVar6 = lVar5;
          if (*(int *)(lVar6 + 0x10) == 0) break;
          bVar13 = bVar13 + 1;
          lVar5 = *(longlong *)(lVar6 + 8);
        } while (*(longlong *)(lVar6 + 8) != param_1 + 0x148);
        if (bVar13 < 0x10) {
          *(byte *)(lVar6 + 0x1d) = param_5;
          *(uint *)(lVar6 + 0x18) = param_2;
          *(undefined4 *)(lVar6 + 0x14) = *(undefined4 *)((longlong)plVar8 + 0x14);
          *(undefined1 *)(lVar6 + 0x1c) = uVar12;
          *(ushort *)(lVar6 + 0x1e) = uVar10;
          *(int *)(lVar6 + 0x10) = (int)plVar8[2];
          memcpy((void *)(lVar6 + 0x20),plVar8 + 4,(longlong)(int)((uint)param_5 << 2));
        }
      }
    }
  }
  plVar7 = (longlong *)(param_1 + 0x138);
  lVar5 = *plVar7;
  *plVar7 = (longlong)plVar8;
  plVar8[1] = (longlong)plVar7;
  *plVar8 = lVar5;
  *(longlong **)(lVar5 + 8) = plVar8;
LAB_00013ecc:
  return CONCAT71((int7)((ulonglong)plVar7 >> 8),1);
}



===== handle_waited_event @ 00013ef8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void handle_waited_event(longlong param_1)

{
  undefined8 *puVar1;
  uint uVar2;
  code *pcVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 uVar6;
  byte bVar7;
  ulonglong uVar8;
  ushort uVar9;
  undefined1 auStackY_98 [32];
  undefined1 local_58 [20];
  char local_44;
  longlong local_40;
  uint local_38 [8];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  uVar6 = 0;
  memset(local_58,0,0x20);
  bVar7 = 0;
  lVar4 = *(longlong *)(param_1 + 0x150);
  if (*(longlong *)(param_1 + 0x150) == param_1 + 0x148) {
LAB_00013f65:
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  do {
    lVar5 = lVar4;
    if (*(int *)(lVar5 + 0x10) != 0) break;
    bVar7 = bVar7 + 1;
    lVar4 = *(longlong *)(lVar5 + 8);
  } while (*(longlong *)(lVar5 + 8) != param_1 + 0x148);
  if (0xf < bVar7) goto LAB_00013f65;
  uVar2 = *(uint *)(lVar5 + 0x18);
  puVar1 = (undefined8 *)(lVar5 + 0x20);
  if (puVar1 != (undefined8 *)0x0) {
    *puVar1 = *puVar1;
    *(undefined8 *)(lVar5 + 0x28) = *(undefined8 *)(lVar5 + 0x28);
  }
  if (*(char *)(lVar5 + 0x30) != '\0') {
    local_40 = lVar5 + 0x32;
    local_44 = *(char *)(lVar5 + 0x30);
  }
  if (uVar2 != 0x10064) {
    if (uVar2 == 0x20024) {
      uVar9 = 0x1e;
      goto LAB_00013fc6;
    }
    if (1 < uVar2 - 0x20025) {
      uVar9 = 0;
      goto LAB_00013fc6;
    }
  }
  uVar9 = 6;
LAB_00013fc6:
  if (*(char *)(param_1 + 0x9c) == '\0') {
    uVar6 = CONCAT71((int7)((ulonglong)uVar6 >> 8),*(undefined1 *)(lVar5 + 0x1c));
    uVar8 = (ulonglong)*(ushort *)(lVar5 + 0x1e);
    MvGenerateSysMsg(uVar2,*(ushort *)(lVar5 + 0x1e),uVar6,
                     CONCAT71((int7)((ulonglong)local_40 >> 8),4),(undefined4 *)puVar1,local_44,
                     local_40,local_38);
    uVar6 = MvLogEvent(local_38,uVar8,uVar6,(ulonglong)uVar9);
    if ((char)uVar6 != '\0') {
      *(char *)(param_1 + 0x16d) = *(char *)(param_1 + 0x16d) + -1;
      memset((void *)(lVar5 + 0x10),0,0x40);
    }
  }
  return;
}



===== hba_module_get_resourcequota @ 00014048 =====

/* WARNING: Removing unreachable block (ram,0x000140b3) */
/* WARNING: Removing unreachable block (ram,0x000140a2) */

ulonglong hba_module_get_resourcequota(int param_1,ushort param_2)

{
  ushort uVar1;
  uint uVar2;
  
  if (param_1 == 0) {
    uVar2 = 0x20;
    if (param_2 != 1) {
      uVar2 = 0x42;
    }
    return (ulonglong)
           ((uint)param_2 * 0x50 +
           ((int)((ulonglong)uVar2 * 0x40 + 7 >> 3) + (int)((ulonglong)uVar2 * 8 + 7 >> 3) +
           (int)((ulonglong)uVar2 * 2 + 7 >> 3)) * 8 + 0x4950 + ((param_2 + 8) * 2 + 7 & 0xfffffff8)
           );
  }
  if (param_1 != 1) {
    return 0;
  }
  uVar1 = 2;
  if (2 < param_2) {
    uVar1 = param_2;
  }
  return (ulonglong)((uint)uVar1 * 0x440 + 0x6568);
}



===== hba_module_initialize @ 00014110 =====

void hba_module_initialize(longlong param_1,ushort param_2)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong *plVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  short sVar6;
  uint uVar7;
  longlong *plVar8;
  longlong lVar9;
  ulonglong uVar10;
  ushort uVar11;
  ushort uVar12;
  longlong lVar13;
  void *_Dst;
  longlong lVar14;
  ushort uVar15;
  longlong lVar16;
  void *local_48;
  undefined8 local_40;
  uint local_38;
  
  uVar4 = g_max_transfersize;
  *(ushort *)(param_1 + 0xaa) = *(ushort *)(param_1 + 0xaa) | 0x18;
  *(undefined4 *)(param_1 + 0xa4) = uVar4;
  plVar1 = (longlong *)(param_1 + 0x210);
  *(ushort *)(param_1 + 0xa2) = param_2;
  *(undefined2 *)(param_1 + 0xa8) = 0x80;
  lVar9 = param_1 + 0x118;
  lVar16 = 8;
  *(longlong *)(param_1 + 0x120) = lVar9;
  *(longlong *)lVar9 = lVar9;
  lVar9 = param_1 + 0x128;
  *(undefined1 *)(param_1 + 0x58) = 1;
  *(undefined8 *)(param_1 + 0x5c) = 0;
  *(longlong *)(param_1 + 0x130) = lVar9;
  *(undefined4 *)(param_1 + 0x98) = 1;
  *(undefined2 *)(param_1 + 0x9d) = 0;
  *(undefined2 *)(param_1 + 0x106) = 0;
  *(undefined4 *)(param_1 + 0x10c) = 0;
  *(undefined2 *)(param_1 + 0xa0) = 0;
  *(longlong *)lVar9 = lVar9;
  plVar8 = (longlong *)(param_1 + 0xa88);
  *(longlong **)(param_1 + 0x218) = plVar1;
  *plVar1 = (longlong)plVar1;
  lVar9 = 8;
  do {
    lVar13 = *plVar1;
    *plVar1 = (longlong)plVar8;
    plVar8[1] = (longlong)plVar1;
    *plVar8 = lVar13;
    *(longlong **)(lVar13 + 8) = plVar8;
    plVar8 = plVar8 + 0xcb;
    lVar9 = lVar9 + -1;
  } while (lVar9 != 0);
  lVar9 = param_1 + 0x138;
  plVar2 = (longlong *)(param_1 + 0x148);
  plVar3 = (longlong *)(param_1 + 0x158);
  *(undefined2 *)(param_1 + 0x16c) = 0;
  *(undefined4 *)(param_1 + 0x168) = 0;
  *(longlong *)lVar9 = lVar9;
  *plVar2 = (longlong)plVar2;
  *plVar3 = (longlong)plVar3;
  *(longlong *)(param_1 + 0x140) = lVar9;
  *(longlong **)(param_1 + 0x150) = plVar2;
  *(longlong **)(param_1 + 0x160) = plVar3;
  lVar9 = 0x14;
  do {
    lVar13 = lVar9;
    lVar9 = *plVar3;
    *plVar3 = (longlong)plVar8;
    plVar8[1] = (longlong)plVar3;
    *plVar8 = lVar9;
    *(longlong **)(lVar9 + 8) = plVar8;
    plVar8 = plVar8 + 10;
    lVar9 = lVar13 + -1;
  } while (lVar9 != 0);
  uVar10 = (ulonglong)((int)lVar13 + 0xf);
  do {
    lVar9 = *plVar2;
    *plVar2 = (longlong)plVar8;
    plVar8[1] = (longlong)plVar2;
    *plVar8 = lVar9;
    *(longlong **)(lVar9 + 8) = plVar8;
    plVar8 = plVar8 + 10;
    uVar10 = uVar10 - 1;
  } while (uVar10 != 0);
  uVar15 = param_2 + 8;
  *(longlong **)(param_1 + 0x220) = plVar8;
  *(ushort *)(param_1 + 0x22a) = uVar15;
  uVar11 = 0;
  *(ushort *)(param_1 + 0x228) = uVar15;
  *(undefined1 *)(param_1 + 0x22e) = 0;
  *(undefined2 *)(param_1 + 0x22c) = 0;
  lVar9 = (longlong)plVar8 + (longlong)(int)(param_2 + 8) * 2;
  if (uVar15 != 0) {
    lVar13 = 0;
    do {
      sVar6 = uVar15 - uVar11;
      uVar11 = uVar11 + 1;
      *(short *)(lVar13 + *(longlong *)(param_1 + 0x220)) = sVar6 + -1;
      lVar13 = lVar13 + 2;
    } while (uVar11 < uVar15);
  }
  uVar15 = 0x20;
  if (param_2 == 1) {
    uVar11 = 0x20;
  }
  else {
    uVar11 = 0x42;
  }
  *(ushort *)(param_1 + 0xd0) = uVar11;
  *(longlong *)(param_1 + 0xd8) = lVar9;
  *(ushort *)(param_1 + 0xe2) = uVar11;
  uVar10 = (ulonglong)uVar11;
  *(ushort *)(param_1 + 0xe0) = uVar11;
  *(undefined1 *)(param_1 + 0xe6) = 0;
  *(undefined2 *)(param_1 + 0xe4) = 0;
  uVar12 = 0;
  lVar13 = uVar10 * 2 + lVar9;
  if (uVar11 != 0) {
    lVar14 = 0;
    do {
      sVar6 = uVar11 - uVar12;
      uVar12 = uVar12 + 1;
      *(short *)(lVar14 + *(longlong *)(param_1 + 0xd8)) = sVar6 + -1;
      lVar14 = lVar14 + 2;
    } while (uVar12 < uVar11);
  }
  *(undefined8 *)(param_1 + 0xe8) = 0;
  *(longlong *)(param_1 + 200) = lVar13;
  lVar13 = lVar13 + uVar10 * 8;
  if (uVar11 != 0) {
    lVar14 = 0;
    do {
      *(undefined8 *)(lVar13 + 0x38) = 0;
      *(undefined1 *)(lVar13 + 0x30) = 0;
      *(longlong *)(lVar14 + *(longlong *)(param_1 + 200)) = lVar13;
      lVar13 = lVar13 + 0x40;
      lVar14 = lVar14 + 8;
      uVar10 = uVar10 - 1;
    } while (uVar10 != 0);
  }
  if (param_2 != 1) {
    uVar15 = 0x42;
  }
  lVar9 = lVar9 + (ulonglong)
                  (uint)(((int)((ulonglong)uVar15 * 2 + 7 >> 3) +
                         (int)((ulonglong)uVar15 * 0x40 + 7 >> 3) +
                         (int)((ulonglong)uVar15 * 8 + 7 >> 3)) * 8);
  sVar6 = *(short *)(param_1 + 0xb6);
  *(longlong *)(param_1 + 0x178) = lVar9;
  if ((((sVar6 == -0x6b80) || (sVar6 == -0x6a80)) || (sVar6 == -0x6a78)) || (sVar6 == -0x6ab8)) {
    uVar5 = *(undefined8 *)(param_1 + 0x70);
  }
  else {
    uVar5 = *(undefined8 *)(param_1 + 0x68);
  }
  local_48 = *(void **)(param_1 + 0xf0);
  *(undefined8 *)(param_1 + 0x170) = uVar5;
  local_40 = *(undefined8 *)(param_1 + 0xf8);
  local_38 = *(uint *)(param_1 + 0x100);
  memset(local_48,0,(ulonglong)local_38);
  uVar15 = 2;
  if (2 < param_2) {
    uVar15 = param_2;
  }
  mu_initialize(param_1,&local_48,*(undefined8 *)(param_1 + 0x170),uVar15);
  lVar13 = *(longlong *)(lVar9 + 0x78);
  _Dst = *(void **)(lVar9 + 0x38);
  do {
    if ((*(longlong **)(param_1 + 0x218) == plVar1) ||
       (plVar8 = *(longlong **)(param_1 + 0x218), plVar8 == plVar1)) {
      plVar8 = (longlong *)0x0;
    }
    else {
      plVar2 = (longlong *)plVar8[1];
      lVar9 = *plVar8;
      *plVar2 = lVar9;
      *(longlong **)(lVar9 + 8) = plVar2;
      plVar8[1] = 0;
      *plVar8 = 0;
    }
    *(undefined1 *)((longlong)plVar8 + 0x3c) = 1;
    plVar8[5] = (longlong)_Dst;
    plVar8[3] = 0;
    *(undefined4 *)((longlong)plVar8 + 0x5d) = 0x8000000;
    *(int *)((longlong)plVar8 + 0x55) = (int)lVar13;
    *(int *)((longlong)plVar8 + 0x59) = (int)((ulonglong)lVar13 >> 0x20);
    uVar7 = *(uint *)((longlong)plVar8 + 0x5d);
    if ((*(byte *)(param_1 + 0xaa) & 0x10) != 0) {
      uVar7 = 0xc000000;
    }
    *(uint *)((longlong)plVar8 + 0x5d) = uVar7;
    if ((uVar7 >> 0x1a & 1) == 0) {
      *(undefined4 *)((longlong)plVar8 + 0x61) = 0x400;
    }
    else {
      *(uint *)((longlong)plVar8 + 0x5d) = uVar7 & 0xffc00400 | 0x400;
    }
    lVar9 = *plVar1;
    *plVar1 = (longlong)plVar8;
    _Dst = (void *)((longlong)_Dst + 0x400);
    lVar13 = lVar13 + 0x400;
    plVar8[1] = (longlong)plVar1;
    *plVar8 = lVar9;
    *(longlong **)(lVar9 + 8) = plVar8;
    lVar16 = lVar16 + -1;
  } while (lVar16 != 0);
  *(longlong *)(param_1 + 0xa70) = lVar13;
  memset(_Dst,-1,0x4000);
  return;
}



===== hba_module_start @ 0001455c =====

void hba_module_start(undefined8 *param_1)

{
  longlong *plVar1;
  longlong lVar2;
  
  timer_check_request((undefined8 *)*param_1);
  plVar1 = (longlong *)param_1[0x2f];
  lVar2 = plVar1[1];
  *(undefined4 *)((ulonglong)*(uint *)(lVar2 + 0x1a8) + *plVar1) =
       *(undefined4 *)((ulonglong)*(uint *)(lVar2 + 0x1a8) + *plVar1);
  LOCK();
  UNLOCK();
  *(undefined4 *)((ulonglong)*(uint *)(lVar2 + 0x1ac) + *plVar1) = 0x3fffffff;
  LOCK();
  UNLOCK();
  *(uint *)(lVar2 + 0x5c) = *(uint *)(lVar2 + 0x5c) | *(uint *)(lVar2 + 500);
  *(uint *)((ulonglong)*(uint *)(lVar2 + 0x184) + *plVar1) =
       *(uint *)((ulonglong)*(uint *)(lVar2 + 0x184) + *plVar1) | *(uint *)(lVar2 + 500);
  LOCK();
  UNLOCK();
  *(undefined1 *)(lVar2 + 0x58) = 0;
  mu_check_handshake(param_1,0,0,plVar1);
  return;
}



===== hba_module_notification @ 000145f4 =====

void hba_module_notification(undefined8 *param_1,undefined8 *param_2,int param_3,undefined8 param_4)

{
  if (param_3 < 3) {
    StorPortNotification(7,*param_1);
  }
  else if (param_3 == 3) {
    FUN_00013c14((longlong)param_1,*(uint *)((longlong)param_2 + 0xc),
                 (ulonglong)*(ushort *)(param_2 + 2),
                 CONCAT71((int7)((ulonglong)param_4 >> 8),*(undefined1 *)((longlong)param_2 + 0x12))
                 ,*(byte *)((longlong)param_2 + 0x13),(undefined4 *)*param_2,
                 *(byte *)((longlong)param_2 + 0x14),(void *)param_2[3]);
    return;
  }
  return;
}



===== mvGetEvent @ 00014654 =====

void mvGetEvent(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  byte *pbVar2;
  longlong lVar3;
  longlong *plVar4;
  byte bVar5;
  
  pbVar2 = *(byte **)(param_2 + 0x18);
  bVar5 = 0;
  *pbVar2 = 0;
  if (*(char *)(param_1 + 0x16d) != '\0') {
    handle_waited_event(param_1);
  }
  if (*(char *)(param_1 + 0x16c) != '\0') {
    for (; (*(longlong **)(param_1 + 0x140) != (longlong *)(param_1 + 0x138) && (bVar5 < 6));
        bVar5 = bVar5 + 1) {
      plVar4 = *(longlong **)(param_1 + 0x140);
      if (plVar4 == (longlong *)(param_1 + 0x138)) {
        plVar4 = (longlong *)0x0;
      }
      else {
        plVar1 = (longlong *)plVar4[1];
        lVar3 = *plVar4;
        *plVar1 = lVar3;
        *(longlong **)(lVar3 + 8) = plVar1;
        plVar4[1] = 0;
        *plVar4 = 0;
      }
      lVar3 = plVar4[3];
      *(longlong *)(pbVar2 + (ulonglong)bVar5 * 0x40 + 4) = plVar4[2];
      *(longlong *)(pbVar2 + (ulonglong)bVar5 * 0x40 + 4 + 8) = lVar3;
      lVar3 = plVar4[5];
      *(longlong *)(pbVar2 + (ulonglong)bVar5 * 0x40 + 0x14) = plVar4[4];
      *(longlong *)(pbVar2 + (ulonglong)bVar5 * 0x40 + 0x14 + 8) = lVar3;
      *(char *)(param_1 + 0x16c) = *(char *)(param_1 + 0x16c) + -1;
      plVar1 = (longlong *)(param_1 + 0x158);
      lVar3 = *plVar1;
      *plVar1 = (longlong)plVar4;
      plVar4[1] = (longlong)plVar1;
      *plVar4 = lVar3;
      *(longlong **)(lVar3 + 8) = plVar4;
    }
    *pbVar2 = bVar5;
  }
  *(undefined1 *)(param_2 + 4) = 0;
  return;
}



===== hba_get_time_in_second @ 00014720 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong hba_get_time_in_second(void)

{
  longlong local_res8 [4];
  
  local_res8[0] = _DAT_fffff78000000014;
  ExSystemTimeToLocalTime(local_res8,local_res8);
  local_res8[0] = SUB168(SEXT816(-0x29406b2a1a85bd43) * SEXT816(local_res8[0]),8) + local_res8[0];
  return ((local_res8[0] >> 0x17) + -0x2b6109100) - (local_res8[0] >> 0x3f);
}



===== handle_clob @ 0001477c =====

undefined8 handle_clob(undefined8 *param_1,longlong *param_2,ulonglong param_3,undefined8 param_4)

{
  longlong *plVar1;
  longlong *plVar2;
  undefined8 *puVar3;
  longlong lVar4;
  longlong lVar5;
  byte *pbVar6;
  code *pcVar7;
  byte bVar8;
  undefined8 uVar9;
  ulonglong uVar10;
  char cVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong *plVar14;
  byte *pbVar15;
  byte *local_38;
  int local_2c;
  undefined2 local_28;
  byte local_26;
  undefined1 local_25;
  byte local_24;
  byte *local_20;
  
  lVar4 = param_1[0x2f];
  plVar13 = (longlong *)(lVar4 + 0xa8);
  if (*(longlong **)(lVar4 + 0xb0) != plVar13) {
    plVar1 = (longlong *)(lVar4 + 0x98);
    do {
      if (*(int *)(lVar4 + 0x8c) == 0) {
        pcVar7 = (code *)swi(3);
        uVar9 = (*pcVar7)();
        return uVar9;
      }
      plVar12 = *(longlong **)(lVar4 + 0xb0);
      if (plVar12 == plVar13) {
        plVar12 = (longlong *)0x0;
      }
      else {
        plVar14 = (longlong *)plVar12[1];
        lVar5 = *plVar12;
        *plVar14 = lVar5;
        *(longlong **)(lVar5 + 8) = plVar14;
        plVar12[1] = 0;
        *plVar12 = 0;
      }
      if (*(short *)((longlong)plVar12 + 0x12) == -1) {
        plVar14 = (longlong *)0x0;
        param_3 = 0xffff;
      }
      else {
        if (*(char *)((longlong)param_1 + 0x22e) == '\x01') {
          param_2 = (longlong *)
                    ((ulonglong)
                     ((uint)*(ushort *)(param_1 + 0x45) +
                     (uint)*(ushort *)((longlong)param_1 + 0x22c)) %
                    (ulonglong)(longlong)(int)(uint)*(ushort *)((longlong)param_1 + 0x22a));
          uVar10 = (ulonglong)(int)param_2;
        }
        else {
          uVar10 = (ulonglong)*(ushort *)(param_1 + 0x45);
        }
        *(short *)(param_1[0x44] + uVar10 * 2) = *(short *)((longlong)plVar12 + 0x12);
        *(short *)(param_1 + 0x45) = *(short *)(param_1 + 0x45) + 1;
        param_3 = (ulonglong)*(ushort *)((longlong)plVar12 + 0x12);
        plVar14 = (longlong *)param_1[param_3 + 0x46];
      }
      if (plVar14 != (longlong *)0x0) {
        param_1[param_3 + 0x46] = 0;
        lVar5 = plVar14[3];
        if (lVar5 != 0) {
          cVar11 = *(char *)((longlong)plVar12 + 0x14);
          if (cVar11 == '\0') {
            *(undefined1 *)(lVar5 + 4) = 0;
          }
          else if (cVar11 == '\b') {
            *(undefined1 *)(lVar5 + 4) = 3;
          }
          else if (cVar11 == '\x02') {
            bVar8 = *(byte *)((longlong)plVar12 + 0x1a) & 0xf;
            if ((bVar8 == 4) && (*(char *)((longlong)plVar12 + 0x24) == '\x05')) {
              *(undefined1 *)(lVar5 + 4) = 6;
            }
            else if (bVar8 == 5) {
              if (*(char *)((longlong)plVar12 + 0x24) == '$') {
                *(undefined1 *)(lVar5 + 4) = 2;
              }
              else {
                *(undefined1 *)(lVar5 + 4) = 4;
              }
            }
            else {
              uVar10 = CONCAT71((int7)((ulonglong)param_2 >> 8),
                                -((*(byte *)((longlong)plVar12 + 0x15) & 1) != 0)) &
                       0xffffffffffffff08;
              cVar11 = (char)uVar10 + '\b';
              param_2 = (longlong *)CONCAT71((int7)(uVar10 >> 8),cVar11);
              *(char *)(lVar5 + 4) = cVar11;
            }
          }
          if (((*(byte *)((longlong)plVar12 + 0x15) & 1) == 0) ||
             (*(char *)((longlong)plVar12 + 0x14) != '\x02')) {
            if (((*(byte *)((longlong)plVar12 + 0x15) & 2) != 0) &&
               (*(char *)((longlong)plVar12 + 0x14) == '\0')) {
              *(int *)(lVar5 + 0x10) = (int)plVar12[3];
            }
          }
          else {
            param_3 = (ulonglong)*(byte *)(lVar5 + 0xb);
            param_2 = plVar12 + 3;
            memcpy(*(void **)(lVar5 + 0x20),param_2,param_3);
          }
        }
        plVar2 = param_1 + 0x25;
        lVar5 = *plVar2;
        *plVar2 = (longlong)plVar14;
        plVar14[1] = (longlong)plVar2;
        *plVar14 = lVar5;
        *(longlong **)(lVar5 + 8) = plVar14;
      }
      *(int *)(lVar4 + 0x8c) = *(int *)(lVar4 + 0x8c) + -1;
      lVar5 = *plVar1;
      *plVar1 = (longlong)plVar12;
      *plVar12 = lVar5;
      plVar12[1] = (longlong)plVar1;
      *(longlong **)(lVar5 + 8) = plVar12;
    } while (*(longlong **)(lVar4 + 0xb0) != plVar13);
  }
  plVar13 = (longlong *)param_1[0x26];
  while (plVar13 != param_1 + 0x25) {
    plVar13 = (longlong *)param_1[0x26];
    if (plVar13 == param_1 + 0x25) {
      plVar13 = (longlong *)0x0;
    }
    else {
      plVar1 = (longlong *)plVar13[1];
      lVar4 = *plVar13;
      *plVar1 = lVar4;
      *(longlong **)(lVar4 + 8) = plVar1;
      plVar13[1] = 0;
      *plVar13 = 0;
    }
    param_2 = (longlong *)plVar13[3];
    if (param_2 == (longlong *)0x0) {
      if (*(char *)((longlong)plVar13 + 0x45) == -0xc) {
        pbVar6 = (byte *)plVar13[5];
        if ((pbVar6 != (byte *)0x0) && (*pbVar6 != 0)) {
          local_25 = 4;
          pbVar15 = pbVar6 + 0x24;
          uVar10 = (ulonglong)*pbVar6;
          do {
            local_28 = *(undefined2 *)(pbVar15 + -0x12);
            local_24 = *pbVar15;
            local_2c = *(int *)(pbVar15 + -0x18);
            local_26 = pbVar15[-0x14];
            local_38 = pbVar15 + -0x10;
            if (local_24 == 0) {
              local_24 = 0;
            }
            else {
              if (0x1e < local_24) {
                local_24 = 0x1e;
              }
              local_20 = pbVar15 + 2;
            }
            if (local_2c != -1) {
              param_3 = 3;
              hba_module_notification(param_1,&local_38,3,param_4);
            }
            pbVar15 = pbVar15 + 0x40;
            uVar10 = uVar10 - 1;
          } while (uVar10 != 0);
        }
        if (*(char *)((longlong)param_1 + 0x16d) != '\0') {
          handle_waited_event((longlong)param_1);
        }
        puVar3 = param_1 + 0x42;
        param_2 = (longlong *)*puVar3;
        *puVar3 = plVar13;
        plVar13[1] = (longlong)puVar3;
        *plVar13 = (longlong)param_2;
        param_2[1] = (longlong)plVar13;
      }
    }
    else {
      hba_request_callback(param_1,(longlong)param_2,param_3,param_4);
    }
    plVar13 = (longlong *)param_1[0x26];
  }
  uVar9 = hba_handle_waiting_list(param_1,param_2,param_3,param_4);
  return CONCAT71((int7)((ulonglong)uVar9 >> 8),1);
}



===== hba_interrupt_service_routine @ 00014a78 =====

bool hba_interrupt_service_routine
               (undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  longlong *plVar2;
  ulonglong uVar3;
  
  uVar3 = (ulonglong)*(uint *)((ulonglong)*(uint *)(param_1 + 0x30) + param_1[0x2e]);
  uVar1 = (*(uint *)((longlong)param_1 + 500) | *(uint *)(param_1 + 0x3e)) &
          *(uint *)((ulonglong)*(uint *)(param_1 + 0x30) + param_1[0x2e]);
  plVar2 = (longlong *)(ulonglong)uVar1;
  if (uVar1 != 0) {
    mu_isr((longlong *)param_1[0x2f],uVar1,uVar3,param_4);
  }
  if (*(int *)(param_1 + 0x13) == 3) {
    handle_clob(param_1,plVar2,uVar3,param_4);
  }
  return uVar1 != 0;
}



===== hba_clear_int @ 00014ad8 =====

undefined8 hba_clear_int(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  undefined1 uVar6;
  
  uVar6 = 0;
  puVar4 = (uint *)((ulonglong)*(uint *)(param_1 + 0x180) + *(longlong *)(param_1 + 0x170));
  uVar5 = (*(uint *)(param_1 + 500) | *(uint *)(param_1 + 0x1f0)) & *puVar4;
  if (uVar5 != 0) {
    *(uint *)(param_1 + 0x60) = *(uint *)(param_1 + 0x60) | uVar5;
    plVar1 = *(longlong **)(param_1 + 0x178);
    uVar6 = 1;
    lVar2 = plVar1[1];
    if ((*(uint *)(lVar2 + 500) & uVar5) != 0) {
      uVar3 = *(uint *)((ulonglong)*(uint *)(lVar2 + 0x1a8) + *plVar1);
      *(uint *)((longlong)plVar1 + 0x44) = *(uint *)((longlong)plVar1 + 0x44) | uVar3;
      *(uint *)((ulonglong)*(uint *)(lVar2 + 0x1a8) + *plVar1) = uVar3;
      LOCK();
      UNLOCK();
    }
    uVar3 = *(uint *)(lVar2 + 0x1f0) | 0x40;
    puVar4 = (uint *)(ulonglong)uVar3;
    if ((uVar5 & uVar3) != 0) {
      puVar4 = (uint *)((ulonglong)*(uint *)(lVar2 + 0x1e4) + *plVar1);
      uVar5 = *puVar4;
      *(uint *)(plVar1 + 9) = *(uint *)(plVar1 + 9) | uVar5;
      uVar5 = (*(uint *)(lVar2 + 0x208) | *(uint *)(lVar2 + 0x204) | 0x110) & uVar5;
      if (uVar5 != 0) {
        *(uint *)((ulonglong)*(uint *)(lVar2 + 0x1e4) + *plVar1) = uVar5;
        LOCK();
        UNLOCK();
      }
    }
  }
  return CONCAT71((int7)((ulonglong)puVar4 >> 8),uVar6);
}



===== hba_isr_dpc_routine @ 00014b90 =====

void hba_isr_dpc_routine(undefined8 param_1,undefined8 *param_2)

{
  int iVar1;
  uint uVar2;
  longlong *plVar3;
  longlong lVar4;
  longlong *plVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  undefined1 local_28 [32];
  
  plVar3 = (longlong *)param_2[0x2f];
  memset(local_28,0,0x20);
  if (*(int *)(param_2 + 0xc) != 0) {
    uVar7 = 0;
    uVar6 = 2;
    StorPortNotification(0x1003,param_2,2,0,local_28);
    plVar5 = (longlong *)(ulonglong)*(uint *)((longlong)plVar3 + 0x44);
    if (*(uint *)((longlong)plVar3 + 0x44) != 0) {
      mu_handle_drbl_int(plVar3,(ulonglong)plVar5,uVar6,uVar7);
      *(undefined4 *)((longlong)plVar3 + 0x44) = 0;
    }
    if ((int)plVar3[9] != 0) {
      if (*(int *)((longlong)plVar3 + 0x94) == 3) {
        mu_receive_outb_list_entry(plVar3);
      }
      *(undefined4 *)(plVar3 + 9) = 0;
    }
    if (*(int *)(param_2 + 0x13) == 3) {
      handle_clob(param_2,plVar5,uVar6,uVar7);
    }
    *(undefined4 *)(param_2 + 0xc) = 0;
    StorPortNotification(0x1004,param_2,local_28);
  }
  StorPortNotification(0x1003,param_2,3,0,local_28);
  iVar1 = *(int *)((longlong)param_2 + 0x5c);
  lVar4 = *(longlong *)param_2[0x2f];
  uVar2 = *(uint *)((longlong)param_2 + 0x184);
  do {
    *(int *)((ulonglong)uVar2 + lVar4) = iVar1;
    LOCK();
    UNLOCK();
  } while (*(int *)((ulonglong)uVar2 + lVar4) != iVar1);
  *(undefined1 *)(param_2 + 0xb) = 0;
  StorPortNotification(0x1004,param_2,local_28);
  return;
}



===== timer_check_request @ 00014c94 =====

void timer_check_request(undefined8 *param_1)

{
  longlong lVar1;
  ulonglong uVar2;
  ushort uVar3;
  
  param_1[0x1d] = param_1[0x1d] + 500;
  uVar3 = 0;
  if (*(short *)(param_1 + 0x1a) != 0) {
    do {
      lVar1 = *(longlong *)(param_1[0x19] + (ulonglong)uVar3 * 8);
      if (((lVar1 != 0) && (*(char *)(lVar1 + 0x30) != '\0')) &&
         (*(ulonglong *)(lVar1 + 0x38) <= (ulonglong)param_1[0x1d])) {
        (**(code **)(lVar1 + 0x28))(*(undefined8 *)(lVar1 + 0x10),*(undefined8 *)(lVar1 + 0x18));
        if (*(char *)(lVar1 + 0x30) != '\0') {
          *(undefined1 *)(lVar1 + 0x30) = 0;
          if (*(char *)((longlong)param_1 + 0xe6) == '\x01') {
            uVar2 = (ulonglong)
                    (int)((ulonglong)
                          ((uint)*(ushort *)((longlong)param_1 + 0xe4) +
                          (uint)*(ushort *)(param_1 + 0x1c)) %
                         (ulonglong)(longlong)(int)(uint)*(ushort *)((longlong)param_1 + 0xe2));
          }
          else {
            uVar2 = (ulonglong)*(ushort *)(param_1 + 0x1c);
          }
          *(ushort *)(param_1[0x1b] + uVar2 * 2) = uVar3;
          *(short *)(param_1 + 0x1c) = *(short *)(param_1 + 0x1c) + 1;
        }
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(ushort *)(param_1 + 0x1a));
  }
                    /* WARNING: Could not recover jumptable at 0x00014d7d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortNotification(6,*param_1,timer_check_request,500000);
  return;
}



===== hba_translate_req_status_to_os_status @ 00014d84 =====

void hba_translate_req_status_to_os_status(undefined8 param_1,longlong param_2)

{
  undefined1 *puVar1;
  bool bVar2;
  byte bVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  
  puVar1 = *(undefined1 **)(param_2 + 0x20);
  bVar3 = *(byte *)(param_2 + 4);
  bVar2 = true;
  if ((puVar1 == (undefined1 *)0x0) || (*(byte *)(param_2 + 0xb) < 0x12)) {
    bVar2 = false;
  }
  uVar5 = 4;
  uVar4 = 4;
  if (bVar3 < 6) {
    if (bVar3 < 4) {
      if (bVar3 == 0) {
        uVar5 = 1;
      }
      else if (bVar3 == 1) {
        if (bVar2) {
          bVar3 = puVar1[2] & 0xf2 | 2;
LAB_00014dd9:
          uVar5 = 2;
          puVar1[7] = 0xb;
          *puVar1 = 0xf0;
          uVar4 = 0x84;
          puVar1[2] = bVar3;
          *(undefined2 *)(puVar1 + 0xc) = 0;
          goto LAB_00014e39;
        }
        uVar5 = 5;
      }
      else if (bVar3 == 2) {
        if (bVar2) {
          bVar3 = puVar1[2] & 0xf3 | 3;
          goto LAB_00014dd9;
        }
      }
      else if (bVar3 == 3) {
        uVar5 = 8;
        goto LAB_00014e39;
      }
    }
    else {
      uVar5 = 6;
    }
  }
  else if (bVar3 == 6) {
    uVar5 = 10;
  }
  else if (bVar3 == 7) {
    if (bVar2) goto LAB_00014e26;
  }
  else if ((bVar3 != 8) && (bVar3 == 0x10)) {
LAB_00014e26:
    uVar5 = 2;
    uVar4 = 0x84;
    goto LAB_00014e39;
  }
  uVar4 = uVar5;
  uVar5 = 0;
LAB_00014e39:
  *(undefined1 *)(param_2 + 4) = uVar5;
  *(undefined1 *)(param_2 + 3) = uVar4;
  return;
}



===== FUN_00014e44 @ 00014e44 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00014e44(undefined8 param_1,longlong param_2,longlong param_3,ulonglong param_4)

{
  ushort uVar1;
  undefined4 uVar2;
  code *pcVar3;
  ushort uVar4;
  short sVar5;
  uint uVar6;
  undefined2 *puVar7;
  ulonglong uVar8;
  undefined4 *puVar9;
  longlong lVar10;
  undefined8 uVar11;
  uint uVar12;
  short *psVar13;
  int iVar14;
  undefined2 *_Dst;
  uint *puVar15;
  undefined1 auStack_78 [30];
  short sStack_5a;
  undefined8 local_58;
  undefined8 local_50;
  undefined4 local_48;
  undefined2 local_44;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_78;
  local_58 = 0;
  local_50 = 0;
  local_48 = 0;
  local_44 = 0;
  if ((param_3 != 0) && (param_2 != 0)) {
    uVar1 = *(ushort *)(param_3 + 0x66);
    uVar11 = CONCAT71((int7)((ulonglong)param_2 >> 8),0xf0);
    lVar10 = param_3;
    uVar8 = param_4;
    puVar7 = (undefined2 *)IoAllocateErrorLogEntry(param_2);
    if (puVar7 == (undefined2 *)0x0) {
      MV_PRINT("Event Log packet allocate Failed!\n",uVar11,lVar10,uVar8);
    }
    else {
      uVar2 = *(undefined4 *)(param_3 + 0x48);
      *(undefined8 *)(puVar7 + 8) = 0;
      *puVar7 = 0;
      *(undefined4 *)(puVar7 + 6) = uVar2;
      *(undefined8 *)(puVar7 + 0xc) = 0;
      uVar8 = 0;
      puVar7[1] = *(short *)(param_3 + 100) << 2;
      uVar11 = 4;
      if (*(short *)(param_3 + 100) != 0) {
        puVar9 = (undefined4 *)(puVar7 + 0x14);
        do {
          uVar12 = (int)uVar8 + 1;
          uVar8 = (ulonglong)uVar12;
          *puVar9 = *(undefined4 *)((param_3 - (longlong)puVar7) + 0x40 + (longlong)puVar9);
          puVar9 = puVar9 + 1;
        } while ((int)uVar12 < (int)(uint)*(ushort *)(param_3 + 100));
      }
      if (puVar7[1] == 0) {
        puVar7[1] = 4;
      }
      iVar14 = 0;
      uVar4 = (((ushort)puVar7[1] >> 2) + 0xb) * 4;
      puVar7[3] = uVar4;
      _Dst = (undefined2 *)((ulonglong)uVar4 + (longlong)puVar7);
      puVar7[2] = (ushort)*(byte *)(param_3 + 0x4c);
      if (*(char *)(param_3 + 0x4c) != '\0') {
        puVar15 = (uint *)(param_3 + 0x50);
        do {
          lVar10 = 1;
          if ((uVar1 & 1 << ((byte)iVar14 & 0x1f)) == 0) {
            uVar12 = *puVar15;
            uVar8 = (ulonglong)uVar12 / 10;
            if ((int)uVar8 != 0) {
              do {
                lVar10 = lVar10 + 1;
                uVar8 = uVar8 / 10;
              } while ((int)uVar8 != 0);
              if (10 < lVar10) {
                pcVar3 = (code *)swi(3);
                (*pcVar3)();
                return;
              }
            }
            *(undefined2 *)(auStack_78 + lVar10 * 2 + 0x20) = 0;
            if (lVar10 != 0) {
              psVar13 = (short *)(auStack_78 + lVar10 * 2 + 0x1e);
              uVar8 = (ulonglong)uVar12;
              do {
                *psVar13 = (short)uVar8 + (short)(uVar8 / 10) * -10 + 0x30;
                psVar13 = psVar13 + -1;
                lVar10 = lVar10 + -1;
                uVar8 = uVar8 / 10;
              } while (lVar10 != 0);
            }
          }
          else {
            uVar12 = *puVar15;
            uVar8 = (ulonglong)(uVar12 >> 4);
            if (uVar12 >> 4 != 0) {
              do {
                uVar8 = uVar8 >> 4;
                lVar10 = lVar10 + 1;
              } while ((int)uVar8 != 0);
              if (10 < lVar10) {
                pcVar3 = (code *)swi(3);
                (*pcVar3)();
                return;
              }
            }
            *(undefined2 *)(auStack_78 + lVar10 * 2 + 0x20) = 0;
            if (lVar10 != 0) {
              psVar13 = (short *)(auStack_78 + lVar10 * 2 + 0x1e);
              do {
                uVar6 = uVar12 & 0xf;
                if (uVar6 == 10) {
                  sVar5 = 0x61;
                }
                else if (uVar6 == 0xb) {
                  sVar5 = 0x62;
                }
                else if (uVar6 == 0xc) {
                  sVar5 = 99;
                }
                else if (uVar6 == 0xd) {
                  sVar5 = 100;
                }
                else if (uVar6 == 0xe) {
                  sVar5 = 0x65;
                }
                else if (uVar6 == 0xf) {
                  sVar5 = 0x66;
                }
                else {
                  sVar5 = ((ushort)uVar12 & 0xf) + 0x30;
                }
                *psVar13 = sVar5;
                uVar12 = uVar12 >> 4;
                psVar13 = psVar13 + -1;
                lVar10 = lVar10 + -1;
              } while (lVar10 != 0);
            }
          }
          lVar10 = -1;
          do {
            lVar10 = lVar10 + 1;
          } while (*(short *)(auStack_78 + lVar10 * 2 + 0x20) != 0);
          uVar8 = (ulonglong)(byte)((byte)lVar10 * '\x02');
          memcpy(_Dst,&local_58,uVar8);
          puVar15 = puVar15 + 1;
          _Dst[(byte)lVar10 & 0x7f] = 0;
          _Dst = _Dst + ((byte)lVar10 & 0x7f) + 1;
          iVar14 = iVar14 + 1;
          uVar11 = 0xf;
        } while (iVar14 < (int)(uint)*(byte *)(param_3 + 0x4c));
      }
      *(undefined4 *)(puVar7 + 0x14) = *(undefined4 *)(param_3 + 0x48);
      IoWriteErrorLogEntry(puVar7);
      if ((uint)param_4 < 0x14) {
        MV_PRINT("Valid entry, entry=%d!\n",param_4 & 0xffffffff,uVar8,uVar11);
        LOCK();
        (&DAT_00017460)[(param_4 & 0xffffffff) * 0x1e] =
             (&DAT_00017460)[(param_4 & 0xffffffff) * 0x1e] + -1;
        UNLOCK();
      }
      else {
        MV_PRINT("Big Panic, wrong entry=%d.!\n",param_4 & 0xffffffff,uVar8,uVar11);
      }
    }
  }
  return;
}



===== MvGenerateSysMsg @ 00015128 =====

void MvGenerateSysMsg(uint param_1,ushort param_2,undefined8 param_3,ulonglong param_4,
                     undefined4 *param_5,char param_6,longlong param_7,uint *param_8)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 *puVar3;
  ulonglong uVar4;
  byte bVar5;
  bool bVar6;
  
  uVar2 = (uint)param_3 & 0xff;
  bVar5 = 0;
  if (uVar2 == 1) {
    bVar5 = 3;
  }
  else if (uVar2 == 2) {
    bVar5 = 2;
  }
  else if (uVar2 == 3) {
    bVar5 = 1;
  }
  uVar2 = (uint)bVar5 << 0x1e | 0x20000000 | param_1 & 0xfffffff;
  *param_8 = uVar2;
  if (param_1 == 0x10002) {
    bVar6 = uVar2 == 0x60010002;
  }
  else if (param_1 == 0x10003) {
    bVar6 = uVar2 == 0xa0010003;
  }
  else if (param_1 == 0x10028) {
    bVar6 = uVar2 == 0x60010028;
  }
  else if (param_1 == 0x1002d) {
    bVar6 = uVar2 == 0x6001002d;
  }
  else if (param_1 == 0x20002) {
    bVar6 = uVar2 == 0xa0020002;
  }
  else if (param_1 == 0x20003) {
    bVar6 = uVar2 == 0xa0020003;
  }
  else {
    if (param_1 != 0x20004) goto LAB_000151e7;
    bVar6 = uVar2 == 0x60020004;
  }
  if (!bVar6) {
    MV_PRINT("MRU event ID=0x%x Can\'t get the matched SystemMsg, check it for details.\n",
             (ulonglong)param_1,param_3,param_4);
  }
LAB_000151e7:
  *(undefined1 *)(param_8 + 1) = 1;
  param_8[2] = (uint)param_2;
  if ((char)param_4 != '\0') {
    uVar4 = param_4 & 0xff;
    puVar3 = param_5;
    do {
      uVar1 = *puVar3;
      puVar3 = puVar3 + 1;
      *(undefined4 *)((longlong)param_8 + (8 - (longlong)param_5) + (longlong)puVar3) = uVar1;
      *(char *)(param_8 + 1) = (char)param_8[1] + '\x01';
      uVar4 = uVar4 - 1;
    } while (uVar4 != 0);
  }
  if ((param_6 != '\0') && (param_7 != 0)) {
    param_8[(ulonglong)(byte)param_8[1] + 2] = *(byte *)(param_7 + 2) & 0xf;
    param_8[(ulonglong)(byte)param_8[1] + 2] = (uint)*(byte *)(param_7 + 0xc);
    *(char *)(param_8 + 1) = (char)param_8[1] + '\x01';
    param_8[(ulonglong)(byte)param_8[1] + 2] = (uint)*(byte *)(param_7 + 0xd);
    *(char *)(param_8 + 1) = (char)param_8[1] + '\x01';
  }
  return;
}



===== MvLogEvent @ 00015268 =====

ulonglong MvLogEvent(uint *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int *piVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  int iVar5;
  longlong lVar6;
  
  piVar1 = &DAT_00017460;
  iVar5 = 0;
  do {
    if (*piVar1 == 0) {
      lVar6 = (longlong)iVar5;
      lVar2 = lVar6 * 0x78;
      piVar1 = &DAT_00017460 + lVar6 * 0x1e;
      LOCK();
      *piVar1 = *piVar1 + 1;
      UNLOCK();
      if (piVar1 != (int *)0x0) {
        memcpy((void *)(lVar2 + 0x174a8),param_1,0x1c);
        *(short *)(&DAT_000174c6 + lVar2) = (short)param_4;
        *(undefined2 *)(&DAT_000174c4 + lVar2) = 0;
        uVar4 = KeInsertQueueDpc(&DAT_00017468 + lVar2,piVar1,lVar6);
        return CONCAT71((int7)((ulonglong)uVar4 >> 8),1);
      }
      break;
    }
    piVar1 = piVar1 + 0x1e;
    iVar5 = iVar5 + 1;
  } while ((longlong)piVar1 < 0x17dc0);
  uVar3 = MV_PRINT("Event Log overflow when trying to log event=0x%x!\n",(ulonglong)*param_1,
                   &DAT_00017460,param_4);
  return uVar3 & 0xffffffffffffff00;
}



===== entry @ 00015310 =====

void entry(longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2,(undefined1 *)param_1,param_4);
  return;
}



===== __security_check_cookie @ 00015340 =====

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



===== __GSHandlerCheck @ 00015360 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 00015380 =====

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



===== _guard_check_icall @ 000153f0 =====

void _guard_check_icall(void)

{
  return;
}



===== memcpy @ 00015400 =====

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
        if (uVar12 == 0) goto LAB_000155b7;
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
LAB_000155b7:
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
      if (uVar12 == 0) goto LAB_00015412;
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
LAB_00015412:
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



===== memset @ 00015740 =====

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
      if (uVar5 == 0) goto LAB_00015800;
      puVar3 = puVar3 + (uVar5 - 8);
      uVar6 = uVar6 + 1;
      switch(uVar5) {
      case 2:
        goto switchD_000157fd_caseD_2;
      case 3:
        goto switchD_000157fd_caseD_3;
      case 4:
        goto switchD_000157fd_caseD_4;
      case 5:
        goto switchD_000157fd_caseD_5;
      case 6:
        goto switchD_000157fd_caseD_6;
      case 7:
        goto switchD_000157fd_caseD_7;
      }
      while( true ) {
        puVar3[7] = uVar4;
        puVar3 = puVar3 + 8;
        uVar6 = uVar6 - 1;
        if (uVar6 == 0) break;
LAB_00015800:
        *puVar3 = uVar4;
switchD_000157fd_caseD_7:
        puVar3[1] = uVar4;
switchD_000157fd_caseD_6:
        puVar3[2] = uVar4;
switchD_000157fd_caseD_5:
        puVar3[3] = uVar4;
switchD_000157fd_caseD_4:
        puVar3[4] = uVar4;
switchD_000157fd_caseD_3:
        puVar3[5] = uVar4;
switchD_000157fd_caseD_2:
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



===== __security_init_cookie @ 00019000 =====

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


