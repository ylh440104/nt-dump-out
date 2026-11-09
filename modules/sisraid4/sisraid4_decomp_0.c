
===== AHCIGetFreeCommandSlot @ 00011008 =====

ulonglong AHCIGetFreeCommandSlot(longlong param_1,byte param_2,byte param_3,char param_4)

{
  char cVar1;
  byte bVar2;
  bool bVar3;
  uint uVar4;
  ulonglong uVar5;
  byte bVar6;
  longlong lVar7;
  uint uVar8;
  
  bVar3 = false;
  if (*(char *)(param_1 + 0x768d) == '\0') {
    lVar7 = (ulonglong)param_2 * 0xe28;
    uVar8 = *(uint *)(lVar7 + 0xe64 + param_1) | *(uint *)(lVar7 + 0xe68 + param_1);
    uVar4 = *(uint *)(lVar7 + 0xe60 + param_1) | uVar8;
    uVar5 = (ulonglong)uVar4;
    if ((uVar4 >> (*(byte *)(lVar7 + 0xd5a + param_1) & 0x1f) & 1) != 0) {
      do {
        if (param_4 == '\x01') {
          uVar5 = *(ulonglong *)(lVar7 + 0x58 + param_1);
          if ((*(int *)(uVar5 + 0x34) == 0) && (*(int *)(lVar7 + 0xe64 + param_1) == 0)) {
            bVar6 = *(byte *)(lVar7 + 0xd5a + param_1);
            uVar4 = *(uint *)(lVar7 + 0xe60 + param_1) | *(uint *)(lVar7 + 0xe68 + param_1);
            uVar5 = (ulonglong)uVar4;
            uVar4 = 1 << (bVar6 & 0x1f) & uVar4;
LAB_00011111:
            bVar3 = true;
          }
          else {
            bVar6 = *(byte *)(lVar7 + 0xd5a + param_1);
            uVar4 = 1 << (bVar6 & 0x1f) & uVar8;
          }
        }
        else {
          cVar1 = *(char *)(param_1 + 0x76b6);
          uVar5 = CONCAT71((int7)(uVar5 >> 8),cVar1);
          if ((cVar1 == '`') || (cVar1 == 'a')) {
            bVar6 = *(byte *)(lVar7 + 0xd5a + param_1);
            uVar4 = 1 << (bVar6 & 0x1f) & uVar8;
            goto LAB_00011111;
          }
          bVar6 = *(byte *)(lVar7 + 0xd5a + param_1);
          uVar4 = 1 << (bVar6 & 0x1f);
          uVar5 = (ulonglong)uVar4;
          uVar4 = (*(uint *)(*(longlong *)(lVar7 + 0x58 + param_1) + 0x38) |
                  *(uint *)(lVar7 + 0xe68 + param_1)) & uVar4;
        }
        if (uVar4 == 0) break;
        *(byte *)(lVar7 + 0xd5a + param_1) = bVar6 + 1;
        if (bVar3) {
          bVar2 = *(byte *)((ulonglong)param_3 * 0xc0 + lVar7 + 0x2d2 + param_1);
        }
        else {
          bVar2 = *(byte *)(param_1 + 0x767d);
        }
        uVar5 = 0;
        *(char *)(lVar7 + 0xd5a + param_1) =
             (char)((ulonglong)(byte)(bVar6 + 1) % (ulonglong)(longlong)(int)(uint)bVar2);
      } while( true );
    }
    uVar5 = CONCAT71((int7)(uVar5 >> 8),*(undefined1 *)(lVar7 + 0xd5a + param_1));
  }
  else {
    *(undefined1 *)((ulonglong)param_2 * 0xe28 + 0xd5a + param_1) = 0;
    uVar5 = (ulonglong)param_2 * 0xe28 & 0xffffffffffffff00;
  }
  return uVar5;
}



===== AHCIFillCommand @ 0001117c =====

ulonglong AHCIFillCommand(longlong param_1,byte param_2,byte param_3,void *param_4,longlong param_5,
                         byte param_6,char param_7)

{
  uint *puVar1;
  char *pcVar2;
  undefined4 uVar3;
  void *_Dst;
  uint uVar4;
  undefined4 *puVar5;
  ulonglong uVar6;
  longlong lVar7;
  byte bVar8;
  
  lVar7 = (ulonglong)param_2 * 0xe28;
  puVar5 = (undefined4 *)((ulonglong)param_6 * 0x20 + *(longlong *)(lVar7 + 0x60 + param_1));
  _Dst = *(void **)(param_1 + 0x70 + ((ulonglong)param_2 * 0x1c5 + (ulonglong)param_6) * 8);
  *puVar5 = *(undefined4 *)(param_1 + 0x7694);
  puVar5[1] = *(undefined4 *)(param_1 + 0x7698);
  if ((*(char *)(param_1 + 0x76b6) == 'a') || (*(char *)(param_1 + 0x76b6) == '`')) {
    *(byte *)(param_1 + 0x76c0) = param_6 << 3;
  }
  memcpy(_Dst,(void *)(param_1 + 0x76b4),(longlong)(int)((*(byte *)(param_1 + 0x7694) & 0x1f) << 2))
  ;
  if ((*(byte *)(param_1 + 0x7694) & 0x20) != 0) {
    memcpy((void *)((longlong)_Dst + 0x40),param_4,0x10);
  }
  bVar8 = 0;
  if (*(short *)(param_1 + 0x7696) != 0) {
    do {
      uVar6 = (ulonglong)bVar8;
      bVar8 = bVar8 + 1;
      *(undefined4 *)((longlong)_Dst + uVar6 * 0x10 + 0x80) =
           *(undefined4 *)(param_5 + 4 + uVar6 * 0xc);
      uVar3 = *(undefined4 *)(param_5 + uVar6 * 0xc);
      *(undefined4 *)((longlong)_Dst + uVar6 * 0x10 + 0x88) = 0;
      *(undefined4 *)((longlong)_Dst + uVar6 * 0x10 + 0x84) = uVar3;
      *(int *)((longlong)_Dst + uVar6 * 0x10 + 0x8c) = *(int *)(param_5 + 8 + uVar6 * 0xc) + -1;
    } while ((ushort)bVar8 < *(ushort *)(param_1 + 0x7696));
  }
  puVar1 = (uint *)((ulonglong)bVar8 * 0x10 + 0x7c + (longlong)_Dst);
  *puVar1 = *puVar1 | 0x80000000;
  if (param_7 == '\x01') {
    puVar1 = (uint *)(lVar7 + 0xe68 + param_1);
    *puVar1 = *puVar1 | 1 << (param_6 & 0x1f);
  }
  else {
    uVar4 = 1 << (param_6 & 0x1f);
    if ((*(char *)(param_1 + 0x76b6) == '`') || (*(char *)(param_1 + 0x76b6) == 'a')) {
      *(uint *)(*(longlong *)(lVar7 + 0x58 + param_1) + 0x34) = uVar4;
      puVar1 = (uint *)(lVar7 + 0xe64 + param_1);
      *puVar1 = *puVar1 | uVar4;
    }
    *(uint *)(*(longlong *)(lVar7 + 0x58 + param_1) + 0x38) = uVar4;
    puVar1 = (uint *)(lVar7 + 0xe60 + param_1);
    *puVar1 = *puVar1 | uVar4;
  }
  if ((*(char *)(param_1 + 0x76b6) == '`') || (*(char *)(param_1 + 0x76b6) == 'a')) {
    pcVar2 = (char *)(lVar7 + 0xd5a + param_1);
    *pcVar2 = *pcVar2 + '\x01';
    bVar8 = *(byte *)((ulonglong)param_3 * 0xc0 + lVar7 + 0x2d2 + param_1);
  }
  else {
    pcVar2 = (char *)(lVar7 + 0xd5a + param_1);
    *pcVar2 = *pcVar2 + '\x01';
    bVar8 = *(byte *)(param_1 + 0x767d);
  }
  uVar6 = (ulonglong)*(byte *)(lVar7 + 0xd5a + param_1);
  *(char *)(lVar7 + 0xd5a + param_1) = (char)(uVar6 % (ulonglong)(longlong)(int)(uint)bVar8);
  return uVar6 / (ulonglong)(longlong)(int)(uint)bVar8;
}



===== AHCIProcessPMFatalError @ 00011360 =====

undefined8 AHCIProcessPMFatalError(longlong param_1,byte param_2,undefined1 param_3)

{
  byte *pbVar1;
  byte bVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  longlong lVar5;
  char *pcVar6;
  longlong lVar7;
  ulonglong uVar8;
  uint uVar9;
  char cVar10;
  
  uVar8 = (ulonglong)param_2;
  cVar10 = '\0';
  lVar5 = *(longlong *)(param_1 + 0x38f8 + uVar8 * 8);
  if (((*(byte *)(lVar5 + 0x42) & 1) == 0) || ((*(byte *)(lVar5 + 0x42) & 0x80) != 0)) {
    *(undefined1 *)(param_1 + 0x768a) = 1;
    lVar5 = AHCIPortReset(param_1,param_2);
    if ((char)lVar5 == '\0') {
      uVar4 = StorPortDebugPrint(0,"[FUNCTION] %s :PortReset Failed at port %d subport %d\n",
                                 "AHCIProcessPMFatalError",uVar8,param_3);
      goto LAB_000113ed;
    }
    *(undefined1 *)(uVar8 * 0xe28 + 0xe6f + param_1) = 0;
    pbVar1 = (byte *)(*(longlong *)(uVar8 * 0xe28 + 0x58 + param_1) + 0x18);
    *pbVar1 = *pbVar1 | 1;
  }
  else {
    lVar7 = uVar8 * 0xe28;
    uVar9 = 0;
    pbVar1 = (byte *)(*(longlong *)(lVar7 + 0x58 + param_1) + 0x18);
    *pbVar1 = *pbVar1 & 0xfe;
    if ((*(int *)(lVar7 + 0xe64 + param_1) != 0) &&
       (uVar3 = AHCIPortReset(param_1,param_2), (char)uVar3 == '\0')) {
      pcVar6 = "[FUNCTION] %s : PortReset for NCQ Failed at port %d subport %d\n";
LAB_000113d3:
      uVar4 = StorPortDebugPrint(0,pcVar6,"AHCIProcessPMFatalError",uVar8,param_3);
LAB_000113ed:
      *(undefined1 *)(uVar8 * 0xe28 + 0xe6f + param_1) = 1;
LAB_000113f5:
      return uVar4 & 0xffffffffffffff00;
    }
    bVar2 = *(byte *)(*(longlong *)(lVar7 + 0x58 + param_1) + 0x19);
    while ((bVar2 & 0x80) != 0) {
      if (cVar10 == '\x02') {
        uVar4 = StorPortDebugPrint(0,
                                   "[FUNCTION] %s :Time out,Waiting the PxCmd.CR to be clear for 1000 miliseconds at Port %d subport %d.\n"
                                   ,"AHCIProcessPMFatalError",uVar8,param_3);
        goto LAB_000113f5;
      }
      if (999 < uVar9) {
        cVar10 = cVar10 + '\x01';
        uVar9 = 0;
        *(undefined1 *)(param_1 + 0x768a) = 1;
        StorPortDebugPrint(0,
                           "[FUNCTION] %s :Time out,Waiting the PxCmd.CR to be clear for 500 miliseconds at port %d subport %d\n"
                           ,"AHCIProcessPMFatalError",uVar8,param_3);
        uVar3 = AHCIPortReset(param_1,param_2);
        if ((char)uVar3 == '\0') {
          pcVar6 = "[FUNCTION] %s :PortReset Failed at port %d subport %d\n";
          goto LAB_000113d3;
        }
      }
      uVar9 = uVar9 + 1;
      StorPortStallExecution();
      bVar2 = *(byte *)(*(longlong *)(lVar7 + 0x58 + param_1) + 0x19);
    }
    lVar5 = *(longlong *)(lVar7 + 0x58 + param_1);
    *(undefined1 *)(lVar7 + 0xd5a + param_1) = 0;
    *(byte *)(lVar5 + 0x18) = *(byte *)(lVar5 + 0x18) | 1;
  }
  return CONCAT71((int7)((ulonglong)lVar5 >> 8),1);
}



===== AHCIProcessFatalError @ 00011530 =====

undefined8 AHCIProcessFatalError(longlong param_1,byte param_2,undefined1 param_3)

{
  byte *pbVar1;
  byte bVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  longlong lVar5;
  char *pcVar6;
  longlong lVar7;
  uint uVar8;
  char cVar9;
  
  uVar4 = (ulonglong)param_2;
  cVar9 = '\0';
  lVar7 = uVar4 * 0xe28;
  lVar5 = *(longlong *)(lVar7 + 0x58 + param_1);
  if (((*(byte *)(lVar5 + 0x20) & 1) == 0) || ((*(byte *)(lVar5 + 0x20) & 0x80) != 0)) {
    lVar5 = AHCIPortReset(param_1,param_2);
    if ((char)lVar5 == '\0') {
LAB_00011631:
      pcVar6 = "[FUNCTION] %s :PortReset Failed at port %d subport %d\n";
      goto LAB_0001159b;
    }
    *(undefined1 *)(lVar7 + 0xe6f + param_1) = 0;
    pbVar1 = (byte *)(*(longlong *)(lVar7 + 0x58 + param_1) + 0x18);
    *pbVar1 = *pbVar1 | 1;
  }
  else {
    *(byte *)(lVar5 + 0x18) = *(byte *)(lVar5 + 0x18) & 0xfe;
    uVar8 = 0;
    if ((*(int *)(lVar7 + 0xe64 + param_1) != 0) &&
       (uVar3 = AHCIPortReset(param_1,param_2), (char)uVar3 == '\0')) {
      pcVar6 = "[FUNCTION] %s : PortReset for NCQ Failed at port %d subport %d\n";
LAB_0001159b:
      uVar4 = StorPortDebugPrint(0,pcVar6,"AHCIProcessFatalError",uVar4,param_3);
      *(undefined1 *)(lVar7 + 0xe6f + param_1) = 1;
LAB_000115bd:
      return uVar4 & 0xffffffffffffff00;
    }
    bVar2 = *(byte *)(*(longlong *)(lVar7 + 0x58 + param_1) + 0x19);
    while ((bVar2 & 0x80) != 0) {
      if (cVar9 == '\x02') {
        uVar4 = StorPortDebugPrint(0,
                                   "[FUNCTION] %s :Time out,Waiting the PxCmd.CR to be clear for 1000 miliseconds at Port %d subport %d.\n"
                                   ,"AHCIProcessFatalError",uVar4,param_3);
        goto LAB_000115bd;
      }
      if (999 < uVar8) {
        cVar9 = cVar9 + '\x01';
        uVar8 = 0;
        StorPortDebugPrint(0,
                           "[FUNCTION] %s :Time out,Waiting the PxCmd.CR to be clear for 500 miliseconds at port %d subport %d\n"
                           ,"AHCIProcessFatalError",uVar4,param_3);
        uVar3 = AHCIPortReset(param_1,param_2);
        if ((char)uVar3 == '\0') goto LAB_00011631;
      }
      uVar8 = uVar8 + 1;
      StorPortStallExecution();
      bVar2 = *(byte *)(*(longlong *)(lVar7 + 0x58 + param_1) + 0x19);
    }
    lVar5 = *(longlong *)(lVar7 + 0x58 + param_1);
    *(undefined1 *)(lVar7 + 0xd5a + param_1) = 0;
    *(byte *)(lVar5 + 0x18) = *(byte *)(lVar5 + 0x18) | 1;
  }
  return CONCAT71((int7)((ulonglong)lVar5 >> 8),1);
}



===== AHCIWaitForCommandComplete @ 000116b4 =====

ulonglong AHCIWaitForCommandComplete
                    (longlong param_1,byte param_2,undefined1 param_3,char param_4,int param_5)

{
  byte *pbVar1;
  uint *puVar2;
  char cVar3;
  uint uVar4;
  longlong lVar5;
  bool bVar6;
  ulonglong uVar7;
  byte bVar8;
  longlong lVar9;
  uint uVar10;
  uint uVar11;
  
  bVar6 = true;
  lVar9 = (ulonglong)param_2 * 0xe28;
  cVar3 = *(char *)(lVar9 + 0xd5a + param_1);
  if (cVar3 == '\0') {
    bVar8 = *(byte *)(*(longlong *)(param_1 + 0x10) + 1) & 0x1f;
  }
  else {
    bVar8 = cVar3 - 1;
  }
  uVar10 = 1 << (bVar8 & 0x1f);
  uVar11 = 0;
  uVar4 = *(uint *)(*(longlong *)(lVar9 + 0x58 + param_1) + 0x38);
  while( true ) {
    if ((uVar4 & uVar10) == 0) {
      *(undefined4 *)(*(longlong *)(lVar9 + 0x58 + param_1) + 0x30) = 0xffffffff;
      lVar5 = *(longlong *)(lVar9 + 0x58 + param_1);
      *(undefined4 *)(lVar5 + 0x10) = 0xffffffff;
      if (param_4 == '\0') {
        puVar2 = (uint *)(lVar9 + 0xe60 + param_1);
        *puVar2 = *puVar2 & ~uVar10;
      }
      else {
        *(undefined4 *)(lVar9 + 0xe60 + param_1) = 0;
      }
      return CONCAT71((int7)((ulonglong)lVar5 >> 8),1);
    }
    lVar5 = *(longlong *)(lVar9 + 0x58 + param_1);
    if (((*(byte *)(lVar5 + 0x28) & 0xf) == 0) && ((*(byte *)(lVar9 + 0xd58 + param_1) & 4) == 0))
    break;
    if ((*(uint *)(lVar5 + 0x10) & 0x78000000) != 0) {
      StorPortDebugPrint(0,0x1fe00,"AHCIWaitForCommandComplete",*(uint *)(lVar5 + 0x10),
                         *(undefined4 *)(lVar5 + 0x30),param_2,param_3);
      *(undefined4 *)(*(longlong *)(lVar9 + 0x58 + param_1) + 0x30) = 0xffffffff;
      *(undefined4 *)(*(longlong *)(lVar9 + 0x58 + param_1) + 0x10) = 0xffffffff;
      AHCIProcessFatalError(param_1,param_2,param_3);
      *(undefined4 *)(*(longlong *)(lVar9 + 0x58 + param_1) + 0x30) = 0xffffffff;
      *(undefined4 *)(*(longlong *)(lVar9 + 0x58 + param_1) + 0x10) = 0xffffffff;
      bVar6 = false;
    }
    lVar5 = *(longlong *)(lVar9 + 0x58 + param_1);
    if ((*(char *)(lVar5 + 0x20) == '\x7f') ||
       (((*(byte *)(lVar5 + 0x28) & 0xf) == 0 && ((*(byte *)(lVar9 + 0xd58 + param_1) & 4) == 0))))
    {
      StorPortDebugPrint(0,"[FUNCTION] %s :Px.TFD %lx,Px.DET %lx at port %d subport %d.\n",
                         "AHCIWaitForCommandComplete",*(char *)(lVar5 + 0x20),
                         *(byte *)(lVar5 + 0x28) & 0xf,param_2,param_3);
      *(undefined4 *)(*(longlong *)(lVar9 + 0x58 + param_1) + 0x30) = 0xffffffff;
      *(undefined4 *)(*(longlong *)(lVar9 + 0x58 + param_1) + 0x10) = 0xffffffff;
      bVar6 = false;
    }
    if ((uint)(param_5 * 200) <= uVar11) {
      StorPortDebugPrint(0,
                         "[FUNCTION] %s :Command failed to complete at port %d subport %d,Px->CI %lx CI %lx\n "
                         ,"AHCIWaitForCommandComplete",param_2,param_3,
                         *(undefined4 *)(*(longlong *)(lVar9 + 0x58 + param_1) + 0x38),
                         *(undefined4 *)(lVar9 + 0xe60 + param_1));
      lVar5 = *(longlong *)(lVar9 + 0x58 + param_1);
      StorPortDebugPrint(0,0x1fe00,"AHCIWaitForCommandComplete",*(undefined4 *)(lVar5 + 0x10),
                         *(undefined4 *)(lVar5 + 0x30),param_2,param_3);
      AHCIPortReset(param_1,param_2);
      bVar6 = false;
    }
    lVar5 = *(longlong *)(lVar9 + 0x58 + param_1);
    if ((*(int *)(lVar5 + 0x30) != 0) && ((*(uint *)(lVar5 + 0x30) & 0xfffdfdff) != 0)) {
      bVar6 = false;
    }
    if (!bVar6) {
      *(undefined4 *)(lVar5 + 0x30) = 0xffffffff;
      *(undefined4 *)(*(longlong *)(lVar9 + 0x58 + param_1) + 0x10) = 0xffffffff;
      pbVar1 = (byte *)(*(longlong *)(lVar9 + 0x58 + param_1) + 0x18);
      *pbVar1 = *pbVar1 & 0xfe;
      uVar7 = StorPortStallExecution(500);
      pbVar1 = (byte *)(*(longlong *)(lVar9 + 0x58 + param_1) + 0x18);
      *pbVar1 = *pbVar1 | 1;
      if (param_4 == '\0') {
        puVar2 = (uint *)(lVar9 + 0xe60 + param_1);
        *puVar2 = *puVar2 & ~uVar10;
      }
      else {
        *(undefined4 *)(lVar9 + 0xe60 + param_1) = 0;
      }
      goto LAB_00011967;
    }
    uVar11 = uVar11 + 1;
    StorPortStallExecution(500);
    uVar4 = *(uint *)(*(longlong *)(lVar9 + 0x58 + param_1) + 0x38);
  }
  uVar7 = StorPortDebugPrint(0,
                             "[FUNCTION] %s :Plug Out Occurred at port %d subport %d,PxIS %lx PxSERR %lx PxSSTS %lx. \n"
                             ,"AHCIWaitForCommandComplete",(ulonglong)param_2,param_3,
                             *(undefined4 *)(lVar5 + 0x10),*(undefined4 *)(lVar5 + 0x30),
                             *(undefined4 *)(lVar5 + 0x28));
LAB_00011967:
  return uVar7 & 0xffffffffffffff00;
}



===== AHCIPMDeviceReset @ 000119e0 =====

ulonglong AHCIPMDeviceReset(longlong param_1,byte param_2,byte param_3,byte param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  
  *(byte *)(param_1 + 0x76b5) = *(byte *)(param_1 + 0x76b5) & 0x60;
  *(byte *)(param_1 + 0x76b5) = *(byte *)(param_1 + 0x76b5) | param_4 & 0x1f;
  *(undefined1 *)(param_1 + 0x76b4) = 0x27;
  *(undefined1 *)(param_1 + 0x76c3) = 4;
  *(undefined2 *)(param_1 + 0x7696) = 0;
  *(undefined1 *)(param_1 + 0x7694) = 5;
  *(undefined4 *)(param_1 + 0x7698) = 0;
  *(byte *)(param_1 + 0x7695) = *(byte *)(param_1 + 0x7695) & 8 | param_4 << 4 | 4;
  uVar1 = AHCIGetFreeCommandSlot(param_1,param_2,param_3,'\0');
  AHCIFillCommand(param_1,param_2,param_3,(void *)0x0,0,(byte)uVar1,'\0');
  lVar2 = 100;
  lVar3 = 100;
  do {
    StorPortStallExecution(500);
    lVar3 = lVar3 + -1;
  } while (lVar3 != 0);
  *(byte *)(param_1 + 0x7695) = *(byte *)(param_1 + 0x7695) & 0xfb;
  *(undefined1 *)(param_1 + 0x76c3) = 0;
  *(undefined4 *)(param_1 + 0x7698) = 0;
  uVar1 = AHCIGetFreeCommandSlot(param_1,param_2,param_3,'\0');
  uVar4 = 0;
  AHCIFillCommand(param_1,param_2,param_3,(void *)0x0,0,(byte)uVar1,'\0');
  do {
    StorPortStallExecution(500);
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  uVar5 = (undefined4)((ulonglong)uVar4 >> 0x20);
  uVar1 = AHCIWaitForCommandComplete(param_1,param_2,param_3,'\x01',0x1e);
  if ((char)uVar1 == '\0') {
    uVar1 = StorPortDebugPrint(0,0x1ff00,"AHCIPMDeviceReset",(int)(char)param_2,
                               CONCAT44(uVar5,(uint)param_3));
    uVar1 = uVar1 & 0xffffffffffffff00;
  }
  else {
    lVar2 = *(longlong *)(param_1 + 0x38f8 + (longlong)(char)param_2 * 8);
    lVar3 = (longlong)(char)param_2 * 0xe28;
    if ((*(uint *)(lVar2 + 0x44) & 0xffff00) == 0xeb1400) {
      lVar2 = param_1 + lVar3;
      *(undefined1 *)((ulonglong)param_3 + 0x1fa + lVar2) = 0x11;
    }
    else {
      *(undefined1 *)((ulonglong)param_3 + 0x1fa + param_1 + lVar3) = 1;
    }
    uVar1 = CONCAT71((int7)((ulonglong)lVar2 >> 8),1);
  }
  return uVar1;
}



===== AHCIInitialHBADevice @ 00011b90 =====

void AHCIInitialHBADevice(longlong param_1,undefined8 param_2,undefined8 param_3,ulonglong param_4)

{
  byte *pbVar1;
  bool bVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  byte bVar5;
  byte bVar6;
  longlong lVar7;
  
  bVar5 = 0;
  *(undefined1 *)(param_1 + 0x767a) = 0;
  do {
    bVar2 = false;
    *(undefined2 *)(param_1 + 0x7518) = 0;
    bVar6 = 0;
    if (*(char *)(param_1 + 0x767e) != '\0') {
      do {
        lVar7 = (ulonglong)bVar6 * 0xe28;
        pbVar1 = (byte *)(lVar7 + 0xe78 + param_1);
        *pbVar1 = *pbVar1 & 0xbf;
        pbVar1 = (byte *)(lVar7 + 0xd58 + param_1);
        *pbVar1 = *pbVar1 & 0x1a;
        *(undefined2 *)(lVar7 + 0x1f8 + param_1) = 0;
        *(undefined1 *)(lVar7 + 0xd5a + param_1) = 0;
        *(undefined4 *)(lVar7 + 0xe60 + param_1) = 0;
        *(undefined4 *)(lVar7 + 0xe64 + param_1) = 0;
        *(undefined4 *)(lVar7 + 0xe68 + param_1) = 0;
        *(undefined1 *)(lVar7 + 0xe6d + param_1) = 0;
        *(undefined1 *)(lVar7 + 0xe6c + param_1) = 0;
        uVar3 = AHCISpinUpDevice(param_1,bVar6);
        if ((char)uVar3 == '\0') {
          if ((*(byte *)(*(longlong *)(lVar7 + 0x58 + param_1) + 0x28) & 0xf) != 0) {
            bVar2 = true;
            uVar4 = AHCIDeviceReset(param_1,bVar6,0);
            if ((char)uVar4 != '\0') goto LAB_00011c84;
            param_4 = (ulonglong)bVar6;
            StorPortDebugPrint(0,"[FUNCTION] %s :SoftReset Failed at port %d\n");
          }
          *(undefined1 *)(lVar7 + 0x1fa + param_1) = 0x5a;
          pbVar1 = (byte *)(*(longlong *)(lVar7 + 0x58 + param_1) + 0x2c);
          *pbVar1 = *pbVar1 & 0xf0;
        }
        else {
LAB_00011c84:
          pbVar1 = (byte *)(lVar7 + 0xd58 + param_1);
          *pbVar1 = *pbVar1 | 0x40;
          uVar3 = AHCIDetectDevice(param_1,bVar6,0,param_4);
          if ((char)uVar3 == '\0') {
            *(undefined1 *)(lVar7 + 0x1fa + param_1) = 0x5a;
            bVar2 = true;
            pbVar1 = (byte *)(*(longlong *)(lVar7 + 0x58 + param_1) + 0x18);
            *pbVar1 = *pbVar1 & 0xfe;
          }
        }
        bVar6 = bVar6 + 1;
      } while (bVar6 < *(byte *)(param_1 + 0x767e));
    }
    bVar5 = bVar5 + 1;
    if ((3 < bVar5) || (!bVar2)) {
      return;
    }
    if (bVar5 == 3) {
      AHCIHBAReset(param_1);
      pbVar1 = (byte *)(*(longlong *)(param_1 + 0x18) + 3);
      *pbVar1 = *pbVar1 | 0x80;
      StorPortDebugPrint(0,"[FUNCTION] %s : HBA reset again.\n");
    }
  } while( true );
}



===== AHCIDeviceReset @ 00011d28 =====

ulonglong AHCIDeviceReset(longlong param_1,byte param_2,byte param_3)

{
  byte *pbVar1;
  uint uVar2;
  bool bVar3;
  ulonglong uVar4;
  longlong lVar5;
  uint uVar6;
  longlong lVar7;
  longlong lVar8;
  longlong lVar9;
  undefined8 in_stack_ffffffffffffffb8;
  undefined4 uVar10;
  
  uVar2 = (uint)param_3;
  uVar6 = 0;
  lVar5 = (longlong)(char)param_2 * 0xe28;
  pbVar1 = (byte *)(*(longlong *)(lVar5 + 0x58 + param_1) + 0x18);
  *pbVar1 = *pbVar1 & 0xfe;
  bVar3 = false;
  if ((*(byte *)(*(longlong *)(lVar5 + 0x58 + param_1) + 0x19) & 0x80) != 0) {
    lVar9 = 1000;
LAB_00011d85:
    if (uVar6 < 1000) goto code_r0x00011d8a;
    in_stack_ffffffffffffffb8 = CONCAT44((int)((ulonglong)in_stack_ffffffffffffffb8 >> 0x20),uVar2);
    StorPortDebugPrint(0,
                       "[FUNCTION] %s :Time out,Waiting the PxCmd.CR to be clear for 500 miliseconds.at port %d subport %d\n"
                       ,0x1ffc0,(int)(char)param_2,in_stack_ffffffffffffffb8);
    lVar8 = *(longlong *)(lVar5 + 0x58 + param_1);
    lVar7 = 0x14;
    *(byte *)(lVar8 + 0x2c) = *(byte *)(lVar8 + 0x2c) & 0xf1 | 1;
    do {
      StorPortStallExecution(500);
      lVar7 = lVar7 + -1;
    } while (lVar7 != 0);
    lVar8 = 0x14;
    pbVar1 = (byte *)(*(longlong *)(lVar5 + 0x58 + param_1) + 0x2c);
    *pbVar1 = *pbVar1 & 0xf0;
    do {
      StorPortStallExecution(500);
      lVar8 = lVar8 + -1;
    } while (lVar8 != 0);
    do {
      StorPortStallExecution(500);
      lVar9 = lVar9 + -1;
    } while (lVar9 != 0);
    bVar3 = true;
  }
LAB_00011e1a:
  uVar6 = 0;
  *(undefined4 *)(*(longlong *)(lVar5 + 0x58 + param_1) + 0x30) = 0xffffffff;
  while( true ) {
    uVar10 = (undefined4)((ulonglong)in_stack_ffffffffffffffb8 >> 0x20);
    *(undefined4 *)(*(longlong *)(lVar5 + 0x58 + param_1) + 0x10) = 0xffffffff;
    **(undefined4 **)(param_1 + 0x20) = *(undefined4 *)(lVar5 + 0xe7c + param_1);
    lVar9 = *(longlong *)(lVar5 + 0x58 + param_1);
    if ((((*(byte *)(lVar9 + 0x20) & 0x80) == 0) && ((*(byte *)(lVar9 + 0x20) & 8) == 0)) ||
       (!bVar3)) goto LAB_00011ebc;
    if (19999 < uVar6) break;
    uVar6 = uVar6 + 1;
    StorPortStallExecution(500);
    in_stack_ffffffffffffffb8 = CONCAT44(uVar10,uVar2);
    StorPortDebugPrint(0,"[FUNCTION] %s :port %d subport %d.\n",0x1ffc0,(int)(char)param_2,
                       in_stack_ffffffffffffffb8);
    *(undefined4 *)(*(longlong *)(lVar5 + 0x58 + param_1) + 0x30) = 0xffffffff;
  }
  StorPortDebugPrint(0,
                     "[FUNCTION] %s :Time out,Waiting the BSY to be clear for 10 seconds at port %d subport %d.\n"
                     ,0x1ffc0,(int)(char)param_2,uVar2);
LAB_00011ebc:
  *(undefined1 *)(lVar5 + 0xd5a + param_1) = 0;
  pbVar1 = (byte *)(*(longlong *)(lVar5 + 0x58 + param_1) + 0x18);
  *pbVar1 = *pbVar1 | 8;
  pbVar1 = (byte *)(*(longlong *)(lVar5 + 0x58 + param_1) + 0x18);
  *pbVar1 = *pbVar1 | 1;
  *(undefined4 *)(*(longlong *)(lVar5 + 0x58 + param_1) + 0x30) = 0xffffffff;
  *(undefined4 *)(*(longlong *)(lVar5 + 0x58 + param_1) + 0x10) = 0xffffffff;
  **(undefined4 **)(param_1 + 0x20) = *(undefined4 *)(lVar5 + 0xe7c + param_1);
  *(byte *)(param_1 + 0x7695) = *(byte *)(param_1 + 0x7695) & 8;
  *(byte *)(param_1 + 0x76b5) = *(byte *)(param_1 + 0x76b5) & 0x60;
  *(undefined1 *)(param_1 + 0x76b4) = 0x27;
  *(undefined1 *)(param_1 + 0x76c3) = 4;
  *(byte *)(param_1 + 0x76b5) = *(byte *)(param_1 + 0x76b5) | param_3 & 0x1f;
  *(undefined1 *)(param_1 + 0x76b6) = 0;
  *(undefined2 *)(param_1 + 0x7696) = 0;
  *(undefined1 *)(param_1 + 0x7694) = 5;
  *(undefined4 *)(param_1 + 0x7698) = 0;
  *(byte *)(param_1 + 0x7695) = param_3 << 4 | *(byte *)(param_1 + 0x7695) & 0xfd | 5;
  uVar4 = AHCIGetFreeCommandSlot(param_1,param_2,param_3,'\0');
  AHCIFillCommand(param_1,param_2,param_3,(void *)0x0,0,(byte)uVar4,'\0');
  lVar9 = 100;
  do {
    StorPortStallExecution(500);
    lVar9 = lVar9 + -1;
  } while (lVar9 != 0);
  *(byte *)(param_1 + 0x7695) = *(byte *)(param_1 + 0x7695) & 0xfa;
  *(undefined1 *)(param_1 + 0x76c3) = 0;
  *(undefined4 *)(param_1 + 0x7698) = 0;
  uVar4 = AHCIGetFreeCommandSlot(param_1,param_2,param_3,'\0');
  uVar10 = 0;
  AHCIFillCommand(param_1,param_2,param_3,(void *)0x0,0,(byte)uVar4,'\0');
  uVar4 = AHCIWaitForCommandComplete(param_1,param_2,param_3,'\x01',0x1e);
  if ((char)uVar4 == '\0') {
    uVar4 = StorPortDebugPrint(0,0x1ff00,0x1ffc0,(int)(char)param_2,CONCAT44(uVar10,uVar2));
    uVar4 = uVar4 & 0xffffffffffffff00;
  }
  else {
    lVar9 = *(longlong *)(lVar5 + 0x58 + param_1);
    if ((*(char *)(lVar9 + 0x26) == 'i') && (*(char *)(lVar9 + 0x27) == -0x6a)) {
      pbVar1 = (byte *)(lVar5 + 0xd58 + param_1);
      *pbVar1 = *pbVar1 | 0x20;
    }
    else if ((*(char *)(lVar9 + 0x26) == '\x14') && (*(char *)(lVar9 + 0x27) == -0x15)) {
      *(undefined1 *)(lVar5 + 0x1fa + param_1) = 0x11;
    }
    else {
      *(undefined1 *)(lVar5 + 0x1fa + param_1) = 1;
    }
    uVar4 = CONCAT71((int7)((ulonglong)lVar9 >> 8),1);
  }
  return uVar4;
code_r0x00011d8a:
  uVar6 = uVar6 + 1;
  StorPortStallExecution();
  bVar3 = false;
  if ((*(byte *)(*(longlong *)(lVar5 + 0x58 + param_1) + 0x19) & 0x80) == 0) goto LAB_00011e1a;
  goto LAB_00011d85;
}



===== AHCIPortReset @ 00012078 =====

ulonglong AHCIPortReset(longlong param_1,byte param_2)

{
  byte *pbVar1;
  ulonglong uVar2;
  byte bVar3;
  longlong lVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  longlong lVar8;
  longlong lVar9;
  uint uVar10;
  ulonglong uVar11;
  
  uVar11 = (ulonglong)param_2;
  lVar4 = uVar11 * 0xe28;
  uVar2 = *(ulonglong *)(lVar4 + 0x58 + param_1);
  if ((*(byte *)(uVar2 + 0x28) & 0xf) == 0) goto LAB_00012419;
  *(byte *)(uVar2 + 0x18) = *(byte *)(uVar2 + 0x18) & 0xfe;
  uVar10 = 0;
  iVar5 = 0;
  while( true ) {
    lVar9 = *(longlong *)(lVar4 + 0x58 + param_1);
    if (((*(byte *)(lVar9 + 0x19) & 0x80) == 0) && (*(int *)(lVar9 + 0x38) == 0)) goto LAB_0001212b;
    if (iVar5 == 2000) break;
    iVar5 = iVar5 + 1;
    StorPortStallExecution();
  }
  StorPortDebugPrint(0,
                     "[FUNCTION] %s :Time out,Waiting the PxCmd.CR to be clear for 500 miliseconds at port %d"
                     ,"AHCIPortReset",uVar11);
  lVar9 = *(longlong *)(lVar4 + 0x58 + param_1);
  StorPortDebugPrint(0,",PxIS %lx PxCMD %lx pxSERR %lx PxCI %lx\n",*(undefined4 *)(lVar9 + 0x10),
                     *(undefined4 *)(lVar9 + 0x18),*(undefined4 *)(lVar9 + 0x30),
                     *(undefined4 *)(lVar9 + 0x38));
LAB_0001212b:
  lVar9 = *(longlong *)(lVar4 + 0x58 + param_1);
  *(undefined1 *)(lVar4 + 0xd5a + param_1) = 0;
  lVar8 = 10;
  *(byte *)(lVar9 + 0x2c) = *(byte *)(lVar9 + 0x2c) & 0xf1 | 1;
  do {
    StorPortStallExecution(500);
    lVar8 = lVar8 + -1;
  } while (lVar8 != 0);
  uVar6 = 0;
  pbVar1 = (byte *)(*(longlong *)(lVar4 + 0x58 + param_1) + 0x2c);
  *pbVar1 = *pbVar1 & 0xf0;
  do {
    StorPortStallExecution(500);
    lVar9 = *(longlong *)(lVar4 + 0x58 + param_1);
    if ((*(byte *)(lVar9 + 0x28) & 0xf) == 3) break;
    uVar6 = uVar6 + 1;
  } while (uVar6 < 1000);
  *(undefined4 *)(lVar9 + 0x30) = 0xffffffff;
  *(undefined4 *)(*(longlong *)(lVar4 + 0x58 + param_1) + 0x10) = 0xffffffff;
  lVar9 = *(longlong *)(lVar4 + 0x58 + param_1);
  if ((*(int *)(lVar9 + 0x38) != 0) || (*(int *)(lVar9 + 0x34) != 0)) {
    *(byte *)(lVar9 + 0x18) = *(byte *)(lVar9 + 0x18) | 1;
    lVar9 = 10;
    do {
      StorPortStallExecution(500);
      lVar9 = lVar9 + -1;
    } while (lVar9 != 0);
    lVar8 = 10;
    pbVar1 = (byte *)(*(longlong *)(lVar4 + 0x58 + param_1) + 0x18);
    *pbVar1 = *pbVar1 & 0xfe;
    lVar9 = *(longlong *)(lVar4 + 0x58 + param_1);
    *(undefined1 *)(lVar4 + 0xd5a + param_1) = 0;
    *(byte *)(lVar9 + 0x2c) = *(byte *)(lVar9 + 0x2c) & 0xf1 | 1;
    do {
      StorPortStallExecution(500);
      lVar8 = lVar8 + -1;
    } while (lVar8 != 0);
    uVar6 = 0;
    pbVar1 = (byte *)(*(longlong *)(lVar4 + 0x58 + param_1) + 0x2c);
    *pbVar1 = *pbVar1 & 0xf0;
    do {
      StorPortStallExecution(500);
      if ((*(byte *)(*(longlong *)(lVar4 + 0x58 + param_1) + 0x28) & 0xf) == 3) break;
      uVar6 = uVar6 + 1;
    } while (uVar6 < 1000);
  }
  uVar6 = 0;
  *(undefined4 *)(*(longlong *)(lVar4 + 0x58 + param_1) + 0x30) = 0xffffffff;
  *(undefined4 *)(*(longlong *)(lVar4 + 0x58 + param_1) + 0x10) = 0xffffffff;
  while( true ) {
    lVar9 = *(longlong *)(lVar4 + 0x58 + param_1);
    bVar3 = *(byte *)(lVar9 + 0x28) & 0xf;
    if ((bVar3 == 3) &&
       ((*(int *)(lVar9 + 0x30) == 0 || ((*(uint *)(lVar9 + 0x30) & 0xfffdfdff) == 0)))) {
      *(undefined4 *)(lVar9 + 0x30) = 0xffffffff;
      *(undefined4 *)(*(longlong *)(lVar4 + 0x58 + param_1) + 0x10) = 0xffffffff;
      lVar9 = *(longlong *)(lVar4 + 0x58 + param_1);
      if ((*(byte *)(lVar9 + 0x28) & 0xf) != 3) goto LAB_000123c1;
      goto LAB_00012319;
    }
    if (4 < uVar6) break;
    uVar6 = uVar6 + 1;
    if (bVar3 != 3) {
      *(byte *)(lVar9 + 0x2c) = *(byte *)(lVar9 + 0x2c) & 0xf1;
      *(byte *)(lVar9 + 0x2c) = *(byte *)(lVar9 + 0x2c) | 1;
      lVar9 = 10;
      do {
        StorPortStallExecution(500);
        lVar9 = lVar9 + -1;
      } while (lVar9 != 0);
      uVar7 = 0;
      pbVar1 = (byte *)(*(longlong *)(lVar4 + 0x58 + param_1) + 0x2c);
      *pbVar1 = *pbVar1 & 0xf0;
      do {
        StorPortStallExecution(500);
        if ((*(byte *)(*(longlong *)(lVar4 + 0x58 + param_1) + 0x28) & 0xf) == 3) break;
        uVar7 = uVar7 + 1;
      } while (uVar7 < 10000);
    }
    *(undefined4 *)(*(longlong *)(lVar4 + 0x58 + param_1) + 0x30) = 0xffffffff;
    *(undefined4 *)(*(longlong *)(lVar4 + 0x58 + param_1) + 0x10) = 0xffffffff;
    lVar9 = *(longlong *)(lVar4 + 0x58 + param_1);
    StorPortDebugPrint(0,
                       "[FUNCTION] %s :Link can\'t be established....PxSSTS.DET %x,PxSERR %lx at port %d\n"
                       ,"AHCIPortReset",*(byte *)(lVar9 + 0x28) & 0xf,*(undefined4 *)(lVar9 + 0x30),
                       param_2);
  }
  StorPortDebugPrint(0,
                     "[FUNCTION] %s :Link can\'t be established....PxSSTS.DET %x,PxSERR %lx at port %d\n"
                     ,"AHCIPortReset",*(byte *)(lVar9 + 0x28) & 0xf,*(undefined4 *)(lVar9 + 0x30),
                     param_2);
  goto LAB_00012407;
LAB_00012319:
  lVar8 = *(longlong *)(lVar4 + 0x58 + param_1);
  bVar3 = *(byte *)(lVar8 + 0x20);
  lVar9 = CONCAT71((int7)((ulonglong)lVar9 >> 8),bVar3);
  if (((-1 < (char)bVar3) && ((bVar3 & 8) == 0)) && ((bVar3 & 1) == 0)) goto LAB_000123c1;
  if ((*(byte *)(lVar8 + 0x28) & 0xf) == 0) {
    lVar9 = StorPortDebugPrint(0,"[FUNCTION] %s :Port %d has been plug out\n","AHCIPortReset",uVar11
                              );
LAB_000123c1:
    *(undefined4 *)(*(longlong *)(lVar4 + 0x58 + param_1) + 0x30) = 0xffffffff;
    *(undefined4 *)(*(longlong *)(lVar4 + 0x58 + param_1) + 0x10) = 0xffffffff;
    return CONCAT71((int7)((ulonglong)lVar9 >> 8),1);
  }
  StorPortStallExecution(500);
  lVar9 = *(longlong *)(lVar4 + 0x58 + param_1);
  uVar10 = uVar10 + 1;
  if (17999 < uVar10) goto LAB_0001235f;
  *(undefined4 *)(lVar9 + 0x30) = 0xffffffff;
  lVar9 = *(longlong *)(lVar4 + 0x58 + param_1);
  *(undefined4 *)(lVar9 + 0x10) = 0xffffffff;
  goto LAB_00012319;
LAB_0001235f:
  bVar3 = *(byte *)(lVar9 + 0x20);
  StorPortDebugPrint(0,
                     "[FUNCTION] %s: Device is not ready:BSY %x DRQ %x ERR %x Error %x at port %d\n"
                     ,"AHCIPortReset",bVar3 >> 7,bVar3 >> 3 & 1,bVar3 & 1,
                     *(undefined1 *)(lVar9 + 0x21),param_2);
LAB_00012407:
  *(undefined4 *)(*(longlong *)(lVar4 + 0x58 + param_1) + 0x30) = 0xffffffff;
  uVar2 = *(ulonglong *)(lVar4 + 0x58 + param_1);
  *(undefined4 *)(uVar2 + 0x10) = 0xffffffff;
LAB_00012419:
  return uVar2 & 0xffffffffffffff00;
}



===== AHCIHBAReset @ 00012440 =====

undefined8 AHCIHBAReset(longlong param_1)

{
  byte bVar1;
  byte *pbVar2;
  ulonglong uVar3;
  uint uVar4;
  
  uVar4 = 0;
  **(byte **)(param_1 + 0x18) = **(byte **)(param_1 + 0x18) | 1;
  pbVar2 = *(byte **)(param_1 + 0x18);
  bVar1 = *pbVar2;
  while( true ) {
    if ((bVar1 & 1) == 0) {
      return CONCAT71((int7)((ulonglong)pbVar2 >> 8),1);
    }
    StorPortDebugPrint(0,"[FUNCTION] %s :HBA.Reset %lx \n","AHCIHBAReset",
                       **(undefined4 **)(param_1 + 0x10));
    if (1999 < uVar4) break;
    uVar4 = uVar4 + 1;
    pbVar2 = (byte *)StorPortStallExecution();
    bVar1 = **(byte **)(param_1 + 0x18);
  }
  uVar3 = StorPortDebugPrint(0,
                             "[FUNCTION] %s :The HBA maybe hung,We has waited 1 second for HBA reset completing.\n"
                             ,"AHCIHBAReset");
  return uVar3 & 0xffffffffffffff00;
}



===== AHCIPMReadWrite @ 000124c8 =====

void AHCIPMReadWrite(longlong param_1,byte param_2,byte param_3,undefined8 param_4,char param_5,
                    undefined1 param_6,uint *param_7)

{
  longlong lVar1;
  uint uVar2;
  byte bVar3;
  ulonglong uVar4;
  
  *(undefined1 *)(param_1 + 0x76b4) = 0x27;
  *(byte *)(param_1 + 0x7694) = *(byte *)(param_1 + 0x7694) & 0x7f;
  *(char *)(param_1 + 0x76b6) = param_5;
  *(byte *)(param_1 + 0x76b5) = *(byte *)(param_1 + 0x76b5) & 0xef | 0x8f;
  *(byte *)(param_1 + 0x76bb) = param_3;
  *(undefined1 *)(param_1 + 0x76b7) = param_6;
  uVar2 = *param_7;
  *param_7 = *param_7 >> 8;
  *(char *)(param_1 + 0x76c0) = (char)uVar2;
  uVar2 = *param_7;
  *(char *)(param_1 + 0x76b8) = (char)uVar2;
  *(char *)(param_1 + 0x76b9) = (char)(uVar2 >> 8);
  *(byte *)(param_1 + 0x7695) = *(byte *)(param_1 + 0x7695) & 0xf8 | 0xf0;
  bVar3 = *(byte *)(param_1 + 0x7694);
  *param_7 = uVar2 >> 0x10;
  *(char *)(param_1 + 0x76ba) = (char)(uVar2 >> 0x10);
  *(undefined2 *)(param_1 + 0x7696) = 0;
  if (param_5 == -0x1c) {
    bVar3 = bVar3 & 0xbf;
  }
  else {
    bVar3 = bVar3 | 0x40;
  }
  *(byte *)(param_1 + 0x7694) = bVar3;
  *(byte *)(param_1 + 0x7694) = *(byte *)(param_1 + 0x7694) & 0xc5;
  *(byte *)(param_1 + 0x7694) = *(byte *)(param_1 + 0x7694) | 5;
  *(undefined4 *)(param_1 + 0x7698) = 0;
  uVar4 = AHCIGetFreeCommandSlot(param_1,param_2,param_3,'\0');
  AHCIFillCommand(param_1,param_2,param_3,(void *)0x0,0,(byte)uVar4,'\0');
  AHCIWaitForCommandComplete(param_1,param_2,param_3,'\0',0x1e);
  lVar1 = *(longlong *)(param_1 + 0x38f8 + (ulonglong)param_2 * 8);
  *param_7 = (uint)*(byte *)(lVar1 + 0x4c) ^ *(int *)(lVar1 + 0x44) << 8;
  return;
}



===== AHCIPMHardReset @ 0001262c =====

ulonglong AHCIPMHardReset(longlong param_1,byte param_2,byte param_3,undefined8 param_4)

{
  byte bVar1;
  longlong lVar2;
  ulonglong uVar3;
  longlong lVar4;
  undefined8 uVar5;
  uint local_res20 [2];
  
  local_res20[0] = 1;
  uVar5 = CONCAT71((int7)((ulonglong)param_4 >> 8),0xf);
  uVar3 = AHCIPMReadWrite(param_1,param_2,param_3,uVar5,-0x18,2,local_res20);
  if ((char)uVar3 != '\0') {
    uVar5 = CONCAT71((int7)((ulonglong)uVar5 >> 8),0xf);
    local_res20[0] = 0;
    uVar3 = AHCIPMReadWrite(param_1,param_2,param_3,uVar5,-0x18,2,local_res20);
    if ((char)uVar3 != '\0') {
      uVar5 = CONCAT71((int7)((ulonglong)uVar5 >> 8),0xf);
      local_res20[0] = 0;
      uVar3 = AHCIPMReadWrite(param_1,param_2,param_3,uVar5,-0x1c,1,local_res20);
      if ((char)uVar3 != '\0') {
        local_res20[0] = 0xffffffff;
        uVar5 = CONCAT71((int7)((ulonglong)uVar5 >> 8),0xf);
        uVar3 = AHCIPMReadWrite(param_1,param_2,param_3,uVar5,-0x18,1,local_res20);
        if ((char)uVar3 != '\0') {
          local_res20[0] = 0;
          uVar3 = AHCIPMReadWrite(param_1,param_2,param_3,
                                  CONCAT71((int7)((ulonglong)uVar5 >> 8),0xf),-0x1c,0,local_res20);
          if ((char)uVar3 != '\0') {
            lVar4 = (ulonglong)param_2 * 0xe28;
            if ((local_res20[0] & 3) == 0) {
              uVar3 = StorPortDebugPrint(0,
                                         "[FUNCTION] %s :The link is not established between Port %x and its subport %x the SSTS is %x\n"
                                         ,"AHCIPMHardReset",param_2,param_3,
                                         *(undefined1 *)
                                          (*(longlong *)(param_1 + 0x58 + lVar4) + 0x24));
              if ((local_res20[0] & 1) != 0) {
                uVar3 = (ulonglong)param_3 + lVar4;
                *(undefined1 *)(uVar3 + 0x1fa + param_1) = 0x5a;
              }
            }
            else {
              lVar2 = *(longlong *)(param_1 + 0x58 + lVar4);
              if ((((*(byte *)(lVar2 + 0x20) & 0x80) == 0) && ((*(byte *)(lVar2 + 0x20) & 8) == 0))
                 && ((*(byte *)(lVar2 + 0x20) & 1) == 0)) {
                return CONCAT71((int7)(uVar3 >> 8),1);
              }
              bVar1 = *(byte *)(lVar2 + 0x20);
              uVar3 = StorPortDebugPrint(0,
                                         "[FUNCTION] %s :TimeOut, BSY %x DRQ %x ERR %x Error %x at port %d\n"
                                         ,"AHCIPMHardReset",bVar1 >> 7,bVar1 >> 3 & 1,bVar1 & 1,
                                         *(undefined1 *)(lVar2 + 0x21),param_2);
              *(undefined1 *)((ulonglong)param_3 + lVar4 + 0x1fa + param_1) = 0x5a;
            }
          }
        }
      }
    }
  }
  return uVar3 & 0xffffffffffffff00;
}



===== AHCIIssueIdentify @ 0001282c =====

ulonglong AHCIIssueIdentify(longlong param_1,byte param_2,byte param_3)

{
  longlong lVar1;
  undefined1 *puVar2;
  byte *pbVar3;
  ushort uVar4;
  uint uVar5;
  uint6 uVar6;
  undefined1 uVar7;
  ulonglong uVar8;
  byte *pbVar9;
  byte bVar10;
  short sVar11;
  longlong lVar12;
  longlong lVar13;
  byte bVar14;
  undefined1 *puVar15;
  longlong lVar16;
  longlong lVar17;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  
  *(undefined1 *)(param_1 + 0x76b4) = 0x27;
  lVar13 = (ulonglong)param_2 * 0xe28;
  lVar1 = (ulonglong)param_3 + lVar13;
  *(byte *)(param_1 + 0x76b5) = *(byte *)(param_1 + 0x76b5) & 0xe0 | param_3 & 0x1f | 0x80;
  uVar7 = 0xa1;
  if (*(char *)(lVar1 + 0x1fa + param_1) == '\x01') {
    uVar7 = 0xec;
  }
  *(undefined1 *)(param_1 + 0x76b6) = uVar7;
  *(undefined2 *)(param_1 + 0x7696) = 1;
  local_34 = *(undefined4 *)(param_1 + 0x7528);
  *(undefined1 *)(param_1 + 0x7694) = 5;
  local_38 = 0;
  *(byte *)(param_1 + 0x7695) = *(byte *)(param_1 + 0x7695) & 8 | param_3 << 4;
  local_30 = 0x200;
  *(undefined4 *)(param_1 + 0x7698) = 0;
  uVar8 = AHCIGetFreeCommandSlot(param_1,param_2,param_3,'\0');
  AHCIFillCommand(param_1,param_2,param_3,(void *)0x0,(longlong)&local_38,(byte)uVar8,'\0');
  uVar8 = AHCIWaitForCommandComplete(param_1,param_2,param_3,'\0',300);
  if ((char)uVar8 == '\0') {
LAB_00012e00:
    uVar8 = uVar8 & 0xffffffffffffff00;
  }
  else {
    lVar12 = 0x36;
    lVar17 = 0x14;
    lVar16 = (ulonglong)param_3 * 0xc0 + lVar13;
    puVar15 = (undefined1 *)(lVar16 + 0x219 + param_1);
    do {
      puVar15[-1] = *(undefined1 *)(lVar12 + 1 + *(longlong *)(param_1 + 0x7520));
      puVar2 = (undefined1 *)(lVar12 + *(longlong *)(param_1 + 0x7520));
      lVar12 = lVar12 + 2;
      *puVar15 = *puVar2;
      puVar15 = puVar15 + 2;
      lVar17 = lVar17 + -1;
    } while (lVar17 != 0);
    sVar11 = *(short *)(*(longlong *)(param_1 + 0x7520) + 0xb0) * 0x100;
    *(short *)(lVar16 + 0x2d0 + param_1) = sVar11;
    sVar11 = (*(ushort *)(*(longlong *)(param_1 + 0x7520) + 0x7e) & 0xf) * 0x10 + sVar11;
    *(short *)(lVar16 + 0x2d0 + param_1) = sVar11;
    *(ushort *)(lVar16 + 0x2d0 + param_1) =
         (*(ushort *)(*(longlong *)(param_1 + 0x7520) + 0x80) & 0xf) + sVar11;
    bVar14 = (*(byte *)(*(longlong *)(param_1 + 0x7520) + 0x96) & 0x1f) + 1;
    *(byte *)(lVar16 + 0x2d2 + param_1) = bVar14;
    pbVar9 = (byte *)(lVar16 + 0x2c1 + param_1);
    *pbVar9 = *pbVar9 ^ (*(char *)(*(longlong *)(param_1 + 0x7520) + 99) << 5 ^
                        *(byte *)(lVar16 + 0x2c1 + param_1)) & 0x20;
    bVar10 = *(byte *)(lVar16 + 0x2c1 + param_1);
    *(byte *)(lVar16 + 0x2c1 + param_1) =
         ((byte)((ushort)*(undefined2 *)(*(longlong *)(param_1 + 0x7520) + 0x62) >> 9) << 4 ^ bVar10
         ) & 0x10 ^ bVar10;
    if (*(byte *)(param_1 + 0x767d) < bVar14) {
      *(byte *)(lVar16 + 0x2d2 + param_1) = *(byte *)(param_1 + 0x767d);
    }
    pbVar9 = (byte *)(lVar16 + 0x2c1 + param_1);
    *pbVar9 = *pbVar9 & 0xbf;
    pbVar9 = (byte *)(lVar16 + 0x2c2 + param_1);
    *pbVar9 = *pbVar9 & 7;
    pbVar9 = (byte *)(lVar16 + 0x2c3 + param_1);
    *pbVar9 = *pbVar9 & 0xf0;
    pbVar9 = (byte *)(lVar16 + 0x2c1 + param_1);
    *pbVar9 = *pbVar9 & 0x7f;
    bVar10 = *(byte *)(lVar16 + 0x2c2 + param_1);
    *(char *)(lVar16 + 0x2d3 + param_1) =
         (char)((int)((uint)*(byte *)(lVar16 + 0x2d2 + param_1) * 3) >> 2);
    uVar4 = *(ushort *)(*(longlong *)(param_1 + 0x7520) + 0x98);
    if ((uVar4 != 0) && (uVar4 != 0xffffffff)) {
      bVar10 = ((char)(uVar4 >> 1) << 6 ^ bVar10) & 0x40 ^ bVar10;
      *(byte *)(lVar16 + 0x2c2 + param_1) = bVar10;
      bVar10 = (char)(*(ushort *)(*(longlong *)(param_1 + 0x7520) + 0x98) >> 2) << 7 | bVar10 & 0x7f
      ;
      *(byte *)(lVar16 + 0x2c2 + param_1) = bVar10;
      pbVar9 = (byte *)(lVar16 + 0x2c1 + param_1);
      *pbVar9 = *pbVar9 ^ (*(char *)(*(longlong *)(param_1 + 0x7520) + 0x99) << 6 ^
                          *(byte *)(lVar16 + 0x2c1 + param_1)) & 0x40;
      pbVar9 = (byte *)(lVar16 + 0x2c2 + param_1);
      *pbVar9 = *pbVar9 ^ ((byte)((ushort)*(undefined2 *)(*(longlong *)(param_1 + 0x7520) + 0x98) >>
                                 9) << 4 ^ bVar10) & 0x10;
      bVar10 = *(byte *)(param_1 + 0xd58 + lVar13);
      if (((bVar10 & 0x20) == 0) && (*(char *)(param_1 + 0x768b) != '\0')) {
        *(byte *)(param_1 + 0xd58 + lVar13) =
             (*(byte *)(lVar16 + 0x2c2 + param_1) >> 2 ^ bVar10) & 4 ^ bVar10;
      }
      pbVar9 = (byte *)(lVar16 + 0x2c3 + param_1);
      *pbVar9 = *pbVar9 ^ ((byte)((ushort)*(undefined2 *)(*(longlong *)(param_1 + 0x7520) + 0x98) >>
                                 10) ^ *(byte *)(lVar16 + 0x2c3 + param_1)) & 1;
      pbVar9 = (byte *)(lVar16 + 0x2c2 + param_1);
      *pbVar9 = *pbVar9 ^ ((char)(*(ushort *)(*(longlong *)(param_1 + 0x7520) + 0x9c) >> 1) << 3 ^
                          *(byte *)(lVar16 + 0x2c2 + param_1)) & 8;
      *(byte *)(lVar16 + 0x2c1 + param_1) =
           (char)(*(ushort *)(*(longlong *)(param_1 + 0x7520) + 0x9c) >> 2) << 7 |
           *(byte *)(lVar16 + 0x2c1 + param_1) & 0x7f;
      pbVar9 = (byte *)(lVar16 + 0x2c2 + param_1);
      *pbVar9 = *pbVar9 ^ ((char)(*(ushort *)(*(longlong *)(param_1 + 0x7520) + 0x98) >> 3) << 5 ^
                          *(byte *)(lVar16 + 0x2c2 + param_1)) & 0x20;
      pbVar9 = (byte *)(lVar16 + 0x2c3 + param_1);
      *pbVar9 = *pbVar9 ^ ((char)(*(ushort *)(*(longlong *)(param_1 + 0x7520) + 0x9c) >> 4) << 3 ^
                          *(byte *)(lVar16 + 0x2c3 + param_1)) & 8;
      bVar10 = *(byte *)(lVar16 + 0x2c3 + param_1);
      bVar10 = ((char)(*(ushort *)(*(longlong *)(param_1 + 0x7520) + 0x9c) >> 5) << 2 ^ bVar10) & 4
               ^ bVar10;
      *(byte *)(lVar16 + 0x2c3 + param_1) = bVar10;
      *(byte *)(lVar16 + 0x2c3 + param_1) =
           ((char)(*(ushort *)(*(longlong *)(param_1 + 0x7520) + 0x9c) >> 6) * '\x02' ^ bVar10) & 2
           ^ bVar10;
    }
    bVar10 = *(byte *)(lVar16 + 0x2c1 + param_1);
    if (((bVar10 & 0x40) != 0) && (*(char *)(lVar16 + 0x2d3 + param_1) == '\0')) {
      *(byte *)(lVar16 + 0x2c1 + param_1) = bVar10 & 0xbf;
    }
    pbVar9 = *(byte **)(param_1 + 0x7520);
    if (*(char *)(lVar1 + 0x1fa + param_1) == '\x11') {
      pbVar3 = (byte *)(lVar16 + 0x2c1 + param_1);
      *pbVar3 = *pbVar3 ^ (*pbVar9 << 2 ^ *(byte *)(lVar16 + 0x2c1 + param_1)) & 0xc;
    }
    else {
      pbVar3 = (byte *)(lVar16 + 0x2c1 + param_1);
      *pbVar3 = *pbVar3 ^ (*pbVar9 >> 7 ^ *(byte *)(lVar16 + 0x2c1 + param_1)) & 1;
      *(undefined1 *)(lVar16 + 0x2c0 + param_1) =
           *(undefined1 *)(*(longlong *)(param_1 + 0x7520) + 0x5e);
      lVar1 = *(longlong *)(param_1 + 0x7520);
      pbVar9 = (byte *)(lVar16 + 0x2c1 + param_1);
      *pbVar9 = *pbVar9 ^ ((byte)((ushort)*(undefined2 *)(lVar1 + 0xa6) >> 10) * '\x02' ^
                          *(byte *)(lVar16 + 0x2c1 + param_1)) & 2;
      bVar10 = *(byte *)(lVar16 + 0x2c1 + param_1);
      pbVar9 = (byte *)CONCAT71((int7)((ulonglong)lVar1 >> 8),bVar10);
      if ((bVar10 & 0x10) == 0) {
        uVar8 = StorPortDebugPrint(0,
                                   "[FUNCTION] %s :The Hard drive can\'t support LBA, we do not support this old device!!!\n"
                                   ,"AHCIIssueIdentify");
        goto LAB_00012e00;
      }
      if ((bVar10 & 2) == 0) {
        *(undefined8 *)(lVar16 + 0x2c8 + param_1) = 0;
        uVar4 = *(ushort *)(*(longlong *)(param_1 + 0x7520) + 0x7a);
        *(ulonglong *)(lVar16 + 0x2c8 + param_1) = (ulonglong)uVar4 * 0x10000;
        *(ulonglong *)(lVar16 + 0x2c8 + param_1) =
             (ulonglong)CONCAT22(uVar4,*(undefined2 *)(*(longlong *)(param_1 + 0x7520) + 0x78));
      }
      else {
        uVar4 = *(ushort *)(*(longlong *)(param_1 + 0x7520) + 0xce);
        *(ulonglong *)(lVar16 + 0x2c8 + param_1) = (ulonglong)uVar4 * 0x10000;
        uVar5 = CONCAT22(uVar4,*(undefined2 *)(*(longlong *)(param_1 + 0x7520) + 0xcc));
        *(ulonglong *)(lVar16 + 0x2c8 + param_1) = (ulonglong)uVar5 * 0x10000;
        uVar6 = CONCAT42(uVar5,*(undefined2 *)(*(longlong *)(param_1 + 0x7520) + 0xca));
        *(ulonglong *)(lVar16 + 0x2c8 + param_1) = (ulonglong)uVar6 * 0x10000;
        pbVar9 = *(byte **)(param_1 + 0x7520);
        *(ulonglong *)(lVar16 + 0x2c8 + param_1) = CONCAT62(uVar6,*(undefined2 *)(pbVar9 + 200));
      }
    }
    uVar8 = CONCAT71((int7)((ulonglong)pbVar9 >> 8),1);
  }
  return uVar8;
}



===== AHCISetFeatures @ 00012e34 =====

bool AHCISetFeatures(longlong param_1,byte param_2,byte param_3,undefined1 param_4,
                    undefined1 param_5,undefined1 param_6)

{
  ulonglong uVar1;
  
  *(undefined1 *)(param_1 + 0x76b6) = param_4;
  *(undefined1 *)(param_1 + 0x76b4) = 0x27;
  *(undefined1 *)(param_1 + 0x76bb) = 0xa0;
  *(undefined1 *)(param_1 + 0x76b8) = 0;
  *(undefined1 *)(param_1 + 0x76b9) = 0;
  *(undefined1 *)(param_1 + 0x76ba) = 0;
  *(undefined2 *)(param_1 + 0x7696) = 0;
  *(undefined1 *)(param_1 + 0x76b7) = param_5;
  *(undefined1 *)(param_1 + 0x76c0) = param_6;
  *(byte *)(param_1 + 0x76b5) = *(byte *)(param_1 + 0x76b5) & 0xe0 | param_3 & 0x1f | 0x80;
  *(undefined1 *)(param_1 + 0x7694) = 5;
  *(undefined4 *)(param_1 + 0x7698) = 0;
  *(byte *)(param_1 + 0x7695) = *(byte *)(param_1 + 0x7695) & 8 | param_3 << 4;
  uVar1 = AHCIGetFreeCommandSlot(param_1,param_2,param_3,'\0');
  AHCIFillCommand(param_1,param_2,param_3,(void *)0x0,0,(byte)uVar1,'\0');
  uVar1 = AHCIWaitForCommandComplete(param_1,param_2,param_3,'\0',0x96);
  return (char)uVar1 != '\0';
}



===== AHCISetDeviceParameter @ 00012f44 =====

ulonglong AHCISetDeviceParameter(longlong param_1,byte param_2,byte param_3)

{
  ushort uVar1;
  bool bVar2;
  ulonglong uVar3;
  undefined7 extraout_var;
  longlong lVar4;
  char *pcVar5;
  char cVar6;
  longlong lVar7;
  
  lVar7 = (ulonglong)param_3 * 0xc0 + (ulonglong)param_2 * 0xe28;
  uVar1 = *(ushort *)(lVar7 + 0x2d0 + param_1);
  if ((uVar1 & 2) == 0) {
    cVar6 = (-((uVar1 & 1) != 0) & 3U) + 8;
  }
  else {
    cVar6 = '\f';
  }
  bVar2 = AHCISetFeatures(param_1,param_2,param_3,0xef,3,cVar6);
  if (bVar2) {
    uVar1 = *(ushort *)(lVar7 + 0x2d0 + param_1);
    if ((uVar1 & 0xff00) == 0) {
      if ((uVar1 & 0x40) == 0) {
        if ((uVar1 & 0x20) == 0) {
          if ((uVar1 & 0x10) != 0) {
            cVar6 = ' ';
          }
        }
        else {
          cVar6 = '!';
        }
      }
      else {
        cVar6 = '\"';
      }
    }
    else if ((uVar1 & 0x4000) == 0) {
      if ((uVar1 & 0x2000) == 0) {
        if ((uVar1 & 0x1000) == 0) {
          if ((uVar1 & 0x800) == 0) {
            if ((uVar1 & 0x400) == 0) {
              if ((uVar1 & 0x200) == 0) {
                if ((uVar1 & 0x100) != 0) {
                  cVar6 = '@';
                }
              }
              else {
                cVar6 = 'A';
              }
            }
            else {
              cVar6 = 'B';
            }
          }
          else {
            cVar6 = 'C';
          }
        }
        else {
          cVar6 = 'D';
        }
      }
      else {
        cVar6 = 'E';
      }
    }
    else {
      cVar6 = 'F';
    }
    bVar2 = AHCISetFeatures(param_1,param_2,param_3,0xef,3,cVar6);
    if (bVar2) {
      if (*(char *)(param_1 + 0x768b) == '\0') {
        if (((*(byte *)(lVar7 + 0x2c2 + param_1) & 0x20) == 0) ||
           (bVar2 = AHCISetFeatures(param_1,param_2,param_3,0xef,0x90,3), bVar2)) goto LAB_00013138;
        pcVar5 = "[FUNCTION] %s :Failed to disable Device-initiated IPM at port %d subport %d\n";
      }
      else if (((*(byte *)(lVar7 + 0x2c2 + param_1) & 0x20) == 0) ||
              (bVar2 = AHCISetFeatures(param_1,param_2,param_3,0xef,0x10,3), bVar2)) {
LAB_00013138:
        if (((*(byte *)(lVar7 + 0x2c2 + param_1) & 8) == 0) ||
           (bVar2 = AHCISetFeatures(param_1,param_2,param_3,0xef,0x90,1), bVar2)) {
          if (((*(byte *)(lVar7 + 0x2c1 + param_1) & 0x80) == 0) ||
             (bVar2 = AHCISetFeatures(param_1,param_2,param_3,0xef,0x10,2), bVar2)) {
            lVar4 = (ulonglong)param_3 + (ulonglong)param_2 * 0xe28;
            if (*(char *)(lVar4 + 0x1fa + param_1) != '\x01') {
LAB_000131e4:
              return CONCAT71((int7)((ulonglong)lVar4 >> 8),1);
            }
            bVar2 = AHCISetFeatures(param_1,param_2,param_3,0xc6,0,
                                    *(undefined1 *)(lVar7 + 0x2c0 + param_1));
            lVar4 = CONCAT71(extraout_var,bVar2);
            if (bVar2) goto LAB_000131e4;
            pcVar5 = "[FUNCTION] %s :Failed to Set Read/Write Multiple at port %d subport %d\n";
          }
          else {
            pcVar5 = 
            "[FUNCTION] %s :Failed to enable DMA setup FIS Auto-Activate optimization at port %d subport %d\n"
            ;
          }
        }
        else {
          pcVar5 = 
          "[FUNCTION] %s :Failed to disable Non-Zero Buffer Offset int DMA setup FIS at port %d subport %d\n"
          ;
        }
      }
      else {
        pcVar5 = "[FUNCTION] %s :Failed to Enable Device-initiated IPM at port %d subport %d\n";
      }
      uVar3 = StorPortDebugPrint(0,pcVar5,"AHCISetDeviceParameter",param_2,param_3);
      goto LAB_00012fe4;
    }
    pcVar5 = "[FUNCTION] %s :Failed to set the UDMA Mode %x. at port %d subport %d\n";
  }
  else {
    pcVar5 = "[FUNCTION] %s :Failed to set the PIO Mode %x. at port %d subport %d\n";
  }
  uVar3 = StorPortDebugPrint(0,pcVar5,"AHCISetDeviceParameter",cVar6,param_2,param_3);
LAB_00012fe4:
  return uVar3 & 0xffffffffffffff00;
}



===== AHCIWaitingAdapterReady @ 0001320c =====

undefined8 AHCIWaitingAdapterReady(longlong param_1)

{
  undefined8 uVar1;
  byte bVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  
  uVar4 = (ulonglong)*(uint *)(param_1 + 0x7650);
  uVar3 = (ulonglong)*(uint *)(param_1 + 0x764c);
  uVar1 = 4;
  StorPortSetBusDataByOffset();
  AHCIInitialHBADevice(param_1,uVar1,uVar3,uVar4);
  if ((*(char *)(param_1 + 0x767f) != '\0') && (bVar2 = 0, *(char *)(param_1 + 0x767e) != '\0')) {
    do {
      uVar1 = CONCAT71((int7)((ulonglong)uVar1 >> 8),bVar2);
      AHCIGetRaidInfo(param_1,bVar2);
      bVar2 = bVar2 + 1;
    } while (bVar2 < *(byte *)(param_1 + 0x767e));
  }
  AHCICheckRaidInfo(param_1);
  AHCIHwinitialize(param_1,uVar1,uVar3,uVar4);
  StorPortNotification(7,param_1);
  do {
    uVar1 = StorPortReady(param_1);
  } while ((char)uVar1 == '\0');
  *(undefined1 *)(param_1 + 0x7681) = 1;
  return CONCAT71((int7)((ulonglong)uVar1 >> 8),1);
}



===== AHCIAdapterControl @ 000132d0 =====

undefined8 AHCIAdapterControl(longlong param_1,int param_2,longlong param_3)

{
  byte *pbVar1;
  byte bVar2;
  ulonglong uVar3;
  byte bVar4;
  longlong lVar5;
  longlong lVar6;
  byte bVar7;
  byte local_res10 [8];
  
  if (param_2 == 0) {
    *(undefined1 *)(param_3 + 4) = 1;
    *(undefined1 *)(param_3 + 5) = 1;
    *(undefined1 *)(param_3 + 6) = 1;
    *(undefined1 *)(param_3 + 7) = 1;
    *(undefined1 *)(param_3 + 8) = 1;
  }
  else if (param_2 == 1) {
    local_res10[0] = *(byte *)(param_1 + 0x7551) | 4;
    StorPortSetBusDataByOffset
              (param_1,4,*(undefined4 *)(param_1 + 0x764c),*(undefined4 *)(param_1 + 0x7650),
               local_res10,5,1);
    **(byte **)(param_1 + 0x18) = **(byte **)(param_1 + 0x18) & 0xfd;
    bVar4 = 0;
    **(undefined4 **)(param_1 + 0x38) = 0;
    **(undefined4 **)(param_1 + 0x40) = 0;
    **(undefined4 **)(param_1 + 0x20) = 0xffffffff;
    if (*(char *)(param_1 + 0x767e) != '\0') {
      do {
        if (*(char *)(param_1 + 0x7681) != '\x01') break;
        if ((**(uint **)(param_1 + 0x28) >> (bVar4 & 0x1f) & 1) != 0) {
          bVar7 = 0;
          lVar6 = (ulonglong)bVar4 * 0xe28;
          do {
            if ((((*(byte *)(lVar6 + 0xd58 + param_1) & 0x20) != 0) || (bVar7 == 0)) &&
               (*(char *)((ulonglong)bVar7 + lVar6 + 0x1fa + param_1) == '\x01')) {
              *(undefined1 *)(param_1 + 0x76b4) = 0x27;
              *(byte *)(param_1 + 0x76b5) = *(byte *)(param_1 + 0x76b5) & 0xe0 | bVar7 & 0x1f | 0x80
              ;
              bVar2 = *(byte *)((ulonglong)bVar7 * 0xc0 + lVar6 + 0x2c1 + param_1);
              *(undefined2 *)(param_1 + 0x7696) = 0;
              *(undefined1 *)(param_1 + 0x7694) = 5;
              *(undefined4 *)(param_1 + 0x7698) = 0;
              *(byte *)(param_1 + 0x76b6) = (-((bVar2 & 2) != 0) & 3U) - 0x19;
              *(byte *)(param_1 + 0x7695) = *(byte *)(param_1 + 0x7695) & 8 | bVar7 << 4;
              uVar3 = AHCIGetFreeCommandSlot(param_1,bVar4,bVar7,'\0');
              AHCIFillCommand(param_1,bVar4,bVar7,(void *)0x0,0,(byte)uVar3,'\0');
              uVar3 = AHCIWaitForCommandComplete(param_1,bVar4,bVar7,'\0',100);
              if ((char)uVar3 == '\0') {
                StorPortDebugPrint(0,"[FUNCTION] %s :Stop Controler Failed(Flush).\n",
                                   "AHCIAdapterControl");
                return 1;
              }
            }
            bVar7 = bVar7 + 1;
          } while (bVar7 < 0xf);
        }
        bVar4 = bVar4 + 1;
      } while (bVar4 < *(byte *)(param_1 + 0x767e));
    }
    bVar4 = 0;
    if (*(char *)(param_1 + 0x767e) != '\0') {
      do {
        uVar3 = (ulonglong)bVar4;
        bVar4 = bVar4 + 1;
        lVar6 = uVar3 * 0xe28;
        *(undefined4 *)(*(longlong *)(lVar6 + 0x58 + param_1) + 0x14) = 0;
        *(undefined4 *)(*(longlong *)(lVar6 + 0x58 + param_1) + 0x30) = 0xffffffff;
        *(undefined4 *)(*(longlong *)(lVar6 + 0x58 + param_1) + 0x10) = 0xffffffff;
        *(undefined4 *)(*(longlong *)(lVar6 + 0x58 + param_1) + 0x18) = 0;
      } while (bVar4 < *(byte *)(param_1 + 0x767e));
    }
    local_res10[0] = *(byte *)(param_1 + 0x7551) & 0xfb;
    StorPortSetBusDataByOffset
              (param_1,4,*(undefined4 *)(param_1 + 0x764c),*(undefined4 *)(param_1 + 0x7650),
               local_res10,5,1);
  }
  else if (param_2 == 2) {
    bVar4 = 0;
    if (*(char *)(param_1 + 0x767e) != '\0') {
      do {
        uVar3 = (ulonglong)bVar4;
        bVar4 = bVar4 + 1;
        *(undefined4 *)(*(longlong *)(uVar3 * 0xe28 + 0x58 + param_1) + 0x18) = 0;
      } while (bVar4 < *(byte *)(param_1 + 0x767e));
    }
    bVar4 = 0;
    if (*(char *)(param_1 + 0x767e) != '\0') {
      do {
        bVar7 = 0;
        lVar6 = (ulonglong)bVar4 * 0xe28;
        *(undefined4 *)(*(longlong *)(lVar6 + 0x58 + param_1) + 4) = 0;
        **(undefined4 **)(lVar6 + 0x58 + param_1) = *(undefined4 *)(lVar6 + 0x68 + param_1);
        *(undefined4 *)(*(longlong *)(lVar6 + 0x58 + param_1) + 0xc) = 0;
        *(undefined4 *)(*(longlong *)(lVar6 + 0x58 + param_1) + 8) =
             *(undefined4 *)(lVar6 + 0x6c + param_1);
        if (*(char *)(param_1 + 0x767d) != '\0') {
          do {
            uVar3 = (ulonglong)bVar7;
            bVar7 = bVar7 + 1;
            lVar5 = uVar3 * 0x20;
            *(undefined4 *)(*(longlong *)(lVar6 + 0x60 + param_1) + 0xc + lVar5) = 0;
            *(undefined4 *)(*(longlong *)(lVar6 + 0x60 + param_1) + 8 + lVar5) =
                 *(undefined4 *)(param_1 + 0x170 + ((ulonglong)bVar4 * 0x38a + uVar3) * 4);
          } while (bVar7 < *(byte *)(param_1 + 0x767d));
        }
        bVar4 = bVar4 + 1;
      } while (bVar4 < *(byte *)(param_1 + 0x767e));
    }
    bVar4 = 0;
    if (*(char *)(param_1 + 0x767e) != '\0') {
      do {
        lVar6 = *(longlong *)((ulonglong)bVar4 * 0xe28 + 0x58 + param_1);
        if ((*(byte *)(lVar6 + 0x18) & 0x10) != 0) {
          pbVar1 = (byte *)(lVar6 + 0x18);
          *pbVar1 = *pbVar1 & 0xef;
        }
        lVar6 = *(longlong *)((ulonglong)bVar4 * 0xe28 + 0x58 + param_1);
        if ((*(byte *)(lVar6 + 0x18) & 1) != 0) {
          pbVar1 = (byte *)(lVar6 + 0x18);
          *pbVar1 = *pbVar1 & 0xfe;
        }
        bVar4 = bVar4 + 1;
      } while (bVar4 < *(byte *)(param_1 + 0x767e));
    }
    bVar4 = 0;
    if (*(char *)(param_1 + 0x767e) != '\0') {
      do {
        uVar3 = (ulonglong)bVar4;
        bVar4 = bVar4 + 1;
        pbVar1 = (byte *)(*(longlong *)(uVar3 * 0xe28 + 0x58 + param_1) + 0x18);
        *pbVar1 = *pbVar1 | 0x10;
      } while (bVar4 < *(byte *)(param_1 + 0x767e));
    }
    *(undefined1 *)(param_1 + 0x7680) = 1;
    *(undefined1 *)(param_1 + 0x7681) = 0;
    StorPortNotification(7,param_1);
  }
  else {
    if (param_2 == 3) {
      lVar6 = *(longlong *)(param_1 + 0x18);
    }
    else {
      if (param_2 != 4) {
        return 1;
      }
      StorPortSetBusDataByOffset
                (param_1,4,*(undefined4 *)(param_1 + 0x764c),*(undefined4 *)(param_1 + 0x7650),
                 param_1 + 0x754c,0,0x100);
      **(undefined4 **)(param_1 + 0x48) = *(undefined4 *)(param_1 + 0x7654);
      **(undefined4 **)(param_1 + 0x50) = *(undefined4 *)(param_1 + 0x7658);
      pbVar1 = (byte *)(*(longlong *)(param_1 + 0x18) + 3);
      *pbVar1 = *pbVar1 | 0x80;
      if (*(char *)(param_1 + 0x7689) != '\x01') {
        AHCIHBAReset(param_1);
      }
      lVar6 = *(longlong *)(param_1 + 0x18);
    }
    *(byte *)(lVar6 + 3) = *(byte *)(lVar6 + 3) | 0x80;
  }
  return 0;
}



===== AHCIAdjustDiskSize @ 00013750 =====

void AHCIAdjustDiskSize(longlong param_1,ushort param_2)

{
  byte *pbVar1;
  char cVar2;
  byte bVar3;
  ushort uVar4;
  ulonglong uVar5;
  int iVar6;
  longlong lVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  byte *pbVar10;
  longlong lVar11;
  
  lVar7 = 0;
  lVar11 = (ulonglong)param_2 * 0x100;
  uVar4 = *(ushort *)(lVar11 + 0x3922 + param_1);
  cVar2 = *(char *)(lVar11 + 0x3920 + param_1);
  if (cVar2 == '\x01') {
    if (uVar4 != 0) {
      pbVar10 = (byte *)(lVar11 + 0x3959 + param_1);
      uVar9 = (ulonglong)uVar4;
      do {
        bVar3 = *pbVar10;
        pbVar1 = pbVar10 + -1;
        pbVar10 = pbVar10 + 3;
        lVar7 = lVar7 + *(longlong *)
                         ((ulonglong)bVar3 * 0xc0 + 0x2c8 + param_1 + (ulonglong)*pbVar1 * 0xe28);
        uVar9 = uVar9 - 1;
      } while (uVar9 != 0);
    }
    iVar6 = (uint)uVar4 * 0x4f + -0x3f;
  }
  else {
    if (cVar2 != '\x02') {
      if (cVar2 == '\x03') {
        uVar9 = *(ulonglong *)
                 ((ulonglong)*(byte *)(lVar11 + 0x3958 + param_1) * 0xe28 + 0x2c8 +
                 param_1 + (ulonglong)*(byte *)(lVar11 + 0x3959 + param_1) * 0xc0);
        uVar8 = *(ulonglong *)
                 ((ulonglong)*(byte *)(lVar11 + 0x395c + param_1) * 0xc0 + 0x2c8 +
                 param_1 + (ulonglong)*(byte *)(lVar11 + 0x395b + param_1) * 0xe28);
        if (uVar8 < uVar9) {
          uVar9 = uVar8;
        }
        lVar7 = uVar9 - 0x10;
      }
      else if (cVar2 == '\x04') {
        pbVar10 = (byte *)(lVar11 + 0x395c + param_1);
        lVar7 = 3;
        uVar9 = *(ulonglong *)
                 ((ulonglong)*(byte *)(lVar11 + 0x3958 + param_1) * 0xe28 + 0x2c8 +
                 param_1 + (ulonglong)*(byte *)(lVar11 + 0x3959 + param_1) * 0xc0);
        do {
          uVar8 = *(ulonglong *)
                   ((ulonglong)*pbVar10 * 0xc0 + 0x2c8 + param_1 + (ulonglong)pbVar10[-1] * 0xe28);
          if (uVar8 < uVar9) {
            uVar9 = uVar8;
          }
          pbVar10 = pbVar10 + 3;
          lVar7 = lVar7 + -1;
        } while (lVar7 != 0);
        lVar7 = (uVar9 - (uVar9 - 0x4f) % (ulonglong)*(uint *)(lVar11 + 0x3a0c + param_1)) * 2 +
                -0x5f;
      }
      goto LAB_00013990;
    }
    uVar9 = *(ulonglong *)
             ((ulonglong)*(byte *)(lVar11 + 0x3958 + param_1) * 0xe28 + 0x2c8 +
             param_1 + (ulonglong)*(byte *)(lVar11 + 0x3959 + param_1) * 0xc0);
    if (1 < uVar4) {
      pbVar10 = (byte *)(lVar11 + 0x395c + param_1);
      uVar8 = (ulonglong)(ushort)(uVar4 - 1);
      do {
        uVar5 = *(ulonglong *)
                 ((ulonglong)*pbVar10 * 0xc0 + 0x2c8 + param_1 + (ulonglong)pbVar10[-1] * 0xe28);
        if (uVar5 < uVar9) {
          uVar9 = uVar5;
        }
        pbVar10 = pbVar10 + 3;
        uVar8 = uVar8 - 1;
      } while (uVar8 != 0);
    }
    lVar7 = (uVar9 - (uVar9 - 0x4f) % (ulonglong)*(uint *)(lVar11 + 0x3a0c + param_1)) *
            (ulonglong)uVar4 - (longlong)(int)((uint)uVar4 * 0x3f + -0x3f);
    iVar6 = (uint)uVar4 << 4;
  }
  lVar7 = lVar7 - iVar6;
LAB_00013990:
  *(longlong *)(lVar11 + 0x3928 + param_1) = lVar7;
  return;
}



===== AHCIRWTheSiSInfoSector @ 000139b0 =====

ulonglong AHCIRWTheSiSInfoSector(longlong param_1,byte param_2,byte param_3,byte param_4)

{
  short *psVar1;
  char cVar2;
  byte bVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  void *pvVar6;
  longlong lVar7;
  longlong lVar8;
  longlong lVar9;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  local_24 = *(undefined4 *)(param_1 + 0x7548);
  uVar5 = (ulonglong)param_3;
  local_28 = 0;
  lVar9 = (ulonglong)param_2 * 0xe28;
  lVar8 = uVar5 * 0xc0 + lVar9;
  *(undefined4 *)(*(longlong *)(lVar9 + 0x58 + param_1) + 0x30) = 0xffffffff;
  local_20 = 0x200;
  *(undefined4 *)(*(longlong *)(lVar9 + 0x58 + param_1) + 0x10) = 0xffffffff;
  *(undefined1 *)(param_1 + 0x76b4) = 0x27;
  *(undefined1 *)(param_1 + 0x76c0) = 1;
  *(undefined1 *)(param_1 + 0x76c1) = 0;
  *(byte *)(param_1 + 0x76b5) = *(byte *)(param_1 + 0x76b5) & 0xe0 | param_3 & 0x1f | 0x80;
  lVar7 = *(longlong *)(lVar8 + 0x2c8 + param_1) + -0x10;
  *(char *)(param_1 + 0x76b8) = (char)lVar7;
  *(char *)(param_1 + 0x76b9) = (char)((ulonglong)lVar7 >> 8);
  *(char *)(param_1 + 0x76ba) = (char)((ulonglong)lVar7 >> 0x10);
  bVar3 = (byte)((ulonglong)lVar7 >> 0x18);
  if ((*(byte *)(lVar8 + 0x2c1 + param_1) & 2) == 0) {
    *(byte *)(param_1 + 0x76bb) = bVar3 & 0xf | 0xe0;
  }
  else {
    *(undefined1 *)(param_1 + 0x76bb) = 0xe0;
    *(byte *)(param_1 + 0x76bc) = bVar3;
    *(char *)(param_1 + 0x76be) = (char)((ulonglong)lVar7 >> 0x28);
    *(char *)(param_1 + 0x76bd) = (char)((ulonglong)lVar7 >> 0x20);
  }
  bVar3 = *(byte *)(lVar8 + 0x2c1 + param_1);
  if ((bVar3 & 0x20) == 0) {
    if (param_4 == 0) {
      bVar3 = bVar3 & 2 | 0x10;
    }
    else {
      bVar3 = bVar3 & 2 | 0x18;
    }
    cVar2 = bVar3 * '\x02';
  }
  else if (param_4 == 0) {
    cVar2 = (-((bVar3 & 2) != 0) & 0x5dU) - 0x38;
  }
  else {
    cVar2 = (-((bVar3 & 2) != 0) & 0x6bU) - 0x36;
  }
  *(char *)(param_1 + 0x76b6) = cVar2;
  *(byte *)(param_1 + 0x7694) = (param_4 & 1) << 6 | 5;
  *(undefined2 *)(param_1 + 0x7696) = 1;
  *(byte *)(param_1 + 0x7695) = *(byte *)(param_1 + 0x7695) & 8 | param_3 << 4;
  *(undefined4 *)(param_1 + 0x7698) = 0;
  uVar4 = AHCIGetFreeCommandSlot(param_1,param_2,param_3,'\0');
  AHCIFillCommand(param_1,param_2,param_3,(void *)0x0,(longlong)&local_28,(byte)uVar4,'\0');
  uVar4 = AHCIWaitForCommandComplete(param_1,param_2,param_3,'\0',100);
  if ((char)uVar4 == '\0') {
    *(undefined1 *)(uVar5 + lVar9 + 0x1fa + param_1) = 0x5a;
    uVar5 = 0xffff;
    *(short *)(param_1 + 0x7518) = *(short *)(param_1 + 0x7518) + -1;
    psVar1 = (short *)(lVar9 + 0x1f8 + param_1);
    *psVar1 = *psVar1 + -1;
    if (((*(byte *)(lVar9 + 0xd58 + param_1) & 0x20) == 0) ||
       (*(short *)(lVar9 + 0x1f8 + param_1) == 0)) {
      uVar5 = *(ulonglong *)(lVar9 + 0x58 + param_1);
      *(byte *)(uVar5 + 0x18) = *(byte *)(uVar5 + 0x18) & 0xfe;
    }
    uVar5 = uVar5 & 0xffffffffffffff00;
  }
  else {
    pvVar6 = memcpy((void *)((uVar5 * 3 + 9) * 0x40 + lVar9 + param_1),*(void **)(param_1 + 0x7540),
                    0x80);
    uVar5 = CONCAT71((int7)((ulonglong)pvVar6 >> 8),1);
  }
  return uVar5;
}



===== AHCIGetRaidInfo @ 00013c1c =====

undefined8 AHCIGetRaidInfo(longlong param_1,byte param_2)

{
  ulonglong in_RAX;
  longlong lVar1;
  byte bVar2;
  ulonglong uVar3;
  
  lVar1 = (ulonglong)param_2 * 0xe28;
  if (*(short *)(lVar1 + 0x1f8 + param_1) != 0) {
    if ((*(byte *)(lVar1 + 0xd58 + param_1) & 0x20) == 0) {
      if ((*(char *)(lVar1 + 0x1fa + param_1) == '\x01') &&
         (in_RAX = AHCIRWTheSiSInfoSector(param_1,param_2,0,0), (char)in_RAX == '\0')) {
LAB_00013c97:
        return in_RAX & 0xffffffffffffff00;
      }
    }
    else {
      uVar3 = 0;
      if (*(char *)(lVar1 + 0xd59 + param_1) != '\0') {
        do {
          in_RAX = uVar3 + lVar1;
          if ((*(char *)(in_RAX + 0x1fa + param_1) == '\x01') &&
             (in_RAX = AHCIRWTheSiSInfoSector(param_1,param_2,(byte)uVar3,0), (char)in_RAX == '\0'))
          goto LAB_00013c97;
          bVar2 = (byte)uVar3 + 1;
          uVar3 = (ulonglong)bVar2;
        } while (bVar2 < *(byte *)(lVar1 + 0xd59 + param_1));
      }
    }
  }
  return CONCAT71((int7)(in_RAX >> 8),1);
}



===== AHCIProcessBrokenJBOD_StripedSet @ 00013cd4 =====

void AHCIProcessBrokenJBOD_StripedSet(longlong param_1,ushort param_2)

{
  byte bVar1;
  byte bVar2;
  short sVar3;
  byte bVar4;
  ushort uVar5;
  ulonglong uVar6;
  longlong lVar7;
  ushort uVar8;
  longlong lVar9;
  longlong lVar10;
  
  if (param_2 < 0x3c) {
    lVar9 = (ulonglong)param_2 * 0x100;
    uVar8 = 0;
    if (*(short *)(lVar9 + 0x3922 + param_1) != 0) {
      do {
        sVar3 = *(short *)(lVar9 + 0x3a10 + param_1);
        lVar7 = lVar9 + (ulonglong)uVar8 * 3;
        bVar1 = *(byte *)(lVar7 + 0x3959 + param_1);
        bVar2 = *(byte *)(lVar7 + 0x3958 + param_1);
        if (sVar3 == 0) {
          return;
        }
        lVar7 = lVar9 + ((ulonglong)uVar8 + 0x131e) * 3;
        if (*(char *)(lVar7 + param_1) == 'Z') {
          lVar10 = (ulonglong)bVar2 * 0xe28;
          if (*(char *)((ulonglong)bVar1 + lVar10 + 0x1fa + param_1) == '\x01') {
            if (sVar3 == 1) {
              uVar5 = param_2;
            }
            else {
              uVar6 = 0;
              do {
                bVar4 = (byte)uVar6;
                if ((*(char *)(uVar6 * 0x100 + 0x3a12 + param_1) == '\0') &&
                   (*(char *)(uVar6 * 0x100 + 0x3a13 + param_1) == '\0')) break;
                bVar4 = bVar4 + 1;
                uVar6 = (ulonglong)bVar4;
              } while (bVar4 < 0x3c);
              uVar5 = (ushort)bVar4;
            }
            if (uVar5 != 0x3c) {
              *(short *)(lVar9 + 0x3a10 + param_1) = sVar3 + -1;
              *(undefined1 *)(lVar7 + param_1) = 0;
              lVar7 = (ulonglong)uVar5 * 0x100;
              *(undefined1 *)(lVar7 + 0x3924 + param_1) = 1;
              *(undefined1 *)(lVar7 + 0x3a15 + param_1) = 1;
              *(undefined1 *)(lVar7 + 0x3920 + param_1) = 0;
              *(undefined2 *)(lVar7 + 0x3922 + param_1) = 1;
              *(undefined8 *)(lVar7 + 0x3928 + param_1) = 0;
              memcpy((void *)(lVar7 + 0x3930 + param_1),"Broken",6);
              memcpy((void *)(lVar7 + 0x3936 + param_1),
                     (void *)((ulonglong)bVar1 * 0xc0 + lVar10 + 0x218 + param_1),0x22);
              *(byte *)(lVar7 + 0x3958 + param_1) = bVar2;
              *(undefined1 *)(lVar7 + 0x395a + param_1) = 0x5a;
              *(byte *)(lVar7 + 0x3959 + param_1) = bVar1;
            }
          }
          else {
            *(undefined1 *)(lVar7 + param_1) = 0;
          }
        }
        uVar8 = uVar8 + 1;
      } while (uVar8 < *(ushort *)(lVar9 + 0x3922 + param_1));
    }
  }
  return;
}



===== AHCIProcessBorkenMirrorSet @ 00013eac =====

void AHCIProcessBorkenMirrorSet(longlong param_1,ushort param_2)

{
  longlong lVar1;
  byte bVar2;
  byte bVar3;
  longlong lVar4;
  byte bVar5;
  void *_Src;
  
  if (param_2 < 0x3c) {
    lVar4 = (ulonglong)param_2 * 0x100;
    bVar3 = 0;
    bVar2 = 0;
    bVar5 = 0;
    if (*(short *)(lVar4 + 0x3922 + param_1) != 0) {
      do {
        if (*(char *)(lVar4 + ((ulonglong)bVar5 + 0x131e) * 3 + param_1) == 'Z') {
          lVar1 = lVar4 + (ulonglong)bVar5 * 3;
          bVar3 = *(byte *)(lVar1 + 0x3958 + param_1);
          bVar2 = *(byte *)(lVar1 + 0x3959 + param_1);
        }
        bVar5 = bVar5 + 1;
      } while ((ushort)bVar5 < *(ushort *)(lVar4 + 0x3922 + param_1));
    }
    *(undefined1 *)(lVar4 + 0x3924 + param_1) = 1;
    *(undefined1 *)(lVar4 + 0x3a15 + param_1) = 1;
    *(undefined1 *)(lVar4 + 0x3920 + param_1) = 0;
    *(undefined2 *)(lVar4 + 0x3922 + param_1) = 1;
    if (*(longlong *)(lVar4 + 0x3928 + param_1) == 0) {
      *(undefined8 *)(lVar4 + 0x3928 + param_1) =
           *(undefined8 *)((ulonglong)bVar2 * 0xc0 + 0x2c8 + param_1 + (ulonglong)bVar3 * 0xe28);
    }
    _Src = (void *)((ulonglong)bVar3 * 0xe28 + param_1 + ((ulonglong)bVar2 * 3 + 9) * 0x40);
    if (*(char *)(lVar4 + 0x3a12 + param_1) != '\x01') {
      *(undefined1 *)(lVar4 + 0x3a12 + param_1) = 1;
      memcpy((void *)(lVar4 + 0x3930 + param_1),&s_SiSRAID1_SET,0xc);
      *(byte *)(lVar4 + 0x393c + param_1) = (*(byte *)((longlong)_Src + 0x45) & 0xf) + 0x30;
    }
    *(byte *)(lVar4 + 0x3958 + param_1) = bVar3;
    *(byte *)(lVar4 + 0x3959 + param_1) = bVar2;
    *(undefined1 *)(lVar4 + 0x395a + param_1) = 0x5a;
    *(undefined1 *)(lVar4 + 0x395d + param_1) = 0;
    *(undefined1 *)((longlong)_Src + 0x3e) = 1;
    memcpy(*(void **)(param_1 + 0x7540),_Src,0x80);
    AHCIRWTheSiSInfoSector(param_1,bVar3,bVar2,1);
  }
  return;
}



===== AHCIProcessBorkenStripedMirrorSet @ 00014060 =====

void AHCIProcessBorkenStripedMirrorSet(longlong param_1,ushort param_2)

{
  short sVar1;
  byte bVar2;
  ushort uVar3;
  longlong lVar4;
  longlong lVar5;
  byte bVar6;
  char *pcVar7;
  byte bVar8;
  void *_Src;
  longlong local_res18;
  
  if (0x3b < param_2) {
    return;
  }
  lVar5 = (ulonglong)param_2 * 0x100;
  pcVar7 = (char *)(param_1 + 0x395a + lVar5);
  if ((*pcVar7 != 'Z') || (*(char *)(param_1 + 0x395d + lVar5) != 'Z')) {
    if ((*(char *)(param_1 + 0x3960 + lVar5) != 'Z') || (*(char *)(param_1 + 0x3963 + lVar5) != 'Z')
       ) {
      local_res18 = 4;
      do {
        if (*pcVar7 == 'Z') {
          bVar6 = pcVar7[-2];
          bVar8 = pcVar7[-1];
          *pcVar7 = '\0';
          if ((bVar6 != 0xff) && (bVar8 != 0xff)) {
            sVar1 = *(short *)(param_1 + 0x3a10 + lVar5);
            if (sVar1 == 1) {
              uVar3 = param_2;
            }
            else {
              bVar2 = 0;
              do {
                if ((*(char *)((ulonglong)bVar2 * 0x100 + 0x3a12 + param_1) == '\0') &&
                   (*(char *)((ulonglong)bVar2 * 0x100 + 0x3a13 + param_1) == '\0')) break;
                bVar2 = bVar2 + 1;
              } while (bVar2 < 0x3c);
              uVar3 = (ushort)bVar2;
            }
            if (uVar3 != 0x3c) {
              *(short *)(param_1 + 0x3a10 + lVar5) = sVar1 + -1;
              lVar4 = (ulonglong)uVar3 * 0x100;
              *(undefined1 *)(lVar4 + 0x3924 + param_1) = 1;
              *(undefined1 *)(lVar4 + 0x3a15 + param_1) = 1;
              *(undefined1 *)(lVar4 + 0x3920 + param_1) = 0;
              *(undefined2 *)(lVar4 + 0x3922 + param_1) = 1;
              *(undefined8 *)(lVar4 + 0x3928 + param_1) = 0;
              memcpy((void *)(lVar4 + 0x3930 + param_1),
                     (void *)((ulonglong)bVar8 * 0xc0 + 0x218 + param_1 + (ulonglong)bVar6 * 0xe28),
                     0x28);
              *(byte *)(lVar4 + 0x3959 + param_1) = bVar8;
              *(undefined1 *)(lVar4 + 0x395a + param_1) = 0x5a;
              *(byte *)(lVar4 + 0x3958 + param_1) = bVar6;
            }
          }
        }
        pcVar7 = pcVar7 + 3;
        local_res18 = local_res18 + -1;
        if (local_res18 == 0) {
          return;
        }
      } while( true );
    }
    if (*pcVar7 == 'Z') {
      bVar6 = *(byte *)(param_1 + 0x3958 + lVar5);
      bVar8 = *(byte *)(param_1 + 0x3959 + lVar5);
      *pcVar7 = '\0';
LAB_000142f1:
      if ((bVar6 != 0xff) && (bVar8 != 0xff)) {
        bVar2 = 0;
        do {
          if ((*(char *)((ulonglong)bVar2 * 0x100 + 0x3a12 + param_1) == '\0') &&
             (*(char *)((ulonglong)bVar2 * 0x100 + 0x3a13 + param_1) == '\0')) break;
          bVar2 = bVar2 + 1;
        } while (bVar2 < 0x3c);
        if (bVar2 != 0x3c) {
          lVar4 = (ulonglong)bVar2 * 0x100;
          *(undefined1 *)(lVar4 + 0x3924 + param_1) = 1;
          *(undefined1 *)(lVar4 + 0x3a15 + param_1) = 1;
          *(undefined4 *)(lVar4 + 0x3918 + param_1) = 0;
          *(undefined4 *)(lVar4 + 0x391c + param_1) = 0;
          *(undefined1 *)(lVar4 + 0x3920 + param_1) = 0;
          *(undefined2 *)(lVar4 + 0x3922 + param_1) = 1;
          *(undefined8 *)(lVar4 + 0x3928 + param_1) = 0;
          memcpy((void *)(lVar4 + 0x3930 + param_1),
                 (void *)((ulonglong)bVar8 * 0xc0 + 0x218 + param_1 + (ulonglong)bVar6 * 0xe28),0x28
                );
          *(byte *)(lVar4 + 0x3958 + param_1) = bVar6;
          *(byte *)(lVar4 + 0x3959 + param_1) = bVar8;
          *(undefined1 *)(lVar4 + 0x395a + param_1) = 0x5a;
        }
      }
    }
    else if (*(char *)(param_1 + 0x395d + lVar5) == 'Z') {
      bVar6 = *(byte *)(param_1 + 0x395b + lVar5);
      bVar8 = *(byte *)(param_1 + 0x395c + lVar5);
      *(undefined1 *)(param_1 + 0x395d + lVar5) = 0;
      goto LAB_000142f1;
    }
    bVar6 = *(byte *)(param_1 + 0x395f + lVar5);
    bVar8 = *(byte *)(param_1 + 0x395e + lVar5);
    *(undefined1 *)(param_1 + 0x3920 + lVar5) = 2;
    *(undefined2 *)(param_1 + 0x3922 + lVar5) = 2;
    *pcVar7 = 'Z';
    *(undefined1 *)(param_1 + 0x395d + lVar5) = 0x5a;
    *(undefined1 *)(param_1 + 0x395b + lVar5) = *(undefined1 *)(param_1 + 0x3961 + lVar5);
    *(undefined1 *)(param_1 + 0x395c + lVar5) = *(undefined1 *)(param_1 + 0x3962 + lVar5);
    *(undefined1 *)(param_1 + 0x3924 + lVar5) = 1;
    *(undefined1 *)(param_1 + 0x3a15 + lVar5) = 1;
    _Src = (void *)((ulonglong)bVar8 * 0xe28 + param_1 + ((ulonglong)bVar6 * 3 + 9) * 0x40);
    *(byte *)(param_1 + 0x3958 + lVar5) = bVar8;
    *(byte *)(param_1 + 0x3959 + lVar5) = bVar6;
    *(undefined1 *)(param_1 + 0x3960 + lVar5) = 0;
    *(undefined1 *)(param_1 + 0x3963 + lVar5) = 0;
    if (*(char *)(param_1 + 0x3a12 + lVar5) != '\x01') {
      *(undefined1 *)(param_1 + 0x3a12 + lVar5) = 1;
      memcpy((void *)(param_1 + 0x3930 + lVar5),&s_SiSRAID0_1_SET,0xe);
      *(byte *)(param_1 + 0x393e + lVar5) = (*(byte *)((longlong)_Src + 0x45) & 0xf) + 0x30;
    }
    *(undefined1 *)((longlong)_Src + 0x3e) = 1;
    memcpy(*(void **)(param_1 + 0x7540),_Src,0x80);
    goto LAB_000144c0;
  }
  if (*(char *)(param_1 + 0x3960 + lVar5) == 'Z') {
    bVar6 = *(byte *)(param_1 + 0x395e + lVar5);
    bVar8 = *(byte *)(param_1 + 0x395f + lVar5);
    *(undefined1 *)(param_1 + 0x3960 + lVar5) = 0;
LAB_00014106:
    if ((bVar6 != 0xff) && (bVar8 != 0xff)) {
      bVar2 = 0;
      do {
        if ((*(char *)((ulonglong)bVar2 * 0x100 + 0x3a12 + param_1) == '\0') &&
           (*(char *)((ulonglong)bVar2 * 0x100 + 0x3a13 + param_1) == '\0')) break;
        bVar2 = bVar2 + 1;
      } while (bVar2 < 0x3c);
      if (bVar2 != 0x3c) {
        lVar4 = (ulonglong)bVar2 * 0x100;
        *(undefined1 *)(lVar4 + 0x3924 + param_1) = 1;
        *(undefined1 *)(lVar4 + 0x3a15 + param_1) = 1;
        *(undefined4 *)(lVar4 + 0x3918 + param_1) = 0;
        *(undefined4 *)(lVar4 + 0x391c + param_1) = 0;
        *(undefined1 *)(lVar4 + 0x3920 + param_1) = 0;
        *(undefined2 *)(lVar4 + 0x3922 + param_1) = 1;
        *(undefined8 *)(lVar4 + 0x3928 + param_1) = 0;
        memcpy((void *)(lVar4 + 0x3930 + param_1),
               (void *)((ulonglong)bVar8 * 0xc0 + 0x218 + param_1 + (ulonglong)bVar6 * 0xe28),0x28);
        *(byte *)(lVar4 + 0x3958 + param_1) = bVar6;
        *(byte *)(lVar4 + 0x3959 + param_1) = bVar8;
        *(undefined1 *)(lVar4 + 0x395a + param_1) = 0x5a;
      }
    }
  }
  else if (*(char *)(param_1 + 0x3963 + lVar5) == 'Z') {
    bVar6 = *(byte *)(param_1 + 0x3961 + lVar5);
    bVar8 = *(byte *)(param_1 + 0x3962 + lVar5);
    *(undefined1 *)(param_1 + 0x3963 + lVar5) = 0;
    goto LAB_00014106;
  }
  bVar6 = *(byte *)(param_1 + 0x3959 + lVar5);
  bVar8 = *(byte *)(param_1 + 0x3958 + lVar5);
  *(undefined1 *)(param_1 + 0x3920 + lVar5) = 2;
  *(undefined2 *)(param_1 + 0x3922 + lVar5) = 2;
  *(undefined1 *)(param_1 + 0x3924 + lVar5) = 1;
  *(undefined1 *)(param_1 + 0x3a15 + lVar5) = 1;
  _Src = (void *)((ulonglong)bVar8 * 0xe28 + param_1 + ((ulonglong)bVar6 * 3 + 9) * 0x40);
  if (*(char *)(param_1 + 0x3a12 + lVar5) != '\x01') {
    *(undefined1 *)(param_1 + 0x3a12 + lVar5) = 1;
    memcpy((void *)(param_1 + 0x3930 + lVar5),&s_SiSRAID0_1_SET,0xe);
    *(byte *)(param_1 + 0x393e + lVar5) = (*(byte *)((longlong)_Src + 0x45) & 0xf) + 0x30;
  }
  *(undefined1 *)((longlong)_Src + 0x3e) = 1;
  memcpy(*(void **)(param_1 + 0x7540),_Src,0x80);
LAB_000144c0:
  AHCIRWTheSiSInfoSector(param_1,bVar8,bVar6,1);
  bVar6 = *(byte *)(param_1 + 0x395c + lVar5);
  bVar8 = *(byte *)(param_1 + 0x395b + lVar5);
  *(undefined1 *)((longlong)_Src + 0x3e) = 1;
  memcpy(*(void **)(param_1 + 0x7540),
         (void *)((ulonglong)bVar8 * 0xe28 + param_1 + ((ulonglong)bVar6 * 3 + 9) * 0x40),0x80);
  AHCIRWTheSiSInfoSector(param_1,bVar8,bVar6,1);
  if (*(longlong *)(param_1 + 0x3928 + lVar5) == 0) {
    AHCIAdjustDiskSize(param_1,param_2);
  }
  return;
}



===== AHCIGetRaidOrder @ 00014694 =====

undefined8 AHCIGetRaidOrder(longlong param_1)

{
  byte bVar1;
  undefined8 in_RAX;
  undefined7 uVar2;
  undefined1 uVar3;
  
  bVar1 = *(byte *)(param_1 + 0x3c);
  uVar3 = 0;
  uVar2 = (undefined7)((ulonglong)in_RAX >> 8);
  if (bVar1 != *(byte *)(param_1 + 2) >> 4) {
    if (bVar1 == (*(byte *)(param_1 + 2) & 0xf)) {
      uVar3 = 1;
    }
    else if (bVar1 == *(byte *)(param_1 + 1) >> 4) {
      uVar3 = 2;
    }
    else {
      uVar3 = 0;
      uVar2 = 0;
      if (bVar1 == (*(byte *)(param_1 + 1) & 0xf)) {
        uVar3 = 3;
      }
    }
  }
  return CONCAT71(uVar2,uVar3);
}



===== SearchTheFreeLogicalVolumn @ 000146e4 =====

byte SearchTheFreeLogicalVolumn(longlong param_1,byte param_2,char param_3)

{
  byte bVar1;
  
  if (((param_3 == '\0') && (*(char *)((ulonglong)param_2 * 0x100 + 0x3a12 + param_1) == '\0')) &&
     (*(char *)((ulonglong)param_2 * 0x100 + 0x3a13 + param_1) == '\0')) {
    return param_2;
  }
  bVar1 = 0;
  while ((*(char *)((ulonglong)bVar1 * 0x100 + 0x3a12 + param_1) != '\0' ||
         (*(char *)((ulonglong)bVar1 * 0x100 + 0x3a13 + param_1) != '\0'))) {
    bVar1 = bVar1 + 1;
    if (0x3b < bVar1) {
      return bVar1;
    }
  }
  return bVar1;
}



===== AHCICheckRaidInfo @ 0001473c =====

void AHCICheckRaidInfo(longlong param_1)

{
  char cVar1;
  undefined1 uVar2;
  byte bVar3;
  bool bVar4;
  byte bVar5;
  ulonglong uVar6;
  undefined7 extraout_var;
  undefined7 extraout_var_00;
  undefined7 extraout_var_01;
  longlong lVar7;
  byte *pbVar8;
  longlong lVar9;
  byte bVar10;
  undefined1 *puVar11;
  short *psVar12;
  short sVar13;
  byte *pbVar14;
  ushort uVar15;
  ulonglong uVar16;
  ulonglong uVar17;
  ulonglong uVar18;
  longlong lVar19;
  longlong lVar20;
  byte bVar21;
  ushort uVar22;
  ushort local_res8;
  ushort local_res18;
  
  puVar11 = (undefined1 *)(param_1 + 0x3a14);
  uVar6 = 0;
  uVar22 = (ushort)*(byte *)(param_1 + 0x767e) * 0xf;
  do {
    sVar13 = 0;
    if (puVar11[-1] == '\x01') {
      uVar16 = 0;
      lVar7 = uVar6 * 0x100;
      if (*(short *)(lVar7 + 0x3922 + param_1) != 0) {
        do {
          lVar20 = lVar7 + (uVar16 + 0x131e) * 3;
          if (*(char *)(lVar20 + param_1) == 'Z') {
            lVar9 = lVar7 + uVar16 * 3;
            uVar17 = (ulonglong)((int)*(char *)(lVar9 + 0x3959 + param_1) & 0xffff);
            lVar19 = (ulonglong)((int)*(char *)(lVar9 + 0x3958 + param_1) & 0xffff) * 0xe28;
            cVar1 = *(char *)(lVar19 + uVar17 + 0x1fa + param_1);
            if ((cVar1 == '\x01') || (cVar1 == '\x11')) {
              lVar19 = (uVar17 * 3 + 9) * 0x40 + lVar19;
              bVar21 = *(byte *)(lVar7 + 0x3920 + param_1);
              bVar10 = *(byte *)(lVar19 + 3 + param_1) >> 4;
              if ((bVar10 != bVar21) &&
                 ((*(char *)(lVar7 + 0x3a15 + param_1) == '\0' || ((bVar10 != 3 && (bVar10 != 4)))))
                 ) goto LAB_0001480b;
              *(undefined4 *)(lVar7 + 0x391c + param_1) = *(undefined4 *)(lVar19 + 0x10 + param_1);
            }
            else {
              bVar21 = *(byte *)(lVar7 + 0x3920 + param_1);
LAB_0001480b:
              if (bVar21 != 0) {
                *(undefined1 *)(lVar9 + 0x3959 + param_1) = 0xff;
              }
              sVar13 = sVar13 + 1;
            }
            *(undefined1 *)(lVar20 + param_1) = 0;
          }
          uVar15 = (short)uVar16 + 1;
          uVar16 = (ulonglong)uVar15;
        } while (uVar15 < *(ushort *)(lVar7 + 0x3922 + param_1));
      }
      if (sVar13 == *(short *)(lVar7 + 0x3922 + param_1)) {
        *(undefined4 *)(lVar7 + 0x3918 + param_1) = 0;
        *(undefined4 *)(lVar7 + 0x391c + param_1) = 0;
        *(undefined1 *)(lVar7 + 0x3a12 + param_1) = 0;
      }
      if (*(char *)(lVar7 + 0x3a12 + param_1) == '\0') {
        memset((void *)(lVar7 + 0x3930 + param_1),0,0x28);
        uVar16 = 0x28;
      }
      *(undefined1 *)(lVar7 + 0x3924 + param_1) = 0;
      *(undefined1 *)(uVar16 * 0x100 + 0x3a14 + param_1) = 0;
      *(undefined1 *)(lVar7 + 0x3920 + param_1) = 0;
      *(undefined2 *)(lVar7 + 0x3a10 + param_1) = 0;
      *(undefined2 *)(lVar7 + 0x3922 + param_1) = 0;
      *(undefined1 *)(lVar7 + 0x3a13 + param_1) = 0;
    }
    else {
      puVar11[-0xf0] = 0;
      *puVar11 = 0;
      *(undefined4 *)(puVar11 + -0xfc) = 0;
      *(undefined4 *)(puVar11 + -0xf8) = 0;
      *(undefined2 *)(puVar11 + -4) = 0;
      *(undefined2 *)(puVar11 + -0xf2) = 0;
      puVar11[-2] = 0;
      puVar11[-1] = 0;
      puVar11[2] = 0;
      uVar16 = 0;
      if (uVar22 != 0) {
        do {
          bVar21 = (char)uVar16 + 1;
          lVar7 = uVar16 * 3 + (-0x3a14 - param_1);
          puVar11[param_1 + lVar7 + 0x3958] = 0;
          puVar11[param_1 + lVar7 + 0x3959] = 0xff;
          puVar11[param_1 + (uVar16 + 0x131e) * 3 + (-0x3a14 - param_1)] = 0;
          uVar16 = (ulonglong)bVar21;
        } while (bVar21 < uVar22);
      }
    }
    bVar21 = (char)uVar6 + 1;
    uVar6 = (ulonglong)bVar21;
    puVar11 = puVar11 + 0x100;
  } while (bVar21 < 0x3c);
  bVar21 = 0;
  if (*(char *)(param_1 + 0x767e) != '\0') {
    do {
      uVar6 = (ulonglong)bVar21;
      bVar21 = bVar21 + 1;
      lVar7 = uVar6 * 0xe28;
      *(undefined8 *)(lVar7 + 0x209 + param_1) = 0;
      *(undefined4 *)(lVar7 + 0x211 + param_1) = 0;
      *(undefined2 *)(lVar7 + 0x215 + param_1) = 0;
      *(undefined1 *)(lVar7 + 0x217 + param_1) = 0;
    } while (bVar21 < *(byte *)(param_1 + 0x767e));
  }
  uVar6 = (ulonglong)local_res8;
  bVar21 = 0;
  if (*(char *)(param_1 + 0x767e) != '\0') {
    do {
      bVar10 = 0;
      lVar7 = (ulonglong)bVar21 * 0xe28;
      do {
        uVar16 = 0;
        if (((*(byte *)(lVar7 + 0xd58 + param_1) & 0x20) != 0) || (bVar10 == 0)) {
          uVar17 = (ulonglong)bVar10;
          cVar1 = *(char *)(lVar7 + uVar17 + 0x1fa + param_1);
          if (cVar1 == '\x01') {
            lVar20 = (uVar17 * 3 + 9) * 0x40 + lVar7 + param_1;
            if ((*(int *)(lVar20 + 8) == 0x10390180) && ((*(byte *)(lVar20 + 3) & 0xf0) != 0)) {
              do {
                if ((*(int *)(uVar16 * 0x100 + 0x3918 + param_1) == 0x10390180) &&
                   (*(int *)(lVar20 + 0x10) == *(int *)(uVar16 * 0x100 + 0x391c + param_1))) {
                  if (*(char *)(lVar20 + 0x3e) == '\x01') {
                    *(undefined1 *)(uVar16 * 0x100 + 0x3a14 + param_1) = 1;
                  }
                  uVar17 = AHCIGetRaidOrder(lVar20);
                  uVar15 = (ushort)uVar16;
                  lVar19 = (uVar16 & 0xffff) * 0x100;
                  lVar9 = lVar19 + (uVar17 & 0xff) * 3;
                  *(byte *)(lVar9 + 0x3958 + param_1) = bVar21;
                  *(byte *)(lVar9 + 0x3959 + param_1) = bVar10;
                  *(undefined1 *)(lVar19 + ((uVar17 & 0xff) + 0x131e) * 3 + param_1) = 0x5a;
                  psVar12 = (short *)(lVar19 + 0x3a10 + param_1);
                  *psVar12 = *psVar12 + 1;
                  if ((*(char *)(lVar19 + 0x3a12 + param_1) == '\x01') ||
                     (*(char *)(lVar19 + 0x3920 + param_1) == '\0')) {
                    *(byte *)(lVar19 + 0x3920 + param_1) = *(byte *)(lVar20 + 3) >> 4;
                    bVar5 = *(byte *)(lVar20 + 3);
                    *(undefined1 *)(lVar19 + 0x3a13 + param_1) = 1;
                    *(ushort *)(lVar19 + 0x3922 + param_1) = (ushort)(bVar5 & 0xf);
                    *(undefined1 *)(lVar19 + 0x3a16 + param_1) = *(undefined1 *)(lVar20 + 0x45);
                  }
                  break;
                }
                uVar15 = (short)uVar16 + 1;
                uVar16 = (ulonglong)uVar15;
              } while (uVar15 < 0x3c);
              if (uVar15 == 0x3c) {
                bVar5 = SearchTheFreeLogicalVolumn(param_1,bVar21,bVar10);
                uVar16 = CONCAT71(extraout_var,bVar5);
                uVar6 = uVar16 & 0xffff;
                if ((short)uVar16 != 0x3c) {
                  lVar19 = (uVar16 & 0xffff) * 0x100;
                  *(undefined1 *)(lVar19 + 0x3a13 + param_1) = 1;
                  uVar2 = *(undefined1 *)(lVar20 + 0x45);
                  *(undefined4 *)(lVar19 + 0x3918 + param_1) = 0x10390180;
                  *(undefined1 *)(lVar19 + 0x3a16 + param_1) = uVar2;
                  *(undefined4 *)(lVar19 + 0x391c + param_1) = *(undefined4 *)(lVar20 + 0x10);
                  *(byte *)(lVar19 + 0x3920 + param_1) = *(byte *)(lVar20 + 3) >> 4;
                  *(ushort *)(lVar19 + 0x3922 + param_1) = (ushort)(*(byte *)(lVar20 + 3) & 0xf);
                  uVar16 = AHCIGetRaidOrder(lVar20);
                  lVar9 = lVar19 + (uVar16 & 0xff) * 3;
                  *(byte *)(lVar9 + 0x3958 + param_1) = bVar21;
                  *(byte *)(lVar9 + 0x3959 + param_1) = bVar10;
                  *(undefined1 *)(lVar19 + ((uVar16 & 0xff) + 0x131e) * 3 + param_1) = 0x5a;
                  *(undefined2 *)(lVar19 + 0x3a10 + param_1) = 1;
                  if (*(char *)(lVar20 + 0x3e) == '\x01') {
                    *(undefined1 *)(lVar19 + 0x3a14 + param_1) = 1;
                  }
                  bVar5 = *(byte *)(lVar20 + 3) >> 4;
                  if (((bVar5 == 2) || (bVar5 == 4)) || (bVar5 == 5)) {
                    *(undefined4 *)(lVar19 + 0x3a0c + param_1) = *(undefined4 *)(lVar20 + 0xc);
                  }
                }
              }
            }
            else {
              uVar6 = 0;
              if (uVar22 != 0) {
                do {
                  if (((int)*(char *)(uVar6 * 0x100 + 0x3958 + param_1) == (uint)bVar21) &&
                     ((int)*(char *)(uVar6 * 0x100 + 0x3959 + param_1) == (uint)bVar10)) {
                    if ((short)uVar6 != 0xff) goto LAB_00014e6b;
                    break;
                  }
                  uVar15 = (short)uVar6 + 1;
                  uVar6 = (ulonglong)uVar15;
                } while (uVar15 < uVar22);
              }
              bVar5 = SearchTheFreeLogicalVolumn(param_1,bVar21,bVar10);
              uVar6 = CONCAT71(extraout_var_00,bVar5) & 0xffff;
LAB_00014e6b:
              if ((short)uVar6 != 0x3c) {
                lVar9 = uVar6 * 0x100;
                lVar20 = uVar17 * 0xc0 + lVar7;
                *(undefined1 *)(lVar9 + 0x3924 + param_1) = 1;
                *(undefined1 *)(lVar9 + 0x3a15 + param_1) = 0;
                *(undefined1 *)(lVar9 + 0x3a14 + param_1) = 0;
                *(undefined1 *)(lVar9 + 0x3a12 + param_1) = 1;
                *(undefined1 *)(lVar9 + 0x3a13 + param_1) = 1;
                *(undefined1 *)(lVar9 + 0x3920 + param_1) = 0;
                *(undefined2 *)(lVar9 + 0x3922 + param_1) = 1;
                *(undefined8 *)(lVar9 + 0x3928 + param_1) =
                     *(undefined8 *)(lVar20 + 0x2c8 + param_1);
                goto LAB_00014ed9;
              }
            }
          }
          else if (cVar1 == '\x11') {
            uVar15 = 0;
            if (uVar22 != 0) {
              do {
                if (((int)*(char *)((ulonglong)uVar15 * 0x100 + 0x3958 + param_1) == (uint)bVar21)
                   && ((int)*(char *)((ulonglong)uVar15 * 0x100 + 0x3959 + param_1) == (uint)bVar10)
                   ) {
                  uVar6 = (ulonglong)uVar15;
                  if (uVar15 != 0xff) goto LAB_00014f77;
                  break;
                }
                uVar15 = uVar15 + 1;
              } while (uVar15 < uVar22);
            }
            bVar5 = SearchTheFreeLogicalVolumn(param_1,bVar21,bVar10);
            uVar6 = CONCAT71(extraout_var_01,bVar5) & 0xffff;
LAB_00014f77:
            if ((short)uVar6 != 0x3c) {
              lVar9 = uVar6 * 0x100;
              lVar20 = uVar17 * 0xc0 + lVar7;
              *(undefined1 *)(lVar9 + 0x3924 + param_1) = 1;
              *(undefined1 *)(lVar9 + 0x3a15 + param_1) = 0;
              *(undefined1 *)(lVar9 + 0x3a14 + param_1) = 0;
              *(undefined1 *)(lVar9 + 0x3a12 + param_1) = 1;
              *(undefined1 *)(lVar9 + 0x3a13 + param_1) = 1;
              *(undefined1 *)(lVar9 + 0x3920 + param_1) = 0;
              *(undefined2 *)(lVar9 + 0x3922 + param_1) = 1;
              *(undefined8 *)(lVar9 + 0x3928 + param_1) = 0;
LAB_00014ed9:
              memcpy((void *)(lVar9 + 0x3930 + param_1),(void *)(lVar20 + 0x218 + param_1),0x28);
              *(byte *)(lVar9 + 0x3958 + param_1) = bVar21;
              *(byte *)(lVar9 + 0x3959 + param_1) = bVar10;
              *(undefined1 *)(lVar9 + 0x395a + param_1) = 0x5a;
            }
          }
        }
        bVar10 = bVar10 + 1;
      } while (bVar10 < 0xf);
      bVar21 = bVar21 + 1;
    } while (bVar21 < *(byte *)(param_1 + 0x767e));
  }
  local_res18 = 0;
  psVar12 = (short *)(param_1 + 0x3a10);
  do {
    if ((*(int *)(psVar12 + -0x7c) == 0x10390180) && (cVar1 = (char)psVar12[-0x78], cVar1 != '\0'))
    {
      if (*psVar12 == psVar12[-0x77]) {
        bVar21 = *(byte *)(psVar12 + -0x5c);
        pbVar8 = (byte *)((longlong)psVar12 + -0xb7);
        bVar10 = *pbVar8;
        *(undefined1 *)(psVar12 + -0x76) = 1;
        *(undefined1 *)((longlong)psVar12 + 5) = 0;
        AHCIAdjustDiskSize(param_1,local_res18);
        bVar5 = 0;
        bVar4 = false;
        if (((char)psVar12[-0x78] != '\0') && (psVar12[-0x77] != 0)) {
          uVar17 = (ulonglong)(ushort)psVar12[-0x77];
          pbVar14 = pbVar8;
          uVar16 = uVar17;
          do {
            uVar18 = uVar16;
            bVar3 = *(byte *)((ulonglong)*pbVar14 * 0xc0 + 0x2d3 +
                             param_1 + (ulonglong)pbVar14[-1] * 0xe28);
            if (bVar3 != 0) {
              if (!bVar4) {
                bVar4 = true;
                bVar5 = bVar3;
              }
              if (bVar3 < bVar5) {
                bVar5 = bVar3;
              }
            }
            pbVar14 = pbVar14 + 3;
            uVar16 = uVar18 - 1;
          } while (uVar16 != 0);
          do {
            lVar7 = param_1 + (ulonglong)pbVar8[-1] * 0xe28;
            if (*(char *)((ulonglong)*pbVar8 * 0xc0 + 0x2d3 + lVar7) != '\0') {
              *(byte *)((ulonglong)*pbVar8 * 0xc0 + 0x2d3 + lVar7) = bVar5;
            }
            pbVar8 = pbVar8 + 3;
            uVar17 = uVar17 - (uVar18 & 0xffffffff);
          } while (uVar17 != 0);
        }
        if ((char)psVar12[1] != '\x01') {
          lVar7 = (ulonglong)bVar21 * 0xe28 + param_1 + ((ulonglong)bVar10 * 3 + 9) * 0x40;
          if (*(char *)(lVar7 + 0x14) == '\0') {
            cVar1 = (char)psVar12[-0x78];
            if (cVar1 == '\x01') {
              memcpy((void *)(uVar6 * 0x100 + 0x3930 + param_1),&s_SiSJBOD_SET,0xb);
              *(byte *)(uVar6 * 0x100 + 0x393b + param_1) = (*(byte *)(lVar7 + 0x45) & 0xf) + 0x30;
            }
            else {
              if (cVar1 == '\x02') {
                puVar11 = &s_SiSRAID0_SET;
                lVar20 = uVar6 << 8;
              }
              else {
                if (cVar1 != '\x03') {
                  if (cVar1 == '\x04') {
                    lVar20 = uVar6 * 0x100;
                    *(undefined1 *)(lVar20 + 0x3a12 + param_1) = 1;
                    memcpy((void *)(lVar20 + 0x3930 + param_1),&s_SiSRAID0_1_SET,0xe);
                    *(byte *)(lVar20 + 0x393e + param_1) = (*(byte *)(lVar7 + 0x45) & 0xf) + 0x30;
                  }
                  else if (cVar1 == '\x05') {
                    puVar11 = &s_SiSRAID5_SET;
                    goto LAB_00015051;
                  }
                  goto LAB_00015154;
                }
                puVar11 = &s_SiSRAID1_SET;
LAB_00015051:
                lVar20 = uVar6 * 0x100;
                *(undefined1 *)(lVar20 + 0x3a12 + param_1) = 1;
              }
              memcpy((void *)(lVar20 + 0x3930 + param_1),puVar11,0xc);
              *(byte *)(lVar20 + 0x393c + param_1) = (*(byte *)(lVar7 + 0x45) & 0xf) + 0x30;
            }
          }
          else {
            pbVar8 = (byte *)(psVar12 + -0x70);
            memcpy(pbVar8,(char *)(lVar7 + 0x14),0x28);
            lVar7 = 0x28;
            do {
              bVar21 = *pbVar8;
              if (((bVar21 < 0x20) || (0x7e < bVar21)) && (bVar21 != 0)) {
                *pbVar8 = 0x20;
              }
              pbVar8 = pbVar8 + 1;
              lVar7 = lVar7 + -1;
            } while (lVar7 != 0);
            if (((char)psVar12[-0x78] == '\x03') || ((char)psVar12[-0x78] == '\x04')) {
              *(undefined1 *)(psVar12 + 1) = 1;
            }
          }
        }
      }
      else {
        *(undefined1 *)(psVar12 + 2) = 0;
        if (cVar1 == '\x03') {
          AHCIProcessBorkenMirrorSet(param_1,local_res18);
        }
        else if (cVar1 == '\x04') {
          AHCIProcessBorkenStripedMirrorSet(param_1,local_res18);
        }
        else {
          AHCIProcessBrokenJBOD_StripedSet(param_1,local_res18);
        }
      }
    }
LAB_00015154:
    local_res18 = local_res18 + 1;
    psVar12 = psVar12 + 0x80;
    if (0x3b < local_res18) {
      return;
    }
  } while( true );
}



===== AHCIResetController @ 0001518c =====

undefined8
AHCIResetController(longlong param_1,undefined1 param_2,undefined8 param_3,undefined8 param_4)

{
  byte *pbVar1;
  bool bVar2;
  longlong lVar3;
  undefined8 uVar4;
  longlong lVar5;
  char cVar6;
  undefined1 *puVar7;
  ulonglong uVar8;
  char *pcVar9;
  byte bVar10;
  uint uVar11;
  char cVar12;
  char cVar13;
  char *pcVar14;
  ulonglong uVar15;
  longlong lVar16;
  char cVar17;
  char local_res18 [16];
  char acStackY_68 [16];
  
  pcVar14 = "AHCIResetController";
  puVar7 = &s__s_;
  cVar12 = '\0';
  bVar2 = false;
  StorPortDebugPrint(0,&s__s_,"AHCIResetController");
  uVar15 = CONCAT71((int7)((ulonglong)param_4 >> 8),0xff);
  uVar8 = CONCAT71((int7)((ulonglong)puVar7 >> 8),param_2);
  pcVar14 = (char *)CONCAT71((int7)((ulonglong)pcVar14 >> 8),0xff);
  StorPortCompleteRequest(param_1);
  if (*(char *)(param_1 + 0x7680) != '\x01') {
    cVar17 = '\0';
    if (*(char *)(param_1 + 0x767e) == '\0') goto LAB_00015564;
    cVar6 = *(char *)(param_1 + 0x767d);
    bVar10 = *(byte *)(param_1 + 0x767e);
    do {
      lVar16 = (longlong)cVar17;
      pcVar14 = local_res18 + lVar16;
      lVar3 = lVar16 * 0xe28;
      *pcVar14 = '\0';
      lVar5 = *(longlong *)(lVar3 + 0x58 + param_1);
      if ((*(char *)(lVar5 + 0x20) != 'P') && (*(char *)(lVar5 + 0x20) != '\x7f')) {
        *pcVar14 = '\x01';
        bVar2 = true;
      }
      if ((*(int *)(lVar5 + 0x38) != 0) || (*(int *)(lVar5 + 0x34) != 0)) {
        *pcVar14 = '\x01';
      }
      if ((*(int *)(lVar3 + 0xe60 + param_1) != 0) || (*(int *)(lVar3 + 0xe64 + param_1) != 0)) {
        *pcVar14 = '\x01';
        bVar2 = true;
      }
      cVar13 = '\0';
      if (cVar6 != '\0') {
        do {
          if (*(longlong *)(param_1 + 0xd60 + ((longlong)cVar13 + lVar16 * 0x1c5) * 8) != 0) {
            *pcVar14 = '\x01';
            bVar2 = true;
            break;
          }
          cVar13 = cVar13 + '\x01';
        } while ((int)cVar13 < (int)(uint)*(byte *)(param_1 + 0x767d));
      }
      cVar17 = cVar17 + '\x01';
    } while ((int)cVar17 < (int)(uint)bVar10);
    if (!bVar2) goto LAB_00015564;
    cVar17 = '\0';
    do {
      if ((*(byte *)((longlong)cVar17 * 0xe28 + 0xd58 + param_1) & 4) == 0) {
        local_res18[cVar17] = '\x01';
      }
      cVar17 = cVar17 + '\x01';
    } while ((int)cVar17 < (int)(uint)bVar10);
    uVar15 = (ulonglong)*(uint *)(param_1 + 0x7650);
    pcVar14 = (char *)(ulonglong)*(uint *)(param_1 + 0x764c);
    uVar8 = 4;
    StorPortSetBusDataByOffset(param_1);
    lVar5 = 0x3c;
    **(byte **)(param_1 + 0x18) = **(byte **)(param_1 + 0x18) & 0xfd;
    puVar7 = (undefined1 *)(param_1 + 0x3924);
    do {
      *puVar7 = 0;
      puVar7 = puVar7 + 0x100;
      lVar5 = lVar5 + -1;
    } while (lVar5 != 0);
    cVar17 = '\0';
    if (*(char *)(param_1 + 0x767e) != '\0') {
      do {
        pcVar14 = "AHCIResetController";
        lVar3 = (longlong)cVar17 * 0xe28;
        lVar5 = *(longlong *)(lVar3 + 0x58 + param_1);
        pbVar1 = (byte *)(lVar3 + 0xd58 + param_1);
        *pbVar1 = *pbVar1 & 0xbf;
        uVar15 = (ulonglong)*(byte *)(lVar3 + 0xe6c + param_1);
        pcVar9 = 
        "[FUNCTION] %s :NCQDepth %d NonNCQDepth %d CI %lx SACT %lx  HoldingCI %lx PxCI %lx PxSACT %lx\n"
        ;
        StorPortDebugPrint(0,
                           "[FUNCTION] %s :NCQDepth %d NonNCQDepth %d CI %lx SACT %lx  HoldingCI %lx PxCI %lx PxSACT %lx\n"
                           ,"AHCIResetController",uVar15,*(undefined1 *)(lVar3 + 0xe6d + param_1),
                           *(undefined4 *)(lVar3 + 0xe60 + param_1),
                           *(undefined4 *)(lVar3 + 0xe64 + param_1),
                           *(undefined4 *)(lVar3 + 0xe68 + param_1),*(undefined4 *)(lVar5 + 0x38),
                           *(undefined4 *)(lVar5 + 0x34));
        *(undefined8 *)(lVar3 + 0x1fa + param_1) = 0;
        *(undefined4 *)(lVar3 + 0x202 + param_1) = 0;
        *(undefined2 *)(lVar3 + 0x206 + param_1) = 0;
        *(undefined1 *)(lVar3 + 0x208 + param_1) = 0;
        uVar8 = (ulonglong)pcVar9 & 0xffffffffffffff00;
        if (*(char *)(param_1 + 0x767d) != '\0') {
          do {
            cVar6 = (char)uVar8;
            cVar13 = cVar6 + '\x01';
            uVar8 = CONCAT71((int7)(uVar8 >> 8),cVar13);
            *(undefined8 *)(param_1 + 0xd60 + ((longlong)cVar6 + (longlong)cVar17 * 0x1c5) * 8) = 0;
          } while ((int)cVar13 < (int)(uint)*(byte *)(param_1 + 0x767d));
        }
      } while ((*(char *)(lVar3 + 0xe6f + param_1) == '\0') &&
              (cVar17 = cVar17 + '\x01', (int)cVar17 < (int)(uint)*(byte *)(param_1 + 0x767e)));
    }
    cVar17 = '\0';
    if (*(char *)(param_1 + 0x767e) != '\0') {
      do {
        lVar5 = 10;
        *(undefined4 *)(*(longlong *)((longlong)cVar17 * 0xe28 + 0x58 + param_1) + 0x18) = 0;
        do {
          StorPortStallExecution(500);
          lVar5 = lVar5 + -1;
        } while (lVar5 != 0);
        cVar17 = cVar17 + '\x01';
      } while ((int)cVar17 < (int)(uint)*(byte *)(param_1 + 0x767e));
    }
    uVar11 = 0;
    **(byte **)(param_1 + 0x18) = **(byte **)(param_1 + 0x18) | 1;
    bVar10 = **(byte **)(param_1 + 0x18);
    while ((bVar10 & 1) != 0) {
      if (3999 < uVar11) {
        uVar8 = StorPortDebugPrint(0,&s__FUNCTION___s__The_AHCI_has_hung,"AHCIResetController");
        return uVar8 & 0xffffffffffffff00;
      }
      uVar11 = uVar11 + 1;
      StorPortStallExecution();
      bVar10 = **(byte **)(param_1 + 0x18);
    }
    pbVar1 = (byte *)(*(longlong *)(param_1 + 0x18) + 3);
    *pbVar1 = *pbVar1 | 0x80;
  }
  AHCIInitialHBADevice(param_1,uVar8,pcVar14,uVar15);
  if ((*(char *)(param_1 + 0x767f) != '\0') && (bVar10 = 0, *(char *)(param_1 + 0x767e) != '\0')) {
    do {
      uVar8 = CONCAT71((int7)(uVar8 >> 8),bVar10);
      AHCIGetRaidInfo(param_1,bVar10);
      bVar10 = bVar10 + 1;
    } while ((int)(char)bVar10 < (int)(uint)*(byte *)(param_1 + 0x767e));
  }
  AHCICheckRaidInfo(param_1);
  AHCIHwinitialize(param_1,uVar8,pcVar14,uVar15);
  if (*(char *)(param_1 + 0x767e) != '\0') {
    do {
      if (local_res18[cVar12] == '\x01') {
        lVar5 = (longlong)cVar12 * 0xe28;
        bVar10 = *(byte *)(lVar5 + 0xd58 + param_1);
        if ((bVar10 & 4) != 0) {
          pbVar1 = (byte *)(lVar5 + 0xe78 + param_1);
          *pbVar1 = *pbVar1 & 0xc3;
          *(byte *)(lVar5 + 0xd58 + param_1) = bVar10 & 0xfb;
        }
      }
      cVar12 = cVar12 + '\x01';
    } while ((int)cVar12 < (int)(uint)*(byte *)(param_1 + 0x767e));
  }
  *(undefined1 *)(param_1 + 0x7686) = 1;
  StorPortNotification(7,param_1);
LAB_00015564:
  uVar4 = StorPortNotification(1,param_1,0);
  return CONCAT71((int7)((ulonglong)uVar4 >> 8),1);
}



===== AHCIPassiveInitialziation @ 000155a8 =====

undefined1 AHCIPassiveInitialziation(longlong param_1)

{
  StorPortNotification(0x1001,param_1,param_1 + 0x7768,AHCIEnableInterruptsCallback);
  StorPortNotification(0x1001,param_1,param_1 + 0x77b0,AHCIDisableInterruptsCallback);
  return 1;
}



===== AHCIHwinitialize @ 000155f8 =====

undefined8
AHCIHwinitialize(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  uint *puVar1;
  byte *pbVar2;
  char cVar3;
  longlong lVar4;
  undefined8 uVar5;
  byte bVar6;
  byte bVar7;
  longlong lVar8;
  uint local_res8 [2];
  
  local_res8[0] = 0xffffffff;
  bVar7 = 0;
  if (*(char *)(param_1 + 0x767e) != '\0') {
    do {
      lVar8 = (ulonglong)bVar7 * 0xe28;
      if ((*(byte *)(lVar8 + 0xd58 + param_1) & 0x20) != 0) {
        bVar6 = 0;
        if (*(char *)(lVar8 + 0xd59 + param_1) != '\0') {
          do {
            cVar3 = *(char *)((ulonglong)bVar6 + lVar8 + 0x1fa + param_1);
            if ((cVar3 != '\x01') && (cVar3 != '\x11')) break;
            param_4 = CONCAT71((int7)((ulonglong)param_4 >> 8),0xf);
            AHCIPMReadWrite(param_1,bVar7,bVar6,param_4,-0x18,1,local_res8);
            bVar6 = bVar6 + 1;
          } while (bVar6 < *(byte *)(lVar8 + 0xd59 + param_1));
        }
        *(undefined4 *)(*(longlong *)(lVar8 + 0x58 + param_1) + 0x3c) = 0xffffffff;
      }
      *(undefined4 *)(*(longlong *)(lVar8 + 0x58 + param_1) + 0x30) = 0xffffffff;
      *(undefined4 *)(*(longlong *)(lVar8 + 0x58 + param_1) + 0x10) = 0xffffffff;
      lVar4 = *(longlong *)(lVar8 + 0x58 + param_1);
      if ((*(byte *)(lVar8 + 0xd58 + param_1) & 4) == 0) {
        *(undefined4 *)(lVar4 + 0x14) = 0x78c000cb;
      }
      else {
        *(undefined4 *)(lVar4 + 0x14) = 0x788000cb;
      }
      if ((*(byte *)(lVar8 + 0xe78 + param_1) & 0x80) != 0) {
        puVar1 = (uint *)(*(longlong *)(lVar8 + 0x58 + param_1) + 0x14);
        *puVar1 = *puVar1 & 0xfffffff0;
      }
      if ((*(char *)(param_1 + 0x768f) != '\0') &&
         ((*(byte *)(lVar8 + 0xd58 + param_1) & 0x20) != 0)) {
        puVar1 = (uint *)(*(longlong *)(lVar8 + 0x58 + param_1) + 0x14);
        *puVar1 = *puVar1 | 8;
      }
      pbVar2 = (byte *)(*(longlong *)(lVar8 + 0x58 + param_1) + 0x1b);
      *pbVar2 = *pbVar2 & 0xf7;
      pbVar2 = (byte *)(*(longlong *)(lVar8 + 0x58 + param_1) + 0x1b);
      *pbVar2 = *pbVar2 & 0xfb;
      *(undefined1 *)(param_1 + 0x7678) = 0;
      *(undefined4 *)(lVar8 + 0xe68 + param_1) = 0;
      *(undefined4 *)(lVar8 + 0xe60 + param_1) = 0;
      *(undefined4 *)(lVar8 + 0xe64 + param_1) = 0;
      *(undefined1 *)(lVar8 + 0xd5a + param_1) = 0;
      *(undefined1 *)(lVar8 + 0xe6e + param_1) = 0;
      *(undefined1 *)(lVar8 + 0xe6f + param_1) = 0;
      *(undefined1 *)(lVar8 + 0xe72 + param_1) = 0;
      *(undefined1 *)(lVar8 + 0xe71 + param_1) = 0;
      *(undefined1 *)(lVar8 + 0xe73 + param_1) = 0;
      *(undefined1 *)(lVar8 + 0xe74 + param_1) = 0;
      *(undefined1 *)(lVar8 + 0xe75 + param_1) = 0;
      pbVar2 = (byte *)(*(longlong *)(lVar8 + 0x58 + param_1) + 0x18);
      *pbVar2 = *pbVar2 | 0x10;
      pbVar2 = (byte *)(lVar8 + 0xd58 + param_1);
      *pbVar2 = *pbVar2 & 0xfe;
      bVar6 = *(byte *)(lVar8 + 0xd58 + param_1);
      if ((bVar6 & 0x20) == 0) {
        *(byte *)(lVar8 + 0xd58 + param_1) =
             (*(byte *)(lVar8 + 0x2c1 + param_1) >> 6 ^ bVar6) & 1 ^ bVar6;
      }
      pbVar2 = (byte *)(lVar8 + 0xe78 + param_1);
      *pbVar2 = *pbVar2 & 0xfc;
      bVar7 = bVar7 + 1;
    } while (bVar7 < *(byte *)(param_1 + 0x767e));
  }
  if (*(int *)(param_1 + 0x7760) != 0x10391184) {
    *(undefined4 *)(param_1 + 0x7760) = 0x10391184;
    local_res8[0] = 0;
    StorPortNotification(0x1000,param_1,AHCIPassiveInitialziation,local_res8);
  }
  *(undefined1 *)(param_1 + 0x7679) = 0;
  *(undefined1 *)(param_1 + 0x7685) = 0;
  *(undefined1 *)(param_1 + 0x7676) = 0;
  *(undefined1 *)(param_1 + 0x7677) = 1;
  *(undefined4 *)(param_1 + 0x765c) = 0;
  **(undefined4 **)(param_1 + 0x20) = 0xffffffff;
  **(byte **)(param_1 + 0x18) = **(byte **)(param_1 + 0x18) | 2;
  if ((*(char *)(param_1 + 0x768e) != '\0') && (*(int *)(param_1 + 0x7690) != 0)) {
    **(undefined4 **)(param_1 + 0x40) = **(undefined4 **)(param_1 + 0x28);
    *(int *)(param_1 + 0x7660) = 1 << (**(byte **)(param_1 + 0x38) >> 3);
    (*(byte **)(param_1 + 0x38))[1] = 5;
    *(undefined2 *)(*(longlong *)(param_1 + 0x38) + 2) = 500;
    **(byte **)(param_1 + 0x38) = **(byte **)(param_1 + 0x38) & 0xfe;
    **(byte **)(param_1 + 0x38) = **(byte **)(param_1 + 0x38) | 1;
  }
  local_res8[0] = CONCAT31(local_res8[0]._1_3_,*(undefined1 *)(param_1 + 0x7551)) & 0xfffffffb;
  *(undefined1 *)(param_1 + 0x7681) = 1;
  uVar5 = StorPortSetBusDataByOffset
                    (param_1,4,*(undefined4 *)(param_1 + 0x764c),*(undefined4 *)(param_1 + 0x7650),
                     local_res8,5,1);
  return CONCAT71((int7)((ulonglong)uVar5 >> 8),1);
}



===== AHCISpinUpDevice @ 000158e4 =====

ulonglong AHCISpinUpDevice(longlong param_1,byte param_2)

{
  byte *pbVar1;
  bool bVar2;
  undefined8 uVar3;
  byte bVar4;
  char *pcVar5;
  uint uVar6;
  ulonglong uVar7;
  uint uVar8;
  longlong lVar9;
  longlong lVar10;
  longlong lVar11;
  
  uVar8 = 0;
  bVar2 = false;
  uVar6 = 0;
  lVar9 = (ulonglong)param_2 * 0xe28;
  *(undefined4 *)(*(longlong *)(lVar9 + 0x58 + param_1) + 0x30) = 0xffffffff;
  *(undefined4 *)(*(longlong *)(lVar9 + 0x58 + param_1) + 0x10) = 0xffffffff;
  do {
    if ((*(byte *)(*(longlong *)(lVar9 + 0x58 + param_1) + 0x28) & 0xf) != 0) {
      bVar2 = true;
      break;
    }
    lVar10 = 10;
    do {
      StorPortStallExecution(500);
      lVar10 = lVar10 + -1;
    } while (lVar10 != 0);
    uVar6 = uVar6 + 1;
  } while (uVar6 < 4);
  StorPortDebugPrint(0,"[FUNCTION] %s :Port %d Link status  DET %x\n","AHCISpinUpDevice",
                     (ulonglong)param_2,
                     *(byte *)(*(longlong *)(lVar9 + 0x58 + param_1) + 0x28) & 0xf);
  *(undefined4 *)(*(longlong *)(lVar9 + 0x58 + param_1) + 0x18) = 0x10;
  if (*(char *)(param_1 + 0x7843) == '\0') {
LAB_000159ba:
    if (*(char *)(param_1 + 0x768c) != '\0') {
LAB_000159c3:
      pbVar1 = (byte *)(*(longlong *)(lVar9 + 0x58 + param_1) + 0x18);
      *pbVar1 = *pbVar1 & 0xfd;
      lVar10 = 10;
      do {
        lVar11 = lVar10;
        StorPortStallExecution(500);
        lVar10 = lVar11 + -1;
      } while (lVar10 != 0);
      uVar7 = (ulonglong)((int)lVar11 + 0x13);
      pbVar1 = (byte *)(*(longlong *)(lVar9 + 0x58 + param_1) + 0x18);
      *pbVar1 = *pbVar1 | 2;
      do {
        StorPortStallExecution(500);
        uVar7 = uVar7 - 1;
      } while (uVar7 != 0);
    }
    *(undefined4 *)(*(longlong *)(lVar9 + 0x58 + param_1) + 0x30) = 0xffffffff;
    *(undefined4 *)(*(longlong *)(lVar9 + 0x58 + param_1) + 0x10) = 0xffffffff;
    *(undefined1 *)(param_1 + 0x767b) = 0;
  }
  else {
    if (*(char *)(param_1 + 0x768c) != '\0') goto LAB_000159c3;
    if ((*(byte *)(*(longlong *)(lVar9 + 0x58 + param_1) + 0x28) & 0xf) != 3) goto LAB_000159ba;
  }
  uVar6 = 0;
  do {
    bVar4 = *(byte *)(*(longlong *)(lVar9 + 0x58 + param_1) + 0x28) & 0xf;
    if (bVar4 == 3) goto LAB_00015a9e;
    if ((bVar4 == 0) && (!bVar2)) break;
    uVar6 = uVar6 + 1;
    lVar10 = 200;
    do {
      StorPortStallExecution(500);
      lVar10 = lVar10 + -1;
    } while (lVar10 != 0);
  } while (uVar6 < 500);
  pcVar5 = "1.[FUNCTION] %s :Link Failed, Close Port %d DET %x\n";
  if (bVar2) {
    pcVar5 = "2.[FUNCTION] %s :Link Failed, Close Port %d DET %x\n";
  }
  uVar7 = StorPortDebugPrint(0,pcVar5,"AHCISpinUpDevice",param_2,
                             *(byte *)(*(longlong *)(lVar9 + 0x58 + param_1) + 0x28) & 0xf);
  pbVar1 = (byte *)(lVar9 + 0xd58 + param_1);
  *pbVar1 = *pbVar1 | 0x40;
  *(undefined1 *)(lVar9 + 0x1fa + param_1) = 0x5a;
LAB_00015b8d:
  return uVar7 & 0xffffffffffffff00;
LAB_00015a9e:
  lVar10 = *(longlong *)(lVar9 + 0x58 + param_1);
  if ((((*(byte *)(lVar10 + 0x20) & 0x80) == 0) && ((*(byte *)(lVar10 + 0x20) & 8) == 0)) &&
     ((*(byte *)(lVar10 + 0x20) & 1) == 0)) {
    *(undefined4 *)(lVar10 + 0x30) = 0xffffffff;
    *(undefined4 *)(*(longlong *)(lVar9 + 0x58 + param_1) + 0x10) = 0xffffffff;
    pbVar1 = (byte *)(*(longlong *)(lVar9 + 0x58 + param_1) + 0x18);
    *pbVar1 = *pbVar1 | 1;
    uVar3 = StorPortDebugPrint(0,"[FUNCTION] %s :Port %d Link status  DET %x successful\n",
                               "AHCISpinUpDevice",param_2,
                               *(byte *)(*(longlong *)(lVar9 + 0x58 + param_1) + 0x28) & 0xf);
    return CONCAT71((int7)((ulonglong)uVar3 >> 8),1);
  }
  StorPortStallExecution(500);
  lVar10 = *(longlong *)(lVar9 + 0x58 + param_1);
  uVar8 = uVar8 + 1;
  if ((*(byte *)(lVar10 + 0x28) & 0xf) == 0) {
    uVar7 = StorPortDebugPrint(0,"[FUNCTION] %s : The Device is plug out at port %d suddenlfy.\n",
                               "AHCISpinUpDevice",param_2);
    goto LAB_00015b8d;
  }
  if (59999 < uVar8) goto LAB_00015b25;
  *(undefined4 *)(lVar10 + 0x30) = 0xffffffff;
  *(undefined4 *)(*(longlong *)(lVar9 + 0x58 + param_1) + 0x10) = 0xffffffff;
  goto LAB_00015a9e;
LAB_00015b25:
  bVar4 = *(byte *)(lVar10 + 0x20);
  StorPortDebugPrint(0,"[FUNCTION] %s :Device is not ready:BSY %x DRQ %x ERR %x Error %x\n",
                     "AHCISpinUpDevice",bVar4 >> 7,bVar4 >> 3 & 1,bVar4 & 1,
                     *(undefined1 *)(lVar10 + 0x21));
  *(undefined4 *)(*(longlong *)(lVar9 + 0x58 + param_1) + 0x30) = 0xffffffff;
  uVar7 = *(ulonglong *)(lVar9 + 0x58 + param_1);
  *(undefined4 *)(uVar7 + 0x10) = 0xffffffff;
  goto LAB_00015b8d;
}



===== AHCIRecoverPMFromLastError @ 00015bb4 =====

ulonglong AHCIRecoverPMFromLastError(longlong param_1,byte param_2)

{
  byte *pbVar1;
  longlong lVar2;
  undefined8 in_RAX;
  ulonglong uVar3;
  longlong lVar4;
  
  lVar4 = (ulonglong)param_2 * 0xe28;
  lVar2 = *(longlong *)(lVar4 + 0x58 + param_1);
  uVar3 = CONCAT71((int7)((ulonglong)in_RAX >> 8),*(undefined1 *)(lVar2 + 0x28)) &
          0xffffffffffffff0f;
  if ((char)uVar3 == '\x03') {
    uVar3 = CONCAT71((int7)(uVar3 >> 8),1);
  }
  else {
    StorPortDebugPrint(0,
                       "[FUNCTION] %s :Can\'t recover from the error,PxIS %lx, PxSERR %lx ,PxSSTS.DET %x\n"
                       ,"AHCIRecoverPMFromLastError",*(undefined4 *)(lVar2 + 0x10),
                       *(undefined4 *)(lVar2 + 0x30),*(byte *)(lVar2 + 0x28) & 0xf);
    pbVar1 = (byte *)(lVar4 + 0xd58 + param_1);
    *pbVar1 = *pbVar1 & 0xdf;
    pbVar1 = (byte *)(*(longlong *)(lVar4 + 0x58 + param_1) + 0x1a);
    *pbVar1 = *pbVar1 & 0xfd;
    *(undefined2 *)(lVar4 + 0x1f8 + param_1) = 0;
    *(undefined1 *)(lVar4 + 0x1fa + param_1) = 0;
    uVar3 = *(ulonglong *)(lVar4 + 0x58 + param_1);
    if ((*(byte *)(uVar3 + 0x28) & 0xf) == 1) {
      *(undefined1 *)(lVar4 + 0x1fa + param_1) = 0x5a;
    }
    uVar3 = uVar3 & 0xffffffffffffff00;
  }
  return uVar3;
}



===== AHCIDetectSinglePMDevice @ 00015c58 =====

ulonglong AHCIDetectSinglePMDevice(longlong param_1,byte param_2,byte param_3,undefined8 param_4)

{
  longlong lVar1;
  short *psVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  
  lVar1 = (ulonglong)param_2 * 0xe28 + (ulonglong)param_3;
  *(undefined1 *)(lVar1 + 0x1fa + param_1) = 0;
  uVar3 = AHCIPMHardReset(param_1,param_2,param_3,param_4);
  if ((char)uVar3 == '\x01') {
    uVar4 = AHCIPMDeviceReset(param_1,param_2,param_3,(byte)param_4);
    if ((char)uVar4 != '\0') {
      if (*(char *)(lVar1 + 0x1fa + param_1) == '\x11') {
        *(undefined1 *)(lVar1 + 0x1fa + param_1) = 0x5a;
        goto LAB_00015cce;
      }
      uVar4 = AHCIIssueIdentify(param_1,param_2,param_3);
      if (((char)uVar4 == '\x01') &&
         (uVar4 = AHCISetDeviceParameter(param_1,param_2,param_3), (char)uVar4 == '\x01')) {
        psVar2 = (short *)((ulonglong)param_2 * 0xe28 + 0x1f8 + param_1);
        *psVar2 = *psVar2 + 1;
        *(short *)(param_1 + 0x7518) = *(short *)(param_1 + 0x7518) + 1;
        uVar4 = StorPortLogError(param_1,0,0,param_2,0,0xc,0);
        goto LAB_00015d3c;
      }
    }
    *(undefined1 *)(lVar1 + 0x1fa + param_1) = 0x5a;
  }
  uVar4 = AHCIRecoverPMFromLastError(param_1,param_2);
  if ((char)uVar4 != '\0') {
LAB_00015d3c:
    return CONCAT71((int7)(uVar4 >> 8),1);
  }
LAB_00015cce:
  return uVar4 & 0xffffffffffffff00;
}



===== AHCIDetectDevice @ 00015d60 =====

ulonglong AHCIDetectDevice(longlong param_1,byte param_2,undefined8 param_3,undefined8 param_4)

{
  byte *pbVar1;
  short *psVar2;
  char cVar3;
  uint uVar4;
  void *pvVar5;
  void *extraout_RAX;
  undefined8 uVar6;
  ulonglong uVar7;
  uint uVar8;
  ulonglong uVar9;
  longlong lVar10;
  byte bVar11;
  undefined7 uVar12;
  byte bVar13;
  byte bVar14;
  longlong lVar15;
  uint local_res8 [2];
  byte local_res10;
  uint local_res20 [2];
  
  uVar12 = (undefined7)((ulonglong)param_4 >> 8);
  lVar10 = (ulonglong)param_2 * 0xe28;
  pbVar1 = (byte *)(lVar10 + 0xd58 + param_1);
  *pbVar1 = *pbVar1 & 0xdf;
  pvVar5 = (void *)AHCIDeviceReset(param_1,param_2,0xf);
  uVar9 = 0;
  if (((char)pvVar5 != '\0') ||
     (pvVar5 = (void *)AHCIDeviceReset(param_1,param_2,0), (char)pvVar5 != '\0')) {
    bVar11 = *(byte *)(lVar10 + 0xd58 + param_1);
    pvVar5 = (void *)CONCAT71((int7)((ulonglong)pvVar5 >> 8),bVar11);
    if ((bVar11 & 0x20) != 0) {
      pbVar1 = (byte *)(*(longlong *)(lVar10 + 0x58 + param_1) + 0x1a);
      *pbVar1 = *pbVar1 | 2;
      local_res8[0] = 0;
      pbVar1 = (byte *)(lVar10 + 0xd58 + param_1);
      *pbVar1 = *pbVar1 ^ (*(char *)(param_1 + 0x768b) << 2 ^ *(byte *)(lVar10 + 0xd58 + param_1)) &
                          4;
      *(byte *)((ulonglong)*(byte *)(param_1 + 0x767a) + 0x7670 + param_1) = param_2;
      *(char *)(param_1 + 0x767a) = *(char *)(param_1 + 0x767a) + '\x01';
      AHCIPMReadWrite(param_1,param_2,0xf,CONCAT71(uVar12,0xf),-0x1c,2,local_res8);
      uVar8 = local_res8[0] & 0xf;
      uVar4 = local_res8[0] & 0xf;
      bVar14 = (byte)local_res8[0] & 0xf;
      *(byte *)(lVar10 + 0xd59 + param_1) = bVar14;
      local_res8[0] = 0x4010000;
      local_res10 = bVar14;
      AHCIPMReadWrite(param_1,param_2,0xf,CONCAT71(uVar12,0xf),-0x18,0x21,local_res8);
      local_res8[0] = 0;
      AHCIPMReadWrite(param_1,param_2,0xf,CONCAT71(uVar12,0xf),-0x1c,1,local_res8);
      *(byte *)(lVar10 + 0xe79 + param_1) = (byte)local_res8[0] & 0xf;
      local_res8[0] = 0;
      AHCIPMReadWrite(param_1,param_2,0xf,CONCAT71(uVar12,0xf),-0x1c,0x40,local_res8);
      pbVar1 = (byte *)(lVar10 + 0xe7a + param_1);
      *pbVar1 = *pbVar1 & 7;
      bVar13 = (byte)local_res8[0];
      bVar11 = (((bVar13 & 2) << 2 | bVar13 & 4) << 2 | bVar13 & 8) * '\x02';
      *(byte *)(lVar10 + 0xe7a + param_1) =
           bVar11 | bVar13 << 7 | *(byte *)(lVar10 + 0xe7a + param_1) & 0x87 | bVar13 >> 1 & 8;
      if ((bVar11 & 0x10) != 0) {
        local_res8[0] = 0;
        AHCIPMReadWrite(param_1,param_2,0xf,CONCAT71(uVar12,0xf),-0x1c,0x60,local_res8);
        local_res8[0] = local_res8[0] | 8;
        AHCIPMReadWrite(param_1,param_2,0xf,CONCAT71(uVar12,0xf),-0x18,0x60,local_res8);
      }
      local_res8[0] = 0;
      AHCIPMReadWrite(param_1,param_2,0xf,CONCAT71(uVar12,0xf),-0x1c,0x60,local_res8);
      bVar11 = 0xf;
      local_res20[0] = 0;
      *(byte *)(lVar10 + 0xe7a + param_1) =
           *(byte *)(lVar10 + 0xe7a + param_1) & 7 | (byte)local_res8[0] << 7;
      AHCIPMReadWrite(param_1,param_2,0xf,CONCAT71(uVar12,0xf),-0x1c,0x20,local_res20);
      if ((char)extraout_RAX != '\0') {
        local_res8[0] = 0xffffffff;
        uVar7 = 0;
        if (*(char *)(lVar10 + 0xd59 + param_1) != '\0') {
          do {
            cVar3 = *(char *)(uVar7 + lVar10 + 0x1fa + param_1);
            if ((cVar3 != '\x01') && (cVar3 != '\x11')) break;
            bVar11 = 0xf;
            AHCIPMReadWrite(param_1,param_2,(byte)uVar7,CONCAT71(uVar12,0xf),-0x18,1,local_res8);
            bVar13 = (byte)uVar7 + 1;
            uVar7 = (ulonglong)bVar13;
          } while (bVar13 < *(byte *)(lVar10 + 0xd59 + param_1));
        }
        bVar13 = 0;
        *(undefined4 *)(*(longlong *)(lVar10 + 0x58 + param_1) + 0x3c) = 0xffffffff;
        if (uVar4 != 0) {
          uVar8 = local_res20[0];
          do {
            lVar15 = (ulonglong)bVar13 + lVar10;
            *(undefined1 *)(lVar15 + 0x1fa + param_1) = 0;
            if ((uVar8 >> (bVar13 & 0x1f) & 1) != 0) {
              uVar6 = AHCIPMHardReset(param_1,param_2,bVar13,CONCAT71(uVar12,bVar11));
              if ((char)uVar6 == '\x01') {
                bVar11 = bVar13;
                uVar7 = AHCIPMDeviceReset(param_1,param_2,bVar13,bVar13);
                if ((char)uVar7 == '\0') {
LAB_00016105:
                  *(undefined1 *)(lVar15 + 0x1fa + param_1) = 0x5a;
                  goto LAB_0001610e;
                }
                if (*(char *)(lVar15 + 0x1fa + param_1) == '\x11') {
                  *(undefined1 *)(lVar15 + 0x1fa + param_1) = 0x5a;
                }
                else {
                  uVar7 = AHCIIssueIdentify(param_1,param_2,bVar13);
                  if (((char)uVar7 != '\x01') ||
                     (uVar7 = AHCISetDeviceParameter(param_1,param_2,bVar13), (char)uVar7 != '\x01')
                     ) goto LAB_00016105;
                  psVar2 = (short *)(lVar10 + 0x1f8 + param_1);
                  *psVar2 = *psVar2 + 1;
                  *(short *)(param_1 + 0x7518) = *(short *)(param_1 + 0x7518) + 1;
                }
              }
              else {
LAB_0001610e:
                pvVar5 = (void *)AHCIRecoverPMFromLastError(param_1,param_2);
                if ((char)pvVar5 == '\0') goto LAB_0001626b;
              }
              uVar8 = local_res20[0];
            }
            bVar13 = bVar13 + 1;
          } while (bVar13 < local_res10);
        }
        local_res8[0] = 0xffffffff;
        if (*(char *)(lVar10 + 0xd59 + param_1) != '\0') {
          do {
            cVar3 = *(char *)(uVar9 + lVar10 + 0x1fa + param_1);
            if ((cVar3 != '\x01') && (cVar3 != '\x11')) break;
            AHCIPMReadWrite(param_1,param_2,(byte)uVar9,CONCAT71(uVar12,0xf),-0x18,1,local_res8);
            bVar11 = (byte)uVar9 + 1;
            uVar9 = (ulonglong)bVar11;
          } while (bVar11 < *(byte *)(lVar10 + 0xd59 + param_1));
        }
        pvVar5 = *(void **)(lVar10 + 0x58 + param_1);
        *(undefined4 *)((longlong)pvVar5 + 0x3c) = 0xffffffff;
LAB_0001625e:
        return CONCAT71((int7)((ulonglong)pvVar5 >> 8),1);
      }
      pvVar5 = extraout_RAX;
      if (uVar8 != 0) {
        pvVar5 = memset((void *)(lVar10 + 0x1fa + param_1),0,(ulonglong)bVar14);
      }
      goto LAB_0001626b;
    }
    cVar3 = *(char *)(lVar10 + 0x1fa + param_1);
    if (cVar3 == '\x11') {
      *(byte *)(lVar10 + 0xd58 + param_1) = bVar11 | 0x80;
      pbVar1 = (byte *)(*(longlong *)(lVar10 + 0x58 + param_1) + 0x1b);
      *pbVar1 = *pbVar1 | 1;
      pbVar1 = (byte *)(*(longlong *)(lVar10 + 0x58 + param_1) + 0x1b);
      *pbVar1 = *pbVar1 | 2;
    }
    else if (cVar3 != '\x01') goto LAB_0001625e;
    pvVar5 = (void *)AHCIIssueIdentify(param_1,param_2,0);
    if (((char)pvVar5 != '\0') &&
       (pvVar5 = (void *)AHCISetDeviceParameter(param_1,param_2,0), (char)pvVar5 == '\x01')) {
      *(undefined2 *)(lVar10 + 0x1f8 + param_1) = 1;
      *(short *)(param_1 + 0x7518) = *(short *)(param_1 + 0x7518) + 1;
      goto LAB_0001625e;
    }
  }
  *(undefined1 *)(lVar10 + 0x1fa + param_1) = 0x5a;
LAB_0001626b:
  return (ulonglong)pvVar5 & 0xffffffffffffff00;
}



===== AHCILowResourceAllocateMemory @ 00016284 =====

ulonglong AHCILowResourceAllocateMemory(longlong param_1,longlong param_2)

{
  uint uVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  byte bVar5;
  longlong lVar6;
  uint local_res8 [2];
  
  bVar5 = 0;
  *(undefined1 *)(param_2 + 0x51) = 1;
  *(undefined4 *)(param_2 + 0x30) = 3;
  *(undefined4 *)(param_2 + 0x1c) = 1;
  *(undefined1 *)(param_2 + 0x52) = 1;
  *(undefined1 *)(param_2 + 0x5c) = 1;
  *(undefined1 *)(param_2 + 0x53) = 0;
  *(undefined1 *)(param_2 + 0x5d) = 0;
  *(undefined1 *)(param_2 + 0x5b) = 0;
  *(undefined1 *)(param_2 + 0x57) = 1;
  *(undefined1 *)(param_2 + 0x48) = 1;
  *(undefined1 *)(param_2 + 0x61) = 0x3c;
  *(undefined4 *)(param_2 + 0x18) = 0x10000;
  uVar1 = 0x2000;
  if (*(char *)(param_1 + 0x767e) == '\x02') {
    uVar1 = 0x1000;
  }
  lVar2 = StorPortGetUncachedExtension(param_1,param_2,uVar1);
  if (lVar2 == 0) {
    uVar3 = StorPortDebugPrint(0,
                               "[FUNCTION] %s :Can\'t allocate memory by ExAllocatePoolWithTag().\n"
                               ,"AHCILowResourceAllocateMemory");
    uVar3 = uVar3 & 0xffffffffffffff00;
  }
  else {
    uVar3 = 0;
    local_res8[0] = 0;
    if (uVar1 >> 2 != 0) {
      do {
        *(undefined4 *)(lVar2 + uVar3 * 4) = 0;
        local_res8[0] = local_res8[0] + 1;
        uVar3 = (ulonglong)local_res8[0];
      } while (local_res8[0] < uVar1 >> 2);
    }
    if (*(char *)(param_1 + 0x767e) != '\0') {
      do {
        uVar1 = StorPortGetPhysicalAddress(param_1,0,lVar2,local_res8);
        if ((uVar1 & 0x3ff) == 0) {
          local_res8[0] = 0x400;
          lVar6 = (ulonglong)bVar5 * 0xe28;
          *(longlong *)(lVar6 + 0x60 + param_1) = lVar2;
          *(undefined4 *)(*(longlong *)(lVar6 + 0x58 + param_1) + 4) = 0;
          **(uint **)(lVar6 + 0x58 + param_1) = uVar1;
          *(uint *)(lVar6 + 0x68 + param_1) = uVar1;
          *(longlong *)(lVar6 + 0x70 + param_1) = lVar2 + 0x80;
          *(undefined4 *)(*(longlong *)(lVar6 + 0x60 + param_1) + 0xc) = 0;
          *(uint *)(*(longlong *)(lVar6 + 0x60 + param_1) + 8) = uVar1 + 0x80;
          *(uint *)(lVar6 + 0x170 + param_1) = uVar1 + 0x80;
          *(undefined4 *)(*(longlong *)(lVar6 + 0x58 + param_1) + 0xc) = 0;
          *(uint *)(*(longlong *)(lVar6 + 0x58 + param_1) + 8) = uVar1 + 0x200;
          *(uint *)(lVar6 + 0x6c + param_1) = uVar1 + 0x200;
          *(longlong *)(param_1 + 0x38f8 + (ulonglong)bVar5 * 8) = lVar2 + 0x200;
          uVar1 = 0x400;
          bVar5 = bVar5 + 1;
        }
        else {
          uVar1 = 0x400 - (uVar1 & 0x3ff);
        }
        lVar2 = lVar2 + (ulonglong)uVar1;
      } while (bVar5 < *(byte *)(param_1 + 0x767e));
    }
    uVar4 = StorPortGetPhysicalAddress(param_1,0,lVar2,local_res8);
    *(longlong *)(param_1 + 0x7540) = lVar2;
    *(longlong *)(param_1 + 0x7520) = lVar2 + 0x200;
    *(int *)(param_1 + 0x7548) = (int)uVar4;
    *(undefined1 *)(param_1 + 0x768d) = 1;
    *(undefined1 *)(param_1 + 0x767c) = 1;
    uVar3 = CONCAT71((int7)((ulonglong)uVar4 >> 8),1);
    *(int *)(param_1 + 0x7528) = (int)uVar4 + 0x200;
  }
  return uVar3;
}



===== AHCIAllocateMemory @ 0001646c =====

ulonglong AHCIAllocateMemory(longlong *param_1,longlong param_2)

{
  uint uVar1;
  longlong lVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  int iVar5;
  int iVar6;
  ushort uVar7;
  ulonglong uVar8;
  uint uVar9;
  uint uVar10;
  ulonglong uVar11;
  uint uVar12;
  ushort uVar13;
  ushort uVar14;
  bool bVar15;
  ushort local_res8;
  uint local_res18 [2];
  longlong local_res20;
  
  iVar5 = *(byte *)((longlong)param_1 + 0x767e) / 3 +
          (*(byte *)((longlong)param_1 + 0x767d) / 5 + 1) *
          (*(byte *)((longlong)param_1 + 0x767e) + 1) + 3;
  uVar12 = iVar5 * 0x1000;
  lVar2 = StorPortGetUncachedExtension(param_1,param_2,uVar12 + 0x20000);
  param_1[0xecd] = lVar2;
  if (lVar2 == 0) {
    uVar3 = AHCILowResourceAllocateMemory((longlong)param_1,param_2);
    if ((char)uVar3 == '\0') {
      uVar4 = StorPortDebugPrint(0,
                                 "[FUNCTION] %s :Can\'t allocate memory by ExAllocatePoolWithTag().\n"
                                 ,"AHCIAllocateMemory");
      *(byte *)(param_1[3] + 3) = *(byte *)(param_1[3] + 3) & 0x7f;
      uVar4 = uVar4 & 0xffffffffffffff00;
    }
    else {
      uVar4 = CONCAT71((int7)((ulonglong)uVar3 >> 8),1);
    }
  }
  else {
    lVar2 = lVar2 + 0x20000;
    uVar4 = 0;
    *(undefined4 *)(param_1 + 1) = 0x30313834;
    *param_1 = lVar2;
    local_res18[0] = 0;
    if (iVar5 != 0) {
      do {
        *(undefined4 *)(lVar2 + uVar4 * 4) = 0;
        local_res18[0] = local_res18[0] + 1;
        uVar4 = (ulonglong)local_res18[0];
      } while (local_res18[0] < (uint)(iVar5 * 0x400));
    }
    uVar14 = (ushort)*(byte *)((longlong)param_1 + 0x767e);
    uVar7 = (ushort)*(byte *)((longlong)param_1 + 0x767d) *
            (ushort)*(byte *)((longlong)param_1 + 0x767e);
    uVar13 = 1;
    uVar9 = 0;
    local_res8 = uVar7;
    local_res20 = lVar2;
    if (iVar5 != 0) {
      do {
        uVar1 = StorPortGetPhysicalAddress(param_1,0,lVar2,local_res18);
        uVar4 = 0x1000;
        if ((uVar1 & 0xfff) == 0) {
          uVar9 = uVar9 + 0x1000;
          uVar10 = 0x1000;
          local_res18[0] = 0x1000;
          do {
            if (uVar14 == 0) {
              if (uVar7 != 0) {
                uVar4 = (longlong)(int)(uVar7 - 1) %
                        (longlong)(int)(uint)*(byte *)((longlong)param_1 + 0x767d);
                uVar8 = (longlong)(int)(uVar7 - 1) /
                        (longlong)(int)(uint)*(byte *)((longlong)param_1 + 0x767d) & 0xffff;
                uVar11 = uVar4 & 0xffff;
                iVar5 = (((uint)uVar4 & 0xffff) % 5) * 0x300;
                iVar6 = iVar5 + uVar1;
                param_1[uVar8 * 0x1c5 + uVar11 + 0xe] = iVar5 + lVar2;
                *(undefined4 *)(uVar11 * 0x20 + 0xc + param_1[uVar8 * 0x1c5 + 0xc]) = 0;
                *(int *)(uVar11 * 0x20 + 8 + param_1[uVar8 * 0x1c5 + 0xc]) = iVar6;
                *(int *)((longlong)param_1 + (uVar8 * 0x38a + uVar11) * 4 + 0x170) = iVar6;
                uVar7 = local_res8 - 1;
                uVar4 = 0;
                local_res8 = uVar7;
                if ((uint)uVar7 % 5 != 0) {
                  uVar4 = (ulonglong)uVar7 /
                          (ulonglong)(longlong)(int)(uint)*(byte *)((longlong)param_1 + 0x767d);
                  bVar15 = (int)((ulonglong)uVar7 %
                                (ulonglong)
                                (longlong)(int)(uint)*(byte *)((longlong)param_1 + 0x767d)) == 0;
                  goto LAB_0001666c;
                }
                goto LAB_00016672;
              }
              if (uVar13 == 0) {
                param_1[0xea6] = lVar2;
                *(uint *)(param_1 + 0xea7) = uVar1;
                uVar9 = uVar12;
              }
              else {
                uVar13 = uVar13 - 1;
                param_1[0xea8] = lVar2;
                *(uint *)(param_1 + 0xea5) = uVar1 + 0x200;
                *(uint *)(param_1 + 0xea9) = uVar1;
                param_1[0xea4] = lVar2 + 0x200;
                uVar4 = 0;
                if ((uVar13 & 3) != 0) goto LAB_000167ed;
              }
LAB_000167e1:
              local_res18[0] = uVar10 - 0x1000;
              uVar10 = local_res18[0];
            }
            else {
              uVar14 = uVar14 - 1;
              uVar4 = (ulonglong)uVar14;
              uVar10 = (uint)uVar14 % 3;
              iVar5 = uVar10 * 0x400 + uVar1;
              param_1[uVar4 * 0x1c5 + 0xc] = (int)(uVar10 * 0x400) + lVar2;
              *(undefined4 *)(param_1[uVar4 * 0x1c5 + 0xb] + 4) = 0;
              *(int *)param_1[uVar4 * 0x1c5 + 0xb] = iVar5;
              *(int *)(param_1 + uVar4 * 0x1c5 + 0xd) = iVar5;
              *(undefined4 *)(param_1[uVar4 * 0x1c5 + 0xb] + 0xc) = 0;
              iVar5 = (uVar10 + 0xc) * 0x100 + uVar1;
              *(int *)(param_1[uVar4 * 0x1c5 + 0xb] + 8) = iVar5;
              *(int *)(uVar4 * 0xe28 + 0x6c + (longlong)param_1) = iVar5;
              param_1[uVar4 + 0x71f] = (longlong)(int)(uVar10 * 0x100) + 0xc00 + lVar2;
              uVar10 = (uVar14 / 3) * 3;
              uVar4 = (ulonglong)uVar10;
              bVar15 = uVar14 == uVar10;
LAB_0001666c:
              if (bVar15) {
LAB_00016672:
                uVar10 = local_res18[0];
                goto LAB_000167e1;
              }
              uVar10 = local_res18[0];
            }
LAB_000167ed:
          } while (uVar10 != 0);
        }
        else {
          uVar1 = 0x1000 - (uVar1 & 0xfff);
          uVar4 = (ulonglong)uVar1;
          uVar9 = uVar9 + uVar1;
        }
        lVar2 = (ulonglong)uVar9 + local_res20;
      } while (uVar9 < uVar12);
    }
    uVar4 = CONCAT71((int7)(uVar4 >> 8),1);
  }
  return uVar4;
}



===== ParsingParameters @ 00016824 =====

void ParsingParameters(longlong param_1,longlong param_2)

{
  byte *pbVar1;
  char cVar2;
  bool bVar3;
  undefined2 uVar4;
  longlong lVar5;
  ulonglong uVar6;
  byte bVar7;
  byte bVar8;
  char *pcVar9;
  byte bVar10;
  byte bVar11;
  byte bVar12;
  byte bVar13;
  byte bVar14;
  byte bVar15;
  char cVar16;
  byte local_res8 [8];
  
  cVar16 = -1;
  bVar12 = 0;
  bVar8 = 0;
  StorPortDebugPrint(0,"[FUNCTION] %s : Completed.\n","ParsingParameters");
  local_res8[0] = 0;
  local_res8[1] = 0;
  uVar4 = local_res8._0_2_;
  bVar14 = 0;
  local_res8[2] = 0;
  bVar10 = 0;
  while( true ) {
    pcVar9 = (char *)((ulonglong)bVar10 + param_1);
    if (pcVar9 == (char *)0x0) {
      return;
    }
    if (((((*pcVar9 == 'P') && (pcVar9 + 1 != (char *)0x0)) && (pcVar9[1] == 'a')) &&
        (((pcVar9 + 2 != (char *)0x0 && (pcVar9[2] == 'r')) &&
         ((pcVar9 + 3 != (char *)0x0 && ((pcVar9[3] == 't' && (pcVar9 + 4 != (char *)0x0)))))))) &&
       ((pcVar9[4] == 'i' &&
        ((((pcVar9 + 5 != (char *)0x0 && (pcVar9[5] == 'a')) && (pcVar9 + 6 != (char *)0x0)) &&
         (pcVar9[6] == 'l')))))) break;
    bVar10 = bVar10 + 1;
    if (0x9f < bVar10) {
      return;
    }
  }
  local_res8[1] = 0;
  local_res8[0] = 0;
  bVar3 = false;
  bVar15 = 0;
  bVar13 = local_res8[1];
  bVar11 = local_res8[0];
  local_res8._0_2_ = uVar4;
  do {
    pcVar9 = (char *)((ulonglong)bVar15 + (ulonglong)bVar10 + param_1);
    if (pcVar9 == (char *)0x0) {
      return;
    }
    cVar2 = *pcVar9;
    if (cVar2 == '=') {
      bVar15 = bVar15 + 1;
      bVar3 = true;
      bVar12 = 0;
      cVar16 = cVar16 + '\x01';
      bVar8 = 0;
    }
    else if (bVar3) {
      if (cVar16 == '\0') {
        if (cVar2 != ' ') goto LAB_00016be2;
        if (bVar8 == 3) {
          bVar7 = bVar14;
        }
        else if (bVar8 == 2) {
          bVar7 = bVar13;
        }
        else {
          bVar7 = 0;
          if (bVar8 == 1) {
            bVar7 = bVar11;
          }
        }
        lVar5 = (ulonglong)bVar12 * 0xe28;
        pbVar1 = (byte *)(lVar5 + 0xe78 + param_2);
        *pbVar1 = *pbVar1 & 0xfb;
        bVar8 = (bVar7 & 1) << 2;
LAB_000169aa:
        pbVar1 = (byte *)(lVar5 + 0xe78 + param_2);
        *pbVar1 = *pbVar1 | bVar8;
      }
      else {
        if (cVar16 == '\x01') {
          if (cVar2 != ' ') goto LAB_00016be2;
          if (bVar8 == 3) {
            bVar7 = bVar14;
          }
          else if (bVar8 == 2) {
            bVar7 = bVar13;
          }
          else {
            bVar7 = 0;
            if (bVar8 == 1) {
              bVar7 = bVar11;
            }
          }
          lVar5 = (ulonglong)bVar12 * 0xe28;
          pbVar1 = (byte *)(lVar5 + 0xe78 + param_2);
          *pbVar1 = *pbVar1 & 0xf7;
          bVar8 = (bVar7 & 1) << 3;
          goto LAB_000169aa;
        }
        if (cVar16 == '\x02') {
          if (cVar2 != ' ') goto LAB_00016be2;
          if (bVar8 == 3) {
            bVar7 = bVar14;
          }
          else if (bVar8 == 2) {
            bVar7 = bVar13;
          }
          else {
            bVar7 = 0;
            if (bVar8 == 1) {
              bVar7 = bVar11;
            }
          }
          lVar5 = (ulonglong)bVar12 * 0xe28;
          pbVar1 = (byte *)(lVar5 + 0xe78 + param_2);
          *pbVar1 = *pbVar1 & 0xef;
          bVar8 = (bVar7 & 1) << 4;
          goto LAB_000169aa;
        }
        if (cVar16 != '\x03') {
          if (cVar16 == '\x04') {
            if (cVar2 == ' ') {
              if (bVar8 == 3) {
                bVar7 = bVar14;
              }
              else if (bVar8 == 2) {
                bVar7 = bVar13;
              }
              else {
                bVar7 = 0;
                if (bVar8 == 1) {
                  bVar7 = bVar11;
                }
              }
              lVar5 = (ulonglong)bVar12 * 0xe28;
              pbVar1 = (byte *)(lVar5 + 0xe78 + param_2);
              *pbVar1 = *pbVar1 & 0xdf;
              bVar8 = (bVar7 & 1) << 5;
              goto LAB_000169aa;
            }
          }
          else {
            if (cVar16 != '\x05') {
              if (cVar16 == '\x06') {
                if (cVar2 != ' ') goto LAB_00016be2;
                if (bVar8 == 3) {
                  bVar7 = bVar14;
                }
                else if (bVar8 == 2) {
                  bVar7 = bVar13;
                }
                else {
                  bVar7 = 0;
                  if (bVar8 == 1) {
                    bVar7 = bVar11;
                  }
                }
                uVar6 = (ulonglong)bVar12;
                bVar12 = bVar12 + 1;
                bVar8 = 0;
                pbVar1 = (byte *)(uVar6 * 0xe28 + 0xd58 + param_2);
                *pbVar1 = *pbVar1 & 0xfd;
                pbVar1 = (byte *)(uVar6 * 0xe28 + 0xd58 + param_2);
                *pbVar1 = *pbVar1 | (bVar7 & 1) * '\x02';
                if (bVar12 == 4) {
                  return;
                }
              }
              goto LAB_00016c69;
            }
            if (cVar2 == ' ') {
              if (bVar8 == 3) {
                bVar7 = (bVar11 * '\n' + bVar13) * '\n' + bVar14;
              }
              else if (bVar8 == 2) {
                bVar7 = bVar11 * '\n' + bVar13;
              }
              else {
                bVar7 = 0;
                if (bVar8 == 1) {
                  bVar7 = bVar11;
                }
              }
              *(byte *)((ulonglong)bVar12 * 0xe28 + 0xe77 + param_2) = bVar7;
              goto LAB_000169b1;
            }
          }
LAB_00016be2:
          uVar6 = (ulonglong)bVar8;
          bVar8 = bVar8 + 1;
          local_res8[uVar6] = cVar2 - 0x30;
          bVar14 = local_res8[2];
          bVar13 = local_res8[1];
          bVar11 = local_res8[0];
          goto LAB_00016c69;
        }
        if (cVar2 != ' ') goto LAB_00016be2;
        if (bVar8 == 3) {
          bVar7 = (bVar11 * '\n' + bVar13) * '\n' + bVar14;
        }
        else if (bVar8 == 2) {
          bVar7 = bVar11 * '\n' + bVar13;
        }
        else {
          bVar7 = 0;
          if (bVar8 == 1) {
            bVar7 = bVar11;
          }
        }
        *(byte *)((ulonglong)bVar12 * 0xe28 + 0xe76 + param_2) = bVar7;
      }
LAB_000169b1:
      bVar12 = bVar12 + 1;
      bVar8 = 0;
      if (bVar12 == 4) {
        bVar3 = false;
      }
    }
LAB_00016c69:
    bVar15 = bVar15 + 1;
    if (0xa9 < bVar15) {
      return;
    }
  } while( true );
}



===== AHCIFindController @ 00016c9c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
AHCIFindController(longlong *param_1,undefined8 param_2,undefined8 param_3,longlong param_4,
                  longlong param_5,undefined1 *param_6)

{
  byte *pbVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  undefined8 uVar5;
  longlong lVar6;
  ulonglong uVar7;
  longlong *plVar8;
  ulonglong uVar9;
  longlong lVar10;
  ushort uVar11;
  ulonglong uVar12;
  byte bVar13;
  undefined8 *puVar14;
  undefined4 *puVar15;
  uint uVar16;
  undefined1 auStack_d8 [32];
  byte *local_b8;
  int local_b0;
  undefined4 local_a8;
  char local_98;
  byte local_97 [7];
  undefined8 auStack_90 [5];
  longlong local_68;
  undefined4 local_58;
  undefined2 uStack_54;
  undefined2 uStack_52;
  undefined1 uStack_50;
  undefined1 uStack_4f;
  undefined1 uStack_4e;
  undefined1 uStack_4d;
  undefined1 uStack_4c;
  undefined1 uStack_4b;
  undefined1 uStack_4a;
  undefined1 uStack_49;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_d8;
  uVar12 = 0;
  pbVar1 = (byte *)((longlong)param_1 + 0x754c);
  uStack_54 = 0x17d4;
  local_b0 = 0xff;
  local_68 = 0;
  local_98 = '\0';
  local_58 = 0x88cc8ad7;
  uStack_52 = 0x42d7;
  uStack_50 = 0xa1;
  uStack_4f = 0x76;
  uStack_4e = 0xf6;
  uStack_4d = 0xc1;
  uStack_4c = 200;
  uStack_4b = 0xe5;
  uStack_4a = 0xe9;
  uStack_49 = 0x68;
  local_b8 = pbVar1;
  iVar4 = StorPortGetBusData(param_1,4,*(undefined4 *)(param_5 + 4),*(undefined4 *)(param_5 + 100));
  *param_6 = 0;
  if (iVar4 != 0xff) {
    return 0;
  }
  if (*(int *)pbVar1 != 0x11841039) {
    if (*(int *)pbVar1 == 0x11851039) {
      if (*(int *)pbVar1 != 0x1861039) {
        *(undefined1 *)((longlong)param_1 + 0x767f) = 0;
        goto LAB_00016d93;
      }
    }
    else if (*(int *)pbVar1 != 0x1861039) {
      return 0;
    }
  }
  *(undefined1 *)((longlong)param_1 + 0x767f) = 1;
LAB_00016d93:
  uVar11 = 0;
  *(bool *)((longlong)param_1 + 0x7843) = 2 < (*(uint *)((longlong)param_1 + 0x7554) & 0xff);
  lVar10 = 0;
  if (*(int *)(param_5 + 0x34) != 0) {
    do {
      puVar14 = (undefined8 *)((ulonglong)uVar11 * 0x10 + *(longlong *)(param_5 + 0x38));
      if (uVar11 < 5) {
        local_b0 = CONCAT31(local_b0._1_3_,1);
      }
      else {
        local_b0 = (uint)local_b0._1_3_ << 8;
      }
      local_b8 = (byte *)CONCAT44(local_b8._4_4_,*(undefined4 *)(puVar14 + 1));
      uVar5 = StorPortGetDeviceBase
                        (param_1,*(undefined4 *)(param_5 + 8),*(undefined4 *)(param_5 + 4),*puVar14)
      ;
      auStack_90[uVar11] = uVar5;
      if ((uVar11 == 5) && (local_68 == 0)) {
        StorPortDebugPrint(0,"[FUNCTION] %s :AHCIBaseAddress is NULL \n","AHCIFindController");
        return 3;
      }
      uVar11 = uVar11 + 1;
      lVar10 = local_68;
    } while ((uint)uVar11 < *(uint *)(param_5 + 0x34));
  }
  *(undefined4 *)((longlong)param_1 + 0x764c) = *(undefined4 *)(param_5 + 4);
  *(undefined4 *)(param_1 + 0xeca) = *(undefined4 *)(param_5 + 100);
  *(undefined1 *)(param_5 + 0x51) = 1;
  *(undefined4 *)(param_5 + 0x30) = 3;
  *(undefined4 *)(param_5 + 0x1c) = 0x11;
  *(undefined1 *)(param_5 + 0x5a) = 1;
  *(undefined1 *)(param_5 + 0x52) = 1;
  *(undefined1 *)(param_5 + 0x5c) = 1;
  *(undefined1 *)(param_5 + 0x57) = 1;
  *(undefined1 *)(param_5 + 0x48) = 1;
  *(undefined1 *)(param_5 + 0x61) = 4;
  *(undefined4 *)(param_5 + 0x18) = 0x10000;
  *(undefined1 *)(param_5 + 0x53) = 1;
  *(undefined1 *)(param_5 + 0x5d) = 1;
  *(undefined1 *)(param_5 + 0x5b) = 1;
  *(undefined1 *)(param_5 + 0x91) = 1;
  *(undefined1 *)(param_5 + 0x59) = 2;
  *(undefined4 *)(param_5 + 0x94) = 0;
  *(undefined1 *)(param_5 + 0x93) = 1;
  *(undefined4 *)(param_1 + 0xed9) = 2;
  param_1[0xede] = 0;
  param_1[0xedf] = 0;
  param_1[0xeda] = (longlong)&SiSRAID4GuidList;
  param_1[0xedb] = (longlong)&AHCIWmiQueryWmiRegInfo;
  param_1[0xedc] = (longlong)AHCIWmiQueryDataBlock;
  param_1[0xedd] = (longlong)AHCIWmiSetDataBlock;
  param_1[0xee0] = (longlong)AHCIWmiFunctionControl;
  param_1[2] = lVar10;
  param_1[0xeea] = CONCAT26(uStack_52,CONCAT24(uStack_54,local_58));
  param_1[0xeeb] =
       CONCAT17(uStack_49,
                CONCAT16(uStack_4a,
                         CONCAT15(uStack_4b,
                                  CONCAT14(uStack_4c,
                                           CONCAT13(uStack_4d,
                                                    CONCAT12(uStack_4e,CONCAT11(uStack_4f,uStack_50)
                                                            ))))));
  param_1[3] = lVar10 + 4;
  param_1[9] = lVar10 + 0xa0;
  param_1[4] = lVar10 + 8;
  param_1[5] = lVar10 + 0xc;
  param_1[6] = lVar10 + 0x10;
  param_1[7] = lVar10 + 0x14;
  param_1[8] = lVar10 + 0x18;
  param_1[10] = lVar10 + 0xb0;
  if (*(int *)pbVar1 == 0x1861039) {
    *(undefined4 *)(lVar10 + 0xa0) = 0x6db3ffd3;
    *(undefined4 *)param_1[10] = 0x1fc8;
  }
  if ((undefined4 *)param_1[9] != (undefined4 *)0x0) {
    *(undefined4 *)((longlong)param_1 + 0x7654) = *(undefined4 *)param_1[9];
  }
  if ((undefined4 *)param_1[10] != (undefined4 *)0x0) {
    *(undefined4 *)(param_1 + 0xecb) = *(undefined4 *)param_1[10];
  }
  lVar6 = param_1[2];
  if (lVar6 != 0) {
    *(byte *)((longlong)param_1 + 0x767d) = (*(byte *)(lVar6 + 1) & 0x1f) + 1;
    *(byte *)((longlong)param_1 + 0x768c) = *(byte *)(lVar6 + 3) >> 3 & 1;
    bVar13 = *(byte *)(lVar6 + 3);
    *(undefined1 *)((longlong)param_1 + 0x768b) = 0;
    *(undefined1 *)((longlong)param_1 + 0x768e) = 0;
    *(byte *)((longlong)param_1 + 0x768f) = bVar13 >> 5 & 1;
  }
  local_b0 = 0xff;
  local_b8 = pbVar1;
  StorPortGetBusData(param_1,4,*(undefined4 *)(param_5 + 4),*(undefined4 *)(param_5 + 100));
  puVar15 = (undefined4 *)((longlong)param_1 + 0xe7c);
  lVar6 = 4;
  do {
    *puVar15 = 0;
    puVar15 = puVar15 + 0x38a;
    lVar6 = lVar6 + -1;
  } while (lVar6 != 0);
  uVar16 = 0;
  *(undefined1 *)((longlong)param_1 + 0x767e) = 0;
  uVar11 = 0;
  do {
    if ((param_1[2] == 0) || ((*(byte *)param_1[2] & 0x1f) < uVar11)) {
      puVar15 = (undefined4 *)param_1[3];
      *(undefined1 *)((longlong)param_1 + 0x7689) = 0;
      if (puVar15 != (undefined4 *)0x0) {
        if ((*(byte *)((longlong)puVar15 + 3) & 0x80) != 0) {
          *(undefined1 *)((longlong)param_1 + 0x7689) = 1;
        }
        if ((puVar15 != (undefined4 *)0x0) && (*(char *)((longlong)param_1 + 0x7689) == '\0')) {
          *puVar15 = 0;
          *(byte *)(param_1[3] + 3) = *(byte *)(param_1[3] + 3) | 0x80;
        }
      }
      *(undefined1 *)((longlong)param_1 + 0x768d) = 0;
      *(char *)((longlong)param_1 + 0x767c) =
           (char)((int)((uint)*(byte *)((longlong)param_1 + 0x767d) * 3) >> 2);
      if (((int)param_1[1] == 0x30313834) ||
         (uVar5 = AHCIAllocateMemory(param_1,param_5), (char)uVar5 != '\0')) {
        while( true ) {
          bVar3 = false;
          bVar2 = false;
          if ((*(char *)((longlong)param_1 + 0x7689) == '\0') &&
             (uVar5 = AHCIHBAReset((longlong)param_1), (char)uVar5 == '\0')) break;
          if ((param_1[3] != 0) && (*(char *)((longlong)param_1 + 0x7689) == '\0')) {
            pbVar1 = (byte *)(param_1[3] + 3);
            *pbVar1 = *pbVar1 | 0x80;
          }
          uVar11 = 0;
          if (*(char *)((longlong)param_1 + 0x767e) != '\0') {
            do {
              uVar9 = (ulonglong)uVar11;
              if ((*(byte *)(param_1[uVar9 * 0x1c5 + 0xb] + 0x18) & 0x10) != 0) {
                pbVar1 = (byte *)(param_1[uVar9 * 0x1c5 + 0xb] + 0x18);
                *pbVar1 = *pbVar1 & 0xef;
              }
              if ((*(byte *)(param_1[uVar9 * 0x1c5 + 0xb] + 0x18) & 1) != 0) {
                pbVar1 = (byte *)(param_1[uVar9 * 0x1c5 + 0xb] + 0x18);
                *pbVar1 = *pbVar1 & 0xfe;
              }
              bVar13 = *(byte *)(param_1[uVar9 * 0x1c5 + 0xb] + 0x19);
              for (uVar16 = 0; ((bVar13 & 0x80) != 0 && (uVar16 < 1000)); uVar16 = uVar16 + 1) {
                StorPortStallExecution(500);
                bVar13 = *(byte *)(param_1[uVar9 * 0x1c5 + 0xb] + 0x19);
              }
              uVar11 = uVar11 + 1;
            } while (uVar11 < *(byte *)((longlong)param_1 + 0x767e));
          }
          uVar9 = (ulonglong)*(uint *)(param_1 + 0xeca);
          local_97[0] = *(byte *)((longlong)param_1 + 0x7551) | 4;
          local_a8 = 1;
          local_b0 = 5;
          local_b8 = local_97;
          StorPortSetBusDataByOffset(param_1,4);
          pbVar1 = (byte *)param_1[3];
          if (pbVar1 != (byte *)0x0) {
            *pbVar1 = *pbVar1 & 0xfd;
          }
          *(undefined2 *)(param_1 + 0xea3) = 0;
          *(undefined1 *)(param_1 + 0xecf) = 0;
          *(undefined1 *)((longlong)param_1 + 0x767a) = 0;
          *(undefined1 *)((longlong)param_1 + 0x7679) = 0;
          *(undefined1 *)((longlong)param_1 + 0x7684) = 0;
          uVar11 = 0;
          if (*(char *)((longlong)param_1 + 0x767e) != '\0') {
            do {
              uVar7 = (ulonglong)uVar11;
              uVar11 = uVar11 + 1;
              lVar10 = uVar7 * 0xe28;
              *(undefined4 *)(param_1[uVar7 * 0x1c5 + 0xb] + 0x30) = 0xffffffff;
              *(undefined4 *)(param_1[uVar7 * 0x1c5 + 0xb] + 0x10) = 0xffffffff;
              *(undefined8 *)(lVar10 + 0x1fa + (longlong)param_1) = 0;
              *(undefined4 *)(lVar10 + 0x202 + (longlong)param_1) = 0;
              *(undefined2 *)(lVar10 + 0x206 + (longlong)param_1) = 0;
              *(undefined1 *)(param_1 + uVar7 * 0x1c5 + 0x41) = 0;
            } while (uVar11 < *(byte *)((longlong)param_1 + 0x767e));
          }
          uVar11 = 0;
          if (*(char *)((longlong)param_1 + 0x767e) != '\0') {
            do {
              uVar7 = (ulonglong)uVar11;
              uVar11 = uVar11 + 1;
              *(byte *)(param_1 + uVar7 * 0x1c5 + 0x1ab) =
                   *(byte *)(param_1 + uVar7 * 0x1c5 + 0x1ab) | 2;
            } while (uVar11 < *(byte *)((longlong)param_1 + 0x767e));
          }
          if (param_4 != 0) {
            ParsingParameters(param_4,(longlong)param_1);
          }
          uVar11 = 0;
          if (*(char *)((longlong)param_1 + 0x767e) != '\0') {
            do {
              uVar7 = (ulonglong)uVar11;
              lVar6 = uVar7 * 0xe28;
              lVar10 = param_1[uVar7 * 0x1c5 + 0xb];
              *(byte *)(param_1 + uVar7 * 0x1c5 + 0x1cf) =
                   *(byte *)(param_1 + uVar7 * 0x1c5 + 0x1cf) & 0xbf;
              *(byte *)(param_1 + uVar7 * 0x1c5 + 0x1ab) =
                   *(byte *)(param_1 + uVar7 * 0x1c5 + 0x1ab) & 0x1a;
              *(undefined2 *)(param_1 + uVar7 * 0x1c5 + 0x3f) = 0;
              *(undefined1 *)(lVar6 + 0xd5a + (longlong)param_1) = 0;
              *(undefined4 *)(param_1 + uVar7 * 0x1c5 + 0x1cc) = 0;
              *(undefined4 *)(lVar6 + 0xe64 + (longlong)param_1) = 0;
              *(undefined4 *)(param_1 + uVar7 * 0x1c5 + 0x1cd) = 0;
              *(undefined1 *)(lVar6 + 0xe6d + (longlong)param_1) = 0;
              *(undefined1 *)(lVar6 + 0xe6c + (longlong)param_1) = 0;
              *(undefined4 *)(lVar10 + 0x18) = 0;
              uVar5 = AHCISpinUpDevice((longlong)param_1,(byte)uVar11);
              if ((char)uVar5 != '\0') {
                *(byte *)(param_1 + uVar7 * 0x1c5 + 0x1ab) =
                     *(byte *)(param_1 + uVar7 * 0x1c5 + 0x1ab) | 0x40;
                uVar5 = AHCIDetectDevice((longlong)param_1,(byte)uVar11,0,uVar9);
                if ((char)uVar5 == '\0') {
                  lVar10 = param_1[uVar7 * 0x1c5 + 0xb];
                  *(undefined1 *)(lVar6 + 0x1fa + (longlong)param_1) = 0x5a;
                  bVar3 = true;
                  bVar2 = true;
                  *(byte *)(lVar10 + 0x18) = *(byte *)(lVar10 + 0x18) & 0xfe;
                }
              }
              if ((*(byte *)(param_1 + uVar7 * 0x1c5 + 0x1ab) & 4) == 0) {
                *(undefined4 *)(param_1[uVar7 * 0x1c5 + 0xb] + 0x14) = 0x78c000cb;
              }
              else {
                *(undefined4 *)(param_1[uVar7 * 0x1c5 + 0xb] + 0x14) = 0x788000cb;
              }
              uVar11 = uVar11 + 1;
            } while (uVar11 < *(byte *)((longlong)param_1 + 0x767e));
          }
          for (uVar11 = 0;
              (*(char *)((longlong)param_1 + 0x767f) != '\0' &&
              (uVar11 < *(byte *)((longlong)param_1 + 0x767e))); uVar11 = uVar11 + 1) {
            uVar5 = AHCIGetRaidInfo((longlong)param_1,(byte)uVar11);
            bVar2 = bVar3;
            if ((char)uVar5 == '\0') {
              bVar2 = true;
            }
            bVar3 = bVar2;
          }
          if ((local_98 != '\0') || (!bVar2)) {
            plVar8 = param_1 + 0x723;
            lVar10 = 0x3c;
            do {
              *(undefined1 *)((longlong)plVar8 + 0xc) = 0;
              *(undefined4 *)plVar8 = 0;
              *(undefined4 *)((longlong)plVar8 + 4) = 0;
              *(undefined2 *)((longlong)plVar8 + 10) = 0;
              *(undefined2 *)(plVar8 + 0x1f) = 0;
              *(undefined1 *)((longlong)plVar8 + 0xfa) = 0;
              *(undefined1 *)((longlong)plVar8 + 0xfb) = 0;
              plVar8 = plVar8 + 0x20;
              lVar10 = lVar10 + -1;
            } while (lVar10 != 0);
            AHCICheckRaidInfo((longlong)param_1);
            if ((*(char *)((longlong)param_1 + 0x768d) == '\x01') &&
               (uVar11 = 0, *(char *)((longlong)param_1 + 0x767e) != '\0')) {
              do {
                uVar9 = (ulonglong)uVar11;
                uVar11 = uVar11 + 1;
                *(byte *)(param_1 + uVar9 * 0x1c5 + 0x1ab) =
                     *(byte *)(param_1 + uVar9 * 0x1c5 + 0x1ab) & 0xfb;
              } while (uVar11 < *(byte *)((longlong)param_1 + 0x767e));
            }
            if (((*(char *)((longlong)param_1 + 0x768b) == '\x01') && (param_4 == 0)) &&
               (uVar11 = 0, *(char *)((longlong)param_1 + 0x767e) != '\0')) {
              do {
                uVar9 = (ulonglong)uVar11;
                if ((*(byte *)(param_1 + uVar9 * 0x1c5 + 0x1ab) & 4) == 0) {
                  *(byte *)(param_1 + uVar9 * 0x1c5 + 0x1cf) =
                       *(byte *)(param_1 + uVar9 * 0x1c5 + 0x1cf) & 0xc3;
                }
                else {
                  *(byte *)(param_1 + uVar9 * 0x1c5 + 0x1cf) =
                       *(byte *)(param_1 + uVar9 * 0x1c5 + 0x1cf) & 199 | 4;
                }
                uVar11 = uVar11 + 1;
              } while (uVar11 < *(byte *)((longlong)param_1 + 0x767e));
            }
            if ((*(char *)((longlong)param_1 + 0x768e) == '\x01') &&
               (uVar11 = 0, *(char *)((longlong)param_1 + 0x767e) != '\0')) {
              do {
                uVar9 = (ulonglong)uVar11;
                uVar11 = uVar11 + 1;
                *(byte *)(param_1 + uVar9 * 0x1c5 + 0x1cf) =
                     *(byte *)(param_1 + uVar9 * 0x1c5 + 0x1cf) | 0x80;
              } while (uVar11 < *(byte *)((longlong)param_1 + 0x767e));
            }
            if (*(char *)((longlong)param_1 + 0x768e) == '\0') {
              if (*(char *)((longlong)param_1 + 0x767e) != '\0') {
                do {
                  uVar11 = (short)uVar12 + 1;
                  *(byte *)(param_1 + uVar12 * 0x1c5 + 0x1cf) =
                       *(byte *)(param_1 + uVar12 * 0x1c5 + 0x1cf) & 0x7f;
                  uVar12 = (ulonglong)uVar11;
                } while (uVar11 < *(byte *)((longlong)param_1 + 0x767e));
              }
            }
            else {
              *(undefined4 *)(param_1 + 0xed2) = 0;
              if (*(char *)((longlong)param_1 + 0x767e) != '\0') {
                do {
                  if ((*(byte *)(param_1 + uVar12 * 0x1c5 + 0x1cf) & 0x80) != 0) {
                    *(uint *)(param_1 + 0xed2) =
                         *(uint *)(param_1 + 0xed2) |
                         *(uint *)(uVar12 * 0xe28 + 0xe7c + (longlong)param_1);
                  }
                  uVar11 = (short)uVar12 + 1;
                  uVar12 = (ulonglong)uVar11;
                } while (uVar11 < *(byte *)((longlong)param_1 + 0x767e));
              }
            }
            return 1;
          }
          local_98 = '\x01';
        }
      }
      return 0;
    }
    if ((uint *)param_1[5] != (uint *)0x0) {
      do {
        bVar13 = (byte)uVar16;
        if ((*(uint *)param_1[5] >> (uVar16 & 0x1f) & 1) != 0) break;
        if (0x20 < bVar13) goto LAB_000170a5;
        uVar16 = (uint)(byte)(bVar13 + 1);
      } while (param_1[5] != 0);
    }
    bVar13 = (byte)uVar16;
    if (bVar13 < 0x20) {
      param_1[(ulonglong)uVar11 * 0x1c5 + 0xb] = (ulonglong)(uVar16 << 7) + 0x100 + lVar10;
      *(int *)((ulonglong)uVar11 * 0xe28 + 0xe7c + (longlong)param_1) = 1 << (bVar13 & 0x1f);
      *(char *)((longlong)param_1 + 0x767e) = *(char *)((longlong)param_1 + 0x767e) + '\x01';
    }
LAB_000170a5:
    uVar16 = (uint)(byte)(bVar13 + 1);
    uVar11 = uVar11 + 1;
  } while( true );
}



===== AHCIBuildSGList @ 000175b0 =====

void AHCIBuildSGList(longlong param_1,longlong param_2,uint param_3,byte *param_4,uint *param_5,
                    uint *param_6)

{
  int *piVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  ulonglong uVar9;
  
  do {
    if (param_3 == 0) {
      return;
    }
    uVar8 = *param_6;
    if (uVar8 != 0) {
      bVar2 = *param_4;
      uVar9 = (ulonglong)bVar2;
      uVar4 = *param_5;
      *(undefined4 *)(param_2 + 200 + (ulonglong)*(byte *)(param_2 + 0x1a0) * 0xc) =
           *(undefined4 *)(param_1 + 0x14 + uVar9 * 0x18);
      uVar5 = *(uint *)(param_1 + 0x10 + uVar9 * 0x18);
      if (uVar4 + uVar5 < uVar5) {
        piVar1 = (int *)(param_2 + 200 + (ulonglong)*(byte *)(param_2 + 0x1a0) * 0xc);
        *piVar1 = *piVar1 + 1;
      }
      *(uint *)(param_2 + ((ulonglong)*(byte *)(param_2 + 0x1a0) * 3 + 0x33) * 4) =
           uVar4 + *(int *)(param_1 + 0x10 + uVar9 * 0x18);
      bVar3 = *(byte *)(param_2 + 0x1a0);
      if (param_3 < uVar8) {
        *(uint *)(param_2 + 0xd0 + (ulonglong)bVar3 * 0xc) = param_3;
        *param_5 = uVar4 + param_3;
        *param_6 = uVar8 - param_3;
        param_3 = 0;
      }
      else {
        *param_6 = 0;
        param_3 = param_3 - uVar8;
        *param_5 = 0;
        *(uint *)(param_2 + 0xd0 + (ulonglong)bVar3 * 0xc) = uVar8;
        *param_4 = bVar2 + 1;
      }
      *(char *)(param_2 + 0x1a0) = *(char *)(param_2 + 0x1a0) + '\x01';
      if (param_3 == 0) {
        return;
      }
    }
    bVar2 = *param_4;
    uVar9 = (ulonglong)bVar2;
    *(undefined4 *)(param_2 + 200 + (ulonglong)*(byte *)(param_2 + 0x1a0) * 0xc) =
         *(undefined4 *)(param_1 + 0x14 + uVar9 * 0x18);
    *(undefined4 *)(param_2 + ((ulonglong)*(byte *)(param_2 + 0x1a0) * 3 + 0x33) * 4) =
         *(undefined4 *)(param_1 + 0x10 + uVar9 * 0x18);
    bVar3 = *(byte *)(param_2 + 0x1a0);
    if (param_3 < *(uint *)(param_1 + 0x18 + uVar9 * 0x18)) {
      *(uint *)(param_2 + 0xd0 + (ulonglong)bVar3 * 0xc) = param_3;
      iVar7 = *(int *)(param_1 + 0x18 + uVar9 * 0x18);
      *param_5 = param_3;
      uVar8 = iVar7 - param_3;
      param_3 = 0;
      *param_6 = uVar8;
    }
    else {
      uVar6 = *(undefined4 *)(param_1 + 0x18 + uVar9 * 0x18);
      *param_6 = 0;
      *(undefined4 *)(param_2 + 0xd0 + (ulonglong)bVar3 * 0xc) = uVar6;
      param_3 = param_3 - *(int *)(param_1 + 0x18 + uVar9 * 0x18);
      *param_5 = 0;
      *param_4 = bVar2 + 1;
    }
    *(char *)(param_2 + 0x1a0) = *(char *)(param_2 + 0x1a0) + '\x01';
  } while( true );
}



===== AHCIBuildCcb @ 0001773c =====

undefined8 AHCIBuildCcb(longlong param_1,longlong param_2,byte param_3,byte param_4)

{
  void *_Dst;
  undefined1 *puVar1;
  uint *puVar2;
  ushort uVar3;
  longlong lVar4;
  undefined8 uVar5;
  int *piVar6;
  ulonglong uVar7;
  undefined7 uVar10;
  undefined8 *puVar8;
  void *pvVar9;
  uint7 uVar11;
  char cVar12;
  longlong lVar13;
  longlong lVar14;
  longlong lVar15;
  byte *pbVar16;
  ulonglong uVar17;
  uint uVar18;
  uint uVar19;
  ulonglong uVar20;
  int iVar21;
  byte bVar22;
  undefined1 uVar23;
  uint uVar24;
  int iVar25;
  longlong lVar26;
  byte bVar27;
  char cVar28;
  longlong lVar29;
  uint uVar30;
  ulonglong uVar31;
  byte local_58;
  byte local_57;
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  undefined8 local_40;
  
  lVar4 = *(longlong *)(param_2 + 0x38);
  uVar24 = *(uint *)(param_2 + 0x10);
  lVar29 = (ulonglong)*(byte *)(param_2 + 6) * 0x100 + 0x3918 + param_1;
  local_58 = 0;
  local_4c = local_4c & 0xffffff00;
  local_54 = 0;
  local_50 = 0;
  if (*(byte *)(param_2 + 10) < 0x10) {
    uVar20 = (ulonglong)
             CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(param_2 + 0x4a),
                                        *(undefined1 *)(param_2 + 0x4b)),
                               *(undefined1 *)(param_2 + 0x4c)),*(undefined1 *)(param_2 + 0x4d));
  }
  else {
    pbVar16 = (byte *)(param_2 + 0x4a);
    uVar20 = 0;
    lVar14 = 8;
    do {
      bVar27 = *pbVar16;
      pbVar16 = pbVar16 + 1;
      uVar20 = uVar20 * 0x100 + (ulonglong)bVar27;
      lVar14 = lVar14 + -1;
    } while (lVar14 != 0);
  }
  *(undefined1 *)(lVar4 + 0x10b0) = 0;
  if (*(char *)(param_2 + 0x48) == '/') {
    uVar24 = 0x10000;
  }
  piVar6 = (int *)StorPortGetScatterGatherList(param_1,param_2);
  if (*(char *)(lVar4 + 0x11) == '\x01') {
    uVar7 = (ulonglong)param_3 * 0xe28 + param_1;
    cVar12 = *(char *)((ulonglong)param_4 + 0x1fa + uVar7);
    if ((cVar12 == '\x01') || (cVar12 == '\x11')) {
      *(undefined1 *)(lVar4 + 0x10b0) = 1;
      *(byte *)(lVar4 + 0x22) = param_3;
      *(undefined1 *)(lVar4 + 0x20) = 0;
      *(byte *)(lVar4 + 0x23) = param_4;
      uVar23 = *(undefined1 *)(param_2 + 0x48);
      uVar7 = CONCAT71((int7)(uVar7 >> 8),uVar23);
      *(undefined1 *)(lVar4 + 0x26) = 1;
      *(uint *)(lVar4 + 0x34) = uVar24;
      *(ulonglong *)(lVar4 + 0x38) = uVar20;
      *(undefined1 *)(lVar4 + 0x24) = uVar23;
      *(undefined1 *)(lVar4 + 0x1c0) = 0;
      if ((piVar6 != (int *)0x0) && (*piVar6 != 0)) {
        AHCIBuildSGList((longlong)piVar6,lVar4 + 0x20,uVar24,&local_58,&local_50,&local_54);
        uVar7 = (ulonglong)*(byte *)(lVar4 + 0x1c0) * 3;
        puVar2 = (uint *)(lVar4 + 0xe4 + (ulonglong)*(byte *)(lVar4 + 0x1c0) * 0xc);
        *puVar2 = *puVar2 | 0x80000000;
      }
      goto LAB_000178c7;
    }
LAB_0001783a:
    return CONCAT71((int7)(uVar7 >> 8),4);
  }
  uVar7 = (ulonglong)*(byte *)(param_2 + 6) * 0x100;
  if (*(char *)(uVar7 + 0x3924 + param_1) == '\0') goto LAB_0001783a;
  cVar12 = *(char *)(lVar29 + 8);
  uVar10 = (undefined7)(uVar7 >> 8);
  if (cVar12 == '\0') {
    *(undefined1 *)(lVar4 + 0x10b0) = 1;
    *(undefined1 *)(lVar4 + 0x20) = 0;
    *(undefined1 *)(lVar4 + 0x22) = *(undefined1 *)(lVar29 + 0x40);
    *(undefined1 *)(lVar4 + 0x23) = *(undefined1 *)(lVar29 + 0x41);
    uVar23 = *(undefined1 *)(param_2 + 0x48);
    uVar7 = CONCAT71(uVar10,uVar23);
    *(undefined1 *)(lVar4 + 0x26) = 1;
    *(undefined1 *)(lVar4 + 0x24) = uVar23;
    *(uint *)(lVar4 + 0x34) = uVar24;
  }
  else {
    if (cVar12 == '\x01') {
      uVar3 = *(ushort *)(lVar29 + 10);
      cVar12 = '\0';
      uVar17 = 0;
      if (uVar3 != 0) {
LAB_000180f6:
        cVar28 = (char)uVar17;
        lVar14 = lVar29 + uVar17 * 2;
        uVar7 = (ulonglong)*(byte *)(uVar17 + 0x41 + lVar14);
        lVar14 = param_1 + (ulonglong)*(byte *)(uVar17 + 0x40 + lVar14) * 0xe28;
        if (cVar28 == '\0') {
          uVar31 = *(longlong *)(uVar7 * 0xc0 + 0x2c8 + lVar14) - 0x10;
        }
        else {
          uVar31 = *(longlong *)(uVar7 * 0xc0 + 0x2c8 + lVar14) - 0x4f;
        }
        if (uVar31 <= uVar20) {
          uVar7 = (ulonglong)uVar3;
          uVar20 = uVar20 - uVar31;
          if ((int)uVar17 + 1U != (uint)uVar3) goto code_r0x00018160;
          goto LAB_0001783a;
        }
        uVar7 = (uVar24 >> 9) + uVar20;
        if (uVar31 < uVar7) {
          iVar21 = (int)uVar31 - (int)uVar20;
          if (cVar28 != '\0') {
            uVar20 = uVar20 + 0x3f;
          }
          uVar30 = (int)uVar17 + 1;
          iVar25 = (uVar24 >> 9) - iVar21;
          bVar27 = 0;
          local_57 = (byte)uVar30;
          local_40 = CONCAT44(local_40._4_4_,iVar25);
          *(undefined1 *)(lVar4 + 0x10b0) = 2;
          do {
            puVar1 = (undefined1 *)((ulonglong)bVar27 * 0x1a8 + 0x20 + lVar4);
            puVar1[4] = *(undefined1 *)(param_2 + 0x48);
            *puVar1 = 0;
            if (bVar27 == 0) {
              lVar26 = (longlong)cVar28;
              lVar14 = lVar29 + lVar26 * 2;
              puVar1[2] = *(undefined1 *)(lVar26 + 0x40 + lVar14);
              uVar23 = *(undefined1 *)(lVar26 + 0x41 + lVar14);
              *(ulonglong *)(puVar1 + 0x18) = uVar20;
              iVar25 = iVar21;
            }
            else {
              lVar26 = (longlong)(char)uVar30;
              lVar14 = lVar29 + lVar26 * 2;
              puVar1[2] = *(undefined1 *)(lVar26 + 0x40 + lVar14);
              uVar23 = *(undefined1 *)(lVar26 + 0x41 + lVar14);
              *(undefined8 *)(puVar1 + 0x18) = 0x3f;
            }
            uVar7 = CONCAT71((int7)((ulonglong)bVar27 * 0x1a8 >> 8),uVar23);
            puVar1[0x1a0] = 0;
            puVar1[3] = uVar23;
            *(int *)(puVar1 + 0x14) = iVar25 << 9;
            if ((piVar6 != (int *)0x0) && (*piVar6 != 0)) {
              uVar7 = AHCIBuildSGList((longlong)piVar6,(longlong)puVar1,iVar25 << 9,&local_58,
                                      &local_50,&local_54);
              if (puVar1[0x1a0] == 0) {
                *(uint *)(puVar1 + 0xd0) = *(uint *)(puVar1 + 0xd0) | 0x80000000;
              }
              else {
                uVar7 = (ulonglong)(byte)puVar1[0x1a0];
                *(uint *)(puVar1 + uVar7 * 0xc + 0xc4) =
                     *(uint *)(puVar1 + uVar7 * 0xc + 0xc4) | 0x80000000;
              }
            }
            uVar30 = (uint)local_57;
            bVar27 = bVar27 + 1;
            puVar1[6] = 1;
            iVar25 = (int)local_40;
          } while (bVar27 < *(byte *)(lVar4 + 0x10b0));
          goto LAB_0001834e;
        }
        cVar12 = cVar28;
        if (cVar28 != '\0') {
          uVar20 = uVar20 + 0x3f;
        }
      }
LAB_000182ba:
      *(undefined1 *)(lVar4 + 0x10b0) = 1;
      lVar14 = (longlong)cVar12;
      *(undefined1 *)(lVar4 + 0x20) = 0;
      lVar29 = lVar29 + lVar14 * 2;
      *(undefined1 *)(lVar4 + 0x22) = *(undefined1 *)(lVar14 + 0x40 + lVar29);
      *(undefined1 *)(lVar4 + 0x23) = *(undefined1 *)(lVar14 + 0x41 + lVar29);
      uVar23 = *(undefined1 *)(param_2 + 0x48);
      uVar7 = CONCAT71((int7)(uVar7 >> 8),uVar23);
      *(undefined1 *)(lVar4 + 0x26) = 1;
      *(uint *)(lVar4 + 0x34) = uVar24;
      *(ulonglong *)(lVar4 + 0x38) = uVar20;
      *(undefined1 *)(lVar4 + 0x1c0) = 0;
      *(undefined1 *)(lVar4 + 0x24) = uVar23;
      if ((piVar6 != (int *)0x0) && (*piVar6 != 0)) {
        uVar7 = AHCIBuildSGList((longlong)piVar6,lVar4 + 0x20,uVar24,&local_58,&local_50,&local_54);
        if (*(byte *)(lVar4 + 0x1c0) == 0) {
          *(uint *)(lVar4 + 0xf0) = *(uint *)(lVar4 + 0xf0) | 0x80000000;
        }
        else {
          uVar7 = (ulonglong)*(byte *)(lVar4 + 0x1c0);
          puVar2 = (uint *)(lVar4 + 0xe4 + uVar7 * 0xc);
          *puVar2 = *puVar2 | 0x80000000;
        }
      }
LAB_0001834e:
      *(undefined1 *)(lVar4 + 0x10b0) = 1;
      goto LAB_000178c7;
    }
    if (cVar12 == '\x02') {
      local_48 = *(uint *)(lVar29 + 0xf4);
      puVar8 = (undefined8 *)(lVar4 + 0x38);
      lVar14 = 4;
      do {
        *(undefined1 *)(puVar8 + 0x31) = 0;
        *puVar8 = 0;
        *(undefined4 *)((longlong)puVar8 + -4) = 0;
        puVar8 = puVar8 + 0x35;
        lVar14 = lVar14 + -1;
      } while (lVar14 != 0);
      uVar30 = uVar24 >> 9;
      if (uVar30 + uVar20 < (ulonglong)(local_48 + 0x3f)) {
        *(ulonglong *)(lVar4 + 0x38) = uVar20;
        *(uint *)(lVar4 + 0x34) = uVar24;
        *(undefined1 *)(lVar4 + 0x22) = *(undefined1 *)(lVar29 + 0x40);
        uVar7 = (ulonglong)CONCAT31((int3)(local_48 + 0x3f >> 8),*(undefined1 *)(lVar29 + 0x41));
        *(undefined1 *)(lVar4 + 0x23) = *(undefined1 *)(lVar29 + 0x41);
        if ((piVar6 == (int *)0x0) || (*piVar6 == 0)) {
          *(undefined1 *)(lVar4 + 0x1c0) = 1;
        }
        else {
          uVar7 = AHCIBuildSGList((longlong)piVar6,lVar4 + 0x20,uVar24,&local_58,&local_50,&local_54
                                 );
        }
      }
      else {
        if (uVar20 < 0x3f) {
          *(ulonglong *)(lVar4 + 0x38) = uVar20;
          iVar21 = (local_48 - (int)uVar20) + 0x3f;
          *(undefined1 *)(lVar4 + 0x22) = *(undefined1 *)(lVar29 + 0x40);
          *(undefined1 *)(lVar4 + 0x23) = *(undefined1 *)(lVar29 + 0x41);
          uVar24 = iVar21 * 0x200;
          *(uint *)(lVar4 + 0x34) = uVar24;
          if ((piVar6 == (int *)0x0) || (*piVar6 == 0)) {
            *(undefined1 *)(lVar4 + 0x1c0) = 1;
          }
          else {
            AHCIBuildSGList((longlong)piVar6,lVar4 + 0x20,uVar24,&local_58,&local_50,&local_54);
          }
          uVar30 = uVar30 - iVar21;
          uVar20 = (ulonglong)local_48;
          uVar17 = 1;
        }
        else {
          uVar17 = (ulonglong)local_4c;
          uVar20 = uVar20 - 0x3f;
        }
        uVar7 = uVar20 / local_48;
        uVar20 = uVar20 % (ulonglong)local_48;
        if (uVar30 != 0) {
          uVar3 = *(ushort *)(lVar29 + 10);
          uVar31 = uVar7;
          uVar24 = local_48;
          local_40 = uVar7;
          do {
            uVar19 = uVar24 - (int)uVar20;
            if (uVar30 <= uVar19) {
              uVar19 = uVar30;
            }
            uVar17 = (uVar17 & 0xff) % (ulonglong)(longlong)(int)(uint)uVar3;
            lVar14 = (uVar17 & 0xff) * 0x1a8 + 0x20 + lVar4;
            if (*(char *)(lVar14 + 0x1a0) == '\0') {
              lVar13 = (longlong)(char)((uVar31 & 0xffffffff) % (ulonglong)uVar3);
              *(ulonglong *)(lVar14 + 0x18) =
                   (ulonglong)
                   ((int)((uVar31 & 0xffffffff) / (ulonglong)uVar3) * uVar24 + 0x3f + (int)uVar20);
              lVar26 = lVar29 + lVar13 * 2;
              *(undefined1 *)(lVar14 + 2) = *(undefined1 *)(lVar13 + 0x40 + lVar26);
              *(undefined1 *)(lVar14 + 3) = *(undefined1 *)(lVar13 + 0x41 + lVar26);
            }
            *(int *)(lVar14 + 0x14) = *(int *)(lVar14 + 0x14) + uVar19 * 0x200;
            uVar7 = 0;
            if ((piVar6 == (int *)0x0) || (*piVar6 == 0)) {
              *(undefined1 *)(lVar14 + 0x1a0) = 1;
            }
            else {
              uVar7 = AHCIBuildSGList((longlong)piVar6,lVar14,uVar19 << 9,&local_58,&local_50,
                                      &local_54);
              uVar24 = local_48;
            }
            uVar30 = uVar30 - uVar19;
            uVar31 = (ulonglong)((int)uVar31 + 1);
            uVar17 = (ulonglong)(byte)((char)uVar17 + 1);
            uVar20 = 0;
          } while (uVar30 != 0);
        }
      }
      lVar29 = 4;
      pbVar16 = (byte *)(lVar4 + 0x1c0);
      do {
        if (*pbVar16 != 0) {
          *(uint *)(pbVar16 + (ulonglong)*pbVar16 * 0xc + -0xdc) =
               *(uint *)(pbVar16 + (ulonglong)*pbVar16 * 0xc + -0xdc) | 0x80000000;
          pbVar16[-0x1a0] = 0;
          pbVar16[-0x19a] = 1;
          uVar7 = 0;
          pbVar16[-0x19c] = *(byte *)(param_2 + 0x48);
          *(char *)(lVar4 + 0x10b0) = *(char *)(lVar4 + 0x10b0) + '\x01';
        }
        pbVar16 = pbVar16 + 0x1a8;
        lVar29 = lVar29 + -1;
      } while (lVar29 != 0);
      goto LAB_000178c7;
    }
    if (cVar12 != '\x03') {
      if (cVar12 == '\x04') {
        local_48 = *(uint *)(lVar29 + 0xf4);
        lVar26 = 4;
        puVar8 = (undefined8 *)(lVar4 + 0x38);
        lVar14 = 4;
        do {
          *(undefined1 *)(puVar8 + 0x31) = 0;
          *puVar8 = 0;
          *(undefined4 *)((longlong)puVar8 + -4) = 0;
          puVar8 = puVar8 + 0x35;
          lVar14 = lVar14 + -1;
        } while (lVar14 != 0);
        uVar30 = uVar24 >> 9;
        if (uVar30 + uVar20 < (ulonglong)(local_48 + 0x3f)) {
          *(ulonglong *)(lVar4 + 0x38) = uVar20;
          *(uint *)(lVar4 + 0x34) = uVar24;
          *(undefined1 *)(lVar4 + 0x22) = *(undefined1 *)(lVar29 + 0x40);
          uVar7 = (ulonglong)CONCAT31((int3)(local_48 + 0x3f >> 8),*(undefined1 *)(lVar29 + 0x41));
          *(undefined1 *)(lVar4 + 0x23) = *(undefined1 *)(lVar29 + 0x41);
          if ((piVar6 == (int *)0x0) || (*piVar6 == 0)) {
            *(undefined1 *)(lVar4 + 0x1c0) = 1;
          }
          else {
            uVar7 = AHCIBuildSGList((longlong)piVar6,lVar4 + 0x20,uVar24,&local_58,&local_50,
                                    &local_54);
          }
        }
        else {
          if (uVar20 < 0x3f) {
            *(ulonglong *)(lVar4 + 0x38) = uVar20;
            iVar21 = (local_48 - (int)uVar20) + 0x3f;
            *(undefined1 *)(lVar4 + 0x22) = *(undefined1 *)(lVar29 + 0x40);
            *(undefined1 *)(lVar4 + 0x23) = *(undefined1 *)(lVar29 + 0x41);
            uVar24 = iVar21 * 0x200;
            *(uint *)(lVar4 + 0x34) = uVar24;
            if ((piVar6 == (int *)0x0) || (*piVar6 == 0)) {
              *(undefined1 *)(lVar4 + 0x1c0) = 1;
            }
            else {
              AHCIBuildSGList((longlong)piVar6,lVar4 + 0x20,uVar24,&local_58,&local_50,&local_54);
            }
            uVar20 = (ulonglong)local_48;
            uVar30 = uVar30 - iVar21;
            uVar24 = 1;
          }
          else {
            uVar20 = uVar20 - 0x3f;
            uVar24 = local_4c;
          }
          uVar7 = uVar20 / local_48;
          uVar20 = uVar20 % (ulonglong)local_48;
          uVar17 = uVar7;
          uVar19 = local_48;
          for (; uVar30 != 0; uVar30 = uVar30 - uVar18) {
            uVar18 = uVar19 - (int)uVar20;
            if (uVar30 <= uVar18) {
              uVar18 = uVar30;
            }
            uVar7 = (uVar17 & 0xffffffff) % 2;
            local_40._4_4_ = (undefined4)(local_40 >> 0x20);
            local_40 = CONCAT44(local_40._4_4_,(int)uVar7);
            uVar5 = local_40;
            local_4c = uVar24 & 1;
            lVar14 = (ulonglong)local_4c * 0x1a8 + 0x20 + lVar4;
            if (*(char *)(lVar14 + 0x1a0) == '\0') {
              local_40._0_1_ = (char)uVar7;
              lVar15 = (longlong)(char)local_40;
              *(ulonglong *)(lVar14 + 0x18) =
                   (ulonglong)((int)((uVar17 & 0xffffffff) / 2) * uVar19 + 0x3f + (int)uVar20);
              lVar13 = lVar29 + lVar15 * 2;
              *(undefined1 *)(lVar14 + 2) = *(undefined1 *)(lVar15 + 0x40 + lVar13);
              *(undefined1 *)(lVar14 + 3) = *(undefined1 *)(lVar15 + 0x41 + lVar13);
            }
            *(int *)(lVar14 + 0x14) = *(int *)(lVar14 + 0x14) + uVar18 * 0x200;
            uVar7 = 0;
            local_40 = uVar5;
            if ((piVar6 == (int *)0x0) || (*piVar6 == 0)) {
              *(undefined1 *)(lVar14 + 0x1a0) = 1;
            }
            else {
              uVar7 = AHCIBuildSGList((longlong)piVar6,lVar14,uVar18 << 9,&local_58,&local_50,
                                      &local_54);
              uVar19 = local_48;
            }
            uVar17 = (ulonglong)((int)uVar17 + 1);
            uVar24 = (uint)(byte)((char)local_4c + 1);
            uVar20 = 0;
          }
        }
        pbVar16 = (byte *)(lVar4 + 0x1c0);
        do {
          if (*pbVar16 != 0) {
            *(uint *)(pbVar16 + (ulonglong)*pbVar16 * 0xc + -0xdc) =
                 *(uint *)(pbVar16 + (ulonglong)*pbVar16 * 0xc + -0xdc) | 0x80000000;
            pbVar16[-0x1a0] = 0;
            pbVar16[-0x19a] = 1;
            uVar7 = 0;
            pbVar16[-0x19c] = *(byte *)(param_2 + 0x48);
            *(char *)(lVar4 + 0x10b0) = *(char *)(lVar4 + 0x10b0) + '\x01';
          }
          pbVar16 = pbVar16 + 0x1a8;
          lVar26 = lVar26 + -1;
        } while (lVar26 != 0);
        cVar12 = *(char *)(param_2 + 0x48);
        uVar7 = CONCAT71((int7)(uVar7 >> 8),cVar12);
        if ((cVar12 == '*') || (cVar12 == '/')) {
          bVar27 = *(byte *)(lVar4 + 0x10b0);
          bVar22 = 0;
          if (bVar27 != 0) {
            do {
              _Dst = (void *)((ulonglong)bVar27 * 0x1a8 + 0x20 + lVar4);
              pvVar9 = memcpy(_Dst,(void *)((ulonglong)bVar22 * 0x1a8 + 0x20 + lVar4),0x1a8);
              cVar12 = bVar22 + 2;
              bVar22 = bVar22 + 1;
              lVar26 = (longlong)cVar12;
              bVar27 = bVar27 + 1;
              lVar14 = lVar29 + lVar26 * 2;
              *(undefined1 *)((longlong)_Dst + 2) = *(undefined1 *)(lVar26 + 0x40 + lVar14);
              uVar23 = *(undefined1 *)(lVar26 + 0x41 + lVar14);
              uVar7 = CONCAT71((int7)((ulonglong)pvVar9 >> 8),uVar23);
              *(undefined1 *)((longlong)_Dst + 3) = uVar23;
            } while (bVar22 < *(byte *)(lVar4 + 0x10b0));
          }
          *(char *)(lVar4 + 0x10b0) = *(char *)(lVar4 + 0x10b0) + bVar22;
        }
      }
      goto LAB_000178c7;
    }
    if (*(char *)(param_2 + 0x48) != '(') {
      if (*(char *)(param_2 + 0x48) == '*') {
        *(undefined1 *)(lVar4 + 0x10b0) = 2;
        uVar17 = 0;
        do {
          local_58 = 0;
          local_50 = 0;
          lVar14 = lVar29 + uVar17 * 2;
          local_54 = 0;
          puVar1 = (undefined1 *)(uVar17 * 0x1a8 + 0x20 + lVar4);
          *puVar1 = 0;
          puVar1[2] = *(undefined1 *)(uVar17 + 0x40 + lVar14);
          uVar23 = *(undefined1 *)(uVar17 + 0x41 + lVar14);
          uVar7 = CONCAT71((int7)(uVar17 * 0x1a8 >> 8),uVar23);
          puVar1[4] = 0x2a;
          puVar1[6] = 1;
          *(uint *)(puVar1 + 0x14) = uVar24;
          *(ulonglong *)(puVar1 + 0x18) = uVar20;
          puVar1[3] = uVar23;
          puVar1[0x1a0] = 0;
          if ((piVar6 != (int *)0x0) && (*piVar6 != 0)) {
            uVar7 = AHCIBuildSGList((longlong)piVar6,(longlong)puVar1,uVar24,&local_58,&local_50,
                                    &local_54);
            if (puVar1[0x1a0] == 0) {
              *(uint *)(puVar1 + 0xd0) = *(uint *)(puVar1 + 0xd0) | 0x80000000;
            }
            else {
              uVar7 = (ulonglong)(byte)puVar1[0x1a0];
              *(uint *)(puVar1 + uVar7 * 0xc + 0xc4) =
                   *(uint *)(puVar1 + uVar7 * 0xc + 0xc4) | 0x80000000;
            }
          }
          bVar27 = (char)uVar17 + 1;
          uVar17 = (ulonglong)bVar27;
        } while (bVar27 < *(byte *)(lVar4 + 0x10b0));
      }
      else if (*(char *)(param_2 + 0x48) == '/') {
        *(undefined1 *)(lVar4 + 0x10b0) = 2;
        bVar27 = 0;
        do {
          uVar17 = (ulonglong)bVar27;
          bVar27 = bVar27 + 1;
          lVar14 = lVar29 + uVar17 * 2;
          lVar26 = uVar17 * 0x1a8;
          *(undefined1 *)(lVar26 + 0x20 + lVar4) = 0;
          *(undefined1 *)(lVar26 + 0x22 + lVar4) = *(undefined1 *)(uVar17 + 0x40 + lVar14);
          uVar23 = *(undefined1 *)(uVar17 + 0x41 + lVar14);
          uVar7 = CONCAT71((int7)(uVar7 >> 8),uVar23);
          *(undefined1 *)(lVar26 + 0x24 + lVar4) = 0x2f;
          *(undefined1 *)(lVar26 + 0x26 + lVar4) = 1;
          *(uint *)(lVar26 + 0x34 + lVar4) = uVar24;
          *(ulonglong *)(lVar26 + 0x38 + lVar4) = uVar20;
          *(undefined1 *)(lVar26 + 0x23 + lVar4) = uVar23;
        } while (bVar27 < *(byte *)(lVar4 + 0x10b0));
      }
      goto LAB_000178c7;
    }
    if (*(char *)(lVar29 + 0xfc) == '\x01') {
      bVar27 = *(byte *)(lVar29 + 0x40);
      uVar23 = *(undefined1 *)(lVar29 + 0x41);
      uVar7 = (ulonglong)bVar27 * 0xe28;
      if (*(char *)(uVar7 + 0x27e + param_1) != '\x01') {
        bVar27 = *(byte *)(lVar29 + 0x43);
        uVar23 = *(undefined1 *)(lVar29 + 0x44);
      }
      *(undefined1 *)(lVar4 + 0x10b0) = 1;
      *(undefined1 *)(lVar4 + 0x20) = 0;
      *(byte *)(lVar4 + 0x22) = bVar27;
      *(undefined1 *)(lVar4 + 0x23) = uVar23;
      *(longlong *)(lVar4 + 0x48) = param_2;
    }
    else {
      *(undefined1 *)(lVar4 + 0x10b0) = 1;
      *(undefined1 *)(lVar4 + 0x20) = 0;
      *(undefined1 *)(lVar4 + 0x22) = *(undefined1 *)(lVar29 + 0x40);
      uVar7 = CONCAT71(uVar10,*(undefined1 *)(lVar29 + 0x41));
      *(undefined1 *)(lVar4 + 0x23) = *(undefined1 *)(lVar29 + 0x41);
    }
    *(uint *)(lVar4 + 0x34) = uVar24;
    *(undefined1 *)(lVar4 + 0x26) = 1;
    *(undefined1 *)(lVar4 + 0x24) = 0x28;
  }
  lVar29 = lVar4 + 0x20;
  *(ulonglong *)(lVar4 + 0x38) = uVar20;
  *(undefined1 *)(lVar4 + 0x1c0) = 0;
  if ((piVar6 != (int *)0x0) && (*piVar6 != 0)) {
    uVar7 = AHCIBuildSGList((longlong)piVar6,lVar29,uVar24,&local_58,&local_50,&local_54);
    if (*(byte *)(lVar29 + 0x1a0) == 0) {
      *(uint *)(lVar29 + 0xd0) = *(uint *)(lVar29 + 0xd0) | 0x80000000;
    }
    else {
      uVar7 = (ulonglong)*(byte *)(lVar29 + 0x1a0);
      puVar2 = (uint *)(lVar29 + 0xc4 + uVar7 * 0xc);
      *puVar2 = *puVar2 | 0x80000000;
    }
  }
LAB_000178c7:
  uVar20 = 0;
  if (*(char *)(lVar4 + 0x10b0) != '\0') {
    do {
      lVar14 = uVar20 * 0x1a8;
      uVar7 = (ulonglong)*(byte *)(lVar14 + 0x23 + lVar4);
      lVar26 = (ulonglong)*(byte *)(lVar14 + 0x22 + lVar4) * 0xe28;
      lVar29 = uVar7 + lVar26;
      if (*(char *)(lVar29 + 0x1fa + param_1) == '\x11') {
        *(undefined1 *)(lVar14 + 0x25 + lVar4) = 0;
        *(undefined1 *)(lVar14 + 0x24 + lVar4) = 0xa0;
        *(undefined1 *)(lVar4 + 0x10b1) = 0;
        if ((*(byte *)(param_2 + 0xc) & 0x80) != 0) {
          *(undefined1 *)(lVar4 + 0x10b1) = 1;
        }
        uVar7 = uVar7 * 0xc0 + lVar26;
        if ((*(byte *)(uVar7 + 0x2c1 + param_1) & 0x20) != 0) {
          *(undefined1 *)(lVar14 + 0x25 + lVar4) = 1;
        }
      }
      else {
        lVar13 = uVar7 * 0xc0 + lVar26;
        if ((*(byte *)(lVar13 + 0x2c1 + param_1) & 0x20) == 0) {
LAB_00018402:
          *(undefined1 *)(lVar14 + 0x25 + lVar4) = 0;
        }
        else {
          bVar27 = *(byte *)(lVar26 + 0xd58 + param_1);
          lVar29 = CONCAT71((int7)((ulonglong)lVar29 >> 8),bVar27);
          if ((((bVar27 & 1) == 0) || ((bVar27 & 2) == 0)) || (*(char *)(param_1 + 0x768d) != '\0'))
          {
            *(undefined1 *)(lVar14 + 0x25 + lVar4) = 1;
          }
          else {
            *(undefined1 *)(lVar14 + 0x25 + lVar4) = 2;
          }
          if (*(char *)(lVar14 + 0x24 + lVar4) == '/') goto LAB_00018402;
        }
        cVar12 = *(char *)(param_2 + 0x48);
        uVar11 = (uint7)((ulonglong)lVar29 >> 8);
        uVar7 = CONCAT71(uVar11,cVar12);
        if ((cVar12 == '(') || (cVar12 == -0x78)) {
          *(undefined1 *)(lVar4 + 0x10b1) = 0;
          cVar12 = *(char *)(lVar14 + 0x25 + lVar4);
          if (cVar12 == '\0') {
            uVar7 = (ulonglong)uVar11 << 8;
            cVar12 = (-((*(byte *)(lVar13 + 0x2c1 + param_1) & 2) != 0) & 0x65U) - 0x3c;
          }
          else {
            if (cVar12 != '\x01') {
              if (cVar12 == '\x02') {
                *(undefined1 *)(lVar14 + 0x24 + lVar4) = 0x60;
              }
              goto LAB_00018537;
            }
            uVar7 = (ulonglong)uVar11 << 8;
            cVar12 = (-((*(byte *)(lVar13 + 0x2c1 + param_1) & 2) != 0) & 0x5dU) - 0x38;
          }
        }
        else {
          if ((cVar12 != '*') && (cVar12 != -0x76)) {
            if ((cVar12 == '/') || (cVar12 == -0x71)) {
              *(undefined1 *)(lVar4 + 0x10b1) = 0;
              uVar7 = CONCAT71(uVar11,*(undefined1 *)(lVar13 + 0x2c1 + param_1)) &
                      0xffffffffffffff02 | 0x40;
              *(char *)(lVar14 + 0x24 + lVar4) = (char)uVar7;
            }
            goto LAB_00018537;
          }
          *(undefined1 *)(lVar4 + 0x10b1) = 1;
          cVar12 = *(char *)(lVar14 + 0x25 + lVar4);
          if (cVar12 == '\0') {
            uVar7 = (ulonglong)uVar11 << 8;
            cVar12 = (-((*(byte *)(lVar13 + 0x2c1 + param_1) & 2) != 0) & 0x74U) - 0x3b;
          }
          else {
            if (cVar12 != '\x01') {
              if (cVar12 == '\x02') {
                *(undefined1 *)(lVar14 + 0x24 + lVar4) = 0x61;
              }
              goto LAB_00018537;
            }
            uVar7 = (ulonglong)uVar11 << 8;
            cVar12 = (-((*(byte *)(lVar13 + 0x2c1 + param_1) & 2) != 0) & 0x6bU) - 0x36;
          }
        }
        *(char *)(lVar14 + 0x24 + lVar4) = cVar12;
      }
LAB_00018537:
      if (*(char *)(param_2 + 0x48) == '/') {
        *(undefined1 *)(lVar14 + 0x1c0 + lVar4) = 0;
      }
      bVar27 = (char)uVar20 + 1;
      uVar20 = (ulonglong)bVar27;
    } while (bVar27 < *(byte *)(lVar4 + 0x10b0));
  }
  return CONCAT71((int7)(uVar7 >> 8),1);
code_r0x00018160:
  uVar7 = (ulonglong)(byte)(cVar28 + 1U);
  uVar17 = uVar7;
  if (uVar3 <= (byte)(cVar28 + 1U)) goto LAB_000182ba;
  goto LAB_000180f6;
}



===== AHCIRunCcb @ 00018578 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 AHCIRunCcb(longlong param_1,longlong param_2)

{
  char *pcVar1;
  char *pcVar2;
  byte bVar3;
  byte bVar4;
  char cVar5;
  uint uVar6;
  int iVar7;
  longlong lVar8;
  byte bVar9;
  undefined1 uVar10;
  longlong lVar11;
  undefined8 uVar12;
  ulonglong uVar13;
  undefined1 uVar14;
  undefined1 uVar15;
  undefined1 uVar17;
  undefined1 uVar16;
  uint uVar18;
  undefined1 uVar19;
  longlong lVar20;
  byte *pbVar21;
  ulonglong uVar22;
  ushort uVar23;
  bool bVar24;
  bool bVar25;
  undefined1 auStackY_b8 [32];
  undefined1 local_77;
  ushort local_76;
  undefined1 local_68 [4];
  char local_64;
  undefined1 local_63;
  undefined1 local_62;
  undefined1 local_61;
  undefined1 local_60;
  undefined1 local_5e;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_b8;
  lVar8 = *(longlong *)(param_2 + 0x38);
  local_77 = 0x78;
  bVar25 = false;
  if (*(char *)(lVar8 + 0x10b0) != '\0') {
    uVar22 = (ulonglong)*(byte *)(lVar8 + 0x10b0);
    pbVar21 = (byte *)(lVar8 + 0x23);
    do {
      lVar20 = (ulonglong)pbVar21[-1] * 0xe28;
      lVar11 = (ulonglong)*pbVar21 + lVar20;
      if (*(char *)(lVar11 + 0x1fa + param_1) == '\x01') {
        if (pbVar21[2] == 2) {
          lVar11 = (ulonglong)*pbVar21 * 0xc0 + lVar20;
          bVar3 = *(byte *)(lVar11 + 0x2d3 + param_1);
          uVar12 = CONCAT71((int7)((ulonglong)lVar11 >> 8),bVar3);
          bVar24 = *(byte *)(lVar20 + 0xe6c + param_1) < bVar3;
        }
        else {
          uVar12 = CONCAT71((int7)((ulonglong)lVar11 >> 8),*(byte *)(param_1 + 0x767c));
          bVar24 = *(byte *)(lVar20 + 0xe6d + param_1) < *(byte *)(param_1 + 0x767c);
        }
        if (!bVar24) {
          bVar25 = true;
        }
      }
      else {
        uVar12 = 0;
        if (*(byte *)(param_1 + 0x767c) + 2 <= (uint)*(byte *)(lVar20 + 0xe6d + param_1)) {
          bVar25 = true;
        }
      }
      pbVar21 = pbVar21 + 0x1a8;
      uVar22 = uVar22 - 1;
    } while (uVar22 != 0);
    if (bVar25) {
      *(undefined1 *)(param_2 + 3) = 5;
      return CONCAT71((int7)((ulonglong)uVar12 >> 8),5);
    }
  }
  *(byte *)(param_1 + 0x76b5) = *(byte *)(param_1 + 0x76b5) | 0x80;
  uVar22 = 0;
  *(undefined1 *)(param_1 + 0x76b4) = 0x27;
  local_76 = 0;
  uVar19 = 0x78;
  if (*(char *)(lVar8 + 0x10b0) != '\0') {
    do {
      pcVar1 = (char *)((uVar22 & 0xffff) * 0x1a8 + 0x20 + lVar8);
      bVar3 = pcVar1[2];
      uVar22 = (ulonglong)bVar3;
      bVar4 = pcVar1[3];
      lVar11 = uVar22 * 0xe28;
      if ((*(byte *)(param_1 + 0xe78 + lVar11) & 3) != 0) {
        lVar20 = *(longlong *)(param_1 + 0x58 + lVar11);
        uVar23 = 0;
        *(byte *)(lVar20 + 0x1b) = *(byte *)(lVar20 + 0x1b) & 0xf | 0x10;
        pbVar21 = (byte *)(param_1 + 0xe78 + lVar11);
        *pbVar21 = *pbVar21 & 0xfc;
        do {
          lVar20 = *(longlong *)(param_1 + 0x58 + lVar11);
          if (((*(byte *)(lVar20 + 0x29) & 0xf) != 6) && ((*(byte *)(lVar20 + 0x28) & 0xf) == 3))
          break;
          StorPortStallExecution(500);
          uVar23 = uVar23 + 1;
        } while (uVar23 < 20000);
        *(undefined4 *)(*(longlong *)(param_1 + 0x58 + lVar11) + 0x30) = 0xffffffff;
        lVar20 = 0x14;
        *(undefined4 *)(*(longlong *)(param_1 + 0x58 + lVar11) + 0x10) = 0xffffffff;
        do {
          StorPortStallExecution(500);
          lVar20 = lVar20 + -1;
        } while (lVar20 != 0);
      }
      uVar6 = *(uint *)(pcVar1 + 0x14);
      uVar12 = *(undefined8 *)(pcVar1 + 0x18);
      uVar18 = uVar6 >> 9;
      if ((*(byte *)(param_1 + 0xd58 + lVar11) & 0x20) != 0) {
        *(byte *)(param_1 + 0x76b5) = *(byte *)(param_1 + 0x76b5) & 0xe0;
        *(byte *)(param_1 + 0x76b5) = *(byte *)(param_1 + 0x76b5) | bVar4 & 0x1f;
      }
      lVar20 = (ulonglong)bVar4 + lVar11;
      cVar5 = *(char *)(lVar20 + 0x1fa + param_1);
      if (cVar5 == '\x01') {
        uVar16 = (undefined1)uVar18;
        bVar9 = (byte)((ulonglong)uVar12 >> 0x18);
        uVar19 = (undefined1)((ulonglong)uVar12 >> 8);
        uVar17 = (undefined1)(uVar18 >> 8);
        uVar14 = (undefined1)((ulonglong)uVar12 >> 0x10);
        if ((*(byte *)((ulonglong)bVar4 * 0xc0 + lVar11 + 0x2c1 + param_1) & 2) == 0) {
          if (*pcVar1 != '\0') goto LAB_0001891e;
          cVar5 = pcVar1[5];
          *(undefined1 *)(param_1 + 0x76c1) = 0;
          *(char *)(param_1 + 0x76b8) = (char)uVar12;
          *(undefined1 *)(param_1 + 0x76bd) = 0;
          *(undefined1 *)(param_1 + 0x76be) = 0;
          if (cVar5 != '\x02') {
            *(undefined1 *)(param_1 + 0x76c0) = uVar16;
            *(undefined1 *)(param_1 + 0x76bc) = 0;
            *(undefined1 *)(param_1 + 0x76b9) = uVar19;
            *(byte *)(param_1 + 0x76bb) = bVar9 & 0xf | 0xe0;
            goto LAB_000188f5;
          }
          *(undefined1 *)(param_1 + 0x76b7) = uVar16;
          *(byte *)(param_1 + 0x76bc) = bVar9;
          *(undefined1 *)(param_1 + 0x76c0) = 0;
          *(undefined1 *)(param_1 + 0x76bf) = uVar17;
          *(undefined1 *)(param_1 + 0x76ba) = uVar14;
          *(undefined1 *)(param_1 + 0x76b9) = uVar19;
          *(undefined1 *)(param_1 + 0x76bb) = 0x40;
        }
        else {
          if (*pcVar1 != '\0') {
LAB_0001891e:
            memcpy(local_68,(void *)(*(longlong *)(param_2 + 0x18) + 0x1c),0x21);
            *(undefined1 *)(param_1 + 0x76c0) = local_63;
            *(undefined1 *)(param_1 + 0x76b8) = local_62;
            *(char *)(param_1 + 0x76b7) = local_64;
            *(undefined1 *)(param_1 + 0x76b9) = local_61;
            *(undefined1 *)(param_1 + 0x76bf) = 0;
            *(undefined1 *)(param_1 + 0x76ba) = local_60;
            *(undefined1 *)(param_1 + 0x76c1) = 0;
            *(undefined1 *)(param_1 + 0x76bc) = 0;
            *(undefined1 *)(param_1 + 0x76bd) = 0;
            *(undefined1 *)(param_1 + 0x76be) = 0;
            *(undefined1 *)(param_1 + 0x76b6) = local_5e;
            *(undefined1 *)(param_1 + 0x76bb) = 0xe0;
            *(undefined1 *)(param_1 + 0x76c3) = 0;
            if (local_64 == -0x2a) {
              *(uint *)(param_2 + 0xc) = *(uint *)(param_2 + 0xc) & 0xffffffbf;
              *(uint *)(param_2 + 0xc) = *(uint *)(param_2 + 0xc) | 0x80;
            }
            else if (local_64 == -0x2b) {
              *(uint *)(param_2 + 0xc) = *(uint *)(param_2 + 0xc) & 0xffffff7f;
              *(uint *)(param_2 + 0xc) = *(uint *)(param_2 + 0xc) | 0x40;
            }
            goto LAB_00018aa2;
          }
          cVar5 = pcVar1[5];
          *(char *)(param_1 + 0x76b8) = (char)uVar12;
          *(byte *)(param_1 + 0x76bc) = bVar9;
          uVar10 = (undefined1)((ulonglong)uVar12 >> 0x20);
          uVar15 = (undefined1)((ulonglong)uVar12 >> 0x28);
          if (cVar5 == '\x02') {
            *(undefined1 *)(param_1 + 0x76b7) = uVar16;
            *(undefined1 *)(param_1 + 0x76b9) = uVar19;
            *(undefined1 *)(param_1 + 0x76c0) = 0;
            *(undefined1 *)(param_1 + 0x76bf) = uVar17;
            *(undefined1 *)(param_1 + 0x76c1) = 0;
            *(undefined1 *)(param_1 + 0x76bd) = uVar10;
            *(undefined1 *)(param_1 + 0x76bb) = 0x40;
            *(undefined1 *)(param_1 + 0x76be) = uVar15;
          }
          else {
            *(undefined1 *)(param_1 + 0x76c0) = uVar16;
            *(undefined1 *)(param_1 + 0x76b9) = uVar19;
            *(undefined1 *)(param_1 + 0x76c1) = uVar17;
            *(undefined1 *)(param_1 + 0x76bb) = 0xe0;
            *(undefined1 *)(param_1 + 0x76bd) = uVar10;
            *(undefined1 *)(param_1 + 0x76be) = uVar15;
LAB_000188f5:
            *(undefined1 *)(param_1 + 0x76bf) = 0;
            *(undefined1 *)(param_1 + 0x76b7) = 0;
          }
          *(undefined1 *)(param_1 + 0x76ba) = uVar14;
        }
        cVar5 = pcVar1[4];
        *(undefined1 *)(param_1 + 0x76c3) = 0;
        *(char *)(param_1 + 0x76b6) = cVar5;
      }
      else if (cVar5 == '\x11') {
        if (*(uint *)(param_2 + 0x10) < 0x10000) {
          *(undefined1 *)(param_1 + 0x76b9) = *(undefined1 *)(param_2 + 0x10);
          *(char *)(param_1 + 0x76ba) = (char)((uint)*(undefined4 *)(param_2 + 0x10) >> 8);
        }
        else {
          *(undefined1 *)(param_1 + 0x76b9) = 0xff;
          *(undefined1 *)(param_1 + 0x76ba) = 0xff;
        }
        if (pcVar1[5] == '\0') {
          *(undefined1 *)(param_1 + 0x76b7) = 0;
        }
        else if (pcVar1[5] == '\x01') {
          if ((*(byte *)(param_2 + 0xc) & 0x40) == 0) {
            if ((*(byte *)(param_2 + 0xc) & 0x80) != 0) {
              *(undefined1 *)(param_1 + 0x76b7) = 1;
            }
          }
          else {
            *(undefined1 *)(param_1 + 0x76b7) = 5;
          }
        }
        *(undefined1 *)(param_1 + 0x76c0) = 0;
        *(undefined1 *)(param_1 + 0x76b8) = 0;
        *(undefined1 *)(param_1 + 0x76bb) = 0xe0;
        *(char *)(param_1 + 0x76b6) = pcVar1[4];
      }
      else {
        pcVar1[6] = '\x04';
        *(undefined1 *)(param_2 + 3) = 4;
        pcVar2 = (char *)(lVar8 + 0x10b0);
        *pcVar2 = *pcVar2 + -1;
        if ((*pcVar2 == '\0') && (*(int *)(param_1 + 0xe68 + lVar11) == 0)) {
          StorPortDeviceReady(param_1,CONCAT31((uint3)(uVar6 >> 0x11),*(undefined1 *)(param_2 + 5)),
                              *(undefined1 *)(param_2 + 6));
        }
        StorPortNotification(0,param_1,param_2);
      }
LAB_00018aa2:
      bVar9 = pcVar1[0x1a0];
      *(byte *)(param_1 + 0x7694) = *(byte *)(param_1 + 0x7694) & 0x7f;
      *(ushort *)(param_1 + 0x7696) = (ushort)bVar9;
      *(byte *)(param_1 + 0x7695) = *(byte *)(param_1 + 0x7695) & 8 | bVar4 << 4;
      bVar9 = *(byte *)(lVar8 + 0x10b1);
      *(undefined4 *)(param_1 + 0x7698) = 0;
      *(byte *)(param_1 + 0x7694) = (bVar9 & 1) << 6 | *(byte *)(param_1 + 0x7694) & 0x85 | 5;
      if (*(char *)(lVar20 + 0x1fa + param_1) == '\x01') {
        if (pcVar1[5] == '\x02') {
          pcVar2 = (char *)(param_1 + 0xe6c + lVar11);
          *pcVar2 = *pcVar2 + '\x01';
          if (*(int *)(param_1 + 0xe64 + lVar11) == 0) {
            iVar7 = *(int *)(param_1 + 0xe60 + lVar11);
          }
          else {
            iVar7 = *(int *)(param_1 + 0xe68 + lVar11);
          }
          if (iVar7 != 0) {
LAB_00018ca9:
            uVar13 = AHCIGetFreeCommandSlot(param_1,bVar3,bVar4,'\x01');
            *(longlong *)(pcVar1 + 8) = param_2;
            *(char **)(param_1 + 0xd60 + (uVar22 * 0x1c5 + (uVar13 & 0xff)) * 8) = pcVar1;
            AHCIFillCommand(param_1,bVar3,bVar4,(void *)0x0,(longlong)(pcVar1 + 200),(byte)uVar13,
                            '\x01');
            goto LAB_00018d69;
          }
          uVar13 = AHCIGetFreeCommandSlot(param_1,bVar3,bVar4,'\0');
          *(longlong *)(pcVar1 + 8) = param_2;
          *(char **)(param_1 + 0xd60 + (uVar22 * 0x1c5 + (uVar13 & 0xff)) * 8) = pcVar1;
          *(undefined1 *)(param_1 + 0xe70 + lVar11) = *(undefined1 *)(param_1 + 0x76b6);
          uVar22 = AHCIFillCommand(param_1,bVar3,bVar4,(void *)0x0,(longlong)(pcVar1 + 200),
                                   (byte)uVar13,'\0');
          bVar3 = *(byte *)((ulonglong)bVar4 * 0xc0 + lVar11 + 0x2d3 + param_1);
          uVar22 = CONCAT71((int7)(uVar22 >> 8),bVar3);
          bVar25 = *(byte *)(param_1 + 0xe6c + lVar11) < bVar3;
        }
        else {
          pcVar2 = (char *)(param_1 + 0xe6d + lVar11);
          *pcVar2 = *pcVar2 + '\x01';
          if ((*(int *)(param_1 + 0xe64 + lVar11) != 0) ||
             (*(int *)(*(longlong *)(param_1 + 0x58 + lVar11) + 0x34) != 0)) goto LAB_00018ca9;
          uVar13 = AHCIGetFreeCommandSlot(param_1,bVar3,bVar4,'\0');
          *(longlong *)(pcVar1 + 8) = param_2;
          *(char **)(param_1 + 0xd60 + (uVar22 * 0x1c5 + (uVar13 & 0xff)) * 8) = pcVar1;
          uVar22 = AHCIFillCommand(param_1,bVar3,bVar4,(void *)0x0,(longlong)(pcVar1 + 200),
                                   (byte)uVar13,'\0');
          bVar25 = *(byte *)(param_1 + 0xe6d + lVar11) < *(byte *)(param_1 + 0x767c);
        }
        if (!bVar25) goto LAB_00018d69;
      }
      else {
        *(byte *)(param_1 + 0x7694) = *(byte *)(param_1 + 0x7694) | 0x20;
        uVar13 = AHCIGetFreeCommandSlot(param_1,bVar3,bVar4,'\0');
        *(longlong *)(pcVar1 + 8) = param_2;
        *(char **)(param_1 + 0xd60 + (uVar22 * 0x1c5 + (uVar13 & 0xff)) * 8) = pcVar1;
        AHCIFillCommand(param_1,bVar3,bVar4,(void *)(param_2 + 0x48),(longlong)(pcVar1 + 200),
                        (byte)uVar13,'\0');
        pcVar1 = (char *)(param_1 + 0xe6d + lVar11);
        *pcVar1 = *pcVar1 + '\x01';
LAB_00018d69:
        uVar22 = StorPortDeviceBusy(param_1,*(undefined1 *)(param_2 + 5),
                                    *(undefined1 *)(param_2 + 6));
        local_77 = 0;
      }
      local_76 = local_76 + 1;
      uVar22 = CONCAT62((int6)(uVar22 >> 0x10),local_76);
      uVar19 = local_77;
    } while (local_76 < *(byte *)(lVar8 + 0x10b0));
  }
  return CONCAT71((int7)(uVar22 >> 8),uVar19);
}



===== AHCIExecuteAtapiCommand @ 00018d98 =====

ulonglong AHCIExecuteAtapiCommand(longlong param_1,longlong param_2)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  longlong lVar4;
  ulonglong uVar5;
  
  lVar4 = (ulonglong)*(byte *)(param_2 + 6) * 0x100;
  bVar1 = *(byte *)(lVar4 + 0x3958 + param_1);
  bVar2 = *(byte *)(lVar4 + 0x3959 + param_1);
  if ((*(char *)(param_2 + 0x48) == '\x12') && (*(char *)(param_1 + 0x7686) != '\0')) {
    *(undefined1 *)(param_1 + 0x7686) = 0;
    StorPortNotification(7,param_1);
  }
  if ((*(char *)(param_2 + 7) == '\0') &&
     (*(short *)((ulonglong)*(byte *)(param_2 + 6) * 0x100 + 0x3922 + param_1) != 0)) {
    if (((*(byte *)(param_2 + 0xc) & 0x80) != 0) && ((*(uint *)(param_2 + 0x10) & 2) != 0)) {
      StorPortDebugPrint(0,"[FUNCTION] %s :Write Command : %x  Length %lx\n",
                         "AHCIExecuteAtapiCommand",*(undefined1 *)(param_2 + 0x48),
                         *(uint *)(param_2 + 0x10));
    }
    cVar3 = *(char *)(param_2 + 0x48);
    if (((cVar3 != '(') && (cVar3 != '*')) && (cVar3 != '/')) {
      AHCIBuildCcb(param_1,param_2,bVar1,bVar2);
    }
    uVar5 = AHCIRunCcb(param_1,param_2);
    uVar5 = uVar5 & 0xff;
  }
  else {
    uVar5 = 10;
  }
  return uVar5;
}



===== AHCIModeSense @ 00018e84 =====

undefined8 AHCIModeSense(undefined8 param_1,longlong param_2)

{
  int iVar1;
  undefined1 *puVar2;
  byte bVar3;
  undefined8 uVar4;
  
  iVar1 = *(int *)(param_2 + 0x10);
  bVar3 = *(byte *)(param_2 + 0x4a) & 0x3f;
  if ((bVar3 == 8) || (bVar3 == 0x3f)) {
    puVar2 = *(undefined1 **)(param_2 + 0x18);
    *puVar2 = 0;
    puVar2[1] = 0;
    puVar2[2] = 0x10;
    puVar2[3] = 0;
    if (iVar1 - 4U < 0xc) {
      *(undefined4 *)(param_2 + 0x10) = 4;
    }
    else {
      *puVar2 = 0xf;
      puVar2[4] = 8;
      puVar2[5] = 10;
      puVar2[6] = 4;
      puVar2[7] = 0;
      puVar2[8] = 0;
      puVar2[9] = 0;
      puVar2[10] = 0;
      puVar2[0xb] = 0;
      puVar2[0xc] = 0;
      puVar2[0xd] = 0;
      puVar2[0xe] = 0;
      puVar2[0xf] = 0;
      *(undefined4 *)(param_2 + 0x10) = 0x10;
    }
    uVar4 = 1;
  }
  else if (bVar3 == 0) {
    puVar2 = *(undefined1 **)(param_2 + 0x18);
    uVar4 = 1;
    *puVar2 = 0;
    puVar2[1] = 0;
    puVar2[2] = 0x10;
    puVar2[3] = 0;
    if (iVar1 - 4U < 8) {
      *(undefined4 *)(param_2 + 0x10) = 4;
    }
    else {
      puVar2[3] = 8;
      puVar2[4] = 0;
      puVar2[5] = 0;
      puVar2[6] = 0;
      puVar2[7] = 0;
      puVar2[8] = 0;
      puVar2[9] = 0;
      puVar2[10] = 1;
      puVar2[0xb] = 0;
      *(undefined4 *)(param_2 + 0x10) = 0xc;
    }
  }
  else {
    uVar4 = 6;
  }
  return uVar4;
}



===== AHCIExecuteIDECommand @ 00018f64 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong AHCIExecuteIDECommand(longlong param_1,longlong param_2)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  undefined1 *_Dst;
  undefined1 *_Dst_00;
  ulonglong uVar4;
  longlong lVar5;
  undefined8 uVar6;
  byte *pbVar7;
  undefined1 uVar8;
  uint uVar9;
  ulonglong uVar10;
  byte bVar11;
  undefined1 auStack_68 [32];
  undefined1 local_48;
  undefined1 local_47;
  undefined1 local_46;
  undefined1 local_44;
  undefined1 local_43;
  undefined1 local_42;
  undefined1 local_41;
  char local_40 [16];
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_68;
  _Dst = *(undefined1 **)(param_2 + 0x18);
  lVar5 = (ulonglong)*(byte *)(param_2 + 6) * 0x100;
  bVar1 = *(byte *)(lVar5 + 0x3958 + param_1);
  bVar2 = *(byte *)(lVar5 + 0x3959 + param_1);
  bVar11 = *(byte *)(param_2 + 0x48);
  if (bVar11 < 0x29) {
    if (bVar11 != 0x28) {
      if (bVar11 < 0x16) {
        if (bVar11 == 0x15) {
          return 6;
        }
        if (bVar11 == 0) {
          return 1;
        }
        if (bVar11 == 3) {
          memset(_Dst,0,(ulonglong)*(uint *)(param_2 + 0x10));
          *_Dst = 0x70;
          _Dst[2] = 5;
          _Dst[7] = 10;
          _Dst[0xc] = 0x24;
          _Dst[0xd] = 0;
          return 1;
        }
        if (bVar11 == 6) {
          return 6;
        }
        if (bVar11 == 0xc) {
          return 6;
        }
        if (bVar11 != 0x12) {
          return 6;
        }
        if (*(char *)(param_1 + 0x7686) != '\0') {
          *(undefined1 *)(param_1 + 0x7686) = 0;
          StorPortNotification(7);
        }
        if ((*(char *)(param_2 + 7) != '\0') ||
           (*(char *)((ulonglong)*(byte *)(param_2 + 6) * 0x100 + 0x3924 + param_1) == '\0')) {
          return 8;
        }
        _Dst_00 = *(undefined1 **)(param_2 + 0x18);
        local_48 = 0;
        builtin_strncpy(local_40,"SiS  driver",0xc);
        local_47 = 0x80;
        local_46 = 0x83;
        local_44 = 0;
        local_43 = 0x80;
        local_42 = 0;
        local_41 = 0x14;
        memset(_Dst_00,0,(ulonglong)*(uint *)(param_2 + 0x10));
        bVar11 = *(byte *)(param_2 + 0x49) & 1;
        if ((bVar11 == 0) && (*(char *)(param_2 + 0x4a) != '\0')) {
          *(undefined1 *)(param_2 + 4) = 2;
          return 1;
        }
        if (bVar11 == 0) {
          *_Dst_00 = 0;
          if ((*(byte *)((ulonglong)bVar2 * 0xc0 + 0x2c1 + param_1 + (ulonglong)bVar1 * 0xe28) & 1)
              != 0) {
            _Dst_00[1] = _Dst_00[1] | 0x80;
          }
          memcpy(_Dst_00 + 8,(void *)((ulonglong)*(byte *)(param_2 + 6) * 0x100 + 0x3930 + param_1),
                 0x18);
          _Dst_00[3] = _Dst_00[3] & 0xf2;
          _Dst_00[7] = _Dst_00[7] | 2;
          _Dst_00[3] = _Dst_00[3] | 2;
          _Dst_00[2] = _Dst_00[2] & 0xfc;
          _Dst_00[2] = _Dst_00[2] | 4;
          _Dst_00[0x20] = 0x31;
          _Dst_00[0x21] = 0x2e;
          _Dst_00[0x22] = 0x30;
          _Dst_00[0x23] = 0x30;
          return 1;
        }
        cVar3 = *(char *)(param_2 + 0x4a);
        if (cVar3 == '\0') {
          _Dst[3] = 3;
          if (*(uint *)(param_2 + 0x10) < 7) {
            return 4;
          }
          memcpy(_Dst + 4,&local_48,3);
          return 1;
        }
        if (cVar3 != -0x80) {
          if (cVar3 == -0x7d) {
            _Dst[1] = 0x83;
            _Dst[3] = 0x10;
            if (0x13 < *(uint *)(param_2 + 0x10)) {
              _Dst[4] = 1;
              _Dst[5] = 2;
              _Dst[7] = 0xc;
              memcpy(_Dst + 8,local_40,0xc);
              *(undefined4 *)(param_2 + 0x10) = 0x14;
              return 1;
            }
          }
          return 4;
        }
        memcpy(_Dst,&local_44,4);
        if (*(uint *)(param_2 + 0x10) < 0x18) {
          return 4;
        }
        memcpy(_Dst + 4,"01234567890000000000,",0x14);
        *(undefined4 *)(param_2 + 0x10) = 0x18;
        return 1;
      }
      if (bVar11 < 0x16) {
        return 6;
      }
      if (bVar11 < 0x18) {
        return 1;
      }
      if (bVar11 == 0x1a) {
        uVar10 = AHCIModeSense(param_1,param_2);
        return uVar10 & 0xffffffff;
      }
      if (bVar11 == 0x1b) {
        return 1;
      }
      if (bVar11 < 0x1d) {
        return 6;
      }
      if (bVar11 < 0x1f) {
        return 6;
      }
      if (bVar11 != 0x25) {
        return 6;
      }
      *(undefined4 *)(_Dst + 4) = 0x20000;
      uVar10 = *(ulonglong *)((ulonglong)*(byte *)(param_2 + 6) * 0x100 + 0x3928 + param_1);
      if (0xffffffff < uVar10) {
        uVar10 = 0x100000000;
      }
      if (uVar10 == 0) {
LAB_000192bf:
        **(undefined4 **)(param_2 + 0x18) = 0;
        return 1;
      }
      lVar5 = uVar10 - 1;
      uVar9 = (((uint)(byte)((ulonglong)lVar5 >> 8) | ((uint)lVar5 & 0xff) << 8) << 8 |
              (uint)(byte)((ulonglong)lVar5 >> 0x10)) << 8 | (uint)((ulonglong)lVar5 >> 0x18) & 0xff
      ;
LAB_000192b4:
      **(uint **)(param_2 + 0x18) = uVar9;
      return 1;
    }
  }
  else if (bVar11 < 0x89) {
    if (((bVar11 != 0x88) && (bVar11 != 0x2a)) && (bVar11 != 0x2f)) {
      if (bVar11 == 0x35) {
        uVar9 = 0;
        if (*(char *)(param_1 + 0x767e) != '\0') {
          lVar5 = *(longlong *)((ulonglong)bVar1 * 0xe28 + 0x58 + param_1);
          do {
            if (*(int *)(lVar5 + 0x38) != 0) {
              return 1;
            }
            if (*(int *)(lVar5 + 0x34) != 0) {
              return 1;
            }
            uVar9 = uVar9 + 1;
          } while (uVar9 < *(byte *)(param_1 + 0x767e));
        }
        return 1;
      }
      if (bVar11 < 0x56) {
        return 6;
      }
      if (bVar11 < 0x58) {
        return 1;
      }
      if (1 < bVar11 - 0x60) {
        return 6;
      }
      lVar5 = *(longlong *)(param_2 + 0x38);
      *(undefined1 *)(lVar5 + 0x12) = 0;
      *(undefined1 *)(lVar5 + 0x11) = 1;
      uVar8 = 0x2a;
      if (*(char *)(param_2 + 0x48) == '`') {
        uVar8 = 0x28;
      }
      *(undefined1 *)(param_2 + 0x48) = uVar8;
      uVar6 = AHCIBuildCcb(param_1,param_2,*(byte *)(param_2 + 0x4e),*(byte *)(param_2 + 0x52));
      if ((char)uVar6 != '\x04') {
        AHCIRunCcb(param_1,param_2);
      }
      return 0;
    }
  }
  else if ((bVar11 != 0x8a) && (bVar11 != 0x8f)) {
    if (bVar11 != 0x9e) {
      if (bVar11 == 0xa0) {
        memset(_Dst,0,(ulonglong)*(uint *)(param_2 + 0x10));
        _Dst[3] = 8;
        return 1;
      }
      return 6;
    }
    *(undefined4 *)(_Dst + 8) = 0x20000;
    lVar5 = *(longlong *)((ulonglong)*(byte *)(param_2 + 6) * 0x100 + 0x3928 + param_1);
    if (lVar5 == 0) goto LAB_000192bf;
    uVar10 = lVar5 - 1;
    *(uint *)(*(longlong *)(param_2 + 0x18) + 4) =
         (((uint)(byte)(uVar10 >> 8) | ((uint)uVar10 & 0xff) << 8) << 8 |
         (uint)(byte)(uVar10 >> 0x10)) << 8 | (uint)(byte)(uVar10 >> 0x18);
    uVar9 = (((uint)((uVar10 >> 0x20 & 0xff) << 8) | (uint)(byte)(uVar10 >> 0x28)) << 8 |
            (uint)(byte)(uVar10 >> 0x30)) << 8 | (uint)(byte)(uVar10 >> 0x38);
    goto LAB_000192b4;
  }
  if (*(byte *)(param_2 + 10) < 0x10) {
    uVar10 = (ulonglong)
             CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(param_2 + 0x4a),
                                        *(undefined1 *)(param_2 + 0x4b)),
                               *(undefined1 *)(param_2 + 0x4c)),*(undefined1 *)(param_2 + 0x4d));
  }
  else {
    uVar10 = 0;
    pbVar7 = (byte *)(param_2 + 0x4a);
    lVar5 = 8;
    do {
      bVar11 = *pbVar7;
      pbVar7 = pbVar7 + 1;
      uVar10 = uVar10 * 0x100 + (ulonglong)bVar11;
      lVar5 = lVar5 + -1;
    } while (lVar5 != 0);
  }
  *(undefined1 *)(*(longlong *)(param_2 + 0x38) + 0x11) = 0;
  lVar5 = (ulonglong)*(byte *)(param_2 + 6) * 0x100;
  if (*(char *)(lVar5 + 0x3924 + param_1) == '\0') {
    *(undefined1 *)(param_1 + 0x7686) = 1;
    StorPortNotification(7,param_1,0);
    return 8;
  }
  if ((*(char *)(param_2 + 0x48) != '/') && (*(int *)(param_2 + 0x10) == 0)) {
    return 1;
  }
  uVar4 = *(ulonglong *)(lVar5 + 0x3928 + param_1);
  if (uVar4 == 0) {
    uVar4 = *(ulonglong *)((ulonglong)bVar2 * 0xc0 + 0x2c8 + param_1 + (ulonglong)bVar1 * 0xe28);
  }
  if (uVar10 < uVar4) {
    uVar10 = AHCIRunCcb(param_1,param_2);
    return uVar10 & 0xff;
  }
  return 6;
}



===== AHCIRemoveSrb @ 00019584 =====

void AHCIRemoveSrb(longlong param_1,byte param_2)

{
  byte *pbVar1;
  char *pcVar2;
  uint *puVar3;
  byte bVar4;
  int iVar5;
  longlong lVar6;
  longlong lVar7;
  undefined8 uVar8;
  longlong lVar9;
  uint uVar10;
  uint uVar11;
  ulonglong uVar12;
  longlong lVar13;
  byte bVar14;
  ushort uVar15;
  ushort uVar16;
  ushort uVar17;
  bool bVar18;
  bool bVar19;
  longlong local_40;
  
  bVar14 = 0;
  uVar17 = 0;
  lVar7 = (ulonglong)param_2 * 0x100;
  bVar18 = *(short *)(lVar7 + 0x3922 + param_1) != 0;
  do {
    uVar11 = 0;
    if (!bVar18) {
      if (*(char *)(param_1 + 0x7682) != '\0') {
        bVar14 = *(byte *)(param_1 + 0x751a);
        bVar4 = *(byte *)(param_1 + 0x751b);
        uVar17 = 0;
        do {
          lVar7 = (ulonglong)uVar17 * 0x100;
          if (*(char *)(lVar7 + 0x3924 + param_1) == '\x01') {
            bVar18 = *(short *)(lVar7 + 0x3922 + param_1) != 0;
            uVar15 = 0;
            while (bVar18) {
              if (((*(char *)(lVar7 + ((ulonglong)uVar15 + 0x131e) * 3 + param_1) == 'Z') &&
                  (lVar13 = lVar7 + (ulonglong)uVar15 * 3,
                  (int)*(char *)(lVar13 + 0x3958 + param_1) == (uint)bVar14)) &&
                 ((int)*(char *)(lVar13 + 0x3959 + param_1) == (uint)bVar4)) {
                *(undefined1 *)(lVar7 + ((ulonglong)uVar15 + 0x131e) * 3 + param_1) = 0;
                *(undefined1 *)(lVar7 + 0x3924 + param_1) = 0;
                uVar11 = 1;
                break;
              }
              uVar15 = uVar15 + 1;
              bVar18 = uVar15 < *(ushort *)(lVar7 + 0x3922 + param_1);
            }
          }
        } while (((char)uVar11 != '\x01') && (uVar17 = uVar17 + 1, uVar17 < 0x3c));
      }
      if (*(char *)(param_1 + 0x7683) == '\x01') {
        bVar14 = *(byte *)(param_1 + 0x751a);
        *(undefined1 *)(param_1 + 0x7683) = 0;
        bVar18 = false;
        uVar17 = 0;
        do {
          lVar7 = (ulonglong)uVar17 * 0x100;
          if (*(char *)(lVar7 + 0x3924 + param_1) == '\x01') {
            uVar16 = 0;
            uVar15 = *(ushort *)(lVar7 + 0x3922 + param_1);
            bVar19 = uVar15 != 0;
            while (bVar19) {
              if (((*(char *)(lVar7 + ((ulonglong)uVar16 + 0x131e) * 3 + param_1) == 'Z') &&
                  (lVar13 = lVar7 + (ulonglong)uVar16 * 3,
                  (int)*(char *)(lVar13 + 0x3958 + param_1) == (uint)bVar14)) &&
                 (*(char *)(lVar13 + 0x3959 + param_1) == '\0')) {
                AHCIRemoveSrb(param_1,(char)uVar16 + (char)uVar17 * '\x0f');
                bVar18 = true;
                break;
              }
              uVar16 = uVar16 + 1;
              bVar19 = uVar16 < uVar15;
            }
          }
        } while ((!bVar18) && (uVar17 = uVar17 + 1, uVar17 < 0x3c));
      }
      return;
    }
    bVar4 = *(byte *)(lVar7 + (ulonglong)uVar17 * 3 + 0x3958 + param_1);
    if ((uVar17 == 0) || (bVar14 != bVar4)) {
      lVar13 = (ulonglong)bVar4 * 0xe28;
      pbVar1 = (byte *)(*(longlong *)(lVar13 + 0x58 + param_1) + 0x18);
      *pbVar1 = *pbVar1 & 0xfe;
      bVar14 = *(byte *)(*(longlong *)(lVar13 + 0x58 + param_1) + 0x19);
      while ((bVar14 & 0x80) != 0) {
        StorPortStallExecution(500);
        uVar11 = uVar11 + 1;
        if (999 < uVar11) {
          uVar8 = AHCIPortReset(param_1,bVar4);
          if (((char)uVar8 == '\0') &&
             ((*(byte *)(*(longlong *)(lVar13 + 0x58 + param_1) + 0x28) & 0xf) == 1)) {
            StorPortDebugPrint(0,
                               "[FUNCTION] %s :Can\'t recover from  the Port Reset procedure at port %d.\n"
                               ,"AHCIRemoveSrb",bVar4);
            *(undefined1 *)(lVar13 + 0xe6f + param_1) = 1;
          }
          break;
        }
        bVar14 = *(byte *)(*(longlong *)(lVar13 + 0x58 + param_1) + 0x19);
      }
      uVar12 = 0;
      if (*(char *)(param_1 + 0x767d) != '\0') {
        do {
          uVar11 = *(uint *)(lVar13 + 0xe60 + param_1);
          uVar10 = 1 << ((byte)uVar12 & 0x1f);
          if (((uVar10 & uVar11) != 0) || ((*(uint *)(lVar13 + 0xe68 + param_1) & uVar10) != 0)) {
            lVar9 = (ulonglong)bVar4 * 0x1c5 + uVar12;
            lVar6 = *(longlong *)(*(longlong *)(param_1 + 0xd60 + lVar9 * 8) + 8);
            if (*(byte *)(lVar6 + 6) == param_2) {
              uVar10 = ~uVar10;
              puVar3 = (uint *)(lVar13 + 0xe64 + param_1);
              *puVar3 = *puVar3 & uVar10;
              puVar3 = (uint *)(lVar13 + 0xe68 + param_1);
              *puVar3 = *puVar3 & uVar10;
              *(uint *)(lVar13 + 0xe60 + param_1) = uVar10 & uVar11;
              *(undefined8 *)(param_1 + 0xd60 + lVar9 * 8) = 0;
              local_40 = *(longlong *)(lVar6 + 0x38);
              pcVar2 = (char *)(local_40 + 0x10b0);
              *pcVar2 = *pcVar2 + -1;
              if (*pcVar2 == '\0') {
                *(undefined1 *)(lVar6 + 3) = 4;
                if (*(int *)(lVar13 + 0xe68 + param_1) == 0) {
                  StorPortDeviceReady(param_1,CONCAT31((int3)(uVar10 >> 8),
                                                       *(undefined1 *)(lVar6 + 5)),
                                      CONCAT31((int3)(uVar11 >> 8),*(undefined1 *)(lVar6 + 6)),
                                      *(undefined1 *)(lVar6 + 7));
                }
                StorPortNotification(0,param_1,lVar6);
              }
            }
          }
          uVar15 = (short)uVar12 + 1;
          uVar12 = (ulonglong)uVar15;
        } while (uVar15 < *(byte *)(param_1 + 0x767d));
      }
      if (((*(byte *)(lVar13 + 0xd58 + param_1) & 0x20) == 0) &&
         (*(char *)(param_1 + 0x7683) != '\x01')) {
        *(undefined4 *)(*(longlong *)(lVar13 + 0x58 + param_1) + 0x38) =
             *(undefined4 *)(lVar13 + 0xe60 + param_1);
        *(undefined4 *)(*(longlong *)(lVar13 + 0x58 + param_1) + 0x34) =
             *(undefined4 *)(lVar13 + 0xe64 + param_1);
        lVar6 = *(longlong *)(lVar13 + 0x58 + param_1);
        if ((((*(int *)(lVar6 + 0x38) == 0) && (*(int *)(lVar6 + 0x34) == 0)) &&
            (iVar5 = *(int *)(lVar13 + 0xe68 + param_1), iVar5 != 0)) &&
           (*(int *)(lVar6 + 0x38) = iVar5,
           *(char *)((ulonglong)uVar17 * 0x1a8 + 0x25 + local_40) == '\x02')) {
          *(undefined4 *)(*(longlong *)(lVar13 + 0x58 + param_1) + 0x34) =
               *(undefined4 *)(lVar13 + 0xe68 + param_1);
        }
        pbVar1 = (byte *)(*(longlong *)(lVar13 + 0x58 + param_1) + 0x18);
        *pbVar1 = *pbVar1 | 1;
      }
      else {
        *(undefined4 *)(lVar13 + 0xe60 + param_1) = 0;
        *(undefined4 *)(lVar13 + 0xe64 + param_1) = 0;
        *(undefined4 *)(lVar13 + 0xe68 + param_1) = 0;
      }
      bVar14 = bVar4;
    }
    uVar17 = uVar17 + 1;
    bVar18 = uVar17 < *(ushort *)(lVar7 + 0x3922 + param_1);
  } while( true );
}



===== AHCIProcessPlugoutDeviceRequest @ 00019a14 =====

void AHCIProcessPlugoutDeviceRequest(longlong param_1)

{
  byte bVar1;
  undefined1 uVar2;
  longlong lVar3;
  longlong lVar4;
  uint uVar5;
  byte bVar6;
  longlong lVar7;
  ushort uVar8;
  
  if (*(char *)(param_1 + 0x7683) == '\x01') {
    bVar1 = *(byte *)(param_1 + 0x751a);
    uVar8 = 0;
    if (*(char *)(param_1 + 0x767d) != '\0') {
      lVar7 = (ulonglong)bVar1 * 0xe28;
      do {
        uVar5 = 1 << ((byte)uVar8 & 0x1f);
        if ((((*(uint *)(param_1 + 0xe60 + lVar7) & uVar5) != 0) ||
            ((*(uint *)(param_1 + 0xe68 + lVar7) & uVar5) != 0)) &&
           (lVar3 = *(longlong *)
                     (param_1 + 0xd60 + ((ulonglong)bVar1 * 0x1c5 + (ulonglong)uVar8) * 8),
           lVar3 != 0)) {
          lVar4 = *(longlong *)(lVar3 + 8);
          *(undefined1 *)(param_1 + 0x751a) = *(undefined1 *)(lVar3 + 2);
          uVar2 = *(undefined1 *)(lVar3 + 3);
          *(undefined1 *)(param_1 + 0x7682) = 1;
          *(undefined1 *)(param_1 + 0x751b) = uVar2;
          AHCIRemoveSrb(param_1,*(byte *)(lVar4 + 6));
        }
        uVar8 = uVar8 + 1;
      } while (uVar8 < *(byte *)(param_1 + 0x767d));
    }
    lVar7 = (ulonglong)bVar1 * 0xe28;
    *(undefined8 *)(lVar7 + 0x1fa + param_1) = 0;
    *(undefined4 *)(lVar7 + 0x202 + param_1) = 0;
    *(undefined2 *)(lVar7 + 0x206 + param_1) = 0;
    *(undefined1 *)(lVar7 + 0x208 + param_1) = 0;
  }
  else {
    bVar1 = *(byte *)(param_1 + 0x751a);
    lVar7 = (ulonglong)bVar1 * 0xe28;
    if ((*(byte *)(lVar7 + 0xd58 + param_1) & 0x20) == 0) {
      bVar6 = 0;
    }
    else {
      bVar6 = *(byte *)(param_1 + 0x751b);
    }
    uVar8 = 0;
    *(undefined1 *)((ulonglong)bVar6 + lVar7 + 0x1fa + param_1) = 0;
    if (*(char *)(param_1 + 0x767d) != '\0') {
      do {
        uVar5 = 1 << ((byte)uVar8 & 0x1f);
        if ((((((*(uint *)(lVar7 + 0xe60 + param_1) & uVar5) != 0) ||
              ((*(uint *)(lVar7 + 0xe68 + param_1) & uVar5) != 0)) &&
             (lVar3 = *(longlong *)
                       (param_1 + 0xd60 + ((ulonglong)bVar1 * 0x1c5 + (ulonglong)uVar8) * 8),
             lVar3 != 0)) && (*(byte *)(lVar3 + 2) == bVar1)) &&
           (((*(byte *)(lVar7 + 0xd58 + param_1) & 0x20) == 0 || (*(byte *)(lVar3 + 3) == bVar6))))
        {
          AHCIRemoveSrb(param_1,*(byte *)(*(longlong *)(lVar3 + 8) + 6));
        }
        uVar8 = uVar8 + 1;
      } while (uVar8 < *(byte *)(param_1 + 0x767d));
    }
  }
  StorPortNotification(1,param_1,0);
  return;
}



===== AHCIGetTheHotPlugInDevice @ 00019bec =====

void AHCIGetTheHotPlugInDevice(longlong param_1)

{
  byte bVar1;
  longlong lVar2;
  
  bVar1 = 0;
  if (*(char *)(param_1 + 0x767e) != '\0') {
    do {
      if (*(char *)((ulonglong)bVar1 * 0xe28 + 0xe75 + param_1) == '\x01') {
        lVar2 = (ulonglong)bVar1 * 0xe28;
        *(undefined1 *)(param_1 + 0x7674) = *(undefined1 *)(lVar2 + 0xe73 + param_1);
        *(undefined1 *)(param_1 + 0x7675) = *(undefined1 *)(lVar2 + 0xe74 + param_1);
        *(undefined1 *)(lVar2 + 0xe75 + param_1) = 0;
        *(undefined1 *)(lVar2 + 0xe72 + param_1) = 0;
        return;
      }
      bVar1 = bVar1 + 1;
    } while (bVar1 < *(byte *)(param_1 + 0x767e));
  }
  *(undefined1 *)(param_1 + 0x7676) = 0;
  *(undefined1 *)(param_1 + 0x7677) = 1;
  *(undefined1 *)(param_1 + 0x7674) = 0xff;
  *(undefined1 *)(param_1 + 0x7675) = 0xff;
  return;
}



===== AHCIHotplugInCallBack @ 00019c74 =====

void AHCIHotplugInCallBack
               (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  byte *pbVar1;
  uint *puVar2;
  char *pcVar3;
  byte bVar4;
  char cVar5;
  undefined8 uVar6;
  byte bVar7;
  ulonglong uVar8;
  longlong lVar9;
  longlong lVar10;
  longlong lVar11;
  undefined4 uVar12;
  
  if (*(char *)(param_1 + 0x7677) == '\x01') {
    AHCIGetTheHotPlugInDevice(param_1);
  }
  bVar7 = *(byte *)(param_1 + 0x7674);
  bVar4 = *(byte *)(param_1 + 0x7675);
  uVar8 = 0;
  if (bVar7 == 0xff) {
    *(undefined1 *)(param_1 + 0x7677) = 1;
    if (*(char *)(param_1 + 0x767e) == '\0') {
      return;
    }
    do {
      if ((*(byte *)(uVar8 * 0xe28 + 0xe78 + param_1) & 0x40) != 0) {
        *(undefined1 *)(param_1 + 0x7684) = 1;
      }
      bVar7 = (char)uVar8 + 1;
      uVar8 = (ulonglong)bVar7;
    } while (bVar7 < *(byte *)(param_1 + 0x767e));
    return;
  }
  *(undefined1 *)(param_1 + 0x7677) = 0;
  lVar9 = (ulonglong)bVar7 * 0xe28;
  pbVar1 = (byte *)(*(longlong *)(lVar9 + 0x58 + param_1) + 0x18);
  *pbVar1 = *pbVar1 & 0xfe;
  *(undefined4 *)(*(longlong *)(lVar9 + 0x58 + param_1) + 0x14) = 0;
  *(undefined4 *)(*(longlong *)(lVar9 + 0x58 + param_1) + 0x30) = 0xffffffff;
  *(undefined4 *)(*(longlong *)(lVar9 + 0x58 + param_1) + 0x10) = 0xffffffff;
  if ((*(byte *)(lVar9 + 0xd58 + param_1) & 0x20) == 0) {
    *(byte *)(param_1 + 0x7748) = bVar7;
    *(byte *)(param_1 + 0x7749) = bVar4;
    *(undefined4 *)(param_1 + 0x774c) = 0xc;
    *(undefined4 *)(*(longlong *)(lVar9 + 0x58 + param_1) + 0x14) = 0;
    *(undefined4 *)(*(longlong *)(lVar9 + 0x58 + param_1) + 0x18) = 2;
    *(undefined2 *)(param_1 + 0x7518) = 0;
    pbVar1 = (byte *)(lVar9 + 0xd58 + param_1);
    *pbVar1 = *pbVar1 & 0x1f;
    *(undefined2 *)(lVar9 + 0x1f8 + param_1) = 0;
    *(undefined1 *)(lVar9 + 0xd5a + param_1) = 0;
    pbVar1 = (byte *)(*(longlong *)(lVar9 + 0x58 + param_1) + 0x18);
    *pbVar1 = *pbVar1 | 0x10;
    if (*(byte *)(lVar9 + 0xe72 + param_1) < 4) {
      lVar10 = 0x14;
      if (*(char *)(param_1 + 0x768c) == '\0') {
        lVar11 = *(longlong *)(lVar9 + 0x58 + param_1);
        *(byte *)(lVar11 + 0x2c) = *(byte *)(lVar11 + 0x2c) & 0xf1 | 1;
        do {
          StorPortStallExecution(500);
          lVar10 = lVar10 + -1;
        } while (lVar10 != 0);
        lVar10 = 0x14;
        pbVar1 = (byte *)(*(longlong *)(lVar9 + 0x58 + param_1) + 0x2c);
        *pbVar1 = *pbVar1 & 0xf0;
        do {
          StorPortStallExecution(500);
          lVar10 = lVar10 + -1;
        } while (lVar10 != 0);
      }
      else {
        pbVar1 = (byte *)(*(longlong *)(lVar9 + 0x58 + param_1) + 0x18);
        *pbVar1 = *pbVar1 & 0xfd;
        do {
          StorPortStallExecution(500);
          lVar10 = lVar10 + -1;
        } while (lVar10 != 0);
        lVar10 = 0x14;
        pbVar1 = (byte *)(*(longlong *)(lVar9 + 0x58 + param_1) + 0x18);
        *pbVar1 = *pbVar1 | 2;
        do {
          StorPortStallExecution(500);
          lVar10 = lVar10 + -1;
        } while (lVar10 != 0);
      }
    }
    lVar10 = 100;
    *(undefined4 *)(*(longlong *)(lVar9 + 0x58 + param_1) + 0x30) = 0xffffffff;
    do {
      StorPortStallExecution(500);
      lVar10 = lVar10 + -1;
    } while (lVar10 != 0);
    lVar10 = *(longlong *)(lVar9 + 0x58 + param_1);
    if (((*(byte *)(lVar10 + 0x28) & 0xf) == 3) &&
       ((*(int *)(lVar10 + 0x30) == 0 || ((*(uint *)(lVar10 + 0x30) & 0xfffdfdff) == 0)))) {
      if ((*(byte *)(lVar9 + 0xd58 + param_1) & 0x20) == 0) {
        param_3 = CONCAT71((int7)((ulonglong)param_3 >> 8),0xf);
        AHCIDeviceReset(param_1,bVar7,0xf);
      }
      if (*(char *)(param_1 + 0x7843) == '\0') {
        lVar10 = 200;
        do {
          StorPortStallExecution();
          lVar10 = lVar10 + -1;
        } while (lVar10 != 0);
      }
      lVar10 = 10;
      *(undefined4 *)(*(longlong *)(lVar9 + 0x58 + param_1) + 0x30) = 0xffffffff;
      *(undefined4 *)(*(longlong *)(lVar9 + 0x58 + param_1) + 0x10) = 0xffffffff;
      do {
        StorPortStallExecution(500);
        lVar10 = lVar10 + -1;
      } while (lVar10 != 0);
      lVar10 = *(longlong *)(lVar9 + 0x58 + param_1);
      if ((((*(byte *)(lVar10 + 0x20) & 0x80) == 0) && ((*(byte *)(lVar10 + 0x20) & 8) == 0)) &&
         ((*(byte *)(lVar10 + 0x20) & 1) == 0)) {
        pbVar1 = (byte *)(lVar9 + 0xd58 + param_1);
        *pbVar1 = *pbVar1 | 0x40;
        *(byte *)(lVar10 + 0x18) = *(byte *)(lVar10 + 0x18) | 1;
        uVar6 = AHCIDetectDevice(param_1,bVar7,CONCAT71((int7)((ulonglong)param_3 >> 8),1),param_4);
        if ((char)uVar6 != '\0') goto LAB_0001a1bf;
        pcVar3 = (char *)(lVar9 + 0xe72 + param_1);
        *pcVar3 = *pcVar3 + '\x01';
        if (*(byte *)(lVar9 + 0xe72 + param_1) < 10) {
          lVar10 = *(longlong *)(lVar9 + 0x58 + param_1);
          lVar11 = 0x14;
          *(byte *)(lVar10 + 0x2c) = *(byte *)(lVar10 + 0x2c) & 0xf1 | 1;
          do {
            StorPortStallExecution(500);
            lVar11 = lVar11 + -1;
          } while (lVar11 != 0);
          pbVar1 = (byte *)(*(longlong *)(lVar9 + 0x58 + param_1) + 0x2c);
          *pbVar1 = *pbVar1 & 0xf0;
          lVar10 = 0x14;
          do {
            lVar11 = lVar10;
            StorPortStallExecution(500);
            lVar10 = lVar11 + -1;
          } while (lVar10 != 0);
          StorPortNotification((int)lVar11 + 5,param_1,AHCIHotplugInCallBack,1000000);
        }
        *(byte *)(param_1 + 0x7748) = bVar7;
        *(byte *)(param_1 + 0x7749) = bVar4;
        *(undefined4 *)(param_1 + 0x774c) = 0xe;
        pbVar1 = (byte *)(*(longlong *)(lVar9 + 0x58 + param_1) + 0x18);
        *pbVar1 = *pbVar1 & 0xfe;
        *(undefined1 *)(lVar9 + 0x1fa + param_1) = 0x5a;
        *(undefined4 *)(*(longlong *)(lVar9 + 0x58 + param_1) + 0x14) = 0x78c000cb;
      }
      else {
        pcVar3 = (char *)(lVar9 + 0xe72 + param_1);
        *pcVar3 = *pcVar3 + '\x01';
        if (*(byte *)(lVar9 + 0xe72 + param_1) < 0x29) {
          if (*(char *)(lVar10 + 0x20) != '\x7f') goto LAB_0001a435;
        }
        else {
          *(byte *)(param_1 + 0x7748) = bVar7;
          *(byte *)(param_1 + 0x7749) = bVar4;
          *(undefined4 *)(param_1 + 0x774c) = 0xe;
          lVar10 = *(longlong *)(lVar9 + 0x58 + param_1);
        }
        *(undefined4 *)(lVar10 + 0x14) = 0x78c000cb;
        lVar9 = *(longlong *)(lVar9 + 0x58 + param_1);
        StorPortDebugPrint(0,"[FUNCTION] %s :PxDET %x PxIS %lx PxSERR %lx TFD %x\n",
                           "AHCIHotplugInCallBack",*(byte *)(lVar9 + 0x28) & 0xf,
                           *(undefined4 *)(lVar9 + 0x10),*(undefined4 *)(lVar9 + 0x30),
                           *(undefined1 *)(lVar9 + 0x20));
      }
    }
    else {
      pcVar3 = (char *)(lVar9 + 0xe72 + param_1);
      *pcVar3 = *pcVar3 + '\x01';
      if (*(byte *)(lVar9 + 0xe72 + param_1) < 0x29) {
        if ((*(byte *)(lVar10 + 0x28) & 0xf) != 0) {
LAB_0001a435:
          uVar6 = 1000000;
          goto LAB_0001a43b;
        }
      }
      else {
        *(byte *)(param_1 + 0x7748) = bVar7;
        *(byte *)(param_1 + 0x7749) = bVar4;
        *(undefined4 *)(param_1 + 0x774c) = 0xe;
        lVar10 = *(longlong *)(lVar9 + 0x58 + param_1);
      }
      StorPortDebugPrint(0,"[FUNCTION] %s :PxDET %x PxIS %lx PxSERR %lx\n","AHCIHotplugInCallBack",
                         *(byte *)(lVar10 + 0x28) & 0xf,*(undefined4 *)(lVar10 + 0x10),
                         *(undefined4 *)(lVar10 + 0x30));
      *(undefined4 *)(*(longlong *)(lVar9 + 0x58 + param_1) + 0x14) = 0x78c000cb;
    }
    pcVar3 = (char *)(param_1 + 0x7676);
    *pcVar3 = *pcVar3 + -1;
    cVar5 = *pcVar3;
    *(undefined1 *)(param_1 + 0x7677) = 1;
  }
  else {
    pbVar1 = (byte *)(*(longlong *)(lVar9 + 0x58 + param_1) + 0x18);
    *pbVar1 = *pbVar1 | 1;
    *(byte *)(param_1 + 0x7748) = bVar7;
    *(byte *)(param_1 + 0x7749) = bVar4;
    *(undefined4 *)(param_1 + 0x774c) = 0xc;
    uVar12 = 1;
    uVar6 = AHCIDetectSinglePMDevice
                      (param_1,bVar7,bVar4,CONCAT71((int7)((ulonglong)param_4 >> 8),bVar4));
    if ((char)uVar6 != '\x01') {
      *(byte *)(param_1 + 0x7748) = bVar7;
      *(byte *)(param_1 + 0x7749) = bVar4;
      *(undefined4 *)(param_1 + 0x774c) = 0xe;
      *(undefined1 *)(param_1 + 0x7682) = 0;
      *(undefined1 *)(lVar9 + 0xe71 + param_1) = 0;
      *(byte *)(lVar9 + 0xe73 + param_1) = bVar7;
      *(undefined1 *)(lVar9 + 0xe74 + param_1) = 0;
      if (*(char *)(lVar9 + 0xe75 + param_1) != '\x01') {
        *(undefined1 *)(lVar9 + 0xe75 + param_1) = 1;
        *(char *)(param_1 + 0x7676) = *(char *)(param_1 + 0x7676) + '\x01';
      }
      pbVar1 = (byte *)(lVar9 + 0xd58 + param_1);
      *pbVar1 = *pbVar1 & 0xdf;
      pbVar1 = (byte *)(lVar9 + 0xe78 + param_1);
      *pbVar1 = *pbVar1 & 0xbf;
      *(undefined1 *)(lVar9 + 0xe72 + param_1) = 0;
      *(undefined1 *)(param_1 + 0x7677) = 1;
      StorPortNotification(6,param_1,AHCIHotplugInCallBack,500000,uVar12);
      if (*(char *)(param_1 + 0x767e) == '\0') {
        return;
      }
      do {
        if ((*(byte *)(uVar8 * 0xe28 + 0xe78 + param_1) & 0x40) != 0) {
          *(undefined1 *)(param_1 + 0x7684) = 1;
        }
        bVar7 = (char)uVar8 + 1;
        uVar8 = (ulonglong)bVar7;
      } while (bVar7 < *(byte *)(param_1 + 0x767e));
      return;
    }
    param_4 = 0;
    AHCIRWTheSiSInfoSector(param_1,bVar7,bVar4,0);
    if (*(char *)((ulonglong)bVar4 + lVar9 + 0x1fa + param_1) == 'Z') {
      *(byte *)(param_1 + 0x7748) = bVar7;
      *(byte *)(param_1 + 0x7749) = bVar4;
      *(undefined4 *)(param_1 + 0x774c) = 0xe;
      *(undefined1 *)(param_1 + 0x7682) = 0;
      *(undefined1 *)(lVar9 + 0xe71 + param_1) = 0;
      *(byte *)(lVar9 + 0xe73 + param_1) = bVar7;
      *(undefined1 *)(lVar9 + 0xe74 + param_1) = 0;
      if (*(char *)(lVar9 + 0xe75 + param_1) != '\x01') {
        *(undefined1 *)(lVar9 + 0xe75 + param_1) = 1;
        *(char *)(param_1 + 0x7676) = *(char *)(param_1 + 0x7676) + '\x01';
      }
      pbVar1 = (byte *)(lVar9 + 0xd58 + param_1);
      *pbVar1 = *pbVar1 & 0xdf;
      pbVar1 = (byte *)(lVar9 + 0xe78 + param_1);
      *pbVar1 = *pbVar1 & 0xbf;
      *(undefined1 *)(lVar9 + 0xe72 + param_1) = 0;
      *(undefined1 *)(param_1 + 0x7677) = 1;
      StorPortNotification(6,param_1,AHCIHotplugInCallBack,500000,uVar12);
      if (*(char *)(param_1 + 0x767e) == '\0') {
        return;
      }
      do {
        if ((*(byte *)(uVar8 * 0xe28 + 0xe78 + param_1) & 0x40) != 0) {
          *(undefined1 *)(param_1 + 0x7684) = 1;
        }
        bVar7 = (char)uVar8 + 1;
        uVar8 = (ulonglong)bVar7;
      } while (bVar7 < *(byte *)(param_1 + 0x767e));
      return;
    }
LAB_0001a1bf:
    *(char *)(param_1 + 0x7676) = *(char *)(param_1 + 0x7676) + -1;
    *(undefined1 *)(param_1 + 0x7677) = 1;
    if (*(char *)(param_1 + 0x767f) != '\0') {
      AHCIGetRaidInfo(param_1,bVar7);
    }
    AHCICheckRaidInfo(param_1);
    lVar10 = *(longlong *)(lVar9 + 0x58 + param_1);
    if ((*(byte *)(lVar9 + 0xd58 + param_1) & 4) == 0) {
      *(undefined4 *)(lVar10 + 0x14) = 0x78c000cb;
      pbVar1 = (byte *)(lVar9 + 0xe78 + param_1);
      *pbVar1 = *pbVar1 & 0xc3;
    }
    else {
      *(undefined4 *)(lVar10 + 0x14) = 0x788000cb;
      *(byte *)(lVar9 + 0xe78 + param_1) = *(byte *)(lVar9 + 0xe78 + param_1) & 199 | 4;
    }
    if ((*(byte *)(lVar9 + 0xe78 + param_1) & 0x80) != 0) {
      puVar2 = (uint *)(*(longlong *)(lVar9 + 0x58 + param_1) + 0x14);
      *puVar2 = *puVar2 & 0xfffffff0;
    }
    if ((*(char *)(param_1 + 0x768f) != '\0') && ((*(byte *)(lVar9 + 0xd58 + param_1) & 0x20) != 0))
    {
      puVar2 = (uint *)(*(longlong *)(lVar9 + 0x58 + param_1) + 0x14);
      *puVar2 = *puVar2 | 8;
    }
    uVar6 = 0;
    *(undefined1 *)(param_1 + 0x7686) = 1;
    lVar10 = param_1;
    StorPortNotification(7);
    if ((*(byte *)(lVar9 + 0xd58 + param_1) & 0x20) != 0) {
      *(byte *)(param_1 + 0x751a) = bVar7;
      *(undefined1 *)(param_1 + 0x7685) = 1;
      AHCIInterrupt(param_1,lVar10,uVar6,param_4);
    }
    lVar10 = *(longlong *)(lVar9 + 0x58 + param_1);
    if ((*(byte *)(lVar10 + 0x1b) & 4) != 0) {
      pbVar1 = (byte *)(lVar10 + 0x1b);
      *pbVar1 = *pbVar1 & 0xf7;
      pbVar1 = (byte *)(*(longlong *)(lVar9 + 0x58 + param_1) + 0x1b);
      *pbVar1 = *pbVar1 & 0xfb;
    }
    pbVar1 = (byte *)(lVar9 + 0xd58 + param_1);
    *pbVar1 = *pbVar1 & 0xfe;
    bVar7 = *(byte *)(lVar9 + 0xd58 + param_1);
    if ((bVar7 & 0x20) == 0) {
      *(byte *)(lVar9 + 0xd58 + param_1) =
           (*(byte *)(lVar9 + 0x2c1 + param_1) >> 6 ^ bVar7) & 1 ^ bVar7;
    }
    bVar7 = 0;
    if (*(char *)(param_1 + 0x767e) != '\0') {
      do {
        if ((*(byte *)((ulonglong)bVar7 * 0xe28 + 0xe78 + param_1) & 0x40) != 0) {
          *(undefined1 *)(param_1 + 0x7684) = 1;
        }
        bVar7 = bVar7 + 1;
      } while (bVar7 < *(byte *)(param_1 + 0x767e));
    }
    *(undefined1 *)(lVar9 + 0xe6d + param_1) = 0;
    *(undefined1 *)(lVar9 + 0xe6c + param_1) = 0;
    AHCIWmiFireEvent(param_1);
    *(bool *)(param_1 + 0x7688) = *(char *)(param_1 + 0x7687) == '\0';
    if (*(char *)(param_1 + 0x7677) != '\x01') {
      return;
    }
    cVar5 = *(char *)(param_1 + 0x7676);
  }
  if (cVar5 == '\0') {
    return;
  }
  AHCIGetTheHotPlugInDevice(param_1);
  *(undefined1 *)(param_1 + 0x7677) = 0;
  uVar6 = 500000;
LAB_0001a43b:
  StorPortNotification(6,param_1,AHCIHotplugInCallBack,uVar6);
  return;
}



===== AHCIDisableInterruptsCallback @ 0001a474 =====

undefined8
AHCIDisableInterruptsCallback
          (undefined8 param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  longlong lVar4;
  byte bVar5;
  longlong lVar6;
  longlong lVar7;
  ulonglong uVar8;
  undefined8 uVar9;
  uint local_res10 [2];
  
  bVar2 = *(byte *)(param_2 + 0x751a);
  bVar3 = *(byte *)(param_2 + 0x751b);
  lVar7 = (ulonglong)bVar2 * 0xe28;
  if (((*(byte *)(lVar7 + 0xd58 + param_2) & 0x20) == 0) || (*(char *)(param_2 + 0x7683) != '\0')) {
    bVar5 = *(byte *)(*(longlong *)(lVar7 + 0x58 + param_2) + 0x28) & 0xf;
  }
  else {
    uVar9 = CONCAT71((int7)((ulonglong)param_4 >> 8),0xf);
    local_res10[0] = 0;
    AHCIPMReadWrite(param_2,bVar2,bVar3,uVar9,-0x1c,0,local_res10);
    bVar5 = (byte)local_res10[0];
    local_res10[0] = 0xffffffff;
    AHCIPMReadWrite(param_2,bVar2,bVar3,CONCAT71((int7)((ulonglong)uVar9 >> 8),0xf),-0x18,1,
                    local_res10);
  }
  if (((bVar5 == 0) || (bVar5 == 1)) || (*(char *)(param_2 + 0x7682) == '\x01')) {
    AHCIProcessPlugoutDeviceRequest(param_2);
    AHCICheckRaidInfo(param_2);
    if (*(char *)(param_2 + 0x7682) != '\0') {
      *(byte *)(param_2 + 0x7748) = bVar2;
      *(undefined1 *)(param_2 + 0x7749) = 0;
      *(undefined4 *)(param_2 + 0x774c) = 0xd;
      AHCIWmiFireEvent(param_2);
    }
    if (*(char *)(param_2 + 0x7683) == '\x01') {
      *(undefined1 *)(param_2 + 0x7683) = 0;
      *(undefined1 *)(param_2 + 0x7682) = 0;
      *(undefined1 *)(lVar7 + 0xe71 + param_2) = 0;
      *(byte *)(lVar7 + 0xe73 + param_2) = bVar2;
      *(undefined1 *)(lVar7 + 0xe74 + param_2) = 0;
      *(undefined1 *)(lVar7 + 0xe75 + param_2) = 1;
      *(char *)(param_2 + 0x7676) = *(char *)(param_2 + 0x7676) + '\x01';
      pbVar1 = (byte *)(lVar7 + 0xd58 + param_2);
      *pbVar1 = *pbVar1 & 0xdf;
      *(undefined1 *)(lVar7 + 0xe72 + param_2) = 0;
      StorPortNotification(6,param_2,AHCIHotplugInCallBack,200000);
      *(undefined1 *)(param_2 + 0x7686) = 1;
      lVar4 = StorPortNotification(7,param_2);
      pbVar1 = (byte *)(lVar7 + 0xd58 + param_2);
      *pbVar1 = *pbVar1 & 0xfb;
      goto LAB_0001a6bf;
    }
    *(undefined1 *)(param_2 + 0x7686) = 1;
    StorPortNotification(7,param_2);
    pbVar1 = (byte *)(lVar7 + 0xd58 + param_2);
    *pbVar1 = *pbVar1 & 0xfb;
  }
  else if (*(char *)(param_2 + 0x7682) == '\0') {
    *(undefined1 *)(lVar7 + 0xe72 + param_2) = 0;
    lVar4 = StorPortNotification(6,param_2,AHCIHotplugInCallBack);
    *(undefined4 *)(*(longlong *)(lVar7 + 0x58 + param_2) + 0x14) = 0x78c000cb;
    goto LAB_0001a6bf;
  }
  lVar4 = *(longlong *)(lVar7 + 0x58 + param_2);
  if (*(byte *)(lVar7 + 0xe71 + param_2) < 5) {
    *(undefined4 *)(lVar4 + 0x14) = 0x78c000cb;
  }
  else {
    *(undefined4 *)(lVar4 + 0x14) = 0x788000cb;
  }
  lVar4 = *(longlong *)(lVar7 + 0x58 + param_2);
  if (*(char *)(lVar4 + 0x20) == -0x80) {
    *(undefined4 *)(lVar4 + 0x18) = 0x10;
    lVar4 = 10;
    do {
      lVar6 = lVar4;
      StorPortStallExecution(500);
      lVar4 = lVar6 + -1;
    } while (lVar4 != 0);
    uVar8 = (ulonglong)((int)lVar6 + 0x13);
    *(undefined4 *)(*(longlong *)(lVar7 + 0x58 + param_2) + 0x18) = 0x12;
    do {
      lVar4 = StorPortStallExecution(500);
      uVar8 = uVar8 - 1;
    } while (uVar8 != 0);
  }
  *(undefined1 *)(param_2 + 0x7683) = 0;
LAB_0001a6bf:
  return CONCAT71((int7)((ulonglong)lVar4 >> 8),1);
}



===== AHCIEnableInterruptsCallback @ 0001a6e0 =====

undefined8 AHCIEnableInterruptsCallback(undefined8 param_1,longlong param_2)

{
  byte *pbVar1;
  byte bVar2;
  undefined8 uVar3;
  byte bVar4;
  longlong lVar5;
  byte bVar6;
  ulonglong uVar7;
  undefined4 local_res10 [6];
  
  bVar6 = *(byte *)(param_2 + 0x751a);
  bVar4 = *(byte *)(param_2 + 0x751b);
  lVar5 = (ulonglong)bVar6 * 0xe28;
  *(undefined4 *)(*(longlong *)(lVar5 + 0x58 + param_2) + 0x14) = 0;
  *(undefined4 *)(*(longlong *)(lVar5 + 0x58 + param_2) + 0x30) = 0xffffffff;
  *(undefined4 *)(*(longlong *)(lVar5 + 0x58 + param_2) + 0x10) = 0xffffffff;
  **(undefined4 **)(param_2 + 0x20) = *(undefined4 *)(lVar5 + 0xe7c + param_2);
  bVar2 = *(byte *)(lVar5 + 0xd58 + param_2);
  if ((bVar2 & 4) != 0) {
    if ((*(byte *)(*(longlong *)(lVar5 + 0x58 + param_2) + 0x28) & 0xf) == 0) {
      *(byte *)(lVar5 + 0xd58 + param_2) = bVar2 & 0xbf;
      if ((bVar2 & 0x20) != 0) {
        *(undefined1 *)(param_2 + 0x7683) = 1;
      }
    }
    else if (*(char *)(lVar5 + 0xe75 + param_2) != '\x01') {
      *(undefined1 *)(param_2 + 0x7682) = 0;
      *(undefined1 *)(lVar5 + 0xe71 + param_2) = 0;
      *(byte *)(lVar5 + 0xe73 + param_2) = bVar6;
      *(undefined1 *)(lVar5 + 0xe74 + param_2) = 0;
      if (*(char *)(lVar5 + 0xe75 + param_2) != '\x01') {
        *(undefined1 *)(lVar5 + 0xe75 + param_2) = 1;
        *(char *)(param_2 + 0x7676) = *(char *)(param_2 + 0x7676) + '\x01';
      }
    }
  }
  bVar2 = *(byte *)(lVar5 + 0xd58 + param_2);
  if ((bVar2 & 0x20) == 0) {
    if (*(char *)(param_2 + 0x7682) == '\x01') {
      *(undefined1 *)(lVar5 + 0x1fa + param_2) = 0;
      *(undefined4 *)(*(longlong *)(lVar5 + 0x58 + param_2) + 0x18) = 0;
    }
  }
  else if (*(char *)(param_2 + 0x7683) == '\0') {
    if (*(char *)(param_2 + 0x7682) == '\x01') {
      *(undefined1 *)((ulonglong)bVar4 + lVar5 + 0x1fa + param_2) = 0;
    }
  }
  else {
    *(byte *)(lVar5 + 0xd58 + param_2) = bVar2 & 0xdf;
    pbVar1 = (byte *)(*(longlong *)(lVar5 + 0x58 + param_2) + 0x1a);
    *pbVar1 = *pbVar1 & 0xfd;
    *(byte *)((ulonglong)*(byte *)(param_2 + 0x767a) + 0x7670 + param_2) = bVar6;
    *(char *)(param_2 + 0x767a) = *(char *)(param_2 + 0x767a) + -1;
    *(undefined1 *)(lVar5 + 0x1fa + param_2) = 0;
    *(undefined4 *)(*(longlong *)(lVar5 + 0x58 + param_2) + 0x18) = 0;
    if (*(byte *)(param_2 + 0x767a) != 0) {
      bVar4 = 0;
      do {
        if (*(byte *)((ulonglong)bVar4 + 0x7670 + param_2) == bVar6) break;
        bVar4 = bVar4 + 1;
      } while (bVar4 <= (**(byte **)(param_2 + 0x10) & 0x1f));
      bVar6 = bVar4;
      if (bVar4 <= *(byte *)(param_2 + 0x767a)) {
        do {
          uVar7 = (ulonglong)bVar6;
          if (*(byte *)(param_2 + 0x767a) <= bVar4) break;
          bVar6 = bVar6 + 1;
          *(undefined1 *)(uVar7 + 0x7670 + param_2) = *(undefined1 *)(uVar7 + 0x7671 + param_2);
        } while (bVar6 <= *(byte *)(param_2 + 0x767a));
      }
    }
  }
  local_res10[0] = 0;
  uVar3 = StorPortNotification(0x1002,param_2,param_2 + 0x77b0,0,0,local_res10);
  return CONCAT71((int7)((ulonglong)uVar3 >> 8),1);
}



===== AHCIPMHotplugEventDetect @ 0001a8c4 =====

ulonglong AHCIPMHotplugEventDetect
                    (longlong param_1,undefined8 param_2,undefined8 param_3,ulonglong param_4)

{
  byte *pbVar1;
  uint uVar2;
  bool bVar3;
  bool bVar4;
  char cVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  char *pcVar8;
  byte bVar9;
  ulonglong uVar10;
  longlong lVar11;
  char *pcVar12;
  code *pcVar13;
  byte bVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  ulonglong uVar17;
  char cVar18;
  uint uVar19;
  uint local_res8 [2];
  uint local_res10 [2];
  undefined8 in_stack_ffffffffffffffa8;
  undefined7 uVar20;
  undefined4 uVar21;
  
  uVar10 = 0;
  cVar18 = '\0';
  bVar4 = false;
  local_res8[0] = local_res8[0] & 0xffffff00;
  StorPortDebugPrint(0,&s__s_,"AHCIPMHotplugEventDetect");
  uVar7 = param_4 & 0xffffffffffffff00;
  bVar9 = *(byte *)((ulonglong)*(byte *)(param_1 + 0x7679) + 0x7670 + param_1);
  uVar17 = (ulonglong)*(byte *)(param_1 + 0x7679);
  do {
    uVar6 = (ulonglong)bVar9 * 0xe28;
    if ((*(byte *)(uVar6 + 0xe78 + param_1) & 0x40) != 0) break;
    bVar14 = (char)uVar7 + 1;
    uVar7 = CONCAT71((int7)(uVar7 >> 8),bVar14);
    uVar6 = (ulonglong)((int)uVar17 + 1U & 0xff) %
            (ulonglong)(longlong)(int)(uint)*(byte *)(param_1 + 0x767a);
    *(char *)(param_1 + 0x7679) = (char)uVar6;
    bVar9 = *(byte *)(uVar6 + 0x7670 + param_1);
    uVar17 = uVar6;
  } while (bVar14 < 4);
  lVar11 = (ulonglong)bVar9 * 0xe28;
  if (((*(byte *)(lVar11 + 0xe78 + param_1) & 0x40) == 0) ||
     ((*(byte *)(lVar11 + 0xd58 + param_1) & 0x20) == 0)) {
    *(undefined1 *)(param_1 + 0x7684) = 0;
    pbVar1 = (byte *)(lVar11 + 0xe78 + param_1);
    *pbVar1 = *pbVar1 & 0xbf;
    return uVar6;
  }
  uVar16 = CONCAT71((int7)((ulonglong)in_stack_ffffffffffffffa8 >> 8),0xe4);
  cVar5 = AHCIPMReadWrite(param_1,bVar9,0xf,CONCAT71((int7)(uVar7 >> 8),0xf),-0x1c,0x20,local_res10)
  ;
  uVar19 = local_res10[0];
  if (cVar5 == '\x01') {
    pcVar12 = "AHCIPMHotplugEventDetect";
    uVar17 = (ulonglong)local_res10[0];
    StorPortDebugPrint(0,"[FUNCTION]%s:GSCR32 %lx\n");
    if (uVar19 != 0) {
      bVar14 = 0;
      uVar2 = uVar19;
      while (((uVar2 & 1) == 0 &&
             (bVar14 = bVar14 + 1, bVar14 < *(byte *)(lVar11 + 0xd59 + param_1)))) {
        uVar2 = uVar19 >> (bVar14 & 0x1f);
      }
      local_res10[0] = uVar19 & ~(1 << (bVar14 & 0x1f));
      if (local_res10[0] == 0) {
        pbVar1 = (byte *)(lVar11 + 0xe78 + param_1);
        *pbVar1 = *pbVar1 & 0xbf;
      }
      if (*(byte *)(lVar11 + 0xd59 + param_1) <= bVar14) goto LAB_0001b134;
      uVar21 = (undefined4)((ulonglong)uVar16 >> 0x20);
      cVar18 = AHCIPMReadWrite(param_1,bVar9,bVar14,CONCAT71((int7)(uVar17 >> 8),0xf),-0x1c,1,
                               local_res10);
      uVar19 = local_res10[0];
      if (cVar18 != '\x01') goto LAB_0001b0ca;
      pcVar12 = "AHCIPMHotplugEventDetect";
      uVar17 = (ulonglong)local_res10[0];
      StorPortDebugPrint(0,"[FUNCTION]%s:PSERR %lx\n");
      if ((*(byte *)(lVar11 + 0xd58 + param_1) & 4) != 0) {
        if ((uVar19 >> 0x1a & 1) == 0) {
          uVar17 = CONCAT71((int7)(uVar17 >> 8),0xf);
          pcVar12 = (char *)CONCAT71((int7)((ulonglong)pcVar12 >> 8),bVar14);
          AHCIPMReadWrite(param_1,bVar9,bVar14,uVar17,-0x1c,1,local_res10);
          if ((uVar19 & 0xf00) == 0x100) {
            uVar19 = local_res10[0];
          }
          else {
            uVar16 = CONCAT71((int7)(uVar17 >> 8),0xf);
            local_res10[0] = 1;
            AHCIPMReadWrite(param_1,bVar9,bVar14,uVar16,-0x18,2,local_res10);
            uVar16 = CONCAT71((int7)((ulonglong)uVar16 >> 8),0xf);
            local_res10[0] = 0;
            AHCIPMReadWrite(param_1,bVar9,bVar14,uVar16,-0x18,2,local_res10);
            local_res10[0] = 0xffffffff;
            uVar16 = CONCAT71((int7)((ulonglong)uVar16 >> 8),0xf);
            AHCIPMReadWrite(param_1,bVar9,bVar14,uVar16,-0x18,1,local_res10);
            AHCIPMReadWrite(param_1,bVar9,bVar14,CONCAT71((int7)((ulonglong)uVar16 >> 8),0xf),-0x1c,
                            1,local_res10);
            uVar17 = (ulonglong)local_res10[0];
            StorPortDebugPrint(0,"[FUNCTION]%s:PSERR %lx\n","AHCIPMHotplugEventDetect",uVar17);
            AHCIPMReadWrite(param_1,bVar9,bVar14,CONCAT71((int7)(uVar17 >> 8),0xf),-0x1c,0,
                            local_res10);
            uVar19 = local_res10[0];
            pcVar12 = "AHCIPMHotplugEventDetect";
            uVar17 = (ulonglong)local_res10[0];
            StorPortDebugPrint(0,"[FUNCTION]%s:PSSTS %lx\n");
          }
          if (uVar19 != 0) {
            if (*(char *)((ulonglong)bVar14 + lVar11 + 0x1fa + param_1) != '\0') goto LAB_0001b134;
            goto LAB_0001b02e;
          }
          if (*(char *)((ulonglong)bVar14 + lVar11 + 0x1fa + param_1) == '\0') goto LAB_0001b134;
          *(byte *)(param_1 + 0x751a) = bVar9;
          *(byte *)(param_1 + 0x751b) = bVar14;
          *(undefined1 *)(param_1 + 0x7682) = 1;
          uVar21 = 0;
          *(undefined1 *)(param_1 + 0x7686) = 1;
          local_res8[0] = 0;
          StorPortNotification(0x1002,param_1,param_1 + 0x7768,0,0,local_res8);
          pcVar8 = "[FUNCTION] %s :Plug out at Port %d subport %d \n";
        }
        else {
LAB_0001b02e:
          *(undefined1 *)(param_1 + 0x7682) = 0;
          *(undefined1 *)(lVar11 + 0xe71 + param_1) = 0;
          *(undefined1 *)(param_1 + 0x7686) = 1;
          *(byte *)(lVar11 + 0xe73 + param_1) = bVar9;
          *(byte *)(lVar11 + 0xe74 + param_1) = bVar14;
          *(undefined1 *)(lVar11 + 0xe75 + param_1) = 1;
          *(char *)(param_1 + 0x7676) = *(char *)(param_1 + 0x7676) + '\x01';
          *(byte *)(param_1 + 0x751b) = bVar14;
          *(byte *)(param_1 + 0x751a) = bVar9;
          if (*(char *)(param_1 + 0x7686) == '\x01') {
            uVar21 = 0;
            local_res8[0] = 0;
            StorPortNotification(0x1002,param_1,param_1 + 0x7768,0,0,local_res8);
          }
          pcVar8 = "[FUNCTION] %s :Plug In at Port %d subport %d \n";
        }
        pcVar12 = "AHCIPMHotplugEventDetect";
        uVar17 = (ulonglong)bVar9;
        StorPortDebugPrint(0,pcVar8,"AHCIPMHotplugEventDetect",uVar17,CONCAT44(uVar21,(uint)bVar14))
        ;
        goto LAB_0001b134;
      }
      if ((uVar19 >> 0x1a & 1) == 0) {
        if ((uVar19 >> 0x10 & 1) != 0) {
          *(undefined1 *)(param_1 + 0x7682) = 1;
          *(undefined1 *)(param_1 + 0x7686) = 1;
          pcVar8 = "[FUNCTION] %s :Plug out at Port %d subport %d \n";
          goto LAB_0001adda;
        }
      }
      else {
        *(undefined1 *)(param_1 + 0x7682) = 0;
        *(undefined1 *)(lVar11 + 0xe71 + param_1) = 0;
        *(undefined1 *)(param_1 + 0x7686) = 1;
        *(byte *)(lVar11 + 0xe73 + param_1) = bVar9;
        *(byte *)(lVar11 + 0xe74 + param_1) = bVar14;
        *(undefined1 *)(lVar11 + 0xe75 + param_1) = 1;
        *(char *)(param_1 + 0x7676) = *(char *)(param_1 + 0x7676) + '\x01';
        pcVar8 = "[FUNCTION] %s :Plug In at Port %d subport %d \n";
LAB_0001adda:
        pcVar12 = "AHCIPMHotplugEventDetect";
        uVar17 = (ulonglong)bVar9;
        *(byte *)(param_1 + 0x751a) = bVar9;
        *(byte *)(param_1 + 0x751b) = bVar14;
        StorPortDebugPrint(0,pcVar8,"AHCIPMHotplugEventDetect",uVar17,CONCAT44(uVar21,(uint)bVar14))
        ;
      }
      if (*(char *)(param_1 + 0x7686) == '\x01') {
        pcVar12 = (char *)(param_1 + 0x7768);
        uVar17 = 0;
        local_res8[0] = 0;
        StorPortNotification(0x1002,param_1,pcVar12,0,0,local_res8);
      }
      goto LAB_0001b134;
    }
    bVar14 = *(byte *)(*(longlong *)(lVar11 + 0x58 + param_1) + 0x29) & 0xf;
    bVar3 = false;
    if (bVar14 != 1) {
      bVar3 = false;
      if (bVar14 != 0) {
        bVar3 = true;
      }
    }
    if ((((*(byte *)(lVar11 + 0xd58 + param_1) & 4) != 0) && (bVar3)) &&
       (bVar14 = 0, *(char *)(lVar11 + 0xd59 + param_1) != '\0')) {
      do {
        uVar15 = CONCAT71((int7)(uVar17 >> 8),0xf);
        uVar20 = (undefined7)((ulonglong)uVar16 >> 8);
        local_res10[0] = 1;
        AHCIPMReadWrite(param_1,bVar9,bVar14,uVar15,-0x18,2,local_res10);
        uVar16 = CONCAT71((int7)((ulonglong)uVar15 >> 8),0xf);
        local_res10[0] = 0;
        AHCIPMReadWrite(param_1,bVar9,bVar14,uVar16,-0x18,2,local_res10);
        local_res10[0] = 0xffffffff;
        uVar16 = CONCAT71((int7)((ulonglong)uVar16 >> 8),0xf);
        AHCIPMReadWrite(param_1,bVar9,bVar14,uVar16,-0x18,1,local_res10);
        AHCIPMReadWrite(param_1,bVar9,bVar14,CONCAT71((int7)((ulonglong)uVar16 >> 8),0xf),-0x1c,1,
                        local_res10);
        uVar17 = (ulonglong)local_res10[0];
        StorPortDebugPrint(0,"[FUNCTION]%s:PSERR %lx\n","AHCIPMHotplugEventDetect",uVar17);
        uVar16 = CONCAT71(uVar20,0xe4);
        AHCIPMReadWrite(param_1,bVar9,bVar14,CONCAT71((int7)(uVar17 >> 8),0xf),-0x1c,0,local_res10);
        uVar17 = (ulonglong)local_res10[0];
        pcVar12 = "AHCIPMHotplugEventDetect";
        StorPortDebugPrint(0,"[FUNCTION]%s:PSSTS %lx\n");
        uVar21 = (undefined4)((ulonglong)uVar16 >> 0x20);
        if (local_res10[0] == 0) {
          if (*(char *)((ulonglong)bVar14 + lVar11 + 0x1fa + param_1) != '\0') {
            if ((char)local_res8[0] == '\0') {
              bVar4 = true;
LAB_0001ab7f:
              local_res8[0] = CONCAT31(local_res8[0]._1_3_,1);
            }
LAB_0001ab87:
            cVar18 = cVar18 + '\x01';
          }
        }
        else if (*(char *)((ulonglong)bVar14 + lVar11 + 0x1fa + param_1) == '\0') {
          if ((char)local_res8[0] == '\0') {
            bVar4 = false;
            goto LAB_0001ab7f;
          }
          goto LAB_0001ab87;
        }
        bVar14 = bVar14 + 1;
      } while (bVar14 < *(byte *)(lVar11 + 0xd59 + param_1));
      if (cVar18 != '\0') {
        if (bVar4) {
          *(byte *)(param_1 + 0x751a) = bVar9;
          *(byte *)(param_1 + 0x751b) = bVar14;
          *(undefined1 *)(param_1 + 0x7682) = 1;
          uVar21 = 0;
          *(undefined1 *)(param_1 + 0x7686) = 1;
          local_res8[0] = 0;
          StorPortNotification(0x1002,param_1,param_1 + 0x7768,0,0,local_res8);
          pcVar8 = "[FUNCTION] %s :Plug out at Port %d subport %d \n";
          uVar16 = CONCAT44(uVar21,(uint)bVar14);
        }
        else {
          if (bVar4) goto LAB_0001acb6;
          *(undefined1 *)(param_1 + 0x7682) = 0;
          *(undefined1 *)(lVar11 + 0xe71 + param_1) = 0;
          *(undefined1 *)(param_1 + 0x7686) = 1;
          *(byte *)(lVar11 + 0xe73 + param_1) = bVar9;
          *(byte *)(lVar11 + 0xe74 + param_1) = bVar14;
          *(undefined1 *)(lVar11 + 0xe75 + param_1) = 1;
          *(char *)(param_1 + 0x7676) = *(char *)(param_1 + 0x7676) + '\x01';
          *(byte *)(param_1 + 0x751a) = bVar9;
          *(byte *)(param_1 + 0x751b) = bVar14;
          if (*(char *)(param_1 + 0x7686) == '\x01') {
            uVar21 = 0;
            local_res8[0] = 0;
            StorPortNotification(0x1002,param_1,param_1 + 0x7768,0,0,local_res8);
          }
          pcVar8 = "[FUNCTION] %s :Plug In at Port %d subport %d \n";
          uVar16 = CONCAT44(uVar21,(uint)bVar14);
        }
        pcVar12 = "AHCIPMHotplugEventDetect";
        uVar17 = (ulonglong)bVar9;
        StorPortDebugPrint(0,pcVar8,"AHCIPMHotplugEventDetect",uVar17,uVar16);
        cVar18 = cVar18 + -1;
      }
LAB_0001acb6:
      if (cVar18 != '\0') goto LAB_0001b134;
    }
  }
  else {
LAB_0001b0ca:
    *(undefined1 *)(param_1 + 0x7682) = 0;
    *(undefined1 *)(lVar11 + 0xe74 + param_1) = 0;
    *(byte *)(lVar11 + 0xe73 + param_1) = bVar9;
    *(undefined1 *)(lVar11 + 0xe71 + param_1) = 0;
    if (*(char *)(lVar11 + 0xe75 + param_1) != '\x01') {
      *(undefined1 *)(lVar11 + 0xe75 + param_1) = 1;
      *(char *)(param_1 + 0x7676) = *(char *)(param_1 + 0x7676) + '\x01';
    }
    pbVar1 = (byte *)(lVar11 + 0xd58 + param_1);
    *pbVar1 = *pbVar1 & 0xdf;
    pcVar13 = AHCIHotplugInCallBack;
    uVar17 = 500000;
    *(undefined1 *)(lVar11 + 0xe72 + param_1) = 0;
    StorPortNotification(6,param_1);
    pcVar12 = (char *)pcVar13;
  }
  pbVar1 = (byte *)(lVar11 + 0xe78 + param_1);
  *pbVar1 = *pbVar1 & 0xbf;
LAB_0001b134:
  if (*(char *)(param_1 + 0x767e) != '\0') {
    do {
      if ((*(byte *)(uVar10 * 0xe28 + 0xe78 + param_1) & 0x40) != 0) {
        *(undefined1 *)(param_1 + 0x7684) = 1;
      }
      bVar9 = (char)uVar10 + 1;
      uVar10 = (ulonglong)bVar9;
    } while (bVar9 < *(byte *)(param_1 + 0x767e));
  }
  uVar10 = (ulonglong)(byte)(*(char *)(param_1 + 0x7679) + 1);
  uVar7 = uVar10 / (ulonglong)(longlong)(int)(uint)*(byte *)(param_1 + 0x767a);
  uVar10 = uVar10 % (ulonglong)(longlong)(int)(uint)*(byte *)(param_1 + 0x767a);
  *(char *)(param_1 + 0x7679) = (char)uVar10;
  if (*(char *)(param_1 + 0x7685) == '\x01') {
    uVar7 = AHCIInterrupt(param_1,uVar10,pcVar12,uVar17);
  }
  return uVar7;
}



===== AHCISlumberEnableRoutine @ 0001b1c4 =====

void AHCISlumberEnableRoutine(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  byte bVar3;
  ulonglong uVar4;
  
  uVar4 = 0;
  if (*(char *)(param_1 + 0x767e) != '\0') {
    do {
      lVar1 = uVar4 * 0xe28;
      bVar3 = *(byte *)(param_1 + 0xe78 + lVar1);
      if (((bVar3 & 0x20) != 0) && ((bVar3 & 3) == 1)) {
        lVar2 = *(longlong *)(param_1 + 0x58 + lVar1);
        *(byte *)(param_1 + 0xe78 + lVar1) = bVar3 & 0xfe | 2;
        if ((*(int *)(lVar2 + 0x38) == 0) &&
           ((*(int *)(lVar2 + 0x34) == 0 && ((*(byte *)(lVar2 + 0x18) & 1) != 0)))) {
          *(byte *)(lVar2 + 0x1b) = *(byte *)(lVar2 + 0x1b) & 0xf;
          *(byte *)(lVar2 + 0x1b) = *(byte *)(lVar2 + 0x1b) | 0x10;
          lVar2 = 10;
          do {
            StorPortStallExecution(500);
            lVar2 = lVar2 + -1;
          } while (lVar2 != 0);
          lVar1 = *(longlong *)(param_1 + 0x58 + lVar1);
          *(byte *)(lVar1 + 0x1b) = *(byte *)(lVar1 + 0x1b) & 0xf | 0x60;
        }
      }
      bVar3 = (char)uVar4 + 1;
      uVar4 = (ulonglong)bVar3;
    } while (bVar3 < *(byte *)(param_1 + 0x767e));
  }
  return;
}



===== AHCIPartialEnableRoutine @ 0001b280 =====

void AHCIPartialEnableRoutine(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  byte bVar3;
  ulonglong uVar4;
  
  uVar4 = 0;
  if (*(char *)(param_1 + 0x767e) != '\0') {
    do {
      lVar2 = uVar4 * 0xe28;
      bVar3 = *(byte *)(lVar2 + 0xe78 + param_1);
      if ((((bVar3 & 0x10) != 0) || ((bVar3 & 0x20) != 0)) && ((bVar3 & 3) == 0)) {
        lVar1 = *(longlong *)(lVar2 + 0x58 + param_1);
        *(byte *)(lVar2 + 0xe78 + param_1) = bVar3 & 0xfd | 1;
        if (((*(int *)(lVar1 + 0x38) == 0) && (*(int *)(lVar1 + 0x34) == 0)) &&
           ((*(byte *)(lVar1 + 0x18) & 1) != 0)) {
          if ((bVar3 & 0x10) != 0) {
            *(byte *)(lVar1 + 0x1b) = *(byte *)(lVar1 + 0x1b) & 0xf;
            *(byte *)(lVar1 + 0x1b) = *(byte *)(lVar1 + 0x1b) | 0x20;
          }
          if ((*(byte *)(lVar2 + 0xe78 + param_1) & 0x20) != 0) {
            StorPortNotification
                      (6,param_1,AHCISlumberEnableRoutine,
                       (uint)*(byte *)(lVar2 + 0xe77 + param_1) * 1000000);
          }
        }
      }
      bVar3 = (char)uVar4 + 1;
      uVar4 = (ulonglong)bVar3;
    } while (bVar3 < *(byte *)(param_1 + 0x767e));
  }
  return;
}



===== AHCIAutoRequestSenseDPC @ 0001b340 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 AHCIAutoRequestSenseDPC(longlong param_1,byte *param_2,byte *param_3)

{
  char *pcVar1;
  byte bVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined1 auStackY_78 [32];
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined8 local_28;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  local_38 = 0;
  local_30 = 0x12;
  lVar3 = *(longlong *)(param_1 + 0xd60 + ((ulonglong)*param_2 * 0x1c5 + (ulonglong)*param_3) * 8);
  *(undefined1 *)(*(longlong *)(*(longlong *)(lVar3 + 8) + 0x38) + 0x10b0) = 1;
  bVar2 = *(byte *)(lVar3 + 3);
  local_20 = 0;
  *(undefined1 *)(lVar3 + 4) = 3;
  *(undefined4 *)(param_1 + 0x7698) = 0;
  *(undefined1 *)(param_1 + 0x76b4) = 0x27;
  *(undefined1 *)(param_1 + 0x76bb) = 0xe0;
  *(undefined1 *)(param_1 + 0x76b6) = 0xa0;
  *(undefined1 *)(param_1 + 0x76b9) = 0x12;
  *(undefined1 *)(param_1 + 0x76ba) = 0;
  *(undefined2 *)(param_1 + 0x7696) = 1;
  *(undefined1 *)(param_1 + 0x7694) = 0x25;
  local_28 = 0x1200000003;
  *(byte *)(param_1 + 0x76b5) = *(byte *)(param_1 + 0x76b5) & 0xe0 | bVar2 & 0x1f | 0x80;
  local_34 = *(undefined4 *)(param_1 + 0x7528);
  *(byte *)(param_1 + 0x7695) = *(byte *)(param_1 + 0x7695) & 8 | bVar2 << 4;
  pcVar1 = (char *)((ulonglong)*param_2 * 0xe28 + 0xe6d + param_1);
  *pcVar1 = *pcVar1 + '\x01';
  uVar4 = AHCIFillCommand(param_1,*param_2,bVar2,&local_28,(longlong)&local_38,*param_3,'\0');
  return CONCAT71((int7)(uVar4 >> 8),1);
}



===== AHCIGetTheLGDevicePosition @ 0001b498 =====

byte AHCIGetTheLGDevicePosition(longlong param_1,byte param_2,byte param_3)

{
  byte bVar1;
  longlong lVar2;
  byte bVar3;
  
  bVar1 = 0;
  do {
    bVar3 = 0;
    lVar2 = (ulonglong)bVar1 * 0x100;
    do {
      if (((*(char *)(lVar2 + 0x395a + param_1) == 'Z') &&
          ((int)*(char *)(lVar2 + 0x3958 + param_1) == (uint)param_2)) &&
         ((int)*(char *)(lVar2 + 0x3959 + param_1) == (uint)param_3)) {
        return bVar1;
      }
      bVar3 = bVar3 + 1;
    } while (bVar3 < 4);
    bVar1 = bVar1 + 1;
    if (0x3b < bVar1) {
      return bVar1;
    }
  } while( true );
}



===== AHCIInterrupt @ 0001b500 =====

undefined8 AHCIInterrupt(longlong param_1,undefined4 *param_2,undefined8 param_3,undefined8 param_4)

{
  byte *pbVar1;
  uint *puVar2;
  char *pcVar3;
  char cVar4;
  undefined4 uVar5;
  longlong lVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  byte bVar9;
  byte bVar10;
  uint uVar11;
  ulonglong uVar12;
  undefined8 uVar13;
  byte bVar14;
  undefined1 uVar15;
  undefined4 *puVar16;
  longlong lVar17;
  ulonglong uVar18;
  longlong lVar19;
  byte bVar20;
  uint uVar21;
  longlong lVar22;
  undefined1 *puVar23;
  char *pcVar24;
  ulonglong uVar25;
  longlong lVar26;
  bool bVar27;
  uint local_res8 [2];
  byte local_res10;
  ulonglong local_res18;
  ulonglong local_res20;
  ulonglong local_68;
  char *local_60;
  ulonglong local_58;
  longlong local_50;
  
  uVar25 = 0;
  uVar11 = **(uint **)(param_1 + 0x20);
  local_60 = (char *)0x0;
  local_res10 = 0;
  if (uVar11 == 0) {
    if (*(char *)(param_1 + 0x7685) != '\x01') {
      return (ulonglong)*(uint **)(param_1 + 0x20) & 0xffffffffffffff00;
    }
    uVar18 = CONCAT71((int7)((ulonglong)param_4 >> 8),*(undefined1 *)(param_1 + 0x751a));
    *(undefined1 *)(param_1 + 0x7685) = 0;
    local_res8[0] = CONCAT31(local_res8[0]._1_3_,*(undefined1 *)(param_1 + 0x751a));
LAB_0001bb8c:
    lVar19 = (uVar18 & 0xff) * 0xe28 + param_1;
    uVar12 = uVar18 & 0xff;
    bVar9 = 0;
    do {
      *(undefined4 *)(param_1 + 0x765c) = 0;
      *(byte *)(lVar19 + 0xd58) = *(byte *)(lVar19 + 0xd58) & 0xef;
      *(byte *)(lVar19 + 0xd58) = *(byte *)(lVar19 + 0xd58) | 8;
      lVar17 = *(longlong *)(lVar19 + 0x58);
      uVar11 = *(uint *)(lVar17 + 0x10);
      if (((*(byte *)(lVar19 + 0xd58) & 0x20) != 0) && ((uVar11 & 0x800008) != 0)) {
        if (*(char *)(param_1 + 0x768f) != '\0') {
          if ((*(uint *)(lVar17 + 0x3c) >> 0xf & 1) == 0) goto LAB_0001bc40;
          StorPortDebugPrint(0,"[FUNCTION] %s :PxCI %lx PxSNTF %lx.\n","AHCIInterrupt",
                             *(undefined4 *)(lVar17 + 0x38),*(uint *)(lVar17 + 0x3c));
          *(undefined4 *)(*(longlong *)(lVar19 + 0x58) + 0x3c) = 0x8000;
          uVar18 = (ulonglong)*(uint *)(*(longlong *)(lVar19 + 0x58) + 0x38);
          StorPortDebugPrint(0,"[FUNCTION] %s :Clear PxCI %lx PxSNTF %lx.\n","AHCIInterrupt",uVar18,
                             *(undefined4 *)(*(longlong *)(lVar19 + 0x58) + 0x3c));
          uVar18 = CONCAT71((int7)(uVar18 >> 8),(byte)local_res8[0]);
        }
        *(undefined1 *)(param_1 + 0x7684) = 1;
        *(byte *)(lVar19 + 0xe78) = *(byte *)(lVar19 + 0xe78) | 0x40;
      }
LAB_0001bc40:
      if ((uVar11 & 0x78000000) != 0) {
        lVar17 = *(longlong *)(lVar19 + 0x58);
        if ((*(byte *)(lVar17 + 0x20) & 1) == 0) {
          uVar18 = uVar18 & 0xff;
          StorPortDebugPrint(0,
                             "[FUNCTION] %s :Port %d subport %d,PxIS %lx Px->IS %lx Px->SERR %lx cmd %x TFD %x ERR %x\n"
                             ,"AHCIInterrupt",uVar18,bVar9,uVar11,*(undefined4 *)(lVar17 + 0x10),
                             *(undefined4 *)(lVar17 + 0x30),*(undefined1 *)(param_1 + 0x76b6),
                             *(undefined1 *)(lVar17 + 0x20),*(undefined1 *)(lVar17 + 0x21));
        }
        *(byte *)(lVar19 + 0xd58) = *(byte *)(lVar19 + 0xd58) | 0x10;
      }
      *(undefined4 *)(*(longlong *)(lVar19 + 0x58) + 0x30) = 0xffffffff;
      *(uint *)(*(longlong *)(lVar19 + 0x58) + 0x10) = uVar11;
      **(undefined4 **)(param_1 + 0x20) = *(undefined4 *)(lVar19 + 0xe7c);
      if (*(uint *)(lVar19 + 0xe64) == 0) {
        uVar21 = ~*(uint *)(*(longlong *)(lVar19 + 0x58) + 0x38) & *(uint *)(lVar19 + 0xe60);
      }
      else {
        uVar21 = ~*(uint *)(*(longlong *)(lVar19 + 0x58) + 0x34) & *(uint *)(lVar19 + 0xe64);
      }
      bVar27 = false;
      bVar9 = 0;
      uVar8 = local_res18 >> 8;
      local_res18 = local_res18 & 0xffffffffffffff00;
      uVar7 = local_res20 >> 8;
      local_res20 = local_res20 & 0xffffffffffffff00;
      if (uVar21 != 0) {
        bVar27 = true;
        local_res20 = CONCAT71((int7)uVar7,1);
        if ((uVar21 & 1) == 0) {
          do {
            bVar9 = bVar9 + 1;
          } while ((uVar21 >> (bVar9 & 0x1f) & 1) == 0);
          local_res18 = CONCAT71((int7)uVar8,bVar9);
        }
      }
      uVar21 = uVar21 & ~(1 << (bVar9 & 0x1f));
      if (((uVar11 & 0x80000b) == 0) && (!bVar27)) {
        *(byte *)(lVar19 + 0xd58) = *(byte *)(lVar19 + 0xd58) & 0xf7;
      }
      if ((*(byte *)(lVar19 + 0xd58) & 0x10) != 0) {
        uVar25 = (ulonglong)(byte)local_res8[0];
        lVar19 = uVar25 * 0xe28;
        uVar11 = *(uint *)(param_1 + 0xe64 + lVar19);
        local_58 = uVar25;
        if (uVar11 == 0) {
          lVar17 = *(longlong *)(param_1 + 0x58 + lVar19);
          bVar27 = false;
          uVar18 = local_res20 >> 8;
          local_res20 = local_res20 & 0xffffffffffffff00;
          local_68 = uVar25 * 0x1c5;
          bVar14 = *(byte *)(lVar17 + 0x19) & 0x1f;
          local_60 = *(char **)(param_1 + 0xd60 +
                               (((ulonglong)*(byte *)(lVar17 + 0x19) & 0x1f) + local_68) * 8);
          if (local_60 == (char *)0x0) {
            if (bVar14 == 0) {
              uVar12 = 0x1f;
            }
            else {
              uVar12 = (ulonglong)(byte)(bVar14 - 1);
            }
            local_60 = *(char **)(param_1 + 0xd60 + (uVar12 + local_68) * 8);
            bVar14 = (byte)uVar12;
            if (local_60 != (char *)0x0) goto LAB_0001c699;
          }
          else {
LAB_0001c699:
            bVar9 = bVar14;
            local_res20 = CONCAT71((int7)uVar18,1);
            bVar27 = true;
            local_res18 = CONCAT71(local_res18._1_7_,bVar9);
          }
          uVar11 = *(uint *)(lVar17 + 0x38) & ~*(uint *)(param_1 + 0xe60 + lVar19);
          if (bVar27) {
            lVar26 = *(longlong *)(local_60 + 8);
            local_res10 = local_60[3];
            lVar22 = *(longlong *)(lVar26 + 0x38);
            *(char *)(lVar22 + 0x10b0) = *(char *)(lVar22 + 0x10b0) + -1;
            *(undefined1 *)(lVar26 + 3) = 4;
            pcVar24 = (char *)(param_1 + 0xe6d + lVar19);
            *pcVar24 = *pcVar24 + -1;
            if (*(char *)(lVar22 + 0x10b0) == '\0') {
              *(undefined1 *)(param_1 + 0x7840) = 0;
              bVar14 = *(byte *)((ulonglong)bVar9 * 0x20 + *(longlong *)(param_1 + 0x60 + lVar19))
                       >> 5 & 1;
              if ((bVar14 == 0) ||
                 ((*(byte *)(*(longlong *)(param_1 + 0x58 + lVar19) + 0x20) & 1) == 0)) {
                if (bVar14 != 0) {
                  *(undefined1 *)(lVar26 + 3) = 9;
                }
              }
              else {
                *(undefined1 *)(lVar22 + 0x11) = 0;
                *(undefined1 *)(lVar26 + 4) = 2;
                *(undefined1 *)(param_1 + 0x7840) = 0;
                *(byte *)(param_1 + 0x7841) = bVar9;
                *(byte *)(param_1 + 0x7842) = (byte)local_res8[0];
                if (*(longlong *)(lVar26 + 0x20) != 0) {
                  *(undefined1 *)(param_1 + 0x7840) = 1;
                }
              }
              if (*(char *)(param_1 + 0x7840) == '\0') {
                if (*(int *)(param_1 + 0xe68 + lVar19) == 0) {
                  StorPortDeviceReady(param_1,CONCAT71((int7)((ulonglong)lVar17 >> 8),
                                                       *(undefined1 *)(lVar26 + 5)),
                                      CONCAT71((int7)((ulonglong)local_60 >> 8),
                                               *(undefined1 *)(lVar26 + 6)),
                                      CONCAT71((int7)(local_68 >> 8),*(undefined1 *)(lVar26 + 7)));
                }
                StorPortNotification(0,param_1,lVar26);
                if (*(char *)(lVar22 + 0x11) != '\0') {
                  *(undefined1 *)(lVar22 + 0x11) = 0;
                }
                uVar25 = (ulonglong)(byte)local_res8[0];
                *(undefined8 *)(param_1 + 0xd60 + (bVar9 + local_68) * 8) = 0;
              }
            }
            puVar2 = (uint *)(param_1 + 0xe60 + lVar19);
            *puVar2 = *puVar2 & ~(1 << (bVar9 & 0x1f));
          }
          puVar2 = (uint *)(param_1 + 0xe60 + lVar19);
          *puVar2 = *puVar2 & ~uVar11;
          uVar18 = local_68;
          while (uVar11 != 0) {
            bVar9 = 0;
            uVar12 = local_res18 >> 8;
            local_res18 = local_res18 & 0xffffffffffffff00;
            if ((uVar11 & 1) == 0) {
              do {
                bVar9 = bVar9 + 1;
              } while ((uVar11 >> (bVar9 & 0x1f) & 1) == 0);
              local_res18 = CONCAT71((int7)uVar12,bVar9);
            }
            local_60 = (char *)0x0;
            uVar11 = uVar11 & ~(1 << (bVar9 & 0x1f));
            local_50 = bVar9 + uVar18;
            pcVar24 = *(char **)(param_1 + 0xd60 + local_50 * 8);
            if (pcVar24 != (char *)0x0) {
              lVar17 = *(longlong *)(pcVar24 + 8);
              lVar26 = *(longlong *)(lVar17 + 0x38);
              *(char *)(lVar26 + 0x10b0) = *(char *)(lVar26 + 0x10b0) + -1;
              *(undefined1 *)(lVar17 + 3) = 4;
              pcVar3 = (char *)(param_1 + 0xe6d + lVar19);
              *pcVar3 = *pcVar3 + -1;
              local_60 = pcVar24;
              if (*(char *)(lVar26 + 0x10b0) == '\0') {
                *(undefined1 *)(param_1 + 0x7840) = 0;
                bVar14 = *(byte *)((ulonglong)bVar9 * 0x20 + *(longlong *)(param_1 + 0x60 + lVar19))
                         >> 5 & 1;
                if ((bVar14 == 0) ||
                   ((*(byte *)(*(longlong *)(param_1 + 0x58 + lVar19) + 0x20) & 1) == 0)) {
                  if (bVar14 != 0) {
                    *(undefined1 *)(lVar17 + 3) = 9;
                  }
                }
                else {
                  *(undefined1 *)(lVar26 + 0x11) = 0;
                  *(undefined1 *)(lVar17 + 4) = 2;
                  *(undefined1 *)(param_1 + 0x7840) = 0;
                  *(byte *)(param_1 + 0x7841) = bVar9;
                  *(char *)(param_1 + 0x7842) = (char)uVar25;
                  if (*(longlong *)(lVar17 + 0x20) != 0) {
                    *(undefined1 *)(param_1 + 0x7840) = 1;
                  }
                }
                if (*(char *)(param_1 + 0x7840) == '\0') {
                  if (*(int *)(param_1 + 0xe68 + lVar19) == 0) {
                    StorPortDeviceReady(param_1,*(undefined1 *)(lVar17 + 5),
                                        CONCAT71((int7)((ulonglong)pcVar24 >> 8),
                                                 *(undefined1 *)(lVar17 + 6)),
                                        *(undefined1 *)(lVar17 + 7));
                  }
                  StorPortNotification(0,param_1,lVar17);
                  if (*(char *)(lVar26 + 0x11) != '\0') {
                    *(undefined1 *)(lVar26 + 0x11) = 0;
                  }
                  *(undefined8 *)(param_1 + 0xd60 + local_50 * 8) = 0;
                  uVar18 = local_68;
                }
              }
            }
            uVar25 = (ulonglong)(byte)local_res8[0];
          }
        }
        else {
          lVar17 = *(longlong *)(param_1 + 0x58 + lVar19);
          uVar21 = ~*(uint *)(lVar17 + 0x38) & *(uint *)(lVar17 + 0x34);
          *(uint *)(param_1 + 0xe64 + lVar19) = ~uVar21 & uVar11;
          if (uVar21 != 0) {
            do {
              bVar9 = 0;
              uVar12 = local_res18 >> 8;
              local_res18 = local_res18 & 0xffffffffffffff00;
              if ((uVar21 & 1) == 0) {
                do {
                  bVar9 = bVar9 + 1;
                } while ((uVar21 >> (bVar9 & 0x1f) & 1) == 0);
                local_res18 = CONCAT71((int7)uVar12,bVar9);
              }
              local_60 = (char *)0x0;
              lVar17 = (ulonglong)bVar9 + uVar25 * 0x1c5;
              pcVar24 = *(char **)(param_1 + 0xd60 + lVar17 * 8);
              uVar21 = uVar21 & ~(1 << (bVar9 & 0x1f));
              if (pcVar24 != (char *)0x0) {
                lVar26 = *(longlong *)(pcVar24 + 8);
                lVar22 = *(longlong *)(lVar26 + 0x38);
                *(undefined8 *)(param_1 + 0xd60 + lVar17 * 8) = 0;
                pcVar3 = (char *)(lVar22 + 0x10b0);
                *pcVar3 = *pcVar3 + -1;
                *(undefined1 *)(lVar26 + 3) = 4;
                pcVar3 = (char *)(param_1 + 0xe6c + lVar19);
                *pcVar3 = *pcVar3 + -1;
                local_60 = pcVar24;
                if ((*(char *)(lVar22 + 0x10b0) == '\0') &&
                   (*(int *)(param_1 + 0xe68 + lVar19) == 0)) {
                  uVar18 = CONCAT71((int7)(uVar18 >> 8),*(undefined1 *)(lVar26 + 7));
                  StorPortDeviceReady(param_1,*(undefined1 *)(lVar26 + 5),
                                      CONCAT71((int7)((ulonglong)pcVar24 >> 8),
                                               *(undefined1 *)(lVar26 + 6)),uVar18);
                }
                StorPortNotification(0,param_1,lVar26);
              }
            } while (uVar21 != 0);
          }
          uVar11 = *(uint *)(param_1 + 0xe64 + lVar19);
          uVar21 = ~*(uint *)(*(longlong *)(param_1 + 0x58 + lVar19) + 0x34) & uVar11;
          *(uint *)(param_1 + 0xe60 + lVar19) = ~uVar21 & uVar11;
          if (uVar21 != 0) {
            lVar17 = local_58 * 0x1c5;
            do {
              bVar9 = 0;
              uVar25 = local_res18 >> 8;
              local_res18 = local_res18 & 0xffffffffffffff00;
              if ((uVar21 & 1) == 0) {
                do {
                  bVar9 = bVar9 + 1;
                } while ((uVar21 >> (bVar9 & 0x1f) & 1) == 0);
                local_res18 = CONCAT71((int7)uVar25,bVar9);
              }
              local_60 = (char *)0x0;
              uVar21 = uVar21 & ~(1 << (bVar9 & 0x1f));
              lVar26 = (ulonglong)bVar9 + lVar17;
              pcVar24 = *(char **)(param_1 + 0xd60 + lVar26 * 8);
              if (pcVar24 != (char *)0x0) {
                lVar22 = *(longlong *)(pcVar24 + 8);
                lVar6 = *(longlong *)(lVar22 + 0x38);
                *(undefined8 *)(param_1 + 0xd60 + lVar26 * 8) = 0;
                pcVar3 = (char *)(lVar6 + 0x10b0);
                *pcVar3 = *pcVar3 + -1;
                *(undefined1 *)(lVar22 + 3) = 4;
                if (pcVar24[5] == '\x02') {
                  pcVar3 = (char *)(param_1 + 0xe6c + lVar19);
                  *pcVar3 = *pcVar3 + -1;
                }
                local_60 = pcVar24;
                if ((*(char *)(lVar6 + 0x10b0) == '\0') && (*(int *)(param_1 + 0xe68 + lVar19) == 0)
                   ) {
                  uVar18 = CONCAT71((int7)(uVar18 >> 8),*(undefined1 *)(lVar22 + 7));
                  StorPortDeviceReady(param_1,*(undefined1 *)(lVar22 + 5),
                                      CONCAT71((int7)((ulonglong)pcVar24 >> 8),
                                               *(undefined1 *)(lVar22 + 6)),uVar18);
                }
                StorPortNotification(0,param_1,lVar22);
              }
            } while (uVar21 != 0);
          }
        }
        bVar20 = local_res10;
        *(undefined4 *)(*(longlong *)(param_1 + 0x58 + lVar19) + 0x14) = 0;
        *(undefined4 *)(*(longlong *)(param_1 + 0x58 + lVar19) + 0x30) = 0xffffffff;
        *(undefined4 *)(*(longlong *)(param_1 + 0x58 + lVar19) + 0x10) = 0xffffffff;
        **(undefined4 **)(param_1 + 0x20) = *(undefined4 *)(param_1 + 0xe7c + lVar19);
        *(undefined1 *)(param_1 + 0x7686) = 0;
        bVar14 = (byte)local_res8[0];
        if ((*(byte *)(param_1 + 0xd58 + lVar19) & 0x20) == 0) {
          uVar13 = AHCIProcessFatalError(param_1,(byte)local_res8[0],local_res10);
          if ((char)uVar13 == '\0') {
            *(undefined1 *)(param_1 + 0x7686) = 1;
            *(undefined1 *)(param_1 + 0x7682) = 1;
            bVar14 = AHCIGetTheLGDevicePosition(param_1,bVar14,bVar20);
            *(undefined1 *)((ulonglong)bVar14 * 0x100 + 0x3924 + param_1) = 0;
            *(undefined1 *)((ulonglong)bVar20 + lVar19 + 0x1fa + param_1) = 0;
          }
        }
        else {
          uVar13 = AHCIProcessPMFatalError(param_1,(byte)local_res8[0],local_res10);
          if ((char)uVar13 == '\0') {
            *(undefined1 *)(param_1 + 0x7686) = 1;
            *(undefined1 *)(param_1 + 0x7682) = 1;
            *(undefined1 *)(param_1 + 0x7683) = 1;
            bVar20 = 0;
            puVar23 = (undefined1 *)(param_1 + 0x1fa + lVar19);
            do {
              bVar10 = AHCIGetTheLGDevicePosition(param_1,bVar14,bVar20);
              bVar20 = bVar20 + 1;
              *(undefined1 *)((ulonglong)bVar10 * 0x100 + 0x3924 + param_1) = 0;
              *puVar23 = 0;
              puVar23 = puVar23 + 1;
            } while (bVar20 < 0xf);
            StorPortDebugPrint(0,"[FUNCTION ]%s :AHCIProcessFatalError FAILED for PM Exit",
                               "AHCIInterrupt");
          }
          else {
            uVar13 = CONCAT71((int7)(uVar18 >> 8),0xf);
            AHCIPMReadWrite(param_1,bVar14,0xf,uVar13,-0x1c,0x20,(uint *)&local_68);
            bVar14 = 0;
            if ((uint)local_68 != 0) {
              bVar9 = (byte)local_res8[0];
              uVar11 = (uint)local_68;
              do {
                uVar21 = 1 << (bVar14 & 0x1f);
                if ((uVar21 & uVar11) != 0) {
                  local_res8[0] = 0xffffffff;
                  uVar13 = CONCAT71((int7)((ulonglong)uVar13 >> 8),0xf);
                  AHCIPMReadWrite(param_1,bVar9,bVar14,uVar13,-0x18,1,local_res8);
                  uVar13 = CONCAT71((int7)((ulonglong)uVar13 >> 8),0xf);
                  local_res8[0] = 0;
                  AHCIPMReadWrite(param_1,bVar9,bVar14,uVar13,-0x1c,0,local_res8);
                  if ((((byte)local_res8[0] & 0xf) == 4) &&
                     ((cVar4 = *(char *)((ulonglong)bVar14 + lVar19 + 0x1fa + param_1),
                      cVar4 == '\x01' || (cVar4 == '\x11')))) {
                    uVar13 = CONCAT71((int7)((ulonglong)uVar13 >> 8),0xf);
                    local_res8[0] = 1;
                    AHCIPMReadWrite(param_1,bVar9,bVar14,uVar13,-0x18,1,local_res8);
                    uVar13 = CONCAT71((int7)((ulonglong)uVar13 >> 8),0xf);
                    local_res8[0] = 0;
                    AHCIPMReadWrite(param_1,bVar9,bVar14,uVar13,-0x18,1,local_res8);
                    local_res8[0] = 0xffffffff;
                    uVar13 = CONCAT71((int7)((ulonglong)uVar13 >> 8),0xf);
                    AHCIPMReadWrite(param_1,bVar9,bVar14,uVar13,-0x18,1,local_res8);
                    uVar13 = CONCAT71((int7)((ulonglong)uVar13 >> 8),0xf);
                    local_res8[0] = 0;
                    AHCIPMReadWrite(param_1,bVar9,bVar14,uVar13,-0x1c,0,local_res8);
                  }
                  else if ((local_res8[0] & 3) == 3) {
LAB_0001cc31:
                    cVar4 = *(char *)((ulonglong)bVar14 + lVar19 + 0x1fa + param_1);
                    if ((cVar4 != '\x01') && (cVar4 != '\x11')) {
                      *(undefined1 *)(param_1 + 0x7686) = 1;
                      *(undefined1 *)(param_1 + 0x7682) = 0;
                      *(undefined1 *)(param_1 + 0xe71 + lVar19) = 0;
                      *(byte *)(param_1 + 0xe73 + lVar19) = bVar9;
                      *(byte *)(param_1 + 0xe74 + lVar19) = bVar14;
                      *(undefined1 *)(param_1 + 0xe72 + lVar19) = 0;
                      if (*(char *)(param_1 + 0xe75 + lVar19) != '\x01') {
                        *(undefined1 *)(param_1 + 0xe75 + lVar19) = 1;
                        *(char *)(param_1 + 0x7676) = *(char *)(param_1 + 0x7676) + '\x01';
                      }
                    }
                  }
                  else {
                    cVar4 = *(char *)((ulonglong)bVar14 + lVar19 + 0x1fa + param_1);
                    if ((cVar4 == '\x01') || (cVar4 == '\x11')) {
                      *(undefined1 *)(param_1 + 0x7682) = 1;
                      *(undefined1 *)(param_1 + 0xe71 + lVar19) = 0;
                      *(byte *)(param_1 + 0xe73 + lVar19) = bVar9;
                      *(byte *)(param_1 + 0xe74 + lVar19) = bVar14;
                      *(undefined1 *)(param_1 + 0xe72 + lVar19) = 0;
                      *(undefined1 *)(param_1 + 0x7686) = 1;
                    }
                    else if ((local_res8[0] & 3) == 3) goto LAB_0001cc31;
                  }
                }
                bVar14 = bVar14 + 1;
                uVar11 = uVar11 & ~uVar21;
              } while (uVar11 != 0);
              bVar9 = (byte)local_res18;
            }
          }
        }
        *(char *)(param_1 + 0x7678) =
             (char)((ulonglong)(byte)(*(char *)(param_1 + 0x7678) + 1) %
                   (ulonglong)(longlong)(int)(uint)*(byte *)(param_1 + 0x767e));
        lVar17 = *(longlong *)(param_1 + 0x58 + lVar19);
        if ((*(byte *)(param_1 + 0xd58 + lVar19) & 4) == 0) {
          *(undefined4 *)(lVar17 + 0x14) = 0x78c000cb;
        }
        else {
          *(undefined4 *)(lVar17 + 0x14) = 0x788000cb;
        }
        if ((*(byte *)(param_1 + 0xe78 + lVar19) & 0x80) != 0) {
          puVar2 = (uint *)(*(longlong *)(param_1 + 0x58 + lVar19) + 0x14);
          *puVar2 = *puVar2 & 0xfffffff0;
        }
        if ((*(char *)(param_1 + 0x768f) != '\0') &&
           ((*(byte *)(param_1 + 0xd58 + lVar19) & 0x20) != 0)) {
          puVar2 = (uint *)(*(longlong *)(param_1 + 0x58 + lVar19) + 0x14);
          *puVar2 = *puVar2 | 8;
        }
        if (*(char *)(param_1 + 0x7686) == '\x01') {
LAB_0001ce8c:
          if (*(char *)(param_1 + 0x7840) != '\x01') goto LAB_0001cd46;
          lVar22 = local_58 * 0x1c5 + (ulonglong)bVar9;
          pcVar24 = *(char **)(param_1 + 0xd60 + lVar22 * 8);
          lVar17 = *(longlong *)(pcVar24 + 8);
          lVar26 = *(longlong *)(lVar17 + 0x38);
          StorPortNotification(0,param_1,lVar17);
          if (*(char *)(lVar26 + 0x11) != '\0') {
            *(undefined1 *)(lVar26 + 0x11) = 0;
          }
          *(undefined8 *)(param_1 + 0xd60 + lVar22 * 8) = 0;
          if (*(int *)(param_1 + 0xe68 + lVar19) == 0) {
            StorPortDeviceReady(param_1,*(undefined1 *)(lVar17 + 5),*(undefined1 *)(lVar17 + 6),
                                *(undefined1 *)(lVar17 + 7));
          }
        }
        else {
          if (*(char *)(param_1 + 0x7840) == '\x01') {
            AHCIAutoRequestSenseDPC(param_1,(byte *)(param_1 + 0x7842),(byte *)(param_1 + 0x7841));
          }
          else if (*(char *)(param_1 + 0x7686) == '\x01') goto LAB_0001ce8c;
LAB_0001cd46:
          pcVar24 = local_60;
        }
        if (*(char *)(param_1 + 0x7686) == '\x01') {
          uVar11 = *(uint *)(param_1 + 0xe60 + lVar19);
          *(undefined4 *)(param_1 + 0xe64 + lVar19) = 0;
          bVar9 = 0;
          *(undefined4 *)(param_1 + 0xe60 + lVar19) = 0;
          if (uVar11 != 0) {
            local_res8[0] = 1;
            uVar25 = local_58 * 0x1c5;
            local_60 = pcVar24;
            local_58 = uVar25;
            do {
              uVar21 = uVar11 & local_res8[0];
              while (uVar21 == 0) {
                bVar9 = bVar9 + 1;
                uVar21 = uVar11 >> (bVar9 & 0x1f) & 1;
              }
              local_res8[0] = 1 << (bVar9 & 0x1f);
              uVar11 = uVar11 & ~local_res8[0];
              pcVar24 = *(char **)(param_1 + 0xd60 + (bVar9 + uVar25) * 8);
              if (pcVar24 != (char *)0x0) {
                local_60 = pcVar24;
              }
              if (local_60 != (char *)0x0) {
                if ((char)local_res20 == '\x01') {
                  lVar17 = *(longlong *)(local_60 + 8);
                  lVar26 = *(longlong *)(lVar17 + 0x38);
                  *(undefined8 *)(param_1 + 0xd60 + (bVar9 + uVar25) * 8) = 0;
                  *(char *)(lVar26 + 0x10b0) = *(char *)(lVar26 + 0x10b0) + -1;
                  *(undefined1 *)(lVar17 + 3) = 4;
                  if (local_60[5] == '\x02') {
                    pcVar24 = (char *)(param_1 + 0xe6c + lVar19);
                    *pcVar24 = *pcVar24 + -1;
                  }
                  if (*(char *)(lVar26 + 0x10b0) == '\0') {
                    if (*(int *)(param_1 + 0xe68 + lVar19) == 0) {
                      StorPortDeviceReady(param_1,CONCAT31((int3)(local_res8[0] >> 8),
                                                           *(undefined1 *)(lVar17 + 5)),
                                          *(undefined1 *)(lVar17 + 6),*(undefined1 *)(lVar17 + 7));
                    }
                    StorPortNotification(0,param_1,lVar17);
                    if ((*(char *)((ulonglong)local_res10 + lVar19 + 0x1fa + param_1) == '\x11') ||
                       (*(char *)(lVar26 + 0x11) != '\0')) {
                      *(undefined1 *)(lVar26 + 0x11) = 0;
                    }
                  }
                  uVar25 = local_58;
                }
              }
            } while (uVar11 != 0);
          }
          local_res8[0] = 0;
          uVar12 = StorPortNotification(0x1002,param_1,param_1 + 0x7768,0,0,local_res8);
        }
        else {
          if (*(int *)(param_1 + 0xe64 + lVar19) != 0) {
            uVar5 = *(undefined4 *)(param_1 + 0xe60 + lVar19);
            *(undefined4 *)(param_1 + 0xe64 + lVar19) = uVar5;
            *(undefined4 *)(*(longlong *)(param_1 + 0x58 + lVar19) + 0x34) = uVar5;
          }
          uVar11 = *(uint *)(param_1 + 0xe60 + lVar19);
          uVar12 = (ulonglong)uVar11;
          *(uint *)(*(longlong *)(param_1 + 0x58 + lVar19) + 0x38) = uVar11;
          if ((*(int *)(param_1 + 0xe60 + lVar19) == 0) && (*(int *)(param_1 + 0xe64 + lVar19) == 0)
             ) {
            uVar11 = *(uint *)(param_1 + 0xe68 + lVar19);
            *(undefined1 *)(param_1 + 0xe70 + lVar19) = 0;
            if (uVar11 != 0) {
              bVar9 = 0;
              for (uVar21 = uVar11; (uVar21 != 0 && ((uVar21 & 1) == 0)); uVar21 = uVar21 >> 1) {
                bVar9 = bVar9 + 1;
              }
              uVar21 = 1 << (bVar9 & 0x1f);
              *(uint *)(param_1 + 0xe68 + lVar19) = ~uVar21 & uVar11;
              lVar17 = *(longlong *)(param_1 + 0xd60 + (local_58 * 0x1c5 + (ulonglong)bVar9) * 8);
              uVar12 = 0;
              if (lVar17 != 0) {
                cVar4 = *(char *)(lVar17 + 5);
                uVar12 = *(ulonglong *)(param_1 + 0x58 + lVar19);
                *(uint *)(param_1 + 0xe60 + lVar19) = uVar21;
                if (cVar4 == '\x02') {
                  *(uint *)(param_1 + 0xe64 + lVar19) = uVar21;
                  *(uint *)(uVar12 + 0x38) = uVar21;
                  uVar11 = *(uint *)(param_1 + 0xe64 + lVar19);
                  uVar12 = (ulonglong)uVar11;
                  *(uint *)(*(longlong *)(param_1 + 0x58 + lVar19) + 0x34) = uVar11;
                }
                else {
                  *(uint *)(uVar12 + 0x38) = uVar21;
                }
              }
            }
          }
        }
        goto LAB_0001b7d1;
      }
      if (((*(byte *)(lVar19 + 0xd58) & 8) == 0) && ((*(byte *)(lVar19 + 0xe78) & 0x80) == 0)) {
        lVar19 = (ulonglong)(byte)local_res8[0] * 0xe28;
        *(undefined4 *)(*(longlong *)(lVar19 + 0x58 + param_1) + 0x30) = 0xffffffff;
        *(undefined4 *)(*(longlong *)(lVar19 + 0x58 + param_1) + 0x10) = 0x87fffff4;
        uVar11 = *(uint *)(lVar19 + 0xe7c + param_1);
        uVar12 = (ulonglong)uVar11;
        **(uint **)(param_1 + 0x20) = uVar11;
        goto LAB_0001b7d1;
      }
      while (bVar27) {
        local_68 = (ulonglong)bVar9;
        pcVar24 = *(char **)(param_1 + 0xd60 + (uVar12 * 0x1c5 + local_68) * 8);
        local_60 = pcVar24;
        if (pcVar24 == (char *)0x0) {
          uVar11 = ~(1 << (bVar9 & 0x1f));
          *(uint *)(lVar19 + 0xe64) = *(uint *)(lVar19 + 0xe64) & uVar11;
          *(uint *)(lVar19 + 0xe60) = *(uint *)(lVar19 + 0xe60) & uVar11;
          break;
        }
        local_58 = (ulonglong)(byte)pcVar24[2];
        local_res10 = pcVar24[3];
        lVar17 = *(longlong *)(pcVar24 + 8);
        local_res18 = *(ulonglong *)(lVar17 + 0x38);
        local_res20 = local_58 * 0xe28;
        lVar19 = local_res20 + param_1;
        local_res8[0] = CONCAT31(local_res8[0]._1_3_,pcVar24[2]);
        local_50 = local_68 * 0x20;
        if (((((*(int *)(*(longlong *)(lVar19 + 0x60) + 4 + local_50) == *(int *)(pcVar24 + 0x14))
              || (pcVar24[5] == '\x02')) || (pcVar24[4] == '@')) || (pcVar24[4] == 'B')) ||
           ((((*(byte *)(*(longlong *)(lVar19 + 0x60) + local_50) & 0x20) != 0 &&
             ((*(byte *)(*(longlong *)(lVar19 + 0x58) + 0x20) & 8) == 0)) &&
            ((*(byte *)(*(longlong *)(lVar19 + 0x58) + 0x20) & 0x80) == 0)))) {
          uVar11 = ~(1 << (bVar9 & 0x1f));
          *(uint *)(lVar19 + 0xe60) = *(uint *)(lVar19 + 0xe60) & uVar11;
          if (*(uint *)(lVar19 + 0xe64) != 0) {
            *(uint *)(lVar19 + 0xe64) = uVar11 & *(uint *)(lVar19 + 0xe64);
          }
          *(undefined1 *)(lVar19 + 0xe6f) = 0;
          if (((*(char *)(lVar17 + 2) == '\x02') && (*(char *)(local_res18 + 0x11) != '\0')) &&
             (*pcVar24 != '\0')) {
            lVar26 = *(longlong *)(lVar17 + 0x18);
            puVar16 = (undefined4 *)(lVar26 + 0x1c);
            if ((pcVar24[1] == -0x30) || (pcVar24[1] == -0x2f)) {
              pcVar24[6] = '\x01';
              *puVar16 = *(undefined4 *)(pcVar24 + 0x14);
            }
            else {
              pcVar24[6] = '\x01';
              *puVar16 = 0;
            }
            *(undefined1 *)(lVar26 + 0x21) = 0;
            *(undefined1 *)(lVar26 + 0x20) = 0;
            if (pcVar24[1] == -0x26) {
              *(undefined1 *)(lVar26 + 0x2c) = 0xda;
              *(undefined1 *)(lVar26 + 0x2d) = *(undefined1 *)(*(longlong *)(lVar19 + 0x58) + 0x21);
              *(undefined1 *)(lVar26 + 0x2e) = *(undefined1 *)(*(longlong *)(lVar19 + 0x58) + 0x24);
              *(undefined1 *)(lVar26 + 0x2f) = *(undefined1 *)(*(longlong *)(lVar19 + 0x58) + 0x25);
              *(undefined1 *)(lVar26 + 0x30) = *(undefined1 *)(*(longlong *)(lVar19 + 0x58) + 0x26);
              uVar15 = *(undefined1 *)(*(longlong *)(lVar19 + 0x58) + 0x27);
              *(undefined1 *)(lVar26 + 0x32) = 0xb0;
              *puVar16 = 8;
              *(undefined1 *)(lVar26 + 0x31) = uVar15;
            }
          }
          if (pcVar24[5] == '\x02') {
            *(char *)(lVar19 + 0xe6c) = *(char *)(lVar19 + 0xe6c) + -1;
          }
          else {
            *(char *)(lVar19 + 0xe6d) = *(char *)(lVar19 + 0xe6d) + -1;
          }
          *(undefined8 *)(param_1 + 0xd60 + (local_58 * 0x1c5 + local_68) * 8) = 0;
          pcVar3 = (char *)(local_res18 + 0x10b0);
          *pcVar3 = *pcVar3 + -1;
          if (*pcVar3 == '\0') {
            if (*(char *)(lVar17 + 3) != '\x04') {
              *(undefined1 *)(lVar17 + 3) = 1;
            }
            if ((((*(byte *)(local_50 + *(longlong *)(lVar19 + 0x60)) & 0x20) != 0) &&
                (pcVar24[4] == '\x03')) && (*(char *)(lVar17 + 0x48) != '\x03')) {
              *(undefined1 *)(lVar17 + 3) = 0x84;
              memcpy(*(void **)(lVar17 + 0x20),*(void **)(param_1 + 0x7520),0x12);
            }
            if (*(int *)(lVar19 + 0xe68) == 0) {
              StorPortDeviceReady(param_1,*(undefined1 *)(lVar17 + 5),*(undefined1 *)(lVar17 + 6),
                                  *(undefined1 *)(lVar17 + 7));
            }
            StorPortNotification(0,param_1,lVar17);
            if ((*(char *)(local_res20 + param_1 + (ulonglong)local_res10 + 0x1fa) == '\x11') ||
               (*(char *)(local_res18 + 0x11) != '\0')) {
              *(undefined1 *)(local_res18 + 0x11) = 0;
            }
          }
          if (uVar21 == 0) break;
          bVar27 = false;
          bVar9 = 0;
          if (uVar21 != 0) {
            bVar27 = true;
            uVar11 = uVar21;
            while ((uVar11 & 1) == 0) {
              bVar9 = bVar9 + 1;
              uVar11 = uVar21 >> (bVar9 & 0x1f);
            }
          }
        }
        else {
          if ((*(byte *)(local_res20 + param_1 + (ulonglong)local_res10 * 0xc0 + 0x2c1) & 0x20) != 0
             ) {
            StorPortDebugPrint(0,
                               "[FUNCTION] %s :The DataTransferring is DMA.It\'s strange for DMA Command.\n"
                               ,"AHCIInterrupt");
            uVar18 = local_res18;
            uVar11 = ~(1 << (bVar9 & 0x1f));
            *(uint *)(lVar19 + 0xe60) = *(uint *)(lVar19 + 0xe60) & uVar11;
            if (*(uint *)(lVar19 + 0xe64) != 0) {
              *(uint *)(lVar19 + 0xe64) = uVar11 & *(uint *)(lVar19 + 0xe64);
            }
            if (pcVar24[5] == '\x02') {
              *(char *)(lVar19 + 0xe6c) = *(char *)(lVar19 + 0xe6c) + -1;
            }
            else {
              *(char *)(lVar19 + 0xe6d) = *(char *)(lVar19 + 0xe6d) + -1;
            }
            *(undefined8 *)(param_1 + 0xd60 + (local_58 * 0x1c5 + local_68) * 8) = 0;
            pcVar3 = (char *)(local_res18 + 0x10b0);
            *pcVar3 = *pcVar3 + -1;
            if (*pcVar3 == '\0') {
              if ((*(byte *)(local_50 + *(longlong *)(lVar19 + 0x60)) & 0x20) == 0) {
                *(undefined1 *)(lVar17 + 3) = 4;
              }
              else if (pcVar24[4] == '\x03') {
                if (*(char *)(lVar17 + 0x48) != '\x03') {
                  *(undefined1 *)(lVar17 + 3) = 0x84;
                  memcpy(*(void **)(lVar17 + 0x20),*(void **)(param_1 + 0x7520),0x12);
                }
              }
              else {
                *(undefined1 *)(lVar17 + 3) = 1;
              }
              if (*(int *)(lVar19 + 0xe68) == 0) {
                StorPortDeviceReady(param_1,*(undefined1 *)(lVar17 + 5),*(undefined1 *)(lVar17 + 6),
                                    *(undefined1 *)(lVar17 + 7));
              }
              StorPortNotification(0,param_1,lVar17);
              if ((*(char *)(local_res20 + param_1 + (ulonglong)local_res10 + 0x1fa) == '\x11') ||
                 (*(char *)(uVar18 + 0x11) != '\0')) {
                *(undefined1 *)(uVar18 + 0x11) = 0;
              }
            }
          }
          if (uVar21 == 0) break;
          bVar27 = false;
          bVar9 = 0;
          if (uVar21 != 0) {
            bVar27 = true;
            uVar11 = uVar21;
            while ((uVar11 & 1) == 0) {
              bVar9 = bVar9 + 1;
              uVar11 = uVar21 >> (bVar9 & 0x1f);
            }
          }
        }
        uVar21 = uVar21 & ~(1 << (bVar9 & 0x1f));
        uVar12 = local_58;
      }
      uVar18 = (ulonglong)(byte)local_res8[0];
      uVar12 = uVar18 * 0xe28;
      lVar19 = uVar12 + param_1;
      if (*(int *)(lVar19 + 0xe64) == 0) {
        if (*(int *)(lVar19 + 0xe60) == 0) goto LAB_0001c202;
        uVar12 = *(ulonglong *)(lVar19 + 0x58);
        bVar27 = *(int *)(lVar19 + 0xe60) == *(int *)(uVar12 + 0x38);
      }
      else {
        uVar12 = *(ulonglong *)(lVar19 + 0x58);
        bVar27 = *(int *)(lVar19 + 0xe64) == *(int *)(uVar12 + 0x34);
      }
      if (bVar27) goto LAB_0001c202;
      uVar12 = uVar18;
      bVar9 = local_res10;
    } while( true );
  }
  if ((*(uint *)((ulonglong)*(byte *)(param_1 + 0x7678) * 0xe28 + 0xe7c + param_1) & uVar11) == 0) {
    do {
      uVar18 = (ulonglong)(byte)(*(char *)(param_1 + 0x7678) + 1) %
               (ulonglong)(longlong)(int)(uint)*(byte *)(param_1 + 0x767e);
      *(char *)(param_1 + 0x7678) = (char)uVar18;
    } while ((**(uint **)(param_1 + 0x20) & *(uint *)(uVar18 * 0xe28 + 0xe7c + param_1)) == 0);
  }
  bVar9 = *(byte *)(param_1 + 0x7678);
  uVar18 = (ulonglong)bVar9;
  local_res8[0] = CONCAT31(local_res8[0]._1_3_,bVar9);
  lVar17 = uVar18 * 0xe28;
  lVar19 = *(longlong *)(param_1 + 0x58 + lVar17);
  uVar11 = *(uint *)(lVar19 + 0x10);
  if (*(int *)(lVar19 + 0x30) != 0) {
    uVar18 = (ulonglong)bVar9;
    StorPortDebugPrint(0,
                       "[FUNCTION] %s :Port %d ,PxIS %lx Px->IS %lx Px->SERR %lx cmd %x TFD %x ERR %x\n"
                       ,"AHCIInterrupt",uVar18,uVar11,uVar11,*(int *)(lVar19 + 0x30),
                       *(undefined1 *)(param_1 + 0x76b6),*(undefined1 *)(lVar19 + 0x20),
                       *(undefined1 *)(lVar19 + 0x21));
    uVar18 = CONCAT71((int7)(uVar18 >> 8),(byte)local_res8[0]);
  }
  bVar9 = *(byte *)(param_1 + 0xd58 + lVar17) >> 2 & 1;
  if ((bVar9 == 0) || (((uVar11 & 0x80) == 0 && ((uVar11 & 0x40) == 0)))) {
    if ((bVar9 != 0) ||
       ((((uVar11 & 0x80) == 0 && ((uVar11 >> 0x16 & 1) == 0)) && ((uVar11 & 0x40) == 0))))
    goto LAB_0001bb8c;
    StorPortDebugPrint(0,"[FUNCTION] %s : Port %d PxIS.Value %lx PxIS %lx\n","AHCIInterrupt",
                       uVar18 & 0xff,*(undefined4 *)(*(longlong *)(param_1 + 0x58 + lVar17) + 0x10),
                       uVar11);
    *(undefined1 *)(param_1 + 0x7686) = 1;
    lVar19 = 10;
    if ((uVar11 & 0x80) == 0) {
    }
    else {
      lVar26 = 10;
      if (*(char *)(param_1 + 0x768c) == '\0') {
        lVar22 = *(longlong *)(param_1 + 0x58 + lVar17);
        *(byte *)(lVar22 + 0x2c) = *(byte *)(lVar22 + 0x2c) & 0xf1 | 1;
        do {
          StorPortStallExecution(500);
          lVar26 = lVar26 + -1;
        } while (lVar26 != 0);
        lVar26 = 0x14;
        pbVar1 = (byte *)(*(longlong *)(param_1 + 0x58 + lVar17) + 0x2c);
        *pbVar1 = *pbVar1 & 0xf0;
        do {
          StorPortStallExecution(500);
          lVar26 = lVar26 + -1;
        } while (lVar26 != 0);
      }
      else {
        pbVar1 = (byte *)(*(longlong *)(param_1 + 0x58 + lVar17) + 0x18);
        *pbVar1 = *pbVar1 & 0xfd;
        do {
          StorPortStallExecution(500);
          lVar26 = lVar26 + -1;
        } while (lVar26 != 0);
        lVar26 = 0x14;
        pbVar1 = (byte *)(*(longlong *)(param_1 + 0x58 + lVar17) + 0x18);
        *pbVar1 = *pbVar1 | 2;
        do {
          StorPortStallExecution(500);
          lVar26 = lVar26 + -1;
        } while (lVar26 != 0);
      }
      if ((*(byte *)(*(longlong *)(param_1 + 0x58 + lVar17) + 0x28) & 0xf) == 0) {
        pbVar1 = (byte *)(param_1 + 0xd58 + lVar17);
        *pbVar1 = *pbVar1 & 0xbf;
        *(undefined1 *)(param_1 + 0x7682) = 1;
        if ((*(byte *)(param_1 + 0xd58 + lVar17) & 0x20) != 0) {
          *(undefined1 *)(param_1 + 0x7683) = 1;
        }
      }
      else {
        *(undefined1 *)(param_1 + 0x7682) = 0;
        *(undefined1 *)(param_1 + 0xe71 + lVar17) = 0;
        *(byte *)(param_1 + 0xe73 + lVar17) = (byte)local_res8[0];
        *(undefined1 *)(param_1 + 0xe74 + lVar17) = 0;
        *(undefined1 *)(param_1 + 0xe72 + lVar17) = 0;
        if (*(char *)(param_1 + 0xe75 + lVar17) != '\x01') {
          *(undefined1 *)(param_1 + 0xe75 + lVar17) = 1;
          *(char *)(param_1 + 0x7676) = *(char *)(param_1 + 0x7676) + '\x01';
        }
      }
    }
    lVar26 = *(longlong *)(param_1 + 0x58 + lVar17);
    bVar9 = *(byte *)(lVar26 + 0x28) & 0xf;
    if (((bVar9 == 0) && ((*(byte *)(lVar26 + 0x18) & 2) == 0)) && ((uVar11 & 0x40) != 0)) {
LAB_0001bab1:
      *(undefined1 *)(param_1 + 0x7682) = 0;
      *(undefined1 *)(param_1 + 0xe71 + lVar17) = 0;
      *(byte *)(param_1 + 0xe73 + lVar17) = (byte)local_res8[0];
      *(undefined1 *)(param_1 + 0xe74 + lVar17) = 0;
      if (*(char *)(param_1 + 0xe75 + lVar17) != '\x01') {
        *(undefined1 *)(param_1 + 0xe75 + lVar17) = 1;
        *(char *)(param_1 + 0x7676) = *(char *)(param_1 + 0x7676) + '\x01';
      }
      *(undefined1 *)(param_1 + 0xe72 + lVar17) = 0;
    }
    else if ((uVar11 >> 0x16 & 1) == 0) {
      if ((uVar11 & 0x40) != 0) {
        *(undefined4 *)(lVar26 + 0x30) = 0x4000000;
        uVar12 = *(ulonglong *)(param_1 + 0x58 + lVar17);
        *(undefined4 *)(uVar12 + 0x10) = 0x40;
        *(int *)(param_1 + 0x765c) = *(int *)(param_1 + 0x765c) + 1;
        if (999 < *(uint *)(param_1 + 0x765c)) {
          lVar26 = *(longlong *)(param_1 + 0x58 + lVar17);
          lVar22 = 10;
          *(byte *)(lVar26 + 0x2c) = *(byte *)(lVar26 + 0x2c) & 0xf1 | 1;
          do {
            StorPortStallExecution(500);
            lVar22 = lVar22 + -1;
          } while (lVar22 != 0);
          pbVar1 = (byte *)(*(longlong *)(param_1 + 0x58 + lVar17) + 0x2c);
          *pbVar1 = *pbVar1 & 0xf0;
          do {
            uVar12 = StorPortStallExecution(500);
            lVar19 = lVar19 + -1;
          } while (lVar19 != 0);
          *(undefined4 *)(param_1 + 0x765c) = 0;
        }
        goto LAB_0001b7d1;
      }
    }
    else {
      if (bVar9 != 0) goto LAB_0001bab1;
      *(undefined1 *)(param_1 + 0x7682) = 1;
      pcVar24 = (char *)(param_1 + 0xe71 + lVar17);
      *pcVar24 = *pcVar24 + '\x01';
      if ((*(byte *)(param_1 + 0xd58 + lVar17) & 0x20) != 0) {
        *(undefined1 *)(param_1 + 0x7683) = 1;
      }
    }
    lVar26 = *(longlong *)(param_1 + 0x58 + lVar17);
    if (((*(byte *)(lVar26 + 0x28) & 0xf) != 3) && ((uVar11 & 0x40) != 0)) {
      *(byte *)(lVar26 + 0x2c) = *(byte *)(lVar26 + 0x2c) & 0xf1;
      *(byte *)(lVar26 + 0x2c) = *(byte *)(lVar26 + 0x2c) | 1;
      lVar26 = 10;
      do {
        StorPortStallExecution(500);
        lVar26 = lVar26 + -1;
      } while (lVar26 != 0);
      pbVar1 = (byte *)(*(longlong *)(param_1 + 0x58 + lVar17) + 0x2c);
      *pbVar1 = *pbVar1 & 0xf0;
      do {
        StorPortStallExecution(500);
        lVar19 = lVar19 + -1;
      } while (lVar19 != 0);
    }
    uVar15 = (byte)local_res8[0];
  }
  else {
    lVar19 = *(longlong *)(param_1 + 0x58 + lVar17);
    StorPortDebugPrint(0,"[FUNCTION] %s : Port %d PxSERR %lx PxIS %lx PxSSTS %lx\n","AHCIInterrupt",
                       uVar18 & 0xff,*(undefined4 *)(lVar19 + 0x30),*(undefined4 *)(lVar19 + 0x10),
                       *(undefined4 *)(lVar19 + 0x28));
    if ((uVar11 & 0x80) == 0) {
      if ((uVar11 & 0x40) != 0) {
        lVar19 = *(longlong *)(param_1 + 0x58 + lVar17);
        if ((*(byte *)(lVar19 + 0x18) & 1) != 0) {
          uVar12 = StorPortDebugPrint(0,
                                      "[FUNCTION] %s:Good,HotPlug Event PxIS %lx PxSERR %lx SSTS %lx at port %d\n"
                                      ,"AHCIInterrupt",uVar11,*(undefined4 *)(lVar19 + 0x30),
                                      *(undefined4 *)(lVar19 + 0x28),uVar18 & 0xff);
          *(undefined4 *)(*(longlong *)(param_1 + 0x58 + lVar17) + 0x30) = 0xffffffff;
          *(uint *)(*(longlong *)(param_1 + 0x58 + lVar17) + 0x10) = uVar11;
          goto LAB_0001b7d1;
        }
        *(undefined1 *)(param_1 + 0x7682) = 0;
        *(undefined1 *)(param_1 + 0xe71 + lVar17) = 0;
        *(undefined1 *)(param_1 + 0xe74 + lVar17) = 0;
        *(byte *)(param_1 + 0xe73 + lVar17) = (byte)local_res8[0];
        if (*(char *)(param_1 + 0xe75 + lVar17) != '\x01') {
          *(undefined1 *)(param_1 + 0xe75 + lVar17) = 1;
          *(char *)(param_1 + 0x7676) = *(char *)(param_1 + 0x7676) + '\x01';
        }
        *(undefined1 *)(param_1 + 0xe72 + lVar17) = 0;
      }
    }
    else {
      if (*(char *)(param_1 + 0x768c) == '\0') {
        lVar19 = *(longlong *)(param_1 + 0x58 + lVar17);
        *(byte *)(lVar19 + 0x2c) = *(byte *)(lVar19 + 0x2c) & 0xf1 | 1;
        lVar19 = 10;
        do {
          lVar26 = lVar19;
          StorPortStallExecution(500);
          lVar19 = lVar26 + -1;
        } while (lVar19 != 0);
        uVar25 = (ulonglong)((int)lVar26 + 0x13);
        pbVar1 = (byte *)(*(longlong *)(param_1 + 0x58 + lVar17) + 0x2c);
        *pbVar1 = *pbVar1 & 0xf0;
        do {
          StorPortStallExecution(500);
          uVar25 = uVar25 - 1;
        } while (uVar25 != 0);
      }
      else {
        pbVar1 = (byte *)(*(longlong *)(param_1 + 0x58 + lVar17) + 0x18);
        *pbVar1 = *pbVar1 & 0xfd;
        lVar19 = 10;
        do {
          lVar26 = lVar19;
          StorPortStallExecution(500);
          lVar19 = lVar26 + -1;
        } while (lVar19 != 0);
        uVar25 = (ulonglong)((int)lVar26 + 0x13);
        pbVar1 = (byte *)(*(longlong *)(param_1 + 0x58 + lVar17) + 0x18);
        *pbVar1 = *pbVar1 | 2;
        do {
          StorPortStallExecution(500);
          uVar25 = uVar25 - 1;
        } while (uVar25 != 0);
      }
      if (((*(byte *)(*(longlong *)(param_1 + 0x58 + lVar17) + 0x28) & 0xf) == 0) ||
         ((*(byte *)(param_1 + 0xd58 + lVar17) & 0x20) != 0)) {
        pbVar1 = (byte *)(param_1 + 0xd58 + lVar17);
        *pbVar1 = *pbVar1 & 0xbf;
        *(undefined1 *)(param_1 + 0x7682) = 1;
        if ((*(byte *)(param_1 + 0xd58 + lVar17) & 0x20) != 0) {
          *(undefined1 *)(param_1 + 0x7683) = 1;
        }
      }
      else {
        *(undefined1 *)(param_1 + 0x7682) = 0;
        *(undefined1 *)(param_1 + 0xe71 + lVar17) = 0;
        *(undefined1 *)(param_1 + 0xe74 + lVar17) = 0;
        *(undefined1 *)(param_1 + 0xe72 + lVar17) = 0;
        *(byte *)(param_1 + 0xe73 + lVar17) = (byte)local_res8[0];
        if (*(char *)(param_1 + 0xe75 + lVar17) != '\x01') {
          *(undefined1 *)(param_1 + 0xe75 + lVar17) = 1;
          *(char *)(param_1 + 0x7676) = *(char *)(param_1 + 0x7676) + '\x01';
        }
      }
    }
    *(undefined1 *)(param_1 + 0x7686) = 1;
    uVar15 = (byte)local_res8[0];
  }
  *(undefined4 *)(*(longlong *)(param_1 + 0x58 + lVar17) + 0x30) = 0xffffffff;
  local_res8[0] = 0;
  *(uint *)(*(longlong *)(param_1 + 0x58 + lVar17) + 0x10) = uVar11;
  **(undefined4 **)(param_1 + 0x20) = *(undefined4 *)(param_1 + 0xe7c + lVar17);
  *(undefined1 *)(param_1 + 0x751a) = uVar15;
  *(undefined1 *)(param_1 + 0x751b) = 0;
  *(undefined4 *)(*(longlong *)(param_1 + 0x58 + lVar17) + 0x14) = 0;
  StorPortNotification(0x1002,param_1,param_1 + 0x7768,0,0,local_res8);
  uVar12 = 0;
  *(char *)(param_1 + 0x7678) =
       (char)((ulonglong)(byte)(*(char *)(param_1 + 0x7678) + 1) %
             (ulonglong)(longlong)(int)(uint)*(byte *)(param_1 + 0x767e));
LAB_0001b7d1:
  return CONCAT71((int7)(uVar12 >> 8),1);
LAB_0001c202:
  bVar9 = 0;
  if (*(char *)(param_1 + 0x767e) != '\0') {
    do {
      lVar19 = (ulonglong)bVar9 * 0xe28;
      if ((*(int *)(lVar19 + 0xe60 + param_1) == 0) && (*(int *)(lVar19 + 0xe64 + param_1) == 0)) {
        uVar11 = *(uint *)(lVar19 + 0xe68 + param_1);
        *(undefined1 *)(lVar19 + 0xe70 + param_1) = 0;
        if (uVar11 != 0) {
          bVar14 = 0;
          for (uVar21 = uVar11; (uVar21 != 0 && ((uVar21 & 1) == 0)); uVar21 = uVar21 >> 1) {
            bVar14 = bVar14 + 1;
          }
          uVar21 = 1 << (bVar14 & 0x1f);
          *(uint *)(lVar19 + 0xe68 + param_1) = ~uVar21 & uVar11;
          lVar17 = *(longlong *)
                    (param_1 + 0xd60 + ((ulonglong)bVar9 * 0x1c5 + (ulonglong)bVar14) * 8);
          if (lVar17 == 0) {
            uVar12 = StorPortDebugPrint(0,"[FUNCTION] %s :HoldingCI is not ZERO, But CCB is NULL\n",
                                        "AHCIInterrupt");
          }
          else {
            cVar4 = *(char *)(lVar17 + 5);
            uVar12 = *(ulonglong *)(lVar19 + 0x58 + param_1);
            *(uint *)(lVar19 + 0xe60 + param_1) = uVar21;
            if (cVar4 == '\x02') {
              *(uint *)(lVar19 + 0xe64 + param_1) = uVar21;
              *(uint *)(uVar12 + 0x38) = uVar21;
              uVar11 = *(uint *)(lVar19 + 0xe64 + param_1);
              uVar12 = (ulonglong)uVar11;
              *(uint *)(*(longlong *)(lVar19 + 0x58 + param_1) + 0x34) = uVar11;
            }
            else {
              *(uint *)(uVar12 + 0x38) = uVar21;
            }
          }
        }
      }
      bVar9 = bVar9 + 1;
    } while (bVar9 < *(byte *)(param_1 + 0x767e));
  }
  if ((*(char *)(param_1 + 0x7684) == '\x01') && (*(char *)(param_1 + 0x767a) != '\0')) {
    *(undefined1 *)(param_1 + 0x7684) = 0;
    *(byte *)(param_1 + 0x751a) = bVar9;
    if (*(int *)((ulonglong)bVar9 * 0xe28 + 0xe60 + param_1) != 0) {
      *(undefined1 *)(param_1 + 0x7685) = 1;
    }
    uVar12 = StorPortNotification(6,param_1,AHCIPMHotplugEventDetect,0x32);
  }
  bVar9 = 0;
  if (*(char *)(param_1 + 0x767e) != '\0') {
    do {
      lVar19 = (ulonglong)bVar9 * 0xe28;
      if ((*(byte *)(lVar19 + 0xd58 + param_1) & 4) != 0) {
        bVar14 = *(byte *)(lVar19 + 0xe78 + param_1);
        if ((bVar14 & 8) == 0) {
          lVar17 = *(longlong *)(lVar19 + 0x58 + param_1);
          if ((bVar14 & 4) == 0) {
            pbVar1 = (byte *)(lVar17 + 0x1b);
            *pbVar1 = *pbVar1 & 0xf7;
            uVar12 = *(ulonglong *)(lVar19 + 0x58 + param_1);
            *(byte *)(uVar12 + 0x1b) = *(byte *)(uVar12 + 0x1b) & 0xfb;
            goto LAB_0001c3af;
          }
          pbVar1 = (byte *)(lVar17 + 0x1b);
          *pbVar1 = *pbVar1 & 0xf7;
        }
        else {
          pbVar1 = (byte *)(*(longlong *)(lVar19 + 0x58 + param_1) + 0x1b);
          *pbVar1 = *pbVar1 | 8;
        }
        uVar12 = *(ulonglong *)(lVar19 + 0x58 + param_1);
        *(byte *)(uVar12 + 0x1b) = *(byte *)(uVar12 + 0x1b) | 4;
      }
LAB_0001c3af:
      bVar9 = bVar9 + 1;
    } while (bVar9 < *(byte *)(param_1 + 0x767e));
    if (*(char *)(param_1 + 0x767e) != '\0') {
      do {
        uVar12 = uVar25 * 0xe28;
        if ((*(byte *)(uVar12 + 0xd58 + param_1) & 4) != 0) {
          bVar9 = *(byte *)(uVar12 + 0xe78 + param_1);
          uVar12 = CONCAT71((int7)(uVar12 >> 8),bVar9);
          if (((((bVar9 & 8) == 0) && ((bVar9 & 4) == 0)) &&
              (((bVar9 & 0x10) != 0 || ((bVar9 & 0x20) != 0)))) && ((bVar9 & 3) == 0)) {
            uVar12 = StorPortNotification
                               (6,param_1,AHCIPartialEnableRoutine,
                                (uint)*(byte *)(uVar25 * 0xe28 + 0xe76 + param_1) * 1000000);
            break;
          }
        }
        bVar9 = (char)uVar25 + 1;
        uVar25 = (ulonglong)bVar9;
      } while (bVar9 < *(byte *)(param_1 + 0x767e));
    }
  }
  goto LAB_0001b7d1;
}



===== AHCIBuildSMARTCCB @ 0001d04c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 AHCIBuildSMARTCCB(longlong param_1,longlong param_2)

{
  byte bVar1;
  byte bVar2;
  longlong lVar3;
  int *piVar4;
  undefined8 uVar5;
  undefined1 *puVar6;
  undefined1 auStackY_88 [32];
  byte local_58 [4];
  uint local_54 [3];
  undefined1 local_48 [4];
  byte local_44;
  byte local_43;
  ulonglong local_40;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStackY_88;
  memcpy(local_48,(void *)(*(longlong *)(param_2 + 0x18) + 0x1c),0x21);
  if ((char)(local_40 >> 0x10) == -0x50) {
    lVar3 = (local_40 >> 0x20 & 0xff) * 0x100;
    bVar1 = *(byte *)(lVar3 + 0x3958 + param_1);
    bVar2 = *(byte *)(lVar3 + 0x3959 + param_1);
    if ((*(char *)(lVar3 + 0x3920 + param_1) == '\0') &&
       (*(char *)((ulonglong)bVar2 + 0x1fa + (ulonglong)bVar1 * 0xe28 + param_1) != '\x01')) {
      return 10;
    }
    piVar4 = (int *)StorPortGetScatterGatherList(param_1,param_2);
    lVar3 = *(longlong *)(param_2 + 0x38);
    *(undefined1 *)(lVar3 + 0x10b0) = 1;
    *(undefined1 *)(lVar3 + 0x10b1) = 0;
    puVar6 = (undefined1 *)(lVar3 + 0x20);
    *(undefined4 *)(lVar3 + 0x34) = 0;
    *puVar6 = 1;
    *(byte *)(lVar3 + 0x21) = local_44;
    *(byte *)(lVar3 + 0x22) = bVar1;
    *(byte *)(lVar3 + 0x23) = bVar2;
    *(undefined1 *)(lVar3 + 0x24) = 0x78;
    *(undefined1 *)(lVar3 + 0x25) = 0;
    if (0xcf < local_44) {
      if (local_44 < 0xd2) {
        *(undefined4 *)(lVar3 + 0x34) = 0x200;
      }
      else if ((0xd4 < local_44) && (local_44 < 0xd7)) {
        *(uint *)(lVar3 + 0x34) = (uint)local_43 << 9;
      }
    }
    if (((*(uint *)(lVar3 + 0x34) != 0) && (piVar4 != (int *)0x0)) && (*piVar4 != 0)) {
      local_54[1] = 0;
      local_54[0] = 0;
      local_58[0] = 0;
      *(undefined1 *)(lVar3 + 0x1c0) = 0;
      AHCIBuildSGList((longlong)piVar4,(longlong)puVar6,*(uint *)(lVar3 + 0x34),local_58,
                      local_54 + 1,local_54);
      if (*(int *)(puVar6 + 0xd0) == 0) {
        StorPortDebugPrint(0,"[FUNCTION] %s :Smart Command Failed \n","AHCIBuildSMARTCCB");
        goto LAB_0001d1b0;
      }
    }
    uVar5 = 1;
  }
  else {
LAB_0001d1b0:
    uVar5 = 4;
  }
  return uVar5;
}



===== AHCIBuildIo @ 0001d1e0 =====

undefined8 AHCIBuildIo(longlong param_1,longlong param_2)

{
  char cVar1;
  undefined8 in_RAX;
  longlong lVar2;
  undefined8 uVar3;
  
  if (*(char *)(param_2 + 2) == '\0') {
    cVar1 = *(char *)(param_2 + 0x48);
    uVar3 = CONCAT71((int7)((ulonglong)in_RAX >> 8),cVar1);
    if (((cVar1 == '*') || (cVar1 == '(')) || (cVar1 == '/')) {
      lVar2 = (ulonglong)*(byte *)(param_2 + 6) * 0x100;
      uVar3 = AHCIBuildCcb(param_1,param_2,*(byte *)(lVar2 + 0x3958 + param_1),
                           *(byte *)(lVar2 + 0x3959 + param_1));
    }
    cVar1 = *(char *)(param_2 + 0x48);
    in_RAX = CONCAT71((int7)((ulonglong)uVar3 >> 8),cVar1);
    if (((cVar1 == -0x76) || (cVar1 == -0x78)) || (cVar1 == -0x71)) {
      lVar2 = (ulonglong)*(byte *)(param_2 + 6) * 0x100;
      in_RAX = AHCIBuildCcb(param_1,param_2,*(byte *)(lVar2 + 0x3958 + param_1),
                            *(byte *)(lVar2 + 0x3959 + param_1));
    }
  }
  return CONCAT71((int7)((ulonglong)in_RAX >> 8),1);
}



===== AHCIResetDevice @ 0001d268 =====

undefined8 AHCIResetDevice(longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  byte *pbVar1;
  uint *puVar2;
  longlong lVar3;
  char cVar4;
  undefined8 uVar5;
  byte bVar6;
  ulonglong uVar7;
  longlong lVar8;
  ulonglong uVar9;
  byte bVar10;
  ulonglong uVar11;
  undefined8 uVar12;
  
  uVar5 = CONCAT71((int7)((ulonglong)param_4 >> 8),*(undefined1 *)(param_2 + 7));
  uVar12 = 1;
  StorPortDeviceBusy(param_1,*(undefined1 *)(param_2 + 5),*(undefined1 *)(param_2 + 6),uVar5,
                     0xffffffff);
  uVar9 = CONCAT71((int7)((ulonglong)uVar5 >> 8),*(undefined1 *)(param_2 + 7));
  StorPortCompleteRequest
            (param_1,*(undefined1 *)(param_2 + 5),*(undefined1 *)(param_2 + 6),uVar9,0xe);
  uVar11 = 0;
  if (*(short *)((ulonglong)*(byte *)(param_2 + 6) * 0x100 + 0x3922 + param_1) != 0) {
    do {
      lVar8 = param_1 + (ulonglong)*(byte *)(param_2 + 6) * 0x100;
      bVar10 = *(byte *)(uVar11 * 3 + 0x3958 + lVar8);
      bVar6 = *(byte *)(uVar11 * 3 + 0x3959 + lVar8);
      if ((char)uVar11 == '\0') {
        *(undefined1 *)((ulonglong)bVar10 * 0xe28 + 0xe6d + param_1) = 0;
        *(undefined1 *)((ulonglong)bVar10 * 0xe28 + 0xe6c + param_1) = 0;
      }
      lVar8 = (ulonglong)bVar10 * 0xe28;
      *(undefined4 *)(*(longlong *)(lVar8 + 0x58 + param_1) + 0x14) = 0;
      if ((*(byte *)(lVar8 + 0xd58 + param_1) & 0x20) == 0) {
        uVar5 = AHCIPortReset(param_1,bVar10);
        cVar4 = (char)uVar5;
      }
      else {
        uVar5 = AHCIPMHardReset(param_1,bVar10,bVar6,uVar9);
        cVar4 = (char)uVar5;
      }
      if (cVar4 == '\0') {
        uVar9 = (ulonglong)bVar10;
        StorPortDebugPrint(0,
                           "[FUNCTION] %s : PortReset for DeviceReset Failed at port %d subport %d\n"
                           ,"AHCIResetDevice",uVar9,bVar6);
        *(undefined1 *)(lVar8 + 0xe6f + param_1) = 1;
        uVar12 = 0;
      }
      if (*(char *)(param_1 + 0x767d) != '\0') {
        uVar7 = 0;
        do {
          bVar6 = (char)uVar7 + 1;
          *(undefined8 *)(param_1 + 0xd60 + (uVar7 + (ulonglong)bVar10 * 0x1c5) * 8) = 0;
          uVar7 = (ulonglong)bVar6;
        } while (bVar6 < *(byte *)(param_1 + 0x767d));
      }
      *(undefined4 *)(lVar8 + 0xe68 + param_1) = 0;
      *(undefined4 *)(lVar8 + 0xe64 + param_1) = 0;
      *(undefined4 *)(lVar8 + 0xe60 + param_1) = 0;
      pbVar1 = (byte *)(*(longlong *)(lVar8 + 0x58 + param_1) + 0x18);
      *pbVar1 = *pbVar1 | 1;
      lVar3 = *(longlong *)(lVar8 + 0x58 + param_1);
      if ((*(byte *)(lVar8 + 0xd58 + param_1) & 4) == 0) {
        *(undefined4 *)(lVar3 + 0x14) = 0x78c000cb;
      }
      else {
        *(undefined4 *)(lVar3 + 0x14) = 0x788000cb;
      }
      if ((*(byte *)(lVar8 + 0xe78 + param_1) & 0x80) != 0) {
        puVar2 = (uint *)(*(longlong *)(lVar8 + 0x58 + param_1) + 0x14);
        *puVar2 = *puVar2 & 0xfffffff0;
      }
      if ((*(char *)(param_1 + 0x768f) != '\0') &&
         ((*(byte *)(lVar8 + 0xd58 + param_1) & 0x20) != 0)) {
        puVar2 = (uint *)(*(longlong *)(lVar8 + 0x58 + param_1) + 0x14);
        *puVar2 = *puVar2 | 8;
      }
      bVar10 = (char)uVar11 + 1;
      uVar11 = (ulonglong)bVar10;
    } while ((ushort)bVar10 <
             *(ushort *)((ulonglong)*(byte *)(param_2 + 6) * 0x100 + 0x3922 + param_1));
  }
  StorPortDeviceReady(param_1,*(undefined1 *)(param_2 + 5),*(undefined1 *)(param_2 + 6),
                      *(undefined1 *)(param_2 + 7));
  return uVar12;
}



===== AHCIStartIO @ 0001d478 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 AHCIStartIO(longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  char cVar1;
  byte bVar2;
  uint uVar3;
  undefined8 uVar4;
  uint7 extraout_var;
  ulonglong uVar5;
  byte bVar6;
  longlong lVar7;
  longlong lVar8;
  undefined1 *puVar9;
  uint uVar10;
  longlong lVar11;
  byte bVar12;
  undefined1 *puVar13;
  byte *pbVar14;
  int iVar15;
  ulonglong uVar16;
  ushort uVar17;
  longlong lVar18;
  undefined1 auStackY_138 [32];
  byte local_d8;
  undefined1 local_d0 [10];
  char cStack_c6;
  uint5 uStack_c5;
  char local_a8;
  undefined1 local_a7;
  undefined1 local_a6;
  undefined1 local_a5;
  undefined1 local_a4;
  undefined1 local_a3;
  undefined1 local_a2;
  undefined1 local_a1;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined1 local_94 [16];
  undefined1 local_84 [44];
  ulonglong local_58;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_138;
  *(undefined1 *)(param_2 + 3) = 1;
  lVar8 = (ulonglong)*(byte *)(param_2 + 6) * 0x100;
  uVar10 = 1;
  bVar6 = *(byte *)(lVar8 + 0x3958 + param_1);
  uVar16 = (ulonglong)bVar6;
  bVar12 = *(byte *)(lVar8 + 0x3959 + param_1);
  uVar4 = CONCAT71((int7)((ulonglong)param_3 >> 8),bVar12);
  if ((*(char *)(param_1 + 0x7681) == '\0') && (*(char *)(param_1 + 0x7680) == '\0')) {
    *(undefined1 *)(param_2 + 3) = 5;
  }
  else {
    cVar1 = *(char *)(param_2 + 2);
    if (cVar1 == '\0') {
      if (*(char *)(param_1 + 0x7680) == '\x01') {
        StorPortNotification(6,param_1,AHCIWaitingAdapterReady,1);
        *(undefined1 *)(param_1 + 0x7680) = 0;
        *(undefined1 *)(param_2 + 3) = 5;
        goto LAB_0001e60c;
      }
      if (*(char *)((ulonglong)bVar12 + 0x1fa + (ulonglong)bVar6 * 0xe28 + param_1) == '\x11') {
        uVar5 = AHCIExecuteAtapiCommand(param_1,param_2);
      }
      else {
        uVar5 = AHCIExecuteIDECommand(param_1,param_2);
      }
      uVar10 = (uint)uVar5;
      if ((*(char *)(param_1 + 0x7687) == '\x01') && (*(char *)(param_1 + 0x7688) == '\x01')) {
        *(undefined1 *)(param_1 + 0x7688) = 0;
        AHCIWmiFireEvent(param_1);
        uVar5 = (ulonglong)extraout_var << 8;
      }
LAB_0001e5cd:
      if (uVar10 == 0) goto LAB_0001e616;
LAB_0001e5d2:
      if (uVar10 == 0x78) goto LAB_0001e616;
    }
    else if (cVar1 == '\x02') {
      lVar7 = *(longlong *)(param_2 + 0x18);
      pbVar14 = &s_SCSIDISK;
      iVar15 = 8;
      do {
        bVar6 = pbVar14[lVar7 + -0x211fc];
        bVar12 = *pbVar14;
        pbVar14 = pbVar14 + 1;
        if (bVar6 != bVar12) {
          if ((byte)(bVar6 + 0xbf) < 0x1a) {
            bVar6 = bVar6 + 0x20;
          }
          if ((byte)(bVar12 + 0xbf) < 0x1a) {
            bVar12 = bVar12 + 0x20;
          }
          if (bVar6 != bVar12) {
            iVar15 = (uint)bVar6 - (uint)bVar12;
            goto LAB_0001d8a6;
          }
        }
        iVar15 = iVar15 + -1;
      } while ((iVar15 != 0) && (bVar6 != 0));
      iVar15 = 0;
LAB_0001d8a6:
      if (iVar15 == 0) {
        uVar3 = *(uint *)(lVar7 + 0x10);
        if (uVar3 < 0x1b0532) {
          if (uVar3 == 0x1b0531) {
            memcpy(local_d0,(void *)(lVar7 + 0x1c),0x24);
            bVar6 = (byte)(uStack_c5 >> 8);
            if (bVar6 < 0x3c) {
              lVar8 = (ulonglong)bVar6 * 0x100;
              cVar1 = *(char *)(lVar8 + 0x3924 + param_1);
              if (cVar1 != '\0') {
                local_a7 = *(undefined1 *)(lVar8 + 0x3a15 + param_1);
                local_a6 = *(undefined1 *)(lVar8 + 0x3a14 + param_1);
                local_a5 = *(undefined1 *)(lVar8 + 0x3920 + param_1);
                local_a3 = *(undefined1 *)(lVar8 + 0x3922 + param_1);
                local_a1 = *(undefined1 *)(lVar8 + 0x3a16 + param_1);
                local_58 = *(ulonglong *)(lVar8 + 0x3928 + param_1);
                if (local_58 < 0x100000000) {
                  local_a0 = (undefined4)local_58;
                  local_58 = 0;
                }
                else {
                  local_a0 = 0xffffffff;
                }
                local_9c = *(undefined4 *)(lVar8 + 0x3a0c + param_1);
                puVar9 = local_94;
                puVar13 = (undefined1 *)(lVar8 + 0x3958 + param_1);
                local_98 = *(undefined4 *)(lVar8 + 0x391c + param_1);
                lVar18 = 4;
                do {
                  lVar11 = lVar18;
                  if (puVar13[2] == 'Z') {
                    *puVar9 = *puVar13;
                    puVar9[1] = puVar13[1];
                  }
                  else {
                    *puVar9 = 0xff;
                  }
                  puVar13 = puVar13 + 3;
                  puVar9 = puVar9 + 2;
                  lVar18 = lVar11 + -1;
                } while (lVar18 != 0);
                local_a8 = cVar1;
                local_a4 = local_a5;
                local_a2 = local_a3;
                memcpy(local_84,(void *)(lVar8 + 0x3930 + param_1),(ulonglong)((int)lVar11 + 0x27));
                memcpy((void *)(lVar7 + 0x2c),&local_a8,0x58);
                *(undefined4 *)(lVar7 + 0x1c) = 0x58;
                goto LAB_0001dfd8;
              }
            }
            goto LAB_0001d91c;
          }
          if (uVar3 == 0x1b0500) {
            *(undefined1 *)(lVar7 + 0x1c) = 1;
            *(undefined1 *)(lVar7 + 0x1d) = 1;
            *(undefined1 *)(lVar7 + 0x1e) = 0;
            *(undefined4 *)(lVar7 + 0x20) = 7;
            *(char *)(lVar7 + 0x1f) = '\x01' << (*(byte *)(param_2 + 6) & 0x1f);
          }
          else if (uVar3 == 0x1b0501) {
            memcpy(local_d0,(undefined4 *)(lVar7 + 0x1c),0x21);
            lVar8 = ((ulonglong)(uStack_c5 >> 8) & 0xff) * 0x100;
            if ((*(char *)(lVar8 + 0x3920 + param_1) == '\0') &&
               (*(char *)(lVar8 + 0x3a15 + param_1) != '\x01')) {
              bVar6 = *(byte *)(lVar8 + 0x3958 + param_1);
              uVar16 = (ulonglong)bVar6;
              local_d8 = *(byte *)(lVar8 + 0x3959 + param_1);
              if (bVar6 < 4) {
                lVar8 = (ulonglong)bVar6 * 0xe28;
                cVar1 = *(char *)((ulonglong)local_d8 + param_1 + 0x1fa + lVar8);
                if ((cVar1 == '\x01') || (cVar1 == '\x11')) {
                  if ((*(byte *)(param_1 + 0xe78 + lVar8) & 3) != 0) {
                    lVar18 = *(longlong *)(param_1 + 0x58 + lVar8);
                    *(byte *)(lVar18 + 0x1b) = *(byte *)(lVar18 + 0x1b) & 0xf | 0x10;
                    pbVar14 = (byte *)(param_1 + 0xe78 + lVar8);
                    *pbVar14 = *pbVar14 & 0xfc;
                    uVar17 = 0;
                    do {
                      lVar18 = *(longlong *)(param_1 + 0x58 + lVar8);
                      if (((*(byte *)(lVar18 + 0x29) & 0xf) != 6) &&
                         ((*(byte *)(lVar18 + 0x28) & 0xf) == 3)) break;
                      StorPortStallExecution(500);
                      uVar17 = uVar17 + 1;
                    } while (uVar17 < 20000);
                    lVar18 = 0x14;
                    *(undefined4 *)(*(longlong *)(param_1 + 0x58 + lVar8) + 0x30) = 0xffffffff;
                    *(undefined4 *)(*(longlong *)(param_1 + 0x58 + lVar8) + 0x10) = 0xffffffff;
                    do {
                      StorPortStallExecution();
                      lVar18 = lVar18 + -1;
                    } while (lVar18 != 0);
                  }
                  *(undefined4 *)(lVar7 + 0x1c) = 0x200;
                  *(undefined1 *)(lVar7 + 0x20) = 0;
                  *(undefined1 *)(lVar7 + 0x21) = 0;
                  iVar15 = *(int *)(*(longlong *)(param_1 + 0x58 + lVar8) + 0x34);
                  for (uVar10 = 0; (iVar15 != 0 && (uVar10 < 6000)); uVar10 = uVar10 + 1) {
                    StorPortStallExecution();
                    iVar15 = *(int *)(*(longlong *)(param_1 + 0x58 + lVar8) + 0x34);
                  }
                  iVar15 = *(int *)(*(longlong *)(param_1 + 0x58 + lVar8) + 0x38);
                  for (uVar10 = 0; (iVar15 != 0 && (uVar10 < 10000)); uVar10 = uVar10 + 1) {
                    StorPortStallExecution();
                    iVar15 = *(int *)(*(longlong *)(param_1 + 0x58 + lVar8) + 0x38);
                  }
                  lVar8 = *(longlong *)(param_1 + 0x58 + lVar8);
                  if ((*(int *)(lVar8 + 0x34) != 0) || (*(int *)(lVar8 + 0x38) != 0)) {
                    StorPortDebugPrint(0,
                                       "[FUNCTION] %s :PxSACT : %lx ,PxCI %lx, CI %lx at port %d\n",
                                       "AHCIStartIO");
                  }
                  goto LAB_0001de3e;
                }
              }
            }
            uVar10 = 10;
          }
          else if (0x1b0501 < uVar3) {
            if (uVar3 < 0x1b050a) {
              if ((*(char *)(lVar8 + 0x3920 + param_1) == '\0') &&
                 (*(char *)(lVar8 + 0x3a15 + param_1) != '\x01')) {
                uVar5 = AHCIBuildSMARTCCB(param_1,param_2);
                uVar10 = (uint)uVar5;
                if (uVar10 == 1) {
                  uVar5 = AHCIRunCcb(param_1,param_2);
                  uVar10 = (uint)(byte)uVar5;
                }
                goto LAB_0001e5cd;
              }
            }
            else if (uVar3 == 0x1b0530) {
              memcpy(local_d0,(void *)(lVar7 + 0x1c),0x24);
              bVar6 = (byte)(uStack_c5 >> 8);
              if ((bVar6 < 0x3c) &&
                 (lVar8 = (ulonglong)bVar6 * 0x100, *(char *)(param_1 + 0x3924 + lVar8) != '\0')) {
                StorPortSetBusDataByOffset
                          (param_1,4,*(undefined4 *)(param_1 + 0x764c),
                           *(undefined4 *)(param_1 + 0x7650));
                if (*(short *)(param_1 + 0x3922 + lVar8) != 0) {
                  uVar17 = 0;
                  do {
                    lVar7 = (ulonglong)uVar17 + param_1 + (ulonglong)uVar17 * 2;
                    bVar6 = *(byte *)(lVar7 + 0x3959 + lVar8);
                    bVar12 = *(byte *)(lVar7 + 0x3958 + lVar8);
                    uVar16 = (ulonglong)bVar12;
                    *(undefined1 *)(param_1 + 0x76b4) = 0x27;
                    lVar7 = uVar16 * 0xe28;
                    *(byte *)(param_1 + 0x76b5) =
                         *(byte *)(param_1 + 0x76b5) & 0xe0 | bVar6 & 0x1f | 0x80;
                    bVar2 = *(byte *)((ulonglong)bVar6 * 0xc0 + param_1 + 0x2c1 + lVar7);
                    *(undefined2 *)(param_1 + 0x7696) = 0;
                    *(undefined1 *)(param_1 + 0x7694) = 5;
                    *(undefined4 *)(param_1 + 0x7698) = 0;
                    *(byte *)(param_1 + 0x76b6) = (-((bVar2 & 2) != 0) & 3U) - 0x19;
                    *(byte *)(param_1 + 0x7695) = *(byte *)(param_1 + 0x7695) & 8 | bVar6 << 4;
                    iVar15 = *(int *)(*(longlong *)(param_1 + 0x58 + lVar7) + 0x34);
                    for (uVar10 = 0; (iVar15 != 0 && (uVar10 < 6000)); uVar10 = uVar10 + 1) {
                      StorPortStallExecution(500);
                      iVar15 = *(int *)(*(longlong *)(param_1 + 0x58 + lVar7) + 0x34);
                    }
                    iVar15 = *(int *)(*(longlong *)(param_1 + 0x58 + lVar7) + 0x38);
                    for (uVar10 = 0; (iVar15 != 0 && (uVar10 < 6000)); uVar10 = uVar10 + 1) {
                      StorPortStallExecution(500);
                      iVar15 = *(int *)(*(longlong *)(param_1 + 0x58 + lVar7) + 0x38);
                    }
                    lVar18 = *(longlong *)(param_1 + 0x58 + lVar7);
                    if ((*(int *)(lVar18 + 0x34) != 0) || (*(int *)(lVar18 + 0x38) != 0)) {
                      StorPortDebugPrint(0,
                                         "[FUNCTION] %s :PxSACT : %lx ,PxCI %lx, CI %lx at port %d\n"
                                         ,"AHCIStartIO");
                    }
                    uVar5 = AHCIGetFreeCommandSlot(param_1,bVar12,bVar6,'\0');
                    AHCIFillCommand(param_1,bVar12,bVar6,(void *)0x0,0,(byte)uVar5,'\0');
                    uVar5 = AHCIWaitForCommandComplete(param_1,bVar12,bVar6,'\0',100);
                    if ((char)uVar5 == '\0') {
                      if (*(char *)(param_1 + 0xe6e + lVar7) != '\0') {
                        uVar4 = AHCIPortReset(param_1,bVar12);
                        if ((char)uVar4 == '\0') {
                          *(undefined1 *)(param_1 + 0xe6f + lVar7) = 1;
                        }
                        else {
                          *(undefined1 *)(param_1 + 0xe6e + lVar7) = 0;
                        }
                      }
                      StorPortDebugPrint(0,
                                         "[FUNCTION] %s :SRB_FUNCTION_SHUTDOWN: IDE_STATUS_BUSY %lx dev = %x Cdb = %x\n"
                                         ,"AHCIStartIO",
                                         *(undefined1 *)
                                          (*(longlong *)(param_1 + 0x58 + lVar7) + 0x20));
                    }
                    uVar17 = uVar17 + 1;
                  } while (uVar17 < *(ushort *)(param_1 + 0x3922 + lVar8));
                }
                StorPortSetBusDataByOffset
                          (param_1,4,*(undefined4 *)(param_1 + 0x764c),
                           *(undefined4 *)(param_1 + 0x7650));
                goto LAB_0001d845;
              }
              goto LAB_0001d91c;
            }
          }
        }
        else {
          if (uVar3 == 0x1b0535) {
            for (uVar17 = 0;
                (*(char *)(param_1 + 0x767f) != '\0' && (uVar17 < *(byte *)(param_1 + 0x767e)));
                uVar17 = uVar17 + 1) {
              AHCIGetRaidInfo(param_1,(byte)uVar17);
            }
            AHCICheckRaidInfo(param_1);
            *(undefined4 *)(lVar7 + 0x1c) = 0;
            *(undefined1 *)(lVar7 + 0x20) = 0;
            *(undefined1 *)(lVar7 + 0x21) = 0;
            uVar5 = StorPortNotification(7);
            *(undefined1 *)(param_1 + 0x7686) = 1;
            uVar10 = 1;
            goto LAB_0001e5cd;
          }
          if (uVar3 == 0x1b0536) {
            memcpy(local_d0,(undefined4 *)(lVar7 + 0x1c),0x24);
            uVar16 = (ulonglong)(uStack_c5 >> 8);
            bVar6 = (byte)(uStack_c5 >> 8);
            if (bVar6 < 4) {
              lVar8 = (ulonglong)bVar6 * 0xe28;
              cVar1 = *(char *)(((ulonglong)(uStack_c5 >> 0x10) & 0xff) + param_1 + 0x1fa + lVar8);
              if ((cVar1 == '\x01') || (cVar1 == '\x11')) {
                uVar10 = 6;
                if ((*(byte *)(param_1 + 0xe78 + lVar8) & 3) != 0) {
                  lVar18 = *(longlong *)(param_1 + 0x58 + lVar8);
                  *(byte *)(lVar18 + 0x1b) = *(byte *)(lVar18 + 0x1b) & 0xf | 0x10;
                  pbVar14 = (byte *)(param_1 + 0xe78 + lVar8);
                  *pbVar14 = *pbVar14 & 0xfc;
                  uVar17 = 0;
                  do {
                    lVar18 = *(longlong *)(param_1 + 0x58 + lVar8);
                    if (((*(byte *)(lVar18 + 0x29) & 0xf) != 6) &&
                       ((*(byte *)(lVar18 + 0x28) & 0xf) == 3)) break;
                    StorPortStallExecution(500);
                    uVar17 = uVar17 + 1;
                  } while (uVar17 < 20000);
                  lVar18 = 0x14;
                  *(undefined4 *)(*(longlong *)(param_1 + 0x58 + lVar8) + 0x30) = 0xffffffff;
                  *(undefined4 *)(*(longlong *)(param_1 + 0x58 + lVar8) + 0x10) = 0xffffffff;
                  do {
                    StorPortStallExecution(500);
                    lVar18 = lVar18 + -1;
                  } while (lVar18 != 0);
                }
                *(undefined4 *)(lVar7 + 0x1c) = 0x200;
                *(undefined1 *)(lVar7 + 0x20) = 0;
                *(undefined1 *)(lVar7 + 0x21) = 0;
                if ((cStack_c6 == -0x5f) || (cStack_c6 == -0x14)) {
                  iVar15 = *(int *)(*(longlong *)(param_1 + 0x58 + lVar8) + 0x34);
                  for (uVar10 = 0; (iVar15 != 0 && (uVar10 < 6000)); uVar10 = uVar10 + 1) {
                    StorPortStallExecution();
                    iVar15 = *(int *)(*(longlong *)(param_1 + 0x58 + lVar8) + 0x34);
                  }
                  iVar15 = *(int *)(*(longlong *)(param_1 + 0x58 + lVar8) + 0x38);
                  for (uVar10 = 0; (iVar15 != 0 && (uVar10 < 10000)); uVar10 = uVar10 + 1) {
                    StorPortStallExecution();
                    iVar15 = *(int *)(*(longlong *)(param_1 + 0x58 + lVar8) + 0x38);
                  }
                  lVar8 = *(longlong *)(param_1 + 0x58 + lVar8);
                  if ((*(int *)(lVar8 + 0x34) != 0) || (*(int *)(lVar8 + 0x38) != 0)) {
                    StorPortDebugPrint(0,
                                       "[FUNCTION] %s :PxSACT : %lx ,PxCI %lx, CI %lx at port %d\n",
                                       "AHCIStartIO");
                  }
                  local_d8 = (byte)(uStack_c5 >> 0x10);
LAB_0001de3e:
                  AHCIIssueIdentify(param_1,(byte)uVar16,local_d8);
                  memcpy((void *)(lVar7 + 0x2c),*(void **)(param_1 + 0x7520),0x200);
                  goto LAB_0001d845;
                }
                goto LAB_0001e5d9;
              }
            }
LAB_0001d91c:
            uVar10 = 10;
          }
          else {
            if (uVar3 != 0x1b0537) {
              uVar5 = (ulonglong)(uVar3 - 0x1b0538);
              if (uVar3 - 0x1b0538 == 0) {
                memcpy(local_d0,(void *)(lVar7 + 0x1c),(ulonglong)(uVar3 - 0x1b0514));
                uVar16 = (ulonglong)(uStack_c5 >> 8);
                if (*(char *)(lVar7 + 0x40) == '\x01') {
                  lVar8 = (uVar16 & 0xff) * 0xe28;
                  pbVar14 = (byte *)(lVar8 + 0xe78 + param_1);
                  *pbVar14 = *pbVar14 ^
                             (*(char *)(lVar7 + 0x46) << 2 ^ *(byte *)(lVar8 + 0xe78 + param_1)) & 4
                  ;
                  bVar6 = *(byte *)(lVar8 + 0xe78 + param_1);
                  bVar6 = (*(char *)(lVar7 + 0x49) << 3 ^ bVar6) & 8 ^ bVar6;
                  *(byte *)(lVar8 + 0xe78 + param_1) = bVar6;
                  bVar6 = (*(char *)(lVar7 + 0x47) << 4 ^ bVar6) & 0x10 ^ bVar6;
                  *(byte *)(lVar8 + 0xe78 + param_1) = bVar6;
                  bVar6 = (*(char *)(lVar7 + 0x4a) << 5 ^ bVar6) & 0x20 ^ bVar6;
                  *(byte *)(lVar8 + 0xe78 + param_1) = bVar6;
                  *(undefined1 *)(lVar8 + 0xe76 + param_1) = *(undefined1 *)(lVar7 + 0x48);
                  *(undefined1 *)(lVar8 + 0xe77 + param_1) = *(undefined1 *)(lVar7 + 0x4b);
                  pbVar14 = (byte *)(lVar8 + 0xd58 + param_1);
                  *pbVar14 = *pbVar14 ^
                             (*(char *)(lVar7 + 0x44) * '\x02' ^ *(byte *)(lVar8 + 0xd58 + param_1))
                             & 2;
                  pbVar14 = (byte *)(lVar8 + 0xe78 + param_1);
                  *pbVar14 = *pbVar14 ^ (*(char *)(lVar7 + 0x4d) << 6 ^ bVar6) & 0x40;
                  bVar6 = *(byte *)(lVar8 + 0xe78 + param_1);
                  if ((*(byte *)(lVar8 + 0xd58 + param_1) & 4) != 0) {
                    if (((bVar6 & 0x10) != 0) || ((bVar6 & 0x20) != 0)) {
                      pbVar14 = (byte *)(*(longlong *)(lVar8 + 0x58 + param_1) + 0x1b);
                      *pbVar14 = *pbVar14 & 0xfb;
                      pbVar14 = (byte *)(*(longlong *)(lVar8 + 0x58 + param_1) + 0x1b);
                      *pbVar14 = *pbVar14 & 0xf7;
                    }
                    if (((*(byte *)(lVar8 + 0xd58 + param_1) & 4) != 0) &&
                       ((bVar6 = *(byte *)(lVar8 + 0xe78 + param_1), (bVar6 & 4) != 0 ||
                        ((bVar6 & 8) != 0)))) {
                      lVar18 = *(longlong *)(lVar8 + 0x58 + param_1);
                      *(byte *)(lVar18 + 0x1b) = *(byte *)(lVar18 + 0x1b) & 0xf | 0x10;
                    }
                  }
                  if (((*(byte *)(lVar8 + 0xd58 + param_1) & 0x20) != 0) &&
                     ((*(byte *)(lVar8 + 0xe78 + param_1) & 0x40) != 0)) {
                    *(undefined1 *)(param_1 + 0x7684) = 1;
                    pbVar14 = (byte *)(lVar8 + 0xe78 + param_1);
                    *pbVar14 = *pbVar14 & 0xbf;
                  }
                  if ((*(char *)(param_1 + 0x7684) == '\x01') &&
                     (*(char *)(param_1 + 0x767a) != '\0')) {
                    uVar17 = 0;
                    do {
                      if (*(int *)((ulonglong)uVar17 * 0xe28 + 0xe60 + param_1) != 0) break;
                      uVar17 = uVar17 + 1;
                    } while (uVar17 <= (**(byte **)(param_1 + 0x10) & 0x1f));
                    *(undefined1 *)(param_1 + 0x7684) = 0;
                    StorPortNotification(6,param_1,AHCIPMHotplugEventDetect);
                  }
                  *(undefined4 *)(lVar7 + 0x1c) = 0;
                }
                else {
                  if (*(char *)(lVar7 + 0x40) != '\x02') {
                    *(undefined4 *)(lVar7 + 0x1c) = 0;
                    *(undefined1 *)(lVar7 + 0x20) = 0;
                    *(undefined1 *)(lVar7 + 0x21) = 0;
                    goto LAB_0001d53f;
                  }
                  lVar8 = (uVar16 & 0xff) * 0xe28;
                  if ((*(byte *)(lVar8 + 0xd58 + param_1) & 0x20) == 0) {
                    *(undefined1 *)(lVar7 + 0x38) = 0;
                    *(undefined1 *)(lVar7 + 0x2e) = 0;
                    *(undefined1 *)(lVar7 + 0x2d) = 1;
                  }
                  else {
                    bVar6 = *(byte *)(lVar8 + 0xe7a + param_1);
                    *(undefined1 *)(lVar7 + 0x2e) = 1;
                    *(byte *)(lVar7 + 0x38) = bVar6 >> 4 & 1;
                    *(undefined1 *)(lVar7 + 0x2d) = *(undefined1 *)(lVar8 + 0xd59 + param_1);
                  }
                  if ((*(byte *)(lVar8 + 0xd58 + param_1) & 4) == 0) {
                    *(undefined1 *)(lVar7 + 0x31) = 0;
                    *(undefined1 *)(lVar7 + 0x32) = 0;
                    *(undefined1 *)(lVar7 + 0x35) = 0;
                    *(undefined1 *)(lVar7 + 0x33) = 0;
                    *(undefined1 *)(lVar7 + 0x36) = 0;
                    *(undefined1 *)(lVar7 + 0x37) = 0;
                  }
                  else {
                    *(undefined1 *)(lVar7 + 0x31) = 1;
                    *(byte *)(lVar7 + 0x32) = *(byte *)(lVar8 + 0xe78 + param_1) >> 2 & 1;
                    *(byte *)(lVar7 + 0x35) = *(byte *)(lVar8 + 0xe78 + param_1) >> 3 & 1;
                    *(byte *)(lVar7 + 0x33) = *(byte *)(lVar8 + 0xe78 + param_1) >> 4 & 1;
                    *(undefined1 *)(lVar7 + 0x34) = *(undefined1 *)(lVar8 + 0xe76 + param_1);
                    *(byte *)(lVar7 + 0x36) = *(byte *)(lVar8 + 0xe78 + param_1) >> 5 & 1;
                    *(undefined1 *)(lVar7 + 0x37) = *(undefined1 *)(lVar8 + 0xe77 + param_1);
                  }
                  if ((*(byte *)(lVar8 + 0xd58 + param_1) & 1) == 0) {
                    *(undefined1 *)(lVar7 + 0x2f) = 0;
                    *(undefined1 *)(lVar7 + 0x30) = 0;
                  }
                  else {
                    *(undefined1 *)(lVar7 + 0x2f) = 1;
                    *(byte *)(lVar7 + 0x30) = *(byte *)(lVar8 + 0xd58 + param_1) >> 1 & 1;
                  }
                  *(undefined1 *)(lVar7 + 0x39) = 0;
                  *(undefined4 *)(lVar7 + 0x1c) = 0xe;
                }
LAB_0001dfd8:
                *(undefined1 *)(lVar7 + 0x20) = 0;
                *(undefined1 *)(lVar7 + 0x21) = 0;
                goto LAB_0001d845;
              }
              goto LAB_0001e5d2;
            }
            *(undefined4 *)(lVar7 + 0x30) = 0x300;
            *(uint *)(lVar7 + 0x34) = *(uint *)(param_1 + 0x7554) & 0xf;
            *(uint *)(lVar7 + 0x2c) = (uint)*(ushort *)(param_1 + 0x754e);
            *(undefined4 *)(lVar7 + 0x1c) = 0xc;
            *(undefined1 *)(lVar7 + 0x20) = 0;
            *(undefined1 *)(lVar7 + 0x21) = 0;
          }
        }
      }
      else {
LAB_0001d53f:
        uVar10 = 6;
      }
    }
    else if (cVar1 == '\a') {
      uVar17 = 0;
      if (*(short *)(lVar8 + 0x3922 + param_1) != 0) {
        do {
          lVar8 = param_1 + (ulonglong)*(byte *)(param_2 + 6) * 0x100;
          bVar6 = *(byte *)((ulonglong)uVar17 * 3 + 0x3958 + lVar8);
          uVar16 = (ulonglong)bVar6;
          bVar12 = *(byte *)((ulonglong)uVar17 * 3 + 0x3959 + lVar8);
          uVar10 = 0;
          lVar8 = uVar16 * 0xe28;
          bVar2 = *(byte *)(*(longlong *)(param_1 + 0x58 + lVar8) + 0x20);
          while ((bVar2 & 0x80) != 0) {
            if (299999 < uVar10) {
              StorPortDebugPrint(0,
                                 "[FUNCTION] %s :Time out,Waiting the BSY to be clear for 30 seconds.\n"
                                 ,"AHCIStartIO");
              break;
            }
            uVar10 = uVar10 + 1;
            StorPortStallExecution();
            bVar2 = *(byte *)(*(longlong *)(param_1 + 0x58 + lVar8) + 0x20);
          }
          if ((*(byte *)(*(longlong *)(param_1 + 0x58 + lVar8) + 0x20) & 0x80) != 0) {
            lVar8 = *(longlong *)(uVar16 * 0xe28 + 0x58 + param_1);
LAB_0001d811:
            StorPortDebugPrint(0,
                               "[FUNCTION] %s :SRB_FUNCTION_SHUTDOWN: IDE_STATUS_BUSY %lx dev = %x Cdb = %x\n"
                               ,"AHCIStartIO",*(undefined1 *)(lVar8 + 0x20));
            break;
          }
          *(undefined1 *)(param_1 + 0x76b4) = 0x27;
          *(byte *)(param_1 + 0x76b5) = *(byte *)(param_1 + 0x76b5) & 0xe0 | bVar12 & 0x1f | 0x80;
          bVar2 = *(byte *)((ulonglong)bVar12 * 0xc0 + param_1 + 0x2c1 + lVar8);
          *(undefined2 *)(param_1 + 0x7696) = 0;
          *(undefined1 *)(param_1 + 0x7694) = 5;
          *(undefined4 *)(param_1 + 0x7698) = 0;
          *(byte *)(param_1 + 0x76b6) = (-((bVar2 & 2) != 0) & 3U) - 0x19;
          *(byte *)(param_1 + 0x7695) = *(byte *)(param_1 + 0x7695) & 8 | bVar12 << 4;
          for (uVar10 = 0;
              (*(int *)(*(longlong *)(param_1 + 0x58 + lVar8) + 0x34) != 0 && (uVar10 < 6000));
              uVar10 = uVar10 + 1) {
            StorPortStallExecution(500);
          }
          for (uVar10 = 0;
              (*(int *)(*(longlong *)(param_1 + 0x58 + lVar8) + 0x38) != 0 && (uVar10 < 6000));
              uVar10 = uVar10 + 1) {
            StorPortStallExecution(500);
          }
          lVar8 = *(longlong *)(param_1 + 0x58 + lVar8);
          if ((*(int *)(lVar8 + 0x34) != 0) || (*(int *)(lVar8 + 0x38) != 0)) {
            StorPortDebugPrint(0,"[FUNCTION] %s :PxSACT : %lx ,PxCI %lx, CI %lx at port %d\n",
                               "AHCIStartIO");
          }
          uVar5 = AHCIGetFreeCommandSlot(param_1,bVar6,bVar12,'\0');
          AHCIFillCommand(param_1,bVar6,bVar12,(void *)0x0,0,(byte)uVar5,'\0');
          uVar5 = AHCIWaitForCommandComplete(param_1,bVar6,bVar12,'\0',100);
          if ((char)uVar5 == '\0') {
            lVar8 = uVar16 * 0xe28;
            if (*(char *)(lVar8 + 0xe6e + param_1) != '\0') {
              uVar4 = AHCIPortReset(param_1,bVar6);
              if ((char)uVar4 == '\0') {
                *(undefined1 *)(lVar8 + 0xe6f + param_1) = 1;
              }
              else {
                *(undefined1 *)(lVar8 + 0xe6e + param_1) = 0;
              }
            }
            lVar8 = *(longlong *)(lVar8 + 0x58 + param_1);
            goto LAB_0001d811;
          }
          uVar17 = uVar17 + 1;
        } while (uVar17 < *(ushort *)((ulonglong)*(byte *)(param_2 + 6) * 0x100 + 0x3922 + param_1))
        ;
      }
LAB_0001d845:
      uVar10 = 1;
    }
    else if ((cVar1 != '\b') && (cVar1 != '\x10')) {
      if (cVar1 == '\x12') {
        uVar4 = AHCIResetController(param_1,0,uVar4,param_4);
        if ((char)uVar4 == '\0') {
          StorPortLogError(param_1,0,0,0);
          uVar10 = 4;
        }
      }
      else {
        if (cVar1 != '\x13') {
          if (cVar1 == '\x17') {
            uVar4 = AHCIWmiSrb(param_1,param_2);
            return uVar4;
          }
          if (cVar1 != ' ') goto LAB_0001d53f;
        }
        uVar4 = AHCIResetDevice(param_1,param_2,uVar4,param_4);
        uVar10 = 4;
        if ((int)uVar4 == 1) {
          uVar10 = 1;
        }
      }
    }
LAB_0001e5d9:
    *(char *)(param_2 + 3) = (char)uVar10;
    if (*(int *)((uVar16 & 0xff) * 0xe28 + 0xe68 + param_1) == 0) {
      StorPortDeviceReady(param_1,*(undefined1 *)(param_2 + 5),*(undefined1 *)(param_2 + 6),
                          *(undefined1 *)(param_2 + 7));
    }
  }
LAB_0001e60c:
  uVar5 = StorPortNotification(0,param_1,param_2);
LAB_0001e616:
  return CONCAT71((int7)(uVar5 >> 8),1);
}



===== DriverEntry @ 0001e64c =====

uint DriverEntry(undefined8 param_1,undefined8 param_2)

{
  uint uVar1;
  uint uVar2;
  undefined1 local_res18;
  undefined1 local_res19;
  undefined1 local_res1a;
  undefined1 local_res1b;
  undefined1 local_res20;
  undefined1 local_res21;
  undefined1 local_res22;
  undefined1 local_res23;
  undefined1 local_a8;
  undefined1 local_a7;
  undefined1 local_a6;
  undefined1 local_a5;
  undefined4 local_98;
  undefined4 local_94;
  code *local_90;
  code *local_88;
  code *local_80;
  code *local_78;
  code *local_70;
  undefined1 *local_60;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined1 local_40;
  undefined1 local_3f;
  undefined1 local_3e;
  undefined1 local_3d;
  undefined1 local_3c;
  undefined2 local_3a;
  undefined1 *local_38;
  undefined2 local_2e;
  undefined1 *local_28;
  code *local_20;
  code *local_18;
  
  local_res18 = 0x31;
  local_res19 = 0x30;
  local_res1a = 0x33;
  local_res1b = 0x39;
  local_res20 = 0x31;
  local_res21 = 0x31;
  local_res22 = 0x38;
  local_res23 = 0x34;
  local_a8 = 0x31;
  local_a7 = 0x31;
  local_a6 = 0x38;
  local_a5 = 0x35;
  memset(&local_98,0,0x88);
  local_90 = AHCIHwinitialize;
  local_3a = 4;
  local_70 = AHCIResetController;
  local_2e = 4;
  local_88 = AHCIStartIO;
  local_80 = AHCIInterrupt;
  local_78 = AHCIFindController;
  local_60 = &AHCIAdapterState;
  local_20 = AHCIAdapterControl;
  local_98 = 0x88;
  local_18 = AHCIBuildIo;
  local_38 = &local_res18;
  local_58 = 0x7848;
  local_28 = &local_res20;
  local_54 = 8;
  local_4c = 6;
  local_3f = 1;
  local_3d = 1;
  local_3e = 1;
  local_3c = 1;
  local_50 = 0x10b8;
  local_40 = 2;
  local_94 = 5;
  uVar1 = StorPortInitialize(param_1,param_2,&local_98,0);
  local_28 = &local_a8;
  uVar2 = StorPortInitialize(param_1,param_2,&local_98,0);
  if (uVar2 < uVar1) {
    uVar1 = uVar2;
  }
  return uVar1;
}



===== AHCIWmiSrb @ 0001e7f4 =====

undefined8 AHCIWmiSrb(longlong param_1,longlong param_2)

{
  byte bVar1;
  char cVar2;
  undefined8 uVar3;
  uint local_res10 [2];
  int local_res18 [2];
  undefined1 local_28 [8];
  uint local_20;
  uint *local_18;
  byte local_10;
  char local_f;
  uint local_c;
  
  bVar1 = *(byte *)(param_2 + 4);
  local_res10[0] = 0;
  local_c = 0;
  if (bVar1 < 10) {
    local_20 = *(uint *)(param_2 + 0x10);
    local_18 = *(uint **)(param_2 + 0x18);
    local_10 = bVar1;
    cVar2 = ScsiWmipProcessRequest
                      ((uint *)(param_1 + 0x76c8),bVar1,param_1,local_28,
                       *(ulonglong **)(param_2 + 0x20),*(uint *)(param_2 + 0x10),
                       *(uint **)(param_2 + 0x18),local_res10,(short *)local_res18);
    if (local_res18[0] == 1) {
      local_c = local_res10[0];
      if (cVar2 != '\x01') {
        local_c = 0;
      }
      local_f = cVar2;
    }
  }
  else {
    local_f = '\x04';
  }
  *(char *)(param_2 + 3) = local_f;
  *(uint *)(param_2 + 0x10) = local_c;
  StorPortNotification(0,param_1,param_2);
  uVar3 = StorPortNotification(1,param_1);
  return CONCAT71((int7)((ulonglong)uVar3 >> 8),1);
}



===== AHCIWmiQueryDataBlock @ 0001e8f8 =====

char AHCIWmiQueryDataBlock
               (longlong param_1,longlong param_2,int param_3,undefined8 param_4,undefined8 param_5,
               undefined4 *param_6,uint param_7,undefined1 *param_8)

{
  char cVar1;
  ushort uVar2;
  byte bVar3;
  uint uVar4;
  char cVar5;
  char cVar6;
  ulonglong uVar7;
  longlong lVar8;
  ulonglong uVar9;
  longlong lVar10;
  byte bVar11;
  byte local_res8;
  byte local_res18;
  byte local_48;
  uint local_40;
  
  cVar5 = '\0';
  if (param_3 == 0) {
    uVar4 = 0xc50;
    local_40 = 0xc50;
    if (param_7 < 0xc50) {
      StorPortDebugPrint(0,"Data buffer is too small.(%lx)\n");
      cVar6 = '\x12';
    }
    else {
      uVar9 = 0;
      *param_6 = 0xc50;
      local_res8 = 0;
      param_8[0x15c] = *(undefined1 *)(param_1 + 0x767e);
      cVar6 = '\x01';
      *param_8 = *(undefined1 *)(param_1 + 0x7687);
      if (*(char *)(param_1 + 0x767e) != '\0') {
        local_48 = 0;
        do {
          lVar8 = uVar9 * 0xe28;
          param_8[uVar9 + 2] = *(byte *)(lVar8 + 0xd58 + param_1) >> 2 & 1;
          param_8[uVar9 + 6] = *(byte *)(lVar8 + 0xe78 + param_1) >> 2 & 1;
          param_8[uVar9 + 10] = *(byte *)(lVar8 + 0xe78 + param_1) >> 4 & 1;
          param_8[uVar9 + 0xe] = *(byte *)(lVar8 + 0xd58 + param_1) >> 2 & 1;
          param_8[uVar9 + 0x12] = *(byte *)(lVar8 + 0xe78 + param_1) >> 3 & 1;
          param_8[uVar9 + 0x16] = *(byte *)(lVar8 + 0xe78 + param_1) >> 5 & 1;
          param_8[uVar9 + 0x161] = *(undefined1 *)(lVar8 + 0xe76 + param_1);
          param_8[uVar9 + 0x165] = *(undefined1 *)(lVar8 + 0xe77 + param_1);
          param_8[uVar9 + 0x22] = *(byte *)(lVar8 + 0xd58 + param_1) & 1;
          param_8[uVar9 + 0x26] = *(byte *)(lVar8 + 0xd58 + param_1) >> 1 & 1;
          if ((*(byte *)(lVar8 + 0xd58 + param_1) & 0x20) == 0) {
            param_8[uVar9 + 0x15d] = 1;
          }
          else {
            param_8[uVar9 + 0x15d] = *(undefined1 *)(lVar8 + 0xd59 + param_1);
          }
          uVar7 = 0;
          local_res18 = 0;
          param_8[uVar9 + 0x1a] = *(byte *)(lVar8 + 0xd58 + param_1) >> 5 & 1;
          param_8[uVar9 + 0x2a] = *(byte *)(lVar8 + 0xe78 + param_1) >> 6 & 1;
          uVar4 = (uint)local_48;
          bVar11 = (byte)uVar9;
          bVar3 = local_48;
          if ((uint)local_48 < local_48 + 0xf) {
            do {
              uVar9 = (ulonglong)bVar3;
              lVar10 = uVar7 * 0xc0 + lVar8;
              memcpy(param_8 + (ulonglong)(uVar4 * 0x14) + 0x439,(void *)(lVar10 + 0x218 + param_1),
                     0x14);
              uVar2 = *(ushort *)(lVar10 + 0x2d0 + param_1);
              if ((uVar2 & 0xff00) == 0) {
                if ((uVar2 & 0xf0) == 0) {
                  cVar5 = ((byte)uVar2 & 0xf) + 1;
                }
                else if ((uVar2 & 0x400) == 0) {
                  if ((uVar2 & 0x200) == 0) {
                    if ((uVar2 & 0x100) != 0) {
                      cVar5 = '\x10';
                    }
                  }
                  else {
                    cVar5 = '\x11';
                  }
                }
                else {
                  cVar5 = '\x12';
                }
              }
              else if ((uVar2 & 0x8000) == 0) {
                if ((uVar2 & 0x4000) == 0) {
                  if ((uVar2 & 0x2000) == 0) {
                    if ((uVar2 & 0x1000) == 0) {
                      if ((uVar2 & 0x800) == 0) {
                        if ((uVar2 & 0x400) == 0) {
                          if ((uVar2 & 0x200) == 0) {
                            if ((uVar2 & 0x100) != 0) {
                              cVar5 = ' ';
                            }
                          }
                          else {
                            cVar5 = '!';
                          }
                        }
                        else {
                          cVar5 = '\"';
                        }
                      }
                      else {
                        cVar5 = '#';
                      }
                    }
                    else {
                      cVar5 = '$';
                    }
                  }
                  else {
                    cVar5 = '%';
                  }
                }
                else {
                  cVar5 = '&';
                }
              }
              else {
                cVar5 = '\'';
              }
              param_8[uVar9 + 0x169] = cVar5;
              cVar1 = *(char *)(lVar8 + (ulonglong)local_res18 + 0x1fa + param_1);
              if ((cVar1 == '\x01') || (cVar1 == '\x11')) {
                param_8[uVar9 + 0x2e] = 1;
              }
              else {
                param_8[uVar9 + 0x2e] = 0;
              }
              bVar11 = *(byte *)(lVar8 + 0xd58 + param_1);
              if ((((bVar11 & 1) == 0) || ((bVar11 & 2) == 0)) || ((bVar11 & 0x20) != 0)) {
                param_8[uVar9 + 0x1a5] = cVar5;
              }
              else {
                param_8[uVar9 + 0x1a5] = 0x30;
              }
              *(int *)(param_8 + uVar9 * 4 + 0x6c) =
                   (int)(*(ulonglong *)(lVar10 + 0x2c8 + param_1) >> 0x15);
              local_res18 = local_res18 + 1;
              uVar7 = (ulonglong)local_res18;
              param_8[uVar9 + 0x259] = ((*(byte *)(lVar10 + 0x2c2 + param_1) & 0x80) != 0) + '\x01';
              param_8[uVar9 + 0x3fd] = *(byte *)(lVar10 + 0x2c1 + param_1) >> 6 & 1;
              param_8[uVar9 + 0x1e1] = *(byte *)(lVar10 + 0x2c2 + param_1) >> 4 & 1;
              param_8[uVar9 + 0x2d1] = *(byte *)(lVar10 + 0x2c2 + param_1) >> 3 & 1;
              param_8[uVar9 + 0x295] = *(byte *)(lVar10 + 0x2c1 + param_1) >> 7;
              param_8[uVar9 + 0x21d] = *(byte *)(lVar10 + 0x2c2 + param_1) >> 5 & 1;
              param_8[uVar9 + 0x30d] = *(byte *)(lVar10 + 0x2c3 + param_1) & 1;
              param_8[uVar9 + 0x349] = *(byte *)(lVar10 + 0x2c3 + param_1) >> 1 & 1;
              param_8[uVar9 + 0x385] = *(byte *)(lVar10 + 0x2c3 + param_1) >> 2 & 1;
              param_8[uVar9 + 0x3c1] = *(byte *)(lVar10 + 0x2c3 + param_1) >> 3 & 1;
              uVar4 = (uint)(byte)(bVar3 + 1);
              bVar3 = bVar3 + 1;
            } while (uVar4 < local_48 + 0xf);
            bVar11 = local_res8;
          }
          local_res8 = bVar11 + 1;
          uVar9 = (ulonglong)local_res8;
          local_48 = local_48 + 0xf;
        } while (local_res8 < *(byte *)(param_1 + 0x767e));
        uVar4 = local_40;
      }
    }
  }
  else {
    cVar6 = '\x06';
    uVar4 = 0;
  }
  ScsiPortWmiPostProcess(param_2,cVar6,uVar4);
  return cVar6;
}



===== AHCIWmiSetDataBlock @ 0001ed74 =====

char AHCIWmiSetDataBlock(longlong param_1,longlong param_2,int param_3,undefined8 param_4,
                        uint param_5,longlong param_6)

{
  byte *pbVar1;
  longlong lVar2;
  byte bVar3;
  ulonglong uVar4;
  longlong lVar5;
  char cVar6;
  byte bVar7;
  
  if (param_3 == 0) {
    if (param_5 < 0xc50) {
      StorPortDebugPrint(0,"Data buffer is too small.(%lx)\n",param_5);
      cVar6 = '\x12';
    }
    else {
      bVar7 = 0;
      *(undefined1 *)(param_6 + 0x15c) = *(undefined1 *)(param_1 + 0x767e);
      if (*(char *)(param_1 + 0x767e) != '\0') {
        do {
          uVar4 = (ulonglong)bVar7;
          lVar5 = uVar4 * 0xe28;
          if ((*(byte *)(lVar5 + 0xd58 + param_1) & 4) != 0) {
            bVar3 = *(byte *)(lVar5 + 0xe78 + param_1);
            if ((((bVar3 & 4) != 0) || ((bVar3 & 8) != 0)) &&
               ((*(char *)(uVar4 + 10 + param_6) != '\0' ||
                (*(char *)(uVar4 + 0x16 + param_6) != '\0')))) {
              pbVar1 = (byte *)(*(longlong *)(lVar5 + 0x58 + param_1) + 0x1b);
              *pbVar1 = *pbVar1 & 0xfb;
              pbVar1 = (byte *)(*(longlong *)(lVar5 + 0x58 + param_1) + 0x1b);
              *pbVar1 = *pbVar1 & 0xf7;
            }
            if ((((*(byte *)(lVar5 + 0xd58 + param_1) & 4) != 0) &&
                ((bVar3 = *(byte *)(lVar5 + 0xe78 + param_1), (bVar3 & 0x10) != 0 ||
                 ((bVar3 & 0x20) != 0)))) &&
               ((*(char *)(uVar4 + 6 + param_6) != '\0' ||
                (*(char *)(uVar4 + 0x12 + param_6) != '\0')))) {
              lVar2 = *(longlong *)(lVar5 + 0x58 + param_1);
              *(byte *)(lVar2 + 0x1b) = *(byte *)(lVar2 + 0x1b) & 0xf | 0x10;
            }
          }
          bVar7 = bVar7 + 1;
          pbVar1 = (byte *)(lVar5 + 0xe78 + param_1);
          *pbVar1 = *pbVar1 ^ (*(char *)(uVar4 + 6 + param_6) << 2 ^
                              *(byte *)(lVar5 + 0xe78 + param_1)) & 4;
          bVar3 = *(byte *)(lVar5 + 0xe78 + param_1);
          bVar3 = (*(char *)(uVar4 + 0x12 + param_6) << 3 ^ bVar3) & 8 ^ bVar3;
          *(byte *)(lVar5 + 0xe78 + param_1) = bVar3;
          bVar3 = (*(char *)(uVar4 + 10 + param_6) << 4 ^ bVar3) & 0x10 ^ bVar3;
          *(byte *)(lVar5 + 0xe78 + param_1) = bVar3;
          bVar3 = (*(char *)(uVar4 + 0x16 + param_6) << 5 ^ bVar3) & 0x20 ^ bVar3;
          *(byte *)(lVar5 + 0xe78 + param_1) = bVar3;
          *(undefined1 *)(lVar5 + 0xe76 + param_1) = *(undefined1 *)(uVar4 + 0x161 + param_6);
          *(undefined1 *)(lVar5 + 0xe77 + param_1) = *(undefined1 *)(uVar4 + 0x165 + param_6);
          pbVar1 = (byte *)(lVar5 + 0xd58 + param_1);
          *pbVar1 = *pbVar1 ^ (*(char *)(uVar4 + 0x26 + param_6) * '\x02' ^
                              *(byte *)(lVar5 + 0xd58 + param_1)) & 2;
          pbVar1 = (byte *)(lVar5 + 0xe78 + param_1);
          *pbVar1 = *pbVar1 ^ (*(char *)(uVar4 + 0x2a + param_6) << 6 ^ bVar3) & 0x40;
        } while (bVar7 < *(byte *)(param_1 + 0x767e));
      }
      cVar6 = '\x01';
    }
  }
  else {
    cVar6 = '\x06';
  }
  ScsiPortWmiPostProcess(param_2,cVar6,param_5);
  bVar7 = 0;
  if (*(char *)(param_1 + 0x767e) != '\0') {
    do {
      if (((*(byte *)((ulonglong)bVar7 * 0xe28 + 0xe78 + param_1) & 0x40) != 0) &&
         ((*(byte *)((ulonglong)bVar7 * 0xe28 + 0xd58 + param_1) & 0x20) != 0)) {
        *(undefined1 *)(param_1 + 0x7684) = 1;
      }
      bVar7 = bVar7 + 1;
    } while (bVar7 < *(byte *)(param_1 + 0x767e));
  }
  if ((*(char *)(param_1 + 0x7684) == '\x01') && (*(char *)(param_1 + 0x767a) != '\0')) {
    uVar4 = 0;
    if (*(char *)(param_1 + 0x767e) != '\0') {
      do {
        if (*(int *)(uVar4 * 0xe28 + 0xe60 + param_1) != 0) {
          return cVar6;
        }
        bVar7 = (char)uVar4 + 1;
        uVar4 = (ulonglong)bVar7;
      } while (bVar7 < *(byte *)(param_1 + 0x767e));
    }
    *(undefined1 *)(param_1 + 0x7684) = 0;
    StorPortNotification(6,param_1,AHCIPMHotplugEventDetect);
  }
  return cVar6;
}



===== AHCIWmiFunctionControl @ 0001efe4 =====

char AHCIWmiFunctionControl(longlong param_1,longlong param_2,int param_3,int param_4,char param_5)

{
  char cVar1;
  
  if (param_3 == 0) {
    cVar1 = '\x06';
    if (param_4 == 1) {
      cVar1 = '\x01';
    }
  }
  else if ((param_3 == 1) && (param_4 == 0)) {
    cVar1 = '\x01';
    if (param_5 == '\0') {
      *(undefined1 *)(param_1 + 0x7687) = 0;
    }
    else {
      *(undefined1 *)(param_1 + 0x7687) = 1;
    }
  }
  else {
    cVar1 = '\x06';
  }
  ScsiPortWmiPostProcess(param_2,cVar1,0);
  return cVar1;
}



===== AHCIWmiFireEvent @ 0001f048 =====

undefined1 AHCIWmiFireEvent(longlong param_1)

{
  if (*(char *)(param_1 + 0x7687) == '\x01') {
    *(undefined4 *)(param_1 + 0x7714) = 0;
    *(undefined4 *)(param_1 + 0x773c) = 0;
    *(undefined8 *)(param_1 + 0x7720) = *(undefined8 *)(param_1 + 0x7750);
    *(undefined8 *)(param_1 + 0x7728) = *(undefined8 *)(param_1 + 0x7758);
    *(undefined4 *)(param_1 + 0x7734) = 0x8a;
    *(undefined4 *)(param_1 + 0x7744) = 8;
    *(undefined4 *)(param_1 + 0x7740) = 0x40;
    *(undefined4 *)(param_1 + 0x7708) = 0x48;
    ScsiPortNotification(8,param_1,(undefined4 *)(param_1 + 0x7708),0xff);
  }
  return 1;
}



===== ScsiPortWmiPostProcess @ 0001f0b4 =====

void ScsiPortWmiPostProcess(longlong param_1,char param_2,uint param_3)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  ulonglong uVar6;
  uint *puVar7;
  ulonglong uVar8;
  uint *puVar9;
  uint uVar10;
  
  cVar1 = *(char *)(param_1 + 0x18);
  puVar4 = *(uint **)(param_1 + 0x10);
  if (cVar1 == '\0') {
    uVar10 = puVar4[0xc];
    uVar2 = puVar4[0xd];
    uVar8 = (ulonglong)uVar2;
    uVar3 = uVar10 + param_3;
    if (param_2 == '\x01') {
      if (uVar3 <= *(uint *)(param_1 + 8)) {
        *puVar4 = uVar3;
        if ((puVar4[0xb] & 0x80) != 0) {
          puVar9 = puVar4 + 0xf;
          if (uVar2 != 0) {
            puVar7 = puVar4 + (longlong)(int)uVar2 + 0xe;
            puVar4 = puVar4 + (longlong)(int)uVar2 * 2 + 0xe;
            uVar6 = uVar8;
            do {
              uVar5 = *puVar7;
              puVar7 = puVar7 + -1;
              *puVar4 = uVar5;
              puVar4 = puVar4 + -2;
              uVar5 = (int)uVar6 - 1;
              uVar6 = (ulonglong)uVar5;
            } while (uVar5 != 0);
            if (uVar2 != 0) {
              do {
                puVar4 = puVar9 + 1;
                *puVar9 = uVar10;
                puVar9 = puVar9 + 2;
                uVar10 = *puVar4 + 7 + uVar10 & 0xfffffff8;
                uVar8 = uVar8 - 1;
              } while (uVar8 != 0);
            }
          }
        }
        goto LAB_0001f1a4;
      }
      param_2 = '\x12';
    }
LAB_0001f12a:
    if (param_2 == '\x12') {
      puVar4[0xc] = uVar3;
      puVar4[0xb] = 0x20;
      *puVar4 = 0x38;
      uVar3 = 0x38;
      param_2 = '\x01';
      goto LAB_0001f1a4;
    }
  }
  else {
    if (cVar1 == '\x01') {
      uVar3 = param_3 + puVar4[0xe];
      if (param_2 == '\x01') {
        *puVar4 = uVar3;
        goto LAB_0001f1a4;
      }
      goto LAB_0001f12a;
    }
    if (cVar1 == '\t') {
      uVar3 = param_3 + puVar4[0xf];
      if (param_2 == '\x01') {
        *puVar4 = uVar3;
        puVar4[0x10] = param_3;
        goto LAB_0001f1a4;
      }
      goto LAB_0001f12a;
    }
  }
  uVar3 = 0;
LAB_0001f1a4:
  *(uint *)(param_1 + 0x1c) = uVar3;
  *(char *)(param_1 + 0x19) = param_2;
  return;
}



===== ScsiWmipProcessRequest @ 0001f1c0 =====

char ScsiWmipProcessRequest
               (uint *param_1,byte param_2,undefined8 param_3,undefined8 param_4,ulonglong *param_5,
               uint param_6,uint *param_7,uint *param_8,short *param_9)

{
  short sVar1;
  ulonglong uVar2;
  short *psVar3;
  char cVar4;
  code *pcVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  ulonglong *puVar9;
  undefined2 *puVar10;
  longlong lVar11;
  uint *puVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  undefined8 uVar16;
  longlong *plVar17;
  ulonglong uVar18;
  ushort uVar19;
  bool bVar20;
  uint local_res10;
  undefined4 uVar21;
  
  puVar12 = (uint *)0x0;
  psVar3 = param_9;
  psVar3[0] = 0;
  psVar3[1] = 0;
  if (param_2 != 8) {
    uVar18 = 0;
    if (*param_1 != 0) {
      plVar17 = *(longlong **)(param_1 + 2);
      do {
        uVar2 = *(ulonglong *)*plVar17;
        bVar20 = *param_5 < uVar2;
        if ((*param_5 == uVar2) &&
           (uVar2 = ((ulonglong *)*plVar17)[1], bVar20 = param_5[1] < uVar2, param_5[1] == uVar2)) {
          iVar6 = 0;
        }
        else {
          iVar6 = (1 - (uint)bVar20) - (uint)(bVar20 != 0);
        }
        if (iVar6 == 0) {
          uVar14 = *(uint *)(*(longlong **)(param_1 + 2) + uVar18 * 2 + 1);
          if (((((param_2 != 1) && (param_2 != 2)) && (param_2 != 3)) && (param_2 != 9)) ||
             ((local_res10 = param_7[0xd], (param_7[0xb] & 0x80) == 0 || (local_res10 < uVar14))))
          goto LAB_0001f29f;
          break;
        }
        uVar14 = (int)uVar18 + 1;
        uVar18 = (ulonglong)uVar14;
        plVar17 = plVar17 + 2;
      } while (uVar14 < *param_1);
    }
    *param_8 = 0;
LAB_0001f286:
    cVar4 = '\x04';
    goto LAB_0001f5be;
  }
  uVar18 = (ulonglong)local_res10;
  uVar14 = local_res10;
LAB_0001f29f:
  if (param_2 < 6) {
    if (param_2 != 5) {
      if (param_2 == 0) {
        if (0x47 < param_6) {
          param_7[0xb] = param_7[0xb] & 0xffffffef;
          param_7[0xd] = uVar14;
          uVar7 = uVar14 * 8 + 0x40;
          param_7[0xc] = uVar7;
          if (param_6 < uVar7) {
            lVar11 = 0;
            iVar6 = 0;
          }
          else {
            puVar12 = param_7 + 0xf;
            lVar11 = (ulonglong)uVar7 + (longlong)param_7;
            iVar6 = param_6 - uVar7;
          }
          local_res10 = 0;
          goto LAB_0001f3be;
        }
      }
      else {
        if (param_2 == 1) {
          puVar12 = param_7 + 0xf;
          lVar11 = (ulonglong)param_7[0xe] + (longlong)param_7;
          iVar6 = param_6 - param_7[0xe];
          uVar14 = 1;
LAB_0001f3be:
          cVar4 = (**(code **)(param_1 + 6))
                            (param_3,param_4,uVar18,local_res10,uVar14,puVar12,iVar6,lVar11);
          return cVar4;
        }
        if (param_2 == 2) {
          if (*(code **)(param_1 + 8) != (code *)0x0) {
            cVar4 = (**(code **)(param_1 + 8))
                              (param_3,param_4,uVar18,local_res10,param_7[0xf],
                               (ulonglong)param_7[0xe] + (longlong)param_7);
            return cVar4;
          }
        }
        else if (param_2 == 3) {
          if (*(code **)(param_1 + 10) != (code *)0x0) {
            cVar4 = (**(code **)(param_1 + 10))
                              (param_3,param_4,uVar18,local_res10,param_7[0xe],param_7[0x10],
                               (ulonglong)param_7[0xf] + (longlong)param_7);
            return cVar4;
          }
        }
        else if (param_2 == 4) {
          pcVar5 = *(code **)(param_1 + 0xe);
          if (pcVar5 != (code *)0x0) {
            uVar16 = 0;
            goto LAB_0001f5aa;
          }
          goto LAB_0001f5bb;
        }
      }
      goto LAB_0001f286;
    }
    pcVar5 = *(code **)(param_1 + 0xe);
    if (pcVar5 != (code *)0x0) {
      uVar21 = 0;
      uVar16 = 0;
      goto LAB_0001f5af;
    }
  }
  else if (param_2 == 6) {
    pcVar5 = *(code **)(param_1 + 0xe);
    if (pcVar5 != (code *)0x0) {
      uVar16 = 1;
LAB_0001f5aa:
      uVar21 = 1;
LAB_0001f5af:
      cVar4 = (*pcVar5)(param_3,param_4,uVar18,uVar16,uVar21);
      return cVar4;
    }
  }
  else {
    if (param_2 != 7) {
      if (param_2 != 8) {
        if ((param_2 == 9) && (*(code **)(param_1 + 0xc) != (code *)0x0)) {
          cVar4 = (**(code **)(param_1 + 0xc))
                            (param_3,param_4,uVar18,local_res10,param_7[0xe],param_7[0x10],
                             param_6 - param_7[0xf],(longlong)param_7 + (ulonglong)param_7[0xf]);
          return cVar4;
        }
        goto LAB_0001f286;
      }
      cVar4 = (**(code **)(param_1 + 4))(param_3,param_4,&param_9);
      if (cVar4 == '\x01') {
        uVar7 = *param_1;
        uVar18 = (ulonglong)uVar7;
        lVar11 = *(longlong *)(param_1 + 2);
        uVar15 = uVar7 * 0x20 + 0x18;
        uVar14 = uVar7 * 0x20 + 0x34;
        if (param_9 == (short *)0x0) {
          uVar19 = 0;
        }
        else {
          uVar19 = 0;
          sVar1 = *param_9;
          while (sVar1 != 0) {
            uVar19 = uVar19 + 1;
            sVar1 = param_9[uVar19];
          }
          uVar19 = uVar19 * 2;
        }
        uVar8 = uVar19 + uVar14;
        if ((uVar8 < uVar14) || (uVar13 = uVar8 + 2, uVar13 < uVar8)) {
          cVar4 = '\x04';
          goto LAB_0001f57a;
        }
        *param_7 = uVar13;
        if (param_6 < uVar13) {
          uVar13 = 4;
        }
        else {
          param_7[1] = 0;
          param_7[3] = uVar14;
          param_7[2] = 0;
          param_7[4] = uVar7;
          if (uVar7 != 0) {
            puVar12 = (uint *)(lVar11 + 0xc);
            puVar9 = (ulonglong *)(param_7 + 0xc);
            do {
              uVar2 = (*(ulonglong **)(puVar12 + -3))[1];
              puVar9[-3] = **(ulonglong **)(puVar12 + -3);
              puVar9[-2] = uVar2;
              if (puVar12[-1] == 0xffffffff) {
                *(uint *)(puVar9 + -1) = *puVar12;
                *puVar9 = 0;
                *(undefined4 *)((longlong)puVar9 + -4) = 0;
              }
              else {
                *(uint *)(puVar9 + -1) = *puVar12 | 8;
                *puVar9 = (ulonglong)uVar15;
                *(uint *)((longlong)puVar9 + -4) = puVar12[-1];
              }
              puVar9 = puVar9 + 4;
              puVar12 = puVar12 + 4;
              uVar18 = uVar18 - 1;
            } while (uVar18 != 0);
          }
          puVar10 = (undefined2 *)((ulonglong)uVar15 + (longlong)param_7);
          *puVar10 = 0x1a;
          memcpy(puVar10 + 1,L"ScsiMiniPort",0x1a);
          *(ushort *)((ulonglong)uVar14 + (longlong)param_7) = uVar19;
          memcpy((ushort *)((ulonglong)uVar14 + (longlong)param_7) + 1,param_9,(ulonglong)uVar19);
        }
      }
      else {
LAB_0001f57a:
        uVar13 = 0;
      }
      *param_8 = uVar13;
      goto LAB_0001f5be;
    }
    pcVar5 = *(code **)(param_1 + 0xe);
    if (pcVar5 != (code *)0x0) {
      uVar21 = 0;
      uVar16 = 1;
      goto LAB_0001f5af;
    }
  }
LAB_0001f5bb:
  cVar4 = '\x01';
LAB_0001f5be:
  psVar3[0] = 1;
  psVar3[1] = 0;
  return cVar4;
}



===== __security_check_cookie @ 0001f600 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== __report_gsfailure @ 0001f628 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
                    /* WARNING: Subroutine does not return */
  KeBugCheckEx(0xf7,_StackCookie,__security_cookie,__security_cookie_complement,0);
}



===== memcpy @ 0001f660 =====

void * __cdecl memcpy(void *_Dst,void *_Src,size_t _Size)

{
  undefined8 uVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  
  uVar5 = (longlong)_Src - (longlong)_Dst;
  if (_Src < _Dst) {
    puVar4 = (undefined8 *)((longlong)_Dst + _Size);
    puVar3 = puVar4;
    if (_Size < 8) goto LAB_0001f874;
    if (((ulonglong)puVar4 & 7) != 0) {
      if (((ulonglong)puVar4 & 1) != 0) {
        puVar4 = (undefined8 *)((longlong)puVar4 + -1);
        _Size = _Size - 1;
        *(undefined1 *)puVar4 = *(undefined1 *)(uVar5 + (longlong)puVar4);
      }
      if (((ulonglong)puVar4 & 2) != 0) {
        puVar4 = (undefined8 *)((longlong)puVar4 + -2);
        _Size = _Size - 2;
        *(undefined2 *)puVar4 = *(undefined2 *)(uVar5 + (longlong)puVar4);
      }
      if (((ulonglong)puVar4 & 4) != 0) {
        puVar4 = (undefined8 *)((longlong)puVar4 + -4);
        _Size = _Size - 4;
        *(undefined4 *)puVar4 = *(undefined4 *)(uVar5 + (longlong)puVar4);
      }
    }
    while (uVar6 = _Size >> 5, puVar3 = puVar4, uVar6 != 0) {
      if ((uVar6 < 0x2000) || (0xfffffffffffff000 < uVar5)) goto LAB_0001f8b0;
      do {
        iVar2 = 0x20;
        do {
          puVar3 = puVar4;
          iVar2 = iVar2 + -1;
          puVar4 = puVar3 + -0x10;
        } while (iVar2 != 0);
        iVar2 = 0x40;
        puVar3 = puVar3 + 0x1f0;
        do {
          uVar1 = *(undefined8 *)((uVar5 - 0x10) + (longlong)puVar3);
          puVar3[-1] = *(undefined8 *)((uVar5 - 8) + (longlong)puVar3);
          puVar3[-2] = uVar1;
          uVar1 = *(undefined8 *)((uVar5 - 0x20) + (longlong)puVar3);
          puVar3[-3] = *(undefined8 *)((uVar5 - 0x18) + (longlong)puVar3);
          puVar3[-4] = uVar1;
          uVar1 = *(undefined8 *)((uVar5 - 0x30) + (longlong)puVar3);
          puVar4 = puVar3 + -8;
          puVar3[-5] = *(undefined8 *)((uVar5 - 0x28) + (longlong)puVar3);
          puVar3[-6] = uVar1;
          uVar1 = *(undefined8 *)(uVar5 + (longlong)puVar4);
          iVar2 = iVar2 + -1;
          puVar3[-7] = *(undefined8 *)(uVar5 + 8 + (longlong)puVar4);
          *puVar4 = uVar1;
          puVar3 = puVar4;
        } while (iVar2 != 0);
        _Size = _Size - 0x1000;
      } while (0xfff < _Size);
      LOCK();
      UNLOCK();
    }
    goto LAB_0001f857;
  }
  puVar4 = _Dst;
  if (_Size < 8) goto LAB_0001f6d4;
  puVar3 = _Dst;
  if (((ulonglong)_Dst & 7) != 0) {
    if (((ulonglong)_Dst & 1) != 0) {
      _Size = _Size - 1;
      *(undefined1 *)_Dst = *(undefined1 *)(uVar5 + (longlong)_Dst);
      puVar3 = (undefined8 *)((longlong)_Dst + 1);
    }
    if (((ulonglong)puVar3 & 2) != 0) {
      _Size = _Size - 2;
      *(undefined2 *)puVar3 = *(undefined2 *)(uVar5 + (longlong)puVar3);
      puVar3 = (undefined8 *)((longlong)puVar3 + 2);
    }
    if (((ulonglong)puVar3 & 4) != 0) {
      _Size = _Size - 4;
      *(undefined4 *)puVar3 = *(undefined4 *)(uVar5 + (longlong)puVar3);
      puVar3 = (undefined8 *)((longlong)puVar3 + 4);
    }
  }
  while (uVar6 = _Size >> 5, puVar4 = puVar3, uVar6 != 0) {
    if ((uVar6 < 0x2000) || (uVar5 < 0x1000)) goto LAB_0001f710;
    do {
      iVar2 = 0x20;
      do {
        puVar4 = puVar3;
        iVar2 = iVar2 + -1;
        puVar3 = puVar4 + 0x10;
      } while (iVar2 != 0);
      iVar2 = 0x40;
      puVar4 = puVar4 + -0x1f0;
      do {
        uVar1 = *(undefined8 *)(uVar5 + 8 + (longlong)puVar4);
        *puVar4 = *(undefined8 *)(uVar5 + (longlong)puVar4);
        puVar4[1] = uVar1;
        uVar1 = *(undefined8 *)(uVar5 + 0x18 + (longlong)puVar4);
        puVar4[2] = *(undefined8 *)(uVar5 + 0x10 + (longlong)puVar4);
        puVar4[3] = uVar1;
        uVar1 = *(undefined8 *)(uVar5 + 0x28 + (longlong)puVar4);
        puVar3 = puVar4 + 8;
        puVar4[4] = *(undefined8 *)(uVar5 + 0x20 + (longlong)puVar4);
        puVar4[5] = uVar1;
        uVar1 = *(undefined8 *)((uVar5 - 8) + (longlong)puVar3);
        iVar2 = iVar2 + -1;
        puVar4[6] = *(undefined8 *)((uVar5 - 0x10) + (longlong)puVar3);
        puVar4[7] = uVar1;
        puVar4 = puVar3;
      } while (iVar2 != 0);
      _Size = _Size - 0x1000;
    } while (0xfff < _Size);
    LOCK();
    UNLOCK();
  }
  goto LAB_0001f6b7;
LAB_0001f8b0:
  do {
    uVar1 = *(undefined8 *)((uVar5 - 0x10) + (longlong)puVar4);
    puVar3 = puVar4 + -4;
    puVar4[-1] = *(undefined8 *)((uVar5 - 8) + (longlong)puVar4);
    puVar4[-2] = uVar1;
    uVar1 = *(undefined8 *)(uVar5 + (longlong)puVar3);
    uVar6 = uVar6 - 1;
    puVar4[-3] = *(undefined8 *)(uVar5 + 8 + (longlong)puVar3);
    *puVar3 = uVar1;
    puVar4 = puVar3;
  } while (uVar6 != 0);
  _Size = _Size & 0x1f;
LAB_0001f857:
  uVar6 = _Size >> 3;
  if (uVar6 != 0) {
    do {
      puVar3 = puVar3 + -1;
      uVar6 = uVar6 - 1;
      *puVar3 = *(undefined8 *)(uVar5 + (longlong)puVar3);
    } while (uVar6 != 0);
    _Size = _Size & 7;
  }
LAB_0001f874:
  if (_Size == 0) {
    return _Dst;
  }
  do {
    puVar3 = (undefined8 *)((longlong)puVar3 + -1);
    _Size = _Size - 1;
    *(undefined1 *)puVar3 = *(undefined1 *)(uVar5 + (longlong)puVar3);
  } while (_Size != 0);
  return _Dst;
LAB_0001f710:
  do {
    uVar1 = *(undefined8 *)(uVar5 + 8 + (longlong)puVar3);
    puVar4 = puVar3 + 4;
    *puVar3 = *(undefined8 *)(uVar5 + (longlong)puVar3);
    puVar3[1] = uVar1;
    uVar1 = *(undefined8 *)((uVar5 - 8) + (longlong)puVar4);
    uVar6 = uVar6 - 1;
    puVar3[2] = *(undefined8 *)((uVar5 - 0x10) + (longlong)puVar4);
    puVar3[3] = uVar1;
    puVar3 = puVar4;
  } while (uVar6 != 0);
  _Size = _Size & 0x1f;
LAB_0001f6b7:
  uVar6 = _Size >> 3;
  if (uVar6 != 0) {
    do {
      *puVar4 = *(undefined8 *)(uVar5 + (longlong)puVar4);
      puVar4 = puVar4 + 1;
      uVar6 = uVar6 - 1;
    } while (uVar6 != 0);
    _Size = _Size & 7;
  }
LAB_0001f6d4:
  if (_Size == 0) {
    return _Dst;
  }
  do {
    *(undefined1 *)puVar4 = *(undefined1 *)(uVar5 + (longlong)puVar4);
    puVar4 = (undefined8 *)((longlong)puVar4 + 1);
    _Size = _Size - 1;
  } while (_Size != 0);
  return _Dst;
}



===== StorPortDebugPrint @ 0001f99a =====

void StorPortDebugPrint(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001f99a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortDebugPrint();
  return;
}



===== StorPortNotification @ 0001f9a6 =====

void StorPortNotification(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001f9a6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortNotification();
  return;
}



===== StorPortGetBusData @ 0001f9b2 =====

void StorPortGetBusData(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001f9b2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortGetBusData();
  return;
}



===== StorPortGetScatterGatherList @ 0001f9be =====

void StorPortGetScatterGatherList(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001f9be. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortGetScatterGatherList();
  return;
}



===== StorPortDeviceReady @ 0001f9ca =====

void StorPortDeviceReady(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001f9ca. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortDeviceReady();
  return;
}



===== StorPortGetDeviceBase @ 0001f9d6 =====

void StorPortGetDeviceBase(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001f9d6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortGetDeviceBase();
  return;
}



===== StorPortLogError @ 0001f9e2 =====

void StorPortLogError(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001f9e2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortLogError();
  return;
}



===== StorPortSetBusDataByOffset @ 0001f9ee =====

void StorPortSetBusDataByOffset(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001f9ee. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortSetBusDataByOffset();
  return;
}



===== StorPortStallExecution @ 0001f9fa =====

void StorPortStallExecution(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001f9fa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortStallExecution();
  return;
}



===== StorPortGetPhysicalAddress @ 0001fa06 =====

void StorPortGetPhysicalAddress(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001fa06. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortGetPhysicalAddress();
  return;
}



===== StorPortInitialize @ 0001fa12 =====

void StorPortInitialize(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001fa12. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortInitialize();
  return;
}



===== StorPortCompleteRequest @ 0001fa1e =====

void StorPortCompleteRequest(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001fa1e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortCompleteRequest();
  return;
}



===== StorPortReady @ 0001fa2a =====

void StorPortReady(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001fa2a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortReady();
  return;
}



===== StorPortGetUncachedExtension @ 0001fa36 =====

void StorPortGetUncachedExtension(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001fa36. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortGetUncachedExtension();
  return;
}



===== StorPortDeviceBusy @ 0001fa42 =====

void StorPortDeviceBusy(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001fa42. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortDeviceBusy();
  return;
}



===== memset @ 0001fa60 =====

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



===== __GSHandlerCheckCommon @ 0001fb50 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

longlong __GSHandlerCheckCommon(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar1 = *(longlong *)(param_2 + 0x10);
  lVar2 = (ulonglong)*(uint *)(lVar1 + 8) + *(longlong *)(param_2 + 8);
  if ((*(byte *)(lVar2 + 3) & 0xf) != 0) {
    lVar1 = (longlong)(int)(*(byte *)(lVar2 + 3) & 0xfffffff0);
  }
  return lVar1;
}



===== __GSHandlerCheck @ 0001fbbc =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== entry @ 00025008 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void entry(undefined8 param_1,undefined8 param_2)

{
  if (((__security_cookie == 0) || (__security_cookie == 0x2b992ddfa232)) &&
     (__security_cookie = (_DAT_fffff78000000320 ^ 0x23100) & 0xffffffffffff, __security_cookie == 0
     )) {
    __security_cookie = 0x2b992ddfa232;
  }
  __security_cookie_complement = ~__security_cookie;
  DriverEntry(param_1,param_2);
  return;
}


