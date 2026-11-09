
===== ToppReceiveNetBufferListHandler @ 140001010 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ToppReceiveNetBufferListHandler
               (longlong param_1,undefined8 *param_2,undefined8 param_3,undefined8 param_4,
               byte param_5)

{
  int *piVar1;
  longlong lVar2;
  undefined8 *puVar3;
  uint uVar4;
  ushort uVar5;
  longlong lVar6;
  int iVar7;
  uint uVar8;
  byte bVar9;
  char *pcVar10;
  undefined8 *puVar11;
  undefined8 *puVar12;
  undefined1 auStack_a8 [32];
  uint local_88;
  undefined4 local_80;
  int local_78;
  uint local_74;
  longlong local_70;
  undefined8 *local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined4 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_a8;
  uVar8 = *(uint *)(param_1 + 0x34);
  bVar9 = param_5 & 1;
  puVar12 = (undefined8 *)0x0;
  if ((uVar8 & 0x40) == 0) {
    if ((char)uVar8 < '\0') {
      uVar4 = topActivePolicyFlags & 8;
    }
    else {
      uVar4 = topActivePolicyFlags & 4;
    }
  }
  else {
    uVar4 = topActivePolicyFlags & 2;
  }
  if ((uVar4 == 0) && ((uVar8 & 7) == 0)) {
    if (param_2 == (undefined8 *)0x0) {
      return;
    }
    puVar3 = (undefined8 *)0x0;
    puVar11 = param_2;
    do {
      param_2 = puVar3;
      lVar2 = puVar11[1];
      local_68 = (undefined8 *)*puVar11;
      local_60 = 0;
      uStack_58 = 0;
      lVar6 = *(longlong *)(lVar2 + 8);
      local_50 = 0;
      local_48 = 0;
      if ((uint)(*(int *)(lVar6 + 0x28) - *(int *)(lVar2 + 0x10)) < 0xe) {
LAB_1400014fc:
        if ((param_5 & 2) == 0) {
          if (param_2 == (undefined8 *)0x0) {
            param_2 = puVar11;
          }
          else {
            *puVar12 = puVar11;
          }
          *puVar11 = 0;
          puVar12 = puVar11;
        }
      }
      else {
        if ((*(byte *)(lVar6 + 10) & 5) == 0) {
          local_80 = 0x40000000;
          local_88 = 0;
          lVar6 = MmMapLockedPagesSpecifyCache(lVar6,0,1);
        }
        else {
          lVar6 = *(longlong *)(lVar6 + 0x18);
        }
        if (lVar6 == 0) goto LAB_1400014fc;
        uVar8 = *(uint *)(lVar2 + 0x10);
        local_70 = (ulonglong)uVar8 + lVar6;
        if (((local_70 == 0) ||
            (((*(byte *)(local_70 + 6) == 0xff &&
              ((((*(char *)(local_70 + 7) != -1 || (*(char *)(local_70 + 8) != -1)) ||
                (*(char *)(local_70 + 9) != -1)) ||
               ((*(char *)(local_70 + 10) != -1 || (*(char *)(local_70 + 0xb) == -1)))))) ||
             ((*(byte *)(local_70 + 6) & 1) != 0)))) ||
           ((*(int *)(local_70 + 8) == *(int *)(param_1 + 0x126) &&
            (*(short *)(local_70 + 6) == *(short *)(param_1 + 0x124))))) goto LAB_1400014fc;
        iVar7 = 0xe;
        uVar5 = *(ushort *)(local_70 + 0xc) >> 8 | *(ushort *)(local_70 + 0xc) << 8;
        if (uVar5 == 0x8100) {
          if (*(int *)(*(longlong *)(lVar2 + 8) + 0x28) - uVar8 < 0x12) goto LAB_1400014fc;
          iVar7 = 0x12;
          uVar5 = *(ushort *)(local_70 + 0x10) >> 8 | *(ushort *)(local_70 + 0x10) << 8;
        }
        if (uVar5 != 0x88d9) goto LAB_1400014fc;
        local_74 = *(uint *)(lVar2 + 0x28);
        local_78 = *(int *)(lVar2 + 0x18);
        if (uVar8 + iVar7 < *(uint *)(*(longlong *)(lVar2 + 8) + 0x28)) {
          *(uint *)(lVar2 + 0x10) = uVar8 + iVar7;
          *(uint *)(lVar2 + 0x28) = local_74 + iVar7;
          *(int *)(lVar2 + 0x18) = local_78 - iVar7;
        }
        else {
          NdisAdvanceNetBufferDataStart(lVar2,iVar7,0,0);
        }
        if (*(uint *)(lVar2 + 0x18) < 0x12) {
LAB_1400014c2:
          lVar6 = *(longlong *)(lVar2 + 0x20);
          *(int *)(lVar2 + 0x18) = local_78;
          *(uint *)(lVar2 + 0x28) = local_74;
          *(longlong *)(lVar2 + 8) = lVar6;
          *(uint *)(lVar2 + 0x10) = local_74;
          if ((lVar6 != 0) && (*(uint *)(lVar6 + 0x28) < local_74)) {
            NdisAdjustNetBufferCurrentMdl(lVar2);
          }
          goto LAB_1400014fc;
        }
        lVar6 = *(longlong *)(lVar2 + 8);
        if ((uint)(*(int *)(lVar6 + 0x28) - *(int *)(lVar2 + 0x10)) < 0x12) {
          local_88 = 0;
          pcVar10 = (char *)NdisGetDataBuffer(lVar2,0x12,&local_60);
          if (pcVar10 != (char *)0x0) {
            uVar8 = *(int *)(lVar2 + 0x10) + 0x12;
            if (uVar8 < *(uint *)(*(longlong *)(lVar2 + 8) + 0x28)) {
              *(int *)(lVar2 + 0x28) = *(int *)(lVar2 + 0x28) + 0x12;
              *(int *)(lVar2 + 0x18) = *(int *)(lVar2 + 0x18) + -0x12;
              *(uint *)(lVar2 + 0x10) = uVar8;
            }
            else {
              NdisAdvanceNetBufferDataStart(lVar2,0x12,0);
            }
            goto LAB_140001384;
          }
          goto LAB_1400014c2;
        }
        if ((*(byte *)(lVar6 + 10) & 5) == 0) {
          local_80 = 0x40000000;
          local_88 = 0;
          lVar6 = MmMapLockedPagesSpecifyCache(lVar6,0,1);
        }
        else {
          lVar6 = *(longlong *)(lVar6 + 0x18);
        }
        if (lVar6 == 0) {
          pcVar10 = (char *)0x0;
        }
        else {
          pcVar10 = (char *)((ulonglong)*(uint *)(lVar2 + 0x10) + lVar6);
        }
        uVar8 = *(int *)(lVar2 + 0x10) + 0x12;
        if (uVar8 < *(uint *)(*(longlong *)(lVar2 + 8) + 0x28)) {
          *(int *)(lVar2 + 0x28) = *(int *)(lVar2 + 0x28) + 0x12;
          *(int *)(lVar2 + 0x18) = *(int *)(lVar2 + 0x18) + -0x12;
          *(uint *)(lVar2 + 0x10) = uVar8;
        }
        else {
          NdisAdvanceNetBufferDataStart(lVar2,0x12,0);
        }
        if (pcVar10 == (char *)0x0) goto LAB_1400014c2;
LAB_140001384:
        if ((*pcVar10 != '\x01') || (2 < (byte)pcVar10[1])) goto LAB_1400014c2;
        puVar3 = (undefined8 *)puVar11[1];
        puVar11[9] = ToppNetBufferListCompletionRoutine;
        *(undefined4 *)(puVar11 + 8) = 1;
        puVar11[10] = 0;
        puVar11[0xb] = 0;
        *(uint *)(puVar11 + 0x11) = *(uint *)(puVar11 + 0x11) & 0xffffc;
        for (; puVar3 != (undefined8 *)0x0; puVar3 = (undefined8 *)*puVar3) {
          *(undefined4 *)(puVar3 + 10) = *(undefined4 *)(puVar3 + 5);
          *(undefined4 *)((longlong)puVar3 + 0x54) = *(undefined4 *)(puVar3 + 3);
        }
        if ((param_5 & 2) == 0) {
          *(uint *)(puVar11 + 0x11) = *(uint *)(puVar11 + 0x11) | 0x2000000;
        }
        *(uint *)(lVar2 + 0x50) = local_74;
        *(int *)(lVar2 + 0x54) = local_78;
        local_88 = CONCAT31(local_88._1_3_,param_5) & 0xffffff01;
        (*(code *)(&PTR_TopReceiveHandler_14000d108)[(byte)pcVar10[1]])
                  (param_1,puVar11,local_70,pcVar10);
        if ((*(uint *)(puVar11 + 0x11) & 0x1000000) == 0) {
          LOCK();
          piVar1 = (int *)(puVar11 + 8);
          iVar7 = *piVar1;
          *piVar1 = *piVar1 + -1;
          UNLOCK();
          if (iVar7 == 1) {
            (*(code *)puVar11[9])(puVar11,puVar11[10],puVar11[0xb],bVar9);
          }
          goto LAB_1400014fc;
        }
        LOCK();
        piVar1 = (int *)(puVar11 + 8);
        iVar7 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar7 == 1) {
          (*(code *)puVar11[9])(puVar11,puVar11[10],puVar11[0xb],bVar9);
        }
      }
      puVar3 = param_2;
      puVar11 = local_68;
    } while (local_68 != (undefined8 *)0x0);
    if (param_2 == (undefined8 *)0x0) {
      return;
    }
  }
  else if ((param_5 & 2) != 0) {
    return;
  }
  NdisReturnNetBufferLists(*(undefined8 *)(param_1 + 0x80),param_2,bVar9);
  return;
}



===== ToppStatusHandlerEx @ 140001530 =====

void ToppStatusHandlerEx(longlong param_1,char *param_2)

{
  longlong lVar1;
  uint uVar2;
  
  if ((*param_2 == -0x68) && (*(short *)(param_2 + 2) == 0x70)) {
    if ((*(int *)(param_2 + 0x14) == 0x40010017) &&
       (lVar1 = *(longlong *)(param_2 + 0x30), *(int *)(param_2 + 0x38) == 0x28)) {
      KeAcquireSpinLockAtDpcLevel(param_1 + 0x18);
      uVar2 = *(uint *)(param_1 + 0x34) | 0x100;
      if (*(int *)(lVar1 + 4) != 2) {
        uVar2 = *(uint *)(param_1 + 0x34) & 0xfffffeff;
      }
      *(uint *)(param_1 + 0x34) = uVar2;
      KeReleaseSpinLockFromDpcLevel(param_1 + 0x18);
    }
  }
  else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((2 < (byte)WPP_GLOBAL_Control[0x29] && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0))
          )) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
            &WPP_a011ba9f6767340892c0619c2587c1d2_Traceguids);
  }
  return;
}



===== ToppUnbindAdapterHandlerEx @ 1400015f0 =====

undefined8 ToppUnbindAdapterHandlerEx(undefined8 param_1,longlong param_2)

{
  TopDeleteContext(param_2);
  return 0;
}



===== ToppBindAdapterHandlerEx @ 140001610 =====

ulonglong ToppBindAdapterHandlerEx(undefined8 param_1,undefined8 param_2,longlong param_3)

{
  ulonglong *puVar1;
  longlong *plVar2;
  code *pcVar3;
  longlong lVar4;
  undefined1 uVar5;
  uint uVar6;
  undefined8 uVar7;
  undefined8 *puVar8;
  ulonglong uVar9;
  longlong lVar10;
  undefined4 *puVar11;
  undefined8 uVar12;
  longlong *plVar13;
  undefined4 local_res20 [2];
  ulonglong *puVar14;
  longlong local_98;
  wchar_t *pwStack_90;
  longlong local_88;
  undefined4 local_80;
  undefined4 local_7c;
  undefined8 local_78;
  undefined *local_70;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 *local_60;
  undefined8 local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  
  lVar4 = topNdisProtocolHandle;
  local_98 = 0;
  local_res20[0] = 0;
  local_7c = 0;
  local_64 = 0;
  local_4c = 0;
  local_88 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  if (topNdisProtocolHandle == 0) {
    return 0xc00002fe;
  }
  lVar10 = param_3;
  uVar6 = TopCreateContext(param_3,&local_98);
  if (uVar6 != 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (1 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0))
    {
      WPP_SF_Sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,lVar10,
                *(wchar_t **)(*(longlong *)(param_3 + 0x10) + 8),(char)uVar6);
    }
    return (ulonglong)uVar6;
  }
  local_78 = *(undefined8 *)(param_3 + 0x10);
  local_70 = &DAT_14000f274;
  local_60 = local_res20;
  local_80 = 0x380187;
  local_68 = 1;
  local_58 = 0;
  local_50 = 0;
  NdisInitializeEvent(&local_48);
  lVar10 = local_98;
  *(undefined8 **)(local_98 + 0x98) = &local_48;
  puVar1 = (ulonglong *)(local_98 + 0x80);
  puVar11 = &local_80;
  puVar14 = puVar1;
  uVar6 = NdisOpenAdapterEx(lVar4,local_98,puVar11,param_2);
  if (uVar6 == 0x103) {
    NdisWaitEvent(&local_48,0);
    uVar6 = (uint)uStack_30;
  }
  uVar9 = (ulonglong)uVar6;
  *(undefined8 *)(lVar10 + 0x98) = 0;
  if (uVar6 != 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (1 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0))
    {
      WPP_SF_Sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,puVar11,
                *(wchar_t **)(*(longlong *)(param_3 + 0x10) + 8),(char)uVar6);
    }
    goto LAB_140001aa2;
  }
  if ((4 < (byte)WPP_GLOBAL_Control[0x29]) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
    local_98 = 0;
    pwStack_90 = (wchar_t *)0x0;
    uVar9 = *puVar1;
    NdisQueryAdapterInstanceName(&local_98);
    if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
      if ((4 < (byte)WPP_GLOBAL_Control[0x29]) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0))
      {
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar9,puVar11,lVar10);
      }
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (4 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)
         ) {
        uVar9 = 0x13;
        WPP_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,puVar11,
                 *(wchar_t **)(*(longlong *)(param_3 + 0x10) + 8));
      }
    }
    if (pwStack_90 == (wchar_t *)0x0) {
LAB_140001955:
      if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
        if ((4 < (byte)WPP_GLOBAL_Control[0x29]) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
          uVar9 = (ulonglong)*(ushort *)(param_3 + 0xc0);
          puVar14 = (ulonglong *)
                    CONCAT44((int)((ulonglong)puVar14 >> 0x20),*(undefined4 *)(param_3 + 0x8c));
          WPP_SF__MAC_lDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar9,puVar11,param_3 + 0x6a,
                          (char)*(undefined4 *)(param_3 + 0x8c),(char)*(ushort *)(param_3 + 0xc0),
                          (char)*(undefined4 *)(param_3 + 0x24));
        }
        if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
          if ((4 < (byte)WPP_GLOBAL_Control[0x29]) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
            puVar14 = (ulonglong *)
                      CONCAT44((int)((ulonglong)puVar14 >> 0x20),*(undefined4 *)(param_3 + 0xd4));
            WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar9,puVar11,
                      *(undefined4 *)(param_3 + 0xd0),(char)*(undefined4 *)(param_3 + 0xd4));
          }
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
            WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar9,puVar11,
                     *(undefined4 *)(param_3 + 0x60));
          }
        }
      }
    }
    else if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
      puVar11 = (undefined4 *)WPP_GLOBAL_Control;
      if ((4 < (byte)WPP_GLOBAL_Control[0x29]) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0))
      {
        uVar9 = 0x14;
        WPP_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,WPP_GLOBAL_Control,pwStack_90);
      }
      goto LAB_140001955;
    }
    if (pwStack_90 != (wchar_t *)0x0) {
      NdisFreeMemory(pwStack_90,0,0);
    }
  }
  uVar12 = 0x1010e;
  uVar7 = TopOidRequestSynchronousSafe(lVar10,1,0x1010e,&topNdisPacketFilterStop,(int)puVar14);
  if ((((int)uVar7 != 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
     ((2 < (byte)WPP_GLOBAL_Control[0x29] && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)))) {
    WPP_SF_SLd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),
               (ulonglong)*(uint *)(WPP_GLOBAL_Control + 0x2c),uVar12,
               *(wchar_t **)(*(longlong *)(param_3 + 0x10) + 8),puVar14,(char)uVar7);
  }
  uVar5 = KeAcquireSpinLockRaiseToDpc(&topContextListLock);
  plVar13 = &local_88;
  puVar8 = TopLookupDevice(*(ushort **)(*(ushort **)(param_3 + 0x10) + 4),
                           (uint)**(ushort **)(param_3 + 0x10),plVar13);
  if (puVar8 == (undefined8 *)0x0) {
    plVar13 = (longlong *)(lVar10 + 0x20);
    plVar2 = *(longlong **)(local_88 + 8);
    if (*plVar2 == local_88) {
      *plVar13 = local_88;
      *(longlong **)(lVar10 + 0x28) = plVar2;
      *plVar2 = (longlong)plVar13;
      *(longlong **)(local_88 + 8) = plVar13;
      KeReleaseSpinLock(&topContextListLock,uVar5);
      TopUpdateNetworkCategoryInformation(lVar10);
      return 0;
    }
    pcVar3 = (code *)swi(0x29);
    (*pcVar3)(3);
    pcVar3 = (code *)swi(3);
    uVar9 = (*pcVar3)();
    return uVar9;
  }
  KeReleaseSpinLock(&topContextListLock,uVar5);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (1 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
    WPP_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,plVar13,
             *(wchar_t **)(*(longlong *)(param_3 + 0x10) + 8));
  }
  uVar9 = 0xc000000d;
LAB_140001aa2:
  TopDeleteContext(lVar10);
  return uVar9;
}



===== TopCreateContext @ 140001ac0 =====

int TopCreateContext(longlong param_1,undefined8 *param_2)

{
  ushort uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined8 uVar4;
  undefined4 *local_res8;
  
  local_res8 = (undefined4 *)0x0;
  iVar2 = NdisAllocateMemoryWithTag(&local_res8,**(ushort **)(param_1 + 0x10) + 0x262,0x78436f49);
  if (iVar2 == 0) {
    uVar4 = 0x260;
    memset(local_res8,0,0x260);
    uVar1 = *(ushort *)(param_1 + 0x68);
    if (uVar1 == 6) {
      if (0x5e9 < (ulonglong)*(uint *)(param_1 + 0x24) + 0xe) {
        local_res8[0x49] = *(undefined4 *)(param_1 + 0x6a);
        *(undefined2 *)(local_res8 + 0x4a) = *(undefined2 *)(param_1 + 0x6e);
        QosInitializeModule((longlong)(local_res8 + 100));
        KeInitializeSpinLock(local_res8 + 6);
        puVar3 = local_res8 + 8;
        *(undefined4 **)(local_res8 + 10) = puVar3;
        *(undefined4 **)puVar3 = puVar3;
        puVar3 = local_res8 + 0x52;
        *(undefined4 **)(local_res8 + 0x54) = puVar3;
        *(undefined4 **)puVar3 = puVar3;
        puVar3 = local_res8 + 0x56;
        *(undefined4 **)(local_res8 + 0x58) = puVar3;
        *(undefined4 **)puVar3 = puVar3;
        puVar3 = local_res8 + 0x4c;
        *(undefined4 **)(local_res8 + 0x4e) = puVar3;
        *(undefined4 **)puVar3 = puVar3;
        puVar3 = local_res8 + 0x5e;
        *(undefined4 **)(local_res8 + 0x60) = puVar3;
        *(undefined4 **)puVar3 = puVar3;
        *local_res8 = 0;
        *(undefined4 **)(local_res8 + 4) = local_res8;
        *(undefined ***)(local_res8 + 2) = &PTR_ToppCloseHandler_14000d000;
        local_res8[0xc] = 1;
        local_res8[0xd] = 0x44;
        local_res8[0x96] = (uint)**(ushort **)(param_1 + 0x10);
        *(undefined8 *)(local_res8 + 0x22) = *(undefined8 *)(param_1 + 0xa8);
        local_res8[0x24] = *(undefined4 *)(param_1 + 0xb0);
        local_res8[0x48] = *(undefined4 *)(param_1 + 0x8c);
        if ((*(uint *)(param_1 + 0xd8) & 0x200) != 0) {
          local_res8[0xd] = local_res8[0xd] | 0x20;
        }
        if ((*(uint *)(param_1 + 0xd8) & 0x40) != 0) {
          local_res8[0xd] = local_res8[0xd] | 0x10;
        }
        if (*(int *)(param_1 + 0x48) == 2) {
          local_res8[0xd] = local_res8[0xd] | 0x100;
        }
        memmove(local_res8 + 0x97,*(void **)(*(ushort **)(param_1 + 0x10) + 4),
                (ulonglong)**(ushort **)(param_1 + 0x10));
        *(undefined2 *)((ulonglong)**(ushort **)(param_1 + 0x10) + 0x25c + (longlong)local_res8) = 0
        ;
        KeInitializeMutex(local_res8 + 0xe,0);
        TopInitializeRequestQueue((longlong)(local_res8 + 0x28));
        *param_2 = local_res8;
        return 0;
      }
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)
         ) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                 &WPP_b515efb401d631d3025e3a3f22783527_Traceguids,*(uint *)(param_1 + 0x24));
      }
    }
    else if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
      WPP_SF_SD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(ulonglong)uVar1,uVar4,
                *(wchar_t **)(*(longlong *)(param_1 + 0x10) + 8),(char)uVar1);
    }
    NdisFreeMemory(local_res8,0,0);
    iVar2 = -0x3ffffff3;
  }
  else if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
             &WPP_b515efb401d631d3025e3a3f22783527_Traceguids,iVar2);
  }
  return iVar2;
}



===== TopLookupDevice @ 140001df0 =====

undefined8 * TopLookupDevice(ushort *param_1,uint param_2,undefined8 *param_3)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  ushort *puVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  undefined8 *puVar9;
  
  puVar9 = topContextList;
  do {
    if ((undefined8 **)puVar9 == &topContextList) {
LAB_140001eaa:
      if (param_3 != (undefined8 *)0x0) {
        *param_3 = puVar9;
      }
      return (undefined8 *)0x0;
    }
    uVar3 = *(uint *)(puVar9 + 0x47);
    uVar4 = uVar3;
    if (param_2 <= uVar3) {
      uVar4 = param_2;
    }
    for (puVar5 = param_1; puVar5 < (ushort *)((ulonglong)uVar4 + (longlong)param_1);
        puVar5 = puVar5 + 1) {
      uVar1 = *puVar5;
      uVar7 = (uint)uVar1;
      uVar2 = *(ushort *)((longlong)puVar9 + (0x23c - (longlong)param_1) + (longlong)puVar5);
      uVar8 = (uint)uVar2;
      if ((uint)uVar1 != (uint)uVar2) {
        if (uVar1 - 0x61 < 0x1a) {
          uVar7 = uVar1 - 0x20;
        }
        if (uVar2 - 0x61 < 0x1a) {
          uVar8 = uVar2 - 0x20;
        }
        if (uVar7 != uVar8) {
          iVar6 = uVar7 - uVar8;
          goto LAB_140001e7b;
        }
      }
    }
    iVar6 = param_2 - uVar3;
LAB_140001e7b:
    if (iVar6 < 1) {
      if (-1 < iVar6) {
        return puVar9 + -4;
      }
      goto LAB_140001eaa;
    }
    puVar9 = (undefined8 *)*puVar9;
  } while( true );
}



===== ToppNlInterfaceParameterChangeCallback @ 140001ed0 =====

void ToppNlInterfaceParameterChangeCallback
               (undefined8 param_1,longlong *param_2,longlong param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  undefined1 uVar3;
  undefined8 *puVar4;
  
  if (param_4 != 0) {
    return;
  }
  if (((*(int *)(param_3 + 0x14) == 0x10) && (*param_2 != 0)) && ((int)param_2[1] == 8)) {
    uVar3 = KeAcquireSpinLockRaiseToDpc(&topContextListLock);
    for (puVar4 = topContextList; (undefined8 **)puVar4 != &topContextList;
        puVar4 = (undefined8 *)*puVar4) {
      if (puVar4[0xd] == *(longlong *)*param_2) {
        KeAcquireSpinLockAtDpcLevel(puVar4 + -1);
        if ((*(uint *)((longlong)puVar4 + 0x14) & 1) == 0) {
          LOCK();
          *(int *)(puVar4 + 2) = *(int *)(puVar4 + 2) + 1;
          UNLOCK();
          KeReleaseSpinLockFromDpcLevel();
          KeReleaseSpinLock(&topContextListLock,uVar3);
          TopUpdateNetworkCategoryInformation((longlong)(puVar4 + -4));
          LOCK();
          piVar1 = (int *)(puVar4 + 2);
          iVar2 = *piVar1;
          *piVar1 = *piVar1 + -1;
          UNLOCK();
          if (iVar2 == 1) {
            NdisFreeMemory(puVar4 + -4,0,0);
            return;
          }
          return;
        }
        KeReleaseSpinLockFromDpcLevel(puVar4 + -1);
        break;
      }
    }
    KeReleaseSpinLock(&topContextListLock,uVar3);
  }
  return;
}



===== TopUpdateNetworkCategoryInformation @ 140001ff0 =====

void TopUpdateNetworkCategoryInformation(longlong param_1)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  ulonglong uVar5;
  undefined1 uVar6;
  int iVar7;
  undefined8 uVar8;
  bool bVar9;
  int local_res8 [2];
  int local_res10 [2];
  undefined8 local_res18;
  
  local_res18 = *(undefined8 *)(param_1 + 0x88);
  local_res10[0] = -1;
  local_res8[0] = -1;
  bVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x18);
  iVar7 = 1;
  iVar3 = NsiGetParameter(1,&NPI_MS_IPV4_MODULEID,7,&local_res18,8,0,local_res10,4,0x10);
  uVar8 = 7;
  iVar4 = NsiGetParameter(1,&NPI_MS_IPV6_MODULEID,7,&local_res18,8,0,local_res8,4,0x10);
  if ((iVar3 < 0) || (local_res10[0] == -1)) {
    if ((-1 < iVar4) && (iVar7 = local_res8[0], local_res8[0] != -1)) goto LAB_14000212f;
LAB_140002155:
    iVar7 = 2;
LAB_140002160:
    do {
      uVar6 = (undefined1)iVar7;
      uVar1 = *(uint *)(param_1 + 0x34);
      LOCK();
      bVar9 = uVar1 == *(uint *)(param_1 + 0x34);
      if (bVar9) {
        *(uint *)(param_1 + 0x34) = uVar1 & 0xffffff7f | 0x40;
      }
      UNLOCK();
    } while (!bVar9);
  }
  else {
    if ((iVar4 < 0) || (local_res8[0] == -1)) {
      iVar7 = local_res10[0];
LAB_14000212f:
      if (iVar7 == 2) goto LAB_140002160;
      if (iVar7 == 1) goto LAB_140002140;
    }
    else {
      if ((local_res10[0] == 2) || (local_res8[0] == 2)) goto LAB_140002155;
      if ((local_res10[0] != 0) && (local_res8[0] != 0)) {
LAB_140002140:
        do {
          uVar6 = (undefined1)iVar7;
          uVar1 = *(uint *)(param_1 + 0x34);
          LOCK();
          bVar9 = uVar1 == *(uint *)(param_1 + 0x34);
          if (bVar9) {
            *(uint *)(param_1 + 0x34) = uVar1 & 0xffffffbf | 0x80;
          }
          UNLOCK();
        } while (!bVar9);
        goto LAB_140002173;
      }
      iVar7 = 0;
    }
    uVar6 = (undefined1)iVar7;
    LOCK();
    *(uint *)(param_1 + 0x34) = *(uint *)(param_1 + 0x34) & 0xffffff3f;
    UNLOCK();
  }
LAB_140002173:
  uVar5 = (ulonglong)bVar2;
  KeReleaseSpinLock(param_1 + 0x18);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    WPP_SF__MAC_llDlD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,uVar8,param_1 + 0x124,uVar6,
                      (char)local_res10[0],(char)iVar3,(char)local_res8[0],(char)iVar4);
  }
  return;
}



===== TopDeleteContext @ 140002200 =====

void TopDeleteContext(longlong param_1)

{
  int *piVar1;
  longlong ****pppplVar2;
  longlong lVar3;
  longlong *plVar4;
  longlong *****ppppplVar5;
  code *pcVar6;
  undefined1 uVar7;
  int iVar8;
  longlong *****ppppplVar9;
  undefined4 in_stack_ffffffffffffffb8;
  longlong *****local_38;
  longlong *****local_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  uVar7 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x18);
  LOCK();
  *(uint *)(param_1 + 0x34) = *(uint *)(param_1 + 0x34) | 5;
  UNLOCK();
  KeReleaseSpinLock(param_1 + 0x18,uVar7);
  TopOidRequestSynchronousSafe(param_1,1,0x1010e,&topNdisPacketFilterStop,in_stack_ffffffffffffffb8)
  ;
  KeAcquireSpinLockRaiseToDpc(&topContextListLock);
  lVar3 = *(longlong *)(param_1 + 0x20);
  if ((*(longlong *)(lVar3 + 8) == param_1 + 0x20) &&
     (plVar4 = *(longlong **)(param_1 + 0x28), *plVar4 == param_1 + 0x20)) {
    *plVar4 = lVar3;
    *(longlong **)(lVar3 + 8) = plVar4;
    KeReleaseSpinLock(&topContextListLock);
    ToppEnableMappingSupport(param_1,'\0');
    local_30 = (longlong *****)&local_38;
    local_38 = (longlong *****)&local_38;
    uVar7 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x18);
    ppppplVar9 = *(longlong ******)(param_1 + 0x178);
    while( true ) {
      ppppplVar5 = ppppplVar9;
      if (ppppplVar5 == (longlong *****)(param_1 + 0x178)) {
        KeReleaseSpinLock(param_1 + 0x18,uVar7);
        ppppplVar9 = local_38;
        if ((longlong ******)local_38 != &local_38) {
          do {
            ppppplVar5 = (longlong *****)*ppppplVar9;
            LOCK();
            pppplVar2 = ppppplVar9[-8];
            ppppplVar9[-8] = (longlong ****)0x0;
            UNLOCK();
            if (pppplVar2 != (longlong ****)0x0) {
              LOCK();
              piVar1 = (int *)(param_1 + 0x30);
              iVar8 = *piVar1;
              *piVar1 = *piVar1 + -1;
              UNLOCK();
              if (iVar8 == 1) {
                NdisFreeMemory(param_1,0,0);
              }
            }
            *(undefined4 *)(ppppplVar9 + -0xf) = 0xc00002fe;
            ppppplVar9[-0xe] = (longlong ****)0x0;
            IofCompleteRequest(ppppplVar9 + -0x15);
            LOCK();
            piVar1 = (int *)(param_1 + 0x30);
            iVar8 = *piVar1;
            *piVar1 = *piVar1 + -1;
            UNLOCK();
            if (iVar8 == 1) {
              NdisFreeMemory(param_1);
            }
            ppppplVar9 = ppppplVar5;
          } while ((longlong ******)ppppplVar5 != &local_38);
        }
        TopWaitForPendingIo(param_1);
        TopFlushReceiveQueue(param_1);
        QosShutdownModule(param_1 + 400);
        TopShutdownRequestQueue(param_1 + 0xa0);
        if (*(longlong *)(param_1 + 0x80) != 0) {
          local_28 = 0;
          uStack_20 = 0;
          local_18 = 0;
          NdisInitializeEvent(&local_28);
          *(undefined8 **)(param_1 + 0x98) = &local_28;
          iVar8 = NdisCloseAdapterEx(*(undefined8 *)(param_1 + 0x80));
          if (iVar8 == 0x103) {
            NdisWaitEvent(&local_28,0);
          }
          else if ((((iVar8 != 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
                   (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
            WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                     &WPP_b515efb401d631d3025e3a3f22783527_Traceguids,iVar8);
          }
          *(undefined8 *)(param_1 + 0x98) = 0;
          *(undefined8 *)(param_1 + 0x80) = 0;
        }
        LOCK();
        piVar1 = (int *)(param_1 + 0x30);
        iVar8 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar8 == 1) {
          NdisFreeMemory(param_1,0,0);
        }
        return;
      }
      ppppplVar9 = (longlong *****)*ppppplVar5;
      if (((longlong *****)ppppplVar9[1] != ppppplVar5) ||
         (pppplVar2 = ppppplVar5[1], (longlong *****)*pppplVar2 != ppppplVar5)) break;
      *pppplVar2 = (longlong ***)ppppplVar9;
      ppppplVar9[1] = pppplVar2;
      if ((longlong ******)local_38[1] != &local_38) break;
      *ppppplVar5 = (longlong ****)local_38;
      ppppplVar5[1] = (longlong ****)&local_38;
      local_38[1] = (longlong ****)ppppplVar5;
      local_38 = ppppplVar5;
    }
  }
  pcVar6 = (code *)swi(0x29);
  (*pcVar6)(3);
  pcVar6 = (code *)swi(3);
  (*pcVar6)();
  return;
}



===== ToppEnableMappingSupport @ 140002540 =====

ulonglong ToppEnableMappingSupport(longlong param_1,char param_2)

{
  uint uVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined *puVar5;
  bool bVar6;
  
  uVar4 = 0;
  puVar5 = (undefined *)0x0;
  KeWaitForSingleObject(param_1 + 0x38,0,0,0,0);
  if (param_2 == '\0') {
    uVar2 = *(uint *)(param_1 + 0x34);
    do {
      LOCK();
      uVar1 = *(uint *)(param_1 + 0x34);
      bVar6 = uVar2 == uVar1;
      if (bVar6) {
        *(uint *)(param_1 + 0x34) = uVar2 & 0xfffffff7;
      }
      else {
        uVar2 = uVar1;
      }
      UNLOCK();
    } while (!bVar6);
    if ((uVar2 & 8) != 0) {
      TopDereferencePacketFilterSafe(param_1,CONCAT71((int7)((ulonglong)uVar4 >> 8),1),puVar5);
    }
  }
  else if ((*(uint *)(param_1 + 0x34) & 8) == 0) {
    uVar3 = TopReferencePacketFilter(param_1,1);
    if ((int)uVar3 < 0) {
      KeReleaseMutex(param_1 + 0x38,0);
      return uVar3 & 0xffffffff;
    }
    LOCK();
    *(uint *)(param_1 + 0x34) = *(uint *)(param_1 + 0x34) | 8;
    UNLOCK();
  }
  KeReleaseMutex(param_1 + 0x38,0);
  return 0;
}



===== TopShutdownRequestQueue @ 140002610 =====

void TopShutdownRequestQueue(longlong param_1)

{
  int *piVar1;
  int iVar2;
  undefined1 uVar3;
  char cVar4;
  longlong lVar5;
  
  uVar3 = KeAcquireSpinLockRaiseToDpc();
  *(undefined4 *)(param_1 + 0x28) = 1;
  KeReleaseSpinLockFromDpcLevel(param_1);
  KeAcquireSpinLockAtDpcLevel(param_1);
  lVar5 = *(longlong *)(param_1 + 0x70);
  if (lVar5 != 0) {
    do {
      *(undefined1 *)(lVar5 + 1) = 1;
      lVar5 = *(longlong *)(lVar5 + 0x100);
    } while (lVar5 != 0);
    cVar4 = KeRemoveQueueDpc(param_1 + 0x30);
    if (cVar4 != '\0') {
      KeReleaseSpinLockFromDpcLevel(param_1);
      ToppRequestCompletePrivateHandlerAtDpcLevel(param_1,*(longlong *)(param_1 + 0x70),0xc001000c);
      goto LAB_1400026b0;
    }
  }
  KeReleaseSpinLockFromDpcLevel(param_1);
LAB_1400026b0:
  KeLowerIrql(uVar3);
  LOCK();
  piVar1 = (int *)(param_1 + 8);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 != 1) {
    NdisWaitEvent(param_1 + 0x10,0);
  }
  return;
}



===== QosShutdownModule @ 140002700 =====

void QosShutdownModule(longlong param_1)

{
  undefined8 ***pppuVar1;
  undefined8 ***pppuVar2;
  int iVar3;
  undefined1 uVar4;
  char cVar5;
  undefined8 ***pppuVar6;
  undefined8 ***pppuVar7;
  undefined8 ***local_18;
  undefined8 ***local_10;
  
  uVar4 = KeAcquireSpinLockRaiseToDpc();
  cVar5 = KeCancelTimer(param_1 + 0x38);
  KeReleaseSpinLock(param_1,uVar4);
  if (cVar5 == '\0') {
    KeFlushQueuedDpcs();
  }
  local_10 = &local_18;
  local_18 = &local_18;
  uVar4 = KeAcquireSpinLockRaiseToDpc(param_1);
  pppuVar7 = *(undefined8 ****)(param_1 + 8);
  pppuVar1 = (undefined8 ***)(param_1 + 8);
  if (pppuVar7 != pppuVar1) {
    local_10 = *(undefined8 ****)(param_1 + 0x10);
    pppuVar7[1] = &local_18;
    *local_10 = &local_18;
    *(undefined8 ****)(param_1 + 0x10) = pppuVar1;
    *pppuVar1 = pppuVar1;
    local_18 = pppuVar7;
  }
  pppuVar6 = *(undefined8 ****)(param_1 + 0x18);
  pppuVar1 = (undefined8 ***)(param_1 + 0x18);
  if (pppuVar6 != pppuVar1) {
    *local_10 = pppuVar6;
    pppuVar6[1] = local_10;
    pppuVar6 = &local_18;
    local_10 = *(undefined8 ****)(param_1 + 0x20);
    *local_10 = pppuVar6;
    *(undefined8 ****)(param_1 + 0x20) = pppuVar1;
    *pppuVar1 = pppuVar1;
  }
  KeReleaseSpinLockFromDpcLevel(param_1);
  while (pppuVar1 = local_18, (undefined8 ****)local_18 != &local_18) {
    pppuVar2 = local_18 + -5;
    KeAcquireSpinLockAtDpcLevel(local_18 + -2);
    LOCK();
    *(int *)(pppuVar1 + -1) = *(int *)(pppuVar1 + -1) + 1;
    UNLOCK();
    QosDeleteSession((int *)pppuVar2);
    KeReleaseSpinLockFromDpcLevel(pppuVar1 + -2);
    QospShutdownSessionAtDpcLevel(pppuVar2);
    LOCK();
    pppuVar1 = pppuVar1 + -1;
    iVar3 = *(int *)pppuVar1;
    *(int *)pppuVar1 = *(int *)pppuVar1 + -1;
    UNLOCK();
    if (iVar3 == 1) {
      QosCleanupSession((longlong)pppuVar2,pppuVar6,pppuVar7);
    }
  }
  KeLowerIrql(uVar4);
  return;
}



===== TopWaitForPendingIo @ 140002890 =====

void TopWaitForPendingIo(longlong param_1)

{
  undefined8 local_res8 [4];
  
  local_res8[0] = 0xfffffffffff85ee0;
  do {
    if (*(int *)(param_1 + 0x170) == 0) {
      if (*(int *)(param_1 + 0x140) == 0) {
        return;
      }
    }
    else {
      TopCancelPendingReads(param_1);
    }
    KeDelayExecutionThread(0,0,local_res8);
  } while( true );
}



===== ToppPnPEventHandler @ 1400028f0 =====

undefined8 ToppPnPEventHandler(longlong param_1,longlong param_2)

{
  int iVar1;
  char *pcVar2;
  undefined1 uVar3;
  undefined8 *puVar4;
  undefined8 local_res8;
  
  iVar1 = *(int *)(param_2 + 8);
  if (iVar1 == 6) {
    KeSetEvent(&topBindingComplete,2);
    return 0;
  }
  if (iVar1 == 8) {
    uVar3 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x18);
    LOCK();
    *(uint *)(param_1 + 0x34) = *(uint *)(param_1 + 0x34) | 2;
    UNLOCK();
    iVar1 = *(int *)(param_1 + 0x140);
    local_res8 = 0xfffffffffff85ee0;
    while (iVar1 != 0) {
      KeReleaseSpinLock(param_1 + 0x18,uVar3);
      KeDelayExecutionThread(0,0,&local_res8);
      uVar3 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x18);
      iVar1 = *(int *)(param_1 + 0x140);
    }
    KeReleaseSpinLock(param_1 + 0x18,uVar3);
    TopFlushReceiveQueue(param_1);
    return 0;
  }
  if (iVar1 != 9) {
    return 0;
  }
  pcVar2 = *(char **)(param_2 + 0x10);
  if (pcVar2 == (char *)0x0) {
    puVar4 = (undefined8 *)0x0;
  }
  else {
    if ((*pcVar2 != -0x5d) || (*(ushort *)(pcVar2 + 2) < 0x38)) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 0;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 3) {
        return 0;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) {
        return 0;
      }
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
              &WPP_a011ba9f6767340892c0619c2587c1d2_Traceguids);
      return 0;
    }
    puVar4 = *(undefined8 **)(pcVar2 + 0x18);
  }
  uVar3 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x18);
  do {
    if (puVar4 == (undefined8 *)0x0) {
LAB_14000298b:
      LOCK();
      *(uint *)(param_1 + 0x34) = *(uint *)(param_1 + 0x34) & 0xfffffffd;
      UNLOCK();
      KeReleaseSpinLock(param_1 + 0x18,uVar3);
      return 0;
    }
    if ((*(int *)(puVar4 + 1) == 0x1021d) && (*(int *)((longlong)puVar4 + 0xc) == 0x58)) {
      if ((*(uint *)((longlong)puVar4 + 0x2c) & 0x200) == 0) {
        LOCK();
        *(uint *)(param_1 + 0x34) = *(uint *)(param_1 + 0x34) & 0xffffffdf;
        UNLOCK();
      }
      else {
        LOCK();
        *(uint *)(param_1 + 0x34) = *(uint *)(param_1 + 0x34) | 0x20;
        UNLOCK();
      }
      if ((*(uint *)((longlong)puVar4 + 0x2c) & 0x40) == 0) {
        LOCK();
        *(uint *)(param_1 + 0x34) = *(uint *)(param_1 + 0x34) & 0xffffffef;
        UNLOCK();
      }
      else {
        LOCK();
        *(uint *)(param_1 + 0x34) = *(uint *)(param_1 + 0x34) | 0x10;
        UNLOCK();
      }
      goto LAB_14000298b;
    }
    puVar4 = (undefined8 *)*puVar4;
  } while( true );
}



===== TopFlushReceiveQueue @ 140002af0 =====

void TopFlushReceiveQueue(longlong param_1)

{
  longlong ****pppplVar1;
  longlong ****pppplVar2;
  longlong ***ppplVar3;
  longlong ***ppplVar4;
  code *pcVar5;
  undefined1 uVar6;
  longlong ****local_18;
  longlong ****local_10;
  
  local_10 = (longlong ****)&local_18;
  local_18 = (longlong ****)&local_18;
  uVar6 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x18);
  pppplVar1 = (longlong ****)(param_1 + 0x158);
  pppplVar2 = (longlong ****)*pppplVar1;
  if (pppplVar2 != pppplVar1) {
    local_10 = *(longlong *****)(param_1 + 0x160);
    pppplVar2[1] = (longlong ***)&local_18;
    *local_10 = (longlong ***)&local_18;
    *(longlong *****)(param_1 + 0x160) = pppplVar1;
    *pppplVar1 = (longlong ***)pppplVar1;
    *(undefined8 *)(param_1 + 0x168) = 0;
    local_18 = pppplVar2;
  }
  KeReleaseSpinLockFromDpcLevel(param_1 + 0x18);
  KeAcquireSpinLockAtDpcLevel(&topDescriptorLookasideListLock);
  while( true ) {
    if ((longlong *****)local_18 == &local_18) {
      KeReleaseSpinLock(&topDescriptorLookasideListLock,uVar6);
      return;
    }
    ppplVar3 = *local_18;
    if (((longlong ****)ppplVar3[1] != local_18) ||
       (ppplVar4 = local_18[1], (longlong ****)*ppplVar4 != local_18)) break;
    *ppplVar4 = (longlong **)ppplVar3;
    ppplVar3[1] = (longlong **)ppplVar4;
    ExFreeToNPagedLookasideList(local_18[2],local_18);
  }
  pcVar5 = (code *)swi(0x29);
  (*pcVar5)(3);
  pcVar5 = (code *)swi(3);
  (*pcVar5)();
  return;
}



===== TopOidRequestSynchronousSafe @ 140002c10 =====

undefined8
TopOidRequestSynchronousSafe
          (longlong param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4,
          undefined4 param_5)

{
  undefined1 uVar1;
  undefined8 uVar2;
  undefined8 in_stack_ffffffffffffffe8;
  
  param_5 = 0;
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x18);
  if ((*(uint *)(param_1 + 0x34) & 1) == 0) {
    LOCK();
    *(int *)(param_1 + 0x140) = *(int *)(param_1 + 0x140) + 1;
    UNLOCK();
    KeReleaseSpinLock(param_1 + 0x18,uVar1);
    uVar2 = TopOidRequestSynchronous
                      (*(undefined8 *)(param_1 + 0x80),param_2,param_3,param_4,
                       in_stack_ffffffffffffffe8,&param_5);
    LOCK();
    *(int *)(param_1 + 0x140) = *(int *)(param_1 + 0x140) + -1;
    UNLOCK();
  }
  else {
    KeReleaseSpinLock();
    uVar2 = 0xc00002fe;
  }
  return uVar2;
}



===== QosInitializeModule @ 140002cd0 =====

void QosInitializeModule(longlong param_1)

{
  longlong lVar1;
  
  KeInitializeSpinLock();
  lVar1 = param_1 + 8;
  *(longlong *)(param_1 + 0x10) = lVar1;
  *(longlong *)lVar1 = lVar1;
  lVar1 = param_1 + 0x18;
  *(longlong *)(param_1 + 0x20) = lVar1;
  *(longlong *)lVar1 = lVar1;
  *(undefined8 *)(param_1 + 0x28) = 0;
  *(undefined8 *)(param_1 + 0x30) = 0;
  KeInitializeDpc(param_1 + 0x78,QosdiagpRenewalTimerDpc,param_1 + -400);
  KeInitializeTimer(param_1 + 0x38);
  NdisGetSystemUpTimeEx(param_1 + 0xb8);
  *(longlong *)(param_1 + 0xb8) = *(longlong *)(param_1 + 0xb8) + -240000;
  *(undefined2 *)(param_1 + 0xc0) = 3;
  return;
}



===== TopInitializeRequestQueue @ 140002d70 =====

void TopInitializeRequestQueue(longlong param_1)

{
  KeInitializeSpinLock();
  KeInitializeDpc(param_1 + 0x30,ToppRequestDpc,param_1);
  NdisInitializeEvent(param_1 + 0x10);
  *(undefined4 *)(param_1 + 8) = 1;
  return;
}



===== TopOidRequestSynchronous @ 140002dd0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void TopOidRequestSynchronous
               (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4,
               undefined8 param_5,undefined4 *param_6)

{
  int iVar1;
  undefined1 auStack_178 [32];
  undefined1 local_158 [8];
  undefined4 local_150;
  undefined4 local_14c;
  undefined4 local_130;
  undefined8 local_128;
  undefined4 local_120;
  undefined4 local_11c;
  undefined4 local_118;
  undefined1 local_58 [24];
  int local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_178;
  memset(local_158,0,0x120);
  NdisInitializeEvent(local_58);
  local_158[0] = 1;
  local_150 = 0xf80196;
  local_120 = 4;
  local_14c = param_2;
  local_130 = param_3;
  local_128 = param_4;
  iVar1 = NdisOidRequest(param_1,&local_150);
  if (iVar1 == 0x103) {
    NdisWaitEvent(local_58,0);
    iVar1 = local_40;
  }
  if (iVar1 == 0) {
    local_118 = local_11c;
  }
  *param_6 = local_118;
  return;
}



===== TopUnregisterUnbindNotification @ 140002ec0 =====

void TopUnregisterUnbindNotification
               (longlong param_1,undefined8 ***param_2,undefined8 **param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  undefined8 **ppuVar3;
  code *pcVar4;
  undefined1 uVar5;
  undefined8 ***pppuVar6;
  undefined8 ***pppuVar7;
  undefined8 ***local_18;
  undefined8 ***local_10;
  
  local_10 = &local_18;
  local_18 = &local_18;
  uVar5 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x18);
  pppuVar6 = *(undefined8 ****)(param_1 + 0x178);
LAB_140002f0f:
  do {
    pppuVar7 = pppuVar6;
    if (pppuVar7 == (undefined8 ***)(param_1 + 0x178)) goto LAB_140002f86;
    pppuVar6 = (undefined8 ***)*pppuVar7;
    if (param_2 == (undefined8 ***)0x0) {
      if (param_3 != (undefined8 **)0x0) {
        if (pppuVar7[-6] < param_3) goto LAB_140002f0f;
        if (param_3 < pppuVar7[-6]) goto LAB_140002f86;
      }
    }
    else if (param_2 != pppuVar7 + -0x15) goto LAB_140002f0f;
    if (((undefined8 ***)pppuVar6[1] != pppuVar7) ||
       (ppuVar3 = pppuVar7[1], (undefined8 ***)*ppuVar3 != pppuVar7)) {
LAB_14000304e:
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)(3);
      pcVar4 = (code *)swi(3);
      (*pcVar4)();
      return;
    }
    *ppuVar3 = pppuVar6;
    pppuVar6[1] = ppuVar3;
    if ((undefined8 ****)local_18[1] != &local_18) goto LAB_14000304e;
    *pppuVar7 = local_18;
    pppuVar7[1] = &local_18;
    local_18[1] = pppuVar7;
    local_18 = pppuVar7;
    if (param_2 != (undefined8 ***)0x0) {
LAB_140002f86:
      KeReleaseSpinLock(param_1 + 0x18,uVar5);
      pppuVar6 = local_18;
      if ((undefined8 ****)local_18 != &local_18) {
        do {
          pppuVar7 = (undefined8 ***)*pppuVar6;
          LOCK();
          ppuVar3 = pppuVar6[-8];
          pppuVar6[-8] = (undefined8 **)0x0;
          UNLOCK();
          if (ppuVar3 != (undefined8 **)0x0) {
            LOCK();
            piVar1 = (int *)(param_1 + 0x30);
            iVar2 = *piVar1;
            *piVar1 = *piVar1 + -1;
            UNLOCK();
            if (iVar2 == 1) {
              NdisFreeMemory(param_1,0,0);
            }
          }
          *(undefined4 *)(pppuVar6 + -0xf) = param_4;
          pppuVar6[-0xe] = (undefined8 **)0x0;
          IofCompleteRequest(pppuVar6 + -0x15);
          LOCK();
          piVar1 = (int *)(param_1 + 0x30);
          iVar2 = *piVar1;
          *piVar1 = *piVar1 + -1;
          UNLOCK();
          if (iVar2 == 1) {
            NdisFreeMemory(param_1);
          }
          pppuVar6 = pppuVar7;
        } while ((undefined8 ****)pppuVar7 != &local_18);
      }
      return;
    }
  } while( true );
}



===== TopOidRequestCompleteHandler @ 140003060 =====

void TopOidRequestCompleteHandler(longlong param_1,longlong param_2,undefined4 param_3)

{
  undefined1 uVar1;
  
  if (*(char *)(param_2 + -8) == '\0') {
    uVar1 = KfRaiseIrql(2);
    ToppRequestCompletePrivateHandlerAtDpcLevel(param_1 + 0xa0,param_2 + -8,param_3);
    KeLowerIrql(uVar1);
  }
  else {
    *(undefined4 *)(param_2 + 0x110) = param_3;
    NdisSetEvent(param_2 + 0xf8);
  }
  return;
}



===== ToppCloseAdapterCompleteHandlerEx @ 1400030f0 =====

void ToppCloseAdapterCompleteHandlerEx(longlong param_1)

{
  NdisSetEvent(*(undefined8 *)(param_1 + 0x98));
  return;
}



===== ToppDelayedPolicyResolutionTimerCallback @ 140003120 =====

/* WARNING: Removing unreachable block (ram,0x000140003154) */

ulonglong ToppDelayedPolicyResolutionTimerCallback(void)

{
  longlong lVar1;
  ulonglong uVar2;
  uint uVar3;
  
  lVar1 = IoAllocateWorkItem(topDeviceObject);
  if (lVar1 == 0) {
    uVar3 = (DAT_14000f540 & 0xfffffffe) - 2 | DAT_14000f540 & 1;
    LOCK();
    uVar2 = (ulonglong)DAT_14000f540;
    UNLOCK();
    DAT_14000f540 = uVar3;
    if (uVar3 == 0) {
      uVar2 = KeSetEvent(DAT_14000f548,0,0);
    }
  }
  else {
    uVar2 = IoQueueWorkItemEx(lVar1,ToppDelayedPolicyResolutionWorker,1);
  }
  return uVar2;
}



===== ToppAdvanceRequestAtDpcLevel @ 1400031b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ToppAdvanceRequestAtDpcLevel(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  
  KeAcquireSpinLockAtDpcLevel();
  lVar2 = *(longlong *)(param_1 + 0x70);
  lVar3 = *(longlong *)(lVar2 + 0x100);
  lVar4 = lVar3;
  if (*(int *)(param_1 + 0x28) == 0) {
    if ((lVar3 == 0) || (*(char *)(lVar3 + 1) == '\0')) {
      lVar4 = 0;
    }
    else {
      do {
        plVar1 = (longlong *)(lVar3 + 0x100);
        lVar3 = *plVar1;
        if (lVar3 == 0) break;
      } while (*(char *)(lVar3 + 1) != '\0');
      *plVar1 = 0;
    }
    *(longlong *)(param_1 + 0x70) = lVar3;
    if (lVar3 != 0) {
      KeInsertQueueDpc(param_1 + 0x30,0,0);
    }
  }
  else {
    *(undefined8 *)(param_1 + 0x70) = 0;
  }
  KeReleaseSpinLockFromDpcLevel(param_1);
  while (lVar4 != 0) {
    lVar3 = *(longlong *)(lVar4 + 0x100);
    if (*(code **)(lVar4 + 0x108) != (code *)0x0) {
      (**(code **)(lVar4 + 0x108))
                (param_1 + -0xa0,*(undefined8 *)(lVar4 + 0x110),*(undefined8 *)(lVar4 + 0x118),
                 0xc001000c);
    }
    ToppCleanupRequestAtDpcLevel(param_1,lVar4);
    lVar4 = lVar3;
  }
  ToppCleanupRequestAtDpcLevel(param_1,lVar2);
  return;
}



===== TopAllowLLTDioOnPublicNetPolicyCallback @ 1400032c0 =====

void TopAllowLLTDioOnPublicNetPolicyCallback(int *param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 uVar1;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
    if (param_1 == (int *)0x0) {
      uVar1 = 0;
    }
    else {
      uVar1 = (undefined1)*param_1;
    }
    WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,param_3,param_1,uVar1);
  }
  if ((param_1 == (int *)0x0) || (*param_1 == 0)) {
    LOCK();
    topActivePolicyFlags = topActivePolicyFlags | 4;
    UNLOCK();
  }
  else {
    LOCK();
    topActivePolicyFlags = topActivePolicyFlags & 0xfffffffb;
    UNLOCK();
  }
  return;
}



===== TopProhibitLLTDioOnPrivateNetPolicyCallback @ 140003340 =====

void TopProhibitLLTDioOnPrivateNetPolicyCallback(int *param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 uVar1;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
    if (param_1 == (int *)0x0) {
      uVar1 = 0;
    }
    else {
      uVar1 = (undefined1)*param_1;
    }
    WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,param_3,param_1,uVar1);
  }
  if ((param_1 == (int *)0x0) || (*param_1 == 0)) {
    LOCK();
    topActivePolicyFlags = topActivePolicyFlags & 0xfffffff7;
    UNLOCK();
  }
  else {
    LOCK();
    topActivePolicyFlags = topActivePolicyFlags | 8;
    UNLOCK();
  }
  return;
}



===== TopAllowLLTDioOnDomainPolicyCallback @ 1400033c0 =====

void TopAllowLLTDioOnDomainPolicyCallback(int *param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 uVar1;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
    if (param_1 == (int *)0x0) {
      uVar1 = 0;
    }
    else {
      uVar1 = (undefined1)*param_1;
    }
    WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,param_3,param_1,uVar1);
  }
  if ((param_1 == (int *)0x0) || (*param_1 == 0)) {
    LOCK();
    topActivePolicyFlags = topActivePolicyFlags | 2;
    UNLOCK();
  }
  else {
    LOCK();
    topActivePolicyFlags = topActivePolicyFlags & 0xfffffffd;
    UNLOCK();
  }
  return;
}



===== TopReferencePacketFilter @ 140003440 =====

ulonglong TopReferencePacketFilter(longlong param_1,byte param_2)

{
  int *piVar1;
  uint uVar2;
  bool bVar3;
  undefined1 uVar4;
  uint uVar5;
  ulonglong uVar6;
  int iVar7;
  undefined8 *puVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  undefined *puVar11;
  bool bVar12;
  uint local_res8 [2];
  undefined8 local_res20;
  undefined8 *puVar13;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  
  if ((*(uint *)(param_1 + 0x34) & 1) != 0) {
    return 0xc00002fe;
  }
  puVar11 = (undefined *)0x0;
  puVar13 = (undefined8 *)0x0;
  KeWaitForSingleObject(param_1 + 0x38,0,0,0);
  uVar4 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x18);
  iVar7 = *(int *)(param_1 + 0x70) + 1;
  *(int *)(param_1 + 0x70) = iVar7;
  if ((iVar7 != 1) && (param_2 == 0)) {
    KeReleaseSpinLock(param_1 + 0x18,uVar4);
    uVar10 = 0;
    goto LAB_14000378d;
  }
  bVar3 = false;
  uVar5 = *(uint *)(param_1 + 0x34);
  do {
    LOCK();
    uVar2 = *(uint *)(param_1 + 0x34);
    bVar12 = uVar5 == uVar2;
    if (bVar12) {
      *(uint *)(param_1 + 0x34) = uVar5 & 0xfffffffb;
    }
    else {
      uVar5 = uVar2;
    }
    UNLOCK();
  } while (!bVar12);
  if ((uVar5 & 4) == 0) {
    puVar8 = (undefined8 *)(param_1 + 0x18);
    KeReleaseSpinLock(puVar8,uVar4);
    bVar12 = false;
LAB_140003682:
    bVar3 = bVar12;
    if (param_2 != 0) {
      uVar9 = *(ulonglong *)(param_1 + 0x88);
      puVar13 = &local_res20;
      local_res20 = 0;
      uVar5 = TopCreateBackChannel(puVar8,uVar9,puVar11,param_1,puVar13);
      uVar10 = (ulonglong)uVar5;
      if ((int)uVar5 < 0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
          puVar11 = &WPP_b515efb401d631d3025e3a3f22783527_Traceguids;
          uVar9 = 0x13;
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
                   &WPP_b515efb401d631d3025e3a3f22783527_Traceguids,uVar5);
        }
        uVar4 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x18);
        goto LAB_140003709;
      }
      uVar4 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x18);
      *(undefined8 *)(param_1 + 0x188) = local_res20;
      KeReleaseSpinLock(param_1 + 0x18,uVar4);
    }
    uVar10 = 0;
  }
  else {
    local_res8[0] = 0xc0000001;
    puVar11 = (undefined *)0x0;
    local_48 = 0;
    uVar9 = 0;
    local_58 = 0;
    uStack_50 = 0;
    KeInitializeEvent(&local_58);
    uVar6 = TopQueueOidRequestAsynchronousAtDpcLevel
                      (param_1 + 0xa0,uVar9,puVar11,&topNdisPacketFilterDefault,puVar13,
                       ToppReferenceCompletionCallback,&local_58,local_res8);
    uVar10 = uVar6 & 0xffffffff;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (uVar9 = (ulonglong)*(uint *)(WPP_GLOBAL_Control + 0x2c),
       (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
      puVar11 = &WPP_b515efb401d631d3025e3a3f22783527_Traceguids;
      puVar13 = (undefined8 *)CONCAT44((int)((ulonglong)puVar13 >> 0x20),(int)uVar6);
      uVar9 = 0x11;
      WPP_SF_Dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
                &WPP_b515efb401d631d3025e3a3f22783527_Traceguids,(uint)param_2,(char)uVar6);
    }
    if (-1 < (int)uVar6) {
      KeReleaseSpinLock(param_1 + 0x18);
      puVar13 = (undefined8 *)0x0;
      puVar11 = (undefined *)0x0;
      puVar8 = &local_58;
      uVar9 = 0;
      bVar3 = true;
      KeWaitForSingleObject(puVar8,0,0,0);
      uVar10 = (ulonglong)local_res8[0];
      bVar12 = true;
      if (-1 < (int)local_res8[0]) goto LAB_140003682;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)
         ) {
        puVar11 = &WPP_b515efb401d631d3025e3a3f22783527_Traceguids;
        uVar9 = 0x12;
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
                 &WPP_b515efb401d631d3025e3a3f22783527_Traceguids,local_res8[0]);
        uVar10 = (ulonglong)local_res8[0];
      }
      uVar4 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x18);
      if (-1 < (int)uVar10) goto LAB_14000378d;
    }
LAB_140003709:
    piVar1 = (int *)(param_1 + 0x70);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      LOCK();
      *(uint *)(param_1 + 0x34) = *(uint *)(param_1 + 0x34) | 4;
      UNLOCK();
      if (bVar3) {
        TopQueueOidRequestAsynchronousAtDpcLevel
                  (param_1 + 0xa0,uVar9,puVar11,&topNdisPacketFilterStop,puVar13,0,0,0);
      }
    }
    KeReleaseSpinLock(param_1 + 0x18,uVar4);
  }
LAB_14000378d:
  KeReleaseMutex(param_1 + 0x38,0);
  return uVar10;
}



===== ToppCleanupRequestAtDpcLevel @ 1400037d0 =====

void ToppCleanupRequestAtDpcLevel(longlong param_1,undefined8 param_2)

{
  int *piVar1;
  int iVar2;
  
  ExFreePoolWithTag(param_2,0);
  LOCK();
  piVar1 = (int *)(param_1 + 8);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    NdisSetEvent(param_1 + 0x10);
  }
  return;
}



===== TopCancelPendingReads @ 140003820 =====

void TopCancelPendingReads(longlong param_1)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  longlong *plVar4;
  longlong *plVar5;
  code *pcVar6;
  undefined1 uVar7;
  undefined1 *puVar8;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  
  uVar7 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x18);
  puVar8 = auStack_38;
LAB_140003857:
  do {
    plVar4 = *(longlong **)(param_1 + 0x148);
    if (plVar4 == (longlong *)(param_1 + 0x148)) {
LAB_140003944:
      *(undefined8 *)(puVar8 + -8) = 0x140003953;
      KeReleaseSpinLock(param_1 + 0x18,uVar7);
      return;
    }
    LOCK();
    lVar3 = plVar4[-8];
    plVar4[-8] = 0;
    UNLOCK();
    if (lVar3 != 0) {
      lVar3 = *plVar4;
      if (((longlong *)*(longlong *)(lVar3 + 8) != plVar4) ||
         (plVar5 = (longlong *)plVar4[1], (longlong *)*plVar5 != plVar4)) {
        pcVar6 = (code *)swi(0x29);
        (*pcVar6)(3);
        puVar8 = auStack_30;
        goto LAB_140003944;
      }
      *plVar5 = lVar3;
      *(longlong **)(lVar3 + 8) = plVar5;
      KeReleaseSpinLockFromDpcLevel(param_1 + 0x18);
      plVar4[-0xe] = 0;
      *(undefined4 *)(plVar4 + -0xf) = 0xc0000120;
      IofCompleteRequest(plVar4 + -0x15,0);
      LOCK();
      piVar1 = (int *)(param_1 + 0x30);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar2 == 1) {
        NdisFreeMemory(param_1,0,0);
      }
      KeAcquireSpinLockAtDpcLevel(param_1 + 0x18);
      LOCK();
      *(int *)(param_1 + 0x170) = *(int *)(param_1 + 0x170) + -1;
      UNLOCK();
      goto LAB_140003857;
    }
    KeReleaseSpinLock(param_1 + 0x18,uVar7);
    KeDelayExecutionThread(0,0);
    uVar7 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x18);
  } while( true );
}



===== ToppRequestCompletePrivateHandlerAtDpcLevel @ 140003980 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ToppRequestCompletePrivateHandlerAtDpcLevel
               (longlong param_1,longlong param_2,undefined4 param_3)

{
  if (*(code **)(param_2 + 0x108) != (code *)0x0) {
    (**(code **)(param_2 + 0x108))
              (param_1 + -0xa0,*(undefined8 *)(param_2 + 0x110),*(undefined8 *)(param_2 + 0x118),
               param_3);
  }
  ToppAdvanceRequestAtDpcLevel(param_1);
  return;
}



===== __report_gsfailure @ 1400039e0 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== WPP_SF_ @ 1400039f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_(undefined8 param_1,undefined2 param_2,undefined8 param_3)

{
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,0);
  return;
}



===== WPP_SF_Dd @ 140003a1c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Dd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,&param_5,4,0);
  return;
}



===== WPP_SF_D @ 140003a6c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_D(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,0);
  return;
}



===== WppClassicProviderCallback @ 140003ab0 =====

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



===== wil_details_FeatureDescriptors_SkipPadding @ 140003ae4 =====

longlong * wil_details_FeatureDescriptors_SkipPadding(longlong *param_1)

{
  while( true ) {
    if (&UNK_14000eb5f < param_1) {
      return (longlong *)0x0;
    }
    if (*param_1 != 0) break;
    param_1 = param_1 + 1;
  }
  return param_1;
}



===== wil_details_RecordCachedUsage @ 140003b0c =====

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



===== wil_details_RecordFeatureUsageReporting @ 140003c60 =====

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



===== WPP_SF_qqD @ 140003ce4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,&param_5,8,&param_6,4,0);
  return;
}



===== WPP_SF_qqDSDd @ 140003d44 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqDSDd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                  undefined1 param_5,undefined1 param_6,wchar_t *param_7,undefined1 param_8,
                  undefined1 param_9)

{
  longlong lVar1;
  wchar_t *pwVar2;
  undefined8 local_res20;
  
  if (param_7 == (wchar_t *)0x0) {
    lVar1 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_7[lVar1] != L'\0');
    lVar1 = lVar1 * 2 + 2;
  }
  pwVar2 = param_7;
  if (param_7 == (wchar_t *)0x0) {
    pwVar2 = L"NULL";
  }
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_23ef441b8cf036704207f83c1fc48158_Traceguids,0xc,&local_res20,8,
             &param_5,8,&param_6,4,pwVar2,lVar1,&param_8,4,&param_9,4,0);
  return;
}



===== TopEnableLLTDioPolicyCallback @ 140003e40 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void TopEnableLLTDioPolicyCallback(int *param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 uVar1;
  byte bVar2;
  int iVar3;
  undefined4 local_88;
  undefined2 local_84;
  undefined1 local_82 [10];
  undefined1 local_78 [24];
  code *local_60;
  code *local_58;
  code *local_50;
  code *local_48;
  code *local_40;
  code *local_30;
  code *local_28;
  code *local_20;
  code *local_18;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
    if (param_1 == (int *)0x0) {
      uVar1 = 1;
    }
    else {
      uVar1 = (undefined1)*param_1;
    }
    WPP_SF_qDq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),param_2,param_3,param_1,uVar1);
  }
  if ((param_1 == (int *)0x0) || (*param_1 != 0)) {
    LOCK();
    topActivePolicyFlags = topActivePolicyFlags & 0xfffffffe;
    UNLOCK();
    if (topNdisProtocolHandle == 0) {
      memset(local_82,0,0x7a);
      bVar2 = NdisGeneratePartialCancelId();
      local_88 = 0x800295;
      _topPartialNdisCancelId = (ulonglong)bVar2 << 0x38;
      local_84 = 0x5906;
      RtlInitUnicodeString(local_78,L"lltdio");
      local_50 = ToppOpenAdapterCompleteHandlerEx;
      local_48 = ToppCloseAdapterCompleteHandlerEx;
      local_18 = ToppSendNetBufferListsCompleteHandler;
      local_30 = TopOidRequestCompleteHandler;
      local_28 = ToppStatusHandlerEx;
      local_20 = ToppReceiveNetBufferListHandler;
      local_40 = ToppPnPEventHandler;
      local_60 = ToppBindAdapterHandlerEx;
      local_58 = ToppUnbindAdapterHandlerEx;
      iVar3 = NdisRegisterProtocolDriver(0,&local_88,&topNdisProtocolHandle);
      if (((iVar3 != 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
         ((1 < (byte)WPP_GLOBAL_Control[0x29] && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)))
         ) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                 &WPP_a011ba9f6767340892c0619c2587c1d2_Traceguids,iVar3);
      }
    }
  }
  else {
    LOCK();
    topActivePolicyFlags = topActivePolicyFlags | 1;
    UNLOCK();
    TopStopNdisBindingModule();
  }
  return;
}



===== TopReceiveNetBufferListFromBackChannel @ 140003ff0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void TopReceiveNetBufferListFromBackChannel(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  longlong *plVar4;
  char cVar5;
  ushort uVar6;
  longlong lVar7;
  uint uVar8;
  int iVar9;
  char *pcVar10;
  short *psVar11;
  
  cVar5 = KeGetCurrentIrql();
  uVar1 = *(uint *)(param_1 + 0x34);
  if ((uVar1 & 0x40) == 0) {
    if ((char)uVar1 < '\0') {
      uVar8 = topActivePolicyFlags & 8;
    }
    else {
      uVar8 = topActivePolicyFlags & 4;
    }
  }
  else {
    uVar8 = topActivePolicyFlags & 2;
  }
  if ((uVar8 == 0) && ((uVar1 & 7) == 0)) {
    for (; param_3 != (undefined8 *)0x0; param_3 = (undefined8 *)*param_3) {
      plVar4 = (longlong *)param_3[1];
      if ((*plVar4 == 0) &&
         (lVar7 = plVar4[1], 0xd < (uint)(*(int *)(lVar7 + 0x28) - (int)plVar4[2]))) {
        if ((*(byte *)(lVar7 + 10) & 5) == 0) {
          lVar7 = MmMapLockedPagesSpecifyCache(lVar7,0,1);
        }
        else {
          lVar7 = *(longlong *)(lVar7 + 0x18);
        }
        if ((((lVar7 != 0) &&
             (psVar11 = (short *)((ulonglong)*(uint *)(plVar4 + 2) + lVar7), psVar11 != (short *)0x0
             )) && (*(int *)(psVar11 + 4) == *(int *)(param_1 + 0x126))) &&
           (psVar11[3] == *(short *)(param_1 + 0x124))) {
          uVar6 = (ushort)psVar11[6] >> 8 | psVar11[6] << 8;
          iVar9 = 0xe;
          if (uVar6 == 0x8100) {
            if ((uint)(*(int *)(plVar4[1] + 0x28) - (int)plVar4[2]) < 0x12) goto LAB_14000424f;
            iVar9 = 0x12;
            uVar6 = (ushort)psVar11[8] >> 8 | psVar11[8] << 8;
          }
          if (uVar6 == 0x88d9) {
            iVar2 = (int)plVar4[3];
            uVar8 = (int)plVar4[2] + iVar9;
            uVar1 = *(uint *)(plVar4 + 5);
            if (uVar8 < *(uint *)(plVar4[1] + 0x28)) {
              *(uint *)(plVar4 + 2) = uVar8;
              *(uint *)(plVar4 + 5) = uVar1 + iVar9;
              *(int *)(plVar4 + 3) = iVar2 - iVar9;
            }
            else {
              NdisAdvanceNetBufferDataStart(plVar4,iVar9,0);
            }
            if (*(uint *)(plVar4 + 3) < 0x12) {
LAB_140004222:
              *(int *)(plVar4 + 3) = iVar2;
            }
            else {
              lVar7 = plVar4[1];
              if ((uint)(*(int *)(lVar7 + 0x28) - (int)plVar4[2]) < 0x12) {
                pcVar10 = (char *)NdisGetDataBuffer(plVar4);
                if (pcVar10 != (char *)0x0) {
                  uVar8 = (int)plVar4[2] + 0x12;
                  if (uVar8 < *(uint *)(plVar4[1] + 0x28)) {
                    *(int *)(plVar4 + 5) = (int)plVar4[5] + 0x12;
                    *(int *)(plVar4 + 3) = (int)plVar4[3] + -0x12;
                    *(uint *)(plVar4 + 2) = uVar8;
                  }
                  else {
                    NdisAdvanceNetBufferDataStart(plVar4);
                  }
                  goto LAB_1400042e5;
                }
                goto LAB_140004222;
              }
              if ((*(byte *)(lVar7 + 10) & 5) == 0) {
                lVar7 = MmMapLockedPagesSpecifyCache(lVar7);
              }
              else {
                lVar7 = *(longlong *)(lVar7 + 0x18);
              }
              if (lVar7 == 0) {
                pcVar10 = (char *)0x0;
              }
              else {
                pcVar10 = (char *)((ulonglong)*(uint *)(plVar4 + 2) + lVar7);
              }
              uVar8 = (int)plVar4[2] + 0x12;
              if (uVar8 < *(uint *)(plVar4[1] + 0x28)) {
                *(int *)(plVar4 + 5) = (int)plVar4[5] + 0x12;
                *(int *)(plVar4 + 3) = (int)plVar4[3] + -0x12;
                *(uint *)(plVar4 + 2) = uVar8;
              }
              else {
                NdisAdvanceNetBufferDataStart(plVar4);
              }
              if (pcVar10 == (char *)0x0) goto LAB_140004222;
LAB_1400042e5:
              if (((*pcVar10 != '\x01') || (1 < (byte)pcVar10[1])) ||
                 ((*(int *)(pcVar10 + 0xc) != *(int *)(param_1 + 0x126) ||
                  (*(short *)(pcVar10 + 10) != *(short *)(param_1 + 0x124))))) goto LAB_140004222;
              lVar7 = plVar4[10];
              uVar3 = *(undefined4 *)(param_3 + 0x11);
              *(int *)((longlong)plVar4 + 0x54) = iVar2;
              *(uint *)(plVar4 + 10) = uVar1;
              *(uint *)(param_3 + 0x11) = *(uint *)(param_3 + 0x11) & 0xffffc;
              TopReceiveHandler(param_1,(longlong)param_3,psVar11,pcVar10,cVar5 == '\x02');
              plVar4[10] = lVar7;
              *(undefined4 *)(param_3 + 0x11) = uVar3;
              *(int *)(plVar4 + 3) = iVar2;
            }
            lVar7 = plVar4[4];
            *(uint *)(plVar4 + 2) = uVar1;
            plVar4[1] = lVar7;
            *(uint *)(plVar4 + 5) = uVar1;
            if ((lVar7 != 0) && (*(uint *)(lVar7 + 0x28) < uVar1)) {
              NdisAdjustNetBufferCurrentMdl(plVar4);
            }
          }
        }
      }
LAB_14000424f:
    }
  }
  return;
}



===== ToppNetBufferListCompletionRoutine @ 140004380 =====

void ToppNetBufferListCompletionRoutine(longlong param_1)

{
  TopRestoreNetBufferList(param_1);
  return;
}



===== ToppOpenAdapterCompleteHandlerEx @ 1400043a0 =====

void ToppOpenAdapterCompleteHandlerEx(longlong param_1,undefined4 param_2)

{
  *(undefined4 *)(*(longlong *)(param_1 + 0x98) + 0x18) = param_2;
  NdisSetEvent();
  return;
}



===== ToppSendNetBufferListsCompleteHandler @ 1400043d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ToppSendNetBufferListsCompleteHandler
               (undefined8 *param_1,undefined8 *param_2,ulonglong param_3)

{
  int *piVar1;
  int iVar2;
  undefined8 *puVar3;
  byte bVar4;
  undefined8 *puVar5;
  undefined7 uVar6;
  
  if (param_2 != (undefined8 *)0x0) {
    bVar4 = (byte)param_3;
    puVar5 = param_1;
    do {
      puVar3 = (undefined8 *)*param_2;
      *param_2 = 0;
      uVar6 = (undefined7)(param_3 >> 8);
      if ((*(uint *)(param_2 + 0x11) & 0x30000000) == 0x10000000) {
        param_3 = CONCAT71(uVar6,bVar4) & 0xffffffffffffff01;
        puVar5 = param_1;
        TopSendCompletionHandler((longlong)param_1,(longlong)param_2,bVar4 & 1);
      }
      else if ((*(uint *)(param_2 + 0x11) & 0x30000000) == 0x20000000) {
        param_3 = CONCAT71(uVar6,bVar4) & 0xffffffffffffff01;
        QosautoSendCompletionHandler(puVar5,(longlong)param_2,param_3);
      }
      else {
        LOCK();
        piVar1 = (int *)(param_2 + 8);
        iVar2 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar2 == 1) {
          param_3 = param_2[0xb];
          (*(code *)param_2[9])(param_2,param_2[10],param_3,bVar4 & 1);
          puVar5 = param_2;
        }
        LOCK();
        *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + -1;
        UNLOCK();
      }
      param_2 = puVar3;
    } while (puVar3 != (undefined8 *)0x0);
  }
  return;
}



===== WPP_SF_DD @ 140004480 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_a011ba9f6767340892c0619c2587c1d2_Traceguids,0x16,local_res20,4,
             &param_5,4,0);
  return;
}



===== WPP_SF_L @ 1400044d8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_L(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_a011ba9f6767340892c0619c2587c1d2_Traceguids,0x17,local_res20,4,0);
  return;
}



===== WPP_SF_S @ 140004524 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_S(undefined8 param_1,undefined2 param_2,undefined8 param_3,wchar_t *param_4)

{
  longlong lVar1;
  
  if (param_4 == (wchar_t *)0x0) {
    lVar1 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_4[lVar1] != L'\0');
    lVar1 = lVar1 * 2 + 2;
  }
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"NULL";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_a011ba9f6767340892c0619c2587c1d2_Traceguids,param_2,param_4,lVar1,0);
  return;
}



===== WPP_SF_SLd @ 140004598 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_SLd(undefined8 param_1,undefined8 param_2,undefined8 param_3,wchar_t *param_4,
               undefined8 param_5,undefined1 param_6)

{
  longlong lVar1;
  undefined4 local_18 [6];
  
  local_18[0] = 0;
  if (param_4 == (wchar_t *)0x0) {
    lVar1 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_4[lVar1] != L'\0');
    lVar1 = lVar1 * 2 + 2;
  }
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"NULL";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_a011ba9f6767340892c0619c2587c1d2_Traceguids,0x18,param_4,lVar1,
             local_18,4,&param_6,4,0);
  return;
}



===== WPP_SF_Sd @ 140004638 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Sd(undefined8 param_1,undefined2 param_2,undefined8 param_3,wchar_t *param_4,
              undefined1 param_5)

{
  longlong lVar1;
  
  if (param_4 == (wchar_t *)0x0) {
    lVar1 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_4[lVar1] != L'\0');
    lVar1 = lVar1 * 2 + 2;
  }
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"NULL";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_a011ba9f6767340892c0619c2587c1d2_Traceguids,param_2,param_4,lVar1,
             &param_5,4,0);
  return;
}



===== WPP_SF__MAC_lDD @ 1400046c4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF__MAC_lDD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                    undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_a011ba9f6767340892c0619c2587c1d2_Traceguids,0x15,param_4,6,&param_5,4
             ,&param_6,4,&param_7,4,0);
  return;
}



===== WPP_SF_q @ 140004730 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_q(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_a011ba9f6767340892c0619c2587c1d2_Traceguids,0x12,&local_res20,8,0);
  return;
}



===== WPP_SF_qD @ 14000477c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_a011ba9f6767340892c0619c2587c1d2_Traceguids,param_2,&local_res20,8,
             &param_5,4,0);
  return;
}



===== WPP_SF_qDq @ 1400047d4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qDq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5)

{
  undefined8 local_res20;
  undefined8 local_18 [3];
  
  local_18[0] = topNdisProtocolHandle;
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_a011ba9f6767340892c0619c2587c1d2_Traceguids,0xc,&local_res20,8,
             &param_5,4,local_18,8,0);
  return;
}



===== Feature_405434683__private_IsEnabledDeviceUsageNoInline @ 140004844 =====

ulonglong Feature_405434683__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  undefined4 *local_res8;
  
  local_res8 = (undefined4 *)(ulonglong)Feature_405434683__private_featureState;
  if ((Feature_405434683__private_featureState & 0x10) == 0) {
    uVar1 = Feature_405434683__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_405434683__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_405434683__private_IsEnabledFallback @ 14000487c =====

void Feature_405434683__private_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2);
  return;
}



===== TopBindDevice @ 1400048a0 =====

int TopBindDevice(longlong param_1,longlong param_2,ushort *param_3,uint param_4,uint *param_5,
                 undefined8 *param_6)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  undefined1 uVar4;
  uint *puVar5;
  undefined8 *puVar6;
  int iVar7;
  bool bVar8;
  
  puVar5 = TopFindEA(param_5,"ObjectType",10);
  uVar4 = KeAcquireSpinLockRaiseToDpc(&topContextListLock);
  puVar6 = TopLookupDevice(param_3,param_4,(undefined8 *)0x0);
  if ((puVar6 == (undefined8 *)0x0) || ((*(uint *)((longlong)puVar6 + 0x34) & 1) != 0)) {
    KeReleaseSpinLock(&topContextListLock,uVar4);
    return (-(uint)(puVar6 != (undefined8 *)0x0) & 0x2ca) + 0xc0000034;
  }
  LOCK();
  *(int *)(puVar6 + 6) = *(int *)(puVar6 + 6) + 1;
  UNLOCK();
  KeReleaseSpinLockFromDpcLevel(&topContextListLock);
  KeAcquireSpinLockAtDpcLevel(puVar6 + 3);
  if ((param_2 != 0) && ((*(uint *)((longlong)puVar6 + 0x34) & 0x100) != 0)) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (1 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
              &WPP_b515efb401d631d3025e3a3f22783527_Traceguids);
    }
    iVar7 = -0x15557fff;
    goto LAB_140004a10;
  }
  if ((*(uint *)((longlong)puVar6 + 0x34) & 0x40) == 0) {
    if ((char)*(uint *)((longlong)puVar6 + 0x34) < '\0') {
      uVar3 = topActivePolicyFlags & 8;
      goto LAB_14000499c;
    }
    if ((topActivePolicyFlags & 4) == 0) goto LAB_1400049f6;
    iVar7 = -0x15558000;
  }
  else {
    uVar3 = topActivePolicyFlags & 2;
LAB_14000499c:
    if (uVar3 == 0) {
LAB_1400049f6:
      if (*(char *)((ulonglong)*(byte *)((longlong)puVar5 + 5) + 9 + (longlong)puVar5) != '\0') {
LAB_140004a48:
        KeReleaseSpinLock(puVar6 + 3,uVar4);
        *param_6 = puVar6;
        return 0;
      }
      LOCK();
      bVar8 = puVar6[0xf] == 0;
      if (bVar8) {
        puVar6[0xf] = param_1;
      }
      UNLOCK();
      if (bVar8) goto LAB_140004a48;
      iVar7 = -0x7fffffef;
      goto LAB_140004a10;
    }
    iVar7 = -0x3ffffc9c;
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (1 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
             &WPP_b515efb401d631d3025e3a3f22783527_Traceguids,iVar7);
  }
LAB_140004a10:
  KeReleaseSpinLock(puVar6 + 3,uVar4);
  LOCK();
  piVar1 = (int *)(puVar6 + 6);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    NdisFreeMemory(puVar6,0,0);
  }
  return iVar7;
}



===== TopDereferencePacketFilterSafe @ 140004aac =====

void TopDereferencePacketFilterSafe(longlong param_1,undefined8 param_2,undefined *param_3)

{
  int *piVar1;
  uint uVar2;
  char cVar3;
  undefined1 uVar4;
  uint uVar5;
  bool bVar6;
  undefined8 in_stack_ffffffffffffffd8;
  
  cVar3 = (char)param_2;
  uVar4 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x18);
  piVar1 = (int *)(param_1 + 0x70);
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    uVar5 = *(uint *)(param_1 + 0x34);
    do {
      LOCK();
      uVar2 = *(uint *)(param_1 + 0x34);
      bVar6 = uVar5 == uVar2;
      if (bVar6) {
        *(uint *)(param_1 + 0x34) = uVar5 | 4;
      }
      else {
        uVar5 = uVar2;
      }
      UNLOCK();
    } while (!bVar6);
    if ((uVar5 & 4) == 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)
         ) {
        param_3 = &WPP_b515efb401d631d3025e3a3f22783527_Traceguids;
        param_2 = 0x10;
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
                &WPP_b515efb401d631d3025e3a3f22783527_Traceguids);
      }
      TopQueueOidRequestAsynchronousAtDpcLevel
                (param_1 + 0xa0,param_2,param_3,&topNdisPacketFilterStop,in_stack_ffffffffffffffd8,0
                 ,0,0);
    }
  }
  if (cVar3 == '\0') {
    KeReleaseSpinLock(param_1 + 0x18,uVar4);
  }
  else {
    piVar1 = *(int **)(param_1 + 0x188);
    *(undefined8 *)(param_1 + 0x188) = 0;
    KeReleaseSpinLock();
    TopDeleteBackChannel(piVar1);
  }
  return;
}



===== TopReceiveHandler @ 140004bb0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void TopReceiveHandler(longlong param_1,longlong param_2,short *param_3,char *param_4,char param_5)

{
  longlong *plVar1;
  byte bVar2;
  int iVar3;
  longlong lVar4;
  longlong *plVar5;
  code *pcVar6;
  uint uVar7;
  ulonglong uVar8;
  longlong *plVar9;
  undefined *puVar10;
  longlong lVar11;
  uint *puVar12;
  undefined1 *puVar13;
  undefined1 *puVar14;
  uint uVar15;
  undefined *puVar16;
  bool bVar17;
  undefined1 auStackY_88 [8];
  undefined1 auStackY_80 [24];
  longlong local_58;
  undefined4 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_88;
  lVar4 = *(longlong *)(param_2 + 8);
  local_58 = 0;
  puVar14 = auStackY_88;
  if ((*(uint *)(param_1 + 0x34) & 8) == 0) goto LAB_140004f34;
  if (*param_4 == '\0') {
    uVar15 = ((int)param_4 - (int)param_3) + 0x1c;
LAB_140004da8:
    puVar16 = &topSmallDescriptorLookasideList;
  }
  else {
    puVar14 = auStackY_88;
    if (0xc < (byte)param_4[3]) goto LAB_140004f34;
    lVar11 = ((ulonglong)(byte)param_4[1] * 0xd + (ulonglong)(byte)param_4[3]) * 0x10;
    puVar12 = (uint *)(&topMappingProtocolRules + lVar11);
    puVar14 = auStackY_88;
    if (*(uint *)(lVar4 + 0x18) < *puVar12) goto LAB_140004f34;
    uVar15 = *(uint *)(&DAT_14000d75c + lVar11) & 0xc;
    if (uVar15 != 0) {
      iVar3 = *(int *)(param_1 + 0x126);
      if (((*(int *)(param_3 + 1) != iVar3) || (*param_3 != *(short *)(param_1 + 0x124))) &&
         ((puVar14 = auStackY_88, (char)*param_3 != -1 ||
          ((((puVar14 = auStackY_88, *(char *)((longlong)param_3 + 1) != -1 ||
             (puVar14 = auStackY_88, (char)param_3[1] != -1)) ||
            (puVar14 = auStackY_88, *(char *)((longlong)param_3 + 3) != -1)) ||
           ((puVar14 = auStackY_88, (char)param_3[2] != -1 ||
            (puVar14 = auStackY_88, *(char *)((longlong)param_3 + 5) != -1))))))))
      goto LAB_140004f34;
      if (uVar15 == 4) {
        puVar14 = auStackY_88;
        if (*(int *)(param_4 + 6) != iVar3) goto LAB_140004f34;
        bVar17 = *(short *)(param_4 + 4) == *(short *)(param_1 + 0x124);
      }
      else {
        if (((((byte)*(uint *)(&DAT_14000d75c + lVar11) & 0xc) != 8) &&
            (*(int *)(param_4 + 6) == iVar3)) &&
           (*(short *)(param_4 + 4) == *(short *)(param_1 + 0x124))) goto LAB_140004d07;
        puVar14 = auStackY_88;
        if ((((param_4[4] != -1) || (puVar14 = auStackY_88, param_4[5] != -1)) ||
            (puVar14 = auStackY_88, param_4[6] != -1)) ||
           ((puVar14 = auStackY_88, param_4[7] != -1 || (puVar14 = auStackY_88, param_4[8] != -1))))
        goto LAB_140004f34;
        bVar17 = param_4[9] == -1;
      }
      puVar14 = auStackY_88;
      if (!bVar17) goto LAB_140004f34;
    }
LAB_140004d07:
    if ((*(uint *)(&DAT_14000d75c + lVar11) & 2) == 0) {
      if (((*(uint *)(&DAT_14000d75c + lVar11) & 1) == 0) &&
         (puVar14 = auStackY_88, *(short *)(param_4 + 0x10) != 0)) goto LAB_140004f34;
    }
    else {
      puVar14 = auStackY_88;
      if (*(short *)(param_4 + 0x10) == 0) goto LAB_140004f34;
    }
    bVar2 = (&DAT_14000d758)[lVar11];
    if (bVar2 == 0xfe) {
      uVar15 = (int)param_4 + 0x12 + (*puVar12 - (int)param_3);
      goto LAB_140004da8;
    }
    if ((bVar2 != 0xff) &&
       (puVar14 = auStackY_88,
       *(uint *)(lVar4 + 0x18) <
       ((ushort)(*(ushort *)(param_4 + (ulonglong)bVar2 + 0x12) >> 8 |
                *(ushort *)(param_4 + (ulonglong)bVar2 + 0x12) << 8) & 0x3fff) *
       (uint)(byte)(&DAT_14000d759)[lVar11] + *puVar12)) goto LAB_140004f34;
    uVar15 = *(uint *)(lVar4 + 0x54);
    puVar16 = &topFullDescriptorLookasideList;
    uVar8 = Feature_405434683__private_IsEnabledDeviceUsageNoInline();
    if (((int)uVar8 != 0) && (0x5ea < uVar15)) {
      local_58 = 0x3c05497;
      local_50 = 0;
      RtlLogUnexpectedCodepath(&local_58);
      puVar14 = auStackY_88;
      goto LAB_140004f34;
    }
  }
  if (param_5 == '\0') {
    KeAcquireSpinLockRaiseToDpc(&topDescriptorLookasideListLock);
  }
  else {
    KeAcquireSpinLockAtDpcLevel();
  }
  plVar9 = (longlong *)ExAllocateFromNPagedLookasideList(puVar16);
  puVar10 = &topDescriptorLookasideListLock;
  if (plVar9 == (longlong *)0x0) {
LAB_140004f06:
    puVar13 = auStackY_88;
    if (param_5 != '\0') {
      KeReleaseSpinLockFromDpcLevel(puVar10);
      puVar14 = auStackY_88;
      goto LAB_140004f34;
    }
  }
  else {
    KeReleaseSpinLockFromDpcLevel(&topDescriptorLookasideListLock);
    plVar9[2] = (longlong)puVar16;
    *(uint *)(plVar9 + 3) = uVar15;
    TopRtlCopyMdlToBuffer
              (*(undefined8 **)(lVar4 + 0x20),(ulonglong)*(uint *)(lVar4 + 0x50),plVar9 + 4,
               (ulonglong)uVar15,&local_58);
    puVar10 = (undefined *)(param_1 + 0x18);
    KeAcquireSpinLockAtDpcLevel(puVar10);
    if (((byte)*(undefined4 *)(param_1 + 0x34) & 0xf) != 8) {
LAB_140004ed1:
      KeReleaseSpinLockFromDpcLevel(param_1 + 0x18);
      KeAcquireSpinLockAtDpcLevel(&topDescriptorLookasideListLock);
      ExFreeToNPagedLookasideList(plVar9[2],plVar9);
      puVar10 = &topDescriptorLookasideListLock;
      goto LAB_140004f06;
    }
    plVar1 = (longlong *)(param_1 + 0x158);
    lVar4 = *plVar1;
    if (*(longlong **)(lVar4 + 8) == plVar1) {
      *plVar9 = lVar4;
      plVar9[1] = (longlong)plVar1;
      *(longlong **)(lVar4 + 8) = plVar9;
      *plVar1 = (longlong)plVar9;
      uVar15 = *(int *)(param_1 + 0x16c) + uVar15;
      uVar7 = *(int *)(param_1 + 0x168) + 1;
      *(uint *)(param_1 + 0x16c) = uVar15;
      *(uint *)(param_1 + 0x168) = uVar7;
      if ((uVar15 < 0x8001) && (uVar7 < 0x3e9)) {
        ToppServiceReadRequestsUnderLock(param_1);
        goto LAB_140004f06;
      }
      plVar9 = *(longlong **)(param_1 + 0x160);
      if (((longlong *)*plVar9 == plVar1) &&
         (plVar5 = (longlong *)plVar9[1], (longlong *)*plVar5 == plVar9)) {
        *(longlong **)(param_1 + 0x160) = plVar5;
        *plVar5 = (longlong)plVar1;
        *(int *)(param_1 + 0x168) = *(int *)(param_1 + 0x168) + -1;
        *(int *)(param_1 + 0x16c) = *(int *)(param_1 + 0x16c) - (int)plVar9[3];
        goto LAB_140004ed1;
      }
    }
    pcVar6 = (code *)swi(0x29);
    (*pcVar6)(3);
    puVar13 = auStackY_80;
  }
  *(undefined8 *)(puVar13 + -8) = 0x140004f2f;
  KeReleaseSpinLock();
  puVar14 = puVar13;
LAB_140004f34:
  *(undefined8 *)(puVar14 + -8) = 0x140004f41;
  return;
}



===== TopRegisterUnbindNotification @ 140004f58 =====

undefined8 TopRegisterUnbindNotification(longlong param_1,longlong param_2,ulonglong param_3)

{
  longlong lVar1;
  byte *pbVar2;
  code *pcVar3;
  undefined1 uVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  undefined1 *puVar9;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  lVar1 = param_1 + 0x18;
  uVar4 = KeAcquireSpinLockRaiseToDpc(lVar1);
  puVar9 = auStack_28;
  if ((*(uint *)(param_1 + 0x34) & 1) == 0) {
    LOCK();
    *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + 1;
    UNLOCK();
    LOCK();
    *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + 1;
    UNLOCK();
    for (puVar6 = *(undefined8 **)(param_1 + 0x178);
        (puVar6 != (undefined8 *)(param_1 + 0x178) && ((ulonglong)puVar6[-6] < param_3));
        puVar6 = (undefined8 *)*puVar6) {
    }
    *(ulonglong *)(param_2 + 0x78) = param_3;
    puVar7 = (undefined8 *)(param_2 + 0xa8);
    *(longlong *)(param_2 + 0x80) = param_1;
    puVar8 = (undefined8 *)puVar6[1];
    if ((undefined8 *)*puVar8 != puVar6) {
      puVar7 = (undefined8 *)0x3;
      pcVar3 = (code *)swi(0x29);
      puVar6 = (undefined8 *)(*pcVar3)();
      puVar9 = auStack_20;
    }
    *puVar7 = puVar6;
    puVar7[1] = puVar8;
    *puVar8 = puVar7;
    puVar6[1] = puVar7;
    LOCK();
    *(code **)(param_2 + 0x68) = ToppCancelUnbindNotifyIrpCallback;
    UNLOCK();
    pbVar2 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar2 = *pbVar2 | 1;
    *(undefined8 *)(puVar9 + -8) = 0x140005022;
    KeReleaseSpinLock(lVar1,uVar4);
    uVar5 = 0;
  }
  else {
    KeReleaseSpinLock(lVar1,uVar4);
    uVar5 = 0xc00002fe;
  }
  return uVar5;
}



===== TopSendCompletionHandler @ 140005048 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TopSendCompletionHandler(longlong param_1,longlong param_2,char param_3)

{
  int *piVar1;
  longlong *plVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  longlong lVar6;
  longlong *plVar7;
  code *pcVar8;
  undefined1 uVar9;
  undefined4 uVar10;
  ulonglong uVar11;
  
  lVar5 = *(longlong *)(param_2 + 0x58);
  uVar11 = 0;
  uVar9 = 0;
  IoAcquireCancelSpinLock(lVar5 + 0x45);
  LOCK();
  *(undefined8 *)(lVar5 + 0x68) = 0;
  UNLOCK();
  *(undefined8 *)(lVar5 + 0x78) = 0;
  IoReleaseCancelSpinLock(*(undefined1 *)(lVar5 + 0x45));
  if (param_3 == '\0') {
    uVar9 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x18);
  }
  else {
    KeAcquireSpinLockAtDpcLevel();
  }
  plVar2 = (longlong *)(lVar5 + 0xa8);
  lVar6 = *plVar2;
  if ((*(longlong **)(lVar6 + 8) != plVar2) ||
     (plVar7 = *(longlong **)(lVar5 + 0xb0), (longlong *)*plVar7 != plVar2)) {
    pcVar8 = (code *)swi(0x29);
    (*pcVar8)(3);
    pcVar8 = (code *)swi(3);
    (*pcVar8)();
    return;
  }
  *plVar7 = lVar6;
  *(longlong **)(lVar6 + 8) = plVar7;
  if (param_3 == '\0') {
    KeReleaseSpinLock(param_1 + 0x18,CONCAT71((int7)((ulonglong)plVar7 >> 8),uVar9));
  }
  else {
    KeReleaseSpinLockFromDpcLevel();
  }
  iVar4 = *(int *)(param_2 + 0x8c);
  LOCK();
  piVar1 = (int *)(param_2 + 0x40);
  iVar3 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar3 == 1) {
    (**(code **)(param_2 + 0x48))
              (param_2,*(undefined8 *)(param_2 + 0x50),*(undefined8 *)(param_2 + 0x58),param_3);
  }
  if (iVar4 == 0) {
    uVar10 = 0;
    uVar11 = (ulonglong)*(uint *)(*(longlong *)(lVar5 + 0xb8) + 8);
  }
  else {
    uVar10 = 0xc0000001;
  }
  *(ulonglong *)(lVar5 + 0x38) = uVar11;
  *(undefined4 *)(lVar5 + 0x30) = uVar10;
  IofCompleteRequest(lVar5,0);
  LOCK();
  *(int *)(param_1 + 0x140) = *(int *)(param_1 + 0x140) + -1;
  UNLOCK();
  LOCK();
  piVar1 = (int *)(param_1 + 0x30);
  iVar3 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar3 == 1) {
    NdisFreeMemory(param_1,0,0);
  }
  return;
}



===== ToppCancelReadCallback @ 1400051c0 =====

void ToppCancelReadCallback(undefined8 param_1,undefined8 *param_2)

{
  int *piVar1;
  undefined8 *puVar2;
  int iVar3;
  longlong lVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  code *pcVar7;
  undefined1 uVar8;
  undefined8 *puVar9;
  
  IoReleaseCancelSpinLock(*(undefined1 *)((longlong)param_2 + 0x45));
  lVar4 = param_2[0xf];
  uVar8 = KeAcquireSpinLockRaiseToDpc(lVar4 + 0x18);
  puVar2 = (undefined8 *)(lVar4 + 0x148);
  puVar9 = (undefined8 *)*puVar2;
  do {
    if (puVar9 == puVar2) {
LAB_14000524a:
      KeReleaseSpinLock(lVar4 + 0x18,uVar8);
      if (puVar9 != puVar2) {
        param_2[7] = 0;
        *(undefined4 *)(param_2 + 6) = 0xc0000120;
        IofCompleteRequest(param_2,0);
        LOCK();
        piVar1 = (int *)(lVar4 + 0x30);
        iVar3 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar3 == 1) {
          NdisFreeMemory(lVar4,0,0);
        }
      }
      return;
    }
    puVar5 = (undefined8 *)*puVar9;
    if (param_2 == puVar9 + -0x15) {
      if (((undefined8 *)puVar5[1] != puVar9) ||
         (puVar6 = (undefined8 *)puVar9[1], (undefined8 *)*puVar6 != puVar9)) {
        pcVar7 = (code *)swi(0x29);
        (*pcVar7)(3);
        pcVar7 = (code *)swi(3);
        (*pcVar7)();
        return;
      }
      *puVar6 = puVar5;
      puVar5[1] = puVar6;
      LOCK();
      *(int *)(lVar4 + 0x170) = *(int *)(lVar4 + 0x170) + -1;
      UNLOCK();
      goto LAB_14000524a;
    }
    puVar9 = puVar5;
  } while( true );
}



===== ToppCancelUnbindNotifyIrpCallback @ 1400052d0 =====

void ToppCancelUnbindNotifyIrpCallback(undefined8 param_1,undefined8 ***param_2)

{
  undefined8 **ppuVar1;
  int iVar2;
  undefined8 **ppuVar3;
  
  LOCK();
  param_2[0xd] = (undefined8 **)0x0;
  UNLOCK();
  IoReleaseCancelSpinLock(*(undefined1 *)((longlong)param_2 + 0x45));
  ppuVar3 = param_2[0x10];
  TopUnregisterUnbindNotification((longlong)ppuVar3,param_2,(undefined8 **)0x0,0xc0000120);
  LOCK();
  ppuVar1 = ppuVar3 + 6;
  iVar2 = *(int *)ppuVar1;
  *(int *)ppuVar1 = *(int *)ppuVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    NdisFreeMemory(ppuVar3,0,0);
  }
  return;
}



===== ToppCancelWriteCallback @ 140005340 =====

void ToppCancelWriteCallback(undefined8 param_1,undefined8 *param_2)

{
  longlong lVar1;
  int *piVar2;
  undefined8 *puVar3;
  int iVar4;
  longlong lVar5;
  undefined1 uVar6;
  undefined8 uVar7;
  undefined8 *puVar8;
  
  lVar5 = param_2[0xf];
  uVar7 = 0;
  if (lVar5 == 0) {
    IoReleaseCancelSpinLock(*(undefined1 *)((longlong)param_2 + 0x45));
  }
  else {
    if ((*(uint *)(lVar5 + 0x34) & 1) == 0) {
      LOCK();
      *(int *)(lVar5 + 0x30) = *(int *)(lVar5 + 0x30) + 1;
      UNLOCK();
    }
    IoReleaseCancelSpinLock(*(undefined1 *)((longlong)param_2 + 0x45));
    lVar1 = lVar5 + 0x18;
    uVar6 = KeAcquireSpinLockRaiseToDpc(lVar1);
    if ((*(uint *)(lVar5 + 0x34) & 1) == 0) {
      puVar3 = (undefined8 *)(lVar5 + 0x130);
      for (puVar8 = (undefined8 *)*puVar3; puVar8 != puVar3; puVar8 = (undefined8 *)*puVar8) {
        if (param_2 == puVar8 + -0x15) {
          uVar7 = param_2[0x10];
          LOCK();
          *(int *)(lVar5 + 0x140) = *(int *)(lVar5 + 0x140) + 1;
          UNLOCK();
          break;
        }
      }
      KeReleaseSpinLock(lVar1,uVar6);
      if (puVar8 != puVar3) {
        NdisCancelSendNetBufferLists(*(undefined8 *)(lVar5 + 0x80),uVar7);
        LOCK();
        *(int *)(lVar5 + 0x140) = *(int *)(lVar5 + 0x140) + -1;
        UNLOCK();
      }
    }
    else {
      KeReleaseSpinLock(lVar1,uVar6);
    }
    LOCK();
    piVar2 = (int *)(lVar5 + 0x30);
    iVar4 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar4 == 1) {
      NdisFreeMemory(lVar5,0,0);
    }
  }
  return;
}



===== ToppCleanupHandler @ 140005470 =====

undefined8 ToppCleanupHandler(longlong param_1,longlong param_2)

{
  undefined1 uVar1;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    WPP_SF_qqD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
               &WPP_b515efb401d631d3025e3a3f22783527_Traceguids,
               *(undefined8 *)(*(longlong *)(param_2 + 0xb8) + 0x30),(char)param_1,
               (char)*(undefined4 *)(param_1 + 0x30));
  }
  ToppEnableMappingSupport(param_1,'\0');
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x18);
  *(undefined8 *)(param_1 + 0x78) = 0;
  KeReleaseSpinLock(param_1 + 0x18,uVar1);
  TopCancelPendingReads(param_1);
  TopFlushReceiveQueue(param_1);
  return 0;
}



===== ToppCloseHandler @ 140005520 =====

undefined8 ToppCloseHandler(longlong param_1,longlong param_2)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  
  lVar3 = *(longlong *)(param_2 + 0xb8);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    WPP_SF_qqD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
               &WPP_b515efb401d631d3025e3a3f22783527_Traceguids,*(undefined8 *)(lVar3 + 0x30),
               (char)param_1,(char)*(undefined4 *)(param_1 + 0x30));
  }
  LOCK();
  piVar1 = (int *)(param_1 + 0x30);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    NdisFreeMemory(param_1,0,0);
  }
  *(undefined8 *)(*(longlong *)(lVar3 + 0x30) + 0x18) = 0;
  return 0;
}



===== ToppDeviceControlHandler @ 1400055c0 =====

ulonglong ToppDeviceControlHandler(longlong param_1,longlong param_2)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  undefined8 *puVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  undefined4 in_stack_ffffffffffffffe8;
  
  lVar3 = *(longlong *)(param_2 + 0xb8);
  iVar2 = *(int *)(lVar3 + 0x10);
  *(undefined8 *)(param_2 + 0x38) = 0;
  if (param_1 == 0) {
    return 0xc0000008;
  }
  if ((*(uint *)(param_1 + 0x34) & 1) != 0) {
    return 0xc00002fe;
  }
  LOCK();
  *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + 1;
  UNLOCK();
  if (*(int *)(lVar3 + 0x18) == 0x124018) {
    if ((iVar2 == 0) && (0x17 < *(uint *)(lVar3 + 8))) {
      puVar4 = *(undefined8 **)(param_2 + 0x18);
      uVar5 = TopOidRequestSynchronousSafe
                        (param_1,0,0x10107,(longlong)puVar4 + 0x14,in_stack_ffffffffffffffe8);
      uVar6 = uVar5 & 0xffffffff;
      if ((int)uVar5 == 0) {
        *puVar4 = *(undefined8 *)(param_1 + 0x88);
        *(undefined4 *)(puVar4 + 1) = *(undefined4 *)(param_1 + 0x90);
        *(undefined4 *)((longlong)puVar4 + 0xc) = *(undefined4 *)(param_1 + 0x124);
        *(undefined2 *)(puVar4 + 2) = *(undefined2 *)(param_1 + 0x128);
        *(undefined8 *)(param_2 + 0x38) = 0x18;
      }
      goto LAB_14000569c;
    }
  }
  else {
    if (*(int *)(lVar3 + 0x18) != 0x128004) {
      uVar6 = 0xc0000010;
      goto LAB_14000569c;
    }
    if ((iVar2 == 1) && (*(int *)(lVar3 + 8) == 0)) {
      uVar6 = ToppEnableMappingSupport(param_1,**(char **)(param_2 + 0x18));
      uVar6 = uVar6 & 0xffffffff;
      goto LAB_14000569c;
    }
  }
  uVar6 = 0xc000000d;
LAB_14000569c:
  LOCK();
  piVar1 = (int *)(param_1 + 0x30);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    NdisFreeMemory(param_1,0,0);
  }
  return uVar6;
}



===== ToppReadHandler @ 1400056f0 =====

undefined4 ToppReadHandler(longlong param_1,longlong param_2)

{
  int *piVar1;
  byte *pbVar2;
  longlong *plVar3;
  int iVar4;
  code *pcVar5;
  uint uVar6;
  undefined1 uVar7;
  longlong lVar8;
  void *_Dst;
  undefined8 *puVar9;
  longlong *plVar10;
  undefined8 *puVar11;
  undefined4 uVar12;
  undefined1 *puVar13;
  undefined1 *puVar14;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  undefined4 local_18;
  undefined4 local_10;
  
  puVar14 = auStack_38;
  puVar11 = *(undefined8 **)(param_2 + 0xb8);
  if (param_1 == 0) goto LAB_1400059a6;
  if ((*(uint *)(param_1 + 0x34) & 0x40) == 0) {
    if ((char)*(uint *)(param_1 + 0x34) < '\0') {
      uVar6 = topActivePolicyFlags & 8;
      goto LAB_140005734;
    }
    if ((topActivePolicyFlags & 4) == 0) goto LAB_140005794;
    uVar12 = 0xeaaa8000;
  }
  else {
    uVar6 = topActivePolicyFlags & 2;
LAB_140005734:
    if (uVar6 == 0) {
LAB_140005794:
      lVar8 = *(longlong *)(param_2 + 8);
      puVar14 = auStack_38;
      if (((lVar8 == 0) || (puVar14 = auStack_38, *(uint *)(puVar11 + 1) < 0xe)) ||
         (puVar14 = auStack_38, *(uint *)(lVar8 + 0x28) < *(uint *)(puVar11 + 1)))
      goto LAB_1400059a6;
      if ((*(byte *)(lVar8 + 10) & 5) == 0) {
        local_10 = 0x40000010;
        local_18 = 0;
        puVar11 = (undefined8 *)0x0;
        lVar8 = MmMapLockedPagesSpecifyCache(lVar8,0,1);
      }
      else {
        lVar8 = *(longlong *)(lVar8 + 0x18);
      }
      puVar14 = auStack_38;
      if (lVar8 == 0) goto LAB_1400059a6;
      lVar8 = param_1 + 0x18;
      *(longlong *)(param_2 + 0x78) = param_1;
      uVar7 = KeAcquireSpinLockRaiseToDpc(lVar8);
      puVar13 = auStack_38;
      if ((*(uint *)(param_1 + 0x34) & 1) != 0) {
        KeReleaseSpinLock(lVar8,uVar7);
        puVar14 = auStack_38;
        goto LAB_1400059a6;
      }
      LOCK();
      *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + 1;
      UNLOCK();
      plVar10 = (longlong *)(param_1 + 0x148);
      if (((longlong *)*plVar10 == plVar10) &&
         (plVar3 = (longlong *)(param_1 + 0x158), (longlong *)*plVar3 != plVar3)) {
        puVar9 = *(undefined8 **)(param_1 + 0x160);
        if (((longlong *)*puVar9 == plVar3) &&
           (plVar10 = (longlong *)puVar9[1], (undefined8 *)*plVar10 == puVar9)) {
          *(longlong **)(param_1 + 0x160) = plVar10;
          *plVar10 = (longlong)plVar3;
          *(int *)(param_1 + 0x168) = *(int *)(param_1 + 0x168) + -1;
          *(int *)(param_1 + 0x16c) = *(int *)(param_1 + 0x16c) - *(int *)(puVar9 + 3);
          KeReleaseSpinLockFromDpcLevel(lVar8);
          lVar8 = *(longlong *)(param_2 + 8);
          uVar6 = *(uint *)(puVar9 + 3);
          if (*(uint *)(lVar8 + 0x28) < *(uint *)(puVar9 + 3)) {
            uVar6 = *(uint *)(lVar8 + 0x28);
          }
          if ((*(byte *)(lVar8 + 10) & 5) == 0) {
            local_10 = 0x40000010;
            local_18 = 0;
            _Dst = (void *)MmMapLockedPagesSpecifyCache(lVar8,0,1);
          }
          else {
            _Dst = *(void **)(lVar8 + 0x18);
          }
          memmove(_Dst,puVar9 + 4,(ulonglong)uVar6);
          KeAcquireSpinLockAtDpcLevel(&topDescriptorLookasideListLock);
          ExFreeToNPagedLookasideList(puVar9[2],puVar9);
          KeReleaseSpinLock(&topDescriptorLookasideListLock,uVar7);
          LOCK();
          piVar1 = (int *)(param_1 + 0x30);
          iVar4 = *piVar1;
          *piVar1 = *piVar1 + -1;
          UNLOCK();
          if (iVar4 == 1) {
            NdisFreeMemory(param_1,0,0);
          }
          *(ulonglong *)(param_2 + 0x38) = (ulonglong)uVar6;
          puVar14 = auStack_38;
          goto LAB_1400059a6;
        }
LAB_14000593d:
        plVar10 = (longlong *)0x3;
        pcVar5 = (code *)swi(0x29);
        puVar9 = (undefined8 *)(*pcVar5)();
        puVar13 = auStack_30;
      }
      else {
        puVar11 = *(undefined8 **)(param_1 + 0x150);
        puVar9 = (undefined8 *)(param_2 + 0xa8);
        if ((longlong *)*puVar11 != plVar10) goto LAB_14000593d;
      }
      *puVar9 = plVar10;
      puVar9[1] = puVar11;
      *puVar11 = puVar9;
      plVar10[1] = (longlong)puVar9;
      LOCK();
      *(int *)(param_1 + 0x170) = *(int *)(param_1 + 0x170) + 1;
      UNLOCK();
      LOCK();
      *(code **)(param_2 + 0x68) = ToppCancelReadCallback;
      UNLOCK();
      pbVar2 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
      *pbVar2 = *pbVar2 | 1;
      *(undefined8 *)(puVar13 + -8) = 0x14000597c;
      KeReleaseSpinLock(lVar8,uVar7);
      puVar14 = puVar13;
      goto LAB_1400059a6;
    }
    uVar12 = 0xc0000364;
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (1 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
             &WPP_b515efb401d631d3025e3a3f22783527_Traceguids,uVar12);
  }
  puVar14 = auStack_38;
LAB_1400059a6:
  return (int)*(undefined8 *)(puVar14 + 0x40);
}



===== ToppReferenceCompletionCallback @ 1400059d0 =====

void ToppReferenceCompletionCallback
               (undefined8 param_1,undefined8 param_2,undefined4 *param_3,undefined4 param_4)

{
  *param_3 = param_4;
  KeSetEvent(param_2,0,0);
  return;
}



===== ToppServiceReadRequestsUnderLock @ 1400059f8 =====

void ToppServiceReadRequestsUnderLock(longlong param_1)

{
  int *piVar1;
  longlong *plVar2;
  longlong *plVar3;
  int iVar4;
  longlong lVar5;
  uint uVar6;
  longlong *plVar7;
  undefined8 *puVar8;
  code *pcVar9;
  void *_Dst;
  longlong *plVar10;
  
  plVar2 = (longlong *)(param_1 + 0x148);
  while( true ) {
    if ((longlong *)*plVar2 == plVar2) {
      return;
    }
    plVar3 = (longlong *)(param_1 + 0x158);
    plVar10 = (longlong *)*plVar2;
    if ((longlong *)*plVar3 == plVar3) {
      return;
    }
    while( true ) {
      if (plVar10 == plVar2) {
        return;
      }
      LOCK();
      lVar5 = plVar10[-8];
      plVar10[-8] = 0;
      UNLOCK();
      plVar7 = (longlong *)*plVar10;
      if (lVar5 != 0) break;
      plVar10 = plVar7;
    }
    if (((longlong *)plVar7[1] != plVar10) ||
       (puVar8 = (undefined8 *)plVar10[1], (longlong *)*puVar8 != plVar10)) break;
    *puVar8 = plVar7;
    plVar7[1] = (longlong)puVar8;
    if (plVar10 + -0x15 == (longlong *)0x0) {
      return;
    }
    puVar8 = *(undefined8 **)(param_1 + 0x160);
    if (((longlong *)*puVar8 != plVar3) ||
       (plVar7 = (longlong *)puVar8[1], (undefined8 *)*plVar7 != puVar8)) break;
    *(longlong **)(param_1 + 0x160) = plVar7;
    *plVar7 = (longlong)plVar3;
    *(int *)(param_1 + 0x168) = *(int *)(param_1 + 0x168) + -1;
    *(int *)(param_1 + 0x16c) = *(int *)(param_1 + 0x16c) - *(int *)(puVar8 + 3);
    KeReleaseSpinLockFromDpcLevel(param_1 + 0x18);
    lVar5 = plVar10[-0x14];
    uVar6 = *(uint *)(puVar8 + 3);
    if (*(uint *)(lVar5 + 0x28) < *(uint *)(puVar8 + 3)) {
      uVar6 = *(uint *)(lVar5 + 0x28);
    }
    if ((*(byte *)(lVar5 + 10) & 5) == 0) {
      _Dst = (void *)MmMapLockedPagesSpecifyCache(lVar5,0,1,0,0,0x40000010);
    }
    else {
      _Dst = *(void **)(lVar5 + 0x18);
    }
    memmove(_Dst,puVar8 + 4,(ulonglong)uVar6);
    *(undefined4 *)(plVar10 + -0xf) = 0;
    plVar10[-0xe] = (ulonglong)uVar6;
    IofCompleteRequest(plVar10 + -0x15,2);
    KeAcquireSpinLockAtDpcLevel(&topDescriptorLookasideListLock);
    ExFreeToNPagedLookasideList(puVar8[2],puVar8);
    KeReleaseSpinLockFromDpcLevel(&topDescriptorLookasideListLock);
    LOCK();
    piVar1 = (int *)(param_1 + 0x30);
    iVar4 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar4 == 1) {
      NdisFreeMemory(param_1,0,0);
    }
    KeAcquireSpinLockAtDpcLevel(param_1 + 0x18);
    LOCK();
    *(int *)(param_1 + 0x170) = *(int *)(param_1 + 0x170) + -1;
    UNLOCK();
  }
  pcVar9 = (code *)swi(0x29);
  (*pcVar9)(3);
  return;
}



===== ToppWriteHandler @ 140005bd0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 ToppWriteHandler(longlong param_1,longlong param_2)

{
  byte *pbVar1;
  int *piVar2;
  int *piVar3;
  undefined8 uVar4;
  code *pcVar5;
  bool bVar6;
  bool bVar7;
  undefined1 uVar8;
  ushort uVar9;
  int iVar10;
  short *psVar11;
  longlong lVar12;
  longlong *plVar13;
  longlong lVar14;
  longlong lVar15;
  longlong *plVar16;
  undefined4 uVar17;
  undefined1 *puVar18;
  uint uVar19;
  undefined1 auStackY_58 [8];
  undefined1 auStackY_50 [24];
  undefined4 in_stack_ffffffffffffffc8;
  undefined4 in_stack_ffffffffffffffcc;
  
  if (param_1 == 0) {
    return 0xc0000008;
  }
  if ((*(uint *)(param_1 + 0x34) & 0x40) == 0) {
    if ((char)*(uint *)(param_1 + 0x34) < '\0') {
      uVar19 = topActivePolicyFlags & 8;
      goto LAB_140005c17;
    }
    if ((topActivePolicyFlags & 4) != 0) {
      uVar17 = 0xeaaa8000;
      goto LAB_140005c37;
    }
  }
  else {
    uVar19 = topActivePolicyFlags & 2;
LAB_140005c17:
    if (uVar19 != 0) {
      uVar17 = 0xc0000364;
LAB_140005c37:
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return uVar17;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
        return uVar17;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) {
        return uVar17;
      }
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
               &WPP_b515efb401d631d3025e3a3f22783527_Traceguids,uVar17);
      return uVar17;
    }
  }
  lVar15 = *(longlong *)(param_2 + 8);
  uVar19 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 8);
  if (lVar15 == 0) {
    return 0xc000000d;
  }
  if (uVar19 < 0xe) {
    return 0xc000000d;
  }
  if (*(uint *)(lVar15 + 0x28) < uVar19) {
    return 0xc000000d;
  }
  if (0x5ea < uVar19) {
    return 0xc000000d;
  }
  if ((*(byte *)(lVar15 + 10) & 5) == 0) {
    in_stack_ffffffffffffffc8 = 0;
    psVar11 = (short *)MmMapLockedPagesSpecifyCache(lVar15,0,1,0);
  }
  else {
    psVar11 = *(short **)(lVar15 + 0x18);
  }
  if (psVar11 == (short *)0x0) {
    return 0xc000009a;
  }
  uVar9 = (ushort)psVar11[6] >> 8 | psVar11[6] << 8;
  if (uVar9 == 0x88d9) {
    if (((((uVar19 < 0x20) || (*(int *)(psVar11 + 4) != *(int *)(param_1 + 0x126))) ||
         (psVar11[3] != *(short *)(param_1 + 0x124))) ||
        (((char)psVar11[7] != '\x01' || (1 < *(byte *)((longlong)psVar11 + 0xf))))) ||
       ((0xc < *(byte *)((longlong)psVar11 + 0x11) ||
        ((*(int *)(psVar11 + 0xd) != *(int *)(param_1 + 0x126) ||
         (psVar11[0xc] != *(short *)(param_1 + 0x124))))))) {
      return 0xc000000d;
    }
    lVar15 = (ulonglong)*(byte *)((longlong)psVar11 + 0xf) * 0xd +
             (ulonglong)*(byte *)((longlong)psVar11 + 0x11);
    if (uVar19 < *(int *)(&DAT_14000d754 + lVar15 * 0x10) + 0x20U) {
      return 0xc000000d;
    }
    if (((byte)(&DAT_14000d758)[lVar15 * 0x10] < 0xfe) &&
       (uVar9 = *(ushort *)
                 ((ulonglong)(byte)(&DAT_14000d758)[lVar15 * 0x10] + 0x20 + (longlong)psVar11),
       uVar19 < *(int *)(&DAT_14000d754 + lVar15 * 0x10) + 0x20U +
                ((ushort)(uVar9 >> 8 | uVar9 << 8) & 0x3fff) *
                (uint)(byte)(&DAT_14000d759)[lVar15 * 0x10])) {
      return 0xc000000d;
    }
  }
  else {
    if (uVar9 != 0x806) {
      return 0xc000000d;
    }
    if (uVar19 < 0x2a) {
      return 0xc000000d;
    }
    if ((ushort)((ushort)psVar11[7] >> 8 | psVar11[7] << 8) != 1) {
      return 0xc000000d;
    }
    if ((ushort)((ushort)psVar11[8] >> 8 | psVar11[8] << 8) != 0x800) {
      return 0xc000000d;
    }
    if ((char)psVar11[9] != '\x06') {
      return 0xc000000d;
    }
    if (*(char *)((longlong)psVar11 + 0x13) != '\x04') {
      return 0xc000000d;
    }
    if ((ushort)((ushort)psVar11[10] >> 8 | psVar11[10] << 8) != 1) {
      return 0xc000000d;
    }
    uVar19 = 0x2a;
  }
  lVar15 = param_1 + 0x18;
  uVar8 = KeAcquireSpinLockRaiseToDpc(lVar15);
  if ((*(uint *)(param_1 + 0x34) >> 8 & 1) != 0) {
    uVar17 = 0xc000020c;
LAB_140006028:
    KeReleaseSpinLock(lVar15,uVar8);
    return uVar17;
  }
  if ((*(uint *)(param_1 + 0x34) & 1) != 0) {
    uVar17 = 0xc00002fe;
    goto LAB_140006028;
  }
  LOCK();
  *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + 1;
  UNLOCK();
  piVar2 = (int *)(param_1 + 0x140);
  LOCK();
  *piVar2 = *piVar2 + 1;
  UNLOCK();
  lVar12 = lVar15;
  KeReleaseSpinLockFromDpcLevel();
  lVar12 = TopAllocateAndReferenceNetBufferAndNetBufferList
                     (lVar12,*(undefined8 *)(param_1 + 0x80),param_2,*(undefined8 *)(param_2 + 8),
                      CONCAT44(in_stack_ffffffffffffffcc,in_stack_ffffffffffffffc8),uVar19);
  if (lVar12 == 0) {
    KeLowerIrql(uVar8);
    LOCK();
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    LOCK();
    piVar2 = (int *)(param_1 + 0x30);
    iVar10 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar10 == 1) {
      NdisFreeMemory(param_1,0,0);
      return 0xc000009a;
    }
    return 0xc000009a;
  }
  *(uint *)(lVar12 + 0x88) = *(uint *)(lVar12 + 0x88) | 0x10000000;
  LOCK();
  UNLOCK();
  iVar10 = topLocalNdisCancelId + 1;
  topLocalNdisCancelId = topLocalNdisCancelId + 1;
  *(ulonglong *)(lVar12 + 0xb8) = (longlong)iVar10 & 0xffffffffffffffU | _topPartialNdisCancelId;
  *(longlong *)(param_2 + 0x78) = param_1;
  *(undefined8 *)(param_2 + 0x80) = *(undefined8 *)(lVar12 + 0xb8);
  KeAcquireSpinLockAtDpcLevel(lVar15);
  puVar18 = auStackY_58;
  lVar14 = param_1 + 0x130;
  plVar16 = *(longlong **)(param_1 + 0x138);
  plVar13 = (longlong *)(param_2 + 0xa8);
  if (*plVar16 != lVar14) {
    lVar14 = 3;
    pcVar5 = (code *)swi(0x29);
    plVar13 = (longlong *)(*pcVar5)();
    puVar18 = auStackY_50;
  }
  *plVar13 = lVar14;
  plVar13[1] = (longlong)plVar16;
  *plVar16 = (longlong)plVar13;
  *(longlong **)(lVar14 + 8) = plVar13;
  LOCK();
  *piVar2 = *piVar2 + 1;
  UNLOCK();
  LOCK();
  *(code **)(param_2 + 0x68) = ToppCancelWriteCallback;
  UNLOCK();
  lVar14 = *(longlong *)(param_2 + 0xb8);
  bVar6 = false;
  pbVar1 = (byte *)(lVar14 + 3);
  *pbVar1 = *pbVar1 | 1;
  piVar3 = *(int **)(param_1 + 0x188);
  if (piVar3 == (int *)0x0) {
    *(undefined8 *)(puVar18 + -8) = 0x140005fed;
    KeReleaseSpinLock(lVar15,CONCAT71((int7)((ulonglong)lVar14 >> 8),uVar8));
  }
  else {
    LOCK();
    *piVar3 = *piVar3 + 1;
    UNLOCK();
    *(undefined8 *)(puVar18 + -8) = 0x140005f6c;
    KeReleaseSpinLock();
    if ((*(int *)(psVar11 + 1) == *(int *)(param_1 + 0x126)) &&
       (*psVar11 == *(short *)(param_1 + 0x124))) {
      bVar7 = true;
LAB_140005fa1:
      bVar6 = bVar7;
      uVar4 = *(undefined8 *)(piVar3 + 6);
      *(undefined8 *)(puVar18 + -8) = 0x140005fb1;
      ExNotifyCallback(uVar4,0);
    }
    else if ((*(int *)(psVar11 + 1) == -1) && (bVar7 = false, *psVar11 == -1)) goto LAB_140005fa1;
    LOCK();
    iVar10 = *piVar3;
    *piVar3 = *piVar3 + -1;
    UNLOCK();
    if (iVar10 == 1) {
      *(undefined8 *)(puVar18 + -8) = 0x140005fca;
      TopCleanupBackChannel((longlong)piVar3);
    }
    if (bVar6) {
      *(undefined8 *)(puVar18 + -8) = 0x140005fe4;
      TopSendCompletionHandler(param_1,lVar12,'\0');
      goto LAB_140006015;
    }
  }
  uVar4 = *(undefined8 *)(param_1 + 0x80);
  *(undefined8 *)(lVar12 + 0x78) = uVar4;
  *(undefined8 *)(puVar18 + -8) = 0x140006010;
  NdisSendNetBufferLists(uVar4,lVar12,0,0);
LAB_140006015:
  LOCK();
  *piVar2 = *piVar2 + -1;
  UNLOCK();
  return 0x103;
}



===== WPP_SF_SD @ 140006048 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_SD(undefined8 param_1,undefined8 param_2,undefined8 param_3,wchar_t *param_4,
              undefined1 param_5)

{
  longlong lVar1;
  
  if (param_4 == (wchar_t *)0x0) {
    lVar1 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_4[lVar1] != L'\0');
    lVar1 = lVar1 * 2 + 2;
  }
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"NULL";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_b515efb401d631d3025e3a3f22783527_Traceguids,0xd,param_4,lVar1,
             &param_5,4,0);
  return;
}



===== WPP_SF__MAC_llDlD @ 1400060d8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF__MAC_llDlD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                      undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
                      undefined1 param_9)

{
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_b515efb401d631d3025e3a3f22783527_Traceguids,0x16,param_4,6,&param_5,4
             ,&param_6,4,&param_7,4,&param_8,4,&param_9,4,0);
  return;
}



===== wil_details_FeatureReporting_IncrementOpportunityInCache @ 140006164 =====

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



===== wil_details_FeatureReporting_IncrementUsageInCache @ 14000623c =====

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



===== wil_details_FeatureReporting_RecordUsageInCache @ 140006320 =====

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
LAB_140006478:
    wil_details_FeatureReporting_IncrementUsageInCache(param_2,uVar5,param_3,param_1);
  }
  else {
    if (uVar5 == 1) {
LAB_14000646b:
      wil_details_FeatureReporting_IncrementOpportunityInCache(param_2,uVar5,param_3,param_1);
      return param_1;
    }
    if ((uVar5 != 2) && (uVar5 != 3)) {
      if (uVar5 == 4) goto LAB_140006478;
      if (uVar5 == 5) goto LAB_14000646b;
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



===== wil_details_FeatureReporting_ReportUsageToService @ 1400064a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void wil_details_FeatureReporting_ReportUsageToService
               (undefined8 param_1,undefined8 param_2,uint param_3)

{
  bool bVar1;
  uint uVar2;
  undefined7 extraout_var;
  ulonglong uVar3;
  uint uVar4;
  uint local_res18 [4];
  
  uVar4 = (uint)param_2 & 1;
  uVar3 = (ulonglong)param_3;
  local_res18[0] = param_3;
  uVar2 = wil_details_MapReportingKind(param_3,uVar4);
  bVar1 = wil_details_FeatureReporting_ReportUsageToServiceDirect(uVar3,param_2,(ulonglong)uVar2);
  if (((int)CONCAT71(extraout_var,bVar1) != 0) &&
     (g_wil_details_pfnFeatureLoggingHook != (code *)0x0)) {
    (*g_wil_details_pfnFeatureLoggingHook)
              (0x3c05498,&Feature_405434683_logged_traits,0,uVar4,local_res18,0,0,1);
  }
  return;
}



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 14000651c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool wil_details_FeatureReporting_ReportUsageToServiceDirect
               (undefined8 param_1,undefined8 param_2,ulonglong param_3)

{
  uint6 uVar1;
  uint *puVar2;
  undefined1 auStack_88 [32];
  uint *local_68;
  undefined8 local_58;
  uint local_50 [6];
  uint local_38;
  uint uStack_34;
  uint uStack_30;
  uint uStack_2c;
  undefined8 local_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_88;
  puVar2 = wil_details_FeatureReporting_RecordUsageInCache
                     (local_50,(uint *)&Feature_405434683__private_reporting,param_3,
                      (uint)((ulonglong)param_2 >> 0x20));
  local_38 = *puVar2;
  uStack_34 = puVar2[1];
  uStack_30 = puVar2[2];
  uStack_2c = puVar2[3];
  local_28 = *(undefined8 *)(puVar2 + 4);
  if (g_wil_details_recordFeatureUsage != (code *)0x0) {
    local_68 = &local_38;
    (*g_wil_details_recordFeatureUsage)
              (0x3c05498,param_3 & 0xffffffff,1,&Feature_405434683__private_reporting);
  }
  if ((((uint)param_2 >> 10 & 1) != 0) && ((int)param_3 != 0xfe)) {
    local_58._0_6_ = CONCAT24((short)(param_3 & 0xffffffff),0x3c05498);
    uVar1 = (uint6)local_58;
    local_58 = (ulonglong)(uint6)local_58;
    if (((uint)param_2 >> 0xb & 1) != 0) {
      local_58 = CONCAT26(1,uVar1);
    }
    RtlNotifyFeatureUsage(&local_58);
  }
  return (int)local_28 == 0;
}



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 140006608 =====

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



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 140006718 =====

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
  if ((Feature_405434683__private_featureState & 2) != 0) {
    uVar1 = Feature_405434683__private_featureState;
    while ((uVar1 & 1) == (param_1 & 1)) {
      LOCK();
      bVar3 = uVar1 == Feature_405434683__private_featureState;
      if (bVar3) {
        Feature_405434683__private_featureState = uVar2 | uVar1;
      }
      else {
        uVar1 = Feature_405434683__private_featureState;
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



===== wil_details_GetCurrentFeatureEnabledState @ 14000676c =====

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



===== wil_details_IsEnabledFallback @ 1400068cc =====

uint wil_details_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  undefined4 *puVar1;
  ulonglong local_res18;
  
  local_res18 = (ulonglong)param_1 & 0xffffffff;
  if (((ulonglong)param_1 & 2) == 0) {
    puVar1 = &Feature_405434683__private_featureState;
    local_res18 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                            (&Feature_405434683__private_featureState,(ulonglong)param_1,0x14000eb28
                            );
    param_1 = puVar1;
    puVar1 = (undefined4 *)(local_res18 & 0xffffffff);
  }
  else {
    puVar1 = param_1;
  }
  if (param_2 != 0) {
    wil_details_FeatureReporting_ReportUsageToService(param_1,local_res18,param_2);
    if (param_2 - 3 < 2) {
      wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath((uint)local_res18,param_2);
    }
  }
  return (uint)puVar1 & 1;
}



===== wil_details_MapReportingKind @ 14000695c =====

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



===== QosBindDevice @ 140006a00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int QosBindDevice(longlong param_1,undefined4 *param_2,ushort *param_3,uint param_4,uint *param_5,
                 undefined8 *param_6)

{
  int *piVar1;
  int *piVar2;
  longlong lVar3;
  int iVar4;
  byte bVar5;
  longlong lVar6;
  char cVar7;
  undefined1 uVar8;
  undefined8 uVar9;
  uint *puVar10;
  uint *puVar11;
  ulonglong uVar12;
  longlong lVar13;
  undefined4 *puVar14;
  int **ppiVar15;
  int *piVar16;
  int local_res10 [2];
  undefined8 in_stack_ffffffffffffff78;
  uint uVar17;
  undefined4 local_58;
  undefined4 local_54 [3];
  longlong local_48;
  int *local_40;
  int *local_38 [2];
  
  uVar17 = (uint)((ulonglong)in_stack_ffffffffffffff78 >> 0x20);
  lVar13 = *(longlong *)(param_2 + 0x2e);
  local_res10[0] = 0;
  local_48 = 0;
  local_38[0] = (int *)0x0;
  if (topEnableNetTestAccessCheck != '\0') {
    local_54[0] = 0;
    local_58 = 0xc0000000;
    uVar9 = IoGetFileObjectGenericMapping();
    RtlMapGenericMask(&local_58,uVar9);
    uVar8 = 1;
    if ((*(byte *)(lVar13 + 2) & 1) == 0) {
      uVar8 = *(undefined1 *)(param_2 + 0x10);
    }
    cVar7 = SeAccessCheck(&toppNetworkTestServiceDescriptor,
                          *(longlong *)(*(longlong *)(lVar13 + 8) + 8) + 0x20,0,local_58,
                          (ulonglong)uVar17 << 0x20,0,uVar9,uVar8,local_54,local_res10);
    if (cVar7 == '\0') {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return local_res10[0];
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
        return local_res10[0];
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0) {
        return local_res10[0];
      }
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
               &WPP_1564c523e1063e4f7fac143b272659d2_Traceguids,local_res10[0]);
      return local_res10[0];
    }
  }
  local_res10[0] = TopBindDevice(param_1,0,param_3,param_4,param_5,&local_48);
  if (local_res10[0] < 0) {
    return local_res10[0];
  }
  puVar10 = TopFindEA(param_5,"SinkAddress",0xb);
  puVar11 = TopFindEA(param_5,"IntMod",6);
  lVar13 = local_48;
  if ((((puVar10 == (uint *)0x0) || (*(short *)((longlong)puVar10 + 6) != 6)) ||
      (puVar11 == (uint *)0x0)) ||
     ((*(short *)((longlong)puVar11 + 6) != 1 ||
      (cVar7 = *(char *)((ulonglong)*(byte *)((longlong)puVar11 + 5) + 9 + (longlong)puVar11),
      (byte)(cVar7 - 2U) < 0xfd)))) {
    local_res10[0] = -0x3ffffff3;
  }
  else {
    bVar5 = *(byte *)((longlong)puVar10 + 5);
    uVar12 = TopReferencePacketFilter(local_48,0);
    local_res10[0] = (int)uVar12;
    if (local_res10[0] < 0) goto LAB_140006dee;
    lVar3 = lVar13 + 400;
    uVar8 = KeAcquireSpinLockRaiseToDpc(lVar3);
    ppiVar15 = local_38;
    local_40 = (int *)QosLookupSession(lVar3,(void *)((longlong)puVar10 + (ulonglong)bVar5 + 9),
                                       ppiVar15);
    if (local_40 != (int *)0x0) {
      KeReleaseSpinLock(lVar3);
      TopDereferencePacketFilterSafe(lVar13,0,(undefined *)ppiVar15);
      local_res10[0] = -0x7fffffef;
      goto LAB_140006dee;
    }
    puVar14 = (undefined4 *)((longlong)puVar10 + (ulonglong)bVar5 + 9);
    piVar16 = local_38[0];
    uVar9 = QosCreateSession(lVar13,puVar14,(longlong)local_38[0],&local_40);
    piVar2 = local_40;
    local_res10[0] = (int)uVar9;
    if (local_res10[0] < 0) {
      KeReleaseSpinLock();
      TopDereferencePacketFilterSafe(lVar13,0,(undefined *)piVar16);
      goto LAB_140006dee;
    }
    LOCK();
    local_40[8] = local_40[8] + 1;
    UNLOCK();
    KeReleaseSpinLockFromDpcLevel(lVar3);
    lVar6 = local_48;
    lVar13 = local_48 + 0x18;
    KeAcquireSpinLockAtDpcLevel(lVar13);
    if ((*(uint *)(lVar6 + 0x34) & 1) == 0) {
      LOCK();
      *(int *)(lVar6 + 0x140) = *(int *)(lVar6 + 0x140) + 1;
      UNLOCK();
      KeReleaseSpinLockFromDpcLevel(lVar13);
      piVar16 = local_40 + 0xf;
      lVar13 = QospCreateQosInitializeSinkFrameAtDpcLevel(local_48,puVar14,piVar16,cVar7);
      if (local_res10[0] < 0) {
        LOCK();
        *(int *)(lVar6 + 0x140) = *(int *)(lVar6 + 0x140) + -1;
        UNLOCK();
        param_2 = puVar14;
      }
      else {
        piVar16 = (int *)0x0;
        uVar9 = QosautopInitializeIrpAndSendAtDpcLevel
                          ((longlong)local_40,(longlong)param_2,0,QosautopCreateIrpCompletionHandler
                           ,QosautopCreateReceiveHandler,1,lVar13,lVar13);
        local_res10[0] = (int)uVar9;
        LOCK();
        *(int *)(lVar6 + 0x140) = *(int *)(lVar6 + 0x140) + -1;
        UNLOCK();
        if (local_res10[0] < 0) {
          LOCK();
          piVar1 = (int *)(lVar13 + 0x40);
          iVar4 = *piVar1;
          *piVar1 = *piVar1 + -1;
          UNLOCK();
          if (iVar4 == 1) {
            piVar16 = *(int **)(lVar13 + 0x58);
            param_2 = *(undefined4 **)(lVar13 + 0x50);
            (**(code **)(lVar13 + 0x48))(lVar13,param_2,piVar16,1);
          }
        }
        else {
          local_res10[0] = 0x103;
          *param_6 = local_40;
        }
      }
      if (local_res10[0] != 0x103) goto LAB_140006d94;
    }
    else {
      KeReleaseSpinLockFromDpcLevel(lVar13);
      local_res10[0] = -0x3ffffd02;
      param_2 = puVar14;
LAB_140006d94:
      KeAcquireSpinLockAtDpcLevel(lVar3);
      QosDeleteSession(local_40);
      KeReleaseSpinLockFromDpcLevel(lVar3);
    }
    KeLowerIrql(uVar8);
    LOCK();
    piVar2 = piVar2 + 8;
    iVar4 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar4 == 1) {
      QosCleanupSession((longlong)local_40,param_2,piVar16);
    }
  }
  lVar13 = local_48;
LAB_140006dee:
  LOCK();
  piVar2 = (int *)(lVar13 + 0x30);
  iVar4 = *piVar2;
  *piVar2 = *piVar2 + -1;
  UNLOCK();
  if (iVar4 == 1) {
    NdisFreeMemory(local_48,0,0);
  }
  return local_res10[0];
}



===== QosCleanupSession @ 140006e3c =====

void QosCleanupSession(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  
  lVar3 = *(longlong *)(param_1 + 0x10);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0))
  {
    WPP_SF__MAC_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,param_3,param_1 + 0x3c);
  }
  ExFreePoolWithTag(param_1,0);
  LOCK();
  piVar1 = (int *)(lVar3 + 0x30);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    NdisFreeMemory(lVar3,0,0);
  }
  return;
}



===== QosCreateSession @ 140006ec4 =====

undefined8
QosCreateSession(longlong param_1,undefined4 *param_2,longlong param_3,undefined8 *param_4)

{
  undefined4 *puVar1;
  undefined8 uVar2;
  code *pcVar3;
  undefined8 uVar4;
  undefined4 *_Dst;
  longlong *plVar5;
  longlong *plVar6;
  undefined1 *puVar7;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  
  if (*(uint *)(param_1 + 0x1b8) < 0x20) {
    _Dst = (undefined4 *)ExAllocatePool2(0x40,0x60,0x53516f49);
    if (_Dst == (undefined4 *)0x0) {
      uVar4 = 0xc000009a;
    }
    else {
      uVar4 = 0x60;
      memset(_Dst,0,0x60);
      KeInitializeSpinLock(_Dst + 6);
      puVar7 = auStack_38;
      puVar1 = _Dst + 0x14;
      *(undefined4 **)(_Dst + 0x16) = puVar1;
      *(undefined4 **)puVar1 = puVar1;
      *(undefined ***)(_Dst + 2) = &PTR_QospCloseHandler_14000d1c0;
      *_Dst = 1;
      *(longlong *)(_Dst + 4) = param_1;
      _Dst[8] = 2;
      *(undefined2 *)((longlong)_Dst + 0x42) = 0;
      _Dst[0xf] = *param_2;
      *(undefined2 *)(_Dst + 0x10) = *(undefined2 *)(param_2 + 1);
      LOCK();
      *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + 1;
      UNLOCK();
      plVar6 = *(longlong **)(param_3 + 8);
      plVar5 = (longlong *)(_Dst + 10);
      if (*plVar6 != param_3) {
        plVar6 = (longlong *)0x3;
        pcVar3 = (code *)swi(0x29);
        plVar5 = (longlong *)(*pcVar3)();
        puVar7 = auStack_30;
      }
      *plVar5 = param_3;
      plVar5[1] = (longlong)plVar6;
      *plVar6 = (longlong)plVar5;
      *(longlong **)(param_3 + 8) = plVar5;
      LOCK();
      *(int *)(param_1 + 0x1b8) = *(int *)(param_1 + 0x1b8) + 1;
      UNLOCK();
      *param_4 = _Dst;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
        uVar2 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
        *(undefined8 *)(puVar7 + -8) = 0x140006fe5;
        WPP_SF__MAC_(uVar2,0xd,uVar4,param_2);
      }
      uVar4 = 0;
    }
  }
  else {
    uVar4 = 0x80000011;
  }
  return uVar4;
}



===== QosDeleteSession @ 140007008 =====

ulonglong QosDeleteSession(int *param_1)

{
  longlong *plVar1;
  int *piVar2;
  int iVar3;
  longlong lVar4;
  longlong *plVar5;
  code *pcVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  longlong lVar10;
  
  lVar10 = *(longlong *)(param_1 + 4);
  if ((param_1[0xe] & 1U) == 0) {
    if (*param_1 == 2) {
      LOCK();
      *(int *)(lVar10 + 0x1bc) = *(int *)(lVar10 + 0x1bc) + -1;
      UNLOCK();
      *(uint *)(lVar10 + 0x1c0) =
           *(uint *)(lVar10 + 0x1c0) & ~(1 << (*(ushort *)((longlong)param_1 + 0x42) >> 0xb));
    }
    else {
      LOCK();
      *(int *)(lVar10 + 0x1b8) = *(int *)(lVar10 + 0x1b8) + -1;
      UNLOCK();
    }
    plVar1 = (longlong *)(param_1 + 10);
    lVar4 = *plVar1;
    if ((*(longlong **)(lVar4 + 8) != plVar1) ||
       (plVar5 = *(longlong **)(param_1 + 0xc), (longlong *)*plVar5 != plVar1)) {
      pcVar6 = (code *)swi(0x29);
      (*pcVar6)(3);
      pcVar6 = (code *)swi(3);
      uVar8 = (*pcVar6)();
      return uVar8;
    }
    *plVar5 = lVar4;
    *(longlong **)(lVar4 + 8) = plVar5;
    uVar9 = 0;
    *(longlong **)(param_1 + 0xc) = plVar1;
    *plVar1 = (longlong)plVar1;
    param_1[0xe] = param_1[0xe] | 1;
    uVar8 = TopDereferencePacketFilterSafe(lVar10,0,(undefined *)lVar10);
    LOCK();
    piVar2 = param_1 + 8;
    iVar3 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar3 == 1) {
      uVar8 = QosCleanupSession((longlong)param_1,uVar9,lVar10);
    }
    uVar7 = CONCAT71((int7)((ulonglong)uVar8 >> 8),1);
  }
  else {
    uVar7 = (ulonglong)(param_1[0xe] & 0xffffff00);
  }
  return uVar7;
}



===== QosLookupSession @ 1400070b0 =====

undefined8 * QosLookupSession(longlong param_1,void *param_2,undefined8 *param_3)

{
  int iVar1;
  undefined8 *puVar2;
  
  puVar2 = *(undefined8 **)(param_1 + 8);
  do {
    if (puVar2 == (undefined8 *)(param_1 + 8)) {
LAB_1400070fe:
      if (param_3 != (undefined8 *)0x0) {
        *param_3 = puVar2;
      }
      return (undefined8 *)0x0;
    }
    iVar1 = memcmp(param_2,(void *)((longlong)puVar2 + 0x14),6);
    if (-1 < iVar1) {
      if (iVar1 < 1) {
        return puVar2 + -5;
      }
      goto LAB_1400070fe;
    }
    puVar2 = (undefined8 *)*puVar2;
  } while( true );
}



===== QosReceiveHandler @ 140007130 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void QosReceiveHandler(longlong param_1,longlong param_2,short *param_3,undefined8 *param_4,
                      char param_5)

{
  int *piVar1;
  int iVar2;
  byte bVar3;
  undefined1 uVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  longlong lVar10;
  undefined8 *puVar11;
  ushort uVar12;
  
  puVar8 = *(undefined8 **)(param_2 + 8);
  uVar4 = 0;
  if (((((*(int *)(param_3 + 1) == *(int *)(param_1 + 0x126)) &&
        (*param_3 == *(short *)(param_1 + 0x124))) &&
       (*(int *)((longlong)param_4 + 6) == *(int *)(param_1 + 0x126))) &&
      ((*(short *)((longlong)param_4 + 4) == *(short *)(param_1 + 0x124) &&
       (*(int *)(param_3 + 4) == *(int *)((longlong)param_4 + 0xc))))) &&
     (param_3[3] == *(short *)((longlong)param_4 + 10))) {
    bVar3 = *(byte *)((longlong)param_4 + 3);
    if (((bVar3 < 0xb) &&
        (*(uint *)(&topQosProtocolRules + (ulonglong)bVar3 * 4) <= *(uint *)(puVar8 + 3))) &&
       (*(short *)(param_4 + 2) != 0)) {
      if (7 < bVar3) {
        QosdiagpReceiveHandler(param_1,param_2,&topQosProtocolRules,param_4,param_5);
      }
      uVar5 = KeQueryPerformanceCounter(0);
      lVar10 = param_1 + 400;
      uVar12 = *(ushort *)(param_4 + 2) >> 8 | *(ushort *)(param_4 + 2) << 8;
      if (param_5 == '\0') {
        uVar4 = KeAcquireSpinLockRaiseToDpc(lVar10);
      }
      else {
        KeAcquireSpinLockAtDpcLevel();
      }
      puVar11 = (undefined8 *)0x0;
      puVar6 = QosLookupSession(lVar10,(void *)((longlong)param_4 + 10),(undefined8 *)0x0);
      if ((puVar6 == (undefined8 *)0x0) || ((*(uint *)(puVar6 + 7) & 1) != 0)) {
        if (param_5 == '\0') {
          KeReleaseSpinLock(lVar10,uVar4);
        }
        else {
          KeReleaseSpinLockFromDpcLevel();
        }
      }
      else {
        LOCK();
        *(int *)(puVar6 + 4) = *(int *)(puVar6 + 4) + 1;
        UNLOCK();
        KeReleaseSpinLockFromDpcLevel(lVar10);
        KeAcquireSpinLockAtDpcLevel(puVar6 + 3);
        puVar9 = puVar6 + 10;
        for (puVar7 = (undefined8 *)*puVar9; puVar7 != puVar9; puVar7 = (undefined8 *)*puVar7) {
          lVar10 = puVar7[-6];
          if (uVar12 <= *(ushort *)(lVar10 + 0x20)) {
            if (uVar12 == *(ushort *)(lVar10 + 0x20)) {
              (**(code **)(lVar10 + 0x30))(lVar10,puVar8,param_4,uVar5);
              puVar9 = puVar8;
              puVar11 = param_4;
              goto LAB_1400072cc;
            }
            break;
          }
        }
        KeReleaseSpinLockFromDpcLevel(puVar6 + 3);
LAB_1400072cc:
        if (param_5 == '\0') {
          KeLowerIrql(uVar4);
        }
        LOCK();
        piVar1 = (int *)(puVar6 + 4);
        iVar2 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar2 == 1) {
          QosCleanupSession((longlong)puVar6,puVar9,puVar11);
        }
      }
    }
  }
  return;
}



===== QosautoSendCompletionHandler @ 140007340 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void QosautoSendCompletionHandler(undefined8 param_1,longlong param_2,longlong param_3)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  longlong lVar4;
  undefined1 uVar5;
  char cVar6;
  
  uVar3 = *(uint *)(param_2 + 0x8c);
  uVar5 = 0;
  lVar4 = *(longlong *)(param_2 + 0x58);
  cVar6 = (char)param_3;
  LOCK();
  piVar1 = (int *)(lVar4 + 0x48);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (((*(uint *)(lVar4 + 0xc) & 0x10000) == 0) && (uVar3 != 0)) {
    if (cVar6 == '\0') {
      uVar5 = KfRaiseIrql(CONCAT71((uint7)(uint3)((uint)(iVar2 + -1) >> 8),2));
    }
    QosautopCompleteIrpAtDpcLevel(lVar4,(ulonglong)uVar3);
    if (cVar6 == '\0') {
      KeLowerIrql(uVar5);
    }
  }
  else if (iVar2 + -1 == 0) {
    if (cVar6 == '\0') {
      uVar5 = KeAcquireSpinLockRaiseToDpc(lVar4);
    }
    else {
      KeAcquireSpinLockAtDpcLevel();
    }
    if ((*(uint *)(lVar4 + 0xc) & 0x20000) == 0) {
      *(int *)(lVar4 + 0xd0) = *(int *)(lVar4 + 0xd0) + 1;
      param_3 = lVar4 + 0x90;
      KeSetTimer(lVar4 + 0x50,0xfffffffffff85ee0);
      LOCK();
      *(int *)(lVar4 + 8) = *(int *)(lVar4 + 8) + 1;
      UNLOCK();
    }
    if (cVar6 == '\0') {
      KeReleaseSpinLock(lVar4,uVar5);
    }
    else {
      KeReleaseSpinLockFromDpcLevel();
    }
  }
  LOCK();
  piVar1 = (int *)(lVar4 + 8);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    QosautopCleanupIrpContext(lVar4,cVar6,param_3);
  }
  LOCK();
  piVar1 = (int *)(param_2 + 0x40);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    (**(code **)(param_2 + 0x48))
              (param_2,*(undefined8 *)(param_2 + 0x50),*(undefined8 *)(param_2 + 0x58),cVar6);
  }
  return;
}



===== QosautopCancelIrpCallback @ 140007490 =====

void QosautopCancelIrpCallback(undefined8 param_1,longlong param_2,undefined8 param_3)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  longlong lVar4;
  
  cVar3 = *(char *)(param_2 + 0x45);
  lVar4 = *(longlong *)(param_2 + 0x78);
  LOCK();
  *(undefined8 *)(param_2 + 0x68) = 0;
  UNLOCK();
  IoReleaseCancelSpinLock(2);
  QosautopCompleteIrpAtDpcLevel(lVar4,0xc0000120);
  LOCK();
  piVar1 = (int *)(lVar4 + 8);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    QosautopCleanupIrpContext(lVar4,'\x01',param_3);
  }
  if (cVar3 != '\x02') {
    KeLowerIrql(cVar3);
  }
  return;
}



===== QosautopCleanupIrpCompletionHandler @ 140007500 =====

void QosautopCleanupIrpCompletionHandler(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 **ppuVar1;
  int iVar2;
  undefined8 **ppuVar3;
  undefined8 *puVar4;
  undefined1 uVar5;
  
  ppuVar3 = *(undefined8 ***)(param_1 + 0x10);
  puVar4 = ppuVar3[2];
  uVar5 = KeAcquireSpinLockRaiseToDpc(ppuVar3 + 3);
  KeAcquireSpinLockAtDpcLevel(puVar4 + 0x32);
  LOCK();
  *(int *)(ppuVar3 + 4) = *(int *)(ppuVar3 + 4) + 1;
  UNLOCK();
  QosDeleteSession((int *)ppuVar3);
  KeReleaseSpinLockFromDpcLevel(puVar4 + 0x32);
  KeReleaseSpinLockFromDpcLevel(ppuVar3 + 3);
  QospShutdownSessionAtDpcLevel(ppuVar3);
  KeLowerIrql(uVar5);
  LOCK();
  ppuVar1 = ppuVar3 + 4;
  iVar2 = *(int *)ppuVar1;
  *(int *)ppuVar1 = *(int *)ppuVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    QosCleanupSession((longlong)ppuVar3,param_2,param_3);
  }
  return;
}



===== QosautopCleanupIrpContext @ 1400075bc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void QosautopCleanupIrpContext(longlong param_1,char param_2,undefined8 param_3)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  undefined1 uVar5;
  
  lVar3 = *(longlong *)(param_1 + 0x10);
  lVar4 = *(longlong *)(param_1 + 0x40);
  uVar5 = 0;
  if (lVar4 != 0) {
    LOCK();
    piVar1 = (int *)(lVar4 + 0x40);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      param_3 = *(undefined8 *)(lVar4 + 0x58);
      (**(code **)(lVar4 + 0x48))(lVar4,*(undefined8 *)(lVar4 + 0x50),param_3,1);
    }
  }
  if (param_2 == '\0') {
    uVar5 = KeAcquireSpinLockRaiseToDpc(&qospIrpContextLookasideListLock);
  }
  else {
    KeAcquireSpinLockAtDpcLevel();
  }
  ExFreeToNPagedLookasideList(&qospIrpContextLookasideList);
  if (param_2 == '\0') {
    param_1 = CONCAT71((int7)((ulonglong)param_1 >> 8),uVar5);
    KeReleaseSpinLock(&qospIrpContextLookasideListLock);
  }
  else {
    KeReleaseSpinLockFromDpcLevel();
  }
  LOCK();
  piVar1 = (int *)(lVar3 + 0x20);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    QosCleanupSession(lVar3,param_1,param_3);
  }
  return;
}



===== QosautopCleanupReceiveHandler @ 1400076a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void QosautopCleanupReceiveHandler(longlong param_1,undefined8 param_2,longlong param_3)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  
  if (*(char *)(param_3 + 3) == '\a') {
    lVar3 = QosautopDetachIrpUnderLockAndReleaseFromDpcLevel(param_1,param_2,param_3);
    if (lVar3 != 0) {
      if (*(code **)(param_1 + 0x28) != (code *)0x0) {
        param_3 = 0;
        (**(code **)(param_1 + 0x28))(param_1,lVar3,0,0);
      }
      *(undefined4 *)(lVar3 + 0x30) = 0;
      *(undefined8 *)(lVar3 + 0x38) = 0;
      IofCompleteRequest(lVar3,2);
      LOCK();
      piVar1 = (int *)(param_1 + 8);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar2 == 1) {
        QosautopCleanupIrpContext(param_1,'\x01',param_3);
      }
    }
  }
  else {
    KeReleaseSpinLockFromDpcLevel(*(longlong *)(param_1 + 0x10) + 0x18);
  }
  return;
}



===== QosautopCompleteIrpAtDpcLevel @ 140007734 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void QosautopCompleteIrpAtDpcLevel(longlong param_1,undefined8 param_2)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  undefined8 *puVar4;
  code *pcVar5;
  uint uVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  uint uVar9;
  
  lVar3 = *(longlong *)(param_1 + 0x10);
  uVar9 = (uint)param_2;
  KeAcquireSpinLockAtDpcLevel(lVar3 + 0x18);
  puVar4 = *(undefined8 **)(param_1 + 0x18);
  if (puVar4 != (undefined8 *)0x0) {
    puVar8 = (undefined8 *)(lVar3 + 0x50);
    for (puVar7 = (undefined8 *)*puVar8; puVar7 != puVar8; puVar7 = (undefined8 *)*puVar7) {
      if (puVar4 == puVar7 + -0x15) {
        QosautopDetachIrpUnderLockAndReleaseFromDpcLevel(param_1,param_2,puVar8);
        pcVar5 = *(code **)(param_1 + 0x28);
        uVar6 = uVar9;
        if (pcVar5 != (code *)0x0) {
          uVar6 = 0;
          if (pcVar5 != QosautopCleanupIrpCompletionHandler) {
            uVar6 = uVar9;
          }
          puVar8 = (undefined8 *)(ulonglong)uVar6;
          (*pcVar5)(param_1,puVar4,puVar8,0);
        }
        puVar4[7] = 0;
        *(uint *)(puVar4 + 6) = uVar6;
        IofCompleteRequest(puVar4,2);
        LOCK();
        piVar1 = (int *)(param_1 + 8);
        iVar2 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar2 == 1) {
          QosautopCleanupIrpContext(param_1,'\x01',puVar8);
          return;
        }
        return;
      }
    }
  }
  KeReleaseSpinLockFromDpcLevel(lVar3 + 0x18);
  return;
}



===== QosautopCreateIrpCompletionHandler @ 140007830 =====

void QosautopCreateIrpCompletionHandler(longlong param_1,longlong param_2,undefined8 param_3)

{
  undefined8 **ppuVar1;
  int *piVar2;
  int iVar3;
  undefined8 **ppuVar4;
  undefined8 *puVar5;
  longlong lVar6;
  undefined1 uVar7;
  
  if ((int)param_3 < 0) {
    ppuVar4 = *(undefined8 ***)(param_1 + 0x10);
    puVar5 = ppuVar4[2];
    uVar7 = KeAcquireSpinLockRaiseToDpc(ppuVar4 + 3);
    KeAcquireSpinLockAtDpcLevel(puVar5 + 0x32);
    LOCK();
    *(int *)(ppuVar4 + 4) = *(int *)(ppuVar4 + 4) + 1;
    UNLOCK();
    QosDeleteSession((int *)ppuVar4);
    KeReleaseSpinLockFromDpcLevel(puVar5 + 0x32);
    KeReleaseSpinLockFromDpcLevel(ppuVar4 + 3);
    QospShutdownSessionAtDpcLevel(ppuVar4);
    KeLowerIrql(uVar7);
    LOCK();
    ppuVar1 = ppuVar4 + 4;
    iVar3 = *(int *)ppuVar1;
    *(int *)ppuVar1 = *(int *)ppuVar1 + -1;
    UNLOCK();
    if (iVar3 == 1) {
      QosCleanupSession((longlong)ppuVar4,param_2,param_3);
    }
    lVar6 = *(longlong *)(param_1 + 0x10);
    LOCK();
    piVar2 = (int *)(lVar6 + 0x20);
    iVar3 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar3 == 1) {
      QosCleanupSession(lVar6,param_2,param_3);
    }
  }
  else {
    *(undefined8 *)(*(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30) + 0x18) =
         *(undefined8 *)(param_1 + 0x10);
  }
  return;
}



===== QosautopCreateReceiveHandler @ 140007930 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void QosautopCreateReceiveHandler(longlong param_1,longlong param_2,longlong param_3)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  ulonglong uVar4;
  code *pcVar5;
  ushort uVar6;
  uint *puVar7;
  ushort *puVar8;
  longlong lVar9;
  undefined8 uVar10;
  uint uVar11;
  undefined8 *puVar12;
  undefined1 auStack_58 [32];
  undefined4 local_38;
  undefined8 local_28;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  local_28 = 0;
  local_20 = 0;
  lVar9 = *(longlong *)(param_1 + 0x10);
  if (*(char *)(param_3 + 3) == '\x01') {
    uVar10 = 0xc;
    if (0xb < *(uint *)(param_2 + 0x18)) {
      local_38 = 0;
      puVar12 = &local_28;
      puVar7 = (uint *)NdisGetDataBuffer(param_2,0xc,puVar12,1);
      if (puVar7 != (uint *)0x0) {
        uVar4 = *(ulonglong *)(puVar7 + 1);
        uVar11 = 0;
        *(ulonglong *)(lVar9 + 0x48) =
             uVar4 >> 0x38 | (uVar4 & 0xff000000000000) >> 0x28 | (uVar4 & 0xff0000000000) >> 0x18 |
             (uVar4 & 0xff00000000) >> 8 | (uVar4 & 0xff000000) << 8 | (uVar4 & 0xff0000) << 0x18 |
             (uVar4 & 0xff00) << 0x28 | uVar4 << 0x38;
        uVar3 = *puVar7;
        *(uint *)(lVar9 + 0x44) =
             uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
LAB_140007a15:
        lVar9 = QosautopDetachIrpUnderLockAndReleaseFromDpcLevel(param_1,uVar10,puVar12);
        if (lVar9 == 0) {
          return;
        }
        pcVar5 = *(code **)(param_1 + 0x28);
        if (pcVar5 != (code *)0x0) {
          uVar3 = 0;
          if (pcVar5 != QosautopCleanupIrpCompletionHandler) {
            uVar3 = uVar11;
          }
          uVar11 = uVar3;
          puVar12 = (undefined8 *)(ulonglong)uVar11;
          (*pcVar5)(param_1,lVar9,puVar12,0);
        }
        *(undefined8 *)(lVar9 + 0x38) = 0;
        *(uint *)(lVar9 + 0x30) = uVar11;
        IofCompleteRequest(lVar9,2);
        LOCK();
        piVar1 = (int *)(param_1 + 8);
        iVar2 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar2 == 1) {
          QosautopCleanupIrpContext(param_1,'\x01',puVar12);
          return;
        }
        return;
      }
    }
  }
  else if ((*(char *)(param_3 + 3) == '\x06') && (1 < *(uint *)(param_2 + 0x18))) {
    local_38 = 0;
    puVar12 = &local_28;
    uVar10 = 2;
    puVar8 = (ushort *)NdisGetDataBuffer(param_2);
    if (puVar8 != (ushort *)0x0) {
      uVar6 = *puVar8 >> 8 | *puVar8 << 8;
      if (uVar6 < 3) {
        uVar11 = *(uint *)(&DAT_14000d938 + (ulonglong)uVar6 * 4);
      }
      else {
        uVar11 = 0xc0000001;
      }
      goto LAB_140007a15;
    }
  }
  KeReleaseSpinLockFromDpcLevel(lVar9 + 0x18);
  return;
}



===== QosautopDetachIrpUnderLockAndReleaseFromDpcLevel @ 140007ab8 =====

longlong QosautopDetachIrpUnderLockAndReleaseFromDpcLevel
                   (longlong param_1,undefined8 param_2,undefined8 param_3)

{
  int *piVar1;
  longlong *plVar2;
  int iVar3;
  longlong lVar4;
  longlong *plVar5;
  code *pcVar6;
  char cVar7;
  longlong lVar8;
  
  lVar8 = *(longlong *)(param_1 + 0x18);
  *(undefined8 *)(param_1 + 0x18) = 0;
  plVar2 = (longlong *)(lVar8 + 0xa8);
  lVar4 = *plVar2;
  if ((*(longlong **)(lVar4 + 8) != plVar2) ||
     (plVar5 = *(longlong **)(lVar8 + 0xb0), (longlong *)*plVar5 != plVar2)) {
    pcVar6 = (code *)swi(0x29);
    (*pcVar6)(3);
    pcVar6 = (code *)swi(3);
    lVar8 = (*pcVar6)();
    return lVar8;
  }
  *plVar5 = lVar4;
  *(longlong **)(lVar4 + 8) = plVar5;
  KeReleaseSpinLockFromDpcLevel(*(longlong *)(param_1 + 0x10) + 0x18);
  IoAcquireCancelSpinLock(lVar8 + 0x45);
  LOCK();
  lVar4 = *(longlong *)(lVar8 + 0x68);
  *(longlong *)(lVar8 + 0x68) = 0;
  UNLOCK();
  if (lVar4 != 0) {
    LOCK();
    piVar1 = (int *)(param_1 + 8);
    iVar3 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar3 == 1) {
      QosautopCleanupIrpContext(param_1,'\x01',param_3);
    }
  }
  IoReleaseCancelSpinLock(*(undefined1 *)(lVar8 + 0x45));
  KeAcquireSpinLockAtDpcLevel(param_1);
  LOCK();
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 0x20000;
  UNLOCK();
  cVar7 = KeCancelTimer(param_1 + 0x50);
  if (cVar7 != '\0') {
    LOCK();
    piVar1 = (int *)(param_1 + 8);
    iVar3 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar3 == 1) {
      QosautopCleanupIrpContext(param_1,'\x01',param_3);
    }
  }
  KeReleaseSpinLockFromDpcLevel(param_1);
  if (*(int *)(param_1 + 0x48) != 0) {
    lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x10);
    KeAcquireSpinLockAtDpcLevel(lVar4 + 0x18);
    if ((*(uint *)(lVar4 + 0x34) & 1) == 0) {
      LOCK();
      *(int *)(lVar4 + 0x140) = *(int *)(lVar4 + 0x140) + 1;
      UNLOCK();
      KeReleaseSpinLockFromDpcLevel();
      NdisCancelSendNetBufferLists(*(undefined8 *)(lVar4 + 0x80),*(undefined8 *)(param_1 + 0x38));
      LOCK();
      *(int *)(lVar4 + 0x140) = *(int *)(lVar4 + 0x140) + -1;
      UNLOCK();
    }
    else {
      KeReleaseSpinLockFromDpcLevel(lVar4 + 0x18);
    }
  }
  return lVar8;
}



===== QosautopInitializeIrpAndSendAtDpcLevel @ 140007c38 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
QosautopInitializeIrpAndSendAtDpcLevel
          (longlong param_1,longlong param_2,uint param_3,undefined8 param_4,undefined8 param_5,
          int param_6,undefined8 param_7,longlong param_8)

{
  byte *pbVar1;
  code *pcVar2;
  int iVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  ulonglong uVar7;
  undefined8 *puVar8;
  longlong lVar9;
  longlong *plVar10;
  undefined1 *puVar11;
  ushort uVar12;
  longlong lVar13;
  longlong *plVar14;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [40];
  
  uVar5 = *(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x80);
  KeAcquireSpinLockAtDpcLevel(&qospIrpContextLookasideListLock);
  lVar4 = ExAllocateFromNPagedLookasideList(&qospIrpContextLookasideList);
  KeReleaseSpinLockFromDpcLevel(&qospIrpContextLookasideListLock);
  if (lVar4 == 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
              &WPP_1564c523e1063e4f7fac143b272659d2_Traceguids);
    }
    uVar5 = 0xc000009a;
  }
  else {
    *(uint *)(lVar4 + 0xc) = param_3;
    *(longlong *)(lVar4 + 0x10) = param_1;
    *(longlong *)(lVar4 + 0x18) = param_2;
    *(int *)(lVar4 + 8) = param_6 + 2;
    *(longlong *)(lVar4 + 0x40) = param_8;
    iVar3 = topLocalNdisCancelId;
    LOCK();
    topLocalNdisCancelId = topLocalNdisCancelId + 1;
    UNLOCK();
    *(undefined4 *)(lVar4 + 0xd0) = 0;
    *(undefined8 *)(lVar4 + 0x28) = param_4;
    *(ulonglong *)(lVar4 + 0x38) =
         (longlong)(iVar3 + 1) & 0xffffffffffffffU | _topPartialNdisCancelId;
    *(int *)(lVar4 + 0x48) = param_6;
    *(undefined8 *)(lVar4 + 0x30) = param_5;
    if ((param_3 >> 0x12 & 1) == 0) {
      uVar12 = *(short *)(param_1 + 0x42) + 1;
      param_3 = (uint)uVar12;
      if (uVar12 == 0) {
        param_3 = 1;
      }
      *(short *)(param_1 + 0x42) = (short)param_3;
    }
    *(short *)(lVar4 + 0x20) = (short)param_3;
    KeInitializeSpinLock(lVar4);
    KeInitializeTimer(lVar4 + 0x50);
    KeInitializeDpc(lVar4 + 0x90,QosautopTimerDpc,lVar4);
    if (param_8 != 0) {
      LOCK();
      *(int *)(param_8 + 0x40) = *(int *)(param_8 + 0x40) + 1;
      UNLOCK();
    }
    KeAcquireSpinLockAtDpcLevel(param_1 + 0x18);
    puVar11 = auStack_48;
    LOCK();
    *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
    UNLOCK();
    plVar14 = (longlong *)(param_1 + 0x50);
    plVar10 = (longlong *)*plVar14;
    if (plVar10 != plVar14) {
      do {
        if (*(ushort *)(lVar4 + 0x20) <= *(ushort *)(plVar10[-6] + 0x20)) break;
        plVar10 = (longlong *)*plVar10;
      } while (plVar10 != plVar14);
    }
    *(longlong *)(param_2 + 0x78) = lVar4;
    LOCK();
    *(code **)(param_2 + 0x68) = QosautopCancelIrpCallback;
    UNLOCK();
    puVar6 = (undefined8 *)(param_2 + 0xa8);
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
    puVar8 = (undefined8 *)plVar10[1];
    if ((longlong *)*puVar8 != plVar10) {
      puVar8 = (undefined8 *)0x3;
      pcVar2 = (code *)swi(0x29);
      puVar6 = (undefined8 *)(*pcVar2)();
      puVar11 = auStack_40;
    }
    puVar6[1] = puVar8;
    *puVar6 = plVar10;
    *puVar8 = puVar6;
    plVar10[1] = (longlong)puVar6;
    *(undefined8 *)(puVar11 + -8) = 0x140007e36;
    KeReleaseSpinLockFromDpcLevel(param_1 + 0x18);
    uVar12 = *(ushort *)(lVar4 + 0x20);
    puVar6 = *(undefined8 **)(puVar11 + 0x80);
    while (puVar6 != (undefined8 *)0x0) {
      puVar8 = (undefined8 *)*puVar6;
      *puVar6 = 0;
      lVar13 = puVar6[1];
      puVar6[0xf] = uVar5;
      puVar6[0xb] = lVar4;
      puVar6[0x17] = *(undefined8 *)(lVar4 + 0x38);
      lVar9 = *(longlong *)(lVar13 + 8);
      if ((*(byte *)(lVar9 + 10) & 5) == 0) {
        *(undefined4 *)(puVar11 + 0x28) = 0x40000000;
        *(undefined4 *)(puVar11 + 0x20) = 0;
        *(undefined8 *)(puVar11 + -8) = 0x140007e9d;
        lVar9 = MmMapLockedPagesSpecifyCache(lVar9,0,1,0);
      }
      else {
        lVar9 = *(longlong *)(lVar9 + 0x18);
      }
      if (lVar9 == 0) {
        lVar9 = 0;
      }
      else {
        lVar9 = (ulonglong)*(uint *)(lVar13 + 0x10) + lVar9;
      }
      lVar13 = lVar9 + 4;
      if ((ushort)(*(ushort *)(lVar9 + 0xc) >> 8 | *(ushort *)(lVar9 + 0xc) << 8) != 0x8100) {
        lVar13 = lVar9;
      }
      *(ushort *)(lVar13 + 0x1e) = uVar12 >> 8 | uVar12 << 8;
      if (*(char *)(lVar13 + 0x11) == '\x02') {
        *(undefined8 *)(puVar11 + -8) = 0x140007edc;
        uVar7 = KeQueryPerformanceCounter(0);
        *(ulonglong *)(lVar13 + 0x20) =
             uVar7 >> 0x38 | (uVar7 & 0xff000000000000) >> 0x28 | (uVar7 & 0xff0000000000) >> 0x18 |
             (uVar7 & 0xff00000000) >> 8 | (uVar7 & 0xff000000) << 8 | (uVar7 & 0xff0000) << 0x18 |
             (uVar7 & 0xff00) << 0x28 | uVar7 << 0x38;
      }
      *(undefined8 *)(puVar11 + -8) = 0x140007efb;
      NdisSendNetBufferLists(uVar5,puVar6,0);
      puVar6 = puVar8;
    }
    uVar5 = 0;
  }
  return uVar5;
}



===== QosautopProbegapReceiveHandler @ 140007f40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void QosautopProbegapReceiveHandler
               (longlong param_1,longlong param_2,longlong param_3,undefined8 param_4)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  ulonglong uVar4;
  code *pcVar5;
  ulonglong *puVar6;
  longlong lVar7;
  undefined1 *puVar8;
  undefined8 uVar9;
  ulonglong uVar10;
  undefined8 *puVar11;
  undefined1 auStack_78 [32];
  undefined4 local_58;
  undefined4 local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined2 local_30;
  undefined1 local_2e;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_78;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  local_30 = 0;
  local_2e = 0;
  if ((*(char *)(param_3 + 3) == '\x02') && (uVar9 = 0x1b, 0x1a < *(uint *)(param_2 + 0x18))) {
    local_58 = 0;
    puVar11 = &local_48;
    puVar6 = (ulonglong *)NdisGetDataBuffer(param_2);
    if ((puVar6 != (ulonglong *)0x0) && ((char)puVar6[3] == '\x02')) {
      lVar7 = QosautopDetachIrpUnderLockAndReleaseFromDpcLevel(param_1,uVar9,puVar11);
      if (lVar7 == 0) {
        return;
      }
      lVar3 = *(longlong *)(lVar7 + 8);
      if ((*(byte *)(lVar3 + 10) & 5) == 0) {
        local_50 = 0x40000010;
        local_58 = 0;
        puVar11 = (undefined8 *)0x1;
        puVar8 = (undefined1 *)MmMapLockedPagesSpecifyCache(lVar3,0);
      }
      else {
        puVar8 = *(undefined1 **)(lVar3 + 0x18);
      }
      *puVar8 = *(undefined1 *)((longlong)puVar6 + 0x19);
      uVar4 = puVar6[1];
      *(ulonglong *)(puVar8 + 0x10) =
           uVar4 >> 0x38 | (uVar4 & 0xff000000000000) >> 0x28 | (uVar4 & 0xff0000000000) >> 0x18 |
           (uVar4 & 0xff00000000) >> 8 | (uVar4 & 0xff000000) << 8 | (uVar4 & 0xff0000) << 0x18 |
           (uVar4 & 0xff00) << 0x28 | uVar4 << 0x38;
      uVar4 = puVar6[2];
      *(ulonglong *)(puVar8 + 0x18) =
           uVar4 >> 0x38 | (uVar4 & 0xff000000000000) >> 0x28 | (uVar4 & 0xff0000000000) >> 0x18 |
           (uVar4 & 0xff00000000) >> 8 | (uVar4 & 0xff000000) << 8 | (uVar4 & 0xff0000) << 0x18 |
           (uVar4 & 0xff00) << 0x28 | uVar4 << 0x38;
      uVar4 = *puVar6;
      uVar10 = 0x28;
      *(ulonglong *)(puVar8 + 8) =
           uVar4 >> 0x38 | (uVar4 & 0xff000000000000) >> 0x28 | (uVar4 & 0xff0000000000) >> 0x18 |
           (uVar4 & 0xff00000000) >> 8 | (uVar4 & 0xff000000) << 8 | (uVar4 & 0xff0000) << 0x18 |
           (uVar4 & 0xff00) << 0x28 | uVar4 << 0x38;
      *(undefined8 *)(puVar8 + 0x20) = param_4;
      pcVar5 = *(code **)(param_1 + 0x28);
      if (pcVar5 != (code *)0x0) {
        puVar11 = (undefined8 *)0x0;
        uVar10 = -(ulonglong)(pcVar5 != QosautopCleanupIrpCompletionHandler) & 0x28;
        (*pcVar5)(param_1,lVar7,0,uVar10);
      }
      *(undefined4 *)(lVar7 + 0x30) = 0;
      *(ulonglong *)(lVar7 + 0x38) = uVar10;
      IofCompleteRequest(lVar7,2);
      LOCK();
      piVar1 = (int *)(param_1 + 8);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar2 == 1) {
        QosautopCleanupIrpContext(param_1,'\x01',puVar11);
        return;
      }
      return;
    }
  }
  KeReleaseSpinLockFromDpcLevel(*(longlong *)(param_1 + 0x10) + 0x18);
  return;
}



===== QosautopTimedProbeReceiveHandler @ 1400080e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void QosautopTimedProbeReceiveHandler(longlong param_1,longlong param_2,undefined8 *param_3)

{
  int *piVar1;
  int iVar2;
  code *pcVar3;
  ushort uVar4;
  ushort *puVar5;
  longlong lVar6;
  longlong lVar7;
  longlong lVar8;
  ulonglong *puVar9;
  uint uVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  longlong lVar13;
  ulonglong uVar14;
  undefined1 auStack_88 [32];
  undefined4 local_68;
  undefined4 local_60;
  uint local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined2 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_88;
  local_40 = 0;
  local_50 = 0;
  uStack_48 = 0;
  if (*(char *)((longlong)param_3 + 3) != '\x04') {
    lVar6 = *(longlong *)(param_1 + 0x10);
    goto LAB_1400081c4;
  }
  if (1 < *(uint *)(param_2 + 0x18)) {
    lVar6 = *(longlong *)(param_2 + 8);
    uVar10 = *(uint *)(param_2 + 0x10);
    if (*(int *)(lVar6 + 0x28) - uVar10 < 2) {
      local_68 = 0;
      param_3 = &local_50;
      uVar11 = 2;
      puVar5 = (ushort *)NdisGetDataBuffer(param_2);
      if (puVar5 != (ushort *)0x0) {
        uVar10 = *(int *)(param_2 + 0x10) + 2;
        if (uVar10 < *(uint *)(*(longlong *)(param_2 + 8) + 0x28)) {
          *(int *)(param_2 + 0x28) = *(int *)(param_2 + 0x28) + 2;
          *(int *)(param_2 + 0x18) = *(int *)(param_2 + 0x18) + -2;
          *(uint *)(param_2 + 0x10) = uVar10;
        }
        else {
          param_3 = (undefined8 *)0x0;
          uVar11 = 2;
          NdisAdvanceNetBufferDataStart(param_2);
        }
        goto LAB_140008251;
      }
    }
    else {
      if ((*(byte *)(lVar6 + 10) & 5) == 0) {
        local_60 = 0x40000000;
        local_68 = 0;
        param_3 = (undefined8 *)0x1;
        lVar7 = MmMapLockedPagesSpecifyCache(lVar6,0);
        lVar6 = *(longlong *)(param_2 + 8);
        uVar10 = *(uint *)(param_2 + 0x10);
      }
      else {
        lVar7 = *(longlong *)(lVar6 + 0x18);
      }
      if (lVar7 == 0) {
        puVar5 = (ushort *)0x0;
      }
      else {
        uVar10 = *(uint *)(param_2 + 0x10);
        puVar5 = (ushort *)(lVar7 + (ulonglong)uVar10);
      }
      uVar10 = uVar10 + 2;
      uVar11 = (ulonglong)uVar10;
      if (uVar10 < *(uint *)(lVar6 + 0x28)) {
        *(int *)(param_2 + 0x28) = *(int *)(param_2 + 0x28) + 2;
        *(int *)(param_2 + 0x18) = *(int *)(param_2 + 0x18) + -2;
        *(uint *)(param_2 + 0x10) = uVar10;
      }
      else {
        param_3 = (undefined8 *)0x0;
        uVar11 = 2;
        NdisAdvanceNetBufferDataStart(param_2);
      }
      if (puVar5 != (ushort *)0x0) {
LAB_140008251:
        uVar4 = *puVar5 >> 8 | *puVar5 << 8;
        uVar14 = (ulonglong)uVar4;
        if (uVar14 * 0x12 <= (ulonglong)*(uint *)(param_2 + 0x18)) {
          lVar6 = QosautopDetachIrpUnderLockAndReleaseFromDpcLevel(param_1,uVar11,param_3);
          if (lVar6 == 0) {
            return;
          }
          lVar7 = *(longlong *)(lVar6 + 8);
          if ((*(byte *)(lVar7 + 10) & 5) == 0) {
            local_60 = 0x40000010;
            local_68 = 0;
            param_3 = (undefined8 *)0x1;
            lVar7 = MmMapLockedPagesSpecifyCache(lVar7,0);
          }
          else {
            lVar7 = *(longlong *)(lVar7 + 0x18);
          }
          uVar10 = *(uint *)(*(longlong *)(lVar6 + 8) + 0x28) / 0x18;
          if (uVar10 < uVar4) {
            uVar14 = (ulonglong)uVar10;
          }
          local_58 = 0;
          do {
            if ((uint)uVar14 <= local_58) {
              pcVar3 = *(code **)(param_1 + 0x28);
              lVar7 = uVar14 * 0x18;
              if (pcVar3 != (code *)0x0) {
                lVar7 = 0;
                if (pcVar3 != QosautopCleanupIrpCompletionHandler) {
                  lVar7 = uVar14 * 0x18;
                }
                param_3 = (undefined8 *)0x0;
                (*pcVar3)(param_1,lVar6,0,lVar7);
              }
              *(undefined4 *)(lVar6 + 0x30) = 0;
              *(longlong *)(lVar6 + 0x38) = lVar7;
LAB_1400083cc:
              IofCompleteRequest(lVar6,2);
              LOCK();
              piVar1 = (int *)(param_1 + 8);
              iVar2 = *piVar1;
              *piVar1 = *piVar1 + -1;
              UNLOCK();
              if (iVar2 == 1) {
                QosautopCleanupIrpContext(param_1,'\x01',param_3);
                return;
              }
              return;
            }
            if (*(uint *)(param_2 + 0x18) < 0x12) {
LAB_14000838c:
              pcVar3 = *(code **)(param_1 + 0x28);
              uVar10 = 0xc000009a;
              if (pcVar3 != (code *)0x0) {
                uVar10 = -(uint)(pcVar3 != QosautopCleanupIrpCompletionHandler) & 0xc000009a;
                param_3 = (undefined8 *)(ulonglong)uVar10;
                (*pcVar3)(param_1,lVar6,param_3,0);
              }
              *(undefined8 *)(lVar6 + 0x38) = 0;
              *(uint *)(lVar6 + 0x30) = uVar10;
              goto LAB_1400083cc;
            }
            lVar13 = *(longlong *)(param_2 + 8);
            uVar10 = *(uint *)(param_2 + 0x10);
            if (*(int *)(lVar13 + 0x28) - uVar10 < 0x12) {
              local_68 = 0;
              param_3 = &local_50;
              puVar9 = (ulonglong *)NdisGetDataBuffer(param_2,0x12);
              if (puVar9 == (ulonglong *)0x0) goto LAB_14000838c;
              uVar10 = *(int *)(param_2 + 0x10) + 0x12;
              if (uVar10 < *(uint *)(*(longlong *)(param_2 + 8) + 0x28)) {
                *(int *)(param_2 + 0x28) = *(int *)(param_2 + 0x28) + 0x12;
                *(int *)(param_2 + 0x18) = *(int *)(param_2 + 0x18) + -0x12;
                *(uint *)(param_2 + 0x10) = uVar10;
              }
              else {
                param_3 = (undefined8 *)0x0;
                NdisAdvanceNetBufferDataStart(param_2,0x12);
              }
            }
            else {
              if ((*(byte *)(lVar13 + 10) & 5) == 0) {
                local_60 = 0x40000000;
                local_68 = 0;
                param_3 = (undefined8 *)0x1;
                lVar8 = MmMapLockedPagesSpecifyCache(lVar13,0);
                lVar13 = *(longlong *)(param_2 + 8);
                uVar10 = *(uint *)(param_2 + 0x10);
              }
              else {
                lVar8 = *(longlong *)(lVar13 + 0x18);
              }
              if (lVar8 == 0) {
                puVar9 = (ulonglong *)0x0;
              }
              else {
                uVar10 = *(uint *)(param_2 + 0x10);
                puVar9 = (ulonglong *)(lVar8 + (ulonglong)uVar10);
              }
              if (uVar10 + 0x12 < *(uint *)(lVar13 + 0x28)) {
                *(int *)(param_2 + 0x28) = *(int *)(param_2 + 0x28) + 0x12;
                *(int *)(param_2 + 0x18) = *(int *)(param_2 + 0x18) + -0x12;
                *(uint *)(param_2 + 0x10) = uVar10 + 0x12;
              }
              else {
                param_3 = (undefined8 *)0x0;
                NdisAdvanceNetBufferDataStart(param_2,0x12);
              }
              if (puVar9 == (ulonglong *)0x0) goto LAB_14000838c;
            }
            uVar12 = (ulonglong)local_58;
            local_58 = local_58 + 1;
            *(char *)(lVar7 + uVar12 * 0x18) = (char)puVar9[2];
            uVar11 = puVar9[1];
            *(ulonglong *)(lVar7 + 0x10 + uVar12 * 0x18) =
                 uVar11 >> 0x38 | (uVar11 & 0xff000000000000) >> 0x28 |
                 (uVar11 & 0xff0000000000) >> 0x18 | (uVar11 & 0xff00000000) >> 8 |
                 (uVar11 & 0xff000000) << 8 | (uVar11 & 0xff0000) << 0x18 |
                 (uVar11 & 0xff00) << 0x28 | uVar11 << 0x38;
            uVar11 = *puVar9;
            *(ulonglong *)(lVar7 + 8 + uVar12 * 0x18) =
                 uVar11 >> 0x38 | (uVar11 & 0xff000000000000) >> 0x28 |
                 (uVar11 & 0xff0000000000) >> 0x18 | (uVar11 & 0xff00000000) >> 8 |
                 (uVar11 & 0xff000000) << 8 | (uVar11 & 0xff0000) << 0x18 |
                 (uVar11 & 0xff00) << 0x28 | uVar11 << 0x38;
          } while( true );
        }
      }
    }
  }
  lVar6 = *(longlong *)(param_1 + 0x10);
LAB_1400081c4:
  KeReleaseSpinLockFromDpcLevel(lVar6 + 0x18);
  return;
}



===== QosautopTimerDpc @ 1400084e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void QosautopTimerDpc(undefined8 param_1,longlong param_2,undefined8 param_3)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  undefined8 uVar5;
  
  KeAcquireSpinLockAtDpcLevel(param_2);
  if ((*(uint *)(param_2 + 0xc) & 0x20000) == 0) {
    if ((*(uint *)(param_2 + 0xd0) < 3) && (lVar3 = *(longlong *)(param_2 + 0x40), lVar3 != 0)) {
      lVar4 = *(longlong *)(*(longlong *)(param_2 + 0x10) + 0x10);
      *(undefined4 *)(param_2 + 0x48) = 1;
      LOCK();
      *(int *)(lVar3 + 0x40) = *(int *)(lVar3 + 0x40) + 1;
      UNLOCK();
      LOCK();
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 1;
      UNLOCK();
      KeReleaseSpinLockFromDpcLevel(param_2);
      KeAcquireSpinLockAtDpcLevel(lVar4 + 0x18);
      if ((*(uint *)(lVar4 + 0x34) & 1) == 0) {
        LOCK();
        *(int *)(lVar4 + 0x140) = *(int *)(lVar4 + 0x140) + 1;
        UNLOCK();
        KeReleaseSpinLockFromDpcLevel(lVar4 + 0x18);
        uVar5 = *(undefined8 *)(lVar4 + 0x80);
        param_3 = 0;
        *(undefined8 *)(lVar3 + 0x78) = uVar5;
        NdisSendNetBufferLists(uVar5,lVar3,0,1);
        LOCK();
        *(int *)(lVar4 + 0x140) = *(int *)(lVar4 + 0x140) + -1;
        UNLOCK();
      }
      else {
        KeReleaseSpinLockFromDpcLevel();
        KeAcquireSpinLockAtDpcLevel(param_2);
        *(undefined4 *)(param_2 + 0x48) = 0;
        KeReleaseSpinLockFromDpcLevel(param_2);
        LOCK();
        piVar1 = (int *)(lVar3 + 0x40);
        iVar2 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar2 == 1) {
          param_3 = *(undefined8 *)(lVar3 + 0x58);
          (**(code **)(lVar3 + 0x48))(lVar3,*(undefined8 *)(lVar3 + 0x50),param_3,1);
        }
        QosautopCompleteIrpAtDpcLevel(param_2,0xc00002fe);
        LOCK();
        piVar1 = (int *)(param_2 + 8);
        iVar2 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar2 == 1) {
          QosautopCleanupIrpContext(param_2,'\x01',param_3);
        }
      }
    }
    else {
      KeReleaseSpinLockFromDpcLevel(param_2);
      QosautopCompleteIrpAtDpcLevel(param_2,0xc00000b5);
    }
  }
  else {
    KeReleaseSpinLockFromDpcLevel(param_2);
  }
  LOCK();
  piVar1 = (int *)(param_2 + 8);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    QosautopCleanupIrpContext(param_2,'\x01',param_3);
  }
  return;
}



===== QosdiagBindDevice @ 140008690 =====

ulonglong QosdiagBindDevice(longlong param_1,undefined8 param_2,ushort *param_3,uint param_4,
                           uint *param_5,undefined8 *param_6)

{
  int *piVar1;
  longlong lVar2;
  int iVar3;
  undefined4 extraout_var;
  ulonglong uVar4;
  ulonglong uVar5;
  longlong local_18;
  undefined8 local_10;
  
  local_18 = 0;
  local_10 = 0;
  iVar3 = TopBindDevice(param_1,0,param_3,param_4,param_5,&local_18);
  lVar2 = local_18;
  uVar4 = CONCAT44(extraout_var,iVar3);
  if (-1 < iVar3) {
    uVar5 = TopReferencePacketFilter(local_18,0);
    uVar4 = uVar5 & 0xffffffff;
    if (-1 < (int)uVar5) {
      KeAcquireSpinLockRaiseToDpc(lVar2 + 400);
      uVar5 = QosdiagCreateSession(lVar2,&local_10);
      uVar4 = uVar5 & 0xffffffff;
      if ((int)uVar5 < 0) {
        KeReleaseSpinLock();
        TopDereferencePacketFilterSafe(lVar2,0,(undefined *)param_3);
      }
      else {
        KeReleaseSpinLock(lVar2 + 400);
        uVar4 = 0;
        *param_6 = local_10;
      }
    }
    LOCK();
    piVar1 = (int *)(lVar2 + 0x30);
    iVar3 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar3 == 1) {
      NdisFreeMemory(local_18,0,0);
    }
  }
  return uVar4;
}



===== QosdiagCreateSession @ 14000878c =====

undefined8 QosdiagCreateSession(longlong param_1,undefined8 *param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  code *pcVar5;
  undefined8 uVar6;
  undefined4 *_Dst;
  longlong *plVar7;
  ushort uVar8;
  longlong lVar9;
  longlong *plVar10;
  longlong lVar11;
  undefined1 *puVar12;
  int iVar13;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  if (*(uint *)(param_1 + 0x1bc) < 0x20) {
    _Dst = (undefined4 *)ExAllocatePool2(0x40,0x60,0x53446f49);
    lVar11 = 0;
    if (_Dst == (undefined4 *)0x0) {
      uVar6 = 0xc000009a;
    }
    else {
      memset(_Dst,0,0x60);
      KeInitializeSpinLock(_Dst + 6);
      puVar12 = auStack_28;
      puVar1 = _Dst + 0x14;
      *(undefined4 **)(_Dst + 0x16) = puVar1;
      *(undefined4 **)puVar1 = puVar1;
      *(undefined ***)(_Dst + 2) = &PTR_QospCloseHandler_14000d130;
      iVar13 = 1;
      *_Dst = 2;
      *(longlong *)(_Dst + 4) = param_1;
      _Dst[8] = 2;
      *(undefined2 *)((longlong)_Dst + 0x42) = 0;
      LOCK();
      *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + 1;
      UNLOCK();
      lVar9 = param_1 + 0x1a8;
      plVar10 = *(longlong **)(param_1 + 0x1b0);
      plVar7 = (longlong *)(_Dst + 10);
      if (*plVar10 != lVar9) {
        lVar9 = 3;
        pcVar5 = (code *)swi(0x29);
        iVar13 = 1;
        plVar7 = (longlong *)(*pcVar5)();
        puVar12 = auStack_20;
      }
      *plVar7 = lVar9;
      plVar7[1] = (longlong)plVar10;
      *plVar10 = (longlong)plVar7;
      *(longlong **)(lVar9 + 8) = plVar7;
      uVar8 = 0;
      uVar4 = *(uint *)(param_1 + 0x1c0);
      if ((byte)((byte)iVar13 & (byte)uVar4) != 0) {
        do {
          uVar8 = uVar8 + (short)iVar13;
        } while ((uVar4 >> ((byte)uVar8 & 0x1f) & 1) != 0);
      }
      *(uint *)(param_1 + 0x1c0) = uVar4 | 1 << (uVar8 & 0x1f);
      *(ushort *)((longlong)_Dst + 0x42) = uVar8 << 0xb;
      LOCK();
      piVar2 = (int *)(param_1 + 0x1bc);
      iVar3 = *piVar2;
      *piVar2 = *piVar2 + iVar13;
      UNLOCK();
      if ((iVar3 + iVar13 == iVar13) && (2 < *(ushort *)(param_1 + 0x250))) {
        *(undefined8 *)(puVar12 + 0x30) = 0;
        *(undefined8 *)(puVar12 + -8) = 0x1400088bf;
        NdisGetSystemUpTimeEx(puVar12 + 0x30);
        if ((ulonglong)(*(longlong *)(puVar12 + 0x30) - *(longlong *)(param_1 + 0x248)) < 240000) {
          lVar11 = ((*(longlong *)(puVar12 + 0x30) - *(longlong *)(param_1 + 0x248)) - 240000U) *
                   10000;
        }
        *(undefined8 *)(puVar12 + -8) = 0x1400088fd;
        KeSetTimer(param_1 + 0x1c8,lVar11,param_1 + 0x208);
      }
      *param_2 = _Dst;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
        uVar6 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
        *(undefined8 *)(puVar12 + -8) = 0x14000893a;
        WPP_SF_(uVar6,10,&WPP_1564c523e1063e4f7fac143b272659d2_Traceguids);
      }
      uVar6 = 0;
    }
  }
  else {
    uVar6 = 0x80000011;
  }
  return uVar6;
}



===== QosdiagpCleanupHandler @ 140008960 =====

undefined8 QosdiagpCleanupHandler(undefined8 **param_1,longlong param_2,undefined *param_3)

{
  undefined8 **ppuVar1;
  longlong *plVar2;
  int iVar3;
  undefined8 *puVar4;
  undefined1 uVar5;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0))
  {
    plVar2 = (longlong *)(param_2 + 0xb8);
    param_3 = &WPP_1564c523e1063e4f7fac143b272659d2_Traceguids;
    param_2 = 0x11;
    WPP_SF_qqD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
               &WPP_1564c523e1063e4f7fac143b272659d2_Traceguids,*(undefined8 *)(*plVar2 + 0x30),
               (char)param_1,(char)*(undefined4 *)(param_1 + 4));
  }
  puVar4 = param_1[2];
  uVar5 = KeAcquireSpinLockRaiseToDpc(param_1 + 3);
  KeAcquireSpinLockAtDpcLevel(puVar4 + 0x32);
  LOCK();
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  UNLOCK();
  QosDeleteSession((int *)param_1);
  KeReleaseSpinLockFromDpcLevel(puVar4 + 0x32);
  KeReleaseSpinLockFromDpcLevel(param_1 + 3);
  QospShutdownSessionAtDpcLevel(param_1);
  KeLowerIrql(uVar5);
  LOCK();
  ppuVar1 = param_1 + 4;
  iVar3 = *(int *)ppuVar1;
  *(int *)ppuVar1 = *(int *)ppuVar1 + -1;
  UNLOCK();
  if (iVar3 == 1) {
    QosCleanupSession((longlong)param_1,param_2,param_3);
  }
  return 0;
}



===== QosdiagpCounterSnapshotReceiveHandler @ 140008a70 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void QosdiagpCounterSnapshotReceiveHandler(longlong param_1,longlong param_2,undefined8 *param_3)

{
  int *piVar1;
  int iVar2;
  code *pcVar3;
  longlong lVar4;
  longlong lVar5;
  undefined1 *puVar6;
  longlong lVar7;
  ushort *puVar8;
  uint uVar9;
  ulonglong uVar10;
  uint uVar11;
  uint uVar12;
  undefined1 *puVar13;
  undefined1 auStack_68 [32];
  undefined4 local_48;
  undefined4 local_40;
  undefined8 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_68;
  uVar9 = 0;
  local_38 = 0;
  if (*(char *)((longlong)param_3 + 3) != '\t') {
    lVar5 = *(longlong *)(param_1 + 0x10);
    goto LAB_140008b53;
  }
  if (3 < *(uint *)(param_2 + 0x18)) {
    lVar5 = *(longlong *)(param_2 + 8);
    uVar11 = *(uint *)(param_2 + 0x10);
    if (*(int *)(lVar5 + 0x28) - uVar11 < 4) {
      local_48 = 0;
      param_3 = &local_38;
      uVar10 = 4;
      puVar13 = (undefined1 *)NdisGetDataBuffer(param_2);
      if (puVar13 != (undefined1 *)0x0) {
        uVar11 = *(int *)(param_2 + 0x10) + 4;
        if (uVar11 < *(uint *)(*(longlong *)(param_2 + 8) + 0x28)) {
          *(int *)(param_2 + 0x28) = *(int *)(param_2 + 0x28) + 4;
          *(int *)(param_2 + 0x18) = *(int *)(param_2 + 0x18) + -4;
          *(uint *)(param_2 + 0x10) = uVar11;
        }
        else {
          param_3 = (undefined8 *)0x0;
          uVar10 = 4;
          NdisAdvanceNetBufferDataStart(param_2);
        }
        goto LAB_140008be5;
      }
    }
    else {
      if ((*(byte *)(lVar5 + 10) & 5) == 0) {
        local_40 = 0x40000000;
        local_48 = 0;
        param_3 = (undefined8 *)0x1;
        lVar4 = MmMapLockedPagesSpecifyCache(lVar5,0);
        lVar5 = *(longlong *)(param_2 + 8);
        uVar11 = *(uint *)(param_2 + 0x10);
      }
      else {
        lVar4 = *(longlong *)(lVar5 + 0x18);
      }
      if (lVar4 == 0) {
        puVar13 = (undefined1 *)0x0;
      }
      else {
        uVar11 = *(uint *)(param_2 + 0x10);
        puVar13 = (undefined1 *)(lVar4 + (ulonglong)uVar11);
      }
      uVar11 = uVar11 + 4;
      uVar10 = (ulonglong)uVar11;
      if (uVar11 < *(uint *)(lVar5 + 0x28)) {
        *(int *)(param_2 + 0x28) = *(int *)(param_2 + 0x28) + 4;
        *(int *)(param_2 + 0x18) = *(int *)(param_2 + 0x18) + -4;
        *(uint *)(param_2 + 0x10) = uVar11;
      }
      else {
        param_3 = (undefined8 *)0x0;
        uVar10 = 4;
        NdisAdvanceNetBufferDataStart(param_2);
      }
      if (puVar13 != (undefined1 *)0x0) {
LAB_140008be5:
        uVar11 = (byte)puVar13[3] + 1;
        if (uVar11 * 8 <= *(uint *)(param_2 + 0x18)) {
          lVar5 = QosautopDetachIrpUnderLockAndReleaseFromDpcLevel(param_1,uVar10,param_3);
          if (lVar5 == 0) {
            return;
          }
          lVar4 = *(longlong *)(lVar5 + 8);
          if ((*(byte *)(lVar4 + 10) & 5) == 0) {
            local_40 = 0x40000010;
            local_48 = 0;
            param_3 = (undefined8 *)0x1;
            puVar6 = (undefined1 *)MmMapLockedPagesSpecifyCache(lVar4,0);
          }
          else {
            puVar6 = *(undefined1 **)(lVar4 + 0x18);
          }
          puVar6[2] = *puVar13;
          *puVar6 = puVar13[1];
          puVar6[1] = puVar13[2];
          uVar12 = (int)((ulonglong)*(uint *)(*(longlong *)(lVar5 + 8) + 0x28) - 0xc >> 3) + 1;
          if (uVar12 < uVar11) {
            uVar11 = uVar12;
          }
          do {
            if (uVar11 <= uVar9) {
              lVar4 = (ulonglong)(uVar11 - 1) * 8 + 0xc;
              pcVar3 = *(code **)(param_1 + 0x28);
              lVar7 = lVar4;
              if (pcVar3 != (code *)0x0) {
                lVar7 = 0;
                if (pcVar3 != QosautopCleanupIrpCompletionHandler) {
                  lVar7 = lVar4;
                }
                param_3 = (undefined8 *)0x0;
                (*pcVar3)(param_1,lVar5,0,lVar7);
              }
              *(undefined4 *)(lVar5 + 0x30) = 0;
              *(longlong *)(lVar5 + 0x38) = lVar7;
LAB_140008d62:
              IofCompleteRequest(lVar5,2);
              LOCK();
              piVar1 = (int *)(param_1 + 8);
              iVar2 = *piVar1;
              *piVar1 = *piVar1 + -1;
              UNLOCK();
              if (iVar2 == 1) {
                QosautopCleanupIrpContext(param_1,'\x01',param_3);
                return;
              }
              return;
            }
            if (*(uint *)(param_2 + 0x18) < 8) {
LAB_140008d22:
              pcVar3 = *(code **)(param_1 + 0x28);
              uVar9 = 0xc000009a;
              if (pcVar3 != (code *)0x0) {
                uVar9 = -(uint)(pcVar3 != QosautopCleanupIrpCompletionHandler) & 0xc000009a;
                param_3 = (undefined8 *)(ulonglong)uVar9;
                (*pcVar3)(param_1,lVar5,param_3,0);
              }
              *(undefined8 *)(lVar5 + 0x38) = 0;
              *(uint *)(lVar5 + 0x30) = uVar9;
              goto LAB_140008d62;
            }
            lVar4 = *(longlong *)(param_2 + 8);
            uVar12 = *(uint *)(param_2 + 0x10);
            if (*(int *)(lVar4 + 0x28) - uVar12 < 8) {
              local_48 = 0;
              param_3 = &local_38;
              puVar8 = (ushort *)NdisGetDataBuffer(param_2,8);
              if (puVar8 == (ushort *)0x0) goto LAB_140008d22;
              uVar12 = *(int *)(param_2 + 0x10) + 8;
              if (uVar12 < *(uint *)(*(longlong *)(param_2 + 8) + 0x28)) {
                *(int *)(param_2 + 0x28) = *(int *)(param_2 + 0x28) + 8;
                *(int *)(param_2 + 0x18) = *(int *)(param_2 + 0x18) + -8;
                *(uint *)(param_2 + 0x10) = uVar12;
              }
              else {
                param_3 = (undefined8 *)0x0;
                NdisAdvanceNetBufferDataStart(param_2,8);
              }
            }
            else {
              if ((*(byte *)(lVar4 + 10) & 5) == 0) {
                local_40 = 0x40000000;
                local_48 = 0;
                param_3 = (undefined8 *)0x1;
                lVar7 = MmMapLockedPagesSpecifyCache(lVar4,0);
                lVar4 = *(longlong *)(param_2 + 8);
                uVar12 = *(uint *)(param_2 + 0x10);
              }
              else {
                lVar7 = *(longlong *)(lVar4 + 0x18);
              }
              if (lVar7 == 0) {
                puVar8 = (ushort *)0x0;
              }
              else {
                uVar12 = *(uint *)(param_2 + 0x10);
                puVar8 = (ushort *)(lVar7 + (ulonglong)uVar12);
              }
              if (uVar12 + 8 < *(uint *)(lVar4 + 0x28)) {
                *(int *)(param_2 + 0x28) = *(int *)(param_2 + 0x28) + 8;
                *(int *)(param_2 + 0x18) = *(int *)(param_2 + 0x18) + -8;
                *(uint *)(param_2 + 0x10) = uVar12 + 8;
              }
              else {
                param_3 = (undefined8 *)0x0;
                NdisAdvanceNetBufferDataStart(param_2,8);
              }
              if (puVar8 == (ushort *)0x0) goto LAB_140008d22;
            }
            uVar10 = (ulonglong)uVar9;
            *(ushort *)(puVar6 + uVar10 * 8 + 4) = puVar8[2] >> 8 | puVar8[2] << 8;
            *(ushort *)(puVar6 + uVar10 * 8 + 6) = *puVar8 >> 8 | *puVar8 << 8;
            *(ushort *)(puVar6 + uVar10 * 8 + 8) = puVar8[3] >> 8 | puVar8[3] << 8;
            *(ushort *)(puVar6 + uVar10 * 8 + 10) = puVar8[1] >> 8 | puVar8[1] << 8;
            uVar9 = uVar9 + 1;
          } while( true );
        }
      }
    }
  }
  lVar5 = *(longlong *)(param_1 + 0x10);
LAB_140008b53:
  KeReleaseSpinLockFromDpcLevel(lVar5 + 0x18);
  return;
}



===== QosdiagpDeviceControlHandler @ 140008e90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong QosdiagpDeviceControlHandler(ulonglong param_1,longlong param_2)

{
  int *piVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  undefined4 *puVar6;
  undefined1 uVar7;
  uint uVar8;
  ulonglong uVar9;
  longlong lVar10;
  undefined8 uVar11;
  undefined1 uVar12;
  uint uVar13;
  longlong local_res10;
  longlong local_res18 [2];
  ulonglong in_stack_ffffffffffffff98;
  
  lVar5 = *(longlong *)(param_1 + 0x10);
  uVar13 = 0;
  local_res10 = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  if ((*(uint *)(lVar5 + 0x34) & 0x40) == 0) {
    if ((char)*(uint *)(lVar5 + 0x34) < '\0') {
      uVar8 = topActivePolicyFlags & 8;
      goto LAB_140008ec4;
    }
    if ((topActivePolicyFlags & 4) != 0) {
      uVar13 = 0xeaaa8000;
      goto LAB_140008ee4;
    }
  }
  else {
    uVar8 = topActivePolicyFlags & 2;
LAB_140008ec4:
    if (uVar8 != 0) {
      uVar13 = 0xc0000364;
LAB_140008ee4:
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
                 &WPP_1564c523e1063e4f7fac143b272659d2_Traceguids,uVar13);
      }
      goto LAB_140008f1d;
    }
  }
  lVar10 = *(longlong *)(param_2 + 0xb8);
  iVar3 = *(int *)(lVar10 + 0x18);
  iVar4 = *(int *)(lVar10 + 0x10);
  uVar8 = *(uint *)(lVar10 + 8);
  if (iVar3 == 0x128012) {
    lVar10 = *(longlong *)(param_2 + 8);
    if ((lVar10 != 0) && (uVar8 <= *(uint *)(lVar10 + 0x28))) {
      if ((*(byte *)(lVar10 + 10) & 5) == 0) {
        lVar10 = MmMapLockedPagesSpecifyCache
                           (lVar10,0,1,0,in_stack_ffffffffffffff98 & 0xffffffff00000000,0x40000010);
      }
      else {
        lVar10 = *(longlong *)(lVar10 + 0x18);
      }
      if (((lVar10 != 0) && (iVar4 == 0x10)) && (0xb < uVar8)) {
        puVar6 = *(undefined4 **)(param_2 + 0x18);
        lVar10 = lVar5 + 0x18;
        uVar7 = KeAcquireSpinLockRaiseToDpc(lVar10);
        if ((*(uint *)(lVar5 + 0x34) & 1) != 0) {
          KeReleaseSpinLock(lVar10,CONCAT31((int3)(*(uint *)(lVar5 + 0x34) >> 8),uVar7));
          return 0xc00002fe;
        }
        LOCK();
        *(int *)(lVar5 + 0x140) = *(int *)(lVar5 + 0x140) + 1;
        UNLOCK();
        KeReleaseSpinLockFromDpcLevel(lVar10);
        lVar10 = QospAllocateAndInitializePacket
                           (*(undefined8 *)(lVar5 + 0x80),&local_res10,0x21,'\0',puVar6,
                            (undefined4 *)(lVar5 + 0x124),(undefined4 *)((longlong)puVar6 + 6),'\b',
                            &local_res10);
        if (lVar10 != 0) {
          uVar12 = 0xff;
          if ((uint)puVar6[3] < 0x100) {
            uVar12 = (char)puVar6[3];
          }
          *(undefined1 *)(lVar10 + 0x12) = uVar12;
          KeAcquireSpinLockAtDpcLevel(lVar5 + 400);
          uVar8 = *(int *)(lVar5 + 0x1c4) + 1;
          uVar13 = 1;
          if (uVar8 < 0x800) {
            uVar13 = uVar8;
          }
          *(uint *)(lVar5 + 0x1c4) = uVar13;
          uVar2 = *(ushort *)(param_1 + 0x42);
          KeReleaseSpinLockFromDpcLevel(lVar5 + 400);
          lVar10 = local_res10;
          uVar11 = QosautopInitializeIrpAndSendAtDpcLevel
                             (param_1,param_2,uVar2 | uVar13 | 0x40000,0,
                              QosdiagpCounterSnapshotReceiveHandler,1,local_res10,local_res10);
          if ((int)uVar11 < 0) {
            LOCK();
            piVar1 = (int *)(lVar10 + 0x40);
            iVar3 = *piVar1;
            *piVar1 = *piVar1 + -1;
            UNLOCK();
            if (iVar3 == 1) {
              (**(code **)(lVar10 + 0x48))
                        (local_res10,*(undefined8 *)(lVar10 + 0x50),*(undefined8 *)(lVar10 + 0x58),1
                        );
            }
          }
          KeLowerIrql(uVar7);
          LOCK();
          *(int *)(lVar5 + 0x140) = *(int *)(lVar5 + 0x140) + -1;
          UNLOCK();
          return 0x103;
        }
        KeLowerIrql(uVar7);
        LOCK();
        *(int *)(lVar5 + 0x140) = *(int *)(lVar5 + 0x140) + -1;
        UNLOCK();
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
                  &WPP_1564c523e1063e4f7fac143b272659d2_Traceguids);
        }
        return 0xc000009a;
      }
    }
  }
  else if (iVar3 == 0x12801e) {
    local_res18[0] = 0;
    if ((iVar4 == 0) && (uVar8 == 0)) {
      NdisGetSystemUpTimeEx(local_res18);
      uVar7 = KeAcquireSpinLockRaiseToDpc(lVar5 + 400);
      if (2 < *(ushort *)(lVar5 + 0x250)) {
        if ((ulonglong)(local_res18[0] - *(longlong *)(lVar5 + 0x248)) < 60000) {
          uVar13 = 0xc0000044;
        }
        else {
          KeSetTimer(lVar5 + 0x1c8,0,lVar5 + 0x208);
        }
      }
      KeReleaseSpinLock(lVar5 + 400,uVar7);
LAB_140008f1d:
      return (ulonglong)uVar13;
    }
  }
  else {
    if (iVar3 != 0x124022) {
      return 0xc0000010;
    }
    if ((iVar4 == 0) && (uVar8 == 0)) {
      uVar9 = TopRegisterUnbindNotification(*(longlong *)(param_1 + 0x10),param_2,param_1);
      if ((int)uVar9 < 0) {
        return uVar9 & 0xffffffff;
      }
      return 0x103;
    }
  }
  return 0xc000000d;
}



===== QosdiagpReceiveHandler @ 140009270 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void QosdiagpReceiveHandler
               (longlong param_1,longlong param_2,undefined8 param_3,undefined8 *param_4,
               char param_5)

{
  int *piVar1;
  longlong lVar2;
  int iVar3;
  ushort uVar4;
  undefined1 uVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  ushort uVar9;
  undefined8 *puVar10;
  
  lVar2 = param_1 + 400;
  uVar4 = *(ushort *)(param_4 + 2) << 8;
  uVar9 = *(ushort *)(param_4 + 2) >> 8 | uVar4;
  uVar5 = 0;
  if (param_5 == '\0') {
    uVar5 = KeAcquireSpinLockRaiseToDpc(lVar2);
  }
  else {
    KeAcquireSpinLockAtDpcLevel();
  }
  puVar8 = (undefined8 *)(param_1 + 0x1a8);
  puVar7 = (undefined8 *)*puVar8;
  do {
    if (puVar7 == puVar8) {
LAB_14000939e:
      if (param_5 == '\0') {
        KeReleaseSpinLock(lVar2,CONCAT71((int7)((ulonglong)puVar8 >> 8),uVar5));
        return;
      }
      KeReleaseSpinLockFromDpcLevel();
      return;
    }
    if (*(ushort *)((longlong)puVar7 + 0x1a) == (uVar4 & 0xf800)) {
      if ((*(uint *)(puVar7 + 2) & 1) == 0) {
        LOCK();
        *(int *)(puVar7 + -1) = *(int *)(puVar7 + -1) + 1;
        UNLOCK();
        KeReleaseSpinLockFromDpcLevel(lVar2);
        KeAcquireSpinLockAtDpcLevel(puVar7 + -2);
        puVar10 = puVar7 + 5;
        puVar6 = (undefined8 *)*puVar10;
        break;
      }
      goto LAB_14000939e;
    }
    puVar7 = (undefined8 *)*puVar7;
  } while( true );
LAB_140009335:
  if (puVar6 == puVar10) {
LAB_140009361:
    KeReleaseSpinLockFromDpcLevel(puVar7 + -2);
LAB_140009371:
    if (param_5 == '\0') {
      KeLowerIrql(uVar5);
    }
    LOCK();
    piVar1 = (int *)(puVar7 + -1);
    iVar3 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar3 == 1) {
      QosCleanupSession((longlong)(puVar7 + -5),puVar8,puVar10);
    }
    return;
  }
  uVar4 = *(ushort *)(puVar6[-6] + 0x20);
  if (uVar9 <= uVar4) {
    if (uVar9 == uVar4) {
      puVar8 = *(undefined8 **)(param_2 + 8);
      (**(code **)(puVar6[-6] + 0x30))();
      puVar10 = param_4;
      goto LAB_140009371;
    }
    goto LAB_140009361;
  }
  puVar6 = (undefined8 *)*puVar6;
  goto LAB_140009335;
}



===== QosdiagpRenewalTimerDpc @ 1400093f0 =====

void QosdiagpRenewalTimerDpc(undefined8 param_1,longlong param_2,longlong param_3)

{
  int iVar1;
  longlong lVar2;
  undefined8 uVar3;
  ushort uVar4;
  longlong lVar5;
  longlong lVar6;
  undefined4 *puVar7;
  bool bVar8;
  undefined8 local_res10;
  
  local_res10 = 0;
  NdisGetSystemUpTimeEx(&local_res10);
  lVar5 = param_2 + 400;
  KeAcquireSpinLockAtDpcLevel(lVar5);
  iVar1 = *(int *)(param_2 + 0x1bc);
  if (*(ushort *)(param_2 + 0x250) < 3) {
    uVar4 = *(ushort *)(param_2 + 0x250) + 1;
  }
  else {
    if (iVar1 == 0) goto LAB_140009451;
    uVar4 = 1;
  }
  *(ushort *)(param_2 + 0x250) = uVar4;
  *(undefined8 *)(param_2 + 0x248) = local_res10;
  KeReleaseSpinLockFromDpcLevel(lVar5);
  lVar5 = param_2 + 0x18;
  KeAcquireSpinLockAtDpcLevel(lVar5);
  if ((*(uint *)(param_2 + 0x34) & 1) == 0) {
    if ((*(ushort *)(param_2 + 0x250) < 3) || (iVar1 != 0)) {
      param_3 = param_2 + 0x208;
      KeSetTimer(param_2 + 0x1c8,(-(ulonglong)(uVar4 < 3) & 0x8edf5140) - 2400000000);
    }
    if ((*(uint *)(param_2 + 0x34) & 0x40) == 0) {
      if ((char)*(uint *)(param_2 + 0x34) < '\0') {
        bVar8 = (topActivePolicyFlags & 8) == 0;
      }
      else {
        bVar8 = (topActivePolicyFlags & 4) == 0;
      }
    }
    else {
      bVar8 = (topActivePolicyFlags & 2) == 0;
    }
    if (bVar8) {
      LOCK();
      *(int *)(param_2 + 0x140) = *(int *)(param_2 + 0x140) + 1;
      UNLOCK();
      KeReleaseSpinLockFromDpcLevel();
      lVar5 = TopAllocateAndReferenceNetBufferAndNetBufferListNoMdl
                        (lVar5,*(undefined8 *)(param_2 + 0x80),param_3,0x20);
      if (lVar5 == 0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
                  &WPP_1564c523e1063e4f7fac143b272659d2_Traceguids);
        }
        LOCK();
        *(int *)(param_2 + 0x140) = *(int *)(param_2 + 0x140) + -1;
        UNLOCK();
        return;
      }
      lVar2 = *(longlong *)(lVar5 + 8);
      lVar6 = *(longlong *)(lVar2 + 8);
      if ((*(byte *)(lVar6 + 10) & 5) == 0) {
        lVar6 = MmMapLockedPagesSpecifyCache(lVar6,0,1,0,0,0x40000000);
      }
      else {
        lVar6 = *(longlong *)(lVar6 + 0x18);
      }
      if (lVar6 == 0) {
        puVar7 = (undefined4 *)0x0;
      }
      else {
        puVar7 = (undefined4 *)((ulonglong)*(uint *)(lVar2 + 0x10) + lVar6);
      }
      *puVar7 = 0xffffffff;
      *(undefined2 *)(puVar7 + 1) = 0xffff;
      *(undefined4 *)((longlong)puVar7 + 6) = *(undefined4 *)(param_2 + 0x124);
      *(undefined2 *)((longlong)puVar7 + 10) = *(undefined2 *)(param_2 + 0x128);
      puVar7[3] = 0x201d988;
      *(undefined2 *)(puVar7 + 4) = 0xa00;
      *(undefined4 *)((longlong)puVar7 + 0x12) = 0xffffffff;
      *(undefined2 *)((longlong)puVar7 + 0x16) = 0xffff;
      puVar7[6] = *(undefined4 *)(param_2 + 0x124);
      *(undefined2 *)(puVar7 + 7) = *(undefined2 *)(param_2 + 0x128);
      *(undefined2 *)((longlong)puVar7 + 0x1e) = 0;
      uVar3 = *(undefined8 *)(param_2 + 0x80);
      *(undefined8 *)(lVar5 + 0x78) = uVar3;
      NdisSendNetBufferLists(uVar3,lVar5,0,0);
      return;
    }
    KeReleaseSpinLockFromDpcLevel();
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0) {
      return;
    }
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
            &WPP_1564c523e1063e4f7fac143b272659d2_Traceguids);
    return;
  }
LAB_140009451:
  KeReleaseSpinLockFromDpcLevel(lVar5);
  return;
}



===== QospAllocateAndInitializePacket @ 1400096cc =====

void QospAllocateAndInitializePacket
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,char param_4,
               undefined4 *param_5,undefined4 *param_6,undefined4 *param_7,char param_8,
               longlong *param_9)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  undefined4 *puVar4;
  
  lVar1 = TopAllocateAndReferenceNetBufferAndNetBufferListNoMdl
                    (param_1,param_1,param_3,(int)param_3);
  *param_9 = lVar1;
  if (lVar1 != 0) {
    lVar1 = *(longlong *)(lVar1 + 8);
    lVar2 = *(longlong *)(lVar1 + 8);
    if ((*(byte *)(lVar2 + 10) & 5) == 0) {
      lVar2 = MmMapLockedPagesSpecifyCache(lVar2,0,1,0,0,0x40000000);
    }
    else {
      lVar2 = *(longlong *)(lVar2 + 0x18);
    }
    if (lVar2 == 0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      puVar4 = (undefined4 *)((ulonglong)*(uint *)(lVar1 + 0x10) + lVar2);
    }
    *puVar4 = *param_5;
    *(undefined2 *)(puVar4 + 1) = *(undefined2 *)(param_5 + 1);
    *(undefined4 *)((longlong)puVar4 + 6) = *param_6;
    *(undefined2 *)((longlong)puVar4 + 10) = *(undefined2 *)(param_6 + 1);
    pcVar3 = (char *)((longlong)puVar4 + 0xe);
    if (param_4 < '\0') {
      *(undefined2 *)(puVar4 + 3) = 0x81;
      *pcVar3 = param_4 << 5;
      pcVar3 = (char *)((longlong)puVar4 + 0x12);
      *(undefined1 *)((longlong)puVar4 + 0xf) = 0;
      *(undefined2 *)(puVar4 + 4) = 0xd988;
    }
    else {
      *(undefined2 *)(puVar4 + 3) = 0xd988;
    }
    pcVar3[0] = '\x01';
    pcVar3[1] = '\x02';
    pcVar3[2] = '\0';
    pcVar3[3] = param_8;
    *(undefined4 *)(pcVar3 + 4) = *param_7;
    *(undefined2 *)(pcVar3 + 8) = *(undefined2 *)(param_7 + 1);
    *(undefined4 *)(pcVar3 + 10) = *param_6;
    *(undefined2 *)(pcVar3 + 0xe) = *(undefined2 *)(param_6 + 1);
    *(uint *)(*param_9 + 0x88) = *(uint *)(*param_9 + 0x88) | 0x20000000;
  }
  return;
}



===== QospCleanupHandler @ 1400097f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 QospCleanupHandler(undefined8 **param_1,longlong param_2,undefined8 ***param_3)

{
  undefined8 **ppuVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined1 uVar4;
  longlong lVar5;
  undefined8 uVar6;
  undefined8 ****ppppuVar7;
  undefined8 ****local_res18 [2];
  
  puVar3 = param_1[2];
  local_res18[0] = (undefined8 ****)0x0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0))
  {
    param_3 = (undefined8 ***)&WPP_1564c523e1063e4f7fac143b272659d2_Traceguids;
    WPP_SF_qqD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
               &WPP_1564c523e1063e4f7fac143b272659d2_Traceguids,
               *(undefined8 *)(*(longlong *)(param_2 + 0xb8) + 0x30),(char)param_1,
               (char)*(undefined4 *)(param_1 + 4));
  }
  uVar4 = KeAcquireSpinLockRaiseToDpc(puVar3 + 3);
  if ((*(uint *)((longlong)puVar3 + 0x34) & 1) == 0) {
    LOCK();
    *(int *)(puVar3 + 0x28) = *(int *)(puVar3 + 0x28) + 1;
    UNLOCK();
    KeReleaseSpinLockFromDpcLevel(puVar3 + 3);
    ppppuVar7 = local_res18;
    param_3 = (undefined8 ***)0x20;
    lVar5 = QospAllocateAndInitializePacket
                      (puVar3[0x10],ppppuVar7,0x20,'\0',(undefined4 *)((longlong)param_1 + 0x3c),
                       (undefined4 *)((longlong)puVar3 + 0x124),
                       (undefined4 *)((longlong)param_1 + 0x3c),'\x05',(longlong *)ppppuVar7);
    if (lVar5 == 0) {
      KeLowerIrql(uVar4);
      LOCK();
      *(int *)(puVar3 + 0x28) = *(int *)(puVar3 + 0x28) + -1;
      UNLOCK();
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
        param_3 = (undefined8 ***)&WPP_1564c523e1063e4f7fac143b272659d2_Traceguids;
        ppppuVar7 = (undefined8 ****)0x17;
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
                &WPP_1564c523e1063e4f7fac143b272659d2_Traceguids);
      }
    }
    else {
      param_3 = (undefined8 ***)0x10000;
      uVar6 = QosautopInitializeIrpAndSendAtDpcLevel
                        ((longlong)param_1,param_2,0x10000,QosautopCleanupIrpCompletionHandler,
                         QosautopCleanupReceiveHandler,1,local_res18[0],(longlong)local_res18[0]);
      LOCK();
      *(int *)(puVar3 + 0x28) = *(int *)(puVar3 + 0x28) + -1;
      UNLOCK();
      if (-1 < (int)uVar6) {
        KeLowerIrql(uVar4);
        return 0x103;
      }
      LOCK();
      ppppuVar7 = local_res18[0] + 8;
      iVar2 = *(int *)ppppuVar7;
      *(int *)ppppuVar7 = *(int *)ppppuVar7 + -1;
      UNLOCK();
      ppppuVar7 = local_res18[0];
      if (iVar2 == 1) {
        param_3 = local_res18[0][0xb];
        ppppuVar7 = (undefined8 ****)local_res18[0][10];
        (*(code *)local_res18[0][9])(local_res18[0],ppppuVar7,param_3,1);
      }
      KeLowerIrql(uVar4);
    }
  }
  else {
    ppppuVar7 = (undefined8 ****)
                (ulonglong)CONCAT31((int3)(*(uint *)((longlong)puVar3 + 0x34) >> 8),uVar4);
    KeReleaseSpinLock();
  }
  puVar3 = param_1[2];
  uVar4 = KeAcquireSpinLockRaiseToDpc(param_1 + 3);
  KeAcquireSpinLockAtDpcLevel(puVar3 + 0x32);
  LOCK();
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  UNLOCK();
  QosDeleteSession((int *)param_1);
  KeReleaseSpinLockFromDpcLevel(puVar3 + 0x32);
  KeReleaseSpinLockFromDpcLevel(param_1 + 3);
  QospShutdownSessionAtDpcLevel(param_1);
  KeLowerIrql(uVar4);
  LOCK();
  ppuVar1 = param_1 + 4;
  iVar2 = *(int *)ppuVar1;
  *(int *)ppuVar1 = *(int *)ppuVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    QosCleanupSession((longlong)param_1,ppppuVar7,param_3);
  }
  return 0;
}



===== QospCloseHandler @ 140009a90 =====

undefined8 QospCloseHandler(longlong param_1,longlong param_2,undefined *param_3)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  
  lVar3 = *(longlong *)(param_2 + 0xb8);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0))
  {
    param_3 = &WPP_1564c523e1063e4f7fac143b272659d2_Traceguids;
    param_2 = 0x18;
    WPP_SF_qqD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
               &WPP_1564c523e1063e4f7fac143b272659d2_Traceguids,*(undefined8 *)(lVar3 + 0x30),
               (char)param_1,(char)*(undefined4 *)(param_1 + 0x20));
  }
  LOCK();
  piVar1 = (int *)(param_1 + 0x20);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    QosCleanupSession(param_1,param_2,param_3);
  }
  *(undefined8 *)(*(longlong *)(lVar3 + 0x30) + 0x18) = 0;
  return 0;
}



===== QospCreateQosInitializeSinkFrameAtDpcLevel @ 140009b1c =====

undefined8
QospCreateQosInitializeSinkFrameAtDpcLevel
          (longlong param_1,undefined8 param_2,undefined4 *param_3,undefined1 param_4)

{
  longlong lVar1;
  undefined8 local_res10 [3];
  
  local_res10[0] = 0;
  lVar1 = QospAllocateAndInitializePacket
                    (*(undefined8 *)(param_1 + 0x80),local_res10,0x21,'\0',param_3,
                     (undefined4 *)(param_1 + 0x124),param_3,'\0',local_res10);
  if (lVar1 == 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
              &WPP_1564c523e1063e4f7fac143b272659d2_Traceguids);
    }
    local_res10[0] = 0;
  }
  else {
    *(undefined1 *)(lVar1 + 0x12) = param_4;
  }
  return local_res10[0];
}



===== QospDeviceControlHandler @ 140009bc0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong QospDeviceControlHandler(ulonglong param_1,longlong param_2)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  undefined8 *puVar4;
  undefined1 uVar5;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  longlong lVar9;
  longlong lVar10;
  undefined8 uVar11;
  undefined2 uVar12;
  void *pvVar13;
  undefined8 *puVar14;
  uint uVar15;
  byte bVar16;
  byte bVar17;
  ulonglong uVar18;
  undefined4 *puVar19;
  undefined8 **ppuVar20;
  uint *puVar21;
  int local_res20;
  ulonglong in_stack_ffffffffffffff68;
  uint local_64;
  undefined8 *local_58;
  undefined8 local_50;
  void *local_48;
  
  lVar9 = *(longlong *)(param_2 + 0xb8);
  local_res20 = 0;
  uVar15 = *(uint *)(lVar9 + 0x10);
  uVar8 = *(uint *)(lVar9 + 8);
  local_50 = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  iVar2 = *(int *)(lVar9 + 0x18);
  if (iVar2 == 0x12800a) {
    if (0x52 < uVar15 >> 3) {
      return 0xc000000d;
    }
    if (uVar15 == 0) {
      return 0xc000000d;
    }
    if ((uVar15 & 7) != 0) {
      return 0xc000000d;
    }
    if ((ulonglong)uVar8 < (ulonglong)(uVar15 >> 3) * 0x18) {
      return 0xc000000d;
    }
    bVar17 = 0;
  }
  else {
    if (iVar2 != 0x12800e) {
      if (iVar2 == 0x124014) {
        if (uVar15 != 0) {
          return 0xc000000d;
        }
        if (uVar8 < 0x20) {
          return 0xc000000d;
        }
        lVar9 = *(longlong *)(param_2 + 0x18);
        uVar18 = TopOidRequestSynchronousSafe
                           (*(longlong *)(param_1 + 0x10),0,0x10107,lVar9 + 8,
                            (int)in_stack_ffffffffffffff68);
        if ((int)uVar18 < 0) {
          return uVar18;
        }
        *(undefined4 *)(lVar9 + 0x18) = *(undefined4 *)(param_1 + 0x44);
        KeQueryPerformanceCounter(lVar9);
        *(undefined8 *)(lVar9 + 0x10) = *(undefined8 *)(param_1 + 0x48);
        *(undefined8 *)(param_2 + 0x38) = 0x20;
        return 0;
      }
      if (iVar2 != 0x124022) {
        return 0xc0000010;
      }
      if (uVar15 != 0) {
        return 0xc000000d;
      }
      if (uVar8 != 0) {
        return 0xc000000d;
      }
      uVar18 = TopRegisterUnbindNotification(*(longlong *)(param_1 + 0x10),param_2,param_1);
      if ((int)uVar18 < 0) {
        return uVar18 & 0xffffffff;
      }
      return 0x103;
    }
    if (uVar8 < 0x28) {
      return 0xc000000d;
    }
    if (uVar15 != 8) {
      return 0xc000000d;
    }
    bVar17 = 1;
  }
  lVar9 = *(longlong *)(param_2 + 8);
  if ((lVar9 == 0) || (*(uint *)(lVar9 + 0x28) < uVar8)) {
    return 0xc000000d;
  }
  if ((*(byte *)(lVar9 + 10) & 5) == 0) {
    lVar9 = MmMapLockedPagesSpecifyCache
                      (lVar9,0,1,0,in_stack_ffffffffffffff68 & 0xffffffff00000000,0x40000010);
  }
  else {
    lVar9 = *(longlong *)(lVar9 + 0x18);
  }
  if (lVar9 == 0) {
    return 0xc000000d;
  }
  lVar9 = *(longlong *)(param_1 + 0x10);
  ppuVar20 = &local_58;
  local_58 = (undefined8 *)0x0;
  lVar10 = *(longlong *)(param_2 + 0x18);
  if ((*(uint *)(lVar9 + 0x34) & 0x40) == 0) {
    if ((char)*(uint *)(lVar9 + 0x34) < '\0') {
      uVar8 = topActivePolicyFlags & 8;
      goto LAB_140009cde;
    }
    if ((topActivePolicyFlags & 4) == 0) goto LAB_140009d3e;
    uVar8 = 0xeaaa8000;
  }
  else {
    uVar8 = topActivePolicyFlags & 2;
LAB_140009cde:
    if (uVar8 == 0) {
LAB_140009d3e:
      uVar5 = KeAcquireSpinLockRaiseToDpc(lVar9 + 0x18);
      pvVar13 = (void *)(ulonglong)CONCAT31((int3)(*(uint *)(lVar9 + 0x34) >> 8),uVar5);
      if ((*(uint *)(lVar9 + 0x34) & 1) != 0) {
        KeReleaseSpinLock();
        return 0xc00002fe;
      }
      LOCK();
      *(int *)(lVar9 + 0x140) = *(int *)(lVar9 + 0x140) + 1;
      UNLOCK();
      KeReleaseSpinLock(lVar9 + 0x18);
      NdisGetSystemUpTimeEx(&local_50);
      uVar8 = *(uint *)(lVar9 + 0x34);
      local_48 = (void *)0x0;
      local_64 = 0;
      puVar21 = (uint *)(lVar10 + 4);
      for (; puVar14 = local_58, 7 < uVar15; uVar15 = uVar15 - 8) {
        uVar6 = *puVar21 + 3 & 0xfffffffc;
        bVar16 = -((uVar8 & 0x10) != 0) & *(byte *)((longlong)puVar21 + -3);
        if (0x5af < *puVar21) {
          uVar8 = 0xc000000d;
          goto joined_r0x000140009f76;
        }
        uVar3 = uVar6 + 0x3f;
        if (-1 < (char)bVar16) {
          uVar3 = uVar6 + 0x3b;
        }
        lVar10 = QospAllocateAndInitializePacket
                           (*(undefined8 *)(lVar9 + 0x80),(ulonglong)(uVar6 + 0x3b),(ulonglong)uVar3
                            ,bVar16,(undefined4 *)(param_1 + 0x3c),(undefined4 *)(lVar9 + 0x124),
                            (undefined4 *)(param_1 + 0x3c),'\x02',(longlong *)ppuVar20);
        if (lVar10 == 0) {
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((byte)WPP_GLOBAL_Control[0x29] < 2)) ||
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) goto LAB_14000a032;
          uVar12 = 0x1b;
          goto LAB_14000a022;
        }
        pvVar13 = (void *)(*ppuVar20)[1];
        *(uint *)((longlong)pvVar13 + 0x18) = (uVar3 - uVar6) + *puVar21;
        *(undefined8 *)(lVar10 + 0x1a) = 0;
        *(undefined8 *)(lVar10 + 0x22) = 0;
        *(byte *)(lVar10 + 0x2a) = bVar17;
        *(char *)(lVar10 + 0x2b) = (char)puVar21[-1];
        *(undefined1 *)(lVar10 + 0x2c) = *(undefined1 *)((longlong)puVar21 + -2);
        uVar3 = *puVar21;
        if (uVar3 != 0) {
          if (*(char *)((longlong)puVar21 + -1) == '\0') {
            pvVar13 = (void *)0x0;
            memset((void *)(lVar10 + 0x2d),0,(ulonglong)uVar3);
          }
          else {
            uVar18 = 0;
            pvVar13 = local_48;
            if (local_48 != (void *)0x0) {
              if (local_64 <= uVar3) {
                uVar3 = local_64;
              }
              uVar18 = (ulonglong)uVar3;
              memmove((void *)(lVar10 + 0x2d),local_48,uVar18);
            }
            if ((uint)uVar18 < *puVar21) {
              for (puVar19 = (undefined4 *)(uVar18 + 0x2d + lVar10);
                  puVar19 < (undefined4 *)((ulonglong)uVar6 + 0x2d + lVar10); puVar19 = puVar19 + 1)
              {
                uVar7 = RtlRandomEx(&local_50);
                *puVar19 = uVar7;
              }
              local_48 = (void *)(lVar10 + 0x2d);
              local_64 = uVar6;
            }
          }
        }
        ppuVar20 = (undefined8 **)*ppuVar20;
        puVar21 = puVar21 + 2;
        local_res20 = local_res20 + 1;
      }
      uVar8 = 0;
      if (uVar15 == 0) {
        if (bVar17 == 0) {
          lVar10 = QospAllocateAndInitializePacket
                             (*(undefined8 *)(lVar9 + 0x80),pvVar13,0x20,'\0',
                              (undefined4 *)(param_1 + 0x3c),(undefined4 *)(lVar9 + 0x124),
                              (undefined4 *)(param_1 + 0x3c),'\x03',(longlong *)ppuVar20);
          if (lVar10 == 0) {
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
              uVar12 = 0x1c;
LAB_14000a022:
              WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar12,
                      &WPP_1564c523e1063e4f7fac143b272659d2_Traceguids);
            }
LAB_14000a032:
            uVar8 = 0xc000009a;
            puVar14 = local_58;
            goto joined_r0x000140009f76;
          }
          local_res20 = local_res20 + 1;
        }
        uVar5 = KfRaiseIrql(2);
        if (bVar17 == 0) {
          puVar14 = *ppuVar20;
        }
        else {
          puVar14 = (undefined8 *)0x0;
        }
        uVar11 = QosautopInitializeIrpAndSendAtDpcLevel
                           (param_1,param_2,0,0,
                            (&PTR_QosautopTimedProbeReceiveHandler_14000d120)[bVar17],local_res20,
                            local_58,(longlong)puVar14);
        uVar8 = (uint)uVar11;
        KeLowerIrql(uVar5);
        puVar14 = local_58;
        if (-1 < (int)uVar8) {
          LOCK();
          *(int *)(lVar9 + 0x140) = *(int *)(lVar9 + 0x140) + -1;
          UNLOCK();
          return 0x103;
        }
      }
joined_r0x000140009f76:
      while (puVar4 = puVar14, puVar4 != (undefined8 *)0x0) {
        puVar14 = (undefined8 *)*puVar4;
        *puVar4 = 0;
        LOCK();
        piVar1 = (int *)(puVar4 + 8);
        iVar2 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar2 == 1) {
          (*(code *)puVar4[9])(puVar4,puVar4[10],puVar4[0xb],0);
        }
      }
      LOCK();
      *(int *)(lVar9 + 0x140) = *(int *)(lVar9 + 0x140) + -1;
      UNLOCK();
      goto LAB_140009d37;
    }
    uVar8 = 0xc0000364;
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (1 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0))
  {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
             &WPP_1564c523e1063e4f7fac143b272659d2_Traceguids,uVar8);
  }
LAB_140009d37:
  return (ulonglong)uVar8;
}



===== QospShutdownSessionAtDpcLevel @ 14000a180 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void QospShutdownSessionAtDpcLevel(undefined8 **param_1)

{
  undefined8 **ppuVar1;
  int *piVar2;
  int iVar3;
  undefined8 **ppuVar4;
  undefined8 *puVar5;
  code *pcVar6;
  undefined8 **ppuVar7;
  uint uVar8;
  undefined8 **ppuVar9;
  undefined8 **ppuVar10;
  
  ppuVar7 = (undefined8 **)0x0;
  ppuVar10 = param_1;
  TopUnregisterUnbindNotification((longlong)param_1[2],(undefined8 ***)0x0,param_1,0xc0000120);
  ppuVar1 = param_1 + 3;
  KeAcquireSpinLockAtDpcLevel(ppuVar1);
  while (ppuVar4 = (undefined8 **)param_1[10], ppuVar4 != param_1 + 10) {
    puVar5 = ppuVar4[-6];
    ppuVar9 = ppuVar4 + -0x15;
    QosautopDetachIrpUnderLockAndReleaseFromDpcLevel((longlong)puVar5,ppuVar7,ppuVar10);
    pcVar6 = (code *)puVar5[5];
    uVar8 = 0xc0000120;
    if (pcVar6 != (code *)0x0) {
      uVar8 = -(uint)(pcVar6 != QosautopCleanupIrpCompletionHandler) & 0xc0000120;
      ppuVar10 = (undefined8 **)(ulonglong)uVar8;
      ppuVar7 = ppuVar9;
      (*pcVar6)(puVar5,ppuVar9,ppuVar10,0);
    }
    ppuVar4[-0xe] = (undefined8 *)0x0;
    ppuVar7 = (undefined8 **)CONCAT71((int7)((ulonglong)ppuVar7 >> 8),2);
    *(uint *)(ppuVar4 + -0xf) = uVar8;
    IofCompleteRequest(ppuVar9);
    LOCK();
    piVar2 = (int *)(puVar5 + 1);
    iVar3 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar3 == 1) {
      ppuVar7 = (undefined8 **)CONCAT71((int7)((ulonglong)ppuVar7 >> 8),1);
      QosautopCleanupIrpContext((longlong)puVar5,'\x01',ppuVar10);
    }
    KeAcquireSpinLockAtDpcLevel(ppuVar1);
  }
  KeReleaseSpinLockFromDpcLevel(ppuVar1);
  return;
}



===== WPP_SF__MAC_ @ 14000a298 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF__MAC_(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4)

{
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_1564c523e1063e4f7fac143b272659d2_Traceguids,param_2,param_4,6,0);
  return;
}



===== TopQueueOidRequestAsynchronousAtDpcLevel @ 14000a2d8 =====

undefined8
TopQueueOidRequestAsynchronousAtDpcLevel
          (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
          undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8)

{
  void *_Dst;
  undefined8 uVar1;
  
  _Dst = (void *)ExAllocatePool2(0x40,0x120,0x71526f49);
  if (_Dst == (void *)0x0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
              &WPP_006e561b8dd438e832959c88679fc92c_Traceguids);
    }
    uVar1 = 0xc000009a;
  }
  else {
    memset(_Dst,0,0x120);
    *(undefined8 *)((longlong)_Dst + 0x108) = param_6;
    *(undefined8 *)((longlong)_Dst + 0x110) = param_7;
    *(undefined8 *)((longlong)_Dst + 0x118) = param_8;
    *(undefined4 *)((longlong)_Dst + 8) = 0xf80196;
    *(undefined4 *)((longlong)_Dst + 0xc) = 1;
    *(undefined4 *)((longlong)_Dst + 0x28) = 0x1010e;
    *(undefined8 *)((longlong)_Dst + 0x30) = param_4;
    *(undefined4 *)((longlong)_Dst + 0x38) = 4;
    KeAcquireSpinLockAtDpcLevel(param_1);
    LOCK();
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    UNLOCK();
    if (*(int *)(param_1 + 0x28) == 0) {
      if (*(longlong *)(param_1 + 0x70) == 0) {
        *(void **)(param_1 + 0x78) = _Dst;
        *(void **)(param_1 + 0x70) = _Dst;
        KeInsertQueueDpc(param_1 + 0x30,0,0);
      }
      else {
        *(void **)(*(longlong *)(param_1 + 0x78) + 0x100) = _Dst;
        *(void **)(param_1 + 0x78) = _Dst;
      }
      KeReleaseSpinLockFromDpcLevel(param_1);
      uVar1 = 0;
    }
    else {
      KeReleaseSpinLockFromDpcLevel(param_1);
      ToppCleanupRequestAtDpcLevel(param_1,_Dst);
      uVar1 = 0xc00002fe;
    }
  }
  return uVar1;
}



===== ToppRequestDpc @ 14000a440 =====

void ToppRequestDpc(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  int iVar2;
  
  lVar1 = *(longlong *)(param_2 + 0x70);
  KeAcquireSpinLockAtDpcLevel(param_2);
  if ((*(int *)(param_2 + 0x28) == 0) && (*(char *)(lVar1 + 1) == '\0')) {
    KeReleaseSpinLockFromDpcLevel(param_2);
    iVar2 = NdisOidRequest(*(undefined8 *)(param_2 + -0x20),lVar1 + 8);
    if (iVar2 == 0x103) {
      return;
    }
  }
  else {
    KeReleaseSpinLockFromDpcLevel(param_2);
    iVar2 = -0x3ffefff4;
  }
  ToppRequestCompletePrivateHandlerAtDpcLevel(param_2,lVar1,iVar2);
  return;
}



===== TopRtlCopyMdlToBuffer @ 14000a4d0 =====

void TopRtlCopyMdlToBuffer
               (undefined8 *param_1,ulonglong param_2,void *param_3,ulonglong param_4,
               longlong *param_5)

{
  undefined1 uVar1;
  ulonglong uVar2;
  longlong lVar3;
  ulonglong uVar4;
  ulonglong _Size;
  
  *param_5 = 0;
  for (; (param_1 != (undefined8 *)0x0 && (*(uint *)(param_1 + 5) <= param_2));
      param_1 = (undefined8 *)*param_1) {
    param_2 = param_2 - *(uint *)(param_1 + 5);
  }
  uVar4 = param_4;
  while ((param_1 != (undefined8 *)0x0 && (uVar4 != 0))) {
    if ((ulonglong)*(uint *)(param_1 + 5) != 0) {
      uVar2 = *(uint *)(param_1 + 5) - param_2;
      _Size = uVar4;
      if (uVar2 <= uVar4) {
        _Size = uVar2;
      }
      if ((*(byte *)((longlong)param_1 + 10) & 5) == 0) {
        lVar3 = MmMapLockedPagesSpecifyCache(param_1,0,1,0,0,0x40000000);
      }
      else {
        lVar3 = param_1[3];
      }
      if (lVar3 == 0) {
        uVar1 = KfRaiseIrql(2);
        TopRtlCopyMdlToBufferWithReservedMappingAtDpcLevel((longlong)param_1,param_2,param_3,_Size);
        KeLowerIrql(uVar1);
      }
      else {
        memmove(param_3,(void *)(lVar3 + param_2),_Size);
      }
      param_2 = 0;
      param_3 = (void *)((longlong)param_3 + _Size);
      uVar4 = uVar4 - _Size;
    }
    param_1 = (undefined8 *)*param_1;
  }
  *param_5 = param_4 - uVar4;
  return;
}



===== TopRtlCopyMdlToBufferWithReservedMappingAtDpcLevel @ 14000a5fc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void TopRtlCopyMdlToBufferWithReservedMappingAtDpcLevel
               (longlong param_1,ulonglong param_2,void *param_3,longlong param_4)

{
  uint uVar1;
  ulonglong uVar2;
  void *_Src;
  ulonglong uVar3;
  ulonglong uVar4;
  undefined1 auStack_98 [32];
  undefined8 local_78;
  uint local_70;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_98;
  local_70 = 0x38;
  local_50 = 0x1000;
  local_78 = 0;
  local_58 = 0;
  KeAcquireSpinLockAtDpcLevel(&DAT_14000f440);
  uVar3 = param_4 + param_2;
  while (param_2 < uVar3) {
    uVar1 = *(uint *)(param_1 + 0x2c);
    uVar2 = ((ulonglong)(uVar1 + 0x1000 + (int)param_2) & 0xfffff000) - (ulonglong)uVar1;
    uVar4 = uVar3;
    if (uVar2 <= uVar3) {
      uVar4 = uVar2;
    }
    IoBuildPartialMdl(param_1,&local_78,uVar1 + param_2 + *(longlong *)(param_1 + 0x20),
                      (int)uVar4 - (int)param_2);
    _Src = (void *)MmMapLockedPagesWithReservedMapping(DAT_14000f5f0,0x74506142,&local_78,1);
    memmove(param_3,_Src,uVar4 - param_2);
    MmUnmapReservedMapping(DAT_14000f5f0,0x74506142,&local_78);
    if ((local_70 & 0x200000) != 0) {
      MmUnmapLockedPages(local_60,&local_78);
    }
    param_3 = (void *)((longlong)param_3 + (uVar4 - param_2));
    param_2 = uVar4;
  }
  KeReleaseSpinLockFromDpcLevel(&DAT_14000f440);
  return;
}



===== TopAllocateAndReferenceNetBufferAndNetBufferList @ 14000a754 =====

longlong TopAllocateAndReferenceNetBufferAndNetBufferList
                   (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                   undefined8 param_5,undefined4 param_6)

{
  longlong lVar1;
  undefined8 *puVar2;
  
  lVar1 = NdisAllocateNetBufferAndNetBufferList
                    (topNetBufferAndNetBufferListPool,0,0,param_4,0,param_6);
  if (lVar1 != 0) {
    puVar2 = *(undefined8 **)(lVar1 + 8);
    *(undefined4 *)(lVar1 + 0x40) = 1;
    *(code **)(lVar1 + 0x48) = TopDefaultNetBufferListCompletionRoutine;
    *(undefined8 *)(lVar1 + 0x50) = param_2;
    *(undefined8 *)(lVar1 + 0x58) = param_3;
    *(uint *)(lVar1 + 0x88) = *(uint *)(lVar1 + 0x88) & 0xffffc;
    for (; puVar2 != (undefined8 *)0x0; puVar2 = (undefined8 *)*puVar2) {
      *(undefined4 *)(puVar2 + 10) = *(undefined4 *)(puVar2 + 5);
      *(undefined4 *)((longlong)puVar2 + 0x54) = *(undefined4 *)(puVar2 + 3);
    }
    *(uint *)(lVar1 + 0x88) = *(uint *)(lVar1 + 0x88) | 0x4000000;
  }
  return lVar1;
}



===== TopAllocateAndReferenceNetBufferAndNetBufferListNoMdl @ 14000a7f0 =====

longlong TopAllocateAndReferenceNetBufferAndNetBufferListNoMdl
                   (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  int iVar1;
  longlong lVar2;
  undefined8 *puVar3;
  
  lVar2 = NdisAllocateNetBufferAndNetBufferList(topNetBufferAndNetBufferListPool,0,0,0,0,0);
  if (lVar2 != 0) {
    iVar1 = NdisRetreatNetBufferDataStart(*(undefined8 *)(lVar2 + 8),param_4,0,0);
    if (-1 < iVar1) {
      *(undefined8 *)(lVar2 + 0x58) = 0;
      puVar3 = *(undefined8 **)(lVar2 + 8);
      *(code **)(lVar2 + 0x48) = TopDefaultNetBufferListCompletionRoutine;
      *(undefined4 *)(lVar2 + 0x40) = 1;
      *(undefined8 *)(lVar2 + 0x50) = param_2;
      *(uint *)(lVar2 + 0x88) = *(uint *)(lVar2 + 0x88) & 0xffffc;
      for (; puVar3 != (undefined8 *)0x0; puVar3 = (undefined8 *)*puVar3) {
        *(undefined4 *)(puVar3 + 10) = *(undefined4 *)(puVar3 + 5);
        *(undefined4 *)((longlong)puVar3 + 0x54) = *(undefined4 *)(puVar3 + 3);
      }
      *(uint *)(lVar2 + 0x88) = *(uint *)(lVar2 + 0x88) | 0xc000000;
      return lVar2;
    }
    NdisFreeNetBufferList(lVar2);
  }
  return 0;
}



===== TopDefaultNetBufferListCompletionRoutine @ 14000a8d0 =====

void TopDefaultNetBufferListCompletionRoutine
               (longlong param_1,undefined8 param_2,undefined8 param_3,char param_4)

{
  uint uVar1;
  
  TopRestoreNetBufferList(param_1);
  uVar1 = *(uint *)(param_1 + 0x88);
  if ((uVar1 >> 0x1a & 1) == 0) {
    if ((uVar1 >> 0x18 & 1) != 0) {
      NdisReturnNetBufferLists(param_2,param_1,param_4 != '\0');
    }
  }
  else {
    if ((uVar1 >> 0x1b & 1) != 0) {
      NdisAdvanceNetBufferDataStart
                (*(longlong *)(param_1 + 8),*(undefined4 *)(*(longlong *)(param_1 + 8) + 0x18),1,0);
    }
    NdisFreeNetBufferList(param_1);
  }
  return;
}



===== TopRestoreNetBufferList @ 14000a964 =====

void TopRestoreNetBufferList(longlong param_1)

{
  uint uVar1;
  longlong lVar2;
  undefined8 *puVar3;
  
  for (puVar3 = *(undefined8 **)(param_1 + 8); puVar3 != (undefined8 *)0x0;
      puVar3 = (undefined8 *)*puVar3) {
    uVar1 = *(uint *)(puVar3 + 10);
    *(undefined4 *)(puVar3 + 3) = *(undefined4 *)((longlong)puVar3 + 0x54);
    lVar2 = puVar3[4];
    *(uint *)(puVar3 + 5) = uVar1;
    puVar3[1] = lVar2;
    *(uint *)(puVar3 + 2) = uVar1;
    if ((lVar2 != 0) && (*(uint *)(lVar2 + 0x28) < uVar1)) {
      NdisAdjustNetBufferCurrentMdl(puVar3);
    }
  }
  return;
}



===== ToppDelayedPolicyChangeKeyNotifyTimerCallback @ 14000a9c0 =====

/* WARNING: Removing unreachable block (ram,0x00014000a9f4) */

ulonglong ToppDelayedPolicyChangeKeyNotifyTimerCallback(void)

{
  longlong lVar1;
  ulonglong uVar2;
  uint uVar3;
  
  lVar1 = IoAllocateWorkItem(topDeviceObject);
  if (lVar1 == 0) {
    uVar3 = (DAT_14000f540 & 0xfffffffe) - 2 | DAT_14000f540 & 1;
    LOCK();
    uVar2 = (ulonglong)DAT_14000f540;
    UNLOCK();
    DAT_14000f540 = uVar3;
    if (uVar3 == 0) {
      uVar2 = KeSetEvent(DAT_14000f548,0,0);
    }
  }
  else {
    uVar2 = IoQueueWorkItemEx(lVar1,ToppDelayedPolicyChangeKeyNotifyWorker,1);
  }
  return uVar2;
}



===== RtlStringCopyWorkerW @ 14000aa48 =====

uint RtlStringCopyWorkerW(short *param_1,longlong param_2,undefined8 param_3,longlong param_4)

{
  short sVar1;
  longlong lVar2;
  short *psVar3;
  longlong lVar4;
  
  if (param_2 != 0) {
    lVar2 = 0x7ffffffe;
    lVar4 = param_4 - (longlong)param_1;
    do {
      if ((lVar2 == 0) || (sVar1 = *(short *)(lVar4 + (longlong)param_1), sVar1 == 0)) break;
      *param_1 = sVar1;
      lVar2 = lVar2 + -1;
      param_1 = param_1 + 1;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  psVar3 = param_1 + -1;
  if (param_2 != 0) {
    psVar3 = param_1;
  }
  *psVar3 = 0;
  return ~-(uint)(param_2 != 0) & 0x80000005;
}



===== RtlStringLengthWorkerW @ 14000aaa4 =====

uint RtlStringLengthWorkerW(short *param_1,undefined8 param_2,longlong *param_3)

{
  uint uVar1;
  longlong lVar2;
  
  lVar2 = 0x2f;
  do {
    if (*param_1 == 0) break;
    param_1 = param_1 + 1;
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  uVar1 = ~-(uint)(lVar2 != 0) & 0xc000000d;
  if (param_3 != (longlong *)0x0) {
    if (lVar2 != 0) {
      *param_3 = 0x2f - lVar2;
      return uVar1;
    }
    *param_3 = 0;
  }
  return uVar1;
}



===== TopShutdownWaitRef @ 14000aaec =====

/* WARNING: Removing unreachable block (ram,0x00014000ab41) */

ulonglong TopShutdownWaitRef(undefined8 param_1,char param_2)

{
  uint uVar1;
  ulonglong uVar2;
  uint uVar3;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  uVar3 = DAT_14000f540;
  uVar1 = DAT_14000f540;
  if (param_2 != '\0') {
    KeInitializeEvent(&local_28,0,0);
    DAT_14000f548 = &local_28;
    uVar3 = (DAT_14000f540 & 0xfffffffe) - 2;
    uVar1 = DAT_14000f540;
  }
  DAT_14000f540 = uVar3 & 0xfffffffe;
  LOCK();
  uVar2 = (ulonglong)uVar1;
  UNLOCK();
  if ((param_2 != '\0') && (DAT_14000f540 != 0)) {
    uVar2 = KeWaitForSingleObject(&local_28,0,0,0,0);
  }
  return uVar2;
}



===== _guard_check_icall @ 14000ab90 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 14000aba8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 14000abcc =====

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



===== __cpu_features_init @ 14000ac40 =====

/* WARNING: Removing unreachable block (ram,0x00014000acaa) */
/* WARNING: Removing unreachable block (ram,0x00014000ac59) */
/* WARNING: Removing unreachable block (ram,0x00014000ac4a) */

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



===== __security_check_cookie @ 14000ad10 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 14000ad50 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 14000ad80 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x00014000ad80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 14000adb0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcmp @ 14000ade0 =====

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
      if ((byte)*(ulonglong *)_Buf1 != *(byte *)((longlong)_Buf1 + lVar3)) goto LAB_14000ae23;
      _Size = _Size - 1;
    }
    if (_Size >> 3 != 0) {
      uVar4 = _Size >> 5;
      if (uVar4 != 0) {
        do {
          uVar2 = *(ulonglong *)_Buf1;
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3)) goto LAB_14000ae94;
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 8);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 8)) {
LAB_14000ae90:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_14000ae94;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x10);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x10)) {
LAB_14000ae8c:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_14000ae90;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x18);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x18)) {
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_14000ae8c;
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
LAB_14000ae94:
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
LAB_14000ae23:
  return (1 - (uint)bVar5) - (uint)(bVar5 != 0);
}



===== memmove @ 14000af00 =====

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



===== memset @ 14000b200 =====

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



===== __memset_repmovs @ 14000b340 =====

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



===== __memset_query @ 14000b3c0 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 14000b440 =====

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



===== __memset_spec_ermsb_repmovsb @ 14000b580 =====

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



===== __memset_spec_plain @ 14000b600 =====

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



===== ToppDelayedPolicyChangeKeyNotifyWorker @ 140013010 =====

/* WARNING: Removing unreachable block (ram,0x000140013045) */

ulonglong ToppDelayedPolicyChangeKeyNotifyWorker
                    (undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  ulonglong uVar1;
  uint uVar2;
  
  ToppEnablePolicySettingsHelper();
  IoFreeWorkItem(param_3);
  uVar2 = (DAT_14000f540 & 0xfffffffe) - 2 | DAT_14000f540 & 1;
  LOCK();
  uVar1 = (ulonglong)DAT_14000f540;
  UNLOCK();
  DAT_14000f540 = uVar2;
  if (uVar2 == 0) {
    uVar1 = KeSetEvent(DAT_14000f548,0,0);
  }
  return uVar1;
}



===== ToppEnablePolicySettingsHelper @ 140013080 =====

/* WARNING: Removing unreachable block (ram,0x00014001312c) */
/* WARNING: Removing unreachable block (ram,0x0001400131af) */

ulonglong ToppEnablePolicySettingsHelper(void)

{
  char cVar1;
  uint uVar2;
  ulonglong uVar3;
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
  
  local_34 = 0;
  local_1c = 0;
  local_48 = 0;
  uStack_40 = 0;
  RtlInitUnicodeString
            (&local_48,
             L"\\Registry\\Machine\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Group Policy\\State\\Machine"
            );
  local_28 = &local_48;
  local_38 = 0x30;
  local_30 = 0;
  local_20 = 0x240;
  local_18 = 0;
  uStack_10 = 0;
  uVar3 = ZwOpenKey(&DAT_14000f608,0x2001f,&local_38);
  if ((int)uVar3 < 0) {
    if ((int)uVar3 != -0x3fffffcc) {
      return uVar3;
    }
LAB_140013112:
    if ((DAT_14000f540 & 1) != 0) {
      DAT_14000f540 = (DAT_14000f540 + 2 ^ DAT_14000f540) & 1 ^ DAT_14000f540 + 2;
      LOCK();
      UNLOCK();
      uVar3 = (ulonglong)DAT_14000f188;
      if (DAT_14000f188 < 600000) {
        DAT_14000f188 = DAT_14000f188 * 2;
      }
      KeSetTimer(&DAT_14000f550,uVar3 * -10000,&DAT_14000f480);
      LOCK();
      if (DAT_14000f540 == 0) {
        DAT_14000f540 = 0;
      }
      UNLOCK();
      if ((DAT_14000f540 & 1) != 0) goto LAB_14001325d;
      cVar1 = KeCancelTimer(&DAT_14000f550);
      if (cVar1 != '\0') {
        DAT_14000f540 = (DAT_14000f540 & 0xfffffffe) - 2 | DAT_14000f540 & 1;
        LOCK();
        UNLOCK();
        if (DAT_14000f540 == 0) {
          KeSetEvent(DAT_14000f548,0,0);
        }
      }
    }
    uVar3 = 0xc00002fe;
  }
  else {
    uVar2 = ZwNotifyChangeKey(DAT_14000f608,DAT_14000f5e0,&DAT_14000f520,1,&DAT_14000f510,4,1,0,0,1)
    ;
    if ((int)uVar2 < 0) {
      ZwClose(DAT_14000f608);
      DAT_14000f608 = 0;
      if (uVar2 != 0xc0000034) {
        DAT_14000f608 = 0;
        return (ulonglong)uVar2;
      }
      goto LAB_140013112;
    }
LAB_14001325d:
    uVar3 = 0;
  }
  return uVar3;
}



===== TopRegReadUlongValue @ 140013280 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong TopRegReadUlongValue(undefined8 param_1,undefined8 param_2,undefined4 *param_3)

{
  uint uVar1;
  ulonglong uVar2;
  undefined1 auStack_98 [32];
  undefined4 local_78;
  undefined4 *local_70;
  undefined4 local_68 [2];
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined1 local_28 [4];
  int local_24;
  undefined4 local_1c;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_98;
  local_50 = 0;
  local_58 = 0x30;
  local_40 = 0x240;
  local_60 = 0;
  local_68[0] = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_48 = param_1;
  uVar2 = ZwOpenKey(&local_60,0x20019,&local_58);
  if (-1 < (int)uVar2) {
    local_70 = local_68;
    local_78 = 0x14;
    uVar1 = ZwQueryValueKey(local_60,param_2,2,local_28);
    uVar2 = (ulonglong)uVar1;
    ZwClose(local_60);
    if (-1 < (int)uVar1) {
      if (local_24 == 4) {
        *param_3 = local_1c;
        uVar2 = 0;
      }
      else {
        uVar2 = 0xc0000001;
      }
    }
  }
  return uVar2;
}



===== WppLoadTracingSupport @ 140013380 =====

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



===== WppInitKm @ 1400134d0 =====

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



===== TopFreeSecurityDescriptor @ 140013564 =====

void TopFreeSecurityDescriptor(undefined8 param_1)

{
  int iVar1;
  undefined1 local_res10 [8];
  undefined1 local_res18 [8];
  undefined8 local_res20;
  
  local_res20 = 0;
  local_res18[0] = 0;
  local_res10[0] = 0;
  iVar1 = RtlGetDaclSecurityDescriptor(param_1,local_res18,&local_res20,local_res10);
  if (-1 < iVar1) {
    ExFreePoolWithTag(local_res20,0x44536f49);
  }
  return;
}



===== TopFreeSid @ 1400135b8 =====

void TopFreeSid(undefined8 param_1)

{
  ExFreePoolWithTag(param_1,0x44536f49);
  return;
}



===== ToppUnloadDriver @ 1400135e0 =====

void ToppUnloadDriver(void)

{
  TopShutdownPolicyChangeNotification();
  TopStopNdisBindingModule();
  TopRtlInvokeStopRoutines();
  if (topDeviceObject != 0) {
    IoDeleteDevice();
  }
  WppCleanupKm();
  wil_UninitializeFeatureStaging();
  return;
}



===== WppCleanupKm @ 140013624 =====

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



===== WppTraceCallback @ 1400136b0 =====

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



===== wil_UninitializeFeatureStaging @ 140013938 =====

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



===== wil_details_BuildFeatureStateCacheFromQueryResults @ 140013990 =====

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
      goto LAB_1400139ed;
    }
    if (param_1 == 0x117) {
      uVar1 = (*(uint *)(param_2 + 4) & 0x80) << 3 | 0x206;
      goto LAB_1400139ed;
    }
  }
  uVar1 = 0x206;
LAB_1400139ed:
  *param_3 = uVar1;
  return;
}



===== wil_details_EvaluateFeatureDependencies @ 1400139f8 =====

void wil_details_EvaluateFeatureDependencies(void)

{
  longlong *plVar1;
  undefined **ppuVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  bool bVar6;
  
  plVar1 = wil_details_FeatureDescriptors_SkipPadding
                     ((longlong *)&Feature_405434683__private_descriptor);
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
  ppuVar2 = &Feature_405434683__private_descriptor;
  while( true ) {
    plVar1 = wil_details_FeatureDescriptors_SkipPadding((longlong *)ppuVar2);
    if (plVar1 == (longlong *)0x0) break;
    wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
              ((uint *)*plVar1,(longlong)plVar1);
    ppuVar2 = (undefined **)(plVar1 + 7);
  }
  return;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 140013ab0 =====

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



===== wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState @ 140013ae8 =====

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
        if (puVar1 == (undefined8 *)0x0) goto LAB_140013b6a;
        if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
           (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
        if ((uVar5 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
          uVar5 = 0;
          goto LAB_140013b6a;
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
LAB_140013b6a:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 140013bc0 =====

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
      ppuVar3 = &Feature_405434683__private_descriptor;
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



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 140013c20 =====

void wil_details_ReevaluateOnFeatureConfigurationChange(void)

{
  wil_details_UpdateFeatureConfiguredStates();
  wil_details_EvaluateFeatureDependencies();
  return;
}



===== wil_details_UpdateFeatureConfiguredStates @ 140013c3c =====

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
  ppuVar3 = &Feature_405434683__private_descriptor;
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



===== TopFindEA @ 140013cf0 =====

uint * TopFindEA(uint *param_1,void *param_2,ushort param_3)

{
  uint uVar1;
  int iVar2;
  
  while( true ) {
    uVar1 = *param_1;
    if ((*(byte *)((longlong)param_1 + 5) == param_3) &&
       (iVar2 = memcmp(param_1 + 2,param_2,(ulonglong)(param_3 + 1)), iVar2 == 0)) break;
    param_1 = (uint *)((longlong)param_1 + (ulonglong)uVar1);
    if (uVar1 == 0) {
      return (uint *)0x0;
    }
  }
  return param_1;
}



===== ToppDispatch @ 140013d70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int ToppDispatch(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  int iVar2;
  
  lVar1 = *(longlong *)(*(longlong *)(*(byte **)(param_2 + 0xb8) + 0x30) + 0x18);
  *(undefined8 *)(param_2 + 0x38) = 0;
  if (lVar1 == 0) {
    iVar2 = -0x3ffffff0;
  }
  else {
    iVar2 = (**(code **)(*(longlong *)(lVar1 + 8) + -0x10 +
                        (ulonglong)**(byte **)(param_2 + 0xb8) * 8))(lVar1,param_2);
    if (iVar2 == 0x103) {
      return 0x103;
    }
  }
  *(int *)(param_2 + 0x30) = iVar2;
  IofCompleteRequest(param_2,0);
  return iVar2;
}



===== ToppDispatchCreate @ 140013df0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int ToppDispatchCreate(undefined8 param_1,longlong param_2)

{
  byte bVar1;
  ushort uVar2;
  longlong lVar3;
  int iVar4;
  uint *puVar5;
  uint *puVar6;
  uint *puVar7;
  wchar_t *_Dst;
  longlong lVar8;
  wchar_t *pwVar9;
  longlong local_res10;
  undefined8 local_res18;
  void *local_res20;
  
  lVar3 = *(longlong *)(param_2 + 0xb8);
  local_res10 = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  local_res18 = 0;
  if ((topActivePolicyFlags & 1) == 0) {
    if ((0xb < *(uint *)(lVar3 + 0x20)) && (*(longlong *)(param_2 + 0x18) != 0)) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((3 < (byte)WPP_GLOBAL_Control[0x29] && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)))
         ) {
        WPP_SF_qqD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                   &WPP_23ef441b8cf036704207f83c1fc48158_Traceguids,param_1,
                   (char)*(undefined8 *)(lVar3 + 0x30),(char)*(uint *)(lVar3 + 0x20));
      }
      *(undefined8 *)(*(longlong *)(lVar3 + 0x30) + 0x18) = 0;
      puVar7 = *(uint **)(param_2 + 0x18);
      puVar5 = TopFindEA(puVar7,"ObjectType",10);
      puVar6 = TopFindEA(puVar7,"BindWait",8);
      puVar7 = TopFindEA(puVar7,"DeviceName",10);
      if ((((puVar5 != (uint *)0x0) && (*(short *)((longlong)puVar5 + 6) == 1)) &&
          (puVar6 != (uint *)0x0)) &&
         ((*(short *)((longlong)puVar6 + 6) == 4 && (puVar7 != (uint *)0x0)))) {
        uVar2 = *(ushort *)((longlong)puVar7 + 6);
        if ((1 < uVar2) && ((uVar2 & 1) == 0)) {
          bVar1 = *(byte *)((ulonglong)*(byte *)((longlong)puVar5 + 5) + 9 + (longlong)puVar5);
          if ((bVar1 < 3) &&
             (local_res20 = (void *)((ulonglong)*(byte *)((longlong)puVar7 + 5) + 9 +
                                    (longlong)puVar7),
             *(short *)(((ulonglong)uVar2 - 2) + (longlong)local_res20) == 0)) {
            local_res10 = (ulonglong)
                          *(uint *)((ulonglong)*(byte *)((longlong)puVar6 + 5) + 9 +
                                   (longlong)puVar6) * -10000;
            iVar4 = KeWaitForSingleObject(&topBindingComplete,0,0,0,&local_res10);
            if (-1 < iVar4) {
              _Dst = (wchar_t *)
                     ExAllocatePool2(0x40,*(undefined2 *)((longlong)puVar7 + 6),0x72436f49);
              if (_Dst == (wchar_t *)0x0) {
                iVar4 = -0x3fffff66;
              }
              else {
                memmove(_Dst,local_res20,(ulonglong)*(ushort *)((longlong)puVar7 + 6));
                lVar8 = param_2;
                pwVar9 = _Dst;
                iVar4 = (*(code *)(&PTR_TopBindDevice_14000d0f0)[bVar1])
                                  (*(undefined8 *)(lVar3 + 0x30),param_2,_Dst,
                                   *(ushort *)((longlong)puVar7 + 6) - 2,
                                   *(undefined8 *)(param_2 + 0x18),&local_res18);
                if (iVar4 == 0x103) {
                  ExFreePoolWithTag(_Dst,0);
                  return 0x103;
                }
                if (iVar4 < 0) {
                  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                      (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
                     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
                    WPP_SF_qqDSDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),lVar8,pwVar9,param_1,
                                  (char)*(undefined8 *)(lVar3 + 0x30),bVar1,_Dst,
                                  (char)*(undefined2 *)((longlong)puVar7 + 6),(char)iVar4);
                  }
                }
                else {
                  *(undefined8 *)(*(longlong *)(lVar3 + 0x30) + 0x18) = local_res18;
                }
                ExFreePoolWithTag(_Dst,0);
              }
            }
            goto LAB_1400140fb;
          }
        }
      }
    }
    iVar4 = -0x3ffffff3;
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (1 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
              &WPP_23ef441b8cf036704207f83c1fc48158_Traceguids);
    }
    iVar4 = -0x3ffffc9c;
  }
LAB_1400140fb:
  *(int *)(param_2 + 0x30) = iVar4;
  IofCompleteRequest(param_2,0);
  return iVar4;
}



===== TopStopNdisBindingModule @ 14001412c =====

void TopStopNdisBindingModule(void)

{
  longlong lVar1;
  
  lVar1 = topNdisProtocolHandle;
  LOCK();
  topNdisProtocolHandle = 0;
  UNLOCK();
  if (lVar1 != 0) {
    NdisDeregisterProtocolDriver();
  }
  return;
}



===== TopStopContextManagementModule @ 140014160 =====

void TopStopContextManagementModule(void)

{
  if (toppNlInterfaceV4NotificationHandle != 0) {
    NsiDeregisterChangeNotification(&NPI_MS_IPV4_MODULEID,7);
    toppNlInterfaceV4NotificationHandle = 0;
  }
  if (toppNlInterfaceV6NotificationHandle != 0) {
    NsiDeregisterChangeNotification(&NPI_MS_IPV6_MODULEID,7);
    toppNlInterfaceV6NotificationHandle = 0;
  }
  ExDeleteNPagedLookasideList(&topSmallDescriptorLookasideList);
  ExDeleteNPagedLookasideList(&topFullDescriptorLookasideList);
  return;
}



===== wil_RtlStagingConfig_QueryFeatureState @ 1400141f0 =====

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



===== QosStopManagementModule @ 1400142c0 =====

void QosStopManagementModule(void)

{
  ExDeleteNPagedLookasideList(&qospIrpContextLookasideList);
  TopFreeSecurityDescriptor(&toppNetworkTestServiceDescriptor);
  return;
}



===== QospInvalidDeviceRequestHandler @ 1400142f0 =====

undefined8 QospInvalidDeviceRequestHandler(void)

{
  return 0xc0000010;
}



===== TopRtlInvokeStopRoutines @ 140014300 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TopRtlInvokeStopRoutines(void)

{
  uint uVar1;
  uint uVar2;
  ulonglong uVar3;
  
  uVar3 = 3;
  uVar1 = DAT_14000f200;
  do {
    if (((&DAT_14000d090)[uVar3 * 6] & uVar1) != 0) {
      (*(code *)(&PTR_TopStopRtlSupportModule_14000d0a0)[uVar3 * 3])();
      DAT_14000f200 = DAT_14000f200 & ~(&DAT_14000d090)[uVar3 * 6];
      uVar1 = DAT_14000f200;
    }
    uVar2 = (int)uVar3 - 1;
    uVar3 = (ulonglong)uVar2;
  } while (-1 < (int)uVar2);
  return;
}



===== TopStopRtlSupportModule @ 140014370 =====

void TopStopRtlSupportModule(void)

{
  if (DAT_14000f5f0 != 0) {
    MmFreeMappingAddress(DAT_14000f5f0,0x74506142);
  }
  return;
}



===== TopStopNetBufferModule @ 1400143a0 =====

void TopStopNetBufferModule(void)

{
  if (topNetBufferAndNetBufferListPool != 0) {
    NdisFreeNetBufferListPool();
    topNetBufferAndNetBufferListPool = 0;
  }
  if (DAT_14000f600 != 0) {
    NdisFreeGenericObject();
    DAT_14000f600 = 0;
  }
  return;
}



===== TopShutdownPolicyChangeNotification @ 1400143f0 =====

/* WARNING: Removing unreachable block (ram,0x000140014479) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void TopShutdownPolicyChangeNotification(void)

{
  undefined8 uVar1;
  char cVar2;
  int iVar3;
  undefined *puVar4;
  undefined8 local_res8;
  undefined8 local_res10 [3];
  
  KeEnterCriticalRegion();
  ExAcquireFastMutexUnsafe(&DAT_14000f448);
  _DAT_14000f590 = 0;
  puVar4 = &DAT_14000f448;
  DAT_14000f4c0 = 0;
  ExReleaseFastMutexUnsafe();
  KeLeaveCriticalRegion();
  TopShutdownWaitRef(puVar4,'\0');
  puVar4 = &DAT_14000f550;
  cVar2 = KeCancelTimer();
  if (cVar2 != '\0') {
    DAT_14000f540 = (DAT_14000f540 & 0xfffffffe) - 2 | DAT_14000f540 & 1;
    puVar4 = (undefined *)(ulonglong)DAT_14000f540;
    LOCK();
    UNLOCK();
    if (DAT_14000f540 == 0) {
      puVar4 = DAT_14000f548;
      KeSetEvent(DAT_14000f548,0,0);
    }
  }
  TopShutdownWaitRef(puVar4,'\x01');
  if (DAT_14000f608 != 0) {
    ZwClose();
    DAT_14000f608 = 0;
  }
  local_res8 = 0;
  iVar3 = ObReferenceObjectByHandle
                    (DAT_14000f5e0,1,*(undefined8 *)ExEventObjectType_exref,0,&local_res8,0);
  uVar1 = local_res8;
  if (-1 < iVar3) {
    local_res10[0] = 0xffffffffffd9da60;
    while (iVar3 = KeReadStateEvent(uVar1), iVar3 != 0) {
      KeDelayExecutionThread(0,0,local_res10);
    }
    ObfDereferenceObject(uVar1);
  }
  ZwClose(DAT_14000f5e0);
  KeFlushQueuedDpcs();
  return;
}



===== TopCleanupBackChannel @ 140014578 =====

void TopCleanupBackChannel(longlong param_1)

{
  ObfDereferenceObject(*(undefined8 *)(param_1 + 0x18));
  ExFreePoolWithTag(param_1,0);
  return;
}



===== TopCreateBackChannel @ 1400145b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint TopCreateBackChannel
               (undefined8 param_1,longlong param_2,undefined8 param_3,undefined8 param_4,
               undefined8 *param_5)

{
  undefined8 *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined4 *puVar6;
  undefined1 auStack_f8 [32];
  undefined4 local_d8;
  undefined4 uStack_d4;
  undefined8 uStack_d0;
  undefined8 *local_c8;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined8 local_b8;
  ulonglong uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  short local_98 [48];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_f8;
  local_b8 = 0;
  uStack_b0 = uStack_b0 & 0xffffffff00000000;
  uVar5 = 0x20;
  local_d8 = 0;
  uStack_d4 = 0;
  uStack_d0 = 0;
  local_c8 = (undefined8 *)0x0;
  uStack_c0 = 0;
  uStack_bc = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  puVar3 = (undefined4 *)ExAllocatePool2(0x40,0x20,0x68436b42);
  if (puVar3 == (undefined4 *)0x0) {
    uVar2 = 0xc000009a;
  }
  else {
    *puVar3 = 1;
    uVar2 = ToppBuildCallbackString(local_98,uVar5,(longlong)L"Rspndr",param_2);
    if (-1 < (int)uVar2) {
      RtlInitUnicodeString(&local_a8,local_98);
      uStack_d0 = 0;
      local_c8 = &local_a8;
      local_d8 = 0x30;
      uStack_c0 = 0x250;
      puVar6 = &local_d8;
      local_b8 = 0;
      uStack_b0 = 0;
      uVar2 = ExCreateCallback(puVar3 + 6,puVar6,1);
      if (-1 < (int)uVar2) {
        uVar2 = ToppBuildCallbackString(local_98,puVar6,(longlong)L"Mapper",param_2);
        if (-1 < (int)uVar2) {
          RtlInitUnicodeString(&local_a8,local_98);
          uStack_d0 = 0;
          local_c8 = &local_a8;
          local_d8 = 0x30;
          uStack_c0 = 0x250;
          puVar1 = (undefined8 *)(puVar3 + 2);
          local_b8 = 0;
          uStack_b0 = 0;
          uVar2 = ExCreateCallback(puVar1,&local_d8,1);
          if (-1 < (int)uVar2) {
            lVar4 = ExRegisterCallback(*puVar1,TopReceiveNetBufferListFromBackChannel,param_4);
            *(longlong *)(puVar3 + 4) = lVar4;
            if (lVar4 != 0) {
              *param_5 = puVar3;
              return 0;
            }
            ObfDereferenceObject(*puVar1);
          }
        }
        ObfDereferenceObject(*(undefined8 *)(puVar3 + 6));
      }
    }
    ExFreePoolWithTag(puVar3,0);
  }
  return uVar2;
}



===== TopDeleteBackChannel @ 1400147ac =====

void TopDeleteBackChannel(int *param_1)

{
  int iVar1;
  
  ExUnregisterCallback(*(undefined8 *)(param_1 + 4));
  ObfDereferenceObject(*(undefined8 *)(param_1 + 2));
  LOCK();
  iVar1 = *param_1;
  *param_1 = *param_1 + -1;
  UNLOCK();
  if (iVar1 == 1) {
    TopCleanupBackChannel((longlong)param_1);
  }
  return;
}



===== ToppBuildCallbackString @ 1400147f8 =====

uint ToppBuildCallbackString(short *param_1,undefined8 param_2,longlong param_3,longlong param_4)

{
  short *psVar1;
  byte bVar2;
  short sVar3;
  uint uVar4;
  undefined8 uVar5;
  longlong lVar6;
  longlong *plVar7;
  short *psVar8;
  longlong local_18;
  longlong local_10;
  
  local_10 = 0;
  uVar5 = 0x2f;
  uVar4 = RtlStringCopyWorkerW(param_1,0x2f,param_3,0x14000d988);
  if (-1 < (int)uVar4) {
    plVar7 = &local_18;
    local_18 = 0;
    uVar4 = RtlStringLengthWorkerW(param_1,uVar5,plVar7);
    if (-1 < (int)uVar4) {
      lVar6 = 0x2f - local_18;
      uVar4 = RtlStringCopyWorkerW(param_1 + local_18,lVar6,plVar7,param_3);
      if (-1 < (int)uVar4) {
        if (param_1 == (short *)0x0) {
          uVar4 = 0xc000000d;
        }
        else {
          uVar4 = RtlStringLengthWorkerW(param_1,lVar6,&local_10);
          if (-1 < (int)uVar4) {
            lVar6 = 0x10;
            if (0x2fU - local_10 < 0x11) {
              uVar4 = 0x80000005;
            }
            else {
              psVar8 = param_1 + local_10;
              do {
                psVar1 = psVar8 + 1;
                bVar2 = (byte)((ulonglong)param_4 >> 0x3c);
                sVar3 = 0x57;
                param_4 = param_4 << 4;
                if (bVar2 < 10) {
                  sVar3 = 0x30;
                }
                *psVar8 = sVar3 + (ushort)bVar2;
                lVar6 = lVar6 + -1;
                psVar8 = psVar1;
              } while (lVar6 != 0);
              *psVar1 = 0;
              uVar4 = 0;
            }
          }
        }
      }
    }
  }
  return uVar4;
}



===== ToppPolicyChangeNotificationCallback @ 140014900 =====

/* WARNING: Removing unreachable block (ram,0x00014001493a) */
/* WARNING: Removing unreachable block (ram,0x0001400149e6) */

ulonglong ToppPolicyChangeNotificationCallback(void)

{
  ulonglong uVar1;
  uint uVar2;
  
  ZwWaitForSingleObject(DAT_14000f5e0,0,0);
  if ((DAT_14000f540 & 1) == 0) {
    uVar1 = ZwResetEvent(DAT_14000f5e0,0);
  }
  else {
    DAT_14000f540 = (DAT_14000f540 + 2 ^ DAT_14000f540) & 1 ^ DAT_14000f540 + 2;
    LOCK();
    UNLOCK();
    ZwResetEvent(DAT_14000f5e0,0);
    ZwNotifyChangeKey(DAT_14000f608,DAT_14000f5e0,&DAT_14000f520,1,&DAT_14000f510,4,1,0,0,1);
    uVar1 = KeSetTimer(&DAT_14000f5a0,0xffffffffff676980,&DAT_14000f4d0);
    if ((char)uVar1 != '\0') {
      uVar2 = (DAT_14000f540 & 0xfffffffe) - 2 | DAT_14000f540 & 1;
      LOCK();
      uVar1 = (ulonglong)DAT_14000f540;
      UNLOCK();
      DAT_14000f540 = uVar2;
      if (uVar2 == 0) {
        uVar1 = KeSetEvent(DAT_14000f548,0,0);
      }
    }
  }
  return uVar1;
}



===== ToppDelayedPolicyResolutionWorker @ 140014a30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x000140014b5d) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong ToppDelayedPolicyResolutionWorker(undefined8 param_1,undefined8 param_2,longlong param_3)

{
  ulonglong uVar1;
  uint uVar2;
  longlong lVar3;
  uint uVar4;
  longlong lVar5;
  uint local_res18 [2];
  
  KeEnterCriticalRegion();
  ExAcquireFastMutexUnsafe(&DAT_14000f448);
  uVar4 = 0;
  if (DAT_14000f4c0 != 0) {
    do {
      local_res18[0] = 0;
      lVar5 = (ulonglong)uVar4 * 0x30 + _DAT_14000f590;
      uVar1 = TopRegReadUlongValue(lVar5,lVar5 + 0x10,local_res18);
      uVar2 = *(uint *)(lVar5 + 0x28);
      if ((int)uVar1 < 0) {
        if ((uVar2 & 1) != 0) {
          if ((uVar2 & 4) == 0) goto LAB_140014af5;
          uVar2 = uVar2 & 0xfffffffb;
        }
        uVar2 = uVar2 | 1;
LAB_140014ade:
        *(uint *)(lVar5 + 0x28) = uVar2;
        lVar3 = lVar5 + 0x2c;
        if ((uVar2 & 4) == 0) {
          lVar3 = 0;
        }
        (**(code **)(lVar5 + 0x20))(lVar3);
      }
      else {
        if ((uVar2 & 2) != 0) {
          local_res18[0] = (uint)(local_res18[0] != 0);
        }
        if (((uVar2 & 4) == 0) || (local_res18[0] != *(uint *)(lVar5 + 0x2c))) {
          *(uint *)(lVar5 + 0x2c) = local_res18[0];
          uVar2 = uVar2 | 5;
          goto LAB_140014ade;
        }
      }
LAB_140014af5:
      uVar4 = uVar4 + 1;
    } while (uVar4 < DAT_14000f4c0);
  }
  ExReleaseFastMutexUnsafe(&DAT_14000f448);
  uVar1 = KeLeaveCriticalRegion();
  if (param_3 != 0) {
    IoFreeWorkItem(param_3);
    uVar4 = (DAT_14000f540 & 0xfffffffe) - 2 | DAT_14000f540 & 1;
    LOCK();
    uVar1 = (ulonglong)DAT_14000f540;
    UNLOCK();
    DAT_14000f540 = uVar4;
    if (uVar4 == 0) {
      uVar1 = KeSetEvent(DAT_14000f548,0,0);
    }
  }
  return uVar1;
}



===== TopRtlInvokeStartRoutines @ 140014b90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int TopRtlInvokeStartRoutines(void)

{
  int iVar1;
  uint uVar2;
  ulonglong uVar3;
  
  uVar3 = 0;
  uVar2 = DAT_14000f200;
  do {
    if (3 < (uint)uVar3) {
      return 0;
    }
    if (((&DAT_14000d090)[uVar3 * 6] & uVar2) == 0) {
      iVar1 = (*(code *)(&PTR_TopStartRtlSupportModule_14000d098)[uVar3 * 3])();
      if (iVar1 < 0) {
        TopRtlInvokeStopRoutines();
        return iVar1;
      }
      DAT_14000f200 = DAT_14000f200 | (&DAT_14000d090)[uVar3 * 6];
      uVar2 = DAT_14000f200;
    }
    uVar3 = (ulonglong)((uint)uVar3 + 1);
  } while( true );
}



===== ToppAdjustSecurityDescriptor @ 140015010 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int ToppAdjustSecurityDescriptor(void)

{
  longlong lVar1;
  int iVar2;
  undefined2 uVar3;
  undefined1 auStackY_f8 [32];
  undefined8 in_stack_ffffffffffffff48;
  undefined8 in_stack_ffffffffffffff50;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined4 local_70;
  undefined2 local_6c;
  undefined4 local_68 [2];
  longlong local_60;
  undefined4 local_58;
  undefined8 local_50;
  undefined4 local_48;
  undefined8 local_40;
  undefined4 local_38;
  undefined8 local_30;
  undefined4 local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_f8;
  local_6c = 0x500;
  local_78 = 0;
  local_70 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_88 = 0;
  uStack_80 = 0;
  lVar1 = *(longlong *)SeExports_exref;
  local_68[0] = 0x10000000;
  local_60 = 0;
  local_58 = 0x10000000;
  local_50 = *(undefined8 *)(lVar1 + 0x110);
  local_40 = *(undefined8 *)(lVar1 + 0x108);
  local_30 = *(undefined8 *)(lVar1 + 0x188);
  local_20 = *(undefined8 *)(lVar1 + 0x180);
  local_48 = 0x10000000;
  local_38 = 0x10000000;
  local_28 = 0x10000000;
  iVar2 = TopAllocateAndInitializeSid
                    (&local_70,2,0x20,0x22c,0,0,0,0,in_stack_ffffffffffffff48,
                     in_stack_ffffffffffffff50,&local_60);
  if (iVar2 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar2;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return iVar2;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
      return iVar2;
    }
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
             &WPP_6a48e31e446332df021f8f71f6b1fa4f_Traceguids,iVar2);
    return iVar2;
  }
  iVar2 = TopCreateSecurityDescriptor(&local_98,(longlong)local_68,5);
  if (iVar2 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((byte)WPP_GLOBAL_Control[0x29] < 2)) || ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0))
    goto LAB_1400151d5;
    uVar3 = 0x1a;
  }
  else {
    iVar2 = ObSetSecurityObjectByPointer(topDeviceObject,4,&local_98);
    TopFreeSecurityDescriptor(&local_98);
    if (-1 < iVar2) {
      iVar2 = 0;
      goto LAB_1400151d5;
    }
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((byte)WPP_GLOBAL_Control[0x29] < 2)) || ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0))
    goto LAB_1400151d5;
    uVar3 = 0x1b;
  }
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar3,
           &WPP_6a48e31e446332df021f8f71f6b1fa4f_Traceguids,iVar2);
LAB_1400151d5:
  TopFreeSid(local_60);
  return iVar2;
}



===== TopAllocateAndInitializeSid @ 140015210 =====

int TopAllocateAndInitializeSid
              (undefined8 param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4,
              undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
              undefined8 param_9,undefined8 param_10,longlong *param_11)

{
  undefined4 uVar1;
  int iVar2;
  longlong lVar3;
  undefined4 *puVar4;
  undefined8 local_28;
  undefined8 local_20;
  
  local_28 = 1;
  local_20 = 0;
  uVar1 = RtlLengthRequiredSid(param_2);
  lVar3 = ExAllocatePool3(0x40,uVar1,0x44536f49,&local_28,1);
  if (lVar3 == 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (1 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
              &WPP_6a48e31e446332df021f8f71f6b1fa4f_Traceguids);
    }
    iVar2 = -0x3fffff66;
  }
  else {
    iVar2 = RtlInitializeSid(lVar3,param_1,param_2);
    if (iVar2 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)
         ) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
                 &WPP_6a48e31e446332df021f8f71f6b1fa4f_Traceguids,iVar2);
      }
      ExFreePoolWithTag(lVar3,0);
    }
    else {
      switch(param_2) {
      case 8:
        puVar4 = (undefined4 *)RtlSubAuthoritySid(lVar3,7);
        *puVar4 = 0;
      case 7:
        puVar4 = (undefined4 *)RtlSubAuthoritySid(lVar3,6);
        *puVar4 = 0;
      case 6:
        puVar4 = (undefined4 *)RtlSubAuthoritySid(lVar3,5);
        *puVar4 = param_8;
      case 5:
        puVar4 = (undefined4 *)RtlSubAuthoritySid(lVar3,4);
        *puVar4 = param_7;
      case 4:
        puVar4 = (undefined4 *)RtlSubAuthoritySid(lVar3,3);
        *puVar4 = param_6;
      case 3:
        puVar4 = (undefined4 *)RtlSubAuthoritySid(lVar3,2);
        *puVar4 = param_5;
      case 2:
        puVar4 = (undefined4 *)RtlSubAuthoritySid(lVar3,1);
        *puVar4 = param_4;
      case 1:
        puVar4 = (undefined4 *)RtlSubAuthoritySid(lVar3,0);
        *puVar4 = param_3;
      default:
        *param_11 = lVar3;
        iVar2 = 0;
      }
    }
  }
  return iVar2;
}



===== entry @ 140015460 =====

void entry(longlong param_1,undefined8 *param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 140015494 =====

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



===== wil_InitializeFeatureStaging @ 1400154c8 =====

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
    ppuVar4 = &Feature_405434683__private_descriptor;
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



===== wil_details_PopulateInitialConfiguredFeatureStates @ 1400155b8 =====

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
  ppuVar3 = &Feature_405434683__private_descriptor;
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



===== TopStartContextManagementModule @ 1400156a0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 TopStartContextManagementModule(void)

{
  int iVar1;
  undefined8 in_stack_ffffffffffffffe0;
  undefined4 uVar2;
  
  uVar2 = (undefined4)((ulonglong)in_stack_ffffffffffffffe0 >> 0x20);
  _DAT_14000f658 = &topContextList;
  topContextList = &topContextList;
  KeInitializeSpinLock(&topContextListLock);
  KeInitializeSpinLock(&topDescriptorLookasideListLock);
  ExInitializeNPagedLookasideList
            (&topSmallDescriptorLookasideList,0,0,0x200,0x52,CONCAT44(uVar2,0x44496f49),0);
  ExInitializeNPagedLookasideList(&topFullDescriptorLookasideList,0,0,0x200,0x60a,0x44496f49,0);
  iVar1 = NsiRegisterChangeNotification
                    (&NPI_MS_IPV4_MODULEID,7,ToppNlInterfaceParameterChangeCallback,0,0,
                     &toppNlInterfaceV4NotificationHandle);
  if (iVar1 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (2 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0))
    {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
               &WPP_b515efb401d631d3025e3a3f22783527_Traceguids,iVar1);
    }
    toppNlInterfaceV4NotificationHandle = 0;
  }
  iVar1 = NsiRegisterChangeNotification
                    (&NPI_MS_IPV6_MODULEID,7,ToppNlInterfaceParameterChangeCallback,0,0,
                     &toppNlInterfaceV6NotificationHandle);
  if (iVar1 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (2 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0))
    {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
               &WPP_b515efb401d631d3025e3a3f22783527_Traceguids,iVar1);
    }
    toppNlInterfaceV6NotificationHandle = 0;
  }
  return 0;
}



===== QosStartManagementModule @ 140015850 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int QosStartManagementModule(void)

{
  int iVar1;
  undefined2 uVar2;
  undefined1 auStackY_88 [32];
  undefined8 in_stack_ffffffffffffffb8;
  undefined8 in_stack_ffffffffffffffc0;
  undefined8 local_28;
  longlong local_20;
  undefined4 local_18;
  undefined2 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_88;
  local_14 = 0x500;
  local_20 = 0;
  local_18 = 0;
  local_28 = 0x10000000;
  KeInitializeSpinLock(&qospIrpContextLookasideListLock);
  ExInitializeNPagedLookasideList(&qospIrpContextLookasideList,0,0,0x200);
  iVar1 = TopAllocateAndInitializeSid
                    (&local_18,6,0x50,0x62e42435,0xbba433cc,0x33564568,0xeba2e3c2,0xf123d6d4,
                     in_stack_ffffffffffffffb8,in_stack_ffffffffffffffc0,&local_20);
  if (iVar1 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((byte)WPP_GLOBAL_Control[0x29] < 2)) ||
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) goto LAB_1400159a2;
    uVar2 = 0xe;
  }
  else {
    iVar1 = TopCreateSecurityDescriptor(&toppNetworkTestServiceDescriptor,(longlong)&local_28,1);
    ExFreePoolWithTag(local_20,0);
    if (-1 < iVar1) {
      return 0;
    }
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((byte)WPP_GLOBAL_Control[0x29] < 2)) ||
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) goto LAB_1400159a2;
    uVar2 = 0xf;
  }
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar2,
           &WPP_1564c523e1063e4f7fac143b272659d2_Traceguids,iVar1);
LAB_1400159a2:
  ExDeleteNPagedLookasideList(&qospIrpContextLookasideList);
  return iVar1;
}



===== TopStartRtlSupportModule @ 1400159f0 =====

uint TopStartRtlSupportModule(void)

{
  KeInitializeSpinLock(&DAT_14000f440);
  DAT_14000f5f0 = MmAllocateMappingAddress(0x1000,0x74506142);
  return ~-(uint)(DAT_14000f5f0 != 0) & 0xc000009a;
}



===== TopStartNetBufferModule @ 140015a40 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 TopStartNetBufferModule(void)

{
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  local_28 = 0;
  uStack_20 = 0;
  DAT_14000f600 = NdisAllocateGenericObject(0,0x424e6142,0);
  if (DAT_14000f600 != 0) {
    local_28 = CONCAT26(local_28._6_2_,0x10000100180);
    uStack_20 = CONCAT44(uStack_20._4_4_,0x424e6142);
    topNetBufferAndNetBufferListPool = NdisAllocateNetBufferListPool(DAT_14000f600,&local_28);
    if (topNetBufferAndNetBufferListPool != 0) {
      return 0;
    }
  }
  TopStopNetBufferModule();
  return 0xc000009a;
}



===== TopCreateSecurityDescriptor @ 140015ae0 =====

int TopCreateSecurityDescriptor(undefined8 param_1,longlong param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined2 uVar5;
  uint uVar6;
  undefined8 *puVar7;
  ulonglong uVar8;
  undefined4 local_res20 [2];
  undefined8 local_38;
  undefined8 local_30;
  
  uVar8 = (ulonglong)param_3;
  iVar1 = RtlCreateSecurityDescriptor(param_1,1);
  if (iVar1 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (1 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0))
    {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
               &WPP_6a48e31e446332df021f8f71f6b1fa4f_Traceguids,iVar1);
    }
    return iVar1;
  }
  iVar1 = 8;
  if (param_3 != 0) {
    puVar7 = (undefined8 *)(param_2 + 8);
    do {
      iVar2 = RtlLengthSid(*puVar7);
      puVar7 = puVar7 + 2;
      iVar1 = iVar1 + 8 + iVar2;
      uVar8 = uVar8 - 1;
    } while (uVar8 != 0);
  }
  uVar6 = 0;
  local_30 = 0;
  local_38 = 1;
  lVar3 = ExAllocatePool3(0x40,iVar1,0x44536f49,&local_38,1);
  if (lVar3 == 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (1 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
              &WPP_6a48e31e446332df021f8f71f6b1fa4f_Traceguids);
    }
    return -0x3fffff66;
  }
  iVar1 = RtlCreateAcl(lVar3,iVar1,2);
  if (iVar1 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((byte)WPP_GLOBAL_Control[0x29] < 2)) || ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0))
    goto LAB_140015c59;
    uVar5 = 0x15;
  }
  else {
    uVar4 = IoGetFileObjectGenericMapping();
    for (; uVar6 < param_3; uVar6 = uVar6 + 1) {
      local_res20[0] = *(undefined4 *)(param_2 + (ulonglong)uVar6 * 0x10);
      RtlMapGenericMask(local_res20,uVar4);
      iVar1 = RtlAddAccessAllowedAce(lVar3,2,local_res20[0]);
      if (iVar1 < 0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
          WPP_SF_Dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
                    &WPP_6a48e31e446332df021f8f71f6b1fa4f_Traceguids,uVar6,(char)iVar1);
        }
        goto LAB_140015c59;
      }
    }
    if (uVar6 != param_3) goto LAB_140015c59;
    iVar1 = RtlSetDaclSecurityDescriptor(param_1,1,lVar3,0);
    if (iVar1 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((byte)WPP_GLOBAL_Control[0x29] < 2)) || ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)
         ) goto LAB_140015c59;
      uVar5 = 0x17;
    }
    else {
      iVar1 = RtlSetOwnerSecurityDescriptor
                        (param_1,*(undefined8 *)(*(longlong *)SeExports_exref + 0x108),0);
      if (-1 < iVar1) {
        return 0;
      }
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((byte)WPP_GLOBAL_Control[0x29] < 2)) || ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)
         ) goto LAB_140015c59;
      uVar5 = 0x18;
    }
  }
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,
           &WPP_6a48e31e446332df021f8f71f6b1fa4f_Traceguids,iVar1);
LAB_140015c59:
  ExFreePoolWithTag(lVar3,0);
  return iVar1;
}



===== DriverEntry @ 140015e10 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong DriverEntry(longlong param_1,undefined8 *param_2)

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  undefined2 uVar6;
  ulonglong uVar7;
  undefined1 auStack_d8 [32];
  uint local_b8;
  int *local_b0;
  undefined8 *local_a8;
  int local_98 [2];
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 *local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined1 local_40 [4];
  int local_3c;
  int local_34;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_d8;
  uVar2 = wil_InitializeFeatureStaging();
  if ((int)uVar2 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (1 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0))
    {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
               &WPP_6a48e31e446332df021f8f71f6b1fa4f_Traceguids,uVar2);
    }
    return (ulonglong)uVar2;
  }
  if (*(int *)InitSafeBootMode_exref != 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (2 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
              &WPP_6a48e31e446332df021f8f71f6b1fa4f_Traceguids);
    }
    if (g_wil_details_featureChangeNotification != 0) {
      RtlUnregisterFeatureConfigurationChangeNotification();
      g_wil_details_featureChangeNotification = 0;
    }
    if (g_wil_details_featureUsageProvider != 0) {
      RtlUnregisterFeatureUsageProvider();
      g_wil_details_featureUsageProvider = 0;
    }
    g_wil_details_isFeatureStagingInitialized = 0;
    return 0xc000035f;
  }
  _WPP_MAIN_CB = 0;
  DAT_14000f6a8 = &WPP_ThisDir_CTLGUID_LLTDIO;
  DAT_14000f6b0 = 0;
  _DAT_14000f6c0 = 0;
  _DAT_14000f6c8 = 1;
  topDriverObject = param_1;
  WppLoadTracingSupport();
  _DAT_14000f6c0 = 0;
  WppInitKm();
  local_80 = 0x30;
  _DAT_14000f530 = ToppPolicyChangeNotificationCallback;
  local_68 = 0x200;
  _DAT_14000f538 = 0;
  _DAT_14000f520 = 0;
  local_78 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_70 = (undefined8 *)0x0;
  local_b8 = local_b8 & 0xffffff00;
  uVar2 = ZwCreateEvent(&DAT_14000f5e0,0x1f0003,&local_80,0);
  if ((int)uVar2 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (1 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0))
    {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
               &WPP_6a48e31e446332df021f8f71f6b1fa4f_Traceguids,uVar2);
    }
    WppCleanupKm();
    wil_UninitializeFeatureStaging();
    return (ulonglong)uVar2;
  }
  DAT_14000f540 = 3;
  DAT_14000f548 = 0;
  KeInitializeDpc(&DAT_14000f4d0,ToppDelayedPolicyResolutionTimerCallback,0);
  KeInitializeTimer(&DAT_14000f5a0);
  KeInitializeDpc(&DAT_14000f480,ToppDelayedPolicyChangeKeyNotifyTimerCallback,0);
  KeInitializeTimer(&DAT_14000f550);
  _DAT_14000f448 = 1;
  _DAT_14000f450 = 0;
  _DAT_14000f458 = 0;
  KeInitializeEvent(&DAT_14000f460,1,0);
  DAT_14000f4c0 = 4;
  local_90 = 0;
  _DAT_14000f590 = &DAT_14000f000;
  local_88 = 0;
  local_80 = 0x30;
  local_50 = 0;
  uStack_48 = 0;
  local_68 = 0x240;
  local_60 = 0;
  uStack_58 = 0;
  local_98[0] = 0;
  local_78 = 0;
  local_70 = param_2;
  iVar3 = ZwOpenKey(&local_90,0x20019,&local_80);
  if (-1 < iVar3) {
    RtlInitUnicodeString(&local_50,L"Parameters");
    local_78 = local_90;
    local_70 = &local_50;
    local_80 = CONCAT44(local_80._4_4_,0x30);
    local_68 = CONCAT44(local_68._4_4_,0x240);
    local_60 = 0;
    uStack_58 = 0;
    iVar3 = ZwOpenKey(&local_88,0x20019,&local_80);
    ZwClose(local_90);
    if (-1 < iVar3) {
      RtlInitUnicodeString(&local_50,L"EnableNetTestAccessCheck");
      local_b0 = local_98;
      local_b8 = 0x20;
      iVar3 = ZwQueryValueKey(local_88,&local_50,2,local_40);
      ZwClose(local_88);
      if ((((-1 < iVar3) && (local_98[0] == 0x10)) && (local_3c == 4)) && (local_34 == 0)) {
        topEnableNetTestAccessCheck = 0;
      }
    }
  }
  local_a8 = &topDeviceObject;
  local_b0 = (int *)((ulonglong)local_b0 & 0xffffffffffffff00);
  local_b8 = 0x100;
  uVar2 = IoCreateDevice(param_1,0,&TOPP_DEVICE_NAME_STRING,0x12);
  uVar7 = (ulonglong)uVar2;
  if ((int)uVar2 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((byte)WPP_GLOBAL_Control[0x29] < 2)) || ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0))
    goto LAB_140016353;
    uVar5 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
    uVar6 = 0xd;
  }
  else {
    uVar2 = ToppAdjustSecurityDescriptor();
    uVar7 = (ulonglong)uVar2;
    if ((int)uVar2 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((byte)WPP_GLOBAL_Control[0x29] < 2)) || ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)
         ) goto LAB_140016353;
      uVar6 = 0xe;
    }
    else {
      *(uint *)(topDeviceObject + 0x30) = *(uint *)(topDeviceObject + 0x30) | 0x10;
      KeInitializeEvent(&topBindingComplete);
      lVar1 = topDriverObject;
      *(code **)(topDriverObject + 0x70) = ToppDispatchCreate;
      *(code **)(lVar1 + 0x100) = ToppDispatch;
      *(code **)(lVar1 + 0x80) = ToppDispatch;
      *(code **)(lVar1 + 0x88) = ToppDispatch;
      *(code **)(lVar1 + 0x90) = ToppDispatch;
      *(code **)(lVar1 + 0xe0) = ToppDispatch;
      uVar2 = TopRtlInvokeStartRoutines();
      uVar7 = (ulonglong)uVar2;
      if ((int)uVar2 < 0) {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((byte)WPP_GLOBAL_Control[0x29] < 2)) ||
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) goto LAB_140016353;
        uVar6 = 0xf;
      }
      else {
        uVar4 = ToppEnablePolicySettingsHelper();
        uVar7 = uVar4 & 0xffffffff;
        if (-1 < (int)uVar4) {
          ToppDelayedPolicyResolutionWorker(0,0,0);
          *(code **)(param_1 + 0x68) = ToppUnloadDriver;
          *(uint *)(topDeviceObject + 0x30) = *(uint *)(topDeviceObject + 0x30) & 0xffffff7f;
          return 0;
        }
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((byte)WPP_GLOBAL_Control[0x29] < 2)) ||
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) goto LAB_140016353;
        uVar6 = 0x10;
      }
    }
    uVar5 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
  }
  WPP_SF_D(uVar5,uVar6,&WPP_6a48e31e446332df021f8f71f6b1fa4f_Traceguids,(int)uVar7);
LAB_140016353:
  ToppUnloadDriver();
  return uVar7;
}


