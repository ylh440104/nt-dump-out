
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



===== AllocatePool @ 140001020 =====

longlong * AllocatePool(longlong param_1,int param_2,char param_3)

{
  uint uVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong *plVar4;
  uint uVar5;
  ulonglong uVar6;
  
  uVar5 = param_2 + 0x27U & 0xfffffff0;
  uVar1 = uVar5 + 0x10;
  if (param_3 == '\0') {
    uVar1 = uVar5;
  }
  uVar6 = (ulonglong)uVar1;
  plVar3 = *(longlong **)(param_1 + 0x10);
  plVar4 = (longlong *)0x0;
  while( true ) {
    plVar2 = plVar3;
    if (plVar2 == (longlong *)0x0) {
      return (longlong *)0x0;
    }
    uVar5 = *(uint *)(plVar2 + 2);
    if (uVar1 <= uVar5) break;
    plVar3 = (longlong *)*plVar2;
    plVar4 = plVar2;
  }
  if (plVar4 == (longlong *)0x0) {
    if ((ulonglong)uVar5 < uVar6 + 0x18) {
      *(longlong *)(param_1 + 0x10) = **(longlong **)(param_1 + 0x10);
      goto LAB_1400010bc;
    }
    plVar4 = (longlong *)(uVar6 + (longlong)plVar2);
    *(longlong **)(param_1 + 0x10) = plVar4;
    *(uint *)(plVar4 + 2) = (int)plVar2[2] - uVar1;
  }
  else {
    if ((ulonglong)uVar5 < uVar6 + 0x18) {
      *plVar4 = *plVar2;
      goto LAB_1400010bc;
    }
    *plVar4 = uVar6 + (longlong)plVar2;
    *(uint *)(uVar6 + (longlong)plVar2 + 0x10) = (int)plVar2[2] - uVar1;
    plVar4 = (longlong *)*plVar4;
  }
  *plVar4 = *plVar2;
  *(uint *)(plVar2 + 2) = uVar1;
LAB_1400010bc:
  *plVar2 = 0;
  if (param_3 == '\0') {
    return plVar2 + 3;
  }
  return (longlong *)((longlong)plVar2 + 0x27U & 0xfffffffffffffff0);
}



===== AllocateScatterGatherList @ 1400010e4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void AllocateScatterGatherList(longlong *param_1,longlong param_2)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  uint uVar4;
  uint uVar5;
  longlong lVar6;
  uint uVar7;
  ulonglong uVar8;
  longlong *plVar9;
  
  lVar2 = *param_1;
  if (*(char *)(param_2 + 2) == '(') {
    lVar6 = *(longlong *)(param_2 + 0x40);
    uVar5 = *(uint *)(param_2 + 0x3c);
    uVar4 = *(uint *)(param_2 + 0x18);
  }
  else {
    lVar6 = *(longlong *)(param_2 + 0x18);
    uVar5 = *(uint *)(param_2 + 0x10);
    uVar4 = *(uint *)(param_2 + 0xc);
  }
  uVar8 = 0;
  plVar9 = param_1 + 0xf;
  if (param_1[8] == 0) {
    *(undefined4 *)(param_1 + 0xd) = 1;
    *(uint *)(param_1 + 0x10) = uVar5;
    *plVar9 = param_1[9];
  }
  else {
    *(undefined4 *)(param_1 + 0xd) = 0;
    *(int *)(param_1 + 0x4d) =
         (int)((ulonglong)((uint)lVar6 & 0xfff) + 0xfff + (ulonglong)uVar5 >> 0xc);
    if (uVar5 != 0) {
      do {
        plVar1 = plVar9 + 1;
        *(uint *)plVar1 = uVar5 - (int)uVar8;
        lVar3 = (**(code **)(*(longlong *)(*(longlong *)(lVar2 + 0x40) + 8) + 0x40))
                          (*(longlong *)(lVar2 + 0x40),param_1[8],param_1[0x4c],uVar8 + lVar6,plVar1
                           ,(byte)(uVar4 >> 7) & 1);
        uVar7 = (int)uVar8 + (int)*plVar1;
        uVar8 = (ulonglong)uVar7;
        *plVar9 = lVar3;
        plVar9 = plVar9 + 3;
        *(int *)(param_1 + 0xd) = (int)param_1[0xd] + 1;
      } while (uVar7 < uVar5);
    }
  }
  return;
}



===== ControlCleanup @ 1400011e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ControlCleanup(longlong param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  ulonglong uVar7;
  int iVar8;
  
  lVar3 = *(longlong *)(param_1 + 0x38);
  iVar8 = 0;
  lVar4 = *(longlong *)(lVar3 + 0x30);
  if ((*param_2 == 3) && ((*(byte *)(lVar4 + 0x132) & 2) != 0)) {
    lVar5 = *(longlong *)(lVar4 + 0x138);
    lVar6 = *(longlong *)(lVar5 + 0x28);
    *(uint *)(lVar5 + 0x250) = *(uint *)(lVar5 + 0x250) & 0xfffffff9;
    *(undefined8 *)(lVar5 + 0x260) = 0;
    *(undefined1 *)(lVar5 + 0x2b2) = 1;
    *(undefined1 *)(lVar6 + 3) = 0;
    if (*(char *)(lVar6 + 2) == '(') {
      *(undefined4 *)(lVar6 + 0x14) = 7;
      *(undefined4 *)(lVar6 + 0x78) = 0;
      *(undefined4 *)(lVar6 + 0x18) = 0x2c;
      *(undefined8 *)(lVar6 + 0x70) = 0;
      *(undefined4 *)(lVar6 + 0x28) = 10;
      *(undefined4 *)(lVar6 + 0x10) = 0x90;
      *(undefined4 *)(lVar6 + 0x38) = 0;
    }
    else {
      *(undefined1 *)(lVar6 + 10) = 0;
      *(undefined1 *)(lVar6 + 2) = 7;
      *(undefined4 *)(lVar6 + 0xc) = 0x2c;
      *(undefined1 *)(lVar6 + 4) = 0;
      *(undefined8 *)(lVar6 + 0x28) = 0;
      *(undefined4 *)(lVar6 + 0x14) = 10;
    }
    ExecuteSrb(param_1,lVar6);
  }
  *(ushort *)(lVar4 + 0x132) = *(ushort *)(lVar4 + 0x132) & 0xfffc;
  if (*param_2 - 2U < 2) {
    FreeAdapterResources(*(longlong *)(param_1 + 0x38));
  }
  uVar7 = Feature_SteelixInlineNvmeCryptoEngine__private_IsEnabledNoReportingNoInline();
  if ((int)uVar7 == 0) {
    return;
  }
  iVar1 = *param_2;
  lVar3 = *(longlong *)(*(longlong *)(lVar3 + 0x38) + 0x70);
  if (iVar1 == 1) {
    return;
  }
  if (((iVar1 == 2) && (*(int *)(lVar3 + 4) == 1)) && (*(int *)(lVar3 + 8) == 0)) {
    return;
  }
  lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x60);
  if (lVar4 == 0) {
    return;
  }
  if (*(code **)(lVar4 + 0x70) == (code *)0x0) {
    return;
  }
  iVar2 = *(int *)(lVar3 + 8);
  if (*(int *)(lVar3 + 4) != 1) {
    if ((*(int *)(lVar3 + 4) == 2) && (iVar2 == 0)) {
      iVar8 = 3 - (uint)(iVar1 != 2);
      goto LAB_140001332;
    }
    if (iVar2 != 1) {
      if (iVar2 == 2) {
        iVar8 = 2;
      }
      else if (iVar2 == 3) {
        iVar8 = 3;
      }
      goto LAB_140001332;
    }
  }
  iVar8 = 1;
LAB_140001332:
  (**(code **)(lVar4 + 0x70))(*(undefined8 *)(lVar4 + 8),iVar8);
  return;
}



===== ControlEarlyInitCleanup @ 140001364 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 ControlEarlyInitCleanup(longlong param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  longlong *plVar7;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  puVar6 = *(undefined8 **)(param_2 + 0x28);
  do {
    if (puVar6 == (undefined8 *)(param_2 + 0x28)) {
      return 0;
    }
    if (puVar6[6] == lVar2) {
      lVar3 = puVar6[5];
      if (*(longlong *)(lVar3 + 0x38) != 0) {
        ExFreePoolWithTag(*(longlong *)(lVar3 + 0x38),0x44436152);
        *(undefined8 *)(lVar3 + 0x38) = 0;
      }
      if (*(longlong *)(lVar3 + 0x80) != 0) {
        ExFreePoolWithTag(*(longlong *)(lVar3 + 0x80),0x44436152);
        *(undefined8 *)(lVar3 + 0x80) = 0;
      }
      if (*(longlong *)(lVar3 + 0x88) != 0) {
        ExFreePoolWithTag(*(longlong *)(lVar3 + 0x88),0x44436152);
        *(undefined8 *)(lVar3 + 0x88) = 0;
      }
      plVar7 = *(longlong **)(lVar3 + 0x128);
      if (plVar7 != (longlong *)0x0) {
        while (plVar7 = (longlong *)*plVar7, plVar7 != (longlong *)0x0) {
          if (plVar7[1] != 0) {
            MmUnmapIoSpace(plVar7[1],*(undefined4 *)(plVar7 + 2));
          }
        }
        ExFreePoolWithTag(*(undefined8 *)(lVar3 + 0x128),0x44436152);
        *(undefined8 *)(lVar3 + 0x128) = 0;
      }
      uVar4 = Feature_SteelixInlineNvmeCryptoEngine__private_IsEnabledNoReportingNoInline();
      if ((((int)uVar4 != 0) &&
          (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x60), lVar3 != 0)) &&
         (*(code **)(lVar3 + 0x60) != (code *)0x0)) {
        iVar1 = *(int *)(param_2 + 8);
        if (*(int *)(param_2 + 4) == 1) {
LAB_1400014af:
          uVar5 = 1;
        }
        else if ((*(int *)(param_2 + 4) == 2) && (iVar1 == 0)) {
LAB_14000148e:
          uVar5 = 2;
        }
        else {
          if (iVar1 == 1) goto LAB_1400014af;
          if (iVar1 == 2) goto LAB_14000148e;
          if (iVar1 == 3) {
            uVar5 = 3;
          }
          else {
            uVar5 = 0;
          }
        }
        (**(code **)(lVar3 + 0x60))(*(undefined8 *)(lVar3 + 8),uVar5);
      }
    }
    puVar6 = (undefined8 *)*puVar6;
  } while( true );
}



===== ControlGetDeviceInternalLog @ 1400014f4 =====

ulonglong ControlGetDeviceInternalLog(longlong param_1,undefined8 *param_2)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  uint uVar3;
  uint uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  char *pcVar7;
  uint uVar8;
  undefined2 local_res8;
  undefined2 local_res18;
  undefined2 local_res20;
  undefined8 in_stack_ffffffffffffffb8;
  uint local_38;
  undefined4 local_34;
  
  local_34 = 0;
  if ((((param_1 == 0) || (param_2 == (undefined8 *)0x0)) ||
      (puVar2 = (undefined8 *)*param_2, puVar2 == (undefined8 *)0x0)) ||
     (*(int *)(param_2 + 1) == 0)) {
    uVar5 = 0xc000000d;
  }
  else {
    *puVar2 = 0xb0;
    uVar4 = *(uint *)(param_2 + 1);
    if (uVar4 < 0x2a8) {
      uVar5 = 0xc0000023;
    }
    else {
      *(undefined4 *)(param_2 + 1) = 0;
      uVar4 = uVar4 - 0xa8;
      puVar1 = puVar2 + 0x15;
      local_38 = uVar4;
      uVar6 = IssueReadBuffer(param_1,puVar1,&local_38,0,in_stack_ffffffffffffffb8,'\x01');
      uVar5 = uVar6 & 0xffffffff;
      if (-1 < (int)uVar6) {
        if (local_38 < 0x28) {
          return 0xc0000001;
        }
        *(undefined1 *)(puVar2 + 4) = *(undefined1 *)(puVar2 + 0x16);
        *(undefined1 *)((longlong)puVar2 + 0xf) = *(undefined1 *)puVar1;
        *(undefined1 *)((longlong)puVar2 + 0xe) = *(undefined1 *)((longlong)puVar2 + 0xa9);
        *(undefined1 *)((longlong)puVar2 + 0xd) = *(undefined1 *)((longlong)puVar2 + 0xaa);
        *(undefined1 *)((longlong)puVar2 + 0xc) = *(undefined1 *)((longlong)puVar2 + 0xab);
        *(undefined1 *)((longlong)puVar2 + 0xb) = *(undefined1 *)((longlong)puVar2 + 0xac);
        *(undefined1 *)((longlong)puVar2 + 10) = *(undefined1 *)((longlong)puVar2 + 0xad);
        *(undefined1 *)((longlong)puVar2 + 9) = *(undefined1 *)((longlong)puVar2 + 0xae);
        *(undefined1 *)(puVar2 + 1) = *(undefined1 *)((longlong)puVar2 + 0xaf);
        uVar8 = (uint)(ushort)(CONCAT11(*(undefined1 *)((longlong)puVar2 + 0xc6),
                                        *(undefined1 *)((longlong)puVar2 + 199)) >> 3);
        uVar5 = 0;
        if (uVar8 != 0) {
          pcVar7 = (char *)((longlong)puVar2 + 0xc9);
          do {
            if (*pcVar7 == '\x01') {
              local_38 = uVar4;
              uVar6 = IssueReadBuffer(param_1,puVar1,&local_38,
                                      *(undefined1 *)(puVar2 + uVar5 + 0x19),
                                      in_stack_ffffffffffffffb8,'\0');
              uVar5 = uVar6 & 0xffffffff;
              if (-1 < (int)uVar6) {
                if (local_38 < 0x200) {
                  return 0xc0000001;
                }
                local_res8 = CONCAT11(*(undefined1 *)(puVar2 + 0x16),
                                      *(undefined1 *)((longlong)puVar2 + 0xb1));
                local_res18 = CONCAT11(*(undefined1 *)((longlong)puVar2 + 0xb2),
                                       *(undefined1 *)((longlong)puVar2 + 0xb3));
                local_res20 = CONCAT11(*(undefined1 *)((longlong)puVar2 + 0xb4),
                                       *(undefined1 *)((longlong)puVar2 + 0xb5));
                *(uint *)(puVar2 + 2) = (uint)local_res8;
                local_34 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)((longlong)puVar2 + 0xb6),
                                                      *(undefined1 *)((longlong)puVar2 + 0xb7)),
                                             *(undefined1 *)(puVar2 + 0x17)),
                                    *(undefined1 *)((longlong)puVar2 + 0xb9));
                *(uint *)((longlong)puVar2 + 0x14) = (uint)local_res18;
                *(uint *)(puVar2 + 3) = (uint)local_res20;
                *(undefined4 *)((longlong)puVar2 + 0x1c) = local_34;
                uVar4 = (local_res8 + 1) * 0x200;
                *(undefined8 *)((longlong)puVar2 + 0x24) = puVar2[0x45];
                *(undefined8 *)((longlong)puVar2 + 0x2c) = puVar2[0x46];
                *(undefined8 *)((longlong)puVar2 + 0x34) = puVar2[0x47];
                *(undefined8 *)((longlong)puVar2 + 0x3c) = puVar2[0x48];
                *(undefined8 *)((longlong)puVar2 + 0x44) = puVar2[0x49];
                *(undefined8 *)((longlong)puVar2 + 0x4c) = puVar2[0x4a];
                *(undefined8 *)((longlong)puVar2 + 0x54) = puVar2[0x4b];
                *(undefined8 *)((longlong)puVar2 + 0x5c) = puVar2[0x4c];
                *(undefined8 *)((longlong)puVar2 + 100) = puVar2[0x4d];
                *(undefined8 *)((longlong)puVar2 + 0x6c) = puVar2[0x4e];
                *(undefined8 *)((longlong)puVar2 + 0x74) = puVar2[0x4f];
                *(undefined8 *)((longlong)puVar2 + 0x7c) = puVar2[0x50];
                *(undefined8 *)((longlong)puVar2 + 0x84) = puVar2[0x51];
                *(undefined8 *)((longlong)puVar2 + 0x8c) = puVar2[0x52];
                *(undefined8 *)((longlong)puVar2 + 0x94) = puVar2[0x53];
                *(undefined8 *)((longlong)puVar2 + 0x9c) = puVar2[0x54];
                if (local_38 < uVar4) {
                  *(uint *)((longlong)puVar2 + 0xa4) = local_38;
                }
                else {
                  *(uint *)((longlong)puVar2 + 0xa4) = uVar4;
                  local_38 = uVar4;
                }
                *(uint *)((longlong)puVar2 + 4) = local_38 + 0xa8;
                *(uint *)(param_2 + 1) = local_38 + 0xa8;
              }
              goto LAB_14000177f;
            }
            uVar3 = (int)uVar5 + 1;
            uVar5 = (ulonglong)uVar3;
            pcVar7 = pcVar7 + 8;
          } while (uVar3 < uVar8);
        }
        uVar5 = 0xc00000bb;
      }
    }
  }
LAB_14000177f:
  return uVar5;
}



===== ControlPowerOn @ 140001798 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int ControlPowerOn(longlong param_1,char *param_2)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  
  iVar5 = 0;
  iVar6 = 0;
  lVar1 = *(longlong *)(param_1 + 0x30);
  lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 0x30);
  pcVar3 = *(char **)(lVar2 + 0x18);
  if (pcVar3 == (char *)0x0) {
    cVar4 = '\x01';
  }
  else {
    cVar4 = *pcVar3;
  }
  if (*(char **)(lVar1 + 0x18) != (char *)0x0) {
    if ((cVar4 == '\0') || (**(char **)(lVar1 + 0x18) == '\0')) {
      cVar4 = '\0';
    }
    else {
      cVar4 = '\x01';
    }
  }
  if ((*param_2 != '\0') && (cVar4 == '\0')) {
    if ((pcVar3 != (char *)0x0) &&
       (((*pcVar3 == '\0' && (*(code **)(lVar2 + 0x20) != (code *)0x0)) &&
        (iVar5 = (**(code **)(lVar2 + 0x20))(*(undefined8 *)(lVar2 + 0x28)), iVar5 < 0)))) {
      return iVar5;
    }
    iVar6 = iVar5;
    if (((*(char **)(lVar1 + 0x18) != (char *)0x0) && (**(char **)(lVar1 + 0x18) == '\0')) &&
       (*(code **)(lVar1 + 0x20) != (code *)0x0)) {
      iVar6 = (**(code **)(lVar1 + 0x20))(*(undefined8 *)(lVar1 + 0x28));
    }
    if (iVar6 < 0) {
      return iVar6;
    }
    if (*(char **)(lVar2 + 0x18) == (char *)0x0) {
      cVar4 = '\x01';
    }
    else {
      cVar4 = **(char **)(lVar2 + 0x18);
    }
    if (*(char **)(lVar1 + 0x18) != (char *)0x0) {
      if ((cVar4 == '\0') || (**(char **)(lVar1 + 0x18) == '\0')) {
        cVar4 = '\0';
      }
      else {
        cVar4 = '\x01';
      }
    }
  }
  param_2[1] = cVar4;
  return iVar6;
}



===== ControlPrepare @ 140001878 =====

undefined8 ControlPrepare(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  
  lVar1 = *(longlong *)(param_1 + 0x38);
  lVar2 = *(longlong *)(param_1 + 0x30);
  lVar3 = *(longlong *)(lVar1 + 0x30);
  KeQueryPerformanceCounter(&g_Frequency);
  if ((*(byte *)(lVar3 + 0x132) & 1) == 0) {
    uVar4 = PrepareAdapter(lVar1,lVar2);
    if ((int)uVar4 < 0) {
      return uVar4;
    }
    MarkHiberBootPhaseForAdapter(lVar3);
  }
  if (*(longlong *)(lVar2 + 0x18) != 0) {
    PoSetHiberRange(0,0x10000,*(longlong *)(lVar2 + 0x18),1,0x74707344);
  }
  uVar5 = Feature_SteelixInlineNvmeCryptoEngine__private_IsEnabledNoReportingNoInline();
  if (((int)uVar5 != 0) && (*(longlong *)(lVar2 + 0x60) != 0)) {
    PoSetHiberRange(0,0x10000,*(longlong *)(lVar2 + 0x60),0xa8,0x74707344);
  }
  return 0;
}



===== ControlPrepareEarlyDumpData @ 140001938 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 ControlPrepareEarlyDumpData(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined4 *puVar2;
  longlong lVar3;
  longlong lVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined8 uVar9;
  int iVar10;
  uint uVar11;
  longlong *plVar12;
  undefined8 *puVar13;
  undefined8 *puVar14;
  undefined8 uVar15;
  uint uVar16;
  undefined8 *puVar17;
  undefined4 *puVar18;
  undefined8 *puVar19;
  uint uVar20;
  undefined4 local_58;
  int iStack_54;
  int iStack_50;
  undefined4 uStack_4c;
  undefined8 uStack_48;
  longlong lStack_40;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  uVar16 = 0xc;
  puVar19 = (undefined8 *)(*(longlong *)(lVar1 + 0x70) + 0x28);
  uVar15 = 0;
  for (puVar17 = (undefined8 *)*puVar19; puVar17 != puVar19; puVar17 = (undefined8 *)*puVar17) {
    if (puVar17[6] == lVar1) {
      lVar3 = *(longlong *)(puVar17[6] + 0x48);
      lVar4 = puVar17[5];
      if ((*(uint *)(lVar3 + 0xb8) & 0x10000) == 0) {
        return 0xc00000bb;
      }
      uStack_48._4_4_ = 0;
      lStack_40 = lVar4 + 0x48;
      local_58 = 0x20;
      iStack_54 = 0;
      iStack_50 = 0;
      uStack_4c = 0;
      uStack_48._0_4_ = 0;
      iVar10 = (**(code **)(lVar3 + 0x78))(0,0x18,&local_58);
      if (iVar10 != 3) {
        return 0xc0000001;
      }
      uVar16 = uVar16 + *(int *)(lVar4 + 0x7c) * 0x10 + 0x34 + iStack_54;
      plVar12 = *(longlong **)(lVar4 + 0x128);
      if (plVar12 != (longlong *)0x0) {
        while (plVar12 = (longlong *)*plVar12, plVar12 != (longlong *)0x0) {
          uVar16 = uVar16 + 0x28;
        }
      }
    }
  }
  *(uint *)(param_2 + 0x14) = uVar16;
  if (*(uint *)(param_2 + 0x10) < uVar16) {
    uVar15 = 0xc0000023;
  }
  else {
    puVar2 = *(undefined4 **)(param_2 + 8);
    uVar16 = uVar16 - 0xc;
    *puVar2 = 0xc;
    puVar18 = puVar2 + 3;
    puVar2[2] = 0xc;
    for (puVar17 = (undefined8 *)*puVar19; puVar17 != puVar19; puVar17 = (undefined8 *)*puVar17) {
      if (puVar17[6] == lVar1) {
        lVar3 = puVar17[5];
        lVar4 = *(longlong *)(puVar17[6] + 0x48);
        if (uVar16 < 0x34) {
          return 0x80000005;
        }
        *puVar18 = 0x34;
        lStack_40 = lVar3 + 0x48;
        uVar5 = *(undefined4 *)(puVar17 + 2);
        uVar6 = *(undefined4 *)((longlong)puVar17 + 0x14);
        uVar7 = *(undefined4 *)(puVar17 + 3);
        uVar8 = *(undefined4 *)((longlong)puVar17 + 0x1c);
        puVar18[0xb] = 0x34;
        puVar18[3] = uVar5;
        puVar18[4] = uVar6;
        puVar18[5] = uVar7;
        puVar18[6] = uVar8;
        uStack_4c = 0;
        local_58 = 0x20;
        iStack_54 = 0;
        uStack_48 = (ulonglong)(uint)puVar18[0xb] + (longlong)puVar18;
        iStack_50 = uVar16 - 0x34;
        iVar10 = (**(code **)(lVar4 + 0x78))(0,0x18,&local_58);
        if (iVar10 != 0) {
          return 0xc0000001;
        }
        puVar18[0xc] = iStack_54;
        uVar16 = (uVar16 - 0x34) - iStack_54;
        uVar11 = iStack_54 + 0x34;
        if (*(longlong *)(lVar3 + 0x128) != 0) {
          uVar20 = *(int *)(lVar3 + 0x7c) * 0x10;
          if ((int)uVar16 < (int)uVar20) {
            return 0x80000005;
          }
          uVar16 = uVar16 + *(int *)(lVar3 + 0x7c) * -0x10;
          puVar18[10] = uVar20;
          puVar18[9] = uVar11;
          memmove((void *)((ulonglong)uVar11 + (longlong)puVar18),*(void **)(lVar3 + 0x80),
                  (ulonglong)uVar20);
          puVar18[7] = uVar11 + uVar20;
          puVar13 = (undefined8 *)((ulonglong)(uVar11 + uVar20) + (longlong)puVar18);
          for (puVar14 = (undefined8 *)**(undefined8 **)(lVar3 + 0x128);
              puVar14 != (undefined8 *)0x0; puVar14 = (undefined8 *)*puVar14) {
            if (uVar16 < 0x28) {
              return 0x80000005;
            }
            puVar18[8] = puVar18[8] + 0x28;
            uVar16 = uVar16 - 0x28;
            uVar9 = puVar14[1];
            *puVar13 = *puVar14;
            puVar13[1] = uVar9;
            uVar9 = puVar14[3];
            puVar13[2] = puVar14[2];
            puVar13[3] = uVar9;
            puVar13[4] = puVar14[4];
            *puVar13 = 0;
            puVar13[1] = 0;
            puVar13 = puVar13 + 5;
          }
          puVar18 = (undefined4 *)((longlong)puVar18 + (ulonglong)(uint)puVar18[8]);
        }
      }
    }
  }
  return uVar15;
}



===== ControlRestoreEarlyDumpData @ 140001ba4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 ControlRestoreEarlyDumpData(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 *puVar2;
  longlong lVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  int iVar8;
  undefined8 *puVar9;
  void *_Dst;
  longlong *plVar10;
  undefined8 *puVar11;
  longlong lVar12;
  longlong *plVar13;
  uint uVar14;
  undefined8 *puVar15;
  uint local_res8;
  undefined8 local_68;
  longlong lStack_60;
  undefined8 local_58;
  longlong lStack_50;
  ulonglong local_48;
  
  local_48 = 0;
  local_68 = 0;
  lStack_60 = 0;
  local_58 = 0;
  lStack_50 = 0;
  uVar14 = *(uint *)(*(longlong *)(param_2 + 8) + 8);
  if (uVar14 != 0) {
    lVar1 = *(longlong *)(param_2 + 8) + (ulonglong)uVar14;
    puVar9 = (undefined8 *)(*(longlong *)(*(longlong *)(param_1 + 0x40) + 0x70) + 0x28);
    for (puVar2 = (undefined8 *)*puVar9; puVar2 != puVar9; puVar2 = (undefined8 *)*puVar2) {
      if ((puVar2[2] == *(longlong *)(lVar1 + 0xc)) && (puVar2[3] == *(longlong *)(lVar1 + 0x14))) {
        lVar12 = puVar2[5];
        lVar3 = *(longlong *)(puVar2[6] + 0x48);
        if ((*(uint *)(lVar3 + 0xb8) & 0x10000) == 0) {
          return 0xc00000bb;
        }
        uVar14 = *(uint *)(lVar1 + 0x28);
        if (uVar14 != 0) {
          _Dst = (void *)ExAllocatePool2(0x40,uVar14,0x44436152);
          *(void **)(lVar12 + 0x80) = _Dst;
          if (_Dst == (void *)0x0) {
            return 0xc0000017;
          }
          memmove(_Dst,(void *)((ulonglong)*(uint *)(lVar1 + 0x24) + lVar1),(ulonglong)uVar14);
          *(uint *)(lVar12 + 0x7c) = uVar14 >> 4;
        }
        if (*(int *)(lVar1 + 0x30) != 0) {
          local_48 = 0;
          local_58 = 0;
          lStack_50 = 0;
          local_68 = CONCAT44(*(undefined4 *)(lVar1 + 0x30),0x28);
          lStack_60 = (ulonglong)*(uint *)(lVar1 + 0x2c) + lVar1;
          iVar8 = (**(code **)(lVar3 + 0x78))(0,0x19,&local_68);
          if (iVar8 != 3) {
            return 0xc0000001;
          }
          uVar4 = (undefined4)local_48;
          lStack_50 = ExAllocatePool2(0x40,local_48 & 0xffffffff,0x44436152);
          if (lStack_50 == 0) {
            return 0xc0000017;
          }
          local_58 = CONCAT44(local_58._4_4_,uVar4);
          iVar8 = (**(code **)(lVar3 + 0x78))(0,0x19,&local_68);
          if (iVar8 != 0) {
            return 0xc0000001;
          }
          *(longlong *)(lVar12 + 0x88) = lStack_50;
        }
        puVar15 = (undefined8 *)((ulonglong)*(uint *)(lVar1 + 0x1c) + lVar1);
        plVar10 = (longlong *)ExAllocatePool2(0x40,*(int *)(lVar1 + 0x20) + 8,0x44436152);
        *(longlong **)(lVar12 + 0x128) = plVar10;
        if (plVar10 == (longlong *)0x0) {
          return 0xc0000017;
        }
        local_res8 = 0;
        *plVar10 = (longlong)(plVar10 + 1);
        uVar14 = *(uint *)(lVar1 + 0x20) / 0x28;
        if (uVar14 != 0) {
          plVar13 = plVar10 + 4;
          puVar11 = (undefined8 *)0x0;
          plVar10 = plVar10 + 1;
          do {
            if (puVar11 != (undefined8 *)0x0) {
              *puVar11 = plVar10;
            }
            uVar7 = puVar15[1];
            *plVar10 = *puVar15;
            plVar10[1] = uVar7;
            uVar4 = *(undefined4 *)((longlong)puVar15 + 0x14);
            uVar5 = *(undefined4 *)(puVar15 + 3);
            uVar6 = *(undefined4 *)((longlong)puVar15 + 0x1c);
            *(undefined4 *)(plVar10 + 2) = *(undefined4 *)(puVar15 + 2);
            *(undefined4 *)((longlong)plVar10 + 0x14) = uVar4;
            *(undefined4 *)(plVar10 + 3) = uVar5;
            *(undefined4 *)((longlong)plVar10 + 0x1c) = uVar6;
            plVar10[4] = puVar15[4];
            lVar12 = MmMapIoSpaceEx(*plVar13,(int)plVar13[-1],0x204);
            plVar13[-2] = lVar12;
            if (lVar12 == 0) {
              return 0xc000000d;
            }
            local_res8 = local_res8 + 1;
            puVar15 = puVar15 + 5;
            plVar13 = plVar13 + 5;
            puVar11 = plVar10;
            plVar10 = plVar10 + 5;
          } while (local_res8 < uVar14);
        }
      }
    }
  }
  return 0;
}



===== ControlStart @ 140001e38 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 ControlStart(longlong param_1)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  char cVar5;
  longlong lVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  undefined8 local_18;
  code *local_10;
  
  lVar6 = *(longlong *)(param_1 + 0x38);
  uVar8 = 2;
  lVar3 = *(longlong *)(param_1 + 0x30);
  lVar4 = *(longlong *)(lVar6 + 0x30);
  if ((*(byte *)(lVar4 + 0x132) & 2) == 0) {
    cVar5 = (**(code **)(*(longlong *)(*(longlong *)(lVar6 + 0x38) + 0x48) + 8))
                      (*(longlong *)(*(longlong *)(lVar4 + 0x138) + 8) + 0x10);
    if (cVar5 == '\0') {
      FreeAdapterResources(lVar6);
      return 0xc0000001;
    }
    *(ushort *)(lVar4 + 0x132) = *(ushort *)(lVar4 + 0x132) | 2;
  }
  lVar6 = IssueInquiry(param_1);
  if ((lVar6 == 0) || (cVar5 = ResetBus(param_1), cVar5 == '\0')) {
    return 0xc0000001;
  }
  StartDisk(param_1);
  IssueReadCapacity(param_1);
  if (*(int *)(lVar3 + 0x58) == 0) {
    return 0xc0000001;
  }
  uVar7 = Feature_SteelixInlineNvmeCryptoEngine__private_IsEnabledNoReportingNoInline();
  if ((int)uVar7 == 0) {
    return 0;
  }
  lVar6 = *(longlong *)(lVar3 + 0x60);
  if (lVar6 == 0) {
    return 0;
  }
  if (*(code **)(lVar6 + 0x68) == (code *)0x0) {
    return 0;
  }
  local_18 = 0x10;
  local_10 = (code *)0x0;
  lVar3 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x38) + 0x38) + 0x70);
  iVar1 = *(int *)(lVar3 + 4);
  iVar2 = *(int *)(lVar3 + 8);
  if (iVar1 == 1) {
LAB_140001f5a:
    uVar8 = 1;
  }
  else {
    if ((iVar1 != 2) || (iVar2 != 0)) {
      if (iVar2 == 1) goto LAB_140001f5a;
      if (iVar2 != 2) {
        if (iVar2 == 3) {
          uVar8 = 3;
        }
        else {
          uVar8 = 0;
        }
        goto LAB_140001f5f;
      }
    }
    local_10 = NvmeIceDumpMarkHiberMemory;
  }
LAB_140001f5f:
  uVar8 = (**(code **)(lVar6 + 0x68))(*(undefined8 *)(lVar6 + 8),uVar8,&local_18);
  if ((int)uVar8 < 0) {
    return uVar8;
  }
  return 0;
}



===== DspAcquireCryptoKeyResources @ 140001f9c =====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int DspAcquireCryptoKeyResources(longlong param_1,longlong param_2,longlong param_3)

{
  uint uVar1;
  longlong lVar2;
  uint *puVar3;
  void *_Src;
  code *pcVar4;
  undefined8 uVar5;
  longlong lVar6;
  int iVar7;
  int iVar8;
  ulonglong uVar9;
  undefined1 *puVar10;
  undefined8 uStack_60;
  undefined1 auStack_58 [32];
  undefined4 local_38;
  undefined1 auStack_34 [8];
  undefined4 uStack_2c;
  
  puVar10 = auStack_58;
  register0x00000000 = __security_cookie ^ (ulonglong)&local_38;
  iVar8 = 0;
  if ((param_1 == 0) || (lVar2 = *(longlong *)(param_1 + 8), lVar2 == 0)) {
    iVar8 = 0;
  }
  else {
    puVar3 = *(uint **)(lVar2 + 8);
    uStack_60 = 0x140002002;
    iVar7 = memcmp(puVar3 + 6,(undefined8 *)(param_2 + 0x2f0),0x20);
    puVar10 = auStack_58;
    if (iVar7 != 0) {
      local_38 = puVar3[5] + 0x38;
      uVar9 = (ulonglong)local_38 + 0xf;
      if (uVar9 <= local_38) {
        uVar9 = 0xffffffffffffff0;
      }
      uStack_60 = 0x140002032;
      lVar6 = -(uVar9 & 0xfffffffffffffff0);
      *(short *)(auStack_58 + lVar6 + 0x20) = (short)puVar3[2];
      *(short *)(auStack_34 + lVar6 + -2) = (short)(*(uint *)(param_2 + 0x238) >> 10);
      *(undefined4 *)(auStack_34 + lVar6) = *(undefined4 *)(param_3 + 0x58);
      *(undefined4 *)(auStack_34 + lVar6 + 4) = 0x1000;
      *(undefined8 *)(auStack_34 + lVar6 + 0x24) = *(undefined8 *)(param_2 + 0x2e8);
      if (*puVar3 < 2) {
        *(undefined4 *)(auStack_34 + lVar6 + 8) = 0;
      }
      else {
        *(uint *)(auStack_34 + lVar6 + 8) = puVar3[0x16];
        uVar5 = *(undefined8 *)(puVar3 + 0x14);
        *(undefined8 *)(auStack_34 + lVar6 + 0x10) = *(undefined8 *)(puVar3 + 0x12);
        *(undefined8 *)(auStack_34 + lVar6 + 0x18) = uVar5;
      }
      *(short *)(auStack_34 + lVar6 + 0xc) = (short)puVar3[5];
      uVar1 = puVar3[5];
      _Src = *(void **)(puVar3 + 0xe);
      *(undefined8 *)(auStack_58 + lVar6 + -8) = 0x14000209e;
      memmove(auStack_34 + lVar6 + 0x2c,_Src,(ulonglong)uVar1);
      *(undefined8 *)(param_2 + 0x2e0) = *(undefined8 *)(param_3 + 0x60);
      pcVar4 = *(code **)(*(longlong *)(param_3 + 0x60) + 0x30);
      uVar5 = *(undefined8 *)(*(longlong *)(param_3 + 0x60) + 8);
      *(undefined8 *)(auStack_58 + lVar6 + -8) = 0x1400020c1;
      iVar8 = (*pcVar4)(uVar5,auStack_58 + lVar6 + 0x20,&local_38);
      puVar10 = auStack_58 + lVar6;
      if (iVar8 != 0) {
        puVar10 = auStack_58 + lVar6;
        if (-1 < iVar8) {
          iVar8 = -0x3fffffff;
          puVar10 = auStack_58 + lVar6;
        }
        goto LAB_14000210d;
      }
      uVar5 = *(undefined8 *)(puVar3 + 8);
      *(undefined8 *)(param_2 + 0x2f0) = *(undefined8 *)(puVar3 + 6);
      *(undefined8 *)(param_2 + 0x2f8) = uVar5;
      uVar5 = *(undefined8 *)(puVar3 + 0xc);
      *(undefined8 *)(param_2 + 0x300) = *(undefined8 *)(puVar3 + 10);
      *(undefined8 *)(param_2 + 0x308) = uVar5;
      *(undefined8 *)(param_2 + 0x2e8) = *(undefined8 *)(auStack_34 + lVar6 + 0x24);
      *(undefined4 *)(param_2 + 0x328) = *(undefined4 *)(param_3 + 0x58);
    }
    *(int *)(param_2 + 0x310) = *(int *)(param_2 + 0x310) + 1;
    *(longlong *)(param_2 + 0x318) = lVar2;
  }
LAB_14000210d:
  *(undefined8 *)(puVar10 + -8) = 0x140002119;
  return iVar8;
}



===== DspControl @ 140002140 =====

ulonglong DspControl(longlong param_1,int param_2,int *param_3)

{
  ushort *puVar1;
  undefined8 *puVar2;
  longlong lVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  
  if ((param_2 == 0) || (10 < param_2)) {
    return 0xc000000d;
  }
  puVar2 = *(undefined8 **)(param_1 + 0x30);
  if (*(int *)((longlong)puVar2 + 4) == 0x2002) {
    uVar5 = DspNvmeControl(param_1,param_2,param_3,puVar2);
    return uVar5;
  }
  if (param_2 < 7) {
    if (param_2 == 6) {
      lVar3 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x38) + 0x30) + 0x138);
      *param_3 = *(int *)(puVar2 + 0xb);
      param_3[1] = *(int *)(lVar3 + 0x238);
      return 0;
    }
    if (param_2 == 1) {
      uVar4 = ControlPowerOn(param_1,(char *)param_3);
    }
    else if (param_2 == 2) {
      uVar6 = ControlPrepare(param_1);
      uVar4 = (uint)uVar6;
    }
    else {
      if (param_2 == 3) {
        puVar1 = (ushort *)(*(longlong *)(*(longlong *)(param_1 + 0x38) + 0x30) + 0x132);
        *puVar1 = *puVar1 & 0xfffe;
        return 0;
      }
      if (param_2 != 4) {
        if (param_2 == 5) {
          return 0;
        }
        return 0xc00000bb;
      }
      uVar6 = ControlStart(param_1);
      uVar4 = (uint)uVar6;
    }
  }
  else {
    if (param_2 == 7) {
      ControlCleanup(param_1,param_3);
      return 0;
    }
    if (param_2 == 8) {
      uVar5 = ControlGetDeviceInternalLog(param_1,(undefined8 *)param_3);
      uVar4 = (uint)uVar5;
    }
    else if (param_2 == 9) {
      uVar6 = ControlPrepareEarlyDumpData(param_1,(longlong)param_3);
      uVar4 = (uint)uVar6;
    }
    else {
      if (param_2 != 10) {
        return 0xc00000bb;
      }
      uVar6 = ControlRestoreEarlyDumpData(param_1,(longlong)param_3);
      uVar4 = (uint)uVar6;
    }
  }
  return (ulonglong)uVar4;
}



===== DspFlush @ 140002240 =====

undefined8 DspFlush(longlong param_1)

{
  longlong lVar1;
  longlong *plVar2;
  undefined4 *puVar3;
  undefined8 uVar4;
  undefined4 *puVar5;
  
  lVar1 = *(longlong *)(param_1 + 0x30);
  if (*(int *)(lVar1 + 4) == 0x2002) {
    uVar4 = DspNvmeFlush(param_1);
  }
  else {
    plVar2 = *(longlong **)(*(longlong *)(*(longlong *)(param_1 + 0x38) + 0x30) + 0x138);
    puVar3 = (undefined4 *)plVar2[5];
    puVar5 = InitializeScsiSrb(plVar2,puVar3,0,0,10,0x2c,*(undefined1 *)(lVar1 + 0x52),
                               *(undefined1 *)(lVar1 + 0x53),*(undefined1 *)(lVar1 + 0x54),10,'\0');
    *(undefined1 *)puVar5 = 0x35;
    ExecuteSrb(param_1,(longlong)puVar3);
    uVar4 = 0;
  }
  return uVar4;
}



===== DspLiveControl @ 1400022e0 =====

undefined8 DspLiveControl(longlong param_1,int param_2,longlong param_3)

{
  undefined8 uVar1;
  
  if ((param_2 == 0) || (10 < param_2)) {
    uVar1 = 0xc000000d;
  }
  else if (param_2 == 7) {
    uVar1 = ControlEarlyInitCleanup(param_1,param_3);
  }
  else {
    uVar1 = 0xc00000bb;
  }
  return uVar1;
}



===== DspNvmeIceIoStart @ 140002314 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
DspNvmeIceIoStart(longlong param_1,undefined8 param_2,longlong param_3,undefined4 param_4,
                 uint param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8)

{
  undefined8 *puVar1;
  longlong lVar2;
  int iVar3;
  uint uVar4;
  code *pcVar5;
  undefined1 auStack_e8 [32];
  ulonglong local_c8;
  undefined8 local_b8;
  undefined4 local_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 local_98;
  undefined4 local_94;
  uint local_90;
  undefined4 local_8c;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_e8;
  puVar1 = *(undefined8 **)(param_1 + 0x318);
  lVar2 = *(longlong *)(param_1 + 0x2e0);
  local_b8 = param_6;
  if (puVar1 == (undefined8 *)0x0) {
    return 0;
  }
  pcVar5 = *(code **)(lVar2 + 0x48);
  if (pcVar5 == (code *)0x0) {
    return 0;
  }
  local_8c = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_80 = *puVar1;
  if (param_3 != 0) {
    local_b0 = *(undefined4 *)puVar1;
    uStack_ac = *(undefined4 *)((longlong)puVar1 + 4);
    uStack_a8 = *(undefined4 *)(puVar1 + 1);
    uStack_a4 = *(undefined4 *)((longlong)puVar1 + 0xc);
    iVar3 = (**(code **)(puVar1[1] + 0x60))
                      (*(undefined8 *)(puVar1[1] + 0x68),&local_b0,
                       (ulonglong)*(uint *)(param_1 + 0x328) * param_3);
    if (iVar3 < 0) {
      local_c8 = param_3;
                    /* WARNING: Subroutine does not return */
      KeBugCheckEx(0x2c,0x80000004,2,puVar1);
    }
    local_80 = CONCAT44(uStack_ac,local_b0);
    pcVar5 = *(code **)(lVar2 + 0x48);
  }
  local_88 = *(undefined8 *)(param_1 + 0x2e8);
  local_98 = 0x480001;
  local_90 = param_5;
  local_68 = local_b8;
  if (param_5 == 2) {
    local_60 = param_7;
  }
  else {
    local_60 = 0;
    if (2 < param_5) {
      local_58 = param_8;
      goto LAB_14000241c;
    }
  }
  local_58 = 0;
LAB_14000241c:
  local_94 = param_4;
  uVar4 = (*pcVar5)(*(undefined8 *)(lVar2 + 8),&local_98);
  if (uVar4 != 0) {
    local_c8 = (ulonglong)uVar4;
                    /* WARNING: Subroutine does not return */
    KeBugCheckEx(0x2c,0x80000004,0,&local_98);
  }
  *(undefined8 *)(param_1 + 800) = uStack_70;
  return 0;
}



===== DspRead @ 1400024a0 =====

void DspRead(longlong param_1,int param_2,ulonglong *param_3,longlong param_4)

{
  DspRead2(param_1,param_2,param_3,param_4,0);
  return;
}



===== DspRead2 @ 1400024c0 =====

void DspRead2(longlong param_1,int param_2,ulonglong *param_3,longlong param_4,longlong param_5)

{
  if (*(int *)(*(longlong *)(param_1 + 0x30) + 4) == 0x2002) {
    DspNvmeRead(param_1,param_2,param_3,param_4);
  }
  else {
    IssueIo('(',param_1,param_2,param_3,param_4,param_5);
  }
  return;
}



===== DspWrite @ 140002510 =====

void DspWrite(longlong param_1,int param_2,ulonglong *param_3,longlong param_4,undefined8 param_5)

{
  DspWrite2(param_1,param_2,param_3,param_4,param_5,0);
  return;
}



===== DspWrite2 @ 140002540 =====

ulonglong DspWrite2(longlong param_1,int param_2,ulonglong *param_3,longlong param_4,
                   undefined8 param_5,longlong param_6)

{
  longlong *plVar1;
  byte bVar2;
  longlong lVar3;
  longlong *plVar4;
  longlong lVar5;
  undefined4 *puVar6;
  undefined1 uVar9;
  undefined1 uVar8;
  undefined1 uVar7;
  uint uVar10;
  int iVar11;
  ulonglong uVar12;
  undefined4 extraout_var;
  ulonglong uVar13;
  undefined4 extraout_var_00;
  undefined4 *puVar14;
  undefined1 uVar15;
  uint uVar16;
  char local_res8;
  
  lVar3 = *(longlong *)(param_1 + 0x30);
  uVar10 = 0;
  if (*(int *)(lVar3 + 4) == 0x2002) {
    uVar12 = DspNvmeWrite(param_1,param_2,param_3,param_4);
  }
  else {
    plVar4 = *(longlong **)(*(longlong *)(*(longlong *)(param_1 + 0x38) + 0x30) + 0x138);
    lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x70);
    if (param_2 == 1) {
      puVar6 = (undefined4 *)plVar4[5];
      *(ulonglong *)(param_4 + 0x20) = *(ulonglong *)(param_4 + 0x20) & 0xfffffffffffff000;
      *(undefined4 *)(plVar4 + 0xc) = *(undefined4 *)(param_4 + 0x28);
      if ((*(int *)(lVar5 + 4) != 2) || (local_res8 = '\x01', *(int *)(lVar5 + 8) != 2)) {
        local_res8 = '\0';
      }
      while( true ) {
        if ((uVar10 != 0) && (*(int *)(lVar5 + 4) == 1)) {
          MmMapMemoryDumpMdl(param_4);
        }
        plVar4[8] = param_4;
        if ((char)plVar4[0x56] == '\0') {
          uVar12 = (ulonglong)*(uint *)(param_4 + 0x2c) + *(longlong *)(param_4 + 0x20);
        }
        else {
          uVar12 = *(ulonglong *)(param_4 + 0x18);
          *(ulonglong *)(param_4 + 0x20) = uVar12 & 0xfffffffffffff000;
        }
        bVar2 = *(byte *)(lVar3 + 0x55);
        uVar13 = Feature_SteelixInlineNvmeCryptoEngine__private_IsEnabledNoReportingNoInline();
        if ((int)uVar13 != 0) {
          iVar11 = DspAcquireCryptoKeyResources(param_6,(longlong)plVar4,lVar3);
          if (iVar11 < 0) {
            return CONCAT44(extraout_var_00,iVar11);
          }
        }
        puVar14 = InitializeScsiSrb(plVar4,puVar6,uVar12,*(undefined4 *)(param_4 + 0x28),10,0xac,
                                    *(undefined1 *)(lVar3 + 0x52),*(undefined1 *)(lVar3 + 0x53),
                                    *(undefined1 *)(lVar3 + 0x54),(-((bVar2 & 1) != 0) & 6U) + 10,
                                    local_res8);
        uVar12 = *param_3 / (ulonglong)*(uint *)(lVar3 + 0x58);
        uVar16 = *(uint *)(param_4 + 0x28) >> ((byte)*(undefined4 *)(lVar3 + 0x5c) & 0x1f);
        uVar15 = (undefined1)(uVar12 >> 8);
        uVar7 = (undefined1)(uVar12 >> 0x10);
        uVar8 = (undefined1)(uVar12 >> 0x18);
        uVar9 = (undefined1)(uVar16 >> 8);
        if ((*(byte *)(lVar3 + 0x55) & 1) == 0) {
          if (0xffffffff < uVar12) {
            return 0xc0000001;
          }
          *(undefined1 *)((longlong)puVar14 + 2) = uVar8;
          *(undefined1 *)((longlong)puVar14 + 3) = uVar7;
          *(undefined1 *)(puVar14 + 1) = uVar15;
          *(undefined1 *)((longlong)puVar14 + 7) = uVar9;
          *(undefined1 *)puVar14 = 0x2a;
          *(char *)((longlong)puVar14 + 5) = (char)uVar12;
          *(char *)(puVar14 + 2) = (char)uVar16;
        }
        else {
          *(undefined1 *)puVar14 = 0x8a;
          *(undefined1 *)((longlong)puVar14 + 7) = uVar7;
          *(undefined1 *)((longlong)puVar14 + 6) = uVar8;
          *(char *)((longlong)puVar14 + 5) = (char)(uVar12 >> 0x20);
          *(char *)(puVar14 + 1) = (char)(uVar12 >> 0x28);
          *(char *)((longlong)puVar14 + 3) = (char)(uVar12 >> 0x30);
          *(undefined1 *)(puVar14 + 3) = uVar9;
          *(char *)((longlong)puVar14 + 9) = (char)uVar12;
          *(char *)((longlong)puVar14 + 0xd) = (char)uVar16;
          *(char *)((longlong)puVar14 + 10) = (char)(uVar16 >> 0x18);
          *(undefined1 *)(puVar14 + 2) = uVar15;
          *(char *)((longlong)puVar14 + 2) = (char)(uVar12 >> 0x38);
          *(char *)((longlong)puVar14 + 0xb) = (char)(uVar16 >> 0x10);
        }
        ExecuteSrb(param_1,(longlong)puVar6);
        uVar12 = Feature_SteelixInlineNvmeCryptoEngine__private_IsEnabledNoReportingNoInline();
        if (((int)uVar12 != 0) && (plVar4[99] != 0)) {
          plVar1 = plVar4 + 0x62;
          *(int *)plVar1 = (int)*plVar1 + -1;
          if ((int)*plVar1 == 0) {
            plVar4[99] = 0;
          }
        }
        if ((*(byte *)((longlong)puVar6 + 3) & 0x3f) == 1) break;
        if (1 < uVar10) {
          return 0xc0000001;
        }
        uVar10 = uVar10 + 1;
      }
      return 0;
    }
    uVar10 = IssueIo('*',param_1,param_2,param_3,param_4,param_6);
    uVar12 = CONCAT44(extraout_var,uVar10);
  }
  return uVar12;
}



===== DumpPreInitialize @ 140002810 =====

void DumpPreInitialize(void)

{
                    /* 0x2810  1  DumpPreInitialize */
  wil_InitializeFeatureStaging();
  return;
}



===== DumpUninitialize @ 140002830 =====

void DumpUninitialize(void)

{
                    /* 0x2830  2  DumpUninitialize */
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



===== ExecuteSrb @ 140002888 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ExecuteSrb(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  longlong lVar2;
  code *pcVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  char cVar7;
  int iVar8;
  bool bVar9;
  char local_res8 [8];
  
  local_res8[0] = '\0';
  plVar1 = *(longlong **)(*(longlong *)(*(longlong *)(param_1 + 0x38) + 0x30) + 0x138);
  lVar2 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x38) + 0x38) + 0x48);
  StartIo(plVar1,param_2);
  iVar8 = 10;
  while (*(char *)((longlong)plVar1 + 0x2b3) != '\0') {
    uVar5 = 0;
    do {
      uVar6 = 0;
      do {
        if (((*(uint *)((longlong)plVar1 + 0x24c) & 0x20) == 0) &&
           (pcVar3 = *(code **)(lVar2 + 0x18), pcVar3 != (code *)0x0)) {
          (*pcVar3)(plVar1[1] + 0x10);
        }
        if (*(char *)((longlong)plVar1 + 0x2b3) == '\0') {
          bVar9 = iVar8 == 0;
          iVar8 = iVar8 + -1;
          if (bVar9) goto LAB_1400029f0;
        }
        if ((*(uint *)((longlong)plVar1 + 0x24c) & 0x40) != 0) {
          *(uint *)((longlong)plVar1 + 0x24c) = *(uint *)((longlong)plVar1 + 0x24c) & 0xffffffbf;
          (*(code *)plVar1[0x54])(plVar1[1] + 0x10);
          if ((*(uint *)((longlong)plVar1 + 0x24c) & 0x10) != 0) {
            *(uint *)((longlong)plVar1 + 0x24c) = *(uint *)((longlong)plVar1 + 0x24c) & 0xffffffcf;
            (*(code *)plVar1[0x54])(plVar1[1] + 0x10);
          }
        }
        if ((*(uint *)((longlong)plVar1 + 0x24c) & 8) != 0) {
          *(uint *)((longlong)plVar1 + 0x24c) = *(uint *)((longlong)plVar1 + 0x24c) & 0xfffffff7;
          pcVar3 = *(code **)(lVar2 + 0x30);
          if (pcVar3 != (code *)0x0) {
            (*pcVar3)(plVar1[1] + 0x10);
          }
        }
        KeStallExecutionProcessor(5);
        if ((*(int *)((longlong)plVar1 + 700) != 0) &&
           (iVar4 = *(int *)((longlong)plVar1 + 700) + -1, *(int *)((longlong)plVar1 + 700) = iVar4,
           iVar4 == 0)) {
          (*(code *)plVar1[0x55])(plVar1[1] + 0x10);
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 < 50000);
      uVar5 = uVar5 + 1;
    } while (uVar5 < 4);
    TickHandler(param_1,param_2);
  }
LAB_1400029f0:
  if ((param_2 == plVar1[5]) && (*(char *)(param_2 + 3) != '\x01')) {
    cVar7 = '\0';
    RetrieveScsiStatusAndCdbOpcode(param_2,local_res8,(undefined1 *)0x0);
    if ((local_res8[0] == '\x02') && (*(char *)((longlong)plVar1 + 0x2b2) == cVar7)) {
      IssueRequestSense(param_1);
    }
  }
  return;
}



===== Feature_CrashDumpOneMBTransferSize__private_IsEnabledFallback @ 140002a44 =====

void Feature_CrashDumpOneMBTransferSize__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback
            (param_1,param_2,&Feature_CrashDumpOneMBTransferSize__private_descriptor);
  return;
}



===== Feature_CrashDumpOneMBTransferSize__private_IsEnabledNoReportingNoInline @ 140002a60 =====

ulonglong Feature_CrashDumpOneMBTransferSize__private_IsEnabledNoReportingNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_CrashDumpOneMBTransferSize__private_featureState;
  if ((Feature_CrashDumpOneMBTransferSize__private_featureState & 2) == 0) {
    uVar1 = Feature_CrashDumpOneMBTransferSize__private_IsEnabledFallback(local_res8,0);
  }
  else {
    uVar1 = (ulonglong)(Feature_CrashDumpOneMBTransferSize__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_SteelixInlineNvmeCryptoEngine__private_IsEnabledFallback @ 140002a98 =====

void Feature_SteelixInlineNvmeCryptoEngine__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback
            (param_1,param_2,&Feature_SteelixInlineNvmeCryptoEngine__private_descriptor);
  return;
}



===== Feature_SteelixInlineNvmeCryptoEngine__private_IsEnabledNoReportingNoInline @ 140002ab4 =====

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



===== FreeAdapterResources @ 140002aec =====

void FreeAdapterResources(longlong param_1)

{
  longlong lVar1;
  undefined8 *puVar2;
  
  lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x138);
  if (lVar1 != 0) {
    if (*(char *)(lVar1 + 0x2b5) != '\0') {
      HalDmaFreeCrashDumpRegistersEx(*(undefined8 *)(param_1 + 0x40),0);
      HalDmaFreeCrashDumpRegistersEx(*(undefined8 *)(param_1 + 0x40),1);
      *(undefined1 *)(lVar1 + 0x2b5) = 0;
    }
    if (*(longlong *)(lVar1 + 8) != 0) {
      puVar2 = (undefined8 *)(*(longlong *)(lVar1 + 8) + -0x18);
      *puVar2 = *(undefined8 *)(lVar1 + 0x10);
      *(undefined8 *)(lVar1 + 8) = 0;
      *(undefined8 **)(lVar1 + 0x10) = puVar2;
    }
    if (*(longlong *)(lVar1 + 0x50) != 0) {
      puVar2 = (undefined8 *)(*(longlong *)(lVar1 + 0x50) + -0x18);
      *puVar2 = *(undefined8 *)(lVar1 + 0x10);
      *(undefined8 *)(lVar1 + 0x50) = 0;
      *(undefined8 **)(lVar1 + 0x10) = puVar2;
    }
  }
  return;
}



===== GetDeviceTransferSize @ 140002b8c =====

uint GetDeviceTransferSize(longlong param_1)

{
  uint uVar1;
  ulonglong uVar2;
  uint uVar3;
  
  if (param_1 == 0) {
    return 0x8000;
  }
  uVar2 = Feature_CrashDumpOneMBTransferSize__private_IsEnabledNoReportingNoInline();
  uVar1 = *(uint *)(param_1 + 0x18);
  if ((int)uVar2 == 0) {
    uVar3 = 0x8000;
    if (uVar1 != 0) {
      uVar3 = uVar1;
    }
    if (*(int *)(param_1 + 8) != 5) {
      if (uVar3 < 0x8001) {
        return uVar3;
      }
      return 0x8000;
    }
    if (uVar3 < 0x10001) {
      return uVar3;
    }
  }
  else if (uVar1 < 0x10000) {
    if (uVar1 < 0x8001) {
      return 0x8000;
    }
    return uVar1;
  }
  return 0x10000;
}



===== InitializeScsiSrb @ 140002c00 =====

undefined4 *
InitializeScsiSrb(longlong *param_1,undefined4 *param_2,undefined8 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined1 param_7,undefined1 param_8,
                 undefined1 param_9,undefined1 param_10,char param_11)

{
  longlong lVar1;
  undefined4 uVar2;
  longlong lVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  size_t _Size;
  
  puVar5 = (undefined4 *)0x0;
  if (param_2 != (undefined4 *)0x0) {
    lVar1 = *(longlong *)(*param_1 + 0x30);
    if ((*(uint *)(lVar1 + 0x48) < 0xd1) || (*(char *)(lVar1 + 0xaa) != '\x01')) {
      memset(param_2,0,0x58);
      puVar5 = param_2 + 0x12;
      *(undefined8 *)(param_2 + 10) = 0;
      *(undefined1 *)((longlong)param_2 + 5) = param_7;
      *(undefined1 *)((longlong)param_2 + 6) = param_8;
      *(undefined1 *)((longlong)param_2 + 7) = param_9;
      *(undefined1 *)((longlong)param_2 + 10) = param_10;
      param_2[5] = param_5;
      param_2[3] = param_6;
      *param_2 = 0x58;
      *(undefined8 *)(param_2 + 6) = param_3;
      param_2[4] = param_4;
      *(undefined1 *)(param_2 + 1) = 0;
    }
    else {
      if ((param_11 == '\0') || (_Size = 0xe0, *(short *)(lVar1 + 0x130) == -1)) {
        _Size = 0xb8;
      }
      memset(param_2,0,_Size);
      *(undefined8 *)(param_2 + 0x1c) = 0;
      param_2[10] = param_5;
      *param_2 = 0x280008;
      param_2[2] = 0x53524258;
      param_2[3] = 1;
      *(undefined2 *)(param_2 + 9) = 2;
      *(undefined8 *)(param_2 + 0x10) = param_3;
      param_2[0xf] = param_4;
      param_2[6] = param_6;
      if ((param_11 == '\0') || (*(short *)(lVar1 + 0x130) == -1)) {
        param_2[4] = 0xb8;
        uVar2 = 0x90;
        param_2[0xd] = 0x80;
        lVar3 = 0x80;
        param_2[0xe] = 1;
      }
      else {
        lVar3 = 0x88;
        param_2[4] = 0xe0;
        param_2[0xd] = 0x88;
        uVar2 = 0x98;
        param_2[0xe] = 2;
        param_2[0x1f] = 0xc0;
      }
      param_2[0x1e] = uVar2;
      *(undefined1 *)(lVar3 + 8 + (longlong)param_2) = param_7;
      *(undefined1 *)(lVar3 + 9 + (longlong)param_2) = param_8;
      *(undefined1 *)(lVar3 + 10 + (longlong)param_2) = param_9;
      *(undefined2 *)(lVar3 + (longlong)param_2) = 1;
      *(undefined4 *)(lVar3 + 4 + (longlong)param_2) = 4;
      puVar4 = (undefined4 *)((ulonglong)(uint)param_2[0x1e] + (longlong)param_2);
      puVar5 = puVar4 + 6;
      *puVar4 = 0x40;
      puVar4[1] = 0x20;
      *(undefined1 *)((longlong)puVar4 + 10) = param_10;
      *(undefined1 *)(puVar4 + 2) = 0;
      if ((param_11 == '\x01') && (*(short *)(lVar1 + 0x130) != -1)) {
        puVar4 = (undefined4 *)((ulonglong)(uint)param_2[0x1f] + (longlong)param_2);
        puVar4[3] = 0;
        *puVar4 = 0x80;
        puVar4[1] = 0x18;
        puVar4[2] = 0x80000000;
        puVar4[4] = param_4;
        *(undefined1 *)(puVar4 + 5) = 1;
        *(undefined1 *)((longlong)puVar4 + 0x15) = *(undefined1 *)(lVar1 + 0x130);
      }
    }
  }
  return puVar5;
}



===== IssueInquiry @ 140002e14 =====

undefined8 IssueInquiry(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  longlong *plVar3;
  undefined8 uVar4;
  undefined4 *puVar5;
  byte bVar6;
  undefined4 *puVar7;
  uint uVar8;
  
  lVar1 = *(longlong *)(param_1 + 0x38);
  lVar2 = *(longlong *)(param_1 + 0x30);
  uVar8 = 0;
  plVar3 = *(longlong **)(*(longlong *)(lVar1 + 0x30) + 0x138);
  KeGetRecommendedSharedDataAlignment();
  uVar4 = *(undefined8 *)(lVar1 + 0x58);
  puVar5 = (undefined4 *)plVar3[5];
  while( true ) {
    puVar7 = InitializeScsiSrb(plVar3,puVar5,uVar4,0x24,5,0x6c,*(undefined1 *)(lVar2 + 0x52),
                               *(undefined1 *)(lVar2 + 0x53),*(undefined1 *)(lVar2 + 0x54),6,'\0');
    plVar3[8] = 0;
    plVar3[9] = plVar3[4];
    *(undefined2 *)puVar7 = 0x12;
    *(undefined2 *)((longlong)puVar7 + 3) = 0x2400;
    *(undefined1 *)((longlong)puVar7 + 2) = 0;
    *(undefined1 *)((longlong)puVar7 + 5) = 0;
    ExecuteSrb(param_1,(longlong)puVar5);
    if (((*(byte *)((longlong)puVar5 + 3) & 0x3f) == 1) ||
       (bVar6 = *(byte *)((longlong)puVar5 + 3) & 0x3f, bVar6 == 0x12)) {
      return uVar4;
    }
    if ((bVar6 == 10) || (1 < uVar8)) break;
    uVar8 = uVar8 + 1;
  }
  return 0;
}



===== IssueIo @ 140002f38 =====

uint IssueIo(char param_1,longlong param_2,int param_3,ulonglong *param_4,longlong param_5,
            longlong param_6)

{
  longlong *plVar1;
  longlong *plVar2;
  uint uVar3;
  longlong lVar4;
  ulonglong uVar5;
  
  plVar2 = *(longlong **)(*(longlong *)(*(longlong *)(param_2 + 0x38) + 0x30) + 0x138);
  if (param_3 - 1U < 2) {
    uVar3 = SetupIoRequest(param_2,param_4,param_5,param_1,param_6);
    if ((int)uVar3 < 0) {
      return uVar3;
    }
    StartIo(plVar2,plVar2[5]);
    *(undefined4 *)(plVar2 + 0x58) = 2;
    lVar4 = KeQueryPerformanceCounter(0);
    plVar2[0x5b] = lVar4;
  }
  do {
    if (param_3 == 1) goto LAB_140002fd8;
    if (param_3 == 4) goto LAB_140002fd8;
    uVar3 = 0;
    while( true ) {
      uVar3 = WaitOnRequest(param_2,uVar3);
      uVar5 = Feature_SteelixInlineNvmeCryptoEngine__private_IsEnabledNoReportingNoInline();
      if ((int)uVar5 == 0) {
        if (uVar3 == 0x103) {
          return 0x103;
        }
      }
      else {
        if (uVar3 == 0x103) {
          return 0x103;
        }
        if (plVar2[99] != 0) {
          plVar1 = plVar2 + 0x62;
          *(int *)plVar1 = (int)*plVar1 + -1;
          if ((int)*plVar1 == 0) {
            plVar2[99] = 0;
          }
        }
      }
      if (-1 < (int)uVar3) {
        return uVar3;
      }
      if ((int)plVar2[0x58] == 0) {
        return uVar3;
      }
      if (*(int *)(*(longlong *)(*(longlong *)(param_2 + 0x40) + 0x70) + 4) == 1) {
        MmMapMemoryDumpMdl(param_5);
      }
      uVar3 = SetupIoRequest(param_2,param_4,param_5,param_1,param_6);
      if ((int)uVar3 < 0) {
        return uVar3;
      }
      StartIo(plVar2,plVar2[5]);
      *(int *)(plVar2 + 0x58) = (int)plVar2[0x58] + -1;
      lVar4 = KeQueryPerformanceCounter(0);
      plVar2[0x5b] = lVar4;
      if (param_3 != 1) break;
LAB_140002fd8:
      uVar3 = 0xffffffff;
    }
    if (param_3 != 4) {
      return 0x103;
    }
  } while( true );
}



===== IssueReadBuffer @ 1400030d8 =====

undefined8
IssueReadBuffer(longlong param_1,void *param_2,uint *param_3,undefined1 param_4,undefined8 param_5,
               char param_6)

{
  longlong lVar1;
  longlong lVar2;
  longlong *plVar3;
  void *_Src;
  undefined4 *puVar4;
  undefined8 *puVar5;
  byte bVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  lVar1 = *(longlong *)(param_1 + 0x30);
  lVar2 = *(longlong *)(param_1 + 0x38);
  plVar3 = *(longlong **)(*(longlong *)(lVar2 + 0x30) + 0x138);
  KeGetRecommendedSharedDataAlignment();
  _Src = *(void **)(lVar2 + 0x58);
  puVar4 = (undefined4 *)plVar3[5];
  uVar9 = *param_3;
  if (*(uint *)(lVar2 + 0x48) <= *param_3) {
    uVar9 = *(uint *)(lVar2 + 0x48);
  }
  param_5._1_1_ = (undefined1)(uVar9 >> 8);
  param_5._2_1_ = (undefined1)(uVar9 >> 0x10);
  param_5._3_1_ = (undefined1)(uVar9 >> 0x18);
  uVar7 = uVar9;
  if (param_6 == '\0') {
    uVar7 = uVar9 & 0xfffffe00;
    param_5._1_1_ = (undefined1)(uVar7 >> 8);
    param_5._2_1_ = (undefined1)(uVar7 >> 0x10);
    param_5._3_1_ = (undefined1)(uVar7 >> 0x18);
  }
  uVar8 = uVar9 & 0xfffffe00;
  if (param_6 != '\0') {
    uVar8 = uVar9;
  }
  uVar10 = uVar9 & 0xfffffe00;
  if (param_6 != '\0') {
    uVar10 = uVar9;
  }
  puVar5 = (undefined8 *)
           InitializeScsiSrb(plVar3,puVar4,_Src,uVar10,10,0x6c,*(undefined1 *)(lVar1 + 0x52),
                             *(undefined1 *)(lVar1 + 0x53),*(undefined1 *)(lVar1 + 0x54),0x10,'\0');
  *puVar5 = 0;
  puVar5[1] = 0;
  *(undefined2 *)puVar5 = 0x3c9b;
  *(undefined1 *)((longlong)puVar5 + 0xe) = param_4;
  if (param_6 == '\0') {
    *(byte *)((longlong)puVar5 + 0xb) = (byte)(uVar8 >> 0x19);
    *(char *)((longlong)puVar5 + 0xd) = (char)(uVar8 >> 9);
    *(char *)((longlong)puVar5 + 0xc) = (char)(uVar8 >> 0x11);
  }
  else {
    *(undefined1 *)((longlong)puVar5 + 0xc) = param_5._1_1_;
    *(undefined1 *)((longlong)puVar5 + 0xb) = param_5._2_1_;
    *(undefined1 *)((longlong)puVar5 + 10) = param_5._3_1_;
    *(char *)((longlong)puVar5 + 0xd) = (char)uVar7;
  }
  plVar3[8] = 0;
  plVar3[9] = plVar3[4];
  ExecuteSrb(param_1,(longlong)puVar4);
  RetrieveScsiStatusAndCdbOpcode((longlong)puVar4,(undefined1 *)0x0,&param_6);
  if ((*(byte *)((longlong)puVar4 + 3) & 0x3f) == 1) {
    if (*(char *)((longlong)puVar4 + 2) == '(') {
      uVar9 = puVar4[0xf];
    }
    else {
      uVar9 = puVar4[4];
    }
    memmove(param_2,_Src,(ulonglong)uVar9);
  }
  else {
    uVar9 = 0;
  }
  *param_3 = uVar9;
  bVar6 = *(byte *)((longlong)puVar4 + 3) & 0x3f;
  if (bVar6 < 0xf) {
    if (bVar6 == 0xe) {
      return 0xc00000b5;
    }
    if ((*(byte *)((longlong)puVar4 + 3) & 0x3f) == 0) {
      return 0x103;
    }
    if (bVar6 == 1) {
      return 0;
    }
    if (bVar6 == 6) {
      return 0xc0000010;
    }
    if (bVar6 != 8) {
      if (bVar6 == 9) {
        return 0xc00000b5;
      }
      if (bVar6 == 10) {
        return 0xc000009d;
      }
      if (bVar6 == 0xb) {
        return 0xc00000b5;
      }
      return 0xc0000185;
    }
  }
  else if (bVar6 != 0x11) {
    if (bVar6 == 0x12) {
      return 0x80000005;
    }
    if (bVar6 != 0x15) {
      if (bVar6 == 0x20) {
        return 0xc00000c0;
      }
      if (bVar6 == 0x21) {
        return 0xc00000c0;
      }
      if (bVar6 != 0x22) {
        return 0xc0000185;
      }
    }
    return 0xc0000010;
  }
  return 0xc00000c0;
}



===== IssueReadCapacity @ 140003310 =====

void IssueReadCapacity(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  longlong *plVar3;
  undefined4 *puVar4;
  int *piVar5;
  bool bVar6;
  uint uVar7;
  undefined4 *puVar8;
  byte bVar9;
  uint uVar10;
  char local_res8 [8];
  
  lVar1 = *(longlong *)(param_1 + 0x38);
  lVar2 = *(longlong *)(param_1 + 0x30);
  uVar10 = 0;
  local_res8[0] = '\0';
  bVar6 = false;
  plVar3 = *(longlong **)(*(longlong *)(lVar1 + 0x30) + 0x138);
  KeGetRecommendedSharedDataAlignment();
  puVar4 = (undefined4 *)plVar3[5];
  piVar5 = *(int **)(lVar1 + 0x58);
  *(undefined4 *)(lVar2 + 0x58) = 0;
  *(undefined4 *)(lVar2 + 0x5c) = 0;
  while( true ) {
    while( true ) {
      puVar8 = InitializeScsiSrb(plVar3,puVar4,piVar5,(-(uint)bVar6 & 0x18) + 8,5,0x6c,
                                 *(undefined1 *)(lVar2 + 0x52),*(undefined1 *)(lVar2 + 0x53),
                                 *(undefined1 *)(lVar2 + 0x54),(-bVar6 & 6U) + 10,'\0');
      if (bVar6) {
        *(undefined1 *)puVar8 = 0x9e;
        *(undefined1 *)((longlong)puVar8 + 0xd) = 0x20;
        *(byte *)((longlong)puVar8 + 1) = *(byte *)((longlong)puVar8 + 1) & 0xf0 | 0x10;
      }
      else {
        *(undefined1 *)puVar8 = 0x25;
      }
      plVar3[8] = 0;
      plVar3[9] = plVar3[4];
      ExecuteSrb(param_1,(longlong)puVar4);
      RetrieveScsiStatusAndCdbOpcode((longlong)puVar4,(undefined1 *)0x0,local_res8);
      bVar9 = *(byte *)((longlong)puVar4 + 3) & 0x3f;
      if ((bVar9 == 1) || (((bVar9 == 0x12 && (local_res8[0] != '%')) && (local_res8[0] != -0x62))))
      break;
      if (1 < uVar10) {
        return;
      }
      uVar10 = uVar10 + 1;
    }
    if (bVar6) break;
    if (*piVar5 != -1) {
      uVar10 = piVar5[1];
      uVar7 = uVar10 >> 0x18 | (uVar10 & 0xff0000) >> 8 | (uVar10 & 0xff00) << 8 | uVar10 << 0x18;
      *(uint *)(lVar2 + 0x58) = uVar7;
      uVar10 = 0x1f;
      if (uVar7 != 0) {
        for (; uVar7 >> uVar10 == 0; uVar10 = uVar10 - 1) {
        }
      }
LAB_140003460:
      *(uint *)(lVar2 + 0x5c) = uVar10 & 0xff;
      return;
    }
    bVar6 = true;
    uVar10 = 0;
  }
  uVar10 = piVar5[2];
  uVar7 = uVar10 >> 0x18 | (uVar10 & 0xff0000) >> 8 | (uVar10 & 0xff00) << 8 | uVar10 << 0x18;
  *(uint *)(lVar2 + 0x58) = uVar7;
  uVar10 = 0x1f;
  if (uVar7 != 0) {
    for (; uVar7 >> uVar10 == 0; uVar10 = uVar10 - 1) {
    }
  }
  *(byte *)(lVar2 + 0x55) = *(byte *)(lVar2 + 0x55) | 1;
  goto LAB_140003460;
}



===== IssueRequestSense @ 140003488 =====

void IssueRequestSense(longlong param_1)

{
  longlong lVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined4 *puVar4;
  longlong lVar5;
  ulonglong uVar6;
  undefined4 *puVar7;
  undefined1 uVar8;
  undefined1 uVar9;
  undefined1 uVar10;
  
  lVar1 = *(longlong *)(param_1 + 0x38);
  plVar2 = *(longlong **)(*(longlong *)(lVar1 + 0x30) + 0x138);
  KeGetRecommendedSharedDataAlignment();
  lVar3 = plVar2[5];
  puVar4 = (undefined4 *)plVar2[6];
  lVar5 = plVar2[0x44];
  if (*(char *)(lVar3 + 2) == '(') {
    uVar6 = (ulonglong)*(uint *)(lVar3 + 0x34);
    uVar8 = *(undefined1 *)(uVar6 + 8 + lVar3);
    uVar10 = *(undefined1 *)(uVar6 + 9 + lVar3);
    uVar9 = *(undefined1 *)(uVar6 + 10 + lVar3);
  }
  else {
    uVar8 = *(undefined1 *)(lVar3 + 5);
    uVar10 = *(undefined1 *)(lVar3 + 6);
    uVar9 = *(undefined1 *)(lVar3 + 7);
  }
  puVar7 = InitializeScsiSrb(plVar2,puVar4,lVar5,0x12,5,0x7c,uVar8,uVar10,uVar9,6,'\0');
  plVar2[8] = 0;
  plVar2[9] = (ulonglong)(uint)((int)lVar5 - *(int *)(lVar1 + 0x50)) + plVar2[3];
  *(undefined1 *)puVar7 = 3;
  *(undefined1 *)(puVar7 + 1) = 0x12;
  ExecuteSrb(param_1,(longlong)puVar4);
  return;
}



===== MarkHiberBootPhaseForAdapter @ 140003574 =====

void MarkHiberBootPhaseForAdapter(longlong param_1)

{
  undefined8 *puVar1;
  
  if (*(longlong *)(param_1 + 0x18) != 0) {
    PoSetHiberRange(0,0x10000,*(longlong *)(param_1 + 0x18),1,0x74707344);
  }
  PoSetHiberRange(0,0x10000,*(undefined8 *)(param_1 + 0x38),*(undefined4 *)(param_1 + 0x30),
                  0x74707344);
  if (*(longlong *)(param_1 + 0x128) != 0) {
    PoSetHiberRange(0,0x10000,*(longlong *)(param_1 + 0x128),8,0x74707344);
    for (puVar1 = *(undefined8 **)(param_1 + 0x128); puVar1 != (undefined8 *)0x0;
        puVar1 = (undefined8 *)*puVar1) {
      PoSetHiberRange(0,0x10000,puVar1,8,0x74707344);
    }
  }
  if (*(uint *)(param_1 + 0x7c) != 0) {
    PoSetHiberRange(0,0x10000,*(undefined8 *)(param_1 + 0x80),
                    (ulonglong)*(uint *)(param_1 + 0x7c) << 4,0x74707344);
  }
  if (((0xc3 < *(uint *)(param_1 + 0x48)) && (*(int *)(param_1 + 0x108) != 0)) &&
     (*(int *)(param_1 + 0x100) != 0)) {
    PoSetHiberRange(0,0x10000,*(undefined8 *)(param_1 + 0xf0),*(int *)(param_1 + 0x100),0x74707344);
  }
  return;
}



===== NvmeIceDumpMarkHiberMemory @ 1400036b0 =====

void NvmeIceDumpMarkHiberMemory(undefined8 param_1,undefined8 param_2)

{
  PoSetHiberRange(0,0x10000,param_1,param_2,0x65634944);
  return;
}



===== PrepareAdapter @ 1400036e4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 PrepareAdapter(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  uint *puVar2;
  longlong lVar3;
  undefined8 *puVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  longlong *plVar8;
  ulonglong uVar9;
  undefined1 uVar10;
  longlong lVar11;
  undefined8 *puVar12;
  undefined8 uVar13;
  longlong lVar14;
  longlong lVar15;
  undefined1 auStack_d8 [32];
  uint *local_b8;
  uint *local_b0;
  uint *local_a8;
  byte local_98;
  undefined1 local_97;
  undefined1 local_96 [2];
  uint local_94;
  int local_90;
  undefined4 local_8c;
  longlong local_88;
  char local_80 [8];
  int *local_78;
  longlong local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  uint local_58 [8];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_d8;
  lVar3 = *(longlong *)(param_1 + 0x30);
  local_94 = 0;
  local_58[0] = 0;
  local_58[1] = 0;
  local_58[2] = 0;
  local_58[3] = 0;
  local_96[0] = 0;
  local_58[4] = 0;
  local_58[5] = 0;
  local_58[6] = 0;
  local_58[7] = 0;
  builtin_strncpy(local_80,"dump=1;",8);
  local_97 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = *(int **)(*(longlong *)(param_1 + 0x38) + 0x48);
  local_88 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 0x70);
  iVar7 = *local_78;
  local_70 = param_2;
  if (iVar7 == 0xb0) {
    local_98 = 1;
  }
  else if (iVar7 == 0x88) {
    local_98 = 0;
  }
  else {
    if (iVar7 != 0xd0) {
      uVar13 = 0xc0000059;
      goto LAB_140003cc8;
    }
    local_98 = *(byte *)(local_78 + 0x2e) & 1;
  }
  if (*(int *)(local_88 + 8) == 3) {
    lVar11 = *(longlong *)(lVar3 + 0x138);
    local_68 = *(undefined8 *)(lVar11 + 600);
    uStack_60 = *(undefined8 *)(lVar11 + 0x260);
    local_97 = *(undefined1 *)(lVar11 + 0x2b5);
  }
  memset(*(void **)(lVar3 + 0x38),0,(ulonglong)*(uint *)(lVar3 + 0x30));
  puVar4 = *(undefined8 **)(lVar3 + 0x38);
  plVar1 = puVar4 + 3;
  *plVar1 = param_1;
  puVar4[4] = 0;
  puVar4[0xd] = 0;
  if (*(int *)(local_88 + 8) == 3) {
    *(undefined4 *)(puVar4 + 0x4e) = (undefined4)local_68;
    *(undefined4 *)((longlong)puVar4 + 0x274) = local_68._4_4_;
    *(undefined4 *)(puVar4 + 0x4f) = (undefined4)uStack_60;
    *(undefined4 *)((longlong)puVar4 + 0x27c) = uStack_60._4_4_;
    *(undefined1 *)((longlong)puVar4 + 0x2cd) = local_97;
  }
  if ((*(uint *)(lVar3 + 0x48) < 0xd1) || (*(char *)(lVar3 + 0xaa) != '\x01')) {
    puVar12 = puVar4 + 0x74;
    uVar6 = 0x3f8;
  }
  else {
    local_90 = 0x4e0;
    local_8c = 0xffff;
    lVar11 = 0xb8;
    if (*(short *)(lVar3 + 0x130) != -1) {
      lVar11 = 0xe0;
    }
    puVar12 = (undefined8 *)((longlong)puVar4 + lVar11 + 0x348);
    uVar6 = 0x4b8;
    if (*(short *)(lVar3 + 0x130) != -1) {
      uVar6 = 0x4e0;
    }
  }
  puVar2 = (uint *)(puVar4 + 2);
  *puVar2 = uVar6;
  puVar4[8] = puVar4 + 0x69;
  puVar4[9] = puVar12;
  *puVar4 = 0;
  puVar4[5] = (ulonglong)*puVar2 + (longlong)puVar4;
  *(uint *)((ulonglong)*puVar2 + (longlong)puVar4 + 0x10) = *(int *)(lVar3 + 0x30) - *puVar2;
  *(undefined8 *)puVar4[5] = 0;
  local_90 = KeGetRecommendedSharedDataAlignment();
  puVar12 = (undefined8 *)(param_1 + 0x50);
  lVar11 = 2;
  do {
    memset((void *)*puVar12,0,(ulonglong)*(uint *)(param_1 + 0x48));
    piVar5 = local_78;
    puVar12 = puVar12 + 1;
    lVar11 = lVar11 + -1;
  } while (lVar11 != 0);
  puVar2 = (uint *)(lVar3 + 0x48);
  if (*Mm64BitPhysicalAddress_exref != (code)0x0) {
    *(undefined1 *)(lVar3 + 0xd8) = 0x80;
  }
  *(undefined2 *)((longlong)puVar4 + 0x2cb) = 0;
  *(undefined4 *)(puVar4 + 0xe) = 0xffffffff;
  plVar8 = AllocatePool((longlong)plVar1,local_78[0x10] + 0x10,
                        (byte)((uint)local_78[0x2e] >> 10) & 1);
  puVar4[4] = plVar8;
  if (plVar8 == (longlong *)0x0) {
LAB_14000391e:
    uVar13 = 0xc000009a;
    goto LAB_140003cc8;
  }
  *plVar8 = (longlong)plVar1;
  if (piVar5[0x11] != 0) {
    *(int *)(puVar4 + 0x5a) = piVar5[0x11];
    plVar8 = AllocatePool((longlong)plVar1,piVar5[0x11],'\0');
    puVar4[0xd] = plVar8;
    if (plVar8 == (longlong *)0x0) goto LAB_14000391e;
    memset(plVar8,0,(ulonglong)*(uint *)(puVar4 + 0x5a));
  }
  if ((*(int *)(lVar3 + 0x50) == piVar5[1]) && (*(int *)(lVar3 + 0x7c) == piVar5[0x13])) {
    if ((0xd0 < *puVar2) && (4000000 < *(uint *)(lVar3 + 0x120))) {
      *(undefined4 *)(lVar3 + 0x120) = 4000000;
    }
    if (((*piVar5 == 0xb0) || (*piVar5 == 0x88)) && (*(char *)(lVar3 + 0xaa) == '\x01')) {
      *(undefined2 *)(lVar3 + 0xaa) = 0;
    }
    *(undefined4 *)((longlong)puVar4 + 0x24c) = 0x18;
    uVar6 = GetDeviceTransferSize((longlong)puVar2);
    *(uint *)(puVar4 + 0x4a) = uVar6;
    puVar4[0x48] = *(undefined8 *)(param_1 + 0x50);
    *(int *)(puVar4 + 0x49) = piVar5[0x12];
    uVar6 = local_90 + -1 + (piVar5[0x12] + 7U & 0xfffffff8) & ~(local_90 - 1U);
    puVar4[0x47] = (ulonglong)uVar6 + *(longlong *)(param_1 + 0x50);
    uVar6 = uVar6 + (local_90 + 0x11U & ~(local_90 - 1U)) + 7 & 0xfffffff8;
    puVar4[0x45] = (ulonglong)uVar6 + *(longlong *)(param_1 + 0x50);
    *(uint *)(puVar4 + 0x46) = *(int *)(param_1 + 0x48) - uVar6;
    if (*(longlong *)(param_1 + 0x40) == 0) {
LAB_140003b42:
      uVar10 = 0;
    }
    else {
      if (*(char *)((longlong)puVar4 + 0x2cd) == '\0') {
        uVar6 = *(uint *)(param_1 + 0x48);
        puVar4[0x4e] = 0;
        local_b8 = &local_94;
        uVar6 = uVar6 >> 0xc;
        iVar7 = HalDmaAllocateCrashDumpRegistersEx(*(undefined8 *)(param_1 + 0x40),uVar6,0);
        if (iVar7 < 0) {
          local_b8 = (uint *)(ulonglong)local_94;
                    /* WARNING: Subroutine does not return */
          KeBugCheckEx(0x2c,0x80000002,(longlong)iVar7,uVar6);
        }
        uVar9 = Feature_CrashDumpOneMBTransferSize__private_IsEnabledNoReportingNoInline();
        if ((int)uVar9 == 0) {
          uVar6 = *(uint *)(puVar4 + 0x4a) >> 0xc;
        }
        local_94 = 0;
        puVar4[0x4f] = 0;
        local_b8 = &local_94;
        iVar7 = HalDmaAllocateCrashDumpRegistersEx(*(undefined8 *)(param_1 + 0x40),uVar6,1);
        if (iVar7 < 0) {
          local_b8 = (uint *)(ulonglong)local_94;
                    /* WARNING: Subroutine does not return */
          KeBugCheckEx(0x2c,0x80000003,(longlong)iVar7,uVar6);
        }
        *(undefined1 *)((longlong)puVar4 + 0x2cd) = 1;
      }
      if ((*(char *)((longlong)piVar5 + 0x59) == '\0') ||
         (uVar10 = 1, *(char *)(lVar3 + 0x9a) == '\0')) goto LAB_140003b42;
    }
    lVar15 = -1;
    *(undefined1 *)((longlong)puVar4 + 0x2c9) = uVar10;
    puVar12 = puVar4 + 6;
    lVar11 = 2;
    do {
      lVar14 = lVar11;
      *puVar12 = *(undefined8 *)((param_1 - (longlong)plVar1) + 0x48 + (longlong)puVar12);
      puVar12 = puVar12 + 1;
      lVar11 = lVar14 + -1;
    } while (lVar11 != 0);
    if (199 < *puVar2) {
      if (*(int *)(local_88 + 4) == 1) {
        iVar7 = (int)lVar14 + 2;
        if (*(int *)(local_88 + 8) != iVar7) {
          iVar7 = 1;
        }
        uVar10 = (undefined1)iVar7;
      }
      else {
        uVar10 = 2;
        if (*(int *)(local_88 + 8) == 3) {
          uVar10 = 4;
        }
      }
      *(undefined1 *)(lVar3 + 0x10d) = uVar10;
    }
    uVar9 = Feature_SteelixInlineNvmeCryptoEngine__private_IsEnabledNoReportingNoInline();
    if (((int)uVar9 != 0) && (*(longlong *)(local_70 + 0x60) != 0)) {
      *(undefined1 *)((longlong)puVar4 + 0x344) = 1;
    }
    do {
      lVar11 = lVar15;
      lVar15 = lVar11 + 1;
    } while (local_80[lVar11 + 1] != '\0');
    memmove(local_58,local_80,lVar11 + 2);
    local_b0 = (uint *)local_96;
    if (local_98 == 0) {
      local_b8 = puVar2;
      iVar7 = (**(code **)(piVar5 + 8))(puVar4[4] + 0x10,0,0,local_58);
    }
    else {
      local_b8 = local_58;
      local_a8 = local_b0;
      local_b0 = puVar2;
      iVar7 = (**(code **)(piVar5 + 8))(puVar4[4] + 0x10,0,0,0);
    }
    if (iVar7 == 1) {
      *(undefined1 *)(puVar4 + 0x59) = *(undefined1 *)(lVar3 + 0xa1);
      iVar7 = *(int *)(lVar3 + 100);
      *(int *)((longlong)puVar4 + 0x254) = iVar7;
      if (*(char *)((longlong)piVar5 + 0x5d) != '\0') {
        *(uint *)(puVar4 + 0x4b) = *(uint *)(puVar4 + 0x4b) | 2;
      }
      *(undefined1 *)(puVar4 + 0x4c) = *(undefined1 *)((longlong)piVar5 + 0x5a);
      *(undefined1 *)((longlong)puVar4 + 0x261) = *(undefined1 *)(lVar3 + 0x9c);
      *(undefined4 *)((longlong)puVar4 + 0x25c) = *(undefined4 *)(lVar3 + 0x78);
      if (iVar7 == 0) {
        uVar6 = (*(int *)(puVar4 + 0x4a) + 0xfffU & 0xfffff000) + 1;
        *(uint *)((longlong)puVar4 + 0x254) = uVar6;
        if (*(uint *)(lVar3 + 100) < uVar6) {
          *(uint *)((longlong)puVar4 + 0x254) = *(uint *)(lVar3 + 100);
        }
      }
      *(ushort *)(lVar3 + 0x132) = *(ushort *)(lVar3 + 0x132) | 1;
      *(longlong **)(lVar3 + 0x138) = plVar1;
      return 0;
    }
  }
  uVar13 = 0xc000000e;
LAB_140003cc8:
  FreeAdapterResources(param_1);
  return uVar13;
}



===== ResetBus @ 140003d08 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined1 ResetBus(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  code *pcVar4;
  undefined1 uVar5;
  int iVar6;
  
  lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 0x30);
  lVar2 = *(longlong *)(lVar1 + 0x138);
  lVar3 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x38) + 0x38) + 0x48);
  uVar5 = (**(code **)(lVar3 + 0x28))
                    (*(longlong *)(lVar2 + 8) + 0x10,
                     *(undefined1 *)(*(longlong *)(param_1 + 0x30) + 0x52));
  if (*(uint *)(lVar1 + 0x48) < 0xd1) {
    iVar6 = 4000000;
  }
  else {
    iVar6 = *(int *)(lVar1 + 0x120);
    if (iVar6 == 0) goto LAB_140003d75;
  }
  KeStallExecutionProcessor(iVar6);
LAB_140003d75:
  pcVar4 = *(code **)(lVar3 + 0x18);
  if (pcVar4 != (code *)0x0) {
    (*pcVar4)(*(longlong *)(lVar2 + 8) + 0x10);
  }
  return uVar5;
}



===== RetrieveScsiStatusAndCdbOpcode @ 140003dac =====

void RetrieveScsiStatusAndCdbOpcode(longlong param_1,undefined1 *param_2,undefined1 *param_3)

{
  bool bVar1;
  undefined1 uVar2;
  int *piVar3;
  uint uVar4;
  ulonglong uVar5;
  
  bVar1 = false;
  if (param_1 != 0) {
    if (param_2 != (undefined1 *)0x0) {
      *param_2 = 0;
    }
    if (param_3 != (undefined1 *)0x0) {
      *param_3 = 0;
    }
    if (*(char *)(param_1 + 2) == '(') {
      uVar5 = 0;
      if (*(int *)(param_1 + 0x38) != 0) {
        do {
          uVar4 = *(uint *)(param_1 + 0x78 + uVar5 * 4);
          if ((0x7f < uVar4) && (uVar4 <= *(uint *)(param_1 + 0x10))) {
            piVar3 = (int *)((ulonglong)uVar4 + param_1);
            if (*piVar3 == 0x40) {
              if (param_2 != (undefined1 *)0x0) {
                bVar1 = true;
                *param_2 = (char)piVar3[2];
              }
              if ((param_3 != (undefined1 *)0x0) && (*(char *)((longlong)piVar3 + 10) != '\0')) {
                uVar2 = (undefined1)piVar3[6];
                goto LAB_140003e36;
              }
            }
            if (bVar1) {
              return;
            }
          }
          uVar4 = (int)uVar5 + 1;
          uVar5 = (ulonglong)uVar4;
          if (*(uint *)(param_1 + 0x38) <= uVar4) {
            return;
          }
        } while( true );
      }
    }
    else {
      if (param_2 != (undefined1 *)0x0) {
        *param_2 = *(undefined1 *)(param_1 + 4);
      }
      if (param_3 != (undefined1 *)0x0) {
        uVar2 = *(undefined1 *)(param_1 + 0x48);
LAB_140003e36:
        *param_3 = uVar2;
      }
    }
  }
  return;
}



===== SetupIoRequest @ 140003e44 =====

int SetupIoRequest(longlong param_1,ulonglong *param_2,longlong param_3,char param_4,
                  longlong param_5)

{
  longlong lVar1;
  longlong *plVar2;
  longlong lVar3;
  char cVar7;
  char cVar6;
  char cVar5;
  char cVar4;
  int iVar8;
  ulonglong uVar9;
  char *pcVar10;
  ulonglong uVar11;
  uint uVar12;
  undefined1 uVar13;
  char local_res20;
  
  lVar1 = *(longlong *)(param_1 + 0x30);
  iVar8 = 0;
  plVar2 = *(longlong **)(*(longlong *)(*(longlong *)(param_1 + 0x38) + 0x30) + 0x138);
  if ((param_4 - 0x28U & 0xfd) == 0) {
    lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x70);
    if (((*(int *)(lVar3 + 4) != 2) || (*(int *)(lVar3 + 8) != 2)) ||
       (local_res20 = '\x01', param_4 != '*')) {
      local_res20 = '\0';
    }
    *(ulonglong *)(param_3 + 0x20) = *(ulonglong *)(param_3 + 0x20) & 0xfffffffffffff000;
    *(undefined4 *)(plVar2 + 0xc) = *(undefined4 *)(param_3 + 0x28);
    plVar2[8] = param_3;
    if ((char)plVar2[0x56] == '\0') {
      uVar11 = (ulonglong)*(uint *)(param_3 + 0x2c) + *(longlong *)(param_3 + 0x20);
    }
    else {
      uVar11 = *(ulonglong *)(param_3 + 0x18);
      *(ulonglong *)(param_3 + 0x20) = uVar11 & 0xfffffffffffff000;
    }
    if (param_4 == '(') {
      uVar12 = 0x40;
    }
    else {
      uVar12 = 0;
      if (param_4 == '*') {
        uVar12 = 0x80;
      }
    }
    if ((*(byte *)(lVar1 + 0x55) & 1) == 0) {
      if (param_4 == '(') {
        uVar13 = 10;
      }
      else {
        uVar13 = 0;
        if (param_4 == '*') {
          uVar13 = 10;
        }
      }
    }
    else if ((param_4 == '(') || (uVar13 = 0, param_4 == '*')) {
      uVar13 = 0x10;
    }
    uVar9 = Feature_SteelixInlineNvmeCryptoEngine__private_IsEnabledNoReportingNoInline();
    if (((int)uVar9 != 0) &&
       (iVar8 = DspAcquireCryptoKeyResources(param_5,(longlong)plVar2,lVar1), iVar8 < 0)) {
      return iVar8;
    }
    pcVar10 = (char *)InitializeScsiSrb(plVar2,(undefined4 *)plVar2[5],uVar11,
                                        *(undefined4 *)(param_3 + 0x28),10,uVar12 | 0x2c,
                                        *(undefined1 *)(lVar1 + 0x52),*(undefined1 *)(lVar1 + 0x53),
                                        *(undefined1 *)(lVar1 + 0x54),uVar13,local_res20);
    uVar11 = *param_2 / (ulonglong)*(uint *)(lVar1 + 0x58);
    uVar12 = *(uint *)(param_3 + 0x28) >> ((byte)*(undefined4 *)(lVar1 + 0x5c) & 0x1f);
    cVar4 = (char)(uVar11 >> 8);
    cVar5 = (char)(uVar11 >> 0x10);
    cVar6 = (char)(uVar11 >> 0x18);
    cVar7 = (char)(uVar12 >> 8);
    if ((*(byte *)(lVar1 + 0x55) & 1) == 0) {
      if (uVar11 < 0x100000000) {
        *pcVar10 = param_4;
        pcVar10[2] = cVar6;
        pcVar10[3] = cVar5;
        pcVar10[4] = cVar4;
        pcVar10[7] = cVar7;
        pcVar10[5] = (char)uVar11;
        pcVar10[8] = (char)uVar12;
      }
      else {
        iVar8 = -0x3fffffff;
      }
    }
    else {
      if (param_4 == '(') {
        *pcVar10 = -0x78;
      }
      else if (param_4 == '*') {
        *pcVar10 = -0x76;
      }
      pcVar10[8] = cVar4;
      pcVar10[7] = cVar5;
      pcVar10[6] = cVar6;
      pcVar10[5] = (char)(uVar11 >> 0x20);
      pcVar10[4] = (char)(uVar11 >> 0x28);
      pcVar10[3] = (char)(uVar11 >> 0x30);
      pcVar10[0xc] = cVar7;
      pcVar10[9] = (char)uVar11;
      pcVar10[0xd] = (char)uVar12;
      pcVar10[10] = (char)(uVar12 >> 0x18);
      pcVar10[2] = (char)(uVar11 >> 0x38);
      pcVar10[0xb] = (char)(uVar12 >> 0x10);
    }
  }
  else {
    iVar8 = -0x3ffffffe;
  }
  return iVar8;
}



===== StartDisk @ 1400040c4 =====

void StartDisk(longlong param_1)

{
  longlong lVar1;
  longlong *plVar2;
  undefined4 *puVar3;
  undefined8 *puVar4;
  uint uVar5;
  
  lVar1 = *(longlong *)(param_1 + 0x30);
  uVar5 = 0;
  plVar2 = *(longlong **)(*(longlong *)(*(longlong *)(param_1 + 0x38) + 0x30) + 0x138);
  puVar3 = (undefined4 *)plVar2[6];
  do {
    puVar4 = (undefined8 *)
             InitializeScsiSrb(plVar2,puVar3,0,0,0x1e,0x80028,*(undefined1 *)(lVar1 + 0x52),
                               *(undefined1 *)(lVar1 + 0x53),*(undefined1 *)(lVar1 + 0x54),6,'\0');
    *puVar4 = 0;
    puVar4[1] = 0;
    *(byte *)((longlong)puVar4 + 4) = *(byte *)((longlong)puVar4 + 4) | 1;
    *(undefined1 *)puVar4 = 0x1b;
    ExecuteSrb(param_1,(longlong)puVar3);
    if (*(char *)((longlong)puVar3 + 3) == '\x01') {
      return;
    }
    uVar5 = uVar5 + 1;
  } while (uVar5 < 4);
  return;
}



===== StartIo @ 140004184 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void StartIo(longlong *param_1,longlong param_2)

{
  longlong lVar1;
  code *pcVar2;
  char cVar3;
  uint uVar4;
  undefined4 uVar5;
  
  lVar1 = *(longlong *)(*(longlong *)(*param_1 + 0x38) + 0x48);
  *(undefined1 *)((longlong)param_1 + 0x2b3) = 1;
  if (*(char *)(param_2 + 2) == '(') {
    uVar4 = *(uint *)(param_2 + 0x18);
    uVar5 = *(undefined4 *)(param_2 + 0x28);
    *(longlong *)(param_2 + 0x68) = param_1[0x45];
  }
  else {
    uVar4 = *(uint *)(param_2 + 0xc);
    uVar5 = *(undefined4 *)(param_2 + 0x14);
    *(longlong *)(param_2 + 0x38) = param_1[0x45];
  }
  if (((uVar4 & 0xc0) != 0) && (*(char *)((longlong)param_1 + 0x2b1) != '\0')) {
    AllocateScatterGatherList(param_1,param_2);
  }
  *(undefined4 *)(param_1 + 0xb) = uVar5;
  pcVar2 = *(code **)(lVar1 + 0x80);
  if ((pcVar2 == (code *)0x0) || (cVar3 = (*pcVar2)(param_1[1] + 0x10,param_2), cVar3 != '\0')) {
    (**(code **)(lVar1 + 0x10))(param_1[1] + 0x10,param_2);
    return;
  }
  return;
}



===== StorPortAllocateRegistryBuffer @ 140004240 =====

undefined8 StorPortAllocateRegistryBuffer(void)

{
                    /* 0x4240  3  StorPortAllocateRegistryBuffer
                       0x4240  45  StorPortSetBusDataByOffset */
  return 0;
}



===== StorPortBusy @ 140004250 =====

undefined1 StorPortBusy(void)

{
                    /* 0x4250  4  StorPortBusy
                       0x4250  8  StorPortDeviceBusy
                       0x4250  9  StorPortDeviceReady
                       0x4250  40  StorPortReady
                       0x4250  43  StorPortResume
                       0x4250  44  StorPortResumeDevice
                       0x4250  46  StorPortSetDeviceQueueDepth
                       0x4250  49  StorPortValidateRange */
  return 1;
}



===== StorPortCompleteRequest @ 140004260 =====

void StorPortCompleteRequest
               (longlong param_1,undefined8 param_2,undefined8 param_3,int param_4,
               undefined1 param_5)

{
  longlong lVar1;
  longlong lVar2;
  
                    /* 0x4260  5  StorPortCompleteRequest */
  if (*(char *)(*(longlong *)(param_1 + -0x10) + 0x2b3) != '\0') {
    lVar1 = *(longlong *)(*(longlong *)(param_1 + -0x10) + 0x28);
    *(undefined1 *)(lVar1 + 3) = param_5;
    if (*(char *)(lVar1 + 2) == '(') {
      *(undefined4 *)(lVar1 + 0x3c) = 0;
      lVar2 = *(longlong *)(lVar1 + 0x70);
    }
    else {
      *(undefined4 *)(lVar1 + 0x10) = 0;
      lVar2 = *(longlong *)(lVar1 + 0x28);
    }
    StorPortNotification(0,param_1,lVar1,param_4);
    if (lVar2 != 0) {
      *(undefined1 *)(lVar2 + 3) = param_5;
      if (*(char *)(lVar2 + 2) == '(') {
        *(undefined4 *)(lVar2 + 0x3c) = 0;
      }
      else {
        *(undefined4 *)(lVar2 + 0x10) = 0;
      }
      StorPortNotification(0,param_1,lVar2,param_4);
    }
  }
  return;
}



===== StorPortConvertUlongToPhysicalAddress @ 1400042f0 =====

undefined8 StorPortConvertUlongToPhysicalAddress(undefined8 param_1)

{
                    /* 0x42f0  6  StorPortConvertUlongToPhysicalAddress */
  return param_1;
}



===== StorPortDebugPrint @ 140004300 =====

void StorPortDebugPrint(void)

{
                    /* 0x4300  7  StorPortDebugPrint */
  return;
}



===== StorPortExtendedFunction @ 140004320 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong StorPortExtendedFunction
                    (int param_1,longlong param_2,PSLIST_HEADER param_3,undefined8 *param_4,
                    undefined8 *param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,
                    undefined8 param_9)

{
  code *pcVar1;
  undefined2 uVar2;
  int iVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  longlong lVar6;
  int local_res18;
  uint local_res20;
  
                    /* 0x4320  10  StorPortExtendedFunction */
  if (param_1 < 0x2e) {
    if (param_1 != 0x2d) {
      if (param_1 == 0x23) {
        InitializeSListHead(param_3);
        return 0;
      }
      if (param_1 == 0x24) {
        uVar4 = ExpInterlockedFlushSList(param_3);
        param_5 = param_4;
      }
      else if (param_1 == 0x25) {
        uVar4 = ExpInterlockedPopEntrySList(param_3);
        param_5 = param_4;
      }
      else {
        if (param_1 != 0x26) {
          if (param_1 == 0x27) {
            uVar2 = ExQueryDepthSList(param_3);
            *(undefined2 *)param_4 = uVar2;
            return 0;
          }
          return 0xc1000002;
        }
        uVar4 = ExpInterlockedPushEntrySList(param_3,param_4);
      }
      *param_5 = uVar4;
      return 0;
    }
    if (((ulonglong)param_5 & 0xfffffffe) == 0) {
      PoSetHiberRange(0,(((uint)param_5 & 1) + 4) * 0x4000,param_3,param_4,0x706d7344);
      return 0;
    }
    return 0xc1000006;
  }
  local_res18 = (int)param_3;
  if (param_1 == 0x51) {
    KeStallExecutionProcessor((ulonglong)param_3 & 0xffffffff);
    return 0;
  }
  if (param_1 == 0x61) {
    uVar5 = Feature_SteelixInlineNvmeCryptoEngine__private_IsEnabledNoReportingNoInline();
    if ((int)uVar5 != 0) {
      if (param_4 == (undefined8 *)0x0) {
        return 0xc1000006;
      }
      if (local_res18 == 1) {
        *(bool *)param_4 = *(char *)(*(longlong *)(param_2 + -0x10) + 0x32c) != '\0';
        return 0;
      }
    }
  }
  else if (param_1 == 0x7e) {
    uVar5 = Feature_SteelixInlineNvmeCryptoEngine__private_IsEnabledNoReportingNoInline();
    if ((int)uVar5 != 0) {
      lVar6 = *(longlong *)(param_2 + -0x10);
      local_res20 = (uint)param_4;
      param_4 = (undefined8 *)0x0;
      uVar4 = param_6;
      param_9 = param_8;
LAB_140004547:
      uVar5 = DspNvmeIceIoStart(lVar6,param_7,(longlong)param_4,local_res20,(uint)param_5,uVar4,
                                param_7,param_9);
      return uVar5 & 0xffffffff;
    }
  }
  else if (param_1 == 0x7f) {
    uVar5 = Feature_SteelixInlineNvmeCryptoEngine__private_IsEnabledNoReportingNoInline();
    if ((int)uVar5 != 0) {
      lVar6 = *(longlong *)(param_2 + -0x10);
      iVar3 = 0;
      if (*(longlong *)(lVar6 + 0x318) == 0) {
        return 0;
      }
      pcVar1 = *(code **)(*(longlong *)(lVar6 + 0x2e0) + 0x50);
      if (pcVar1 != (code *)0x0) {
        iVar3 = (*pcVar1)(*(undefined8 *)(*(longlong *)(lVar6 + 0x2e0) + 8),
                          *(undefined8 *)(lVar6 + 800));
      }
      *(undefined8 *)(lVar6 + 800) = 0;
      if (iVar3 != 0) {
                    /* WARNING: Subroutine does not return */
        KeBugCheckEx(0x2c,0x80000004,1,0,iVar3);
      }
      return 0;
    }
  }
  else if ((param_1 == 0x86) &&
          (uVar5 = Feature_SteelixInlineNvmeCryptoEngine__private_IsEnabledNoReportingNoInline(),
          (int)uVar5 != 0)) {
    lVar6 = *(longlong *)(param_2 + -0x10);
    local_res20 = (uint)param_5;
    uVar4 = param_7;
    param_7 = param_8;
    param_5._0_4_ = (uint)param_6;
    goto LAB_140004547;
  }
  return 0xc1000002;
}



===== _guard_check_icall @ 1400045b0 =====

void _guard_check_icall(void)

{
                    /* 0x45b0  11  StorPortFreeDeviceBase
                       0x45b0  12  StorPortFreeRegistryBuffer
                       0x45b0  22  StorPortLogError */
  return;
}



===== StorPortGetBusData @ 1400045c0 =====

undefined4
StorPortGetBusData(undefined8 param_1,int param_2,undefined4 param_3,undefined4 param_4,
                  undefined8 param_5,undefined4 param_6)

{
  undefined4 uVar1;
  
                    /* 0x45c0  13  StorPortGetBusData */
  uVar1 = 0;
  if (param_2 == 4) {
    uVar1 = HalGetBusDataByOffset(4,param_3,param_4,param_5,0,param_6);
  }
  return uVar1;
}



===== StorPortGetDeviceBase @ 140004610 =====

longlong StorPortGetDeviceBase
                   (longlong param_1,undefined4 param_2,int param_3,longlong param_4,int param_5,
                   byte param_6)

{
  undefined8 *puVar1;
  char cVar2;
  longlong lVar3;
  longlong local_res8;
  
                    /* 0x4610  14  StorPortGetDeviceBase */
  _param_6 = (uint)param_6;
  local_res8 = 0;
  puVar1 = *(undefined8 **)(*(longlong *)(**(longlong **)(param_1 + -0x10) + 0x30) + 0x128);
  cVar2 = HalTranslateBusAddress(param_2,param_3,param_4,&param_6,&local_res8);
  lVar3 = 0;
  if (cVar2 != '\0') {
    if (_param_6 == 0) {
      for (; puVar1 != (undefined8 *)0x0; puVar1 = (undefined8 *)*puVar1) {
        if (((param_3 == *(int *)(puVar1 + 4)) && (param_5 == *(int *)(puVar1 + 2))) &&
           (param_4 == puVar1[3])) {
          return puVar1[1];
        }
      }
    }
    else {
      lVar3 = local_res8;
    }
  }
  return lVar3;
}



===== StorPortGetLogicalUnit @ 1400046d0 =====

undefined8 StorPortGetLogicalUnit(longlong param_1)

{
                    /* 0x46d0  15  StorPortGetLogicalUnit */
  return *(undefined8 *)(*(longlong *)(param_1 + -0x10) + 0x50);
}



===== StorPortGetPhysicalAddress @ 1400046e0 =====

longlong StorPortGetPhysicalAddress
                   (longlong param_1,longlong param_2,ulonglong param_3,int *param_4)

{
  uint *puVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong lVar4;
  uint uVar5;
  int iVar6;
  ulonglong uVar7;
  longlong *plVar8;
  longlong *plVar9;
  
                    /* 0x46e0  16  StorPortGetPhysicalAddress */
  plVar2 = *(longlong **)(param_1 + -0x10);
  lVar3 = *plVar2;
  uVar5 = (uint)param_3;
  if (param_2 != 0) {
    if (*(char *)(param_2 + 2) == '(') {
      uVar7 = *(ulonglong *)(param_2 + 0x68);
    }
    else {
      uVar7 = *(ulonglong *)(param_2 + 0x38);
    }
    if ((param_3 < uVar7) || (*(uint *)(plVar2 + 0x46) + uVar7 <= param_3)) {
      if (*(char *)((longlong)plVar2 + 0x2b1) != '\0') {
        plVar9 = plVar2 + 0xf;
        if (*(char *)(param_2 + 2) == '(') {
          iVar6 = *(int *)(param_2 + 0x40);
        }
        else {
          iVar6 = *(int *)(param_2 + 0x18);
        }
        uVar5 = uVar5 - iVar6;
        plVar8 = plVar9;
        if (*(uint *)(plVar2 + 0x10) <= uVar5) {
          do {
            uVar5 = uVar5 - (int)plVar8[1];
            plVar9 = plVar8 + 3;
            puVar1 = (uint *)(plVar8 + 4);
            plVar8 = plVar9;
          } while (*puVar1 <= uVar5);
        }
        *param_4 = (int)plVar9[1] - uVar5;
        return (ulonglong)uVar5 + *plVar9;
      }
      lVar4 = plVar2[8];
      if (lVar4 != 0) {
        if ((char)plVar2[0x56] == '\0') {
          iVar6 = *(int *)(lVar4 + 0x20);
        }
        else {
          iVar6 = *(int *)(lVar4 + 0x18);
        }
        return *(longlong *)(lVar4 + 0x30 + (ulonglong)(uVar5 - iVar6 >> 0xc) * 8) * 0x1000 +
               (ulonglong)(uVar5 & 0xfff);
      }
    }
  }
  uVar7 = *(ulonglong *)(lVar3 + 0x50);
  if ((param_3 < uVar7) || (uVar7 + *(uint *)(lVar3 + 0x48) <= param_3)) {
    uVar7 = *(ulonglong *)(lVar3 + 0x58);
    if ((param_3 < uVar7) || (uVar7 + *(uint *)(lVar3 + 0x48) <= param_3)) {
      DbgPrint("Dumpstorport: miniport attempted to get physical address for invalid VA %#p\n",
               param_3);
      DbgPrint("Dumpstorport: Valid range 1: %p through %p\n",*(longlong *)(lVar3 + 0x50),
               (ulonglong)*(uint *)(lVar3 + 0x48) + *(longlong *)(lVar3 + 0x50));
      DbgPrint("Dumpstorport: Valid ranges 2: %p through %p\n",*(longlong *)(lVar3 + 0x58),
               (ulonglong)*(uint *)(lVar3 + 0x48) + *(longlong *)(lVar3 + 0x58));
                    /* WARNING: Subroutine does not return */
      KeBugCheckEx(0x2c,0x80000001,plVar2,param_3,0);
    }
    lVar4 = plVar2[4] - uVar7;
    iVar6 = (*(uint *)(lVar3 + 0x48) - uVar5) + (int)uVar7;
  }
  else {
    lVar4 = plVar2[3] - uVar7;
    iVar6 = (*(uint *)(lVar3 + 0x48) - uVar5) + (int)uVar7;
  }
  *param_4 = iVar6;
  return lVar4 + param_3;
}



===== StorPortGetScatterGatherList @ 140004880 =====

longlong StorPortGetScatterGatherList(longlong param_1)

{
                    /* 0x4880  17  StorPortGetScatterGatherList */
  return *(longlong *)(param_1 + -0x10) + 0x68;
}



===== StorPortGetSrb @ 140004890 =====

undefined8 StorPortGetSrb(longlong param_1)

{
  undefined8 uVar1;
  
                    /* 0x4890  18  StorPortGetSrb */
  uVar1 = 0;
  if (*(char *)(*(longlong *)(param_1 + -0x10) + 0x2b3) != '\0') {
    uVar1 = *(undefined8 *)(*(longlong *)(param_1 + -0x10) + 0x28);
  }
  return uVar1;
}



===== StorPortGetUncachedExtension @ 1400048b0 =====

undefined8 StorPortGetUncachedExtension(longlong param_1,undefined8 param_2,uint param_3)

{
  undefined8 uVar1;
  
                    /* 0x48b0  19  StorPortGetUncachedExtension */
  uVar1 = 0;
  if (param_3 <= *(uint *)(*(longlong *)(param_1 + -0x10) + 0x218)) {
    uVar1 = *(undefined8 *)(*(longlong *)(param_1 + -0x10) + 0x210);
  }
  return uVar1;
}



===== StorPortGetVirtualAddress @ 1400048d0 =====

longlong StorPortGetVirtualAddress(longlong param_1,uint param_2)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  
                    /* 0x48d0  20  StorPortGetVirtualAddress */
  lVar3 = 0;
  lVar2 = **(longlong **)(param_1 + -0x10);
  uVar1 = *(uint *)(lVar2 + 0x60);
  if ((param_2 < uVar1) || (*(int *)(lVar2 + 0x48) + uVar1 <= param_2)) {
    uVar1 = *(uint *)(lVar2 + 0x68);
    if ((uVar1 <= param_2) && (param_2 < *(int *)(lVar2 + 0x48) + uVar1)) {
      lVar3 = (ulonglong)(param_2 - uVar1) + *(longlong *)(lVar2 + 0x58);
    }
  }
  else {
    lVar3 = (ulonglong)(param_2 - uVar1) + *(longlong *)(lVar2 + 0x50);
  }
  return lVar3;
}



===== StorPortInitialize @ 140004930 =====

undefined8 StorPortInitialize(undefined8 param_1,longlong param_2,uint *param_3)

{
  undefined8 *puVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  ulonglong uVar5;
  longlong lVar6;
  undefined8 *puVar7;
  undefined8 uVar8;
  
                    /* 0x4930  21  StorPortInitialize */
  uVar2 = *param_3;
  uVar8 = 0;
  if (((uVar2 == 0xd0) || (uVar2 == 0xb0)) || (uVar2 == 0x88)) {
    if (((*(longlong *)(param_3 + 2) == 0) || (*(longlong *)(param_3 + 8) == 0)) ||
       ((*(longlong *)(param_3 + 10) == 0 || (*(uint *)(param_2 + 0x44) < uVar2)))) {
      uVar8 = 0xc0000001;
    }
    else {
      *(code **)(param_2 + 0x50) = DspRead;
      *(code **)(param_2 + 0x58) = DspWrite;
      *(code **)(param_2 + 0x60) = DspFlush;
      *(code **)(param_2 + 0x68) = DspControl;
      uVar5 = Feature_SteelixInlineNvmeCryptoEngine__private_IsEnabledNoReportingNoInline();
      if ((int)uVar5 != 0) {
        *(code **)(param_2 + 0xa8) = DspWrite2;
        *(code **)(param_2 + 0xa0) = DspRead2;
      }
      memset(*(void **)(param_2 + 0x48),0,(ulonglong)*(uint *)(param_2 + 0x44));
      memmove(*(void **)(param_2 + 0x48),param_3,(ulonglong)*param_3);
      if ((*(uint *)(param_2 + 0x40) & 2) != 0) {
        lVar3 = *(longlong *)(param_2 + 0x70);
        *(code **)(param_2 + 0x18) = DspLiveControl;
        puVar1 = (undefined8 *)(lVar3 + 0x28);
        for (puVar7 = (undefined8 *)*puVar1; puVar7 != puVar1; puVar7 = (undefined8 *)*puVar7) {
          if (puVar7[6] == param_2) {
            lVar4 = puVar7[5];
            *(undefined8 *)(lVar4 + 0x18) = 0;
            *(undefined8 *)(lVar4 + 0x20) = 0;
            *(undefined8 *)(lVar4 + 0x28) = 0;
            *(undefined8 *)(lVar4 + 0x10) = 0;
            *(undefined8 *)(lVar4 + 0x128) = 0;
            *(undefined8 *)(lVar4 + 0x40) = 0;
            *(undefined4 *)(lVar4 + 0x7c) = 0;
            *(undefined8 *)(lVar4 + 0x80) = 0;
            *(undefined8 *)(lVar4 + 0x88) = 0;
            lVar6 = ExAllocatePool2(0x40,*(undefined4 *)(lVar4 + 0x30),0x44436152);
            *(longlong *)(lVar4 + 0x38) = lVar6;
            if (lVar6 == 0) {
              return 0xc000009a;
            }
          }
        }
        puVar1 = (undefined8 *)(lVar3 + 0x18);
        for (puVar7 = (undefined8 *)*puVar1; puVar7 != puVar1; puVar7 = (undefined8 *)*puVar7) {
          if (puVar7[7] == param_2) {
            lVar3 = puVar7[5];
            *(undefined8 *)(lVar3 + 0x18) = 0;
            *(undefined8 *)(lVar3 + 0x20) = 0;
            *(undefined8 *)(lVar3 + 0x28) = 0;
          }
        }
      }
    }
  }
  else {
    uVar8 = 0xc0000059;
  }
  return uVar8;
}



===== StorPortMoveMemory @ 140004af0 =====

void StorPortMoveMemory(void *param_1,void *param_2,uint param_3)

{
                    /* 0x4af0  23  StorPortMoveMemory */
  memmove(param_1,param_2,(ulonglong)param_3);
  return;
}



===== StorPortNotification @ 140004b10 =====

void StorPortNotification(int param_1,longlong param_2,longlong param_3,int param_4)

{
  longlong *plVar1;
  longlong lVar2;
  int iVar3;
  
                    /* 0x4b10  24  StorPortNotification */
  plVar1 = *(longlong **)(param_2 + -0x10);
  if (param_1 == 0) {
    if (param_3 == plVar1[5]) {
      *(undefined1 *)((longlong)plVar1 + 0x2b4) = 1;
    }
    else if (param_3 == plVar1[6]) {
      *(undefined1 *)((longlong)plVar1 + 0x2b4) = 1;
      WorkHorseDpc(plVar1);
    }
  }
  else if ((param_1 == 1) || (param_1 == 2)) {
    *(uint *)(plVar1 + 0x4a) = *(uint *)(plVar1 + 0x4a) | 1;
  }
  else if (param_1 == 3) {
    if (*(uint *)(*(longlong *)(*plVar1 + 0x30) + 0x48) < 0xd1) {
      iVar3 = 4000000;
    }
    else {
      iVar3 = *(int *)(*(longlong *)(*plVar1 + 0x30) + 0x120);
      if (iVar3 == 0) goto LAB_140004c52;
    }
    KeStallExecutionProcessor(iVar3);
  }
  else {
    if (param_1 == 4) {
      *(uint *)((longlong)plVar1 + 0x24c) = *(uint *)((longlong)plVar1 + 0x24c) | 0x10;
    }
    else {
      if (param_1 != 5) {
        if (param_1 == 6) {
          plVar1[0x55] = param_3;
          *(int *)((longlong)plVar1 + 700) = param_4;
          if (param_4 != 0) {
            lVar2 = KeQueryPerformanceCounter(0);
            plVar1[0x59] = lVar2;
            plVar1[0x5a] = ((ulonglong)*(uint *)((longlong)plVar1 + 700) * g_Frequency) / 1000000;
            *(uint *)((longlong)plVar1 + 700) = (*(uint *)((longlong)plVar1 + 700) + 4) / 5;
          }
        }
        goto LAB_140004c52;
      }
      *(uint *)((longlong)plVar1 + 0x24c) = *(uint *)((longlong)plVar1 + 0x24c) | 0x60;
    }
    plVar1[0x54] = param_3;
  }
LAB_140004c52:
  WorkHorseDpc(plVar1);
  return;
}



===== StorPortPause @ 140004c70 =====

undefined1 StorPortPause(undefined8 param_1,int param_2)

{
                    /* 0x4c70  25  StorPortPause */
  KeStallExecutionProcessor(param_2 * 1000000);
  return 1;
}



===== StorPortPauseDevice @ 140004ca0 =====

undefined1 StorPortPauseDevice(void)

{
  int in_stack_00000028;
  
                    /* 0x4ca0  26  StorPortPauseDevice */
  KeStallExecutionProcessor(in_stack_00000028 * 1000000);
  return 1;
}



===== StorPortQuerySystemTime @ 140004cd0 =====

void StorPortQuerySystemTime(undefined8 *param_1)

{
                    /* 0x4cd0  27  StorPortQuerySystemTime */
  *param_1 = 0;
  return;
}



===== StorPortReadPortBufferUchar @ 140004ce0 =====

void StorPortReadPortBufferUchar
               (undefined8 param_1,undefined2 param_2,undefined1 *param_3,uint param_4)

{
  undefined1 uVar1;
  ulonglong uVar2;
  
                    /* 0x4ce0  28  StorPortReadPortBufferUchar */
  uVar2 = (ulonglong)param_4;
  while (uVar2 != 0) {
    uVar2 = uVar2 - 1;
    uVar1 = in(param_2);
    *param_3 = uVar1;
    param_3 = param_3 + 1;
  }
  return;
}



===== StorPortReadPortBufferUlong @ 140004d00 =====

void StorPortReadPortBufferUlong
               (undefined8 param_1,undefined2 param_2,undefined4 *param_3,uint param_4)

{
  undefined4 uVar1;
  ulonglong uVar2;
  
                    /* 0x4d00  29  StorPortReadPortBufferUlong */
  uVar2 = (ulonglong)param_4;
  while (uVar2 != 0) {
    uVar2 = uVar2 - 1;
    uVar1 = in(param_2);
    *param_3 = uVar1;
    param_3 = param_3 + 1;
  }
  return;
}



===== StorPortReadPortBufferUshort @ 140004d20 =====

void StorPortReadPortBufferUshort
               (undefined8 param_1,undefined2 param_2,undefined2 *param_3,uint param_4)

{
  undefined2 uVar1;
  ulonglong uVar2;
  
                    /* 0x4d20  30  StorPortReadPortBufferUshort */
  uVar2 = (ulonglong)param_4;
  while (uVar2 != 0) {
    uVar2 = uVar2 - 1;
    uVar1 = in(param_2);
    *param_3 = uVar1;
    param_3 = param_3 + 1;
  }
  return;
}



===== StorPortReadPortUchar @ 140004d40 =====

undefined1 StorPortReadPortUchar(undefined8 param_1,undefined2 param_2)

{
  undefined1 uVar1;
  
  uVar1 = in(param_2);
  return uVar1;
}



===== StorPortReadPortUlong @ 140004d50 =====

undefined4 StorPortReadPortUlong(undefined8 param_1,undefined2 param_2)

{
  undefined4 uVar1;
  
  uVar1 = in(param_2);
  return uVar1;
}



===== StorPortReadPortUshort @ 140004d60 =====

undefined2 StorPortReadPortUshort(undefined8 param_1,undefined2 param_2)

{
  undefined2 uVar1;
  
  uVar1 = in(param_2);
  return uVar1;
}



===== StorPortReadRegisterBufferUchar @ 140004d70 =====

void StorPortReadRegisterBufferUchar
               (undefined8 param_1,undefined1 *param_2,undefined1 *param_3,uint param_4)

{
  ulonglong uVar1;
  
                    /* 0x4d70  34  StorPortReadRegisterBufferUchar */
  for (uVar1 = (ulonglong)param_4; uVar1 != 0; uVar1 = uVar1 - 1) {
    *param_3 = *param_2;
    param_2 = param_2 + 1;
    param_3 = param_3 + 1;
  }
  return;
}



===== StorPortReadRegisterBufferUlong @ 140004da0 =====

void StorPortReadRegisterBufferUlong
               (undefined8 param_1,undefined4 *param_2,undefined4 *param_3,uint param_4)

{
  ulonglong uVar1;
  
                    /* 0x4da0  35  StorPortReadRegisterBufferUlong */
  for (uVar1 = (ulonglong)param_4; uVar1 != 0; uVar1 = uVar1 - 1) {
    *param_3 = *param_2;
    param_2 = param_2 + 1;
    param_3 = param_3 + 1;
  }
  return;
}



===== StorPortReadRegisterBufferUshort @ 140004dd0 =====

void StorPortReadRegisterBufferUshort
               (undefined8 param_1,undefined2 *param_2,undefined2 *param_3,uint param_4)

{
  ulonglong uVar1;
  
                    /* 0x4dd0  36  StorPortReadRegisterBufferUshort */
  for (uVar1 = (ulonglong)param_4; uVar1 != 0; uVar1 = uVar1 - 1) {
    *param_3 = *param_2;
    param_2 = param_2 + 1;
    param_3 = param_3 + 1;
  }
  return;
}



===== StorPortReadRegisterUchar @ 140004e00 =====

undefined1 StorPortReadRegisterUchar(undefined8 param_1,undefined1 *param_2)

{
  return *param_2;
}



===== StorPortReadRegisterUlong @ 140004e10 =====

undefined4 StorPortReadRegisterUlong(undefined8 param_1,undefined4 *param_2)

{
  return *param_2;
}



===== StorPortReadRegisterUshort @ 140004e20 =====

undefined2 StorPortReadRegisterUshort(undefined8 param_1,undefined2 *param_2)

{
  return *param_2;
}



===== StorPortRegistryRead @ 140004e30 =====

undefined1 StorPortRegistryRead(void)

{
                    /* 0x4e30  41  StorPortRegistryRead
                       0x4e30  42  StorPortRegistryWrite */
  return 0;
}



===== StorPortStallExecution @ 140004e40 =====

void StorPortStallExecution(void)

{
                    /* 0x4e40  47  StorPortStallExecution */
  KeStallExecutionProcessor();
  return;
}



===== StorPortSynchronizeAccess @ 140004e60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void StorPortSynchronizeAccess(undefined8 param_1,undefined *param_2,undefined8 param_3)

{
                    /* 0x4e60  48  StorPortSynchronizeAccess */
  (*(code *)param_2)(param_1,param_3);
  return;
}



===== StorPortWritePortBufferUchar @ 140004e80 =====

void StorPortWritePortBufferUchar
               (undefined8 param_1,undefined2 param_2,undefined1 *param_3,uint param_4)

{
  ulonglong uVar1;
  
                    /* 0x4e80  50  StorPortWritePortBufferUchar */
  uVar1 = (ulonglong)param_4;
  while (uVar1 != 0) {
    uVar1 = uVar1 - 1;
    out(*param_3,param_2);
    param_3 = param_3 + 1;
  }
  return;
}



===== StorPortWritePortBufferUlong @ 140004ea0 =====

void StorPortWritePortBufferUlong
               (undefined8 param_1,undefined2 param_2,undefined4 *param_3,uint param_4)

{
  ulonglong uVar1;
  
                    /* 0x4ea0  51  StorPortWritePortBufferUlong */
  uVar1 = (ulonglong)param_4;
  while (uVar1 != 0) {
    uVar1 = uVar1 - 1;
    out(*param_3,param_2);
    param_3 = param_3 + 1;
  }
  return;
}



===== StorPortWritePortBufferUshort @ 140004ec0 =====

void StorPortWritePortBufferUshort
               (undefined8 param_1,undefined2 param_2,undefined2 *param_3,uint param_4)

{
  ulonglong uVar1;
  
                    /* 0x4ec0  52  StorPortWritePortBufferUshort */
  uVar1 = (ulonglong)param_4;
  while (uVar1 != 0) {
    uVar1 = uVar1 - 1;
    out(*param_3,param_2);
    param_3 = param_3 + 1;
  }
  return;
}



===== StorPortWritePortUchar @ 140004ee0 =====

undefined1 StorPortWritePortUchar(undefined8 param_1,undefined2 param_2,undefined1 param_3)

{
  out(param_2,param_3);
  return param_3;
}



===== StorPortWritePortUlong @ 140004ef0 =====

undefined4 StorPortWritePortUlong(undefined8 param_1,undefined2 param_2,undefined4 param_3)

{
  out(param_2,param_3);
  return param_3;
}



===== StorPortWritePortUshort @ 140004f00 =====

undefined2 StorPortWritePortUshort(undefined8 param_1,undefined2 param_2,undefined2 param_3)

{
  out(param_2,param_3);
  return param_3;
}



===== StorPortWriteRegisterBufferUchar @ 140004f20 =====

void StorPortWriteRegisterBufferUchar
               (undefined8 param_1,undefined1 *param_2,undefined1 *param_3,uint param_4)

{
  ulonglong uVar1;
  
                    /* 0x4f20  56  StorPortWriteRegisterBufferUchar */
  for (uVar1 = (ulonglong)param_4; uVar1 != 0; uVar1 = uVar1 - 1) {
    *param_2 = *param_3;
    param_3 = param_3 + 1;
    param_2 = param_2 + 1;
  }
  LOCK();
  UNLOCK();
  return;
}



===== StorPortWriteRegisterBufferUlong @ 140004f50 =====

void StorPortWriteRegisterBufferUlong
               (undefined8 param_1,undefined4 *param_2,undefined4 *param_3,uint param_4)

{
  ulonglong uVar1;
  
                    /* 0x4f50  57  StorPortWriteRegisterBufferUlong */
  for (uVar1 = (ulonglong)param_4; uVar1 != 0; uVar1 = uVar1 - 1) {
    *param_2 = *param_3;
    param_3 = param_3 + 1;
    param_2 = param_2 + 1;
  }
  LOCK();
  UNLOCK();
  return;
}



===== StorPortWriteRegisterBufferUshort @ 140004f80 =====

void StorPortWriteRegisterBufferUshort
               (undefined8 param_1,undefined2 *param_2,undefined2 *param_3,uint param_4)

{
  ulonglong uVar1;
  
                    /* 0x4f80  58  StorPortWriteRegisterBufferUshort */
  for (uVar1 = (ulonglong)param_4; uVar1 != 0; uVar1 = uVar1 - 1) {
    *param_2 = *param_3;
    param_3 = param_3 + 1;
    param_2 = param_2 + 1;
  }
  LOCK();
  UNLOCK();
  return;
}



===== StorPortWriteRegisterUchar @ 140004fb0 =====

void StorPortWriteRegisterUchar(undefined8 param_1,undefined1 *param_2,undefined1 param_3)

{
                    /* 0x4fb0  59  StorPortWriteRegisterUchar */
  *param_2 = param_3;
  LOCK();
  UNLOCK();
  return;
}



===== StorPortWriteRegisterUlong @ 140004fc0 =====

void StorPortWriteRegisterUlong(undefined8 param_1,undefined4 *param_2,undefined4 param_3)

{
                    /* 0x4fc0  60  StorPortWriteRegisterUlong */
  *param_2 = param_3;
  LOCK();
  UNLOCK();
  return;
}



===== StorPortWriteRegisterUshort @ 140004fd0 =====

void StorPortWriteRegisterUshort(undefined8 param_1,undefined2 *param_2,undefined2 param_3)

{
                    /* 0x4fd0  61  StorPortWriteRegisterUshort */
  *param_2 = param_3;
  LOCK();
  UNLOCK();
  return;
}



===== TickHandler @ 140004fe4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TickHandler(longlong param_1,longlong param_2)

{
  int iVar1;
  longlong *plVar2;
  code *pcVar3;
  longlong lVar4;
  longlong lVar5;
  undefined1 local_res8 [8];
  
  plVar2 = *(longlong **)(*(longlong *)(*(longlong *)(param_1 + 0x38) + 0x30) + 0x138);
  lVar4 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x38) + 0x38) + 0x48);
  if (*(char *)((longlong)plVar2 + 0x2b3) != '\0') {
    if ((*(uint *)((longlong)plVar2 + 0x24c) & 1) == 0) {
      iVar1 = (int)plVar2[0xb];
      if (iVar1 == 0) {
        RetrieveScsiStatusAndCdbOpcode(plVar2[5],(undefined1 *)0x0,local_res8);
        *(undefined4 *)(plVar2 + 0xb) = 0xffffffff;
        ResetBus(param_1);
        lVar5 = 10;
        do {
          KeStallExecutionProcessor(10);
          pcVar3 = *(code **)(lVar4 + 0x18);
          if (pcVar3 != (code *)0x0) {
            (*pcVar3)(plVar2[1] + 0x10);
          }
          lVar5 = lVar5 + -1;
        } while (lVar5 != 0);
      }
      else if (iVar1 != -1) {
        *(int *)(plVar2 + 0xb) = iVar1 + -1;
      }
    }
    else {
      *(uint *)((longlong)plVar2 + 0x24c) = *(uint *)((longlong)plVar2 + 0x24c) & 0xfffffffe;
      StartIo(plVar2,param_2);
      lVar4 = KeQueryPerformanceCounter(0);
      plVar2[0x5b] = lVar4;
    }
  }
  return;
}



===== WaitOnRequest @ 1400050c4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WaitOnRequest(longlong param_1,uint param_2)

{
  char cVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  code *pcVar5;
  undefined1 auVar6 [16];
  longlong lVar7;
  ulonglong uVar8;
  longlong lVar9;
  uint uVar10;
  ulonglong uVar11;
  char local_res10 [8];
  
  local_res10[0] = '\0';
  uVar11 = 0;
  lVar2 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x38) + 0x30) + 0x138);
  lVar3 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x38) + 0x38) + 0x48);
  lVar7 = KeQueryPerformanceCounter();
  lVar9 = 0;
  if (param_2 - 1 < 0xfffffffe) {
    auVar6._8_8_ = 0;
    auVar6._0_8_ = param_2 * g_Frequency;
    lVar9 = SUB168(ZEXT816(0x624dd2f1a9fbe77) * auVar6,8);
    uVar11 = (param_2 * g_Frequency - lVar9 >> 1) + lVar9 >> 9;
    lVar9 = lVar7;
  }
  while( true ) {
    if (*(ulonglong *)(lVar2 + 0x2d0) != 0) {
      lVar4 = *(longlong *)(lVar2 + 0x2c8);
      uVar8 = 0;
      if (lVar4 < lVar7) {
        uVar8 = lVar7 - lVar4;
      }
      else if (lVar7 < lVar4) {
        uVar8 = (lVar7 - lVar4) - 1;
      }
      if ((*(ulonglong *)(lVar2 + 0x2d0) <= uVar8) && (*(code **)(lVar2 + 0x2a8) != (code *)0x0)) {
        (**(code **)(lVar2 + 0x2a8))();
        *(undefined8 *)(lVar2 + 0x2c8) = 0;
        *(undefined8 *)(lVar2 + 0x2d0) = 0;
      }
    }
    if (((*(uint *)(lVar2 + 0x24c) & 0x20) == 0) &&
       (pcVar5 = *(code **)(lVar3 + 0x18), pcVar5 != (code *)0x0)) {
      (*pcVar5)();
    }
    uVar8 = 0;
    if (*(char *)(lVar2 + 0x2b3) == '\0') break;
    lVar4 = *(longlong *)(lVar2 + 0x2d8);
    if (lVar4 < lVar7) {
      uVar8 = lVar7 - lVar4;
    }
    else if (lVar7 < lVar4) {
      uVar8 = (lVar7 - lVar4) - 1;
    }
    if (g_Frequency <= uVar8) {
      do {
        TickHandler(param_1,*(longlong *)(lVar2 + 0x28));
        uVar8 = uVar8 - g_Frequency;
      } while (g_Frequency <= uVar8);
      lVar7 = KeQueryPerformanceCounter();
      if (uVar8 != 0) {
        lVar7 = lVar7 - uVar8;
      }
      *(longlong *)(lVar2 + 0x2d8) = lVar7;
    }
    if (param_2 == 0) {
      return 0x103;
    }
    lVar7 = KeQueryPerformanceCounter();
    if (param_2 != 0xffffffff) {
      uVar8 = 0;
      if (lVar9 < lVar7) {
        uVar8 = lVar7 - lVar9;
      }
      else if (lVar7 < lVar9) {
        uVar8 = (lVar7 - lVar9) - 1;
      }
      if (uVar11 <= uVar8) {
        return 0x103;
      }
    }
  }
  cVar1 = *(char *)(*(longlong *)(lVar2 + 0x28) + 3);
  *(undefined8 *)(lVar2 + 0x2d8) = 0;
  uVar10 = -(uint)(cVar1 != '\x01') & 0xc0000001;
  if (cVar1 == '\x01') {
    return 0;
  }
  RetrieveScsiStatusAndCdbOpcode(*(longlong *)(lVar2 + 0x28),local_res10,(undefined1 *)0x0);
  if (local_res10[0] != '\x02') {
    return uVar10;
  }
  if (*(char *)(lVar2 + 0x2b2) == '\0') {
    IssueRequestSense(param_1);
    return uVar10;
  }
  return uVar10;
}



===== WorkHorseDpc @ 1400052f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WorkHorseDpc(longlong *param_1)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  uint uVar4;
  undefined1 uVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  char local_res8 [8];
  
  uVar4 = *(uint *)(param_1 + 0x4a);
  lVar1 = *param_1;
  lVar2 = param_1[5];
  local_res8[0] = '\0';
  if ((uVar4 & 2) != 0) {
    lVar3 = param_1[0x4e];
    if (*(char *)(lVar3 + 2) == '(') {
      uVar4 = *(uint *)(lVar3 + 0x18);
    }
    else {
      uVar4 = *(uint *)(lVar3 + 0xc);
    }
    lVar3 = *(longlong *)(lVar1 + 0x40);
    (**(code **)(*(longlong *)(lVar3 + 8) + 0x28))
              (lVar3,param_1[8],param_1[0x4c],param_1[0x4f],(int)param_1[0x50],
               (byte)(uVar4 >> 7) & 1);
    *(uint *)(param_1 + 0x4a) = *(uint *)(param_1 + 0x4a) & 0xfffffffd;
    uVar4 = *(uint *)(param_1 + 0x4a);
  }
  if ((uVar4 & 4) != 0) {
    lVar3 = param_1[0x51];
    if (*(char *)(lVar3 + 2) == '(') {
      uVar4 = *(uint *)(lVar3 + 0x18);
    }
    else {
      uVar4 = *(uint *)(lVar3 + 0xc);
    }
    lVar1 = *(longlong *)(lVar1 + 0x40);
    (**(code **)(*(longlong *)(lVar1 + 8) + 0x40))
              (lVar1,param_1[8],param_1[0x4c],param_1[0x52],param_1 + 0x53,(byte)(uVar4 >> 7) & 1);
    *(uint *)(param_1 + 0x4a) = *(uint *)(param_1 + 0x4a) & 0xfffffffb;
    *(uint *)((longlong)param_1 + 0x24c) = *(uint *)((longlong)param_1 + 0x24c) | 8;
    param_1[0x4e] = param_1[0x51];
    param_1[0x4f] = param_1[0x52];
    param_1[0x50] = param_1[0x53];
  }
  if (*(char *)((longlong)param_1 + 0x2b4) != '\0') {
    *(undefined4 *)(param_1 + 0xb) = 0xffffffff;
    *(undefined2 *)((longlong)param_1 + 0x2b3) = 0;
    if ((*(char *)((longlong)param_1 + 0x2b1) != '\0') && (param_1[8] != 0)) {
      if (*(char *)(lVar2 + 2) == '(') {
        uVar7 = *(undefined8 *)(lVar2 + 0x40);
        uVar6 = *(undefined4 *)(lVar2 + 0x3c);
        uVar4 = *(uint *)(lVar2 + 0x18);
      }
      else {
        uVar7 = *(undefined8 *)(lVar2 + 0x18);
        uVar6 = *(undefined4 *)(lVar2 + 0x10);
        uVar4 = *(uint *)(lVar2 + 0xc);
      }
      (**(code **)(*(longlong *)(*(longlong *)(*param_1 + 0x40) + 8) + 0x28))
                (*(longlong *)(*param_1 + 0x40),param_1[8],param_1[0x4c],uVar7,uVar6,
                 (byte)(uVar4 >> 7) & 1);
    }
    if (*(char *)(lVar2 + 3) != '\x01') {
      uVar5 = 0;
      RetrieveScsiStatusAndCdbOpcode(lVar2,local_res8,(undefined1 *)0x0);
      if (((local_res8[0] == '\b') || (*(char *)(lVar2 + 3) == '\x05')) &&
         (uVar4 = *(uint *)((longlong)param_1 + 0x5c),
         *(uint *)((longlong)param_1 + 0x5c) = uVar4 + 1, uVar4 < 0x14)) {
        *(undefined1 *)(lVar2 + 3) = uVar5;
        *(uint *)((longlong)param_1 + 0x24c) = *(uint *)((longlong)param_1 + 0x24c) | 1;
        if (*(char *)(lVar2 + 2) == '(') {
          *(int *)(lVar2 + 0x3c) = (int)param_1[0xc];
        }
        else {
          *(int *)(lVar2 + 0x10) = (int)param_1[0xc];
        }
        *(undefined1 *)((longlong)param_1 + 0x2b3) = 1;
      }
    }
    if (*(char *)((longlong)param_1 + 0x2b3) != '\x01') {
      param_1[8] = 0;
      param_1[9] = 0;
    }
  }
  return;
}



===== wil_details_FeatureReporting_RecordUsageInCache @ 1400054e8 =====

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
LAB_1400056fd:
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
LAB_1400055cb:
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
      if (param_3 == 4) goto LAB_1400056fd;
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
        goto LAB_1400055cb;
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



===== wil_details_FeatureReporting_ReportUsageToService @ 1400057f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void wil_details_FeatureReporting_ReportUsageToService
               (longlong param_1,ulonglong param_2,int param_3,undefined8 param_4)

{
  bool bVar1;
  undefined7 extraout_var;
  uint uVar2;
  uint uVar3;
  byte bVar4;
  int local_res18 [4];
  
  uVar2 = (uint)param_2 & 1;
  if (param_3 != 0) {
    if (param_3 == 1) {
      uVar3 = (uVar2 ^ 1) << 2;
      goto LAB_1400058c1;
    }
    if (param_3 == 2) {
      uVar3 = (uVar2 ^ 1) * 4 + 1;
      goto LAB_1400058c1;
    }
    if (param_3 == 3) {
      uVar3 = (uVar2 ^ 1) * 4 + 2;
      goto LAB_1400058c1;
    }
    if (param_3 == 4) {
      uVar3 = (uVar2 ^ 1) * 4 + 3;
      goto LAB_1400058c1;
    }
    if (param_3 == 5) {
      uVar3 = (uVar2 ^ 1) * 2 + 8;
      goto LAB_1400058c1;
    }
    if (param_3 == 6) {
      uVar3 = (uVar2 ^ 1) * 2 + 9;
      goto LAB_1400058c1;
    }
    bVar4 = (char)param_3 + 0x9c;
    if (bVar4 < 0x32) {
      uVar3 = (-(uint)((param_2 & 1) != 0) & 0xffffffce) + 0x96 + (uint)bVar4;
      goto LAB_1400058c1;
    }
  }
  uVar3 = 0xff;
LAB_1400058c1:
  local_res18[0] = param_3;
  bVar1 = wil_details_FeatureReporting_ReportUsageToServiceDirect
                    (param_1,param_2,uVar3,(uint)param_4);
  if (((int)CONCAT71(extraout_var,bVar1) != 0) &&
     (g_wil_details_pfnFeatureLoggingHook != (code *)0x0)) {
    (*g_wil_details_pfnFeatureLoggingHook)
              (*(undefined4 *)(param_1 + 0x18),*(undefined8 *)(param_1 + 0x10),0,uVar2,local_res18,0
               ,0,param_4);
  }
  return;
}



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 14000591c =====

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



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 140005a04 =====

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
LAB_140005ab7:
    uVar8 = uVar8 << 10;
    if (uVar5 != 0) {
      uVar5 = 0x800;
      goto LAB_140005ae5;
    }
  }
  else {
    uVar8 = 0;
    uVar5 = 0;
    uVar11 = (uint)local_70;
    if (iVar4 != 0x117) goto LAB_140005ab7;
    bVar2 = 1;
    uVar8 = (local_58._4_4_ >> 7 & 1) << 10;
  }
  uVar5 = 0;
LAB_140005ae5:
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



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 140005c70 =====

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



===== wil_details_IsEnabledFallback @ 140005cd4 =====

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



===== wil_details_RecordCachedUsage @ 140005d70 =====

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



===== wil_details_RecordFeatureUsageReporting @ 140005ed0 =====

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



===== AdminQueueInitialize @ 140005f54 =====

undefined8 AdminQueueInitialize(ulonglong param_1)

{
  ulonglong *puVar1;
  ulonglong *puVar2;
  ushort uVar3;
  void *pvVar4;
  void *_Dst;
  
  puVar1 = (ulonglong *)(param_1 + 0x210);
  puVar2 = (ulonglong *)(param_1 + 0x150);
  uVar3 = *(ushort *)(param_1 + 0x144);
  _Dst = (void *)(*puVar1 + (ulonglong)uVar3 * 0x10);
  pvVar4 = (void *)((ulonglong)uVar3 * 0x10 + (longlong)_Dst);
  if (uVar3 != 0) {
    memset(_Dst,0,(ulonglong)uVar3 << 4);
  }
  if (*(ushort *)(param_1 + 0x144) != 0) {
    memset(pvVar4,0,(ulonglong)*(ushort *)(param_1 + 0x144) << 5);
  }
  NVMeSubmissionQueueInit(param_1,puVar2,0,*puVar2,0,(ulonglong)_Dst,(ulonglong)pvVar4,0);
  NVMeCompletionQueueInit(param_1,puVar1,0,*puVar1,0,0,0);
  if (*(ushort *)(param_1 + 0x144) != 0) {
    memset((void *)*puVar2,0,(ulonglong)*(ushort *)(param_1 + 0x144) << 6);
  }
  pvVar4 = (void *)((ulonglong)*(ushort *)(param_1 + 0x144) << 2);
  if ((int)pvVar4 != 0) {
    pvVar4 = memset((void *)*puVar1,0,(ulonglong)*(ushort *)(param_1 + 0x144) << 4);
  }
  *(undefined2 *)(param_1 + 0x18a) = 0;
  *(undefined4 *)(param_1 + 0x2c4) = 1;
  return CONCAT71((int7)((ulonglong)pvVar4 >> 8),1);
}



===== ControllerAllocateUncachedExtension @ 140006090 =====

ulonglong ControllerAllocateUncachedExtension(longlong param_1)

{
  longlong lVar1;
  longlong *plVar2;
  void *_Dst;
  ulonglong uVar3;
  int local_res10 [6];
  
  _Dst = (void *)0x0;
  uVar3 = *(ulonglong *)(param_1 + -0x10);
  if (0x9fff < *(uint *)(uVar3 + 0x218)) {
    _Dst = *(void **)(uVar3 + 0x210);
  }
  *(void **)(param_1 + 0x558) = _Dst;
  if (_Dst == (void *)0x0) {
    *(undefined4 *)(param_1 + 0x1c) = 1;
    uVar3 = uVar3 & 0xffffffffffffff00;
  }
  else {
    memset(_Dst,0,0xa000);
    uVar3 = *(longlong *)(param_1 + 0x558) + 0xfffU & 0xfffffffffffff000;
    *(ulonglong *)(param_1 + 0x558) = uVar3;
    *(ulonglong *)(param_1 + 0x548) = uVar3;
    lVar1 = StorPortGetPhysicalAddress(param_1,0,uVar3,local_res10);
    *(longlong *)(param_1 + 0x550) = lVar1;
    *(longlong *)(param_1 + 0x440) = *(longlong *)(param_1 + 0x558) + 0x1000;
    uVar3 = *(longlong *)(param_1 + 0x558) + 0x3000;
    *(ulonglong *)(param_1 + 0x558) = uVar3;
    *(ulonglong *)(param_1 + 0x5a8) = uVar3;
    lVar1 = StorPortGetPhysicalAddress(param_1,0,uVar3,local_res10);
    *(longlong *)(param_1 + 0x5b0) = lVar1;
    lVar1 = *(longlong *)(param_1 + 0x558) + 0x1000;
    *(longlong *)(param_1 + 0x150) = lVar1;
    uVar3 = lVar1 + (ulonglong)*(ushort *)(param_1 + 0x144) * 0x40;
    plVar2 = (longlong *)(ulonglong)((uint)uVar3 & 0xfff);
    if ((uVar3 & 0xfff) != 0) {
      uVar3 = (uVar3 - (longlong)plVar2) + 0x1000;
    }
    *(ulonglong *)(param_1 + 0x558) = uVar3 + 0x1000;
    *(ulonglong *)(param_1 + 0x210) = uVar3;
    if (*(char *)(param_1 + 0x14) != '\0') {
      *(ulonglong *)(param_1 + 0x558) = uVar3 + 0x3000;
      *(ulonglong *)(param_1 + 0x3a0) = uVar3 + 0x2e78;
      *(longlong **)(param_1 + 0x398) = (longlong *)(uVar3 + 0x2db8);
      *(longlong *)(uVar3 + 0x2db8) = uVar3 + 0x1000;
      plVar2 = *(longlong **)(param_1 + 0x3a0);
      *plVar2 = uVar3 + 0x2000;
    }
    uVar3 = CONCAT71((int7)((ulonglong)plVar2 >> 8),1);
  }
  return uVar3;
}



===== ControllerReset @ 1400061f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int ControllerReset(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 *param_4)

{
  longlong lVar1;
  byte bVar2;
  uint uVar3;
  longlong *plVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  ulonglong uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  longlong lVar12;
  uint uVar13;
  undefined1 local_f8 [32];
  undefined4 in_stack_ffffffffffffff28;
  undefined4 in_stack_ffffffffffffff2c;
  undefined8 in_stack_ffffffffffffff30;
  undefined4 in_stack_ffffffffffffff38;
  undefined4 in_stack_ffffffffffffff3c;
  undefined8 in_stack_ffffffffffffff40;
  undefined4 in_stack_ffffffffffffff48;
  undefined4 in_stack_ffffffffffffff4c;
  undefined4 local_88;
  undefined4 local_84;
  byte local_80;
  undefined1 local_7f;
  undefined4 local_7c;
  undefined4 local_78;
  undefined8 local_70;
  undefined4 local_68;
  undefined2 local_64;
  undefined2 local_62;
  undefined2 local_60;
  undefined2 local_5e;
  undefined2 local_5c;
  undefined2 local_5a;
  undefined2 local_58;
  undefined2 local_56;
  undefined2 local_54;
  undefined2 local_52;
  undefined2 local_50;
  undefined2 local_4e;
  undefined2 local_4c;
  undefined2 local_4a;
  longlong local_48;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)local_f8;
  uVar7 = *(uint *)(param_1 + 0xcc) / 10;
  memset(&local_88,0,0x58);
  uVar3 = *(uint *)(*(longlong *)(param_1 + 0xb0) + 0x14);
  uVar6 = *(uint *)(*(longlong *)(param_1 + 0xb0) + 0x1c);
  if (((uVar3 & 1) != 0) && ((uVar6 & 1) == 0)) {
    uVar13 = 0;
    if (uVar7 != 0) {
      do {
        if ((uVar6 & 1) != 0) goto LAB_1400062cc;
        if (*(longlong *)(*(longlong *)(param_1 + 0xb0) + 0x28) == -1) goto LAB_1400062c3;
        StorPortExtendedFunction
                  (0x51,param_1,(PSLIST_HEADER)0x2710,param_4,
                   (undefined8 *)CONCAT44(in_stack_ffffffffffffff2c,in_stack_ffffffffffffff28),
                   in_stack_ffffffffffffff30,
                   CONCAT44(in_stack_ffffffffffffff3c,in_stack_ffffffffffffff38),
                   in_stack_ffffffffffffff40,
                   CONCAT44(in_stack_ffffffffffffff4c,in_stack_ffffffffffffff48));
        uVar13 = uVar13 + 1;
        uVar6 = *(uint *)(*(longlong *)(param_1 + 0xb0) + 0x1c);
      } while (uVar13 < uVar7);
    }
    if (((uVar6 & 1) == 0) && (uVar13 == uVar7)) {
      bVar2 = 0;
      goto LAB_140006346;
    }
  }
LAB_1400062cc:
  *(uint *)(*(longlong *)(param_1 + 0xb0) + 0x14) = uVar3 & 0xfffffffe;
  LOCK();
  UNLOCK();
  uVar6 = 0;
  uVar3 = *(uint *)(*(longlong *)(param_1 + 0xb0) + 0x1c);
  if (uVar7 != 0) {
    do {
      if ((uVar3 & 1) == 0) goto LAB_140006503;
      if (*(longlong *)(*(longlong *)(param_1 + 0xb0) + 0x28) == -1) goto LAB_1400062c3;
      StorPortExtendedFunction
                (0x51,param_1,(PSLIST_HEADER)0x2710,param_4,
                 (undefined8 *)CONCAT44(in_stack_ffffffffffffff2c,in_stack_ffffffffffffff28),
                 in_stack_ffffffffffffff30,
                 CONCAT44(in_stack_ffffffffffffff3c,in_stack_ffffffffffffff38),
                 in_stack_ffffffffffffff40,
                 CONCAT44(in_stack_ffffffffffffff4c,in_stack_ffffffffffffff48));
      uVar6 = uVar6 + 1;
      uVar3 = *(uint *)(*(longlong *)(param_1 + 0xb0) + 0x1c);
    } while (uVar6 < uVar7);
  }
  if (((uVar3 & 1) == 0) || (uVar6 != uVar7)) {
LAB_140006503:
    *(int *)(param_1 + 0xf58) = *(int *)(param_1 + 0xf58) + 1;
    return 0;
  }
  bVar2 = 0;
LAB_140006346:
  *(int *)(param_1 + 0xf5c) = *(int *)(param_1 + 0xf5c) + 1;
  local_7c = *(undefined4 *)(param_1 + 0x18);
  local_78 = *(undefined4 *)(param_1 + 0x1c);
  local_80 = *(byte *)(param_1 + 0x15) >> 5 & 1;
  local_88 = 0x58;
  local_7f = *(undefined1 *)(param_1 + 0x16);
  local_70 = *(undefined8 *)(param_1 + 0xdf8);
  local_68 = *(undefined4 *)(param_1 + 0xe00);
  local_64 = *(undefined2 *)(param_1 + 0x140);
  local_62 = *(undefined2 *)(param_1 + 0x142);
  local_60 = *(undefined2 *)(param_1 + 0x144);
  local_5e = *(undefined2 *)(param_1 + 0x146);
  local_5c = *(undefined2 *)(param_1 + 0x148);
  local_5a = *(undefined2 *)(param_1 + 0x14a);
  local_58 = *(undefined2 *)(param_1 + 0x14c);
  local_56 = *(undefined2 *)(param_1 + 0x14e);
  local_54 = *(undefined2 *)(param_1 + 0x3a8);
  local_52 = *(undefined2 *)(param_1 + 0x3aa);
  local_50 = *(undefined2 *)(param_1 + 0x3c0);
  local_4e = *(undefined2 *)(param_1 + 0x3c2);
  local_4c = *(undefined2 *)(param_1 + 0x3c4);
  local_4a = *(undefined2 *)(param_1 + 0x3c6);
  local_84 = 0x58;
  if (*(uint *)(param_1 + 0xe0) != 0) {
    plVar4 = (longlong *)(param_1 + 0x5b8);
    uVar8 = (ulonglong)*(uint *)(param_1 + 0xe0);
    lVar12 = local_48;
    iVar5 = local_34;
    iVar11 = local_40;
    iVar9 = local_38;
    iVar10 = local_3c;
    do {
      lVar1 = *plVar4;
      if (lVar1 != 0) {
        lVar12 = lVar12 + *(longlong *)(lVar1 + 0x18);
        iVar11 = iVar11 + *(int *)(lVar1 + 0x20);
        iVar10 = iVar10 + *(int *)(lVar1 + 0x24);
        iVar9 = iVar9 + *(int *)(lVar1 + 0x28);
        iVar5 = iVar5 + *(int *)(lVar1 + 0x2c);
        local_48 = lVar12;
        local_40 = iVar11;
        local_3c = iVar10;
        local_38 = iVar9;
        local_34 = iVar5;
      }
      plVar4 = plVar4 + 1;
      uVar8 = uVar8 - 1;
    } while (uVar8 != 0);
  }
  StorPortNotification(0x100d,param_1,0,0);
  return (-(uint)bVar2 & 8) + 0xc1000001;
LAB_1400062c3:
  *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) | 0x1000000;
  bVar2 = 1;
  goto LAB_140006346;
}



===== DspNvmeControl @ 14000653c =====

ulonglong DspNvmeControl(longlong param_1,int param_2,undefined4 *param_3,undefined8 *param_4)

{
  ushort *puVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  code *pcVar5;
  uint uVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  char *pcVar9;
  
  if ((param_2 == 0) || (10 < param_2)) {
    return 0xc000000d;
  }
  if (param_2 < 7) {
    if (param_2 == 6) {
      lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 0x30);
      *param_3 = *(undefined4 *)(*(longlong *)(param_1 + 0x30) + 0x6c);
      param_3[1] = *(undefined4 *)(lVar2 + 0x14c);
      return 0;
    }
    if (param_2 == 1) {
      *(undefined1 *)((longlong)param_3 + 1) = 1;
      return 0;
    }
    if (param_2 == 2) {
      lVar2 = *(longlong *)(param_1 + 0x38);
      lVar3 = *(longlong *)(param_1 + 0x30);
      lVar4 = *(longlong *)(lVar2 + 0x30);
      KeQueryPerformanceCounter(&g_Frequency);
      if ((*(byte *)(lVar4 + 0x150) & 1) == 0) {
        uVar6 = NvmePrepareAdapter(lVar2);
        if ((int)uVar6 < 0) goto LAB_14000665c;
        MarkHiberBootPhaseForAdapter(lVar4);
      }
      lVar2 = *(longlong *)(lVar3 + 0x28);
      if (lVar2 != 0) {
        PoSetHiberRange(0,0x10000,lVar2,1,0x74707344);
      }
    }
    else {
      if (param_2 == 3) {
        puVar1 = (ushort *)(*(longlong *)(*(longlong *)(param_1 + 0x38) + 0x30) + 0x150);
        *puVar1 = *puVar1 & 0xfffe;
        return 0;
      }
      if (param_2 != 4) {
        if (param_2 == 5) {
          return 0;
        }
LAB_14000669f:
        DbgPrintEx(5,2,"*\n*\nDumpControl NOT SUPPORTED\n*\n*\n");
        pcVar5 = (code *)swi(3);
        uVar8 = (*pcVar5)();
        return uVar8;
      }
      lVar2 = *(longlong *)(param_1 + 0x30);
      lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 0x30);
      lVar4 = *(longlong *)(*(longlong *)(lVar3 + 0x158) + 8);
      if ((*(byte *)(lVar3 + 0x150) & 2) == 0) {
        uVar7 = NvmeDumpStartAdapter(*(longlong *)(param_1 + 0x38));
        uVar6 = (uint)uVar7;
        if ((int)uVar6 < 0) goto LAB_14000665c;
      }
      *(undefined4 *)(lVar2 + 0x6c) =
           *(undefined4 *)
            (*(longlong *)(lVar4 + 0x5c8 + (ulonglong)(*(int *)(lVar2 + 100) - 1) * 8) + 0x34);
    }
    uVar6 = 0;
  }
  else {
    if (param_2 != 7) {
      if (param_2 == 8) {
        pcVar9 = "*\n*\nDumpControlGetDeviceInternalLog\n*\n*\n";
      }
      else if (param_2 == 9) {
        pcVar9 = "*\n*\nDumpControlPrepareEarlyDumpData\n*\n*\n";
      }
      else {
        if (param_2 != 10) goto LAB_14000669f;
        pcVar9 = "*\n*\nDumpControlRestoreEarlyDumpData\n*\n*\n";
      }
      DbgPrintEx(5,2,pcVar9);
      pcVar5 = (code *)swi(3);
      uVar8 = (*pcVar5)();
      return uVar8;
    }
    uVar7 = NvmeControlCleanup(param_1,0,(ulonglong)param_3,param_4);
    uVar6 = (uint)uVar7;
  }
LAB_14000665c:
  return (ulonglong)uVar6;
}



===== DspNvmeFlush @ 140006720 =====

void DspNvmeFlush(longlong param_1)

{
  undefined4 uVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  
  lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 0x30);
  lVar3 = *(longlong *)(*(longlong *)(lVar2 + 0x158) + 8);
  *(undefined1 *)(lVar3 + 0x3fb) = 0;
  memset(*(void **)(lVar3 + 0x450),0,0x1080);
  *(undefined8 *)(*(longlong *)(lVar3 + 0x450) + 0x1060) = 0;
  lVar4 = *(longlong *)(lVar3 + 0x450);
  *(longlong *)(lVar3 + 0x430) = lVar4;
  *(undefined4 *)(lVar3 + 0x3f0) = 1;
  uVar1 = *(undefined4 *)(lVar2 + 0x148);
  *(undefined1 *)(lVar4 + 0x1000) = 0;
  *(undefined4 *)(lVar4 + 0x1004) = uVar1;
  NvmeDumpSynchronousExecuteCommandInSpecificQueue
            (lVar3 + 0x10,*(longlong *)(lVar3 + 0x3a8),*(longlong **)(lVar3 + 0x3b0),
             *(ushort *)(lVar3 + 0x156),lVar3 + 0x3f0);
  return;
}



===== DspNvmeRead @ 1400067d8 =====

ulonglong DspNvmeRead(longlong param_1,int param_2,ulonglong *param_3,longlong param_4)

{
  int iVar1;
  undefined4 uVar2;
  longlong lVar3;
  longlong lVar4;
  longlong *plVar5;
  undefined1 auVar6 [16];
  int iVar7;
  uint uVar8;
  ulonglong uVar9;
  longlong lVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  longlong *plVar14;
  int local_res10 [2];
  
  if (param_2 == 1) {
    lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 0x30);
    lVar3 = *(longlong *)(*(longlong *)(lVar10 + 0x158) + 8);
    *(undefined1 *)(lVar3 + 0x3fb) = 0;
    memset(*(void **)(lVar3 + 0x450),0,0x1080);
    *(undefined8 *)(*(longlong *)(lVar3 + 0x450) + 0x1060) = 0;
    lVar4 = *(longlong *)(lVar3 + 0x450);
    *(longlong *)(lVar3 + 0x430) = lVar4;
    *(undefined4 *)(lVar3 + 0x3f0) = 1;
    uVar13 = *(uint *)(param_4 + 0x28);
    iVar1 = *(int *)(param_4 + 0x20);
    uVar8 = *(uint *)(param_4 + 0x2c);
    uVar2 = *(undefined4 *)(lVar10 + 0x148);
    uVar12 = *(uint *)(*(longlong *)(param_1 + 0x30) + 0x6c);
    uVar9 = *param_3;
    *(undefined1 *)(lVar4 + 0x1000) = 2;
    *(uint *)(lVar4 + 0x1000) = *(uint *)(lVar4 + 0x1000) & 0xfffffcff;
    *(undefined4 *)(lVar4 + 0x1004) = uVar2;
    auVar6._8_8_ = 0;
    auVar6._0_8_ = uVar9;
    *(int *)(lVar4 + 0x1028) = SUB164(auVar6 / ZEXT416(uVar12),0);
    *(int *)(lVar4 + 0x102c) = SUB164(auVar6 / ZEXT416(uVar12),4);
    *(undefined8 *)(lVar4 + 0x1010) = 0;
    *(undefined1 *)(lVar4 + 0x1034) = 0;
    *(undefined8 *)(lVar4 + 0x1038) = 0;
    *(short *)(lVar4 + 0x1030) = (short)(((uVar13 - 1) + uVar12) / uVar12) + -1;
    *(uint *)(lVar4 + 0x1030) = *(uint *)(lVar4 + 0x1030) & 0x3ffffff;
    KeFlushIoBuffers(param_4,0,CONCAT31((int3)(uVar12 >> 8),1));
    plVar5 = *(longlong **)(lVar3 + 0x450);
    uVar9 = (ulonglong)(uVar8 >> 0xc);
    if (uVar8 < 0x1000) {
      uVar9 = 0;
    }
    uVar12 = uVar8 & 0xfff;
    if (uVar8 < 0x1000) {
      uVar12 = uVar8;
    }
    uVar11 = (uint)((ulonglong)uVar13 + 0xfff + ((ulonglong)uVar8 & 0xfff) >> 0xc);
    if ((uVar11 == 0) ||
       (iVar7 = (int)uVar9,
       (uint)((ulonglong)uVar13 + 0xfff + (ulonglong)(iVar1 + uVar8 & 0xfff) >> 0xc) <
       iVar7 + uVar11)) {
      uVar9 = 0xc0000001;
    }
    else {
      plVar5[0x203] = *(longlong *)(param_4 + 0x30 + uVar9 * 8) * 0x1000 + (ulonglong)uVar12;
      if (uVar11 != 1) {
        if (uVar11 == 2) {
          lVar10 = *(longlong *)(param_4 + 0x30 + (ulonglong)(iVar7 + 1) * 8) << 0xc;
          plVar5[0x204] = lVar10;
          if (plVar5 != (longlong *)0x0) {
            *plVar5 = lVar10;
          }
        }
        else {
          local_res10[0] = 0;
          uVar13 = 1;
          plVar14 = plVar5;
          if (1 < uVar11) {
            do {
              uVar8 = iVar7 + uVar13;
              uVar13 = uVar13 + 1;
              *plVar14 = *(longlong *)(param_4 + 0x30 + (ulonglong)uVar8 * 8) << 0xc;
              plVar14 = plVar14 + 1;
            } while (uVar13 < uVar11);
          }
          lVar10 = NvmeDumpGetPhysicalAddressFromCommonBuffer
                             (lVar3 + 0x10,(ulonglong)plVar5,local_res10);
          plVar5[0x204] = lVar10;
        }
      }
      uVar9 = NvmeDumpSynchronousExecuteCommandInSpecificQueue
                        (lVar3 + 0x10,*(longlong *)(lVar3 + 0x3a8),*(longlong **)(lVar3 + 0x3b0),
                         *(ushort *)(lVar3 + 0x156),lVar3 + 0x3f0);
    }
  }
  else {
    uVar9 = 0xc00000bb;
  }
  return uVar9;
}



===== DspNvmeWrite @ 140006a44 =====

ulonglong DspNvmeWrite(longlong param_1,int param_2,ulonglong *param_3,longlong param_4)

{
  int iVar1;
  undefined4 uVar2;
  longlong lVar3;
  longlong lVar4;
  longlong *plVar5;
  undefined1 auVar6 [16];
  int iVar7;
  uint uVar8;
  ulonglong uVar9;
  longlong lVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  longlong *plVar14;
  int local_res10 [2];
  
  if (param_2 == 1) {
    lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 0x30);
    lVar3 = *(longlong *)(*(longlong *)(lVar10 + 0x158) + 8);
    *(undefined1 *)(lVar3 + 0x3fb) = 0;
    memset(*(void **)(lVar3 + 0x450),0,0x1080);
    *(undefined8 *)(*(longlong *)(lVar3 + 0x450) + 0x1060) = 0;
    lVar4 = *(longlong *)(lVar3 + 0x450);
    *(longlong *)(lVar3 + 0x430) = lVar4;
    *(undefined4 *)(lVar3 + 0x3f0) = 1;
    uVar13 = *(uint *)(param_4 + 0x28);
    iVar1 = *(int *)(param_4 + 0x20);
    uVar8 = *(uint *)(param_4 + 0x2c);
    uVar2 = *(undefined4 *)(lVar10 + 0x148);
    uVar12 = *(uint *)(*(longlong *)(param_1 + 0x30) + 0x6c);
    uVar9 = *param_3;
    *(undefined1 *)(lVar4 + 0x1000) = 1;
    *(uint *)(lVar4 + 0x1000) = *(uint *)(lVar4 + 0x1000) & 0xfffffcff;
    *(undefined4 *)(lVar4 + 0x1004) = uVar2;
    auVar6._8_8_ = 0;
    auVar6._0_8_ = uVar9;
    *(int *)(lVar4 + 0x1028) = SUB164(auVar6 / ZEXT416(uVar12),0);
    *(int *)(lVar4 + 0x102c) = SUB164(auVar6 / ZEXT416(uVar12),4);
    *(undefined8 *)(lVar4 + 0x1010) = 0;
    *(undefined1 *)(lVar4 + 0x1034) = 0;
    *(undefined8 *)(lVar4 + 0x1038) = 0;
    *(short *)(lVar4 + 0x1030) = (short)(((uVar13 - 1) + uVar12) / uVar12) + -1;
    *(uint *)(lVar4 + 0x1030) = *(uint *)(lVar4 + 0x1030) & 0x3ffffff;
    KeFlushIoBuffers(param_4,0,CONCAT31((int3)(uVar12 >> 8),1));
    plVar5 = *(longlong **)(lVar3 + 0x450);
    uVar9 = (ulonglong)(uVar8 >> 0xc);
    if (uVar8 < 0x1000) {
      uVar9 = 0;
    }
    uVar12 = uVar8 & 0xfff;
    if (uVar8 < 0x1000) {
      uVar12 = uVar8;
    }
    uVar11 = (uint)((ulonglong)uVar13 + 0xfff + ((ulonglong)uVar8 & 0xfff) >> 0xc);
    if ((uVar11 == 0) ||
       (iVar7 = (int)uVar9,
       (uint)((ulonglong)uVar13 + 0xfff + (ulonglong)(iVar1 + uVar8 & 0xfff) >> 0xc) <
       iVar7 + uVar11)) {
      uVar9 = 0xc0000001;
    }
    else {
      plVar5[0x203] = *(longlong *)(param_4 + 0x30 + uVar9 * 8) * 0x1000 + (ulonglong)uVar12;
      if (uVar11 != 1) {
        if (uVar11 == 2) {
          lVar10 = *(longlong *)(param_4 + 0x30 + (ulonglong)(iVar7 + 1) * 8) << 0xc;
          plVar5[0x204] = lVar10;
          if (plVar5 != (longlong *)0x0) {
            *plVar5 = lVar10;
          }
        }
        else {
          local_res10[0] = 0;
          uVar13 = 1;
          plVar14 = plVar5;
          if (1 < uVar11) {
            do {
              uVar8 = iVar7 + uVar13;
              uVar13 = uVar13 + 1;
              *plVar14 = *(longlong *)(param_4 + 0x30 + (ulonglong)uVar8 * 8) << 0xc;
              plVar14 = plVar14 + 1;
            } while (uVar13 < uVar11);
          }
          lVar10 = NvmeDumpGetPhysicalAddressFromCommonBuffer
                             (lVar3 + 0x10,(ulonglong)plVar5,local_res10);
          plVar5[0x204] = lVar10;
        }
      }
      uVar9 = NvmeDumpSynchronousExecuteCommandInSpecificQueue
                        (lVar3 + 0x10,*(longlong *)(lVar3 + 0x3a8),*(longlong **)(lVar3 + 0x3b0),
                         *(ushort *)(lVar3 + 0x156),lVar3 + 0x3f0);
    }
  }
  else {
    uVar9 = 0xc00000bb;
  }
  return uVar9;
}



===== GetSrbScsiData @ 140006cb0 =====

int * GetSrbScsiData(longlong param_1,uint *param_2)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  bool bVar4;
  uint *puVar5;
  ulonglong uVar6;
  int *piVar7;
  
  piVar7 = (int *)0x0;
  bVar4 = false;
  if (((*(char *)(param_1 + 2) == '(') && (*(int *)(param_1 + 0x14) == 0)) &&
     (*(uint *)(param_1 + 0x38) != 0)) {
    puVar5 = (uint *)(param_1 + 0x78);
    uVar6 = (ulonglong)*(uint *)(param_1 + 0x38);
    do {
      uVar2 = *puVar5;
      if ((0x7f < uVar2) && (uVar2 <= *(uint *)(param_1 + 0x10))) {
        piVar1 = (int *)(param_1 + (ulonglong)uVar2);
        iVar3 = *piVar1;
        if ((iVar3 == 0x40) || (iVar3 == 0x41)) {
          bVar4 = true;
          if (param_2 != (uint *)0x0) {
            *param_2 = (uint)*(byte *)((longlong)piVar1 + 10);
          }
          if (*(char *)((longlong)piVar1 + 10) != '\0') {
            piVar7 = piVar1 + 6;
          }
        }
        else if (iVar3 == 0x42) {
          bVar4 = true;
          if (param_2 != (uint *)0x0) {
            *param_2 = piVar1[3];
          }
          if (piVar1[3] != 0) {
            piVar7 = piVar1 + 8;
          }
        }
      }
      puVar5 = puVar5 + 1;
      uVar6 = uVar6 - 1;
    } while (uVar6 != 0);
  }
  if (*(char *)(param_1 + 2) == '\0') {
    if (param_2 != (uint *)0x0) {
      *param_2 = (uint)*(byte *)(param_1 + 10);
    }
    if (*(char *)(param_1 + 10) != '\0') {
      piVar7 = (int *)(param_1 + 0x48);
    }
  }
  else if ((!bVar4) && (param_2 != (uint *)0x0)) {
    *param_2 = 0;
  }
  return piVar7;
}



===== IoQueuesCreation @ 140006d90 =====

undefined8 IoQueuesCreation(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  uint uVar4;
  int iVar5;
  undefined8 uVar6;
  undefined4 uVar7;
  undefined8 unaff_RBP;
  ushort uVar8;
  undefined8 unaff_RSI;
  undefined8 unaff_RDI;
  longlong lVar9;
  undefined8 unaff_R14;
  undefined8 *unaff_R15;
  undefined8 local_res8;
  _SLIST_HEADER local_res18;
  
  local_res8 = 0;
  local_res18.s.Alignment = 0;
  StorPortExtendedFunction
            (0x2f,param_1,&local_res18,&local_res8,unaff_R15,unaff_R14,unaff_RDI,unaff_RSI,unaff_RBP
            );
  plVar1 = (longlong *)(param_1 + 0x3a0);
  uVar8 = 1;
  if (*(short *)(param_1 + 0x14c) != 0) {
    do {
      *(undefined1 *)(param_1 + 0x3eb) = 0;
      memset(*(void **)(param_1 + 0x440),0,0x1080);
      *(undefined8 *)(*(longlong *)(param_1 + 0x440) + 0x1060) = 0;
      *(undefined8 *)(param_1 + 0x420) = *(undefined8 *)(param_1 + 0x440);
      *(undefined4 *)(param_1 + 0x3e0) = 1;
      lVar2 = *(longlong *)(param_1 + 0x440);
      *(undefined2 *)(lVar2 + 0x106c) = 0;
      *(byte *)(lVar2 + 0x1079) = *(byte *)(lVar2 + 0x1079) & 0xfd | 1;
      lVar3 = *plVar1;
      *(undefined1 *)(lVar2 + 0x1000) = 5;
      lVar9 = (ulonglong)uVar8 * 0x188;
      *(undefined8 *)(lVar2 + 0x1018) = *(undefined8 *)(lVar9 + -0x180 + *plVar1);
      *(ushort *)(lVar2 + 0x1028) = uVar8;
      *(short *)(lVar2 + 0x102a) = *(short *)(param_1 + 0x146) + -1;
      uVar4 = *(uint *)(lVar2 + 0x102c);
      *(uint *)(lVar2 + 0x102c) = uVar4 | 1;
      if ((*(char *)(param_1 + 0x14) == '\0') && (*(char *)(lVar9 + -0x90 + lVar3) == '\0')) {
        uVar4 = uVar4 | 3;
      }
      else {
        uVar4 = uVar4 & 0xfffffffd | 1;
      }
      *(uint *)(lVar2 + 0x102c) = uVar4;
      *(undefined2 *)(lVar2 + 0x102e) = *(undefined2 *)(*plVar1 + -0xd8 + lVar9);
      iVar5 = NvmeDumpSynchronousExecuteCommandInAdminQueue(param_1,param_1 + 0x3e0);
      if (iVar5 < 0) {
        uVar6 = 0xc1000001;
        uVar7 = 0x17;
        goto LAB_140006ee0;
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 <= *(ushort *)(param_1 + 0x14c));
  }
  uVar6 = NVMeIoSubmissionQueueCreate(param_1);
  if ((int)uVar6 == 0) {
    uVar6 = 0;
  }
  else {
    uVar7 = 0x16;
LAB_140006ee0:
    *(undefined4 *)(param_1 + 0x1c) = uVar7;
    *plVar1 = 0;
    *(undefined8 *)(param_1 + 0x398) = 0;
    *(undefined4 *)(param_1 + 0x14a) = 0;
  }
  return uVar6;
}



===== IoQueuesDeletion @ 140006f1c =====

bool IoQueuesDeletion(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 *param_4)

{
  undefined4 *puVar1;
  byte *pbVar2;
  longlong lVar3;
  int iVar4;
  bool bVar5;
  ushort uVar6;
  short sVar7;
  undefined8 unaff_R15;
  ushort local_res8 [4];
  undefined8 *in_stack_ffffffffffffffb8;
  undefined4 in_stack_ffffffffffffffc0;
  undefined4 in_stack_ffffffffffffffc4;
  undefined8 in_stack_ffffffffffffffc8;
  undefined8 in_stack_ffffffffffffffd0;
  
  local_res8[0] = 0;
  bVar5 = true;
  if ((uint)*(ushort *)(param_1 + 0x542) + (uint)*(ushort *)(param_1 + 0x540) <
      (uint)*(ushort *)(param_1 + 0x1d8)) {
    do {
      StorPortExtendedFunction
                (0x51,param_1,(PSLIST_HEADER)0x2710,param_4,in_stack_ffffffffffffffb8,
                 CONCAT44(in_stack_ffffffffffffffc4,in_stack_ffffffffffffffc0),
                 in_stack_ffffffffffffffc8,in_stack_ffffffffffffffd0,unaff_R15);
      if ((uint)*(ushort *)(param_1 + 0x1d8) <=
          (uint)*(ushort *)(param_1 + 0x542) + (uint)*(ushort *)(param_1 + 0x540)) break;
      local_res8[0] = local_res8[0] + 1;
    } while (local_res8[0] < 1000);
  }
  local_res8[0] = 0;
  uVar6 = 0;
  if (*(short *)(param_1 + 0x14a) != 0) {
    do {
      uVar6 = 0;
      do {
        StorPortExtendedFunction
                  (0x51,param_1,(PSLIST_HEADER)0x2710,param_4,in_stack_ffffffffffffffb8,
                   CONCAT44(in_stack_ffffffffffffffc4,in_stack_ffffffffffffffc0),
                   in_stack_ffffffffffffffc8,in_stack_ffffffffffffffd0,unaff_R15);
        if (*(short *)((ulonglong)local_res8[0] * 0xc0 + 0x88 + *(longlong *)(param_1 + 0x398)) == 0
           ) break;
        uVar6 = uVar6 + 1;
      } while (uVar6 < 1000);
      uVar6 = *(ushort *)(param_1 + 0x14a);
      local_res8[0] = local_res8[0] + 1;
    } while (local_res8[0] < uVar6);
  }
  local_res8[0] = 0;
  puVar1 = (undefined4 *)(param_1 + 0x3e0);
  if (uVar6 != 0) {
    do {
      *(undefined1 *)(param_1 + 0x3eb) = 0;
      sVar7 = local_res8[0] + 1;
      memset(*(void **)(param_1 + 0x440),0,0x1080);
      *(undefined8 *)(*(longlong *)(param_1 + 0x440) + 0x1060) = 0;
      *(undefined8 *)(param_1 + 0x420) = *(undefined8 *)(param_1 + 0x440);
      *puVar1 = 1;
      pbVar2 = (byte *)(*(longlong *)(param_1 + 0x440) + 0x1079);
      *pbVar2 = *pbVar2 | 1;
      pbVar2 = (byte *)(*(longlong *)(param_1 + 0x440) + 0x1079);
      *pbVar2 = *pbVar2 & 0xfd;
      *(undefined2 *)(*(longlong *)(param_1 + 0x440) + 0x106c) = 0;
      lVar3 = *(longlong *)(param_1 + 0x440);
      *(undefined1 *)(lVar3 + 0x1000) = 0;
      *(short *)(lVar3 + 0x1028) = sVar7;
      iVar4 = NvmeDumpSynchronousExecuteCommandInAdminQueue(param_1,(longlong)puVar1);
      if (iVar4 < 0) {
        *(undefined4 *)(param_1 + 0x1c) = 0xf;
        StorPortExtendedFunction
                  (0x62,param_1,(PSLIST_HEADER)0x0,(undefined8 *)0xa,
                   (undefined8 *)L"IO Submission Queue deletion failed",
                   CONCAT44(in_stack_ffffffffffffffc4,2),local_res8,in_stack_ffffffffffffffd0,
                   unaff_R15);
      }
      bVar5 = iVar4 >= 0;
      local_res8[0] = local_res8[0] + 1;
    } while (local_res8[0] < *(ushort *)(param_1 + 0x14a));
  }
  local_res8[0] = 0;
  if (*(short *)(param_1 + 0x14c) != 0) {
    do {
      *(undefined1 *)(param_1 + 0x3eb) = 0;
      sVar7 = local_res8[0] + 1;
      memset(*(void **)(param_1 + 0x440),0,0x1080);
      *(undefined8 *)(*(longlong *)(param_1 + 0x440) + 0x1060) = 0;
      *(undefined8 *)(param_1 + 0x420) = *(undefined8 *)(param_1 + 0x440);
      *puVar1 = 1;
      pbVar2 = (byte *)(*(longlong *)(param_1 + 0x440) + 0x1079);
      *pbVar2 = *pbVar2 | 1;
      pbVar2 = (byte *)(*(longlong *)(param_1 + 0x440) + 0x1079);
      *pbVar2 = *pbVar2 & 0xfd;
      *(undefined2 *)(*(longlong *)(param_1 + 0x440) + 0x106c) = 0;
      lVar3 = *(longlong *)(param_1 + 0x440);
      *(undefined1 *)(lVar3 + 0x1000) = 4;
      *(short *)(lVar3 + 0x1028) = sVar7;
      iVar4 = NvmeDumpSynchronousExecuteCommandInAdminQueue(param_1,(longlong)puVar1);
      if (iVar4 < 0) {
        *(undefined4 *)(param_1 + 0x1c) = 0x10;
        StorPortExtendedFunction
                  (0x62,param_1,(PSLIST_HEADER)0x0,(undefined8 *)0xa,
                   (undefined8 *)L"IO Completion Queue deletion failed",
                   CONCAT44(in_stack_ffffffffffffffc4,2),local_res8,in_stack_ffffffffffffffd0,
                   unaff_R15);
      }
      bVar5 = iVar4 >= 0;
      local_res8[0] = local_res8[0] + 1;
    } while (local_res8[0] < *(ushort *)(param_1 + 0x14c));
  }
  return bVar5;
}



===== IoQueuesInitialize @ 140007214 =====

ulonglong IoQueuesInitialize(ulonglong param_1)

{
  ushort uVar1;
  ushort uVar2;
  undefined8 *puVar3;
  uint uVar4;
  ulonglong in_RAX;
  void *pvVar5;
  void *pvVar6;
  void *_Dst;
  void *_Dst_00;
  uint uVar7;
  ulonglong uVar8;
  
  if (*(short *)(param_1 + 0x14c) != 0) {
    uVar1 = *(ushort *)(param_1 + 0x14a);
    if (uVar1 != 0) {
      uVar2 = *(ushort *)(param_1 + 0x146);
      pvVar6 = (void *)(**(longlong **)(param_1 + 0x3a0) + (ulonglong)uVar2 * 0x10);
      _Dst_00 = (void *)((ulonglong)uVar2 * (ulonglong)uVar1 * 0x10 + (longlong)pvVar6);
      _Dst = (void *)((ulonglong)*(ushort *)(param_1 + 0x148) * (ulonglong)uVar1 * 0x20 +
                     (longlong)_Dst_00);
      uVar7 = (uint)uVar1 * (uint)uVar2 & 0xfffffff;
      if (uVar7 != 0) {
        memset(pvVar6,0,(ulonglong)(uVar7 << 2) << 2);
      }
      uVar7 = (uint)*(ushort *)(param_1 + 0x148) * (uint)*(ushort *)(param_1 + 0x14a) & 0x7ffffff;
      if (uVar7 != 0) {
        memset(_Dst_00,0,(ulonglong)(uVar7 << 3) << 2);
      }
      pvVar5 = (void *)((ulonglong)*(ushort *)(param_1 + 0x14c) << 1);
      if ((int)pvVar5 != 0) {
        pvVar5 = memset(_Dst,0,(ulonglong)*(ushort *)(param_1 + 0x14c) << 3);
      }
      uVar7 = 0;
      if (*(short *)(param_1 + 0x14a) != 0) {
        do {
          puVar3 = *(undefined8 **)(param_1 + 0x398);
          uVar8 = (ulonglong)uVar7;
          pvVar5 = (void *)*puVar3;
          if (uVar2 != 0) {
            memset(pvVar5,0,(ulonglong)uVar2 << 6);
          }
          NVMeSubmissionQueueInit
                    (param_1,puVar3 + uVar8 * 0x18,(short)uVar7 + 1,(ulonglong)pvVar5,0,
                     (ulonglong)(*(ushort *)(param_1 + 0x146) * uVar8 * 0x10 + (longlong)pvVar6),
                     (ulonglong)(*(ushort *)(param_1 + 0x148) * uVar8 * 0x20 + (longlong)_Dst_00),0)
          ;
          pvVar5 = (void *)(ulonglong)*(ushort *)(param_1 + 0x14a);
          uVar7 = uVar7 + 1;
        } while (uVar7 < *(ushort *)(param_1 + 0x14a));
      }
      uVar7 = 0;
      if (*(short *)(param_1 + 0x14c) != 0) {
        do {
          pvVar5 = (void *)(ulonglong)*(ushort *)(param_1 + 0x14a);
          if (*(ushort *)(param_1 + 0x14a) <= uVar7) break;
          puVar3 = *(undefined8 **)(param_1 + 0x3a0);
          pvVar6 = (void *)*puVar3;
          uVar4 = (uint)((ulonglong)uVar2 * 0x10) >> 2;
          if (uVar4 != 0) {
            memset(pvVar6,0,(ulonglong)uVar4 << 2);
          }
          pvVar5 = (void *)NVMeCompletionQueueInit
                                     (param_1,puVar3 + (ulonglong)uVar7 * 0x31,(short)uVar7 + 1,
                                      (ulonglong)pvVar6,0,
                                      (ulonglong)((longlong)_Dst + (ulonglong)uVar7 * 8),0);
          uVar7 = uVar7 + 1;
        } while (uVar7 < *(ushort *)(param_1 + 0x14c));
      }
      return CONCAT71((int7)((ulonglong)pvVar5 >> 8),1);
    }
  }
  return in_RAX & 0xffffffffffffff00;
}



===== NVMeAllocateDmaBuffer @ 140007478 =====

void NVMeAllocateDmaBuffer(longlong param_1,uint param_2,undefined8 param_3)

{
  ulonglong uVar1;
  int iVar2;
  undefined4 in_stack_ffffffffffffffcc;
  undefined4 in_stack_ffffffffffffffd4;
  
  if ((*(uint *)(param_1 + 0x38) & 2) == 0) {
    iVar2 = *(int *)(param_1 + 0xf4);
  }
  else {
    iVar2 = -0x80000000;
  }
  uVar1 = StorPortExtendedFunction
                    (0x52,param_1,(PSLIST_HEADER)(ulonglong)param_2,(undefined8 *)0x0,
                     (undefined8 *)0x7fffffffffffffff,0,CONCAT44(in_stack_ffffffffffffffcc,1),
                     CONCAT44(in_stack_ffffffffffffffd4,iVar2),param_3);
  if (((int)uVar1 != 0) && (iVar2 != -0x80000000)) {
    StorPortExtendedFunction
              (0x52,param_1,(PSLIST_HEADER)(ulonglong)param_2,(undefined8 *)0x0,
               (undefined8 *)0x7fffffffffffffff,0,CONCAT44(in_stack_ffffffffffffffcc,1),
               CONCAT44(in_stack_ffffffffffffffd4,0x80000000),param_3);
  }
  return;
}



===== NVMeCompletionQueueInit @ 140007554 =====

void NVMeCompletionQueueInit
               (ulonglong param_1,ulonglong *param_2,ushort param_3,ulonglong param_4,
               ulonglong param_5,ulonglong param_6,ulonglong param_7)

{
  ushort uVar1;
  int iVar2;
  longlong lVar3;
  short sVar4;
  undefined4 uVar5;
  ulonglong uVar6;
  undefined4 uVar7;
  undefined1 uVar8;
  int local_res18 [2];
  
  *param_2 = param_4;
  if (param_5 == 0) {
    uVar6 = StorPortGetPhysicalAddress(param_1,0,param_4,local_res18);
    param_2[1] = uVar6;
  }
  else {
    param_2[1] = param_5;
  }
  lVar3 = *(longlong *)(param_1 + 0xb0);
  iVar2 = *(int *)(param_1 + 200);
  *(ushort *)(param_2 + 0x15) = param_3;
  *(undefined4 *)((longlong)param_2 + 0xaa) = 0;
  *(undefined4 *)(param_2 + 0x16) = 0;
  param_2[2] = (ulonglong)(((uint)param_3 * 2 + 1) * iVar2) + lVar3 + 0x1000;
  if (param_6 != 0) {
    param_2[0x18] = param_6;
  }
  *(undefined8 *)((longlong)param_2 + 0xb4) = 0;
  uVar8 = 1;
  if (*(short *)(param_1 + 0x14c) != 0) {
    *(ushort *)(param_2 + 0x19) = (ushort)(param_2[0x18] != 0);
    uVar1 = *(ushort *)(param_1 + 0x14a);
    if (*(ushort *)(param_1 + 0xea) <= *(ushort *)(param_1 + 0x14a)) {
      uVar1 = *(ushort *)(param_1 + 0xea);
    }
    *(short *)((longlong)param_2 + 0xca) =
         (short)((int)(uVar1 - 1) / (int)(uint)*(ushort *)(param_1 + 0x14c)) + 1;
  }
  uVar7 = 0xffffffff;
  if ((short)param_2[0x19] == 0) {
    uVar5 = 0xffffffff;
  }
  else {
    uVar5 = *(undefined4 *)(param_1 + 0xf20);
  }
  *(undefined4 *)((longlong)param_2 + 0xcc) = uVar5;
  if (*(short *)((longlong)param_2 + 0xca) == 0) {
    uVar5 = 0xffffffff;
  }
  else {
    uVar5 = *(undefined4 *)(param_1 + 0xf24);
  }
  *(undefined4 *)(param_2 + 0x1a) = uVar5;
  if (param_7 != 0) {
    param_2[0x1c] = param_7;
  }
  *(undefined8 *)((longlong)param_2 + 0xd4) = 0;
  if (*(short *)(param_1 + 0x14c) != 0) {
    *(ushort *)(param_2 + 0x1d) = (ushort)(param_2[0x1c] != 0);
    sVar4 = 0;
    if (*(ushort *)(param_1 + 0xea) < *(ushort *)(param_1 + 0x14a)) {
      sVar4 = (short)((int)(((uint)*(ushort *)(param_1 + 0x14a) - (uint)*(ushort *)(param_1 + 0xea))
                           + -1) / (int)(uint)*(ushort *)(param_1 + 0x14c)) + 1;
    }
    *(short *)((longlong)param_2 + 0xea) = sVar4;
  }
  if ((short)param_2[0x1d] == 0) {
    uVar5 = 0xffffffff;
  }
  else {
    uVar5 = *(undefined4 *)(param_1 + 0xf28);
  }
  *(undefined4 *)((longlong)param_2 + 0xec) = uVar5;
  if (*(short *)((longlong)param_2 + 0xea) != 0) {
    uVar7 = *(undefined4 *)(param_1 + 0xf2c);
  }
  *(undefined4 *)(param_2 + 0x1e) = uVar7;
  if ((param_3 == 0) || (*(ushort *)(param_1 + 0x14e) < param_3)) {
    uVar8 = 0;
  }
  else {
    *(undefined4 *)((longlong)param_2 + 0xfc) = 0;
    param_2[0x2a] = param_1;
    param_2[0x2b] = (ulonglong)param_2;
  }
  *(undefined1 *)(param_2 + 0x1f) = uVar8;
  return;
}



===== NVMeControllerGetFeaturesSupportedCacheCapabilities @ 140007754 =====

void NVMeControllerGetFeaturesSupportedCacheCapabilities(longlong param_1)

{
  byte *pbVar1;
  longlong lVar2;
  int iVar3;
  
  if (((*(byte *)(*(longlong *)(param_1 + 0x548) + 0x20d) & 1) != 0) &&
     (((1 < *(ushort *)(param_1 + 0xba) || (*(char *)(param_1 + 0xb9) != '\0')) &&
      ((*(byte *)(*(longlong *)(param_1 + 0x548) + 0x208) & 0x10) != 0)))) {
    *(undefined1 *)(param_1 + 0x3eb) = 0;
    memset(*(void **)(param_1 + 0x440),0,0x1080);
    *(undefined8 *)(*(longlong *)(param_1 + 0x440) + 0x1060) = 0;
    *(undefined8 *)(param_1 + 0x420) = *(undefined8 *)(param_1 + 0x440);
    *(undefined4 *)(param_1 + 0x3e0) = 1;
    pbVar1 = (byte *)(*(longlong *)(param_1 + 0x440) + 0x1079);
    *pbVar1 = *pbVar1 | 1;
    pbVar1 = (byte *)(*(longlong *)(param_1 + 0x440) + 0x1079);
    *pbVar1 = *pbVar1 & 0xfd;
    pbVar1 = (byte *)(*(longlong *)(param_1 + 0x440) + 0x1079);
    *pbVar1 = *pbVar1 & 0xfb;
    *(undefined2 *)(*(longlong *)(param_1 + 0x440) + 0x106c) = 0;
    lVar2 = *(longlong *)(param_1 + 0x440);
    *(undefined1 *)(lVar2 + 0x1028) = 6;
    *(undefined1 *)(lVar2 + 0x1000) = 10;
    *(uint *)(lVar2 + 0x1028) = *(uint *)(lVar2 + 0x1028) & 0xfffffbff | 0x300;
    *(code **)(*(longlong *)(param_1 + 0x440) + 0x1058) =
         NVMeGetFeaturesSupportedCacheCapabilitiesCompletion;
    iVar3 = NvmeDumpSynchronousExecuteCommandInAdminQueue(param_1,param_1 + 0x3e0);
    if (-1 < iVar3) {
      *(byte *)(param_1 + 0xea4) = *(byte *)(param_1 + 0xea4) & 0xfb;
    }
  }
  return;
}



===== NVMeControllerIdentify @ 140007884 =====

void NVMeControllerIdentify(longlong param_1)

{
  byte *pbVar1;
  longlong lVar2;
  undefined8 uVar3;
  char cVar4;
  int iVar5;
  
  *(undefined1 *)(param_1 + 0x3eb) = 0;
  memset(*(void **)(param_1 + 0x440),0,0x1080);
  iVar5 = 0;
  *(undefined8 *)(*(longlong *)(param_1 + 0x440) + 0x1060) = 0;
  *(undefined8 *)(param_1 + 0x420) = *(undefined8 *)(param_1 + 0x440);
  *(undefined4 *)(param_1 + 0x3e0) = 1;
  do {
    cVar4 = (char)iVar5;
    iVar5 = iVar5 + 1;
    pbVar1 = (byte *)(*(longlong *)(param_1 + 0x440) + 0x1079);
    *pbVar1 = *pbVar1 | cVar4 + 1U;
  } while (iVar5 < 2);
  *(undefined2 *)(*(longlong *)(param_1 + 0x440) + 0x106c) = 0;
  lVar2 = *(longlong *)(param_1 + 0x440);
  uVar3 = *(undefined8 *)(param_1 + 0x550);
  *(undefined1 *)(lVar2 + 0x1000) = 6;
  *(undefined4 *)(lVar2 + 0x1004) = 0;
  *(undefined8 *)(lVar2 + 0x1018) = uVar3;
  *(undefined1 *)(lVar2 + 0x1028) = 1;
  NvmeDumpSynchronousExecuteCommandInAdminQueue(param_1,param_1 + 0x3e0);
  return;
}



===== NVMeControllerInitPart1 @ 140007944 =====

int NVMeControllerInitPart1(ulonglong param_1)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  uint uVar6;
  undefined1 local_68 [96];
  
  memset(local_68,0,0x58);
  uVar5 = AdminQueueInitialize(param_1);
  if ((char)uVar5 == '\0') {
    *(undefined4 *)(param_1 + 0x1c) = 7;
    iVar4 = -0x3effffff;
  }
  else {
    uVar3 = *(ushort *)(param_1 + 0x144) - 1 & 0xfff;
    *(uint *)(*(longlong *)(param_1 + 0xb0) + 0x24) = uVar3 << 0x10 | uVar3;
    LOCK();
    UNLOCK();
    lVar2 = *(longlong *)(param_1 + 0xb0);
    uVar5 = *(undefined8 *)(param_1 + 0x218);
    *(int *)(lVar2 + 0x30) = (int)uVar5;
    LOCK();
    UNLOCK();
    *(int *)(lVar2 + 0x34) = (int)((ulonglong)uVar5 >> 0x20);
    LOCK();
    UNLOCK();
    lVar2 = *(longlong *)(param_1 + 0xb0);
    uVar5 = *(undefined8 *)(param_1 + 0x158);
    *(int *)(lVar2 + 0x28) = (int)uVar5;
    LOCK();
    UNLOCK();
    *(int *)(lVar2 + 0x2c) = (int)((ulonglong)uVar5 >> 0x20);
    LOCK();
    UNLOCK();
    if (((*(ulonglong *)(param_1 + 0xc0) >> 0x11 & 1) == 0) ||
       ((*(uint *)(param_1 + 0x38) & 0x400) == 0)) {
      uVar3 = 0;
    }
    else {
      uVar3 = 0x800;
    }
    uVar6 = uVar3 | 0x60;
    if ((*(ulonglong *)(param_1 + 0xc0) & 0x80000000000) == 0) {
      uVar6 = uVar3;
    }
    *(uint *)(*(longlong *)(param_1 + 0xb0) + 0x14) = uVar6 | 0x460000;
    LOCK();
    UNLOCK();
    KeStallExecutionProcessor(5000);
    uVar3 = *(uint *)(param_1 + 0xcc);
    *(uint *)(*(longlong *)(param_1 + 0xb0) + 0x14) =
         *(uint *)(*(longlong *)(param_1 + 0xb0) + 0x14) | 1;
    LOCK();
    UNLOCK();
    for (uVar6 = 0;
        (uVar1 = *(uint *)(*(longlong *)(param_1 + 0xb0) + 0x1c), (uVar1 & 1) == 0 &&
        (uVar6 < uVar3 / 10)); uVar6 = uVar6 + 1) {
      KeStallExecutionProcessor(10000);
    }
    if ((uVar1 & 1) == 0) {
      iVar4 = -0x3effffff;
      *(undefined4 *)(param_1 + 0x1c) = 8;
    }
    else {
      *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) & 0xffffffdf;
      iVar4 = NVMeControllerIdentify(param_1);
      if (iVar4 == 0) {
        NVMeGetControllerIoCommandSetIdentify(param_1);
        if (*(char *)(param_1 + 0x14) == '\0') {
          NVMeGetNVMSetAttributeList(param_1);
        }
        NVMeNameSpaceIdentify(param_1);
        *(int *)(param_1 + 0xf88) = *(int *)(param_1 + 0xf88) + 1;
        *(undefined4 *)(param_1 + 0xe8) = 0x10001;
        return 0;
      }
      *(undefined4 *)(param_1 + 0x1c) = 0x1e;
    }
  }
  *(int *)(param_1 + 0xf8c) = *(int *)(param_1 + 0xf8c) + 1;
  return iVar4;
}



===== NVMeControllerInitPart3 @ 140007b30 =====

undefined8 NVMeControllerInitPart3(longlong param_1)

{
  byte *pbVar1;
  byte bVar2;
  longlong lVar3;
  longlong lVar4;
  ulonglong uVar5;
  uint7 extraout_var;
  
  lVar3 = *(longlong *)(param_1 + 0x548);
  if ((*(byte *)(lVar3 + 0x208) & 0x40) != 0) {
    NVMeSyncHostTime(param_1);
  }
  uVar5 = *(ulonglong *)(param_1 + 0x548);
  if ((*(byte *)(uVar5 + 0x20d) & 1) != 0) {
    bVar2 = *(byte *)(param_1 + 0xea4);
    uVar5 = CONCAT71((int7)(uVar5 >> 8),bVar2) & 0xffffffffffffff06;
    if ((char)uVar5 == '\x02') {
      *(undefined1 *)(param_1 + 0x3eb) = 0;
      memset(*(void **)(param_1 + 0x440),0,0x1080);
      *(undefined8 *)(*(longlong *)(param_1 + 0x440) + 0x1060) = 0;
      *(undefined8 *)(param_1 + 0x420) = *(undefined8 *)(param_1 + 0x440);
      *(undefined4 *)(param_1 + 0x3e0) = 1;
      pbVar1 = (byte *)(*(longlong *)(param_1 + 0x440) + 0x1079);
      *pbVar1 = *pbVar1 | 1;
      pbVar1 = (byte *)(*(longlong *)(param_1 + 0x440) + 0x1079);
      *pbVar1 = *pbVar1 & 0xfd;
      pbVar1 = (byte *)(*(longlong *)(param_1 + 0x440) + 0x1079);
      *pbVar1 = *pbVar1 & 0xfb;
      *(undefined2 *)(*(longlong *)(param_1 + 0x440) + 0x106c) = 0;
      lVar4 = *(longlong *)(param_1 + 0x440);
      *(undefined1 *)(lVar4 + 0x1000) = 9;
      *(undefined1 *)(lVar4 + 0x1028) = 6;
      *(uint *)(lVar4 + 0x102c) =
           ((uint)bVar2 ^ *(uint *)(lVar4 + 0x102c)) & 1 ^ *(uint *)(lVar4 + 0x102c);
      *(code **)(*(longlong *)(param_1 + 0x440) + 0x1058) = NVMeSetFeaturesCacheCompletion;
      uVar5 = NvmeDumpSynchronousExecuteCommandInAdminQueue(param_1,param_1 + 0x3e0);
    }
  }
  if ((*(byte *)(lVar3 + 0x208) & 0x20) != 0) {
    NVMeControllerSetHostIdentifier(param_1);
    uVar5 = (ulonglong)extraout_var << 8;
  }
  *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) & 0xffddffff | 0x201;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  return CONCAT71((int7)(uVar5 >> 8),1);
}



===== NVMeControllerSetHostIdentifier @ 140007c94 =====

bool NVMeControllerSetHostIdentifier(longlong param_1)

{
  byte *pbVar1;
  byte bVar2;
  longlong lVar3;
  char cVar4;
  int iVar5;
  undefined8 unaff_RSI;
  undefined8 unaff_RDI;
  undefined8 unaff_R14;
  bool bVar6;
  PSLIST_HEADER local_res8;
  longlong local_res10;
  undefined4 in_stack_ffffffffffffffdc;
  
  bVar2 = *(byte *)(param_1 + 0xee0);
  local_res8 = (PSLIST_HEADER)&((PSLIST_HEADER)0x0)->s;
  local_res10 = 0;
  bVar6 = false;
  if ((bVar2 & 1) != 0) {
    if (((*(uint *)(*(longlong *)(param_1 + 0x548) + 0x60) & 1) != 0) && ((bVar2 & 2) != 0)) {
      *(byte *)(param_1 + 0xee0) = bVar2 | 8;
    }
    *(undefined1 *)(param_1 + 0x3eb) = 0;
    memset(*(void **)(param_1 + 0x440),0,0x1080);
    iVar5 = 0;
    *(undefined8 *)(*(longlong *)(param_1 + 0x440) + 0x1060) = 0;
    *(undefined8 *)(param_1 + 0x420) = *(undefined8 *)(param_1 + 0x440);
    *(undefined4 *)(param_1 + 0x3e0) = 1;
    do {
      cVar4 = (char)iVar5;
      iVar5 = iVar5 + 1;
      pbVar1 = (byte *)(*(longlong *)(param_1 + 0x440) + 0x1079);
      *pbVar1 = *pbVar1 | cVar4 + 1U;
    } while (iVar5 < 2);
    pbVar1 = (byte *)(*(longlong *)(param_1 + 0x440) + 0x1079);
    *pbVar1 = *pbVar1 | 4;
    *(undefined2 *)(*(longlong *)(param_1 + 0x440) + 0x106c) = 0;
    bVar2 = *(byte *)(param_1 + 0xee0);
    NVMeAllocateDmaBuffer(param_1,0x10,&local_res8);
    if (local_res8 != (PSLIST_HEADER)0x0) {
      (local_res8->s).Alignment = 0;
      (local_res8->s).Region = 0;
      memmove(local_res8,(void *)(param_1 + 0xee1),(ulonglong)(-(uint)((bVar2 & 8) != 0) & 8) + 8);
      *(_struct_314 **)(*(longlong *)(param_1 + 0x440) + 0x1040) = &local_res8->s;
      *(longlong *)(*(longlong *)(param_1 + 0x440) + 0x1048) = local_res10;
      *(undefined4 *)(*(longlong *)(param_1 + 0x440) + 0x1068) = 0x10;
      bVar2 = *(byte *)(param_1 + 0xee0);
      lVar3 = *(longlong *)(param_1 + 0x440);
      *(undefined1 *)(lVar3 + 0x1000) = 9;
      *(undefined1 *)(lVar3 + 0x1028) = 0x81;
      *(uint *)(lVar3 + 0x102c) =
           ((uint)(bVar2 >> 3) ^ *(uint *)(lVar3 + 0x102c)) & 1 ^ *(uint *)(lVar3 + 0x102c);
      *(undefined8 *)(lVar3 + 0x1018) = *(undefined8 *)(lVar3 + 0x1048);
      iVar5 = NvmeDumpSynchronousExecuteCommandInAdminQueue(param_1,param_1 + 0x3e0);
      bVar6 = -1 < iVar5;
      if (bVar6) {
        *(byte *)(param_1 + 0xee0) = *(byte *)(param_1 + 0xee0) | 4;
      }
      if ((local_res8 != (PSLIST_HEADER)0x0) && (local_res10 != 0)) {
        StorPortExtendedFunction
                  (0x53,param_1,local_res8,(undefined8 *)0x10,
                   (undefined8 *)CONCAT44(in_stack_ffffffffffffffdc,1),local_res10,unaff_R14,
                   unaff_RDI,unaff_RSI);
      }
    }
  }
  return bVar6;
}



===== NVMeGetControllerIoCommandSetIdentify @ 140007e8c =====

void NVMeGetControllerIoCommandSetIdentify(longlong param_1)

{
  byte *pbVar1;
  undefined1 *puVar2;
  longlong lVar3;
  undefined8 uVar4;
  char cVar5;
  int iVar6;
  
  puVar2 = *(undefined1 **)(param_1 + 0x5a8);
  *(undefined1 *)(param_1 + 0x3eb) = 0;
  memset(*(void **)(param_1 + 0x440),0,0x1080);
  iVar6 = 0;
  *(undefined8 *)(*(longlong *)(param_1 + 0x440) + 0x1060) = 0;
  *(undefined8 *)(param_1 + 0x420) = *(undefined8 *)(param_1 + 0x440);
  *(undefined4 *)(param_1 + 0x3e0) = 1;
  do {
    cVar5 = (char)iVar6;
    iVar6 = iVar6 + 1;
    pbVar1 = (byte *)(*(longlong *)(param_1 + 0x440) + 0x1079);
    *pbVar1 = *pbVar1 | cVar5 + 1U;
  } while (iVar6 < 2);
  *(undefined2 *)(*(longlong *)(param_1 + 0x440) + 0x106c) = 0;
  lVar3 = *(longlong *)(param_1 + 0x440);
  uVar4 = *(undefined8 *)(param_1 + 0x5b0);
  *(undefined4 *)(lVar3 + 0x1004) = 0xffffffff;
  *(undefined1 *)(lVar3 + 0x1000) = 6;
  *(undefined8 *)(lVar3 + 0x1018) = uVar4;
  *(undefined1 *)(lVar3 + 0x1028) = 6;
  *(undefined4 *)(lVar3 + 0x102a) = 0;
  *(undefined1 *)(lVar3 + 0x102f) = 0;
  iVar6 = NvmeDumpSynchronousExecuteCommandInAdminQueue(param_1,param_1 + 0x3e0);
  if (-1 < iVar6) {
    *(undefined1 *)(param_1 + 0xf10) = *puVar2;
    *(undefined1 *)(param_1 + 0xf11) = puVar2[1];
    *(undefined1 *)(param_1 + 0xf12) = puVar2[2];
    *(undefined1 *)(param_1 + 0xf13) = puVar2[3];
    *(undefined4 *)(param_1 + 0xf14) = *(undefined4 *)(puVar2 + 4);
    *(undefined8 *)(param_1 + 0xf18) = *(undefined8 *)(puVar2 + 8);
  }
  return;
}



===== NVMeGetFeaturesSupportedCacheCapabilitiesCompletion @ 140007fb0 =====

void NVMeGetFeaturesSupportedCacheCapabilitiesCompletion
               (longlong param_1,longlong param_2,byte *param_3)

{
  ulonglong uVar1;
  
  if (*(char *)(param_2 + 2) == '(') {
    uVar1 = *(ulonglong *)(param_2 + 0x68);
  }
  else {
    uVar1 = *(ulonglong *)(param_2 + 0x38);
  }
  if ((uVar1 & 0xfff) != 0) {
    uVar1 = (uVar1 - ((uint)uVar1 & 0xfff)) + 0x1000;
  }
  if (*(char *)(param_2 + 3) == '\x01') {
    if (param_3 == (byte *)0x0) {
      *(undefined1 *)(param_2 + 3) = 4;
    }
    else {
      *(byte *)(param_1 + 0xea4) = (*param_3 & 1) << 2 | *(byte *)(param_1 + 0xea4) & 0xfb;
    }
  }
  *(byte *)(uVar1 + 0x1079) = *(byte *)(uVar1 + 0x1079) | 8;
  return;
}



===== NVMeGetNVMSetAttributeList @ 140008014 =====

void NVMeGetNVMSetAttributeList(longlong param_1)

{
  longlong *plVar1;
  byte *pbVar2;
  longlong lVar3;
  longlong lVar4;
  char cVar5;
  uint uVar6;
  ulonglong uVar7;
  uint uVar8;
  int iVar9;
  undefined8 unaff_R13;
  undefined8 unaff_R14;
  ushort uVar10;
  undefined8 unaff_R15;
  undefined8 in_stack_ffffffffffffffd0;
  
  lVar3 = *(longlong *)(param_1 + 0x548);
  if (((*(uint *)(lVar3 + 0x60) & 4) == 0) || (*(ushort *)(lVar3 + 0x152) == 0)) {
    *(undefined8 *)(param_1 + 0xec0) = 0;
  }
  else {
    plVar1 = (longlong *)(param_1 + 0xec0);
    uVar7 = StorPortExtendedFunction
                      (0,param_1,(PSLIST_HEADER)((ulonglong)*(ushort *)(lVar3 + 0x152) << 7),
                       (undefined8 *)0x656d764e,plVar1,in_stack_ffffffffffffffd0,unaff_R15,unaff_R14
                       ,unaff_R13);
    if ((((int)uVar7 == 0) && (*plVar1 != 0)) && (uVar7 = 0, *(short *)(lVar3 + 0x152) != 0)) {
      do {
        *(undefined1 *)(param_1 + 0x3eb) = 0;
        memset(*(void **)(param_1 + 0x440),0,0x1080);
        iVar9 = 0;
        *(undefined8 *)(*(longlong *)(param_1 + 0x440) + 0x1060) = 0;
        *(undefined8 *)(param_1 + 0x420) = *(undefined8 *)(param_1 + 0x440);
        *(undefined4 *)(param_1 + 0x3e0) = 1;
        do {
          cVar5 = (char)iVar9;
          iVar9 = iVar9 + 1;
          pbVar2 = (byte *)(*(longlong *)(param_1 + 0x440) + 0x1079);
          *pbVar2 = *pbVar2 | cVar5 + 1U;
        } while (iVar9 < 2);
        *(undefined2 *)(*(longlong *)(param_1 + 0x440) + 0x106c) = 0;
        lVar4 = *(longlong *)(param_1 + 0x440);
        *(undefined8 *)(lVar4 + 0x1018) = *(undefined8 *)(param_1 + 0x5b0);
        *(short *)(lVar4 + 0x102c) = (short)uVar7 + 1;
        *(undefined1 *)(lVar4 + 0x1000) = 6;
        *(undefined4 *)(lVar4 + 0x1004) = 0;
        *(undefined1 *)(lVar4 + 0x1028) = 4;
        iVar9 = NvmeDumpSynchronousExecuteCommandInAdminQueue(param_1,param_1 + 0x3e0);
        if (iVar9 < 0) {
          return;
        }
        pbVar2 = *(byte **)(param_1 + 0x5a8);
        uVar8 = (uint)*(ushort *)(lVar3 + 0x152) - (int)uVar7;
        uVar6 = (uint)*pbVar2;
        if ((int)uVar8 <= (int)(uint)*pbVar2) {
          uVar6 = uVar8;
        }
        memmove((void *)(uVar7 * 0x80 + *plVar1),pbVar2 + 0x80,(longlong)(int)uVar6 << 7);
        uVar10 = (short)uVar7 + (ushort)*pbVar2;
        uVar7 = (ulonglong)uVar10;
      } while (uVar10 < *(ushort *)(lVar3 + 0x152));
    }
  }
  return;
}



===== NVMeIoSubmissionQueueCreate @ 1400081c4 =====

undefined8 NVMeIoSubmissionQueueCreate(longlong param_1)

{
  longlong lVar1;
  int iVar2;
  ushort uVar3;
  
  uVar3 = 1;
  if (*(short *)(param_1 + 0x14a) != 0) {
    do {
      *(undefined1 *)(param_1 + 0x3eb) = 0;
      memset(*(void **)(param_1 + 0x440),0,0x1080);
      *(undefined8 *)(*(longlong *)(param_1 + 0x440) + 0x1060) = 0;
      *(undefined8 *)(param_1 + 0x420) = *(undefined8 *)(param_1 + 0x440);
      *(undefined4 *)(param_1 + 0x3e0) = 1;
      lVar1 = *(longlong *)(param_1 + 0x440);
      *(undefined2 *)(lVar1 + 0x106c) = 0;
      *(undefined1 *)(lVar1 + 0x1000) = 1;
      *(byte *)(lVar1 + 0x1079) = *(byte *)(lVar1 + 0x1079) & 0xfd | 1;
      *(undefined8 *)(lVar1 + 0x1018) =
           *(undefined8 *)(*(longlong *)(param_1 + 0x398) + -0xb8 + (ulonglong)uVar3 * 0xc0);
      *(ushort *)(lVar1 + 0x1028) = uVar3;
      *(short *)(lVar1 + 0x102a) = *(short *)(param_1 + 0x146) + -1;
      *(uint *)(lVar1 + 0x102c) = *(uint *)(lVar1 + 0x102c) & 0xfffffffd | 5;
      *(undefined2 *)(lVar1 + 0x102e) =
           *(undefined2 *)(*(longlong *)(param_1 + 0x398) + -0x86 + (ulonglong)uVar3 * 0xc0);
      iVar2 = NvmeDumpSynchronousExecuteCommandInAdminQueue(param_1,param_1 + 0x3e0);
      if (iVar2 < 0) {
        return 0xc1000001;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 <= *(ushort *)(param_1 + 0x14a));
  }
  return 0;
}



===== NVMeNameSpaceIdentify @ 140008304 =====

void NVMeNameSpaceIdentify(longlong param_1)

{
  byte *pbVar1;
  ushort uVar2;
  longlong lVar3;
  longlong lVar4;
  longlong *plVar5;
  longlong lVar6;
  undefined4 *puVar7;
  char cVar8;
  bool bVar9;
  bool bVar10;
  int iVar11;
  undefined4 uVar12;
  uint uVar13;
  uint uVar14;
  bool bVar15;
  
  lVar3 = *(longlong *)(param_1 + 0x548);
  uVar12 = 0;
  lVar4 = *(longlong *)(param_1 + 0xec0);
  uVar2 = *(ushort *)(param_1 + 0xba);
  if (((uVar2 == 1) && (*(char *)(param_1 + 0xb9) != '\0')) || (1 < uVar2)) {
    bVar9 = true;
  }
  else {
    bVar9 = false;
  }
  if (((*(uint *)(param_1 + 0x38) & 0x100000) != 0) || (bVar10 = false, 1 < uVar2)) {
    bVar10 = true;
  }
  uVar13 = *(uint *)(lVar3 + 0x204);
  plVar5 = *(longlong **)(param_1 + 0x5a8);
  if (0xff < uVar13) {
    uVar13 = 0xff;
  }
  if (uVar13 != 0) {
    uVar14 = 1;
    do {
      if (*(uint *)(param_1 + 0xd8) == uVar14) {
        *(undefined1 *)(param_1 + 0x3eb) = 0;
        memset(*(void **)(param_1 + 0x440),0,0x1080);
        iVar11 = 0;
        *(undefined8 *)(*(longlong *)(param_1 + 0x440) + 0x1060) = 0;
        *(undefined8 *)(param_1 + 0x420) = *(undefined8 *)(param_1 + 0x440);
        *(undefined4 *)(param_1 + 0x3e0) = 1;
        do {
          cVar8 = (char)iVar11;
          iVar11 = iVar11 + 1;
          pbVar1 = (byte *)(*(longlong *)(param_1 + 0x440) + 0x1079);
          *pbVar1 = *pbVar1 | cVar8 + 1U;
        } while (iVar11 < 2);
        *(undefined2 *)(*(longlong *)(param_1 + 0x440) + 0x106c) = 0;
        lVar6 = *(longlong *)(param_1 + 0x440);
        *(undefined8 *)(lVar6 + 0x1018) = *(undefined8 *)(param_1 + 0x5b0);
        *(bool *)(lVar6 + 0x1028) = uVar14 == 0;
        *(undefined1 *)(lVar6 + 0x1000) = 6;
        *(uint *)(lVar6 + 0x1004) = uVar14;
        iVar11 = NvmeDumpSynchronousExecuteCommandInAdminQueue(param_1,param_1 + 0x3e0);
        if (-1 < iVar11) {
          if (((bVar9) &&
              (*(char *)((longlong)plVar5 +
                        (ulonglong)(*(byte *)((longlong)plVar5 + 0x1a) & 0xf) * 4 + 0x82) == '\0'))
             && (*plVar5 == 0)) {
            if (((bVar10) && (*(char *)(param_1 + 0x14) == '\0')) ||
               ((1 < uVar13 && (*(char *)(param_1 + 0x14) == '\0')))) break;
            *(uint *)(param_1 + 0xf08) = *(uint *)(param_1 + 0xf08) | 0x40;
          }
          puVar7 = *(undefined4 **)(param_1 + 0x558);
          *(undefined4 **)(param_1 + 0x558) = puVar7 + 0x6a;
          NVMeParseNameSpaceIdentifyData(param_1,plVar5,lVar3,lVar4,uVar14,puVar7);
          *(undefined4 **)(param_1 + 0x5b8 + (ulonglong)(uVar14 - 1) * 8) = puVar7;
          uVar12 = 1;
          *(uint *)(param_1 + 0xe0) = uVar14 & 0xffff;
        }
        break;
      }
      bVar15 = uVar14 < uVar13;
      uVar14 = uVar14 + 1;
    } while (bVar15);
  }
  *(undefined4 *)(param_1 + 0xd4) = uVar12;
  return;
}



===== NVMeParseNameSpaceIdentifyData @ 140008500 =====

ulonglong NVMeParseNameSpaceIdentifyData
                    (longlong param_1,undefined8 *param_2,longlong param_3,longlong param_4,
                    undefined4 param_5,undefined4 *param_6)

{
  ushort uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  
  memset(param_6,0,0x1a8);
  *(byte *)(param_6 + 0x10) = *(byte *)((longlong)param_2 + 0x1a) & 0xf;
  uVar6 = 0xffffffff;
  uVar7 = 0xffffffff;
  param_6[0xc] = *(undefined4 *)
                  ((longlong)param_2 +
                  (ulonglong)(*(byte *)((longlong)param_2 + 0x1a) & 0xf) * 4 + 0x80);
  iVar8 = 1 << (*(byte *)((longlong)param_6 + 0x32) & 0x1f);
  param_6[0xd] = iVar8;
  *(undefined8 *)(param_6 + 0xe) = *param_2;
  *(byte *)((longlong)param_6 + 0x41) = *(byte *)(param_2 + 3) & 1;
  *(byte *)((longlong)param_6 + 0x42) = *(byte *)((longlong)param_2 + 0x1d) & 7;
  *(undefined2 *)(param_6 + 0x17) = *(undefined2 *)((longlong)param_2 + 0x2e);
  uVar1 = *(ushort *)((longlong)param_2 + 100);
  *(ushort *)((longlong)param_6 + 0x5e) = uVar1;
  *(undefined2 *)(param_6 + 0x18) = *(undefined2 *)((longlong)param_2 + 0x66);
  *(undefined1 *)(param_6 + 0x1c) = *(undefined1 *)((longlong)param_2 + 0x1f);
  *(undefined8 *)(param_6 + 0x15) = param_2[0xf];
  uVar2 = param_2[0xd];
  uVar3 = param_2[0xe];
  *param_6 = 1;
  *(char *)((longlong)param_6 + 10) = (char)param_5 + -1;
  *(undefined8 *)(param_6 + 0x11) = uVar2;
  *(undefined8 *)(param_6 + 0x13) = uVar3;
  param_6[1] = 4;
  *(undefined2 *)(param_6 + 2) = 0;
  param_6[4] = param_5;
  *(undefined8 *)(param_6 + 0x19) = 0;
  param_6[0x1b] = 0;
  *(undefined8 *)(param_6 + 0x28) = 0;
  if (*(byte *)(param_3 + 0x4d) != 0) {
    uVar7 = (1 << (*(byte *)(param_1 + 0xc6) & 0xf) + 0xc) *
            (1 << (*(byte *)(param_3 + 0x4d) & 0x1f));
  }
  uVar4 = (ulonglong)*(uint *)(param_3 + 0x60);
  if ((((*(uint *)(param_3 + 0x60) & 4) != 0) && (param_4 != 0)) &&
     (uVar1 <= *(ushort *)(param_3 + 0x152))) {
    uVar4 = (ulonglong)uVar1 * 0x80;
    uVar5 = *(uint *)((uVar4 - 0x74) + param_4);
    uVar6 = 0xffffffff;
    if (uVar5 != 0) {
      uVar6 = uVar5;
    }
  }
  if ((*(byte *)(param_2 + 3) & 0x10) == 0) {
    uVar4 = (ulonglong)(uVar6 - 0x8000);
    if (uVar6 - 0x8000 < 0xffff7fff) {
      param_6[0x19] = uVar6;
    }
    if ((*(byte *)(param_2 + 3) & 0x10) == 0) {
      return uVar4;
    }
  }
  uVar5 = (*(ushort *)(param_2 + 9) + 1) * iVar8;
  if (uVar5 <= uVar7) {
    if (uVar6 < uVar5) {
      uVar5 = uVar6;
    }
    if (((uVar5 != 0xffffffff) && (((*(uint *)(param_1 + 0x38) & 0x8000) != 0 || (0x7fff < uVar5))))
       && (uVar6 = (*(ushort *)(param_2 + 8) + 1) * iVar8, uVar6 <= uVar7)) {
      uVar7 = (*(ushort *)((longlong)param_2 + 0x42) + 1) * iVar8;
      uVar4 = (ulonglong)uVar6 / (ulonglong)uVar7;
      if (uVar6 % uVar7 == 0) {
        param_6[0x19] = uVar5;
        param_6[0x1a] = uVar6;
        param_6[0x1b] = uVar7;
        param_6[0x28] = *(ushort *)((longlong)param_2 + 0x44) + 1;
        uVar6 = *(ushort *)((longlong)param_2 + 0x46) + 1;
        uVar4 = (ulonglong)uVar6;
        param_6[0x29] = uVar6;
      }
    }
  }
  return uVar4;
}



===== NVMeSetFeaturesCacheCompletion @ 1400086f0 =====

void NVMeSetFeaturesCacheCompletion(undefined8 param_1,longlong param_2,longlong param_3)

{
  ulonglong uVar1;
  
  if (*(char *)(param_2 + 2) == '(') {
    uVar1 = *(ulonglong *)(param_2 + 0x68);
  }
  else {
    uVar1 = *(ulonglong *)(param_2 + 0x38);
  }
  if ((uVar1 & 0xfff) != 0) {
    uVar1 = (uVar1 - ((uint)uVar1 & 0xfff)) + 0x1000;
  }
  if ((*(char *)(param_2 + 3) == '\x01') && (param_3 == 0)) {
    *(undefined1 *)(param_2 + 3) = 4;
  }
  *(byte *)(uVar1 + 0x1079) = *(byte *)(uVar1 + 0x1079) | 8;
  return;
}



===== NVMeSetIoQueueCount @ 140008734 =====

undefined8 NVMeSetIoQueueCount(longlong param_1,char param_2)

{
  byte *pbVar1;
  longlong lVar2;
  int iVar3;
  undefined8 uVar4;
  short sVar5;
  short sVar6;
  
  if (param_2 == '\0') {
    *(undefined4 *)(param_1 + 0x14a) = 0;
    sVar6 = 1;
    sVar5 = 1;
  }
  else {
    sVar6 = *(short *)(param_1 + 0x14a);
    sVar5 = *(short *)(param_1 + 0x14c);
  }
  *(undefined1 *)(param_1 + 0x3eb) = 0;
  memset(*(void **)(param_1 + 0x440),0,0x1080);
  *(undefined8 *)(*(longlong *)(param_1 + 0x440) + 0x1060) = 0;
  *(undefined8 *)(param_1 + 0x420) = *(undefined8 *)(param_1 + 0x440);
  *(undefined4 *)(param_1 + 0x3e0) = 1;
  pbVar1 = (byte *)(*(longlong *)(param_1 + 0x440) + 0x1079);
  *pbVar1 = *pbVar1 | 1;
  pbVar1 = (byte *)(*(longlong *)(param_1 + 0x440) + 0x1079);
  *pbVar1 = *pbVar1 & 0xfd;
  *(undefined2 *)(*(longlong *)(param_1 + 0x440) + 0x106c) = 0;
  lVar2 = *(longlong *)(param_1 + 0x440);
  *(short *)(lVar2 + 0x102c) = sVar6 + -1;
  *(undefined1 *)(lVar2 + 0x1000) = 9;
  *(short *)(lVar2 + 0x102e) = sVar5 + -1;
  *(undefined1 *)(lVar2 + 0x1028) = 7;
  iVar3 = NvmeDumpSynchronousExecuteCommandInAdminQueue(param_1,param_1 + 0x3e0);
  if (iVar3 < 0) {
    uVar4 = 0xc1000001;
  }
  else {
    *(short *)(param_1 + 0x14a) = sVar6;
    uVar4 = 0;
    *(short *)(param_1 + 0x14c) = sVar5;
  }
  return uVar4;
}



===== NVMeSubmissionQueueInit @ 140008850 =====

void NVMeSubmissionQueueInit
               (longlong param_1,ulonglong *param_2,ushort param_3,ulonglong param_4,
               ulonglong param_5,ulonglong param_6,ulonglong param_7,ulonglong param_8)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  ushort uVar5;
  ulonglong uVar6;
  undefined2 uVar7;
  int local_res18 [2];
  
  lVar4 = 0;
  if (param_3 == 0) {
    uVar7 = *(undefined2 *)(param_1 + 0xea);
    uVar5 = *(ushort *)(param_1 + 0x144);
  }
  else {
    uVar5 = *(ushort *)(param_1 + 0x146);
    uVar7 = 0;
  }
  *param_2 = param_4;
  if (param_5 == 0) {
    uVar6 = StorPortGetPhysicalAddress(param_1,0,param_4,local_res18);
    param_2[1] = uVar6;
  }
  else {
    param_2[1] = param_5;
  }
  iVar1 = *(int *)(param_1 + 200);
  lVar3 = *(longlong *)(param_1 + 0xb0);
  *(ushort *)(param_2 + 6) = param_3;
  *(undefined8 *)((longlong)param_2 + 0x32) = 0;
  param_2[3] = param_6;
  param_2[4] = param_7;
  param_2[5] = param_8;
  param_2[2] = (ulonglong)((uint)param_3 * iVar1 * 2) + lVar3 + 0x1000;
  *(undefined2 *)((longlong)param_2 + 0x3a) = 0;
  *(undefined2 *)((longlong)param_2 + 0x3c) = uVar7;
  *(undefined2 *)(param_2 + 0x11) = 0;
  *(undefined4 *)((longlong)param_2 + 0x8c) = 0;
  if (uVar5 != 0) {
    lVar3 = 0;
    uVar6 = (ulonglong)uVar5;
    do {
      lVar2 = *param_2 + lVar3;
      lVar3 = lVar3 + 0x40;
      *(longlong *)(lVar4 + param_2[3]) = lVar2;
      lVar4 = lVar4 + 0x10;
      uVar6 = uVar6 - 1;
    } while (uVar6 != 0);
  }
  return;
}



===== NVMeSyncHostTime @ 140008964 =====

undefined8 NVMeSyncHostTime(longlong param_1)

{
  byte *pbVar1;
  longlong lVar2;
  char cVar3;
  int iVar4;
  undefined8 unaff_RBX;
  undefined8 unaff_RDI;
  undefined8 uVar5;
  undefined8 unaff_retaddr;
  PSLIST_HEADER local_res10;
  ulonglong local_res18;
  undefined4 in_stack_ffffffffffffffec;
  
  local_res10 = (PSLIST_HEADER)0x0;
  local_res18 = 0;
  NVMeAllocateDmaBuffer(param_1,8,&local_res10);
  if (local_res10 == (PSLIST_HEADER)0x0) {
    uVar5 = 0xc1000003;
  }
  else {
    *(undefined1 *)(param_1 + 0x3eb) = 0;
    memset(*(void **)(param_1 + 0x440),0,0x1080);
    *(undefined8 *)(*(longlong *)(param_1 + 0x440) + 0x1060) = 0;
    *(undefined8 *)(param_1 + 0x420) = *(undefined8 *)(param_1 + 0x440);
    *(undefined4 *)(param_1 + 0x3e0) = 1;
    (local_res10->s).Alignment = 0xf568cf499800;
    lVar2 = *(longlong *)(param_1 + 0x440);
    if ((local_res18 & 0xfff) == 0) {
      *(undefined8 *)(lVar2 + 0x1020) = 0;
      iVar4 = 0;
      *(ulonglong *)(lVar2 + 0x1018) = local_res18;
      do {
        cVar3 = (char)iVar4;
        iVar4 = iVar4 + 1;
        pbVar1 = (byte *)(*(longlong *)(param_1 + 0x440) + 0x1079);
        *pbVar1 = *pbVar1 | cVar3 + 1U;
      } while (iVar4 < 2);
      pbVar1 = (byte *)(*(longlong *)(param_1 + 0x440) + 0x1079);
      *pbVar1 = *pbVar1 | 4;
      SrbAssignQueueId(param_1,(PSLIST_HEADER)(param_1 + 1000));
      *(undefined4 *)(*(longlong *)(param_1 + 0x440) + 0x1004) = 0xffffffff;
      *(undefined1 *)(*(longlong *)(param_1 + 0x440) + 0x1000) = 9;
      *(undefined1 *)(*(longlong *)(param_1 + 0x440) + 0x1028) = 0xe;
      NvmeDumpSynchronousExecuteCommandInAdminQueue(param_1,param_1 + 0x3e0);
      uVar5 = 0;
    }
    else {
      uVar5 = 0xc1000001;
    }
    if ((local_res10 != (PSLIST_HEADER)0x0) && (local_res18 != 0)) {
      StorPortExtendedFunction
                (0x53,param_1,local_res10,(undefined8 *)0x8,
                 (undefined8 *)CONCAT44(in_stack_ffffffffffffffec,1),local_res18,unaff_RDI,
                 unaff_retaddr,unaff_RBX);
    }
  }
  return uVar5;
}



===== NvmeControlCleanup @ 140008ac4 =====

undefined8
NvmeControlCleanup(longlong param_1,longlong param_2,ulonglong param_3,undefined8 *param_4)

{
  byte bVar1;
  longlong lVar2;
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  ulonglong uVar6;
  ulonglong uVar7;
  longlong lVar8;
  undefined8 unaff_RBX;
  uint uVar9;
  undefined8 unaff_RSI;
  ulonglong uVar10;
  uint uVar11;
  undefined8 *unaff_RDI;
  undefined8 unaff_retaddr;
  undefined8 in_stack_00000018;
  
  uVar11 = 0;
  lVar2 = *(longlong *)
           (*(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x38) + 0x30) + 0x158) + 8);
  uVar9 = *(uint *)(*(longlong *)(lVar2 + 0x558) + 0x58);
  if (uVar9 == 0) {
    uVar10 = 500;
  }
  else {
    param_3 = (ulonglong)uVar9;
    param_4 = (undefined8 *)0x346dc5d63886594b;
    uVar6 = ((ulonglong)uVar9 / 10000) * 10000;
    uVar10 = uVar6 + 10000;
    if (param_3 == uVar6) {
      uVar10 = param_3;
    }
    auVar3._8_8_ = 0;
    auVar3._0_8_ = uVar10;
    param_2 = SUB168(ZEXT816(0x346dc5d63886594b) * auVar3,8);
    uVar10 = uVar10 / 10000;
  }
  uVar9 = (uint)uVar10;
  bVar1 = *(byte *)(lVar2 + 0x3f);
  if (bVar1 != 0) {
    auVar4._8_8_ = 0;
    auVar4._0_8_ = uVar10;
    lVar8 = SUB168(ZEXT816(0x47ae147ae147ae15) * auVar4,8);
    uVar7 = ((uVar10 - lVar8 >> 1) + lVar8 >> 6) * 100;
    uVar6 = uVar7 + 100;
    if (uVar10 == uVar7) {
      uVar6 = uVar10;
    }
    auVar5._8_8_ = 0;
    auVar5._0_8_ = uVar6;
    param_2 = SUB168(ZEXT816(0x47ae147ae147ae15) * auVar5,8);
    param_4 = (undefined8 *)((uVar6 - param_2 >> 1) + param_2 >> 6);
    uVar9 = (uint)bVar1;
    if ((uint)bVar1 < (uint)param_4) {
      uVar9 = (uint)param_4;
    }
    uVar9 = uVar9 * 100;
    param_3 = uVar10;
  }
  *(uint *)(lVar2 + 0x28) = *(uint *)(lVar2 + 0x28) & 0xfffffdfe | 4;
  IoQueuesDeletion(lVar2 + 0x10,param_2,param_3,param_4);
  *(uint *)(*(longlong *)(lVar2 + 0xc0) + 0x14) =
       *(uint *)(*(longlong *)(lVar2 + 0xc0) + 0x14) & 0xffff7fff | 0x4000;
  LOCK();
  UNLOCK();
  if (uVar9 != 0) {
    do {
      if (((byte)*(undefined4 *)(*(longlong *)(lVar2 + 0xc0) + 0x1c) & 0xc) == 8) break;
      StorPortExtendedFunction
                (0x51,lVar2 + 0x10,(PSLIST_HEADER)0x2710,param_4,unaff_RDI,unaff_retaddr,unaff_RBX,
                 unaff_RSI,in_stack_00000018);
      uVar11 = uVar11 + 1;
    } while (uVar11 < uVar9);
    if (uVar11 < uVar9) {
      return 0;
    }
  }
  *(uint *)(lVar2 + 0x28) = *(uint *)(lVar2 + 0x28) | 0x200000;
  return 0;
}



===== NvmeDumpGetPhysicalAddressFromCommonBuffer @ 140008c1c =====

longlong NvmeDumpGetPhysicalAddressFromCommonBuffer(longlong param_1,ulonglong param_2,int *param_3)

{
  uint *puVar1;
  longlong *plVar2;
  longlong lVar3;
  int iVar4;
  ulonglong uVar5;
  
  plVar2 = *(longlong **)(param_1 + -0x10);
  lVar3 = *plVar2;
  uVar5 = *(ulonglong *)(lVar3 + 0x50);
  puVar1 = (uint *)(lVar3 + 0x48);
  if ((param_2 < uVar5) || (uVar5 + *puVar1 <= param_2)) {
    uVar5 = *(ulonglong *)(lVar3 + 0x58);
    if ((param_2 < uVar5) || (uVar5 + *puVar1 <= param_2)) {
      DbgPrint("Dumpstorport: miniport attempted to get physical address for invalid VA %#p\n",
               param_2);
      DbgPrint("Dumpstorport: Valid range 1: %p through %p\n",*(longlong *)(lVar3 + 0x50),
               (ulonglong)*puVar1 + *(longlong *)(lVar3 + 0x50));
      DbgPrint("Dumpstorport: Valid ranges 2: %p through %p\n",*(longlong *)(lVar3 + 0x58),
               (ulonglong)*puVar1 + *(longlong *)(lVar3 + 0x58));
                    /* WARNING: Subroutine does not return */
      KeBugCheckEx(0x2c,0x80000001,plVar2,param_2,0);
    }
    lVar3 = plVar2[4];
    iVar4 = (*puVar1 - (int)param_2) + (int)uVar5;
  }
  else {
    lVar3 = plVar2[3];
    iVar4 = (*puVar1 - (int)param_2) + (int)uVar5;
  }
  *param_3 = iVar4;
  return (lVar3 - uVar5) + param_2;
}



===== NvmeDumpHwFindAdapter @ 140008d14 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 NvmeDumpHwFindAdapter(longlong param_1,ulonglong param_2,longlong param_3)

{
  byte bVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined2 uVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  ulonglong uVar9;
  uint uVar10;
  ulonglong uVar11;
  uint uVar12;
  undefined8 *puVar13;
  PSLIST_HEADER p_Var14;
  undefined8 *puVar15;
  undefined1 uVar16;
  undefined8 auStackY_468 [128];
  int in_stack_ffffffffffffff98;
  undefined4 in_stack_ffffffffffffff9c;
  undefined1 in_stack_ffffffffffffffa0;
  undefined7 in_stack_ffffffffffffffa1;
  char cVar17;
  uint7 in_stack_ffffffffffffffa9;
  undefined1 uVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  undefined2 uVar21;
  undefined1 uVar22;
  undefined1 uVar23;
  undefined1 uVar24;
  undefined1 uVar25;
  
  uVar12 = *(uint *)(param_2 + 0x18);
  cVar17 = '\0';
  uVar18 = 0;
  uVar22 = 0;
  uVar24 = 0;
  uVar25 = 0;
  uVar19 = 0x1010101;
  uVar23 = 1;
  uVar20 = 0x1010101;
  uVar21 = 0x101;
  uVar16 = *(char *)(param_3 + 0xc5) == '\0';
  puVar15 = auStackY_468 + 0x83;
  StorPortExtendedFunction
            (0x67,param_2,(PSLIST_HEADER)0x10,puVar15,
             (undefined8 *)CONCAT44(in_stack_ffffffffffffff9c,in_stack_ffffffffffffff98),
             CONCAT71(in_stack_ffffffffffffffa1,in_stack_ffffffffffffffa0),
             (ulonglong)in_stack_ffffffffffffffa9 << 8,0x101010101010100,
             (ulonglong)CONCAT16(uVar16,0x100010101));
  *(undefined1 *)(param_2 + 0x14) = *(undefined1 *)(param_3 + 0xc5);
  lVar2 = *(longlong *)(param_1 + 0x30);
  *(undefined2 *)(param_2 + 4) = *(undefined2 *)(lVar2 + 0x132);
  *(undefined2 *)(param_2 + 6) = *(undefined2 *)(lVar2 + 0x134);
  *(undefined1 *)(param_2 + 8) = *(undefined1 *)(lVar2 + 0x136);
  lVar3 = *(longlong *)(lVar2 + 0x138);
  *(longlong *)(param_2 + 0xa8) = lVar3;
  puVar13 = *(undefined8 **)(lVar2 + 0x140);
  uVar4 = puVar13[1];
  *(undefined8 *)(param_2 + 0x20) = *puVar13;
  *(undefined8 *)(param_2 + 0x28) = uVar4;
  uVar4 = puVar13[3];
  *(undefined8 *)(param_2 + 0x30) = puVar13[2];
  *(undefined8 *)(param_2 + 0x38) = uVar4;
  uVar4 = puVar13[5];
  *(undefined8 *)(param_2 + 0x40) = puVar13[4];
  *(undefined8 *)(param_2 + 0x48) = uVar4;
  uVar4 = puVar13[7];
  *(undefined8 *)(param_2 + 0x50) = puVar13[6];
  *(undefined8 *)(param_2 + 0x58) = uVar4;
  uVar4 = puVar13[9];
  *(undefined8 *)(param_2 + 0x60) = puVar13[8];
  *(undefined8 *)(param_2 + 0x68) = uVar4;
  uVar4 = puVar13[0xb];
  *(undefined8 *)(param_2 + 0x70) = puVar13[10];
  *(undefined8 *)(param_2 + 0x78) = uVar4;
  uVar4 = puVar13[0xd];
  *(undefined8 *)(param_2 + 0x80) = puVar13[0xc];
  *(undefined8 *)(param_2 + 0x88) = uVar4;
  uVar4 = puVar13[0xf];
  *(undefined8 *)(param_2 + 0x90) = puVar13[0xe];
  *(undefined8 *)(param_2 + 0x98) = uVar4;
  *(undefined4 *)(param_2 + 0xa0) = *(undefined4 *)(puVar13 + 0x10);
  puVar13 = (undefined8 *)0x0;
  uVar7 = *(undefined4 *)(lVar2 + 0x148);
  *(uint *)(param_2 + 0x38) = *(uint *)(param_2 + 0x38) | 4;
  *(undefined4 *)(param_2 + 0xd8) = uVar7;
  if (*(uint *)(param_3 + 0x34) != 0) {
    lVar2 = *(longlong *)(param_3 + 0x38);
    uVar6 = 0;
    do {
      uVar11 = (ulonglong)uVar6;
      puVar15 = (undefined8 *)(uVar11 * 2);
      if (*(longlong *)(lVar2 + uVar11 * 0x10) == lVar3) {
        in_stack_ffffffffffffffa0 = *(char *)(lVar2 + 0xc + uVar11 * 0x10) == '\0';
        in_stack_ffffffffffffff98 = *(int *)(lVar2 + 8 + uVar11 * 0x10);
        puVar15 = *(undefined8 **)(lVar2 + uVar11 * 0x10);
        puVar13 = (undefined8 *)
                  StorPortGetDeviceBase
                            (param_2,*(undefined4 *)(param_3 + 8),*(int *)(param_3 + 4),
                             (longlong)puVar15,in_stack_ffffffffffffff98,in_stack_ffffffffffffffa0);
        break;
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < *(uint *)(param_3 + 0x34));
  }
  *(undefined8 **)(param_2 + 0xb0) = puVar13;
  if (puVar13 == (undefined8 *)0x0) {
    *(undefined4 *)(param_2 + 0x1c) = 4;
    uVar7 = 0xc000000d;
    goto LAB_140009050;
  }
  p_Var14 = (PSLIST_HEADER)0x1;
  *(undefined8 *)(param_2 + 0xc0) = *puVar13;
  *(undefined4 *)(param_2 + 0xb8) = *(undefined4 *)(*(longlong *)(param_2 + 0xb0) + 8);
  *(int *)(param_2 + 200) = 4 << ((byte)((ulonglong)*(undefined8 *)(param_2 + 0xc0) >> 0x20) & 0xf);
  *(uint *)(param_2 + 0xcc) = (uint)*(byte *)(param_2 + 0xc3) * 500;
  uVar7 = 3;
  if (*(int *)(param_3 + 0x14) != 1) {
    uVar7 = 1;
  }
  *(undefined4 *)(param_2 + 0x10) = uVar7;
  uVar11 = param_2;
  uVar9 = StorPortExtendedFunction
                    (0x61,param_2,(PSLIST_HEADER)0x1,auStackY_468 + 0x82,
                     (undefined8 *)CONCAT44(in_stack_ffffffffffffff9c,in_stack_ffffffffffffff98),
                     CONCAT71(in_stack_ffffffffffffffa1,in_stack_ffffffffffffffa0),
                     CONCAT71(in_stack_ffffffffffffffa9,cVar17),
                     CONCAT35((int3)uVar20,CONCAT41(uVar19,uVar18)),
                     CONCAT17(uVar25,CONCAT16(uVar16,CONCAT15(uVar24,CONCAT14(uVar23,CONCAT13(uVar22
                                                  ,CONCAT21(uVar21,(char)((uint)uVar20 >> 0x18))))))
                             ));
  if ((int)uVar9 == 0) {
    *(uint *)(param_2 + 0xf08) =
         *(uint *)(param_2 + 0xf08) & 0xfffeffff | -(uint)(cVar17 != '\0') & 0x10000;
  }
  else {
    *(uint *)(param_2 + 0xf08) = *(uint *)(param_2 + 0xf08) & 0xfffeffff;
  }
  uVar6 = *(uint *)(param_2 + 0x24);
  puVar15 = (undefined8 *)0x20;
  *(undefined2 *)(param_2 + 0x144) = 0x20;
  *(undefined4 *)(param_2 + 0x140) = 0x100040;
  if (uVar6 == 0) {
    uVar5 = 0x20;
  }
  else {
    if (0x20 < uVar6) {
      uVar6 = 0x20;
    }
    uVar5 = (undefined2)uVar6;
  }
  *(undefined2 *)(param_2 + 0x146) = uVar5;
  *(undefined2 *)(param_2 + 0x148) = uVar5;
  *(undefined4 *)(param_3 + 0x30) = 3;
  *(undefined1 *)(param_3 + 0x51) = 1;
  *(undefined1 *)(param_3 + 0x91) = 0;
  *(undefined4 *)(param_3 + 0x94) = 1;
  *(uint *)(param_3 + 0xa0) = (*(int *)(param_3 + 0x14) == 1) + 1;
  *(undefined4 *)(param_3 + 0xd8) = 0;
  if (*(char *)(param_3 + 0x90) == -0x80) {
    *(undefined1 *)(param_3 + 0x90) = 2;
  }
  uVar6 = *(uint *)(param_3 + 0xdc);
  *(undefined1 *)(param_3 + 0x93) = 0;
  uVar10 = uVar6 | 0x2b;
  *(uint *)(param_3 + 0xdc) = uVar10;
  if ((*(uint *)(param_2 + 0x38) & 2) == 0) {
    uVar10 = uVar6 | 0x2f;
    *(uint *)(param_3 + 0xdc) = uVar10;
  }
  if ((*(uint *)(param_2 + 0x38) & 0x400000) == 0) {
    *(uint *)(param_3 + 0xdc) = uVar10 | 0x80000000;
  }
  *(undefined4 *)(param_3 + 0x18) = 0x200000;
  if ((uVar12 & 2) == 0) {
    p_Var14 = (PSLIST_HEADER)(param_2 + 0xfd8);
    uVar11 = param_2;
    StorPortExtendedFunction
              (0x20,param_2,p_Var14,(undefined8 *)0x20,
               (undefined8 *)CONCAT44(in_stack_ffffffffffffff9c,in_stack_ffffffffffffff98),
               CONCAT71(in_stack_ffffffffffffffa1,in_stack_ffffffffffffffa0),
               CONCAT71(in_stack_ffffffffffffffa9,cVar17),
               CONCAT35((int3)uVar20,CONCAT41(uVar19,uVar18)),
               CONCAT17(uVar25,CONCAT16(uVar16,CONCAT15(uVar24,CONCAT14(uVar23,CONCAT13(uVar22,
                                                  CONCAT21(uVar21,(char)((uint)uVar20 >> 0x18)))))))
              );
    uVar9 = ControllerAllocateUncachedExtension(param_2);
    if ((char)uVar9 != '\0') goto LAB_14000902f;
  }
  else {
LAB_14000902f:
    iVar8 = ControllerReset(param_2,uVar11,p_Var14,puVar15);
    if ((iVar8 == 0) && (iVar8 = NVMeControllerInitPart1(param_2), iVar8 == 0)) {
      bVar1 = *(byte *)(*(longlong *)(param_2 + 0x548) + 0x4d);
      uVar12 = 0x200000;
      if (bVar1 == 0) {
        *(undefined4 *)(param_2 + 0xd0) = 0xffffffff;
      }
      else {
        uVar6 = (1 << (*(byte *)(param_2 + 0xc6) & 0xf) + 0xc) * (1 << (bVar1 & 0x1f));
        *(uint *)(param_2 + 0xd0) = uVar6;
        if (uVar6 < 0x200001) {
          uVar12 = uVar6;
        }
      }
      uVar6 = *(uint *)(param_2 + 0x20);
      if ((uVar6 != 0) && (uVar6 <= uVar12)) {
        uVar12 = uVar6;
      }
      uVar6 = *(uint *)(param_2 + 0x34);
      if ((uVar6 != 0) && (uVar6 < uVar12)) {
        uVar12 = uVar6;
      }
      *(uint *)(param_3 + 0x18) = uVar12;
      *(undefined4 *)(param_3 + 0xd4) = 0x20;
      *(undefined4 *)(param_3 + 0xcc) = 0x20;
      *(undefined4 *)(param_3 + 0xd0) = 0x20;
      *(undefined4 *)(param_3 + 0x1c) = 0x201;
      *(undefined1 *)(param_3 + 0x48) = 1;
      *(undefined1 *)(param_3 + 0x61) = 1;
      *(undefined1 *)(param_3 + 0x92) = 0xff;
      *(uint *)(param_2 + 0x18) = *(uint *)(param_2 + 0x18) & 0xfffffffd;
      return 0;
    }
  }
  uVar7 = 0xc00000c2;
LAB_140009050:
  if (*(PSLIST_HEADER *)(param_2 + 0xfd8) != (PSLIST_HEADER)0x0) {
    StorPortExtendedFunction
              (0x22,param_2,*(PSLIST_HEADER *)(param_2 + 0xfd8),puVar15,
               (undefined8 *)CONCAT44(in_stack_ffffffffffffff9c,in_stack_ffffffffffffff98),
               CONCAT71(in_stack_ffffffffffffffa1,in_stack_ffffffffffffffa0),
               CONCAT71(in_stack_ffffffffffffffa9,cVar17),
               CONCAT35((int3)uVar20,CONCAT41(uVar19,uVar18)),
               CONCAT17(uVar25,CONCAT16(uVar16,CONCAT15(uVar24,CONCAT14(uVar23,CONCAT13(uVar22,
                                                  CONCAT21(uVar21,(char)((uint)uVar20 >> 0x18)))))))
              );
    *(undefined8 *)(param_2 + 0xfd8) = 0;
    *(undefined4 *)(param_2 + 0xfe0) = 0;
  }
  if (*(PSLIST_HEADER *)(param_2 + 0xe10) != (PSLIST_HEADER)0x0) {
    StorPortExtendedFunction
              (1,param_2,*(PSLIST_HEADER *)(param_2 + 0xe10),puVar15,
               (undefined8 *)CONCAT44(in_stack_ffffffffffffff9c,in_stack_ffffffffffffff98),
               CONCAT71(in_stack_ffffffffffffffa1,in_stack_ffffffffffffffa0),
               CONCAT71(in_stack_ffffffffffffffa9,cVar17),
               CONCAT35((int3)uVar20,CONCAT41(uVar19,uVar18)),
               CONCAT17(uVar25,CONCAT16(uVar16,CONCAT15(uVar24,CONCAT14(uVar23,CONCAT13(uVar22,
                                                  CONCAT21(uVar21,(char)((uint)uVar20 >> 0x18)))))))
              );
    *(undefined8 *)(param_2 + 0xe10) = 0;
  }
  if (*(PSLIST_HEADER *)(param_2 + 0x168) != (PSLIST_HEADER)0x0) {
    StorPortExtendedFunction
              (1,param_2,*(PSLIST_HEADER *)(param_2 + 0x168),puVar15,
               (undefined8 *)CONCAT44(in_stack_ffffffffffffff9c,in_stack_ffffffffffffff98),
               CONCAT71(in_stack_ffffffffffffffa1,in_stack_ffffffffffffffa0),
               CONCAT71(in_stack_ffffffffffffffa9,cVar17),
               CONCAT35((int3)uVar20,CONCAT41(uVar19,uVar18)),
               CONCAT17(uVar25,CONCAT16(uVar16,CONCAT15(uVar24,CONCAT14(uVar23,CONCAT13(uVar22,
                                                  CONCAT21(uVar21,(char)((uint)uVar20 >> 0x18)))))))
              );
    *(undefined8 *)(param_2 + 0x168) = 0;
  }
  if (*(PSLIST_HEADER *)(param_2 + 0x170) != (PSLIST_HEADER)0x0) {
    StorPortExtendedFunction
              (1,param_2,*(PSLIST_HEADER *)(param_2 + 0x170),puVar15,
               (undefined8 *)CONCAT44(in_stack_ffffffffffffff9c,in_stack_ffffffffffffff98),
               CONCAT71(in_stack_ffffffffffffffa1,in_stack_ffffffffffffffa0),
               CONCAT71(in_stack_ffffffffffffffa9,cVar17),
               CONCAT35((int3)uVar20,CONCAT41(uVar19,uVar18)),
               CONCAT17(uVar25,CONCAT16(uVar16,CONCAT15(uVar24,CONCAT14(uVar23,CONCAT13(uVar22,
                                                  CONCAT21(uVar21,(char)((uint)uVar20 >> 0x18)))))))
              );
    *(undefined8 *)(param_2 + 0x170) = 0;
  }
  if (*(PSLIST_HEADER *)(param_2 + 0x178) != (PSLIST_HEADER)0x0) {
    StorPortExtendedFunction
              (1,param_2,*(PSLIST_HEADER *)(param_2 + 0x178),puVar15,
               (undefined8 *)CONCAT44(in_stack_ffffffffffffff9c,in_stack_ffffffffffffff98),
               CONCAT71(in_stack_ffffffffffffffa1,in_stack_ffffffffffffffa0),
               CONCAT71(in_stack_ffffffffffffffa9,cVar17),
               CONCAT35((int3)uVar20,CONCAT41(uVar19,uVar18)),
               CONCAT17(uVar25,CONCAT16(uVar16,CONCAT15(uVar24,CONCAT14(uVar23,CONCAT13(uVar22,
                                                  CONCAT21(uVar21,(char)((uint)uVar20 >> 0x18)))))))
              );
    *(undefined8 *)(param_2 + 0x178) = 0;
  }
  return uVar7;
}



===== NvmeDumpQueueCommandInSpecificQueue @ 1400091b8 =====

undefined8
NvmeDumpQueueCommandInSpecificQueue
          (longlong param_1,longlong param_2,longlong param_3,ushort param_4)

{
  ushort uVar1;
  ushort uVar2;
  longlong lVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  uint *puVar6;
  ushort uVar7;
  uint uVar8;
  longlong lVar9;
  ushort uVar10;
  uint uVar11;
  longlong *plVar12;
  ushort uVar13;
  ushort *puVar14;
  ushort *puVar15;
  undefined1 uVar16;
  
  uVar16 = 1;
  if (*(ushort *)(param_3 + 0x30) == 0) {
    uVar10 = *(ushort *)(param_1 + 0x144);
    puVar14 = (ushort *)(param_1 + 0x184);
    puVar15 = (ushort *)(param_1 + 0x188);
    plVar12 = (longlong *)(param_1 + 0x170);
    puVar6 = (uint *)(param_1 + 0x186);
    uVar13 = uVar10;
  }
  else {
    uVar10 = *(ushort *)(param_1 + 0x146);
    lVar3 = *(longlong *)(param_1 + 0x398);
    uVar13 = *(ushort *)(param_1 + 0x148);
    lVar9 = (ulonglong)*(ushort *)(param_3 + 0x30) * 0xc0;
    puVar14 = (ushort *)(lVar3 + -0x8c + lVar9);
    puVar15 = (ushort *)(lVar3 + -0x88 + lVar9);
    plVar12 = (longlong *)(lVar3 + -0xa0 + lVar9);
    puVar6 = (uint *)(lVar3 + -0x8a + lVar9);
  }
  uVar2 = *puVar14;
  if (((uint)(ushort)*puVar6 != uVar2 + 1) &&
     (((ushort)*puVar6 != 0 || (puVar6 = (uint *)(ulonglong)(uVar10 - 1), (uint)uVar2 != uVar10 - 1)
      ))) {
    *puVar14 = uVar2 + 1;
    if ((ushort)(uVar2 + 1) == uVar10) {
      *puVar14 = 0;
    }
    if (*puVar15 < uVar13) {
      uVar7 = *puVar15;
      do {
        uVar1 = uVar7 + 1;
        if (*(longlong *)((ulonglong)uVar7 * 0x20 + 0x10 + *plVar12) == 0) {
          *puVar15 = uVar1;
          goto LAB_14000936d;
        }
        uVar7 = uVar1;
      } while (uVar1 < uVar13);
    }
    if (*puVar15 != 0) {
      uVar7 = 0;
      do {
        uVar1 = uVar7 + 1;
        if (*(longlong *)((ulonglong)uVar7 * 0x20 + 0x10 + *plVar12) == 0) {
          *puVar15 = uVar1;
LAB_14000936d:
          if (uVar1 == uVar13) {
            *puVar15 = 0;
          }
          *(ushort *)(param_2 + 0x1070) = uVar2;
          *(ushort *)(param_2 + 0x1002) = uVar7;
          *(ushort *)(param_2 + 0x106e) = uVar7;
          *(undefined8 *)((ulonglong)uVar7 * 0x20 + 0x10 + *(longlong *)(param_3 + 0x20)) = 0;
          *(undefined2 *)
           ((ulonglong)*(ushort *)(param_2 + 0x106e) * 0x20 + 0x18 + *(longlong *)(param_3 + 0x20))
               = *(undefined2 *)(param_2 + 0x1070);
          uVar5 = *(undefined8 *)(param_2 + 0x1008);
          puVar4 = *(undefined8 **)
                    (*(longlong *)(param_3 + 0x18) + (ulonglong)*(ushort *)(param_2 + 0x1070) * 0x10
                    );
          *puVar4 = *(undefined8 *)(param_2 + 0x1000);
          puVar4[1] = uVar5;
          uVar5 = *(undefined8 *)(param_2 + 0x1018);
          puVar4[2] = *(undefined8 *)(param_2 + 0x1010);
          puVar4[3] = uVar5;
          uVar5 = *(undefined8 *)(param_2 + 0x1028);
          puVar4[4] = *(undefined8 *)(param_2 + 0x1020);
          puVar4[5] = uVar5;
          uVar5 = *(undefined8 *)(param_2 + 0x1038);
          puVar4[6] = *(undefined8 *)(param_2 + 0x1030);
          puVar4[7] = uVar5;
          *(undefined2 *)
           (*(longlong *)(param_3 + 0x18) + 8 + (ulonglong)*(ushort *)(param_2 + 0x1070) * 0x10) =
               *(undefined2 *)(param_2 + 0x106e);
          *(undefined4 *)
           ((ulonglong)*(ushort *)(param_2 + 0x106e) * 0x20 + *(longlong *)(param_3 + 0x20)) = 0x108
          ;
          LOCK();
          *(short *)(param_3 + 0x88) = *(short *)(param_3 + 0x88) + 1;
          UNLOCK();
          puVar6 = *(uint **)(param_3 + 0x10);
          uVar11 = (uint)(ushort)(*(short *)(param_2 + 0x1070) + 1);
          uVar8 = 0;
          if (uVar11 != param_4) {
            uVar8 = uVar11;
          }
          *puVar6 = uVar8;
          LOCK();
          UNLOCK();
          goto LAB_140009320;
        }
        uVar7 = uVar1;
      } while (uVar1 < *puVar15);
    }
    uVar13 = *puVar14;
    puVar6 = (uint *)(ulonglong)uVar13;
    if (uVar13 != 0) {
      uVar10 = uVar13;
    }
    *puVar14 = uVar10 - 1;
  }
  uVar16 = 0;
LAB_140009320:
  if (*(short *)(param_3 + 0x30) == 0) {
    LOCK();
    *(short *)(param_1 + 0x3c0) = *(short *)(param_1 + 0x3c0) + -1;
    UNLOCK();
  }
  return CONCAT71((int7)((ulonglong)puVar6 >> 8),uVar16);
}



===== NvmeDumpStartAdapter @ 140009464 =====

undefined8 NvmeDumpStartAdapter(longlong param_1)

{
  ushort *puVar1;
  longlong lVar2;
  longlong lVar3;
  int iVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  
  lVar2 = *(longlong *)(param_1 + 0x30);
  lVar3 = *(longlong *)(*(longlong *)(lVar2 + 0x158) + 8);
  uVar6 = lVar3 + 0x10;
  DbgPrintEx(5,2,"NVMeControllerInitPart2\n");
  if (((*(uint *)(lVar3 + 0x48) & 0x800000) != 0) && (*(int *)(lVar3 + 0xe4) == 0))
  goto LAB_1400095c9;
  if (((*(uint *)(lVar3 + 0x90) & 0x10) == 0) && ((*(uint *)(lVar3 + 0x28) >> 0xd & 1) != 0)) {
    *(undefined4 *)(lVar3 + 0x8c) = 0xffff;
  }
  uVar5 = NVMeSetIoQueueCount(uVar6,'\0');
  iVar4 = (int)uVar5;
  if (iVar4 == 0) {
    if (*(short *)(lVar3 + 0x3d6) == 0) {
      if ((*(short *)(lVar3 + 0x15c) == 0) || (*(short *)(lVar3 + 0x15a) == 0)) goto LAB_140009504;
LAB_14000956c:
      uVar5 = IoQueuesInitialize(uVar6);
      if ((char)uVar5 != '\0') {
        *(undefined2 *)(*(longlong *)(lVar3 + 0x3a8) + 0x3a) =
             *(undefined2 *)(*(longlong *)(lVar3 + 0x3b0) + 0xa8);
        *(undefined4 *)(*(longlong *)(lVar3 + 0x3b0) + 0xb0) = 0;
        goto LAB_1400095a7;
      }
      *(undefined4 *)(lVar3 + 0x2c) = 0xd;
      goto LAB_14000950f;
    }
    if (*(short *)(lVar3 + 0x15c) != 0) {
      if (*(short *)(lVar3 + 0x15a) != 0) goto LAB_14000956c;
LAB_1400095a7:
      if ((*(short *)(lVar3 + 0x15c) != 0) && (*(short *)(lVar3 + 0x15a) != 0)) {
        uVar5 = IoQueuesCreation(uVar6);
        iVar4 = (int)uVar5;
        if (iVar4 != 0) goto LAB_140009514;
      }
    }
LAB_1400095c9:
    NVMeControllerGetFeaturesSupportedCacheCapabilities(uVar6);
    *(int *)(lVar3 + 4000) = *(int *)(lVar3 + 4000) + 1;
  }
  else {
LAB_140009504:
    *(undefined4 *)(lVar3 + 0x2c) = 0xc;
    if (iVar4 == 0) {
LAB_14000950f:
      iVar4 = -0x3effffff;
    }
LAB_140009514:
    *(int *)(lVar3 + 0xfa4) = *(int *)(lVar3 + 0xfa4) + 1;
    if (iVar4 != 0) goto LAB_1400095dc;
  }
  DbgPrintEx(5,2,"NVMeControllerInitPart3\n");
  uVar5 = NVMeControllerInitPart3(uVar6);
  if ((char)uVar5 != '\0') {
    puVar1 = (ushort *)(lVar2 + 0x150);
    *puVar1 = *puVar1 | 2;
    return 0;
  }
LAB_1400095dc:
  FreeAdapterResources(param_1);
  return 0xc0000001;
}



===== NvmeDumpSynchronousExecuteCommandInAdminQueue @ 140009608 =====

void NvmeDumpSynchronousExecuteCommandInAdminQueue(longlong param_1,longlong param_2)

{
  NvmeDumpSynchronousExecuteCommandInSpecificQueue
            (param_1,param_1 + 0x150,(longlong *)(param_1 + 0x210),*(ushort *)(param_1 + 0x144),
             param_2);
  return;
}



===== NvmeDumpSynchronousExecuteCommandInSpecificQueue @ 14000963c =====

ulonglong NvmeDumpSynchronousExecuteCommandInSpecificQueue
                    (longlong param_1,longlong param_2,longlong *param_3,ushort param_4,
                    longlong param_5)

{
  ushort uVar1;
  ulonglong uVar2;
  longlong lVar3;
  short sVar4;
  longlong lVar5;
  bool bVar6;
  undefined8 uStack_20;
  
  uStack_20 = 0;
  NvmeDumpQueueCommandInSpecificQueue(param_1,*(longlong *)(param_5 + 0x60),param_2,param_4);
  lVar5 = (ulonglong)*(ushort *)((longlong)param_3 + 0xaa) * 0x10 + *param_3;
  bVar6 = ((ushort)((uint)*(undefined4 *)(lVar5 + 0xc) >> 0x10) & 1) ==
          *(ushort *)((longlong)param_3 + 0xac);
  if (!bVar6) {
    uStack_20 = *(undefined8 *)(lVar5 + 8);
  }
  lVar5 = KeQueryPerformanceCounter(0);
  do {
    if (!bVar6) {
      uVar2 = TranslateNVMeCommandStatusToNtStatus(uStack_20._6_2_);
      uVar1 = *(ushort *)(param_1 + 0x146);
      *(undefined2 *)(param_2 + 0x36) = (undefined2)uStack_20;
      if ((uint)*(ushort *)((longlong)param_3 + 0xaa) < uVar1 - 1) {
        sVar4 = *(ushort *)((longlong)param_3 + 0xaa) + 1;
      }
      else {
        sVar4 = 0;
        *(ushort *)((longlong)param_3 + 0xac) = (ushort)(*(short *)((longlong)param_3 + 0xac) != 1);
      }
      *(short *)((longlong)param_3 + 0xaa) = sVar4;
      LOCK();
      *(short *)(param_2 + 0x88) = *(short *)(param_2 + 0x88) + -1;
      UNLOCK();
      *(uint *)param_3[2] = (uint)*(ushort *)((longlong)param_3 + 0xaa);
      LOCK();
      UNLOCK();
      return uVar2 & 0xffffffff;
    }
    lVar3 = (ulonglong)*(ushort *)((longlong)param_3 + 0xaa) * 0x10 + *param_3;
    bVar6 = ((ushort)((uint)*(undefined4 *)(lVar3 + 0xc) >> 0x10) & 1) ==
            *(ushort *)((longlong)param_3 + 0xac);
    if (!bVar6) {
      uStack_20 = *(undefined8 *)(lVar3 + 8);
    }
    lVar3 = KeQueryPerformanceCounter(0);
  } while (lVar3 - lVar5 <= g_Frequency * 10);
  return 0xc00000b5;
}



===== NvmePrepareAdapter @ 1400097e8 =====

int NvmePrepareAdapter(longlong param_1)

{
  uint *puVar1;
  longlong *plVar2;
  uint *puVar3;
  longlong lVar4;
  int *piVar5;
  longlong lVar6;
  undefined8 *puVar7;
  uint uVar8;
  int iVar9;
  longlong *plVar10;
  longlong lVar11;
  undefined8 *puVar12;
  undefined1 uVar13;
  undefined4 local_48;
  int local_44;
  longlong local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  
  uVar13 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_48 = 0;
  lVar4 = *(longlong *)(param_1 + 0x30);
  lVar11 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 0x70);
  piVar5 = *(int **)(*(longlong *)(param_1 + 0x38) + 0x48);
  puVar1 = (uint *)(lVar4 + 0x48);
  iVar9 = *piVar5;
  local_40 = lVar11;
  if (((iVar9 != 0xb0) && (iVar9 != 0x88)) && (iVar9 != 0xd0)) {
    iVar9 = -0x3fffffa7;
    goto LAB_140009ce6;
  }
  if (*(int *)(lVar11 + 8) == 3) {
    lVar6 = *(longlong *)(lVar4 + 0x158);
    local_38 = *(undefined8 *)(lVar6 + 600);
    uStack_30 = *(undefined8 *)(lVar6 + 0x260);
    uVar13 = *(undefined1 *)(lVar6 + 0x2b5);
  }
  memset(*(void **)(lVar4 + 0x38),0,(ulonglong)*(uint *)(lVar4 + 0x30));
  puVar7 = *(undefined8 **)(lVar4 + 0x38);
  plVar2 = puVar7 + 3;
  puVar7[4] = 0;
  puVar7[0xd] = 0;
  *plVar2 = param_1;
  if (*(int *)(lVar11 + 8) == 3) {
    *(undefined4 *)(puVar7 + 0x4e) = (undefined4)local_38;
    *(undefined4 *)((longlong)puVar7 + 0x274) = local_38._4_4_;
    *(undefined4 *)(puVar7 + 0x4f) = (undefined4)uStack_30;
    *(undefined4 *)((longlong)puVar7 + 0x27c) = uStack_30._4_4_;
    *(undefined1 *)((longlong)puVar7 + 0x2cd) = uVar13;
  }
  if ((*puVar1 < 0xd1) || (*(char *)(lVar4 + 0xaa) != '\x01')) {
    uVar8 = 0x3f8;
    puVar12 = puVar7 + 0x74;
  }
  else {
    local_44 = 0xffff;
    lVar11 = 0xb8;
    if (*(short *)(lVar4 + 0x130) != -1) {
      lVar11 = 0xe0;
    }
    puVar12 = (undefined8 *)((longlong)puVar7 + lVar11 + 0x348);
    uVar8 = 0x4b8;
    if (*(short *)(lVar4 + 0x130) != -1) {
      uVar8 = 0x4e0;
    }
  }
  puVar3 = (uint *)(puVar7 + 2);
  *puVar3 = uVar8;
  puVar7[8] = puVar7 + 0x69;
  puVar7[9] = puVar12;
  *puVar7 = 0;
  puVar7[5] = (ulonglong)*puVar3 + (longlong)puVar7;
  *(uint *)((ulonglong)*puVar3 + (longlong)puVar7 + 0x10) = *(int *)(lVar4 + 0x30) - *puVar3;
  *(undefined8 *)puVar7[5] = 0;
  local_44 = KeGetRecommendedSharedDataAlignment();
  puVar12 = (undefined8 *)(param_1 + 0x50);
  lVar11 = 2;
  do {
    memset((void *)*puVar12,0,(ulonglong)*(uint *)(param_1 + 0x48));
    puVar12 = puVar12 + 1;
    lVar11 = lVar11 + -1;
  } while (lVar11 != 0);
  if (*Mm64BitPhysicalAddress_exref != (code)0x0) {
    *(undefined1 *)(lVar4 + 0xd8) = 0x80;
  }
  *(undefined4 *)(puVar7 + 0xe) = 0xffffffff;
  *(undefined2 *)((longlong)puVar7 + 0x2cb) = 0;
  plVar10 = AllocatePool((longlong)plVar2,piVar5[0x10] + 0x10,(byte)((uint)piVar5[0x2e] >> 10) & 1);
  puVar7[4] = plVar10;
  if (plVar10 == (longlong *)0x0) {
LAB_1400099ce:
    iVar9 = -0x3fffff66;
    goto LAB_140009ce6;
  }
  *plVar10 = (longlong)plVar2;
  if (piVar5[0x11] != 0) {
    *(int *)(puVar7 + 0x5a) = piVar5[0x11];
    plVar10 = AllocatePool((longlong)plVar2,piVar5[0x11],'\0');
    puVar7[0xd] = plVar10;
    if (plVar10 == (longlong *)0x0) goto LAB_1400099ce;
    memset(plVar10,0,(ulonglong)*(uint *)(puVar7 + 0x5a));
  }
  if ((*(int *)(lVar4 + 0x50) != piVar5[1]) || (*(int *)(lVar4 + 0x7c) != piVar5[0x13])) {
    iVar9 = -0x3ffffff2;
    goto LAB_140009ce6;
  }
  if ((0xd0 < *puVar1) && (4000000 < *(uint *)(lVar4 + 0x120))) {
    *(undefined4 *)(lVar4 + 0x120) = 4000000;
  }
  if (((*piVar5 == 0xb0) || (*piVar5 == 0x88)) && (*(char *)(lVar4 + 0xaa) == '\x01')) {
    *(undefined2 *)(lVar4 + 0xaa) = 0;
  }
  *(undefined4 *)((longlong)puVar7 + 0x24c) = 0x18;
  uVar8 = GetDeviceTransferSize((longlong)puVar1);
  *(uint *)(puVar7 + 0x4a) = uVar8;
  puVar7[0x48] = *(undefined8 *)(param_1 + 0x50);
  *(int *)(puVar7 + 0x49) = piVar5[0x12];
  uVar8 = local_44 + -1 + (piVar5[0x12] + 7U & 0xfffffff8) & ~(local_44 - 1U);
  puVar7[0x47] = (ulonglong)uVar8 + *(longlong *)(param_1 + 0x50);
  uVar8 = uVar8 + (local_44 + 0x11U & ~(local_44 - 1U)) + 7 & 0xfffffff8;
  puVar7[0x45] = (ulonglong)uVar8 + *(longlong *)(param_1 + 0x50);
  *(uint *)(puVar7 + 0x46) = *(int *)(param_1 + 0x48) - uVar8;
  if (*(longlong *)(param_1 + 0x40) == 0) {
LAB_140009be2:
    uVar13 = 0;
  }
  else {
    if (*(char *)((longlong)puVar7 + 0x2cd) == '\0') {
      uVar8 = *(uint *)(param_1 + 0x48);
      puVar7[0x4e] = 0;
      uVar8 = uVar8 >> 0xc;
      iVar9 = HalDmaAllocateCrashDumpRegistersEx
                        (*(undefined8 *)(param_1 + 0x40),uVar8,0,puVar7 + 0x4e,&local_48);
      if (iVar9 < 0) {
                    /* WARNING: Subroutine does not return */
        KeBugCheckEx(0x2c,0x80000002,(longlong)iVar9,uVar8,local_48);
      }
      uVar8 = *(uint *)(puVar7 + 0x4a);
      local_48 = 0;
      puVar7[0x4f] = 0;
      iVar9 = HalDmaAllocateCrashDumpRegistersEx
                        (*(undefined8 *)(param_1 + 0x40),uVar8 >> 0xc,1,puVar7 + 0x4f,&local_48);
      if (iVar9 < 0) {
                    /* WARNING: Subroutine does not return */
        KeBugCheckEx(0x2c,0x80000003,(longlong)iVar9,uVar8 >> 0xc,local_48);
      }
      *(undefined1 *)((longlong)puVar7 + 0x2cd) = 1;
    }
    if ((*(char *)((longlong)piVar5 + 0x59) == '\0') ||
       (uVar13 = 1, *(char *)(lVar4 + 0x9a) == '\0')) goto LAB_140009be2;
  }
  lVar11 = 2;
  *(undefined1 *)((longlong)puVar7 + 0x2c9) = uVar13;
  puVar12 = puVar7 + 6;
  do {
    *puVar12 = *(undefined8 *)((param_1 - (longlong)plVar2) + 0x48 + (longlong)puVar12);
    puVar12 = puVar12 + 1;
    lVar11 = lVar11 + -1;
  } while (lVar11 != 0);
  if (199 < *puVar1) {
    if (*(int *)(local_40 + 4) == 1) {
      uVar13 = 3;
      if (*(int *)(local_40 + 8) != 3) {
        uVar13 = 1;
      }
      *(undefined1 *)(lVar4 + 0x10d) = uVar13;
    }
    else {
      uVar13 = 2;
      if (*(int *)(local_40 + 8) == 3) {
        uVar13 = 4;
      }
      *(undefined1 *)(lVar4 + 0x10d) = uVar13;
    }
  }
  iVar9 = NvmeDumpHwFindAdapter(param_1,puVar7[4] + 0x10,(longlong)puVar1);
  if (iVar9 == 0) {
    *(undefined1 *)(puVar7 + 0x59) = *(undefined1 *)(lVar4 + 0xa1);
    iVar9 = *(int *)(lVar4 + 100);
    *(int *)((longlong)puVar7 + 0x254) = iVar9;
    if (*(char *)((longlong)piVar5 + 0x5d) != '\0') {
      *(uint *)(puVar7 + 0x4b) = *(uint *)(puVar7 + 0x4b) | 2;
    }
    *(undefined1 *)(puVar7 + 0x4c) = *(undefined1 *)((longlong)piVar5 + 0x5a);
    *(undefined1 *)((longlong)puVar7 + 0x261) = *(undefined1 *)(lVar4 + 0x9c);
    *(undefined4 *)((longlong)puVar7 + 0x25c) = *(undefined4 *)(lVar4 + 0x78);
    if (iVar9 == 0) {
      uVar8 = (*(int *)(puVar7 + 0x4a) + 0xfffU & 0xfffff000) + 1;
      *(uint *)((longlong)puVar7 + 0x254) = uVar8;
      if (*(uint *)(lVar4 + 100) < uVar8) {
        *(uint *)((longlong)puVar7 + 0x254) = *(uint *)(lVar4 + 100);
      }
    }
    *(ushort *)(lVar4 + 0x150) = *(ushort *)(lVar4 + 0x150) | 1;
    *(longlong **)(lVar4 + 0x158) = plVar2;
    return 0;
  }
  if (-1 < iVar9) {
    return iVar9;
  }
LAB_140009ce6:
  FreeAdapterResources(param_1);
  return iVar9;
}



===== SrbAssignQueueId @ 140009d18 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SrbAssignQueueId(longlong param_1,PSLIST_HEADER param_2)

{
  undefined2 uVar1;
  ulonglong uVar2;
  undefined8 *puVar3;
  undefined1 auStackY_68 [32];
  undefined8 *in_stack_ffffffffffffffb8;
  undefined8 in_stack_ffffffffffffffc0;
  undefined4 uVar4;
  undefined4 in_stack_ffffffffffffffcc;
  undefined8 in_stack_ffffffffffffffd0;
  undefined4 uVar5;
  undefined4 uVar6;
  uint uStack_1c;
  _SLIST_HEADER local_18;
  
  local_18.s.Region = __security_cookie ^ (ulonglong)auStackY_68;
  if (*(char *)((longlong)&(param_2->s).Alignment + 2) == '(') {
    uVar2 = *(ulonglong *)((longlong)param_2 + 0x68);
  }
  else {
    uVar2 = *(ulonglong *)((longlong)param_2 + 0x38);
  }
  if ((uVar2 & 0xfff) != 0) {
    uVar2 = (uVar2 - ((uint)uVar2 & 0xfff)) + 0x1000;
  }
  uVar4 = 0;
  if ((*(byte *)(uVar2 + 0x1079) & 1) == 0) {
    local_18.s.Alignment._0_4_ = 0;
    GetSrbScsiData((longlong)param_2,(uint *)(auStackY_68 + 0x38));
    puVar3 = (undefined8 *)(auStackY_68 + 0x40);
    uVar6 = 0x14;
    uVar5 = 2;
    StorPortExtendedFunction
              (0xf,param_1,param_2,puVar3,in_stack_ffffffffffffffb8,in_stack_ffffffffffffffc0,
               CONCAT44(in_stack_ffffffffffffffcc,uVar4),in_stack_ffffffffffffffd0,0x1400000002);
    if ((local_18.Header8.Depth == 0xffff) && (local_18.s.Alignment._2_1_ == -1)) {
      StorPortExtendedFunction
                (0x11,param_1,&local_18,puVar3,in_stack_ffffffffffffffb8,in_stack_ffffffffffffffc0,
                 CONCAT44(in_stack_ffffffffffffffcc,uVar4),in_stack_ffffffffffffffd0,
                 CONCAT44(uVar6,uVar5));
    }
    StorPortExtendedFunction
              (0x38,param_1,&local_18,(undefined8 *)(auStackY_68 + 0x30),in_stack_ffffffffffffffb8,
               in_stack_ffffffffffffffc0,CONCAT44(in_stack_ffffffffffffffcc,uVar4),
               in_stack_ffffffffffffffd0,CONCAT44(uVar6,uVar5));
    if ((*(byte *)(uVar2 + 0x1079) & 1) == 0) {
      uVar1 = *(undefined2 *)(*(longlong *)(param_1 + 0x398) + 0x30);
      goto LAB_140009dfe;
    }
  }
  uVar1 = *(undefined2 *)(param_1 + 0x180);
LAB_140009dfe:
  *(undefined2 *)(uVar2 + 0x106c) = uVar1;
  return;
}



===== TranslateNVMeCommandStatusToNtStatus @ 140009e30 =====

undefined8 TranslateNVMeCommandStatusToNtStatus(ushort param_1)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  bool bVar4;
  
  uVar1 = param_1 >> 9 & 7;
  if ((param_1 >> 9 & 7) == 0) {
    uVar2 = param_1 >> 1 & 0xff;
    if (uVar2 < 0x81) {
      if (uVar2 == 0x80) {
        return 0xc0000010;
      }
      if (0xe < uVar2) {
        if (uVar2 < 0x17) {
          if (uVar2 == 0x16) {
            return 0xc0000010;
          }
          if (uVar2 == 0xf) {
            return 0xc0000010;
          }
          if (uVar2 == 0x10) {
            return 0xc0000010;
          }
          if (uVar2 == 0x11) {
            return 0xc0000010;
          }
          if (uVar2 == 0x12) {
            return 0xc0000010;
          }
          if (uVar2 == 0x13) {
            return 0xc0000010;
          }
          iVar3 = uVar2 - 0x14;
          if (iVar3 == 0) {
            return 0xc0000184;
          }
          goto LAB_14000a075;
        }
        if (uVar2 == 0x18) {
          return 0xc0000010;
        }
        if ((uVar2 == 0x19) || (uVar2 == 0x1a)) {
          return 0xc00000b5;
        }
        if (uVar2 == 0x1b) {
          return 0xc0000240;
        }
        if (uVar2 == 0x1c) {
          return 0xc0000185;
        }
        bVar4 = uVar2 == 0x1e;
        goto LAB_14000a0a4;
      }
      if (uVar2 == 0xe) {
        return 0xc0000010;
      }
      if (uVar2 < 8) {
        if (uVar2 == 7) {
          return 0xc0000240;
        }
        if ((char)(param_1 >> 1) == '\0') {
          return 0;
        }
        if (uVar2 == 1) {
          return 0xc0000010;
        }
        if (uVar2 == 2) {
          return 0xc0000010;
        }
        if (uVar2 == 3) {
          return 0xc0000185;
        }
        if (uVar2 == 4) {
          return 0xc0000185;
        }
        iVar3 = uVar2 - 5;
LAB_140009f41:
        if ((iVar3 == 0) || (iVar3 == 1)) {
          return 0xc0000184;
        }
        return 0xc0000185;
      }
      if (uVar2 == 8) {
        return 0xc0000240;
      }
      if (uVar2 == 9) {
        return 0xc0000240;
      }
      if (uVar2 == 10) {
        return 0xc0000240;
      }
      if (uVar2 == 0xb) {
        return 0xc0000010;
      }
      iVar3 = uVar2 - 0xc;
      if (iVar3 == 0) {
        return 0xc000042a;
      }
    }
    else {
      if (uVar2 == 0x81) {
        return 0xc0000010;
      }
      iVar3 = uVar2 - 0x82;
      if (iVar3 == 0) {
        return 0xc00000a3;
      }
    }
  }
  else {
    if (uVar1 != 1) {
      if (uVar1 != 2) {
        return 0xc0000185;
      }
      uVar2 = param_1 >> 1 & 0xff;
      if (uVar2 == 0x80) {
        return 0xc0000185;
      }
      if (uVar2 == 0x81) {
        return 0xc0000185;
      }
      if (uVar2 == 0x82) {
        return 0xc0000185;
      }
      if (uVar2 == 0x83) {
        return 0xc0000185;
      }
      if (uVar2 == 0x84) {
        return 0xc0000185;
      }
      iVar3 = uVar2 - 0x85;
      if (iVar3 == 0) {
        return 0xc0000185;
      }
LAB_14000a075:
      if (iVar3 == 1) {
        return 0xc0000022;
      }
      return 0xc0000185;
    }
    uVar2 = param_1 >> 1 & 0xff;
    if (uVar2 < 0x81) {
      if (uVar2 == 0x80) {
        return 0xc0000010;
      }
      if (uVar2 < 0x12) {
        if (uVar2 == 0x11) {
          return 0x800001b6;
        }
        if (9 < uVar2) {
          if (uVar2 == 10) {
            return 0xc0000010;
          }
          if (uVar2 != 0xb) {
            if (uVar2 == 0xc) {
              return 0xc0000010;
            }
            if (uVar2 == 0xd) {
              return 0xc0000010;
            }
            if (uVar2 == 0xe) {
              return 0xc0000010;
            }
            if (uVar2 == 0xf) {
              return 0xc0000010;
            }
            if (uVar2 != 0x10) {
              return 0xc0000185;
            }
          }
          return 0x800001b6;
        }
        if (uVar2 == 9) {
          return 0xc0000010;
        }
        if ((char)(param_1 >> 1) == '\0') {
          return 0xc0000010;
        }
        if (uVar2 == 1) {
          return 0xc0000010;
        }
        if (uVar2 == 2) {
          return 0xc0000010;
        }
        if (uVar2 == 3) {
          return 0xc0000010;
        }
        iVar3 = uVar2 - 5;
      }
      else {
        if (uVar2 < 0x1b) {
          if (uVar2 == 0x1a) {
            return 0xc0000184;
          }
          if (uVar2 == 0x12) {
            return 0xc0000184;
          }
          if (uVar2 == 0x13) {
            return 0xc0000184;
          }
          if (uVar2 == 0x14) {
            return 0xc0000018;
          }
          if (uVar2 == 0x15) {
            return 0xc0000185;
          }
          if (uVar2 == 0x16) {
            return 0xc0000184;
          }
          iVar3 = uVar2 - 0x18;
          goto LAB_140009f41;
        }
        if (uVar2 == 0x1b) {
          return 0xc00000bb;
        }
        if (uVar2 == 0x1c) {
          return 0xc0000010;
        }
        if (uVar2 == 0x1e) {
          return 0xc0000022;
        }
        iVar3 = uVar2 - 0x1f;
      }
      if (iVar3 == 0) {
        return 0xc0000010;
      }
      if (iVar3 == 1) {
        return 0xc0000010;
      }
      iVar3 = iVar3 + -2;
      if (iVar3 == 0) {
        return 0xc0000010;
      }
    }
    else {
      if (uVar2 == 0x81) {
        return 0xc0000010;
      }
      iVar3 = uVar2 - 0x82;
      if (iVar3 == 0) {
        return 0xc0000022;
      }
    }
  }
  bVar4 = iVar3 == 1;
LAB_14000a0a4:
  if (bVar4) {
    return 0xc0000010;
  }
  return 0xc0000185;
}



===== __GSHandlerCheck @ 14000a0e8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 14000a10c =====

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



===== __chkstk @ 14000a172 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __chkstk(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000a172. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  return;
}



===== __cpu_features_init @ 14000a190 =====

/* WARNING: Removing unreachable block (ram,0x00014000a1fa) */
/* WARNING: Removing unreachable block (ram,0x00014000a1a9) */
/* WARNING: Removing unreachable block (ram,0x00014000a19a) */

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



===== __security_check_cookie @ 14000a260 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 14000a2a0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 14000a2d0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x00014000a2d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 14000a300 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcmp @ 14000a360 =====

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
      if ((byte)*(ulonglong *)_Buf1 != *(byte *)((longlong)_Buf1 + lVar3)) goto LAB_14000a3a3;
      _Size = _Size - 1;
    }
    if (_Size >> 3 != 0) {
      uVar4 = _Size >> 5;
      if (uVar4 != 0) {
        do {
          uVar2 = *(ulonglong *)_Buf1;
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3)) goto LAB_14000a414;
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 8);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 8)) {
LAB_14000a410:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_14000a414;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x10);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x10)) {
LAB_14000a40c:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_14000a410;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x18);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x18)) {
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_14000a40c;
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
LAB_14000a414:
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
LAB_14000a3a3:
  return (1 - (uint)bVar5) - (uint)(bVar5 != 0);
}



===== memmove @ 14000a480 =====

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



===== memset @ 14000a780 =====

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



===== __memset_repmovs @ 14000a8c0 =====

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



===== __memset_query @ 14000a940 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 14000a9c0 =====

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



===== __memset_spec_ermsb_repmovsb @ 14000ab00 =====

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



===== __memset_spec_plain @ 14000ab80 =====

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



===== wil_details_EvaluateFeatureDependencies @ 140011008 =====

void wil_details_EvaluateFeatureDependencies(void)

{
  uint uVar1;
  undefined **ppuVar2;
  undefined **ppuVar3;
  undefined *puVar4;
  bool bVar5;
  
  puVar4 = (undefined *)0x0;
  ppuVar3 = &wil_details_featureDescriptors_a;
  ppuVar2 = &wil_details_featureDescriptors_a;
  do {
    if (*ppuVar2 != (undefined *)0x0) goto joined_r0x000140011043;
    ppuVar2 = ppuVar2 + 1;
  } while (ppuVar2 < &wil_details_featureDescriptors_z);
LAB_1400110bd:
  while( true ) {
    if (&UNK_14000d267 < ppuVar3) {
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
      if (&UNK_14000d267 < ppuVar3) {
        return;
      }
      if (*ppuVar3 != puVar4) break;
      ppuVar3 = ppuVar3 + 1;
    }
  } while( true );
joined_r0x000140011043:
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
      if (&UNK_14000d267 < ppuVar2) goto LAB_1400110bd;
      if (*ppuVar2 != (undefined *)0x0) break;
      ppuVar2 = ppuVar2 + 1;
    }
  }
  goto LAB_1400110bd;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 1400110f8 =====

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
          if (puVar1 == (undefined8 *)0x0) goto LAB_140011190;
          if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
             (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
          if ((uVar4 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
            uVar4 = 0;
            goto LAB_140011190;
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
LAB_140011190:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 1400111e0 =====

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
      for (ppuVar2 = &wil_details_featureDescriptors_a; ppuVar2 < &wil_details_featureDescriptors_z;
          ppuVar2 = ppuVar2 + 1) {
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
              if (&UNK_14000d267 < ppuVar2) {
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



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 140011260 =====

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
  for (ppuVar3 = &wil_details_featureDescriptors_a; ppuVar3 < &wil_details_featureDescriptors_z;
      ppuVar3 = ppuVar3 + 1) {
    if (*ppuVar3 != (undefined *)0x0) goto LAB_14001135d;
  }
LAB_140011366:
  wil_details_EvaluateFeatureDependencies();
  return;
LAB_14001135d:
  if (ppuVar3 == (undefined **)0x0) goto LAB_140011366;
  if (((*(char *)((longlong)ppuVar3 + 0x1d) == '\0') &&
      (*(char *)((longlong)ppuVar3 + 0x1e) == '\0')) &&
     (*(char *)((longlong)ppuVar3 + 0x1c) == '\0')) {
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    iVar1 = RtlQueryFeatureConfiguration(*(undefined4 *)(ppuVar3 + 3),1,&local_28,&local_20);
    if ((iVar1 == -0x7fffffde) || (iVar1 == -0x3ffffddb)) {
LAB_14001132e:
      uVar2 = 0x206;
    }
    else {
      if (iVar1 == 0) {
        uVar2 = (local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0;
      }
      else {
        if (iVar1 != 0x117) goto LAB_14001132e;
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
    if (&UNK_14000d267 < ppuVar3) goto LAB_140011366;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_14001135d;
}



===== entry @ 140013010 =====

void entry(void)

{
  __security_init_cookie();
  DriverEntry();
  return;
}



===== __security_init_cookie @ 140013044 =====

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



===== DriverEntry @ 140013078 =====

undefined8 DriverEntry(void)

{
  return 0;
}



===== wil_InitializeFeatureStaging @ 140013084 =====

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
    for (ppuVar3 = &wil_details_featureDescriptors_a; ppuVar3 < &wil_details_featureDescriptors_z;
        ppuVar3 = ppuVar3 + 1) {
      if (*ppuVar3 != (undefined *)0x0) goto LAB_14001310b;
    }
LAB_140013145:
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
LAB_14001310b:
  if (ppuVar3 == (undefined **)0x0) goto LAB_140013145;
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
    goto LAB_140013145;
  }
  ppuVar3 = ppuVar3 + 7;
  while( true ) {
    if (&UNK_14000d267 < ppuVar3) goto LAB_140013145;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_14001310b;
}



===== wil_details_PopulateInitialConfiguredFeatureStates @ 140013198 =====

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
  ppuVar4 = &wil_details_featureDescriptors_a;
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
            if (&UNK_14000d267 < ppuVar4) {
              return;
            }
            if (*ppuVar4 != (undefined *)0x0) break;
            ppuVar4 = ppuVar4 + 1;
          }
        } while (ppuVar4 != (undefined **)0x0);
        return;
      }
      if (iVar3 == -0x3ffffddb) goto LAB_140013282;
      if (iVar3 == 0) {
        local_28 = (ulonglong)(((local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0) << 3 | 0x206);
      }
      else {
        if (iVar3 != 0x117) goto LAB_140013282;
        local_28 = (ulonglong)((local_20._4_4_ & 0x80) << 3 | 0x206);
      }
    }
    else {
LAB_140013282:
      local_28 = 0x206;
    }
    puVar1 = (ulonglong *)*ppuVar4;
    ppuVar4 = ppuVar4 + 7;
    *puVar1 = local_28;
    while( true ) {
      if (&UNK_14000d267 < ppuVar4) {
        return;
      }
      if (*ppuVar4 != (undefined *)0x0) break;
      ppuVar4 = ppuVar4 + 1;
    }
  } while( true );
}


