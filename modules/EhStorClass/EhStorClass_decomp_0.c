
===== FilterDeviceEvtWdmIoctlIrpPreprocess @ 140001010 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong FilterDeviceEvtWdmIoctlIrpPreprocess(undefined8 param_1,longlong param_2)

{
  byte bVar1;
  undefined8 *puVar2;
  longlong lVar3;
  undefined4 *puVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  bool bVar8;
  bool bVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  undefined8 *puVar13;
  undefined8 uVar14;
  ulonglong uVar15;
  ulonglong uVar16;
  char cVar17;
  bool bVar18;
  char *pcVar19;
  uint *puVar20;
  bool bVar21;
  ulonglong uVar22;
  int *piVar23;
  uint local_res10;
  ulonglong local_res18;
  int *local_res20;
  undefined8 in_stack_ffffffffffffff08;
  undefined8 in_stack_ffffffffffffff10;
  undefined8 in_stack_ffffffffffffff20;
  undefined8 in_stack_ffffffffffffff30;
  undefined8 in_stack_ffffffffffffff40;
  int *local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  
  uVar15 = 0;
  local_68 = (int *)0x0;
  bVar18 = false;
  bVar8 = false;
  puVar13 = (undefined8 *)
            (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,param_1,PTR__WDF_FILTER_DEVICE_EXTENSION_TYPE_INFO_140016018
                      );
  pcVar19 = *(char **)(param_2 + 0xb8);
  if ((1 < (byte)(*pcVar19 - 3U)) || (*(int *)(puVar13[0x2f] + 0x1c) != 0x11)) {
    (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*puVar13);
    iVar11 = *(int *)(puVar13 + 1);
    uVar10 = *(uint *)(puVar13 + 2);
    (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals);
    cVar17 = *pcVar19;
    if (iVar11 == 0) {
      if ((cVar17 == '\x0e') && (*(int *)(pcVar19 + 0x18) == 0x2d1400)) {
        bVar18 = true;
      }
      else {
LAB_1400010d2:
        bVar18 = false;
      }
    }
    else {
      bVar18 = true;
      if ((byte)(cVar17 - 3U) < 2) {
        if ((*(int *)(puVar13[0x2f] + 0x1c) == 0x11) || ((uVar10 & 1) != 0)) goto LAB_1400010d2;
      }
      else if (cVar17 == '\x0f') {
        local_res18 = *(ulonglong *)(pcVar19 + 8);
        cVar17 = *(char *)(local_res18 + 2);
        if (cVar17 == '(') {
          uVar12 = *(uint *)(local_res18 + 0x18);
        }
        else {
          uVar12 = *(uint *)(local_res18 + 0xc);
        }
        if ((*(int *)(puVar13[0x2f] + 0x1c) == 0x11) ||
           ((uVar10 & 1) != 0 || (uVar12 >> 0x13 & 1) != 0)) {
          bVar18 = false;
        }
        bVar8 = true;
        if (cVar17 == '\0') {
          pcVar19 = (char *)(local_res18 + 0x48);
          uVar15 = 0;
        }
        else {
          if (cVar17 != '(') goto LAB_1400010d5;
          pcVar19 = (char *)0x0;
          uVar15 = local_res18;
          if (*(int *)(local_res18 + 0x14) == 0) {
            uVar10 = 0;
            if (*(uint *)(local_res18 + 0x38) != 0) {
              puVar20 = (uint *)(local_res18 + 0x78);
              do {
                uVar12 = *puVar20;
                uVar16 = (ulonglong)uVar12;
                if ((0x7f < uVar12) &&
                   (uVar22 = (ulonglong)*(uint *)(local_res18 + 0x10),
                   uVar12 < *(uint *)(local_res18 + 0x10))) {
                  iVar11 = *(int *)(uVar16 + local_res18);
                  lVar3 = uVar16 + local_res18;
                  if (iVar11 == 0x40) {
                    if (uVar16 + 0x28 <= uVar22) {
                      cVar17 = *(char *)(lVar3 + 10);
joined_r0x000140001640:
                      if (cVar17 != '\0') {
                        pcVar19 = (char *)(lVar3 + 0x18);
                      }
                      break;
                    }
                  }
                  else if (iVar11 == 0x41) {
                    if (uVar16 + 0x38 <= uVar22) {
                      cVar17 = *(char *)(lVar3 + 10);
                      goto joined_r0x000140001640;
                    }
                  }
                  else if ((iVar11 == 0x42) && (uVar16 + 0x28 <= uVar22)) {
                    if (*(int *)(lVar3 + 0xc) != 0) {
                      pcVar19 = (char *)(lVar3 + 0x20);
                    }
                    break;
                  }
                }
                uVar10 = uVar10 + 1;
                puVar20 = puVar20 + 1;
              } while (uVar10 < *(uint *)(local_res18 + 0x38));
            }
          }
        }
        if ((((pcVar19 != (char *)0x0) && (*pcVar19 == 'H')) && ((pcVar19[1] & 0x1fU) == 3)) &&
           ((*(int *)((longlong)puVar13 + 500) != 0 && (EnableCryptoSanitizeTranslation != '\0'))))
        {
          uVar10 = IssueSyncIoctl(puVar13[0x34],(longlong *)puVar13[0x37],pcVar19,0x2dd4b0,0,0,0,0,
                                  (undefined8 *)0x0);
          cVar17 = ((byte)((int)uVar10 >> 0x1f) & 3) + 1;
          if (*(char *)(local_res18 + 2) == '(') {
            *(char *)(uVar15 + 3) = cVar17;
          }
          else {
            *(char *)(local_res18 + 3) = cVar17;
          }
          goto LAB_1400015e8;
        }
      }
      else if (cVar17 == '\x0e') {
        iVar11 = *(int *)(pcVar19 + 0x18);
        bVar9 = false;
        local_res10 = 0;
        if ((iVar11 - 0x4d004U & 0xffffffef) == 0) {
          bVar1 = *(byte *)(*(longlong *)(param_2 + 0x18) + 0x24);
          uVar12 = (uint)bVar1;
          if ((bVar1 == 0xa2) || (local_res20 = (int *)0x0, bVar1 == 0xb5)) {
            bVar1 = *(byte *)(*(longlong *)(param_2 + 0x18) + 0x25);
            uVar16 = (ulonglong)bVar1;
            if ((bVar1 < 2) || ((bVar1 == 0xee || (local_res20 = (int *)0x0, bVar1 == 2)))) {
              bVar8 = true;
LAB_140001a68:
              local_res10 = uVar12;
              local_res20 = (int *)uVar16;
LAB_140001a77:
              bVar9 = true;
              bVar18 = (bool)(~(byte)uVar10 & 1);
            }
          }
LAB_1400013f7:
          bVar21 = false;
        }
        else {
          if ((iVar11 - 0x4d02cU & 0xfffffffb) == 0) {
            bVar1 = *(byte *)(*(longlong *)(param_2 + 0x18) + 0x2e);
            uVar12 = (uint)bVar1;
            if ((bVar1 == 0x5c) || (local_res20 = (int *)0x0, bVar1 == 0x5e)) {
              bVar1 = *(byte *)(*(longlong *)(param_2 + 0x18) + 0x28);
              uVar16 = (ulonglong)bVar1;
              if ((bVar1 < 2) || ((bVar1 == 0xee || (local_res20 = (int *)0x0, bVar1 == 2))))
              goto LAB_140001a68;
            }
            goto LAB_1400013f7;
          }
          if (iVar11 == 0x2dd3c0) {
            lVar3 = *(longlong *)(param_2 + 0x18);
            local_res20 = (int *)0x0;
            if ((*(int *)(lVar3 + 8) == 3) &&
               ((uVar12 = *(uint *)(lVar3 + 0x50) & 0xff, uVar12 == 0x81 ||
                (local_res20 = (int *)0x0, uVar12 == 0x82)))) {
              bVar1 = *(byte *)(lVar3 + 0x7b);
              if ((bVar1 < 2) || ((bVar1 == 0xee || (local_res20 = (int *)0x0, bVar1 == 2)))) {
                local_res10 = uVar12;
                local_res20 = (int *)(ulonglong)bVar1;
                goto LAB_140001a77;
              }
            }
            goto LAB_1400013f7;
          }
          if (iVar11 == 0x2d280c) {
            if (((0x27 < *(uint *)(pcVar19 + 0x10)) &&
                (piVar5 = *(int **)(param_2 + 0x18), *piVar5 == 0x28)) && (piVar5[1] == 0x28)) {
              iVar11 = piVar5[3];
              iVar6 = piVar5[4];
              iVar7 = piVar5[5];
              *(int *)(puVar13 + 0x2c) = piVar5[2];
              *(int *)((longlong)puVar13 + 0x164) = iVar11;
              *(int *)(puVar13 + 0x2d) = iVar6;
              *(int *)((longlong)puVar13 + 0x16c) = iVar7;
            }
            local_res20 = (int *)0x0;
            goto LAB_1400013f7;
          }
          if ((iVar11 == 0x2d1400) && (0xb < *(uint *)(pcVar19 + 0x10))) {
            piVar5 = *(int **)(param_2 + 0x18);
            if (*piVar5 == 0x40) {
              if (piVar5[1] != 1) {
                if (piVar5[1] == 0) {
                  uVar10 = *(uint *)(pcVar19 + 8);
                  if (uVar10 < 8) {
                    uVar15 = 0xc0000023;
                  }
                  else {
                    memset(piVar5,0,(ulonglong)uVar10);
                    if (uVar10 < 0x10) {
                      if (uVar10 < 0xc) {
                        *piVar5 = 0x10;
                        piVar5[1] = 0x10;
                        *(undefined8 *)(param_2 + 0x38) = 8;
                      }
                      else {
                        *piVar5 = 0xc;
                        piVar5[1] = 0xc;
                        *(undefined1 *)(piVar5 + 2) = 1;
                        *(undefined8 *)(param_2 + 0x38) = 0xc;
                      }
                    }
                    else {
                      puVar4 = *(undefined4 **)(param_2 + 0x18);
                      *puVar4 = 0x10;
                      puVar4[1] = 0x10;
                      *(undefined1 *)(puVar4 + 2) = 1;
                      puVar4[3] = 1;
                      *(undefined8 *)(param_2 + 0x38) = 0x10;
                    }
                    uVar15 = 0;
                  }
                }
                else {
                  uVar15 = 0xc00000bb;
                }
              }
              bVar21 = true;
            }
            else {
              bVar21 = false;
            }
            bVar9 = false;
            local_res20 = (int *)0x0;
          }
          else {
            local_res20 = (int *)0x0;
            if (iVar11 != 0x2d08c0) goto LAB_1400013f7;
            piVar5 = *(int **)(param_2 + 0x18);
            bVar18 = false;
            bVar21 = true;
            uVar10 = *(uint *)(pcVar19 + 8);
            uVar15 = (ulonglong)uVar10;
            if (*(uint *)(pcVar19 + 0x10) < 0x18) {
              uVar15 = 0xc0000004;
              local_res20 = (int *)0x0;
            }
            else if (*piVar5 == 0x18) {
              iVar11 = piVar5[2];
              local_res18 = CONCAT44(local_res18._4_4_,iVar11);
              if (iVar11 - 1U < 3) {
                if (uVar10 < 8) {
                  uVar15 = 0xc0000023;
                  local_res20 = (int *)0x0;
                }
                else {
                  local_res20 = piVar5;
                  if (iVar11 == 2) {
                    bVar18 = 0x17 < uVar10;
                    if (!bVar18) {
                      memset(piVar5,0,uVar15);
                      *piVar5 = 0x160;
                      piVar5[1] = 0x18;
                      *(undefined8 *)(param_2 + 0x38) = 8;
                    }
                    bVar9 = false;
                    bVar21 = !bVar18;
                    uVar15 = 0;
                    local_res20 = (int *)0x0;
                  }
                  else if (uVar10 < 0x160) {
                    memset(piVar5,0,uVar15);
                    *piVar5 = 0x160;
                    piVar5[1] = 0x160;
                    uVar15 = 0;
                    local_res20 = (int *)0x0;
                    bVar9 = false;
                    *(undefined8 *)(param_2 + 0x38) = 8;
                  }
                  else {
                    if (iVar11 == 1) {
                      piVar23 = piVar5 + 6;
                    }
                    else if (iVar11 == 3) {
                      piVar23 = piVar5 + 6;
                    }
                    else {
                      piVar23 = local_68;
                    }
                    memset(piVar5,0,uVar15);
                    *local_res20 = 0x160;
                    local_res20[1] = 0x160;
                    local_res20[2] = (int)local_res18;
                    *(undefined8 *)(param_2 + 0x38) = 0x160;
                    *piVar23 = -0x3ffffb37;
                    *(undefined2 *)(piVar23 + 1) = 0xf;
                    builtin_wcsncpy((wchar_t *)((longlong)piVar23 + 6),L"EhSt",4);
                    builtin_wcsncpy((wchar_t *)((longlong)piVar23 + 0xe),L"orCl",4);
                    *(undefined8 *)((longlong)piVar23 + 0x16) = 0x2e007300730061;
                    *(undefined4 *)((longlong)piVar23 + 0x1e) = 0x790073;
                    *(undefined2 *)((longlong)piVar23 + 0x22) = 0x73;
                    *(undefined2 *)((longlong)piVar23 + 0x46) = 0x1e;
                    builtin_wcsncpy((wchar_t *)(piVar23 + 0x12),L"Hard",4);
                    builtin_wcsncpy((wchar_t *)(piVar23 + 0x14),L"ware",4);
                    builtin_wcsncpy((wchar_t *)(piVar23 + 0x16),L" Enc",4);
                    builtin_wcsncpy((wchar_t *)(piVar23 + 0x18),L"rypt",4);
                    builtin_wcsncpy((wchar_t *)(piVar23 + 0x1a),L"ion ",4);
                    builtin_wcsncpy((wchar_t *)(piVar23 + 0x1c),L"is e",4);
                    piVar23[0x1e] = 0x61006e;
                    piVar23[0x1f] = 0x6c0062;
                    piVar23[0x20] = 0x640065;
                    uVar15 = 0;
                    local_res20 = (int *)0x0;
                    bVar9 = false;
                  }
                }
              }
              else {
                uVar15 = 0xc000000d;
                local_res20 = (int *)0x0;
              }
            }
            else {
              uVar15 = 0xc00000bb;
              local_res20 = (int *)0x0;
            }
          }
        }
        if ((IsWinPE == '\0') && (bVar9)) {
          local_68 = (int *)0x0;
          local_res18 = local_res18 & 0xffffffff00000000;
          local_60 = 0;
          uStack_58 = 0;
          local_50 = 0;
          uStack_48 = 0;
          RtlInitUnicodeString
                    (&local_60,
                     L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\EnhancedStorage\\");
          iVar11 = (**(code **)(WdfFunctions_01015 + 0x728))
                             (WdfDriverGlobals,0,&local_60,0x20019,0,&local_68);
          if ((-1 < iVar11) && (local_68 != (int *)0x0)) {
            RtlInitUnicodeString(&local_50,L"DisableSecurityPassthrough");
            (**(code **)(WdfFunctions_01015 + 0x780))
                      (WdfDriverGlobals,local_68,&local_50,&local_res18);
            (**(code **)(WdfFunctions_01015 + 0x738))(WdfDriverGlobals,local_68);
          }
          uVar15 = 0;
          if ((Microsoft_Windows_EnhancedStorage_ClassDriverEnableBits & 2) != 0) {
            McTemplateK0quuujzzxzxzxzxzxzxzxzx_EtwWriteTransfer
                      ((ulonglong)local_res10,(ulonglong)*(uint *)(pcVar19 + 0x18),puVar13 + 0x2c,
                       (uint)*(byte *)((longlong)puVar13 + 0x174),
                       *(undefined1 *)((longlong)puVar13 + 0x175),
                       *(undefined1 *)((longlong)puVar13 + 0x176),
                       *(undefined1 *)((longlong)puVar13 + 0x177),puVar13 + 0x2c,
                       in_stack_ffffffffffffff08,in_stack_ffffffffffffff10,
                       (char)*(uint *)(pcVar19 + 0x18),in_stack_ffffffffffffff20,(char)local_res10,
                       in_stack_ffffffffffffff30,(char)local_res20,in_stack_ffffffffffffff40,
                       (char)local_res18);
          }
          if ((int)local_res18 != 0) {
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (2 < (byte)WPP_GLOBAL_Control[0x29])) {
              WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
                      &WPP_45305c62c3e63920635d5fbdd89541d2_Traceguids);
            }
            uVar10 = 0xc00000bb;
            goto LAB_1400015e8;
          }
        }
        uVar10 = (uint)uVar15;
        if (bVar21) {
LAB_1400015e8:
          *(uint *)(param_2 + 0x30) = uVar10;
          IofCompleteRequest(param_2,0);
          return (ulonglong)uVar10;
        }
        if ((int)uVar10 < 0) {
          return uVar15;
        }
      }
    }
  }
LAB_1400010d5:
  puVar2 = *(undefined8 **)(param_2 + 0xb8);
  if ((*(uint *)((longlong)puVar13 + 0x134) & 0xf000) < 0x6000) {
    if (bVar8) {
      puVar2[-9] = *puVar2;
      puVar2[-8] = puVar2[1];
      puVar2[-7] = puVar2[2];
      puVar2[-6] = puVar2[3];
      *(undefined4 *)(puVar2 + -5) = *(undefined4 *)(puVar2 + 4);
      *(undefined4 *)((longlong)puVar2 + -0x24) = *(undefined4 *)((longlong)puVar2 + 0x24);
      *(undefined4 *)(puVar2 + -4) = *(undefined4 *)(puVar2 + 5);
      *(undefined4 *)((longlong)puVar2 + -0x1c) = *(undefined4 *)((longlong)puVar2 + 0x2c);
      puVar2[-3] = puVar2[6];
      *(undefined1 *)((longlong)puVar2 + -0x45) = 0;
      lVar3 = *(longlong *)(param_2 + 0xb8);
      *(code **)(lVar3 + -0x10) = FilterDeviceWdmIoctlCompletionRoutine;
      *(undefined8 *)(lVar3 + -8) = param_1;
      *(undefined1 *)(lVar3 + -0x45) = 0xc0;
      goto LAB_14000110a;
    }
  }
  else {
    bVar18 = false;
  }
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *(undefined8 **)(param_2 + 0xb8) = puVar2 + 9;
LAB_14000110a:
  if (bVar18 == true) {
    uVar15 = (**(code **)(WdfFunctions_01015 + 0x110))(WdfDriverGlobals,param_1,param_2);
  }
  else {
    uVar14 = (**(code **)(WdfFunctions_01015 + 0x100))();
    uVar15 = IofCallDriver(uVar14,param_2);
  }
  return uVar15;
}



===== FilterDeviceEvtIoInCallerContext @ 140001ac0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FilterDeviceEvtIoInCallerContext(undefined8 param_1,undefined8 param_2)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  undefined8 *puVar4;
  undefined2 uVar5;
  undefined1 auStack_88 [32];
  char *local_68;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_88;
  puVar4 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_2,PTR__WDF_REQUEST_CONTEXT_TYPE_INFO_140016108);
  local_68 = "onecore\\drivers\\storage\\enhancedstorage\\drivers\\ehstorclass\\dataio.c";
  *puVar4 = 0;
  puVar4[1] = 0;
  puVar4[2] = 0;
  puVar4[3] = 0;
  puVar4[4] = 0;
  puVar4[5] = 0;
  (**(code **)(WdfFunctions_01015 + 0x668))
            (WdfDriverGlobals,param_2,FilterDeviceEvtIoInCallerContext,0x3e9);
  local_38 = 0;
  uStack_50 = 0;
  local_58 = 0x28;
  local_48 = 0;
  uStack_40 = 0;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_58);
  if (((int)uStack_40 == 0x4d014) && (local_58._4_4_ == 0xe)) {
    *(undefined1 *)(puVar4 + 1) = 1;
    puVar4[5] = ForwardRequestToLocalIoTarget;
  }
  if (*(char *)(puVar4 + 1) == '\x01') {
    bVar1 = KeGetCurrentIrql();
    if (bVar1 < 2) {
      KeInitializeEvent(puVar4 + 2,0,0);
      goto LAB_140001ba7;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
              &WPP_45305c62c3e63920635d5fbdd89541d2_Traceguids);
    }
    iVar3 = -0x3ffffeb8;
LAB_140001e5d:
    if (*(char *)(puVar4 + 1) == '\x01') {
      KeSetEvent(puVar4 + 2,0,0);
    }
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar3);
    if (iVar3 < 0) goto LAB_140001cca;
  }
  else {
LAB_140001ba7:
    iVar3 = (**(code **)(WdfFunctions_01015 + 0x2d8))(WdfDriverGlobals,param_1,param_2);
    if (iVar3 < 0) goto LAB_140001e5d;
    if (*(char *)(puVar4 + 1) != '\x01') goto LAB_140001cca;
LAB_140001be7:
    while( true ) {
      local_68 = (char *)0x0;
      iVar3 = KeWaitForSingleObject(puVar4 + 2,0,0,1);
      if (iVar3 == 0) break;
      if (iVar3 == 0x101) {
        cVar2 = PsIsThreadTerminating(SystemReserved1[0xf]);
        if (cVar2 == '\0') goto LAB_140001e39;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (2 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                  &WPP_45305c62c3e63920635d5fbdd89541d2_Traceguids);
        }
        cVar2 = (**(code **)(WdfFunctions_01015 + 0x810))(WdfDriverGlobals);
        if (((cVar2 == '\0') && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                  &WPP_45305c62c3e63920635d5fbdd89541d2_Traceguids);
        }
      }
      else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar5 = 0xc;
        goto LAB_140001d87;
      }
    }
    cVar2 = (**(code **)(WdfFunctions_01015 + 0x808))(WdfDriverGlobals,param_2);
    if (cVar2 != '\0') {
      iVar3 = -0x3ffffee0;
      goto LAB_140001e5d;
    }
  }
  if (*(char *)(puVar4 + 1) == '\x01') {
    (*(code *)puVar4[5])(param_2,param_1);
  }
LAB_140001cca:
  local_68 = "onecore\\drivers\\storage\\enhancedstorage\\drivers\\ehstorclass\\dataio.c";
  (**(code **)(WdfFunctions_01015 + 0x670))
            (WdfDriverGlobals,param_2,FilterDeviceEvtIoInCallerContext,0x458);
  return;
LAB_140001e39:
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (2 < (byte)WPP_GLOBAL_Control[0x29])) {
    uVar5 = 0xf;
    iVar3 = 0x101;
LAB_140001d87:
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,
             &WPP_45305c62c3e63920635d5fbdd89541d2_Traceguids,iVar3);
  }
  goto LAB_140001be7;
}



===== DefaultQueueEvtInternalDeviceControl @ 140001e90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void DefaultQueueEvtInternalDeviceControl(undefined8 param_1,undefined8 param_2)

{
  byte bVar1;
  int iVar2;
  longlong lVar3;
  undefined8 uVar4;
  longlong lVar5;
  longlong lVar6;
  uint uVar7;
  
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_REQUEST_CONTEXT_TYPE_INFO_140016108);
  uVar4 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,uVar4);
  lVar6 = (**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals,param_2);
  lVar6 = *(longlong *)(*(longlong *)(lVar6 + 0xb8) + 8);
  bVar1 = *(byte *)(lVar6 + 2);
  uVar7 = (uint)bVar1;
  if (bVar1 == 0x28) {
    uVar7 = *(uint *)(lVar6 + 0x14);
  }
  if (uVar7 == 0) {
    (**(code **)(WdfFunctions_01015 + 0x8c8))(WdfDriverGlobals,param_2,*(undefined8 *)(lVar5 + 400))
    ;
  }
  else {
    iVar2 = ForwardRequestToLocalIoTargetWithCompletionRoutine(param_2,uVar4,(undefined *)0x0);
    if ((iVar2 < 0) && (*(char *)(lVar3 + 8) == '\x01')) {
      KeSetEvent(lVar3 + 0x10,0,0);
    }
  }
  return;
}



===== ForwardRequestToLocalIoTargetWithCompletionRoutine @ 140001fc0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4
ForwardRequestToLocalIoTargetWithCompletionRoutine
          (undefined8 param_1,undefined8 param_2,undefined *param_3)

{
  char cVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  code *pcVar4;
  
  (**(code **)(WdfFunctions_01015 + 0x7d8))(WdfDriverGlobals,param_1);
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_FILTER_DEVICE_EXTENSION_TYPE_INFO_140016018);
  pcVar4 = RequestDummyCompletionRoutine;
  if (param_3 != (undefined *)0x0) {
    pcVar4 = (code *)param_3;
  }
  (**(code **)(WdfFunctions_01015 + 0x820))(WdfDriverGlobals,param_1,pcVar4,uVar3);
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x150))(WdfDriverGlobals,param_2);
  cVar1 = (**(code **)(WdfFunctions_01015 + 0x7e8))(WdfDriverGlobals,param_1,uVar3,0);
  if (cVar1 == '\0') {
    uVar2 = (**(code **)(WdfFunctions_01015 + 0x7f0))(WdfDriverGlobals,param_1);
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_1,uVar2);
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



===== McTemplateK0quuujzdzxzxzxzx_EtwWriteTransfer @ 1400020e8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0quuujzdzxzxzxzx_EtwWriteTransfer(void)

{
  longlong lVar1;
  longlong lVar2;
  undefined1 local_res20 [8];
  undefined1 uStack0000000000000028;
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  wchar_t *in_stack_00000048;
  undefined1 uStack0000000000000050;
  wchar_t *in_stack_00000058;
  undefined1 uStack0000000000000060;
  wchar_t *in_stack_00000068;
  undefined1 uStack0000000000000070;
  wchar_t *in_stack_00000078;
  undefined1 uStack0000000000000080;
  wchar_t *in_stack_00000088;
  undefined1 uStack0000000000000090;
  undefined1 auStackY_148 [32];
  undefined8 local_118 [2];
  undefined1 *local_108;
  undefined8 local_100;
  undefined1 *local_f8;
  undefined8 local_f0;
  undefined1 *local_e8;
  undefined8 local_e0;
  undefined1 *local_d8;
  undefined8 local_d0;
  undefined8 local_c0;
  wchar_t *local_b8;
  int local_b0;
  undefined4 local_ac;
  undefined1 *local_a8;
  undefined8 local_a0;
  wchar_t *local_98;
  int local_90;
  undefined4 local_8c;
  undefined1 *local_88;
  undefined8 local_80;
  wchar_t *local_78;
  int local_70;
  undefined4 local_6c;
  undefined1 *local_68;
  undefined8 local_60;
  wchar_t *local_58;
  int local_50;
  undefined4 local_4c;
  undefined1 *local_48;
  undefined8 local_40;
  wchar_t *local_38;
  int local_30;
  undefined4 local_2c;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_148;
  local_108 = local_res20;
  local_30 = 10;
  local_f8 = &uStack0000000000000028;
  local_100 = 4;
  local_e8 = &uStack0000000000000030;
  local_d8 = &uStack0000000000000038;
  lVar1 = -1;
  local_f0 = 1;
  local_e0 = 1;
  local_d0 = 1;
  local_c0 = 0x10;
  if (in_stack_00000048 == (wchar_t *)0x0) {
    local_b0 = 10;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (in_stack_00000048[lVar2] != L'\0');
    local_b0 = (int)lVar2 * 2 + 2;
  }
  local_ac = 0;
  if (in_stack_00000048 == (wchar_t *)0x0) {
    in_stack_00000048 = L"NULL";
  }
  local_a0 = 4;
  local_a8 = &uStack0000000000000050;
  if (in_stack_00000058 == (wchar_t *)0x0) {
    local_90 = 10;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (in_stack_00000058[lVar2] != L'\0');
    local_90 = (int)lVar2 * 2 + 2;
  }
  local_88 = &uStack0000000000000060;
  local_8c = 0;
  if (in_stack_00000058 == (wchar_t *)0x0) {
    in_stack_00000058 = L"NULL";
  }
  local_80 = 8;
  if (in_stack_00000068 == (wchar_t *)0x0) {
    local_70 = 10;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (in_stack_00000068[lVar2] != L'\0');
    local_70 = (int)lVar2 * 2 + 2;
  }
  local_68 = &uStack0000000000000070;
  local_6c = 0;
  if (in_stack_00000068 == (wchar_t *)0x0) {
    in_stack_00000068 = L"NULL";
  }
  local_60 = 8;
  if (in_stack_00000078 == (wchar_t *)0x0) {
    local_50 = 10;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (in_stack_00000078[lVar2] != L'\0');
    local_50 = (int)lVar2 * 2 + 2;
  }
  local_48 = &uStack0000000000000080;
  local_4c = 0;
  if (in_stack_00000078 == (wchar_t *)0x0) {
    in_stack_00000078 = L"NULL";
  }
  local_40 = 8;
  if (in_stack_00000088 != (wchar_t *)0x0) {
    do {
      lVar1 = lVar1 + 1;
    } while (in_stack_00000088[lVar1] != L'\0');
    local_30 = (int)lVar1 * 2 + 2;
  }
  local_28 = &uStack0000000000000090;
  local_2c = 0;
  if (in_stack_00000088 == (wchar_t *)0x0) {
    in_stack_00000088 = L"NULL";
  }
  local_20 = 8;
  local_b8 = in_stack_00000048;
  local_98 = in_stack_00000058;
  local_78 = in_stack_00000068;
  local_58 = in_stack_00000078;
  local_38 = in_stack_00000088;
  McGenEventWrite_EtwWriteTransfer(local_48,&DeviceFailedCommand,in_stack_00000058,0x10,local_118);
  return;
}



===== FilterDeviceEvtWdmPowerIrpPreprocess @ 140002330 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int FilterDeviceEvtWdmPowerIrpPreprocess(undefined8 param_1,longlong param_2)

{
  char *pcVar1;
  bool bVar2;
  undefined1 uVar3;
  int iVar4;
  longlong lVar5;
  longlong *plVar6;
  undefined8 local_78;
  code *pcStack_70;
  ulonglong local_68;
  undefined4 local_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 local_50;
  undefined4 uStack_4c;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined *local_30;
  
  pcVar1 = *(char **)(param_2 + 0xb8);
  iVar4 = 0;
  local_30 = (undefined *)((ulonglong)local_30 & 0xffffffff00000000);
  local_60 = 0;
  uStack_5c = 0;
  uStack_58 = 0;
  uStack_54 = 0;
  local_68 = local_68 & 0xffffffff00000000;
  local_50 = 0;
  uStack_4c = 0;
  uStack_48 = 0;
  bVar2 = true;
  local_40 = 0;
  uStack_38 = 0;
  local_78 = 0;
  pcStack_70 = (code *)0x0;
  if (((*pcVar1 == '\x16') && (pcVar1[1] == '\x02')) && (*(int *)(pcVar1 + 0x10) == 1)) {
    lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,param_1,PTR__WDF_FILTER_DEVICE_EXTENSION_TYPE_INFO_140016018
                      );
    LogEvent("FPwrIrpE",(ulonglong)*(uint *)(pcVar1 + 8),
             (longlong)(int)(*(int *)(pcVar1 + 0x10) << 8 | *(uint *)(pcVar1 + 0x18)),
             (longlong)*(int *)(pcVar1 + 0x20));
    *(undefined4 *)(lVar5 + 0x134) = *(undefined4 *)(pcVar1 + 8);
    if ((*(int *)(pcVar1 + 0x18) == 1) && (*(int *)(pcVar1 + 0x20) == 5)) {
      uStack_4c = 0;
      uStack_38 = 0;
      local_30 = PTR__WDF_POWER_IRP_WORKITEM_CONTEXT_TYPE_INFO_140016040;
      pcStack_70 = FilterDevicePreprocessRebootIrp;
      uStack_48 = 0x100000001;
      local_68 = 1;
      uStack_5c = 0;
      uStack_58 = 0;
      uStack_54 = 0;
      local_50 = 0;
      local_60 = 0x38;
      local_78 = 0x18;
      local_40 = param_1;
      iVar4 = (**(code **)(WdfFunctions_01015 + 0xbd8))(WdfDriverGlobals,&local_78,&local_60);
      if (iVar4 < 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,
                   &WPP_7186403ff6ae38c3a7435fda3b62a1f7_Traceguids,iVar4);
        }
      }
      else {
        plVar6 = (longlong *)
                 (**(code **)(WdfFunctions_01015 + 0x650))
                           (WdfDriverGlobals,0,
                            PTR__WDF_POWER_IRP_WORKITEM_CONTEXT_TYPE_INFO_140016040);
        *plVar6 = param_2;
        (**(code **)(WdfFunctions_01015 + 0xbe0))(WdfDriverGlobals,0);
        bVar2 = false;
        iVar4 = 0x103;
      }
    }
    LogEvent("FPwrIrpX",param_1,(longlong)iVar4,0);
    if (!bVar2) {
      return iVar4;
    }
  }
  uVar3 = KfRaiseIrql(2);
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  iVar4 = (**(code **)(WdfFunctions_01015 + 0x110))(WdfDriverGlobals,param_1,param_2);
  KeLowerIrql(uVar3);
  return iVar4;
}



===== McTemplateK0quuuju_EtwWriteTransfer @ 14000258c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0quuuju_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined8 param_8,
               undefined1 param_9)

{
  undefined4 local_res20 [2];
  undefined1 auStackY_b8 [32];
  undefined8 local_88 [2];
  undefined4 *local_78;
  undefined8 local_70;
  undefined1 *local_68;
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
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_b8;
  local_78 = local_res20;
  local_70 = 4;
  local_68 = &param_5;
  local_60 = 1;
  local_58 = &param_6;
  local_50 = 1;
  local_48 = &param_7;
  local_38 = param_8;
  local_28 = &param_9;
  local_40 = 1;
  local_30 = 0x10;
  local_20 = 1;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&DevicePdoCapsDiscovered,param_3,7,local_88);
  return;
}



===== IoctlDeviceQueryProperties @ 140002644 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int IoctlDeviceQueryProperties(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 *puVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined1 auStackY_98 [32];
  undefined4 *local_48;
  longlong local_40 [3];
  undefined8 local_28;
  undefined4 uStack_24;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStackY_98;
  local_48 = (undefined4 *)0x0;
  local_40[0] = 0;
  local_40[1] = 0;
  local_40[2] = 0;
  local_28 = 0;
  LogEvent("DevQProp",0,0,0);
  puVar2 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_CHILD_DEVICE_EXTENSION_TYPE_INFO_1400160b8);
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,*puVar2,PTR__WDF_FILTER_DEVICE_EXTENSION_TYPE_INFO_140016018);
  uVar4 = 8;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,param_2,8,&local_48);
  if (iVar1 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
               &WPP_6b540f47682e3482637f60efce621d01_Traceguids,iVar1);
    }
  }
  else {
    iVar1 = IssueSyncIoctl(*(undefined8 *)(lVar3 + 0x1a0),(longlong *)puVar2[4],uVar4,0x70000,0,0,
                           (longlong)(local_40 + 1),0x18,local_40);
    if ((iVar1 < 0) || (local_40[0] != 0x18)) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_Pd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
                  &WPP_6b540f47682e3482637f60efce621d01_Traceguids,local_40[0],(char)iVar1);
      }
    }
    else {
      *local_48 = 8;
      local_48[1] = uStack_24;
      (**(code **)(WdfFunctions_01015 + 0x898))(WdfDriverGlobals,param_2,8);
    }
  }
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar1);
  return iVar1;
}



===== FilterDeviceEvtD0Entry @ 140002860 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 FilterDeviceEvtD0Entry(undefined8 param_1,int param_2)

{
  uint uVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  undefined8 *puVar5;
  longlong lVar6;
  longlong lVar7;
  undefined *puVar8;
  ulonglong uVar9;
  uint local_res10 [2];
  longlong local_res18;
  
  local_res18 = 0;
  local_res10[0] = 0;
  uVar9 = 0;
  LogEvent("FD0EntE",param_1,(longlong)param_2,0);
  puVar8 = PTR__WDF_FILTER_DEVICE_EXTENSION_TYPE_INFO_140016018;
  puVar5 = (undefined8 *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*puVar5);
  iVar4 = *(int *)(puVar5 + 1);
  uVar1 = *(uint *)(puVar5 + 2);
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*puVar5);
  if ((Microsoft_Windows_EnhancedStorage_ClassDriverEnableBits & 1) != 0) {
    uVar9 = (ulonglong)*(byte *)((longlong)puVar5 + 0x174);
    McTemplateK0quuujuu_EtwWriteTransfer
              (puVar5 + 0x2c,&DeviceEnterD0,puVar8,(uint)*(byte *)((longlong)puVar5 + 0x174),
               *(undefined1 *)((longlong)puVar5 + 0x175),*(undefined1 *)((longlong)puVar5 + 0x176),
               *(undefined1 *)((longlong)puVar5 + 0x177),puVar5 + 0x2c,(char)*(int *)(puVar5 + 0x25)
               ,(char)*(undefined4 *)(puVar5 + 1));
  }
  if (((*(int *)(puVar5 + 0x25) == 0) && (iVar4 != 0)) &&
     (FilterDeviceSend1667Probe(param_1,&local_res18,local_res10,uVar9), local_res18 != 0)) {
    ExFreePoolWithTag(local_res18,0);
    local_res18 = 0;
  }
  if (((*(uint *)(puVar5 + 0x26) & 0x10) != 0) && ((uVar1 & 1) != 0)) {
    *(uint *)(puVar5 + 0x26) = *(uint *)(puVar5 + 0x26) & 0xffffffef;
    (**(code **)(WdfFunctions_01015 + 0x430))(WdfDriverGlobals,param_1);
    bVar2 = false;
    bVar3 = false;
    while (lVar7 = (**(code **)(WdfFunctions_01015 + 0x438))(WdfDriverGlobals,param_1), lVar7 != 0)
    {
      lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))
                        (WdfDriverGlobals,lVar7,PTR__WDF_CHILD_DEVICE_EXTENSION_TYPE_INFO_1400160b8)
      ;
      if ((*(uint *)(lVar6 + 0x84) & 1) != 0) {
        iVar4 = ChildDeviceSendOnDemandAuthenticationRequest(lVar7,1);
        bVar2 = bVar3;
        if (-1 < iVar4) {
          bVar2 = true;
          bVar3 = true;
        }
      }
    }
    (**(code **)(WdfFunctions_01015 + 0x440))(WdfDriverGlobals,param_1);
    if (bVar2) {
      FilterDeviceSetState(param_1,2,2);
    }
  }
  if (puVar5[0x38] != 0) {
    (**(code **)(WdfFunctions_01015 + 0x4d0))(WdfDriverGlobals);
    *(uint *)(puVar5 + 0x26) = *(uint *)(puVar5 + 0x26) | 0x100;
  }
  LogEvent("FD0EntX",0,0,0);
  return 0;
}



===== RedirectedIoctlQueueEvtIoDeviceControl @ 140002b10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void RedirectedIoctlQueueEvtIoDeviceControl(undefined8 param_1,undefined8 param_2)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_2,PTR__WDF_REQUEST_CONTEXT_TYPE_INFO_140016108);
  IoctlRedirectToDevice(param_2,*puVar1);
  return;
}



===== IoctlRedirectToDevice @ 140002b60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void IoctlRedirectToDevice(undefined8 param_1,undefined8 param_2)

{
  longlong *plVar1;
  bool bVar2;
  undefined8 uVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  longlong lVar7;
  longlong lVar8;
  longlong lVar9;
  undefined8 *puVar10;
  undefined2 uVar11;
  char cVar12;
  undefined1 auStack_148 [32];
  char *local_128;
  undefined8 local_120;
  undefined8 local_118;
  undefined8 local_110;
  char local_f8;
  longlong local_f0;
  longlong local_e8;
  undefined8 local_e0;
  undefined8 local_d8;
  char *local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 local_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 local_98;
  undefined4 uStack_94;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined *local_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  ulonglong uStack_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_148;
  local_f0 = 0;
  uStack_b0 = 0;
  uStack_ac = 0;
  local_78 = (undefined *)((ulonglong)local_78 & 0xffffffff00000000);
  local_d0 = (char *)0x0;
  local_d8 = 0;
  local_f8 = '\0';
  local_c0 = 0;
  uStack_b8 = 0;
  uStack_b4 = 0;
  iVar5 = 0;
  bVar2 = false;
  local_a8 = 0;
  uStack_a4 = 0;
  uStack_a0 = 0;
  uStack_9c = 0;
  local_e8 = 0;
  local_98 = 0;
  uStack_94 = 0;
  uStack_90 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_e0 = param_1;
  local_c8 = param_2;
  LogEvent("RedirDev",0,0,0);
  lVar7 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_CHILD_DEVICE_EXTENSION_TYPE_INFO_1400160b8);
  local_50 = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_60 = 0;
  uStack_58 = 0;
  if ((lVar7 == 0) || (*(int *)(lVar7 + 0x30) != 3)) {
    iVar5 = -0x3ffffff3;
  }
  else {
    plVar1 = (longlong *)(lVar7 + 0x18);
    if (*plVar1 == 0) {
      iVar5 = ChildDeviceCreateIoTarget(param_2);
      if (-1 < iVar5) {
        if (*plVar1 != 0) goto LAB_140002cad;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2c,
                  &WPP_6b540f47682e3482637f60efce621d01_Traceguids);
        }
        iVar5 = -0x3fffff5d;
      }
    }
    else {
LAB_140002cad:
      (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,*(undefined8 *)(lVar7 + 0x60),0);
      lVar8 = *plVar1;
      if (lVar8 == 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2d,
                  &WPP_6b540f47682e3482637f60efce621d01_Traceguids);
        }
        iVar5 = -0x3ffffff2;
        lVar8 = local_e8;
      }
      else {
        local_128 = "onecore\\drivers\\storage\\enhancedstorage\\drivers\\ehstorclass\\ioctl.c";
        local_e8 = lVar8;
        (**(code **)(WdfFunctions_01015 + 0x668))
                  (WdfDriverGlobals,lVar8,IoctlRedirectToDevice,0x7e8);
      }
      (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,*(undefined8 *)(lVar7 + 0x60));
      uVar3 = local_e0;
      if (iVar5 < 0) {
LAB_140002d4c:
        cVar12 = '\0';
      }
      else {
        local_70 = CONCAT62(local_70._2_6_,0x28);
        (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,local_e0,&local_70);
        if (local_70._4_4_ != 0xe) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2e,
                    &WPP_6b540f47682e3482637f60efce621d01_Traceguids);
          }
          iVar5 = -0x3ffffff0;
          goto LAB_140002d4c;
        }
        iVar5 = (**(code **)(WdfFunctions_01015 + 0x858))(WdfDriverGlobals,uVar3,&local_d0);
        if (iVar5 != -0x3fffffdd) {
          if (-1 < iVar5) goto LAB_140002d8d;
          if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_140002d4c;
          uVar11 = 0x2f;
LAB_1400030e8:
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar11,
                   &WPP_6b540f47682e3482637f60efce621d01_Traceguids,iVar5);
          goto LAB_140002d4c;
        }
        local_d0 = (char *)0x0;
LAB_140002d8d:
        iVar5 = (**(code **)(WdfFunctions_01015 + 0x860))(WdfDriverGlobals,local_e0,&local_d8);
        if (iVar5 == -0x3fffffdd) {
          local_d8 = 0;
        }
        else if (iVar5 < 0) {
          if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_140002d4c;
          uVar11 = 0x30;
          goto LAB_1400030e8;
        }
        uStack_94 = 0;
        uStack_80 = 0;
        uStack_90 = 0x100000001;
        local_78 = PTR__WDF_IOCTL_REDIRECT_REQUEST_CONTEXT_TYPE_INFO_1400160e0;
        local_88 = local_c8;
        uStack_a4 = 0;
        uStack_a0 = 0;
        uStack_9c = 0;
        local_98 = 0;
        local_a8 = 0x38;
        iVar5 = (**(code **)(WdfFunctions_01015 + 0x7b8))
                          (WdfDriverGlobals,&local_a8,lVar8,&local_f0);
        if (iVar5 < 0) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar11 = 0x31;
LAB_140003158:
            WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar11,
                     &WPP_6b540f47682e3482637f60efce621d01_Traceguids,iVar5);
          }
LAB_140003167:
          if (local_f0 != 0) {
            (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
            local_f0 = 0;
          }
          iVar5 = 0;
        }
        else {
          local_110 = 0;
          local_118 = local_d8;
          local_120 = 0;
          local_128 = local_d0;
          iVar5 = (**(code **)(WdfFunctions_01015 + 0x5d8))
                            (WdfDriverGlobals,lVar8,local_f0,uStack_58 & 0xffffffff);
          if (iVar5 < 0) {
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              uVar11 = 0x32;
              goto LAB_140003158;
            }
            goto LAB_140003167;
          }
        }
        if (local_f0 == 0) {
          local_128 = (char *)0x0;
          iVar5 = KeWaitForSingleObject(lVar7 + 0x40,0,0,1);
          if (iVar5 < 0) {
            if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
               ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_140002d4c;
            uVar11 = 0x33;
            goto LAB_1400030e8;
          }
          bVar2 = true;
          cVar12 = '\x01';
          local_f0 = (**(code **)(WdfFunctions_01015 + 0x98))
                               (WdfDriverGlobals,*(undefined8 *)(lVar7 + 0x38));
          if (local_f0 == 0) {
            iVar5 = -0x3fffff66;
            cVar12 = local_f8;
          }
          else {
            (**(code **)(WdfFunctions_01015 + 0x80))
                      (WdfDriverGlobals,*(undefined8 *)(lVar7 + 0x38),local_f0);
            uStack_b4 = 0;
            uStack_b0 = 0;
            uStack_ac = 0;
            local_c0 = 0x18;
            uStack_b8 = 0;
            iVar5 = (**(code **)(WdfFunctions_01015 + 0x7c8))(WdfDriverGlobals,local_f0,&local_c0);
            if (-1 < iVar5) {
              local_110 = 0;
              local_118 = local_d8;
              local_120 = 0;
              local_128 = local_d0;
              iVar5 = (**(code **)(WdfFunctions_01015 + 0x5d8))
                                (WdfDriverGlobals,local_e8,local_f0,uStack_58 & 0xffffffff);
              local_f8 = '\x01';
              if (-1 < iVar5) goto LAB_140002e88;
              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x34,
                         &WPP_6b540f47682e3482637f60efce621d01_Traceguids,iVar5);
              }
            }
          }
        }
        else {
LAB_140002e88:
          lVar8 = (**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals,local_f0);
          lVar9 = (**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals,local_e0);
          *(uint *)(lVar8 + 0x10) = *(uint *)(lVar8 + 0x10) | *(uint *)(lVar9 + 0x10) & 0x40;
          puVar10 = (undefined8 *)
                    (**(code **)(WdfFunctions_01015 + 0x650))
                              (WdfDriverGlobals,local_f0,
                               PTR__WDF_IOCTL_REDIRECT_REQUEST_CONTEXT_TYPE_INFO_1400160e0);
          cVar12 = local_f8;
          *puVar10 = local_e0;
          puVar10[1] = local_c8;
          *(char *)(puVar10 + 2) = local_f8;
          (**(code **)(WdfFunctions_01015 + 0x820))
                    (WdfDriverGlobals,local_f0,IoctlRedirectionCompletionRoutine,0);
          cVar4 = (**(code **)(WdfFunctions_01015 + 0x7e8))(WdfDriverGlobals,local_f0,local_e8,0);
          if (cVar4 == '\0') {
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x35,
                      &WPP_6b540f47682e3482637f60efce621d01_Traceguids);
            }
            iVar5 = -0x3ffffe7d;
          }
        }
      }
      if (local_e8 != 0) {
        local_128 = "onecore\\drivers\\storage\\enhancedstorage\\drivers\\ehstorclass\\ioctl.c";
        (**(code **)(WdfFunctions_01015 + 0x670))
                  (WdfDriverGlobals,local_e8,IoctlRedirectToDevice,0x8c7);
      }
      if (-1 < iVar5) {
        return;
      }
      if (cVar12 != '\0') {
        iVar6 = (**(code **)(WdfFunctions_01015 + 0x78))
                          (WdfDriverGlobals,*(undefined8 *)(lVar7 + 0x38),local_f0);
        if (((iVar6 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x36,
                   &WPP_6b540f47682e3482637f60efce621d01_Traceguids,iVar6);
        }
        goto LAB_140002c4e;
      }
    }
  }
  if (local_f0 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
LAB_140002c4e:
  local_f0 = 0;
  if (bVar2) {
    KeReleaseSemaphore(lVar7 + 0x40,0,1);
  }
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,local_e0,iVar5);
  return;
}



===== DefaultQueueEvtDeviceControl @ 1400033c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void DefaultQueueEvtDeviceControl
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               uint param_5)

{
  uint uVar1;
  char cVar2;
  undefined1 uVar3;
  uint uVar4;
  int iVar5;
  longlong *plVar6;
  longlong lVar7;
  longlong lVar8;
  longlong lVar9;
  undefined8 uVar10;
  undefined2 uVar11;
  code *pcVar12;
  longlong lVar13;
  uint uVar14;
  uint uVar15;
  int *local_28 [2];
  
  local_28[0] = (int *)0x0;
  plVar6 = (longlong *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_2,PTR__WDF_REQUEST_CONTEXT_TYPE_INFO_140016108);
  lVar7 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
  lVar8 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,lVar7,PTR__WDF_FILTER_DEVICE_EXTENSION_TYPE_INFO_140016018);
  lVar13 = 0;
  lVar9 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,lVar7,PTR__WDF_FILTER_DEVICE_EXTENSION_TYPE_INFO_140016018);
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals);
  uVar4 = 0;
  uVar14 = *(uint *)(lVar9 + 0x1d0);
  while (uVar15 = uVar4, uVar4 + 1 < uVar14) {
    uVar15 = uVar14 + uVar4 >> 1;
    uVar1 = *(uint *)(*(longlong *)(lVar9 + 0x1c8) + (ulonglong)uVar15 * 0x10);
    if (param_5 < uVar1) {
      uVar14 = uVar15;
    }
    else {
      if (param_5 <= uVar1) break;
      uVar4 = uVar15 + 1;
    }
  }
  if (uVar15 < *(uint *)(lVar9 + 0x1d0)) {
    if (*(uint *)(*(longlong *)(lVar9 + 0x1c8) + (ulonglong)uVar15 * 0x10) == param_5) {
      lVar13 = *(longlong *)(*(longlong *)(lVar9 + 0x1c8) + 8 + (ulonglong)uVar15 * 0x10);
    }
  }
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals);
  if (lVar13 == 0) {
    if ((param_5 - 0x4d004 < 0x2d) &&
       ((0x110000010001U >> ((ulonglong)(param_5 - 0x4d004) & 0x3f) & 1) != 0)) {
      uVar4 = (**(code **)(WdfFunctions_01015 + 0x8c8))
                        (WdfDriverGlobals,param_2,*(undefined8 *)(lVar8 + 400));
      if (-1 < (int)uVar4) {
        return;
      }
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
        return;
      }
      uVar11 = 0x11;
    }
    else {
      if (param_5 != 0x2d1410) {
        if (((((*(uint *)(lVar8 + 0x130) & 0x20) != 0) || (param_5 != 0x2d1400)) ||
            (iVar5 = (**(code **)(WdfFunctions_01015 + 0x868))
                               (WdfDriverGlobals,param_2,0xc,local_28,0), iVar5 < 0)) ||
           ((*local_28[0] != 1 ||
            (pcVar12 = StorageQueryPropertyCompletionRoutine, local_28[0][1] != 0)))) {
          pcVar12 = RequestDummyCompletionRoutine;
        }
        (**(code **)(WdfFunctions_01015 + 0x7d8))(WdfDriverGlobals,param_2);
        uVar10 = (**(code **)(WdfFunctions_01015 + 0x650))
                           (WdfDriverGlobals,lVar7,
                            PTR__WDF_FILTER_DEVICE_EXTENSION_TYPE_INFO_140016018);
        (**(code **)(WdfFunctions_01015 + 0x820))(WdfDriverGlobals,param_2,pcVar12,uVar10);
        uVar10 = (**(code **)(WdfFunctions_01015 + 0x150))(WdfDriverGlobals,lVar7);
        cVar2 = (**(code **)(WdfFunctions_01015 + 0x7e8))(WdfDriverGlobals,param_2,uVar10,0);
        if (cVar2 != '\0') {
          return;
        }
        iVar5 = (**(code **)(WdfFunctions_01015 + 0x7f0))(WdfDriverGlobals,param_2);
        (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar5);
        if (-1 < iVar5) {
          return;
        }
        if ((char)plVar6[1] == '\x01') {
          KeSetEvent(plVar6 + 2,0,0);
          return;
        }
        return;
      }
      uVar4 = IoctlDeviceEnumeratePdos(lVar7,0,param_2);
      if (-1 < (int)uVar4) {
        return;
      }
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
        return;
      }
      uVar11 = 0x12;
    }
  }
  else {
    LogEvent("ChkRdr",(ulonglong)(param_5 >> 2 & 0xfff),0,0);
    *plVar6 = lVar13;
    uVar3 = KfRaiseIrql(2);
    uVar4 = (**(code **)(WdfFunctions_01015 + 0x8c8))
                      (WdfDriverGlobals,param_2,*(undefined8 *)(lVar8 + 0x1c0));
    KeLowerIrql(uVar3);
    if (-1 < (int)uVar4) {
      return;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return;
    }
    uVar11 = 0x10;
  }
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar11,
           &WPP_45305c62c3e63920635d5fbdd89541d2_Traceguids,uVar4);
  return;
}



===== LogEvent @ 140003880 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void LogEvent(void *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  ulonglong uVar1;
  ulonglong uVar2;
  longlong lVar3;
  size_t _Size;
  
  if ((g_Logger & 1) != 0) {
    (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,DAT_140016308);
    uVar2 = DAT_140016300;
    DAT_140016300 = DAT_140016300 + 1;
    if (0x7f < DAT_140016300) {
      DAT_140016300 = 0;
    }
    uVar1 = DAT_140016300;
    lVar3 = DAT_140016300 * 0x30;
    *(undefined8 *)(&DAT_140016310 + lVar3) = 0;
    *(undefined8 *)(&DAT_140016318 + lVar3) = 0;
    lVar3 = uVar1 * 0x30;
    *(undefined8 *)(&DAT_140016320 + lVar3) = 0;
    *(undefined8 *)(&DAT_140016328 + lVar3) = 0;
    lVar3 = uVar1 * 0x30;
    *(undefined8 *)(&DAT_140016330 + lVar3) = 0;
    *(undefined8 *)(&DAT_140016338 + lVar3) = 0;
    if ((DAT_140016300 == DAT_1400162f8) &&
       (DAT_1400162f8 = DAT_1400162f8 + 1, 0x7f < DAT_1400162f8)) {
      DAT_1400162f8 = 0;
    }
    (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,DAT_140016308);
    lVar3 = uVar2 * 0x30;
    _Size = 0xffffffffffffffff;
    *(undefined8 *)(&DAT_140016318 + lVar3) = _DAT_fffff78000000008;
    *(void **)(&DAT_140016320 + lVar3) = SystemReserved1[0xf];
    uVar2 = 0xffffffffffffffff;
    do {
      uVar2 = uVar2 + 1;
    } while (*(char *)((longlong)param_1 + uVar2) != '\0');
    if (uVar2 < 8) {
      do {
        _Size = _Size + 1;
      } while (*(char *)((longlong)param_1 + _Size) != '\0');
    }
    else {
      _Size = 8;
    }
    memmove(&DAT_140016310 + lVar3,param_1,_Size);
    *(undefined8 *)(&DAT_140016328 + lVar3) = param_2;
    *(undefined8 *)(&DAT_140016330 + lVar3) = param_3;
    *(undefined8 *)(&DAT_140016338 + lVar3) = param_4;
  }
  return;
}



===== McTemplateK0quuujuu_EtwWriteTransfer @ 140003a00 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0quuujuu_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined8 param_8,
               undefined1 param_9,undefined1 param_10)

{
  undefined4 local_res20 [2];
  undefined1 auStackY_c8 [32];
  undefined8 local_98 [2];
  undefined4 *local_88;
  undefined8 local_80;
  undefined1 *local_78;
  undefined8 local_70;
  undefined1 *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_c8;
  local_88 = local_res20;
  local_80 = 4;
  local_78 = &param_5;
  local_70 = 1;
  local_68 = &param_6;
  local_58 = &param_7;
  local_48 = param_8;
  local_38 = &param_9;
  local_28 = &param_10;
  local_60 = 1;
  local_50 = 1;
  local_40 = 0x10;
  local_30 = 1;
  local_20 = 1;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,param_3,8,local_98);
  return;
}



===== McGenEventWrite_EtwWriteTransfer @ 140003ac0 =====

void McGenEventWrite_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined8 *param_5)

{
  ushort *puVar1;
  undefined4 uVar2;
  uint uVar3;
  
  puVar1 = DAT_140016058;
  uVar2 = 0;
  if (DAT_140016058 == (ushort *)0x0) {
    *param_5 = 0;
    uVar3 = 0;
  }
  else {
    *param_5 = DAT_140016058;
    uVar2 = 2;
    uVar3 = (uint)*puVar1;
  }
  *(uint *)(param_5 + 1) = uVar3;
  *(undefined4 *)((longlong)param_5 + 0xc) = uVar2;
  EtwWriteTransfer(EhStorClassEventProvider_Context,param_2,0,0,param_4,param_5);
  return;
}



===== IssueSyncIoctl @ 140003b24 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int IssueSyncIoctl(undefined8 param_1,longlong *param_2,undefined8 param_3,undefined4 param_4,
                  longlong param_5,undefined4 param_6,longlong param_7,undefined4 param_8,
                  undefined8 *param_9)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  undefined1 auStack_c8 [32];
  longlong local_a8;
  undefined8 local_a0;
  longlong local_98;
  undefined8 local_90;
  undefined4 local_78;
  undefined8 local_70;
  undefined4 local_68;
  undefined8 local_64;
  undefined4 local_5c;
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_c8;
  uVar3 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_78 = param_4;
  if (*param_2 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,*param_2,0);
  }
  local_64 = 0;
  local_5c = 0;
  local_70 = 0x18;
  local_68 = 0;
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x7c8))(WdfDriverGlobals,param_2[1],&local_70);
  if (-1 < iVar2) {
    if (param_5 != 0) {
      iVar2 = (**(code **)(WdfFunctions_01015 + 0x618))(WdfDriverGlobals,param_2[2],param_5,param_6)
      ;
      if (iVar2 < 0) goto LAB_140003d50;
    }
    if (param_7 != 0) {
      iVar2 = (**(code **)(WdfFunctions_01015 + 0x618))(WdfDriverGlobals,param_2[3],param_7,param_8)
      ;
    }
    if (-1 < iVar2) {
      if (param_7 == 0) {
        local_98 = 0;
      }
      else {
        local_98 = param_2[3];
      }
      if (param_5 == 0) {
        local_a8 = 0;
      }
      else {
        local_a8 = param_2[2];
      }
      local_90 = 0;
      local_a0 = 0;
      iVar2 = (**(code **)(WdfFunctions_01015 + 0x5d8))
                        (WdfDriverGlobals,param_1,param_2[1],local_78);
      if (-1 < iVar2) {
        local_58 = 0x300000010;
        uStack_50 = 0xffffffffff676980;
        cVar1 = (**(code **)(WdfFunctions_01015 + 0x7e8))
                          (WdfDriverGlobals,param_2[1],param_1,&local_58);
        if (cVar1 == '\0') {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                    &WPP_3cd491e07ee83ecda6dcbf116627806f_Traceguids);
          }
          iVar2 = -0x3ffffe7d;
        }
        else {
          iVar2 = (**(code **)(WdfFunctions_01015 + 0x7f0))(WdfDriverGlobals,param_2[1]);
          uVar3 = (**(code **)(WdfFunctions_01015 + 0x8a0))(WdfDriverGlobals,param_2[1]);
        }
      }
    }
  }
LAB_140003d50:
  if (*param_2 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals);
  }
  if (param_9 != (undefined8 *)0x0) {
    *param_9 = uVar3;
  }
  return iVar2;
}



===== FilterDeviceSend1667Probe @ 140003dac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint FilterDeviceSend1667Probe(undefined8 param_1,longlong *param_2,uint *param_3,ulonglong param_4)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  longlong lVar4;
  undefined4 *puVar5;
  longlong lVar6;
  byte bVar7;
  undefined2 uVar8;
  uint uVar9;
  undefined7 uVar11;
  undefined *puVar10;
  uint uVar12;
  int iVar13;
  bool bVar14;
  bool bVar15;
  uint local_48;
  uint local_44;
  
  uVar3 = 0;
  lVar6 = 0;
  uVar9 = 0;
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FILTER_DEVICE_EXTENSION_TYPE_INFO_140016018);
  local_44 = *(uint *)(lVar4 + 300) & 2;
  bVar15 = local_44 == 0;
  uVar12 = -(uint)(local_44 != 0) & 0xfffffe01;
  iVar13 = uVar12 + 0x200;
  bVar7 = ~-(local_44 != 0) & 9;
  local_48 = (uVar12 + 0x21f >> bVar7) * iVar13;
  puVar5 = (undefined4 *)ExAllocatePool2(0x40,local_48,0x47536353);
  if (puVar5 == (undefined4 *)0x0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      uVar8 = 0xf;
LAB_140003f62:
      param_4 = (ulonglong)local_48;
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar8,
               &WPP_94719a13e7d8366cd9a87695c567288d_Traceguids,local_48);
    }
LAB_140003f76:
    uVar3 = 0xc000009a;
  }
  else {
    puVar5[3] = 0x1011001;
    *(undefined2 *)(puVar5 + 2) = 0x101;
    *puVar5 = 0x20000000;
    uVar2 = *(uint *)(lVar4 + 0x24);
    puVar5[7] = (uVar2 << 0x10 | uVar2 & 0xff00) << 8 | uVar2 >> 8 & 0xff00 |
                (uint)*(byte *)(lVar4 + 0x27);
    uVar2 = *(uint *)(lVar4 + 0x18);
    puVar5[4] = (uVar2 << 0x10 | uVar2 & 0xff00) << 8 | uVar2 >> 8 & 0xff00 |
                (uint)*(byte *)(lVar4 + 0x1b);
    uVar2 = *(uint *)(lVar4 + 0x1c);
    puVar5[5] = (uVar2 << 0x10 | uVar2 & 0xff00) << 8 | uVar2 >> 8 & 0xff00 |
                (uint)*(byte *)(lVar4 + 0x1f);
    local_48 = (uVar12 + 0x20d >> bVar7) * iVar13;
    lVar6 = ExAllocatePool2();
    if (lVar6 == 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar8 = 0x10;
        goto LAB_140003f62;
      }
      goto LAB_140003f76;
    }
  }
  if (**(longlong **)(lVar4 + 0x1b8) != 0) {
    (**(code **)(WdfFunctions_01015 + 0x9c8))();
  }
  if (-1 < (int)uVar3) {
    uVar3 = IssueSecurityProtocolOut
                      (*(undefined8 *)(lVar4 + 0x198),*(longlong *)(lVar4 + 0x1b8),bVar15,param_4,0,
                       1,(longlong)puVar5,((-(uint)(local_44 != 0) & 0x1f) + 1) * iVar13,
                       *(char *)(lVar4 + 0x180),0);
    if ((int)uVar3 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        param_4 = (ulonglong)uVar3;
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
                 &WPP_94719a13e7d8366cd9a87695c567288d_Traceguids,uVar3);
      }
    }
    else {
      param_4 = CONCAT71((int7)(param_4 >> 8),0xee);
      uVar3 = IssueSecurityProtocolIn
                        (*(undefined8 *)(lVar4 + 0x198),*(longlong *)(lVar4 + 0x1b8),
                         (ulonglong)bVar15,0xee,0,1,lVar6,&local_48,*(char *)(lVar4 + 0x180),0);
      if (-1 < (int)uVar3) {
        param_4 = (ulonglong)local_48;
        if (local_48 < 0xe) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
                     &WPP_94719a13e7d8366cd9a87695c567288d_Traceguids,local_48);
          }
          if ((Microsoft_Windows_EnhancedStorage_ClassDriverEnableBits & 2) != 0) {
            param_4 = (ulonglong)*(byte *)(lVar4 + 0x174);
            McTemplateK0quuujzdzxzxzxzx_EtwWriteTransfer();
          }
          uVar3 = 0xc000009c;
        }
        goto LAB_140004286;
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        param_4 = (ulonglong)uVar3;
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
                 &WPP_94719a13e7d8366cd9a87695c567288d_Traceguids,uVar3);
      }
    }
    if ((Microsoft_Windows_EnhancedStorage_ClassDriverEnableBits & 2) != 0) {
      param_4 = (ulonglong)*(byte *)(lVar4 + 0x174);
      McTemplateK0quuujzdzxzxzxzx_EtwWriteTransfer();
    }
  }
LAB_140004286:
  if (**(longlong **)(lVar4 + 0x1b8) != 0) {
    (**(code **)(WdfFunctions_01015 + 0x9d0))();
  }
  puVar10 = (undefined *)0x0;
  if (-1 < (int)uVar3) {
    bVar1 = *(byte *)(lVar6 + 7);
    if (bVar1 < 2) {
      uVar9 = *(uint *)(lVar6 + 8);
      uVar9 = (uVar9 << 0x10 | uVar9 & 0xff00) << 8 | uVar9 >> 8 & 0xff00 |
              (uint)*(byte *)(lVar6 + 0xb);
      if (uVar9 == 0) {
        uVar9 = (uint)(byte)*(ushort *)(lVar6 + 0xc) << 8 | (uint)(*(ushort *)(lVar6 + 0xc) >> 8);
        uVar9 = uVar9 + (-(uint)(uVar9 != 0) & 0xe);
      }
      if (uVar9 != 0) {
        ExFreePoolWithTag(lVar6,0);
        puVar10 = (undefined *)0x47536353;
        local_48 = (uVar12 + 0x1ff + uVar9 >> bVar7) * iVar13;
        lVar6 = ExAllocatePool2(0x40,local_48,0x47536353);
        if (lVar6 == 0) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            param_4 = (ulonglong)local_48;
            puVar10 = &WPP_94719a13e7d8366cd9a87695c567288d_Traceguids;
            WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
                     &WPP_94719a13e7d8366cd9a87695c567288d_Traceguids,local_48);
          }
          uVar3 = 0xc000009a;
        }
      }
    }
    else {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        param_4 = (ulonglong)(uint)bVar1;
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
                 &WPP_94719a13e7d8366cd9a87695c567288d_Traceguids,(uint)bVar1);
      }
      puVar10 = (undefined *)0x0;
      if ((Microsoft_Windows_EnhancedStorage_ClassDriverEnableBits & 2) != 0) {
        param_4 = (ulonglong)*(byte *)(lVar4 + 0x174);
        McTemplateK0quuujzdzxzxzxzx_EtwWriteTransfer();
      }
      uVar3 = 0xc000009c;
    }
  }
  if (**(longlong **)(lVar4 + 0x1b8) != 0) {
    puVar10 = (undefined *)0x0;
    (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,**(longlong **)(lVar4 + 0x1b8),0);
  }
  if ((-1 < (int)uVar3) && (uVar9 != 0)) {
    bVar14 = local_44 != 0;
    local_44 = -local_44;
    uVar11 = (undefined7)((ulonglong)puVar10 >> 8);
    uVar3 = IssueSecurityProtocolOut
                      (*(undefined8 *)(lVar4 + 0x198),*(longlong *)(lVar4 + 0x1b8),bVar15,param_4,0,
                       1,(longlong)puVar5,((-(uint)bVar14 & 0x1f) + 1) * iVar13,
                       *(char *)(lVar4 + 0x180),0);
    if ((int)uVar3 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
                 &WPP_94719a13e7d8366cd9a87695c567288d_Traceguids,uVar3);
      }
    }
    else {
      uVar3 = IssueSecurityProtocolIn
                        (*(undefined8 *)(lVar4 + 0x198),*(longlong *)(lVar4 + 0x1b8),
                         CONCAT71(uVar11,bVar15),0xee,0,1,lVar6,&local_48,*(char *)(lVar4 + 0x180),0
                        );
      if (-1 < (int)uVar3) {
        if (local_48 < uVar9) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
                      &WPP_94719a13e7d8366cd9a87695c567288d_Traceguids,local_48,(char)uVar9);
          }
          if ((Microsoft_Windows_EnhancedStorage_ClassDriverEnableBits & 2) != 0) {
            McTemplateK0quuujzdzxzxzxzx_EtwWriteTransfer();
          }
          uVar3 = 0xc000009c;
        }
        goto LAB_140004744;
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
                 &WPP_94719a13e7d8366cd9a87695c567288d_Traceguids,uVar3);
      }
    }
    if ((Microsoft_Windows_EnhancedStorage_ClassDriverEnableBits & 2) != 0) {
      McTemplateK0quuujzdzxzxzxzx_EtwWriteTransfer();
    }
  }
LAB_140004744:
  if (**(longlong **)(lVar4 + 0x1b8) != 0) {
    (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals);
  }
  if (-1 < (int)uVar3) {
    if (*(byte *)(lVar6 + 7) < 2) {
      if (param_2 != (longlong *)0x0) {
        *param_2 = lVar6;
        *param_3 = local_48;
        goto LAB_140004855;
      }
    }
    else {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
                 &WPP_94719a13e7d8366cd9a87695c567288d_Traceguids,(uint)*(byte *)(lVar6 + 7));
      }
      if ((Microsoft_Windows_EnhancedStorage_ClassDriverEnableBits & 2) != 0) {
        McTemplateK0quuujzdzxzxzxzx_EtwWriteTransfer();
      }
      uVar3 = 0xc000009c;
    }
  }
  if (lVar6 != 0) {
    ExFreePoolWithTag(lVar6,0);
  }
LAB_140004855:
  if (puVar5 != (undefined4 *)0x0) {
    ExFreePoolWithTag(puVar5,0);
  }
  return uVar3;
}



===== IoctlDeviceSendSiloCommand @ 1400048a8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint IoctlDeviceSendSiloCommand(undefined8 param_1,ulonglong param_2)

{
  uint uVar1;
  undefined4 uVar2;
  undefined8 *puVar3;
  longlong lVar4;
  longlong lVar5;
  uint *puVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  ulonglong *puVar9;
  ulonglong uVar10;
  int iVar11;
  uint uVar12;
  undefined1 auStackY_128 [32];
  ulonglong local_98;
  ulonglong local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  ulonglong local_70;
  ulonglong local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_128;
  local_88 = 0;
  lVar5 = 0;
  local_90 = 0;
  puVar6 = (uint *)0x0;
  local_80 = 0;
  uVar10 = 5;
  local_98 = 0;
  local_70 = param_2;
  puVar3 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_CHILD_DEVICE_EXTENSION_TYPE_INFO_1400160b8);
  local_78 = *puVar3;
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,local_78,PTR__WDF_FILTER_DEVICE_EXTENSION_TYPE_INFO_140016018)
  ;
  local_48 = 0;
  uStack_60 = 0;
  local_68 = 0x28;
  local_58 = 0;
  uStack_50 = 0;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_68);
  if (*(int *)(puVar3 + 6) != 3) {
    uVar1 = 0xc00000bb;
    goto LAB_140004b30;
  }
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x858))(WdfDriverGlobals,param_2,&local_88);
  if ((int)uVar1 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
               &WPP_6b540f47682e3482637f60efce621d01_Traceguids,uVar1);
    }
    goto LAB_140004b30;
  }
  uVar7 = local_88;
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,local_88,&local_90);
  if ((lVar5 == 0) || (local_90 < 8)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_qP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar7,&WPP_GLOBAL_Control,lVar5,
                (char)local_90);
    }
LAB_140004b27:
    uVar1 = 0xc000000d;
  }
  else {
    uVar1 = (**(code **)(WdfFunctions_01015 + 0x860))(WdfDriverGlobals,local_70,&local_80);
    if ((int)uVar1 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
                 &WPP_6b540f47682e3482637f60efce621d01_Traceguids,uVar1);
      }
    }
    else {
      puVar6 = (uint *)(**(code **)(WdfFunctions_01015 + 0x610))
                                 (WdfDriverGlobals,local_80,&local_98);
      uVar8 = local_90 - 8;
      if (uVar8 < *(uint *)(lVar5 + 4)) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_dP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar8,&WPP_GLOBAL_Control,
                    *(uint *)(lVar5 + 4),(char)uVar8);
        }
        goto LAB_140004b27;
      }
    }
  }
  param_2 = local_70;
LAB_140004b30:
  if (*(longlong *)puVar3[5] != 0) {
    (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,*(longlong *)puVar3[5],0);
  }
  if (-1 < (int)uVar1) {
LAB_140004b61:
    iVar11 = (int)uVar10;
    if (*(int *)(lVar4 + 0x128) == 1) {
      uVar1 = SiloCommandToTCGCommand(local_78,(longlong *)puVar3[5],lVar5,puVar6,&local_98);
    }
    else {
      LogEvent("SiloCmdE",(ulonglong)*(uint *)((longlong)puVar3 + 0x7c),
               (ulonglong)*(byte *)(lVar5 + 1),uVar10);
      local_70 = 0;
      uVar1 = *(uint *)(lVar5 + 4);
      if (uVar1 == 0) {
        puVar9 = &local_70;
        uVar1 = 8;
      }
      else {
        puVar9 = (ulonglong *)(lVar5 + 8);
      }
      uVar1 = IssueSecurityProtocolOut
                        (*(undefined8 *)(lVar4 + 0x198),puVar3[5],
                         ~(byte)(*(uint *)(lVar4 + 300) >> 1) & 1,uVar10,
                         *(undefined1 *)(puVar3 + 0x10),*(undefined1 *)(lVar5 + 1),(longlong)puVar9,
                         uVar1,*(char *)(lVar4 + 0x180),(*(uint *)(lVar4 + 0x130) & 0x40) << 5);
      if ((int)uVar1 < 0) {
joined_r0x000140004d0f:
        if ((Microsoft_Windows_EnhancedStorage_ClassDriverEnableBits & 2) != 0) {
          McTemplateK0quuujzdzxzxzxzx_EtwWriteTransfer();
        }
      }
      else {
        uVar2 = (undefined4)local_98;
        if (0xffffffff < local_98) {
          uVar2 = 0xffffffff;
        }
        local_70 = CONCAT44(local_70._4_4_,uVar2);
        uVar1 = IssueSecurityProtocolIn
                          (*(undefined8 *)(lVar4 + 0x198),puVar3[5],
                           (ulonglong)
                           CONCAT31((uint3)(*(uint *)(lVar4 + 300) >> 9),
                                    ~(byte)(*(uint *)(lVar4 + 300) >> 1)) & 0xffffffffffffff01,0xee,
                           *(undefined1 *)(puVar3 + 0x10),*(undefined1 *)(lVar5 + 1),
                           (longlong)puVar6,(uint *)&local_70,*(char *)(lVar4 + 0x180),
                           (*(uint *)(lVar4 + 0x130) & 0x40) << 5);
        local_98 = local_70 & 0xffffffff;
        if ((int)uVar1 < 0) goto joined_r0x000140004d0f;
      }
      LogEvent("SiloCmdX",(ulonglong)*(uint *)((longlong)puVar3 + 0x7c),
               (ulonglong)*(byte *)(lVar5 + 1),(longlong)(int)uVar1);
    }
    uVar12 = iVar11 - 1;
    uVar10 = (ulonglong)uVar12;
    if (uVar1 == 0xc0000185) {
      if ((*(char *)(puVar3[5] + 0x23) != '\x0e') || (uVar12 == 0)) goto LAB_140004e24;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (2 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
                &WPP_6b540f47682e3482637f60efce621d01_Traceguids);
      }
      goto LAB_140004b61;
    }
    if (-1 < (int)uVar1) goto LAB_140004e29;
  }
LAB_140004e24:
  local_98 = 0;
LAB_140004e29:
  if (*(longlong *)puVar3[5] != 0) {
    (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals);
  }
  (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,param_2,uVar1,local_98);
  return uVar1;
}



===== IssueZeroLengthSecurityProtocolIn @ 140004ea4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int IssueZeroLengthSecurityProtocolIn(undefined8 param_1,longlong param_2,char param_3,char param_4)

{
  int iVar1;
  undefined1 auStackY_78 [32];
  undefined7 in_stack_ffffffffffffffa9;
  undefined4 in_stack_ffffffffffffffc4;
  uint local_28 [2];
  undefined8 local_20;
  undefined8 uStack_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_78;
  local_28[0] = 0;
  uStack_18 = 0;
  local_20 = (ulonglong)CONCAT14(-(param_3 != '\0') & 0x80,0xa2);
  iVar1 = IssueSyncScsiCommand
                    (param_1,param_2,'\x01',(byte *)&local_20,
                     CONCAT71(in_stack_ffffffffffffffa9,0xc),0,local_28,
                     CONCAT44(in_stack_ffffffffffffffc4,0x14),param_4,0);
  if (((iVar1 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
     (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
             &WPP_66125b4cf8143944cb9284854ee08e62_Traceguids,iVar1);
  }
  return iVar1;
}



===== IssueSecurityProtocolOut @ 140004f6c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int IssueSecurityProtocolOut
              (undefined8 param_1,longlong param_2,char param_3,undefined8 param_4,
              undefined1 param_5,undefined1 param_6,longlong param_7,uint param_8,char param_9,
              uint param_10)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  undefined1 auStackY_88 [32];
  undefined4 in_stack_ffffffffffffff98;
  undefined4 in_stack_ffffffffffffff9c;
  undefined4 in_stack_ffffffffffffffb4;
  undefined8 local_38;
  ulonglong uStack_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_88;
  uStack_30 = 0;
  local_38._0_4_ = CONCAT13(param_6,CONCAT12(param_5,0xeeb5));
  uVar2 = (uint)local_38;
  local_38 = (ulonglong)(uint)local_38;
  if (param_3 == '\x01') {
    if ((param_8 & 0x1ff) != 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
                 &WPP_66125b4cf8143944cb9284854ee08e62_Traceguids,param_8);
      }
      return -0x3ffffdfa;
    }
    uVar1 = CONCAT11((char)(param_8 >> 9),(char)((param_8 >> 9) >> 8));
    local_38._0_7_ = (uint7)CONCAT14(0x80,uVar2);
    local_38 = CONCAT17(param_8._3_1_ >> 1,(uint7)local_38);
  }
  else {
    uVar1 = CONCAT11((undefined1)param_8,param_8._1_1_);
    local_38 = CONCAT17(param_8._2_1_,CONCAT16(param_8._3_1_,(uint6)uVar2));
  }
  uStack_30 = (ulonglong)uVar1;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    in_stack_ffffffffffffff98 = 0;
    WPP_SF_DdD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,WPP_GLOBAL_Control,0xee,param_5,
               param_6);
  }
  iVar3 = IssueSyncScsiCommand
                    (param_1,param_2,'\0',(byte *)&local_38,
                     CONCAT44(in_stack_ffffffffffffff9c,
                              CONCAT31((int3)((uint)in_stack_ffffffffffffff98 >> 8),0xc)),param_7,
                     &param_8,CONCAT44(in_stack_ffffffffffffffb4,0x14),param_9,param_10);
  if (((iVar3 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
     (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
             &WPP_66125b4cf8143944cb9284854ee08e62_Traceguids,iVar3);
  }
  return iVar3;
}



===== IssueSecurityProtocolIn @ 140005110 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int IssueSecurityProtocolIn
              (undefined8 param_1,longlong param_2,undefined8 param_3,byte param_4,
              undefined1 param_5,undefined1 param_6,longlong param_7,uint *param_8,char param_9,
              uint param_10)

{
  uint uVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  undefined1 auStackY_98 [32];
  undefined4 in_stack_ffffffffffffff88;
  undefined4 in_stack_ffffffffffffff8c;
  undefined4 in_stack_ffffffffffffffa4;
  undefined8 local_48;
  ulonglong uStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_98;
  uStack_40 = 0;
  local_48._0_4_ = CONCAT13(param_6,CONCAT12(param_5,CONCAT11(param_4,0xa2)));
  uVar3 = (uint)local_48;
  local_48 = (ulonglong)(uint)local_48;
  if ((char)param_3 == '\x01') {
    uVar1 = *param_8;
    if ((uVar1 & 0x1ff) != 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
                 &WPP_66125b4cf8143944cb9284854ee08e62_Traceguids,uVar1);
      }
      return -0x3ffffdfa;
    }
    uVar2 = CONCAT11((char)(uVar1 >> 9),(char)((uVar1 >> 9) >> 8));
    local_48._0_7_ = (uint7)CONCAT14(0x80,uVar3);
    local_48 = CONCAT17((byte)(uVar1 >> 0x19),(uint7)local_48);
  }
  else {
    uVar2 = CONCAT11((char)*param_8,*(undefined1 *)((longlong)param_8 + 1));
    local_48 = CONCAT17(*(undefined1 *)((longlong)param_8 + 2),
                        CONCAT16(*(undefined1 *)((longlong)param_8 + 3),(uint6)uVar3));
  }
  uStack_40 = (ulonglong)uVar2;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    in_stack_ffffffffffffff88 = 0;
    WPP_SF_DdD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,param_3,(uint)param_4,param_5,param_6
              );
  }
  iVar4 = IssueSyncScsiCommand
                    (param_1,param_2,'\x01',(byte *)&local_48,
                     CONCAT44(in_stack_ffffffffffffff8c,
                              CONCAT31((int3)((uint)in_stack_ffffffffffffff88 >> 8),0xc)),param_7,
                     param_8,CONCAT44(in_stack_ffffffffffffffa4,0x14),param_9,param_10);
  if (((iVar4 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
     (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
             &WPP_66125b4cf8143944cb9284854ee08e62_Traceguids,iVar4);
  }
  return iVar4;
}



===== IssueSyncScsiCommand @ 1400052b4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int IssueSyncScsiCommand
              (undefined8 param_1,longlong param_2,char param_3,byte *param_4,undefined8 param_5,
              longlong param_6,uint *param_7,undefined8 param_8,char param_9,uint param_10)

{
  undefined2 *puVar1;
  undefined8 *puVar2;
  byte *pbVar3;
  longlong lVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  bool bVar8;
  bool bVar9;
  char cVar10;
  uint uVar11;
  uint uVar12;
  byte bVar13;
  byte bVar14;
  undefined2 uVar15;
  byte bVar16;
  int iVar17;
  undefined1 auStackY_168 [32];
  byte local_108;
  longlong local_100;
  longlong local_e8;
  undefined8 local_70;
  undefined4 local_68;
  undefined8 local_64;
  undefined4 local_5c;
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_168;
  local_58 = 0;
  uStack_50 = 0;
  local_100 = 0;
  puVar1 = (undefined2 *)(param_2 + 0x20);
  pbVar3 = (byte *)(param_2 + 0xd8);
  local_e8 = 0;
  bVar9 = false;
  local_64 = 0;
  local_5c = 0;
  local_70 = 0x18;
  local_68 = 0;
  puVar2 = (undefined8 *)(param_2 + 8);
  iVar17 = (**(code **)(WdfFunctions_01015 + 0x7c8))(WdfDriverGlobals,*puVar2,&local_70);
  if (-1 < iVar17) {
    if (*param_7 == 0) {
      iVar17 = 0x1b0013;
    }
    else {
      iVar17 = 0x1b0012 - (uint)(param_3 != '\0');
    }
    iVar17 = (**(code **)(WdfFunctions_01015 + 0x5f8))(WdfDriverGlobals,param_1,*puVar2,iVar17);
  }
  if ((-1 < iVar17) && (param_6 != 0)) {
    local_100 = (**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals,*puVar2);
    local_e8 = IoAllocateMdl(param_6,*param_7,0,0);
    if (local_e8 == 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
                &WPP_66125b4cf8143944cb9284854ee08e62_Traceguids);
      }
      iVar17 = -0x3fffff66;
    }
    MmProbeAndLockPages(local_e8,0,param_3 != '\0');
    bVar9 = true;
    *(longlong *)(local_100 + 8) = local_e8;
  }
  if (iVar17 < 0) {
LAB_140005ade:
    if (iVar17 != -0x7ffffffb) goto LAB_140005b0d;
    if (param_9 == '\x01') {
      uVar11 = *(uint *)(param_2 + 0x5c);
    }
    else {
      uVar11 = *(uint *)(param_2 + 0x30);
    }
    if (*param_7 <= uVar11) goto LAB_140005b0d;
    *param_7 = uVar11;
  }
  else {
    local_100 = (**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals);
    lVar4 = *(longlong *)(local_100 + 0xb8);
    *(undefined1 *)(lVar4 + -0x46) = 2;
    *(undefined2 **)(lVar4 + -0x40) = puVar1;
    memset((void *)(param_2 + 0x22),0,0xb6);
    pbVar3[0] = 0;
    pbVar3[1] = 0;
    pbVar3[2] = 0;
    pbVar3[3] = 0;
    pbVar3[4] = 0;
    pbVar3[5] = 0;
    pbVar3[6] = 0;
    pbVar3[7] = 0;
    *(undefined8 *)(param_2 + 0xe0) = 0;
    *(undefined2 *)(param_2 + 0xe8) = 0;
    *(undefined1 *)(param_2 + 0x23) = 0;
    if (param_9 == '\x01') {
      *(undefined1 *)(param_2 + 0x22) = 0x28;
      *(undefined4 *)(param_2 + 0x28) = 0x53524258;
      *(undefined4 *)(param_2 + 0x2c) = 1;
      *(undefined4 *)(param_2 + 0x40) = 0xff;
      *(undefined2 *)(param_2 + 0x46) = 0x20;
      *(undefined4 *)(param_2 + 0x54) = 0x80;
      *puVar1 = 8;
      *(undefined4 *)(param_2 + 0x30) = 0xb8;
      *(undefined4 *)(param_2 + 0x34) = 0;
      *(undefined8 *)(param_2 + 0x90) = 0;
      *(longlong *)(param_2 + 0x70) = local_100;
      *(undefined4 *)(param_2 + 0x48) = 0x14;
      *(uint *)(param_2 + 0x5c) = *param_7;
      *(undefined4 *)(param_2 + 0x58) = 1;
      *(undefined4 *)(param_2 + 0x98) = 0x90;
      uVar11 = *(uint *)(param_2 + 0x38) | 0x80118 | param_10;
      *(uint *)(param_2 + 0x38) = uVar11;
      if (*param_7 != 0) {
        if (param_3 == '\0') {
          uVar11 = uVar11 | 0x80;
        }
        else {
          uVar11 = uVar11 | 0x40;
        }
      }
      *(uint *)(param_2 + 0x38) = uVar11;
      if (param_6 != 0) {
        *(ulonglong *)(param_2 + 0x60) =
             (ulonglong)*(uint *)(*(longlong *)(local_100 + 8) + 0x2c) +
             *(longlong *)(*(longlong *)(local_100 + 8) + 0x20);
      }
      *(undefined2 *)(param_2 + 0xa0) = 1;
      *(undefined4 *)(param_2 + 0xa4) = 4;
      *(undefined4 *)(param_2 + 0xb0) = 0x40;
      *(undefined4 *)(param_2 + 0xb4) = 0x20;
      *(undefined2 *)(param_2 + 0xb8) = 0x1200;
      *(byte **)(param_2 + 0xc0) = pbVar3;
      *(undefined1 *)(param_2 + 0xba) = 0xc;
      uVar5 = *(undefined4 *)(param_4 + 4);
      uVar6 = *(undefined4 *)(param_4 + 8);
      uVar7 = *(undefined4 *)(param_4 + 0xc);
      *(undefined4 *)(param_2 + 200) = *(undefined4 *)param_4;
      *(undefined4 *)(param_2 + 0xcc) = uVar5;
      *(undefined4 *)(param_2 + 0xd0) = uVar6;
      *(undefined4 *)(param_2 + 0xd4) = uVar7;
    }
    else {
      *(undefined2 *)(param_2 + 0x28) = 0x20ff;
      *puVar1 = 0x58;
      *(undefined1 *)(param_2 + 0x22) = 0;
      *(undefined1 *)(param_2 + 0x24) = 0;
      *(undefined8 *)(param_2 + 0x48) = 0;
      *(longlong *)(param_2 + 0x50) = local_100;
      *(byte **)(param_2 + 0x40) = pbVar3;
      *(undefined1 *)(param_2 + 0x2b) = 0x12;
      *(undefined4 *)(param_2 + 0x34) = 0x14;
      uVar11 = *(uint *)(param_2 + 0x2c) | 0x80118 | param_10;
      *(uint *)(param_2 + 0x2c) = uVar11;
      if (*param_7 != 0) {
        if (param_3 == '\0') {
          uVar11 = uVar11 | 0x80;
        }
        else {
          uVar11 = uVar11 | 0x40;
        }
      }
      *(uint *)(param_2 + 0x2c) = uVar11;
      if (param_6 != 0) {
        *(ulonglong *)(param_2 + 0x38) =
             (ulonglong)*(uint *)(*(longlong *)(local_100 + 8) + 0x2c) +
             *(longlong *)(*(longlong *)(local_100 + 8) + 0x20);
      }
      *(uint *)(param_2 + 0x30) = *param_7;
      uVar5 = *(undefined4 *)(param_4 + 4);
      uVar6 = *(undefined4 *)(param_4 + 8);
      uVar7 = *(undefined4 *)(param_4 + 0xc);
      *(undefined4 *)(param_2 + 0x68) = *(undefined4 *)param_4;
      *(undefined4 *)(param_2 + 0x6c) = uVar5;
      *(undefined4 *)(param_2 + 0x70) = uVar6;
      *(undefined4 *)(param_2 + 0x74) = uVar7;
      *(undefined1 *)(param_2 + 0x2a) = 0xc;
    }
    if (iVar17 < 0) goto LAB_140005ade;
    local_58 = 0x300000010;
    uStack_50 = 0xffffffffee1e5d00;
    cVar10 = (**(code **)(WdfFunctions_01015 + 0x7e8))(WdfDriverGlobals,*puVar2,param_1,&local_58);
    if (cVar10 == '\0') {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                &WPP_66125b4cf8143944cb9284854ee08e62_Traceguids);
      }
      iVar17 = -0x3ffffe7d;
      goto LAB_140005b0d;
    }
    iVar17 = (**(code **)(WdfFunctions_01015 + 0x7f0))(WdfDriverGlobals,*puVar2);
    if (iVar17 < 0) goto LAB_140005ade;
    if (param_9 == '\x01') {
      uVar11 = *(uint *)(param_2 + 0x5c);
    }
    else {
      uVar11 = *(uint *)(param_2 + 0x30);
    }
    bVar13 = *(byte *)(param_2 + 0x23);
    if ((bVar13 & 0x3f) != 1) {
      local_108 = 0;
      bVar16 = 0;
      bVar14 = 0;
      bVar8 = false;
      if ((char)bVar13 < '\0') {
        if (pbVar3 != (byte *)0x0) {
          if ((byte)((*pbVar3 & 0x7f) + 0x8e) < 2) {
            if (param_2 + 0xe0U <= param_2 + 0xeaU) {
              local_108 = *(byte *)(param_2 + 0xd9) & 0xf;
              bVar16 = *(byte *)(param_2 + 0xda);
              bVar14 = *(byte *)(param_2 + 0xdb);
              goto LAB_140005973;
            }
          }
          else if (param_2 + 0xe0U <= param_2 + 0xeaU) {
            uVar12 = *(byte *)(param_2 + 0xdf) + 8;
            if (0x12 < uVar12) {
              uVar12 = 0x12;
            }
            local_108 = *(byte *)(param_2 + 0xda) & 0xf;
            if ((byte *)(param_2 + 0xe5U) <= pbVar3 + uVar12) {
              bVar16 = *(byte *)(param_2 + 0xe4);
            }
            if (pbVar3 + uVar12 < (byte *)(param_2 + 0xe6U)) {
              bVar14 = 0;
            }
            else {
              bVar14 = *(byte *)(param_2 + 0xe5U);
            }
LAB_140005973:
            bVar8 = true;
          }
        }
        if (bVar8) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_DDDDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(ulonglong)bVar16,
                         (ulonglong)local_108,(uint)*param_4,bVar13,local_108,bVar16,bVar14);
          }
        }
        else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar15 = 0xe;
          goto LAB_140005a0b;
        }
      }
      else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar15 = 0xf;
LAB_140005a0b:
        WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar15,
                  &WPP_66125b4cf8143944cb9284854ee08e62_Traceguids,(uint)*param_4,bVar13);
      }
      bVar13 = *(byte *)(param_2 + 0x23) & 0x3f;
      if (bVar13 < 0xf) {
        if (bVar13 != 0xe) {
          if (bVar13 == 2) goto LAB_140005a67;
          if (bVar13 != 4) {
            if (bVar13 == 6) {
              iVar17 = -0x3ffffff0;
            }
            else {
              if ((bVar13 == 7) || (bVar13 == 8)) goto LAB_140005aa4;
              if (bVar13 != 9) {
                if (bVar13 == 10) {
                  iVar17 = -0x3fffff63;
                  goto LAB_140005ac5;
                }
                if (bVar13 != 0xb) goto LAB_140005ac0;
              }
LAB_140005a67:
              iVar17 = -0x3fffff4b;
            }
            goto LAB_140005ac5;
          }
        }
LAB_140005ac0:
        iVar17 = -0x3ffffe7b;
      }
      else {
        if (bVar13 == 0xf) goto LAB_140005ac0;
        if (bVar13 != 0x11) {
          if (bVar13 == 0x12) {
            if (uVar11 < *param_7) {
              *param_7 = uVar11;
              iVar17 = 0;
            }
            else {
              iVar17 = -0x7ffffffb;
            }
            goto LAB_140005ac5;
          }
          if ((((bVar13 == 0x13) || (bVar13 == 0x14)) || (bVar13 == 0x16)) ||
             ((bVar13 != 0x20 && (bVar13 != 0x21)))) goto LAB_140005ac0;
        }
LAB_140005aa4:
        iVar17 = -0x3ffffff2;
      }
LAB_140005ac5:
      if (((*(char *)(param_2 + 0x23) < '\0') && (bVar8)) && (local_108 == 5)) {
        iVar17 = -0x3ffffff0;
      }
      goto LAB_140005b0d;
    }
    *param_7 = uVar11;
  }
  iVar17 = 0;
LAB_140005b0d:
  if (local_e8 != 0) {
    if (bVar9) {
      MmUnlockPages(local_e8);
    }
    IoFreeMdl(local_e8);
    *(undefined8 *)(local_100 + 8) = 0;
  }
  return iVar17;
}



===== ForwardRequestToLocalIoTarget @ 140005b80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 ForwardRequestToLocalIoTarget(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  (**(code **)(WdfFunctions_01015 + 0x7d8))(WdfDriverGlobals,param_1);
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_FILTER_DEVICE_EXTENSION_TYPE_INFO_140016018);
  (**(code **)(WdfFunctions_01015 + 0x820))
            (WdfDriverGlobals,param_1,RequestDummyCompletionRoutine,uVar3);
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x150))(WdfDriverGlobals,param_2);
  cVar1 = (**(code **)(WdfFunctions_01015 + 0x7e8))(WdfDriverGlobals,param_1,uVar3,0);
  if (cVar1 == '\0') {
    uVar2 = (**(code **)(WdfFunctions_01015 + 0x7f0))(WdfDriverGlobals,param_1);
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_1,uVar2);
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



===== IoWaitQueueEvtDefault @ 140005ca0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void IoWaitQueueEvtDefault(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  undefined4 uVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_REQUEST_CONTEXT_TYPE_INFO_140016108);
  uVar4 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
  if (*(char *)(lVar3 + 8) == '\x01') {
    KeSetEvent(lVar3 + 0x10,0,0);
  }
  else {
    (**(code **)(WdfFunctions_01015 + 0x7d8))(WdfDriverGlobals,param_2);
    uVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,uVar4,PTR__WDF_FILTER_DEVICE_EXTENSION_TYPE_INFO_140016018);
    (**(code **)(WdfFunctions_01015 + 0x820))
              (WdfDriverGlobals,param_2,RequestDummyCompletionRoutine,uVar5);
    uVar4 = (**(code **)(WdfFunctions_01015 + 0x150))(WdfDriverGlobals,uVar4);
    cVar1 = (**(code **)(WdfFunctions_01015 + 0x7e8))(WdfDriverGlobals,param_2,uVar4,0);
    if (cVar1 == '\0') {
      uVar2 = (**(code **)(WdfFunctions_01015 + 0x7f0))(WdfDriverGlobals,param_2);
      (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,uVar2);
    }
  }
  return;
}



===== RequestDummyCompletionRoutine @ 140005e30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void RequestDummyCompletionRoutine(undefined8 param_1)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x7f0))(WdfDriverGlobals,param_1);
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_1,uVar1);
  return;
}



===== IoWaitQueueEvtIoDeviceControl @ 140005e90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void IoWaitQueueEvtIoDeviceControl(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  undefined4 uVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_REQUEST_CONTEXT_TYPE_INFO_140016108);
  uVar4 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
  if (*(char *)(lVar3 + 8) == '\x01') {
    KeSetEvent(lVar3 + 0x10,0,0);
    return;
  }
  (**(code **)(WdfFunctions_01015 + 0x7d8))(WdfDriverGlobals,param_2);
  uVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar4,PTR__WDF_FILTER_DEVICE_EXTENSION_TYPE_INFO_140016018);
  (**(code **)(WdfFunctions_01015 + 0x820))
            (WdfDriverGlobals,param_2,RequestDummyCompletionRoutine,uVar5);
  uVar4 = (**(code **)(WdfFunctions_01015 + 0x150))(WdfDriverGlobals,uVar4);
  cVar1 = (**(code **)(WdfFunctions_01015 + 0x7e8))(WdfDriverGlobals,param_2,uVar4,0);
  if (cVar1 == '\0') {
    uVar2 = (**(code **)(WdfFunctions_01015 + 0x7f0))(WdfDriverGlobals,param_2);
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,uVar2);
  }
  return;
}



===== FilterDeviceWdmIoctlCompletionRoutine @ 140006030 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
FilterDeviceWdmIoctlCompletionRoutine(undefined8 param_1,longlong param_2,undefined8 param_3)

{
  longlong lVar1;
  longlong *plVar2;
  int iVar3;
  char *pcVar4;
  char cVar5;
  uint uVar6;
  undefined8 *puVar7;
  longlong lVar8;
  byte bVar9;
  uint uVar10;
  ulonglong uVar11;
  byte bVar12;
  uint uVar13;
  char *pcVar14;
  uint uVar15;
  byte bVar16;
  byte *pbVar17;
  bool bVar18;
  bool bVar19;
  ulonglong local_res20;
  uint local_58;
  ulonglong local_50;
  uint *local_40;
  
  local_50 = 0;
  pbVar17 = (byte *)0x0;
  bVar12 = 0;
  uVar15 = 0;
  bVar16 = 0;
  bVar19 = false;
  puVar7 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_3,PTR__WDF_FILTER_DEVICE_EXTENSION_TYPE_INFO_140016018)
  ;
  pcVar4 = *(char **)(param_2 + 0xb8);
  if (DisableScsiSenseFixup != '\0') goto switchD_1400063a0_caseD_9;
  if (*pcVar4 == '\x0f') {
    lVar8 = *(longlong *)(pcVar4 + 8);
    bVar19 = false;
    if (*(char *)(lVar8 + 2) == '\0') {
      bVar12 = *(byte *)(lVar8 + 3) & 0x3f;
      if ((bVar12 == 4) || (bVar12 == 0xe)) {
        bVar19 = true;
      }
      else if (-1 < (char)*(byte *)(lVar8 + 3)) goto switchD_1400063a0_caseD_9;
      pbVar17 = *(byte **)(lVar8 + 0x20);
      pcVar14 = (char *)(lVar8 + 0x48);
      bVar12 = *(byte *)(lVar8 + 0xb);
      uVar15 = (uint)*(byte *)(lVar8 + 10);
    }
    else {
      if ((*(char *)(lVar8 + 2) != '(') || (*(int *)(lVar8 + 0x14) != 0))
      goto switchD_1400063a0_caseD_9;
      bVar9 = *(byte *)(lVar8 + 3) & 0x3f;
      if ((bVar9 == 4) || (bVar9 == 0xe)) {
        bVar19 = true;
      }
      else if (-1 < (char)*(byte *)(lVar8 + 3)) goto switchD_1400063a0_caseD_9;
      pcVar14 = (char *)0x0;
      local_58 = 0;
      if (*(uint *)(lVar8 + 0x38) != 0) {
        local_40 = (uint *)(lVar8 + 0x78);
        do {
          uVar6 = *local_40;
          uVar11 = (ulonglong)uVar6;
          if ((0x7f < uVar6) && (uVar13 = *(uint *)(lVar8 + 0x10), uVar6 < uVar13)) {
            iVar3 = *(int *)(lVar8 + uVar11);
            lVar1 = lVar8 + uVar11;
            if (iVar3 == 0x40) {
              uVar11 = uVar11 + 0x28;
            }
            else {
              if (iVar3 != 0x41) {
                if ((iVar3 != 0x42) || ((ulonglong)uVar13 < uVar11 + 0x28)) goto LAB_14000627f;
                uVar15 = *(uint *)(lVar1 + 0xc);
                if (uVar15 != 0) {
                  pcVar14 = (char *)(lVar1 + 0x20);
                }
                pbVar17 = *(byte **)(lVar1 + 0x18);
                bVar12 = *(byte *)(lVar1 + 9);
                break;
              }
              uVar11 = uVar11 + 0x38;
            }
            if (uVar11 <= uVar13) {
              bVar16 = *(byte *)(lVar1 + 10);
              if (bVar16 != 0) {
                pcVar14 = (char *)(lVar1 + 0x18);
              }
              pbVar17 = *(byte **)(lVar1 + 0x10);
              bVar12 = *(byte *)(lVar1 + 9);
              goto LAB_1400061be;
            }
          }
LAB_14000627f:
          local_58 = local_58 + 1;
          local_40 = local_40 + 1;
        } while (local_58 < *(uint *)(lVar8 + 0x38));
      }
      if (uVar15 == 0) {
LAB_1400061be:
        uVar15 = (uint)bVar16;
      }
    }
  }
  else {
    if ((*pcVar4 != '\x0e') || ((*(int *)(pcVar4 + 0x18) - 0x4d004U & 0xffffffef) != 0))
    goto switchD_1400063a0_caseD_9;
    cVar5 = IoIs32bitProcess(param_2);
    uVar15 = *(uint *)(pcVar4 + 8);
    if (cVar5 == '\0') {
      if (uVar15 < 0x38) goto switchD_1400063a0_caseD_9;
      lVar8 = *(longlong *)(param_2 + 0x18);
      bVar12 = *(byte *)(lVar8 + 7);
      uVar6 = *(uint *)(lVar8 + 0x20);
      if (uVar15 < uVar6 + bVar12) goto switchD_1400063a0_caseD_9;
      pcVar14 = (char *)(lVar8 + 0x24);
    }
    else {
      if (uVar15 < 0x2c) goto switchD_1400063a0_caseD_9;
      lVar8 = *(longlong *)(param_2 + 0x18);
      bVar12 = *(byte *)(lVar8 + 7);
      uVar6 = *(uint *)(lVar8 + 0x18);
      if (uVar15 < uVar6 + bVar12) goto switchD_1400063a0_caseD_9;
      pcVar14 = (char *)(lVar8 + 0x1c);
    }
    uVar15 = (uint)*(byte *)(lVar8 + 6);
    pbVar17 = (byte *)(lVar8 + (ulonglong)uVar6);
  }
  if ((pbVar17 == (byte *)0x0) || (pcVar14 == (char *)0x0)) goto switchD_1400063a0_caseD_9;
  bVar9 = 0;
  bVar16 = 0;
  if (bVar12 == 0) goto switchD_1400063a0_caseD_9;
  bVar18 = false;
  if ((byte)((*pbVar17 & 0x7f) + 0x8e) < 2) {
    if (pbVar17 + 8 <= pbVar17 + bVar12) {
      bVar16 = pbVar17[2];
      bVar9 = pbVar17[1] & 0xf;
      goto LAB_140006353;
    }
  }
  else if (pbVar17 + 8 <= pbVar17 + bVar12) {
    bVar9 = pbVar17[2] & 0xf;
    uVar6 = (uint)bVar12;
    if (pbVar17[7] + 8 <= (uint)bVar12) {
      uVar6 = pbVar17[7] + 8;
    }
    if (pbVar17 + 0xd <= pbVar17 + uVar6) {
      bVar16 = pbVar17[0xc];
    }
LAB_140006353:
    bVar18 = true;
  }
  if ((!bVar18) || (((!bVar19 && (bVar9 == 0)) && (bVar16 == 0)))) goto switchD_1400063a0_caseD_9;
  cVar5 = *pcVar14;
  switch(cVar5) {
  case '\b':
  case '\n':
    if (uVar15 == 6) {
      local_50 = (ulonglong)((uint6)CONCAT21(CONCAT11(pcVar14[1],pcVar14[2]),pcVar14[3]) & 0x1fffff)
      ;
      local_res20 = (ulonglong)(byte)pcVar14[4];
      bVar18 = cVar5 == '\n';
      bVar19 = cVar5 == '\b';
    }
    else {
LAB_1400063f3:
      local_res20 = 0;
      bVar19 = false;
      bVar18 = false;
    }
    goto LAB_14000655b;
  default:
    goto switchD_1400063a0_caseD_9;
  case '(':
  case '*':
    if (uVar15 != 10) goto LAB_1400063f3;
    local_res20 = (ulonglong)(byte)pcVar14[8];
    bVar18 = cVar5 == '*';
    local_50 = (ulonglong)CONCAT31(CONCAT21(CONCAT11(pcVar14[2],pcVar14[3]),pcVar14[4]),pcVar14[5]);
    bVar19 = cVar5 == '(';
    uVar11 = (ulonglong)(byte)pcVar14[7];
    break;
  case -0x78:
  case -0x76:
    if (uVar15 != 0x10) goto switchD_1400063a0_caseD_9;
    local_50 = CONCAT71(CONCAT61(CONCAT51(CONCAT41(CONCAT31(CONCAT21(CONCAT11(pcVar14[2],pcVar14[3])
                                                                     ,pcVar14[4]),pcVar14[5]),
                                                   pcVar14[6]),pcVar14[7]),pcVar14[8]),pcVar14[9]);
    bVar18 = cVar5 == -0x76;
    bVar19 = cVar5 == -0x78;
    uVar11 = (ulonglong)CONCAT21(CONCAT11(pcVar14[10],pcVar14[0xb]),pcVar14[0xc]);
    local_res20 = (ulonglong)(byte)pcVar14[0xd];
    break;
  case -0x58:
  case -0x56:
    if (uVar15 != 0xc) goto LAB_1400063f3;
    bVar18 = cVar5 == -0x56;
    local_50 = (ulonglong)CONCAT31(CONCAT21(CONCAT11(pcVar14[2],pcVar14[3]),pcVar14[4]),pcVar14[5]);
    bVar19 = cVar5 == -0x58;
    uVar11 = (ulonglong)CONCAT21(CONCAT11(pcVar14[6],pcVar14[7]),pcVar14[8]);
    local_res20 = (ulonglong)(byte)pcVar14[9];
  }
  local_res20 = uVar11 * 0x100 + local_res20;
LAB_14000655b:
  if ((!bVar19) && (!bVar18)) goto switchD_1400063a0_caseD_9;
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*puVar7);
  iVar3 = *(int *)(puVar7 + 1);
  uVar15 = *(uint *)(puVar7 + 2);
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*puVar7);
  if (iVar3 != 1) {
    if ((((uVar15 & 2) == 0) || (puVar7[0x3d] == 0)) || (*(int *)((longlong)puVar7 + 500) == 0))
    goto switchD_1400063a0_caseD_9;
    (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,puVar7[0x40]);
    if (bVar19) {
      if ((*(uint *)(puVar7 + 0x26) & 1) == 0) goto LAB_140006623;
LAB_140006659:
      bVar18 = true;
    }
    else {
      if ((*(uint *)(puVar7 + 0x26) & 2) != 0) goto LAB_140006659;
LAB_140006623:
      bVar18 = false;
    }
    uVar15 = *(uint *)(puVar7 + 0x3e);
    uVar6 = 0;
    uVar13 = uVar15;
    while (uVar10 = uVar6, uVar6 + 1 < uVar13) {
      uVar10 = uVar13 + uVar6 >> 1;
      uVar11 = *(ulonglong *)(puVar7[0x3d] + (ulonglong)uVar10 * 0x18);
      if (uVar11 < local_50) {
        uVar6 = uVar10;
      }
      else {
        if (uVar11 <= local_50) break;
        uVar13 = uVar10;
      }
    }
    if ((uVar10 < uVar15) &&
       (plVar2 = (longlong *)(puVar7[0x3d] + (ulonglong)uVar10 * 0x18),
       local_50 < (ulonglong)(*(longlong *)(puVar7[0x3d] + 8 + (ulonglong)uVar10 * 0x18) + *plVar2))
       ) {
      if (!bVar18) {
        if (bVar19) {
          cVar5 = (char)plVar2[2];
        }
        else {
          cVar5 = *(char *)((longlong)plVar2 + 0x11);
        }
        if (cVar5 == '\0') {
          bVar18 = false;
          goto LAB_1400066ac;
        }
      }
      bVar18 = true;
    }
LAB_1400066ac:
    if ((uVar10 + 1 < uVar15) &&
       (lVar8 = puVar7[0x3d],
       *(ulonglong *)(lVar8 + (ulonglong)(uVar10 + 1) * 0x18) < local_res20 + local_50)) {
      if (!bVar18) {
        if (bVar19) {
          cVar5 = *(char *)(lVar8 + 0x10 + (ulonglong)uVar10 * 0x18);
        }
        else {
          cVar5 = *(char *)(lVar8 + 0x11 + (ulonglong)uVar10 * 0x18);
        }
        if (cVar5 == '\0') {
          (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,puVar7[0x40]);
          goto switchD_1400063a0_caseD_9;
        }
      }
      (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,puVar7[0x40]);
    }
    else {
      (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,puVar7[0x40]);
      if (!bVar18) goto switchD_1400063a0_caseD_9;
    }
  }
  bVar12 = *pbVar17;
  *pbVar17 = bVar12 & 0xf0 | 0x70;
  if ((byte)((bVar12 & 0x7f) + 0x8e) < 2) {
    pbVar17[1] = pbVar17[1] & 0xf7 | 7;
    pbVar17[2] = 0x20;
    pbVar17[3] = 2;
  }
  else {
    pbVar17[2] = pbVar17[2] & 0xf7 | 7;
    pbVar17[0xc] = 0x20;
    pbVar17[0xd] = 2;
  }
  if (*pcVar4 == '\x0f') {
    *(byte *)(*(longlong *)(pcVar4 + 8) + 3) = *(byte *)(*(longlong *)(pcVar4 + 8) + 3) | 0x80;
  }
switchD_1400063a0_caseD_9:
  if (*(char *)(param_2 + 0x41) != '\0') {
    pbVar17 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar17 = *pbVar17 | 1;
  }
  return 0;
}



===== RequestEvtCleanup @ 1400067d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void RequestEvtCleanup(undefined8 param_1)

{
  int iVar1;
  longlong lVar2;
  
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_REQUEST_CONTEXT_TYPE_INFO_140016108);
  if (*(char *)(lVar2 + 8) == '\x01') {
    iVar1 = KeReadStateEvent(lVar2 + 0x10);
    if (iVar1 == 0) {
      KeSetEvent(lVar2 + 0x10,0,0);
    }
  }
  return;
}



===== RtlStringCopyWorkerW @ 140006844 =====

uint RtlStringCopyWorkerW(short *param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  short sVar1;
  short *psVar2;
  longlong lVar3;
  longlong lVar4;
  
  lVar4 = param_4 - (longlong)param_1;
  lVar3 = 0x209;
  do {
    if ((lVar3 == -0x7ffffdf5) || (sVar1 = *(short *)(lVar4 + (longlong)param_1), sVar1 == 0))
    break;
    *param_1 = sVar1;
    param_1 = param_1 + 1;
    lVar3 = lVar3 + -1;
  } while (lVar3 != 0);
  psVar2 = param_1 + -1;
  if (lVar3 != 0) {
    psVar2 = param_1;
  }
  *psVar2 = 0;
  return ~-(uint)(lVar3 != 0) & 0x80000005;
}



===== IoctlRedirectionCompletionRoutine @ 1400068a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void IoctlRedirectionCompletionRoutine(undefined8 param_1,undefined8 param_2,longlong param_3)

{
  undefined4 uVar1;
  undefined8 uVar2;
  int iVar3;
  undefined8 *puVar4;
  longlong lVar5;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined8 local_1c;
  undefined4 local_14;
  
  puVar4 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,
                      PTR__WDF_IOCTL_REDIRECT_REQUEST_CONTEXT_TYPE_INFO_1400160e0);
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,puVar4[1],PTR__WDF_CHILD_DEVICE_EXTENSION_TYPE_INFO_1400160b8)
  ;
  local_1c = 0;
  local_14 = 0;
  local_24 = 0;
  local_20 = 0;
  uVar1 = *(undefined4 *)(param_3 + 8);
  uVar2 = *(undefined8 *)(param_3 + 0x10);
  local_28 = 0x18;
  (**(code **)(WdfFunctions_01015 + 0x7c8))(WdfDriverGlobals,param_1,&local_28);
  (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,*puVar4,uVar1,uVar2);
  if (*(char *)(puVar4 + 2) == '\0') {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,param_1);
  }
  else {
    iVar3 = (**(code **)(WdfFunctions_01015 + 0x78))
                      (WdfDriverGlobals,*(undefined8 *)(lVar5 + 0x38),param_1);
    if (((iVar3 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x37,
               &WPP_6b540f47682e3482637f60efce621d01_Traceguids,iVar3);
    }
    KeReleaseSemaphore(lVar5 + 0x40,0,1);
  }
  return;
}



===== entry @ 140006a20 =====

void entry(_WDF_BIND_INFO *param_1,undefined8 param_2)

{
  __security_init_cookie();
  FxDriverEntryWorker(param_1,param_2);
  return;
}



===== FxDriverEntryWorker @ 140006a54 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FxDriverEntryWorker(_WDF_BIND_INFO *param_1,undefined8 param_2)

{
  int iVar1;
  _WDF_BIND_INFO *p_Var2;
  
  if (param_1 == (_WDF_BIND_INFO *)0x0) {
    iVar1 = DriverEntry(0,param_2);
  }
  else {
    _DAT_140017d50 = 0x2080000;
    _DAT_140017d58 = &DAT_140017b40;
    RtlCopyUnicodeString(&DAT_140017d50);
    p_Var2 = param_1;
    iVar1 = WdfVersionBind(param_1,&DAT_140017d50,&WdfBindInfo,&WdfDriverGlobals);
    if (-1 < iVar1) {
      iVar1 = FxStubBindClasses(p_Var2);
      if ((-1 < iVar1) && (iVar1 = FxStubInitTypes(), -1 < iVar1)) {
        iVar1 = DriverEntry(param_1,param_2);
        if (-1 < iVar1) {
          if (*(char *)(WdfDriverGlobals + 0x30) != '\0') {
            if (*(longlong *)(param_1 + 0x68) != 0) {
              DAT_140017d48 = *(longlong *)(param_1 + 0x68);
            }
            *(code **)(param_1 + 0x68) = FxStubDriverUnload;
          }
          return 0;
        }
        DbgPrintEx(0x4d,0,"DriverEntry failed 0x%x for driver %wZ\n",iVar1,&DAT_140017d50);
        FxStubDriverEntryFailure();
      }
      FxStubDriverUnloadCommon();
    }
  }
  return iVar1;
}



===== FxStubInitTypes @ 140006b78 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x000140006b95) */
/* long __cdecl FxStubInitTypes(void) */

long __cdecl FxStubInitTypes(void)

{
  void *pvVar1;
  void **ppvVar2;
  
  ppvVar2 = &__KMDF_TYPE_INIT_END;
  while( true ) {
    for (; (ppvVar2 + 1 < (void **)((longlong)&__KMDF_TYPE_INIT_END + 1) &&
           (*ppvVar2 == (void *)0x0)); ppvVar2 = ppvVar2 + 1) {
    }
    if ((void **)0x14001623f < ppvVar2) break;
    if (((&__KMDF_TYPE_INIT_END < ppvVar2 + 5) || (*(uint *)ppvVar2 != 0x28)) ||
       (ppvVar2 == (void **)0x0)) {
      DbgPrintEx(0x4d,0,"FxGetNextObjectContextTypeInfo failed\n");
      return -0x3fffff85;
    }
    if (ppvVar2[4] != (code *)0x0) {
      pvVar1 = (void *)(*ppvVar2[4])();
      ppvVar2[3] = pvVar1;
    }
    ppvVar2 = (void **)((ulonglong)*(uint *)ppvVar2 + (longlong)ppvVar2);
  }
  return 0;
}



===== FxStubBindClasses @ 140006c40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x000140006c65) */
/* long __cdecl FxStubBindClasses(struct _WDF_BIND_INFO * __ptr64) */

long __cdecl FxStubBindClasses(_WDF_BIND_INFO *param_1)

{
  int iVar1;
  uint *puVar2;
  void **ppvVar3;
  
  iVar1 = 0;
  ppvVar3 = &__KMDF_CLASS_BIND_END;
  while( true ) {
    puVar2 = (uint *)FxGetNextClassBindInfo((longlong *)ppvVar3,(longlong *)&__KMDF_CLASS_BIND_END);
    if (puVar2 == (uint *)0x0) {
      DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
      return -0x3fffff85;
    }
    if ((uint *)0x14001621f < puVar2) break;
    PTR___KMDF_CLASS_BIND_START_140016228 = (undefined *)puVar2;
    if (*(code **)(puVar2 + 0xe) == (code *)0x0) {
      iVar1 = WdfVersionBindClass(&WdfBindInfo,WdfDriverGlobals,puVar2);
      if (iVar1 < 0) {
        DbgPrintEx(0x4d,0,
                   "FxStubBindClasses: VersionBindClass WDF_CLASS_BIND_INFO 0x%p, class %S, returned status 0x%x\n"
                   ,puVar2,*(undefined8 *)(puVar2 + 2),iVar1);
        return iVar1;
      }
    }
    else {
      iVar1 = (**(code **)(puVar2 + 0xe))
                        (WdfVersionBindClass_exref,&WdfBindInfo,WdfDriverGlobals,puVar2);
      if (iVar1 < 0) {
        DbgPrintEx(0x4d,0,
                   "FxStubBindClasses: ClientBindClass %p, WDF_CLASS_BIND_INFO 0x%p, class %S, returned status 0x%x\n"
                   ,*(undefined8 *)(puVar2 + 0xe),puVar2,*(undefined8 *)(puVar2 + 2),iVar1);
        return iVar1;
      }
    }
    ppvVar3 = (void **)((longlong)puVar2 + (ulonglong)*puVar2);
  }
  return iVar1;
}



===== FxGetNextClassBindInfo @ 140006da0 =====

longlong * FxGetNextClassBindInfo(longlong *param_1,longlong *param_2)

{
  longlong *plVar1;
  
  plVar1 = param_1 + 1;
  for (; (plVar1 <= param_2 && (*param_1 == 0)); param_1 = param_1 + 1) {
    plVar1 = param_1 + 2;
  }
  if (param_2 <= param_1) {
    return param_2;
  }
  if (param_2 < param_1 + 10) {
    return (longlong *)0x0;
  }
  plVar1 = (longlong *)0x0;
  if ((int)*param_1 == 0x50) {
    plVar1 = param_1;
  }
  return plVar1;
}



===== FxStubDriverUnload @ 140006df0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FxStubDriverUnload(void)

{
  if ((DAT_140017d48 != (code *)0x0) && (DAT_140017d48 != FxStubDriverUnload)) {
    (*DAT_140017d48)();
  }
  FxStubDriverUnloadCommon();
  return;
}



===== FxStubDriverUnloadCommon @ 140006e24 =====

/* void __cdecl FxStubDriverUnloadCommon(void) */

void __cdecl FxStubDriverUnloadCommon(void)

{
  _WDF_BIND_INFO *in_RCX;
  
  FxStubUnbindClasses(in_RCX);
  WdfVersionUnbind(&DAT_140017d50,&WdfBindInfo,WdfDriverGlobals);
  return;
}



===== ChildDeviceEvtIoDeviceControl @ 140006e60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ChildDeviceEvtIoDeviceControl
               (undefined8 param_1,ulonglong param_2,undefined8 param_3,undefined8 param_4,
               int param_5)

{
  longlong lVar1;
  undefined8 *puVar2;
  longlong lVar3;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
  puVar2 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,lVar1,PTR__WDF_CHILD_DEVICE_EXTENSION_TYPE_INFO_1400160b8);
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,*puVar2,PTR__WDF_FILTER_DEVICE_EXTENSION_TYPE_INFO_140016018);
  if (param_5 == 0x2d1400) {
    ForwardRequestToParentDeviceIoQueue(param_2,*(undefined8 *)(lVar3 + 0x188));
    return;
  }
  if (param_5 != 0x2d1404) {
    if (param_5 == 0x2d140c) {
      IoctlDeviceSendSiloCommand(lVar1,param_2);
      return;
    }
    if (param_5 == 0x2d1410) {
      IoctlDeviceEnumeratePdos(lVar1,1,param_2);
      return;
    }
    if (param_5 != 0x2d1414) {
      if (param_5 == 0x2d1418) {
        IoctlDeviceQueryProperties(lVar1,param_2);
        return;
      }
      if (param_5 == 0x2d141c) {
        IoctlDeviceGetQueueState(lVar1,param_2);
        return;
      }
      if (param_5 == 0x2d1424) {
        IoctlDeviceGetAuthzState(lVar1,param_2);
        return;
      }
      if (param_5 != 0x2dd420) {
        (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,0xc00000bb);
        return;
      }
      lVar3 = (**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals);
      if ((*(uint *)(lVar3 + 0x10) & 0x400000) == 0) {
        return;
      }
      IoctlDeviceSetQueueState(lVar1,param_2);
      return;
    }
  }
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals,param_2);
  if ((*(uint *)(lVar3 + 0x10) & 0x400000) != 0) {
    IoctlDeviceSetAuthzState(lVar1,param_2);
  }
  return;
}



===== RtlStringLengthWorkerA @ 140006ffc =====

uint RtlStringLengthWorkerA(char *param_1,undefined8 param_2,longlong *param_3)

{
  uint uVar1;
  longlong lVar2;
  
  lVar2 = 0x80;
  do {
    if (*param_1 == '\0') break;
    param_1 = param_1 + 1;
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  uVar1 = ~-(uint)(lVar2 != 0) & 0xc000000d;
  if (param_3 == (longlong *)0x0) {
    return uVar1;
  }
  if (lVar2 == 0) {
    *param_3 = 0;
    return 0xc000000d;
  }
  *param_3 = 0x80 - lVar2;
  return uVar1;
}



===== LogInit @ 140007044 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int LogInit(void)

{
  int iVar1;
  
  memset(&g_Logger,0,0x1820);
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x9d8))(WdfDriverGlobals,0,&DAT_140016308);
  if (iVar1 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (WPP_GLOBAL_Control[0x29] != '\0')) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
               &WPP_0159312f707f3ae441c80b26dad3f39c_Traceguids,iVar1);
    }
  }
  else {
    _g_Logger = 1;
  }
  return iVar1;
}



===== McGenControlCallbackV2 @ 1400070e0 =====

void McGenControlCallbackV2
               (undefined8 param_1,int param_2,undefined1 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6,longlong param_7)

{
  uint *puVar1;
  ulonglong uVar2;
  bool bVar3;
  uint uVar4;
  uint uVar5;
  ulonglong uVar6;
  
  if (param_7 != 0) {
    if (param_2 == 0) {
      *(undefined4 *)(param_7 + 0x24) = 0;
      *(undefined1 *)(param_7 + 0x28) = 0;
      *(undefined8 *)(param_7 + 0x10) = 0;
      *(undefined8 *)(param_7 + 0x18) = 0;
      if (*(ushort *)(param_7 + 0x2a) != 0) {
        memset(*(void **)(param_7 + 0x30),0,
               (longlong)((int)(*(ushort *)(param_7 + 0x2a) - 1) / 0x20 + 1) << 2);
      }
    }
    else if (param_2 == 1) {
      *(undefined1 *)(param_7 + 0x28) = param_3;
      uVar6 = 0;
      *(undefined8 *)(param_7 + 0x18) = param_5;
      *(undefined8 *)(param_7 + 0x10) = param_4;
      *(undefined4 *)(param_7 + 0x24) = 1;
      if (*(short *)(param_7 + 0x2a) != 0) {
        do {
          uVar2 = *(ulonglong *)(*(longlong *)(param_7 + 0x38) + uVar6 * 8);
          if (((*(byte *)(param_7 + 0x28) < *(byte *)(uVar6 + *(longlong *)(param_7 + 0x40))) &&
              (*(byte *)(param_7 + 0x28) != 0)) ||
             ((uVar2 != 0 &&
              (((*(ulonglong *)(param_7 + 0x10) & uVar2) == 0 ||
               ((*(ulonglong *)(param_7 + 0x18) & uVar2) != *(ulonglong *)(param_7 + 0x18))))))) {
            bVar3 = false;
          }
          else {
            bVar3 = true;
          }
          uVar4 = 1 << ((byte)uVar6 & 0x1f);
          puVar1 = (uint *)(*(longlong *)(param_7 + 0x30) + (uVar6 >> 5) * 4);
          uVar5 = *puVar1;
          if (bVar3) {
            uVar4 = uVar4 | uVar5;
          }
          else {
            uVar4 = ~uVar4 & uVar5;
          }
          *puVar1 = uVar4;
          uVar5 = (int)uVar6 + 1;
          uVar6 = (ulonglong)uVar5;
        } while (uVar5 < *(ushort *)(param_7 + 0x2a));
      }
    }
  }
  return;
}



===== McGenEventRegister_EtwRegister @ 1400071f0 =====

void McGenEventRegister_EtwRegister(void)

{
  if (EhStorClassEventProvider_Context == 0) {
    EtwRegister(&EhStorClassEventProvider,McGenControlCallbackV2,&EhStorClassEventProvider_Context,
                &EhStorClassEventProvider_Context);
  }
  return;
}



===== GetTransferResultsTCGCommand @ 140007230 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint GetTransferResultsTCGCommand
               (undefined8 param_1,longlong param_2,uint *param_3,ulonglong *param_4)

{
  byte bVar1;
  short sVar2;
  uint uVar3;
  uint uVar4;
  longlong lVar5;
  ulonglong uVar6;
  void *_Src;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  uint local_res20 [2];
  
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FILTER_DEVICE_EXTENSION_TYPE_INFO_140016018);
  if (*param_4 < 0x34) {
    return 0xc000000d;
  }
  bVar1 = *(byte *)(lVar5 + 0x139);
  sVar2 = *(short *)(lVar5 + 0x138);
  local_res20[0] = (uint)*param_4;
  uVar6 = Feature_3414581563__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar6 == 0) {
    uVar7 = local_res20[0] + 0x1ff & 0xfffffe00;
    local_res20[0] = 0x10000;
    if (uVar7 < 0x10000) {
      local_res20[0] = uVar7;
    }
  }
  else {
    uVar7 = local_res20[0] + 0x1ff & 0xfffffe00;
    bVar9 = local_res20[0] <= uVar7;
    local_res20[0] = 0x10000;
    if ((bVar9) && (local_res20[0] = 0x10000, uVar7 < 0x10000)) {
      local_res20[0] = uVar7;
    }
  }
  _Src = (void *)ExAllocatePool2(0x40,local_res20[0],0x47536353);
  uVar6 = Feature_3414581563__private_IsEnabledDeviceUsageNoInline();
  uVar7 = 0;
  if ((int)uVar6 != 0) {
    uVar7 = local_res20[0];
  }
  if (_Src == (void *)0x0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
               &WPP_6dffcf61b7ff359f9fb81cd3fb43e1c9_Traceguids,local_res20[0]);
    }
    return 0xc000009a;
  }
  uVar3 = IssueSecurityProtocolInTCG
                    (*(undefined8 *)(lVar5 + 0x198),param_2,1,(ushort)bVar1 | sVar2 << 8,
                     (longlong)_Src,local_res20,*(char *)(lVar5 + 0x180),
                     (*(uint *)(lVar5 + 0x130) & 0x40) << 5);
  if ((int)uVar3 < 0) {
joined_r0x000140007604:
    if ((Microsoft_Windows_EnhancedStorage_ClassDriverEnableBits & 2) != 0) {
      McTemplateK0quuujzdzxzxzxzx_EtwWriteTransfer();
    }
    goto LAB_140007816;
  }
  if (local_res20[0] < 0x14) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
               &WPP_6dffcf61b7ff359f9fb81cd3fb43e1c9_Traceguids,local_res20[0]);
    }
  }
  else {
    uVar6 = Feature_3414581563__private_IsEnabledDeviceUsageNoInline();
    uVar8 = *(uint *)((longlong)_Src + 0x10);
    uVar8 = (uVar8 << 0x10 | uVar8 & 0xff00) << 8 | uVar8 >> 8 & 0xff00 |
            (uint)*(byte *)((longlong)_Src + 0x13);
    if ((int)uVar6 == 0) {
      uVar7 = uVar8 + 0x14;
      uVar8 = uVar8 + 0x34;
      local_res20[0] = uVar8;
      if ((ulonglong)uVar8 <= *param_4) {
        uVar4 = uVar8 >> 0x18 | (uVar8 & 0xff0000) >> 8 | (uVar8 & 0xff00) << 8 | uVar8 * 0x1000000;
        *param_3 = uVar4;
        param_3[2] = uVar4;
        *(undefined1 *)((longlong)param_3 + 7) = 0;
        param_3[7] = uVar7 >> 0x18 | (uVar7 & 0xff0000) >> 8 | (uVar7 & 0xff00) << 8 |
                     uVar7 * 0x1000000;
        memmove(param_3 + 8,_Src,(ulonglong)uVar7);
        *param_4 = (ulonglong)uVar8;
        goto LAB_140007816;
      }
LAB_140007811:
      uVar3 = 0xc0000023;
      goto LAB_140007816;
    }
    uVar4 = uVar8 + 0x14;
    if (uVar8 <= uVar4) {
      uVar8 = uVar8 + 0x34;
      local_res20[0] = 0xffffffff;
      if (uVar8 >= 0x20) {
        local_res20[0] = uVar8;
      }
      uVar3 = -(uint)(uVar8 < 0x20) & 0xc0000095;
      if (0x1f < uVar8) {
        uVar6 = (ulonglong)local_res20[0];
        if (uVar6 <= *param_4) {
          if (uVar4 <= uVar7) {
            uVar7 = local_res20[0] >> 0x18 | (local_res20[0] & 0xff0000) >> 8 |
                    (local_res20[0] & 0xff00) << 8 | local_res20[0] << 0x18;
            *param_3 = uVar7;
            param_3[2] = uVar7;
            *(undefined1 *)((longlong)param_3 + 7) = 0;
            param_3[7] = (uVar4 & 0xff0000 | uVar4 >> 0x10) >> 8 |
                         (uVar4 * 0x10000 | uVar4 & 0xff00) << 8;
            memmove(param_3 + 8,_Src,(ulonglong)uVar4);
            *param_4 = uVar6;
            goto LAB_140007816;
          }
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
                      &WPP_6dffcf61b7ff359f9fb81cd3fb43e1c9_Traceguids,uVar4,(char)uVar7);
          }
          uVar3 = 0xc0000186;
          goto joined_r0x000140007604;
        }
        goto LAB_140007811;
      }
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      uVar7 = *(uint *)((longlong)_Src + 0x10);
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
               &WPP_6dffcf61b7ff359f9fb81cd3fb43e1c9_Traceguids,
               (uVar7 << 0x10 | uVar7 & 0xff00) << 8 | uVar7 >> 8 & 0xff00 |
               (uint)*(byte *)((longlong)_Src + 0x13));
    }
  }
  if ((Microsoft_Windows_EnhancedStorage_ClassDriverEnableBits & 2) != 0) {
    McTemplateK0quuujzdzxzxzxzx_EtwWriteTransfer();
  }
  uVar3 = 0xc0000186;
LAB_140007816:
  ExFreePoolWithTag(_Src,0);
  return uVar3;
}



===== IoctlDeviceGetAuthzState @ 140007854 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int IoctlDeviceGetAuthzState(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 *puVar2;
  longlong lVar3;
  undefined1 *local_res18 [2];
  
  local_res18[0] = (undefined1 *)0x0;
  puVar2 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_CHILD_DEVICE_EXTENSION_TYPE_INFO_1400160b8);
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,*puVar2,PTR__WDF_FILTER_DEVICE_EXTENSION_TYPE_INFO_140016018);
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,param_2,2,local_res18,0);
  if (iVar1 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
               &WPP_6b540f47682e3482637f60efce621d01_Traceguids,iVar1);
    }
  }
  else {
    *local_res18[0] = *(undefined1 *)(lVar3 + 0x177);
    local_res18[0][1] = *(int *)(lVar3 + 8) == 2;
    (**(code **)(WdfFunctions_01015 + 0x898))(WdfDriverGlobals,param_2,2);
  }
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar1);
  LogEvent("GetAuthz",(longlong)*(int *)(lVar3 + 8),(ulonglong)*(byte *)(lVar3 + 0xc),
           (longlong)iVar1);
  return iVar1;
}



===== ChildDevicePerformPartitionRediscovery @ 1400079c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void ChildDevicePerformPartitionRediscovery(undefined8 param_1)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  longlong lVar4;
  undefined *puVar5;
  undefined1 auStackY_c8 [32];
  longlong local_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 local_48;
  ulonglong uStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_c8;
  local_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_78 = 0;
  uVar2 = (**(code **)(WdfFunctions_01015 + 0xbe8))(WdfDriverGlobals,param_1);
  puVar3 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,uVar2,PTR__WDF_CHILD_DEVICE_EXTENSION_TYPE_INFO_1400160b8);
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,*puVar3,PTR__WDF_FILTER_DEVICE_EXTENSION_TYPE_INFO_140016018);
  puVar5 = (undefined *)(longlong)*(int *)(lVar4 + 8);
  LogEvent("PartDisc",(ulonglong)*(uint *)((longlong)puVar3 + 0x7c),puVar5,0);
  if ((*(uint *)(lVar4 + 0x130) & 4) != 0) {
    *(uint *)(lVar4 + 0x130) = *(uint *)(lVar4 + 0x130) & 0xfffffffb;
    iVar1 = IssueSyncIoctl(*(undefined8 *)(lVar4 + 0x1a0),(longlong *)puVar3[4],puVar5,0x700f0,0,0,
                           (longlong)&local_48,0x10,&local_78);
    if (iVar1 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        puVar5 = &WPP_45305c62c3e63920635d5fbdd89541d2_Traceguids;
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
                 &WPP_45305c62c3e63920635d5fbdd89541d2_Traceguids,iVar1);
      }
    }
    else if ((local_78 != 0x10) || ((uint)local_48 < 0x10)) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        puVar5 = &WPP_45305c62c3e63920635d5fbdd89541d2_Traceguids;
        WPP_SF_Pd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
                  &WPP_45305c62c3e63920635d5fbdd89541d2_Traceguids,local_78,(char)local_48);
      }
      iVar1 = -0x3fffff1b;
    }
    if (-1 < iVar1) {
      if (*(int *)(lVar4 + 8) == 1) {
        if ((uStack_40 & 1) == 0) {
          uStack_68 = 1;
          local_60 = 1;
          local_70 = CONCAT35(local_70._5_3_,0x28);
          iVar1 = IssueSyncIoctl(*(undefined8 *)(lVar4 + 0x1a0),(longlong *)puVar3[4],puVar5,0x7c0f4
                                 ,(longlong)&local_70,0x28,0,0,&local_78);
          LogEvent("DskOffLn",(ulonglong)*(uint *)((longlong)puVar3 + 0x7c),(longlong)iVar1,0);
          if (-1 < iVar1) {
            *(uint *)(lVar4 + 0x130) = *(uint *)(lVar4 + 0x130) | 8;
          }
        }
      }
      else {
        if (((uStack_40 & 1) != 0) && ((*(uint *)(lVar4 + 0x130) & 8) != 0)) {
          local_60 = 1;
          local_70 = CONCAT35(local_70._5_3_,0x28);
          uStack_68 = 0;
          iVar1 = IssueSyncIoctl(*(undefined8 *)(lVar4 + 0x1a0),(longlong *)puVar3[4],puVar5,0x7c0f4
                                 ,(longlong)&local_70,0x28,0,0,&local_78);
          puVar5 = (undefined *)(longlong)iVar1;
          LogEvent("DiskOnLn",(ulonglong)*(uint *)((longlong)puVar3 + 0x7c),puVar5,0);
          if (iVar1 < 0) goto LAB_140007cc4;
          *(uint *)(lVar4 + 0x130) = *(uint *)(lVar4 + 0x130) & 0xfffffff7;
        }
        iVar1 = IssueSyncIoctl(*(undefined8 *)(lVar4 + 0x1a0),(longlong *)puVar3[4],puVar5,0x70140,0
                               ,0,0,0,(undefined8 *)0x0);
        if (((iVar1 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
                   &WPP_45305c62c3e63920635d5fbdd89541d2_Traceguids,iVar1);
        }
      }
    }
  }
LAB_140007cc4:
  (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,param_1);
  return;
}



===== ForwardRequestToParentDeviceIoQueue @ 140007d10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int ForwardRequestToParentDeviceIoQueue(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined4 local_res18;
  undefined4 local_res1c;
  
  local_res18 = 8;
  local_res1c = 1;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0xc58))(WdfDriverGlobals,param_1,param_2,&local_res18);
  if (iVar1 < 0) {
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_1,iVar1);
  }
  return iVar1;
}



===== RtlStringValidateDestW @ 140007d8c =====

undefined8 RtlStringValidateDestW(undefined8 param_1,longlong param_2)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if (0x7ffffffe < param_2 - 1U) {
    uVar1 = 0xc000000d;
  }
  return uVar1;
}



===== IssueSecurityProtocolInTCG @ 140007dac =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int IssueSecurityProtocolInTCG
              (undefined8 param_1,longlong param_2,byte param_3,ushort param_4,longlong param_5,
              uint *param_6,char param_7,uint param_8)

{
  uint uVar1;
  int iVar2;
  byte bStackX_21;
  undefined1 auStackY_a8 [32];
  uint in_stack_ffffffffffffff78;
  undefined4 in_stack_ffffffffffffff7c;
  undefined4 in_stack_ffffffffffffff94;
  undefined1 local_58 [3];
  undefined1 auStack_55 [4];
  byte bStack_51;
  undefined8 uStack_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_a8;
  uVar1 = *param_6;
  if ((uVar1 & 0x1ff) == 0) {
    bStackX_21 = (byte)(param_4 >> 8);
    local_58 = (undefined1  [3])((uint3)bStackX_21 << 0x10);
    _local_58 = CONCAT53(0x8000,local_58);
    uStack_50 = (ulonglong)CONCAT11((char)(uVar1 >> 9),(char)((uVar1 >> 9) >> 8));
    local_58._0_2_ = CONCAT11(param_3,0xa2);
    _local_58 = CONCAT44(0x80,CONCAT13((char)param_4,local_58));
    _local_58 = CONCAT17((byte)(uVar1 >> 0x19),_local_58);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      in_stack_ffffffffffffff78 = (uint)param_4;
      WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
                &WPP_66125b4cf8143944cb9284854ee08e62_Traceguids,(uint)param_3,(char)param_4);
    }
    iVar2 = IssueSyncScsiCommand
                      (param_1,param_2,'\x01',local_58,
                       CONCAT44(in_stack_ffffffffffffff7c,
                                CONCAT31((int3)(in_stack_ffffffffffffff78 >> 8),0xc)),param_5,
                       param_6,CONCAT44(in_stack_ffffffffffffff94,0x14),param_7,param_8);
    if (((iVar2 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
               &WPP_66125b4cf8143944cb9284854ee08e62_Traceguids,iVar2);
    }
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
               &WPP_66125b4cf8143944cb9284854ee08e62_Traceguids,uVar1);
    }
    iVar2 = -0x3ffffdfa;
  }
  return iVar2;
}



===== FxStubUnbindClasses @ 140007f24 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl FxStubUnbindClasses(struct _WDF_BIND_INFO * __ptr64) */

void __cdecl FxStubUnbindClasses(_WDF_BIND_INFO *param_1)

{
  uint *puVar1;
  uint *puVar2;
  void **ppvVar3;
  
  ppvVar3 = &__KMDF_CLASS_BIND_END;
  if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_140016228 != &__KMDF_CLASS_BIND_START) {
    puVar1 = (uint *)(PTR___KMDF_CLASS_BIND_START_140016228 + 0x50);
    while (puVar2 = (uint *)FxGetNextClassBindInfo((longlong *)ppvVar3,(longlong *)puVar1),
          puVar2 != (uint *)0x0) {
      if (puVar1 <= puVar2) {
        return;
      }
      if (*(code **)(puVar2 + 0x10) == (code *)0x0) {
        WdfVersionUnbindClass(&WdfBindInfo,WdfDriverGlobals,puVar2);
      }
      else {
        (**(code **)(puVar2 + 0x10))
                  (WdfVersionUnbindClass_exref,&WdfBindInfo,WdfDriverGlobals,puVar2);
      }
      ppvVar3 = (void **)((longlong)puVar2 + (ulonglong)*puVar2);
    }
    DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
  }
  return;
}



===== McGenEventUnregister_EtwUnregister @ 140007fe0 =====

undefined8 McGenEventUnregister_EtwUnregister(void)

{
  undefined8 uVar1;
  
  if (EhStorClassEventProvider_Context == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = EtwUnregister();
    EhStorClassEventProvider_Context = 0;
  }
  return uVar1;
}



===== WPP_SF_ @ 140008014 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_(undefined8 param_1,undefined2 param_2,undefined8 param_3)

{
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,0);
  return;
}



===== FxStubDriverEntryFailure @ 140008040 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl FxStubDriverEntryFailure(void) */

void __cdecl FxStubDriverEntryFailure(void)

{
  int iVar1;
  undefined *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined4 local_14;
  
  if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_140016228 != &__KMDF_CLASS_BIND_START) {
    local_1c = 0;
    uStack_18 = 0;
    local_14 = 0;
    local_28 = &GUID_WDF_LOADER_INTERFACE_DRIVER_ENTRY_FAILURE;
    local_20 = 0x18;
    iVar1 = WdfLdrQueryInterface(&local_28);
    if (-1 < iVar1) {
      (*(code *)CONCAT44(local_14,uStack_18))(&WdfBindInfo,WdfDriverGlobals);
    }
  }
  return;
}



===== __report_gsfailure @ 1400080c0 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== __C_specific_handler @ 1400080cd =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001400080cd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== _vsnwprintf @ 1400080e0 =====

int __cdecl _vsnwprintf(wchar_t *_Dest,size_t _Count,wchar_t *_Format,va_list _Args)

{
  int iVar1;
  
  iVar1 = _vsnwprintf_l(_Dest,_Count,_Format,(_locale_t)0x0,_Args);
  return iVar1;
}



===== _vsnwprintf_l @ 140008100 =====

int __cdecl
_vsnwprintf_l(wchar_t *_DstBuf,size_t _MaxCount,wchar_t *_Format,_locale_t _Locale,va_list _ArgList)

{
  int iVar1;
  FILE local_38;
  
  local_38._12_4_ = 0;
  local_38._tmpfname._4_4_ = 0;
  local_38._file = 0;
  local_38._charbuf = 0;
  local_38._36_8_ = 0;
  if ((_Format == (wchar_t *)0x0) || ((_MaxCount != 0 && (_DstBuf == (wchar_t *)0x0)))) {
    _guard_check_icall();
    iVar1 = -1;
  }
  else {
    local_38._flag = 0x42;
    if (_MaxCount < 0x40000000) {
      local_38._cnt = (int)_MaxCount * 2;
    }
    else {
      local_38._cnt = 0x7fffffff;
    }
    local_38._ptr = (char *)_DstBuf;
    local_38._base = (char *)_DstBuf;
    iVar1 = _woutput_l(&local_38,_Format,_Locale,_ArgList);
    if (_DstBuf != (wchar_t *)0x0) {
      local_38._cnt = local_38._cnt + -1;
      if (local_38._cnt < 0) {
        _flsbuf(0,&local_38);
      }
      else {
        *local_38._ptr = 0;
        local_38._ptr = (char *)((longlong)local_38._ptr + 1);
      }
      local_38._cnt = local_38._cnt + -1;
      if (local_38._cnt < 0) {
        _flsbuf(0,&local_38);
      }
      else {
        *local_38._ptr = 0;
      }
    }
  }
  return iVar1;
}



===== _vsnprintf @ 1400081f8 =====

int __cdecl _vsnprintf(char *_Dest,size_t _Count,char *_Format,va_list _Args)

{
  int iVar1;
  
  iVar1 = _vsnprintf_l(_Dest,_Count,_Format,(_locale_t)0x0,_Args);
  return iVar1;
}



===== _vsnprintf_l @ 140008218 =====

int __cdecl
_vsnprintf_l(char *_DstBuf,size_t _MaxCount,char *_Format,_locale_t _Locale,va_list _ArgList)

{
  int iVar1;
  FILE local_38;
  
  local_38._12_4_ = 0;
  local_38._tmpfname._4_4_ = 0;
  local_38._file = 0;
  local_38._charbuf = 0;
  local_38._36_8_ = 0;
  if (_Format == (char *)0x0) {
LAB_1400082a9:
    _guard_check_icall();
    iVar1 = -1;
  }
  else {
    if (_MaxCount == 0) {
LAB_14000825f:
      local_38._cnt = (int)_MaxCount;
    }
    else {
      if (_DstBuf == (char *)0x0) goto LAB_1400082a9;
      local_38._cnt = 0x7fffffff;
      if (_MaxCount < 0x80000000) goto LAB_14000825f;
    }
    local_38._flag = 0x42;
    local_38._ptr = _DstBuf;
    local_38._base = _DstBuf;
    iVar1 = _output_l(&local_38,_Format,_Locale,_ArgList);
    if (_DstBuf != (char *)0x0) {
      local_38._cnt = local_38._cnt + -1;
      if (local_38._cnt < 0) {
        _flsbuf(0,&local_38);
      }
      else {
        *local_38._ptr = '\0';
      }
    }
  }
  return iVar1;
}



===== _flsbuf @ 1400082d8 =====

int __cdecl _flsbuf(int _Ch,FILE *_File)

{
  _File->_flag = _File->_flag | 0x20;
  return -1;
}



===== _woutput_l @ 1400082e8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl _woutput_l(FILE *_File,wchar_t *_Format,_locale_t _Locale,va_list _ArgList)

{
  char *pcVar1;
  ushort uVar2;
  ushort *puVar3;
  int *piVar4;
  wchar_t *pwVar5;
  int iVar6;
  ulonglong uVar7;
  uint uVar8;
  wchar_t *pwVar9;
  char cVar10;
  uint uVar11;
  uint uVar12;
  wchar_t *pwVar13;
  uint uVar14;
  FILE *pFVar15;
  uint uVar16;
  ulonglong uVar17;
  wchar_t wVar18;
  ulonglong uVar19;
  uint uVar20;
  wchar_t *pwVar21;
  int iVar22;
  undefined1 auStack_4d8 [32];
  undefined8 local_4b8;
  int local_4a8;
  uint local_4a4;
  uint local_4a0;
  wchar_t local_49c [2];
  int local_498;
  int local_494;
  char local_490 [4];
  wchar_t local_48c;
  short local_48a;
  uint local_488;
  wchar_t *local_480;
  int local_478;
  FILE *local_470;
  undefined4 local_468;
  wchar_t *local_460;
  wchar_t local_448 [255];
  undefined2 local_249;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_4d8;
  local_468 = 0;
  uVar16 = 0;
  local_488 = 0;
  uVar12 = 0;
  uVar14 = 0;
  local_4a0 = 0;
  pwVar13 = (wchar_t *)0x0;
  local_4a4 = 0;
  local_478 = 0;
  local_480 = (wchar_t *)_ArgList;
  local_470 = _File;
  memset(local_448,0,0x400);
  local_49c[0] = L'\0';
  local_498 = 0;
  if ((_File == (FILE *)0x0) || (_Format == (wchar_t *)0x0)) {
LAB_140008bac:
    local_4b8 = 0;
    _guard_check_icall();
    iVar6 = -1;
  }
  else {
    wVar18 = *_Format;
    iVar6 = 0;
    local_4a8 = 0;
    uVar19 = 0;
    local_494 = 0;
    if (wVar18 != L'\0') {
      do {
        pwVar21 = _Format + 1;
        if (iVar6 < 0) break;
        uVar8 = 0;
        if ((ushort)(wVar18 + L'￠') < 0x5b) {
          uVar20 = (int)"PartDisc"[(ulonglong)(ushort)wVar18 + 8] & 0xf;
        }
        else {
          uVar20 = uVar8;
        }
        uVar11 = (uint)(ushort)wVar18;
        local_494 = (int)(char)(&__lookuptable)[(int)(local_494 + uVar20 * 8)] >> 4;
        uVar20 = uVar16;
        local_460 = pwVar21;
        if (local_494 == 0) {
LAB_140008a80:
          local_498 = 1;
          write_char(wVar18,local_470,&local_4a8);
          uVar16 = uVar20;
LAB_14000892e:
          iVar6 = local_4a8;
LAB_140008936:
        }
        else if (local_494 == 1) {
          uVar12 = 0xffffffff;
          uVar14 = 0xffffffff;
          local_478 = 0;
          local_4a0 = 0xffffffff;
          local_488 = 0;
          local_4a4 = 0;
          local_498 = 0;
          uVar16 = uVar8;
        }
        else if (local_494 == 2) {
          if (uVar11 == 0x20) {
            uVar16 = uVar16 | 2;
          }
          else if (uVar11 == 0x23) {
            uVar16 = uVar16 | 0x80;
          }
          else if (uVar11 == 0x2b) {
            uVar16 = uVar16 | 1;
          }
          else if (uVar11 == 0x2d) {
            uVar16 = uVar16 | 4;
          }
          else if (uVar11 == 0x30) {
            uVar16 = uVar16 | 8;
          }
        }
        else if (local_494 == 3) {
          if (wVar18 == L'*') {
            uVar8 = *(uint *)_ArgList;
            local_480 = (wchar_t *)((longlong)_ArgList + 8);
            if ((int)uVar8 < 0) {
              uVar16 = uVar16 | 4;
            }
            local_488 = -uVar8;
            if (-1 < (int)uVar8) {
              local_488 = uVar8;
            }
          }
          else {
            local_488 = uVar11 + (local_488 * 5 + -0x18) * 2;
          }
        }
        else if (local_494 == 4) {
          local_4a0 = 0;
          uVar14 = uVar8;
          uVar12 = uVar8;
        }
        else if (local_494 == 5) {
          if (wVar18 == L'*') {
            local_4a0 = *(uint *)_ArgList;
            local_480 = (wchar_t *)((longlong)_ArgList + 8);
            uVar14 = local_4a0;
            uVar12 = local_4a0;
            if ((int)local_4a0 < 0) {
              local_4a0 = 0xffffffff;
              uVar14 = 0xffffffff;
              uVar12 = 0xffffffff;
            }
          }
          else {
            local_4a0 = uVar11 + (uVar14 * 5 + -0x18) * 2;
            uVar14 = local_4a0;
            uVar12 = local_4a0;
          }
        }
        else if (local_494 == 6) {
          if (uVar11 == 0x49) {
LAB_1400089d1:
            uVar20 = uVar16 | 0x8000;
            if (wVar18 == L'I') {
              if (*pwVar21 == L'6') {
                if (_Format[2] != L'4') goto LAB_140008a54;
                pwVar21 = _Format + 3;
                uVar16 = uVar20;
              }
              else {
                if ((*pwVar21 != L'3') || (_Format[2] != L'2')) {
LAB_140008a54:
                  if ((ushort)(*pwVar21 + L'ﾨ') < 0x21) {
                    uVar16 = uVar20;
                    if ((0x120821001U >> ((ulonglong)(ushort)(*pwVar21 + L'ﾨ') & 0x3f) & 1) != 0)
                    goto LAB_140008940;
                  }
                  local_494 = 0;
                  goto LAB_140008a80;
                }
                pwVar21 = _Format + 3;
                uVar16 = uVar16 & 0xffff7fff;
              }
            }
            else {
              uVar16 = uVar20;
              if (wVar18 != L'j') goto LAB_140008a54;
            }
          }
          else if (uVar11 == 0x68) {
            uVar16 = uVar16 | 0x20;
          }
          else {
            if (uVar11 == 0x6a) goto LAB_1400089d1;
            if (uVar11 == 0x6c) {
              if (*pwVar21 == L'l') {
                pwVar21 = _Format + 2;
                uVar16 = uVar16 | 0x1000;
              }
              else {
                uVar16 = uVar16 | 0x10;
              }
            }
            else {
              if (uVar11 == 0x74) goto LAB_1400089d1;
              if (uVar11 == 0x77) {
                uVar16 = uVar16 | 0x800;
              }
              else if (uVar11 == 0x7a) goto LAB_1400089d1;
            }
          }
        }
        else if (local_494 == 7) {
          if ((ushort)wVar18 < 0x6a) {
            if (wVar18 == L'i') {
LAB_140008479:
              uVar16 = uVar16 | 0x40;
LAB_14000847c:
              uVar19 = 10;
              goto LAB_140008487;
            }
            if (uVar11 == 0x43) {
              if ((uVar16 & 0x830) == 0) {
                uVar16 = uVar16 | 0x20;
              }
LAB_1400085b0:
              local_49c[0] = *(wchar_t *)_ArgList;
              local_480 = (wchar_t *)((longlong)_ArgList + 8);
              local_498 = 1;
              if ((uVar16 & 0x20) == 0) {
                local_448[0] = local_49c[0];
              }
              else {
                local_490[0] = (char)local_49c[0];
                local_490[1] = 0;
                iVar22 = mbtowc(local_448,local_490,(longlong)__mb_cur_max);
                if (iVar22 < 0) {
                  local_478 = 1;
                }
              }
              pwVar13 = local_448;
              uVar19 = 1;
            }
            else if (uVar11 == 0x53) {
              if ((uVar16 & 0x830) == 0) {
                uVar16 = uVar16 | 0x20;
              }
LAB_140008539:
              pwVar13 = *(wchar_t **)_ArgList;
              uVar8 = uVar14;
              if (uVar14 == 0xffffffff) {
                uVar8 = 0x7fffffff;
              }
              local_480 = (wchar_t *)((longlong)_ArgList + 8);
              if ((uVar16 & 0x20) == 0) {
                local_498 = 1;
                pwVar9 = L"(null)";
                pwVar5 = L"(null)";
                if (pwVar13 != (wchar_t *)0x0) {
                  pwVar9 = pwVar13;
                  pwVar5 = pwVar13;
                }
                for (; (pwVar13 = pwVar5, uVar8 != 0 && (uVar8 = uVar8 - 1, *pwVar9 != L'\0'));
                    pwVar9 = pwVar9 + 1) {
                  pwVar5 = pwVar13;
                }
                uVar19 = (longlong)pwVar9 - (longlong)pwVar13 >> 1 & 0xffffffff;
              }
              else {
                if (pwVar13 == (wchar_t *)0x0) {
                  pwVar13 = L"渨汵⥬";
                }
                pwVar9 = pwVar13;
                uVar19 = 0;
                if (0 < (int)uVar8) {
                  do {
                    if ((char)*pwVar9 == '\0') break;
                    pwVar9 = (wchar_t *)((longlong)pwVar9 + 1);
                    uVar20 = (int)uVar19 + 1;
                    uVar19 = (ulonglong)uVar20;
                  } while ((int)uVar20 < (int)uVar8);
                }
              }
            }
            else {
              if (uVar11 == 0x58) goto LAB_14000868a;
              if (uVar11 == 0x5a) {
                puVar3 = *(ushort **)_ArgList;
                local_480 = (wchar_t *)((longlong)_ArgList + 8);
                if ((puVar3 == (ushort *)0x0) ||
                   (pwVar13 = *(wchar_t **)(puVar3 + 4), pwVar13 == (wchar_t *)0x0)) {
                  pwVar13 = L"渨汵⥬";
                  uVar7 = 0xffffffffffffffff;
                  do {
                    uVar19 = uVar7 + 1;
                    pcVar1 = "null)" + uVar7;
                    uVar7 = uVar19;
                  } while (*pcVar1 != '\0');
                }
                else {
                  uVar2 = *puVar3;
                  if (puVar3[1] < uVar2) goto LAB_140008bac;
                  uVar19 = (ulonglong)(uint)uVar2;
                  if ((uVar16 >> 0xb & 1) == 0) {
                    local_498 = 0;
                  }
                  else {
                    if (((~(uint)uVar2 & 1) == 0) || ((~(uint)pwVar13 & 1) == 0))
                    goto LAB_140008bac;
                    uVar19 = (ulonglong)(uVar2 >> 1);
                    local_498 = 1;
                  }
                }
              }
              else {
                if (uVar11 == 99) goto LAB_1400085b0;
                if (uVar11 == 100) goto LAB_140008479;
              }
            }
LAB_1400087c6:
            if (local_478 != 0) goto LAB_140008936;
            if ((uVar16 & 0x40) != 0) {
              if ((uVar16 >> 8 & 1) == 0) {
                if ((uVar16 & 1) == 0) {
                  if ((uVar16 & 2) == 0) goto LAB_140008814;
                  local_48c = L' ';
                }
                else {
                  local_48c = L'+';
                }
              }
              else {
                local_48c = L'-';
              }
              local_4a4 = 1;
            }
LAB_140008814:
            uVar14 = local_4a4;
            iVar6 = (int)uVar19;
            iVar22 = (local_488 - iVar6) - local_4a4;
            if ((uVar16 & 0xc) == 0) {
              write_multi_char(L' ',iVar22,local_470,&local_4a8);
            }
            write_string(&local_48c,uVar14,local_470,&local_4a8);
            pFVar15 = local_470;
            if ((uVar16 & 0xc) == 8) {
              write_multi_char(L'0',iVar22,local_470,&local_4a8);
            }
            if ((local_498 == 0) && (0 < iVar6)) {
              uVar7 = uVar19 & 0xffffffff;
              pwVar21 = pwVar13;
              do {
                iVar6 = mbtowc(local_49c,(char *)pwVar21,(longlong)__mb_cur_max);
                uVar14 = (int)uVar7 - ((iVar6 == 2) + 1);
                uVar7 = (ulonglong)uVar14;
                if (iVar6 < 1) {
                  local_4a8 = -1;
                  pFVar15 = local_470;
                  pwVar21 = local_460;
                  goto LAB_14000890a;
                }
                write_char(local_49c[0],local_470,&local_4a8);
                pwVar21 = (wchar_t *)((longlong)pwVar21 + (longlong)iVar6);
              } while (0 < (int)uVar14);
              pFVar15 = local_470;
              pwVar21 = local_460;
            }
            else {
              write_string(pwVar13,iVar6,pFVar15,&local_4a8);
            }
LAB_14000890a:
            iVar6 = local_4a8;
            if ((-1 < local_4a8) && ((uVar16 & 4) != 0)) {
              write_multi_char(L' ',iVar22,pFVar15,&local_4a8);
              uVar14 = local_4a0;
              uVar12 = local_4a0;
              goto LAB_14000892e;
            }
          }
          else {
            if (wVar18 != L'n') {
              if (wVar18 == L'o') {
                uVar19 = 8;
                if ((char)uVar16 < '\0') {
                  uVar16 = uVar16 | 0x200;
                }
              }
              else {
                if (wVar18 == L'p') {
                  uVar12 = 0x10;
                  uVar14 = 0x10;
                  uVar16 = uVar16 | 0x8000;
LAB_14000868a:
                  local_468 = 7;
                }
                else {
                  if (wVar18 == L's') goto LAB_140008539;
                  if (wVar18 == L'u') goto LAB_14000847c;
                  if (wVar18 != L'x') goto LAB_1400087c6;
                  local_468 = 0x27;
                }
                if ((char)uVar16 < '\0') {
                  local_4a4 = 2;
                  local_48a = (short)local_468 + 0x51;
                  local_48c = L'0';
                }
                uVar19 = 0x10;
              }
LAB_140008487:
              local_480 = (wchar_t *)((longlong)_ArgList + 8);
              if ((uVar16 >> 0xf == 0) && ((uVar16 >> 0xc & 1) == 0)) {
                if ((uVar16 & 0x20) == 0) {
                  if ((uVar16 & 0x40) != 0) {
                    uVar7 = (ulonglong)(int)*(uint *)_ArgList;
                    goto LAB_140008701;
                  }
                  uVar7 = (ulonglong)*(uint *)_ArgList;
                }
                else if ((uVar16 & 0x40) == 0) {
                  uVar7 = (ulonglong)(ushort)*(wchar_t *)_ArgList;
                }
                else {
                  uVar7 = (ulonglong)*(wchar_t *)_ArgList;
LAB_140008701:
                  if ((longlong)uVar7 < 0) {
                    uVar7 = -uVar7;
                    uVar16 = uVar16 | 0x100;
                  }
                }
              }
              else {
                uVar7 = *(ulonglong *)_ArgList;
                if ((uVar16 & 0x40) != 0) goto LAB_140008701;
              }
              uVar17 = uVar7 & 0xffffffff;
              if ((uVar16 & 0x9000) != 0) {
                uVar17 = uVar7;
              }
              if ((int)uVar14 < 0) {
                uVar12 = 1;
              }
              else {
                uVar16 = uVar16 & 0xfffffff7;
                if (0x200 < (int)uVar14) {
                  uVar12 = 0x200;
                }
              }
              local_4a4 = -(uint)(uVar17 != 0) & local_4a4;
              pwVar9 = &local_249;
              for (; (uVar14 = uVar12 - 1, 0 < (int)uVar12 || (uVar17 != 0));
                  uVar17 = uVar17 / uVar19) {
                uVar12 = (int)(uVar17 % uVar19) + 0x30;
                cVar10 = (char)uVar12;
                if (0x39 < uVar12) {
                  cVar10 = cVar10 + (char)local_468;
                }
                *(char *)pwVar9 = cVar10;
                pwVar9 = (wchar_t *)((longlong)pwVar9 + -1);
                uVar12 = uVar14;
              }
              uVar12 = (int)&local_249 - (int)pwVar9;
              uVar19 = (ulonglong)uVar12;
              pwVar13 = (wchar_t *)((longlong)pwVar9 + 1);
              if (((uVar16 >> 9 & 1) != 0) && ((uVar12 == 0 || (*(char *)pwVar13 != '0')))) {
                uVar19 = (ulonglong)(uVar12 + 1);
                *(char *)pwVar9 = '0';
                pwVar13 = pwVar9;
              }
              uVar12 = uVar14;
              local_4a0 = uVar14;
              goto LAB_1400087c6;
            }
            piVar4 = *(int **)_ArgList;
            local_480 = (wchar_t *)((longlong)_ArgList + 8);
            iVar22 = _get_printf_count_output();
            if (iVar22 == 0) goto LAB_140008bac;
            if ((uVar16 & 0x20) == 0) {
              *piVar4 = iVar6;
            }
            else {
              *(short *)piVar4 = (short)iVar6;
            }
            local_478 = 1;
          }
          uVar14 = local_4a0;
          uVar12 = local_4a0;
        }
LAB_140008940:
        wVar18 = *pwVar21;
        _Format = pwVar21;
        _ArgList = (va_list)local_480;
      } while (wVar18 != L'\0');
    }
  }
  return iVar6;
}



===== write_char @ 140008bf4 =====

void write_char(wchar_t param_1,FILE *param_2,int *param_3)

{
  wint_t wVar1;
  
  if (((param_2->_flag & 0x40U) == 0) || (param_2->_base != (char *)0x0)) {
    wVar1 = _fputwc_nolock(param_1,param_2);
    if ((wVar1 == 0xffff) && ((param_2->_flag & 0x20U) != 0)) {
      *param_3 = -1;
    }
    else {
      *param_3 = *param_3 + 1;
    }
  }
  else {
    *param_3 = *param_3 + 1;
  }
  return;
}



===== write_multi_char @ 140008c48 =====

void write_multi_char(wchar_t param_1,int param_2,FILE *param_3,int *param_4)

{
  if (0 < param_2) {
    do {
      param_2 = param_2 + -1;
      write_char(param_1,param_3,param_4);
      if (*param_4 == -1) {
        return;
      }
    } while (0 < param_2);
  }
  return;
}



===== write_string @ 140008ca0 =====

void write_string(wchar_t *param_1,int param_2,FILE *param_3,int *param_4)

{
  if (((param_3->_flag & 0x40U) == 0) || (param_3->_base != (char *)0x0)) {
    do {
      if (param_2 < 1) {
        return;
      }
      param_2 = param_2 + -1;
      write_char(*param_1,param_3,param_4);
      param_1 = param_1 + 1;
    } while (*param_4 != -1);
  }
  else {
    *param_4 = *param_4 + param_2;
  }
  return;
}



===== _output_l @ 140008d14 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Type propagation algorithm not settling */

int __cdecl _output_l(FILE *_File,char *_Format,_locale_t _Locale,va_list _ArgList)

{
  char *pcVar1;
  byte bVar2;
  ushort uVar3;
  wchar_t _WCh;
  ushort *puVar4;
  int *piVar5;
  FILE *pFVar6;
  wchar_t *pwVar7;
  errno_t eVar8;
  ulonglong uVar9;
  uint uVar10;
  uint uVar11;
  wchar_t *pwVar12;
  char cVar13;
  int iVar14;
  uint uVar15;
  wchar_t *pwVar16;
  int iVar17;
  ulonglong uVar18;
  ulonglong uVar19;
  byte *pbVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  undefined1 auStack_2b8 [32];
  undefined8 local_298;
  uint local_288;
  int local_284;
  byte local_280;
  char local_27f;
  int local_27c;
  int local_278;
  int local_274;
  int local_270;
  wchar_t *local_268;
  int local_260;
  undefined4 local_25c;
  FILE *local_258;
  int local_250 [2];
  wchar_t local_248 [255];
  undefined2 uStack_49;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_2b8;
  local_25c = 0;
  uVar22 = 0;
  local_270 = 0;
  uVar15 = 0;
  uVar21 = 0;
  local_288 = 0;
  local_260 = 0;
  pwVar16 = (wchar_t *)0x0;
  local_268 = (wchar_t *)_ArgList;
  local_258 = _File;
  memset(local_248,0,0x200);
  local_278 = 0;
  if ((_File == (FILE *)0x0) || (_Format == (char *)0x0)) {
LAB_140009541:
    local_298 = 0;
    _guard_check_icall();
    return -1;
  }
  bVar2 = *_Format;
  iVar17 = 0;
  local_284 = 0;
  local_274 = 0;
  local_27c = 0;
  uVar11 = 0;
joined_r0x000140008db6:
  if ((bVar2 == 0) || (pbVar20 = (byte *)(_Format + 1), iVar17 < 0)) {
    return iVar17;
  }
  uVar10 = 0;
  if ((byte)(bVar2 - 0x20) < 0x5b) {
    uVar23 = (int)"PartDisc"[(longlong)(char)bVar2 + 8] & 0xf;
  }
  else {
    uVar23 = uVar10;
  }
  iVar14 = (int)(char)bVar2;
  local_274 = (int)(char)(&__lookuptable)[(int)(local_274 + uVar23 * 8)] >> 4;
  if (local_274 == 0) {
LAB_14000940e:
    local_278 = 0;
    write_char(bVar2,local_258,&local_284);
LAB_140009425:
    iVar17 = local_284;
  }
  else {
    if (local_274 == 1) {
      local_260 = 0;
      local_270 = 0;
      local_288 = 0;
      uVar15 = 0xffffffff;
      uVar21 = 0xffffffff;
      local_278 = 0;
      uVar22 = uVar10;
      goto LAB_140009432;
    }
    if (local_274 == 2) {
      if (bVar2 == 0x20) {
        uVar22 = uVar22 | 2;
        uVar10 = uVar11;
      }
      else if (bVar2 == 0x23) {
        uVar22 = uVar22 | 0x80;
        uVar10 = uVar11;
      }
      else if (bVar2 == 0x2b) {
        uVar22 = uVar22 | 1;
        uVar10 = uVar11;
      }
      else if (bVar2 == 0x2d) {
        uVar22 = uVar22 | 4;
        uVar10 = uVar11;
      }
      else {
        uVar10 = uVar11;
        if (bVar2 == 0x30) {
          uVar22 = uVar22 | 8;
        }
      }
      goto LAB_140009432;
    }
    if (local_274 == 3) {
      if (bVar2 == 0x2a) {
        iVar14 = *(int *)_ArgList;
        local_268 = (wchar_t *)((longlong)_ArgList + 8);
        if (iVar14 < 0) {
          uVar22 = uVar22 | 4;
        }
        local_270 = -iVar14;
        if (-1 < iVar14) {
          local_270 = iVar14;
        }
        uVar10 = uVar11;
      }
      else {
        local_270 = iVar14 + (local_270 * 5 + -0x18) * 2;
        uVar10 = uVar11;
      }
      goto LAB_140009432;
    }
    if (local_274 == 4) {
      uVar21 = uVar10;
      uVar15 = uVar10;
      uVar10 = uVar11;
      goto LAB_140009432;
    }
    if (local_274 == 5) {
      if (bVar2 == 0x2a) {
        uVar21 = *(uint *)_ArgList;
        local_268 = (wchar_t *)((longlong)_ArgList + 8);
        uVar15 = uVar21;
        uVar10 = uVar11;
        if ((int)uVar21 < 0) {
          uVar21 = 0xffffffff;
          uVar15 = 0xffffffff;
        }
      }
      else {
        uVar21 = iVar14 + (uVar21 * 5 + -0x18) * 2;
        uVar15 = uVar21;
        uVar10 = uVar11;
      }
      goto LAB_140009432;
    }
    if (local_274 == 6) {
      if (bVar2 == 0x49) {
LAB_14000937f:
        uVar23 = uVar22 | 0x8000;
        if (bVar2 == 0x49) {
          if (*pbVar20 == 0x36) {
            if (_Format[2] != 0x34) goto LAB_1400093ef;
            pbVar20 = (byte *)(_Format + 3);
            uVar22 = uVar23;
            uVar10 = uVar11;
          }
          else {
            if ((*pbVar20 != 0x33) || (_Format[2] != 0x32)) {
LAB_1400093ef:
              if ((byte)(*pbVar20 + 0xa8) < 0x21) {
                uVar22 = uVar23;
                uVar10 = uVar11;
                if ((0x120821001U >> ((ulonglong)(byte)(*pbVar20 + 0xa8) & 0x3f) & 1) != 0)
                goto LAB_140009432;
              }
              local_274 = 0;
              uVar22 = uVar23;
              goto LAB_14000940e;
            }
            pbVar20 = (byte *)(_Format + 3);
            uVar22 = uVar22 & 0xffff7fff;
            uVar10 = uVar11;
          }
        }
        else {
          uVar22 = uVar23;
          uVar10 = uVar11;
          if (bVar2 != 0x6a) goto LAB_1400093ef;
        }
      }
      else if (bVar2 == 0x68) {
        uVar22 = uVar22 | 0x20;
        uVar10 = uVar11;
      }
      else {
        if (bVar2 == 0x6a) goto LAB_14000937f;
        if (bVar2 == 0x6c) {
          bVar2 = *pbVar20;
          if (bVar2 == 0x6c) {
            pbVar20 = (byte *)(_Format + 2);
          }
          uVar10 = 0x1000;
          if (bVar2 != 0x6c) {
            uVar10 = 0x10;
          }
          uVar22 = uVar22 | uVar10;
          uVar10 = uVar11;
        }
        else {
          if (bVar2 == 0x74) goto LAB_14000937f;
          if (bVar2 == 0x77) {
            uVar22 = uVar22 | 0x800;
            uVar10 = uVar11;
          }
          else {
            uVar10 = uVar11;
            if (bVar2 == 0x7a) goto LAB_14000937f;
          }
        }
      }
      goto LAB_140009432;
    }
    uVar10 = uVar11;
    if (local_274 != 7) goto LAB_140009432;
    if (iVar14 < 0x6a) {
      if (iVar14 == 0x69) {
LAB_140008e92:
        uVar22 = uVar22 | 0x40;
LAB_140008e96:
        uVar19 = 10;
LAB_140008ea1:
        local_268 = (wchar_t *)((longlong)_ArgList + 8);
        if ((uVar22 >> 0xf == 0) && ((uVar22 >> 0xc & 1) == 0)) {
          if ((uVar22 & 0x20) == 0) {
            if ((uVar22 & 0x40) != 0) {
              uVar9 = (ulonglong)*(int *)_ArgList;
              goto LAB_1400090f3;
            }
            uVar9 = (ulonglong)*(uint *)_ArgList;
          }
          else if ((uVar22 & 0x40) == 0) {
            uVar9 = (ulonglong)(ushort)*(wchar_t *)_ArgList;
          }
          else {
            uVar9 = (ulonglong)*(wchar_t *)_ArgList;
LAB_1400090f3:
            if ((longlong)uVar9 < 0) {
              uVar9 = -uVar9;
              uVar22 = uVar22 | 0x100;
            }
          }
        }
        else {
          uVar9 = *(ulonglong *)_ArgList;
          if ((uVar22 & 0x40) != 0) goto LAB_1400090f3;
        }
        uVar18 = uVar9 & 0xffffffff;
        if ((uVar22 & 0x9000) != 0) {
          uVar18 = uVar9;
        }
        if ((int)uVar21 < 0) {
          uVar15 = 1;
        }
        else {
          uVar22 = uVar22 & 0xfffffff7;
          if (0x200 < (int)uVar21) {
            uVar15 = 0x200;
          }
        }
        uVar11 = -(uint)(uVar18 != 0) & uVar11;
        pwVar12 = &uStack_49;
        for (; (uVar21 = uVar15 - 1, 0 < (int)uVar15 || (uVar18 != 0)); uVar18 = uVar18 / uVar19) {
          uVar15 = (int)(uVar18 % uVar19) + 0x30;
          cVar13 = (char)uVar15;
          if (0x39 < uVar15) {
            cVar13 = cVar13 + (char)local_25c;
          }
          *(char *)pwVar12 = cVar13;
          pwVar12 = (wchar_t *)((longlong)pwVar12 + -1);
          uVar15 = uVar21;
        }
        local_27c = (int)&uStack_49 - (int)pwVar12;
        pwVar16 = (wchar_t *)((longlong)pwVar12 + 1);
        if (((uVar22 >> 9 & 1) != 0) && ((local_27c == 0 || (*(char *)pwVar16 != '0')))) {
          local_27c = local_27c + 1;
          *(char *)pwVar12 = '0';
          pwVar16 = pwVar12;
        }
        uVar15 = uVar21;
        local_288 = uVar11;
      }
      else if (iVar14 == 0x43) {
        if ((uVar22 & 0x830) == 0) {
          uVar22 = uVar22 | 0x800;
        }
LAB_140008fae:
        local_268 = (wchar_t *)((longlong)_ArgList + 8);
        if ((uVar22 & 0x810) == 0) {
          local_248[0]._0_1_ = (char)*(wchar_t *)_ArgList;
          local_27c = 1;
        }
        else {
          eVar8 = wctomb_s(&local_27c,(char *)local_248,0x200,*(wchar_t *)_ArgList);
          if (eVar8 != 0) {
            local_260 = 1;
          }
        }
        pwVar16 = local_248;
      }
      else if (iVar14 == 0x53) {
        if ((uVar22 & 0x830) == 0) {
          uVar22 = uVar22 | 0x800;
        }
LAB_140008f55:
        pwVar16 = *(wchar_t **)_ArgList;
        uVar10 = uVar21;
        if (uVar21 == 0xffffffff) {
          uVar10 = 0x7fffffff;
        }
        local_268 = (wchar_t *)((longlong)_ArgList + 8);
        if ((uVar22 & 0x810) == 0) {
          pwVar12 = L"渨汵⥬";
          pwVar7 = L"渨汵⥬";
          if (pwVar16 != (wchar_t *)0x0) {
            pwVar12 = pwVar16;
            pwVar7 = pwVar16;
          }
          for (; (pwVar16 = pwVar7, uVar10 != 0 && (uVar10 = uVar10 - 1, (char)*pwVar12 != '\0'));
              pwVar12 = (wchar_t *)((longlong)pwVar12 + 1)) {
            pwVar7 = pwVar16;
          }
          local_27c = (int)pwVar12 - (int)pwVar16;
        }
        else {
          if (pwVar16 == (wchar_t *)0x0) {
            pwVar16 = L"(null)";
          }
          local_278 = 1;
          for (pwVar12 = pwVar16; (uVar10 != 0 && (uVar10 = uVar10 - 1, *pwVar12 != L'\0'));
              pwVar12 = pwVar12 + 1) {
          }
          local_27c = (int)((longlong)pwVar12 - (longlong)pwVar16 >> 1);
        }
      }
      else {
        if (iVar14 == 0x58) goto LAB_140009089;
        if (iVar14 == 0x5a) {
          puVar4 = *(ushort **)_ArgList;
          local_268 = (wchar_t *)((longlong)_ArgList + 8);
          if ((puVar4 == (ushort *)0x0) ||
             (pwVar16 = *(wchar_t **)(puVar4 + 4), pwVar16 == (wchar_t *)0x0)) {
            pwVar16 = L"渨汵⥬";
            uVar19 = 0xffffffffffffffff;
            do {
              uVar9 = uVar19 + 1;
              pcVar1 = "null)" + uVar19;
              uVar19 = uVar9;
            } while (*pcVar1 != '\0');
          }
          else {
            uVar3 = *puVar4;
            if (puVar4[1] < uVar3) goto LAB_140009541;
            uVar9 = (ulonglong)(uint)uVar3;
            if ((uVar22 >> 0xb & 1) == 0) {
              local_278 = 0;
            }
            else {
              if (((~(uint)uVar3 & 1) == 0) || ((~(uint)pwVar16 & 1) == 0)) goto LAB_140009541;
              local_278 = 1;
              uVar9 = (ulonglong)(uVar3 >> 1);
            }
          }
          local_27c = (int)uVar9;
        }
        else {
          if (iVar14 == 99) goto LAB_140008fae;
          if (iVar14 == 100) goto LAB_140008e92;
        }
      }
LAB_1400091bc:
      if (local_260 == 0) {
        if ((uVar22 & 0x40) != 0) {
          if ((uVar22 >> 8 & 1) == 0) {
            if ((uVar22 & 1) == 0) {
              if ((uVar22 & 2) == 0) goto LAB_140009205;
              local_280 = 0x20;
            }
            else {
              local_280 = 0x2b;
            }
          }
          else {
            local_280 = 0x2d;
          }
          local_288 = 1;
        }
LAB_140009205:
        uVar11 = local_288;
        iVar17 = (local_270 - local_27c) - local_288;
        if ((uVar22 & 0xc) == 0) {
          write_multi_char(0x20,iVar17,local_258,&local_284);
        }
        write_string(&local_280,uVar11,local_258,&local_284);
        pFVar6 = local_258;
        if ((uVar22 & 0xc) == 8) {
          write_multi_char(0x30,iVar17,local_258,&local_284);
        }
        if ((local_278 == 0) || (local_27c < 1)) {
          write_string((byte *)pwVar16,local_27c,pFVar6,&local_284);
        }
        else {
          local_250[0] = 0;
          pwVar12 = pwVar16;
          iVar14 = local_27c;
          do {
            _WCh = *pwVar12;
            pwVar12 = pwVar12 + 1;
            iVar14 = iVar14 + -1;
            eVar8 = wctomb_s(local_250,(char *)((longlong)&uStack_49 + 1),6,_WCh);
            if ((eVar8 != 0) || (local_250[0] == 0)) {
              local_284 = -1;
              break;
            }
            write_string((byte *)((longlong)&uStack_49 + 1),local_250[0],local_258,&local_284);
          } while (iVar14 != 0);
        }
        if ((-1 < local_284) && ((uVar22 & 4) != 0)) {
          write_multi_char(0x20,iVar17,local_258,&local_284);
          uVar11 = local_288;
          goto LAB_140009425;
        }
        iVar17 = local_284;
        uVar11 = local_288;
      }
      goto LAB_14000942d;
    }
    if (iVar14 != 0x6e) {
      if (iVar14 == 0x6f) {
        uVar19 = 8;
        if ((char)uVar22 < '\0') {
          uVar22 = uVar22 | 0x200;
        }
      }
      else {
        if (iVar14 == 0x70) {
          uVar15 = 0x10;
          uVar21 = 0x10;
          uVar22 = uVar22 | 0x8000;
LAB_140009089:
          local_25c = 7;
        }
        else {
          if (iVar14 == 0x73) goto LAB_140008f55;
          if (iVar14 == 0x75) goto LAB_140008e96;
          if (iVar14 != 0x78) goto LAB_1400091bc;
          local_25c = 0x27;
        }
        if ((char)uVar22 < '\0') {
          local_27f = (char)local_25c + 'Q';
          local_280 = 0x30;
          uVar11 = 2;
        }
        uVar19 = 0x10;
      }
      goto LAB_140008ea1;
    }
    local_268 = (wchar_t *)((longlong)_ArgList + 8);
    piVar5 = *(int **)_ArgList;
    iVar14 = _get_printf_count_output();
    if (iVar14 == 0) goto LAB_140009541;
    if ((uVar22 & 0x20) == 0) {
      *piVar5 = iVar17;
    }
    else {
      *(short *)piVar5 = (short)iVar17;
    }
    local_260 = 1;
  }
LAB_14000942d:
  uVar10 = uVar11;
LAB_140009432:
  bVar2 = *pbVar20;
  _Format = (char *)pbVar20;
  _ArgList = (va_list)local_268;
  uVar11 = uVar10;
  goto joined_r0x000140008db6;
}



===== write_char @ 14000958c =====

void write_char(byte param_1,FILE *param_2,int *param_3)

{
  int *piVar1;
  uint uVar2;
  
  if (((param_2->_flag & 0x40U) == 0) || (param_2->_base != (char *)0x0)) {
    piVar1 = &param_2->_cnt;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 < 0) {
      uVar2 = _flsbuf((int)(char)param_1,param_2);
    }
    else {
      *param_2->_ptr = param_1;
      param_2->_ptr = param_2->_ptr + 1;
      uVar2 = (uint)param_1;
    }
    if (uVar2 == 0xffffffff) {
      *param_3 = -1;
    }
    else {
      *param_3 = *param_3 + 1;
    }
  }
  else {
    *param_3 = *param_3 + 1;
  }
  return;
}



===== write_multi_char @ 1400095dc =====

void write_multi_char(byte param_1,int param_2,FILE *param_3,int *param_4)

{
  if (0 < param_2) {
    do {
      param_2 = param_2 + -1;
      write_char(param_1,param_3,param_4);
      if (*param_4 == -1) {
        return;
      }
    } while (0 < param_2);
  }
  return;
}



===== write_string @ 140009634 =====

void write_string(byte *param_1,int param_2,FILE *param_3,int *param_4)

{
  if (((param_3->_flag & 0x40U) == 0) || (param_3->_base != (char *)0x0)) {
    do {
      if (param_2 < 1) {
        return;
      }
      param_2 = param_2 + -1;
      write_char(*param_1,param_3,param_4);
      param_1 = param_1 + 1;
    } while (*param_4 != -1);
  }
  else {
    *param_4 = *param_4 + param_2;
  }
  return;
}



===== _get_printf_count_output @ 1400096a8 =====

int __cdecl _get_printf_count_output(void)

{
  return (int)(DAT_140016260 == (__security_cookie | 1));
}



===== _fputwc_nolock @ 1400096c8 =====

wint_t __cdecl _fputwc_nolock(wchar_t _Ch,FILE *_File)

{
  int *piVar1;
  int iVar2;
  
  if (_File == (FILE *)0x0) {
    _guard_check_icall();
    _Ch = L'\xffff';
  }
  else {
    piVar1 = &_File->_cnt;
    *piVar1 = *piVar1 + -2;
    if (*piVar1 < 0) {
      iVar2 = _flswbuf((uint)(ushort)_Ch,_File);
      _Ch = (wchar_t)iVar2;
    }
    else {
      *(wchar_t *)_File->_ptr = _Ch;
      _File->_ptr = _File->_ptr + 2;
    }
  }
  return _Ch;
}



===== mbtowc @ 140009714 =====

int __cdecl mbtowc(wchar_t *_DstCh,char *_SrcCh,size_t _SrcSizeInBytes)

{
  wchar_t wVar1;
  char *local_res10 [3];
  
  local_res10[0]._0_4_ = 0;
  if ((_SrcCh != (char *)0x0) && (_SrcSizeInBytes != 0)) {
    if (*_SrcCh == '\0') {
      if (_DstCh != (wchar_t *)0x0) {
        *_DstCh = L'\0';
      }
    }
    else {
      local_res10[0] = _SrcCh;
      wVar1 = RtlAnsiCharToUnicodeChar(local_res10);
      *_DstCh = wVar1;
      local_res10[0]._0_4_ = (int)local_res10[0] - (int)_SrcCh;
    }
  }
  return (int)local_res10[0];
}



===== __GSHandlerCheck @ 140009768 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 14000978c =====

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



===== _wctomb_s_l @ 1400097f8 =====

errno_t __cdecl
_wctomb_s_l(int *_SizeConverted,char *_MbCh,size_t _SizeInBytes,wchar_t _WCh,_locale_t _Locale)

{
  int iVar1;
  int local_res10 [4];
  wchar_t local_res20 [4];
  
  if ((_MbCh == (char *)0x0) && (_SizeInBytes != 0)) {
    if (_SizeConverted != (int *)0x0) {
      *_SizeConverted = 0;
    }
  }
  else {
    if (_SizeConverted != (int *)0x0) {
      *_SizeConverted = -1;
    }
    local_res20[0] = _WCh;
    if (0x7fffffff < _SizeInBytes) {
      _guard_check_icall();
      return 0x16;
    }
    if (_MbCh == (char *)0x0) {
      if (_SizeConverted != (int *)0x0) {
        *_SizeConverted = __mb_cur_max;
      }
    }
    else {
      local_res10[0] = 0;
      iVar1 = RtlUnicodeToMultiByteN(_MbCh,_SizeInBytes & 0xffffffff,local_res10,local_res20,2);
      if (iVar1 < 0) {
        return 0x2a;
      }
      if (_SizeConverted != (int *)0x0) {
        *_SizeConverted = local_res10[0];
      }
    }
  }
  return 0;
}



===== wctomb_s @ 1400098a8 =====

errno_t __cdecl wctomb_s(int *_SizeConverted,char *_MbCh,rsize_t _SizeInBytes,wchar_t _WCh)

{
  errno_t eVar1;
  
  eVar1 = _wctomb_s_l(_SizeConverted,_MbCh,_SizeInBytes,_WCh,(_locale_t)0x0);
  return eVar1;
}



===== _flswbuf @ 1400098c4 =====

int __cdecl _flswbuf(int _Ch,FILE *_File)

{
  _File->_flag = _File->_flag | 0x20;
  return 0xffff;
}



===== __cpu_features_init @ 1400098e0 =====

/* WARNING: Removing unreachable block (ram,0x00014000994a) */
/* WARNING: Removing unreachable block (ram,0x0001400098f9) */
/* WARNING: Removing unreachable block (ram,0x0001400098ea) */

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



===== RtlAnsiCharToUnicodeChar @ 1400099a6 =====

void RtlAnsiCharToUnicodeChar(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001400099a6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RtlAnsiCharToUnicodeChar();
  return;
}



===== RtlUnicodeToMultiByteN @ 1400099b8 =====

void RtlUnicodeToMultiByteN(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001400099b8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RtlUnicodeToMultiByteN();
  return;
}



===== ext_ms_win_ntos_ksr_l1_1_5_KsrPersistMemory @ 1400099d0 =====

undefined8 ext_ms_win_ntos_ksr_l1_1_5_KsrPersistMemory(void)

{
  return 0xc00000bb;
}



===== ext_ms_win_ntos_ksr_l1_1_5_KsrFreePersistedMemory @ 1400099e0 =====

undefined8 ext_ms_win_ntos_ksr_l1_1_5_KsrFreePersistedMemory(void)

{
  return 0;
}



===== WPP_SF_D @ 1400099ec =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_D(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,0);
  return;
}



===== WppClassicProviderCallback @ 140009a30 =====

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



===== wil_details_FeatureDescriptors_SkipPadding @ 140009a64 =====

longlong * wil_details_FeatureDescriptors_SkipPadding(longlong *param_1)

{
  while( true ) {
    if (&UNK_140015d0f < param_1) {
      return (longlong *)0x0;
    }
    if (*param_1 != 0) break;
    param_1 = param_1 + 1;
  }
  return param_1;
}



===== wil_details_RecordCachedUsage @ 140009a8c =====

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



===== wil_details_RecordFeatureUsageReporting @ 140009be0 =====

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



===== FilterDeviceEvtCleanup @ 140009c70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FilterDeviceEvtCleanup(undefined8 param_1)

{
  longlong lVar1;
  
  LogEvent("FCleanup",param_1,0,0);
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FILTER_DEVICE_EXTENSION_TYPE_INFO_140016018);
  if (*(longlong *)(lVar1 + 0x1c8) != 0) {
    ExFreePoolWithTag(*(longlong *)(lVar1 + 0x1c8),0);
    *(undefined8 *)(lVar1 + 0x1c8) = 0;
  }
  *(undefined4 *)(lVar1 + 0x1d0) = 0;
  if (*(longlong *)(lVar1 + 0x1e8) != 0) {
    ExFreePoolWithTag(*(longlong *)(lVar1 + 0x1e8),0);
    *(undefined8 *)(lVar1 + 0x1e8) = 0;
  }
  *(undefined4 *)(lVar1 + 0x1f0) = 0;
  *(undefined4 *)(lVar1 + 500) = 0;
  if (*(longlong *)(lVar1 + 0x218) != 0) {
    ExFreePoolWithTag(*(longlong *)(lVar1 + 0x218),0);
    *(undefined8 *)(lVar1 + 0x218) = 0;
  }
  *(undefined4 *)(lVar1 + 0x220) = 0;
  return;
}



===== FilterDeviceEvtD0Exit @ 140009d50 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 FilterDeviceEvtD0Exit(undefined8 param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined8 *puVar3;
  longlong lVar4;
  longlong lVar5;
  
  puVar3 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_FILTER_DEVICE_EXTENSION_TYPE_INFO_140016018)
  ;
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*puVar3);
  iVar1 = *(int *)(puVar3 + 1);
  lVar5 = (longlong)iVar1;
  uVar2 = *(uint *)(puVar3 + 2);
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*puVar3);
  LogEvent("FD0ExitE",param_1,lVar5,(longlong)param_2);
  if ((Microsoft_Windows_EnhancedStorage_ClassDriverEnableBits & 1) != 0) {
    McTemplateK0quuujuu_EtwWriteTransfer
              (puVar3 + 0x2c,&DeviceExitD0,lVar5,(uint)*(byte *)((longlong)puVar3 + 0x174),
               *(undefined1 *)((longlong)puVar3 + 0x175),*(undefined1 *)((longlong)puVar3 + 0x176),
               *(undefined1 *)((longlong)puVar3 + 0x177),puVar3 + 0x2c,
               *(undefined1 *)(puVar3 + 0x25),(char)*(undefined4 *)(puVar3 + 1));
  }
  if (iVar1 == 2) {
    if ((uVar2 & 1) == 0) {
      if ((*(uint *)((longlong)puVar3 + 0x134) & 0xf00) != 0) {
        FilterDeviceSetState(param_1,1,1);
      }
    }
    else if ((KsrShutdown == '\0') && (DisablePowerDownDeauthentication == '\0')) {
      FilterDeviceSetState(param_1,1,2);
      if (((*(uint *)((longlong)puVar3 + 0x134) & 0xf000) != 0x5000) ||
         (uVar2 = *(uint *)(puVar3 + 0x26), -1 < (char)uVar2)) {
        *(uint *)(puVar3 + 0x26) = *(uint *)(puVar3 + 0x26) | 0x40;
        (**(code **)(WdfFunctions_01015 + 0x430))(WdfDriverGlobals,param_1);
        while (lVar5 = (**(code **)(WdfFunctions_01015 + 0x438))(WdfDriverGlobals,param_1),
              lVar5 != 0) {
          lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                            (WdfDriverGlobals,lVar5,
                             PTR__WDF_CHILD_DEVICE_EXTENSION_TYPE_INFO_1400160b8);
          if ((*(uint *)(lVar4 + 0x84) & 1) != 0) {
            lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
            if (*(longlong *)(lVar4 + 0x18) == 0) {
              if (*(int *)(lVar4 + 0x7c) == 0x104) {
                if (*(int *)(puVar3 + 0x25) == 0) {
                  ChildDeviceSendTPerReset1667(param_1,lVar5);
                }
                else {
                  SendTCGTPerReset(param_1,0x800,(undefined4 *)0x0,(ulonglong *)0x0);
                }
              }
            }
            else if (KsrShutdown == '\0') {
              ChildDeviceSendOnDemandAuthenticationRequest(lVar5,0);
            }
          }
        }
        (**(code **)(WdfFunctions_01015 + 0x440))(WdfDriverGlobals,param_1);
        uVar2 = *(uint *)(puVar3 + 0x26) & 0xffffffbf;
      }
      *(uint *)(puVar3 + 0x26) = uVar2 | 0x10;
    }
  }
  if ((4 < param_2) && (0x5000 < (*(uint *)((longlong)puVar3 + 0x134) & 0xf000))) {
    (**(code **)(WdfFunctions_01015 + 0x528))(WdfDriverGlobals,puVar3[0x31]);
    (**(code **)(WdfFunctions_01015 + 0x528))(WdfDriverGlobals,puVar3[0x32]);
  }
  if (puVar3[0x38] != 0) {
    (**(code **)(WdfFunctions_01015 + 0x4d8))(WdfDriverGlobals);
    *(uint *)(puVar3 + 0x26) = *(uint *)(puVar3 + 0x26) & 0xfffffeff;
  }
  LogEvent("FD0ExitX",0,0,0);
  return 0;
}



===== FilterDeviceEvtSelfManagedIoInit @ 14000a0c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FilterDeviceEvtSelfManagedIoInit(undefined8 param_1)

{
  wchar_t *pwVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  undefined4 uVar5;
  undefined8 *puVar6;
  undefined8 uVar7;
  longlong lVar8;
  undefined8 uVar9;
  undefined2 uVar10;
  wchar_t *pwVar11;
  undefined *puVar12;
  ulonglong *puVar13;
  ulonglong uVar14;
  undefined1 auStackY_198 [32];
  undefined8 local_138;
  ulonglong local_130;
  undefined8 local_128;
  uint local_120 [2];
  ulonglong local_118 [5];
  undefined8 uStack_f0;
  undefined8 local_e8;
  undefined8 local_d8;
  undefined8 local_b8;
  undefined4 local_48;
  ulonglong local_44;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_198;
  local_118[0] = (ulonglong)(uint)local_118[0];
  memset(&local_d8,0,0x88);
  local_44 = (ulonglong)(uint)local_44;
  local_130 = 0;
  local_128 = 0;
  local_120[0] = 0;
  LogEvent("FStartE",param_1,0,0);
  puVar6 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_FILTER_DEVICE_EXTENSION_TYPE_INFO_140016018)
  ;
  local_e8 = 0;
  local_118[2] = 0;
  local_118[1] = 0;
  local_118[0] = 0x38;
  uStack_f0 = 0;
  local_118[3] = 0x100000001;
  local_118[4] = param_1;
  iVar4 = (**(code **)(WdfFunctions_01015 + 0x580))(WdfDriverGlobals,puVar6[0x33],9,1);
  if (iVar4 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,
               &WPP_7186403ff6ae38c3a7435fda3b62a1f7_Traceguids,iVar4);
    }
    pwVar11 = L"<unknown>";
  }
  else {
    pwVar11 = (wchar_t *)(**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,local_128,0);
  }
  pwVar1 = (wchar_t *)(puVar6 + 0x2a);
  RtlInitUnicodeString(pwVar1,pwVar11);
  puVar12 = (undefined *)0xb;
  iVar4 = (**(code **)(WdfFunctions_01015 + 0x580))(WdfDriverGlobals,puVar6[0x33]);
  if (iVar4 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      puVar12 = &WPP_7186403ff6ae38c3a7435fda3b62a1f7_Traceguids;
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,
               &WPP_7186403ff6ae38c3a7435fda3b62a1f7_Traceguids,iVar4);
    }
    RtlInitUnicodeString(pwVar1,L"<unknown>");
  }
  else {
    puVar12 = (undefined *)0x0;
    uVar9 = (**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,local_128);
    RtlInitUnicodeString(puVar6 + 0x28,uVar9);
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    uVar9 = param_1;
    uVar7 = (**(code **)(WdfFunctions_01015 + 0x108))(WdfDriverGlobals);
    WPP_SF_qZZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar9,puVar12,uVar7,pwVar1,
               (wchar_t *)(puVar6 + 0x28));
  }
  puVar13 = (ulonglong *)0x47536353;
  lVar8 = ExAllocatePool2(0x40);
  if (lVar8 == 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      puVar13 = (ulonglong *)&WPP_7186403ff6ae38c3a7435fda3b62a1f7_Traceguids;
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x25,
               &WPP_7186403ff6ae38c3a7435fda3b62a1f7_Traceguids,0x200);
    }
    iVar4 = -0x3fffff66;
  }
  else {
    puVar13 = local_118;
    iVar4 = (**(code **)(WdfFunctions_01015 + 0x538))(WdfDriverGlobals);
    if (iVar4 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar10 = 0x26;
LAB_14000a527:
        puVar13 = (ulonglong *)&WPP_7186403ff6ae38c3a7435fda3b62a1f7_Traceguids;
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar10,
                 &WPP_7186403ff6ae38c3a7435fda3b62a1f7_Traceguids,iVar4);
      }
    }
    else {
      uVar9 = (**(code **)(WdfFunctions_01015 + 0x108))(WdfDriverGlobals,param_1);
      local_b8 = IoGetAttachedDeviceReference(uVar9);
      puVar6[0x35] = local_b8;
      puVar13 = &local_d8;
      local_d8._0_4_ = 0x88;
      local_d8._4_4_ = 1;
      iVar4 = (**(code **)(WdfFunctions_01015 + 0x540))(WdfDriverGlobals,puVar6[0x34]);
      if (iVar4 < 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          puVar13 = (ulonglong *)&WPP_7186403ff6ae38c3a7435fda3b62a1f7_Traceguids;
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x27,
                   &WPP_7186403ff6ae38c3a7435fda3b62a1f7_Traceguids,iVar4);
        }
        (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
        puVar6[0x34] = 0;
      }
      else {
        puVar13 = *(ulonglong **)(puVar6[0x37] + 8);
        iVar4 = (**(code **)(WdfFunctions_01015 + 0x5d8))(WdfDriverGlobals);
        if (iVar4 < 0) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar10 = 0x28;
            goto LAB_14000a527;
          }
        }
        else {
          iVar4 = IssueSyncIoctl(puVar6[0x33],(longlong *)puVar6[0x37],puVar13,0x41018,0,0,
                                 (longlong)(puVar6 + 0x2e),8,&local_130);
          if ((iVar4 < 0) || (local_130 < 8)) {
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              puVar13 = (ulonglong *)&WPP_7186403ff6ae38c3a7435fda3b62a1f7_Traceguids;
              WPP_SF_Pd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x29,
                        &WPP_7186403ff6ae38c3a7435fda3b62a1f7_Traceguids,local_130,(char)iVar4);
            }
            iVar4 = 0;
            puVar6[0x2e] = 0;
          }
        }
      }
    }
  }
  local_44 = 0;
  local_48 = 0;
  local_138 = 0;
  if (iVar4 < 0) goto LAB_14000a8dc;
  iVar4 = IssueSyncIoctl(puVar6[0x33],(longlong *)puVar6[0x37],puVar13,0x2d1400,(longlong)&local_48,
                         0xc,(longlong)&local_138,8,&local_130);
  if (iVar4 < 0) {
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14000a8dc;
    uVar10 = 0x2a;
LAB_14000a77e:
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar10,
             &WPP_7186403ff6ae38c3a7435fda3b62a1f7_Traceguids,iVar4);
    goto LAB_14000a8dc;
  }
  if (local_130 < 8) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_P(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,puVar13,local_130);
    }
    goto LAB_14000a8dc;
  }
  iVar4 = (**(code **)(WdfFunctions_01015 + 0x600))(WdfDriverGlobals);
  if (iVar4 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2c,
                &WPP_7186403ff6ae38c3a7435fda3b62a1f7_Traceguids,local_138._4_4_,(char)iVar4);
    }
    goto LAB_14000a8dc;
  }
  uVar14 = (ulonglong)local_138._4_4_;
  memset((void *)puVar6[0x2f],0,uVar14);
  iVar4 = IssueSyncIoctl(puVar6[0x33],(longlong *)puVar6[0x37],uVar14,0x2d1400,(longlong)&local_48,
                         0xc,puVar6[0x2f],local_138._4_4_,&local_130);
  if (iVar4 < 0) {
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14000a8dc;
    uVar10 = 0x2d;
    goto LAB_14000a77e;
  }
  uVar14 = local_138 >> 0x20;
  if (local_130 < uVar14) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_Pd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2e,
                &WPP_7186403ff6ae38c3a7435fda3b62a1f7_Traceguids,local_130,(char)(local_138 >> 0x20)
               );
    }
    goto LAB_14000a8dc;
  }
  if (ForceNativeOpalSupport == '\0') {
    bVar2 = FilterDeviceDiscoverPdoCaps(param_1);
    if (!bVar2) goto LAB_14000a819;
    cVar3 = FilterDeviceCheck1667Support(param_1,local_120);
    if (cVar3 == '\0') goto LAB_14000a819;
    uVar9 = FilterDeviceEnumerate1667Silos(param_1);
    if ((char)uVar9 == '\0') goto LAB_14000a8dc;
    uVar5 = 0;
  }
  else {
LAB_14000a819:
    if (EnableNativeOpalSupport == '\0') goto LAB_14000a8dc;
    uVar9 = FilterDeviceCheckNativeOpal(param_1);
    if ((char)uVar9 == '\0') goto LAB_14000a8dc;
    uVar5 = 1;
  }
  *(undefined4 *)(puVar6 + 0x25) = uVar5;
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*puVar6);
  uVar5 = *(undefined4 *)(puVar6 + 1);
  uVar9 = *puVar6;
  *(undefined4 *)(puVar6 + 1) = 1;
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals);
  if ((Microsoft_Windows_EnhancedStorage_ClassDriverEnableBits & 1) != 0) {
    McTemplateK0quuujuuu_EtwWriteTransfer
              (puVar6 + 0x2c,uVar9,uVar14,(uint)*(byte *)((longlong)puVar6 + 0x174),
               *(undefined1 *)((longlong)puVar6 + 0x175),*(undefined1 *)((longlong)puVar6 + 0x176),
               *(undefined1 *)((longlong)puVar6 + 0x177),puVar6 + 0x2c,
               *(undefined1 *)(puVar6 + 0x25),(char)uVar5,1);
  }
LAB_14000a8dc:
  if (lVar8 != 0) {
    ExFreePoolWithTag(lVar8);
  }
  LogEvent("FStartX",0,0,0);
  return 0;
}



===== FilterDeviceEvtSurpriseRemoval @ 14000a940 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FilterDeviceEvtSurpriseRemoval(undefined8 param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  uVar2 = 0;
  LogEvent("FSurpRmv",param_1,0,0);
  if ((Microsoft_Windows_EnhancedStorage_ClassDriverEnableBits & 4) != 0) {
    McTemplateK0quuujuu_EtwWriteTransfer
              ((ulonglong)
               CONCAT31((int3)((uint)*(undefined4 *)(lVar1 + 8) >> 8),*(undefined1 *)(lVar1 + 0x128)
                       ),&DeviceSurpriseRemoved,uVar2,(uint)*(byte *)(lVar1 + 0x174),
               *(undefined1 *)(lVar1 + 0x175),*(undefined1 *)(lVar1 + 0x176),
               *(undefined1 *)(lVar1 + 0x177),lVar1 + 0x160,*(undefined1 *)(lVar1 + 0x128),
               (char)*(undefined4 *)(lVar1 + 8));
  }
  return;
}



===== FilterDeviceEvtWdmPnpIrpPreprocess @ 14000aa00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int FilterDeviceEvtWdmPnpIrpPreprocess(undefined8 param_1,longlong param_2)

{
  int iVar1;
  longlong *plVar2;
  bool bVar3;
  undefined8 local_68;
  code *pcStack_60;
  ulonglong local_58;
  undefined4 local_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined *local_20;
  
  local_20 = (undefined *)((ulonglong)local_20 & 0xffffffff00000000);
  local_58 = local_58 & 0xffffffff00000000;
  local_50 = 0;
  uStack_4c = 0;
  uStack_48 = 0;
  uStack_44 = 0;
  local_40 = 0;
  uStack_3c = 0;
  uStack_38 = 0;
  local_30 = 0;
  uStack_28 = 0;
  local_68 = 0;
  pcStack_60 = (code *)0x0;
  if ((**(char **)(param_2 + 0xb8) == '\x1b') && ((*(char **)(param_2 + 0xb8))[1] == '\0')) {
    uStack_3c = 0;
    uStack_28 = 0;
    local_20 = PTR__WDF_PNP_IRP_WORKITEM_CONTEXT_TYPE_INFO_140016130;
    pcStack_60 = FilterDevicePreprocessStartIrp;
    uStack_4c = 0;
    uStack_48 = 0;
    uStack_44 = 0;
    local_40 = 0;
    local_50 = 0x38;
    uStack_38 = 0x100000001;
    local_68 = 0x18;
    local_58 = 1;
    local_30 = param_1;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0xbd8))(WdfDriverGlobals,&local_68,&local_50);
    bVar3 = -1 < iVar1;
    if (bVar3) {
      plVar2 = (longlong *)
               (**(code **)(WdfFunctions_01015 + 0x650))
                         (WdfDriverGlobals,0,PTR__WDF_PNP_IRP_WORKITEM_CONTEXT_TYPE_INFO_140016130);
      *plVar2 = param_2;
      (**(code **)(WdfFunctions_01015 + 0xbe0))(WdfDriverGlobals,0);
      iVar1 = 0x103;
    }
    LogEvent("FPnpIrpX",param_1,(longlong)iVar1,0);
    if (bVar3) {
      return iVar1;
    }
  }
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x110))(WdfDriverGlobals,param_1,param_2);
  return iVar1;
}



===== FilterDeviceRecalcAggregatedSiloCaps @ 14000ab90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FilterDeviceRecalcAggregatedSiloCaps(undefined8 param_1)

{
  undefined4 uVar1;
  byte bVar2;
  undefined8 *puVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  byte bVar8;
  
  puVar3 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_FILTER_DEVICE_EXTENSION_TYPE_INFO_140016018)
  ;
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*puVar3);
  (**(code **)(WdfFunctions_01015 + 0x430))(WdfDriverGlobals,param_1);
  lVar7 = 0;
  *(undefined4 *)(puVar3 + 2) = 0;
  while( true ) {
    lVar7 = (**(code **)(WdfFunctions_01015 + 0x438))(WdfDriverGlobals,param_1,lVar7,1);
    if (lVar7 == 0) break;
    lVar4 = (**(code **)(WdfFunctions_01015 + 0x108))(WdfDriverGlobals,lVar7);
    lVar5 = IoGetAttachedDeviceReference(lVar4);
    lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,lVar7,PTR__WDF_CHILD_DEVICE_EXTENSION_TYPE_INFO_1400160b8);
    *(uint *)(puVar3 + 2) = *(uint *)(puVar3 + 2) | *(uint *)(lVar6 + 0x84);
    if ((lVar4 != lVar5) && ((*(uint *)(lVar6 + 0x84) & 1) == 0)) {
      *(uint *)(puVar3 + 2) = *(uint *)(puVar3 + 2) | 0x80000000;
    }
    ObfDereferenceObject(lVar5);
  }
  uVar1 = *(undefined4 *)(puVar3 + 2);
  (**(code **)(WdfFunctions_01015 + 0x440))(WdfDriverGlobals,param_1);
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*puVar3);
  bVar2 = (byte)((uint)uVar1 >> 0x18);
  bVar8 = bVar2 >> 7;
  (**(code **)(WdfFunctions_01015 + 0x188))(WdfDriverGlobals,param_1,1,bVar8);
  (**(code **)(WdfFunctions_01015 + 0x188))(WdfDriverGlobals,param_1,2,bVar8);
  (**(code **)(WdfFunctions_01015 + 0x188))(WdfDriverGlobals,param_1,3,bVar2 >> 7);
  return;
}



===== McTemplateK0quuujuuu_EtwWriteTransfer @ 14000adb0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0quuujuuu_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined8 param_8,
               undefined1 param_9,undefined1 param_10,undefined1 param_11)

{
  undefined4 local_res20 [2];
  undefined1 auStackY_d8 [32];
  undefined8 local_a8 [2];
  undefined4 *local_98;
  undefined8 local_90;
  undefined1 *local_88;
  undefined8 local_80;
  undefined1 *local_78;
  undefined8 local_70;
  undefined1 *local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_d8;
  local_98 = local_res20;
  local_90 = 4;
  local_88 = &param_5;
  local_80 = 1;
  local_78 = &param_6;
  local_70 = 1;
  local_68 = &param_7;
  local_58 = param_8;
  local_48 = &param_9;
  local_38 = &param_10;
  local_28 = &param_11;
  local_60 = 1;
  local_50 = 0x10;
  local_40 = 1;
  local_30 = 1;
  local_20 = 1;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&DeviceStateChange,param_3,9,local_a8);
  return;
}



===== WPP_SF_P @ 14000ae88 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_P(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_7186403ff6ae38c3a7435fda3b62a1f7_Traceguids,param_2,&local_res20,8,0)
  ;
  return;
}



===== WPP_SF_Pd @ 14000aed0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Pd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,&param_5,4,0);
  return;
}



===== WPP_SF_DD @ 14000af24 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,&param_5,4,0);
  return;
}



===== WPP_SF_q @ 14000af74 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_q(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,0);
  return;
}



===== WPP_SF_qZZ @ 14000afb8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qZZ(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               wchar_t *param_5,wchar_t *param_6)

{
  wchar_t wVar1;
  wchar_t wVar2;
  wchar_t *pwVar3;
  wchar_t *pwVar4;
  undefined8 local_res20;
  
  pwVar3 = L"NULL";
  if (param_6 == (wchar_t *)0x0) {
    wVar2 = L'\b';
  }
  else {
    wVar2 = *param_6;
    if (*param_6 != L'\0') {
      pwVar4 = *(wchar_t **)(param_6 + 4);
      goto LAB_14000b00e;
    }
  }
  pwVar4 = L"NULL";
LAB_14000b00e:
  if (param_6 == (wchar_t *)0x0) {
    param_6 = L"\b";
  }
  if (param_5 == (wchar_t *)0x0) {
    wVar1 = L'\b';
  }
  else {
    wVar1 = *param_5;
    if (*param_5 != L'\0') {
      pwVar3 = *(wchar_t **)(param_5 + 4);
    }
  }
  if (param_5 == (wchar_t *)0x0) {
    param_5 = L"\b";
  }
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_7186403ff6ae38c3a7435fda3b62a1f7_Traceguids,0x24,&local_res20,8,
             param_5,2,pwVar3,wVar1,param_6,2,pwVar4,wVar2,0);
  return;
}



===== ChildDeviceSchedulePartitionRediscovery @ 14000b0c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int ChildDeviceSchedulePartitionRediscovery(undefined8 param_1)

{
  int iVar1;
  undefined8 *puVar2;
  longlong lVar3;
  undefined8 local_res8;
  ulonglong local_58;
  code *pcStack_50;
  undefined8 local_48;
  ulonglong local_40 [5];
  undefined8 uStack_18;
  undefined8 local_10;
  
  local_res8 = 0;
  local_40[0] = (ulonglong)(uint)local_40[0];
  local_58 = (ulonglong)(uint)local_58;
  puVar2 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_CHILD_DEVICE_EXTENSION_TYPE_INFO_1400160b8);
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,*puVar2);
  *(uint *)(lVar3 + 0x130) = *(uint *)(lVar3 + 0x130) | 4;
  LogEvent("SchdPart",(ulonglong)*(uint *)((longlong)puVar2 + 0x7c),0,0);
  local_10 = 0;
  local_58 = 0x18;
  local_40[2] = 0;
  pcStack_50 = ChildDevicePerformPartitionRediscovery;
  local_40[1] = 0;
  local_40[3] = 0x100000001;
  uStack_18 = 0;
  local_48 = 1;
  local_40[0] = 0x38;
  local_40[4] = param_1;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0xbd8))(WdfDriverGlobals,&local_58,local_40,&local_res8)
  ;
  if (iVar1 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
               &WPP_45305c62c3e63920635d5fbdd89541d2_Traceguids,iVar1);
    }
  }
  else {
    (**(code **)(WdfFunctions_01015 + 0xbe0))(WdfDriverGlobals,local_res8);
  }
  return iVar1;
}



===== DefaultQueueEvtDefault @ 14000b230 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void DefaultQueueEvtDefault(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  longlong lVar2;
  undefined8 uVar3;
  longlong lVar4;
  longlong lVar5;
  
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_REQUEST_CONTEXT_TYPE_INFO_140016108);
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,uVar3);
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals,param_2);
  if ((**(char **)(lVar5 + 0xb8) == '\x03') || (**(char **)(lVar5 + 0xb8) == '\x04')) {
    (**(code **)(WdfFunctions_01015 + 0x8c8))(WdfDriverGlobals,param_2,*(undefined8 *)(lVar4 + 400))
    ;
  }
  else {
    iVar1 = ForwardRequestToLocalIoTargetWithCompletionRoutine(param_2,uVar3,(undefined *)0x0);
    if ((iVar1 < 0) && (*(char *)(lVar2 + 8) == '\x01')) {
      KeSetEvent(lVar2 + 0x10,0,0);
    }
  }
  return;
}



===== FilterDeviceSetState @ 14000b358 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FilterDeviceSetState(undefined8 param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  undefined1 uVar2;
  int iVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  undefined *puVar6;
  
  puVar6 = PTR__WDF_FILTER_DEVICE_EXTENSION_TYPE_INFO_140016018;
  puVar4 = (undefined8 *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  if (param_3 == 1) {
    (**(code **)(WdfFunctions_01015 + 0x4d8))(WdfDriverGlobals,puVar4[0x32],0,0);
    puVar6 = (undefined *)0x2;
    (**(code **)(WdfFunctions_01015 + 0x560))(WdfDriverGlobals,puVar4[0x33]);
  }
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*puVar4);
  uVar1 = *(undefined4 *)(puVar4 + 1);
  if (param_2 == -1) {
    iVar3 = *(int *)(puVar4 + 1);
  }
  else {
    iVar3 = param_2;
  }
  *(int *)(puVar4 + 1) = iVar3;
  if (param_3 == 1) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
    if (param_3 != 0) {
      uVar2 = *(undefined1 *)((longlong)puVar4 + 0xc);
    }
  }
  *(undefined1 *)((longlong)puVar4 + 0xc) = uVar2;
  if (param_3 == 1) {
    (**(code **)(WdfFunctions_01015 + 0x558))(WdfDriverGlobals,puVar4[0x33]);
  }
  if (*(char *)((longlong)puVar4 + 0xc) != '\x01') {
    (**(code **)(WdfFunctions_01015 + 0x4d0))(WdfDriverGlobals,puVar4[0x32]);
    (**(code **)(WdfFunctions_01015 + 0x4d0))(WdfDriverGlobals,puVar4[0x31]);
  }
  uVar5 = *puVar4;
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals);
  if ((param_2 != -1) && ((Microsoft_Windows_EnhancedStorage_ClassDriverEnableBits & 1) != 0)) {
    McTemplateK0quuujuuu_EtwWriteTransfer
              (puVar4 + 0x2c,uVar5,puVar6,(uint)*(byte *)((longlong)puVar4 + 0x174),
               *(undefined1 *)((longlong)puVar4 + 0x175),*(undefined1 *)((longlong)puVar4 + 0x176),
               *(undefined1 *)((longlong)puVar4 + 0x177),puVar4 + 0x2c,
               *(undefined1 *)(puVar4 + 0x25),(char)uVar1,(char)param_2);
  }
  return;
}



===== McTemplateK0quuujzzxzxzxzxzxzxzxzx_EtwWriteTransfer @ 14000b530 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0quuujzzxzxzxzxzxzxzxzx_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined8 param_8,
               undefined8 param_9,undefined8 param_10,undefined1 param_11,undefined8 param_12,
               undefined1 param_13,undefined8 param_14,undefined1 param_15,undefined8 param_16,
               undefined1 param_17)

{
  longlong lVar1;
  undefined4 local_res20 [2];
  undefined1 auStackY_1d8 [32];
  undefined8 local_1a8;
  undefined8 local_1a0;
  undefined8 local_198;
  undefined8 local_190;
  undefined8 local_188 [2];
  undefined4 *local_178;
  undefined8 local_170;
  undefined1 *local_168;
  undefined8 local_160;
  undefined1 *local_158;
  undefined8 local_150;
  undefined1 *local_148;
  undefined8 local_140;
  undefined8 local_138;
  undefined8 local_130;
  wchar_t *local_128;
  int local_120;
  undefined4 local_11c;
  wchar_t *local_118;
  undefined8 local_110;
  undefined1 *local_108;
  undefined8 local_100;
  wchar_t *local_f8;
  undefined8 local_f0;
  undefined1 *local_e8;
  undefined8 local_e0;
  wchar_t *local_d8;
  undefined8 local_d0;
  undefined1 *local_c8;
  undefined8 local_c0;
  wchar_t *local_b8;
  undefined8 local_b0;
  undefined1 *local_a8;
  undefined8 local_a0;
  wchar_t *local_98;
  undefined8 local_90;
  undefined8 *local_88;
  undefined8 local_80;
  wchar_t *local_78;
  undefined8 local_70;
  undefined8 *local_68;
  undefined8 local_60;
  wchar_t *local_58;
  undefined8 local_50;
  undefined8 *local_48;
  undefined8 local_40;
  wchar_t *local_38;
  undefined8 local_30;
  undefined8 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_1d8;
  local_170 = 4;
  local_178 = local_res20;
  local_190 = 0;
  local_168 = &param_5;
  local_198 = 0;
  local_158 = &param_6;
  local_148 = &param_7;
  local_138 = param_8;
  lVar1 = -1;
  local_1a0 = 0;
  local_1a8 = 0;
  local_160 = 1;
  local_150 = 1;
  local_140 = 1;
  local_130 = 0x10;
  do {
    lVar1 = lVar1 + 1;
  } while (L"Security passthrough command encountered"[lVar1] != L'\0');
  local_120 = (int)lVar1 * 2 + 2;
  local_11c = 0;
  local_98 = L"NULL";
  local_118 = L"IoControlCode";
  local_108 = &param_11;
  local_78 = L"NULL";
  local_f8 = L"Security Command";
  local_e8 = &param_13;
  local_d8 = L"Security Protocol";
  local_c8 = &param_15;
  local_b8 = L"Blocked";
  local_a8 = &param_17;
  local_88 = &local_1a8;
  local_68 = &local_1a0;
  local_48 = &local_198;
  local_28 = &local_190;
  local_58 = L"NULL";
  local_38 = L"NULL";
  local_128 = L"Security passthrough command encountered";
  local_110 = 0x1c;
  local_100 = 8;
  local_f0 = 0x22;
  local_e0 = 8;
  local_d0 = 0x24;
  local_c0 = 8;
  local_b0 = 0x10;
  local_a0 = 8;
  local_90 = 10;
  local_80 = 8;
  local_70 = 10;
  local_60 = 8;
  local_50 = 10;
  local_40 = 8;
  local_30 = 10;
  local_20 = 8;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer
            (L"Security passthrough command encountered",&GenericWarningEvent,param_3,0x17,local_188
            );
  return;
}



===== RequestEvtCanceledOnQueue @ 14000b760 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void RequestEvtCanceledOnQueue(undefined8 param_1,undefined8 param_2)

{
  longlong lVar1;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_REQUEST_CONTEXT_TYPE_INFO_140016108);
  if (*(char *)(lVar1 + 8) == '\x01') {
    KeSetEvent(lVar1 + 0x10,0,0);
  }
  return;
}



===== Feature_2813562171__private_IsEnabledDeviceUsageNoInline @ 14000b7ac =====

ulonglong Feature_2813562171__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_2813562171__private_featureState;
  if ((Feature_2813562171__private_featureState & 0x10) == 0) {
    uVar1 = Feature_2813562171__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_2813562171__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_2813562171__private_IsEnabledFallback @ 14000b7e4 =====

void Feature_2813562171__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_2813562171__private_descriptor);
  return;
}



===== WPP_SF_dDq @ 14000b800 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dDq(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_94719a13e7d8366cd9a87695c567288d_Traceguids,param_2,local_res20,4,
             &param_5,4,&param_6,8,0);
  return;
}



===== WPP_SF_dq @ 14000b868 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dq(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_94719a13e7d8366cd9a87695c567288d_Traceguids,param_2,local_res20,4,
             &param_5,8,0);
  return;
}



===== wil_details_FeatureReporting_IncrementOpportunityInCache @ 14000b8c0 =====

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



===== wil_details_FeatureReporting_IncrementUsageInCache @ 14000b998 =====

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



===== wil_details_FeatureReporting_RecordUsageInCache @ 14000ba7c =====

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
LAB_14000bbd4:
    wil_details_FeatureReporting_IncrementUsageInCache(param_2,uVar5,param_3,param_1);
  }
  else {
    if (uVar5 == 1) {
LAB_14000bbc7:
      wil_details_FeatureReporting_IncrementOpportunityInCache(param_2,uVar5,param_3,param_1);
      return param_1;
    }
    if ((uVar5 != 2) && (uVar5 != 3)) {
      if (uVar5 == 4) goto LAB_14000bbd4;
      if (uVar5 == 5) goto LAB_14000bbc7;
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



===== wil_details_FeatureReporting_ReportUsageToService @ 14000bbfc =====

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



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 14000bc80 =====

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



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 14000bd70 =====

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



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 14000be80 =====

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



===== wil_details_GetCurrentFeatureEnabledState @ 14000bee4 =====

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



===== wil_details_IsEnabledFallback @ 14000c044 =====

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



===== wil_details_MapReportingKind @ 14000c0d8 =====

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



===== WPP_SF_Z @ 14000c178 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Z(undefined8 param_1,undefined2 param_2,undefined8 param_3,wchar_t *param_4)

{
  wchar_t *pwVar1;
  wchar_t wVar2;
  
  if (param_4 == (wchar_t *)0x0) {
    wVar2 = L'\b';
  }
  else {
    wVar2 = *param_4;
    if (*param_4 != L'\0') {
      pwVar1 = *(wchar_t **)(param_4 + 4);
      goto LAB_14000c1a5;
    }
  }
  pwVar1 = L"NULL";
LAB_14000c1a5:
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"\b";
  }
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,param_4,2,pwVar1,wVar2,0);
  return;
}



===== ChildDeviceCreateIoTarget @ 14000c1f8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int ChildDeviceCreateIoTarget(undefined8 param_1)

{
  int iVar1;
  int iVar2;
  undefined8 *puVar3;
  longlong lVar4;
  undefined8 *puVar5;
  undefined2 uVar6;
  uint uVar7;
  longlong local_res10;
  longlong local_res18;
  longlong local_res20;
  undefined4 local_118;
  undefined4 uStack_114;
  undefined4 uStack_110;
  undefined4 uStack_10c;
  undefined4 local_108;
  undefined4 uStack_104;
  undefined8 uStack_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined *local_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined4 local_c8;
  undefined4 local_c4;
  code *local_c0;
  code *local_b8;
  code *local_b0;
  undefined4 local_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 local_88;
  undefined4 local_7c;
  undefined4 local_78;
  
  iVar1 = 0;
  puVar3 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_CHILD_DEVICE_EXTENSION_TYPE_INFO_1400160b8);
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x108))(WdfDriverGlobals,param_1);
  local_res20 = IoGetAttachedDeviceReference(lVar4);
  if ((puVar3[3] != 0) || (local_res20 == lVar4)) goto LAB_14000c769;
  local_res10 = 0;
  local_e8 = (undefined *)0x0;
  local_108 = 0;
  uStack_104 = 0;
  uStack_114 = 0;
  uStack_110 = 0;
  uStack_10c = 0;
  local_118 = 0x38;
  uStack_f0 = 0;
  uStack_100 = 0x100000001;
  local_f8 = param_1;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x538))
                    (WdfDriverGlobals,param_1,&local_118,&local_res10);
  if (iVar1 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      uVar6 = 0x1e;
LAB_14000c89a:
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,
               &WPP_4d5b31fc5b25398542187f229fa95b66_Traceguids,iVar1);
    }
  }
  else {
    memset(&local_c8,0,0x88);
    local_res18 = 0;
    local_e0 = 0;
    uStack_d8 = 0;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x9a0))(WdfDriverGlobals,0,0,&local_res18);
    if (iVar1 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar6 = 0x1f;
LAB_14000c3f6:
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,
                 &WPP_4d5b31fc5b25398542187f229fa95b66_Traceguids,iVar1);
      }
    }
    else {
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x278))
                        (WdfDriverGlobals,param_1,&GUID_EHSTOR_SILO_INTERFACE,0,local_res18);
      if (iVar1 < 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar6 = 0x20;
          goto LAB_14000c3f6;
        }
      }
      else {
        (**(code **)(WdfFunctions_01015 + 0x9a8))(WdfDriverGlobals,local_res18,&local_e0);
        memset(&local_c8,0,0x88);
        local_c0 = ChildDeviceEvtIoTargetQueryRemove;
        local_b8 = ChildDeviceEvtIoTargetRemoveCanceled;
        local_b0 = ChildDeviceEvtIoTargetRemoveComplete;
        local_c8 = 0x88;
        local_c4 = 2;
        local_98 = (undefined4)local_e0;
        uStack_94 = local_e0._4_4_;
        uStack_90 = (undefined4)uStack_d8;
        uStack_8c = uStack_d8._4_4_;
        local_88 = 0x1f0000;
        local_78 = 0x40;
        local_7c = 1;
        iVar1 = (**(code **)(WdfFunctions_01015 + 0x540))(WdfDriverGlobals,local_res10,&local_c8);
      }
    }
    if (local_res18 != 0) {
      (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
    }
    LogEvent("COpenTgt",*puVar3,(ulonglong)*(uint *)((longlong)puVar3 + 0x7c),(longlong)iVar1);
    if (iVar1 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,
                 &WPP_4d5b31fc5b25398542187f229fa95b66_Traceguids,iVar1);
      }
      (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,local_res10);
      local_res10 = 0;
      if ((iVar1 == -0x3fffffcc) || (iVar1 == -0x3fffffc6)) {
        iVar1 = 0;
        goto LAB_14000c769;
      }
    }
    else {
      local_e8 = (undefined *)0x0;
      local_108 = 0;
      uStack_104 = 0;
      uStack_114 = 0;
      uStack_110 = 0;
      uStack_10c = 0;
      local_118 = 0x38;
      uStack_f0 = 0;
      uStack_100 = 0x100000001;
      local_f8 = param_1;
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x68))(WdfDriverGlobals,&local_118,puVar3 + 7);
      if (((iVar1 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar6 = 0x23;
        goto LAB_14000c89a;
      }
      uVar7 = 0;
      while (-1 < iVar1) {
        if (2 < uVar7) {
          KeInitializeSemaphore(puVar3 + 8,3,3);
          local_e8 = (undefined *)0x0;
          local_108 = 0;
          uStack_104 = 0;
          uStack_100 = 0x100000001;
          uStack_114 = 0;
          uStack_110 = 0;
          uStack_10c = 0;
          local_118 = 0x38;
          uStack_f0 = 0;
          local_f8 = param_1;
          iVar1 = (**(code **)(WdfFunctions_01015 + 0x7b8))
                            (WdfDriverGlobals,&local_118,local_res10,puVar3 + 0xd);
          if (iVar1 < 0) {
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              uVar6 = 0x27;
              goto LAB_14000c89a;
            }
          }
          else {
            iVar1 = (**(code **)(WdfFunctions_01015 + 0x5e8))
                              (WdfDriverGlobals,local_res10,puVar3[0xd],0x2dd448,0,0,0,0);
            if (-1 < iVar1) {
              puVar5 = (undefined8 *)
                       (**(code **)(WdfFunctions_01015 + 0x650))
                                 (WdfDriverGlobals,*puVar3,
                                  PTR__WDF_FILTER_DEVICE_EXTENSION_TYPE_INFO_140016018);
              (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*puVar5);
              iVar2 = *(int *)(puVar5 + 1);
              (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*puVar5);
              puVar3[3] = local_res10;
              if ((((*(uint *)((longlong)puVar3 + 0x84) & 1) != 0) && (iVar2 != 2)) &&
                 (iVar2 = ChildDeviceSendOnDemandAuthenticationRequest(param_1,1), -1 < iVar2)) {
                FilterDeviceSetState(*puVar3,2,2);
              }
              goto LAB_14000c769;
            }
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              uVar6 = 0x28;
              goto LAB_14000c89a;
            }
          }
          break;
        }
        local_res18 = 0;
        uStack_104 = 0;
        uStack_f0 = 0;
        uStack_114 = 0;
        uStack_110 = 0;
        uStack_10c = 0;
        local_108 = 0;
        local_118 = 0x38;
        uStack_100 = 0x100000001;
        local_f8 = param_1;
        local_e8 = PTR__WDF_IOCTL_REDIRECT_REQUEST_CONTEXT_TYPE_INFO_1400160e0;
        iVar1 = (**(code **)(WdfFunctions_01015 + 0x7b8))
                          (WdfDriverGlobals,&local_118,local_res10,&local_res18);
        if (iVar1 < 0) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar6 = 0x24;
LAB_14000c706:
            WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,
                     &WPP_4d5b31fc5b25398542187f229fa95b66_Traceguids,iVar1);
          }
LAB_14000c715:
          if (local_res18 != 0) {
            (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
          }
        }
        else {
          iVar1 = (**(code **)(WdfFunctions_01015 + 0x5d8))
                            (WdfDriverGlobals,local_res10,local_res18,0,0,0,0,0);
          if (iVar1 < 0) {
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              uVar6 = 0x25;
              goto LAB_14000c706;
            }
            goto LAB_14000c715;
          }
          iVar1 = (**(code **)(WdfFunctions_01015 + 0x78))(WdfDriverGlobals,puVar3[7],local_res18);
          if (iVar1 < 0) {
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              uVar6 = 0x26;
              goto LAB_14000c706;
            }
            goto LAB_14000c715;
          }
        }
        uVar7 = uVar7 + 1;
      }
    }
  }
  if (local_res10 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
LAB_14000c769:
  ObfDereferenceObject(local_res20);
  return iVar1;
}



===== ChildDeviceEvtCleanup @ 14000c960 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ChildDeviceEvtCleanup(undefined8 param_1)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_CHILD_DEVICE_EXTENSION_TYPE_INFO_1400160b8);
  LogEvent("CCleanup",*puVar1,(ulonglong)*(uint *)((longlong)puVar1 + 0x7c),0);
  RtlFreeUnicodeString(puVar1 + 0x11);
  return;
}



===== ChildDeviceEvtIoInternalDeviceControl @ 14000c9d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ChildDeviceEvtIoInternalDeviceControl
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               int param_5)

{
  longlong lVar1;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
  if (param_5 == 0x2dd440) {
    IoctlDriverReportCapabilities(lVar1,param_2);
  }
  else if (param_5 == 0x2dd444) {
    IoctlDriverUpdateLbaFilterTable(lVar1,param_2);
  }
  else {
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,0xc00000bb);
  }
  return;
}



===== ChildDeviceEvtIoTargetQueryRemove @ 14000ca50 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 ChildDeviceEvtIoTargetQueryRemove(longlong param_1)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x570))(WdfDriverGlobals,param_1);
  puVar2 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,uVar1,PTR__WDF_CHILD_DEVICE_EXTENSION_TYPE_INFO_1400160b8);
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,puVar2[0xc],0);
  (**(code **)(WdfFunctions_01015 + 0x548))(WdfDriverGlobals,param_1);
  if (((param_1 != puVar2[3]) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
     (WPP_GLOBAL_Control[0x29] != '\0')) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x29,
            &WPP_4d5b31fc5b25398542187f229fa95b66_Traceguids);
  }
  (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,puVar2[0xc]);
  LogEvent("CTgtQRmv",*puVar2,(ulonglong)*(uint *)((longlong)puVar2 + 0x7c),0);
  return 0;
}



===== ChildDeviceEvtIoTargetRemoveCanceled @ 14000cb60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ChildDeviceEvtIoTargetRemoveCanceled(longlong param_1)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  undefined4 local_98;
  undefined4 local_94;
  undefined1 local_90 [136];
  
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x570))(WdfDriverGlobals,param_1);
  puVar3 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,uVar2,PTR__WDF_CHILD_DEVICE_EXTENSION_TYPE_INFO_1400160b8);
  if (puVar3[3] == param_1) {
    memset(local_90,0,0x80);
    local_98 = 0x88;
    local_94 = 3;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x540))(WdfDriverGlobals,param_1,&local_98);
    if (-1 < iVar1) {
      puVar3[3] = param_1;
    }
    LogEvent("CTgtCRmv",*puVar3,(ulonglong)*(uint *)((longlong)puVar3 + 0x7c),(longlong)iVar1);
  }
  else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (WPP_GLOBAL_Control[0x29] != '\0')) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
            &WPP_4d5b31fc5b25398542187f229fa95b66_Traceguids);
  }
  return;
}



===== ChildDeviceEvtIoTargetRemoveComplete @ 14000cc70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ChildDeviceEvtIoTargetRemoveComplete(longlong param_1)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x570))(WdfDriverGlobals,param_1);
  puVar2 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,uVar1,PTR__WDF_CHILD_DEVICE_EXTENSION_TYPE_INFO_1400160b8);
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,puVar2[0xc],0);
  if (param_1 == puVar2[3]) {
    puVar2[3] = 0;
    (**(code **)(WdfFunctions_01015 + 0x550))(WdfDriverGlobals,param_1);
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,param_1);
    LogEvent("CTgtRmvd",*puVar2,(ulonglong)*(uint *)((longlong)puVar2 + 0x7c),0);
  }
  else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (WPP_GLOBAL_Control[0x29] != '\0')) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2a,
            &WPP_4d5b31fc5b25398542187f229fa95b66_Traceguids);
  }
  (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,puVar2[0xc]);
  return;
}



===== ChildDevicePnpNotifyInterfaceChange @ 14000cda0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int ChildDevicePnpNotifyInterfaceChange(longlong param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 *puVar2;
  longlong lVar3;
  
  iVar1 = 0;
  puVar2 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_2,PTR__WDF_CHILD_DEVICE_EXTENSION_TYPE_INFO_1400160b8);
  lVar3 = *(longlong *)(param_1 + 4) + -0x11d046f0cb3a4004;
  if (lVar3 == 0) {
    lVar3 = *(longlong *)(param_1 + 0xc) + -0x3f05139760008fb0;
  }
  if (lVar3 == 0) {
    LogEvent("CIfArriv",*puVar2,(ulonglong)*(uint *)((longlong)puVar2 + 0x7c),0);
    iVar1 = ChildDeviceCreateIoTarget(param_2);
  }
  return iVar1;
}



===== ChildDeviceSendOnDemandAuthenticationRequest @ 14000ce30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int ChildDeviceSendOnDemandAuthenticationRequest(undefined8 param_1,byte param_2)

{
  char cVar1;
  int iVar2;
  undefined8 *puVar3;
  uint *puVar4;
  longlong lVar5;
  undefined1 auStack_88 [32];
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_38;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined8 local_20;
  undefined8 uStack_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_88;
  uStack_28 = 0;
  uStack_24 = 0;
  local_38 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  local_20 = 0;
  uStack_18 = 0;
  puVar3 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_CHILD_DEVICE_EXTENSION_TYPE_INFO_1400160b8);
  LogEvent("SendAuth",*puVar3,(ulonglong)*(uint *)((longlong)puVar3 + 0x7c),(ulonglong)param_2);
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,puVar3[0xc],0);
  if (puVar3[3] == 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2c,
              &WPP_4d5b31fc5b25398542187f229fa95b66_Traceguids);
    }
    iVar2 = -0x3fffff5d;
  }
  else {
    uStack_2c = 0;
    uStack_28 = 0;
    uStack_24 = 0;
    uStack_30 = 0;
    local_38 = 0x18;
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x7c8))(WdfDriverGlobals,puVar3[0xd],&local_38);
    if (-1 < iVar2) {
      puVar4 = (uint *)(**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,puVar3[0xe],0);
      *puVar4 = 0;
      if (param_2 == 0) {
        lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                          (WdfDriverGlobals,*puVar3,
                           PTR__WDF_FILTER_DEVICE_EXTENSION_TYPE_INFO_140016018);
        if (0x4ff < (*(uint *)(lVar5 + 0x134) & 0xf00)) {
          *puVar4 = *puVar4 | 2;
        }
      }
      else {
        *puVar4 = 1;
      }
      local_50 = 0;
      local_68 = puVar3[0xe];
      local_58 = 0;
      local_60 = 0;
      iVar2 = (**(code **)(WdfFunctions_01015 + 0x5e8))
                        (WdfDriverGlobals,puVar3[3],puVar3[0xd],0x2dd448);
      if (-1 < iVar2) {
        local_20 = 0x300000010;
        uStack_18 = 0xffffffffff676980;
        cVar1 = (**(code **)(WdfFunctions_01015 + 0x7e8))
                          (WdfDriverGlobals,puVar3[0xd],puVar3[3],&local_20);
        if (cVar1 == '\0') {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2d,
                     &WPP_4d5b31fc5b25398542187f229fa95b66_Traceguids,iVar2);
          }
          iVar2 = -0x3ffffe7d;
        }
        else {
          iVar2 = (**(code **)(WdfFunctions_01015 + 0x7f0))(WdfDriverGlobals,puVar3[0xd]);
        }
      }
    }
  }
  (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,puVar3[0xc]);
  return iVar2;
}



===== ChildDeviceSendTPerReset1667 @ 14000d0f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int ChildDeviceSendTPerReset1667(undefined8 param_1,undefined8 param_2)

{
  undefined1 uVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined1 *puVar7;
  undefined8 uVar8;
  longlong lVar9;
  undefined1 auStackY_2d8 [32];
  uint local_248 [4];
  undefined4 local_238;
  undefined1 local_234 [3];
  byte local_231;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_2d8;
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FILTER_DEVICE_EXTENSION_TYPE_INFO_140016018);
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_CHILD_DEVICE_EXTENSION_TYPE_INFO_1400160b8);
  uVar6 = *(uint *)(lVar3 + 300) & 2;
  memset(local_234,0,0x1fc);
  local_238 = 8;
  puVar5 = &local_238;
  lVar9 = 2;
  puVar7 = (undefined1 *)((longlong)&local_238 + 3);
  local_248[0] = (-(uint)(uVar6 != 0) & 0xfffffe08) + 0x200;
  do {
    uVar1 = *(undefined1 *)puVar5;
    *(undefined1 *)puVar5 = *puVar7;
    puVar5 = (undefined4 *)((longlong)puVar5 + 1);
    *puVar7 = uVar1;
    puVar7 = puVar7 + -1;
    lVar9 = lVar9 + -1;
  } while (lVar9 != 0);
  if (**(longlong **)(lVar4 + 0x28) != 0) {
    (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,**(longlong **)(lVar4 + 0x28),0);
  }
  uVar8 = 0;
  LogEvent("SendTRst",param_1,(ulonglong)*(uint *)(lVar4 + 0x7c),0);
  iVar2 = IssueSecurityProtocolOut
                    (*(undefined8 *)(lVar3 + 0x198),*(longlong *)(lVar4 + 0x28),uVar6 == 0,uVar8,
                     *(undefined1 *)(lVar4 + 0x80),5,(longlong)&local_238,local_248[0],
                     *(char *)(lVar3 + 0x180),0x800);
  if (-1 < iVar2) {
    uVar8 = 0x200;
    memset(&local_238,0,0x200);
    iVar2 = IssueSecurityProtocolIn
                      (*(undefined8 *)(lVar3 + 0x198),*(longlong *)(lVar4 + 0x28),
                       CONCAT71((int7)((ulonglong)uVar8 >> 8),uVar6 == 0),0xee,
                       *(undefined1 *)(lVar4 + 0x80),5,(longlong)&local_238,local_248,
                       *(char *)(lVar3 + 0x180),0x800);
    if (-1 < iVar2) {
      if (local_248[0] < 8) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2f,
                    &WPP_4d5b31fc5b25398542187f229fa95b66_Traceguids,local_248[0],8);
        }
        if ((Microsoft_Windows_EnhancedStorage_ClassDriverEnableBits & 2) != 0) {
          McTemplateK0quuujzdzxzxzxzx_EtwWriteTransfer();
        }
        iVar2 = -0x3ffffe7a;
      }
      else if (local_231 != 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x30,
                   &WPP_4d5b31fc5b25398542187f229fa95b66_Traceguids,(uint)local_231);
        }
        if ((Microsoft_Windows_EnhancedStorage_ClassDriverEnableBits & 2) != 0) {
          McTemplateK0quuujzdzxzxzxzx_EtwWriteTransfer();
        }
        iVar2 = -0x3fffffff;
      }
      goto LAB_14000d5b3;
    }
  }
  if ((Microsoft_Windows_EnhancedStorage_ClassDriverEnableBits & 2) != 0) {
    McTemplateK0quuujzdzxzxzxzx_EtwWriteTransfer();
  }
LAB_14000d5b3:
  if (**(longlong **)(lVar4 + 0x28) != 0) {
    (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals);
  }
  return iVar2;
}



===== RtlStringCbCatA @ 14000d608 =====

void RtlStringCbCatA(char *param_1,undefined8 param_2,longlong param_3)

{
  int iVar1;
  longlong *plVar2;
  longlong local_res10 [3];
  
  local_res10[0] = 0;
  plVar2 = local_res10;
  iVar1 = RtlStringValidateDestAndLengthA(param_1,param_2,plVar2);
  if (-1 < iVar1) {
    RtlStringCopyWorkerA(param_1 + local_res10[0],0x80 - local_res10[0],plVar2,param_3,0x7ffffffe);
  }
  return;
}



===== RtlStringCbCopyA @ 14000d65c =====

void RtlStringCbCopyA(char *param_1,undefined8 param_2,undefined8 param_3)

{
  RtlStringCopyWorkerA(param_1,0x80,param_3,param_3,0x7ffffffe);
  return;
}



===== RtlStringCbPrintfA @ 14000d684 =====

undefined8 RtlStringCbPrintfA(char *param_1,longlong param_2,char *param_3,undefined8 param_4)

{
  size_t _Count;
  int iVar1;
  undefined8 uVar2;
  undefined8 local_res20;
  
  if (param_2 - 1U < 0x7fffffff) {
    _Count = param_2 - 1;
    uVar2 = 0;
    local_res20 = param_4;
    iVar1 = _vsnprintf(param_1,_Count,param_3,(va_list)&local_res20);
    if ((iVar1 < 0) || (_Count < (ulonglong)(longlong)iVar1)) {
      param_1[_Count] = '\0';
      uVar2 = 0x80000005;
    }
    else if ((longlong)iVar1 == _Count) {
      param_1[_Count] = '\0';
    }
  }
  else {
    uVar2 = 0xc000000d;
    if (param_2 != 0) {
      *param_1 = '\0';
    }
  }
  return uVar2;
}



===== RtlStringCchPrintfExW @ 14000d6f4 =====

ulonglong RtlStringCchPrintfExW
                    (wchar_t *param_1,ulonglong param_2,longlong *param_3,ulonglong *param_4,
                    uint param_5,wchar_t *param_6,char param_7)

{
  int iVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  size_t _Count;
  ulonglong *puVar4;
  wchar_t *pwVar5;
  wchar_t *local_58;
  ulonglong local_50 [2];
  
  puVar4 = param_4;
  uVar2 = RtlStringExValidateDestW((longlong)param_1,param_2,param_3,param_5);
  if ((int)uVar2 < 0) {
    if (param_2 == 0) {
      return uVar2 & 0xffffffff;
    }
    *param_1 = L'\0';
    return uVar2 & 0xffffffff;
  }
  if (((param_5 >> 8 & 1) != 0) && (param_6 == (wchar_t *)0x0)) {
    param_6 = L"";
  }
  uVar2 = 0;
  if ((param_5 & 0xffffe000) == 0) {
    if (param_2 == 0) {
      if (*param_6 == L'\0') goto LAB_14000d7c3;
      uVar2 = (ulonglong)((-(uint)(param_1 != (wchar_t *)0x0) & 0xbffffff8) + 0xc000000d);
      local_58 = param_1;
      local_50[0] = param_2;
      goto LAB_14000d773;
    }
    local_50[0] = 0;
    _Count = param_2 - 1;
    local_58 = param_1;
    iVar1 = _vsnwprintf(param_1,_Count,param_6,&param_7);
    if (iVar1 < 0) {
LAB_14000d830:
      uVar2 = 0x80000005;
LAB_14000d835:
      param_1[_Count] = L'\0';
    }
    else {
      uVar3 = (ulonglong)iVar1;
      if (_Count < uVar3) goto LAB_14000d830;
      if (uVar3 == _Count) goto LAB_14000d835;
      _Count = uVar3;
    }
    uVar3 = param_2 - _Count;
    pwVar5 = param_1 + _Count;
    local_58 = pwVar5;
    local_50[0] = uVar3;
    if ((int)uVar2 < 0) goto LAB_14000d773;
    if ((((param_5 >> 9 & 1) != 0) && (1 < uVar3)) && (2 < uVar3 * 2)) {
      memset(pwVar5 + 1,param_5 & 0xff,uVar3 * 2 - 2);
    }
  }
  else {
    uVar2 = 0xc000000d;
    local_58 = param_1;
    local_50[0] = param_2;
    if (param_2 != 0) {
      *param_1 = L'\0';
      local_58 = param_1;
      local_50[0] = param_2;
    }
LAB_14000d773:
    pwVar5 = local_58;
    uVar3 = local_50[0];
    if (((param_5 & 0x1c00) != 0) && (param_2 != 0)) {
      RtlStringExHandleOtherFlagsW(param_1,param_2 * 2,param_6,&local_58,local_50,param_5);
      pwVar5 = local_58;
      uVar3 = local_50[0];
    }
    if ((((int)uVar2 + 0x80000000U & 0x80000000) == 0) && ((int)uVar2 != -0x7ffffffb)) {
      return uVar2;
    }
  }
  puVar4 = param_4;
  param_1 = pwVar5;
  param_2 = uVar3;
LAB_14000d7c3:
  if (param_3 != (longlong *)0x0) {
    *param_3 = (longlong)param_1;
  }
  if (puVar4 != (ulonglong *)0x0) {
    *puVar4 = param_2;
  }
  return uVar2;
}



===== WPP_SF_sd @ 14000d8ac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_sd(undefined8 param_1,undefined2 param_2,undefined8 param_3,char *param_4,
              undefined1 param_5)

{
  longlong lVar1;
  longlong lVar2;
  
  if (param_4 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar2 = lVar1;
      lVar1 = lVar2 + 1;
    } while (param_4[lVar1] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (param_4 == (char *)0x0) {
    param_4 = "NULL";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_4d5b31fc5b25398542187f229fa95b66_Traceguids,param_2,param_4,lVar2,
             &param_5,4,0);
  return;
}



===== _guard_check_icall @ 14000d930 =====

void _guard_check_icall(void)

{
  return;
}



===== CompareLbaFilterTableEntries @ 14000d940 =====

ulonglong CompareLbaFilterTableEntries(ulonglong *param_1,ulonglong *param_2)

{
  if (*param_1 < *param_2) {
    return 0xffffffff;
  }
  return (ulonglong)(*param_2 < *param_1);
}



===== IoctlDeviceGetQueueState @ 14000d960 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int IoctlDeviceGetQueueState(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 *puVar2;
  longlong lVar3;
  undefined1 *local_res18 [2];
  
  local_res18[0] = (undefined1 *)0x0;
  puVar2 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_CHILD_DEVICE_EXTENSION_TYPE_INFO_1400160b8);
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,*puVar2,PTR__WDF_FILTER_DEVICE_EXTENSION_TYPE_INFO_140016018);
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,param_2,1,local_res18,0);
  if (iVar1 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
               &WPP_6b540f47682e3482637f60efce621d01_Traceguids,iVar1);
    }
  }
  else {
    *local_res18[0] = *(undefined1 *)(lVar3 + 0xc);
    (**(code **)(WdfFunctions_01015 + 0x898))(WdfDriverGlobals,param_2,1);
  }
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar1);
  LogEvent("GetQStat",(longlong)*(int *)(lVar3 + 8),(ulonglong)*(byte *)(lVar3 + 0xc),
           (longlong)iVar1);
  return iVar1;
}



===== IoctlDeviceSetAuthzState @ 14000daac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int IoctlDeviceSetAuthzState(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  int iVar2;
  undefined8 *puVar3;
  longlong lVar4;
  undefined1 auStack_88 [32];
  longlong local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  longlong local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_88;
  local_58 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  uStack_38 = 0;
  local_30 = 0;
  puVar3 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_CHILD_DEVICE_EXTENSION_TYPE_INFO_1400160b8);
  uVar1 = *puVar3;
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar1,PTR__WDF_FILTER_DEVICE_EXTENSION_TYPE_INFO_140016018);
  if (*(int *)(puVar3 + 6) == 3) {
    local_50 = CONCAT62(local_50._2_6_,0x28);
    (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_50);
    if (local_40 == 2) {
      iVar2 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_2,2,&local_58);
      if (iVar2 < 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
                   &WPP_6b540f47682e3482637f60efce621d01_Traceguids,iVar2);
        }
      }
      else {
        FilterDeviceSetState
                  (uVar1,(*(char *)(local_58 + 1) != '\0') + 1,
                   ~-(uint)(*(char *)(local_58 + 1) != '\0') & 2);
        if (*(char *)(lVar4 + 0xc) != '\x01') {
          iVar2 = ChildDeviceSchedulePartitionRediscovery(param_1);
        }
      }
    }
    else {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_Pd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
                  &WPP_6b540f47682e3482637f60efce621d01_Traceguids,local_40,2);
      }
      iVar2 = -0x3ffffdfa;
    }
  }
  else {
    iVar2 = -0x3fffff45;
  }
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar2);
  LogEvent("SetAuthz",(longlong)*(int *)(lVar4 + 8),(ulonglong)*(byte *)(lVar4 + 0xc),
           (longlong)iVar2);
  return iVar2;
}



===== IoctlDeviceSetQueueState @ 14000dcc4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int IoctlDeviceSetQueueState(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  int iVar2;
  undefined8 *puVar3;
  longlong lVar4;
  undefined1 auStack_88 [32];
  char *local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  longlong local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_88;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  uStack_38 = 0;
  local_30 = 0;
  local_58 = (char *)0x0;
  puVar3 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_CHILD_DEVICE_EXTENSION_TYPE_INFO_1400160b8);
  uVar1 = *puVar3;
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar1,PTR__WDF_FILTER_DEVICE_EXTENSION_TYPE_INFO_140016018);
  if (*(int *)(puVar3 + 6) == 3) {
    local_50 = CONCAT62(local_50._2_6_,0x28);
    (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_50);
    if (local_40 == 1) {
      iVar2 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_2,1,&local_58);
      if (iVar2 < 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
                   &WPP_6b540f47682e3482637f60efce621d01_Traceguids,iVar2);
        }
      }
      else {
        FilterDeviceSetState(uVar1,-1,(uint)(*local_58 != '\0'));
      }
    }
    else {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_Pd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
                  &WPP_6b540f47682e3482637f60efce621d01_Traceguids,local_40,1);
      }
      iVar2 = -0x3ffffdfa;
    }
  }
  else {
    iVar2 = -0x3fffff45;
  }
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar2);
  LogEvent("SetQStat",(longlong)*(int *)(lVar4 + 8),(ulonglong)*(byte *)(lVar4 + 0xc),
           (longlong)iVar2);
  return iVar2;
}



===== IoctlDriverReportCapabilities @ 14000deb8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int IoctlDriverReportCapabilities(longlong param_1,undefined8 param_2)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  int iVar4;
  int iVar5;
  undefined8 *puVar6;
  longlong lVar7;
  uint *puVar8;
  longlong lVar9;
  void *_Dst;
  longlong lVar10;
  uint uVar11;
  longlong *plVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  uint uVar18;
  undefined8 local_58;
  ulonglong local_50 [2];
  
  local_58 = 0;
  local_50[0] = 0;
  LogEvent("RepCaps",0,0,0);
  puVar6 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_CHILD_DEVICE_EXTENSION_TYPE_INFO_1400160b8);
  uVar2 = *puVar6;
  lVar7 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar2,PTR__WDF_FILTER_DEVICE_EXTENSION_TYPE_INFO_140016018);
  if (*(int *)(puVar6 + 6) != 3) {
    iVar5 = -0x3fffff45;
    goto LAB_14000e44a;
  }
  iVar5 = (**(code **)(WdfFunctions_01015 + 0x858))(WdfDriverGlobals,param_2,&local_58);
  if (iVar5 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,
               &WPP_6b540f47682e3482637f60efce621d01_Traceguids,iVar5);
    }
    goto LAB_14000e44a;
  }
  puVar8 = (uint *)(**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,local_58,local_50);
  if (local_50[0] < 0x14) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_Pd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,
                &WPP_6b540f47682e3482637f60efce621d01_Traceguids,local_50[0],0x14);
    }
    iVar5 = -0x3ffffdfa;
    goto LAB_14000e44a;
  }
  uVar18 = puVar8[3];
  if (uVar18 == 0) {
    if (*puVar8 < 0x14) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,
                 &WPP_6b540f47682e3482637f60efce621d01_Traceguids,*puVar8);
      }
      iVar5 = -0x3ffffff3;
      goto LAB_14000e44a;
    }
  }
  else {
    uVar14 = (ulonglong)puVar8[4] + (ulonglong)uVar18 * 4;
    if ((0xffffffff < uVar14) || (local_50[0] < (uVar14 & 0xffffffff))) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_Pd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,
                  &WPP_6b540f47682e3482637f60efce621d01_Traceguids,local_50[0],(char)uVar18);
      }
      iVar5 = -0x3ffffdfa;
    }
    if (iVar5 < 0) goto LAB_14000e44a;
  }
  if ((puVar8[1] & 2) == 0) {
    if (puVar8[2] != 0) {
      iVar5 = -0x3ffffff3;
      goto LAB_14000e44a;
    }
  }
  else {
    if (puVar8[2] == 0) {
      iVar5 = -0x3ffffff3;
    }
    if (iVar5 < 0) goto LAB_14000e44a;
  }
  *(uint *)((longlong)puVar6 + 0x84) = puVar8[1];
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,*(undefined8 *)(lVar7 + 0x1d8),0);
  iVar17 = 0;
  if ((*(longlong *)(lVar7 + 0x1c8) != 0) && (*(uint *)(lVar7 + 0x1d0) != 0)) {
    plVar12 = (longlong *)(*(longlong *)(lVar7 + 0x1c8) + 8);
    uVar14 = (ulonglong)*(uint *)(lVar7 + 0x1d0);
    do {
      lVar9 = *plVar12;
      plVar12 = plVar12 + 2;
      iVar4 = iVar17 + 1;
      if (lVar9 == param_1) {
        iVar4 = iVar17;
      }
      iVar17 = iVar4;
      uVar14 = uVar14 - 1;
    } while (uVar14 != 0);
  }
  uVar18 = iVar17 + puVar8[3];
  if (uVar18 == 0) {
    lVar9 = 0;
LAB_14000e2dc:
    (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(lVar7 + 0x1e0));
    lVar10 = *(longlong *)(lVar7 + 0x1c8);
    *(longlong *)(lVar7 + 0x1c8) = lVar9;
    lVar9 = 0;
    *(uint *)(lVar7 + 0x1d0) = uVar18;
    (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(lVar7 + 0x1e0));
    if (lVar10 != 0) {
      ExFreePoolWithTag(lVar10,0);
    }
  }
  else {
    lVar9 = ExAllocatePool2(0x40,(ulonglong)uVar18 << 4,0x47536353);
    if (lVar9 != 0) {
      lVar10 = *(longlong *)(lVar7 + 0x1c8);
      uVar15 = 0;
      if ((lVar10 != 0) && (uVar11 = 0, *(int *)(lVar7 + 0x1d0) != 0)) {
        do {
          if (uVar18 <= uVar15) break;
          if (*(longlong *)(lVar10 + 8 + (ulonglong)uVar11 * 0x10) != param_1) {
            puVar6 = (undefined8 *)(lVar10 + (ulonglong)uVar11 * 0x10);
            uVar3 = puVar6[1];
            uVar14 = (ulonglong)uVar15;
            uVar15 = uVar15 + 1;
            puVar1 = (undefined8 *)(lVar9 + uVar14 * 0x10);
            *puVar1 = *puVar6;
            puVar1[1] = uVar3;
            lVar10 = *(longlong *)(lVar7 + 0x1c8);
          }
          uVar11 = uVar11 + 1;
        } while (uVar11 < *(uint *)(lVar7 + 0x1d0));
      }
      uVar11 = puVar8[4];
      uVar14 = 0;
      if (puVar8[3] != 0) {
        do {
          if (uVar18 <= uVar15) break;
          lVar10 = uVar14 * 4;
          uVar16 = (int)uVar14 + 1;
          uVar14 = (ulonglong)uVar16;
          uVar13 = (ulonglong)uVar15;
          uVar15 = uVar15 + 1;
          *(undefined4 *)(lVar9 + uVar13 * 0x10) =
               *(undefined4 *)((longlong)puVar8 + lVar10 + (ulonglong)uVar11);
          *(longlong *)(lVar9 + 8 + uVar13 * 0x10) = param_1;
        } while (uVar16 < puVar8[3]);
      }
      ShellSort(lVar9,uVar18,0x10,CompareRedirectionTableEntries,SwapRedirectionTableEntries);
      for (uVar15 = 1; uVar15 < uVar18; uVar15 = uVar15 + 1) {
        if (*(int *)(lVar9 + (ulonglong)(uVar15 - 1) * 0x10) ==
            *(int *)(lVar9 + (ulonglong)uVar15 * 0x10)) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x24,
                    &WPP_6b540f47682e3482637f60efce621d01_Traceguids);
          }
          iVar5 = -0x3ffffff3;
          goto LAB_14000e34b;
        }
      }
      goto LAB_14000e2dc;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,
              &WPP_6b540f47682e3482637f60efce621d01_Traceguids);
    }
    iVar5 = -0x3fffff66;
  }
LAB_14000e34b:
  (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,*(undefined8 *)(lVar7 + 0x1d8));
  if (lVar9 != 0) {
    ExFreePoolWithTag(lVar9,0);
  }
  if (-1 < iVar5) {
    (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,*(undefined8 *)(lVar7 + 0x1f8),0);
    uVar18 = puVar8[2];
    if (*(uint *)(lVar7 + 500) < uVar18) {
      _Dst = (void *)ExAllocatePool2(0x40,(ulonglong)uVar18 * 0x18,0x47536353);
      if (_Dst == (void *)0x0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x25,
                  &WPP_6b540f47682e3482637f60efce621d01_Traceguids);
        }
        iVar5 = -0x3fffff66;
      }
      else {
        memmove(_Dst,*(void **)(lVar7 + 0x1e8),(ulonglong)*(uint *)(lVar7 + 0x1f0) * 0x18);
        (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(lVar7 + 0x200));
        lVar9 = *(longlong *)(lVar7 + 0x1e8);
        *(void **)(lVar7 + 0x1e8) = _Dst;
        *(uint *)(lVar7 + 500) = puVar8[2];
        (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(lVar7 + 0x200));
        if (lVar9 != 0) {
          ExFreePoolWithTag(lVar9,0);
        }
      }
    }
    else if ((uVar18 == 0) && (*(uint *)(lVar7 + 500) != 0)) {
      (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(lVar7 + 0x200));
      if (*(longlong *)(lVar7 + 0x1e8) != 0) {
        ExFreePoolWithTag(*(longlong *)(lVar7 + 0x1e8),0);
        *(undefined8 *)(lVar7 + 0x1e8) = 0;
      }
      *(undefined4 *)(lVar7 + 0x1f0) = 0;
      *(undefined4 *)(lVar7 + 500) = 0;
      (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(lVar7 + 0x200));
      FilterDeviceSetState(uVar2,1,2);
    }
    (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,*(undefined8 *)(lVar7 + 0x1f8));
    if (-1 < iVar5) {
      FilterDeviceRecalcAggregatedSiloCaps(uVar2);
    }
  }
LAB_14000e44a:
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar5);
  return iVar5;
}



===== IoctlDriverUpdateLbaFilterTable @ 14000e5c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int IoctlDriverUpdateLbaFilterTable(undefined8 param_1,undefined8 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  longlong lVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  bool bVar7;
  int iVar8;
  undefined8 *puVar9;
  longlong lVar10;
  longlong lVar11;
  ulonglong uVar12;
  undefined2 uVar13;
  uint uVar14;
  ulonglong *puVar15;
  uint *puVar16;
  uint uVar17;
  uint uVar18;
  longlong lVar19;
  undefined8 local_res20;
  ulonglong local_48;
  undefined8 local_40;
  
  local_res20 = 0;
  local_48 = 0;
  LogEvent("UpdLba",0,0,0);
  puVar9 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_CHILD_DEVICE_EXTENSION_TYPE_INFO_1400160b8);
  local_40 = *puVar9;
  lVar10 = (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,local_40,PTR__WDF_FILTER_DEVICE_EXTENSION_TYPE_INFO_140016018
                     );
  if ((*(int *)(puVar9 + 6) != 3) || ((*(uint *)((longlong)puVar9 + 0x84) & 2) == 0)) {
    iVar8 = -0x3fffff45;
    goto LAB_14000eab8;
  }
  iVar8 = (**(code **)(WdfFunctions_01015 + 0x858))(WdfDriverGlobals,param_2,&local_res20);
  if (iVar8 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x26,
               &WPP_6b540f47682e3482637f60efce621d01_Traceguids,iVar8);
    }
LAB_14000e808:
    puVar16 = (uint *)0x0;
    bVar7 = false;
    if (iVar8 < 0) goto LAB_14000eab8;
  }
  else {
    puVar16 = (uint *)(**(code **)(WdfFunctions_01015 + 0x610))
                                (WdfDriverGlobals,local_res20,&local_48);
    if (local_48 < 0x20) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_Pd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x27,
                  &WPP_6b540f47682e3482637f60efce621d01_Traceguids,local_48,0x20);
      }
LAB_14000e803:
      iVar8 = -0x3ffffdfa;
      goto LAB_14000e808;
    }
    uVar17 = *puVar16;
    if (uVar17 < 0x20) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar13 = 0x28;
LAB_14000e76d:
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar13,
                 &WPP_6b540f47682e3482637f60efce621d01_Traceguids,uVar17);
      }
LAB_14000e77d:
      iVar8 = -0x3ffffff3;
      goto LAB_14000e808;
    }
    uVar17 = puVar16[6];
    if (uVar17 < 0x18) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar13 = 0x29;
        goto LAB_14000e76d;
      }
      goto LAB_14000e77d;
    }
    uVar14 = puVar16[5];
    if (uVar14 != 0) {
      uVar12 = (ulonglong)uVar14 * (ulonglong)uVar17 + (ulonglong)puVar16[7];
      if ((0xffffffff < uVar12) || (local_48 < (uVar12 & 0xffffffff))) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_Pddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(ulonglong)uVar14,(ulonglong)uVar17
                      ,local_48,(char)puVar16[7],(char)uVar14,(char)uVar17);
        }
        goto LAB_14000e803;
      }
    }
    if (((char)puVar16[1] == '\0') || (bVar7 = false, (char)puVar16[3] == '\0')) {
      bVar7 = true;
    }
    if (uVar14 != 0) {
      ShellSort((ulonglong)puVar16[7] + (longlong)puVar16,uVar14,0x18,CompareLbaFilterTableEntries,
                SwapLbaFilterTableEntries);
      for (uVar17 = 0; uVar17 < puVar16[5]; uVar17 = uVar17 + 1) {
        puVar15 = (ulonglong *)
                  ((ulonglong)(puVar16[6] * uVar17) + (ulonglong)puVar16[7] + (longlong)puVar16);
        uVar12 = puVar15[1];
        if ((~*puVar15 < uVar12) ||
           ((uVar17 < puVar16[5] - 1 &&
            (*(ulonglong *)
              ((ulonglong)(puVar16[6] * (uVar17 + 1)) + (ulonglong)puVar16[7] + (longlong)puVar16) <
             uVar12 + *puVar15)))) {
          iVar8 = -0x3ffffff3;
          goto LAB_14000eab8;
        }
        if ((bVar7) ||
           ((uVar12 != 0 &&
            (((char)puVar15[2] == '\0' || (*(char *)((longlong)puVar15 + 0x11) == '\0')))))) {
          bVar7 = true;
        }
        else {
          bVar7 = false;
        }
      }
    }
  }
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,*(undefined8 *)(lVar10 + 0x1f8),0);
  if (*(uint *)(lVar10 + 500) < puVar16[5]) {
    lVar11 = ExAllocatePool2(0x40,(ulonglong)puVar16[5] * 0x18,0x47536353);
    if (lVar11 == 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
                &WPP_6b540f47682e3482637f60efce621d01_Traceguids);
      }
      iVar8 = -0x3fffff66;
    }
    if (-1 < iVar8) goto LAB_14000e971;
  }
  else {
    lVar11 = *(longlong *)(lVar10 + 0x1e8);
LAB_14000e971:
    (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(lVar10 + 0x200));
    uVar12 = 0;
    if (puVar16[5] != 0) {
      do {
        uVar17 = puVar16[7];
        uVar14 = (int)uVar12 * puVar16[6];
        uVar18 = (int)uVar12 + 1;
        puVar1 = (undefined4 *)((longlong)puVar16 + (ulonglong)uVar17 + (ulonglong)uVar14);
        uVar4 = puVar1[1];
        uVar5 = puVar1[2];
        uVar6 = puVar1[3];
        puVar2 = (undefined4 *)(lVar11 + uVar12 * 0x18);
        *puVar2 = *puVar1;
        puVar2[1] = uVar4;
        puVar2[2] = uVar5;
        puVar2[3] = uVar6;
        *(undefined8 *)(lVar11 + 0x10 + uVar12 * 0x18) =
             *(undefined8 *)((longlong)puVar16 + (ulonglong)uVar17 + 0x10 + (ulonglong)uVar14);
        uVar12 = (ulonglong)uVar18;
      } while (uVar18 < puVar16[5]);
    }
    lVar3 = *(longlong *)(lVar10 + 0x1e8);
    lVar19 = 0;
    if (lVar3 != lVar11) {
      *(longlong *)(lVar10 + 0x1e8) = lVar11;
      *(uint *)(lVar10 + 500) = puVar16[5];
      lVar19 = lVar3;
    }
    *(uint *)(lVar10 + 0x1f0) = puVar16[5];
    uVar17 = *(uint *)(lVar10 + 0x130) | 1;
    if ((char)puVar16[1] == '\0') {
      uVar17 = *(uint *)(lVar10 + 0x130) & 0xfffffffe;
    }
    *(uint *)(lVar10 + 0x130) = uVar17;
    uVar14 = uVar17 | 2;
    if ((char)puVar16[3] == '\0') {
      uVar14 = uVar17 & 0xfffffffd;
    }
    *(uint *)(lVar10 + 0x130) = uVar14;
    (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(lVar10 + 0x200));
    if (lVar19 != 0) {
      ExFreePoolWithTag(lVar19,0);
    }
  }
  (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,*(undefined8 *)(lVar10 + 0x1f8));
  if (-1 < iVar8) {
    FilterDeviceSetState(local_40,bVar7 + 1,2);
    iVar8 = ChildDeviceSchedulePartitionRediscovery(param_1);
  }
LAB_14000eab8:
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar8);
  return iVar8;
}



===== IoctlRedirectionRemoveTargetDevice @ 14000eafc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void IoctlRedirectionRemoveTargetDevice(longlong param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined8 *puVar7;
  longlong lVar8;
  longlong lVar9;
  uint uVar10;
  uint uVar11;
  
  puVar7 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_CHILD_DEVICE_EXTENSION_TYPE_INFO_1400160b8);
  lVar8 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,*puVar7,PTR__WDF_FILTER_DEVICE_EXTENSION_TYPE_INFO_140016018);
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals);
  lVar9 = *(longlong *)(lVar8 + 0x1c8);
  uVar10 = 0;
  if (lVar9 != 0) {
    uVar6 = *(uint *)(lVar8 + 0x1d0);
    uVar11 = 0;
    if (uVar6 != 0) {
      do {
        if (*(longlong *)(lVar9 + 8 + (ulonglong)uVar11 * 0x10) != param_1) {
          if (uVar10 < uVar11) {
            puVar1 = (undefined4 *)(lVar9 + (ulonglong)uVar11 * 0x10);
            uVar3 = puVar1[1];
            uVar4 = puVar1[2];
            uVar5 = puVar1[3];
            puVar2 = (undefined4 *)(lVar9 + (ulonglong)uVar10 * 0x10);
            *puVar2 = *puVar1;
            puVar2[1] = uVar3;
            puVar2[2] = uVar4;
            puVar2[3] = uVar5;
            lVar9 = *(longlong *)(lVar8 + 0x1c8);
            uVar6 = *(uint *)(lVar8 + 0x1d0);
          }
          uVar10 = uVar10 + 1;
        }
        uVar11 = uVar11 + 1;
      } while (uVar11 < uVar6);
    }
    *(uint *)(lVar8 + 0x1d0) = uVar10;
  }
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(lVar8 + 0x1e0));
  return;
}



===== SwapLbaFilterTableEntries @ 14000ec10 =====

void SwapLbaFilterTableEntries(undefined8 *param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  uVar2 = param_2[1];
  uVar3 = *param_1;
  uVar4 = param_1[1];
  uVar1 = param_1[2];
  *param_1 = *param_2;
  param_1[1] = uVar2;
  param_1[2] = param_2[2];
  *param_2 = uVar3;
  param_2[1] = uVar4;
  param_2[2] = uVar1;
  return;
}



===== WPP_SF_Pddd @ 14000ec38 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Pddd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_6b540f47682e3482637f60efce621d01_Traceguids,0x2a,&local_res20,8,
             &param_5,4,&param_6,4,&param_7,4,0);
  return;
}



===== WPP_SF_dP @ 14000ecac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dP(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_6b540f47682e3482637f60efce621d01_Traceguids,0x15,local_res20,4,
             &param_5,8,0);
  return;
}



===== WPP_SF_qP @ 14000ed08 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qP(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_6b540f47682e3482637f60efce621d01_Traceguids,0x13,&local_res20,8,
             &param_5,8,0);
  return;
}



===== IssueSecurityProtocolOutTCG @ 14000ed60 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int IssueSecurityProtocolOutTCG
              (undefined8 param_1,longlong param_2,byte param_3,ushort param_4,longlong param_5,
              uint param_6,char param_7,uint param_8)

{
  int iVar1;
  byte bStackX_21;
  undefined1 auStackY_98 [32];
  uint in_stack_ffffffffffffff88;
  undefined4 in_stack_ffffffffffffff8c;
  undefined4 in_stack_ffffffffffffffa4;
  undefined1 local_48 [3];
  undefined1 auStack_45 [4];
  byte bStack_41;
  undefined8 uStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_98;
  if ((param_6 & 0x1ff) == 0) {
    bStackX_21 = (byte)(param_4 >> 8);
    local_48 = (undefined1  [3])((uint3)bStackX_21 << 0x10);
    _local_48 = CONCAT53(0x8000,local_48);
    uStack_40 = (ulonglong)CONCAT11((char)(param_6 >> 9),(char)((param_6 >> 9) >> 8));
    local_48._0_2_ = CONCAT11(param_3,0xb5);
    _local_48 = CONCAT44(0x80,CONCAT13((char)param_4,local_48));
    _local_48 = CONCAT17((byte)(param_6 >> 0x19),_local_48);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      in_stack_ffffffffffffff88 = (uint)param_4;
      WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
                &WPP_66125b4cf8143944cb9284854ee08e62_Traceguids,(uint)param_3,(char)param_4);
    }
    iVar1 = IssueSyncScsiCommand
                      (param_1,param_2,'\0',local_48,
                       CONCAT44(in_stack_ffffffffffffff8c,
                                CONCAT31((int3)(in_stack_ffffffffffffff88 >> 8),0xc)),param_5,
                       &param_6,CONCAT44(in_stack_ffffffffffffffa4,0x14),param_7,param_8);
    if (((iVar1 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
               &WPP_66125b4cf8143944cb9284854ee08e62_Traceguids,iVar1);
    }
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
               &WPP_66125b4cf8143944cb9284854ee08e62_Traceguids,param_6);
    }
    iVar1 = -0x3ffffdfa;
  }
  return iVar1;
}



===== StorageQueryPropertyCompletionRoutine @ 14000eee0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void StorageQueryPropertyCompletionRoutine
               (undefined8 param_1,undefined8 param_2,longlong param_3,longlong param_4)

{
  int iVar1;
  undefined4 uVar2;
  longlong local_res18 [2];
  
  local_res18[0] = 0;
  if (-1 < *(int *)(param_3 + 8)) {
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,param_1,0x20,local_res18,0);
    if (-1 < iVar1) {
      if (*(int *)(local_res18[0] + 4) == 0x20) {
        *(undefined1 *)(param_4 + 0x180) = *(undefined1 *)(local_res18[0] + 0x1e);
      }
      *(uint *)(param_4 + 0x130) = *(uint *)(param_4 + 0x130) | 0x20;
    }
  }
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x7f0))(WdfDriverGlobals,param_1);
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_1,uVar2);
  return;
}



===== WPP_SF_DDDDD @ 14000ef9c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DDDDD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                 undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_66125b4cf8143944cb9284854ee08e62_Traceguids,0xd,local_res20,4,
             &param_5,4,&param_6,4,&param_7,4,&param_8,4,0);
  return;
}



===== WPP_SF_DdD @ 14000f01c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DdD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_66125b4cf8143944cb9284854ee08e62_Traceguids,param_2,local_res20,4,
             &param_5,4,&param_6,4,0);
  return;
}



===== ShellSort @ 14000f080 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
ShellSort(longlong param_1,uint param_2,int param_3,undefined *param_4,undefined *param_5)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  int iVar3;
  undefined8 uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  longlong lVar10;
  longlong lVar11;
  
  uVar9 = ((ulonglong)param_2 * 10 >> 1) + 5;
  auVar1._8_8_ = 0;
  auVar1._0_8_ = uVar9;
  uVar4 = SUB168(ZEXT816(0xcccccccccccccccd) * auVar1,0);
  uVar9 = uVar9 / 10;
  iVar5 = (int)uVar9;
  do {
    if (iVar5 == 0) {
      return uVar4;
    }
    uVar6 = (uint)uVar9;
    uVar8 = uVar9 & 0xffffffff;
    uVar7 = uVar6;
    while (uVar7 < param_2) {
      iVar5 = (int)uVar8;
      do {
        iVar3 = (int)uVar8;
        uVar7 = iVar3 - uVar6;
        uVar8 = (ulonglong)uVar7;
        lVar10 = (ulonglong)(uint)(iVar3 * param_3) + param_1;
        lVar11 = (ulonglong)(uVar7 * param_3) + param_1;
        iVar3 = (*(code *)param_4)(lVar11,lVar10);
        if (iVar3 < 1) break;
        (*(code *)param_5)(lVar11,lVar10);
      } while (uVar6 <= uVar7);
      uVar7 = iVar5 + 1;
      uVar8 = (ulonglong)uVar7;
    }
    uVar9 = ((uVar9 & 0xffffffff) * 0x32) / 0xb + 5;
    auVar2._8_8_ = 0;
    auVar2._0_8_ = uVar9;
    uVar4 = SUB168(ZEXT816(0xcccccccccccccccd) * auVar2,0);
    uVar9 = uVar9 / 10;
    iVar5 = (int)uVar9;
    uVar9 = uVar9 & 0xffffffff;
  } while( true );
}



===== FilterDeviceKsrRestoreDeviceContext @ 14000f180 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 FilterDeviceKsrRestoreDeviceContext(undefined8 param_1)

{
  ulonglong uVar1;
  longlong lVar2;
  int iVar3;
  longlong lVar4;
  void *_Dst;
  undefined8 uVar5;
  undefined4 *puVar6;
  undefined1 uVar7;
  ulonglong uVar8;
  
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FILTER_DEVICE_EXTENSION_TYPE_INFO_140016018);
  lVar2 = KsrCachedContext;
  if (lVar4 == 0) {
    uVar5 = 0xc00000bb;
  }
  else {
    if (KsrCachedContext != 0) {
      uVar1 = *(ulonglong *)(KsrCachedContext + 0x10);
      puVar6 = (undefined4 *)(*(longlong *)(KsrCachedContext + 0x20) + KsrCachedContext);
      uVar7 = 1;
      for (uVar8 = 0; uVar8 < uVar1; uVar8 = uVar8 + 1) {
        iVar3 = memcmp(puVar6 + 4,*(void **)(lVar4 + 0x228),*(size_t *)(lVar4 + 0x230));
        if (iVar3 == 0) {
          *(undefined4 *)(lVar4 + 8) = *puVar6;
          _Dst = (void *)ExAllocatePool2(0x40,puVar6[1],0x47536353);
          *(void **)(lVar4 + 0x218) = _Dst;
          if (_Dst == (void *)0x0) {
            uVar5 = 0xc000009a;
            goto LAB_14000f270;
          }
          memmove(_Dst,(void *)(*(longlong *)(puVar6 + 2) + (longlong)puVar6),
                  (ulonglong)(uint)puVar6[1]);
          uVar5 = 0;
          *(undefined4 *)(lVar4 + 0x220) = puVar6[1];
          goto LAB_14000f29c;
        }
        puVar6 = (undefined4 *)((longlong)puVar6 + *(longlong *)(lVar2 + 0x18));
      }
    }
    uVar5 = 0xc00000c0;
  }
LAB_14000f270:
  if (*(longlong *)(lVar4 + 0x218) != 0) {
    ExFreePoolWithTag(*(longlong *)(lVar4 + 0x218),0);
    *(undefined8 *)(lVar4 + 0x218) = 0;
  }
  *(undefined4 *)(lVar4 + 0x220) = 0;
  uVar7 = 0;
LAB_14000f29c:
  *(undefined1 *)(lVar4 + 0x208) = uVar7;
  return uVar5;
}



===== FilterDeviceKsrSaveDeviceContext @ 14000f2c8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FilterDeviceKsrSaveDeviceContext(undefined8 param_1,undefined4 *param_2)

{
  longlong lVar1;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FILTER_DEVICE_EXTENSION_TYPE_INFO_140016018);
  *param_2 = *(undefined4 *)(lVar1 + 8);
  memmove(param_2 + 0x84,*(void **)(lVar1 + 0x218),(ulonglong)*(uint *)(lVar1 + 0x220));
  *(undefined8 *)(param_2 + 2) = 0x210;
  param_2[1] = *(undefined4 *)(lVar1 + 0x220);
  memmove(param_2 + 4,*(void **)(lVar1 + 0x228),*(size_t *)(lVar1 + 0x230));
  return;
}



===== Feature_3414581563__private_IsEnabledDeviceUsageNoInline @ 14000f358 =====

ulonglong Feature_3414581563__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_3414581563__private_featureState;
  if ((Feature_3414581563__private_featureState & 0x10) == 0) {
    uVar1 = Feature_3414581563__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_3414581563__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_3414581563__private_IsEnabledFallback @ 14000f390 =====

void Feature_3414581563__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_3414581563__private_descriptor);
  return;
}



===== Feature_4258686266__private_IsEnabledDeviceUsageNoInline @ 14000f3ac =====

ulonglong Feature_4258686266__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_4258686266__private_featureState;
  if ((Feature_4258686266__private_featureState & 0x10) == 0) {
    uVar1 = Feature_4258686266__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_4258686266__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_4258686266__private_IsEnabledFallback @ 14000f3e4 =====

void Feature_4258686266__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_4258686266__private_descriptor);
  return;
}



===== GetCapabilitiesTCGCommand @ 14000f400 =====

int GetCapabilitiesTCGCommand(undefined8 param_1,longlong *param_2,uint *param_3,ulonglong *param_4)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  uint uVar4;
  uint uVar5;
  ulonglong _Size;
  short local_res20 [4];
  uint local_38 [2];
  uint *local_30;
  
  local_30 = (uint *)0x0;
  local_38[0] = 0;
  local_res20[0] = 0;
  if ((uint)*param_4 < 0x20) {
    iVar2 = -0x3ffffff3;
  }
  else {
    iVar2 = GetTCGLevel0DiscoveryData(param_1,param_2,&local_30,local_38);
    uVar1 = local_38[0];
    if (-1 < iVar2) {
      _Size = (ulonglong)local_38[0];
      uVar4 = local_38[0] + 0x20;
      if (*param_4 < (ulonglong)uVar4) {
        iVar2 = -0x3fffffdd;
      }
      else {
        uVar3 = GetTCGStorageSSCData(local_30,local_38[0],(uint *)0x0,local_res20);
        iVar2 = (int)uVar3;
        if (-1 < iVar2) {
          memset(param_3,0,*param_4);
          uVar5 = uVar4 >> 0x18 | (uVar4 & 0xff0000) >> 8 | (uVar4 & 0xff00) << 8 |
                  uVar4 * 0x1000000;
          *(short *)(param_3 + 3) = local_res20[0];
          *param_3 = uVar5;
          *(undefined1 *)((longlong)param_3 + 7) = 0;
          param_3[2] = uVar5;
          param_3[7] = uVar1;
          memmove(param_3 + 8,local_30,_Size);
          *param_4 = (ulonglong)uVar4;
        }
      }
      if (local_30 != (uint *)0x0) {
        ExFreePoolWithTag(local_30,0);
      }
    }
  }
  return iVar2;
}



===== GetTCGLevel0DiscoveryData @ 14000f500 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int GetTCGLevel0DiscoveryData
              (undefined8 param_1,longlong *param_2,undefined8 *param_3,uint *param_4)

{
  bool bVar1;
  int iVar2;
  longlong lVar3;
  void *_Dst;
  uint local_res18 [4];
  
  bVar1 = false;
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FILTER_DEVICE_EXTENSION_TYPE_INFO_140016018);
  *param_3 = 0;
  *param_4 = 0;
  local_res18[0] = 0x800;
  _Dst = (void *)ExAllocatePool2(0x40,0x800,0x47536353);
  if (_Dst == (void *)0x0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
               &WPP_6dffcf61b7ff359f9fb81cd3fb43e1c9_Traceguids,local_res18[0]);
    }
    iVar2 = -0x3fffff66;
  }
  else {
    if (param_2 == (longlong *)0x0) {
      param_2 = *(longlong **)(lVar3 + 0x1b8);
      if (*param_2 != 0) {
        (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,*param_2,0);
        bVar1 = true;
      }
    }
    iVar2 = IssueSecurityProtocolOutTCG
                      (*(undefined8 *)(lVar3 + 0x198),(longlong)param_2,1,1,(longlong)_Dst,
                       local_res18[0],*(char *)(lVar3 + 0x180),0);
    if (iVar2 < 0) {
      if ((Microsoft_Windows_EnhancedStorage_ClassDriverEnableBits & 2) != 0) {
        McTemplateK0quuujzdzxzxzxzx_EtwWriteTransfer();
      }
    }
    else {
      memset(_Dst,0,(ulonglong)local_res18[0]);
      iVar2 = IssueSecurityProtocolInTCG
                        (*(undefined8 *)(lVar3 + 0x198),(longlong)param_2,1,1,(longlong)_Dst,
                         local_res18,*(char *)(lVar3 + 0x180),0);
      if ((iVar2 < 0) || (local_res18[0] < 0x30)) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                   &WPP_6dffcf61b7ff359f9fb81cd3fb43e1c9_Traceguids,iVar2);
        }
        if ((Microsoft_Windows_EnhancedStorage_ClassDriverEnableBits & 2) != 0) {
          McTemplateK0quuujzdzxzxzxzx_EtwWriteTransfer();
        }
        iVar2 = -0x3fffffff;
      }
    }
    if (bVar1) {
      (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,*param_2);
    }
    if (iVar2 < 0) {
      ExFreePoolWithTag(_Dst,0);
    }
    else {
      *param_4 = local_res18[0];
      *param_3 = _Dst;
    }
  }
  return iVar2;
}



===== GetTCGStorageSSCData @ 14000f86c =====

undefined8 GetTCGStorageSSCData(uint *param_1,uint param_2,uint *param_3,short *param_4)

{
  bool bVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  ushort uVar5;
  undefined8 uVar6;
  
  bVar1 = false;
  if (param_2 < 0x31) {
    uVar6 = 0xc0000186;
  }
  else {
    uVar3 = *param_1;
    uVar4 = (uVar3 << 0x10 | uVar3 & 0xff00) << 8;
    if (((ulonglong)(uVar3 >> 8) & 0xff00 | (ulonglong)*(byte *)((longlong)param_1 + 3) |
        (ulonglong)uVar4) + 4 <= (ulonglong)param_2) {
      param_2 = (uVar3 >> 8 & 0xff00 | (uint)*(byte *)((longlong)param_1 + 3) | uVar4) + 4;
    }
    uVar3 = param_2 - 0x30;
    puVar2 = param_1 + 0xc;
    if (3 < uVar3) {
      do {
        uVar5 = (ushort)*(byte *)((longlong)puVar2 + 1) | (short)*puVar2 << 8;
        uVar4 = *(byte *)((longlong)puVar2 + 3) + 4;
        if (uVar3 < uVar4) break;
        if (((uVar5 == 0x200) || (uVar5 == 0x203)) && (*(byte *)((longlong)puVar2 + 3) == 0x10)) {
          if (param_3 != (uint *)0x0) {
            *param_3 = (uint)uVar5;
          }
          if (param_4 != (short *)0x0) {
            *param_4 = (short)puVar2[1];
          }
          bVar1 = true;
          if (uVar5 == 0x203) {
            return 0;
          }
        }
        uVar3 = uVar3 - uVar4;
        puVar2 = (uint *)((longlong)puVar2 + (ulonglong)uVar4);
      } while (3 < uVar3);
      if (bVar1) {
        return 0;
      }
    }
    uVar6 = 0xc00000bb;
  }
  return uVar6;
}



===== SendTCGStackReset @ 14000f994 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int SendTCGStackReset(undefined8 param_1,uint param_2,undefined4 *param_3,ulonglong *param_4)

{
  int iVar1;
  longlong lVar2;
  uint *puVar3;
  uint *puVar4;
  int iVar5;
  ushort uVar6;
  uint local_res20 [2];
  
  iVar1 = 0;
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FILTER_DEVICE_EXTENSION_TYPE_INFO_140016018);
  if (*param_4 < 8) {
    iVar1 = -0x3ffffff3;
  }
  else {
    uVar6 = (ushort)*(byte *)(lVar2 + 0x139) | *(short *)(lVar2 + 0x138) << 8;
    puVar3 = (uint *)ExAllocatePool2(0x40,0x200,0x47536353);
    iVar5 = -0x3fffff66;
    if (puVar3 == (uint *)0x0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
                 &WPP_6dffcf61b7ff359f9fb81cd3fb43e1c9_Traceguids,0x200);
      }
      iVar1 = -0x3fffff66;
    }
    local_res20[0] = 0x200;
    puVar4 = (uint *)ExAllocatePool2(0x40,0x200,0x47536353);
    if (puVar4 == (uint *)0x0) {
      iVar1 = iVar5;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
                 &WPP_6dffcf61b7ff359f9fb81cd3fb43e1c9_Traceguids,local_res20[0]);
      }
    }
    else if (-1 < iVar1) {
      *puVar3 = (uint)*(ushort *)(lVar2 + 0x138);
      puVar3[1] = 0x2000000;
      if (**(longlong **)(lVar2 + 0x1b8) != 0) {
        (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,**(longlong **)(lVar2 + 0x1b8),0)
        ;
      }
      iVar1 = IssueSecurityProtocolOutTCG
                        (*(undefined8 *)(lVar2 + 0x198),*(longlong *)(lVar2 + 0x1b8),2,uVar6,
                         (longlong)puVar3,0x200,*(char *)(lVar2 + 0x180),param_2);
      if ((iVar1 < 0) ||
         (iVar1 = IssueSecurityProtocolInTCG
                            (*(undefined8 *)(lVar2 + 0x198),*(longlong *)(lVar2 + 0x1b8),2,uVar6,
                             (longlong)puVar4,local_res20,*(char *)(lVar2 + 0x180),param_2),
         iVar1 < 0)) {
        if ((Microsoft_Windows_EnhancedStorage_ClassDriverEnableBits & 2) != 0) {
          McTemplateK0quuujzdzxzxzxzx_EtwWriteTransfer();
        }
      }
      else {
        if (local_res20[0] < 0x10) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
                     &WPP_6dffcf61b7ff359f9fb81cd3fb43e1c9_Traceguids,local_res20[0]);
          }
          if ((Microsoft_Windows_EnhancedStorage_ClassDriverEnableBits & 2) != 0) {
            McTemplateK0quuujzdzxzxzxzx_EtwWriteTransfer();
          }
          iVar1 = -0x3ffffe7a;
        }
        if (((*puVar4 != (uint)*(ushort *)(lVar2 + 0x138)) || (puVar4[1] != 0x2000000)) ||
           (*(short *)((longlong)puVar4 + 10) != 0x400)) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
                    &WPP_6dffcf61b7ff359f9fb81cd3fb43e1c9_Traceguids);
          }
          if ((Microsoft_Windows_EnhancedStorage_ClassDriverEnableBits & 2) != 0) {
            McTemplateK0quuujzdzxzxzxzx_EtwWriteTransfer();
          }
          iVar1 = -0x3ffffe7a;
        }
      }
      local_res20[0] = 8;
      *param_3 = 0x8000000;
      *(byte *)((longlong)param_3 + 7) = (byte)(iVar1 >> 0x1f) & 0x80;
      if (**(longlong **)(lVar2 + 0x1b8) != 0) {
        (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals);
      }
    }
    if (puVar3 != (uint *)0x0) {
      ExFreePoolWithTag(puVar3,0);
    }
    if (puVar4 != (uint *)0x0) {
      ExFreePoolWithTag(puVar4,0);
    }
  }
  return iVar1;
}



===== SendTCGTPerReset @ 14000ff44 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int SendTCGTPerReset(undefined8 param_1,uint param_2,undefined4 *param_3,ulonglong *param_4)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FILTER_DEVICE_EXTENSION_TYPE_INFO_140016018);
  if (((param_3 == (undefined4 *)0x0) || (param_4 == (ulonglong *)0x0)) || (7 < *param_4)) {
    lVar3 = ExAllocatePool2(0x40,0x200,0x47536353);
    if (lVar3 == 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
                 &WPP_6dffcf61b7ff359f9fb81cd3fb43e1c9_Traceguids,0x200);
      }
      iVar1 = -0x3fffff66;
    }
    else {
      if (**(longlong **)(lVar2 + 0x1b8) != 0) {
        (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,**(longlong **)(lVar2 + 0x1b8),0)
        ;
      }
      iVar1 = IssueSecurityProtocolOutTCG
                        (*(undefined8 *)(lVar2 + 0x198),*(longlong *)(lVar2 + 0x1b8),2,4,lVar3,0x200
                         ,*(char *)(lVar2 + 0x180),param_2);
      if ((iVar1 < 0) && ((Microsoft_Windows_EnhancedStorage_ClassDriverEnableBits & 2) != 0)) {
        McTemplateK0quuujzdzxzxzxzx_EtwWriteTransfer();
      }
      if ((param_3 != (undefined4 *)0x0) && (param_4 != (ulonglong *)0x0)) {
        *param_3 = 0x8000000;
        *(byte *)((longlong)param_3 + 7) = (byte)(iVar1 >> 0x1f) & 0x80;
        *param_4 = 8;
      }
      if (**(longlong **)(lVar2 + 0x1b8) != 0) {
        (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals);
      }
      ExFreePoolWithTag(lVar3,0);
    }
  }
  else {
    iVar1 = -0x3ffffff3;
  }
  return iVar1;
}



===== SendTransferTCGCommand @ 140010188 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint SendTransferTCGCommand
               (undefined8 param_1,longlong param_2,longlong param_3,uint *param_4,
               ulonglong *param_5)

{
  void *pvVar1;
  uint uVar2;
  longlong lVar3;
  ulonglong uVar4;
  void *_Src;
  ushort uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  uint local_58;
  uint local_54;
  uint local_50;
  void *local_48;
  void *local_40;
  
  local_54 = 0;
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FILTER_DEVICE_EXTENSION_TYPE_INFO_140016018);
  if ((*(uint *)(param_3 + 4) < 0x34) || (*param_5 < 0x34)) {
    return 0xc000000d;
  }
  local_48 = (void *)(param_3 + 0x28);
  uVar5 = (ushort)*(byte *)(lVar3 + 0x139) | *(short *)(lVar3 + 0x138) << 8;
  uVar4 = Feature_4258686266__private_IsEnabledDeviceUsageNoInline();
  uVar7 = *(uint *)(param_3 + 0x38);
  uVar7 = (uVar7 << 0x10 | uVar7 & 0xff00) << 8 | uVar7 >> 8 & 0xff00 |
          (uint)*(byte *)(param_3 + 0x3b);
  uVar8 = uVar7 + 0x14;
  if ((int)uVar4 == 0) {
    uVar7 = uVar7 + 0x213 & 0xfffffe00;
  }
  else if (((uVar8 < uVar7) || (local_54 = 0, *(int *)(param_3 + 4) - 0x20U < uVar8)) ||
          (uVar7 = uVar7 + 0x213 & 0xfffffe00, uVar7 < uVar8)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      uVar7 = *(uint *)(param_3 + 0x38);
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
               &WPP_6dffcf61b7ff359f9fb81cd3fb43e1c9_Traceguids,
               (uVar7 << 0x10 | uVar7 & 0xff00) << 8 | uVar7 >> 8 & 0xff00 |
               (uint)*(byte *)(param_3 + 0x3b));
    }
    if ((Microsoft_Windows_EnhancedStorage_ClassDriverEnableBits & 2) == 0) {
      return 0xc000000d;
    }
    McTemplateK0quuujzdzxzxzxzx_EtwWriteTransfer();
    return 0xc000000d;
  }
  local_40 = (void *)ExAllocatePool2(0x40,uVar7,0x47536353);
  uVar2 = 0xc000009a;
  if (local_40 == (void *)0x0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
               &WPP_6dffcf61b7ff359f9fb81cd3fb43e1c9_Traceguids,uVar7);
    }
    local_54 = 0xc000009a;
  }
  local_58 = (uint)*param_5;
  uVar4 = Feature_3414581563__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar4 == 0) {
    uVar6 = local_58 + 0x1ff & 0xfffffe00;
    local_58 = 0x10000;
    if (uVar6 < 0x10000) {
      local_58 = uVar6;
    }
  }
  else {
    uVar6 = local_58 + 0x1ff & 0xfffffe00;
    bVar9 = local_58 <= uVar6;
    local_58 = 0x10000;
    if ((bVar9) && (local_58 = 0x10000, uVar6 < 0x10000)) {
      local_58 = uVar6;
    }
  }
  _Src = (void *)ExAllocatePool2(0x40,local_58,0x47536353);
  uVar4 = Feature_3414581563__private_IsEnabledDeviceUsageNoInline();
  pvVar1 = local_40;
  local_50 = 0;
  if ((int)uVar4 != 0) {
    local_50 = local_58;
  }
  if (_Src == (void *)0x0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
               &WPP_6dffcf61b7ff359f9fb81cd3fb43e1c9_Traceguids,local_58);
    }
    goto LAB_140010aea;
  }
  uVar2 = local_54;
  if ((int)local_54 < 0) goto LAB_140010aea;
  memmove(local_40,local_48,(ulonglong)uVar8);
  uVar2 = IssueSecurityProtocolOutTCG
                    (*(undefined8 *)(lVar3 + 0x198),param_2,1,uVar5,(longlong)pvVar1,uVar7,
                     *(char *)(lVar3 + 0x180),(*(uint *)(lVar3 + 0x130) & 0x40) << 5);
  if (((int)uVar2 < 0) ||
     (uVar2 = IssueSecurityProtocolInTCG
                        (*(undefined8 *)(lVar3 + 0x198),param_2,1,uVar5,(longlong)_Src,&local_58,
                         *(char *)(lVar3 + 0x180),(*(uint *)(lVar3 + 0x130) & 0x40) << 5),
     (int)uVar2 < 0)) {
joined_r0x0001400108b9:
    if ((Microsoft_Windows_EnhancedStorage_ClassDriverEnableBits & 2) != 0) {
      McTemplateK0quuujzdzxzxzxzx_EtwWriteTransfer();
    }
    goto LAB_140010aea;
  }
  if (local_58 < 0x14) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
               &WPP_6dffcf61b7ff359f9fb81cd3fb43e1c9_Traceguids,local_58);
    }
  }
  else {
    uVar4 = Feature_3414581563__private_IsEnabledDeviceUsageNoInline();
    uVar7 = *(uint *)((longlong)_Src + 0x10);
    uVar7 = (uVar7 << 0x10 | uVar7 & 0xff00) << 8 | uVar7 >> 8 & 0xff00 |
            (uint)*(byte *)((longlong)_Src + 0x13);
    if ((int)uVar4 == 0) {
      uVar8 = uVar7 + 0x14;
      uVar7 = uVar7 + 0x34;
      local_58 = uVar7;
      if ((ulonglong)uVar7 <= *param_5) {
        uVar6 = uVar7 >> 0x18 | (uVar7 & 0xff0000) >> 8 | (uVar7 & 0xff00) << 8 | uVar7 * 0x1000000;
        *param_4 = uVar6;
        param_4[2] = uVar6;
        *(undefined1 *)((longlong)param_4 + 7) = 0;
        param_4[7] = uVar8 >> 0x18 | (uVar8 & 0xff0000) >> 8 | (uVar8 & 0xff00) << 8 |
                     uVar8 * 0x1000000;
        memmove(param_4 + 8,_Src,(ulonglong)uVar8);
        *param_5 = (ulonglong)uVar7;
        goto LAB_140010aea;
      }
LAB_140010ae5:
      uVar2 = 0xc0000023;
      goto LAB_140010aea;
    }
    uVar8 = uVar7 + 0x14;
    if (uVar7 <= uVar8) {
      uVar7 = uVar7 + 0x34;
      local_58 = 0xffffffff;
      if (uVar7 >= 0x20) {
        local_58 = uVar7;
      }
      uVar2 = -(uint)(uVar7 < 0x20) & 0xc0000095;
      if (0x1f < uVar7) {
        uVar4 = (ulonglong)local_58;
        if (uVar4 <= *param_5) {
          if (uVar8 <= local_50) {
            uVar7 = local_58 >> 0x18 | (local_58 & 0xff0000) >> 8 | (local_58 & 0xff00) << 8 |
                    local_58 << 0x18;
            *param_4 = uVar7;
            param_4[2] = uVar7;
            *(undefined1 *)((longlong)param_4 + 7) = 0;
            param_4[7] = (uVar8 & 0xff0000 | uVar8 >> 0x10) >> 8 |
                         (uVar8 * 0x10000 | uVar8 & 0xff00) << 8;
            memmove(param_4 + 8,_Src,(ulonglong)uVar8);
            *param_5 = uVar4;
            goto LAB_140010aea;
          }
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
                      &WPP_6dffcf61b7ff359f9fb81cd3fb43e1c9_Traceguids,uVar8,(char)local_50);
          }
          uVar2 = 0xc0000186;
          goto joined_r0x0001400108b9;
        }
        goto LAB_140010ae5;
      }
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      uVar7 = *(uint *)((longlong)_Src + 0x10);
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
               &WPP_6dffcf61b7ff359f9fb81cd3fb43e1c9_Traceguids,
               (uVar7 << 0x10 | uVar7 & 0xff00) << 8 | uVar7 >> 8 & 0xff00 |
               (uint)*(byte *)((longlong)_Src + 0x13));
    }
  }
  if ((Microsoft_Windows_EnhancedStorage_ClassDriverEnableBits & 2) != 0) {
    McTemplateK0quuujzdzxzxzxzx_EtwWriteTransfer();
  }
  uVar2 = 0xc0000186;
LAB_140010aea:
  if (local_40 != (void *)0x0) {
    ExFreePoolWithTag(local_40,0);
  }
  if (_Src != (void *)0x0) {
    ExFreePoolWithTag(_Src,0);
  }
  return uVar2;
}



===== SiloCommandToTCGCommand @ 140010b4c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint SiloCommandToTCGCommand
               (undefined8 param_1,longlong *param_2,longlong param_3,uint *param_4,
               ulonglong *param_5)

{
  char cVar1;
  uint uVar2;
  longlong lVar3;
  
  uVar2 = 0xc0000010;
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FILTER_DEVICE_EXTENSION_TYPE_INFO_140016018);
  cVar1 = *(char *)(param_3 + 1);
  if (cVar1 == '\x01') {
    uVar2 = GetCapabilitiesTCGCommand(param_1,param_2,param_4,param_5);
  }
  else if (cVar1 == '\x02') {
    uVar2 = SendTransferTCGCommand(param_1,(longlong)param_2,param_3,param_4,param_5);
  }
  else if (cVar1 == '\x04') {
    uVar2 = GetTransferResultsTCGCommand(param_1,(longlong)param_2,param_4,param_5);
  }
  else if (cVar1 == '\x05') {
    uVar2 = SendTCGTPerReset(param_1,(*(uint *)(lVar3 + 0x130) & 0x40) << 5,param_4,param_5);
  }
  else {
    if (cVar1 != '\x03') goto LAB_140010c46;
    uVar2 = SendTCGStackReset(param_1,(*(uint *)(lVar3 + 0x130) & 0x40) << 5,param_4,param_5);
  }
  if (-1 < (int)uVar2) {
    return uVar2;
  }
LAB_140010c46:
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
             &WPP_6dffcf61b7ff359f9fb81cd3fb43e1c9_Traceguids,uVar2);
  }
  return uVar2;
}



===== RtlStringCopyWorkerA @ 140010c9c =====

uint RtlStringCopyWorkerA
               (char *param_1,longlong param_2,undefined8 param_3,longlong param_4,longlong param_5)

{
  char *pcVar1;
  longlong lVar2;
  
  if (param_2 != 0) {
    lVar2 = param_4 - (longlong)param_1;
    do {
      if ((param_5 == 0) || (param_1[lVar2] == '\0')) break;
      *param_1 = param_1[lVar2];
      param_5 = param_5 + -1;
      param_1 = param_1 + 1;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  pcVar1 = param_1 + -1;
  if (param_2 != 0) {
    pcVar1 = param_1;
  }
  *pcVar1 = '\0';
  return ~-(uint)(param_2 != 0) & 0x80000005;
}



===== RtlStringExHandleOtherFlagsW @ 140010cf0 =====

undefined8
RtlStringExHandleOtherFlagsW
          (undefined2 *param_1,ulonglong param_2,undefined8 param_3,undefined8 *param_4,
          ulonglong *param_5,uint param_6)

{
  ulonglong uVar1;
  
  uVar1 = param_2 >> 1;
  if ((uVar1 != 0) && ((param_6 & 0x1000) != 0)) {
    *param_4 = param_1;
    *param_5 = uVar1;
    *param_1 = 0;
  }
  if ((param_6 & 0x400) != 0) {
    memset(param_1,param_6 & 0xff,param_2);
    if ((char)param_6 != '\0') {
      if (uVar1 == 0) {
        return 0;
      }
      *param_5 = 1;
      *param_4 = param_1 + (uVar1 - 1);
      param_1[uVar1 - 1] = 0;
      goto LAB_140010d5b;
    }
    *param_4 = param_1;
    *param_5 = uVar1;
  }
  if (uVar1 == 0) {
    return 0;
  }
LAB_140010d5b:
  if ((param_6 & 0x800) != 0) {
    *param_4 = param_1;
    *param_5 = uVar1;
    *param_1 = 0;
  }
  return 0;
}



===== RtlStringExValidateDestW @ 140010db0 =====

undefined8
RtlStringExValidateDestW(longlong param_1,ulonglong param_2,undefined8 param_3,uint param_4)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if ((param_4 >> 8 & 1) == 0) {
    uVar1 = 0;
    if (0x7ffffffe < param_2 - 1) {
      uVar1 = 0xc000000d;
    }
  }
  else if (((param_1 == 0) && (param_2 != 0)) || (0x7fffffff < param_2)) {
    return 0xc000000d;
  }
  return uVar1;
}



===== RtlStringValidateDestAndLengthA @ 140010df0 =====

void RtlStringValidateDestAndLengthA(char *param_1,undefined8 param_2,longlong *param_3)

{
  RtlStringLengthWorkerA(param_1,param_2,param_3);
  return;
}



===== __GSHandlerCheck_SEH @ 140010e08 =====

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



===== __security_check_cookie @ 140010ea0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140010ee0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 140010f10 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140010f10. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140010f40 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memset @ 140010fc0 =====

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



===== __memset_repmovs @ 140011100 =====

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



===== __memset_query @ 140011180 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140011200 =====

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



===== __memset_spec_ermsb_repmovsb @ 140011340 =====

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



===== __memset_spec_plain @ 1400113c0 =====

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



===== memcmp @ 1400114e0 =====

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
      if ((byte)*(ulonglong *)_Buf1 != *(byte *)((longlong)_Buf1 + lVar3)) goto LAB_140011523;
      _Size = _Size - 1;
    }
    if (_Size >> 3 != 0) {
      uVar4 = _Size >> 5;
      if (uVar4 != 0) {
        do {
          uVar2 = *(ulonglong *)_Buf1;
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3)) goto LAB_140011594;
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 8);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 8)) {
LAB_140011590:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_140011594;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x10);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x10)) {
LAB_14001158c:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_140011590;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x18);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x18)) {
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_14001158c;
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
LAB_140011594:
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
LAB_140011523:
  return (1 - (uint)bVar5) - (uint)(bVar5 != 0);
}



===== memmove @ 140011600 =====

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



===== WppCleanupKm @ 14001a008 =====

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



===== WppInitKm @ 14001a088 =====

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



===== WppTraceCallback @ 14001a120 =====

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
        memmove((ushort *)((ulonglong)uVar11 + (longlong)param_4) + 1,*(void **)(puVar3 + 4),
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



===== wil_UninitializeFeatureStaging @ 14001a3a8 =====

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



===== wil_details_BuildFeatureStateCacheFromQueryResults @ 14001a400 =====

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
      goto LAB_14001a45d;
    }
    if (param_1 == 0x117) {
      uVar1 = (*(uint *)(param_2 + 4) & 0x80) << 3 | 0x206;
      goto LAB_14001a45d;
    }
  }
  uVar1 = 0x206;
LAB_14001a45d:
  *param_3 = uVar1;
  return;
}



===== wil_details_EvaluateFeatureDependencies @ 14001a468 =====

void wil_details_EvaluateFeatureDependencies(void)

{
  longlong *plVar1;
  undefined **ppuVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  bool bVar6;
  
  plVar1 = wil_details_FeatureDescriptors_SkipPadding
                     ((longlong *)&Feature_2813562171__private_descriptor);
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
  ppuVar2 = &Feature_2813562171__private_descriptor;
  while( true ) {
    plVar1 = wil_details_FeatureDescriptors_SkipPadding((longlong *)ppuVar2);
    if (plVar1 == (longlong *)0x0) break;
    wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
              ((uint *)*plVar1,(longlong)plVar1);
    ppuVar2 = (undefined **)(plVar1 + 7);
  }
  return;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 14001a520 =====

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



===== wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState @ 14001a558 =====

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
        if (puVar1 == (undefined8 *)0x0) goto LAB_14001a5da;
        if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
           (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
        if ((uVar5 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
          uVar5 = 0;
          goto LAB_14001a5da;
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
LAB_14001a5da:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 14001a630 =====

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
      ppuVar3 = &Feature_2813562171__private_descriptor;
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



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 14001a690 =====

void wil_details_ReevaluateOnFeatureConfigurationChange(void)

{
  wil_details_UpdateFeatureConfiguredStates();
  wil_details_EvaluateFeatureDependencies();
  return;
}



===== wil_details_UpdateFeatureConfiguredStates @ 14001a6ac =====

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
  ppuVar3 = &Feature_2813562171__private_descriptor;
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



===== FilterDeviceEvtSelfManagedIoCleanup @ 14001a760 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FilterDeviceEvtSelfManagedIoCleanup(undefined8 param_1)

{
  longlong lVar1;
  
  LogEvent("FStop",param_1,0,0);
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FILTER_DEVICE_EXTENSION_TYPE_INFO_140016018);
  if (*(longlong *)(lVar1 + 0x1a0) != 0) {
    (**(code **)(WdfFunctions_01015 + 0x550))(WdfDriverGlobals);
    *(undefined8 *)(lVar1 + 0x1a0) = 0;
  }
  if (*(longlong *)(lVar1 + 0x1a8) != 0) {
    ObfDereferenceObject();
    *(undefined8 *)(lVar1 + 0x1a8) = 0;
  }
  return;
}



===== FilterDeviceEvtSelfManagedIoFlush @ 14001a800 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FilterDeviceEvtSelfManagedIoFlush(undefined8 param_1)

{
  longlong lVar1;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  LogEvent("FIoFlush",param_1,0,0);
  (**(code **)(WdfFunctions_01015 + 0x528))(WdfDriverGlobals,*(undefined8 *)(lVar1 + 0x188),0,0);
  (**(code **)(WdfFunctions_01015 + 0x528))(WdfDriverGlobals,*(undefined8 *)(lVar1 + 400),0,0);
  return;
}



===== FilterDevicePreprocessRebootIrp @ 14001a8b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FilterDevicePreprocessRebootIrp(undefined8 param_1)

{
  char *pcVar1;
  longlong *plVar2;
  longlong lVar3;
  int iVar4;
  undefined8 uVar5;
  longlong *plVar6;
  
  uVar5 = (**(code **)(WdfFunctions_01015 + 0xbe8))(WdfDriverGlobals,param_1);
  plVar6 = (longlong *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  LogEvent("FRebootE",uVar5,0,0);
  FilterDeviceEvtD0Exit(uVar5,5);
  lVar3 = *plVar6;
  pcVar1 = (char *)(lVar3 + 0x43);
  *pcVar1 = *pcVar1 + '\x01';
  plVar2 = (longlong *)(lVar3 + 0xb8);
  *plVar2 = *plVar2 + 0x48;
  iVar4 = (**(code **)(WdfFunctions_01015 + 0x110))(WdfDriverGlobals,uVar5);
  if (iVar4 < 0) {
    *(int *)(*plVar6 + 0x30) = iVar4;
    IofCompleteRequest(*plVar6,0);
  }
  (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  LogEvent("FRebootX",0,0,0);
  return;
}



===== FilterDevicePreprocessStartIrp @ 14001a9c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FilterDevicePreprocessStartIrp(undefined8 param_1)

{
  char *pcVar1;
  longlong *plVar2;
  longlong lVar3;
  int iVar4;
  undefined8 uVar5;
  longlong *plVar6;
  
  uVar5 = (**(code **)(WdfFunctions_01015 + 0xbe8))(WdfDriverGlobals,param_1);
  plVar6 = (longlong *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_PNP_IRP_WORKITEM_CONTEXT_TYPE_INFO_140016130
                     );
  lVar3 = *plVar6;
  pcVar1 = (char *)(lVar3 + 0x43);
  *pcVar1 = *pcVar1 + '\x01';
  plVar2 = (longlong *)(lVar3 + 0xb8);
  *plVar2 = *plVar2 + 0x48;
  iVar4 = (**(code **)(WdfFunctions_01015 + 0x110))(WdfDriverGlobals,uVar5,*plVar6);
  if (iVar4 < 0) {
    *(int *)(*plVar6 + 0x30) = iVar4;
    IofCompleteRequest(*plVar6,0);
  }
  return;
}



===== FilterDeviceCheck1667Support @ 14001aa70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined1 FilterDeviceCheck1667Support(undefined8 param_1,uint *param_2)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  byte bVar5;
  byte *pbVar6;
  uint uVar7;
  undefined8 uVar8;
  undefined1 uVar9;
  undefined1 uVar10;
  uint uVar11;
  int iVar12;
  uint local_res20 [2];
  uint local_48 [4];
  
  lVar2 = WdfFunctions_01015;
  uVar9 = 0;
  uVar10 = 0;
  *param_2 = 0;
  local_48[0] = 0;
  lVar2 = (**(code **)(lVar2 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FILTER_DEVICE_EXTENSION_TYPE_INFO_140016018);
  uVar7 = *(uint *)(lVar2 + 300) & 2;
  if (**(longlong **)(lVar2 + 0x1b8) != 0) {
    (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,**(longlong **)(lVar2 + 0x1b8),0);
  }
  uVar8 = 0x47536353;
  uVar11 = -(uint)(uVar7 != 0) & 0xfffffe01;
  iVar12 = uVar11 + 0x200;
  bVar5 = ~-(uVar7 != 0) & 9;
  local_res20[0] = (uVar11 + 0x207 >> bVar5) * iVar12;
  lVar3 = ExAllocatePool2(0x40,local_res20[0],0x47536353);
  if (lVar3 == 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
               &WPP_94719a13e7d8366cd9a87695c567288d_Traceguids,local_res20[0]);
    }
    iVar12 = -0x3fffff66;
  }
  else {
    iVar1 = IssueSecurityProtocolIn
                      (*(undefined8 *)(lVar2 + 0x198),*(longlong *)(lVar2 + 0x1b8),
                       CONCAT71((int7)((ulonglong)uVar8 >> 8),uVar7 == 0),0,0,0,lVar3,local_res20,
                       *(char *)(lVar2 + 0x180),0);
    if ((iVar1 < 0) || (local_res20[0] < 8)) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                 &WPP_94719a13e7d8366cd9a87695c567288d_Traceguids,iVar1);
      }
      if ((Microsoft_Windows_EnhancedStorage_ClassDriverEnableBits & 2) != 0) {
        McTemplateK0quuujzdzxzxzxzx_EtwWriteTransfer();
      }
      iVar12 = -0x3fffffff;
    }
    else {
      uVar11 = (uint)*(byte *)(lVar3 + 7) + (uint)*(byte *)(lVar3 + 6) * 0x100 + 8;
      local_res20[0] = ((uVar11 - 1) + iVar12 >> bVar5) * iVar12;
      ExFreePoolWithTag(lVar3,0);
      uVar8 = 0x47536353;
      lVar3 = ExAllocatePool2(0x40,local_res20[0],0x47536353);
      if (lVar3 == 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                   &WPP_94719a13e7d8366cd9a87695c567288d_Traceguids,local_res20[0]);
        }
        iVar12 = -0x3fffff66;
      }
      else {
        local_48[0] = local_res20[0];
        iVar12 = IssueSecurityProtocolIn
                           (*(undefined8 *)(lVar2 + 0x198),*(longlong *)(lVar2 + 0x1b8),
                            CONCAT71((int7)((ulonglong)uVar8 >> 8),uVar7 == 0),0,0,0,lVar3,local_48,
                            *(char *)(lVar2 + 0x180),0);
        if ((iVar12 < 0) || (local_48[0] < uVar11)) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                     &WPP_94719a13e7d8366cd9a87695c567288d_Traceguids,iVar12);
          }
          if ((Microsoft_Windows_EnhancedStorage_ClassDriverEnableBits & 2) != 0) {
            McTemplateK0quuujzdzxzxzxzx_EtwWriteTransfer();
          }
          iVar12 = -0x3fffffff;
        }
      }
    }
  }
  if (**(longlong **)(lVar2 + 0x1b8) != 0) {
    (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals);
  }
  if (-1 < iVar12) {
    local_48[0] = (uint)CONCAT11(*(undefined1 *)(lVar3 + 6),*(undefined1 *)(lVar3 + 7));
    uVar4 = Feature_2813562171__private_IsEnabledDeviceUsageNoInline();
    if (((int)uVar4 != 0) && (local_res20[0] - 8 < local_48[0])) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                  &WPP_94719a13e7d8366cd9a87695c567288d_Traceguids,local_48[0],
                  (char)(local_res20[0] - 8));
      }
      if ((Microsoft_Windows_EnhancedStorage_ClassDriverEnableBits & 2) != 0) {
        McTemplateK0quuujzdzxzxzxzx_EtwWriteTransfer();
      }
      local_48[0] = 0;
    }
    if (local_48[0] != 0) {
      uVar4 = (ulonglong)local_48[0];
      pbVar6 = (byte *)(lVar3 + 8);
      do {
        bVar5 = *pbVar6;
        if (bVar5 < 0x20) {
          *param_2 = *param_2 | 1 << (bVar5 & 0x1f);
        }
        else {
          uVar10 = uVar9;
          if (bVar5 == 0xee) {
            uVar10 = 1;
            uVar9 = 1;
          }
        }
        pbVar6 = pbVar6 + 1;
        uVar4 = uVar4 - 1;
      } while (uVar4 != 0);
    }
  }
  if (lVar3 != 0) {
    ExFreePoolWithTag(lVar3,0);
  }
  return uVar10;
}



===== FilterDeviceCheckNativeOpal @ 14001b054 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 FilterDeviceCheckNativeOpal(undefined8 param_1)

{
  bool bVar1;
  bool bVar2;
  undefined1 uVar3;
  int iVar4;
  uint uVar5;
  longlong lVar6;
  undefined4 extraout_var;
  undefined *puVar7;
  longlong lVar8;
  undefined2 uVar9;
  undefined1 uVar10;
  undefined8 uVar11;
  short local_res10 [4];
  uint local_res18 [2];
  uint local_res20 [2];
  uint *local_38;
  longlong local_30;
  
  uVar10 = 0;
  local_30 = 0;
  bVar2 = false;
  bVar1 = false;
  local_38 = (uint *)0x0;
  local_res18[0] = 0;
  local_res20[0] = 0;
  local_res10[0] = 0;
  lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FILTER_DEVICE_EXTENSION_TYPE_INFO_140016018);
  iVar4 = GetTCGLevel0DiscoveryData(param_1,(longlong *)0x0,&local_38,local_res18);
  puVar7 = (undefined *)CONCAT44(extraout_var,iVar4);
  if (iVar4 < 0) goto LAB_14001b2c3;
  puVar7 = (undefined *)GetTCGStorageSSCData(local_38,local_res18[0],local_res20,local_res10);
  bVar1 = bVar2;
  if ((-1 < (int)puVar7) && (local_res20[0] == 0x203)) {
    uVar11 = 0x104;
    uVar5 = ChildDeviceCreate(param_1,3,0x104,0,&local_30);
    if ((int)uVar5 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar3 = (**(code **)(WdfFunctions_01015 + 0x108))(WdfDriverGlobals,param_1);
        WPP_SF_dDq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,uVar11,0,4,uVar3);
      }
    }
    else {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar3 = (**(code **)(WdfFunctions_01015 + 0x108))(WdfDriverGlobals,param_1);
        WPP_SF_dDq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,uVar11,0,4,uVar3);
      }
      lVar8 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,local_30);
      *(undefined4 *)(lVar8 + 0x78) = 0x20002;
      *(short *)(lVar6 + 0x138) = local_res10[0];
      bVar1 = true;
    }
    uVar5 = ChildDeviceCreate(param_1,2,0,0,(longlong *)(lVar6 + 0x1b0));
    puVar7 = WPP_GLOBAL_Control;
    if ((int)uVar5 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar11 = (**(code **)(WdfFunctions_01015 + 0x108))(WdfDriverGlobals,param_1);
        uVar9 = 0x24;
        goto LAB_14001b291;
      }
    }
    else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      uVar11 = (**(code **)(WdfFunctions_01015 + 0x108))(WdfDriverGlobals,param_1);
      uVar9 = 0x23;
LAB_14001b291:
      puVar7 = (undefined *)
               WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar9,
                        &WPP_94719a13e7d8366cd9a87695c567288d_Traceguids,uVar11);
    }
  }
  if (local_38 != (uint *)0x0) {
    puVar7 = (undefined *)ExFreePoolWithTag(local_38,0);
  }
LAB_14001b2c3:
  if ((*(longlong *)(lVar6 + 0x1b0) != 0) || (bVar1)) {
    uVar10 = 1;
  }
  return CONCAT71((int7)((ulonglong)puVar7 >> 8),uVar10);
}



===== FilterDeviceEnumerate1667Silos @ 14001b2f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 FilterDeviceEnumerate1667Silos(undefined8 param_1)

{
  uint *puVar1;
  byte bVar2;
  byte bVar3;
  undefined1 uVar4;
  uint uVar5;
  undefined *puVar6;
  undefined *puVar7;
  undefined4 extraout_var;
  ulonglong uVar8;
  longlong lVar9;
  undefined8 uVar10;
  undefined2 uVar11;
  undefined1 uVar12;
  uint uVar13;
  uint *puVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  char local_res10 [8];
  uint local_res18 [2];
  uint local_res20;
  uint local_68 [2];
  longlong local_60;
  uint *local_58;
  undefined *local_50;
  longlong local_48;
  uint *local_40;
  
  uVar12 = 0;
  local_60 = 0;
  uVar5 = 0;
  local_res18[0] = 0;
  uVar17 = 0;
  local_res10[0] = '\0';
  local_58 = (uint *)0x0;
  local_68[0] = 0;
  local_res20 = 0;
  puVar14 = (uint *)PTR__WDF_FILTER_DEVICE_EXTENSION_TYPE_INFO_140016018;
  puVar6 = (undefined *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  puVar7 = puVar6;
  if ((FilterDeviceKsrCallbackObject != 0) &&
     (puVar7 = (undefined *)ExIsSoftBoot(), (char)puVar7 != '\0')) {
    puVar7 = (undefined *)FilterDeviceKsrRestoreDeviceContext(param_1);
    uVar5 = (uint)puVar7;
    if (-1 < (int)uVar5) {
      local_60 = *(longlong *)(puVar6 + 0x218);
      local_res18[0] = *(uint *)(puVar6 + 0x220);
    }
  }
  uVar8 = (ulonglong)local_res18[0];
  if (*(longlong *)(puVar6 + 0x218) == 0) {
    puVar14 = local_res18;
    uVar5 = FilterDeviceSend1667Probe(param_1,&local_60,puVar14,uVar8);
    puVar7 = (undefined *)CONCAT44(extraout_var,uVar5);
    if ((int)uVar5 < 0) goto LAB_14001b80a;
    *(longlong *)(puVar6 + 0x218) = local_60;
    puVar7 = (undefined *)(ulonglong)local_res18[0];
    *(uint *)(puVar6 + 0x220) = local_res18[0];
    uVar8 = (ulonglong)local_res18[0];
  }
  else if ((int)uVar5 < 0) goto LAB_14001b80a;
  iVar16 = 0xe;
  if ((uint)uVar8 < 0xe) goto LAB_14001b80a;
  iVar15 = 0xe;
  local_50 = (undefined *)
             (((ulonglong)((*(ushort *)(local_60 + 0xc) & 0xff) << 8) |
              (ulonglong)(*(ushort *)(local_60 + 0xc) >> 8)) / 0x24);
  for (; puVar7 = local_50, uVar17 < (uint)local_50; uVar17 = uVar17 + 1) {
    if (uVar8 < (longlong)iVar15 + 0x24U) {
      puVar7 = WPP_GLOBAL_Control;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar4 = (**(code **)(WdfFunctions_01015 + 0x108))(WdfDriverGlobals,param_1);
        puVar7 = (undefined *)
                 WPP_SF_dq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,puVar14,uVar17,uVar4);
      }
      break;
    }
    uVar13 = *(uint *)(local_60 + 0x2a + (ulonglong)uVar17 * 0x24);
    puVar7 = (undefined *)0x0;
    uVar13 = (uVar13 << 0x10 | uVar13 & 0xff00) << 8 |
             (uint)*(byte *)(local_60 + 0x2d + (ulonglong)uVar17 * 0x24) | uVar13 >> 8 & 0xff00;
    puVar14 = (uint *)(ulonglong)uVar13;
    if (uVar13 == 0x100) goto LAB_14001b4d0;
    iVar15 = iVar15 + 0x24;
  }
  uVar5 = 0xc0000186;
LAB_14001b4d0:
  if ((int)uVar5 < 0) {
    uVar17 = 0;
    goto LAB_14001b80a;
  }
  puVar14 = local_68;
  PolicyReadSiloAllowList(local_res10,(longlong *)&local_58,(int *)puVar14);
  for (uVar17 = 0; uVar17 < (uint)local_50; uVar17 = uVar17 + 1) {
    local_48 = 0;
    if ((ulonglong)local_res18[0] < (longlong)iVar16 + 0x24U) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar4 = (**(code **)(WdfFunctions_01015 + 0x108))(WdfDriverGlobals,param_1);
        WPP_SF_dq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,puVar14,uVar17,uVar4);
      }
      break;
    }
    uVar8 = (ulonglong)uVar17;
    local_40 = (uint *)(uVar8 * 9);
    puVar1 = (uint *)(local_60 + 0x2a + uVar8 * 0x24);
    uVar5 = *puVar1;
    uVar13 = uVar5 >> 8 & 0xff00;
    bVar2 = *(byte *)(local_60 + 0x2d + uVar8 * 0x24);
    uVar5 = (uVar5 << 0x10 | uVar5 & 0xff00) << 8 | uVar13 | (uint)bVar2;
    if (local_res10[0] == '\0') {
LAB_14001b5ac:
      puVar14 = (uint *)(ulonglong)uVar5;
      uVar5 = ChildDeviceCreate(param_1,3,uVar5,(byte)uVar17,&local_48);
      if ((int)uVar5 < 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar4 = (**(code **)(WdfFunctions_01015 + 0x108))(WdfDriverGlobals,param_1);
          uVar11 = 0x1e;
          goto LAB_14001b6c4;
        }
      }
      else {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar4 = (**(code **)(WdfFunctions_01015 + 0x108))(WdfDriverGlobals,param_1);
          WPP_SF_dDq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,puVar14,uVar17,bVar2,uVar4);
        }
        lVar9 = (**(code **)(WdfFunctions_01015 + 0x650))
                          (WdfDriverGlobals,local_48,
                           PTR__WDF_CHILD_DEVICE_EXTENSION_TYPE_INFO_1400160b8);
        local_res20 = local_res20 + 1;
        *(undefined1 *)(lVar9 + 0x7a) = *(undefined1 *)(local_60 + 0x30 + (longlong)local_40 * 4);
        *(undefined1 *)(lVar9 + 0x7b) = *(undefined1 *)(local_60 + 0x31 + (longlong)local_40 * 4);
        *(undefined1 *)(lVar9 + 0x78) = *(undefined1 *)(local_60 + 0x2e + (longlong)local_40 * 4);
        *(undefined1 *)(lVar9 + 0x79) = *(undefined1 *)(local_60 + 0x2f + (longlong)local_40 * 4);
        puVar14 = local_40;
      }
    }
    else {
      puVar14 = local_58;
      bVar3 = PolicyIsSiloBlocked(puVar1,(ulonglong)uVar13,local_58,local_68[0]);
      if (bVar3 == 0) goto LAB_14001b5ac;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (2 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar4 = (**(code **)(WdfFunctions_01015 + 0x108))(WdfDriverGlobals,param_1);
        uVar11 = 0x1c;
LAB_14001b6c4:
        WPP_SF_dDq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar11,puVar14,uVar17,bVar2,uVar4);
      }
    }
    iVar16 = iVar16 + 0x24;
  }
  uVar17 = ChildDeviceCreate(param_1,2,0,0,(longlong *)(puVar6 + 0x1b0));
  puVar7 = WPP_GLOBAL_Control;
  if ((int)uVar17 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      uVar10 = (**(code **)(WdfFunctions_01015 + 0x108))(WdfDriverGlobals,param_1);
      uVar11 = 0x20;
      goto LAB_14001b7d4;
    }
  }
  else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    uVar10 = (**(code **)(WdfFunctions_01015 + 0x108))(WdfDriverGlobals,param_1);
    uVar11 = 0x1f;
LAB_14001b7d4:
    puVar7 = (undefined *)
             WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar11,
                      &WPP_94719a13e7d8366cd9a87695c567288d_Traceguids,uVar10);
  }
  if (local_58 != (uint *)0x0) {
    puVar7 = (undefined *)ExFreePoolWithTag(local_58,0);
  }
  uVar17 = local_res20;
LAB_14001b80a:
  if ((*(longlong *)(puVar6 + 0x1b0) != 0) || (uVar17 != 0)) {
    uVar12 = 1;
  }
  return CONCAT71((int7)((ulonglong)puVar7 >> 8),uVar12);
}



===== wil_RtlStagingConfig_QueryFeatureState @ 14001b838 =====

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



===== ConvertSiloStringToSiloID @ 14001b904 =====

undefined8 ConvertSiloStringToSiloID(longlong param_1,uint param_2,longlong param_3)

{
  char cVar1;
  byte bVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  char cVar6;
  int iVar7;
  ulonglong uVar8;
  char cVar9;
  
  uVar8 = (ulonglong)param_2;
  if ((param_1 == 0) || (param_3 == 0)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
              &WPP_caa29ff4fe803fdfa287e005371d076d_Traceguids);
    }
  }
  else {
    if (param_2 < 9) {
      pcVar5 = (char *)(param_3 + 3);
      pcVar3 = (char *)(param_1 + -2 + uVar8 * 2);
      do {
        iVar7 = (int)uVar8;
        if (iVar7 == 0) {
          return 0;
        }
        cVar1 = *pcVar3;
        cVar6 = '\0';
        cVar9 = cVar1 + -0x20;
        if (0x19 < (byte)(cVar1 + 0x9fU)) {
          cVar9 = cVar1;
        }
        pcVar4 = pcVar3 + -2;
        uVar8 = (ulonglong)(iVar7 - 1U);
        if (iVar7 - 1U != 0) {
          cVar1 = *pcVar4;
          cVar6 = cVar1 + -0x20;
          if (0x19 < (byte)(cVar1 + 0x9fU)) {
            cVar6 = cVar1;
          }
          pcVar4 = pcVar3 + -4;
          uVar8 = (ulonglong)(iVar7 - 2);
          if (9 < (byte)(cVar6 - 0x30U)) {
            if (5 < (byte)(cVar6 + 0xbfU)) {
              return 0xc000000d;
            }
            cVar6 = cVar6 + -0x37;
          }
        }
        bVar2 = cVar9 - 0x30;
        if (9 < bVar2) {
          if (5 < (byte)(cVar9 + 0xbfU)) {
            return 0xc000000d;
          }
          bVar2 = cVar9 - 0x37;
        }
        *pcVar5 = cVar6 * '\x10' + bVar2;
        pcVar5 = pcVar5 + -1;
        pcVar3 = pcVar4;
      } while( true );
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                &WPP_caa29ff4fe803fdfa287e005371d076d_Traceguids,param_2,8);
    }
  }
  return 0xc000000d;
}



===== PolicyIsSiloBlocked @ 14001ba44 =====

byte PolicyIsSiloBlocked(void *param_1,undefined8 param_2,void *param_3,uint param_4)

{
  int iVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  ulonglong uVar5;
  
  bVar2 = 1;
  if ((param_4 & 3) == 0) {
    uVar5 = 0;
    do {
      bVar3 = 0;
      if (bVar2 == 0) break;
      iVar1 = memcmp(param_1,&TrustedSiloIdentifiers + uVar5 * 4,4);
      uVar4 = (int)uVar5 + 1;
      uVar5 = (ulonglong)uVar4;
      bVar2 = bVar2 & -(iVar1 != 0);
      bVar3 = bVar2;
    } while (uVar4 == 0);
    for (; (3 < param_4 && (bVar3 != 0)); bVar3 = bVar3 & -(iVar1 != 0)) {
      iVar1 = memcmp(param_1,param_3,4);
      param_3 = (void *)((longlong)param_3 + 4);
      param_4 = param_4 - 4;
    }
  }
  else {
    bVar3 = 0;
  }
  return bVar3;
}



===== PolicyReadSiloAllowList @ 14001baec =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PolicyReadSiloAllowList(char *param_1,longlong *param_2,int *param_3)

{
  uint uVar1;
  code *pcVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined2 uVar5;
  longlong lVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined1 auStack_378 [32];
  undefined8 local_358;
  int *local_350;
  longlong local_348;
  int local_340 [2];
  wchar_t local_338 [8];
  ulonglong local_328 [2];
  wchar_t *local_318;
  ulonglong local_310;
  undefined8 local_308;
  undefined8 uStack_300;
  undefined8 local_2f8;
  undefined8 uStack_2f0;
  undefined1 local_2e8 [8];
  undefined4 local_2e0;
  wchar_t *local_2d8;
  int *local_2d0;
  undefined4 local_2c8;
  undefined1 local_278 [8];
  uint local_270;
  short local_26c [274];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_378;
  iVar9 = 0;
  *param_1 = '\0';
  *param_2 = 0;
  local_328[0] = (ulonglong)(uint)local_328[0];
  local_310 = (ulonglong)(uint)local_310;
  local_348 = 0;
  local_338[0] = L'\0';
  local_338[1] = L'\0';
  local_338[2] = L'\0';
  local_338[3] = L'\0';
  local_338[4] = L'\0';
  local_338[5] = L'\0';
  local_338[6] = L'\0';
  local_338[7] = L'\0';
  local_340[0] = 0;
  lVar3 = 0;
  *param_3 = 0;
  RtlInitUnicodeString
            (local_338,
             L"\\Registry\\Machine\\Software\\Policies\\Microsoft\\Windows\\EnhancedStorageDevices\\ApprovedSilos"
            );
  local_318 = local_338;
  local_328[0] = 0x30;
  local_310 = 0x240;
  local_328[1] = 0;
  local_308 = 0;
  uStack_300 = 0;
  uVar1 = ZwOpenKey(&local_348,0x20019,local_328);
  lVar6 = local_348;
  if ((-1 < (int)uVar1) && (local_348 != 0)) {
    memset(local_2e8,0,0x70);
    local_2e0 = 0x124;
    local_2d8 = L"SiloAllowListPolicy";
    local_2d0 = local_340;
    local_2c8 = 0x4000000;
    local_2f8 = 0;
    uStack_2f0 = 0;
    RtlInitUnicodeString(&local_2f8,L"RtlQueryRegistryValuesEx");
    pcVar2 = (code *)MmGetSystemRoutineAddress(&local_2f8);
    local_358 = 0;
    if (pcVar2 == (code *)0x0) {
      pcVar2 = RtlQueryRegistryValues_exref;
    }
    uVar1 = (*pcVar2)(0x40000000,lVar6,local_2e8,0);
    if ((-1 < (int)uVar1) && (local_340[0] != 0)) {
      *param_1 = '\x01';
    }
    ZwClose(local_348);
    local_348 = 0;
  }
  if (*param_1 == '\0') {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      uVar5 = 0xc;
LAB_14001bc9a:
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,
              &WPP_caa29ff4fe803fdfa287e005371d076d_Traceguids);
    }
  }
  else if (-1 < (int)uVar1) {
    RtlInitUnicodeString
              (local_338,
               L"\\Registry\\Machine\\Software\\Policies\\Microsoft\\Windows\\EnhancedStorageDevices\\ApprovedSilos\\List"
              );
    local_318 = local_338;
    local_328[0] = 0x30;
    local_310 = 0x240;
    local_328[1] = 0;
    local_308 = 0;
    uStack_300 = 0;
    uVar1 = ZwOpenKey(&local_348,0x20019,local_328);
    if (-1 < (int)uVar1) {
      if (local_348 == 0) {
        return;
      }
      local_340[1] = 0;
      iVar8 = 0;
      iVar7 = 0;
      while (-1 < (int)uVar1) {
        memset(local_278,0,0x22a);
        local_350 = local_340 + 1;
        local_358 = CONCAT44(local_358._4_4_,0x229);
        uVar1 = ZwEnumerateValueKey(local_348,iVar8,0,local_278);
        if (uVar1 == 0x8000001a) {
          uVar1 = 0;
          if (iVar7 == 0) {
            if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
               ((byte)WPP_GLOBAL_Control[0x29] < 3)) goto LAB_14001bf0c;
            uVar5 = 0xd;
            uVar1 = 0;
            goto LAB_14001bc9a;
          }
          lVar3 = ExAllocatePool2(0x100,iVar7 * 4,0x47536353);
          uVar1 = ~-(uint)(lVar3 != 0) & 0xc0000017;
          break;
        }
        if ((-1 < (int)uVar1) && (local_270 < 9)) {
          iVar7 = iVar7 + 1;
        }
        iVar8 = iVar8 + 1;
      }
      iVar7 = 0;
      while (-1 < (int)uVar1) {
        memset(local_278,0,0x22a);
        local_350 = local_340 + 1;
        local_358 = CONCAT44(local_358._4_4_,0x229);
        uVar1 = ZwEnumerateValueKey(local_348,iVar9,0,local_278);
        if (uVar1 == 0x8000001a) {
          *param_2 = lVar3;
          uVar1 = 0;
          *param_3 = iVar7 * 4;
          break;
        }
        if (-1 < (int)uVar1) {
          lVar6 = -1;
          uVar1 = 0;
          do {
            lVar6 = lVar6 + 1;
          } while (local_26c[lVar6] != 0);
          uVar4 = ConvertSiloStringToSiloID
                            ((longlong)local_26c,(uint)lVar6,(ulonglong)(uint)(iVar7 * 4) + lVar3);
          if ((int)uVar4 < 0) {
            RtlInitUnicodeString(local_338);
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (2 < (byte)WPP_GLOBAL_Control[0x29])) {
              WPP_SF_Z(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                       &WPP_caa29ff4fe803fdfa287e005371d076d_Traceguids,local_338);
            }
          }
          else {
            iVar7 = iVar7 + 1;
          }
        }
        iVar9 = iVar9 + 1;
      }
      ZwClose(local_348);
      local_348 = 0;
    }
  }
LAB_14001bf0c:
  if (local_348 != 0) {
    ZwClose(local_348);
    local_348 = 0;
  }
  if ((int)uVar1 < 0) {
    if (lVar3 != 0) {
      ExFreePoolWithTag(lVar3,0);
    }
    *param_2 = 0;
    *param_3 = 0;
  }
  return;
}



===== ChildDeviceCreate @ 14001bf80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint ChildDeviceCreate(undefined8 param_1,int param_2,uint param_3,byte param_4,longlong *param_5)

{
  longlong lVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  longlong lVar5;
  ulonglong uVar6;
  undefined8 *puVar7;
  undefined2 uVar8;
  undefined8 uVar9;
  uint uVar10;
  char *pcVar11;
  wchar_t *pwVar12;
  undefined *puVar13;
  undefined8 uVar14;
  undefined1 auStack_398 [32];
  longlong local_340;
  longlong local_338;
  wchar_t local_330 [8];
  ulonglong local_320;
  undefined8 local_318;
  undefined8 local_310;
  undefined8 uStack_308;
  undefined8 local_300;
  code *pcStack_2f8;
  undefined8 local_2f0;
  undefined8 uStack_2e8;
  longlong local_2e0;
  undefined8 uStack_2d8;
  undefined *local_2d0;
  undefined8 *local_2c8;
  longlong *local_2c0;
  undefined8 local_2b8;
  longlong local_2b0;
  code *local_2a8;
  code *local_2a0;
  code *local_298;
  undefined4 local_288;
  undefined8 local_284;
  undefined1 local_27b;
  code *local_260;
  code *local_258;
  undefined4 local_228;
  undefined4 local_224;
  code *local_1f0;
  code *local_1e0;
  code *local_1c8;
  undefined8 local_198;
  undefined8 uStack_190;
  undefined8 local_188;
  undefined8 uStack_180;
  undefined8 local_178;
  undefined8 uStack_170;
  undefined4 local_168;
  undefined4 uStack_164;
  undefined4 uStack_160;
  undefined4 uStack_15c;
  wchar_t local_158 [4];
  undefined8 *puStack_150;
  undefined *local_148;
  wchar_t awStack_140 [28];
  char local_108 [128];
  char local_88 [64];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_398;
  local_340 = 0;
  local_2c0 = param_5;
  local_320 = CONCAT44(local_320._4_4_,param_2);
  local_2d0 = (undefined *)((ulonglong)local_2d0 & 0xffffffff00000000);
  local_224 = 0;
  local_300 = 0;
  pcStack_2f8 = (code *)0x0;
  local_2f0 = 0;
  uStack_2e8 = 0;
  local_2e0 = 0;
  uStack_2d8 = 0;
  local_318 = param_1;
  memset(&local_228,0,0x8c);
  memset(&local_288,0,0x60);
  local_338 = 0;
  puVar7 = (undefined8 *)0x0;
  local_2c8 = (undefined8 *)0x0;
  local_198 = 0;
  uStack_190 = 0;
  local_188 = 0;
  uStack_180 = 0;
  local_178 = 0;
  uStack_170 = 0;
  local_310 = 0;
  uStack_308 = 0;
  local_330[0] = L'\0';
  local_330[1] = L'\0';
  local_330[2] = L'\0';
  local_330[3] = L'\0';
  local_330[4] = L'\0';
  local_330[5] = L'\0';
  local_330[6] = L'\0';
  local_330[7] = L'\0';
  LogEvent("CCreate",param_1,(ulonglong)param_3,(ulonglong)param_4);
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FILTER_DEVICE_EXTENSION_TYPE_INFO_140016018);
  if (param_2 - 2U < 2) {
    local_340 = (**(code **)(WdfFunctions_01015 + 0x690))(WdfDriverGlobals,param_1);
    if (local_340 == 0) {
      uVar4 = 0xc000009a;
    }
    else {
      (**(code **)(WdfFunctions_01015 + 0x210))(WdfDriverGlobals,local_340,0x46);
      (**(code **)(WdfFunctions_01015 + 0x230))(WdfDriverGlobals,local_340,0x180,0);
      (**(code **)(WdfFunctions_01015 + 0x1f0))(WdfDriverGlobals,local_340,0);
      uVar4 = (**(code **)(WdfFunctions_01015 + 0x6d0))
                        (WdfDriverGlobals,local_340,&GUID_ENHANCED_STORAGE_CLASS);
      if (-1 < (int)uVar4) {
        uVar4 = (**(code **)(WdfFunctions_01015 + 0x220))
                          (WdfDriverGlobals,local_340,&SDDL_DEVOBJ_SYS_ALL_ADM_RWX_WORLD_R_RES_R);
        if (-1 < (int)uVar4) {
          (**(code **)(WdfFunctions_01015 + 0x1f8))(WdfDriverGlobals);
          uVar10 = 0;
          do {
            if (2 < uVar10) break;
            pcVar11 = (char *)0x0;
            memset(local_108,0,0x80);
            bVar2 = false;
            if (param_2 == 2) {
              RtlStringCbCopyA(local_108,pcVar11,"IEEE1667\\Control");
            }
            else {
              pcVar11 = (char *)0x80;
              RtlStringCbPrintfA(local_108,0x80,"IEEE1667\\Silo_%x",(ulonglong)param_3);
            }
            uVar4 = *(uint *)(*(longlong *)(lVar5 + 0x178) + 0xc);
            if ((uVar4 == 0) || (*(uint *)(*(longlong *)(lVar5 + 0x178) + 4) <= uVar4)) {
              if (uVar10 != 2) goto LAB_14001c25b;
              bVar2 = true;
            }
            else {
              RtlStringCbCatA(local_108,pcVar11,0x14001410c);
              lVar1 = *(longlong *)(lVar5 + 0x178);
              AppendFieldTrailingWhitespaceRemoved
                        (local_108,pcVar11,(char *)((ulonglong)*(uint *)(lVar1 + 0xc) + lVar1),
                         (ulonglong)(*(int *)(lVar1 + 4) - *(uint *)(lVar1 + 0xc)));
LAB_14001c25b:
              if (uVar10 < 2) {
                uVar4 = *(uint *)(*(longlong *)(lVar5 + 0x178) + 0x10);
                if ((uVar4 != 0) && (uVar4 < *(uint *)(*(longlong *)(lVar5 + 0x178) + 4))) {
                  RtlStringCbCatA(local_108,pcVar11,0x140014114);
                  lVar1 = *(longlong *)(lVar5 + 0x178);
                  AppendFieldTrailingWhitespaceRemoved
                            (local_108,pcVar11,(char *)((ulonglong)*(uint *)(lVar1 + 0x10) + lVar1),
                             (ulonglong)(*(int *)(lVar1 + 4) - *(uint *)(lVar1 + 0x10)));
                  goto LAB_14001c2b3;
                }
                if (uVar10 != 1) goto LAB_14001c2b3;
LAB_14001c315:
                bVar2 = true;
              }
              else {
LAB_14001c2b3:
                pcVar11 = (char *)0x1;
                if (uVar10 == 0) {
                  uVar4 = *(uint *)(*(longlong *)(lVar5 + 0x178) + 0x14);
                  if ((uVar4 == 0) || (*(uint *)(*(longlong *)(lVar5 + 0x178) + 4) <= uVar4))
                  goto LAB_14001c315;
                  RtlStringCbCatA(local_108,1,0x14001411c);
                  lVar1 = *(longlong *)(lVar5 + 0x178);
                  AppendFieldTrailingWhitespaceRemoved
                            (local_108,pcVar11,(char *)((ulonglong)*(uint *)(lVar1 + 0x14) + lVar1),
                             (ulonglong)(*(int *)(lVar1 + 4) - *(uint *)(lVar1 + 0x14)));
                }
              }
            }
            RtlInitAnsiString(&local_310,local_108);
            uVar3 = RtlAnsiStringToUnicodeString(local_330,&local_310,1);
            uVar4 = uVar3;
            if (-1 < (int)uVar3) {
              if (uVar10 == 0) {
                uVar4 = (**(code **)(WdfFunctions_01015 + 0x6a0))
                                  (WdfDriverGlobals,local_340,local_330);
                if (-1 < (int)uVar4) {
                  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
                    WPP_SF_Z(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
                             &WPP_4d5b31fc5b25398542187f229fa95b66_Traceguids,local_330);
                  }
                  goto LAB_14001c3bf;
                }
                if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                   ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14001c478;
                uVar8 = 0xb;
LAB_14001c465:
                WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar8,
                         &WPP_4d5b31fc5b25398542187f229fa95b66_Traceguids,uVar4);
              }
              else {
LAB_14001c3bf:
                if (!bVar2) {
                  uVar4 = (**(code **)(WdfFunctions_01015 + 0x6b0))
                                    (WdfDriverGlobals,local_340,local_330);
                  if ((int)uVar4 < 0) {
                    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                      uVar8 = 0xd;
                      goto LAB_14001c465;
                    }
                  }
                  else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                          (3 < (byte)WPP_GLOBAL_Control[0x29])) {
                    WPP_SF_Z(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                             &WPP_4d5b31fc5b25398542187f229fa95b66_Traceguids,local_330);
                  }
                }
              }
            }
LAB_14001c478:
            if (-1 < (int)uVar3) {
              RtlFreeUnicodeString(local_330);
            }
            uVar10 = uVar10 + 1;
          } while (-1 < (int)uVar4);
          puVar7 = local_2c8;
          param_2 = (int)local_320;
        }
      }
      uVar10 = 0;
      if (-1 < (int)uVar4) {
        do {
          if (1 < uVar10) goto LAB_14001c617;
          uVar9 = 0;
          memset(local_108,0,0x80);
          if (param_2 == 2) {
            if (uVar10 != 0) break;
            pcVar11 = "IEEE1667_CONTROL";
LAB_14001c50c:
            RtlStringCbCopyA(local_108,uVar9,pcVar11);
          }
          else {
            if (uVar10 != 0) {
              pcVar11 = "IEEE1667_RAWSILO";
              goto LAB_14001c50c;
            }
            RtlStringCbPrintfA(local_108,0x80,"IEEE1667Silo_%x",(ulonglong)param_3);
          }
          RtlInitAnsiString(&local_310,local_108);
          uVar3 = RtlAnsiStringToUnicodeString(local_330,&local_310,1);
          uVar4 = uVar3;
          if (-1 < (int)uVar3) {
            uVar4 = (**(code **)(WdfFunctions_01015 + 0x6b8))(WdfDriverGlobals,local_340,local_330);
            if ((int)uVar4 < 0) {
              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                         &WPP_4d5b31fc5b25398542187f229fa95b66_Traceguids,uVar4);
              }
            }
            else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                    (3 < (byte)WPP_GLOBAL_Control[0x29])) {
              WPP_SF_Z(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                       &WPP_4d5b31fc5b25398542187f229fa95b66_Traceguids,local_330);
            }
          }
          if (-1 < (int)uVar3) {
            RtlFreeUnicodeString(local_330);
          }
          uVar10 = uVar10 + 1;
        } while (-1 < (int)uVar4);
        if (-1 < (int)uVar4) {
LAB_14001c617:
          local_320 = 0;
          memset(local_108,0,0x80);
          memset(local_88,0,0x40);
          uVar4 = *(uint *)(*(longlong *)(lVar5 + 0x178) + 0x18);
          if (uVar4 != 0) {
            RtlStringCbPrintfA(local_108,0x80,"%s&",*(longlong *)(lVar5 + 0x178) + (ulonglong)uVar4)
            ;
          }
          uVar9 = 0x40;
          if (param_2 == 2) {
            RtlStringCbPrintfA(local_88,0x40,"%01x&Control",(ulonglong)*(byte *)(lVar5 + 0x177));
          }
          else {
            RtlStringCbPrintfA(local_88,0x40,"%01x&%x_%x",(ulonglong)*(byte *)(lVar5 + 0x177));
          }
          RtlStringCbCatA(local_108,uVar9,(longlong)local_88);
          pcVar11 = local_108;
          RtlInitAnsiString(&local_310);
          uVar4 = RtlStringLengthWorkerA(local_108,pcVar11,(longlong *)&local_320);
          if ((int)uVar4 < 0) {
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
                       &WPP_4d5b31fc5b25398542187f229fa95b66_Traceguids,uVar4);
            }
LAB_14001c772:
            if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
               ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14001c981;
            uVar8 = 0x11;
          }
          else {
            uVar6 = 0;
            if (local_320 != 0) {
              do {
                if (local_108[uVar6] == ' ') {
                  local_108[uVar6] = '_';
                }
                uVar6 = uVar6 + 1;
              } while (uVar6 < local_320);
            }
            uVar4 = RtlAnsiStringToUnicodeString(local_330,&local_310,1);
            if ((int)uVar4 < 0) goto LAB_14001c772;
            pwVar12 = local_330;
            uVar4 = (**(code **)(WdfFunctions_01015 + 0x6a8))(WdfDriverGlobals,local_340);
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (3 < (byte)WPP_GLOBAL_Control[0x29])) {
              pwVar12 = L"ㇼ䵛嬥㦅ᡂ≿ꦟ晛Silo command";
              WPP_SF_Z(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
                       &WPP_4d5b31fc5b25398542187f229fa95b66_Traceguids,local_330);
            }
            RtlFreeUnicodeString(local_330);
            if ((int)uVar4 < 0) {
              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                WPP_SF_sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,pwVar12,local_108,
                          (char)uVar4);
              }
              goto LAB_14001c981;
            }
            builtin_wcsncpy(local_158,L"{000",4);
            puStack_150 = (undefined8 *)0x30003000300030;
            builtin_wcsncpy(awStack_140,L"00-0000-ffff-fffffff",0x14);
            local_148 = (undefined *)0x300030002d0030;
            builtin_wcsncpy(awStack_140 + 0x14,L"fffff}",7);
            RtlInitUnicodeString(local_330,local_158);
            uVar4 = (**(code **)(WdfFunctions_01015 + 0xc38))(WdfDriverGlobals,local_340,local_330);
            if (-1 < (int)uVar4) {
              memset(&local_228,0,0x90);
              local_1e0 = ChildDeviceEvtSelfManagedIoInit;
              local_1f0 = ChildDeviceEvtSelfManagedIoCleanup;
              local_1c8 = ChildDeviceEvtSurpriseRemoval;
              local_228 = 0x90;
              (**(code **)(WdfFunctions_01015 + 0x1b8))(WdfDriverGlobals,local_340,&local_228);
              goto LAB_14001c981;
            }
            if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
               ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14001c981;
            uVar8 = 0x14;
          }
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar8,
                   &WPP_4d5b31fc5b25398542187f229fa95b66_Traceguids,uVar4);
        }
      }
    }
  }
  else {
    uVar4 = 0xc000000d;
  }
LAB_14001c981:
  (**(code **)(WdfFunctions_01015 + 0xc40))(WdfDriverGlobals,local_340);
  if ((int)uVar4 < 0) {
LAB_14001ca47:
    uVar9 = local_318;
  }
  else {
    local_2f0 = 0;
    local_2d0 = PTR__WDF_CHILD_DEVICE_EXTENSION_TYPE_INFO_1400160b8;
    pcStack_2f8 = ChildDeviceEvtCleanup;
    local_2e0 = 0;
    uStack_2d8 = 0;
    local_300 = 0x38;
    uStack_2e8 = 0x300000002;
    uVar4 = (**(code **)(WdfFunctions_01015 + 600))
                      (WdfDriverGlobals,&local_340,&local_300,&local_338);
    if ((int)uVar4 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
                 &WPP_4d5b31fc5b25398542187f229fa95b66_Traceguids,uVar4);
      }
      goto LAB_14001ca47;
    }
    puVar13 = PTR__WDF_CHILD_DEVICE_EXTENSION_TYPE_INFO_1400160b8;
    puVar7 = (undefined8 *)
             (**(code **)(WdfFunctions_01015 + 0x650))
                       (WdfDriverGlobals,local_338,
                        PTR__WDF_CHILD_DEVICE_EXTENSION_TYPE_INFO_1400160b8);
    uVar9 = local_318;
    *(byte *)(puVar7 + 0x10) = param_4;
    *puVar7 = local_318;
    uVar14 = CONCAT71((int7)((ulonglong)puVar13 >> 8),1);
    *(int *)(puVar7 + 6) = param_2;
    *(uint *)((longlong)puVar7 + 0x7c) = param_3;
    uVar4 = RtlAnsiStringToUnicodeString(puVar7 + 0x11,&local_310);
    if ((int)uVar4 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,uVar14,local_108,(char)uVar4);
      }
    }
    else {
      uStack_170 = 0xffffffffffffffff;
      local_198 = 0x200000030;
      local_178 = 0x200000002;
      uStack_190 = 0x100000002;
      uStack_180 = 0x100000002;
      local_188 = CONCAT44((uint)(*(int *)(*(longlong *)(lVar5 + 0x178) + 0x18) != 0),2);
      (**(code **)(WdfFunctions_01015 + 0x298))(WdfDriverGlobals,local_338,&local_198);
    }
  }
  local_2d0 = (undefined *)0x0;
  local_2f0 = 0;
  uStack_2e8 = 0x100000001;
  pcStack_2f8 = (code *)0x0;
  local_300 = 0x38;
  uStack_2d8 = 0;
  local_2e0 = local_338;
  if (-1 < (int)uVar4) {
    local_2a8 = _guard_check_icall;
    local_2b8 = 0x10028;
    local_2a0 = _guard_check_icall;
    local_298 = ChildDeviceGetLocationString;
    puStack_150 = &local_2b8;
    local_148 = &GUID_PNP_LOCATION_INTERFACE;
    local_2b0 = local_338;
    local_158[0] = L'0';
    local_158[1] = L'\0';
    local_158[2] = L'\0';
    local_158[3] = L'\0';
    awStack_140[0] = L'\0';
    awStack_140[1] = L'\0';
    awStack_140[2] = L'\0';
    awStack_140[3] = L'\0';
    awStack_140[8] = L'\0';
    awStack_140[9] = L'\0';
    awStack_140[10] = L'\0';
    awStack_140[0xb] = L'\0';
    awStack_140[4] = L'\0';
    awStack_140[5] = L'\0';
    awStack_140[6] = L'\0';
    awStack_140[7] = L'\0';
    uVar4 = (**(code **)(WdfFunctions_01015 + 0x720))(WdfDriverGlobals,local_338,local_158);
    if (-1 < (int)uVar4) {
      memset(&local_288,0,0x60);
      local_260 = ChildDeviceEvtIoDeviceControl;
      local_288 = 0x60;
      local_258 = ChildDeviceEvtIoInternalDeviceControl;
      local_27b = 1;
      local_284 = 1;
      uVar4 = (**(code **)(WdfFunctions_01015 + 0x4c0))
                        (WdfDriverGlobals,local_338,&local_288,&local_300);
      if ((int)uVar4 < 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar8 = 0x17;
          goto LAB_14001cda4;
        }
      }
      else {
        uVar4 = CreateProxyRequest(&local_300,puVar7 + 4);
        if ((-1 < (int)uVar4) &&
           (uVar4 = CreateProxyRequest(&local_300,puVar7 + 5), -1 < (int)uVar4)) {
          uVar4 = (**(code **)(WdfFunctions_01015 + 0x5d8))
                            (WdfDriverGlobals,*(undefined8 *)(lVar5 + 0x1a0),
                             *(undefined8 *)(puVar7[4] + 8),0x70000);
          if ((int)uVar4 < 0) {
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              uVar8 = 0x18;
LAB_14001cda4:
              WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar8,
                       &WPP_4d5b31fc5b25398542187f229fa95b66_Traceguids,uVar4);
            }
          }
          else {
            uVar4 = (**(code **)(WdfFunctions_01015 + 0x600))
                              (WdfDriverGlobals,&local_300,0x200,0x47536353);
            if ((int)uVar4 < 0) {
              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
                          &WPP_4d5b31fc5b25398542187f229fa95b66_Traceguids,1,(char)uVar4);
              }
            }
            else {
              uVar4 = (**(code **)(WdfFunctions_01015 + 0x9c0))
                                (WdfDriverGlobals,&local_300,puVar7 + 0xc);
              if ((((int)uVar4 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
                 (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                uVar8 = 0x1a;
                goto LAB_14001cda4;
              }
            }
          }
        }
      }
    }
  }
  if (param_2 == 2) {
    local_168 = 0x4f40006f;
    uStack_164 = 0x4550b933;
    uStack_160 = 0x582b32b5;
    uStack_15c = 0xd314e6ce;
  }
  else {
    local_168 = 0x7c2bcf57;
    uStack_164 = 0x46da2bea;
    uStack_160 = 0xfd7826ad;
    uStack_15c = 0x46ee3cc8;
  }
  if (-1 < (int)uVar4) {
    uVar4 = (**(code **)(WdfFunctions_01015 + 0x268))(WdfDriverGlobals,local_338,&local_168,0);
    if ((int)uVar4 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar8 = 0x1b;
LAB_14001cf3c:
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar8,
                 &WPP_4d5b31fc5b25398542187f229fa95b66_Traceguids,uVar4);
      }
    }
    else {
      uVar4 = (**(code **)(WdfFunctions_01015 + 0x428))(WdfDriverGlobals,uVar9,local_338);
      if (-1 < (int)uVar4) goto LAB_14001cf9c;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar8 = 0x1c;
        goto LAB_14001cf3c;
      }
    }
  }
  if (local_340 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x1b0))(WdfDriverGlobals);
  }
  if (local_338 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
    local_338 = 0;
  }
LAB_14001cf9c:
  if (local_2c0 != (longlong *)0x0) {
    *local_2c0 = local_338;
  }
  return uVar4;
}



===== ChildDeviceEvtSelfManagedIoCleanup @ 14001cfe0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void ChildDeviceEvtSelfManagedIoCleanup(longlong param_1)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined1 auStack_58 [32];
  undefined1 local_38;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  local_28 = 0;
  uStack_20 = 0;
  puVar1 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_CHILD_DEVICE_EXTENSION_TYPE_INFO_1400160b8);
  LogEvent("CStop",*puVar1,(ulonglong)*(uint *)((longlong)puVar1 + 0x7c),0);
  if (*(int *)(puVar1 + 6) == 2) {
    uVar2 = 0x4f40006f;
    uVar3 = 0x4550b933;
    uVar4 = 0x582b32b5;
    uVar5 = 0xd314e6ce;
  }
  else {
    if (*(int *)(puVar1 + 6) != 3) goto LAB_14001d064;
    uVar2 = 0x7c2bcf57;
    uVar3 = 0x46da2bea;
    uVar4 = 0xfd7826ad;
    uVar5 = 0x46ee3cc8;
  }
  local_28 = CONCAT44(uVar3,uVar2);
  uStack_20 = CONCAT44(uVar5,uVar4);
LAB_14001d064:
  local_38 = 0;
  (**(code **)(WdfFunctions_01015 + 0x270))(WdfDriverGlobals,param_1,&local_28);
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,puVar1[0xc],0);
  if (puVar1[3] != 0) {
    (**(code **)(WdfFunctions_01015 + 0x550))(WdfDriverGlobals);
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,puVar1[3]);
    puVar1[3] = 0;
    LogEvent("CClosTgt",*puVar1,(ulonglong)*(uint *)((longlong)puVar1 + 0x7c),0);
  }
  (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,puVar1[0xc]);
  if (puVar1[2] != 0) {
    IoUnregisterPlugPlayNotificationEx();
    puVar1[2] = 0;
  }
  IoctlRedirectionRemoveTargetDevice(param_1);
  *(undefined4 *)((longlong)puVar1 + 0x84) = 0;
  FilterDeviceRecalcAggregatedSiloCaps(*puVar1);
  return;
}



===== ChildDeviceEvtSelfManagedIoInit @ 14001d180 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int ChildDeviceEvtSelfManagedIoInit(undefined8 param_1)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined1 auStack_68 [32];
  code *local_48;
  undefined8 local_40;
  undefined8 *local_38;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  iVar1 = 0;
  puVar2 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_CHILD_DEVICE_EXTENSION_TYPE_INFO_1400160b8);
  local_28 = 0;
  uStack_20 = 0;
  LogEvent("CStart",*puVar2,(ulonglong)*(uint *)((longlong)puVar2 + 0x7c),0);
  if (*(int *)(puVar2 + 6) == 2) {
    uVar4 = 0x4f40006f;
    uVar5 = 0x4550b933;
    uVar6 = 0x582b32b5;
    uVar7 = 0xd314e6ce;
LAB_14001d205:
    local_28 = CONCAT44(uVar5,uVar4);
    uStack_20 = CONCAT44(uVar7,uVar6);
  }
  else {
    if (*(int *)(puVar2 + 6) == 3) {
      uVar4 = 0x7c2bcf57;
      uVar5 = 0x46da2bea;
      uVar6 = 0xfd7826ad;
      uVar7 = 0x46ee3cc8;
      goto LAB_14001d205;
    }
    iVar1 = -0x3ffffbe0;
  }
  local_48 = (code *)CONCAT71(local_48._1_7_,1);
  (**(code **)(WdfFunctions_01015 + 0x270))(WdfDriverGlobals,param_1,&local_28,0);
  if (-1 < iVar1) {
    if (*(int *)(puVar2 + 6) == 3) {
      uVar3 = (**(code **)(WdfFunctions_01015 + 0x138))(WdfDriverGlobals,param_1);
      uVar3 = (**(code **)(WdfFunctions_01015 + 0x3b0))(WdfDriverGlobals,uVar3);
      local_38 = puVar2 + 2;
      local_48 = ChildDevicePnpNotifyInterfaceChange;
      local_40 = param_1;
      iVar1 = IoRegisterPlugPlayNotification(2,0,&local_28,uVar3);
      if (iVar1 < 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
                   &WPP_4d5b31fc5b25398542187f229fa95b66_Traceguids,iVar1);
        }
        goto LAB_14001d302;
      }
    }
    iVar1 = ChildDeviceCreateIoTarget(param_1);
    if (-1 < iVar1) {
      return iVar1;
    }
  }
LAB_14001d302:
  if (puVar2[2] != 0) {
    IoUnregisterPlugPlayNotificationEx();
    puVar2[2] = 0;
  }
  return iVar1;
}



===== ChildDeviceEvtSurpriseRemoval @ 14001d350 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ChildDeviceEvtSurpriseRemoval(undefined8 param_1)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_CHILD_DEVICE_EXTENSION_TYPE_INFO_1400160b8);
  LogEvent("CSurpRmv",*puVar1,(ulonglong)*(uint *)((longlong)puVar1 + 0x7c),0);
  return;
}



===== ChildDeviceGetLocationString @ 14001d3a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong ChildDeviceGetLocationString(undefined8 param_1,undefined8 *param_2)

{
  char cVar1;
  wchar_t *pwVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  ulonglong local_res8;
  
  cVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_CHILD_DEVICE_EXTENSION_TYPE_INFO_1400160b8);
  *param_2 = 0;
  pwVar2 = (wchar_t *)ExAllocatePool2(0x100,0x100);
  if (pwVar2 == (wchar_t *)0x0) {
    uVar3 = 0xc000009a;
  }
  else {
    uVar4 = RtlStringCchPrintfExW
                      (pwVar2,0x80,(longlong *)0x0,&local_res8,0x200,L"%wZ",cVar1 + -0x78);
    *param_2 = pwVar2;
    uVar3 = uVar4 & 0xffffffff;
    if (-1 < (int)uVar4) {
      uVar3 = 0x120;
    }
  }
  return uVar3;
}



===== CompareRedirectionTableEntries @ 14001d460 =====

ulonglong CompareRedirectionTableEntries(uint *param_1,uint *param_2)

{
  if (*param_1 < *param_2) {
    return 0xffffffff;
  }
  return (ulonglong)(*param_2 < *param_1);
}



===== SwapRedirectionTableEntries @ 14001d480 =====

void SwapRedirectionTableEntries(undefined8 *param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  uVar1 = param_2[1];
  uVar2 = *param_1;
  uVar3 = param_1[1];
  *param_1 = *param_2;
  param_1[1] = uVar1;
  *param_2 = uVar2;
  param_2[1] = uVar3;
  return;
}



===== AppendFieldTrailingWhitespaceRemoved @ 14001d498 =====

void AppendFieldTrailingWhitespaceRemoved
               (char *param_1,char *param_2,char *param_3,ulonglong param_4)

{
  int iVar1;
  longlong *plVar2;
  char *pcVar3;
  char *pcVar4;
  longlong local_res10 [3];
  
  pcVar4 = (char *)0x0;
  if (*param_3 != '\0') {
    param_2 = param_3;
    pcVar3 = (char *)0x0;
    do {
      pcVar4 = pcVar3;
      if ((param_4 & 0xffffffff) <= (ulonglong)((longlong)param_2 - (longlong)param_3)) break;
      pcVar4 = param_2 + (1 - (longlong)param_3);
      if (*param_2 == ' ') {
        pcVar4 = pcVar3;
      }
      param_2 = param_2 + 1;
      pcVar3 = pcVar4;
    } while (*param_2 != '\0');
  }
  local_res10[0] = 0;
  plVar2 = local_res10;
  iVar1 = RtlStringValidateDestAndLengthA(param_1,param_2,plVar2);
  if ((-1 < iVar1) && (pcVar4 < (char *)0x7fffffff)) {
    RtlStringCopyWorkerA
              (param_1 + local_res10[0],0x80 - local_res10[0],plVar2,(longlong)param_3,
               (longlong)pcVar4);
  }
  return;
}



===== CreateProxyRequest @ 14001d52c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int CreateProxyRequest(undefined8 param_1,longlong *param_2)

{
  int iVar1;
  undefined2 uVar2;
  undefined8 local_res18;
  
  local_res18 = 0;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x600))
                    (WdfDriverGlobals,param_1,0x200,0x47536353,0xf0,&local_res18,param_2);
  if (iVar1 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
                &WPP_3cd491e07ee83ecda6dcbf116627806f_Traceguids,0xf0,(char)iVar1);
    }
  }
  else {
    memset((void *)*param_2,0,0xf0);
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x9c0))(WdfDriverGlobals,param_1,*param_2);
    if (iVar1 < 0) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return iVar1;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
        return iVar1;
      }
      uVar2 = 0xb;
    }
    else {
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x7b8))(WdfDriverGlobals,param_1,0,*param_2 + 8);
      if (iVar1 < 0) {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return iVar1;
        }
        if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
          return iVar1;
        }
        uVar2 = 0xc;
      }
      else {
        iVar1 = (**(code **)(WdfFunctions_01015 + 0x608))
                          (WdfDriverGlobals,param_1,&TempChar,1,*param_2 + 0x10);
        if (iVar1 < 0) {
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return iVar1;
          }
          if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
            return iVar1;
          }
          uVar2 = 0xd;
        }
        else {
          iVar1 = (**(code **)(WdfFunctions_01015 + 0x608))
                            (WdfDriverGlobals,param_1,&TempChar,1,*param_2 + 0x18);
          if (-1 < iVar1) {
            return iVar1;
          }
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return iVar1;
          }
          if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
            return iVar1;
          }
          uVar2 = 0xe;
        }
      }
    }
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar2,
             &WPP_3cd491e07ee83ecda6dcbf116627806f_Traceguids,iVar1);
  }
  return iVar1;
}



===== FilterDeviceKsrCallback @ 14001d770 =====

void FilterDeviceKsrCallback(undefined8 param_1,int param_2)

{
  if (param_2 == 0) {
    KsrShutdown = 1;
    FilterDeviceKsrSaveContext();
  }
  else {
    if (param_2 == 1) {
      KsrShutdown = 0;
    }
    else {
      if (param_2 != 2) {
        return;
      }
      KsrShutdown = 0;
      if (KsrCachedContext != 0) {
        ExFreePoolWithTag(KsrCachedContext,0);
        KsrCachedContext = 0;
      }
    }
    KsrFreePersistedMemory(&GUID_ENHANCED_STORAGE_CLASS_KSR_CONTEXT,1);
  }
  return;
}



===== FilterDeviceKsrSaveContext @ 14001d7e4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int FilterDeviceKsrSaveContext(void)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  longlong lVar4;
  longlong lVar5;
  undefined4 *puVar6;
  longlong lVar7;
  uint uVar8;
  uint uVar9;
  undefined4 *puVar10;
  undefined4 local_res8 [2];
  undefined8 local_res10;
  undefined8 local_res18 [2];
  
  local_res18[0] = 0;
  uVar8 = 0;
  local_res8[0] = 0;
  uVar9 = 0;
  local_res10 = 0;
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x3b0))(WdfDriverGlobals,*WdfDriverGlobals);
  lVar5 = *(longlong *)(lVar5 + 8);
  if (lVar5 != 0) {
    do {
      uVar3 = (**(code **)(WdfFunctions_01015 + 0xf0))(WdfDriverGlobals,lVar5);
      lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                        (WdfDriverGlobals,uVar3,PTR__WDF_FILTER_DEVICE_EXTENSION_TYPE_INFO_140016018
                        );
      if (((lVar4 != 0) && (*(longlong *)(lVar4 + 0x218) != 0)) &&
         (uVar1 = *(uint *)(lVar4 + 0x220), uVar1 != 0)) {
        uVar9 = uVar9 + 1;
        if (uVar1 <= uVar8) {
          uVar1 = uVar8;
        }
        uVar8 = uVar1;
      }
      lVar5 = *(longlong *)(lVar5 + 0x10);
    } while (lVar5 != 0);
    if (uVar9 != 0) {
      uVar8 = uVar8 + 0x210;
      lVar5 = MmAllocatePagesForMdlEx
                        (0,0xffffffffffffffff,0,
                         (ulonglong)(uVar8 * uVar9) + 0x1027 & 0xfffffffffffff000,1,0x24);
      if (lVar5 == 0) {
        return -0x3fffff66;
      }
      puVar6 = (undefined4 *)MmMapLockedPagesSpecifyCache(lVar5,0,1,0,0,0x40000020);
      if (puVar6 == (undefined4 *)0x0) {
        iVar2 = -0x3fffff66;
      }
      else {
        iVar2 = KsrMdlToMemoryRuns(lVar5,&local_res10,1,local_res8);
        if ((-1 < iVar2) &&
           (iVar2 = KsrPersistMemory(&GUID_ENHANCED_STORAGE_CLASS_KSR_CONTEXT,&local_res10,
                                     local_res8[0],local_res18), -1 < iVar2)) {
          *puVar6 = 0x46494c4b;
          puVar6[1] = 0x28;
          *(undefined8 *)(puVar6 + 8) = 0x28;
          *(ulonglong *)(puVar6 + 2) = (ulonglong)(uVar8 * uVar9) + 0x28;
          puVar10 = puVar6 + 10;
          *(ulonglong *)(puVar6 + 4) = (ulonglong)uVar9;
          *(ulonglong *)(puVar6 + 6) = (ulonglong)uVar8;
          lVar4 = (**(code **)(WdfFunctions_01015 + 0x3b0))(WdfDriverGlobals,*WdfDriverGlobals);
          for (lVar4 = *(longlong *)(lVar4 + 8); lVar4 != 0; lVar4 = *(longlong *)(lVar4 + 0x10)) {
            uVar3 = (**(code **)(WdfFunctions_01015 + 0xf0))(WdfDriverGlobals,lVar4);
            lVar7 = (**(code **)(WdfFunctions_01015 + 0x650))
                              (WdfDriverGlobals,uVar3,
                               PTR__WDF_FILTER_DEVICE_EXTENSION_TYPE_INFO_140016018);
            if (((lVar7 != 0) && (*(longlong *)(lVar7 + 0x218) != 0)) &&
               (*(int *)(lVar7 + 0x220) != 0)) {
              FilterDeviceKsrSaveDeviceContext(uVar3,puVar10);
              puVar10 = (undefined4 *)((longlong)puVar10 + (ulonglong)uVar8);
            }
          }
        }
        MmUnmapLockedPages(puVar6,lVar5);
      }
      ExFreePoolWithTag(lVar5,0);
      return iVar2;
    }
  }
  return -0x3ffffff2;
}



===== IoctlDeviceEnumeratePdos @ 14001da90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint IoctlDeviceEnumeratePdos(longlong param_1,byte param_2,undefined8 param_3)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  longlong *plVar5;
  longlong lVar6;
  longlong lVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  longlong lVar10;
  uint *local_res20;
  longlong local_68;
  longlong local_60;
  longlong local_50;
  longlong local_48;
  
  local_60 = 0;
  local_res20 = (uint *)0x0;
  local_68 = 0;
  local_48 = 0;
  plVar5 = (longlong *)0x0;
  LogEvent("EnumPdo",(ulonglong)param_2,0,0);
  local_50 = (**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals,param_3);
  if (param_2 != 0) {
    local_60 = param_1;
    plVar5 = (longlong *)
             (**(code **)(WdfFunctions_01015 + 0x650))
                       (WdfDriverGlobals,param_1,PTR__WDF_CHILD_DEVICE_EXTENSION_TYPE_INFO_1400160b8
                       );
    param_1 = *plVar5;
  }
  uVar4 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_3,4,&local_res20,0);
  lVar10 = 0;
  if ((int)uVar4 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
               &WPP_6b540f47682e3482637f60efce621d01_Traceguids,uVar4);
    }
  }
  else {
    uVar1 = *local_res20;
    if ((uVar1 == 0x100) || (uVar1 - 1 < 3)) {
      local_res20 = (uint *)0x0;
      if ((uVar1 == 0x100) || (uVar1 == 1)) {
        uVar4 = 1;
      }
      else {
        (**(code **)(WdfFunctions_01015 + 0x430))(WdfDriverGlobals,param_1);
        lVar6 = (**(code **)(WdfFunctions_01015 + 0x438))(WdfDriverGlobals,param_1,0,1);
        uVar4 = 0;
        if (lVar6 != 0) {
          do {
            lVar7 = (**(code **)(WdfFunctions_01015 + 0x650))
                              (WdfDriverGlobals,lVar6,
                               PTR__WDF_CHILD_DEVICE_EXTENSION_TYPE_INFO_1400160b8);
            uVar3 = uVar4 + 1;
            if (*(uint *)(lVar7 + 0x30) != uVar1) {
              uVar3 = uVar4;
            }
            uVar4 = uVar3;
            lVar6 = (**(code **)(WdfFunctions_01015 + 0x438))(WdfDriverGlobals,param_1,lVar6,1);
          } while (lVar6 != 0);
        }
        (**(code **)(WdfFunctions_01015 + 0x440))(WdfDriverGlobals,param_1);
        if (uVar4 == 0) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
                     &WPP_6b540f47682e3482637f60efce621d01_Traceguids,uVar1);
          }
          uVar4 = 0xc0000225;
          goto LAB_14001dedd;
        }
      }
      lVar10 = (ulonglong)uVar4 * 0x420 + 4;
      if ((*(uint *)(local_50 + 0x10) & 0x40) == 0) {
        uVar4 = 0x80000005;
      }
      else {
        uVar4 = (**(code **)(WdfFunctions_01015 + 0x870))
                          (WdfDriverGlobals,param_3,lVar10,&local_res20,&local_68);
        puVar2 = local_res20;
        uVar9 = (ulonglong)uVar4;
        if ((int)uVar4 < 0) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
                    &WPP_6b540f47682e3482637f60efce621d01_Traceguids);
          }
          local_res20 = (uint *)0x0;
          lVar10 = local_48;
        }
        else {
          lVar10 = 4;
          local_68 = local_68 + -4;
          local_res20 = (uint *)0x0;
          if ((uVar1 == 1) || (uVar1 == 0x100)) {
            *puVar2 = 1;
            uVar4 = 1;
            if (param_2 != 0) {
              if (uVar1 == 0x100) {
                uVar4 = *(uint *)(plVar5 + 6);
                param_1 = local_60;
              }
              else {
                uVar4 = uVar1;
              }
            }
            uVar9 = FillEnumPdoEntry((undefined1 *)(puVar2 + 1),param_1,uVar4);
            uVar4 = (uint)uVar9;
            if (-1 < (int)uVar4) {
              lVar10 = 0x424;
              local_68 = local_68 + -0x420;
              goto LAB_14001dedd;
            }
          }
          else {
            *puVar2 = 0;
            (**(code **)(WdfFunctions_01015 + 0x430))(WdfDriverGlobals,param_1);
            local_60 = (**(code **)(WdfFunctions_01015 + 0x438))(WdfDriverGlobals,param_1,0,1);
            do {
              uVar4 = (uint)uVar9;
              if (local_60 == 0) break;
              lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))
                                (WdfDriverGlobals,local_60,
                                 PTR__WDF_CHILD_DEVICE_EXTENSION_TYPE_INFO_1400160b8);
              if (*(uint *)(lVar6 + 0x30) == uVar1) {
                uVar8 = FillEnumPdoEntry((undefined1 *)(puVar2 + (ulonglong)*puVar2 * 0x108 + 1),
                                         local_60,uVar1);
                uVar9 = uVar8 & 0xffffffff;
                if (-1 < (int)uVar8) {
                  *puVar2 = *puVar2 + 1;
                  lVar10 = lVar10 + 0x420;
                  local_68 = local_68 + -0x420;
                }
              }
              local_60 = (**(code **)(WdfFunctions_01015 + 0x438))
                                   (WdfDriverGlobals,param_1,local_60,1);
              uVar4 = (uint)uVar9;
            } while (-1 < (int)uVar4);
            (**(code **)(WdfFunctions_01015 + 0x440))(WdfDriverGlobals,param_1);
            if (-1 < (int)uVar4) {
              if (*puVar2 != 0) goto LAB_14001dedd;
              uVar4 = 0xc0000225;
            }
          }
          lVar10 = 0;
        }
      }
      goto LAB_14001dedd;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
               &WPP_6b540f47682e3482637f60efce621d01_Traceguids,uVar1);
    }
    uVar4 = 0xc000000d;
  }
  local_res20 = (uint *)0x0;
LAB_14001dedd:
  (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,param_3,uVar4,lVar10);
  return uVar4;
}



===== FillEnumPdoEntry @ 14001df64 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FillEnumPdoEntry(undefined1 *param_1,undefined8 param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  undefined8 *puVar3;
  longlong lVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined1 auStack_78 [48];
  longlong local_48;
  undefined8 local_40;
  undefined8 uStack_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_78;
  local_48 = 0;
  local_40 = 0;
  uStack_38 = 0;
  memset(param_1,0,0x420);
  uVar5 = (**(code **)(WdfFunctions_01015 + 0x108))(WdfDriverGlobals,param_2);
  if (param_3 == 1) {
    uVar7 = 0x53f56307;
    uVar8 = 0x11d0b6bf;
    uVar9 = 0xa000f294;
    uVar10 = 0x8bfb1ec9;
LAB_14001e02b:
    puVar3 = &local_40;
    local_40 = CONCAT44(uVar8,uVar7);
    uStack_38 = CONCAT44(uVar10,uVar9);
    uVar1 = IoGetDeviceInterfaces(puVar3,uVar5,0,&local_48);
    uVar6 = (ulonglong)uVar1;
    if ((int)uVar1 < 0) goto LAB_14001e053;
  }
  else {
    if (param_3 == 2) {
      uVar7 = 0x4f40006f;
      uVar8 = 0x4550b933;
      uVar9 = 0x582b32b5;
      uVar10 = 0xd314e6ce;
      goto LAB_14001e02b;
    }
    if (param_3 == 3) {
      uVar7 = 0x7c2bcf57;
      uVar8 = 0x46da2bea;
      uVar9 = 0xfd7826ad;
      uVar10 = 0x46ee3cc8;
      goto LAB_14001e02b;
    }
    uVar6 = 0xc000000d;
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_14001e1cb;
    if (1 < (byte)WPP_GLOBAL_Control[0x29]) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
               &WPP_6b540f47682e3482637f60efce621d01_Traceguids,param_3);
    }
LAB_14001e053:
    puVar3 = (undefined8 *)WPP_GLOBAL_Control;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      puVar3 = *(undefined8 **)(WPP_GLOBAL_Control + 0x18);
      WPP_SF_D(puVar3,0xb,&WPP_6b540f47682e3482637f60efce621d01_Traceguids,(int)uVar6);
    }
    if ((int)uVar6 < 0) goto LAB_14001e1cb;
  }
  if (local_48 == 0) {
LAB_14001e0b9:
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x158))(WdfDriverGlobals,param_2);
    param_1[1] = (iVar2 != 0x119) + '\x01';
    *param_1 = (char)param_3;
    if (param_3 == 3) {
      puVar3 = (undefined8 *)
               (**(code **)(WdfFunctions_01015 + 0x650))
                         (WdfDriverGlobals,param_2,
                          PTR__WDF_CHILD_DEVICE_EXTENSION_TYPE_INFO_1400160b8);
      if (puVar3 == (undefined8 *)0x0) {
        uVar6 = 0xc000000d;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                  &WPP_6b540f47682e3482637f60efce621d01_Traceguids);
        }
      }
      else {
        lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                          (WdfDriverGlobals,*puVar3,
                           PTR__WDF_FILTER_DEVICE_EXTENSION_TYPE_INFO_140016018);
        *(undefined4 *)(param_1 + 4) = *(undefined4 *)((longlong)puVar3 + 0x7c);
        param_1[8] = *(undefined1 *)(puVar3 + 0xf);
        param_1[9] = *(undefined1 *)((longlong)puVar3 + 0x79);
        param_1[10] = *(undefined1 *)((longlong)puVar3 + 0x7a);
        param_1[0xb] = *(undefined1 *)((longlong)puVar3 + 0x7b);
        param_1[2] = *(undefined1 *)(lVar4 + 300);
      }
    }
  }
  else {
    uVar5 = 0x209;
    lVar4 = local_48;
    uVar6 = RtlStringValidateDestW(puVar3,0x209);
    uVar1 = (uint)uVar6;
    uVar6 = uVar6 & 0xffffffff;
    if ((int)uVar1 < 0) {
      *(undefined2 *)(param_1 + 0xc) = 0;
    }
    else {
      uVar1 = RtlStringCopyWorkerW((short *)(param_1 + 0xc),uVar5,lVar4,lVar4);
      uVar6 = (ulonglong)uVar1;
      if (-1 < (int)uVar1) goto LAB_14001e0b9;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
               &WPP_6b540f47682e3482637f60efce621d01_Traceguids,uVar1);
    }
  }
LAB_14001e1cb:
  if (local_48 != 0) {
    ExFreePoolWithTag(local_48,0);
  }
  return uVar6;
}



===== FilterDeviceEvtUsageNotification @ 14001e210 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FilterDeviceEvtUsageNotification(undefined8 param_1,int param_2,char param_3)

{
  longlong lVar1;
  uint uVar2;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FILTER_DEVICE_EXTENSION_TYPE_INFO_140016018);
  if (param_2 == 2) {
    if (param_3 == '\0') {
      uVar2 = *(uint *)(lVar1 + 0x130) & 0xffffff7f;
    }
    else {
      uVar2 = *(uint *)(lVar1 + 0x130) | 0x80;
    }
    *(uint *)(lVar1 + 0x130) = uVar2;
  }
  return;
}



===== FilterDeviceDiscoverPdoCaps @ 14001e278 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

bool FilterDeviceDiscoverPdoCaps(undefined8 param_1)

{
  int iVar1;
  longlong lVar2;
  uint uVar3;
  undefined8 uVar4;
  
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  if (**(longlong **)(lVar2 + 0x1b8) != 0) {
    (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals);
  }
  uVar4 = 0;
  iVar1 = IssueZeroLengthSecurityProtocolIn
                    (*(undefined8 *)(lVar2 + 0x198),*(longlong *)(lVar2 + 0x1b8),'\0',
                     *(char *)(lVar2 + 0x180));
  uVar4 = CONCAT71((int7)((ulonglong)uVar4 >> 8),1);
  uVar3 = *(uint *)(lVar2 + 300) | 2;
  if (iVar1 < 0) {
    uVar3 = *(uint *)(lVar2 + 300) & 0xfffffffd;
  }
  *(uint *)(lVar2 + 300) = uVar3;
  iVar1 = IssueZeroLengthSecurityProtocolIn
                    (*(undefined8 *)(lVar2 + 0x198),*(longlong *)(lVar2 + 0x1b8),'\x01',
                     *(char *)(lVar2 + 0x180));
  uVar3 = *(uint *)(lVar2 + 300) | 1;
  if (iVar1 < 0) {
    uVar3 = *(uint *)(lVar2 + 300) & 0xfffffffe;
  }
  *(uint *)(lVar2 + 300) = uVar3;
  if (**(longlong **)(lVar2 + 0x1b8) != 0) {
    (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals);
  }
  uVar3 = *(uint *)(lVar2 + 300);
  if (((byte)uVar3 & 3) == 3) {
    uVar3 = uVar3 & 0xfffffffd;
    *(uint *)(lVar2 + 300) = uVar3;
  }
  if ((Microsoft_Windows_EnhancedStorage_ClassDriverEnableBits & 1) != 0) {
    McTemplateK0quuuju_EtwWriteTransfer
              ((ulonglong)CONCAT31((int3)(uVar3 >> 8),*(undefined1 *)(lVar2 + 0x175)),lVar2 + 0x160,
               uVar4,(uint)*(byte *)(lVar2 + 0x174),*(undefined1 *)(lVar2 + 0x175),
               *(undefined1 *)(lVar2 + 0x176),*(undefined1 *)(lVar2 + 0x177),lVar2 + 0x160,
               *(undefined1 *)(lVar2 + 300));
  }
  return (uVar3 & 3) != 0;
}



===== WppLoadTracingSupport @ 14001e3e8 =====

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



===== FindStringInMultiSz @ 14001e52c =====

undefined1 FindStringInMultiSz(undefined8 *param_1,undefined8 param_2)

{
  int iVar1;
  longlong lVar2;
  short sVar3;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  longlong lStack_10;
  
  local_18 = *param_1;
  lVar2 = param_1[1];
  local_28 = 0;
  uStack_20 = 0;
  sVar3 = (short)local_18;
  lStack_10 = lVar2;
  while( true ) {
    if (sVar3 == 0) {
      return 0;
    }
    RtlInitUnicodeString(&local_28,lVar2);
    iVar1 = RtlCompareUnicodeString(&local_28,param_2,1);
    if (iVar1 == 0) break;
    lVar2 = lVar2 + (ulonglong)((ushort)local_28 >> 1) * 2 + 2;
    sVar3 = sVar3 + (-2 - (ushort)local_28);
  }
  return 1;
}



===== DriverEvtDeviceAdd @ 14001e5e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int DriverEvtDeviceAdd(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  void *_Dst;
  undefined8 uVar4;
  undefined2 uVar5;
  ulonglong *puVar6;
  ushort uVar7;
  undefined8 local_res10;
  undefined1 local_res18 [8];
  undefined1 local_res20 [8];
  undefined8 in_stack_fffffffffffffe20;
  longlong *plVar8;
  undefined4 uVar10;
  ulonglong uVar9;
  longlong local_1c0;
  int local_1b8 [2];
  undefined8 local_1b0;
  code *pcStack_1a8;
  undefined8 local_1a0;
  undefined8 uStack_198;
  undefined8 local_190;
  undefined8 uStack_188;
  undefined *local_180;
  ulonglong local_178;
  undefined8 local_170;
  longlong lStack_168;
  undefined4 local_158;
  undefined8 local_154;
  undefined1 local_14b;
  code *local_148;
  code *local_130;
  code *local_128;
  code *local_110;
  undefined4 local_108;
  undefined8 local_f8;
  undefined *local_f0;
  undefined8 local_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined4 local_c8;
  undefined4 local_c4;
  code *local_c0;
  code *local_b0;
  code *local_90;
  code *local_88;
  code *local_80;
  code *local_68;
  code *local_50;
  
  uVar10 = (undefined4)((ulonglong)in_stack_fffffffffffffe20 >> 0x20);
  local_180 = (undefined *)((ulonglong)local_180 & 0xffffffff00000000);
  local_c4 = 0;
  iVar2 = 0;
  local_1b0 = 0;
  pcStack_1a8 = (code *)0x0;
  local_1a0 = 0;
  uStack_198 = 0;
  local_190 = 0;
  uStack_188 = 0;
  local_res10 = param_2;
  memset(&local_c8,0,0x8c);
  memset(&local_158,0,0x60);
  local_1c0 = 0;
  _Dst = (void *)0x0;
  local_e0 = 0;
  uStack_d8 = 0;
  LogEvent("FDevAddE",0,0,0);
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x3e0))(WdfDriverGlobals,local_res10);
  if (DisableEhstorSupport != '\0') {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
              &WPP_7186403ff6ae38c3a7435fda3b62a1f7_Traceguids);
    }
    goto LAB_14001f1b2;
  }
  if ((EnableNativeOpalSupport == '\0') && (ForceNativeOpalSupport == '\0')) {
    plVar8 = &local_1c0;
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x3f8))(WdfDriverGlobals,local_res10,2,0x200,0,plVar8)
    ;
    uVar10 = (undefined4)((ulonglong)plVar8 >> 0x20);
    if (iVar2 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                 &WPP_7186403ff6ae38c3a7435fda3b62a1f7_Traceguids,iVar2);
      }
    }
    else {
      puVar6 = &local_178;
      local_178 = 0;
      local_170 = 0;
      lStack_168 = 0;
      lStack_168 = (**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,local_1c0);
      if ((local_178 - 1 < 0xffff) && ((local_178 & 1) == 0)) {
        uVar7 = (short)local_178 - 2;
        local_170 = CONCAT62(CONCAT42(local_170._4_4_,(short)local_178),uVar7);
        if (*(short *)(lStack_168 + ((ulonglong)uVar7 & 0xfffe)) == 0) {
          RtlInitUnicodeString(&local_e0,L"Disk1667");
          cVar1 = FindStringInMultiSz(&local_170,&local_e0);
          if (cVar1 == '\0') {
            iVar2 = -0x3fffffff;
          }
          goto LAB_14001e857;
        }
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                  &WPP_7186403ff6ae38c3a7435fda3b62a1f7_Traceguids);
        }
      }
      else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_P(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,puVar6,local_178);
      }
      iVar2 = -0x3fffffff;
    }
LAB_14001e857:
    if (local_1c0 != 0) {
      (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
      local_1c0 = 0;
    }
    if (iVar2 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                &WPP_7186403ff6ae38c3a7435fda3b62a1f7_Traceguids);
      }
      iVar2 = 0;
      goto LAB_14001f1b2;
    }
  }
  (**(code **)(WdfFunctions_01015 + 0x408))(WdfDriverGlobals);
  if (-1 < iVar2) {
    memset(&local_c8,0,0x90);
    local_80 = FilterDeviceEvtSelfManagedIoInit;
    local_90 = FilterDeviceEvtSelfManagedIoCleanup;
    local_88 = FilterDeviceEvtSelfManagedIoFlush;
    local_c0 = FilterDeviceEvtD0Entry;
    local_b0 = FilterDeviceEvtD0Exit;
    local_50 = FilterDeviceEvtUsageNotification;
    local_68 = FilterDeviceEvtSurpriseRemoval;
    local_c8 = 0x90;
    (**(code **)(WdfFunctions_01015 + 0x1b8))(WdfDriverGlobals,local_res10,&local_c8);
    local_res18[0] = 2;
    uVar4 = CONCAT44(uVar10,1);
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x248))
                      (WdfDriverGlobals,local_res10,FilterDeviceEvtWdmPowerIrpPreprocess,0x16,
                       local_res18,uVar4);
    if (iVar2 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar5 = 0xf;
        goto LAB_14001ed45;
      }
    }
    else {
      local_res20[0] = 0;
      uVar9 = CONCAT44((int)((ulonglong)uVar4 >> 0x20),1);
      iVar2 = (**(code **)(WdfFunctions_01015 + 0x248))
                        (WdfDriverGlobals,local_res10,FilterDeviceEvtWdmPnpIrpPreprocess,0x1b,
                         local_res20,uVar9);
      if (iVar2 < 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar5 = 0x10;
          goto LAB_14001ed45;
        }
      }
      else {
        uVar9 = uVar9 & 0xffffffff00000000;
        iVar2 = (**(code **)(WdfFunctions_01015 + 0x248))
                          (WdfDriverGlobals,local_res10,FilterDeviceEvtWdmIoctlIrpPreprocess,0xe,0,
                           uVar9);
        if (iVar2 < 0) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar5 = 0x11;
            goto LAB_14001ed45;
          }
        }
        else {
          uVar9 = uVar9 & 0xffffffff00000000;
          iVar2 = (**(code **)(WdfFunctions_01015 + 0x248))
                            (WdfDriverGlobals,local_res10,FilterDeviceEvtWdmIoctlIrpPreprocess,0xf,0
                             ,uVar9);
          if (iVar2 < 0) {
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              uVar5 = 0x12;
              goto LAB_14001ed45;
            }
          }
          else {
            uVar9 = uVar9 & 0xffffffff00000000;
            iVar2 = (**(code **)(WdfFunctions_01015 + 0x248))
                              (WdfDriverGlobals,local_res10,FilterDeviceEvtWdmIoctlIrpPreprocess,3,0
                               ,uVar9);
            if (iVar2 < 0) {
              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                uVar5 = 0x13;
                goto LAB_14001ed45;
              }
            }
            else {
              iVar2 = (**(code **)(WdfFunctions_01015 + 0x248))
                                (WdfDriverGlobals,local_res10,FilterDeviceEvtWdmIoctlIrpPreprocess,4
                                 ,0,uVar9 & 0xffffffff00000000);
              if (iVar2 < 0) {
                if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                  uVar5 = 0x14;
                  goto LAB_14001ed45;
                }
              }
              else {
                local_180 = PTR__WDF_REQUEST_CONTEXT_TYPE_INFO_140016108;
                pcStack_1a8 = RequestEvtCleanup;
                local_1b0 = 0x38;
                local_1a0 = 0;
                local_190 = 0;
                uStack_188 = 0;
                uStack_198 = 0x100000001;
                (**(code **)(WdfFunctions_01015 + 0x240))(WdfDriverGlobals,local_res10,&local_1b0);
                (**(code **)(WdfFunctions_01015 + 0x250))
                          (WdfDriverGlobals,local_res10,FilterDeviceEvtIoInCallerContext);
                local_180 = PTR__WDF_FILTER_DEVICE_EXTENSION_TYPE_INFO_140016018;
                local_1b0 = 0x38;
                pcStack_1a8 = FilterDeviceEvtCleanup;
                local_1a0 = 0;
                local_190 = 0;
                uStack_188 = 0;
                uStack_198 = 0x100000001;
                iVar2 = (**(code **)(WdfFunctions_01015 + 600))
                                  (WdfDriverGlobals,&local_res10,&local_1b0);
                if (iVar2 < 0) {
                  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                     (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                    uVar5 = 0x15;
                    goto LAB_14001ed45;
                  }
                }
                else {
                  _Dst = (void *)(**(code **)(WdfFunctions_01015 + 0x650))
                                           (WdfDriverGlobals,0,
                                            PTR__WDF_FILTER_DEVICE_EXTENSION_TYPE_INFO_140016018);
                  memset(_Dst,0,0x238);
                  *(undefined4 *)((longlong)_Dst + 0x14) = 0x114;
                  iVar2 = RtlGetVersion();
                  if (((iVar2 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
                     (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                    uVar5 = 0x16;
LAB_14001ed45:
                    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,
                             &WPP_7186403ff6ae38c3a7435fda3b62a1f7_Traceguids,iVar2);
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  local_180 = (undefined *)0x0;
  local_1a0 = 0;
  uStack_198 = 0x100000001;
  pcStack_1a8 = (code *)0x0;
  local_1b0 = 0x38;
  uStack_188 = 0;
  local_190 = 0;
  if (iVar2 < 0) {
LAB_14001f18c:
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14001f1b2;
    uVar5 = 0x20;
  }
  else {
    local_1b8[0] = 0;
    local_f0 = &DEVPKEY_Device_InstanceId;
    local_f8 = 0x18;
    local_e8 = 0;
    iVar2 = (**(code **)(WdfFunctions_01015 + 0xd90))
                      (WdfDriverGlobals,0,&local_f8,0x200,&local_1b0,&local_1c0,local_1b8);
    if (iVar2 < 0) goto LAB_14001f18c;
    if (local_1b8[0] == 0x12) {
      uVar4 = (**(code **)(WdfFunctions_01015 + 0x610))
                        (WdfDriverGlobals,local_1c0,(longlong)_Dst + 0x230);
      *(undefined8 *)((longlong)_Dst + 0x228) = uVar4;
    }
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x9d8))(WdfDriverGlobals,&local_1b0,_Dst);
    if (((iVar2 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
               &WPP_7186403ff6ae38c3a7435fda3b62a1f7_Traceguids,iVar2);
    }
    *(undefined4 *)((longlong)_Dst + 8) = 0;
    *(undefined1 *)((longlong)_Dst + 0xc) = 0;
    *(undefined4 *)((longlong)_Dst + 0x10) = 0;
    *(undefined1 *)((longlong)_Dst + 0x180) = 0;
    if (iVar2 < 0) goto LAB_14001f18c;
    uVar4 = (**(code **)(WdfFunctions_01015 + 0x150))(WdfDriverGlobals,0);
    *(undefined8 *)((longlong)_Dst + 0x198) = uVar4;
    iVar2 = CreateProxyRequest(&local_1b0,(longlong *)((longlong)_Dst + 0x1b8));
    if (iVar2 < 0) goto LAB_14001f18c;
    *(undefined8 *)((longlong)_Dst + 0x1c8) = 0;
    *(undefined4 *)((longlong)_Dst + 0x1d0) = 0;
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x9d8))
                      (WdfDriverGlobals,&local_1b0,(longlong)_Dst + 0x1e0);
    if (iVar2 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar5 = 0x18;
LAB_14001f17d:
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,
                 &WPP_7186403ff6ae38c3a7435fda3b62a1f7_Traceguids,iVar2);
      }
      goto LAB_14001f18c;
    }
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x9c0))
                      (WdfDriverGlobals,&local_1b0,(longlong)_Dst + 0x1d8);
    if (iVar2 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar5 = 0x19;
        goto LAB_14001f17d;
      }
      goto LAB_14001f18c;
    }
    *(uint *)((longlong)_Dst + 0x130) = *(uint *)((longlong)_Dst + 0x130) | 3;
    *(undefined8 *)((longlong)_Dst + 0x1e8) = 0;
    *(undefined8 *)((longlong)_Dst + 0x1f0) = 0;
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x9d8))
                      (WdfDriverGlobals,&local_1b0,(longlong)_Dst + 0x200);
    if (iVar2 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar5 = 0x1a;
        goto LAB_14001f17d;
      }
      goto LAB_14001f18c;
    }
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x9c0))
                      (WdfDriverGlobals,&local_1b0,(longlong)_Dst + 0x1f8);
    if (iVar2 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar5 = 0x1b;
        goto LAB_14001f17d;
      }
      goto LAB_14001f18c;
    }
    memset(&local_158,0,0x60);
    local_108 = 0xffffffff;
    local_148 = DefaultQueueEvtDefault;
    local_158 = 0x60;
    local_130 = DefaultQueueEvtDeviceControl;
    local_14b = 1;
    local_128 = DefaultQueueEvtInternalDeviceControl;
    local_110 = RequestEvtCanceledOnQueue;
    local_154 = 2;
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x4c0))
                      (WdfDriverGlobals,0,&local_158,0,(longlong)_Dst + 0x188);
    if (iVar2 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar5 = 0x1c;
        goto LAB_14001f17d;
      }
      goto LAB_14001f18c;
    }
    memset(&local_158,0,0x60);
    local_108 = 0xffffffff;
    local_148 = IoWaitQueueEvtDefault;
    local_158 = 0x60;
    local_130 = IoWaitQueueEvtIoDeviceControl;
    local_128 = IoWaitQueueEvtIoDeviceControl;
    local_110 = RequestEvtCanceledOnQueue;
    local_154 = 2;
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x4c0))
                      (WdfDriverGlobals,0,&local_158,0,(longlong)_Dst + 400);
    if (iVar2 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar5 = 0x1d;
        goto LAB_14001f17d;
      }
      goto LAB_14001f18c;
    }
    memset(&local_158,0,0x60);
    local_108 = 0xffffffff;
    local_130 = RedirectedIoctlQueueEvtIoDeviceControl;
    local_154 = 2;
    uStack_198 = CONCAT44(uStack_198._4_4_,2);
    local_158 = 0x60;
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x4c0))
                      (WdfDriverGlobals,0,&local_158,&local_1b0,
                       (undefined8 *)((longlong)_Dst + 0x1c0));
    if (iVar2 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar5 = 0x1e;
        goto LAB_14001f17d;
      }
      goto LAB_14001f18c;
    }
    (**(code **)(WdfFunctions_01015 + 0x4d8))
              (WdfDriverGlobals,*(undefined8 *)((longlong)_Dst + 0x1c0),0);
    *(uint *)((longlong)_Dst + 0x130) = *(uint *)((longlong)_Dst + 0x130) & 0xfffffeff;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 4)) goto LAB_14001f1b2;
    uVar5 = 0x1f;
  }
  WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,
           &WPP_7186403ff6ae38c3a7435fda3b62a1f7_Traceguids,uVar3);
LAB_14001f1b2:
  LogEvent("FDevAddX",0,(longlong)iVar2,0);
  return iVar2;
}



===== DriverEvtUnload @ 14001f2d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void DriverEvtUnload(undefined8 param_1)

{
  if (KsrCachedContext != 0) {
    ExFreePoolWithTag(KsrCachedContext,0);
    KsrCachedContext = 0;
  }
  if (KsrCallbackHandle != 0) {
    ExUnregisterCallback();
  }
  McGenEventUnregister_EtwUnregister();
  (**(code **)(WdfFunctions_01015 + 0x3b0))(WdfDriverGlobals,param_1);
  WppCleanupKm();
  wil_UninitializeFeatureStaging();
  return;
}



===== FilterDeviceReadControlSettings @ 140020008 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FilterDeviceReadControlSettings(void)

{
  int iVar1;
  int local_res8 [2];
  longlong local_res10;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  local_res10 = 0;
  local_28 = 0;
  uStack_20 = 0;
  RtlInitUnicodeString
            (&local_18,L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\EnhancedStorage\\"
            );
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x728))
                    (WdfDriverGlobals,0,&local_18,0x20019,0,&local_res10);
  if ((-1 < iVar1) && (local_res10 != 0)) {
    local_res8[0] = 0;
    RtlInitUnicodeString(&local_28,L"EnableNativeOpalSupport");
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x780))
                      (WdfDriverGlobals,local_res10,&local_28,local_res8);
    if (-1 < iVar1) {
      EnableNativeOpalSupport = local_res8[0] != 0;
    }
    local_res8[0] = 0;
    RtlInitUnicodeString(&local_28,L"ForceNativeOpalSupport");
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x780))
                      (WdfDriverGlobals,local_res10,&local_28,local_res8);
    if (-1 < iVar1) {
      ForceNativeOpalSupport = local_res8[0] != 0;
    }
    local_res8[0] = 0;
    RtlInitUnicodeString(&local_28,L"DisableEhstorSupport");
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x780))
                      (WdfDriverGlobals,local_res10,&local_28,local_res8);
    if (-1 < iVar1) {
      DisableEhstorSupport = local_res8[0] != 0;
    }
    local_res8[0] = 0;
    RtlInitUnicodeString(&local_28,L"EnableCryptoSanitizeTranslation");
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x780))
                      (WdfDriverGlobals,local_res10,&local_28,local_res8);
    if (-1 < iVar1) {
      EnableCryptoSanitizeTranslation = local_res8[0] != 0;
    }
    local_res8[0] = 0;
    RtlInitUnicodeString(&local_28,L"DisableScsiSenseFixup");
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x780))
                      (WdfDriverGlobals,local_res10,&local_28,local_res8);
    if (-1 < iVar1) {
      DisableScsiSenseFixup = local_res8[0] != 0;
    }
    local_res8[0] = 0;
    RtlInitUnicodeString(&local_28,L"DisablePowerDownDeauthentication");
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x780))
                      (WdfDriverGlobals,local_res10,&local_28,local_res8);
    if (-1 < iVar1) {
      DisablePowerDownDeauthentication = local_res8[0] != 0;
    }
    (**(code **)(WdfFunctions_01015 + 0x738))(WdfDriverGlobals,local_res10);
  }
  return;
}



===== FilterDeviceKsrInitialize @ 140020290 =====

void FilterDeviceKsrInitialize(void)

{
  int iVar1;
  ulonglong uVar2;
  longlong local_res8 [4];
  undefined8 local_48;
  undefined8 uStack_40;
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_30;
  undefined8 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res8[1] = 0;
  local_1c = 0;
  local_34 = 0;
  local_48 = 0;
  uStack_40 = 0;
  iVar1 = KsrGetFirmwareInformation(local_res8 + 1);
  if (-1 < iVar1) {
    local_res8[0] = 0;
    KsrEnumeratePersistedMemory
              (&GUID_ENHANCED_STORAGE_CLASS_KSR_CONTEXT,FilterDeviceKsrEnumeratePersistedMemory,
               local_res8);
    if ((local_res8[0] != 0) &&
       (uVar2 = FilterDeviceKsrRestoreContext(local_res8[0]), (int)uVar2 < 0)) {
      return;
    }
    RtlInitUnicodeString(&local_48,L"\\Callback\\SoftRestart");
    local_30 = 0;
    local_28 = &local_48;
    local_38 = 0x30;
    local_20 = 0x50;
    local_18 = 0;
    uStack_10 = 0;
    iVar1 = ExCreateCallback(&FilterDeviceKsrCallbackObject,&local_38,0,1);
    if (-1 < iVar1) {
      KsrCallbackHandle =
           ExRegisterCallback(FilterDeviceKsrCallbackObject,FilterDeviceKsrCallback,0);
    }
  }
  return;
}



===== __security_init_cookie @ 14002038c =====

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



===== wil_InitializeFeatureStaging @ 1400203c0 =====

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
    ppuVar4 = &Feature_2813562171__private_descriptor;
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



===== wil_details_PopulateInitialConfiguredFeatureStates @ 1400204b0 =====

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
  ppuVar3 = &Feature_2813562171__private_descriptor;
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



===== FilterDeviceKsrEnumeratePersistedMemory @ 1400205a0 =====

undefined8
FilterDeviceKsrEnumeratePersistedMemory(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  *param_3 = param_2;
  return 0;
}



===== FilterDeviceKsrRestoreContext @ 1400205b0 =====

ulonglong FilterDeviceKsrRestoreContext(undefined8 param_1)

{
  ulonglong uVar1;
  undefined8 *puVar2;
  void *_Src;
  ulonglong uVar3;
  undefined4 local_res10 [2];
  ulonglong local_res18;
  undefined4 uVar5;
  undefined4 *puVar4;
  
  local_res18 = 0;
  puVar4 = local_res10;
  local_res10[0] = 0;
  uVar1 = KsrClaimPersistedMemory
                    (&GUID_ENHANCED_STORAGE_CLASS_KSR_CONTEXT,param_1,&local_res18,1,1,puVar4);
  uVar5 = (undefined4)((ulonglong)puVar4 >> 0x20);
  uVar3 = uVar1 & 0xffffffff;
  if ((int)uVar1 < 0) {
    return uVar1;
  }
  puVar2 = (undefined8 *)ExAllocatePool2(0x40,(local_res18 >> 0x28) * 8 + 0x30,0x52534b53);
  if (puVar2 == (undefined8 *)0x0) {
    uVar3 = 0xc000009a;
  }
  else {
    *puVar2 = 0;
    uVar1 = 0;
    puVar2[4] = 0;
    *(undefined4 *)((longlong)puVar2 + 0x2c) = 0;
    *(undefined2 *)((longlong)puVar2 + 10) = 2;
    *(uint *)(puVar2 + 5) = (uint)(local_res18 >> 0x1c) & 0xfffff000;
    *(short *)(puVar2 + 1) = ((short)(local_res18 >> 0x28) + 6) * 8;
    if ((local_res18 & 0xffffff0000000000) != 0) {
      do {
        puVar2[uVar1 + 6] = (local_res18 & 0xffffffffff) + uVar1;
        uVar1 = uVar1 + 1;
      } while (uVar1 < local_res18 >> 0x28);
    }
    _Src = (void *)MmMapLockedPagesSpecifyCache(puVar2,0,1,0,0,CONCAT44(uVar5,0x40000020));
    if ((_Src == (void *)0x0) ||
       (KsrCachedContext =
             (void *)ExAllocatePool2(0x40,*(undefined8 *)((longlong)_Src + 8),0x52534b53),
       KsrCachedContext == (void *)0x0)) {
      uVar3 = 0xc000009a;
    }
    else {
      memmove(KsrCachedContext,_Src,*(size_t *)((longlong)_Src + 8));
    }
    ExFreePoolWithTag(puVar2,0);
  }
  return uVar3;
}



===== DriverEntry @ 14002074c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  ulonglong local_28;
  code *local_20;
  code *local_18;
  undefined8 local_10;
  
  _DAT_140017da8 = 1;
  _WPP_MAIN_CB = 0;
  local_28 = (ulonglong)(uint)local_28;
  DAT_140017d90 = 0;
  DAT_140017d88 = &WPP_ThisDir_CTLGUID_EhStorClass;
  _DAT_140017da0 = 0;
  WppLoadTracingSupport();
  _DAT_140017da0 = 0;
  WppInitKm();
  iVar1 = wil_InitializeFeatureStaging();
  if (((iVar1 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
     (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
             &WPP_9c8b80de206d39be6f8d74bf5c20b79d_Traceguids,iVar1);
  }
  local_28 = 0x20;
  local_20 = DriverEvtDeviceAdd;
  local_10 = 0;
  local_18 = DriverEvtUnload;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x3a0))(WdfDriverGlobals,param_1,param_2,0,&local_28,0);
  if (iVar1 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
               &WPP_9c8b80de206d39be6f8d74bf5c20b79d_Traceguids,iVar1);
    }
    wil_UninitializeFeatureStaging();
    WppCleanupKm();
  }
  else {
    iVar1 = RtlCheckRegistryKey(2,L"MiniNT");
    if (-1 < iVar1) {
      IsWinPE = 1;
    }
    iVar1 = 0;
    McGenEventRegister_EtwRegister();
    FilterDeviceKsrInitialize();
    FilterDeviceReadControlSettings();
    LogInit();
  }
  return iVar1;
}


