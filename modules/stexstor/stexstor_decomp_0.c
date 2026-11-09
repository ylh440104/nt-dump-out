
===== osi_notification @ 00011008 =====

/* void __cdecl osi_notification(void * __ptr64,enum _comp_noti_type_t,unsigned __int64,unsigned
   __int64) */

void __cdecl
osi_notification(void *param_1,_comp_noti_type_t param_2,__uint64 param_3,__uint64 param_4)

{
  _comp_mgr_t *p_Var1;
  
  if (param_2 == 6) {
    StorPortNotification(7,param_1);
  }
  else if (param_2 == 8) {
    *(undefined4 *)((longlong)param_1 + 0xc4) = 0;
    *(undefined4 *)((longlong)param_1 + 0xc0) = 1;
    *(undefined2 *)((longlong)param_1 + 200) = 0x78;
    StorPortReady();
    if ((gIsLdrDump != '\0') &&
       (p_Var1 = *(_comp_mgr_t **)((longlong)param_1 + 0xb8), p_Var1 != (_comp_mgr_t *)0x0)) {
      *(undefined8 *)((longlong)param_1 + 0xb8) = 0;
      RaidHwStartIo(param_1,p_Var1);
      return;
    }
  }
  return;
}



===== OsiGetCurrentTime @ 00011084 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl OsiGetCurrentTime(struct u64_t * __ptr64,int,unsigned char * __ptr64) */

void __cdecl OsiGetCurrentTime(u64_t *param_1,int param_2,uchar *param_3)

{
  undefined4 uVar1;
  longlong lVar2;
  longlong lVar3;
  longlong local_res8;
  longlong local_res18;
  
  local_res8 = _DAT_fffff78000000014;
  ExSystemTimeToLocalTime(&local_res8,&local_res18);
  local_res18 = SUB168(SEXT816(-0x29406b2a1a85bd43) * SEXT816(local_res18),8) + local_res18;
  lVar3 = ((local_res18 >> 0x17) + -0x2b6109100) - (local_res18 >> 0x3f);
  local_res8 = SUB168(SEXT816(-0x29406b2a1a85bd43) * SEXT816(local_res8),8) + local_res8;
  lVar2 = ((local_res8 >> 0x17) + -0x2b6109100) - (local_res8 >> 0x3f);
  uVar1 = (undefined4)lVar2;
  if (param_2 != 0) {
    uVar1 = (undefined4)lVar3;
  }
  *(undefined4 *)param_1 = uVar1;
  uVar1 = (undefined4)((ulonglong)lVar2 >> 0x20);
  if (param_2 != 0) {
    uVar1 = (undefined4)((ulonglong)lVar3 >> 0x20);
  }
  *(undefined4 *)(param_1 + 4) = uVar1;
  if (lVar3 < lVar2) {
    lVar3 = (lVar2 - lVar3) / 900 + (lVar2 - lVar3 >> 0x3f);
    lVar2 = lVar3 + 0x80;
  }
  else {
    lVar3 = (lVar3 - lVar2) / 900 + (lVar3 - lVar2 >> 0x3f);
    lVar2 = lVar3;
  }
  *param_3 = (char)lVar2 - (char)(lVar3 >> 0x3f);
  return;
}



===== FUN_0001117c @ 0001117c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001117c(longlong param_1,longlong param_2,short *param_3)

{
  int iVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  ulonglong uVar5;
  
  iVar1 = _pprvtData_phyaddr;
  puVar3 = (uint *)(param_3 + 4);
  if (param_2 == param_1 + 0xd0) {
    param_3[8] = 0x20;
    param_3[9] = 0;
    *puVar3 = iVar1 + 0x1c;
    *(undefined4 *)(param_3 + 6) = DAT_000161e4;
    *param_3 = *param_3 + 1;
    *(int *)(param_3 + 2) = *(int *)(param_3 + 2) + *(int *)(param_3 + 8);
  }
  else {
    puVar2 = (uint *)StorPortGetScatterGatherList();
    uVar5 = 0;
    if (puVar2 == (uint *)0x0) {
      *(undefined1 *)(param_2 + 3) = 0x55;
    }
    else if (*puVar2 != 0) {
      do {
        uVar4 = (int)uVar5 + 1;
        puVar3[2] = puVar2[uVar5 * 6 + 6];
        *puVar3 = puVar2[uVar5 * 6 + 4];
        puVar3[1] = puVar2[uVar5 * 6 + 5];
        *param_3 = *param_3 + 1;
        *(uint *)(param_3 + 2) = *(int *)(param_3 + 2) + puVar3[2];
        puVar3 = puVar3 + 3;
        uVar5 = (ulonglong)uVar4;
      } while (uVar4 < *puVar2);
    }
  }
  return;
}



===== FUN_00011238 @ 00011238 =====

/* WARNING: Removing unreachable block (ram,0x00011324) */

undefined8 FUN_00011238(longlong param_1,longlong param_2,longlong param_3)

{
  short sVar1;
  uint uVar2;
  longlong lVar3;
  bool bVar4;
  char cVar5;
  longlong lVar6;
  uint *puVar7;
  undefined1 *puVar8;
  int iVar9;
  short *psVar10;
  uint uVar11;
  ulonglong uVar12;
  short *psVar13;
  
  iVar9 = *(int *)(param_1 + 0x84);
  lVar3 = *(longlong *)(param_2 + 0x30);
  psVar13 = (short *)(param_3 + 0x18);
  bVar4 = false;
  if (iVar9 != 1) {
    if (iVar9 == 2) {
      *(byte *)(param_3 + 3) = *(byte *)(lVar3 + 6) >> 3;
      *(byte *)(param_3 + 2) = *(byte *)(lVar3 + 6) & 7;
    }
    else if (2 < iVar9) {
      if (iVar9 < 5) {
        *(undefined1 *)(param_3 + 3) = *(undefined1 *)(lVar3 + 6);
        *(undefined1 *)(param_3 + 2) = *(undefined1 *)(lVar3 + 7);
        if ((0x78 < *(uint *)(lVar3 + 0x14)) &&
           ((uint)*(ushort *)(param_1 + 200) < *(uint *)(lVar3 + 0x14) * 2)) {
          *(short *)(param_1 + 200) = *(short *)(lVar3 + 0x14) * 2;
        }
      }
      else if (iVar9 == 5) {
        *(undefined1 *)(param_3 + 0x13) = *(undefined1 *)(lVar3 + 6);
        *(undefined1 *)(param_3 + 0x12) = *(undefined1 *)(lVar3 + 7);
        *(undefined1 *)(param_3 + 9) = *(undefined1 *)(lVar3 + 5);
        *(undefined2 *)(param_3 + 10) = *(undefined2 *)(lVar3 + 0x14);
        if ((0x78 < *(uint *)(lVar3 + 0x14)) &&
           ((uint)*(ushort *)(param_1 + 200) < *(uint *)(lVar3 + 0x14) * 2)) {
          *(short *)(param_1 + 200) = *(short *)(lVar3 + 0x14) * 2;
        }
        psVar13 = (short *)(param_3 + 0x28);
      }
    }
    goto LAB_0001134f;
  }
  if (*(char *)(lVar3 + 6) == '\0') {
    cVar5 = *(char *)(lVar3 + 7);
LAB_00011347:
    *(char *)(param_3 + 2) = cVar5;
  }
  else if (*(char *)(lVar3 + 6) == '\x01') {
    cVar5 = *(char *)(lVar3 + 7) + -2;
    goto LAB_00011347;
  }
  *(undefined1 *)(param_3 + 3) = 0;
LAB_0001134f:
  if (*(int *)(param_1 + 0x84) == 5) {
    cVar5 = *(char *)(lVar3 + 2);
    lVar6 = 0;
    if (((((cVar5 == '\x02') && (lVar6 = *(longlong *)(lVar3 + 0x18), lVar6 != 0)) &&
         (*(int *)(lVar6 + 0x10) == 0x10000001)) || (cVar5 == '$')) ||
       ((cVar5 == '\a' &&
        ((*(char *)(lVar3 + 6) == '\0' ||
         ((*(char *)(lVar3 + 6) == *(char *)(param_1 + 0x91) && (*(char *)(lVar3 + 7) == '\0')))))))
       ) {
      bVar4 = true;
      puVar8 = (undefined1 *)(param_2 + 0x50);
      iVar9 = 0x10;
      do {
        puVar8[(param_3 - param_2) + -0x38] = *puVar8;
        puVar8 = puVar8 + 1;
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
    }
    else if (((cVar5 == '\x02') && (lVar6 != 0)) && (*(int *)(lVar6 + 0x10) == 0x10000002)) {
      puVar8 = (undefined1 *)(param_2 + 0x50);
      iVar9 = 0x10;
      do {
        puVar8[(param_3 - param_2) + -0x38] = *puVar8;
        puVar8 = puVar8 + 1;
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
    }
    else {
      puVar8 = (undefined1 *)(lVar3 + 0x48);
      iVar9 = 0x10;
      do {
        puVar8[(param_3 - lVar3) + -0x30] = *puVar8;
        puVar8 = puVar8 + 1;
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
    }
    *(undefined1 *)(param_3 + 0x16) = 0;
    if (!bVar4) {
      if ((*(uint *)(lVar3 + 0xc) & 0x40) != 0) {
        *(undefined1 *)(param_3 + 0x16) = 1;
      }
      if ((char)*(undefined4 *)(lVar3 + 0xc) < '\0') {
        *(byte *)(param_3 + 0x16) = *(byte *)(param_3 + 0x16) | 2;
      }
    }
  }
  else {
    puVar8 = (undefined1 *)(lVar3 + 0x48);
    iVar9 = 0x10;
    do {
      puVar8[(param_3 - lVar3) + -0x40] = *puVar8;
      puVar8 = puVar8 + 1;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
    *(undefined1 *)(param_3 + 6) = 0;
    if ((*(uint *)(lVar3 + 0xc) & 0x40) != 0) {
      *(undefined1 *)(param_3 + 6) = 1;
    }
    if ((char)*(undefined4 *)(lVar3 + 0xc) < '\0') {
      *(byte *)(param_3 + 6) = *(byte *)(param_3 + 6) | 2;
    }
  }
  *psVar13 = 0;
  sVar1 = *(short *)(param_1 + 0x92);
  psVar13[2] = 0;
  psVar13[3] = 0;
  psVar13[1] = sVar1;
  if (*(int *)(lVar3 + 0x10) != 0) {
    if (*(int *)(param_1 + 0x84) == 5) {
      if (!bVar4) {
        FUN_0001117c(param_1,lVar3,psVar13);
      }
    }
    else {
      psVar10 = psVar13 + 4;
      puVar7 = (uint *)StorPortGetScatterGatherList(param_1,lVar3);
      if (puVar7 == (uint *)0x0) {
        *(undefined1 *)(lVar3 + 3) = 0x55;
      }
      else {
        uVar12 = 0;
        if (*puVar7 != 0) {
          do {
            uVar11 = (int)uVar12 + 1;
            *(uint *)(psVar10 + 2) = puVar7[uVar12 * 6 + 6];
            *(uint *)(psVar10 + 4) = puVar7[uVar12 * 6 + 4];
            uVar2 = puVar7[uVar12 * 6 + 5];
            *(undefined1 *)psVar10 = 0x60;
            *(uint *)(psVar10 + 6) = uVar2;
            *psVar13 = *psVar13 + 1;
            *(int *)(psVar13 + 2) = *(int *)(psVar13 + 2) + *(int *)(psVar10 + 2);
            psVar10 = psVar10 + 8;
            uVar12 = (ulonglong)uVar11;
          } while (uVar11 < *puVar7);
        }
        *(byte *)(psVar10 + -8) = *(byte *)(psVar10 + -8) | 0x80;
      }
    }
  }
  return 1;
}



===== FUN_00011518 @ 00011518 =====

void FUN_00011518(longlong param_1,longlong param_2,longlong param_3)

{
  char cVar1;
  uint uVar2;
  longlong lVar3;
  byte *pbVar4;
  undefined4 *puVar5;
  undefined1 uVar6;
  undefined1 *puVar7;
  uint uVar8;
  ulonglong uVar9;
  undefined1 *puVar10;
  undefined4 uVar11;
  
  lVar3 = *(longlong *)(param_2 + 0x30);
  uVar8 = (uint)*(byte *)(param_3 + 7) * 4 - 8;
  *(undefined1 *)(lVar3 + 4) = *(undefined1 *)(param_3 + 5);
  *(undefined1 *)(lVar3 + 3) = *(undefined1 *)(param_3 + 4);
  if ((*(char *)(param_3 + 6) == '\x01') && (uVar8 == 0)) {
    *(undefined4 *)(lVar3 + 0x10) = *(undefined4 *)(param_3 + 8);
  }
  if ((((*(int *)(param_1 + 0x84) - 1U & 0xfffffffb) == 0) && (*(char *)(lVar3 + 4) != '\x02')) &&
     (*(char *)(lVar3 + 0x48) == -0x28)) {
    *(undefined4 *)(lVar3 + 0x10) = *(undefined4 *)(param_3 + 8);
  }
  if (1 < *(byte *)(lVar3 + 3)) goto LAB_00011667;
  if (((*(char *)(lVar3 + 0x48) != '\x12') || (*(char *)(lVar3 + 4) != '\0')) ||
     (pbVar4 = *(byte **)(lVar3 + 0x18), pbVar4 == (byte *)0x0)) {
    if (((*(int *)(param_1 + 0x84) == 3) && (*(char *)(lVar3 + 0x48) == -0x60)) &&
       ((*(char *)(lVar3 + 4) == '\0' &&
        (puVar5 = *(undefined4 **)(lVar3 + 0x18), puVar5 != (undefined4 *)0x0)))) {
      *puVar5 = 0;
      *(undefined1 *)((longlong)puVar5 + 3) = 8;
      *(undefined8 *)(puVar5 + 2) = 0;
    }
    else {
      cVar1 = *(char *)(lVar3 + 4);
      if (cVar1 == '\0') {
        *(undefined1 *)(lVar3 + 3) = 1;
      }
      else if (cVar1 == '\x02') {
        *(undefined1 *)(lVar3 + 3) = 0x84;
      }
      else if (cVar1 == '\b') {
        *(undefined1 *)(lVar3 + 3) = 5;
      }
      else {
        uVar6 = 0xe;
        if (cVar1 != '\x0e') {
          uVar6 = 4;
        }
        *(undefined1 *)(lVar3 + 3) = uVar6;
      }
    }
    goto LAB_00011667;
  }
  uVar2 = *(uint *)(param_1 + 0x84);
  uVar9 = (ulonglong)uVar2;
  if (uVar2 == 3) {
LAB_000115c0:
    if ((*pbVar4 & 0xe0) != 0x60) {
LAB_000115d1:
      *(undefined1 *)(lVar3 + 3) = 1;
      if ((*(int *)(param_1 + 0x84) == 5) &&
         (uVar9 = (ulonglong)CONCAT31((int3)(uVar2 >> 8),*(char *)(lVar3 + 6)),
         *(char *)(lVar3 + 6) != '\0')) {
        uVar11 = 0x80;
      }
      else {
        uVar9 = CONCAT71((int7)(uVar9 >> 8),*(undefined1 *)(lVar3 + 6));
        uVar11 = 0xfe;
      }
      StorPortSetDeviceQueueDepth
                (param_1,CONCAT71((int7)((ulonglong)pbVar4 >> 8),*(undefined1 *)(lVar3 + 5)),uVar9,
                 *(undefined1 *)(lVar3 + 7),uVar11);
      goto LAB_00011667;
    }
  }
  else if ((*pbVar4 & 0xe0) == 0) {
    if (uVar2 == 3) goto LAB_000115c0;
    goto LAB_000115d1;
  }
  *(undefined1 *)(lVar3 + 3) = 10;
LAB_00011667:
  if (uVar8 != 0) {
    if (((*(char *)(lVar3 + 4) == '\0') && (*(char *)(lVar3 + 3) == '\x01')) &&
       (puVar7 = *(undefined1 **)(lVar3 + 0x18), puVar7 != (undefined1 *)0x0)) {
      puVar10 = (undefined1 *)(param_3 + 8);
      uVar2 = *(uint *)(lVar3 + 0x10);
      if (uVar8 < *(uint *)(lVar3 + 0x10)) {
        uVar2 = uVar8;
      }
      for (; uVar2 != 0; uVar2 = uVar2 - 1) {
        uVar6 = *puVar10;
        puVar10 = puVar10 + 1;
        *puVar7 = uVar6;
        puVar7 = puVar7 + 1;
      }
    }
    else if (((*(uint *)(lVar3 + 0xc) & 0x20) == 0) &&
            (puVar7 = *(undefined1 **)(lVar3 + 0x20), puVar7 != (undefined1 *)0x0)) {
      puVar10 = (undefined1 *)(param_3 + 8);
      uVar2 = (uint)*(byte *)(lVar3 + 0xb);
      if (uVar8 < *(byte *)(lVar3 + 0xb)) {
        uVar2 = uVar8;
      }
      for (; uVar2 != 0; uVar2 = uVar2 - 1) {
        uVar6 = *puVar10;
        puVar10 = puVar10 + 1;
        *puVar7 = uVar6;
        puVar7 = puVar7 + 1;
      }
    }
    else {
      pbVar4 = (byte *)(lVar3 + 3);
      *pbVar4 = *pbVar4 & 0x7f;
      uVar6 = *(undefined1 *)(lVar3 + 3);
      if (*pbVar4 == 0) {
        uVar6 = 4;
      }
      *(undefined1 *)(lVar3 + 3) = uVar6;
    }
  }
  return;
}



===== OsdFindBridgeA @ 00011700 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl OsdFindBridgeA(unsigned long,unsigned char * __ptr64,unsigned char * __ptr64) */

void __cdecl OsdFindBridgeA(ulong param_1,uchar *param_2,uchar *param_3)

{
  char cVar1;
  byte bVar2;
  uchar uVar3;
  undefined1 auStack_88 [32];
  int *local_68;
  undefined4 local_60;
  undefined4 local_58;
  int local_48 [6];
  char local_2f;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_88;
  *param_2 = 0xff;
  *param_3 = 0xff;
  uVar3 = '\0';
  do {
    bVar2 = 0;
    do {
      if (DAT_000161d2 != '\0') {
        local_68 = local_48;
        local_58 = 0x20;
        local_60 = 0;
        cVar1 = (*DAT_00016208)(DAT_00016200,uVar3,bVar2,0);
        if ((cVar1 != '\0') &&
           (((local_48[0] == 0x3708086 || (local_48[0] == 0x3358086)) && (local_2f == (char)param_1)
            ))) {
          *param_2 = uVar3;
          *param_3 = bVar2;
          return;
        }
      }
      bVar2 = bVar2 + 1;
    } while (bVar2 < 0x20);
    uVar3 = uVar3 + '\x01';
    if (uVar3 == 0xff) {
      return;
    }
  } while( true );
}



===== GetPCIDeviceInfo @ 000117cc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* unsigned char __cdecl GetPCIDeviceInfo(void * __ptr64,struct _PORT_CONFIGURATION_INFORMATION *
   __ptr64,struct _pci_dev_info_t * __ptr64) */

uchar __cdecl
GetPCIDeviceInfo(void *param_1,_PORT_CONFIGURATION_INFORMATION *param_2,_pci_dev_info_t *param_3)

{
  longlong lVar1;
  uchar uVar2;
  int iVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  uint uVar7;
  undefined1 auStack_178 [32];
  undefined2 *local_158;
  undefined4 local_150;
  undefined2 local_148;
  undefined2 local_146;
  undefined2 local_11c;
  ushort local_11a;
  char local_10a;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_178;
  local_158 = &local_148;
  *(undefined4 *)(param_2 + 0x1c) = 0;
  local_150 = 0x100;
  iVar3 = StorPortGetBusData(param_1,4,*(undefined4 *)(param_2 + 4),*(uint *)(param_2 + 100) & 0x1f)
  ;
  uVar2 = '\0';
  if (iVar3 != 0) {
    *(undefined8 *)(param_3 + 0x30) = 0;
    iVar3 = CONCAT22(local_148,local_146);
    *(int *)(param_3 + 0x48) = iVar3;
    *(uint *)(param_3 + 0x4c) = CONCAT22(local_11c,local_11a);
    *(undefined4 *)(param_3 + 0x38) = *(undefined4 *)(param_2 + 4);
    *(undefined4 *)(param_3 + 0x3c) = *(undefined4 *)(param_2 + 100);
    *(undefined4 *)(param_3 + 0x40) = *(undefined4 *)(param_2 + 0xc);
    *(undefined4 *)(param_3 + 0x44) = *(undefined4 *)(param_2 + 0x10);
    if (iVar3 == _DAT_00016164) {
      iVar3 = 1;
    }
    else if (iVar3 == 0x105a7250) {
      iVar3 = 4 - (uint)((local_11a & 1) != 0);
    }
    else if (iVar3 == 0x105a3360) {
      iVar3 = 3;
    }
    else if (((iVar3 == 0x11f88010) || (iVar3 == 0x105a8750)) || (iVar3 == 0x105a8760)) {
      iVar3 = 5;
    }
    else {
      iVar3 = 2;
    }
    *(int *)(param_3 + 0x54) = iVar3;
    if (iVar3 == 2) {
      OsdFindBridgeA(*(ulong *)(param_3 + 0x38),(uchar *)(param_3 + 0x50),(uchar *)(param_3 + 0x51))
      ;
      if (local_10a == -0x70) {
        *(undefined4 *)(param_2 + 0x1c) = 0x21;
      }
    }
    else {
      param_3[0x50] = (_pci_dev_info_t)0xff;
    }
    uVar7 = 0;
    if (*(int *)(param_2 + 0x34) != 0) {
      do {
        lVar1 = *(longlong *)(param_2 + 0x38);
        uVar5 = (ulonglong)uVar7;
        uVar6 = (ulonglong)uVar7;
        local_150 = CONCAT31(local_150._1_3_,*(char *)(lVar1 + 0xc + uVar5 * 0x10) == '\0');
        local_158 = (undefined2 *)
                    CONCAT44(local_158._4_4_,*(undefined4 *)(lVar1 + 8 + uVar5 * 0x10));
        uVar4 = StorPortGetDeviceBase
                          (param_1,*(undefined4 *)(param_2 + 8),*(undefined4 *)(param_2 + 4),
                           *(undefined8 *)(lVar1 + uVar5 * 0x10));
        uVar7 = uVar7 + 1;
        *(undefined8 *)(param_3 + uVar6 * 8) = uVar4;
      } while (uVar7 < *(uint *)(param_2 + 0x34));
    }
    uVar2 = '\x01';
  }
  return uVar2;
}



===== DriverEntry @ 00011984 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void DriverEntry(longlong param_1,longlong param_2)

{
  int iVar1;
  uint uVar2;
  code *pcVar3;
  _comp_tmpl_t *_Dst;
  int iVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 auStack_3b8 [32];
  undefined8 local_398;
  undefined4 local_388 [2];
  undefined1 *local_380;
  undefined1 local_378 [16];
  undefined4 local_368;
  undefined4 local_364;
  code *local_360;
  code *local_358;
  code *local_350;
  code *local_348;
  code *local_340;
  undefined8 local_338;
  undefined8 local_330;
  int local_328;
  uint local_324;
  int local_320;
  undefined4 local_31c;
  undefined1 local_310;
  undefined4 local_30f;
  code *local_2f0;
  code *local_2e8;
  undefined1 local_298 [8];
  undefined4 local_290;
  wchar_t *local_288;
  int *local_280;
  undefined4 local_278;
  int *local_270;
  undefined4 local_268;
  undefined1 local_228 [512];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_3b8;
  _Dst = (_comp_tmpl_t *)&local_364;
  iVar4 = 0;
  local_368 = 0;
  memset(_Dst,0,0xcc);
  if (param_2 != 0) {
    local_380 = local_228;
    local_388[0] = 0x2000000;
    memset(local_228,0,0x200);
    memset(local_298,0,0x70);
    RtlAppendUnicodeStringToString(local_388,param_2);
    RtlAppendUnicodeToString(local_388,L"\\Parameters\\Device");
    _Dst = (_comp_tmpl_t *)0x0;
    puVar5 = local_380;
    iVar1 = RtlCheckRegistryKey();
    puVar6 = local_380;
    iVar4 = (int)puVar5;
    if (iVar1 == 0) {
      local_288 = L"RESET";
      local_280 = &support_reset;
      local_270 = &support_reset;
      local_278 = 4;
      local_268 = 4;
      local_290 = 0x20;
      RtlInitUnicodeString(local_378,L"RtlQueryRegistryValuesEx");
      pcVar3 = (code *)MmGetSystemRoutineAddress(local_378);
      _Dst = (_comp_tmpl_t *)0x80000000;
      local_398 = 0;
      if (pcVar3 == (code *)0x0) {
        pcVar3 = RtlQueryRegistryValues_exref;
      }
      (*pcVar3)();
      iVar4 = (int)puVar6;
    }
  }
  gIsLdrDump = param_1 == 0;
  DAT_000161f0 = 2;
  uVar2 = compmgr_get_global_rsc_size(_Dst,iVar4,0);
  local_360 = RaidHwInitialize;
  local_328 = uVar2 + 0x578;
  local_358 = RaidHwStartIo;
  local_368 = 0xd0;
  local_350 = RaidHwInterrupt;
  local_338 = 0;
  local_348 = RaidHwFindAdapter;
  local_330 = 0;
  local_340 = RaidHwResetBus;
  pcVar3 = RaidHwScsiAdapterControl;
  local_2f0 = RaidHwScsiAdapterControl;
  local_324 = compmgr_get_global_rsc_size((_comp_tmpl_t *)RaidHwScsiAdapterControl,iVar4,2);
  uVar2 = compmgr_get_global_rsc_size((_comp_tmpl_t *)pcVar3,iVar4,1);
  local_320 = uVar2 + 0x450;
  local_364 = 5;
  local_30f = 0x1010101;
  local_31c = 1;
  local_310 = 2;
  local_2e8 = RaidHwBuildIo;
  StorPortInitialize(param_1,param_2,&local_368,0);
  return;
}



===== RaidReturn @ 00011bb4 =====

/* void __cdecl RaidReturn(void * __ptr64,struct _io_t * __ptr64,enum _io_sts_t) */

void __cdecl RaidReturn(void *param_1,_io_t *param_2,_io_sts_t param_3)

{
  longlong *plVar1;
  longlong lVar2;
  ushort uVar3;
  longlong lVar4;
  
  lVar2 = *(longlong *)(param_2 + 0x30);
  if (((*(char *)(lVar2 + 2) == '\x02') && (*(int *)((longlong)param_1 + 0x84) == 5)) &&
     (*(int *)(*(longlong *)(lVar2 + 0x18) + 0x10) == 0x10000002)) {
    if (*(char *)((longlong)pprvtData + 0x1c) == -0x56) {
      fw_agree2reset = 1;
    }
    else {
      fw_agree2reset = (int)(*(char *)((longlong)pprvtData + 0x1c) != 'U');
    }
    prvtSRBcalled = '\0';
    return;
  }
  if ((uint)*(ushort *)(lVar2 + 0x14) * 2 == (uint)*(ushort *)((longlong)param_1 + 200)) {
    lVar4 = *(longlong *)(*(longlong *)((longlong)param_1 + 0x98) + 0x40);
    lVar2 = *(longlong *)((longlong)param_1 + 0x98) + 0x38;
    uVar3 = 0x78;
    if (lVar4 != lVar2) {
      do {
        plVar1 = (longlong *)(lVar4 + 0x30);
        lVar4 = *(longlong *)(lVar4 + 8);
        if (uVar3 < *(ushort *)(*plVar1 + 0x14)) {
          uVar3 = *(ushort *)(*plVar1 + 0x14);
        }
      } while (lVar4 != lVar2);
      if (0x78 < uVar3) {
        uVar3 = uVar3 * 2;
      }
    }
    *(ushort *)((longlong)param_1 + 200) = uVar3;
  }
                    /* WARNING: Could not recover jumptable at 0x00011c73. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortNotification(0,param_1);
  return;
}



===== RaidHwFindAdapter @ 00011c80 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
RaidHwFindAdapter(_comp_tmpl_t *param_1,int param_2,undefined8 param_3,uint param_4,
                 _PORT_CONFIGURATION_INFORMATION *param_5,undefined1 *param_6)

{
  _comp_tmpl_t _Var1;
  int iVar2;
  longlong lVar3;
  code *pcVar4;
  uchar uVar5;
  uint uVar6;
  int iVar7;
  undefined8 uVar8;
  _comp_tmpl_t *p_Var9;
  _PORT_CONFIGURATION_INFORMATION *p_Var10;
  uint uVar11;
  _comp_tmpl_t *p_Var12;
  size_t _Size;
  longlong lVar13;
  _comp_tmpl_t *in_stack_ffffffffffffffa8;
  int in_stack_ffffffffffffffb0;
  int local_48;
  uint local_44;
  void *local_40;
  int local_38;
  undefined4 local_34;
  
  compmgr_get_global_rsc_size(param_1,param_2,0);
  *param_6 = 1;
  p_Var9 = param_1;
  p_Var10 = param_5;
  uVar5 = GetPCIDeviceInfo(param_1,param_5,(_pci_dev_info_t *)(param_1 + 0x30));
  iVar7 = (int)p_Var10;
  if ((uVar5 == '\0') || (*(longlong *)(param_1 + 0x30) == 0)) {
    return 3;
  }
  *(undefined4 *)(param_1 + 0xc4) = 0;
  *(undefined2 *)(param_1 + 200) = 0x78;
  *(undefined4 *)(param_5 + 0x18) = 0x20000;
  if (*(int *)(param_5 + 0x1c) == 0) {
    uVar6 = *(uint *)(param_1 + 0x84);
    p_Var9 = (_comp_tmpl_t *)(ulonglong)uVar6;
    if (uVar6 == 5) {
      *(undefined4 *)(param_5 + 0x1c) = 0x26;
    }
    else {
      *(uint *)(param_5 + 0x1c) = (uVar6 != 2) + 0x20;
    }
  }
  *(undefined4 *)(param_5 + 0x30) = 3;
  param_5[0x48] = (_PORT_CONFIGURATION_INFORMATION)0x1;
  param_5[0x57] = (_PORT_CONFIGURATION_INFORMATION)0x0;
  param_5[0x91] = (_PORT_CONFIGURATION_INFORMATION)0x0;
  iVar2 = *(int *)(param_1 + 0x84);
  if (iVar2 == 1) {
    param_5[0x61] = (_PORT_CONFIGURATION_INFORMATION)0x2;
  }
  else {
    param_5[0x61] = (_PORT_CONFIGURATION_INFORMATION)0x80;
    if (iVar2 != 5) {
      param_5[0x92] = (_PORT_CONFIGURATION_INFORMATION)0x1;
      goto LAB_00011d5f;
    }
  }
  param_5[0x92] = (_PORT_CONFIGURATION_INFORMATION)0xff;
LAB_00011d5f:
  param_5[0x60] = (_PORT_CONFIGURATION_INFORMATION)0x1;
  param_5[0x90] = (_PORT_CONFIGURATION_INFORMATION)0x1;
  param_5[0x93] = (_PORT_CONFIGURATION_INFORMATION)0x0;
  *(undefined2 *)(param_5 + 0x51) = 0x101;
  param_5[0x53] = (_PORT_CONFIGURATION_INFORMATION)0x1;
  *(undefined4 *)(param_5 + 0x94) = 1;
  *(undefined2 *)(param_1 + 0x92) = *(undefined2 *)(param_5 + 0x1c);
  _Var1 = *(_comp_tmpl_t *)(param_5 + 0x61);
  param_1[0x90] = _Var1;
  param_1[0x91] = (_comp_tmpl_t)((char)_Var1 + -1);
  uVar6 = compmgr_get_global_rsc_size(p_Var9,iVar7,1);
  *(uint *)(param_1 + 0x88) = uVar6;
  uVar6 = compmgr_get_global_rsc_size(p_Var9,iVar7,2);
  *(uint *)(param_1 + 0x8c) = uVar6;
  compmgr_init_components
            ((_comp_mgr_t *)param_1,param_1,param_1 + 0x578,param_4,in_stack_ffffffffffffffa8,
             in_stack_ffffffffffffffb0);
  p_Var12 = *(_comp_tmpl_t **)(param_1 + 0x28);
  p_Var9 = param_1 + 0x20;
  _Size = 0;
  if (p_Var12 != p_Var9) {
    do {
      lVar3 = *(longlong *)((longlong)*(int *)(p_Var12 + 0x18) * 0x10 + *(longlong *)param_1 + 8);
      if ((lVar3 != 0) && (pcVar4 = *(code **)(lVar3 + 8), pcVar4 != (code *)0x0)) {
        iVar7 = (*pcVar4)(p_Var12 + 0x20,4);
        _Size = (size_t)((int)_Size + (iVar7 + 7U & 0xfffffff8));
      }
      p_Var12 = *(_comp_tmpl_t **)(p_Var12 + 8);
    } while (p_Var12 != p_Var9);
    iVar7 = (int)_Size;
    if (iVar7 != 0) {
      local_40 = (void *)StorPortGetUncachedExtension(param_1,param_5,iVar7 + 0x3c);
      if (local_40 == (void *)0x0) {
        return 2;
      }
      pprvtData = (void *)((longlong)local_40 + _Size);
      uVar8 = StorPortGetPhysicalAddress(param_1,0,local_40,&param_6);
      local_48 = 4;
      local_38 = (int)uVar8;
      _pprvtData_phyaddr = iVar7 + local_38;
      DAT_000161e4 = (undefined4)((ulonglong)uVar8 >> 0x20);
      local_44 = iVar7;
      local_34 = DAT_000161e4;
      memset(local_40,0,_Size);
      for (p_Var12 = *(_comp_tmpl_t **)(param_1 + 0x28); p_Var12 != p_Var9;
          p_Var12 = *(_comp_tmpl_t **)(p_Var12 + 8)) {
        lVar13 = (longlong)*(int *)(p_Var12 + 0x18) * 0x10 + *(longlong *)param_1;
        lVar3 = *(longlong *)(lVar13 + 8);
        if ((lVar3 != 0) && (pcVar4 = *(code **)(lVar3 + 8), pcVar4 != (code *)0x0)) {
          iVar7 = (*pcVar4)(p_Var12 + 0x20,local_48);
          uVar6 = local_44;
          uVar11 = iVar7 + 7U & 0xfffffff8;
          if (uVar11 != 0) {
            local_44 = uVar11;
            (**(code **)(*(longlong *)(lVar13 + 8) + 0x10))(p_Var12 + 0x20,&local_48);
            local_44 = uVar6 - uVar11;
            if (local_48 == 4) {
              local_40 = (void *)((longlong)local_40 + (ulonglong)uVar11);
              local_38 = local_38 + uVar11;
            }
          }
        }
      }
    }
  }
  iVar7 = compmgr_search_if((_comp_mgr_t *)param_1,(_guid_t *)&DAT_000150f0,
                            (_if_impl_t *)(param_1 + 0x98),1,in_stack_ffffffffffffffa8);
  if (iVar7 != 0) {
    (**(code **)(*(longlong *)(param_1 + 0xa0) + 8))
              (*(undefined8 *)(param_1 + 0x98),param_1,FUN_00011238,FUN_00011518);
  }
  compmgr_search_if((_comp_mgr_t *)param_1,(_guid_t *)&DAT_00015100,(_if_impl_t *)(param_1 + 0xa8),2
                    ,in_stack_ffffffffffffffa8);
  return 1;
}



===== RaidHwInitialize @ 00011f90 =====

undefined1 RaidHwInitialize(_comp_mgr_t *param_1)

{
  if (gIsLdrDump == '\0') {
    StorPortBusy();
    compmgr_start_component(param_1,(void *)0x0);
  }
  StorPortNotification(6,param_1,RaidHwTimerService,1000000);
  return 1;
}



===== RaidHwResetBus @ 00011fe0 =====

undefined1 RaidHwResetBus(_comp_mgr_t *param_1)

{
  if ((support_reset != 0) && (*(int *)(param_1 + 0x84) == 1)) {
    compmgr_reset_components(param_1,0);
  }
  return 1;
}



===== FUN_0001200c @ 0001200c =====

void FUN_0001200c(void *param_1,_io_t *param_2,_io_sts_t param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  longlong lVar4;
  undefined4 *puVar5;
  
  lVar4 = *(longlong *)(param_2 + 0x30);
  if ((*(char *)(lVar4 + 4) == '\0') && (*(char *)(lVar4 + 3) == '\x01')) {
    puVar2 = *(undefined4 **)(lVar4 + 0x18);
    puVar3 = (undefined4 *)((longlong)param_1 + 0x30);
    lVar4 = 6;
    puVar5 = puVar2;
    do {
      uVar1 = *puVar3;
      puVar3 = puVar3 + 2;
      *puVar5 = uVar1;
      puVar5 = puVar5 + 1;
      lVar4 = lVar4 + -1;
    } while (lVar4 != 0);
    uVar1 = *(undefined4 *)((longlong)param_1 + 0x60);
    puVar2[9] = 0;
    puVar2[7] = 5;
    puVar2[6] = uVar1;
    puVar2[8] = 1;
    puVar2[10] = 10;
    puVar2[0x13] = *(undefined4 *)((longlong)param_1 + 0x68);
    puVar2[0x14] = *(undefined4 *)((longlong)param_1 + 0x6c);
    puVar2[0x15] = *(undefined4 *)((longlong)param_1 + 0x70);
    puVar2[0x16] = *(undefined4 *)((longlong)param_1 + 0x74);
    puVar2[0x17] = *(undefined4 *)((longlong)param_1 + 0x78);
    puVar2[0x18] = *(undefined4 *)((longlong)param_1 + 0x7c);
  }
  RaidReturn(param_1,param_2,param_3);
  return;
}



===== FUN_000120b8 @ 000120b8 =====

undefined8 FUN_000120b8(_comp_mgr_t *param_1,_io_t *param_2)

{
  int iVar1;
  undefined4 uVar2;
  longlong lVar3;
  undefined4 *puVar4;
  _comp_mgr_t *p_Var5;
  longlong lVar6;
  
  p_Var5 = *(_comp_mgr_t **)(param_2 + 0x30);
  lVar6 = 6;
  lVar3 = *(longlong *)(p_Var5 + 0x18);
  p_Var5[3] = (_comp_mgr_t)0x6;
  if ((*(int *)(lVar3 + 4) != 0x54534146) || (*(int *)(lVar3 + 8) != 0x4b415254)) {
    return 4;
  }
  p_Var5[3] = (_comp_mgr_t)0x1;
  iVar1 = *(int *)(lVar3 + 0x10);
  if (iVar1 == 1) {
    if (*(uint *)(lVar3 + 0x18) < 0x28) {
      p_Var5[3] = (_comp_mgr_t)0x4;
    }
    memset((void *)(lVar3 + 0x1c),0,0x28);
    *(undefined4 *)(lVar3 + 0x24) = 0;
    *(undefined4 *)(lVar3 + 0x1c) = 5;
    *(undefined4 *)(lVar3 + 0x20) = 1;
    *(undefined4 *)(lVar3 + 0x28) = 10;
    *(undefined4 *)(lVar3 + 0x2c) = 0x4e415041;
    *(_comp_mgr_t *)(lVar3 + 0x34) = param_1[0x91];
    return 4;
  }
  if (iVar1 == 2) {
    if (*(uint *)(lVar3 + 0x18) < 0x58) {
      p_Var5[3] = (_comp_mgr_t)0x4;
    }
    memset((void *)(lVar3 + 0x1c),0,0x58);
    puVar4 = (undefined4 *)(lVar3 + 0x1c);
    p_Var5 = param_1 + 0x30;
    do {
      uVar2 = *(undefined4 *)p_Var5;
      p_Var5 = p_Var5 + 8;
      *puVar4 = uVar2;
      puVar4 = puVar4 + 1;
      lVar6 = lVar6 + -1;
    } while (lVar6 != 0);
    uVar2 = *(undefined4 *)(param_1 + 0x60);
    *(undefined4 *)(lVar3 + 0x40) = 0;
    *(undefined4 *)(lVar3 + 0x38) = 5;
    *(undefined4 *)(lVar3 + 0x34) = uVar2;
    *(undefined4 *)(lVar3 + 0x3c) = 1;
    *(undefined4 *)(lVar3 + 0x44) = 10;
    *(undefined4 *)(lVar3 + 0x50) = *(undefined4 *)(param_1 + 0x68);
    *(undefined4 *)(lVar3 + 0x54) = *(undefined4 *)(param_1 + 0x6c);
    *(undefined4 *)(lVar3 + 0x58) = *(undefined4 *)(param_1 + 0x70);
    *(undefined4 *)(lVar3 + 0x5c) = *(undefined4 *)(param_1 + 0x74);
    *(undefined4 *)(lVar3 + 0x60) = *(undefined4 *)(param_1 + 0x78);
    *(undefined4 *)(lVar3 + 100) = *(undefined4 *)(param_1 + 0x7c);
    return 4;
  }
  if (iVar1 == 0x10000001) {
    if (*(uint *)(lVar3 + 0x18) < 4) {
      p_Var5[3] = (_comp_mgr_t)0x4;
    }
    iVar1 = *(int *)(lVar3 + 0x1c);
    if ((*(int *)(param_1 + 0x84) - 1U & 0xfffffffb) != 0) {
      p_Var5[2] = (_comp_mgr_t)0x0;
      p_Var5[10] = (_comp_mgr_t)0x6;
      *(undefined2 *)(p_Var5 + 0x48) = 0xee1;
      p_Var5[0x4a] = (_comp_mgr_t)(iVar1 == 0);
      RaidHwStartIo(param_1,p_Var5);
      return 3;
    }
    memset(param_2 + 0x38,0,0x418);
    if (*(int *)(param_1 + 0x84) == 1) {
      *(undefined2 *)(param_2 + 0x40) = 0xbad8;
      param_2[0x42] = (_io_t)0x3;
      param_2[0x43] = (_io_t)((-(iVar1 != 0) & 3U) + 0xd);
    }
    else {
      *(undefined2 *)(param_2 + 0x50) = 0xbad8;
      param_2[0x52] = (_io_t)0x3;
      param_2[0x53] = (_io_t)((-(iVar1 != 0) & 3U) + 0xd);
    }
    if (iVar1 != 0) goto LAB_00012249;
  }
  else {
    if (iVar1 != 0x10000002) {
      if (iVar1 != -0x21522153) {
        p_Var5[3] = (_comp_mgr_t)0x6;
        return 4;
      }
      RaidReturn(param_1,param_2,4);
      if (support_reset == 0) {
        return 3;
      }
      compmgr_reset_components(param_1,1);
      return 3;
    }
    if (*(uint *)(lVar3 + 0x18) < 0x20) {
      p_Var5[3] = (_comp_mgr_t)0x4;
    }
    if (*(int *)(param_1 + 0x84) != 5) {
      return 4;
    }
    memset(param_2 + 0x38,0,0x200);
    *(undefined4 *)(param_2 + 0x50) = 0x2103bad8;
  }
  p_Var5[3] = (_comp_mgr_t)0x0;
  (*(code *)**(undefined8 **)(param_1 + 0xa0))(*(undefined8 *)(param_1 + 0x98),param_2);
LAB_00012249:
  p_Var5[3] = (_comp_mgr_t)0x1;
  return 3;
}



===== RaidHwBuildIo @ 00012330 =====

undefined8 RaidHwBuildIo(longlong param_1,longlong param_2)

{
  longlong lVar1;
  uint uVar2;
  undefined8 uVar3;
  
  lVar1 = *(longlong *)(param_2 + 0x38);
  *(longlong *)(lVar1 + 0x30) = param_2;
  *(code **)(lVar1 + 0x20) = RaidReturn;
  *(longlong *)(lVar1 + 0x28) = param_1;
  if (*(uint *)(param_1 + 0x88) < 0x451) {
    *(undefined8 *)(lVar1 + 0x10) = 0;
  }
  else {
    uVar2 = *(uint *)(param_1 + 0x88) - 0x450;
    *(uint *)(lVar1 + 0x18) = uVar2;
    if (0x450 < uVar2) {
      *(longlong *)(lVar1 + 0x10) = lVar1 + 0x450;
    }
  }
  uVar3 = FUN_00011238(param_1,lVar1,lVar1 + 0x38);
  return CONCAT71((int7)((ulonglong)uVar3 >> 8),1);
}



===== FUN_00012394 @ 00012394 =====

undefined8 FUN_00012394(longlong param_1,longlong param_2,int param_3)

{
  longlong lVar1;
  undefined8 uVar2;
  
  lVar1 = *(longlong *)(param_2 + 0x38);
  if ((*(int *)(param_1 + 0x84) - 1U & 0xfffffffb) == 0) {
    memset((void *)(lVar1 + 0x38),0,0x418);
    if (*(int *)(param_1 + 0x84) == 5) {
      *(undefined2 *)(lVar1 + 0x50) = 0xbad8;
      *(undefined1 *)(lVar1 + 0x52) = 3;
      *(byte *)(lVar1 + 0x53) = (-(param_3 != 0) & 3U) + 0xd;
    }
    else {
      *(undefined2 *)(lVar1 + 0x40) = 0xbad8;
      *(undefined1 *)(lVar1 + 0x42) = 3;
      *(byte *)(lVar1 + 0x43) = (-(param_3 != 0) & 3U) + 0xd;
    }
    *(undefined1 *)(param_2 + 3) = 0;
    uVar2 = (*(code *)**(undefined8 **)(param_1 + 0xa0))(*(undefined8 *)(param_1 + 0x98),lVar1);
  }
  else {
    uVar2 = 4;
  }
  *(undefined1 *)(param_2 + 3) = 1;
  return uVar2;
}



===== QueryFW4Reset @ 00012458 =====

/* void __cdecl QueryFW4Reset(void * __ptr64) */

void __cdecl QueryFW4Reset(void *param_1)

{
  _comp_mgr_t *p_Var1;
  void *pvVar2;
  
  p_Var1 = (_comp_mgr_t *)((longlong)param_1 + 0xd0);
  *(undefined2 *)p_Var1 = 0x58;
  pvVar2 = pprvtData;
  *(undefined1 *)((longlong)param_1 + 0xd2) = 2;
  *(void **)((longlong)param_1 + 0xe8) = pvVar2;
  *(undefined2 *)((longlong)param_1 + 0xd6) = 0;
  *(undefined1 *)((longlong)param_1 + 0xda) = 6;
  *(undefined4 *)((longlong)pvVar2 + 4) = 0x54534146;
  *(undefined4 *)((longlong)pvVar2 + 8) = 0x4b415254;
  *(undefined4 *)((longlong)pvVar2 + 0x10) = 0x10000002;
  prvtSRBcalled = '\x01';
  *(undefined4 *)((longlong)pvVar2 + 0x18) = 0x20;
  *(undefined4 *)((longlong)param_1 + 0xe0) = 0x20;
  *(undefined4 *)((longlong)param_1 + 0xdc) = 0x40;
  *(undefined1 *)((longlong)param_1 + 0xd3) = 0;
  *(longlong *)((longlong)param_1 + 0x108) = (longlong)param_1 + 0x128;
  *(void **)((longlong)param_1 + 0x150) = param_1;
  *(_comp_mgr_t **)((longlong)param_1 + 0x158) = p_Var1;
  *(code **)((longlong)param_1 + 0x148) = RaidReturn;
  RaidHwStartIo(param_1,p_Var1);
  return;
}



===== RaidHwStartIo @ 000124e0 =====

undefined8 RaidHwStartIo(_comp_mgr_t *param_1,_comp_mgr_t *param_2)

{
  _comp_mgr_t _Var1;
  undefined1 uVar2;
  _io_t *p_Var3;
  undefined3 uVar4;
  int iVar5;
  _comp_mgr_t *in_RAX;
  undefined8 uVar6;
  _comp_mgr_t *extraout_RAX;
  uint uVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  
  p_Var3 = *(_io_t **)(param_2 + 0x38);
  if (param_2[3] == (_comp_mgr_t)0x55) goto LAB_00012504;
  if (param_2[7] == (_comp_mgr_t)0xff) {
    param_2[3] = (_comp_mgr_t)0xa;
  }
  else {
    if (*(int *)(param_1 + 0xc0) == 0) {
      if ((gIsLdrDump != '\0') && (*(longlong *)(param_1 + 0xb8) == 0)) {
        *(_comp_mgr_t **)(param_1 + 0xb8) = param_2;
        compmgr_start_component(param_1,(void *)0x0);
        param_2[3] = (_comp_mgr_t)0x0;
        if (param_2[8] == (_comp_mgr_t)0xff) {
          in_RAX = (_comp_mgr_t *)StorPortNotification(1);
        }
        else {
          in_RAX = (_comp_mgr_t *)StorPortNotification(2,param_1,param_2[5],param_2[6],param_2[7]);
        }
        goto LAB_000127bd;
      }
    }
    else if ((*(int *)(param_1 + 0xc4) == 0) || (in_RAX = param_1 + 0xd0, param_2 == in_RAX)) {
      _Var1 = param_2[2];
      if ((byte)_Var1 < 0x14) {
        if (_Var1 == (_comp_mgr_t)0x13) {
LAB_00012781:
          in_RAX = (_comp_mgr_t *)StorPortDeviceReady(param_1,param_2[5],param_2[6]);
LAB_0001273d:
          param_2[3] = (_comp_mgr_t)0x1;
          goto LAB_00012797;
        }
        if (_Var1 == (_comp_mgr_t)0x0) {
LAB_000125f1:
          param_2[3] = (_comp_mgr_t)0x0;
          if ((param_2[6] == param_1[0x91]) &&
             (((*(int *)(param_1 + 0x84) - 1U & 0xfffffffb) != 0 || (param_2[7] == (_comp_mgr_t)0x0)
              ))) {
            _Var1 = param_2[0x48];
            uVar4 = (undefined3)(*(int *)(param_1 + 0x84) - 1U >> 8);
            in_RAX = (_comp_mgr_t *)(ulonglong)CONCAT31(uVar4,_Var1);
            if (_Var1 == (_comp_mgr_t)0x12) {
              iVar5 = 4;
              if (param_2[7] == (_comp_mgr_t)0x0) {
                in_RAX = (_comp_mgr_t *)(ulonglong)CONCAT31(uVar4,param_2[0x49]);
                if (((byte)param_2[0x49] & 1) == 0) {
                  param_2[3] = (_comp_mgr_t)0x1;
                  _Var1 = param_2[0x4c];
                  in_RAX = (_comp_mgr_t *)(ulonglong)CONCAT31(uVar4,_Var1);
                  uVar7 = 0x40;
                  if ((byte)_Var1 < 0x40) {
                    uVar7 = (uint)(byte)_Var1;
                  }
                  puVar9 = *(undefined1 **)(param_2 + 0x18);
                  puVar8 = &DAT_00016110;
                  for (; uVar7 != 0; uVar7 = uVar7 - 1) {
                    uVar2 = *puVar8;
                    in_RAX = (_comp_mgr_t *)CONCAT71((int7)((ulonglong)in_RAX >> 8),uVar2);
                    puVar8 = puVar8 + 1;
                    *puVar9 = uVar2;
                    puVar9 = puVar9 + 1;
                  }
                }
                else {
                  param_2[3] = (_comp_mgr_t)0x6;
                }
              }
              else {
                param_2[3] = (_comp_mgr_t)0xa;
              }
              goto LAB_00012799;
            }
            if ((_Var1 == (_comp_mgr_t)0xe3) && (param_2[0x49] == (_comp_mgr_t)0x5)) {
              *(code **)(p_Var3 + 0x20) = FUN_0001200c;
            }
          }
          if ((param_2[0x48] == (_comp_mgr_t)0x1b) &&
             (((param_2[6] == (_comp_mgr_t)0x0 ||
               ((param_2[6] == param_1[0x91] && (param_2[7] == (_comp_mgr_t)0x0)))) &&
              (in_RAX = (_comp_mgr_t *)(ulonglong)(*(int *)(param_1 + 0x84) - 1U),
              (*(int *)(param_1 + 0x84) - 1U & 0xfffffffb) == 0)))) goto LAB_0001273d;
LAB_00012658:
          in_RAX = (_comp_mgr_t *)
                   (*(code *)**(undefined8 **)(param_1 + 0xa0))
                             (*(undefined8 *)(param_1 + 0x98),p_Var3);
          goto LAB_00012678;
        }
        if (_Var1 != (_comp_mgr_t)0x2) {
          if (_Var1 != (_comp_mgr_t)0x7) {
            if (_Var1 != (_comp_mgr_t)0x8) {
              if (_Var1 == (_comp_mgr_t)0x12) goto LAB_000125dc;
              goto LAB_00012793;
            }
            param_2[2] = (_comp_mgr_t)0x0;
            param_2[10] = (_comp_mgr_t)0x6;
            param_2[0x48] = (_comp_mgr_t)0x35;
            goto LAB_000125f1;
          }
          if (((*(int *)(param_1 + 0x84) != 5) || (param_2[6] == (_comp_mgr_t)0x0)) ||
             ((param_2[6] == param_1[0x91] && (param_2[7] == (_comp_mgr_t)0x0)))) {
LAB_0001266d:
            iVar5 = 0;
            goto LAB_00012670;
          }
          goto LAB_00012658;
        }
        uVar6 = FUN_000120b8(param_1,p_Var3);
        iVar5 = (int)uVar6;
        in_RAX = param_1 + 0xd0;
        if (param_2 == in_RAX) {
          return 4;
        }
      }
      else {
        if (_Var1 == (_comp_mgr_t)0x17) {
LAB_00012793:
          param_2[3] = (_comp_mgr_t)0x6;
          goto LAB_00012797;
        }
        if (_Var1 == (_comp_mgr_t)0x20) goto LAB_00012781;
        if (_Var1 != (_comp_mgr_t)0x24) {
          if (_Var1 != (_comp_mgr_t)0x25) goto LAB_00012793;
          *(undefined4 *)(param_2 + 0x40) = 1;
LAB_000125dc:
          param_2[3] = (_comp_mgr_t)0x1;
LAB_00012797:
          iVar5 = 4;
          goto LAB_00012799;
        }
        uVar7 = *(uint *)(param_2 + 8);
        in_RAX = (_comp_mgr_t *)(ulonglong)uVar7;
        if (uVar7 != 1) {
          if (uVar7 == 4) goto LAB_0001266d;
          *(undefined2 *)(param_2 + 3) = 0x101;
          goto LAB_00012797;
        }
        iVar5 = 1;
LAB_00012670:
        in_RAX = (_comp_mgr_t *)FUN_00012394((longlong)param_1,(longlong)param_2,iVar5);
LAB_00012678:
        iVar5 = (int)in_RAX;
      }
LAB_00012799:
      if (iVar5 == 1) {
        param_2[3] = (_comp_mgr_t)0x5;
      }
      else if (((iVar5 == 2) || (iVar5 == 3)) || (iVar5 != 4)) goto LAB_000127bd;
      goto LAB_000127b5;
    }
LAB_00012504:
    param_2[3] = (_comp_mgr_t)0x5;
  }
LAB_000127b5:
  RaidReturn(param_1,p_Var3,4);
  in_RAX = extraout_RAX;
LAB_000127bd:
  return CONCAT71((int7)((ulonglong)in_RAX >> 8),1);
}



===== RaidHwInterrupt @ 000127dc =====

ulonglong RaidHwInterrupt(longlong param_1)

{
  ulonglong in_RAX;
  undefined8 uVar1;
  
  if ((*(longlong *)(param_1 + 0xa8) == 0) ||
     (in_RAX = (*(code *)**(undefined8 **)(param_1 + 0xb0))(), (int)in_RAX == 0)) {
    return in_RAX & 0xffffffffffffff00;
  }
  uVar1 = (**(code **)(*(longlong *)(param_1 + 0xb0) + 8))(*(undefined8 *)(param_1 + 0xa8));
  return CONCAT71((int7)((ulonglong)uVar1 >> 8),1);
}



===== osi_reset_iop @ 00012824 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl osi_reset_iop(void * __ptr64) */

void __cdecl osi_reset_iop(void *param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined1 auStack_188 [32];
  byte *local_168;
  undefined4 local_160;
  undefined4 local_158;
  byte local_148 [8];
  undefined1 local_140 [4];
  byte local_13c;
  byte local_138 [4];
  byte local_134;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_188;
  local_168 = local_138;
  uVar2 = *(uint *)((longlong)param_1 + 0x6c) & 0x1f;
  local_160 = 0x100;
  StorPortGetBusData(param_1,4,*(undefined4 *)((longlong)param_1 + 0x68),uVar2);
  if (*(char *)((longlong)param_1 + 0x80) == -1) {
    DAT_00016218 = '\x01';
  }
  if (DAT_00016218 == '\0') {
    if (DAT_000161d2 != '\0') {
      local_168 = local_148;
      local_158 = 1;
      local_160 = 0x3e;
      (*DAT_00016208)(DAT_00016200,*(char *)((longlong)param_1 + 0x80),
                      *(undefined1 *)((longlong)param_1 + 0x81),0);
    }
    local_148[0] = local_148[0] | 0x40;
    if (DAT_000161d2 != '\0') {
      local_168 = local_148;
      local_158 = 1;
      local_160 = 0x3e;
      (*DAT_00016210)(DAT_00016200,*(undefined1 *)((longlong)param_1 + 0x80),
                      *(undefined1 *)((longlong)param_1 + 0x81),0);
    }
    uVar3 = 100000;
    do {
      if (uVar3 < 0x3e9) {
        StorPortStallExecution(uVar3);
        uVar3 = 0;
      }
      else {
        StorPortStallExecution(1000);
        uVar3 = uVar3 - 1000;
      }
    } while (uVar3 != 0);
    local_148[0] = local_148[0] & 0xbf;
    if (DAT_000161d2 != '\0') {
      local_168 = local_148;
      local_158 = 1;
      local_160 = 0x3e;
      (*DAT_00016210)(DAT_00016200,*(undefined1 *)((longlong)param_1 + 0x80),
                      *(undefined1 *)((longlong)param_1 + 0x81),0);
    }
  }
  else {
    local_158 = 1;
    local_148[0] = local_134 & 0xf9;
    local_168 = local_148;
    local_160 = 4;
    local_148[1] = 0x20;
    StorPortSetBusDataByOffset(param_1,4,*(undefined4 *)((longlong)param_1 + 0x68),uVar2);
    uVar3 = 1000;
    do {
      if (uVar3 < 0x3e9) {
        StorPortStallExecution(uVar3);
        uVar3 = 0;
      }
      else {
        StorPortStallExecution(1000);
        uVar3 = uVar3 - 1000;
      }
    } while (uVar3 != 0);
    local_168 = local_148 + 1;
    local_158 = 1;
    local_160 = 0x84;
    StorPortSetBusDataByOffset(param_1,4,*(undefined4 *)((longlong)param_1 + 0x68),uVar2);
    uVar3 = 10000;
    do {
      if (uVar3 < 0x3e9) {
        StorPortStallExecution(uVar3);
        uVar3 = 0;
      }
      else {
        StorPortStallExecution(1000);
        uVar3 = uVar3 - 1000;
      }
    } while (uVar3 != 0);
    local_148[0] = local_148[0] | 6;
    local_168 = local_148;
    local_158 = 1;
    local_160 = 4;
    StorPortSetBusDataByOffset(param_1,4,*(undefined4 *)((longlong)param_1 + 0x68),uVar2);
  }
  while( true ) {
    local_168 = local_140;
    local_160 = 8;
    iVar1 = StorPortGetBusData(param_1,4,*(undefined4 *)((longlong)param_1 + 0x68),uVar2);
    if (((iVar1 == 8) && (local_13c != 0xffffffff)) && ((local_13c & 4) != 0)) break;
    uVar3 = 1000;
    do {
      if (uVar3 < 0x3e9) {
        StorPortStallExecution(uVar3);
        uVar3 = 0;
      }
      else {
        StorPortStallExecution(1000);
        uVar3 = uVar3 - 1000;
      }
    } while (uVar3 != 0);
  }
  uVar3 = 5000000;
  do {
    if (uVar3 < 0x3e9) {
      StorPortStallExecution(uVar3);
      uVar3 = 0;
    }
    else {
      StorPortStallExecution(1000);
      uVar3 = uVar3 - 1000;
    }
  } while (uVar3 != 0);
  local_168 = local_138;
  local_158 = 0x100;
  local_160 = 0;
  StorPortSetBusDataByOffset(param_1,4,*(undefined4 *)((longlong)param_1 + 0x68),uVar2);
  return;
}



===== RaidHwTimerService @ 00012b74 =====

void RaidHwTimerService(longlong param_1)

{
  (**(code **)(*(longlong *)(param_1 + 0xa0) + 0x10))(*(undefined8 *)(param_1 + 0x98));
                    /* WARNING: Could not recover jumptable at 0x00012ba8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortNotification(6,param_1,RaidHwTimerService,1000000);
  return;
}



===== RaidHwScsiAdapterControl @ 00012bb8 =====

undefined8 RaidHwScsiAdapterControl(_comp_mgr_t *param_1,int param_2,longlong param_3)

{
  longlong lVar1;
  code *pcVar2;
  _comp_mgr_t *p_Var3;
  
  if (param_2 == 0) {
    *(undefined2 *)(param_3 + 4) = 0x101;
    *(undefined1 *)(param_3 + 6) = 1;
  }
  else if (param_2 == 1) {
    *(undefined4 *)(param_1 + 0xc0) = 0;
    p_Var3 = *(_comp_mgr_t **)(param_1 + 0x28);
    *(undefined4 *)(param_1 + 0x18) = 5;
    for (; p_Var3 != param_1 + 0x20; p_Var3 = *(_comp_mgr_t **)(p_Var3 + 8)) {
      lVar1 = *(longlong *)((longlong)*(int *)(p_Var3 + 0x18) * 0x10 + *(longlong *)param_1 + 8);
      if ((lVar1 != 0) && (pcVar2 = *(code **)(lVar1 + 0x20), pcVar2 != (code *)0x0)) {
        (*pcVar2)(p_Var3 + 0x20);
      }
    }
    *(undefined4 *)(param_1 + 0x18) = 6;
    *(undefined4 *)(param_1 + 0xc4) = 1;
  }
  else if (param_2 == 2) {
    *(undefined4 *)(param_1 + 0xc4) = 0;
    *(undefined2 *)(param_1 + 200) = 0x78;
    compmgr_start_component(param_1,(void *)0x0);
  }
  return 0;
}



===== compmgr_get_global_rsc_size @ 00012c6c =====

/* unsigned int __cdecl compmgr_get_global_rsc_size(struct _comp_tmpl_t * __ptr64,int,enum
   _rsc_type_t) */

uint __cdecl compmgr_get_global_rsc_size(_comp_tmpl_t *param_1,int param_2,_rsc_type_t param_3)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = 0;
  if ((PTR_hmu_if_comp_00016158 != (undefined *)0x0) &&
     (*(code **)(PTR_hmu_if_comp_00016158 + 8) != (code *)0x0)) {
    iVar2 = (**(code **)(PTR_hmu_if_comp_00016158 + 8))(0,param_3);
    uVar1 = (iVar2 + 7U & 0xfffffff8) + 0x28;
  }
  return uVar1;
}



===== compmgr_init_components @ 00012ca8 =====

/* void __cdecl compmgr_init_components(struct _comp_mgr_t * __ptr64,void * __ptr64,void *
   __ptr64,unsigned int,struct _comp_tmpl_t * __ptr64,int) */

void __cdecl
compmgr_init_components
          (_comp_mgr_t *param_1,void *param_2,void *param_3,uint param_4,_comp_tmpl_t *param_5,
          int param_6)

{
  _comp_mgr_t *p_Var1;
  longlong *plVar2;
  longlong lVar3;
  code *pcVar4;
  int iVar5;
  uint uVar6;
  undefined8 *puVar7;
  _comp_mgr_t *p_Var8;
  int iVar9;
  longlong lVar10;
  
  p_Var1 = param_1 + 0x20;
  iVar9 = 0;
  *(undefined4 *)(param_1 + 0x18) = 1;
  *(_comp_mgr_t **)p_Var1 = p_Var1;
  *(void **)(param_1 + 8) = param_2;
  *(undefined ***)param_1 = &comp_tmpls;
  *(undefined4 *)(param_1 + 0x14) = 1;
  *(undefined4 *)(param_1 + 0x10) = 0x22334455;
  *(_comp_mgr_t **)(param_1 + 0x28) = p_Var1;
  lVar10 = 0;
  do {
    *(int *)((longlong)param_3 + 0x20) = iVar9;
    *(_comp_mgr_t **)param_3 = param_1;
    *(undefined4 *)((longlong)param_3 + 0x18) = 0x11223344;
    lVar3 = *(longlong *)p_Var1;
    *(_comp_mgr_t **)((longlong)param_3 + 0x10) = p_Var1;
    plVar2 = (longlong *)((longlong)param_3 + 8);
    *plVar2 = lVar3;
    *(longlong **)(*(longlong *)p_Var1 + 8) = plVar2;
    *(longlong **)p_Var1 = plVar2;
    lVar3 = *(longlong *)(lVar10 + 8 + *(longlong *)param_1);
    puVar7 = (undefined8 *)((longlong)param_3 + 0x28);
    if ((lVar3 != 0) && (pcVar4 = *(code **)(lVar3 + 8), pcVar4 != (code *)0x0)) {
      iVar5 = (*pcVar4)(0,0);
      uVar6 = iVar5 + 7U & 0xfffffff8;
      *(uint *)((longlong)param_3 + 0x1c) = uVar6;
      puVar7 = (undefined8 *)((longlong)puVar7 + (ulonglong)uVar6);
    }
    iVar9 = iVar9 + 1;
    lVar10 = lVar10 + 0x10;
    param_3 = puVar7;
  } while (iVar9 < *(int *)(param_1 + 0x14));
  for (p_Var8 = *(_comp_mgr_t **)(param_1 + 0x28); p_Var8 != p_Var1;
      p_Var8 = *(_comp_mgr_t **)(p_Var8 + 8)) {
    puVar7 = *(undefined8 **)((longlong)*(int *)(p_Var8 + 0x18) * 0x10 + *(longlong *)param_1 + 8);
    if ((puVar7 != (undefined8 *)0x0) && (pcVar4 = (code *)*puVar7, pcVar4 != (code *)0x0)) {
      (*pcVar4)(p_Var8 + 0x20,*(undefined4 *)(p_Var8 + 0x14));
    }
  }
  *(undefined4 *)(param_1 + 0x18) = 2;
  return;
}



===== compmgr_start_component @ 00012db4 =====

/* void __cdecl compmgr_start_component(struct _comp_mgr_t * __ptr64,void * __ptr64) */

void __cdecl compmgr_start_component(_comp_mgr_t *param_1,void *param_2)

{
  _comp_mgr_t *p_Var1;
  _comp_mgr_t *p_Var2;
  __uint64 in_R9;
  
  *(undefined4 *)(param_1 + 0x18) = 3;
  if (param_2 == (void *)0x0) {
    p_Var2 = *(_comp_mgr_t **)(param_1 + 0x20);
  }
  else {
    p_Var2 = *(_comp_mgr_t **)((longlong)param_2 + -0x20);
  }
  p_Var1 = param_1 + 0x20;
  if (p_Var2 != p_Var1) {
    do {
      in_R9 = *(__uint64 *)(*(longlong *)param_1 + 8 + (longlong)*(int *)(p_Var2 + 0x18) * 0x10);
      if ((in_R9 != 0) && (*(longlong *)(in_R9 + 0x18) != 0)) {
                    /* WARNING: Could not recover jumptable at 0x00012e12. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(in_R9 + 0x18))(p_Var2 + 0x20);
        return;
      }
      p_Var2 = *(_comp_mgr_t **)p_Var2;
    } while (p_Var2 != p_Var1);
  }
  *(undefined4 *)(param_1 + 0x18) = 4;
  osi_notification(*(void **)(param_1 + 8),8,(__uint64)p_Var1,in_R9);
  return;
}



===== compmgr_reset_components @ 00012e1c =====

/* void __cdecl compmgr_reset_components(struct _comp_mgr_t * __ptr64,enum _comp_reset_type_t) */

void __cdecl compmgr_reset_components(_comp_mgr_t *param_1,_comp_reset_type_t param_2)

{
  longlong lVar1;
  code *pcVar2;
  _comp_mgr_t *p_Var3;
  
  for (p_Var3 = *(_comp_mgr_t **)(param_1 + 0x28); p_Var3 != param_1 + 0x20;
      p_Var3 = *(_comp_mgr_t **)(p_Var3 + 8)) {
    lVar1 = *(longlong *)((longlong)*(int *)(p_Var3 + 0x18) * 0x10 + *(longlong *)param_1 + 8);
    if ((lVar1 != 0) && (pcVar2 = *(code **)(lVar1 + 0x30), pcVar2 != (code *)0x0)) {
      (*pcVar2)(p_Var3 + 0x20,param_2);
    }
  }
  return;
}



===== compmgr_search_if @ 00012e88 =====

/* int __cdecl compmgr_search_if(struct _comp_mgr_t * __ptr64,struct _guid_t const * __ptr64,struct
   _if_impl_t * __ptr64,enum _comp_iter_dir_t,void * __ptr64) */

int __cdecl
compmgr_search_if(_comp_mgr_t *param_1,_guid_t *param_2,_if_impl_t *param_3,_comp_iter_dir_t param_4
                 ,void *param_5)

{
  longlong lVar1;
  code *pcVar2;
  int iVar3;
  _comp_mgr_t *p_Var4;
  
  iVar3 = 0;
  if (param_4 == 1) {
    p_Var4 = *(_comp_mgr_t **)(param_1 + 0x28);
  }
  else {
    p_Var4 = *(_comp_mgr_t **)(param_1 + 0x20);
  }
  while( true ) {
    if (p_Var4 == param_1 + 0x20) {
      return iVar3;
    }
    lVar1 = *(longlong *)((longlong)*(int *)(p_Var4 + 0x18) * 0x10 + *(longlong *)param_1 + 8);
    if (((lVar1 != 0) && (pcVar2 = *(code **)(lVar1 + 0x38), pcVar2 != (code *)0x0)) &&
       (iVar3 = (*pcVar2)(p_Var4 + 0x20,param_2,param_3,param_4,0), iVar3 != 0)) break;
    if (param_4 == 1) {
      p_Var4 = *(_comp_mgr_t **)(p_Var4 + 8);
    }
    else {
      p_Var4 = *(_comp_mgr_t **)p_Var4;
    }
  }
  return iVar3;
}



===== compmgr_on_notify @ 00012f34 =====

/* void __cdecl compmgr_on_notify(void * __ptr64,enum _comp_iter_dir_t,enum
   _comp_noti_type_t,unsigned __int64,unsigned __int64) */

void __cdecl
compmgr_on_notify(void *param_1,_comp_iter_dir_t param_2,_comp_noti_type_t param_3,__uint64 param_4,
                 __uint64 param_5)

{
  longlong *plVar1;
  longlong lVar2;
  code *pcVar3;
  int iVar4;
  longlong *plVar5;
  longlong *plVar6;
  
  plVar6 = (longlong *)((longlong)param_1 + -0x28);
  plVar1 = (longlong *)*plVar6;
  for (plVar5 = (longlong *)plVar1[5]; plVar5 != plVar1 + 4; plVar5 = (longlong *)plVar5[1]) {
    plVar6 = plVar5 + -1;
    lVar2 = *(longlong *)((longlong)(int)plVar5[3] * 0x10 + *plVar1 + 8);
    if ((lVar2 != 0) && (pcVar3 = *(code **)(lVar2 + 0x28), pcVar3 != (code *)0x0)) {
      iVar4 = (*pcVar3)(plVar5 + 4,param_1,5,0,0);
      if (iVar4 == 0) break;
    }
  }
  compmgr_start_component((_comp_mgr_t *)*plVar6,param_1);
  return;
}



===== hmu_get_rsc_req @ 00012fd4 =====

/* unsigned int __cdecl hmu_get_rsc_req(struct _hmu_t * __ptr64,enum _rsc_type_t) */

uint __cdecl hmu_get_rsc_req(_hmu_t *param_1,_rsc_type_t param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  if (param_2 == 0) {
    return 0x2518;
  }
  if ((param_2 == 1) || (param_2 != 4)) {
    return 0;
  }
  iVar1 = *(int *)(*(longlong *)param_1 + 0x84);
  if (gIsLdrDump == '\x01') {
    uVar2 = 0x947;
    uVar3 = 0x53f;
  }
  else {
    if (iVar1 == 1) {
      uVar2 = 0xa541f;
      goto LAB_00013027;
    }
    uVar2 = 0x944a7;
    uVar3 = 0x51ab3;
  }
  if (iVar1 == 5) {
    uVar2 = uVar3;
  }
LAB_00013027:
  if (iVar1 != 3) {
    return uVar2;
  }
  if (gIsLdrDump == '\x01') {
    return uVar2 + 0x918;
  }
  return uVar2 + 0x200000;
}



===== hmu_init @ 00013048 =====

/* void __cdecl hmu_init(struct _hmu_t * __ptr64,unsigned int) */

void __cdecl hmu_init(_hmu_t *param_1,uint param_2)

{
  _hmu_t *p_Var1;
  longlong lVar2;
  undefined8 uVar3;
  
  lVar2 = *(longlong *)(*(longlong *)(param_1 + -0x28) + 8);
  *(longlong *)param_1 = lVar2;
  uVar3 = *(undefined8 *)(lVar2 + 0x30);
  *(undefined8 *)(param_1 + 0x20ac) = 0x200;
  *(undefined8 *)(param_1 + 8) = uVar3;
  *(undefined8 *)(param_1 + 0x2510) = 0;
  p_Var1 = param_1 + 0x28;
  *(_hmu_t **)(param_1 + 0x30) = p_Var1;
  *(_hmu_t **)p_Var1 = p_Var1;
  p_Var1 = param_1 + 0x38;
  *(_hmu_t **)(param_1 + 0x40) = p_Var1;
  *(_hmu_t **)p_Var1 = p_Var1;
  *(undefined2 *)(param_1 + 0x90) = 0x200;
  FUN_00014844((ushort *)(param_1 + 0x90));
  return;
}



===== hmu_assign_rsc @ 0001309c =====

/* void __cdecl hmu_assign_rsc(struct _hmu_t * __ptr64,struct _rsc_desc_t * __ptr64) */

void __cdecl hmu_assign_rsc(_hmu_t *param_1,_rsc_desc_t *param_2)

{
  int iVar1;
  longlong lVar2;
  uchar uVar3;
  undefined2 uVar4;
  int iVar5;
  uint uVar6;
  ulonglong uVar7;
  
  lVar2 = *(longlong *)param_1;
  iVar1 = *(int *)param_2;
  uVar7 = 0;
  if (*(int *)(lVar2 + 0x84) == 5) {
    if ((iVar1 == 3) || (iVar1 == 4)) {
      uVar7 = *(ulonglong *)(param_2 + 8);
    }
    else if (iVar1 == 5) {
      uVar7 = (ulonglong)*(uint *)(param_2 + 8);
    }
    if ((uVar7 & 0x1f) != 0) {
      uVar6 = (uint)uVar7 & 0x1f;
      iVar5 = 0x20;
LAB_0001310a:
      uVar6 = iVar5 - uVar6;
      *(uint *)(param_2 + 4) = *(int *)(param_2 + 4) - uVar6;
      if (iVar1 == 4) {
        *(ulonglong *)(param_2 + 8) = *(longlong *)(param_2 + 8) + (ulonglong)uVar6;
        *(uint *)(param_2 + 0x10) = *(int *)(param_2 + 0x10) + uVar6;
      }
    }
  }
  else {
    if ((iVar1 == 3) || (iVar1 == 4)) {
      uVar7 = *(ulonglong *)(param_2 + 8);
    }
    else if (iVar1 == 5) {
      uVar7 = (ulonglong)*(uint *)(param_2 + 8);
    }
    if ((uVar7 & 7) != 0) {
      uVar6 = (uint)uVar7 & 7;
      iVar5 = 8;
      goto LAB_0001310a;
    }
  }
  uVar3 = gIsLdrDump;
  *(undefined8 *)(param_1 + 0x48) = *(undefined8 *)(param_2 + 8);
  *(undefined8 *)(param_1 + 0x50) = *(undefined8 *)(param_2 + 0x10);
  if (*(int *)(lVar2 + 0x84) == 5) {
    uVar6 = 0x40200;
    if (uVar3 == '\x01') {
      uVar6 = 0x400;
    }
  }
  else {
    uVar6 = 0x83418;
    if (uVar3 == '\x01') {
      uVar6 = 0x830;
    }
  }
  *(uint *)(param_2 + 4) = *(int *)(param_2 + 4) - uVar6;
  if (*(int *)param_2 == 4) {
    *(ulonglong *)(param_2 + 8) = *(longlong *)(param_2 + 8) + (ulonglong)uVar6;
    *(uint *)(param_2 + 0x10) = *(int *)(param_2 + 0x10) + uVar6;
  }
  if (*(int *)(lVar2 + 0x84) == 5) {
    *(undefined8 *)(param_1 + 0x78) = *(undefined8 *)(param_2 + 8);
    uVar6 = 0x804;
    if (uVar3 == '\x01') {
      uVar6 = 8;
    }
    *(undefined8 *)(param_1 + 0x80) = *(undefined8 *)(param_2 + 0x10);
    *(uint *)(param_2 + 4) = *(int *)(param_2 + 4) - uVar6;
    if (*(int *)param_2 == 4) {
      *(ulonglong *)(param_2 + 8) = *(longlong *)(param_2 + 8) + (ulonglong)uVar6;
      *(uint *)(param_2 + 0x10) = *(int *)(param_2 + 0x10) + uVar6;
    }
  }
  uVar6 = 0x22000;
  *(undefined8 *)(param_1 + 0x60) = *(undefined8 *)(param_2 + 8);
  *(undefined8 *)(param_1 + 0x68) = *(undefined8 *)(param_2 + 0x10);
  if (*(int *)(lVar2 + 0x84) != 1) {
    uVar6 = 0x11088;
  }
  if (uVar3 == '\x01') {
    uVar6 = 0x110;
  }
  *(uint *)(param_2 + 4) = *(int *)(param_2 + 4) - uVar6;
  if (*(int *)param_2 == 4) {
    *(ulonglong *)(param_2 + 8) = *(longlong *)(param_2 + 8) + (ulonglong)uVar6;
    *(uint *)(param_2 + 0x10) = *(int *)(param_2 + 0x10) + uVar6;
  }
  if (uVar3 == '\x01') {
    uVar4 = 2;
    *(undefined2 *)(param_1 + 0x58) = 2;
  }
  else {
    uVar4 = 0x201;
    *(undefined2 *)(param_1 + 0x58) = 0x201;
    if (*(int *)(lVar2 + 0x84) == 1) {
      *(undefined2 *)(param_1 + 0x70) = 0x400;
      goto LAB_00013207;
    }
  }
  *(undefined2 *)(param_1 + 0x70) = uVar4;
LAB_00013207:
  if (*(int *)(param_2 + 4) == 0) {
    *(undefined4 *)(param_1 + 0x20b4) = 0;
    *(undefined4 *)(param_1 + 0x20b8) = 0;
  }
  else {
    *(int *)(param_1 + 0x20b4) = *(int *)(param_2 + 8) - *(int *)(param_1 + 0x48);
    uVar6 = *(uint *)(param_2 + 4);
    *(uint *)(param_1 + 0x20b8) = uVar6;
    *(uint *)(param_2 + 4) = *(int *)(param_2 + 4) - uVar6;
    if (*(int *)param_2 == 4) {
      *(ulonglong *)(param_2 + 8) = *(longlong *)(param_2 + 8) + (ulonglong)uVar6;
      *(uint *)(param_2 + 0x10) = *(int *)(param_2 + 0x10) + uVar6;
    }
  }
  return;
}



===== FUN_00013270 @ 00013270 =====

void FUN_00013270(longlong *param_1,undefined8 param_2,uchar *param_3,__uint64 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  longlong lVar4;
  undefined1 uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  __uint64 in_stack_ffffffffffffffd8;
  
  uVar6 = (uint)param_2;
  if (uVar6 != 0) {
    uVar7 = 0;
    do {
      if (*(int *)(param_1[2] + 0x84) == 5) {
        iVar1 = (int)param_1[0x415];
        if (iVar1 != 0) {
          if (iVar1 == 1) {
            *(undefined4 *)(param_1 + 0x415) = 2;
LAB_000132e3:
            *(undefined4 *)(param_1 + 0x415) = 3;
            *(ushort *)(param_1 + 0x12) = *(ushort *)((longlong)param_1 + 0x20ac);
            FUN_00014844((ushort *)(param_1 + 0x12));
LAB_00013303:
            puVar3 = (undefined4 *)param_1[9];
            param_2 = 0;
            *puVar3 = (int)param_1[10];
            uVar2 = *(undefined4 *)((longlong)param_1 + 0x54);
            *(undefined1 *)(puVar3 + 2) = 0x80;
            puVar3[1] = uVar2;
            param_3 = (uchar *)((longlong)puVar3 + 0x2a);
            puVar3[4] = (int)param_1[10];
            puVar3[5] = *(undefined4 *)((longlong)param_1 + 0x54);
            *(undefined2 *)(puVar3 + 6) = 0x200;
            *(short *)((longlong)puVar3 + 0x1a) = (short)param_1[0xb];
            *(undefined2 *)(puVar3 + 7) = 0x88;
            lVar4 = param_1[0xe];
            *(undefined1 *)((longlong)puVar3 + 0x2b) = 0;
            *(short *)((longlong)puVar3 + 0x1e) = (short)lVar4;
            OsiGetCurrentTime((u64_t *)(puVar3 + 8),0,param_3);
            if ((int)DAT_000161f0 == 1) {
              *(undefined1 *)(puVar3 + 10) = 0;
            }
            else if ((int)DAT_000161f0 == 2) {
              uVar5 = 1;
              if (gIsLdrDump == '\x01') {
                uVar5 = 4;
              }
              *(undefined1 *)(puVar3 + 10) = uVar5;
            }
            else if ((int)DAT_000161f0 == 3) {
              *(undefined1 *)(puVar3 + 10) = 2;
            }
            else if ((int)DAT_000161f0 == 4) {
              *(undefined1 *)(puVar3 + 10) = 5;
            }
            else if ((int)DAT_000161f0 == 5) {
              *(undefined1 *)(puVar3 + 10) = 6;
            }
            bVar9 = DAT_000161f0._4_4_ != 0;
            puVar3[0xc] = 5;
            *(undefined8 *)(puVar3 + 0xd) = 1;
            puVar3[0xf] = 10;
            *(bool *)((longlong)puVar3 + 0x29) = bVar9;
            puVar3[0x10] = *(undefined4 *)((longlong)param_1 + 0x20b4);
            puVar3[0x11] = (int)param_1[0x417];
            puVar3[0x12] = (uint)*(ushort *)(param_1 + 0xe) << 2;
            *(undefined4 *)(param_1 + 0x415) = 4;
            *(uint *)(param_1[1] + 0x34) = *(uint *)(param_1[1] + 0x34) & 0xfffffffb;
            LOCK();
            UNLOCK();
            *(undefined4 *)(param_1[1] + 0xc4) = *(undefined4 *)((longlong)param_1 + 0x54);
            LOCK();
            UNLOCK();
            *(int *)(param_1[1] + 0xc0) = (int)param_1[10];
            LOCK();
            UNLOCK();
            uVar8 = 1000;
            do {
              if (uVar8 < 0x3e9) {
                StorPortStallExecution(uVar8);
                uVar8 = 0;
              }
              else {
                StorPortStallExecution(1000);
                uVar8 = uVar8 - 1000;
              }
            } while (uVar8 != 0);
          }
          else {
            if (iVar1 == 2) goto LAB_000132e3;
            if (iVar1 == 3) goto LAB_00013303;
            if (iVar1 != 4) goto LAB_0001348f;
          }
          if ((*(uint *)param_1[0xf] & 0x20000000) != 0) {
            *(uint *)param_1[0xf] = 0;
            *(undefined1 *)(param_1[9] + 8) = 0;
            *(undefined2 *)((longlong)param_1 + 0x5a) = 0;
            *(undefined2 *)((longlong)param_1 + 0x72) = 0;
            *(undefined4 *)(param_1 + 0x415) = 5;
            compmgr_on_notify(param_1,(_comp_iter_dir_t)param_2,(_comp_noti_type_t)param_3,param_4,
                              in_stack_ffffffffffffffd8);
            FUN_00013808((longlong)param_1);
          }
        }
      }
      else {
        FUN_00014694(param_1,(_comp_iter_dir_t)param_2,(_comp_noti_type_t)param_3,param_4);
      }
LAB_0001348f:
      if ((int)param_1[0x415] == 5) {
        return;
      }
      uVar8 = 1000;
      do {
        if (uVar8 < 0x3e9) {
          StorPortStallExecution(uVar8);
          uVar8 = 0;
        }
        else {
          StorPortStallExecution(1000);
          uVar8 = uVar8 - 1000;
        }
      } while (uVar8 != 0);
      uVar7 = uVar7 + 1;
    } while (uVar7 < uVar6);
  }
  return;
}



===== hmu_start @ 000134ec =====

/* void __cdecl hmu_start(struct _hmu_t * __ptr64) */

void __cdecl hmu_start(_hmu_t *param_1)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  uchar *in_R8;
  __uint64 in_R9;
  
  lVar1 = *(longlong *)(param_1 + 0x10);
  iVar2 = 0;
  if (*(int *)(lVar1 + 0x84) != 5) {
    *(undefined4 *)(*(longlong *)(param_1 + 8) + 0x28) = 0x7b;
    LOCK();
    UNLOCK();
    if (*(int *)(lVar1 + 0x84) != 5) goto LAB_000135be;
  }
  do {
    uVar3 = 1000;
    do {
      if (uVar3 < 0x3e9) {
        StorPortStallExecution(uVar3);
        uVar3 = 0;
      }
      else {
        StorPortStallExecution(1000);
        uVar3 = uVar3 - 1000;
      }
    } while (uVar3 != 0);
  } while ((-1 < **(int **)(param_1 + 8)) && (iVar2 = iVar2 + 1, iVar2 < 180000));
  if ((iVar2 < 180000) && (*(int *)(*(longlong *)(param_1 + 8) + 0x9c) < 0)) {
    *(int *)(*(longlong *)(param_1 + 8) + 0xa0) = *(int *)(*(longlong *)(param_1 + 8) + 0x9c);
    LOCK();
    UNLOCK();
    uVar3 = 1000;
    do {
      if (uVar3 < 0x3e9) {
        StorPortStallExecution(uVar3);
        uVar3 = 0;
      }
      else {
        StorPortStallExecution(1000);
        uVar3 = uVar3 - 1000;
      }
    } while (uVar3 != 0);
  }
LAB_000135be:
  *(undefined4 *)(param_1 + 0x20a8) = 1;
  FUN_00013270((longlong *)param_1,60000,in_R8,in_R9);
  return;
}



===== hmu_stop @ 000135f0 =====

/* void __cdecl hmu_stop(struct _hmu_t * __ptr64) */

void __cdecl hmu_stop(_hmu_t *param_1)

{
  if (*(int *)(*(longlong *)param_1 + 0x84) == 5) {
    *(undefined4 *)(*(longlong *)(param_1 + 8) + 0x20) = 4;
  }
  else {
    *(undefined4 *)(*(longlong *)(param_1 + 8) + 0x20) = 8;
  }
  LOCK();
  UNLOCK();
  *(undefined4 *)(param_1 + 0x20a8) = 6;
  *(undefined2 *)(param_1 + 0x5a) = 0;
  *(undefined2 *)(param_1 + 0x72) = 0;
  return;
}



===== hmu_notify @ 00013630 =====

/* int __cdecl hmu_notify(struct _hmu_t * __ptr64,void * __ptr64,enum _comp_noti_type_t,unsigned
   __int64,unsigned __int64) */

int __cdecl
hmu_notify(_hmu_t *param_1,void *param_2,_comp_noti_type_t param_3,__uint64 param_4,__uint64 param_5
          )

{
  return 1;
}



===== FUN_0001363c @ 0001363c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0001363c(longlong param_1,longlong param_2,undefined1 param_3)

{
  longlong *plVar1;
  undefined1 auStack_e8 [32];
  undefined1 local_c8 [4];
  undefined1 local_c4;
  undefined1 local_c3;
  undefined2 local_c2;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_e8;
  if (*(longlong *)(param_2 + 8) != param_2) {
    do {
      plVar1 = *(longlong **)(param_2 + 8);
      *(longlong *)(*plVar1 + 8) = plVar1[1];
      *(longlong *)plVar1[1] = *plVar1;
      local_c4 = 0;
      local_c2 = 0x200;
      local_c3 = param_3;
      if (*(ushort *)((longlong)plVar1 + 0x1c) != 0xffff) {
        tagpool_release((_tag_pool_t *)(param_1 + 0x90),(uint)*(ushort *)((longlong)plVar1 + 0x1c));
      }
      (**(code **)(param_1 + 0x20))(*(undefined8 *)(param_1 + 0x10),plVar1,local_c8);
      if (param_2 == param_1 + 0x38) {
        *(short *)(param_1 + 0x20ae) = *(short *)(param_1 + 0x20ae) + -1;
      }
      else if (param_2 == param_1 + 0x28) {
        *(int *)(param_1 + 0x20b0) = *(int *)(param_1 + 0x20b0) + -1;
      }
      (*(code *)plVar1[4])(plVar1[5],plVar1,4);
    } while (*(longlong *)(param_2 + 8) != param_2);
  }
  return;
}



===== hmu_reset @ 00013738 =====

/* void __cdecl hmu_reset(struct _hmu_t * __ptr64,enum _comp_reset_type_t) */

void __cdecl hmu_reset(_hmu_t *param_1,_comp_reset_type_t param_2)

{
  int iVar1;
  longlong lVar2;
  _hmu_t *p_Var3;
  uint uVar4;
  undefined1 uVar5;
  undefined7 in_register_00000081;
  __uint64 in_R9;
  
  lVar2 = *(longlong *)param_1;
  p_Var3 = param_1 + 0x28;
  uVar5 = 0xe;
  FUN_0001363c((longlong)param_1,(longlong)p_Var3,0xe);
  iVar1 = *(int *)(lVar2 + 0x84);
  if (iVar1 == 1) {
    FUN_0001363c((longlong)param_1,(longlong)(param_1 + 0x38),0xe);
    *(undefined4 *)(*(longlong *)(param_1 + 8) + 0x20) = 0x10;
    LOCK();
    UNLOCK();
    uVar4 = 1000000;
    do {
      if (uVar4 < 0x3e9) {
        StorPortStallExecution(uVar4);
        uVar4 = 0;
      }
      else {
        StorPortStallExecution(1000);
        uVar4 = uVar4 - 1000;
      }
    } while (uVar4 != 0);
  }
  else if ((iVar1 == 2) && (param_2 == 1)) {
    FUN_00013b4c(param_1,p_Var3,CONCAT71(in_register_00000081,uVar5),in_R9);
  }
  else if ((iVar1 == 5) && (prvtSRBcalled == '\0')) {
    QueryFW4Reset(*(void **)param_1);
  }
  return;
}



===== hmu_set_io_builder @ 000137f4 =====

/* void __cdecl hmu_set_io_builder(struct _hmu_t * __ptr64,void * __ptr64,int (__cdecl*)(void *
   __ptr64,struct _io_t * __ptr64,void * __ptr64),void (__cdecl*)(void * __ptr64,struct _io_t *
   __ptr64,void * __ptr64)) */

void __cdecl
hmu_set_io_builder(_hmu_t *param_1,void *param_2,_func_int_void_ptr__io_t_ptr_void_ptr *param_3,
                  _func_void_void_ptr__io_t_ptr_void_ptr *param_4)

{
  *(void **)(param_1 + 0x10) = param_2;
  *(_func_int_void_ptr__io_t_ptr_void_ptr **)(param_1 + 0x18) = param_3;
  *(_func_void_void_ptr__io_t_ptr_void_ptr **)(param_1 + 0x20) = param_4;
  return;
}



===== FUN_00013808 @ 00013808 =====

int FUN_00013808(longlong param_1)

{
  longlong lVar1;
  longlong *plVar2;
  ushort uVar3;
  int iVar4;
  longlong lVar5;
  longlong *plVar6;
  undefined8 *puVar7;
  longlong lVar8;
  undefined2 uVar9;
  uint uVar10;
  int *piVar11;
  uchar *in_R8;
  __uint64 in_R9;
  int iVar12;
  
  lVar5 = *(longlong *)(param_1 + 0x10);
  iVar12 = 0;
  if (*(int *)(param_1 + 0x20a8) == 5) {
    lVar1 = param_1 + 0x28;
    if (*(longlong *)(param_1 + 0x30) != lVar1) {
      do {
        if (*(ushort *)(param_1 + 0x20ac) <= *(ushort *)(param_1 + 0x20ae)) break;
        plVar6 = *(longlong **)(param_1 + 0x30);
        *(longlong *)(*plVar6 + 8) = plVar6[1];
        *(longlong *)plVar6[1] = *plVar6;
        if (*(int *)(lVar5 + 0x84) == 5) {
          uVar10 = *(ushort *)(param_1 + 0x5a) + 1;
          piVar11 = (int *)((ulonglong)*(ushort *)(param_1 + 0x5a) * 0x200 +
                           *(longlong *)(param_1 + 0x48));
          *(ushort *)(param_1 + 0x5a) =
               -(ushort)(uVar10 < *(ushort *)(param_1 + 0x58)) & (ushort)uVar10;
        }
        else {
          uVar3 = *(ushort *)(param_1 + 0x58);
          uVar10 = *(ushort *)(param_1 + 0x5a) + 1;
          uVar10 = ((uint)uVar3 - (uint)uVar3) - (uint)(uVar10 < uVar3) & uVar10;
          if (uVar10 == *(uint *)(*(longlong *)(param_1 + 8) + 0x18)) {
            piVar11 = (int *)0x0;
          }
          else {
            uVar3 = *(ushort *)(param_1 + 0x5a);
            *(short *)(param_1 + 0x5a) = (short)uVar10;
            piVar11 = (int *)((ulonglong)uVar3 * 0x418 + *(longlong *)(param_1 + 0x48));
          }
        }
        if (piVar11 == (int *)0x0) {
          *plVar6 = lVar1;
          plVar6[1] = *(longlong *)(param_1 + 0x30);
          **(undefined8 **)(param_1 + 0x30) = plVar6;
          *(longlong **)(param_1 + 0x30) = plVar6;
          break;
        }
        *(int *)(param_1 + 0x20b0) = *(int *)(param_1 + 0x20b0) + -1;
        *(short *)(param_1 + 0x20ae) = *(short *)(param_1 + 0x20ae) + 1;
        puVar7 = *(undefined8 **)(param_1 + 0x98);
        if (*(int *)(lVar5 + 0x84) == 5) {
          if (puVar7 == (undefined8 *)0x0) {
            uVar9 = 0xffff;
          }
          else {
            *(undefined8 *)(param_1 + 0x98) = *puVar7;
            puVar7[1] = plVar6;
            *puVar7 = 0;
            if (*(longlong *)(param_1 + 0x98) == 0) {
              *(undefined8 *)(param_1 + 0xa0) = 0;
            }
            *(short *)(param_1 + 0x92) = *(short *)(param_1 + 0x92) + 1;
            uVar9 = (undefined2)((ulonglong)((longlong)puVar7 + (-0x18 - (param_1 + 0x90))) >> 4);
          }
          *(undefined2 *)(piVar11 + 4) = uVar9;
          *(undefined2 *)((longlong)plVar6 + 0x1c) = uVar9;
          *piVar11 = (*(int *)(param_1 + 0x50) - *(int *)(param_1 + 0x48)) + (int)piVar11;
          iVar4 = *(int *)(param_1 + 0x54);
          *(undefined1 *)(piVar11 + 2) = 0;
          piVar11[1] = iVar4;
          *(undefined2 *)(piVar11 + 5) = 0;
        }
        else {
          if (puVar7 == (undefined8 *)0x0) {
            uVar9 = 0xffff;
          }
          else {
            *(undefined8 *)(param_1 + 0x98) = *puVar7;
            puVar7[1] = plVar6;
            *puVar7 = 0;
            if (*(longlong *)(param_1 + 0x98) == 0) {
              *(undefined8 *)(param_1 + 0xa0) = 0;
            }
            *(short *)(param_1 + 0x92) = *(short *)(param_1 + 0x92) + 1;
            uVar9 = (undefined2)((ulonglong)((longlong)puVar7 + (-0x18 - (param_1 + 0x90))) >> 4);
          }
          *(undefined2 *)piVar11 = uVar9;
          *(undefined2 *)((longlong)plVar6 + 0x1c) = uVar9;
          *(undefined2 *)(piVar11 + 1) = 0;
        }
        (**(code **)(param_1 + 0x18))(*(undefined8 *)(param_1 + 0x10),plVar6);
        if (*(int *)(lVar5 + 0x84) == 5) {
          *piVar11 = *piVar11 + (*(ushort *)(piVar11 + 10) + 4) / 0xb;
        }
        *(undefined2 *)((longlong)plVar6 + 0x1e) = 0;
        plVar2 = (longlong *)(param_1 + 0x38);
        lVar8 = *plVar2;
        plVar6[1] = (longlong)plVar2;
        *plVar6 = lVar8;
        *(longlong **)(*plVar2 + 8) = plVar6;
        *plVar2 = (longlong)plVar6;
        if (*(int *)(lVar5 + 0x84) == 5) {
          *(undefined4 *)(*(longlong *)(param_1 + 8) + 0xc4) = *(undefined4 *)(param_1 + 0x54);
          LOCK();
          UNLOCK();
          *(int *)(*(longlong *)(param_1 + 8) + 0xc0) = *piVar11;
          LOCK();
          UNLOCK();
        }
        iVar12 = iVar12 + 1;
      } while (*(longlong *)(param_1 + 0x30) != lVar1);
      if ((iVar12 != 0) && (*(int *)(lVar5 + 0x84) != 5)) {
        *(uint *)(*(longlong *)(param_1 + 8) + 0x10) = (uint)*(ushort *)(param_1 + 0x5a);
        LOCK();
        UNLOCK();
        *(undefined4 *)(*(longlong *)(param_1 + 8) + 0x20) = 2;
        LOCK();
        UNLOCK();
      }
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x20a8) = 1;
    FUN_00013270((longlong *)param_1,1000,in_R8,in_R9);
    iVar12 = 0;
  }
  return iVar12;
}



===== hmu_start_io @ 00013aa8 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* enum _io_sts_t __cdecl hmu_start_io(struct _hmu_t * __ptr64,struct _io_t * __ptr64) */

_io_sts_t __cdecl hmu_start_io(_hmu_t *param_1,_io_t *param_2)

{
  _hmu_t *p_Var1;
  longlong lVar2;
  undefined1 local_28 [8];
  undefined8 local_20;
  
  local_20 = 0;
  StorPortNotification(0x1003,*(undefined8 *)param_1,3,0,local_28);
  *(int *)(param_1 + 0x20b0) = *(int *)(param_1 + 0x20b0) + 1;
  _DAT_000161ec = _DAT_000161ec + 1;
  p_Var1 = param_1 + 0x28;
  *(undefined2 *)(param_2 + 0x1c) = 0xffff;
  lVar2 = *(longlong *)p_Var1;
  *(_hmu_t **)(param_2 + 8) = p_Var1;
  *(longlong *)param_2 = lVar2;
  *(_io_t **)(*(longlong *)p_Var1 + 8) = param_2;
  *(_io_t **)p_Var1 = param_2;
  FUN_00013808((longlong)param_1);
  StorPortNotification(0x1004,*(undefined8 *)param_1,local_28);
  return (-(uint)(*(ushort *)(param_1 + 0x20ae) < *(ushort *)(param_1 + 0x20ac)) & 0xfffffffd) + 5;
}



===== FUN_00013b4c @ 00013b4c =====

void FUN_00013b4c(_hmu_t *param_1,undefined8 param_2,undefined8 param_3,__uint64 param_4)

{
  undefined1 uVar1;
  undefined7 uVar2;
  
  uVar2 = (undefined7)((ulonglong)param_3 >> 8);
  osi_reset_iop(*(void **)param_1);
  FUN_0001363c((longlong)param_1,(longlong)(param_1 + 0x28),8);
  uVar1 = 8;
  FUN_0001363c((longlong)param_1,(longlong)(param_1 + 0x38),8);
  hmu_stop(param_1);
  *(undefined4 *)(param_1 + 0x20a8) = 1;
  FUN_00013270((longlong *)param_1,60000,(uchar *)CONCAT71(uVar2,uVar1),param_4);
  return;
}



===== yellowstone_reset_iop @ 00013ba8 =====

/* void __cdecl yellowstone_reset_iop(struct _hmu_t * __ptr64) */

void __cdecl yellowstone_reset_iop(_hmu_t *param_1)

{
  uint uVar1;
  int iVar2;
  undefined1 uVar3;
  undefined7 in_register_00000081;
  __uint64 in_R9;
  
  FUN_0001363c((longlong)param_1,(longlong)(param_1 + 0x28),0xe);
  uVar3 = 0xe;
  FUN_0001363c((longlong)param_1,(longlong)(param_1 + 0x38),0xe);
  hmu_stop(param_1);
  iVar2 = 0;
  *(undefined4 *)(*(longlong *)(param_1 + 8) + 0xa0) =
       *(undefined4 *)(*(longlong *)(param_1 + 8) + 0x9c);
  LOCK();
  UNLOCK();
  uVar1 = 1000;
  do {
    if (uVar1 < 0x3e9) {
      StorPortStallExecution(uVar1);
      uVar1 = 0;
    }
    else {
      StorPortStallExecution(1000);
      uVar1 = uVar1 - 1000;
    }
  } while (uVar1 != 0);
  *(uint *)(*(longlong *)(param_1 + 8) + 0x20) =
       *(uint *)(*(longlong *)(param_1 + 8) + 0x20) | 0x100;
  LOCK();
  UNLOCK();
  uVar1 = 5000000;
  do {
    if (uVar1 < 0x3e9) {
      StorPortStallExecution(uVar1);
      uVar1 = 0;
    }
    else {
      StorPortStallExecution(1000);
      uVar1 = uVar1 - 1000;
    }
  } while (uVar1 != 0);
  do {
    uVar1 = 1000;
    do {
      if (uVar1 < 0x3e9) {
        StorPortStallExecution(uVar1);
        uVar1 = 0;
      }
      else {
        StorPortStallExecution(1000);
        uVar1 = uVar1 - 1000;
      }
    } while (uVar1 != 0);
  } while ((-1 < **(int **)(param_1 + 8)) && (iVar2 = iVar2 + 1, iVar2 < 50000));
  *(undefined4 *)(param_1 + 0x20a8) = 1;
  FUN_00013270((longlong *)param_1,60000,(uchar *)CONCAT71(in_register_00000081,uVar3),in_R9);
  return;
}



===== hmu_timer_tick @ 00013cd4 =====

/* void __cdecl hmu_timer_tick(struct _hmu_t * __ptr64) */

void __cdecl hmu_timer_tick(_hmu_t *param_1)

{
  void *pvVar1;
  _hmu_t *p_Var2;
  int iVar3;
  ulonglong uVar4;
  
  iVar3 = fw_agree2reset;
  pvVar1 = *(void **)param_1;
  if (*(int *)((longlong)pvVar1 + 0x84) == 1) {
    return;
  }
  uVar4 = (ulonglong)(uint)fw_agree2reset;
  if ((*(uint *)((longlong)pvVar1 + 0xc4) == 0) && (fw_agree2reset == 0)) {
    p_Var2 = *(_hmu_t **)(param_1 + 0x40);
    if (p_Var2 == param_1 + 0x38) {
      return;
    }
    *(short *)(p_Var2 + 0x1e) = *(short *)(p_Var2 + 0x1e) + 1;
    if (*(ushort *)(p_Var2 + 0x1e) < *(ushort *)((longlong)pvVar1 + 200)) {
      return;
    }
  }
  else if (((*(uint *)((longlong)pvVar1 + 0xc4) & 2) == 0) && (fw_agree2reset == 0)) {
    return;
  }
  if (*(int *)(*(longlong *)param_1 + 0x84) == 2) {
    FUN_00013b4c(param_1,uVar4,2,0);
  }
  else if (*(int *)(*(longlong *)param_1 + 0x84) == 5) {
    if (support_reset == 0) {
      if (iVar3 != 0) {
        fw_agree2reset = 0;
      }
    }
    else if (iVar3 != 0) {
      fw_agree2reset = 0;
      yellowstone_reset_iop(param_1);
      goto LAB_00013daa;
    }
    if (prvtSRBcalled == '\0') {
      if (support_reset != 0) {
        QueryFW4Reset(pvVar1);
      }
    }
    else if (support_reset != 0) {
      prvtSRBcalled = '\0';
      fw_agree2reset = 1;
    }
  }
LAB_00013daa:
  if ((*(uint *)((longlong)pvVar1 + 0xc4) & 2) != 0) {
    *(uint *)((longlong)pvVar1 + 0xc4) = *(uint *)((longlong)pvVar1 + 0xc4) & 0xfffffffd;
  }
  return;
}



===== FUN_00013dcc @ 00013dcc =====

void FUN_00013dcc(longlong param_1)

{
  uint uVar1;
  uint *puVar2;
  longlong *plVar3;
  uint uVar4;
  
  puVar2 = *(uint **)(param_1 + 0x78);
  if (((*puVar2 & 0x20000000) == 0) || (*(char *)(*(longlong *)(param_1 + 0x48) + 8) != -0x80)) {
    if (*(longlong *)(param_1 + 0x40) == param_1 + 0x38) {
      puVar2 = puVar2 + *(ushort *)(param_1 + 0x72);
      uVar1 = *puVar2;
      while ((int)uVar1 < 0) {
        *puVar2 = 0;
        *(short *)(param_1 + 0x72) = *(short *)(param_1 + 0x72) + 1;
        if (*(ushort *)(param_1 + 0x70) <= *(ushort *)(param_1 + 0x72)) {
          *(undefined2 *)(param_1 + 0x72) = 0;
        }
        puVar2 = (uint *)(*(longlong *)(param_1 + 0x78) + (ulonglong)*(ushort *)(param_1 + 0x72) * 4
                         );
        uVar1 = *puVar2;
      }
    }
    else {
      puVar2 = puVar2 + *(ushort *)(param_1 + 0x72);
      uVar1 = *puVar2;
      while ((int)uVar1 < 0) {
        uVar4 = uVar1 & 0xffff;
        *puVar2 = 0;
        if (uVar4 == 0xffffffff) {
          return;
        }
        plVar3 = *(longlong **)(param_1 + ((ulonglong)uVar4 + 0xb) * 0x10);
        if (plVar3 == (longlong *)0x0) {
          return;
        }
        if ((uVar1 >> 0x1e & 1) == 0) {
          (**(code **)(param_1 + 0x20))
                    (*(undefined8 *)(param_1 + 0x10),plVar3,
                     (ulonglong)*(ushort *)(param_1 + 0x72) * 0x88 + *(longlong *)(param_1 + 0x60));
        }
        else {
          *(undefined2 *)(plVar3[6] + 3) = 1;
        }
        *(short *)(param_1 + 0x72) = *(short *)(param_1 + 0x72) + 1;
        if (*(ushort *)(param_1 + 0x70) <= *(ushort *)(param_1 + 0x72)) {
          *(undefined2 *)(param_1 + 0x72) = 0;
        }
        puVar2 = (uint *)(*(longlong *)(param_1 + 0x78) + (ulonglong)*(ushort *)(param_1 + 0x72) * 4
                         );
        uVar1 = *puVar2;
        tagpool_release((_tag_pool_t *)(param_1 + 0x90),uVar4);
        *(short *)(param_1 + 0x20ae) = *(short *)(param_1 + 0x20ae) + -1;
        *(longlong *)(*plVar3 + 8) = plVar3[1];
        *(longlong *)plVar3[1] = *plVar3;
        (*(code *)plVar3[4])(plVar3[5],plVar3,4);
      }
    }
  }
  return;
}



===== hmu_check_intr @ 00013f3c =====

/* int __cdecl hmu_check_intr(struct _hmu_t * __ptr64) */

int __cdecl hmu_check_intr(_hmu_t *param_1)

{
  int iVar1;
  
  if (*(int *)(*(longlong *)(param_1 + 0x10) + 0x84) == 5) {
    iVar1 = *(int *)(*(longlong *)(param_1 + 8) + 0x9c);
    if ((iVar1 == -1) && (*(int *)(param_1 + 0x20a8) == 6)) {
      return 0;
    }
  }
  else {
    iVar1 = *(int *)(*(longlong *)(param_1 + 8) + 0x2c);
    if ((iVar1 == -1) && (*(int *)(param_1 + 0x20a8) == 6)) {
      return 0;
    }
    *(undefined4 *)(*(longlong *)(param_1 + 8) + 0x30) =
         *(undefined4 *)(*(longlong *)(param_1 + 8) + 0x30);
    LOCK();
    UNLOCK();
  }
  return (int)(iVar1 != 0);
}



===== FUN_00013fa4 @ 00013fa4 =====

undefined8
FUN_00013fa4(longlong *param_1,_comp_iter_dir_t param_2,_comp_noti_type_t param_3,__uint64 param_4)

{
  undefined8 uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1[1] + 0x9c);
  if ((uVar2 == 0) || ((uVar2 == 0xffffffff && ((int)param_1[0x415] == 6)))) {
    uVar1 = 0;
  }
  else {
    *(uint *)(param_1[1] + 0xa0) = uVar2;
    LOCK();
    UNLOCK();
    if ((int)param_1[0x415] == 5) {
      if ((uVar2 >> 0xc & 1) != 0) {
        uVar2 = uVar2 & 0xffffefff;
        StorPortNotification(7,*param_1);
      }
      if ((uVar2 >> 0xd & 1) != 0) {
        *(uint *)(*param_1 + 0xc4) = *(uint *)(*param_1 + 0xc4) | 2;
        uVar2 = uVar2 & 0xffffdfff;
      }
      FUN_00013dcc((longlong)param_1);
      if (((uVar2 & 2) != 0) &&
         (*(ushort *)((longlong)param_1 + 0x20ae) < *(ushort *)((longlong)param_1 + 0x20ac))) {
        StorPortReady(*param_1);
      }
      FUN_00013808((longlong)param_1);
    }
    else {
      if ((int)param_1[0x415] == 6) {
        *(undefined4 *)(param_1 + 0x415) = 1;
      }
      if (*(int *)(param_1[2] + 0x84) == 5) {
        FUN_0001445c(param_1,param_2,param_3,param_4);
      }
      else {
        FUN_00014694(param_1,param_2,param_3,param_4);
      }
    }
    uVar1 = 1;
  }
  return uVar1;
}



===== FUN_0001408c @ 0001408c =====

void FUN_0001408c(longlong param_1)

{
  uint uVar1;
  longlong *plVar2;
  ushort uVar3;
  ushort *puVar4;
  
  uVar1 = *(uint *)(*(longlong *)(param_1 + 8) + 0x1c);
  if (*(longlong *)(param_1 + 0x40) == param_1 + 0x38) {
    *(short *)(param_1 + 0x72) = (short)uVar1;
  }
  else if (*(int *)(param_1 + 0x20a8) == 5) {
    uVar3 = *(ushort *)(param_1 + 0x72);
    while (uVar3 != uVar1) {
      puVar4 = (ushort *)
               ((ulonglong)*(ushort *)(param_1 + 0x72) * 0x88 + *(longlong *)(param_1 + 0x60));
      if ((*puVar4 == 0xffffffff) ||
         (plVar2 = *(longlong **)(param_1 + ((ulonglong)*puVar4 + 0xb) * 0x10),
         plVar2 == (longlong *)0x0)) break;
      if (plVar2 == *(longlong **)(param_1 + 0x2510)) {
        *(short *)(param_1 + 0x72) = *(short *)(param_1 + 0x72) + 1;
        if (*(ushort *)(param_1 + 0x70) <= *(ushort *)(param_1 + 0x72)) {
          *(undefined2 *)(param_1 + 0x72) = 0;
        }
        tagpool_release((_tag_pool_t *)(param_1 + 0x90),(uint)*puVar4);
        *(short *)(param_1 + 0x20ae) = *(short *)(param_1 + 0x20ae) + -1;
        *(longlong *)(*plVar2 + 8) = plVar2[1];
        *(longlong *)plVar2[1] = *plVar2;
        *(undefined8 *)(param_1 + 0x2510) = 0;
        break;
      }
      uVar3 = *(ushort *)(param_1 + 0x72) + 1;
      *(ushort *)(param_1 + 0x72) = uVar3;
      if (*(ushort *)(param_1 + 0x70) <= uVar3) {
        *(undefined2 *)(param_1 + 0x72) = 0;
      }
      tagpool_release((_tag_pool_t *)(param_1 + 0x90),(uint)*puVar4);
      (**(code **)(param_1 + 0x20))(*(undefined8 *)(param_1 + 0x10),plVar2,puVar4);
      *(short *)(param_1 + 0x20ae) = *(short *)(param_1 + 0x20ae) + -1;
      *(longlong *)(*plVar2 + 8) = plVar2[1];
      *(longlong *)plVar2[1] = *plVar2;
      (*(code *)plVar2[4])(plVar2[5],plVar2,4);
      uVar3 = *(ushort *)(param_1 + 0x72);
    }
  }
  *(uint *)(*(longlong *)(param_1 + 8) + 0x14) = (uint)*(ushort *)(param_1 + 0x72);
  LOCK();
  UNLOCK();
  return;
}



===== FUN_00014200 @ 00014200 =====

undefined8
FUN_00014200(longlong *param_1,_comp_iter_dir_t param_2,_comp_noti_type_t param_3,__uint64 param_4)

{
  uint *puVar1;
  longlong lVar2;
  undefined8 uVar3;
  uint uVar4;
  
  lVar2 = *param_1;
  uVar4 = *(uint *)(param_1[1] + 0x2c);
  if (uVar4 == 0) {
    uVar3 = 0;
  }
  else {
    *(uint *)(param_1[1] + 0x2c) = uVar4;
    LOCK();
    UNLOCK();
    if ((uVar4 & 8) != 0) {
      param_2 = (_comp_iter_dir_t)*param_1;
      param_3 = 0;
      uVar4 = uVar4 & 0xfffffff7;
      StorPortNotification(7);
    }
    if ((uVar4 & 0x10) != 0) {
      uVar4 = uVar4 & 0xffffffef;
    }
    if ((*(int *)(lVar2 + 0x84) == 2) && ((uVar4 >> 0x1b & 1) != 0)) {
      uVar4 = uVar4 & 0xf7ffffff;
      puVar1 = (uint *)(lVar2 + 0xc4);
      *puVar1 = *puVar1 | 2;
    }
    if (uVar4 != 0) {
      if ((int)param_1[0x415] == 5) {
        if ((uVar4 & 4) != 0) {
          FUN_0001408c((longlong)param_1);
        }
        if (((uVar4 & 2) != 0) &&
           (*(ushort *)((longlong)param_1 + 0x20ae) < *(ushort *)((longlong)param_1 + 0x20ac))) {
          StorPortReady(*param_1);
        }
        FUN_00013808((longlong)param_1);
      }
      else if (*(int *)(param_1[2] + 0x84) == 5) {
        FUN_0001445c(param_1,param_2,param_3,param_4);
      }
      else {
        FUN_00014694(param_1,param_2,param_3,param_4);
      }
    }
    uVar3 = 1;
  }
  return uVar3;
}



===== hmu_handle_intr @ 000142ec =====

/* int __cdecl hmu_handle_intr(struct _hmu_t * __ptr64) */

int __cdecl hmu_handle_intr(_hmu_t *param_1)

{
  int iVar1;
  undefined8 uVar2;
  _comp_iter_dir_t in_EDX;
  uint uVar3;
  _comp_noti_type_t in_R8D;
  __uint64 in_R9;
  
  if (*(int *)(*(longlong *)(param_1 + 0x10) + 0x84) != 5) {
    uVar2 = FUN_00014200((longlong *)param_1,in_EDX,in_R8D,in_R9);
    return (int)uVar2;
  }
  uVar3 = *(uint *)(*(longlong *)(param_1 + 8) + 0x9c);
  if ((uVar3 == 0) || ((uVar3 == 0xffffffff && (*(int *)(param_1 + 0x20a8) == 6)))) {
    iVar1 = 0;
  }
  else {
    *(uint *)(*(longlong *)(param_1 + 8) + 0xa0) = uVar3;
    LOCK();
    UNLOCK();
    if (*(int *)(param_1 + 0x20a8) == 5) {
      if ((uVar3 >> 0xc & 1) != 0) {
        uVar3 = uVar3 & 0xffffefff;
        StorPortNotification(7,*(undefined8 *)param_1);
      }
      if ((uVar3 >> 0xd & 1) != 0) {
        *(uint *)(*(longlong *)param_1 + 0xc4) = *(uint *)(*(longlong *)param_1 + 0xc4) | 2;
        uVar3 = uVar3 & 0xffffdfff;
      }
      FUN_00013dcc((longlong)param_1);
      if (((uVar3 & 2) != 0) && (*(ushort *)(param_1 + 0x20ae) < *(ushort *)(param_1 + 0x20ac))) {
        StorPortReady(*(undefined8 *)param_1);
      }
      FUN_00013808((longlong)param_1);
    }
    else {
      if (*(int *)(param_1 + 0x20a8) == 6) {
        *(undefined4 *)(param_1 + 0x20a8) = 1;
      }
      if (*(int *)(*(longlong *)(param_1 + 0x10) + 0x84) == 5) {
        FUN_0001445c(param_1,in_EDX,in_R8D,in_R9);
      }
      else {
        FUN_00014694((longlong *)param_1,in_EDX,in_R8D,in_R9);
      }
    }
    iVar1 = 1;
  }
  return iVar1;
}



===== hmu_query_if @ 00014308 =====

/* int __cdecl hmu_query_if(struct _hmu_t * __ptr64,struct _guid_t const * __ptr64,struct _if_impl_t
   * __ptr64,enum _comp_iter_dir_t,void * __ptr64) */

int __cdecl
hmu_query_if(_hmu_t *param_1,_guid_t *param_2,_if_impl_t *param_3,_comp_iter_dir_t param_4,
            void *param_5)

{
  undefined **ppuVar1;
  
  if ((*(longlong *)param_2 == 0x457201f95118fab0) &&
     (*(longlong *)(param_2 + 8) == -0x2104ca13e8adbc4e)) {
    ppuVar1 = &hmu_if_cmdhdlr;
  }
  else {
    if ((*(longlong *)param_2 != 0x45bb0e2581eaf6ba) ||
       (*(longlong *)(param_2 + 8) != -0x57564a492b3ba5f)) {
      return 0;
    }
    ppuVar1 = &hmu_if_intr;
  }
  *(undefined ***)(param_3 + 8) = ppuVar1;
  *(_hmu_t **)param_3 = param_1;
  return 1;
}



===== FUN_00014360 @ 00014360 =====

void FUN_00014360(longlong param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined1 uVar2;
  bool bVar3;
  
  *param_2 = *(undefined4 *)(param_1 + 0x50);
  uVar1 = *(undefined4 *)(param_1 + 0x54);
  *(undefined1 *)(param_2 + 2) = 0x80;
  param_2[1] = uVar1;
  param_2[4] = *(undefined4 *)(param_1 + 0x50);
  param_2[5] = *(undefined4 *)(param_1 + 0x54);
  *(undefined2 *)(param_2 + 6) = 0x200;
  *(undefined2 *)((longlong)param_2 + 0x1a) = *(undefined2 *)(param_1 + 0x58);
  *(undefined2 *)(param_2 + 7) = 0x88;
  *(undefined2 *)((longlong)param_2 + 0x1e) = *(undefined2 *)(param_1 + 0x70);
  *(undefined1 *)((longlong)param_2 + 0x2b) = 0;
  OsiGetCurrentTime((u64_t *)(param_2 + 8),0,(uchar *)((longlong)param_2 + 0x2a));
  if ((int)DAT_000161f0 == 1) {
    *(undefined1 *)(param_2 + 10) = 0;
  }
  else if ((int)DAT_000161f0 == 2) {
    uVar2 = 1;
    if (gIsLdrDump == '\x01') {
      uVar2 = 4;
    }
    *(undefined1 *)(param_2 + 10) = uVar2;
  }
  else if ((int)DAT_000161f0 == 3) {
    *(undefined1 *)(param_2 + 10) = 2;
  }
  else if ((int)DAT_000161f0 == 4) {
    *(undefined1 *)(param_2 + 10) = 5;
  }
  else if ((int)DAT_000161f0 == 5) {
    *(undefined1 *)(param_2 + 10) = 6;
  }
  bVar3 = DAT_000161f0._4_4_ != 0;
  param_2[0xc] = 5;
  param_2[0xd] = 1;
  param_2[0xe] = 0;
  param_2[0xf] = 10;
  *(bool *)((longlong)param_2 + 0x29) = bVar3;
  param_2[0x10] = *(undefined4 *)(param_1 + 0x20b4);
  param_2[0x11] = *(undefined4 *)(param_1 + 0x20b8);
  param_2[0x12] = (uint)*(ushort *)(param_1 + 0x70) << 2;
  return;
}



===== FUN_0001445c @ 0001445c =====

void FUN_0001445c(void *param_1,_comp_iter_dir_t param_2,_comp_noti_type_t param_3,__uint64 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  __uint64 in_stack_ffffffffffffffe8;
  
  iVar1 = *(int *)((longlong)param_1 + 0x20a8);
  if (iVar1 == 0) {
    return;
  }
  if (iVar1 == 1) {
    *(undefined4 *)((longlong)param_1 + 0x20a8) = 2;
LAB_000144a1:
    *(undefined4 *)((longlong)param_1 + 0x20a8) = 3;
    *(ushort *)((longlong)param_1 + 0x90) = *(ushort *)((longlong)param_1 + 0x20ac);
    FUN_00014844((ushort *)((longlong)param_1 + 0x90));
  }
  else {
    if (iVar1 == 2) goto LAB_000144a1;
    if (iVar1 != 3) {
      if (iVar1 != 4) {
        return;
      }
      goto LAB_0001453c;
    }
  }
  puVar2 = *(undefined4 **)((longlong)param_1 + 0x48);
  FUN_00014360((longlong)param_1,puVar2);
  *(undefined4 *)((longlong)param_1 + 0x20a8) = 4;
  *(uint *)(*(longlong *)((longlong)param_1 + 8) + 0x34) =
       *(uint *)(*(longlong *)((longlong)param_1 + 8) + 0x34) & 0xfffffffb;
  LOCK();
  UNLOCK();
  *(undefined4 *)(*(longlong *)((longlong)param_1 + 8) + 0xc4) =
       *(undefined4 *)((longlong)param_1 + 0x54);
  LOCK();
  UNLOCK();
  *(undefined4 *)(*(longlong *)((longlong)param_1 + 8) + 0xc0) =
       *(undefined4 *)((longlong)param_1 + 0x50);
  LOCK();
  UNLOCK();
  uVar3 = 1000;
  do {
    if (uVar3 < 0x3e9) {
      StorPortStallExecution(uVar3);
      uVar3 = 0;
    }
    else {
      StorPortStallExecution(1000);
      uVar3 = uVar3 - 1000;
    }
    param_2 = (_comp_iter_dir_t)puVar2;
  } while (uVar3 != 0);
LAB_0001453c:
  if ((**(uint **)((longlong)param_1 + 0x78) & 0x20000000) != 0) {
    **(uint **)((longlong)param_1 + 0x78) = 0;
    *(undefined1 *)(*(longlong *)((longlong)param_1 + 0x48) + 8) = 0;
    *(undefined2 *)((longlong)param_1 + 0x5a) = 0;
    *(undefined2 *)((longlong)param_1 + 0x72) = 0;
    *(undefined4 *)((longlong)param_1 + 0x20a8) = 5;
    compmgr_on_notify(param_1,param_2,param_3,param_4,in_stack_ffffffffffffffe8);
    FUN_00013808((longlong)param_1);
  }
  return;
}



===== FUN_0001458c @ 0001458c =====

void FUN_0001458c(longlong *param_1,undefined4 *param_2)

{
  undefined1 uVar1;
  int iVar2;
  bool bVar3;
  
  iVar2 = 1;
  *param_2 = (int)param_1[10];
  param_2[1] = *(undefined4 *)((longlong)param_1 + 0x54);
  *(undefined2 *)(param_2 + 2) = 0x418;
  *(short *)((longlong)param_2 + 10) = (short)param_1[0xb];
  *(undefined2 *)(param_2 + 3) = 0x88;
  *(short *)((longlong)param_2 + 0xe) = (short)param_1[0xe];
  *(bool *)((longlong)param_2 + 0x1b) = *(int *)(*param_1 + 0x84) == 1;
  if ((*(int *)(*param_1 + 0x84) == 1) || (*(int *)(*param_1 + 0x84) == 3)) {
    iVar2 = 0;
  }
  OsiGetCurrentTime((u64_t *)(param_2 + 4),iVar2,(uchar *)((longlong)param_2 + 0x1a));
  if ((int)DAT_000161f0 == 1) {
    *(undefined1 *)(param_2 + 6) = 0;
  }
  else if ((int)DAT_000161f0 == 2) {
    uVar1 = 1;
    if (gIsLdrDump == '\x01') {
      uVar1 = 4;
    }
    *(undefined1 *)(param_2 + 6) = uVar1;
  }
  else if ((int)DAT_000161f0 == 3) {
    *(undefined1 *)(param_2 + 6) = 2;
  }
  else if ((int)DAT_000161f0 == 4) {
    *(undefined1 *)(param_2 + 6) = 5;
  }
  else if ((int)DAT_000161f0 == 5) {
    *(undefined1 *)(param_2 + 6) = 6;
  }
  bVar3 = DAT_000161f0._4_4_ != 0;
  param_2[8] = 5;
  param_2[9] = 1;
  param_2[10] = 0;
  param_2[0xb] = 10;
  *(bool *)((longlong)param_2 + 0x19) = bVar3;
  param_2[0xc] = *(undefined4 *)((longlong)param_1 + 0x20b4);
  param_2[0xd] = (int)param_1[0x417];
  return;
}



===== FUN_00014694 @ 00014694 =====

void FUN_00014694(longlong *param_1,_comp_iter_dir_t param_2,_comp_noti_type_t param_3,
                 __uint64 param_4)

{
  int iVar1;
  ushort uVar2;
  undefined4 *puVar3;
  uint uVar4;
  __uint64 in_stack_ffffffffffffffe8;
  
  iVar1 = (int)param_1[0x415];
  if (iVar1 == 0) {
    return;
  }
  if (iVar1 == 1) {
    if (*(int *)(param_1[1] + 0x18) != 0x55aaaa55) {
      *(undefined4 *)(param_1[1] + 0x20) = 1;
      LOCK();
      UNLOCK();
      return;
    }
    *(undefined4 *)(param_1 + 0x415) = 3;
    uVar4 = *(uint *)(param_1[1] + 0x1c);
    uVar2 = (ushort)uVar4;
    if ((uVar4 & 0xffff0000) != 0x5a5a0000) {
      uVar2 = 0x200;
    }
    if (uVar2 < *(ushort *)((longlong)param_1 + 0x20ac)) {
      *(ushort *)((longlong)param_1 + 0x20ac) = uVar2;
    }
    *(ushort *)(param_1 + 0x12) = *(ushort *)((longlong)param_1 + 0x20ac);
    FUN_00014844((ushort *)(param_1 + 0x12));
  }
  else if (iVar1 != 3) {
    if (iVar1 != 4) {
      return;
    }
    goto LAB_000147b4;
  }
  puVar3 = (undefined4 *)param_1[0xc];
  FUN_0001458c(param_1,puVar3);
  *(undefined4 *)(param_1 + 0x415) = 4;
  *(int *)(param_1[1] + 0x10) = (int)param_1[0xd];
  LOCK();
  UNLOCK();
  *(undefined4 *)(param_1[1] + 0x14) = *(undefined4 *)((longlong)param_1 + 0x6c);
  LOCK();
  UNLOCK();
  *(undefined4 *)(param_1[1] + 0x18) = *(undefined4 *)((longlong)param_1 + 0x6c);
  LOCK();
  UNLOCK();
  *(undefined4 *)(param_1[1] + 0x20) = 1;
  LOCK();
  UNLOCK();
  uVar4 = 1000;
  do {
    if (uVar4 < 0x3e9) {
      StorPortStallExecution(uVar4);
      uVar4 = 0;
    }
    else {
      StorPortStallExecution(1000);
      uVar4 = uVar4 - 1000;
    }
    param_2 = (_comp_iter_dir_t)puVar3;
  } while (uVar4 != 0);
LAB_000147b4:
  if (*(int *)(param_1[1] + 0x18) == 0x55aaaa55) {
    *(undefined4 *)(param_1[1] + 0x2c) = *(undefined4 *)(param_1[1] + 0x2c);
    LOCK();
    UNLOCK();
    *(undefined4 *)(param_1[1] + 0x30) = *(undefined4 *)(param_1[1] + 0x30);
    LOCK();
    UNLOCK();
    *(undefined4 *)(param_1 + 0x415) = 5;
    *(undefined4 *)(param_1[1] + 0x10) = 0;
    LOCK();
    UNLOCK();
    *(undefined4 *)(param_1[1] + 0x14) = 0;
    LOCK();
    UNLOCK();
    *(undefined4 *)(param_1[1] + 0x18) = 0;
    LOCK();
    UNLOCK();
    *(undefined4 *)(param_1[1] + 0x1c) = 0;
    LOCK();
    UNLOCK();
    compmgr_on_notify(param_1,param_2,param_3,param_4,in_stack_ffffffffffffffe8);
    FUN_00013808((longlong)param_1);
  }
  return;
}



===== FUN_00014844 @ 00014844 =====

void FUN_00014844(ushort *param_1)

{
  int iVar1;
  ushort *puVar2;
  ushort *puVar3;
  ulonglong uVar4;
  uint uVar5;
  ushort uVar6;
  
  puVar2 = param_1 + 0xc;
  puVar2[0] = 0;
  puVar2[1] = 0;
  puVar2[2] = 0;
  puVar2[3] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  uVar6 = 0;
  if (0 < (int)(*param_1 - 1)) {
    uVar5 = 0;
    do {
      iVar1 = uVar5 + 1;
      uVar4 = (ulonglong)uVar6;
      uVar6 = uVar6 + 1;
      uVar5 = (uint)uVar6;
      *(ushort **)(param_1 + uVar4 * 8 + 0xc) = param_1 + (longlong)iVar1 * 8 + 0xc;
    } while ((int)uVar5 < (int)(*param_1 - 1));
  }
  puVar3 = param_1 + (ulonglong)uVar6 * 8 + 0xc;
  puVar3[0] = 0;
  puVar3[1] = 0;
  puVar3[2] = 0;
  puVar3[3] = 0;
  *(ushort **)(param_1 + 4) = puVar2;
  param_1[1] = 0;
  *(ushort **)(param_1 + 8) = param_1 + (longlong)(int)(*param_1 - 1) * 8 + 0xc;
  return;
}



===== tagpool_release @ 000148d8 =====

/* void __cdecl tagpool_release(struct _tag_pool_t * __ptr64,unsigned int) */

void __cdecl tagpool_release(_tag_pool_t *param_1,uint param_2)

{
  _tag_pool_t *p_Var1;
  
  p_Var1 = param_1 + (ulonglong)param_2 * 0x10 + 0x18;
  *(undefined8 *)p_Var1 = 0;
  *(undefined8 *)(p_Var1 + 8) = 0;
  if (*(undefined8 **)(param_1 + 0x10) != (undefined8 *)0x0) {
    **(undefined8 **)(param_1 + 0x10) = p_Var1;
  }
  if (*(longlong *)(param_1 + 8) == 0) {
    *(_tag_pool_t **)(param_1 + 8) = p_Var1;
  }
  *(_tag_pool_t **)(param_1 + 0x10) = p_Var1;
  *(short *)(param_1 + 2) = *(short *)(param_1 + 2) + -1;
  return;
}



===== entry @ 0001491c =====

void entry(longlong param_1,longlong param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_check_cookie @ 00014960 =====

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



===== __GSHandlerCheck @ 00014998 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 000149bc =====

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



===== memset @ 00014a30 =====

void * __cdecl memset(void *_Dst,int _Val,size_t _Size)

{
  void *pvVar1;
  uint uVar2;
  ulonglong *puVar3;
  ulonglong uVar4;
  size_t sVar5;
  ulonglong uVar6;
  
  uVar4 = (ulonglong)(uint)_Val;
  pvVar1 = _Dst;
  sVar5 = _Size;
  if (7 < _Size) {
    uVar4 = (ulonglong)(byte)_Val * 0x101010101010101;
    if (0x3f < _Size) {
      uVar2 = -(int)_Dst & 7;
      if (uVar2 != 0) {
        sVar5 = _Size - uVar2;
        *(ulonglong *)_Dst = uVar4;
      }
      _Dst = (void *)((ulonglong)uVar2 + (longlong)_Dst);
      _Size = sVar5 & 0x3f;
      uVar6 = sVar5 >> 6;
      if (uVar6 != 0) {
        puVar3 = _Dst;
        if (uVar6 < 0x1c00) {
          do {
            *puVar3 = uVar4;
            puVar3[1] = uVar4;
            puVar3[2] = uVar4;
            _Dst = puVar3 + 8;
            puVar3[3] = uVar4;
            puVar3[4] = uVar4;
            uVar6 = uVar6 - 1;
            puVar3[5] = uVar4;
            puVar3[6] = uVar4;
            puVar3[7] = uVar4;
            puVar3 = _Dst;
          } while (uVar6 != 0);
        }
        else {
          do {
            *puVar3 = uVar4;
            puVar3[1] = uVar4;
            puVar3[2] = uVar4;
            _Dst = puVar3 + 8;
            puVar3[3] = uVar4;
            puVar3[4] = uVar4;
            uVar6 = uVar6 - 1;
            puVar3[5] = uVar4;
            puVar3[6] = uVar4;
            puVar3[7] = uVar4;
            puVar3 = _Dst;
          } while (uVar6 != 0);
          LOCK();
          UNLOCK();
        }
      }
    }
    sVar5 = _Size & 7;
    for (uVar6 = _Size >> 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(ulonglong *)_Dst = uVar4;
      _Dst = (void *)((longlong)_Dst + 8);
    }
  }
  for (; sVar5 != 0; sVar5 = sVar5 - 1) {
    *(char *)_Dst = (char)uVar4;
    _Dst = (void *)((longlong)_Dst + 1);
  }
  return pvVar1;
}



===== __security_init_cookie @ 00018008 =====

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


