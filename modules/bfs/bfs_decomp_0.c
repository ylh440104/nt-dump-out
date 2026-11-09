
===== _tlgWriteTransfer_EtwWriteTransfer @ 140001008 =====

void _tlgWriteTransfer_EtwWriteTransfer(undefined8 param_1,byte *param_2)

{
  undefined4 uStack0000000000000028;
  undefined8 *in_stack_00000030;
  int local_18;
  uint local_14;
  undefined8 local_10;
  
  local_18 = (uint)*param_2 << 0x18;
  local_14 = (uint)*(ushort *)(param_2 + 1);
  local_10 = *(undefined8 *)(param_2 + 3);
  *in_stack_00000030 = PTR_DAT_140019008;
  *(uint *)(in_stack_00000030 + 1) = (uint)*(ushort *)PTR_DAT_140019008;
  in_stack_00000030[2] = param_2 + 0xb;
  *(undefined4 *)((longlong)in_stack_00000030 + 0xc) = 2;
  *(uint *)(in_stack_00000030 + 3) = (uint)*(ushort *)(param_2 + 0xb);
  *(undefined4 *)((longlong)in_stack_00000030 + 0x1c) = 1;
  uStack0000000000000028 = 0x73;
  EtwWriteTransfer(DAT_140019020,&local_18,0,0,3);
  return;
}



===== BfsRegistryCallback @ 1400010c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint BfsRegistryCallback(undefined8 param_1,uint param_2,undefined8 *param_3)

{
  uint uVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  undefined8 **ppuVar5;
  undefined8 uVar6;
  undefined8 **ppuVar7;
  bool bVar8;
  undefined1 auStack_a8 [40];
  undefined1 *local_80;
  undefined1 local_78;
  undefined1 local_77 [3];
  uint local_74;
  int local_70;
  int local_6c;
  undefined1 local_68 [32];
  uint *local_48;
  undefined8 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_a8;
  local_77[0] = 0;
  local_6c = 0;
  local_78 = 0;
  cVar2 = ExGetPreviousMode();
  if (cVar2 == '\0') {
    return 0;
  }
  uVar4 = 0;
  ppuVar5 = (undefined8 **)
            PsReferenceImpersonationToken(SystemReserved1[0xf],local_77,&local_78,&local_6c);
  bVar8 = ppuVar5 == (undefined8 **)0x0;
  if (bVar8) {
    uVar6 = IoGetCurrentProcess();
    ppuVar5 = (undefined8 **)PsReferencePrimaryToken(uVar6);
  }
  local_70 = 0;
  ppuVar7 = ppuVar5;
  uVar3 = SeQueryInformationToken(ppuVar5,0x30,&local_70);
  uVar1 = local_74;
  if (-1 < (int)uVar3) {
    if (local_70 == 0) goto LAB_140001184;
    if (param_2 == 0x1a) {
LAB_140001259:
      ppuVar7 = (undefined8 **)(ulonglong)param_2;
      uVar4 = BfsRegistryPreCreateCallback(param_2,param_3,ppuVar5);
      uVar1 = local_74;
    }
    else {
      uVar3 = 0;
      if (param_2 != 0x1b) {
        if (param_2 == 0x1c) goto LAB_140001259;
        uVar3 = 1;
        if (param_2 != 0x1d) goto LAB_140001184;
      }
      ppuVar7 = (undefined8 **)(ulonglong)uVar3;
      uVar4 = BfsRegistryPostCreateCallback(ppuVar7,param_3,ppuVar5);
      uVar1 = local_74;
    }
    uVar3 = uVar4;
    if (-1 < (int)uVar4) goto LAB_140001184;
  }
  local_74 = uVar3;
  if (3 < DAT_140019000) {
    local_48 = &local_74;
    local_40 = 4;
    local_80 = local_68;
    _tlgWriteTransfer_EtwWriteTransfer(ppuVar7,&DAT_140016d11);
    uVar1 = local_74;
  }
LAB_140001184:
  local_74 = uVar1;
  if (ppuVar5 != (undefined8 **)0x0) {
    if (bVar8) {
      PsDereferencePrimaryToken();
    }
    else {
      PsDereferenceImpersonationToken(ppuVar5);
    }
  }
  return uVar4;
}



===== BfsIsApplicableToken @ 1400012c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool BfsIsApplicableToken(undefined8 param_1)

{
  bool bVar1;
  undefined1 auStack_78 [40];
  undefined1 *local_50;
  int local_48;
  int local_44;
  undefined1 local_40 [32];
  int *local_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_78;
  local_48 = 0;
  local_44 = SeQueryInformationToken(param_1,0x30,&local_48);
  if (local_44 < 0) {
    if (3 < DAT_140019000) {
      local_20 = &local_44;
      local_50 = local_40;
      local_18 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(local_50,&DAT_140016d11);
    }
    bVar1 = false;
  }
  else {
    bVar1 = local_48 != 0;
  }
  return bVar1;
}



===== BfsGetFileContext @ 140001350 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint BfsGetFileContext(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  uint uVar1;
  undefined8 uVar2;
  undefined1 auStack_a8 [32];
  undefined8 **local_88;
  undefined1 *local_80;
  uint local_78 [2];
  undefined8 *local_70;
  undefined8 *local_68;
  undefined1 local_60 [32];
  uint *local_40;
  undefined8 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_a8;
  uVar2 = *(undefined8 *)(param_1 + 0x18);
  local_70 = (undefined8 *)0x0;
  local_68 = (undefined8 *)0x0;
  uVar1 = FltGetFileContext(uVar2,param_2,&local_70);
  if (uVar1 == 0xc0000225) {
    uVar2 = *(undefined8 *)(param_1 + 8);
    local_88 = &local_70;
    uVar1 = FltAllocateContext(uVar2,4,0x10,1);
    if ((int)uVar1 < 0) goto joined_r0x000140001441;
    *local_70 = 0;
    local_70[1] = 0;
    local_88 = &local_68;
    uVar2 = *(undefined8 *)(param_1 + 0x18);
    uVar1 = FltSetFileContext(uVar2,param_2,1,local_70);
    if (uVar1 == 0xc01c0002) {
      FltReleaseContext(local_70);
      *param_3 = local_68;
      return 0;
    }
  }
  if (-1 < (int)uVar1) {
    *param_3 = local_70;
    return uVar1;
  }
joined_r0x000140001441:
  if (3 < DAT_140019000) {
    local_40 = local_78;
    local_38 = 4;
    local_80 = local_60;
    local_78[0] = uVar1;
    _tlgWriteTransfer_EtwWriteTransfer(uVar2,&DAT_140016d11);
  }
  if (local_70 != (undefined8 *)0x0) {
    FltReleaseContext();
  }
  return uVar1;
}



===== BfsPostCleanupOperation @ 1400014d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 BfsPostCleanupOperation(longlong param_1,longlong param_2,char *param_3)

{
  int iVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  ushort *puVar4;
  undefined1 auStack_118 [32];
  undefined4 local_f8;
  undefined **local_f0;
  undefined4 local_e8;
  undefined8 local_e0;
  int local_d8;
  int local_d4 [5];
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined *local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined *local_68;
  uint local_60;
  undefined4 local_5c;
  undefined *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  int *local_48;
  undefined8 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_118;
  local_b0 = 0;
  local_c0 = 0;
  uStack_b8 = 0;
  local_a8 = (undefined *)0x0;
  uStack_a0 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_78 = 0;
  uStack_70 = 0;
  if (param_3 != (char *)0x0) {
    if (*param_3 != '\0') {
      local_f0 = (undefined **)0x0;
      local_f8 = 5;
      iVar1 = FltQueryInformationFile
                        (*(undefined8 *)(param_2 + 0x18),
                         *(undefined8 *)(*(longlong *)(param_1 + 0x10) + 8),&local_c0,0x18);
      if (iVar1 == -0x3ffffedd) {
        local_f0 = &local_a8;
        local_e0 = 0;
        local_e8 = 0x40;
        local_f8 = 0;
        iVar1 = FltFsControlFile(*(undefined8 *)(param_2 + 0x18),
                                 *(undefined8 *)(*(longlong *)(param_1 + 0x10) + 8),0x9009c,0);
        if (iVar1 == -0x3ffffedd) {
          uVar2 = Feature_Servicing_BfsGAFeature__private_IsEnabledDeviceUsageNoInline();
          if ((int)uVar2 == 0) {
            puVar4 = (ushort *)0x0;
          }
          else {
            puVar4 = (ushort *)(*(longlong *)(param_3 + 8) + 8);
          }
          uVar3 = BfsProcessDelete(puVar4);
          iVar1 = (int)uVar3;
          if (iVar1 < 0) {
            if (3 < DAT_140019000) {
              local_40 = 4;
              local_48 = &local_d8;
              local_68 = PTR_DAT_140019008;
              local_d4[2] = 3;
              local_d4[1] = 0xb000000;
              local_d4[3] = 0;
              local_d4[4] = 0;
              local_60 = (uint)*(ushort *)PTR_DAT_140019008;
              local_58 = &DAT_140016d1c;
              local_5c = 2;
              local_50 = 0x1e;
              local_4c = 1;
              local_d4[0] = 0x73;
              local_f0 = &local_68;
              local_f8 = 3;
              local_d8 = iVar1;
              EtwWriteTransfer(DAT_140019020,local_d4 + 1,0,0);
            }
            goto LAB_14000176c;
          }
        }
        else if (((iVar1 + 0x80000000U & 0x80000000) == 0) && (iVar1 != -0x3ffffd10)) {
          if (3 < DAT_140019000) {
            local_48 = local_d4;
            local_68 = PTR_DAT_140019008;
            local_d4[2] = 3;
            local_40 = 4;
            local_d4[1] = 0xb000000;
            local_d4[3] = 0;
            local_d4[4] = 0;
            local_60 = (uint)*(ushort *)PTR_DAT_140019008;
            local_58 = &DAT_140016d1c;
            local_5c = 2;
            local_50 = 0x1e;
            local_4c = 1;
            local_d8 = 0x73;
            local_f0 = &local_68;
            local_f8 = 3;
            local_d4[0] = iVar1;
            EtwWriteTransfer(DAT_140019020,local_d4 + 1,0,0);
          }
          goto LAB_14000176c;
        }
      }
    }
    uVar2 = Feature_Servicing_BfsGAFeature__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar2 == 0) {
      FltReleaseContext(param_3);
    }
  }
  iVar1 = 0;
LAB_14000176c:
  uVar2 = Feature_1199833401__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar2 != 0) {
    KeEnterCriticalRegion();
  }
  ExReleaseRundownProtection(&gBfsRundownProtection);
  KeLeaveCriticalRegion();
  uVar2 = Feature_Servicing_BfsGAFeature__private_IsEnabledDeviceUsageNoInline();
  if ((((int)uVar2 != 0) || (iVar1 < 0)) && (param_3 != (char *)0x0)) {
    FltReleaseContext(param_3);
  }
  return 0;
}



===== BfsPostCreateOperation @ 1400017f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 BfsPostCreateOperation(longlong param_1,longlong param_2,uint *param_3,ulonglong param_4)

{
  uint *puVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  code *pcVar5;
  bool bVar6;
  bool bVar7;
  char cVar8;
  ushort uVar9;
  int iVar10;
  ulonglong *puVar11;
  ulonglong uVar12;
  undefined8 uVar13;
  short sVar14;
  longlong lVar15;
  uint uVar16;
  int iVar17;
  longlong lVar18;
  undefined1 auStackY_d8 [32];
  char local_a8 [16];
  undefined8 local_98;
  ulonglong uStack_90;
  int local_88;
  int local_84;
  int local_80;
  int local_7c;
  undefined1 *local_78;
  undefined *local_70;
  undefined8 uStack_68;
  undefined *local_60;
  undefined4 local_58;
  undefined4 local_54;
  int *local_50;
  undefined8 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_d8;
  bVar7 = false;
  local_78 = (undefined1 *)0x0;
  lVar18 = 0;
  local_98 = 0;
  uStack_90 = 0;
  if ((param_4 & 1) == 0) {
    if (param_3 == (uint *)0x0) goto LAB_140001ad1;
    if ((((*param_3 & 2) == 0) || (*(int *)(param_1 + 0x18) < 0)) || ((char)param_3[0x12] == '\0'))
    {
LAB_14000193e:
      if ((*param_3 & 1) == 0) goto LAB_140001ad1;
      lVar18 = *(longlong *)(param_3 + 0x10);
      param_3[0x10] = 0;
      param_3[0x11] = 0;
      if (param_3[2] == 0) {
        uVar16 = *(uint *)(*(longlong *)(param_1 + 0x10) + 0x20);
        puVar1 = (uint *)(*(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x10) + 0x18) + 8) +
                         0x14);
        *puVar1 = *puVar1 & 0xfff3ffff;
        FltSetCallbackDataDirty(param_1);
        if (((uVar16 & 1) == 0) || ((*(byte *)(param_1 + 0x20) & 2) == 0)) {
          if ((((byte)uVar16 & 0x41) == 0x40) && ((*(byte *)(param_1 + 0x20) & 2) != 0)) {
            lVar15 = *(longlong *)(param_3 + 0xc);
            puVar11 = (ulonglong *)BfsGetFileName((ushort *)&local_98,lVar15);
            iVar10 = 1;
            iVar17 = 0;
            goto LAB_1400019d5;
          }
        }
        else {
          lVar15 = *(longlong *)(param_3 + 0xc);
          puVar11 = (ulonglong *)BfsGetFileName((ushort *)&local_98,lVar15);
          iVar10 = 2;
          iVar17 = 2;
LAB_1400019d5:
          local_98 = *puVar11;
          uStack_90 = puVar11[1];
          BfsAddOrModifyEntry(*(longlong *)(lVar18 + 0x30),iVar10,1,iVar17,(ushort *)(lVar15 + 0x18)
                              ,(short *)&local_98);
        }
        if (*(longlong *)
             (*(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x10) + 0x18) + 8) + 0x20) != 0) {
          ObfDereferenceObject();
        }
        uVar13 = *(undefined8 *)(param_3 + 6);
        lVar15 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x10) + 0x18) + 8);
        *(undefined8 *)(lVar15 + 0x20) = *(undefined8 *)(param_3 + 4);
        *(undefined8 *)(lVar15 + 0x28) = uVar13;
        uVar13 = *(undefined8 *)(param_3 + 10);
        *(undefined8 *)(lVar15 + 0x30) = *(undefined8 *)(param_3 + 8);
        *(undefined8 *)(lVar15 + 0x38) = uVar13;
        uVar12 = Feature_Servicing_BfsGAFeature__private_IsEnabledDeviceUsageNoInline();
        if ((int)uVar12 == 0) {
          FltReleaseFileNameInformation(*(undefined8 *)(param_3 + 0xc));
          BfsDereferencePolicyEntryEx(lVar18,'\0');
          ExFreePoolWithTag(param_3,0);
          return 0;
        }
LAB_140001ad1:
        bVar6 = bVar7;
        uVar12 = Feature_Servicing_BfsGAFeature__private_IsEnabledDeviceUsageNoInline();
        if (((((int)uVar12 != 0) && (param_3 != (uint *)0x0)) && ((*param_3 & 4) != 0)) &&
           ((-1 < *(int *)(param_1 + 0x18) && ((*(byte *)(param_1 + 0x20) & 2) != 0)))) {
          lVar15 = *(longlong *)(param_3 + 0x14);
          uStack_90 = *(ulonglong *)(lVar15 + 0x10);
          sVar14 = *(short *)(lVar15 + 8) - *(short *)(lVar15 + 0x48);
          local_98 = (ulonglong)CONCAT22(sVar14,sVar14);
          KeEnterCriticalRegion();
          ExAcquirePushLockExclusiveEx(&DAT_140019198,0);
          KeEnterCriticalRegion();
          ExAcquirePushLockExclusiveEx(&gBfsGlobalFileTable,0);
          uVar13 = DAT_1400191b8;
          local_60 = (undefined *)0x0;
          lVar15 = 0;
          uVar16 = 0;
          local_70 = (undefined *)0x0;
          uStack_68 = 0;
          if ((local_98 & 0xfffe) == 0) {
LAB_140001bdf:
            lVar15 = -1;
          }
          else {
            do {
              uVar9 = RtlUpcaseUnicodeChar(*(undefined2 *)(uStack_90 + (ulonglong)uVar16 * 2));
              uVar16 = uVar16 + 1;
              lVar15 = (lVar15 * 0x25 + ((ulonglong)uVar9 & 0xff)) * 0x25 + (ulonglong)(uVar9 >> 8);
            } while (uVar16 < (ushort)local_98 >> 1);
            if (lVar15 == 0) goto LAB_140001bdf;
          }
          lVar15 = RtlLookupEntryHashTable(uVar13,lVar15,&local_70);
          while (lVar15 != 0) {
            cVar8 = RtlEqualUnicodeString(&local_98,lVar15 + 0x40,1);
            if (cVar8 != '\0') {
              if (*(char *)(lVar15 + 0x28) != '\0') {
                plVar2 = (longlong *)(lVar15 + 0x18);
                *(undefined1 *)(lVar15 + 0x28) = 0;
                lVar3 = *plVar2;
                if ((*(longlong **)(lVar3 + 8) != plVar2) ||
                   (plVar4 = *(longlong **)(lVar15 + 0x20), (longlong *)*plVar4 != plVar2)) {
                  pcVar5 = (code *)swi(0x29);
                  (*pcVar5)(3);
                  pcVar5 = (code *)swi(3);
                  uVar13 = (*pcVar5)();
                  return uVar13;
                }
                *plVar4 = lVar3;
                *(longlong **)(lVar3 + 8) = plVar4;
                *plVar2 = 0;
                *(undefined8 *)(lVar15 + 0x20) = 0;
                *(undefined8 *)(lVar15 + 0x30) = 0;
                *(undefined8 *)(lVar15 + 0x38) = 0;
              }
              break;
            }
            lVar15 = RtlGetNextEntryHashTable(uVar13);
          }
          ExReleasePushLockExclusiveEx(&gBfsGlobalFileTable);
          KeLeaveCriticalRegion();
          ExReleasePushLockExclusiveEx(&DAT_140019198);
          KeLeaveCriticalRegion();
        }
      }
      else {
        if ((param_3[2] != 1) || (*(int *)(param_1 + 0x18) != -0x3fffffde)) goto LAB_140001ad1;
        if (*(int *)(lVar18 + 0x68) != 0) {
          if (*(int *)(lVar18 + 0x68) == 1) goto LAB_140001d76;
          goto LAB_140001ad1;
        }
        local_a8[0] = '\0';
        iVar10 = RtlCheckTokenCapability
                           (0,*(undefined8 *)(*(longlong *)SeExports_exref + 0x248),local_a8);
        if ((iVar10 < 0) || (local_a8[0] == '\0')) {
          *(undefined4 *)(lVar18 + 0x68) = 2;
          goto LAB_140001ad1;
        }
        *(undefined4 *)(lVar18 + 0x68) = 1;
LAB_140001d76:
        SeCaptureSubjectContext(param_3 + 4);
        bVar6 = true;
        if (*(longlong *)(param_3 + 4) == 0) {
LAB_140001f43:
          uVar13 = PsGetCurrentProcessId();
          *(undefined8 *)(param_3 + 0xe) = uVar13;
          uVar12 = BfsPerformPrompt(param_1,param_2,(longlong)param_3);
          bVar7 = true;
          if (-1 < (int)uVar12) goto LAB_140001ad1;
          if (3 < DAT_140019000) {
            local_48 = 4;
            local_50 = &local_84;
            local_70 = PTR_DAT_140019008;
            local_98 = 0x30b000000;
            uStack_90 = 0;
            local_60 = &DAT_140016d1c;
            uStack_68 = CONCAT44(2,(uint)*(ushort *)PTR_DAT_140019008);
            local_58 = 0x1e;
            local_54 = 1;
            local_88 = 0x73;
            local_84 = (int)uVar12;
            EtwWriteTransfer(DAT_140019020,&local_98,0,0);
          }
        }
        else {
          local_7c = 0;
          local_80 = 0;
          iVar10 = SeQuerySessionIdToken(*(undefined8 *)(param_3 + 8));
          if (iVar10 < 0) {
            if (3 < DAT_140019000) {
              local_48 = 4;
              local_50 = &local_88;
              local_70 = PTR_DAT_140019008;
              local_98 = 0x30b000000;
              uStack_90 = 0;
              local_60 = &DAT_140016d1c;
              uStack_68 = CONCAT44(2,(uint)*(ushort *)PTR_DAT_140019008);
              local_58 = 0x1e;
              local_54 = 1;
              local_84 = 0x73;
              local_88 = iVar10;
              EtwWriteTransfer(DAT_140019020,&local_98,0,0);
            }
          }
          else {
            iVar10 = SeQuerySessionIdToken(*(undefined8 *)(param_3 + 4));
            if (iVar10 < 0) {
              if (3 < DAT_140019000) {
                local_48 = 4;
                local_50 = &local_84;
                local_70 = PTR_DAT_140019008;
                local_98 = 0x30b000000;
                uStack_90 = 0;
                local_60 = &DAT_140016d1c;
                uStack_68 = CONCAT44(2,(uint)*(ushort *)PTR_DAT_140019008);
                local_58 = 0x1e;
                local_54 = 1;
                local_88 = 0x73;
                local_84 = iVar10;
                EtwWriteTransfer(DAT_140019020,&local_98,0,0);
              }
            }
            else if (local_7c == local_80) goto LAB_140001f43;
          }
        }
      }
      if (lVar18 != 0) {
        BfsDereferencePolicyEntryEx(lVar18,'\0');
      }
      if (bVar6) {
        SeReleaseSubjectContext(param_3 + 4);
      }
      goto LAB_140001ca4;
    }
    iVar10 = BfsGetFileContext(param_2,*(undefined8 *)(*(longlong *)(param_1 + 0x10) + 8),&local_78)
    ;
    if (-1 < iVar10) {
      *local_78 = 1;
      goto LAB_14000193e;
    }
    if (3 < DAT_140019000) {
      local_48 = 4;
      local_50 = &local_7c;
      local_70 = PTR_DAT_140019008;
      local_98 = 0x30b000000;
      uStack_90 = 0;
      local_60 = &DAT_140016d1c;
      uStack_68 = CONCAT44(2,(uint)*(ushort *)PTR_DAT_140019008);
      local_58 = 0x1e;
      local_54 = 1;
      local_80 = 0x73;
      local_7c = iVar10;
      EtwWriteTransfer(DAT_140019020,&local_98,0,0);
    }
  }
  else {
LAB_140001ca4:
    if (param_3 == (uint *)0x0) goto LAB_140001d2e;
  }
  if (*(longlong *)(param_3 + 0xc) != 0) {
    FltReleaseFileNameInformation();
  }
  uVar12 = Feature_Servicing_BfsGAFeature__private_IsEnabledDeviceUsageNoInline();
  if (((int)uVar12 != 0) && (*(longlong *)(param_3 + 0x14) != 0)) {
    FltReleaseFileNameInformation();
  }
  ExFreePoolWithTag(param_3,0);
  uVar12 = Feature_1199833401__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar12 != 0) {
    uVar12 = Feature_1199833401__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar12 != 0) {
      KeEnterCriticalRegion();
    }
    ExReleaseRundownProtection(&gBfsRundownProtection);
    KeLeaveCriticalRegion();
  }
LAB_140001d2e:
  if (local_78 != (undefined1 *)0x0) {
    FltReleaseContext();
  }
  return 0;
}



===== BfsPreCleanupOperation @ 140002070 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 BfsPreCleanupOperation(longlong param_1,longlong param_2,longlong *param_3)

{
  longlong lVar1;
  char cVar2;
  int iVar3;
  ulonglong uVar4;
  bool bVar5;
  undefined1 auStack_b8 [32];
  undefined4 local_98;
  undefined **local_90;
  longlong local_88;
  int local_80 [2];
  longlong local_78;
  undefined4 local_70;
  undefined4 local_6c;
  undefined8 local_68;
  undefined *local_60;
  uint local_58;
  undefined4 local_54;
  undefined *local_50;
  undefined4 local_48;
  undefined4 local_44;
  int *local_40;
  undefined8 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_b8;
  local_88 = 0;
  local_78 = 0;
  uVar4 = Feature_Servicing_AppSiloSmbNoTrackDelete__private_IsEnabledDeviceUsageNoInline();
  if (((int)uVar4 != 0) &&
     ((lVar1 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x10) + 8) + 8), lVar1 == 0 ||
      (*(int *)(lVar1 + 0x48) == 0x14)))) goto LAB_140002255;
  KeEnterCriticalRegion();
  cVar2 = ExAcquireRundownProtection(&gBfsRundownProtection);
  uVar4 = Feature_1199833401__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar4 == 0) {
    if (cVar2 != '\0') goto LAB_140002115;
  }
  else {
    KeLeaveCriticalRegion();
    if (cVar2 == '\0') goto LAB_140002255;
LAB_140002115:
    iVar3 = FltGetFileContext(*(undefined8 *)(param_2 + 0x18),
                              *(undefined8 *)(*(longlong *)(param_1 + 0x10) + 8),&local_88);
    if (-1 < iVar3) {
      uVar4 = Feature_Servicing_BfsGAFeature__private_IsEnabledDeviceUsageNoInline();
      if (((int)uVar4 == 0) || (*(longlong *)(local_88 + 8) != 0)) {
LAB_1400022c8:
        *param_3 = local_88;
        return 0;
      }
      iVar3 = FltGetFileNameInformation(param_1,0x101,&local_78);
      if (-1 < iVar3) {
        LOCK();
        bVar5 = *(longlong *)(local_88 + 8) == 0;
        if (bVar5) {
          *(longlong *)(local_88 + 8) = local_78;
        }
        UNLOCK();
        if (!bVar5) {
          FltReleaseFileNameInformation(local_78);
        }
        goto LAB_1400022c8;
      }
      if (3 < DAT_140019000) {
        local_38 = 4;
        local_40 = local_80;
        local_60 = PTR_DAT_140019008;
        local_6c = 3;
        local_70 = 0xb000000;
        local_68 = 0;
        local_58 = (uint)*(ushort *)PTR_DAT_140019008;
        local_50 = &DAT_140016d1c;
        local_54 = 2;
        local_48 = 0x1e;
        local_44 = 1;
        local_80[1] = 0x73;
        local_90 = &local_60;
        local_98 = 3;
        local_80[0] = iVar3;
        EtwWriteTransfer(DAT_140019020,&local_70,0,0);
      }
    }
    uVar4 = Feature_1199833401__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar4 != 0) {
      KeEnterCriticalRegion();
    }
    ExReleaseRundownProtection(&gBfsRundownProtection);
  }
  KeLeaveCriticalRegion();
LAB_140002255:
  uVar4 = Feature_Servicing_BfsGAFeature__private_IsEnabledDeviceUsageNoInline();
  if (((int)uVar4 != 0) && (local_88 != 0)) {
    FltReleaseContext();
  }
  return 1;
}



===== BfsPreCreateOperation @ 1400022e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int BfsPreCreateOperation(ushort *param_1,longlong param_2,longlong *param_3)

{
  byte bVar1;
  undefined2 uVar2;
  uint uVar3;
  longlong *plVar4;
  int iVar5;
  bool bVar6;
  char cVar7;
  int iVar8;
  ulonglong uVar9;
  uint *puVar10;
  longlong lVar11;
  ushort *puVar12;
  undefined8 uVar13;
  short sVar14;
  int iVar15;
  undefined1 auStackY_148 [32];
  undefined4 local_118;
  char local_114;
  undefined8 local_108;
  undefined8 uStack_100;
  longlong local_f8;
  char local_f0;
  uint *local_e8;
  undefined1 local_e0;
  undefined1 local_df [7];
  longlong local_d8;
  int local_d0 [2];
  longlong *local_c8;
  int local_c0 [2];
  undefined8 *local_b8;
  undefined8 *local_b0;
  longlong local_a8;
  ulonglong local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  longlong lStack_80;
  undefined *local_78;
  uint local_70;
  undefined4 local_6c;
  undefined *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  longlong *local_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_148;
  local_df[0] = 0;
  local_e0 = 0;
  iVar15 = 1;
  local_c0[0] = 0;
  local_f0 = '\0';
  local_98 = 0;
  uStack_90 = 0;
  puVar12 = (ushort *)0x0;
  local_d8 = 0;
  local_88 = 0;
  lStack_80 = 0;
  local_d0[0] = 0;
  puVar10 = (uint *)0x0;
  local_a8 = 0;
  iVar8 = 0;
  local_b0 = (undefined8 *)0x0;
  local_b8 = (undefined8 *)0x0;
  local_e8 = (uint *)0x0;
  local_f8 = param_2;
  local_c8 = param_3;
  uVar9 = Feature_1199833401__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar9 != 0) {
    *local_c8 = 0;
  }
  KeEnterCriticalRegion();
  local_114 = ExAcquireRundownProtection(&gBfsRundownProtection);
  uVar9 = Feature_1199833401__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar9 == 0) {
    if (local_114 == '\0') {
      KeLeaveCriticalRegion();
      goto LAB_1400023ba;
    }
LAB_14000248f:
    if ((*(uint *)(*(longlong *)(param_1 + 8) + 0x20) & 0x1000) == 0) {
LAB_14000262f:
      uVar9 = Feature_Servicing_BfsGAFeature__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar9 == 0) goto LAB_14000283f;
      iVar8 = FltGetFileSystemType(*(undefined8 *)(param_2 + 0x10),local_d0);
      if (iVar8 < 0) goto LAB_140002658;
      uVar9 = Feature_Servicing_AppSiloSmbNoTrackDelete__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar9 == 0) {
        if (local_d0[0] == 0x19) goto LAB_14000283f;
        bVar1 = *(byte *)(*(longlong *)(param_1 + 8) + 0x23);
LAB_1400026a9:
        if ((5 < bVar1) || ((0x2dU >> (bVar1 & 0x1f) & 1) == 0)) goto LAB_14000283f;
        iVar8 = FltGetFileNameInformation(param_1,0x101,&local_d8);
        if (iVar8 < 0) goto LAB_140002658;
        sVar14 = *(short *)(local_d8 + 8) - *(short *)(local_d8 + 0x48);
        uStack_100 = *(undefined8 *)(local_d8 + 0x10);
        local_108._0_4_ = CONCAT22(sVar14,sVar14);
        uVar3 = (uint)local_108;
        local_108 = (ulonglong)(uint)local_108;
        local_98 = (ulonglong)uVar3;
        uStack_90 = uStack_100;
        KeEnterCriticalRegion();
        ExAcquirePushLockSharedEx(&gBfsGlobalFileTable,0);
        lVar11 = BfsGetGlobalFileEntry(0x140019190,(ushort *)&local_98);
        ExReleasePushLockSharedEx(&gBfsGlobalFileTable,0);
        KeLeaveCriticalRegion();
        if (lVar11 == 0) {
          FltReleaseFileNameInformation(local_d8);
LAB_140002835:
          local_d8 = 0;
          param_2 = local_f8;
          goto LAB_14000283f;
        }
        if ((puVar10 != (uint *)0x0) ||
           (puVar10 = (uint *)ExAllocatePool2(0x100,0x58,0x43736642), local_e8 = puVar10,
           puVar10 != (uint *)0x0)) {
          *puVar10 = *puVar10 | 4;
          iVar15 = 0;
          *(longlong *)(puVar10 + 0x14) = local_d8;
          goto LAB_140002835;
        }
        if (DAT_140019000 < 4) goto LAB_140002588;
        local_f8 = CONCAT44(local_f8._4_4_,0xc0000017);
LAB_1400027b9:
        local_78 = PTR_DAT_140019008;
        local_70 = (uint)*(ushort *)PTR_DAT_140019008;
        goto LAB_140002520;
      }
      if (local_d0[0] != 0x19) {
        lVar11 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 8) + 8) + 8);
        if ((lVar11 != 0) && (*(int *)(lVar11 + 0x48) != 0x14)) {
          bVar1 = *(byte *)(*(longlong *)(param_1 + 8) + 0x23);
          goto LAB_1400026a9;
        }
      }
LAB_14000283f:
      if ((char)param_1[0x28] == '\0') {
        Feature_1199833401__private_IsEnabledDeviceUsageNoInline();
LAB_14000284a:
        if (iVar8 < 0) goto LAB_140002588;
      }
      else {
        puVar12 = (ushort *)
                  PsReferenceImpersonationToken
                            (*(undefined8 *)(param_1 + 4),local_df,&local_e0,local_c0);
        if (puVar12 == (ushort *)0x0) {
          uVar13 = IoGetCurrentProcess();
          puVar12 = (ushort *)PsReferencePrimaryToken(uVar13);
        }
        else {
          local_f0 = '\x01';
          if (local_c0[0] < 2) goto LAB_14000284a;
        }
        bVar6 = BfsIsApplicableToken(puVar12);
        if (!bVar6) goto LAB_14000284a;
        uVar9 = Feature_Servicing_BfsGAFeature__private_IsEnabledDeviceUsageNoInline();
        if (((int)uVar9 == 0) &&
           (iVar8 = FltGetFileSystemType(*(undefined8 *)(param_2 + 0x10),local_d0), iVar8 < 0)) {
LAB_140002658:
          if (DAT_140019000 < 4) goto LAB_140002588;
          local_f8 = CONCAT44(local_f8._4_4_,iVar8);
          goto LAB_1400027b9;
        }
        if (local_d0[0] != 0x19) {
          uVar9 = Feature_Servicing_BfsGAFeature__private_IsEnabledDeviceUsageNoInline();
          if ((int)uVar9 != 0) {
            uVar13 = BfsCheckDeleteList(*(longlong **)(param_2 + 8),*(undefined8 *)(param_2 + 0x18))
            ;
            iVar8 = (int)uVar13;
            if (iVar8 < 0) goto LAB_140002658;
          }
          cVar7 = BfsCheckAndApplyPolicy
                            (*(longlong **)(param_2 + 8),*(longlong *)(param_2 + 0x18),puVar12,
                             param_1,(longlong *)&local_e8);
          iVar5 = 0;
          if (cVar7 == '\0') {
            iVar5 = iVar15;
          }
          iVar15 = iVar5;
          puVar10 = local_e8;
          goto LAB_14000284a;
        }
        iVar8 = SeQueryInformationToken(puVar12,1,&local_b8);
        if (((iVar8 < 0) || (iVar8 = SeQueryInformationToken(puVar12,0x1f,&local_b0), iVar8 < 0)) ||
           (iVar8 = FltGetFileNameInformation(param_1,0x101,&local_d8), iVar8 < 0))
        goto LAB_140002658;
        local_a8 = BfsAcquireNamedPipeMapping
                             (0x140019250,(byte *)*local_b8,(byte *)*local_b0,
                              (ushort *)(local_d8 + 8));
        if (local_a8 != 0) {
          uVar2 = *(undefined2 *)(local_a8 + 0x40);
          lVar11 = local_a8 + 0x40;
          lStack_80 = ExAllocatePool2(0x100,uVar2,0x46736642);
          if (lStack_80 == 0) {
            if (3 < DAT_140019000) {
              local_f8 = CONCAT44(local_f8._4_4_,0xc0000017);
              local_78 = PTR_DAT_140019008;
              local_70 = (uint)*(ushort *)PTR_DAT_140019008;
              goto LAB_140002520;
            }
          }
          else {
            local_88._0_4_ = CONCAT22(uVar2,(undefined2)local_88);
            RtlCopyUnicodeString(&local_88,lVar11);
            BfsReparseNamedPipe((longlong)param_1,(undefined4 *)&local_88);
            iVar15 = 4;
          }
          goto LAB_140002588;
        }
      }
      if (iVar15 == 0) {
        *local_c8 = (longlong)puVar10;
        goto LAB_1400025a2;
      }
    }
    else {
      puVar10 = (uint *)ExAllocatePool2(0x100,0x58,0x43736642);
      local_e8 = puVar10;
      if (puVar10 != (uint *)0x0) {
        *puVar10 = *puVar10 | 2;
        *(undefined1 *)(puVar10 + 0x12) = 1;
        iVar15 = 0;
        goto LAB_14000262f;
      }
      if (3 < DAT_140019000) {
        local_f8 = CONCAT44(local_f8._4_4_,0xc0000017);
        local_78 = PTR_DAT_140019008;
        local_70 = (uint)*(ushort *)PTR_DAT_140019008;
LAB_140002520:
        local_58 = &local_f8;
        local_108 = 0x30b000000;
        local_50 = 4;
        local_5c = 1;
        uStack_100 = 0;
        local_6c = 2;
        local_68 = &DAT_140016d1c;
        local_60 = 0x1e;
        local_118 = 0x73;
        PTR_DAT_140019008 = local_78;
        EtwWriteTransfer(DAT_140019020,&local_108,0,0);
        puVar10 = local_e8;
      }
    }
LAB_140002588:
    if (puVar10 != (uint *)0x0) {
      ExFreePoolWithTag(puVar10,0);
    }
  }
  else {
    KeLeaveCriticalRegion();
    if (local_114 != '\0') goto LAB_14000248f;
LAB_1400023ba:
    if (3 < DAT_140019000) {
      local_118 = 0xc0000001;
      local_58 = (longlong *)&local_118;
      local_78 = PTR_DAT_140019008;
      local_50 = 4;
      local_108 = 0x30b000000;
      uStack_100 = 0;
      local_70 = (uint)*(ushort *)PTR_DAT_140019008;
      local_68 = &DAT_140016d1c;
      local_6c = 2;
      local_60 = 0x1e;
      local_5c = 1;
      local_f8 = CONCAT44(local_f8._4_4_,0x73);
      EtwWriteTransfer(DAT_140019020,&local_108,0,0);
    }
  }
LAB_1400025a2:
  plVar4 = local_c8;
  if (local_b8 != (undefined8 *)0x0) {
    ExFreePoolWithTag(local_b8,0);
  }
  if (local_b0 != (undefined8 *)0x0) {
    ExFreePoolWithTag(local_b0,0);
  }
  if (local_a8 != 0) {
    BfsReleaseNamedPipeMapping(0x140019250,local_a8);
  }
  if (local_d8 != 0) {
    FltReleaseFileNameInformation();
  }
  uVar9 = Feature_1199833401__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar9 == 0) {
    if (local_114 == '\0') goto LAB_140002ac8;
  }
  else if ((local_114 == '\0') || (*plVar4 != 0)) goto LAB_140002ac8;
  uVar9 = Feature_1199833401__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar9 != 0) {
    KeEnterCriticalRegion();
  }
  ExReleaseRundownProtection(&gBfsRundownProtection);
  KeLeaveCriticalRegion();
LAB_140002ac8:
  if (puVar12 != (ushort *)0x0) {
    if (local_f0 == '\0') {
      PsDereferencePrimaryToken(puVar12);
    }
    else {
      PsDereferenceImpersonationToken();
    }
  }
  return iVar15;
}



===== BfsPreCreatePipeOperation @ 140002b30 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int BfsPreCreatePipeOperation(longlong param_1,longlong param_2,longlong *param_3)

{
  bool bVar1;
  char cVar2;
  bool bVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  ulonglong uVar8;
  longlong lVar9;
  undefined8 uVar10;
  ushort *puVar11;
  longlong lVar12;
  undefined1 auStackY_108 [32];
  int local_d8;
  int local_d4;
  undefined1 local_d0;
  undefined1 local_cf [7];
  ushort local_c8 [8];
  int local_b8 [2];
  longlong local_b0;
  longlong local_a8;
  longlong *local_a0;
  longlong *local_98;
  undefined4 local_90;
  longlong local_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined *local_70;
  uint local_68;
  undefined4 local_64;
  undefined *local_60;
  undefined4 local_58;
  undefined4 local_54;
  int *local_50;
  undefined8 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_108;
  local_cf[0] = 0;
  local_d0 = 0;
  iVar6 = 1;
  local_a8 = 0;
  local_90 = 0;
  local_88 = 0;
  local_80 = 0;
  uStack_78 = 0;
  local_b8[0] = 0;
  if (*(char *)(param_1 + 0x50) == '\0') {
    return 1;
  }
  lVar9 = 0;
  bVar1 = false;
  local_b0 = 0;
  local_98 = (longlong *)0x0;
  local_a0 = (longlong *)0x0;
  KeEnterCriticalRegion();
  cVar2 = ExAcquireRundownProtection(&gBfsRundownProtection);
  uVar8 = Feature_1199833401__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar8 == 0) {
    if (cVar2 != '\0') goto LAB_140002be5;
    KeLeaveCriticalRegion();
  }
  else {
    KeLeaveCriticalRegion();
    if (cVar2 != '\0') {
LAB_140002be5:
      *param_3 = 0;
      lVar9 = PsReferenceImpersonationToken
                        (*(undefined8 *)(param_1 + 8),local_cf,&local_d0,local_b8);
      if (lVar9 == 0) {
        uVar10 = IoGetCurrentProcess();
        lVar9 = PsReferencePrimaryToken(uVar10);
      }
      else {
        bVar1 = true;
        if (local_b8[0] < 2) goto LAB_140002fa3;
      }
      bVar3 = BfsIsApplicableToken(lVar9);
      if (bVar3) {
        iVar5 = FltGetFileNameInformation(param_1,0x101,&local_b0);
        if (iVar5 < 0) {
          if (3 < DAT_140019000) {
            local_c8[4] = 0;
            local_c8[5] = 0;
            local_c8[6] = 0;
            local_c8[7] = 0;
            local_50 = &local_d8;
            local_70 = PTR_DAT_140019008;
            local_c8[2] = 3;
            local_c8[3] = 0;
            local_48 = 4;
            local_c8[0] = 0;
            local_c8[1] = 0xb00;
            local_68 = (uint)*(ushort *)PTR_DAT_140019008;
            local_60 = &DAT_140016d1c;
            local_64 = 2;
            local_58 = 0x1e;
            local_54 = 1;
            local_d4 = 0x73;
            local_d8 = iVar5;
            EtwWriteTransfer(DAT_140019020,local_c8,0,0);
          }
        }
        else {
          puVar11 = BfsGetFileName(local_c8,local_b0);
          local_80 = *(undefined8 *)puVar11;
          uStack_78 = *(undefined8 *)(puVar11 + 4);
          cVar4 = RtlPrefixUnicodeString(&LocalPrefixString,&local_80,1);
          if ((cVar4 == '\0') &&
             (cVar4 = RtlPrefixUnicodeString(&SessionsPrefixString,&local_80,1), cVar4 == '\0')) {
            iVar5 = SeQueryInformationToken(lVar9,1,&local_a0);
            if ((iVar5 < 0) || (iVar5 = SeQueryInformationToken(lVar9,0x1f,&local_98), iVar5 < 0)) {
LAB_140002da8:
              if (3 < DAT_140019000) {
                local_d4 = iVar5;
LAB_140002dbe:
                local_c8[4] = 0;
                local_c8[5] = 0;
                local_c8[6] = 0;
                local_c8[7] = 0;
                local_c8[0] = 0;
                local_c8[1] = 0xb00;
                local_50 = &local_d4;
                local_70 = PTR_DAT_140019008;
                local_c8[2] = 3;
                local_c8[3] = 0;
                local_48 = 4;
                local_68 = (uint)*(ushort *)PTR_DAT_140019008;
                local_60 = &DAT_140016d1c;
                local_64 = 2;
                local_58 = 0x1e;
                local_54 = 1;
                local_d8 = 0x73;
                EtwWriteTransfer(DAT_140019020,local_c8,0,0);
              }
            }
            else {
              if ((*(uint *)(*(longlong *)(param_1 + 0x10) + 0x20) & 0xff000000) == 0x1000000) {
                lVar12 = BfsAcquireNamedPipeMapping
                                   (0x140019250,(byte *)*local_a0,(byte *)*local_98,
                                    (ushort *)(local_b0 + 8));
                if (lVar12 == 0) goto LAB_140002fa3;
                BfsReleaseNamedPipeMapping(0x140019250,lVar12);
              }
              iVar6 = BfsRedirectNamedPipe
                                (*(undefined8 *)(param_2 + 8),param_1,*local_a0,*local_98,local_b0,
                                 (short *)&local_80);
              iVar6 = (iVar6 >> 0x1f & 0xfffffffdU) + 4;
            }
          }
          else {
            iVar5 = FltGetEcpListFromCallbackData(*(undefined8 *)(param_2 + 8),param_1,&local_88);
            if (iVar5 < 0) goto LAB_140002da8;
            if (local_88 != 0) {
              local_a8 = 0;
              iVar7 = FltFindExtraCreateParameter
                                (*(undefined8 *)(param_2 + 8),local_88,&BfsEcpType,&local_a8);
              iVar5 = 0;
              if (iVar7 != -0x3ffffddb) {
                iVar5 = iVar7;
              }
              if (iVar5 < 0) {
                if (3 < DAT_140019000) {
                  local_d4 = iVar5;
                  goto LAB_140002dbe;
                }
              }
              else if ((local_a8 != 0) &&
                      (cVar4 = FltIsEcpFromUserMode(*(undefined8 *)(param_2 + 8)), cVar4 == '\0')) {
                iVar6 = 0;
                *param_3 = *(longlong *)(local_a8 + 8);
              }
            }
          }
        }
      }
    }
  }
LAB_140002fa3:
  if (local_b0 != 0) {
    FltReleaseFileNameInformation();
  }
  uVar8 = Feature_1199833401__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar8 == 0) {
    if (cVar2 == '\0') goto LAB_140003008;
  }
  else if ((cVar2 == '\0') || (*param_3 != 0)) goto LAB_140003008;
  uVar8 = Feature_1199833401__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar8 != 0) {
    KeEnterCriticalRegion();
  }
  ExReleaseRundownProtection(&gBfsRundownProtection);
  KeLeaveCriticalRegion();
LAB_140003008:
  if (local_a0 != (longlong *)0x0) {
    ExFreePoolWithTag(local_a0,0);
  }
  if (local_98 != (longlong *)0x0) {
    ExFreePoolWithTag(local_98,0);
  }
  if (lVar9 != 0) {
    if (bVar1) {
      PsDereferenceImpersonationToken();
    }
    else {
      PsDereferencePrimaryToken(lVar9);
    }
  }
  return iVar6;
}



===== __report_gsfailure @ 1400030b0 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== __C_specific_handler @ 1400030bd =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001400030bd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== BfsClose @ 1400030d0 =====

undefined8 BfsClose(undefined8 param_1,longlong param_2)

{
  *(undefined4 *)(param_2 + 0x30) = 0;
  IofCompleteRequest(param_2,0);
  return 0;
}



===== BfsDeviceIoControl @ 140003100 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong BfsDeviceIoControl(undefined8 param_1,ulonglong param_2)

{
  longlong lVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  longlong *plVar7;
  undefined1 auStack_98 [40];
  undefined1 *local_70;
  char local_68;
  ulonglong local_60;
  longlong *local_58;
  longlong local_50;
  undefined1 local_48 [32];
  ulonglong *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_98;
  local_60 = param_2;
  KeEnterCriticalRegion();
  cVar2 = ExAcquireRundownProtection(&gBfsRundownProtection);
  local_68 = cVar2;
  uVar5 = Feature_1199833401__private_IsEnabledDeviceUsageNoInline();
  if (((int)uVar5 == 0) && (cVar2 != '\0')) {
LAB_14000317b:
    uVar5 = Feature_Servicing_BfsGAFeature__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar5 == 0) {
LAB_1400031db:
      lVar1 = *(longlong *)(param_2 + 0xb8);
      iVar3 = *(int *)(lVar1 + 0x18);
      local_50 = lVar1;
      if (iVar3 == 0x224008) {
        local_60 = local_60 & 0xffffffff00000000;
        uVar4 = 0;
        if (*(uint *)(lVar1 + 0x10) < 8) {
LAB_1400032fa:
          plVar7 = (longlong *)(ulonglong)uVar4;
          *(undefined8 *)(param_2 + 0x38) = 8;
LAB_140003302:
          *(undefined4 *)(param_2 + 0x30) = 0xc0000023;
LAB_14000330a:
          iVar3 = -0x3fffffdd;
          uVar5 = 0xc0000023;
          goto LAB_140003198;
        }
        plVar7 = (longlong *)**(undefined8 **)(param_2 + 0x18);
        if (*(uint *)(lVar1 + 8) < 4) {
          *(undefined8 *)(param_2 + 0x38) = 4;
          goto LAB_140003302;
        }
        uVar5 = BfsProcessQueryPolicySizeRequest(plVar7,(int *)&local_60);
        uVar5 = uVar5 & 0xffffffff;
        **(undefined4 **)(param_2 + 0x18) = (undefined4)local_60;
        *(undefined8 *)(param_2 + 0x38) = 4;
LAB_140003346:
        *(int *)(param_2 + 0x30) = (int)uVar5;
      }
      else {
        if (iVar3 == 0x22400f) {
          local_58 = (longlong *)0x0;
          if (*(uint *)(lVar1 + 0x10) < 8) {
            plVar7 = (longlong *)0x0;
            goto LAB_14000330a;
          }
          ProbeForRead(*(undefined8 *)(lVar1 + 0x20),*(uint *)(lVar1 + 0x10),8);
          local_58 = (longlong *)**(undefined8 **)(lVar1 + 0x20);
          uVar5 = BfsProcessQueryPolicyRequest
                            (local_58,*(uint **)(param_2 + 0x70),*(uint *)(lVar1 + 8));
          uVar4 = (uint)uVar5;
        }
        else if (iVar3 == 0x228004) {
          uVar5 = BfsProcessSetPolicyRequest
                            (*(undefined8 **)(param_2 + 0x18),*(uint *)(lVar1 + 0x10));
          uVar4 = (uint)uVar5;
        }
        else {
          if (iVar3 != 0x228010) {
            uVar5 = 0xc0000010;
            goto LAB_140003346;
          }
          uVar4 = 0xc;
          if (*(uint *)(lVar1 + 0x10) < 8) goto LAB_1400032fa;
          uVar4 = BfsProcessDeletePolicyEntryRequest(**(longlong **)(param_2 + 0x18));
        }
        uVar5 = (ulonglong)uVar4;
        *(uint *)(param_2 + 0x30) = uVar4;
      }
    }
    else {
      plVar7 = gBfsFilterHandle;
      uVar5 = BfsCheckDeleteList(gBfsFilterHandle,0);
      iVar3 = (int)uVar5;
      uVar5 = uVar5 & 0xffffffff;
      if (-1 < iVar3) goto LAB_1400031db;
LAB_140003198:
      if (3 < DAT_140019000) {
        local_60 = CONCAT44(local_60._4_4_,iVar3);
        local_28 = &local_60;
        local_20 = 4;
        local_1c = 0;
        local_70 = local_48;
        _tlgWriteTransfer_EtwWriteTransfer(plVar7,&DAT_140016d11);
      }
    }
    if (cVar2 != '\0') {
      uVar6 = Feature_1199833401__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar6 != 0) {
        KeEnterCriticalRegion();
      }
      ExReleaseRundownProtection(&gBfsRundownProtection);
      KeLeaveCriticalRegion();
      goto LAB_14000338c;
    }
  }
  else {
    KeLeaveCriticalRegion();
    if (cVar2 != '\0') goto LAB_14000317b;
  }
  uVar5 = 0xc0000010;
  *(undefined4 *)(param_2 + 0x30) = 0xc0000010;
LAB_14000338c:
  IofCompleteRequest(param_2,0);
  return uVar5;
}



===== BfsGetPipeNameMappingTable @ 1400033cc =====

undefined * BfsGetPipeNameMappingTable(void)

{
  return &gBfsPipeMappingTable;
}



===== BfsGetPolicyTable @ 1400033dc =====

undefined * BfsGetPolicyTable(void)

{
  return &gBfsPolicyTable;
}



===== BfsInitializeBootDevice @ 1400033ec =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int BfsInitializeBootDevice(undefined4 *param_1)

{
  int iVar1;
  longlong lVar2;
  undefined8 ****ppppuVar3;
  undefined1 auStack_c8 [40];
  undefined1 *local_a0;
  int local_98;
  undefined4 local_94;
  undefined8 ****local_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined4 local_78;
  undefined4 local_74;
  undefined8 local_70;
  undefined8 *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined1 local_48 [32];
  int *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_c8;
  local_90 = (undefined8 ****)0x0;
  local_74 = 0;
  local_5c = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_94 = 0;
  RtlInitUnicodeString(&local_88,L"\\Device\\BootDevice");
  local_68 = &local_88;
  local_78 = 0x30;
  local_70 = 0;
  local_60 = 0x240;
  ppppuVar3 = &local_90;
  local_58 = 0;
  uStack_50 = 0;
  local_98 = ZwOpenSymbolicLinkObject(ppppuVar3,1,&local_78);
  if (local_98 < 0) {
    if (DAT_140019000 < 4) {
      return local_98;
    }
    goto LAB_14000352d;
  }
  ppppuVar3 = local_90;
  local_98 = ZwQuerySymbolicLinkObject(local_90,param_1,&local_94);
  if (local_98 == -0x3fffffdd) {
    if (*(longlong *)(param_1 + 2) != 0) {
      *param_1 = 0;
      ExFreePoolWithTag(*(longlong *)(param_1 + 2),0);
    }
    ppppuVar3 = (undefined8 ****)0x100;
    lVar2 = ExAllocatePool2(0x100,local_94,0x46736642);
    *(longlong *)(param_1 + 2) = lVar2;
    if (lVar2 != 0) {
      *(undefined2 *)((longlong)param_1 + 2) = (undefined2)local_94;
      ppppuVar3 = local_90;
      local_98 = ZwQuerySymbolicLinkObject(local_90,param_1,&local_94);
      goto LAB_14000351d;
    }
    local_98 = -0x3fffffe9;
  }
  else {
LAB_14000351d:
    if (-1 < local_98) {
      return local_98;
    }
  }
  if (DAT_140019000 < 4) {
    return local_98;
  }
LAB_14000352d:
  iVar1 = local_98;
  local_28 = &local_98;
  local_20 = 4;
  local_a0 = local_48;
  _tlgWriteTransfer_EtwWriteTransfer(ppppuVar3,&DAT_140016d11);
  return iVar1;
}



===== BfsOpenPolicyRootDirectory @ 140003580 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int BfsOpenPolicyRootDirectory(undefined8 param_1,undefined8 *param_2)

{
  int iVar1;
  undefined8 *puVar2;
  undefined1 auStack_f8 [32];
  undefined8 local_d8;
  undefined1 *local_d0;
  undefined4 local_c8;
  undefined4 local_c0;
  undefined4 local_b8;
  undefined8 local_b0;
  undefined4 local_a8;
  int local_98 [2];
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined4 local_70;
  undefined4 local_6c;
  undefined *local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined1 local_48 [32];
  int *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_f8;
  local_a8 = 0;
  local_b0 = 0;
  *param_2 = 0;
  local_90 = 0;
  local_6c = 0;
  local_80 = 0;
  local_60 = 0;
  local_b8 = 0x21;
  local_c0 = 3;
  local_c8 = 3;
  puVar2 = &local_90;
  local_88 = 0x30;
  local_d0 = (undefined1 *)CONCAT44(local_d0._4_4_,0x10);
  local_d8 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_70 = 0x240;
  local_68 = &gBfsPolicyStorageDirectoryDescriptor;
  local_78 = param_1;
  iVar1 = ZwCreateFile(puVar2,0x100047,&local_88,&local_58);
  if (iVar1 < 0) {
    if (3 < DAT_140019000) {
      local_1c = 0;
      local_28 = local_98;
      local_d0 = local_48;
      local_20 = 4;
      local_98[0] = iVar1;
      _tlgWriteTransfer_EtwWriteTransfer(puVar2,&DAT_140016d11);
    }
  }
  else {
    *param_2 = local_90;
  }
  return iVar1;
}



===== BfsPostCreatePipeOperation @ 1400036b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 BfsPostCreatePipeOperation(longlong param_1,longlong param_2,undefined8 *param_3)

{
  bool bVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined *puVar4;
  longlong lVar5;
  longlong lVar6;
  undefined1 auStackY_d8 [32];
  char local_98 [4];
  uint local_94;
  longlong local_90;
  undefined4 *local_88;
  undefined8 local_80;
  uint *local_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_d8;
  uVar2 = *(uint *)(param_1 + 0x18);
  local_80 = 0;
  local_90 = 0;
  local_98[0] = '\0';
  local_88 = (undefined4 *)0x0;
  lVar6 = 0;
  bVar1 = false;
  if ((int)uVar2 < 0) {
    if (DAT_140019000 < 4) goto LAB_140003852;
    lVar5 = param_1;
    local_94 = uVar2;
    bVar1 = false;
LAB_140003818:
    uVar2 = local_94;
    local_58 = &local_94;
    local_50 = 4;
    _tlgWriteTransfer_EtwWriteTransfer(lVar5,&DAT_140016d11);
  }
  else {
    if (param_3 == (undefined8 *)0x0) {
      return 0;
    }
    bVar1 = true;
    puVar4 = &gBfsPipeMappingTable;
    uVar2 = BfsInsertNamedPipeMapping
                      (0x140019250,(byte *)*param_3,(byte *)param_3[1],(ushort *)(param_3 + 2),
                       param_3 + 4,local_98,&local_90);
    if (-1 < (int)uVar2) {
      puVar4 = *(undefined **)(param_2 + 8);
      uVar2 = FltAllocateContext(puVar4,0x10,0x10,1);
      lVar6 = local_90;
      if (-1 < (int)uVar2) {
        *local_88 = 1;
        *(longlong *)(local_88 + 2) = local_90;
        uVar3 = Feature_2293653819__private_IsEnabledDeviceUsageNoInline();
        lVar5 = *(longlong *)(param_2 + 0x18);
        if ((int)uVar3 != 0) {
          lVar6 = 0;
        }
        uVar2 = FltSetStreamHandleContext(lVar5,*(undefined8 *)(param_2 + 0x20),0,local_88);
        if (((int)uVar2 < 0) && (3 < DAT_140019000)) {
          local_94 = uVar2;
          goto LAB_140003818;
        }
        goto LAB_14000383d;
      }
    }
    if (3 < DAT_140019000) {
      local_58 = &local_94;
      local_50 = 4;
      local_94 = uVar2;
      _tlgWriteTransfer_EtwWriteTransfer(puVar4,&DAT_140016d11);
    }
    lVar6 = local_90;
  }
LAB_14000383d:
  if (local_88 != (undefined4 *)0x0) {
    FltReleaseContext();
  }
LAB_140003852:
  if (param_3 != (undefined8 *)0x0) {
    if (local_98[0] == '\0') {
      ExFreePoolWithTag(*param_3,0);
      ExFreePoolWithTag(param_3[1],0);
      ExFreePoolWithTag(param_3[3],0);
      ExFreePoolWithTag(param_3[5],0);
    }
    ExFreePoolWithTag(param_3,0);
    uVar3 = Feature_1199833401__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar3 != 0) {
      uVar3 = Feature_1199833401__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar3 != 0) {
        KeEnterCriticalRegion();
      }
      ExReleaseRundownProtection(&gBfsRundownProtection);
      KeLeaveCriticalRegion();
    }
  }
  if ((int)uVar2 < 0) {
    if (lVar6 != 0) {
      BfsReleaseNamedPipeMapping(0x140019250,lVar6);
    }
    if (bVar1) {
      *(uint *)(param_1 + 0x18) = uVar2;
      FltSetCallbackDataDirty(param_1);
      FltCancelFileOpen(*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20));
    }
  }
  return 0;
}



===== BfsPostSetInfoOperation @ 140003970 =====

undefined8 BfsPostSetInfoOperation(longlong param_1,undefined8 param_2,undefined1 *param_3)

{
  uint *puVar1;
  bool bVar2;
  
  if (-1 < *(int *)(param_1 + 0x18)) {
    puVar1 = *(uint **)(*(longlong *)(param_1 + 0x10) + 0x38);
    if (*(int *)(*(longlong *)(param_1 + 0x10) + 0x20) == 0xd) {
      if (puVar1 == (uint *)0x0) goto LAB_1400039a1;
      bVar2 = (char)*puVar1 == '\0';
    }
    else {
      if (puVar1 == (uint *)0x0) goto LAB_1400039a1;
      bVar2 = (*puVar1 & 1) == 0;
    }
    if (!bVar2) {
      *param_3 = 1;
    }
  }
LAB_1400039a1:
  FltReleaseContext(param_3);
  return 0;
}



===== BfsPreSetInfoOperation @ 1400039c0 =====

undefined8 BfsPreSetInfoOperation(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  int iVar1;
  undefined8 local_res8 [4];
  
  local_res8[0] = 0;
  iVar1 = *(int *)(*(longlong *)(param_1 + 0x10) + 0x20);
  if (((iVar1 == 0xd) || (iVar1 == 0x40)) &&
     (iVar1 = BfsGetFileContext(param_2,*(undefined8 *)(*(longlong *)(param_1 + 0x10) + 8),
                                local_res8), -1 < iVar1)) {
    *param_3 = local_res8[0];
    return 0;
  }
  return 1;
}



===== BfsVerifyAce @ 140003a18 =====

int BfsVerifyAce(longlong param_1,char param_2,char param_3,uint param_4,undefined8 param_5,
                undefined1 *param_6)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  char *local_res8;
  
  local_res8 = (char *)0x0;
  iVar3 = -0x3ffffddb;
  uVar4 = 0;
  *param_6 = 0;
  while( true ) {
    if (*(ushort *)(param_1 + 4) <= uVar4) {
      return iVar3;
    }
    iVar3 = RtlGetAce(param_1,uVar4,&local_res8);
    if (iVar3 < 0) break;
    cVar2 = *local_res8;
    if (((cVar2 == param_2) && (local_res8[1] == param_3)) && ((cVar2 == '\0' || (cVar2 == '\x11')))
       ) {
      uVar1 = *(uint *)(local_res8 + 4);
      cVar2 = RtlEqualSid(param_5,local_res8 + 8);
      if ((cVar2 != '\0') && ((uVar1 & param_4) == param_4)) {
        *param_6 = 1;
        return iVar3;
      }
    }
    uVar4 = uVar4 + 1;
  }
  return iVar3;
}



===== Feature_1199833401__private_IsEnabledDeviceUsageNoInline @ 140003ae8 =====

ulonglong Feature_1199833401__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_1199833401__private_featureState;
  if ((Feature_1199833401__private_featureState & 0x10) == 0) {
    uVar1 = Feature_1199833401__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_1199833401__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_1199833401__private_IsEnabledFallback @ 140003b20 =====

void Feature_1199833401__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&wil_details_featureDescriptors_a);
  return;
}



===== Feature_2293653819__private_IsEnabledDeviceUsageNoInline @ 140003b3c =====

ulonglong Feature_2293653819__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_2293653819__private_featureState;
  if ((Feature_2293653819__private_featureState & 0x10) == 0) {
    uVar1 = Feature_2293653819__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_2293653819__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_2293653819__private_IsEnabledFallback @ 140003b74 =====

void Feature_2293653819__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_2293653819__private_descriptor);
  return;
}



===== Feature_2603245880__private_IsEnabledDeviceUsageNoInline @ 140003b90 =====

ulonglong Feature_2603245880__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_2603245880__private_featureState;
  if ((Feature_2603245880__private_featureState & 0x10) == 0) {
    uVar1 = Feature_2603245880__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_2603245880__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_2603245880__private_IsEnabledFallback @ 140003bc8 =====

void Feature_2603245880__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_2603245880__private_descriptor);
  return;
}



===== Feature_Servicing_AppSiloSmbNoTrackDelete__private_IsEnabledDeviceUsageNoInline @ 140003be4 =====

ulonglong Feature_Servicing_AppSiloSmbNoTrackDelete__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_Servicing_AppSiloSmbNoTrackDelete__private_featureState;
  if ((Feature_Servicing_AppSiloSmbNoTrackDelete__private_featureState & 0x10) == 0) {
    uVar1 = Feature_Servicing_AppSiloSmbNoTrackDelete__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_Servicing_AppSiloSmbNoTrackDelete__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_Servicing_AppSiloSmbNoTrackDelete__private_IsEnabledFallback @ 140003c1c =====

void Feature_Servicing_AppSiloSmbNoTrackDelete__private_IsEnabledFallback
               (ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback
            (param_1,param_2,&Feature_Servicing_AppSiloSmbNoTrackDelete__private_descriptor);
  return;
}



===== Feature_Servicing_BfsGAFeature__private_IsEnabledDeviceUsageNoInline @ 140003c38 =====

ulonglong Feature_Servicing_BfsGAFeature__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_Servicing_BfsGAFeature__private_featureState;
  if ((Feature_Servicing_BfsGAFeature__private_featureState & 0x10) == 0) {
    uVar1 = Feature_Servicing_BfsGAFeature__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_Servicing_BfsGAFeature__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_Servicing_BfsGAFeature__private_IsEnabledFallback @ 140003c70 =====

void Feature_Servicing_BfsGAFeature__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_Servicing_BfsGAFeature__private_descriptor)
  ;
  return;
}



===== _tlgDefineProvider_annotation__TlggBfsLoggingHandleProv @ 140003c8c =====

void _tlgDefineProvider_annotation__TlggBfsLoggingHandleProv(void)

{
  return;
}



===== wil_details_FeatureDescriptors_SkipPadding @ 140003c98 =====

longlong * wil_details_FeatureDescriptors_SkipPadding(longlong *param_1)

{
  while( true ) {
    if (&UNK_1400187d7 < param_1) {
      return (longlong *)0x0;
    }
    if (*param_1 != 0) break;
    param_1 = param_1 + 1;
  }
  return param_1;
}



===== wil_details_FeatureReporting_IncrementOpportunityInCache @ 140003cc4 =====

void wil_details_FeatureReporting_IncrementOpportunityInCache
               (uint *param_1,uint param_2,undefined8 param_3,uint *param_4)

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
    uVar3 = uVar2 + 1;
    if ((0x7f < uVar3) || (uVar3 < uVar2)) {
      uVar3 = 1;
      param_4[2] = param_2;
      param_4[1] = uVar2;
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



===== wil_details_FeatureReporting_IncrementUsageInCache @ 140003d9c =====

void wil_details_FeatureReporting_IncrementUsageInCache
               (uint *param_1,uint param_2,undefined8 param_3,uint *param_4)

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
    uVar4 = uVar2 + 1;
    if ((0x1ff < uVar4) || (uVar4 < uVar2)) {
      uVar4 = 1;
      param_4[2] = param_2;
      param_4[1] = uVar2;
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



===== wil_details_FeatureReporting_RecordUsageInCache @ 140003e80 =====

uint * wil_details_FeatureReporting_RecordUsageInCache
                 (uint *param_1,uint *param_2,undefined8 param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  
  uVar5 = (uint)param_3;
  param_1[0] = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  if (uVar5 == 0) {
LAB_140003fd8:
    wil_details_FeatureReporting_IncrementUsageInCache(param_2,uVar5,param_3,param_1);
  }
  else {
    if (uVar5 == 1) {
LAB_140003fcb:
      wil_details_FeatureReporting_IncrementOpportunityInCache(param_2,uVar5,param_3,param_1);
      return param_1;
    }
    if ((uVar5 != 2) && (uVar5 != 3)) {
      if (uVar5 == 4) goto LAB_140003fd8;
      if (uVar5 == 5) goto LAB_140003fcb;
      if ((uVar5 != 6) && (uVar5 != 7)) {
        uVar6 = uVar5 - 0x140;
        if ((int)uVar6 < 0x40) {
          uVar2 = param_2[1];
          do {
            if (((uVar2 & 0x10) == 0) || ((uVar2 >> 5 & 0x3f) != uVar6)) {
              uVar4 = 0;
            }
            else {
              uVar4 = 1;
            }
            param_1[4] = uVar4;
            LOCK();
            uVar4 = param_2[1];
            bVar7 = uVar2 == uVar4;
            if (bVar7) {
              param_2[1] = (uVar6 * 0x20 ^ uVar2) & 0x7e0 ^ uVar2 | 0x10;
            }
            else {
              uVar2 = uVar4;
            }
            UNLOCK();
          } while (!bVar7);
          if (param_1[4] != 0) {
            return param_1;
          }
        }
        param_1[2] = uVar5;
        param_1[1] = 1;
        param_1[3] = param_4;
        return param_1;
      }
    }
    uVar6 = 0;
    if (uVar5 == 2) {
      uVar6 = 2;
    }
    else if (uVar5 == 3) {
      uVar6 = 8;
    }
    else if (uVar5 == 6) {
      uVar6 = 4;
    }
    else if (uVar5 == 7) {
      uVar6 = 0x10;
    }
    uVar2 = 1;
    uVar5 = *param_2;
    do {
      uVar3 = uVar5;
      uVar5 = uVar6 | uVar3;
      param_1[4] = (uint)(uVar5 == uVar3);
      uVar4 = uVar5 | 1;
      if (uVar5 == uVar3) {
        uVar4 = uVar5;
      }
      LOCK();
      uVar1 = *param_2;
      if (uVar3 == uVar1) {
        *param_2 = uVar4;
        uVar5 = uVar3;
      }
      else {
        uVar5 = uVar1;
      }
      UNLOCK();
    } while (uVar3 != uVar1);
    if (((uVar4 & 1) == 0) || ((uVar3 & 1) != 0)) {
      uVar2 = 0;
    }
    *param_1 = uVar2;
  }
  return param_1;
}



===== wil_details_FeatureReporting_ReportUsageToService @ 140004000 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void wil_details_FeatureReporting_ReportUsageToService
               (longlong param_1,undefined8 param_2,int param_3)

{
  bool bVar1;
  uint uVar2;
  undefined7 extraout_var;
  uint uVar3;
  int local_res18 [4];
  
  uVar3 = (uint)param_2 & 1;
  local_res18[0] = param_3;
  uVar2 = wil_details_MapReportingKind(param_3,uVar3);
  bVar1 = wil_details_FeatureReporting_ReportUsageToServiceDirect(param_1,param_2,(ulonglong)uVar2);
  if (((int)CONCAT71(extraout_var,bVar1) != 0) &&
     (g_wil_details_pfnFeatureLoggingHook != (code *)0x0)) {
    (*g_wil_details_pfnFeatureLoggingHook)
              (*(undefined4 *)(param_1 + 0x18),*(undefined8 *)(param_1 + 0x10),0,uVar3,local_res18,0
               ,0,1);
  }
  return;
}



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 140004084 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool wil_details_FeatureReporting_ReportUsageToServiceDirect
               (longlong param_1,undefined8 param_2,ulonglong param_3)

{
  uint6 uVar1;
  uint *puVar2;
  undefined1 auStack_98 [32];
  uint *local_78;
  undefined8 local_68;
  uint local_60 [6];
  uint local_48;
  uint uStack_44;
  uint uStack_40;
  uint uStack_3c;
  undefined8 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_98;
  puVar2 = wil_details_FeatureReporting_RecordUsageInCache
                     (local_60,*(uint **)(param_1 + 8),param_3,(uint)((ulonglong)param_2 >> 0x20));
  local_48 = *puVar2;
  uStack_44 = puVar2[1];
  uStack_40 = puVar2[2];
  uStack_3c = puVar2[3];
  local_38 = *(undefined8 *)(puVar2 + 4);
  if (g_wil_details_recordFeatureUsage != (code *)0x0) {
    local_78 = &local_48;
    (*g_wil_details_recordFeatureUsage)
              (*(undefined4 *)(param_1 + 0x18),param_3 & 0xffffffff,1,*(undefined8 *)(param_1 + 8));
  }
  if ((((uint)param_2 >> 10 & 1) != 0) && ((int)param_3 != 0xfe)) {
    local_68._0_6_ = CONCAT24((short)(param_3 & 0xffffffff),*(undefined4 *)(param_1 + 0x18));
    uVar1 = (uint6)local_68;
    local_68 = (ulonglong)(uint6)local_68;
    if (((uint)param_2 >> 0xb & 1) != 0) {
      local_68 = CONCAT26(1,uVar1);
    }
    RtlNotifyFeatureUsage(&local_68);
  }
  return (int)local_38 == 0;
}



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 140004174 =====

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



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 140004284 =====

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



===== wil_details_GetCurrentFeatureEnabledState @ 1400042e8 =====

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
  ulonglong local_res10;
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
        uVar7 = *(uint *)*puVar3;
        local_res10 = (ulonglong)uVar7;
        if ((uVar7 & 2) == 0) {
          uVar6 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                            ((uint *)*puVar3,local_res10,(longlong)puVar3);
          uVar7 = (uint)uVar6;
        }
        uVar4 = local_res8 & 0xfffffffe;
        local_res8 = (uint)((uVar7 & local_res8 & 1) != 0);
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



===== wil_details_IsEnabledFallback @ 140004448 =====

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
     (wil_details_FeatureReporting_ReportUsageToService((longlong)param_3,local_res8,param_2),
     param_2 - 3U < 2)) {
    wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath((uint)local_res8,param_2,param_3);
  }
  return (uint)param_1 & 1;
}



===== wil_details_MapReportingKind @ 1400044dc =====

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



===== wil_details_RecordCachedUsage @ 14000457c =====

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



===== wil_details_RecordFeatureUsageReporting @ 1400046d0 =====

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



===== BfsAllocateAndConcatenatePath @ 140004754 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint BfsAllocateAndConcatenatePath(short *param_1,short *param_2,undefined8 *param_3)

{
  uint uVar1;
  undefined2 *puVar2;
  undefined1 auStack_b8 [40];
  undefined1 *local_90;
  uint local_88 [2];
  undefined2 local_80;
  short sStack_7e;
  undefined4 uStack_7c;
  longlong lStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined1 local_60 [32];
  uint *local_40;
  undefined8 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_b8;
  uStack_7c = 0;
  local_70 = 0;
  uStack_68 = 0;
  RtlInitUnicodeString(&local_70,L"\\");
  puVar2 = (undefined2 *)0x100;
  sStack_7e = (short)local_70 + *param_1 + *param_2;
  local_80 = 0;
  lStack_78 = ExAllocatePool2(0x100,sStack_7e,0x4e736642);
  if (lStack_78 == 0) {
    uVar1 = 0xc0000017;
    if (DAT_140019000 < 4) goto LAB_140004873;
    local_88[0] = 0xc0000017;
  }
  else {
    if (*param_1 == 0) {
LAB_140004829:
      puVar2 = &local_80;
      uVar1 = RtlAppendUnicodeStringToString(puVar2,param_2);
      if (-1 < (int)uVar1) {
        *param_3 = CONCAT44(uStack_7c,CONCAT22(sStack_7e,local_80));
        param_3[1] = lStack_78;
        return uVar1;
      }
    }
    else {
      puVar2 = &local_80;
      uVar1 = RtlAppendUnicodeStringToString(puVar2,param_1);
      if (-1 < (int)uVar1) {
        puVar2 = &local_80;
        uVar1 = RtlAppendUnicodeStringToString(puVar2,&local_70);
        if (-1 < (int)uVar1) goto LAB_140004829;
      }
    }
    if (DAT_140019000 < 4) goto LAB_140004873;
    local_88[0] = uVar1;
  }
  uVar1 = local_88[0];
  local_40 = local_88;
  local_38 = 4;
  local_90 = local_60;
  _tlgWriteTransfer_EtwWriteTransfer(puVar2,&DAT_140016d11);
LAB_140004873:
  if (lStack_78 != 0) {
    RtlFreeUnicodeString(&local_80);
  }
  return uVar1;
}



===== BfsApplyPolicyAsUser @ 1400048b8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint BfsApplyPolicyAsUser
               (longlong param_1,longlong param_2,undefined8 param_3,longlong param_4,
               longlong *param_5)

{
  longlong lVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  longlong lVar6;
  undefined1 auStack_128 [32];
  longlong *local_108;
  longlong *local_100;
  longlong *local_f8;
  uint local_e8 [2];
  longlong local_e0;
  longlong local_d8;
  longlong local_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 *puStack_90;
  undefined8 local_88;
  undefined4 local_80;
  longlong local_78 [4];
  uint *local_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_128;
  local_88 = 0;
  local_80 = 0;
  local_e0 = 0;
  local_f8 = &local_d0;
  local_d8 = 0;
  local_100 = (longlong *)((ulonglong)local_100 & 0xffffffffffffff00);
  local_d0 = 0;
  local_108 = *(longlong **)SeTokenObjectType_exref;
  local_c8 = 0;
  uStack_c0 = 0;
  local_b8 = 0;
  uStack_b0 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  local_98 = 0;
  puStack_90 = (undefined8 *)0x0;
  uVar5 = ObOpenObjectByPointer(param_2,0x200,0,0xf01ff);
  if ((int)uVar5 < 0) {
LAB_14000495d:
    if (3 < DAT_140019000) {
      local_e8[0] = uVar5;
LAB_140004a97:
      uVar5 = local_e8[0];
      local_58 = local_e8;
      local_50 = 4;
      local_100 = local_78;
      _tlgWriteTransfer_EtwWriteTransfer(param_2,&DAT_140016d11);
    }
  }
  else {
    local_b8 = CONCAT44(local_b8._4_4_,0x30);
    puStack_90 = &local_88;
    local_100 = &local_e0;
    uStack_b0 = 0;
    local_108 = (longlong *)CONCAT44(local_108._4_4_,2);
    uStack_a0 = CONCAT44(uStack_a0._4_4_,0x200);
    local_a8 = 0;
    local_98 = 0;
    local_88 = 0x20000000c;
    local_80 = CONCAT22(local_80._2_2_,1);
    param_2 = local_d0;
    uVar5 = ZwDuplicateToken(local_d0,0xf01ff,&local_b8,0);
    if ((int)uVar5 < 0) goto LAB_14000495d;
    local_108 = &local_d8;
    local_100 = (longlong *)0x0;
    param_2 = local_e0;
    uVar5 = ObReferenceObjectByHandle(local_e0,0xf01ff,*(undefined8 *)SeTokenObjectType_exref,0);
    if ((int)uVar5 < 0) goto LAB_14000495d;
    local_c8 = *(undefined8 *)(*(longlong *)SeExports_exref + 0x1e8);
    uStack_c0 = CONCAT44(uStack_c0._4_4_,0x60);
    param_2 = local_e0;
    uVar5 = ZwSetInformationToken(local_e0,0x19,&local_c8);
    if ((int)uVar5 < 0) goto LAB_14000495d;
    lVar6 = *param_5;
    if (lVar6 != 0) {
LAB_140004ad9:
      *(undefined4 *)(lVar6 + 8) = 0;
      lVar6 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x10) + 0x18) + 8);
      lVar1 = *param_5;
      uVar2 = *(undefined4 *)(lVar6 + 0x24);
      uVar3 = *(undefined4 *)(lVar6 + 0x28);
      uVar4 = *(undefined4 *)(lVar6 + 0x2c);
      *(undefined4 *)(lVar1 + 0x10) = *(undefined4 *)(lVar6 + 0x20);
      *(undefined4 *)(lVar1 + 0x14) = uVar2;
      *(undefined4 *)(lVar1 + 0x18) = uVar3;
      *(undefined4 *)(lVar1 + 0x1c) = uVar4;
      uVar2 = *(undefined4 *)(lVar6 + 0x34);
      uVar3 = *(undefined4 *)(lVar6 + 0x38);
      uVar4 = *(undefined4 *)(lVar6 + 0x3c);
      *(undefined4 *)(lVar1 + 0x20) = *(undefined4 *)(lVar6 + 0x30);
      *(undefined4 *)(lVar1 + 0x24) = uVar2;
      *(undefined4 *)(lVar1 + 0x28) = uVar3;
      *(undefined4 *)(lVar1 + 0x2c) = uVar4;
      *(longlong *)(*(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x10) + 0x18) + 8) + 0x20) =
           local_d8;
      *(undefined4 *)(*(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x10) + 0x18) + 8) + 0x28)
           = 2;
      FltReferenceFileNameInformation(param_3);
      *(undefined8 *)(*param_5 + 0x30) = param_3;
      LOCK();
      *(int *)(param_4 + 0x90) = *(int *)(param_4 + 0x90) + 1;
      UNLOCK();
      *(longlong *)(*param_5 + 0x40) = param_4;
      *(uint *)*param_5 = *(uint *)*param_5 | 1;
      goto LAB_140004b4f;
    }
    param_2 = 0x100;
    lVar6 = ExAllocatePool2(0x100,0x58,0x43736642);
    *param_5 = lVar6;
    if (lVar6 != 0) goto LAB_140004ad9;
    uVar5 = 0xc0000017;
    if (3 < DAT_140019000) {
      local_e8[0] = 0xc0000017;
      goto LAB_140004a97;
    }
  }
  if (local_d8 != 0) {
    ObfDereferenceObject();
  }
LAB_140004b4f:
  if (local_e0 != 0) {
    ZwClose();
  }
  if (local_d0 != 0) {
    ZwClose();
  }
  return uVar5;
}



===== BfsBuildPathFromComponents @ 140004ba4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint BfsBuildPathFromComponents(undefined8 *param_1,short *param_2,short *param_3,longlong *param_4)

{
  ushort uVar1;
  uint uVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  undefined1 auStack_d8 [40];
  undefined1 *local_b0;
  uint local_a8 [2];
  longlong local_a0;
  longlong lStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined1 local_80 [32];
  uint *local_60;
  undefined8 local_58;
  ulonglong local_50;
  
  local_50 = __security_cookie ^ (ulonglong)auStack_d8;
  local_90 = 0;
  uStack_88 = 0;
  RtlInitUnicodeString(&local_90,L"\\");
  uVar1 = BfsGetPathLength(param_1,param_2,param_3);
  lStack_98 = ExAllocatePool2(0x100,uVar1,0x46736642);
  if (lStack_98 == 0) {
    return 0xc0000017;
  }
  puVar4 = (undefined8 *)*param_1;
  local_a0 = (ulonglong)uVar1 << 0x10;
  for (; puVar4 != param_1; puVar4 = (undefined8 *)*puVar4) {
    if (*(short *)(puVar4 + 3) != 0) {
      plVar3 = &local_a0;
      uVar2 = RtlAppendUnicodeStringToString();
      if ((int)uVar2 < 0) goto LAB_140004cd9;
      plVar3 = &local_a0;
      uVar2 = RtlAppendUnicodeStringToString(plVar3,&local_90);
      if ((int)uVar2 < 0) goto LAB_140004cd9;
    }
  }
  plVar3 = &local_a0;
  uVar2 = RtlAppendUnicodeStringToString(plVar3,param_2);
  if (-1 < (int)uVar2) {
    if (*param_3 == 0) {
LAB_140004d1c:
      *param_4 = local_a0;
      param_4[1] = lStack_98;
      return uVar2;
    }
    plVar3 = &local_a0;
    uVar2 = RtlAppendUnicodeStringToString(plVar3,&local_90);
    if (-1 < (int)uVar2) {
      plVar3 = &local_a0;
      uVar2 = RtlAppendUnicodeStringToString(plVar3,param_3);
      if (-1 < (int)uVar2) goto LAB_140004d1c;
    }
  }
LAB_140004cd9:
  if (3 < DAT_140019000) {
    local_60 = local_a8;
    local_58 = 4;
    local_b0 = local_80;
    local_a8[0] = uVar2;
    _tlgWriteTransfer_EtwWriteTransfer(plVar3,&DAT_140016d11);
  }
  RtlFreeUnicodeString(&local_a0);
  return uVar2;
}



===== BfsCheckAndApplyPolicy @ 140004d50 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
BfsCheckAndApplyPolicy
          (longlong *param_1,longlong param_2,ushort *param_3,ushort *param_4,longlong *param_5)

{
  byte bVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  ushort *puVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  longlong lVar9;
  longlong *plVar10;
  longlong lVar11;
  undefined1 uVar12;
  undefined1 auStackY_118 [32];
  uint local_e8;
  char local_e4;
  char local_e3 [3];
  longlong local_e0;
  longlong local_d8;
  undefined8 *local_d0;
  undefined8 *local_c8;
  ushort *local_c0;
  longlong local_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  ushort local_90 [24];
  uint *local_60;
  undefined8 local_58;
  ulonglong local_50;
  
  local_50 = __security_cookie ^ (ulonglong)auStackY_118;
  local_e3[0] = '\0';
  local_d0 = (undefined8 *)0x0;
  local_e0 = 0;
  local_d8 = 0;
  local_c8 = (undefined8 *)0x0;
  uVar12 = 0;
  local_b0 = 0;
  uStack_a8 = 0;
  puVar6 = param_3;
  uVar3 = SeQueryInformationToken(param_3,1,&local_d0);
  if (((int)uVar3 < 0) ||
     (puVar6 = param_3, uVar3 = SeQueryInformationToken(param_3,0x1f,&local_c8), (int)uVar3 < 0)) {
    if (DAT_140019000 < 4) goto LAB_140005253;
    local_e8 = uVar3;
  }
  else {
    uVar3 = FltGetFileNameInformation(param_4,0x101,&local_d8);
    if (uVar3 == 0xc0000201) {
      local_b8 = 0;
      local_c0 = param_3;
      uVar3 = BfsQueueDeferredWorkItemAndWait
                        ((longlong)param_1,param_2,param_4,&local_c0,
                         BfsQueryFileNameInformationCallback);
      local_d8 = local_b8;
    }
    puVar6 = (ushort *)(ulonglong)uVar3;
    if (-1 < (int)uVar3) {
      bVar1 = BfsPolicyEntryExists(param_1,param_2,0x140019260,(byte *)*local_d0,(byte *)*local_c8);
      if (bVar1 == 0) {
        plVar10 = (longlong *)&gBfsPolicyTable;
        uVar8 = BfsGetNotPresentPolicyEntry
                          (0x140019260,(byte *)*local_d0,(byte *)*local_c8,&local_e0);
        uVar4 = (uint)uVar8;
        uVar3 = local_e8;
        if ((int)(uint)uVar8 < 0) goto joined_r0x0001400050c7;
        lVar11 = local_e0;
LAB_140004fd2:
        local_e4 = '\0';
        puVar6 = (ushort *)0x0;
        uVar3 = RtlCheckTokenCapability
                          (0,*(undefined8 *)(*(longlong *)SeExports_exref + 0x250),&local_e4);
        if ((int)uVar3 < 0) {
          if (uVar3 != 0xc0000022) goto LAB_140005028;
LAB_14000519b:
          if ((local_d8 == 0) &&
             (uVar3 = FltGetFileNameInformation(param_4,0x101,&local_d8), puVar6 = param_4,
             (int)uVar3 < 0)) goto LAB_140005028;
          lVar9 = *param_5;
          if (lVar9 != 0) {
LAB_140005204:
            *(undefined4 *)(lVar9 + 8) = 1;
            FltReferenceFileNameInformation(local_d8);
            *(longlong *)(*param_5 + 0x30) = local_d8;
            *(longlong *)(*param_5 + 0x40) = lVar11;
            LOCK();
            *(int *)(lVar11 + 0x90) = *(int *)(lVar11 + 0x90) + 1;
            UNLOCK();
            uVar12 = 1;
            *(uint *)*param_5 = *(uint *)*param_5 | 1;
            uVar3 = local_e8;
            goto LAB_14000523f;
          }
          puVar6 = (ushort *)0x100;
          lVar9 = ExAllocatePool2(0x100,0x58,0x43736642);
          *param_5 = lVar9;
          if (lVar9 != 0) goto LAB_140005204;
          if (DAT_140019000 < 4) goto LAB_140005244;
          local_e8 = 0xc0000017;
        }
        else {
          if (local_e4 == '\0') goto LAB_14000519b;
          puVar6 = param_3;
          uVar3 = BfsFileInPublisherDirectory(param_3,local_d8,(ushort *)local_e3,&local_b0);
          if ((int)uVar3 < 0) goto LAB_140005028;
          if (local_e3[0] == '\0') goto LAB_14000519b;
          if (lVar11 == 0) {
LAB_14000508d:
            plVar10 = param_1;
            uVar4 = BfsGetPolicyEntry(param_1,param_2,(longlong *)&gBfsPolicyTable,(byte *)*local_d0
                                      ,(byte *)*local_c8,&local_e0);
            uVar3 = local_e8;
            if ((int)uVar4 < 0) goto joined_r0x0001400050c7;
            lVar11 = local_e0;
          }
          else if (*(int *)(lVar11 + 0x38) == 2) {
            BfsDereferencePolicyEntryEx(lVar11,'\0');
            local_e0 = 0;
            goto LAB_14000508d;
          }
          uVar7 = Feature_1827994938__private_IsEnabledDeviceUsageNoInline();
          if (((int)uVar7 != 0) && (*(int *)(lVar11 + 0x38) == 0x10000001)) {
            BfsDereferencePolicyEntryEx(lVar11,'\0');
            local_e0 = 0;
            uVar4 = BfsGetPolicyEntry(param_1,param_2,(longlong *)&gBfsPolicyTable,(byte *)*local_d0
                                      ,(byte *)*local_c8,&local_e0);
            plVar10 = param_1;
            uVar3 = local_e8;
            if ((int)uVar4 < 0) goto joined_r0x0001400050c7;
            lVar11 = local_e0;
          }
          BfsAddOrModifyEntry(*(longlong *)(lVar11 + 0x30),2,1,2,(ushort *)(local_d8 + 0x18),
                              (short *)&local_b0);
LAB_140005168:
          uVar3 = BfsApplyPolicyAsUser((longlong)param_4,(longlong)param_3,local_d8,lVar11,param_5);
          puVar6 = param_4;
          if (-1 < (int)uVar3) {
            uVar12 = 1;
            goto LAB_140005244;
          }
LAB_140005028:
          if (DAT_140019000 < 4) goto LAB_140005244;
          local_e8 = uVar3;
        }
        local_60 = &local_e8;
        local_58 = 4;
        _tlgWriteTransfer_EtwWriteTransfer(puVar6,&DAT_140016d11);
      }
      else {
        plVar10 = param_1;
        uVar4 = BfsGetPolicyEntry(param_1,param_2,(longlong *)&gBfsPolicyTable,(byte *)*local_d0,
                                  (byte *)*local_c8,&local_e0);
        uVar3 = local_e8;
        if ((int)uVar4 < 0) {
joined_r0x0001400050c7:
          local_e8 = uVar4;
          if (3 < DAT_140019000) {
            local_58 = 4;
            local_60 = &local_e8;
            _tlgWriteTransfer_EtwWriteTransfer(plVar10,&DAT_140016d11);
            uVar3 = local_e8;
          }
LAB_14000523f:
          local_e8 = uVar3;
          lVar11 = local_e0;
        }
        else {
          lVar9 = local_d8;
          puVar6 = BfsGetFileName(local_90,local_d8);
          lVar11 = local_e0;
          local_a0 = *(undefined8 *)puVar6;
          uStack_98 = *(undefined8 *)(puVar6 + 4);
          uVar7 = BfsGetPolicy(*(longlong *)(local_e0 + 0x30),(ushort *)(lVar9 + 0x18),&local_a0);
          iVar5 = (int)uVar7;
          if (iVar5 == 0) goto LAB_140004fd2;
          if (iVar5 == 1) goto LAB_140005168;
          if (iVar5 == 2) {
            bVar2 = BfsQueryAccessOnly((*(uint *)(*(longlong *)(param_4 + 8) + 0x20) & 1) + 1,
                                       (longlong)param_4);
            if (bVar2) goto LAB_140005168;
            bVar2 = BfsQueryAccessOnly((*(uint *)(*(longlong *)(param_4 + 8) + 0x20) & 1) + 1,
                                       (longlong)param_4);
            if (!bVar2) goto LAB_14000519b;
          }
        }
      }
LAB_140005244:
      if (lVar11 != 0) {
        BfsDereferencePolicyEntryEx(lVar11,'\0');
      }
      goto LAB_140005253;
    }
    if (DAT_140019000 < 4) goto LAB_140005253;
    local_e8 = uVar3;
  }
  local_60 = &local_e8;
  local_58 = 4;
  _tlgWriteTransfer_EtwWriteTransfer(puVar6,&DAT_140016d11);
LAB_140005253:
  if (local_d8 != 0) {
    FltReleaseFileNameInformation();
  }
  if (local_d0 != (undefined8 *)0x0) {
    ExFreePoolWithTag(local_d0,0);
  }
  if (local_c8 != (undefined8 *)0x0) {
    ExFreePoolWithTag(local_c8,0);
  }
  return uVar12;
}



===== BfsCheckAndReleaseIdlePolicy @ 1400052c4 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void BfsCheckAndReleaseIdlePolicy(longlong param_1)

{
  undefined8 *puVar1;
  int *piVar2;
  undefined8 ***pppuVar3;
  undefined8 ***pppuVar4;
  int iVar5;
  undefined8 uVar6;
  code *pcVar7;
  ulonglong uVar8;
  undefined8 *puVar9;
  undefined1 *puVar10;
  undefined8 ***pppuVar11;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  undefined8 ***local_18;
  undefined8 ***local_10;
  
  local_10 = &local_18;
  pppuVar11 = (undefined8 ***)(_DAT_fffff78000000014 + -3000000000);
  local_18 = &local_18;
  uVar8 = Feature_3434922298__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar8 == 0) {
    KeEnterCriticalRegion();
    ExAcquirePushLockSharedEx(param_1,0);
  }
  else {
    KeEnterCriticalRegion();
    ExAcquirePushLockExclusiveEx(param_1,0);
  }
  puVar1 = (undefined8 *)(param_1 + 0x10);
  puVar9 = (undefined8 *)*puVar1;
  do {
    if (puVar9 == puVar1) {
      uVar8 = Feature_3434922298__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar8 == 0) {
        ExReleasePushLockSharedEx(param_1,0);
        KeLeaveCriticalRegion();
      }
      puVar10 = auStack_38;
      if ((undefined8 ****)local_18 != &local_18) {
        uVar8 = Feature_3434922298__private_IsEnabledDeviceUsageNoInline();
        if ((int)uVar8 == 0) {
          KeEnterCriticalRegion();
          ExAcquirePushLockExclusiveEx(param_1,0);
        }
        puVar10 = auStack_38;
        pppuVar11 = local_18;
        while ((undefined8 ****)pppuVar11 != &local_18) {
LAB_140005410:
          pppuVar3 = pppuVar11 + -10;
          pppuVar4 = pppuVar11 + 8;
          pppuVar11 = (undefined8 ***)*pppuVar11;
          if (*(int *)pppuVar4 == 2) {
            *(undefined8 *)(puVar10 + -8) = 0x14000542d;
            BfsDereferencePolicyEntryEx((longlong)pppuVar3,'\x01');
          }
          *(undefined8 *)(puVar10 + -8) = 0x140005437;
          BfsDereferencePolicyEntryEx((longlong)pppuVar3,'\x01');
        }
        if ((undefined8 *)*puVar1 == puVar1) {
          uVar6 = *(undefined8 *)(param_1 + 0x20);
          *(undefined8 *)(puVar10 + -8) = 0x140005452;
          ExCancelTimer(uVar6,0);
        }
        *(undefined8 *)(puVar10 + -8) = 0x14000545c;
        uVar8 = Feature_3434922298__private_IsEnabledDeviceUsageNoInline();
        if ((int)uVar8 == 0) {
          *(undefined8 *)(puVar10 + -8) = 0x14000546c;
          ExReleasePushLockExclusiveEx(param_1,0);
          *(undefined8 *)(puVar10 + -8) = 0x140005478;
          KeLeaveCriticalRegion();
        }
      }
      *(undefined8 *)(puVar10 + -8) = 0x140005482;
      uVar8 = Feature_3434922298__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar8 != 0) {
        *(undefined8 *)(puVar10 + -8) = 0x140005492;
        ExReleasePushLockExclusiveEx(param_1,0);
        *(undefined8 *)(puVar10 + -8) = 0x14000549e;
        KeLeaveCriticalRegion();
      }
      return;
    }
    if ((longlong)puVar9[4] < (longlong)pppuVar11) {
      LOCK();
      piVar2 = (int *)(puVar9 + 10);
      iVar5 = *piVar2;
      *piVar2 = *piVar2 + 1;
      UNLOCK();
      if (iVar5 == 1) {
        pppuVar3 = (undefined8 ***)(puVar9 + 2);
        if ((undefined8 ****)*local_10 != &local_18) {
          pcVar7 = (code *)swi(0x29);
          (*pcVar7)(3);
          puVar10 = auStack_30;
          goto LAB_140005410;
        }
        puVar9[3] = local_10;
        *pppuVar3 = &local_18;
        *local_10 = pppuVar3;
        local_10 = pppuVar3;
      }
      else {
        LOCK();
        *(int *)(puVar9 + 10) = *(int *)(puVar9 + 10) + -1;
        UNLOCK();
      }
    }
    puVar9 = (undefined8 *)*puVar9;
  } while( true );
}



===== BfsDereferencePolicyEntryEx @ 1400054c4 =====

void BfsDereferencePolicyEntryEx(longlong param_1,char param_2)

{
  longlong *plVar1;
  int *piVar2;
  int iVar3;
  longlong lVar4;
  longlong *plVar5;
  code *pcVar6;
  
  if (param_2 == '\0') {
    KeEnterCriticalRegion();
    ExAcquirePushLockExclusiveEx(&gBfsPolicyTable,0);
  }
  LOCK();
  piVar2 = (int *)(param_1 + 0x90);
  iVar3 = *piVar2;
  *piVar2 = *piVar2 + -1;
  UNLOCK();
  if (iVar3 == 1) {
    if (*(longlong *)(param_1 + 0x18) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_1 + 0x18),0);
    }
    if (*(longlong *)(param_1 + 0x20) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_1 + 0x20),0);
    }
    if (*(longlong *)(param_1 + 0x28) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_1 + 0x28),0);
    }
    if (*(longlong *)(param_1 + 0x30) != 0) {
      BfsCloseStorage(*(longlong *)(param_1 + 0x30));
    }
    plVar1 = (longlong *)(param_1 + 0x40);
    lVar4 = *plVar1;
    if ((lVar4 != 0) && (*(longlong *)(param_1 + 0x48) != 0)) {
      if ((*(longlong **)(lVar4 + 8) != plVar1) ||
         (plVar5 = *(longlong **)(param_1 + 0x48), (longlong *)*plVar5 != plVar1)) {
        pcVar6 = (code *)swi(0x29);
        (*pcVar6)(3);
        pcVar6 = (code *)swi(3);
        (*pcVar6)();
        return;
      }
      *plVar5 = lVar4;
      *(longlong **)(lVar4 + 8) = plVar5;
    }
    if (*(longlong *)(param_1 + 0x78) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_1 + 0x78),0);
    }
    if (*(longlong *)(param_1 + 0x88) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_1 + 0x88),0);
    }
    BfsRemoveEntryHashTable(DAT_140019268,param_1);
    ExFreePoolWithTag(param_1,0);
  }
  if (param_2 == '\0') {
    ExReleasePushLockExclusiveEx(&gBfsPolicyTable,0);
    KeLeaveCriticalRegion();
  }
  return;
}



===== BfsEnumeratePolicy @ 140005624 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong BfsEnumeratePolicy(longlong param_1,longlong *param_2,int *param_3,int *param_4)

{
  int *piVar1;
  undefined8 uVar2;
  longlong *plVar3;
  longlong lVar4;
  code *pcVar5;
  undefined8 ****ppppuVar6;
  int *piVar7;
  ushort uVar8;
  uint uVar9;
  ulonglong uVar10;
  undefined8 ****ppppuVar11;
  undefined8 *puVar12;
  undefined8 ****ppppuVar13;
  wchar_t *pwVar14;
  undefined8 ****ppppuVar15;
  undefined8 ****ppppuVar16;
  undefined1 *puVar17;
  int iVar18;
  int iVar19;
  uint uVar20;
  undefined1 auStack_128 [8];
  undefined1 auStack_120 [32];
  undefined1 *local_100;
  uint local_f8 [2];
  undefined8 ****local_f0;
  undefined8 ****local_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 ****local_c8;
  int *local_c0;
  short local_b8 [8];
  undefined8 ****local_a8;
  int *local_a0;
  int *local_98;
  longlong local_90;
  undefined1 local_88 [32];
  uint *local_68;
  undefined8 local_60;
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStack_128;
  local_c0 = (int *)0x0;
  local_f8[0] = 0;
  iVar18 = 0;
  local_e0 = (undefined8 ***)0x0;
  uStack_d8 = (undefined8 ***)0x0;
  local_b8[0] = 0;
  local_b8[1] = 0;
  local_b8[2] = 0;
  local_b8[3] = 0;
  local_b8[4] = 0;
  local_b8[5] = 0;
  local_b8[6] = 0;
  local_b8[7] = 0;
  if (param_3 != (int *)0x0) {
    *param_3 = 0;
  }
  local_a0 = param_4;
  local_98 = param_3;
  local_90 = param_1;
  uVar10 = Feature_AppSiloEnumeratePolicyCheck__private_IsEnabledDeviceUsageNoInline();
  puVar17 = auStack_128;
  if (((int)uVar10 != 0) && (*(int *)(param_1 + 0x38) != 0x10000000)) {
    *param_4 = 0;
    uVar10 = 0;
    goto LAB_140005a94;
  }
  uVar2 = *(undefined8 *)(param_1 + 0x30);
  local_e8 = &local_f0;
  local_f0 = &local_f0;
  KeEnterCriticalRegion();
  ExAcquirePushLockSharedEx(uVar2,0);
  ppppuVar15 = (undefined8 ****)(*(longlong *)(param_1 + 0x30) + 0x30);
  ppppuVar13 = (undefined8 ****)0x100;
  local_a8 = ppppuVar15;
  ppppuVar11 = (undefined8 ****)ExAllocatePool2(0x100,0x30,0x63456642);
  if (ppppuVar11 == (undefined8 ****)0x0) {
LAB_14000570b:
    uVar9 = 0xc0000017;
    ppppuVar16 = (undefined8 ****)0xc0000017;
LAB_140005712:
    if (3 < DAT_140019000) {
      local_68 = local_f8;
      local_60 = 4;
      local_100 = local_88;
      local_f8[0] = uVar9;
      _tlgWriteTransfer_EtwWriteTransfer(ppppuVar13,&DAT_140016d11);
    }
  }
  else {
    ppppuVar11[2] = ppppuVar15;
    *(undefined4 *)(ppppuVar11 + 5) = 0;
    iVar19 = 0;
    RtlInitUnicodeString(ppppuVar11 + 3,L"");
    RtlInitUnicodeString(&local_e0,L"");
    uVar20 = 0;
    local_c8 = ppppuVar15;
LAB_140005806:
    do {
      ppppuVar13 = ppppuVar15;
      uVar10 = BfsEnumerateDirectory((longlong)ppppuVar15,iVar19,(longlong *)&local_c0);
      piVar7 = local_c0;
      ppppuVar6 = local_e8;
      iVar19 = iVar19 + 1;
      uVar9 = (uint)uVar10;
      ppppuVar16 = (undefined8 ****)(uVar10 & 0xffffffff);
      if ((int)uVar9 < 0) {
        if (uVar9 != 0x8000001a) goto LAB_140005712;
        if ((undefined8 *****)local_f0 != &local_f0) {
          ppppuVar16 = ppppuVar11;
          if (((undefined8 *****)*local_e8 != &local_f0) ||
             (ppppuVar13 = (undefined8 ****)local_e8[1], (undefined8 ****)*ppppuVar13 != local_e8))
          goto LAB_140005a8b;
          *ppppuVar13 = &local_f0;
          ppppuVar15 = (undefined8 ****)local_e8[2];
          local_e0 = local_e8[3];
          uStack_d8 = local_e8[4];
          iVar19 = *(int *)(local_e8 + 5);
          local_e8 = ppppuVar13;
          local_c8 = ppppuVar15;
          BfsDereferenceTableEntry(ppppuVar11[2] + -1);
          ExFreePoolWithTag(ppppuVar11,0);
          ppppuVar11 = ppppuVar6;
          goto LAB_140005806;
        }
      }
      else {
        if (*local_c0 == 2) {
          *(int *)(ppppuVar11 + 5) = iVar19;
          ppppuVar11[2] = ppppuVar15;
          *(undefined4 *)(ppppuVar11 + 3) = (undefined4)local_e0;
          *(undefined4 *)((longlong)ppppuVar11 + 0x1c) = local_e0._4_4_;
          *(undefined4 *)(ppppuVar11 + 4) = (undefined4)uStack_d8;
          *(undefined4 *)((longlong)ppppuVar11 + 0x24) = uStack_d8._4_4_;
          if ((undefined8 *****)*local_e8 != &local_f0) goto LAB_140005a8b;
          ppppuVar11[1] = local_e8;
          *ppppuVar11 = &local_f0;
          piVar1 = local_c0 + 5;
          *local_e8 = ppppuVar11;
          local_e8 = ppppuVar11;
          RtlInitUnicodeString(&local_e0,piVar1);
          uVar10 = BfsCreateDirectory((longlong)ppppuVar15,(ushort *)&local_e0,1,
                                      (longlong *)&local_c8);
          uVar9 = (uint)uVar10;
          ppppuVar16 = (undefined8 ****)(uVar10 & 0xffffffff);
          ppppuVar13 = ppppuVar15;
          if ((int)uVar9 < 0) goto LAB_140005712;
          ppppuVar13 = (undefined8 ****)0x100;
          ppppuVar11 = (undefined8 ****)ExAllocatePool2(0x100,0x30,0x63456642);
          if (ppppuVar11 == (undefined8 ****)0x0) goto LAB_14000570b;
          *(undefined4 *)(ppppuVar11 + 5) = 0;
          pwVar14 = L"";
          iVar19 = 0;
          ppppuVar11[2] = local_c8;
          *(undefined4 *)(ppppuVar11 + 3) = (undefined4)local_e0;
          *(undefined4 *)((longlong)ppppuVar11 + 0x1c) = local_e0._4_4_;
          *(undefined4 *)(ppppuVar11 + 4) = (undefined4)uStack_d8;
          *(undefined4 *)((longlong)ppppuVar11 + 0x24) = uStack_d8._4_4_;
          ppppuVar15 = local_c8;
LAB_1400058f7:
          RtlInitUnicodeString(local_b8,pwVar14);
        }
        else if (*local_c0 == 1) {
          pwVar14 = (wchar_t *)(local_c0 + 5);
          goto LAB_1400058f7;
        }
        uVar9 = (uint)ppppuVar16;
        if (piVar7[1] != 0) {
          local_f8[0] = local_f8[0] + 0x20;
          iVar18 = iVar18 + 1;
          if (param_2 == (longlong *)0x0) {
            uVar8 = BfsGetPathLength(&local_f0,(short *)&local_e0,local_b8);
            local_f8[0] = local_f8[0] + uVar8;
          }
          else {
            ppppuVar13 = (undefined8 ****)0x100;
            puVar12 = (undefined8 *)ExAllocatePool2(0x100,0x30,0x49736642);
            if (puVar12 == (undefined8 *)0x0) goto LAB_14000570b;
            *(int *)(puVar12 + 2) = *piVar7;
            *(int *)(puVar12 + 3) = piVar7[2];
            *(int *)((longlong)puVar12 + 0x14) = piVar7[1];
            plVar3 = (longlong *)param_2[1];
            if ((longlong *)*plVar3 != param_2) goto LAB_140005a8b;
            puVar12[1] = plVar3;
            *puVar12 = param_2;
            *plVar3 = (longlong)puVar12;
            ppppuVar13 = &local_f0;
            param_2[1] = (longlong)puVar12;
            uVar9 = BfsBuildPathFromComponents(ppppuVar13,(short *)&local_e0,local_b8,puVar12 + 4);
            ppppuVar16 = (undefined8 ****)(ulonglong)uVar9;
            if ((int)uVar9 < 0) goto LAB_140005712;
          }
        }
        uVar20 = local_f8[0];
        if (uVar9 != 0x8000001a) goto LAB_140005806;
      }
    } while (ppppuVar15 != local_a8);
    ExFreePoolWithTag(ppppuVar11,0);
    iVar19 = uVar20 + 8;
    if (iVar18 == 0) {
      iVar19 = 0;
    }
    *local_a0 = iVar19;
    if (local_98 != (int *)0x0) {
      *local_98 = iVar18;
    }
    ppppuVar16 = (undefined8 ****)0x0;
  }
  ExReleasePushLockSharedEx(*(undefined8 *)(local_90 + 0x30),0);
  KeLeaveCriticalRegion();
  puVar17 = auStack_128;
  if (((int)ppppuVar16 < 0) && (puVar17 = auStack_128, param_2 != (longlong *)0x0)) {
    while( true ) {
      plVar3 = (longlong *)*param_2;
      puVar17 = auStack_128;
      if (plVar3 == param_2) break;
      if ((longlong *)plVar3[1] != param_2) goto LAB_140005a8b;
      lVar4 = *plVar3;
      if (*(longlong **)(lVar4 + 8) != plVar3) goto LAB_140005a8b;
      *param_2 = lVar4;
      *(longlong **)(lVar4 + 8) = param_2;
      RtlFreeUnicodeString(plVar3 + 4);
      ExFreePoolWithTag(plVar3,0);
    }
  }
LAB_140005a92:
  uVar10 = (ulonglong)ppppuVar16 & 0xffffffff;
LAB_140005a94:
  *(undefined8 *)(puVar17 + -8) = 0x140005aa0;
  return uVar10;
LAB_140005a8b:
  pcVar5 = (code *)swi(0x29);
  (*pcVar5)(3);
  puVar17 = auStack_120;
  goto LAB_140005a92;
}



===== BfsFileInPublisherDirectory @ 140005abc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int BfsFileInPublisherDirectory
              (ushort *param_1,longlong param_2,ushort *param_3,undefined8 *param_4)

{
  char cVar1;
  int iVar2;
  ulonglong uVar3;
  longlong lVar4;
  ushort *puVar5;
  ushort *puVar6;
  undefined1 auStack_108 [40];
  undefined1 *local_e0;
  int local_d8 [2];
  undefined8 local_d0;
  undefined8 uStack_c8;
  ushort local_c0 [16];
  undefined8 local_a0;
  wchar_t *local_98;
  ushort local_90 [8];
  undefined1 local_80 [32];
  int *local_60;
  undefined8 local_58;
  ulonglong local_50;
  
  local_50 = __security_cookie ^ (ulonglong)auStack_108;
  local_a0 = 0x180016;
  *(undefined1 *)param_3 = 0;
  iVar2 = 0;
  local_98 = L"ProgramData";
  local_90[0] = 0;
  local_90[1] = 0;
  local_90[2] = 0;
  local_90[3] = 0;
  local_90[4] = 0;
  local_90[5] = 0;
  local_90[6] = 0;
  local_90[7] = 0;
  local_c0[0] = 0;
  local_c0[1] = 0;
  local_c0[2] = 0;
  local_c0[3] = 0;
  local_c0[4] = 0;
  local_c0[5] = 0;
  local_c0[6] = 0;
  local_c0[7] = 0;
  if (*(short *)(param_2 + 0x28) == 0) {
    cVar1 = RtlEqualUnicodeString(param_2 + 0x18,&gBfsBootDevice,1);
    if (cVar1 == '\0') goto LAB_140005c51;
    puVar5 = BfsGetFileName(local_c0 + 8,param_2);
    local_d0 = *(undefined8 *)puVar5;
    uStack_c8 = *(undefined8 *)(puVar5 + 4);
    puVar5 = BfsGetPathComponent(local_c0 + 8,&local_d0,(undefined8 *)local_90);
    local_d0 = *(undefined8 *)puVar5;
    uStack_c8 = *(undefined8 *)(puVar5 + 4);
    cVar1 = RtlEqualUnicodeString(local_90,&local_a0,1);
    if (cVar1 == '\0') goto LAB_140005c51;
    puVar5 = local_90;
    BfsGetPathComponent(local_c0 + 8,&local_d0,(undefined8 *)puVar5);
    uVar3 = BfsGetPublisherIdFromToken(param_1,(short *)local_c0);
    iVar2 = (int)uVar3;
    if (-1 < iVar2) {
      lVar4 = BfsUnicodeStringEndsWith(local_90,local_c0);
      if ((char)lVar4 == '\0') goto LAB_140005c51;
      puVar6 = local_c0 + 8;
      goto LAB_140005c2d;
    }
  }
  else {
    puVar5 = param_3;
    uVar3 = BfsGetPublisherIdFromToken(param_1,(short *)local_c0);
    iVar2 = (int)uVar3;
    if (-1 < iVar2) {
      lVar4 = BfsUnicodeStringEndsWith((ushort *)(param_2 + 0x28),local_c0);
      if ((char)lVar4 == '\0') goto LAB_140005c51;
      puVar6 = (ushort *)&local_d0;
LAB_140005c2d:
      puVar6 = BfsGetFileName(puVar6,param_2);
      local_d0 = *(undefined8 *)puVar6;
      uStack_c8 = *(undefined8 *)(puVar6 + 4);
      BfsGetPathComponentEx(local_c0 + 8,&local_d0,puVar5,param_4);
      *(undefined1 *)param_3 = 1;
      goto LAB_140005c51;
    }
  }
  if (3 < DAT_140019000) {
    local_60 = local_d8;
    local_58 = 4;
    local_e0 = local_80;
    local_d8[0] = iVar2;
    _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_140016d11);
  }
LAB_140005c51:
  RtlFreeUnicodeString(local_c0);
  return iVar2;
}



===== BfsFileOpenAsUserCallback @ 140005c90 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint BfsFileOpenAsUserCallback
               (longlong *param_1,longlong *param_2,longlong param_3,undefined8 *param_4)

{
  longlong lVar1;
  uint uVar2;
  void *pvVar3;
  undefined1 auStack_1a8 [32];
  uint local_188;
  undefined8 *local_180;
  longlong *local_178;
  undefined8 local_170;
  uint local_168;
  uint local_160;
  uint local_158;
  uint local_150;
  undefined8 local_148;
  undefined4 local_140;
  undefined4 local_138;
  uint local_128;
  uint local_124;
  longlong *local_120;
  undefined4 local_118 [2];
  longlong local_110 [6];
  undefined8 local_e0;
  undefined8 uStack_d8;
  longlong local_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  ulonglong local_80;
  undefined8 local_78 [4];
  uint *local_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_1a8;
  local_120 = (longlong *)0x0;
  local_80 = 0;
  pvVar3 = (void *)*param_4;
  local_a0 = 0;
  uStack_98 = 0;
  local_110[0] = 0;
  local_90 = 0;
  uStack_88 = 0;
  local_110[3] = 0;
  local_110[1] = 0;
  local_110[2] = 0;
  local_118[0] = 0;
  local_110[4] = 0;
  local_110[5] = 0;
  local_e0 = 0;
  uStack_d8 = 0;
  local_d0 = 0;
  uStack_c8 = 0;
  local_c0 = 0;
  uStack_b8 = 0;
  uVar2 = BfsImpersonateUser(pvVar3,local_110 + 1);
  if ((int)uVar2 < 0) {
    if (3 < DAT_140019000) {
      local_58 = &local_128;
      local_50 = 4;
      local_180 = local_78;
      local_128 = uVar2;
      _tlgWriteTransfer_EtwWriteTransfer(pvVar3,&DAT_140016d11);
    }
    goto LAB_140005f1c;
  }
  lVar1 = *(longlong *)(param_3 + 0x10);
  local_d0 = param_4[1] + 8;
  local_e0 = CONCAT44(local_e0._4_4_,0x30);
  uStack_d8 = 0;
  uStack_c8 = CONCAT44(uStack_c8._4_4_,0x600);
  local_c0 = 0;
  uStack_b8 = 0;
  local_158 = *(uint *)(lVar1 + 0x20) >> 0x18;
  local_150 = *(uint *)(lVar1 + 0x20) & 0x20041 | 0x20;
  local_188 = *(uint *)(*(longlong *)(lVar1 + 0x18) + 0x10) & 0xfff3ffff | 0x100000;
  if (local_158 == 0) {
LAB_140005db3:
    local_158 = 3;
  }
  else if (local_158 == 4) {
    local_158 = 1;
  }
  else if (local_158 == 5) goto LAB_140005db3;
  local_138 = 0;
  local_140 = 0;
  local_148 = 0;
  local_160 = (uint)*(ushort *)(lVar1 + 0x2a);
  local_178 = local_110 + 4;
  local_168 = (uint)*(ushort *)(lVar1 + 0x28);
  local_170 = 0;
  local_180 = &local_e0;
  uVar2 = FltCreateFileEx(param_1,param_2,&local_120,local_110);
  if ((int)uVar2 < 0) {
LAB_140005e1c:
    if (3 < DAT_140019000) {
      local_58 = &local_128;
      local_128 = uVar2;
LAB_140005ef6:
      local_180 = local_78;
      local_50 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_140016d11);
    }
  }
  else {
    local_180 = (undefined8 *)local_118;
    local_188 = 4;
    uVar2 = FltQueryInformationFile(param_2,local_110[0],&local_a0,0x28);
    param_1 = param_2;
    if ((int)uVar2 < 0) goto LAB_140005e1c;
    *(uint *)(param_4 + 2) = ((local_80 & 0x10) != 0) + 1;
    if (local_110[5] == 2) {
      local_128 = 1;
      local_188 = 0x40;
      local_b0 = 0;
      uStack_a8 = 0;
      param_1 = local_120;
      uVar2 = ZwSetInformationFile(local_120,&local_b0,&local_128,4);
      if (-1 < (int)uVar2) goto LAB_140005ebd;
    }
    else {
LAB_140005ebd:
      param_1 = local_120;
      uVar2 = FltClose();
      if (-1 < (int)uVar2) {
        param_1 = local_110 + 1;
        local_120 = (longlong *)0x0;
        uVar2 = BfsRevertTokenImpersonation(param_1);
        if (-1 < (int)uVar2) goto LAB_140005f1c;
      }
    }
    if (3 < DAT_140019000) {
      local_58 = &local_124;
      local_124 = uVar2;
      goto LAB_140005ef6;
    }
  }
  BfsRevertTokenImpersonation(local_110 + 1);
LAB_140005f1c:
  if (local_110[0] != 0) {
    ObfDereferenceObject();
  }
  if (local_120 != (longlong *)0x0) {
    FltClose();
  }
  return uVar2;
}



===== BfsGetFileName @ 140005f70 =====

ushort * BfsGetFileName(ushort *param_1,longlong param_2)

{
  ushort uVar1;
  longlong lVar2;
  ushort uVar3;
  
  uVar3 = *(ushort *)(param_2 + 8);
  uVar1 = *(ushort *)(param_2 + 0x18);
  param_1[0] = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  if (uVar1 < uVar3) {
    lVar2 = *(longlong *)(param_2 + 0x10);
    uVar3 = (uVar3 - *(short *)(param_2 + 0x48)) - uVar1;
    *param_1 = uVar3;
    lVar2 = lVar2 + (ulonglong)(uVar1 >> 1) * 2;
    *(longlong *)(param_1 + 4) = lVar2;
    if (1 < uVar3) {
      lVar2 = lVar2 + 2;
      *(longlong *)(param_1 + 4) = lVar2;
      do {
        uVar3 = uVar3 - 2;
        *param_1 = uVar3;
        if (uVar3 < 2) break;
      } while (*(short *)(lVar2 + (ulonglong)(ushort)((uVar3 >> 1) - 1) * 2) == 0x5c);
    }
    param_1[1] = uVar3;
  }
  return param_1;
}



===== BfsGetFinalPathComponent @ 140005ff0 =====

ushort * BfsGetFinalPathComponent(ushort *param_1,undefined8 *param_2)

{
  ushort uVar1;
  short *psVar2;
  undefined8 uVar3;
  short *psVar4;
  
  uVar3 = param_2[1];
  *(undefined8 *)param_1 = *param_2;
  *(undefined8 *)(param_1 + 4) = uVar3;
  uVar1 = *param_1;
  *param_1 = 0;
  psVar4 = (short *)(*(longlong *)(param_1 + 4) + ((ulonglong)(uVar1 >> 1) - 1) * 2);
  psVar2 = (short *)param_2[1];
  *(short **)(param_1 + 4) = psVar4;
  if (psVar4 <= psVar2) {
LAB_140006065:
    param_1[1] = *param_1;
    return param_1;
  }
  do {
    if (*psVar4 != 0x5c) break;
    psVar4 = psVar4 + -1;
    *(short **)(param_1 + 4) = psVar4;
  } while (psVar2 < psVar4);
  do {
    if (psVar4 <= psVar2) goto LAB_140006065;
    if (*psVar4 == 0x5c) {
      *(short **)(param_1 + 4) = psVar4 + 1;
      goto LAB_140006065;
    }
    if (*psVar4 == 0x3a) {
      *param_1 = 0;
    }
    else {
      *param_1 = *param_1 + 2;
    }
    psVar4 = psVar4 + -1;
    *(short **)(param_1 + 4) = psVar4;
  } while( true );
}



===== BfsGetNotPresentPolicyEntry @ 140006078 =====

undefined8
BfsGetNotPresentPolicyEntry(longlong param_1,byte *param_2,byte *param_3,longlong *param_4)

{
  uint uVar1;
  undefined8 uVar2;
  longlong lVar3;
  undefined8 uVar4;
  longlong local_res8;
  
  uVar4 = 0;
  local_res8 = 0;
  uVar1 = RtlLengthSid(param_2);
  BfsUpdateHash(param_2,uVar1,&local_res8);
  uVar1 = RtlLengthSid(param_3);
  BfsUpdateHash(param_3,uVar1,&local_res8);
  uVar2 = BfsFinalHash(&local_res8);
  *param_4 = 0;
  KeEnterCriticalRegion();
  ExAcquirePushLockSharedEx(param_1,0);
  lVar3 = BfsLookupPolicyEntryHashTable(*(undefined8 *)(param_1 + 8),uVar2,param_2,param_3);
  if (lVar3 == 0) {
    uVar4 = 0xc0190021;
  }
  else {
    if (*(int *)(lVar3 + 0x38) != 2) {
      ExReleasePushLockSharedEx(param_1,0);
      KeLeaveCriticalRegion();
      return 0xc0190021;
    }
    LOCK();
    *(int *)(lVar3 + 0x90) = *(int *)(lVar3 + 0x90) + 1;
    UNLOCK();
  }
  ExReleasePushLockSharedEx(param_1,0);
  KeLeaveCriticalRegion();
  *param_4 = lVar3;
  return uVar4;
}



===== BfsGetNotPresentPolicyEntryLocked @ 1400061a0 =====

undefined8
BfsGetNotPresentPolicyEntryLocked(longlong param_1,byte *param_2,byte *param_3,longlong *param_4)

{
  undefined8 uVar1;
  uint uVar2;
  undefined8 uVar3;
  longlong lVar4;
  undefined8 uVar5;
  longlong local_res8;
  
  uVar5 = 0;
  local_res8 = 0;
  uVar2 = RtlLengthSid(param_2);
  BfsUpdateHash(param_2,uVar2,&local_res8);
  uVar2 = RtlLengthSid(param_3);
  BfsUpdateHash(param_3,uVar2,&local_res8);
  uVar3 = BfsFinalHash(&local_res8);
  uVar1 = *(undefined8 *)(param_1 + 8);
  *param_4 = 0;
  lVar4 = BfsLookupPolicyEntryHashTable(uVar1,uVar3,param_2,param_3);
  if (lVar4 == 0) {
    uVar5 = 0xc0190021;
  }
  else {
    if (*(int *)(lVar4 + 0x38) != 2) {
      return 0xc0190021;
    }
    LOCK();
    *(int *)(lVar4 + 0x90) = *(int *)(lVar4 + 0x90) + 1;
    UNLOCK();
  }
  *param_4 = lVar4;
  return uVar5;
}



===== BfsGetPathLength @ 140006260 =====

short BfsGetPathLength(undefined8 *param_1,short *param_2,short *param_3)

{
  short sVar1;
  undefined8 *puVar2;
  
  sVar1 = 0;
  for (puVar2 = (undefined8 *)*param_1; puVar2 != param_1; puVar2 = (undefined8 *)*puVar2) {
    if (*(short *)(puVar2 + 3) != 0) {
      sVar1 = sVar1 + *(short *)(puVar2 + 3) + 2;
    }
  }
  if (*param_3 != 0) {
    sVar1 = sVar1 + *param_3 + 2;
  }
  return sVar1 + 2 + *param_2;
}



===== BfsGetPolicy @ 1400062a8 =====

ulonglong BfsGetPolicy(longlong param_1,ushort *param_2,undefined8 *param_3)

{
  uint uVar1;
  longlong lVar2;
  ulonglong uVar3;
  ushort *puVar4;
  longlong lVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  longlong local_res8;
  undefined8 local_48;
  undefined8 uStack_40;
  ushort local_38 [16];
  
  local_48 = *param_3;
  uStack_40 = param_3[1];
  uVar7 = 0;
  local_res8 = 0;
  uVar8 = 0;
  local_38[0] = 0;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 0;
  local_38[5] = 0;
  local_38[6] = 0;
  local_38[7] = 0;
  uVar3 = BfsCreateDirectory(param_1 + 0x30,param_2,1,&local_res8);
  if ((int)uVar3 < 0) {
    uVar3 = 0;
  }
  else {
    while( true ) {
      lVar2 = local_res8;
      puVar4 = BfsGetPathComponent(local_38 + 8,&local_48,(undefined8 *)local_38);
      local_48 = *(undefined8 *)puVar4;
      uStack_40 = *(undefined8 *)(puVar4 + 4);
      KeEnterCriticalRegion();
      ExAcquirePushLockSharedEx(lVar2,0);
      lVar5 = BfsFindEntry(lVar2,local_38);
      ExReleasePushLockSharedEx(lVar2,0);
      KeLeaveCriticalRegion();
      if (lVar5 == 0) break;
      uVar1 = *(uint *)(lVar5 + 8);
      uVar8 = *(uint *)(lVar5 + 4);
      uVar6 = uVar1 | uVar7;
      uVar7 = uVar1 & 0xfffffffe;
      if ((uVar1 & 1) == 0) {
        uVar7 = uVar6;
      }
      if ((ushort)local_48 < 2) goto LAB_1400063c7;
      uVar3 = BfsCreateDirectory(lVar2,local_38,1,&local_res8);
      if ((int)uVar3 < 0) {
        BfsDereferenceTableEntry((undefined8 *)(lVar2 + -8));
        return uVar3 & 0xffffffff;
      }
      BfsDereferenceTableEntry((undefined8 *)(lVar2 + -8));
    }
    if (1 < (ushort)local_48) {
      uVar8 = uVar8 & -(uint)((uVar7 & 2) != 0);
    }
LAB_1400063c7:
    BfsDereferenceTableEntry((undefined8 *)(lVar2 + -8));
    uVar3 = (ulonglong)uVar8;
  }
  return uVar3;
}



===== BfsGetPolicyEntry @ 1400063f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int BfsGetPolicyEntry(longlong *param_1,undefined8 param_2,longlong *param_3,byte *param_4,
                     byte *param_5,longlong *param_6)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  longlong lVar4;
  ulonglong uVar5;
  undefined1 auStackY_d8 [32];
  longlong local_98;
  longlong local_90;
  undefined8 local_88;
  longlong *local_60;
  undefined4 local_58;
  undefined4 local_54;
  ulonglong local_50;
  
  local_50 = __security_cookie ^ (ulonglong)auStackY_d8;
  local_98 = 0;
  local_88 = param_2;
  uVar1 = RtlLengthSid(param_4);
  BfsUpdateHash(param_4,uVar1,&local_98);
  uVar1 = RtlLengthSid(param_5);
  BfsUpdateHash(param_5,uVar1,&local_98);
  uVar3 = BfsFinalHash(&local_98);
  *param_6 = 0;
  KeEnterCriticalRegion();
  ExAcquirePushLockSharedEx(param_3,0);
  lVar4 = BfsLookupPolicyEntryHashTable(param_3[1],uVar3,param_4,param_5);
  local_90 = lVar4;
  if ((lVar4 == 0) || ((*(uint *)(lVar4 + 0x38) & 0x10000000) == 0)) {
    ExReleasePushLockSharedEx(param_3,0);
    KeLeaveCriticalRegion();
    uVar5 = BfsInsertPolicyEntry
                      (param_1,local_88,(longlong)param_3,uVar3,(longlong)param_4,(longlong)param_5,
                       &local_90);
    iVar2 = (int)uVar5;
    uVar5 = Feature_1122292024__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar5 == 0) {
      param_3 = param_1;
      if (iVar2 < 0) goto LAB_140006520;
    }
    else if (iVar2 < 0) {
      return iVar2;
    }
  }
  else {
    LOCK();
    *(int *)(lVar4 + 0x90) = *(int *)(lVar4 + 0x90) + 1;
    UNLOCK();
    ExReleasePushLockSharedEx();
    KeLeaveCriticalRegion();
    if (*(int *)(lVar4 + 0x38) == 0x10000001) {
      param_3 = *(longlong **)(lVar4 + 0x28);
      KeWaitForSingleObject(param_3,0,0,0);
    }
    if (*(int *)(lVar4 + 0x38) != 0x10000000) {
      iVar2 = -0x3fffffff;
LAB_140006520:
      if (3 < DAT_140019000) {
        local_54 = 0;
        local_60 = &local_98;
        local_98 = CONCAT44(local_98._4_4_,iVar2);
        local_58 = 4;
        _tlgWriteTransfer_EtwWriteTransfer(param_3,&DAT_140016d11);
      }
      goto LAB_1400065d9;
    }
    iVar2 = 0;
  }
  LOCK();
  *(undefined8 *)(local_90 + 0x60) = _DAT_fffff78000000014;
  UNLOCK();
  *param_6 = local_90;
  if (-1 < iVar2) {
    return iVar2;
  }
LAB_1400065d9:
  if (local_90 != 0) {
    BfsDereferencePolicyEntryEx(local_90,'\0');
  }
  return iVar2;
}



===== BfsGetPolicyEntryLocked @ 140006614 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong BfsGetPolicyEntryLocked
                    (undefined8 *param_1,undefined8 param_2,longlong param_3,byte *param_4,
                    byte *param_5,int *param_6,longlong *param_7)

{
  uint uVar1;
  undefined8 uVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  char cVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  undefined1 auStackY_c8 [32];
  longlong local_88;
  longlong local_80;
  undefined8 *local_78;
  longlong *local_50;
  undefined4 local_48;
  undefined4 local_44;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_c8;
  local_88 = 0;
  local_78 = param_1;
  uVar1 = RtlLengthSid(param_4);
  BfsUpdateHash(param_4,uVar1,&local_88);
  uVar1 = RtlLengthSid(param_5);
  BfsUpdateHash(param_5,uVar1,&local_88);
  uVar2 = BfsFinalHash(&local_88);
  *param_7 = 0;
  uVar5 = *(undefined8 *)(param_3 + 8);
  uVar7 = uVar2;
  lVar3 = BfsLookupPolicyEntryHashTable(uVar5,uVar2,param_4,param_5);
  local_80 = lVar3;
  if ((lVar3 == 0) || ((*(uint *)(lVar3 + 0x38) & 0x10000000) == 0)) {
    if (*param_6 == 1) {
      return 0xc000022d;
    }
    uVar4 = BfsInsertPolicyEntryLocked
                      (local_78,uVar7,param_3,uVar2,(longlong)param_4,(longlong)param_5,param_6,
                       &local_80);
    uVar8 = uVar4 & 0xffffffff;
    if ((int)uVar4 < 0) {
      return uVar4;
    }
  }
  else {
    LOCK();
    *(int *)(lVar3 + 0x90) = *(int *)(lVar3 + 0x90) + 1;
    UNLOCK();
    if (*(int *)(lVar3 + 0x38) == 0x10000001) {
      if (*param_6 == 1) {
        ExReleasePushLockSharedEx();
      }
      else {
        ExReleasePushLockExclusiveEx(param_3);
      }
      KeLeaveCriticalRegion();
      *param_6 = 0;
      uVar5 = *(undefined8 *)(lVar3 + 0x28);
      KeWaitForSingleObject(uVar5,0,0,0);
    }
    if (*(int *)(lVar3 + 0x38) != 0x10000000) {
      if (3 < DAT_140019000) {
        local_44 = 0;
        local_50 = &local_88;
        local_88 = CONCAT44(local_88._4_4_,0xc0000001);
        local_48 = 4;
        _tlgWriteTransfer_EtwWriteTransfer(uVar5,&DAT_140016d11);
      }
      lVar3 = local_80;
      if (local_80 == 0) {
        return 0xc0000001;
      }
      if (*param_6 == 2) {
        cVar6 = '\x01';
      }
      else {
        if (*param_6 == 1) {
          ExReleasePushLockSharedEx(param_3);
          KeLeaveCriticalRegion();
          *param_6 = 0;
        }
        cVar6 = '\0';
      }
      BfsDereferencePolicyEntryEx(lVar3,cVar6);
      return 0xc0000001;
    }
    uVar8 = 0;
  }
  LOCK();
  *(undefined8 *)(local_80 + 0x60) = _DAT_fffff78000000014;
  UNLOCK();
  *param_7 = local_80;
  return uVar8;
}



===== BfsGetPublisherIdFromToken @ 140006850 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong BfsGetPublisherIdFromToken(ushort *param_1,short *param_2)

{
  uint uVar1;
  ulonglong uVar2;
  longlong lVar3;
  undefined1 *puVar4;
  undefined1 auStack_1c8 [32];
  undefined8 local_1a8;
  undefined1 *local_1a0;
  undefined8 *local_198;
  uint local_188 [2];
  undefined8 local_180;
  undefined8 local_178;
  ushort local_170 [8];
  undefined1 local_160 [32];
  uint *local_140;
  undefined8 local_138;
  undefined1 local_128 [256];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_1c8;
  local_180 = 0;
  local_170[0] = 0;
  local_170[1] = 0;
  local_170[2] = 0;
  local_170[3] = 0;
  local_170[4] = 0;
  local_170[5] = 0;
  local_170[6] = 0;
  local_170[7] = 0;
  memset(local_128,0,0x100);
  local_198 = &local_180;
  local_178 = 0x100;
  local_1a0 = (undefined1 *)0x0;
  local_1a8 = 0;
  param_2[0] = 0;
  param_2[1] = 0;
  param_2[4] = 0;
  param_2[5] = 0;
  param_2[6] = 0;
  param_2[7] = 0;
  uVar1 = RtlQueryPackageIdentityEx(param_1,local_128,&local_178,0);
  uVar2 = (ulonglong)uVar1;
  if ((int)uVar1 < 0) {
LAB_140006958:
    if (DAT_140019000 < 4) goto LAB_14000698c;
    local_188[0] = uVar1;
  }
  else {
    puVar4 = local_128;
    RtlInitUnicodeString(local_170);
    param_1 = local_170;
    uVar2 = KappxParsePackageFullNameFromToken(param_1,puVar4,param_2);
    uVar1 = (uint)uVar2;
    uVar2 = uVar2 & 0xffffffff;
    if ((int)uVar1 < 0) goto LAB_140006958;
    uVar2 = (ulonglong)(ushort)param_2[1];
    param_1 = (ushort *)0x100;
    lVar3 = ExAllocatePool2(0x100,uVar2,0x4e736642);
    *(longlong *)(param_2 + 4) = lVar3;
    if (lVar3 != 0) {
      param_1 = local_170;
      uVar2 = KappxParsePackageFullNameFromToken(param_1,uVar2,param_2);
      uVar1 = (uint)uVar2;
      uVar2 = uVar2 & 0xffffffff;
      if (-1 < (int)uVar1) {
        return uVar2;
      }
      goto LAB_140006958;
    }
    uVar2 = 0xc0000017;
    if (DAT_140019000 < 4) goto LAB_14000698c;
    local_188[0] = 0xc0000017;
  }
  local_140 = local_188;
  local_138 = 4;
  local_1a0 = local_160;
  _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_140016d11);
LAB_14000698c:
  RtlFreeUnicodeString(param_2);
  return uVar2;
}



===== BfsGetShareName @ 1400069cc =====

ushort * BfsGetShareName(ushort *param_1,longlong param_2)

{
  longlong lVar1;
  ushort uVar2;
  
  lVar1 = *(longlong *)(param_2 + 0x30);
  param_1[0] = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  if (lVar1 != 0) {
    *(longlong *)(param_1 + 4) = lVar1;
    uVar2 = *(ushort *)(param_2 + 0x28);
    *param_1 = uVar2;
    if (1 < uVar2) {
      *(longlong *)(param_1 + 4) = lVar1 + 2;
      do {
        uVar2 = uVar2 - 2;
        *param_1 = uVar2;
        if (uVar2 < 2) break;
      } while (*(short *)(lVar1 + 2 + (ulonglong)(ushort)((uVar2 >> 1) - 1) * 2) == 0x5c);
    }
    param_1[1] = uVar2;
  }
  return param_1;
}



===== BfsIdleCheckTimerCallback @ 140006a30 =====

void BfsIdleCheckTimerCallback(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  uVar1 = IoAllocateWorkItem(gBfsDeviceObject);
  IoQueueWorkItemEx(uVar1,BfsIdleCheckWorkitemRoutine,1,param_2);
  return;
}



===== BfsIdleCheckWorkitemRoutine @ 140006a80 =====

void BfsIdleCheckWorkitemRoutine(undefined8 param_1,longlong param_2,undefined8 param_3)

{
  char cVar1;
  ulonglong uVar2;
  
  KeEnterCriticalRegion();
  cVar1 = ExAcquireRundownProtection(&gBfsRundownProtection);
  uVar2 = Feature_1199833401__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar2 == 0) {
    if (cVar1 != '\0') goto LAB_140006ad5;
  }
  else {
    KeLeaveCriticalRegion();
    if (cVar1 == '\0') goto LAB_140006b11;
LAB_140006ad5:
    BfsCheckAndReleaseIdlePolicy(param_2);
    uVar2 = Feature_1199833401__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar2 != 0) {
      KeEnterCriticalRegion();
    }
    ExReleaseRundownProtection(&gBfsRundownProtection);
  }
  KeLeaveCriticalRegion();
LAB_140006b11:
  IoFreeWorkItem(param_3);
  return;
}



===== BfsInitializePolicyTable @ 140006b38 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 BfsInitializePolicyTable(longlong param_1)

{
  char cVar1;
  undefined8 uVar2;
  longlong local_res8 [4];
  
  local_res8[0] = param_1;
  ExInitializePushLock(&gBfsPolicyTable);
  local_res8[0] = ExAllocatePool2(0x100,0x28,0x54736642);
  if (local_res8[0] == 0) {
    uVar2 = 0xc0000017;
  }
  else {
    cVar1 = RtlCreateHashTable(local_res8,0,0);
    if (cVar1 == '\0') {
      uVar2 = 0xc0000001;
    }
    else {
      _DAT_140019278 = &DAT_140019270;
      _DAT_140019270 = &DAT_140019270;
      _DAT_140019280 = ExAllocateTimer(BfsIdleCheckTimerCallback,&gBfsPolicyTable,8);
      if (_DAT_140019280 != 0) {
        DAT_140019268 = local_res8[0];
        return 0;
      }
      RtlDeleteHashTable(local_res8[0]);
      uVar2 = 0xc0000017;
    }
    ExFreePoolWithTag(local_res8[0],0);
  }
  return uVar2;
}



===== BfsInsertNotPresentPolicyEntry @ 140006c30 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint BfsInsertNotPresentPolicyEntry
               (longlong param_1,undefined8 param_2,longlong param_3,longlong param_4)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  ulonglong uVar6;
  longlong lVar7;
  longlong lVar8;
  undefined1 auStack_b8 [40];
  undefined1 *local_90;
  uint local_88 [2];
  undefined1 local_80 [32];
  uint *local_60;
  undefined8 local_58;
  ulonglong local_50;
  
  local_50 = __security_cookie ^ (ulonglong)auStack_b8;
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(param_1,0);
  lVar2 = BfsLookupPolicyEntryHashTable(*(undefined8 *)(param_1 + 8),param_2,param_3,param_4);
  if (lVar2 != 0) {
    uVar1 = 0x40000000;
    if (*(int *)(lVar2 + 0x38) != 0x10000000) {
      uVar1 = 0;
    }
    ExReleasePushLockExclusiveEx(param_1,0);
    KeLeaveCriticalRegion();
    return uVar1;
  }
  uVar6 = 0x100;
  lVar3 = ExAllocatePool2(0x100,(ulonglong)*(byte *)(param_3 + 1) * 4 + 8,0x53736642);
  lVar2 = 0;
  lVar7 = lVar3;
  if (lVar3 == 0) {
    uVar1 = 0xc0000017;
    lVar8 = 0;
  }
  else {
    uVar6 = 0x100;
    lVar4 = ExAllocatePool2(0x100,(ulonglong)*(byte *)(param_4 + 1) * 4 + 8,0x53736642);
    lVar8 = lVar4;
    if (lVar4 == 0) goto LAB_140006d47;
    uVar6 = (ulonglong)((uint)*(byte *)(param_3 + 1) * 4 + 8);
    uVar1 = RtlCopySid(uVar6,lVar3,param_3);
    if (-1 < (int)uVar1) {
      uVar6 = (ulonglong)((uint)*(byte *)(param_4 + 1) * 4 + 8);
      uVar1 = RtlCopySid(uVar6,lVar4,param_4);
      if (-1 < (int)uVar1) {
        uVar6 = 0x100;
        lVar2 = ExAllocatePool2(0x100,0x98,0x45736642);
        if (lVar2 != 0) {
          LOCK();
          *(int *)(lVar2 + 0x90) = *(int *)(lVar2 + 0x90) + 1;
          UNLOCK();
          uVar6 = 0x40;
          lVar5 = ExAllocatePool2(0x40,0x18,0x76736642);
          *(longlong *)(lVar2 + 0x28) = lVar5;
          if (lVar5 != 0) {
            *(longlong *)(lVar2 + 0x18) = lVar3;
            uVar6 = Feature_3148938554__private_IsEnabledDeviceUsageNoInline();
            *(longlong *)(lVar2 + 0x20) = lVar4;
            lVar7 = 0;
            if ((int)uVar6 == 0) {
              lVar7 = lVar3;
            }
            uVar6 = Feature_3148938554__private_IsEnabledDeviceUsageNoInline();
            *(undefined4 *)(lVar2 + 0x38) = 2;
            *(undefined4 *)(lVar2 + 0x68) = 0;
            *(undefined8 *)(lVar2 + 0x70) = 0;
            *(undefined8 *)(lVar2 + 0x78) = 0;
            *(undefined2 *)(lVar2 + 0x72) = 0;
            lVar8 = 0;
            if ((int)uVar6 == 0) {
              lVar8 = lVar4;
            }
            *(undefined8 *)(lVar2 + 0x78) = 0;
            *(undefined8 *)(lVar2 + 0x80) = 0;
            *(undefined8 *)(lVar2 + 0x88) = 0;
            *(undefined2 *)(lVar2 + 0x82) = 0;
            *(undefined8 *)(lVar2 + 0x88) = 0;
            KeInitializeEvent(*(undefined8 *)(lVar2 + 0x28),0,0);
            uVar6 = *(ulonglong *)(param_1 + 8);
            uVar1 = BfsInsertEntryHashTable(uVar6,param_2,lVar2);
            if (-1 < (int)uVar1) goto LAB_140006eb7;
            goto joined_r0x000140006e8d;
          }
        }
LAB_140006d47:
        uVar1 = 0xc0000017;
      }
    }
  }
joined_r0x000140006e8d:
  if (3 < DAT_140019000) {
    local_58 = 4;
    local_60 = local_88;
    local_90 = local_80;
    local_88[0] = uVar1;
    _tlgWriteTransfer_EtwWriteTransfer(uVar6,&DAT_140016d11);
  }
LAB_140006eb7:
  ExReleasePushLockExclusiveEx(param_1);
  KeLeaveCriticalRegion();
  if ((int)uVar1 < 0) {
    if (lVar2 != 0) {
      BfsDereferencePolicyEntryEx(lVar2,'\0');
    }
    if (lVar7 != 0) {
      ExFreePoolWithTag(lVar7,0);
    }
    if (lVar8 != 0) {
      ExFreePoolWithTag(lVar8,0);
    }
  }
  return uVar1;
}



===== BfsInsertNotPresentPolicyEntryLocked @ 140006f3c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint BfsInsertNotPresentPolicyEntryLocked
               (longlong param_1,undefined8 param_2,longlong param_3,longlong param_4)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  uint unaff_ESI;
  undefined1 auStack_b8 [40];
  undefined1 *local_90;
  uint local_88 [2];
  undefined1 local_80 [32];
  uint *local_60;
  undefined8 local_58;
  ulonglong local_50;
  
  local_50 = __security_cookie ^ (ulonglong)auStack_b8;
  lVar2 = BfsLookupPolicyEntryHashTable(*(undefined8 *)(param_1 + 8),param_2,param_3,param_4);
  if (lVar2 != 0) {
    return unaff_ESI;
  }
  uVar6 = 0x100;
  lVar2 = ExAllocatePool2(0x100,(ulonglong)*(byte *)(param_3 + 1) * 4 + 8,0x53736642);
  if (lVar2 == 0) {
    if (DAT_140019000 < 4) {
      return unaff_ESI;
    }
    local_88[0] = 0xc0000017;
    local_60 = local_88;
    local_58 = 4;
    local_90 = local_80;
    _tlgWriteTransfer_EtwWriteTransfer(uVar6,&DAT_140016d11);
    return unaff_ESI;
  }
  uVar7 = 0x100;
  lVar3 = ExAllocatePool2(0x100,(ulonglong)*(byte *)(param_4 + 1) * 4 + 8,0x53736642);
  if (lVar3 == 0) {
LAB_14000702a:
    uVar1 = 0xc0000017;
LAB_140007031:
    if (3 < DAT_140019000) {
      local_60 = local_88;
      local_58 = 4;
      local_90 = local_80;
      local_88[0] = uVar1;
      _tlgWriteTransfer_EtwWriteTransfer(uVar7,&DAT_140016d11);
    }
  }
  else {
    uVar7 = (ulonglong)((uint)*(byte *)(param_3 + 1) * 4 + 8);
    uVar1 = RtlCopySid(uVar7,lVar2,param_3);
    if ((int)uVar1 < 0) goto LAB_140007031;
    uVar7 = (ulonglong)((uint)*(byte *)(param_4 + 1) * 4 + 8);
    uVar1 = RtlCopySid(uVar7,lVar3,param_4);
    if ((int)uVar1 < 0) goto LAB_140007031;
    uVar7 = 0x100;
    lVar4 = ExAllocatePool2(0x100,0x98,0x45736642);
    if (lVar4 == 0) goto LAB_14000702a;
    LOCK();
    *(int *)(lVar4 + 0x90) = *(int *)(lVar4 + 0x90) + 1;
    UNLOCK();
    uVar6 = 0x40;
    lVar5 = ExAllocatePool2(0x40,0x18,0x76736642);
    *(longlong *)(lVar4 + 0x28) = lVar5;
    if (lVar5 == 0) {
      uVar1 = 0xc0000017;
    }
    else {
      *(longlong *)(lVar4 + 0x18) = lVar2;
      *(longlong *)(lVar4 + 0x20) = lVar3;
      *(undefined4 *)(lVar4 + 0x38) = 2;
      *(undefined4 *)(lVar4 + 0x68) = 0;
      *(undefined8 *)(lVar4 + 0x70) = 0;
      *(undefined8 *)(lVar4 + 0x78) = 0;
      *(undefined2 *)(lVar4 + 0x72) = 0;
      lVar2 = 0;
      *(undefined8 *)(lVar4 + 0x78) = 0;
      lVar3 = 0;
      *(undefined8 *)(lVar4 + 0x80) = 0;
      *(undefined8 *)(lVar4 + 0x88) = 0;
      *(undefined2 *)(lVar4 + 0x82) = 0;
      *(undefined8 *)(lVar4 + 0x88) = 0;
      KeInitializeEvent(lVar5,0,0);
      uVar6 = *(undefined8 *)(param_1 + 8);
      uVar1 = BfsInsertEntryHashTable(uVar6,param_2,lVar4);
      if (-1 < (int)uVar1) {
        return unaff_ESI;
      }
    }
    if (3 < DAT_140019000) {
      local_60 = local_88;
      local_58 = 4;
      local_90 = local_80;
      local_88[0] = uVar1;
      _tlgWriteTransfer_EtwWriteTransfer(uVar6,&DAT_140016d11);
    }
    BfsDereferencePolicyEntryEx(lVar4,'\x01');
    if (lVar2 == 0) goto LAB_1400071c3;
  }
  ExFreePoolWithTag(lVar2,0);
LAB_1400071c3:
  if (lVar3 != 0) {
    ExFreePoolWithTag(lVar3,0);
  }
  return unaff_ESI;
}



===== BfsInsertPolicyEntry @ 140007200 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong BfsInsertPolicyEntry
                    (longlong *param_1,undefined8 param_2,longlong param_3,undefined8 param_4,
                    longlong param_5,longlong param_6,longlong *param_7)

{
  undefined8 *puVar1;
  longlong *plVar2;
  code *pcVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  uint uVar7;
  longlong lVar8;
  ulonglong uVar9;
  longlong lVar10;
  longlong lVar11;
  longlong lVar12;
  ulonglong uVar13;
  longlong *plVar14;
  undefined1 auStackY_128 [32];
  char local_f7;
  undefined8 local_f0;
  char local_e8;
  char local_e6;
  uint local_e4;
  longlong *local_e0;
  longlong local_d8;
  longlong local_d0;
  longlong local_c8;
  longlong *local_c0;
  undefined8 local_b8;
  longlong local_b0 [9];
  uint *local_68;
  undefined8 local_60;
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStackY_128;
  local_c8 = param_5;
  local_d8 = 0;
  lVar10 = 0;
  local_b0[0] = 0;
  lVar11 = 0;
  bVar4 = false;
  local_f7 = '\0';
  bVar6 = false;
  bVar5 = false;
  local_e8 = '\0';
  local_d0 = param_6;
  local_c0 = param_7;
  local_b0[3] = 0;
  local_b0[4] = 0;
  local_e4 = 2;
  local_b0[1] = 0;
  local_b0[2] = 0;
  local_f0 = param_2;
  local_e0 = param_1;
  local_b8 = param_4;
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(param_3,0);
  lVar8 = BfsLookupPolicyEntryHashTable(*(undefined8 *)(param_3 + 8),local_b8,local_c8,param_6);
  lVar12 = local_c8;
  if (lVar8 == 0) {
    lVar10 = ExAllocatePool2(0x100,(ulonglong)*(byte *)(local_c8 + 1) * 4 + 8,0x53736642);
    if ((lVar10 == 0) ||
       (lVar11 = ExAllocatePool2(0x100,(ulonglong)*(byte *)(local_d0 + 1) * 4 + 8,0x53736642),
       lVar11 == 0)) goto LAB_14000741a;
    uVar13 = (ulonglong)((uint)*(byte *)(lVar12 + 1) * 4 + 8);
    uVar7 = RtlCopySid(uVar13,lVar10,lVar12);
    uVar9 = (ulonglong)uVar7;
    if ((int)uVar7 < 0) {
LAB_1400074b0:
      if (3 < DAT_140019000) {
        local_f0 = CONCAT44(local_f0._4_4_,uVar7);
LAB_140007432:
        local_68 = (uint *)&local_f0;
        local_60 = 4;
        _tlgWriteTransfer_EtwWriteTransfer(uVar13,&DAT_140016d11);
      }
    }
    else {
      uVar13 = (ulonglong)((uint)*(byte *)(local_d0 + 1) * 4 + 8);
      uVar7 = RtlCopySid(uVar13,lVar11,local_d0);
      uVar9 = (ulonglong)uVar7;
      if ((int)uVar7 < 0) goto LAB_1400074b0;
      lVar8 = ExAllocatePool2(0x100,0x98,0x45736642);
      if (lVar8 != 0) {
        LOCK();
        *(int *)(lVar8 + 0x90) = *(int *)(lVar8 + 0x90) + 1;
        UNLOCK();
        lVar12 = ExAllocatePool2(0x40,0x18,0x76736642);
        *(longlong *)(lVar8 + 0x28) = lVar12;
        if (lVar12 != 0) {
          *(longlong *)(lVar8 + 0x18) = lVar10;
          uVar13 = Feature_3148938554__private_IsEnabledDeviceUsageNoInline();
          *(longlong *)(lVar8 + 0x20) = lVar11;
          if ((int)uVar13 != 0) {
            lVar10 = 0;
          }
          uVar13 = Feature_3148938554__private_IsEnabledDeviceUsageNoInline();
          *(undefined4 *)(lVar8 + 0x38) = 0x10000001;
          *(undefined4 *)(lVar8 + 0x68) = 0;
          *(undefined8 *)(lVar8 + 0x70) = 0;
          *(undefined8 *)(lVar8 + 0x78) = 0;
          *(undefined2 *)(lVar8 + 0x72) = 0;
          if ((int)uVar13 != 0) {
            lVar11 = 0;
          }
          *(undefined8 *)(lVar8 + 0x78) = 0;
          *(undefined8 *)(lVar8 + 0x80) = 0;
          *(undefined8 *)(lVar8 + 0x88) = 0;
          *(undefined2 *)(lVar8 + 0x82) = 0;
          *(undefined8 *)(lVar8 + 0x88) = 0;
          KeInitializeEvent(*(undefined8 *)(lVar8 + 0x28),0,0);
          uVar13 = *(ulonglong *)(param_3 + 8);
          uVar7 = BfsInsertEntryHashTable(uVar13,local_b8,lVar8);
          uVar9 = (ulonglong)uVar7;
          if ((int)uVar7 < 0) goto LAB_1400074b0;
          LOCK();
          *(int *)(lVar8 + 0x90) = *(int *)(lVar8 + 0x90) + 1;
          UNLOCK();
          plVar14 = (longlong *)(param_3 + 0x10);
          local_f7 = '\x01';
          if ((longlong *)*plVar14 == plVar14) {
            ExSetTimer(*(undefined8 *)(param_3 + 0x20),0xffffffffee1e5d00,300000000);
          }
          puVar1 = *(undefined8 **)(param_3 + 0x18);
          plVar2 = (longlong *)(lVar8 + 0x40);
          if ((longlong *)*puVar1 != plVar14) goto LAB_1400079bd;
          *plVar2 = (longlong)plVar14;
          *(undefined8 **)(lVar8 + 0x48) = puVar1;
          *puVar1 = plVar2;
          *(longlong **)(param_3 + 0x18) = plVar2;
          LOCK();
          *(undefined8 *)(lVar8 + 0x60) = _DAT_fffff78000000014;
          UNLOCK();
          goto LAB_140007622;
        }
      }
LAB_14000741a:
      uVar13 = 0xc0000017;
      uVar9 = 0xc0000017;
      if (3 < DAT_140019000) {
        local_f0 = CONCAT44(local_f0._4_4_,0xc0000017);
        goto LAB_140007432;
      }
    }
LAB_14000777f:
    ExReleasePushLockExclusiveEx(param_3);
    KeLeaveCriticalRegion();
    bVar5 = false;
    bVar6 = false;
    bVar4 = false;
    if (-1 < (int)uVar9) goto LAB_1400079a1;
LAB_1400077b0:
    local_e6 = local_f7;
    if (lVar8 != 0) {
      bVar5 = bVar6;
      if ((local_e8 != '\0') && (local_f7 == '\0')) {
        KeEnterCriticalRegion();
        ExAcquirePushLockExclusiveEx(param_3);
        uVar13 = Feature_3083317562__private_IsEnabledDeviceUsageNoInline();
        if ((int)uVar13 == 0) {
          uVar7 = 2;
        }
        else {
          uVar7 = local_e4;
        }
        local_f7 = local_e6;
        *(uint *)(lVar8 + 0x38) = uVar7;
        KeSetEvent(*(undefined8 *)(lVar8 + 0x28),0,0);
        ExReleasePushLockExclusiveEx(param_3);
        KeLeaveCriticalRegion();
      }
      goto LAB_140007866;
    }
  }
  else {
    if ((*(uint *)(lVar8 + 0x38) & 0x10000000) == 0) {
      uVar9 = Feature_3083317562__private_IsEnabledDeviceUsageNoInline();
      uVar7 = *(uint *)(lVar8 + 0x38);
      uVar13 = (ulonglong)uVar7;
      if ((int)uVar9 == 0) {
        if (uVar7 != 2) goto LAB_1400073a8;
      }
      else {
        if (1 < uVar7 - 1) {
LAB_1400073a8:
          uVar7 = 0xc0000001;
          lVar8 = 0;
          uVar9 = 0xc0000001;
          goto LAB_1400074b0;
        }
        local_e4 = uVar7;
      }
      *(undefined4 *)(lVar8 + 0x38) = 0x10000001;
      KeResetEvent(*(undefined8 *)(lVar8 + 0x28));
      local_e8 = '\x01';
      LOCK();
      *(int *)(lVar8 + 0x90) = *(int *)(lVar8 + 0x90) + 1;
      UNLOCK();
LAB_140007622:
      ExReleasePushLockExclusiveEx(param_3,0);
      KeLeaveCriticalRegion();
      plVar14 = local_b0 + 1;
      uVar7 = RtlConvertSidToUnicodeString(plVar14,local_c8,1);
      uVar9 = (ulonglong)uVar7;
      if (-1 < (int)uVar7) {
        plVar14 = local_b0 + 3;
        bVar4 = true;
        uVar7 = RtlConvertSidToUnicodeString(plVar14,local_d0,1);
        uVar9 = (ulonglong)uVar7;
        if (-1 < (int)uVar7) {
          bVar6 = true;
          bVar5 = true;
          plVar14 = local_e0;
          uVar7 = BfsOpenPolicyDirectory(local_e0,local_f0,local_b0 + 1,'\0',local_b0);
          uVar9 = (ulonglong)uVar7;
          if (-1 < (int)uVar7) {
            plVar14 = local_e0;
            uVar9 = BfsCreateStorage((longlong)local_e0,local_f0,local_b0[0],local_b0 + 3,&local_d8)
            ;
            uVar7 = (uint)uVar9;
            uVar9 = uVar9 & 0xffffffff;
            if (-1 < (int)uVar7) {
              RtlFreeUnicodeString(local_b0 + 1);
              RtlFreeUnicodeString(local_b0 + 3);
              KeEnterCriticalRegion();
              ExAcquirePushLockExclusiveEx(param_3);
              *(longlong *)(lVar8 + 0x30) = local_d8;
              *(undefined4 *)(lVar8 + 0x38) = 0x10000000;
              KeSetEvent(*(undefined8 *)(lVar8 + 0x28),0,0);
              *local_c0 = lVar8;
              goto LAB_14000777f;
            }
          }
        }
      }
      if (3 < DAT_140019000) {
        local_f0 = CONCAT44(local_f0._4_4_,uVar7);
        local_68 = (uint *)&local_f0;
        local_60 = 4;
        _tlgWriteTransfer_EtwWriteTransfer(plVar14,&DAT_140016d11);
      }
      goto LAB_1400077b0;
    }
    LOCK();
    *(int *)(lVar8 + 0x90) = *(int *)(lVar8 + 0x90) + 1;
    UNLOCK();
    lVar12 = param_3;
    ExReleasePushLockExclusiveEx();
    KeLeaveCriticalRegion();
    if (*(int *)(lVar8 + 0x38) == 0x10000001) {
      lVar12 = *(longlong *)(lVar8 + 0x28);
      KeWaitForSingleObject(lVar12,0,0,0);
    }
    if (*(int *)(lVar8 + 0x38) == 0x10000000) {
      *param_7 = lVar8;
      return 0;
    }
    uVar9 = 0xc0000001;
    if (3 < DAT_140019000) {
      local_e4 = 0xc0000001;
      local_68 = &local_e4;
      local_60 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(lVar12,&DAT_140016d11);
    }
LAB_140007866:
    BfsDereferencePolicyEntryEx(lVar8,'\0');
  }
  if (local_f7 != '\0') {
    KeEnterCriticalRegion();
    ExAcquirePushLockExclusiveEx(param_3,0);
    lVar12 = BfsLookupPolicyEntryHashTable(*(undefined8 *)(param_3 + 8),local_b8,local_c8,local_d0);
    if (lVar12 != 0) {
      plVar14 = (longlong *)(lVar12 + 0x40);
      *(undefined4 *)(lVar12 + 0x38) = 1;
      lVar8 = *plVar14;
      if ((*(longlong **)(lVar8 + 8) != plVar14) ||
         (plVar2 = *(longlong **)(lVar12 + 0x48), (longlong *)*plVar2 != plVar14)) {
LAB_1400079bd:
        pcVar3 = (code *)swi(0x29);
        (*pcVar3)(3);
        pcVar3 = (code *)swi(3);
        uVar13 = (*pcVar3)();
        return uVar13;
      }
      *plVar2 = lVar8;
      *(longlong **)(lVar8 + 8) = plVar2;
      uVar13 = Feature_Servicing_BfsGAFeature__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar13 != 0) {
        *plVar14 = 0;
        *(undefined8 *)(lVar12 + 0x48) = 0;
      }
      KeSetEvent(*(undefined8 *)(lVar12 + 0x28),0,0);
      BfsDereferencePolicyEntryEx(lVar12,'\x01');
    }
    ExReleasePushLockExclusiveEx(param_3,0);
    KeLeaveCriticalRegion();
  }
  if (bVar4) {
    RtlFreeUnicodeString(local_b0 + 1);
  }
  if (bVar5) {
    RtlFreeUnicodeString(local_b0 + 3);
  }
  if (lVar10 != 0) {
    ExFreePoolWithTag(lVar10,0);
  }
  if (lVar11 != 0) {
    ExFreePoolWithTag(lVar11,0);
  }
LAB_1400079a1:
  if (local_b0[0] != 0) {
    FltClose();
  }
  return uVar9;
}



===== BfsInsertPolicyEntryLocked @ 1400079cc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong BfsInsertPolicyEntryLocked
                    (undefined8 *param_1,undefined8 param_2,longlong param_3,undefined8 param_4,
                    longlong param_5,longlong param_6,int *param_7,longlong *param_8)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  bool bVar4;
  bool bVar5;
  uint uVar6;
  longlong lVar7;
  ulonglong uVar8;
  longlong lVar9;
  longlong lVar10;
  longlong *plVar11;
  ulonglong uVar12;
  undefined8 uVar13;
  undefined8 *puVar14;
  int *piVar15;
  longlong lVar16;
  undefined1 auStackY_118 [32];
  char local_e8;
  char local_e7;
  uint local_e4;
  char local_e0;
  char local_df;
  char local_de;
  uint local_d8 [2];
  longlong local_d0;
  int *local_c8;
  longlong local_c0;
  longlong local_b8;
  longlong local_b0;
  longlong local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  uint *local_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_118;
  local_c8 = param_7;
  local_c0 = 0;
  lVar16 = 0;
  local_a8 = 0;
  lVar9 = 0;
  local_e8 = '\0';
  bVar4 = false;
  bVar5 = false;
  local_e7 = '\0';
  local_e0 = '\0';
  uVar13 = *(undefined8 *)(param_3 + 8);
  local_b0 = param_5;
  local_b8 = param_6;
  local_88 = 0;
  uStack_80 = 0;
  local_e4 = 2;
  local_98 = 0;
  uStack_90 = 0;
  local_d0 = param_3;
  local_a0 = param_4;
  lVar7 = BfsLookupPolicyEntryHashTable(uVar13,param_4,param_5,param_6);
  lVar1 = local_b0;
  lVar10 = local_d0;
  if (lVar7 == 0) {
    uVar12 = 0x100;
    lVar16 = ExAllocatePool2(0x100,(ulonglong)*(byte *)(local_b0 + 1) * 4 + 8,0x53736642);
    if (lVar16 == 0) {
      uVar6 = 0xc0000017;
      goto LAB_140007be8;
    }
    uVar12 = 0x100;
    lVar9 = ExAllocatePool2(0x100,(ulonglong)*(byte *)(param_6 + 1) * 4 + 8,0x53736642);
    if (lVar9 == 0) {
LAB_140007cbb:
      uVar6 = 0xc0000017;
      uVar8 = 0xc0000017;
    }
    else {
      uVar12 = (ulonglong)((uint)*(byte *)(lVar1 + 1) * 4 + 8);
      uVar6 = RtlCopySid(uVar12,lVar16,lVar1);
      uVar8 = (ulonglong)uVar6;
      if (-1 < (int)uVar6) {
        uVar12 = (ulonglong)((uint)*(byte *)(local_b8 + 1) * 4 + 8);
        uVar6 = RtlCopySid(uVar12,lVar9,local_b8);
        uVar8 = (ulonglong)uVar6;
        if (-1 < (int)uVar6) {
          uVar12 = 0x100;
          lVar7 = ExAllocatePool2(0x100,0x98,0x45736642);
          if (lVar7 == 0) goto LAB_140007cbb;
          LOCK();
          *(int *)(lVar7 + 0x90) = *(int *)(lVar7 + 0x90) + 1;
          UNLOCK();
          uVar13 = 0x40;
          lVar10 = ExAllocatePool2(0x40,0x18,0x76736642);
          *(longlong *)(lVar7 + 0x28) = lVar10;
          if (lVar10 == 0) {
            uVar8 = 0xc0000017;
            if (3 < DAT_140019000) {
              local_e4 = 0xc0000017;
              local_58 = &local_e4;
              local_50 = 4;
              _tlgWriteTransfer_EtwWriteTransfer(uVar13,&DAT_140016d11);
            }
            goto LAB_140007fc4;
          }
          *(longlong *)(lVar7 + 0x18) = lVar16;
          *(longlong *)(lVar7 + 0x20) = lVar9;
          *(undefined4 *)(lVar7 + 0x38) = 0x10000001;
          *(undefined4 *)(lVar7 + 0x68) = 0;
          *(undefined8 *)(lVar7 + 0x70) = 0;
          *(undefined8 *)(lVar7 + 0x78) = 0;
          *(undefined2 *)(lVar7 + 0x72) = 0;
          lVar16 = 0;
          *(undefined8 *)(lVar7 + 0x78) = 0;
          lVar9 = 0;
          *(undefined8 *)(lVar7 + 0x80) = 0;
          *(undefined8 *)(lVar7 + 0x88) = 0;
          *(undefined2 *)(lVar7 + 0x82) = 0;
          *(undefined8 *)(lVar7 + 0x88) = 0;
          KeInitializeEvent(lVar10,0,0);
          lVar10 = local_d0;
          uVar13 = *(undefined8 *)(local_d0 + 8);
          uVar6 = BfsInsertEntryHashTable(uVar13,local_a0,lVar7);
          lVar1 = local_d0;
          uVar8 = (ulonglong)uVar6;
          if (-1 < (int)uVar6) {
            LOCK();
            *(int *)(lVar7 + 0x90) = *(int *)(lVar7 + 0x90) + 1;
            UNLOCK();
            bVar4 = true;
            bVar5 = true;
            plVar11 = (longlong *)(local_d0 + 0x10);
            if ((longlong *)*plVar11 == plVar11) {
              ExSetTimer(*(undefined8 *)(local_d0 + 0x20),0xffffffffee1e5d00,300000000);
            }
            puVar14 = *(undefined8 **)(lVar1 + 0x18);
            plVar2 = (longlong *)(lVar7 + 0x40);
            if ((longlong *)*puVar14 != plVar11) goto LAB_140008129;
            *plVar2 = (longlong)plVar11;
            *(undefined8 **)(lVar7 + 0x48) = puVar14;
            *puVar14 = plVar2;
            *(longlong **)(lVar1 + 0x18) = plVar2;
            LOCK();
            *(undefined8 *)(lVar7 + 0x60) = _DAT_fffff78000000014;
            UNLOCK();
            goto LAB_140007e82;
          }
          if (3 < DAT_140019000) {
            local_58 = &local_e4;
            local_50 = 4;
            local_e4 = uVar6;
            _tlgWriteTransfer_EtwWriteTransfer(uVar13,&DAT_140016d11);
          }
          goto LAB_140007fc9;
        }
      }
    }
    if (3 < DAT_140019000) {
      local_58 = &local_e4;
      local_50 = 4;
      local_e4 = uVar6;
      _tlgWriteTransfer_EtwWriteTransfer(uVar12,&DAT_140016d11);
    }
LAB_14000809b:
    ExFreePoolWithTag(lVar16,0);
  }
  else {
    if ((*(uint *)(lVar7 + 0x38) & 0x10000000) == 0) {
      uVar8 = Feature_3083317562__private_IsEnabledDeviceUsageNoInline();
      uVar6 = *(uint *)(lVar7 + 0x38);
      uVar12 = (ulonglong)uVar6;
      if ((int)uVar8 == 0) {
        if (uVar6 == 2) goto LAB_140007b87;
      }
      else if (uVar6 - 1 < 2) {
        local_e4 = uVar6;
LAB_140007b87:
        *(undefined4 *)(lVar7 + 0x38) = 0x10000001;
        KeResetEvent(*(undefined8 *)(lVar7 + 0x28));
        local_e0 = '\x01';
        LOCK();
        *(int *)(lVar7 + 0x90) = *(int *)(lVar7 + 0x90) + 1;
        UNLOCK();
LAB_140007e82:
        lVar9 = 0;
        puVar14 = &local_98;
        uVar6 = RtlConvertSidToUnicodeString(puVar14,local_b0,1);
        uVar8 = (ulonglong)uVar6;
        if (-1 < (int)uVar6) {
          puVar14 = &local_88;
          local_e8 = '\x01';
          uVar6 = RtlConvertSidToUnicodeString(puVar14,local_b8,1);
          uVar8 = (ulonglong)uVar6;
          if (-1 < (int)uVar6) {
            local_e7 = '\x01';
            puVar14 = param_1;
            uVar6 = BfsOpenPolicyDirectory(param_1,0,&local_98,'\0',&local_a8);
            uVar8 = (ulonglong)uVar6;
            if (-1 < (int)uVar6) {
              uVar8 = BfsCreateStorage((longlong)param_1,0,local_a8,&local_88,&local_c0);
              uVar6 = (uint)uVar8;
              uVar8 = uVar8 & 0xffffffff;
              puVar14 = param_1;
              if (-1 < (int)uVar6) {
                RtlFreeUnicodeString(&local_98);
                RtlFreeUnicodeString(&local_88);
                *(longlong *)(lVar7 + 0x30) = local_c0;
                *(undefined4 *)(lVar7 + 0x38) = 0x10000000;
                KeSetEvent(*(undefined8 *)(lVar7 + 0x28),0,0);
                *param_8 = lVar7;
                goto LAB_14000810d;
              }
            }
          }
        }
        if (3 < DAT_140019000) {
          local_58 = local_d8;
          local_50 = 4;
          local_d8[0] = uVar6;
          _tlgWriteTransfer_EtwWriteTransfer(puVar14,&DAT_140016d11);
        }
        lVar16 = 0;
        local_de = local_e8;
        local_df = local_e7;
        if (lVar7 != 0) {
          bVar5 = bVar4;
          if ((local_e0 != '\0') && (!bVar4)) {
            uVar12 = Feature_3083317562__private_IsEnabledDeviceUsageNoInline();
            local_e7 = local_df;
            local_e8 = local_de;
            uVar6 = 2;
            if ((int)uVar12 != 0) {
              uVar6 = local_e4;
            }
            *(uint *)(lVar7 + 0x38) = uVar6;
            KeSetEvent(*(undefined8 *)(lVar7 + 0x28),0,0);
          }
LAB_140007fc4:
          lVar10 = local_d0;
LAB_140007fc9:
          piVar15 = local_c8;
          goto LAB_140007fce;
        }
        lVar10 = local_d0;
        goto LAB_140007fea;
      }
      uVar6 = 0xc0000001;
LAB_140007be8:
      uVar8 = (ulonglong)uVar6;
      if (3 < DAT_140019000) {
        local_58 = &local_e4;
        local_50 = 4;
        local_e4 = uVar6;
        _tlgWriteTransfer_EtwWriteTransfer(uVar12,&DAT_140016d11);
      }
      goto LAB_14000810d;
    }
    LOCK();
    *(int *)(lVar7 + 0x90) = *(int *)(lVar7 + 0x90) + 1;
    UNLOCK();
    if (*(int *)(lVar7 + 0x38) == 0x10000001) {
      ExReleasePushLockExclusiveEx(local_d0);
      KeLeaveCriticalRegion();
      piVar15 = local_c8;
      *local_c8 = 0;
      uVar13 = *(undefined8 *)(lVar7 + 0x28);
      KeWaitForSingleObject(uVar13,0,0,0);
    }
    else {
      piVar15 = local_c8;
    }
    if (*(int *)(lVar7 + 0x38) == 0x10000000) {
      *param_8 = lVar7;
      return 0;
    }
    uVar8 = 0xc0000001;
    if (3 < DAT_140019000) {
      local_e4 = 0xc0000001;
      local_58 = &local_e4;
      local_50 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(uVar13,&DAT_140016d11);
    }
LAB_140007fce:
    BfsDereferencePolicyEntryEx(lVar7,*piVar15 == 2);
LAB_140007fea:
    if ((bVar5) &&
       (lVar10 = BfsLookupPolicyEntryHashTable
                           (*(undefined8 *)(lVar10 + 8),local_a0,local_b0,local_b8), lVar10 != 0)) {
      *(undefined4 *)(lVar10 + 0x38) = 1;
      plVar11 = (longlong *)(lVar10 + 0x40);
      lVar1 = *plVar11;
      if ((*(longlong **)(lVar1 + 8) != plVar11) ||
         (plVar2 = *(longlong **)(lVar10 + 0x48), (longlong *)*plVar2 != plVar11)) {
LAB_140008129:
        pcVar3 = (code *)swi(0x29);
        (*pcVar3)(3);
        pcVar3 = (code *)swi(3);
        uVar12 = (*pcVar3)();
        return uVar12;
      }
      *plVar2 = lVar1;
      *(longlong **)(lVar1 + 8) = plVar2;
      *plVar11 = 0;
      *(undefined8 *)(lVar10 + 0x48) = 0;
      KeSetEvent(*(undefined8 *)(lVar10 + 0x28),0,0);
      BfsDereferencePolicyEntryEx(lVar10,'\x01');
    }
    if (local_e8 != '\0') {
      RtlFreeUnicodeString(&local_98);
    }
    if (local_e7 != '\0') {
      RtlFreeUnicodeString(&local_88);
    }
    if (lVar16 != 0) goto LAB_14000809b;
  }
  if (lVar9 != 0) {
    ExFreePoolWithTag(lVar9,0);
  }
LAB_14000810d:
  if (local_a8 != 0) {
    FltClose();
  }
  return uVar8;
}



===== BfsLookupPolicyEntryHashTable @ 140008138 =====

longlong BfsLookupPolicyEntryHashTable
                   (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  char cVar1;
  longlong lVar2;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  lVar2 = RtlLookupEntryHashTable(0,param_2,&local_28);
  while ((lVar2 != 0 &&
         ((cVar1 = RtlEqualSid(param_3,*(undefined8 *)(lVar2 + 0x18)), cVar1 == '\0' ||
          (cVar1 = RtlEqualSid(param_4,*(undefined8 *)(lVar2 + 0x20)), cVar1 == '\0'))))) {
    lVar2 = RtlGetNextEntryHashTable(param_1,&local_28);
  }
  return lVar2;
}



===== BfsOpenPolicyDirectory @ 1400081e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int BfsOpenPolicyDirectory
              (undefined8 param_1,undefined8 param_2,undefined8 param_3,char param_4,
              undefined8 *param_5)

{
  int iVar1;
  undefined1 auStack_128 [32];
  undefined4 local_108;
  undefined8 *local_100;
  undefined8 *local_f8;
  undefined8 local_f0;
  undefined4 local_e8;
  undefined4 local_e0;
  int local_d8;
  undefined4 local_d0;
  undefined8 local_c8;
  undefined4 local_c0;
  undefined4 local_b8;
  undefined8 local_b0;
  int local_a8 [2];
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined4 local_80;
  undefined4 local_7c;
  undefined *local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined1 local_58 [32];
  int *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_128;
  local_a0 = 0;
  local_7c = 0;
  *param_5 = 0;
  local_98 = 0x30;
  local_68 = 0;
  uStack_60 = 0;
  local_90 = BfsGetRootDirectory();
  local_70 = 0;
  local_78 = &gBfsPolicyStorageDirectoryDescriptor;
  local_80 = 0x240;
  local_b0 = 0;
  local_b8 = 0x100;
  local_d8 = (-(uint)(param_4 != '\0') & 0xfffffffe) + 3;
  local_c0 = 0;
  local_c8 = 0;
  local_d0 = 0x21;
  local_f8 = &local_68;
  local_e0 = 3;
  local_e8 = 0x10;
  local_f0 = 0;
  local_100 = &local_98;
  local_108 = 0x100047;
  local_88 = param_3;
  iVar1 = FltCreateFileEx2();
  if (iVar1 < 0) {
    if (3 < DAT_140019000) {
      local_2c = 0;
      local_38 = local_a8;
      local_100 = (undefined8 *)local_58;
      local_30 = 4;
      local_a8[0] = iVar1;
      _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_140016d11);
    }
  }
  else {
    *param_5 = local_a0;
  }
  return iVar1;
}



===== BfsPolicyEntryExists @ 14000831c =====

byte BfsPolicyEntryExists
               (undefined8 param_1,undefined8 param_2,longlong param_3,byte *param_4,byte *param_5)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  byte extraout_var;
  longlong lVar4;
  byte bVar5;
  byte bVar6;
  longlong local_res18;
  byte *local_res20;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  
  bVar6 = 0;
  local_78 = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_res18 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_res20 = param_4;
  uVar2 = RtlLengthSid(param_4);
  BfsUpdateHash(param_4,uVar2,&local_res18);
  uVar2 = RtlLengthSid(param_5);
  BfsUpdateHash(param_5,uVar2,&local_res18);
  local_res18 = BfsFinalHash(&local_res18);
  bVar5 = 0;
  KeEnterCriticalRegion();
  ExAcquirePushLockSharedEx(param_3,0);
  lVar4 = BfsLookupPolicyEntryHashTable(*(undefined8 *)(param_3 + 8),local_res18,param_4,param_5);
  if (lVar4 != 0) {
    uVar1 = *(undefined4 *)(lVar4 + 0x38);
    ExReleasePushLockSharedEx();
    KeLeaveCriticalRegion();
    return (byte)((uint)uVar1 >> 0x1c) & 1;
  }
  ExReleasePushLockSharedEx(param_3,0);
  KeLeaveCriticalRegion();
  iVar3 = RtlConvertSidToUnicodeString(&local_60,param_4,1);
  if (iVar3 < 0) {
    return 0;
  }
  iVar3 = RtlConvertSidToUnicodeString(&local_70,param_5,1);
  if (iVar3 < 0) goto LAB_14000856f;
  iVar3 = BfsOpenPolicyDirectory(param_1,param_2,&local_60,'\x01',&local_78);
  if (iVar3 < 0) {
LAB_140008538:
    uVar2 = BfsInsertNotPresentPolicyEntry(param_3,local_res18,(longlong)param_4,(longlong)param_5);
    bVar6 = bVar5;
    if (uVar2 == 0x40000000) {
      bVar6 = 1;
    }
  }
  else {
    uVar2 = (uint)(ushort)local_70;
    local_50 = 0;
    uStack_48 = 0;
    lVar4 = ExAllocatePool2(0x100,uVar2 + 0x10,0x4e736642);
    if (lVar4 != 0) {
      ZwQueryDirectoryFile(local_78,0,0,0,&local_50,lVar4,uVar2 + 0x10,0xc,1,&local_70,1);
      ExFreePoolWithTag(lVar4,0);
      bVar5 = extraout_var >> 7 ^ 1;
    }
    FltClose(local_78);
    bVar6 = bVar5;
    if ((bVar5 == 0) && (lVar4 != 0)) {
      param_4 = local_res20;
      goto LAB_140008538;
    }
  }
  RtlFreeUnicodeString(&local_70);
LAB_14000856f:
  RtlFreeUnicodeString(&local_60);
  return bVar6;
}



===== BfsPolicyEntryExistsLocked @ 14000859c =====

ulonglong BfsPolicyEntryExistsLocked
                    (undefined8 param_1,undefined8 param_2,longlong param_3,byte *param_4,
                    byte *param_5,int param_6)

{
  uint uVar1;
  int iVar2;
  byte extraout_var;
  int extraout_EAX;
  longlong lVar3;
  ulonglong uVar4;
  byte bVar5;
  longlong local_res10;
  undefined8 local_res18;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  
  local_res18 = 0;
  local_res10 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  uVar1 = RtlLengthSid(param_4);
  BfsUpdateHash(param_4,uVar1,&local_res10);
  uVar1 = RtlLengthSid(param_5);
  BfsUpdateHash(param_5,uVar1,&local_res10);
  local_res10 = BfsFinalHash(&local_res10);
  bVar5 = 0;
  lVar3 = BfsLookupPolicyEntryHashTable(*(undefined8 *)(param_3 + 8),local_res10,param_4,param_5);
  if (lVar3 != 0) {
    if ((*(uint *)(lVar3 + 0x38) & 0x10000000) == 0) {
      return 0xc0000225;
    }
    return 0;
  }
  uVar4 = RtlConvertSidToUnicodeString(&local_48,param_4,1);
  if ((int)uVar4 < 0) {
    return uVar4;
  }
  uVar1 = RtlConvertSidToUnicodeString(&local_58,param_5,1);
  if ((int)uVar1 < 0) {
    RtlFreeUnicodeString(&local_48);
    return (ulonglong)uVar1;
  }
  iVar2 = BfsOpenPolicyDirectory(param_1,0,&local_48,'\x01',&local_res18);
  if (-1 < iVar2) {
    uVar1 = (uint)(ushort)local_58;
    local_38 = 0;
    uStack_30 = 0;
    lVar3 = ExAllocatePool2(0x100,uVar1 + 0x10,0x4e736642);
    if (lVar3 != 0) {
      ZwQueryDirectoryFile(local_res18,0,0,0,&local_38,lVar3,uVar1 + 0x10,0xc,1,&local_58,1);
      ExFreePoolWithTag(lVar3,0);
      bVar5 = extraout_var >> 7 ^ 1;
    }
    FltClose(local_res18);
    if ((bVar5 != 0) || (lVar3 == 0)) goto LAB_1400087bc;
  }
  if (param_6 == 1) {
    return 0xc000022d;
  }
  uVar1 = BfsInsertNotPresentPolicyEntryLocked
                    (param_3,local_res10,(longlong)param_4,(longlong)param_5);
  bVar5 = (byte)uVar1;
  if (extraout_EAX == 0x40000000) {
    bVar5 = 1;
  }
LAB_1400087bc:
  RtlFreeUnicodeString(&local_58);
  RtlFreeUnicodeString(&local_48);
  return (ulonglong)(~-(uint)(bVar5 != 0) & 0xc0000225);
}



===== BfsProcessDeletePolicyEntryRequest @ 14000880c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint BfsProcessDeletePolicyEntryRequest(longlong param_1)

{
  bool bVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined1 auStackY_98 [32];
  uint local_68 [2];
  longlong local_60;
  undefined8 *local_58;
  undefined8 *local_50 [5];
  uint *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  local_50[0] = (undefined8 *)0x0;
  local_60 = 0;
  local_58 = (undefined8 *)0x0;
  uVar2 = ObReferenceObjectByHandle(param_1,8,*(undefined8 *)SeTokenObjectType_exref,1);
  if ((int)uVar2 < 0) {
LAB_1400088ff:
    if (DAT_140019000 < 4) goto LAB_140008933;
    local_68[0] = uVar2;
  }
  else {
    param_1 = local_60;
    bVar1 = BfsIsApplicableToken(local_60);
    if (bVar1) {
      param_1 = local_60;
      uVar2 = SeQueryInformationToken(local_60,1,&local_58);
      if (-1 < (int)uVar2) {
        uVar3 = 0x1f;
        param_1 = local_60;
        uVar2 = SeQueryInformationToken(local_60,0x1f,local_50);
        if (-1 < (int)uVar2) {
          param_1 = gBfsFilterHandle;
          uVar2 = BfsRemovePolicyEntry
                            (gBfsFilterHandle,uVar3,0x140019260,(byte *)*local_58,
                             (byte *)*local_50[0]);
          if (-1 < (int)uVar2) goto LAB_140008933;
        }
      }
      goto LAB_1400088ff;
    }
    uVar2 = 0xc000a200;
    if (DAT_140019000 < 4) goto LAB_140008933;
    local_68[0] = 0xc000a200;
  }
  uVar2 = local_68[0];
  local_1c = 0;
  local_28 = local_68;
  local_20 = 4;
  _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_140016d11);
LAB_140008933:
  if (local_60 != 0) {
    ObfDereferenceObject();
  }
  if (local_58 != (undefined8 *)0x0) {
    ExFreePoolWithTag(local_58,0);
  }
  if (local_50[0] != (undefined8 *)0x0) {
    ExFreePoolWithTag(local_50[0],0);
  }
  return uVar2;
}



===== BfsProcessQueryPolicyRequest @ 14000899c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong BfsProcessQueryPolicyRequest(longlong *param_1,uint *param_2,uint param_3)

{
  undefined8 ****ppppuVar1;
  undefined8 ****ppppuVar2;
  code *pcVar3;
  uint *puVar4;
  bool bVar5;
  byte bVar6;
  uint uVar7;
  ulonglong uVar8;
  undefined1 *puVar9;
  undefined8 ****ppppuVar10;
  undefined1 auStackY_e8 [8];
  undefined1 auStackY_e0 [24];
  uint local_b8;
  uint local_b4;
  longlong *local_b0;
  undefined8 ****local_a8;
  undefined8 ****local_a0;
  undefined8 *local_98;
  undefined8 *local_90;
  uint local_88;
  undefined4 local_84;
  uint *local_80;
  longlong *local_78;
  longlong local_70;
  uint *puStack_68;
  uint *local_40;
  undefined4 local_38;
  undefined4 local_34;
  ulonglong local_30;
  
  puVar9 = auStackY_e8;
  local_30 = __security_cookie ^ (ulonglong)auStackY_e8;
  local_90 = (undefined8 *)0x0;
  local_78 = (longlong *)0x0;
  local_b0 = (longlong *)0x0;
  local_98 = (undefined8 *)0x0;
  if ((param_2 == (uint *)0x0) || (param_3 == 0)) {
    uVar8 = 0xc000000d;
    goto LAB_140008d96;
  }
  local_b4 = 0;
  local_b8 = 0;
  local_a0 = &local_a8;
  local_a8 = &local_a8;
  ProbeForWrite(param_2,param_3,4);
  uVar7 = ObReferenceObjectByHandle(param_1,8,*(undefined8 *)SeTokenObjectType_exref,1);
  uVar8 = (ulonglong)uVar7;
  if ((int)uVar7 < 0) goto LAB_140008a67;
  param_1 = local_b0;
  bVar5 = BfsIsApplicableToken(local_b0);
  if (bVar5) {
    param_1 = local_b0;
    uVar7 = SeQueryInformationToken(local_b0,1,&local_98);
    uVar8 = (ulonglong)uVar7;
    if ((int)uVar7 < 0) {
LAB_140008a67:
      if (3 < DAT_140019000) {
        local_b8 = uVar7;
        goto LAB_140008a78;
      }
    }
    else {
      param_1 = local_b0;
      uVar7 = SeQueryInformationToken(local_b0,0x1f,&local_90);
      uVar8 = (ulonglong)uVar7;
      if ((int)uVar7 < 0) goto LAB_140008a67;
      bVar6 = BfsPolicyEntryExists
                        (gBfsFilterHandle,0,0x140019260,(byte *)*local_98,(byte *)*local_90);
      if (bVar6 != 0) {
        param_1 = gBfsFilterHandle;
        uVar7 = BfsGetPolicyEntry(gBfsFilterHandle,0,(longlong *)&gBfsPolicyTable,(byte *)*local_98,
                                  (byte *)*local_90,(longlong *)&local_78);
        uVar8 = (ulonglong)uVar7;
        if (-1 < (int)uVar7) {
          param_1 = local_78;
          uVar8 = BfsEnumeratePolicy((longlong)local_78,(longlong *)&local_a8,(int *)&local_b8,
                                     (int *)&local_b4);
          uVar7 = (uint)uVar8;
          uVar8 = uVar8 & 0xffffffff;
          if (-1 < (int)uVar7) {
            if (param_3 < local_b4) {
              uVar8 = 0xc0000023;
              goto LAB_140008ac6;
            }
            memset(param_2,0,(ulonglong)local_b4);
            *param_2 = local_b8;
            uVar8 = 0;
            local_88 = 0;
            local_80 = param_2 + (ulonglong)local_b8 * 8 + 2;
            for (ppppuVar10 = local_a8; puVar4 = local_80, (undefined8 *****)ppppuVar10 != &local_a8
                ; ppppuVar10 = (undefined8 ****)*ppppuVar10) {
              param_2[uVar8 * 8 + 2] = *(uint *)(ppppuVar10 + 2);
              param_2[uVar8 * 8 + 4] = *(uint *)(ppppuVar10 + 3);
              param_2[uVar8 * 8 + 3] = *(uint *)((longlong)ppppuVar10 + 0x14);
              local_70 = (ulonglong)*(ushort *)((longlong)ppppuVar10 + 0x22) << 0x10;
              puStack_68 = local_80;
              RtlCopyUnicodeString(&local_70);
              *(longlong *)(param_2 + uVar8 * 8 + 6) = local_70;
              *(uint **)(param_2 + uVar8 * 8 + 6 + 2) = puStack_68;
              local_80 = (uint *)((longlong)puVar4 +
                                 (ulonglong)*(ushort *)((longlong)ppppuVar10 + 0x22));
              local_88 = (int)uVar8 + 1;
              uVar8 = (ulonglong)local_88;
            }
            uVar8 = 0;
            local_84 = 0;
            goto LAB_140008cd9;
          }
        }
        goto LAB_140008a67;
      }
    }
  }
  else {
    uVar8 = 0xc000a200;
LAB_140008ac6:
    if (DAT_140019000 < 4) goto LAB_140008cd9;
    local_b8 = (uint)uVar8;
LAB_140008a78:
    local_40 = &local_b8;
    local_38 = 4;
    local_34 = 0;
    _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_140016d11);
  }
LAB_140008cd9:
  while( true ) {
    ppppuVar10 = local_a8;
    puVar9 = auStackY_e8;
    if ((undefined8 *****)local_a8 == &local_a8) break;
    ppppuVar2 = (undefined8 ****)*local_a8;
    if (((undefined8 *****)local_a8[1] != &local_a8) || ((undefined8 ****)ppppuVar2[1] != local_a8))
    {
      pcVar3 = (code *)swi(0x29);
      (*pcVar3)(3);
      puVar9 = auStackY_e0;
      break;
    }
    ppppuVar2[1] = &local_a8;
    ppppuVar1 = local_a8 + 4;
    local_a8 = ppppuVar2;
    RtlFreeUnicodeString(ppppuVar1);
    ExFreePoolWithTag(ppppuVar10);
  }
  if (*(longlong *)(puVar9 + 0x70) != 0) {
    *(undefined8 *)(puVar9 + -8) = 0x140008d45;
    BfsDereferencePolicyEntryEx(*(longlong *)(puVar9 + 0x70),'\0');
  }
  if (*(longlong *)(puVar9 + 0x38) != 0) {
    *(undefined8 *)(puVar9 + -8) = 0x140008d56;
    ObfDereferenceObject();
  }
  if (*(longlong *)(puVar9 + 0x50) != 0) {
    *(undefined8 *)(puVar9 + -8) = 0x140008d6e;
    ExFreePoolWithTag(*(longlong *)(puVar9 + 0x50),0);
  }
  if (*(longlong *)(puVar9 + 0x58) != 0) {
    *(undefined8 *)(puVar9 + -8) = 0x140008d86;
    ExFreePoolWithTag(*(longlong *)(puVar9 + 0x58),0);
  }
LAB_140008d96:
  *(undefined8 *)(puVar9 + -8) = 0x140008da6;
  return uVar8;
}



===== BfsProcessQueryPolicySizeRequest @ 140008dc0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong BfsProcessQueryPolicySizeRequest(longlong *param_1,int *param_2)

{
  bool bVar1;
  byte bVar2;
  uint uVar3;
  longlong *plVar4;
  ulonglong uVar5;
  undefined1 auStackY_a8 [32];
  uint local_78 [2];
  longlong *local_70;
  longlong *local_68;
  undefined8 *local_60;
  undefined8 *local_58 [5];
  uint *local_30;
  undefined8 local_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_58[0] = (undefined8 *)0x0;
  local_68 = (longlong *)0x0;
  local_70 = (longlong *)0x0;
  local_60 = (undefined8 *)0x0;
  uVar3 = ObReferenceObjectByHandle(param_1,8,*(undefined8 *)SeTokenObjectType_exref,1);
  uVar5 = (ulonglong)uVar3;
  if ((int)uVar3 < 0) goto LAB_140008e2a;
  param_1 = local_70;
  bVar1 = BfsIsApplicableToken(local_70);
  if (bVar1) {
    param_1 = local_70;
    uVar3 = SeQueryInformationToken(local_70,1,&local_60);
    uVar5 = (ulonglong)uVar3;
    if (-1 < (int)uVar3) {
      param_1 = local_70;
      uVar3 = SeQueryInformationToken(local_70,0x1f,local_58);
      uVar5 = (ulonglong)uVar3;
      if (-1 < (int)uVar3) {
        param_1 = gBfsFilterHandle;
        bVar2 = BfsPolicyEntryExists
                          (gBfsFilterHandle,0,0x140019260,(byte *)*local_60,(byte *)*local_58[0]);
        if (bVar2 == 0) {
          uVar5 = 0xc000000f;
          goto LAB_140008e76;
        }
        plVar4 = gBfsFilterHandle;
        uVar3 = BfsGetPolicyEntry(gBfsFilterHandle,0,(longlong *)&gBfsPolicyTable,(byte *)*local_60,
                                  (byte *)*local_58[0],(longlong *)&local_68);
        uVar5 = (ulonglong)uVar3;
        if ((int)uVar3 < 0) {
LAB_140008f4e:
          if (3 < DAT_140019000) {
            local_30 = local_78;
            local_28 = 4;
            local_78[0] = uVar3;
            _tlgWriteTransfer_EtwWriteTransfer(plVar4,&DAT_140016d11);
          }
        }
        else {
          plVar4 = local_68;
          uVar5 = BfsEnumeratePolicy((longlong)local_68,(longlong *)0x0,(int *)0x0,param_2);
          uVar3 = (uint)uVar5;
          uVar5 = uVar5 & 0xffffffff;
          if ((int)uVar3 < 0) goto LAB_140008f4e;
        }
        if (local_68 != (longlong *)0x0) {
          BfsDereferencePolicyEntryEx((longlong)local_68,'\0');
        }
        goto LAB_140008f90;
      }
    }
LAB_140008e2a:
    if (DAT_140019000 < 4) goto LAB_140008f90;
    local_78[0] = uVar3;
  }
  else {
    uVar5 = 0xc000a200;
LAB_140008e76:
    if (DAT_140019000 < 4) goto LAB_140008f90;
    local_78[0] = (uint)uVar5;
  }
  local_30 = local_78;
  local_28 = 4;
  _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_140016d11);
LAB_140008f90:
  if (local_70 != (longlong *)0x0) {
    ObfDereferenceObject();
  }
  if (local_60 != (undefined8 *)0x0) {
    ExFreePoolWithTag(local_60,0);
  }
  if (local_58[0] != (undefined8 *)0x0) {
    ExFreePoolWithTag(local_58[0],0);
  }
  return uVar5;
}



===== BfsProcessSetPolicyRequest @ 140008ffc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong BfsProcessSetPolicyRequest(undefined8 *param_1,uint param_2)

{
  longlong lVar1;
  int iVar2;
  ushort uVar3;
  bool bVar4;
  uint uVar5;
  int iVar6;
  ulonglong uVar7;
  ushort *puVar8;
  ulonglong uVar9;
  ushort *******pppppppuVar10;
  short sVar11;
  longlong lVar12;
  undefined1 auStackY_1a8 [32];
  uint local_138 [2];
  longlong local_130;
  longlong local_128;
  ushort *******local_120;
  ushort *******local_118;
  undefined8 *local_110;
  undefined8 *local_108;
  ushort *******local_100;
  ushort ******local_f8;
  longlong lStack_f0;
  undefined8 local_e8;
  void *pvStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  longlong lStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 *local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  ulonglong uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  ushort ******local_68;
  undefined8 uStack_60;
  ushort *******local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  ulonglong uStack_40;
  uint *local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_1a8;
  local_108 = (undefined8 *)0x0;
  local_118 = (ushort *******)0x0;
  local_f8 = (ushort ******)0x0;
  lStack_f0 = 0;
  lVar12 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_130 = 0;
  local_100 = (ushort *******)0x0;
  local_88 = 0;
  uStack_80 = 0;
  local_68 = (ushort ******)0x0;
  uStack_60 = 0;
  local_b8 = 0;
  uStack_b0 = 0;
  local_a8 = (undefined8 *)0x0;
  uStack_a0 = 0;
  local_98 = 0;
  uStack_90 = uStack_90 & 0xffffffff00000000;
  local_e8 = 0;
  pvStack_e0 = (void *)0x0;
  local_128 = 0;
  local_c8 = 0;
  lStack_c0 = 0;
  local_120 = (ushort *******)0x0;
  local_110 = (undefined8 *)0x0;
  if (param_2 < 0x30) {
    return 0xc0000023;
  }
  local_58 = (ushort *******)*param_1;
  uStack_50 = param_1[1];
  local_48 = param_1[2];
  uStack_40 = param_1[3];
  local_38 = (uint *)param_1[4];
  uStack_30 = param_1[5];
  uVar7 = Feature_AppSiloBfsProcessSetPolicyRequestBufferCheck__private_IsEnabledDeviceUsageNoInline
                    ();
  if (((int)uVar7 != 0) && ((uStack_40 & 1) != 0)) {
    return 0xc000000d;
  }
  uVar3 = (ushort)uStack_40;
  uVar5 = (uint)(ushort)uStack_40;
  ProbeForRead(local_38,uVar5,2);
  if (uVar3 == 0) {
    return 0xc0000206;
  }
  pvStack_e0 = (void *)ExAllocatePool2(0x100,(ulonglong)uVar5,0x50736642);
  if (pvStack_e0 == (void *)0x0) {
    return 0xc0000017;
  }
  local_e8._0_4_ = CONCAT22((ushort)uStack_40,(ushort)uStack_40);
  memmove(pvStack_e0,local_38,(ulonglong)uVar5);
  pppppppuVar10 = local_58;
  uVar5 = ObReferenceObjectByHandle(local_58,8,*(undefined8 *)SeTokenObjectType_exref,1);
  uVar7 = (ulonglong)uVar5;
  if ((int)uVar5 < 0) {
LAB_14000964f:
    if (DAT_140019000 < 4) goto LAB_14000968e;
    local_138[0] = uVar5;
  }
  else {
    pppppppuVar10 = local_120;
    bVar4 = BfsIsApplicableToken(local_120);
    if (bVar4) {
      pppppppuVar10 = local_120;
      uVar5 = SeQueryInformationToken(local_120,1,&local_110);
      uVar7 = (ulonglong)uVar5;
      if (-1 < (int)uVar5) {
        pppppppuVar10 = local_120;
        uVar5 = SeQueryInformationToken(local_120,0x1f,&local_108);
        uVar7 = (ulonglong)uVar5;
        if (-1 < (int)uVar5) {
          iVar2 = (int)uStack_50;
          local_b8 = CONCAT44(local_b8._4_4_,0x30);
          uStack_b0 = 0;
          uStack_a0 = CONCAT44(uStack_a0._4_4_,0x600);
          local_a8 = &local_e8;
          local_98 = 0;
          uStack_90 = 0;
          pppppppuVar10 = (ushort *******)&local_118;
          uVar5 = ZwOpenFile(pppppppuVar10,0x80000000,&local_b8,&local_88);
          bVar4 = uVar5 == 0xc0000034;
          if (bVar4) {
            pppppppuVar10 = (ushort *******)&local_118;
            uVar5 = IoCreateFile(pppppppuVar10,0x80100000,&local_b8,&local_88);
          }
          uVar7 = (ulonglong)uVar5;
          if ((int)uVar5 < 0) goto LAB_1400091e6;
          pppppppuVar10 = local_118;
          uVar5 = ObReferenceObjectByHandle
                            (local_118,0x80000000,*(undefined8 *)IoFileObjectType_exref,0);
          uVar7 = (ulonglong)uVar5;
          if (-1 < (int)uVar5) {
            pppppppuVar10 = local_100;
            uVar5 = FltGetFileNameInformationUnsafe(local_100,0,0x101,&local_130);
            uVar7 = (ulonglong)uVar5;
            if (-1 < (int)uVar5) {
              puVar8 = BfsGetFileName((ushort *)&local_d8,local_130);
              local_f8 = *(ushort *******)puVar8;
              lStack_f0 = *(longlong *)(puVar8 + 4);
              puVar8 = BfsGetShareName((ushort *)&local_d8,local_130);
              local_c8 = *(undefined8 *)puVar8;
              lStack_c0 = *(longlong *)(puVar8 + 4);
              if (bVar4) {
                pppppppuVar10 = (ushort *******)&local_d8;
                puVar8 = BfsGetFinalPathComponent((ushort *)pppppppuVar10,&local_e8);
                local_78 = *(undefined8 *)puVar8;
                uStack_70 = *(undefined8 *)(puVar8 + 4);
                if (*puVar8 == 0) {
                  uVar7 = 0xc000003a;
                  goto LAB_1400091e6;
                }
                pppppppuVar10 = &local_f8;
                uVar5 = BfsAllocateAndConcatenatePath
                                  ((short *)pppppppuVar10,(short *)&local_78,&local_f8);
                uVar7 = (ulonglong)uVar5;
                if ((int)uVar5 < 0) goto LAB_14000964f;
                lVar12 = lStack_f0;
              }
              pppppppuVar10 = gBfsFilterHandle;
              uVar5 = BfsGetPolicyEntry((longlong *)gBfsFilterHandle,0,(longlong *)&gBfsPolicyTable,
                                        (byte *)*local_110,(byte *)*local_108,&local_128);
              uVar7 = (ulonglong)uVar5;
              if (-1 < (int)uVar5) {
                if (((int)uStack_30 == 0) || ((int)uStack_30 == 1)) {
                  if ((lStack_c0 != 0) &&
                     ((iVar6 = RtlCompareUnicodeString(&local_f8,&local_c8,1), lVar1 = local_128,
                      iVar6 != 0 &&
                      (uVar7 = BfsGetPolicy(*(longlong *)(local_128 + 0x30),
                                            (ushort *)(local_130 + 0x18),&local_c8),
                      1 < (int)uVar7 - 1U)))) {
                    pppppppuVar10 = *(ushort ********)(lVar1 + 0x30);
                    uVar7 = BfsAddOrModifyEntry((longlong)pppppppuVar10,2,2,0,
                                                (ushort *)(local_130 + 0x18),(short *)&local_c8);
                    uVar5 = (uint)uVar7;
                    uVar7 = uVar7 & 0xffffffff;
                    if ((int)uVar5 < 0) goto LAB_14000964f;
                  }
                  pppppppuVar10 = *(ushort ********)(local_128 + 0x30);
                  uVar7 = BfsAddOrModifyEntry((longlong)pppppppuVar10,iVar2,uStack_50._4_4_,
                                              (int)local_48,(ushort *)(local_130 + 0x18),
                                              (short *)&local_f8);
                  uVar5 = (uint)uVar7;
                  uVar7 = uVar7 & 0xffffffff;
                  if ((int)uVar5 < 0) goto LAB_14000964f;
                  uVar9 = Feature_Servicing_BfsGAFeature__private_IsEnabledDeviceUsageNoInline();
                  if ((int)uVar9 == 0) goto LAB_14000968e;
                  uStack_d0 = *(undefined8 *)(local_130 + 0x10);
                  sVar11 = *(short *)(local_130 + 8) - *(short *)(local_130 + 0x48);
                  local_d8 = (ushort ******)(ulonglong)CONCAT22(sVar11,sVar11);
                  local_68 = local_d8;
                  pppppppuVar10 = (ushort *******)&gBfsGlobalFileTable;
                  uStack_60 = uStack_d0;
                  uVar7 = BfsAddPolicyToGlobalFileTable
                                    (0x140019190,(byte *)*local_110,(byte *)*local_108,
                                     (ushort *)&local_68,iVar2);
                }
                else {
                  if ((int)uStack_30 != 2) goto LAB_14000968e;
                  pppppppuVar10 = *(ushort ********)(local_128 + 0x30);
                  uVar7 = BfsDeleteEntry((longlong)pppppppuVar10,iVar2,(ushort *)(local_130 + 0x18),
                                         &local_f8);
                }
                uVar5 = (uint)uVar7;
                uVar7 = uVar7 & 0xffffffff;
                if (-1 < (int)uVar5) goto LAB_14000968e;
              }
            }
          }
        }
      }
      goto LAB_14000964f;
    }
    uVar7 = 0xc000a200;
LAB_1400091e6:
    if (DAT_140019000 < 4) goto LAB_14000968e;
    local_138[0] = (uint)uVar7;
  }
  local_38 = local_138;
  uStack_30 = 4;
  _tlgWriteTransfer_EtwWriteTransfer(pppppppuVar10,&DAT_140016d11);
LAB_14000968e:
  if (local_128 != 0) {
    BfsDereferencePolicyEntryEx(local_128,'\0');
  }
  if (lVar12 != 0) {
    ExFreePoolWithTag(lVar12,0);
  }
  if (local_130 != 0) {
    FltReleaseFileNameInformation(local_130);
  }
  if (pvStack_e0 != (void *)0x0) {
    ExFreePoolWithTag(pvStack_e0,0);
  }
  if (local_118 != (ushort *******)0x0) {
    ZwClose();
  }
  if (local_100 != (ushort *******)0x0) {
    ObfDereferenceObject();
  }
  if (local_120 != (ushort *******)0x0) {
    ObfDereferenceObject();
  }
  if (local_110 != (undefined8 *)0x0) {
    ExFreePoolWithTag(local_110,0);
  }
  if (local_108 != (undefined8 *)0x0) {
    ExFreePoolWithTag(local_108,0);
  }
  return uVar7;
}



===== BfsQueryAccessOnly @ 1400097c0 =====

bool BfsQueryAccessOnly(int param_1,longlong param_2)

{
  byte bVar1;
  uint uVar2;
  ulonglong uVar3;
  bool bVar4;
  
  uVar2 = *(uint *)(*(longlong *)(*(longlong *)(*(longlong *)(param_2 + 0x10) + 0x18) + 8) + 0x18);
  uVar3 = Feature_893282618__private_IsEnabledDeviceUsageNoInline();
  if ((((int)uVar3 == 0) || (bVar1 = *(byte *)(*(longlong *)(param_2 + 0x10) + 0x23), bVar1 == 1))
     || (5 < bVar1)) {
    if (param_1 == 2) {
      uVar2 = uVar2 & 0xffe1ff7e;
    }
    else {
      uVar2 = uVar2 & 0xffe1ff76;
    }
    bVar4 = uVar2 == 0;
  }
  else {
    bVar4 = false;
  }
  return bVar4;
}



===== BfsQueryFileNameInformationCallback @ 140009830 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint BfsQueryFileNameInformationCallback
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 *param_4)

{
  uint uVar1;
  void *pvVar2;
  undefined1 auStack_a8 [40];
  undefined1 *local_80;
  uint local_78 [2];
  longlong local_70 [3];
  undefined1 local_58 [32];
  uint *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_a8;
  pvVar2 = (void *)*param_4;
  local_70[0] = 0;
  local_70[1] = 0;
  local_70[2] = 0;
  uVar1 = BfsImpersonateUser(pvVar2,local_70);
  if ((int)uVar1 < 0) {
    if (3 < DAT_140019000) {
      local_2c = 0;
      local_38 = local_78;
      local_80 = local_58;
      local_30 = 4;
      local_78[0] = uVar1;
      _tlgWriteTransfer_EtwWriteTransfer(pvVar2,&DAT_140016d11);
    }
  }
  else {
    uVar1 = FltGetFileNameInformation(param_3,0x101,param_4 + 1);
    if (((int)uVar1 < 0) && (3 < DAT_140019000)) {
      local_2c = 0;
      local_38 = local_78;
      local_80 = local_58;
      local_30 = 4;
      local_78[0] = uVar1;
      _tlgWriteTransfer_EtwWriteTransfer(param_3,&DAT_140016d11);
    }
    BfsRevertTokenImpersonation(local_70);
    if (-1 < (int)uVar1) {
      return uVar1;
    }
  }
  if (param_4[1] != 0) {
    FltReleaseFileNameInformation();
  }
  return uVar1;
}



===== BfsRemovePolicyEntry @ 140009950 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int BfsRemovePolicyEntry
              (undefined8 param_1,undefined8 param_2,longlong param_3,byte *param_4,byte *param_5)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  longlong lVar4;
  ulonglong uVar5;
  undefined8 *puVar6;
  longlong lVar7;
  undefined1 auStackY_108 [32];
  longlong local_d8;
  longlong local_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  longlong lStack_a0;
  undefined8 *local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  longlong *local_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_108;
  local_d0 = 0;
  local_a8 = 0;
  lStack_a0 = 0;
  lVar7 = 0;
  local_d8 = 0;
  local_98 = (undefined8 *)0x0;
  uStack_90 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_c8 = 0;
  uStack_c0 = 0;
  local_b8 = 0;
  uStack_b0 = 0;
  uVar1 = RtlLengthSid(param_4);
  BfsUpdateHash(param_4,uVar1,&local_d8);
  uVar1 = RtlLengthSid(param_5);
  BfsUpdateHash(param_5,uVar1,&local_d8);
  uVar3 = BfsFinalHash(&local_d8);
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(param_3,0);
  lVar4 = BfsLookupPolicyEntryHashTable(*(undefined8 *)(param_3 + 8),uVar3,param_4,param_5);
  if (lVar4 != 0) {
    if (*(int *)(lVar4 + 0x38) != 0x10000000) {
      iVar2 = 0;
      goto LAB_140009b94;
    }
    *(undefined4 *)(lVar4 + 0x38) = 0x10000002;
    uVar5 = Feature_Servicing_BfsGAFeature__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar5 != 0) {
      BfsRemoveAllPoliciesFromGlobalFileTable(0x140019190,lVar4);
    }
    BfsDereferencePolicyEntryEx(lVar4,'\x01');
  }
  RtlInitUnicodeString(&local_b8,0);
  RtlInitUnicodeString(&local_c8,0);
  puVar6 = &local_b8;
  iVar2 = RtlConvertSidToUnicodeString(puVar6,param_4,1);
  if (-1 < iVar2) {
    puVar6 = &local_c8;
    iVar2 = RtlConvertSidToUnicodeString(puVar6,param_5,1);
    if (-1 < iVar2) {
      iVar2 = BfsOpenPolicyDirectory(param_1,0,&local_b8,'\x01',&local_d0);
      lVar7 = local_d0;
      if (iVar2 < 0) {
        if (3 < DAT_140019000) {
          local_d8 = CONCAT44(local_d8._4_4_,iVar2);
          local_58 = &local_d8;
          local_50 = 4;
          _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_140016d11);
        }
        lVar7 = local_d0;
        goto LAB_140009b94;
      }
      local_98 = &local_c8;
      lStack_a0 = local_d0;
      puVar6 = &local_a8;
      local_88 = 0;
      uStack_80 = 0;
      local_a8 = CONCAT44(local_a8._4_4_,0x30);
      uStack_90 = CONCAT44(uStack_90._4_4_,0x40);
      iVar2 = ZwDeleteFile();
      if (-1 < iVar2) goto LAB_140009b94;
    }
  }
  if (3 < DAT_140019000) {
    local_d8 = CONCAT44(local_d8._4_4_,iVar2);
    local_58 = &local_d8;
    local_50 = 4;
    _tlgWriteTransfer_EtwWriteTransfer(puVar6,&DAT_140016d11);
  }
LAB_140009b94:
  ExReleasePushLockExclusiveEx(param_3,0);
  KeLeaveCriticalRegion();
  if ((short)local_c8 != 0) {
    RtlFreeUnicodeString(&local_c8);
  }
  if ((short)local_b8 != 0) {
    RtlFreeUnicodeString(&local_b8);
  }
  if (lVar7 != 0) {
    FltClose(lVar7);
  }
  return iVar2;
}



===== BfsUnicodeStringEndsWith @ 140009c24 =====

longlong BfsUnicodeStringEndsWith(ushort *param_1,ushort *param_2)

{
  ushort uVar1;
  uint7 uVar3;
  longlong lVar2;
  uint uVar4;
  uint uVar5;
  
  uVar1 = *param_2;
  uVar5 = (uVar1 >> 1) - 1;
  uVar3 = (uint7)(byte)(uVar1 >> 8);
  if (uVar1 == 0) {
LAB_140009c7c:
    lVar2 = CONCAT71(uVar3,1);
  }
  else {
    if (uVar1 <= *param_1) {
      uVar4 = ((uint)(*param_1 >> 1) - (uint)(uVar1 >> 1)) + uVar5;
      while (*(short *)(*(longlong *)(param_1 + 4) + (ulonglong)uVar4 * 2) ==
             *(short *)(*(longlong *)(param_2 + 4) + (ulonglong)uVar5 * 2)) {
        if (uVar5 == 0) goto LAB_140009c7c;
        uVar5 = uVar5 - 1;
        uVar4 = uVar4 - 1;
      }
    }
    lVar2 = (ulonglong)uVar3 << 8;
  }
  return lVar2;
}



===== BfsUninitializePolicyTable @ 140009c90 =====

void BfsUninitializePolicyTable(longlong param_1)

{
  longlong lVar1;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  undefined8 uStack_18;
  undefined8 local_10;
  
  local_10 = 0;
  local_38 = 0;
  local_30 = 0;
  uStack_28 = 0;
  local_20 = 0;
  uStack_18 = 0;
  local_48 = 0;
  uStack_40 = 0;
  if (*(longlong *)(param_1 + 0x20) != 0) {
    ExDeleteTimer(*(longlong *)(param_1 + 0x20),1,1,&local_48);
    *(undefined8 *)(param_1 + 0x20) = 0;
  }
  if (*(longlong *)(param_1 + 8) != 0) {
    RtlInitEnumerationHashTable(*(longlong *)(param_1 + 8),&local_30);
    while( true ) {
      lVar1 = RtlEnumerateEntryHashTable(*(undefined8 *)(param_1 + 8),&local_30);
      if (lVar1 == 0) break;
      BfsDereferencePolicyEntryEx(lVar1,'\x01');
    }
    RtlEndEnumerationHashTable(*(undefined8 *)(param_1 + 8),&local_30);
    RtlDeleteHashTable(*(undefined8 *)(param_1 + 8));
    ExFreePoolWithTag(*(undefined8 *)(param_1 + 8),0);
    *(undefined8 *)(param_1 + 8) = 0;
  }
  return;
}



===== BfsUpdatePolicySecurity @ 140009d68 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint BfsUpdatePolicySecurity(undefined8 param_1)

{
  uint uVar1;
  undefined1 *_Dst;
  undefined8 uVar2;
  undefined8 ***pppuVar3;
  undefined1 uVar4;
  undefined1 auStack_128 [32];
  undefined8 *local_108;
  undefined1 *local_100;
  undefined4 local_f8;
  undefined4 local_f0;
  undefined1 local_e8;
  undefined8 *local_e0;
  undefined1 local_d8;
  uint local_c8 [2];
  undefined8 ***local_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 *local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  ulonglong uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined1 local_58 [32];
  uint *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_128;
  local_c0 = (undefined8 ***)0x0;
  local_88 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  uStack_80 = uStack_80 & 0xffffffff00000000;
  uVar4 = 1;
  local_98 = (undefined8 *)0x0;
  uStack_90 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_b8 = 0;
  uStack_b0 = 0;
  RtlInitUnicodeString(&local_b8,L"S-1-*");
  uVar2 = 0x100;
  _Dst = (undefined1 *)ExAllocatePool2(0x100,0x110,0x4e736642);
  if (_Dst == (undefined1 *)0x0) {
    uVar1 = 0xc0000017;
    if (3 < DAT_140019000) {
      local_2c = 0;
      local_38 = local_c8;
      local_100 = local_58;
      local_c8[0] = 0xc0000017;
      local_30 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(uVar2,&DAT_140016d11);
    }
  }
  else {
    do {
      local_e0 = &local_b8;
      local_e8 = 1;
      local_108 = &local_68;
      local_f0 = 0xc;
      local_f8 = 0x110;
      local_100 = _Dst;
      local_d8 = uVar4;
      uVar1 = ZwQueryDirectoryFile(param_1,0,0,0);
      uVar4 = 0;
      if (-1 < (int)uVar1) {
        RtlInitUnicodeString(&local_78,_Dst + 0xc);
        local_98 = &local_78;
        local_100 = (undefined1 *)CONCAT44(local_100._4_4_,0x21);
        local_a8 = CONCAT44(local_a8._4_4_,0x30);
        uStack_90 = CONCAT44(uStack_90._4_4_,0x200);
        pppuVar3 = &local_c0;
        local_108 = (undefined8 *)CONCAT44(local_108._4_4_,3);
        local_88 = 0;
        uStack_80 = 0;
        uStack_a0 = param_1;
        uVar1 = ZwOpenFile(pppuVar3,0x1f01ff,&local_a8);
        if (-1 < (int)uVar1) {
          pppuVar3 = local_c0;
          uVar1 = BfsUpdateUserPolicyDirectorySecurity(local_c0,&local_b8);
          if (-1 < (int)uVar1) {
            ZwClose(local_c0);
            local_c0 = (undefined8 ***)0x0;
            goto LAB_140009f30;
          }
        }
        if (3 < DAT_140019000) {
          local_2c = 0;
          local_38 = local_c8;
          local_100 = local_58;
          local_30 = 4;
          local_c8[0] = uVar1;
          _tlgWriteTransfer_EtwWriteTransfer(pppuVar3,&DAT_140016d11);
        }
        goto LAB_140009f75;
      }
LAB_140009f30:
      memset(_Dst,0,0x110);
    } while (-1 < (int)uVar1);
    if ((uVar1 == 0xc000000f) || (uVar1 == 0x80000006)) {
      uVar1 = ZwSetSecurityObject(param_1,0x17,&gBfsPolicyStorageDirectoryDescriptor);
    }
LAB_140009f75:
    ExFreePoolWithTag(_Dst,0);
  }
  if (local_c0 != (undefined8 ***)0x0) {
    ZwClose();
  }
  return uVar1;
}



===== BfsUpdateUserPolicyDirectorySecurity @ 14000a004 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint BfsUpdateUserPolicyDirectorySecurity(undefined8 param_1,undefined8 param_2)

{
  uint uVar1;
  undefined1 *_Dst;
  undefined8 uVar2;
  undefined8 ***pppuVar3;
  undefined1 uVar4;
  undefined1 auStack_128 [32];
  undefined8 *local_108;
  undefined1 *local_100;
  undefined4 local_f8;
  undefined4 local_f0;
  undefined1 local_e8;
  undefined8 local_e0;
  undefined1 local_d8;
  uint local_c8 [2];
  undefined8 ***local_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 *local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  ulonglong uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined1 local_68 [32];
  uint *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_128;
  local_c0 = (undefined8 ***)0x0;
  local_98 = 0;
  uStack_90 = uStack_90 & 0xffffffff00000000;
  uVar4 = 1;
  local_88 = 0;
  uStack_80 = 0;
  uVar2 = 0x100;
  local_b8 = 0;
  uStack_b0 = 0;
  local_a8 = (undefined8 *)0x0;
  uStack_a0 = 0;
  local_78 = 0;
  uStack_70 = 0;
  _Dst = (undefined1 *)ExAllocatePool2(0x100,0x110,0x4e736642);
  if (_Dst == (undefined1 *)0x0) {
    uVar1 = 0xc0000017;
    if (3 < DAT_140019000) {
      local_3c = 0;
      local_48 = local_c8;
      local_100 = local_68;
      local_c8[0] = 0xc0000017;
      local_40 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(uVar2,&DAT_140016d11);
    }
  }
  else {
    do {
      local_108 = &local_78;
      local_e8 = 1;
      local_f0 = 0xc;
      local_f8 = 0x110;
      local_100 = _Dst;
      local_e0 = param_2;
      local_d8 = uVar4;
      uVar1 = ZwQueryDirectoryFile(param_1,0,0,0);
      uVar4 = 0;
      if (-1 < (int)uVar1) {
        RtlInitUnicodeString(&local_88,_Dst + 0xc);
        local_a8 = &local_88;
        local_100 = (undefined1 *)CONCAT44(local_100._4_4_,0x60);
        local_b8 = CONCAT44(local_b8._4_4_,0x30);
        uStack_a0 = CONCAT44(uStack_a0._4_4_,0x200);
        pppuVar3 = &local_c0;
        local_108 = (undefined8 *)CONCAT44(local_108._4_4_,3);
        local_98 = 0;
        uStack_90 = 0;
        uStack_b0 = param_1;
        uVar1 = ZwOpenFile(pppuVar3,0x1f01ff,&local_b8);
        if (-1 < (int)uVar1) {
          pppuVar3 = local_c0;
          uVar1 = ZwSetSecurityObject(local_c0,0x17,&gBfsPolicyStorageFileDescriptor);
          if (-1 < (int)uVar1) {
            ZwClose(local_c0);
            local_c0 = (undefined8 ***)0x0;
            goto LAB_14000a1b0;
          }
        }
        if (3 < DAT_140019000) {
          local_3c = 0;
          local_48 = local_c8;
          local_100 = local_68;
          local_40 = 4;
          local_c8[0] = uVar1;
          _tlgWriteTransfer_EtwWriteTransfer(pppuVar3,&DAT_140016d11);
        }
        goto LAB_14000a1f5;
      }
LAB_14000a1b0:
      memset(_Dst,0,0x110);
    } while (-1 < (int)uVar1);
    if ((uVar1 == 0xc000000f) || (uVar1 == 0x80000006)) {
      uVar1 = ZwSetSecurityObject(param_1,0x17,&gBfsPolicyStorageDirectoryDescriptor);
    }
LAB_14000a1f5:
    ExFreePoolWithTag(_Dst,0);
  }
  if (local_c0 != (undefined8 ***)0x0) {
    ZwClose();
  }
  return uVar1;
}



===== BfsVerifyPolicySecurity @ 14000a280 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint BfsVerifyPolicySecurity(longlong param_1,undefined1 *param_2)

{
  undefined4 uVar1;
  char cVar2;
  uint uVar3;
  longlong lVar4;
  longlong lVar5;
  undefined1 auStackY_c8 [32];
  char local_98 [4];
  uint local_94;
  char local_90;
  char local_8f;
  char local_8e;
  char local_8d [5];
  undefined4 local_88;
  longlong local_80;
  longlong local_78;
  longlong local_70;
  longlong local_68 [5];
  uint *local_40;
  undefined8 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_c8;
  *param_2 = 1;
  local_98[0] = '\0';
  local_80 = 0;
  local_8d[1] = 0;
  local_8e = '\0';
  local_70 = 0;
  local_8f = '\0';
  local_88 = 0;
  local_78 = 0;
  local_90 = '\0';
  local_68[0] = 0;
  local_8d[2] = 0;
  local_8d[0] = '\0';
  lVar5 = param_1;
  uVar3 = ZwQuerySecurityObject(param_1,0x1f,0,0);
  uVar1 = local_88;
  if (uVar3 != 0xc0000023) {
    if (DAT_140019000 < 4) {
      return uVar3;
    }
    local_94 = uVar3;
LAB_14000a31a:
    uVar3 = local_94;
    local_40 = &local_94;
    local_38 = 4;
    _tlgWriteTransfer_EtwWriteTransfer(lVar5,&DAT_140016d11);
    return uVar3;
  }
  lVar5 = 0x100;
  lVar4 = ExAllocatePool2(0x100,local_88,0x44736642);
  if (lVar4 == 0) {
    if (DAT_140019000 < 4) {
      return 0xc0000017;
    }
    local_94 = 0xc0000017;
    goto LAB_14000a31a;
  }
  uVar3 = ZwQuerySecurityObject(param_1,0x1f,lVar4,uVar1);
  if ((-1 < (int)uVar3) &&
     (param_1 = lVar4, uVar3 = RtlGetOwnerSecurityDescriptor(lVar4,&local_78,&local_90),
     -1 < (int)uVar3)) {
    if ((local_78 == 0) ||
       ((local_90 == '\x01' ||
        (cVar2 = RtlEqualSid(local_78,*(undefined8 *)(*(longlong *)SeExports_exref + 0x108)),
        cVar2 == '\0')))) goto LAB_14000a5da;
    param_1 = lVar4;
    uVar3 = RtlGetGroupSecurityDescriptor(lVar4,&local_70,&local_8f);
    if (-1 < (int)uVar3) {
      if (((local_70 == 0) || (local_8f == '\x01')) ||
         (cVar2 = RtlEqualSid(local_70,*(undefined8 *)(*(longlong *)SeExports_exref + 0x108)),
         cVar2 == '\0')) goto LAB_14000a5da;
      param_1 = lVar4;
      uVar3 = RtlGetDaclSecurityDescriptor(lVar4,&local_8e,&local_80,local_8d + 1);
      if (-1 < (int)uVar3) {
        if (((local_8e == '\0') || (local_80 == 0)) || (*(short *)(local_80 + 4) != 2))
        goto LAB_14000a5da;
        param_1 = local_80;
        uVar3 = BfsVerifyAce(local_80,'\0','\x03',0x1f01ff,
                             *(undefined8 *)(*(longlong *)SeExports_exref + 0x220),local_98);
        if (-1 < (int)uVar3) {
          if (local_98[0] == '\0') goto LAB_14000a5da;
          param_1 = local_80;
          uVar3 = BfsVerifyAce(local_80,'\0','\x03',0x1f01ff,
                               *(undefined8 *)(*(longlong *)SeExports_exref + 0x108),local_98);
          if (-1 < (int)uVar3) {
            if (local_98[0] == '\0') goto LAB_14000a5da;
            param_1 = lVar4;
            uVar3 = RtlGetSaclSecurityDescriptor(lVar4,local_8d,local_68,local_8d + 2);
            if (-1 < (int)uVar3) {
              if ((local_8d[0] == '\0') || (local_68[0] == 0)) goto LAB_14000a5da;
              param_1 = local_68[0];
              uVar3 = BfsVerifyAce(local_68[0],'\x11','\x03',7,
                                   *(undefined8 *)(*(longlong *)SeExports_exref + 0x1f0),local_98);
              if (-1 < (int)uVar3) {
                if (local_98[0] != '\0') {
                  *param_2 = 0;
                }
                goto LAB_14000a5da;
              }
            }
          }
        }
      }
    }
  }
  if (3 < DAT_140019000) {
    local_40 = &local_94;
    local_38 = 4;
    local_94 = uVar3;
    _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_140016d11);
  }
LAB_14000a5da:
  ExFreePoolWithTag(lVar4,0);
  return uVar3;
}



===== Feature_1122292024__private_IsEnabledDeviceUsageNoInline @ 14000a618 =====

ulonglong Feature_1122292024__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_1122292024__private_featureState;
  if ((Feature_1122292024__private_featureState & 0x10) == 0) {
    uVar1 = Feature_1122292024__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_1122292024__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_1122292024__private_IsEnabledFallback @ 14000a650 =====

void Feature_1122292024__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_1122292024__private_descriptor);
  return;
}



===== Feature_1827994938__private_IsEnabledDeviceUsageNoInline @ 14000a66c =====

ulonglong Feature_1827994938__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_1827994938__private_featureState;
  if ((Feature_1827994938__private_featureState & 0x10) == 0) {
    uVar1 = Feature_1827994938__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_1827994938__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_1827994938__private_IsEnabledFallback @ 14000a6a4 =====

void Feature_1827994938__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_1827994938__private_descriptor);
  return;
}



===== Feature_3083317562__private_IsEnabledDeviceUsageNoInline @ 14000a6c0 =====

ulonglong Feature_3083317562__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_3083317562__private_featureState;
  if ((Feature_3083317562__private_featureState & 0x10) == 0) {
    uVar1 = Feature_3083317562__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_3083317562__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_3083317562__private_IsEnabledFallback @ 14000a6f8 =====

void Feature_3083317562__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_3083317562__private_descriptor);
  return;
}



===== Feature_3148938554__private_IsEnabledDeviceUsageNoInline @ 14000a714 =====

ulonglong Feature_3148938554__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_3148938554__private_featureState;
  if ((Feature_3148938554__private_featureState & 0x10) == 0) {
    uVar1 = Feature_3148938554__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_3148938554__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_3148938554__private_IsEnabledFallback @ 14000a74c =====

void Feature_3148938554__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_3148938554__private_descriptor);
  return;
}



===== Feature_3434922298__private_IsEnabledDeviceUsageNoInline @ 14000a768 =====

ulonglong Feature_3434922298__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_3434922298__private_featureState;
  if ((Feature_3434922298__private_featureState & 0x10) == 0) {
    uVar1 = Feature_3434922298__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_3434922298__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_3434922298__private_IsEnabledFallback @ 14000a7a0 =====

void Feature_3434922298__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_3434922298__private_descriptor);
  return;
}



===== Feature_893282618__private_IsEnabledDeviceUsageNoInline @ 14000a7bc =====

ulonglong Feature_893282618__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_893282618__private_featureState;
  if ((Feature_893282618__private_featureState & 0x10) == 0) {
    uVar1 = Feature_893282618__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_893282618__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_893282618__private_IsEnabledFallback @ 14000a7f4 =====

void Feature_893282618__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_893282618__private_descriptor);
  return;
}



===== Feature_AppSiloBfsProcessSetPolicyRequestBufferCheck__private_IsEnabledDeviceUsageNoInline @ 14000a810 =====

ulonglong Feature_AppSiloBfsProcessSetPolicyRequestBufferCheck__private_IsEnabledDeviceUsageNoInline
                    (void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_AppSiloBfsProcessSetPolicyRequestBufferCheck__private_featureState
  ;
  if ((Feature_AppSiloBfsProcessSetPolicyRequestBufferCheck__private_featureState & 0x10) == 0) {
    uVar1 = Feature_AppSiloBfsProcessSetPolicyRequestBufferCheck__private_IsEnabledFallback
                      (local_res8,3);
  }
  else {
    uVar1 = (ulonglong)
            (Feature_AppSiloBfsProcessSetPolicyRequestBufferCheck__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_AppSiloBfsProcessSetPolicyRequestBufferCheck__private_IsEnabledFallback @ 14000a848 =====

void Feature_AppSiloBfsProcessSetPolicyRequestBufferCheck__private_IsEnabledFallback
               (ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback
            (param_1,param_2,
             &Feature_AppSiloBfsProcessSetPolicyRequestBufferCheck__private_descriptor);
  return;
}



===== Feature_AppSiloEnumeratePolicyCheck__private_IsEnabledDeviceUsageNoInline @ 14000a864 =====

ulonglong Feature_AppSiloEnumeratePolicyCheck__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_AppSiloEnumeratePolicyCheck__private_featureState;
  if ((Feature_AppSiloEnumeratePolicyCheck__private_featureState & 0x10) == 0) {
    uVar1 = Feature_AppSiloEnumeratePolicyCheck__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_AppSiloEnumeratePolicyCheck__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_AppSiloEnumeratePolicyCheck__private_IsEnabledFallback @ 14000a89c =====

void Feature_AppSiloEnumeratePolicyCheck__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback
            (param_1,param_2,&Feature_AppSiloEnumeratePolicyCheck__private_descriptor);
  return;
}



===== BfsAcquireNamedPipeMapping @ 14000a8b8 =====

longlong BfsAcquireNamedPipeMapping(longlong param_1,byte *param_2,byte *param_3,ushort *param_4)

{
  undefined8 uVar1;
  longlong lVar2;
  longlong local_res8;
  
  local_res8 = 0;
  BfsUpdateHash(param_2,(uint)param_2[1] * 4 + 8,&local_res8);
  BfsUpdateHash(param_3,(uint)param_3[1] * 4 + 8,&local_res8);
  BfsUpdateUnicodeStringHash(param_4,&local_res8);
  uVar1 = BfsFinalHash(&local_res8);
  KeEnterCriticalRegion();
  ExAcquirePushLockSharedEx(param_1,0);
  lVar2 = BfsLookupPipeMappingEntryHashTable
                    (*(undefined8 *)(param_1 + 8),uVar1,param_2,param_3,param_4);
  if (lVar2 != 0) {
    LOCK();
    *(int *)(lVar2 + 0x18) = *(int *)(lVar2 + 0x18) + 1;
    UNLOCK();
  }
  ExReleasePushLockSharedEx(param_1,0);
  KeLeaveCriticalRegion();
  return lVar2;
}



===== BfsInitializePipeMappingTable @ 14000a9a0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 BfsInitializePipeMappingTable(longlong param_1)

{
  char cVar1;
  undefined8 uVar2;
  longlong local_res8 [4];
  
  local_res8[0] = param_1;
  ExInitializePushLock(&gBfsPipeMappingTable);
  local_res8[0] = ExAllocatePool2(0x100,0x28,0x54736642);
  if (local_res8[0] == 0) {
    uVar2 = 0xc0000017;
  }
  else {
    cVar1 = RtlCreateHashTable(local_res8,0,0);
    if (cVar1 == '\0') {
      ExFreePoolWithTag(local_res8[0],0);
      uVar2 = 0xc0000001;
    }
    else {
      _DAT_140019258 = local_res8[0];
      uVar2 = 0;
    }
  }
  return uVar2;
}



===== BfsInsertNamedPipeMapping @ 14000aa38 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint BfsInsertNamedPipeMapping
               (longlong param_1,byte *param_2,byte *param_3,ushort *param_4,undefined8 *param_5,
               undefined1 *param_6,longlong *param_7)

{
  uint uVar1;
  undefined8 uVar2;
  longlong lVar3;
  void *_Dst;
  undefined1 auStackY_c8 [32];
  longlong local_98;
  undefined8 local_90;
  longlong *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStackY_c8;
  local_98 = 0;
  *param_6 = 0;
  BfsUpdateHash(param_2,(uint)param_2[1] * 4 + 8,&local_98);
  BfsUpdateHash(param_3,(uint)param_3[1] * 4 + 8,&local_98);
  BfsUpdateUnicodeStringHash(param_4,&local_98);
  uVar2 = BfsFinalHash(&local_98);
  local_90 = uVar2;
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(param_1,0);
  lVar3 = BfsLookupPipeMappingEntryHashTable
                    (*(undefined8 *)(param_1 + 8),uVar2,param_2,param_3,param_4);
  if (lVar3 != 0) {
    LOCK();
    *(int *)(lVar3 + 0x18) = *(int *)(lVar3 + 0x18) + 1;
    UNLOCK();
    ExReleasePushLockExclusiveEx(param_1,0);
    KeLeaveCriticalRegion();
    *param_7 = lVar3;
    return 0;
  }
  uVar2 = 0x100;
  _Dst = (void *)ExAllocatePool2(0x100,0x50,0x4d736642);
  if (_Dst == (void *)0x0) {
    uVar1 = 0xc0000017;
    if (DAT_140019000 < 4) goto LAB_14000abfa;
    local_98 = CONCAT44(local_98._4_4_,0xc0000017);
  }
  else {
    memset(_Dst,0,0x50);
    *(byte **)((longlong)_Dst + 0x20) = param_2;
    *(byte **)((longlong)_Dst + 0x28) = param_3;
    uVar2 = *(undefined8 *)(param_4 + 4);
    *(undefined8 *)((longlong)_Dst + 0x30) = *(undefined8 *)param_4;
    *(undefined8 *)((longlong)_Dst + 0x38) = uVar2;
    uVar2 = param_5[1];
    *(undefined8 *)((longlong)_Dst + 0x40) = *param_5;
    *(undefined8 *)((longlong)_Dst + 0x48) = uVar2;
    *(undefined4 *)((longlong)_Dst + 0x18) = 1;
    uVar2 = *(undefined8 *)(param_1 + 8);
    uVar1 = BfsInsertEntryHashTable(uVar2,local_90,_Dst);
    if (-1 < (int)uVar1) {
      *(undefined4 *)((longlong)_Dst + 0x1c) = 1;
      *param_7 = (longlong)_Dst;
      *param_6 = 1;
      goto LAB_14000abfa;
    }
    if (DAT_140019000 < 4) goto LAB_14000abfa;
    local_98 = CONCAT44(local_98._4_4_,uVar1);
  }
  local_5c = 0;
  local_68 = &local_98;
  local_60 = 4;
  _tlgWriteTransfer_EtwWriteTransfer(uVar2,&DAT_140016d11);
LAB_14000abfa:
  ExReleasePushLockExclusiveEx(param_1,0);
  KeLeaveCriticalRegion();
  if (((int)uVar1 < 0) && (_Dst != (void *)0x0)) {
    ExFreePoolWithTag(_Dst,0);
  }
  return uVar1;
}



===== BfsLookupPipeMappingEntryHashTable @ 14000ac5c =====

longlong BfsLookupPipeMappingEntryHashTable
                   (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                   undefined8 param_5)

{
  char cVar1;
  longlong lVar2;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  lVar2 = RtlLookupEntryHashTable(0,param_2,&local_28);
  while( true ) {
    if (lVar2 == 0) {
      return 0;
    }
    cVar1 = RtlEqualSid(*(undefined8 *)(lVar2 + 0x20),param_3);
    if (((cVar1 != '\0') &&
        (cVar1 = RtlEqualSid(*(undefined8 *)(lVar2 + 0x28),param_4), cVar1 != '\0')) &&
       (cVar1 = RtlEqualUnicodeString(lVar2 + 0x30,param_5,1), cVar1 != '\0')) break;
    lVar2 = RtlGetNextEntryHashTable(param_1,&local_28);
  }
  return lVar2;
}



===== BfsNamedPipeStreamHandleCleanup @ 14000ad20 =====

void BfsNamedPipeStreamHandleCleanup(int *param_1,short param_2)

{
  if ((param_2 == 0x10) && (*param_1 == 1)) {
    BfsReleaseNamedPipeMapping(0x140019250,*(longlong *)(param_1 + 2));
  }
  return;
}



===== BfsRedirectNamedPipe @ 14000ad4c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int BfsRedirectNamedPipe
              (undefined8 param_1,longlong param_2,longlong param_3,longlong param_4,
              longlong param_5,short *param_6)

{
  ushort uVar1;
  int iVar2;
  longlong lVar3;
  longlong *plVar4;
  longlong lVar5;
  longlong lVar6;
  ushort uVar7;
  uint uVar8;
  undefined8 uVar9;
  ulonglong uVar10;
  undefined8 *puVar11;
  longlong lVar12;
  undefined1 auStack_f8 [32];
  undefined8 local_d8;
  undefined1 *local_d0;
  undefined4 **local_c8;
  undefined8 local_b8;
  longlong local_b0;
  longlong local_a8;
  undefined4 *local_a0;
  undefined8 local_98;
  longlong lStack_90;
  longlong local_88;
  undefined1 local_80 [32];
  undefined8 *local_60;
  undefined4 local_58;
  undefined4 local_54;
  ulonglong local_50;
  
  local_50 = __security_cookie ^ (ulonglong)auStack_f8;
  local_a0 = (undefined4 *)0x0;
  local_a8 = 0;
  uVar9 = 0x100;
  local_b8 = param_5;
  local_98 = 0;
  lStack_90 = 0;
  plVar4 = (longlong *)0x0;
  lVar3 = 0;
  local_b0 = ExAllocatePool2(0x100,(ulonglong)*(byte *)(param_3 + 1) * 4 + 8,0x53736642);
  if (local_b0 == 0) {
    if (DAT_140019000 < 4) {
      return -0x3fffffe9;
    }
    local_54 = 0;
    local_b8 = CONCAT44(local_b8._4_4_,0xc0000017);
    local_60 = &local_b8;
    local_d0 = local_80;
    local_58 = 4;
    _tlgWriteTransfer_EtwWriteTransfer(uVar9,&DAT_140016d11);
    return -0x3fffffe9;
  }
  uVar10 = (ulonglong)((uint)*(byte *)(param_3 + 1) * 4 + 8);
  iVar2 = RtlCopySid(uVar10,local_b0,param_3);
  if (iVar2 < 0) {
LAB_14000ae34:
    if (3 < DAT_140019000) {
      local_b8 = CONCAT44(local_b8._4_4_,iVar2);
LAB_14000b19b:
      local_54 = 0;
      local_60 = &local_b8;
      local_d0 = local_80;
      local_58 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(uVar10,&DAT_140016d11);
    }
  }
  else {
    uVar10 = 0x100;
    lVar3 = ExAllocatePool2(0x100,(ulonglong)*(byte *)(param_4 + 1) * 4 + 8,0x53736642);
    if (lVar3 == 0) {
LAB_14000ae75:
      iVar2 = -0x3fffffe9;
      goto LAB_14000ae34;
    }
    uVar10 = (ulonglong)((uint)*(byte *)(param_4 + 1) * 4 + 8);
    iVar2 = RtlCopySid(uVar10,lVar3,param_4);
    lVar6 = local_b8;
    if (iVar2 < 0) goto LAB_14000ae34;
    uVar8 = *(ushort *)(local_b8 + 0x18) + 0xe;
    uVar10 = (ulonglong)uVar8;
    uVar7 = (ushort)uVar8;
    if ((*(ushort *)(local_b8 + 0x18) <= uVar7) && (uVar1 = uVar7 + *param_6, uVar7 <= uVar1)) {
      uVar10 = 0x100;
      local_88 = ExAllocatePool2(0x100,uVar1,0x46736642);
      if (local_88 == 0) goto LAB_14000ae75;
      local_98._0_4_ = CONCAT22(uVar1,(undefined2)local_98);
      lStack_90 = local_88;
      RtlCopyUnicodeString(&local_98,lVar6 + 0x18);
      puVar11 = &local_98;
      iVar2 = RtlAppendUnicodeStringToString(puVar11,&ReparsePrefixString);
      if (iVar2 < 0) {
joined_r0x00014000afc5:
        if (3 < DAT_140019000) {
          local_54 = 0;
          local_b8._4_4_ = (undefined4)((ulonglong)local_b8 >> 0x20);
          local_b8 = CONCAT44(local_b8._4_4_,iVar2);
          local_60 = &local_b8;
          local_58 = 4;
          local_d0 = local_80;
          _tlgWriteTransfer_EtwWriteTransfer(puVar11,&DAT_140016d11);
        }
        lVar12 = local_b0;
      }
      else {
        puVar11 = &local_98;
        iVar2 = RtlAppendUnicodeStringToString(puVar11,param_6);
        if (iVar2 < 0) goto joined_r0x00014000afc5;
        puVar11 = (undefined8 *)0x100;
        plVar4 = (longlong *)ExAllocatePool2(0x100,0x30,0x52736642);
        lVar12 = local_b0;
        lVar6 = local_b8;
        if (plVar4 == (longlong *)0x0) {
          iVar2 = -0x3fffffe9;
          goto joined_r0x00014000afc5;
        }
        uVar9 = 0x100;
        *plVar4 = local_b0;
        plVar4[1] = lVar3;
        lVar5 = ExAllocatePool2(0x100,*(undefined2 *)(local_b8 + 8),0x46736642);
        plVar4[3] = lVar5;
        if (lVar5 == 0) {
LAB_14000b000:
          iVar2 = -0x3fffffe9;
        }
        else {
          *(undefined2 *)((longlong)plVar4 + 0x12) = *(undefined2 *)(lVar6 + 8);
          RtlCopyUnicodeString(plVar4 + 2,lVar6 + 8);
          uVar9 = 0x100;
          lVar6 = ExAllocatePool2(0x100,local_98 & 0xffff,0x46736642);
          plVar4[5] = lVar6;
          if (lVar6 == 0) goto LAB_14000b000;
          *(undefined2 *)((longlong)plVar4 + 0x22) = (undefined2)local_98;
          RtlCopyUnicodeString(plVar4 + 4,&local_98);
          uVar9 = param_1;
          iVar2 = FltGetEcpListFromCallbackData(param_1,param_2,&local_a8);
          if ((-1 < iVar2) &&
             ((local_a8 != 0 ||
              ((uVar9 = param_1, iVar2 = FltAllocateExtraCreateParameterList(param_1,0,&local_a8),
               -1 < iVar2 &&
               (uVar9 = param_1, iVar2 = FltSetEcpListIntoCallbackData(param_1,param_2,local_a8),
               -1 < iVar2)))))) {
            local_c8 = &local_a0;
            local_d0 = (undefined1 *)CONCAT44(local_d0._4_4_,0x70736642);
            local_d8 = 0;
            uVar9 = param_1;
            iVar2 = FltAllocateExtraCreateParameter(param_1,&BfsEcpType,0x10);
            if (-1 < iVar2) {
              *local_a0 = 1;
              *(longlong **)(local_a0 + 2) = plVar4;
              iVar2 = FltInsertExtraCreateParameter(param_1,local_a8,local_a0);
              uVar9 = param_1;
              if (-1 < iVar2) {
                BfsReparseNamedPipe(param_2,(undefined4 *)&local_98);
                return iVar2;
              }
            }
          }
        }
        if (3 < DAT_140019000) {
          local_54 = 0;
          local_b8 = CONCAT44(local_b8._4_4_,iVar2);
          local_60 = &local_b8;
          local_d0 = local_80;
          local_58 = 4;
          _tlgWriteTransfer_EtwWriteTransfer(uVar9,&DAT_140016d11);
        }
      }
      ExFreePoolWithTag(local_88,0);
      goto LAB_14000b1c6;
    }
    iVar2 = -0x3fffff6b;
    if (3 < DAT_140019000) {
      local_b8 = CONCAT44(local_b8._4_4_,0xc0000095);
      iVar2 = -0x3fffff6b;
      goto LAB_14000b19b;
    }
  }
  lVar12 = local_b0;
LAB_14000b1c6:
  ExFreePoolWithTag(lVar12,0);
  if (lVar3 != 0) {
    ExFreePoolWithTag(lVar3,0);
  }
  if (plVar4 != (longlong *)0x0) {
    if (plVar4[3] != 0) {
      ExFreePoolWithTag(plVar4[3],0);
    }
    if (plVar4[5] != 0) {
      ExFreePoolWithTag(plVar4[5],0);
    }
    ExFreePoolWithTag(plVar4,0);
  }
  return iVar2;
}



===== BfsReleaseNamedPipeMapping @ 14000b25c =====

void BfsReleaseNamedPipeMapping(longlong param_1,longlong param_2)

{
  int *piVar1;
  int iVar2;
  ulonglong uVar3;
  
  uVar3 = Feature_752421176__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar3 != 0) {
    KeEnterCriticalRegion();
    ExAcquirePushLockExclusiveEx(param_1,0);
  }
  LOCK();
  piVar1 = (int *)(param_2 + 0x18);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    uVar3 = Feature_752421176__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar3 == 0) {
      KeEnterCriticalRegion();
      ExAcquirePushLockExclusiveEx(param_1,0);
    }
    if (*(int *)(param_2 + 0x18) == 0) {
      if ((*(uint *)(param_2 + 0x1c) & 1) != 0) {
        BfsRemoveEntryHashTable(*(undefined8 *)(param_1 + 8),param_2);
      }
      ExFreePoolWithTag(*(undefined8 *)(param_2 + 0x20),0);
      ExFreePoolWithTag(*(undefined8 *)(param_2 + 0x28),0);
      RtlFreeUnicodeString(param_2 + 0x30);
      RtlFreeUnicodeString(param_2 + 0x40);
      ExFreePoolWithTag(param_2,0);
    }
    uVar3 = Feature_752421176__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar3 == 0) {
      ExReleasePushLockExclusiveEx(param_1,0);
      KeLeaveCriticalRegion();
    }
  }
  uVar3 = Feature_752421176__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar3 != 0) {
    ExReleasePushLockExclusiveEx(param_1,0);
    KeLeaveCriticalRegion();
  }
  return;
}



===== BfsReparseNamedPipe @ 14000b398 =====

void BfsReparseNamedPipe(longlong param_1,undefined4 *param_2)

{
  longlong lVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 8);
  if (*(longlong *)(lVar1 + 0x60) != 0) {
    ExFreePoolWithTag(*(longlong *)(lVar1 + 0x60),0);
  }
  uVar2 = param_2[1];
  uVar3 = param_2[2];
  uVar4 = param_2[3];
  *(undefined4 *)(lVar1 + 0x58) = *param_2;
  *(undefined4 *)(lVar1 + 0x5c) = uVar2;
  *(undefined4 *)(lVar1 + 0x60) = uVar3;
  *(undefined4 *)(lVar1 + 100) = uVar4;
  *(undefined8 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0x104;
  FltSetCallbackDataDirty(param_1);
  return;
}



===== BfsUninitializePipeMappingTable @ 14000b408 =====

void BfsUninitializePipeMappingTable(undefined8 *param_1)

{
  longlong lVar1;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_18 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  if (param_1[1] != 0) {
    KeEnterCriticalRegion();
    ExAcquirePushLockExclusiveEx(param_1,0);
    if (param_1[1] != 0) {
      RtlInitEnumerationHashTable(param_1[1],&local_38);
      while( true ) {
        lVar1 = RtlEnumerateEntryHashTable(param_1[1],&local_38);
        if (lVar1 == 0) break;
        BfsRemoveEntryHashTable(param_1[1],lVar1);
        *(uint *)(lVar1 + 0x1c) = *(uint *)(lVar1 + 0x1c) & 0xfffffffe;
      }
      RtlEndEnumerationHashTable(param_1[1],&local_38);
      RtlDeleteHashTable(param_1[1]);
      ExFreePoolWithTag(param_1[1],0);
      param_1[1] = 0;
    }
    ExReleasePushLockExclusiveEx(param_1,0);
    KeLeaveCriticalRegion();
    *param_1 = 0;
  }
  return;
}



===== Feature_752421176__private_IsEnabledDeviceUsageNoInline @ 14000b50c =====

ulonglong Feature_752421176__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_752421176__private_featureState;
  if ((Feature_752421176__private_featureState & 0x10) == 0) {
    uVar1 = Feature_752421176__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_752421176__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_752421176__private_IsEnabledFallback @ 14000b544 =====

void Feature_752421176__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_752421176__private_descriptor);
  return;
}



===== BfsAddPolicyToGlobalFileTable @ 14000b560 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong BfsAddPolicyToGlobalFileTable
                    (longlong param_1,byte *param_2,byte *param_3,ushort *param_4,undefined4 param_5
                    )

{
  uint uVar1;
  undefined8 uVar2;
  longlong lVar3;
  ulonglong uVar4;
  longlong lVar5;
  int iVar6;
  undefined1 auStack_c8 [40];
  undefined1 *local_a0;
  longlong local_98;
  byte *local_90;
  undefined1 local_88 [32];
  longlong *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStack_c8;
  local_98 = 0;
  local_90 = param_3;
  BfsUpdateUnicodeStringHash(param_4,&local_98);
  uVar2 = BfsFinalHash(&local_98);
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(param_1 + 8,0);
  KeEnterCriticalRegion();
  ExAcquirePushLockSharedEx(param_1,0);
  iVar6 = 1;
  lVar3 = BfsGetGlobalFileEntry(param_1,param_4);
  if (lVar3 == 0) {
    ExReleasePushLockSharedEx(param_1,0);
    KeLeaveCriticalRegion();
    KeEnterCriticalRegion();
    ExAcquirePushLockExclusiveEx(param_1,0);
    iVar6 = 2;
    lVar3 = BfsGetGlobalFileEntry(param_1,param_4);
    local_98 = lVar3;
    if (lVar3 != 0) goto LAB_14000b6c6;
    uVar4 = BfsCreateGlobalFileEntry(param_4,param_5,&local_98);
    lVar3 = local_98;
    uVar1 = (uint)uVar4;
    uVar4 = uVar4 & 0xffffffff;
    if (-1 < (int)uVar1) {
      param_4 = *(ushort **)(param_1 + 0x28);
      uVar1 = BfsInsertEntryHashTable(param_4,uVar2,local_98);
      uVar4 = (ulonglong)uVar1;
      if (-1 < (int)uVar1) goto LAB_14000b6c6;
    }
    if (3 < DAT_140019000) {
      local_5c = 0;
      local_98 = CONCAT44(local_98._4_4_,uVar1);
      local_68 = &local_98;
      local_a0 = local_88;
      local_60 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(param_4,&DAT_140016d11);
    }
LAB_14000b720:
    ExReleasePushLockExclusiveEx(param_1,0);
  }
  else {
LAB_14000b6c6:
    lVar5 = param_1;
    uVar1 = BfsUpdateGlobalFilePolicy(param_1,lVar3,param_2,local_90);
    uVar4 = (ulonglong)uVar1;
    if ((int)uVar1 < 0) {
      if (DAT_140019000 < 4) {
        return uVar4;
      }
      local_5c = 0;
      local_98 = CONCAT44(local_98._4_4_,uVar1);
      local_68 = &local_98;
      local_a0 = local_88;
      local_60 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(lVar5,&DAT_140016d11);
      return uVar4;
    }
    if (iVar6 == 2) goto LAB_14000b720;
    if (iVar6 != 1) goto LAB_14000b756;
    ExReleasePushLockSharedEx(param_1,0);
  }
  KeLeaveCriticalRegion();
LAB_14000b756:
  ExReleasePushLockExclusiveEx(param_1 + 8,0);
  KeLeaveCriticalRegion();
  return uVar4;
}



===== BfsCheckDeleteList @ 14000b7a0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 BfsCheckDeleteList(longlong *param_1,undefined8 param_2)

{
  undefined8 *puVar1;
  longlong lVar2;
  undefined8 *puVar3;
  
  lVar2 = _DAT_fffff78000000014;
  KeEnterCriticalRegion();
  ExAcquirePushLockSharedEx(&gBfsGlobalFileTable,0);
  if (((undefined8 **)DAT_1400191c0 == &DAT_1400191c0) ||
     (lVar2 - DAT_1400191c0[4] <= (longlong)(ulonglong)gBfsDeleteThreshold)) {
    ExReleasePushLockSharedEx(&gBfsGlobalFileTable,0);
  }
  else {
    ExReleasePushLockSharedEx(&gBfsGlobalFileTable,0);
    KeLeaveCriticalRegion();
    KeEnterCriticalRegion();
    ExAcquirePushLockExclusiveEx(&DAT_140019198,0);
    KeEnterCriticalRegion();
    ExAcquirePushLockExclusiveEx(&gBfsGlobalFileTable,0);
    puVar3 = DAT_1400191c0;
    while (((undefined8 **)puVar3 != &DAT_1400191c0 &&
           ((longlong)(ulonglong)gBfsDeleteThreshold < lVar2 - puVar3[4]))) {
      puVar1 = (undefined8 *)*puVar3;
      BfsDeleteFileFromGlobalFileTable(param_1,param_2,(ushort *)(puVar3 + 5));
      puVar3 = puVar1;
    }
    ExReleasePushLockExclusiveEx(&gBfsGlobalFileTable,0);
    KeLeaveCriticalRegion();
    ExReleasePushLockExclusiveEx(&DAT_140019198,0);
  }
  KeLeaveCriticalRegion();
  return 0;
}



===== BfsClearGlobalFileEntry @ 14000b920 =====

void BfsClearGlobalFileEntry(longlong param_1)

{
  longlong lVar1;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_18 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  if (*(longlong *)(param_1 + 0x48) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x48),0);
  }
  if (*(char *)(param_1 + 0x28) != '\0') {
    BfsRemoveFileEntryFromDeleteList(param_1);
  }
  if (*(longlong *)(param_1 + 0x58) != 0) {
    RtlInitEnumerationHashTable(*(longlong *)(param_1 + 0x58),&local_38);
    while( true ) {
      lVar1 = RtlEnumerateEntryHashTable(*(undefined8 *)(param_1 + 0x58),&local_38);
      if (lVar1 == 0) break;
      ExFreePoolWithTag(*(undefined8 *)(lVar1 + 0x18),0);
      ExFreePoolWithTag(*(undefined8 *)(lVar1 + 0x20),0);
      BfsRemoveEntryHashTable(*(undefined8 *)(param_1 + 0x58),lVar1);
      ExFreePoolWithTag(lVar1,0);
    }
    RtlEndEnumerationHashTable(*(undefined8 *)(param_1 + 0x58),&local_38);
    RtlDeleteHashTable(*(undefined8 *)(param_1 + 0x58));
    ExFreePoolWithTag(*(undefined8 *)(param_1 + 0x58),0);
    *(undefined8 *)(param_1 + 0x58) = 0;
  }
  return;
}



===== BfsCreateGlobalFileEntry @ 14000ba34 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 BfsCreateGlobalFileEntry(ushort *param_1,undefined4 param_2,longlong *param_3)

{
  longlong *plVar1;
  char cVar2;
  longlong lVar3;
  longlong lVar4;
  ulonglong uVar5;
  longlong lVar6;
  longlong lVar7;
  undefined8 uVar8;
  undefined1 auStack_98 [40];
  undefined1 *local_70;
  undefined4 local_68 [2];
  undefined1 local_60 [32];
  undefined4 *local_40;
  undefined8 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_98;
  lVar6 = 0x100;
  lVar3 = ExAllocatePool2(0x100,0x60,0x67736642);
  lVar7 = 0;
  if (lVar3 == 0) {
LAB_14000ba8e:
    uVar8 = 0xc0000017;
    if (3 < DAT_140019000) {
      local_68[0] = 0xc0000017;
LAB_14000bb6d:
      local_40 = local_68;
      local_38 = 4;
      local_70 = local_60;
      _tlgWriteTransfer_EtwWriteTransfer(lVar6,&DAT_140016d11);
    }
  }
  else {
    *(undefined4 *)(lVar3 + 0x50) = param_2;
    *(undefined1 *)(lVar3 + 0x28) = 0;
    *(undefined8 *)(lVar3 + 0x30) = 0;
    lVar6 = 0x100;
    lVar4 = ExAllocatePool2(0x100,(ulonglong)*param_1 + 2,0x4e736642);
    *(longlong *)(lVar3 + 0x48) = lVar4;
    if (lVar4 == 0) goto LAB_14000ba8e;
    *(ushort *)(lVar3 + 0x40) = *param_1;
    *(ushort *)(lVar3 + 0x42) = *param_1 + 2;
    RtlCopyUnicodeString((ushort *)(lVar3 + 0x40),param_1);
    lVar6 = 0x100;
    lVar4 = ExAllocatePool2(0x100,0x28,0x54736642);
    plVar1 = (longlong *)(lVar3 + 0x58);
    *plVar1 = lVar4;
    if (lVar4 == 0) goto LAB_14000ba8e;
    cVar2 = RtlCreateHashTable(plVar1,0,0);
    if (cVar2 != '\0') {
      uVar8 = 0;
      lVar7 = lVar3;
      goto LAB_14000bc42;
    }
    lVar6 = *plVar1;
    ExFreePoolWithTag(lVar6,0);
    *plVar1 = 0;
    uVar8 = 0xc0000001;
    if (3 < DAT_140019000) {
      local_68[0] = 0xc0000001;
      goto LAB_14000bb6d;
    }
  }
  uVar5 = Feature_138916153__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar5 == 0) {
    if (lVar3 != 0) {
      ExFreePoolWithTag(lVar3,0);
    }
    if (*(longlong *)(lVar3 + 0x48) != 0) {
      ExFreePoolWithTag(*(longlong *)(lVar3 + 0x48),0);
    }
    if (*(longlong *)(lVar3 + 0x58) == 0) goto LAB_14000bc42;
    RtlDeleteHashTable();
    lVar3 = *(longlong *)(lVar3 + 0x58);
  }
  else {
    if (lVar3 == 0) goto LAB_14000bc42;
    if (*(longlong *)(lVar3 + 0x48) != 0) {
      ExFreePoolWithTag(*(longlong *)(lVar3 + 0x48),0);
    }
    if (*(longlong *)(lVar3 + 0x58) != 0) {
      RtlDeleteHashTable();
      ExFreePoolWithTag(*(undefined8 *)(lVar3 + 0x58),0);
    }
  }
  ExFreePoolWithTag(lVar3,0);
LAB_14000bc42:
  *param_3 = lVar7;
  return uVar8;
}



===== BfsDeleteFileFromGlobalFileTable @ 14000bc74 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 BfsDeleteFileFromGlobalFileTable(longlong *param_1,undefined8 param_2,ushort *param_3)

{
  short sVar1;
  longlong lVar2;
  ulonglong uVar3;
  longlong lVar4;
  int iVar5;
  longlong lVar6;
  uint uVar7;
  uint uVar8;
  undefined1 auStackY_f8 [32];
  longlong local_c8;
  undefined8 local_c0;
  longlong lStack_b8;
  ushort local_b0 [4];
  longlong lStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  longlong *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_f8;
  local_80 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  local_90 = 0;
  uStack_88 = 0;
  local_c0 = 0;
  lStack_b8 = 0;
  local_b0[0] = 0;
  local_b0[1] = 0;
  local_b0[2] = 0;
  local_b0[3] = 0;
  lStack_a8 = 0;
  lVar2 = BfsGetGlobalFileEntry(0x140019190,param_3);
  iVar5 = 0;
  uVar3 = 0;
  uVar8 = (uint)(*(ushort *)(lVar2 + 0x40) >> 1);
  if (uVar8 != 0) {
    lVar4 = *(longlong *)(lVar2 + 0x48);
    do {
      if ((*(short *)(lVar4 + uVar3 * 2) == 0x5c) && (iVar5 = iVar5 + 1, iVar5 == 3))
      goto LAB_14000bd02;
      uVar7 = (int)uVar3 + 1;
      uVar3 = (ulonglong)uVar7;
    } while (uVar7 < uVar8);
    if (iVar5 == 3) {
LAB_14000bd02:
      sVar1 = (short)uVar3 * 2;
      uVar8 = (int)uVar3 + 1;
      local_b0[1] = sVar1;
      local_b0[0] = sVar1;
      lStack_b8 = *(longlong *)(lVar2 + 0x48) + (ulonglong)uVar8 * 2;
      sVar1 = *(short *)(lVar2 + 0x40) + (short)uVar8 * -2;
      local_c0._0_4_ = CONCAT22(sVar1,sVar1);
      lStack_a8 = lVar4;
      if (*(longlong *)(lVar2 + 0x58) != 0) {
        RtlInitEnumerationHashTable(*(longlong *)(lVar2 + 0x58),&local_a0);
        while (lVar4 = RtlEnumerateEntryHashTable(*(undefined8 *)(lVar2 + 0x58),&local_a0),
              lVar4 != 0) {
          local_c8 = 0;
          if (*(longlong *)(lVar4 + 0x28) <= *(longlong *)(lVar2 + 0x30)) {
            iVar5 = BfsGetPolicyEntry(param_1,param_2,(longlong *)&gBfsPolicyTable,
                                      *(byte **)(lVar4 + 0x18),*(byte **)(lVar4 + 0x20),&local_c8);
            lVar6 = local_c8;
            if (-1 < iVar5) {
              uVar3 = BfsDeleteEntry(*(longlong *)(local_c8 + 0x30),*(int *)(lVar2 + 0x50),local_b0,
                                     &local_c0);
              BfsDereferencePolicyEntryEx(lVar6,'\0');
              iVar5 = 0;
              if ((int)uVar3 != -0x3ffffddb) {
                iVar5 = (int)uVar3;
              }
              if (iVar5 < 0) {
                if (DAT_140019000 < 4) {
                  return 0;
                }
                local_4c = 0;
                local_c8 = CONCAT44(local_c8._4_4_,iVar5);
                local_58 = &local_c8;
                local_50 = 4;
                _tlgWriteTransfer_EtwWriteTransfer(lVar6,&DAT_140016d11);
                return 0;
              }
            }
            ExFreePoolWithTag(*(undefined8 *)(lVar4 + 0x18),0);
            ExFreePoolWithTag(*(undefined8 *)(lVar4 + 0x20),0);
            BfsRemoveEntryHashTable(*(undefined8 *)(lVar2 + 0x58),lVar4);
            ExFreePoolWithTag(lVar4,0);
          }
        }
        RtlEndEnumerationHashTable(*(undefined8 *)(lVar2 + 0x58),&local_a0);
      }
      BfsRemoveFileEntryFromDeleteList(lVar2);
      if (*(int *)(*(longlong *)(lVar2 + 0x58) + 0x14) == 0) {
        BfsRemoveEntryHashTable(DAT_1400191b8,lVar2);
        BfsClearGlobalFileEntry(lVar2);
        ExFreePoolWithTag(lVar2,0);
        return 0;
      }
      return 0;
    }
  }
  BfsRemoveFileEntryFromDeleteList(lVar2);
  return 0;
}



===== BfsFileContextCleanup @ 14000bef0 =====

void BfsFileContextCleanup(longlong param_1)

{
  if (*(longlong *)(param_1 + 8) != 0) {
    FltReleaseFileNameInformation();
    *(undefined8 *)(param_1 + 8) = 0;
  }
  return;
}



===== BfsGetGlobalFileEntry @ 14000bf20 =====

longlong BfsGetGlobalFileEntry(longlong param_1,ushort *param_2)

{
  undefined8 uVar1;
  char cVar2;
  undefined8 uVar3;
  longlong lVar4;
  longlong local_res8;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  uVar1 = *(undefined8 *)(param_1 + 0x28);
  local_res8 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  BfsUpdateUnicodeStringHash(param_2,&local_res8);
  uVar3 = BfsFinalHash(&local_res8);
  lVar4 = RtlLookupEntryHashTable(uVar1,uVar3,&local_28);
  while( true ) {
    if (lVar4 == 0) {
      return 0;
    }
    cVar2 = RtlEqualUnicodeString(param_2,lVar4 + 0x40,1);
    if (cVar2 != '\0') break;
    lVar4 = RtlGetNextEntryHashTable(uVar1,&local_28);
  }
  return lVar4;
}



===== BfsGetGlobalFilePolicy @ 14000bfcc =====

longlong BfsGetGlobalFilePolicy(longlong param_1,byte *param_2,byte *param_3)

{
  undefined8 uVar1;
  char cVar2;
  undefined8 uVar3;
  longlong lVar4;
  longlong local_res8;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  uVar1 = *(undefined8 *)(param_1 + 0x58);
  local_res8 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  BfsUpdateHash(param_2,(uint)param_2[1] * 4 + 8,&local_res8);
  BfsUpdateHash(param_3,(uint)param_3[1] * 4 + 8,&local_res8);
  uVar3 = BfsFinalHash(&local_res8);
  lVar4 = RtlLookupEntryHashTable(uVar1,uVar3,&local_28);
  while( true ) {
    if (lVar4 == 0) {
      return 0;
    }
    cVar2 = RtlEqualSid(param_2,*(undefined8 *)(lVar4 + 0x18));
    if ((cVar2 != '\0') &&
       (cVar2 = RtlEqualSid(param_3,*(undefined8 *)(lVar4 + 0x20)), cVar2 != '\0')) break;
    lVar4 = RtlGetNextEntryHashTable(uVar1,&local_28);
  }
  return lVar4;
}



===== BfsInitializeGlobalFileTable @ 14000c0bc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int BfsInitializeGlobalFileTable(undefined8 param_1,undefined8 param_2,longlong param_3)

{
  bool bVar1;
  undefined1 *puVar2;
  char cVar3;
  char cVar4;
  int iVar5;
  longlong lVar6;
  ulonglong uVar7;
  longlong lVar8;
  undefined8 uVar9;
  undefined1 *puVar10;
  longlong *plVar11;
  undefined1 *puVar12;
  undefined1 auStack_168 [32];
  undefined8 *local_148;
  undefined1 *local_140;
  undefined4 local_138;
  undefined4 local_130;
  undefined1 local_128;
  undefined8 *local_120;
  undefined1 local_118;
  undefined4 local_108;
  undefined4 local_104;
  int local_100 [2];
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined1 local_c8 [32];
  undefined4 *local_a8;
  undefined8 local_a0;
  undefined1 local_98 [32];
  undefined4 *local_78;
  undefined8 local_70;
  undefined1 local_68 [32];
  int *local_48;
  undefined8 local_40;
  ulonglong local_38;
  
  puVar2 = gBfsFilterHandle;
  local_38 = __security_cookie ^ (ulonglong)auStack_168;
  bVar1 = false;
  local_d8 = 0;
  uStack_d0 = 0;
  local_f8 = 0;
  uStack_f0 = 0;
  local_e8 = 0;
  uStack_e0 = 0;
  RtlInitUnicodeString(&local_f8,L"S-1-*");
  lVar6 = 0;
  LOCK();
  lVar8 = *(longlong *)(param_3 + 0x40);
  if (lVar8 == 0) {
    *(longlong *)(param_3 + 0x40) = -1;
  }
  else {
    lVar6 = lVar8;
  }
  UNLOCK();
  if (lVar6 == -1) {
    local_148 = (undefined8 *)0x0;
    KeWaitForSingleObject(param_3 + 0x10,0,0,0);
    if ((*(longlong *)(param_3 + 0x40) == 0) || (*(longlong *)(param_3 + 0x40) == -1)) {
      return -0x3fffffff;
    }
    return 0;
  }
  if (lVar6 != 0) {
    return 0;
  }
  iVar5 = 0;
  KeEnterCriticalRegion();
  cVar3 = ExAcquireRundownProtection(&gBfsRundownProtection);
  uVar7 = Feature_1199833401__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar7 == 0) {
    if (cVar3 == '\0') {
      KeLeaveCriticalRegion();
      goto LAB_14000c3e5;
    }
  }
  else {
    KeLeaveCriticalRegion();
    if (cVar3 == '\0') goto LAB_14000c3e5;
  }
  ExInitializePushLock(param_3);
  ExInitializePushLock(param_3 + 8);
  lVar8 = ExAllocatePool2(0x100,0x28,0x54736642);
  plVar11 = (longlong *)(param_3 + 0x28);
  *plVar11 = lVar8;
  if (lVar8 == 0) {
    iVar5 = -0x3fffffe9;
    if (3 < DAT_140019000) {
      local_a8 = &local_108;
      local_108 = 0xc0000017;
      local_140 = local_c8;
      local_a0 = 4;
LAB_14000c245:
      _tlgWriteTransfer_EtwWriteTransfer(plVar11,&DAT_140016d11);
    }
  }
  else {
    cVar4 = RtlCreateHashTable(plVar11,0,0);
    if (cVar4 == '\0') {
      iVar5 = -0x3fffffff;
      if (3 < DAT_140019000) {
        local_78 = &local_104;
        local_104 = 0xc0000001;
        local_140 = local_98;
        local_70 = 4;
        goto LAB_14000c245;
      }
    }
    else {
      lVar8 = param_3 + 0x30;
      bVar1 = true;
      *(longlong *)(param_3 + 0x38) = lVar8;
      *(longlong *)lVar8 = lVar8;
      uVar9 = BfsGetRootDirectory();
      puVar10 = (undefined1 *)ExAllocatePool2(0x100,0x186,0x4e736642);
      local_118 = 1;
      while( true ) {
        local_120 = &local_f8;
        local_128 = 0;
        local_130 = 0xc;
        local_148 = &local_d8;
        local_138 = 0x186;
        local_140 = puVar10;
        iVar5 = ZwQueryDirectoryFile(uVar9,0,0,0);
        if (iVar5 < 0) break;
        if (*(uint *)(puVar10 + 8) != 0) {
          puVar12 = puVar10 + 0xc;
          *(undefined2 *)(puVar10 + (ulonglong)(*(uint *)(puVar10 + 8) >> 1) * 2 + 0xc) = 0;
          RtlInitUnicodeString(&local_e8);
          iVar5 = BfsLoadUserPolicyEntriesToGlobalFileTable
                            (puVar2,puVar12,param_3,(longlong)&local_e8);
          if (iVar5 < 0) {
            if (3 < DAT_140019000) {
              local_48 = local_100;
              local_40 = 4;
              local_140 = local_68;
              local_100[0] = iVar5;
              _tlgWriteTransfer_EtwWriteTransfer(0,&DAT_140016d11);
            }
            goto LAB_14000c392;
          }
        }
        local_118 = 0;
      }
      if ((iVar5 == -0x7ffffffa) || (iVar5 == -0x3ffffff1)) {
        iVar5 = 0;
      }
      LOCK();
      *(undefined8 *)(param_3 + 0x40) = 1;
      UNLOCK();
LAB_14000c392:
      if (puVar10 != (undefined1 *)0x0) {
        ExFreePoolWithTag(puVar10,0);
      }
      if (-1 < iVar5) goto LAB_14000c3e5;
    }
  }
  if (*(longlong *)(param_3 + 0x28) != 0) {
    if (bVar1) {
      RtlDeleteHashTable();
    }
    ExFreePoolWithTag(*(undefined8 *)(param_3 + 0x28),0);
    *(undefined8 *)(param_3 + 0x28) = 0;
  }
  LOCK();
  *(undefined8 *)(param_3 + 0x40) = 0;
  UNLOCK();
LAB_14000c3e5:
  KeSetEvent(param_3 + 0x10,0,0);
  if (cVar3 != '\0') {
    uVar7 = Feature_1199833401__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar7 != 0) {
      KeEnterCriticalRegion();
    }
    ExReleaseRundownProtection(&gBfsRundownProtection);
    KeLeaveCriticalRegion();
  }
  return iVar5;
}



===== BfsLoadUserPolicyEntriesToGlobalFileTable @ 14000c4a8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int BfsLoadUserPolicyEntriesToGlobalFileTable
              (undefined1 *param_1,undefined8 param_2,longlong param_3,longlong param_4)

{
  byte ****ppppbVar1;
  byte ****ppppbVar2;
  byte ****ppppbVar3;
  code *pcVar4;
  int iVar5;
  longlong lVar6;
  ulonglong uVar7;
  undefined1 *puVar8;
  byte ****ppppbVar9;
  undefined1 *puVar10;
  undefined1 auStackY_1d8 [8];
  undefined1 auStackY_1d0 [24];
  int local_178 [2];
  byte ****local_170;
  byte ****local_168;
  longlong local_160;
  byte ****local_158;
  byte *local_150;
  undefined8 local_148;
  undefined8 uStack_140;
  undefined8 local_138;
  undefined8 uStack_130;
  undefined8 local_128;
  undefined8 uStack_120;
  undefined1 local_118 [48];
  longlong local_e8 [18];
  int *local_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_1d8;
  local_158 = (byte ****)0x0;
  local_128 = 0;
  uStack_120 = 0;
  local_138 = 0;
  uStack_130 = 0;
  local_148 = 0;
  uStack_140 = 0;
  memset(local_118,0,0x98);
  local_168 = (byte ****)&local_170;
  local_178[0] = 0;
  local_170 = (byte ****)&local_170;
  local_160 = 0;
  local_150 = (byte *)0x0;
  RtlInitUnicodeString(&local_138,L"S-1-*");
  SeConvertStringSidToSid(*(undefined8 *)(param_4 + 8));
  puVar8 = param_1;
  iVar5 = BfsOpenPolicyDirectory(param_1,0,param_4,'\x01',&local_160);
  if (iVar5 < 0) {
    if (DAT_140019000 < 4) goto LAB_14000c7a9;
    local_178[0] = iVar5;
  }
  else {
    puVar8 = (undefined1 *)0x100;
    lVar6 = ExAllocatePool2(0x100,0x186,0x4e736642);
    if (lVar6 != 0) {
LAB_14000c756:
      do {
        iVar5 = ZwQueryDirectoryFile(local_160,0,0,0);
        if (iVar5 < 0) goto code_r0x00014000c787;
        if (*(uint *)(lVar6 + 8) != 0) {
          *(undefined2 *)(lVar6 + 0xc + (ulonglong)(*(uint *)(lVar6 + 8) >> 1) * 2) = 0;
          RtlInitUnicodeString(&local_148,lVar6 + 0xc);
          SeConvertStringSidToSid(uStack_140);
          puVar8 = param_1;
          uVar7 = BfsCreateStorage((longlong)param_1,0,local_160,&local_148,local_e8);
          iVar5 = (int)uVar7;
          if (-1 < iVar5) {
            puVar8 = local_118;
            uVar7 = BfsEnumeratePolicy((longlong)puVar8,(longlong *)&local_170,(int *)0x0,local_178)
            ;
            iVar5 = (int)uVar7;
            if (-1 < iVar5) {
              while (ppppbVar9 = local_170, (byte *****)local_170 != &local_170) {
                if (((byte *****)local_170[1] != &local_170) ||
                   (ppppbVar3 = (byte ****)*local_170, (byte ****)ppppbVar3[1] != local_170))
                goto LAB_14000c872;
                ppppbVar3[1] = (byte ***)&local_170;
                ppppbVar1 = local_170 + 4;
                ppppbVar2 = local_170 + 2;
                local_170 = ppppbVar3;
                BfsAddPolicyToGlobalFileTable
                          (param_3,local_150,(byte *)local_158,(ushort *)ppppbVar1,
                           *(undefined4 *)ppppbVar2);
                RtlFreeUnicodeString(ppppbVar9 + 4);
                ExFreePoolWithTag(ppppbVar9);
              }
              BfsCloseStorage(local_e8[0]);
              local_e8[0] = 0;
              ExFreePoolWithTag(local_158);
              local_158 = (byte ****)0x0;
              goto LAB_14000c756;
            }
          }
          if (3 < DAT_140019000) {
            local_58 = local_178;
            local_50 = 4;
            local_178[0] = iVar5;
            _tlgWriteTransfer_EtwWriteTransfer(puVar8,&DAT_140016d11);
          }
          goto LAB_14000c798;
        }
      } while( true );
    }
    iVar5 = -0x3fffffe9;
    if (DAT_140019000 < 4) goto LAB_14000c7a9;
    local_178[0] = -0x3fffffe9;
  }
  iVar5 = local_178[0];
  local_58 = local_178;
  local_50 = 4;
  _tlgWriteTransfer_EtwWriteTransfer(puVar8,&DAT_140016d11);
  goto LAB_14000c7a9;
code_r0x00014000c787:
  if ((iVar5 == -0x7ffffffa) || (iVar5 == -0x3ffffff1)) {
    iVar5 = 0;
  }
LAB_14000c798:
  ExFreePoolWithTag(lVar6,0);
LAB_14000c7a9:
  puVar10 = auStackY_1d8;
  if (local_160 != 0) {
    ZwClose(local_160);
  }
  if (local_e8[0] != 0) {
    BfsCloseStorage(local_e8[0]);
  }
  if (local_150 != (byte *)0x0) {
    ExFreePoolWithTag(local_150,0);
  }
  ppppbVar9 = local_158;
  if (local_158 == (byte ****)0x0) goto LAB_14000c7fd;
  while( true ) {
    ExFreePoolWithTag(ppppbVar9,0);
LAB_14000c7fd:
    if ((byte *****)local_170 == &local_170) goto LAB_14000c879;
    if (((byte *****)local_170[1] != &local_170) ||
       (ppppbVar3 = (byte ****)*local_170, (byte ****)ppppbVar3[1] != local_170)) break;
    ppppbVar3[1] = (byte ***)&local_170;
    ppppbVar9 = local_170;
    local_170 = ppppbVar3;
  }
LAB_14000c872:
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  puVar10 = auStackY_1d0;
LAB_14000c879:
  *(undefined8 *)(puVar10 + -8) = 0x14000c88a;
  return iVar5;
}



===== BfsProcessDelete @ 14000c8b0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 BfsProcessDelete(ushort *param_1)

{
  longlong lVar1;
  code *pcVar2;
  ulonglong uVar3;
  longlong lVar4;
  longlong *plVar5;
  undefined8 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  uVar3 = Feature_Servicing_BfsGAFeature__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar3 == 0) {
    return 0;
  }
  KeEnterCriticalRegion();
  ExAcquirePushLockSharedEx(&gBfsGlobalFileTable,0);
  lVar4 = BfsGetGlobalFileEntry(0x140019190,param_1);
  if (lVar4 == 0) {
    ExReleasePushLockSharedEx(&gBfsGlobalFileTable,0);
    puVar8 = auStack_28;
    goto LAB_14000ca45;
  }
  ExReleasePushLockSharedEx();
  KeLeaveCriticalRegion();
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(&DAT_140019198,0);
  KeEnterCriticalRegion();
  ExAcquirePushLockSharedEx(&gBfsGlobalFileTable,0);
  lVar4 = BfsGetGlobalFileEntry(0x140019190,param_1);
  puVar7 = auStack_28;
  puVar8 = auStack_28;
  if (lVar4 != 0) {
    if (*(char *)(lVar4 + 0x28) == '\x01') {
      *(undefined1 *)(lVar4 + 0x28) = 0;
      plVar5 = (longlong *)(lVar4 + 0x18);
      lVar1 = *plVar5;
      if ((*(longlong **)(lVar1 + 8) == plVar5) &&
         (param_1 = *(ushort **)(lVar4 + 0x20), *(longlong **)param_1 == plVar5)) {
        *(longlong *)param_1 = lVar1;
        *(ushort **)(lVar1 + 8) = param_1;
        *plVar5 = 0;
        *(undefined8 *)(lVar4 + 0x20) = 0;
        *(undefined8 *)(lVar4 + 0x30) = 0;
        *(undefined8 *)(lVar4 + 0x38) = 0;
        goto LAB_14000c9b5;
      }
LAB_14000c9e9:
      puVar6 = (undefined8 *)0x3;
      pcVar2 = (code *)swi(0x29);
      DAT_1400191c8 = (undefined8 *)(*pcVar2)();
      puVar7 = auStack_20;
    }
    else {
LAB_14000c9b5:
      *(undefined1 *)(lVar4 + 0x28) = 1;
      param_1 = (ushort *)&DAT_1400191c0;
      *(undefined8 *)(lVar4 + 0x30) = DAT_1400191d0;
      *(undefined8 *)(lVar4 + 0x38) = _DAT_fffff78000000014;
      puVar6 = (undefined8 *)(lVar4 + 0x18);
      if ((undefined8 *)*DAT_1400191c8 != &DAT_1400191c0) goto LAB_14000c9e9;
    }
    *puVar6 = param_1;
    puVar6[1] = DAT_1400191c8;
    *DAT_1400191c8 = puVar6;
    puVar8 = puVar7;
    DAT_1400191c8 = puVar6;
  }
  *(undefined8 *)(puVar8 + -8) = 0x14000ca11;
  ExReleasePushLockSharedEx(&gBfsGlobalFileTable,0);
  *(undefined8 *)(puVar8 + -8) = 0x14000ca1d;
  KeLeaveCriticalRegion();
  *(undefined8 *)(puVar8 + -8) = 0x14000ca32;
  ExReleasePushLockExclusiveEx(&DAT_140019198,0);
LAB_14000ca45:
  *(undefined8 *)(puVar8 + -8) = 0x14000ca4c;
  KeLeaveCriticalRegion();
  return 0;
}



===== BfsReadDeleteThresholdFromRegistry @ 14000ca60 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int BfsReadDeleteThresholdFromRegistry(void)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  longlong lVar4;
  undefined8 ***pppuVar5;
  int iVar6;
  undefined1 auStack_e8 [32];
  undefined4 local_c8;
  undefined4 *local_c0;
  int local_b8;
  undefined4 local_b4;
  undefined8 ***local_b0;
  undefined8 local_a8;
  wchar_t *local_a0;
  undefined8 local_98;
  wchar_t *local_90;
  undefined8 local_88;
  wchar_t *local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 *local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined4 local_48 [8];
  int *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_e8;
  local_78 = 0x30;
  local_60 = 0x240;
  local_80 = L"\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control\\FileSystem";
  local_b0 = (undefined8 ***)0x0;
  local_a0 = L"MaximumTunnelEntries";
  pppuVar5 = &local_b0;
  local_b4 = 0;
  local_90 = L"MaximumTunnelEntryAgeInSeconds";
  local_68 = &local_88;
  local_88 = 0x7c007a;
  iVar6 = 150000000;
  local_a8 = 0x2a0028;
  local_98 = 0x3e003c;
  local_70 = 0;
  local_58 = 0;
  uStack_50 = 0;
  iVar2 = ZwOpenKey(pppuVar5,0x20019,&local_78);
  if (iVar2 < 0) {
LAB_14000cb1a:
    lVar4 = 0;
    if (DAT_140019000 < 4) goto LAB_14000ccc9;
    local_b8 = iVar2;
  }
  else {
    local_c0 = &local_b4;
    local_c8 = 0;
    pppuVar5 = local_b0;
    iVar2 = ZwQueryValueKey(local_b0,&local_a8,2);
    uVar1 = local_b4;
    if (iVar2 != -0x3fffffdd) goto LAB_14000cb1a;
    pppuVar5 = (undefined8 ***)0x100;
    lVar4 = ExAllocatePool2(0x100,local_b4,0x76526642);
    if (lVar4 != 0) {
      local_c0 = &local_b4;
      local_c8 = uVar1;
      iVar2 = ZwQueryValueKey(local_b0,&local_a8,2,lVar4);
      if (iVar2 < 0) {
        if (iVar2 != -0x3fffffcc) goto LAB_14000ccc9;
      }
      else {
        if (*(int *)(lVar4 + 4) != 4) goto LAB_14000ccc9;
        if (*(int *)(lVar4 + 0xc) == 0) {
          iVar6 = 0;
          goto LAB_14000ccc9;
        }
      }
      ExFreePoolWithTag(lVar4,0);
      local_c0 = &local_b4;
      local_c8 = 0;
      pppuVar5 = local_b0;
      iVar2 = ZwQueryValueKey(local_b0,&local_98,2);
      uVar1 = local_b4;
      if (iVar2 != -0x3fffffdd) goto LAB_14000cb1a;
      pppuVar5 = (undefined8 ***)0x100;
      lVar4 = ExAllocatePool2(0x100,local_b4,0x76526642);
      if (lVar4 != 0) {
        local_c0 = &local_b4;
        local_c8 = uVar1;
        iVar2 = ZwQueryValueKey(local_b0,&local_98,2,lVar4);
        if ((-1 < iVar2) && (*(int *)(lVar4 + 4) == 4)) {
          uVar3 = *(uint *)(lVar4 + 0xc);
          if (0x47 < uVar3) {
            uVar3 = 0x47;
          }
          iVar6 = uVar3 * 10000000;
        }
        goto LAB_14000ccc9;
      }
    }
    if (DAT_140019000 < 4) goto LAB_14000ccc9;
    local_b8 = -0x3fffffe9;
  }
  local_28 = &local_b8;
  local_20 = 4;
  local_c0 = local_48;
  _tlgWriteTransfer_EtwWriteTransfer(pppuVar5,&DAT_140016d11);
LAB_14000ccc9:
  if (local_b0 != (undefined8 ***)0x0) {
    ZwClose();
  }
  if (lVar4 != 0) {
    ExFreePoolWithTag(lVar4,0);
  }
  return iVar6;
}



===== BfsRemoveAllPoliciesFromGlobalFileTable @ 14000cd28 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong BfsRemoveAllPoliciesFromGlobalFileTable(longlong param_1,longlong param_2)

{
  undefined8 ****ppppuVar1;
  undefined8 ****ppppuVar2;
  code *pcVar3;
  ulonglong uVar4;
  longlong lVar5;
  ulonglong uVar6;
  undefined1 *puVar7;
  undefined8 ****ppppuVar8;
  undefined1 auStack_a8 [8];
  undefined1 auStack_a0 [32];
  undefined1 *local_80;
  int local_78 [2];
  undefined8 ****local_70;
  undefined8 ****local_68;
  int local_60 [2];
  undefined1 local_58 [32];
  int *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_a8;
  local_78[0] = 0;
  local_68 = &local_70;
  local_60[0] = 0;
  local_70 = &local_70;
  lVar5 = param_2;
  uVar4 = BfsEnumeratePolicy(param_2,(longlong *)&local_70,local_78,local_60);
  puVar7 = auStack_a8;
  uVar6 = uVar4 & 0xffffffff;
  if ((int)uVar4 < 0) {
    if (3 < DAT_140019000) {
      local_78[0] = (int)uVar4;
LAB_14000cdd8:
      local_2c = 0;
      local_38 = local_78;
      local_80 = local_58;
      local_30 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(lVar5,&DAT_140016d11);
    }
  }
  else {
    for (ppppuVar8 = local_70; (undefined8 *****)ppppuVar8 != &local_70;
        ppppuVar8 = (undefined8 ****)*ppppuVar8) {
      lVar5 = param_1;
      uVar4 = BfsRemovePolicyFromGlobalFileTable
                        (param_1,*(byte **)(param_2 + 0x18),*(byte **)(param_2 + 0x20),
                         (ushort *)(ppppuVar8 + 4));
      uVar6 = 0;
      if ((int)uVar4 != -0x3ffffddb) {
        uVar6 = uVar4 & 0xffffffff;
      }
      if ((int)uVar6 < 0) {
        if (3 < DAT_140019000) {
          local_78[0] = (int)uVar6;
          goto LAB_14000cdd8;
        }
        break;
      }
    }
  }
  do {
    ppppuVar8 = local_70;
    if ((undefined8 *****)local_70 == &local_70) {
LAB_14000ce56:
      *(undefined8 *)(puVar7 + -8) = 0x14000ce64;
      return uVar6;
    }
    if (((undefined8 *****)local_70[1] != &local_70) ||
       (ppppuVar2 = (undefined8 ****)*local_70, (undefined8 ****)ppppuVar2[1] != local_70)) {
      pcVar3 = (code *)swi(0x29);
      (*pcVar3)(3);
      puVar7 = auStack_a0;
      goto LAB_14000ce56;
    }
    ppppuVar2[1] = &local_70;
    ppppuVar1 = local_70 + 4;
    local_70 = ppppuVar2;
    RtlFreeUnicodeString(ppppuVar1);
    ExFreePoolWithTag(ppppuVar8,0);
  } while( true );
}



===== BfsRemoveFileEntryFromDeleteList @ 14000ce84 =====

void BfsRemoveFileEntryFromDeleteList(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  
  plVar1 = (longlong *)(param_1 + 0x18);
  *(undefined1 *)(param_1 + 0x28) = 0;
  lVar2 = *plVar1;
  if ((*(longlong **)(lVar2 + 8) == plVar1) &&
     (plVar3 = *(longlong **)(param_1 + 0x20), (longlong *)*plVar3 == plVar1)) {
    *plVar3 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar3;
    *plVar1 = 0;
    *(undefined8 *)(param_1 + 0x20) = 0;
    *(undefined8 *)(param_1 + 0x30) = 0;
    *(undefined8 *)(param_1 + 0x38) = 0;
    return;
  }
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  pcVar4 = (code *)swi(3);
  (*pcVar4)();
  return;
}



===== BfsRemovePolicyFromGlobalFileTable @ 14000cec8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
BfsRemovePolicyFromGlobalFileTable(longlong param_1,byte *param_2,byte *param_3,ushort *param_4)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined1 auStack_a8 [40];
  undefined1 *local_80;
  longlong local_78;
  undefined1 local_70 [32];
  longlong *local_50;
  undefined4 local_48;
  undefined4 local_44;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_a8;
  local_78 = 0;
  BfsUpdateUnicodeStringHash(param_4,&local_78);
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(param_1 + 8,0);
  lVar3 = param_1;
  lVar1 = BfsGetGlobalFileEntry(param_1,param_4);
  if (lVar1 != 0) {
    lVar3 = lVar1;
    lVar2 = BfsGetGlobalFilePolicy(lVar1,param_2,param_3);
    if (lVar2 != 0) {
      BfsRemoveEntryHashTable(*(undefined8 *)(lVar1 + 0x58),lVar2);
      ExFreePoolWithTag(*(undefined8 *)(lVar2 + 0x18),0);
      ExFreePoolWithTag(*(undefined8 *)(lVar2 + 0x20),0);
      ExFreePoolWithTag(lVar2,0);
      if (*(int *)(*(longlong *)(lVar1 + 0x58) + 0x14) == 0) {
        KeEnterCriticalRegion();
        ExAcquirePushLockExclusiveEx(param_1,0);
        lVar3 = BfsGetGlobalFileEntry(param_1,param_4);
        if (lVar3 != 0) {
          BfsRemoveEntryHashTable(*(undefined8 *)(param_1 + 0x28),lVar3);
          BfsClearGlobalFileEntry(lVar3);
          ExFreePoolWithTag(lVar3,0);
        }
        ExReleasePushLockExclusiveEx(param_1,0);
        KeLeaveCriticalRegion();
      }
      uVar4 = 0;
      goto LAB_14000d04f;
    }
  }
  uVar4 = 0xc0000225;
  if (3 < DAT_140019000) {
    local_44 = 0;
    local_78 = CONCAT44(local_78._4_4_,0xc0000225);
    local_50 = &local_78;
    local_80 = local_70;
    local_48 = 4;
    _tlgWriteTransfer_EtwWriteTransfer(lVar3,&DAT_140016d11);
  }
LAB_14000d04f:
  ExReleasePushLockExclusiveEx(param_1 + 8,0);
  KeLeaveCriticalRegion();
  return uVar4;
}



===== BfsUninitializeGlobalFileTable @ 14000d094 =====

void BfsUninitializeGlobalFileTable(void)

{
  longlong lVar1;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_18 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  if (DAT_1400191b8 != 0) {
    RtlInitEnumerationHashTable(DAT_1400191b8,&local_38);
    while( true ) {
      lVar1 = RtlEnumerateEntryHashTable(DAT_1400191b8,&local_38);
      if (lVar1 == 0) break;
      BfsClearGlobalFileEntry(lVar1);
      BfsRemoveEntryHashTable(DAT_1400191b8,lVar1);
      ExFreePoolWithTag(lVar1,0);
    }
    RtlEndEnumerationHashTable(DAT_1400191b8,&local_38);
    RtlDeleteHashTable(DAT_1400191b8);
    ExFreePoolWithTag(DAT_1400191b8,0);
  }
  LOCK();
  DAT_1400191d0 = 0;
  UNLOCK();
  return;
}



===== BfsUpdateGlobalFilePolicy @ 14000d178 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint BfsUpdateGlobalFilePolicy(longlong param_1,longlong param_2,byte *param_3,byte *param_4)

{
  uint uVar1;
  undefined8 uVar2;
  longlong lVar3;
  longlong lVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  undefined1 auStack_a8 [40];
  undefined1 *local_80;
  longlong local_78;
  undefined1 local_70 [32];
  longlong *local_50;
  undefined4 local_48;
  undefined4 local_44;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_a8;
  uVar7 = *(ulonglong *)(param_2 + 0x58);
  local_78 = 0;
  BfsUpdateHash(param_3,(uint)param_3[1] * 4 + 8,&local_78);
  BfsUpdateHash(param_4,(uint)param_4[1] * 4 + 8,&local_78);
  uVar2 = BfsFinalHash(&local_78);
  lVar3 = BfsGetGlobalFilePolicy(param_2,param_3,param_4);
  if (lVar3 != 0) {
LAB_14000d39d:
    if (*(longlong *)(param_1 + 0x40) != -1) {
      LOCK();
      *(longlong *)(param_1 + 0x40) = *(longlong *)(param_1 + 0x40) + 1;
      UNLOCK();
      *(undefined8 *)(lVar3 + 0x28) = *(undefined8 *)(param_1 + 0x40);
    }
    return 0;
  }
  uVar5 = 0x100;
  lVar3 = ExAllocatePool2(0x100,0x30,0x47736642);
  if (lVar3 == 0) {
    if (DAT_140019000 < 4) {
      return 0xc0000017;
    }
    local_44 = 0;
    local_78 = CONCAT44(local_78._4_4_,0xc0000017);
    local_50 = &local_78;
    local_80 = local_70;
    local_48 = 4;
    _tlgWriteTransfer_EtwWriteTransfer(uVar5,&DAT_140016d11);
    return 0xc0000017;
  }
  uVar6 = 0x100;
  lVar4 = ExAllocatePool2(0x100,(ulonglong)param_3[1] * 4 + 8,0x53736642);
  *(longlong *)(lVar3 + 0x18) = lVar4;
  if (lVar4 != 0) {
    uVar6 = (ulonglong)((uint)param_3[1] * 4 + 8);
    uVar1 = RtlCopySid(uVar6,lVar4,param_3);
    if ((int)uVar1 < 0) goto LAB_14000d328;
    uVar6 = 0x100;
    lVar4 = ExAllocatePool2(0x100,(ulonglong)param_4[1] * 4 + 8,0x53736642);
    *(longlong *)(lVar3 + 0x20) = lVar4;
    if (lVar4 != 0) {
      uVar6 = (ulonglong)((uint)param_4[1] * 4 + 8);
      uVar1 = RtlCopySid(uVar6,lVar4,param_4);
      if ((-1 < (int)uVar1) &&
         (uVar1 = BfsInsertEntryHashTable(uVar7,uVar2,lVar3), uVar6 = uVar7, -1 < (int)uVar1))
      goto LAB_14000d39d;
      goto LAB_14000d328;
    }
  }
  uVar1 = 0xc0000017;
LAB_14000d328:
  if (3 < DAT_140019000) {
    local_44 = 0;
    local_78 = CONCAT44(local_78._4_4_,uVar1);
    local_50 = &local_78;
    local_80 = local_70;
    local_48 = 4;
    _tlgWriteTransfer_EtwWriteTransfer(uVar6,&DAT_140016d11);
  }
  if (*(longlong *)(lVar3 + 0x18) != 0) {
    ExFreePoolWithTag(*(longlong *)(lVar3 + 0x18),0);
  }
  if (*(longlong *)(lVar3 + 0x20) != 0) {
    ExFreePoolWithTag(*(longlong *)(lVar3 + 0x20),0);
  }
  ExFreePoolWithTag(lVar3,0);
  return uVar1;
}



===== Feature_138916153__private_IsEnabledDeviceUsageNoInline @ 14000d3dc =====

ulonglong Feature_138916153__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_138916153__private_featureState;
  if ((Feature_138916153__private_featureState & 0x10) == 0) {
    uVar1 = Feature_138916153__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_138916153__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_138916153__private_IsEnabledFallback @ 14000d414 =====

void Feature_138916153__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_138916153__private_descriptor);
  return;
}



===== BfsPerformPrompt @ 14000d430 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong BfsPerformPrompt(longlong param_1,longlong param_2,longlong param_3)

{
  uint *puVar1;
  short sVar2;
  ushort uVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  int iVar10;
  bool bVar11;
  uint uVar12;
  undefined2 *puVar13;
  ulonglong uVar14;
  short sVar15;
  undefined8 *puVar16;
  undefined1 *puVar17;
  undefined8 *puVar18;
  longlong *plVar19;
  ulonglong uVar20;
  int iVar21;
  longlong lVar22;
  undefined1 auStackY_168 [32];
  longlong local_138;
  char local_130;
  char local_12f;
  undefined8 *local_128 [2];
  undefined8 local_118;
  longlong lStack_110;
  longlong local_108;
  undefined8 *local_100;
  undefined8 local_f8;
  longlong lStack_f0;
  longlong local_e8;
  undefined2 *local_e0;
  undefined8 local_d8;
  undefined1 *puStack_d0;
  undefined8 *local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  ulonglong local_a8;
  longlong lStack_a0;
  longlong *local_78;
  undefined4 local_70;
  undefined4 local_6c;
  ulonglong local_68;
  
  local_68 = __security_cookie ^ (ulonglong)auStackY_168;
  puVar18 = *(undefined8 **)(param_3 + 0x10);
  local_b8 = 0;
  local_100 = (undefined8 *)0x0;
  local_12f = '\0';
  lVar22 = 0;
  local_138 = 0;
  local_130 = '\0';
  iVar21 = 3;
  local_128[0] = (undefined8 *)0x0;
  local_108 = 0;
  local_c8 = (undefined8 *)0x0;
  uStack_c0 = 0;
  local_a8 = 0;
  lStack_a0 = 0;
  local_d8 = 0;
  puStack_d0 = (undefined1 *)0x0;
  if (puVar18 == (undefined8 *)0x0) {
    puVar18 = *(undefined8 **)(param_3 + 0x20);
  }
  puVar16 = puVar18;
  local_e8 = param_2;
  uVar12 = SeQueryInformationToken(puVar18,1,local_128);
  uVar20 = (ulonglong)uVar12;
  if ((int)uVar12 < 0) {
LAB_14000d4d6:
    if (DAT_140019000 < 4) goto LAB_14000d917;
    local_138 = CONCAT44(local_138._4_4_,uVar12);
  }
  else {
    puVar16 = puVar18;
    uVar12 = SeQueryInformationToken(puVar18,0x1f,&local_100);
    uVar20 = (ulonglong)uVar12;
    if ((int)uVar12 < 0) goto LAB_14000d4d6;
    puVar16 = &local_d8;
    uVar12 = RtlConvertSidToUnicodeString(puVar16,*local_128[0],1);
    uVar20 = (ulonglong)uVar12;
    if ((int)uVar12 < 0) goto LAB_14000d4d6;
    uStack_c0 = *(undefined8 *)(param_3 + 0x30);
    puVar16 = *(undefined8 **)(param_2 + 8);
    local_12f = '\x01';
    local_c8 = puVar18;
    uVar12 = BfsQueueDeferredWorkItemAndWait
                       ((longlong)puVar16,*(longlong *)(param_2 + 0x18),param_1,&local_c8,
                        BfsFileOpenAsUserCallback);
    uVar20 = (ulonglong)uVar12;
    if ((int)uVar12 < 0) goto LAB_14000d4d6;
    iVar10 = (int)local_b8;
    puVar16 = (undefined8 *)0x100;
    local_f8 = (ulonglong)*(ushort *)(*(longlong *)(param_3 + 0x30) + 0x18) + 2;
    puVar13 = (undefined2 *)ExAllocatePool2(0x100,local_f8,0x4e736642);
    local_e0 = puVar13;
    if (puVar13 != (undefined2 *)0x0) {
      RtlStringCbCopyUnicodeString
                (puVar13,local_f8,(ushort *)(*(longlong *)(param_3 + 0x30) + 0x18));
      lVar4 = *(longlong *)(param_3 + 0x30);
      uVar3 = *(ushort *)(lVar4 + 0x18);
      lStack_110 = *(longlong *)(lVar4 + 0x10) + (ulonglong)(uVar3 >> 1) * 2;
      local_118._0_4_ =
           CONCAT22((*(short *)(lVar4 + 10) - *(short *)(lVar4 + 0x48)) - uVar3,
                    (*(short *)(lVar4 + 8) - *(short *)(lVar4 + 0x48)) - uVar3);
      local_118 = (ulonglong)(uint)local_118;
      local_f8 = local_118;
      puVar17 = puStack_d0;
      lStack_f0 = lStack_110;
      uVar12 = BfsPromptForConsent(puStack_d0,puVar13,lStack_110,*(undefined8 *)(param_3 + 0x38),
                                   &local_130);
      uVar20 = (ulonglong)uVar12;
      if ((int)uVar12 < 0) {
        if (3 < DAT_140019000) {
          local_138 = CONCAT44(local_138._4_4_,uVar12);
LAB_14000d688:
          local_6c = 0;
          local_78 = &local_138;
          local_70 = 4;
          _tlgWriteTransfer_EtwWriteTransfer(puVar17,&DAT_140016d11);
        }
      }
      else if (local_130 == '\x01') {
        uVar12 = BfsGetUserToken((longlong)puVar18,&local_108);
        lVar22 = local_108;
        uVar20 = (ulonglong)uVar12;
        if ((int)uVar12 < 0) {
          if (3 < DAT_140019000) {
            local_6c = 0;
            local_138 = CONCAT44(local_138._4_4_,uVar12);
            local_78 = &local_138;
            local_70 = 4;
            _tlgWriteTransfer_EtwWriteTransfer(puVar18,&DAT_140016d11);
          }
          lVar22 = local_108;
        }
        else {
          lVar4 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x10) + 0x18) + 8);
          uVar6 = *(undefined8 *)(lVar4 + 0x20);
          uVar7 = *(undefined8 *)(lVar4 + 0x28);
          uVar8 = *(undefined8 *)(lVar4 + 0x30);
          uVar9 = *(undefined8 *)(lVar4 + 0x38);
          *(longlong *)(lVar4 + 0x20) = local_108;
          *(undefined4 *)
           (*(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x10) + 0x18) + 8) + 0x28) = 2;
          FltReissueSynchronousIo(*(undefined8 *)(local_e8 + 0x18),param_1);
          puVar1 = (uint *)(*(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x10) + 0x18) + 8) +
                           0x14);
          *puVar1 = *puVar1 & 0xfff3ffff;
          FltSetCallbackDataDirty(param_1);
          puVar17 = *(undefined1 **)(*(longlong *)(param_1 + 0x10) + 0x18);
          lVar4 = *(longlong *)(puVar17 + 8);
          *(undefined8 *)(lVar4 + 0x20) = uVar6;
          *(undefined8 *)(lVar4 + 0x28) = uVar7;
          *(undefined8 *)(lVar4 + 0x30) = uVar8;
          *(undefined8 *)(lVar4 + 0x38) = uVar9;
          uVar12 = *(uint *)(param_1 + 0x18);
          uVar20 = (ulonglong)uVar12;
          if (-1 < (int)uVar12) {
            bVar11 = BfsQueryAccessOnly(iVar10,param_1);
            iVar21 = bVar11 + 1;
            goto LAB_14000d7c5;
          }
          if (3 < DAT_140019000) {
            local_138 = CONCAT44(local_138._4_4_,uVar12);
            goto LAB_14000d688;
          }
        }
      }
      else {
LAB_14000d7c5:
        plVar19 = gBfsFilterHandle;
        uVar12 = BfsGetPolicyEntry(gBfsFilterHandle,0,(longlong *)&gBfsPolicyTable,
                                   (byte *)*local_128[0],(byte *)*local_100,&local_138);
        lVar4 = local_138;
        uVar20 = (ulonglong)uVar12;
        if ((int)uVar12 < 0) {
LAB_14000d8c0:
          if (3 < DAT_140019000) {
            local_6c = 0;
            local_138 = CONCAT44(local_138._4_4_,uVar12);
            local_78 = &local_138;
            local_70 = 4;
            _tlgWriteTransfer_EtwWriteTransfer(plVar19,&DAT_140016d11);
          }
        }
        else {
          lStack_f0 = lStack_110 + 2;
          plVar19 = *(longlong **)(local_138 + 0x30);
          sVar15 = (short)local_f8 + -2;
          sVar2 = local_f8._2_2_ + -2;
          local_f8._0_4_ = CONCAT22(sVar2,sVar15);
          uVar20 = BfsAddOrModifyEntry((longlong)plVar19,iVar10,iVar21,0,
                                       (ushort *)(*(longlong *)(param_3 + 0x30) + 0x18),
                                       (short *)&local_f8);
          uVar12 = (uint)uVar20;
          uVar20 = uVar20 & 0xffffffff;
          if ((int)uVar12 < 0) goto LAB_14000d8c0;
          uVar14 = Feature_Servicing_BfsGAFeature__private_IsEnabledDeviceUsageNoInline();
          if ((int)uVar14 != 0) {
            lVar5 = *(longlong *)(param_3 + 0x30);
            lStack_110 = *(longlong *)(lVar5 + 0x10);
            sVar15 = *(short *)(lVar5 + 8) - *(short *)(lVar5 + 0x48);
            local_118._0_4_ = CONCAT22(sVar15,sVar15);
            local_118 = (ulonglong)(uint)local_118;
            plVar19 = (longlong *)&gBfsGlobalFileTable;
            local_a8 = local_118;
            lStack_a0 = lStack_110;
            uVar20 = BfsAddPolicyToGlobalFileTable
                               (0x140019190,(byte *)*local_128[0],(byte *)*local_100,
                                (ushort *)&local_a8,iVar10);
            uVar12 = (uint)uVar20;
            uVar20 = uVar20 & 0xffffffff;
            if ((int)uVar12 < 0) goto LAB_14000d8c0;
          }
        }
        if (lVar4 != 0) {
          BfsDereferencePolicyEntryEx(lVar4,'\0');
        }
      }
      ExFreePoolWithTag(local_e0,0);
      goto LAB_14000d917;
    }
    uVar20 = 0xc0000017;
    if (DAT_140019000 < 4) goto LAB_14000d917;
    local_138 = CONCAT44(local_138._4_4_,0xc0000017);
  }
  local_6c = 0;
  local_78 = &local_138;
  local_70 = 4;
  _tlgWriteTransfer_EtwWriteTransfer(puVar16,&DAT_140016d11);
LAB_14000d917:
  if (local_128[0] != (undefined8 *)0x0) {
    ExFreePoolWithTag(local_128[0],0);
  }
  if (local_100 != (undefined8 *)0x0) {
    ExFreePoolWithTag(local_100,0);
  }
  if (local_12f != '\0') {
    RtlFreeUnicodeString(&local_d8);
  }
  if (lVar22 != 0) {
    ObfDereferenceObject(lVar22);
  }
  return uVar20;
}



===== RtlStringCbCopyUnicodeString @ 14000d9ac =====

uint RtlStringCbCopyUnicodeString(undefined2 *param_1,ulonglong param_2,ushort *param_3)

{
  ushort uVar1;
  ushort uVar2;
  undefined2 *puVar3;
  ulonglong uVar4;
  longlong lVar5;
  longlong lVar6;
  
  uVar4 = param_2 >> 1;
  if (uVar4 - 1 < 0x7fff) {
    uVar1 = *param_3;
    if ((((((uVar1 & 1) == 0) && (uVar2 = param_3[1], (uVar2 & 1) == 0)) && (uVar1 <= uVar2)) &&
        (uVar2 != 0xffff)) && ((*(longlong *)(param_3 + 4) != 0 || ((uVar1 == 0 && (uVar2 == 0))))))
    {
      lVar5 = (uVar1 >> 1) - uVar4;
      lVar6 = *(longlong *)(param_3 + 4) - (longlong)param_1;
      do {
        if (lVar5 + uVar4 == 0) break;
        *param_1 = *(undefined2 *)(lVar6 + (longlong)param_1);
        param_1 = param_1 + 1;
        uVar4 = uVar4 - 1;
      } while (uVar4 != 0);
      puVar3 = param_1 + -1;
      if (uVar4 != 0) {
        puVar3 = param_1;
      }
      *puVar3 = 0;
      return ~-(uint)(uVar4 != 0) & 0x80000005;
    }
    *param_1 = 0;
  }
  return 0xc000000d;
}



===== BfsAccessRegistryKeyAsUserCallback @ 14000da60 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Type propagation algorithm not settling */

uint BfsAccessRegistryKeyAsUserCallback(longlong *param_1)

{
  bool bVar1;
  bool bVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  char cVar6;
  longlong lVar7;
  ulonglong uVar8;
  undefined8 *******pppppppuVar9;
  undefined1 auStack_138 [32];
  longlong *local_118;
  undefined1 *local_110;
  undefined4 *local_108;
  undefined1 local_100;
  longlong *local_f8;
  uint *local_f0;
  uint local_e8;
  uint local_e4;
  undefined4 local_e0 [2];
  undefined8 *******local_d8;
  undefined4 local_d0 [2];
  longlong local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 ******local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  ulonglong uStack_68;
  undefined1 local_60 [32];
  uint *local_40;
  undefined8 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_138;
  local_d0[0] = 0;
  pppppppuVar9 = (undefined8 *******)param_1[1];
  local_e0[0] = 0;
  lVar7 = 0;
  local_c8 = 0;
  uStack_c0 = 0;
  local_b8 = 0;
  local_d8 = (undefined8 *******)0x0;
  local_90 = 0;
  uStack_88 = 0;
  local_70 = 0;
  local_80 = 0;
  uStack_78 = 0;
  uStack_68 = uStack_68 & 0xffffffff00000000;
  local_b0 = (undefined8 ******)0x0;
  uStack_a8 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  local_e4 = BfsImpersonateUser(pppppppuVar9,&local_c8);
  uVar4 = local_e8;
  uVar5 = local_e4;
  bVar2 = false;
  if (-1 < (int)local_e4) {
    local_90 = CONCAT44(local_90._4_4_,0x30);
    bVar2 = true;
    bVar1 = true;
    uStack_88 = 0;
    uStack_78 = CONCAT44(uStack_78._4_4_,0x600);
    local_80 = *(undefined8 *)*param_1;
    local_70 = 0;
    uStack_68 = 0;
    if ((int)param_1[4] == 0x1c) {
      pppppppuVar9 = &local_d8;
      local_e4 = ZwOpenKey(pppppppuVar9,0x20000,&local_90);
LAB_14000db33:
      uVar4 = local_e8;
      uVar5 = local_e4;
      if ((int)local_e4 < 0) goto joined_r0x00014000dd4f;
    }
    else if ((int)param_1[4] == 0x1a) {
      local_108 = local_d0;
      local_110 = (undefined1 *)
                  CONCAT44(local_110._4_4_,*(undefined4 *)((undefined8 *)*param_1 + 3));
      pppppppuVar9 = &local_d8;
      local_118 = (longlong *)0x0;
      local_e4 = ZwCreateKey(pppppppuVar9,0x20000,&local_90,0);
      goto LAB_14000db33;
    }
    local_118 = (longlong *)local_e0;
    local_e4 = ZwQuerySecurityObject(local_d8,0xf,0);
    uVar3 = local_e0[0];
    uVar4 = local_e8;
    if (local_e4 != 0xc0000023) goto LAB_14000ddc1;
    pppppppuVar9 = (undefined8 *******)0x100;
    lVar7 = ExAllocatePool2(0x100,local_e0[0],0x44736642);
    if (lVar7 == 0) {
      local_e4 = 0xc0000017;
      uVar4 = local_e8;
      uVar5 = local_e4;
    }
    else {
      local_118 = (longlong *)local_e0;
      pppppppuVar9 = local_d8;
      local_e4 = ZwQuerySecurityObject(local_d8,0xf,lVar7,uVar3);
      uVar4 = local_e8;
      uVar5 = local_e4;
      if (-1 < (int)local_e4) {
        SeCaptureSubjectContext(&local_b0);
        local_f0 = &local_e4;
        local_100 = 1;
        local_108 = (undefined4 *)&BfsKeyMapping;
        local_110 = (undefined1 *)0x0;
        local_118 = (longlong *)((ulonglong)local_118 & 0xffffffff00000000);
        local_f8 = (longlong *)((longlong)param_1 + 0x1c);
        cVar6 = SeAccessCheck(lVar7,&local_b0,0,0x2000000);
        pppppppuVar9 = &local_b0;
        SeReleaseSubjectContext();
        uVar4 = local_e8;
        if (cVar6 == '\0') goto LAB_14000ddc1;
        uVar5 = local_e4;
        if (-1 < (int)local_e4) {
          BfsRevertTokenImpersonation(&local_c8);
          pppppppuVar9 = (undefined8 *******)param_1[1];
          local_e4 = BfsImpersonateToken(pppppppuVar9,&local_c8);
          uVar4 = local_e8;
          uVar5 = local_e4;
          bVar2 = false;
          if (-1 < (int)local_e4) {
            bVar1 = true;
            SeCaptureSubjectContext(&local_b0);
            local_f0 = &local_e4;
            local_f8 = param_1 + 3;
            local_100 = 1;
            local_108 = (undefined4 *)&BfsKeyMapping;
            local_110 = (undefined1 *)0x0;
            local_118 = (longlong *)((ulonglong)local_118 & 0xffffffff00000000);
            cVar6 = SeAccessCheck(lVar7,&local_b0,0,0x2000000);
            SeReleaseSubjectContext(&local_b0);
            if (((cVar6 != '\0') ||
                (pppppppuVar9 = (undefined8 *******)(ulonglong)local_e4,
                (local_e4 + 0x80000000 & 0x80000000) != 0)) ||
               (uVar4 = local_e8, uVar5 = local_e4, bVar2 = bVar1, local_e4 == 0xc0000022)) {
              local_118 = param_1 + 2;
              local_110 = (undefined1 *)0x0;
              pppppppuVar9 = local_d8;
              local_e4 = ObReferenceObjectByHandle
                                   (local_d8,*(undefined4 *)((longlong)param_1 + 0x1c),
                                    *(undefined8 *)CmKeyObjectType_exref,0);
              uVar4 = local_e8;
              uVar5 = local_e4;
              bVar2 = true;
              if (-1 < (int)local_e4) goto LAB_14000ddc1;
            }
          }
        }
      }
    }
  }
joined_r0x00014000dd4f:
  bVar1 = bVar2;
  local_e8 = uVar5;
  local_e4 = local_e8;
  if (3 < DAT_140019000) {
    local_40 = &local_e8;
    local_38 = 4;
    local_110 = local_60;
    _tlgWriteTransfer_EtwWriteTransfer(pppppppuVar9,&DAT_140016d11);
    uVar4 = local_e8;
  }
LAB_14000ddc1:
  local_e8 = uVar4;
  uVar8 = Feature_Servicing_BfsGAFeature__private_IsEnabledDeviceUsageNoInline();
  if (((int)uVar8 != 0) && (lVar7 != 0)) {
    ExFreePoolWithTag(lVar7,0);
  }
  if (bVar1) {
    BfsRevertTokenImpersonation(&local_c8);
  }
  if (local_d8 != (undefined8 *******)0x0) {
    ZwClose();
  }
  return local_e4;
}



===== BfsAdjustRegistryKeySecurity @ 14000de38 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint BfsAdjustRegistryKeySecurity(undefined8 *param_1,longlong param_2,uint param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  undefined1 auStackY_c8 [32];
  uint local_88;
  char local_84;
  char local_83;
  undefined1 local_82;
  undefined4 local_80;
  undefined8 *local_78;
  uint *local_50;
  undefined8 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_c8;
  local_78 = (undefined8 *)0x0;
  local_82 = 0;
  local_84 = '\0';
  local_80 = 0;
  local_83 = '\0';
  puVar6 = param_1;
  uVar3 = ZwQuerySecurityObject(param_1,4,0,0);
  uVar2 = local_80;
  if (uVar3 != 0xc0000023) {
LAB_14000deab:
    if (3 < DAT_140019000) {
      local_50 = &local_88;
      local_48 = 4;
      local_88 = uVar3;
      _tlgWriteTransfer_EtwWriteTransfer(puVar6,&DAT_140016d11);
    }
    return uVar3;
  }
  puVar6 = (undefined8 *)0x100;
  puVar4 = (undefined8 *)ExAllocatePool2(0x100,local_80,0x44736642);
  if (puVar4 == (undefined8 *)0x0) {
    uVar3 = 0xc0000017;
    goto LAB_14000deab;
  }
  puVar6 = param_1;
  uVar3 = ZwQuerySecurityObject(param_1,4,puVar4,uVar2);
  if ((-1 < (int)uVar3) &&
     (puVar6 = puVar4, uVar3 = RtlGetDaclSecurityDescriptor(), -1 < (int)uVar3)) {
    if (local_84 == '\0') goto LAB_14000e0c4;
    puVar6 = local_78;
    uVar3 = BfsVerifyAce((longlong)local_78,'\0','\0',param_3,param_2,&local_83);
    if (-1 < (int)uVar3) {
      if (local_83 != '\0') goto LAB_14000e0c4;
      iVar1 = *(ushort *)((longlong)local_78 + 2) + 0x10 + (uint)*(byte *)(param_2 + 1) * 4;
      puVar6 = (undefined8 *)0x100;
      puVar5 = (undefined8 *)ExAllocatePool2(0x100,iVar1,0x41736642);
      if (puVar5 != (undefined8 *)0x0) {
        puVar6 = param_1;
        uVar3 = BfsUpdateSecurityDescriptor(param_1,local_78,puVar5,iVar1,param_2,param_3,'\0');
        if (((((int)uVar3 < 0) ||
             (puVar6 = param_1, uVar3 = BfsRemoveKeyValues(param_1), (int)uVar3 < 0)) ||
            (uVar3 = BfsUpdateSecurityDescriptor
                               (param_1,local_78,puVar5,iVar1,param_2,param_3,'\x01'),
            puVar6 = param_1, (int)uVar3 < 0)) && (3 < DAT_140019000)) {
          local_50 = &local_88;
          local_48 = 4;
          local_88 = uVar3;
          _tlgWriteTransfer_EtwWriteTransfer(puVar6,&DAT_140016d11);
        }
        ExFreePoolWithTag(puVar5,0);
        goto LAB_14000e0c4;
      }
      uVar3 = 0xc0000017;
    }
  }
  if (3 < DAT_140019000) {
    local_48 = 4;
    local_50 = &local_88;
    local_88 = uVar3;
    _tlgWriteTransfer_EtwWriteTransfer(puVar6,&DAT_140016d11);
  }
LAB_14000e0c4:
  ExFreePoolWithTag(puVar4,0);
  return uVar3;
}



===== BfsCalculateRegistryPrefix @ 14000e108 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int BfsCalculateRegistryPrefix(ushort *param_1,ushort *param_2,PUCHAR param_3,PUCHAR param_4)

{
  short sVar1;
  NTSTATUS NVar2;
  PUCHAR pbOutput;
  longlong lVar3;
  BCRYPT_ALG_HANDLE hAlgorithm;
  BCRYPT_ALG_HANDLE pvVar4;
  PUCHAR pUVar5;
  PUCHAR pUVar6;
  uint uVar7;
  undefined1 auStackY_108 [32];
  NTSTATUS local_c8;
  ULONG local_c4;
  PUCHAR local_c0;
  ULONG local_b8 [2];
  undefined8 local_b0;
  longlong lStack_a8;
  undefined8 local_a0;
  longlong lStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  NTSTATUS *local_60;
  undefined8 local_58;
  ulonglong local_50;
  
  hAlgorithm = gBfsSHA256Handle;
  local_50 = __security_cookie ^ (ulonglong)auStackY_108;
  local_c0 = (PUCHAR)0x0;
  local_c4 = 0;
  local_b8[0] = 0;
  local_90 = 0;
  uStack_88 = 0;
  local_b0 = 0;
  lStack_a8 = 0;
  local_a0 = 0;
  lStack_98 = 0;
  RtlInitUnicodeString(&local_90,L"\\Registry\\WC\\Silo");
  pvVar4 = hAlgorithm;
  NVar2 = BCryptCreateHash(hAlgorithm,&local_c0,(PUCHAR)0x0,0,(PUCHAR)0x0,0,0);
  if (-1 < NVar2) {
    NVar2 = BCryptGetProperty(hAlgorithm,L"HashDigestLength",(PUCHAR)&local_c4,4,local_b8,0);
    pvVar4 = hAlgorithm;
    if (-1 < NVar2) {
      pvVar4 = (BCRYPT_ALG_HANDLE)0x100;
      pbOutput = (PUCHAR)ExAllocatePool2(0x100,local_c4,0x64736642);
      if (pbOutput != (PUCHAR)0x0) {
        pUVar5 = local_c0;
        NVar2 = BCryptHashData(local_c0,*(PUCHAR *)(param_2 + 4),(uint)*param_2,0);
        if (NVar2 < 0) {
LAB_14000e276:
          if (3 < DAT_140019000) {
            local_60 = &local_c8;
            local_58 = 4;
            local_c8 = NVar2;
            _tlgWriteTransfer_EtwWriteTransfer(pUVar5,&DAT_140016d11);
          }
        }
        else {
          pUVar5 = local_c0;
          NVar2 = BCryptHashData(local_c0,*(PUCHAR *)(param_1 + 4),(uint)*param_1,0);
          if (NVar2 < 0) goto LAB_14000e276;
          pUVar5 = local_c0;
          NVar2 = BCryptFinishHash(local_c0,pbOutput,local_c4,0);
          if (NVar2 < 0) goto LAB_14000e276;
          for (uVar7 = 0; NVar2 = 0, uVar7 < 2; uVar7 = uVar7 + 1) {
            pUVar5 = param_3;
            if (uVar7 != 0) {
              pUVar5 = param_4;
            }
            pUVar6 = pbOutput + (ulonglong)uVar7 * 0x10;
            NVar2 = RtlStringFromGUID(pUVar6,&local_b0);
            if (NVar2 < 0) {
LAB_14000e3f4:
              pUVar5 = pUVar6;
              goto LAB_14000e276;
            }
            lStack_98 = lStack_a8 + 2;
            local_a0._0_4_ = CONCAT22(local_b0._2_2_ + -4,(short)local_b0 + -4);
            sVar1 = (short)local_b0 + -4;
            if (*(longlong *)(pUVar5 + 8) != 0) {
              ExFreePoolWithTag(*(longlong *)(pUVar5 + 8),0);
              sVar1 = (short)local_a0;
            }
            sVar1 = (short)local_90 + 2 + sVar1;
            pUVar6 = (PUCHAR)0x100;
            *(short *)(pUVar5 + 2) = sVar1;
            lVar3 = ExAllocatePool2(0x100,sVar1,0x4e736642);
            *(longlong *)(pUVar5 + 8) = lVar3;
            if (lVar3 == 0) {
              NVar2 = -0x3fffffe9;
              goto LAB_14000e3f4;
            }
            pUVar5[0] = '\0';
            pUVar5[1] = '\0';
            RtlCopyUnicodeString(pUVar5,&local_90);
            NVar2 = RtlAppendUnicodeStringToString(pUVar5,&local_a0);
            if (NVar2 < 0) goto LAB_14000e276;
            RtlFreeUnicodeString(&local_b0);
          }
        }
        ExFreePoolWithTag(pbOutput,0x64736642);
        goto LAB_14000e415;
      }
      NVar2 = -0x3fffffe9;
    }
  }
  if (3 < DAT_140019000) {
    local_58 = 4;
    local_60 = &local_c8;
    local_c8 = NVar2;
    _tlgWriteTransfer_EtwWriteTransfer(pvVar4,&DAT_140016d11);
  }
LAB_14000e415:
  if (local_c0 != (PUCHAR)0x0) {
    BCryptDestroyHash(local_c0);
  }
  if (lStack_a8 != 0) {
    RtlFreeUnicodeString(&local_b0);
  }
  if (NVar2 < 0) {
    RtlFreeUnicodeString(param_3);
    RtlFreeUnicodeString(param_4);
  }
  return NVar2;
}



===== BfsGetRegistryPrefix @ 14000e48c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong BfsGetRegistryPrefix
                    (ushort *param_1,undefined8 *param_2,undefined8 *param_3,int *param_4,
                    longlong *param_5)

{
  short *psVar1;
  uint uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  ushort *puVar5;
  char cVar6;
  undefined8 uVar7;
  longlong lVar8;
  undefined1 auStackY_218 [32];
  undefined8 *local_1d8;
  longlong local_1d0;
  undefined8 *local_1c8;
  undefined8 *local_1c0;
  undefined8 local_1b8;
  ushort local_1b0 [8];
  undefined8 local_1a0;
  undefined8 uStack_198;
  undefined8 **local_170;
  undefined8 local_168;
  undefined1 local_158 [256];
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStackY_218;
  local_1c0 = (undefined8 *)0x0;
  local_1a0 = 0;
  uStack_198 = 0;
  local_1d8 = param_3;
  memset(local_158,0,0x100);
  local_1b8 = 0x100;
  local_1d0 = 0;
  local_1c8 = (undefined8 *)0x0;
  *param_5 = 0;
  local_1b0[0] = 0;
  local_1b0[1] = 0;
  local_1b0[2] = 0;
  local_1b0[3] = 0;
  local_1b0[4] = 0;
  local_1b0[5] = 0;
  local_1b0[6] = 0;
  local_1b0[7] = 0;
  lVar8 = 0;
  puVar5 = param_1;
  uVar2 = SeQueryInformationToken(param_1,1,&local_1c8);
  uVar3 = (ulonglong)uVar2;
  if ((int)uVar2 < 0) {
LAB_14000e52a:
    param_1 = puVar5;
    if (DAT_140019000 < 4) goto LAB_14000e75f;
    local_1d8 = (undefined8 *)CONCAT44(local_1d8._4_4_,uVar2);
  }
  else {
    uVar7 = 0x1f;
    puVar5 = param_1;
    uVar2 = SeQueryInformationToken(param_1,0x1f,&local_1c0);
    uVar3 = (ulonglong)uVar2;
    if ((int)uVar2 < 0) goto LAB_14000e52a;
    puVar5 = gBfsFilterHandle;
    uVar3 = BfsPolicyEntryExistsLocked
                      (gBfsFilterHandle,uVar7,0x140019260,(byte *)*local_1c8,(byte *)*local_1c0,
                       *param_4);
    uVar2 = (uint)uVar3;
    uVar3 = uVar3 & 0xffffffff;
    if (uVar2 == 0) {
      puVar5 = gBfsFilterHandle;
      uVar4 = BfsGetPolicyEntryLocked
                        ((undefined8 *)gBfsFilterHandle,uVar7,0x140019260,(byte *)*local_1c8,
                         (byte *)*local_1c0,param_4,&local_1d0);
LAB_14000e5f1:
      uVar3 = uVar4 & 0xffffffff;
      if ((int)uVar4 < 0) {
        if (3 < DAT_140019000) {
          local_1d8 = (undefined8 *)CONCAT44(local_1d8._4_4_,(int)uVar4);
          local_170 = &local_1d8;
          local_168 = 4;
          _tlgWriteTransfer_EtwWriteTransfer(puVar5,&DAT_140016d11);
        }
        lVar8 = local_1d0;
        goto LAB_14000e75f;
      }
      lVar8 = local_1d0;
    }
    else {
      if (uVar2 == 0xc0000225) {
        puVar5 = (ushort *)&gBfsPolicyTable;
        uVar4 = BfsGetNotPresentPolicyEntryLocked
                          (0x140019260,(byte *)*local_1c8,(byte *)*local_1c0,&local_1d0);
        goto LAB_14000e5f1;
      }
      if ((int)uVar2 < 0) goto LAB_14000e52a;
    }
    psVar1 = (short *)(lVar8 + 0x70);
    if ((*psVar1 != 0) && (*(short *)(lVar8 + 0x80) != 0)) {
LAB_14000e73a:
      uVar7 = *(undefined8 *)(lVar8 + 0x78);
      *param_2 = *(undefined8 *)psVar1;
      param_2[1] = uVar7;
      uVar7 = *(undefined8 *)(lVar8 + 0x88);
      *local_1d8 = *(undefined8 *)(lVar8 + 0x80);
      local_1d8[1] = uVar7;
      *param_5 = lVar8;
      lVar8 = 0;
      goto LAB_14000e75f;
    }
    if (*param_4 == 2) {
      puVar5 = local_1b0;
      uVar2 = RtlConvertSidToUnicodeString(puVar5,*local_1c8,1);
      uVar3 = (ulonglong)uVar2;
      if ((int)uVar2 < 0) goto LAB_14000e690;
      uVar2 = RtlQueryPackageIdentity(param_1,local_158,&local_1b8,0);
      uVar3 = (ulonglong)uVar2;
      if (-1 < (int)uVar2) {
        RtlInitUnicodeString(&local_1a0,local_158);
        param_1 = local_1b0;
        uVar2 = BfsCalculateRegistryPrefix
                          (param_1,(ushort *)&local_1a0,(PUCHAR)psVar1,(PUCHAR)(lVar8 + 0x80));
        uVar3 = (ulonglong)uVar2;
        if (-1 < (int)uVar2) goto LAB_14000e73a;
      }
      if (DAT_140019000 < 4) goto LAB_14000e75f;
      local_1d8 = (undefined8 *)CONCAT44(local_1d8._4_4_,uVar2);
    }
    else {
      uVar3 = 0xc000022d;
LAB_14000e690:
      param_1 = puVar5;
      if (DAT_140019000 < 4) goto LAB_14000e75f;
      local_1d8 = (undefined8 *)CONCAT44(local_1d8._4_4_,(int)uVar3);
    }
  }
  local_170 = &local_1d8;
  local_168 = 4;
  _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_140016d11);
LAB_14000e75f:
  RtlFreeUnicodeString(local_1b0);
  if (local_1c8 != (undefined8 *)0x0) {
    ExFreePoolWithTag();
  }
  if (local_1c0 != (undefined8 *)0x0) {
    ExFreePoolWithTag();
  }
  if (lVar8 != 0) {
    if (*param_4 == 2) {
      cVar6 = '\x01';
    }
    else {
      if (*param_4 == 1) {
        ExReleasePushLockSharedEx(&gBfsPolicyTable);
        KeLeaveCriticalRegion();
        *param_4 = 0;
      }
      cVar6 = '\0';
    }
    BfsDereferencePolicyEntryEx(lVar8,cVar6);
  }
  return uVar3;
}



===== BfsGetRegistryPrefixEx @ 14000e810 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint BfsGetRegistryPrefixEx(ushort *param_1,undefined8 *param_2,undefined8 *param_3)

{
  short *psVar1;
  byte bVar2;
  uint uVar3;
  undefined8 uVar4;
  ushort *puVar5;
  longlong *plVar6;
  longlong lVar7;
  undefined1 auStackY_1f8 [32];
  uint local_1c8 [2];
  longlong local_1c0;
  undefined8 *local_1b8;
  undefined8 *local_1b0;
  undefined8 local_1a8;
  ushort local_1a0 [8];
  undefined8 local_190;
  undefined8 uStack_188;
  uint *local_160;
  undefined8 local_158;
  undefined1 local_148 [256];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_1f8;
  local_1b0 = (undefined8 *)0x0;
  local_190 = 0;
  uStack_188 = 0;
  memset(local_148,0,0x100);
  local_1a8 = 0x100;
  local_1c0 = 0;
  local_1b8 = (undefined8 *)0x0;
  lVar7 = 0;
  local_1a0[0] = 0;
  local_1a0[1] = 0;
  local_1a0[2] = 0;
  local_1a0[3] = 0;
  local_1a0[4] = 0;
  local_1a0[5] = 0;
  local_1a0[6] = 0;
  local_1a0[7] = 0;
  puVar5 = param_1;
  uVar3 = SeQueryInformationToken(param_1,1,&local_1b8);
  if (-1 < (int)uVar3) {
    puVar5 = param_1;
    uVar3 = SeQueryInformationToken(param_1,0x1f,&local_1b0);
    if (-1 < (int)uVar3) {
      bVar2 = BfsPolicyEntryExists
                        (gBfsFilterHandle,0,0x140019260,(byte *)*local_1b8,(byte *)*local_1b0);
      if (bVar2 == 1) {
        plVar6 = gBfsFilterHandle;
        uVar3 = BfsGetPolicyEntry(gBfsFilterHandle,0,(longlong *)&gBfsPolicyTable,(byte *)*local_1b8
                                  ,(byte *)*local_1b0,&local_1c0);
      }
      else {
        plVar6 = (longlong *)&gBfsPolicyTable;
        uVar4 = BfsGetNotPresentPolicyEntry
                          (0x140019260,(byte *)*local_1b8,(byte *)*local_1b0,&local_1c0);
        uVar3 = (uint)uVar4;
      }
      lVar7 = local_1c0;
      if ((int)uVar3 < 0) {
        if (3 < DAT_140019000) {
          local_160 = local_1c8;
          local_158 = 4;
          local_1c8[0] = uVar3;
          _tlgWriteTransfer_EtwWriteTransfer(plVar6,&DAT_140016d11);
        }
        lVar7 = local_1c0;
        goto LAB_14000ea83;
      }
      psVar1 = (short *)(local_1c0 + 0x70);
      if ((*psVar1 != 0) && (*(short *)(local_1c0 + 0x80) != 0)) {
LAB_14000ea6e:
        uVar4 = *(undefined8 *)(lVar7 + 0x78);
        *param_2 = *(undefined8 *)psVar1;
        param_2[1] = uVar4;
        uVar4 = *(undefined8 *)(lVar7 + 0x88);
        *param_3 = *(undefined8 *)(lVar7 + 0x80);
        param_3[1] = uVar4;
        goto LAB_14000ea83;
      }
      puVar5 = local_1a0;
      uVar3 = RtlConvertSidToUnicodeString(puVar5,*local_1b8,1);
      if (-1 < (int)uVar3) {
        uVar3 = RtlQueryPackageIdentity(param_1,local_148,&local_1a8,0);
        puVar5 = param_1;
        if (-1 < (int)uVar3) {
          RtlInitUnicodeString(&local_190,local_148);
          puVar5 = local_1a0;
          uVar3 = BfsCalculateRegistryPrefix
                            (puVar5,(ushort *)&local_190,(PUCHAR)psVar1,(PUCHAR)(lVar7 + 0x80));
          if (-1 < (int)uVar3) goto LAB_14000ea6e;
        }
      }
    }
  }
  if (3 < DAT_140019000) {
    local_160 = local_1c8;
    local_158 = 4;
    local_1c8[0] = uVar3;
    _tlgWriteTransfer_EtwWriteTransfer(puVar5,&DAT_140016d11);
  }
LAB_14000ea83:
  RtlFreeUnicodeString(local_1a0);
  if (local_1b8 != (undefined8 *)0x0) {
    ExFreePoolWithTag();
  }
  if (local_1b0 != (undefined8 *)0x0) {
    ExFreePoolWithTag();
  }
  if (lVar7 != 0) {
    BfsDereferencePolicyEntryEx(lVar7,'\0');
  }
  return uVar3;
}



===== BfsGetRegistryPrefixOld @ 14000eb08 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong BfsGetRegistryPrefixOld
                    (ushort *param_1,undefined8 *param_2,undefined8 *param_3,int *param_4)

{
  short *psVar1;
  uint uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  ushort *puVar5;
  char cVar6;
  undefined8 uVar7;
  longlong lVar8;
  undefined1 auStackY_218 [32];
  uint local_1d8 [2];
  longlong local_1d0;
  undefined8 *local_1c8;
  undefined8 *local_1c0;
  undefined8 local_1b8;
  ushort local_1b0 [8];
  undefined8 local_1a0;
  undefined8 uStack_198;
  uint *local_170;
  undefined8 local_168;
  undefined1 local_158 [256];
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStackY_218;
  local_1c0 = (undefined8 *)0x0;
  local_1a0 = 0;
  uStack_198 = 0;
  memset(local_158,0,0x100);
  local_1b8 = 0x100;
  local_1d0 = 0;
  local_1c8 = (undefined8 *)0x0;
  lVar8 = 0;
  local_1b0[0] = 0;
  local_1b0[1] = 0;
  local_1b0[2] = 0;
  local_1b0[3] = 0;
  local_1b0[4] = 0;
  local_1b0[5] = 0;
  local_1b0[6] = 0;
  local_1b0[7] = 0;
  puVar5 = param_1;
  uVar2 = SeQueryInformationToken(param_1,1,&local_1c8);
  uVar3 = (ulonglong)uVar2;
  if ((int)uVar2 < 0) {
LAB_14000eb99:
    param_1 = puVar5;
    if (DAT_140019000 < 4) goto LAB_14000edc1;
    local_1d8[0] = uVar2;
  }
  else {
    uVar7 = 0x1f;
    puVar5 = param_1;
    uVar2 = SeQueryInformationToken(param_1,0x1f,&local_1c0);
    uVar3 = (ulonglong)uVar2;
    if ((int)uVar2 < 0) goto LAB_14000eb99;
    puVar5 = gBfsFilterHandle;
    uVar3 = BfsPolicyEntryExistsLocked
                      (gBfsFilterHandle,uVar7,0x140019260,(byte *)*local_1c8,(byte *)*local_1c0,
                       *param_4);
    uVar2 = (uint)uVar3;
    uVar3 = uVar3 & 0xffffffff;
    if (uVar2 == 0) {
      puVar5 = gBfsFilterHandle;
      uVar4 = BfsGetPolicyEntryLocked
                        ((undefined8 *)gBfsFilterHandle,uVar7,0x140019260,(byte *)*local_1c8,
                         (byte *)*local_1c0,param_4,&local_1d0);
LAB_14000ec60:
      uVar3 = uVar4 & 0xffffffff;
      if ((int)(uint)uVar4 < 0) {
        if (3 < DAT_140019000) {
          local_170 = local_1d8;
          local_168 = 4;
          local_1d8[0] = (uint)uVar4;
          _tlgWriteTransfer_EtwWriteTransfer(puVar5,&DAT_140016d11);
        }
        lVar8 = local_1d0;
        goto LAB_14000edc1;
      }
      lVar8 = local_1d0;
    }
    else {
      if (uVar2 == 0xc0000225) {
        puVar5 = (ushort *)&gBfsPolicyTable;
        uVar4 = BfsGetNotPresentPolicyEntryLocked
                          (0x140019260,(byte *)*local_1c8,(byte *)*local_1c0,&local_1d0);
        goto LAB_14000ec60;
      }
      if ((int)uVar2 < 0) goto LAB_14000eb99;
    }
    psVar1 = (short *)(lVar8 + 0x70);
    if ((*psVar1 != 0) && (*(short *)(lVar8 + 0x80) != 0)) {
LAB_14000eda9:
      uVar7 = *(undefined8 *)(lVar8 + 0x78);
      *param_2 = *(undefined8 *)psVar1;
      param_2[1] = uVar7;
      uVar7 = *(undefined8 *)(lVar8 + 0x88);
      *param_3 = *(undefined8 *)(lVar8 + 0x80);
      param_3[1] = uVar7;
      goto LAB_14000edc1;
    }
    if (*param_4 == 2) {
      puVar5 = local_1b0;
      uVar2 = RtlConvertSidToUnicodeString(puVar5,*local_1c8,1);
      uVar3 = (ulonglong)uVar2;
      if ((int)uVar2 < 0) goto LAB_14000ecff;
      uVar2 = RtlQueryPackageIdentity(param_1,local_158,&local_1b8,0);
      uVar3 = (ulonglong)uVar2;
      if (-1 < (int)uVar2) {
        RtlInitUnicodeString(&local_1a0,local_158);
        param_1 = local_1b0;
        uVar2 = BfsCalculateRegistryPrefix
                          (param_1,(ushort *)&local_1a0,(PUCHAR)psVar1,(PUCHAR)(lVar8 + 0x80));
        uVar3 = (ulonglong)uVar2;
        if (-1 < (int)uVar2) goto LAB_14000eda9;
      }
      if (DAT_140019000 < 4) goto LAB_14000edc1;
      local_1d8[0] = uVar2;
    }
    else {
      uVar3 = 0xc000022d;
LAB_14000ecff:
      param_1 = puVar5;
      if (DAT_140019000 < 4) goto LAB_14000edc1;
      local_1d8[0] = (uint)uVar3;
    }
  }
  local_170 = local_1d8;
  local_168 = 4;
  _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_140016d11);
LAB_14000edc1:
  RtlFreeUnicodeString(local_1b0);
  if (local_1c8 != (undefined8 *)0x0) {
    ExFreePoolWithTag();
  }
  if (local_1c0 != (undefined8 *)0x0) {
    ExFreePoolWithTag();
  }
  if (lVar8 != 0) {
    if (*param_4 == 2) {
      cVar6 = '\x01';
    }
    else {
      if (*param_4 == 1) {
        ExReleasePushLockSharedEx(&gBfsPolicyTable);
        KeLeaveCriticalRegion();
        *param_4 = 0;
      }
      cVar6 = '\0';
    }
    BfsDereferencePolicyEntryEx(lVar8,cVar6);
  }
  return uVar3;
}



===== BfsRegistryPostCreateCallback @ 14000ee74 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint BfsRegistryPostCreateCallback(undefined8 param_1,undefined8 *param_2,undefined8 *param_3)

{
  int *piVar1;
  longlong lVar2;
  undefined8 uVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined8 *puVar6;
  undefined1 auStack_b8 [32];
  undefined8 local_98;
  undefined1 *local_90;
  undefined8 **local_88;
  uint local_78 [2];
  longlong *local_70;
  undefined8 *local_68;
  undefined1 local_60 [32];
  uint *local_40;
  undefined4 local_38;
  undefined4 local_34;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_b8;
  piVar1 = (int *)param_2[4];
  uVar4 = 0;
  local_68 = (undefined8 *)0x0;
  local_70 = (longlong *)0x0;
  if (piVar1 == (int *)0x0) goto LAB_14000f020;
  lVar2 = param_2[2];
  uVar4 = 0;
  if (*piVar1 != 0) {
    local_88 = &local_68;
    local_90 = (undefined1 *)((ulonglong)local_90 & 0xffffffffffffff00);
    local_98 = *(undefined8 *)CmKeyObjectType_exref;
    puVar6 = *(undefined8 **)(piVar1 + 4);
    uVar4 = ObOpenObjectByPointer(puVar6,0x200,0,piVar1[1]);
    if ((int)uVar4 < 0) {
LAB_14000ef59:
      if (3 < DAT_140019000) {
        local_34 = 0;
        local_40 = local_78;
        local_90 = local_60;
        local_38 = 4;
        local_78[0] = uVar4;
        _tlgWriteTransfer_EtwWriteTransfer(puVar6,&DAT_140016d11);
      }
      if ((uVar4 != 0xc0000503) && (*(longlong *)(piVar1 + 4) != 0)) {
        ObfDereferenceObject();
      }
    }
    else if (*piVar1 == 1) {
      **(undefined8 **)(lVar2 + 0x48) = *(undefined8 *)(piVar1 + 4);
LAB_14000efb7:
      uVar4 = 0xc0000503;
      *(int *)(lVar2 + 0x3c) = piVar1[1];
      uVar3 = *(undefined8 *)(piVar1 + 4);
      *(undefined4 *)(param_2 + 3) = 0;
      *param_2 = uVar3;
    }
    else if (*piVar1 == 2) {
      uVar4 = SeQueryInformationToken(param_3,0x1f,&local_70);
      puVar6 = param_3;
      if (-1 < (int)uVar4) {
        puVar6 = local_68;
        uVar4 = BfsAdjustRegistryKeySecurity(local_68,*local_70,piVar1[2]);
        if (-1 < (int)uVar4) {
          **(undefined8 **)(lVar2 + 0x48) = *(undefined8 *)(piVar1 + 4);
          goto LAB_14000efb7;
        }
      }
      goto LAB_14000ef59;
    }
  }
  ExFreePoolWithTag(piVar1,0);
  uVar5 = Feature_1199833401__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar5 != 0) {
    uVar5 = Feature_1199833401__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar5 != 0) {
      KeEnterCriticalRegion();
    }
    ExReleaseRundownProtection(&gBfsRundownProtection);
    KeLeaveCriticalRegion();
  }
LAB_14000f020:
  if (local_70 != (longlong *)0x0) {
    ExFreePoolWithTag(local_70,0);
  }
  if (local_68 != (undefined8 *)0x0) {
    ZwClose();
  }
  return uVar4;
}



===== BfsRegistryPreCreateCallback @ 14000f074 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint BfsRegistryPreCreateCallback(undefined4 param_1,undefined8 *param_2,undefined8 **param_3)

{
  uint uVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined4 *puVar6;
  undefined8 **ppuVar7;
  undefined1 auStackY_f8 [32];
  uint local_c8;
  char local_c4;
  longlong local_c0 [5];
  undefined8 *local_98;
  undefined8 **ppuStack_90;
  longlong local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  uint *local_50;
  undefined4 local_48;
  undefined4 local_44;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_f8;
  local_c0[0] = 0;
  local_78 = 0;
  local_c4 = '\0';
  uVar4 = 0;
  local_98 = (undefined8 *)0x0;
  ppuStack_90 = (undefined8 **)0x0;
  puVar6 = (undefined4 *)0x0;
  uVar3 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_c0[1] = 0;
  local_c0[2] = 0;
  local_c0[3] = 0;
  local_c0[4] = 0;
  RtlInitUnicodeString(local_c0 + 1,L"\\Registry\\WC\\Silo");
  cVar2 = RtlPrefixUnicodeString(local_c0 + 1,*param_2,1);
  if (cVar2 == '\0') {
    return 0;
  }
  uVar5 = Feature_1199833401__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar5 == 0) {
LAB_14000f17a:
    uVar5 = Feature_2470751545__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar5 == 0) {
      ppuVar7 = param_3;
      uVar3 = BfsGetRegistryPrefixEx((ushort *)param_3,local_c0 + 1,local_c0 + 3);
      if ((int)uVar3 < 0) {
        if (DAT_140019000 < 4) goto LAB_14000f6b6;
        local_50 = &local_c8;
        local_c8 = uVar3;
LAB_14000f1b4:
        local_44 = 0;
        local_48 = 4;
        _tlgWriteTransfer_EtwWriteTransfer(ppuVar7,&DAT_140016d11);
        uVar4 = 0;
      }
      else {
        cVar2 = RtlPrefixUnicodeString(local_c0 + 1,*param_2,1);
        if ((cVar2 == '\0') &&
           (cVar2 = RtlPrefixUnicodeString(local_c0 + 3,*param_2,1), cVar2 == '\0')) {
          return 0;
        }
LAB_14000f552:
        uVar4 = 0;
        ppuVar7 = &local_98;
        local_78 = CONCAT44(local_78._4_4_,param_1);
        local_98 = param_2;
        ppuStack_90 = param_3;
        uVar3 = BfsQueueIoWorkItemAndWait(ppuVar7);
        if ((int)uVar3 < 0) {
          if (3 < DAT_140019000) {
            local_c0[0] = CONCAT44(local_c0[0]._4_4_,uVar3);
            local_50 = (uint *)local_c0;
            goto LAB_14000f1b4;
          }
        }
        else {
          uVar1 = uStack_80._4_4_;
          if ((uint)uStack_80 == 0) {
            if (uStack_80._4_4_ != 0) {
              ppuVar7 = (undefined8 **)0x100;
              puVar6 = (undefined4 *)ExAllocatePool2(0x100,0x18,0x4f506642);
              if (puVar6 != (undefined4 *)0x0) {
                *puVar6 = 2;
                puVar6[1] = uVar1;
                puVar6[2] = uVar1;
                goto LAB_14000f5ea;
              }
LAB_14000f5ba:
              uVar3 = 0xc0000017;
              if (3 < DAT_140019000) {
                local_c0[0] = CONCAT44(local_c0[0]._4_4_,0xc0000017);
                local_50 = (uint *)local_c0;
                goto LAB_14000f1b4;
              }
            }
          }
          else if (((((uint)uStack_80 != uStack_80._4_4_) && ((uint)uStack_80 != 0)) &&
                   ((*(uint *)(param_2 + 7) & 0x2020006) != 0)) &&
                  ((uStack_80 & 0x2000600000000) != 0)) {
            ppuVar7 = (undefined8 **)0x100;
            puVar6 = (undefined4 *)ExAllocatePool2(0x100,0x18,0x4f506642);
            if (puVar6 == (undefined4 *)0x0) goto LAB_14000f5ba;
            *puVar6 = 1;
            if ((*(uint *)(param_2 + 7) >> 0x19 & 1) == 0) {
              uVar4 = *(uint *)(param_2 + 7) & uVar1;
            }
            else {
              uVar4 = uVar1;
            }
            puVar6[1] = uVar4;
            puVar6[2] = uVar1;
LAB_14000f5ea:
            puVar6[3] = *(undefined4 *)(param_2 + 3);
            *(longlong *)(puVar6 + 4) = local_88;
            param_2[10] = puVar6;
LAB_14000f4f2:
            uVar3 = 0;
            uVar4 = 0;
          }
        }
      }
    }
    else {
      KeEnterCriticalRegion();
      ExAcquirePushLockSharedEx(&gBfsPolicyTable,0);
      local_c8 = 1;
      uVar5 = Feature_2279589178__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar5 == 0) {
        ppuVar7 = param_3;
        uVar5 = BfsGetRegistryPrefixOld
                          ((ushort *)param_3,local_c0 + 1,local_c0 + 3,(int *)&local_c8);
        uVar3 = (uint)uVar5;
        if (-1 < (int)uVar3) {
LAB_14000f2fa:
          cVar2 = RtlPrefixUnicodeString(local_c0 + 1,*param_2,1);
          if ((cVar2 == '\0') &&
             (cVar2 = RtlPrefixUnicodeString(local_c0 + 3,*param_2,1), cVar2 == '\0')) {
            if (local_c8 == 1) {
              ExReleasePushLockSharedEx(&gBfsPolicyTable,0);
            }
            else {
              if (local_c8 != 2) {
                return 0;
              }
              ExReleasePushLockExclusiveEx(&gBfsPolicyTable,0);
            }
            KeLeaveCriticalRegion();
            return 0;
          }
          if (local_c8 == 1) {
            ExReleasePushLockSharedEx(&gBfsPolicyTable,0);
          }
          else {
            if (local_c8 != 2) goto LAB_14000f552;
LAB_14000f510:
            ExReleasePushLockExclusiveEx(&gBfsPolicyTable,0);
          }
          KeLeaveCriticalRegion();
          goto LAB_14000f552;
        }
        if (uVar3 == 0xc000022d) {
          if (local_c8 == 1) {
            ExReleasePushLockSharedEx(&gBfsPolicyTable,0);
            KeLeaveCriticalRegion();
          }
          KeEnterCriticalRegion();
          ExAcquirePushLockExclusiveEx(&gBfsPolicyTable,0);
          local_c8 = 2;
          ppuVar7 = param_3;
          uVar5 = BfsGetRegistryPrefixOld
                            ((ushort *)param_3,local_c0 + 1,local_c0 + 3,(int *)&local_c8);
          uVar3 = (uint)uVar5;
          if (-1 < (int)uVar3) goto LAB_14000f2fa;
        }
LAB_14000f675:
        if (3 < DAT_140019000) {
          local_44 = 0;
          local_c0[0] = CONCAT44(local_c0[0]._4_4_,uVar3);
          local_50 = (uint *)local_c0;
          local_48 = 4;
          _tlgWriteTransfer_EtwWriteTransfer(ppuVar7,&DAT_140016d11);
        }
        uVar4 = local_c8;
      }
      else {
        while( true ) {
          ppuVar7 = param_3;
          uVar5 = BfsGetRegistryPrefix
                            ((ushort *)param_3,local_c0 + 1,local_c0 + 3,(int *)&local_c8,local_c0);
          uVar1 = local_c8;
          uVar3 = (uint)uVar5;
          if (uVar3 != 0xc000022d) {
            if ((int)uVar3 < 0) goto LAB_14000f675;
            if (local_c8 != 0) {
              cVar2 = RtlPrefixUnicodeString(local_c0 + 1,*param_2,1);
              if ((cVar2 != '\0') ||
                 (cVar2 = RtlPrefixUnicodeString(local_c0 + 3,*param_2,1), cVar2 != '\0')) {
                if (uVar1 != 2) {
                  ExReleasePushLockSharedEx(&gBfsPolicyTable);
                  KeLeaveCriticalRegion();
                  BfsDereferencePolicyEntryEx(local_c0[0],'\0');
                  goto LAB_14000f552;
                }
                BfsDereferencePolicyEntryEx(local_c0[0],'\x01');
                goto LAB_14000f510;
              }
              if (uVar1 == 2) {
                BfsDereferencePolicyEntryEx(local_c0[0],'\x01');
                ExReleasePushLockExclusiveEx(&gBfsPolicyTable,0);
                KeLeaveCriticalRegion();
              }
              else {
                ExReleasePushLockSharedEx(&gBfsPolicyTable);
                KeLeaveCriticalRegion();
                BfsDereferencePolicyEntryEx(local_c0[0],'\0');
              }
              goto LAB_14000f4f2;
            }
          }
          if (local_c0[0] == 0) {
            if (local_c8 == 1) {
              ExReleasePushLockSharedEx(&gBfsPolicyTable,0);
              KeLeaveCriticalRegion();
            }
          }
          else {
            BfsDereferencePolicyEntryEx(local_c0[0],'\0');
            local_c0[0] = 0;
          }
          if (2 < uVar4) break;
          KeEnterCriticalRegion();
          ExAcquirePushLockExclusiveEx(&gBfsPolicyTable,0);
          uVar4 = uVar4 + 1;
          local_c8 = 2;
        }
        uVar4 = 0;
        uVar3 = 0xc0000001;
      }
    }
  }
  else {
    KeEnterCriticalRegion();
    cVar2 = ExAcquireRundownProtection(&gBfsRundownProtection);
    local_c4 = cVar2;
    uVar5 = Feature_1199833401__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar5 == 0) {
      if (cVar2 != '\0') goto LAB_14000f166;
      KeLeaveCriticalRegion();
    }
    else {
      KeLeaveCriticalRegion();
LAB_14000f166:
      local_c4 = cVar2;
      if (cVar2 != '\0') goto LAB_14000f17a;
    }
  }
LAB_14000f6b6:
  uVar5 = Feature_2470751545__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar5 != 0) {
    if (uVar4 == 1) {
      ExReleasePushLockSharedEx(&gBfsPolicyTable,0);
    }
    else {
      if (uVar4 != 2) goto LAB_14000f703;
      ExReleasePushLockExclusiveEx(&gBfsPolicyTable,0);
    }
    KeLeaveCriticalRegion();
  }
LAB_14000f703:
  if ((local_88 != 0) && (puVar6 == (undefined4 *)0x0)) {
    ObfDereferenceObject();
  }
  uVar5 = Feature_1199833401__private_IsEnabledDeviceUsageNoInline();
  if ((((int)uVar5 != 0) && (local_c4 != '\0')) && (puVar6 == (undefined4 *)0x0)) {
    uVar5 = Feature_1199833401__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar5 != 0) {
      KeEnterCriticalRegion();
    }
    ExReleaseRundownProtection(&gBfsRundownProtection);
    KeLeaveCriticalRegion();
  }
  return uVar3;
}



===== BfsRemoveKeyValues @ 14000f774 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int BfsRemoveKeyValues(undefined8 param_1)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  undefined1 auStack_98 [32];
  undefined4 local_78;
  undefined4 *local_70;
  int local_68;
  undefined4 local_64;
  undefined8 local_60;
  longlong lStack_58;
  undefined4 local_50 [8];
  int *local_30;
  undefined4 local_28;
  undefined4 local_24;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_98;
  local_64 = 0;
  uVar5 = 0xd8;
  local_60 = 0;
  lStack_58 = 0;
  uVar4 = 0x100;
  iVar2 = 0;
  lVar3 = ExAllocatePool2(0x100,0xd8,0x56736642);
  if (lVar3 == 0) {
LAB_14000f8fb:
    iVar2 = -0x3fffffe9;
    if (3 < DAT_140019000) {
      local_24 = 0;
      local_68 = -0x3fffffe9;
      local_30 = &local_68;
      local_70 = local_50;
      local_28 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(uVar4,&DAT_140016d11);
    }
  }
  else {
    do {
      while( true ) {
        local_70 = &local_64;
        uVar4 = param_1;
        local_78 = uVar5;
        iVar1 = ZwEnumerateValueKey(param_1,0,0,lVar3);
        if ((iVar1 != -0x7ffffffb) && (iVar1 != -0x3fffffdd)) break;
        ExFreePoolWithTag(lVar3,0);
        uVar5 = local_64;
        uVar4 = 0x100;
        lVar3 = ExAllocatePool2();
        if (lVar3 == 0) goto LAB_14000f8fb;
LAB_14000f8ed:
        if (iVar1 == -0x7fffffe6) goto LAB_14000f897;
      }
      if (iVar1 < 0) {
        if (-1 < iVar2) goto LAB_14000f8ed;
        if (DAT_140019000 < 4) goto LAB_14000f897;
        local_68 = iVar2;
        goto LAB_14000f86f;
      }
      local_60._0_4_ = CONCAT22(*(undefined2 *)(lVar3 + 8),*(undefined2 *)(lVar3 + 8));
      lStack_58 = lVar3 + 0xc;
      uVar4 = param_1;
      iVar2 = ZwDeleteValueKey();
    } while (-1 < iVar2);
    if (3 < DAT_140019000) {
      local_68 = iVar2;
LAB_14000f86f:
      iVar2 = local_68;
      local_24 = 0;
      local_30 = &local_68;
      local_70 = local_50;
      local_28 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(uVar4,&DAT_140016d11);
    }
LAB_14000f897:
    if (lVar3 != 0) {
      ExFreePoolWithTag(lVar3,0);
    }
  }
  return iVar2;
}



===== Feature_2279589178__private_IsEnabledDeviceUsageNoInline @ 14000f968 =====

ulonglong Feature_2279589178__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_2279589178__private_featureState;
  if ((Feature_2279589178__private_featureState & 0x10) == 0) {
    uVar1 = Feature_2279589178__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_2279589178__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_2279589178__private_IsEnabledFallback @ 14000f9a0 =====

void Feature_2279589178__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_2279589178__private_descriptor);
  return;
}



===== Feature_2470751545__private_IsEnabledDeviceUsageNoInline @ 14000f9bc =====

ulonglong Feature_2470751545__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_2470751545__private_featureState;
  if ((Feature_2470751545__private_featureState & 0x10) == 0) {
    uVar1 = Feature_2470751545__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_2470751545__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_2470751545__private_IsEnabledFallback @ 14000f9f4 =====

void Feature_2470751545__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_2470751545__private_descriptor);
  return;
}



===== BfsGetUserToken @ 14000fa10 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint BfsGetUserToken(longlong param_1,longlong *param_2)

{
  uint uVar1;
  undefined1 auStack_108 [32];
  longlong *local_e8;
  longlong *local_e0;
  longlong *local_d8;
  uint local_c8 [2];
  longlong local_c0;
  longlong local_b8;
  longlong local_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 *puStack_70;
  undefined8 local_68;
  undefined4 local_60;
  longlong local_58 [4];
  uint *local_38;
  undefined8 local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_108;
  local_68 = 0;
  local_60 = 0;
  local_d8 = &local_b0;
  local_b0 = 0;
  local_e0 = (longlong *)((ulonglong)local_e0 & 0xffffffffffffff00);
  local_b8 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  local_e8 = *(longlong **)SeTokenObjectType_exref;
  local_c0 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_78 = 0;
  puStack_70 = (undefined8 *)0x0;
  uVar1 = ObOpenObjectByPointer(0,0x200,0,0xf01ff);
  if (-1 < (int)uVar1) {
    local_98 = CONCAT44(local_98._4_4_,0x30);
    puStack_70 = &local_68;
    local_e0 = &local_c0;
    uStack_90 = 0;
    local_e8 = (longlong *)CONCAT44(local_e8._4_4_,2);
    uStack_80 = CONCAT44(uStack_80._4_4_,0x200);
    local_88 = 0;
    local_78 = 0;
    local_68 = 0x20000000c;
    local_60 = CONCAT22(local_60._2_2_,1);
    param_1 = local_b0;
    uVar1 = ZwDuplicateToken(local_b0,0xf01ff,&local_98,0);
    if (-1 < (int)uVar1) {
      local_e8 = &local_b8;
      local_e0 = (longlong *)0x0;
      param_1 = local_c0;
      uVar1 = ObReferenceObjectByHandle(local_c0,0xf01ff,*(undefined8 *)SeTokenObjectType_exref,0);
      if (-1 < (int)uVar1) {
        local_a8 = *(undefined8 *)(*(longlong *)SeExports_exref + 0x1e8);
        uStack_a0 = CONCAT44(uStack_a0._4_4_,0x60);
        param_1 = local_c0;
        uVar1 = ZwSetInformationToken(local_c0,0x19,&local_a8,0x10);
        if (-1 < (int)uVar1) {
          *param_2 = local_b8;
          goto LAB_14000fbc9;
        }
      }
    }
  }
  if (3 < DAT_140019000) {
    local_38 = local_c8;
    local_30 = 4;
    local_e0 = local_58;
    local_c8[0] = uVar1;
    _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_140016d11);
  }
  if (local_b8 != 0) {
    ObfDereferenceObject();
  }
LAB_14000fbc9:
  if (local_c0 != 0) {
    ZwClose();
  }
  if (local_b0 != 0) {
    ZwClose();
  }
  return uVar1;
}



===== BfsImpersonateToken @ 14000fc1c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint BfsImpersonateToken(void *param_1,longlong *param_2)

{
  uint uVar1;
  longlong lVar2;
  undefined1 auStack_f8 [32];
  longlong *local_d8;
  void **local_d0;
  void **local_c8;
  uint local_b8 [2];
  longlong local_b0;
  void *local_a8;
  void *local_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 *puStack_70;
  undefined8 local_68;
  undefined4 local_60;
  void *local_58 [4];
  uint *local_38;
  undefined8 local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_f8;
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  local_68 = 0;
  local_60 = 0;
  local_c8 = &local_a0;
  local_a8 = (void *)0x0;
  local_d0 = (void **)((ulonglong)local_d0 & 0xffffffffffffff00);
  local_98 = 0;
  uStack_90 = 0;
  local_b0 = 0;
  local_d8 = *(longlong **)SeTokenObjectType_exref;
  local_88 = 0;
  uStack_80 = 0;
  local_a0 = (void *)0x0;
  local_78 = 0;
  puStack_70 = (undefined8 *)0x0;
  uVar1 = ObOpenObjectByPointer(0,0x200,0,0xf01ff);
  if (-1 < (int)uVar1) {
    puStack_70 = &local_68;
    local_d0 = &local_a8;
    local_98 = CONCAT44(local_98._4_4_,0x30);
    local_d8 = (longlong *)CONCAT44(local_d8._4_4_,2);
    uStack_90 = 0;
    uStack_80 = CONCAT44(uStack_80._4_4_,0x200);
    local_88 = 0;
    local_78 = 0;
    local_68 = 0x20000000c;
    local_60 = CONCAT22(local_60._2_2_,1);
    param_1 = local_a0;
    uVar1 = ZwDuplicateToken(local_a0,0xf01ff,&local_98,0);
    if (-1 < (int)uVar1) {
      local_d8 = &local_b0;
      local_d0 = (void **)0x0;
      param_1 = local_a8;
      uVar1 = ObReferenceObjectByHandle(local_a8,0xf01ff,*(undefined8 *)SeTokenObjectType_exref,0);
      if (-1 < (int)uVar1) {
        lVar2 = PsReferenceImpersonationToken
                          (SystemReserved1[0xf],param_2 + 2,(longlong)param_2 + 0x11,
                           (longlong)param_2 + 0x14);
        if (lVar2 != 0) {
          PsRevertToSelf();
        }
        local_d8 = (longlong *)CONCAT44(local_d8._4_4_,2);
        param_1 = SystemReserved1[0xf];
        uVar1 = PsImpersonateClient(SystemReserved1[0xf],local_b0,0,0);
        if (-1 < (int)uVar1) {
          *param_2 = local_b0;
          param_2[1] = lVar2;
          goto LAB_14000fe0a;
        }
      }
    }
  }
  if (3 < DAT_140019000) {
    local_38 = local_b8;
    local_30 = 4;
    local_d0 = local_58;
    local_b8[0] = uVar1;
    _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_140016d11);
  }
  if (local_b0 != 0) {
    ObfDereferenceObject();
  }
LAB_14000fe0a:
  if (local_a8 != (void *)0x0) {
    ZwClose();
  }
  if (local_a0 != (void *)0x0) {
    ZwClose();
  }
  return uVar1;
}



===== BfsImpersonateUser @ 14000fe64 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint BfsImpersonateUser(void *param_1,longlong *param_2)

{
  uint uVar1;
  longlong lVar2;
  undefined1 auStack_108 [32];
  longlong *local_e8;
  void **local_e0;
  void **local_d8;
  uint local_c8 [2];
  longlong local_c0;
  void *local_b8;
  void *local_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 *puStack_70;
  undefined8 local_68;
  undefined4 local_60;
  void *local_58 [4];
  uint *local_38;
  undefined8 local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_108;
  local_68 = 0;
  local_60 = 0;
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  local_d8 = &local_b0;
  local_b8 = (void *)0x0;
  local_e0 = (void **)((ulonglong)local_e0 & 0xffffffffffffff00);
  local_a8 = 0;
  uStack_a0 = 0;
  local_c0 = 0;
  local_e8 = *(longlong **)SeTokenObjectType_exref;
  local_98 = 0;
  uStack_90 = 0;
  local_b0 = (void *)0x0;
  local_88 = 0;
  uStack_80 = 0;
  local_78 = 0;
  puStack_70 = (undefined8 *)0x0;
  uVar1 = ObOpenObjectByPointer(0,0x200,0,0xf01ff);
  if (-1 < (int)uVar1) {
    puStack_70 = &local_68;
    local_e0 = &local_b8;
    local_98 = CONCAT44(local_98._4_4_,0x30);
    local_e8 = (longlong *)CONCAT44(local_e8._4_4_,2);
    uStack_90 = 0;
    uStack_80 = CONCAT44(uStack_80._4_4_,0x200);
    local_88 = 0;
    local_78 = 0;
    local_68 = 0x20000000c;
    local_60 = CONCAT22(local_60._2_2_,1);
    param_1 = local_b0;
    uVar1 = ZwDuplicateToken(local_b0,0xf01ff,&local_98,0);
    if (-1 < (int)uVar1) {
      local_e8 = &local_c0;
      local_e0 = (void **)0x0;
      param_1 = local_b8;
      uVar1 = ObReferenceObjectByHandle(local_b8,0xf01ff,*(undefined8 *)SeTokenObjectType_exref,0);
      if (-1 < (int)uVar1) {
        lVar2 = PsReferenceImpersonationToken
                          (SystemReserved1[0xf],param_2 + 2,(longlong)param_2 + 0x11,
                           (longlong)param_2 + 0x14);
        if (lVar2 != 0) {
          PsRevertToSelf();
        }
        local_a8 = *(undefined8 *)(*(longlong *)SeExports_exref + 0x1e8);
        uStack_a0 = CONCAT44(uStack_a0._4_4_,0x60);
        param_1 = local_b8;
        uVar1 = ZwSetInformationToken(local_b8,0x19,&local_a8);
        if (-1 < (int)uVar1) {
          local_e8 = (longlong *)CONCAT44(local_e8._4_4_,2);
          param_1 = SystemReserved1[0xf];
          uVar1 = PsImpersonateClient(SystemReserved1[0xf],local_c0,0,0);
          if (-1 < (int)uVar1) {
            *param_2 = local_c0;
            param_2[1] = lVar2;
            goto LAB_14001009d;
          }
        }
      }
    }
  }
  if (3 < DAT_140019000) {
    local_38 = local_c8;
    local_30 = 4;
    local_e0 = local_58;
    local_c8[0] = uVar1;
    _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_140016d11);
  }
  if (local_c0 != 0) {
    ObfDereferenceObject();
  }
LAB_14001009d:
  if (local_b8 != (void *)0x0) {
    ZwClose();
  }
  if (local_b0 != (void *)0x0) {
    ZwClose();
  }
  return uVar1;
}



===== BfsRevertTokenImpersonation @ 1400100f4 =====

undefined4 BfsRevertTokenImpersonation(undefined8 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  PsRevertToSelf();
  ObfDereferenceObject(*param_1);
  if (param_1[1] != 0) {
    uVar1 = PsImpersonateClient(SystemReserved1[0xf],param_1[1],*(undefined1 *)(param_1 + 2),
                                *(undefined1 *)((longlong)param_1 + 0x11),
                                *(undefined4 *)((longlong)param_1 + 0x14));
  }
  return uVar1;
}



===== BfsQueueDeferredWorkItemAndWait @ 140010164 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint BfsQueueDeferredWorkItemAndWait
               (longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5)

{
  uint uVar1;
  undefined1 *puVar2;
  longlong lVar3;
  undefined1 *puVar4;
  undefined1 auStack_108 [32];
  longlong *local_e8;
  undefined1 *local_e0;
  uint local_d8 [4];
  longlong local_c8;
  longlong local_c0;
  undefined1 local_b8 [24];
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  uint local_88;
  undefined1 local_78 [32];
  uint *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_108;
  memset(&local_c8,0,0x48);
  local_98 = param_5;
  local_a0 = param_4;
  local_90 = param_3;
  KeInitializeEvent(local_b8,1);
  lVar3 = param_1;
  uVar1 = FltObjectReference();
  if ((int)uVar1 < 0) {
LAB_1400101de:
    if (DAT_140019000 < 4) goto LAB_140010309;
    local_d8[0] = uVar1;
  }
  else {
    local_c8 = param_1;
    if (param_2 != 0) {
      lVar3 = param_2;
      uVar1 = FltObjectReference();
      if ((int)uVar1 < 0) goto LAB_1400101de;
    }
    local_c0 = param_2;
    puVar2 = (undefined1 *)FltAllocateDeferredIoWorkItem();
    if (puVar2 != (undefined1 *)0x0) {
      local_e8 = &local_c8;
      puVar4 = puVar2;
      uVar1 = FltQueueDeferredIoWorkItem(puVar2,param_3,BfspSynchronousDeferredWorkItemRoutine,1);
      if ((int)uVar1 < 0) {
LAB_140010299:
        if (3 < DAT_140019000) {
          local_4c = 0;
          local_58 = local_d8;
          local_e0 = local_78;
          local_50 = 4;
          local_d8[0] = uVar1;
          _tlgWriteTransfer_EtwWriteTransfer(puVar4,&DAT_140016d11);
        }
      }
      else {
        local_e8 = (longlong *)0x0;
        puVar4 = local_b8;
        uVar1 = KeWaitForSingleObject(puVar4,6,0);
        if ((int)uVar1 < 0) goto LAB_140010299;
        uVar1 = local_88;
      }
      FltFreeDeferredIoWorkItem(puVar2);
      goto LAB_140010309;
    }
    uVar1 = 0xc0000017;
    if (DAT_140019000 < 4) goto LAB_140010309;
    local_d8[0] = 0xc0000017;
  }
  uVar1 = local_d8[0];
  local_4c = 0;
  local_58 = local_d8;
  local_e0 = local_78;
  local_50 = 4;
  _tlgWriteTransfer_EtwWriteTransfer(lVar3,&DAT_140016d11);
LAB_140010309:
  if (local_c0 != 0) {
    FltObjectDereference(param_2);
  }
  if (local_c8 != 0) {
    FltObjectDereference(param_1);
  }
  return uVar1;
}



===== BfsQueueIoWorkItemAndWait @ 14001035c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int BfsQueueIoWorkItemAndWait(undefined8 param_1)

{
  int iVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  undefined1 auStack_a8 [32];
  undefined8 local_88;
  undefined1 *local_80;
  int local_78 [2];
  undefined8 local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  code *local_50;
  undefined8 local_48;
  undefined1 local_40 [32];
  int *local_20;
  undefined4 local_18;
  undefined4 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_a8;
  local_70 = 0;
  local_48 = 0;
  local_50 = BfsAccessRegistryKeyAsUserCallback;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = param_1;
  KeInitializeEvent(&local_70,1);
  uVar3 = gBfsDeviceObject;
  lVar2 = IoAllocateWorkItem();
  if (lVar2 == 0) {
    iVar1 = -0x3fffffe9;
    if (3 < DAT_140019000) {
      local_14 = 0;
      local_20 = local_78;
      local_80 = local_40;
      local_78[0] = -0x3fffffe9;
      local_18 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(uVar3,&DAT_140016d11);
    }
  }
  else {
    IoQueueWorkItem(lVar2,BfspSynchronousIoWorkItemRoutine,0,&local_70);
    local_88 = 0;
    puVar4 = &local_70;
    iVar1 = KeWaitForSingleObject(puVar4,6,0);
    if (iVar1 < 0) {
      if (3 < DAT_140019000) {
        local_14 = 0;
        local_20 = local_78;
        local_80 = local_40;
        local_18 = 4;
        local_78[0] = iVar1;
        _tlgWriteTransfer_EtwWriteTransfer(puVar4,&DAT_140016d11);
      }
    }
    else {
      iVar1 = (int)local_48;
    }
    IoFreeWorkItem(lVar2);
  }
  return iVar1;
}



===== BfspSynchronousDeferredWorkItemRoutine @ 1400104d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void BfspSynchronousDeferredWorkItemRoutine
               (undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  undefined4 uVar1;
  
  uVar1 = (*(code *)param_3[6])(*param_3,param_3[1],param_2,param_3[5]);
  *(undefined4 *)(param_3 + 8) = uVar1;
  KeSetEvent(param_3 + 2,0,0);
  return;
}



===== BfspSynchronousIoWorkItemRoutine @ 140010520 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void BfspSynchronousIoWorkItemRoutine(undefined8 param_1,longlong param_2)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(param_2 + 0x20))(*(undefined8 *)(param_2 + 0x18));
  *(undefined4 *)(param_2 + 0x28) = uVar1;
  KeSetEvent(param_2,0,0);
  return;
}



===== BfsAddOrModifyEntry @ 14001055c =====

ulonglong BfsAddOrModifyEntry(longlong param_1,int param_2,int param_3,int param_4,ushort *param_5,
                             short *param_6)

{
  ushort uVar1;
  bool bVar2;
  uint uVar3;
  ulonglong uVar4;
  ushort *puVar5;
  longlong lVar6;
  ulonglong uVar7;
  int iVar8;
  short *psVar9;
  int iVar10;
  int iVar11;
  short *local_88;
  longlong local_80;
  ushort local_78 [8];
  undefined8 local_68;
  undefined8 uStack_60;
  ushort local_58 [16];
  
  psVar9 = param_6;
  param_6 = (short *)0x0;
  local_78[0] = 0;
  local_78[1] = 0;
  local_78[2] = 0;
  local_78[3] = 0;
  local_78[4] = 0;
  local_78[5] = 0;
  local_78[6] = 0;
  local_78[7] = 0;
  local_68 = *(undefined8 *)psVar9;
  uStack_60 = *(undefined8 *)(psVar9 + 4);
  if (((*psVar9 == 0) && (param_3 == 1)) && (param_4 == 2)) {
    uVar4 = 0xc000000d;
  }
  else {
    uVar4 = BfsCreateDirectory(param_1 + 0x30,param_5,3,(longlong *)&param_6);
    if (-1 < (int)uVar4) {
      bVar2 = true;
      local_88 = param_6;
      psVar9 = param_6;
      uVar4 = uVar4 & 0xffffffff;
      do {
        puVar5 = BfsGetPathComponent(local_58,&local_68,(undefined8 *)local_78);
        uVar1 = *puVar5;
        local_68 = *(undefined8 *)puVar5;
        uStack_60 = *(undefined8 *)(puVar5 + 4);
        KeEnterCriticalRegion();
        ExAcquirePushLockSharedEx(psVar9,0);
        lVar6 = BfsFindEntry((longlong)psVar9,local_78);
        ExReleasePushLockSharedEx(psVar9,0);
        KeLeaveCriticalRegion();
        if (lVar6 == 0) {
          iVar10 = 0;
          iVar11 = 0;
          if (uVar1 < 2) {
            bVar2 = false;
            iVar10 = param_3;
            iVar11 = param_4;
            iVar8 = param_2;
          }
          else {
            iVar8 = 2;
          }
          lVar6 = BfsInsertDirectoryEntry((longlong)psVar9,iVar8,iVar10,iVar11,local_78);
          uVar7 = Feature_AppSiloBfsInsertEntryValidityCheck__private_IsEnabledDeviceUsageNoInline()
          ;
          if (((int)uVar7 != 0) && (lVar6 == 0)) {
            return 0xc0000017;
          }
        }
        if (uVar1 < 2) {
          if (bVar2) {
            param_6 = (short *)((ulonglong)param_6 & 0xffffffff00000000);
            local_80 = 0;
            KeEnterCriticalRegion();
            ExAcquirePushLockExclusiveEx(psVar9,0);
            *(int *)(lVar6 + 4) = param_3;
            *(int *)(lVar6 + 8) = param_4;
            uVar7 = BfsGetEntryBlock((longlong)psVar9,lVar6,&local_80,(undefined4 *)&param_6);
            uVar4 = uVar7 & 0xffffffff;
            if ((int)uVar7 < 0) {
              ExReleasePushLockExclusiveEx(psVar9,0);
              KeLeaveCriticalRegion();
              goto LAB_14001079d;
            }
            uVar3 = BfsWriteBlock(param_1,(int)param_6,local_80);
            uVar4 = (ulonglong)uVar3;
            ExReleasePushLockExclusiveEx(psVar9,0);
            KeLeaveCriticalRegion();
            BfsDereferenceTableEntry((undefined8 *)(psVar9 + -4));
            if ((int)uVar3 < 0) break;
          }
        }
        else {
          uVar7 = BfsCreateDirectory((longlong)psVar9,local_78,1,(longlong *)&local_88);
          uVar4 = uVar7 & 0xffffffff;
          if ((int)uVar7 < 0) {
LAB_14001079d:
            BfsDereferenceTableEntry((undefined8 *)(psVar9 + -4));
            break;
          }
          BfsDereferenceTableEntry((undefined8 *)(psVar9 + -4));
          psVar9 = local_88;
        }
      } while (1 < uVar1);
    }
  }
  return uVar4;
}



===== BfsAllocateBlock @ 1400107cc =====

undefined8 BfsAllocateBlock(longlong param_1,int *param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = RtlFindClearBits(param_1 + 0x18,1);
  if (iVar1 == -1) {
    uVar2 = 0x8000001a;
  }
  else {
    RtlSetBits(param_1 + 0x18,iVar1,1);
    uVar2 = 0;
    *param_2 = iVar1;
  }
  return uVar2;
}



===== BfsAllocateTableEntry @ 140010840 =====

void BfsAllocateTableEntry(undefined8 param_1,undefined4 param_2)

{
  ExAllocatePool2(0x100,param_2,0x65736642);
  return;
}



===== BfsCloseStorage @ 14001086c =====

void BfsCloseStorage(longlong param_1)

{
  undefined8 *puVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong lVar4;
  code *pcVar5;
  char cVar6;
  undefined8 *puVar7;
  ulonglong uVar8;
  undefined8 *puVar9;
  undefined8 *puVar10;
  undefined1 *puVar11;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  if (*(longlong *)(param_1 + 8) != 0) {
    FltClose();
  }
  if (*(longlong *)(param_1 + 0x10) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x10),0);
  }
  puVar11 = auStack_28;
  plVar2 = *(longlong **)(param_1 + 0x40);
  do {
    plVar3 = (longlong *)*plVar2;
    if (plVar3 == plVar2) {
LAB_140010902:
      *(undefined8 *)(puVar11 + -8) = 0x14001090e;
      ExFreePoolWithTag(plVar2,0);
      puVar1 = (undefined8 *)(param_1 + 0x50);
      puVar9 = puVar1;
      do {
        *(undefined8 *)(puVar11 + -8) = 0x140010926;
        puVar7 = (undefined8 *)RtlEnumerateGenericTableAvl(puVar9,1);
        puVar10 = puVar9;
        if (puVar7 == (undefined8 *)0x0) {
          if (puVar9 == puVar1) {
            *(undefined8 *)(puVar11 + -8) = 0x140010988;
            ExFreePoolWithTag(param_1,0);
            return;
          }
          puVar7 = puVar9 + -5;
          puVar10 = (undefined8 *)(puVar9[0xd] + 0x20);
        }
        *(undefined8 *)(puVar11 + -8) = 0x140010952;
        cVar6 = RtlIsGenericTableEmptyAvl(puVar7 + 5);
        if (cVar6 == '\0') {
          puVar9 = puVar7 + 5;
        }
        else {
          *(undefined8 *)(puVar11 + -8) = 0x140010963;
          BfsDereferenceTableEntry(puVar7);
          *(undefined8 *)(puVar11 + -8) = 0x140010968;
          uVar8 = Feature_819443003__private_IsEnabledDeviceUsageNoInline();
          puVar9 = puVar1;
          if ((int)uVar8 == 0) {
            puVar9 = puVar10;
          }
        }
      } while( true );
    }
    if (((longlong *)plVar3[1] != plVar2) ||
       (lVar4 = *plVar3, (longlong *)*(longlong *)(lVar4 + 8) != plVar3)) {
      pcVar5 = (code *)swi(0x29);
      (*pcVar5)(3);
      puVar11 = auStack_20;
      goto LAB_140010902;
    }
    *plVar2 = lVar4;
    *(longlong **)(lVar4 + 8) = plVar2;
    ExFreePoolWithTag(plVar3[2]);
    ExFreePoolWithTag(plVar3);
  } while( true );
}



===== BfsCompareTableEntries @ 1400109b0 =====

char BfsCompareTableEntries(undefined8 param_1,undefined8 *param_2,undefined8 *param_3)

{
  char cVar1;
  int iVar2;
  
  iVar2 = RtlCompareUnicodeString(*param_2,*param_3,1);
  cVar1 = '\0';
  if (-1 < iVar2) {
    cVar1 = (iVar2 < 1) + '\x01';
  }
  return cVar1;
}



===== BfsCreateDirectory @ 1400109e8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong BfsCreateDirectory(longlong param_1,ushort *param_2,uint param_3,longlong *param_4)

{
  longlong *plVar1;
  code *pcVar2;
  uint uVar3;
  ulonglong uVar4;
  longlong lVar5;
  longlong *plVar6;
  longlong lVar7;
  ulonglong uVar8;
  longlong lVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  undefined1 *puVar13;
  int iVar14;
  undefined1 auStackY_148 [8];
  undefined1 auStackY_140 [24];
  char local_118 [8];
  undefined1 *local_110;
  undefined1 local_108 [8];
  undefined8 local_100;
  longlong *local_f8;
  undefined1 local_78 [32];
  undefined1 *local_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_148;
  memset(local_108,0,0x88);
  lVar9 = param_1 + 0x18;
  local_118[0] = '\0';
  uVar4 = BfsLocateDirectory(lVar9,param_2,param_4);
  puVar13 = auStackY_148;
  if (-1 < (int)uVar4) goto LAB_140010d60;
  KeEnterCriticalRegion();
  ExAcquirePushLockSharedEx(param_1,0);
  lVar5 = BfsFindEntry(param_1,param_2);
  ExReleasePushLockSharedEx(param_1,0);
  KeLeaveCriticalRegion();
  puVar13 = auStackY_148;
  if (lVar5 == 0) {
    if (param_3 == 1) {
      uVar4 = 0xc0000225;
      puVar13 = auStackY_148;
      goto LAB_140010d60;
    }
    if ((param_3 & 3) != 0) {
      lVar5 = BfsInsertDirectoryEntry(param_1,2,0,0,param_2);
      uVar4 = Feature_AppSiloBfsInsertEntryValidityCheck__private_IsEnabledDeviceUsageNoInline();
      puVar13 = auStackY_148;
      if (((int)uVar4 != 0) && (lVar5 == 0)) {
        uVar4 = 0xc0000017;
        goto LAB_140010d60;
      }
    }
  }
  else if (*(int *)(lVar5 + 0xc) == 0) {
    uVar4 = 0xc0000032;
    goto LAB_140010d60;
  }
  iVar14 = *(int *)(lVar5 + 0xc);
  lVar5 = 0x100;
  local_f8 = (longlong *)ExAllocatePool2(0x100,0x10,0x48736642);
  puVar11 = auStackY_148;
  puVar13 = auStackY_148;
  puVar12 = auStackY_148;
  if (local_f8 == (longlong *)0x0) {
LAB_140010d07:
    lVar9 = lVar5;
    uVar4 = 0xc0000017;
    puVar13 = auStackY_148;
    if (3 < DAT_140019000) {
      local_110 = (undefined1 *)CONCAT44(local_110._4_4_,0xc0000017);
LAB_140010d23:
      local_50 = 4;
      local_58 = puVar12 + 0x38;
      *(undefined1 **)(puVar12 + 0x28) = local_78;
      *(undefined8 *)(puVar12 + -8) = 0x140010d41;
      _tlgWriteTransfer_EtwWriteTransfer(lVar9,&DAT_140016d11);
      puVar13 = puVar12;
    }
  }
  else {
    local_f8[1] = (longlong)local_f8;
    *local_f8 = (longlong)local_f8;
    do {
      lVar5 = 0x100;
      plVar6 = (longlong *)ExAllocatePool2(0x100,0x20,0x4c736642);
      if (plVar6 == (longlong *)0x0) goto LAB_140010d07;
      lVar5 = 0x100;
      lVar7 = ExAllocatePool2(0x100,0x4000,0x62736642);
      if (lVar7 == 0) {
LAB_140010cfe:
        uVar3 = 0xc0000017;
        uVar4 = 0xc0000017;
        puVar10 = puVar11;
LAB_140010cdd:
        puVar13 = puVar10;
        if (DAT_140019000 < 4) goto LAB_140010d41;
        *(uint *)(puVar10 + 0x38) = uVar3;
        lVar9 = lVar5;
        puVar12 = puVar10;
        goto LAB_140010d23;
      }
      plVar6[2] = lVar7;
      *(int *)(plVar6 + 3) = iVar14;
      plVar1 = (longlong *)local_f8[1];
      if ((longlong *)*plVar1 != local_f8) {
        lVar5 = 3;
        pcVar2 = (code *)swi(0x29);
        (*pcVar2)();
        puVar11 = auStackY_140;
        goto LAB_140010cfe;
      }
      *plVar6 = (longlong)local_f8;
      plVar6[1] = (longlong)plVar1;
      *plVar1 = (longlong)plVar6;
      local_f8[1] = (longlong)plVar6;
      lVar5 = *(longlong *)(param_1 + 8);
      uVar3 = BfsReadBlock(lVar5,iVar14,lVar7);
      uVar4 = (ulonglong)uVar3;
      puVar10 = auStackY_148;
      if ((int)uVar3 < 0) goto LAB_140010cdd;
      iVar14 = *(int *)(lVar7 + 4);
    } while (iVar14 != 0);
    local_100 = *(undefined8 *)(param_1 + 8);
    local_110 = local_108;
    KeEnterCriticalRegion();
    ExAcquirePushLockExclusiveEx(lVar9,0);
    uVar8 = BfsInsertDirectory(lVar9,(longlong)param_2,(longlong *)&local_110,(longlong)local_118);
    puVar12 = local_110;
    uVar4 = uVar8 & 0xffffffff;
    if (-1 < (int)uVar8) {
      if (local_118[0] == '\0') {
        BfsFreeDirectoryBlockList(local_f8);
        ExFreePoolWithTag(local_f8,0);
      }
      else {
        ExInitializePushLock(local_110 + 0x18);
        RtlInitializeGenericTableAvl
                  (puVar12 + 0x20,BfsCompareTableEntries,BfsAllocateTableEntry,BfsFreeTableEntry);
        LOCK();
        *(int *)(param_1 + 0x90) = *(int *)(param_1 + 0x90) + 1;
        UNLOCK();
      }
      ExReleasePushLockExclusiveEx(lVar9,0);
      KeLeaveCriticalRegion();
      *param_4 = (longlong)local_110;
      goto LAB_140010d60;
    }
    ExReleasePushLockExclusiveEx(lVar9,0);
    KeLeaveCriticalRegion();
    puVar13 = auStackY_148;
    if (3 < DAT_140019000) {
      local_110 = (undefined1 *)CONCAT44(local_110._4_4_,(int)uVar8);
      puVar12 = auStackY_148;
      goto LAB_140010d23;
    }
  }
LAB_140010d41:
  *(undefined8 *)(puVar13 + -8) = 0x140010d4b;
  BfsFreeDirectoryBlockList(*(longlong **)(puVar13 + 0x50));
  *(undefined8 *)(puVar13 + -8) = 0x140010d59;
  ExFreePoolWithTag(*(undefined8 *)(puVar13 + 0x50),0);
LAB_140010d60:
  *(undefined8 *)(puVar13 + -8) = 0x140010d6c;
  return uVar4;
}



===== BfsCreateStorage @ 140010d90 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong BfsCreateStorage(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4
                          ,longlong *param_5)

{
  uint uVar1;
  uint uVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined4 *_Dst;
  undefined4 *puVar5;
  undefined1 auStack_188 [32];
  undefined4 local_168;
  undefined4 uStack_164;
  undefined8 *local_160;
  longlong *local_158;
  undefined8 local_150;
  undefined4 local_148;
  undefined4 local_140;
  undefined4 local_138;
  undefined4 local_130;
  undefined8 local_128;
  undefined4 local_120;
  undefined4 local_118;
  undefined8 local_110;
  uint local_108;
  int local_104;
  longlong local_100 [3];
  longlong *local_e8;
  undefined8 local_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined *local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0 [4];
  uint *local_80;
  undefined8 local_78;
  undefined8 local_70;
  longlong lStack_68;
  undefined8 local_60;
  uint *local_50;
  undefined8 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_188;
  local_110 = 0;
  local_e8 = param_5;
  local_118 = 0x100;
  _Dst = (undefined4 *)0x0;
  local_120 = 0;
  lVar3 = 0;
  local_128 = 0;
  puVar5 = (undefined4 *)0x0;
  local_130 = 0x860;
  local_138 = 3;
  local_140 = 0;
  *param_5 = 0;
  local_148 = 0x80;
  local_c0 = &gBfsPolicyStorageFileDescriptor;
  local_158 = local_100 + 1;
  local_150 = 0;
  local_160 = &local_e0;
  local_168 = 0xc0110000;
  local_100[1] = 0;
  local_100[2] = 0;
  local_e0 = 0x30;
  local_c8 = 0x240;
  local_100[0] = 0;
  local_b8 = 0;
  local_d8 = param_3;
  local_d0 = param_4;
  uVar2 = FltCreateFileEx2(0,param_2,local_100,0);
  uVar4 = (ulonglong)uVar2;
  if ((int)uVar2 < 0) {
LAB_140010e98:
    if (3 < DAT_140019000) {
      local_50 = &local_108;
      local_160 = &local_70;
      local_48 = 4;
      local_108 = uVar2;
LAB_140011168:
      _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_140016d11);
    }
  }
  else {
    param_1 = 0x100;
    lVar3 = ExAllocatePool2(0x100,200,0x73736642);
    if (lVar3 == 0) {
      uVar2 = 0xc0000017;
      uVar4 = 0xc0000017;
      goto LAB_140010e98;
    }
    ExInitializePushLock(lVar3);
    *(longlong *)(lVar3 + 8) = local_100[0];
    uVar4 = Feature_1122292024__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar4 == 0) {
LAB_140010f45:
      if (local_100[2] == 2) goto LAB_140010f4e;
      param_1 = 0x100;
      _Dst = (undefined4 *)ExAllocatePool2(0x100,0x4000,0x63736642);
      if (_Dst != (undefined4 *)0x0) {
        param_1 = lVar3;
        uVar2 = BfsReadBlock(lVar3,0,_Dst);
        uVar4 = (ulonglong)uVar2;
        if (-1 < (int)uVar2) {
          *(undefined4 **)(lVar3 + 0x10) = _Dst;
          RtlInitializeBitMap(lVar3 + 0x18,_Dst + 6,0x1ff40);
          param_1 = lVar3;
          uVar2 = BfsOpenRootDirectory(lVar3);
          uVar4 = (ulonglong)uVar2;
          if ((int)uVar2 < 0) goto LAB_140011148;
          ExInitializePushLock(lVar3 + 0x48);
          local_168 = 0;
          uStack_164 = 0;
          RtlInitializeGenericTableAvl
                    (lVar3 + 0x50,BfsCompareTableEntries,BfsAllocateTableEntry,BfsFreeTableEntry);
LAB_1400111f6:
          *local_e8 = lVar3;
          goto LAB_1400111fd;
        }
        goto LAB_140011148;
      }
LAB_140010f7e:
      uVar2 = 0xc0000017;
      uVar4 = 0xc0000017;
LAB_140011148:
      if (DAT_140019000 < 4) goto LAB_140011179;
      local_108 = uVar2;
LAB_140011154:
      local_80 = &local_108;
      local_78 = 4;
      local_160 = local_a0;
      goto LAB_140011168;
    }
    if (local_100[2] != 2) {
      local_168 = 5;
      local_b0 = 0;
      uStack_a8 = 0;
      local_60 = 0;
      local_70 = 0;
      lStack_68 = 0;
      param_1 = local_100[0];
      uVar2 = ZwQueryInformationFile(local_100[0],&local_b0,&local_70,0x18);
      uVar4 = (ulonglong)uVar2;
      if (-1 < (int)uVar2) {
        if (lStack_68 == 0) {
          local_100[2] = 2;
        }
        goto LAB_140010f45;
      }
      goto LAB_140011148;
    }
LAB_140010f4e:
    local_104 = 0;
    local_108 = 0;
    param_1 = 0x100;
    _Dst = (undefined4 *)ExAllocatePool2(0x100,0x4000,0x63736642);
    if (_Dst == (undefined4 *)0x0) goto LAB_140010f7e;
    memset(_Dst,0,0x4000);
    *_Dst = 0x43736642;
    _Dst[2] = 0x4000;
    _Dst[1] = _Dst[1] & 0xff000001 | 1;
    *(undefined1 *)((longlong)_Dst + 7) = 0;
    *(undefined4 **)(lVar3 + 0x10) = _Dst;
    RtlInitializeBitMap(lVar3 + 0x18,_Dst + 6,0x1ff40);
    ExInitializePushLock(lVar3 + 0x48);
    local_168 = 0;
    uStack_164 = 0;
    RtlInitializeGenericTableAvl
              (lVar3 + 0x50,BfsCompareTableEntries,BfsAllocateTableEntry,BfsFreeTableEntry);
    param_1 = lVar3;
    uVar4 = BfsAllocateBlock(lVar3,&local_104);
    uVar2 = (uint)uVar4;
    uVar4 = uVar4 & 0xffffffff;
    if ((int)uVar2 < 0) goto LAB_140011148;
    if (local_104 == 0) {
      param_1 = lVar3;
      uVar4 = BfsAllocateBlock(lVar3,(int *)&local_108);
      uVar1 = local_108;
      uVar2 = (uint)uVar4;
      uVar4 = uVar4 & 0xffffffff;
      if (-1 < (int)uVar2) {
        param_1 = 0x100;
        *(uint *)(*(longlong *)(lVar3 + 0x10) + 0xc) = local_108;
        puVar5 = (undefined4 *)ExAllocatePool2(0x100,0x4000,0x62736642);
        if (puVar5 == (undefined4 *)0x0) goto LAB_140010f7e;
        memset(puVar5 + 1,0,0x3ffc);
        *puVar5 = 0x44736642;
        param_1 = lVar3;
        uVar2 = BfsWriteBlock(lVar3,local_104,_Dst);
        uVar4 = (ulonglong)uVar2;
        if (-1 < (int)uVar2) {
          param_1 = lVar3;
          uVar2 = BfsWriteBlock(lVar3,uVar1,puVar5);
          uVar4 = (ulonglong)uVar2;
          if (-1 < (int)uVar2) {
            param_1 = lVar3;
            uVar2 = BfsOpenRootDirectory(lVar3);
            uVar4 = (ulonglong)uVar2;
            if (-1 < (int)uVar2) goto LAB_1400111f6;
          }
        }
      }
      goto LAB_140011148;
    }
    uVar4 = 0xc0000032;
    if (3 < DAT_140019000) {
      local_108 = 0xc0000032;
      goto LAB_140011154;
    }
  }
LAB_140011179:
  if (local_100[0] != 0) {
    FltClose();
  }
  if (lVar3 != 0) {
    ExFreePoolWithTag(lVar3,0);
  }
  if (_Dst != (undefined4 *)0x0) {
    ExFreePoolWithTag(_Dst,0);
  }
LAB_1400111fd:
  if (puVar5 != (undefined4 *)0x0) {
    ExFreePoolWithTag(puVar5,0);
  }
  return uVar4;
}



===== BfsDeleteEntry @ 14001123c =====

ulonglong BfsDeleteEntry(longlong param_1,int param_2,ushort *param_3,undefined8 *param_4)

{
  longlong lVar1;
  undefined4 uVar2;
  uint uVar3;
  ulonglong uVar4;
  ushort *puVar5;
  int *_Dst;
  ulonglong uVar6;
  ulonglong uVar7;
  ulonglong local_res8;
  ulonglong local_res20;
  longlong local_78;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  ushort local_50 [20];
  
  local_60 = *param_4;
  uStack_58 = param_4[1];
  local_res8 = 0;
  local_50[0] = 0;
  local_50[1] = 0;
  local_50[2] = 0;
  local_50[3] = 0;
  local_50[4] = 0;
  local_50[5] = 0;
  local_50[6] = 0;
  local_50[7] = 0;
  uVar4 = BfsCreateDirectory(param_1 + 0x30,param_3,1,(longlong *)&local_res8);
  if ((int)uVar4 < 0) {
    return uVar4;
  }
  local_res20 = local_res8;
  uVar4 = local_res8;
  do {
    puVar5 = BfsGetPathComponent(local_50 + 8,&local_60,(undefined8 *)local_50);
    local_60 = *(undefined8 *)puVar5;
    uStack_58 = *(undefined8 *)(puVar5 + 4);
    KeEnterCriticalRegion();
    ExAcquirePushLockSharedEx(uVar4,0);
    _Dst = (int *)BfsFindEntry(uVar4,local_50);
    ExReleasePushLockSharedEx(uVar4,0);
    KeLeaveCriticalRegion();
    if (_Dst == (int *)0x0) {
      BfsDereferenceTableEntry((undefined8 *)(uVar4 - 8));
      return 0xc0000225;
    }
    if ((ushort)local_60 < 2) {
      local_res8 = local_res8 & 0xffffffff00000000;
      local_78 = 0;
      uStack_68 = 0;
      local_70 = 0;
      local_6c = 0;
      if (*_Dst != param_2) {
        uVar7 = 0xc0000024;
LAB_140011445:
        BfsDereferenceTableEntry((undefined8 *)(uVar4 - 8));
        return uVar7;
      }
      KeEnterCriticalRegion();
      ExAcquirePushLockExclusiveEx(uVar4,0);
      uVar6 = BfsGetEntryBlock(uVar4,(longlong)_Dst,&local_78,(undefined4 *)&local_res8);
      lVar1 = local_78;
      uVar7 = uVar6 & 0xffffffff;
      if ((int)uVar6 < 0) {
        ExReleasePushLockExclusiveEx(uVar4,0);
        KeLeaveCriticalRegion();
        goto LAB_140011445;
      }
      if (*_Dst == 1) {
        uVar2 = BfsGetEntryIndex(local_78,(longlong)_Dst);
        RtlInitializeBitMap(&local_70,lVar1 + 0x3e60,0x1e);
        RtlClearBits(&local_70,uVar2,1);
        memset(_Dst,0,0x214);
      }
      else {
        _Dst[1] = 0;
        _Dst[2] = 0;
      }
      uVar3 = BfsWriteBlock(param_1,(int)local_res8,lVar1);
      uVar7 = (ulonglong)uVar3;
      ExReleasePushLockExclusiveEx(uVar4,0);
      KeLeaveCriticalRegion();
      BfsDereferenceTableEntry((undefined8 *)(uVar4 - 8));
      if ((int)uVar3 < 0) {
        return uVar7;
      }
    }
    else {
      uVar6 = BfsCreateDirectory(uVar4,local_50,1,(longlong *)&local_res20);
      uVar7 = uVar6 & 0xffffffff;
      if ((int)uVar6 < 0) goto LAB_140011445;
      BfsDereferenceTableEntry((undefined8 *)(uVar4 - 8));
      uVar4 = local_res20;
    }
    if ((ushort)local_60 < 2) {
      return uVar7;
    }
    if (local_50[0] < 2) {
      return uVar7;
    }
  } while( true );
}



===== BfsDereferenceTableEntry @ 1400114a8 =====

void BfsDereferenceTableEntry(undefined8 *param_1)

{
  int *piVar1;
  undefined8 uVar2;
  longlong lVar3;
  longlong *plVar4;
  int iVar5;
  ulonglong uVar6;
  longlong lVar7;
  
  LOCK();
  piVar1 = (int *)(param_1 + 0x13);
  iVar5 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  while( true ) {
    if (iVar5 != 1) {
      return;
    }
    uVar6 = Feature_3083317562__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar6 == 0) {
      uVar2 = param_1[0x12];
      KeEnterCriticalRegion();
      ExAcquirePushLockExclusiveEx(uVar2,0);
    }
    uVar6 = Feature_3083317562__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar6 != 0) {
      lVar3 = param_1[0x12];
      KeEnterCriticalRegion();
      ExAcquirePushLockExclusiveEx(lVar3 + 0x18,0);
      if (*(int *)(param_1 + 0x13) != 0) {
        ExReleasePushLockExclusiveEx(param_1[0x12] + 0x18,0);
        KeLeaveCriticalRegion();
        return;
      }
    }
    lVar3 = param_1[0x12];
    uVar2 = *param_1;
    plVar4 = (longlong *)param_1[3];
    RtlDeleteElementGenericTableAvl(lVar3 + 0x20);
    RtlFreeUnicodeString(uVar2);
    ExFreePoolWithTag(uVar2);
    if (plVar4 != (longlong *)0x0) {
      BfsFreeDirectoryBlockList(plVar4);
      ExFreePoolWithTag(plVar4);
    }
    uVar6 = Feature_3083317562__private_IsEnabledDeviceUsageNoInline();
    lVar7 = lVar3;
    if ((int)uVar6 != 0) {
      lVar7 = lVar3 + 0x18;
    }
    ExReleasePushLockExclusiveEx(lVar7);
    KeLeaveCriticalRegion();
    param_1 = (undefined8 *)(lVar3 + -8);
    if (*(longlong *)(lVar3 + 0x88) == 0) break;
    LOCK();
    piVar1 = (int *)(lVar3 + 0x90);
    iVar5 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
  }
  return;
}



===== BfsEnumerateDirectory @ 140011628 =====

undefined8 BfsEnumerateDirectory(longlong param_1,int param_2,longlong *param_3)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  undefined8 uVar4;
  longlong *plVar5;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  
  uVar4 = 0x8000001a;
  KeEnterCriticalRegion();
  ExAcquirePushLockSharedEx(param_1,0);
  plVar5 = (longlong *)**(undefined8 **)(param_1 + 0x10);
  uVar3 = 0;
  do {
    if (plVar5 == *(longlong **)(param_1 + 0x10)) {
LAB_140011707:
      ExReleasePushLockSharedEx(param_1,0);
      KeLeaveCriticalRegion();
      return uVar4;
    }
    uStack_20 = 0;
    local_28 = 0;
    uStack_24 = 0;
    lVar1 = **(longlong **)(param_1 + 0x10);
    RtlInitializeBitMap(&local_28,*(longlong *)(lVar1 + 0x10) + 0x3e60,0x1e);
    uVar2 = RtlNumberOfSetBits();
    if (param_2 - uVar3 < uVar2) {
      uVar3 = RtlFindSetBits(&local_28,1);
      *param_3 = *(longlong *)(lVar1 + 0x10) + 8 + (ulonglong)uVar3 * 0x214;
      uVar4 = 0;
      goto LAB_140011707;
    }
    plVar5 = (longlong *)*plVar5;
    uVar3 = uVar2;
  } while( true );
}



===== BfsExpandDirectory @ 14001174c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong BfsExpandDirectory(longlong param_1,longlong param_2,longlong param_3,undefined8 *param_4,
                            undefined8 *param_5)

{
  undefined8 uVar1;
  longlong *plVar2;
  code *pcVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  ulonglong uVar7;
  longlong *plVar8;
  ulonglong uVar9;
  longlong lVar10;
  undefined4 *puVar11;
  bool bVar12;
  undefined1 auStack_d8 [40];
  undefined1 *local_b0;
  uint local_a8 [2];
  longlong local_a0;
  undefined8 *local_98;
  undefined8 *local_90;
  undefined1 local_88 [32];
  uint *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStack_d8;
  *param_4 = 0;
  local_98 = param_5;
  *param_5 = 0;
  uVar1 = *(undefined8 *)(param_1 + 8);
  local_a8[0] = 0;
  local_a0 = param_3;
  local_90 = param_4;
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(uVar1,0);
  uVar7 = BfsAllocateBlock(*(longlong *)(param_1 + 8),(int *)local_a8);
  if ((int)uVar7 < 0) {
    ExReleasePushLockExclusiveEx(*(undefined8 *)(param_1 + 8),0);
    KeLeaveCriticalRegion();
    return uVar7 & 0xffffffff;
  }
  lVar10 = 0x100;
  puVar11 = (undefined4 *)0x0;
  bVar12 = false;
  plVar8 = (longlong *)ExAllocatePool2(0x100,0x20,0x4c736642);
  uVar4 = local_a8[0];
  if (plVar8 == (longlong *)0x0) {
    uVar7 = 0xc0000017;
    uVar6 = 0xc0000017;
    uVar5 = local_a8[0];
  }
  else {
    lVar10 = 0x100;
    puVar11 = (undefined4 *)ExAllocatePool2(0x100,0x4000,0x62736642);
    if (puVar11 == (undefined4 *)0x0) {
      uVar7 = 0xc0000017;
      uVar6 = 0xc0000017;
      uVar5 = local_a8[0];
    }
    else {
      plVar8[2] = (longlong)puVar11;
      *(uint *)(plVar8 + 3) = uVar4;
      lVar10 = *(longlong *)(param_1 + 0x10);
      plVar2 = *(longlong **)(lVar10 + 8);
      if (*plVar2 != lVar10) goto LAB_1400119f3;
      *plVar8 = lVar10;
      plVar8[1] = (longlong)plVar2;
      *plVar2 = (longlong)plVar8;
      *(longlong **)(lVar10 + 8) = plVar8;
      uVar7 = Feature_3544435002__private_IsEnabledDeviceUsageNoInline();
      bVar12 = (int)uVar7 != 0;
      memset(puVar11 + 1,0,0x3ffc);
      *puVar11 = 0x44736642;
      lVar10 = *(longlong *)(param_1 + 8);
      uVar6 = BfsWriteBlock(lVar10,uVar4,puVar11);
      uVar7 = (ulonglong)uVar6;
      uVar5 = local_a8[0];
      if (-1 < (int)uVar6) {
        lVar10 = *(longlong *)(param_1 + 8);
        uVar6 = BfsWriteBlock(lVar10,0,*(undefined8 *)(lVar10 + 0x10));
        uVar7 = (ulonglong)uVar6;
        uVar5 = local_a8[0];
        if (-1 < (int)uVar6) {
          *(uint *)(param_2 + 4) = uVar4;
          lVar10 = *(longlong *)(param_1 + 8);
          uVar6 = BfsWriteBlock(lVar10,*(int *)(local_a0 + 0x18),param_2);
          uVar7 = (ulonglong)uVar6;
          uVar5 = local_a8[0];
          if (-1 < (int)uVar6) {
            *local_98 = plVar8;
            *local_90 = puVar11;
            goto LAB_1400119ce;
          }
        }
      }
    }
  }
  local_a8[0] = uVar6;
  if (3 < DAT_140019000) {
    local_5c = 0;
    local_68 = local_a8;
    local_60 = 4;
    local_b0 = local_88;
    _tlgWriteTransfer_EtwWriteTransfer(lVar10,&DAT_140016d11);
    uVar5 = local_a8[0];
  }
  local_a8[0] = uVar5;
  BfsFreeBlock(*(longlong *)(param_1 + 8),uVar4);
  uVar9 = Feature_3544435002__private_IsEnabledDeviceUsageNoInline();
  if (((int)uVar9 != 0) && (*(uint *)(param_2 + 4) == uVar4)) {
    *(undefined4 *)(param_2 + 4) = 0;
  }
  if (plVar8 != (longlong *)0x0) {
    uVar9 = Feature_3544435002__private_IsEnabledDeviceUsageNoInline();
    if (((int)uVar9 != 0) && (bVar12)) {
      lVar10 = *plVar8;
      if ((*(longlong **)(lVar10 + 8) != plVar8) ||
         (plVar2 = (longlong *)plVar8[1], (longlong *)*plVar2 != plVar8)) {
LAB_1400119f3:
        pcVar3 = (code *)swi(0x29);
        (*pcVar3)(3);
        pcVar3 = (code *)swi(3);
        uVar7 = (*pcVar3)();
        return uVar7;
      }
      *plVar2 = lVar10;
      *(longlong **)(lVar10 + 8) = plVar2;
    }
    ExFreePoolWithTag(plVar8,0);
  }
  if (puVar11 != (undefined4 *)0x0) {
    ExFreePoolWithTag(puVar11,0);
  }
LAB_1400119ce:
  ExReleasePushLockExclusiveEx(*(undefined8 *)(param_1 + 8),0);
  KeLeaveCriticalRegion();
  return uVar7;
}



===== BfsFindEntry @ 140011a00 =====

longlong BfsFindEntry(longlong param_1,undefined8 param_2)

{
  longlong lVar1;
  bool bVar2;
  char cVar3;
  uint uVar4;
  uint uVar5;
  undefined8 *puVar6;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  
  uStack_30 = 0;
  local_38 = 0;
  local_34 = 0;
  puVar6 = (undefined8 *)**(undefined8 **)(param_1 + 0x10);
  do {
    if (puVar6 == *(undefined8 **)(param_1 + 0x10)) {
      return 0;
    }
    lVar1 = puVar6[2];
    RtlInitializeBitMap(&local_38,lVar1 + 0x3e60,0x1e);
    uVar4 = RtlFindSetBits(&local_38,1);
    do {
      if (uVar4 == 0xffffffff) break;
      local_28 = 0;
      uStack_20 = 0;
      RtlInitUnicodeString(&local_28,(ulonglong)uVar4 * 0x214 + 0x1c + lVar1);
      cVar3 = RtlEqualUnicodeString(&local_28,param_2,1);
      if (cVar3 != '\0') {
        return lVar1 + 8 + (ulonglong)uVar4 * 0x214;
      }
      if (0x1d < uVar4 + 1) break;
      uVar5 = RtlFindSetBits(&local_38,1,uVar4 + 1);
      bVar2 = uVar4 < uVar5;
      uVar4 = uVar5;
    } while (bVar2);
    puVar6 = (undefined8 *)*puVar6;
  } while( true );
}



===== BfsFreeBlock @ 140011b1c =====

undefined8 BfsFreeBlock(longlong param_1,undefined4 param_2)

{
  char cVar1;
  undefined8 uVar2;
  
  cVar1 = RtlTestBit(param_1 + 0x18);
  if (cVar1 == '\0') {
    uVar2 = 0xc0000001;
  }
  else {
    RtlClearBits(param_1 + 0x18,param_2,1);
    uVar2 = 0;
  }
  return uVar2;
}



===== BfsFreeDirectoryBlockList @ 140011b74 =====

void BfsFreeDirectoryBlockList(longlong *param_1)

{
  longlong *plVar1;
  longlong lVar2;
  code *pcVar3;
  
  while( true ) {
    plVar1 = (longlong *)*param_1;
    if (plVar1 == param_1) {
      return;
    }
    if (((longlong *)plVar1[1] != param_1) || (lVar2 = *plVar1, *(longlong **)(lVar2 + 8) != plVar1)
       ) break;
    *param_1 = lVar2;
    *(longlong **)(lVar2 + 8) = param_1;
    ExFreePoolWithTag(plVar1[2],0);
    ExFreePoolWithTag(plVar1);
  }
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  return;
}



===== BfsFreeTableEntry @ 140011be0 =====

void BfsFreeTableEntry(undefined8 param_1,undefined8 param_2)

{
  ExFreePoolWithTag(param_2,0);
  return;
}



===== BfsGetEntryBlock @ 140011c04 =====

undefined8 BfsGetEntryBlock(longlong param_1,longlong param_2,longlong *param_3,undefined4 *param_4)

{
  longlong lVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  undefined8 *puVar5;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  
  puVar5 = *(undefined8 **)(param_1 + 0x10);
  *param_3 = 0;
  *param_4 = 0;
  puVar5 = (undefined8 *)*puVar5;
  do {
    if (puVar5 == *(undefined8 **)(param_1 + 0x10)) {
      return 0xc0000225;
    }
    lVar1 = puVar5[2];
    if (lVar1 != 0) {
      uStack_20 = 0;
      local_28 = 0;
      uStack_24 = 0;
      RtlInitializeBitMap(&local_28,lVar1 + 0x3e60,0x1e);
      uVar3 = RtlFindSetBits(&local_28,1);
      while (uVar3 != 0xffffffff) {
        if (param_2 == (ulonglong)uVar3 * 0x214 + 8 + lVar1) {
          *param_4 = *(undefined4 *)(puVar5 + 3);
          *param_3 = lVar1;
          return 0;
        }
        if ((0x1d < uVar3 + 1) ||
           (uVar4 = RtlFindSetBits(&local_28,1,uVar3 + 1), bVar2 = uVar4 <= uVar3, uVar3 = uVar4,
           bVar2)) break;
      }
    }
    puVar5 = (undefined8 *)*puVar5;
  } while( true );
}



===== BfsGetEntryIndex @ 140011d14 =====

void BfsGetEntryIndex(longlong param_1,longlong param_2)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 uStack_10;
  
  uStack_10 = 0;
  local_18 = 0;
  local_14 = 0;
  RtlInitializeBitMap(&local_18,param_1 + 0x3e60,0x1e);
  uVar2 = RtlFindSetBits(&local_18,1);
  do {
    if (uVar2 == 0xffffffff) {
      return;
    }
    if (param_2 == (ulonglong)uVar2 * 0x214 + 8 + param_1) {
      return;
    }
    if (0x1d < uVar2 + 1) {
      return;
    }
    uVar3 = RtlFindSetBits(&local_18,1,uVar2 + 1);
    bVar1 = uVar2 < uVar3;
    uVar2 = uVar3;
  } while (bVar1);
  return;
}



===== BfsGetPathComponent @ 140011dc0 =====

ushort * BfsGetPathComponent(ushort *param_1,undefined8 *param_2,undefined8 *param_3)

{
  short sVar1;
  undefined8 uVar2;
  ushort uVar3;
  short sVar4;
  undefined8 local_18;
  
  local_18 = *param_2;
  uVar2 = param_2[1];
  sVar4 = 0;
  *(undefined8 *)param_1 = local_18;
  *(undefined8 *)(param_1 + 4) = uVar2;
  while( true ) {
    uVar3 = *param_1;
    local_18 = CONCAT62(local_18._2_6_,sVar4);
    if (uVar3 < 2) break;
    uVar3 = uVar3 - 2;
    sVar1 = **(short **)(param_1 + 4);
    *param_1 = uVar3;
    *(short **)(param_1 + 4) = *(short **)(param_1 + 4) + 1;
    if (sVar1 == 0x5c) break;
    sVar4 = sVar4 + 2;
  }
  param_1[1] = uVar3;
  *param_3 = local_18;
  param_3[1] = uVar2;
  return param_1;
}



===== BfsGetPathComponentEx @ 140011e28 =====

ushort * BfsGetPathComponentEx
                   (ushort *param_1,undefined8 *param_2,undefined8 param_3,undefined8 *param_4)

{
  short *psVar1;
  undefined8 uVar2;
  ushort uVar3;
  short sVar4;
  int iVar5;
  undefined8 local_18;
  
  local_18 = *param_2;
  uVar2 = param_2[1];
  sVar4 = 0;
  iVar5 = 2;
  *(undefined8 *)param_1 = local_18;
  *(undefined8 *)(param_1 + 4) = uVar2;
  do {
    uVar3 = *param_1;
    local_18 = CONCAT62(local_18._2_6_,sVar4);
    if (uVar3 < 2) {
LAB_140011e84:
      param_1[1] = uVar3;
      *param_4 = local_18;
      param_4[1] = uVar2;
      return param_1;
    }
    psVar1 = *(short **)(param_1 + 4);
    if (*psVar1 == 0x5c) {
      iVar5 = iVar5 + -1;
      if (iVar5 == 0) {
        uVar3 = uVar3 - 2;
        *(short **)(param_1 + 4) = psVar1 + 1;
        *param_1 = uVar3;
        goto LAB_140011e84;
      }
    }
    sVar4 = sVar4 + 2;
    *(short **)(param_1 + 4) = psVar1 + 1;
    *param_1 = uVar3 - 2;
  } while( true );
}



===== BfsInsertDirectory @ 140011ea0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 BfsInsertDirectory(longlong param_1,longlong param_2,longlong *param_3,longlong param_4)

{
  undefined8 *puVar1;
  longlong lVar2;
  undefined1 auStack_f8 [32];
  longlong local_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined4 local_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined8 uStack_50;
  longlong local_48;
  int local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_f8;
  memset(&local_d0,0,0x98);
  local_d8 = ExAllocatePool2(0x100,0x10,0x4e736642);
  if (local_d8 != 0) {
    lVar2 = ExAllocatePool2(0x100,*(undefined2 *)(param_2 + 2),0x4e736642);
    if (lVar2 != 0) {
      *(longlong *)(local_d8 + 8) = lVar2;
      *(undefined2 *)(local_d8 + 2) = *(undefined2 *)(param_2 + 2);
      RtlCopyUnicodeString(local_d8,param_2);
      local_48 = param_1 + -0x18;
      LOCK();
      *(int *)(param_1 + 0x78) = *(int *)(param_1 + 0x78) + 1;
      UNLOCK();
      LOCK();
      local_40 = local_40 + 1;
      UNLOCK();
      puVar1 = (undefined8 *)*param_3;
      local_d0 = *puVar1;
      uStack_c8 = puVar1[1];
      local_c0 = puVar1[2];
      uStack_b8 = puVar1[3];
      local_b0 = puVar1[4];
      uStack_a8 = puVar1[5];
      local_a0 = puVar1[6];
      uStack_98 = puVar1[7];
      local_90 = puVar1[8];
      uStack_88 = puVar1[9];
      local_80 = *(undefined4 *)(puVar1 + 10);
      uStack_7c = *(undefined4 *)((longlong)puVar1 + 0x54);
      uStack_78 = *(undefined4 *)(puVar1 + 0xb);
      uStack_74 = *(undefined4 *)((longlong)puVar1 + 0x5c);
      local_70 = puVar1[0xc];
      uStack_68 = puVar1[0xd];
      uStack_60 = *(undefined4 *)(puVar1 + 0xe);
      uStack_5c = *(undefined4 *)((longlong)puVar1 + 0x74);
      uStack_58 = *(undefined4 *)(puVar1 + 0xf);
      uStack_54 = *(undefined4 *)((longlong)puVar1 + 0x7c);
      uStack_50 = puVar1[0x10];
      lVar2 = RtlInsertElementGenericTableAvl(param_1 + 8,&local_d8,0xa0,param_4);
      *param_3 = lVar2 + 8;
      LOCK();
      *(int *)(lVar2 + 0x98) = *(int *)(lVar2 + 0x98) + 1;
      UNLOCK();
      if (param_4 == 0) {
        ExFreePoolWithTag(*(undefined8 *)(local_d8 + 8),0);
        ExFreePoolWithTag(local_d8,0);
        BfsDereferenceTableEntry((undefined8 *)(param_1 + -0x20));
      }
      return 0;
    }
    ExFreePoolWithTag(local_d8,0);
  }
  return 0xc0000017;
}



===== BfsInsertDirectoryEntry @ 140012058 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

longlong BfsInsertDirectoryEntry
                   (longlong param_1,int param_2,undefined4 param_3,int param_4,ushort *param_5)

{
  longlong *plVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  ulonglong uVar5;
  undefined4 *puVar6;
  undefined8 uVar7;
  longlong lVar8;
  longlong lVar9;
  ulonglong uVar10;
  longlong lVar11;
  longlong *plVar12;
  undefined1 auStackY_d8 [32];
  int local_a8;
  char local_a4;
  int local_a0 [2];
  longlong local_98;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 uStack_88;
  longlong *local_80;
  int local_78;
  undefined4 local_74;
  ushort *local_70;
  int *local_48;
  undefined8 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_d8;
  local_70 = param_5;
  uStack_88 = 0;
  local_90 = 0;
  local_8c = 0;
  local_a8 = param_4;
  local_78 = param_2;
  local_74 = param_3;
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(param_1,0);
  local_a0[0] = 0;
  bVar2 = false;
  local_a4 = '\0';
  puVar6 = (undefined4 *)0x0;
  lVar11 = ((longlong *)**(longlong **)(param_1 + 0x10))[2];
  local_80 = (longlong *)**(longlong **)(param_1 + 0x10);
LAB_1400120fe:
  local_98 = lVar11;
  do {
    plVar12 = local_80;
    RtlInitializeBitMap(&local_90,lVar11 + 0x3e60,0x1e);
    uVar3 = RtlFindClearBits(&local_90,1);
    if (uVar3 != 0xffffffff) break;
    plVar1 = (longlong *)*plVar12;
    if (plVar1 != (longlong *)*(longlong *)(param_1 + 0x10)) goto code_r0x0001400120f3;
    lVar9 = param_1;
    uVar5 = BfsExpandDirectory(param_1,lVar11,(longlong)plVar12,&local_98,&local_80);
    lVar11 = local_98;
    if ((int)uVar5 < 0) {
      if (3 < DAT_140019000) {
        local_48 = local_a0;
        local_40 = 4;
        local_a0[0] = (int)uVar5;
        _tlgWriteTransfer_EtwWriteTransfer(lVar9,&DAT_140016d11);
      }
      goto LAB_1400124e9;
    }
    RtlInitializeBitMap(&local_90,local_98 + 0x3e60,0x1e);
    uVar3 = RtlFindClearBits(&local_90,1);
    plVar12 = local_80;
  } while (uVar3 == 0xffffffff);
  uVar10 = (ulonglong)uVar3;
  local_98 = uVar10 * 0x214;
  lVar9 = local_98 + lVar11;
  RtlSetBits(&local_90,uVar10,1);
  uVar5 = Feature_3185813816__private_IsEnabledDeviceUsageNoInline();
  if (((int)uVar5 == 0) || (lVar8 = 0x1fe, *local_70 < 0x1ff)) {
    memset((void *)(local_98 + 0xc + lVar11),0,0x210);
    iVar4 = local_78;
    *(undefined4 *)(lVar9 + 0xc) = local_74;
    *(int *)(lVar9 + 8) = local_78;
    memmove((void *)(lVar9 + 0x1c),*(void **)(local_70 + 4),(ulonglong)*local_70);
    if (iVar4 != 2) {
      *(undefined4 *)(lVar9 + 0x10) = 0;
LAB_140012406:
      lVar8 = *(longlong *)(param_1 + 8);
      iVar4 = BfsWriteBlock(lVar8,(int)plVar12[3],lVar11);
      if (-1 < iVar4) {
        ExReleasePushLockExclusiveEx(param_1,0);
        KeLeaveCriticalRegion();
        return lVar9 + 8;
      }
      if (3 < DAT_140019000) {
        local_48 = &local_a8;
        local_40 = 4;
        local_a8 = iVar4;
        _tlgWriteTransfer_EtwWriteTransfer(lVar8,&DAT_140016d11);
      }
      bVar2 = false;
      puVar6 = (undefined4 *)0x0;
      if (local_a4 == '\0') goto LAB_140012498;
LAB_14001245c:
      puVar6 = (undefined4 *)0x0;
      uVar5 = Feature_329147705__private_IsEnabledDeviceUsageNoInline();
      if (((int)uVar5 != 0) && (!bVar2)) {
        uVar7 = *(undefined8 *)(param_1 + 8);
        KeEnterCriticalRegion();
        ExAcquirePushLockExclusiveEx(uVar7,0);
        bVar2 = true;
      }
      BfsFreeBlock(*(longlong *)(param_1 + 8),local_a0[0]);
      goto LAB_140012498;
    }
    lVar8 = 0x100;
    *(int *)(lVar9 + 0x10) = local_a8;
    puVar6 = (undefined4 *)ExAllocatePool2(0x100,0x4000,0x62736642);
    if (puVar6 == (undefined4 *)0x0) {
      if (DAT_140019000 < 4) goto LAB_140012498;
      local_a8 = -0x3fffffe9;
    }
    else {
      uVar7 = *(undefined8 *)(param_1 + 8);
      KeEnterCriticalRegion();
      ExAcquirePushLockExclusiveEx(uVar7,0);
      lVar8 = *(longlong *)(param_1 + 8);
      bVar2 = true;
      uVar7 = BfsAllocateBlock(lVar8,local_a0);
      if (-1 < (int)uVar7) {
        local_a4 = '\x01';
        memset(puVar6 + 1,0,0x3ffc);
        *puVar6 = 0x44736642;
        *(int *)(lVar9 + 0x14) = local_a0[0];
        local_a8 = BfsWriteBlock(*(longlong *)(param_1 + 8),local_a0[0],puVar6);
        ExFreePoolWithTag();
        iVar4 = local_a8;
        if (-1 < local_a8) {
          puVar6 = *(undefined4 **)(param_1 + 8);
          iVar4 = BfsWriteBlock((longlong)puVar6,0,*(undefined8 *)(puVar6 + 4));
          if (-1 < iVar4) {
            ExReleasePushLockExclusiveEx(*(undefined8 *)(param_1 + 8),0);
            KeLeaveCriticalRegion();
            goto LAB_140012406;
          }
        }
        if (3 < DAT_140019000) {
          local_48 = &local_a8;
          local_40 = 4;
          local_a8 = iVar4;
          _tlgWriteTransfer_EtwWriteTransfer(puVar6,&DAT_140016d11);
        }
        goto LAB_14001245c;
      }
      if (DAT_140019000 < 4) goto LAB_140012498;
      local_a8 = (int)uVar7;
    }
    local_48 = &local_a8;
  }
  else {
    if (DAT_140019000 < 4) goto LAB_140012498;
    local_48 = local_a0;
    local_a0[0] = -0x3ffffefa;
  }
  local_40 = 4;
  _tlgWriteTransfer_EtwWriteTransfer(lVar8,&DAT_140016d11);
LAB_140012498:
  RtlClearBits(&local_90,uVar10,1);
  if (puVar6 != (undefined4 *)0x0) {
    ExFreePoolWithTag(puVar6,0);
  }
  if (bVar2) {
    ExReleasePushLockExclusiveEx(*(undefined8 *)(param_1 + 8),0);
    KeLeaveCriticalRegion();
  }
LAB_1400124e9:
  ExReleasePushLockExclusiveEx(param_1,0);
  KeLeaveCriticalRegion();
  return 0;
code_r0x0001400120f3:
  lVar11 = plVar1[2];
  local_80 = plVar1;
  goto LAB_1400120fe;
}



===== BfsLocateDirectory @ 140012560 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 BfsLocateDirectory(longlong param_1,undefined8 param_2,longlong *param_3)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined1 auStack_e8 [32];
  undefined8 local_c8;
  undefined1 local_c0 [152];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_e8;
  memset(local_c0,0,0x98);
  uVar2 = 0;
  *param_3 = 0;
  KeEnterCriticalRegion();
  ExAcquirePushLockSharedEx(param_1,0);
  local_c8 = param_2;
  lVar1 = RtlLookupElementGenericTableAvl(param_1 + 8,&local_c8);
  if (lVar1 == 0) {
    uVar2 = 0xc0000225;
  }
  else {
    LOCK();
    *(int *)(lVar1 + 0x98) = *(int *)(lVar1 + 0x98) + 1;
    UNLOCK();
    *param_3 = lVar1 + 8;
  }
  ExReleasePushLockSharedEx(param_1,0);
  KeLeaveCriticalRegion();
  return uVar2;
}



===== BfsOpenRootDirectory @ 140012640 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint BfsOpenRootDirectory(longlong param_1)

{
  longlong *plVar1;
  undefined8 uVar2;
  code *pcVar3;
  uint uVar4;
  longlong lVar5;
  longlong *plVar6;
  longlong lVar7;
  undefined1 *puVar8;
  int iVar9;
  undefined1 auStack_98 [8];
  undefined1 auStack_90 [40];
  uint local_68 [2];
  undefined1 local_60 [32];
  uint *local_40;
  undefined4 local_38;
  undefined4 local_34;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_98;
  lVar7 = 0x100;
  iVar9 = *(int *)(*(longlong *)(param_1 + 0x10) + 0xc);
  lVar5 = ExAllocatePool2(0x100,0x10,0x48736642);
  *(longlong *)(param_1 + 0x40) = lVar5;
  puVar8 = auStack_98;
  if (lVar5 == 0) {
LAB_14001273b:
    uVar4 = 0xc0000017;
LAB_140012742:
    if (3 < DAT_140019000) {
      local_34 = 0;
      local_40 = local_68;
      local_68[0] = uVar4;
      *(undefined1 **)(puVar8 + 0x28) = local_60;
      local_38 = 4;
      *(undefined8 *)(puVar8 + -8) = 0x140012776;
      _tlgWriteTransfer_EtwWriteTransfer(lVar7,&DAT_140016d11);
    }
    plVar6 = *(longlong **)(param_1 + 0x40);
    if (plVar6 != (longlong *)0x0) {
      *(undefined8 *)(puVar8 + -8) = 0x140012784;
      BfsFreeDirectoryBlockList(plVar6);
      uVar2 = *(undefined8 *)(param_1 + 0x40);
      *(undefined8 *)(puVar8 + -8) = 0x140012791;
      ExFreePoolWithTag(uVar2,0);
    }
  }
  else {
    *(longlong *)(lVar5 + 8) = lVar5;
    *(longlong *)lVar5 = lVar5;
    do {
      lVar7 = 0x100;
      plVar6 = (longlong *)ExAllocatePool2(0x100,0x20,0x4c736642);
      puVar8 = auStack_98;
      if (plVar6 == (longlong *)0x0) goto LAB_14001273b;
      lVar7 = 0x100;
      lVar5 = ExAllocatePool2(0x100,0x4000,0x62736642);
      puVar8 = auStack_98;
      if (lVar5 == 0) goto LAB_14001273b;
      plVar6[2] = lVar5;
      *(int *)(plVar6 + 3) = iVar9;
      lVar7 = param_1;
      uVar4 = BfsReadBlock(param_1,iVar9,lVar5);
      puVar8 = auStack_98;
      if ((int)uVar4 < 0) goto LAB_140012742;
      lVar7 = *(longlong *)(param_1 + 0x40);
      plVar1 = *(longlong **)(lVar7 + 8);
      if (*plVar1 != lVar7) {
        lVar7 = 3;
        pcVar3 = (code *)swi(0x29);
        (*pcVar3)();
        puVar8 = auStack_90;
        goto LAB_14001273b;
      }
      *plVar6 = lVar7;
      plVar6[1] = (longlong)plVar1;
      *plVar1 = (longlong)plVar6;
      *(longlong **)(lVar7 + 8) = plVar6;
      iVar9 = *(int *)(lVar5 + 4);
    } while (iVar9 != 0);
    *(longlong *)(param_1 + 0x38) = param_1;
    puVar8 = auStack_98;
  }
  *(undefined8 *)(puVar8 + -8) = 0x1400127a4;
  return uVar4;
}



===== BfsReadBlock @ 1400127c4 =====

void BfsReadBlock(longlong param_1,int param_2,undefined8 param_3)

{
  ulonglong local_res8 [4];
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res8[0] = (ulonglong)(uint)(param_2 << 0xe);
  local_18 = 0;
  uStack_10 = 0;
  ZwReadFile(*(undefined8 *)(param_1 + 8),0,0,0,&local_18,param_3,0x4000,local_res8,0);
  return;
}



===== BfsWriteBlock @ 140012824 =====

void BfsWriteBlock(longlong param_1,int param_2,undefined8 param_3)

{
  ulonglong local_res8 [4];
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res8[0] = (ulonglong)(uint)(param_2 << 0xe);
  local_18 = 0;
  uStack_10 = 0;
  ZwWriteFile(*(undefined8 *)(param_1 + 8),0,0,0,&local_18,param_3,0x4000,local_res8,0);
  return;
}



===== Feature_3185813816__private_IsEnabledDeviceUsageNoInline @ 140012884 =====

ulonglong Feature_3185813816__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_3185813816__private_featureState;
  if ((Feature_3185813816__private_featureState & 0x10) == 0) {
    uVar1 = Feature_3185813816__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_3185813816__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_3185813816__private_IsEnabledFallback @ 1400128bc =====

void Feature_3185813816__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_3185813816__private_descriptor);
  return;
}



===== Feature_329147705__private_IsEnabledDeviceUsageNoInline @ 1400128d8 =====

ulonglong Feature_329147705__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_329147705__private_featureState;
  if ((Feature_329147705__private_featureState & 0x10) == 0) {
    uVar1 = Feature_329147705__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_329147705__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_329147705__private_IsEnabledFallback @ 140012910 =====

void Feature_329147705__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_329147705__private_descriptor);
  return;
}



===== Feature_3544435002__private_IsEnabledDeviceUsageNoInline @ 14001292c =====

ulonglong Feature_3544435002__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_3544435002__private_featureState;
  if ((Feature_3544435002__private_featureState & 0x10) == 0) {
    uVar1 = Feature_3544435002__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_3544435002__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_3544435002__private_IsEnabledFallback @ 140012964 =====

void Feature_3544435002__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_3544435002__private_descriptor);
  return;
}



===== Feature_819443003__private_IsEnabledDeviceUsageNoInline @ 140012980 =====

ulonglong Feature_819443003__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_819443003__private_featureState;
  if ((Feature_819443003__private_featureState & 0x10) == 0) {
    uVar1 = Feature_819443003__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_819443003__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_819443003__private_IsEnabledFallback @ 1400129b8 =====

void Feature_819443003__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_819443003__private_descriptor);
  return;
}



===== Feature_AppSiloBfsInsertEntryValidityCheck__private_IsEnabledDeviceUsageNoInline @ 1400129d4 =====

ulonglong Feature_AppSiloBfsInsertEntryValidityCheck__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_AppSiloBfsInsertEntryValidityCheck__private_featureState;
  if ((Feature_AppSiloBfsInsertEntryValidityCheck__private_featureState & 0x10) == 0) {
    uVar1 = Feature_AppSiloBfsInsertEntryValidityCheck__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_AppSiloBfsInsertEntryValidityCheck__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_AppSiloBfsInsertEntryValidityCheck__private_IsEnabledFallback @ 140012a0c =====

void Feature_AppSiloBfsInsertEntryValidityCheck__private_IsEnabledFallback
               (ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback
            (param_1,param_2,&Feature_AppSiloBfsInsertEntryValidityCheck__private_descriptor);
  return;
}



===== BfsFinalHash @ 140012a28 =====

void BfsFinalHash(longlong *param_1)

{
  if (*param_1 == 0) {
    *param_1 = -1;
  }
  return;
}



===== BfsInsertEntryHashTable @ 140012a40 =====

uint BfsInsertEntryHashTable(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  char cVar1;
  
  cVar1 = RtlInsertEntryHashTable(param_1,param_3,param_2,0);
  return ~-(uint)(cVar1 != '\0') & 0xc0000001;
}



===== BfsRemoveEntryHashTable @ 140012a74 =====

uint BfsRemoveEntryHashTable(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  
  cVar1 = RtlRemoveEntryHashTable(param_1,param_2,0);
  return ~-(uint)(cVar1 != '\0') & 0xc0000001;
}



===== BfsUpdateHash @ 140012aa0 =====

void BfsUpdateHash(byte *param_1,uint param_2,longlong *param_3)

{
  byte bVar1;
  ulonglong uVar2;
  
  if (param_2 != 0) {
    uVar2 = (ulonglong)param_2;
    do {
      bVar1 = *param_1;
      param_1 = param_1 + 1;
      *param_3 = *param_3 * 0x25 + (ulonglong)bVar1;
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  return;
}



===== BfsUpdateUnicodeStringHash @ 140012ac8 =====

void BfsUpdateUnicodeStringHash(ushort *param_1,longlong *param_2)

{
  byte *pbVar1;
  longlong lVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined2 local_res8 [4];
  
  uVar4 = 0;
  if ((*param_1 & 0xfffe) != 0) {
    do {
      local_res8[0] = RtlUpcaseUnicodeChar(*(undefined2 *)(*(longlong *)(param_1 + 4) + uVar4 * 2));
      lVar2 = 0;
      do {
        pbVar1 = (byte *)((longlong)local_res8 + lVar2);
        lVar2 = lVar2 + 1;
        *param_2 = (ulonglong)*pbVar1 + *param_2 * 0x25;
      } while (lVar2 < 2);
      uVar3 = (int)uVar4 + 1;
      uVar4 = (ulonglong)uVar3;
    } while (uVar3 < *param_1 >> 1);
  }
  return;
}



===== BfsCreatePolicyStorageDescriptor @ 140012b40 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint BfsCreatePolicyStorageDescriptor(undefined1 *param_1,undefined1 param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  ulonglong uVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined1 auStack_a8 [32];
  undefined8 local_88;
  undefined1 *local_80;
  uint local_78 [2];
  undefined1 local_70 [32];
  uint *local_50;
  undefined8 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_a8;
  puVar6 = (undefined1 *)0x0;
  puVar7 = param_1;
  uVar1 = RtlCreateSecurityDescriptor(param_1,1);
  if ((((int)uVar1 < 0) ||
      (puVar7 = param_1,
      uVar1 = RtlSetOwnerSecurityDescriptor
                        (param_1,*(undefined8 *)(*(longlong *)SeExports_exref + 0x108),0),
      (int)uVar1 < 0)) ||
     (puVar7 = param_1,
     uVar1 = RtlSetGroupSecurityDescriptor
                       (param_1,*(undefined8 *)(*(longlong *)SeExports_exref + 0x108),0),
     (int)uVar1 < 0)) {
LAB_140012c4e:
    if (3 < DAT_140019000) {
      local_50 = local_78;
      local_48 = 4;
      local_80 = local_70;
      local_78[0] = uVar1;
      _tlgWriteTransfer_EtwWriteTransfer(puVar7,&DAT_140016d11);
    }
    return uVar1;
  }
  iVar2 = RtlLengthSid(*(undefined8 *)(*(longlong *)SeExports_exref + 0x220));
  iVar3 = RtlLengthSid(*(undefined8 *)(*(longlong *)SeExports_exref + 0x108));
  puVar7 = (undefined1 *)0x100;
  iVar2 = iVar2 + iVar3 + 0x18;
  puVar4 = (undefined1 *)ExAllocatePool2(0x100,iVar2,0x41736642);
  if (puVar4 == (undefined1 *)0x0) {
    uVar1 = 0xc0000017;
    goto LAB_140012c4e;
  }
  puVar7 = param_1;
  uVar1 = RtlSetControlSecurityDescriptor(param_1,0x3000,0x3000);
  puVar8 = puVar4;
  if (((int)uVar1 < 0) || (puVar7 = puVar4, uVar1 = RtlCreateAcl(puVar4,iVar2,2), (int)uVar1 < 0)) {
LAB_140012d59:
    if (3 < DAT_140019000) {
      local_50 = local_78;
      local_48 = 4;
      local_80 = local_70;
      local_78[0] = uVar1;
      _tlgWriteTransfer_EtwWriteTransfer(puVar7,&DAT_140016d11);
    }
  }
  else {
    local_88 = *(undefined8 *)(*(longlong *)SeExports_exref + 0x220);
    puVar7 = puVar4;
    uVar1 = RtlAddAccessAllowedAceEx(puVar4,*puVar4,param_2,0x1f01ff);
    if ((int)uVar1 < 0) goto LAB_140012d59;
    local_88 = *(undefined8 *)(*(longlong *)SeExports_exref + 0x108);
    puVar7 = puVar4;
    uVar1 = RtlAddAccessAllowedAceEx(puVar4,*puVar4,param_2,0x1f01ff);
    if (((int)uVar1 < 0) ||
       (puVar7 = param_1, uVar1 = RtlSetDaclSecurityDescriptor(param_1,1,puVar4,0), (int)uVar1 < 0))
    goto LAB_140012d59;
    uVar5 = Feature_4176729402__private_IsEnabledDeviceUsageNoInline();
    puVar8 = (undefined1 *)0x0;
    if ((int)uVar5 == 0) {
      puVar8 = puVar4;
    }
    iVar2 = RtlLengthSid(*(undefined8 *)(*(longlong *)SeExports_exref + 0x1f0));
    puVar7 = (undefined1 *)0x100;
    puVar6 = (undefined1 *)ExAllocatePool2(0x100,iVar2 + 0x10,0x41736642);
    if (puVar6 == (undefined1 *)0x0) {
      uVar1 = 0xc0000017;
    }
    else {
      puVar7 = puVar6;
      uVar1 = RtlCreateAcl(puVar6,iVar2 + 0x10,2);
      if (-1 < (int)uVar1) {
        local_80 = (undefined1 *)CONCAT44(local_80._4_4_,7);
        local_88 = CONCAT71(local_88._1_7_,0x11);
        puVar7 = puVar6;
        uVar1 = RtlAddMandatoryAce(puVar6,2,param_2,
                                   *(undefined8 *)(*(longlong *)SeExports_exref + 0x1f0));
        if ((-1 < (int)uVar1) &&
           (uVar1 = RtlSetSaclSecurityDescriptor(param_1,1,puVar6,0), puVar7 = param_1,
           -1 < (int)uVar1)) {
          Feature_4176729402__private_IsEnabledDeviceUsageNoInline();
          return uVar1;
        }
      }
    }
    if (3 < DAT_140019000) {
      local_50 = local_78;
      local_48 = 4;
      local_80 = local_70;
      local_78[0] = uVar1;
      _tlgWriteTransfer_EtwWriteTransfer(puVar7,&DAT_140016d11);
    }
    if (puVar8 == (undefined1 *)0x0) goto LAB_140012eab;
  }
  ExFreePoolWithTag(puVar8,0);
LAB_140012eab:
  if (puVar6 == (undefined1 *)0x0) {
    return uVar1;
  }
  ExFreePoolWithTag(puVar6,0);
  return uVar1;
}



===== BfsUpdateSecurityDescriptor @ 140012ef8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint BfsUpdateSecurityDescriptor
               (undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,undefined4 param_4,
               undefined8 param_5,undefined4 param_6,char param_7)

{
  uint uVar1;
  undefined8 *puVar2;
  undefined1 auStack_e8 [32];
  undefined8 local_c8;
  undefined1 *local_c0;
  uint local_b8 [2];
  undefined8 local_b0;
  undefined4 local_a8 [2];
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined1 local_78 [32];
  uint *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_e8;
  local_a8[0] = 0;
  local_b0 = 0;
  local_80 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  local_90 = 0;
  uStack_88 = 0;
  puVar2 = param_3;
  local_b8[0] = RtlCreateAcl(param_3,param_4);
  if (-1 < (int)local_b8[0]) {
    local_c8 = param_5;
    if (param_7 == '\0') {
      puVar2 = param_3;
      local_b8[0] = RtlAddAccessDeniedAceEx(param_3,*(undefined1 *)param_3,0,param_6);
    }
    else {
      puVar2 = param_3;
      local_b8[0] = RtlAddAccessAllowedAceEx();
    }
    if ((int)local_b8[0] < 0) {
      if (DAT_140019000 < 4) {
        return local_b8[0];
      }
      goto LAB_140012f6e;
    }
    puVar2 = param_2;
    local_b8[0] = RtlGetAce(param_2,0,&local_b0);
    if (-1 < (int)local_b8[0]) {
      local_b8[0] = RtlGetAcesBufferSize(param_2,local_a8);
      puVar2 = param_2;
      if (-1 < (int)local_b8[0]) {
        local_c8 = CONCAT44(local_c8._4_4_,local_a8[0]);
        puVar2 = param_3;
        local_b8[0] = RtlAddAce(param_3,2,1,local_b0);
        if (-1 < (int)local_b8[0]) {
          puVar2 = &local_a0;
          local_b8[0] = RtlCreateSecurityDescriptor(puVar2,1);
          if (-1 < (int)local_b8[0]) {
            puVar2 = &local_a0;
            local_b8[0] = RtlSetDaclSecurityDescriptor(puVar2,1,param_3,0);
            if (-1 < (int)local_b8[0]) {
              local_b8[0] = ZwSetSecurityObject(param_1,4,&local_a0);
              puVar2 = param_1;
              if (-1 < (int)local_b8[0]) {
                return 0;
              }
            }
          }
        }
      }
    }
  }
  if (DAT_140019000 < 4) {
    return local_b8[0];
  }
LAB_140012f6e:
  uVar1 = local_b8[0];
  local_4c = 0;
  local_58 = local_b8;
  local_c0 = local_78;
  local_50 = 4;
  _tlgWriteTransfer_EtwWriteTransfer(puVar2,&DAT_140016d11);
  return uVar1;
}



===== Feature_4176729402__private_IsEnabledDeviceUsageNoInline @ 1400130d8 =====

ulonglong Feature_4176729402__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_4176729402__private_featureState;
  if ((Feature_4176729402__private_featureState & 0x10) == 0) {
    uVar1 = Feature_4176729402__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_4176729402__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_4176729402__private_IsEnabledFallback @ 140013110 =====

void Feature_4176729402__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_4176729402__private_descriptor);
  return;
}



===== BfsPromptForConsent @ 14001312c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint BfsPromptForConsent(undefined1 *param_1,undefined8 param_2,undefined8 param_3,
                        undefined8 param_4,undefined1 *param_5)

{
  bool bVar1;
  uint uVar2;
  undefined **ppuVar3;
  uint uVar4;
  undefined1 auStack_198 [32];
  wchar_t *local_178;
  undefined1 *local_170;
  undefined8 local_168;
  undefined8 local_160;
  undefined4 local_158;
  int *local_150;
  undefined1 local_148;
  undefined8 local_140;
  uint local_138;
  CLIENT_CALL_RETURN local_130;
  RPC_BINDING_HANDLE local_128;
  undefined4 local_120;
  undefined8 local_11c;
  undefined4 local_114;
  undefined4 local_110;
  undefined4 local_10c;
  undefined8 local_108;
  undefined4 *local_100;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  int local_c0 [2];
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined8 local_9c;
  undefined8 uStack_94;
  undefined8 local_8c;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined1 local_70 [32];
  undefined8 *local_50;
  undefined8 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_198;
  local_9c = 0;
  uStack_94 = 0;
  local_8c = 0;
  local_84 = 0;
  bVar1 = false;
  local_ac = 0;
  local_11c = 0;
  local_114 = 0;
  local_108 = 0;
  local_e8 = 0;
  uStack_e0 = 0;
  local_d0 = 0;
  uStack_c8 = 0;
  uVar4 = 0;
  local_c0[0] = 1;
  *param_5 = 0;
  local_128 = (RPC_BINDING_HANDLE)0x0;
  local_a8 = 1;
  local_a4 = 1;
  local_a0 = 3;
  local_80 = 0x10d20e7a;
  uStack_7c = 0x494a2530;
  uStack_78 = 0xddb801ac;
  uStack_74 = 0xd20a4804;
  local_f8 = 5;
  local_f0 = 0;
  local_ec = 3;
  local_f4 = 0x11;
  local_d8 = *(undefined8 *)(*(longlong *)SeExports_exref + 0x108);
  local_120 = 1;
  local_110 = 6;
  local_10c = 0x14;
  local_100 = &local_f8;
  local_b8 = 1;
  local_b4 = 2;
  local_b0 = 5;
  ppuVar3 = (undefined **)&local_a8;
  local_140 = param_4;
  uVar2 = RpcBindingCreateW(ppuVar3,&local_120,&local_b8,&local_128);
  if (uVar2 == 0) {
LAB_1400132b2:
    ppuVar3 = (undefined **)0x0;
    uVar2 = RpcBindingBind(0,local_128,&DAT_140016650);
    if (uVar2 != 0) {
      if ((int)uVar2 < 1) {
        uVar4 = uVar2;
      }
      else {
        uVar4 = uVar2 & 0xffff | 0xc0070000;
      }
      if ((int)uVar4 < 0) goto LAB_1400133ce;
    }
    bVar1 = true;
    local_148 = 1;
    local_130.Pointer = (void *)0x0;
    local_150 = local_c0;
    local_158 = (undefined4)local_140;
    local_178 = L"appSiloFileSystem";
    ppuVar3 = &PTR_PTR_140016620;
    local_170 = param_1;
    local_168 = param_2;
    local_160 = param_3;
    local_130 = NdrClientCall3((MIDL_STUBLESS_PROXY_INFO *)&PTR_PTR_140016620,0,(void *)0x0);
    uVar2 = (uint)local_130.Simple;
    if (uVar2 != 0) {
      if ((int)uVar2 < 1) {
        uVar4 = uVar2;
      }
      else {
        uVar4 = uVar2 & 0xffff | 0xc0070000;
      }
      local_138 = uVar4;
      if ((int)uVar4 < 0) {
        if (3 < DAT_140019000) {
          local_140 = CONCAT44(local_140._4_4_,uVar4);
          local_50 = &local_140;
          local_48 = 4;
          local_170 = local_70;
          _tlgWriteTransfer_EtwWriteTransfer(ppuVar3,&DAT_140016d11);
        }
        goto LAB_14001340d;
      }
    }
    if (local_c0[0] == 0) {
      *param_5 = 1;
    }
    if (-1 < (int)uVar4) goto LAB_14001340d;
  }
  else {
    if ((int)uVar2 < 1) {
      uVar4 = uVar2;
    }
    else {
      uVar4 = uVar2 & 0xffff | 0xc0070000;
    }
    if (-1 < (int)uVar4) goto LAB_1400132b2;
  }
LAB_1400133ce:
  if (3 < DAT_140019000) {
    local_50 = &local_140;
    local_170 = local_70;
    local_140 = CONCAT44(local_140._4_4_,uVar4);
    local_48 = 4;
    _tlgWriteTransfer_EtwWriteTransfer(ppuVar3,&DAT_140016d11);
  }
LAB_14001340d:
  if (local_128 != (RPC_BINDING_HANDLE)0x0) {
    if (bVar1) {
      RpcBindingUnbind();
    }
    RpcBindingFree(&local_128);
  }
  return uVar4;
}



===== MIDL_user_allocate @ 140013470 =====

void * __stdcall MIDL_user_allocate(size_t size)

{
  void *pvVar1;
  
  pvVar1 = (void *)ExAllocatePool2(0x100,size,0x72736642);
  return pvVar1;
}



===== MIDL_user_free @ 1400134a0 =====

void __stdcall MIDL_user_free(void *param_1)

{
  ExFreePoolWithTag(param_1,0);
  return;
}



===== _guard_check_icall @ 1400134d0 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 1400134e8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 14001350c =====

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



===== __GSHandlerCheck_SEH @ 140013574 =====

void __GSHandlerCheck_SEH
               (_EXCEPTION_RECORD *param_1,void *param_2,_CONTEXT *param_3,
               _DISPATCHER_CONTEXT *param_4)

{
  uint uVar1;
  uint *puVar2;
  
  puVar2 = *(uint **)(param_4 + 0x38);
  uVar1 = *puVar2;
  __GSHandlerCheckCommon(param_2,(longlong)param_4);
  if ((puVar2[(ulonglong)uVar1 * 4 + 1] & ((param_1->ExceptionFlags & 0x66) != 0) + 1) != 0) {
    __C_specific_handler(param_1,param_2,param_3,param_4);
  }
  return;
}



===== __cpu_features_init @ 140013610 =====

/* WARNING: Removing unreachable block (ram,0x00014001367a) */
/* WARNING: Removing unreachable block (ram,0x000140013629) */
/* WARNING: Removing unreachable block (ram,0x00014001361a) */

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



===== __security_check_cookie @ 1400136e0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140013720 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 140013750 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140013750. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140013780 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memmove @ 140013800 =====

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



===== memset @ 140013b00 =====

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



===== __memset_repmovs @ 140013c40 =====

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



===== __memset_query @ 140013cc0 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140013d40 =====

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



===== __memset_spec_ermsb_repmovsb @ 140013e80 =====

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



===== __memset_spec_plain @ 140013f00 =====

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



===== BfsPromptForConsent$filt$0 @ 140013ffd =====

void BfsPromptForConsent_filt_0(undefined8 *param_1)

{
  RpcExceptionFilter(*(undefined4 *)*param_1);
  return;
}



===== BfsGetRootDirectory @ 14001e008 =====

undefined8 BfsGetRootDirectory(void)

{
  return gBfsRootDirectory;
}



===== BfsUnload @ 14001e020 =====

undefined8 BfsUnload(void)

{
  undefined8 uVar1;
  ulonglong uVar2;
  undefined *puVar3;
  undefined8 *puVar4;
  
  KeEnterCriticalRegion();
  ExWaitForRundownProtectionRelease(&gBfsRundownProtection);
  KeLeaveCriticalRegion();
  if (gBfsRootDirectory != 0) {
    ZwClose();
  }
  uVar2 = Feature_2603245880__private_IsEnabledDeviceUsageNoInline();
  if (((int)uVar2 == 0) && (gBfsDeviceObject != 0)) {
    IoDeleteDevice();
  }
  if (gBfsSHA256Handle != (BCRYPT_ALG_HANDLE)0x0) {
    BCryptCloseAlgorithmProvider(gBfsSHA256Handle,0);
  }
  if (DAT_140019228 != 0) {
    ExFreePoolWithTag(DAT_140019228,0);
  }
  if (DAT_140019220 != 0) {
    ExFreePoolWithTag(DAT_140019220,0);
  }
  if (DAT_140019200 != 0) {
    ExFreePoolWithTag(DAT_140019200,0);
  }
  if (DAT_1400191f8 != 0) {
    ExFreePoolWithTag(DAT_1400191f8,0);
  }
  puVar3 = BfsGetPolicyTable();
  if (puVar3 != (undefined *)0x0) {
    BfsUninitializePolicyTable((longlong)puVar3);
  }
  puVar4 = (undefined8 *)BfsGetPipeNameMappingTable();
  if (puVar4 != (undefined8 *)0x0) {
    BfsUninitializePipeMappingTable(puVar4);
  }
  uVar2 = Feature_Servicing_BfsGAFeature__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar2 != 0) {
    BfsUninitializeGlobalFileTable();
  }
  RtlFreeUnicodeString(&gBfsBootDevice);
  FltUnregisterFilter(gBfsFilterHandle);
  CmUnRegisterCallback(gBfsRegistryCookie);
  uVar2 = Feature_2603245880__private_IsEnabledDeviceUsageNoInline();
  if (((int)uVar2 != 0) && (gBfsDeviceObject != 0)) {
    IoDeleteDevice();
  }
  wil_UninitializeFeatureStaging();
  uVar1 = DAT_140019020;
  DAT_140019020 = 0;
  DAT_140019000 = 0;
  EtwUnregister(uVar1);
  return 0;
}



===== BfsVerifyVolumeRootDescriptor @ 14001e1cc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint BfsVerifyVolumeRootDescriptor(void)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined8 *******pppppppuVar4;
  undefined8 *******pppppppuVar5;
  undefined8 *******pppppppuVar6;
  undefined1 auStackY_128 [32];
  uint local_f8;
  char local_f4;
  char local_f3;
  char local_f2 [2];
  undefined4 local_f0;
  undefined8 *******local_e8;
  undefined4 local_e0 [2];
  undefined8 *******local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined8 local_b0;
  undefined8 *local_a8;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 ******local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  uint *local_30;
  undefined8 local_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStackY_128;
  local_e0[0] = 0;
  local_f3 = '\0';
  local_e8 = (undefined8 *******)0x0;
  local_f4 = '\0';
  local_f2[0] = '\0';
  local_d0 = 0;
  local_f0 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_68 = 0;
  local_88 = (undefined8 ******)0x0;
  uStack_80 = 0;
  local_b4 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_9c = 0;
  local_c8 = 0;
  uStack_c0 = 0;
  local_d8 = (undefined8 *******)0x0;
  RtlInitUnicodeString(&local_c8,L"\\Device\\BootDevice\\");
  local_a8 = &local_c8;
  local_b8 = 0x30;
  local_b0 = 0;
  local_a0 = 0x200;
  pppppppuVar6 = &local_d8;
  local_98 = 0;
  uStack_90 = 0;
  uVar3 = ZwOpenFile(pppppppuVar6,0x60000,&local_b8);
  if ((-1 < (int)uVar3) &&
     (pppppppuVar6 = local_d8, uVar3 = ZwQuerySecurityObject(local_d8,4,0), uVar2 = local_f0,
     uVar3 == 0xc0000023)) {
    pppppppuVar6 = (undefined8 *******)0x100;
    pppppppuVar4 = (undefined8 *******)ExAllocatePool2(0x100,local_f0,0x44736642);
    if (pppppppuVar4 != (undefined8 *******)0x0) {
      pppppppuVar6 = local_d8;
      uVar3 = ZwQuerySecurityObject(local_d8,4,pppppppuVar4,uVar2);
      if (((int)uVar3 < 0) ||
         (pppppppuVar6 = pppppppuVar4,
         uVar3 = RtlGetDaclSecurityDescriptor(pppppppuVar4,&local_f4,&local_e8,local_f2),
         (int)uVar3 < 0)) {
LAB_14001e394:
        if (3 < DAT_140019000) {
          local_30 = &local_f8;
          local_28 = 4;
          local_f8 = uVar3;
          _tlgWriteTransfer_EtwWriteTransfer(pppppppuVar6,&DAT_140016d11);
        }
      }
      else if ((local_f4 != '\0') && (local_e8 != (undefined8 *******)0x0)) {
        pppppppuVar6 = local_e8;
        uVar3 = BfsVerifyAce((longlong)local_e8,'\0','\0',0x1000a1,
                             *(undefined8 *)(*(longlong *)SeExports_exref + 0x238),&local_f3);
        if ((int)uVar3 < 0) goto LAB_14001e394;
        if (local_f3 != '\0') goto LAB_14001e601;
        pppppppuVar6 = (undefined8 *******)0x100;
        iVar1 = *(ushort *)((longlong)local_e8 + 2) + 0x10 +
                (uint)*(byte *)(*(longlong *)(*(longlong *)SeExports_exref + 0x238) + 1) * 4;
        pppppppuVar5 = (undefined8 *******)ExAllocatePool2(0x100,iVar1,0x41736642);
        if (pppppppuVar5 == (undefined8 *******)0x0) {
          uVar3 = 0xc0000017;
          goto LAB_14001e394;
        }
        pppppppuVar6 = pppppppuVar5;
        uVar3 = RtlCreateAcl(pppppppuVar5,iVar1,*(undefined1 *)local_e8);
        if (((((int)uVar3 < 0) ||
             (pppppppuVar6 = pppppppuVar5,
             uVar3 = RtlAddAccessAllowedAceEx(pppppppuVar5,*(undefined1 *)pppppppuVar5,0,0x1000a1),
             (int)uVar3 < 0)) ||
            (pppppppuVar6 = local_e8, uVar3 = RtlGetAce(local_e8,0,&local_d0), (int)uVar3 < 0)) ||
           ((pppppppuVar6 = local_e8, uVar3 = RtlGetAcesBufferSize(local_e8,local_e0),
            (int)uVar3 < 0 ||
            (pppppppuVar6 = pppppppuVar5, uVar3 = RtlAddAce(pppppppuVar5,2,1,local_d0),
            (int)uVar3 < 0)))) {
LAB_14001e5c1:
          if (3 < DAT_140019000) {
            local_30 = &local_f8;
            local_28 = 4;
            local_f8 = uVar3;
            _tlgWriteTransfer_EtwWriteTransfer(pppppppuVar6,&DAT_140016d11);
          }
        }
        else {
          pppppppuVar6 = &local_88;
          uVar3 = RtlCreateSecurityDescriptor(pppppppuVar6,1);
          if ((int)uVar3 < 0) goto LAB_14001e5c1;
          pppppppuVar6 = &local_88;
          uVar3 = RtlSetDaclSecurityDescriptor(pppppppuVar6,1,pppppppuVar5,0);
          if (((int)uVar3 < 0) ||
             (pppppppuVar6 = local_d8, uVar3 = ZwSetSecurityObject(local_d8,4,&local_88),
             (int)uVar3 < 0)) goto LAB_14001e5c1;
        }
        ExFreePoolWithTag(pppppppuVar5,0);
      }
LAB_14001e601:
      ExFreePoolWithTag(pppppppuVar4,0);
      goto LAB_14001e612;
    }
    uVar3 = 0xc0000017;
  }
  if (3 < DAT_140019000) {
    local_28 = 4;
    local_30 = &local_f8;
    local_f8 = uVar3;
    _tlgWriteTransfer_EtwWriteTransfer(pppppppuVar6,&DAT_140016d11);
  }
LAB_14001e612:
  if (local_d8 != (undefined8 *******)0x0) {
    ZwClose();
  }
  return uVar3;
}



===== TraceLoggingRegisterEx_EtwRegister_EtwSetInformation @ 14001e65c =====

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
  local_28 = *(undefined4 *)(PTR_DAT_140019008 + -0x10);
  uStack_24 = *(undefined4 *)(PTR_DAT_140019008 + -0xc);
  uStack_20 = *(undefined4 *)(PTR_DAT_140019008 + -8);
  uStack_1c = *(undefined4 *)(PTR_DAT_140019008 + -4);
  if (DAT_140019020 != 0) {
    pcVar2 = (code *)swi(0x29);
    (*pcVar2)(5);
    puVar4 = auStack_40;
  }
  _DAT_140019028 = 0;
  uRam0000000140019030 = 0;
  *(undefined8 *)(puVar4 + -8) = 0x14001e6bf;
  iVar3 = EtwRegister(puVar4 + 0x20,_tlgEnableCallback,&DAT_140019000,&DAT_140019020);
  if (iVar3 == 0) {
    uVar1 = *(undefined2 *)PTR_DAT_140019008;
    *(undefined8 *)(puVar4 + -8) = 0x14001e6e6;
    EtwSetInformation(DAT_140019020,2,PTR_DAT_140019008,uVar1);
  }
  *(undefined8 *)(puVar4 + -8) = 0x14001e6fa;
  return iVar3;
}



===== _tlgEnableCallback @ 14001e710 =====

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



===== wil_RtlStagingConfig_QueryFeatureState @ 14001e78c =====

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



===== wil_UninitializeFeatureStaging @ 14001e858 =====

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



===== wil_details_BuildFeatureStateCacheFromQueryResults @ 14001e8b0 =====

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
      goto LAB_14001e90d;
    }
    if (param_1 == 0x117) {
      uVar1 = (*(uint *)(param_2 + 4) & 0x80) << 3 | 0x206;
      goto LAB_14001e90d;
    }
  }
  uVar1 = 0x206;
LAB_14001e90d:
  *param_3 = uVar1;
  return;
}



===== wil_details_EvaluateFeatureDependencies @ 14001e918 =====

void wil_details_EvaluateFeatureDependencies(void)

{
  longlong *plVar1;
  undefined **ppuVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  bool bVar6;
  
  plVar1 = wil_details_FeatureDescriptors_SkipPadding((longlong *)&wil_details_featureDescriptors_a)
  ;
  if (plVar1 != (longlong *)0x0) {
    uVar4 = 0;
    uVar5 = 0x180;
    do {
      uVar3 = *(uint *)*plVar1;
      if ((uVar3 >> 9 & 1) != 0) {
        if (((uint)uVar5 & uVar3) == 0) {
          bVar6 = *(char *)((longlong)plVar1 + 0x1f) != '\0';
        }
        else {
          bVar6 = (uVar3 & (uint)uVar5) == 0x100;
        }
        uVar3 = uVar3 & 0x40 ^ (uint)bVar6 << 6 | (uint)uVar4 & 0xffffffbf;
        uVar4 = (ulonglong)uVar3;
        LOCK();
        *(uint *)*plVar1 = *(uint *)*plVar1 ^ uVar3;
        UNLOCK();
      }
      plVar1 = wil_details_FeatureDescriptors_SkipPadding(plVar1 + 7);
    } while (plVar1 != (longlong *)0x0);
  }
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



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 14001e9d0 =====

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



===== wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState @ 14001ea08 =====

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
        if (puVar1 == (undefined8 *)0x0) goto LAB_14001ea8a;
        if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
           (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
        if ((uVar5 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
          uVar5 = 0;
          goto LAB_14001ea8a;
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
LAB_14001ea8a:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 14001eae0 =====

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



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 14001eb40 =====

void wil_details_ReevaluateOnFeatureConfigurationChange(void)

{
  wil_details_UpdateFeatureConfiguredStates();
  wil_details_EvaluateFeatureDependencies();
  return;
}



===== wil_details_UpdateFeatureConfiguredStates @ 14001eb5c =====

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



===== KappxParsePackageFullNameFromToken @ 14001ec10 =====

ulonglong KappxParsePackageFullNameFromToken(ushort *param_1,undefined8 param_2,short *param_3)

{
  ushort uVar1;
  void *_Dst;
  ulonglong uVar2;
  ulonglong uVar3;
  void *pvVar4;
  ushort uVar5;
  uint uVar6;
  short *psVar7;
  void *pvVar8;
  
  uVar2 = 0;
  _Dst = (void *)ExAllocatePool2(0x100,*param_1,0x58707041);
  if (_Dst == (void *)0x0) {
    uVar2 = 0xc0000017;
  }
  else {
    memmove(_Dst,*(void **)(param_1 + 4),(ulonglong)*param_1);
    uVar5 = *param_1 >> 1;
    pvVar8 = _Dst;
    for (uVar6 = 0; uVar6 < 5; uVar6 = uVar6 + 1) {
      pvVar4 = pvVar8;
      uVar1 = KappxSafeSearch((longlong)pvVar8,uVar5,0x5f);
      if ((uVar1 == uVar5) && (uVar6 != 4)) {
        uVar2 = 0x80000005;
        break;
      }
      if (uVar6 == 0) {
LAB_14001ecbb:
        psVar7 = (short *)0x0;
LAB_14001ecbe:
        uVar3 = KappxParseString(pvVar4,uVar1,psVar7);
        uVar2 = uVar3 & 0xffffffff;
        if ((int)uVar3 < 0) break;
      }
      else {
        if ((uVar6 != 1) && (uVar6 != 2)) {
          if (uVar6 == 3) goto LAB_14001ecbb;
          if (uVar6 != 4) {
            return 0xffffffff;
          }
          psVar7 = param_3;
          goto LAB_14001ecbe;
        }
        uVar2 = 0;
      }
      pvVar8 = (void *)((longlong)pvVar8 + (ulonglong)uVar1 * 2 + 2);
      uVar5 = uVar5 + (-1 - uVar1);
    }
    ExFreePoolWithTag(_Dst,0x58707041);
  }
  return uVar2;
}



===== KappxParseString @ 14001ed24 =====

undefined8 KappxParseString(void *param_1,ushort param_2,short *param_3)

{
  ushort uVar1;
  short sVar2;
  
  if (param_3 != (short *)0x0) {
    sVar2 = param_2 * 2;
    uVar1 = sVar2 + 2;
    if (*(void **)(param_3 + 4) == (void *)0x0) {
      param_3[1] = uVar1;
    }
    else {
      if ((ushort)param_3[1] < uVar1) {
        return 0xc000000d;
      }
      memmove(*(void **)(param_3 + 4),param_1,(ulonglong)param_2 * 2);
      if (uVar1 < 3) {
        sVar2 = 0;
      }
      *(undefined2 *)((ulonglong)param_2 * 2 + *(longlong *)(param_3 + 4)) = 0;
      *param_3 = sVar2;
    }
  }
  return 0;
}



===== KappxSafeSearch @ 14001edc0 =====

void KappxSafeSearch(longlong param_1,ushort param_2,short param_3)

{
  ushort uVar1;
  
  uVar1 = 0;
  while( true ) {
    if (param_2 <= uVar1) {
      return;
    }
    if (*(short *)(param_1 + (ulonglong)uVar1 * 2) == param_3) break;
    uVar1 = uVar1 + 1;
  }
  *(undefined2 *)(param_1 + (ulonglong)uVar1 * 2) = 0;
  return;
}



===== entry @ 14001f010 =====

void entry(undefined *param_1)

{
  __security_init_cookie();
  DriverEntry(param_1);
  return;
}



===== __security_init_cookie @ 14001f044 =====

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



===== DriverEntry @ 14001f078 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint DriverEntry(undefined *param_1)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  uint uVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  code *pcVar7;
  longlong *plVar8;
  undefined *puVar9;
  wchar_t *pwVar10;
  code *pcVar11;
  undefined1 auStack_e8 [32];
  undefined8 *local_c8;
  undefined1 *local_c0;
  longlong *local_b8;
  uint local_a8;
  char local_a4 [4];
  code *local_a0;
  longlong local_98;
  wchar_t local_90 [8];
  longlong local_80 [4];
  undefined1 local_60 [32];
  uint *local_40;
  undefined8 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_e8;
  local_90[0] = L'\0';
  local_90[1] = L'\0';
  local_90[2] = L'\0';
  local_90[3] = L'\0';
  local_90[4] = L'\0';
  local_90[5] = L'\0';
  local_90[6] = L'\0';
  local_90[7] = L'\0';
  local_80[2] = 0;
  local_80[3] = 0;
  local_80[0] = 0;
  local_80[1] = 0;
  pcVar7 = (code *)param_1;
  wil_InitializeFeatureStaging();
  pcVar11 = (code *)0x0;
  local_a0 = (code *)0x0;
  local_98 = 0;
  bVar3 = false;
  bVar1 = false;
  bVar2 = false;
  local_a4[0] = '\0';
  uVar4 = BfsVerifyVolumeRootDescriptor();
  if ((int)uVar4 < 0) {
LAB_14001f40a:
    bVar1 = bVar3;
    if (DAT_140019000 < 4) goto LAB_14001f43b;
    local_a8 = uVar4;
  }
  else {
    pcVar7 = (code *)&gBfsPolicyStorageDirectoryDescriptor;
    uVar4 = BfsCreatePolicyStorageDescriptor(&gBfsPolicyStorageDirectoryDescriptor,3);
    if ((int)uVar4 < 0) goto LAB_14001f40a;
    pcVar7 = (code *)&gBfsPolicyStorageFileDescriptor;
    uVar4 = BfsCreatePolicyStorageDescriptor(&gBfsPolicyStorageFileDescriptor,0);
    if ((int)uVar4 < 0) goto LAB_14001f40a;
    ExInitializeRundownProtection(&gBfsRundownProtection);
    pcVar7 = (code *)local_80;
    RtlInitUnicodeString(pcVar7,L"\\SystemRoot\\System32\\config\\BFS");
    uVar5 = BfsInitializePolicyTable((longlong)pcVar7);
    uVar4 = (uint)uVar5;
    if ((int)uVar4 < 0) goto LAB_14001f40a;
    uVar5 = BfsInitializePipeMappingTable((longlong)pcVar7);
    uVar4 = (uint)uVar5;
    if ((int)uVar4 < 0) goto LAB_14001f40a;
    plVar8 = local_80;
    uVar4 = BfsOpenPolicyRootDirectory(plVar8,&local_a0);
    pcVar11 = local_a0;
    if ((int)uVar4 < 0) {
      if (3 < DAT_140019000) {
        local_40 = &local_a8;
        local_38 = 4;
        local_c0 = local_60;
        local_a8 = uVar4;
        _tlgWriteTransfer_EtwWriteTransfer(plVar8,&DAT_140016d11);
      }
      pcVar11 = local_a0;
      goto LAB_14001f43b;
    }
    uVar4 = BfsVerifyPolicySecurity((longlong)local_a0,local_a4);
    uVar6 = Feature_Servicing_BfsGAFeature__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar6 != 0) {
      gBfsDeleteThreshold = BfsReadDeleteThresholdFromRegistry();
    }
    if ((((int)uVar4 < 0) || (local_a4[0] != '\0')) &&
       (pcVar7 = pcVar11, uVar4 = BfsUpdatePolicySecurity(pcVar11), (int)uVar4 < 0))
    goto LAB_14001f40a;
    pcVar7 = (code *)&gBfsBootDevice;
    uVar4 = BfsInitializeBootDevice((undefined4 *)&gBfsBootDevice);
    if ((int)uVar4 < 0) goto LAB_14001f40a;
    uVar6 = Feature_Servicing_BfsGAFeature__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar6 != 0) {
      KeInitializeEvent(&DAT_1400191a0,0,0);
    }
    *(code **)(param_1 + 0x70) = BfsClose;
    *(code **)(param_1 + 0x100) = BfsClose;
    *(code **)(param_1 + 0xe0) = BfsDeviceIoControl;
    *(code **)(param_1 + 0x80) = BfsClose;
    RtlInitUnicodeString(local_80 + 2,L"\\Device\\Bfs");
    pcVar7 = (code *)&gBfsSHA256Handle;
    uVar4 = BCryptOpenAlgorithmProvider(&gBfsSHA256Handle,L"SHA256",(LPCWSTR)0x0,0);
    if ((int)uVar4 < 0) goto LAB_14001f40a;
    uVar6 = Feature_Servicing_BfsGAFeature__private_IsEnabledDeviceUsageNoInline();
    puVar9 = &FilterRegistrationGA;
    if ((int)uVar6 == 0) {
      puVar9 = &FilterRegistration;
    }
    pcVar7 = (code *)param_1;
    uVar4 = FltRegisterFilter(param_1,puVar9,&gBfsFilterHandle);
    if (-1 < (int)uVar4) {
      local_b8 = &local_98;
      local_c0 = (undefined1 *)((ulonglong)local_c0 & 0xffffffffffffff00);
      local_c8 = (undefined8 *)CONCAT44(local_c8._4_4_,0x100);
      bVar3 = true;
      pcVar7 = (code *)param_1;
      uVar4 = IoCreateDevice(param_1,0,local_80 + 2,0x22);
      if (-1 < (int)uVar4) {
        pwVar10 = L"150000";
        RtlInitUnicodeString(local_90);
        uVar6 = Feature_1199833401__private_IsEnabledDeviceUsageNoInline();
        pcVar7 = (code *)&gBfsRegistryCookie;
        if ((int)uVar6 == 0) {
          local_c0 = (undefined1 *)0x0;
          pwVar10 = local_90;
          local_c8 = &gBfsRegistryCookie;
          pcVar7 = BfsRegistryCallback;
          uVar4 = CmRegisterCallbackEx(BfsRegistryCallback,pwVar10,param_1,0);
          if ((int)uVar4 < 0) goto LAB_14001f40a;
          bVar2 = true;
        }
        uVar6 = Feature_Servicing_BfsGAFeature__private_IsEnabledDeviceUsageNoInline();
        if ((int)uVar6 != 0) {
          TraceLoggingRegisterEx_EtwRegister_EtwSetInformation();
          gBfsDeviceObject = local_98;
          gBfsRootDirectory = pcVar11;
          uVar4 = BfsInitializeGlobalFileTable(pcVar7,pwVar10,0x140019190);
          if ((int)uVar4 < 0) goto LAB_14001f40a;
        }
        uVar6 = Feature_1199833401__private_IsEnabledDeviceUsageNoInline();
        if ((int)uVar6 != 0) {
          local_c0 = (undefined1 *)0x0;
          local_c8 = &gBfsRegistryCookie;
          pcVar7 = BfsRegistryCallback;
          uVar4 = CmRegisterCallbackEx(BfsRegistryCallback,local_90,param_1,0);
          if ((int)uVar4 < 0) goto LAB_14001f40a;
          bVar2 = true;
        }
        pcVar7 = gBfsFilterHandle;
        uVar4 = FltStartFiltering();
        if (-1 < (int)uVar4) {
          uVar6 = Feature_Servicing_BfsGAFeature__private_IsEnabledDeviceUsageNoInline();
          if ((int)uVar6 == 0) {
            TraceLoggingRegisterEx_EtwRegister_EtwSetInformation();
            gBfsDeviceObject = local_98;
            gBfsRootDirectory = pcVar11;
            return uVar4;
          }
          return uVar4;
        }
      }
      goto LAB_14001f40a;
    }
    if (DAT_140019000 < 4) goto LAB_14001f43b;
    local_a8 = uVar4;
    bVar1 = bVar3;
  }
  uVar4 = local_a8;
  local_40 = &local_a8;
  local_38 = 4;
  local_c0 = local_60;
  _tlgWriteTransfer_EtwWriteTransfer(pcVar7,&DAT_140016d11);
LAB_14001f43b:
  uVar6 = Feature_1199833401__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar6 != 0) {
    KeEnterCriticalRegion();
    ExWaitForRundownProtectionRelease(&gBfsRundownProtection);
    KeLeaveCriticalRegion();
  }
  if (DAT_140019228 != 0) {
    ExFreePoolWithTag(DAT_140019228,0);
  }
  if (DAT_140019220 != 0) {
    ExFreePoolWithTag(DAT_140019220,0);
  }
  if (DAT_140019200 != 0) {
    ExFreePoolWithTag(DAT_140019200,0);
  }
  if (DAT_1400191f8 != 0) {
    ExFreePoolWithTag(DAT_1400191f8,0);
  }
  BfsUninitializePipeMappingTable((undefined8 *)&gBfsPipeMappingTable);
  BfsUninitializePolicyTable(0x140019260);
  if (pcVar11 != (code *)0x0) {
    ZwClose(pcVar11);
  }
  if (local_98 != 0) {
    IoDeleteDevice();
  }
  if (bVar1) {
    FltUnregisterFilter(gBfsFilterHandle);
  }
  if (gBfsSHA256Handle != (BCRYPT_ALG_HANDLE)0x0) {
    BCryptCloseAlgorithmProvider(gBfsSHA256Handle,0);
  }
  if (bVar2) {
    CmUnRegisterCallback(gBfsRegistryCookie);
  }
  if (DAT_140019238 != 0) {
    RtlFreeUnicodeString(&gBfsBootDevice);
  }
  uVar6 = Feature_Servicing_BfsGAFeature__private_IsEnabledDeviceUsageNoInline();
  uVar5 = DAT_140019020;
  if ((int)uVar6 != 0) {
    DAT_140019020 = 0;
    DAT_140019000 = 0;
    EtwUnregister(uVar5);
  }
  wil_UninitializeFeatureStaging();
  return uVar4;
}



===== wil_InitializeFeatureStaging @ 14001f604 =====

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



===== wil_details_PopulateInitialConfiguredFeatureStates @ 14001f6f4 =====

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


