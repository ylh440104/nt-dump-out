
===== AsyncWorkerThreadCallback @ 140001010 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void AsyncWorkerThreadCallback
               (undefined8 param_1,_KsecIoctlIpcFunctionCall *param_2,undefined8 param_3,
               undefined8 param_4)

{
  undefined4 uVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  longlong local_18;
  undefined8 local_10;
  
  TlsSetValue(DAT_14000d0cc,param_2 + 0x20);
  if (DAT_14000d6e8 == (void *)0x0) {
    local_18 = *(longlong *)(param_2 + 0x10);
    local_10 = *(undefined8 *)(param_2 + 0x18);
    RtlEnterCriticalSection(&InitConnectionCriticalSection);
    if (DAT_14000d6e8 == (void *)0x0) {
      uVar3 = 0xc0000002;
      if ((gLsapSspiExtension != 0) && (*(code **)(gLsapSspiExtension + 0x80) != (code *)0x0)) {
        uVar2 = (**(code **)(gLsapSspiExtension + 0x80))(&local_18,L"AsyncKsecDD",&DAT_14000d6e8);
        uVar3 = (ulonglong)uVar2;
        if (-1 < (int)uVar2) goto LAB_140001060;
      }
      if (DebugInfoLevel != 0) {
        LsapDebugOut(1,"Failed to init connection handle. Status: 0x%x\n",uVar3,param_4);
      }
    }
LAB_140001060:
    RtlLeaveCriticalSection(&InitConnectionCriticalSection);
    if (DAT_14000d6e8 == (void *)0x0) {
      if ((param_2 != (_KsecIoctlIpcFunctionCall *)0x0) && (*(longlong *)param_2 != 0)) {
        uVar4 = 0;
        local_10 = 0xc0000140;
        local_18 = *(longlong *)param_2;
        uVar2 = LsapCallKsec(0x39006f,&local_18,0x10,0,0);
        if (((int)uVar2 < 0) && (DebugInfoLevel != 0)) {
          LsapDebugOut(1,"SendStatusOnlyResponse failed. ReturnValue: 0x%x\n",(ulonglong)uVar2,uVar4
                      );
        }
      }
      goto LAB_140001088;
    }
  }
  uVar2 = *(uint *)(param_2 + 8);
  if (uVar2 != 2) {
    if (uVar2 == 0) {
      AsyncAcquireCredentialsHandle(DAT_14000d6e8,param_2);
      goto LAB_140001088;
    }
    if (uVar2 != 1) {
      if (uVar2 == 3) {
        if ((gLsapSspiExtension == 0) || (*(longlong *)(gLsapSspiExtension + 0x40) == 0)) {
          if (DebugInfoLevel != 0) {
            LsapDebugOut(2,"The registered SSPI extenstion does not support ACH\n",3,param_4);
          }
          SendStatusOnlyResponse((longlong *)param_2,0xc00000bb);
        }
        else if (*(uint *)(param_2 + 0x28) < 0x50) {
          SendStatusOnlyResponse((longlong *)param_2,0xc0000023);
        }
        else {
          uVar1 = SspirDeleteSecurityContext(DAT_14000d6e8,param_2 + 0x10,param_2 + 0x38,0);
          if (*(int *)(param_2 + 0x48) != 0) {
            SendStatusOnlyResponse((longlong *)param_2,uVar1);
          }
        }
      }
      else {
        if (DebugInfoLevel != 0) {
          LsapDebugOut(1,"Invalid async ksecdd function call: %d\n",(ulonglong)uVar2,param_4);
        }
        SendStatusOnlyResponse((longlong *)param_2,0xc0000002);
      }
      goto LAB_140001088;
    }
  }
  AsyncProcessSecurityContext(DAT_14000d6e8,param_2);
LAB_140001088:
  TlsSetValue(DAT_14000d0cc,(LPVOID)0x0);
  NtClose(*(undefined8 *)(param_2 + 0x20));
                    /* WARNING: Could not recover jumptable at 0x0001400010cd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,param_2);
  return;
}



===== AsyncProcessSecurityContext @ 1400012d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* WARNING: Type propagation algorithm not settling */
/* void __cdecl AsyncProcessSecurityContext(void * __ptr64,struct _KsecIoctlIpcFunctionCall *
   __ptr64) */

void __cdecl AsyncProcessSecurityContext(void *param_1,_KsecIoctlIpcFunctionCall *param_2)

{
  _KsecIoctlIpcFunctionCall *p_Var1;
  longlong lVar2;
  int iVar3;
  DWORD DVar4;
  _KsecIoctlIpcFunctionCall *p_Var5;
  uint uVar6;
  ulonglong uVar7;
  uint uVar8;
  undefined8 in_R8;
  longlong lVar9;
  undefined8 in_R9;
  undefined8 uVar10;
  undefined1 auStackY_188 [32];
  undefined8 local_d8;
  longlong lStack_d0;
  longlong local_c8;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 *puStack_88;
  longlong local_80;
  undefined8 *puStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_188;
  if ((gLsapSspiExtension == 0) || (*(longlong *)(gLsapSspiExtension + 0x38) == 0)) {
    if (DebugInfoLevel != 0) {
      LsapDebugOut(2,"The registered SSPI extenstion does not support PSC\n",in_R8,in_R9);
    }
    SendStatusOnlyResponse((longlong *)param_2,0xc00000bb);
    return;
  }
  uVar6 = *(uint *)(param_2 + 0x28);
  if (uVar6 < 0x78) {
    local_c8 = *(longlong *)param_2;
    if (local_c8 == 0) {
      return;
    }
LAB_14000167e:
    uVar10 = 0;
    local_bc = 0;
    local_c0 = 0xc0000023;
    uVar6 = LsapCallKsec(0x39006f,&local_c8,0x10,0,0);
    if (((int)uVar6 < 0) && (DebugInfoLevel != 0)) {
      LsapDebugOut(1,"SendStatusOnlyResponse failed. ReturnValue: 0x%x\n",(ulonglong)uVar6,uVar10);
    }
  }
  else {
    uVar7 = *(ulonglong *)(param_2 + 0x38);
    if (uVar7 <= uVar6) {
      if (uVar7 != 0) {
        *(_KsecIoctlIpcFunctionCall **)(param_2 + 0x38) = param_2 + uVar7;
      }
      p_Var5 = *(_KsecIoctlIpcFunctionCall **)(param_2 + 0x68);
      if (p_Var5 <= (_KsecIoctlIpcFunctionCall *)(ulonglong)uVar6) {
        if (p_Var5 != (_KsecIoctlIpcFunctionCall *)0x0) {
          p_Var5 = p_Var5 + (longlong)param_2;
          *(_KsecIoctlIpcFunctionCall **)(param_2 + 0x68) = p_Var5;
        }
        lVar9 = 0;
        if (p_Var5 != (_KsecIoctlIpcFunctionCall *)0x0) {
          p_Var1 = *(_KsecIoctlIpcFunctionCall **)(p_Var5 + 8);
          if ((_KsecIoctlIpcFunctionCall *)(ulonglong)uVar6 < p_Var1) goto LAB_140001743;
          if (p_Var1 != (_KsecIoctlIpcFunctionCall *)0x0) {
            *(_KsecIoctlIpcFunctionCall **)(p_Var5 + 8) = p_Var1 + (longlong)param_2;
          }
          for (uVar6 = 0; lVar9 = *(longlong *)(param_2 + 0x68), uVar6 < *(uint *)(lVar9 + 4);
              uVar6 = uVar6 + 1) {
            lVar9 = *(longlong *)(lVar9 + 8) + (ulonglong)uVar6 * 0x10;
            uVar7 = *(ulonglong *)(lVar9 + 8);
            if (*(uint *)(param_2 + 0x28) < uVar7) goto LAB_140001743;
            if (uVar7 != 0) {
              *(_KsecIoctlIpcFunctionCall **)(lVar9 + 8) = param_2 + uVar7;
            }
          }
        }
        uVar7 = *(ulonglong *)(param_2 + 0x70);
        if (uVar7 <= *(uint *)(param_2 + 0x28)) {
          if (uVar7 == 0) {
LAB_1400013f6:
            if ((lVar9 != 0) && (uVar7 = (ulonglong)*(uint *)(lVar9 + 4), *(uint *)(lVar9 + 4) != 0)
               ) {
              do {
                uVar7 = uVar7 - 1;
              } while (uVar7 != 0);
            }
            local_50 = 0;
            puStack_88 = &local_d8;
            local_90 = 0;
            puStack_78 = &local_b8;
            local_80 = 0;
            local_98 = *(undefined8 *)param_2;
            local_a8 = 0;
            uStack_a0 = 0;
            local_d8 = 0;
            lStack_d0 = 0;
            local_b8 = 0;
            uStack_b0 = 0;
            local_70 = 0;
            uStack_68 = 0;
            local_60 = 0;
            uStack_58 = 0;
            if (*(longlong *)(param_2 + 0x38) == 0) {
              p_Var5 = (_KsecIoctlIpcFunctionCall *)0x0;
            }
            else {
              p_Var5 = param_2 + 0x30;
            }
            iVar3 = SspirProcessSecurityContext(param_1,param_2 + 0x10,&local_70);
            if (iVar3 < 0) {
              if (DebugInfoLevel != 0) {
                LsapDebugOut(2,"%hs - Ignoring API status as marshaling failed\n",
                             "AsyncProcessSecurityContext",p_Var5);
              }
              local_90 = CONCAT44(local_90._4_4_,iVar3);
            }
            DVar4 = MarshalAndSendProcessSecurityContextResult(&local_98);
            if ((int)DVar4 < 0) {
              if (DebugInfoLevel != 0) {
                LsapDebugOut(1,
                             "Unable to marshal result to caller - sending status only. Status: 0x%x \n"
                             ,(ulonglong)DVar4,p_Var5);
              }
              SendStatusOnlyResponse((longlong *)param_2,DVar4);
            }
            if (lStack_d0 != 0) {
              uVar8 = 0;
              lVar9 = lStack_d0;
              uVar6 = local_d8._4_4_;
              if (local_d8._4_4_ != 0) {
                do {
                  lVar2 = *(longlong *)(lVar9 + 8 + (ulonglong)uVar8 * 0x10);
                  if (lVar2 != 0) {
                    (**(code **)(gLsapSspiExtension + 8))(lVar2);
                    *(undefined8 *)(lStack_d0 + 8 + (ulonglong)uVar8 * 0x10) = 0;
                    lVar9 = lStack_d0;
                    uVar6 = local_d8._4_4_;
                  }
                  uVar8 = uVar8 + 1;
                } while (uVar8 < uVar6);
              }
              (**(code **)(gLsapSspiExtension + 8))();
              lStack_d0 = 0;
            }
            if (puStack_78[1] != 0) {
              (**(code **)(gLsapSspiExtension + 8))();
              puStack_78[1] = 0;
            }
            if (local_80 == 0) {
              return;
            }
            (**(code **)(gLsapSspiExtension + 8))();
            return;
          }
          p_Var5 = param_2 + uVar7;
          *(_KsecIoctlIpcFunctionCall **)(param_2 + 0x70) = p_Var5;
          if (p_Var5 == (_KsecIoctlIpcFunctionCall *)0x0) goto LAB_1400013f6;
          uVar7 = *(ulonglong *)(p_Var5 + 8);
          if (uVar7 <= *(uint *)(param_2 + 0x28)) {
            if (uVar7 != 0) {
              *(_KsecIoctlIpcFunctionCall **)(p_Var5 + 8) = param_2 + uVar7;
              lVar9 = *(longlong *)(param_2 + 0x68);
            }
            goto LAB_1400013f6;
          }
          local_c8 = *(longlong *)param_2;
          if (local_c8 == 0) {
            return;
          }
          goto LAB_14000167e;
        }
      }
    }
LAB_140001743:
    SendStatusOnlyResponse((longlong *)param_2,0xc0000023);
  }
  return;
}



===== MarshalAndSendProcessSecurityContextResult @ 140001790 =====

DWORD MarshalAndSendProcessSecurityContextResult(undefined8 *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined8 *puVar5;
  uint uVar6;
  int *piVar7;
  void *pvVar8;
  undefined8 uVar9;
  uint uVar10;
  BOOL BVar11;
  DWORD DVar12;
  undefined8 *_Dst;
  longlong lVar13;
  uint *puVar14;
  longlong lVar15;
  ulonglong uVar16;
  undefined8 *puVar17;
  uint uVar18;
  longlong *plVar19;
  uint uVar20;
  undefined8 *_Dst_00;
  undefined8 *puVar21;
  ulonglong uVar22;
  undefined4 *puVar23;
  int iVar24;
  int iVar25;
  int iVar26;
  int iVar27;
  int iVar28;
  int iVar29;
  int iVar30;
  int iVar31;
  undefined8 *local_res20;
  
  lVar13 = param_1[2];
  DVar12 = 0;
  uVar18 = 0;
  if (lVar13 != 0) {
    uVar6 = *(uint *)(lVar13 + 4);
    uVar18 = 0x10;
    if (uVar6 != 0) {
      uVar10 = 0;
      uVar18 = (uVar6 + 1) * 0x10;
      if (uVar6 != 0) {
        if (7 < uVar6) {
          lVar15 = *(longlong *)(lVar13 + 8);
          iVar28 = 0;
          iVar29 = 0;
          iVar30 = 0;
          iVar31 = 0;
          iVar24 = 0;
          iVar25 = 0;
          iVar26 = 0;
          iVar27 = 0;
          uVar20 = 2;
          do {
            uVar16 = (ulonglong)uVar10;
            uVar10 = uVar10 + 8;
            uVar1 = uVar20 + 4;
            uVar2 = uVar20 + 3;
            uVar3 = uVar20 + 2;
            uVar4 = uVar20 + 5;
            iVar28 = iVar28 + *(int *)(lVar15 + uVar16 * 0x10);
            iVar29 = iVar29 + *(int *)(lVar15 + (ulonglong)(uVar20 - 1) * 0x10);
            iVar30 = iVar30 + *(int *)(lVar15 + (ulonglong)uVar20 * 0x10);
            iVar31 = iVar31 + *(int *)(lVar15 + (ulonglong)(uVar20 + 1) * 0x10);
            uVar20 = uVar20 + 8;
            iVar24 = *(int *)(lVar15 + (ulonglong)uVar3 * 0x10) + iVar24;
            iVar25 = *(int *)(lVar15 + (ulonglong)uVar2 * 0x10) + iVar25;
            iVar26 = *(int *)(lVar15 + (ulonglong)uVar1 * 0x10) + iVar26;
            iVar27 = *(int *)(lVar15 + (ulonglong)uVar4 * 0x10) + iVar27;
          } while (uVar10 < (uVar6 & 0xfffffff8));
          uVar18 = uVar18 + iVar28 + iVar24 + iVar30 + iVar26 + iVar29 + iVar25 + iVar31 + iVar27;
          if (uVar6 <= uVar10) goto LAB_1400017c2;
        }
        lVar15 = (ulonglong)uVar10 << 4;
        uVar16 = (ulonglong)(uVar6 - uVar10);
        do {
          uVar18 = uVar18 + *(int *)(*(longlong *)(lVar13 + 8) + lVar15);
          lVar15 = lVar15 + 0x10;
          uVar16 = uVar16 - 1;
        } while (uVar16 != 0);
      }
    }
  }
LAB_1400017c2:
  if (param_1[3] != 0) {
    iVar24 = *(int *)(param_1[3] + 4);
    uVar18 = uVar18 + 0x10;
    if (iVar24 != 0) {
      uVar18 = uVar18 + iVar24 * 8;
    }
  }
  piVar7 = (int *)param_1[4];
  if ((piVar7 != (int *)0x0) && (uVar18 = uVar18 + 0x10, *(longlong *)(piVar7 + 2) != 0)) {
    uVar18 = uVar18 + *piVar7;
  }
  if (uVar18 == 0) {
    return 0xc000009a;
  }
  uVar6 = uVar18 + 0x50;
  _Dst = (undefined8 *)
         RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),8,uVar6);
  if (_Dst == (undefined8 *)0x0) {
    return 0xc000009a;
  }
  memset(_Dst,0,(ulonglong)uVar6);
  uVar9 = param_1[1];
  puVar21 = _Dst + 10;
  *_Dst = *param_1;
  _Dst[1] = uVar9;
  uVar9 = param_1[3];
  _Dst[2] = param_1[2];
  _Dst[3] = uVar9;
  uVar9 = param_1[5];
  _Dst[4] = param_1[4];
  _Dst[5] = uVar9;
  uVar9 = param_1[7];
  _Dst[6] = param_1[6];
  _Dst[7] = uVar9;
  uVar9 = param_1[9];
  _Dst[8] = param_1[8];
  _Dst[9] = uVar9;
  puVar17 = (undefined8 *)param_1[2];
  _Dst[2] = 0;
  _Dst_00 = puVar21;
  if ((puVar17 == (undefined8 *)0x0) || (_Dst[2] = 0, uVar18 < 0x10)) {
LAB_140001993:
    puVar23 = (undefined4 *)param_1[3];
    _Dst[3] = 0;
    if (_Dst != (undefined8 *)0x0) goto LAB_1400019b1;
LAB_1400019ba:
    puVar14 = (uint *)param_1[4];
    _Dst[4] = 0;
    puVar21 = _Dst_00;
    if (_Dst == (undefined8 *)0x0) goto LAB_140001a2c;
  }
  else {
    uVar18 = uVar18 - 0x10;
    _Dst[2] = puVar21;
    puVar5 = _Dst + 0xc;
    _Dst_00 = puVar5;
    if (puVar21 == (undefined8 *)0x0) goto LAB_140001993;
    uVar9 = puVar17[1];
    *puVar21 = *puVar17;
    _Dst[0xb] = uVar9;
    iVar24 = *(int *)((longlong)puVar17 + 4);
    lVar13 = _Dst[2];
    uVar10 = iVar24 * 0x10;
    *(undefined8 *)(lVar13 + 8) = 0;
    if (uVar10 <= uVar18) {
      _Dst_00 = (undefined8 *)((ulonglong)uVar10 + (longlong)puVar5);
      *(undefined8 **)(lVar13 + 8) = puVar5;
      uVar18 = uVar18 + iVar24 * -0x10;
    }
    local_res20 = *(undefined8 **)(_Dst[2] + 8);
    if (local_res20 == (undefined8 *)0x0) {
      _Dst[2] = 0;
      puVar23 = (undefined4 *)param_1[3];
      _Dst[3] = 0;
    }
    else {
      puVar14 = (uint *)puVar17[1];
      for (uVar10 = 0; uVar10 < *(uint *)((longlong)puVar17 + 4); uVar10 = uVar10 + 1) {
        uVar9 = *(undefined8 *)(puVar14 + 2);
        *local_res20 = *(undefined8 *)puVar14;
        local_res20[1] = uVar9;
        pvVar8 = *(void **)(puVar14 + 2);
        uVar20 = *puVar14;
        local_res20[1] = 0;
        if (pvVar8 != (void *)0x0) {
          if (uVar18 < uVar20) {
            _Dst[2] = 0;
            puVar23 = (undefined4 *)param_1[3];
            _Dst[3] = 0;
            goto LAB_1400019b1;
          }
          memcpy(_Dst_00,pvVar8,(ulonglong)uVar20);
          lVar13 = (longlong)_Dst_00 - (longlong)_Dst;
          _Dst_00 = (undefined8 *)((longlong)_Dst_00 + (ulonglong)uVar20);
          uVar18 = uVar18 - uVar20;
          local_res20[1] = lVar13;
        }
        local_res20 = local_res20 + 2;
        puVar14 = puVar14 + 4;
      }
      *(longlong *)(_Dst[2] + 8) = *(longlong *)(_Dst[2] + 8) - (longlong)_Dst;
      _Dst[2] = _Dst[2] - (longlong)_Dst;
      puVar23 = (undefined4 *)param_1[3];
      _Dst[3] = 0;
    }
LAB_1400019b1:
    if (puVar23 == (undefined4 *)0x0) goto LAB_1400019ba;
    _Dst[3] = 0;
    puVar17 = (undefined8 *)0x0;
    puVar21 = _Dst_00;
    if (0xf < uVar18) {
      _Dst[3] = _Dst_00;
      puVar21 = _Dst_00 + 2;
      uVar18 = uVar18 - 0x10;
      puVar17 = _Dst_00;
    }
    if (puVar17 == (undefined8 *)0x0) {
      _Dst[3] = 0;
      puVar14 = (uint *)param_1[4];
      _Dst[4] = 0;
    }
    else {
      iVar24 = puVar23[1];
      puVar17[1] = 0;
      uVar10 = iVar24 * 8;
      if (uVar10 <= uVar18) {
        puVar17[1] = puVar21;
        puVar21 = (undefined8 *)((longlong)puVar21 + (ulonglong)uVar10);
        uVar18 = uVar18 + iVar24 * -8;
      }
      if (*(longlong *)((undefined4 *)_Dst[3] + 2) == 0) {
        _Dst[3] = 0;
        puVar14 = (uint *)param_1[4];
        _Dst[4] = 0;
      }
      else {
        uVar10 = 0;
        *(undefined4 *)_Dst[3] = *puVar23;
        *(undefined4 *)(_Dst[3] + 4) = puVar23[1];
        if (puVar23[1] != 0) {
          do {
            uVar16 = (ulonglong)uVar10;
            uVar10 = uVar10 + 1;
            lVar13 = uVar16 * 8;
            *(undefined4 *)(*(longlong *)(_Dst[3] + 8) + 4 + lVar13) =
                 *(undefined4 *)(*(longlong *)(puVar23 + 2) + 4 + lVar13);
            *(undefined4 *)(lVar13 + *(longlong *)(_Dst[3] + 8)) =
                 *(undefined4 *)(lVar13 + *(longlong *)(puVar23 + 2));
          } while (uVar10 < (uint)puVar23[1]);
        }
        *(longlong *)(_Dst[3] + 8) = *(longlong *)(_Dst[3] + 8) - (longlong)_Dst;
        _Dst[3] = _Dst[3] - (longlong)_Dst;
        puVar14 = (uint *)param_1[4];
        _Dst[4] = 0;
      }
    }
  }
  plVar19 = _Dst + 4;
  if ((puVar14 != (uint *)0x0) && (*plVar19 = 0, 0xf < uVar18)) {
    *plVar19 = (longlong)puVar21;
    if (puVar21 != (undefined8 *)0x0) {
      uVar9 = *(undefined8 *)(puVar14 + 2);
      *puVar21 = *(undefined8 *)puVar14;
      puVar21[1] = uVar9;
      pvVar8 = *(void **)(puVar14 + 2);
      lVar13 = *plVar19;
      uVar10 = *puVar14;
      *(undefined8 *)(lVar13 + 8) = 0;
      if (pvVar8 != (void *)0x0) {
        if (uVar18 - 0x10 < uVar10) {
          *plVar19 = 0;
          goto LAB_140001a2c;
        }
        memcpy(puVar21 + 2,pvVar8,(ulonglong)uVar10);
        *(longlong *)(lVar13 + 8) = (longlong)(puVar21 + 2) - (longlong)_Dst;
      }
      *plVar19 = *plVar19 - (longlong)_Dst;
    }
  }
LAB_140001a2c:
  if (uVar6 == 0) {
    if (DebugInfoLevel != 0) {
      LsapDebugOut(1,
                   "AsyncKsecSendResponse parameter check failed. Response: 0x%p ResponseSize: 0x%x\n"
                   ,_Dst,0);
    }
    DVar12 = 0xc000000d;
  }
  else {
    uVar16 = (ulonglong)uVar6;
    BVar11 = DeviceIoControl(DAT_14000d6f0,0x39006f,_Dst,uVar6,(LPVOID)0x0,0,(LPDWORD)0x0,
                             (LPOVERLAPPED)0x0);
    if (BVar11 == 0) {
      DVar12 = GetLastError();
      uVar22 = (ulonglong)DVar12;
      if (0 < (int)DVar12) {
        DVar12 = DVar12 & 0xffff | 0xc0070000;
      }
      if (DebugInfoLevel != 0) {
        LsapDebugOut(1,"AsyncKsecSendResponse DeviceIoControl failed. Error: 0x%x\n",uVar22,uVar16);
      }
    }
  }
  RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,_Dst);
  return DVar12;
}



===== AsyncAcquireCredentialsHandle @ 140001d80 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl AsyncAcquireCredentialsHandle(void * __ptr64,struct _KsecIoctlIpcFunctionCall *
   __ptr64) */

void __cdecl AsyncAcquireCredentialsHandle(void *param_1,_KsecIoctlIpcFunctionCall *param_2)

{
  ulonglong uVar1;
  undefined4 uVar2;
  BOOL BVar3;
  DWORD DVar4;
  ulonglong uVar5;
  DWORD DVar6;
  undefined8 in_R8;
  _KsecIoctlIpcFunctionCall *p_Var7;
  undefined8 in_R9;
  _KsecIoctlIpcFunctionCall *p_Var8;
  undefined8 uVar9;
  undefined1 auStackY_a8 [32];
  undefined8 local_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  undefined8 uStack_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_a8;
  if ((gLsapSspiExtension == 0) || (*(longlong *)(gLsapSspiExtension + 0x28) == 0)) {
    if (DebugInfoLevel != 0) {
      LsapDebugOut(2,"The registered SSPI extenstion does not support ACH\n",in_R8,in_R9);
    }
    SendStatusOnlyResponse((longlong *)param_2,0xc00000bb);
    return;
  }
  uVar5 = (ulonglong)*(uint *)(param_2 + 0x28);
  if ((0x77 < *(uint *)(param_2 + 0x28)) && (uVar1 = *(ulonglong *)(param_2 + 0x48), uVar1 <= uVar5)
     ) {
    if (uVar1 != 0) {
      *(_KsecIoctlIpcFunctionCall **)(param_2 + 0x48) = param_2 + uVar1;
    }
    uVar1 = *(ulonglong *)(param_2 + 0x38);
    if (uVar1 <= uVar5) {
      if (uVar1 != 0) {
        *(_KsecIoctlIpcFunctionCall **)(param_2 + 0x38) = param_2 + uVar1;
      }
      uVar1 = *(ulonglong *)(param_2 + 0x70);
      if (uVar1 != 0) {
        if (uVar5 < uVar1) goto LAB_140001f8e;
        *(_KsecIoctlIpcFunctionCall **)(param_2 + 0x70) = param_2 + uVar1;
      }
      local_38 = *(undefined8 *)param_2;
      local_30 = 0;
      uStack_28 = 0;
      local_20 = 0;
      uStack_18 = 0;
      p_Var8 = param_2 + 0x40;
      p_Var7 = param_2 + 0x30;
      if (*(short *)(param_2 + 0x40) == 0) {
        p_Var8 = (_KsecIoctlIpcFunctionCall *)0x0;
      }
      if (*(short *)p_Var7 == 0) {
        p_Var7 = (_KsecIoctlIpcFunctionCall *)0x0;
      }
      uVar2 = SspirAcquireCredentialsHandle(param_1,param_2 + 0x10,p_Var7,p_Var8);
      uVar9 = 0x28;
      local_30 = CONCAT44(local_30._4_4_,uVar2);
      BVar3 = DeviceIoControl(DAT_14000d6f0,0x39006f,&local_38,0x28,(LPVOID)0x0,0,(LPDWORD)0x0,
                              (LPOVERLAPPED)0x0);
      if (BVar3 != 0) {
        return;
      }
      DVar4 = GetLastError();
      if ((int)DVar4 < 1) {
        DVar6 = DVar4;
      }
      else {
        DVar6 = DVar4 & 0xffff | 0xc0070000;
      }
      if (DebugInfoLevel != 0) {
        LsapDebugOut(1,"AsyncKsecSendResponse DeviceIoControl failed. Error: 0x%x\n",
                     (ulonglong)DVar4,uVar9);
      }
      if (-1 < (int)DVar6) {
        return;
      }
      if (DebugInfoLevel != 0) {
        LsapDebugOut(1,
                     "Unable to marshal SspirAcquireCredentialsHandle result to caller. Status: 0x%x \n"
                     ,(ulonglong)DVar6,uVar9);
      }
      SendStatusOnlyResponse((longlong *)param_2,DVar6);
      return;
    }
  }
LAB_140001f8e:
  SendStatusOnlyResponse((longlong *)param_2,0xc0000023);
  return;
}



===== LsaLookuprOpenPolicy2 @ 140001fd0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

undefined8 LsaLookuprOpenPolicy2(void)

{
  undefined8 uVar1;
  
  if ((gLsapLookupExtension == (undefined8 *)0x0) || ((code *)*gLsapLookupExtension == (code *)0x0))
  {
    uVar1 = 0xc0000002;
  }
  else {
    uVar1 = (*(code *)*gLsapLookupExtension)();
  }
  return uVar1;
}



===== MIDL_user_free @ 140002000 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void __stdcall MIDL_user_free(void *param_1)

{
  if ((gLsapLookupExtension == 0) || (*(code **)(gLsapLookupExtension + 0x40) == (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x000140002015. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    LocalFree();
    return;
  }
  (**(code **)(gLsapLookupExtension + 0x40))();
  return;
}



===== LsaLookuprTranslateSids2 @ 140002030 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

undefined8
LsaLookuprTranslateSids2
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
          undefined8 param_5,undefined4 param_6,undefined4 param_7)

{
  undefined8 uVar1;
  
  if ((gLsapLookupExtension == 0) || (*(code **)(gLsapLookupExtension + 0x10) == (code *)0x0)) {
    uVar1 = 0xc0000002;
  }
  else {
    uVar1 = (**(code **)(gLsapLookupExtension + 0x10))
                      (param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  return uVar1;
}



===== LsaLookuprOpenPolicy2_notify @ 1400020a0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void LsaLookuprOpenPolicy2_notify(void)

{
  if ((gLsapLookupExtension != 0) && (*(code **)(gLsapLookupExtension + 0x58) != (code *)0x0)) {
    (**(code **)(gLsapLookupExtension + 0x58))();
  }
  return;
}



===== LsaLookuprClose @ 1400020d0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

undefined8 LsaLookuprClose(void)

{
  undefined8 uVar1;
  
  if ((gLsapLookupExtension == 0) || (*(code **)(gLsapLookupExtension + 8) == (code *)0x0)) {
    return 0xc0000002;
  }
  uVar1 = (**(code **)(gLsapLookupExtension + 8))();
  return uVar1;
}



===== MIDL_user_allocate @ 140002100 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void * __stdcall MIDL_user_allocate(size_t size)

{
  void *pvVar1;
  HLOCAL pvVar2;
  
  if ((gLsapLookupExtension == 0) || (*(code **)(gLsapLookupExtension + 0x38) == (code *)0x0)) {
    pvVar2 = LocalAlloc(0x40,size);
    return pvVar2;
  }
  pvVar1 = (void *)(**(code **)(gLsapLookupExtension + 0x38))();
  return pvVar1;
}



===== LsapFreeLsaHeap @ 140002150 =====

void LsapFreeLsaHeap(undefined8 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000140002162. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,param_1);
  return;
}



===== LsapMakePipeSD @ 140002180 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int LsapMakePipeSD(longlong *param_1)

{
  int iVar1;
  BOOL BVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  HANDLE ProcessHandle;
  longlong lVar6;
  longlong lVar7;
  undefined1 auStackY_318 [32];
  undefined4 local_2b8;
  DWORD local_2b4;
  HANDLE local_2b0;
  undefined8 local_2a8;
  undefined4 local_2a0;
  undefined2 local_29c;
  undefined8 local_298 [12];
  undefined1 local_238 [512];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_318;
  local_2b4 = 0x4c;
  local_2b0 = (HANDLE)0x0;
  local_2b8 = 0;
  local_2a8 = 0;
  local_2a0 = 0;
  lVar6 = 0;
  local_29c = 0x1000;
  memset(local_238,0,0x200);
  lVar5 = LsapAllocateLsaHeap(0x28);
  if (lVar5 == 0) {
    iVar1 = -0x3fffffe9;
  }
  else {
    iVar1 = RtlCreateSecurityDescriptor(lVar5,1);
    if (-1 < iVar1) {
      ProcessHandle = GetCurrentProcess();
      BVar2 = OpenProcessToken(ProcessHandle,0x20008,&local_2b0);
      if (BVar2 == 0) {
        iVar1 = -0x3fffffe9;
      }
      else {
        BVar2 = GetTokenInformation(local_2b0,TokenOwner,local_298,local_2b4,&local_2b4);
        if (BVar2 == 0) {
          iVar1 = -0x3fffffe9;
        }
        else {
          iVar3 = RtlLengthSid(gLsapAnonymousSid);
          iVar4 = RtlLengthSid(gLsapWorldSid);
          lVar6 = LsapAllocateLsaHeap(iVar3 + iVar4 + 0x70);
          if (lVar6 == 0) {
            iVar1 = -0x3fffffe9;
          }
          else {
            iVar1 = RtlSetOwnerSecurityDescriptor(lVar5,local_298[0],0);
            if ((((-1 < iVar1) && (iVar1 = RtlCreateAcl(lVar6,iVar3 + iVar4 + 0x70,2), -1 < iVar1))
                && (iVar1 = RtlAddAccessAllowedAce(lVar6,2,0x12019b,gLsapWorldSid), -1 < iVar1)) &&
               ((iVar1 = RtlAddAccessAllowedAce(lVar6,2,0x12019b,gLsapAnonymousSid), -1 < iVar1 &&
                (iVar1 = RtlAddAccessAllowedAce(lVar6,2,0x1f01ff,local_298[0]), -1 < iVar1)))) {
              iVar1 = RtlSetDaclSecurityDescriptor(lVar5,1,lVar6,0);
              if (iVar1 < 0) {
                iVar1 = -0x3fffffe9;
              }
              else {
                iVar1 = RtlAllocateAndInitializeSid(&local_2a0,1,0,0);
                if (((-1 < iVar1) && (iVar1 = RtlCreateAcl(local_238,0x200,2), -1 < iVar1)) &&
                   ((iVar1 = RtlAddMandatoryAce(local_238,2,0,local_2a8), -1 < iVar1 &&
                    (iVar1 = RtlSetSaclSecurityDescriptor(lVar5,1,local_238,0), -1 < iVar1)))) {
                  iVar1 = RtlMakeSelfRelativeSD(lVar5,0,&local_2b8);
                  if (iVar1 == -0x3fffffdd) {
                    lVar7 = LsapAllocateLsaHeap(local_2b8);
                    if (lVar7 == 0) {
                      iVar1 = -0x3fffffe9;
                    }
                    else {
                      iVar1 = RtlMakeSelfRelativeSD(lVar5,lVar7,&local_2b8);
                      if (-1 < iVar1) {
                        *param_1 = lVar7;
                      }
                    }
                  }
                  else if (-1 < iVar1) {
                    iVar1 = -0x3fffff1b;
                  }
                }
              }
            }
          }
        }
      }
    }
    if (local_2b0 != (HANDLE)0x0) {
      CloseHandle(local_2b0);
    }
    LsapFreeLsaHeap(lVar6);
    LsapFreeLsaHeap(lVar5);
  }
  return iVar1;
}



===== LsapAllocateLsaHeap @ 140002550 =====

void LsapAllocateLsaHeap(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000140002565. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),8,param_1);
  return;
}



===== LsaLookuprTranslateNames3 @ 140002580 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

undefined8
LsaLookuprTranslateNames3
          (undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
          undefined8 param_5,undefined8 param_6,undefined4 param_7,undefined4 param_8)

{
  undefined8 uVar1;
  
  if ((gLsapLookupExtension == 0) || (*(code **)(gLsapLookupExtension + 0x18) == (code *)0x0)) {
    uVar1 = 0xc0000002;
  }
  else {
    uVar1 = (**(code **)(gLsapLookupExtension + 0x18))
                      (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  }
  return uVar1;
}



===== LsaLookuprGetDomainInfo @ 140002600 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

undefined8 LsaLookuprGetDomainInfo(void)

{
  undefined8 uVar1;
  
  if ((gLsapLookupExtension == 0) || (*(code **)(gLsapLookupExtension + 0x28) == (code *)0x0)) {
    return 0xc0000002;
  }
  uVar1 = (**(code **)(gLsapLookupExtension + 0x28))();
  return uVar1;
}



===== LsaRpcIfCallbackFn @ 140002630 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

undefined8 LsaRpcIfCallbackFn(void)

{
  undefined8 uVar1;
  
  if ((gLsapLookupExtension == 0) || (*(code **)(gLsapLookupExtension + 0x50) == (code *)0x0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(gLsapLookupExtension + 0x50))();
  }
  return uVar1;
}



===== LsapCallRm @ 140002660 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint LsapCallRm(uint param_1,void *param_2,uint param_3,void *param_4,uint param_5)

{
  short sVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined1 auStack_288 [32];
  ulonglong *local_268;
  undefined8 *local_260;
  undefined8 local_258;
  undefined8 local_250;
  undefined8 local_248 [2];
  ulonglong local_238 [5];
  uint local_210;
  undefined1 local_20c [468];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_288;
  memset(local_20c,0,0x1d4);
  if ((param_3 < 0x1d5) && (param_5 < 0x1d5)) {
    local_238[4] = 0;
    local_238[1] = 0;
    sVar1 = (short)(param_3 + 0x30);
    local_238[0] = (ulonglong)CONCAT22(sVar1,sVar1 + -0x28);
    local_238[2] = 0;
    local_238[3] = 0;
    local_210 = param_1;
    if (param_3 != 0) {
      memcpy(local_20c,param_2,(ulonglong)param_3);
    }
    local_248[0] = 0x200;
    local_250 = 0;
    uVar3 = 0;
    local_258 = 0;
    local_260 = local_248;
    local_268 = local_238;
    uVar2 = NtAlpcSendWaitReceivePort(gLsapRmCommandPortHandle,0x20000,local_238);
    if ((int)uVar2 < 0) {
      if (DebugInfoLevel != 0) {
        LsapDebugOut(1,"LsapCallRm: Command sent from LSA to RM failed: 0x%lx\n",(ulonglong)uVar2,
                     uVar3);
      }
    }
    else {
      if (param_4 != (void *)0x0) {
        memcpy(param_4,local_20c,(ulonglong)param_5);
      }
      uVar2 = local_210;
    }
  }
  else {
    uVar2 = 0x80000005;
  }
  return uVar2;
}



===== LsapCallKsec @ 1400027c0 =====

void LsapCallKsec(undefined4 param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4,
                 undefined4 param_5)

{
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  NtDeviceIoControlFile(KsecDevice,0,0,0,&local_18,param_1,param_2,param_3,param_4,param_5);
  return;
}



===== LsaLookuprUserAccountType @ 140002820 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

undefined8 LsaLookuprUserAccountType(void)

{
  undefined8 uVar1;
  
  if ((gLsapLookupExtension == 0) || (*(code **)(gLsapLookupExtension + 0x30) == (code *)0x0)) {
    return 0xc0000002;
  }
  uVar1 = (**(code **)(gLsapLookupExtension + 0x30))();
  return uVar1;
}



===== LsaImpersonateKsecCaller @ 140002850 =====

undefined8 LsaImpersonateKsecCaller(LPHANDLE param_1)

{
  HANDLE hSourceHandle;
  BOOL BVar1;
  undefined8 *puVar2;
  HANDLE hTargetProcessHandle;
  HANDLE hSourceProcessHandle;
  undefined8 uVar3;
  
                    /* 0x2850  2  LsaImpersonateKsecCaller */
  *param_1 = (HANDLE)0x0;
  puVar2 = TlsGetValue(DAT_14000d0cc);
  if (puVar2 != (undefined8 *)0x0) {
    hTargetProcessHandle = GetCurrentProcess();
    hSourceHandle = (HANDLE)*puVar2;
    hSourceProcessHandle = GetCurrentProcess();
    BVar1 = DuplicateHandle(hSourceProcessHandle,hSourceHandle,hTargetProcessHandle,param_1,0,0,2);
    if (BVar1 != 0) {
                    /* WARNING: Could not recover jumptable at 0x00014000290e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar3 = NtSetInformationThread(0xfffffffffffffffe,5,param_1);
      return uVar3;
    }
  }
  return 0xc000005c;
}



===== LsaLookuprTranslateSids2_notify @ 140002920 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void LsaLookuprTranslateSids2_notify(void)

{
  if ((gLsapLookupExtension != 0) && (*(code **)(gLsapLookupExtension + 0x58) != (code *)0x0)) {
    (**(code **)(gLsapLookupExtension + 0x58))();
  }
  return;
}



===== LsaLookuprManageCache @ 140002930 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

undefined8 LsaLookuprManageCache(void)

{
  undefined8 uVar1;
  
  if ((gLsapLookupExtension == 0) || (*(code **)(gLsapLookupExtension + 0x20) == (code *)0x0)) {
    uVar1 = 0xc0000002;
  }
  else {
    uVar1 = (**(code **)(gLsapLookupExtension + 0x20))();
  }
  return uVar1;
}



===== LsapStartExtensions @ 140002970 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void LsapStartExtensions(void)

{
  uint uVar1;
  undefined4 uVar2;
  undefined8 *puVar3;
  
  puVar3 = gLsapExtensionList;
  if ((undefined8 **)gLsapExtensionList != &gLsapExtensionList) {
    do {
      if (*(int *)(puVar3 + 7) == 2) {
        uVar1 = (*(code *)puVar3[9])(2);
        if ((int)uVar1 < 0) {
          if (DebugInfoLevel != 0) {
            LsapDebugOut(1,"LsapStartExtensions: Extension %ws failed to start: 0x%lx\n",puVar3[5],
                         (ulonglong)uVar1);
          }
          *(uint *)(puVar3 + 8) = uVar1;
          uVar2 = RtlNtStatusToDosError(uVar1);
          *(undefined4 *)((longlong)puVar3 + 0x3c) = uVar2;
        }
        else {
          *(undefined4 *)(puVar3 + 7) = 3;
        }
      }
      puVar3 = (undefined8 *)*puVar3;
    } while ((undefined8 **)puVar3 != &gLsapExtensionList);
  }
  return;
}



===== SendStatusOnlyResponse @ 140002a10 =====

void SendStatusOnlyResponse(longlong *param_1,undefined4 param_2)

{
  uint uVar1;
  undefined8 uVar2;
  longlong local_18;
  undefined4 local_10;
  undefined4 local_c;
  
  if ((param_1 != (longlong *)0x0) && (local_18 = *param_1, local_18 != 0)) {
    uVar2 = 0;
    local_c = 0;
    local_10 = param_2;
    uVar1 = LsapCallKsec(0x39006f,&local_18,0x10,0,0);
    if (((int)uVar1 < 0) && (DebugInfoLevel != 0)) {
      LsapDebugOut(1,"SendStatusOnlyResponse failed. ReturnValue: 0x%x\n",(ulonglong)uVar1,uVar2);
    }
  }
  return;
}



===== GetMaxAsyncWorkerThreads @ 140002a80 =====

ulonglong GetMaxAsyncWorkerThreads(void)

{
  ulonglong uVar1;
  uint uVar2;
  LSTATUS LVar3;
  char *pcVar4;
  ulonglong uVar5;
  DWORD local_res8 [2];
  DWORD local_res10 [2];
  uint local_res18 [2];
  HKEY local_res20;
  _SYSTEM_INFO local_48;
  
  local_res20 = (HKEY)0x0;
  local_48.u.dwOemId = 0;
  local_48.dwPageSize = 0;
  local_48.lpMinimumApplicationAddress = (LPVOID)0x0;
  local_48.lpMaximumApplicationAddress = (LPVOID)0x0;
  local_48.dwActiveProcessorMask = 0;
  local_48.dwNumberOfProcessors = 0;
  local_48.dwProcessorType = 0;
  local_48.dwAllocationGranularity = 0;
  local_48.wProcessorLevel = 0;
  local_48.wProcessorRevision = 0;
  GetSystemInfo(&local_48);
  uVar2 = RegOpenKeyExW((HKEY)0xffffffff80000002,L"System\\CurrentControlSet\\Control\\Lsa",0,1,
                        &local_res20);
  if ((uVar2 == 0) && (local_res20 != (HKEY)0x0)) {
    local_res18[0] = 2;
    local_res8[0] = 4;
    local_res10[0] = 4;
    LVar3 = RegQueryValueExW(local_res20,L"MaxAsyncWorkerThreadsPerCpu",(LPDWORD)0x0,local_res8,
                             (LPBYTE)local_res18,local_res10);
    if ((((LVar3 != 0) || (local_res8[0] != 4)) || (local_res10[0] != 4)) ||
       ((local_res18[0] == 0 ||
        (uVar5 = (ulonglong)local_48.dwNumberOfProcessors * (ulonglong)local_res18[0],
        0xffffffff < uVar5)))) goto LAB_140002bbd;
    if (DebugInfoLevel == 0) goto LAB_140002bf0;
    pcVar4 = "%S reg value is valid, setting %d max async worker threads.\n";
  }
  else {
    if (DebugInfoLevel != 0) {
      LsapDebugOut(2,"RegOpenKeyEx(%S) failed: %d\n",L"System\\CurrentControlSet\\Control\\Lsa",
                   (ulonglong)uVar2);
    }
LAB_140002bbd:
    uVar1 = (ulonglong)local_48.dwNumberOfProcessors * 2;
    uVar5 = local_48._32_8_;
    if (uVar1 < 0x100000000) {
      uVar5 = uVar1;
    }
    uVar5 = uVar5 & 0xffffffff;
    if (DebugInfoLevel == 0) goto LAB_140002bf0;
    pcVar4 = "%S reg value is missing or invalid, setting %d max async worker threads.\n";
  }
  LsapDebugOut(4,pcVar4,L"MaxAsyncWorkerThreadsPerCpu",uVar5 & 0xffffffff);
LAB_140002bf0:
  return uVar5 & 0xffffffff;
}



===== LsapLookupRpcInit @ 140002c00 =====

uint LsapLookupRpcInit(void)

{
  void *pvVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  undefined8 in_R9;
  void *pvVar5;
  void *local_res8;
  void *local_res10;
  
  local_res8 = (void *)0x0;
  local_res10 = (void *)0x0;
  uVar2 = LsapMakePipeSD((longlong *)&local_res8);
  if ((int)uVar2 < 0) {
    if (DebugInfoLevel != 0) {
      LsapDebugOut(1,"LsapRPCInit: failed to build pipe SD: 0x%lx\n",(ulonglong)uVar2,in_R9);
    }
    return uVar2;
  }
  pvVar5 = local_res8;
  uVar3 = RpcServerUseProtseqEpW((RPC_WSTR)L"ncacn_np",10,(RPC_WSTR)L"\\pipe\\lsass",local_res8);
  uVar2 = 0;
  if (uVar3 != 0x6cc) {
    uVar2 = uVar3;
  }
  LsapFreeLsaHeap(local_res8);
  if (uVar2 == 0) {
    uVar2 = LsapMakeLowBoxRpcSD(&local_res10);
    pvVar1 = local_res10;
    if ((int)uVar2 < 0) {
      if (DebugInfoLevel == 0) {
        return uVar2;
      }
      LsapDebugOut(1,"LsapLookupRpcInit: LsapMakeLowBoxRpcSD failed %#x\n",(ulonglong)uVar2,pvVar5);
      return uVar2;
    }
    pvVar5 = local_res10;
    uVar2 = RpcServerUseProtseqEpW((RPC_WSTR)L"ncalrpc",10,(RPC_WSTR)L"lsapolicylookup",local_res10)
    ;
    if (uVar2 != 0) {
      if (DebugInfoLevel != 0) {
        LsapDebugOut(1,"LsapRPCInit: RpcServerUseProtseqEp failed for ncalrpc: 0x%lx\n",
                     (ulonglong)uVar2,pvVar5);
      }
      LsapFreeLsaHeap(pvVar1);
      uVar2 = I_RpcMapWin32Status(uVar2);
      return uVar2;
    }
    pvVar5 = (void *)0x31;
    uVar2 = RpcServerRegisterIf3(&DAT_140007360,0,0,0x31,0x4d2,0x100000,LsaRpcIfCallbackFn,pvVar1);
    LsapFreeLsaHeap(pvVar1);
    if (uVar2 == 0) {
      return 0;
    }
    if (DebugInfoLevel == 0) goto LAB_140002ca5;
    pcVar4 = "LsapRPCInit: RpcServerRegisterIf2 failed: 0x%lx\n";
  }
  else {
    if (DebugInfoLevel == 0) goto LAB_140002ca5;
    pcVar4 = "LsapRPCInit: RpcServerUseProtseqEpW failed: 0x%lx\n";
  }
  LsapDebugOut(1,pcVar4,(ulonglong)uVar2,pvVar5);
LAB_140002ca5:
  uVar2 = I_RpcMapWin32Status(uVar2);
  return uVar2;
}



===== _wsetargv @ 140002dcc =====

int __cdecl _wsetargv(void)

{
  return 0;
}



===== __wmainCRTStartup @ 140002dd8 =====

undefined8 __wmainCRTStartup(void)

{
  int iVar1;
  wchar_t *local_res18;
  wchar_t *local_res20;
  
  local_res18 = (wchar_t *)0x0;
  local_res20 = (wchar_t *)0x0;
  iVar1 = _initterm_e(&__xi_a,&__xi_z);
  if (iVar1 == 0) {
    _wsetargv();
    _initterm(&__xc_a,&__xc_z);
    iVar1 = wmain(0,&local_res18,&local_res20);
                    /* WARNING: Subroutine does not return */
    exit(iVar1);
  }
  return 0xff;
}



===== entry @ 140002e60 =====

void entry(void)

{
  __security_init_cookie();
  __wmainCRTStartup();
  return;
}



===== _initterm_e @ 140002e86 =====

void _initterm_e(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140002e86. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _initterm_e();
  return;
}



===== _initterm @ 140002e92 =====

void _initterm(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140002e92. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _initterm();
  return;
}



===== __security_init_cookie @ 140002ea0 =====

void __cdecl __security_init_cookie(void)

{
  DWORD DVar1;
  _FILETIME local_res8;
  LARGE_INTEGER local_res10;
  _FILETIME local_res18;
  
  local_res18.dwLowDateTime = 0;
  local_res18.dwHighDateTime = 0;
  local_res10.QuadPart = 0;
  if (__security_cookie == 0x2b992ddfa232) {
    GetSystemTimeAsFileTime(&local_res18);
    local_res8 = local_res18;
    DVar1 = GetCurrentProcessId();
    local_res8 = (_FILETIME)((ulonglong)local_res8 ^ (ulonglong)DVar1);
    DVar1 = GetCurrentThreadId();
    local_res8 = (_FILETIME)((ulonglong)local_res8 ^ (ulonglong)DVar1);
    DVar1 = GetTickCount();
    local_res8 = (_FILETIME)((ulonglong)local_res8 ^ (ulonglong)DVar1 << 0x18);
    DVar1 = GetTickCount();
    local_res8 = (_FILETIME)((ulonglong)DVar1 ^ (ulonglong)local_res8 ^ (ulonglong)&local_res8);
    QueryPerformanceCounter(&local_res10);
    __security_cookie =
         (local_res10.QuadPart << 0x20 ^ local_res10.QuadPart ^ (ulonglong)local_res8) &
         0xffffffffffff;
    if (__security_cookie == 0x2b992ddfa232) {
      __security_cookie = 0x2b992ddfa233;
    }
  }
  __security_cookie_complement = ~__security_cookie;
  return;
}



===== __raise_securityfailure @ 140002f80 =====

void __raise_securityfailure(_EXCEPTION_POINTERS *param_1)

{
  HANDLE pvVar1;
  
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  UnhandledExceptionFilter(param_1);
  pvVar1 = GetCurrentProcess();
                    /* WARNING: Could not recover jumptable at 0x000140002fad. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  TerminateProcess(pvVar1,0xc0000409);
  return;
}



===== __report_gsfailure @ 140002fc0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  DWORD64 ControlPc;
  PRUNTIME_FUNCTION FunctionEntry;
  ulonglong local_38 [2];
  PVOID local_28;
  undefined8 uStack_20;
  undefined8 uStack_18;
  
  local_38[1] = 0;
  local_28 = (PVOID)0x0;
  local_38[0] = 0;
  RtlCaptureContext(&DAT_14000d180);
  ControlPc = DAT_14000d278;
  FunctionEntry = RtlLookupFunctionEntry(DAT_14000d278,local_38,(PUNWIND_HISTORY_TABLE)0x0);
  if (FunctionEntry == (PRUNTIME_FUNCTION)0x0) {
    DAT_14000d278 = *DAT_14000d218;
    DAT_14000d218 = DAT_14000d218 + 1;
  }
  else {
    RtlVirtualUnwind(0,local_38[0],ControlPc,FunctionEntry,(PCONTEXT)&DAT_14000d180,&local_28,
                     local_38 + 1,(PKNONVOLATILE_CONTEXT_POINTERS)0x0);
  }
  _DAT_14000d0f0 = DAT_14000d278;
  _DAT_14000d0e0 = 0xc0000409;
  _DAT_14000d0e4 = 1;
  _DAT_14000d0f8 = 3;
  DAT_14000d100 = 2;
  DAT_14000d108 = __security_cookie;
  DAT_14000d110 = __security_cookie_complement;
  uStack_20 = __security_cookie;
  uStack_18 = __security_cookie_complement;
  _DAT_14000d200 = _StackCookie;
  __raise_securityfailure((_EXCEPTION_POINTERS *)&PTR_DAT_140007000);
  return;
}



===== NdrServerCallAll @ 140003170 =====

void __stdcall NdrServerCallAll(PRPC_MESSAGE pRpcMsg)

{
                    /* WARNING: Could not recover jumptable at 0x000140003170. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  NdrServerCallAll(pRpcMsg);
  return;
}



===== NdrServerCall2 @ 140003180 =====

void __stdcall NdrServerCall2(PRPC_MESSAGE pRpcMsg)

{
                    /* WARNING: Could not recover jumptable at 0x000140003180. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  NdrServerCall2(pRpcMsg);
  return;
}



===== __tailMerge_sspisrv_dll @ 140003186 =====

void __tailMerge_sspisrv_dll
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 in_RAX;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 in_RDX;
  undefined8 in_XMM2_Qa;
  undefined8 in_XMM3_Qa;
  
  UNRECOVERED_JUMPTABLE = (code *)__delayLoadHelper2(&ImgDelayDescr_14000b0e8,in_RAX);
                    /* WARNING: Could not recover jumptable at 0x0001400031fd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(param_1,in_RDX,in_XMM2_Qa,in_XMM3_Qa);
  return;
}



===== DelayLoad_SspiSrvInitialize @ 140003205 =====

void DelayLoad_SspiSrvInitialize
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_sspisrv_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_SspiSrvClientCallback @ 140003217 =====

void DelayLoad_SspiSrvClientCallback
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_sspisrv_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_SspirProcessSecurityContext @ 140003229 =====

void DelayLoad_SspirProcessSecurityContext
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_sspisrv_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_SspirDeleteSecurityContext @ 14000323b =====

void DelayLoad_SspirDeleteSecurityContext
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_sspisrv_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_SspirAcquireCredentialsHandle @ 14000324d =====

void DelayLoad_SspirAcquireCredentialsHandle
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_sspisrv_dll(param_1,param_2,param_3,param_4);
  return;
}



===== LsapDebugOut @ 140003260 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void LsapDebugOut(uint param_1,char *param_2,undefined8 param_3,undefined8 param_4)

{
  errno_t eVar1;
  int iVar2;
  ulonglong uVar3;
  uint uVar4;
  char *pcVar5;
  undefined8 local_res18;
  undefined8 local_res20;
  undefined1 auStackY_168 [32];
  char local_128 [256];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_168;
  if ((DebugInfoLevel & param_1) != 0) {
    if ((param_1 & 1) == 0) {
      if ((param_1 & 2) == 0) {
        uVar4 = ((byte)~(byte)param_1 & 4 | 8) >> 2;
      }
      else {
        uVar4 = 1;
      }
    }
    else {
      uVar4 = 0;
    }
    local_res18 = param_3;
    local_res20 = param_4;
    eVar1 = strcpy_s(local_128,0x80,DebugComponentName);
    if (eVar1 == 0) {
      uVar3 = 0xffffffffffffffff;
      do {
        uVar3 = uVar3 + 1;
      } while (DebugComponentName[uVar3] != '\0');
      iVar2 = (int)uVar3;
      local_128[uVar3 & 0xffffffff] = ':';
      local_128[iVar2 + 1] = ' ';
      local_128[iVar2 + 2] = ' ';
      uVar3 = (ulonglong)(iVar2 + 3);
      iVar2 = _vsnprintf_s(local_128 + uVar3,0x100 - uVar3,0xff - uVar3,param_2,
                           (va_list)&local_res18);
      if (-1 < iVar2) {
        DbgPrintEx(DebugDpfltrId,uVar4,local_128);
        return;
      }
      pcVar5 = "Error printing message\n";
    }
    else {
      pcVar5 = "Error printing message: Bad ComponentName\n";
    }
    DbgPrintEx(DebugDpfltrId,0,pcVar5);
  }
  return;
}



===== FixupEnvironment @ 1400033a4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FixupEnvironment(void)

{
  DWORD DVar1;
  ulonglong uVar2;
  undefined8 in_R9;
  undefined1 auStack_258 [32];
  wchar_t local_238 [8];
  WCHAR local_228 [2];
  wchar_t awStack_224 [6];
  undefined4 auStack_218 [128];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_258;
  builtin_wcsncpy(local_238,L"\\System3",8);
  DVar1 = GetEnvironmentVariableW(L"SystemRoot",local_228,0x104);
  if ((DVar1 != 0) && (9 < 0x105 - DVar1)) {
    uVar2 = (ulonglong)DVar1;
    *(undefined4 *)(local_228 + uVar2) = local_238._0_4_;
    *(undefined4 *)(awStack_224 + uVar2) = local_238._4_4_;
    *(undefined4 *)(awStack_224 + uVar2 + 2) = local_238._8_4_;
    *(undefined4 *)(awStack_224 + uVar2 + 4) = local_238._12_4_;
    *(undefined4 *)((longlong)auStack_218 + uVar2 * 2) = 0x32;
    if (DebugInfoLevel != 0) {
      LsapDebugOut(4,"FixupEnvironment: Setting PATH to %ws\n",local_228,in_R9);
    }
    SetEnvironmentVariableW(L"Path",local_228);
  }
  return;
}



===== LsapActivateRpcServer @ 140003468 =====

undefined8 LsapActivateRpcServer(void)

{
  RPC_STATUS Status;
  DWORD DVar1;
  HANDLE hEvent;
  
  Status = RpcServerListen(1,0x4d2,1);
  I_RpcMapWin32Status(Status);
  hEvent = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,L"LSA_RPC_SERVER_ACTIVE");
  if (hEvent == (HANDLE)0x0) {
    DVar1 = GetLastError();
    if (DVar1 != 0xb7) {
      return 0;
    }
    hEvent = OpenEventW(0x40000000,0,L"LSA_RPC_SERVER_ACTIVE");
    if (hEvent == (HANDLE)0x0) {
      return 0;
    }
  }
  SetEvent(hEvent);
  return 0;
}



===== LsapInitializeGlobals @ 140003504 =====

uint LsapInitializeGlobals(void)

{
  uint uVar1;
  undefined8 uVar2;
  char *pcVar3;
  ulonglong uVar4;
  undefined8 in_R9;
  
  uVar1 = LsapBuildWellKnownSids();
  if ((int)uVar1 < 0) {
    if (DebugInfoLevel == 0) {
      return uVar1;
    }
    uVar4 = (ulonglong)uVar1;
    pcVar3 = "Failed to init well known SIDs: 0x%x\n";
  }
  else {
    uVar1 = LsapBuildSD();
    if ((int)uVar1 < 0) {
      if (DebugInfoLevel == 0) {
        return uVar1;
      }
      uVar4 = (ulonglong)uVar1;
      pcVar3 = "Failed to set Ksec security: 0x%x\n";
    }
    else {
      RtlInitializeResource();
      DAT_14000d748 = &gLsapIfList;
      gLsapIfList = &gLsapIfList;
      DAT_14000d7c8 = &gLsapExtensionList;
      gLsapExtensionList = &gLsapExtensionList;
      LOCK();
      gHasInitLsaIfConfig = gHasInitLsaIfConfig | 2;
      UNLOCK();
      uVar2 = LsapRegisterInterface(0,0,&gLsapRmFunctions);
      uVar1 = (uint)uVar2;
      if (-1 < (int)uVar1) {
        uVar2 = LsapRegisterInterface(0,1,&gLsapCallbackFunctions);
        uVar1 = (uint)uVar2;
      }
      if (-1 < (int)uVar1) {
        return uVar1;
      }
      if (DebugInfoLevel == 0) {
        return uVar1;
      }
      uVar4 = (ulonglong)uVar1;
      pcVar3 = "Failed to init LSA interface list: 0x%x\n";
    }
  }
  LsapDebugOut(1,pcVar3,uVar4,in_R9);
  return uVar1;
}



===== LsapMakeLowBoxRpcSD @ 1400035fc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int LsapMakeLowBoxRpcSD(undefined8 *param_1)

{
  int iVar1;
  undefined1 auStack_1b8 [32];
  undefined8 *local_198;
  undefined4 local_190;
  undefined4 local_188;
  undefined4 local_180;
  undefined4 local_178;
  undefined4 local_170;
  longlong *local_168;
  longlong local_158;
  longlong local_150;
  longlong local_148;
  longlong local_140;
  longlong local_138;
  longlong local_130;
  undefined1 *local_128;
  undefined8 local_120;
  undefined8 local_118;
  wchar_t *local_110;
  undefined4 local_108;
  undefined2 local_104;
  undefined4 local_100;
  undefined2 local_fc;
  undefined4 local_f8;
  undefined2 local_f4;
  undefined4 local_f0;
  undefined2 local_ec;
  undefined2 local_e8;
  undefined1 local_e6;
  undefined4 local_e4;
  longlong *local_e0;
  undefined2 local_d8;
  undefined1 local_d6;
  undefined4 local_d4;
  longlong *local_d0;
  undefined2 local_c8;
  undefined1 local_c6;
  undefined4 local_c4;
  longlong *local_c0;
  undefined2 local_b8;
  undefined1 local_b6;
  undefined4 local_b4;
  longlong *local_b0;
  undefined2 local_a8;
  undefined1 local_a6;
  undefined4 local_a4;
  longlong *local_a0;
  undefined2 local_98;
  undefined1 local_96;
  undefined4 local_94;
  longlong *local_90;
  undefined2 local_88;
  undefined1 local_86;
  undefined4 local_84;
  undefined1 **local_80;
  undefined1 local_78 [48];
  undefined1 local_48 [48];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_1b8;
  local_fc = 0x100;
  local_158 = 0;
  local_c4 = 0x80000000;
  local_94 = 0x80000000;
  local_e4 = 0xe0000000;
  local_110 = L"lpacIdentityServices";
  local_d4 = 0xe0000000;
  local_e0 = &local_158;
  local_d0 = &local_150;
  local_b4 = 0x10000000;
  local_c0 = &local_148;
  local_a4 = 0x10000000;
  local_b0 = &local_140;
  local_84 = 0x80000000;
  local_a0 = &local_138;
  local_150 = 0;
  local_90 = &local_130;
  local_80 = &local_128;
  local_168 = &local_158;
  local_170 = 0;
  local_178 = 0;
  local_180 = 0;
  local_188 = 0;
  local_190 = 0;
  local_198 = (undefined8 *)((ulonglong)local_198 & 0xffffffff00000000);
  local_140 = 0;
  local_138 = 0;
  local_130 = 0;
  local_148 = 0;
  local_128 = (undefined1 *)0x0;
  local_120 = 0;
  local_100 = 0;
  local_108 = 0;
  local_104 = 0x500;
  local_f8 = 0;
  local_f4 = 0x300;
  local_f0 = 0;
  local_ec = 0xf00;
  local_118 = 0x2a0028;
  local_e8 = 0;
  local_e6 = 0;
  local_d8 = 1;
  local_d6 = 0;
  local_c8 = 0;
  local_c6 = 0;
  local_b8 = 0;
  local_b6 = 0;
  local_a8 = 0;
  local_a6 = 0;
  local_98 = 0;
  local_96 = 0;
  local_88 = 0;
  local_86 = 0;
  iVar1 = RtlAllocateAndInitializeSid(&local_100,0x80000001,0,0);
  if (-1 < iVar1) {
    local_168 = &local_150;
    local_170 = 0;
    local_178 = 0;
    local_180 = 0;
    local_188 = 0;
    local_190 = 0;
    local_198 = (undefined8 *)((ulonglong)local_198 & 0xffffffff00000000);
    iVar1 = RtlAllocateAndInitializeSid(&local_108,1,0xc,0);
    if (-1 < iVar1) {
      local_168 = &local_148;
      local_170 = 0;
      local_178 = 0;
      local_180 = 0;
      local_188 = 0;
      local_190 = 0;
      local_198 = (undefined8 *)((ulonglong)local_198 & 0xffffffff00000000);
      iVar1 = RtlAllocateAndInitializeSid(&local_108,1,7,0);
      if (-1 < iVar1) {
        local_168 = &local_140;
        local_170 = 0;
        local_178 = 0;
        local_180 = 0;
        local_188 = 0;
        local_190 = 0;
        local_198 = (undefined8 *)((ulonglong)local_198 & 0xffffffff00000000);
        iVar1 = RtlAllocateAndInitializeSid(&local_108,2,0x20,0x220);
        if (-1 < iVar1) {
          local_168 = &local_138;
          local_170 = 0;
          local_178 = 0;
          local_180 = 0;
          local_188 = 0;
          local_190 = 0;
          local_198 = (undefined8 *)((ulonglong)local_198 & 0xffffffff00000000);
          iVar1 = RtlAllocateAndInitializeSid(&local_f8,1,4,0);
          if (-1 < iVar1) {
            local_168 = &local_130;
            local_170 = 0;
            local_178 = 0;
            local_180 = 0;
            local_188 = 0;
            local_190 = 0;
            local_198 = (undefined8 *)((ulonglong)local_198 & 0xffffffff00000000);
            iVar1 = RtlAllocateAndInitializeSid(&local_f0,2,2,1);
            if (-1 < iVar1) {
              iVar1 = RtlDeriveCapabilitySidsFromName(&local_118,local_48,local_78);
              if (-1 < iVar1) {
                local_128 = local_78;
                local_198 = &local_120;
                iVar1 = RtlCreateAndSetSD(&local_e8,7,0,0);
                if (-1 < iVar1) {
                  *param_1 = local_120;
                }
              }
            }
          }
        }
      }
    }
  }
  if (local_158 != 0) {
    RtlFreeSid();
  }
  if (local_150 != 0) {
    RtlFreeSid();
  }
  if (local_148 != 0) {
    RtlFreeSid();
  }
  if (local_140 != 0) {
    RtlFreeSid();
  }
  if (local_138 != 0) {
    RtlFreeSid();
  }
  if (local_130 != 0) {
    RtlFreeSid();
  }
  return iVar1;
}



===== LsapOpenKsec @ 1400039cc =====

ulonglong LsapOpenKsec(void)

{
  uint uVar1;
  undefined4 extraout_var;
  char *pcVar2;
  undefined8 *puVar3;
  ulonglong uVar4;
  undefined4 *puVar5;
  undefined8 *puVar6;
  undefined4 local_res8 [2];
  undefined8 in_stack_ffffffffffffff78;
  undefined4 uVar7;
  undefined8 local_58;
  undefined8 uStack_50;
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
  
  uVar7 = (undefined4)((ulonglong)in_stack_ffffffffffffff78 >> 0x20);
  local_1c = 0;
  local_34 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  RtlInitUnicodeString(&local_58,L"\\Device\\KsecDD");
  local_28 = &local_58;
  local_30 = 0;
  local_20 = 0;
  local_38 = 0x30;
  local_18 = 0;
  uStack_10 = 0;
  uVar1 = NtOpenFile(&KsecDevice,0xc0000000,&local_38,&local_48,CONCAT44(uVar7,3),0);
  uVar4 = (ulonglong)uVar1;
  if ((int)uVar1 < 0) {
    if (DebugInfoLevel != 0) {
      LsapDebugOut(1,"FAILED to open %ws, status %x\n",uStack_50,(ulonglong)uVar1);
    }
  }
  else {
    puVar6 = (undefined8 *)0x0;
    uVar1 = NtDeviceIoControlFile(KsecDevice,0,0,0,&local_48,0x398000,0,0,&LsapSystemProcessId,4);
    uVar4 = (ulonglong)uVar1;
    if ((int)uVar1 < 0) {
      if (DebugInfoLevel == 0) {
        return uVar4;
      }
      pcVar2 = "FAILED to send ioctl, status %x\n";
    }
    else {
      puVar5 = local_res8;
      puVar6 = (undefined8 *)0x4;
      local_res8[0] = 6;
      puVar3 = &local_48;
      uVar1 = NtSetInformationFile(KsecDevice);
      uVar4 = (ulonglong)uVar1;
      if (-1 < (int)uVar1) {
        uVar1 = InitializeAsyncKsec(&local_38,puVar3,puVar5,puVar6);
        return CONCAT44(extraout_var,uVar1);
      }
      if (DebugInfoLevel == 0) {
        return uVar4;
      }
      pcVar2 = "Failed to set IOCTL completion modes: 0x%lx\n";
    }
    LsapDebugOut(1,pcVar2,uVar4,puVar6);
  }
  return uVar4;
}



===== SetKsecEvent @ 140003b64 =====

undefined8 SetKsecEvent(void)

{
  DWORD DVar1;
  BOOL BVar2;
  HANDLE hEvent;
  undefined8 uVar3;
  undefined8 in_R9;
  
  hEvent = (HANDLE)SpmOpenEvent();
  uVar3 = 0;
  if (hEvent == (HANDLE)0x0) {
    if (DebugInfoLevel != 0) {
      DVar1 = GetLastError();
      LsapDebugOut(1,"SetKsecEvent: Could not open event %ws: %lu\n",
                   L"\\SECURITY\\LSA_AUTHENTICATION_INITIALIZED",(ulonglong)DVar1);
    }
    uVar3 = 0xc0000008;
  }
  else {
    BVar2 = SetEvent(hEvent);
    if (BVar2 == 0) {
      if (DebugInfoLevel != 0) {
        DVar1 = GetLastError();
        LsapDebugOut(1,"SetKsecEvent: Failed to set ksec event: %lu\n",(ulonglong)DVar1,in_R9);
      }
      uVar3 = 0xc0000008;
    }
    CloseHandle(hEvent);
  }
  return uVar3;
}



===== wmain @ 140003c14 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

int __cdecl wmain(int _Argc,wchar_t **_Argv,wchar_t **_Env)

{
  UINT dwExitCode;
  DWORD DVar1;
  int iVar2;
  undefined4 uVar3;
  ulonglong uVar4;
  HANDLE hEvent;
  char *pcVar5;
  undefined8 **ppuVar6;
  undefined8 uVar7;
  undefined4 local_res8 [2];
  undefined4 local_res10;
  undefined8 local_res18;
  
  local_res10 = 0;
  local_res8[0] = 0;
  local_res18 = 0;
  DebugInfoLevel = 0;
  DebugComponentName = "LSA";
  DebugDpfltrId = 0x8a;
  SetErrorMode(1);
  SetUnhandledExceptionFilter(RtlUnhandledExceptionFilter_exref);
  RtlSetProcessIsCritical(1,0,1);
  WerSetFlags(0x786);
  if ((*(byte *)((longlong)ProcessEnvironmentBlock + 3) & 2) != 0) {
    local_res18 = 0x100000002;
    dwExitCode = NtSetInformationProcess(0xffffffffffffffff,0x34,&local_res18,8);
    if (((dwExitCode + 0x80000000 & 0x80000000) == 0) && (dwExitCode != 0xc00000bb))
    goto LAB_140003f3f;
  }
  local_res8[0] = 1;
  dwExitCode = NtSetInformationProcess(0xffffffffffffffff,0x36,local_res8,4);
  if ((int)dwExitCode < 0) goto LAB_140003f3f;
  uVar7 = 4;
  local_res10 = 9;
  dwExitCode = NtSetInformationProcess(0xffffffffffffffff,5);
  if ((int)dwExitCode < 0) goto LAB_140003f3f;
  FixupEnvironment();
  dwExitCode = LsapInitializeGlobals();
  if ((int)dwExitCode < 0) {
    if (DebugInfoLevel == 0) goto LAB_140003f3f;
    uVar4 = (ulonglong)dwExitCode;
    pcVar5 = "Failed to init Lsass global states: 0x%x\n";
  }
  else {
    dwExitCode = LsapRmInitializeServer();
    if ((int)dwExitCode < 0) {
      if (DebugInfoLevel == 0) goto LAB_140003f3f;
      uVar4 = (ulonglong)dwExitCode;
      pcVar5 = "Failed to init RM: 0x%x\n";
    }
    else {
      DVar1 = LsapLoadRequiredExtensions();
      if (DVar1 == 0) {
        DVar1 = LsapLoadLsaInterfaces();
        if (DVar1 != 0) goto LAB_140003f12;
        dwExitCode = LsapLookupRpcInit();
        if ((int)dwExitCode < 0) goto LAB_140003f3f;
        dwExitCode = SspiSrvInitialize();
        if ((int)dwExitCode < 0) goto LAB_140003f3f;
        uVar4 = LsapOpenKsec();
        dwExitCode = (UINT)uVar4;
        if ((int)dwExitCode < 0) {
          if (DebugInfoLevel == 0) goto LAB_140003f3f;
          uVar4 = uVar4 & 0xffffffff;
          pcVar5 = "LsapOpenKsec failed: 0x%lx\n";
          goto LAB_140003f38;
        }
        uVar4 = SetKsecEvent();
        dwExitCode = (UINT)uVar4;
        if ((int)dwExitCode < 0) {
          if (DebugInfoLevel == 0) goto LAB_140003f3f;
          uVar4 = uVar4 & 0xffffffff;
          pcVar5 = "SetKsecEvent failed: 0x%lx\n";
          goto LAB_140003f38;
        }
        uVar4 = LsapActivateRpcServer();
        dwExitCode = (UINT)uVar4;
        uVar4 = uVar4 & 0xffffffff;
        if (-1 < (int)dwExitCode) {
          for (ppuVar6 = (undefined8 **)gLsapExtensionList; ppuVar6 != &gLsapExtensionList;
              ppuVar6 = (undefined8 **)*ppuVar6) {
            if (*(int *)(ppuVar6 + 7) == 1) {
              iVar2 = (*(code *)ppuVar6[9])();
              if (iVar2 < 0) {
                *(int *)(ppuVar6 + 8) = iVar2;
                uVar3 = RtlNtStatusToDosError();
                *(undefined4 *)((longlong)ppuVar6 + 0x3c) = uVar3;
              }
              else {
                *(undefined4 *)(ppuVar6 + 7) = 2;
              }
            }
          }
          LsapStartExtensions();
          hEvent = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,L"LSA_SUBSYSTEM_INITIALIZED");
          if (hEvent == (HANDLE)0x0) {
            DVar1 = GetLastError();
            if (DVar1 != 0xb7) goto LAB_140003f03;
            hEvent = OpenEventW(0x40000000,0,L"LSA_SUBSYSTEM_INITIALIZED");
            if (hEvent == (HANDLE)0x0) goto LAB_140003f03;
          }
          SetEvent(hEvent);
LAB_140003f03:
                    /* WARNING: Subroutine does not return */
          ExitThread(dwExitCode);
        }
        if (DebugInfoLevel == 0) goto LAB_140003f3f;
        pcVar5 = "Failed to start LPR server: 0x%lx\n";
      }
      else {
LAB_140003f12:
        SetLastError(DVar1);
        uVar4 = 0xc0000001;
        dwExitCode = 0xc0000001;
        if (DebugInfoLevel == 0) goto LAB_140003f3f;
        pcVar5 = "Failed to load extensions: 0x%x\n";
      }
      dwExitCode = (UINT)uVar4;
    }
  }
LAB_140003f38:
  LsapDebugOut(1,pcVar5,uVar4,uVar7);
LAB_140003f3f:
                    /* WARNING: Subroutine does not return */
  ExitProcess(dwExitCode);
}



===== LsaGetInterface @ 140003f60 =====

undefined8 LsaGetInterface(int param_1,longlong *param_2)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  
                    /* 0x3f60  1  LsaGetInterface */
  uVar1 = 0;
  if (param_2 == (longlong *)0x0) {
    uVar1 = 0xc000000d;
  }
  else {
    *param_2 = 0;
    if (gHasInitLsaIfConfig == 0) {
      uVar1 = 0xc00000e5;
    }
    else {
      RtlAcquireResourceShared(&gLsaIfLock,1);
      puVar2 = LsapFindRegisteredInterface(param_1);
      if ((puVar2 == (undefined8 *)0x0) || (puVar2[6] == 0)) {
        uVar1 = 0xc0000225;
      }
      else {
        *param_2 = puVar2[6];
      }
      RtlReleaseResource(&gLsaIfLock);
    }
  }
  return uVar1;
}



===== LsaRegisterExtension @ 140004000 =====

undefined8 LsaRegisterExtension(int param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
                    /* 0x4000  3  LsaRegisterExtension */
  uVar1 = 0;
  if (param_1 == 0) {
    gLsapRmExtension = param_2;
    return uVar1;
  }
  if (param_1 == 2) {
    gLsapSspiExtension = param_2;
    return uVar1;
  }
  if (param_1 == 3) {
    gLsapLookupExtension = param_2;
    return uVar1;
  }
  return 0xc000000d;
}



===== LsaRegisterInterface @ 140004040 =====

void LsaRegisterInterface(int param_1,undefined8 param_2)

{
                    /* 0x4040  4  LsaRegisterInterface */
  LsapRegisterInterface(0,param_1,param_2);
  return;
}



===== LsapCreateLsaExtension @ 140004054 =====

undefined4 LsapCreateLsaExtension(void *param_1,longlong *param_2)

{
  short sVar1;
  ushort uVar2;
  longlong lVar3;
  longlong lVar4;
  void *_Dst;
  undefined4 uVar5;
  
  uVar5 = 0;
  lVar3 = LsapAllocateLsaHeap(0x58);
  if (lVar3 == 0) {
    uVar5 = 8;
  }
  else {
    *(longlong *)(lVar3 + 8) = lVar3;
    *(longlong *)lVar3 = lVar3;
    *(undefined8 *)(lVar3 + 0x3c) = 0;
    *(undefined4 *)(lVar3 + 0x38) = 0;
    lVar4 = -1;
    do {
      lVar4 = lVar4 + 1;
    } while (*(short *)((longlong)param_1 + lVar4 * 2) != 0);
    sVar1 = (short)lVar4 * 2;
    *(short *)(lVar3 + 0x20) = sVar1;
    uVar2 = sVar1 + 2;
    *(ushort *)(lVar3 + 0x22) = uVar2;
    _Dst = (void *)LsapAllocateLsaHeap((uint)uVar2);
    *(void **)(lVar3 + 0x28) = _Dst;
    if (_Dst == (void *)0x0) {
      uVar5 = 8;
      LsapFreeLsaHeap(lVar3);
      lVar3 = 0;
    }
    else {
      memcpy(_Dst,param_1,(ulonglong)*(ushort *)(lVar3 + 0x22));
      lVar4 = lVar3 + 0x10;
      *(longlong *)(lVar3 + 0x18) = lVar4;
      *(longlong *)lVar4 = lVar4;
    }
  }
  *param_2 = lVar3;
  return uVar5;
}



===== LsapFindRegisteredInterface @ 14000411c =====

undefined8 * LsapFindRegisteredInterface(int param_1)

{
  undefined8 *puVar1;
  
  puVar1 = gLsapIfList;
  while( true ) {
    if ((undefined8 **)puVar1 == &gLsapIfList) {
      return (undefined8 *)0x0;
    }
    if (*(int *)(puVar1 + 2) == param_1) break;
    puVar1 = (undefined8 *)*puVar1;
  }
  return puVar1;
}



===== LsapLoadExtension @ 140004144 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

DWORD LsapLoadExtension(wchar_t *param_1,undefined8 *param_2)

{
  code *pcVar1;
  int iVar2;
  DWORD DVar3;
  wchar_t *pwVar4;
  HMODULE hModule;
  FARPROC pFVar5;
  FARPROC pFVar6;
  ulonglong uVar7;
  char *pcVar8;
  longlong **pplVar9;
  undefined1 *puVar10;
  longlong **local_res18 [2];
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  
  pplVar9 = (longlong **)0x0;
  local_res18[0] = (longlong **)0x0;
  pwVar4 = wcschr(param_1,L'\\');
  puVar10 = auStack_38;
  if (pwVar4 != (wchar_t *)0x0) {
    DVar3 = 0xd;
    goto LAB_140004329;
  }
  for (pplVar9 = (longlong **)gLsapExtensionList; pplVar9 != &gLsapExtensionList;
      pplVar9 = (longlong **)*pplVar9) {
    iVar2 = _wcsicmp(param_1,(wchar_t *)pplVar9[5]);
    if (iVar2 == 0) {
      local_res18[0] = pplVar9;
      if (pplVar9 != (longlong **)0x0) {
        DVar3 = *(DWORD *)((longlong)pplVar9 + 0x3c);
        if (DVar3 != 0) goto LAB_14000431f;
        if (*(int *)(pplVar9 + 7) != 0) goto LAB_140004329;
        DVar3 = 0x54f;
        goto LAB_14000431f;
      }
      break;
    }
  }
  DVar3 = LsapCreateLsaExtension(param_1,(longlong *)local_res18);
  if (DVar3 == 0) {
    if ((longlong **)*DAT_14000d7c8 != &gLsapExtensionList) {
      pcVar1 = (code *)swi(0x29);
      DAT_14000d7c8 = (longlong *)(*pcVar1)(3);
      puVar10 = auStack_30;
    }
    pplVar9 = *(longlong ***)(puVar10 + 0x50);
    *pplVar9 = (longlong *)&gLsapExtensionList;
    pplVar9[1] = DAT_14000d7c8;
    *DAT_14000d7c8 = (longlong)pplVar9;
    *(undefined8 *)(puVar10 + -8) = 0x140004223;
    DAT_14000d7c8 = (longlong *)pplVar9;
    hModule = LoadLibraryExW(param_1,(HANDLE)0x0,0);
    if (hModule == (HMODULE)0x0) {
      *(undefined8 *)(puVar10 + -8) = 0x140004237;
      DVar3 = GetLastError();
      if (DebugInfoLevel != 0) {
        pcVar8 = "LsapLoadLsaExtension: Can\'t load library for %ws: %lu\n";
LAB_140004252:
        *(undefined8 *)(puVar10 + -8) = 0x140004262;
        LsapDebugOut(1,pcVar8,param_1,(ulonglong)DVar3);
      }
    }
    else {
      pplVar9[6] = (longlong *)hModule;
      *(undefined8 *)(puVar10 + -8) = 0x14000427c;
      pFVar5 = GetProcAddress(hModule,"InitializeLsaExtension");
      if (pFVar5 == (FARPROC)0x0) {
        *(undefined8 *)(puVar10 + -8) = 0x140004290;
        DVar3 = GetLastError();
        if (DebugInfoLevel != 0) {
          pcVar8 = "LsaInitializeExtension: Can\'t get init routine for %ws: %lu\n";
          goto LAB_140004252;
        }
      }
      else {
        pplVar9[9] = (longlong *)pFVar5;
        *(undefined8 *)(puVar10 + -8) = 0x1400042bd;
        pFVar6 = GetProcAddress(hModule,"QueryLsaInterface");
        pplVar9[10] = (longlong *)pFVar6;
        *(undefined8 *)(puVar10 + -8) = 0x1400042d0;
        uVar7 = (*pFVar5)(0);
        if (-1 < (int)uVar7) {
          *(undefined4 *)(pplVar9 + 7) = 1;
          DVar3 = 0;
          goto LAB_140004329;
        }
        if (DebugInfoLevel != 0) {
          *(undefined8 *)(puVar10 + -8) = 0x1400042f6;
          LsapDebugOut(1,"LsaInitializeExtension: Init routine for %ws failed: 0x%lx\n",param_1,
                       uVar7 & 0xffffffff);
        }
        *(undefined8 *)(puVar10 + -8) = 0x1400042ff;
        DVar3 = RtlNtStatusToDosError(uVar7 & 0xffffffff);
        *(int *)(pplVar9 + 8) = (int)uVar7;
      }
    }
    local_res18[0] = pplVar9;
    if (DVar3 == 0) goto LAB_140004329;
  }
  else {
  }
LAB_14000431f:
  pplVar9 = (longlong **)0x0;
  if (local_res18[0] != (longlong **)0x0) {
    *(DWORD *)((longlong)local_res18[0] + 0x3c) = DVar3;
    pplVar9 = (longlong **)0x0;
  }
LAB_140004329:
  if (param_2 != (undefined8 *)0x0) {
    *param_2 = pplVar9;
  }
  return DVar3;
}



===== LsapLoadExtensionFromRegistry @ 140004350 =====

DWORD LsapLoadExtensionFromRegistry(HKEY param_1,undefined8 *param_2)

{
  DWORD DVar1;
  wchar_t *lpData;
  DWORD local_res10 [2];
  DWORD local_res18 [2];
  
  *param_2 = 0;
  local_res18[0] = 0;
  local_res10[0] = 0;
  DVar1 = RegQueryValueExW(param_1,L"Extension",(LPDWORD)0x0,local_res18,(LPBYTE)0x0,local_res10);
  if (DVar1 == 0) {
    if ((local_res10[0] < 3) || (0x207 < (local_res10[0] & 0xfffffffe))) {
      DVar1 = 0x57;
    }
    else {
      lpData = (wchar_t *)LsapAllocateLsaHeap(local_res10[0]);
      if (lpData == (wchar_t *)0x0) {
        DVar1 = 8;
      }
      else {
        DVar1 = RegQueryValueExW(param_1,L"Extension",(LPDWORD)0x0,local_res18,(LPBYTE)lpData,
                                 local_res10);
        if (DVar1 == 0) {
          if (local_res18[0] == 1) {
            if (((local_res10[0] >> 1) - 2 < 0x102) && (lpData[(local_res10[0] >> 1) - 1] == L'\0'))
            {
              DVar1 = LsapLoadExtension(lpData,param_2);
            }
            else {
              DVar1 = 0xd;
            }
          }
          else {
            DVar1 = 0x70c;
          }
        }
        LsapFreeLsaHeap(lpData);
      }
    }
  }
  return DVar1;
}



===== LsapLoadLsaInterfaces @ 140004470 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint LsapLoadLsaInterfaces(void)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  DWORD DVar4;
  int iVar5;
  undefined8 uVar6;
  uint dwIndex;
  LPDWORD lpcchName;
  undefined1 auStackY_d8 [32];
  DWORD local_98 [2];
  HKEY local_90;
  HKEY local_88;
  longlong local_80;
  longlong local_78 [2];
  WCHAR local_68 [32];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_d8;
  lpcchName = (LPDWORD)0x20019;
  local_88 = (HKEY)0x0;
  local_90 = (HKEY)0x0;
  local_98[0] = 0;
  local_80 = 0;
  uVar2 = RegOpenKeyExW((HKEY)0xffffffff80000002,
                        L"System\\CurrentControlSet\\Control\\LsaExtensionConfig\\Interfaces",0,
                        0x20019,&local_88);
  if (uVar2 == 0) {
    dwIndex = 0;
    while( true ) {
      lpcchName = local_98;
      local_98[0] = 0x20;
      uVar2 = RegEnumKeyExW(local_88,dwIndex,local_68,lpcchName,(LPDWORD)0x0,(LPWSTR)0x0,
                            (LPDWORD)0x0,(PFILETIME)0x0);
      if (uVar2 == 0x103) break;
      if (uVar2 != 0) {
        if (DebugInfoLevel != 0) {
          lpcchName = (LPDWORD)(ulonglong)uVar2;
          LsapDebugOut(1,"RegEnumKeyEx failed at index %u: 0x%X\n",(ulonglong)dwIndex,lpcchName);
        }
        goto LAB_14000468a;
      }
      uVar2 = wcstol(local_68,(wchar_t **)0x0,10);
      if (uVar2 - 0x3e9 < 8999) {
        uVar3 = RegOpenKeyExW(local_88,local_68,0,0x20019,&local_90);
        if (uVar3 == 0) {
          DVar4 = LsapLoadExtensionFromRegistry(local_90,&local_80);
          lVar1 = local_80;
          if (DVar4 == 0) {
            local_78[0] = 0;
            if (((((*(code **)(local_80 + 0x50) == (code *)0x0) ||
                  (iVar5 = (**(code **)(local_80 + 0x50))(uVar2,local_78), iVar5 < 0)) ||
                 (local_78[0] == 0)) ||
                (uVar6 = LsapRegisterInterface(lVar1,uVar2,local_78[0]), (int)uVar6 < 0)) &&
               (DebugInfoLevel != 0)) {
              LsapDebugOut(1,"Ignore failure to load interface %ul from extension %ws: 0x%X\n",
                           (ulonglong)uVar2,*(undefined8 *)(lVar1 + 0x28));
            }
          }
          else if (DebugInfoLevel != 0) {
            LsapDebugOut(1,"Ignore failure to load LSA extension from %ws: 0x%X\n",local_68,
                         (ulonglong)DVar4);
          }
          goto LAB_140004646;
        }
        if (DebugInfoLevel != 0) {
          LsapDebugOut(1,"Ignore failure to open interface reg key %ws: 0x%X\n",local_68,
                       (ulonglong)uVar3);
        }
LAB_14000465b:
        local_90 = (HKEY)0x0;
      }
      else {
LAB_140004646:
        if (local_90 != (HKEY)0x0) {
          RegCloseKey(local_90);
          goto LAB_14000465b;
        }
      }
      dwIndex = dwIndex + 1;
    }
    uVar2 = 0;
  }
LAB_14000468a:
  if (local_88 != (HKEY)0x0) {
    RegCloseKey(local_88);
    local_88 = (HKEY)0x0;
  }
  if ((uVar2 != 0) && (DebugInfoLevel != 0)) {
    LsapDebugOut(1,"LsapLoadLsaInterfaces failed: 0x%X\n",(ulonglong)uVar2,lpcchName);
  }
  return uVar2;
}



===== LsapLoadRequiredExtensions @ 1400046f4 =====

uint LsapLoadRequiredExtensions(void)

{
  uint uVar1;
  int iVar2;
  wchar_t *_Str2;
  char *pcVar3;
  wchar_t *pwVar4;
  LPDWORD lpType;
  DWORD local_res8 [2];
  DWORD local_res10 [2];
  HKEY local_res18;
  
  lpType = (LPDWORD)0x20019;
  local_res18 = (HKEY)0x0;
  local_res10[0] = 0;
  local_res8[0] = 0;
  pwVar4 = (wchar_t *)0x0;
  uVar1 = RegOpenKeyExW((HKEY)0xffffffff80000002,
                        L"System\\CurrentControlSet\\Control\\LsaExtensionConfig\\LsaSrv",0,0x20019,
                        &local_res18);
  if (uVar1 == 0) {
    lpType = local_res10;
    uVar1 = RegQueryValueExW(local_res18,L"Extensions",(LPDWORD)0x0,lpType,(LPBYTE)0x0,local_res8);
    if ((uVar1 == 0) || (uVar1 == 0xea)) {
      if (local_res10[0] == 1) {
        if (1 < local_res8[0]) {
          local_res8[0] = local_res8[0] + 2;
LAB_1400047fb:
          _Str2 = (wchar_t *)LsapAllocateLsaHeap(local_res8[0]);
          pwVar4 = _Str2;
          if (_Str2 == (wchar_t *)0x0) {
            uVar1 = 8;
          }
          else {
            lpType = local_res10;
            uVar1 = RegQueryValueExW(local_res18,L"Extensions",(LPDWORD)0x0,lpType,(LPBYTE)_Str2,
                                     local_res8);
            if (uVar1 == 0) {
              _Str2[(ulonglong)(local_res8[0] >> 1) - 1] = L'\0';
              _Str2[(ulonglong)(local_res8[0] >> 1) - 2] = L'\0';
              pwVar4 = (wchar_t *)0x0;
              for (; *_Str2 != L'\0'; _Str2 = _Str2 + 1) {
                iVar2 = wcsncmp(L"lsasrv.dll",_Str2,10);
                if (iVar2 == 0) {
                  uVar1 = LsapLoadExtension(_Str2,(undefined8 *)0x0);
                  if (uVar1 != 0) break;
                }
                else {
                  LsapLoadExtension(_Str2,(undefined8 *)0x0);
                }
                for (; *_Str2 != L'\0'; _Str2 = _Str2 + 1) {
                }
              }
            }
            else if (DebugInfoLevel != 0) {
              lpType = (LPDWORD)(ulonglong)uVar1;
              LsapDebugOut(1,
                           "LsapLoadRequiredExtensions: RegQueryValueEx for LSA key failed with Size %lu: %lu\n"
                           ,(ulonglong)local_res8[0],lpType);
            }
          }
          goto LAB_140004918;
        }
        if (DebugInfoLevel != 0) {
          pcVar3 = "LsapLoadRequiredExtensions: Bad REG_SZ size for LSA extensions value\n";
LAB_1400047e3:
          LsapDebugOut(1,pcVar3,(ulonglong)local_res10[0],lpType);
        }
      }
      else {
        if (local_res10[0] != 7) {
          if (DebugInfoLevel != 0) {
            LsapDebugOut(1,"LsapLoadRequiredExtensions: Bad reg type %lu for LSA extensions value\n"
                         ,(ulonglong)local_res10[0],lpType);
          }
          uVar1 = 0x65d;
          goto LAB_140004918;
        }
        if (3 < local_res8[0]) goto LAB_1400047fb;
        if (DebugInfoLevel != 0) {
          pcVar3 = "LsapLoadRequiredExtensions: Bad REG_MULTI_SZ size for LSA extensions value\n";
          goto LAB_1400047e3;
        }
      }
      uVar1 = 0xd;
      goto LAB_140004918;
    }
    if (DebugInfoLevel == 0) goto LAB_140004918;
    pcVar3 = "LsapLoadRequiredExtensions: RegQueryValueEx for LSA key failed: %lu\n";
  }
  else {
    if (DebugInfoLevel == 0) goto LAB_140004918;
    pcVar3 = "LsapLoadRequiredExtensions: RegOpenKeyEx for LSA key failed: %lu\n";
  }
  LsapDebugOut(1,pcVar3,(ulonglong)uVar1,lpType);
LAB_140004918:
  if (local_res18 != (HKEY)0x0) {
    RegCloseKey(local_res18);
  }
  if (pwVar4 != (wchar_t *)0x0) {
    LsapFreeLsaHeap(pwVar4);
  }
  if ((uVar1 != 0) && (DebugInfoLevel != 0)) {
    LsapDebugOut(1,"LsapLoadRequiredExtensions failed: 0x%x\n",(ulonglong)uVar1,lpType);
  }
  return uVar1;
}



===== LsapRegisterInterface @ 140004974 =====

undefined8 LsapRegisterInterface(longlong param_1,int param_2,undefined8 param_3)

{
  longlong *plVar1;
  code *pcVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  longlong *plVar5;
  undefined4 in_register_00000014;
  
  uVar3 = 0;
  if (gHasInitLsaIfConfig == 0) {
    uVar3 = 0xc00000e5;
  }
  else {
    RtlAcquireResourceExclusive
              (&gLsaIfLock,CONCAT71((int7)(CONCAT44(in_register_00000014,param_2) >> 8),1));
    puVar4 = LsapFindRegisteredInterface(param_2);
    if (puVar4 == (undefined8 *)0x0) {
      puVar4 = (undefined8 *)LsapAllocateLsaHeap(0x38);
      if (puVar4 == (undefined8 *)0x0) {
        uVar3 = 0xc0000017;
      }
      else {
        puVar4[6] = param_3;
        *(int *)(puVar4 + 2) = param_2;
        puVar4[3] = param_1;
        if ((undefined8 *)*DAT_14000d748 != &gLsapIfList) {
LAB_140004a62:
          pcVar2 = (code *)swi(0x29);
          (*pcVar2)(3);
          pcVar2 = (code *)swi(3);
          uVar3 = (*pcVar2)();
          return uVar3;
        }
        *puVar4 = &gLsapIfList;
        puVar4[1] = DAT_14000d748;
        *DAT_14000d748 = puVar4;
        DAT_14000d748 = puVar4;
        if (param_1 != 0) {
          plVar5 = puVar4 + 4;
          plVar1 = *(longlong **)(param_1 + 0x18);
          if (*plVar1 != param_1 + 0x10) goto LAB_140004a62;
          *plVar5 = param_1 + 0x10;
          puVar4[5] = plVar1;
          *plVar1 = (longlong)plVar5;
          *(longlong **)(param_1 + 0x18) = plVar5;
        }
      }
    }
    else {
      uVar3 = 0xc0000718;
    }
    RtlReleaseResource(&gLsaIfLock);
  }
  return uVar3;
}



===== LsapBuildSD @ 140004a70 =====

uint LsapBuildSD(void)

{
  longlong lVar1;
  DWORD DVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  HANDLE hObject;
  longlong lVar9;
  undefined8 uVar10;
  
  hObject = (HANDLE)SpmOpenEvent();
  if (hObject == (HANDLE)0x0) {
    if (DebugInfoLevel != 0) {
      DVar2 = GetLastError();
      LsapDebugOut(1,"LsapBuildSD: Could not open %ws, %d\n",
                   L"\\SECURITY\\LSA_AUTHENTICATION_INITIALIZED",(ulonglong)DVar2);
    }
    uVar8 = 0xc0000008;
  }
  else {
    iVar3 = RtlLengthSid(gLsapIdentityServicesLpacSid);
    iVar4 = RtlLengthSid(gLsapAnyPackageSid);
    iVar5 = RtlLengthSid(gLsapWorldSid);
    iVar6 = RtlLengthSid(gLsapAliasAdminsSid);
    iVar7 = RtlLengthSid(gLsapLocalSystemSid);
    iVar7 = iVar3 + iVar4 + iVar5 + iVar6 + iVar7;
    lVar9 = LsapAllocateLsaHeap(iVar7 + 0x58);
    if (lVar9 == 0) {
      uVar8 = 0xc000009a;
    }
    else {
      lVar1 = lVar9 + 0x28;
      uVar8 = RtlCreateAcl(lVar1,iVar7 + 0x30,2);
      if (-1 < (int)uVar8) {
        uVar8 = RtlAddAccessAllowedAce(lVar1,2,0xa0000000,gLsapWorldSid);
        if (-1 < (int)uVar8) {
          uVar8 = RtlAddAccessAllowedAce(lVar1,2,0x10000000,gLsapLocalSystemSid);
          if (-1 < (int)uVar8) {
            uVar8 = RtlAddAccessAllowedAce(lVar1,2,0xa0020000,gLsapAliasAdminsSid);
            if (-1 < (int)uVar8) {
              uVar8 = RtlAddAccessAllowedAce(lVar1,2,0xa0000000,gLsapAnyPackageSid);
              if (-1 < (int)uVar8) {
                uVar8 = RtlAddAccessAllowedAce(lVar1,2,0xa0000000);
                if (-1 < (int)uVar8) {
                  uVar8 = RtlCreateSecurityDescriptor(lVar9,1);
                  if (-1 < (int)uVar8) {
                    uVar10 = 0;
                    uVar8 = RtlSetDaclSecurityDescriptor(lVar9,1,lVar1);
                    if (-1 < (int)uVar8) {
                      uVar8 = NtSetSecurityObject(hObject,4,lVar9);
                      if (((int)uVar8 < 0) && (DebugInfoLevel != 0)) {
                        LsapDebugOut(1,"Failed to set event SD: 0x%x\n",(ulonglong)uVar8,uVar10);
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    CloseHandle(hObject);
    if (lVar9 != 0) {
      LsapFreeLsaHeap(lVar9);
    }
  }
  return uVar8;
}



===== LsapBuildWellKnownSids @ 140004cf0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int LsapBuildWellKnownSids(void)

{
  undefined4 uVar1;
  int iVar2;
  longlong lVar3;
  undefined4 *puVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  longlong lVar8;
  longlong lVar9;
  undefined1 auStack_88 [32];
  longlong local_68;
  undefined8 local_60;
  wchar_t *local_58;
  undefined4 local_50;
  undefined2 local_4c;
  undefined4 local_48;
  undefined2 local_44;
  undefined4 local_40;
  undefined2 local_3c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_88;
  local_60 = 0x2a0028;
  local_50 = 0;
  local_58 = L"lpacIdentityServices";
  lVar5 = 0;
  local_4c = 0x500;
  lVar6 = 0;
  local_48 = 0;
  local_44 = 0x100;
  lVar7 = 0;
  local_40 = 0;
  lVar8 = 0;
  local_3c = 0xf00;
  lVar9 = 0;
  uVar1 = RtlLengthRequiredSid(1);
  lVar3 = LsapAllocateLsaHeap(uVar1);
  if (lVar3 == 0) {
    return -0x3fffff66;
  }
  local_68 = lVar3;
  RtlInitializeSid(lVar3,&local_50,1);
  puVar4 = (undefined4 *)RtlSubAuthoritySid(lVar3,0);
  *puVar4 = 0x12;
  uVar1 = RtlLengthRequiredSid(1);
  lVar3 = LsapAllocateLsaHeap(uVar1);
  if (lVar3 == 0) {
LAB_140004de0:
    iVar2 = -0x3fffff66;
  }
  else {
    RtlInitializeSid(lVar3,&local_48,1);
    puVar4 = (undefined4 *)RtlSubAuthoritySid(lVar3,0);
    *puVar4 = 0;
    uVar1 = RtlLengthRequiredSid(1);
    lVar5 = LsapAllocateLsaHeap(uVar1);
    if (lVar5 == 0) goto LAB_140004de0;
    RtlInitializeSid(lVar5,&local_50,1);
    puVar4 = (undefined4 *)RtlSubAuthoritySid(lVar5,0);
    *puVar4 = 7;
    uVar1 = RtlLengthRequiredSid(2);
    lVar6 = LsapAllocateLsaHeap(uVar1);
    if (lVar6 == 0) goto LAB_140004de0;
    RtlInitializeSid(lVar6,&local_50,2);
    puVar4 = (undefined4 *)RtlSubAuthoritySid(lVar6,0);
    *puVar4 = 0x20;
    puVar4 = (undefined4 *)RtlSubAuthoritySid(lVar6,1);
    *puVar4 = 0x220;
    uVar1 = RtlLengthRequiredSid(2);
    lVar7 = LsapAllocateLsaHeap(uVar1);
    if (lVar7 == 0) goto LAB_140004de0;
    RtlInitializeSid(lVar7,&local_40,2);
    puVar4 = (undefined4 *)RtlSubAuthoritySid(lVar7,0);
    *puVar4 = 2;
    puVar4 = (undefined4 *)RtlSubAuthoritySid(lVar7,1);
    *puVar4 = 1;
    uVar1 = RtlLengthRequiredSid(10);
    lVar8 = LsapAllocateLsaHeap(uVar1);
    if (lVar8 == 0) goto LAB_140004de0;
    uVar1 = RtlLengthRequiredSid(9);
    lVar9 = LsapAllocateLsaHeap(uVar1);
    if (lVar9 == 0) goto LAB_140004de0;
    iVar2 = RtlDeriveCapabilitySidsFromName(&local_60,lVar9,lVar8);
    if (-1 < iVar2) {
      gLsapLocalSystemSid = local_68;
      gLsapAnyPackageSid = lVar7;
      gLsapAliasAdminsSid = lVar6;
      gLsapIdentityServicesLpacSid = lVar8;
      gLsapAnonymousSid = lVar5;
      gLsapWorldSid = lVar3;
      goto LAB_140004e34;
    }
  }
  LsapFreeLsaHeap(local_68);
  if (lVar3 != 0) {
    LsapFreeLsaHeap(lVar3);
  }
  if (lVar5 != 0) {
    LsapFreeLsaHeap(lVar5);
  }
  if (lVar6 != 0) {
    LsapFreeLsaHeap(lVar6);
  }
  if (lVar7 != 0) {
    LsapFreeLsaHeap(lVar7);
  }
  if (lVar8 != 0) {
    LsapFreeLsaHeap(lVar8);
  }
  if (lVar9 == 0) {
    return iVar2;
  }
LAB_140004e34:
  LsapFreeLsaHeap(lVar9);
  return iVar2;
}



===== SpmOpenEvent @ 140005050 =====

undefined8 SpmOpenEvent(void)

{
  int iVar1;
  DWORD dwErrCode;
  undefined8 local_res18 [2];
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
  
  local_1c = 0;
  local_res18[0] = 0;
  local_34 = 0;
  local_48 = 0;
  uStack_40 = 0;
  RtlInitUnicodeString(&local_48,L"\\SECURITY\\LSA_AUTHENTICATION_INITIALIZED");
  local_30 = 0;
  local_28 = &local_48;
  local_38 = 0x30;
  local_20 = 0x40;
  local_18 = 0;
  uStack_10 = 0;
  iVar1 = NtOpenEvent(local_res18,0x1f0003,&local_38);
  if (iVar1 < 0) {
    dwErrCode = RtlNtStatusToDosError(iVar1);
    SetLastError(dwErrCode);
    local_res18[0] = 0;
  }
  return local_res18[0];
}



===== LsapRmInitializeServer @ 1400050fc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint LsapRmInitializeServer(void)

{
  uint uVar1;
  HANDLE hObject;
  char *pcVar2;
  undefined1 *in_R9;
  undefined8 uVar3;
  undefined1 auStackY_358 [32];
  DWORD local_2f8 [2];
  undefined8 local_2f0;
  undefined8 local_2e8;
  undefined8 local_2e0;
  undefined8 uStack_2d8;
  undefined8 local_2d0;
  undefined8 uStack_2c8;
  undefined4 local_2c0;
  undefined4 local_2bc;
  undefined8 local_2b8;
  undefined8 *local_2b0;
  undefined4 local_2a8;
  undefined4 local_2a4;
  undefined8 local_2a0;
  undefined8 uStack_298;
  undefined8 local_290;
  undefined8 uStack_288;
  undefined8 local_280;
  undefined8 uStack_278;
  undefined8 local_270;
  undefined1 local_268 [4];
  undefined4 local_264;
  undefined4 local_260;
  undefined2 local_25c;
  undefined8 local_258;
  undefined1 local_218 [4];
  ushort local_214;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_358;
  memset(local_218,0,0x200);
  local_2bc = 0;
  local_2a4 = 0;
  local_2f8[0] = 0;
  local_2d0 = 0;
  uStack_2c8 = 0;
  local_2e0 = 0;
  uStack_2d8 = 0;
  RtlInitUnicodeString(&local_2e0);
  local_2b0 = &local_2e0;
  local_2c0 = 0x30;
  local_2b8 = 0;
  local_2a8 = 0;
  local_2a0 = 0;
  uStack_298 = 0;
  memset(local_268,0,0x48);
  local_258 = 0x200;
  uVar1 = NtAlpcCreatePort(&gLsapCommandPortHandle,&local_2c0,local_268);
  if ((int)uVar1 < 0) {
    if (DebugInfoLevel == 0) {
      return uVar1;
    }
    pcVar2 = "LsapRmInitializeServer: NtAlpcCreatePort failed: 0x%lx\n";
  }
  else {
    memset(local_268,0,0x48);
    local_258 = 0x200;
    local_264 = 0xc;
    local_260 = 2;
    local_25c = 0x101;
    RtlInitUnicodeString(&local_2d0,L"\\SeRmCommandPort");
    in_R9 = local_268;
    uVar1 = NtAlpcConnectPort(&gLsapRmCommandPortHandle,&local_2d0,0);
    if (-1 < (int)uVar1) {
      do {
        local_270 = 0;
        in_R9 = (undefined1 *)0x0;
        local_2f0 = 0x200;
        uStack_288 = 0;
        local_280 = 0;
        uStack_278 = 0;
        local_290 = 0x20000000;
        uVar1 = NtAlpcSendWaitReceivePort(gLsapCommandPortHandle,0,0);
        if (uVar1 != 0xc0000023) {
          if ((int)uVar1 < 0) {
            if (DebugInfoLevel == 0) {
              return uVar1;
            }
            pcVar2 = "LsapRmInitializeServer: NtAlpcSendWaitReceivePort failed: 0x%lx\n";
            goto LAB_1400053ef;
          }
          if ((local_214 & 0xff) == 10) goto LAB_140005320;
        }
        NtAlpcCancelMessage(gLsapCommandPortHandle);
      } while( true );
    }
    if (DebugInfoLevel == 0) {
      return uVar1;
    }
    pcVar2 = "LsapRmInitializeServer: NtAlpcConnectPort failed: 0x%lx\n";
  }
LAB_1400053ef:
  LsapDebugOut(1,pcVar2,(ulonglong)uVar1,in_R9);
  return uVar1;
LAB_140005320:
  in_R9 = (undefined1 *)0x0;
  local_2e8 = 0;
  uVar1 = NtAlpcAcceptConnectPort(&local_2e8,gLsapCommandPortHandle,0);
  if (-1 < (int)uVar1) {
    uVar3 = 0;
    hObject = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,LsapRmServerThread,(LPVOID)0x0,0,local_2f8);
    if (hObject == (HANDLE)0x0) {
      if (DebugInfoLevel != 0) {
        LsapDebugOut(1,"LsapRmInitializeServer: CreateThread  failed: 0x%lx\n",(ulonglong)uVar1,
                     uVar3);
      }
    }
    else {
      CloseHandle(hObject);
    }
    return 0;
  }
  if (DebugInfoLevel == 0) {
    return uVar1;
  }
  pcVar2 = "LsapRmInitializeServer: NtAlpcAcceptConnectPort failed: 0x%lx\n";
  goto LAB_1400053ef;
}



===== LsapRmServerThread @ 140005430 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void LsapRmServerThread(void)

{
  int iVar1;
  undefined1 *puVar2;
  ushort uVar3;
  undefined1 auStack_488 [32];
  undefined1 *local_468;
  undefined8 *local_460;
  undefined8 *local_458;
  undefined8 local_450;
  undefined8 local_448;
  undefined8 local_440;
  undefined8 uStack_438;
  undefined8 local_430;
  undefined8 uStack_428;
  undefined8 local_420;
  undefined1 local_418 [4];
  ushort uStack_414;
  undefined8 uStack_410;
  undefined4 local_408;
  undefined4 uStack_404;
  undefined4 uStack_400;
  undefined4 uStack_3fc;
  undefined8 local_3f8;
  undefined1 local_218 [8];
  undefined8 uStack_210;
  undefined4 local_208;
  undefined4 uStack_204;
  undefined4 uStack_200;
  undefined4 uStack_1fc;
  undefined8 local_1f8;
  int local_1f0 [118];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_488;
  memset(local_418,0,0x200);
  memset(local_218,0,0x200);
  do {
    puVar2 = (undefined1 *)0x0;
    while( true ) {
      local_420 = 0;
      local_448 = 0x200;
      local_458 = &local_440;
      local_450 = 0;
      local_460 = &local_448;
      local_468 = local_418;
      uStack_438 = 0;
      local_430 = 0;
      uStack_428 = 0;
      local_440 = 0x20000000;
      iVar1 = NtAlpcSendWaitReceivePort
                        (gLsapCommandPortHandle,-(uint)(puVar2 != (undefined1 *)0x0) & 0x10000,
                         puVar2,0);
      uVar3 = uStack_414;
      if (iVar1 < 0) break;
      if (((uStack_414 & 0xffff00ff) - 1 & 0xfffffffd) != 0) goto LAB_140005596;
      memset(local_1f0,0,0x1d8);
      puVar2 = local_218;
      uStack_210 = uStack_410;
      local_1f8 = local_3f8;
      local_208 = local_408;
      uStack_204 = uStack_404;
      uStack_200 = uStack_400;
      uStack_1fc = uStack_3fc;
      iVar1 = 0;
      if (gLsapRmExtension != (undefined8 *)0x0) {
        iVar1 = (*(code *)*gLsapRmExtension)(local_418);
        if (iVar1 != 0x103) {
          uVar3 = uStack_414;
          goto LAB_14000557f;
        }
        break;
      }
LAB_14000557f:
      local_1f0[0] = iVar1;
      if ((uVar3 & 0xff) == 3) {
LAB_140005596:
        puVar2 = (undefined1 *)0x0;
        if ((uVar3 >> 0xd & 1) != 0) {
          NtAlpcCancelMessage(gLsapCommandPortHandle,0,&uStack_438);
        }
      }
    }
  } while( true );
}



===== LsapGetSystemInfo @ 1400055d0 =====

undefined8 LsapGetSystemInfo(undefined4 *param_1)

{
  *param_1 = LsapSystemProcessId;
  return 0;
}



===== LsapIfClientCallback @ 1400055f0 =====

void LsapIfClientCallback
               (uint param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 *param_5,undefined8 param_6)

{
  uint local_38 [2];
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_38[1] = 0;
  local_38[0] = param_1 & 0xffffff;
  local_18 = 0;
  uStack_10 = 0;
  if ((param_1 >> 0x18 & 1) == 0) {
    SspiSrvClientCallback();
  }
  else {
    local_18 = *param_5;
    uStack_10 = param_5[1];
    local_30 = param_2;
    local_28 = param_3;
    local_20 = param_4;
    LsapCallKsec(0x39003c,local_38,0x30,param_6,0x10);
  }
  return;
}



===== LSA_LOOKPR_HANDLE_rundown @ 140005690 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void LSA_LOOKPR_HANDLE_rundown(void)

{
  if ((gLsapLookupExtension != 0) && (*(code **)(gLsapLookupExtension + 0x48) != (code *)0x0)) {
    (**(code **)(gLsapLookupExtension + 0x48))();
  }
  return;
}



===== AsyncWorkReadyCallback @ 1400056c0 =====

void AsyncWorkReadyCallback
               (undefined8 param_1,undefined8 param_2,undefined *param_3,ulonglong param_4)

{
  uint *puVar1;
  BOOL BVar2;
  DWORD DVar3;
  void *_Dst;
  uint *_Src;
  uint uVar4;
  undefined8 local_18 [2];
  
  puVar1 = DAT_14000d6d8;
  if ((int)param_4 == 0) {
    if (DAT_14000d6d8 == (uint *)0x0) {
      if (DebugInfoLevel != 0) {
        LsapDebugOut(1,"KsecRpcIncomingBuffer is NULL returning from ksecdd.\n",param_3,param_4);
      }
    }
    else {
      uVar4 = 0;
      _Src = DAT_14000d6d8 + 1;
      if (*DAT_14000d6d8 != 0) {
        do {
          _Dst = (void *)LsapAllocateLsaHeap(_Src[10]);
          if (_Dst == (void *)0x0) {
            if (DebugInfoLevel != 0) {
              LsapDebugOut(1,"Out of memory while processing work from ksecdd\n",param_3,param_4);
            }
LAB_1400057ba:
            SendStatusOnlyResponse((longlong *)_Src,0xc000009a);
          }
          else {
            memcpy(_Dst,_Src,(ulonglong)_Src[10]);
            param_3 = &DAT_14000d690;
            BVar2 = TrySubmitThreadpoolCallback
                              (AsyncWorkerThreadCallback,_Dst,(PTP_CALLBACK_ENVIRON)&DAT_14000d690);
            if (BVar2 == 0) {
              if (DebugInfoLevel != 0) {
                DVar3 = GetLastError();
                param_3 = (undefined *)(ulonglong)DVar3;
                LsapDebugOut(1,"Error processing work on worker thread: %d\n",param_3,param_4);
              }
              goto LAB_1400057ba;
            }
          }
          uVar4 = uVar4 + 1;
          _Src = (uint *)((longlong)_Src + (ulonglong)_Src[10]);
        } while (uVar4 < *puVar1);
      }
      local_18[0] = 0;
      NtFreeVirtualMemory(0xffffffffffffffff,&DAT_14000d6d8,local_18,0x8000);
      DAT_14000d6d8 = (uint *)0x0;
      SendRequestForNextAsyncKsecddCall();
    }
  }
  else if (DebugInfoLevel != 0) {
    LsapDebugOut(1,"Error requesting async ksecdd function call: %d\n",param_4 & 0xffffffff,param_4)
    ;
  }
  return;
}



===== SendRequestForNextAsyncKsecddCall @ 140005828 =====

void SendRequestForNextAsyncKsecddCall(void)

{
  BOOL BVar1;
  DWORD DVar2;
  undefined8 uVar3;
  
  while( true ) {
    StartThreadpoolIo(DAT_14000d660);
    uVar3 = 0;
    BVar1 = DeviceIoControl(DAT_14000d6f0,0x39006a,(LPVOID)0x0,0,&DAT_14000d6d8,8,(LPDWORD)0x0,
                            (LPOVERLAPPED)&DAT_14000d668);
    if (BVar1 != 0) {
      return;
    }
    DVar2 = GetLastError();
    if (DVar2 == 0x3e5) break;
    if (DebugInfoLevel != 0) {
      LsapDebugOut(1,"IOCTL_KSEC_IPC_GET_QUEUED_FUNCTION_CALLS failed (error 0x%x).\n",
                   (ulonglong)DVar2,uVar3);
    }
    CancelThreadpoolIo(DAT_14000d660);
    Sleep(0x7d);
  }
  return;
}



===== InitializeAsyncKsec @ 1400058ec =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint InitializeAsyncKsec(undefined8 param_1,undefined8 param_2,undefined8 param_3,
                        undefined8 *param_4)

{
  uint uVar1;
  ulonglong uVar2;
  char *pcVar3;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  DAT_14000d0cc = TlsAlloc();
  if (DAT_14000d0cc == 0xffffffff) {
    uVar1 = GetLastError();
    if (DebugInfoLevel == 0) {
      return 0xc000009a;
    }
    pcVar3 = "FAILED to allocate TLS slot for impersonation token: %d\n";
  }
  else {
    param_4 = &local_18;
    uVar1 = NtOpenFile(&DAT_14000d6f0,0xc0000000,param_1,param_4,3,0);
    if (DAT_14000d6f0 == (HANDLE)0xffffffffffffffff) {
      if (DebugInfoLevel == 0) {
        return uVar1;
      }
      LsapDebugOut(1,"FAILED to open %ws, status %x\n",L"\\Device\\KsecDD",(ulonglong)uVar1);
      return uVar1;
    }
    DAT_14000d6e0 = CreateThreadpool((PVOID)0x0);
    if (DAT_14000d6e0 == (PTP_POOL)0x0) {
      uVar1 = GetLastError();
      if (DebugInfoLevel == 0) {
        return 0xc000009a;
      }
      pcVar3 = "Failed to create worker pool: %d\n";
    }
    else {
      uVar2 = GetMaxAsyncWorkerThreads();
      SetThreadpoolThreadMaximum(DAT_14000d6e0,(DWORD)uVar2);
      _DAT_14000d6a0 = 0;
      param_4 = (undefined8 *)0x0;
      _DAT_14000d6a8 = 0;
      _DAT_14000d6c0 = 0;
      _DAT_14000d6c8 = 0;
      _DAT_14000d6b0 = 0;
      uRam000000014000d6b8 = 0;
      _DAT_14000d698 = DAT_14000d6e0;
      _DAT_14000d690 = 3;
      _DAT_14000d6cc = 1;
      _DAT_14000d6d0 = 0x48;
      DAT_14000d660 =
           CreateThreadpoolIo(DAT_14000d6f0,AsyncWorkReadyCallback,(PVOID)0x0,
                              (PTP_CALLBACK_ENVIRON)0x0);
      if (DAT_14000d660 != (PTP_IO)0x0) {
        SendRequestForNextAsyncKsecddCall();
        return 0;
      }
      uVar1 = GetLastError();
      if (DebugInfoLevel == 0) {
        return 0xc000009a;
      }
      pcVar3 = "Unable to setup IO completion thread pool object: %d\n";
    }
  }
  LsapDebugOut(1,pcVar3,(ulonglong)uVar1,param_4);
  return 0xc000009a;
}



===== __delayLoadHelper2 @ 140005ac0 =====

void __delayLoadHelper2(undefined8 param_1,undefined8 param_2)

{
  ResolveDelayLoadedAPI(&IMAGE_DOS_HEADER_140000000,param_1,0,DelayLoadFailureHook_exref,param_2,0);
  return;
}



===== memcpy @ 140005b03 =====

void * __cdecl memcpy(void *_Dst,void *_Src,size_t _Size)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000140005b03. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = memcpy(_Dst,_Src,_Size);
  return pvVar1;
}



===== memset @ 140005b0f =====

void * __cdecl memset(void *_Dst,int _Val,size_t _Size)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000140005b0f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = memset(_Dst,_Val,_Size);
  return pvVar1;
}



===== __GSHandlerCheck @ 140005b1c =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 140005b40 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong __GSHandlerCheckCommon(undefined8 param_1,longlong param_2)

{
  ulonglong uVar1;
  ulonglong uVar2;
  
  uVar2 = (ulonglong)*(uint *)(*(longlong *)(param_2 + 0x10) + 8);
  uVar1 = *(ulonglong *)(param_2 + 8);
  if ((*(byte *)(uVar2 + 3 + uVar1) & 0xf) != 0) {
    uVar1 = (ulonglong)(*(byte *)(uVar2 + 3 + uVar1) & 0xfffffff0);
  }
  return uVar1;
}



===== _guard_check_icall @ 140005bb0 =====

void _guard_check_icall(void)

{
  return;
}



===== __security_check_cookie @ 140005be0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140005c20 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 140005c50 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140005c50. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140005c80 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall$thunk$10345483385596137414 @ 140006010 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall_thunk_10345483385596137414(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}


