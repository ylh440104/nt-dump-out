
===== SslEnumEccCurves @ 180001010 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void SslEnumEccCurves(uint *param_1,undefined4 *param_2,undefined8 *param_3)

{
  uint *puVar1;
  undefined8 *puVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  uint uVar5;
  
  puVar2 = param_3;
                    /* 0x1010  127  SslEnumEccCurves */
  puVar1 = ValidateSslProvHandle(param_1);
  if (puVar1 == (uint *)0x0) {
    uVar5 = 0x80090026;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_180001192;
    uVar3 = 0xc1;
    uVar5 = 0x80090026;
LAB_180001071:
    WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),param_2,
                "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c","Status",(char)uVar5,
                "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",uVar3);
    goto LAB_180001192;
  }
  if ((param_3 == (undefined8 *)0x0) || (param_2 == (undefined4 *)0x0)) {
    uVar5 = 0x80090027;
    uVar4 = 200;
    uVar3 = 0x27;
  }
  else {
    *param_2 = 0;
    *puVar2 = 0;
    if ((ushort)puVar1[8] < 3) {
      uVar4 = 0xd8;
    }
    else {
      if (*(code **)(puVar1 + 0x42) != (code *)0x0) {
        uVar5 = (**(code **)(puVar1 + 0x42))(*(undefined8 *)(puVar1 + 0x6a));
        if ((int)uVar5 < 0) {
          if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
             ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_180001192;
          uVar3 = 0xf1;
          goto LAB_180001071;
        }
        puVar2 = (undefined8 *)MSCryptAlloc(0x20);
        if (puVar2 != (undefined8 *)0x0) {
          *puVar2 = 0;
          puVar2[1] = 0;
          puVar2[2] = 0;
          puVar2[3] = 0;
          LOCK();
          puVar1[4] = puVar1[4] + 1;
          UNLOCK();
          *puVar2 = puVar1;
          puVar2[1] = *param_3;
          MSCryptAddMemoryBuffer(0x1800278a0,(longlong)puVar2);
          uVar5 = 0;
          goto LAB_180001192;
        }
        uVar5 = 0x8009000e;
        uVar4 = 0xfd;
        uVar3 = 0xe;
        goto LAB_18000117f;
      }
      uVar4 = 0xe3;
    }
    uVar5 = 0x80090029;
    uVar3 = 0x29;
  }
LAB_18000117f:
  DebugTraceError(uVar3,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",uVar4)
  ;
LAB_180001192:
  NormalizeNteStatus(uVar5);
  return;
}



===== NCryptTranslateHandle @ 1800011b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

SECURITY_STATUS __stdcall
NCryptTranslateHandle
          (NCRYPT_PROV_HANDLE *phProvider,NCRYPT_KEY_HANDLE *phKey,HCRYPTPROV hLegacyProv,
          HCRYPTKEY hLegacyKey,DWORD dwLegacyKeySpec,DWORD dwFlags)

{
  longlong lVar1;
  NCRYPT_PROV_HANDLE NVar2;
  HCRYPTKEY hKey;
  BOOL BVar3;
  uint uVar4;
  int iVar5;
  DWORD DVar6;
  LPCWSTR pszProviderName;
  ulonglong uVar7;
  undefined8 uVar8;
  ulonglong uVar9;
  NCRYPT_KEY_HANDLE *pNVar10;
  undefined *puVar11;
  undefined1 *puVar12;
  undefined1 *puVar13;
  LPCWSTR pszKeyName;
  undefined8 uVar14;
  HCRYPTPROV HVar15;
  LPCWSTR pWVar16;
  undefined1 uVar17;
  undefined1 uVar18;
  NCRYPT_KEY_HANDLE hObject;
  undefined1 auStackY_b8 [32];
  DWORD local_78;
  DWORD local_74;
  uint local_70;
  DWORD local_6c;
  uint local_68;
  int local_64;
  NCRYPT_PROV_HANDLE local_60;
  NCRYPT_KEY_HANDLE local_58;
  HCRYPTKEY local_50;
  NCRYPT_PROV_HANDLE *local_48;
  NCRYPT_KEY_HANDLE *local_40;
  ulonglong local_38;
  
                    /* 0x11b0  106  NCryptTranslateHandle */
  local_38 = __security_cookie ^ (ulonglong)&local_78;
  pszProviderName = (LPCWSTR)0x0;
  local_78 = 0;
  pszKeyName = (LPCWSTR)0x0;
  local_74 = 0;
  hObject = 0;
  local_60 = 0;
  local_58 = 0;
  local_68 = 0;
  local_6c = 0;
  local_70 = 0;
  pNVar10 = phKey;
  HVar15 = hLegacyProv;
  local_50 = hLegacyKey;
  local_48 = phProvider;
  local_40 = phKey;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    pNVar10 = (NCRYPT_KEY_HANDLE *)0x21;
    WPP_SF_PDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x21,hLegacyProv,hLegacyProv,
               (char)dwLegacyKeySpec,(char)dwFlags);
  }
  puVar12 = auStackY_b8;
  if ((phKey == (NCRYPT_KEY_HANDLE *)0x0) || (hLegacyProv == 0)) {
    DVar6 = 0x80090027;
    puVar13 = auStackY_b8;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       (puVar13 = auStackY_b8, (WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_18000147f;
    WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),pNVar10,HVar15,"Status",0x27,
                "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",0xdb);
    DVar6 = 0x80090027;
LAB_180001476:
    puVar13 = puVar12;
    if (hObject != 0) {
      *(undefined8 *)(puVar12 + -8) = 0x1800019aa;
      NCryptFreeObject(hObject);
    }
  }
  else {
    if (dwFlags != 0) {
      DVar6 = 0x80090009;
      uVar17 = 0xe2;
      uVar18 = 9;
      goto LAB_1800012a1;
    }
    uVar14 = 0;
    uVar8 = 4;
    BVar3 = CryptGetProvParam(hLegacyProv,4,(BYTE *)0x0,&local_78,0);
    if (BVar3 == 0) {
      DVar6 = GetLastError();
      puVar13 = auStackY_b8;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (puVar13 = auStackY_b8, (WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
        WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),uVar8,uVar14,"Status",(char)DVar6,
                    "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",0xf3);
        puVar13 = auStackY_b8;
      }
      goto LAB_18000147f;
    }
    if ((ulonglong)local_78 * 2 < 0x100000000) {
      uVar4 = local_78 + (int)((ulonglong)local_78 * 2);
      if (local_78 <= uVar4) {
        uVar7 = (ulonglong)uVar4;
        puVar13 = auStackY_b8;
        if ((uVar4 == 0) || (puVar13 = auStackY_b8, g_ulMaxStackAllocSize < uVar7)) {
LAB_1800012d4:
          puVar12 = puVar13;
          if (uVar7 <= uVar7 + 8) {
            *(undefined8 *)(puVar13 + -8) = 0x1800012ed;
            pszProviderName = (LPCWSTR)(*g_pfnAllocate)();
            if (pszProviderName != (LPCWSTR)0x0) {
              pszProviderName[0] = L'效';
              pszProviderName[1] = L'灡';
              pszProviderName = pszProviderName + 4;
            }
          }
        }
        else {
          uVar9 = g_ulAdditionalProbeSize + 8 + uVar7;
          puVar13 = auStackY_b8;
          if (uVar9 < uVar7) goto LAB_1800012d4;
          uVar8 = VerifyStackAvailable(uVar9);
          puVar13 = auStackY_b8;
          if ((int)uVar8 == 0) goto LAB_1800012d4;
          uVar9 = uVar7 + 0x17;
          if (uVar9 <= uVar7 + 8) {
            uVar9 = 0xffffffffffffff0;
          }
          lVar1 = -(uVar9 & 0xfffffffffffffff0);
          puVar12 = auStackY_b8 + lVar1;
          pszProviderName = (LPCWSTR)0x0;
          puVar13 = auStackY_b8 + lVar1;
          if ((undefined4 *)((longlong)&local_78 + lVar1) == (undefined4 *)0x0) goto LAB_1800012d4;
          *(undefined4 *)((longlong)&local_78 + lVar1) = 0x6b637453;
          pszProviderName = (LPCWSTR)((longlong)&local_70 + lVar1);
          puVar13 = auStackY_b8 + lVar1;
          if (pszProviderName == (LPCWSTR)0x0) goto LAB_1800012d4;
        }
        if (pszProviderName == (LPCWSTR)0x0) {
          *(undefined8 *)(puVar12 + -8) = 0x180001881;
          DebugTraceError(0xe,"Status",
                          "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",0xd);
          DVar6 = 0x8009000e;
          goto LAB_180001476;
        }
        uVar7 = (ulonglong)local_78;
        *(undefined4 *)(puVar12 + 0x20) = 0;
        pWVar16 = pszProviderName + uVar7;
        *(undefined8 *)(puVar12 + -8) = 0x18000166e;
        BVar3 = CryptGetProvParam(hLegacyProv,4,(BYTE *)pWVar16,&local_78,*(DWORD *)(puVar12 + 0x20)
                                 );
        DVar6 = local_78;
        if (BVar3 == 0) {
          *(undefined8 *)(puVar12 + -8) = 0x18000188d;
          DVar6 = GetLastError();
          uVar18 = 0x1b;
          goto LAB_1800018b6;
        }
        puVar11 = (undefined *)0x2;
        *(DWORD *)(puVar12 + 0x28) = local_78;
        *(LPCWSTR *)(puVar12 + 0x20) = pszProviderName;
        *(undefined8 *)(puVar12 + -8) = 0x180001698;
        iVar5 = MultiByteToWideChar(0,2,(LPCSTR)pWVar16,DVar6,*(LPWSTR *)(puVar12 + 0x20),
                                    *(int *)(puVar12 + 0x28));
        if (iVar5 == 0) {
          *(undefined8 *)(puVar12 + -8) = 0x1800017b2;
          DVar6 = GetLastError();
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
            *(undefined4 *)(puVar12 + 0x30) = 0xf28;
LAB_18000143d:
            uVar8 = *(undefined8 *)(WPP_GLOBAL_Control + 0x10);
            *(char **)(puVar12 + 0x28) =
                 "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c";
            *(DWORD *)(puVar12 + 0x20) = DVar6;
LAB_180001451:
            *(undefined8 *)(puVar12 + -8) = 0x18000145d;
            WPP_SF_sDsd(uVar8,puVar11,pWVar16,"Status",puVar12[0x20],*(char **)(puVar12 + 0x28),
                        puVar12[0x30]);
          }
          goto LAB_18000145d;
        }
        *(undefined4 *)(puVar12 + 0x20) = 0;
        local_6c = 4;
        *(undefined8 *)(puVar12 + -8) = 0x1800016c1;
        BVar3 = CryptGetProvParam(hLegacyProv,0x1b,(BYTE *)&local_68,&local_6c,
                                  *(DWORD *)(puVar12 + 0x20));
        if (BVar3 != 0) {
          local_70 = (uint)((local_68 & 0x20) != 0);
        }
        *(undefined8 *)(puVar12 + -8) = 0x1800016e2;
        DVar6 = NCryptOpenStorageProvider(&local_60,pszProviderName,0);
        if ((int)DVar6 < 0) {
          uVar18 = 0x4b;
LAB_1800018b6:
          *(undefined8 *)(puVar12 + -8) = 0x1800018cb;
          DebugTraceError((char)DVar6,"Status",
                          "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",
                          uVar18);
        }
        else {
          *(undefined4 *)(puVar12 + 0x20) = 0;
          pWVar16 = (LPCWSTR)0x0;
          *(undefined8 *)(puVar12 + -8) = 0x180001705;
          BVar3 = CryptGetProvParam(hLegacyProv,6,(BYTE *)0x0,&local_74,*(DWORD *)(puVar12 + 0x20));
          if (BVar3 == 0) {
            *(undefined8 *)(puVar12 + -8) = 0x1800018e8;
            DVar6 = GetLastError();
            uVar18 = 0x5c;
            goto LAB_1800018b6;
          }
          uVar7 = (ulonglong)local_74 * 3;
          puVar13 = puVar12;
          if (((uVar7 == 0) || (g_ulMaxStackAllocSize < uVar7)) ||
             (uVar9 = g_ulAdditionalProbeSize + 8 + uVar7, uVar9 < uVar7)) {
LAB_180001777:
            puVar12 = puVar13;
            if (uVar7 <= uVar7 + 8) {
              *(undefined8 *)(puVar13 + -8) = 0x180001790;
              pszKeyName = (LPCWSTR)(*g_pfnAllocate)();
              if (pszKeyName != (LPCWSTR)0x0) {
                pszKeyName[0] = L'效';
                pszKeyName[1] = L'灡';
                pszKeyName = pszKeyName + 4;
              }
            }
          }
          else {
            *(undefined8 *)(puVar12 + -8) = 0x18000173f;
            uVar8 = VerifyStackAvailable(uVar9);
            if ((int)uVar8 == 0) goto LAB_180001777;
            uVar9 = uVar7 + 0x17;
            if (uVar9 <= uVar7 + 8) {
              uVar9 = 0xffffffffffffff0;
            }
            *(undefined8 *)(puVar12 + -8) = 0x180001766;
            lVar1 = -(uVar9 & 0xfffffffffffffff0);
            pszKeyName = (LPCWSTR)0x0;
            puVar13 = puVar12 + lVar1;
            if ((undefined4 *)(puVar12 + lVar1 + 0x40) == (undefined4 *)0x0) goto LAB_180001777;
            *(undefined4 *)(puVar12 + lVar1 + 0x40) = 0x6b637453;
            pszKeyName = (LPCWSTR)(puVar12 + lVar1 + 0x48);
            puVar13 = puVar12 + lVar1;
            puVar12 = puVar12 + lVar1;
            if (pszKeyName == (LPCWSTR)0x0) goto LAB_180001777;
          }
          if (pszKeyName == (LPCWSTR)0x0) {
            DVar6 = 0x8009000e;
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
              *(undefined4 *)(puVar12 + 0x30) = 0xf65;
              *(char **)(puVar12 + 0x28) =
                   "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c";
              *(undefined4 *)(puVar12 + 0x20) = 0x8009000e;
              uVar8 = *(undefined8 *)(WPP_GLOBAL_Control + 0x10);
              puVar11 = WPP_GLOBAL_Control;
              DVar6 = 0x8009000e;
              goto LAB_180001451;
            }
          }
          else {
            uVar7 = (ulonglong)local_74;
            *(undefined4 *)(puVar12 + 0x20) = 0;
            pWVar16 = pszKeyName + uVar7;
            *(undefined8 *)(puVar12 + -8) = 0x1800013d3;
            BVar3 = CryptGetProvParam(hLegacyProv,6,(BYTE *)pWVar16,&local_74,
                                      *(DWORD *)(puVar12 + 0x20));
            DVar6 = local_74;
            if (BVar3 == 0) {
              *(undefined8 *)(puVar12 + -8) = 0x1800018fc;
              DVar6 = GetLastError();
              uVar18 = 0x72;
              goto LAB_1800018b6;
            }
            *(DWORD *)(puVar12 + 0x28) = local_74;
            puVar11 = (undefined *)0x2;
            *(LPCWSTR *)(puVar12 + 0x20) = pszKeyName;
            *(undefined8 *)(puVar12 + -8) = 0x180001401;
            iVar5 = MultiByteToWideChar(0,2,(LPCSTR)pWVar16,DVar6,*(LPWSTR *)(puVar12 + 0x20),
                                        *(int *)(puVar12 + 0x28));
            hKey = local_50;
            if (iVar5 == 0) {
              *(undefined8 *)(puVar12 + -8) = 0x180001415;
              DVar6 = GetLastError();
              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
                *(undefined4 *)(puVar12 + 0x30) = 0xf7f;
                goto LAB_18000143d;
              }
            }
            else {
              if ((dwLegacyKeySpec == 0) && (local_50 != 0)) {
                local_64 = 0;
                *(undefined4 *)(puVar12 + 0x20) = 0;
                local_50 = CONCAT44(local_50._4_4_,4);
                *(undefined8 *)(puVar12 + -8) = 0x18000193d;
                BVar3 = CryptGetKeyParam(hKey,7,(BYTE *)&local_64,(DWORD *)&local_50,
                                         *(DWORD *)(puVar12 + 0x20));
                if (BVar3 == 0) {
                  *(undefined8 *)(puVar12 + -8) = 0x1800018a1;
                  DVar6 = GetLastError();
                  uVar18 = 0x99;
                  goto LAB_1800018b6;
                }
                if ((local_64 == 0x2200) || (local_64 == 0x2400)) {
                  dwLegacyKeySpec = 2;
                }
                else if (((local_64 == 0xa400) || (local_64 == 0xaa01)) || (local_64 == 0xaa02)) {
                  dwLegacyKeySpec = 1;
                }
              }
              NVar2 = local_60;
              pNVar10 = &local_58;
              *(uint *)(puVar12 + 0x20) = local_70 << 5;
              *(undefined8 *)(puVar12 + -8) = 0x1800014e9;
              pWVar16 = pszKeyName;
              DVar6 = NCryptOpenKey(NVar2,pNVar10,pszKeyName,dwLegacyKeySpec,
                                    *(DWORD *)(puVar12 + 0x20));
              NVar2 = local_60;
              if ((int)DVar6 < 0) {
                if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
                  uVar8 = *(undefined8 *)(WPP_GLOBAL_Control + 0x10);
                  *(undefined4 *)(puVar12 + 0x30) = 0xfbc;
                  *(char **)(puVar12 + 0x28) =
                       "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c";
                  *(DWORD *)(puVar12 + 0x20) = DVar6;
                  *(undefined8 *)(puVar12 + -8) = 0x1800015bd;
                  WPP_SF_sDsd(uVar8,pNVar10,pWVar16,"Status",puVar12[0x20],
                              *(char **)(puVar12 + 0x28),puVar12[0x30]);
                }
                hObject = local_58;
              }
              else {
                if (local_48 != (NCRYPT_PROV_HANDLE *)0x0) {
                  local_60 = 0;
                  *local_48 = NVar2;
                }
                DVar6 = 0;
                *local_40 = local_58;
              }
            }
          }
        }
LAB_18000145d:
        if (*(int *)(pszProviderName + -4) == 0x70616548) {
          *(undefined8 *)(puVar12 + -8) = 0x18000199d;
          (*g_pfnFree)();
        }
        if ((pszKeyName != (LPCWSTR)0x0) && (*(int *)(pszKeyName + -4) == 0x70616548)) {
          *(undefined8 *)(puVar12 + -8) = 0x18000152e;
          (*g_pfnFree)();
        }
        goto LAB_180001476;
      }
      uVar18 = 0x16;
      uVar17 = 4;
      DVar6 = 0x216;
    }
    else {
      uVar18 = 0x16;
      uVar17 = 0xfb;
      DVar6 = 0x216;
    }
LAB_1800012a1:
    DebugTraceError(uVar18,"Status",
                    "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",uVar17);
    puVar13 = auStackY_b8;
  }
LAB_18000147f:
  NVar2 = local_60;
  if (local_60 != 0) {
    *(undefined8 *)(puVar13 + -8) = 0x1800015cb;
    NCryptFreeObject(NVar2);
  }
  *(undefined8 *)(puVar13 + -8) = 0x180001493;
  uVar4 = NormalizeNteStatus(DVar6);
  *(undefined8 *)(puVar13 + -8) = 0x18000149f;
  return uVar4;
}



===== WPP_SF_PDD @ 1800019b8 =====

void WPP_SF_PDD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  TraceMessage(param_1,0x2b,&WPP_7a4fecd660bc33d31f6cd64b40025006_Traceguids,param_2,&local_res20,8,
               &param_5,4,&param_6,4,0);
  return;
}



===== ReverseMemCopy @ 180001a20 =====

void ReverseMemCopy(undefined1 *param_1,undefined1 *param_2,uint param_3)

{
  undefined1 *puVar1;
  
  for (puVar1 = param_1 + ((ulonglong)param_3 - 1); param_1 <= puVar1; puVar1 = puVar1 + -1) {
    *puVar1 = *param_2;
    param_2 = param_2 + 1;
  }
  return;
}



===== VerifyStackAvailable @ 180001a44 =====

undefined8 VerifyStackAvailable(ulonglong param_1)

{
  InternalVerifyStackAvailable(param_1);
  return 1;
}



===== InternalVerifyStackAvailable @ 180001a70 =====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void InternalVerifyStackAvailable(ulonglong param_1)

{
  ulonglong uVar1;
  undefined8 auStack_40 [7];
  
  uVar1 = param_1 + 0xf;
  if (uVar1 <= param_1) {
    uVar1 = 0xffffffffffffff0;
  }
  *(undefined8 *)((longlong)auStack_40 - (uVar1 & 0xfffffffffffffff0)) = 0x180001ab4;
  return;
}



===== NCryptEnumAlgorithms @ 180001ad0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

SECURITY_STATUS __stdcall
NCryptEnumAlgorithms
          (NCRYPT_PROV_HANDLE hProvider,DWORD dwAlgOperations,DWORD *pdwAlgCount,
          NCryptAlgorithmName **ppAlgList,DWORD dwFlags)

{
  uint uVar1;
  int *piVar2;
  undefined8 *puVar3;
  undefined4 in_register_00000014;
  undefined8 uVar4;
  undefined1 uVar5;
  
                    /* 0x1ad0  76  NCryptEnumAlgorithms */
  uVar4 = CONCAT44(in_register_00000014,dwAlgOperations);
  puVar3 = (undefined8 *)0x0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    uVar4 = 0x19;
    WPP_SF_PDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x19,pdwAlgCount,hProvider,
               (char)dwAlgOperations,(char)dwFlags);
  }
  piVar2 = ValidateAndReferenceProvider((int *)hProvider);
  if (piVar2 == (int *)0x0) {
    uVar1 = 0x80090026;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),uVar4,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c","Status",0x26
                  ,"onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",0x41);
    }
    goto LAB_180001bac;
  }
  if ((pdwAlgCount == (DWORD *)0x0) || (ppAlgList == (NCryptAlgorithmName **)0x0)) {
    uVar1 = 0x80090027;
    uVar5 = 0x48;
LAB_180001c7c:
    DebugTraceError((char)uVar1,"Status",
                    "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",uVar5);
  }
  else {
    puVar3 = (undefined8 *)MSCryptAlloc(0x20);
    if (puVar3 != (undefined8 *)0x0) {
      *puVar3 = 0;
      puVar3[1] = 0;
      puVar3[2] = 0;
      puVar3[3] = 0;
      do {
        uVar1 = (**(code **)(piVar2 + 0x24))
                          (*(undefined8 *)(piVar2 + 0x44),dwAlgOperations,pdwAlgCount,ppAlgList,
                           dwFlags);
        if (uVar1 != 0x8009002e) {
          if (uVar1 == 0) {
            puVar3[1] = *ppAlgList;
            *puVar3 = piVar2;
            MSCryptAddMemoryBuffer(0x1800278b8,(longlong)puVar3);
            goto LAB_180001bac;
          }
          break;
        }
        if ((dwFlags & 0x40) != 0) {
          uVar1 = 0x80090022;
          uVar5 = 0x6d;
          goto LAB_180001c7c;
        }
        uVar1 = (**(code **)(piVar2 + 0x30))
                          (*(undefined8 *)(piVar2 + 0x44),0,L"NCryptEnumAlgorithms",0);
      } while (uVar1 == 0);
      uVar5 = 0x7f;
      goto LAB_180001c7c;
    }
    uVar1 = 0x8009000e;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),uVar4,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c","Status",0xe,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",0x55);
    }
  }
  DereferenceProvider((longlong)piVar2);
  if (puVar3 != (undefined8 *)0x0) {
    SafeAllocaFreeToHeap(puVar3);
  }
LAB_180001bac:
  uVar1 = NormalizeNteStatus(uVar1);
  return uVar1;
}



===== ConvertLegacyRsaPublicBlob @ 180001d24 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong ConvertLegacyRsaPublicBlob
                    (char *param_1,undefined8 param_2,undefined4 *param_3,uint param_4,uint *param_5
                    ,int *param_6)

{
  int iVar1;
  uint uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  uint uVar7;
  uint uVar8;
  uint *puVar9;
  undefined1 auStackY_88 [32];
  uint local_40 [2];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_88;
  uVar8 = (uint)param_2;
  puVar6 = param_3;
  uVar3 = VerifyLegacyRsaPublicBlob(param_1,uVar8);
  uVar4 = uVar3 & 0xffffffff;
  if ((int)uVar3 == 0) {
    if ((param_1 == (char *)0x0) || (uVar8 < 0x14)) {
      uVar4 = 0x80090027;
    }
    else {
      if (param_6 != (int *)0x0) {
        *param_6 = ((int)((ulonglong)*(undefined8 *)param_1 >> 0x20) == 0x2400) + 1;
      }
      local_40[0] = *(uint *)(param_1 + 0x10);
      iVar1 = (int)((ulonglong)*(undefined8 *)(param_1 + 8) >> 0x20);
      uVar8 = iVar1 + 7U >> 3;
      if ((local_40[0] & 0xff000000) == 0) {
        if ((local_40[0] & 0xff0000) == 0) {
          uVar7 = ((local_40[0] & 0xff00) != 0) + 1;
        }
        else {
          uVar7 = 3;
        }
      }
      else {
        uVar7 = 4;
      }
      uVar2 = uVar8 + 0x18 + uVar7;
      *param_5 = uVar2;
      if (param_3 != (undefined4 *)0x0) {
        if (param_4 < uVar2) {
          return 0x80090028;
        }
        memset(param_3,0,(ulonglong)param_4);
        param_3[4] = 0;
        puVar9 = local_40;
        param_3[5] = 0;
        *param_3 = 0x31415352;
        param_3[1] = iVar1;
        param_3[2] = uVar7;
        param_3[3] = uVar8;
        puVar5 = (undefined4 *)((ulonglong)uVar7 + (longlong)(param_3 + 6));
        puVar6 = puVar5;
        while (puVar6 = (undefined4 *)((longlong)puVar6 + -1), param_3 + 6 <= puVar6) {
          *(char *)puVar6 = (char)*puVar9;
          puVar9 = (uint *)((longlong)puVar9 + 1);
        }
        ReverseMemCopy((undefined1 *)puVar5,param_1 + 0x14,uVar8);
      }
      uVar4 = 0;
    }
  }
  else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
    WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),param_2,puVar6,"Status",(char)uVar3,
                "onecore\\ds\\security\\cryptoapi\\ncrypt\\common\\translate.c",0x4a);
  }
  return uVar4;
}



===== VerifyLegacyRsaPublicBlob @ 180001ee0 =====

undefined8 VerifyLegacyRsaPublicBlob(char *param_1,uint param_2)

{
  if ((((0x13 < param_2) && (*param_1 == '\x06')) && (param_1[1] == '\x02')) &&
     (((*(short *)(param_1 + 2) == 0 && ((*(int *)(param_1 + 4) - 0x2400U & 0xffff7fff) == 0)) &&
      (*(int *)(param_1 + 8) == 0x31415352)))) {
    if (0x3f00 < *(int *)(param_1 + 0xc) - 0x100U) {
      return 0x80090029;
    }
    if ((*(int *)(param_1 + 0xc) + 7U >> 3) + 0x14 <= param_2) {
      return 0;
    }
  }
  return 0x80090005;
}



===== WPP_SF_qSq @ 180001f4c =====

void WPP_SF_qSq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               wchar_t *param_5,undefined1 param_6)

{
  longlong lVar1;
  undefined8 local_res20;
  
  if (param_5 == (wchar_t *)0x0) {
    lVar1 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_5[lVar1] != L'\0');
    lVar1 = lVar1 * 2 + 2;
  }
  if (param_5 == (wchar_t *)0x0) {
    param_5 = L"NULL";
  }
  local_res20 = param_4;
  EtwTraceMessage(param_1,0x2b,&WPP_67679bdabad938a7dfcc8815ccec1def_Traceguids,0x12,&local_res20,8,
                  param_5,lVar1,&param_6,8,0);
  return;
}



===== SslEnumCipherSuitesEx @ 180002000 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void SslEnumCipherSuitesEx
               (uint *param_1,uint *param_2,undefined8 *param_3,longlong *param_4,undefined4 param_5
               )

{
  uint uVar1;
  uint *puVar2;
  undefined8 *puVar3;
  uint *puVar4;
  undefined8 *puVar5;
  undefined1 uVar6;
  undefined8 uVar7;
  undefined1 uVar8;
  longlong *plVar9;
  
                    /* 0x2000  126  SslEnumCipherSuitesEx */
  puVar4 = (uint *)0x0;
  puVar5 = (undefined8 *)0x0;
  plVar9 = param_4;
  puVar2 = ValidateSslProvHandle(param_1);
  if (puVar2 == (uint *)0x0) {
    uVar1 = 0x80090026;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),param_2,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c","Status",0x26,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",0x2b);
    }
    goto LAB_180002139;
  }
  if ((ushort)puVar2[8] < 4) {
    uVar1 = 0x80090029;
    uVar8 = 0x38;
    uVar6 = 0x29;
  }
  else {
    if (param_2 != (uint *)0x0) {
      puVar4 = ValidateSslKeyHandle(param_2);
      if (puVar4 == (uint *)0x0) {
        uVar1 = 0x80090026;
        uVar8 = 0x42;
        uVar6 = 0x26;
        goto LAB_180002293;
      }
    }
    if ((param_3 != (undefined8 *)0x0) && (param_4 != (longlong *)0x0)) {
      if (*plVar9 == 0) {
        puVar5 = (undefined8 *)MSCryptAlloc(0x20);
        if (puVar5 == (undefined8 *)0x0) {
          uVar1 = 0x8009000e;
          uVar8 = 0x5b;
          uVar6 = 0xe;
          goto LAB_180002293;
        }
        *puVar5 = 0;
        puVar5[1] = 0;
        puVar5[2] = 0;
        puVar5[3] = 0;
      }
      puVar3 = (undefined8 *)MSCryptAlloc(0x20);
      if (puVar3 == (undefined8 *)0x0) {
        uVar1 = 0x8009000e;
        DebugTraceError(0xe,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",
                        0x6b);
      }
      else {
        *puVar3 = 0;
        puVar3[1] = 0;
        puVar3[2] = 0;
        puVar3[3] = 0;
        if (puVar4 == (uint *)0x0) {
          uVar7 = 0;
        }
        else {
          uVar7 = *(undefined8 *)(puVar4 + 4);
        }
        uVar1 = (**(code **)(puVar2 + 0x52))
                          (*(undefined8 *)(puVar2 + 0x6a),uVar7,param_3,param_4,param_5);
        if (-1 < (int)uVar1) {
          if (puVar5 != (undefined8 *)0x0) {
            LOCK();
            puVar2[4] = puVar2[4] + 1;
            UNLOCK();
            *puVar5 = puVar2;
            puVar5[1] = *param_4;
            MSCryptAddMemoryBuffer(0x1800278a0,(longlong)puVar5);
          }
          LOCK();
          puVar2[4] = puVar2[4] + 1;
          UNLOCK();
          *puVar3 = puVar2;
          puVar3[1] = *param_3;
          MSCryptAddMemoryBuffer(0x1800278a0,(longlong)puVar3);
          uVar1 = 0;
          goto LAB_180002139;
        }
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
          WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),uVar7,
                      "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c","Status",
                      (char)uVar1,"onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",0x7d)
          ;
        }
      }
      if (puVar5 != (undefined8 *)0x0) {
        SafeAllocaFreeToHeap(puVar5);
      }
      if (puVar3 != (undefined8 *)0x0) {
        SafeAllocaFreeToHeap(puVar3);
      }
      goto LAB_180002139;
    }
    uVar1 = 0x80090027;
    uVar8 = 0x4a;
    uVar6 = 0x27;
  }
LAB_180002293:
  DebugTraceError(uVar6,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",uVar8)
  ;
LAB_180002139:
  NormalizeNteStatus(uVar1);
  return;
}



===== MSCryptAddMemoryBuffer @ 1800022b4 =====

void MSCryptAddMemoryBuffer(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  code *pcVar2;
  longlong *plVar3;
  
  RtlEnterCriticalSection(&DAT_180027d20);
  plVar1 = *(longlong **)(param_1 + 8);
  plVar3 = (longlong *)(param_2 + 0x10);
  if (*plVar1 == param_1) {
    *plVar3 = param_1;
    *(longlong **)(param_2 + 0x18) = plVar1;
    *plVar1 = (longlong)plVar3;
    *(longlong **)(param_1 + 8) = plVar3;
                    /* WARNING: Could not recover jumptable at 0x000180002303. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    RtlLeaveCriticalSection(&DAT_180027d20);
    return;
  }
  pcVar2 = (code *)swi(0x29);
  (*pcVar2)(3);
  pcVar2 = (code *)swi(3);
  (*pcVar2)();
  return;
}



===== SslOpenProvider @ 180002320 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SslOpenProvider(undefined8 *param_1,char *param_2,char *param_3)

{
  uint uVar1;
  undefined4 *_Dst;
  wchar_t *pszProvider;
  undefined1 auStackY_288 [32];
  undefined1 uVar2;
  _CRYPT_PROVIDER_REFS *local_248;
  ULONG local_240 [2];
  _CRYPT_PROVIDER_REFS local_238 [32];
  ulonglong local_38;
  
                    /* 0x2320  158  SslOpenProvider */
  local_38 = __security_cookie ^ (ulonglong)auStackY_288;
  _Dst = (undefined4 *)0x0;
  local_240[0] = 0x200;
  local_248 = local_238;
  if ((param_1 == (undefined8 *)0x0) || ((int)param_3 != 0)) {
    uVar1 = 0xc000000d;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_180002496;
    uVar2 = 0xa3;
    uVar1 = 0xc000000d;
LAB_180002473:
    WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),param_2,param_3,"Status",(char)uVar1,
                "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",uVar2);
  }
  else {
    pszProvider = L"Microsoft SSL Protocol Provider";
    if (param_2 != (char *)0x0) {
      pszProvider = (wchar_t *)param_2;
    }
    do {
      param_3 = (char *)0x0;
      param_2 = (char *)0x10002;
      uVar1 = BCryptResolveProviders
                        ((LPCWSTR)0x0,0x10002,(LPCWSTR)0x0,pszProvider,1,0,local_240,&local_248);
      if (uVar1 != 0xc0000023) break;
      if (local_248 != local_238) {
        SafeAllocaFreeToHeap(local_248);
      }
      local_248 = (_CRYPT_PROVIDER_REFS *)MSCryptAlloc((ulonglong)local_240[0]);
      if (local_248 == (_CRYPT_PROVIDER_REFS *)0x0) {
        param_2 = "Status";
        param_3 = "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c";
        uVar1 = 0xc0000017;
        DebugTraceError(0x17,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",
                        0xd4);
      }
    } while (local_248 != (_CRYPT_PROVIDER_REFS *)0x0);
    if ((int)uVar1 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
        uVar2 = 0xdb;
        goto LAB_180002473;
      }
    }
    else {
      _Dst = (undefined4 *)MSCryptAlloc(0x1b0);
      if (_Dst == (undefined4 *)0x0) {
        uVar1 = 0xc0000017;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
          uVar2 = 0xf0;
          uVar1 = 0xc0000017;
          goto LAB_180002473;
        }
      }
      else {
        memset(_Dst,0,0x1b0);
        param_2 = (char *)(_Dst + 8);
        param_3 = (char *)0x188;
        uVar1 = LoadProviderEx(&(*local_248->rgpProviders)->dwInterface,param_2,0x188,
                               (undefined8 *)(_Dst + 6),param_2);
        if ((int)uVar1 < 0) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
            uVar2 = 5;
            goto LAB_180002473;
          }
        }
        else {
          param_3 = (char *)0x0;
          uVar1 = (**(code **)(_Dst + 0x32))(_Dst + 0x6a);
          if ((int)uVar1 < 0) {
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
              uVar2 = 0x15;
              param_2 = (char *)pszProvider;
              goto LAB_180002473;
            }
          }
          else {
            _Dst[2] = 0;
            _Dst[3] = 0;
            *_Dst = 0x1b0;
            _Dst[1] = 0x44444441;
            _Dst[4] = 1;
            *param_1 = _Dst;
            _Dst = (undefined4 *)0x0;
            uVar1 = 0;
          }
        }
      }
    }
  }
  if ((local_248 != (_CRYPT_PROVIDER_REFS *)0x0) && (local_248 != local_238)) {
    SafeAllocaFreeToHeap(local_248);
  }
  if (_Dst != (undefined4 *)0x0) {
    if (*(undefined8 **)(_Dst + 6) != (undefined8 *)0x0) {
      UnloadProvider(*(undefined8 **)(_Dst + 6));
    }
    SafeAllocaFreeToHeap(_Dst);
  }
LAB_180002496:
  NormalizeNteStatus(uVar1);
  return;
}



===== NCryptEnumKeys @ 180002660 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

SECURITY_STATUS __stdcall
NCryptEnumKeys(NCRYPT_PROV_HANDLE hProvider,LPCWSTR pszScope,NCryptKeyName **ppKeyName,
              PVOID *ppEnumState,DWORD dwFlags)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  int *piVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  undefined1 uVar7;
  undefined **ppuVar8;
  LPCWSTR pWVar9;
  NCryptKeyName **ppNVar10;
  wchar_t *pwVar11;
  undefined1 uVar12;
  PVOID local_38 [2];
  
                    /* 0x2660  77  NCryptEnumKeys */
  puVar6 = (undefined8 *)0x0;
  local_38[0] = (PVOID)0x0;
  ppNVar10 = ppKeyName;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    WPP_SF_PSD(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x1a,ppKeyName,hProvider,pszScope,
               (char)dwFlags);
  }
  ppuVar8 = &WPP_GLOBAL_Control;
  piVar3 = ValidateAndReferenceProvider((int *)hProvider);
  piVar4 = ValidateAndReferenceProvider((int *)hProvider);
  if ((piVar3 == (int *)0x0) || (piVar4 == (int *)0x0)) {
    uVar2 = 0x80090026;
    if (((undefined **)WPP_GLOBAL_Control != ppuVar8) && ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),ppuVar8,ppNVar10,"Status",0x26,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",0xce);
    }
    uVar1 = 0x80090026;
    if (piVar3 == (int *)0x0) goto LAB_180002844;
  }
  else if ((ppKeyName == (NCryptKeyName **)0x0) || (ppEnumState == (PVOID *)0x0)) {
    uVar1 = 0x80090027;
    uVar12 = 0xd5;
    uVar7 = 0x27;
LAB_180002986:
    DebugTraceError(uVar7,"Status",
                    "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",uVar12);
  }
  else {
    local_38[0] = *ppEnumState;
    if (local_38[0] == (PVOID)0x0) {
      puVar6 = (undefined8 *)MSCryptAlloc(0x20);
      if (puVar6 == (undefined8 *)0x0) {
        uVar1 = 0x8009000e;
        uVar12 = 0xe9;
        uVar7 = 0xe;
        goto LAB_180002986;
      }
      *puVar6 = 0;
      puVar6[1] = 0;
      puVar6[2] = 0;
      puVar6[3] = 0;
    }
    puVar5 = (undefined8 *)MSCryptAlloc(0x20);
    if (puVar5 == (undefined8 *)0x0) {
      uVar1 = 0x8009000e;
      DebugTraceError(0xe,"Status",
                      "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",0xfa);
    }
    else {
      *puVar5 = 0;
      puVar5[1] = 0;
      puVar5[2] = 0;
      puVar5[3] = 0;
      do {
        pWVar9 = pszScope;
        pwVar11 = (wchar_t *)ppKeyName;
        uVar1 = (**(code **)(piVar3 + 0x26))
                          (*(undefined8 *)(piVar3 + 0x44),pszScope,ppKeyName,local_38,dwFlags);
        if (uVar1 != 0x8009002e) {
          if (uVar1 == 0) {
            if (puVar6 == (undefined8 *)0x0) {
              if (local_38[0] != *ppEnumState) {
                uVar1 = 0x80090020;
                goto LAB_1800028dc;
              }
            }
            else {
              puVar6[1] = local_38[0];
              *puVar6 = piVar3;
              MSCryptAddMemoryBuffer(0x1800278b8,(longlong)puVar6);
            }
            puVar5[1] = *ppKeyName;
            *puVar5 = piVar4;
            MSCryptAddMemoryBuffer(0x1800278b8,(longlong)puVar5);
            uVar2 = 0;
            *ppEnumState = local_38[0];
            goto LAB_1800027c1;
          }
          break;
        }
        if ((dwFlags & 0x40) != 0) {
          uVar1 = 0x80090022;
          if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
             ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_1800028ce;
          uVar7 = 0x12;
          uVar1 = 0x80090022;
          goto LAB_1800028be;
        }
        pwVar11 = L"NCryptEnumKeys";
        pWVar9 = (LPCWSTR)0x0;
        uVar1 = (**(code **)(piVar3 + 0x30))(*(undefined8 *)(piVar3 + 0x44),0,L"NCryptEnumKeys",0);
      } while (uVar1 == 0);
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
        uVar7 = 0x24;
LAB_1800028be:
        WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),pWVar9,pwVar11,"Status",(char)uVar1,
                    "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",uVar7);
      }
    }
LAB_1800028ce:
    if (puVar6 != (undefined8 *)0x0) {
      SafeAllocaFreeToHeap(puVar6);
    }
    if (puVar5 != (undefined8 *)0x0) {
LAB_1800028dc:
      SafeAllocaFreeToHeap(puVar5);
    }
  }
  uVar2 = uVar1;
  DereferenceProvider((longlong)piVar3);
LAB_180002844:
  if (piVar4 != (int *)0x0) {
    DereferenceProvider((longlong)piVar4);
  }
LAB_1800027c1:
  if ((puVar6 == (undefined8 *)0x0) && (uVar2 == 0)) {
    DereferenceProvider((longlong)piVar3);
  }
  uVar2 = NormalizeNteStatus(uVar2);
  return uVar2;
}



===== _LoadImage @ 1800029dc =====

int _LoadImage(longlong param_1,longlong *param_2)

{
  LPCWSTR lpLibFileName;
  int iVar1;
  DWORD DVar2;
  HMODULE pHVar3;
  LPCWSTR *ppWVar4;
  undefined8 uVar5;
  LPCWSTR local_res8;
  undefined8 local_38;
  wchar_t *local_30;
  ushort local_28 [8];
  
  local_res8 = (LPCWSTR)0x0;
  local_38 = 0x160014;
  local_30 = L"ncrypt.dll";
  local_28[0] = 0;
  local_28[1] = 0;
  local_28[2] = 0;
  local_28[3] = 0;
  local_28[4] = 0;
  local_28[5] = 0;
  local_28[6] = 0;
  local_28[7] = 0;
  RtlInitUnicodeString(local_28,**(undefined8 **)(param_1 + 0x28));
  ppWVar4 = &local_res8;
  iVar1 = _GetImagePath(local_28,ppWVar4);
  lpLibFileName = local_res8;
  if (iVar1 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),ppWVar4,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\loader\\loader.c","sResult",(char)iVar1
                  ,"onecore\\ds\\security\\cryptoapi\\ncrypt\\loader\\loader.c",0xab);
    }
  }
  else {
    *param_2 = 0;
    iVar1 = RtlCompareUnicodeString(local_28,&local_38);
    if (iVar1 == 0) {
      *param_2 = g_hInstance;
    }
    if (*param_2 == 0) {
      uVar5 = 0;
      pHVar3 = LoadLibraryExW(lpLibFileName,(HANDLE)0x0,0);
      *param_2 = (longlong)pHVar3;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((WPP_GLOBAL_Control[0x1c] & 0x20) != 0)) {
        WPP_SF_qSq(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),pHVar3,uVar5,param_1,lpLibFileName,
                   (char)pHVar3);
      }
      if (*param_2 == 0) {
        DVar2 = GetLastError();
        iVar1 = -0x3ffffecb;
        if (DVar2 != 0x7e) {
          iVar1 = -0x3fffff85;
        }
        DebugTraceError((char)iVar1,"sResult",
                        "onecore\\ds\\security\\cryptoapi\\ncrypt\\loader\\loader.c",200);
        goto LAB_180002ac2;
      }
    }
    iVar1 = 0;
  }
LAB_180002ac2:
  if (lpLibFileName != (LPCWSTR)0x0) {
    SafeAllocaFreeToHeap(lpLibFileName);
  }
  return iVar1;
}



===== _GetImagePath @ 180002b7c =====

undefined4 _GetImagePath(ushort *param_1,undefined8 *param_2)

{
  ushort uVar1;
  UINT UVar2;
  LPWSTR lpBuffer;
  ulonglong uVar3;
  undefined4 uVar4;
  undefined1 uVar5;
  
  *param_2 = 0;
  lpBuffer = (LPWSTR)0x0;
  UVar2 = GetSystemDirectoryW((LPWSTR)0x0,0);
  if (UVar2 == 0) {
    uVar5 = 0x19;
  }
  else {
    lpBuffer = (LPWSTR)MSCryptAlloc((ulonglong)*param_1 + 4 + (ulonglong)UVar2 * 2);
    if (lpBuffer == (LPWSTR)0x0) {
      uVar4 = 0xc0000017;
      uVar5 = 0x22;
      goto LAB_180002c57;
    }
    UVar2 = GetSystemDirectoryW(lpBuffer,UVar2);
    if (UVar2 != 0) {
      uVar3 = (ulonglong)UVar2;
      lpBuffer[uVar3] = L'\\';
      memcpy(lpBuffer + uVar3 + 1,*(void **)(param_1 + 4),(ulonglong)*param_1);
      uVar1 = *param_1;
      *param_2 = lpBuffer;
      lpBuffer[(uVar1 >> 1) + uVar3 + 1] = L'\0';
      return 0;
    }
    uVar5 = 0x2b;
  }
  uVar4 = 0xc000003a;
LAB_180002c57:
  DebugTraceError((char)uVar4,"sResult","onecore\\ds\\security\\cryptoapi\\ncrypt\\loader\\loader.c"
                  ,uVar5);
  if (lpBuffer != (LPWSTR)0x0) {
    SafeAllocaFreeToHeap(lpBuffer);
  }
  return uVar4;
}



===== DeserializeCurveNameList @ 180002c84 =====

undefined8
DeserializeCurveNameList(byte *param_1,ulonglong param_2,uint *param_3,uint param_4,uint *param_5)

{
  byte bVar1;
  HRESULT HVar2;
  uint uVar3;
  uint uVar4;
  longlong lVar5;
  undefined8 uVar6;
  STRSAFE_LPCWSTR pszSrc;
  STRSAFE_LPCWSTR pwVar7;
  ulonglong uVar8;
  STRSAFE_LPWSTR pszDest;
  undefined1 uVar9;
  undefined1 uVar10;
  
  uVar6 = 0;
  if (param_1 == (byte *)0x0) {
    uVar6 = 0x80090027;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      uVar10 = 0xf1;
      uVar9 = 0x27;
      pwVar7 = (STRSAFE_LPCWSTR)0x0;
LAB_180002d65:
      WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),param_2,pwVar7,"Status",uVar9,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",uVar10);
    }
  }
  else {
    bVar1 = *param_1;
    uVar8 = (ulonglong)bVar1;
    uVar3 = (int)param_2 + 0xc + (uint)bVar1 * 8;
    *param_5 = uVar3;
    if (param_3 != (uint *)0x0) {
      if (param_4 < uVar3) {
        uVar6 = 0x80090028;
      }
      else {
        *param_3 = (uint)bVar1;
        *(uint **)(param_3 + 2) = param_3 + 4;
        pszDest = (STRSAFE_LPWSTR)(param_3 + 4 + uVar8 * 2);
        pszSrc = (STRSAFE_LPCWSTR)(param_1 + 4);
        for (uVar3 = 0; uVar3 < (uint)uVar8; uVar3 = uVar3 + 1) {
          lVar5 = -1;
          do {
            lVar5 = lVar5 + 1;
          } while (pszSrc[lVar5] != L'\0');
          uVar4 = (int)lVar5 + 1;
          param_2 = (ulonglong)uVar4;
          *(STRSAFE_LPWSTR *)(*(longlong *)(param_3 + 2) + (ulonglong)uVar3 * 8) = pszDest;
          pwVar7 = pszSrc;
          HVar2 = StringCchCopyW(pszDest,param_2,pszSrc);
          if (HVar2 < 0) {
            uVar6 = 0xc00000e5;
            if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
              return 0xc00000e5;
            }
            if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
              return 0xc00000e5;
            }
            uVar10 = 0x16;
            uVar9 = 0xe5;
            goto LAB_180002d65;
          }
          pszSrc = pszSrc + uVar4;
          pszDest = pszDest + uVar4;
        }
      }
    }
  }
  return uVar6;
}



===== StringCchCopyW @ 180002ddc =====

HRESULT __stdcall StringCchCopyW(STRSAFE_LPWSTR pszDest,size_t cchDest,STRSAFE_LPCWSTR pszSrc)

{
  wchar_t wVar1;
  uint uVar2;
  STRSAFE_LPWSTR pwVar3;
  longlong lVar4;
  longlong lVar5;
  
  if (cchDest - 1 < 0x7fffffff) {
    lVar4 = 0x7ffffffe - cchDest;
    lVar5 = (longlong)pszSrc - (longlong)pszDest;
    do {
      if ((lVar4 + cchDest == 0) ||
         (wVar1 = *(wchar_t *)(lVar5 + (longlong)pszDest), wVar1 == L'\0')) break;
      *pszDest = wVar1;
      pszDest = pszDest + 1;
      cchDest = cchDest - 1;
    } while (cchDest != 0);
    pwVar3 = pszDest + -1;
    if (cchDest != 0) {
      pwVar3 = pszDest;
    }
    *pwVar3 = L'\0';
    uVar2 = ~-(uint)(cchDest != 0) & 0x8007007a;
  }
  else {
    uVar2 = 0x80070057;
    if (cchDest != 0) {
      *pszDest = L'\0';
      return -0x7ff8ffa9;
    }
  }
  return uVar2;
}



===== CNG_OpenProtectionDescriptor @ 180002e50 =====

NTSTATUS CNG_OpenProtectionDescriptor(uint *param_1,uint param_2)

{
  uint uVar1;
  NTSTATUS NVar2;
  longlong lVar3;
  longlong lVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  undefined8 local_res8;
  
  local_res8 = 0;
  uVar5 = 0;
  if (*param_1 != 0) {
    lVar4 = 0;
    do {
      uVar6 = 0;
      if (*(int *)(lVar4 + *(longlong *)(param_1 + 2)) != 0) {
        lVar3 = 0;
        do {
          uVar1 = Feature_690454842__private_IsEnabledDeviceUsageNoInline();
          if (uVar1 == 0) {
            NVar2 = NCryptOpenKeyProtector
                              (&local_res8,
                               *(LPCWSTR *)
                                (*(longlong *)(lVar4 + 8 + *(longlong *)(param_1 + 2)) + lVar3),0);
            if ((NVar2 != 0) &&
               (DebugTraceError((char)NVar2,"Status",
                                "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\descriptor.c"
                                ,0x85), (param_2 & 1) == 0)) {
              return NVar2;
            }
            *(undefined8 *)(*(longlong *)(lVar4 + 8 + *(longlong *)(param_1 + 2)) + 0x10 + lVar3) =
                 local_res8;
            *(undefined4 *)(*(longlong *)(lVar4 + 8 + *(longlong *)(param_1 + 2)) + 0x18 + lVar3) =
                 1;
          }
          else {
            local_res8 = 0;
            NVar2 = NCryptOpenKeyProtector
                              (&local_res8,
                               *(LPCWSTR *)
                                (*(longlong *)(lVar4 + 8 + *(longlong *)(param_1 + 2)) + lVar3),0);
            if (NVar2 == 0) {
              *(undefined8 *)(*(longlong *)(lVar4 + 8 + *(longlong *)(param_1 + 2)) + 0x10 + lVar3)
                   = local_res8;
              *(undefined4 *)(*(longlong *)(lVar4 + 8 + *(longlong *)(param_1 + 2)) + 0x18 + lVar3)
                   = 1;
              local_res8 = 0;
            }
            else {
              DebugTraceError((char)NVar2,"Status",
                              "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\descriptor.c"
                              ,0x6e);
              if ((param_2 & 1) == 0) {
                return NVar2;
              }
            }
          }
          uVar6 = uVar6 + 1;
          lVar3 = lVar3 + 0x20;
        } while (uVar6 < *(uint *)(lVar4 + *(longlong *)(param_1 + 2)));
      }
      uVar5 = uVar5 + 1;
      lVar4 = lVar4 + 0x20;
    } while (uVar5 < *param_1);
  }
  return 0;
}



===== CNG_DuplicateDescriptor @ 180002fc0 =====

char * CNG_DuplicateDescriptor(uint *param_1,undefined8 *param_2,uint param_3)

{
  short sVar1;
  uint uVar2;
  longlong lVar3;
  uint *_Dst;
  longlong lVar4;
  uint *puVar5;
  char *pcVar6;
  ulonglong uVar7;
  longlong lVar8;
  longlong lVar9;
  longlong lVar10;
  char *pcVar11;
  longlong lVar12;
  undefined8 *puVar13;
  short *psVar14;
  char *pcVar15;
  longlong lVar16;
  char *_Size;
  longlong lVar17;
  longlong lVar18;
  char *pcVar19;
  uint *puVar20;
  char *pcVar21;
  longlong *plVar22;
  ulonglong uVar23;
  ulonglong uVar24;
  ulonglong uVar25;
  char *pcVar26;
  uint *puVar27;
  ulonglong uVar28;
  bool bVar29;
  uint *local_res8;
  undefined8 *local_res10;
  uint local_res18;
  uint *local_res20;
  undefined1 uVar30;
  
  *param_2 = 0;
  lVar18 = 0;
  uVar25 = (ulonglong)*param_1;
  lVar16 = uVar25 * 0x20 + 0x10;
  puVar13 = param_2;
  if (uVar25 != 0) {
    lVar4 = *(longlong *)(param_1 + 2);
    lVar17 = 0;
    do {
      uVar28 = 0;
      uVar23 = (ulonglong)*(uint *)(lVar17 + lVar4);
      lVar18 = lVar18 + uVar23;
      uVar7 = uVar28;
      if (uVar23 < 2) {
        if (uVar23 != 0) {
          lVar3 = *(longlong *)(lVar4 + 8 + lVar17);
          uVar24 = uVar28;
          goto LAB_18000302f;
        }
      }
      else {
        lVar3 = *(longlong *)(lVar4 + 8 + lVar17);
        lVar10 = (uVar23 - 2 >> 1) + 1;
        plVar22 = (longlong *)(lVar3 + 0x28);
        uVar24 = lVar10 * 2;
        do {
          lVar8 = -1;
          do {
            lVar8 = lVar8 + 1;
          } while (*(short *)(plVar22[-5] + lVar8 * 2) != 0);
          lVar12 = -1;
          do {
            lVar12 = lVar12 + 1;
          } while (*(short *)(plVar22[-4] + lVar12 * 2) != 0);
          lVar9 = -1;
          uVar7 = uVar7 + (lVar8 + lVar12) * 2 + 4;
          do {
            lVar9 = lVar9 + 1;
          } while (*(short *)(plVar22[-1] + lVar9 * 2) != 0);
          puVar13 = (undefined8 *)*plVar22;
          lVar8 = -1;
          do {
            lVar8 = lVar8 + 1;
          } while (*(short *)((longlong)puVar13 + lVar8 * 2) != 0);
          plVar22 = plVar22 + 8;
          uVar28 = uVar28 + (lVar9 + lVar8) * 2 + 4;
          lVar10 = lVar10 + -1;
        } while (lVar10 != 0);
        if (uVar24 < uVar23) {
LAB_18000302f:
          lVar10 = -1;
          do {
            lVar10 = lVar10 + 1;
          } while (*(short *)(*(longlong *)(uVar24 * 0x20 + 8 + lVar3) + lVar10 * 2) != 0);
          puVar13 = *(undefined8 **)(uVar24 * 0x20 + lVar3);
          lVar3 = -1;
          do {
            lVar3 = lVar3 + 1;
          } while (*(short *)((longlong)puVar13 + lVar3 * 2) != 0);
          lVar16 = lVar16 + (lVar10 + lVar3) * 2 + 4;
        }
      }
      lVar17 = lVar17 + 0x20;
      lVar16 = lVar16 + uVar28 + uVar7;
      uVar25 = uVar25 - 1;
    } while (uVar25 != 0);
  }
  _Size = (char *)(lVar16 + lVar18 * 0x20);
  local_res8 = param_1;
  local_res10 = param_2;
  local_res18 = param_3;
  _Dst = (uint *)MSCryptAlloc(_Size);
  if (_Dst == (uint *)0x0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),puVar13,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\descriptor.c",
                  "Status",0xe,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\descriptor.c",
                  0x5c);
    }
    pcVar19 = (char *)0x8009000e;
  }
  else {
    memset(_Dst,0,(size_t)_Size);
    uVar2 = *param_1;
    local_res20 = _Dst + 4;
    *(uint **)(_Dst + 2) = local_res20;
    *_Dst = uVar2;
    puVar27 = local_res20 + (ulonglong)*param_1 * 8;
    lVar16 = 0;
    puVar20 = puVar27 + lVar18 * 8;
    for (uVar25 = 0; pcVar19 = (char *)0x0, uVar25 < *param_1; uVar25 = uVar25 + 1) {
      local_res20[4] = *(uint *)(lVar16 + 0x10 + *(longlong *)(param_1 + 2));
      *(undefined8 *)(local_res20 + 6) = *(undefined8 *)(lVar16 + 0x18 + *(longlong *)(param_1 + 2))
      ;
      *local_res20 = *(uint *)(lVar16 + *(longlong *)(param_1 + 2));
      *(uint **)(local_res20 + 2) = puVar27;
      for (pcVar26 = pcVar19; pcVar11 = (char *)0x0,
          pcVar26 < (char *)(ulonglong)*(uint *)(lVar16 + *(longlong *)(param_1 + 2));
          pcVar26 = pcVar26 + 1) {
        *(uint **)puVar27 = puVar20;
        lVar18 = *(longlong *)(pcVar19 + *(longlong *)(lVar16 + 8 + *(longlong *)(param_1 + 2)));
        lVar4 = -1;
        do {
          lVar17 = lVar4;
          lVar4 = lVar17 + 1;
        } while (*(short *)(lVar18 + lVar4 * 2) != 0);
        if (lVar4 != 0) {
          lVar4 = lVar17 + 2;
          if (lVar17 + 1U < 0x7fffffff) {
            lVar17 = 0x7ffffffe - lVar4;
            _Size = (char *)puVar20;
            pcVar15 = pcVar11;
            do {
              if ((lVar17 + lVar4 == 0) ||
                 (sVar1 = *(short *)((lVar18 - (longlong)puVar20) + (longlong)_Size), sVar1 == 0))
              break;
              *(short *)_Size = sVar1;
              pcVar15 = pcVar15 + 1;
              _Size = (char *)((longlong)_Size + 2);
              lVar4 = lVar4 + -1;
            } while (lVar4 != 0);
            bVar29 = lVar4 != 0;
            puVar5 = (uint *)((longlong)_Size + -2);
            if (bVar29) {
              puVar5 = (uint *)_Size;
            }
            pcVar21 = (char *)0x8007007a;
            if (bVar29) {
              pcVar21 = pcVar11;
            }
            *(short *)puVar5 = 0;
            pcVar6 = pcVar15 + -1;
            if (bVar29) {
              pcVar6 = pcVar15;
            }
            puVar20 = (uint *)((longlong)puVar20 + (longlong)pcVar6 * 2);
LAB_18000329b:
            if (-1 < (int)pcVar21) goto LAB_180003157;
          }
          else {
            pcVar21 = (char *)0x80070057;
            if (lVar4 == 0) goto LAB_18000329b;
            *(short *)puVar20 = 0;
            pcVar21 = (char *)0x80070057;
          }
          pcVar19 = pcVar21;
          if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
             ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_1800032e6;
          uVar30 = 0x82;
LAB_1800032c6:
          _Size = "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\descriptor.c";
          pcVar21 = pcVar19;
          WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),pcVar19,
                      "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\descriptor.c"
                      ,"Status",(char)pcVar19,
                      "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\descriptor.c"
                      ,uVar30);
LAB_1800032e6:
          CNG_FreeProtectionDescriptor(_Dst,pcVar21,_Size);
          return pcVar19;
        }
LAB_180003157:
        *(short *)puVar20 = 0;
        puVar20 = (uint *)((longlong)puVar20 + 2);
        *(uint **)(puVar27 + 2) = puVar20;
        psVar14 = *(short **)(pcVar19 + *(longlong *)(lVar16 + 8 + *(longlong *)(param_1 + 2)) + 8);
        lVar18 = -1;
        do {
          lVar4 = lVar18;
          lVar18 = lVar4 + 1;
        } while (psVar14[lVar18] != 0);
        if (lVar18 != 0) {
          lVar18 = lVar4 + 2;
          if (lVar4 + 1U < 0x7fffffff) {
            lVar4 = 0x7ffffffe - lVar18;
            _Size = (char *)puVar20;
            pcVar21 = pcVar11;
            do {
              if ((lVar4 + lVar18 == 0) || (*psVar14 == 0)) break;
              *(short *)_Size = *psVar14;
              psVar14 = psVar14 + 1;
              _Size = (char *)((longlong)_Size + 2);
              pcVar21 = pcVar21 + 1;
              lVar18 = lVar18 + -1;
            } while (lVar18 != 0);
            bVar29 = lVar18 != 0;
            puVar5 = (uint *)((longlong)_Size + -2);
            if (bVar29) {
              puVar5 = (uint *)_Size;
            }
            pcVar15 = (char *)0x8007007a;
            if (bVar29) {
              pcVar15 = pcVar11;
            }
            *(short *)puVar5 = 0;
            pcVar11 = pcVar21 + -1;
            if (bVar29) {
              pcVar11 = pcVar21;
            }
            puVar20 = (uint *)((longlong)puVar20 + (longlong)pcVar11 * 2);
LAB_1800031fc:
            pcVar21 = pcVar15;
            if (-1 < (int)pcVar15) goto LAB_180003206;
          }
          else {
            pcVar15 = (char *)0x80070057;
            pcVar21 = (char *)0x80070057;
            if (lVar18 == 0) goto LAB_1800031fc;
            *(short *)puVar20 = 0;
          }
          pcVar19 = pcVar21;
          if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
             ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_1800032e6;
          uVar30 = 0x96;
          goto LAB_1800032c6;
        }
LAB_180003206:
        *(short *)puVar20 = 0;
        puVar20 = (uint *)((longlong)puVar20 + 2);
        if ((local_res18 & 1) != 0) {
          local_res8 = (uint *)0x0;
          lVar18 = *(longlong *)(lVar16 + 8 + *(longlong *)(param_1 + 2));
          if ((*(int **)(pcVar19 + lVar18 + 0x10) != (int *)0x0) &&
             (*(int *)(pcVar19 + lVar18 + 0x18) == 1)) {
            _Size = (char *)0x0;
            uVar7 = NCryptDuplicateKeyProtectorHandle
                              (*(int **)(pcVar19 + lVar18 + 0x10),&local_res8,0);
            if ((int)uVar7 != 0) {
              _Size = 
              "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\descriptor.c";
              pcVar21 = "Status";
              DebugTraceError((char)uVar7,"Status",
                              "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\descriptor.c"
                              ,0xaa);
              pcVar19 = (char *)(uVar7 & 0xffffffff);
              goto LAB_1800032e6;
            }
            *(uint **)(puVar27 + 4) = local_res8;
            puVar27[6] = 1;
          }
        }
        puVar27 = puVar27 + 8;
        pcVar19 = pcVar19 + 0x20;
      }
      local_res20 = local_res20 + 8;
      lVar16 = lVar16 + 0x20;
    }
    *local_res10 = _Dst;
  }
  return pcVar19;
}



===== NCryptImportKey @ 180003510 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

SECURITY_STATUS __stdcall
NCryptImportKey(NCRYPT_PROV_HANDLE hProvider,NCRYPT_KEY_HANDLE hImportKey,LPCWSTR pszBlobType,
               NCryptBufferDesc *pParameterList,NCRYPT_KEY_HANDLE *phKey,PBYTE pbData,DWORD cbData,
               DWORD dwFlags)

{
  undefined8 uVar1;
  code *pcVar2;
  NCryptBufferDesc *pNVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  undefined8 *puVar7;
  ulonglong uVar8;
  undefined1 uVar9;
  ulonglong uVar10;
  longlong lVar11;
  int *piVar12;
  wchar_t *pwVar13;
  undefined1 *puVar14;
  undefined1 *puVar15;
  undefined1 *puVar16;
  PBYTE pBVar17;
  wchar_t *pwVar18;
  undefined8 *puVar19;
  undefined1 uVar20;
  undefined8 uVar21;
  undefined1 auStackY_c8 [32];
  uint local_78 [2];
  int *local_70;
  undefined4 local_68 [2];
  int *local_60;
  int *local_58;
  NCryptBufferDesc *local_50;
  undefined8 local_48;
  ulonglong local_38;
  
                    /* 0x3510  85  NCryptImportKey */
  local_38 = __security_cookie ^ (ulonglong)local_78;
  local_58 = (int *)0x0;
  pBVar17 = (PBYTE)0x0;
  local_78[0] = 0;
  local_68[0] = 0;
  local_60 = (int *)hImportKey;
  local_50 = pParameterList;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    WPP_SF_PSD(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x1b,pszBlobType,hProvider,pszBlobType,
               (char)dwFlags);
  }
  if ((pszBlobType == (LPCWSTR)0x0) || (phKey == (NCRYPT_KEY_HANDLE *)0x0)) {
    uVar5 = 0x80090027;
    DebugTraceError(0x27,"Status",
                    "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",0x9a);
    puVar15 = auStackY_c8;
    goto LAB_1800036f6;
  }
  piVar12 = local_60;
  piVar6 = ValidateAndReferenceProvider((int *)hProvider);
  local_70 = piVar6;
  if (piVar6 == (int *)0x0) {
    uVar5 = 0x80090026;
    puVar15 = auStackY_c8;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (puVar15 = auStackY_c8, (WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),piVar12,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c","Status",0x26
                  ,"onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",0xa3);
      puVar15 = auStackY_c8;
    }
    goto LAB_1800036f6;
  }
  if (piVar12 == (int *)0x0) {
LAB_1800035d6:
    puVar15 = auStackY_c8;
    puVar14 = auStackY_c8;
    puVar16 = auStackY_c8;
    Feature_PKCS11_Shielded_Secrets__private_ReportDeviceUsage();
    iVar4 = wcscmp(pszBlobType,L"PUBLICBLOB");
    if (iVar4 == 0) {
      if (cbData < 0x14) {
        uVar5 = 0x80090027;
        uVar20 = 0xcf;
        uVar9 = 0x27;
        goto LAB_180003975;
      }
      local_48 = *(undefined8 *)(pbData + 8);
      if ((int)local_48 == 0x31415352) {
        pszBlobType = L"CAPIPUBLICBLOB";
      }
      else if ((int)local_48 == 0x31535344) {
LAB_1800039d3:
        pszBlobType = L"CAPIDSAPUBLICBLOB";
      }
      else if ((int)local_48 == 0x33484400) {
        pszBlobType = L"CAPIDHPUBLICBLOB";
      }
      else if ((int)local_48 == 0x33535344) goto LAB_1800039d3;
    }
    iVar4 = wcscmp(pszBlobType,L"CAPIPUBLICBLOB");
    if (iVar4 == 0) {
      pwVar13 = (wchar_t *)(ulonglong)cbData;
      uVar8 = ConvertLegacyRsaPublicBlob
                        ((char *)pbData,pwVar13,(undefined4 *)0x0,0,local_78,(int *)0x0);
      uVar5 = (uint)uVar8;
      if (uVar5 == 0) {
        uVar8 = (ulonglong)local_78[0];
        puVar15 = auStackY_c8;
        if ((((uVar8 == 0) || (puVar15 = auStackY_c8, g_ulMaxStackAllocSize < uVar8)) ||
            (uVar10 = g_ulAdditionalProbeSize + 8 + uVar8, puVar15 = auStackY_c8, uVar10 < uVar8))
           || (uVar21 = VerifyStackAvailable(uVar10), puVar15 = auStackY_c8, (int)uVar21 == 0)) {
LAB_180003816:
          puVar16 = puVar15;
          if (uVar8 <= uVar8 + 8) {
            *(undefined8 *)(puVar15 + -8) = 0x18000382f;
            pBVar17 = (PBYTE)(*g_pfnAllocate)();
            if (pBVar17 != (PBYTE)0x0) {
              builtin_memcpy(pBVar17,"Heap",4);
              pBVar17 = pBVar17 + 8;
            }
          }
        }
        else {
          uVar10 = uVar8 + 0x17;
          if (uVar10 <= uVar8 + 8) {
            uVar10 = 0xffffffffffffff0;
          }
          lVar11 = -(uVar10 & 0xfffffffffffffff0);
          puVar16 = auStackY_c8 + lVar11;
          pBVar17 = (PBYTE)0x0;
          puVar15 = auStackY_c8 + lVar11;
          if ((undefined4 *)((longlong)local_78 + lVar11) == (undefined4 *)0x0) goto LAB_180003816;
          *(undefined4 *)((longlong)local_78 + lVar11) = 0x6b637453;
          pBVar17 = (PBYTE)((longlong)local_78 + lVar11 + 8);
          puVar15 = auStackY_c8 + lVar11;
          if (pBVar17 == (PBYTE)0x0) goto LAB_180003816;
        }
        uVar5 = local_78[0];
        if (pBVar17 != (PBYTE)0x0) {
          *(undefined4 **)(puVar16 + 0x28) = local_68;
          pwVar13 = (wchar_t *)(ulonglong)cbData;
          *(uint **)(puVar16 + 0x20) = local_78;
          *(undefined8 *)(puVar16 + -8) = 0x180003929;
          uVar8 = ConvertLegacyRsaPublicBlob
                            ((char *)pbData,pwVar13,(undefined4 *)pBVar17,uVar5,
                             *(uint **)(puVar16 + 0x20),*(int **)(puVar16 + 0x28));
          uVar5 = (uint)uVar8;
          if (uVar5 == 0) {
            pwVar18 = L"RSAPUBLICBLOB";
            goto LAB_180003936;
          }
          uVar20 = 7;
          goto LAB_180003973;
        }
        uVar20 = 0xfa;
LAB_180003a01:
        uVar5 = 0x8009000e;
        uVar9 = 0xe;
        puVar15 = puVar16;
        goto LAB_180003975;
      }
      puVar16 = auStackY_c8;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (puVar16 = auStackY_c8, (WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
LAB_180003780:
        uVar21 = *(undefined8 *)(WPP_GLOBAL_Control + 0x10);
        *(undefined8 *)(puVar14 + -8) = 0x180003790;
        WPP_SF_sDsd(uVar21,pwVar13,
                    "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c","Status",
                    puVar14[0x20],*(char **)(puVar14 + 0x28),puVar14[0x30]);
        puVar16 = puVar14;
      }
    }
    else {
      iVar4 = wcscmp(pszBlobType,L"CAPIDSAPUBLICBLOB");
      if ((iVar4 == 0) || (iVar4 = wcscmp(pszBlobType,L"V2CAPIDSAPUBLICBLOB"), iVar4 == 0)) {
        uVar5 = ConvertLegacyDsaPublicBlob((ulonglong *)pbData,cbData,(undefined4 *)0x0,0,local_78);
        if (uVar5 == 0) {
          uVar8 = (ulonglong)local_78[0];
          puVar15 = auStackY_c8;
          if (((uVar8 == 0) || (puVar15 = auStackY_c8, g_ulMaxStackAllocSize < uVar8)) ||
             ((uVar10 = g_ulAdditionalProbeSize + 8 + uVar8, puVar15 = auStackY_c8, uVar10 < uVar8
              || (uVar21 = VerifyStackAvailable(uVar10), puVar15 = auStackY_c8, (int)uVar21 == 0))))
          {
LAB_180003ba7:
            puVar16 = puVar15;
            if (uVar8 <= uVar8 + 8) {
              *(undefined8 *)(puVar15 + -8) = 0x180003bbc;
              pBVar17 = (PBYTE)(*g_pfnAllocate)();
              if (pBVar17 != (PBYTE)0x0) {
                builtin_memcpy(pBVar17,"Heap",4);
                pBVar17 = pBVar17 + 8;
              }
            }
          }
          else {
            uVar10 = uVar8 + 0x17;
            if (uVar10 <= uVar8 + 8) {
              uVar10 = 0xffffffffffffff0;
            }
            lVar11 = -(uVar10 & 0xfffffffffffffff0);
            pBVar17 = (PBYTE)0x0;
            puVar15 = auStackY_c8 + lVar11;
            if ((undefined4 *)((longlong)local_78 + lVar11) == (undefined4 *)0x0)
            goto LAB_180003ba7;
            *(undefined4 *)((longlong)local_78 + lVar11) = 0x6b637453;
            pBVar17 = (PBYTE)((longlong)local_78 + lVar11 + 8);
            puVar15 = auStackY_c8 + lVar11;
            puVar16 = auStackY_c8 + lVar11;
            if (pBVar17 == (PBYTE)0x0) goto LAB_180003ba7;
          }
          uVar5 = local_78[0];
          if (pBVar17 == (PBYTE)0x0) {
            uVar20 = 0x22;
            goto LAB_180003a01;
          }
          *(uint **)(puVar16 + 0x20) = local_78;
          pwVar13 = (wchar_t *)(ulonglong)cbData;
          *(undefined8 *)(puVar16 + -8) = 0x180003bf2;
          uVar5 = ConvertLegacyDsaPublicBlob
                            ((ulonglong *)pbData,cbData,(undefined4 *)pBVar17,uVar5,
                             *(uint **)(puVar16 + 0x20));
          if (uVar5 == 0) {
            pwVar18 = L"DSAPUBLICBLOB";
            goto LAB_180003936;
          }
          uVar20 = 0x2e;
        }
        else {
          uVar20 = 0x1a;
        }
LAB_180003973:
        uVar9 = (undefined1)uVar5;
        puVar15 = puVar16;
        goto LAB_180003975;
      }
      pwVar13 = L"CAPIDHPUBLICBLOB";
      iVar4 = wcscmp(pszBlobType,L"CAPIDHPUBLICBLOB");
      puVar16 = auStackY_c8;
      if (iVar4 == 0) {
        uVar5 = ConvertLegacyDhPublicBlob((undefined8 *)pbData,cbData,(undefined4 *)0x0,0,local_78);
        if (uVar5 != 0) {
          uVar20 = 0x40;
          puVar16 = auStackY_c8;
          goto LAB_180003973;
        }
        uVar8 = (ulonglong)local_78[0];
        puVar15 = auStackY_c8;
        if ((((uVar8 == 0) || (puVar15 = auStackY_c8, g_ulMaxStackAllocSize < uVar8)) ||
            (uVar10 = g_ulAdditionalProbeSize + 8 + uVar8, puVar15 = auStackY_c8, uVar10 < uVar8))
           || (uVar21 = VerifyStackAvailable(uVar10), puVar15 = auStackY_c8, (int)uVar21 == 0)) {
LAB_180003aa4:
          puVar16 = puVar15;
          if (uVar8 <= uVar8 + 8) {
            *(undefined8 *)(puVar15 + -8) = 0x180003ab9;
            pBVar17 = (PBYTE)(*g_pfnAllocate)();
            if (pBVar17 != (PBYTE)0x0) {
              builtin_memcpy(pBVar17,"Heap",4);
              pBVar17 = pBVar17 + 8;
            }
          }
        }
        else {
          uVar10 = uVar8 + 0x17;
          if (uVar10 <= uVar8 + 8) {
            uVar10 = 0xffffffffffffff0;
          }
          lVar11 = -(uVar10 & 0xfffffffffffffff0);
          pBVar17 = (PBYTE)0x0;
          puVar15 = auStackY_c8 + lVar11;
          if ((undefined4 *)((longlong)local_78 + lVar11) == (undefined4 *)0x0) goto LAB_180003aa4;
          *(undefined4 *)((longlong)local_78 + lVar11) = 0x6b637453;
          pBVar17 = (PBYTE)((longlong)local_78 + lVar11 + 8);
          puVar15 = auStackY_c8 + lVar11;
          puVar16 = auStackY_c8 + lVar11;
          if (pBVar17 == (PBYTE)0x0) goto LAB_180003aa4;
        }
        uVar5 = local_78[0];
        if (pBVar17 == (PBYTE)0x0) {
          uVar20 = 0x48;
          goto LAB_180003a01;
        }
        *(uint **)(puVar16 + 0x20) = local_78;
        pwVar13 = (wchar_t *)(ulonglong)cbData;
        *(undefined8 *)(puVar16 + -8) = 0x180003af6;
        uVar5 = ConvertLegacyDhPublicBlob
                          ((undefined8 *)pbData,cbData,(undefined4 *)pBVar17,uVar5,
                           *(uint **)(puVar16 + 0x20));
        if (uVar5 != 0) {
          uVar20 = 0x54;
          goto LAB_180003973;
        }
        pwVar18 = L"DHPUBLICBLOB";
LAB_180003936:
        piVar6 = local_70;
        pszBlobType = pwVar18;
        pbData = pBVar17;
        cbData = local_78[0];
      }
      *(undefined8 *)(puVar16 + -8) = 0x180003666;
      puVar7 = (undefined8 *)MSCryptAlloc(0x30);
      if (puVar7 == (undefined8 *)0x0) {
        uVar5 = 0x8009000e;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
          *(undefined4 *)(puVar16 + 0x30) = 0xc67;
          *(char **)(puVar16 + 0x28) =
               "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c";
          *(undefined4 *)(puVar16 + 0x20) = 0x8009000e;
          puVar14 = puVar16;
          uVar5 = 0x8009000e;
          goto LAB_180003780;
        }
      }
      else {
        *puVar7 = 0;
        puVar7[1] = 0;
        puVar7[2] = 0;
        puVar7[3] = 0;
        puVar7[4] = 0;
        puVar7[5] = 0;
        *(undefined4 *)puVar7 = 0x44440002;
        puVar7[1] = piVar6;
        while( true ) {
          pNVar3 = local_50;
          if (local_60 == (int *)0x0) {
            uVar21 = 0;
          }
          else {
            uVar21 = *(undefined8 *)(local_58 + 4);
          }
          uVar1 = *(undefined8 *)(piVar6 + 0x44);
          *(DWORD *)(puVar16 + 0x38) = dwFlags;
          pcVar2 = *(code **)(piVar6 + 0x28);
          *(DWORD *)(puVar16 + 0x30) = cbData;
          *(PBYTE *)(puVar16 + 0x28) = pbData;
          *(undefined8 **)(puVar16 + 0x20) = puVar7 + 2;
          *(undefined8 *)(puVar16 + -8) = 0x1800036ce;
          uVar5 = (*pcVar2)(uVar1,uVar21,pszBlobType,pNVar3);
          if (uVar5 != 0x8009002e) break;
          if ((dwFlags & 0x40) != 0) {
            uVar5 = 0x80090022;
            *(undefined8 *)(puVar16 + -8) = 0x180003c7a;
            DebugTraceError(0x22,"Status",
                            "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",
                            0x85);
            goto LAB_180003cb4;
          }
          uVar21 = *(undefined8 *)(local_70 + 0x44);
          pcVar2 = *(code **)(local_70 + 0x30);
          *(undefined8 *)(puVar16 + -8) = 0x180003c48;
          uVar5 = (*pcVar2)(uVar21,0,L"NCryptImportKey",0);
          if (uVar5 != 0) goto LAB_180003c7c;
          piVar6 = local_70;
        }
        if (uVar5 == 0) {
          *phKey = (NCRYPT_KEY_HANDLE)puVar7;
          goto LAB_1800036ed;
        }
LAB_180003c7c:
        uVar21 = 0xc97;
        *(undefined8 *)(puVar16 + -8) = 0x180003c97;
        DebugTraceError((char)uVar5,"Status",
                        "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",0x97);
        lVar11 = puVar7[1];
        pwVar13 = (wchar_t *)puVar7[3];
        *(uint *)(puVar16 + 0x20) = uVar5;
        pwVar18 = *(wchar_t **)(lVar11 + 0x118);
        *(undefined8 *)(puVar16 + -8) = 0x180003cb4;
        EtwLogNCryptOperationFailed(0xd,pwVar18,pwVar13,uVar21,puVar16[0x20]);
LAB_180003cb4:
        puVar19 = puVar7;
        for (lVar11 = 0x30; lVar11 != 0; lVar11 = lVar11 + -1) {
          *(undefined1 *)puVar19 = 0;
          puVar19 = (undefined8 *)((longlong)puVar19 + 1);
        }
        *(undefined8 *)(puVar16 + -8) = 0x180003cc6;
        SafeAllocaFreeToHeap(puVar7);
      }
    }
  }
  else {
    local_58 = ValidateClientKeyHandle(piVar12);
    puVar15 = auStackY_c8;
    if (local_58 != (int *)0x0) goto LAB_1800035d6;
    uVar5 = 0x80090026;
    uVar20 = 0xae;
    uVar9 = 0x26;
LAB_180003975:
    *(undefined8 *)(puVar15 + -8) = 0x180003988;
    DebugTraceError(uVar9,"Status",
                    "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",uVar20);
    puVar16 = puVar15;
  }
  piVar12 = local_70;
  *(undefined8 *)(puVar16 + -8) = 0x180003799;
  DereferenceProvider((longlong)piVar12);
LAB_1800036ed:
  puVar15 = puVar16;
  if ((pBVar17 != (PBYTE)0x0) && (*(int *)(pBVar17 + -8) == 0x70616548)) {
    *(undefined8 *)(puVar16 + -8) = 0x180003866;
    (*g_pfnFree)();
  }
LAB_1800036f6:
  *(undefined8 *)(puVar15 + -8) = 0x1800036fd;
  uVar5 = NormalizeNteStatus(uVar5);
  *(undefined8 *)(puVar15 + -8) = 0x180003709;
  return uVar5;
}



===== ValidateAndReferenceProvider @ 180003d00 =====

int * ValidateAndReferenceProvider(int *param_1)

{
  if ((param_1 == (int *)0x0) || (*param_1 != 0x44440001)) {
    return (int *)0x0;
  }
  LOCK();
  param_1[1] = param_1[1] + 1;
  UNLOCK();
  return param_1;
}



===== NormalizeNteStatus @ 180003d20 =====

uint NormalizeNteStatus(uint param_1)

{
  if ((((param_1 & 0x1fff0000) != 0x90000) && ((param_1 & 0x1fff0000) != 0x100000)) &&
     (param_1 != 0)) {
    if (param_1 < 0x217) {
      if (param_1 == 0x216) {
        return 0x80070216;
      }
      switch(param_1) {
      case 2:
      case 3:
        return 0x80090011;
      case 5:
        return 0x80090010;
      case 8:
      case 0xe:
        return 0x8009000e;
      case 0x57:
        return 0x80090027;
      case 0x70:
        return 0x80070070;
      case 0x7a:
        return 0x80090028;
      case 0xb7:
        return 0x8009000f;
      }
    }
    else if (param_1 < 0xc000007c) {
      if (param_1 == 0xc000007b) {
        return 0x8009001d;
      }
      if (param_1 == 0xc0000008) {
        return 0x80090026;
      }
      if (param_1 < 0xc0000009) {
        if (param_1 == 0x800704c0) {
          return 0x800704c0;
        }
        if (param_1 == 0x54f) {
          return 0x8009002d;
        }
        if (param_1 == 0x800704c7) {
          return 0x800704c7;
        }
        if (param_1 == 0x80070578) {
          return 0x80070578;
        }
      }
      else {
        if (param_1 == 0xc000000d) {
          return 0x80090027;
        }
        if (param_1 == 0xc0000017) {
          return 0x8009000e;
        }
        if (param_1 == 0xc0000023) {
          return 0x80090028;
        }
      }
    }
    else if (param_1 < 0xc0000136) {
      if (param_1 == 0xc0000135) {
        return 0x8009001e;
      }
      if (param_1 == 0xc00000bb) {
        return 0x80090029;
      }
      if (param_1 == 0xc000009a) {
        return 0x8009000e;
      }
      if (param_1 == 0xc00000e5) {
        return 0x8009002d;
      }
    }
    else {
      if (param_1 == 0xc0000142) {
        return 0x8009001d;
      }
      if (param_1 == 0xc0000139) {
        return 0x8009001d;
      }
      if (param_1 == 0xc000a000) {
        return 0x80090006;
      }
    }
  }
  return param_1;
}



===== I_CreateProtectionDescriptor @ 180003fb0 =====

HRESULT I_CreateProtectionDescriptor
                  (STRSAFE_LPCWSTR param_1,uint *param_2,char *param_3,int param_4,
                  undefined8 *param_5)

{
  uint *puVar1;
  HRESULT HVar2;
  longlong lVar3;
  int *piVar4;
  char *pcVar5;
  uint **ppuVar6;
  char *pcVar7;
  char *_Size;
  char *pcVar8;
  uint *local_res10;
  undefined1 uVar9;
  
  local_res10 = (uint *)0x0;
  pcVar7 = (char *)&local_res10;
  ppuVar6 = (uint **)((ulonglong)param_3 & 0xffffffff);
  piVar4 = (int *)0x0;
  _Size = (char *)0x0;
  if (param_2 == (uint *)0x0) {
    pcVar8 = param_3;
    HVar2 = CNG_DescriptorStringToDescriptor(param_1,(undefined8 *)pcVar7);
    if (HVar2 == 0) {
LAB_180003ffc:
      if (param_1 != (STRSAFE_LPCWSTR)0x0) {
        lVar3 = -1;
        do {
          lVar3 = lVar3 + 1;
        } while (param_1[lVar3] != L'\0');
        _Size = (char *)(lVar3 * 2 + 2);
      }
      piVar4 = (int *)MSCryptAlloc(_Size + 0x28);
      if (piVar4 == (int *)0x0) {
        HVar2 = -0x7ff6fff2;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
          uVar9 = 0xb8;
          HVar2 = -0x7ff6fff2;
          goto LAB_180004063;
        }
      }
      else {
        piVar4[2] = 0;
        piVar4[3] = 0;
        piVar4[4] = 0;
        piVar4[5] = 0;
        piVar4[6] = 0;
        piVar4[7] = 0;
        piVar4[8] = 0;
        piVar4[9] = 0;
        *piVar4 = 0x28;
        piVar4[1] = param_4;
        if (_Size != (char *)0x0) {
          *(int **)(piVar4 + 4) = piVar4 + 10;
          memcpy(piVar4 + 10,param_1,(size_t)_Size);
          pcVar8 = _Size;
        }
        puVar1 = local_res10;
        *(uint **)(piVar4 + 2) = local_res10;
        local_res10 = (uint *)0x0;
        HVar2 = CNG_OpenProtectionDescriptor(puVar1,(uint)param_3);
        if (HVar2 != 0) {
          pcVar8 = 
          "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\ncryptprotect.c";
          pcVar7 = "Status";
          DebugTraceError((char)HVar2,"Status",
                          "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\ncryptprotect.c"
                          ,0xd5);
          goto LAB_1800041a6;
        }
        HVar2 = 0;
        *param_5 = piVar4;
        piVar4 = (int *)0x0;
        pcVar7 = (char *)ppuVar6;
      }
    }
    else {
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_180004073;
      uVar9 = 0x98;
LAB_180004063:
      pcVar8 = "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\ncryptprotect.c";
      WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),pcVar7,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\ncryptprotect.c"
                  ,"Status",(char)HVar2,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\ncryptprotect.c"
                  ,uVar9);
    }
  }
  else {
    pcVar8 = (char *)0x1;
    pcVar5 = CNG_DuplicateDescriptor(param_2,(undefined8 *)pcVar7,1);
    HVar2 = (HRESULT)pcVar5;
    if (HVar2 == 0) goto LAB_180003ffc;
    pcVar8 = "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\ncryptprotect.c";
    pcVar7 = "Status";
    DebugTraceError((char)pcVar5,"Status",
                    "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\ncryptprotect.c"
                    ,0xa5);
  }
LAB_180004073:
  if (local_res10 == (uint *)0x0) {
    return HVar2;
  }
  CNG_FreeProtectionDescriptor(local_res10,pcVar7,pcVar8);
  if (piVar4 == (int *)0x0) {
    return HVar2;
  }
LAB_1800041a6:
  NCryptCloseProtectionDescriptor(piVar4,pcVar7,pcVar8);
  return HVar2;
}



===== SslGenerateMasterKey @ 1800041c0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void SslGenerateMasterKey
               (uint *param_1,uint *param_2,uint *param_3,undefined8 *param_4,undefined4 param_5,
               undefined4 param_6,undefined8 param_7,undefined8 param_8,undefined4 param_9,
               undefined8 param_10,undefined4 param_11)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  undefined1 uVar7;
  undefined8 in_stack_ffffffffffffffb0;
  undefined4 uVar8;
  undefined1 uVar9;
  
                    /* 0x41c0  144  SslGenerateMasterKey */
  uVar8 = (undefined4)((ulonglong)in_stack_ffffffffffffffb0 >> 0x20);
  puVar3 = param_3;
  puVar5 = param_4;
  puVar2 = ValidateSslKeyHandle(param_2);
  puVar3 = ValidateSslKeyHandle(puVar3);
  puVar4 = ValidateSslProvHandle(param_1);
  if (puVar4 == (uint *)0x0) {
    uVar1 = 0x80090026;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_1800042e6;
    uVar9 = 0xf1;
    uVar7 = 0x26;
  }
  else if (puVar5 == (undefined8 *)0x0) {
    uVar1 = 0x80090027;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_1800042e6;
    uVar9 = 0xf8;
    uVar7 = 0x27;
  }
  else {
    puVar5 = (undefined8 *)MSCryptAlloc(0x20);
    if (puVar5 != (undefined8 *)0x0) {
      *puVar5 = 0;
      puVar5[1] = 0;
      puVar5[2] = 0;
      puVar5[3] = 0;
      if (puVar3 != (uint *)0x0) {
        param_3 = *(uint **)(puVar3 + 4);
      }
      if (puVar2 == (uint *)0x0) {
        uVar6 = 0;
      }
      else {
        uVar6 = *(undefined8 *)(puVar2 + 4);
      }
      uVar1 = (**(code **)(puVar4 + 0x20))
                        (*(undefined8 *)(puVar4 + 0x6a),uVar6,param_3,puVar5 + 2,param_5,
                         CONCAT44(uVar8,param_6),param_7,param_8,param_9,param_10,param_11);
      if ((int)uVar1 < 0) {
        DebugTraceError((char)uVar1,"Status",
                        "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",0x20);
        SafeAllocaFreeToHeap(puVar5);
      }
      else {
        *(undefined4 *)(puVar5 + 1) = 0;
        *(undefined4 *)puVar5 = 0x20;
        *(undefined4 *)((longlong)puVar5 + 4) = 0x44444442;
        *(undefined4 *)((longlong)puVar5 + 0xc) = 1;
        puVar5[3] = puVar4;
        LOCK();
        puVar4[4] = puVar4[4] + 1;
        UNLOCK();
        *param_4 = puVar5;
        uVar1 = 0;
      }
      goto LAB_1800042e6;
    }
    uVar1 = 0x8009000e;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_1800042e6;
    uVar9 = 8;
    uVar7 = 0xe;
    uVar1 = 0x8009000e;
  }
  WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),param_2,
              "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c","Status",uVar7,
              "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",uVar9);
LAB_1800042e6:
  NormalizeNteStatus(uVar1);
  return;
}



===== SslGenerateSessionKeys @ 180004420 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void SslGenerateSessionKeys
               (uint *param_1,uint *param_2,undefined8 *param_3,undefined8 *param_4,
               undefined8 param_5,undefined4 param_6)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined1 uVar6;
  undefined8 *puVar7;
  undefined1 uVar8;
  undefined8 *puVar9;
  undefined8 in_stack_ffffffffffffffd0;
  undefined4 uVar10;
  
                    /* 0x4420  146  SslGenerateSessionKeys */
  uVar10 = (undefined4)((ulonglong)in_stack_ffffffffffffffd0 >> 0x20);
  puVar7 = param_3;
  puVar9 = param_4;
  puVar2 = ValidateSslProvHandle(param_1);
  if (puVar2 == (uint *)0x0) {
    uVar1 = 0x80090026;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_18000452a;
    uVar8 = 0x62;
    uVar6 = 0x26;
    uVar1 = 0x80090026;
LAB_180004589:
    WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),
                "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",puVar7,"Status",uVar6,
                "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",uVar8);
  }
  else {
    puVar3 = ValidateSslKeyHandle(param_2);
    if (puVar3 == (uint *)0x0) {
      uVar1 = 0x80090026;
      uVar8 = 0x6a;
      uVar6 = 0x26;
    }
    else {
      if ((puVar7 == (undefined8 *)0x0) || (puVar9 == (undefined8 *)0x0)) {
        uVar1 = 0x80090027;
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_18000452a;
        uVar8 = 0x71;
        uVar6 = 0x27;
        goto LAB_180004589;
      }
      puVar4 = (undefined4 *)MSCryptAlloc(0x20);
      if (puVar4 != (undefined4 *)0x0) {
        puVar5 = (undefined4 *)MSCryptAlloc(0x20);
        if (puVar5 == (undefined4 *)0x0) {
          uVar1 = 0x8009000e;
          uVar6 = 0xe;
          uVar8 = 0x8a;
        }
        else {
          uVar1 = (**(code **)(puVar2 + 0x22))
                            (*(undefined8 *)(puVar2 + 0x6a),*(undefined8 *)(puVar3 + 4),puVar4 + 4,
                             puVar5 + 4,param_5,CONCAT44(uVar10,param_6));
          uVar6 = (undefined1)uVar1;
          if (-1 < (int)uVar1) {
            puVar4[2] = 0;
            puVar4[1] = 0x44444442;
            *puVar4 = 0x20;
            puVar4[3] = 1;
            *(uint **)(puVar4 + 6) = puVar2;
            LOCK();
            puVar2[4] = puVar2[4] + 1;
            UNLOCK();
            *param_3 = puVar4;
            puVar5[2] = 0;
            *puVar5 = 0x20;
            puVar5[1] = 0x44444442;
            puVar5[3] = 1;
            *(uint **)(puVar5 + 6) = puVar2;
            LOCK();
            puVar2[4] = puVar2[4] + 1;
            UNLOCK();
            *param_4 = puVar5;
            uVar1 = 0;
            goto LAB_18000452a;
          }
          uVar8 = 0x9c;
        }
        DebugTraceError(uVar6,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",
                        uVar8);
        SafeAllocaFreeToHeap(puVar4);
        if (puVar5 != (undefined4 *)0x0) {
          SafeAllocaFreeToHeap(puVar5);
        }
        goto LAB_18000452a;
      }
      uVar1 = 0x8009000e;
      uVar8 = 0x81;
      uVar6 = 0xe;
    }
    DebugTraceError(uVar6,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",
                    uVar8);
  }
LAB_18000452a:
  NormalizeNteStatus(uVar1);
  return;
}



===== SslGetCipherSuitePRFHashAlgorithm @ 180004680 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void SslGetCipherSuitePRFHashAlgorithm
               (uint *param_1,ulonglong param_2,undefined8 param_3,undefined8 param_4,
               longlong param_5)

{
  uint uVar1;
  uint *puVar2;
  ulonglong uVar3;
  undefined1 uVar4;
  
                    /* 0x4680  147  SslGetCipherSuitePRFHashAlgorithm */
  uVar3 = param_2 & 0xffffffff;
  puVar2 = ValidateSslProvHandle(param_1);
  if (puVar2 == (uint *)0x0) {
    uVar1 = 0x80090026;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_18000471e;
    uVar4 = 0x5d;
    uVar1 = 0x80090026;
  }
  else if (param_5 == 0) {
    uVar1 = 0x80090027;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_18000471e;
    uVar4 = 100;
    uVar1 = 0x80090027;
    param_2 = 0;
  }
  else {
    if ((ushort)puVar2[8] < 2) {
      uVar1 = 0x80090029;
      DebugTraceError(0x29,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",
                      0x72);
      goto LAB_18000471e;
    }
    param_2 = uVar3 & 0xffffffff;
    uVar1 = (**(code **)(puVar2 + 0x3c))(*(undefined8 *)(puVar2 + 0x6a));
    if (-1 < (int)uVar1) {
      uVar1 = 0;
      goto LAB_18000471e;
    }
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_18000471e;
    uVar4 = 0x84;
  }
  WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),param_2,param_3,"Status",(char)uVar1,
              "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",uVar4);
LAB_18000471e:
  NormalizeNteStatus(uVar1);
  return;
}



===== SslIncrementProviderReferenceCount @ 1800047e0 =====

undefined8 SslIncrementProviderReferenceCount(uint *param_1)

{
  uint *puVar1;
  undefined8 uVar2;
  
                    /* 0x47e0  154  SslIncrementProviderReferenceCount */
  puVar1 = ValidateSslProvHandle(param_1);
  uVar2 = 0;
  if (puVar1 == (uint *)0x0) {
    uVar2 = 0xc0000008;
    DebugTraceError(8,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",0xe1);
  }
  else {
    LOCK();
    puVar1[4] = puVar1[4] + 1;
    UNLOCK();
  }
  return uVar2;
}



===== ValidateSslProvHandle @ 180004830 =====

uint * ValidateSslProvHandle(uint *param_1)

{
  uint *puVar1;
  
  if (((param_1 == (uint *)0x0) || (*param_1 < 0x1b0)) || (param_1[1] != 0x44444441)) {
    return (uint *)0x0;
  }
  puVar1 = (uint *)0x0;
  if (param_1[3] == 0) {
    puVar1 = param_1;
  }
  return puVar1;
}



===== ValidateSslKeyHandle @ 180004860 =====

uint * ValidateSslKeyHandle(uint *param_1)

{
  uint *puVar1;
  
  if ((param_1 == (uint *)0x0) || (*param_1 < 0x20)) {
    return (uint *)0x0;
  }
  puVar1 = (uint *)0x0;
  if (param_1[1] == 0x44444442) {
    puVar1 = param_1;
  }
  return puVar1;
}



===== MSCryptAlloc @ 180004890 =====

void MSCryptAlloc(undefined8 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0001800048a2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,param_1);
  return;
}



===== CNG_DescriptorStringToDescriptor @ 1800048b4 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

HRESULT CNG_DescriptorStringToDescriptor(STRSAFE_LPCWSTR param_1,undefined8 *param_2)

{
  int *piVar1;
  ulonglong uVar2;
  wchar_t *lpString1;
  int iVar3;
  void *_Dst;
  undefined8 uVar4;
  char *pcVar5;
  undefined1 uVar6;
  ulonglong uVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  longlong lVar11;
  longlong lVar10;
  wchar_t **cchDest;
  undefined1 uVar12;
  int iVar13;
  ulonglong uVar14;
  STRSAFE_LPWSTR pszDest;
  undefined8 *puVar15;
  undefined1 auStack_98 [64];
  int local_58;
  undefined1 local_54 [4];
  STRSAFE_LPWSTR local_50;
  uint local_48 [2];
  void *pvStack_40;
  wchar_t *local_38;
  wchar_t *local_30;
  undefined8 *local_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)&local_58;
  local_28 = param_2;
  local_58 = 0;
  *param_2 = 0;
  uVar14 = 0;
  local_48[0] = 0;
  local_48[1] = 0;
  pvStack_40 = (void *)0x0;
  if (param_1 == (STRSAFE_LPCWSTR)0x0) {
    pcVar5 = CNG_DuplicateDescriptor(local_48,param_2,1);
    puVar9 = auStack_98;
    iVar3 = (int)pcVar5;
    if (iVar3 != 0) {
      DebugTraceError((char)pcVar5,"hr",
                      "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\descriptor.c"
                      ,0x29);
      puVar9 = auStack_98;
    }
  }
  else {
    lVar10 = -1;
    do {
      lVar11 = lVar10;
      lVar10 = lVar11 + 1;
    } while (param_1[lVar10] != L'\0');
    cchDest = (wchar_t **)(lVar11 + 2);
    pszDest = (STRSAFE_LPWSTR)0x0;
    uVar2 = (longlong)cchDest * 2;
    puVar8 = auStack_98;
    if (((uVar2 == 0) || (puVar8 = auStack_98, g_ulMaxStackAllocSize < uVar2)) ||
       (uVar7 = g_ulAdditionalProbeSize + 8 + uVar2, puVar8 = auStack_98, uVar7 < uVar2)) {
LAB_180004929:
      puVar9 = puVar8;
      if (uVar2 <= uVar2 + 8) {
        *(undefined8 *)(puVar8 + -8) = 0x18000493e;
        pszDest = (STRSAFE_LPWSTR)(*g_pfnAllocate)();
        if (pszDest != (STRSAFE_LPWSTR)0x0) {
          pszDest[0] = L'效';
          pszDest[1] = L'灡';
          pszDest = pszDest + 4;
        }
      }
    }
    else {
      uVar4 = VerifyStackAvailable(uVar7);
      puVar8 = auStack_98;
      if ((int)uVar4 == 0) goto LAB_180004929;
      uVar7 = uVar2 + 0x17;
      if (uVar7 <= uVar2 + 8) {
        uVar7 = 0xffffffffffffff0;
      }
      lVar10 = -(uVar7 & 0xfffffffffffffff0);
      puVar9 = auStack_98 + lVar10;
      pszDest = (STRSAFE_LPWSTR)0x0;
      puVar8 = auStack_98 + lVar10;
      if ((undefined4 *)(auStack_98 + lVar10 + 0x40) == (undefined4 *)0x0) goto LAB_180004929;
      *(undefined4 *)(auStack_98 + lVar10 + 0x40) = 0x6b637453;
      pszDest = (STRSAFE_LPWSTR)(local_54 + lVar10 + 4);
      puVar8 = auStack_98 + lVar10;
      if (pszDest == (STRSAFE_LPWSTR)0x0) goto LAB_180004929;
    }
    if (pszDest != (STRSAFE_LPWSTR)0x0) {
      *(undefined8 *)(puVar9 + -8) = 0x1800049c6;
      iVar3 = StringCchCopyW(pszDest,(size_t)cchDest,param_1);
      if (iVar3 < 0) {
        *(undefined8 *)(puVar9 + -8) = 0x180004d1f;
        DebugTraceError((char)iVar3,"hr",
                        "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\descriptor.c"
                        ,0x41);
        _Dst = pvStack_40;
      }
      else {
        *(undefined8 *)(puVar9 + -8) = 0x1800049dc;
        _Dst = (void *)MSCryptAlloc(0x900);
        pvStack_40 = _Dst;
        if (_Dst == (void *)0x0) {
          iVar3 = -0x7ff6fff2;
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
            *(undefined4 *)(puVar9 + 0x30) = 0x351;
            *(char **)(puVar9 + 0x28) =
                 "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\descriptor.c";
            *(undefined4 *)(puVar9 + 0x20) = 0x8009000e;
LAB_180004be3:
            uVar4 = *(undefined8 *)(WPP_GLOBAL_Control + 0x10);
            *(undefined8 *)(puVar9 + -8) = 0x180004bf3;
            WPP_SF_sDsd(uVar4,cchDest,
                        "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\descriptor.c"
                        ,"hr",puVar9[0x20],*(char **)(puVar9 + 0x28),puVar9[0x30]);
          }
        }
        else {
          *(undefined8 *)(puVar9 + -8) = 0x1800049f9;
          memset(_Dst,0,0x900);
          puVar15 = (undefined8 *)((longlong)_Dst + 0x100);
          *(undefined8 **)((longlong)_Dst + 8) = puVar15;
          local_50 = pszDest;
LAB_180004a08:
          do {
            iVar13 = (int)uVar14;
            if (*local_50 == L'\0') break;
            local_38 = L"";
            cchDest = &local_38;
            local_30 = L"";
            local_54 = (undefined1  [4])0x0;
            *(undefined8 *)(puVar9 + -8) = 0x180004a36;
            uVar4 = _GetProviderNameAndMoveCursToProviderValue(&local_50,cchDest);
            lpString1 = local_38;
            iVar3 = (int)uVar4;
            if (iVar3 < 0) {
              if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                 ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_180004b0c;
              *(undefined4 *)(puVar9 + 0x30) = 0x379;
LAB_180004bd3:
              *(char **)(puVar9 + 0x28) =
                   "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\descriptor.c";
              *(int *)(puVar9 + 0x20) = iVar3;
              goto LAB_180004be3;
            }
            *(undefined4 *)(puVar9 + 0x28) = 0xffffffff;
            *(wchar_t **)(puVar9 + 0x20) = L"CERTIFICATE";
            *(undefined8 *)(puVar9 + -8) = 0x180004a69;
            iVar3 = CompareStringW(0,1,lpString1,-1,*(PCNZWCH *)(puVar9 + 0x20),
                                   *(int *)(puVar9 + 0x28));
            if (iVar3 == 2) {
              if (local_58 != 0) {
                iVar3 = -0x7ff6ffd7;
                goto LAB_180004b0c;
              }
              local_58 = 1;
            }
            cchDest = &local_30;
            *(undefined8 *)(puVar9 + -8) = 0x180004a84;
            uVar4 = _GetProviderValueAndMoveCursToUnparsed(&local_50,cchDest);
            iVar3 = (int)uVar4;
            if (iVar3 < 0) {
              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
                *(undefined4 *)(puVar9 + 0x30) = 0x38e;
                goto LAB_180004bd3;
              }
              goto LAB_180004b0c;
            }
            piVar1 = (int *)(uVar14 * 0x20 + (longlong)_Dst);
            *piVar1 = *piVar1 + 1;
            if (8 < *(uint *)(uVar14 * 0x20 + (longlong)_Dst)) {
              uVar12 = 0x96;
              goto LAB_180004d5a;
            }
            cchDest = (wchar_t **)local_54;
            puVar15[1] = local_30;
            *puVar15 = lpString1;
            puVar15 = puVar15 + 4;
            *(undefined8 *)(puVar9 + -8) = 0x180004abe;
            uVar4 = _GetTokenAndMoveCursToUnparsed(&local_50,(undefined4 *)cchDest);
            iVar3 = (int)uVar4;
            if (iVar3 < 0) {
              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
                *(undefined4 *)(puVar9 + 0x30) = 0x3a3;
                goto LAB_180004bd3;
              }
              goto LAB_180004b0c;
            }
            if (local_54 == (undefined1  [4])0x2) {
              uVar14 = (ulonglong)(iVar13 + 1);
              if (8 < iVar13 + 2U) {
                uVar12 = 0xac;
LAB_180004d5a:
                iVar3 = -0x7ff6fffb;
                uVar6 = 5;
                goto LAB_180004d6e;
              }
              *(undefined8 **)(uVar14 * 0x20 + 8 + (longlong)_Dst) = puVar15;
              goto LAB_180004a08;
            }
            if (local_54 == (undefined1  [4])0x0) {
              uVar12 = 0xb4;
              goto LAB_180004d5a;
            }
          } while (local_54 != (undefined1  [4])0x3);
          puVar15 = local_28;
          local_48[0] = iVar13 + 1;
          *(undefined8 *)(puVar9 + -8) = 0x180004b02;
          pcVar5 = CNG_DuplicateDescriptor(local_48,puVar15,1);
          iVar3 = (int)pcVar5;
          if (iVar3 != 0) {
            uVar12 = 0xca;
            uVar6 = SUB81(pcVar5,0);
LAB_180004d6e:
            *(undefined8 *)(puVar9 + -8) = 0x180004d81;
            DebugTraceError(uVar6,"hr",
                            "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\descriptor.c"
                            ,uVar12);
          }
        }
      }
LAB_180004b0c:
      if (*(int *)(pszDest + -4) == 0x70616548) {
        *(undefined8 *)(puVar9 + -8) = 0x180004b24;
        (*g_pfnFree)();
      }
      goto LAB_180004b74;
    }
    iVar3 = -0x7ff6fff2;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      uVar4 = *(undefined8 *)(WPP_GLOBAL_Control + 0x10);
      *(undefined4 *)(puVar9 + 0x30) = 0x33a;
      *(char **)(puVar9 + 0x28) =
           "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\descriptor.c";
      *(undefined4 *)(puVar9 + 0x20) = 0x8009000e;
      *(undefined8 *)(puVar9 + -8) = 0x180004b70;
      WPP_SF_sDsd(uVar4,param_2,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\descriptor.c",
                  "hr",puVar9[0x20],*(char **)(puVar9 + 0x28),puVar9[0x30]);
    }
  }
  _Dst = pvStack_40;
LAB_180004b74:
  if (_Dst != (void *)0x0) {
    *(undefined8 *)(puVar9 + -8) = 0x180004b81;
    SafeAllocaFreeToHeap(_Dst);
  }
  *(undefined8 *)(puVar9 + -8) = 0x180004b8f;
  return iVar3;
}



===== LoadProviderEx @ 180004d8c =====

int LoadProviderEx(uint *param_1,undefined8 param_2,undefined8 param_3,undefined8 *param_4,
                  void *param_5)

{
  bool bVar1;
  int iVar2;
  undefined8 *puVar3;
  ulonglong uVar4;
  undefined1 uVar5;
  undefined2 uVar6;
  HMODULE *ppHVar7;
  uint *puVar8;
  uint uVar9;
  undefined8 **ppuVar10;
  undefined1 uVar11;
  HMODULE pHVar12;
  HMODULE local_48;
  undefined8 *local_40;
  void *local_38 [2];
  
  uVar9 = (uint)param_3;
  local_38[0] = (void *)0x0;
  bVar1 = false;
  local_48 = (HMODULE)0x0;
  if (g_fLoaderInitialized == 0) {
    iVar2 = -0x3fffff1b;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),param_2,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\loader\\loader.c","sResult",0xe5,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\loader\\loader.c",0x8f);
    }
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)&g_csLoaderLock);
    bVar1 = true;
    puVar3 = _FindInLoadedProviderList((longlong)param_1);
    local_40 = puVar3;
    if (puVar3 == (undefined8 *)0x0) {
      ppHVar7 = &local_48;
      iVar2 = _LoadImage((longlong)param_1,(longlong *)ppHVar7);
      if (iVar2 == 0) {
        pHVar12 = local_48;
        goto LAB_180004eb2;
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
        WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),ppHVar7,
                    "onecore\\ds\\security\\cryptoapi\\ncrypt\\loader\\loader.c","sResult",
                    (char)iVar2,"onecore\\ds\\security\\cryptoapi\\ncrypt\\loader\\loader.c",0xa9);
      }
      pHVar12 = local_48;
    }
    else {
      pHVar12 = (HMODULE)puVar3[1];
LAB_180004eb2:
      puVar8 = param_1;
      uVar4 = _LoadInterface(pHVar12,param_1,param_3,local_38);
      iVar2 = (int)uVar4;
      if (iVar2 == 0) {
        if (uVar9 != 0) {
LAB_180004fb9:
          memcpy(param_5,local_38[0],(ulonglong)uVar9);
          if (puVar3 == (undefined8 *)0x0) {
            ppuVar10 = &local_40;
            iVar2 = _NewLoadedProviderHandle((longlong)param_1,pHVar12,ppuVar10);
            puVar3 = g_pLoadedProviderList;
            if (iVar2 != 0) {
              DebugTraceError((char)iVar2,"sResult",
                              "onecore\\ds\\security\\cryptoapi\\ncrypt\\loader\\loader.c",0xeb);
              puVar3 = local_40;
              goto LAB_180005054;
            }
            g_pLoadedProviderList = local_40;
            local_40[3] = puVar3;
            puVar3 = local_40;
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((WPP_GLOBAL_Control[0x1c] & 0x20) != 0)) {
              uVar9 = *(uint *)(local_40 + 2);
              uVar6 = 0x1c;
              goto LAB_1800050ad;
            }
          }
          else {
            uVar9 = *(uint *)(puVar3 + 2) + 1;
            ppuVar10 = (undefined8 **)(ulonglong)uVar9;
            if (uVar9 < *(uint *)(puVar3 + 2)) {
              iVar2 = -0x3fffff66;
              uVar11 = 0xd5;
              uVar5 = 0x9a;
              goto LAB_180004f87;
            }
            *(uint *)(puVar3 + 2) = uVar9;
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((WPP_GLOBAL_Control[0x1c] & 0x20) != 0)) {
              uVar6 = 0x1b;
LAB_1800050ad:
              WPP_SF_qqSD(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),uVar6,ppuVar10,param_1,
                          (char)puVar3,(wchar_t *)*puVar3,(char)uVar9);
            }
          }
          *param_4 = puVar3;
          goto LAB_1800050ca;
        }
        uVar9 = *param_1;
        if (6 < uVar9) {
          if (uVar9 == 7) {
            uVar9 = 0x58;
          }
          else {
            if (uVar9 == 8) goto LAB_180004f40;
            if (uVar9 == 0x10001) {
              uVar9 = 0x100;
            }
            else if (uVar9 == 0x10002) {
              uVar9 = 0x188;
            }
            else {
              if (uVar9 != 0x10004) goto LAB_180004f77;
              uVar9 = 0x28;
            }
          }
          goto LAB_180004fb9;
        }
        if (uVar9 == 6) {
          uVar9 = 0x30;
          goto LAB_180004fb9;
        }
        if ((uVar9 == 1) || (uVar9 == 2)) {
LAB_180004f40:
          uVar9 = 0x60;
          goto LAB_180004fb9;
        }
        if (uVar9 == 3) {
          uVar9 = 0x70;
          goto LAB_180004fb9;
        }
        if (uVar9 == 4) {
          uVar9 = 0x68;
          goto LAB_180004fb9;
        }
        if (uVar9 == 5) goto LAB_180004f40;
LAB_180004f77:
        iVar2 = -0x3ffffff3;
        uVar11 = 0xc4;
        uVar5 = 0xd;
LAB_180004f87:
        DebugTraceError(uVar5,"sResult","onecore\\ds\\security\\cryptoapi\\ncrypt\\loader\\loader.c"
                        ,uVar11);
      }
      else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
        WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),puVar8,
                    "onecore\\ds\\security\\cryptoapi\\ncrypt\\loader\\loader.c","sResult",
                    (char)uVar4,"onecore\\ds\\security\\cryptoapi\\ncrypt\\loader\\loader.c",0xba);
      }
    }
LAB_180005054:
    if ((puVar3 == (undefined8 *)0x0) && (pHVar12 != (HMODULE)0x0)) {
      _FreeImage(pHVar12);
    }
  }
  *param_4 = 0;
  if (!bVar1) {
    return iVar2;
  }
LAB_1800050ca:
  LeaveCriticalSection((LPCRITICAL_SECTION)&g_csLoaderLock);
  return iVar2;
}



===== McGenEventWrite_EventWriteTransfer @ 180005104 =====

void McGenEventWrite_EventWriteTransfer
               (undefined8 param_1,PCEVENT_DESCRIPTOR param_2,undefined8 param_3,ULONG param_4,
               PEVENT_DATA_DESCRIPTOR param_5)

{
  ushort *puVar1;
  ULONG UVar2;
  uint uVar3;
  
  puVar1 = DAT_180027018;
  UVar2 = 0;
  if (DAT_180027018 == (ushort *)0x0) {
    param_5->Ptr = 0;
    uVar3 = 0;
  }
  else {
    param_5->Ptr = (ULONGLONG)DAT_180027018;
    UVar2 = 2;
    uVar3 = (uint)*puVar1;
  }
  param_5->Size = uVar3;
  param_5->Reserved = UVar2;
  EventWriteTransfer(ETW_LOG_NCRYPT_PROVIDER_Context,param_2,(LPCGUID)0x0,(LPCGUID)0x0,param_4,
                     param_5);
  return;
}



===== KeyProtRouter_CleanupSettings @ 180005168 =====

void KeyProtRouter_CleanupSettings(undefined8 param_1,undefined8 param_2,undefined *param_3)

{
  RtlEnterCriticalSection(&g_csKeyProtectorLock);
  if (DAT_180027ce8 != 0) {
    if (*(int **)(DAT_180027ce8 + 0x18) != (int *)0x0) {
      NCryptCloseProtectionDescriptor(*(int **)(DAT_180027ce8 + 0x18),param_2,param_3);
    }
    SafeAllocaFreeToHeap(DAT_180027ce8);
    DAT_180027ce8 = 0;
    DAT_180027cf0 = 0;
  }
                    /* WARNING: Could not recover jumptable at 0x0001800051b6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RtlLeaveCriticalSection(&g_csKeyProtectorLock);
  return;
}



===== WPP_SF_PPD @ 1800051dc =====

void WPP_SF_PPD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  TraceMessage(param_1,0x2b,&WPP_7a4fecd660bc33d31f6cd64b40025006_Traceguids,0x1f,&local_res20,8,
               &param_5,8,&param_6,4,0);
  return;
}



===== DereferenceSslProvHandle @ 180005250 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

int DereferenceSslProvHandle(uint *param_1,int param_2)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  
  if (param_2 != 0) {
    param_1[3] = 1;
  }
  LOCK();
  puVar1 = param_1 + 4;
  uVar2 = *puVar1;
  *puVar1 = *puVar1 - 1;
  UNLOCK();
  iVar3 = uVar2 - 1;
  if ((iVar3 == 0 || (int)uVar2 < 1) && (param_1[3] != 0)) {
    (**(code **)(param_1 + 0x1e))(*(undefined8 *)(param_1 + 0x6a));
    UnloadProvider(*(undefined8 **)(param_1 + 6));
    memset(param_1,0,(ulonglong)*param_1);
    SafeAllocaFreeToHeap(param_1);
  }
  return iVar3;
}



===== SslCreateClientAuthHash @ 1800052d0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void SslCreateClientAuthHash
               (uint *param_1,undefined8 *param_2,ulonglong param_3,undefined4 param_4,
               undefined8 param_5,undefined4 param_6)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined1 uVar5;
  undefined8 in_stack_ffffffffffffffe0;
  undefined4 uVar6;
  undefined1 uVar7;
  
                    /* 0x52d0  117  SslCreateClientAuthHash */
  uVar6 = (undefined4)((ulonglong)in_stack_ffffffffffffffe0 >> 0x20);
  uVar4 = param_3 & 0xffffffff;
  if ((((param_1 == (uint *)0x0) || (*param_1 < 0x1b0)) || (param_1[1] != 0x44444441)) ||
     (param_1[3] != 0)) {
    uVar3 = 0x80090026;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_1800053df;
    uVar7 = 0xed;
    uVar5 = 0x26;
  }
  else if (param_2 == (undefined8 *)0x0) {
    uVar3 = 0x80090027;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_1800053df;
    uVar7 = 0xf4;
    uVar5 = 0x27;
  }
  else if ((ushort)param_1[8] < 2) {
    uVar3 = 0x80090029;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_1800053df;
    uVar7 = 2;
    uVar5 = 0x29;
  }
  else {
    param_3 = 0x20;
    puVar2 = (undefined8 *)0x0;
    puVar1 = (undefined8 *)
             RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30));
    if (puVar1 != (undefined8 *)0x0) {
      puVar2 = puVar1 + 2;
      *puVar1 = 0;
      puVar1[1] = 0;
      puVar1[2] = 0;
      puVar1[3] = 0;
      uVar3 = (**(code **)(param_1 + 0x3a))
                        (*(undefined8 *)(param_1 + 0x6a),puVar2,uVar4,param_4,param_5,
                         CONCAT44(uVar6,param_6));
      if ((int)uVar3 < 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
          WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),puVar2,uVar4,"Status",(char)uVar3,
                      "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",0x25);
        }
        SafeAllocaFreeToHeap(puVar1);
      }
      else {
        *(undefined4 *)puVar1 = 0x20;
        uVar3 = 0;
        *(undefined8 *)((longlong)puVar1 + 4) = 0x44444443;
        *(undefined4 *)((longlong)puVar1 + 0xc) = 1;
        puVar1[3] = param_1;
        LOCK();
        param_1[4] = param_1[4] + 1;
        UNLOCK();
        *param_2 = puVar1;
      }
      goto LAB_1800053df;
    }
    uVar3 = 0x8009000e;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_1800053df;
    uVar7 = 0x12;
    uVar5 = 0xe;
    param_2 = puVar2;
  }
  WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),param_2,param_3,"Status",uVar5,
              "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",uVar7);
LAB_1800053df:
  NormalizeNteStatus(uVar3);
  return;
}



===== NCryptSecretAgreement @ 180005550 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

SECURITY_STATUS __stdcall
NCryptSecretAgreement
          (NCRYPT_KEY_HANDLE hPrivKey,NCRYPT_KEY_HANDLE hPubKey,NCRYPT_SECRET_HANDLE *phAgreedSecret
          ,DWORD dwFlags)

{
  int *piVar1;
  wchar_t *pwVar2;
  uint uVar3;
  undefined8 *puVar4;
  wchar_t *pwVar5;
  undefined *puVar6;
  longlong lVar7;
  NCRYPT_KEY_HANDLE NVar8;
  int *piVar9;
  undefined8 *puVar10;
  NCRYPT_SECRET_HANDLE *pNVar11;
  wchar_t *pwVar12;
  int *local_res8;
  undefined1 uVar13;
  char *in_stack_ffffffffffffffb0;
  undefined1 uVar14;
  undefined4 in_stack_ffffffffffffffb8;
  undefined4 in_stack_ffffffffffffffbc;
  
                    /* 0x5550  97  NCryptSecretAgreement */
  NVar8 = hPubKey;
  pNVar11 = phAgreedSecret;
  local_res8 = (int *)hPrivKey;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    in_stack_ffffffffffffffb0 =
         (char *)CONCAT44((int)((ulonglong)in_stack_ffffffffffffffb0 >> 0x20),dwFlags);
    WPP_SF_PPD(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),hPubKey,phAgreedSecret,hPrivKey,
               (char)hPubKey,(char)dwFlags);
  }
  piVar1 = local_res8;
  if ((local_res8 == (int *)0x0) || (*local_res8 != 0x44440002)) {
    uVar3 = 0x80090026;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_180005665;
    uVar14 = 0x14;
LAB_1800057ae:
    uVar3 = 0x80090026;
    uVar13 = 0x26;
  }
  else {
    if ((hPubKey == 0) || (*(int *)hPubKey != 0x44440002)) {
      uVar3 = 0x80090026;
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_180005665;
      uVar14 = 0x1d;
      goto LAB_1800057ae;
    }
    NVar8 = 0;
    pNVar11 = (NCRYPT_SECRET_HANDLE *)0x18;
    puVar4 = (undefined8 *)
             RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30));
    if (puVar4 != (undefined8 *)0x0) {
      *puVar4 = 0;
      puVar4[1] = 0;
      puVar4[2] = 0;
      while( true ) {
        pwVar12 = *(wchar_t **)(hPubKey + 0x10);
        piVar9 = *(int **)(piVar1 + 4);
        uVar3 = (**(code **)(*(longlong *)(piVar1 + 2) + 0xd0))
                          (*(undefined8 *)(*(longlong *)(piVar1 + 2) + 0x110),piVar9,pwVar12,
                           puVar4 + 2,dwFlags);
        if (uVar3 != 0x8009002e) break;
        if ((dwFlags & 0x40) != 0) {
          uVar3 = 0x80090022;
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
            WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),piVar9,pwVar12,"Status",0x22,
                        "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",0x42);
          }
          goto LAB_180005709;
        }
        pwVar12 = L"NCryptSecretAgreement";
        piVar9 = local_res8;
        uVar3 = (**(code **)(*(longlong *)(piVar1 + 2) + 0xc0))
                          (*(undefined8 *)(*(longlong *)(piVar1 + 2) + 0x110),local_res8,
                           L"NCryptSecretAgreement",0);
        if (uVar3 != 0) goto LAB_180005696;
      }
      if (uVar3 == 0) {
        if (piVar1[8] == 0) {
          CertInUseLog(2,(undefined8 *)(piVar1 + 10),&local_res8);
        }
        *(undefined4 *)puVar4 = 0x44440003;
        puVar4[1] = *(undefined8 *)(piVar1 + 2);
        piVar1 = *(int **)(piVar1 + 2);
        if ((piVar1 != (int *)0x0) && (*piVar1 == 0x44440001)) {
          LOCK();
          piVar1[1] = piVar1[1] + 1;
          UNLOCK();
        }
        *phAgreedSecret = (NCRYPT_SECRET_HANDLE)puVar4;
      }
      else {
LAB_180005696:
        puVar6 = WPP_GLOBAL_Control;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
          puVar6 = *(undefined **)(WPP_GLOBAL_Control + 0x10);
          in_stack_ffffffffffffffb8 = 0xe54;
          in_stack_ffffffffffffffb0 =
               "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c";
          WPP_SF_sDsd(puVar6,piVar9,pwVar12,"Status",(char)uVar3,
                      "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",0x54);
        }
        pwVar12 = *(wchar_t **)(piVar1 + 6);
        pwVar2 = *(wchar_t **)(*(longlong *)(piVar1 + 2) + 0x118);
        if ((Microsoft_Windows_Crypto_NCryptEnableBits & 1) != 0) {
          pwVar5 = I_GetProcessName();
          McTemplateU0qzzzzdz_EventWriteTransfer
                    (puVar6,piVar9,8,pwVar2,pwVar12,in_stack_ffffffffffffffb0,
                     CONCAT44(in_stack_ffffffffffffffbc,in_stack_ffffffffffffffb8),(char)uVar3,
                     pwVar5);
        }
LAB_180005709:
        puVar10 = puVar4;
        for (lVar7 = 0x18; lVar7 != 0; lVar7 = lVar7 + -1) {
          *(undefined1 *)puVar10 = 0;
          puVar10 = (undefined8 *)((longlong)puVar10 + 1);
        }
        SafeAllocaFreeToHeap(puVar4);
      }
      goto LAB_180005665;
    }
    uVar3 = 0x8009000e;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_180005665;
    uVar14 = 0x2a;
    uVar13 = 0xe;
  }
  WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),NVar8,pNVar11,"Status",uVar13,
              "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",uVar14);
LAB_180005665:
  uVar3 = NormalizeNteStatus(uVar3);
  return uVar3;
}



===== SafeAllocaFreeToHeap @ 1800058b0 =====

void SafeAllocaFreeToHeap(undefined8 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0001800058c2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,param_1);
  return;
}



===== I_GetProcessName @ 1800058d4 =====

short * I_GetProcessName(void)

{
  longlong lVar1;
  
  if (DAT_180027898 == 0) {
    GetModuleFileNameW((HMODULE)0x0,(LPWSTR)&g_wsProcessFileName,0x100);
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (*(short *)(&g_wsProcessFileName + lVar1 * 2) != 0);
    DAT_180027890 = (short *)(&g_wsProcessFileName + lVar1 * 2);
    if (DAT_180027890 != (short *)&g_wsProcessFileName) {
      do {
        if (*DAT_180027890 == 0x5c) goto LAB_18000596d;
        DAT_180027890 = DAT_180027890 + -1;
      } while (DAT_180027890 != (short *)&g_wsProcessFileName);
    }
    if (*DAT_180027890 == 0x5c) {
LAB_18000596d:
      DAT_180027890 = DAT_180027890 + 1;
    }
    DAT_180027898 = 1;
  }
  return DAT_180027890;
}



===== McTemplateU0qzzzzdz_EventWriteTransfer @ 18000598c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateU0qzzzzdz_EventWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,wchar_t *param_4,
               wchar_t *param_5,undefined8 param_6,undefined8 param_7,undefined1 param_8,
               wchar_t *param_9)

{
  longlong lVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined4 local_res18 [4];
  undefined1 auStackY_c8 [32];
  _EVENT_DATA_DESCRIPTOR local_98;
  undefined4 *local_88;
  undefined8 local_80;
  wchar_t *local_78;
  int local_70;
  undefined4 local_6c;
  wchar_t *local_68;
  int local_60;
  undefined4 local_5c;
  wchar_t *local_58;
  undefined8 local_50;
  wchar_t *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  wchar_t *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_c8;
  local_88 = local_res18;
  lVar1 = -1;
  local_80 = 4;
  uVar3 = 10;
  if (param_4 == (wchar_t *)0x0) {
    local_70 = 10;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (param_4[lVar2] != L'\0');
    local_70 = (int)lVar2 * 2 + 2;
  }
  local_6c = 0;
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"NULL";
  }
  if (param_5 == (wchar_t *)0x0) {
    local_60 = 10;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (param_5[lVar2] != L'\0');
    local_60 = (int)lVar2 * 2 + 2;
  }
  local_5c = 0;
  if (param_5 == (wchar_t *)0x0) {
    param_5 = L"NULL";
  }
  local_58 = L"";
  local_38 = &param_8;
  local_50 = 2;
  local_48 = L"";
  local_40 = 2;
  local_30 = 4;
  if (param_9 != (wchar_t *)0x0) {
    do {
      lVar1 = lVar1 + 1;
    } while (param_9[lVar1] != L'\0');
    uVar3 = (ulonglong)((int)lVar1 * 2 + 2);
  }
  local_28 = param_9;
  if (param_9 == (wchar_t *)0x0) {
    local_28 = L"NULL";
  }
  local_20 = (undefined4)uVar3;
  local_1c = 0;
  local_res18[0] = param_3;
  local_78 = param_4;
  local_68 = param_5;
  McGenEventWrite_EventWriteTransfer
            (local_38,(PCEVENT_DESCRIPTOR)&ETW_LOG_NCRYPT_OPERATION_FAILED,uVar3,8,&local_98);
  return;
}



===== McTemplateU0zdz_EventWriteTransfer @ 180005ae4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateU0zdz_EventWriteTransfer
               (undefined8 param_1,undefined8 param_2,wchar_t *param_3,undefined4 param_4,
               wchar_t *param_5)

{
  longlong lVar1;
  longlong lVar2;
  undefined4 local_res20 [2];
  undefined1 auStackY_88 [32];
  _EVENT_DATA_DESCRIPTOR local_58;
  wchar_t *local_48;
  int local_40;
  undefined4 local_3c;
  undefined4 *local_38;
  undefined8 local_30;
  wchar_t *local_28;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  lVar1 = -1;
  local_20 = 10;
  if (param_3 == (wchar_t *)0x0) {
    local_40 = 10;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (param_3[lVar2] != L'\0');
    local_40 = (int)lVar2 * 2 + 2;
  }
  local_38 = local_res20;
  local_3c = 0;
  if (param_3 == (wchar_t *)0x0) {
    param_3 = L"NULL";
  }
  local_30 = 4;
  if (param_5 != (wchar_t *)0x0) {
    do {
      lVar1 = lVar1 + 1;
    } while (param_5[lVar1] != L'\0');
    local_20 = (int)lVar1 * 2 + 2;
  }
  if (param_5 == (wchar_t *)0x0) {
    param_5 = L"NULL";
  }
  local_1c = 0;
  local_res20[0] = param_4;
  local_48 = param_3;
  local_28 = param_5;
  McGenEventWrite_EventWriteTransfer
            (4,(PCEVENT_DESCRIPTOR)&ETW_LOG_NCRYPT_OPEN_PROVIDER_FAILED,param_3,4,&local_58);
  return;
}



===== CertInUseMetadataCleanup @ 180005bbc =====

void CertInUseMetadataCleanup(undefined8 *param_1)

{
  LPVOID lpMem;
  HANDLE hHeap;
  
  LOCK();
  lpMem = (LPVOID)*param_1;
  *param_1 = 0;
  UNLOCK();
  EtwLogNCryptCertInUse((longlong)lpMem);
  if (lpMem == (LPVOID)0x0) {
    return;
  }
  hHeap = GetProcessHeap();
                    /* WARNING: Could not recover jumptable at 0x000180005bf4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  HeapFree(hHeap,0,lpMem);
  return;
}



===== NCryptOpenStorageProvider @ 180005c10 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

SECURITY_STATUS __stdcall
NCryptOpenStorageProvider(NCRYPT_PROV_HANDLE *phProvider,LPCWSTR pszProviderName,DWORD dwFlags)

{
  longlong lVar1;
  uint uVar2;
  longlong lVar3;
  undefined4 *_Dst;
  wchar_t *pwVar4;
  undefined8 *puVar5;
  char *pcVar6;
  LPCWSTR pWVar7;
  uint uVar8;
  undefined4 in_register_00000084;
  wchar_t *pwVar9;
  undefined1 uVar10;
  ULONG local_res8 [4];
  PCRYPT_PROVIDER_REFS local_res20;
  undefined1 uVar11;
  
                    /* 0x5c10  92  NCryptOpenStorageProvider */
  pwVar9 = (wchar_t *)CONCAT44(in_register_00000084,dwFlags);
  _Dst = (undefined4 *)0x0;
  local_res20 = (PCRYPT_PROVIDER_REFS)0x0;
  local_res8[0] = 0;
  uVar8 = 0;
  pcVar6 = (char *)pszProviderName;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    pwVar9 = L"\xecd6穏悼㏓氟䯖ɀِNULL";
    pcVar6 = (char *)0xd;
    WPP_SF_qSD(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0xd,
               &WPP_7a4fecd660bc33d31f6cd64b40025006_Traceguids,phProvider,pszProviderName,
               (char)dwFlags);
  }
  if (phProvider == (NCRYPT_PROV_HANDLE *)0x0) {
    uVar2 = 0x80090027;
    puVar5 = (undefined8 *)WPP_GLOBAL_Control;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      uVar11 = 0x57;
      uVar10 = 0x27;
      uVar2 = 0x80090027;
LAB_180005d30:
      pcVar6 = "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c";
      puVar5 = *(undefined8 **)(WPP_GLOBAL_Control + 0x10);
      WPP_SF_sDsd(puVar5,"onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",pwVar9
                  ,"Status",uVar10,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",uVar11);
    }
LAB_180005d40:
    pwVar9 = L"";
    if (pszProviderName != (LPCWSTR)0x0) {
      pwVar9 = pszProviderName;
    }
  }
  else {
    *phProvider = 0;
    pwVar9 = L"KEY_STORAGE";
    pcVar6 = (char *)0x10001;
    uVar2 = BCryptResolveProviders
                      ((LPCWSTR)0x0,0x10001,L"KEY_STORAGE",pszProviderName,1,0,local_res8,
                       &local_res20);
    if ((int)uVar2 < 0) {
      pcVar6 = "Status";
      puVar5 = (undefined8 *)(ulonglong)uVar2;
      DebugTraceError((char)uVar2,"Status",
                      "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",0x6d);
      goto LAB_180005d40;
    }
    if (((pszProviderName != (LPCWSTR)0x0) && (*pszProviderName != L'\0')) ||
       (pszProviderName = (*local_res20->rgpProviders)->pszProvider, pszProviderName != (LPCWSTR)0x0
       )) {
      lVar3 = -1;
      do {
        lVar1 = lVar3 + 1;
        lVar3 = lVar3 + 1;
      } while (pszProviderName[lVar1] != L'\0');
      uVar8 = (int)lVar3 * 2 + 2;
    }
    uVar2 = uVar8 + 0x120;
    if (uVar2 < 0x120) {
      uVar2 = 0xc0000095;
      puVar5 = (undefined8 *)WPP_GLOBAL_Control;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
        uVar11 = 0x84;
        uVar10 = 0x95;
        uVar2 = 0xc0000095;
        goto LAB_180005d30;
      }
      goto LAB_180005d40;
    }
    _Dst = (undefined4 *)MSCryptAlloc((ulonglong)uVar2);
    if (_Dst == (undefined4 *)0x0) {
      pcVar6 = "Status";
      puVar5 = (undefined8 *)0x8009000e;
      uVar2 = 0x8009000e;
      DebugTraceError(0xe,"Status",
                      "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",0x8d);
      goto LAB_180005d40;
    }
    memset(_Dst,0,(ulonglong)uVar2);
    if (uVar8 == 0) {
      *(undefined8 *)(_Dst + 0x46) = 0;
    }
    else {
      *(undefined4 **)(_Dst + 0x46) = _Dst + 0x48;
      memcpy(_Dst + 0x48,pszProviderName,(ulonglong)uVar8);
    }
    uVar2 = LoadProviderEx(&(*local_res20->rgpProviders)->dwInterface,_Dst + 4,0x100,
                           (undefined8 *)(_Dst + 2),_Dst + 4);
    if ((int)uVar2 < 0) {
      uVar10 = 0xab;
    }
    else {
      if (pszProviderName == (LPCWSTR)0x0) {
        pWVar7 = (*local_res20->rgpProviders)->pszProvider;
      }
      else {
        pWVar7 = pszProviderName;
      }
      uVar2 = (**(code **)(_Dst + 6))(_Dst + 0x44,pWVar7,dwFlags);
      if (-1 < (int)uVar2) {
        *_Dst = 0x44440001;
        uVar2 = 0;
        _Dst[1] = 1;
        *phProvider = (NCRYPT_PROV_HANDLE)_Dst;
        goto LAB_180005d5d;
      }
      uVar10 = 0xbb;
    }
    puVar5 = (undefined8 *)(ulonglong)uVar2;
    pcVar6 = "Status";
    DebugTraceError((char)uVar2,"Status",
                    "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",uVar10);
    if (*(longlong *)(_Dst + 2) != 0) {
      if (*(longlong *)(_Dst + 0x44) != 0) {
        (**(code **)(_Dst + 0x18))();
      }
      puVar5 = *(undefined8 **)(_Dst + 2);
      UnloadProvider(puVar5);
    }
    pwVar9 = *(wchar_t **)(_Dst + 0x46);
    if ((pwVar9 == (wchar_t *)0x0) && (pwVar9 = L"", pszProviderName != (LPCWSTR)0x0)) {
      pwVar9 = pszProviderName;
    }
  }
  if ((Microsoft_Windows_Crypto_NCryptEnableBits & 1) != 0) {
    pwVar4 = I_GetProcessName();
    McTemplateU0zdz_EventWriteTransfer(puVar5,pcVar6,pwVar9,uVar2,pwVar4);
  }
  if (_Dst != (undefined4 *)0x0) {
    SafeAllocaFreeToHeap(_Dst);
  }
LAB_180005d5d:
  if (local_res20 != (PCRYPT_PROVIDER_REFS)0x0) {
    BCryptFreeBuffer(local_res20);
  }
  uVar8 = NormalizeNteStatus(uVar2);
  return uVar8;
}



===== SslLookupCipherLengths @ 180006000 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void SslLookupCipherLengths
               (uint *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               longlong param_5,uint param_6)

{
  uint uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  
                    /* 0x6000  155  SslLookupCipherLengths */
  if ((((param_1 == (uint *)0x0) || (*param_1 < 0x1b0)) || (param_1[1] != 0x44444441)) ||
     (param_1[3] != 0)) {
    uVar1 = 0x80090026;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_1800060c2;
    uVar3 = 0xa8;
    uVar2 = 0x26;
    uVar1 = 0x80090026;
  }
  else {
    if ((param_5 != 0) && (0x13 < param_6)) {
      if ((ushort)param_1[8] < 2) {
        uVar1 = 0x80090029;
        DebugTraceError(0x29,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",
                        0xbe);
      }
      else {
        uVar1 = (**(code **)(param_1 + 0x38))(*(undefined8 *)(param_1 + 0x6a));
        if ((int)uVar1 < 0) {
          DebugTraceError((char)uVar1,"Status",
                          "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",0xd0);
        }
        else {
          uVar1 = 0;
        }
      }
      goto LAB_1800060c2;
    }
    uVar1 = 0x80090027;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_1800060c2;
    uVar3 = 0xb0;
    uVar2 = 0x27;
    uVar1 = 0x80090027;
  }
  WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),param_2,param_3,"Status",uVar2,
              "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",uVar3);
LAB_1800060c2:
  NormalizeNteStatus(uVar1);
  return;
}



===== SslFreeObject @ 180006160 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

uint SslFreeObject(uint *param_1,undefined8 param_2)

{
  uint uVar1;
  uint *_Dst;
  uint uVar2;
  ulonglong uVar3;
  uint *puVar4;
  undefined1 uVar5;
  
                    /* 0x6160  143  SslFreeObject */
  if (param_1 == (uint *)0x0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),param_2,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c","Status",8,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",100);
    }
    return 0x80090026;
  }
  uVar2 = param_1[1];
  if (uVar2 == 0x44444442) {
    if (0x1f < *param_1) {
      _Dst = *(uint **)(param_1 + 6);
      uVar2 = (**(code **)(_Dst + 0x1e))(*(undefined8 *)(param_1 + 4));
      if ((int)uVar2 < 0) {
        DebugTraceError((char)uVar2,"Status",
                        "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",0x9f);
      }
      puVar4 = param_1;
      for (uVar3 = (ulonglong)*param_1; uVar3 != 0; uVar3 = uVar3 - 1) {
        *(undefined1 *)puVar4 = 0;
        puVar4 = (uint *)((longlong)puVar4 + 1);
      }
      RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,param_1);
      LOCK();
      puVar4 = _Dst + 4;
      uVar1 = *puVar4;
      *puVar4 = *puVar4 - 1;
      UNLOCK();
joined_r0x000180006364:
      if (((int)uVar1 < 2) && (_Dst[3] != 0)) {
        (**(code **)(_Dst + 0x1e))(*(undefined8 *)(_Dst + 0x6a));
        UnloadProvider(*(undefined8 **)(_Dst + 6));
        memset(_Dst,0,(ulonglong)*_Dst);
        SafeAllocaFreeToHeap(_Dst);
      }
      if ((uVar2 & 0x1fff0000) == 0x90000) {
        return uVar2;
      }
      if ((uVar2 & 0x1fff0000) == 0x100000) {
        return uVar2;
      }
      if (uVar2 == 0) {
        return 0;
      }
      if (uVar2 < 0x217) {
        if (uVar2 == 0x216) {
          return 0x80070216;
        }
        switch(uVar2) {
        case 2:
        case 3:
          return 0x80090011;
        default:
          return uVar2;
        case 5:
          return 0x80090010;
        case 8:
        case 0xe:
          goto switchD_180006250_caseD_4;
        case 0x57:
          return 0x80090027;
        case 0x70:
          return 0x80070070;
        case 0x7a:
          return 0x80090028;
        case 0xb7:
          return 0x8009000f;
        }
      }
      if (uVar2 < 0xc000007c) {
        if (uVar2 == 0xc000007b) {
          return 0x8009001d;
        }
        if (uVar2 == 0xc0000008) {
          return 0x80090026;
        }
        if (uVar2 < 0xc0000009) {
          if (uVar2 == 0x800704c0) {
            return 0x800704c0;
          }
          if (uVar2 == 0x54f) {
            return 0x8009002d;
          }
          if (uVar2 == 0x800704c7) {
            return 0x800704c7;
          }
          if (uVar2 == 0x80070578) {
            return 0x80070578;
          }
          return uVar2;
        }
        if (uVar2 == 0xc000000d) {
          return 0x80090027;
        }
        if (uVar2 != 0xc0000017) {
          if (uVar2 == 0xc0000023) {
            return 0x80090028;
          }
          return uVar2;
        }
      }
      else {
        if (0xc0000135 < uVar2) {
          if (uVar2 == 0xc0000142) {
            return 0x8009001d;
          }
          if (uVar2 == 0xc0000139) {
            return 0x8009001d;
          }
          if (uVar2 == 0xc000a000) {
            return 0x80090006;
          }
          return uVar2;
        }
        if (uVar2 == 0xc0000135) {
          return 0x8009001e;
        }
        if (uVar2 == 0xc00000bb) {
          return 0x80090029;
        }
        if (uVar2 != 0xc000009a) {
          if (uVar2 == 0xc00000e5) {
            return 0x8009002d;
          }
          return uVar2;
        }
      }
switchD_180006250_caseD_4:
      return 0x8009000e;
    }
    uVar5 = 0x7d;
  }
  else if (uVar2 == 0x44444441) {
    if ((0x1af < *param_1) && (param_1[3] == 0)) {
      DereferenceSslProvHandle(param_1,1);
      return 0;
    }
    uVar5 = 0x71;
  }
  else {
    if (uVar2 != 0x44444443) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 0x80090026;
      }
      if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
        return 0x80090026;
      }
      WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),param_2,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c","Status",0x26,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",0x93);
      return 0x80090026;
    }
    if (0x1f < *param_1) {
      _Dst = *(uint **)(param_1 + 6);
      uVar2 = (**(code **)(_Dst + 0x1e))(*(undefined8 *)(param_1 + 4));
      if ((int)uVar2 < 0) {
        DebugTraceError((char)uVar2,"Status",
                        "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",0xae);
      }
      puVar4 = param_1;
      for (uVar3 = (ulonglong)*param_1; uVar3 != 0; uVar3 = uVar3 - 1) {
        *(undefined1 *)puVar4 = 0;
        puVar4 = (uint *)((longlong)puVar4 + 1);
      }
      RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,param_1);
      LOCK();
      puVar4 = _Dst + 4;
      uVar1 = *puVar4;
      *puVar4 = *puVar4 - 1;
      UNLOCK();
      goto joined_r0x000180006364;
    }
    uVar5 = 0x8a;
  }
  DebugTraceError(0x26,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",uVar5);
  return 0x80090026;
}



===== SslEncryptPacket @ 180006690 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

uint SslEncryptPacket(uint *param_1,uint *param_2,undefined8 param_3,undefined8 param_4,
                     undefined8 param_5,undefined4 param_6,undefined8 param_7,undefined8 param_8,
                     undefined4 param_9,undefined4 param_10)

{
  uint uVar1;
  
                    /* 0x6690  124  SslEncryptPacket */
  if ((((param_1 == (uint *)0x0) || (*param_1 < 0x1b0)) || (param_1[1] != 0x44444441)) ||
     (param_1[3] != 0)) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0x80090026;
    }
    if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
      return 0x80090026;
    }
    WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),param_2,param_3,"Status",0x26,
                "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",0x4e);
    return 0x80090026;
  }
  if (((param_2 == (uint *)0x0) || (*param_2 < 0x20)) || (param_2[1] != 0x44444442)) {
    DebugTraceError(0x26,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",0x56)
    ;
    return 0x80090026;
  }
  uVar1 = (**(code **)(param_1 + 0x16))
                    (*(undefined8 *)(param_1 + 0x6a),*(undefined8 *)(param_2 + 4),param_3,param_4,
                     param_5,param_6,param_7,param_8,param_9,param_10);
  if ((int)uVar1 < 0) {
    DebugTraceError((char)uVar1,"Status",
                    "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",0x6c);
    if ((uVar1 & 0x1fff0000) == 0x90000) {
      return uVar1;
    }
    if ((uVar1 & 0x1fff0000) == 0x100000) {
      return uVar1;
    }
    if (uVar1 != 0) {
      if (uVar1 < 0x217) {
        if (uVar1 == 0x216) {
          return 0x80070216;
        }
        switch(uVar1) {
        case 2:
        case 3:
          return 0x80090011;
        default:
          return uVar1;
        case 5:
          return 0x80090010;
        case 8:
        case 0xe:
          return 0x8009000e;
        case 0x57:
          return 0x80090027;
        case 0x70:
          return 0x80070070;
        case 0x7a:
          return 0x80090028;
        case 0xb7:
          return 0x8009000f;
        }
      }
      if (0xc000007b < uVar1) {
        if (0xc0000135 < uVar1) {
          if (uVar1 == 0xc0000142) {
            return 0x8009001d;
          }
          if (uVar1 == 0xc0000139) {
            return 0x8009001d;
          }
          if (uVar1 == 0xc000a000) {
            return 0x80090006;
          }
          return uVar1;
        }
        if (uVar1 == 0xc0000135) {
          return 0x8009001e;
        }
        if (uVar1 == 0xc00000bb) {
          return 0x80090029;
        }
        if (uVar1 == 0xc000009a) {
          return 0x8009000e;
        }
        if (uVar1 == 0xc00000e5) {
          return 0x8009002d;
        }
        return uVar1;
      }
      if (uVar1 == 0xc000007b) {
        return 0x8009001d;
      }
      if (uVar1 == 0xc0000008) {
        return 0x80090026;
      }
      if (0xc0000008 < uVar1) {
        if (uVar1 == 0xc000000d) {
          return 0x80090027;
        }
        if (uVar1 == 0xc0000017) {
          return 0x8009000e;
        }
        if (uVar1 == 0xc0000023) {
          return 0x80090028;
        }
        return uVar1;
      }
      if (uVar1 == 0x800704c0) {
        return 0x800704c0;
      }
      if (uVar1 == 0x54f) {
        return 0x8009002d;
      }
      if (uVar1 == 0x800704c7) {
        return 0x800704c7;
      }
      if (uVar1 == 0x80070578) {
        return 0x80070578;
      }
      return uVar1;
    }
  }
  return 0;
}



===== SslHashHandshake @ 180006ac0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

uint SslHashHandshake(uint *param_1,uint *param_2,undefined8 param_3,undefined8 param_4,
                     undefined4 param_5)

{
  uint uVar1;
  undefined1 uVar2;
  
                    /* 0x6ac0  151  SslHashHandshake */
  if ((((param_1 == (uint *)0x0) || (*param_1 < 0x1b0)) || (param_1[1] != 0x44444441)) ||
     (param_1[3] != 0)) {
    uVar2 = 0xcc;
  }
  else {
    if (((param_2 != (uint *)0x0) && (0x1f < *param_2)) && (param_2[1] == 0x44444443)) {
      uVar1 = (**(code **)(param_1 + 0x28))
                        (*(undefined8 *)(param_1 + 0x6a),*(undefined8 *)(param_2 + 4),param_3,
                         param_4,param_5);
      if (-1 < (int)uVar1) {
        return 0;
      }
      DebugTraceError((char)uVar1,"Status",
                      "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",0xe4);
      if ((uVar1 & 0x1fff0000) == 0x90000) {
        return uVar1;
      }
      if ((uVar1 & 0x1fff0000) == 0x100000) {
        return uVar1;
      }
      if (uVar1 == 0) {
        return 0;
      }
      if (uVar1 < 0x217) {
        if (uVar1 == 0x216) {
          return 0x80070216;
        }
        switch(uVar1) {
        case 2:
        case 3:
          return 0x80090011;
        default:
          return uVar1;
        case 5:
          return 0x80090010;
        case 8:
        case 0xe:
          return 0x8009000e;
        case 0x57:
          return 0x80090027;
        case 0x70:
          return 0x80070070;
        case 0x7a:
          return 0x80090028;
        case 0xb7:
          return 0x8009000f;
        }
      }
      if (0xc000007b < uVar1) {
        if (0xc0000135 < uVar1) {
          if (uVar1 == 0xc0000142) {
            return 0x8009001d;
          }
          if (uVar1 == 0xc0000139) {
            return 0x8009001d;
          }
          if (uVar1 == 0xc000a000) {
            return 0x80090006;
          }
          return uVar1;
        }
        if (uVar1 == 0xc0000135) {
          return 0x8009001e;
        }
        if (uVar1 == 0xc00000bb) {
          return 0x80090029;
        }
        if (uVar1 == 0xc000009a) {
          return 0x8009000e;
        }
        if (uVar1 == 0xc00000e5) {
          return 0x8009002d;
        }
        return uVar1;
      }
      if (uVar1 == 0xc000007b) {
        return 0x8009001d;
      }
      if (uVar1 == 0xc0000008) {
        return 0x80090026;
      }
      if (0xc0000008 < uVar1) {
        if (uVar1 == 0xc000000d) {
          return 0x80090027;
        }
        if (uVar1 == 0xc0000017) {
          return 0x8009000e;
        }
        if (uVar1 == 0xc0000023) {
          return 0x80090028;
        }
        return uVar1;
      }
      if (uVar1 == 0x800704c0) {
        return 0x800704c0;
      }
      if (uVar1 == 0x54f) {
        return 0x8009002d;
      }
      if (uVar1 == 0x800704c7) {
        return 0x800704c7;
      }
      if (uVar1 == 0x80070578) {
        return 0x80070578;
      }
      return uVar1;
    }
    uVar2 = 0xd4;
  }
  DebugTraceError(0x26,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",uVar2);
  return 0x80090026;
}



===== DebugTraceError @ 180006e68 =====

void DebugTraceError(undefined1 param_1,undefined8 param_2,undefined8 param_3,undefined1 param_4)

{
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
    WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),param_2,param_3,(char *)param_2,param_1,
                (char *)param_3,param_4);
  }
  return;
}



===== NCryptFreeObject @ 180006eb0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

SECURITY_STATUS __stdcall NCryptFreeObject(NCRYPT_HANDLE hObject)

{
  uint uVar1;
  HANDLE hHeap;
  undefined8 in_RDX;
  LPVOID in_R8;
  LPVOID lpMem;
  undefined1 uVar2;
  
                    /* 0x6eb0  82  NCryptFreeObject */
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    WPP_SF_P(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),in_RDX,in_R8,hObject);
  }
  if (hObject == 0) {
LAB_18000701e:
    uVar1 = 0x80090026;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_180006fd1;
    uVar2 = 0x9e;
    uVar1 = 0x80090026;
  }
  else {
    if (*(int *)hObject == 0x44440001) {
      LOCK();
      *(int *)(hObject + 4) = *(int *)(hObject + 4) + 1;
      UNLOCK();
      DereferenceProvider(hObject);
      DereferenceProvider(hObject);
LAB_180006f6e:
      uVar1 = 0;
      goto LAB_180006fd1;
    }
    if (*(int *)hObject == 0x44440002) {
      LOCK();
      lpMem = *(LPVOID *)(hObject + 0x28);
      *(undefined8 *)(hObject + 0x28) = 0;
      UNLOCK();
      EtwLogNCryptCertInUse((longlong)lpMem);
      if (lpMem != (LPVOID)0x0) {
        hHeap = GetProcessHeap();
        HeapFree(hHeap,0,lpMem);
        in_R8 = lpMem;
      }
      in_RDX = *(undefined8 *)(hObject + 0x10);
      uVar1 = (**(code **)(*(longlong *)(hObject + 8) + 0x68))
                        (*(undefined8 *)(*(longlong *)(hObject + 8) + 0x110));
      if (uVar1 == 0) {
        DereferenceProvider(*(longlong *)(hObject + 8));
        RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,hObject);
        goto LAB_180006f6e;
      }
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_180006fd1;
      uVar2 = 0xb6;
    }
    else {
      if (*(int *)hObject != 0x44440003) goto LAB_18000701e;
      in_RDX = *(undefined8 *)(hObject + 0x10);
      uVar1 = (**(code **)(*(longlong *)(hObject + 8) + 0xe0))
                        (*(undefined8 *)(*(longlong *)(hObject + 8) + 0x110));
      if (uVar1 == 0) {
        DereferenceProvider(*(longlong *)(hObject + 8));
        SafeAllocaFreeToHeap(hObject);
        uVar1 = 0;
        goto LAB_180006fd1;
      }
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_180006fd1;
      uVar2 = 0xc6;
    }
  }
  WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),in_RDX,in_R8,"Status",(char)uVar1,
              "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",uVar2);
LAB_180006fd1:
  uVar1 = NormalizeNteStatus(uVar1);
  return uVar1;
}



===== EtwLogNCryptCertInUse @ 1800070b0 =====

DWORD EtwLogNCryptCertInUse(longlong param_1)

{
  int iVar1;
  int iVar2;
  LPVOID lpMem;
  DWORD DVar3;
  DWORD DVar4;
  wchar_t *pwVar5;
  short *psVar6;
  wchar_t *pszDest;
  wchar_t *pwVar7;
  HANDLE pvVar8;
  longlong lVar9;
  longlong lVar10;
  wchar_t *pwVar11;
  longlong lVar12;
  longlong lVar14;
  size_t sVar13;
  LPVOID lpMem_00;
  wchar_t *pwVar15;
  LPVOID local_res8;
  LPVOID local_res10;
  _FILETIME local_res18;
  size_t local_res20;
  
  local_res10 = (LPVOID)0x0;
  lpMem_00 = (LPVOID)0x0;
  local_res8 = (LPVOID)0x0;
  pszDest = (wchar_t *)0x0;
  if ((param_1 == 0) ||
     (((*(int *)(param_1 + 0x24) == 0 && (*(int *)(param_1 + 0x28) == 0)) &&
      (*(int *)(param_1 + 0x2c) == 0)))) {
    return 0;
  }
  InitOnceExecuteOnce((PINIT_ONCE)&DAT_180027d10,_ProcessInfoInitOnceCallback,(PVOID)0x0,
                      (LPVOID *)0x0);
  if ((g_pCertInUseProcessInfo == (undefined8 *)0x0) ||
     (pwVar5 = (wchar_t *)*g_pCertInUseProcessInfo, pwVar5 == (wchar_t *)0x0)) {
    pwVar5 = L"";
  }
  lVar9 = 0x7fffffff;
  do {
    if (*pwVar5 == L'\0') break;
    pwVar5 = pwVar5 + 1;
    lVar9 = lVar9 + -1;
  } while (lVar9 != 0);
  psVar6 = (short *)(param_1 + 0x30);
  DVar3 = 0x80070057;
  if (lVar9 != 0) {
    DVar3 = 0;
  }
  if (lVar9 == 0) {
LAB_1800073e2:
    DVar4 = DVar3;
    if (DVar3 == 0) goto LAB_1800073f8;
  }
  else {
    lVar9 = g_stServiceNameLen + (0x7fffffff - lVar9);
    if (psVar6 == (short *)0x0) {
      DVar3 = 0x80070057;
      goto LAB_1800073e2;
    }
    lVar10 = 0x7fffffff;
    do {
      if (*psVar6 == 0) break;
      psVar6 = psVar6 + 1;
      lVar10 = lVar10 + -1;
    } while (lVar10 != 0);
    DVar3 = 0x80070057;
    if (lVar10 == 0) goto LAB_1800073e2;
    pwVar5 = 
    L"{\"procStart\":\"%s\", \"procPath\":\"%s\", \"serviceName\":\"%s\", \"provider\":\"%s\", \"keyId\":\"%s\", \"sign\":%d, \"decrypt\":%d, \"ephemeral\":%d, \"firstUse\":\"%s\", \"lastUse\":\"%s\"}"
    ;
    lVar12 = 0x7fffffff;
    do {
      if (*pwVar5 == L'\0') break;
      pwVar5 = pwVar5 + 1;
      lVar12 = lVar12 + -1;
    } while (lVar12 != 0);
    DVar3 = 0x80070057;
    if (lVar12 != 0) {
      DVar3 = 0;
    }
    if (lVar12 == 0) goto LAB_1800073e2;
    lVar14 = (lVar9 - lVar10) + 0x8000009c;
    if (lVar10 == 0) {
      lVar14 = lVar9 + 0x9d;
    }
    sVar13 = lVar14 + (0x7fffffff - lVar12);
    local_res20 = sVar13;
    DVar3 = FiletimeToString(*(FILETIME *)(param_1 + 0x14),&local_res10);
    if (DVar3 == 0) {
      DVar4 = FiletimeToString(*(FILETIME *)(param_1 + 0x1c),&local_res8);
      DVar3 = DVar4;
      if (DVar4 == 0) {
        pszDest = CertInUseNonzeroAlloc(sVar13 * 2);
        if (pszDest != (wchar_t *)0x0) {
          InitOnceExecuteOnce((PINIT_ONCE)&DAT_180027d10,_ProcessInfoInitOnceCallback,(PVOID)0x0,
                              (LPVOID *)0x0);
          if ((g_pCertInUseProcessInfo == (undefined8 *)0x0) ||
             (pwVar5 = (wchar_t *)g_pCertInUseProcessInfo[2], pwVar5 == (wchar_t *)0x0)) {
            pwVar5 = L"";
          }
          InitOnceExecuteOnce((PINIT_ONCE)&DAT_180027d10,_ProcessInfoInitOnceCallback,(PVOID)0x0,
                              (LPVOID *)0x0);
          if ((g_pCertInUseProcessInfo == (undefined8 *)0x0) ||
             (pwVar15 = (wchar_t *)g_pCertInUseProcessInfo[1], pwVar15 == (wchar_t *)0x0)) {
            pwVar15 = L"";
          }
          iVar1 = *(int *)(param_1 + 0x2c);
          iVar2 = *(int *)(param_1 + 0x28);
          pwVar7 = I_GetProcessName();
          lpMem_00 = local_res8;
          pwVar11 = pszDest;
          DVar3 = StringCchPrintfExW(pszDest,local_res20,(STRSAFE_LPWSTR *)0x0,(size_t *)&local_res8
                                     ,0,
                                     L"{\"procStart\":\"%s\", \"procPath\":\"%s\", \"serviceName\":\"%s\", \"provider\":\"%s\", \"keyId\":\"%s\", \"sign\":%d, \"decrypt\":%d, \"ephemeral\":%d, \"firstUse\":\"%s\", \"lastUse\":\"%s\"}"
                                     ,pwVar15,pwVar7,pwVar5,param_1 + 0x30,param_1 + 0xb0,
                                     *(undefined4 *)(param_1 + 0x24),iVar1 + iVar2,
                                     *(undefined4 *)(param_1 + 0x10),local_res10,local_res8);
          if ((-1 < (int)DVar3) &&
             (((Microsoft_Windows_Crypto_NCryptEnableBits & 0x20) == 0 ||
              (DVar3 = McTemplateU0z_EventWriteTransfer
                                 (pwVar11,(PCEVENT_DESCRIPTOR)&ETW_NCRYPT_CERT_IN_USE_EVENT,pszDest)
              , -1 < (int)DVar3)))) {
            local_res18.dwLowDateTime = 0;
            local_res18.dwHighDateTime = 0;
            GetSystemTimeAsFileTime(&local_res18);
            *(_FILETIME *)(param_1 + 0x14) = local_res18;
            *(undefined8 *)(param_1 + 0x28) = 0;
            *(undefined4 *)(param_1 + 0x24) = 0;
            goto LAB_1800073f8;
          }
          goto LAB_1800073e2;
        }
        DVar3 = 0x8009000e;
      }
      lpMem_00 = local_res8;
    }
  }
  EtwErrorNCryptCertInUse
            (L"Failed to Log CertInUse ETW Event",(STRSAFE_PCNZWCH)(param_1 + 0x30),DVar3);
  DVar4 = DVar3;
LAB_1800073f8:
  lpMem = local_res10;
  if (local_res10 != (LPVOID)0x0) {
    pvVar8 = GetProcessHeap();
    HeapFree(pvVar8,0,lpMem);
  }
  if (lpMem_00 != (LPVOID)0x0) {
    pvVar8 = GetProcessHeap();
    HeapFree(pvVar8,0,lpMem_00);
  }
  if (pszDest != (wchar_t *)0x0) {
    pvVar8 = GetProcessHeap();
    HeapFree(pvVar8,0,pszDest);
  }
  return DVar4;
}



===== SslExportKey @ 1800074b0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

uint SslExportKey(uint *param_1,uint *param_2,undefined8 param_3)

{
  uint uVar1;
  undefined8 uVar2;
  undefined1 uVar3;
  
                    /* 0x74b0  137  SslExportKey */
  if ((((param_1 == (uint *)0x0) || (*param_1 < 0x1b0)) || (param_1[1] != 0x44444441)) ||
     (param_1[3] != 0)) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0x80090026;
    }
    if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
      return 0x80090026;
    }
    uVar3 = 0xf1;
  }
  else {
    if (((param_2 != (uint *)0x0) && (0x1f < *param_2)) && (param_2[1] == 0x44444442)) {
      uVar2 = *(undefined8 *)(param_2 + 4);
      uVar1 = (**(code **)(param_1 + 0x1a))(*(undefined8 *)(param_1 + 0x6a));
      if ((int)uVar1 < 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
          WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),uVar2,param_3,"Status",(char)uVar1,
                      "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",0xb);
        }
        if ((uVar1 & 0x1fff0000) == 0x90000) {
          return uVar1;
        }
        if ((uVar1 & 0x1fff0000) == 0x100000) {
          return uVar1;
        }
        if (uVar1 != 0) {
          if (uVar1 < 0x217) {
            if (uVar1 == 0x216) {
              return 0x80070216;
            }
            switch(uVar1) {
            case 2:
            case 3:
              return 0x80090011;
            default:
              return uVar1;
            case 5:
              return 0x80090010;
            case 8:
            case 0xe:
              return 0x8009000e;
            case 0x57:
              return 0x80090027;
            case 0x70:
              return 0x80070070;
            case 0x7a:
              return 0x80090028;
            case 0xb7:
              return 0x8009000f;
            }
          }
          if (0xc000007b < uVar1) {
            if (0xc0000135 < uVar1) {
              if (uVar1 == 0xc0000142) {
                return 0x8009001d;
              }
              if (uVar1 == 0xc0000139) {
                return 0x8009001d;
              }
              if (uVar1 == 0xc000a000) {
                return 0x80090006;
              }
              return uVar1;
            }
            if (uVar1 == 0xc0000135) {
              return 0x8009001e;
            }
            if (uVar1 == 0xc00000bb) {
              return 0x80090029;
            }
            if (uVar1 == 0xc000009a) {
              return 0x8009000e;
            }
            if (uVar1 == 0xc00000e5) {
              return 0x8009002d;
            }
            return uVar1;
          }
          if (uVar1 == 0xc000007b) {
            return 0x8009001d;
          }
          if (uVar1 == 0xc0000008) {
            return 0x80090026;
          }
          if (0xc0000008 < uVar1) {
            if (uVar1 == 0xc000000d) {
              return 0x80090027;
            }
            if (uVar1 == 0xc0000017) {
              return 0x8009000e;
            }
            if (uVar1 == 0xc0000023) {
              return 0x80090028;
            }
            return uVar1;
          }
          if (uVar1 == 0x800704c0) {
            return 0x800704c0;
          }
          if (uVar1 == 0x54f) {
            return 0x8009002d;
          }
          if (uVar1 == 0x800704c7) {
            return 0x800704c7;
          }
          if (uVar1 == 0x80070578) {
            return 0x80070578;
          }
          return uVar1;
        }
      }
      return 0;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0x80090026;
    }
    if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
      return 0x80090026;
    }
    uVar3 = 0xf9;
  }
  WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),param_2,param_3,"Status",0x26,
              "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",uVar3);
  return 0x80090026;
}



===== SslDecryptPacket @ 1800078d0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

uint SslDecryptPacket(uint *param_1,uint *param_2,undefined8 param_3)

{
  uint uVar1;
  undefined8 uVar2;
  undefined1 uVar3;
  
                    /* 0x78d0  121  SslDecryptPacket */
  if ((((param_1 == (uint *)0x0) || (*param_1 < 0x1b0)) || (param_1[1] != 0x44444441)) ||
     (param_1[3] != 0)) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0x80090026;
    }
    if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
      return 0x80090026;
    }
    uVar3 = 0;
  }
  else {
    if (((param_2 != (uint *)0x0) && (0x1f < *param_2)) && (param_2[1] == 0x44444442)) {
      uVar2 = *(undefined8 *)(param_2 + 4);
      uVar1 = (**(code **)(param_1 + 0x14))(*(undefined8 *)(param_1 + 0x6a));
      if ((int)uVar1 < 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
          WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),uVar2,param_3,"Status",(char)uVar1,
                      "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",0x1d);
        }
        if ((uVar1 & 0x1fff0000) == 0x90000) {
          return uVar1;
        }
        if ((uVar1 & 0x1fff0000) == 0x100000) {
          return uVar1;
        }
        if (uVar1 != 0) {
          if (uVar1 < 0x217) {
            if (uVar1 == 0x216) {
              return 0x80070216;
            }
            switch(uVar1) {
            case 2:
            case 3:
              return 0x80090011;
            default:
              return uVar1;
            case 5:
              return 0x80090010;
            case 8:
            case 0xe:
              return 0x8009000e;
            case 0x57:
              return 0x80090027;
            case 0x70:
              return 0x80070070;
            case 0x7a:
              return 0x80090028;
            case 0xb7:
              return 0x8009000f;
            }
          }
          if (0xc000007b < uVar1) {
            if (0xc0000135 < uVar1) {
              if (uVar1 == 0xc0000142) {
                return 0x8009001d;
              }
              if (uVar1 == 0xc0000139) {
                return 0x8009001d;
              }
              if (uVar1 == 0xc000a000) {
                return 0x80090006;
              }
              return uVar1;
            }
            if (uVar1 == 0xc0000135) {
              return 0x8009001e;
            }
            if (uVar1 == 0xc00000bb) {
              return 0x80090029;
            }
            if (uVar1 == 0xc000009a) {
              return 0x8009000e;
            }
            if (uVar1 == 0xc00000e5) {
              return 0x8009002d;
            }
            return uVar1;
          }
          if (uVar1 == 0xc000007b) {
            return 0x8009001d;
          }
          if (uVar1 == 0xc0000008) {
            return 0x80090026;
          }
          if (0xc0000008 < uVar1) {
            if (uVar1 == 0xc000000d) {
              return 0x80090027;
            }
            if (uVar1 == 0xc0000017) {
              return 0x8009000e;
            }
            if (uVar1 == 0xc0000023) {
              return 0x80090028;
            }
            return uVar1;
          }
          if (uVar1 == 0x800704c0) {
            return 0x800704c0;
          }
          if (uVar1 == 0x54f) {
            return 0x8009002d;
          }
          if (uVar1 == 0x800704c7) {
            return 0x800704c7;
          }
          if (uVar1 == 0x80070578) {
            return 0x80070578;
          }
          return uVar1;
        }
      }
      return 0;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0x80090026;
    }
    if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
      return 0x80090026;
    }
    uVar3 = 8;
  }
  WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),param_2,param_3,"Status",0x26,
              "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",uVar3);
  return 0x80090026;
}



===== WPP_SF_sDsd @ 180007d24 =====

void WPP_SF_sDsd(undefined8 param_1,undefined8 param_2,undefined8 param_3,char *param_4,
                undefined1 param_5,char *param_6,undefined1 param_7)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  char *pcVar4;
  
  if (param_6 == (char *)0x0) {
    lVar3 = 5;
  }
  else {
    lVar2 = -1;
    do {
      lVar3 = lVar2;
      lVar2 = lVar3 + 1;
    } while (param_6[lVar2] != '\0');
    lVar3 = lVar3 + 2;
  }
  pcVar4 = param_6;
  if (param_6 == (char *)0x0) {
    pcVar4 = "NULL";
  }
  lVar2 = -1;
  if (param_4 == (char *)0x0) {
    lVar1 = 5;
  }
  else {
    do {
      lVar1 = lVar2;
      lVar2 = lVar1 + 1;
    } while (param_4[lVar2] != '\0');
    lVar1 = lVar1 + 2;
  }
  if (param_4 == (char *)0x0) {
    param_4 = "NULL";
  }
  EtwTraceMessage(param_1,0x2b,&WPP_0d7e072671ea36b765e87831c1b7d985_Traceguids,10,param_4,lVar1,
                  &param_5,4,pcVar4,lVar3,&param_7,4,0);
  return;
}



===== NCryptCreatePersistedKey @ 180007e00 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

SECURITY_STATUS __stdcall
NCryptCreatePersistedKey
          (NCRYPT_PROV_HANDLE hProvider,NCRYPT_KEY_HANDLE *phKey,LPCWSTR pszAlgId,LPCWSTR pszKeyName
          ,DWORD dwLegacyKeySpec,DWORD dwFlags)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *_Dst;
  longlong lVar4;
  undefined **ppuVar5;
  undefined4 *puVar6;
  LPCWSTR pWVar7;
  undefined1 uVar8;
  undefined1 uVar9;
  
                    /* 0x7e00  67  NCryptCreatePersistedKey */
  uVar3 = 0;
  pWVar7 = pszAlgId;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    WPP_SF_PSSDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),&WPP_GLOBAL_Control,pszAlgId,hProvider,
                 pszAlgId,pszKeyName,(char)dwLegacyKeySpec,(char)dwFlags);
  }
  ppuVar5 = &WPP_GLOBAL_Control;
  if (phKey == (NCRYPT_KEY_HANDLE *)0x0) {
    uVar3 = 0x80090027;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_180007f50;
    uVar9 = 0xaf;
    uVar8 = 0x27;
    uVar3 = 0x80090027;
  }
  else {
    if ((hProvider != 0) && (*(int *)hProvider == 0x44440001)) {
      LOCK();
      *(int *)(hProvider + 4) = *(int *)(hProvider + 4) + 1;
      UNLOCK();
      if (pszKeyName != (LPCWSTR)0x0) {
        lVar4 = -1;
        do {
          lVar1 = lVar4 + 1;
          lVar4 = lVar4 + 1;
        } while (pszKeyName[lVar1] != L'\0');
        uVar3 = (int)lVar4 * 2 + 2;
      }
      uVar2 = uVar3 + 0x30;
      if (uVar2 < 0x30) {
        uVar3 = 0xc0000095;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
          uVar9 = 200;
          uVar8 = 0x95;
          uVar3 = 0xc0000095;
LAB_180007fa7:
          WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),ppuVar5,pWVar7,"Status",uVar8,
                      "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",uVar9);
        }
      }
      else {
        pWVar7 = (LPCWSTR)(ulonglong)uVar2;
        ppuVar5 = (undefined **)0x0;
        _Dst = (undefined4 *)
               RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30));
        if (_Dst == (undefined4 *)0x0) {
          uVar3 = 0x8009000e;
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
            uVar9 = 0xd1;
            uVar8 = 0xe;
            uVar3 = 0x8009000e;
            goto LAB_180007fa7;
          }
        }
        else {
          memset(_Dst,0,(ulonglong)uVar2);
          if (uVar3 == 0) {
            *(undefined8 *)(_Dst + 6) = 0;
          }
          else {
            *(undefined4 **)(_Dst + 6) = _Dst + 0xc;
            memcpy(_Dst + 0xc,pszKeyName,(ulonglong)uVar3);
          }
          uVar3 = (**(code **)(hProvider + 0x28))
                            (*(undefined8 *)(hProvider + 0x110),_Dst + 4,pszAlgId,pszKeyName,
                             dwLegacyKeySpec,dwFlags);
          if (uVar3 == 0) {
            *_Dst = 0x44440002;
            *(NCRYPT_PROV_HANDLE *)(_Dst + 2) = hProvider;
            _Dst[8] = 1;
            *phKey = (NCRYPT_KEY_HANDLE)_Dst;
            goto LAB_180007f50;
          }
          DebugTraceError((char)uVar3,"Status",
                          "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",0xeb)
          ;
          EtwLogNCryptCreateKeyFailed
                    (*(wchar_t **)(hProvider + 0x118),pszKeyName,pszAlgId,(char)dwFlags,(char)uVar3)
          ;
          puVar6 = _Dst;
          for (lVar4 = 0x30; lVar4 != 0; lVar4 = lVar4 + -1) {
            *(undefined1 *)puVar6 = 0;
            puVar6 = (undefined4 *)((longlong)puVar6 + 1);
          }
          SafeAllocaFreeToHeap(_Dst);
        }
      }
      DereferenceProvider(hProvider);
      goto LAB_180007f50;
    }
    uVar3 = 0x80090026;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_180007f50;
    uVar9 = 0xb8;
    uVar8 = 0x26;
  }
  WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),&WPP_GLOBAL_Control,pWVar7,"Status",uVar8,
              "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",uVar9);
LAB_180007f50:
  uVar3 = NormalizeNteStatus(uVar3);
  return uVar3;
}



===== DereferenceProvider @ 180008110 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void DereferenceProvider(longlong param_1)

{
  int *piVar1;
  int iVar2;
  
  LOCK();
  piVar1 = (int *)(param_1 + 4);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    iVar2 = (**(code **)(param_1 + 0x60))(*(undefined8 *)(param_1 + 0x110));
    if (iVar2 < 0) {
      DebugTraceError((char)iVar2,"Status",
                      "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",0x7b);
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((WPP_GLOBAL_Control[0x1c] & 0x20) != 0)) {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0xc,
               &WPP_7a4fecd660bc33d31f6cd64b40025006_Traceguids,param_1);
    }
    UnloadProvider(*(undefined8 **)(param_1 + 8));
    SafeAllocaFreeToHeap(param_1);
  }
  return;
}



===== NCryptGetProperty @ 1800081b0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

SECURITY_STATUS __stdcall
NCryptGetProperty(NCRYPT_HANDLE hObject,LPCWSTR pszProperty,PBYTE pbOutput,DWORD cbOutput,
                 DWORD *pcbResult,DWORD dwFlags)

{
  undefined1 auVar1 [16];
  bool bVar2;
  bool bVar3;
  bool bVar4;
  uint uVar5;
  uint uVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  longlong lVar9;
  int iVar10;
  undefined1 *puVar11;
  int iVar12;
  undefined1 *puVar13;
  undefined1 *puVar14;
  undefined4 in_register_0000008c;
  undefined1 (*pauVar15) [16];
  uint local_res8 [2];
  LPCWSTR in_stack_ffffffffffffff88;
  undefined4 uVar16;
  uint local_58;
  undefined1 (*local_50) [16];
  NCRYPT_HANDLE local_48;
  NCRYPT_HANDLE local_40;
  
                    /* 0x81b0  83  NCryptGetProperty */
  pauVar15 = (undefined1 (*) [16])CONCAT44(in_register_0000008c,cbOutput);
  local_48 = 0;
  bVar2 = false;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    in_stack_ffffffffffffff88 = pszProperty;
    WPP_SF_PSD(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x10,pbOutput,hObject,pszProperty,
               (char)dwFlags);
    pauVar15 = (undefined1 (*) [16])(ulonglong)cbOutput;
  }
  if ((hObject == 0) || (*(int *)hObject != 0x44440001)) {
    local_40 = 0;
    if ((hObject == 0) || (*(int *)hObject != 0x44440002)) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
        WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),
                    "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",pbOutput,
                    "Status",0x26,
                    "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",0x41);
      }
      return -0x7ff6ffda;
    }
    local_48 = hObject;
  }
  else {
    LOCK();
    *(int *)(hObject + 4) = *(int *)(hObject + 4) + 1;
    UNLOCK();
    local_40 = hObject;
  }
  local_50 = (undefined1 (*) [16])pbOutput;
  if ((pszProperty == (LPCWSTR)0x0) || (pcbResult == (DWORD *)0x0)) {
    uVar6 = 0x80090027;
    DebugTraceError(0x27,"Status",
                    "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",0x49);
  }
  else {
    uVar7 = 0xffffffffffffffff;
    do {
      uVar7 = uVar7 + 1;
    } while (pszProperty[uVar7] != L'\0');
    if (uVar7 < 0x41) {
      uVar6 = 0x80090028;
      local_58 = cbOutput;
      bVar2 = false;
      do {
        uVar16 = (undefined4)((ulonglong)in_stack_ffffffffffffff88 >> 0x20);
        if (local_48 != 0) {
          bVar4 = false;
          lVar9 = 0;
          local_res8[0] = 0;
          do {
            iVar10 = (uint)(ushort)pszProperty[lVar9] - (uint)(ushort)L"Provider Handle"[lVar9];
            if ((iVar10 != 0) ||
               (iVar10 = (uint)(ushort)pszProperty[lVar9 + 1] -
                         (uint)(ushort)L"Provider Handle"[lVar9 + 1], iVar10 != 0)) break;
            lVar9 = lVar9 + 2;
          } while (lVar9 != 0x10);
          if (iVar10 != 0) {
            lVar9 = 0;
            do {
              iVar10 = (uint)(ushort)pszProperty[lVar9] - (uint)(ushort)L"UI Policy"[lVar9];
              if ((iVar10 != 0) ||
                 (iVar10 = (uint)(ushort)pszProperty[lVar9 + 1] -
                           (uint)(ushort)L"UI Policy"[lVar9 + 1], iVar10 != 0)) break;
              lVar9 = lVar9 + 2;
            } while (lVar9 != 10);
            lVar9 = -1;
            do {
              iVar12 = (uint)(ushort)pszProperty[lVar9 + 1] -
                       (uint)(ushort)L"ECCCurveNameList"[lVar9 + 1];
              if ((iVar12 != 0) || (lVar9 = lVar9 + 2, lVar9 == 0x11)) break;
              iVar12 = (uint)(ushort)pszProperty[lVar9] - (uint)(ushort)L"ECCCurveNameList"[lVar9];
            } while (iVar12 == 0);
            if (local_50 != (undefined1 (*) [16])0x0) {
              if (iVar10 == 0) {
                if (local_58 < 0x21) {
                  bVar4 = true;
                  local_50 = (undefined1 (*) [16])0x0;
                  local_58 = 0;
                }
                else {
                  local_50 = local_50 + 2;
                  local_58 = local_58 - 0x20;
                }
              }
              else if (iVar12 == 0) {
                local_50 = (undefined1 (*) [16])MSCryptAlloc((ulonglong)local_58);
                if (local_50 == (undefined1 (*) [16])0x0) {
                  uVar6 = 0x8009000e;
                  goto LAB_1800083ee;
                }
                bVar2 = true;
              }
            }
            in_stack_ffffffffffffff88 = (LPCWSTR)CONCAT44(uVar16,local_58);
            pauVar15 = local_50;
            uVar5 = (**(code **)(*(longlong *)(local_48 + 8) + 0x38))
                              (*(undefined8 *)(*(longlong *)(local_48 + 8) + 0x110),
                               *(undefined8 *)(local_48 + 0x10),pszProperty,local_50,
                               in_stack_ffffffffffffff88,local_res8,dwFlags);
            uVar16 = (undefined4)((ulonglong)in_stack_ffffffffffffff88 >> 0x20);
            if ((iVar12 == 0) && ((uVar5 == 0 || (uVar5 == 0x80090028)))) {
              bVar3 = bVar2;
              if (local_50 == (undefined1 (*) [16])0x0) {
                local_50 = (undefined1 (*) [16])MSCryptAlloc((ulonglong)local_res8[0]);
                if (local_50 == (undefined1 (*) [16])0x0) {
                  uVar6 = 0x8009000e;
                  goto LAB_1800083ee;
                }
                bVar3 = true;
                bVar2 = true;
                uVar5 = (**(code **)(*(longlong *)(local_48 + 8) + 0x38))
                                  (*(undefined8 *)(*(longlong *)(local_48 + 8) + 0x110),
                                   *(undefined8 *)(local_48 + 0x10),pszProperty,local_50,
                                   CONCAT44(uVar16,local_res8[0]),local_res8,dwFlags);
                if (uVar5 != 0) {
                  uVar6 = NormalizeNteStatus(uVar5);
                  goto LAB_1800083ee;
                }
              }
              pauVar15 = (undefined1 (*) [16])(ulonglong)cbOutput;
              in_stack_ffffffffffffff88 = (LPCWSTR)pcbResult;
              uVar8 = DeserializeCurveNameList
                                ((byte *)local_50,(ulonglong)local_res8[0],(uint *)pbOutput,cbOutput
                                 ,pcbResult);
              uVar5 = (uint)uVar8;
              bVar2 = bVar3;
            }
            else {
              *pcbResult = local_res8[0];
            }
            if (iVar10 != 0) goto LAB_1800083d2;
            *pcbResult = *pcbResult + 0x20;
            if (!bVar4) {
              if (uVar5 != 0) goto LAB_1800083d2;
              if (pbOutput != (PBYTE)0x0) {
                auVar1 = *local_50;
                uVar6 = *(uint *)(*local_50 + 8);
                puVar11 = (undefined1 *)0x0;
                if (uVar6 != 0) {
                  puVar11 = local_50[1] + 4;
                }
                puVar14 = (undefined1 *)0x0;
                if (auVar1._12_4_ != 0) {
                  puVar14 = local_50[1] + (ulonglong)uVar6 + 4;
                }
                puVar13 = (undefined1 *)0x0;
                if (*(int *)local_50[1] != 0) {
                  puVar13 = local_50[1] + (ulonglong)uVar6 + (auVar1._8_8_ >> 0x20) + 4;
                }
                *(int *)pbOutput = auVar1._0_4_;
                *(int *)(pbOutput + 4) = auVar1._4_4_;
                *(undefined1 **)(pbOutput + 8) = puVar11;
                *(undefined1 **)(pbOutput + 0x10) = puVar14;
                *(undefined1 **)(pbOutput + 0x18) = puVar13;
              }
LAB_1800083e6:
              uVar6 = 0;
            }
            goto LAB_1800083ee;
          }
          *pcbResult = 8;
          if (pbOutput == (PBYTE)0x0) {
            uVar6 = 0;
          }
          else if (7 < (uint)pauVar15) {
            ValidateAndReferenceProvider(*(int **)(local_48 + 8));
            uVar6 = 0;
            *(undefined8 *)pbOutput = *(undefined8 *)(local_48 + 8);
          }
          goto LAB_1800083ee;
        }
        in_stack_ffffffffffffff88 = (LPCWSTR)pcbResult;
        uVar5 = (**(code **)(local_40 + 0x30))
                          (*(undefined8 *)(local_40 + 0x110),pszProperty,pbOutput,pauVar15,pcbResult
                           ,dwFlags);
LAB_1800083d2:
        if (uVar5 != 0x8009002e) {
          if (uVar5 == 0) goto LAB_1800083e6;
          goto LAB_180008699;
        }
        if ((dwFlags & 0x40) != 0) {
          uVar6 = 0x80090022;
          DebugTraceError(0x22,"Status",
                          "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",0x3f)
          ;
          goto LAB_1800083ee;
        }
        if (local_48 == 0) {
          uVar5 = (**(code **)(local_40 + 0xc0))(*(undefined8 *)(local_40 + 0x110),0);
          if (uVar5 != 0) goto LAB_180008833;
        }
        else {
          uVar5 = (**(code **)(*(longlong *)(local_48 + 8) + 0xc0))
                            (*(undefined8 *)(*(longlong *)(local_48 + 8) + 0x110),hObject,
                             L"NCryptGetProperty",0);
          if (uVar5 != 0) {
            pauVar15 = (undefined1 (*) [16])0x64c;
            goto LAB_180008839;
          }
        }
        pauVar15 = (undefined1 (*) [16])(ulonglong)cbOutput;
      } while( true );
    }
    uVar6 = 0x80090027;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",pbOutput,
                  "Status",0x27,"onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c"
                  ,0x50);
    }
  }
LAB_1800083ee:
  if (local_40 != 0) {
    DereferenceProvider(local_40);
  }
  if (bVar2) {
    SafeAllocaFreeToHeap(local_50);
  }
  return uVar6;
LAB_180008833:
  pauVar15 = (undefined1 (*) [16])0x658;
LAB_180008839:
  DebugTraceError((char)uVar5,"Status",
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",
                  (char)pauVar15);
LAB_180008699:
  if ((local_48 != 0) && (*(longlong *)(local_48 + 8) != 0)) {
    EtwLogNCryptOperationFailed
              (0x10,*(wchar_t **)(*(longlong *)(local_48 + 8) + 0x118),
               *(wchar_t **)(local_48 + 0x18),pauVar15,(char)uVar5);
  }
  uVar6 = NormalizeNteStatus(uVar5);
  goto LAB_1800083ee;
}



===== WPP_SF_P @ 1800088b8 =====

void WPP_SF_P(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  TraceMessage(param_1,0x2b,&WPP_7a4fecd660bc33d31f6cd64b40025006_Traceguids,0x14,&local_res20,8,0);
  return;
}



===== SslExpandPreSharedKey @ 180008910 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void SslExpandPreSharedKey
               (uint *param_1,uint *param_2,undefined8 param_3,undefined4 param_4,
               undefined8 *param_5,undefined8 param_6,undefined4 param_7)

{
  uint uVar1;
  undefined8 *puVar2;
  uint *puVar3;
  undefined8 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  
                    /* 0x8910  133  SslExpandPreSharedKey */
  if ((((param_1 == (uint *)0x0) || (*param_1 < 0x1b0)) || (param_1[1] != 0x44444441)) ||
     (param_1[3] != 0)) {
    param_1 = (uint *)0x0;
  }
  if (((param_2 == (uint *)0x0) || (*param_2 < 0x20)) ||
     (puVar3 = param_2, param_2[1] != 0x44444442)) {
    puVar3 = (uint *)0x0;
  }
  if ((param_1 == (uint *)0x0) || (puVar3 == (uint *)0x0)) {
    uVar1 = 0x80090026;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_180008a37;
    uVar6 = 0xa8;
    uVar5 = 0x26;
    uVar1 = 0x80090026;
  }
  else {
    if (param_5 == (undefined8 *)0x0) {
      uVar1 = 0x80090027;
      DebugTraceError(0x27,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",
                      0xaf);
      goto LAB_180008a37;
    }
    if ((ushort)param_1[8] < 5) {
      uVar1 = 0x80090029;
      DebugTraceError(0x29,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",
                      0xba);
      goto LAB_180008a37;
    }
    uVar4 = 0x20;
    param_2 = (uint *)0x0;
    puVar2 = (undefined8 *)
             RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30));
    if (puVar2 != (undefined8 *)0x0) {
      *puVar2 = 0;
      puVar2[1] = 0;
      puVar2[2] = 0;
      puVar2[3] = 0;
      uVar1 = (**(code **)(param_1 + 0x5a))
                        (*(undefined8 *)(param_1 + 0x6a),*(undefined8 *)(puVar3 + 4),param_3,param_4
                         ,puVar2 + 2,param_6,param_7);
      if ((int)uVar1 < 0) {
        DebugTraceError((char)uVar1,"Status",
                        "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",0xd9);
        SafeAllocaFreeToHeap(puVar2);
      }
      else {
        *(undefined4 *)puVar2 = 0x20;
        *(undefined8 *)((longlong)puVar2 + 4) = 0x44444442;
        *(undefined4 *)((longlong)puVar2 + 0xc) = 1;
        puVar2[3] = param_1;
        *param_5 = puVar2;
        LOCK();
        param_1[4] = param_1[4] + 1;
        UNLOCK();
        uVar1 = 0;
      }
      goto LAB_180008a37;
    }
    uVar1 = 0x8009000e;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_180008a37;
    uVar6 = 0xc6;
    uVar5 = 0xe;
    param_3 = uVar4;
  }
  WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),param_2,param_3,"Status",uVar5,
              "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",uVar6);
LAB_180008a37:
  NormalizeNteStatus(uVar1);
  return;
}



===== NCryptOpenKey @ 180008b70 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

SECURITY_STATUS __stdcall
NCryptOpenKey(NCRYPT_PROV_HANDLE hProvider,NCRYPT_KEY_HANDLE *phKey,LPCWSTR pszKeyName,
             DWORD dwLegacyKeySpec,DWORD dwFlags)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  longlong lVar4;
  undefined4 *_Dst;
  undefined **ppuVar5;
  undefined4 *puVar6;
  undefined1 uVar7;
  undefined1 uVar8;
  
                    /* 0x8b70  90  NCryptOpenKey */
  uVar3 = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    WPP_SF_PSDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),&WPP_GLOBAL_Control,pszKeyName,hProvider,
                pszKeyName,(char)dwLegacyKeySpec,(char)dwFlags);
  }
  ppuVar5 = &WPP_GLOBAL_Control;
  if (phKey == (NCRYPT_KEY_HANDLE *)0x0) {
    uVar3 = 0x80090027;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),&WPP_GLOBAL_Control,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c","Status",0x27
                  ,"onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",0x18);
    }
    goto LAB_180008c42;
  }
  if ((hProvider == 0) || (*(int *)hProvider != 0x44440001)) {
    uVar3 = 0x80090026;
    DebugTraceError(0x26,"Status",
                    "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",0x21);
    goto LAB_180008c42;
  }
  LOCK();
  *(int *)(hProvider + 4) = *(int *)(hProvider + 4) + 1;
  UNLOCK();
  if (pszKeyName != (LPCWSTR)0x0) {
    lVar4 = -1;
    do {
      lVar2 = lVar4 + 1;
      lVar4 = lVar4 + 1;
    } while (pszKeyName[lVar2] != L'\0');
    uVar3 = (int)lVar4 * 2 + 2;
  }
  uVar1 = uVar3 + 0x30;
  if (uVar1 < 0x30) {
    uVar3 = 0xc0000095;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      uVar8 = 0x30;
      uVar7 = 0x95;
LAB_180008c2a:
      WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),ppuVar5,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c","Status",
                  uVar7,"onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",uVar8);
    }
  }
  else {
    _Dst = (undefined4 *)MSCryptAlloc((ulonglong)uVar1);
    if (_Dst == (undefined4 *)0x0) {
      uVar3 = 0x8009000e;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
        uVar8 = 0x39;
        uVar7 = 0xe;
        goto LAB_180008c2a;
      }
    }
    else {
      memset(_Dst,0,(ulonglong)uVar1);
      *_Dst = 0x44440002;
      *(NCRYPT_PROV_HANDLE *)(_Dst + 2) = hProvider;
      if (uVar3 < 2) {
        *(undefined8 *)(_Dst + 6) = 0;
      }
      else {
        *(undefined4 **)(_Dst + 6) = _Dst + 0xc;
        memcpy(_Dst + 0xc,pszKeyName,(ulonglong)uVar3);
      }
      do {
        puVar6 = _Dst + 4;
        uVar3 = (**(code **)(hProvider + 0x20))
                          (*(undefined8 *)(hProvider + 0x110),puVar6,pszKeyName,dwLegacyKeySpec,
                           dwFlags);
        if (uVar3 != 0x8009002e) {
          if (uVar3 == 0) {
            *phKey = (NCRYPT_KEY_HANDLE)_Dst;
            goto LAB_180008c42;
          }
          break;
        }
        if ((dwFlags & 0x40) != 0) {
          uVar3 = 0x80090022;
          goto LAB_180008dda;
        }
        puVar6 = _Dst;
        uVar3 = (**(code **)(hProvider + 0xc0))
                          (*(undefined8 *)(hProvider + 0x110),_Dst,L"NCryptOpenKey",0);
      } while (uVar3 == 0);
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
        WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),puVar6,
                    "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c","Status",
                    (char)uVar3,"onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c"
                    ,0x71);
      }
      EtwLogNCryptOpenKeyFailed(*(wchar_t **)(hProvider + 0x118),pszKeyName,(char)uVar3);
LAB_180008dda:
      puVar6 = _Dst;
      for (lVar4 = 0x30; lVar4 != 0; lVar4 = lVar4 + -1) {
        *(undefined1 *)puVar6 = 0;
        puVar6 = (undefined4 *)((longlong)puVar6 + 1);
      }
      SafeAllocaFreeToHeap(_Dst);
    }
  }
  DereferenceProvider(hProvider);
LAB_180008c42:
  uVar3 = NormalizeNteStatus(uVar3);
  return uVar3;
}



===== SslDecrementProviderReferenceCount @ 180008ea0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

undefined8 SslDecrementProviderReferenceCount(uint *param_1,undefined8 param_2,undefined8 param_3)

{
  uint *puVar1;
  uint uVar2;
  undefined8 uVar3;
  
                    /* 0x8ea0  120  SslDecrementProviderReferenceCount */
  if ((*param_1 < 0x1b0) || (param_1[1] != 0x44444441)) {
    uVar3 = 0xc0000008;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),param_2,param_3,"Status",8,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",0xff);
    }
  }
  else {
    LOCK();
    puVar1 = param_1 + 4;
    uVar2 = *puVar1;
    *puVar1 = *puVar1 - 1;
    UNLOCK();
    uVar3 = 0;
    if (((int)uVar2 < 2) && (param_1[3] != 0)) {
      (**(code **)(param_1 + 0x1e))(*(undefined8 *)(param_1 + 0x6a));
      UnloadProvider(*(undefined8 **)(param_1 + 6));
      memset(param_1,0,(ulonglong)*param_1);
      SafeAllocaFreeToHeap(param_1);
    }
  }
  return uVar3;
}



===== WPP_SF_PSSDD @ 180008f70 =====

void WPP_SF_PSSDD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 wchar_t *param_5,wchar_t *param_6,undefined1 param_7,undefined1 param_8)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  undefined8 local_res20;
  
  lVar2 = -1;
  lVar3 = 10;
  if (param_6 == (wchar_t *)0x0) {
    lVar4 = 10;
  }
  else {
    lVar4 = -1;
    do {
      lVar1 = lVar4 + 1;
      lVar4 = lVar4 + 1;
    } while (param_6[lVar1] != L'\0');
    lVar4 = lVar4 * 2 + 2;
  }
  if (param_6 == (wchar_t *)0x0) {
    param_6 = L"NULL";
  }
  if (param_5 != (wchar_t *)0x0) {
    do {
      lVar3 = lVar2 + 1;
      lVar2 = lVar2 + 1;
    } while (param_5[lVar3] != L'\0');
    lVar3 = lVar2 * 2 + 2;
  }
  if (param_5 == (wchar_t *)0x0) {
    param_5 = L"NULL";
  }
  local_res20 = param_4;
  TraceMessage(param_1,0x2b,&WPP_7a4fecd660bc33d31f6cd64b40025006_Traceguids,0xf,&local_res20,8,
               param_5,lVar3,param_6,lVar4,&param_7,4,&param_8,4,0);
  return;
}



===== SslComputeSessionHash @ 180009090 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void SslComputeSessionHash
               (uint *param_1,uint *param_2,undefined8 param_3,undefined8 param_4,undefined4 param_5
               ,undefined8 param_6,undefined4 param_7)

{
  uint uVar1;
  undefined1 uVar2;
  
                    /* 0x9090  116  SslComputeSessionHash */
  if ((((param_1 == (uint *)0x0) || (*param_1 < 0x1b0)) || (param_1[1] != 0x44444441)) ||
     (param_1[3] != 0)) {
    uVar1 = 0x80090026;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_180009152;
    uVar2 = 0x2d;
  }
  else {
    if (((param_2 != (uint *)0x0) && (0x1f < *param_2)) && (param_2[1] == 0x44444443)) {
      if ((ushort)param_1[8] < 3) {
        uVar1 = 0x80090029;
        DebugTraceError(0x29,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",
                        0x43);
      }
      else {
        uVar1 = (**(code **)(param_1 + 0x3e))
                          (*(undefined8 *)(param_1 + 0x6a),*(undefined8 *)(param_2 + 4),param_3,
                           param_4,param_5,param_6,param_7);
        if ((int)uVar1 < 0) {
          DebugTraceError((char)uVar1,"Status",
                          "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",0x55);
        }
      }
      goto LAB_180009152;
    }
    uVar1 = 0x80090026;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_180009152;
    uVar2 = 0x35;
  }
  uVar1 = 0x80090026;
  WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),param_2,param_3,"Status",0x26,
              "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",uVar2);
LAB_180009152:
  NormalizeNteStatus(uVar1);
  return;
}



===== SslLookupCipherSuiteInfo @ 1800091f0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void SslLookupCipherSuiteInfo(uint *param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  
                    /* 0x91f0  156  SslLookupCipherSuiteInfo */
  if ((((param_1 == (uint *)0x0) || (*param_1 < 0x1b0)) || (param_1[1] != 0x44444441)) ||
     (param_1[3] != 0)) {
    uVar1 = 0x80090026;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_18000928e;
    uVar3 = 0xfb;
    uVar2 = 0x26;
    uVar1 = 0x80090026;
  }
  else {
    uVar1 = (**(code **)(param_1 + 0x2e))(*(undefined8 *)(param_1 + 0x6a));
    if (-1 < (int)uVar1) {
      uVar1 = 0;
      goto LAB_18000928e;
    }
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_18000928e;
    uVar3 = 0xc;
    uVar2 = (undefined1)uVar1;
  }
  WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),param_2,param_3,"Status",uVar2,
              "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",uVar3);
LAB_18000928e:
  NormalizeNteStatus(uVar1);
  return;
}



===== NCryptDeriveKey @ 1800092e0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

SECURITY_STATUS __stdcall
NCryptDeriveKey(NCRYPT_SECRET_HANDLE hSharedSecret,LPCWSTR pwszKDF,NCryptBufferDesc *pParameterList,
               PBYTE pbDerivedKey,DWORD cbDerivedKey,DWORD *pcbResult,ULONG dwFlags)

{
  uint uVar1;
  undefined8 uVar2;
  
                    /* 0x92e0  72  NCryptDeriveKey */
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    WPP_SF_PSD(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x20,pParameterList,hSharedSecret,pwszKDF,
               (char)dwFlags);
  }
  if ((hSharedSecret == 0) || (*(int *)hSharedSecret != 0x44440003)) {
    uVar1 = 0x80090026;
    DebugTraceError(0x26,"Status",
                    "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",0x96);
  }
  else {
    uVar1 = (**(code **)(*(longlong *)(hSharedSecret + 8) + 0xd8))
                      (*(undefined8 *)(*(longlong *)(hSharedSecret + 8) + 0x110),
                       *(undefined8 *)(hSharedSecret + 0x10),pwszKDF,pParameterList,pbDerivedKey,
                       cbDerivedKey,pcbResult,dwFlags);
    if (uVar1 != 0) {
      uVar2 = 0xea6;
      DebugTraceError((char)uVar1,"Status",
                      "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",0xa6);
      EtwLogNCryptOperationFailed
                (9,*(wchar_t **)(*(longlong *)(hSharedSecret + 8) + 0x118),L"DeriveKey",uVar2,
                 (char)uVar1);
    }
  }
  uVar1 = NormalizeNteStatus(uVar1);
  return uVar1;
}



===== WPP_SF_PSD @ 180009430 =====

void WPP_SF_PSD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
               wchar_t *param_5,undefined1 param_6)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 local_res20;
  
  if (param_5 == (wchar_t *)0x0) {
    lVar2 = 10;
  }
  else {
    lVar2 = -1;
    do {
      lVar1 = lVar2 + 1;
      lVar2 = lVar2 + 1;
    } while (param_5[lVar1] != L'\0');
    lVar2 = lVar2 * 2 + 2;
  }
  if (param_5 == (wchar_t *)0x0) {
    param_5 = L"NULL";
  }
  local_res20 = param_4;
  TraceMessage(param_1,0x2b,&WPP_7a4fecd660bc33d31f6cd64b40025006_Traceguids,param_2,&local_res20,8,
               param_5,lVar2,&param_6,4,0);
  return;
}



===== UnloadProvider @ 1800094e4 =====

void UnloadProvider(undefined8 *param_1)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  
  if ((g_fLoaderInitialized != 0) && (param_1 != (undefined8 *)0x0)) {
    EnterCriticalSection((LPCRITICAL_SECTION)&g_csLoaderLock);
    iVar1 = *(int *)(param_1 + 2);
    *(int *)(param_1 + 2) = iVar1 + -1;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((WPP_GLOBAL_Control[0x1c] & 0x20) != 0)) {
      WPP_SF_qSD(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x1d,
                 &WPP_67679bdabad938a7dfcc8815ccec1def_Traceguids,param_1,(wchar_t *)*param_1,
                 (char)(iVar1 + -1));
    }
    if (*(int *)(param_1 + 2) == 0) {
      if ((HMODULE)param_1[1] != (HMODULE)0x0) {
        _FreeImage((HMODULE)param_1[1]);
      }
      puVar3 = g_pLoadedProviderList;
      if (param_1 == g_pLoadedProviderList) {
        g_pLoadedProviderList = (undefined8 *)param_1[3];
      }
      else {
        do {
          puVar2 = puVar3;
          if (puVar2 == (undefined8 *)0x0) break;
          puVar3 = (undefined8 *)puVar2[3];
        } while ((undefined8 *)puVar2[3] != param_1);
        puVar2[3] = param_1[3];
      }
      param_1[3] = 0;
      SafeAllocaFreeToHeap(param_1);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&g_csLoaderLock);
  }
  return;
}



===== WPP_SF_qSD @ 1800095d0 =====

void WPP_SF_qSD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
               wchar_t *param_5,undefined1 param_6)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 local_res20;
  
  if (param_5 == (wchar_t *)0x0) {
    lVar2 = 10;
  }
  else {
    lVar2 = -1;
    do {
      lVar1 = lVar2 + 1;
      lVar2 = lVar2 + 1;
    } while (param_5[lVar1] != L'\0');
    lVar2 = lVar2 * 2 + 2;
  }
  if (param_5 == (wchar_t *)0x0) {
    param_5 = L"NULL";
  }
  local_res20 = param_4;
  TraceMessage(param_1,0x2b,param_3,param_2,&local_res20,8,param_5,lVar2,&param_6,4,0);
  return;
}



===== SslExpandTrafficKeys @ 180009680 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void SslExpandTrafficKeys
               (uint *param_1,uint *param_2,uint *param_3,undefined8 *param_4,undefined8 *param_5,
               undefined8 param_6,undefined4 param_7)

{
  uint uVar1;
  undefined8 *puVar2;
  undefined1 uVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  undefined1 uVar7;
  undefined8 *puVar8;
  
                    /* 0x9680  135  SslExpandTrafficKeys */
  if ((((param_1 == (uint *)0x0) || (*param_1 < 0x1b0)) || (param_1[1] != 0x44444441)) ||
     (param_1[3] != 0)) {
    param_1 = (uint *)0x0;
  }
  if (((param_2 == (uint *)0x0) || (*param_2 < 0x20)) || (param_2[1] != 0x44444442)) {
    param_2 = (uint *)0x0;
  }
  if (((param_3 == (uint *)0x0) || (*param_3 < 0x20)) || (param_3[1] != 0x44444443)) {
    param_3 = (uint *)0x0;
  }
  puVar6 = (undefined8 *)0x0;
  puVar5 = (undefined8 *)0x0;
  if (((param_1 == (uint *)0x0) || (param_2 == (uint *)0x0)) || (param_3 == (uint *)0x0)) {
    uVar1 = 0x80090026;
    uVar7 = 0x65;
    uVar3 = 0x26;
  }
  else if ((param_4 == (undefined8 *)0x0) && (param_5 == (undefined8 *)0x0)) {
    uVar1 = 0x80090027;
    uVar7 = 0x6c;
    uVar3 = 0x27;
  }
  else {
    if (3 < (ushort)param_1[8]) {
      if (param_4 != (undefined8 *)0x0) {
        uVar4 = 0;
        puVar6 = (undefined8 *)
                 RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,0x20);
        if (puVar6 == (undefined8 *)0x0) {
          uVar1 = 0x8009000e;
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
            WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),uVar4,
                        "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c","Status",0xe,
                        "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",0x85);
          }
          goto LAB_18000986b;
        }
        *puVar6 = 0;
        puVar6[1] = 0;
        puVar6[2] = 0;
        puVar6[3] = 0;
      }
      if (param_5 == (undefined8 *)0x0) {
LAB_1800097ac:
        puVar2 = puVar5 + 2;
        puVar8 = puVar6 + 2;
        if (puVar5 == (undefined8 *)0x0) {
          puVar2 = (undefined8 *)0x0;
        }
        if (puVar6 == (undefined8 *)0x0) {
          puVar8 = (undefined8 *)0x0;
        }
        uVar4 = *(undefined8 *)(param_2 + 4);
        uVar1 = (**(code **)(param_1 + 0x4c))
                          (*(undefined8 *)(param_1 + 0x6a),uVar4,*(undefined8 *)(param_3 + 4),puVar8
                           ,puVar2,param_6,param_7);
        if ((int)uVar1 < 0) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
            WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),uVar4,
                        "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c","Status",
                        (char)uVar1,"onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",
                        0xa5);
          }
        }
        else {
          if (puVar6 != (undefined8 *)0x0) {
            *(undefined4 *)puVar6 = 0x20;
            *(undefined8 *)((longlong)puVar6 + 4) = 0x44444442;
            *(undefined4 *)((longlong)puVar6 + 0xc) = 1;
            puVar6[3] = param_1;
            *param_4 = puVar6;
            puVar6 = (undefined8 *)0x0;
            LOCK();
            param_1[4] = param_1[4] + 1;
            UNLOCK();
          }
          if (puVar5 != (undefined8 *)0x0) {
            *(undefined4 *)puVar5 = 0x20;
            *(undefined8 *)((longlong)puVar5 + 4) = 0x44444442;
            *(undefined4 *)((longlong)puVar5 + 0xc) = 1;
            puVar5[3] = param_1;
            *param_5 = puVar5;
            puVar5 = (undefined8 *)0x0;
            LOCK();
            param_1[4] = param_1[4] + 1;
            UNLOCK();
          }
          uVar1 = 0;
        }
      }
      else {
        puVar5 = (undefined8 *)
                 RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,0x20);
        if (puVar5 != (undefined8 *)0x0) {
          *puVar5 = 0;
          puVar5[1] = 0;
          puVar5[2] = 0;
          puVar5[3] = 0;
          goto LAB_1800097ac;
        }
        uVar1 = 0x8009000e;
        DebugTraceError(0xe,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",
                        0x91);
      }
      if (puVar6 != (undefined8 *)0x0) {
        SafeAllocaFreeToHeap(puVar6);
      }
      if (puVar5 != (undefined8 *)0x0) {
        SafeAllocaFreeToHeap(puVar5);
      }
      goto LAB_18000986b;
    }
    uVar1 = 0x80090029;
    uVar7 = 0x77;
    uVar3 = 0x29;
  }
  DebugTraceError(uVar3,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",uVar7)
  ;
LAB_18000986b:
  NormalizeNteStatus(uVar1);
  return;
}



===== NCryptCloseKeyProtector @ 1800099d0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

undefined8 NCryptCloseKeyProtector(int *param_1,undefined8 param_2,undefined *param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  
                    /* 0x99d0  64  NCryptCloseKeyProtector */
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    param_3 = &WPP_6d353d9995a633fdfdb515b4bb0c31fa_Traceguids;
    param_2 = 0xc;
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0xc,
             &WPP_6d353d9995a633fdfdb515b4bb0c31fa_Traceguids,param_1);
  }
  uVar4 = 0;
  if ((param_1 == (int *)0x0) || (*param_1 != 0x48)) {
    uVar4 = 0x80090026;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),param_2,param_3,"Status",0x26,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\router.c",0x3d)
      ;
    }
  }
  else {
    LOCK();
    piVar1 = param_1 + 1;
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    iVar3 = iVar2 + -1;
    if (iVar3 == 0 || iVar2 < 1) {
      if (*(longlong *)(param_1 + 2) != 0) {
        if (*(longlong *)(param_1 + 0xe) != 0) {
          (**(code **)(param_1 + 8))();
        }
        UnloadProvider(*(undefined8 **)(param_1 + 2));
      }
      SafeAllocaFreeToHeap(param_1);
    }
    else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((WPP_GLOBAL_Control[0x1c] & 0x20) != 0)) {
      WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0xd,param_3,param_1,(char)iVar3);
    }
  }
  return uVar4;
}



===== WPP_SF_q @ 180009af8 =====

void WPP_SF_q(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  TraceMessage(param_1,0x2b,param_3,param_2,&local_res20,8,0);
  return;
}



===== entry @ 180009b40 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 entry(undefined8 param_1,undefined8 param_2,char *param_3)

{
  ulonglong uVar1;
  char *pcVar2;
  undefined8 uVar3;
  
  g_hInstance = param_1;
  if ((int)param_2 == 1) {
    LdrDisableThreadCalloutsForDll();
    pcVar2 = (char *)0x1;
    uVar3 = param_1;
    _DllMainCRTStartupForGS2(param_1,1);
    SafeAllocaInitialize();
    McGenEventRegister_EventRegister();
    _DAT_180027df8 = 1;
    WPP_REGISTRATION_GUIDS = &WPP_ThisDir_CTLGUID_CNGTraceControlGuid;
    DAT_180027df0 = 0;
    WPP_GLOBAL_Control = &WPP_MAIN_CB;
    _WPP_MAIN_CB = 0;
    WppInitUm();
    uVar1 = InitializeCNGNcrypt(uVar3,pcVar2,param_3);
    if ((int)uVar1 != 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
        WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),uVar1 & 0xffffffff,param_3,"Status",
                    (char)uVar1,"onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\init.c",
                    0xf0);
      }
      return 0;
    }
    if ((WPP_GLOBAL_Control[0x1c] & 0x20) != 0) {
      uVar3 = 0x100;
      GetModuleFileNameW((HMODULE)0x0,(LPWSTR)&DAT_1800278e0,0x100);
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((WPP_GLOBAL_Control[0x1c] & 0x20) != 0)) {
        WPP_SF_qS(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),10,uVar3,param_1);
      }
    }
  }
  else if ((int)param_2 == 0) {
    UninitializeCNGNcrypt(param_1,param_2,param_3);
    McGenEventUnregister_EventUnregister();
    if (((WPP_GLOBAL_Control[0x1c] & 0x20) != 0) &&
       ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) {
      WPP_SF_qS(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0xb,param_3,param_1);
    }
    WppCleanupUm();
  }
  return 1;
}



===== WppInitUm @ 180009cbc =====

void WppInitUm(void)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined8 local_18;
  undefined8 local_10;
  
  puVar2 = &WPP_REGISTRATION_GUIDS;
  for (puVar1 = (undefined8 *)WPP_GLOBAL_Control; puVar1 != (undefined8 *)0x0;
      puVar1 = (undefined8 *)*puVar1) {
    local_18 = *puVar2;
    local_10 = 0;
    puVar2 = puVar2 + 1;
    puVar1[4] = local_18;
    RegisterTraceGuidsA(WppControlCallback,puVar1,local_18,1,&local_18,0,0,puVar1 + 1);
  }
  return;
}



===== InitializeCNGNcrypt @ 180009d44 =====

ulonglong InitializeCNGNcrypt(undefined8 param_1,char *param_2,char *param_3)

{
  uint uVar1;
  ulonglong uVar2;
  wchar_t *pwVar3;
  undefined *puVar4;
  undefined1 uVar5;
  ulonglong uVar6;
  undefined1 uVar7;
  
  pwVar3 = L"{DCD07F46-25B9-4844-BFA5-C7D582C66524}";
  ASN1_NCRYPT_MODULE_HANDLE = Ordinal_5();
  if (ASN1_NCRYPT_MODULE_HANDLE == 0) {
    uVar6 = 0x80090029;
    puVar4 = WPP_GLOBAL_Control;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_180009e17;
    uVar7 = 0x8d;
    uVar5 = 0x29;
  }
  else {
    uVar1 = MSCryptInitializeMemoryLists();
    uVar6 = (ulonglong)uVar1;
    if (uVar1 == 0) {
      DAT_1800278b0 = DAT_1800278b0 | 1;
      uVar2 = InitializeLoader(pwVar3,param_2,param_3);
      uVar6 = uVar2 & 0xffffffff;
      if ((int)uVar2 == 0) {
        DAT_1800278b0 = DAT_1800278b0 | 2;
        if (DAT_180027cb8 == 0) {
          uVar1 = RtlInitializeCriticalSection(&g_csKeyProtectorLock);
          uVar6 = (ulonglong)uVar1;
          if ((int)uVar1 < 0) {
            param_3 = "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\init.c";
            param_2 = "Status";
            puVar4 = (undefined *)(ulonglong)uVar1;
            DebugTraceError((char)uVar1,"Status",
                            "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\init.c",0xa7);
            goto LAB_180009e17;
          }
          DAT_180027cb8 = 1;
        }
        DAT_1800278b0 = DAT_1800278b0 | 4;
        TraceLoggingRegisterEx_EventRegister_EventSetInformation();
        return 0;
      }
      puVar4 = WPP_GLOBAL_Control;
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_180009e17;
      uVar7 = 0x9f;
    }
    else {
      puVar4 = WPP_GLOBAL_Control;
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_180009e17;
      uVar7 = 0x97;
    }
    uVar5 = (undefined1)uVar6;
  }
  param_3 = "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\init.c";
  puVar4 = *(undefined **)(WPP_GLOBAL_Control + 0x10);
  WPP_SF_sDsd(puVar4,param_2,"onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\init.c",
              "Status",uVar5,"onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\init.c",uVar7
             );
LAB_180009e17:
  UninitializeCNGNcrypt(puVar4,param_2,param_3);
  return uVar6;
}



===== SafeAllocaInitialize @ 180009eac =====

void SafeAllocaInitialize(void)

{
  longlong lVar1;
  
  lVar1 = RtlImageNtHeader(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x10));
  if (((*(char *)((longlong)ProcessEnvironmentBlock + 2) != '\0') || (lVar1 == 0)) ||
     (g_ulMaxStackAllocSize = *(longlong *)(lVar1 + 0x68),
     (ulonglong)(*(longlong *)(lVar1 + 0x60) - g_ulMaxStackAllocSize) < 0x3000)) {
    g_ulMaxStackAllocSize = 0;
  }
  if (lVar1 != 0) {
    g_ulAdditionalProbeSize = (ulonglong)DAT_ff00001748;
    if (g_ulAdditionalProbeSize == 0) {
      g_pfnAllocate = MSCryptAlloc;
      g_ulAdditionalProbeSize = 0x3000;
      g_pfnFree = SafeAllocaFreeToHeap;
      return;
    }
    if (7 < g_ulAdditionalProbeSize + 8) {
      g_pfnAllocate = MSCryptAlloc;
      g_pfnFree = SafeAllocaFreeToHeap;
      return;
    }
  }
  g_ulAdditionalProbeSize = 0xfffffffffffffff7;
  g_pfnAllocate = MSCryptAlloc;
  g_pfnFree = SafeAllocaFreeToHeap;
  return;
}



===== McGenEventRegister_EventRegister @ 180009f6c =====

void McGenEventRegister_EventRegister(void)

{
  if (ETW_LOG_NCRYPT_PROVIDER_Context == 0) {
                    /* WARNING: Could not recover jumptable at 0x000180009f91. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    EventRegister((LPCGUID)&ETW_LOG_NCRYPT_PROVIDER,McGenControlCallbackV2,
                  &ETW_LOG_NCRYPT_PROVIDER_Context,(PREGHANDLE)&ETW_LOG_NCRYPT_PROVIDER_Context);
    return;
  }
  return;
}



===== MSCryptInitializeMemoryLists @ 180009fa4 =====

void MSCryptInitializeMemoryLists(void)

{
  undefined *puVar1;
  int iVar2;
  undefined **ppuVar3;
  longlong lVar4;
  
  ppuVar3 = &g_rgKSPBuffes;
  lVar4 = 3;
  do {
    puVar1 = *ppuVar3;
    ppuVar3 = ppuVar3 + 1;
    *(undefined **)(puVar1 + 8) = puVar1;
    *(undefined **)puVar1 = puVar1;
    lVar4 = lVar4 + -1;
  } while (lVar4 != 0);
  iVar2 = RtlInitializeCriticalSection(&DAT_180027d20);
  if (-1 < iVar2) {
    DAT_180027b40 = 1;
  }
  return;
}



===== CNG_FreeProtectionDescriptor @ 180009ff8 =====

undefined8 CNG_FreeProtectionDescriptor(uint *param_1,undefined8 param_2,undefined *param_3)

{
  int *piVar1;
  longlong lVar2;
  ulonglong uVar3;
  longlong lVar4;
  longlong lVar5;
  ulonglong uVar6;
  
  uVar3 = 0;
  if (*param_1 != 0) {
    lVar5 = 0;
    do {
      lVar2 = *(longlong *)(param_1 + 2);
      uVar6 = 0;
      if (*(int *)(lVar5 + lVar2) != 0) {
        lVar4 = 0;
        do {
          lVar2 = *(longlong *)(lVar5 + 8 + lVar2);
          if ((*(int *)(lVar2 + 0x18 + lVar4) == 1) &&
             (piVar1 = *(int **)(lVar2 + 0x10 + lVar4), piVar1 != (int *)0x0)) {
            NCryptCloseKeyProtector(piVar1,param_2,param_3);
            *(undefined4 *)(*(longlong *)(lVar5 + 8 + *(longlong *)(param_1 + 2)) + 0x18 + lVar4) =
                 0;
            *(undefined8 *)(*(longlong *)(lVar5 + 8 + *(longlong *)(param_1 + 2)) + 0x10 + lVar4) =
                 0;
          }
          lVar2 = *(longlong *)(param_1 + 2);
          uVar6 = uVar6 + 1;
          lVar4 = lVar4 + 0x20;
        } while (uVar6 < *(uint *)(lVar5 + lVar2));
      }
      uVar3 = uVar3 + 1;
      lVar5 = lVar5 + 0x20;
    } while (uVar3 < *param_1);
  }
  SafeAllocaFreeToHeap(param_1);
  return 0;
}



===== InitializeLoader @ 18000a0b0 =====

ulonglong InitializeLoader(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  ulonglong uVar1;
  ulonglong uVar2;
  
  uVar2 = 0;
  if (g_fLoaderInitialized == 0) {
    g_pLoadedProviderList = 0;
    uVar1 = _InitializeLoaderLock();
    uVar2 = uVar1 & 0xffffffff;
    if ((int)uVar1 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
        WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),param_2,param_3,"sResult",(char)uVar1
                    ,"onecore\\ds\\security\\cryptoapi\\ncrypt\\loader\\loader.c",0xac);
      }
    }
    else {
      g_fLoaderInitialized = 1;
    }
  }
  return uVar2;
}



===== NCryptFreeBuffer @ 18000a130 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

SECURITY_STATUS __stdcall NCryptFreeBuffer(PVOID pvInput)

{
  longlong lVar1;
  SECURITY_STATUS SVar2;
  longlong *plVar3;
  
                    /* 0xa130  81  NCryptFreeBuffer */
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x15,
             &WPP_7a4fecd660bc33d31f6cd64b40025006_Traceguids,pvInput);
  }
  plVar3 = MSCryptRemoveMemoryBuffer(&KspRouterBufferList,(longlong)pvInput);
  SVar2 = 0;
  if (plVar3 != (longlong *)0x0) {
    lVar1 = *plVar3;
    SVar2 = (**(code **)(lVar1 + 0x70))(pvInput);
    DereferenceProvider(lVar1);
    pvInput = plVar3;
  }
  SafeAllocaFreeToHeap(pvInput);
  return SVar2;
}



===== MSCryptRemoveMemoryBuffer @ 18000a1e0 =====

undefined8 * MSCryptRemoveMemoryBuffer(undefined8 *param_1,longlong param_2)

{
  longlong *plVar1;
  code *pcVar2;
  bool bVar3;
  longlong *plVar4;
  undefined8 *puVar5;
  longlong *plVar6;
  longlong *plVar7;
  
  plVar7 = (longlong *)0x0;
  bVar3 = false;
  RtlEnterCriticalSection(&DAT_180027d20);
  plVar6 = (longlong *)*param_1;
  do {
    plVar4 = plVar6;
    if (plVar4 == param_1) goto LAB_18000a224;
    plVar7 = plVar4 + -2;
    plVar6 = (longlong *)*plVar4;
  } while (plVar4[-1] != param_2);
  if (((longlong *)plVar6[1] != plVar4) ||
     (plVar1 = (longlong *)plVar4[1], (longlong *)*plVar1 != plVar4)) {
    pcVar2 = (code *)swi(0x29);
    (*pcVar2)(3);
    pcVar2 = (code *)swi(3);
    puVar5 = (undefined8 *)(*pcVar2)();
    return puVar5;
  }
  *plVar1 = (longlong)plVar6;
  bVar3 = true;
  plVar6[1] = (longlong)plVar1;
LAB_18000a224:
  RtlLeaveCriticalSection(&DAT_180027d20);
  plVar6 = (longlong *)0x0;
  if (bVar3) {
    plVar6 = plVar7;
  }
  return plVar6;
}



===== _InitializeLoaderLock @ 18000a294 =====

undefined8 _InitializeLoaderLock(void)

{
  InitializeCriticalSection((LPCRITICAL_SECTION)&g_csLoaderLock);
  return 0;
}



===== UninitializeCNGNcrypt @ 18000a2e0 =====

void UninitializeCNGNcrypt(undefined8 param_1,undefined8 param_2,undefined *param_3)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)DAT_1800278b0;
  if ((DAT_1800278b0 & 4) != 0) {
    if (DAT_180027cb8 != 0) {
      KeyProtRouter_CleanupSettings(uVar1,param_2,param_3);
      RtlDeleteCriticalSection(&g_csKeyProtectorLock);
      DAT_180027cb8 = 0;
    }
    DAT_1800278b0 = DAT_1800278b0 & 0xfffffffb;
    uVar1 = (ulonglong)DAT_1800278b0;
  }
  if ((uVar1 & 2) != 0) {
    UninitializeLoader(uVar1,param_2,param_3);
    DAT_1800278b0 = DAT_1800278b0 & 0xfffffffd;
  }
  CNG_CleanupBCryptProvCache();
  if ((DAT_1800278b0 & 1) != 0) {
    if (DAT_180027b40 != 0) {
      RtlDeleteCriticalSection(&DAT_180027d20);
      DAT_180027b40 = 0;
    }
    DAT_1800278b0 = DAT_1800278b0 & 0xfffffffe;
  }
  CertInUseCleanup();
  return;
}



===== CNG_CleanupBCryptProvCache @ 18000a38c =====

void CNG_CleanupBCryptProvCache(void)

{
  undefined8 *puVar1;
  longlong lVar2;
  
  puVar1 = &DAT_180027b50;
  lVar2 = 0x2c;
  do {
    if ((BCRYPT_ALG_HANDLE)*puVar1 != (BCRYPT_ALG_HANDLE)0x0) {
      BCryptCloseAlgorithmProvider((BCRYPT_ALG_HANDLE)*puVar1,0);
      *puVar1 = 0;
    }
    puVar1 = puVar1 + 1;
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  return;
}



===== UninitializeLoader @ 18000a3dc =====

void UninitializeLoader(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  if (g_fLoaderInitialized == 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),&WPP_GLOBAL_Control,param_3,"NTE_FAIL",
                  0x20,"onecore\\ds\\security\\cryptoapi\\ncrypt\\loader\\loader.c",0xc3);
    }
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)&g_csLoaderLock);
    LeaveCriticalSection((LPCRITICAL_SECTION)&g_csLoaderLock);
    if (g_pLoadedProviderList != (undefined8 *)0x0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((WPP_GLOBAL_Control[0x1c] & 2) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x10));
      }
      while (g_pLoadedProviderList != (undefined8 *)0x0) {
        UnloadProvider(g_pLoadedProviderList);
      }
    }
    DeleteCriticalSection((LPCRITICAL_SECTION)&g_csLoaderLock);
    g_fLoaderInitialized = 0;
  }
  return;
}



===== TraceLoggingRegisterEx_EventRegister_EventSetInformation @ 18000a4c4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ULONG TraceLoggingRegisterEx_EventRegister_EventSetInformation(void)

{
  undefined2 uVar1;
  code *pcVar2;
  ULONG UVar3;
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
  local_28 = *(undefined4 *)(PTR_DAT_180027098 + -0x10);
  uStack_24 = *(undefined4 *)(PTR_DAT_180027098 + -0xc);
  uStack_20 = *(undefined4 *)(PTR_DAT_180027098 + -8);
  uStack_1c = *(undefined4 *)(PTR_DAT_180027098 + -4);
  if (DAT_1800270b0 != 0) {
    pcVar2 = (code *)swi(0x29);
    (*pcVar2)(5);
    puVar4 = auStack_40;
  }
  _DAT_1800270b8 = 0;
  uRam00000001800270c0 = 0;
  *(undefined8 *)(puVar4 + -8) = 0x18000a520;
  UVar3 = EventRegister((LPCGUID)(puVar4 + 0x20),_tlgEnableCallback,&DAT_180027090,
                        (PREGHANDLE)&DAT_1800270b0);
  if (UVar3 == 0) {
    uVar1 = *(undefined2 *)PTR_DAT_180027098;
    *(undefined8 *)(puVar4 + -8) = 0x18000a547;
    EventSetInformation(DAT_1800270b0,2,PTR_DAT_180027098,uVar1);
  }
  else if (0 < (int)UVar3) {
    UVar3 = UVar3 & 0xffff | 0x80070000;
  }
  *(undefined8 *)(puVar4 + -8) = 0x18000a55b;
  return UVar3;
}



===== NCryptUnprotectSecret @ 18000a590 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

uint NCryptUnprotectSecret
               (undefined8 *param_1,uint *param_2,char *param_3,uint param_4,int *param_5,
               undefined8 param_6,undefined8 *param_7,ULONG *param_8)

{
  int *piVar1;
  uint uVar2;
  ulonglong uVar3;
  wchar_t *pwVar4;
  undefined *puVar5;
  char *pcVar6;
  int *piVar7;
  PUCHAR pUVar8;
  PUCHAR pUVar9;
  int *piVar10;
  undefined1 uVar11;
  uint local_58 [2];
  int *local_50;
  PUCHAR local_48 [2];
  
                    /* 0xa590  108  NCryptUnprotectSecret */
  pUVar9 = (PUCHAR)0x0;
  local_58[0] = 0;
  piVar10 = (int *)0x0;
  local_50 = (int *)0x0;
  local_48[0] = (PUCHAR)0x0;
  pcVar6 = (char *)param_2;
  if ((((param_3 == (char *)0x0) || (param_4 == 0)) || (param_7 == (undefined8 *)0x0)) ||
     (param_8 == (ULONG *)0x0)) {
    uVar2 = 0x80090027;
    puVar5 = WPP_GLOBAL_Control;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      uVar11 = 0x5d;
      uVar2 = 0x80090027;
LAB_18000a743:
      puVar5 = *(undefined **)(WPP_GLOBAL_Control + 0x10);
      WPP_SF_sDsd(puVar5,pcVar6,param_3,"Status",(char)uVar2,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\ncryptprotect.c"
                  ,uVar11);
    }
  }
  else {
    if (param_1 != (undefined8 *)0x0) {
      *param_1 = 0;
    }
    *param_7 = 0;
    *param_8 = 0;
    if (((ulonglong)param_2 & 0xffffffbe) == 0) {
      piVar7 = (int *)&NCryptDefaultAllocPara;
      if (param_5 != (int *)0x0) {
        piVar7 = param_5;
      }
      pUVar8 = (PUCHAR)param_3;
      uVar2 = I_OpenProtectedMessage
                        (&local_50,(uint)param_2,param_3,param_4,piVar7,param_6,local_48,local_58);
      pUVar9 = local_48[0];
      piVar1 = local_50;
      param_5 = piVar7;
      if (uVar2 == 0) {
        if (((ulonglong)param_2 & 1) != 0) {
          *param_1 = local_50;
LAB_18000a6cd:
          uVar2 = 0;
          param_3 = (char *)pUVar8;
          goto LAB_18000a6cf;
        }
        pcVar6 = (char *)(*(longlong *)(local_50 + 8) + 0x48);
        pUVar8 = local_48[0];
        uVar3 = CMSG_ImportContentEncryptionKey
                          (*(longlong *)(local_50 + 6),(uint *)pcVar6,local_48[0],local_58[0]);
        uVar2 = (uint)uVar3;
        puVar5 = WPP_GLOBAL_Control;
        piVar10 = piVar1;
        if (uVar2 != 0) {
          param_3 = (char *)pUVar8;
          if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
             ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_18000a753;
          uVar11 = 0xa1;
LAB_18000a733:
          param_3 = (char *)pUVar8;
          goto LAB_18000a743;
        }
        pcVar6 = *(char **)(piVar1 + 8);
        uVar2 = *(uint *)((longlong)pcVar6 + 0x70);
        if (uVar2 == 0) {
          piVar7 = *(int **)(piVar1 + 6);
          if ((piVar7 == (int *)0x0) || (*piVar7 != 0x170)) {
            uVar2 = 0x80090026;
            param_3 = (char *)pUVar8;
            if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
              if ((WPP_GLOBAL_Control[0x1c] & 1) != 0) {
                WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),pcVar6,pUVar8,"Status",0x26,
                            "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptcms\\ncryptcms.c"
                            ,0x60);
              }
              puVar5 = WPP_GLOBAL_Control;
              param_3 = (char *)pUVar8;
              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
                uVar11 = 0xb6;
                uVar2 = 0x80090026;
                goto LAB_18000a743;
              }
            }
          }
          else {
            uVar2 = piVar7[0xc];
            if (uVar2 <= param_4) {
              pcVar6 = param_3 + uVar2;
              uVar2 = param_4 - uVar2;
              goto LAB_18000a6a6;
            }
            param_3 = 
            "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\ncryptprotect.c";
            pcVar6 = "Status";
            puVar5 = (undefined *)0x80090005;
            uVar2 = 0x80090005;
            DebugTraceError(5,"Status",
                            "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\ncryptprotect.c"
                            ,0xbd);
          }
        }
        else {
          pcVar6 = *(char **)((longlong)pcVar6 + 0x78);
LAB_18000a6a6:
          pUVar8 = (PUCHAR)(ulonglong)uVar2;
          uVar2 = CMSG_DecryptAndAllocate
                            (*(longlong *)(piVar1 + 6),(PUCHAR)pcVar6,pUVar8,param_7,param_8);
          if (uVar2 == 0) {
            if (param_1 != (undefined8 *)0x0) {
              *param_1 = piVar1;
              piVar10 = (int *)0x0;
            }
            goto LAB_18000a6cd;
          }
          puVar5 = WPP_GLOBAL_Control;
          param_3 = (char *)pUVar8;
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
            uVar11 = 0xd3;
            goto LAB_18000a733;
          }
        }
      }
      else {
        param_3 = 
        "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\ncryptprotect.c";
        pcVar6 = "Status";
        puVar5 = (undefined *)(ulonglong)uVar2;
        DebugTraceError((char)uVar2,"Status",
                        "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\ncryptprotect.c"
                        ,0x88);
        pUVar9 = local_48[0];
        piVar10 = local_50;
      }
    }
    else {
      uVar2 = 0x80090009;
      puVar5 = WPP_GLOBAL_Control;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
        uVar11 = 0x6f;
        uVar2 = 0x80090009;
        goto LAB_18000a743;
      }
    }
  }
LAB_18000a753:
  if ((Microsoft_Windows_Crypto_NCryptEnableBits & 2) != 0) {
    pwVar4 = I_GetProcessName();
    param_3 = (char *)((ulonglong)param_2 & 0xffffffff);
    pcVar6 = &ETW_LOG_NCRYPT_UNPROTECT_SECRET_FAILED;
    McTemplateU0ddz_EventWriteTransfer
              (puVar5,(PCEVENT_DESCRIPTOR)&ETW_LOG_NCRYPT_UNPROTECT_SECRET_FAILED,(uint)param_2,
               uVar2,pwVar4);
  }
LAB_18000a6cf:
  if (pUVar9 != (PUCHAR)0x0) {
    pUVar8 = pUVar9;
    for (uVar3 = (ulonglong)local_58[0]; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pUVar8 = '\0';
      pUVar8 = pUVar8 + 1;
    }
    (**(code **)(param_5 + 4))(pUVar9);
  }
  if (piVar10 != (int *)0x0) {
    NCryptCloseProtectionDescriptor(piVar10,pcVar6,param_3);
  }
  return uVar2;
}



===== NCryptCloseProtectionDescriptor @ 18000a960 =====

undefined8 NCryptCloseProtectionDescriptor(int *param_1,undefined8 param_2,undefined *param_3)

{
  undefined8 uVar1;
  
                    /* 0xa960  65  NCryptCloseProtectionDescriptor */
  uVar1 = 0;
  if ((param_1 == (int *)0x0) || (*param_1 != 0x28)) {
    uVar1 = 0x80090026;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),param_2,param_3,"Status",0x26,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\ncryptprotect.c"
                  ,0x99);
    }
  }
  else {
    if (*(uint **)(param_1 + 2) != (uint *)0x0) {
      CNG_FreeProtectionDescriptor(*(uint **)(param_1 + 2),param_2,param_3);
    }
    if (*(int **)(param_1 + 6) != (int *)0x0) {
      NCryptMsgClose(*(int **)(param_1 + 6),param_2,param_3);
    }
    SafeAllocaFreeToHeap(param_1);
  }
  return uVar1;
}



===== I_OpenProtectedMessage @ 18000aa00 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

HRESULT I_OpenProtectedMessage
                  (undefined8 *param_1,uint param_2,undefined8 param_3,undefined4 param_4,
                  int *param_5,undefined8 param_6,undefined8 *param_7,uint *param_8)

{
  HRESULT HVar1;
  ulonglong uVar2;
  undefined **ppuVar3;
  int *piVar4;
  undefined **ppuVar5;
  int *piVar6;
  uint local_res8 [2];
  int *local_38;
  undefined **local_30;
  
  local_38 = (int *)0x0;
  local_30 = (undefined **)0x0;
  local_res8[0] = 0;
  *param_1 = 0;
  *param_7 = 0;
  *param_8 = 0;
  piVar6 = param_5;
  HVar1 = I_GetProtectionDescriptor(param_3,param_4,param_5,&local_38);
  piVar4 = local_38;
  if (HVar1 != 0) {
    ppuVar3 = &WPP_GLOBAL_Control;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),&WPP_GLOBAL_Control,piVar6,"Status",
                  (char)HVar1,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\ncryptprotect.c"
                  ,0x9b);
    }
    piVar4 = local_38;
    goto LAB_18000aac8;
  }
  ppuVar3 = (undefined **)0x0;
  if ((param_2 & 1) == 0) {
    piVar6 = param_5;
    HVar1 = I_GetContentEncryptKey
                      ((longlong)local_38,param_2,(undefined *)param_5,param_6,&local_30,local_res8)
    ;
    if (HVar1 == 0) {
      ppuVar3 = local_30;
      goto LAB_18000aaa7;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),&WPP_GLOBAL_Control,piVar6,"Status",
                  (char)HVar1,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\ncryptprotect.c"
                  ,0xaa);
    }
    ppuVar3 = local_30;
  }
  else {
LAB_18000aaa7:
    *param_1 = piVar4;
    piVar4 = (int *)0x0;
    *param_7 = ppuVar3;
    *param_8 = local_res8[0];
    ppuVar3 = (undefined **)0x0;
  }
  if (ppuVar3 != (undefined **)0x0) {
    ppuVar5 = ppuVar3;
    for (uVar2 = (ulonglong)local_res8[0]; uVar2 != 0; uVar2 = uVar2 - 1) {
      *(undefined1 *)ppuVar5 = 0;
      ppuVar5 = (undefined **)((longlong)ppuVar5 + 1);
    }
    (**(code **)(param_5 + 4))(ppuVar3);
  }
LAB_18000aac8:
  if (piVar4 != (int *)0x0) {
    NCryptCloseProtectionDescriptor(piVar4,ppuVar3,(undefined *)piVar6);
  }
  return HVar1;
}



===== CMSG_ImportContentEncryptionKey @ 18000abb4 =====

ulonglong CMSG_ImportContentEncryptionKey
                    (longlong param_1,uint *param_2,PUCHAR param_3,uint param_4)

{
  ulonglong uVar1;
  ulonglong uVar2;
  
  uVar2 = (ulonglong)param_4;
  uVar1 = CNG_ImportCEKBCryptKeyAndAlgorithmInfo
                    (param_2,param_3,param_4,param_1 + 0x10,(longlong *)(param_1 + 0x58));
  if ((((int)uVar1 != 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
     ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
    WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),param_3,uVar2,"Status",(char)uVar1,
                "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptcms\\cmsg.c",0x19);
  }
  return uVar1 & 0xffffffff;
}



===== WPP_SF_PSDD @ 18000ac38 =====

void WPP_SF_PSDD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                wchar_t *param_5,undefined1 param_6,undefined1 param_7)

{
  longlong lVar1;
  undefined8 local_res20;
  
  if (param_5 == (wchar_t *)0x0) {
    lVar1 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_5[lVar1] != L'\0');
    lVar1 = lVar1 * 2 + 2;
  }
  if (param_5 == (wchar_t *)0x0) {
    param_5 = L"NULL";
  }
  local_res20 = param_4;
  TraceMessage(param_1,0x2b,&WPP_7a4fecd660bc33d31f6cd64b40025006_Traceguids,0xe,&local_res20,8,
               param_5,lVar1,&param_6,4,&param_7,4,0);
  return;
}



===== CMSG_DecryptAndAllocate @ 18000acfc =====

NTSTATUS CMSG_DecryptAndAllocate
                   (longlong param_1,PUCHAR param_2,undefined8 param_3,undefined8 *param_4,
                   ULONG *param_5)

{
  NTSTATUS NVar1;
  
  NVar1 = CNG_DecryptAndAllocate
                    ((longlong *)(param_1 + 0x58),param_2,(ULONG)param_3,param_4,param_5);
  if (NVar1 == 0) {
    NVar1 = 0;
  }
  else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
    WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),param_2,param_3,"Status",(char)NVar1,
                "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptcms\\cmsg.c",0x3f);
  }
  return NVar1;
}



===== I_GetProtectionDescriptor @ 18000ad70 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

HRESULT I_GetProtectionDescriptor
                  (undefined8 param_1,undefined4 param_2,int *param_3,undefined8 *param_4)

{
  undefined8 uVar1;
  HRESULT HVar2;
  int iVar3;
  int *_Dst;
  char *pcVar4;
  longlong lVar5;
  char *_Size;
  int *piVar6;
  ulonglong uVar7;
  int *local_res20;
  undefined1 uVar8;
  undefined1 uVar9;
  
  *param_4 = 0;
  pcVar4 = "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptcms\\ncryptcms.c";
  piVar6 = (int *)0x0;
  local_res20 = (int *)0x0;
  if ((param_3 == (int *)0x0) || (*param_3 != 0x18)) {
    HVar2 = -0x7ff6ffd9;
    _Size = (char *)param_3;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptcms\\ncryptcms.c",
                  param_3,"Status",0x27,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptcms\\ncryptcms.c",0xd4);
      goto LAB_18000afbe;
    }
LAB_18000b1b5:
    _Dst = (int *)0x0;
    if (HVar2 == 0) {
LAB_18000b1bf:
      HVar2 = -0x7ff6ffda;
      if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
        if ((WPP_GLOBAL_Control[0x1c] & 1) != 0) {
          WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),pcVar4,_Size,"Status",0x26,
                      "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptcms\\ncryptcms.c",
                      0x60);
        }
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
          WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),pcVar4,_Size,"Status",0x26,
                      "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\ncryptprotect.c"
                      ,0x89);
        }
      }
    }
    else {
LAB_18000afbe:
      _Size = "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\ncryptprotect.c";
      pcVar4 = "Status";
      DebugTraceError((char)HVar2,"Status",
                      "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\ncryptprotect.c"
                      ,0x7c);
      _Dst = (int *)0x0;
    }
    if (_Dst == (int *)0x0) goto LAB_18000afde;
  }
  else {
    _Dst = (int *)(**(code **)(param_3 + 2))(0x170);
    if (_Dst == (int *)0x0) {
      HVar2 = -0x7ff6fff2;
      DebugTraceError(0xe,"Status",
                      "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptcms\\ncryptcms.c",
                      0xe1);
      goto LAB_18000afbe;
    }
    memset(_Dst,0,0x170);
    uVar1 = ASN1_NCRYPT_MODULE_HANDLE;
    _Dst[4] = 0x18;
    _Size = (char *)0x5;
    *_Dst = 0x170;
    pcVar4 = (char *)0x14;
    *(undefined8 *)(_Dst + 6) = *(undefined8 *)(param_3 + 2);
    *(undefined8 *)(_Dst + 8) = *(undefined8 *)(param_3 + 4);
    _Dst[2] = 1;
    HVar2 = Ordinal_4(uVar1,0x14,5,param_1,param_2,_Dst + 0xc,_Dst + 4,_Dst + 0xe);
    if (HVar2 != 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
        uVar8 = 3;
LAB_18000b191:
        uVar9 = (undefined1)HVar2;
LAB_18000b19a:
        WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),pcVar4,_Size,"Status",uVar9,
                    "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptcms\\ncryptcms.c",
                    uVar8);
      }
LAB_18000b1a6:
      I_CMsgFree((longlong)_Dst);
      goto LAB_18000b1b5;
    }
    lVar5 = 0;
    for (uVar7 = 0; uVar7 < 0x20; uVar7 = uVar7 + 0x20) {
      if (*(uint *)((longlong)&DAT_18001f1d8 + uVar7) == **(uint **)(_Dst + 0xe)) {
        _Size = (char *)(ulonglong)*(uint *)((longlong)&DAT_18001f1d8 + uVar7);
        iVar3 = memcmp(*(void **)(*(uint **)(_Dst + 0xe) + 2),
                       *(void **)((longlong)&PTR_DAT_18001f1e0 + uVar7),(size_t)_Size);
        if (iVar3 == 0) {
          *(undefined ***)(_Dst + 0x10) = &PTR_s_1_2_840_113549_1_7_3_18001f1d0 + lVar5 * 4;
          break;
        }
      }
      lVar5 = lVar5 + 1;
    }
    if (*(longlong *)(_Dst + 0x10) == 0) {
      HVar2 = -0x7ff6ffd7;
      pcVar4 = (char *)0x0;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
        uVar8 = 0x1a;
        uVar9 = 0x29;
        goto LAB_18000b19a;
      }
      goto LAB_18000b1a6;
    }
    pcVar4 = (char *)(ulonglong)*(uint *)(*(longlong *)(_Dst + 0x10) + 0x18);
    _Size = (char *)0x5;
    HVar2 = Ordinal_4(ASN1_NCRYPT_MODULE_HANDLE,pcVar4,5,
                      *(undefined8 *)(*(longlong *)(_Dst + 0xe) + 0x18),
                      *(undefined4 *)(*(longlong *)(_Dst + 0xe) + 0x10),0,_Dst + 4,_Dst + 0x34);
    if (HVar2 != 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
        uVar8 = 0x2a;
        goto LAB_18000b191;
      }
      goto LAB_18000b1a6;
    }
    if (*_Dst != 0x170) goto LAB_18000b1bf;
    if (*(longlong *)(_Dst + 0x10) == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(*(longlong *)(_Dst + 0x10) + 0x1c);
    }
    if (iVar3 == 3) {
      if (*_Dst == 0x170) {
        lVar5 = *(longlong *)(_Dst + 0x34);
        pcVar4 = (char *)&local_res20;
        HVar2 = CNG_GetDescriptorFromMessage(lVar5,(undefined8 *)pcVar4);
        if (HVar2 == 0) {
          if (local_res20 != (int *)0x0) {
            *(longlong *)(local_res20 + 8) = lVar5;
            *(int **)(local_res20 + 6) = _Dst;
            *param_4 = local_res20;
            piVar6 = (int *)0x0;
            goto LAB_18000afde;
          }
          HVar2 = -0x7ff6fff6;
          piVar6 = local_res20;
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
            uVar9 = 0xb6;
            uVar8 = 10;
            goto LAB_18000b0c5;
          }
        }
        else {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
            WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),pcVar4,_Size,"Status",(char)HVar2
                        ,
                        "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\ncryptprotect.c"
                        ,0xab);
          }
          piVar6 = local_res20;
        }
      }
      else {
        HVar2 = -0x7ff6ffda;
        if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
          if ((WPP_GLOBAL_Control[0x1c] & 1) != 0) {
            WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),pcVar4,_Size,"Status",0x26,
                        "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptcms\\ncryptcms.c",
                        0x60);
          }
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
            uVar9 = 0x9d;
            uVar8 = 0x26;
            goto LAB_18000b0c5;
          }
        }
      }
    }
    else {
      HVar2 = -0x7ff6fffb;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
        uVar9 = 0x90;
        uVar8 = 5;
LAB_18000b0c5:
        WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),pcVar4,_Size,"Status",uVar8,
                    "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\ncryptprotect.c"
                    ,uVar9);
      }
    }
  }
  NCryptMsgClose(_Dst,pcVar4,_Size);
LAB_18000afde:
  if (piVar6 != (int *)0x0) {
    NCryptCloseProtectionDescriptor(piVar6,pcVar4,_Size);
  }
  return HVar2;
}



===== NCryptMsgClose @ 18000b338 =====

undefined8 NCryptMsgClose(int *param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if ((param_1 == (int *)0x0) || (*param_1 != 0x170)) {
    uVar1 = 0x80090026;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),param_2,param_3,"Status",0x26,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptcms\\ncryptcms.c",0x9f);
    }
  }
  else {
    I_CMsgFree((longlong)param_1);
  }
  return uVar1;
}



===== CNG_GetDescriptorFromMessage @ 18000b3b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

HRESULT CNG_GetDescriptorFromMessage(longlong param_1,undefined8 *param_2)

{
  ulonglong *puVar1;
  undefined8 *puVar2;
  longlong lVar3;
  undefined8 uVar4;
  longlong lVar5;
  HRESULT HVar6;
  ulonglong uVar7;
  char *pcVar8;
  ulonglong uVar9;
  uint uVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  char *pcVar13;
  undefined1 auStackY_1c8 [32];
  ulonglong local_198;
  undefined8 *local_190;
  ulonglong local_188 [8];
  undefined8 local_148 [2];
  int aiStack_138 [2];
  longlong alStack_130 [29];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_1c8;
  local_198 = 0;
  memset(local_188,0,0x40);
  pcVar8 = (char *)0x0;
  pcVar13 = (char *)0x100;
  memset(local_148,0,0x100);
  uVar11 = 0;
  local_190 = local_148;
  *param_2 = 0;
  uVar9 = 0;
  local_198 = local_198 & 0xffffffff00000000;
  uVar12 = uVar11;
  if (*(int *)(param_1 + 0x28) != 0) {
    do {
      uVar11 = uVar12;
      if (7 < (uint)uVar12) break;
      puVar1 = local_188 + uVar12;
      pcVar8 = (char *)puVar1;
      uVar7 = I_GetDescriptorFromRecipientInfo
                        ((int *)(*(longlong *)(param_1 + 0x30) + uVar9 * 0xa0),puVar1);
      if ((int)uVar7 == 0) {
        puVar2 = *(undefined8 **)(*puVar1 + 8);
        uVar4 = puVar2[1];
        local_148[uVar12 * 4] = *puVar2;
        local_148[uVar12 * 4 + 1] = uVar4;
        lVar5 = puVar2[3];
        lVar3 = *(longlong *)(param_1 + 0x30);
        *(undefined8 *)(aiStack_138 + uVar12 * 8) = puVar2[2];
        alStack_130[uVar12 * 4] = lVar5;
        uVar10 = (uint)uVar12 + 1;
        uVar11 = (ulonglong)uVar10;
        aiStack_138[uVar12 * 8] = (int)uVar9;
        local_198 = CONCAT44(local_198._4_4_,uVar10);
        alStack_130[uVar12 * 4] = lVar3 + uVar9 * 0xa0;
      }
      uVar10 = (int)uVar9 + 1;
      uVar9 = (ulonglong)uVar10;
      uVar12 = uVar11;
    } while (uVar10 < *(uint *)(param_1 + 0x28));
    if ((int)uVar11 != 0) {
      pcVar8 = (char *)&local_198;
      pcVar13 = (char *)0x1;
      HVar6 = I_CreateProtectionDescriptor
                        ((STRSAFE_LPCWSTR)0x0,(uint *)pcVar8,(char *)0x1,0,param_2);
      if (HVar6 != 0) {
        pcVar13 = "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\descriptor.c";
        pcVar8 = "Status";
        DebugTraceError((char)HVar6,"Status",
                        "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\descriptor.c"
                        ,0x23);
        goto LAB_18000b4cc;
      }
    }
  }
  HVar6 = 0;
LAB_18000b4cc:
  while ((int)uVar11 != 0) {
    uVar11 = (ulonglong)((int)uVar11 - 1);
    CNG_FreeProtectionDescriptor((uint *)local_188[uVar11],pcVar8,pcVar13);
  }
  return HVar6;
}



===== I_GetDescriptorFromRecipientInfo @ 18000b520 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong I_GetDescriptorFromRecipientInfo(int *param_1,undefined8 *param_2)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  undefined1 uVar4;
  int *piVar5;
  char *pcVar6;
  longlong lVar7;
  wchar_t *pwVar8;
  ulonglong uVar9;
  HLOCAL hMem;
  ulonglong uVar10;
  undefined8 uVar11;
  undefined1 uVar12;
  undefined1 auStackY_1c8 [32];
  HLOCAL local_188;
  HLOCAL local_180;
  int *local_178;
  int *local_170;
  uint local_168 [2];
  ulonglong *local_160;
  ulonglong local_158;
  undefined8 *local_150;
  undefined8 local_148;
  undefined4 local_140;
  undefined8 local_138 [32];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_1c8;
  local_168[0] = 1;
  local_168[1] = 0;
  local_180 = (HLOCAL)0x0;
  local_178 = (int *)0x0;
  pcVar6 = (char *)0x0;
  local_158 = 0;
  local_148 = 0;
  uVar10 = 0x100;
  local_140 = 0;
  memset(local_138,0,0x100);
  local_160 = &local_158;
  *param_2 = 0;
  local_150 = local_138;
  local_188 = (HLOCAL)0x0;
  iVar2 = *param_1;
  local_170 = (int *)0x0;
  if ((iVar2 == 1) || (iVar2 == 2)) {
    if (*param_1 == 1) {
      piVar5 = param_1 + 4;
    }
    else {
      if (param_1[0x24] != 1) {
        uVar12 = 0x6e;
LAB_18000b9b8:
        uVar9 = 0x80090029;
        uVar4 = 0x29;
LAB_18000b8fc:
        DebugTraceError(uVar4,"Status",
                        "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\descriptor.c"
                        ,uVar12);
        goto LAB_18000b762;
      }
      piVar5 = *(int **)(param_1 + 0x26);
    }
    uVar3 = I_GetRecipientIdString(piVar5,(ulonglong)pcVar6,&local_188);
    if (uVar3 == 0) {
      pwVar8 = L"CERTIFICATE";
LAB_18000ba4e:
      uVar10 = local_158 & 0xffffffff;
      local_158 = CONCAT44(local_158._4_4_,(int)local_158 + 1);
      local_138[uVar10 * 4] = pwVar8;
      local_138[uVar10 * 4 + 1] = local_188;
      hMem = local_188;
LAB_18000b6b7:
      uVar11 = 0;
      pcVar6 = CNG_DuplicateDescriptor(local_168,param_2,0);
      uVar9 = (ulonglong)pcVar6 & 0xffffffff;
      if ((int)pcVar6 == 0) {
        uVar9 = 0;
      }
      else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
        WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),param_2,uVar11,"Status",(char)pcVar6,
                    "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\descriptor.c"
                    ,0xd3);
      }
    }
    else {
      uVar12 = 0x7c;
LAB_18000b9ec:
      uVar9 = (ulonglong)uVar3;
      DebugTraceError((char)uVar3,"Status",
                      "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\descriptor.c"
                      ,uVar12);
      hMem = local_188;
    }
    if (hMem != (HLOCAL)0x0) {
      I_DefaultExtrenalFree(hMem);
    }
    goto LAB_18000b762;
  }
  if (iVar2 == 3) {
    puVar1 = *(uint **)(param_1 + 10);
    if ((puVar1 == (uint *)0x0) || (*puVar1 != 0xb)) {
LAB_18000b7e1:
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 0x80090029;
      }
      if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
        return 0x80090029;
      }
      uVar12 = 0x8e;
      goto LAB_18000b807;
    }
    uVar10 = (ulonglong)*puVar1;
    pcVar6 = s_________7J_;
    iVar2 = memcmp(*(void **)(puVar1 + 2),s_________7J_,uVar10);
    if (iVar2 != 0) goto LAB_18000b7e1;
    uVar10 = 0x200001;
    pcVar6 = (char *)0x1;
    uVar3 = Ordinal_4(ASN1_NCRYPT_MODULE_HANDLE,1,0x200001,*(undefined8 *)(puVar1 + 6));
    uVar9 = (ulonglong)uVar3;
    if (uVar3 == 0) {
      pcVar6 = (char *)0x1c;
      uVar10 = 1;
      uVar3 = Ordinal_4(ASN1_NCRYPT_MODULE_HANDLE,0x1c,1,*(undefined8 *)((longlong)local_180 + 0x18)
                       );
      uVar9 = (ulonglong)uVar3;
      if (uVar3 == 0) {
        if ((*local_178 != 1) || ((int)**(ulonglong **)(local_178 + 2) != 1)) {
          uVar9 = 0x80090029;
          if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
             ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_18000b762;
          uVar12 = 0xba;
          goto LAB_18000b807;
        }
        hMem = (HLOCAL)0x0;
        local_160 = *(ulonglong **)(local_178 + 2);
        goto LAB_18000b6b7;
      }
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_18000b762;
      uVar12 = 0xb2;
    }
    else {
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_18000b762;
      uVar12 = 0xa2;
    }
  }
  else {
    if (iVar2 == 5) {
      if (param_1[2] != 0xc) {
LAB_18000ba14:
        uVar12 = 0x5b;
        goto LAB_18000b9b8;
      }
      lVar7 = **(longlong **)(param_1 + 4) + 0x7dfefbfef9d4f5fa;
      if (lVar7 == 0) {
        lVar7 = (ulonglong)*(uint *)(*(longlong **)(param_1 + 4) + 1) - 0x4014a37;
      }
      if (lVar7 == 0) {
        uVar9 = I_GetDescriptorFromAndCombiner(param_1,0,param_2);
        uVar3 = (uint)uVar9;
        uVar9 = uVar9 & 0xffffffff;
        if (uVar3 == 0) goto LAB_18000b762;
        uVar12 = 0x16;
LAB_18000b8e8:
        uVar4 = (undefined1)uVar3;
        goto LAB_18000b8fc;
      }
      lVar7 = **(longlong **)(param_1 + 4) + 0x7dfefbfef9d4f5fa;
      if (lVar7 == 0) {
        lVar7 = (ulonglong)*(uint *)(*(longlong **)(param_1 + 4) + 1) - 0x9014a37;
      }
      if (lVar7 != 0) goto LAB_18000ba14;
      uVar10 = 0x16;
      uVar3 = Ordinal_4(ASN1_NCRYPT_MODULE_HANDLE,0x16,0x200000,*(undefined8 *)(param_1 + 8));
      uVar9 = (ulonglong)uVar3;
      if (uVar3 != 0) {
        uVar12 = 0x2f;
        goto LAB_18000b8e8;
      }
      if (*local_170 == 1) {
        piVar5 = local_170 + 4;
      }
      else {
        if (*local_170 != 2) {
          uVar9 = 0x80090005;
          uVar12 = 0x45;
          uVar4 = 5;
          goto LAB_18000b8fc;
        }
        if (local_170[0x24] != 1) {
          uVar12 = 0x3c;
          goto LAB_18000b9b8;
        }
        piVar5 = *(int **)(local_170 + 0x26);
      }
      uVar3 = I_GetRecipientIdString(piVar5,uVar10,&local_188);
      if (uVar3 == 0) {
        pwVar8 = L"DRACERTIFICATE";
        goto LAB_18000ba4e;
      }
      uVar12 = 0x50;
      goto LAB_18000b9ec;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0x80090029;
    }
    if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
      return 0x80090029;
    }
    uVar12 = 0xc6;
LAB_18000b807:
    uVar9 = 0x80090029;
  }
  WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),pcVar6,uVar10,"Status",(char)uVar9,
              "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\descriptor.c",
              uVar12);
LAB_18000b762:
  if (local_180 != (HLOCAL)0x0) {
    I_DefaultExtrenalFree(local_180);
  }
  if (local_178 != (int *)0x0) {
    I_DefaultExtrenalFree(local_178);
  }
  if (local_170 != (int *)0x0) {
    I_DefaultExtrenalFree(local_170);
  }
  return uVar9;
}



===== I_DefaultExtrenalFree @ 18000ba90 =====

HLOCAL __stdcall I_DefaultExtrenalFree(HLOCAL hMem)

{
  HLOCAL pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000ba90. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = LocalFree(hMem);
  return pvVar1;
}



===== CNG_DecryptAndAllocate @ 18000baa4 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

NTSTATUS CNG_DecryptAndAllocate
                   (longlong *param_1,PUCHAR param_2,ULONG param_3,undefined8 *param_4,
                   ULONG *param_5)

{
  longlong *plVar1;
  longlong lVar2;
  NTSTATUS NVar3;
  PUCHAR pbOutput;
  PUCHAR pUVar4;
  ULONG local_res8 [2];
  undefined1 uVar5;
  
  plVar1 = param_1 + 9;
  *param_4 = 0;
  local_res8[0] = 0;
  *param_5 = 0;
  if ((*(uint *)(param_1 + 0xe) & 0x10000000) != 0) {
    lVar2 = *plVar1;
    if (*(uint *)(param_1 + 8) < 0x98) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return -0x7ff6ffd3;
      }
      if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
        return -0x7ff6ffd3;
      }
      uVar5 = 0x27;
      NVar3 = -0x7ff6ffd3;
      goto LAB_18000bc31;
    }
    if (param_3 < *(uint *)(lVar2 + 0x30)) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return -0x7ff6fffb;
      }
      if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
        return -0x7ff6fffb;
      }
      uVar5 = 0x2e;
      NVar3 = -0x7ff6fffb;
      goto LAB_18000bc31;
    }
    param_3 = param_3 - *(int *)(lVar2 + 0x30);
    *(PUCHAR *)(lVar2 + 0x28) = param_2 + param_3;
  }
  pUVar4 = param_2;
  NVar3 = BCryptDecrypt((BCRYPT_KEY_HANDLE)param_1[2],param_2,param_3,(void *)*plVar1,(PUCHAR)0x0,0,
                        (PUCHAR)0x0,0,local_res8,*(ULONG *)(param_1[3] + 0x48));
  if (NVar3 == 0) {
    pbOutput = (PUCHAR)(**(code **)(*param_1 + 8))(local_res8[0]);
    if (pbOutput != (PUCHAR)0x0) {
      NVar3 = BCryptDecrypt((BCRYPT_KEY_HANDLE)param_1[2],param_2,param_3,(void *)*plVar1,
                            (PUCHAR)0x0,0,pbOutput,local_res8[0],local_res8,
                            *(ULONG *)(param_1[3] + 0x48));
      if (NVar3 == 0) {
        *param_4 = pbOutput;
        *param_5 = local_res8[0];
        return 0;
      }
      DebugTraceError((char)NVar3,"Status",
                      "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptcms\\util.c",0x62);
      (**(code **)(*param_1 + 0x10))(pbOutput);
      return NVar3;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x7ff6fff2;
    }
    if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
      return -0x7ff6fff2;
    }
    uVar5 = 0x50;
    NVar3 = -0x7ff6fff2;
    param_2 = pUVar4;
  }
  else {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return NVar3;
    }
    if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
      return NVar3;
    }
    uVar5 = 0x48;
    param_2 = pUVar4;
  }
LAB_18000bc31:
  WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),param_2,
              "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptcms\\util.c","Status",
              (char)NVar3,"onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptcms\\util.c",
              uVar5);
  return NVar3;
}



===== CNG_ImportCEKBCryptKeyAndAlgorithmInfo @ 18000bd48 =====

ulonglong CNG_ImportCEKBCryptKeyAndAlgorithmInfo
                    (uint *param_1,PUCHAR param_2,ULONG param_3,longlong param_4,longlong *param_5)

{
  uint uVar1;
  ulonglong uVar2;
  BCRYPT_KEY_HANDLE *phKey;
  ulonglong uVar3;
  undefined1 uVar4;
  
  memset(param_5 + 1,0,0x70);
  *param_5 = param_4;
  phKey = (BCRYPT_KEY_HANDLE *)(ulonglong)*param_1;
  uVar2 = CNG_FindBCryptOidInfo(*(undefined8 *)(param_1 + 2),*param_1,1,param_5 + 3);
  uVar3 = uVar2 & 0xffffffff;
  if ((int)uVar2 == 0) {
    phKey = (BCRYPT_KEY_HANDLE *)(param_5 + 1);
    uVar1 = CNG_GetBCryptHandle(*(ushort **)(param_5[3] + 8),phKey);
    uVar3 = (ulonglong)uVar1;
    if (uVar1 == 0) {
      phKey = (BCRYPT_KEY_HANDLE *)(param_5 + 2);
      uVar1 = BCryptGenerateSymmetricKey
                        ((BCRYPT_ALG_HANDLE)param_5[1],phKey,(PUCHAR)0x0,0,param_2,param_3,0);
      uVar3 = (ulonglong)uVar1;
      if (uVar1 == 0) {
        uVar1 = CNG_SetKeyPropertiesFromAlgInfo((longlong)param_1,param_5);
        if (uVar1 == 0) {
          return 0;
        }
        DebugTraceError((char)uVar1,"Status",
                        "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptcms\\util.c",0x86)
        ;
        return (ulonglong)uVar1;
      }
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return uVar3;
      }
      if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
        return uVar3;
      }
      uVar4 = 0x7c;
    }
    else {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return uVar3;
      }
      if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
        return uVar3;
      }
      uVar4 = 0x6d;
    }
  }
  else {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return uVar3;
    }
    if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
      return uVar3;
    }
    uVar4 = 99;
  }
  WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),phKey,
              "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptcms\\util.c","Status",
              (char)uVar3,"onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptcms\\util.c",
              uVar4);
  return uVar3;
}



===== CNG_FindBCryptOidInfo @ 18000bee8 =====

undefined8 CNG_FindBCryptOidInfo(undefined8 param_1,uint param_2,uint param_3,longlong *param_4)

{
  ulonglong uVar1;
  ulonglong uVar2;
  uint uVar3;
  uint uVar4;
  longlong lVar5;
  
  uVar3 = param_3 + 1;
  *param_4 = 0;
  do {
    uVar2 = (ulonglong)param_3;
    if (uVar3 <= param_3) {
      return 0x80090008;
    }
    for (uVar4 = 0; uVar4 < *(uint *)(&DAT_18001f180 + uVar2 * 0x10); uVar4 = uVar4 + 1) {
      lVar5 = (ulonglong)uVar4 * 0x50;
      if ((param_2 == *(uint *)(*(longlong *)(&DAT_18001f188 + uVar2 * 0x10) + 0x28 + lVar5)) &&
         (uVar1 = RtlCompareMemory(param_1,*(undefined8 *)
                                            (*(longlong *)(&DAT_18001f188 + uVar2 * 0x10) + 0x30 +
                                            lVar5),param_2), param_2 == uVar1)) {
        *param_4 = *(longlong *)(&DAT_18001f188 + uVar2 * 0x10) + lVar5;
        return 0;
      }
    }
    param_3 = param_3 + 1;
  } while( true );
}



===== CNG_GetBCryptHandle @ 18000bfbc =====

NTSTATUS CNG_GetBCryptHandle(ushort *param_1,undefined8 *param_2)

{
  NTSTATUS NVar1;
  ushort *puVar2;
  uint uVar3;
  ulonglong uVar4;
  uint uVar5;
  undefined **ppuVar6;
  
  ppuVar6 = &PTR_u_AES_18001f020;
  uVar4 = 0;
  do {
    puVar2 = param_1;
    do {
      uVar3 = (uint)*(ushort *)((longlong)puVar2 + ((longlong)*ppuVar6 - (longlong)param_1));
      uVar5 = *puVar2 - uVar3;
      if (uVar5 != 0) break;
      puVar2 = puVar2 + 1;
    } while (uVar3 != 0);
    if (uVar5 == 0) {
      if (((&DAT_180027b50)[uVar4] == 0) && (NVar1 = I_OpenBCryptAlgHandle((uint)uVar4), NVar1 != 0)
         ) {
        DebugTraceError((char)NVar1,"Status",
                        "onecore\\ds\\security\\cryptoapi\\ncrypt\\common\\provider.c",0x6a);
        return NVar1;
      }
      *param_2 = (&DAT_180027b50)[uVar4];
      return 0;
    }
    uVar3 = (uint)uVar4 + 1;
    uVar4 = (ulonglong)uVar3;
    ppuVar6 = ppuVar6 + 1;
    if (0x2b < uVar3) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
        WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),(ulonglong)uVar5,
                    "onecore\\ds\\security\\cryptoapi\\ncrypt\\common\\provider.c","Status",0x25,
                    "onecore\\ds\\security\\cryptoapi\\ncrypt\\common\\provider.c",0x5e);
      }
      return -0x3ffffddb;
    }
  } while( true );
}



===== NCryptProtectSecret @ 18000c0d0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

uint NCryptProtectSecret(char *param_1,uint param_2,PUCHAR param_3,uint param_4,int *param_5,
                        undefined8 param_6,undefined8 *param_7,undefined4 *param_8)

{
  code *pcVar1;
  longlong lVar2;
  ULONG UVar3;
  uint uVar4;
  undefined8 uVar5;
  int *_Dst;
  longlong lVar6;
  short *psVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  undefined4 *puVar10;
  char *pcVar11;
  undefined1 *puVar12;
  undefined1 *puVar13;
  undefined *puVar14;
  PUCHAR pUVar15;
  char *pcVar16;
  undefined1 uVar17;
  int *piVar18;
  int *piVar19;
  undefined1 auStack_128 [32];
  uint local_108;
  char *local_100;
  undefined4 local_f8;
  uint local_d8 [2];
  ulonglong local_d0;
  PUCHAR pUStack_c8;
  longlong local_c0;
  longlong local_b8;
  PUCHAR local_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined4 local_78 [4];
  undefined8 *local_68;
  ulonglong *local_60;
  ulonglong local_38;
  
                    /* 0xc0d0  94  NCryptProtectSecret */
  local_38 = __security_cookie ^ (ulonglong)local_d8;
  piVar18 = (int *)0x0;
  pcVar11 = (char *)0x0;
  pcVar16 = (char *)0x40;
  local_d8[0] = param_2;
  local_b0 = param_3;
  memset(local_78,0,0x40);
  puVar12 = auStack_128;
  local_b8 = 0;
  local_c0 = 0;
  local_88 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  local_78[0] = 0x40;
  local_98 = 0;
  uStack_90 = 0;
  *param_7 = 0;
  local_d0 = 0;
  pUStack_c8 = (PUCHAR)0x0;
  *param_8 = 0;
  puVar14 = WPP_GLOBAL_Control;
  if ((param_3 == (PUCHAR)0x0) || (param_4 == 0)) {
    uVar4 = 0x80090027;
    param_1 = pcVar11;
    puVar13 = auStack_128;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       (puVar13 = auStack_128, (WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_18000c5a7;
    local_f8 = 0x4cc;
    local_100 = "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\ncryptprotect.c";
    local_108 = 0x80090027;
LAB_18000c27a:
    puVar14 = *(undefined **)(WPP_GLOBAL_Control + 0x10);
    *(undefined8 *)(puVar12 + -8) = 0x18000c28a;
    WPP_SF_sDsd(puVar14,pcVar11,pcVar16,"Status",puVar12[0x20],*(char **)(puVar12 + 0x28),
                puVar12[0x30]);
    param_1 = pcVar11;
    puVar13 = puVar12;
  }
  else if ((param_2 & 0xffffffbf) == 0) {
    if ((param_1 == (char *)0x0) || (*(int *)param_1 != 0x28)) {
      uVar4 = 0x80090026;
      param_1 = pcVar11;
      puVar13 = auStack_128;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (puVar13 = auStack_128, (WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
        local_f8 = 0x4e1;
        local_100 = 
        "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\ncryptprotect.c";
        local_108 = 0x80090026;
        puVar12 = auStack_128;
        goto LAB_18000c27a;
      }
      goto LAB_18000c5a7;
    }
    piVar19 = (int *)&NCryptDefaultAllocPara;
    if (param_5 != (int *)0x0) {
      piVar19 = param_5;
    }
    uVar4 = KeyProtRouter_GetSettings(&local_c0);
    lVar6 = local_c0;
    if (uVar4 != 0) {
      uVar17 = 0xf0;
      puVar14 = (undefined *)(ulonglong)uVar4;
      goto LAB_18000c748;
    }
    pcVar16 = (char *)0x1;
    uVar4 = *(uint *)(*(longlong *)(local_c0 + 8) + 0x20);
    pcVar11 = (char *)(ulonglong)uVar4;
    uVar5 = CNG_FindBCryptOidInfo
                      (*(undefined8 *)(*(longlong *)(local_c0 + 8) + 0x28),uVar4,1,&local_b8);
    puVar13 = auStack_128;
    uVar4 = (uint)uVar5;
    if (uVar4 == 0) {
      pUVar15 = (PUCHAR)0x0;
      uVar4 = *(int *)(local_b8 + 0x38) + 7U >> 3;
      uVar9 = (ulonglong)uVar4;
      local_d0 = CONCAT44(local_d0._4_4_,uVar4);
      puVar12 = auStack_128;
      if (((uVar4 == 0) || (puVar12 = auStack_128, g_ulMaxStackAllocSize < uVar9)) ||
         (uVar8 = g_ulAdditionalProbeSize + 8 + uVar9, puVar12 = auStack_128, uVar8 < uVar9)) {
LAB_18000c204:
        puVar13 = puVar12;
        if (uVar9 <= uVar9 + 8) {
          *(undefined8 *)(puVar12 + -8) = 0x18000c21d;
          pUVar15 = (PUCHAR)(*g_pfnAllocate)();
          if (pUVar15 != (PUCHAR)0x0) {
            builtin_memcpy(pUVar15,"Heap",4);
            pUVar15 = pUVar15 + 8;
          }
        }
      }
      else {
        uVar5 = VerifyStackAvailable(uVar8);
        puVar12 = auStack_128;
        if ((int)uVar5 == 0) goto LAB_18000c204;
        uVar8 = uVar9 + 0x17;
        if (uVar8 <= uVar9 + 8) {
          uVar8 = 0xffffffffffffff0;
        }
        lVar2 = -(uVar8 & 0xfffffffffffffff0);
        puVar13 = auStack_128 + lVar2;
        pUVar15 = (PUCHAR)0x0;
        puVar12 = auStack_128 + lVar2;
        if ((undefined4 *)((longlong)local_d8 + lVar2) == (undefined4 *)0x0) goto LAB_18000c204;
        *(undefined4 *)((longlong)local_d8 + lVar2) = 0x6b637453;
        pUVar15 = (PUCHAR)((longlong)local_d8 + lVar2 + 8);
        puVar12 = auStack_128 + lVar2;
        if (pUVar15 == (PUCHAR)0x0) goto LAB_18000c204;
      }
      pUStack_c8 = pUVar15;
      puVar12 = puVar13;
      if (pUVar15 == (PUCHAR)0x0) {
        uVar4 = 0x8009000e;
        puVar14 = WPP_GLOBAL_Control;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
          *(undefined4 *)(puVar13 + 0x30) = 0x506;
          *(char **)(puVar13 + 0x28) =
               "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\ncryptprotect.c";
          *(undefined4 *)(puVar13 + 0x20) = 0x8009000e;
          goto LAB_18000c6ba;
        }
      }
      else {
        UVar3 = (ULONG)local_d0;
        uVar9 = local_d0 & 0xffffffff;
        *(undefined8 *)(puVar13 + -8) = 0x18000c36b;
        uVar4 = BCryptGenRandom((BCRYPT_ALG_HANDLE)0x0,pUVar15,UVar3,2);
        if (uVar4 == 0) {
          uStack_a0 = *(undefined8 *)(*(longlong *)(lVar6 + 8) + 0x28);
          local_a8 = CONCAT44(local_a8._4_4_,*(undefined4 *)(*(longlong *)(lVar6 + 8) + 0x20));
          local_88 = *(undefined8 *)(lVar6 + 8);
          local_68 = &local_a8;
          local_60 = &local_d0;
          if ((piVar19 != (int *)0x0) && (*piVar19 == 0x18)) {
            pcVar1 = *(code **)(piVar19 + 2);
            *(undefined8 *)(puVar13 + -8) = 0x18000c3d2;
            _Dst = (int *)(*pcVar1)(0x170);
            if (_Dst == (int *)0x0) {
              uVar4 = 0x8009000e;
              puVar14 = (undefined *)0x8009000e;
              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
                *(undefined4 *)(puVar13 + 0x30) = 0x17a;
                *(char **)(puVar13 + 0x28) =
                     "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptcms\\ncryptcms.c";
                *(undefined4 *)(puVar13 + 0x20) = 0x8009000e;
                goto LAB_18000c612;
              }
LAB_18000c4b3:
              uVar4 = (uint)puVar14;
              if (uVar4 != 0) goto LAB_18000c622;
            }
            else {
              *(undefined8 *)(puVar13 + -8) = 0x18000c3eb;
              memset(_Dst,0,0x170);
              pUVar15 = local_b0;
              *_Dst = 0x170;
              _Dst[1] = 1;
              _Dst[4] = 0x18;
              *(undefined8 *)(_Dst + 6) = *(undefined8 *)(piVar19 + 2);
              uVar5 = *(undefined8 *)(piVar19 + 4);
              _Dst[2] = 0;
              *(undefined8 *)(_Dst + 8) = uVar5;
              lVar6 = 0;
              for (uVar9 = 0; uVar9 < 0x20; uVar9 = uVar9 + 0x20) {
                if (*(int *)((longlong)&DAT_18001f1ec + uVar9) == 3) {
                  *(undefined ***)(_Dst + 0x10) = &PTR_s_1_2_840_113549_1_7_3_18001f1d0 + lVar6 * 4;
                  break;
                }
                lVar6 = lVar6 + 1;
              }
              if (*(longlong *)(_Dst + 0x10) == 0) {
                puVar14 = (undefined *)0x80090029;
                *(undefined8 *)(puVar13 + -8) = 0x18000c729;
                DebugTraceError(0x29,"Status",
                                "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptcms\\ncryptcms.c"
                                ,0x97);
LAB_18000c4ab:
                *(undefined8 *)(puVar13 + -8) = 0x18000c4b3;
                I_CMsgFree((longlong)_Dst);
                goto LAB_18000c4b3;
              }
              puVar10 = local_78;
              *(undefined8 *)(puVar13 + -8) = 0x18000c458;
              uVar9 = CMSG_InitEnveloped((longlong)_Dst,(longlong)puVar10,pUVar15,param_4);
              puVar14 = (undefined *)(uVar9 & 0xffffffff);
              if ((int)uVar9 != 0) {
                if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
                  uVar5 = *(undefined8 *)(WPP_GLOBAL_Control + 0x10);
                  *(undefined4 *)(puVar13 + 0x30) = 0x1b0;
                  *(char **)(puVar13 + 0x28) =
                       "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptcms\\ncryptcms.c";
                  *(int *)(puVar13 + 0x20) = (int)uVar9;
                  *(undefined8 *)(puVar13 + -8) = 0x18000c4ab;
                  WPP_SF_sDsd(uVar5,puVar10,pUVar15,"Status",puVar13[0x20],
                              *(char **)(puVar13 + 0x28),puVar13[0x30]);
                }
                goto LAB_18000c4ab;
              }
              *(int **)(_Dst + 0x36) = _Dst + 0x38;
              piVar18 = _Dst;
            }
            pcVar16 = (char *)pUStack_c8;
            param_2 = local_d8[0];
            UVar3 = (ULONG)local_d0;
            *(uint *)(puVar13 + 0x40) = local_d8[0];
            *(undefined4 **)(puVar13 + 0x38) = param_8;
            *(undefined8 **)(puVar13 + 0x30) = param_7;
            *(undefined8 *)(puVar13 + 0x28) = param_6;
            *(int **)(puVar13 + 0x20) = piVar19;
            *(undefined8 *)(puVar13 + -8) = 0x18000c500;
            uVar4 = I_AddRecipientsAndEncodeMessage
                              (piVar18,(longlong)param_1,(PUCHAR)pcVar16,UVar3,
                               *(undefined **)(puVar13 + 0x20),*(undefined8 *)(puVar13 + 0x28),
                               *(undefined8 **)(puVar13 + 0x30),*(undefined4 **)(puVar13 + 0x38),
                               *(undefined4 *)(puVar13 + 0x40));
            if (uVar4 == 0) goto LAB_18000c50a;
            puVar14 = WPP_GLOBAL_Control;
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
              *(undefined4 *)(puVar13 + 0x30) = 0x53d;
              *(char **)(puVar13 + 0x28) =
                   "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\ncryptprotect.c"
              ;
              *(uint *)(puVar13 + 0x20) = uVar4;
              pcVar11 = param_1;
              goto LAB_18000c27a;
            }
            goto LAB_18000c5a7;
          }
          uVar4 = 0x80090027;
          puVar14 = (undefined *)0x80090027;
          if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
             ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_18000c4b3;
          *(undefined4 *)(puVar13 + 0x30) = 0x16d;
          *(char **)(puVar13 + 0x28) =
               "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptcms\\ncryptcms.c";
          *(undefined4 *)(puVar13 + 0x20) = 0x80090027;
LAB_18000c612:
          uVar5 = *(undefined8 *)(WPP_GLOBAL_Control + 0x10);
          *(undefined8 *)(puVar13 + -8) = 0x18000c622;
          WPP_SF_sDsd(uVar5,pUVar15,uVar9,"Status",puVar13[0x20],*(char **)(puVar13 + 0x28),
                      puVar13[0x30]);
LAB_18000c622:
          uVar17 = 0x2c;
        }
        else {
          uVar17 = 0x12;
          puVar14 = (undefined *)(ulonglong)uVar4;
        }
        pcVar11 = "Status";
        pcVar16 = 
        "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\ncryptprotect.c";
        *(undefined8 *)(puVar13 + -8) = 0x18000c63d;
        DebugTraceError((char)puVar14,"Status",
                        "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\ncryptprotect.c"
                        ,uVar17);
      }
    }
    else {
      puVar14 = WPP_GLOBAL_Control;
      puVar12 = auStack_128;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (puVar12 = auStack_128, (WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
        local_f8 = 0x4fc;
        local_100 = 
        "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\ncryptprotect.c";
        local_108 = uVar4;
LAB_18000c6ba:
        puVar14 = *(undefined **)(WPP_GLOBAL_Control + 0x10);
        *(undefined8 *)(puVar13 + -8) = 0x18000c6ca;
        WPP_SF_sDsd(puVar14,pcVar11,pcVar16,"Status",puVar13[0x20],*(char **)(puVar13 + 0x28),
                    puVar13[0x30]);
        puVar12 = puVar13;
      }
    }
    param_1 = pcVar11;
    puVar13 = puVar12;
    param_2 = local_d8[0];
  }
  else {
    uVar4 = 0x80090009;
    uVar17 = 0xd8;
    puVar14 = (undefined *)0x80090009;
LAB_18000c748:
    param_1 = "Status";
    pcVar16 = "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\ncryptprotect.c";
    DebugTraceError((char)puVar14,"Status",
                    "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\ncryptprotect.c"
                    ,uVar17);
    puVar13 = auStack_128;
  }
LAB_18000c5a7:
  if ((Microsoft_Windows_Crypto_NCryptEnableBits & 2) != 0) {
    *(undefined8 *)(puVar13 + -8) = 0x18000c5b9;
    psVar7 = I_GetProcessName();
    *(short **)(puVar13 + 0x20) = psVar7;
    pcVar16 = (char *)(ulonglong)param_2;
    param_1 = "\a";
    *(undefined8 *)(puVar13 + -8) = 0x18000c5d0;
    McTemplateU0ddz_EventWriteTransfer
              (puVar14,(PCEVENT_DESCRIPTOR)&ETW_LOG_NCRYPT_PROTECT_SECRET_FAILED,param_2,uVar4,
               *(wchar_t **)(puVar13 + 0x20));
  }
LAB_18000c50a:
  if (pUStack_c8 != (PUCHAR)0x0) {
    pUVar15 = pUStack_c8;
    for (uVar9 = local_d0 & 0xffffffff; uVar9 != 0; uVar9 = uVar9 - 1) {
      *pUVar15 = '\0';
      pUVar15 = pUVar15 + 1;
    }
    if ((pUStack_c8 != (PUCHAR)0x0) && (*(int *)(pUStack_c8 + -8) == 0x70616548)) {
      *(undefined8 *)(puVar13 + -8) = 0x18000c580;
      (*g_pfnFree)();
    }
  }
  if (piVar18 != (int *)0x0) {
    *(undefined8 *)(puVar13 + -8) = 0x18000c520;
    NCryptMsgClose(piVar18,param_1,pcVar16);
  }
  *(undefined8 *)(puVar13 + -8) = 0x18000c531;
  return uVar4;
}



===== CMSG_InitEnveloped @ 18000c794 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

ulonglong CMSG_InitEnveloped(longlong param_1,longlong param_2,PUCHAR param_3,uint param_4)

{
  longlong *plVar1;
  uint uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined4 uVar6;
  longlong lVar7;
  longlong lVar8;
  undefined8 uVar9;
  char *pcVar10;
  int local_res8 [2];
  longlong local_res10;
  
  local_res8[0] = 0;
  plVar1 = (longlong *)(param_1 + 0x58);
  local_res10 = 0;
  *plVar1 = param_1 + 0x10;
  uVar4 = 0xb;
  if (*(longlong *)(param_2 + 8) == 0) {
    *(char **)(param_1 + 0x120) = s_____H______;
    uVar6 = 0xb;
  }
  else {
    *(undefined8 *)(param_1 + 0x120) = *(undefined8 *)(*(longlong *)(param_2 + 8) + 8);
    uVar6 = **(undefined4 **)(param_2 + 8);
  }
  *(undefined4 *)(param_1 + 0x118) = uVar6;
  if (*(longlong *)(param_2 + 0x10) == 0) {
    pcVar10 = s_____H_e____;
    *(undefined4 *)(param_1 + 0x128) = 0xb;
    *(char **)(param_1 + 0x130) = s_____H_e____;
  }
  else {
    pcVar10 = *(char **)(*(longlong *)(param_2 + 0x10) + 8);
    *(char **)(param_1 + 0x130) = pcVar10;
    uVar4 = (ulonglong)**(uint **)(param_2 + 0x10);
    *(uint *)(param_1 + 0x128) = **(uint **)(param_2 + 0x10);
    *(undefined8 *)(param_1 + 0x90) = *(undefined8 *)(*(longlong *)(param_2 + 0x10) + 0x18);
    *(undefined4 *)(param_1 + 0x88) = *(undefined4 *)(*(longlong *)(param_2 + 0x10) + 0x10);
  }
  uVar9 = 1;
  uVar3 = CNG_FindBCryptOidInfo(pcVar10,(uint)uVar4,1,(longlong *)(param_1 + 0x70));
  uVar5 = uVar3 & 0xffffffff;
  if ((int)uVar3 != 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return uVar5;
    }
    if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
      return uVar5;
    }
    WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),uVar4,uVar9,"Status",(char)uVar3,
                "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptcms\\ncryptcms.c",0xea);
    return uVar5;
  }
  if (*(longlong *)(param_2 + 0x18) != 0) {
    *(undefined8 *)(param_1 + 0x80) = *(undefined8 *)(*(longlong *)(param_2 + 0x18) + 8);
    *(undefined4 *)(param_1 + 0x78) = **(undefined4 **)(param_2 + 0x18);
  }
  uVar4 = CNG_CreateCEKBCryptKeyAndAlgorithmInfo
                    ((uint *)(*(longlong *)(param_1 + 0x70) + 0x28),
                     (BCRYPT_KEY_HANDLE *)(param_1 + 0x10),plVar1);
  if ((int)uVar4 != 0) {
    DebugTraceError((char)uVar4,"Status",
                    "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptcms\\ncryptcms.c",0xfb
                   );
    return uVar4 & 0xffffffff;
  }
  *(undefined8 *)(param_1 + 0x140) = *(undefined8 *)(param_1 + 0x90);
  *(undefined4 *)(param_1 + 0x138) = *(undefined4 *)(param_1 + 0x88);
  if (param_3 != (PUCHAR)0x0) {
    uVar3 = (ulonglong)param_4;
    uVar2 = CNG_EncryptAndAllocate(plVar1,param_3,param_4,&local_res10,local_res8);
    lVar8 = local_res10;
    uVar4 = (ulonglong)uVar2;
    if (uVar2 != 0) {
      DebugTraceError((char)uVar2,"Status",
                      "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptcms\\ncryptcms.c",
                      0xd);
      lVar8 = local_res10;
      goto LAB_18000c95e;
    }
    lVar7 = local_res10;
    uVar5 = CMSG_AddBuffer(param_1,local_res10);
    uVar4 = uVar5 & 0xffffffff;
    if ((int)uVar5 != 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
        WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),lVar7,uVar3,"Status",(char)uVar5,
                    "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptcms\\ncryptcms.c",0x1b
                   );
      }
      goto LAB_18000c95e;
    }
    *(longlong *)(param_1 + 0x158) = lVar8;
    *(int *)(param_1 + 0x150) = local_res8[0];
  }
  uVar4 = 0;
  *(undefined4 *)(param_1 + 0x160) = *(undefined4 *)(param_2 + 0x20);
  *(undefined8 *)(param_1 + 0x168) = *(undefined8 *)(param_2 + 0x28);
  *(undefined4 *)(param_1 + 0xe0) = 2;
  lVar8 = 0;
LAB_18000c95e:
  if (lVar8 != 0) {
    (**(code **)(param_1 + 0x20))(lVar8);
  }
  return uVar4;
}



===== CNG_SetKeyPropertiesFromAlgInfo @ 18000ca6c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

NTSTATUS CNG_SetKeyPropertiesFromAlgInfo(longlong param_1,longlong *param_2)

{
  ULONG cbInput;
  PUCHAR pbInput;
  wchar_t *_Str1;
  undefined4 *puVar1;
  BCRYPT_HANDLE hObject;
  NTSTATUS NVar2;
  int iVar3;
  NTSTATUS NVar4;
  void *pvVar5;
  undefined8 uVar6;
  undefined1 uVar7;
  uint uVar8;
  ulonglong uVar9;
  wchar_t *pwVar10;
  PUCHAR pbInput_00;
  undefined1 *puVar11;
  undefined1 *puVar12;
  ulonglong uVar13;
  undefined1 uVar14;
  longlong lVar15;
  undefined1 auStackY_98 [32];
  undefined8 local_58;
  ulonglong local_50;
  void *pvStack_48;
  uint local_40;
  undefined8 local_38;
  void *pvStack_30;
  ulonglong local_20;
  
  puVar11 = auStackY_98;
  local_20 = __security_cookie ^ (ulonglong)&local_58;
  local_58 = 0;
  local_38 = 0;
  pvStack_30 = (void *)0x0;
  pbInput_00 = (PUCHAR)0x0;
  if (*(int *)(param_2[3] + 0x10) == 1) {
    pbInput = *(PUCHAR *)(param_2[3] + 0x40);
    if (pbInput != (PUCHAR)0x0) {
      lVar15 = -1;
      do {
        lVar15 = lVar15 + 1;
      } while (*(short *)(pbInput + lVar15 * 2) != 0);
      pwVar10 = L"ChainingMode";
      NVar2 = BCryptSetProperty((BCRYPT_HANDLE)param_2[2],L"ChainingMode",pbInput,
                                (int)lVar15 * 2 + 2,0);
      if (NVar2 == 0) goto LAB_18000cb71;
      puVar11 = auStackY_98;
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         (puVar11 = auStackY_98, (WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_18000cb48;
      uVar7 = 0xac;
      goto LAB_18000cb38;
    }
LAB_18000cb71:
    lVar15 = param_2[3];
    _Str1 = *(wchar_t **)(lVar15 + 0x40);
    if (((_Str1 != (wchar_t *)0x0) && (*_Str1 != L'\0')) &&
       (iVar3 = wcscmp(_Str1,L"ChainingModeCBC"), iVar3 != 0)) {
      pwVar10 = L"ChainingModeGCM";
      iVar3 = wcscmp(_Str1,L"ChainingModeGCM");
      if (iVar3 == 0) {
        pwVar10 = (wchar_t *)0x1b;
        local_40 = 0;
        local_50 = 0;
        pvStack_48 = (void *)0x0;
        local_58 = 0x18;
        NVar2 = Ordinal_3(ASN1_NCRYPT_MODULE_HANDLE,0x1b,1,*(undefined8 *)(param_1 + 0x18));
        puVar11 = auStackY_98;
        if (NVar2 == 0) {
          if ((local_40 < 0x11) && ((uint)local_50 < 0xd)) {
            *(undefined4 *)(param_2 + 8) = 0x98;
            *(int *)(param_2 + 8) = *(int *)(param_2[3] + 0x3c) + 0x98;
            pvVar5 = (void *)(**(code **)(*param_2 + 8))();
            param_2[9] = (longlong)pvVar5;
            if (pvVar5 != (void *)0x0) {
              *(uint *)(param_2 + 0xe) = *(uint *)(param_2 + 0xe) | 8;
              memset(pvVar5,0,(ulonglong)*(uint *)(param_2 + 8));
              puVar1 = (undefined4 *)param_2[9];
              *puVar1 = 0x58;
              *(undefined4 **)(puVar1 + 2) = puVar1 + 0x16;
              puVar1[1] = 1;
              puVar1[4] = (uint)local_50;
              *(undefined8 *)(puVar1 + 10) = 0;
              puVar1[0xc] = local_40;
              *(undefined4 **)(puVar1 + 0x22) = puVar1 + 0x26;
              puVar1[0x24] = *(undefined4 *)(param_2[3] + 0x3c);
              memcpy(puVar1 + 0x16,pvStack_48,local_50 & 0xffffffff);
              puVar11 = auStackY_98;
              *(uint *)(param_2 + 0xe) = *(uint *)(param_2 + 0xe) | 0x10000000;
              goto LAB_18000ccc5;
            }
            NVar2 = -0x7ff6fff2;
            puVar11 = auStackY_98;
            if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
               (puVar11 = auStackY_98, (WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_18000cb48;
            uVar7 = 0x17;
            NVar2 = -0x7ff6fff2;
            goto LAB_18000cb38;
          }
          NVar2 = -0x7ff6fff8;
          uVar14 = 0xc;
          uVar7 = 8;
          goto LAB_18000ceda;
        }
        puVar11 = auStackY_98;
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           (puVar11 = auStackY_98, (WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_18000cb48;
        uVar7 = 4;
      }
      else {
        NVar2 = -0x7ff6ffd7;
        puVar11 = auStackY_98;
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           (puVar11 = auStackY_98, (WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_18000cb48;
        uVar7 = 0x30;
        NVar2 = -0x7ff6ffd7;
      }
LAB_18000cb38:
      WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),pwVar10,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptcms\\util.c","Status",
                  (char)NVar2,"onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptcms\\util.c"
                  ,uVar7);
      puVar11 = auStackY_98;
      goto LAB_18000cb48;
    }
    uVar13 = (ulonglong)*(uint *)(lVar15 + 0x3c);
    puVar12 = auStackY_98;
    if ((uVar13 == 0) || (puVar12 = auStackY_98, g_ulMaxStackAllocSize < uVar13)) {
LAB_18000cdf0:
      puVar11 = puVar12;
      if (uVar13 <= uVar13 + 8) {
        *(undefined8 *)(puVar12 + -8) = 0x18000ce05;
        pbInput_00 = (PUCHAR)(*g_pfnAllocate)();
        if (pbInput_00 != (PUCHAR)0x0) {
          builtin_memcpy(pbInput_00,"Heap",4);
          pbInput_00 = pbInput_00 + 8;
        }
      }
    }
    else {
      uVar9 = g_ulAdditionalProbeSize + 8 + uVar13;
      puVar12 = auStackY_98;
      if (uVar9 < uVar13) goto LAB_18000cdf0;
      uVar6 = VerifyStackAvailable(uVar9);
      puVar12 = auStackY_98;
      if ((int)uVar6 == 0) goto LAB_18000cdf0;
      uVar9 = uVar13 + 0x17;
      if (uVar9 <= uVar13 + 8) {
        uVar9 = 0xffffffffffffff0;
      }
      lVar15 = -(uVar9 & 0xfffffffffffffff0);
      puVar11 = auStackY_98 + lVar15;
      pbInput_00 = (PUCHAR)0x0;
      puVar12 = auStackY_98 + lVar15;
      if ((undefined4 *)((longlong)&local_58 + lVar15) == (undefined4 *)0x0) goto LAB_18000cdf0;
      *(undefined4 *)((longlong)&local_58 + lVar15) = 0x6b637453;
      pbInput_00 = (PUCHAR)((longlong)&local_50 + lVar15);
      puVar12 = auStackY_98 + lVar15;
      if (pbInput_00 == (PUCHAR)0x0) goto LAB_18000cdf0;
    }
    if (pbInput_00 == (PUCHAR)0x0) {
      NVar2 = -0x7ff6fff2;
      uVar14 = 0xbd;
      uVar7 = 0xe;
LAB_18000ceda:
      *(undefined8 *)(puVar11 + -8) = 0x18000ceed;
      DebugTraceError(uVar7,"Status",
                      "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptcms\\util.c",uVar14)
      ;
      goto LAB_18000cb48;
    }
    uVar8 = *(uint *)(param_2[3] + 0x3c);
    *(undefined8 *)(puVar11 + -8) = 0x18000ce40;
    memset(pbInput_00,0,(ulonglong)uVar8);
    if (2 < *(uint *)(param_1 + 0x10)) {
      uVar8 = *(uint *)(param_1 + 0x10);
      uVar6 = *(undefined8 *)(param_1 + 0x18);
      *(undefined8 **)(puVar11 + 0x38) = &local_58;
      *(undefined8 **)(puVar11 + 0x30) = &local_38;
      *(undefined8 *)(puVar11 + 0x28) = 0;
      *(ulonglong *)(puVar11 + 0x20) = (ulonglong)uVar8;
      local_58 = 0x10;
      *(undefined8 *)(puVar11 + -8) = 0x18000cf35;
      iVar3 = Ordinal_3(ASN1_NCRYPT_MODULE_HANDLE,6,1,uVar6);
      pvVar5 = pvStack_30;
      if (iVar3 == 0) {
        uVar8 = *(uint *)(param_2[3] + 0x3c);
        if ((uint)local_38 < *(uint *)(param_2[3] + 0x3c)) {
          uVar8 = (uint)local_38;
        }
        *(undefined8 *)(puVar11 + -8) = 0x18000cf5f;
        memcpy(pbInput_00,pvVar5,(ulonglong)uVar8);
      }
    }
    lVar15 = param_2[3];
    hObject = (BCRYPT_HANDLE)param_2[2];
    *(undefined4 *)(puVar11 + 0x20) = 0;
    cbInput = *(ULONG *)(lVar15 + 0x3c);
    *(undefined8 *)(puVar11 + -8) = 0x18000ce6d;
    NVar4 = BCryptSetProperty(hObject,L"IV",pbInput_00,cbInput,*(ULONG *)(puVar11 + 0x20));
    if (NVar4 == 0) goto LAB_18000ccc5;
    *(undefined8 *)(puVar11 + -8) = 0x18000ce97;
    DebugTraceError((char)NVar4,"Status",
                    "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptcms\\util.c",0xe7);
  }
  else {
LAB_18000ccc5:
    NVar2 = 0;
    NVar4 = 0;
    if (pbInput_00 == (PUCHAR)0x0) goto LAB_18000cb48;
  }
  NVar2 = NVar4;
  if (*(int *)(pbInput_00 + -8) == 0x70616548) {
    *(undefined8 *)(puVar11 + -8) = 0x18000ceb3;
    (*g_pfnFree)();
  }
LAB_18000cb48:
  *(undefined8 *)(puVar11 + -8) = 0x18000cb56;
  return NVar2;
}



===== CNG_CreateCEKBCryptKeyAndAlgorithmInfo @ 18000cf6c =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

ulonglong CNG_CreateCEKBCryptKeyAndAlgorithmInfo
                    (uint *param_1,BCRYPT_KEY_HANDLE *param_2,undefined8 *param_3)

{
  longlong *plVar1;
  ULONG UVar2;
  wchar_t *_Str1;
  undefined4 *puVar3;
  BCRYPT_HANDLE hObject;
  uint uVar4;
  int iVar5;
  void *_Dst;
  PUCHAR pUVar6;
  undefined8 uVar7;
  undefined1 uVar8;
  ulonglong uVar9;
  wchar_t *pbBuffer;
  BCRYPT_KEY_HANDLE *ppvVar10;
  ulonglong uVar11;
  undefined1 *puVar12;
  undefined1 *puVar13;
  UCHAR *pbBuffer_00;
  undefined1 uVar14;
  longlong lVar15;
  undefined1 auStackY_a8 [32];
  undefined8 local_68;
  UCHAR aUStack_60 [8];
  undefined8 local_58;
  PUCHAR pUStack_50;
  undefined4 local_48;
  undefined4 local_44;
  undefined8 local_40;
  undefined4 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)&local_68;
  *param_3 = param_2;
  plVar1 = param_3 + 3;
  local_68 = 0;
  pbBuffer_00 = (UCHAR *)0x0;
  local_58 = 0;
  pUStack_50 = (PUCHAR)0x0;
  ppvVar10 = param_2;
  if (*plVar1 == 0) {
    ppvVar10 = (BCRYPT_KEY_HANDLE *)(ulonglong)*param_1;
    uVar11 = CNG_FindBCryptOidInfo(*(undefined8 *)(param_1 + 2),*param_1,1,plVar1);
    uVar4 = (uint)uVar11;
    uVar11 = uVar11 & 0xffffffff;
    if (uVar4 == 0) goto LAB_18000cfc6;
    uVar14 = 0x5d;
LAB_18000d3e1:
    puVar13 = auStackY_a8;
    uVar8 = (undefined1)uVar4;
LAB_18000d3f5:
    *(undefined8 *)(puVar13 + -8) = 0x18000d408;
    DebugTraceError(uVar8,"Status",
                    "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptcms\\util.c",uVar14);
  }
  else {
LAB_18000cfc6:
    pbBuffer = (wchar_t *)(param_3 + 1);
    if (*(BCRYPT_KEY_HANDLE *)pbBuffer == (BCRYPT_KEY_HANDLE)0x0) {
      uVar4 = CNG_GetBCryptHandle(*(ushort **)(*plVar1 + 8),(undefined8 *)pbBuffer);
      uVar11 = (ulonglong)uVar4;
      ppvVar10 = (BCRYPT_KEY_HANDLE *)pbBuffer;
      if (uVar4 == 0) goto LAB_18000cfd3;
      puVar13 = auStackY_a8;
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         (puVar13 = auStackY_a8, (WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_18000d1f8;
      uVar14 = 0x6a;
      goto LAB_18000d1e8;
    }
LAB_18000cfd3:
    pbBuffer = (wchar_t *)ppvVar10;
    if (param_3[5] == 0) {
      *(uint *)(param_3 + 4) = *(uint *)(*plVar1 + 0x38) >> 3;
      pUVar6 = (PUCHAR)(*param_2[1])();
      param_3[5] = pUVar6;
      if (pUVar6 != (PUCHAR)0x0) {
        *(uint *)(param_3 + 0xe) = *(uint *)(param_3 + 0xe) | 4;
        uVar4 = BCryptGenRandom((BCRYPT_ALG_HANDLE)0x0,pUVar6,*(ULONG *)(param_3 + 4),2);
        uVar11 = (ulonglong)uVar4;
        if (uVar4 != 0) {
          uVar14 = 0x85;
          goto LAB_18000d3e1;
        }
        goto LAB_18000cfdd;
      }
      uVar11 = 0x8009000e;
      puVar13 = auStackY_a8;
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         (puVar13 = auStackY_a8, (WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_18000d1f8;
      uVar14 = 0x77;
LAB_18000d26d:
      uVar11 = 0x8009000e;
LAB_18000d1e8:
      WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),pbBuffer,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptcms\\util.c","Status",
                  (char)uVar11,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptcms\\util.c",uVar14);
      puVar13 = auStackY_a8;
      goto LAB_18000d1f8;
    }
LAB_18000cfdd:
    ppvVar10 = (BCRYPT_KEY_HANDLE *)(param_3 + 2);
    if (*ppvVar10 == (BCRYPT_KEY_HANDLE)0x0) {
      pbBuffer = (wchar_t *)ppvVar10;
      uVar4 = BCryptGenerateSymmetricKey
                        ((BCRYPT_ALG_HANDLE)param_3[1],ppvVar10,(PUCHAR)0x0,0,(PUCHAR)param_3[5],
                         *(ULONG *)(param_3 + 4),0);
      uVar11 = (ulonglong)uVar4;
      if (uVar4 != 0) {
        puVar13 = auStackY_a8;
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           (puVar13 = auStackY_a8, (WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_18000d1f8;
        uVar14 = 0x97;
        goto LAB_18000d1e8;
      }
    }
    puVar13 = auStackY_a8;
    if (*(int *)(param_3[3] + 0x10) == 1) {
      pUVar6 = *(PUCHAR *)(param_3[3] + 0x40);
      if (pUVar6 != (PUCHAR)0x0) {
        lVar15 = -1;
        do {
          lVar15 = lVar15 + 1;
        } while (*(short *)(pUVar6 + lVar15 * 2) != 0);
        pbBuffer = L"ChainingMode";
        uVar4 = BCryptSetProperty(*ppvVar10,L"ChainingMode",pUVar6,(int)lVar15 * 2 + 2,0);
        uVar11 = (ulonglong)uVar4;
        if (uVar4 != 0) {
          puVar13 = auStackY_a8;
          if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
             (puVar13 = auStackY_a8, (WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_18000d1f8;
          uVar14 = 0xa9;
          goto LAB_18000d1e8;
        }
      }
      lVar15 = param_3[3];
      _Str1 = *(wchar_t **)(lVar15 + 0x40);
      if (((_Str1 != (wchar_t *)0x0) && (*_Str1 != L'\0')) &&
         (iVar5 = wcscmp(_Str1,L"ChainingModeCBC"), iVar5 != 0)) {
        pbBuffer = L"ChainingModeGCM";
        iVar5 = wcscmp(_Str1,L"ChainingModeGCM");
        if (iVar5 != 0) {
          uVar11 = 0x80090029;
          uVar14 = 0x36;
          uVar8 = 0x29;
          puVar13 = auStackY_a8;
          goto LAB_18000d3f5;
        }
        *(undefined4 *)(param_3 + 8) = 0x98;
        local_44 = 0;
        iVar5 = *(int *)(lVar15 + 0x3c) + 0x98;
        *(int *)(param_3 + 8) = iVar5;
        _Dst = (void *)(*param_2[1])(iVar5);
        param_3[9] = _Dst;
        if (_Dst == (void *)0x0) {
          uVar11 = 0x8009000e;
          puVar13 = auStackY_a8;
          if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
             (puVar13 = auStackY_a8, (WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_18000d1f8;
          uVar14 = 0xfc;
          goto LAB_18000d26d;
        }
        *(uint *)(param_3 + 0xe) = *(uint *)(param_3 + 0xe) | 8;
        memset(_Dst,0,(ulonglong)*(uint *)(param_3 + 8));
        puVar3 = (undefined4 *)param_3[9];
        *puVar3 = 0x58;
        *(undefined4 **)(puVar3 + 10) = puVar3 + 0x19;
        pbBuffer = (wchar_t *)(puVar3 + 0x16);
        puVar3[1] = 1;
        *(undefined4 **)(puVar3 + 0x22) = puVar3 + 0x26;
        *(wchar_t **)(puVar3 + 2) = pbBuffer;
        puVar3[4] = 0xc;
        puVar3[0xc] = 0x10;
        puVar3[0x24] = *(undefined4 *)(param_3[3] + 0x3c);
        uVar4 = BCryptGenRandom((BCRYPT_ALG_HANDLE)0x0,(PUCHAR)pbBuffer,0xc,2);
        uVar11 = (ulonglong)uVar4;
        if (uVar4 == 0) {
          local_40 = *(undefined8 *)(puVar3 + 2);
          pbBuffer = (wchar_t *)0x1b;
          local_48 = puVar3[4];
          local_38 = 0x10;
          uVar4 = Ordinal_2(ASN1_NCRYPT_MODULE_HANDLE,0x1b,0,param_2);
          uVar11 = (ulonglong)uVar4;
          if (uVar4 == 0) {
            *(uint *)(param_3 + 0xe) = *(uint *)(param_3 + 0xe) | 0x10000002;
            *(undefined4 *)(param_3 + 6) = (undefined4)local_68;
            puVar13 = auStackY_a8;
            goto LAB_18000d195;
          }
          puVar13 = auStackY_a8;
          if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
             (puVar13 = auStackY_a8, (WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_18000d1f8;
          uVar14 = 0x29;
        }
        else {
          puVar13 = auStackY_a8;
          if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
             (puVar13 = auStackY_a8, (WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_18000d1f8;
          uVar14 = 0x16;
        }
        goto LAB_18000d1e8;
      }
      uVar11 = (ulonglong)*(uint *)(lVar15 + 0x3c);
      puVar12 = auStackY_a8;
      if ((uVar11 == 0) || (puVar12 = auStackY_a8, g_ulMaxStackAllocSize < uVar11)) {
LAB_18000d4b7:
        puVar13 = puVar12;
        if (uVar11 <= uVar11 + 8) {
          *(undefined8 *)(puVar12 + -8) = 0x18000d4cc;
          pbBuffer_00 = (UCHAR *)(*g_pfnAllocate)();
          if (pbBuffer_00 != (PUCHAR)0x0) {
            builtin_memcpy(pbBuffer_00,"Heap",4);
            pbBuffer_00 = pbBuffer_00 + 8;
          }
        }
      }
      else {
        uVar9 = g_ulAdditionalProbeSize + 8 + uVar11;
        puVar12 = auStackY_a8;
        if (uVar9 < uVar11) goto LAB_18000d4b7;
        uVar7 = VerifyStackAvailable(uVar9);
        puVar12 = auStackY_a8;
        if ((int)uVar7 == 0) goto LAB_18000d4b7;
        uVar9 = uVar11 + 0x17;
        if (uVar9 <= uVar11 + 8) {
          uVar9 = 0xffffffffffffff0;
        }
        lVar15 = -(uVar9 & 0xfffffffffffffff0);
        pbBuffer_00 = (UCHAR *)0x0;
        puVar12 = auStackY_a8 + lVar15;
        if (aUStack_60 + lVar15 + -8 == (UCHAR *)0x0) goto LAB_18000d4b7;
        builtin_memcpy(aUStack_60 + lVar15 + -8,"Stck",4);
        pbBuffer_00 = aUStack_60 + lVar15;
        puVar12 = auStackY_a8 + lVar15;
        puVar13 = auStackY_a8 + lVar15;
        if (pbBuffer_00 == (UCHAR *)0x0) goto LAB_18000d4b7;
      }
      if (pbBuffer_00 == (PUCHAR)0x0) {
        uVar11 = 0x8009000e;
        uVar14 = 0xba;
        uVar8 = 0xe;
        goto LAB_18000d3f5;
      }
      UVar2 = *(ULONG *)(param_3[3] + 0x3c);
      *(undefined8 *)(puVar13 + -8) = 0x18000d501;
      uVar4 = BCryptGenRandom((BCRYPT_ALG_HANDLE)0x0,pbBuffer_00,UVar2,2);
      uVar11 = (ulonglong)uVar4;
      if (uVar4 == 0) {
        local_58 = CONCAT44(local_58._4_4_,*(undefined4 *)(param_3[3] + 0x3c));
        pUStack_50 = pbBuffer_00;
        *(undefined8 **)(puVar13 + 0x30) = &local_58;
        *(undefined8 **)(puVar13 + 0x28) = &local_68;
        *(undefined8 **)(puVar13 + 0x20) = param_3 + 7;
        *(undefined8 *)(puVar13 + -8) = 0x18000d575;
        uVar4 = Ordinal_2(ASN1_NCRYPT_MODULE_HANDLE,6,0,param_2);
        uVar11 = (ulonglong)uVar4;
        if (uVar4 == 0) {
          *(uint *)(param_3 + 0xe) = *(uint *)(param_3 + 0xe) | 2;
          hObject = (BCRYPT_HANDLE)param_3[2];
          *(undefined4 *)(param_3 + 6) = (undefined4)local_68;
          UVar2 = *(ULONG *)(param_3[3] + 0x3c);
          *(undefined4 *)(puVar13 + 0x20) = 0;
          *(undefined8 *)(puVar13 + -8) = 0x18000d5b4;
          uVar4 = BCryptSetProperty(hObject,L"IV",pbBuffer_00,UVar2,*(ULONG *)(puVar13 + 0x20));
          uVar11 = (ulonglong)uVar4;
          if (uVar4 == 0) goto LAB_18000d195;
          uVar14 = 0xe8;
        }
        else {
          uVar14 = 0xd8;
        }
      }
      else {
        uVar14 = 0xc6;
      }
      *(undefined8 *)(puVar13 + -8) = 0x18000d52f;
      DebugTraceError((char)uVar4,"Status",
                      "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptcms\\util.c",uVar14)
      ;
    }
    else {
LAB_18000d195:
      uVar11 = 0;
      if (pbBuffer_00 == (UCHAR *)0x0) goto LAB_18000d1f8;
    }
    if (*(int *)(pbBuffer_00 + -8) == 0x70616548) {
      *(undefined8 *)(puVar13 + -8) = 0x18000d1b5;
      (*g_pfnFree)();
    }
  }
LAB_18000d1f8:
  *(undefined8 *)(puVar13 + -8) = 0x18000d206;
  return uVar11;
}



===== KeyProtRouter_GetSettings @ 18000d5d0 =====

uint KeyProtRouter_GetSettings(undefined8 *param_1)

{
  LPCWSTR pWVar1;
  short *psVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  undefined8 *puVar6;
  undefined8 uVar7;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  bVar3 = false;
  if (DAT_180027cf0 == 0) {
    _RegLoadSettings();
  }
  puVar6 = DAT_180027ce8;
  if (DAT_180027ce8 == (undefined8 *)0x0) {
    RtlEnterCriticalSection(&g_csKeyProtectorLock);
    bVar3 = true;
    puVar6 = DAT_180027ce8;
    if (DAT_180027ce8 == (undefined8 *)0x0) {
      puVar6 = (undefined8 *)MSCryptAlloc(0x20);
      DAT_180027ce8 = puVar6;
      if (puVar6 == (undefined8 *)0x0) {
        uVar5 = 0x8009000e;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
          WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0,
                      "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\reg.c",
                      "Status",0xe,
                      "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\reg.c",0x79
                     );
        }
        goto LAB_18000d6e3;
      }
      *puVar6 = 0;
      puVar6[1] = 0;
      puVar6[2] = 0;
      puVar6[3] = 0;
      *puVar6 = L"2.16.840.1.101.3.4.1.46";
    }
  }
  if (puVar6[1] == 0) {
    psVar2 = (short *)*puVar6;
    if ((psVar2 != (short *)0x0) && (*psVar2 != 0)) {
      local_18 = 0;
      uStack_10 = 0;
      local_28 = 0;
      uStack_20 = 0;
      RtlInitUnicodeString(&local_18,psVar2);
      iVar4 = RtlUnicodeStringToAnsiString(&local_28,&local_18,1);
      if (-1 < iVar4) {
        uVar7 = Ordinal_6(uStack_20,2);
        DAT_180027ce8[1] = uVar7;
        RtlFreeAnsiString(&local_28);
      }
      puVar6 = DAT_180027ce8;
    }
    if (puVar6[1] == 0) {
      uVar7 = Ordinal_6("2.16.840.1.101.3.4.1.46",2);
      puVar6 = DAT_180027ce8;
      DAT_180027ce8[1] = uVar7;
    }
  }
  if (((puVar6[3] == 0) && (pWVar1 = (LPCWSTR)puVar6[2], pWVar1 != (LPCWSTR)0x0)) &&
     (*pWVar1 != L'\0')) {
    uVar5 = NCryptCreateProtectionDescriptor(pWVar1,0,puVar6 + 3);
    if (uVar5 == 0) {
      puVar6 = DAT_180027ce8;
      goto LAB_18000d62a;
    }
    DebugTraceError((char)uVar5,"Status",
                    "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\reg.c",0xaf);
  }
  else {
LAB_18000d62a:
    DAT_180027cf0 = 1;
    uVar5 = 0;
    *param_1 = puVar6;
  }
  if (!bVar3) {
    return uVar5;
  }
LAB_18000d6e3:
  RtlLeaveCriticalSection(&g_csKeyProtectorLock);
  return uVar5;
}



===== CMSG_AddRecipient @ 18000d820 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

ulonglong CMSG_AddRecipient(longlong param_1,undefined8 param_2)

{
  void *_Src;
  undefined8 uVar1;
  undefined8 *puVar2;
  uint uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  size_t sVar6;
  undefined8 *puVar7;
  undefined1 uVar8;
  longlong local_res8;
  size_t local_res18;
  undefined8 local_res20;
  undefined8 *local_38 [2];
  
  local_38[0] = (undefined8 *)0x0;
  local_res18 = 0;
  local_res8 = 0;
  local_res20 = 0;
  uVar3 = Ordinal_2(ASN1_NCRYPT_MODULE_HANDLE,0x16,0,param_1 + 0x10,&local_res8,&local_res20,param_2
                   );
  uVar5 = (ulonglong)uVar3;
  if (uVar3 == 0) {
    uVar3 = Ordinal_3(ASN1_NCRYPT_MODULE_HANDLE,0x16,0x200000,local_res8,local_res20,0,0,
                      &local_res18);
    uVar5 = (ulonglong)uVar3;
    if (uVar3 == 0) {
      sVar6 = local_res18;
      uVar4 = CMSG_AllocateBuffer(param_1,local_res18,local_38);
      puVar2 = local_38[0];
      uVar5 = uVar4 & 0xffffffff;
      if ((int)uVar4 == 0) {
        sVar6 = 0x16;
        uVar3 = Ordinal_3(ASN1_NCRYPT_MODULE_HANDLE,0x16,0x200000,local_res8,local_res20,0,
                          local_38[0],&local_res18);
        uVar5 = (ulonglong)uVar3;
        if (uVar3 == 0) {
          uVar3 = *(uint *)(param_1 + 0x108);
          if (uVar3 == 0) {
            sVar6 = 0x2800;
            uVar4 = CMSG_AllocateBuffer(param_1,0x2800,(undefined8 *)(param_1 + 0x110));
            uVar5 = uVar4 & 0xffffffff;
            if ((int)uVar4 != 0) {
              if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                 ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_18000d9e2;
              uVar8 = 0xfa;
              goto LAB_18000da2c;
            }
          }
          else if ((uVar3 & 0xffffffc0) + 0x40 <= uVar3 + 1) {
            puVar7 = (undefined8 *)(param_1 + 0x110);
            _Src = (void *)*puVar7;
            uVar5 = CMSG_AllocateBuffer(param_1,(ulonglong)((uVar3 & 0xffffffc0) + 0x80) * 0xa0,
                                        puVar7);
            uVar3 = (uint)uVar5;
            uVar5 = uVar5 & 0xffffffff;
            if (uVar3 != 0) {
              uVar8 = 0xd;
              goto LAB_18000daae;
            }
            if (*(uint *)(param_1 + 0x108) != 0) {
              memcpy((void *)*puVar7,_Src,(ulonglong)*(uint *)(param_1 + 0x108) * 0xa0);
            }
          }
          uVar1 = puVar2[1];
          puVar7 = (undefined8 *)
                   ((ulonglong)*(uint *)(param_1 + 0x108) * 0xa0 + *(longlong *)(param_1 + 0x110));
          *puVar7 = *puVar2;
          puVar7[1] = uVar1;
          uVar1 = puVar2[3];
          puVar7[2] = puVar2[2];
          puVar7[3] = uVar1;
          uVar1 = puVar2[5];
          puVar7[4] = puVar2[4];
          puVar7[5] = uVar1;
          uVar1 = puVar2[7];
          puVar7[6] = puVar2[6];
          puVar7[7] = uVar1;
          uVar1 = puVar2[9];
          puVar7[8] = puVar2[8];
          puVar7[9] = uVar1;
          uVar1 = puVar2[0xb];
          puVar7[10] = puVar2[10];
          puVar7[0xb] = uVar1;
          uVar1 = puVar2[0xd];
          puVar7[0xc] = puVar2[0xc];
          puVar7[0xd] = uVar1;
          uVar1 = puVar2[0xf];
          puVar7[0xe] = puVar2[0xe];
          puVar7[0xf] = uVar1;
          uVar1 = puVar2[0x11];
          puVar7[0x10] = puVar2[0x10];
          puVar7[0x11] = uVar1;
          uVar1 = puVar2[0x13];
          puVar7[0x12] = puVar2[0x12];
          puVar7[0x13] = uVar1;
          *(int *)(param_1 + 0x108) = *(int *)(param_1 + 0x108) + 1;
          uVar5 = 0;
          goto LAB_18000d9e2;
        }
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_18000d9e2;
        uVar8 = 0xe7;
      }
      else {
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_18000d9e2;
        uVar8 = 0xd7;
      }
LAB_18000da2c:
      WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),sVar6,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptcms\\cmsg.c","Status",
                  (char)uVar5,"onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptcms\\cmsg.c"
                  ,uVar8);
      goto LAB_18000d9e2;
    }
    uVar8 = 0xcc;
  }
  else {
    uVar8 = 0xbc;
  }
LAB_18000daae:
  DebugTraceError((char)uVar3,"Status",
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptcms\\cmsg.c",uVar8);
LAB_18000d9e2:
  if (local_res8 != 0) {
    (**(code **)(param_1 + 0x20))();
  }
  return uVar5;
}



===== CMSG_AllocateBuffer @ 18000db30 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

ulonglong CMSG_AllocateBuffer(longlong param_1,size_t param_2,undefined8 *param_3)

{
  void *_Dst;
  ulonglong uVar1;
  size_t sVar2;
  ulonglong uVar3;
  
  *param_3 = 0;
  sVar2 = param_2;
  _Dst = (void *)(**(code **)(param_1 + 0x18))(param_2);
  if (_Dst == (void *)0x0) {
    uVar3 = 0x8009000e;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),sVar2,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptcms\\cmsg.c","Status",
                  0xe,"onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptcms\\cmsg.c",0x75);
    }
  }
  else {
    memset(_Dst,0,param_2);
    uVar1 = CMSG_AddBuffer(param_1,_Dst);
    uVar3 = uVar1 & 0xffffffff;
    if ((int)uVar1 == 0) {
      *param_3 = _Dst;
    }
    else {
      DebugTraceError((char)uVar1,"Status",
                      "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptcms\\cmsg.c",0x81);
      (**(code **)(param_1 + 0x20))(_Dst);
    }
  }
  return uVar3;
}



===== CMSG_AddBuffer @ 18000dc1c =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

undefined8 CMSG_AddBuffer(longlong param_1,undefined8 param_2)

{
  uint uVar1;
  longlong lVar2;
  void *_Dst;
  undefined8 uVar3;
  void *_Src;
  
  uVar1 = *(uint *)(param_1 + 0x50);
  _Src = (void *)0x0;
  if (uVar1 == 0) {
    uVar3 = param_2;
    lVar2 = (**(code **)(param_1 + 0x18))(0x800);
    *(longlong *)(param_1 + 0x48) = lVar2;
    if (lVar2 == 0) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 0x8009000e;
      }
      if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
        return 0x8009000e;
      }
      WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),uVar3,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptcms\\cmsg.c","Status",
                  0xe,"onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptcms\\cmsg.c",0x33);
      return 0x8009000e;
    }
  }
  else if ((uVar1 & 0xffffff00) + 0x100 <= uVar1 + 1) {
    _Dst = (void *)(**(code **)(param_1 + 0x18))((ulonglong)((uVar1 & 0xffffff00) + 0x200) << 3);
    if (_Dst == (void *)0x0) {
      DebugTraceError(0xe,"Status",
                      "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptcms\\cmsg.c",0x41);
      return 0x8009000e;
    }
    _Src = *(void **)(param_1 + 0x48);
    *(void **)(param_1 + 0x48) = _Dst;
    if (*(int *)(param_1 + 0x50) != 0) {
      memcpy(_Dst,_Src,(ulonglong)*(uint *)(param_1 + 0x50) << 3);
    }
  }
  *(undefined8 *)(*(longlong *)(param_1 + 0x48) + (ulonglong)*(uint *)(param_1 + 0x50) * 8) =
       param_2;
  *(int *)(param_1 + 0x50) = *(int *)(param_1 + 0x50) + 1;
  if (_Src != (void *)0x0) {
    (**(code **)(param_1 + 0x20))(_Src);
  }
  return 0;
}



===== CNG_EncryptAndAllocate @ 18000dd6c =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

NTSTATUS CNG_EncryptAndAllocate
                   (longlong *param_1,PUCHAR param_2,uint param_3,longlong *param_4,int *param_5)

{
  longlong *plVar1;
  uint uVar2;
  NTSTATUS NVar3;
  PUCHAR pbOutput;
  void *_Src;
  uint uVar4;
  void *pvVar5;
  ULONG local_res8 [2];
  PUCHAR local_res10;
  undefined1 uVar6;
  
  plVar1 = param_1 + 9;
  _Src = (void *)0x0;
  uVar4 = 0;
  uVar2 = *(uint *)(param_1 + 0xe);
  *param_5 = 0;
  local_res8[0] = 0;
  *param_4 = 0;
  local_res10 = param_2;
  if ((uVar2 & 0x10000000) != 0) {
    if (*(uint *)(param_1 + 8) < 0x98) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return -0x7ff6ffd3;
      }
      if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
        return -0x7ff6ffd3;
      }
      uVar6 = 0x58;
      NVar3 = -0x7ff6ffd3;
      goto LAB_18000df13;
    }
    _Src = *(void **)(*plVar1 + 0x28);
    uVar4 = *(uint *)(*plVar1 + 0x30);
  }
  pvVar5 = (void *)(ulonglong)param_3;
  NVar3 = BCryptEncrypt((BCRYPT_KEY_HANDLE)param_1[2],param_2,param_3,(void *)*plVar1,(PUCHAR)0x0,0,
                        (PUCHAR)0x0,0,local_res8,*(ULONG *)(param_1[3] + 0x48));
  if (NVar3 == 0) {
    pbOutput = (PUCHAR)(**(code **)(*param_1 + 8))(local_res8[0] + uVar4);
    *param_4 = (longlong)pbOutput;
    if (pbOutput == (PUCHAR)0x0) {
      DebugTraceError(0xe,"Status",
                      "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptcms\\util.c",0x78);
      return -0x7ff6fff2;
    }
    pvVar5 = (void *)(ulonglong)param_3;
    param_2 = local_res10;
    NVar3 = BCryptEncrypt((BCRYPT_KEY_HANDLE)param_1[2],local_res10,param_3,(void *)*plVar1,
                          (PUCHAR)0x0,0,pbOutput,local_res8[0],local_res8,
                          *(ULONG *)(param_1[3] + 0x48));
    if (NVar3 == 0) {
      if ((_Src != (void *)0x0) && (uVar4 != 0)) {
        memcpy((void *)((ulonglong)local_res8[0] + *param_4),_Src,(ulonglong)uVar4);
      }
      *param_5 = local_res8[0] + uVar4;
      return 0;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return NVar3;
    }
    if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
      return NVar3;
    }
    uVar6 = 0x8a;
  }
  else {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return NVar3;
    }
    if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
      return NVar3;
    }
    uVar6 = 0x70;
  }
  _Src = pvVar5;
LAB_18000df13:
  WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),param_2,_Src,"Status",(char)NVar3,
              "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptcms\\util.c",uVar6);
  return NVar3;
}



===== I_AddRecipientsAndEncodeMessage @ 18000dfc8 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

uint I_AddRecipientsAndEncodeMessage
               (int *param_1,longlong param_2,PUCHAR param_3,ULONG param_4,undefined *param_5,
               undefined8 param_6,undefined8 *param_7,undefined4 *param_8,undefined4 param_9)

{
  longlong lVar1;
  undefined8 *puVar2;
  uint uVar3;
  uint *puVar4;
  ulonglong uVar5;
  undefined1 uVar6;
  longlong lVar7;
  ulonglong uVar8;
  undefined1 uVar9;
  longlong local_48;
  longlong local_40;
  
  local_48 = 0;
  local_40 = 0;
  uVar3 = KeyProtRouter_GetSettings(&local_40);
  if (uVar3 == 0) {
    puVar4 = *(uint **)(param_2 + 8);
    uVar8 = 0;
    if (*puVar4 != 0) {
      do {
        lVar1 = *(longlong *)(puVar4 + 2);
        lVar7 = uVar8 * 0x20;
        if (*(int *)(lVar7 + lVar1) == 0) {
          uVar3 = 0x80090027;
          goto LAB_18000e268;
        }
        if (*(uint *)(lVar7 + lVar1) < 2) {
          puVar2 = *(undefined8 **)(lVar7 + 8 + lVar1);
          if ((*(int *)(puVar2 + 3) != 1) || ((int *)puVar2[2] == (int *)0x0)) {
            uVar3 = 0x80090013;
            uVar9 = 0xfb;
            uVar6 = 0x13;
            goto LAB_18000e255;
          }
          uVar3 = NCryptProtectKey((int *)puVar2[2],puVar2,param_3,param_4,param_5,param_6,&local_48
                                   ,param_9);
          if (uVar3 != 0) {
            DebugTraceError((char)uVar3,"Status",
                            "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\ncryptprotect.c"
                            ,0xb);
            if (-1 < (char)param_9) goto LAB_18000e093;
            goto LAB_18000e268;
          }
        }
        else {
          uVar5 = I_CreateAndCombinerRecipient
                            (param_2,(uint)uVar8,param_3,param_4,param_5,param_6,&local_48,param_9);
          if ((int)uVar5 != 0) {
            DebugTraceError((char)uVar5,"Status",
                            "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\ncryptprotect.c"
                            ,0xef);
LAB_18000e093:
            uVar3 = 0x80090034;
            goto LAB_18000e268;
          }
        }
        uVar5 = CMSG_AddRecipient((longlong)param_1,local_48);
        uVar3 = (uint)uVar5;
        if (uVar3 != 0) {
          uVar9 = 0x1c;
          goto LAB_18000e253;
        }
        if (local_48 != 0) {
          (**(code **)(param_5 + 0x10))();
          local_48 = 0;
        }
        puVar4 = *(uint **)(param_2 + 8);
        uVar3 = (uint)uVar8 + 1;
        uVar8 = (ulonglong)uVar3;
      } while (uVar3 < *puVar4);
    }
    lVar1 = *(longlong *)(local_40 + 0x18);
    if (lVar1 != 0) {
      puVar4 = *(uint **)(lVar1 + 8);
      uVar8 = 0;
      if (*puVar4 != 0) {
        do {
          if (*(uint *)(uVar8 * 0x20 + *(longlong *)(puVar4 + 2)) < 2) {
            puVar2 = *(undefined8 **)(uVar8 * 0x20 + 8 + *(longlong *)(puVar4 + 2));
            uVar3 = NCryptProtectKey((int *)puVar2[2],puVar2,param_3,param_4,param_5,param_6,
                                     &local_48,param_9);
            if (uVar3 != 0) {
              uVar9 = 0x54;
              goto LAB_18000e253;
            }
            uVar5 = CMSG_AddRecipient((longlong)param_1,local_48);
            uVar3 = (uint)uVar5;
            if (uVar3 != 0) {
              uVar9 = 0x5e;
              goto LAB_18000e253;
            }
            if (local_48 != 0) {
              (**(code **)(param_5 + 0x10))();
              local_48 = 0;
            }
          }
          else {
            uVar5 = I_CreateAndCombinerRecipient
                              (lVar1,(uint)uVar8,param_3,param_4,param_5,param_6,&local_48,param_9);
            uVar3 = (uint)uVar5;
            if (uVar3 != 0) {
              uVar9 = 0x40;
              goto LAB_18000e253;
            }
          }
          puVar4 = *(uint **)(lVar1 + 8);
          uVar3 = (uint)uVar8 + 1;
          uVar8 = (ulonglong)uVar3;
        } while (uVar3 < *puVar4);
      }
    }
    uVar3 = NCryptMsgEncode(param_1,param_7,param_8);
    if (uVar3 == 0) goto LAB_18000e268;
    uVar9 = 0x77;
  }
  else {
    uVar9 = 0xce;
  }
LAB_18000e253:
  uVar6 = (undefined1)uVar3;
LAB_18000e255:
  DebugTraceError(uVar6,"Status",
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\ncryptprotect.c"
                  ,uVar9);
LAB_18000e268:
  if (local_48 != 0) {
    (**(code **)(param_5 + 0x10))();
  }
  return uVar3;
}



===== NCryptMsgCreate @ 18000e2ac =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

ulonglong NCryptMsgCreate(undefined8 param_1,int *param_2,undefined8 param_3,undefined **param_4,
                         PUCHAR param_5,uint param_6,undefined8 *param_7)

{
  undefined8 uVar1;
  undefined4 *_Dst;
  longlong lVar2;
  ulonglong uVar3;
  int *piVar4;
  undefined **ppuVar5;
  PUCHAR pUVar6;
  undefined1 uVar7;
  int iVar8;
  undefined1 uVar9;
  
  if (((param_7 == (undefined8 *)0x0) || (param_2 == (int *)0x0)) || (*param_2 != 0x18)) {
    uVar3 = 0x80090027;
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0x80090027;
    }
    if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
      return 0x80090027;
    }
    uVar9 = 0x6d;
    uVar7 = 0x27;
LAB_18000e408:
    WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),param_2,param_3,"Status",uVar7,
                "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptcms\\ncryptcms.c",uVar9);
    return uVar3;
  }
  piVar4 = param_2;
  _Dst = (undefined4 *)(**(code **)(param_2 + 2))(0x170);
  if (_Dst == (undefined4 *)0x0) {
    uVar3 = 0x8009000e;
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0x8009000e;
    }
    if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
      return 0x8009000e;
    }
    uVar9 = 0x7a;
    uVar7 = 0xe;
    param_2 = piVar4;
    goto LAB_18000e408;
  }
  pUVar6 = (PUCHAR)0x170;
  memset(_Dst,0,0x170);
  *_Dst = 0x170;
  ppuVar5 = &PTR_s_1_2_840_113549_1_7_3_18001f1d0;
  _Dst[1] = 1;
  _Dst[4] = 0x18;
  *(undefined8 *)(_Dst + 6) = *(undefined8 *)(param_2 + 2);
  uVar1 = *(undefined8 *)(param_2 + 4);
  _Dst[2] = 0;
  *(undefined8 *)(_Dst + 8) = uVar1;
  lVar2 = 0;
  for (uVar3 = 0; uVar3 < 0x20; uVar3 = uVar3 + 0x20) {
    if (*(int *)((longlong)&DAT_18001f1ec + uVar3) == 3) {
      *(undefined ***)(_Dst + 0x10) = &PTR_s_1_2_840_113549_1_7_3_18001f1d0 + lVar2 * 4;
      break;
    }
    lVar2 = lVar2 + 1;
  }
  if (*(longlong *)(_Dst + 0x10) == 0) {
    uVar3 = 0x80090029;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_18000e464;
    uVar7 = 0x97;
    iVar8 = -0x7ff6ffd7;
  }
  else if ((param_4 == (undefined **)0x0) || (*(int *)param_4 != 0x40)) {
    uVar3 = 0x80090027;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_18000e464;
    uVar7 = 0xa4;
    iVar8 = -0x7ff6ffd9;
  }
  else {
    uVar3 = CMSG_InitEnveloped((longlong)_Dst,(longlong)param_4,param_5,param_6);
    iVar8 = (int)uVar3;
    uVar3 = uVar3 & 0xffffffff;
    if (iVar8 == 0) {
      *(undefined4 **)(_Dst + 0x36) = _Dst + 0x38;
      *param_7 = _Dst;
      return uVar3;
    }
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_18000e464;
    uVar7 = 0xb0;
    ppuVar5 = param_4;
    pUVar6 = param_5;
  }
  WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),ppuVar5,pUVar6,"Status",(char)iVar8,
              "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptcms\\ncryptcms.c",uVar7);
LAB_18000e464:
  I_CMsgFree((longlong)_Dst);
  return uVar3;
}



===== NCryptStreamOpenToProtect @ 18000e540 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

uint NCryptStreamOpenToProtect
               (int *param_1,uint param_2,undefined8 param_3,longlong *param_4,undefined8 *param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  uint uVar6;
  undefined8 uVar7;
  undefined8 *_Dst;
  ulonglong uVar8;
  undefined1 uVar9;
  char *pcVar10;
  char *pcVar11;
  undefined1 uVar12;
  uint local_res8 [2];
  int *local_98;
  longlong local_90;
  longlong local_88 [2];
  undefined *local_78 [2];
  uint *local_68;
  ULONG *local_60;
  
                    /* 0xe540  102  NCryptStreamOpenToProtect */
  local_88[0] = 0;
  local_90 = 0;
  _Dst = (undefined8 *)0x0;
  memset(local_78,0,0x40);
  local_98 = (int *)0x0;
  local_res8[0] = 0;
  local_78[0]._0_4_ = 0x40;
  if (((param_5 == (undefined8 *)0x0) || (param_4 == (longlong *)0x0)) || (*param_4 == 0)) {
    uVar6 = 0x80090027;
    uVar12 = 0x9d;
    uVar9 = 0x27;
  }
  else if ((param_1 == (int *)0x0) || (*param_1 != 0x28)) {
    uVar6 = 0x80090026;
    uVar12 = 0xa6;
    uVar9 = 0x26;
  }
  else {
    if ((param_2 & 0xdfffff3f) == 0) {
      uVar6 = KeyProtRouter_GetSettings(&local_90);
      lVar5 = local_90;
      if (uVar6 != 0) {
        uVar12 = 0xba;
        goto LAB_18000e8b3;
      }
      pcVar11 = (char *)0x1;
      uVar6 = *(uint *)(*(longlong *)(local_90 + 8) + 0x20);
      pcVar10 = (char *)(ulonglong)uVar6;
      uVar7 = CNG_FindBCryptOidInfo
                        (*(undefined8 *)(*(longlong *)(local_90 + 8) + 0x28),uVar6,1,local_88);
      uVar6 = (uint)uVar7;
      if (uVar6 != 0) {
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_18000e7bd;
        uVar9 = 0xc6;
        param_1 = (int *)pcVar10;
        goto LAB_18000e79d;
      }
      uVar6 = *(int *)(local_88[0] + 0x38) + 7U >> 3;
      _Dst = (undefined8 *)I_DefaultExtrenalAlloc((ulonglong)uVar6 + 0xc0);
      if (_Dst == (undefined8 *)0x0) {
        uVar6 = 0x8009000e;
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_18000e7bd;
        uVar9 = 0xd4;
        uVar6 = 0x8009000e;
      }
      else {
        memset(_Dst,0,(ulonglong)uVar6 + 0xc0);
        *_Dst = 0xc0;
        pcVar11 = (char *)(ulonglong)uVar6;
        _Dst[1] = &NCryptDefaultAllocPara;
        lVar3 = *param_4;
        uVar1 = *(undefined4 *)((longlong)param_4 + 4);
        lVar4 = param_4[1];
        uVar2 = *(undefined4 *)((longlong)param_4 + 0xc);
        *(undefined8 *)((longlong)_Dst + 0x24) = 1;
        *(int *)(_Dst + 2) = (int)lVar3;
        *(undefined4 *)((longlong)_Dst + 0x14) = uVar1;
        *(int *)(_Dst + 3) = (int)lVar4;
        *(undefined4 *)((longlong)_Dst + 0x1c) = uVar2;
        _Dst[9] = 0;
        _Dst[6] = 0;
        _Dst[0x10] = _Dst + 0x18;
        *(uint *)(_Dst + 0xf) = uVar6;
        _Dst[7] = param_3;
        *(uint *)(_Dst + 8) = param_2;
        uVar6 = BCryptGenRandom((BCRYPT_ALG_HANDLE)0x0,(PUCHAR)(_Dst + 0x18),uVar6,2);
        if (uVar6 != 0) {
          uVar12 = 0xef;
LAB_18000e8b3:
          uVar9 = (undefined1)uVar6;
          goto LAB_18000e8e1;
        }
        local_68 = (uint *)(_Dst + 10);
        _Dst[0xb] = *(undefined8 *)(*(longlong *)(lVar5 + 8) + 0x28);
        uVar6 = *(uint *)(*(longlong *)(lVar5 + 8) + 0x20);
        *local_68 = uVar6;
        pcVar10 = &NCryptDefaultAllocPara;
        _Dst[0xe] = *(undefined8 *)(lVar5 + 8);
        local_60 = (ULONG *)(_Dst + 0xf);
        uVar8 = NCryptMsgCreate((ulonglong)uVar6,(int *)&NCryptDefaultAllocPara,pcVar11,local_78,
                                (PUCHAR)0x0,0,_Dst + 9);
        uVar6 = (uint)uVar8;
        if (uVar6 == 0) {
          pcVar11 = (char *)_Dst[0x10];
          uVar6 = I_AddRecipientsAndEncodeMessage
                            ((int *)_Dst[9],(longlong)param_1,(PUCHAR)pcVar11,*(ULONG *)(_Dst + 0xf)
                             ,&NCryptDefaultAllocPara,_Dst[7],&local_98,local_res8,
                             *(undefined4 *)(_Dst + 8));
          if (uVar6 == 0) {
            pcVar11 = (char *)(ulonglong)local_res8[0];
            pcVar10 = (char *)local_98;
            uVar6 = (*(code *)*param_4)(param_4[1],local_98,pcVar11,0);
            if (uVar6 == 0) {
              *param_5 = _Dst;
              _Dst = (undefined8 *)0x0;
              goto LAB_18000e7bd;
            }
            uVar12 = 0x2a;
            goto LAB_18000e8b3;
          }
          pcVar10 = (char *)param_1;
          if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
             ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_18000e7bd;
          uVar9 = 0x1a;
        }
        else {
          if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
             ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_18000e7bd;
          uVar9 = 9;
          param_1 = (int *)pcVar10;
        }
LAB_18000e79d:
        pcVar10 = (char *)param_1;
      }
      pcVar11 = "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\stream.c";
      WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),pcVar10,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\stream.c",
                  "Status",(char)uVar6,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\stream.c",uVar9
                 );
      goto LAB_18000e7bd;
    }
    uVar6 = 0x80090009;
    uVar12 = 0xad;
    uVar9 = 9;
  }
LAB_18000e8e1:
  pcVar11 = "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\stream.c";
  pcVar10 = "Status";
  DebugTraceError(uVar9,"Status",
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\stream.c",
                  uVar12);
LAB_18000e7bd:
  if (local_98 != (int *)0x0) {
    I_DefaultExtrenalFree(local_98);
  }
  if (_Dst != (undefined8 *)0x0) {
    I_StreamFree((longlong)_Dst,pcVar10,pcVar11);
  }
  return uVar6;
}



===== I_DefaultExtrenalAlloc @ 18000e910 =====

void I_DefaultExtrenalAlloc(SIZE_T param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00018000e918. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  LocalAlloc(0x40,param_1);
  return;
}



===== NCryptStreamUpdate @ 18000e930 =====

ulonglong NCryptStreamUpdate(longlong *param_1,int *param_2,ulonglong *param_3,int param_4)

{
  longlong lVar1;
  uint uVar2;
  void *_Dst;
  ulonglong uVar3;
  undefined1 uVar4;
  uint uVar5;
  size_t _Size;
  undefined1 uVar6;
  int iVar7;
  int *piVar8;
  ulonglong uVar9;
  ulonglong *puVar10;
  int local_res8 [2];
  ulonglong local_78 [2];
  longlong local_68;
  ulonglong local_60;
  longlong local_58;
  longlong local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  
                    /* 0xe930  105  NCryptStreamUpdate */
  if ((param_1 == (longlong *)0x0) || (*param_1 != 0xc0)) {
    uVar3 = 0x80090026;
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0x80090026;
    }
    if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
      return 0x80090026;
    }
    uVar4 = 0x42;
    uVar2 = 0x80090026;
    goto LAB_18000eb44;
  }
  if ((int)param_1[5] != 0) {
    uVar3 = 0x80090026;
    uVar6 = 0x49;
    uVar4 = 0x26;
    goto LAB_18000eccc;
  }
  *(int *)(param_1 + 5) = param_4;
  uVar3 = param_1[6] + (longlong)param_3;
  if (uVar3 < (ulonglong)param_1[6]) {
    uVar3 = 0xc0000095;
    uVar6 = 0x56;
    uVar4 = 0x95;
    goto LAB_18000eccc;
  }
  param_1[6] = uVar3;
  if ((*(int *)((longlong)param_1 + 0x24) != 0) || (param_1[9] != 0)) goto LAB_18000eafb;
  if (param_1[0x12] == 0) {
    uVar2 = *(uint *)(param_1 + 0x15);
    uVar5 = 0x11 - uVar2;
    piVar8 = param_2;
    puVar10 = param_3;
    if (uVar5 != 0) {
      _Size = (ulonglong)param_3 & 0xffffffff;
      if ((ulonglong *)(ulonglong)uVar5 <= param_3) {
        _Size = (size_t)uVar5;
      }
      memcpy((void *)((ulonglong)uVar2 + param_1[0x14]),param_2,_Size);
      *(int *)(param_1 + 0x15) = (int)param_1[0x15] + (int)_Size;
      piVar8 = (int *)((longlong)param_2 + _Size);
      uVar2 = *(uint *)(param_1 + 0x15);
      puVar10 = (ulonglong *)((longlong)param_3 - _Size);
    }
    if (uVar2 < 2) {
      return 0;
    }
    local_68 = param_1[0x14];
    param_2 = local_res8;
    local_res8[0] = 0;
    local_78[0] = 0;
    local_48 = 0;
    local_40 = 0;
    local_60 = (ulonglong)uVar2;
    param_3 = local_78;
    local_50 = local_60 + local_68;
    local_38 = 0;
    uStack_30 = 0;
    local_58 = local_68;
    uVar2 = Ordinal_37(&local_68);
    uVar3 = (ulonglong)uVar2;
    if (uVar2 == 0) {
      if ((local_res8[0] != 0x20000010) || (0x7ffffff0 < local_78[0])) {
        uVar3 = 0x80090005;
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return 0x80090005;
        }
        if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
          return 0x80090005;
        }
        uVar4 = 0xae;
        uVar2 = 0x80090005;
LAB_18000eb44:
        WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),param_2,param_3,"Status",(char)uVar2,
                    "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\stream.c",
                    uVar4);
        return uVar3;
      }
      uVar2 = ((int)local_78[0] - (int)local_68) + (int)local_58;
      *(uint *)((longlong)param_1 + 0x9c) = uVar2;
      _Dst = (void *)I_DefaultExtrenalAlloc((ulonglong)uVar2);
      param_1[0x12] = (longlong)_Dst;
      if (_Dst == (void *)0x0) {
        uVar3 = 0x8009000e;
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return 0x8009000e;
        }
        if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
          return 0x8009000e;
        }
        uVar4 = 0xbe;
        uVar2 = 0x8009000e;
        goto LAB_18000eb44;
      }
      memcpy(_Dst,(void *)param_1[0x14],(ulonglong)*(uint *)(param_1 + 0x15));
      *(uint *)(param_1 + 0x13) = *(uint *)(param_1 + 0x15);
      memset((void *)param_1[0x14],0,(ulonglong)*(uint *)(param_1 + 0x15));
      param_2 = piVar8;
      param_3 = puVar10;
      goto LAB_18000eaa1;
    }
    if ((param_4 == 0) && ((ulonglong)param_1[6] < 7)) {
      return 0;
    }
    uVar6 = 0x9d;
  }
  else {
LAB_18000eaa1:
    uVar3 = (ulonglong)*(uint *)(param_1 + 0x13);
    uVar5 = *(int *)((longlong)param_1 + 0x9c) - *(uint *)(param_1 + 0x13);
    uVar2 = (uint)param_3;
    if ((ulonglong *)(ulonglong)uVar5 <= param_3) {
      uVar2 = uVar5;
    }
    if (uVar2 != 0) {
      memcpy((void *)(uVar3 + param_1[0x12]),param_2,(ulonglong)uVar2);
      *(uint *)(param_1 + 0x13) = (int)param_1[0x13] + uVar2;
      param_2 = (int *)((longlong)param_2 + (ulonglong)uVar2);
      uVar3 = (ulonglong)*(uint *)(param_1 + 0x13);
      param_3 = (ulonglong *)((longlong)param_3 - (ulonglong)uVar2);
    }
    if ((uint)uVar3 < *(uint *)((longlong)param_1 + 0x9c)) {
      return 0;
    }
    uVar2 = I_StreamOpenProtectedMessage((longlong)param_1,uVar3,param_4);
    uVar3 = (ulonglong)uVar2;
    if (uVar2 == 0) {
      lVar1 = param_1[0x11];
      param_1[9] = *(longlong *)(lVar1 + 0x18);
      if ((*(uint *)(param_1 + 8) & 1) != 0) {
LAB_18000eafb:
        piVar8 = param_2;
        puVar10 = param_3;
        if ((*(uint *)(param_1 + 8) & 1) == 0) {
          do {
            param_3 = (ulonglong *)((ulonglong)puVar10 & 0xffffffff);
            uVar9 = (ulonglong)puVar10 & 0xffffffff;
            puVar10 = (ulonglong *)((longlong)puVar10 - (longlong)param_3);
            if ((param_4 == 0) || (puVar10 != (ulonglong *)0x0)) {
              iVar7 = 0;
            }
            else {
              iVar7 = 1;
            }
            param_2 = piVar8;
            uVar2 = CMSG_UpdateStream((longlong)param_1,piVar8,(ulonglong)param_3,iVar7);
            uVar3 = (ulonglong)uVar2;
            if (uVar2 != 0) {
              if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
                return uVar3;
              }
              if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
                return uVar3;
              }
              uVar4 = 0x3e;
              goto LAB_18000eb44;
            }
            piVar8 = (int *)((longlong)piVar8 + uVar9);
          } while (puVar10 != (ulonglong *)0x0);
        }
        return 0;
      }
      uVar3 = CMSG_ImportContentEncryptionKey
                        (*(longlong *)(lVar1 + 0x18),(uint *)(*(longlong *)(lVar1 + 0x20) + 0x48),
                         (PUCHAR)param_1[0x16],*(uint *)(param_1 + 0x17));
      uVar2 = (uint)uVar3;
      uVar3 = uVar3 & 0xffffffff;
      if (uVar2 == 0) {
        uVar2 = *(uint *)(*(longlong *)(param_1[0x11] + 0x20) + 0x70);
        if (uVar2 == 0) goto LAB_18000eafb;
        if ((param_3 != (ulonglong *)0x0) || (param_4 == 0)) {
          uVar3 = 0x80090005;
          uVar6 = 0x18;
          uVar4 = 5;
          goto LAB_18000eccc;
        }
        uVar2 = CMSG_UpdateStream((longlong)param_1,
                                  *(void **)(*(longlong *)(param_1[0x11] + 0x20) + 0x78),
                                  (ulonglong)uVar2,1);
        uVar3 = (ulonglong)uVar2;
        if (uVar2 == 0) {
          return 0;
        }
        uVar6 = 0x24;
      }
      else {
        uVar6 = 0xb;
      }
    }
    else {
      uVar6 = 0xf9;
    }
  }
  uVar4 = (undefined1)uVar2;
LAB_18000eccc:
  DebugTraceError(uVar4,"Status",
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\stream.c",uVar6
                 );
  return uVar3;
}



===== CMSG_UpdateStream @ 18000edcc =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

int CMSG_UpdateStream(longlong param_1,void *param_2,ulonglong param_3,int param_4)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  PUCHAR _Dst;
  PUCHAR pUVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  ulonglong uVar9;
  PUCHAR pUVar10;
  uint uVar11;
  void *local_res10;
  uint local_res18;
  undefined1 uVar12;
  ULONG local_58;
  uint local_54;
  
  local_res18 = (uint)param_3;
  local_58 = 0;
  lVar2 = *(longlong *)(param_1 + 0x48);
  local_54 = 0;
  uVar1 = *(uint *)(*(longlong *)(lVar2 + 0x70) + 0x3c);
  if ((*(uint *)(lVar2 + 200) & 0x10000000) != 0) {
    local_54 = *(uint *)(*(longlong *)(lVar2 + 0xa0) + 0x30);
  }
  uVar6 = local_54;
  _Dst = *(PUCHAR *)(lVar2 + 0xb8);
  if (_Dst == (PUCHAR)0x0) {
    pUVar5 = (PUCHAR)(0x1000 % (ulonglong)uVar1);
    iVar4 = local_54 + ((int)(0x1000 / (ulonglong)uVar1) + 2) * uVar1 * 2;
    *(int *)(lVar2 + 0xc4) = iVar4;
    uVar9 = param_3;
    _Dst = (PUCHAR)(**(code **)(lVar2 + 0x18))(iVar4);
    *(PUCHAR *)(lVar2 + 0xb8) = _Dst;
    if (_Dst == (PUCHAR)0x0) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return -0x7ff6fff2;
      }
      if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
        return -0x7ff6fff2;
      }
      uVar12 = 0x66;
      iVar4 = -0x7ff6fff2;
LAB_18000f05a:
      WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),pUVar5,uVar9,"Status",(char)iVar4,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptcms\\cmsg.c",uVar12);
      return iVar4;
    }
    *(uint *)(lVar2 + 200) = *(uint *)(lVar2 + 200) | 0x10;
    *(undefined4 *)(lVar2 + 0xc0) = 0;
    param_3 = param_3 & 0xffffffff;
  }
  uVar11 = (*(int *)(lVar2 + 0xc4) - uVar1 >> 1) - uVar6;
  pUVar10 = _Dst + uVar11;
  local_res10 = param_2;
  if (*(int *)(lVar2 + 4) == 0) {
    pUVar10 = pUVar10 + uVar6;
  }
  do {
    uVar9 = (ulonglong)*(uint *)(lVar2 + 0xc0);
    uVar3 = uVar11 - *(uint *)(lVar2 + 0xc0);
    uVar8 = (uint)param_3;
    if (uVar3 <= (uint)param_3) {
      uVar8 = uVar3;
    }
    if (uVar8 != 0) {
      memcpy(_Dst + uVar9,local_res10,(ulonglong)uVar8);
      *(int *)(lVar2 + 0xc0) = *(int *)(lVar2 + 0xc0) + uVar8;
      local_res10 = (void *)((longlong)local_res10 + (ulonglong)uVar8);
      uVar9 = (ulonglong)*(uint *)(lVar2 + 0xc0);
      local_res18 = local_res18 - uVar8;
      param_3 = (ulonglong)local_res18;
      uVar6 = local_54;
    }
    uVar8 = (uint)uVar9;
    if ((param_4 == 0) || ((uint)param_3 != 0)) {
      iVar7 = 0;
      uVar8 = uVar8 - (int)(uVar9 % (ulonglong)uVar1);
      if ((uint)param_3 < uVar1 + uVar6) {
        if (uVar1 < uVar8) {
          uVar8 = uVar8 - uVar1;
          goto LAB_18000eec2;
        }
      }
      else {
LAB_18000eec2:
        if (uVar1 < uVar8) goto LAB_18000eed5;
      }
    }
    else {
      iVar7 = 1;
LAB_18000eed5:
      uVar9 = (ulonglong)uVar8;
      pUVar5 = _Dst;
      if (*(int *)(lVar2 + 4) == 0) {
        iVar4 = CNG_Decrypt(lVar2 + 0x58,_Dst,uVar8,pUVar10,uVar11 + uVar1,&local_58,iVar7);
      }
      else {
        iVar4 = CNG_Encrypt(lVar2 + 0x58,_Dst,uVar8,pUVar10,uVar11 + uVar1 + uVar6,&local_58,iVar7);
      }
      if (iVar4 != 0) {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return iVar4;
        }
        if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
          return iVar4;
        }
        uVar12 = 0xc1;
        goto LAB_18000f05a;
      }
      if (uVar8 < *(uint *)(lVar2 + 0xc0)) {
        memmove(_Dst,_Dst + uVar8,(ulonglong)(*(uint *)(lVar2 + 0xc0) - uVar8));
      }
      *(int *)(lVar2 + 0xc0) = *(int *)(lVar2 + 0xc0) - uVar8;
      *(longlong *)(lVar2 + 0x28) = *(longlong *)(lVar2 + 0x28) + (ulonglong)uVar8;
      if (*(int *)(param_1 + 0x20) == 0) {
        iVar4 = (**(code **)(param_1 + 0x10))();
      }
      else {
        iVar4 = (**(code **)(param_1 + 0x10))
                          (*(undefined8 *)(param_1 + 0x18),pUVar10,local_58,
                           *(undefined8 *)(param_1 + 0x88),iVar7);
      }
      if (iVar4 != 0) {
        DebugTraceError((char)iVar4,"Status",
                        "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptcms\\cmsg.c",0xe2)
        ;
        return iVar4;
      }
      param_3 = (ulonglong)local_res18;
      uVar6 = local_54;
    }
    if ((int)param_3 == 0) {
      return 0;
    }
  } while( true );
}



===== CNG_Encrypt @ 18000f0fc =====

NTSTATUS CNG_Encrypt(longlong param_1,PUCHAR param_2,ULONG param_3,PUCHAR param_4,uint param_5,
                    ULONG *param_6,int param_7)

{
  longlong lVar1;
  uint uVar2;
  NTSTATUS NVar3;
  void *_Src;
  uint uVar4;
  ULONG dwFlags;
  PUCHAR pbIV;
  ULONG cbIV;
  undefined1 uVar5;
  
  pbIV = (PUCHAR)0x0;
  dwFlags = 0;
  cbIV = 0;
  _Src = (void *)0x0;
  uVar4 = 0;
  if ((*(uint *)(param_1 + 0x70) & 0x10000000) == 0) {
    if (param_7 != 0) {
      dwFlags = *(ULONG *)(*(longlong *)(param_1 + 0x18) + 0x48);
    }
  }
  else {
    lVar1 = *(longlong *)(param_1 + 0x48);
    if (*(uint *)(param_1 + 0x40) < 0x98) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return -0x7ff6ffd3;
      }
      if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
        return -0x7ff6ffd3;
      }
      uVar5 = 0xed;
      NVar3 = -0x7ff6ffd3;
      goto LAB_18000f204;
    }
    pbIV = *(PUCHAR *)(lVar1 + 0x88);
    cbIV = *(ULONG *)(lVar1 + 0x90);
    *(longlong *)(lVar1 + 0x38) = lVar1 + 0x74;
    *(undefined4 *)(lVar1 + 0x40) = 0x10;
    if (param_7 == 0) {
      uVar2 = *(uint *)(lVar1 + 0x50) | 1;
    }
    else {
      _Src = *(void **)(lVar1 + 0x28);
      uVar2 = *(uint *)(lVar1 + 0x50) & 0xfffffffe;
      uVar4 = *(uint *)(lVar1 + 0x30);
    }
    *(uint *)(lVar1 + 0x50) = uVar2;
  }
  NVar3 = BCryptEncrypt(*(BCRYPT_KEY_HANDLE *)(param_1 + 0x10),param_2,param_3,
                        *(void **)(param_1 + 0x48),pbIV,cbIV,param_4,param_5,param_6,dwFlags);
  if (NVar3 == 0) {
    if ((_Src != (void *)0x0) && (uVar4 != 0)) {
      if (param_4 != (PUCHAR)0x0) {
        if (param_5 < *param_6 + uVar4) {
          DebugTraceError(0x28,"Status",
                          "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptcms\\util.c",
                          0x25);
          return -0x7ff6ffd8;
        }
        memcpy(param_4 + *param_6,_Src,(ulonglong)uVar4);
      }
      *param_6 = *param_6 + uVar4;
    }
    return 0;
  }
  if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
    return NVar3;
  }
  if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
    return NVar3;
  }
  uVar5 = 0x19;
LAB_18000f204:
  WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),param_2,
              "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptcms\\util.c","Status",
              (char)NVar3,"onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptcms\\util.c",
              uVar5);
  return NVar3;
}



===== I_StreamOpenProtectedMessage @ 18000f2f4 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

HRESULT I_StreamOpenProtectedMessage(longlong param_1,ulonglong param_2,undefined4 param_3)

{
  HRESULT HVar1;
  ulonglong uVar2;
  char *hMem;
  int *piVar3;
  char *pcVar4;
  char *pcVar5;
  uint uVar6;
  int *local_res8;
  ulonglong local_res10 [2];
  char *local_res20;
  
  local_res8 = (int *)0x0;
  pcVar5 = "\x18";
  local_res20 = (char *)0x0;
  local_res10[0] = param_2 & 0xffffffff00000000;
  HVar1 = I_GetProtectionDescriptor
                    (*(undefined8 *)(param_1 + 0x90),*(undefined4 *)(param_1 + 0x9c),
                     (int *)&NCryptDefaultAllocPara,&local_res8);
  piVar3 = local_res8;
  if (HVar1 != 0) {
    pcVar5 = "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\ncryptprotect.c";
    hMem = "Status";
    DebugTraceError((char)HVar1,"Status",
                    "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\ncryptprotect.c"
                    ,0xdd);
    piVar3 = local_res8;
    goto LAB_18000f444;
  }
  if (*(int *)(param_1 + 0x20) != 0) {
    pcVar5 = (char *)0x0;
    HVar1 = (**(code **)(param_1 + 0x10))(*(undefined8 *)(param_1 + 0x18),0,0,local_res8,param_3);
    if (HVar1 != 0) {
      pcVar5 = "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\ncryptprotect.c";
      hMem = "Status";
      DebugTraceError((char)HVar1,"Status",
                      "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\ncryptprotect.c"
                      ,0xf0);
      goto LAB_18000f444;
    }
  }
  pcVar4 = (char *)0x0;
  uVar6 = 0;
  if ((*(uint *)(param_1 + 0x40) & 1) == 0) {
    pcVar5 = "\x18";
    HVar1 = I_GetContentEncryptKey
                      ((longlong)piVar3,*(uint *)(param_1 + 0x40),&NCryptDefaultAllocPara,
                       *(undefined8 *)(param_1 + 0x38),&local_res20,(uint *)local_res10);
    if (HVar1 == 0) {
      pcVar4 = local_res20;
      uVar6 = (uint)local_res10[0];
      goto LAB_18000f414;
    }
    pcVar5 = "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\ncryptprotect.c";
    DebugTraceError((char)HVar1,"Status",
                    "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\ncryptprotect.c"
                    ,0);
    hMem = local_res20;
    uVar6 = (uint)local_res10[0];
  }
  else {
LAB_18000f414:
    *(int **)(param_1 + 0x88) = piVar3;
    piVar3 = (int *)0x0;
    hMem = (char *)0x0;
    *(char **)(param_1 + 0xb0) = pcVar4;
    *(uint *)(param_1 + 0xb8) = uVar6;
  }
  if (hMem != (char *)0x0) {
    pcVar4 = hMem;
    for (uVar2 = (ulonglong)uVar6; uVar2 != 0; uVar2 = uVar2 - 1) {
      *pcVar4 = '\0';
      pcVar4 = pcVar4 + 1;
    }
    I_DefaultExtrenalFree(hMem);
  }
LAB_18000f444:
  if (piVar3 != (int *)0x0) {
    NCryptCloseProtectionDescriptor(piVar3,hMem,pcVar5);
  }
  return HVar1;
}



===== I_CMsgFree @ 18000f46c =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void I_CMsgFree(longlong param_1)

{
  uint uVar1;
  
  if (*(int *)(param_1 + 4) == 0) {
    if (*(longlong *)(param_1 + 0xd0) != 0) {
      (**(code **)(param_1 + 0x20))();
    }
    if (*(longlong *)(param_1 + 0x38) != 0) {
      (**(code **)(param_1 + 0x20))();
    }
  }
  CNG_DestroyBCryptKeyAndAlgorithmInfo((longlong *)(param_1 + 0x58));
  if (*(longlong *)(param_1 + 0x48) != 0) {
    while( true ) {
      if (*(int *)(param_1 + 0x50) == 0) break;
      uVar1 = *(int *)(param_1 + 0x50) - 1;
      *(uint *)(param_1 + 0x50) = uVar1;
      (**(code **)(param_1 + 0x20))
                (*(undefined8 *)(*(longlong *)(param_1 + 0x48) + (ulonglong)uVar1 * 8));
    }
    *(undefined4 *)(param_1 + 0x50) = 0xffffffff;
    (**(code **)(param_1 + 0x20))();
  }
  (**(code **)(param_1 + 0x20))(param_1);
  return;
}



===== CNG_DestroyBCryptKeyAndAlgorithmInfo @ 18000f504 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

NTSTATUS CNG_DestroyBCryptKeyAndAlgorithmInfo(longlong *param_1)

{
  NTSTATUS NVar1;
  
  NVar1 = 0;
  if (((*(uint *)(param_1 + 0xe) & 1) != 0) && (param_1[0xb] != 0)) {
    (**(code **)(*param_1 + 0x10))();
  }
  if (((*(uint *)(param_1 + 0xe) & 2) != 0) && (param_1[7] != 0)) {
    (**(code **)(*param_1 + 0x10))();
  }
  if (((*(uint *)(param_1 + 0xe) & 8) != 0) && (param_1[9] != 0)) {
    (**(code **)(*param_1 + 0x10))();
  }
  if (((*(uint *)(param_1 + 0xe) & 4) != 0) && ((void *)param_1[5] != (void *)0x0)) {
    memset((void *)param_1[5],0,(ulonglong)*(uint *)(param_1 + 4));
    (**(code **)(*param_1 + 0x10))(param_1[5]);
  }
  if (((*(uint *)(param_1 + 0xe) & 0x10) != 0) && (param_1[0xc] != 0)) {
    (**(code **)(*param_1 + 0x10))();
  }
  if ((BCRYPT_KEY_HANDLE)param_1[2] != (BCRYPT_KEY_HANDLE)0x0) {
    NVar1 = BCryptDestroyKey((BCRYPT_KEY_HANDLE)param_1[2]);
  }
  memset(param_1,0,0x78);
  return NVar1;
}



===== NCryptStreamOpenToUnprotect @ 18000f610 =====

ulonglong NCryptStreamOpenToUnprotect
                    (longlong *param_1,longlong *param_2,longlong *param_3,longlong *param_4)

{
  ulonglong uVar1;
  ulonglong uVar2;
  longlong lVar3;
  longlong *plVar4;
  longlong local_res20;
  
                    /* 0xf610  103  NCryptStreamOpenToUnprotect */
  lVar3 = 0;
  local_res20 = 0;
  if (((param_4 == (longlong *)0x0) || (param_1 == (longlong *)0x0)) || (*param_1 == 0)) {
    uVar2 = 0x80090027;
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0x80090027;
    }
    if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
      return 0x80090027;
    }
    plVar4 = param_3;
    WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),param_2,param_3,"Status",0x27,
                "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\stream.c",0xa1);
    param_3 = param_2;
  }
  else {
    if (((ulonglong)param_2 & 0xdfffff3f) != 0) {
      DebugTraceError(9,"Status",
                      "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\stream.c",
                      0xa8);
      return 0x80090009;
    }
    plVar4 = &local_res20;
    uVar1 = I_StreamOpenToUnprotect((int)param_2,param_3,plVar4);
    uVar2 = uVar1 & 0xffffffff;
    if ((int)uVar1 == 0) {
      lVar3 = param_1[1];
      *(longlong *)(local_res20 + 0x10) = *param_1;
      *(longlong *)(local_res20 + 0x18) = lVar3;
      *(undefined4 *)(local_res20 + 0x20) = 0;
      *param_4 = local_res20;
      return 0;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),param_3,plVar4,"Status",(char)uVar1,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\stream.c",0xaf)
      ;
    }
    lVar3 = local_res20;
  }
  if (lVar3 != 0) {
    I_StreamFree(lVar3,param_3,(undefined *)plVar4);
  }
  return uVar2;
}



===== I_StreamOpenToUnprotect @ 18000f76c =====

undefined8 I_StreamOpenToUnprotect(undefined4 param_1,undefined8 param_2,undefined8 *param_3)

{
  undefined8 *_Dst;
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  
  uVar1 = param_2;
  puVar3 = param_3;
  _Dst = (undefined8 *)I_DefaultExtrenalAlloc(0xd1);
  uVar2 = 0;
  if (_Dst == (undefined8 *)0x0) {
    uVar2 = 0x8009000e;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),uVar1,puVar3,"Status",0xe,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\stream.c",0x59)
      ;
    }
  }
  else {
    memset(_Dst,0,0xd1);
    *_Dst = 0xc0;
    _Dst[1] = &NCryptDefaultAllocPara;
    _Dst[0x14] = _Dst + 0x18;
    _Dst[7] = param_2;
    *(undefined4 *)(_Dst + 8) = param_1;
    *param_3 = _Dst;
  }
  return uVar2;
}



===== CNG_Decrypt @ 18000f850 =====

NTSTATUS CNG_Decrypt(longlong param_1,PUCHAR param_2,ULONG param_3,PUCHAR param_4,ULONG param_5,
                    ULONG *param_6,int param_7)

{
  longlong lVar1;
  NTSTATUS NVar2;
  undefined1 uVar3;
  PUCHAR pbIV;
  ULONG cbIV;
  undefined1 uVar4;
  ULONG dwFlags;
  
  dwFlags = 0;
  pbIV = (PUCHAR)0x0;
  cbIV = 0;
  if ((*(uint *)(param_1 + 0x70) & 0x10000000) == 0) {
    if (param_7 != 0) {
      dwFlags = *(ULONG *)(*(longlong *)(param_1 + 0x18) + 0x48);
    }
  }
  else {
    lVar1 = *(longlong *)(param_1 + 0x48);
    if (*(uint *)(param_1 + 0x40) < 0x98) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return -0x7ff6ffd3;
      }
      if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
        return -0x7ff6ffd3;
      }
      WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),param_2,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptcms\\util.c","Status",
                  0x2d,"onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptcms\\util.c",0xbd);
      return -0x7ff6ffd3;
    }
    pbIV = *(PUCHAR *)(lVar1 + 0x88);
    cbIV = *(ULONG *)(lVar1 + 0x90);
    *(longlong *)(lVar1 + 0x38) = lVar1 + 0x74;
    *(undefined4 *)(lVar1 + 0x40) = 0x10;
    if (param_7 == 0) {
      *(uint *)(lVar1 + 0x50) = *(uint *)(lVar1 + 0x50) | 1;
    }
    else {
      if (*(longlong *)(lVar1 + 0x28) == 0) {
        if (param_3 < *(uint *)(lVar1 + 0x30)) {
          NVar2 = -0x7ff6fffb;
          uVar4 = 0xd6;
          uVar3 = 5;
          goto LAB_18000f98c;
        }
        param_3 = param_3 - *(int *)(lVar1 + 0x30);
        *(PUCHAR *)(lVar1 + 0x28) = param_2 + param_3;
      }
      *(uint *)(lVar1 + 0x50) = *(uint *)(lVar1 + 0x50) & 0xfffffffe;
    }
  }
  NVar2 = BCryptDecrypt(*(BCRYPT_KEY_HANDLE *)(param_1 + 0x10),param_2,param_3,
                        *(void **)(param_1 + 0x48),pbIV,cbIV,param_4,param_5,param_6,dwFlags);
  if (NVar2 == 0) {
    return 0;
  }
  uVar4 = 0xfb;
  uVar3 = (undefined1)NVar2;
LAB_18000f98c:
  DebugTraceError(uVar3,"Status",
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptcms\\util.c",uVar4);
  return NVar2;
}



===== SslExpandWriteKey @ 18000f9d0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void SslExpandWriteKey(uint *param_1,uint *param_2,undefined8 *param_3,undefined8 param_4,
                      undefined4 param_5)

{
  uint uVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  uint *puVar4;
  undefined8 *puVar5;
  
                    /* 0xf9d0  136  SslExpandWriteKey */
  if ((((param_1 == (uint *)0x0) || (*param_1 < 0x1b0)) || (param_1[1] != 0x44444441)) ||
     (param_1[3] != 0)) {
    param_1 = (uint *)0x0;
  }
  if (((param_2 == (uint *)0x0) || (*param_2 < 0x20)) ||
     (puVar4 = param_2, param_2[1] != 0x44444442)) {
    puVar4 = (uint *)0x0;
  }
  if ((param_1 == (uint *)0x0) || (puVar4 == (uint *)0x0)) {
    uVar1 = 0x80090026;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),param_2,param_3,"Status",0x26,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",0xfb);
    }
  }
  else if (param_3 == (undefined8 *)0x0) {
    uVar1 = 0x80090027;
    DebugTraceError(0x27,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",2);
  }
  else if ((ushort)param_1[8] < 4) {
    uVar1 = 0x80090029;
    DebugTraceError(0x29,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",0xd);
  }
  else {
    puVar2 = (undefined8 *)
             RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,0x20);
    if (puVar2 == (undefined8 *)0x0) {
      uVar1 = 0x8009000e;
      DebugTraceError(0xe,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",0x19
                     );
    }
    else {
      puVar5 = puVar2 + 2;
      *puVar2 = 0;
      puVar2[1] = 0;
      puVar2[2] = 0;
      puVar2[3] = 0;
      uVar3 = *(undefined8 *)(puVar4 + 4);
      uVar1 = (**(code **)(param_1 + 0x4e))
                        (*(undefined8 *)(param_1 + 0x6a),uVar3,puVar5,param_4,param_5);
      if ((int)uVar1 < 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
          WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),uVar3,puVar5,"Status",(char)uVar1,
                      "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",0x2a);
        }
        SafeAllocaFreeToHeap(puVar2);
      }
      else {
        *(undefined4 *)puVar2 = 0x20;
        *(undefined8 *)((longlong)puVar2 + 4) = 0x44444442;
        *(undefined4 *)((longlong)puVar2 + 0xc) = 1;
        puVar2[3] = param_1;
        *param_3 = puVar2;
        LOCK();
        param_1[4] = param_1[4] + 1;
        UNLOCK();
        uVar1 = 0;
      }
    }
  }
  NormalizeNteStatus(uVar1);
  return;
}



===== NCryptDeleteKey @ 18000fc20 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

SECURITY_STATUS __stdcall NCryptDeleteKey(NCRYPT_KEY_HANDLE hKey,DWORD dwFlags)

{
  undefined *puVar1;
  uint uVar2;
  int *piVar3;
  longlong lVar4;
  undefined4 in_register_00000014;
  undefined8 uVar5;
  int *piVar6;
  undefined8 in_R8;
  
                    /* 0xfc20  71  NCryptDeleteKey */
  uVar5 = CONCAT44(in_register_00000014,dwFlags);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    uVar5 = 0x13;
    WPP_SF_PD(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x13,in_R8,hKey,(char)dwFlags);
  }
  puVar1 = WPP_GLOBAL_Control;
  piVar3 = ValidateClientKeyHandle((int *)hKey);
  if (piVar3 == (int *)0x0) {
    uVar2 = 0x80090026;
    if (((undefined **)puVar1 != &WPP_GLOBAL_Control) && ((puVar1[0x1c] & 1) != 0)) {
      WPP_SF_sDsd(*(undefined8 *)(puVar1 + 0x10),uVar5,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c","Status",0x26
                  ,"onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",0x35);
    }
  }
  else {
    do {
      CertInUseMetadataCleanup((undefined8 *)(piVar3 + 10));
      uVar2 = (**(code **)(*(longlong *)(piVar3 + 2) + 0x58))
                        (*(undefined8 *)(*(longlong *)(piVar3 + 2) + 0x110),
                         *(undefined8 *)(piVar3 + 4),dwFlags);
      if (uVar2 != 0x8009002e) break;
      if ((dwFlags & 0x40) != 0) {
        uVar2 = 0x80090022;
        DebugTraceError(0x22,"Status",
                        "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",0x4e);
        goto LAB_18000fda9;
      }
      uVar2 = (**(code **)(*(longlong *)(piVar3 + 2) + 0xc0))
                        (*(undefined8 *)(*(longlong *)(piVar3 + 2) + 0x110),hKey,L"NCryptDeleteKey",
                         0);
    } while (uVar2 == 0);
    if (uVar2 == 0) {
      DereferenceProvider(*(longlong *)(piVar3 + 2));
      piVar6 = piVar3;
      for (lVar4 = 0x30; lVar4 != 0; lVar4 = lVar4 + -1) {
        *(undefined1 *)piVar6 = 0;
        piVar6 = (int *)((longlong)piVar6 + 1);
      }
      SafeAllocaFreeToHeap(piVar3);
      uVar2 = 0;
    }
    else {
      uVar5 = 0x860;
      DebugTraceError((char)uVar2,"Status",
                      "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",0x60);
      EtwLogNCryptOperationFailed
                (3,*(wchar_t **)(*(longlong *)(piVar3 + 2) + 0x118),*(wchar_t **)(piVar3 + 6),uVar5,
                 (char)uVar2);
    }
  }
LAB_18000fda9:
  uVar2 = NormalizeNteStatus(uVar2);
  return uVar2;
}



===== NCryptEncrypt @ 18000fdd0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

SECURITY_STATUS __stdcall
NCryptEncrypt(NCRYPT_KEY_HANDLE hKey,PBYTE pbInput,DWORD cbInput,void *pPaddingInfo,PBYTE pbOutput,
             DWORD cbOutput,DWORD *pcbResult,DWORD dwFlags)

{
  uint uVar1;
  int *piVar2;
  PBYTE pBVar3;
  undefined4 in_register_00000084;
  ulonglong uVar4;
  undefined8 uVar5;
  undefined **ppuVar6;
  
                    /* 0xfdd0  75  NCryptEncrypt */
  uVar4 = CONCAT44(in_register_00000084,cbInput);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    WPP_SF_PD(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x16,uVar4,hKey,(char)dwFlags);
    uVar4 = (ulonglong)cbInput;
  }
  pBVar3 = pbInput;
  ppuVar6 = (undefined **)WPP_GLOBAL_Control;
  piVar2 = ValidateClientKeyHandle((int *)hKey);
  if (piVar2 == (int *)0x0) {
    uVar1 = 0x80090026;
    if ((ppuVar6 != &WPP_GLOBAL_Control) && ((*(byte *)((longlong)ppuVar6 + 0x1c) & 1) != 0)) {
      WPP_SF_sDsd(ppuVar6[2],pBVar3,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c","Status",0x26
                  ,"onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",0x23);
    }
  }
  else {
    while (uVar1 = (**(code **)(*(longlong *)(piVar2 + 2) + 0x78))
                             (*(undefined8 *)(*(longlong *)(piVar2 + 2) + 0x110),
                              *(undefined8 *)(piVar2 + 4),pBVar3,uVar4 & 0xffffffff,pPaddingInfo,
                              pbOutput,cbOutput,pcbResult,dwFlags), uVar1 == 0x8009002e) {
      if ((dwFlags & 0x40) != 0) {
        uVar1 = 0x80090022;
        DebugTraceError(0x22,"Status",
                        "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",0x3d);
        goto LAB_18000feaf;
      }
      uVar1 = (**(code **)(*(longlong *)(piVar2 + 2) + 0xc0))
                        (*(undefined8 *)(*(longlong *)(piVar2 + 2) + 0x110),hKey,L"NCryptEncrypt",0)
      ;
      if (uVar1 != 0) goto LAB_18000ff01;
      uVar4 = (ulonglong)cbInput;
      pBVar3 = pbInput;
    }
    if (uVar1 != 0) {
LAB_18000ff01:
      uVar5 = 0x94f;
      DebugTraceError((char)uVar1,"Status",
                      "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",0x4f);
      EtwLogNCryptOperationFailed
                (4,*(wchar_t **)(*(longlong *)(piVar2 + 2) + 0x118),*(wchar_t **)(piVar2 + 6),uVar5,
                 (char)uVar1);
    }
  }
LAB_18000feaf:
  uVar1 = NormalizeNteStatus(uVar1);
  return uVar1;
}



===== NCryptExportKey @ 18000ffd0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

SECURITY_STATUS __stdcall
NCryptExportKey(NCRYPT_KEY_HANDLE hKey,NCRYPT_KEY_HANDLE hExportKey,LPCWSTR pszBlobType,
               NCryptBufferDesc *pParameterList,PBYTE pbOutput,DWORD cbOutput,DWORD *pcbResult,
               DWORD dwFlags)

{
  uint uVar1;
  int *piVar2;
  undefined1 uVar3;
  NCRYPT_KEY_HANDLE NVar4;
  undefined8 uVar5;
  undefined1 uVar6;
  char *pcVar7;
  
                    /* 0xffd0  79  NCryptExportKey */
  piVar2 = (int *)0x0;
  NVar4 = hExportKey;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    WPP_SF_PPSD(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),hExportKey,pszBlobType,hKey,
                (char)hExportKey,pszBlobType,(char)dwFlags);
  }
  if (pszBlobType == (LPCWSTR)0x0) {
    uVar1 = 0x80090027;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),NVar4,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c","Status",0x27
                  ,"onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",0xdd);
    }
  }
  else {
    if ((hKey == 0) || (*(int *)hKey != 0x44440002)) {
      uVar6 = 0xe6;
    }
    else {
      if ((hExportKey == 0) ||
         (piVar2 = ValidateClientKeyHandle((int *)hExportKey), piVar2 != (int *)0x0)) {
        do {
          if (hExportKey == 0) {
            uVar5 = 0;
          }
          else {
            uVar5 = *(undefined8 *)(piVar2 + 4);
          }
          NVar4 = *(NCRYPT_KEY_HANDLE *)(hKey + 0x10);
          pcVar7 = (char *)pszBlobType;
          uVar1 = (**(code **)(*(longlong *)(hKey + 8) + 0xa8))
                            (*(undefined8 *)(*(longlong *)(hKey + 8) + 0x110),NVar4,uVar5,
                             pszBlobType,pParameterList,pbOutput,cbOutput,pcbResult,dwFlags);
          if (uVar1 != 0x8009002e) {
            if (uVar1 == 0) goto LAB_1800100af;
            break;
          }
          if ((dwFlags & 0x40) != 0) {
            uVar1 = 0x80090022;
            uVar6 = 0xc;
            uVar3 = 0x22;
            goto LAB_18001022f;
          }
          pcVar7 = (char *)0x0;
          NVar4 = hKey;
          uVar1 = (**(code **)(*(longlong *)(hKey + 8) + 0xc0))
                            (*(undefined8 *)(*(longlong *)(hKey + 8) + 0x110));
        } while (uVar1 == 0);
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
          pcVar7 = "Status";
          WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),NVar4,
                      "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c","Status",
                      (char)uVar1,
                      "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",0x1e);
        }
        EtwLogNCryptOperationFailed
                  (0xc,*(wchar_t **)(*(longlong *)(hKey + 8) + 0x118),*(wchar_t **)(hKey + 0x18),
                   pcVar7,(char)uVar1);
        goto LAB_1800100af;
      }
      uVar6 = 0xf1;
    }
    uVar1 = 0x80090026;
    uVar3 = 0x26;
LAB_18001022f:
    DebugTraceError(uVar3,"Status",
                    "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",uVar6);
  }
LAB_1800100af:
  uVar1 = NormalizeNteStatus(uVar1);
  return uVar1;
}



===== WPP_SF_PPSD @ 180010250 =====

void WPP_SF_PPSD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                undefined1 param_5,wchar_t *param_6,undefined1 param_7)

{
  longlong lVar1;
  longlong lVar2;
  wchar_t *pwVar3;
  undefined8 local_res20;
  
  if (param_6 == (wchar_t *)0x0) {
    lVar2 = 10;
  }
  else {
    lVar2 = -1;
    do {
      lVar1 = lVar2 + 1;
      lVar2 = lVar2 + 1;
    } while (param_6[lVar1] != L'\0');
    lVar2 = lVar2 * 2 + 2;
  }
  pwVar3 = param_6;
  if (param_6 == (wchar_t *)0x0) {
    pwVar3 = L"NULL";
  }
  local_res20 = param_4;
  TraceMessage(param_1,0x2b,&WPP_7a4fecd660bc33d31f6cd64b40025006_Traceguids,0x1c,&local_res20,8,
               &param_5,8,pwVar3,lVar2,&param_7,4,0);
  return;
}



===== NCryptVerifySignature @ 180010320 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

SECURITY_STATUS __stdcall
NCryptVerifySignature
          (NCRYPT_KEY_HANDLE hKey,void *pPaddingInfo,PBYTE pbHashValue,DWORD cbHashValue,
          PBYTE pbSignature,DWORD cbSignature,DWORD dwFlags)

{
  uint uVar1;
  int *piVar2;
  undefined *puVar3;
  undefined **ppuVar4;
  undefined **ppuVar5;
  wchar_t *pwVar6;
  char *pcVar7;
  undefined1 uVar8;
  undefined1 uVar9;
  
                    /* 0x10320  110  NCryptVerifySignature */
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    WPP_SF_PD(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x1e,&WPP_GLOBAL_Control,hKey,(char)dwFlags
             );
  }
  ppuVar5 = &WPP_GLOBAL_Control;
  pwVar6 = pPaddingInfo;
  ppuVar4 = (undefined **)WPP_GLOBAL_Control;
  piVar2 = ValidateClientKeyHandle((int *)hKey);
  if (piVar2 == (int *)0x0) {
    uVar1 = 0x80090026;
    if ((ppuVar4 != ppuVar5) && ((*(byte *)((longlong)ppuVar4 + 0x1c) & 1) != 0)) {
      puVar3 = ppuVar4[2];
      uVar9 = 0xbb;
      uVar8 = 0x26;
      ppuVar4 = (undefined **)pwVar6;
LAB_1800103d5:
      WPP_SF_sDsd(puVar3,ppuVar4,ppuVar5,"Status",uVar8,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",uVar9);
    }
  }
  else {
    while( true ) {
      ppuVar4 = *(undefined ***)(piVar2 + 4);
      pcVar7 = (char *)pbHashValue;
      uVar1 = (**(code **)(*(longlong *)(piVar2 + 2) + 0xb8))
                        (*(undefined8 *)(*(longlong *)(piVar2 + 2) + 0x110));
      if (uVar1 != 0x8009002e) break;
      if ((dwFlags & 0x40) != 0) {
        uVar1 = 0x80090022;
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_1800103e1;
        puVar3 = *(undefined **)(WPP_GLOBAL_Control + 0x10);
        uVar9 = 0xd4;
        uVar8 = 0x22;
        ppuVar5 = (undefined **)pwVar6;
        goto LAB_1800103d5;
      }
      pwVar6 = L"NCryptVerifySignature";
      pcVar7 = (char *)0x0;
      ppuVar4 = (undefined **)hKey;
      uVar1 = (**(code **)(*(longlong *)(piVar2 + 2) + 0xc0))
                        (*(undefined8 *)(*(longlong *)(piVar2 + 2) + 0x110));
      if (uVar1 != 0) goto LAB_18001045a;
      pwVar6 = pPaddingInfo;
    }
    if (uVar1 == 0) {
      uVar1 = 0;
    }
    else {
LAB_18001045a:
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
        pcVar7 = "Status";
        WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),ppuVar4,pwVar6,"Status",(char)uVar1,
                    "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",0xe7);
      }
      EtwLogNCryptOperationFailed
                (7,*(wchar_t **)(*(longlong *)(piVar2 + 2) + 0x118),*(wchar_t **)(piVar2 + 6),pcVar7
                 ,(char)uVar1);
    }
  }
LAB_1800103e1:
  uVar1 = NormalizeNteStatus(uVar1);
  return uVar1;
}



===== NCryptIsKeyHandle @ 180010560 =====

BOOL __stdcall NCryptIsKeyHandle(NCRYPT_KEY_HANDLE hKey)

{
  int *piVar1;
  
                    /* 0x10560  87  NCryptIsKeyHandle */
  piVar1 = ValidateClientKeyHandle((int *)hKey);
  return (uint)(piVar1 != (int *)0x0);
}



===== NCryptDecrypt @ 180010580 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

SECURITY_STATUS __stdcall
NCryptDecrypt(NCRYPT_KEY_HANDLE hKey,PBYTE pbInput,DWORD cbInput,void *pPaddingInfo,PBYTE pbOutput,
             DWORD cbOutput,DWORD *pcbResult,DWORD dwFlags)

{
  uint uVar1;
  int *piVar2;
  undefined *puVar3;
  undefined **ppuVar4;
  undefined **ppuVar5;
  undefined **ppuVar6;
  wchar_t *pwVar7;
  char *pcVar8;
  undefined **local_res8;
  undefined **local_res10;
  undefined1 uVar9;
  undefined1 uVar10;
  
                    /* 0x10580  70  NCryptDecrypt */
  local_res8 = (undefined **)hKey;
  local_res10 = (undefined **)pbInput;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    WPP_SF_PD(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x17,&WPP_GLOBAL_Control,hKey,(char)dwFlags
             );
  }
  ppuVar6 = &WPP_GLOBAL_Control;
  ppuVar4 = local_res10;
  ppuVar5 = (undefined **)WPP_GLOBAL_Control;
  piVar2 = ValidateClientKeyHandle((int *)local_res8);
  if (piVar2 == (int *)0x0) {
    uVar1 = 0x80090026;
    if ((ppuVar5 != ppuVar6) && ((*(byte *)((longlong)ppuVar5 + 0x1c) & 1) != 0)) {
      puVar3 = ppuVar5[2];
      uVar10 = 0x7f;
      uVar9 = 0x26;
      pwVar7 = (wchar_t *)ppuVar6;
      uVar1 = 0x80090026;
LAB_180010784:
      WPP_SF_sDsd(puVar3,ppuVar4,pwVar7,"Status",uVar9,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",uVar10);
    }
  }
  else {
    while( true ) {
      ppuVar5 = *(undefined ***)(piVar2 + 4);
      pcVar8 = (char *)(ulonglong)cbInput;
      pwVar7 = (wchar_t *)ppuVar4;
      uVar1 = (**(code **)(*(longlong *)(piVar2 + 2) + 0x80))
                        (*(undefined8 *)(*(longlong *)(piVar2 + 2) + 0x110));
      if (uVar1 != 0x8009002e) break;
      if ((dwFlags & 0x40) != 0) {
        uVar1 = 0x80090022;
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_18001068d;
        puVar3 = *(undefined **)(WPP_GLOBAL_Control + 0x10);
        uVar10 = 0x99;
        uVar9 = 0x22;
        ppuVar4 = ppuVar5;
        goto LAB_180010784;
      }
      pwVar7 = L"NCryptDecrypt";
      pcVar8 = (char *)0x0;
      ppuVar5 = local_res8;
      uVar1 = (**(code **)(*(longlong *)(piVar2 + 2) + 0xc0))
                        (*(undefined8 *)(*(longlong *)(piVar2 + 2) + 0x110));
      if (uVar1 != 0) goto LAB_1800106e8;
      ppuVar4 = local_res10;
    }
    if (uVar1 == 0) {
      if (((pbOutput != (PBYTE)0x0) && (cbOutput != 0)) && ((dwFlags & 0x10) == 0)) {
        CertInUseLog(1,(undefined8 *)(piVar2 + 10),&local_res8);
      }
      uVar1 = 0;
    }
    else {
LAB_1800106e8:
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
        pcVar8 = "Status";
        WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),ppuVar5,pwVar7,"Status",(char)uVar1,
                    "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",0xac);
      }
      EtwLogNCryptOperationFailed
                (5,*(wchar_t **)(*(longlong *)(piVar2 + 2) + 0x118),*(wchar_t **)(piVar2 + 6),pcVar8
                 ,(char)uVar1);
    }
  }
LAB_18001068d:
  uVar1 = NormalizeNteStatus(uVar1);
  return uVar1;
}



===== NCryptKeyDerivation @ 1800107f0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void NCryptKeyDerivation(int *param_1,wchar_t *param_2,char *param_3,int param_4,longlong param_5,
                        byte param_6)

{
  uint uVar1;
  int *piVar2;
  undefined **ppuVar3;
  int *piVar4;
  wchar_t *pwVar5;
  char *pcVar6;
  undefined **ppuVar7;
  undefined1 uVar8;
  undefined1 uVar9;
  
                    /* 0x107f0  88  NCryptKeyDerivation */
  pcVar6 = param_3;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    WPP_SF_PD(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x23,param_3,param_1,param_6);
  }
  ppuVar3 = &WPP_GLOBAL_Control;
  ppuVar7 = (undefined **)WPP_GLOBAL_Control;
  if (((param_5 == 0) || (param_3 == (char *)0x0)) || (param_4 == 0)) {
    uVar1 = 0x80090027;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_1800108eb;
    uVar9 = 0x34;
    uVar8 = 0x27;
  }
  else {
    piVar2 = ValidateClientKeyHandle(param_1);
    if (piVar2 == (int *)0x0) {
      uVar1 = 0x80090026;
      if ((ppuVar7 == ppuVar3) || ((*(byte *)((longlong)ppuVar7 + 0x1c) & 1) == 0))
      goto LAB_1800108eb;
      uVar9 = 0x41;
      uVar8 = 0x26;
    }
    else {
      if ((1 < *(ushort *)(*(longlong *)(piVar2 + 2) + 0x10)) &&
         (*(longlong *)(*(longlong *)(piVar2 + 2) + 0xe8) != 0)) {
        do {
          piVar4 = *(int **)(piVar2 + 4);
          pwVar5 = param_2;
          pcVar6 = param_3;
          uVar1 = (**(code **)(*(longlong *)(piVar2 + 2) + 0xe8))
                            (*(undefined8 *)(*(longlong *)(piVar2 + 2) + 0x110));
          if (uVar1 != 0x8009002e) {
            if (uVar1 == 0) goto LAB_1800108eb;
            break;
          }
          if ((param_6 & 0x40) != 0) {
            uVar1 = 0x80090022;
            DebugTraceError(0x22,"Status",
                            "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",
                            0x68);
            goto LAB_1800108eb;
          }
          pwVar5 = L"NCryptKeyDerivation";
          pcVar6 = (char *)0x0;
          piVar4 = param_1;
          uVar1 = (**(code **)(*(longlong *)(piVar2 + 2) + 0xc0))
                            (*(undefined8 *)(*(longlong *)(piVar2 + 2) + 0x110));
        } while (uVar1 == 0);
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
          pcVar6 = "Status";
          WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),piVar4,pwVar5,"Status",(char)uVar1,
                      "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",0x7a);
        }
        EtwLogNCryptOperationFailed
                  (10,*(wchar_t **)(*(longlong *)(piVar2 + 2) + 0x118),*(wchar_t **)(piVar2 + 6),
                   pcVar6,(char)uVar1);
        goto LAB_1800108eb;
      }
      uVar1 = 0x80090029;
      if ((ppuVar7 == ppuVar3) || ((*(byte *)((longlong)ppuVar7 + 0x1c) & 1) == 0))
      goto LAB_1800108eb;
      uVar9 = 0x4f;
      uVar8 = 0x29;
      uVar1 = 0x80090029;
    }
  }
  WPP_SF_sDsd(ppuVar7[2],ppuVar3,pcVar6,"Status",uVar8,
              "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",uVar9);
LAB_1800108eb:
  NormalizeNteStatus(uVar1);
  return;
}



===== ValidateClientKeyHandle @ 180010a80 =====

int * ValidateClientKeyHandle(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)0x0;
  if ((param_1 != (int *)0x0) && (piVar1 = param_1, *param_1 != 0x44440002)) {
    piVar1 = (int *)0x0;
  }
  return piVar1;
}



===== NCryptFinalizeKey @ 180010aa0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

SECURITY_STATUS __stdcall NCryptFinalizeKey(NCRYPT_KEY_HANDLE hKey,DWORD dwFlags)

{
  uint uVar1;
  undefined1 uVar2;
  undefined8 in_R8;
  undefined1 uVar3;
  undefined8 uVar4;
  
                    /* 0x10aa0  80  NCryptFinalizeKey */
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    WPP_SF_PD(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x12,in_R8,hKey,(char)dwFlags);
  }
  if ((hKey == 0) || (*(int *)hKey != 0x44440002)) {
    uVar1 = 0x80090026;
    uVar3 = 0xe6;
    uVar2 = 0x26;
LAB_180010bca:
    DebugTraceError(uVar2,"Status",
                    "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",uVar3);
  }
  else {
    do {
      uVar1 = (**(code **)(*(longlong *)(hKey + 8) + 0x50))
                        (*(undefined8 *)(*(longlong *)(hKey + 8) + 0x110),
                         *(undefined8 *)(hKey + 0x10),dwFlags);
      if (uVar1 != 0x8009002e) {
        if (uVar1 == 0) goto LAB_180010b0e;
        break;
      }
      if ((dwFlags & 0x40) != 0) {
        uVar1 = 0x80090022;
        uVar3 = 0xfa;
        uVar2 = 0x22;
        goto LAB_180010bca;
      }
      uVar1 = (**(code **)(*(longlong *)(hKey + 8) + 0xc0))
                        (*(undefined8 *)(*(longlong *)(hKey + 8) + 0x110),hKey,L"NCryptFinalizeKey",
                         0);
    } while (uVar1 == 0);
    uVar4 = 0x80c;
    DebugTraceError((char)uVar1,"Status",
                    "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",0xc);
    EtwLogNCryptOperationFailed
              (0xb,*(wchar_t **)(*(longlong *)(hKey + 8) + 0x118),*(wchar_t **)(hKey + 0x18),uVar4,
               (char)uVar1);
  }
LAB_180010b0e:
  uVar1 = NormalizeNteStatus(uVar1);
  return uVar1;
}



===== WPP_SF_PD @ 180010be8 =====

void WPP_SF_PD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  TraceMessage(param_1,0x2b,&WPP_7a4fecd660bc33d31f6cd64b40025006_Traceguids,param_2,&local_res20,8,
               &param_5,4,0);
  return;
}



===== CertInUseLog @ 180010c40 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void CertInUseLog(int param_1,undefined8 *param_2,undefined8 *param_3)

{
  short *psVar1;
  undefined8 *puVar2;
  byte bVar3;
  short sVar4;
  SECURITY_STATUS SVar5;
  int iVar6;
  uint uVar7;
  HANDLE pvVar8;
  undefined8 *lpMem;
  undefined8 *puVar9;
  ULONGLONG UVar10;
  byte bVar11;
  byte bVar12;
  short *psVar13;
  longlong lVar14;
  byte *pbVar15;
  undefined1 auStackY_a8 [32];
  uint local_68 [2];
  HLOCAL local_60;
  _FILETIME local_58;
  byte local_50 [32];
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_60 = (HLOCAL)0x0;
  local_68[0] = 0;
  InitOnceExecuteOnce((PINIT_ONCE)&DAT_180027d18,_StartRegChangeListenerInitOnceCallback,(PVOID)0x0,
                      (LPVOID *)0x0);
  if (g_dwClientEnabled == 0) {
    return;
  }
  lpMem = (undefined8 *)0x0;
  LOCK();
  puVar2 = (undefined8 *)*param_2;
  if (puVar2 == (undefined8 *)0x0) {
    *param_2 = 0;
  }
  else {
    lpMem = puVar2;
  }
  UNLOCK();
  if (puVar2 == (undefined8 *)0x0) {
    pvVar8 = GetProcessHeap();
    lpMem = HeapAlloc(pvVar8,8,0x100);
    if (lpMem == (undefined8 *)0x0) {
      EtwErrorNCryptCertInUse(L"Metadata Allocation Failed.",L"",0x8009000e);
      return;
    }
    InitializeSRWLock((PSRWLOCK)(lpMem + 0x1f));
    puVar9 = (undefined8 *)0x0;
    *lpMem = 1;
    LOCK();
    puVar2 = (undefined8 *)*param_2;
    if (puVar2 == (undefined8 *)0x0) {
      *param_2 = lpMem;
    }
    else {
      puVar9 = puVar2;
    }
    UNLOCK();
    if (puVar2 != (undefined8 *)0x0) {
      pvVar8 = GetProcessHeap();
      HeapFree(pvVar8,0,lpMem);
      lpMem = puVar9;
    }
  }
  AcquireSRWLockExclusive((PSRWLOCK)(lpMem + 0x1f));
  if (*(int *)((longlong)lpMem + 4) == 2) goto LAB_1800110ce;
  if (*(int *)((longlong)lpMem + 4) == 0) {
    SVar5 = CertInUseGetPubKeyInfo
                      (param_3,(longlong *)&local_60,local_68,(STRSAFE_LPWSTR)(lpMem + 6),
                       (undefined4 *)(lpMem + 2));
    if (SVar5 != 0) {
      EtwErrorNCryptCertInUse
                (L"Key Material perparation failed.",(STRSAFE_PCNZWCH)(lpMem + 6),SVar5);
      *(undefined4 *)((longlong)lpMem + 4) = 2;
      goto LAB_1800110ce;
    }
    iVar6 = BCryptHash(0x41,0,0,local_60);
    if (iVar6 < 0) {
      EtwErrorNCryptCertInUse(L"Key Material hash failed.",(STRSAFE_PCNZWCH)(lpMem + 6),iVar6);
      *(undefined4 *)((longlong)lpMem + 4) = 2;
      goto LAB_1800110ce;
    }
    lVar14 = 2;
    psVar13 = (short *)(lpMem + 0x16);
    pbVar15 = local_50 + 2;
    do {
      bVar3 = pbVar15[-2] >> 4;
      sVar4 = 0x30;
      if (9 < bVar3) {
        sVar4 = 0x37;
      }
      bVar11 = pbVar15[-2] & 0xf;
      *psVar13 = sVar4 + (ushort)bVar3;
      bVar3 = pbVar15[-1];
      sVar4 = 0x30;
      if (9 < bVar11) {
        sVar4 = 0x37;
      }
      psVar13[1] = sVar4 + (ushort)bVar11;
      bVar11 = bVar3 >> 4;
      sVar4 = 0x30;
      if (9 < bVar11) {
        sVar4 = 0x37;
      }
      bVar3 = bVar3 & 0xf;
      psVar13[2] = sVar4 + (ushort)bVar11;
      bVar11 = *pbVar15;
      sVar4 = 0x30;
      if (9 < bVar3) {
        sVar4 = 0x37;
      }
      psVar13[3] = sVar4 + (ushort)bVar3;
      bVar3 = bVar11 >> 4;
      sVar4 = 0x30;
      if (9 < bVar3) {
        sVar4 = 0x37;
      }
      bVar11 = bVar11 & 0xf;
      bVar12 = pbVar15[1];
      psVar13[4] = sVar4 + (ushort)bVar3;
      sVar4 = 0x30;
      if (9 < bVar11) {
        sVar4 = 0x37;
      }
      psVar13[5] = sVar4 + (ushort)bVar11;
      bVar3 = bVar12 >> 4;
      sVar4 = 0x30;
      if (9 < bVar3) {
        sVar4 = 0x37;
      }
      bVar12 = bVar12 & 0xf;
      bVar11 = pbVar15[2];
      psVar13[6] = sVar4 + (ushort)bVar3;
      sVar4 = 0x30;
      if (9 < bVar12) {
        sVar4 = 0x37;
      }
      psVar13[7] = sVar4 + (ushort)bVar12;
      bVar3 = bVar11 >> 4;
      sVar4 = 0x30;
      if (9 < bVar3) {
        sVar4 = 0x37;
      }
      bVar11 = bVar11 & 0xf;
      bVar12 = pbVar15[3];
      psVar13[8] = sVar4 + (ushort)bVar3;
      sVar4 = 0x30;
      if (9 < bVar11) {
        sVar4 = 0x37;
      }
      psVar13[9] = sVar4 + (ushort)bVar11;
      psVar1 = psVar13 + 0x10;
      bVar3 = bVar12 >> 4;
      sVar4 = 0x30;
      if (9 < bVar3) {
        sVar4 = 0x37;
      }
      bVar12 = bVar12 & 0xf;
      bVar11 = pbVar15[4];
      psVar13[10] = sVar4 + (ushort)bVar3;
      sVar4 = 0x30;
      if (9 < bVar12) {
        sVar4 = 0x37;
      }
      psVar13[0xb] = sVar4 + (ushort)bVar12;
      bVar3 = bVar11 >> 4;
      sVar4 = 0x30;
      if (9 < bVar3) {
        sVar4 = 0x37;
      }
      bVar11 = bVar11 & 0xf;
      bVar12 = pbVar15[5];
      psVar13[0xc] = sVar4 + (ushort)bVar3;
      sVar4 = 0x30;
      if (9 < bVar11) {
        sVar4 = 0x37;
      }
      psVar13[0xd] = sVar4 + (ushort)bVar11;
      bVar3 = bVar12 >> 4;
      sVar4 = 0x30;
      if (9 < bVar3) {
        sVar4 = 0x37;
      }
      bVar12 = bVar12 & 0xf;
      psVar13[0xe] = sVar4 + (ushort)bVar3;
      sVar4 = 0x30;
      if (9 < bVar12) {
        sVar4 = 0x37;
      }
      psVar13[0xf] = sVar4 + (ushort)bVar12;
      lVar14 = lVar14 + -1;
      psVar13 = psVar1;
      pbVar15 = pbVar15 + 8;
    } while (lVar14 != 0);
    *psVar1 = 0;
    *(undefined4 *)((longlong)lpMem + 4) = 1;
  }
  if (param_1 == 0) {
LAB_180011065:
    *(int *)((longlong)lpMem + 0x24) = *(int *)((longlong)lpMem + 0x24) + 1;
  }
  else if (param_1 == 1) {
    *(int *)(lpMem + 5) = *(int *)(lpMem + 5) + 1;
  }
  else if (param_1 == 2) {
    *(int *)((longlong)lpMem + 0x2c) = *(int *)((longlong)lpMem + 0x2c) + 1;
  }
  else if ((param_1 == 3) &&
          (uVar7 = Feature_CNG_NCRYPT_PRIVATE_TLS_CLIENT_AUTH__private_IsEnabledDeviceUsageNoInline
                             (), uVar7 != 0)) {
    *(undefined2 *)(lpMem + 6) = 0x40;
    goto LAB_180011065;
  }
  local_58.dwLowDateTime = 0;
  local_58.dwHighDateTime = 0;
  GetSystemTimeAsFileTime(&local_58);
  if ((*(int *)((longlong)lpMem + 0x14) == 0) && (*(int *)(lpMem + 3) == 0)) {
    *(_FILETIME *)((longlong)lpMem + 0x14) = local_58;
  }
  *(_FILETIME *)((longlong)lpMem + 0x1c) = local_58;
  UVar10 = GetTickCount64();
  if ((lpMem[1] == 0) || ((ulonglong)g_dwClientSideEventThrottlingMilliseconds <= UVar10 - lpMem[1])
     ) {
    lpMem[1] = UVar10;
    EtwLogNCryptCertInUse((longlong)lpMem);
  }
LAB_1800110ce:
  if (local_60 != (HLOCAL)0x0) {
    LocalFree(local_60);
    local_60 = (HLOCAL)0x0;
  }
  ReleaseSRWLockExclusive((PSRWLOCK)(lpMem + 0x1f));
  return;
}



===== EtwLogNCryptOperationFailed @ 180011140 =====

undefined8
EtwLogNCryptOperationFailed
          (undefined8 param_1,wchar_t *param_2,wchar_t *param_3,undefined8 param_4,
          undefined1 param_5)

{
  wchar_t *pwVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  wchar_t *pwVar4;
  undefined8 in_stack_ffffffffffffffd0;
  undefined8 in_stack_ffffffffffffffd8;
  
  uVar3 = (undefined4)param_1;
  if ((Microsoft_Windows_Crypto_NCryptEnableBits & 1) == 0) {
    uVar2 = 0;
  }
  else {
    pwVar4 = param_2;
    pwVar1 = I_GetProcessName();
    uVar2 = McTemplateU0qzzzzdz_EventWriteTransfer
                      (param_1,pwVar4,uVar3,param_2,param_3,in_stack_ffffffffffffffd0,
                       in_stack_ffffffffffffffd8,param_5,pwVar1);
  }
  return uVar2;
}



===== SslComputeClientAuthHash @ 1800111a0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void SslComputeClientAuthHash(uint *param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined1 uVar7;
  
                    /* 0x111a0  113  SslComputeClientAuthHash */
  puVar2 = ValidateSslProvHandle(param_1);
  if (puVar2 == (uint *)0x0) {
    uVar7 = 0xd3;
  }
  else {
    puVar3 = ValidateSslKeyHandle(param_2);
    if (puVar3 == (uint *)0x0) {
      uVar7 = 0xdb;
    }
    else {
      puVar4 = ValidateSslHashHandle(param_3);
      if (puVar4 != (uint *)0x0) {
        uVar6 = *(undefined8 *)(puVar4 + 4);
        uVar5 = *(undefined8 *)(puVar3 + 4);
        uVar1 = (**(code **)(puVar2 + 10))(*(undefined8 *)(puVar2 + 0x6a));
        if ((int)uVar1 < 0) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
            WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),uVar5,uVar6,"Status",(char)uVar1,
                        "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",0xf7);
          }
        }
        else {
          uVar1 = 0;
        }
        goto LAB_18001129b;
      }
      uVar7 = 0xe3;
    }
  }
  uVar1 = 0x80090026;
  DebugTraceError(0x26,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",uVar7);
LAB_18001129b:
  NormalizeNteStatus(uVar1);
  return;
}



===== ValidateSslHashHandle @ 1800112b0 =====

uint * ValidateSslHashHandle(uint *param_1)

{
  uint *puVar1;
  
  if ((param_1 == (uint *)0x0) || (*param_1 < 0x20)) {
    return (uint *)0x0;
  }
  puVar1 = (uint *)0x0;
  if (param_1[1] == 0x44444443) {
    puVar1 = param_1;
  }
  return puVar1;
}



===== SslExtractHandshakeKey @ 1800112e0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void SslExtractHandshakeKey
               (uint *param_1,uint *param_2,uint *param_3,uint *param_4,undefined8 *param_5,
               undefined8 param_6,undefined4 param_7)

{
  uint uVar1;
  undefined8 *puVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  
                    /* 0x112e0  140  SslExtractHandshakeKey */
  if ((((param_1 == (uint *)0x0) || (*param_1 < 0x1b0)) || (param_1[1] != 0x44444441)) ||
     (param_1[3] != 0)) {
    param_1 = (uint *)0x0;
  }
  if (((param_2 == (uint *)0x0) || (*param_2 < 0x20)) || (param_2[1] != 0x44444442)) {
    param_2 = (uint *)0x0;
  }
  if (((param_3 == (uint *)0x0) || (*param_3 < 0x20)) || (param_3[1] != 0x44444442)) {
    param_3 = (uint *)0x0;
  }
  if (((param_4 == (uint *)0x0) || (*param_4 < 0x20)) || (param_4[1] != 0x44444442)) {
    param_4 = (uint *)0x0;
  }
  if (((param_1 == (uint *)0x0) || (param_2 == (uint *)0x0)) ||
     ((param_3 == (uint *)0x0 || (param_4 == (uint *)0x0)))) {
    uVar1 = 0x80090026;
    uVar4 = 0x7b;
    uVar3 = 0x26;
  }
  else if (param_5 == (undefined8 *)0x0) {
    uVar1 = 0x80090027;
    uVar4 = 0x82;
    uVar3 = 0x27;
  }
  else if ((ushort)param_1[8] < 4) {
    uVar1 = 0x80090029;
    uVar4 = 0x8d;
    uVar3 = 0x29;
  }
  else {
    puVar2 = (undefined8 *)
             RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,0x20);
    if (puVar2 != (undefined8 *)0x0) {
      *puVar2 = 0;
      puVar2[1] = 0;
      puVar2[2] = 0;
      puVar2[3] = 0;
      uVar1 = (**(code **)(param_1 + 0x48))
                        (*(undefined8 *)(param_1 + 0x6a),*(undefined8 *)(param_2 + 4),
                         *(undefined8 *)(param_3 + 4),*(undefined8 *)(param_4 + 4),puVar2 + 2,
                         param_6,param_7);
      if ((int)uVar1 < 0) {
        DebugTraceError((char)uVar1,"Status",
                        "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",0xac);
        SafeAllocaFreeToHeap(puVar2);
      }
      else {
        *(undefined4 *)puVar2 = 0x20;
        *(undefined8 *)((longlong)puVar2 + 4) = 0x44444442;
        *(undefined4 *)((longlong)puVar2 + 0xc) = 1;
        puVar2[3] = param_1;
        LOCK();
        param_1[4] = param_1[4] + 1;
        UNLOCK();
        *param_5 = puVar2;
        uVar1 = 0;
      }
      goto LAB_180011446;
    }
    uVar1 = 0x8009000e;
    uVar4 = 0x99;
    uVar3 = 0xe;
  }
  DebugTraceError(uVar3,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",uVar4)
  ;
LAB_180011446:
  NormalizeNteStatus(uVar1);
  return;
}



===== SslComputeFinishedHash @ 1800114f0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void SslComputeFinishedHash
               (uint *param_1,uint *param_2,uint *param_3,undefined8 param_4,undefined4 param_5,
               undefined4 param_6)

{
  uint uVar1;
  undefined1 uVar2;
  
                    /* 0x114f0  115  SslComputeFinishedHash */
  if ((((param_1 == (uint *)0x0) || (*param_1 < 0x1b0)) || (param_1[1] != 0x44444441)) ||
     (param_1[3] != 0)) {
    uVar1 = 0x80090026;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_180011619;
    uVar2 = 0xca;
  }
  else if (((param_2 == (uint *)0x0) || (*param_2 < 0x20)) || (param_2[1] != 0x44444442)) {
    uVar1 = 0x80090026;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_180011619;
    uVar2 = 0xd2;
  }
  else {
    if (((param_3 != (uint *)0x0) && (0x1f < *param_3)) && (param_3[1] == 0x44444443)) {
      uVar1 = (**(code **)(param_1 + 0xe))
                        (*(undefined8 *)(param_1 + 0x6a),*(undefined8 *)(param_2 + 4),
                         *(undefined8 *)(param_3 + 4),param_4,param_5,param_6);
      if ((int)uVar1 < 0) {
        DebugTraceError((char)uVar1,"Status",
                        "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",0xec);
      }
      else {
        uVar1 = 0;
      }
      goto LAB_180011619;
    }
    uVar1 = 0x80090026;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_180011619;
    uVar2 = 0xda;
  }
  uVar1 = 0x80090026;
  WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),param_2,param_3,"Status",0x26,
              "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",uVar2);
LAB_180011619:
  NormalizeNteStatus(uVar1);
  return;
}



===== SslExtractEarlyKey @ 180011650 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void SslExtractEarlyKey(uint *param_1,uint *param_2,undefined8 *param_3,undefined4 param_4,
                       undefined4 param_5,undefined8 param_6,undefined4 param_7)

{
  uint uVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  uint *puVar4;
  undefined8 *puVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  
                    /* 0x11650  139  SslExtractEarlyKey */
  if ((((param_1 == (uint *)0x0) || (*param_1 < 0x1b0)) || (param_1[1] != 0x44444441)) ||
     (param_1[3] != 0)) {
    param_1 = (uint *)0x0;
  }
  if (((param_2 == (uint *)0x0) || (*param_2 < 0x20)) || (param_2[1] != 0x44444442)) {
    puVar4 = (uint *)0x0;
  }
  else {
    puVar4 = param_2;
  }
  if ((param_1 == (uint *)0x0) || ((param_2 != (uint *)0x0 && (puVar4 == (uint *)0x0)))) {
    uVar1 = 0x80090026;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_180011779;
    uVar7 = 5;
    uVar6 = 0x26;
    uVar1 = 0x80090026;
  }
  else {
    if (param_3 != (undefined8 *)0x0) {
      if ((ushort)param_1[8] < 4) {
        uVar1 = 0x80090029;
        DebugTraceError(0x29,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",
                        0x17);
      }
      else {
        puVar2 = (undefined8 *)
                 RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,0x20);
        if (puVar2 == (undefined8 *)0x0) {
          uVar1 = 0x8009000e;
          DebugTraceError(0xe,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",
                          0x23);
        }
        else {
          *puVar2 = 0;
          puVar2[1] = 0;
          puVar2[2] = 0;
          puVar2[3] = 0;
          if (puVar4 == (uint *)0x0) {
            uVar3 = 0;
          }
          else {
            uVar3 = *(undefined8 *)(puVar4 + 4);
          }
          puVar5 = puVar2 + 2;
          uVar1 = (**(code **)(param_1 + 0x46))
                            (*(undefined8 *)(param_1 + 0x6a),uVar3,puVar5,param_4,param_5,param_6,
                             param_7);
          if ((int)uVar1 < 0) {
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
              WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),uVar3,puVar5,"Status",
                          (char)uVar1,"onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",
                          0x36);
            }
            SafeAllocaFreeToHeap(puVar2);
          }
          else {
            *(undefined4 *)puVar2 = 0x20;
            *(undefined8 *)((longlong)puVar2 + 4) = 0x44444442;
            *(undefined4 *)((longlong)puVar2 + 0xc) = 1;
            puVar2[3] = param_1;
            LOCK();
            param_1[4] = param_1[4] + 1;
            UNLOCK();
            *param_3 = puVar2;
            uVar1 = 0;
          }
        }
      }
      goto LAB_180011779;
    }
    uVar1 = 0x80090027;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_180011779;
    uVar7 = 0xc;
    uVar6 = 0x27;
    uVar1 = 0x80090027;
  }
  WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),param_2,param_3,"Status",uVar6,
              "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",uVar7);
LAB_180011779:
  NormalizeNteStatus(uVar1);
  return;
}



===== SslExpandExporterMasterKey @ 1800118f0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void SslExpandExporterMasterKey
               (uint *param_1,uint *param_2,uint *param_3,undefined8 *param_4,undefined8 param_5,
               undefined4 param_6)

{
  uint uVar1;
  undefined8 *puVar2;
  uint *puVar3;
  uint *puVar4;
  undefined8 in_stack_ffffffffffffffe0;
  undefined4 uVar5;
  
                    /* 0x118f0  131  SslExpandExporterMasterKey */
  uVar5 = (undefined4)((ulonglong)in_stack_ffffffffffffffe0 >> 0x20);
  if ((((param_1 == (uint *)0x0) || (*param_1 < 0x1b0)) || (param_1[1] != 0x44444441)) ||
     (param_1[3] != 0)) {
    param_1 = (uint *)0x0;
  }
  if (((param_2 == (uint *)0x0) || (*param_2 < 0x20)) ||
     (puVar4 = param_2, param_2[1] != 0x44444442)) {
    puVar4 = (uint *)0x0;
  }
  if (((param_3 == (uint *)0x0) || (*param_3 < 0x20)) ||
     (puVar3 = param_3, param_3[1] != 0x44444443)) {
    puVar3 = (uint *)0x0;
  }
  if (((param_1 == (uint *)0x0) || (puVar4 == (uint *)0x0)) || (puVar3 == (uint *)0x0)) {
    uVar1 = 0x80090026;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),param_2,param_3,"Status",0x26,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",0x73);
    }
  }
  else if (param_4 == (undefined8 *)0x0) {
    uVar1 = 0x80090027;
    DebugTraceError(0x27,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",0x7a)
    ;
  }
  else if ((ushort)param_1[8] < 4) {
    uVar1 = 0x80090029;
    DebugTraceError(0x29,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",0x85)
    ;
  }
  else {
    puVar2 = (undefined8 *)
             RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,0x20);
    if (puVar2 == (undefined8 *)0x0) {
      uVar1 = 0x8009000e;
      DebugTraceError(0xe,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",0x91
                     );
    }
    else {
      *puVar2 = 0;
      puVar2[1] = 0;
      puVar2[2] = 0;
      puVar2[3] = 0;
      uVar1 = (**(code **)(param_1 + 0x50))
                        (*(undefined8 *)(param_1 + 0x6a),*(undefined8 *)(puVar4 + 4),
                         *(undefined8 *)(puVar3 + 4),puVar2 + 2,param_5,CONCAT44(uVar5,param_6));
      if ((int)uVar1 < 0) {
        DebugTraceError((char)uVar1,"Status",
                        "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",0xa3);
        SafeAllocaFreeToHeap(puVar2);
      }
      else {
        *(undefined4 *)puVar2 = 0x20;
        *(undefined8 *)((longlong)puVar2 + 4) = 0x44444442;
        *(undefined4 *)((longlong)puVar2 + 0xc) = 1;
        puVar2[3] = param_1;
        *param_4 = puVar2;
        LOCK();
        param_1[4] = param_1[4] + 1;
        UNLOCK();
        uVar1 = 0;
      }
    }
  }
  NormalizeNteStatus(uVar1);
  return;
}



===== SslExpandResumptionMasterKey @ 180011b40 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void SslExpandResumptionMasterKey
               (uint *param_1,uint *param_2,uint *param_3,undefined8 *param_4,undefined8 param_5,
               undefined4 param_6)

{
  uint uVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  uint *puVar4;
  uint *puVar5;
  undefined8 uVar6;
  undefined1 uVar7;
  undefined8 in_stack_ffffffffffffffe0;
  undefined4 uVar8;
  undefined1 uVar9;
  
                    /* 0x11b40  134  SslExpandResumptionMasterKey */
  uVar8 = (undefined4)((ulonglong)in_stack_ffffffffffffffe0 >> 0x20);
  if ((((param_1 == (uint *)0x0) || (*param_1 < 0x1b0)) || (param_1[1] != 0x44444441)) ||
     (param_1[3] != 0)) {
    param_1 = (uint *)0x0;
  }
  if (((param_2 == (uint *)0x0) || (*param_2 < 0x20)) ||
     (puVar5 = param_2, param_2[1] != 0x44444442)) {
    puVar5 = (uint *)0x0;
  }
  if (((param_3 == (uint *)0x0) || (*param_3 < 0x20)) ||
     (puVar4 = param_3, param_3[1] != 0x44444443)) {
    puVar4 = (uint *)0x0;
  }
  if (((param_1 == (uint *)0x0) || (puVar5 == (uint *)0x0)) || (puVar4 == (uint *)0x0)) {
    uVar1 = 0x80090026;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_180011c75;
    uVar9 = 0xe4;
    uVar7 = 0x26;
  }
  else {
    if (param_4 == (undefined8 *)0x0) {
      uVar1 = 0x80090027;
      DebugTraceError(0x27,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",
                      0xeb);
      goto LAB_180011c75;
    }
    if ((ushort)param_1[8] < 5) {
      uVar1 = 0x80090029;
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_180011c75;
      uVar9 = 0xf6;
      uVar7 = 0x29;
      uVar1 = 0x80090029;
    }
    else {
      param_3 = (uint *)0x20;
      param_2 = (uint *)0x0;
      puVar2 = (undefined8 *)
               RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30));
      if (puVar2 != (undefined8 *)0x0) {
        *puVar2 = 0;
        puVar2[1] = 0;
        puVar2[2] = 0;
        puVar2[3] = 0;
        uVar6 = *(undefined8 *)(puVar4 + 4);
        uVar3 = *(undefined8 *)(puVar5 + 4);
        uVar1 = (**(code **)(param_1 + 0x54))
                          (*(undefined8 *)(param_1 + 0x6a),uVar3,uVar6,puVar2 + 2,param_5,
                           CONCAT44(uVar8,param_6));
        if ((int)uVar1 < 0) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
            WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),uVar3,uVar6,"Status",(char)uVar1,
                        "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",0x14);
          }
          SafeAllocaFreeToHeap(puVar2);
        }
        else {
          *(undefined4 *)puVar2 = 0x20;
          *(undefined8 *)((longlong)puVar2 + 4) = 0x44444442;
          *(undefined4 *)((longlong)puVar2 + 0xc) = 1;
          puVar2[3] = param_1;
          *param_4 = puVar2;
          LOCK();
          param_1[4] = param_1[4] + 1;
          UNLOCK();
          uVar1 = 0;
        }
        goto LAB_180011c75;
      }
      uVar1 = 0x8009000e;
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_180011c75;
      uVar9 = 2;
      uVar7 = 0xe;
    }
  }
  WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),param_2,param_3,"Status",uVar7,
              "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",uVar9);
LAB_180011c75:
  NormalizeNteStatus(uVar1);
  return;
}



===== SslCreateHandshakeHash @ 180011df0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void SslCreateHandshakeHash
               (uint *param_1,undefined8 *param_2,ulonglong param_3,undefined4 param_4,
               undefined4 param_5)

{
  uint uVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  ulonglong uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  
                    /* 0x11df0  119  SslCreateHandshakeHash */
  if ((((param_1 == (uint *)0x0) || (*param_1 < 0x1b0)) || (param_1[1] != 0x44444441)) ||
     (param_1[3] != 0)) {
    uVar1 = 0x80090026;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_180011f05;
    uVar6 = 0x83;
    uVar5 = 0x26;
  }
  else if (param_2 == (undefined8 *)0x0) {
    uVar1 = 0x80090027;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_180011f05;
    uVar6 = 0x8a;
    uVar5 = 0x27;
    uVar1 = 0x80090027;
  }
  else {
    puVar3 = (undefined8 *)0x0;
    uVar4 = 0x20;
    puVar2 = (undefined8 *)
             RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30));
    if (puVar2 != (undefined8 *)0x0) {
      *puVar2 = 0;
      puVar2[1] = 0;
      puVar2[2] = 0;
      puVar2[3] = 0;
      uVar1 = (**(code **)(param_1 + 0x12))
                        (*(undefined8 *)(param_1 + 0x6a),puVar2 + 2,param_3 & 0xffffffff,param_4,
                         param_5);
      if ((int)uVar1 < 0) {
        DebugTraceError((char)uVar1,"Status",
                        "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",0xac);
        SafeAllocaFreeToHeap(puVar2);
      }
      else {
        *(undefined4 *)puVar2 = 0x20;
        uVar1 = 0;
        *(undefined8 *)((longlong)puVar2 + 4) = 0x44444443;
        *(undefined4 *)((longlong)puVar2 + 0xc) = 1;
        puVar2[3] = param_1;
        LOCK();
        param_1[4] = param_1[4] + 1;
        UNLOCK();
        *param_2 = puVar2;
      }
      goto LAB_180011f05;
    }
    uVar1 = 0x8009000e;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_180011f05;
    uVar6 = 0x9a;
    uVar5 = 0xe;
    param_2 = puVar3;
    param_3 = uVar4;
  }
  WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),param_2,param_3,"Status",uVar5,
              "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",uVar6);
LAB_180011f05:
  NormalizeNteStatus(uVar1);
  return;
}



===== SslImportKey @ 180011ff0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void SslImportKey(uint *param_1,undefined8 *param_2,undefined8 param_3,undefined8 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  uint uVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  undefined1 uVar5;
  undefined8 in_stack_ffffffffffffffe0;
  undefined4 uVar6;
  undefined1 uVar7;
  
                    /* 0x11ff0  152  SslImportKey */
  uVar6 = (undefined4)((ulonglong)in_stack_ffffffffffffffe0 >> 0x20);
  if ((((param_1 == (uint *)0x0) || (*param_1 < 0x1b0)) || (param_1[1] != 0x44444441)) ||
     (param_1[3] != 0)) {
    uVar1 = 0x80090026;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_180012110;
    uVar7 = 0x11;
    uVar5 = 0x26;
  }
  else if (param_2 == (undefined8 *)0x0) {
    uVar1 = 0x80090027;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_180012110;
    uVar7 = 0x18;
    uVar5 = 0x27;
    uVar1 = 0x80090027;
  }
  else {
    puVar3 = (undefined8 *)0x0;
    uVar4 = 0x20;
    puVar2 = (undefined8 *)
             RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30));
    if (puVar2 != (undefined8 *)0x0) {
      *puVar2 = 0;
      puVar2[1] = 0;
      puVar2[2] = 0;
      puVar2[3] = 0;
      uVar1 = (**(code **)(param_1 + 0x2c))
                        (*(undefined8 *)(param_1 + 0x6a),puVar2 + 2,param_3,param_4,param_5,
                         CONCAT44(uVar6,param_6));
      if ((int)uVar1 < 0) {
        DebugTraceError((char)uVar1,"Status",
                        "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",0x3b);
        SafeAllocaFreeToHeap(puVar2);
      }
      else {
        *(undefined4 *)puVar2 = 0x20;
        uVar1 = 0;
        *(undefined8 *)((longlong)puVar2 + 4) = 0x44444442;
        *(undefined4 *)((longlong)puVar2 + 0xc) = 1;
        puVar2[3] = param_1;
        LOCK();
        param_1[4] = param_1[4] + 1;
        UNLOCK();
        *param_2 = puVar2;
      }
      goto LAB_180012110;
    }
    uVar1 = 0x8009000e;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_180012110;
    uVar7 = 0x28;
    uVar5 = 0xe;
    param_2 = puVar3;
    param_3 = uVar4;
  }
  WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),param_2,param_3,"Status",uVar5,
              "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",uVar7);
LAB_180012110:
  NormalizeNteStatus(uVar1);
  return;
}



===== SslGetKeyProperty @ 1800121f0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void SslGetKeyProperty(uint *param_1,longlong param_2,longlong param_3,longlong param_4)

{
  uint uVar1;
  ulonglong uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  
                    /* 0x121f0  148  SslGetKeyProperty */
  if (((param_1 == (uint *)0x0) || (*param_1 < 0x20)) || (param_1[1] != 0x44444442)) {
    uVar1 = 0x80090026;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_1800122ba;
    uVar4 = 0xe8;
    uVar3 = 0x26;
  }
  else {
    if (param_2 == 0) {
      uVar1 = 0x80090027;
      DebugTraceError(0x27,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",
                      0xef);
      goto LAB_1800122ba;
    }
    uVar2 = 0xffffffffffffffff;
    do {
      uVar2 = uVar2 + 1;
    } while (*(short *)(param_2 + uVar2 * 2) != 0);
    if (uVar2 < 0x41) {
      if ((param_3 != 0) && (param_4 != 0)) {
        uVar1 = (**(code **)(*(longlong *)(param_1 + 6) + 0x90))(*(undefined8 *)(param_1 + 4));
        if (-1 < (int)uVar1) {
          NormalizeNteStatus(0);
          return;
        }
        DebugTraceError((char)uVar1,"Status",
                        "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",0xc);
        goto LAB_1800122ba;
      }
      uVar1 = 0x80090027;
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_1800122ba;
      uVar4 = 0xfc;
      uVar3 = 0x27;
    }
    else {
      uVar1 = 0x80090027;
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_1800122ba;
      uVar4 = 0xf5;
      uVar3 = 0x27;
    }
  }
  WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),param_2,param_3,"Status",uVar3,
              "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",uVar4);
LAB_1800122ba:
  NormalizeNteStatus(uVar1);
  return;
}



===== SslCreateEphemeralKey @ 180012390 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void SslCreateEphemeralKey
               (uint *param_1,undefined8 *param_2,ulonglong param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined8 param_7,undefined4 param_8,
               undefined4 param_9)

{
  uint uVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  ulonglong uVar4;
  undefined1 uVar5;
  undefined8 in_stack_ffffffffffffffd0;
  undefined4 uVar6;
  undefined1 uVar7;
  
                    /* 0x12390  118  SslCreateEphemeralKey */
  uVar6 = (undefined4)((ulonglong)in_stack_ffffffffffffffd0 >> 0x20);
  if ((((param_1 == (uint *)0x0) || (*param_1 < 0x1b0)) || (param_1[1] != 0x44444441)) ||
     (param_1[3] != 0)) {
    uVar1 = 0x80090026;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_1800124d2;
    uVar7 = 0x19;
    uVar5 = 0x26;
  }
  else if (param_2 == (undefined8 *)0x0) {
    uVar1 = 0x80090027;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_1800124d2;
    uVar7 = 0x20;
    uVar5 = 0x27;
    uVar1 = 0x80090027;
  }
  else {
    puVar3 = (undefined8 *)0x0;
    uVar4 = 0x20;
    puVar2 = (undefined8 *)
             RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30));
    if (puVar2 != (undefined8 *)0x0) {
      puVar3 = puVar2 + 2;
      *puVar2 = 0;
      puVar2[1] = 0;
      uVar4 = param_3 & 0xffffffff;
      puVar2[2] = 0;
      puVar2[3] = 0;
      uVar1 = (**(code **)(param_1 + 0x10))
                        (*(undefined8 *)(param_1 + 0x6a),puVar3,uVar4,param_4,param_5,
                         CONCAT44(uVar6,param_6),param_7,param_8,param_9);
      if ((int)uVar1 < 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
          WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),puVar3,uVar4,"Status",(char)uVar1,
                      "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",0x45);
        }
        RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,puVar2);
      }
      else {
        *(undefined4 *)puVar2 = 0x20;
        uVar1 = 0;
        *(undefined8 *)((longlong)puVar2 + 4) = 0x44444442;
        *(undefined4 *)((longlong)puVar2 + 0xc) = 1;
        puVar2[3] = param_1;
        LOCK();
        param_1[4] = param_1[4] + 1;
        UNLOCK();
        *param_2 = puVar2;
      }
      goto LAB_1800124d2;
    }
    uVar1 = 0x8009000e;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_1800124d2;
    uVar7 = 0x2f;
    uVar5 = 0xe;
    param_2 = puVar3;
    param_3 = uVar4;
  }
  WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),param_2,param_3,"Status",uVar5,
              "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",uVar7);
LAB_1800124d2:
  NormalizeNteStatus(uVar1);
  return;
}



===== SslExtractMasterKey @ 180012600 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void SslExtractMasterKey(uint *param_1,uint *param_2,undefined8 *param_3,undefined8 param_4,
                        undefined4 param_5)

{
  uint uVar1;
  undefined8 *puVar2;
  uint *puVar3;
  undefined8 *puVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  
                    /* 0x12600  141  SslExtractMasterKey */
  if ((((param_1 == (uint *)0x0) || (*param_1 < 0x1b0)) || (param_1[1] != 0x44444441)) ||
     (param_1[3] != 0)) {
    param_1 = (uint *)0x0;
  }
  if (((param_2 == (uint *)0x0) || (*param_2 < 0x20)) ||
     (puVar3 = param_2, param_2[1] != 0x44444442)) {
    puVar3 = (uint *)0x0;
  }
  if ((param_1 == (uint *)0x0) || (puVar3 == (uint *)0x0)) {
    uVar1 = 0x80090026;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_18001270a;
    uVar6 = 0xeb;
    uVar5 = 0x26;
  }
  else {
    if (param_3 == (undefined8 *)0x0) {
      uVar1 = 0x80090027;
      DebugTraceError(0x27,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",
                      0xf2);
      goto LAB_18001270a;
    }
    if ((ushort)param_1[8] < 4) {
      uVar1 = 0x80090029;
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_18001270a;
      uVar6 = 0xfd;
      uVar5 = 0x29;
      uVar1 = 0x80090029;
    }
    else {
      puVar4 = (undefined8 *)0x20;
      param_2 = (uint *)0x0;
      puVar2 = (undefined8 *)
               RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30));
      if (puVar2 != (undefined8 *)0x0) {
        *puVar2 = 0;
        puVar2[1] = 0;
        puVar2[2] = 0;
        puVar2[3] = 0;
        uVar1 = (**(code **)(param_1 + 0x4a))
                          (*(undefined8 *)(param_1 + 0x6a),*(undefined8 *)(puVar3 + 4),puVar2 + 2,
                           param_4,param_5);
        if ((int)uVar1 < 0) {
          DebugTraceError((char)uVar1,"Status",
                          "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",0x1a);
          SafeAllocaFreeToHeap(puVar2);
        }
        else {
          *(undefined4 *)puVar2 = 0x20;
          *(undefined8 *)((longlong)puVar2 + 4) = 0x44444442;
          *(undefined4 *)((longlong)puVar2 + 0xc) = 1;
          puVar2[3] = param_1;
          LOCK();
          param_1[4] = param_1[4] + 1;
          UNLOCK();
          *param_3 = puVar2;
          uVar1 = 0;
        }
        goto LAB_18001270a;
      }
      uVar1 = 0x8009000e;
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_18001270a;
      uVar6 = 9;
      uVar5 = 0xe;
      param_3 = puVar4;
    }
  }
  WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),param_2,param_3,"Status",uVar5,
              "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",uVar6);
LAB_18001270a:
  NormalizeNteStatus(uVar1);
  return;
}



===== SslFreeBuffer @ 180012860 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void SslFreeBuffer(longlong param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  code *pcVar3;
  bool bVar4;
  uint uVar5;
  undefined8 *puVar6;
  longlong *plVar7;
  longlong *plVar8;
  
                    /* 0x12860  142  SslFreeBuffer */
  uVar5 = 0;
  plVar7 = (longlong *)0x0;
  bVar4 = false;
  RtlEnterCriticalSection(&DAT_180027d20);
  puVar1 = SslpProviderBufferList;
  do {
    puVar6 = puVar1;
    if ((undefined8 **)puVar6 == &SslpProviderBufferList) goto LAB_1800128a8;
    plVar7 = puVar6 + -2;
    puVar1 = (undefined8 *)*puVar6;
  } while (puVar6[-1] != param_1);
  if (((undefined8 *)puVar1[1] != puVar6) ||
     (puVar2 = (undefined8 *)puVar6[1], (undefined8 *)*puVar2 != puVar6)) {
    pcVar3 = (code *)swi(0x29);
    (*pcVar3)(3);
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  *puVar2 = puVar1;
  bVar4 = true;
  puVar1[1] = puVar2;
LAB_1800128a8:
  RtlLeaveCriticalSection(&DAT_180027d20);
  plVar8 = (longlong *)0x0;
  if (bVar4) {
    plVar8 = plVar7;
  }
  if (plVar8 == (longlong *)0x0) {
    RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,param_1);
  }
  else {
    uVar5 = (**(code **)(*plVar8 + 0x70))(param_1);
    DereferenceSslProvHandle((uint *)*plVar8,0);
    SafeAllocaFreeToHeap(plVar8);
  }
  NormalizeNteStatus(uVar5);
  return;
}



===== SslExpandBinderKey @ 180012970 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void SslExpandBinderKey(uint *param_1,uint *param_2,undefined8 *param_3,undefined8 param_4,
                       undefined4 param_5)

{
  uint uVar1;
  undefined8 *puVar2;
  uint *puVar3;
  undefined8 *puVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  
                    /* 0x12970  130  SslExpandBinderKey */
  if ((((param_1 == (uint *)0x0) || (*param_1 < 0x1b0)) || (param_1[1] != 0x44444441)) ||
     (param_1[3] != 0)) {
    param_1 = (uint *)0x0;
  }
  if (((param_2 == (uint *)0x0) || (*param_2 < 0x20)) ||
     (puVar3 = param_2, param_2[1] != 0x44444442)) {
    puVar3 = (uint *)0x0;
  }
  if ((param_1 == (uint *)0x0) || (puVar3 == (uint *)0x0)) {
    uVar1 = 0x80090026;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_180012a7a;
    uVar6 = 0xc3;
    uVar5 = 0x26;
  }
  else {
    if (param_3 == (undefined8 *)0x0) {
      uVar1 = 0x80090027;
      DebugTraceError(0x27,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",
                      0xca);
      goto LAB_180012a7a;
    }
    if ((ushort)param_1[8] < 5) {
      uVar1 = 0x80090029;
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_180012a7a;
      uVar6 = 0xd5;
      uVar5 = 0x29;
      uVar1 = 0x80090029;
    }
    else {
      puVar4 = (undefined8 *)0x20;
      param_2 = (uint *)0x0;
      puVar2 = (undefined8 *)
               RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30));
      if (puVar2 != (undefined8 *)0x0) {
        *puVar2 = 0;
        puVar2[1] = 0;
        puVar2[2] = 0;
        puVar2[3] = 0;
        uVar1 = (**(code **)(param_1 + 0x58))
                          (*(undefined8 *)(param_1 + 0x6a),*(undefined8 *)(puVar3 + 4),puVar2 + 2,
                           param_4,param_5);
        if ((int)uVar1 < 0) {
          DebugTraceError((char)uVar1,"Status",
                          "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",0xf2);
          SafeAllocaFreeToHeap(puVar2);
        }
        else {
          *(undefined4 *)puVar2 = 0x20;
          *(undefined8 *)((longlong)puVar2 + 4) = 0x44444442;
          *(undefined4 *)((longlong)puVar2 + 0xc) = 1;
          puVar2[3] = param_1;
          *param_3 = puVar2;
          LOCK();
          param_1[4] = param_1[4] + 1;
          UNLOCK();
          uVar1 = 0;
        }
        goto LAB_180012a7a;
      }
      uVar1 = 0x8009000e;
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_180012a7a;
      uVar6 = 0xe1;
      uVar5 = 0xe;
      param_3 = puVar4;
    }
  }
  WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),param_2,param_3,"Status",uVar5,
              "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",uVar6);
LAB_180012a7a:
  NormalizeNteStatus(uVar1);
  return;
}



===== SslSignHash @ 180012bd0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void SslSignHash(uint *param_1,uint *param_2,undefined8 param_3,undefined8 param_4,
                undefined8 param_5,undefined4 param_6,undefined8 param_7,undefined4 param_8)

{
  uint uVar1;
  undefined1 uVar2;
  
                    /* 0x12bd0  160  SslSignHash */
  if ((((param_1 == (uint *)0x0) || (*param_1 < 0x1b0)) || (param_1[1] != 0x44444441)) ||
     (param_1[3] != 0)) {
    uVar1 = 0x80090026;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_180012cd6;
    uVar2 = 0x66;
  }
  else {
    if (((param_2 != (uint *)0x0) && (0x1f < *param_2)) && (param_2[1] == 0x44444442)) {
      uVar1 = (**(code **)(param_1 + 0x34))
                        (*(undefined8 *)(param_1 + 0x6a),*(undefined8 *)(param_2 + 4),param_3,
                         param_4,param_5,param_6,param_7,param_8);
      if ((int)uVar1 < 0) {
        DebugTraceError((char)uVar1,"Status",
                        "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",0x81);
      }
      else {
        uVar1 = 0;
      }
      goto LAB_180012cd6;
    }
    uVar1 = 0x80090026;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_180012cd6;
    uVar2 = 0x6e;
  }
  uVar1 = 0x80090026;
  WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),param_2,param_3,"Status",0x26,
              "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",uVar2);
LAB_180012cd6:
  NormalizeNteStatus(uVar1);
  return;
}



===== wil_details_FeatureReporting_ReportUsageToService @ 180012d08 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

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



===== wil_details_MapReportingKind @ 180012d90 =====

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



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 180012e30 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool wil_details_FeatureReporting_ReportUsageToServiceDirect
               (longlong param_1,undefined8 param_2,undefined8 param_3)

{
  uint6 uVar1;
  uint *puVar2;
  undefined1 auStack_88 [48];
  undefined8 local_58;
  uint local_50 [10];
  undefined8 local_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_88;
  puVar2 = wil_details_FeatureReporting_RecordUsageInCache
                     (local_50,*(uint **)(param_1 + 8),param_3,(uint)((ulonglong)param_2 >> 0x20));
  local_28 = *(undefined8 *)(puVar2 + 4);
  if ((((uint)param_2 >> 10 & 1) != 0) && ((int)param_3 != 0xfe)) {
    local_58._0_6_ = CONCAT24((short)param_3,*(undefined4 *)(param_1 + 0x18));
    uVar1 = (uint6)local_58;
    local_58 = (ulonglong)(uint6)local_58;
    if (((uint)param_2 >> 0xb & 1) != 0) {
      local_58 = CONCAT26(1,uVar1);
    }
    wil_details_RtlNotifyFeatureUsage(&local_58);
  }
  return (int)local_28 == 0;
}



===== wil_details_FeatureReporting_RecordUsageInCache @ 180012edc =====

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
LAB_180013034:
    wil_details_FeatureReporting_IncrementUsageInCache(param_2,uVar5,param_3,param_1);
  }
  else {
    if (uVar5 == 1) {
LAB_180013027:
      wil_details_FeatureReporting_IncrementOpportunityInCache(param_2,uVar5,param_3,param_1);
      return param_1;
    }
    if ((uVar5 != 2) && (uVar5 != 3)) {
      if (uVar5 == 4) goto LAB_180013034;
      if (uVar5 == 5) goto LAB_180013027;
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



===== CertInUseFree @ 180013060 =====

void CertInUseFree(undefined8 *param_1)

{
  LPVOID lpMem;
  HANDLE hHeap;
  
  if ((param_1 != (undefined8 *)0x0) && (lpMem = (LPVOID)*param_1, lpMem != (LPVOID)0x0)) {
    hHeap = GetProcessHeap();
    HeapFree(hHeap,0,lpMem);
    *param_1 = 0;
  }
  return;
}



===== NCryptCreateClaim @ 1800130c0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void NCryptCreateClaim(int *param_1,int *param_2,undefined8 param_3,undefined8 param_4,
                      undefined8 param_5,undefined4 param_6,undefined8 param_7,undefined4 param_8)

{
  uint uVar1;
  int *piVar2;
  int *piVar3;
  undefined1 uVar4;
  undefined8 uVar5;
  int iVar6;
  longlong lVar7;
  wchar_t *pwVar8;
  undefined1 uVar9;
  int *piVar10;
  undefined8 uVar11;
  
                    /* 0x130c0  66  NCryptCreateClaim */
  piVar3 = (int *)0x0;
  piVar2 = (int *)0x0;
  lVar7 = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    piVar10 = param_1;
    if (param_1 == (int *)0x0) {
      piVar10 = param_2;
    }
    WPP_SF_PDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x24,param_3,piVar10,(char)param_3,
               (char)param_8);
  }
  iVar6 = 5;
  if ((int)param_3 != 4) {
    iVar6 = (int)param_3;
  }
  if (iVar6 - 5U < 2) {
    Feature_Key_Guard_Attestation__private_ReportDeviceUsage();
  }
  if (param_1 == (int *)0x0) {
    if (param_2 == (int *)0x0) {
      uVar1 = 0x80090026;
      uVar9 = 0xbc;
      uVar4 = 0x26;
    }
    else {
LAB_180013238:
      piVar3 = ValidateClientKeyHandle(param_2);
      if (piVar3 != (int *)0x0) {
        if (lVar7 == 0) {
          lVar7 = *(longlong *)(piVar3 + 2);
        }
        goto LAB_18001318d;
      }
      uVar1 = 0x80090026;
      uVar9 = 0xd9;
      uVar4 = 0x26;
    }
  }
  else {
    piVar2 = ValidateClientKeyHandle(param_1);
    if (piVar2 == (int *)0x0) {
      uVar1 = 0x80090026;
      uVar9 = 0xcb;
      uVar4 = 0x26;
    }
    else {
      lVar7 = *(longlong *)(piVar2 + 2);
      if (param_2 != (int *)0x0) goto LAB_180013238;
LAB_18001318d:
      if ((2 < *(ushort *)(lVar7 + 0x10)) && (*(code **)(lVar7 + 0xf0) != (code *)0x0)) {
        if (piVar3 == (int *)0x0) {
          uVar11 = 0;
        }
        else {
          uVar11 = *(undefined8 *)(piVar3 + 4);
        }
        if (piVar2 == (int *)0x0) {
          uVar5 = 0;
        }
        else {
          uVar5 = *(undefined8 *)(piVar2 + 4);
        }
        uVar1 = (**(code **)(lVar7 + 0xf0))
                          (*(undefined8 *)(lVar7 + 0x110),uVar5,uVar11,iVar6,param_4,param_5,param_6
                           ,param_7,param_8);
        if (uVar1 != 0) {
          uVar11 = 0x1101;
          DebugTraceError((char)uVar1,"Status",
                          "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",1);
          if (piVar2 == (int *)0x0) {
            if (piVar3 == (int *)0x0) {
              pwVar8 = L"";
            }
            else {
              pwVar8 = *(wchar_t **)(piVar3 + 6);
            }
          }
          else {
            pwVar8 = *(wchar_t **)(piVar2 + 6);
          }
          EtwLogNCryptOperationFailed(0xe,*(wchar_t **)(lVar7 + 0x118),pwVar8,uVar11,(char)uVar1);
        }
        goto LAB_180013206;
      }
      uVar1 = 0x80090029;
      uVar9 = 0xf0;
      uVar4 = 0x29;
    }
  }
  DebugTraceError(uVar4,"Status",
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",uVar9);
LAB_180013206:
  NormalizeNteStatus(uVar1);
  return;
}



===== WPP_SF_qqSD @ 180013310 =====

void WPP_SF_qqSD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
                undefined1 param_5,wchar_t *param_6,undefined1 param_7)

{
  longlong lVar1;
  longlong lVar2;
  wchar_t *pwVar3;
  undefined8 local_res20;
  
  if (param_6 == (wchar_t *)0x0) {
    lVar2 = 10;
  }
  else {
    lVar2 = -1;
    do {
      lVar1 = lVar2 + 1;
      lVar2 = lVar2 + 1;
    } while (param_6[lVar1] != L'\0');
    lVar2 = lVar2 * 2 + 2;
  }
  pwVar3 = param_6;
  if (param_6 == (wchar_t *)0x0) {
    pwVar3 = L"NULL";
  }
  local_res20 = param_4;
  EtwTraceMessage(param_1,0x2b,&WPP_67679bdabad938a7dfcc8815ccec1def_Traceguids,param_2,&local_res20
                  ,8,&param_5,8,pwVar3,lVar2,&param_7,4,0);
  return;
}



===== McGenControlCallbackV2 @ 1800133e0 =====

void McGenControlCallbackV2
               (undefined8 param_1,int param_2,undefined1 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6,longlong param_7)

{
  uint *puVar1;
  ulonglong uVar2;
  bool bVar3;
  uint uVar4;
  ulonglong uVar5;
  
  if (param_7 != 0) {
    if (param_2 == 0) {
      *(undefined4 *)(param_7 + 0x24) = 0;
      *(undefined1 *)(param_7 + 0x28) = 0;
      *(undefined8 *)(param_7 + 0x10) = 0;
      *(undefined8 *)(param_7 + 0x18) = 0;
      if (*(short *)(param_7 + 0x2a) != 0) {
        memset(*(void **)(param_7 + 0x30),0,
               (longlong)((int)(*(ushort *)(param_7 + 0x2a) - 1) / 0x20 + 1) << 2);
        return;
      }
    }
    else if (param_2 == 1) {
      *(undefined1 *)(param_7 + 0x28) = param_3;
      uVar5 = 0;
      *(undefined8 *)(param_7 + 0x18) = param_5;
      *(undefined8 *)(param_7 + 0x10) = param_4;
      *(undefined4 *)(param_7 + 0x24) = 1;
      if (*(short *)(param_7 + 0x2a) != 0) {
        do {
          uVar2 = *(ulonglong *)(*(longlong *)(param_7 + 0x38) + uVar5 * 8);
          if (((*(byte *)(param_7 + 0x28) < *(byte *)(uVar5 + *(longlong *)(param_7 + 0x40))) &&
              (*(byte *)(param_7 + 0x28) != 0)) ||
             ((uVar2 != 0 &&
              (((*(ulonglong *)(param_7 + 0x10) & uVar2) == 0 ||
               ((*(ulonglong *)(param_7 + 0x18) & uVar2) != *(ulonglong *)(param_7 + 0x18))))))) {
            bVar3 = false;
          }
          else {
            bVar3 = true;
          }
          uVar4 = 1 << ((byte)uVar5 & 0x1f);
          puVar1 = (uint *)(*(longlong *)(param_7 + 0x30) + (uVar5 >> 5) * 4);
          if (bVar3) {
            uVar4 = uVar4 | *puVar1;
          }
          else {
            uVar4 = ~uVar4 & *puVar1;
          }
          *puVar1 = uVar4;
          uVar4 = (int)uVar5 + 1;
          uVar5 = (ulonglong)uVar4;
        } while (uVar4 < *(ushort *)(param_7 + 0x2a));
      }
    }
  }
  return;
}



===== WPP_SF_qS @ 1800134e0 =====

void WPP_SF_qS(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  undefined8 local_res20;
  
  lVar1 = -1;
  do {
    lVar1 = lVar1 + 1;
  } while (*(short *)(&DAT_1800278e0 + lVar1 * 2) != 0);
  local_res20 = param_4;
  TraceMessage(param_1,0x2b,&WPP_4a7a04597ebd39cfc291d74d6f4618d4_Traceguids,param_2,&local_res20,8,
               &DAT_1800278e0,lVar1 * 2 + 2,0);
  return;
}



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 180013554 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

ulonglong wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                    (uint *param_1,ulonglong param_2,longlong param_3)

{
  uint uVar1;
  int iVar2;
  ulonglong uVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  uint local_res8 [2];
  undefined8 local_res10;
  
  iVar2 = 0;
  local_res8[0] = 0;
  local_res10 = param_2;
  if (g_wil_details_ensureSubscribedToFeatureConfigurationChanges != (code *)0x0) {
    iVar2 = (*g_wil_details_ensureSubscribedToFeatureConfigurationChanges)();
  }
  uVar1 = wil_details_GetCurrentFeatureEnabledState(param_3,local_res8);
  if (*(char *)(param_3 + 0x1c) == '\0') {
    local_res8[0] = local_res8[0] & -(uint)(iVar2 != 0);
  }
  uVar3 = param_2 & 0xffffffff;
  while( true ) {
    uVar5 = (uint)uVar3;
    local_res10 = CONCAT44(local_res10._4_4_,uVar5);
    if ((local_res8[0] != 0) && (local_res10 = CONCAT44(local_res10._4_4_,uVar5), (uVar3 & 2) == 0))
    {
      uVar4 = uVar5 & 0xfffff63e | uVar1 & 0x9c1;
      uVar5 = uVar4 | 2;
      local_res10 = CONCAT44(local_res10._4_4_,uVar4) | 2;
    }
    if ((param_2 & 4) == 0) {
      uVar4 = uVar1 & 0x400 | uVar5 & 0xfffffbff;
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
              (param_1,*(undefined1 *)(param_3 + 0x1c),iVar2);
  }
  if (local_res8[0] == 0) {
    local_res10 = CONCAT44(local_res10._4_4_,uVar1 & 0x9c1 | uVar5 & 0xfffff63e);
  }
  return local_res10;
}



===== wil_details_GetCurrentFeatureEnabledState @ 180013680 =====

uint wil_details_GetCurrentFeatureEnabledState(longlong param_1,undefined4 *param_2)

{
  char cVar1;
  undefined8 *puVar2;
  uint uVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  uint uVar6;
  longlong *plVar7;
  uint local_res8;
  ulonglong local_res10;
  uint local_28 [8];
  
  cVar1 = *(char *)(param_1 + 0x1c);
  *param_2 = 1;
  local_28[4] = 0;
  local_28[5] = 0;
  local_28[0] = 0;
  local_28[1] = 0;
  local_28[2] = 0;
  local_28[3] = 0;
  uVar4 = wil_RtlStagingConfig_QueryFeatureState
                    (local_28,*(undefined4 *)(param_1 + 0x18),(uint)((byte)(cVar1 - 2U) < 2));
  uVar3 = -(uint)((int)uVar4 != 0) & local_28[0] & 3;
  if (uVar3 == 0) {
    uVar6 = -(uint)(*(char *)(param_1 + 0x1f) != '\0') & 0x40;
  }
  else {
    uVar6 = 0;
    if (local_28[0] == 2) {
      uVar6 = 0x40;
    }
  }
  local_res8 = uVar6 >> 6 ^
               (uVar3 << 7 | -(uint)(local_28[5] != 0) & 0x800 | -(uint)(local_28[4] != 0) & 0x400 |
               uVar6);
  if ((uVar6 != 0) && (plVar7 = *(longlong **)(param_1 + 0x20), plVar7 != (longlong *)0x0)) {
    do {
      puVar2 = (undefined8 *)*plVar7;
      if (puVar2 == (undefined8 *)0x0) {
        return local_res8;
      }
      if ((*(char *)((longlong)puVar2 + 0x1e) == '\0') &&
         (*(char *)((longlong)puVar2 + 0x1d) == '\0')) {
        uVar6 = *(uint *)*puVar2;
        local_res10 = (ulonglong)uVar6;
        if ((uVar6 & 2) == 0) {
          uVar5 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                            ((uint *)*puVar2,local_res10,(longlong)puVar2);
          uVar6 = (uint)uVar5;
        }
        uVar3 = local_res8 & 0xfffffffe;
        local_res8 = (uint)((uVar6 & local_res8 & 1) != 0);
      }
      else {
        if (((local_res8 & 1) == 0) || (*(char *)((longlong)puVar2 + 0x1f) == '\0')) {
          uVar3 = 0;
        }
        else {
          uVar3 = 1;
        }
        local_res8 = local_res8 & 0xfffffffe;
      }
      local_res8 = local_res8 | uVar3;
      plVar7 = plVar7 + 1;
    } while ((local_res8 & 1) != 0);
  }
  return local_res8;
}



===== wil_RtlStagingConfig_QueryFeatureState @ 1800137dc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 wil_RtlStagingConfig_QueryFeatureState(uint *param_1,undefined4 param_2,int param_3)

{
  undefined8 uVar1;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined8 local_20;
  uint local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  local_28 = 0;
  local_20 = 0;
  local_18 = 0;
  uVar1 = wil_details_RtlQueryFeatureConfiguration(param_2,(uint)(param_3 == 0),&local_28,&local_20)
  ;
  if ((int)uVar1 == 0) {
    *param_1 = local_20._4_4_ >> 4 & 3;
    *(byte *)(param_1 + 1) = (byte)((ulonglong)local_20 >> 0x28) & 0x3f;
    param_1[3] = local_18;
    param_1[2] = local_20._4_4_ >> 0xe & 3;
    param_1[5] = local_20._4_4_ >> 6 & 1;
    param_1[4] = local_20._4_4_ >> 7 & 1;
  }
  else {
    if ((int)uVar1 != 0x117) {
      return 0;
    }
    param_1[4] = local_20._4_4_ >> 7 & 1;
  }
  return 1;
}



===== wil_details_RtlQueryFeatureConfiguration @ 1800138a4 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

undefined8
wil_details_RtlQueryFeatureConfiguration
          (undefined4 param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  
  if ((g_wil_details_pfnRtlQueryFeatureConfiguration == (code *)0x0) &&
     (g_wil_details_pfnRtlQueryFeatureConfiguration =
           (code *)wil_details_GetNtDllProcedureAddress("RtlQueryFeatureConfiguration"),
     g_wil_details_pfnRtlQueryFeatureConfiguration == (code *)0x0)) {
    return 0xc0000139;
  }
  uVar1 = (*g_wil_details_pfnRtlQueryFeatureConfiguration)(param_1,param_2,param_3,param_4);
  return uVar1;
}



===== SslEnumProtocolProviders @ 180013920 =====

void SslEnumProtocolProviders(undefined4 *param_1,longlong *param_2,int param_3)

{
  WCHAR WVar1;
  WCHAR WVar2;
  short sVar3;
  short sVar4;
  short *psVar5;
  size_t _Size;
  uint uVar6;
  longlong lVar7;
  PWSTR pWVar8;
  short *psVar9;
  longlong lVar11;
  longlong lVar10;
  PCRYPT_PROVIDER_REFS pvBuffer;
  int iVar12;
  void *_Dst;
  int iVar13;
  uint uVar14;
  undefined1 uVar15;
  PCRYPT_PROVIDER_REF *pp_Var16;
  PCRYPT_PROVIDER_REF *pp_Var17;
  undefined4 uVar18;
  ulonglong uVar19;
  ULONG local_res8 [2];
  PCRYPT_PROVIDER_REFS local_res20;
  
                    /* 0x13920  129  SslEnumProtocolProviders */
  local_res20 = (PCRYPT_PROVIDER_REFS)0x0;
  local_res8[0] = 0;
  iVar12 = 0;
  iVar13 = 0;
  if ((param_1 == (undefined4 *)0x0) || (param_2 == (longlong *)0x0)) {
    uVar6 = 0x80090027;
    uVar15 = 0x37;
  }
  else if (param_3 == 0) {
    *param_1 = 0;
    *param_2 = 0;
    uVar6 = BCryptResolveProviders
                      ((LPCWSTR)0x0,0x10002,(LPCWSTR)0x0,(LPCWSTR)0x0,1,3,local_res8,&local_res20);
    if ((int)uVar6 < 0) {
      uVar15 = 0x57;
    }
    else {
      uVar6 = 0;
      if (local_res20->cProviders != 0) {
        lVar7 = 0;
        do {
          uVar14 = 0;
          if (uVar6 == 0) {
LAB_180013add:
            lVar10 = -1;
            do {
              lVar10 = lVar10 + 1;
            } while (*(short *)(*(longlong *)
                                 (*(longlong *)(lVar7 + (longlong)local_res20->rgpProviders) + 0x10)
                               + lVar10 * 2) != 0);
            iVar12 = iVar12 + (int)lVar10 * 2 + 2;
            iVar13 = iVar13 + 1;
          }
          else {
            pp_Var17 = local_res20->rgpProviders;
            psVar5 = *(short **)(*(longlong *)(lVar7 + (longlong)pp_Var17) + 0x10);
            do {
              psVar9 = psVar5;
              do {
                sVar3 = *psVar9;
                sVar4 = *(short *)((longlong)psVar9 +
                                  ((longlong)(*pp_Var17)->pszProvider - (longlong)psVar5));
                if (sVar3 != sVar4) break;
                psVar9 = psVar9 + 1;
              } while (sVar4 != 0);
              if (sVar3 == sVar4) break;
              uVar14 = uVar14 + 1;
              pp_Var17 = pp_Var17 + 1;
            } while (uVar14 < uVar6);
            if (uVar6 <= uVar14) goto LAB_180013add;
          }
          uVar6 = uVar6 + 1;
          lVar7 = lVar7 + 8;
        } while (uVar6 < local_res20->cProviders);
      }
      lVar7 = MSCryptAlloc((ulonglong)(uint)(iVar13 * 0x10 + iVar12));
      if (lVar7 != 0) {
        uVar19 = 0;
        uVar18 = 0;
        uVar6 = 0;
        _Dst = (void *)((ulonglong)(uint)(iVar13 * 0x10) + lVar7);
        pvBuffer = local_res20;
        if (local_res20->cProviders != 0) {
          do {
            uVar14 = 0;
            if (uVar6 == 0) {
LAB_180013b27:
              lVar10 = -1;
              do {
                lVar11 = lVar10;
                lVar10 = lVar11 + 1;
              } while (pvBuffer->rgpProviders[uVar6]->pszProvider[lVar10] != L'\0');
              _Size = (ulonglong)((int)lVar11 + 2) * 2;
              *(void **)(lVar7 + uVar19 * 0x10) = _Dst;
              *(undefined8 *)(lVar7 + 8 + uVar19 * 0x10) = 0;
              memcpy(_Dst,local_res20->rgpProviders[uVar6]->pszProvider,_Size);
              _Dst = (void *)((longlong)_Dst + _Size);
              uVar19 = (ulonglong)((int)uVar19 + 1);
              pvBuffer = local_res20;
            }
            else {
              pp_Var16 = pvBuffer->rgpProviders;
              pp_Var17 = pp_Var16 + uVar6;
              do {
                pWVar8 = (*pp_Var17)->pszProvider;
                do {
                  WVar1 = *pWVar8;
                  WVar2 = *(WCHAR *)((longlong)pWVar8 +
                                    ((longlong)(*pp_Var16)->pszProvider -
                                    (longlong)(*pp_Var17)->pszProvider));
                  if (WVar1 != WVar2) break;
                  pWVar8 = pWVar8 + 1;
                } while (WVar2 != L'\0');
                if (WVar1 == WVar2) break;
                uVar14 = uVar14 + 1;
                pp_Var16 = pp_Var16 + 1;
              } while (uVar14 < uVar6);
              if (uVar6 <= uVar14) goto LAB_180013b27;
            }
            uVar18 = (undefined4)uVar19;
            uVar6 = uVar6 + 1;
          } while (uVar6 < pvBuffer->cProviders);
        }
        *param_1 = uVar18;
        uVar6 = 0;
        *param_2 = lVar7;
        goto LAB_180013a59;
      }
      uVar6 = 0x8009000e;
      uVar15 = 0x85;
    }
  }
  else {
    uVar6 = 0x80090009;
    uVar15 = 0x3f;
  }
  DebugTraceError((char)uVar6,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",
                  uVar15);
  pvBuffer = local_res20;
LAB_180013a59:
  if (pvBuffer != (PCRYPT_PROVIDER_REFS)0x0) {
    BCryptFreeBuffer(pvBuffer);
  }
  NormalizeNteStatus(uVar6);
  return;
}



===== _NewLoadedProviderHandle @ 180013bd4 =====

undefined4 _NewLoadedProviderHandle(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  ulonglong uVar1;
  byte bVar2;
  undefined1 uVar3;
  longlong lVar4;
  undefined8 *puVar5;
  undefined4 uVar6;
  undefined1 uVar7;
  short *psVar8;
  
  puVar5 = *(undefined8 **)(param_1 + 0x28);
  *param_3 = 0;
  uVar6 = 0;
  psVar8 = (short *)*puVar5;
  if (psVar8 == (short *)0x0) {
    bVar2 = 0x57;
    puVar5 = param_3;
LAB_180013c89:
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),WPP_GLOBAL_Control,puVar5,"hResult",
                  bVar2,"onecore\\ds\\security\\cryptoapi\\ncrypt\\loader\\loader.c",0x52);
    }
    uVar6 = 0xc000000d;
  }
  else {
    lVar4 = 0x800;
    do {
      if (*psVar8 == 0) break;
      psVar8 = psVar8 + 1;
      lVar4 = lVar4 + -1;
    } while (lVar4 != 0);
    bVar2 = ~-(lVar4 != 0) & 0x57;
    puVar5 = (undefined8 *)0x800;
    if (lVar4 == 0) goto LAB_180013c89;
    uVar1 = -(ulonglong)(lVar4 != 0) & (0x800 - lVar4) * 2;
    if ((uVar1 + 2 < uVar1) || (uVar1 + 0x22 < 0x20)) {
      uVar6 = 0xc0000095;
      uVar7 = 0x5c;
      uVar3 = 0x95;
    }
    else {
      puVar5 = (undefined8 *)
               RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0);
      if (puVar5 != (undefined8 *)0x0) {
        *puVar5 = puVar5 + 4;
        memcpy(puVar5 + 4,(void *)**(undefined8 **)(param_1 + 0x28),uVar1 + 2);
        puVar5[1] = param_2;
        *(undefined4 *)(puVar5 + 2) = 2;
        puVar5[3] = 0;
        goto LAB_180013cae;
      }
      uVar6 = 0xc0000017;
      uVar7 = 0x6f;
      uVar3 = 0x17;
    }
    DebugTraceError(uVar3,"sResult","onecore\\ds\\security\\cryptoapi\\ncrypt\\loader\\loader.c",
                    uVar7);
  }
  puVar5 = (undefined8 *)0x0;
LAB_180013cae:
  *param_3 = puVar5;
  return uVar6;
}



===== NCryptProtectKey @ 180013d70 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

int NCryptProtectKey(int *param_1,undefined8 *param_2,undefined8 param_3,undefined4 param_4,
                    undefined *param_5,undefined8 param_6,undefined8 param_7,undefined4 param_8)

{
  int iVar1;
  undefined8 *puVar2;
  undefined *puVar3;
  undefined8 uVar4;
  
                    /* 0x13d70  93  NCryptProtectKey */
  puVar2 = param_2;
  uVar4 = param_3;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    puVar2 = (undefined8 *)0xe;
    WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0xe,param_3,param_1,(char)param_8);
  }
  if (((param_1 == (int *)0x0) || (*param_1 != 0x48)) || (*(longlong *)(param_1 + 0xe) == 0)) {
    iVar1 = -0x7ff6ffda;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),puVar2,uVar4,"Status",0x26,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\router.c",0x7b)
      ;
    }
  }
  else {
    puVar3 = &NCryptDefaultAllocPara;
    if (param_5 != (undefined *)0x0) {
      puVar3 = param_5;
    }
    puVar2 = param_2;
    iVar1 = (**(code **)(param_1 + 10))
                      (*(undefined8 *)(param_1 + 0xe),param_2,param_3,param_4,puVar3,param_6,param_7
                       ,param_8);
    if (iVar1 != 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
        WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),puVar2,param_3,"Status",(char)iVar1,
                    "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\router.c",
                    0x90);
      }
      EtwLogNCryptProtectKeyFailed
                ((wchar_t *)*param_2,(wchar_t *)param_2[1],(char)param_8,(char)iVar1);
    }
  }
  return iVar1;
}



===== NCryptUnprotectKey @ 180013f10 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

int NCryptUnprotectKey(int *param_1,int *param_2,undefined *param_3,undefined8 param_4,
                      undefined8 param_5,undefined8 param_6,undefined4 param_7)

{
  int iVar1;
  int *piVar2;
  undefined *puVar3;
  
                    /* 0x13f10  107  NCryptUnprotectKey */
  piVar2 = param_2;
  puVar3 = param_3;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    piVar2 = (int *)0xf;
    WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0xf,param_3,param_1,(char)param_7);
  }
  if (((param_1 == (int *)0x0) || (*param_1 != 0x48)) || (*(longlong *)(param_1 + 0xe) == 0)) {
    iVar1 = -0x7ff6ffda;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),piVar2,puVar3,"Status",0x26,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\router.c",0xbe)
      ;
    }
  }
  else {
    puVar3 = &NCryptDefaultAllocPara;
    if (param_3 != (undefined *)0x0) {
      puVar3 = param_3;
    }
    iVar1 = (**(code **)(param_1 + 0xc))
                      (*(undefined8 *)(param_1 + 0xe),param_2,puVar3,param_4,param_5,param_6,param_7
                      );
    if (iVar1 != 0) {
      DebugTraceError((char)iVar1,"Status",
                      "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\router.c",
                      0xd2);
      EtwLogNCryptUnprotectKeyFailed
                (*(wchar_t **)(param_1 + 0x10),param_2,(char)param_7,(char)iVar1);
    }
  }
  return iVar1;
}



===== WPP_SF_qd @ 180014078 =====

void WPP_SF_qd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  EtwTraceMessage(param_1,0x2b,&WPP_6d353d9995a633fdfdb515b4bb0c31fa_Traceguids,param_2,&local_res20
                  ,8,&param_5,4,0);
  return;
}



===== EtwLogNCryptProtectKeyFailed @ 1800140d0 =====

undefined8
EtwLogNCryptProtectKeyFailed
          (wchar_t *param_1,wchar_t *param_2,undefined1 param_3,undefined1 param_4)

{
  wchar_t *pwVar1;
  undefined8 uVar2;
  wchar_t *pwVar3;
  wchar_t *pwVar4;
  
  if ((Microsoft_Windows_Crypto_NCryptEnableBits & 2) == 0) {
    uVar2 = 0;
  }
  else {
    pwVar3 = param_1;
    pwVar4 = param_2;
    pwVar1 = I_GetProcessName();
    uVar2 = McTemplateU0zzddz_EventWriteTransfer
                      (pwVar3,pwVar4,param_1,param_2,param_3,param_4,pwVar1);
  }
  return uVar2;
}



===== McTemplateU0zzddz_EventWriteTransfer @ 180014138 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateU0zzddz_EventWriteTransfer
               (undefined8 param_1,undefined8 param_2,wchar_t *param_3,wchar_t *param_4,
               undefined1 param_5,undefined1 param_6,wchar_t *param_7)

{
  longlong lVar1;
  longlong lVar2;
  undefined1 auStackY_a8 [32];
  _EVENT_DATA_DESCRIPTOR local_78;
  wchar_t *local_68;
  int local_60;
  undefined4 local_5c;
  wchar_t *local_58;
  int local_50;
  undefined4 local_4c;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  wchar_t *local_28;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  lVar1 = -1;
  local_20 = 10;
  if (param_3 == (wchar_t *)0x0) {
    local_60 = 10;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (param_3[lVar2] != L'\0');
    local_60 = (int)lVar2 * 2 + 2;
  }
  local_5c = 0;
  if (param_3 == (wchar_t *)0x0) {
    param_3 = L"NULL";
  }
  if (param_4 == (wchar_t *)0x0) {
    local_50 = 10;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (param_4[lVar2] != L'\0');
    local_50 = (int)lVar2 * 2 + 2;
  }
  local_48 = &param_5;
  local_4c = 0;
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"NULL";
  }
  local_38 = &param_6;
  local_40 = 4;
  local_30 = 4;
  if (param_7 != (wchar_t *)0x0) {
    do {
      lVar1 = lVar1 + 1;
    } while (param_7[lVar1] != L'\0');
    local_20 = (int)lVar1 * 2 + 2;
  }
  local_28 = param_7;
  if (param_7 == (wchar_t *)0x0) {
    local_28 = L"NULL";
  }
  local_1c = 0;
  local_68 = param_3;
  local_58 = param_4;
  McGenEventWrite_EventWriteTransfer
            (local_38,(PCEVENT_DESCRIPTOR)&ETW_LOG_NCRYPT_PROTECT_KEY_FAILED,param_3,6,&local_78);
  return;
}



===== _tlgEnableCallback @ 180014270 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

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



===== _FindInLoadedProviderList @ 1800142ec =====

undefined8 * _FindInLoadedProviderList(longlong param_1)

{
  int iVar1;
  undefined8 *puVar2;
  
  puVar2 = g_pLoadedProviderList;
  while( true ) {
    if (puVar2 == (undefined8 *)0x0) {
      return (undefined8 *)0x0;
    }
    iVar1 = _wcsicmp((wchar_t *)**(undefined8 **)(param_1 + 0x28),(wchar_t *)*puVar2);
    if (iVar1 == 0) break;
    puVar2 = (undefined8 *)puVar2[3];
  }
  return puVar2;
}



===== _GetProviderValueAndMoveCursToUnparsed @ 18001433c =====

undefined8 _GetProviderValueAndMoveCursToUnparsed(undefined8 *param_1,undefined8 *param_2)

{
  ushort uVar1;
  ushort *puVar2;
  ushort *puVar3;
  undefined1 uVar4;
  
  puVar2 = (ushort *)*param_1;
  while( true ) {
    uVar1 = *puVar2;
    if (uVar1 != 0x20) break;
    puVar2 = puVar2 + 1;
  }
  if (uVar1 != 0) {
    puVar3 = puVar2 + 1;
    if (uVar1 != 0x22) {
      puVar3 = puVar2;
    }
    puVar2 = puVar3;
    do {
      if (uVar1 == 0x22) {
        if (*puVar2 == 0) {
          if (*puVar2 != 0x22) {
            DebugTraceError(5,"hr",
                            "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\descriptor.c"
                            ,0xac);
            return 0x80090005;
          }
        }
        else if (*puVar2 != 0x22) goto LAB_18001438a;
LAB_18001439f:
        *puVar2 = 0;
        puVar2 = puVar2 + 1;
LAB_1800143a6:
        *param_1 = puVar2;
        *param_2 = puVar3;
        return 0;
      }
      if (*puVar2 == 0) goto LAB_1800143a6;
      if (*puVar2 == 0x20) goto LAB_18001439f;
      if (*puVar2 == 0x22) goto LAB_180014401;
LAB_18001438a:
      puVar2 = puVar2 + 1;
    } while( true );
  }
  if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
    return 0x80090005;
  }
  if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
    return 0x80090005;
  }
  uVar4 = 0x8e;
LAB_1800143d4:
  WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),param_2,(ulonglong)uVar1,"hr",5,
              "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\descriptor.c",uVar4
             );
  return 0x80090005;
LAB_180014401:
  if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
    return 0x80090005;
  }
  if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
    return 0x80090005;
  }
  uVar4 = 0xa3;
  goto LAB_1800143d4;
}



===== WppControlCallback @ 180014470 =====

undefined8 WppControlCallback(int param_1,longlong param_2,undefined4 *param_3,undefined8 param_4)

{
  undefined1 uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  *param_3 = 0;
  if (param_1 == 4) {
    uVar3 = GetTraceLoggerHandle(param_4);
    uVar1 = GetTraceEnableLevel(uVar3);
    uVar2 = GetTraceEnableFlags(uVar3);
  }
  else {
    if (param_1 != 5) {
      return 0x57;
    }
    uVar3 = 0;
    uVar2 = 0;
    uVar1 = 0;
  }
  if (((*(byte *)(param_2 + 0x1a) & 2) != 0) && (*(longlong *)(param_2 + 0x10) != 0)) {
    param_2 = *(longlong *)(param_2 + 0x10);
  }
  *(undefined4 *)(param_2 + 0x1c) = uVar2;
  *(undefined8 *)(param_2 + 0x10) = uVar3;
  *(undefined1 *)(param_2 + 0x19) = uVar1;
  return 0;
}



===== _GetProviderNameAndMoveCursToProviderValue @ 18001450c =====

undefined8 _GetProviderNameAndMoveCursToProviderValue(undefined8 *param_1,undefined8 *param_2)

{
  short *psVar1;
  short *psVar2;
  undefined8 uVar3;
  short sVar4;
  undefined1 uVar5;
  
  uVar3 = 0;
  for (psVar1 = (short *)*param_1; sVar4 = *psVar1, sVar4 == 0x20; psVar1 = psVar1 + 1) {
  }
  psVar2 = psVar1;
  if (sVar4 == 0) {
    uVar3 = 0x80090005;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      uVar5 = 0x34;
LAB_18001459e:
      uVar3 = 0x80090005;
      WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),param_2,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\descriptor.c",
                  "hr",5,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\descriptor.c",
                  uVar5);
    }
  }
  else {
    while ((sVar4 != 0x3d && (sVar4 != 0x20))) {
      if (sVar4 == 0) goto LAB_180014569;
      if (sVar4 == 0x22) {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return 0x80090005;
        }
        if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
          return 0x80090005;
        }
        uVar5 = 0x45;
        goto LAB_18001459e;
      }
      sVar4 = psVar2[1];
      psVar2 = psVar2 + 1;
    }
    *psVar2 = 0;
    psVar2 = psVar2 + 1;
    if (sVar4 == 0x20) {
      for (; *psVar2 == 0x20; psVar2 = psVar2 + 1) {
      }
      if (*psVar2 != 0x3d) {
        DebugTraceError(5,"hr",
                        "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\descriptor.c"
                        ,0x62);
        return 0x80090005;
      }
      psVar2 = psVar2 + 1;
    }
LAB_180014569:
    *param_1 = psVar2;
    *param_2 = psVar1;
  }
  return uVar3;
}



===== NCryptCreateProtectionDescriptor @ 180014640 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

uint NCryptCreateProtectionDescriptor(LPCWSTR param_1,ulonglong param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  ulonglong _Size;
  longlong lVar2;
  uint uVar3;
  undefined8 uVar4;
  LPCWSTR _Dst;
  ulonglong uVar5;
  uint uVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  STRSAFE_LPCWSTR pwVar9;
  undefined1 uVar10;
  uint uVar11;
  undefined1 auStackY_78 [32];
  ulonglong local_38;
  ulonglong local_30;
  
                    /* 0x14640  68  NCryptCreateProtectionDescriptor */
  puVar8 = auStackY_78;
  puVar7 = auStackY_78;
  local_30 = __security_cookie ^ (ulonglong)&local_38;
  local_38 = 0;
  uVar6 = (uint)param_2;
  pwVar9 = (STRSAFE_LPCWSTR)0x0;
  if (param_3 == (undefined8 *)0x0) {
    uVar3 = 0x80090027;
    puVar8 = auStackY_78;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (puVar8 = auStackY_78, (WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),param_2,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\ncryptprotect.c"
                  ,"Status",0x27,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\ncryptprotect.c"
                  ,0x12);
      puVar8 = auStackY_78;
    }
    goto LAB_1800146dc;
  }
  *param_3 = 0;
  if ((param_1 == (LPCWSTR)0x0) || (*param_1 == L'\0')) {
    uVar3 = 0x80090027;
    uVar10 = 0x1d;
  }
  else if ((param_2 & 0xffffffde) == 0) {
    _Dst = param_1;
    uVar11 = uVar6;
    if ((param_2 & 1) == 0) {
LAB_1800146b5:
      *(undefined8 **)(puVar8 + 0x20) = param_3;
      uVar4 = 0;
      *(undefined8 *)(puVar8 + -8) = 0x1800146ca;
      uVar3 = I_CreateProtectionDescriptor
                        (_Dst,(uint *)0x0,(char *)0x0,uVar11,*(undefined8 **)(puVar8 + 0x20));
      if (uVar3 == 0) {
        uVar3 = 0;
      }
      else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
        uVar1 = *(undefined8 *)(WPP_GLOBAL_Control + 0x10);
        *(undefined4 *)(puVar8 + 0x30) = 0x16b;
        *(char **)(puVar8 + 0x28) =
             "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\ncryptprotect.c";
        *(uint *)(puVar8 + 0x20) = uVar3;
        *(undefined8 *)(puVar8 + -8) = 0x180014746;
        WPP_SF_sDsd(uVar1,uVar4,
                    "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\ncryptprotect.c"
                    ,"Status",puVar8[0x20],*(char **)(puVar8 + 0x28),puVar8[0x30]);
      }
      _Dst = pwVar9;
      if (pwVar9 == (STRSAFE_LPCWSTR)0x0) goto LAB_1800146dc;
LAB_1800148e3:
      if (*(int *)(_Dst + -4) == 0x70616548) {
        *(undefined8 *)(puVar8 + -8) = 0x1800148ff;
        (*g_pfnFree)();
      }
      goto LAB_1800146dc;
    }
    uVar11 = uVar6 & 0xfffffffe;
    uVar3 = NCryptQueryProtectionDescriptorName
                      (param_1,(LPBYTE)0x0,&local_38,(ulonglong)(uVar6 & 0x20));
    if (uVar3 == 0) {
      if (local_38 < 2) {
        uVar3 = 0x80090011;
        uVar10 = 0x42;
        puVar7 = auStackY_78;
      }
      else {
        _Size = local_38 * 2;
        puVar7 = auStackY_78;
        if (((_Size == 0) || (puVar7 = auStackY_78, g_ulMaxStackAllocSize < _Size)) ||
           (uVar5 = g_ulAdditionalProbeSize + 8 + _Size, puVar7 = auStackY_78, uVar5 < _Size)) {
LAB_180014865:
          puVar8 = puVar7;
          _Dst = pwVar9;
          if (_Size <= _Size + 8) {
            *(undefined8 *)(puVar7 + -8) = 0x18001487a;
            _Dst = (LPCWSTR)(*g_pfnAllocate)();
            if (_Dst != (STRSAFE_LPCWSTR)0x0) {
              _Dst[0] = L'效';
              _Dst[1] = L'灡';
              _Dst = _Dst + 4;
            }
          }
        }
        else {
          uVar4 = VerifyStackAvailable(uVar5);
          puVar7 = auStackY_78;
          if ((int)uVar4 == 0) goto LAB_180014865;
          uVar5 = _Size + 0x17;
          if (uVar5 <= _Size + 8) {
            uVar5 = 0xffffffffffffff0;
          }
          lVar2 = -(uVar5 & 0xfffffffffffffff0);
          pwVar9 = (STRSAFE_LPCWSTR)0x0;
          puVar7 = auStackY_78 + lVar2;
          if ((undefined4 *)((longlong)&local_38 + lVar2) == (undefined4 *)0x0) goto LAB_180014865;
          *(undefined4 *)((longlong)&local_38 + lVar2) = 0x6b637453;
          pwVar9 = (STRSAFE_LPCWSTR)((longlong)&local_30 + lVar2);
          puVar7 = auStackY_78 + lVar2;
          puVar8 = auStackY_78 + lVar2;
          _Dst = pwVar9;
          if (pwVar9 == (STRSAFE_LPCWSTR)0x0) goto LAB_180014865;
        }
        if (_Dst != (STRSAFE_LPCWSTR)0x0) {
          *(undefined8 *)(puVar8 + -8) = 0x1800148b0;
          memset(_Dst,0,_Size);
          *(undefined8 *)(puVar8 + -8) = 0x1800148c2;
          uVar3 = NCryptQueryProtectionDescriptorName
                            (param_1,(LPBYTE)_Dst,&local_38,(ulonglong)(uVar6 & 0x20));
          if (uVar3 == 0) {
            pwVar9 = _Dst;
            goto LAB_1800146b5;
          }
          *(undefined8 *)(puVar8 + -8) = 0x1800148e3;
          DebugTraceError((char)uVar3,"Status",
                          "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\ncryptprotect.c"
                          ,0x59);
          goto LAB_1800148e3;
        }
        uVar3 = 0x8009000e;
        uVar10 = 0x4b;
        puVar7 = puVar8;
      }
    }
    else {
      uVar10 = 0x3b;
      puVar7 = auStackY_78;
    }
  }
  else {
    uVar3 = 0x80090009;
    uVar10 = 0x28;
    puVar7 = auStackY_78;
  }
  *(undefined8 *)(puVar7 + -8) = 0x18001492f;
  DebugTraceError((char)uVar3,"Status",
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\ncryptprotect.c"
                  ,uVar10);
  puVar8 = puVar7;
LAB_1800146dc:
  *(undefined8 *)(puVar8 + -8) = 0x1800146ea;
  return uVar3;
}



===== NCryptMsgEncode @ 18001493c =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

int NCryptMsgEncode(int *param_1,undefined8 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined8 local_res8;
  longlong local_res10;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  longlong lStack_30;
  
  local_res10 = 0;
  local_res8 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  lStack_30 = 0;
  if ((param_2 == (undefined8 *)0x0) || (param_3 == (undefined4 *)0x0)) {
    iVar1 = -0x7ff6ffd9;
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x7ff6ffd9;
    }
    if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
      return -0x7ff6ffd9;
    }
    uVar4 = 0xf4;
    uVar3 = 0x27;
  }
  else {
    *param_2 = 0;
    *param_3 = 0;
    if ((param_1 == (int *)0x0) || (*param_1 != 0x170)) {
      iVar1 = -0x7ff6ffda;
      DebugTraceError(0x26,"Status",
                      "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptcms\\ncryptcms.c",0)
      ;
      goto LAB_180014a59;
    }
    if ((*(longlong *)(param_1 + 0x10) == 0) || (*(longlong *)(param_1 + 0x36) == 0)) {
      iVar1 = -0x7ff6ffd7;
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return -0x7ff6ffd7;
      }
      if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
        return -0x7ff6ffd7;
      }
      uVar4 = 9;
      uVar3 = 0x29;
    }
    else {
      puVar2 = (undefined4 *)0x0;
      iVar1 = Ordinal_2(ASN1_NCRYPT_MODULE_HANDLE,
                        *(undefined4 *)(*(longlong *)(param_1 + 0x10) + 0x18),0,param_1 + 4,
                        &local_res10,&local_res8,*(longlong *)(param_1 + 0x36));
      if (iVar1 == 0) {
        puVar2 = (undefined4 *)0x0;
        uStack_40 = *(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x10);
        local_48 = CONCAT44(local_48._4_4_,*(undefined4 *)(*(longlong *)(param_1 + 0x10) + 8));
        lStack_30 = local_res10;
        local_38 = CONCAT44(local_38._4_4_,(undefined4)local_res8);
        iVar1 = Ordinal_2(ASN1_NCRYPT_MODULE_HANDLE,0x14,0,param_1 + 4,param_2,&local_res8,&local_48
                         );
        if (iVar1 == 0) {
          *param_3 = (undefined4)local_res8;
          goto LAB_180014a59;
        }
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_180014a59;
        uVar4 = 0x2c;
      }
      else {
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_180014a59;
        uVar4 = 0x18;
      }
      uVar3 = (undefined1)iVar1;
      param_3 = puVar2;
    }
  }
  WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),WPP_GLOBAL_Control,param_3,"Status",uVar3,
              "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptcms\\ncryptcms.c",uVar4);
LAB_180014a59:
  if (local_res10 != 0) {
    (**(code **)(param_1 + 8))();
  }
  return iVar1;
}



===== NCryptEnumStorageProviders @ 180014bb0 =====

SECURITY_STATUS __stdcall
NCryptEnumStorageProviders
          (DWORD *pdwProviderCount,NCryptProviderName **ppProviderList,DWORD dwFlags)

{
  uint uVar1;
  longlong lVar2;
  NCryptProviderName *pNVar3;
  longlong lVar4;
  undefined1 uVar5;
  PCRYPT_PROVIDER_REF *pp_Var6;
  NCryptProviderName **ppNVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  LPWSTR _Dst;
  int iVar10;
  undefined4 in_register_00000084;
  wchar_t *pwVar11;
  undefined1 uVar12;
  uint uVar13;
  ULONG local_res8 [2];
  PCRYPT_PROVIDER_REFS local_res20;
  
                    /* 0x14bb0  78  NCryptEnumStorageProviders */
  pwVar11 = (wchar_t *)CONCAT44(in_register_00000084,dwFlags);
  local_res20 = (PCRYPT_PROVIDER_REFS)0x0;
  local_res8[0] = 0;
  iVar10 = 0;
  if ((pdwProviderCount == (DWORD *)0x0) || (ppProviderList == (NCryptProviderName **)0x0)) {
    uVar1 = 0x80090027;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_180014d3a;
    uVar12 = 0xcd;
    uVar5 = 0x27;
    uVar1 = 0x80090027;
LAB_180014d93:
    WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),ppProviderList,pwVar11,"Status",uVar5,
                "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",uVar12);
  }
  else {
    if ((dwFlags & 0xffffffbf) == 0) {
      *pdwProviderCount = 0;
      pwVar11 = L"KEY_STORAGE";
      *ppProviderList = (NCryptProviderName *)0x0;
      ppNVar7 = (NCryptProviderName **)0x10001;
      uVar1 = BCryptResolveProviders
                        ((LPCWSTR)0x0,0x10001,L"KEY_STORAGE",(LPCWSTR)0x0,1,2,local_res8,
                         &local_res20);
      if (uVar1 == 0) {
        uVar1 = local_res20->cProviders;
        if (uVar1 != 0) {
          pp_Var6 = local_res20->rgpProviders;
          uVar8 = (ulonglong)uVar1;
          do {
            pwVar11 = (*pp_Var6)->pszProvider;
            lVar2 = -1;
            do {
              lVar2 = lVar2 + 1;
            } while (pwVar11[lVar2] != L'\0');
            pp_Var6 = pp_Var6 + 1;
            iVar10 = iVar10 + (int)lVar2 * 2 + 2;
            uVar8 = uVar8 - 1;
            ppNVar7 = (NCryptProviderName **)0x0;
          } while (uVar8 != 0);
        }
        pNVar3 = (NCryptProviderName *)MSCryptAlloc((ulonglong)(uVar1 * 0x10 + iVar10));
        if (pNVar3 == (NCryptProviderName *)0x0) {
          uVar1 = 0x8009000e;
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
            uVar12 = 5;
            uVar5 = 0xe;
            ppProviderList = ppNVar7;
            uVar1 = 0x8009000e;
            goto LAB_180014d93;
          }
        }
        else {
          uVar8 = 0;
          _Dst = (LPWSTR)((longlong)&pNVar3->pszName + (ulonglong)(uVar1 * 0x10));
          uVar1 = 0;
          if (local_res20->cProviders != 0) {
            do {
              lVar2 = -1;
              do {
                lVar4 = lVar2;
                lVar2 = lVar4 + 1;
              } while (local_res20->rgpProviders[uVar8]->pszProvider[lVar2] != L'\0');
              uVar9 = (ulonglong)((int)lVar4 + 2);
              pNVar3[uVar8].pszName = _Dst;
              pNVar3[uVar8].pszComment = (LPWSTR)0x0;
              memcpy(_Dst,local_res20->rgpProviders[uVar8]->pszProvider,uVar9 * 2);
              _Dst = _Dst + uVar9;
              uVar13 = (int)uVar8 + 1;
              uVar8 = (ulonglong)uVar13;
              uVar1 = local_res20->cProviders;
            } while (uVar13 < uVar1);
          }
          *pdwProviderCount = uVar1;
          uVar1 = 0;
          *ppProviderList = pNVar3;
        }
        goto LAB_180014d29;
      }
      uVar12 = 0xec;
      uVar5 = (undefined1)uVar1;
    }
    else {
      uVar1 = 0x80090009;
      uVar12 = 0xd4;
      uVar5 = 9;
    }
    DebugTraceError(uVar5,"Status",
                    "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",uVar12);
  }
LAB_180014d29:
  if (local_res20 != (PCRYPT_PROVIDER_REFS)0x0) {
    BCryptFreeBuffer(local_res20);
  }
LAB_180014d3a:
  uVar1 = NormalizeNteStatus(uVar1);
  return uVar1;
}



===== McTemplateU0zzdz_EventWriteTransfer @ 180014e34 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateU0zzdz_EventWriteTransfer
               (undefined8 param_1,undefined8 param_2,wchar_t *param_3,wchar_t *param_4,
               undefined1 param_5,wchar_t *param_6)

{
  longlong lVar1;
  longlong lVar2;
  undefined1 auStackY_98 [32];
  _EVENT_DATA_DESCRIPTOR local_68;
  wchar_t *local_58;
  int local_50;
  undefined4 local_4c;
  wchar_t *local_48;
  int local_40;
  undefined4 local_3c;
  undefined1 *local_38;
  undefined8 local_30;
  wchar_t *local_28;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  lVar1 = -1;
  local_20 = 10;
  if (param_3 == (wchar_t *)0x0) {
    local_50 = 10;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (param_3[lVar2] != L'\0');
    local_50 = (int)lVar2 * 2 + 2;
  }
  local_4c = 0;
  if (param_3 == (wchar_t *)0x0) {
    param_3 = L"NULL";
  }
  if (param_4 == (wchar_t *)0x0) {
    local_40 = 10;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (param_4[lVar2] != L'\0');
    local_40 = (int)lVar2 * 2 + 2;
  }
  local_38 = &param_5;
  local_3c = 0;
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"NULL";
  }
  local_30 = 4;
  if (param_6 != (wchar_t *)0x0) {
    do {
      lVar1 = lVar1 + 1;
    } while (param_6[lVar1] != L'\0');
    local_20 = (int)lVar1 * 2 + 2;
  }
  local_28 = param_6;
  if (param_6 == (wchar_t *)0x0) {
    local_28 = L"NULL";
  }
  local_1c = 0;
  local_58 = param_3;
  local_48 = param_4;
  McGenEventWrite_EventWriteTransfer
            (local_38,(PCEVENT_DESCRIPTOR)&ETW_LOG_NCRYPT_OPEN_KEY_FAILED,param_3,5,&local_68);
  return;
}



===== StringCchPrintfExW @ 180014f50 =====

HRESULT __stdcall
StringCchPrintfExW(STRSAFE_LPWSTR pszDest,size_t cchDest,STRSAFE_LPWSTR *ppszDestEnd,
                  size_t *pcchRemaining,DWORD dwFlags,STRSAFE_LPCWSTR pszFormat,...)

{
  HRESULT HVar1;
  int iVar2;
  ulonglong uVar3;
  int iVar4;
  ulonglong _Count;
  size_t *psVar5;
  STRSAFE_LPWSTR pszDestEnd;
  size_t sVar6;
  char cStack0000000000000038;
  STRSAFE_LPWSTR local_58;
  size_t local_50 [2];
  
  psVar5 = pcchRemaining;
  HVar1 = StringExValidateDestW(pszDest,cchDest,(size_t)ppszDestEnd,dwFlags);
  if (HVar1 < 0) {
    if (cchDest == 0) {
      return HVar1;
    }
    *pszDest = L'\0';
    return HVar1;
  }
  if (((dwFlags >> 8 & 1) != 0) && (pszFormat == (STRSAFE_LPCWSTR)0x0)) {
    pszFormat = L"";
  }
  iVar4 = 0;
  if ((dwFlags & 0xffffe000) == 0) {
    if (cchDest == 0) {
      if (*pszFormat == L'\0') goto LAB_18001501f;
      iVar4 = (-(uint)(pszDest != (STRSAFE_LPWSTR)0x0) & 0x23) + 0x80070057;
      local_58 = pszDest;
      local_50[0] = cchDest;
      goto LAB_180014fcf;
    }
    local_50[0] = 0;
    _Count = cchDest - 1;
    local_58 = pszDest;
    iVar2 = _vsnwprintf(pszDest,_Count,pszFormat,&cStack0000000000000038);
    if (iVar2 < 0) {
LAB_180015090:
      iVar4 = -0x7ff8ff86;
LAB_180015095:
      pszDest[_Count] = L'\0';
    }
    else {
      uVar3 = (ulonglong)iVar2;
      if (_Count < uVar3) goto LAB_180015090;
      if (uVar3 == _Count) goto LAB_180015095;
      _Count = uVar3;
    }
    sVar6 = cchDest - _Count;
    pszDestEnd = pszDest + _Count;
    local_58 = pszDestEnd;
    local_50[0] = sVar6;
    if (iVar4 < 0) goto LAB_180014fcf;
    if (((dwFlags >> 9 & 1) != 0) && (1 < sVar6)) {
      StringExHandleFillBehindNullW(pszDestEnd,sVar6 * 2,dwFlags);
    }
  }
  else {
    iVar4 = -0x7ff8ffa9;
    local_58 = pszDest;
    local_50[0] = cchDest;
    if (cchDest != 0) {
      *pszDest = L'\0';
      local_58 = pszDest;
      local_50[0] = cchDest;
    }
LAB_180014fcf:
    pszDestEnd = local_58;
    sVar6 = local_50[0];
    if (((dwFlags & 0x1c00) != 0) && (cchDest != 0)) {
      StringExHandleOtherFlagsW(pszDest,cchDest * 2,(size_t)pszFormat,&local_58,local_50,dwFlags);
      pszDestEnd = local_58;
      sVar6 = local_50[0];
    }
    if (((iVar4 + 0x80000000U & 0x80000000) == 0) && (iVar4 != -0x7ff8ff86)) {
      return iVar4;
    }
  }
  psVar5 = pcchRemaining;
  pszDest = pszDestEnd;
  cchDest = sVar6;
LAB_18001501f:
  if (ppszDestEnd != (STRSAFE_LPWSTR *)0x0) {
    *ppszDestEnd = pszDest;
  }
  if (psVar5 != (size_t *)0x0) {
    *psVar5 = cchDest;
  }
  return iVar4;
}



===== StringExValidateDestW @ 1800150fc =====

HRESULT __stdcall
StringExValidateDestW(STRSAFE_PCNZWCH pszDest,size_t cchDest,size_t cchMax,DWORD dwFlags)

{
  HRESULT HVar1;
  
  HVar1 = 0;
  if ((dwFlags >> 8 & 1) == 0) {
    HVar1 = 0;
    if (0x7ffffffe < cchDest - 1) {
      HVar1 = -0x7ff8ffa9;
    }
  }
  else if (((pszDest == (STRSAFE_PCNZWCH)0x0) && (cchDest != 0)) || (0x7fffffff < cchDest)) {
    return -0x7ff8ffa9;
  }
  return HVar1;
}



===== __delayLoadHelper2 @ 180015140 =====

void __delayLoadHelper2(undefined8 param_1,undefined8 param_2)

{
  ResolveDelayLoadedAPI(0x180000000,param_1,0,DelayLoadFailureHook_exref,param_2,0);
  return;
}



===== SslImportMasterKey @ 180015190 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void SslImportMasterKey(uint *param_1,uint *param_2,undefined8 *param_3,undefined4 param_4,
                       undefined4 param_5,undefined8 param_6,undefined8 param_7,undefined4 param_8,
                       undefined4 param_9)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  undefined8 *puVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  
  puVar4 = param_3;
                    /* 0x15190  153  SslImportMasterKey */
  puVar2 = ValidateSslProvHandle(param_1);
  if (puVar2 == (uint *)0x0) {
    uVar1 = 0x80090026;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),param_2,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c","Status",0x26,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",0x89);
    }
  }
  else {
    puVar3 = ValidateSslKeyHandle(param_2);
    if (puVar3 == (uint *)0x0) {
      uVar1 = 0x80090026;
      uVar6 = 0x91;
      uVar5 = 0x26;
    }
    else if (puVar4 == (undefined8 *)0x0) {
      uVar1 = 0x80090027;
      uVar6 = 0x98;
      uVar5 = 0x27;
    }
    else {
      puVar4 = (undefined8 *)MSCryptAlloc(0x20);
      if (puVar4 != (undefined8 *)0x0) {
        *puVar4 = 0;
        puVar4[1] = 0;
        puVar4[2] = 0;
        puVar4[3] = 0;
        uVar1 = (**(code **)(puVar2 + 0x2a))
                          (*(undefined8 *)(puVar2 + 0x6a),*(undefined8 *)(puVar3 + 4),puVar4 + 2,
                           param_4,param_5,param_6,param_7,param_8,param_9);
        if ((int)uVar1 < 0) {
          DebugTraceError((char)uVar1,"Status",
                          "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",0xbe);
          SafeAllocaFreeToHeap(puVar4);
        }
        else {
          *(undefined4 *)(puVar4 + 1) = 0;
          *(undefined4 *)puVar4 = 0x20;
          *(undefined4 *)((longlong)puVar4 + 4) = 0x44444442;
          *(undefined4 *)((longlong)puVar4 + 0xc) = 1;
          puVar4[3] = puVar2;
          LOCK();
          puVar2[4] = puVar2[4] + 1;
          UNLOCK();
          *param_3 = puVar4;
          uVar1 = 0;
        }
        goto LAB_180015285;
      }
      uVar1 = 0x8009000e;
      uVar6 = 0xa8;
      uVar5 = 0xe;
    }
    DebugTraceError(uVar5,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",
                    uVar6);
  }
LAB_180015285:
  NormalizeNteStatus(uVar1);
  return;
}



===== I_OpenBCryptAlgHandle @ 18001536c =====

NTSTATUS I_OpenBCryptAlgHandle(uint param_1)

{
  NTSTATUS NVar1;
  LPCWSTR pszAlgId;
  undefined8 uVar2;
  bool bVar3;
  BCRYPT_ALG_HANDLE local_res10 [2];
  
  local_res10[0] = (BCRYPT_ALG_HANDLE)0x0;
  uVar2 = 0;
  pszAlgId = (LPCWSTR)(&PTR_u_AES_18001f020)[param_1];
  NVar1 = BCryptOpenAlgorithmProvider(local_res10,pszAlgId,(LPCWSTR)0x0,0);
  if (NVar1 == 0) {
    LOCK();
    bVar3 = (&DAT_180027b50)[param_1] == 0;
    if (bVar3) {
      (&DAT_180027b50)[param_1] = local_res10[0];
    }
    UNLOCK();
    if (bVar3) {
      local_res10[0] = (BCRYPT_ALG_HANDLE)0x0;
    }
    NVar1 = 0;
  }
  else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
    WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),pszAlgId,uVar2,"Status",(char)NVar1,
                "onecore\\ds\\security\\cryptoapi\\ncrypt\\common\\provider.c",0x2d);
  }
  if (local_res10[0] != (BCRYPT_ALG_HANDLE)0x0) {
    BCryptCloseAlgorithmProvider(local_res10[0],0);
  }
  return NVar1;
}



===== _RegLoadSettings @ 180015440 =====

void _RegLoadSettings(void)

{
  uint uVar1;
  LSTATUS LVar2;
  void *_Dst;
  undefined1 uVar3;
  LPBYTE lpData;
  void *pvVar4;
  uint uVar5;
  longlong lVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  undefined1 uVar9;
  HKEY *ppHVar10;
  DWORD DVar11;
  DWORD *lpcbData;
  ulonglong uVar12;
  DWORD local_res8 [2];
  uint local_res10;
  uint local_res18;
  LSTATUS local_res20;
  DWORD local_78 [2];
  LPBYTE local_70;
  HKEY local_68;
  HKEY local_60;
  HKEY local_58 [3];
  
  local_68 = (HKEY)0x0;
  lVar6 = 0;
  local_60 = (HKEY)0x0;
  pvVar4 = (void *)0x0;
  local_res8[0] = 0;
  local_78[0] = 0;
  local_58[0] = (HKEY)0x0;
  local_58[1] = (HKEY)0x0;
  if (DAT_180027cf0 != 0) {
    return;
  }
  RtlEnterCriticalSection(&g_csKeyProtectorLock);
  if (DAT_180027cf0 == 0) {
    uVar8 = 0;
    uVar1 = RegOpenKeyExW((HKEY)0xffffffff80000002,
                          L"Software\\Policies\\Microsoft\\Cryptography\\NProtect",0,0x20019,
                          &local_60);
    if (uVar1 == 0) {
      lVar6 = 1;
      local_58[0] = local_60;
    }
    else {
      if (0 < (int)uVar1) {
        uVar1 = uVar1 & 0xffff | 0x80070000;
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((WPP_GLOBAL_Control[0x1c] & 8) != 0)) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),10,uVar8,uVar1);
      }
    }
    uVar5 = (uint)lVar6;
    uVar8 = 0;
    uVar1 = RegOpenKeyExW((HKEY)0xffffffff80000002,L"Software\\Microsoft\\Cryptography\\NProtect",0,
                          0x20019,&local_68);
    if (uVar1 == 0) {
      uVar5 = uVar5 + 1;
      local_58[lVar6] = local_68;
    }
    else {
      if (0 < (int)uVar1) {
        uVar1 = uVar1 & 0xffff | 0x80070000;
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((WPP_GLOBAL_Control[0x1c] & 8) != 0)) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0xb,uVar8,uVar1);
      }
    }
    if (uVar5 != 0) {
      ppHVar10 = local_58;
      uVar7 = (ulonglong)DAT_180027084 + 0x20;
      uVar1 = 0;
      LVar2 = 3;
      do {
        if (LVar2 == 0) break;
        LVar2 = RegQueryValueExW(*ppHVar10,(LPCWSTR)PTR_u_RecoveryAgent_180027070,(LPDWORD)0x0,
                                 local_res8,(LPBYTE)0x0,local_78);
        if (LVar2 == 0) {
          if (DAT_180027078 == local_res8[0]) {
            uVar7 = uVar7 + local_78[0];
          }
          else {
            LVar2 = -0x7ff6fffb;
            DebugTraceError(5,"dwRes",
                            "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\reg.c"
                            ,0xd0);
          }
        }
        uVar1 = uVar1 + 1;
        ppHVar10 = ppHVar10 + 1;
      } while (uVar1 < uVar5);
      if (uVar7 < 0x1000000) {
        _Dst = (void *)MSCryptAlloc(uVar7);
        if (_Dst != (void *)0x0) {
          memset(_Dst,0,uVar7);
          lpData = (LPBYTE)((longlong)_Dst + 0x20);
          local_70 = lpData;
          DVar11 = (int)uVar7 - 0x20;
          for (local_res18 = 0; local_res18 == 0; local_res18 = local_res18 + 1) {
            uVar7 = 0;
            LVar2 = 3;
            while ((local_res10 = (uint)uVar7, local_res10 < uVar5 && (LVar2 != 0))) {
              uVar12 = (ulonglong)local_res18;
              if (((&DAT_180027084)[uVar12 * 8] == 0) && ((&DAT_18002708c)[uVar12 * 8] == 0)) {
                local_78[0] = (&DAT_180027080)[uVar12 * 8];
                lpData = (LPBYTE)((ulonglong)(uint)(&DAT_180027088)[uVar12 * 8] + (longlong)_Dst);
LAB_180015701:
                lpcbData = local_78;
              }
              else {
                *(LPBYTE *)((ulonglong)(uint)(&DAT_180027088)[uVar12 * 8] + (longlong)_Dst) = lpData
                ;
                if ((&DAT_18002708c)[uVar12 * 8] == 0) {
                  local_78[0] = DVar11;
                  goto LAB_180015701;
                }
                lpcbData = (DWORD *)((ulonglong)(uint)(&DAT_18002708c)[uVar12 * 8] + (longlong)_Dst)
                ;
                *lpcbData = DVar11;
              }
              LVar2 = RegQueryValueExW(local_58[uVar7],
                                       (LPCWSTR)(&PTR_u_RecoveryAgent_180027070)[uVar12 * 4],
                                       (LPDWORD)0x0,local_res8,lpData,lpcbData);
              if (LVar2 == 0) {
                if ((&DAT_180027078)[uVar12 * 8] != local_res8[0]) {
                  local_res20 = -0x7ff6fffb;
                  DebugTraceError(5,"dwRes",
                                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\reg.c"
                                  ,0x35);
                  *(undefined8 *)((ulonglong)(uint)(&DAT_180027088)[uVar12 * 8] + (longlong)_Dst) =
                       0;
                  *lpcbData = 0;
                  LVar2 = local_res20;
                  goto LAB_1800157a0;
                }
                uVar1 = (&DAT_180027084)[uVar12 * 8];
                if ((uVar1 != 0) || ((&DAT_18002708c)[uVar12 * 8] != 0)) {
                  if (DVar11 - *lpcbData < uVar1) {
                    uVar9 = 0x2a;
                    uVar3 = 0x28;
                    pvVar4 = _Dst;
                    goto LAB_180015632;
                  }
                  local_70 = local_70 + (ulonglong)uVar1 + (ulonglong)*lpcbData;
                  DVar11 = (DVar11 - *lpcbData) - uVar1;
                }
              }
              else {
LAB_1800157a0:
                *(undefined8 *)((ulonglong)(uint)(&DAT_180027088)[uVar12 * 8] + (longlong)_Dst) = 0;
                *lpcbData = 0;
              }
              uVar7 = (ulonglong)(local_res10 + 1);
              lpData = local_70;
            }
          }
          pvVar4 = (void *)0x0;
          DAT_180027ce8 = _Dst;
          goto LAB_1800157ec;
        }
        uVar9 = 0xe6;
        uVar3 = 0xe;
      }
      else {
        uVar9 = 0xde;
        uVar3 = 5;
        _Dst = pvVar4;
      }
      pvVar4 = _Dst;
LAB_180015632:
      DebugTraceError(uVar3,"Status",
                      "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\reg.c",
                      uVar9);
    }
  }
LAB_1800157ec:
  DAT_180027cf0 = 1;
  RtlLeaveCriticalSection(&g_csKeyProtectorLock);
  if (local_68 != (HKEY)0x0) {
    RegCloseKey(local_68);
  }
  if (local_60 != (HKEY)0x0) {
    RegCloseKey(local_60);
  }
  if (pvVar4 != (void *)0x0) {
    SafeAllocaFreeToHeap(pvVar4);
  }
  return;
}



===== WppCleanupUm @ 180015858 =====

void WppCleanupUm(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)WPP_GLOBAL_Control;
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    for (; puVar1 != (undefined8 *)0x0; puVar1 = (undefined8 *)*puVar1) {
      if (puVar1[1] != 0) {
        UnregisterTraceGuids();
        puVar1[1] = 0;
      }
    }
    WPP_GLOBAL_Control = (undefined *)&WPP_GLOBAL_Control;
  }
  return;
}



===== _GetTokenAndMoveCursToUnparsed @ 1800158b4 =====

undefined8 _GetTokenAndMoveCursToUnparsed(undefined8 *param_1,undefined4 *param_2)

{
  int iVar1;
  wchar_t *_Str1;
  wchar_t *pwVar2;
  uint uVar3;
  undefined8 uVar4;
  wchar_t wVar5;
  
  uVar4 = 0;
  for (_Str1 = (wchar_t *)*param_1; wVar5 = *_Str1, wVar5 == L' '; _Str1 = _Str1 + 1) {
  }
  pwVar2 = _Str1;
  if (wVar5 == L'\0') {
    *param_2 = 3;
  }
  else {
    while ((wVar5 != L' ' && (wVar5 != L'\0'))) {
      wVar5 = pwVar2[1];
      pwVar2 = pwVar2 + 1;
    }
    *pwVar2 = L'\0';
    *param_1 = pwVar2 + 1;
    uVar3 = (ushort)*_Str1 - 0x4f;
    if ((uVar3 == 0) && (uVar3 = (ushort)_Str1[1] - 0x52, uVar3 == 0)) {
      uVar3 = (uint)(ushort)_Str1[2];
    }
    if (uVar3 == 0) {
      *param_2 = 2;
    }
    else {
      iVar1 = wcscmp(_Str1,L"AND");
      if (iVar1 == 0) {
        *param_2 = 1;
      }
      else {
        *param_2 = 0;
        uVar4 = 0x80090005;
        DebugTraceError(5,"hr",
                        "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\descriptor.c"
                        ,0xf3);
      }
    }
  }
  return uVar4;
}



===== NCryptStreamClose @ 180015990 =====

undefined8 NCryptStreamClose(longlong *param_1,undefined8 param_2,undefined *param_3)

{
  undefined8 uVar1;
  
                    /* 0x15990  101  NCryptStreamClose */
  uVar1 = 0;
  if ((param_1 == (longlong *)0x0) || (*param_1 != 0xc0)) {
    uVar1 = 0x80090026;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),param_2,param_3,"Status",0x26,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\stream.c",99);
    }
  }
  else {
    I_StreamFree((longlong)param_1,param_2,param_3);
  }
  return uVar1;
}



===== I_StreamFree @ 180015a08 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void I_StreamFree(longlong param_1,undefined8 param_2,undefined *param_3)

{
  ulonglong uVar1;
  undefined1 *puVar2;
  
  if (*(int *)(param_1 + 0x24) == 0) {
    if (*(longlong *)(param_1 + 0x90) != 0) {
      (**(code **)(*(longlong *)(param_1 + 8) + 0x10))();
    }
    if (*(longlong *)(param_1 + 0x88) != 0) {
      if (*(undefined1 **)(param_1 + 0xb0) != (undefined1 *)0x0) {
        puVar2 = *(undefined1 **)(param_1 + 0xb0);
        for (uVar1 = (ulonglong)*(uint *)(param_1 + 0xb8); uVar1 != 0; uVar1 = uVar1 - 1) {
          *puVar2 = 0;
          puVar2 = puVar2 + 1;
        }
        (**(code **)(*(longlong *)(param_1 + 8) + 0x10))(*(undefined8 *)(param_1 + 0xb0));
      }
      NCryptCloseProtectionDescriptor(*(int **)(param_1 + 0x88),param_2,param_3);
    }
  }
  else if (*(longlong *)(param_1 + 0x48) != 0) {
    if (*(undefined1 **)(param_1 + 0x80) != (undefined1 *)0x0) {
      puVar2 = *(undefined1 **)(param_1 + 0x80);
      for (uVar1 = (ulonglong)*(uint *)(param_1 + 0x78); uVar1 != 0; uVar1 = uVar1 - 1) {
        *puVar2 = 0;
        puVar2 = puVar2 + 1;
      }
    }
    if (*(int **)(param_1 + 0x48) != (int *)0x0) {
      NCryptMsgClose(*(int **)(param_1 + 0x48),param_2,param_3);
    }
  }
  (**(code **)(*(longlong *)(param_1 + 8) + 0x10))(param_1);
  return;
}



===== CertInUseCleanup @ 180015ad4 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CertInUseCleanup(void)

{
  REGHANDLE RegHandle;
  
  if (g_pTpWait != (PTP_WAIT)0x0) {
    SetThreadpoolWait(g_pTpWait,(HANDLE)0x0,(PFILETIME)0x0);
    WaitForThreadpoolWaitCallbacks(g_pTpWait,1);
    CloseThreadpoolWait(g_pTpWait);
    g_pTpWait = (PTP_WAIT)0x0;
  }
  if (g_CertInUseRegKey != (HKEY)0x0) {
    RegCloseKey(g_CertInUseRegKey);
    g_CertInUseRegKey = (HKEY)0x0;
  }
  if (g_hCertInUseRegChangeEvent != (HANDLE)0x0) {
    CloseHandle(g_hCertInUseRegChangeEvent);
    g_hCertInUseRegChangeEvent = (HANDLE)0x0;
  }
  if (g_pCertInUseProcessInfo != (undefined8 *)0x0) {
    CertInUseFree(g_pCertInUseProcessInfo);
    CertInUseFree(g_pCertInUseProcessInfo + 1);
    CertInUseFree(g_pCertInUseProcessInfo + 2);
    CertInUseFree(&g_pCertInUseProcessInfo);
  }
  RegHandle = DAT_1800270b0;
  DAT_1800270b0 = 0;
  _DAT_180027090 = 0;
                    /* WARNING: Could not recover jumptable at 0x000180015b3a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EventUnregister(RegHandle);
  return;
}



===== McGenEventUnregister_EventUnregister @ 180015be4 =====

ULONG McGenEventUnregister_EventUnregister(void)

{
  ULONG UVar1;
  
  if (ETW_LOG_NCRYPT_PROVIDER_Context == 0) {
    UVar1 = 0;
  }
  else {
    UVar1 = EventUnregister(ETW_LOG_NCRYPT_PROVIDER_Context);
    ETW_LOG_NCRYPT_PROVIDER_Context = 0;
  }
  return UVar1;
}



===== NCryptIsAlgSupported @ 180015c20 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

SECURITY_STATUS __stdcall
NCryptIsAlgSupported(NCRYPT_PROV_HANDLE hProvider,LPCWSTR pszAlgId,DWORD dwFlags)

{
  uint uVar1;
  int *piVar2;
  LPCWSTR pWVar3;
  undefined4 in_register_00000084;
  undefined1 uVar4;
  
                    /* 0x15c20  86  NCryptIsAlgSupported */
  pWVar3 = pszAlgId;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    pWVar3 = (LPCWSTR)0x18;
    WPP_SF_PSD(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x18,
               CONCAT44(in_register_00000084,dwFlags),hProvider,pszAlgId,(char)dwFlags);
  }
  piVar2 = ValidateAndReferenceProvider((int *)hProvider);
  if (piVar2 == (int *)0x0) {
    uVar1 = 0x80090026;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),pWVar3,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c","Status",0x26
                  ,"onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",0xdf);
    }
  }
  else {
    do {
      uVar1 = (**(code **)(piVar2 + 0x22))(*(undefined8 *)(piVar2 + 0x44),pszAlgId,dwFlags);
      if (uVar1 != 0x8009002e) {
        if (uVar1 == 0) goto LAB_180015c97;
        break;
      }
      if ((dwFlags & 0x40) != 0) {
        uVar1 = 0x80090022;
        uVar4 = 0xf3;
        goto LAB_180015d65;
      }
      uVar1 = (**(code **)(piVar2 + 0x30))
                        (*(undefined8 *)(piVar2 + 0x44),0,L"NCryptIsAlgSupported",0);
    } while (uVar1 == 0);
    uVar4 = 5;
LAB_180015d65:
    DebugTraceError((char)uVar1,"Status",
                    "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",uVar4);
LAB_180015c97:
    DereferenceProvider((longlong)piVar2);
  }
  uVar1 = NormalizeNteStatus(uVar1);
  return uVar1;
}



===== WPP_SF_ @ 180015d98 =====

void WPP_SF_(undefined8 param_1)

{
  EtwTraceMessage(param_1,0x2b,&WPP_67679bdabad938a7dfcc8815ccec1def_Traceguids,0x19,0);
  return;
}



===== _FreeImage @ 180015dcc =====

void _FreeImage(HMODULE param_1)

{
  if ((param_1 != g_hInstance) && (param_1 != (HMODULE)0x0)) {
    FreeLibrary(param_1);
  }
  return;
}



===== SslOpenPrivateKey @ 180015e00 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void SslOpenPrivateKey(uint *param_1,undefined8 *param_2,longlong param_3,undefined4 param_4)

{
  uint uVar1;
  uint *puVar2;
  undefined4 *puVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  
                    /* 0x15e00  157  SslOpenPrivateKey */
  puVar3 = (undefined4 *)0x0;
  puVar2 = ValidateSslProvHandle(param_1);
  if (puVar2 == (uint *)0x0) {
    uVar1 = 0x80090026;
    uVar5 = 0x39;
    uVar4 = 0x26;
LAB_180015e41:
    DebugTraceError(uVar4,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",
                    uVar5);
  }
  else {
    if ((param_2 == (undefined8 *)0x0) || (param_3 == 0)) {
      uVar1 = 0x80090027;
      uVar4 = 0x27;
      uVar5 = 0x40;
    }
    else {
      puVar3 = (undefined4 *)MSCryptAlloc(0x20);
      if (puVar3 == (undefined4 *)0x0) {
        uVar1 = 0x8009000e;
        uVar5 = 0x50;
        uVar4 = 0xe;
        goto LAB_180015e41;
      }
      uVar1 = (**(code **)(puVar2 + 0x30))
                        (*(undefined8 *)(puVar2 + 0x6a),puVar3 + 4,param_3,param_4);
      if (-1 < (int)uVar1) {
        puVar3[2] = 0;
        *puVar3 = 0x20;
        puVar3[1] = 0x44444442;
        puVar3[3] = 1;
        *(uint **)(puVar3 + 6) = puVar2;
        LOCK();
        puVar2[4] = puVar2[4] + 1;
        UNLOCK();
        *param_2 = puVar3;
        uVar1 = 0;
        goto LAB_180015f0b;
      }
      uVar4 = (undefined1)uVar1;
      uVar5 = 0x60;
    }
    DebugTraceError(uVar4,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",
                    uVar5);
    if (puVar3 != (undefined4 *)0x0) {
      SafeAllocaFreeToHeap(puVar3);
    }
  }
LAB_180015f0b:
  NormalizeNteStatus(uVar1);
  return;
}



===== _StartRegChangeListenerInitOnceCallback @ 180015f40 =====

undefined8
_StartRegChangeListenerInitOnceCallback(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  if (param_3 != (undefined8 *)0x0) {
    *param_3 = 0;
  }
  StartRegistryChangeMonitor();
  return 1;
}



===== StartRegistryChangeMonitor @ 180015f68 =====

void StartRegistryChangeMonitor(void)

{
  DWORD dwErrCode;
  LSTATUS LVar1;
  HKEY local_res8 [4];
  
  local_res8[0] = (HKEY)0x0;
  dwErrCode = RegOpenKeyExW((HKEY)0xffffffff80000002,
                            L"SYSTEM\\CurrentControlSet\\Control\\Cryptography",0,0x10,local_res8);
  if (dwErrCode == 0) {
    g_CertInUseRegKey = local_res8[0];
    if (local_res8[0] != (HKEY)0x0) {
      g_hCertInUseRegChangeEvent = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCSTR)0x0);
      if (g_hCertInUseRegChangeEvent != (HANDLE)0x0) {
        LVar1 = RegNotifyChangeKeyValue(g_CertInUseRegKey,1,0x10000004,g_hCertInUseRegChangeEvent,1)
        ;
        if (LVar1 == 0) {
          g_pTpWait = CreateThreadpoolWait
                                (OnRegChange_CertInUse,(PVOID)0x0,(PTP_CALLBACK_ENVIRON)0x0);
          if (g_pTpWait != (PTP_WAIT)0x0) {
            SetThreadpoolWait(g_pTpWait,g_hCertInUseRegChangeEvent,(PFILETIME)0x0);
            ReadKey_CertInUse();
            return;
          }
        }
      }
    }
  }
  else {
    SetLastError(dwErrCode);
    g_CertInUseRegKey = (HKEY)0x0;
  }
  EtwErrorNCryptCertInUse(L"Failed to initialize StartRegistryChangeMonitor",L"",0x80004005);
  if (g_CertInUseRegKey != (HKEY)0x0) {
    RegCloseKey(g_CertInUseRegKey);
    g_CertInUseRegKey = (HKEY)0x0;
  }
  if (g_hCertInUseRegChangeEvent != (HANDLE)0x0) {
    CloseHandle(g_hCertInUseRegChangeEvent);
    g_hCertInUseRegChangeEvent = (HANDLE)0x0;
  }
  return;
}



===== EtwErrorNCryptCertInUse @ 1800160cc =====

HRESULT EtwErrorNCryptCertInUse(STRSAFE_PCNZWCH param_1,STRSAFE_PCNZWCH param_2,undefined4 param_3)

{
  HRESULT HVar1;
  wchar_t *pszDest;
  wchar_t *pwVar2;
  STRSAFE_PCNZWCH cchMax;
  size_t sVar3;
  size_t local_res20;
  size_t local_38;
  wchar_t *local_30;
  
  local_30 = (wchar_t *)0x0;
  local_res20 = 0;
  cchMax = param_2;
  HVar1 = StringCchLengthW(param_2,(size_t)param_2,&local_res20);
  if (-1 < HVar1) {
    sVar3 = local_res20;
    HVar1 = StringCchLengthW(param_1,(size_t)cchMax,&local_res20);
    if (-1 < HVar1) {
      local_38 = 0;
      HVar1 = StringCchLengthW(L"{\"provider\":\"%s\", \"errorCode\":\"0x%x\", \"errorMessage\":\"%s\"}"
                               ,(size_t)cchMax,&local_38);
      if (-1 < HVar1) {
        sVar3 = local_res20 + local_38 + sVar3 + 10;
        pszDest = CertInUseNonzeroAlloc(sVar3 * 2);
        local_30 = pszDest;
        if (pszDest == (wchar_t *)0x0) {
          HVar1 = -0x7ff6fff2;
        }
        else {
          pwVar2 = pszDest;
          HVar1 = StringCchPrintfExW(pszDest,sVar3,(STRSAFE_LPWSTR *)0x0,&local_res20,0,
                                     L"{\"provider\":\"%s\", \"errorCode\":\"0x%x\", \"errorMessage\":\"%s\"}"
                                     ,param_2,param_3,param_1);
          if (-1 < HVar1) {
            if ((Microsoft_Windows_Crypto_NCryptEnableBits & 0x40) != 0) {
              HVar1 = McTemplateU0z_EventWriteTransfer
                                (pwVar2,(PCEVENT_DESCRIPTOR)&ETW_NCRYPT_CERT_IN_USE_ERROR,pszDest);
              if (HVar1 < 0) goto LAB_1800161c3;
            }
            HVar1 = 0;
          }
        }
      }
    }
  }
LAB_1800161c3:
  CertInUseFree(&local_30);
  return HVar1;
}



===== ReadKey_CertInUse @ 1800161f0 =====

void ReadKey_CertInUse(void)

{
  LSTATUS LVar1;
  int iVar2;
  int local_res8 [2];
  DWORD local_res10 [2];
  DWORD local_res18 [2];
  HKEY local_res20;
  
  local_res20 = (HKEY)0x0;
  iVar2 = 3600000;
  local_res10[0] = 4;
  local_res18[0] = 4;
  local_res8[0] = 3600000;
  LVar1 = RegOpenKeyExW((HKEY)0xffffffff80000002,
                        L"SYSTEM\\CurrentControlSet\\Control\\Cryptography\\CertInUse",0,1,
                        &local_res20);
  if (LVar1 == 0) {
    LVar1 = RegQueryValueExW(local_res20,L"ClientSideEventThrottlingMinutes",(LPDWORD)0x0,
                             local_res18,(LPBYTE)local_res8,local_res10);
    if (LVar1 == 0) {
      iVar2 = local_res8[0] * 60000;
    }
    g_dwClientSideEventThrottlingMilliseconds = iVar2;
    local_res8[0] = iVar2;
    LVar1 = RegQueryValueExW(local_res20,L"ClientEnable",(LPDWORD)0x0,local_res18,
                             (LPBYTE)&g_dwClientEnabled,local_res10);
    if (LVar1 != 0) {
      g_dwClientEnabled = 0;
    }
    RegCloseKey(local_res20);
  }
  else {
    g_dwClientEnabled = 0;
    g_dwClientSideEventThrottlingMilliseconds = 3600000;
  }
  return;
}



===== I_CreateAndCombinerRecipient @ 1800162f4 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

ulonglong I_CreateAndCombinerRecipient
                    (longlong param_1,uint param_2,PUCHAR param_3,ULONG param_4,undefined *param_5,
                    undefined8 param_6,undefined8 *param_7,undefined4 param_8)

{
  longlong lVar1;
  longlong lVar2;
  ushort *puVar3;
  code *pcVar4;
  ULONG UVar5;
  PUCHAR pUVar6;
  uint uVar7;
  ulonglong uVar8;
  PUCHAR pbBuffer;
  undefined8 uVar9;
  undefined1 uVar10;
  uint uVar11;
  ulonglong uVar12;
  undefined8 *puVar13;
  ulonglong uVar14;
  undefined1 *puVar15;
  undefined1 *puVar16;
  PUCHAR pUVar17;
  undefined8 uVar18;
  undefined1 uVar19;
  longlong lVar20;
  uint cbBuffer;
  undefined1 auStackY_758 [32];
  uint local_718 [2];
  longlong local_710;
  undefined4 local_708;
  ULONG local_704;
  longlong local_700;
  longlong local_6f8;
  PUCHAR local_6f0;
  longlong local_6e8;
  undefined8 local_6e0;
  undefined8 local_6d8;
  undefined8 local_6d0;
  longlong local_6c8;
  PUCHAR local_6c0;
  undefined8 *local_6b8;
  undefined1 local_6a8 [4];
  uint local_6a4;
  undefined8 *local_6a0;
  undefined4 local_698;
  undefined8 local_690;
  undefined4 local_670;
  undefined *local_668;
  undefined4 local_648;
  longlong local_640;
  undefined4 local_638 [2];
  undefined4 local_630;
  undefined *local_628;
  undefined4 local_620;
  longlong local_618;
  longlong local_598 [8];
  undefined8 local_558 [160];
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)local_718;
  local_6d0 = param_6;
  local_6b8 = param_7;
  local_704 = param_4;
  local_6c8 = param_1;
  local_6c0 = param_3;
  memset(local_638,0,0xa0);
  memset(local_6a8,0,0x70);
  memset(local_558,0,0x500);
  uVar9 = 0;
  uVar18 = 0x40;
  memset(local_598,0,0x40);
  *param_7 = 0;
  local_710 = 0;
  local_718[0] = 0;
  local_6e8 = 0;
  local_708 = 0;
  local_6f8 = 0;
  local_6e0 = 0;
  local_700 = 0;
  local_6d8 = 0;
  if (param_2 < **(uint **)(param_1 + 8)) {
    lVar20 = (ulonglong)param_2 * 0x20;
    lVar1 = *(longlong *)(*(longlong *)(param_1 + 8) + 8);
    if (*(uint *)(lVar20 + lVar1) < 9) {
      uVar8 = CNG_FindBCryptOidInfoStr(lVar1,uVar9,&local_710);
      lVar1 = local_710;
      uVar14 = uVar8 & 0xffffffff;
      if ((int)uVar8 == 0) {
        local_690 = *(undefined8 *)(local_710 + 0x30);
        local_698 = *(undefined4 *)(local_710 + 0x28);
        cbBuffer = *(int *)(lVar20 + *(longlong *)(*(longlong *)(param_1 + 8) + 8)) << 5;
        if (cbBuffer < 0x20) {
          uVar14 = 0x80070216;
          uVar19 = 0xd8;
          uVar10 = 0x16;
        }
        else {
          pbBuffer = (PUCHAR)(**(code **)(param_5 + 8))();
          if (pbBuffer != (PUCHAR)0x0) {
            uVar7 = BCryptGenRandom((BCRYPT_ALG_HANDLE)0x0,pbBuffer,cbBuffer,2);
            puVar16 = auStackY_758;
            if (uVar7 == 0) {
              local_6f0 = pbBuffer;
              local_6a0 = local_558;
              uVar11 = 0;
              while( true ) {
                local_710 = CONCAT44(local_710._4_4_,uVar11);
                lVar2 = *(longlong *)(*(longlong *)(param_1 + 8) + 8);
                if (*(uint *)(lVar2 + lVar20) <= uVar11) break;
                puVar13 = (undefined8 *)
                          ((ulonglong)uVar11 * 0x20 + *(longlong *)(lVar2 + 8 + lVar20));
                if ((*(int *)(puVar13 + 3) != 1) || ((int *)puVar13[2] == (int *)0x0)) {
                  uVar14 = 0x80090013;
                  uVar19 = 0xff;
                  uVar10 = 0x13;
                  goto LAB_1800164a6;
                }
                uVar7 = NCryptProtectKey((int *)puVar13[2],puVar13,local_6f0,0x20,param_5,local_6d0,
                                         local_598 + uVar11,param_8);
                if (uVar7 != 0) {
                  uVar19 = 0xf;
                  goto LAB_1800164a4;
                }
                puVar13 = (undefined8 *)local_598[uVar11];
                uVar8 = (ulonglong)local_6a4;
                local_6f0 = local_6f0 + 0x20;
                uVar9 = puVar13[1];
                uVar11 = (int)local_710 + 1;
                local_558[uVar8 * 0x14] = *puVar13;
                local_558[uVar8 * 0x14 + 1] = uVar9;
                uVar9 = puVar13[3];
                local_558[uVar8 * 0x14 + 2] = puVar13[2];
                local_558[uVar8 * 0x14 + 3] = uVar9;
                uVar9 = puVar13[5];
                local_558[uVar8 * 0x14 + 4] = puVar13[4];
                local_558[uVar8 * 0x14 + 5] = uVar9;
                uVar9 = puVar13[7];
                local_558[uVar8 * 0x14 + 6] = puVar13[6];
                local_558[uVar8 * 0x14 + 7] = uVar9;
                uVar9 = puVar13[9];
                local_558[uVar8 * 0x14 + 8] = puVar13[8];
                local_558[uVar8 * 0x14 + 9] = uVar9;
                uVar9 = puVar13[0xb];
                local_558[uVar8 * 0x14 + 10] = puVar13[10];
                local_558[uVar8 * 0x14 + 0xb] = uVar9;
                uVar9 = puVar13[0xd];
                local_558[uVar8 * 0x14 + 0xc] = puVar13[0xc];
                local_558[uVar8 * 0x14 + 0xd] = uVar9;
                uVar9 = puVar13[0xf];
                local_558[uVar8 * 0x14 + 0xe] = puVar13[0xe];
                local_558[uVar8 * 0x14 + 0xf] = uVar9;
                uVar9 = puVar13[0x11];
                local_558[uVar8 * 0x14 + 0x10] = puVar13[0x10];
                local_558[uVar8 * 0x14 + 0x11] = uVar9;
                uVar9 = puVar13[0x13];
                local_6a4 = local_6a4 + 1;
                local_558[uVar8 * 0x14 + 0x12] = puVar13[0x12];
                local_558[uVar8 * 0x14 + 0x13] = uVar9;
                param_1 = local_6c8;
              }
              local_718[0] = *(uint *)(lVar1 + 0x3c);
              uVar8 = (ulonglong)local_718[0];
              pUVar17 = (PUCHAR)0x0;
              uVar14 = (ulonglong)local_718[0];
              puVar15 = auStackY_758;
              if ((((local_718[0] == 0) || (puVar15 = auStackY_758, g_ulMaxStackAllocSize < uVar8))
                  || (uVar12 = g_ulAdditionalProbeSize + 8 + uVar8, puVar15 = auStackY_758,
                     uVar12 < uVar8)) ||
                 (uVar9 = VerifyStackAvailable(uVar12), puVar15 = auStackY_758, (int)uVar9 == 0)) {
LAB_18001666b:
                puVar16 = puVar15;
                if (uVar14 <= uVar14 + 8) {
                  *(undefined8 *)(puVar15 + -8) = 0x180016680;
                  pUVar17 = (PUCHAR)(*g_pfnAllocate)();
                  if (pUVar17 != (PUCHAR)0x0) {
                    builtin_memcpy(pUVar17,"Heap",4);
                    pUVar17 = pUVar17 + 8;
                  }
                }
              }
              else {
                uVar8 = uVar14 + 0x17;
                if (uVar8 <= uVar14 + 8) {
                  uVar8 = 0xffffffffffffff0;
                }
                lVar20 = -(uVar8 & 0xfffffffffffffff0);
                pUVar17 = (PUCHAR)0x0;
                puVar15 = auStackY_758 + lVar20;
                if ((undefined4 *)((longlong)local_718 + lVar20) == (undefined4 *)0x0)
                goto LAB_18001666b;
                *(undefined4 *)((longlong)local_718 + lVar20) = 0x6b637453;
                pUVar17 = (PUCHAR)((longlong)local_718 + lVar20 + 8);
                puVar15 = auStackY_758 + lVar20;
                puVar16 = auStackY_758 + lVar20;
                if (pUVar17 == (PUCHAR)0x0) goto LAB_18001666b;
              }
              if (pUVar17 == (PUCHAR)0x0) {
                uVar14 = 0x8009000e;
                uVar19 = 0x1f;
                uVar10 = 0xe;
                goto LAB_1800164a6;
              }
              puVar3 = *(ushort **)(lVar1 + 8);
              *(uint **)(puVar16 + 0x28) = local_718;
              *(uint *)(puVar16 + 0x20) = local_718[0];
              *(undefined8 *)(puVar16 + -8) = 0x1800166ce;
              uVar7 = CNG_ComputeHash(pbBuffer,cbBuffer,puVar3,pUVar17,*(uint *)(puVar16 + 0x20),
                                      *(uint **)(puVar16 + 0x28));
              pUVar6 = local_6c0;
              UVar5 = local_704;
              uVar14 = (ulonglong)uVar7;
              if (uVar7 == 0) {
                *(undefined4 **)(puVar16 + 0x30) = &local_708;
                *(longlong **)(puVar16 + 0x28) = &local_6e8;
                *(uint *)(puVar16 + 0x20) = local_718[0];
                *(undefined8 *)(puVar16 + -8) = 0x18001670b;
                uVar7 = CNG_AesKeyWrap((longlong)param_5,pUVar6,UVar5,pUVar17,
                                       *(ULONG *)(puVar16 + 0x20),*(undefined8 **)(puVar16 + 0x28),
                                       *(ULONG **)(puVar16 + 0x30));
                uVar14 = (ulonglong)uVar7;
                if ((int)uVar7 < 0) {
                  uVar10 = 0x40;
                  goto LAB_18001685c;
                }
                local_668 = &DAT_180021938;
                local_640 = local_6e8;
                local_648 = local_708;
                local_670 = 0xb;
                *(undefined1 **)(puVar16 + 0x30) = local_6a8;
                *(undefined8 **)(puVar16 + 0x28) = &local_6e0;
                *(longlong **)(puVar16 + 0x20) = &local_6f8;
                *(undefined8 *)(puVar16 + -8) = 0x18001677b;
                uVar7 = Ordinal_2(ASN1_NCRYPT_MODULE_HANDLE,0x1d,0,param_5);
                uVar14 = (ulonglong)uVar7;
                if (uVar7 != 0) {
                  uVar10 = 0x5e;
                  goto LAB_18001685c;
                }
                local_628 = &DAT_180021258;
                local_618 = local_6f8;
                local_620 = (undefined4)local_6e0;
                local_638[0] = 5;
                *(undefined4 **)(puVar16 + 0x30) = local_638;
                local_630 = 0xc;
                *(undefined8 **)(puVar16 + 0x28) = &local_6d8;
                *(longlong **)(puVar16 + 0x20) = &local_700;
                *(undefined8 *)(puVar16 + -8) = 0x180016800;
                uVar7 = Ordinal_2(ASN1_NCRYPT_MODULE_HANDLE,0x16,0,param_5);
                lVar1 = local_700;
                uVar14 = (ulonglong)uVar7;
                if (uVar7 != 0) {
                  uVar10 = 0x77;
                  goto LAB_18001685c;
                }
                *(undefined8 **)(puVar16 + 0x38) = local_6b8;
                uVar9 = local_6d8;
                *(undefined **)(puVar16 + 0x30) = param_5;
                *(undefined8 *)(puVar16 + 0x28) = 0;
                *(undefined8 *)(puVar16 + 0x20) = uVar9;
                *(undefined8 *)(puVar16 + -8) = 0x18001684b;
                uVar7 = Ordinal_4(ASN1_NCRYPT_MODULE_HANDLE,0x16,0x200000,lVar1);
                uVar14 = (ulonglong)uVar7;
                if (uVar7 != 0) {
                  uVar10 = 0x87;
                  goto LAB_18001685c;
                }
              }
              else {
                uVar10 = 0x2d;
LAB_18001685c:
                *(undefined8 *)(puVar16 + -8) = 0x180016871;
                DebugTraceError((char)uVar7,"Status",
                                "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\ncryptprotect.c"
                                ,uVar10);
              }
              if (*(int *)(pUVar17 + -8) == 0x70616548) {
                *(undefined8 *)(puVar16 + -8) = 0x180016889;
                (*g_pfnFree)();
              }
            }
            else {
              uVar19 = 0xec;
LAB_1800164a4:
              uVar14 = (ulonglong)uVar7;
              uVar10 = (undefined1)uVar7;
              puVar16 = auStackY_758;
LAB_1800164a6:
              *(undefined8 *)(puVar16 + -8) = 0x1800164b9;
              DebugTraceError(uVar10,"Status",
                              "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\ncryptprotect.c"
                              ,uVar19);
            }
            pUVar17 = pbBuffer;
            for (uVar8 = (ulonglong)cbBuffer; uVar8 != 0; uVar8 = uVar8 - 1) {
              *pUVar17 = '\0';
              pUVar17 = pUVar17 + 1;
            }
            pcVar4 = *(code **)(param_5 + 0x10);
            *(undefined8 *)(puVar16 + -8) = 0x18001689f;
            (*pcVar4)(pbBuffer);
            goto LAB_180016906;
          }
          uVar14 = 0x8009000e;
          uVar19 = 0xe0;
          uVar10 = 0xe;
        }
      }
      else {
        uVar19 = 199;
        uVar10 = (undefined1)uVar8;
      }
      DebugTraceError(uVar10,"Status",
                      "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\ncryptprotect.c"
                      ,uVar19);
      puVar16 = auStackY_758;
      goto LAB_180016906;
    }
  }
  uVar14 = 0x80090027;
  puVar16 = auStackY_758;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (puVar16 = auStackY_758, (WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
    WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),uVar9,uVar18,"Status",0x27,
                "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\ncryptprotect.c",
                0xb8);
    puVar16 = auStackY_758;
  }
LAB_180016906:
  while (local_6a4 != 0) {
    local_6a4 = local_6a4 - 1;
    lVar1 = local_598[local_6a4];
    pcVar4 = *(code **)(param_5 + 0x10);
    *(undefined8 *)(puVar16 + -8) = 0x180016906;
    (*pcVar4)(lVar1);
  }
  local_6a4 = 0xffffffff;
  if (local_640 != 0) {
    pcVar4 = *(code **)(param_5 + 0x10);
    *(undefined8 *)(puVar16 + -8) = 0x180016927;
    (*pcVar4)();
  }
  if (local_700 != 0) {
    pcVar4 = *(code **)(param_5 + 0x10);
    *(undefined8 *)(puVar16 + -8) = 0x180016939;
    (*pcVar4)();
  }
  if (local_6f8 != 0) {
    pcVar4 = *(code **)(param_5 + 0x10);
    *(undefined8 *)(puVar16 + -8) = 0x18001694b;
    (*pcVar4)();
  }
  *(undefined8 *)(puVar16 + -8) = 0x18001695c;
  return uVar14;
}



===== WPP_SF_D @ 180016978 =====

void WPP_SF_D(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  EtwTraceMessage(param_1,0x2b,&WPP_a8d589a743023471636e7d078e4c0fe8_Traceguids,param_2,local_res20,
                  4,0);
  return;
}



===== McTemplateU0zzzddz_EventWriteTransfer @ 1800169c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateU0zzzddz_EventWriteTransfer
               (undefined8 param_1,undefined8 param_2,wchar_t *param_3,wchar_t *param_4,
               wchar_t *param_5,undefined1 param_6,undefined1 param_7,wchar_t *param_8)

{
  longlong lVar1;
  longlong lVar2;
  undefined1 auStackY_b8 [32];
  _EVENT_DATA_DESCRIPTOR local_88;
  wchar_t *local_78;
  int local_70;
  undefined4 local_6c;
  wchar_t *local_68;
  int local_60;
  undefined4 local_5c;
  wchar_t *local_58;
  int local_50;
  undefined4 local_4c;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  wchar_t *local_28;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_b8;
  lVar1 = -1;
  local_20 = 10;
  if (param_3 == (wchar_t *)0x0) {
    local_70 = 10;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (param_3[lVar2] != L'\0');
    local_70 = (int)lVar2 * 2 + 2;
  }
  local_6c = 0;
  if (param_3 == (wchar_t *)0x0) {
    param_3 = L"NULL";
  }
  if (param_4 == (wchar_t *)0x0) {
    local_60 = 10;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (param_4[lVar2] != L'\0');
    local_60 = (int)lVar2 * 2 + 2;
  }
  local_5c = 0;
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"NULL";
  }
  if (param_5 == (wchar_t *)0x0) {
    local_50 = 10;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (param_5[lVar2] != L'\0');
    local_50 = (int)lVar2 * 2 + 2;
  }
  local_48 = &param_6;
  local_4c = 0;
  if (param_5 == (wchar_t *)0x0) {
    param_5 = L"NULL";
  }
  local_38 = &param_7;
  local_40 = 4;
  local_30 = 4;
  if (param_8 != (wchar_t *)0x0) {
    do {
      lVar1 = lVar1 + 1;
    } while (param_8[lVar1] != L'\0');
    local_20 = (int)lVar1 * 2 + 2;
  }
  local_28 = param_8;
  if (param_8 == (wchar_t *)0x0) {
    local_28 = L"NULL";
  }
  local_1c = 0;
  local_78 = param_3;
  local_68 = param_4;
  local_58 = param_5;
  McGenEventWrite_EventWriteTransfer
            (local_38,(PCEVENT_DESCRIPTOR)&ETW_LOG_NCRYPT_CREATE_KEY_FAILED,param_3,7,&local_88);
  return;
}



===== NCryptSerializeUIPolicy @ 180016b14 =====

undefined8 NCryptSerializeUIPolicy(int *param_1,undefined4 *param_2,uint param_3,uint *param_4)

{
  int iVar1;
  uint uVar2;
  longlong lVar3;
  undefined1 uVar4;
  longlong lVar5;
  longlong lVar6;
  undefined8 uVar7;
  uint uVar8;
  undefined4 *_Dst;
  undefined1 uVar9;
  uint uVar10;
  uint uVar11;
  
  uVar11 = 0;
  uVar10 = 0;
  uVar8 = 0;
  if (((param_1 == (int *)0x0) || (param_4 == (uint *)0x0)) || (0x100000 < param_3)) {
    uVar7 = 0x80090027;
  }
  else {
    if (*param_1 == 1) {
      lVar5 = *(longlong *)(param_1 + 2);
      lVar6 = -1;
      uVar2 = 0x14;
      *param_4 = 0x14;
      if (lVar5 != 0) {
        lVar3 = -1;
        do {
          lVar3 = lVar3 + 1;
        } while (*(short *)(lVar5 + lVar3 * 2) != 0);
        iVar1 = (int)lVar3 * 2;
        uVar11 = iVar1 + 2;
        uVar2 = iVar1 + 0x16;
        *param_4 = uVar2;
      }
      if (*(longlong *)(param_1 + 4) != 0) {
        lVar5 = -1;
        do {
          lVar5 = lVar5 + 1;
        } while (*(short *)(*(longlong *)(param_1 + 4) + lVar5 * 2) != 0);
        uVar10 = (int)lVar5 * 2 + 2;
        uVar2 = uVar2 + uVar10;
        *param_4 = uVar2;
      }
      if (*(longlong *)(param_1 + 6) != 0) {
        do {
          lVar6 = lVar6 + 1;
        } while (*(short *)(*(longlong *)(param_1 + 6) + lVar6 * 2) != 0);
        uVar8 = (int)lVar6 * 2 + 2;
        uVar2 = uVar2 + uVar8;
        *param_4 = uVar2;
      }
      if (uVar2 < 0x100001) {
        if (param_2 == (undefined4 *)0x0) {
          return 0;
        }
        if (param_3 < uVar2) {
          return 0x80090028;
        }
        memset(param_2,0,(ulonglong)uVar2);
        if (*param_1 != 1) {
          return 0x80090029;
        }
        *param_2 = 1;
        _Dst = param_2 + 5;
        param_2[1] = param_1[1];
        if (*(longlong *)(param_1 + 2) != 0) {
          param_2[2] = uVar11;
          memcpy(_Dst,*(void **)(param_1 + 2),(ulonglong)uVar11);
          _Dst = (undefined4 *)((longlong)_Dst + (ulonglong)(uint)param_2[2]);
        }
        if (*(longlong *)(param_1 + 4) != 0) {
          param_2[3] = uVar10;
          memcpy(_Dst,*(void **)(param_1 + 4),(ulonglong)uVar10);
          _Dst = (undefined4 *)((longlong)_Dst + (ulonglong)(uint)param_2[3]);
        }
        if (*(longlong *)(param_1 + 6) == 0) {
          return 0;
        }
        param_2[4] = uVar8;
        memcpy(_Dst,*(void **)(param_1 + 6),(ulonglong)uVar8);
        return 0;
      }
      *param_4 = 0;
      uVar4 = 0x27;
      uVar7 = 0x80090027;
      uVar9 = 0x6b;
    }
    else {
      uVar7 = 0x80090029;
      uVar9 = 0x60;
      uVar4 = 0x29;
    }
    DebugTraceError(uVar4,"Status",
                    "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",uVar9);
  }
  return uVar7;
}



===== I_UnprotectCombinerRecipientKey @ 180016cec =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

ulonglong I_UnprotectCombinerRecipientKey
                    (longlong param_1,ulonglong param_2,int *param_3,undefined *param_4,
                    undefined8 param_5,undefined8 *param_6,undefined4 *param_7)

{
  ULONG UVar1;
  longlong *plVar2;
  ushort *puVar3;
  code *pcVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  longlong lVar8;
  int iVar9;
  uint uVar10;
  PUCHAR pUVar11;
  undefined8 uVar12;
  undefined1 uVar13;
  longlong lVar14;
  ulonglong uVar15;
  ulonglong uVar16;
  ulonglong uVar17;
  undefined1 *puVar18;
  undefined1 *puVar19;
  longlong lVar20;
  undefined4 *puVar21;
  PUCHAR pUVar22;
  undefined4 *puVar23;
  undefined1 uVar24;
  PUCHAR pUVar25;
  uint uVar26;
  undefined1 auStackY_a8 [32];
  uint local_68 [2];
  undefined *local_60;
  undefined4 *local_58;
  longlong local_50;
  longlong local_48;
  longlong local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)local_68;
  local_68[0] = 0;
  local_58 = (undefined4 *)0x0;
  local_68[1] = 0;
  pUVar11 = (PUCHAR)0x0;
  *param_6 = 0;
  uVar26 = 0;
  local_50 = 0;
  *param_7 = 0;
  lVar20 = (param_2 & 0xffffffff) * 0x20;
  local_48 = 0;
  local_60 = param_4;
  local_40 = param_1;
  if (*(uint *)(lVar20 + *(longlong *)(*(longlong *)(param_1 + 8) + 8)) < 9) {
    if ((*param_3 == 5) && (param_3[2] == 0xc)) {
      lVar14 = **(longlong **)(param_3 + 4) + 0x7dfefbfef9d4f5fa;
      if (lVar14 == 0) {
        lVar14 = (ulonglong)*(uint *)(*(longlong **)(param_3 + 4) + 1) - 0x4014a37;
      }
      if (lVar14 != 0) goto LAB_180017175;
      uVar17 = Ordinal_4(ASN1_NCRYPT_MODULE_HANDLE,0x1d,1,*(undefined8 *)(param_3 + 8));
      iVar9 = (int)uVar17;
      if (iVar9 != 0) {
        uVar24 = 0xf1;
LAB_180016e47:
        uVar17 = uVar17 & 0xffffffff;
        uVar13 = (undefined1)iVar9;
        goto LAB_180017185;
      }
      if (*(int *)(local_50 + 0x38) != 0xb) {
LAB_18001716d:
        uVar24 = 0xf8;
        goto LAB_18001717b;
      }
      plVar2 = *(longlong **)(local_50 + 0x40);
      lVar14 = *plVar2 + -0x365014886600906;
      if ((lVar14 == 0) && (lVar14 = (ulonglong)*(ushort *)(plVar2 + 1) - 0x104, lVar14 == 0)) {
        lVar14 = (ulonglong)*(byte *)((longlong)plVar2 + 10) - 0x2d;
      }
      if (lVar14 != 0) goto LAB_18001716d;
      uVar17 = CNG_FindBCryptOidInfo
                         (*(undefined8 *)(local_50 + 0x18),*(uint *)(local_50 + 0x10),2,&local_48);
      iVar9 = (int)uVar17;
      if (iVar9 != 0) {
        uVar24 = 8;
        goto LAB_180016e47;
      }
      uVar26 = *(int *)(lVar20 + *(longlong *)(*(longlong *)(param_1 + 8) + 8)) << 5;
      pUVar11 = (PUCHAR)(**(code **)(param_4 + 8))(uVar26);
      puVar19 = auStackY_a8;
      if (pUVar11 == (PUCHAR)0x0) {
        uVar17 = 0x8009000e;
        uVar24 = 0x18;
        uVar13 = 0xe;
      }
      else {
        if (0x1f < uVar26) {
          uVar16 = 0;
          pUVar25 = pUVar11;
          while( true ) {
            lVar8 = local_48;
            lVar14 = *(longlong *)(*(longlong *)(local_40 + 8) + 8);
            if (*(uint *)(lVar14 + lVar20) <= (uint)uVar16) break;
            uVar10 = NCryptUnprotectKey(*(int **)(uVar16 * 0x20 + 0x10 +
                                                 *(longlong *)(lVar14 + 8 + lVar20)),
                                        (int *)(uVar16 * 0xa0 + *(longlong *)(local_50 + 8)),
                                        local_60,param_5,&local_58,local_68 + 1,0);
            uVar17 = (ulonglong)uVar10;
            if (uVar10 != 0) {
              uVar24 = 0x32;
              goto LAB_180016fd5;
            }
            if (local_68[1] != 0x20) {
              uVar17 = 0x80090003;
              uVar24 = 0x39;
              uVar10 = 0x80090003;
              puVar19 = auStackY_a8;
              goto LAB_180016fd5;
            }
            uVar5 = local_58[1];
            uVar6 = local_58[2];
            uVar7 = local_58[3];
            *(undefined4 *)pUVar25 = *local_58;
            *(undefined4 *)(pUVar25 + 4) = uVar5;
            *(undefined4 *)(pUVar25 + 8) = uVar6;
            *(undefined4 *)(pUVar25 + 0xc) = uVar7;
            uVar5 = local_58[5];
            uVar6 = local_58[6];
            uVar7 = local_58[7];
            *(undefined4 *)(pUVar25 + 0x10) = local_58[4];
            *(undefined4 *)(pUVar25 + 0x14) = uVar5;
            *(undefined4 *)(pUVar25 + 0x18) = uVar6;
            *(undefined4 *)(pUVar25 + 0x1c) = uVar7;
            pUVar25 = pUVar25 + 0x20;
            puVar21 = local_58;
            for (lVar14 = 0x20; lVar14 != 0; lVar14 = lVar14 + -1) {
              *(undefined1 *)puVar21 = 0;
              puVar21 = (undefined4 *)((longlong)puVar21 + 1);
            }
            (**(code **)(local_60 + 0x10))(local_58);
            local_58 = (undefined4 *)0x0;
            uVar16 = (ulonglong)((uint)uVar16 + 1);
          }
          pUVar25 = (PUCHAR)0x0;
          local_68[0] = *(uint *)(local_48 + 0x3c);
          uVar17 = (ulonglong)local_68[0];
          uVar16 = (ulonglong)local_68[0];
          puVar18 = auStackY_a8;
          if (((local_68[0] == 0) || (puVar18 = auStackY_a8, g_ulMaxStackAllocSize < uVar17)) ||
             (uVar15 = g_ulAdditionalProbeSize + 8 + uVar17, puVar18 = auStackY_a8, uVar15 < uVar17)
             ) {
LAB_18001706a:
            puVar19 = puVar18;
            if (uVar16 <= uVar16 + 8) {
              *(undefined8 *)(puVar18 + -8) = 0x18001707f;
              pUVar25 = (PUCHAR)(*g_pfnAllocate)();
              if (pUVar25 != (PUCHAR)0x0) {
                builtin_memcpy(pUVar25,"Heap",4);
                pUVar25 = pUVar25 + 8;
              }
            }
          }
          else {
            uVar12 = VerifyStackAvailable(uVar15);
            puVar18 = auStackY_a8;
            if ((int)uVar12 == 0) goto LAB_18001706a;
            uVar17 = uVar16 + 0x17;
            if (uVar17 <= uVar16 + 8) {
              uVar17 = 0xffffffffffffff0;
            }
            lVar20 = -(uVar17 & 0xfffffffffffffff0);
            pUVar25 = (PUCHAR)0x0;
            puVar18 = auStackY_a8 + lVar20;
            if ((undefined4 *)((longlong)local_68 + lVar20) == (undefined4 *)0x0)
            goto LAB_18001706a;
            *(undefined4 *)((longlong)local_68 + lVar20) = 0x6b637453;
            pUVar25 = (PUCHAR)((longlong)local_68 + lVar20 + 8);
            puVar18 = auStackY_a8 + lVar20;
            puVar19 = auStackY_a8 + lVar20;
            if (pUVar25 == (PUCHAR)0x0) goto LAB_18001706a;
          }
          if (pUVar25 == (PUCHAR)0x0) {
            uVar17 = 0x8009000e;
            uVar24 = 0x4f;
            uVar10 = 0x8009000e;
LAB_180016fd5:
            *(undefined8 *)(puVar19 + -8) = 0x180016fe8;
            DebugTraceError((char)uVar10,"Status",
                            "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\ncryptprotect.c"
                            ,uVar24);
            param_4 = local_60;
          }
          else {
            puVar3 = *(ushort **)(lVar8 + 8);
            *(uint **)(puVar19 + 0x28) = local_68;
            *(uint *)(puVar19 + 0x20) = local_68[0];
            *(undefined8 *)(puVar19 + -8) = 0x1800170ca;
            uVar10 = CNG_ComputeHash(pUVar11,uVar26,puVar3,pUVar25,*(uint *)(puVar19 + 0x20),
                                     *(uint **)(puVar19 + 0x28));
            lVar20 = local_50;
            param_4 = local_60;
            uVar17 = (ulonglong)uVar10;
            if (uVar10 == 0) {
              *(undefined4 **)(puVar19 + 0x30) = param_7;
              UVar1 = *(ULONG *)(lVar20 + 0x60);
              pUVar22 = *(PUCHAR *)(lVar20 + 0x68);
              *(undefined8 **)(puVar19 + 0x28) = param_6;
              *(uint *)(puVar19 + 0x20) = local_68[0];
              *(undefined8 *)(puVar19 + -8) = 0x18001712b;
              uVar10 = CNG_AesKeyUnwrap((longlong)param_4,pUVar22,UVar1,pUVar25,
                                        *(ULONG *)(puVar19 + 0x20),*(undefined8 **)(puVar19 + 0x28),
                                        *(uint **)(puVar19 + 0x30));
              uVar17 = (ulonglong)uVar10;
              if ((int)uVar10 < 0) {
                *(undefined8 *)(puVar19 + -8) = 0x18001714c;
                DebugTraceError((char)uVar10,"Status",
                                "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\ncryptprotect.c"
                                ,0x6e);
              }
            }
            else {
              *(undefined8 *)(puVar19 + -8) = 0x1800170eb;
              DebugTraceError((char)uVar10,"Status",
                              "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\ncryptprotect.c"
                              ,0x5d);
              param_4 = local_60;
            }
            pUVar22 = pUVar25;
            for (uVar16 = (ulonglong)local_68[0]; uVar16 != 0; uVar16 = uVar16 - 1) {
              *pUVar22 = '\0';
              pUVar22 = pUVar22 + 1;
            }
            if (*(int *)(pUVar25 + -8) == 0x70616548) {
              *(undefined8 *)(puVar19 + -8) = 0x18001716b;
              (*g_pfnFree)();
            }
          }
          goto LAB_180017198;
        }
        uVar17 = 0x80070216;
        uVar24 = 0x1f;
        uVar13 = 0x16;
      }
    }
    else {
LAB_180017175:
      uVar24 = 0xe1;
LAB_18001717b:
      uVar13 = 5;
      uVar17 = 0x80090005;
    }
LAB_180017185:
    DebugTraceError(uVar13,"Status",
                    "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\ncryptprotect.c"
                    ,uVar24);
    puVar19 = auStackY_a8;
  }
  else {
    uVar17 = 0x80090005;
    puVar19 = auStackY_a8;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       (puVar19 = auStackY_a8, (WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_1800171d0;
    WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),param_2,
                "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\ncryptprotect.c",
                "Status",5,
                "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\ncryptprotect.c",
                0xd9);
    puVar19 = auStackY_a8;
  }
LAB_180017198:
  puVar21 = local_58;
  if (local_58 != (undefined4 *)0x0) {
    puVar23 = local_58;
    for (uVar16 = (ulonglong)local_68[1]; uVar16 != 0; uVar16 = uVar16 - 1) {
      *(undefined1 *)puVar23 = 0;
      puVar23 = (undefined4 *)((longlong)puVar23 + 1);
    }
    pcVar4 = *(code **)(param_4 + 0x10);
    *(undefined8 *)(puVar19 + -8) = 0x1800171b5;
    (*pcVar4)(puVar21);
  }
  if (pUVar11 != (PUCHAR)0x0) {
    pUVar25 = pUVar11;
    for (uVar16 = (ulonglong)uVar26; uVar16 != 0; uVar16 = uVar16 - 1) {
      *pUVar25 = '\0';
      pUVar25 = pUVar25 + 1;
    }
    pcVar4 = *(code **)(param_4 + 0x10);
    *(undefined8 *)(puVar19 + -8) = 0x1800171d0;
    (*pcVar4)(pUVar11);
  }
LAB_1800171d0:
  *(undefined8 *)(puVar19 + -8) = 0x1800171de;
  return uVar17;
}



===== wil_details_FeatureReporting_IncrementUsageInCache @ 180017204 =====

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



===== NCryptSetProperty @ 1800172f0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

SECURITY_STATUS __stdcall
NCryptSetProperty(NCRYPT_HANDLE hObject,LPCWSTR pszProperty,PBYTE pbInput,DWORD cbInput,
                 DWORD dwFlags)

{
  undefined4 *puVar1;
  byte bVar2;
  void *_Buf1;
  code *pcVar3;
  uint uVar4;
  BOOL BVar5;
  int iVar6;
  ulonglong uVar7;
  LPCWSTR pWVar8;
  undefined8 uVar9;
  LPCWSTR pWVar10;
  longlong lVar11;
  NCRYPT_HANDLE NVar12;
  wchar_t *pwVar13;
  DWORD DVar14;
  ulonglong uVar15;
  undefined1 *puVar16;
  undefined1 *puVar17;
  wchar_t *pwVar18;
  char *pcVar19;
  undefined1 auStackY_a8 [32];
  NCRYPT_HANDLE local_68;
  WCHAR local_60 [2];
  uint local_5c;
  DWORD local_58;
  int local_54;
  undefined4 local_50 [2];
  LPCWSTR local_48;
  LPCWSTR local_40;
  NCRYPT_HANDLE local_38;
  ulonglong local_30;
  
                    /* 0x172f0  99  NCryptSetProperty */
  local_30 = __security_cookie ^ (ulonglong)&local_68;
  local_38 = hObject;
  local_48 = (LPCWSTR)0x0;
  local_54 = 0;
  pWVar8 = (LPCWSTR)0x0;
  local_58 = 0;
  local_40 = (LPCWSTR)0x0;
  local_5c = 0;
  pwVar13 = pszProperty;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    pwVar13 = (LPCWSTR)0x11;
    WPP_SF_PSD(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x11,WPP_GLOBAL_Control,hObject,
               pszProperty,(char)dwFlags);
  }
  NVar12 = 0;
  if ((hObject == 0) || (*(int *)hObject != 0x44440001)) {
    local_68 = 0;
    if ((hObject == 0) || (*(int *)hObject != 0x44440002)) {
      DVar14 = 0x80090026;
      puVar17 = auStackY_a8;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (puVar17 = auStackY_a8, (WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
        WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),pwVar13,WPP_GLOBAL_Control,"Status",
                    0x26,"onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",0xac);
        puVar17 = auStackY_a8;
      }
      goto LAB_18001741a;
    }
  }
  else {
    LOCK();
    *(int *)(hObject + 4) = *(int *)(hObject + 4) + 1;
    UNLOCK();
    local_68 = hObject;
    hObject = 0;
  }
  pwVar18 = (wchar_t *)WPP_GLOBAL_Control;
  if (pszProperty == (LPCWSTR)0x0) {
    DVar14 = 0x80090027;
    puVar17 = auStackY_a8;
    if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
      bVar2 = WPP_GLOBAL_Control[0x1c];
      goto joined_r0x000180017a50;
    }
  }
  else {
    uVar15 = 0xffffffffffffffff;
    uVar7 = 0xffffffffffffffff;
    do {
      uVar7 = uVar7 + 1;
    } while (pszProperty[uVar7] != L'\0');
    if (uVar7 < 0x41) {
      pwVar13 = L"Security Descr";
      lVar11 = -1;
LAB_180017500:
      pWVar10 = (LPCWSTR)pbInput;
      if (pszProperty[lVar11 + 1] == L"Security Descr"[lVar11 + 1]) {
        lVar11 = lVar11 + 2;
        if (lVar11 != 0xf) goto code_r0x000180017516;
        BVar5 = IsValidSecurityDescriptor(pbInput);
        if (BVar5 == 0) {
          DVar14 = 0x80090005;
          puVar17 = auStackY_a8;
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_180017416;
          bVar2 = WPP_GLOBAL_Control[0x1c];
        }
        else {
          if ((hObject != 0) && (*(longlong *)(hObject + 8) != 0)) {
            _Buf1 = *(void **)(*(longlong *)(hObject + 8) + 0x118);
            do {
              uVar15 = uVar15 + 1;
            } while (*(short *)((longlong)_Buf1 + uVar15 * 2) != 0);
            if ((uVar15 & 0x7fffffffffffffff) == 0x27) {
              pwVar18 = (LPCWSTR)0x50;
              pwVar13 = L"Microsoft Software Key Storage Provider";
              iVar6 = memcmp(_Buf1,L"Microsoft Software Key Storage Provider",0x50);
              if (iVar6 != 0) goto LAB_180017730;
              pwVar13 = (LPCWSTR)0x1;
              pwVar18 = (LPCWSTR)0xf;
              iVar6 = ConvertSecurityDescriptorToStringSecurityDescriptorW(pbInput,1,0xf,&local_48);
              puVar17 = auStackY_a8;
              if (iVar6 != 0) {
                uVar4 = local_54 * 2 + 2;
                pWVar10 = local_48;
                goto LAB_1800176c2;
              }
              DVar14 = GetLastError();
              if (0 < (int)DVar14) {
                DVar14 = DVar14 & 0xffff | 0x80070000;
              }
              puVar17 = auStackY_a8;
              if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_180017416;
              bVar2 = WPP_GLOBAL_Control[0x1c];
              goto joined_r0x000180017685;
            }
          }
LAB_180017730:
          local_60[0] = L'\0';
          local_50[0] = 0;
          uVar4 = GetSecurityDescriptorLength(pbInput);
          local_58 = uVar4;
          if (uVar4 <= cbInput) {
            pwVar18 = (wchar_t *)local_50;
            pwVar13 = local_60;
            BVar5 = GetSecurityDescriptorControl
                              (pbInput,(PSECURITY_DESCRIPTOR_CONTROL)pwVar13,(LPDWORD)pwVar18);
            puVar17 = auStackY_a8;
            if (BVar5 != 0) {
              if ((local_60[0] & 0x8000U) != 0) goto LAB_1800176c2;
              uVar7 = (ulonglong)local_58;
              puVar16 = auStackY_a8;
              if ((uVar7 == 0) || (puVar16 = auStackY_a8, g_ulMaxStackAllocSize < uVar7)) {
LAB_180017859:
                puVar17 = puVar16;
                if (uVar7 <= uVar7 + 8) {
                  *(undefined8 *)(puVar16 + -8) = 0x18001786e;
                  pWVar8 = (LPCWSTR)(*g_pfnAllocate)();
                  if (pWVar8 != (LPCWSTR)0x0) {
                    pWVar8[0] = L'效';
                    pWVar8[1] = L'灡';
                    pWVar8 = pWVar8 + 4;
                  }
                }
              }
              else {
                uVar15 = g_ulAdditionalProbeSize + 8 + uVar7;
                puVar16 = auStackY_a8;
                if (uVar15 < uVar7) goto LAB_180017859;
                uVar9 = VerifyStackAvailable(uVar15);
                puVar16 = auStackY_a8;
                if ((int)uVar9 == 0) goto LAB_180017859;
                uVar15 = uVar7 + 0x17;
                if (uVar15 <= uVar7 + 8) {
                  uVar15 = 0xffffffffffffff0;
                }
                lVar11 = -(uVar15 & 0xfffffffffffffff0);
                puVar1 = (undefined4 *)((longlong)local_60 + lVar11 + -8);
                pWVar8 = (LPCWSTR)0x0;
                puVar16 = auStackY_a8 + lVar11;
                if (puVar1 == (undefined4 *)0x0) goto LAB_180017859;
                *puVar1 = 0x6b637453;
                pWVar8 = (LPCWSTR)((longlong)local_60 + lVar11);
                puVar16 = auStackY_a8 + lVar11;
                puVar17 = auStackY_a8 + lVar11;
                if (pWVar8 == (LPCWSTR)0x0) goto LAB_180017859;
              }
              if (pWVar8 == (LPCWSTR)0x0) {
                DVar14 = 0x8009000e;
                if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
                  uVar9 = *(undefined8 *)(WPP_GLOBAL_Control + 0x10);
                  *(undefined4 *)(puVar17 + 0x30) = 0x70b;
                  *(char **)(puVar17 + 0x28) =
                       "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c";
                  *(undefined4 *)(puVar17 + 0x20) = 0x8009000e;
                  goto LAB_18001740a;
                }
              }
              else {
                pwVar18 = (wchar_t *)&local_58;
                *(undefined8 *)(puVar17 + -8) = 0x1800178e1;
                pwVar13 = pWVar8;
                BVar5 = MakeSelfRelativeSD(pbInput,pWVar8,(LPDWORD)pwVar18);
                pWVar10 = pWVar8;
                if (BVar5 != 0) goto LAB_1800176c2;
                *(undefined8 *)(puVar17 + -8) = 0x1800178f1;
                DVar14 = GetLastError();
                if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
                  *(undefined4 *)(puVar17 + 0x30) = 0x713;
                  puVar16 = puVar17;
                  goto LAB_180017693;
                }
              }
              goto LAB_180017416;
            }
            DVar14 = GetLastError();
            puVar16 = auStackY_a8;
            puVar17 = auStackY_a8;
            if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
               (puVar17 = auStackY_a8, (WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_180017416;
            goto LAB_180017693;
          }
          DVar14 = 0x80090005;
          puVar17 = auStackY_a8;
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_180017416;
          bVar2 = WPP_GLOBAL_Control[0x1c];
        }
        DVar14 = 0x80090005;
        puVar17 = auStackY_a8;
        if ((bVar2 & 1) == 0) goto LAB_180017416;
        puVar17 = auStackY_a8;
        DVar14 = 0x80090005;
        uVar9 = *(undefined8 *)(WPP_GLOBAL_Control + 0x10);
        goto LAB_18001740a;
      }
      goto LAB_180017520;
    }
    DVar14 = 0x80090027;
    puVar17 = auStackY_a8;
    if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
      bVar2 = WPP_GLOBAL_Control[0x1c];
joined_r0x000180017a50:
      DVar14 = 0x80090027;
      puVar17 = auStackY_a8;
      if ((bVar2 & 1) != 0) {
        DVar14 = 0x80090027;
        uVar9 = *(undefined8 *)(WPP_GLOBAL_Control + 0x10);
        puVar17 = auStackY_a8;
LAB_18001740a:
        *(undefined8 *)(puVar17 + -8) = 0x180017416;
        WPP_SF_sDsd(uVar9,pwVar13,pwVar18,"Status",puVar17[0x20],*(char **)(puVar17 + 0x28),
                    puVar17[0x30]);
      }
    }
  }
  goto LAB_180017416;
code_r0x000180017516:
  if (pszProperty[lVar11] != L"Security Descr"[lVar11]) goto LAB_180017520;
  goto LAB_180017500;
LAB_180017520:
  pwVar13 = L"UI Policy";
  do {
    uVar4 = cbInput;
    puVar17 = auStackY_a8;
    if ((pszProperty[NVar12] != L"UI Policy"[NVar12]) ||
       (puVar17 = auStackY_a8, pszProperty[NVar12 + 1] != L"UI Policy"[NVar12 + 1]))
    goto LAB_1800176c2;
    NVar12 = NVar12 + 2;
  } while (NVar12 != 10);
  if (cbInput < 0x20) {
    DVar14 = 0x80090027;
    puVar17 = auStackY_a8;
    if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
      bVar2 = WPP_GLOBAL_Control[0x1c];
      goto joined_r0x000180017a50;
    }
  }
  else if (*(int *)pbInput == 1) {
    pwVar18 = (LPCWSTR)0x0;
    pwVar13 = (LPCWSTR)0x0;
    uVar9 = NCryptSerializeUIPolicy((int *)pbInput,(undefined4 *)0x0,0,&local_5c);
    uVar4 = local_5c;
    DVar14 = (DWORD)uVar9;
    if (DVar14 == 0) {
      pWVar10 = (LPCWSTR)MSCryptAlloc((ulonglong)local_5c);
      local_40 = pWVar10;
      if (pWVar10 == (LPCWSTR)0x0) {
        DVar14 = 0x8009000e;
        puVar17 = auStackY_a8;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (puVar17 = auStackY_a8, (WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
          uVar9 = *(undefined8 *)(WPP_GLOBAL_Control + 0x10);
          puVar17 = auStackY_a8;
          goto LAB_18001740a;
        }
      }
      else {
        pwVar18 = (wchar_t *)(ulonglong)uVar4;
        pwVar13 = pWVar10;
        uVar9 = NCryptSerializeUIPolicy((int *)pbInput,(undefined4 *)pWVar10,uVar4,&local_5c);
        puVar17 = auStackY_a8;
        DVar14 = (DWORD)uVar9;
        uVar4 = local_5c;
        if (DVar14 == 0) {
LAB_1800176c2:
          do {
            if (hObject == 0) {
              pcVar19 = (char *)(ulonglong)uVar4;
              *(DWORD *)(puVar17 + 0x20) = dwFlags;
              uVar9 = *(undefined8 *)(local_68 + 0x110);
              pcVar3 = *(code **)(local_68 + 0x40);
              *(undefined8 *)(puVar17 + -8) = 0x180017a8a;
              pwVar13 = pszProperty;
              pwVar18 = pWVar10;
              DVar14 = (*pcVar3)(uVar9);
              if (((DVar14 != 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
                 ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
                *(undefined4 *)(puVar17 + 0x30) = 0x775;
                goto LAB_180017ab1;
              }
            }
            else {
              lVar11 = *(longlong *)(hObject + 8);
              *(DWORD *)(puVar17 + 0x28) = dwFlags;
              pwVar13 = *(wchar_t **)(hObject + 0x10);
              pcVar3 = *(code **)(lVar11 + 0x48);
              uVar9 = *(undefined8 *)(lVar11 + 0x110);
              *(uint *)(puVar17 + 0x20) = uVar4;
              *(undefined8 *)(puVar17 + -8) = 0x1800176f8;
              pwVar18 = pszProperty;
              pcVar19 = (char *)pWVar10;
              DVar14 = (*pcVar3)(uVar9);
              if (((DVar14 != 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
                 ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
                *(undefined4 *)(puVar17 + 0x30) = 0x768;
LAB_180017ab1:
                uVar9 = *(undefined8 *)(WPP_GLOBAL_Control + 0x10);
                pcVar19 = "Status";
                *(char **)(puVar17 + 0x28) =
                     "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c";
                *(DWORD *)(puVar17 + 0x20) = DVar14;
                *(undefined8 *)(puVar17 + -8) = 0x180017aca;
                WPP_SF_sDsd(uVar9,pwVar13,pwVar18,"Status",puVar17[0x20],*(char **)(puVar17 + 0x28),
                            puVar17[0x30]);
              }
            }
            NVar12 = local_38;
            if (DVar14 != 0x8009002e) {
              if (DVar14 != 0) {
                if (hObject == 0) goto LAB_180017416;
                goto LAB_180017c0d;
              }
              DVar14 = 0;
              goto LAB_180017416;
            }
            if ((dwFlags & 0x40) != 0) {
              DVar14 = 0x80090022;
              if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                 ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_180017416;
              uVar9 = *(undefined8 *)(WPP_GLOBAL_Control + 0x10);
              *(undefined4 *)(puVar17 + 0x30) = 0x782;
              *(char **)(puVar17 + 0x28) =
                   "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c";
              *(undefined4 *)(puVar17 + 0x20) = 0x80090022;
              goto LAB_18001740a;
            }
            pcVar19 = (char *)0x0;
            pwVar18 = L"NCryptSetProperty";
            if (hObject == 0) {
              pwVar13 = (LPCWSTR)0x0;
              uVar9 = *(undefined8 *)(local_68 + 0x110);
              pcVar3 = *(code **)(local_68 + 0xc0);
              *(undefined8 *)(puVar17 + -8) = 0x180017b85;
              DVar14 = (*pcVar3)(uVar9);
              if (DVar14 != 0) {
                if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                   ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_180017416;
                uVar9 = *(undefined8 *)(WPP_GLOBAL_Control + 0x10);
                *(undefined4 *)(puVar17 + 0x30) = 0x79b;
                *(char **)(puVar17 + 0x28) =
                     "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c";
                *(DWORD *)(puVar17 + 0x20) = DVar14;
                goto LAB_18001740a;
              }
              goto LAB_1800176c2;
            }
            pcVar3 = *(code **)(*(longlong *)(hObject + 8) + 0xc0);
            uVar9 = *(undefined8 *)(*(longlong *)(hObject + 8) + 0x110);
            *(undefined8 *)(puVar17 + -8) = 0x180017b1b;
            DVar14 = (*pcVar3)(uVar9);
          } while (DVar14 == 0);
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
            uVar9 = *(undefined8 *)(WPP_GLOBAL_Control + 0x10);
            pcVar19 = "Status";
            *(undefined4 *)(puVar17 + 0x30) = 0x78f;
            *(char **)(puVar17 + 0x28) =
                 "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c";
            *(DWORD *)(puVar17 + 0x20) = DVar14;
            *(undefined8 *)(puVar17 + -8) = 0x180017b67;
            WPP_SF_sDsd(uVar9,NVar12,pwVar18,"Status",puVar17[0x20],*(char **)(puVar17 + 0x28),
                        puVar17[0x30]);
          }
LAB_180017c0d:
          if (*(longlong *)(hObject + 8) != 0) {
            pwVar13 = *(wchar_t **)(hObject + 0x18);
            pwVar18 = *(wchar_t **)(*(longlong *)(hObject + 8) + 0x118);
            *(DWORD *)(puVar17 + 0x20) = DVar14;
            *(undefined8 *)(puVar17 + -8) = 0x180017c33;
            EtwLogNCryptOperationFailed(0x11,pwVar18,pwVar13,pcVar19,puVar17[0x20]);
          }
        }
        else {
          puVar17 = auStackY_a8;
          if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
            bVar2 = WPP_GLOBAL_Control[0x1c];
joined_r0x000180017685:
            puVar16 = auStackY_a8;
            puVar17 = puVar16;
            if ((bVar2 & 1) != 0) {
LAB_180017693:
              uVar9 = *(undefined8 *)(WPP_GLOBAL_Control + 0x10);
              *(char **)(puVar16 + 0x28) =
                   "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c";
              *(DWORD *)(puVar16 + 0x20) = DVar14;
              puVar17 = puVar16;
              goto LAB_18001740a;
            }
          }
        }
      }
    }
    else {
      puVar17 = auStackY_a8;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (puVar17 = auStackY_a8, (WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
        uVar9 = *(undefined8 *)(WPP_GLOBAL_Control + 0x10);
        puVar17 = auStackY_a8;
        goto LAB_18001740a;
      }
    }
  }
  else {
    DVar14 = 0x80090027;
    puVar17 = auStackY_a8;
    if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
      bVar2 = WPP_GLOBAL_Control[0x1c];
      goto joined_r0x000180017a50;
    }
  }
LAB_180017416:
  NVar12 = local_68;
LAB_18001741a:
  pWVar10 = local_48;
  if (local_48 != (LPCWSTR)0x0) {
    *(undefined8 *)(puVar17 + -8) = 0x18001742a;
    LocalFree(pWVar10);
  }
  if ((pWVar8 != (LPCWSTR)0x0) && (*(DWORD *)(pWVar8 + -4) == 0x70616548)) {
    *(undefined8 *)(puVar17 + -8) = 0x180017450;
    (*g_pfnFree)(pWVar8 + -4);
  }
  pWVar8 = local_40;
  if (local_40 != (LPCWSTR)0x0) {
    uVar9 = *(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30);
    *(undefined8 *)(puVar17 + -8) = 0x180017472;
    RtlFreeHeap(uVar9,0,pWVar8);
  }
  if (NVar12 != 0) {
    *(undefined8 *)(puVar17 + -8) = 0x180017484;
    DereferenceProvider(NVar12);
  }
  *(undefined8 *)(puVar17 + -8) = 0x18001748b;
  uVar4 = NormalizeNteStatus(DVar14);
  *(undefined8 *)(puVar17 + -8) = 0x180017497;
  return uVar4;
}



===== NCryptSignHash @ 180017c90 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

SECURITY_STATUS __stdcall
NCryptSignHash(NCRYPT_KEY_HANDLE hKey,void *pPaddingInfo,PBYTE pbHashValue,DWORD cbHashValue,
              PBYTE pbSignature,DWORD cbSignature,DWORD *pcbResult,DWORD dwFlags)

{
  longlong lVar1;
  int *piVar2;
  uint uVar3;
  longlong lVar4;
  longlong lVar5;
  int *piVar6;
  wchar_t *pwVar7;
  wchar_t *pwVar8;
  ulonglong uVar9;
  int iVar10;
  undefined1 auStackY_148 [32];
  undefined1 uVar11;
  undefined1 uVar12;
  DWORD local_f8 [2];
  DWORD *local_f0;
  int *local_e8;
  PBYTE local_e0;
  _EVENT_DATA_DESCRIPTOR local_d8;
  DWORD *local_c8;
  undefined8 local_c0;
  wchar_t *local_b8;
  int local_b0;
  undefined4 local_ac;
  wchar_t *local_a8;
  int local_a0;
  undefined4 local_9c;
  wchar_t *local_98;
  undefined8 local_90;
  wchar_t *local_88;
  undefined8 local_80;
  DWORD **local_78;
  undefined8 local_70;
  wchar_t *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  ulonglong local_58;
  
                    /* 0x17c90  100  NCryptSignHash */
  local_58 = __security_cookie ^ (ulonglong)auStackY_148;
  local_f0 = pcbResult;
  iVar10 = 0;
  piVar6 = pPaddingInfo;
  pwVar8 = (wchar_t *)pbHashValue;
  local_f8[0] = cbHashValue;
  local_e8 = (int *)hKey;
  local_e0 = pbHashValue;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    piVar6 = (int *)0x1d;
    WPP_SF_PD(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x1d,pbHashValue,hKey,(char)dwFlags);
    pwVar8 = (wchar_t *)pbHashValue;
  }
  piVar2 = local_e8;
  if ((local_e8 == (int *)0x0) || (*local_e8 != 0x44440002)) {
    uVar3 = 0x80090026;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      uVar12 = 0x4d;
      uVar11 = 0x26;
      uVar3 = 0x80090026;
LAB_180017ff3:
      WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),piVar6,pwVar8,"Status",uVar11,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",uVar12);
    }
  }
  else {
    uVar3 = Feature_CNG_NCRYPT_PRIVATE_TLS_CLIENT_AUTH__private_IsEnabledDeviceUsageNoInline();
    if ((uVar3 != 0) && ((dwFlags >> 0x17 & 1) != 0)) {
      dwFlags = dwFlags & 0xff7fffff;
      iVar10 = 3;
    }
    do {
      piVar6 = *(int **)(piVar2 + 4);
      pwVar8 = pPaddingInfo;
      uVar3 = (**(code **)(*(longlong *)(piVar2 + 2) + 0xb0))
                        (*(undefined8 *)(*(longlong *)(piVar2 + 2) + 0x110));
      if (uVar3 != 0x8009002e) {
        if (uVar3 == 0) {
          if ((pbSignature != (PBYTE)0x0) && (cbSignature != 0)) {
            CertInUseLog(iVar10,(undefined8 *)(piVar2 + 10),&local_e8);
          }
          uVar3 = 0;
          goto LAB_180018003;
        }
        break;
      }
      if ((dwFlags & 0x40) != 0) {
        uVar3 = 0x80090022;
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_180018003;
        uVar12 = 0x73;
        uVar11 = 0x22;
        uVar3 = 0x80090022;
        goto LAB_180017ff3;
      }
      pwVar8 = L"NCryptSignHash";
      piVar6 = local_e8;
      uVar3 = (**(code **)(*(longlong *)(piVar2 + 2) + 0xc0))
                        (*(undefined8 *)(*(longlong *)(piVar2 + 2) + 0x110));
    } while (uVar3 == 0);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),piVar6,pwVar8,"Status",(char)uVar3,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",0x85);
    }
    pwVar8 = *(wchar_t **)(piVar2 + 6);
    pwVar7 = *(wchar_t **)(*(longlong *)(piVar2 + 2) + 0x118);
    if ((Microsoft_Windows_Crypto_NCryptEnableBits & 1) != 0) {
      local_68 = I_GetProcessName();
      local_f0 = (DWORD *)CONCAT44(local_f0._4_4_,uVar3);
      local_f8[0] = 6;
      local_c0 = 4;
      local_c8 = local_f8;
      lVar5 = -1;
      uVar9 = 10;
      if (pwVar7 == (wchar_t *)0x0) {
        local_b0 = 10;
        pwVar7 = L"NULL";
      }
      else {
        lVar4 = -1;
        do {
          lVar1 = lVar4 + 1;
          lVar4 = lVar4 + 1;
        } while (pwVar7[lVar1] != L'\0');
        local_b0 = (int)lVar4 * 2 + 2;
      }
      local_ac = 0;
      if (pwVar8 == (wchar_t *)0x0) {
        local_a0 = 10;
        pwVar8 = L"NULL";
      }
      else {
        lVar4 = -1;
        do {
          lVar1 = lVar4 + 1;
          lVar4 = lVar4 + 1;
        } while (pwVar8[lVar1] != L'\0');
        local_a0 = (int)lVar4 * 2 + 2;
      }
      local_98 = L"";
      local_88 = L"";
      local_78 = &local_f0;
      local_9c = 0;
      local_90 = 2;
      local_80 = 2;
      local_70 = 4;
      if (local_68 == (wchar_t *)0x0) {
        local_68 = L"NULL";
      }
      else {
        do {
          lVar4 = lVar5 + 1;
          lVar5 = lVar5 + 1;
        } while (local_68[lVar4] != L'\0');
        uVar9 = (ulonglong)((int)lVar5 * 2 + 2);
      }
      local_5c = 0;
      local_60 = (undefined4)uVar9;
      local_b8 = pwVar7;
      local_a8 = pwVar8;
      McGenEventWrite_EventWriteTransfer
                (lVar5,(PCEVENT_DESCRIPTOR)&ETW_LOG_NCRYPT_OPERATION_FAILED,uVar9,8,&local_d8);
    }
  }
LAB_180018003:
  uVar3 = NormalizeNteStatus(uVar3);
  return uVar3;
}



===== NCryptOpenKeyProtector @ 180018040 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

NTSTATUS NCryptOpenKeyProtector(undefined8 *param_1,LPCWSTR param_2,undefined4 param_3)

{
  uint uVar1;
  NTSTATUS NVar2;
  longlong lVar3;
  int *_Dst;
  undefined1 uVar4;
  LPCWSTR pWVar5;
  char *pcVar6;
  char *pcVar7;
  undefined1 uVar8;
  ULONG local_res20 [2];
  PCRYPT_PROVIDER_REFS local_1c8 [2];
  undefined8 local_1b8;
  undefined8 uStack_1b0;
  int local_1a8;
  int iStack_1a4;
  int iStack_1a0;
  int iStack_19c;
  undefined8 local_198;
  
                    /* 0x18040  91  NCryptOpenKeyProtector */
  local_1c8[0] = (PCRYPT_PROVIDER_REFS)0x0;
  local_res20[0] = 0;
  _Dst = (int *)0x0;
  memset(&local_1b8,0,0x188);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    WPP_SF_qSD(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),10,
               &WPP_6d353d9995a633fdfdb515b4bb0c31fa_Traceguids,param_1,param_2,(char)param_3);
  }
  uVar1 = Feature_690454842__private_IsEnabledDeviceUsageNoInline();
  if (uVar1 == 0) {
    if (((param_1 == (undefined8 *)0x0) || (param_2 == (LPCWSTR)0x0)) || (*param_2 == L'\0')) {
      NVar2 = -0x7ff6ffd9;
      uVar4 = 0x80;
LAB_18001829a:
      pcVar6 = "Status";
      pcVar7 = "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\router.c";
      DebugTraceError((char)NVar2,"Status",
                      "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\router.c",
                      uVar4);
      if (_Dst != (int *)0x0) {
        NCryptCloseKeyProtector(_Dst,pcVar6,pcVar7);
      }
      goto LAB_1800182ba;
    }
    *param_1 = 0;
LAB_180018131:
    NVar2 = BCryptResolveProviders((LPCWSTR)0x0,0,param_2,(LPCWSTR)0x0,1,0,local_res20,local_1c8);
    if (NVar2 == 0) {
      if ((*local_1c8[0]->rgpProviders)->dwInterface == 0x10004) {
        lVar3 = -1;
        do {
          lVar3 = lVar3 + 1;
        } while (param_2[lVar3] != L'\0');
        _Dst = (int *)MSCryptAlloc(lVar3 * 2 + 0x4a);
        if (_Dst != (int *)0x0) {
          memset(_Dst,0,0x48);
          *_Dst = 0x48;
          *(int **)(_Dst + 0x10) = _Dst + 0x12;
          _Dst[1] = 1;
          pWVar5 = param_2;
          memcpy(_Dst + 0x12,param_2,lVar3 * 2 + 2);
          NVar2 = LoadProviderEx(&(*local_1c8[0]->rgpProviders)->dwInterface,pWVar5,0,
                                 (undefined8 *)(_Dst + 2),&local_1b8);
          if (NVar2 == 0) {
            *(undefined8 *)(_Dst + 4) = local_1b8;
            *(undefined8 *)(_Dst + 6) = uStack_1b0;
            _Dst[8] = local_1a8;
            _Dst[9] = iStack_1a4;
            _Dst[10] = iStack_1a0;
            _Dst[0xb] = iStack_19c;
            *(undefined8 *)(_Dst + 0xc) = local_198;
            NVar2 = (**(code **)(_Dst + 6))(_Dst + 0xe,param_2,param_3);
            if (NVar2 == 0) {
              *param_1 = _Dst;
              NVar2 = 0;
              goto LAB_1800182ba;
            }
            uVar4 = 0xda;
          }
          else {
            uVar4 = 0xc9;
          }
          goto LAB_18001829a;
        }
        NVar2 = -0x7ff6fff2;
        uVar8 = 0xb0;
        uVar4 = 0xe;
      }
      else {
        NVar2 = -0x3ffffff8;
        uVar8 = 0xa1;
        uVar4 = 8;
      }
    }
    else {
      uVar8 = 0x97;
      uVar4 = (undefined1)NVar2;
    }
  }
  else {
    if (param_1 == (undefined8 *)0x0) {
      uVar8 = 0x69;
    }
    else {
      *param_1 = 0;
      if ((param_2 != (LPCWSTR)0x0) && (*param_2 != L'\0')) goto LAB_180018131;
      uVar8 = 0x74;
    }
    NVar2 = -0x7ff6ffd9;
    uVar4 = 0x27;
  }
  DebugTraceError(uVar4,"Status",
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\router.c",uVar8
                 );
LAB_1800182ba:
  if (local_1c8[0] != (PCRYPT_PROVIDER_REFS)0x0) {
    BCryptFreeBuffer(local_1c8[0]);
  }
  return NVar2;
}



===== I_GetContentEncryptKey @ 1800182f8 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

int I_GetContentEncryptKey
              (longlong param_1,uint param_2,undefined *param_3,undefined8 param_4,
              undefined8 *param_5,uint *param_6)

{
  uint *puVar1;
  longlong lVar2;
  longlong *plVar3;
  int iVar4;
  int *piVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  int iVar8;
  undefined1 *puVar9;
  longlong lVar10;
  undefined1 uVar11;
  longlong *plVar12;
  uint uVar13;
  ulonglong uVar14;
  uint local_res8 [2];
  uint local_res10;
  undefined1 *local_50;
  longlong local_48;
  
  iVar4 = 0;
  local_res8[0] = 0;
  puVar1 = *(uint **)(param_1 + 8);
  puVar9 = (undefined1 *)0x0;
  local_50 = (undefined1 *)0x0;
  *param_5 = 0;
  uVar7 = 0xffffffff;
  uVar14 = 0;
  local_48 = *(longlong *)(param_1 + 0x20);
  *param_6 = 0;
  local_res10 = param_2;
  if (*puVar1 != 0) {
    plVar12 = (longlong *)(local_48 + 0x30);
    iVar4 = 0;
    do {
      iVar8 = (int)uVar7;
      lVar10 = uVar14 * 0x20;
      if (*(int *)(lVar10 + *(longlong *)(puVar1 + 2)) == 0) {
        iVar4 = -0x7ff6ffd9;
        goto LAB_1800184a3;
      }
      plVar12 = (longlong *)(local_48 + 0x30);
      uVar6 = (ulonglong)*(uint *)(lVar10 + 0x10 + *(longlong *)(puVar1 + 2));
      lVar2 = *plVar12;
      piVar5 = (int *)(uVar6 * 0xa0 + lVar2);
      if (*(uint *)(lVar10 + *(longlong *)(puVar1 + 2)) < 2) {
        if ((((*piVar5 != 5) || (*(int *)(uVar6 * 0xa0 + 8 + lVar2) != 0xc)) ||
            (plVar3 = *(longlong **)(uVar6 * 0xa0 + 0x10 + lVar2), *plVar3 != -0x7dfefbfef9d4f5fa))
           || ((int)plVar3[1] != 0x9014a37)) {
          iVar4 = NCryptUnprotectKey(*(int **)(*(longlong *)(lVar10 + 8 + *(longlong *)(puVar1 + 2))
                                              + 0x10),(int *)(uVar6 * 0xa0 + lVar2),param_3,param_4,
                                     &local_50,local_res8,local_res10);
          goto LAB_18001843f;
        }
        uVar7 = uVar14;
      }
      else {
        uVar6 = I_UnprotectCombinerRecipientKey
                          (param_1,uVar14,piVar5,param_3,param_4,&local_50,local_res8);
        iVar4 = (int)uVar6;
LAB_18001843f:
        puVar9 = local_50;
        if (iVar4 == 0) goto LAB_18001848f;
        if (local_50 != (undefined1 *)0x0) {
          for (uVar6 = (ulonglong)local_res8[0]; uVar6 != 0; uVar6 = uVar6 - 1) {
            *puVar9 = 0;
            puVar9 = puVar9 + 1;
          }
          (**(code **)(param_3 + 0x10))(local_50);
          local_50 = (undefined1 *)0x0;
          puVar9 = local_50;
        }
      }
      iVar8 = (int)uVar7;
      uVar13 = (int)uVar14 + 1;
      uVar14 = (ulonglong)uVar13;
    } while (uVar13 < *puVar1);
    if (iVar4 == 0) {
LAB_18001848f:
      plVar12 = (longlong *)(local_48 + 0x30);
      if (puVar9 != (undefined1 *)0x0) goto LAB_180018508;
    }
LAB_1800184a3:
    uVar13 = local_res10;
    if (-1 < iVar8) {
      iVar4 = NCryptUnprotectKey(*(int **)(*(longlong *)
                                            ((longlong)iVar8 * 0x20 + 8 + *(longlong *)(puVar1 + 2))
                                          + 0x10),
                                 (int *)((ulonglong)
                                         *(uint *)((longlong)iVar8 * 0x20 + 0x10 +
                                                  *(longlong *)(puVar1 + 2)) * 0xa0 + *plVar12),
                                 param_3,param_4,&local_50,local_res8,local_res10);
      if (iVar4 == 0) {
        iVar4 = 0;
        puVar9 = local_50;
LAB_180018508:
        *param_5 = puVar9;
        *param_6 = local_res8[0];
        return iVar4;
      }
      uVar11 = 0x52;
      goto LAB_180018528;
    }
  }
  uVar11 = 0x62;
  uVar13 = local_res10;
LAB_180018528:
  if ((uVar13 & 0x80) == 0) {
    iVar4 = -0x7ff6ffd4;
  }
  DebugTraceError((char)iVar4,"Status",
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\ncryptprotect.c"
                  ,uVar11);
  if (local_50 != (undefined1 *)0x0) {
    puVar9 = local_50;
    for (uVar7 = (ulonglong)local_res8[0]; uVar7 != 0; uVar7 = uVar7 - 1) {
      *puVar9 = 0;
      puVar9 = puVar9 + 1;
    }
    (**(code **)(param_3 + 0x10))(local_50);
  }
  return iVar4;
}



===== _LoadInterface @ 180018584 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

ulonglong _LoadInterface(HMODULE param_1,uint *param_2,undefined8 param_3,undefined8 *param_4)

{
  uint uVar1;
  int iVar2;
  FARPROC pFVar3;
  undefined1 uVar4;
  char *lpProcName;
  ulonglong uVar5;
  ulonglong uVar6;
  undefined1 uVar7;
  
  uVar1 = *param_2;
  if (uVar1 < 7) {
    if (uVar1 == 6) {
      lpProcName = "GetRngInterface";
    }
    else if (uVar1 == 1) {
      lpProcName = "GetCipherInterface";
    }
    else if (uVar1 == 2) {
      lpProcName = "GetHashInterface";
    }
    else if (uVar1 == 3) {
      lpProcName = "GetAsymmetricEncryptionInterface";
    }
    else if (uVar1 == 4) {
      lpProcName = "GetSecretAgreementInterface";
    }
    else {
      if (uVar1 != 5) goto LAB_18001861c;
      lpProcName = "GetSignatureInterface";
    }
  }
  else if (uVar1 == 7) {
    lpProcName = "GetKeyDerivationInterface";
  }
  else if (uVar1 == 8) {
    lpProcName = "GetKeyEncapsulationInterface";
  }
  else if (uVar1 == 0x10001) {
    lpProcName = "GetKeyStorageInterface";
  }
  else if (uVar1 == 0x10002) {
    lpProcName = "GetSChannelInterface";
  }
  else {
    if (uVar1 != 0x10004) {
LAB_18001861c:
      uVar5 = 0xc00000bb;
      uVar4 = 0x68;
      uVar7 = 0xbb;
      goto LAB_18001882e;
    }
    lpProcName = "GetKeyProtectionInterface";
  }
  pFVar3 = GetProcAddress(param_1,lpProcName);
  if (pFVar3 == (FARPROC)0x0) {
    uVar5 = 0xc0000139;
    uVar4 = 0x73;
    uVar7 = 0x39;
    goto LAB_18001882e;
  }
  uVar1 = *param_2;
  if (uVar1 < 7) {
    if (uVar1 == 6) {
      uVar5 = (*pFVar3)(*(undefined8 *)(param_2 + 4),param_4,0);
      iVar2 = (int)uVar5;
      uVar6 = uVar5 & 0xffffffff;
      uVar5 = uVar5 & 0xffffffff;
      if (iVar2 < 0) {
        uVar7 = 10;
        goto LAB_1800186f9;
      }
    }
    else if (uVar1 == 1) {
      uVar5 = (*pFVar3)(*(undefined8 *)(param_2 + 4),*(undefined8 *)(param_2 + 2),param_4,0);
      iVar2 = (int)uVar5;
      uVar6 = uVar5 & 0xffffffff;
      uVar5 = uVar5 & 0xffffffff;
      if (iVar2 < 0) {
        uVar7 = 0xca;
        goto LAB_1800186f9;
      }
    }
    else if (uVar1 == 2) {
      uVar5 = (*pFVar3)(*(undefined8 *)(param_2 + 4),*(undefined8 *)(param_2 + 2),param_4,0);
      iVar2 = (int)uVar5;
      uVar6 = uVar5 & 0xffffffff;
      uVar5 = uVar5 & 0xffffffff;
      if (iVar2 < 0) {
        uVar7 = 0xd7;
        goto LAB_1800186f9;
      }
    }
    else if (uVar1 == 3) {
      uVar5 = (*pFVar3)(*(undefined8 *)(param_2 + 4),*(undefined8 *)(param_2 + 2),param_4,0);
      iVar2 = (int)uVar5;
      uVar6 = uVar5 & 0xffffffff;
      uVar5 = uVar5 & 0xffffffff;
      if (iVar2 < 0) {
        uVar7 = 0xe4;
        goto LAB_1800186f9;
      }
    }
    else if (uVar1 == 4) {
      uVar5 = (*pFVar3)(*(undefined8 *)(param_2 + 4),*(undefined8 *)(param_2 + 2),param_4,0);
      iVar2 = (int)uVar5;
      uVar6 = uVar5 & 0xffffffff;
      uVar5 = uVar5 & 0xffffffff;
      if (iVar2 < 0) {
        uVar7 = 0xf1;
        goto LAB_1800186f9;
      }
    }
    else {
      if (uVar1 != 5) goto LAB_180018802;
      uVar5 = (*pFVar3)(*(undefined8 *)(param_2 + 4),*(undefined8 *)(param_2 + 2),param_4,0);
      iVar2 = (int)uVar5;
      uVar6 = uVar5 & 0xffffffff;
      uVar5 = uVar5 & 0xffffffff;
      if (iVar2 < 0) {
        uVar7 = 0xfe;
        goto LAB_1800186f9;
      }
    }
LAB_180018921:
    uVar5 = uVar6;
    uVar6 = uVar5;
    if (-1 < (int)uVar5) {
      uVar1 = *param_2;
      uVar5 = 0;
      if (uVar1 < 7) {
        if (uVar1 == 6) {
          if (*(short *)*param_4 == 0) {
            uVar7 = 0x72;
LAB_1800189c8:
            uVar5 = 0xc00000bb;
            DebugTraceError(0xbb,"ntStatus",
                            "onecore\\ds\\security\\cryptoapi\\ncrypt\\loader\\loader.c",uVar7);
          }
        }
        else if (uVar1 == 1) {
          if (*(short *)*param_4 == 0) {
            uVar7 = 0x40;
            goto LAB_1800189c8;
          }
        }
        else if (uVar1 == 2) {
          if (*(short *)*param_4 == 0) {
            uVar7 = 0x4a;
            goto LAB_1800189c8;
          }
        }
        else if (uVar1 == 3) {
          if (*(short *)*param_4 == 0) {
            uVar7 = 0x54;
            goto LAB_1800189c8;
          }
        }
        else if (uVar1 == 4) {
          if (*(short *)*param_4 == 0) {
            uVar7 = 0x5e;
            goto LAB_1800189c8;
          }
        }
        else {
          if (uVar1 != 5) goto LAB_180018a2e;
          if (*(short *)*param_4 == 0) {
            uVar7 = 0x68;
            goto LAB_1800189c8;
          }
        }
LAB_1800189e1:
        if (-1 < (int)uVar5) {
          return uVar5;
        }
      }
      else {
        if (uVar1 != 7) {
          if (uVar1 == 8) {
            if (*(short *)*param_4 == 0) {
              uVar7 = 0x86;
              goto LAB_1800189c8;
            }
          }
          else if (uVar1 == 0x10001) {
            if (*(short *)*param_4 == 0) {
              uVar7 = 0x90;
              goto LAB_1800189c8;
            }
          }
          else if (uVar1 == 0x10002) {
            if (*(short *)*param_4 == 0) {
              uVar7 = 0xa4;
              goto LAB_1800189c8;
            }
          }
          else {
            if (uVar1 != 0x10004) {
LAB_180018a2e:
              uVar7 = 0xaa;
              goto LAB_180018a34;
            }
            if (*(short *)*param_4 == 0) {
              uVar7 = 0x9a;
              goto LAB_1800189c8;
            }
          }
          goto LAB_1800189e1;
        }
        if (*(short *)*param_4 != 0) goto LAB_1800189e1;
        uVar7 = 0x7c;
LAB_180018a34:
        uVar5 = 0xc00000bb;
        DebugTraceError(0xbb,"ntStatus","onecore\\ds\\security\\cryptoapi\\ncrypt\\loader\\loader.c"
                        ,uVar7);
      }
      uVar7 = (undefined1)uVar5;
      uVar4 = 0x82;
      goto LAB_18001882e;
    }
  }
  else {
    if (uVar1 != 7) {
      if (uVar1 == 8) {
        uVar5 = (*pFVar3)(*(undefined8 *)(param_2 + 4),*(undefined8 *)(param_2 + 2),param_4,0);
        iVar2 = (int)uVar5;
        uVar6 = uVar5 & 0xffffffff;
        uVar5 = uVar5 & 0xffffffff;
        if (iVar2 < 0) {
          uVar7 = 0x24;
          goto LAB_1800186f9;
        }
      }
      else if (uVar1 == 0x10001) {
        uVar5 = (*pFVar3)(*(undefined8 *)(param_2 + 4),param_4,0);
        iVar2 = (int)uVar5;
        uVar6 = uVar5 & 0xffffffff;
        uVar5 = uVar5 & 0xffffffff;
        if (iVar2 < 0) {
          uVar7 = 0x30;
          goto LAB_1800186f9;
        }
      }
      else if (uVar1 == 0x10002) {
        uVar5 = (*pFVar3)(*(undefined8 *)(param_2 + 4),param_4,0);
        iVar2 = (int)uVar5;
        uVar6 = uVar5 & 0xffffffff;
        uVar5 = uVar5 & 0xffffffff;
        if (iVar2 < 0) {
          uVar7 = 0x48;
          goto LAB_1800186f9;
        }
      }
      else {
        if (uVar1 != 0x10004) {
LAB_180018802:
          uVar5 = 0xc00000bb;
          uVar7 = 0x4e;
          uVar6 = 0xc00000bb;
          uVar4 = 0xbb;
          goto LAB_180018814;
        }
        uVar5 = (*pFVar3)(*(undefined8 *)(param_2 + 4),param_4,0);
        iVar2 = (int)uVar5;
        uVar6 = uVar5 & 0xffffffff;
        uVar5 = uVar5 & 0xffffffff;
        if (iVar2 < 0) {
          uVar7 = 0x3c;
          goto LAB_1800186f9;
        }
      }
      goto LAB_180018921;
    }
    uVar5 = (*pFVar3)(*(undefined8 *)(param_2 + 4),*(undefined8 *)(param_2 + 2),param_4,0);
    iVar2 = (int)uVar5;
    uVar6 = uVar5 & 0xffffffff;
    uVar5 = uVar5 & 0xffffffff;
    if (-1 < iVar2) goto LAB_180018921;
    uVar7 = 0x17;
LAB_1800186f9:
    uVar4 = (undefined1)iVar2;
LAB_180018814:
    DebugTraceError(uVar4,"ntStatus","onecore\\ds\\security\\cryptoapi\\ncrypt\\loader\\loader.c",
                    uVar7);
  }
  uVar7 = (undefined1)uVar6;
  uVar4 = 0x87;
LAB_18001882e:
  DebugTraceError(uVar7,"sResult","onecore\\ds\\security\\cryptoapi\\ncrypt\\loader\\loader.c",uVar4
                 );
  return uVar5;
}



===== wil_details_IsEnabledFallback @ 180018ae0 =====

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



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 180018b74 =====

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
    do {
      if ((uVar3 & 2) == 0) {
        return;
      }
      if (((uVar3 ^ param_1) & 1) != 0) {
        return;
      }
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
    } while (!bVar5);
  }
  else {
    LOCK();
    *puVar2 = *puVar2 | uVar4;
    UNLOCK();
  }
  return;
}



===== Feature_PKCS11_Shielded_Secrets__private_ReportDeviceUsage @ 180018bd0 =====

void Feature_PKCS11_Shielded_Secrets__private_ReportDeviceUsage(void)

{
  uint uVar1;
  ulonglong local_res8;
  
  if ((Feature_PKCS11_Shielded_Secrets__private_featureState & 0x10) == 0) {
    uVar1 = Feature_PKCS11_Shielded_Secrets__private_featureState | 1;
    local_res8 = (ulonglong)uVar1;
    wil_details_FeatureReporting_ReportUsageToService(0x180023590,local_res8,3);
    wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath
              (uVar1,3,&Feature_PKCS11_Shielded_Secrets__private_descriptor);
  }
  return;
}



===== Feature_Key_Guard_Attestation__private_ReportDeviceUsage @ 180018c34 =====

void Feature_Key_Guard_Attestation__private_ReportDeviceUsage(void)

{
  uint uVar1;
  ulonglong local_res8;
  
  if ((Feature_Key_Guard_Attestation__private_featureState & 0x10) == 0) {
    uVar1 = Feature_Key_Guard_Attestation__private_featureState | 1;
    local_res8 = (ulonglong)uVar1;
    wil_details_FeatureReporting_ReportUsageToService(0x1800235c8,local_res8,3);
    wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath
              (uVar1,3,&Feature_Key_Guard_Attestation__private_descriptor);
  }
  return;
}



===== StringCchLengthW @ 180018c98 =====

HRESULT __stdcall StringCchLengthW(STRSAFE_PCNZWCH psz,size_t cchMax,size_t *pcchLength)

{
  HRESULT HVar1;
  
  if (psz == (STRSAFE_PCNZWCH)0x0) {
    HVar1 = -0x7ff8ffa9;
  }
  else {
    HVar1 = StringLengthWorkerW(psz,0x7fffffff,pcchLength);
    if (-1 < HVar1) {
      return HVar1;
    }
  }
  if (pcchLength != (size_t *)0x0) {
    *pcchLength = 0;
  }
  return HVar1;
}



===== StringLengthWorkerW @ 180018ccc =====

HRESULT __stdcall StringLengthWorkerW(STRSAFE_PCNZWCH psz,size_t cchMax,size_t *pcchLength)

{
  uint uVar1;
  size_t sVar2;
  
  sVar2 = cchMax;
  for (; (sVar2 != 0 && (*psz != L'\0')); psz = psz + 1) {
    sVar2 = sVar2 - 1;
  }
  uVar1 = ~-(uint)(sVar2 != 0) & 0x80070057;
  if (pcchLength != (size_t *)0x0) {
    if (sVar2 != 0) {
      *pcchLength = cchMax - sVar2;
      return uVar1;
    }
    *pcchLength = 0;
  }
  return uVar1;
}



===== EtwLogNCryptOpenKeyFailed @ 180018d14 =====

undefined8 EtwLogNCryptOpenKeyFailed(wchar_t *param_1,wchar_t *param_2,undefined1 param_3)

{
  wchar_t *pwVar1;
  undefined8 uVar2;
  wchar_t *pwVar3;
  wchar_t *pwVar4;
  
  if ((Microsoft_Windows_Crypto_NCryptEnableBits & 1) == 0) {
    uVar2 = 0;
  }
  else {
    pwVar3 = param_1;
    pwVar4 = param_2;
    pwVar1 = I_GetProcessName();
    uVar2 = McTemplateU0zzdz_EventWriteTransfer(pwVar3,pwVar4,param_1,param_2,param_3,pwVar1);
  }
  return uVar2;
}



===== SslEnumCipherSuites @ 180018d70 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void SslEnumCipherSuites(uint *param_1,uint *param_2,undefined8 *param_3,longlong *param_4,
                        undefined4 param_5)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  undefined1 uVar6;
  undefined8 uVar7;
  undefined1 uVar8;
  longlong *plVar9;
  
                    /* 0x18d70  125  SslEnumCipherSuites */
  puVar3 = (uint *)0x0;
  puVar4 = (undefined8 *)0x0;
  plVar9 = param_4;
  puVar2 = ValidateSslProvHandle(param_1);
  if (puVar2 == (uint *)0x0) {
    uVar1 = 0x80090026;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),param_2,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c","Status",0x26,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",0x9c);
    }
    goto LAB_180018f67;
  }
  if (param_2 == (uint *)0x0) {
LAB_180018e20:
    if ((param_3 != (undefined8 *)0x0) && (param_4 != (longlong *)0x0)) {
      if (*plVar9 == 0) {
        puVar4 = (undefined8 *)MSCryptAlloc(0x20);
        if (puVar4 == (undefined8 *)0x0) {
          uVar1 = 0x8009000e;
          uVar8 = 0xbf;
          uVar6 = 0xe;
          goto LAB_180018f54;
        }
        *puVar4 = 0;
        puVar4[1] = 0;
        puVar4[2] = 0;
        puVar4[3] = 0;
      }
      puVar5 = (undefined8 *)MSCryptAlloc(0x20);
      if (puVar5 == (undefined8 *)0x0) {
        uVar1 = 0x8009000e;
        uVar6 = 0xe;
        uVar8 = 0xcf;
      }
      else {
        *puVar5 = 0;
        puVar5[1] = 0;
        puVar5[2] = 0;
        puVar5[3] = 0;
        if (puVar3 == (uint *)0x0) {
          uVar7 = 0;
        }
        else {
          uVar7 = *(undefined8 *)(puVar3 + 4);
        }
        uVar1 = (**(code **)(puVar2 + 0x18))
                          (*(undefined8 *)(puVar2 + 0x6a),uVar7,param_3,param_4,param_5);
        uVar6 = (undefined1)uVar1;
        if (-1 < (int)uVar1) {
          if (puVar4 != (undefined8 *)0x0) {
            LOCK();
            puVar2[4] = puVar2[4] + 1;
            UNLOCK();
            *puVar4 = puVar2;
            puVar4[1] = *param_4;
            MSCryptAddMemoryBuffer(0x1800278a0,(longlong)puVar4);
          }
          LOCK();
          puVar2[4] = puVar2[4] + 1;
          UNLOCK();
          *puVar5 = puVar2;
          puVar5[1] = *param_3;
          MSCryptAddMemoryBuffer(0x1800278a0,(longlong)puVar5);
          uVar1 = 0;
          goto LAB_180018f67;
        }
        uVar8 = 0xe1;
      }
      DebugTraceError(uVar6,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",
                      uVar8);
      if (puVar4 != (undefined8 *)0x0) {
        SafeAllocaFreeToHeap(puVar4);
      }
      if (puVar5 != (undefined8 *)0x0) {
        SafeAllocaFreeToHeap(puVar5);
      }
      goto LAB_180018f67;
    }
    uVar1 = 0x80090027;
    uVar8 = 0xae;
    uVar6 = 0x27;
  }
  else {
    puVar3 = ValidateSslKeyHandle(param_2);
    if (puVar3 != (uint *)0x0) goto LAB_180018e20;
    uVar1 = 0x80090026;
    uVar8 = 0xa6;
    uVar6 = 0x26;
  }
LAB_180018f54:
  DebugTraceError(uVar6,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",uVar8)
  ;
LAB_180018f67:
  NormalizeNteStatus(uVar1);
  return;
}



===== I_GetRecipientIdString @ 180018f8c =====

HRESULT I_GetRecipientIdString(int *param_1,ulonglong param_2,undefined8 *param_3)

{
  wchar_t *pwVar1;
  HRESULT HVar2;
  STRSAFE_LPWSTR pszDest;
  undefined8 uVar3;
  longlong lVar4;
  size_t cchDest;
  undefined1 uVar5;
  uint uVar6;
  int iVar7;
  size_t local_res8;
  ulonglong local_res10;
  wchar_t *local_res18 [2];
  
  *param_3 = 0;
  local_res10 = param_2;
  if (*param_1 == 2) {
    lVar4 = (ulonglong)(uint)(param_1[2] * 2) + 5;
  }
  else {
    if (*param_1 != 1) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return -0x7ff6ffd7;
      }
      if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
        return -0x7ff6ffd7;
      }
      WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),WPP_GLOBAL_Control,param_3,"Status",
                  0x29,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\descriptor.c",
                  0x87);
      return -0x7ff6ffd7;
    }
    lVar4 = (ulonglong)(uint)(param_1[2] * 2) + (ulonglong)(uint)(param_1[6] * 2) + 0x10;
  }
  cchDest = lVar4 + 8;
  local_res8 = cchDest;
  pszDest = (STRSAFE_LPWSTR)I_DefaultExtrenalAlloc(cchDest * 2);
  if (pszDest == (STRSAFE_LPWSTR)0x0) {
    DebugTraceError(0xe,"Status",
                    "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\descriptor.c"
                    ,0x91);
    return -0x7ff6fff2;
  }
  memset(pszDest,0,cchDest * 2);
  local_res18[0] = pszDest;
  if (*param_1 == 2) {
    HVar2 = StringCchPrintfExW(pszDest,cchDest,local_res18,&local_res8,0,L"%ls:",L"KeyId");
    if (HVar2 < 0) {
      uVar5 = 0xa6;
    }
    else {
      uVar3 = CNG_BinToHex(*(byte **)(param_1 + 4),param_1[2],0,local_res18[0],(uint)local_res8,
                           (int *)&local_res10);
      HVar2 = (HRESULT)uVar3;
      if (-1 < HVar2) {
LAB_1800191ad:
        *param_3 = pszDest;
        return 0;
      }
      uVar5 = 0xb6;
    }
  }
  else {
    HVar2 = StringCchPrintfExW(pszDest,cchDest,local_res18,&local_res8,0,L"%ls:",L"IssuerAndSerial")
    ;
    pwVar1 = local_res18[0];
    if (HVar2 < 0) {
      uVar5 = 199;
    }
    else {
      uVar6 = (uint)local_res8;
      local_res10 = CONCAT44(local_res10._4_4_,uVar6);
      uVar3 = CNG_BinToHex(*(byte **)(param_1 + 4),param_1[2],0,local_res18[0],uVar6,
                           (int *)&local_res10);
      HVar2 = (HRESULT)uVar3;
      if (HVar2 < 0) {
        uVar5 = 0xd7;
      }
      else {
        iVar7 = uVar6 - (int)local_res10;
        if (iVar7 == 0) {
          HVar2 = -0x7ff6fff2;
          uVar5 = 0xe2;
        }
        else {
          pwVar1[local_res10 & 0xffffffff] = L',';
          uVar3 = CNG_BinToHex(*(byte **)(param_1 + 8),param_1[6],1,
                               pwVar1 + (local_res10 & 0xffffffff) + 1,iVar7 - 1,(int *)&local_res10
                              );
          HVar2 = (HRESULT)uVar3;
          if (-1 < HVar2) goto LAB_1800191ad;
          uVar5 = 0xf3;
        }
      }
    }
  }
  DebugTraceError((char)HVar2,"Status",
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\descriptor.c",
                  uVar5);
  I_DefaultExtrenalFree(pszDest);
  return HVar2;
}



===== GetKeyAlgoGroupProp @ 180019218 =====

SECURITY_STATUS GetKeyAlgoGroupProp(NCRYPT_HANDLE param_1,undefined8 *param_2)

{
  SECURITY_STATUS SVar1;
  PBYTE pbOutput;
  DWORD local_res10 [6];
  
  local_res10[0] = 0;
  *param_2 = 0;
  SVar1 = NCryptGetProperty(param_1,L"Algorithm Group",(PBYTE)0x0,0,local_res10,0);
  if (SVar1 == 0) {
    pbOutput = (PBYTE)MSCryptAlloc((ulonglong)local_res10[0]);
    *param_2 = pbOutput;
    if (pbOutput == (PBYTE)0x0) {
      SVar1 = -0x7ff6fff2;
    }
    else {
      SVar1 = NCryptGetProperty(param_1,L"Algorithm Group",pbOutput,local_res10[0],local_res10,0);
    }
  }
  return SVar1;
}



===== OnRegChange_CertInUse @ 1800192b0 =====

void OnRegChange_CertInUse(void)

{
  ReadKey_CertInUse();
  RegNotifyChangeKeyValue(g_CertInUseRegKey,1,0x10000004,g_hCertInUseRegChangeEvent,1);
  if (g_pTpWait != (PTP_WAIT)0x0) {
    SetThreadpoolWait(g_pTpWait,g_hCertInUseRegChangeEvent,(PFILETIME)0x0);
  }
  return;
}



===== _DllMainCRTStartupForGS2 @ 180019318 =====

undefined8 _DllMainCRTStartupForGS2(undefined8 param_1,int param_2)

{
  if (param_2 == 1) {
    __security_init_cookie();
  }
  return 1;
}



===== __report_gsfailure @ 180019340 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  DWORD64 ControlPc;
  PRUNTIME_FUNCTION FunctionEntry;
  DWORD64 unaff_retaddr;
  uintptr_t local_res8 [4];
  ulonglong local_38 [2];
  PVOID local_28;
  undefined8 uStack_20;
  undefined8 uStack_18;
  
  local_38[1] = 0;
  local_28 = (PVOID)0x0;
  local_38[0] = 0;
  local_res8[0] = _StackCookie;
  RtlCaptureContext(&DAT_1800271a0);
  ControlPc = DAT_180027298;
  FunctionEntry = RtlLookupFunctionEntry(DAT_180027298,local_38,(PUNWIND_HISTORY_TABLE)0x0);
  if (FunctionEntry == (PRUNTIME_FUNCTION)0x0) {
    _DAT_180027238 = local_res8;
    DAT_180027298 = unaff_retaddr;
  }
  else {
    RtlVirtualUnwind(0,local_38[0],ControlPc,FunctionEntry,(PCONTEXT)&DAT_1800271a0,&local_28,
                     local_38 + 1,(PKNONVOLATILE_CONTEXT_POINTERS)0x0);
  }
  _DAT_180027110 = DAT_180027298;
  _DAT_180027220 = local_res8[0];
  _DAT_180027100 = 0xc0000409;
  _DAT_180027104 = 1;
  _DAT_180027118 = 1;
  DAT_180027120 = 2;
  uStack_20 = __security_cookie;
  uStack_18 = __security_cookie_complement;
  RtlUnhandledExceptionFilter(&PTR_DAT_18001f1f0);
  NtTerminateProcess(0xffffffffffffffff,0xc0000409);
  return;
}



===== __security_init_cookie @ 1800194bc =====

void __cdecl __security_init_cookie(void)

{
  if ((__security_cookie == 0) || (__security_cookie == 0x2b992ddfa232)) {
    __security_init_cookie_ex(&__security_cookie);
  }
  __security_cookie_complement = ~__security_cookie;
  return;
}



===== __security_init_cookie_ex @ 180019508 =====

void __security_init_cookie_ex(ulonglong *param_1)

{
  ulonglong uVar1;
  undefined8 in_RAX;
  
  uVar1 = rdtsc();
  *param_1 = ((CONCAT44((int)((ulonglong)in_RAX >> 0x20),(int)uVar1) | uVar1 & 0xffffffff00000000)
              >> 4 ^ (ulonglong)param_1) & 0xffffffffffff;
  if ((*param_1 == 0) || (*param_1 == 0x2b992ddfa232)) {
    *param_1 = 0x2b992ddfa233;
  }
  return;
}



===== NtTerminateProcess @ 18001956c =====

void NtTerminateProcess(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018001956c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  NtTerminateProcess();
  return;
}



===== RtlCaptureContext @ 180019578 =====

void RtlCaptureContext(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180019578. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RtlCaptureContext();
  return;
}



===== RtlLookupFunctionEntry @ 180019584 =====

PRUNTIME_FUNCTION __stdcall
RtlLookupFunctionEntry(DWORD64 ControlPc,PDWORD64 ImageBase,PUNWIND_HISTORY_TABLE HistoryTable)

{
  PRUNTIME_FUNCTION p_Var1;
  
                    /* WARNING: Could not recover jumptable at 0x000180019584. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  p_Var1 = RtlLookupFunctionEntry(ControlPc,ImageBase,HistoryTable);
  return p_Var1;
}



===== RtlVirtualUnwind @ 180019590 =====

PEXCEPTION_ROUTINE __stdcall
RtlVirtualUnwind(DWORD HandlerType,DWORD64 ImageBase,DWORD64 ControlPc,
                PRUNTIME_FUNCTION FunctionEntry,PCONTEXT ContextRecord,PVOID *HandlerData,
                PDWORD64 EstablisherFrame,PKNONVOLATILE_CONTEXT_POINTERS ContextPointers)

{
  PEXCEPTION_ROUTINE puVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180019590. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  puVar1 = RtlVirtualUnwind(HandlerType,ImageBase,ControlPc,FunctionEntry,ContextRecord,HandlerData,
                            EstablisherFrame,ContextPointers);
  return puVar1;
}



===== RtlUnhandledExceptionFilter @ 18001959c =====

void RtlUnhandledExceptionFilter(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018001959c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RtlUnhandledExceptionFilter();
  return;
}



===== __tailMerge_bcrypt_dll @ 1800195a2 =====

void __tailMerge_bcrypt_dll
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 in_RAX;
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = (code *)__delayLoadHelper2(&ImgDelayDescr_180023670,in_RAX);
                    /* WARNING: Could not recover jumptable at 0x000180019619. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_BCryptFreeBuffer @ 180019621 =====

void DelayLoad_BCryptFreeBuffer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_bcrypt_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_BCryptResolveProviders @ 180019633 =====

void DelayLoad_BCryptResolveProviders
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_bcrypt_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_BCryptGetProperty @ 180019645 =====

void DelayLoad_BCryptGetProperty
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_bcrypt_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_BCryptOpenAlgorithmProvider @ 180019657 =====

void DelayLoad_BCryptOpenAlgorithmProvider
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_bcrypt_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_BCryptFinishHash @ 180019669 =====

void DelayLoad_BCryptFinishHash
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_bcrypt_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_BCryptCloseAlgorithmProvider @ 18001967b =====

void DelayLoad_BCryptCloseAlgorithmProvider
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_bcrypt_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_BCryptDestroyHash @ 18001968d =====

void DelayLoad_BCryptDestroyHash
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_bcrypt_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_BCryptHashData @ 18001969f =====

void DelayLoad_BCryptHashData
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_bcrypt_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_BCryptCreateHash @ 1800196b1 =====

void DelayLoad_BCryptCreateHash
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_bcrypt_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_BCryptGenRandom @ 1800196c3 =====

void DelayLoad_BCryptGenRandom
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_bcrypt_dll(param_1,param_2,param_3,param_4);
  return;
}



===== __tailMerge_api_ms_win_service_private_l1_1_0_dll @ 1800196cf =====

void __tailMerge_api_ms_win_service_private_l1_1_0_dll
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 in_RAX;
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = (code *)__delayLoadHelper2(&ImgDelayDescr_180023690,in_RAX);
                    /* WARNING: Could not recover jumptable at 0x000180019746. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_I_QueryTagInformation @ 18001974e =====

void DelayLoad_I_QueryTagInformation
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_api_ms_win_service_private_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== __tailMerge_cryptsp_dll @ 18001975a =====

void __tailMerge_cryptsp_dll
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 in_RAX;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 in_RCX;
  undefined8 in_XMM2_Qa;
  
  UNRECOVERED_JUMPTABLE = (code *)__delayLoadHelper2(&ImgDelayDescr_1800236b0,in_RAX);
                    /* WARNING: Could not recover jumptable at 0x0001800197d1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(in_RCX,param_2,in_XMM2_Qa,param_4);
  return;
}



===== DelayLoad_CryptGetProvParam @ 1800197d9 =====

void DelayLoad_CryptGetProvParam
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_cryptsp_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_CryptGetKeyParam @ 1800197eb =====

void DelayLoad_CryptGetKeyParam
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_cryptsp_dll(param_1,param_2,param_3,param_4);
  return;
}



===== __tailMerge_ntasn1_dll @ 1800197f7 =====

void __tailMerge_ntasn1_dll
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 in_RAX;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 in_RCX;
  undefined8 in_XMM2_Qa;
  
  UNRECOVERED_JUMPTABLE = (code *)__delayLoadHelper2(&ImgDelayDescr_1800236d0,in_RAX);
                    /* WARNING: Could not recover jumptable at 0x00018001986e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(in_RCX,param_2,in_XMM2_Qa,param_4);
  return;
}



===== DelayLoad_Ordinal_5 @ 180019876 =====

void DelayLoad_Ordinal_5(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4
                        )

{
  __tailMerge_ntasn1_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_Ordinal_2 @ 180019888 =====

void DelayLoad_Ordinal_2(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4
                        )

{
  __tailMerge_ntasn1_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_Ordinal_4 @ 18001989a =====

void DelayLoad_Ordinal_4(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4
                        )

{
  __tailMerge_ntasn1_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_Ordinal_6 @ 1800198ac =====

void DelayLoad_Ordinal_6(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4
                        )

{
  __tailMerge_ntasn1_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_Ordinal_37 @ 1800198be =====

void DelayLoad_Ordinal_37
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ntasn1_dll(param_1,param_2,param_3,param_4);
  return;
}



===== __C_specific_handler @ 1800198d0 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800198d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== DelayLoad_BCryptHash @ 1800198dc =====

void DelayLoad_BCryptHash
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_bcrypt_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_BCryptDestroyKey @ 1800198ee =====

void DelayLoad_BCryptDestroyKey
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_bcrypt_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_BCryptImportKey @ 180019900 =====

void DelayLoad_BCryptImportKey
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_bcrypt_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_BCryptExportKey @ 180019912 =====

void DelayLoad_BCryptExportKey
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_bcrypt_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_BCryptGenerateSymmetricKey @ 180019924 =====

void DelayLoad_BCryptGenerateSymmetricKey
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_bcrypt_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_BCryptEncrypt @ 180019936 =====

void DelayLoad_BCryptEncrypt
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_bcrypt_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_BCryptDecrypt @ 180019948 =====

void DelayLoad_BCryptDecrypt
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_bcrypt_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_BCryptSetProperty @ 18001995a =====

void DelayLoad_BCryptSetProperty
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_bcrypt_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_Ordinal_3 @ 18001996c =====

void DelayLoad_Ordinal_3(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4
                        )

{
  __tailMerge_ntasn1_dll(param_1,param_2,param_3,param_4);
  return;
}



===== SslChangeNotify @ 180019980 =====

undefined8 SslChangeNotify(void)

{
                    /* 0x19980  111  SslChangeNotify */
  return 0x80090029;
}



===== SslCombineKeys @ 180019990 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void SslCombineKeys(uint *param_1,undefined2 param_2,uint *param_3,uint *param_4,undefined8 *param_5
                   ,undefined4 param_6)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  undefined8 *puVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  
                    /* 0x19990  112  SslCombineKeys */
  puVar5 = (undefined8 *)0x0;
  puVar2 = ValidateSslProvHandle(param_1);
  if (puVar2 == (uint *)0x0) {
    uVar1 = 0x80090026;
    uVar7 = 0x2d;
    uVar6 = 0x26;
  }
  else {
    puVar3 = ValidateSslKeyHandle(param_3);
    puVar4 = ValidateSslKeyHandle(param_4);
    if (((puVar3 == (uint *)0x0) || (puVar4 == (uint *)0x0)) || (param_5 == (undefined8 *)0x0)) {
      uVar1 = 0x80090027;
      uVar6 = 0x27;
      uVar7 = 0x38;
LAB_180019ae4:
      DebugTraceError(uVar6,"status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",
                      uVar7);
      if (puVar5 != (undefined8 *)0x0) {
        SafeAllocaFreeToHeap(puVar5);
      }
      goto LAB_180019b04;
    }
    if ((ushort)puVar2[8] < 8) {
      uVar1 = 0x80090029;
      uVar7 = 0x40;
      uVar6 = 0x29;
    }
    else {
      puVar5 = (undefined8 *)MSCryptAlloc(0x20);
      if (puVar5 != (undefined8 *)0x0) {
        *puVar5 = 0;
        puVar5[1] = 0;
        puVar5[2] = 0;
        puVar5[3] = 0;
        uVar1 = (**(code **)(puVar2 + 0x66))
                          (*(undefined8 *)(puVar2 + 0x6a),param_2,*(undefined8 *)(puVar3 + 4),
                           *(undefined8 *)(puVar4 + 4),puVar5 + 2,param_6);
        if (-1 < (int)uVar1) {
          *(undefined4 *)(puVar5 + 1) = 0;
          *(undefined4 *)puVar5 = 0x20;
          *(undefined4 *)((longlong)puVar5 + 4) = 0x44444442;
          *(undefined4 *)((longlong)puVar5 + 0xc) = 1;
          puVar5[3] = puVar2;
          LOCK();
          puVar2[4] = puVar2[4] + 1;
          UNLOCK();
          *param_5 = puVar5;
          uVar1 = 0;
          goto LAB_180019b04;
        }
        uVar6 = (undefined1)uVar1;
        uVar7 = 0x57;
        goto LAB_180019ae4;
      }
      uVar1 = 0x8009000e;
      uVar7 = 0x48;
      uVar6 = 0xe;
    }
  }
  DebugTraceError(uVar6,"status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",uVar7)
  ;
LAB_180019b04:
  NormalizeNteStatus(uVar1);
  return;
}



===== SslComputeEapKeyBlock @ 180019b30 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void SslComputeEapKeyBlock(uint *param_1,uint *param_2)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  
                    /* 0x19b30  114  SslComputeEapKeyBlock */
  puVar2 = ValidateSslProvHandle(param_1);
  if (puVar2 == (uint *)0x0) {
    uVar5 = 0x24;
LAB_180019b49:
    uVar1 = 0x80090026;
    uVar4 = 0x26;
  }
  else {
    puVar3 = ValidateSslKeyHandle(param_2);
    if (puVar3 == (uint *)0x0) {
      uVar5 = 0x2c;
      goto LAB_180019b49;
    }
    uVar1 = (**(code **)(puVar2 + 0xc))(*(undefined8 *)(puVar2 + 0x6a),*(undefined8 *)(puVar3 + 4));
    if (-1 < (int)uVar1) {
      uVar1 = 0;
      goto LAB_180019bd3;
    }
    uVar5 = 0x3f;
    uVar4 = (undefined1)uVar1;
  }
  DebugTraceError(uVar4,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",uVar5)
  ;
LAB_180019bd3:
  NormalizeNteStatus(uVar1);
  return;
}



===== SslDeriveSessionTicketKey @ 180019bf0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void SslDeriveSessionTicketKey
               (uint *param_1,undefined4 param_2,undefined8 param_3,undefined4 param_4,
               undefined8 param_5,undefined4 param_6,undefined8 *param_7,undefined4 param_8)

{
  uint uVar1;
  uint *puVar2;
  undefined8 *puVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  
                    /* 0x19bf0  122  SslDeriveSessionTicketKey */
  puVar2 = ValidateSslProvHandle(param_1);
  if ((ushort)puVar2[8] < 7) {
    uVar1 = 0x80090029;
    uVar5 = 0x10;
    uVar4 = 0x29;
  }
  else if (param_7 == (undefined8 *)0x0) {
    uVar1 = 0x80090027;
    uVar5 = 0x22;
    uVar4 = 0x27;
  }
  else {
    puVar3 = (undefined8 *)MSCryptAlloc(0x20);
    if (puVar3 != (undefined8 *)0x0) {
      *puVar3 = 0;
      puVar3[1] = 0;
      puVar3[2] = 0;
      puVar3[3] = 0;
      uVar1 = (**(code **)(puVar2 + 0x5e))
                        (*(undefined8 *)(puVar2 + 0x6a),param_2,param_3,param_4,param_5,param_6,
                         puVar3 + 2,param_8);
      if ((int)uVar1 < 0) {
        DebugTraceError((char)uVar1,"Status",
                        "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",0x42);
        SafeAllocaFreeToHeap(puVar3);
      }
      else {
        *(undefined4 *)(puVar3 + 1) = 0;
        *(undefined4 *)puVar3 = 0x20;
        *(undefined4 *)((longlong)puVar3 + 4) = 0x44444442;
        *(undefined4 *)((longlong)puVar3 + 0xc) = 1;
        puVar3[3] = puVar2;
        *param_7 = puVar3;
        LOCK();
        puVar2[4] = puVar2[4] + 1;
        UNLOCK();
        uVar1 = 0;
      }
      goto LAB_180019d31;
    }
    uVar1 = 0x8009000e;
    uVar5 = 0x2e;
    uVar4 = 0xe;
  }
  DebugTraceError(uVar4,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",uVar5)
  ;
LAB_180019d31:
  NormalizeNteStatus(uVar1);
  return;
}



===== SslDuplicateTranscriptHash @ 180019d60 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void SslDuplicateTranscriptHash(uint *param_1,uint *param_2,undefined8 *param_3,int param_4)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  undefined8 *puVar4;
  undefined1 uVar5;
  undefined8 *puVar6;
  undefined1 uVar7;
  
  puVar6 = param_3;
                    /* 0x19d60  123  SslDuplicateTranscriptHash */
  puVar2 = ValidateSslProvHandle(param_1);
  puVar3 = ValidateSslHashHandle(param_2);
  puVar4 = (undefined8 *)0x0;
  if ((puVar2 == (uint *)0x0) || (puVar3 == (uint *)0x0)) {
    uVar1 = 0x80090026;
    uVar5 = 0x26;
    uVar7 = 0x4f;
LAB_180019e8a:
    DebugTraceError(uVar5,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",
                    uVar7);
    if (puVar4 != (undefined8 *)0x0) {
      SafeAllocaFreeToHeap(puVar4);
    }
  }
  else {
    if ((puVar6 == (undefined8 *)0x0) || (param_4 != 0)) {
      uVar1 = 0x80090027;
      uVar7 = 0x56;
      uVar5 = 0x27;
    }
    else if ((ushort)puVar2[8] < 5) {
      uVar1 = 0x80090029;
      uVar7 = 0x61;
      uVar5 = 0x29;
    }
    else {
      puVar4 = (undefined8 *)MSCryptAlloc(0x20);
      if (puVar4 != (undefined8 *)0x0) {
        *puVar4 = 0;
        puVar4[1] = 0;
        puVar4[2] = 0;
        puVar4[3] = 0;
        uVar1 = (**(code **)(puVar2 + 0x56))
                          (*(undefined8 *)(puVar2 + 0x6a),*(undefined8 *)(puVar3 + 4),puVar4 + 2,0);
        if (-1 < (int)uVar1) {
          *(undefined4 *)(puVar4 + 1) = 0;
          *(undefined4 *)puVar4 = 0x20;
          *(undefined4 *)((longlong)puVar4 + 4) = 0x44444443;
          *(undefined4 *)((longlong)puVar4 + 0xc) = 1;
          puVar4[3] = puVar2;
          LOCK();
          puVar2[4] = puVar2[4] + 1;
          UNLOCK();
          *param_3 = puVar4;
          uVar1 = 0;
          goto LAB_180019eaa;
        }
        uVar5 = (undefined1)uVar1;
        uVar7 = 0x81;
        goto LAB_180019e8a;
      }
      uVar1 = 0x8009000e;
      uVar7 = 0x71;
      uVar5 = 0xe;
    }
    DebugTraceError(uVar5,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",
                    uVar7);
  }
LAB_180019eaa:
  NormalizeNteStatus(uVar1);
  return;
}



===== SslEnumGroups @ 180019ed0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

uint SslEnumGroups(uint *param_1,longlong param_2,longlong param_3,int param_4)

{
  uint uVar1;
  uint *puVar2;
  
                    /* 0x19ed0  128  SslEnumGroups */
  puVar2 = ValidateSslProvHandle(param_1);
  if (puVar2 == (uint *)0x0) {
    DebugTraceError(0x26,"NTE_INVALID_HANDLE",
                    "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",0x7f);
    uVar1 = 0x80090026;
  }
  else if ((param_2 == 0) || (param_3 == 0)) {
    DebugTraceError(0x27,"NTE_INVALID_PARAMETER",
                    "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",0x85);
    uVar1 = 0x80090027;
  }
  else if (param_4 == 0) {
    if ((ushort)puVar2[8] < 8) {
      DebugTraceError(0x29,"NTE_NOT_SUPPORTED",
                      "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",0x92);
      uVar1 = 0x80090029;
    }
    else {
      uVar1 = (**(code **)(puVar2 + 0x68))(*(undefined8 *)(puVar2 + 0x6a));
      if ((int)uVar1 < 0) {
        DebugTraceError((char)uVar1,"status",
                        "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",0x9d);
        uVar1 = NormalizeNteStatus(uVar1);
        return uVar1;
      }
      uVar1 = 0;
    }
  }
  else {
    DebugTraceError(9,"NTE_BAD_FLAGS","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",
                    0x8b);
    uVar1 = 0x80090009;
  }
  return uVar1;
}



===== SslExpandNextGenTrafficKey @ 180019ff0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void SslExpandNextGenTrafficKey
               (uint *param_1,uint *param_2,undefined8 *param_3,undefined8 param_4,
               undefined4 param_5)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  undefined8 *puVar4;
  undefined1 uVar5;
  undefined8 *puVar6;
  undefined1 uVar7;
  
  puVar6 = param_3;
                    /* 0x19ff0  132  SslExpandNextGenTrafficKey */
  puVar2 = ValidateSslProvHandle(param_1);
  puVar3 = ValidateSslKeyHandle(param_2);
  puVar4 = (undefined8 *)0x0;
  if ((puVar2 == (uint *)0x0) || (puVar3 == (uint *)0x0)) {
    uVar1 = 0x80090026;
    uVar5 = 0x26;
    uVar7 = 0x35;
LAB_18001a11b:
    DebugTraceError(uVar5,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",
                    uVar7);
    if (puVar4 != (undefined8 *)0x0) {
      SafeAllocaFreeToHeap(puVar4);
    }
  }
  else {
    if (puVar6 == (undefined8 *)0x0) {
      uVar1 = 0x80090027;
      uVar7 = 0x3c;
      uVar5 = 0x27;
    }
    else if ((ushort)puVar2[8] < 6) {
      uVar1 = 0x80090029;
      uVar7 = 0x47;
      uVar5 = 0x29;
    }
    else {
      puVar4 = (undefined8 *)MSCryptAlloc(0x20);
      if (puVar4 != (undefined8 *)0x0) {
        *puVar4 = 0;
        puVar4[1] = 0;
        puVar4[2] = 0;
        puVar4[3] = 0;
        uVar1 = (**(code **)(puVar2 + 0x5c))
                          (*(undefined8 *)(puVar2 + 0x6a),*(undefined8 *)(puVar3 + 4),puVar4 + 2,
                           param_4,param_5);
        if (-1 < (int)uVar1) {
          *(undefined4 *)(puVar4 + 1) = 0;
          *(undefined4 *)puVar4 = 0x20;
          *(undefined4 *)((longlong)puVar4 + 4) = 0x44444442;
          *(undefined4 *)((longlong)puVar4 + 0xc) = 1;
          puVar4[3] = puVar2;
          *param_3 = puVar4;
          LOCK();
          puVar2[4] = puVar2[4] + 1;
          UNLOCK();
          uVar1 = 0;
          goto LAB_18001a13b;
        }
        uVar5 = (undefined1)uVar1;
        uVar7 = 100;
        goto LAB_18001a11b;
      }
      uVar1 = 0x8009000e;
      uVar7 = 0x53;
      uVar5 = 0xe;
    }
    DebugTraceError(uVar5,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",
                    uVar7);
  }
LAB_18001a13b:
  NormalizeNteStatus(uVar1);
  return;
}



===== SslExportKeyingMaterial @ 18001a170 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void SslExportKeyingMaterial(uint *param_1,uint *param_2)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  
                    /* 0x1a170  138  SslExportKeyingMaterial */
  puVar2 = ValidateSslProvHandle(param_1);
  puVar3 = ValidateSslKeyHandle(param_2);
  if ((puVar2 == (uint *)0x0) || (puVar3 == (uint *)0x0)) {
    uVar1 = 0x80090026;
    uVar5 = 0x7d;
    uVar4 = 0x26;
  }
  else if ((ushort)puVar2[8] < 3) {
    uVar1 = 0x80090029;
    uVar5 = 0x8b;
    uVar4 = 0x29;
  }
  else {
    uVar1 = (**(code **)(puVar2 + 0x44))(*(undefined8 *)(puVar2 + 0x6a),*(undefined8 *)(puVar3 + 4))
    ;
    if (-1 < (int)uVar1) goto LAB_18001a24b;
    uVar5 = 0xa0;
    uVar4 = (undefined1)uVar1;
  }
  DebugTraceError(uVar4,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",uVar5)
  ;
LAB_18001a24b:
  NormalizeNteStatus(uVar1);
  return;
}



===== SslGeneratePreMasterKey @ 18001a260 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void SslGeneratePreMasterKey
               (uint *param_1,undefined8 param_2,undefined8 *param_3,undefined4 param_4,
               undefined4 param_5,undefined8 param_6,undefined8 param_7,undefined4 param_8,
               undefined8 param_9,undefined4 param_10)

{
  uint uVar1;
  uint *puVar2;
  undefined8 *puVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  
                    /* 0x1a260  145  SslGeneratePreMasterKey */
  puVar2 = ValidateSslProvHandle(param_1);
  if (puVar2 == (uint *)0x0) {
    uVar1 = 0x80090026;
    uVar5 = 0x8e;
    uVar4 = 0x26;
  }
  else if (param_3 == (undefined8 *)0x0) {
    uVar1 = 0x80090027;
    uVar5 = 0x95;
    uVar4 = 0x27;
  }
  else if ((ushort)puVar2[8] < 3) {
    uVar1 = 0x80090029;
    uVar5 = 0xa3;
    uVar4 = 0x29;
  }
  else {
    puVar3 = (undefined8 *)MSCryptAlloc(0x20);
    if (puVar3 != (undefined8 *)0x0) {
      *puVar3 = 0;
      puVar3[1] = 0;
      puVar3[2] = 0;
      puVar3[3] = 0;
      uVar1 = (**(code **)(puVar2 + 0x40))
                        (*(undefined8 *)(puVar2 + 0x6a),param_2,puVar3 + 2,param_4,param_5,param_6,
                         param_7,param_8,param_9,param_10);
      if ((int)uVar1 < 0) {
        DebugTraceError((char)uVar1,"Status",
                        "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",0xc5);
        SafeAllocaFreeToHeap(puVar3);
      }
      else {
        *(undefined4 *)(puVar3 + 1) = 0;
        *(undefined4 *)puVar3 = 0x20;
        *(undefined4 *)((longlong)puVar3 + 4) = 0x44444442;
        *(undefined4 *)((longlong)puVar3 + 0xc) = 1;
        puVar3[3] = puVar2;
        LOCK();
        puVar2[4] = puVar2[4] + 1;
        UNLOCK();
        *param_3 = puVar3;
      }
      goto LAB_18001a3cc;
    }
    uVar1 = 0x8009000e;
    uVar5 = 0xaf;
    uVar4 = 0xe;
  }
  DebugTraceError(uVar4,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",uVar5)
  ;
LAB_18001a3cc:
  NormalizeNteStatus(uVar1);
  return;
}



===== SslGetProviderProperty @ 18001a400 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void SslGetProviderProperty
               (uint *param_1,longlong param_2,longlong param_3,longlong param_4,longlong *param_5,
               undefined4 param_6)

{
  uint uVar1;
  uint *puVar2;
  ulonglong uVar3;
  undefined8 *puVar4;
  undefined1 uVar5;
  longlong lVar6;
  undefined1 uVar7;
  longlong local_28 [2];
  
                    /* 0x1a400  149  SslGetProviderProperty */
  puVar4 = (undefined8 *)0x0;
  local_28[0] = 0;
  lVar6 = param_2;
  puVar2 = ValidateSslProvHandle(param_1);
  if (puVar2 == (uint *)0x0) {
    uVar1 = 0x80090026;
    uVar7 = 0x36;
    uVar5 = 0x26;
  }
  else {
    if (param_2 == 0) {
      uVar7 = 0x3d;
    }
    else {
      uVar3 = 0xffffffffffffffff;
      do {
        uVar3 = uVar3 + 1;
      } while (*(short *)(lVar6 + uVar3 * 2) != 0);
      if (uVar3 < 0x41) {
        if ((param_3 != 0) && (param_4 != 0)) {
          if (param_5 != (longlong *)0x0) {
            local_28[0] = *param_5;
            if (local_28[0] == 0) {
              puVar4 = (undefined8 *)MSCryptAlloc(0x20);
              if (puVar4 == (undefined8 *)0x0) {
                uVar1 = 0x8009000e;
                uVar7 = 0x60;
                uVar5 = 0xe;
                goto LAB_18001a5a2;
              }
              *puVar4 = 0;
              puVar4[1] = 0;
              puVar4[2] = 0;
              puVar4[3] = 0;
            }
          }
          uVar1 = (**(code **)(puVar2 + 0x26))
                            (*(undefined8 *)(puVar2 + 0x6a),param_2,param_3,param_4,local_28,param_6
                            );
          if ((int)uVar1 < 0) {
            DebugTraceError((char)uVar1,"Status",
                            "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",0x75);
          }
          else {
            if (param_5 != (longlong *)0x0) {
              if (puVar4 == (undefined8 *)0x0) {
                if (local_28[0] != *param_5) {
                  uVar1 = 0x80090020;
                  uVar7 = 0x86;
                  uVar5 = 0x20;
                  goto LAB_18001a5a2;
                }
              }
              else {
                LOCK();
                puVar2[4] = puVar2[4] + 1;
                UNLOCK();
                *puVar4 = puVar2;
                puVar4[1] = local_28[0];
                MSCryptAddMemoryBuffer(0x1800278a0,(longlong)puVar4);
                puVar4 = (undefined8 *)0x0;
              }
              *param_5 = local_28[0];
            }
            uVar1 = 0;
          }
          if (puVar4 != (undefined8 *)0x0) {
            SafeAllocaFreeToHeap(puVar4);
          }
          goto LAB_18001a5b5;
        }
        uVar7 = 0x4a;
      }
      else {
        uVar7 = 0x43;
      }
    }
    uVar1 = 0x80090027;
    uVar5 = 0x27;
  }
LAB_18001a5a2:
  DebugTraceError(uVar5,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",uVar7)
  ;
LAB_18001a5b5:
  NormalizeNteStatus(uVar1);
  return;
}



===== SslGetSessionTicketProtectionHeaderSize @ 18001a5e0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void SslGetSessionTicketProtectionHeaderSize(uint *param_1)

{
  uint uVar1;
  uint *puVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  
                    /* 0x1a5e0  150  SslGetSessionTicketProtectionHeaderSize */
  puVar2 = ValidateSslProvHandle(param_1);
  if ((ushort)puVar2[8] < 7) {
    uVar1 = 0x80090029;
    uVar4 = 0x74;
    uVar3 = 0x29;
  }
  else {
    uVar1 = (**(code **)(puVar2 + 0x60))(*(undefined8 *)(puVar2 + 0x6a));
    if (-1 < (int)uVar1) goto LAB_18001a63c;
    uVar4 = 0x8f;
    uVar3 = (undefined1)uVar1;
  }
  DebugTraceError(uVar3,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",uVar4)
  ;
LAB_18001a63c:
  NormalizeNteStatus(uVar1);
  return;
}



===== SslProtectSessionTicket @ 18001a650 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void SslProtectSessionTicket(uint *param_1,uint *param_2)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  
                    /* 0x1a650  159  SslProtectSessionTicket */
  puVar2 = ValidateSslProvHandle(param_1);
  puVar3 = ValidateSslKeyHandle(param_2);
  if ((ushort)puVar2[8] < 7) {
    uVar1 = 0x80090029;
    uVar5 = 0xb1;
    uVar4 = 0x29;
  }
  else if (puVar3 == (uint *)0x0) {
    uVar1 = 0x80090026;
    uVar5 = 0xbd;
    uVar4 = 0x26;
  }
  else {
    uVar1 = (**(code **)(puVar2 + 0x62))(*(undefined8 *)(puVar2 + 0x6a),*(undefined8 *)(puVar3 + 4))
    ;
    if (-1 < (int)uVar1) goto LAB_18001a6f2;
    uVar5 = 0xd0;
    uVar4 = (undefined1)uVar1;
  }
  DebugTraceError(uVar4,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",uVar5)
  ;
LAB_18001a6f2:
  NormalizeNteStatus(uVar1);
  return;
}



===== SslUnprotectSessionTicket @ 18001a710 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void SslUnprotectSessionTicket(uint *param_1,uint *param_2)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  
                    /* 0x1a710  161  SslUnprotectSessionTicket */
  puVar2 = ValidateSslProvHandle(param_1);
  puVar3 = ValidateSslKeyHandle(param_2);
  if ((ushort)puVar2[8] < 7) {
    uVar1 = 0x80090029;
    uVar5 = 0xf2;
    uVar4 = 0x29;
  }
  else if (puVar3 == (uint *)0x0) {
    uVar1 = 0x80090026;
    uVar5 = 0xfe;
    uVar4 = 0x26;
  }
  else {
    uVar1 = (**(code **)(puVar2 + 100))(*(undefined8 *)(puVar2 + 0x6a),*(undefined8 *)(puVar3 + 4));
    if (-1 < (int)uVar1) goto LAB_18001a7b2;
    uVar5 = 0x11;
    uVar4 = (undefined1)uVar1;
  }
  DebugTraceError(uVar4,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",uVar5)
  ;
LAB_18001a7b2:
  NormalizeNteStatus(uVar1);
  return;
}



===== SslVerifySignature @ 18001a7d0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void SslVerifySignature(uint *param_1,uint *param_2)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  
                    /* 0x1a7d0  162  SslVerifySignature */
  puVar2 = ValidateSslProvHandle(param_1);
  if (puVar2 == (uint *)0x0) {
    uVar5 = 0xab;
LAB_18001a7e9:
    uVar1 = 0x80090026;
    uVar4 = 0x26;
  }
  else {
    puVar3 = ValidateSslKeyHandle(param_2);
    if (puVar3 == (uint *)0x0) {
      uVar5 = 0xb3;
      goto LAB_18001a7e9;
    }
    uVar1 = (**(code **)(puVar2 + 0x36))(*(undefined8 *)(puVar2 + 0x6a),*(undefined8 *)(puVar3 + 4))
    ;
    if (-1 < (int)uVar1) {
      uVar1 = 0;
      goto LAB_18001a863;
    }
    uVar5 = 0xc5;
    uVar4 = (undefined1)uVar1;
  }
  DebugTraceError(uVar4,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\sslprot.c",uVar5)
  ;
LAB_18001a863:
  NormalizeNteStatus(uVar1);
  return;
}



===== EtwLogNCryptCreateKeyFailed @ 18001a878 =====

undefined8
EtwLogNCryptCreateKeyFailed
          (wchar_t *param_1,wchar_t *param_2,wchar_t *param_3,undefined1 param_4,undefined1 param_5)

{
  wchar_t *pwVar1;
  undefined8 uVar2;
  wchar_t *pwVar3;
  wchar_t *pwVar4;
  
  if ((Microsoft_Windows_Crypto_NCryptEnableBits & 1) == 0) {
    uVar2 = 0;
  }
  else {
    pwVar3 = param_1;
    pwVar4 = param_2;
    pwVar1 = I_GetProcessName();
    uVar2 = McTemplateU0zzzddz_EventWriteTransfer
                      (pwVar3,pwVar4,param_1,param_2,param_3,param_4,param_5,pwVar1);
  }
  return uVar2;
}



===== EtwLogNCryptUnprotectKeyFailed @ 18001a8e8 =====

ulonglong EtwLogNCryptUnprotectKeyFailed
                    (wchar_t *param_1,int *param_2,undefined1 param_3,undefined1 param_4)

{
  uint uVar1;
  wchar_t *pwVar2;
  wchar_t *pwVar3;
  int *piVar4;
  int iVar5;
  ulonglong uVar6;
  
  uVar6 = 0;
  iVar5 = 0;
  if ((Microsoft_Windows_Crypto_NCryptEnableBits & 2) != 0) {
    if (*param_2 == 3) {
      uVar6 = *(ulonglong *)(param_2 + 6);
      iVar5 = param_2[4];
    }
    else if (*param_2 == 5) {
      uVar6 = *(ulonglong *)(param_2 + 8);
      iVar5 = param_2[6];
    }
    pwVar3 = param_1;
    piVar4 = param_2;
    pwVar2 = I_GetProcessName();
    uVar1 = McTemplateU0zqddzqbr5_EventWriteTransfer
                      (pwVar3,piVar4,param_1,*param_2,param_3,param_4,pwVar2,iVar5,uVar6);
    uVar6 = (ulonglong)uVar1;
  }
  return uVar6;
}



===== McTemplateU0ddz_EventWriteTransfer @ 18001a980 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateU0ddz_EventWriteTransfer
               (undefined8 param_1,PCEVENT_DESCRIPTOR param_2,undefined4 param_3,undefined4 param_4,
               wchar_t *param_5)

{
  longlong lVar1;
  undefined4 local_res18 [2];
  undefined4 local_res20 [2];
  undefined1 auStackY_88 [32];
  _EVENT_DATA_DESCRIPTOR local_58;
  undefined4 *local_48;
  undefined8 local_40;
  undefined4 *local_38;
  undefined8 local_30;
  wchar_t *local_28;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  local_48 = local_res18;
  local_40 = 4;
  local_30 = 4;
  local_38 = local_res20;
  if (param_5 == (wchar_t *)0x0) {
    local_20 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_5[lVar1] != L'\0');
    local_20 = (int)lVar1 * 2 + 2;
  }
  local_1c = 0;
  if (param_5 == (wchar_t *)0x0) {
    param_5 = L"NULL";
  }
  local_res18[0] = param_3;
  local_res20[0] = param_4;
  local_28 = param_5;
  McGenEventWrite_EventWriteTransfer(param_5,param_2,L"NULL",4,&local_58);
  return;
}



===== McTemplateU0zqddzqbr5_EventWriteTransfer @ 18001aa30 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateU0zqddzqbr5_EventWriteTransfer
               (undefined8 param_1,undefined8 param_2,wchar_t *param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6,wchar_t *param_7,undefined4 param_8,
               undefined8 param_9)

{
  longlong lVar1;
  longlong lVar2;
  undefined4 local_res20 [2];
  undefined1 auStackY_c8 [32];
  _EVENT_DATA_DESCRIPTOR local_98;
  wchar_t *local_88;
  int local_80;
  undefined4 local_7c;
  undefined4 *local_78;
  undefined8 local_70;
  undefined1 *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  wchar_t *local_48;
  int local_40;
  undefined4 local_3c;
  undefined4 *local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_c8;
  lVar1 = -1;
  local_40 = 10;
  if (param_3 == (wchar_t *)0x0) {
    local_80 = 10;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (param_3[lVar2] != L'\0');
    local_80 = (int)lVar2 * 2 + 2;
  }
  local_78 = local_res20;
  local_7c = 0;
  local_68 = &param_5;
  local_70 = 4;
  if (param_3 == (wchar_t *)0x0) {
    param_3 = L"NULL";
  }
  local_58 = &param_6;
  local_60 = 4;
  local_50 = 4;
  if (param_7 != (wchar_t *)0x0) {
    do {
      lVar1 = lVar1 + 1;
    } while (param_7[lVar1] != L'\0');
    local_40 = (int)lVar1 * 2 + 2;
  }
  local_48 = param_7;
  if (param_7 == (wchar_t *)0x0) {
    local_48 = L"NULL";
  }
  local_38 = &param_8;
  local_28 = param_9;
  local_20 = param_8;
  local_3c = 0;
  local_30 = 4;
  local_1c = 0;
  local_res20[0] = param_4;
  local_88 = param_3;
  McGenEventWrite_EventWriteTransfer
            (local_58,(PCEVENT_DESCRIPTOR)&ETW_LOG_NCRYPT_UNPROTECT_KEY_FAILED,param_3,8,&local_98);
  return;
}



===== GetIsolationServerInterface @ 18001ab50 =====

undefined8 GetIsolationServerInterface(void)

{
                    /* 0x1ab50  61  GetIsolationServerInterface
                       0x1ab50  62  GetKeyStorageInterface
                       0x1ab50  63  GetSChannelInterface */
  return 0x8007007f;
}



===== NCryptSetAuditingInterface @ 18001ab60 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

DWORD NCryptSetAuditingInterface(void)

{
  BOOL BVar1;
  DWORD DVar2;
  HANDLE ProcessHandle;
  undefined1 uVar3;
  undefined1 auStack_68 [32];
  BOOL aBStack_48 [2];
  HANDLE pvStack_40;
  DWORD DStack_38;
  LONG LStack_34;
  _PRIVILEGE_SET _Stack_30;
  ulonglong uStack_18;
  
                    /* 0x1ab60  98  NCryptSetAuditingInterface */
  uStack_18 = __security_cookie ^ (ulonglong)auStack_68;
  pvStack_40 = (HANDLE)0x0;
  LStack_34 = 0;
  aBStack_48[0] = 0;
  _Stack_30.PrivilegeCount = 0;
  _Stack_30.Control = 0;
  _Stack_30.Privilege[0].Luid.LowPart = 0;
  _Stack_30.Privilege[0].Luid.HighPart = 0;
  _Stack_30.Privilege[0].Attributes = 0;
  DStack_38 = 7;
  ProcessHandle = GetCurrentProcess();
  BVar1 = OpenProcessToken(ProcessHandle,8,&pvStack_40);
  if (BVar1 == 0) {
    DVar2 = GetLastError();
    if ((int)DVar2 < 1) {
      DVar2 = GetLastError();
    }
    else {
      DVar2 = GetLastError();
      DVar2 = DVar2 & 0xffff | 0xc0070000;
    }
    uVar3 = 0x56;
  }
  else {
    _Stack_30.Privilege[0].Luid.HighPart = LStack_34;
    _Stack_30.Privilege[0].Luid.LowPart = DStack_38;
    _Stack_30.Privilege[0].Attributes = 0;
    _Stack_30.PrivilegeCount = 1;
    _Stack_30.Control = 0;
    BVar1 = PrivilegeCheck(pvStack_40,&_Stack_30,aBStack_48);
    if (BVar1 == 0) {
      DVar2 = GetLastError();
      if ((int)DVar2 < 1) {
        DVar2 = GetLastError();
      }
      else {
        DVar2 = GetLastError();
        DVar2 = DVar2 & 0xffff | 0xc0070000;
      }
      uVar3 = 100;
    }
    else {
      if (aBStack_48[0] != 0) {
        DVar2 = 0;
        goto LAB_18001bb08;
      }
      DVar2 = 0xc0000061;
      uVar3 = 0x6b;
    }
  }
  DebugTraceError((char)DVar2,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\common\\audit.c",
                  uVar3);
LAB_18001bb08:
  if (pvStack_40 != (HANDLE)0x0) {
    CloseHandle(pvStack_40);
  }
  return DVar2;
}



===== CertInUseGetPubKeyInfo @ 18001ab6c =====

SECURITY_STATUS
CertInUseGetPubKeyInfo
          (undefined8 *param_1,longlong *param_2,uint *param_3,STRSAFE_LPWSTR param_4,
          undefined4 *param_5)

{
  int *hKey;
  uint uVar1;
  SECURITY_STATUS SVar2;
  int iVar3;
  int *piVar4;
  PBYTE pbOutput;
  undefined8 uVar5;
  undefined1 *puVar6;
  wchar_t *_Str1;
  DWORD local_res8 [2];
  DWORD local_res20 [2];
  wchar_t *local_48 [2];
  
  hKey = (int *)*param_1;
  local_res8[0] = 0;
  local_res20[0] = 0;
  local_48[0] = (wchar_t *)0x0;
  pbOutput = (PBYTE)0x0;
  _Str1 = (wchar_t *)0x0;
  piVar4 = ValidateClientKeyHandle(hKey);
  if (piVar4 == (int *)0x0) {
    SVar2 = -0x7ff6fca3;
  }
  else {
    uVar1 = Feature_CNG_NCRYPT_PRIVATE_TLS_CLIENT_AUTH__private_IsEnabledDeviceUsageNoInline();
    *param_4 = (-(ushort)(uVar1 != 0) & 0xfff9) + L'+';
    StringCchCopyW(param_4 + 1,0x3f,*(STRSAFE_LPCWSTR *)(*(longlong *)(piVar4 + 2) + 0x118));
    *param_5 = 0;
    SVar2 = GetKeyAlgoGroupProp((NCRYPT_HANDLE)hKey,local_48);
    _Str1 = local_48[0];
    if (SVar2 == 0) {
      iVar3 = wcscmp(local_48[0],L"RSA");
      if (iVar3 == 0) {
        SVar2 = NCryptExportKey((NCRYPT_KEY_HANDLE)hKey,0,L"RSAPUBLICBLOB",(NCryptBufferDesc *)0x0,
                                (PBYTE)0x0,0,local_res8,0);
        if (SVar2 != 0) goto LAB_18001ae05;
        pbOutput = (PBYTE)MSCryptAlloc((ulonglong)local_res8[0]);
        if (pbOutput != (PBYTE)0x0) {
          SVar2 = NCryptExportKey((NCRYPT_KEY_HANDLE)hKey,0,L"RSAPUBLICBLOB",(NCryptBufferDesc *)0x0
                                  ,pbOutput,local_res8[0],local_res20,0);
          if (SVar2 != 0) goto LAB_18001ae05;
          uVar5 = Ordinal_5(L"{34e4912d-f770-4f49-b020-96dd74c99d01}");
          SVar2 = 0;
          local_48[0] = (wchar_t *)0x0;
          iVar3 = Ordinal_2(uVar5,0x48,0,0,param_2,local_48,pbOutput);
          if (-1 < iVar3) {
            *param_3 = (uint)local_48[0];
            goto LAB_18001ae05;
          }
        }
      }
      else {
        iVar3 = wcscmp(_Str1,L"ECDSA");
        if (iVar3 != 0) {
          iVar3 = wcscmp(_Str1,L"ECDH");
          if (iVar3 != 0) {
            SVar2 = -0x7ff6fcfe;
            goto LAB_18001ae05;
          }
        }
        SVar2 = NCryptExportKey((NCRYPT_KEY_HANDLE)hKey,0,L"ECCPUBLICBLOB",(NCryptBufferDesc *)0x0,
                                (PBYTE)0x0,0,local_res8,0);
        if (SVar2 != 0) goto LAB_18001ae05;
        pbOutput = (PBYTE)MSCryptAlloc((ulonglong)local_res8[0]);
        if (pbOutput != (PBYTE)0x0) {
          SVar2 = NCryptExportKey((NCRYPT_KEY_HANDLE)hKey,0,L"ECCPUBLICBLOB",(NCryptBufferDesc *)0x0
                                  ,pbOutput,local_res8[0],local_res20,0);
          if (SVar2 != 0) goto LAB_18001ae05;
          uVar1 = *(int *)(pbOutput + 4) * 2;
          if ((ulonglong)uVar1 + 8 <= (ulonglong)local_res20[0]) {
            puVar6 = LocalAlloc(0x40,(ulonglong)(uVar1 + 1));
            *param_2 = (longlong)puVar6;
            if (puVar6 != (undefined1 *)0x0) {
              *puVar6 = 4;
              memcpy((void *)(*param_2 + 1),pbOutput + 8,(ulonglong)uVar1);
              *param_3 = uVar1 + 1;
              SVar2 = 0;
              goto LAB_18001ae05;
            }
          }
        }
      }
      SVar2 = -0x7ff6fff2;
    }
  }
LAB_18001ae05:
  if (*param_4 == L'\0') {
    StringCchCopyW(param_4,0x40,L"Provider name can not be accessed");
  }
  if (pbOutput != (PBYTE)0x0) {
    SafeAllocaFreeToHeap(pbOutput);
  }
  if (_Str1 != (wchar_t *)0x0) {
    SafeAllocaFreeToHeap(_Str1);
  }
  return SVar2;
}



===== Feature_CNG_NCRYPT_PRIVATE_TLS_CLIENT_AUTH__private_IsEnabledDeviceUsageNoInline @ 18001ae60 =====

uint Feature_CNG_NCRYPT_PRIVATE_TLS_CLIENT_AUTH__private_IsEnabledDeviceUsageNoInline(void)

{
  uint uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_CNG_NCRYPT_PRIVATE_TLS_CLIENT_AUTH__private_featureState;
  if ((Feature_CNG_NCRYPT_PRIVATE_TLS_CLIENT_AUTH__private_featureState & 0x10) == 0) {
    uVar1 = wil_details_IsEnabledFallback
                      (local_res8,3,&Feature_CNG_NCRYPT_PRIVATE_TLS_CLIENT_AUTH__private_descriptor)
    ;
    return uVar1;
  }
  return Feature_CNG_NCRYPT_PRIVATE_TLS_CLIENT_AUTH__private_featureState & 1;
}



===== NCryptDecapsulate @ 18001aeb0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void NCryptDecapsulate(int *param_1,undefined8 param_2,ulonglong param_3,undefined8 param_4,
                      undefined4 param_5,longlong param_6,uint param_7)

{
  uint uVar1;
  int *piVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined8 uVar5;
  
                    /* 0x1aeb0  69  NCryptDecapsulate */
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    WPP_SF_PD(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x27,param_3,param_1,(char)param_7);
  }
  if (param_6 == 0) {
    uVar1 = 0x80090027;
    uVar4 = 0x33;
    uVar3 = 0x27;
  }
  else {
    uVar5 = param_2;
    piVar2 = ValidateClientKeyHandle(param_1);
    if (piVar2 == (int *)0x0) {
      uVar1 = 0x80090026;
      uVar4 = 0x3c;
      uVar3 = 0x26;
    }
    else {
      if ((3 < *(ushort *)(*(longlong *)(piVar2 + 2) + 0x10)) &&
         (*(longlong *)(*(longlong *)(piVar2 + 2) + 0x108) != 0)) {
        while (uVar1 = (**(code **)(*(longlong *)(piVar2 + 2) + 0x108))
                                 (*(undefined8 *)(*(longlong *)(piVar2 + 2) + 0x110),
                                  *(undefined8 *)(piVar2 + 4),uVar5,param_3 & 0xffffffff,param_4,
                                  param_5,param_6,param_7), uVar1 == 0x8009002e) {
          if ((param_7 & 0x40) != 0) {
            uVar1 = 0x80090022;
            uVar4 = 0x61;
            uVar3 = 0x22;
            goto LAB_18001b05d;
          }
          uVar1 = (**(code **)(*(longlong *)(piVar2 + 2) + 0xc0))
                            (*(undefined8 *)(*(longlong *)(piVar2 + 2) + 0x110),param_1,
                             L"NCryptDecapsulate",0);
          if (uVar1 != 0) goto LAB_18001b00f;
          uVar5 = param_2;
        }
        if (uVar1 == 0) {
          uVar1 = 0;
        }
        else {
LAB_18001b00f:
          uVar5 = 0x1273;
          DebugTraceError((char)uVar1,"Status",
                          "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",0x73)
          ;
          EtwLogNCryptOperationFailed
                    (0x13,*(wchar_t **)(*(longlong *)(piVar2 + 2) + 0x118),*(wchar_t **)(piVar2 + 6)
                     ,uVar5,(char)uVar1);
        }
        goto LAB_18001b070;
      }
      uVar1 = 0x80090029;
      uVar4 = 0x48;
      uVar3 = 0x29;
    }
  }
LAB_18001b05d:
  DebugTraceError(uVar3,"Status",
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",uVar4);
LAB_18001b070:
  NormalizeNteStatus(uVar1);
  return;
}



===== NCryptEncapsulate @ 18001b0a0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void NCryptEncapsulate(int *param_1,undefined8 param_2,ulonglong param_3,longlong param_4,
                      undefined8 param_5,undefined4 param_6,longlong param_7,uint param_8)

{
  uint uVar1;
  int *piVar2;
  undefined1 uVar3;
  ulonglong uVar4;
  undefined1 uVar5;
  undefined8 uVar6;
  
                    /* 0x1b0a0  74  NCryptEncapsulate */
  uVar4 = param_3;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    WPP_SF_PD(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x26,param_3,param_1,(char)param_8);
    uVar4 = param_3 & 0xffffffff;
  }
  if (param_4 == 0) {
    uVar5 = 0xc0;
LAB_18001b114:
    uVar1 = 0x80090027;
    uVar3 = 0x27;
  }
  else {
    if (param_7 == 0) {
      uVar5 = 0xc6;
      goto LAB_18001b114;
    }
    uVar6 = param_2;
    piVar2 = ValidateClientKeyHandle(param_1);
    if (piVar2 == (int *)0x0) {
      uVar1 = 0x80090026;
      uVar5 = 0xcf;
      uVar3 = 0x26;
    }
    else {
      if ((3 < *(ushort *)(*(longlong *)(piVar2 + 2) + 0x10)) &&
         (*(longlong *)(*(longlong *)(piVar2 + 2) + 0x100) != 0)) {
        while (uVar1 = (**(code **)(*(longlong *)(piVar2 + 2) + 0x100))
                                 (*(undefined8 *)(*(longlong *)(piVar2 + 2) + 0x110),
                                  *(undefined8 *)(piVar2 + 4),uVar6,uVar4 & 0xffffffff,param_4,
                                  param_5,param_6,param_7,param_8), uVar1 == 0x8009002e) {
          if ((param_8 & 0x40) != 0) {
            uVar1 = 0x80090022;
            uVar5 = 0xf5;
            uVar3 = 0x22;
            goto LAB_18001b275;
          }
          uVar1 = (**(code **)(*(longlong *)(piVar2 + 2) + 0xc0))
                            (*(undefined8 *)(*(longlong *)(piVar2 + 2) + 0x110),param_1,
                             L"NCryptEncapsulate",0);
          if (uVar1 != 0) goto LAB_18001b227;
          uVar4 = param_3 & 0xffffffff;
          uVar6 = param_2;
        }
        if (uVar1 == 0) {
          uVar1 = 0;
        }
        else {
LAB_18001b227:
          uVar6 = 0x1207;
          DebugTraceError((char)uVar1,"Status",
                          "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",7);
          EtwLogNCryptOperationFailed
                    (0x12,*(wchar_t **)(*(longlong *)(piVar2 + 2) + 0x118),*(wchar_t **)(piVar2 + 6)
                     ,uVar6,(char)uVar1);
        }
        goto LAB_18001b288;
      }
      uVar1 = 0x80090029;
      uVar5 = 0xdb;
      uVar3 = 0x29;
    }
  }
LAB_18001b275:
  DebugTraceError(uVar3,"Status",
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",uVar5);
LAB_18001b288:
  NormalizeNteStatus(uVar1);
  return;
}



===== NCryptNotifyChangeKey @ 18001b2b0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

SECURITY_STATUS __stdcall
NCryptNotifyChangeKey(NCRYPT_PROV_HANDLE hProvider,HANDLE *phEvent,DWORD dwFlags)

{
  uint uVar1;
  int *piVar2;
  undefined4 in_register_00000084;
  
                    /* 0x1b2b0  89  NCryptNotifyChangeKey */
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    WPP_SF_PD(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x22,CONCAT44(in_register_00000084,dwFlags)
              ,hProvider,(char)dwFlags);
  }
  piVar2 = ValidateAndReferenceProvider((int *)hProvider);
  if (piVar2 == (int *)0x0) {
    uVar1 = 0x80090026;
    DebugTraceError(0x26,"Status",
                    "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",0xff);
  }
  else {
    uVar1 = (**(code **)(piVar2 + 0x32))(*(undefined8 *)(piVar2 + 0x44),phEvent,dwFlags);
    if (uVar1 == 0) {
      uVar1 = 0;
    }
    else {
      DebugTraceError((char)uVar1,"Status",
                      "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",10);
    }
    DereferenceProvider((longlong)piVar2);
  }
  uVar1 = NormalizeNteStatus(uVar1);
  return uVar1;
}



===== NCryptVerifyClaim @ 18001b3a0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void NCryptVerifyClaim(int *param_1,int *param_2,undefined8 param_3,undefined8 param_4,
                      undefined8 param_5,undefined4 param_6,longlong param_7,undefined4 param_8)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  ulonglong uVar4;
  code *pcVar5;
  undefined1 uVar6;
  uint uVar7;
  longlong lVar8;
  int *piVar9;
  undefined1 uVar10;
  undefined8 uVar11;
  int iVar12;
  ulonglong local_38;
  
                    /* 0x1b3a0  109  NCryptVerifyClaim */
  piVar3 = (int *)0x0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    WPP_SF_PD(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x25,param_3,param_1,(char)param_8);
  }
  iVar12 = 5;
  if ((int)param_3 != 4) {
    iVar12 = (int)param_3;
  }
  if (iVar12 - 5U < 2) {
    if ((Feature_Key_Guard_Attestation__private_featureState & 0x10) == 0) {
      uVar7 = Feature_Key_Guard_Attestation__private_featureState | 1;
      local_38 = (ulonglong)uVar7;
      wil_details_FeatureReporting_ReportUsageToService(0x1800235c8,local_38,3);
      wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath
                (uVar7,3,&Feature_Key_Guard_Attestation__private_descriptor);
    }
  }
  piVar2 = ValidateClientKeyHandle(param_1);
  piVar9 = (int *)0x0;
  if (piVar2 == (int *)0x0) {
    uVar10 = 0x43;
LAB_18001b481:
    uVar7 = 0x80090026;
    uVar6 = 0x26;
  }
  else {
    if (param_2 != (int *)0x0) {
      piVar3 = ValidateClientKeyHandle(param_2);
      if (piVar3 == (int *)0x0) {
        uVar10 = 0x4e;
        goto LAB_18001b481;
      }
    }
    if (param_7 == 0) {
      uVar7 = 0x80090027;
      uVar10 = 0x56;
      uVar6 = 0x27;
    }
    else {
      lVar8 = *(longlong *)(piVar2 + 2);
      if ((2 < *(ushort *)(lVar8 + 0x10)) &&
         (pcVar5 = *(code **)(lVar8 + 0xf8), pcVar5 != (code *)0x0)) {
        uVar4 = 0xffffffffffffffff;
        do {
          uVar4 = uVar4 + 1;
        } while (*(short *)((longlong)*(void **)(lVar8 + 0x118) + uVar4 * 2) != (short)piVar9);
        if ((uVar4 & 0x7fffffffffffffff) == 0x27) {
          iVar1 = memcmp(*(void **)(lVar8 + 0x118),L"Microsoft Software Key Storage Provider",0x50);
          piVar9 = (int *)0x0;
          if (iVar1 != 0) goto LAB_18001b5c0;
          if ((Feature_Key_Guard_Attestation__private_featureState & 0x10) == 0) {
            uVar7 = Feature_Key_Guard_Attestation__private_featureState | 1;
            local_38 = (ulonglong)uVar7;
            wil_details_FeatureReporting_ReportUsageToService(0x1800235c8,local_38,3);
            wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath
                      (uVar7,3,&Feature_Key_Guard_Attestation__private_descriptor);
          }
          lVar8 = *(longlong *)(piVar2 + 2);
          pcVar5 = *(code **)(lVar8 + 0xf8);
        }
        else {
LAB_18001b5c0:
          if (piVar3 == (int *)0x0) {
            param_2 = piVar9;
          }
          else {
            param_2 = *(int **)(piVar3 + 4);
          }
          lVar8 = *(longlong *)(lVar8 + 0x110);
          param_1 = *(int **)(piVar2 + 4);
        }
        uVar7 = (*pcVar5)(lVar8,param_1,param_2,iVar12,param_4,param_5,param_6,param_7,param_8);
        if (uVar7 == 0) {
          uVar7 = 0;
        }
        else {
          uVar11 = 0x1193;
          DebugTraceError((char)uVar7,"Status",
                          "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",0x93)
          ;
          EtwLogNCryptOperationFailed
                    (0xf,*(wchar_t **)(*(longlong *)(piVar2 + 2) + 0x118),*(wchar_t **)(piVar2 + 6),
                     uVar11,(char)uVar7);
        }
        goto LAB_18001b680;
      }
      uVar7 = 0x80090029;
      uVar10 = 100;
      uVar6 = 0x29;
    }
  }
  DebugTraceError(uVar6,"Status",
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\ncrypt\\storage.c",uVar10);
LAB_18001b680:
  NormalizeNteStatus(uVar7);
  return;
}



===== wil_details_FeatureReporting_IncrementOpportunityInCache @ 18001b6ac =====

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



===== wil_details_GetNtDllProcedureAddress @ 18001b784 =====

void wil_details_GetNtDllProcedureAddress(LPCSTR param_1)

{
  if (`wil_details_GetNtDllModuleHandle'::__l2::wil_details_ntdllModuleHandle == (HMODULE)0x0) {
    `wil_details_GetNtDllModuleHandle'::__l2::wil_details_ntdllModuleHandle =
         GetModuleHandleW(L"ntdll.dll");
  }
                    /* WARNING: Could not recover jumptable at 0x00018001b7be. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GetProcAddress(`wil_details_GetNtDllModuleHandle'::__l2::wil_details_ntdllModuleHandle,param_1);
  return;
}



===== wil_details_RtlNotifyFeatureUsage @ 18001b7d0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

undefined8 wil_details_RtlNotifyFeatureUsage(undefined8 param_1)

{
  undefined8 uVar1;
  
  if (g_wil_details_pfnRtlNotifyFeatureUsage == (code *)0x0) {
    g_wil_details_pfnRtlNotifyFeatureUsage =
         (code *)wil_details_GetNtDllProcedureAddress("RtlNotifyFeatureUsage");
    if (g_wil_details_pfnRtlNotifyFeatureUsage == (code *)0x0) {
      return 0xc0000139;
    }
  }
  uVar1 = (*g_wil_details_pfnRtlNotifyFeatureUsage)(param_1);
  return uVar1;
}



===== CNG_ComputeHash @ 18001b81c =====

NTSTATUS CNG_ComputeHash(PUCHAR param_1,ULONG param_2,ushort *param_3,PUCHAR param_4,uint param_5,
                        uint *param_6)

{
  NTSTATUS NVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  ULONG local_res8 [2];
  BCRYPT_HASH_HANDLE local_28;
  BCRYPT_HANDLE local_20;
  
  local_20 = (BCRYPT_HANDLE)0x0;
  local_28 = (BCRYPT_HASH_HANDLE)0x0;
  local_res8[0] = 0;
  memset(param_4,0,(ulonglong)param_5);
  if (param_1 == (PUCHAR)0x0) {
    return 0;
  }
  NVar1 = CNG_GetBCryptHandle(param_3,&local_20);
  if (NVar1 == 0) {
    NVar1 = BCryptGetProperty(local_20,L"HashDigestLength",(PUCHAR)param_6,4,local_res8,0);
    if (NVar1 != 0) {
      uVar3 = 0xc0;
      goto LAB_18001b972;
    }
    if (*param_6 <= param_5) {
      NVar1 = BCryptCreateHash(local_20,&local_28,(PUCHAR)0x0,0,(PUCHAR)0x0,0,0);
      if (NVar1 == 0) {
        NVar1 = BCryptHashData(local_28,param_1,param_2,0);
        if (NVar1 == 0) {
          NVar1 = BCryptFinishHash(local_28,param_4,*param_6,0);
          if (NVar1 == 0) goto LAB_18001b987;
          uVar3 = 0xec;
        }
        else {
          uVar3 = 0xe0;
        }
      }
      else {
        uVar3 = 0xd5;
      }
      goto LAB_18001b972;
    }
    NVar1 = -0x7ff6ffd8;
    uVar3 = 199;
    uVar2 = 0x28;
  }
  else {
    uVar3 = 0xb2;
LAB_18001b972:
    uVar2 = (undefined1)NVar1;
  }
  DebugTraceError(uVar2,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\common\\provider.c",
                  uVar3);
LAB_18001b987:
  if (local_28 != (BCRYPT_HASH_HANDLE)0x0) {
    BCryptDestroyHash(local_28);
  }
  return NVar1;
}



===== CngSetAuditingInterface @ 18001b9c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

DWORD CngSetAuditingInterface(void)

{
  BOOL BVar1;
  DWORD DVar2;
  HANDLE ProcessHandle;
  undefined1 uVar3;
  undefined1 auStack_68 [32];
  BOOL local_48 [2];
  HANDLE local_40;
  DWORD local_38;
  LONG LStack_34;
  _PRIVILEGE_SET local_30;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  local_40 = (HANDLE)0x0;
  LStack_34 = 0;
  local_48[0] = 0;
  local_30.PrivilegeCount = 0;
  local_30.Control = 0;
  local_30.Privilege[0].Luid.LowPart = 0;
  local_30.Privilege[0].Luid.HighPart = 0;
  local_30.Privilege[0].Attributes = 0;
  local_38 = 7;
  ProcessHandle = GetCurrentProcess();
  BVar1 = OpenProcessToken(ProcessHandle,8,&local_40);
  if (BVar1 == 0) {
    DVar2 = GetLastError();
    if ((int)DVar2 < 1) {
      DVar2 = GetLastError();
    }
    else {
      DVar2 = GetLastError();
      DVar2 = DVar2 & 0xffff | 0xc0070000;
    }
    uVar3 = 0x56;
  }
  else {
    local_30.Privilege[0].Luid.HighPart = LStack_34;
    local_30.Privilege[0].Luid.LowPart = local_38;
    local_30.Privilege[0].Attributes = 0;
    local_30.PrivilegeCount = 1;
    local_30.Control = 0;
    BVar1 = PrivilegeCheck(local_40,&local_30,local_48);
    if (BVar1 == 0) {
      DVar2 = GetLastError();
      if ((int)DVar2 < 1) {
        DVar2 = GetLastError();
      }
      else {
        DVar2 = GetLastError();
        DVar2 = DVar2 & 0xffff | 0xc0070000;
      }
      uVar3 = 100;
    }
    else {
      if (local_48[0] != 0) {
        DVar2 = 0;
        goto LAB_18001bb08;
      }
      DVar2 = 0xc0000061;
      uVar3 = 0x6b;
    }
  }
  DebugTraceError((char)DVar2,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\common\\audit.c",
                  uVar3);
LAB_18001bb08:
  if (local_40 != (HANDLE)0x0) {
    CloseHandle(local_40);
  }
  return DVar2;
}



===== ConvertLegacyDhPublicBlob @ 18001bb40 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
ConvertLegacyDhPublicBlob
          (undefined8 *param_1,uint param_2,undefined4 *param_3,uint param_4,uint *param_5)

{
  uint uVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined1 uVar5;
  undefined8 *puVar6;
  undefined1 *puVar7;
  undefined4 *puVar8;
  undefined1 *puVar9;
  size_t _Size;
  undefined1 auStack_78 [32];
  int local_58 [2];
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_78;
  _Size = (size_t)param_4;
  local_38 = 0;
  local_58[0] = 0;
  local_58[1] = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  if (param_1 == (undefined8 *)0x0) {
    uVar3 = 0x80090027;
    uVar5 = 0x3d;
  }
  else {
    uVar2 = VerifyLegacyDhPublicBlob(param_1,param_2,local_58);
    if ((int)uVar2 == 0) {
      uVar4 = (uint)local_58[1] >> 3;
      uVar1 = uVar4 * 3 + 8;
      *param_5 = uVar1;
      if (param_3 == (undefined4 *)0x0) {
        return 0;
      }
      if ((uint)_Size < uVar1) {
        return 0x80090028;
      }
      memset(param_3,0,_Size);
      puVar6 = param_1 + 6;
      *param_3 = 0x42504844;
      puVar8 = param_3 + 2;
      param_3[1] = uVar4;
      ReverseMemCopy((undefined1 *)puVar8,(undefined1 *)puVar6,uVar4);
      uVar1 = param_3[1];
      puVar9 = (undefined1 *)((longlong)puVar8 + (ulonglong)uVar1);
      puVar7 = (undefined1 *)((longlong)puVar6 + (uStack_50 >> 3 & 0x1fffffff) + (ulonglong)uVar1);
      ReverseMemCopy(puVar9,puVar7,uVar1);
      uVar1 = param_3[1];
      ReverseMemCopy(puVar9 + uVar1,puVar7 + ((uStack_50._4_4_ + 7U >> 3) + uVar1),uVar1);
      return 0;
    }
    uVar3 = 0x80090003;
    uVar5 = 0x45;
  }
  DebugTraceError((char)uVar3,"Status",
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\common\\translate.c",uVar5);
  return uVar3;
}



===== ConvertLegacyDsaPublicBlob @ 18001bc74 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
ConvertLegacyDsaPublicBlob
          (ulonglong *param_1,uint param_2,undefined4 *param_3,uint param_4,uint *param_5)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  undefined4 uVar4;
  ulonglong *puVar5;
  uint uVar6;
  uint uVar7;
  longlong lVar8;
  undefined1 uVar9;
  undefined1 *puVar10;
  undefined4 *puVar11;
  undefined1 *puVar12;
  undefined1 auStack_a8 [32];
  undefined8 local_88;
  ulonglong local_80;
  ulonglong uStack_78;
  undefined8 local_70;
  int local_68;
  uint uStack_64;
  int iStack_60;
  uint uStack_5c;
  ulonglong local_58;
  ulonglong uStack_50;
  ulonglong local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_a8;
  local_70 = 0;
  local_80 = 0;
  uStack_78 = 0;
  if ((param_1 == (ulonglong *)0x0) || (param_2 < 8)) {
    uVar4 = 0x80090027;
    uVar9 = 0x94;
    goto LAB_18001bf20;
  }
  uVar2 = *param_1;
  local_88 = uVar2;
  if ((char)uVar2 != '\x06') {
    uVar4 = 0x80090003;
    uVar9 = 0xa2;
    goto LAB_18001bf20;
  }
  local_88._1_1_ = (char)(uVar2 >> 8);
  if ((1 < (byte)(local_88._1_1_ - 2U)) ||
     (local_88._4_4_ = (uint)(uVar2 >> 0x20), local_88._4_4_ != 0x2200)) {
    uVar4 = 0x80090003;
    uVar9 = 0xaa;
    goto LAB_18001bf20;
  }
  if (local_88._1_1_ == '\x02') {
    lVar8 = 0x10;
    if (((param_2 < 0x10) || (uVar2 = param_1[1], (int)uVar2 != 0x31535344)) ||
       ((local_88._4_4_ = (uint)(uVar2 >> 0x20), 0xa00 < local_88._4_4_ - 0x200 ||
        (((uVar2 & 0x3f00000000) != 0 ||
         (uVar3 = (ulonglong)((local_88._4_4_ >> 3) * 3), (ulonglong)param_2 < uVar3 + 0x3c)))))) {
      local_88 = uVar2;
      uVar4 = 0x80090003;
      uVar9 = 0xb6;
      goto LAB_18001bf20;
    }
    puVar5 = (ulonglong *)(uVar3 + 0x24 + (longlong)param_1);
    local_80 = *puVar5;
    uStack_78 = puVar5[1];
    puVar5 = &local_80;
    uVar6 = 0;
    local_70 = *(undefined8 *)(uVar3 + 0x34 + (longlong)param_1);
    uVar7 = local_88._4_4_;
    local_88 = uVar2;
LAB_18001be31:
    uVar1 = (uVar7 >> 3) * 3 + 0x34;
    *param_5 = uVar1;
    if (param_3 == (undefined4 *)0x0) {
      return 0;
    }
    if (uVar1 <= param_4) {
      memset(param_3,0,(ulonglong)param_4);
      *param_3 = 0x42505344;
      param_3[1] = uVar7 >> 3;
      ReverseMemCopy((undefined1 *)(param_3 + 2),(undefined1 *)puVar5,4);
      ReverseMemCopy((undefined1 *)(param_3 + 3),(undefined1 *)((longlong)puVar5 + 4),0x14);
      puVar11 = param_3 + 0xd;
      ReverseMemCopy((undefined1 *)puVar11,(undefined1 *)((longlong)param_1 + lVar8),param_3[1]);
      puVar12 = (undefined1 *)((longlong)puVar11 + (ulonglong)(uint)param_3[1]);
      puVar10 = (undefined1 *)((longlong)param_1 + lVar8) + (uint)param_3[1];
      ReverseMemCopy((undefined1 *)(param_3 + 8),puVar10,0x14);
      puVar10 = puVar10 + 0x14;
      ReverseMemCopy(puVar12,puVar10,param_3[1]);
      uVar7 = param_3[1];
      ReverseMemCopy(puVar12 + uVar7,puVar10 + ((uVar6 + 7 >> 3) + uVar7),uVar7);
      return 0;
    }
    uVar4 = 0x80090028;
    uVar9 = 0xed;
  }
  else {
    lVar8 = 0x30;
    if (0x2f < param_2) {
      local_68 = (int)param_1[1];
      uVar7 = *(uint *)((longlong)param_1 + 0xc);
      iStack_60 = (int)param_1[2];
      uVar6 = *(uint *)((longlong)param_1 + 0x14);
      local_58 = param_1[3];
      uStack_50 = param_1[4];
      local_48 = param_1[5];
      uStack_64 = uVar7;
      uStack_5c = uVar6;
      if (((((local_68 == 0x33535344) && (uVar7 - 0x200 < 0xa01)) && ((uVar7 & 0x3f) == 0)) &&
          ((iStack_60 == 0xa0 && (uVar6 < 0xc01)))) &&
         ((ulonglong)(uVar6 + 7 >> 3) + 0x44 + (ulonglong)((uVar7 >> 3) * 3) <= (ulonglong)param_2))
      {
        puVar5 = &local_58;
        goto LAB_18001be31;
      }
    }
    uVar4 = 0x80090003;
    uVar9 = 0xd3;
  }
LAB_18001bf20:
  DebugTraceError((char)uVar4,"Status",
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\common\\translate.c",uVar9);
  return uVar4;
}



===== VerifyLegacyDhPublicBlob @ 18001bf5c =====

undefined8 VerifyLegacyDhPublicBlob(undefined8 *param_1,uint param_2,int *param_3)

{
  uint uVar1;
  undefined8 uVar2;
  
  if ((((0x2f < param_2) && (uVar2 = *param_1, (char)uVar2 == '\x06')) &&
      ((char)((ulonglong)uVar2 >> 8) == '\x03')) && ((int)((ulonglong)uVar2 >> 0x20) - 0xaa01U < 2))
  {
    uVar2 = param_1[2];
    *(undefined8 *)param_3 = param_1[1];
    *(undefined8 *)(param_3 + 2) = uVar2;
    uVar2 = param_1[4];
    *(undefined8 *)(param_3 + 4) = param_1[3];
    *(undefined8 *)(param_3 + 6) = uVar2;
    *(undefined8 *)(param_3 + 8) = param_1[5];
    if ((((*param_3 == 0x33484400) && (uVar1 = param_3[1], uVar1 - 0x200 < 0xe01)) &&
        (((uVar1 & 0x3f) == 0 && (((uint)param_3[3] <= uVar1 && ((uint)param_3[2] <= uVar1)))))) &&
       ((ulonglong)(param_3[3] + 7U >> 3) + (ulonglong)((uVar1 >> 3) * 3) + 0x30 <=
        (ulonglong)param_2)) {
      return 0;
    }
  }
  return 0x80090003;
}



===== CNG_BinToHex @ 18001c004 =====

undefined8
CNG_BinToHex(byte *param_1,uint param_2,int param_3,wchar_t *param_4,uint param_5,int *param_6)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  undefined8 uVar4;
  
  uVar4 = 0;
  iVar3 = 0;
  *param_6 = 0;
  if (param_5 < param_2 * 2) {
    uVar4 = 0x80090028;
  }
  else {
    if (param_3 != 0) {
      param_1 = param_1 + param_2;
    }
    if (param_2 != 0) {
      iVar3 = param_2 * 2;
      do {
        param_2 = param_2 - 1;
        pbVar2 = param_1 + -1;
        if (param_3 == 0) {
          pbVar2 = param_1;
        }
        bVar1 = *pbVar2;
        *param_4 = L"0123456789abcdef"[bVar1 >> 4];
        pbVar2 = param_1 + 1;
        param_4[1] = L"0123456789abcdef"[bVar1 & 0xf];
        param_4 = param_4 + 2;
        param_1 = param_1 + -1;
        if (param_3 == 0) {
          param_1 = pbVar2;
        }
      } while (param_2 != 0);
    }
    *param_6 = iVar3;
  }
  return uVar4;
}



===== Feature_690454842__private_IsEnabledDeviceUsageNoInline @ 18001c0c4 =====

uint Feature_690454842__private_IsEnabledDeviceUsageNoInline(void)

{
  uint uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_690454842__private_featureState;
  if ((Feature_690454842__private_featureState & 0x10) == 0) {
    uVar1 = wil_details_IsEnabledFallback(local_res8,3,&Feature_690454842__private_descriptor);
    return uVar1;
  }
  return Feature_690454842__private_featureState & 1;
}



===== NCryptDuplicateKeyProtectorHandle @ 18001c110 =====

undefined8 NCryptDuplicateKeyProtectorHandle(int *param_1,undefined8 *param_2,undefined8 param_3)

{
  int *piVar1;
  int iVar2;
  undefined1 uVar3;
  undefined8 uVar4;
  undefined1 uVar5;
  
                    /* 0x1c110  73  NCryptDuplicateKeyProtectorHandle */
  if ((param_1 == (int *)0x0) || (*param_1 != 0x48)) {
    uVar4 = 0x80090026;
    uVar5 = 0xe;
    uVar3 = 0x26;
  }
  else {
    if (param_2 != (undefined8 *)0x0) {
      LOCK();
      piVar1 = param_1 + 1;
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + 1;
      UNLOCK();
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((WPP_GLOBAL_Control[0x1c] & 0x20) != 0)) {
        WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0xb,param_3,param_1,
                  (char)iVar2 + '\x01');
      }
      *param_2 = param_1;
      return 0;
    }
    uVar4 = 0x80090027;
    uVar5 = 0x15;
    uVar3 = 0x27;
  }
  DebugTraceError(uVar3,"Status",
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\router.c",uVar5
                 );
  return uVar4;
}



===== NCryptGetProtectionDescriptorInfo @ 18001c1d0 =====

HRESULT NCryptGetProtectionDescriptorInfo
                  (int *param_1,undefined *param_2,int param_3,undefined8 *param_4)

{
  HRESULT HVar1;
  undefined *puVar2;
  undefined1 uVar3;
  
                    /* 0x1c1d0  84  NCryptGetProtectionDescriptorInfo */
  if (param_4 == (undefined8 *)0x0) {
    HVar1 = -0x7ff6ffd9;
    uVar3 = 0x1e;
  }
  else if ((param_1 == (int *)0x0) || (*param_1 != 0x28)) {
    HVar1 = -0x7ff6ffda;
    uVar3 = 0x27;
  }
  else {
    *param_4 = 0;
    puVar2 = &NCryptDefaultAllocPara;
    if (param_2 != (undefined *)0x0) {
      puVar2 = param_2;
    }
    if (param_3 == 1) {
      HVar1 = CNG_DescriptorInfoToString(*(uint **)(param_1 + 2),(longlong)puVar2,param_4);
      if (HVar1 == 0) {
        return 0;
      }
      uVar3 = 0x3e;
    }
    else {
      HVar1 = -0x7ff6ffd7;
      uVar3 = 0x48;
    }
  }
  DebugTraceError((char)HVar1,"Status",
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\ncryptprotect.c"
                  ,uVar3);
  return HVar1;
}



===== NCryptQueryProtectionDescriptorName @ 18001c280 =====

uint NCryptQueryProtectionDescriptorName
               (LPCWSTR param_1,LPBYTE param_2,ulonglong *param_3,ulonglong param_4)

{
  uint uVar1;
  ulonglong uVar2;
  undefined1 uVar3;
  DWORD local_res8 [2];
  DWORD local_res18 [4];
  HKEY local_38 [2];
  
                    /* 0x1c280  95  NCryptQueryProtectionDescriptorName */
  uVar2 = *param_3;
  local_38[0] = (HKEY)0x0;
  local_res18[0] = 0;
  local_res8[0] = 0;
  *param_3 = 0;
  if ((param_1 == (LPCWSTR)0x0) || (*param_1 == L'\0')) {
    uVar1 = 0x80090027;
    uVar3 = 0x62;
  }
  else if ((param_4 & 0xffffffdf) == 0) {
    uVar1 = RegOpenKeyExW((HKEY)((ulonglong)((param_4 & 0x20) != 0) - 0x7fffffff),
                          L"Software\\Microsoft\\Cryptography\\NProtect\\NamedDescriptors",0,0x20019
                          ,local_38);
    if (uVar1 == 0) {
      local_res8[0] = (int)uVar2 * 2;
      uVar1 = RegQueryValueExW(local_38[0],param_1,(LPDWORD)0x0,local_res18,param_2,local_res8);
      if (uVar1 == 0) {
        uVar2 = (ulonglong)(local_res8[0] >> 1);
        *param_3 = uVar2;
        if ((param_2 != (LPBYTE)0x0) && (uVar2 != 0)) {
          (param_2 + uVar2 * 2 + -2)[0] = '\0';
          (param_2 + uVar2 * 2 + -2)[1] = '\0';
        }
        uVar1 = 0;
        goto LAB_18001c3c4;
      }
      if (0 < (int)uVar1) {
        uVar1 = uVar1 & 0xffff | 0x80070000;
      }
      uVar3 = 0x91;
    }
    else {
      if (0 < (int)uVar1) {
        uVar1 = uVar1 & 0xffff | 0x80070000;
      }
      uVar3 = 0x80;
    }
  }
  else {
    uVar1 = 0x80090009;
    uVar3 = 0x69;
  }
  DebugTraceError((char)uVar1,"Status",
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\reg.c",uVar3);
LAB_18001c3c4:
  if (local_38[0] != (HKEY)0x0) {
    RegCloseKey(local_38[0]);
  }
  return uVar1;
}



===== NCryptRegisterProtectionDescriptorName @ 18001c400 =====

uint NCryptRegisterProtectionDescriptorName(LPCWSTR param_1,short *param_2,ulonglong param_3)

{
  uint uVar1;
  longlong lVar2;
  undefined1 uVar3;
  DWORD local_res8 [2];
  HKEY local_res20;
  
                    /* 0x1c400  96  NCryptRegisterProtectionDescriptorName */
  local_res20 = (HKEY)0x0;
  local_res8[0] = 0;
  if ((param_1 == (LPCWSTR)0x0) || (*param_1 == L'\0')) {
    uVar1 = 0x80090027;
    uVar3 = 0xeb;
  }
  else if ((param_3 & 0xffffffdf) == 0) {
    uVar1 = RegCreateKeyExW((HKEY)((ulonglong)((param_3 & 0x20) != 0) - 0x7fffffff),
                            L"Software\\Microsoft\\Cryptography\\NProtect\\NamedDescriptors",0,
                            (LPWSTR)0x0,0,0x20006,(LPSECURITY_ATTRIBUTES)0x0,&local_res20,local_res8
                           );
    if (uVar1 == 0) {
      if ((param_2 == (short *)0x0) || (*param_2 == 0)) {
        uVar1 = RegDeleteValueW(local_res20,param_1);
        if (uVar1 == 0) goto LAB_18001c550;
        if (0 < (int)uVar1) {
          uVar1 = uVar1 & 0xffff | 0x80070000;
        }
        uVar3 = 0x1b;
      }
      else {
        lVar2 = -1;
        do {
          lVar2 = lVar2 + 1;
        } while (param_2[lVar2] != 0);
        uVar1 = RegSetValueExW(local_res20,param_1,0,1,(BYTE *)param_2,(int)lVar2 * 2 + 2);
        if (uVar1 == 0) {
LAB_18001c550:
          uVar1 = 0;
          goto LAB_18001c577;
        }
        if (0 < (int)uVar1) {
          uVar1 = uVar1 & 0xffff | 0x80070000;
        }
        uVar3 = 0x2c;
      }
    }
    else {
      if (0 < (int)uVar1) {
        uVar1 = uVar1 & 0xffff | 0x80070000;
      }
      uVar3 = 0xe;
    }
  }
  else {
    uVar1 = 0x80090009;
    uVar3 = 0xf2;
  }
  DebugTraceError((char)uVar1,"Status",
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\reg.c",uVar3);
LAB_18001c577:
  if (local_res20 != (HKEY)0x0) {
    RegCloseKey(local_res20);
  }
  return uVar1;
}



===== NCryptStreamOpenToUnprotectEx @ 18001c5b0 =====

ulonglong NCryptStreamOpenToUnprotectEx
                    (longlong *param_1,uint param_2,undefined8 param_3,longlong *param_4)

{
  longlong lVar1;
  ulonglong uVar2;
  undefined1 uVar3;
  char *pcVar4;
  ulonglong uVar5;
  char *pcVar6;
  undefined1 uVar7;
  longlong local_res20;
  
                    /* 0x1c5b0  104  NCryptStreamOpenToUnprotectEx */
  local_res20 = 0;
  if (((param_4 == (longlong *)0x0) || (param_1 == (longlong *)0x0)) || (*param_1 == 0)) {
    uVar5 = 0x80090027;
    uVar3 = 0x27;
    uVar7 = 0xed;
  }
  else {
    if ((param_2 & 0xffffff3e) != 0) {
      DebugTraceError(9,"Status",
                      "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\stream.c",
                      0xf4);
      return 0x80090009;
    }
    uVar2 = I_StreamOpenToUnprotect(param_2,param_3,&local_res20);
    uVar5 = uVar2 & 0xffffffff;
    if ((int)uVar2 == 0) {
      lVar1 = param_1[1];
      *(longlong *)(local_res20 + 0x10) = *param_1;
      *(longlong *)(local_res20 + 0x18) = lVar1;
      *(undefined4 *)(local_res20 + 0x20) = 1;
      *param_4 = local_res20;
      return 0;
    }
    uVar3 = (undefined1)uVar2;
    uVar7 = 0xfb;
  }
  lVar1 = local_res20;
  pcVar6 = "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\stream.c";
  pcVar4 = "Status";
  DebugTraceError(uVar3,"Status",
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\stream.c",uVar7
                 );
  if (lVar1 != 0) {
    I_StreamFree(lVar1,pcVar4,pcVar6);
  }
  return uVar5;
}



===== CNG_DescriptorInfoToString @ 18001c6a0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

HRESULT CNG_DescriptorInfoToString(uint *param_1,longlong param_2,undefined8 *param_3)

{
  HRESULT HVar1;
  longlong lVar2;
  STRSAFE_LPWSTR _Dst;
  uint uVar3;
  STRSAFE_LPWSTR pszDest;
  longlong lVar4;
  size_t cchDest;
  uint *puVar5;
  undefined1 uVar6;
  uint uVar7;
  longlong *plVar8;
  ulonglong uVar9;
  size_t local_res8;
  longlong local_res10;
  STRSAFE_LPWSTR local_res18;
  undefined8 uVar10;
  
  cchDest = 1;
  *param_3 = 0;
  local_res8 = 1;
  uVar3 = 0;
  if (*param_1 != 0) {
    puVar5 = *(uint **)(param_1 + 2);
    do {
      if (uVar3 != 0) {
        cchDest = cchDest + 2;
        local_res8 = cchDest;
      }
      uVar7 = 0;
      if (*puVar5 != 0) {
        plVar8 = *(longlong **)(puVar5 + 2);
        do {
          if (uVar7 != 0) {
            cchDest = cchDest + 3;
          }
          lVar4 = -1;
          do {
            lVar4 = lVar4 + 1;
          } while (*(short *)(plVar8[1] + lVar4 * 2) != 0);
          lVar2 = -1;
          do {
            lVar2 = lVar2 + 1;
          } while (*(short *)(*plVar8 + lVar2 * 2) != 0);
          uVar7 = uVar7 + 1;
          plVar8 = plVar8 + 4;
          cchDest = cchDest + 1 + lVar2 + lVar4;
        } while (uVar7 < *puVar5);
        local_res8 = cchDest;
      }
      uVar3 = uVar3 + 1;
      puVar5 = puVar5 + 8;
    } while (uVar3 < *param_1);
  }
  local_res10 = param_2;
  _Dst = (STRSAFE_LPWSTR)(**(code **)(param_2 + 8))(cchDest * 2);
  if (_Dst == (STRSAFE_LPWSTR)0x0) {
    HVar1 = -0x7ff6fff2;
    DebugTraceError(0xe,"Status",
                    "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\descriptor.c"
                    ,0xd);
  }
  else {
    memset(_Dst,0,cchDest * 2);
    uVar3 = 0;
    pszDest = _Dst;
    local_res18 = _Dst;
    while (uVar9 = 0, uVar3 < *param_1) {
      lVar4 = (ulonglong)uVar3 * 0x20;
      while( true ) {
        if (*(uint *)(*(longlong *)(param_1 + 2) + lVar4) <= (uint)uVar9) break;
        lVar2 = *(longlong *)(*(longlong *)(param_1 + 2) + 8 + lVar4);
        uVar10 = *(undefined8 *)(uVar9 * 0x20 + 8 + lVar2);
        HVar1 = StringCchPrintfExW(pszDest,cchDest,&local_res18,&local_res8,0,L"%ls=%ls",
                                   *(undefined8 *)(uVar9 * 0x20 + lVar2),uVar10);
        if (HVar1 < 0) {
          uVar6 = 0x29;
          goto LAB_18001c8c9;
        }
        uVar7 = (uint)uVar9 + 1;
        uVar9 = (ulonglong)uVar7;
        if ((uVar7 < *(uint *)(lVar4 + *(longlong *)(param_1 + 2))) &&
           (HVar1 = StringCchPrintfExW(local_res18,local_res8,&local_res18,&local_res8,0,L"%ls",
                                       L"AND",uVar10), HVar1 < 0)) {
          uVar6 = 0x3a;
          goto LAB_18001c8c9;
        }
        pszDest = local_res18;
        cchDest = local_res8;
      }
      uVar3 = uVar3 + 1;
      if (uVar3 < *param_1) {
        HVar1 = StringCchPrintfExW(pszDest,cchDest,&local_res18,&local_res8,0,L"%ls",L"OR");
        if (HVar1 < 0) {
          uVar6 = 0x4d;
LAB_18001c8c9:
          DebugTraceError((char)HVar1,"Status",
                          "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\descriptor.c"
                          ,uVar6);
          (**(code **)(local_res10 + 0x10))(_Dst);
          return HVar1;
        }
        pszDest = local_res18;
        cchDest = local_res8;
      }
    }
    *param_3 = _Dst;
    HVar1 = 0;
  }
  return HVar1;
}



===== I_GetDescriptorFromAndCombiner @ 18001c918 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong I_GetDescriptorFromAndCombiner(int *param_1,undefined8 param_2,undefined8 *param_3)

{
  undefined8 *_Dst;
  int iVar1;
  longlong *plVar2;
  HLOCAL pvVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  undefined8 uVar7;
  char *pcVar8;
  undefined1 uVar9;
  longlong lVar10;
  int *piVar11;
  ulonglong uVar12;
  ulonglong uVar13;
  undefined1 uVar14;
  undefined1 auStack_278 [32];
  ulonglong local_258;
  undefined8 local_250;
  undefined *local_248;
  HLOCAL *local_240;
  HLOCAL local_238;
  uint local_230 [2];
  undefined8 *local_228;
  undefined8 local_220;
  undefined8 *puStack_218;
  ulonglong local_210;
  ulonglong local_208;
  HLOCAL apvStack_200 [8];
  HLOCAL apvStack_1c0 [8];
  undefined8 auStack_180 [9];
  undefined8 local_138 [32];
  ulonglong local_38;
  
  _Dst = auStack_180 + 1;
  local_38 = __security_cookie ^ (ulonglong)auStack_278;
  local_230[1] = 0;
  local_210 = 0;
  local_208 = local_208 & 0xffffffff00000000;
  local_220 = 0;
  puStack_218 = (undefined8 *)0x0;
  memset(local_138,0,0x100);
  local_238 = (HLOCAL)0x0;
  memset(apvStack_200 + 1,0,0x40);
  memset(apvStack_1c0 + 1,0,0x40);
  memset(_Dst,0,0x40);
  *param_3 = 0;
  if ((*param_1 == 5) && (param_1[2] == 0xc)) {
    lVar10 = **(longlong **)(param_1 + 4) + 0x7dfefbfef9d4f5fa;
    if (lVar10 == 0) {
      lVar10 = (ulonglong)*(uint *)(*(longlong **)(param_1 + 4) + 1) - 0x4014a37;
    }
    if (lVar10 != 0) goto LAB_18001cd08;
    local_258 = (ulonglong)(uint)param_1[6];
    local_240 = &local_238;
    local_248 = &NCryptDefaultAllocPara;
    local_250 = 0;
    piVar11 = (int *)0x1d;
    uVar4 = Ordinal_4(ASN1_NCRYPT_MODULE_HANDLE,0x1d,1,*(undefined8 *)(param_1 + 8));
    uVar12 = (ulonglong)uVar4;
    if (uVar4 == 0) {
      local_228 = &local_220;
      local_208 = 0;
      local_210 = local_210 & 0xffffffff00000000;
      puStack_218 = local_138;
      local_230[0] = 1;
      if (*(uint *)((longlong)local_238 + 4) < 9) {
        uVar13 = 0;
        while (uVar4 = (uint)uVar13, uVar4 < *(uint *)((longlong)local_238 + 4)) {
          piVar6 = (int *)(uVar13 * 0xa0 + *(longlong *)((longlong)local_238 + 8));
          iVar1 = *piVar6;
          if ((iVar1 != 1) && (iVar1 != 2)) {
            if (iVar1 == 3) {
              piVar11 = *(int **)(piVar6 + 10);
              if ((piVar11 != (int *)0x0) && (*piVar11 == 0xb)) {
                plVar2 = *(longlong **)(piVar11 + 2);
                lVar10 = *plVar2 + 0x7dfefbfef9d4f6fa;
                if ((lVar10 == 0) &&
                   (lVar10 = (ulonglong)*(ushort *)(plVar2 + 1) - 18999, lVar10 == 0)) {
                  lVar10 = (ulonglong)*(byte *)((longlong)plVar2 + 10) - 1;
                }
                if (lVar10 == 0) {
                  local_258 = (ulonglong)(uint)piVar11[4];
                  local_248 = &NCryptDefaultAllocPara;
                  local_250 = 0;
                  local_240 = apvStack_200 + uVar13 + 1;
                  uVar5 = Ordinal_4(ASN1_NCRYPT_MODULE_HANDLE,1,0x200001,
                                    *(undefined8 *)(piVar11 + 6));
                  uVar12 = (ulonglong)uVar5;
                  if (uVar5 == 0) {
                    pvVar3 = apvStack_200[uVar13 + 1];
                    local_258 = (ulonglong)*(uint *)((longlong)pvVar3 + 0x10);
                    local_248 = &NCryptDefaultAllocPara;
                    local_250 = 0;
                    local_240 = apvStack_1c0 + uVar13 + 1;
                    uVar5 = Ordinal_4(ASN1_NCRYPT_MODULE_HANDLE,0x1c,1,
                                      *(undefined8 *)((longlong)pvVar3 + 0x18));
                    uVar12 = (ulonglong)uVar5;
                    if (uVar5 == 0) {
                      piVar11 = apvStack_1c0[uVar13 + 1];
                      if ((*piVar11 != 1) || (**(int **)(piVar11 + 2) != 1)) {
                        uVar14 = 0xb0;
                        goto LAB_18001cc82;
                      }
                      local_138[uVar13 * 4] = **(undefined8 **)(*(int **)(piVar11 + 2) + 2);
                      uVar7 = *(undefined8 *)(*(longlong *)(*(longlong *)(piVar11 + 2) + 8) + 8);
                      goto LAB_18001cc38;
                    }
                    uVar14 = 0xa8;
                  }
                  else {
                    uVar14 = 0x98;
                  }
                  goto LAB_18001cc58;
                }
              }
              uVar14 = 0x84;
            }
            else {
              uVar14 = 0xbc;
            }
LAB_18001cc82:
            uVar12 = 0x80090029;
            uVar9 = 0x29;
            goto LAB_18001cc8c;
          }
          if (*piVar6 == 1) {
            piVar6 = piVar6 + 4;
          }
          else {
            if (piVar6[0x24] != 1) {
              uVar14 = 100;
              goto LAB_18001cc82;
            }
            piVar6 = *(int **)(piVar6 + 0x26);
          }
          uVar5 = I_GetRecipientIdString(piVar6,(ulonglong)piVar11,_Dst + uVar13);
          uVar12 = (ulonglong)uVar5;
          if (uVar5 != 0) {
            uVar14 = 0x72;
            goto LAB_18001cc58;
          }
          local_138[uVar13 * 4] = L"CERTIFICATE";
          uVar7 = _Dst[uVar13];
LAB_18001cc38:
          local_138[uVar13 * 4 + 1] = uVar7;
          uVar13 = (ulonglong)(uVar4 + 1);
        }
        local_220 = CONCAT44(local_220._4_4_,uVar4);
        pcVar8 = CNG_DuplicateDescriptor(local_230,param_3,0);
        uVar5 = (uint)pcVar8;
        uVar12 = (ulonglong)pcVar8 & 0xffffffff;
        if (uVar5 == 0) {
          uVar12 = 0;
        }
        else {
          uVar14 = 0xcc;
LAB_18001cc58:
          uVar9 = (undefined1)uVar5;
LAB_18001cc8c:
          DebugTraceError(uVar9,"Status",
                          "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\descriptor.c"
                          ,uVar14);
        }
        if (uVar4 != 0) {
          lVar10 = uVar13 << 3;
          do {
            uVar4 = (int)uVar13 - 1;
            uVar13 = (ulonglong)uVar4;
            if (*(HLOCAL *)((longlong)apvStack_200 + lVar10) != (HLOCAL)0x0) {
              I_DefaultExtrenalFree(*(HLOCAL *)((longlong)apvStack_200 + lVar10));
            }
            if (*(HLOCAL *)((longlong)apvStack_1c0 + lVar10) != (HLOCAL)0x0) {
              I_DefaultExtrenalFree(*(HLOCAL *)((longlong)apvStack_1c0 + lVar10));
            }
            pvVar3 = *(HLOCAL *)((longlong)_Dst + lVar10 + -8);
            if (pvVar3 != (HLOCAL)0x0) {
              I_DefaultExtrenalFree(pvVar3);
            }
            lVar10 = lVar10 + -8;
          } while (uVar4 != 0);
        }
        goto LAB_18001cd2b;
      }
      uVar12 = 0x80090005;
      uVar9 = 0x4a;
      uVar14 = 5;
    }
    else {
      uVar9 = 0x39;
      uVar14 = (undefined1)uVar4;
    }
  }
  else {
LAB_18001cd08:
    uVar12 = 0x80090029;
    uVar9 = 0x29;
    uVar14 = 0x29;
  }
  DebugTraceError(uVar14,"Status",
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\ncryptprotect\\descriptor.c",
                  uVar9);
LAB_18001cd2b:
  if (local_238 != (HLOCAL)0x0) {
    I_DefaultExtrenalFree(local_238);
  }
  return uVar12;
}



===== StringExHandleFillBehindNullW @ 18001cd70 =====

HRESULT __stdcall
StringExHandleFillBehindNullW(STRSAFE_LPWSTR pszDestEnd,size_t cbRemaining,DWORD dwFlags)

{
  if (2 < cbRemaining) {
    memset(pszDestEnd + 1,dwFlags & 0xff,cbRemaining - 2);
  }
  return 0;
}



===== StringExHandleOtherFlagsW @ 18001cd9c =====

HRESULT __stdcall
StringExHandleOtherFlagsW
          (STRSAFE_LPWSTR pszDest,size_t cbDest,size_t cchOriginalDestLength,
          STRSAFE_LPWSTR *ppszDestEnd,size_t *pcchRemaining,DWORD dwFlags)

{
  ulonglong uVar1;
  
  uVar1 = cbDest >> 1;
  if ((uVar1 != 0) && ((dwFlags & 0x1000) != 0)) {
    *ppszDestEnd = pszDest;
    *pcchRemaining = uVar1;
    *pszDest = L'\0';
  }
  if ((dwFlags & 0x400) != 0) {
    memset(pszDest,dwFlags & 0xff,cbDest);
    if ((char)dwFlags != '\0') {
      if (uVar1 == 0) {
        return 0;
      }
      *pcchRemaining = 1;
      *ppszDestEnd = pszDest + (uVar1 - 1);
      pszDest[uVar1 - 1] = L'\0';
      goto LAB_18001ce07;
    }
    *ppszDestEnd = pszDest;
    *pcchRemaining = uVar1;
  }
  if (uVar1 == 0) {
    return 0;
  }
LAB_18001ce07:
  if ((dwFlags & 0x800) != 0) {
    *ppszDestEnd = pszDest;
    *pcchRemaining = uVar1;
    *pszDest = L'\0';
  }
  return 0;
}



===== _resetstkoflw_static @ 18001ce5c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool _resetstkoflw_static(void)

{
  PVOID pvVar1;
  DWORD DVar2;
  BOOL BVar3;
  uint uVar4;
  SIZE_T SVar5;
  LPVOID pvVar6;
  uint uVar7;
  ulonglong uVar8;
  LPVOID lpAddress;
  undefined1 local_98 [16];
  ULONG local_88;
  DWORD local_84;
  _MEMORY_BASIC_INFORMATION local_80;
  _SYSTEM_INFO local_50;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)&local_88;
  local_80.BaseAddress = (PVOID)0x0;
  local_80.AllocationBase = (PVOID)0x0;
  local_84 = 0;
  local_80.AllocationProtect = 0;
  local_80._20_4_ = 0;
  local_80.RegionSize = 0;
  local_88 = 0;
  local_80.State = 0;
  local_80.Protect = 0;
  local_80.Type = 0;
  local_80._44_4_ = 0;
  local_50.u.dwOemId = 0;
  local_50.dwPageSize = 0;
  local_50.lpMinimumApplicationAddress = (LPVOID)0x0;
  local_50.lpMaximumApplicationAddress = (LPVOID)0x0;
  local_50.dwActiveProcessorMask = 0;
  local_50.dwNumberOfProcessors = 0;
  local_50.dwProcessorType = 0;
  local_50.dwAllocationGranularity = 0;
  local_50.wProcessorLevel = 0;
  local_50.wProcessorRevision = 0;
  SVar5 = VirtualQuery(local_98,&local_80,0x30);
  pvVar1 = local_80.AllocationBase;
  if (SVar5 != 0) {
    GetSystemInfo(&local_50);
    DVar2 = local_50.dwPageSize;
    uVar8 = (ulonglong)local_50.dwPageSize;
    BVar3 = SetThreadStackGuarantee(&local_88);
    uVar4 = 0;
    if ((BVar3 == 1) && (uVar4 = 0, local_88 != 0)) {
      uVar4 = local_88;
    }
    uVar7 = (DVar2 - 1) + uVar4;
    if (uVar4 <= uVar7) {
      uVar7 = uVar7 & ~(DVar2 - 1);
      uVar4 = uVar7;
      if ((uVar7 != 0) && (uVar4 = uVar7 + DVar2, uVar4 < uVar7)) {
        return false;
      }
      uVar7 = DVar2 * 3;
      if (DVar2 * 3 <= uVar4) {
        uVar7 = uVar4;
      }
      lpAddress = (LPVOID)((~(ulonglong)(DVar2 - 1) & (ulonglong)local_98) - (ulonglong)uVar7);
      if (((LPVOID)((longlong)pvVar1 + uVar8) <= lpAddress) &&
         (pvVar6 = VirtualAlloc(lpAddress,(ulonglong)uVar7,0x1000,4), pvVar6 != (LPVOID)0x0)) {
        BVar3 = VirtualProtect(lpAddress,(ulonglong)uVar7,0x104,&local_84);
        return BVar3 != 0;
      }
    }
  }
  return false;
}



===== CertInUseNonzeroAlloc @ 18001cfe4 =====

LPVOID CertInUseNonzeroAlloc(SIZE_T param_1)

{
  HANDLE hHeap;
  LPVOID pvVar1;
  
  if (param_1 == 0) {
    return (LPVOID)0x0;
  }
  hHeap = GetProcessHeap();
                    /* WARNING: Could not recover jumptable at 0x00018001d00b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = HeapAlloc(hHeap,0,param_1);
  return pvVar1;
}



===== CertInUseZeroAlloc @ 18001d028 =====

LPVOID CertInUseZeroAlloc(SIZE_T param_1)

{
  HANDLE hHeap;
  LPVOID pvVar1;
  
  if (param_1 == 0) {
    return (LPVOID)0x0;
  }
  hHeap = GetProcessHeap();
                    /* WARNING: Could not recover jumptable at 0x00018001d052. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = HeapAlloc(hHeap,8,param_1);
  return pvVar1;
}



===== Feature_Fix_CIU_Get_Module_Name_OOBR__private_IsEnabledDeviceUsageNoInline @ 18001d070 =====

uint Feature_Fix_CIU_Get_Module_Name_OOBR__private_IsEnabledDeviceUsageNoInline(void)

{
  uint uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_Fix_CIU_Get_Module_Name_OOBR__private_featureState;
  if ((Feature_Fix_CIU_Get_Module_Name_OOBR__private_featureState & 0x10) == 0) {
    uVar1 = wil_details_IsEnabledFallback
                      (local_res8,3,&Feature_Fix_CIU_Get_Module_Name_OOBR__private_descriptor);
    return uVar1;
  }
  return Feature_Fix_CIU_Get_Module_Name_OOBR__private_featureState & 1;
}



===== FiletimeToString @ 18001d0b4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

DWORD FiletimeToString(FILETIME param_1,undefined8 *param_2)

{
  BOOL BVar1;
  DWORD DVar2;
  int iVar3;
  STRSAFE_LPWSTR pszDest;
  undefined1 auStackY_a8 [32];
  FILETIME local_68;
  _SYSTEMTIME local_60;
  WCHAR local_50 [32];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_a8;
  *param_2 = 0;
  local_50[0x10] = L'\0';
  local_50[0x11] = L'\0';
  local_50[0x12] = L'\0';
  local_50[0x13] = L'\0';
  local_50[0x14] = L'\0';
  local_50[0x15] = L'\0';
  local_50[0x16] = L'\0';
  local_50[0x17] = L'\0';
  local_50[0x18] = L'\0';
  local_50[0x19] = L'\0';
  local_50[0x1a] = L'\0';
  local_50[0x1b] = L'\0';
  local_50[0x1c] = L'\0';
  local_50[0x1d] = L'\0';
  local_50[0x1e] = L'\0';
  local_50[0x1f] = L'\0';
  local_50[0] = L'\0';
  local_50[1] = L'\0';
  local_50[2] = L'\0';
  local_50[3] = L'\0';
  local_50[4] = L'\0';
  local_50[5] = L'\0';
  local_50[6] = L'\0';
  local_50[7] = L'\0';
  local_50[8] = L'\0';
  local_50[9] = L'\0';
  local_50[10] = L'\0';
  local_50[0xb] = L'\0';
  local_50[0xc] = L'\0';
  local_50[0xd] = L'\0';
  local_50[0xe] = L'\0';
  local_50[0xf] = L'\0';
  local_60.wYear = 0;
  local_60.wMonth = 0;
  local_60.wDayOfWeek = 0;
  local_60.wDay = 0;
  local_60.wHour = 0;
  local_60.wMinute = 0;
  local_60.wSecond = 0;
  local_60.wMilliseconds = 0;
  local_68 = param_1;
  BVar1 = FileTimeToSystemTime(&local_68,&local_60);
  if (((BVar1 == 0) ||
      (iVar3 = GetDateFormatEx(L"",0,&local_60,L"yyyy-MM-dd",local_50 + 0x10,0x10,(LPCWSTR)0x0),
      iVar3 == 0)) ||
     (iVar3 = GetTimeFormatEx(L"",0,&local_60,L"HH:mm:ss",local_50,0x10), iVar3 == 0)) {
    DVar2 = GetLastError();
  }
  else {
    pszDest = CertInUseZeroAlloc(0x44);
    *param_2 = pszDest;
    if (pszDest == (STRSAFE_LPWSTR)0x0) {
      DVar2 = 0x8009000e;
      goto LAB_18001d1ef;
    }
    DVar2 = StringCchPrintfExW(pszDest,0x22,(STRSAFE_LPWSTR *)0x0,(size_t *)0x0,0x1000,L"%s %s");
    if (-1 < (int)DVar2) {
      return 0;
    }
  }
  if (DVar2 == 0) {
    return 0;
  }
LAB_18001d1ef:
  CertInUseFree(param_2);
  return DVar2;
}



===== GetProcessInfo @ 18001d228 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void GetProcessInfo(void)

{
  ulonglong cchDest;
  undefined8 *puVar1;
  BOOL BVar2;
  DWORD DVar3;
  uint uVar4;
  HRESULT HVar5;
  int iVar6;
  HANDLE hProcess;
  wchar_t *pwVar7;
  undefined8 uVar8;
  STRSAFE_LPWSTR pszDest;
  size_t cchMax;
  wchar_t *psz;
  STRSAFE_PCNZWCH pwVar9;
  undefined1 auStackY_288 [32];
  size_t local_258;
  _FILETIME local_250;
  _FILETIME local_248;
  _FILETIME local_240;
  _FILETIME local_238 [2];
  WCHAR local_228 [260];
  wchar_t local_20 [4];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_288;
  if ((g_pCertInUseProcessInfo == (undefined8 *)0x0) &&
     (g_pCertInUseProcessInfo = CertInUseZeroAlloc(0x18),
     g_pCertInUseProcessInfo == (undefined8 *)0x0)) {
    return;
  }
  local_250.dwLowDateTime = 0;
  local_250.dwHighDateTime = 0;
  local_238[0].dwLowDateTime = 0;
  local_238[0].dwHighDateTime = 0;
  local_240.dwLowDateTime = 0;
  local_240.dwHighDateTime = 0;
  local_248.dwLowDateTime = 0;
  local_248.dwHighDateTime = 0;
  hProcess = GetCurrentProcess();
  BVar2 = GetProcessTimes(hProcess,&local_250,local_238,&local_240,&local_248);
  if ((BVar2 != 0) && (DVar3 = FiletimeToString(local_250,g_pCertInUseProcessInfo + 1), DVar3 != 0))
  {
    CertInUseFree(g_pCertInUseProcessInfo + 1);
  }
  memset(local_228,0,0x208);
  DVar3 = GetModuleFileNameW((HMODULE)0x0,local_228,0x104);
  if (DVar3 != 0) {
    uVar4 = Feature_Fix_CIU_Get_Module_Name_OOBR__private_IsEnabledDeviceUsageNoInline();
    cchMax = 0x5c;
    if (uVar4 == 0) {
      psz = local_20;
      do {
        if (*psz == L'\\') goto LAB_18001d350;
        psz = psz + -1;
      } while (psz != local_228);
      if (*psz == L'\\') {
LAB_18001d350:
        psz = psz + 1;
      }
    }
    else {
      pwVar7 = wcsrchr(local_228,L'\\');
      psz = pwVar7 + 1;
      if (pwVar7 == (wchar_t *)0x0) {
        psz = local_228;
      }
    }
    local_258 = 0;
    HVar5 = StringCchLengthW(psz,cchMax,&local_258);
    if (((-1 < HVar5) && (cchDest = local_258 + 1, local_258 <= cchDest)) &&
       (local_258 = cchDest, uVar8 = ULongLongMult(cchDest,cchMax,&local_258), -1 < (int)uVar8)) {
      pszDest = CertInUseZeroAlloc(local_258);
      *g_pCertInUseProcessInfo = pszDest;
      if (pszDest != (STRSAFE_LPWSTR)0x0) {
        pwVar9 = psz;
        StringCchCopyW(pszDest,cchDest,psz);
        iVar6 = _wcsicmp(psz,L"svchost.exe");
        if ((iVar6 != 0) && (iVar6 = _wcsicmp(psz,L"dllhost.exe"), iVar6 != 0)) {
          return;
        }
        puVar1 = g_pCertInUseProcessInfo;
        DVar3 = GetCurrentProcessId();
        iVar6 = GetServiceTag(DVar3,puVar1 + 2,(SIZE_T)pwVar9);
        if (iVar6 != 0) {
          CertInUseFree(g_pCertInUseProcessInfo + 2);
        }
      }
    }
  }
  return;
}



===== GetServiceTag @ 18001d474 =====

int GetServiceTag(uint param_1,undefined8 *param_2,SIZE_T param_3)

{
  undefined8 *puVar1;
  STRSAFE_PCNZWCH psz;
  STRSAFE_LPCWSTR pszSrc;
  bool bVar2;
  uint *puVar3;
  int iVar4;
  HRESULT HVar5;
  undefined8 uVar6;
  LPVOID pvVar7;
  ulonglong uVar8;
  size_t cchMax;
  uint uVar9;
  ulonglong uVar10;
  uint *puVar11;
  ulonglong cchDest;
  size_t local_res18 [2];
  ulonglong local_58;
  uint *puStack_50;
  
  puStack_50 = (uint *)0x0;
  local_58 = (ulonglong)param_1;
  cchMax = 3;
  local_res18[0] = param_3;
  iVar4 = I_QueryTagInformation(0,3,&local_58);
  puVar3 = puStack_50;
  puVar11 = (uint *)0x0;
  if (iVar4 == 0) {
    puVar11 = puVar3;
    if (puStack_50 == (uint *)0x0) {
      iVar4 = 0x490;
    }
    else {
      cchDest = 0;
      bVar2 = true;
      for (uVar10 = 0; (uint)uVar10 < *puVar3; uVar10 = (ulonglong)((int)uVar10 + 1)) {
        puVar1 = (undefined8 *)(*(longlong *)(puVar3 + 2) + uVar10 * 0x18);
        psz = (STRSAFE_PCNZWCH)puVar1[1];
        if (((int)*puVar1 == 1) && (psz != (STRSAFE_PCNZWCH)0x0)) {
          local_res18[0] = 0;
          HVar5 = StringCchLengthW(psz,cchMax,local_res18);
          if (HVar5 < 0) {
            iVar4 = HVar5;
            goto LAB_18001d5d2;
          }
          uVar8 = local_res18[0] + cchDest;
          if ((uVar8 < cchDest) || (cchDest = uVar8 + 1, cchDest < uVar8)) goto LAB_18001d531;
        }
      }
      if (cchDest != 0) {
        local_res18[0] = 0;
        uVar6 = ULongLongMult(cchDest,cchMax,local_res18);
        if ((int)uVar6 < 0) {
LAB_18001d531:
          iVar4 = 0x216;
          goto LAB_18001d5d2;
        }
        pvVar7 = CertInUseZeroAlloc(local_res18[0]);
        *param_2 = pvVar7;
        if (pvVar7 == (LPVOID)0x0) goto LAB_18001d5d2;
        uVar10 = 0;
        if (*puVar3 != 0) {
          do {
            puVar1 = (undefined8 *)(*(longlong *)(puVar3 + 2) + uVar10 * 0x18);
            pszSrc = (STRSAFE_LPCWSTR)puVar1[1];
            if (((int)*puVar1 == 1) && (pszSrc != (STRSAFE_LPCWSTR)0x0)) {
              if (!bVar2) {
                StringCchCatW((STRSAFE_LPWSTR)*param_2,cchDest,L",");
              }
              StringCchCatW((STRSAFE_LPWSTR)*param_2,cchDest,pszSrc);
              bVar2 = false;
            }
            uVar9 = (int)uVar10 + 1;
            uVar10 = (ulonglong)uVar9;
          } while (uVar9 < *puVar3);
        }
        g_stServiceNameLen = cchDest;
      }
      iVar4 = 0;
    }
  }
LAB_18001d5d2:
  LocalFree(puVar11);
  return iVar4;
}



===== I_GetProcessName @ 18001d604 =====

wchar_t * I_GetProcessName(void)

{
  wchar_t *pwVar1;
  
  InitOnceExecuteOnce((PINIT_ONCE)&DAT_180027d10,_ProcessInfoInitOnceCallback,(PVOID)0x0,
                      (LPVOID *)0x0);
  if ((g_pCertInUseProcessInfo == (longlong *)0x0) ||
     (pwVar1 = (wchar_t *)*g_pCertInUseProcessInfo, pwVar1 == (wchar_t *)0x0)) {
    pwVar1 = L"";
  }
  return pwVar1;
}



===== McTemplateU0z_EventWriteTransfer @ 18001d650 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateU0z_EventWriteTransfer
               (undefined8 param_1,PCEVENT_DESCRIPTOR param_2,wchar_t *param_3)

{
  longlong lVar1;
  undefined1 auStackY_68 [32];
  _EVENT_DATA_DESCRIPTOR local_38;
  wchar_t *local_28;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  if (param_3 == (wchar_t *)0x0) {
    local_20 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_3[lVar1] != L'\0');
    local_20 = (int)lVar1 * 2 + 2;
  }
  local_1c = 0;
  if (param_3 == (wchar_t *)0x0) {
    param_3 = L"NULL";
  }
  local_28 = param_3;
  McGenEventWrite_EventWriteTransfer(L"NULL",param_2,param_3,2,&local_38);
  return;
}



===== StringCchCatW @ 18001d6d4 =====

HRESULT __stdcall StringCchCatW(STRSAFE_LPWSTR pszDest,size_t cchDest,STRSAFE_LPCWSTR pszSrc)

{
  wchar_t wVar1;
  uint uVar2;
  STRSAFE_LPWSTR pwVar3;
  longlong lVar4;
  STRSAFE_LPWSTR pwVar5;
  longlong lVar6;
  longlong lVar7;
  size_t local_res10;
  
  local_res10 = 0;
  if (cchDest - 1 < 0x7fffffff) {
    uVar2 = StringLengthWorkerW(pszDest,cchDest,&local_res10);
    if (-1 < (int)uVar2) {
      pwVar5 = pszDest + local_res10;
      lVar4 = cchDest - local_res10;
      if (lVar4 != 0) {
        lVar7 = local_res10 + 0x7ffffffe + (lVar4 - cchDest);
        lVar6 = (longlong)pszSrc - (longlong)pwVar5;
        do {
          if ((lVar7 == 0) || (wVar1 = *(wchar_t *)(lVar6 + (longlong)pwVar5), wVar1 == L'\0'))
          break;
          *pwVar5 = wVar1;
          lVar7 = lVar7 + -1;
          pwVar5 = pwVar5 + 1;
          lVar4 = lVar4 + -1;
        } while (lVar4 != 0);
      }
      pwVar3 = pwVar5 + -1;
      if (lVar4 != 0) {
        pwVar3 = pwVar5;
      }
      *pwVar3 = L'\0';
      uVar2 = ~-(uint)(lVar4 != 0) & 0x8007007a;
    }
  }
  else {
    uVar2 = 0x80070057;
  }
  return uVar2;
}



===== ULongLongMult @ 18001d788 =====

undefined8 ULongLongMult(ulonglong param_1,undefined8 param_2,undefined8 *param_3)

{
  undefined1 auVar1 [16];
  undefined8 uVar2;
  
  uVar2 = 0;
  auVar1._8_8_ = 0;
  auVar1._0_8_ = param_1;
  if (SUB168(ZEXT816(2) * auVar1,8) == 0) {
    *param_3 = SUB168(ZEXT816(2) * auVar1,0);
  }
  else {
    *param_3 = 0xffffffffffffffff;
    uVar2 = 0x80070216;
  }
  return uVar2;
}



===== _ProcessInfoInitOnceCallback @ 18001d7c0 =====

undefined8 _ProcessInfoInitOnceCallback(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  if (param_3 != (undefined8 *)0x0) {
    *param_3 = 0;
  }
  GetProcessInfo();
  return 1;
}



===== CNG_AesKeyUnwrap @ 18001d7f0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

uint CNG_AesKeyUnwrap(longlong param_1,PUCHAR param_2,ULONG param_3,PUCHAR param_4,ULONG param_5,
                     undefined8 *param_6,uint *param_7)

{
  code *pcVar1;
  longlong lVar2;
  BCRYPT_KEY_HANDLE pvVar3;
  uint uVar4;
  undefined8 uVar5;
  void *_Dst;
  ulonglong uVar6;
  ulonglong uVar7;
  PUCHAR pbOutput;
  undefined1 *puVar8;
  undefined1 *puVar9;
  uint uVar10;
  PUCHAR pUVar11;
  undefined1 uVar12;
  undefined1 auStackY_a8 [32];
  ULONG local_58 [2];
  BCRYPT_KEY_HANDLE local_50;
  BCRYPT_ALG_HANDLE local_48;
  BCRYPT_KEY_HANDLE local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)local_58;
  local_48 = (BCRYPT_ALG_HANDLE)0x0;
  local_40 = (BCRYPT_KEY_HANDLE)0x0;
  local_50 = (BCRYPT_KEY_HANDLE)0x0;
  uVar10 = 0;
  local_58[0] = 0;
  pbOutput = (PUCHAR)0x0;
  uVar4 = CNG_GetBCryptHandle((ushort *)L"AES",&local_48);
  puVar9 = auStackY_a8;
  if ((int)uVar4 < 0) {
    uVar12 = 0xd2;
  }
  else {
    uVar4 = BCryptGenerateSymmetricKey(local_48,&local_40,(PUCHAR)0x0,0,param_4,param_5,0);
    puVar9 = auStackY_a8;
    if ((int)uVar4 < 0) {
      uVar12 = 0xe1;
    }
    else {
      uVar4 = BCryptImportKey(local_48,local_40,L"Rfc3565KeyWrapBlob",&local_50,(PUCHAR)0x0,0,
                              param_2,param_3,0);
      puVar9 = auStackY_a8;
      if ((int)uVar4 < 0) {
        uVar12 = 0xf5;
      }
      else {
        uVar4 = BCryptExportKey(local_50,(BCRYPT_KEY_HANDLE)0x0,L"KeyDataBlob",(PUCHAR)0x0,0,
                                local_58,0);
        puVar9 = auStackY_a8;
        if (-1 < (int)uVar4) {
          uVar7 = (ulonglong)local_58[0];
          puVar8 = auStackY_a8;
          if (((uVar7 == 0) || (puVar8 = auStackY_a8, g_ulMaxStackAllocSize < uVar7)) ||
             (uVar6 = g_ulAdditionalProbeSize + 8 + uVar7, puVar8 = auStackY_a8, uVar6 < uVar7)) {
LAB_18001d9a6:
            puVar9 = puVar8;
            if (uVar7 <= uVar7 + 8) {
              *(undefined8 *)(puVar8 + -8) = 0x18001d9bb;
              pbOutput = (PUCHAR)(*g_pfnAllocate)();
              if (pbOutput != (PUCHAR)0x0) {
                builtin_memcpy(pbOutput,"Heap",4);
                pbOutput = pbOutput + 8;
              }
            }
          }
          else {
            uVar5 = VerifyStackAvailable(uVar6);
            puVar8 = auStackY_a8;
            if ((int)uVar5 == 0) goto LAB_18001d9a6;
            uVar6 = uVar7 + 0x17;
            if (uVar6 <= uVar7 + 8) {
              uVar6 = 0xffffffffffffff0;
            }
            lVar2 = -(uVar6 & 0xfffffffffffffff0);
            pbOutput = (PUCHAR)0x0;
            puVar8 = auStackY_a8 + lVar2;
            if ((undefined4 *)((longlong)local_58 + lVar2) == (undefined4 *)0x0) goto LAB_18001d9a6;
            *(undefined4 *)((longlong)local_58 + lVar2) = 0x6b637453;
            pbOutput = (PUCHAR)((longlong)local_58 + lVar2 + 8);
            puVar8 = auStackY_a8 + lVar2;
            puVar9 = auStackY_a8 + lVar2;
            if (pbOutput == (PUCHAR)0x0) goto LAB_18001d9a6;
          }
          if (pbOutput == (PUCHAR)0x0) {
            uVar12 = 0xe;
          }
          else {
            *(undefined4 *)(puVar9 + 0x30) = 0;
            pvVar3 = local_50;
            *(ULONG **)(puVar9 + 0x28) = local_58;
            *(ULONG *)(puVar9 + 0x20) = local_58[0];
            *(undefined8 *)(puVar9 + -8) = 0x18001da25;
            uVar4 = BCryptExportKey(pvVar3,(BCRYPT_KEY_HANDLE)0x0,L"KeyDataBlob",pbOutput,
                                    *(ULONG *)(puVar9 + 0x20),*(ULONG **)(puVar9 + 0x28),
                                    *(ULONG *)(puVar9 + 0x30));
            if ((int)uVar4 < 0) {
              uVar12 = 0x1c;
              goto LAB_18001d85d;
            }
            uVar4 = *(uint *)(pbOutput + 8);
            pcVar1 = *(code **)(param_1 + 8);
            *(undefined8 *)(puVar9 + -8) = 0x18001da4b;
            _Dst = (void *)(*pcVar1)((ulonglong)uVar4);
            if (_Dst != (void *)0x0) {
              *(undefined8 *)(puVar9 + -8) = 0x18001da6d;
              memcpy(_Dst,pbOutput + 0xc,(ulonglong)uVar4);
              *param_6 = _Dst;
              *param_7 = uVar4;
              goto LAB_18001da81;
            }
            uVar12 = 0x27;
          }
          uVar10 = 0x8009000e;
          *(undefined8 *)(puVar9 + -8) = 0x18001d9f5;
          DebugTraceError(0xe,"hr",
                          "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\common\\keywrap.c",
                          uVar12);
          goto LAB_18001da81;
        }
        uVar12 = 5;
      }
    }
  }
LAB_18001d85d:
  *(undefined8 *)(puVar9 + -8) = 0x18001d872;
  DebugTraceError((char)uVar4,"status",
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\common\\keywrap.c",uVar12);
  uVar10 = uVar4 | 0x10000000;
LAB_18001da81:
  pvVar3 = local_40;
  if (local_40 != (BCRYPT_KEY_HANDLE)0x0) {
    *(undefined8 *)(puVar9 + -8) = 0x18001da91;
    BCryptDestroyKey(pvVar3);
  }
  pvVar3 = local_50;
  if (local_50 != (BCRYPT_KEY_HANDLE)0x0) {
    *(undefined8 *)(puVar9 + -8) = 0x18001daa6;
    BCryptDestroyKey(pvVar3);
  }
  if (pbOutput != (PUCHAR)0x0) {
    pUVar11 = pbOutput;
    for (uVar7 = (ulonglong)local_58[0]; uVar7 != 0; uVar7 = uVar7 - 1) {
      *pUVar11 = '\0';
      pUVar11 = pUVar11 + 1;
    }
    if (*(int *)(pbOutput + -8) == 0x70616548) {
      *(undefined8 *)(puVar9 + -8) = 0x18001dad2;
      (*g_pfnFree)();
    }
  }
  *(undefined8 *)(puVar9 + -8) = 0x18001dae0;
  return uVar10;
}



===== CNG_AesKeyWrap @ 18001db04 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

uint CNG_AesKeyWrap(longlong param_1,PUCHAR param_2,ULONG param_3,PUCHAR param_4,ULONG param_5,
                   undefined8 *param_6,ULONG *param_7)

{
  uint uVar1;
  PUCHAR pbOutput;
  uint uVar2;
  undefined1 uVar3;
  ULONG local_48 [2];
  BCRYPT_KEY_HANDLE local_40;
  BCRYPT_KEY_HANDLE local_38;
  BCRYPT_ALG_HANDLE local_30;
  
  local_30 = (BCRYPT_ALG_HANDLE)0x0;
  local_40 = (BCRYPT_KEY_HANDLE)0x0;
  local_38 = (BCRYPT_KEY_HANDLE)0x0;
  uVar2 = 0;
  local_48[0] = 0;
  pbOutput = (PUCHAR)0x0;
  uVar1 = CNG_GetBCryptHandle((ushort *)L"AES",&local_30);
  if ((int)uVar1 < 0) {
    uVar3 = 0x4b;
  }
  else {
    uVar1 = BCryptGenerateSymmetricKey(local_30,&local_40,(PUCHAR)0x0,0,param_4,param_5,0);
    if ((int)uVar1 < 0) {
      uVar3 = 0x5a;
    }
    else {
      uVar1 = BCryptGenerateSymmetricKey(local_30,&local_38,(PUCHAR)0x0,0,param_2,param_3,0);
      if ((int)uVar1 < 0) {
        uVar3 = 0x6c;
      }
      else {
        uVar1 = BCryptExportKey(local_38,local_40,L"Rfc3565KeyWrapBlob",(PUCHAR)0x0,0,local_48,0);
        if ((int)uVar1 < 0) {
          uVar3 = 0x7c;
        }
        else {
          pbOutput = (PUCHAR)(**(code **)(param_1 + 8))(local_48[0]);
          if (pbOutput == (PUCHAR)0x0) {
            uVar2 = 0x8009000e;
            DebugTraceError(0xe,"hr",
                            "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\common\\keywrap.c",
                            0x85);
            goto LAB_18001dcbd;
          }
          uVar1 = BCryptExportKey(local_38,local_40,L"Rfc3565KeyWrapBlob",pbOutput,local_48[0],
                                  local_48,0);
          if (-1 < (int)uVar1) {
            *param_6 = pbOutput;
            pbOutput = (PUCHAR)0x0;
            *param_7 = local_48[0];
            goto LAB_18001dcbd;
          }
          uVar3 = 0x94;
        }
      }
    }
  }
  DebugTraceError((char)uVar1,"status",
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\protect\\common\\keywrap.c",uVar3);
  uVar2 = uVar1 | 0x10000000;
LAB_18001dcbd:
  if (local_40 != (BCRYPT_KEY_HANDLE)0x0) {
    BCryptDestroyKey(local_40);
  }
  if (local_38 != (BCRYPT_KEY_HANDLE)0x0) {
    BCryptDestroyKey(local_38);
  }
  if (pbOutput != (PUCHAR)0x0) {
    (**(code **)(param_1 + 0x10))(pbOutput);
  }
  return uVar2;
}



===== CNG_FindBCryptOidInfoStr @ 18001dd20 =====

undefined8 CNG_FindBCryptOidInfoStr(undefined8 param_1,undefined8 param_2,longlong *param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  ulonglong uVar4;
  
  *param_3 = 0;
  uVar3 = 2;
  do {
    if (2 < uVar3) {
      return 0x80090008;
    }
    uVar4 = (ulonglong)uVar3;
    for (uVar2 = 0; uVar2 < *(uint *)(&DAT_18001f180 + uVar4 * 0x10); uVar2 = uVar2 + 1) {
      iVar1 = strcmp(*(char **)(*(longlong *)(&DAT_18001f188 + uVar4 * 0x10) + 0x18 +
                               (ulonglong)uVar2 * 0x50),"2.16.840.1.101.3.4.2.1");
      if (iVar1 == 0) {
        *param_3 = *(longlong *)(&DAT_18001f188 + uVar4 * 0x10) + (ulonglong)uVar2 * 0x50;
        return 0;
      }
    }
    uVar3 = uVar3 + 1;
  } while( true );
}



===== _guard_check_icall @ 18001dde0 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 18001ddf8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 18001de1c =====

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



===== __chkstk @ 18001de7d =====

/* WARNING: This is an inlined function */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __chkstk(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018001de7d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  return;
}



===== memcmp @ 18001de89 =====

int __cdecl memcmp(void *_Buf1,void *_Buf2,size_t _Size)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018001de89. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = memcmp(_Buf1,_Buf2,_Size);
  return iVar1;
}



===== memcpy @ 18001de95 =====

void * __cdecl memcpy(void *_Dst,void *_Src,size_t _Size)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018001de95. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = memcpy(_Dst,_Src,_Size);
  return pvVar1;
}



===== memmove @ 18001dea1 =====

void * __cdecl memmove(void *_Dst,void *_Src,size_t _Size)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018001dea1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = memmove(_Dst,_Src,_Size);
  return pvVar1;
}



===== memset @ 18001dead =====

void * __cdecl memset(void *_Dst,int _Val,size_t _Size)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018001dead. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = memset(_Dst,_Val,_Size);
  return pvVar1;
}



===== strcmp @ 18001deb9 =====

int __cdecl strcmp(char *_Str1,char *_Str2)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018001deb9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = strcmp(_Str1,_Str2);
  return iVar1;
}



===== wcscmp @ 18001dec5 =====

int __cdecl wcscmp(wchar_t *_Str1,wchar_t *_Str2)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018001dec5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = wcscmp(_Str1,_Str2);
  return iVar1;
}



===== __security_check_cookie @ 18001dee0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 18001df20 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 18001df50 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x00018001df50. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 18001df80 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== VerifyStackAvailable$filt$0 @ 18001df8c =====

bool VerifyStackAvailable_filt_0(undefined8 *param_1)

{
  return *(int *)*param_1 == -0x3fffff03;
}



===== _guard_dispatch_icall$thunk$10345483385596137414 @ 18001e010 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall_thunk_10345483385596137414(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== BCryptAddContextFunction @ 180030000 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x24160  1  BCryptAddContextFunction  (forwarder -> BCRYPT.BCryptAddContextFunction) */

NTSTATUS __stdcall
BCryptAddContextFunction
          (ULONG dwTable,LPCWSTR pszContext,ULONG dwInterface,LPCWSTR pszFunction,ULONG dwPosition)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== BCryptAddContextFunctionProvider @ 180030008 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x241a1  2  BCryptAddContextFunctionProvider  (forwarder ->
   BCRYPT.BCryptAddContextFunctionProvider) */

void BCryptAddContextFunctionProvider(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== BCryptCloseAlgorithmProvider @ 180030010 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x241e6  3  BCryptCloseAlgorithmProvider  (forwarder -> BCRYPT.BCryptCloseAlgorithmProvider) */

NTSTATUS __stdcall BCryptCloseAlgorithmProvider(BCRYPT_ALG_HANDLE hAlgorithm,ULONG dwFlags)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== BCryptConfigureContext @ 180030018 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x24221  4  BCryptConfigureContext  (forwarder -> BCRYPT.BCryptConfigureContext) */

NTSTATUS __stdcall
BCryptConfigureContext(ULONG dwTable,LPCWSTR pszContext,PCRYPT_CONTEXT_CONFIG pConfig)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== BCryptConfigureContextFunction @ 180030020 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x2425e  5  BCryptConfigureContextFunction  (forwarder -> BCRYPT.BCryptConfigureContextFunction)
    */

NTSTATUS __stdcall
BCryptConfigureContextFunction
          (ULONG dwTable,LPCWSTR pszContext,ULONG dwInterface,LPCWSTR pszFunction,
          PCRYPT_CONTEXT_FUNCTION_CONFIG pConfig)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== BCryptCreateContext @ 180030028 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x24298  6  BCryptCreateContext  (forwarder -> BCRYPT.BCryptCreateContext) */

NTSTATUS __stdcall
BCryptCreateContext(ULONG dwTable,LPCWSTR pszContext,PCRYPT_CONTEXT_CONFIG pConfig)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== BCryptCreateHash @ 180030030 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x242c4  7  BCryptCreateHash  (forwarder -> BCRYPT.BCryptCreateHash) */

NTSTATUS __stdcall
BCryptCreateHash(BCRYPT_ALG_HANDLE hAlgorithm,BCRYPT_HASH_HANDLE *phHash,PUCHAR pbHashObject,
                ULONG cbHashObject,PUCHAR pbSecret,ULONG cbSecret,ULONG dwFlags)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== BCryptCreateMultiHash @ 180030038 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x242f2  8  BCryptCreateMultiHash  (forwarder -> BCRYPT.BCryptCreateMultiHash) */

void BCryptCreateMultiHash(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== BCryptDecapsulate @ 180030040 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x24321  9  BCryptDecapsulate  (forwarder -> BCRYPT.BCryptDecapsulate) */

void BCryptDecapsulate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== BCryptDecrypt @ 180030048 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x24348  10  BCryptDecrypt  (forwarder -> BCRYPT.BCryptDecrypt) */

NTSTATUS __stdcall
BCryptDecrypt(BCRYPT_KEY_HANDLE hKey,PUCHAR pbInput,ULONG cbInput,void *pPaddingInfo,PUCHAR pbIV,
             ULONG cbIV,PUCHAR pbOutput,ULONG cbOutput,ULONG *pcbResult,ULONG dwFlags)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== BCryptDeleteContext @ 180030050 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x24371  11  BCryptDeleteContext  (forwarder -> BCRYPT.BCryptDeleteContext) */

NTSTATUS __stdcall BCryptDeleteContext(ULONG dwTable,LPCWSTR pszContext)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== BCryptDeriveKey @ 180030058 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x2439c  12  BCryptDeriveKey  (forwarder -> BCRYPT.BCryptDeriveKey) */

NTSTATUS __stdcall
BCryptDeriveKey(BCRYPT_SECRET_HANDLE hSharedSecret,LPCWSTR pwszKDF,BCryptBufferDesc *pParameterList,
               PUCHAR pbDerivedKey,ULONG cbDerivedKey,ULONG *pcbResult,ULONG dwFlags)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== BCryptDeriveKeyCapi @ 180030060 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x243c7  13  BCryptDeriveKeyCapi  (forwarder -> BCRYPT.BCryptDeriveKeyCapi) */

NTSTATUS __stdcall
BCryptDeriveKeyCapi(BCRYPT_HASH_HANDLE hHash,BCRYPT_ALG_HANDLE hTargetAlg,PUCHAR pbDerivedKey,
                   ULONG cbDerivedKey,ULONG dwFlags)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== BCryptDeriveKeyPBKDF2 @ 180030068 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x243f8  14  BCryptDeriveKeyPBKDF2  (forwarder -> BCRYPT.BCryptDeriveKeyPBKDF2) */

NTSTATUS __stdcall
BCryptDeriveKeyPBKDF2
          (BCRYPT_ALG_HANDLE hPrf,PUCHAR pbPassword,ULONG cbPassword,PUCHAR pbSalt,ULONG cbSalt,
          ULONGLONG cIterations,PUCHAR pbDerivedKey,ULONG cbDerivedKey,ULONG dwFlags)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== BCryptDestroyHash @ 180030070 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x24427  15  BCryptDestroyHash  (forwarder -> BCRYPT.BCryptDestroyHash) */

NTSTATUS __stdcall BCryptDestroyHash(BCRYPT_HASH_HANDLE hHash)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== BCryptDestroyKey @ 180030078 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x24451  16  BCryptDestroyKey  (forwarder -> BCRYPT.BCryptDestroyKey) */

NTSTATUS __stdcall BCryptDestroyKey(BCRYPT_KEY_HANDLE hKey)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== BCryptDestroySecret @ 180030080 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x2447d  17  BCryptDestroySecret  (forwarder -> BCRYPT.BCryptDestroySecret) */

NTSTATUS __stdcall BCryptDestroySecret(BCRYPT_SECRET_HANDLE hSecret)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== BCryptDuplicateHash @ 180030088 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x244ac  18  BCryptDuplicateHash  (forwarder -> BCRYPT.BCryptDuplicateHash) */

NTSTATUS __stdcall
BCryptDuplicateHash(BCRYPT_HASH_HANDLE hHash,BCRYPT_HASH_HANDLE *phNewHash,PUCHAR pbHashObject,
                   ULONG cbHashObject,ULONG dwFlags)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== BCryptDuplicateKey @ 180030090 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x244da  19  BCryptDuplicateKey  (forwarder -> BCRYPT.BCryptDuplicateKey) */

NTSTATUS __stdcall
BCryptDuplicateKey(BCRYPT_KEY_HANDLE hKey,BCRYPT_KEY_HANDLE *phNewKey,PUCHAR pbKeyObject,
                  ULONG cbKeyObject,ULONG dwFlags)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== BCryptEncapsulate @ 180030098 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x24506  20  BCryptEncapsulate  (forwarder -> BCRYPT.BCryptEncapsulate) */

void BCryptEncapsulate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== BCryptEncrypt @ 1800300a0 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x2452d  21  BCryptEncrypt  (forwarder -> BCRYPT.BCryptEncrypt) */

NTSTATUS __stdcall
BCryptEncrypt(BCRYPT_KEY_HANDLE hKey,PUCHAR pbInput,ULONG cbInput,void *pPaddingInfo,PUCHAR pbIV,
             ULONG cbIV,PUCHAR pbOutput,ULONG cbOutput,ULONG *pcbResult,ULONG dwFlags)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== BCryptEnumAlgorithms @ 1800300a8 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x24557  22  BCryptEnumAlgorithms  (forwarder -> BCRYPT.BCryptEnumAlgorithms) */

NTSTATUS __stdcall
BCryptEnumAlgorithms
          (ULONG dwAlgOperations,ULONG *pAlgCount,BCRYPT_ALGORITHM_IDENTIFIER **ppAlgList,
          ULONG dwFlags)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== BCryptEnumContextFunctionProviders @ 1800300b0 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x24596  23  BCryptEnumContextFunctionProviders  (forwarder ->
   BCRYPT.BCryptEnumContextFunctionProviders) */

NTSTATUS __stdcall
BCryptEnumContextFunctionProviders
          (ULONG dwTable,LPCWSTR pszContext,ULONG dwInterface,LPCWSTR pszFunction,ULONG *pcbBuffer,
          PCRYPT_CONTEXT_FUNCTION_PROVIDERS *ppBuffer)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== BCryptEnumContextFunctions @ 1800300b8 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x245db  24  BCryptEnumContextFunctions  (forwarder -> BCRYPT.BCryptEnumContextFunctions) */

NTSTATUS __stdcall
BCryptEnumContextFunctions
          (ULONG dwTable,LPCWSTR pszContext,ULONG dwInterface,ULONG *pcbBuffer,
          PCRYPT_CONTEXT_FUNCTIONS *ppBuffer)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== BCryptEnumContexts @ 1800300c0 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x24610  25  BCryptEnumContexts  (forwarder -> BCRYPT.BCryptEnumContexts) */

NTSTATUS __stdcall BCryptEnumContexts(ULONG dwTable,ULONG *pcbBuffer,PCRYPT_CONTEXTS *ppBuffer)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== BCryptEnumProviders @ 1800300c8 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x2463e  26  BCryptEnumProviders  (forwarder -> BCRYPT.BCryptEnumProviders) */

NTSTATUS __stdcall
BCryptEnumProviders(LPCWSTR pszAlgId,ULONG *pImplCount,BCRYPT_PROVIDER_NAME **ppImplList,
                   ULONG dwFlags)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== BCryptEnumRegisteredProviders @ 1800300d0 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x24677  27  BCryptEnumRegisteredProviders  (forwarder -> BCRYPT.BCryptEnumRegisteredProviders)
    */

NTSTATUS __stdcall BCryptEnumRegisteredProviders(ULONG *pcbBuffer,PCRYPT_PROVIDERS *ppBuffer)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== BCryptExportKey @ 1800300d8 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x246ac  28  BCryptExportKey  (forwarder -> BCRYPT.BCryptExportKey) */

NTSTATUS __stdcall
BCryptExportKey(BCRYPT_KEY_HANDLE hKey,BCRYPT_KEY_HANDLE hExportKey,LPCWSTR pszBlobType,
               PUCHAR pbOutput,ULONG cbOutput,ULONG *pcbResult,ULONG dwFlags)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== BCryptFinalizeKeyPair @ 1800300e0 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x246d9  29  BCryptFinalizeKeyPair  (forwarder -> BCRYPT.BCryptFinalizeKeyPair) */

NTSTATUS __stdcall BCryptFinalizeKeyPair(BCRYPT_KEY_HANDLE hKey,ULONG dwFlags)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== BCryptFinishHash @ 1800300e8 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x24707  30  BCryptFinishHash  (forwarder -> BCRYPT.BCryptFinishHash) */

NTSTATUS __stdcall
BCryptFinishHash(BCRYPT_HASH_HANDLE hHash,PUCHAR pbOutput,ULONG cbOutput,ULONG dwFlags)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== BCryptFreeBuffer @ 1800300f0 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x24730  31  BCryptFreeBuffer  (forwarder -> BCRYPT.BCryptFreeBuffer) */

void __stdcall BCryptFreeBuffer(PVOID pvBuffer)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== BCryptGenRandom @ 1800300f8 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x24758  32  BCryptGenRandom  (forwarder -> BCRYPT.BCryptGenRandom) */

NTSTATUS __stdcall
BCryptGenRandom(BCRYPT_ALG_HANDLE hAlgorithm,PUCHAR pbBuffer,ULONG cbBuffer,ULONG dwFlags)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== BCryptGenerateKeyPair @ 180030100 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x24785  33  BCryptGenerateKeyPair  (forwarder -> BCRYPT.BCryptGenerateKeyPair) */

NTSTATUS __stdcall
BCryptGenerateKeyPair
          (BCRYPT_ALG_HANDLE hAlgorithm,BCRYPT_KEY_HANDLE *phKey,ULONG dwLength,ULONG dwFlags)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== BCryptGenerateSymmetricKey @ 180030108 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x247bd  34  BCryptGenerateSymmetricKey  (forwarder -> BCRYPT.BCryptGenerateSymmetricKey) */

NTSTATUS __stdcall
BCryptGenerateSymmetricKey
          (BCRYPT_ALG_HANDLE hAlgorithm,BCRYPT_KEY_HANDLE *phKey,PUCHAR pbKeyObject,
          ULONG cbKeyObject,PUCHAR pbSecret,ULONG cbSecret,ULONG dwFlags)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== BCryptGetFipsAlgorithmMode @ 180030110 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x247fa  35  BCryptGetFipsAlgorithmMode  (forwarder -> BCRYPT.BCryptGetFipsAlgorithmMode) */

NTSTATUS __stdcall BCryptGetFipsAlgorithmMode(BOOLEAN *pfEnabled)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== BCryptGetProperty @ 180030118 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x2482e  36  BCryptGetProperty  (forwarder -> BCRYPT.BCryptGetProperty) */

NTSTATUS __stdcall
BCryptGetProperty(BCRYPT_HANDLE hObject,LPCWSTR pszProperty,PUCHAR pbOutput,ULONG cbOutput,
                 ULONG *pcbResult,ULONG dwFlags)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== BCryptHash @ 180030120 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x24852  37  BCryptHash  (forwarder -> BCRYPT.BCryptHash) */

void BCryptHash(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== BCryptHashData @ 180030128 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x24873  38  BCryptHashData  (forwarder -> BCRYPT.BCryptHashData) */

NTSTATUS __stdcall
BCryptHashData(BCRYPT_HASH_HANDLE hHash,PUCHAR pbInput,ULONG cbInput,ULONG dwFlags)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== BCryptImportKey @ 180030130 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x24899  39  BCryptImportKey  (forwarder -> BCRYPT.BCryptImportKey) */

NTSTATUS __stdcall
BCryptImportKey(BCRYPT_ALG_HANDLE hAlgorithm,BCRYPT_KEY_HANDLE hImportKey,LPCWSTR pszBlobType,
               BCRYPT_KEY_HANDLE *phKey,PUCHAR pbKeyObject,ULONG cbKeyObject,PUCHAR pbInput,
               ULONG cbInput,ULONG dwFlags)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== BCryptImportKeyPair @ 180030138 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x248c4  40  BCryptImportKeyPair  (forwarder -> BCRYPT.BCryptImportKeyPair) */

NTSTATUS __stdcall
BCryptImportKeyPair(BCRYPT_ALG_HANDLE hAlgorithm,BCRYPT_KEY_HANDLE hImportKey,LPCWSTR pszBlobType,
                   BCRYPT_KEY_HANDLE *phKey,PUCHAR pbInput,ULONG cbInput,ULONG dwFlags)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== BCryptKeyDerivation @ 180030140 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x248f3  41  BCryptKeyDerivation  (forwarder -> BCRYPT.BCryptKeyDerivation) */

void BCryptKeyDerivation(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== BCryptOpenAlgorithmProvider @ 180030148 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x2492a  42  BCryptOpenAlgorithmProvider  (forwarder -> BCRYPT.BCryptOpenAlgorithmProvider) */

NTSTATUS __stdcall
BCryptOpenAlgorithmProvider
          (BCRYPT_ALG_HANDLE *phAlgorithm,LPCWSTR pszAlgId,LPCWSTR pszImplementation,ULONG dwFlags)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== BCryptProcessMultiOperations @ 180030150 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x2496a  43  BCryptProcessMultiOperations  (forwarder -> BCRYPT.BCryptProcessMultiOperations) */

void BCryptProcessMultiOperations(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== BCryptQueryContextConfiguration @ 180030158 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x249ae  44  BCryptQueryContextConfiguration  (forwarder ->
   BCRYPT.BCryptQueryContextConfiguration) */

NTSTATUS __stdcall
BCryptQueryContextConfiguration
          (ULONG dwTable,LPCWSTR pszContext,ULONG *pcbBuffer,PCRYPT_CONTEXT_CONFIG *ppBuffer)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== BCryptQueryContextFunctionConfiguration @ 180030160 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x249fd  45  BCryptQueryContextFunctionConfiguration  (forwarder ->
   BCRYPT.BCryptQueryContextFunctionConfiguration) */

NTSTATUS __stdcall
BCryptQueryContextFunctionConfiguration
          (ULONG dwTable,LPCWSTR pszContext,ULONG dwInterface,LPCWSTR pszFunction,ULONG *pcbBuffer,
          PCRYPT_CONTEXT_FUNCTION_CONFIG *ppBuffer)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== BCryptQueryContextFunctionProperty @ 180030168 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x24a4f  46  BCryptQueryContextFunctionProperty  (forwarder ->
   BCRYPT.BCryptQueryContextFunctionProperty) */

NTSTATUS __stdcall
BCryptQueryContextFunctionProperty
          (ULONG dwTable,LPCWSTR pszContext,ULONG dwInterface,LPCWSTR pszFunction,
          LPCWSTR pszProperty,ULONG *pcbValue,PUCHAR *ppbValue)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== BCryptQueryProviderRegistration @ 180030170 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x24a99  47  BCryptQueryProviderRegistration  (forwarder ->
   BCRYPT.BCryptQueryProviderRegistration) */

NTSTATUS __stdcall
BCryptQueryProviderRegistration
          (LPCWSTR pszProvider,ULONG dwMode,ULONG dwInterface,ULONG *pcbBuffer,
          PCRYPT_PROVIDER_REG *ppBuffer)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== BCryptRegisterConfigChangeNotify @ 180030178 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x24ae1  48  BCryptRegisterConfigChangeNotify  (forwarder ->
   BCRYPT.BCryptRegisterConfigChangeNotify) */

NTSTATUS __stdcall BCryptRegisterConfigChangeNotify(HANDLE *phEvent)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== BCryptRegisterProvider @ 180030180 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x24b20  49  BCryptRegisterProvider  (forwarder -> BCRYPT.BCryptRegisterProvider) */

void BCryptRegisterProvider(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== BCryptRemoveContextFunction @ 180030188 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x24b5a  50  BCryptRemoveContextFunction  (forwarder -> BCRYPT.BCryptRemoveContextFunction) */

NTSTATUS __stdcall
BCryptRemoveContextFunction(ULONG dwTable,LPCWSTR pszContext,ULONG dwInterface,LPCWSTR pszFunction)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== BCryptRemoveContextFunctionProvider @ 180030190 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x24ba1  51  BCryptRemoveContextFunctionProvider  (forwarder ->
   BCRYPT.BCryptRemoveContextFunctionProvider) */

void BCryptRemoveContextFunctionProvider(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== BCryptResolveProviders @ 180030198 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x24be3  52  BCryptResolveProviders  (forwarder -> BCRYPT.BCryptResolveProviders) */

NTSTATUS __stdcall
BCryptResolveProviders
          (LPCWSTR pszContext,ULONG dwInterface,LPCWSTR pszFunction,LPCWSTR pszProvider,ULONG dwMode
          ,ULONG dwFlags,ULONG *pcbBuffer,PCRYPT_PROVIDER_REFS *ppBuffer)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== BCryptSecretAgreement @ 1800301a0 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x24c17  53  BCryptSecretAgreement  (forwarder -> BCRYPT.BCryptSecretAgreement) */

NTSTATUS __stdcall
BCryptSecretAgreement
          (BCRYPT_KEY_HANDLE hPrivKey,BCRYPT_KEY_HANDLE hPubKey,BCRYPT_SECRET_HANDLE *phAgreedSecret
          ,ULONG dwFlags)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== BCryptSetAuditingInterface @ 1800301a8 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x24c4f  54  BCryptSetAuditingInterface  (forwarder -> BCRYPT.BCryptSetAuditingInterface) */

void BCryptSetAuditingInterface(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== BCryptSetContextFunctionProperty @ 1800301b0 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x24c92  55  BCryptSetContextFunctionProperty  (forwarder ->
   BCRYPT.BCryptSetContextFunctionProperty) */

NTSTATUS __stdcall
BCryptSetContextFunctionProperty
          (ULONG dwTable,LPCWSTR pszContext,ULONG dwInterface,LPCWSTR pszFunction,
          LPCWSTR pszProperty,ULONG cbValue,PUCHAR pbValue)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== BCryptSetProperty @ 1800301b8 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x24ccc  56  BCryptSetProperty  (forwarder -> BCRYPT.BCryptSetProperty) */

NTSTATUS __stdcall
BCryptSetProperty(BCRYPT_HANDLE hObject,LPCWSTR pszProperty,PUCHAR pbInput,ULONG cbInput,
                 ULONG dwFlags)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== BCryptSignHash @ 1800301c0 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x24cf4  57  BCryptSignHash  (forwarder -> BCRYPT.BCryptSignHash) */

NTSTATUS __stdcall
BCryptSignHash(BCRYPT_KEY_HANDLE hKey,void *pPaddingInfo,PUCHAR pbInput,ULONG cbInput,
              PUCHAR pbOutput,ULONG cbOutput,ULONG *pcbResult,ULONG dwFlags)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== BCryptUnregisterConfigChangeNotify @ 1800301c8 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x24d2d  58  BCryptUnregisterConfigChangeNotify  (forwarder ->
   BCRYPT.BCryptUnregisterConfigChangeNotify) */

NTSTATUS __stdcall BCryptUnregisterConfigChangeNotify(HANDLE hEvent)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== BCryptUnregisterProvider @ 1800301d0 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x24d70  59  BCryptUnregisterProvider  (forwarder -> BCRYPT.BCryptUnregisterProvider) */

void BCryptUnregisterProvider(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== BCryptVerifySignature @ 1800301d8 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x24da6  60  BCryptVerifySignature  (forwarder -> BCRYPT.BCryptVerifySignature) */

NTSTATUS __stdcall
BCryptVerifySignature
          (BCRYPT_KEY_HANDLE hKey,void *pPaddingInfo,PUCHAR pbHash,ULONG cbHash,PUCHAR pbSignature,
          ULONG cbSignature,ULONG dwFlags)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


