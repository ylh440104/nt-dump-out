
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



===== __C_specific_handler @ 14000101d =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00014000101d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== wil_details_RecordCachedUsage @ 140001030 =====

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



===== wil_details_RecordFeatureUsageReporting @ 140001190 =====

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



===== RtlStringCbPrintfW @ 140001214 =====

undefined8
RtlStringCbPrintfW(wchar_t *param_1,ulonglong param_2,wchar_t *param_3,undefined8 param_4)

{
  int iVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 local_res20;
  
  uVar2 = param_2 >> 1;
  if (uVar2 - 1 < 0x7fffffff) {
    uVar2 = uVar2 - 1;
    uVar3 = 0;
    local_res20 = param_4;
    iVar1 = _vsnwprintf(param_1,uVar2,param_3,(va_list)&local_res20);
    if ((iVar1 < 0) || (uVar2 < (ulonglong)(longlong)iVar1)) {
      uVar3 = 0x80000005;
    }
    else if ((longlong)iVar1 != uVar2) {
      return 0;
    }
    param_1[uVar2] = L'\0';
  }
  else {
    uVar3 = 0xc000000d;
    if (uVar2 != 0) {
      *param_1 = L'\0';
    }
  }
  return uVar3;
}



===== FTPostOnlyOpCallback @ 140001290 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FTPostOnlyOpCallback(uint *param_1,longlong param_2,undefined8 param_3,ulonglong param_4)

{
  uint *puVar1;
  undefined1 *puVar2;
  char cVar3;
  ushort uVar4;
  short sVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  longlong lVar11;
  longlong lVar12;
  undefined8 uVar13;
  undefined8 *puVar14;
  undefined1 uVar15;
  ulonglong uVar16;
  undefined1 auStackY_3e8 [32];
  char local_3b8;
  undefined1 local_3b7 [3];
  int local_3b4;
  int local_3b0;
  int local_3ac;
  uint local_3a8;
  uint local_3a4;
  uint local_3a0 [2];
  longlong local_398;
  longlong local_390;
  longlong local_388;
  undefined8 local_380;
  undefined1 *local_378;
  undefined8 local_370;
  undefined2 *local_368;
  uint local_360;
  uint local_358;
  longlong local_350;
  longlong local_348;
  undefined1 *local_340;
  undefined8 local_338;
  undefined8 *local_330;
  undefined1 local_328;
  byte bStack_327;
  byte local_326;
  undefined4 local_325;
  undefined1 local_321;
  undefined8 local_320;
  longlong local_318;
  undefined8 uStack_310;
  undefined8 local_308;
  undefined8 local_300;
  char local_2f8;
  undefined4 local_2f7;
  undefined2 local_2f3;
  undefined1 local_2f1;
  longlong local_2f0;
  int local_2e8;
  undefined4 local_2e4;
  longlong local_2e0;
  undefined8 local_2d8;
  longlong local_2d0;
  longlong local_2c8;
  ulonglong local_2c0;
  longlong local_2b8;
  ulonglong local_2b0 [5];
  short *local_288;
  longlong local_280;
  undefined8 local_278;
  undefined1 *local_270;
  undefined8 local_268;
  undefined4 local_258;
  undefined1 local_254;
  undefined1 uStack_253;
  undefined2 uStack_252;
  undefined4 uStack_250;
  undefined4 uStack_24c;
  undefined4 uStack_248;
  undefined4 local_244;
  undefined4 uStack_240;
  undefined4 uStack_23c;
  undefined4 uStack_238;
  undefined4 local_234;
  undefined4 uStack_230;
  undefined4 uStack_22c;
  undefined4 uStack_228;
  undefined4 uStack_224;
  uint uStack_220;
  undefined4 local_21c;
  undefined2 local_218;
  undefined8 local_216;
  undefined8 uStack_20e;
  undefined8 local_206;
  undefined8 uStack_1fe;
  undefined8 local_1f6;
  undefined4 local_1ee;
  undefined2 local_1ea;
  undefined1 local_1e8 [24];
  undefined1 local_1d0 [24];
  undefined1 local_1b8 [384];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_3e8;
  local_3a0[0] = 0;
  local_3b4 = 0;
  local_388 = 0;
  local_258 = 0;
  local_254 = 0;
  uStack_253 = 0;
  uStack_252 = 0;
  uStack_250 = 0;
  uStack_24c = 0;
  uStack_248 = 0;
  local_244 = 0;
  uStack_240 = 0;
  uStack_23c = 0;
  uStack_238 = 0;
  local_234 = 0;
  uStack_230 = 0;
  uStack_22c = 0;
  uStack_228 = 0;
  uStack_224 = 0;
  uStack_220 = 0;
  local_21c = 0;
  local_3b8 = '\x02';
  local_350 = 0;
  local_3ac = -1;
  local_280 = 0;
  local_348 = 0;
  local_3a8 = 0;
  local_3a4 = 0;
  local_390 = 0;
  local_218 = 0x30;
  local_216 = 0;
  uStack_20e = 0;
  local_206 = 0;
  uStack_1fe = 0;
  local_1f6 = 0;
  local_1ee = 0;
  local_1ea = 0;
  local_370 = 0x300000;
  local_368 = &local_218;
  local_330 = (undefined8 *)0x0;
  local_325 = 0;
  local_321 = 0;
  local_318 = 0;
  local_308 = 0;
  local_300 = 0;
  local_2f8 = '\x02';
  local_2f7 = 0;
  local_2f3 = 0;
  local_2f1 = 0;
  local_2f0 = 0;
  local_2e8 = -1;
  local_2e4 = 0;
  local_2e0 = 0;
  local_2d8 = 0;
  local_2d0 = 0;
  local_2c8 = 0;
  local_2c0 = 0;
  local_2b8 = 0;
  local_2b0[0] = 0;
  local_2b0[1] = 0;
  local_2b0[2] = 0;
  local_2b0[3] = 0;
  if ((param_4 & 1) == 0) {
    local_398 = 0;
    puVar1 = *(uint **)(param_1 + 4);
    local_358 = (uint)(byte)puVar1[1];
    local_340 = local_1b8;
    local_338 = (ulonglong)
                CONCAT15(*(undefined1 *)((longlong)puVar1 + 5),CONCAT14((char)puVar1[1],param_1[6]))
    ;
    uStack_310 = *(undefined8 *)(param_2 + 0x20);
    _local_328 = CONCAT11((byte)(*puVar1 >> 1) & 1,2);
    local_326 = (byte)(*param_1 >> 1) & 1;
    local_268 = _DAT_fffff78000000014;
    local_320 = _DAT_fffff78000000014;
    uVar6 = FltGetRequestorProcessId(param_1);
    local_308 = CONCAT44(local_308._4_4_,uVar6);
    lVar11 = FltGetRequestorProcess(param_1);
    if (lVar11 == 0) {
      local_300 = 0;
    }
    else {
      local_300 = PsGetProcessCreateTimeQuadPart(lVar11);
    }
    iVar7 = FltGetVolumeContext(DAT_140008110,*(undefined8 *)(param_2 + 0x10),&local_318);
    if (-1 < iVar7) {
      if (*(longlong *)(param_2 + 0x20) == 0) {
        local_278 = 0;
        local_270 = local_1d0;
        RtlInitUnicodeString(&local_278,L"0x00000000");
        iVar7 = RtlAppendUnicodeToString(&local_370,L":00000001-");
        if (-1 < iVar7) {
          RtlAppendUnicodeStringToString(&local_370,&local_278);
        }
        local_330 = &local_370;
      }
      else {
        uVar8 = FltGetFileNameInformation(param_1,DAT_140008244 | 1,&local_388);
        uVar16 = (ulonglong)uVar8;
        if ((int)uVar8 < 0) {
          local_378 = local_1e8;
          local_380 = 0x120000;
          iVar7 = RtlAppendUnicodeToString(&local_370,L":00000000-");
          if (-1 < iVar7) {
            local_288 = (short *)0x0;
            if (((local_378 == (undefined1 *)0x0) || ((short)local_380 != 0)) ||
               (local_380._2_2_ < 0x12)) {
              iVar7 = -0x3ffffff3;
              local_360 = uVar8;
            }
            else {
              local_288 = (short *)(local_378 + 0x10);
              *local_288 = 0;
              do {
                uVar4 = (ushort)uVar16 & 0xf;
                if (uVar4 < 10) {
                  sVar5 = uVar4 + 0x30;
                }
                else {
                  sVar5 = uVar4 + 0x37;
                }
                local_288 = local_288 + -1;
                *local_288 = sVar5;
                uVar16 = uVar16 >> 4;
              } while ((int)uVar16 != 0);
              local_380 = CONCAT62(local_380._2_6_,0x12);
              iVar7 = 0;
              local_360 = 0;
            }
            if (-1 < iVar7) {
              RtlAppendUnicodeStringToString(&local_370,&local_380);
            }
          }
          local_330 = &local_370;
        }
        else {
          local_330 = (undefined8 *)(local_388 + 8);
        }
        if ((**(uint **)(param_1 + 4) & 2) == 0) {
          if (*(longlong *)(*(longlong *)(param_2 + 0x20) + 0x18) == 0) {
            _local_328 = CONCAT11(bStack_327,3);
          }
          else {
            local_3b7[0] = 0;
            if (-1 < (int)param_1[6]) {
              iVar7 = FltIsDirectory(*(undefined8 *)(*(uint **)(param_1 + 4) + 2),
                                     *(undefined8 *)(param_2 + 0x18),local_3b7);
              uVar15 = 4;
              if (-1 < iVar7) {
                uVar15 = local_3b7[0];
              }
              _local_328 = CONCAT11(bStack_327,uVar15);
            }
          }
        }
      }
      local_258 = CONCAT22(local_258._2_2_,0x40);
      uStack_22c = 0x120000;
      local_254 = *(undefined1 *)(*(longlong *)(param_1 + 4) + 4);
      uStack_253 = 0;
      uStack_240 = 0xf681e6cc;
      uStack_23c = 0x4ee9ec6c;
      uStack_238 = 0xc4c0a690;
      local_234 = 0xc27632e8;
      local_3b0 = 0;
      while (iVar7 = local_3b0, local_3b0 < 8) {
        local_2f8 = '\x02';
        lVar11 = (longlong)local_3b0;
        iVar10 = *(int *)(LogSessions + 0xc + lVar11 * 0x28);
        uVar8 = *(uint *)(LogSessions + 0x14 + lVar11 * 0x28);
        uVar13 = *(undefined8 *)(LogSessions + lVar11 * 0x28);
        uStack_250 = (undefined4)uVar13;
        uStack_24c = (undefined4)((ulonglong)uVar13 >> 0x20);
        if ((*(uint *)(LogSessions + 0x1c + lVar11 * 0x28) & 0x40) != 0) {
          if (*(char *)(*(longlong *)(param_1 + 4) + 4) == '\0') {
            if ((local_3b8 == '\x02') && (-1 < (int)param_1[6])) {
              if ((*(byte *)(*(longlong *)(param_1 + 4) + 6) & 4) == 0) {
                if ((*(longlong *)(param_1 + 8) == 2) ||
                   (local_3b8 = '\x01', *(longlong *)(param_1 + 8) == 5)) {
                  local_3b8 = '\0';
                }
              }
              else {
                local_3b8 = '\x01';
              }
            }
            local_2f8 = local_3b8;
          }
        }
        if (((**(uint **)(param_1 + 4) & 2) == 0) &&
           ((*(uint *)(LogSessions + 0x1c + (longlong)local_3b0 * 0x28) & 4) != 0)) {
          if (local_350 == 0) {
            GetLastAccessTime((longlong)param_1,param_2,&local_350);
          }
          local_2f0 = local_350;
        }
        if ((*(uint *)(LogSessions + 0x1c + (longlong)iVar7 * 0x28) & 2) != 0) {
          if (local_3ac == -1) {
            iVar9 = -1;
            lVar11 = FltGetRequestorProcess(param_1);
            if (lVar11 != 0) {
              iVar9 = PsGetProcessSessionId(lVar11);
            }
            local_3ac = iVar9;
          }
          local_2e8 = local_3ac;
        }
        lVar11 = local_280;
        if ((char)*(undefined4 *)(LogSessions + 0x1c + (longlong)iVar7 * 0x28) < '\0') {
          if (local_280 == 0) {
            lVar12 = FltGetRequestorProcess(param_1);
            if (lVar12 != 0) {
              lVar11 = PsGetProcessWin32WindowStation(lVar12);
              local_280 = lVar11;
            }
          }
          local_2c8 = lVar11;
        }
        if (((**(uint **)(param_1 + 4) & 2) == 0) &&
           ((((GlobalLateBoundFunctions != (code *)0x0 &&
              (cVar3 = (*GlobalLateBoundFunctions)(), cVar3 == '\0')) ||
             ((**(uint **)(param_1 + 4) & 2) == 0)) &&
            ((*(uint *)(LogSessions + 0x1c + (longlong)iVar7 * 0x28) & 1) != 0)))) {
          if (local_348 == 0) {
            GetUserSidAndAcessToken((longlong)param_1,&local_3a8,&local_398,&local_348);
          }
          local_2d8 = CONCAT44(local_2d8._4_4_,local_3a8);
          local_2d0 = local_398;
          local_2e0 = local_348;
        }
        if ((*(uint *)(LogSessions + 0x1c + (longlong)iVar7 * 0x28) & 8) != 0) {
          if (local_390 == 0) {
            CreateParameterBlob((longlong)param_1,&local_3a4,&local_390);
          }
          local_2b8 = local_390;
          local_2c0 = CONCAT44(local_2c0._4_4_,local_3a4);
        }
        local_2b0[0] = local_2b0[0] & 0xffffffff00000000;
        local_2b0[1] = 0;
        lVar11 = (longlong)iVar7 * 5;
        lVar12 = LogSessions;
        SetCallResult((longlong)param_1,
                      (ulonglong)*(uint *)(LogSessions + 0x1c + (longlong)iVar7 * 0x28),
                      (undefined4 *)local_2b0,local_2b0 + 1);
        if ((((iVar10 != 0) && (iVar10 == *(int *)(lVar12 + 0xc + lVar11 * 8))) &&
            (((uVar8 >> (local_358 & 0x1f) & 1) != 0 &&
             ((uVar8 = *(uint *)(lVar12 + 0x20 + lVar11 * 8), (uVar8 >> 0x1a & 1) != 0 ||
              ((*(uint *)(local_318 + 0x1e0) & uVar8) != 0)))))) &&
           (((**(uint **)(param_1 + 4) & 2) == 0 ||
            ((*(uint *)(lVar12 + 0x1c + lVar11 * 8) >> 8 & 1) == 0)))) {
          uVar13 = FormatFileTraceEvent
                             (lVar12 + (longlong)iVar7 * 0x28,(undefined4 *)&local_338,&local_3b4,
                              local_3a0,(longlong *)&local_340);
          puVar2 = local_340;
          if ((char)uVar13 == '\0') break;
          uStack_228 = SUB84(local_340,0);
          uStack_224 = (undefined4)((ulonglong)local_340 >> 0x20);
          uStack_220 = local_3a0[0];
          iVar10 = IoWMIWriteEvent(&local_258);
          if ((iVar10 == -0x3ffffff8) && (lVar11 = FltAllocateGenericWorkItem(), lVar11 != 0)) {
            puVar14 = (undefined8 *)ExAllocatePoolWithTag(0x200,8,0x72744c46);
            if (puVar14 != (undefined8 *)0x0) {
              *puVar14 = CONCAT44(uStack_24c,uStack_250);
              iVar10 = FltQueueGenericWorkItem(lVar11,DAT_140008110,DisableSession,1);
              if (-1 < iVar10) goto LAB_140001b7d;
              ExFreePoolWithTag(puVar14,0x72744c46);
            }
            FltFreeGenericWorkItem(lVar11);
          }
LAB_140001b7d:
          if (local_3b4 == 1) {
            ExFreeToNPagedLookasideList(&DAT_1400081c0,puVar2);
LAB_140001bb7:
            local_3b4 = 0;
          }
          else if (local_3b4 == 2) {
            ExFreePoolWithTag(puVar2,0x72744c46);
            goto LAB_140001bb7;
          }
          local_340 = local_1b8;
        }
        local_2e8 = -1;
        local_2f0 = 0;
        local_2e0 = 0;
        local_2d0 = 0;
        local_2b8 = 0;
        local_2c0 = local_2c0 & 0xffffffff00000000;
        local_2b0[1] = 0;
        local_2b0[0] = local_2b0[0] & 0xffffffff00000000;
        local_2b0[3] = 0;
        local_2b0[2] = local_2b0[2] & 0xffffffff00000000;
        local_2f8 = '\x02';
        local_2c8 = 0;
        local_3b0 = iVar7 + 1;
      }
    }
    if (local_388 != 0) {
      FltReleaseFileNameInformation();
    }
    if (local_398 != 0) {
      ExFreePoolWithTag(local_398,0x72744c46);
    }
    if (local_318 != 0) {
      FltReleaseContext();
    }
    if (local_390 != 0) {
      ExFreePoolWithTag(local_390,0x72744c46);
    }
  }
  return 0;
}



===== FTPostOpCallback @ 140001cd0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FTPostOpCallback(uint *param_1,longlong param_2,longlong param_3,ulonglong param_4)

{
  uint *puVar1;
  char *pcVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  longlong lVar7;
  undefined8 uVar8;
  undefined8 *puVar9;
  uint uVar10;
  undefined1 auStackY_318 [32];
  int local_2e8 [2];
  undefined1 *local_2e0;
  uint local_2d8;
  int local_2d4;
  undefined8 local_2c8;
  longlong local_2c0;
  undefined2 local_2b8;
  byte local_2b6;
  undefined4 local_2b5;
  undefined1 local_2b1;
  undefined8 local_2b0;
  undefined8 local_2a8;
  undefined8 uStack_2a0;
  undefined8 local_298;
  undefined8 local_290;
  undefined1 local_288;
  undefined4 local_287;
  undefined2 local_283;
  undefined1 local_281;
  undefined8 local_280;
  undefined4 local_278;
  undefined4 local_274;
  undefined8 local_270;
  undefined8 local_268;
  undefined8 local_260;
  undefined8 local_258;
  ulonglong local_250;
  undefined8 local_248;
  ulonglong local_240 [2];
  ulonglong local_230;
  undefined8 local_228;
  longlong local_218;
  undefined4 local_208;
  undefined1 local_204;
  undefined1 uStack_203;
  undefined2 uStack_202;
  undefined4 uStack_200;
  undefined4 uStack_1fc;
  undefined4 uStack_1f8;
  undefined4 local_1f4;
  undefined4 uStack_1f0;
  undefined4 uStack_1ec;
  undefined4 uStack_1e8;
  undefined4 local_1e4;
  undefined4 uStack_1e0;
  undefined4 uStack_1dc;
  undefined4 uStack_1d8;
  undefined4 uStack_1d4;
  uint uStack_1d0;
  undefined4 local_1cc;
  undefined1 local_1c8 [384];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_318;
  local_2e0 = (undefined1 *)0x0;
  local_2d8 = 0;
  local_2e8[0] = 0;
  local_208 = 0;
  local_204 = 0;
  uStack_203 = 0;
  uStack_202 = 0;
  uStack_200 = 0;
  uStack_1fc = 0;
  uStack_1f8 = 0;
  local_1f4 = 0;
  uStack_1f0 = 0;
  uStack_1ec = 0;
  uStack_1e8 = 0;
  local_1e4 = 0;
  uStack_1e0 = 0;
  uStack_1dc = 0;
  uStack_1d8 = 0;
  uStack_1d4 = 0;
  uStack_1d0 = 0;
  local_1cc = 0;
  local_2c8 = 0;
  local_2c0 = 0;
  local_2b8 = 2;
  local_2b6 = 0;
  local_2b5 = 0;
  local_2b1 = 0;
  local_2b0 = 0;
  local_2a8 = 0;
  uStack_2a0 = 0;
  local_298 = 0;
  local_290 = 0;
  local_288 = 2;
  local_287 = 0;
  local_283 = 0;
  local_281 = 0;
  local_280 = 0;
  local_278 = 0xffffffff;
  local_274 = 0;
  local_270 = 0;
  local_268 = 0;
  local_260 = 0;
  local_258 = 0;
  local_250 = 0;
  local_248 = 0;
  local_240[0] = 0;
  local_240[1] = 0;
  local_230 = 0;
  local_228 = 0;
  local_218 = param_3;
  if ((param_4 & 1) == 0) {
    local_2e0 = local_1c8;
    puVar1 = *(uint **)(param_1 + 4);
    local_2c8 = (ulonglong)
                CONCAT15(*(undefined1 *)((longlong)puVar1 + 5),CONCAT14((char)puVar1[1],param_1[6]))
    ;
    uStack_2a0 = *(undefined8 *)(param_2 + 0x20);
    local_2b8 = CONCAT11((byte)(*puVar1 >> 1) & 1,2);
    local_2b6 = (byte)(*param_1 >> 1) & 1;
    uVar5 = FltGetRequestorProcessId(param_1);
    local_298 = CONCAT44(local_298._4_4_,uVar5);
    lVar7 = FltGetRequestorProcess(param_1);
    if (lVar7 == 0) {
      local_290 = 0;
    }
    else {
      local_290 = PsGetProcessCreateTimeQuadPart(lVar7);
    }
    if (*(longlong *)(param_3 + 0x50) == 0) {
      local_2c0 = param_3;
    }
    else {
      local_2c0 = *(longlong *)(param_3 + 0x50) + 8;
    }
    local_2b8 = CONCAT11(local_2b8._1_1_,*(undefined1 *)(param_3 + 0x48));
    local_2a8 = *(undefined8 *)(param_3 + 0xc0);
    local_2b0 = *(undefined8 *)(param_3 + 0x40);
    local_208 = CONCAT22(local_208._2_2_,0x40);
    uStack_1dc = 0x120000;
    local_204 = *(undefined1 *)(*(longlong *)(param_1 + 4) + 4);
    uStack_203 = 0;
    uStack_1f0 = 0xf681e6cc;
    uStack_1ec = 0x4ee9ec6c;
    uStack_1e8 = 0xc4c0a690;
    local_1e4 = 0xc27632e8;
    local_2d4 = 0;
    while (iVar4 = local_2d4, local_2d4 < *(int *)(param_3 + 200)) {
      iVar6 = *(int *)(param_3 + 0xd0 + (longlong)local_2d4 * 8);
      puVar9 = (undefined8 *)(LogSessions + (longlong)iVar6 * 0x28);
      uStack_200 = (undefined4)*puVar9;
      uStack_1fc = (undefined4)((ulonglong)*puVar9 >> 0x20);
      if (*(int *)((longlong)puVar9 + 0xc) == *(int *)(param_3 + 0xcc + (longlong)local_2d4 * 8)) {
        uVar10 = 1 << ((byte)iVar6 & 0x1f);
        if ((*(uint *)(param_3 + 0x60) & uVar10) != 0) {
          local_280 = *(undefined8 *)(param_3 + 0x58);
        }
        if ((*(uint *)(param_3 + 0x6c) & uVar10) != 0) {
          local_278 = *(undefined4 *)(param_3 + 0x68);
        }
        if ((*(uint *)(param_3 + 0x78) & uVar10) != 0) {
          local_258 = *(undefined8 *)(param_3 + 0x70);
        }
        if ((*(uint *)(param_3 + 0x98) & uVar10) != 0) {
          local_270 = *(undefined8 *)(param_3 + 0x80);
          local_268 = CONCAT44(local_268._4_4_,*(undefined4 *)(param_3 + 0x88));
          local_260 = *(undefined8 *)(param_3 + 0x90);
        }
        if ((*(uint *)(param_3 + 0xac) & uVar10) != 0) {
          local_248 = *(undefined8 *)(param_3 + 0xa0);
          local_250 = CONCAT44(local_250._4_4_,*(undefined4 *)(param_3 + 0xa8));
        }
        if ((*(uint *)(param_3 + 0xbc) & uVar10) != 0) {
          local_228 = *(undefined8 *)(param_3 + 0xb0);
          local_230 = CONCAT44(local_230._4_4_,*(undefined4 *)(param_3 + 0xb8));
        }
        local_240[0] = local_240[0] & 0xffffffff00000000;
        local_240[1] = 0;
        SetCallResult((longlong)param_1,(ulonglong)*(uint *)((longlong)puVar9 + 0x1c),
                      (undefined4 *)local_240,local_240 + 1);
        uVar8 = FormatFileTraceEvent
                          ((longlong)puVar9,(undefined4 *)&local_2c8,local_2e8,&local_2d8,
                           (longlong *)&local_2e0);
        puVar3 = local_2e0;
        if ((char)uVar8 == '\0') break;
        uStack_1d8 = SUB84(local_2e0,0);
        uStack_1d4 = (undefined4)((ulonglong)local_2e0 >> 0x20);
        uStack_1d0 = local_2d8;
        iVar6 = IoWMIWriteEvent(&local_208);
        if ((iVar6 == -0x3ffffff8) && (lVar7 = FltAllocateGenericWorkItem(), lVar7 != 0)) {
          puVar9 = (undefined8 *)ExAllocatePoolWithTag(0x200,8,0x72744c46);
          if (puVar9 != (undefined8 *)0x0) {
            *puVar9 = CONCAT44(uStack_1fc,uStack_200);
            iVar6 = FltQueueGenericWorkItem(lVar7,DAT_140008110,DisableSession,1);
            if (-1 < iVar6) goto LAB_140002127;
            ExFreePoolWithTag(puVar9,0x72744c46);
          }
          FltFreeGenericWorkItem(lVar7);
        }
LAB_140002127:
        if (local_2e8[0] == 1) {
          ExFreeToNPagedLookasideList(&DAT_1400081c0,puVar3);
LAB_14000215e:
          local_2e8[0] = 0;
        }
        else if (local_2e8[0] == 2) {
          ExFreePoolWithTag(puVar3,0x72744c46);
          goto LAB_14000215e;
        }
        local_2e0 = local_1c8;
        local_278 = 0xffffffff;
        local_280 = 0;
        local_270 = 0;
        local_260 = 0;
        local_248 = 0;
        local_250 = local_250 & 0xffffffff00000000;
        local_240[1] = 0;
        local_240[0] = local_240[0] & 0xffffffff00000000;
        local_228 = 0;
        local_230 = local_230 & 0xffffffff00000000;
        local_288 = 2;
        local_258 = 0;
      }
      local_2d4 = iVar4 + 1;
    }
  }
  FltReleaseContext(*(undefined8 *)(param_3 + 0xc0));
  if (*(longlong *)(param_3 + 0xa0) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_3 + 0xa0),0x72744c46);
  }
  if (*(longlong *)(param_3 + 0x90) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_3 + 0x90),0x72744c46);
  }
  if (*(longlong *)(param_3 + 0xb0) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_3 + 0xb0),0x72744c46);
  }
  pcVar2 = *(char **)(param_3 + 0x50);
  if (pcVar2 != (char *)0x0) {
    if (*pcVar2 == '\x01') {
      ExFreePoolWithTag(pcVar2,0x72744c46);
    }
    else {
      ExFreeToNPagedLookasideList(&DAT_1400081c0,pcVar2);
    }
  }
  ExFreeToNPagedLookasideList(&DAT_140008140,param_3);
  if (local_2e8[0] == 1) {
    ExFreeToNPagedLookasideList(&DAT_1400081c0,local_2e0);
  }
  else if (local_2e8[0] == 2) {
    ExFreePoolWithTag(local_2e0,0x72744c46);
  }
  return 0;
}



===== FTPreOpCallback @ 140002300 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FTPreOpCallback(longlong param_1,longlong param_2,longlong *param_3)

{
  char *pcVar1;
  char cVar2;
  ushort uVar3;
  short sVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  longlong lVar8;
  void *_Dst;
  longlong lVar9;
  ulonglong uVar10;
  undefined8 uVar11;
  byte bVar12;
  longlong lVar13;
  undefined1 uVar14;
  undefined1 auStack_128 [32];
  char local_108;
  undefined1 local_107 [3];
  int local_104;
  int local_100;
  longlong local_f8;
  int local_f0;
  int local_ec;
  uint local_e8;
  int local_e4;
  longlong local_e0;
  longlong local_d8;
  longlong local_d0;
  longlong local_c8;
  undefined8 local_c0;
  undefined1 *local_b8;
  int local_b0;
  uint local_ac;
  uint local_a8;
  longlong local_a0;
  short *local_98;
  undefined8 local_90;
  undefined1 *local_88;
  longlong *local_80;
  undefined1 local_78 [24];
  undefined1 local_60 [24];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_128;
  local_ec = -1;
  local_a0 = 0;
  local_104 = 0;
  local_108 = '\0';
  local_e0 = 0;
  local_f8 = 0;
  local_c8 = 0;
  local_e8 = 0;
  local_d8 = 0;
  local_e4 = 0;
  local_d0 = 0;
  local_80 = param_3;
  lVar8 = IoGetTopLevelIrp();
  if (lVar8 != 0) {
    return 1;
  }
  local_ac = (uint)*(byte *)(*(longlong *)(param_1 + 0x10) + 4);
  _Dst = (void *)ExAllocateFromNPagedLookasideList(&DAT_140008140);
  *param_3 = (longlong)_Dst;
  if (_Dst != (void *)0x0) {
    memset(_Dst,0,0x110);
    *(longlong *)(*param_3 + 8) = *param_3 + 0x10;
    *(undefined2 *)(*param_3 + 2) = 0x30;
    iVar5 = FltGetVolumeContext(DAT_140008110,*(undefined8 *)(param_2 + 0x10),&local_e0);
    if (-1 < iVar5) {
      local_f0 = 0;
      local_100 = 0;
      while (iVar5 = local_100, lVar8 = LogSessions, iVar6 = 0, local_100 < 8) {
        lVar9 = (longlong)local_100;
        local_b0 = *(int *)(LogSessions + 0xc + lVar9 * 0x28);
        if ((((local_b0 != 0) &&
             ((*(uint *)(LogSessions + 0x14 + lVar9 * 0x28) >> (local_ac & 0x1f) & 1) != 0)) &&
            ((uVar7 = *(uint *)(LogSessions + 0x20 + lVar9 * 0x28), (uVar7 >> 0x1a & 1) != 0 ||
             ((*(uint *)(local_e0 + 0x1e0) & uVar7) != 0)))) &&
           (((**(uint **)(param_1 + 0x10) & 2) == 0 ||
            ((*(uint *)(LogSessions + 0x1c + lVar9 * 0x28) >> 8 & 1) == 0)))) {
          lVar13 = (longlong)local_100;
          *(int *)(*param_3 + 0xd0 + (longlong)local_f0 * 8) = local_100;
          *(int *)(*param_3 + 0xcc + (longlong)local_f0 * 8) = local_b0;
          local_f0 = local_f0 + 1;
          *(int *)(*param_3 + 200) = local_f0;
          if (((**(uint **)(param_1 + 0x10) & 2) == 0) &&
             ((*(uint *)(lVar8 + 0x1c + lVar9 * 0x28) & 4) != 0)) {
            if (local_c8 == 0) {
              GetLastAccessTime(param_1,param_2,&local_c8);
            }
            *(longlong *)(*param_3 + 0x58) = local_c8;
          }
          if ((*(uint *)(LogSessions + 0x1c + lVar13 * 0x28) & 2) != 0) {
            if (local_ec == -1) {
              iVar6 = -1;
              lVar8 = FltGetRequestorProcess(param_1);
              if (lVar8 != 0) {
                iVar6 = PsGetProcessSessionId(lVar8);
              }
              local_ec = iVar6;
            }
            *(int *)(*param_3 + 0x68) = local_ec;
          }
          lVar8 = local_a0;
          if ((char)*(undefined4 *)(LogSessions + 0x1c + lVar13 * 0x28) < '\0') {
            if ((local_a0 == 0) && (lVar9 = FltGetRequestorProcess(param_1), lVar9 != 0)) {
              lVar8 = PsGetProcessWin32WindowStation(lVar9);
              local_a0 = lVar8;
            }
            *(longlong *)(*param_3 + 0x70) = lVar8;
          }
          uVar7 = **(uint **)(param_1 + 0x10);
          bVar12 = (byte)iVar5;
          if ((uVar7 & 2) == 0) {
            if (GlobalLateBoundFunctions == (code *)0x0) {
LAB_1400025f3:
              if ((uVar7 & 2) != 0) goto LAB_140002646;
            }
            else {
              cVar2 = (*GlobalLateBoundFunctions)();
              if (cVar2 != '\0') {
                uVar7 = **(uint **)(param_1 + 0x10);
                goto LAB_1400025f3;
              }
            }
            if ((*(uint *)(LogSessions + 0x1c + lVar13 * 0x28) & 1) != 0) {
              lVar8 = *param_3;
              if (*(longlong *)(lVar8 + 0x80) == 0) {
                GetUserSidAndAcessToken
                          (param_1,(uint *)(lVar8 + 0x88),(undefined8 *)(lVar8 + 0x90),
                           (longlong *)(lVar8 + 0x80));
              }
              *(uint *)(*param_3 + 0x98) = 1 << (bVar12 & 0x1f) | *(uint *)(*param_3 + 0x98);
            }
          }
LAB_140002646:
          if ((*(uint *)(LogSessions + 0x1c + lVar13 * 0x28) & 8) != 0) {
            if (local_d8 == 0) {
              CreateParameterBlob(param_1,&local_e8,&local_d8);
            }
            *(longlong *)(*param_3 + 0xa0) = local_d8;
            *(uint *)(*param_3 + 0xa8) = local_e8;
          }
          if (((**(uint **)(param_1 + 0x10) & 2) == 0) &&
             ((*(uint *)(LogSessions + 0x1c + lVar13 * 0x28) & 0x20) != 0)) {
            if (local_d0 == 0) {
              GetPreviousValue(param_1,param_2,&local_e4,&local_d0);
            }
            *(longlong *)(*param_3 + 0xb0) = local_d0;
            *(int *)(*param_3 + 0xb8) = local_e4;
          }
          lVar8 = LogSessions;
          if ((*(uint *)(LogSessions + 0x1c + lVar13 * 0x28) & 4) != 0) {
            *(uint *)(*param_3 + 0x60) = 1 << (bVar12 & 0x1f) | *(uint *)(*param_3 + 0x60);
          }
          if ((*(uint *)(lVar8 + 0x1c + lVar13 * 0x28) & 2) != 0) {
            *(uint *)(*param_3 + 0x6c) = 1 << (bVar12 & 0x1f) | *(uint *)(*param_3 + 0x6c);
          }
          if ((char)*(undefined4 *)(lVar8 + 0x1c + lVar13 * 0x28) < '\0') {
            *(uint *)(*param_3 + 0x78) = 1 << (bVar12 & 0x1f) | *(uint *)(*param_3 + 0x78);
          }
          if ((*(uint *)(lVar8 + 0x1c + lVar13 * 0x28) & 8) != 0) {
            *(uint *)(*param_3 + 0xac) = 1 << (bVar12 & 0x1f) | *(uint *)(*param_3 + 0xac);
          }
          if ((*(uint *)(lVar8 + 0x1c + lVar13 * 0x28) & 0x20) != 0) {
            *(uint *)(*param_3 + 0xbc) = 1 << (bVar12 & 0x1f) | *(uint *)(*param_3 + 0xbc);
          }
          local_108 = '\x01';
        }
        local_100 = iVar5 + 1;
      }
      if (local_108 != '\0') {
        *(longlong *)(*param_3 + 0xc0) = local_e0;
        *(undefined1 *)(*param_3 + 0x48) = 2;
        local_c8 = _DAT_fffff78000000014;
        *(longlong *)(*param_3 + 0x40) = _DAT_fffff78000000014;
        if (*(longlong *)(param_2 + 0x20) == 0) {
          local_90 = 0;
          local_88 = local_60;
          RtlInitUnicodeString(&local_90,L"0x00000000");
          iVar5 = RtlAppendUnicodeToString(*param_3,L":00000001-");
          if (-1 < iVar5) {
            RtlAppendUnicodeStringToString(*param_3,&local_90);
          }
          goto LAB_140002a66;
        }
        uVar7 = FltGetFileNameInformation(param_1,DAT_140008244 | 1,&local_f8);
        uVar10 = (ulonglong)uVar7;
        if ((int)uVar7 < 0) {
          local_b8 = local_78;
          local_c0 = 0x120000;
          iVar5 = RtlAppendUnicodeToString(*param_3,L":00000000-");
          if (-1 < iVar5) {
            local_98 = (short *)0x0;
            if (((local_b8 == (undefined1 *)0x0) || ((short)local_c0 != 0)) ||
               (local_c0._2_2_ < 0x12)) {
              iVar6 = -0x3ffffff3;
              local_a8 = uVar7;
            }
            else {
              local_98 = (short *)(local_b8 + 0x10);
              *local_98 = 0;
              do {
                uVar3 = (ushort)uVar10 & 0xf;
                if (uVar3 < 10) {
                  sVar4 = uVar3 + 0x30;
                }
                else {
                  sVar4 = uVar3 + 0x37;
                }
                local_98 = local_98 + -1;
                *local_98 = sVar4;
                uVar10 = uVar10 >> 4;
              } while ((int)uVar10 != 0);
              local_c0 = CONCAT62(local_c0._2_6_,0x12);
              local_a8 = 0;
            }
            if (-1 < iVar6) {
              RtlAppendUnicodeStringToString(*param_3,&local_c0);
            }
          }
LAB_1400029b1:
          if (((**(uint **)(param_1 + 0x10) & 2) == 0) &&
             (*(longlong *)(*(longlong *)(param_2 + 0x20) + 0x18) != 0)) {
            local_107[0] = 0;
            iVar5 = FltIsDirectory(*(undefined8 *)(*(uint **)(param_1 + 0x10) + 2),
                                   *(undefined8 *)(param_2 + 0x18),local_107);
            uVar14 = 4;
            if (-1 < iVar5) {
              uVar14 = local_107[0];
            }
            *(undefined1 *)(*param_3 + 0x48) = uVar14;
          }
          else {
            *(undefined1 *)(*param_3 + 0x48) = 3;
          }
          goto LAB_140002a66;
        }
        uVar10 = Feature_4048438587__private_IsEnabledDeviceUsageNoInline();
        uVar3 = 0x7e8;
        if ((int)uVar10 == 0) {
          uVar3 = 0x7ff;
        }
        if (uVar3 < *(ushort *)(local_f8 + 8)) {
          uVar11 = ExAllocatePoolWithTag
                             (0x200,(ulonglong)*(ushort *)(local_f8 + 8) + 0x18,0x72744c46);
          *(undefined8 *)(*param_3 + 0x50) = uVar11;
          if (*(undefined1 **)(*param_3 + 0x50) != (undefined1 *)0x0) {
            **(undefined1 **)(*param_3 + 0x50) = 1;
LAB_14000296f:
            lVar8 = *(longlong *)(*param_3 + 0x50);
            uVar11 = *(undefined8 *)(local_f8 + 0x10);
            *(undefined8 *)(lVar8 + 8) = *(undefined8 *)(local_f8 + 8);
            *(undefined8 *)(lVar8 + 0x10) = uVar11;
            memmove((void *)(*(longlong *)(*param_3 + 0x50) + 0x18),*(void **)(local_f8 + 0x10),
                    (ulonglong)*(ushort *)(local_f8 + 8));
            *(longlong *)(*(longlong *)(*param_3 + 0x50) + 0x10) =
                 *(longlong *)(*param_3 + 0x50) + 0x18;
            goto LAB_1400029b1;
          }
        }
        else {
          uVar11 = ExAllocateFromNPagedLookasideList(&DAT_1400081c0);
          *(undefined8 *)(*param_3 + 0x50) = uVar11;
          if (*(undefined1 **)(*param_3 + 0x50) != (undefined1 *)0x0) {
            **(undefined1 **)(*param_3 + 0x50) = 0;
            goto LAB_14000296f;
          }
        }
      }
    }
  }
  local_104 = 1;
LAB_140002a66:
  if (local_f8 != 0) {
    FltReleaseFileNameInformation();
  }
  if (local_104 == 1) {
    if (local_e0 != 0) {
      FltReleaseContext();
    }
    if (local_d8 != 0) {
      ExFreePoolWithTag(local_d8,0x72744c46);
    }
    if (local_d0 != 0) {
      ExFreePoolWithTag(local_d0,0x72744c46);
    }
    if (*param_3 != 0) {
      lVar8 = *(longlong *)(*param_3 + 0x90);
      if (lVar8 != 0) {
        ExFreePoolWithTag(lVar8,0x72744c46);
      }
      pcVar1 = *(char **)(*param_3 + 0x50);
      if (pcVar1 != (char *)0x0) {
        if (*pcVar1 == '\x01') {
          ExFreePoolWithTag(pcVar1,0x72744c46);
        }
        else {
          ExFreeToNPagedLookasideList(&DAT_1400081c0,pcVar1);
        }
      }
      ExFreeToNPagedLookasideList(&DAT_140008140,*param_3);
      *param_3 = 0;
    }
  }
  return local_104;
}



===== FTReleaseOpResources @ 140002b5c =====

void FTReleaseOpResources(longlong param_1)

{
  char *pcVar1;
  
  FltReleaseContext(*(undefined8 *)(param_1 + 0xc0));
  if (*(longlong *)(param_1 + 0xa0) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0xa0),0x72744c46);
  }
  if (*(longlong *)(param_1 + 0x90) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x90),0x72744c46);
  }
  if (*(longlong *)(param_1 + 0xb0) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0xb0),0x72744c46);
  }
  pcVar1 = *(char **)(param_1 + 0x50);
  if (pcVar1 != (char *)0x0) {
    if (*pcVar1 == '\x01') {
      ExFreePoolWithTag(pcVar1,0x72744c46);
    }
    else {
      ExFreeToNPagedLookasideList(&DAT_1400081c0,pcVar1);
    }
  }
  ExFreeToNPagedLookasideList(&DAT_140008140,param_1);
  return;
}



===== FTShutdownCallback @ 140002c30 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FTShutdownCallback(uint *param_1,longlong param_2)

{
  undefined8 *puVar1;
  uint *puVar2;
  undefined4 uVar3;
  int iVar4;
  longlong lVar5;
  undefined8 uVar6;
  undefined1 auStackY_2d8 [32];
  int local_2a8 [2];
  undefined1 *local_2a0;
  int local_298;
  uint local_294;
  uint local_290 [2];
  undefined8 local_288;
  undefined8 local_280;
  ushort local_278;
  byte local_276;
  undefined4 local_275;
  undefined1 local_271;
  undefined8 local_270;
  longlong local_268;
  undefined8 uStack_260;
  undefined8 local_258;
  undefined8 local_250;
  undefined1 local_248;
  undefined4 local_247;
  undefined2 local_243;
  undefined1 local_241;
  undefined8 local_240;
  undefined4 local_238;
  undefined4 local_234;
  undefined8 local_230;
  undefined8 local_228;
  undefined8 local_220;
  undefined8 local_218;
  undefined8 local_210;
  undefined8 local_208;
  undefined8 local_200;
  undefined8 local_1f8;
  undefined8 local_1f0;
  undefined8 local_1e8;
  undefined4 local_1d8;
  undefined1 local_1d4;
  undefined1 uStack_1d3;
  undefined2 uStack_1d2;
  undefined4 uStack_1d0;
  undefined4 uStack_1cc;
  undefined4 uStack_1c8;
  undefined4 local_1c4;
  undefined4 uStack_1c0;
  undefined4 uStack_1bc;
  undefined4 uStack_1b8;
  undefined4 local_1b4;
  undefined4 uStack_1b0;
  undefined4 uStack_1ac;
  undefined8 uStack_1a8;
  undefined4 uStack_1a0;
  undefined4 local_19c;
  undefined1 local_198 [384];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_2d8;
  local_2a0 = (undefined1 *)0x0;
  local_290[0] = 0;
  local_2a8[0] = 0;
  local_1d8 = 0;
  local_1d4 = 0;
  uStack_1d3 = 0;
  uStack_1d2 = 0;
  uStack_1d0 = 0;
  uStack_1cc = 0;
  uStack_1c8 = 0;
  local_1c4 = 0;
  uStack_1c0 = 0;
  uStack_1bc = 0;
  uStack_1b8 = 0;
  local_1b4 = 0;
  uStack_1b0 = 0;
  uStack_1ac = 0;
  uStack_1a8._0_4_ = 0;
  uStack_1a8._4_4_ = 0;
  uStack_1a0 = 0;
  local_19c = 0;
  local_288 = 0;
  local_280 = 0;
  local_278 = 2;
  local_276 = 0;
  local_275 = 0;
  local_271 = 0;
  local_270 = 0;
  local_268 = 0;
  uStack_260 = 0;
  local_258 = 0;
  local_250 = 0;
  local_248 = 2;
  local_247 = 0;
  local_243 = 0;
  local_241 = 0;
  local_240 = 0;
  local_238 = 0xffffffff;
  local_234 = 0;
  local_230 = 0;
  local_228 = 0;
  local_220 = 0;
  local_218 = 0;
  local_210 = 0;
  local_208 = 0;
  local_200 = 0;
  local_1f8 = 0;
  local_1f0 = 0;
  local_1e8 = 0;
  local_294 = (uint)*(byte *)(*(longlong *)(param_1 + 4) + 4);
  lVar5 = IoGetTopLevelIrp();
  uVar6 = local_288;
  if (lVar5 == 0) {
    local_2a0 = local_198;
    puVar2 = *(uint **)(param_1 + 4);
    local_288._6_2_ = SUB82(uVar6,6);
    local_288._0_6_ =
         CONCAT15(*(undefined1 *)((longlong)puVar2 + 5),CONCAT14((char)puVar2[1],param_1[6]));
    uStack_260 = *(undefined8 *)(param_2 + 0x20);
    local_278 = CONCAT11((char)(*puVar2 >> 1),(undefined1)local_278) & 0x1ff;
    local_276 = (byte)(*param_1 >> 1) & 1;
    uVar3 = FltGetRequestorProcessId(param_1);
    local_258 = CONCAT44(local_258._4_4_,uVar3);
    lVar5 = FltGetRequestorProcess(param_1);
    if (lVar5 == 0) {
      local_250 = 0;
    }
    else {
      local_250 = PsGetProcessCreateTimeQuadPart(lVar5);
    }
    iVar4 = FltGetVolumeContext(DAT_140008110,*(undefined8 *)(param_2 + 0x10),&local_268);
    if (-1 < iVar4) {
      local_1d8 = CONCAT22(local_1d8._2_2_,0x40);
      uStack_1ac = 0x120000;
      local_1d4 = *(undefined1 *)(*(longlong *)(param_1 + 4) + 4);
      uStack_1d3 = 0;
      uStack_1c0 = 0xf681e6cc;
      uStack_1bc = 0x4ee9ec6c;
      uStack_1b8 = 0xc4c0a690;
      local_1b4 = 0xc27632e8;
      uStack_1a8 = local_198;
      uStack_1a0 = 0;
      for (local_298 = 0; local_298 < 8; local_298 = local_298 + 1) {
        lVar5 = (longlong)local_298;
        iVar4 = *(int *)(LogSessions + 0xc + lVar5 * 0x28);
        puVar1 = (undefined8 *)(LogSessions + lVar5 * 0x28);
        uStack_1d0 = (undefined4)*puVar1;
        uStack_1cc = (undefined4)((ulonglong)*puVar1 >> 0x20);
        if ((((iVar4 != 0) && (iVar4 == *(int *)((longlong)puVar1 + 0xc))) &&
            ((*(uint *)(LogSessions + 0x14 + lVar5 * 0x28) >> (local_294 & 0x1f) & 1) != 0)) &&
           (((*(uint *)(puVar1 + 4) >> 0x1a & 1) != 0 ||
            ((*(uint *)(local_268 + 0x1e0) & *(uint *)(puVar1 + 4)) != 0)))) {
          uVar6 = FormatFileTraceEvent
                            ((longlong)puVar1,(undefined4 *)&local_288,local_2a8,local_290,
                             (longlong *)&local_2a0);
          if ((char)uVar6 == '\0') break;
          IoWMIWriteEvent(&local_1d8);
        }
      }
    }
  }
  if (local_268 != 0) {
    FltReleaseContext();
  }
  if (local_2a8[0] == 1) {
    ExFreeToNPagedLookasideList(&DAT_1400081c0,local_2a0);
  }
  else if (local_2a8[0] == 2) {
    ExFreePoolWithTag(local_2a0,0x72744c46);
  }
  return 1;
}



===== Feature_1307199801__private_IsEnabledDeviceUsageNoInline @ 140002fa4 =====

ulonglong Feature_1307199801__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)(uint)Feature_1307199801__private_featureState;
  if (((uint)Feature_1307199801__private_featureState & 0x10) == 0) {
    uVar1 = Feature_1307199801__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)((uint)Feature_1307199801__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_1307199801__private_IsEnabledFallback @ 140002fdc =====

void Feature_1307199801__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_1307199801__private_descriptor);
  return;
}



===== Feature_4048438587__private_IsEnabledDeviceUsageNoInline @ 140002ff8 =====

ulonglong Feature_4048438587__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)(uint)Feature_4048438587__private_featureState;
  if (((uint)Feature_4048438587__private_featureState & 0x10) == 0) {
    uVar1 = Feature_4048438587__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)((uint)Feature_4048438587__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_4048438587__private_IsEnabledFallback @ 140003030 =====

void Feature_4048438587__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&wil_details_featureDescriptors_a);
  return;
}



===== FormatFileTraceEvent @ 14000304c =====

undefined8
FormatFileTraceEvent
          (longlong param_1,undefined4 *param_2,undefined4 *param_3,uint *param_4,longlong *param_5)

{
  int *piVar1;
  int iVar2;
  ushort uVar3;
  uint uVar4;
  ushort *puVar5;
  short *psVar6;
  byte bVar7;
  uint uVar8;
  longlong lVar9;
  void *pvVar10;
  uint uVar11;
  ulonglong uVar12;
  int iVar13;
  uint uVar14;
  undefined4 *puVar15;
  undefined4 *_Dst;
  undefined2 *puVar16;
  
  puVar15 = (undefined4 *)*param_5;
  LOCK();
  piVar1 = (int *)(param_1 + 0x10);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + 1;
  UNLOCK();
  *param_4 = 0x56;
  puVar5 = *(ushort **)(param_2 + 2);
  if (puVar5 == (ushort *)0x0) {
LAB_1400030d9:
    uVar11 = 0x58;
  }
  else if ((*(short **)(puVar5 + 4) == (short *)0x0) || (**(short **)(puVar5 + 4) == 0x3a)) {
LAB_1400030c3:
    if (((puVar5 == (ushort *)0x0) || (*(longlong *)(puVar5 + 4) == 0)) ||
       (uVar11 = *puVar5 + 0x58, *puVar5 == 0)) goto LAB_1400030d9;
  }
  else {
    if (*puVar5 <= **(ushort **)(param_2 + 8)) goto LAB_1400030c3;
    uVar11 = ((uint)*puVar5 - (uint)**(ushort **)(param_2 + 8)) + 0x58;
  }
  *param_4 = uVar11;
  puVar5 = (ushort *)(*(longlong *)(param_2 + 8) + 0x10);
  if (((puVar5 != (ushort *)0x0) && (*(longlong *)(*(longlong *)(param_2 + 8) + 0x18) != 0)) &&
     (uVar3 = *puVar5, uVar3 != 0)) {
    uVar11 = uVar3 + uVar11;
  }
  uVar11 = uVar11 + 2;
  *param_4 = uVar11;
  puVar5 = *(ushort **)(param_2 + 8);
  if (((puVar5 == (ushort *)0x0) || (*(longlong *)(puVar5 + 4) == 0)) ||
     (uVar8 = uVar11 + *puVar5, *puVar5 == 0)) {
    uVar8 = uVar11;
  }
  uVar8 = uVar8 + 2;
  *param_4 = uVar8;
  puVar5 = (ushort *)(*(longlong *)(param_2 + 8) + 0x20);
  if (((puVar5 != (ushort *)0x0) && (*(longlong *)(*(longlong *)(param_2 + 8) + 0x28) != 0)) &&
     (uVar3 = *puVar5, uVar3 != 0)) {
    uVar8 = uVar3 + uVar8;
  }
  *param_4 = uVar8 + 2;
  if (*(longlong *)(param_2 + 0x24) == 0) {
LAB_1400031a2:
    uVar11 = 0;
  }
  else {
    MmIsAddressValid();
    bVar7 = KeGetCurrentIrql();
    if ((1 < bVar7) || (*(char *)((longlong)param_2 + 0x11) != '\0')) {
      *(undefined8 *)(param_2 + 0x24) = 0;
      goto LAB_1400031a2;
    }
    uVar11 = param_2[0x22];
    if (0x400 < uVar11) {
      uVar11 = 0x400;
    }
  }
  uVar8 = param_2[0x1e];
  uVar4 = param_2[0x26];
  iVar13 = 4;
  if (param_2[0x18] != 0) {
    iVar13 = param_2[0x18];
  }
  uVar14 = iVar13 + *param_4 + uVar4 + uVar8 + uVar11;
  *param_4 = uVar14;
  if (0x180 < uVar14) {
    if (uVar14 < 0x801) {
      lVar9 = ExAllocateFromNPagedLookasideList(&DAT_1400081c0);
      *param_5 = lVar9;
      if (lVar9 == 0) {
        return 0;
      }
      *param_3 = 1;
    }
    else {
      lVar9 = ExAllocatePoolWithTag(0x200,uVar14,0x72744c46);
      *param_5 = lVar9;
      if (lVar9 == 0) {
        return 0;
      }
      *param_3 = 2;
    }
    puVar15 = (undefined4 *)*param_5;
  }
  *puVar15 = *param_2;
  *(char *)(param_2 + 1) = *(char *)(param_2 + 1) + '\x16';
  *(undefined1 *)(puVar15 + 1) = *(undefined1 *)(param_2 + 1);
  *(undefined1 *)((longlong)puVar15 + 5) = *(undefined1 *)((longlong)param_2 + 5);
  *(int *)((longlong)puVar15 + 6) = iVar2 + 1;
  *(undefined1 *)((longlong)puVar15 + 10) = *(undefined1 *)((longlong)param_2 + 0x11);
  *(undefined1 *)((longlong)puVar15 + 0xb) = *(undefined1 *)((longlong)param_2 + 0x12);
  *(undefined1 *)(puVar15 + 3) = *(undefined1 *)(param_2 + 4);
  *(undefined1 *)((longlong)puVar15 + 0xd) = *(undefined1 *)(param_2 + 0x10);
  *(undefined8 *)((longlong)puVar15 + 0xe) = *(undefined8 *)(param_2 + 6);
  *(undefined4 *)((longlong)puVar15 + 0x16) = param_2[0xc];
  *(undefined8 *)((longlong)puVar15 + 0x1a) = *(undefined8 *)(param_2 + 0xe);
  *(undefined8 *)((longlong)puVar15 + 0x22) = *(undefined8 *)(param_2 + 10);
  *(undefined8 *)((longlong)puVar15 + 0x2a) = *(undefined8 *)(param_2 + 0x12);
  *(undefined4 *)((longlong)puVar15 + 0x32) = param_2[0x14];
  *(undefined8 *)((longlong)puVar15 + 0x36) = *(undefined8 *)(param_2 + 0x1c);
  *(undefined8 *)((longlong)puVar15 + 0x3e) = *(undefined8 *)(param_2 + 0x16);
  *(undefined4 *)((longlong)puVar15 + 0x46) = param_2[0x18];
  *(uint *)((longlong)puVar15 + 0x4a) = uVar8;
  *(uint *)((longlong)puVar15 + 0x4e) = uVar11;
  *(uint *)((longlong)puVar15 + 0x52) = uVar4;
  _Dst = (undefined4 *)((longlong)puVar15 + 0x56);
  if ((param_2[0x18] == 0) || (*(void **)(param_2 + 0x1a) == (void *)0x0)) {
    *_Dst = 0;
    puVar16 = (undefined2 *)((longlong)puVar15 + 0x5a);
  }
  else {
    memmove(_Dst,*(void **)(param_2 + 0x1a),(ulonglong)(uint)param_2[0x18]);
    puVar16 = (undefined2 *)((longlong)_Dst + (ulonglong)(uint)param_2[0x18]);
  }
  if ((uVar8 != 0) && (*(void **)(param_2 + 0x20) != (void *)0x0)) {
    memmove(puVar16,*(void **)(param_2 + 0x20),(ulonglong)uVar8);
    puVar16 = (undefined2 *)((longlong)puVar16 + (ulonglong)uVar8);
  }
  if ((uVar11 != 0) && (*(void **)(param_2 + 0x24) != (void *)0x0)) {
    memmove(puVar16,*(void **)(param_2 + 0x24),(ulonglong)uVar11);
    puVar16 = (undefined2 *)((longlong)puVar16 + (ulonglong)uVar11);
  }
  if ((uVar4 != 0) && (*(void **)(param_2 + 0x28) != (void *)0x0)) {
    memmove(puVar16,*(void **)(param_2 + 0x28),(ulonglong)uVar4);
    puVar16 = (undefined2 *)((longlong)puVar16 + (ulonglong)uVar4);
  }
  puVar5 = *(ushort **)(param_2 + 2);
  if (puVar5 == (ushort *)0x0) goto LAB_1400033d3;
  psVar6 = *(short **)(puVar5 + 4);
  if ((psVar6 == (short *)0x0) || (*psVar6 == 0x3a)) {
LAB_1400033ac:
    if ((puVar5 == (ushort *)0x0) || (*(void **)(puVar5 + 4) == (void *)0x0)) goto LAB_1400033d3;
    memmove(puVar16,*(void **)(puVar5 + 4),(ulonglong)*puVar5);
    uVar12 = (ulonglong)**(ushort **)(param_2 + 2);
  }
  else {
    uVar3 = **(ushort **)(param_2 + 8);
    if (*puVar5 <= uVar3) goto LAB_1400033ac;
    memmove(puVar16,(void *)((longlong)psVar6 + (ulonglong)uVar3),
            (ulonglong)*puVar5 - (ulonglong)uVar3);
    uVar12 = (ulonglong)**(ushort **)(param_2 + 2) - (ulonglong)**(ushort **)(param_2 + 8);
  }
  puVar16 = (undefined2 *)((longlong)puVar16 + uVar12);
LAB_1400033d3:
  *puVar16 = 0;
  puVar16 = puVar16 + 1;
  puVar5 = (ushort *)(*(longlong *)(param_2 + 8) + 0x20);
  if ((puVar5 != (ushort *)0x0) &&
     (pvVar10 = *(void **)(*(longlong *)(param_2 + 8) + 0x28), pvVar10 != (void *)0x0)) {
    memmove(puVar16,pvVar10,(ulonglong)*puVar5);
    puVar16 = (undefined2 *)
              ((ulonglong)*(ushort *)(*(longlong *)(param_2 + 8) + 0x20) + (longlong)puVar16);
  }
  *puVar16 = 0;
  puVar16 = puVar16 + 1;
  pvVar10 = *(void **)(param_2 + 8);
  if (((ushort *)((longlong)pvVar10 + 0x10) != (ushort *)0x0) &&
     (*(void **)((longlong)pvVar10 + 0x18) != (void *)0x0)) {
    memmove(puVar16,*(void **)((longlong)pvVar10 + 0x18),
            (ulonglong)*(ushort *)((longlong)pvVar10 + 0x10));
    pvVar10 = *(void **)(param_2 + 8);
    puVar16 = (undefined2 *)((longlong)puVar16 + (ulonglong)*(ushort *)((longlong)pvVar10 + 0x10));
  }
  *puVar16 = 0;
  puVar16 = puVar16 + 1;
  puVar5 = *(ushort **)(param_2 + 8);
  if ((puVar5 != (ushort *)0x0) && (*(void **)(puVar5 + 4) != (void *)0x0)) {
    pvVar10 = memmove(puVar16,*(void **)(puVar5 + 4),(ulonglong)*puVar5);
    puVar16 = (undefined2 *)((longlong)puVar16 + (ulonglong)**(ushort **)(param_2 + 8));
  }
  *puVar16 = 0;
  return CONCAT71((int7)((ulonglong)pvVar10 >> 8),1);
}



===== SetCallResult @ 1400034a0 =====

void SetCallResult(longlong param_1,ulonglong param_2,undefined4 *param_3,undefined8 *param_4)

{
  char cVar1;
  longlong lVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  
  if ((param_2 & 0x10) == 0) {
    return;
  }
  if (*(int *)(param_1 + 0x18) < 0) {
    return;
  }
  lVar2 = *(longlong *)(param_1 + 0x10);
  cVar1 = *(char *)(lVar2 + 4);
  if (cVar1 == '\x03') {
    *param_3 = *(undefined4 *)(param_1 + 0x20);
    uVar4 = *(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x30);
    goto LAB_1400034fd;
  }
  if (cVar1 == '\x05') {
LAB_1400034ea:
    uVar3 = *(undefined4 *)(lVar2 + 0x18);
  }
  else {
    if (cVar1 == '\a') {
LAB_1400034ca:
      *param_3 = *(undefined4 *)(lVar2 + 0x18);
      uVar4 = *(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x38);
      goto LAB_1400034fd;
    }
    if (cVar1 == '\n') goto LAB_1400034ea;
    if (cVar1 != '\x14') {
      if (cVar1 != '\x19') {
        return;
      }
      goto LAB_1400034ca;
    }
    uVar3 = *(undefined4 *)(lVar2 + 0x20);
  }
  *param_3 = uVar3;
  uVar4 = *(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x28);
LAB_1400034fd:
  *param_4 = uVar4;
  return;
}



===== wil_details_FeatureReporting_RecordUsageInCache @ 140003508 =====

uint * wil_details_FeatureReporting_RecordUsageInCache
                 (uint *param_1,uint *param_2,uint param_3,uint param_4)

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
LAB_140003711:
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
      uVar3 = uVar5 + 1;
      if ((0x1ff < uVar3) || (uVar3 < uVar5)) {
        uVar3 = 1;
        param_1[2] = param_3;
        param_1[1] = uVar5;
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
LAB_1400035e3:
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
      if (param_3 == 4) goto LAB_140003711;
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
          param_1[2] = param_3;
          param_1[1] = 1;
          param_1[3] = param_4;
          return param_1;
        }
        goto LAB_1400035e3;
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
      uVar3 = uVar5 + 1;
      if ((0x7f < uVar3) || (uVar3 < uVar5)) {
        uVar3 = 1;
        param_1[2] = param_3;
        param_1[1] = uVar5;
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



===== wil_details_FeatureReporting_ReportUsageToService @ 1400037fc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void wil_details_FeatureReporting_ReportUsageToService
               (longlong param_1,ulonglong param_2,int param_3)

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
      goto LAB_1400038cd;
    }
    if (param_3 == 2) {
      uVar3 = (uVar2 ^ 1) * 4 + 1;
      goto LAB_1400038cd;
    }
    if (param_3 == 3) {
      uVar3 = (uVar2 ^ 1) * 4 + 2;
      goto LAB_1400038cd;
    }
    if (param_3 == 4) {
      uVar3 = (uVar2 ^ 1) * 4 + 3;
      goto LAB_1400038cd;
    }
    if (param_3 == 5) {
      uVar3 = (uVar2 ^ 1) * 2 + 8;
      goto LAB_1400038cd;
    }
    if (param_3 == 6) {
      uVar3 = (uVar2 ^ 1) * 2 + 9;
      goto LAB_1400038cd;
    }
    bVar4 = (char)param_3 + 0x9c;
    if (bVar4 < 0x32) {
      uVar3 = (-(uint)((param_2 & 1) != 0) & 0xffffffce) + 0x96 + (uint)bVar4;
      goto LAB_1400038cd;
    }
  }
  uVar3 = 0xff;
LAB_1400038cd:
  local_res18[0] = param_3;
  bVar1 = wil_details_FeatureReporting_ReportUsageToServiceDirect(param_1,param_2,uVar3);
  if (((int)CONCAT71(extraout_var,bVar1) != 0) &&
     (g_wil_details_pfnFeatureLoggingHook != (code *)0x0)) {
    (*g_wil_details_pfnFeatureLoggingHook)
              (*(undefined4 *)(param_1 + 0x18),*(undefined8 *)(param_1 + 0x10),0,uVar2,local_res18,0
               ,0,1);
  }
  return;
}



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 140003924 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool wil_details_FeatureReporting_ReportUsageToServiceDirect
               (longlong param_1,undefined8 param_2,uint param_3)

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
              (*(undefined4 *)(param_1 + 0x18),param_3,1,*(undefined8 *)(param_1 + 8));
  }
  if ((((uint)param_2 >> 10 & 1) != 0) && (param_3 != 0xfe)) {
    local_68._0_6_ = CONCAT24((short)param_3,*(undefined4 *)(param_1 + 0x18));
    uVar1 = (uint6)local_68;
    local_68 = (ulonglong)(uint6)local_68;
    if (((uint)param_2 >> 0xb & 1) != 0) {
      local_68 = CONCAT26(1,uVar1);
    }
    RtlNotifyFeatureUsage(&local_68);
  }
  return (int)local_38 == 0;
}



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 140003a14 =====

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
LAB_140003ac7:
    uVar8 = uVar8 << 10;
    if (uVar5 != 0) {
      uVar5 = 0x800;
      goto LAB_140003af5;
    }
  }
  else {
    uVar8 = 0;
    uVar5 = 0;
    uVar11 = (uint)local_70;
    if (iVar4 != 0x117) goto LAB_140003ac7;
    bVar2 = 1;
    uVar8 = (local_58._4_4_ >> 7 & 1) << 10;
  }
  uVar5 = 0;
LAB_140003af5:
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



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 140003c80 =====

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



===== wil_details_IsEnabledFallback @ 140003ce4 =====

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



===== FTContextCleanup @ 140003d80 =====

void FTContextCleanup(longlong param_1,short param_2)

{
  if (param_2 == 1) {
    if (*(longlong *)(param_1 + 8) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_1 + 8),0x72744c46);
    }
    if (*(longlong *)(param_1 + 0x1f0) != 0) {
      ObfDereferenceObject();
    }
  }
  return;
}



===== ThreadTableClear @ 140003dd0 =====

void ThreadTableClear(void)

{
  longlong *plVar1;
  longlong lVar2;
  code *pcVar3;
  longlong *plVar4;
  uint uVar5;
  
  uVar5 = 0;
  plVar4 = &DAT_140008328;
  while( true ) {
    while (plVar1 = (longlong *)*plVar4, plVar1 == plVar4) {
      uVar5 = uVar5 + 1;
      plVar4 = plVar4 + 3;
      if (100 < uVar5) {
        return;
      }
    }
    if (((longlong *)plVar1[1] != plVar4) || (lVar2 = *plVar1, *(longlong **)(lVar2 + 8) != plVar1))
    break;
    *plVar4 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar4;
    ExFreePoolWithTag(plVar1 + -1,0x72744c46);
  }
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  pcVar3 = (code *)swi(3);
  (*pcVar3)();
  return;
}



===== _guard_check_icall @ 140003e50 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 140003e68 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 140003e8c =====

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



===== __GSHandlerCheck_SEH @ 140003ef4 =====

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



===== __cpu_features_init @ 140003f90 =====

/* WARNING: Removing unreachable block (ram,0x000140003ffa) */
/* WARNING: Removing unreachable block (ram,0x000140003fa9) */
/* WARNING: Removing unreachable block (ram,0x000140003f9a) */

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



===== __security_check_cookie @ 140004060 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1400040a0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1400040d0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001400040d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140004100 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memmove @ 140004180 =====

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



===== memset @ 140004480 =====

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



===== __memset_repmovs @ 1400045c0 =====

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



===== __memset_query @ 140004640 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1400046c0 =====

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



===== __memset_spec_ermsb_repmovsb @ 140004800 =====

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



===== __memset_spec_plain @ 140004880 =====

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



===== FTPostOnlyOpCallback$fin$0 @ 14000497d =====

void FTPostOnlyOpCallback_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(longlong *)(param_2 + 0x60) != 0) {
    FltReleaseFileNameInformation();
  }
  if (*(longlong *)(param_2 + 0x50) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 0x50),0x72744c46);
  }
  if (*(longlong *)(param_2 + 0xd0) != 0) {
    FltReleaseContext();
  }
  if (*(longlong *)(param_2 + 0x58) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 0x58),0x72744c46);
  }
  return;
}



===== FTPostOpCallback$fin$0 @ 1400049f8 =====

void FTPostOpCallback_fin_0(undefined8 param_1,longlong param_2)

{
  FTReleaseOpResources(*(longlong *)(param_2 + 0x100));
  if (*(int *)(param_2 + 0x30) == 1) {
    ExFreeToNPagedLookasideList(&DAT_1400081c0,*(undefined8 *)(param_2 + 0x38));
  }
  else if (*(int *)(param_2 + 0x30) == 2) {
    ExFreePoolWithTag(*(undefined8 *)(param_2 + 0x38),0x72744c46);
  }
  return;
}



===== FTPreOpCallback$fin$0 @ 140004a56 =====

void FTPreOpCallback_fin_0(undefined8 param_1,longlong param_2)

{
  longlong *plVar1;
  char *pcVar2;
  
  if (*(longlong *)(param_2 + 0x30) != 0) {
    FltReleaseFileNameInformation();
  }
  if (*(int *)(param_2 + 0x24) == 1) {
    if (*(longlong *)(param_2 + 0x48) != 0) {
      FltReleaseContext();
    }
    if (*(longlong *)(param_2 + 0x50) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_2 + 0x50),0x72744c46);
    }
    if (*(longlong *)(param_2 + 0x58) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_2 + 0x58),0x72744c46);
    }
    plVar1 = *(longlong **)(param_2 + 0xa8);
    if (*plVar1 != 0) {
      if (*(longlong *)(*plVar1 + 0x90) != 0) {
        ExFreePoolWithTag(*(undefined8 *)(*plVar1 + 0x90),0x72744c46);
      }
      if (*(longlong *)(*plVar1 + 0x50) != 0) {
        pcVar2 = *(char **)(*plVar1 + 0x50);
        if (*pcVar2 == '\x01') {
          ExFreePoolWithTag(pcVar2,0x72744c46);
        }
        else {
          ExFreeToNPagedLookasideList(&DAT_1400081c0,pcVar2);
        }
      }
      ExFreeToNPagedLookasideList(&DAT_140008140,*plVar1);
      *plVar1 = 0;
    }
  }
  return;
}



===== FTShutdownCallback$fin$0 @ 140004b64 =====

void FTShutdownCallback_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(longlong *)(param_2 + 0x70) != 0) {
    FltReleaseContext();
  }
  if (*(int *)(param_2 + 0x30) == 1) {
    ExFreeToNPagedLookasideList(&DAT_1400081c0,*(undefined8 *)(param_2 + 0x38));
  }
  else if (*(int *)(param_2 + 0x30) == 2) {
    ExFreePoolWithTag(*(undefined8 *)(param_2 + 0x38),0x72744c46);
  }
  return;
}



===== wil_details_EvaluateFeatureDependencies @ 14000c008 =====

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
    if (*ppuVar2 != (undefined *)0x0) goto joined_r0x00014000c043;
    ppuVar2 = ppuVar2 + 1;
  } while (ppuVar2 < &wil_details_featureDescriptors_z);
LAB_14000c0bd:
  while( true ) {
    if (&UNK_14000701f < ppuVar3) {
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
      if (&UNK_14000701f < ppuVar3) {
        return;
      }
      if (*ppuVar3 != puVar4) break;
      ppuVar3 = ppuVar3 + 1;
    }
  } while( true );
joined_r0x00014000c043:
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
      if (&UNK_14000701f < ppuVar2) goto LAB_14000c0bd;
      if (*ppuVar2 != (undefined *)0x0) break;
      ppuVar2 = ppuVar2 + 1;
    }
  }
  goto LAB_14000c0bd;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 14000c0f8 =====

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
          if (puVar1 == (undefined8 *)0x0) goto LAB_14000c190;
          if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
             (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
          if ((uVar4 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
            uVar4 = 0;
            goto LAB_14000c190;
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
LAB_14000c190:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 14000c1e0 =====

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
              if (&UNK_14000701f < ppuVar2) {
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



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 14000c260 =====

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
    if (*ppuVar3 != (undefined *)0x0) goto LAB_14000c35d;
  }
LAB_14000c366:
  wil_details_EvaluateFeatureDependencies();
  return;
LAB_14000c35d:
  if (ppuVar3 == (undefined **)0x0) goto LAB_14000c366;
  if (((*(char *)((longlong)ppuVar3 + 0x1d) == '\0') &&
      (*(char *)((longlong)ppuVar3 + 0x1e) == '\0')) &&
     (*(char *)((longlong)ppuVar3 + 0x1c) == '\0')) {
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    iVar1 = RtlQueryFeatureConfiguration(*(undefined4 *)(ppuVar3 + 3),1,&local_28,&local_20);
    if ((iVar1 == -0x7fffffde) || (iVar1 == -0x3ffffddb)) {
LAB_14000c32e:
      uVar2 = 0x206;
    }
    else {
      if (iVar1 == 0) {
        uVar2 = (local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0;
      }
      else {
        if (iVar1 != 0x117) goto LAB_14000c32e;
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
    if (&UNK_14000701f < ppuVar3) goto LAB_14000c366;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_14000c35d;
}



===== AttachToRequestedDrives @ 14000c390 =====

void AttachToRequestedDrives(undefined8 param_1,undefined8 param_2,uint *param_3)

{
  uint uVar1;
  ushort uVar2;
  int iVar3;
  longlong lVar4;
  uint uVar5;
  bool bVar6;
  uint uVar7;
  char *pcVar8;
  uint local_res20 [2];
  undefined1 uVar9;
  int local_c4;
  uint uVar10;
  uint local_b8 [2];
  longlong local_b0;
  undefined4 local_a8 [2];
  undefined8 local_a0;
  undefined2 *puStack_98;
  undefined8 *local_90;
  longlong local_88;
  int local_78 [20];
  
  uVar7 = 0;
  local_res20[0] = 0;
  local_b8[0] = 0;
  local_b0 = 0;
  local_a0 = 0;
  puStack_98 = (undefined2 *)0x0;
  DbgPrintEx(0x8e,2,"FileTrace!AttachToRequestedDrives: Start\n");
  uVar1 = *param_3;
  iVar3 = FltEnumerateVolumes(DAT_140008110,0,0,local_res20);
  if (((iVar3 + 0x80000000U & 0x80000000) != 0) || (iVar3 == -0x3fffffdd)) {
    local_res20[0] = local_res20[0] + 2;
    lVar4 = ExAllocatePoolWithTag(1,(ulonglong)local_res20[0] << 3,0x72744c46);
    local_88 = lVar4;
    if (lVar4 != 0) {
      local_c4 = FltEnumerateVolumes(param_2,lVar4,local_res20[0],local_b8);
      if ((local_c4 < 0) || (local_res20[0] <= local_b8[0])) {
        if (local_c4 == -0x3fffffdd) {
          local_c4 = -0x3fffffff;
        }
      }
      else {
        local_res20[0] = local_b8[0];
      }
      if (-1 < local_c4) {
        for (uVar10 = 0; uVar10 < local_res20[0]; uVar10 = uVar10 + 1) {
          bVar6 = false;
          uVar9 = 0;
          uVar5 = uVar10;
          DbgPrintEx(0x8e,2,"\tChecking Volume: ");
          if ((uVar1 >> 0x1a & 1) == 0) {
            local_a8[0] = 0;
            memset(local_78,0,0x48);
            local_90 = (undefined8 *)((ulonglong)uVar10 * 8 + lVar4);
            iVar3 = FltGetVolumeProperties(*local_90,local_78,0x48,local_a8,uVar9,uVar5);
            if (((iVar3 + 0x80000000U & 0x80000000) != 0) || (iVar3 == -0x7ffffffb)) {
              if (local_78[0] == 0x14) {
                if ((uVar1 & 0x10000000) != 0) {
                  pcVar8 = "Network drive mask ";
                  goto LAB_14000c5e7;
                }
              }
              else if ((uVar1 & 0x8000000) != 0) {
                pcVar8 = "Local drive mask ";
LAB_14000c5e7:
                bVar6 = true;
                uVar9 = 1;
                DbgPrintEx(0x8e,2,pcVar8);
              }
            }
            if (bVar6) goto LAB_14000c757;
            local_a0 = 0;
            puStack_98 = (undefined2 *)0x0;
            iVar3 = FltGetDiskDeviceObject(*local_90,&local_b0);
            if (-1 < iVar3) {
              iVar3 = IoVolumeDeviceToDosName(local_b0,&local_a0);
              bVar6 = false;
              if (iVar3 < 0) {
                DbgPrintEx(0x8e,2,"Bad volume name ");
              }
              else {
                DbgPrintEx(0x8e,2,"Drive letter \'%c\' ",*puStack_98,uVar9);
                if ((1 < (ushort)local_a0) && (puStack_98[1] == 0x3a)) {
                  uVar2 = RtlUpcaseUnicodeChar(*puStack_98);
                  if (uVar2 - 0x41 < 0x1a) {
                    uVar5 = 1 << ((byte)(uVar2 - 0x41) & 0x1f);
                    DbgPrintEx(0x8e,2,"Bit mask 0x%x ",uVar5);
                    uVar9 = (uVar1 & uVar5) != 0;
                    bVar6 = (bool)uVar9;
                  }
                }
                ExFreePoolWithTag(puStack_98,0);
              }
              if (local_b0 != 0) {
                ObfDereferenceObject();
                local_b0 = 0;
              }
              goto LAB_14000c752;
            }
            DbgPrintEx(0x8e,2,"Bad device object ->FAIL\n");
          }
          else {
            bVar6 = true;
            uVar9 = 1;
            DbgPrintEx(0x8e,2,"All drives mask ");
LAB_14000c752:
            if (bVar6) {
LAB_14000c757:
              FltAttachVolume(DAT_140008110,*(undefined8 *)((ulonglong)uVar10 * 8 + lVar4),0,0,uVar9
                             );
              pcVar8 = "->PASS\n";
            }
            else {
              pcVar8 = "->FAIL\n";
            }
            DbgPrintEx(0x8e,2,pcVar8);
          }
        }
        for (; uVar7 < local_res20[0]; uVar7 = uVar7 + 1) {
          FltObjectDereference(*(undefined8 *)(lVar4 + (ulonglong)uVar7 * 8));
        }
        ExFreePoolWithTag(lVar4,0x72744c46);
        goto LAB_14000c7fc;
      }
    }
    if (lVar4 != 0) {
      ExFreePoolWithTag(lVar4,0x72744c46);
    }
  }
LAB_14000c7fc:
  ExFreePoolWithTag(param_3,0x72744c46);
  FltFreeGenericWorkItem(param_1);
  DbgPrintEx(0x8e,2,"FileTrace!AttachToRequestedDrives: End\n");
  return;
}



===== DetachFromDrives @ 14000c85c =====

void DetachFromDrives(uint param_1)

{
  undefined8 *puVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  code *pcVar5;
  undefined8 *puVar6;
  char *pcVar7;
  
  DbgPrintEx(0x8e,2,"FileTrace!DetachFromDrives: Start, kept drives 0x%x\n",param_1);
  if ((param_1 >> 0x1a & 1) == 0) {
    ExAcquireFastMutex(&DAT_140008258);
    puVar6 = DAT_140008248;
    while ((undefined8 **)puVar6 != &DAT_140008248) {
      if ((param_1 & *(uint *)(puVar6 + 3)) == 0) {
        FltDetachVolume(DAT_140008110,puVar6[2],0);
        DbgPrintEx(0x8e,2,"\tDetaching from 0x%x\n",*(undefined4 *)(puVar6 + 3));
        FltObjectDereference(puVar6[2]);
        puVar1 = (undefined8 *)*puVar6;
        plVar2 = (longlong *)puVar1[1];
        lVar3 = *plVar2;
        if ((*(longlong **)(lVar3 + 8) != plVar2) ||
           (plVar4 = (longlong *)plVar2[1], (longlong *)*plVar4 != plVar2)) {
          pcVar5 = (code *)swi(0x29);
          (*pcVar5)(3);
          pcVar5 = (code *)swi(3);
          (*pcVar5)();
          return;
        }
        *plVar4 = lVar3;
        *(longlong **)(lVar3 + 8) = plVar4;
        ExFreePoolWithTag(puVar6,0x72744c46);
        puVar6 = puVar1;
      }
      else {
        DbgPrintEx(0x8e,2,"\tKeeping attachment to 0x%x\n");
        puVar6 = (undefined8 *)*puVar6;
      }
    }
    ExReleaseFastMutex(&DAT_140008258);
    pcVar7 = "FileTrace!DetachFromDrives: END\n";
  }
  else {
    pcVar7 = "\tNOTHING!!!\n";
  }
  DbgPrintEx(0x8e,2,pcVar7);
  return;
}



===== DisableSession @ 14000c9e0 =====

void DisableSession(undefined8 param_1,undefined8 param_2,undefined8 *param_3,undefined8 param_4)

{
  longlong lVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  int iVar4;
  int local_24;
  uint local_20;
  undefined8 local_18;
  
  uVar3 = 0;
  local_24 = -1;
  local_18 = 0;
  local_20 = 0;
  DbgPrintEx(0x8e,2,"FileTrace!DisableSession: ",param_4,0);
  if (param_3 != (undefined8 *)0x0) {
    local_18 = *param_3;
    DbgPrintEx(0x8e,2,"lh %I64X, ",local_18,uVar3);
  }
  ExAcquireFastMutex(&SessionLock);
  iVar4 = 0;
  do {
    if (7 < iVar4) {
LAB_14000cac0:
      DbgPrintEx(0x8e,2,"target session %d, ",local_24);
      if (local_24 < 0) {
        ExReleaseFastMutex(&SessionLock);
        DbgPrintEx(0x8e,2,"SESSION NOT FOUND!\n");
      }
      else {
        for (iVar4 = 0; iVar4 < 8; iVar4 = iVar4 + 1) {
          if (iVar4 != local_24) {
            local_20 = local_20 | *(uint *)(LogSessions + (longlong)iVar4 * 0x28 + 0x20);
          }
        }
        DbgPrintEx(0x8e,2,"active session flags 0x%x\n",local_20);
        puVar2 = (undefined1 *)(LogSessions + (longlong)local_24 * 0x28);
        for (lVar1 = 0x28; lVar1 != 0; lVar1 = lVar1 + -1) {
          *puVar2 = 0;
          puVar2 = puVar2 + 1;
        }
        ExReleaseFastMutex(&SessionLock);
        DetachFromDrives(local_20);
      }
      if (param_3 != (undefined8 *)0x0) {
        ExFreePoolWithTag(param_3,0x72744c46);
      }
      FltFreeGenericWorkItem(param_1);
      return;
    }
    if (*(short *)(LogSessions + (longlong)iVar4 * 0x28) == (short)local_18) {
      local_24 = iVar4;
      goto LAB_14000cac0;
    }
    iVar4 = iVar4 + 1;
  } while( true );
}



===== FTInitTracing @ 14000cc10 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FTInitTracing(void)

{
  int iVar1;
  undefined8 in_R9;
  
  LogSessions = (void *)ExAllocatePoolWithTag(0x200,0x140,0x72744c46,in_R9,0);
  if (LogSessions == (void *)0x0) {
    iVar1 = -0x3fffff66;
  }
  else {
    memset(LogSessions,0,0x140);
    SessionSerialNumber = 0;
    _SessionLock = 1;
    _DAT_140008cc8 = 0;
    _DAT_140008cd0 = 0;
    KeInitializeEvent(&DAT_140008cd8,1,0);
    iVar1 = IoWMIRegistrationControl(&WmiRegistrationContext,0x80000001);
  }
  if ((iVar1 < 0) && (LogSessions != (void *)0x0)) {
    ExFreePoolWithTag(LogSessions,0x72744c46);
    LogSessions = (void *)0x0;
  }
  return iVar1;
}



===== FTTraceCallback @ 14000ccf0 =====

int FTTraceCallback(byte param_1,undefined8 param_2,uint param_3,undefined4 *param_4,
                   undefined8 param_5,undefined4 *param_6)

{
  short *psVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  int iVar4;
  int iVar5;
  longlong lVar6;
  undefined4 *puVar7;
  short *psVar8;
  undefined8 *puVar9;
  longlong lVar10;
  int iVar11;
  longlong lVar12;
  undefined4 local_res8 [2];
  
  *param_6 = 0;
  if (5 < param_1) {
    if (param_1 == 6) {
      return 0;
    }
    if (param_1 == 7) {
      return 0;
    }
    if (param_1 != 8) {
      return -0x3ffffff0;
    }
    if (param_3 < 0x98) {
      if (param_3 < 4) {
        return -0x3fffffdd;
      }
      *param_4 = 0x98;
      *param_6 = 4;
      return -0x3fffffdd;
    }
    memset(param_4,0,(ulonglong)param_3);
    param_4[2] = 0;
    puVar9 = &ControlGuids;
    *param_4 = 0x98;
    param_4[4] = 4;
    puVar7 = param_4 + 10;
    do {
      uVar2 = *puVar9;
      uVar3 = puVar9[1];
      puVar9 = puVar9 + 2;
      *puVar7 = 0x81000;
      *(undefined8 *)(puVar7 + -4) = uVar2;
      *(undefined8 *)(puVar7 + -2) = uVar3;
      puVar7 = puVar7 + 8;
    } while ((longlong)puVar9 < 0x140008090);
    *param_6 = 0x98;
    return 0;
  }
  if (param_1 == 5) {
    return 0;
  }
  if (param_1 == 0) {
    return -0x3ffffff0;
  }
  if (param_1 == 1) {
    return -0x3ffffff0;
  }
  if (param_1 == 2) {
    return -0x3ffffff0;
  }
  if (param_1 == 3) {
    return -0x3ffffff0;
  }
  if (param_1 != 4) {
    return -0x3ffffff0;
  }
  local_res8[0] = 0;
  DbgPrintEx(0x8e,2,"IRP_MN_ENABLE_EVENTS: ");
  if (param_3 < 0x30) {
    return -0x3ffffff3;
  }
  uVar2 = *(undefined8 *)(param_4 + 2);
  iVar5 = -1;
  DbgPrintEx(0x8e,2,"logger = %I64X, ",uVar2);
  ExAcquireFastMutex(&SessionLock);
  iVar11 = 0;
  do {
    lVar12 = (longlong)iVar11;
    if (((&ControlGuids)[lVar12 * 2] == *(longlong *)(param_4 + 6)) &&
       ((&DAT_140008058)[lVar12 * 2] == *(longlong *)(param_4 + 8))) {
      if (iVar11 != -1) {
        iVar4 = 0;
        psVar8 = LogSessions;
        goto LAB_14000ce2b;
      }
      break;
    }
    iVar11 = iVar11 + 1;
  } while (iVar11 < 4);
  DbgPrintEx(0x8e,2,"No matching guid\n");
  iVar5 = -0x3ffffd6b;
  goto LAB_14000ce0a;
  while( true ) {
    iVar4 = iVar4 + 1;
    psVar8 = psVar8 + 0x14;
    if (7 < iVar4) break;
LAB_14000ce2b:
    if ((*(int *)(psVar8 + 6) == 0) && (iVar5 < 0)) {
      iVar5 = iVar4;
    }
    if (*psVar8 == (short)uVar2) {
      iVar5 = iVar4;
      break;
    }
  }
  DbgPrintEx(0x8e,2,"TargetIndex = %d, ",iVar5);
  psVar8 = LogSessions;
  if (-1 < iVar5) {
    lVar10 = (longlong)iVar5;
    psVar1 = LogSessions + lVar10 * 0x14 + 6;
    psVar1[0] = 0;
    psVar1[1] = 0;
    *(int *)(psVar8 + lVar10 * 0x14 + 4) = *(int *)(psVar8 + lVar10 * 0x14 + 4) + 1;
    *(undefined8 *)(psVar8 + lVar10 * 0x14) = uVar2;
    DbgPrintEx(0x8e,2,"Refcount now %d\n",*(undefined4 *)(psVar8 + lVar10 * 0x14 + 4));
    lVar12 = lVar12 + lVar10 * 10;
    iVar5 = WmiQueryTraceInformation(2,LogSessions + lVar12 * 2 + 10,4,local_res8,param_4);
    if ((iVar5 < 0) || (iVar11 != 3)) {
LAB_14000cfa6:
      iVar11 = SessionSerialNumber + 1;
      if (SessionSerialNumber + 1 == 0) {
        iVar11 = SessionSerialNumber + 2;
      }
      SessionSerialNumber = iVar11;
      *(int *)(LogSessions + lVar10 * 0x14 + 6) = SessionSerialNumber;
      goto LAB_14000ce0a;
    }
    lVar6 = FltAllocateGenericWorkItem();
    if (lVar6 != 0) {
      puVar7 = (undefined4 *)ExAllocatePoolWithTag(1,4,0x72744c46);
      if (puVar7 != (undefined4 *)0x0) {
        *puVar7 = *(undefined4 *)(LogSessions + lVar12 * 2 + 10);
        iVar5 = FltQueueGenericWorkItem(lVar6,DAT_140008110,AttachToRequestedDrives,1,puVar7);
        if (iVar5 < 0) {
          ExFreePoolWithTag(puVar7,0x72744c46);
          FltFreeGenericWorkItem(lVar6);
        }
        goto LAB_14000cfa6;
      }
      FltFreeGenericWorkItem(lVar6);
    }
  }
  iVar5 = -0x3fffff66;
LAB_14000ce0a:
  ExReleaseFastMutex(&SessionLock);
  return iVar5;
}



===== CreateParameterBlob @ 14000d074 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint CreateParameterBlob(longlong param_1,uint *param_2,longlong *param_3)

{
  uint uVar1;
  byte bVar2;
  ushort *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  bool bVar8;
  char cVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  undefined8 *puVar13;
  ulonglong uVar14;
  void *_Dst;
  undefined4 *puVar15;
  undefined1 *puVar16;
  uint uVar17;
  uint uVar18;
  longlong lVar19;
  longlong lVar20;
  bool bVar21;
  undefined1 auStack_a8 [32];
  undefined4 local_88;
  uint local_74;
  uint *local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  uint local_58;
  undefined2 local_54;
  undefined4 local_52;
  undefined2 local_4e;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_a8;
  bVar21 = false;
  lVar20 = *(longlong *)(param_1 + 0x10);
  uVar10 = 0;
  bVar2 = *(byte *)(lVar20 + 4);
  local_70 = param_2;
  if (0x15 < bVar2) {
    if (bVar2 < 0xf2) {
      if (bVar2 != 0xf1) {
        if (bVar2 == 0x19) {
          uVar14 = Feature_1307199801__private_IsEnabledDeviceUsageNoInline();
          lVar20 = 0x30;
          uVar10 = *(int *)(*(longlong *)(param_1 + 0x10) + 0x30) + 0x30;
          if (((int)uVar14 != 0) && (uVar10 < 0x30)) {
            return 0xc0000095;
          }
          puVar13 = (undefined8 *)ExAllocatePoolWithTag(0x200,uVar10,0x72744c46);
          *param_3 = (longlong)puVar13;
          if (puVar13 == (undefined8 *)0x0) {
            return 0xc000009a;
          }
          lVar19 = *(longlong *)(param_1 + 0x10);
          uVar7 = *(undefined8 *)(lVar19 + 0x20);
          *puVar13 = *(undefined8 *)(lVar19 + 0x18);
          puVar13[1] = uVar7;
          uVar7 = *(undefined8 *)(lVar19 + 0x30);
          puVar13[2] = *(undefined8 *)(lVar19 + 0x28);
          puVar13[3] = uVar7;
          uVar7 = *(undefined8 *)(lVar19 + 0x40);
          puVar13[4] = *(undefined8 *)(lVar19 + 0x38);
          puVar13[5] = uVar7;
          lVar19 = *(longlong *)(param_1 + 0x10);
          uVar18 = *(uint *)(lVar19 + 0x30);
          goto LAB_14000d8ba;
        }
        if (bVar2 == 0x1a) {
          uVar14 = Feature_1307199801__private_IsEnabledDeviceUsageNoInline();
          uVar10 = *(int *)(*(longlong *)(param_1 + 0x10) + 0x18) + 0x18;
          if (((int)uVar14 != 0) && (uVar10 < 0x18)) {
            return 0xc0000095;
          }
LAB_14000d127:
          lVar20 = 0x18;
          puVar13 = (undefined8 *)ExAllocatePoolWithTag(0x200,uVar10,0x72744c46);
          *param_3 = (longlong)puVar13;
          if (puVar13 == (undefined8 *)0x0) {
            return 0xc000009a;
          }
          lVar19 = *(longlong *)(param_1 + 0x10);
          uVar7 = *(undefined8 *)(lVar19 + 0x20);
          *puVar13 = *(undefined8 *)(lVar19 + 0x18);
          puVar13[1] = uVar7;
          puVar13[2] = *(undefined8 *)(lVar19 + 0x28);
          lVar19 = *(longlong *)(param_1 + 0x10);
          uVar18 = *(uint *)(lVar19 + 0x18);
LAB_14000d1d9:
          memmove((void *)(*param_3 + lVar20),*(void **)(lVar19 + 0x20),(ulonglong)uVar18);
          *(longlong *)(*param_3 + 8) = lVar20;
          goto LAB_14000dcd5;
        }
        if (bVar2 == 0x1b) {
          uVar18 = (uint)*(byte *)(lVar20 + 5);
          if (uVar18 < 0xe) {
            if (uVar18 != 0xd) {
              uVar18 = (uint)*(byte *)(lVar20 + 5);
              if (uVar18 == 0) goto LAB_14000da27;
              if (uVar18 == 7) goto LAB_14000da62;
              if (uVar18 == 8) goto LAB_14000d53a;
              iVar12 = uVar18 - 9;
              if (iVar12 != 0) goto LAB_14000dac8;
            }
LAB_14000d9ed:
            uVar10 = 8;
            puVar13 = (undefined8 *)ExAllocatePoolWithTag(0x200,8,0x72744c46);
            *param_3 = (longlong)puVar13;
            if (puVar13 == (undefined8 *)0x0) {
              return 0xc000009a;
            }
            *puVar13 = *(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x18);
            goto LAB_14000dcd5;
          }
          if ((uVar18 != 0xf) && (uVar18 != 0x10)) {
            if (uVar18 == 0x12) {
              uVar10 = 1;
              puVar16 = (undefined1 *)ExAllocatePoolWithTag(0x200,1,0x72744c46);
              *param_3 = (longlong)puVar16;
              if (puVar16 == (undefined1 *)0x0) {
                return 0xc000009a;
              }
              *puVar16 = *(undefined1 *)(*(longlong *)(param_1 + 0x10) + 0x18);
              goto LAB_14000dcd5;
            }
            iVar12 = uVar18 - 0x13;
            if (iVar12 == 0) goto LAB_14000da62;
LAB_14000dac8:
            if (iVar12 != 3) goto LAB_14000dcd5;
LAB_14000da27:
            uVar10 = 0x10;
            puVar13 = (undefined8 *)ExAllocatePoolWithTag(0x200,0x10,0x72744c46);
            *param_3 = (longlong)puVar13;
            if (puVar13 == (undefined8 *)0x0) {
              return 0xc000009a;
            }
            uVar7 = *(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x20);
            *puVar13 = *(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x18);
            puVar13[1] = uVar7;
            goto LAB_14000dcd5;
          }
        }
        else {
          if (bVar2 == 0xed) {
LAB_14000da62:
            uVar10 = 4;
            puVar15 = (undefined4 *)ExAllocatePoolWithTag(0x200,4,0x72744c46);
            *param_3 = (longlong)puVar15;
            if (puVar15 == (undefined4 *)0x0) {
              return 0xc000009a;
            }
            *puVar15 = *(undefined4 *)(*(longlong *)(param_1 + 0x10) + 0x18);
            goto LAB_14000dcd5;
          }
          if (bVar2 == 0xee) goto LAB_14000da27;
          if (bVar2 != 0xef) {
            if (bVar2 != 0xf0) goto LAB_14000d990;
            goto LAB_14000d9ed;
          }
        }
      }
    }
    else {
      if (bVar2 == 0xf2) {
        uVar10 = 0x48;
        puVar13 = (undefined8 *)ExAllocatePoolWithTag(0x200,0x48,0x72744c46);
        *param_3 = (longlong)puVar13;
        if (puVar13 == (undefined8 *)0x0) {
          return 0xc000009a;
        }
        uVar7 = *(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x20);
        *puVar13 = *(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x18);
        puVar13[1] = uVar7;
        puVar13 = *(undefined8 **)(*(longlong *)(param_1 + 0x10) + 0x20);
        lVar20 = *param_3;
        uVar7 = puVar13[1];
        *(undefined8 *)(lVar20 + 0x10) = *puVar13;
        *(undefined8 *)(lVar20 + 0x18) = uVar7;
        uVar7 = puVar13[3];
        *(undefined8 *)(lVar20 + 0x20) = puVar13[2];
        *(undefined8 *)(lVar20 + 0x28) = uVar7;
        uVar7 = puVar13[5];
        *(undefined8 *)(lVar20 + 0x30) = puVar13[4];
        *(undefined8 *)(lVar20 + 0x38) = uVar7;
        *(undefined8 *)(lVar20 + 0x40) = puVar13[6];
LAB_14000dcca:
        *(undefined8 *)(*param_3 + 8) = 0x10;
        goto LAB_14000dcd5;
      }
      if (bVar2 != 0xf3) {
        if (bVar2 == 0xfc) goto LAB_14000d9ed;
        if (bVar2 == 0xfd) {
          uVar10 = 0x18;
          puVar13 = (undefined8 *)ExAllocatePoolWithTag(0x200,0x18,0x72744c46);
          *param_3 = (longlong)puVar13;
          if (puVar13 == (undefined8 *)0x0) {
            return 0xc000009a;
          }
          uVar7 = *(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x20);
          *puVar13 = *(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x18);
          puVar13[1] = uVar7;
          *(undefined8 *)(*param_3 + 0x10) = **(undefined8 **)(*(longlong *)(param_1 + 0x10) + 0x18)
          ;
          *(undefined8 *)*param_3 = 0x10;
          goto LAB_14000dcd5;
        }
        if ((bVar2 == 0xfe) || (bVar2 != 0xff)) goto LAB_14000d990;
        goto LAB_14000d707;
      }
    }
LAB_14000d53a:
    uVar10 = 0x20;
    puVar13 = (undefined8 *)ExAllocatePoolWithTag(0x200,0x20,0x72744c46);
    *param_3 = (longlong)puVar13;
    if (puVar13 == (undefined8 *)0x0) {
      return 0xc000009a;
    }
    lVar20 = *(longlong *)(param_1 + 0x10);
    uVar7 = *(undefined8 *)(lVar20 + 0x20);
    *puVar13 = *(undefined8 *)(lVar20 + 0x18);
    puVar13[1] = uVar7;
    uVar7 = *(undefined8 *)(lVar20 + 0x30);
    puVar13[2] = *(undefined8 *)(lVar20 + 0x28);
    puVar13[3] = uVar7;
    goto LAB_14000dcd5;
  }
  if (bVar2 == 0x15) {
    local_74 = RtlLengthSecurityDescriptor(*(undefined8 *)(lVar20 + 0x20));
    uVar14 = Feature_1307199801__private_IsEnabledDeviceUsageNoInline();
    uVar10 = local_74 + 0x10;
    if (((int)uVar14 != 0) && (uVar10 < 0x10)) {
      return 0xc0000095;
    }
    puVar15 = (undefined4 *)ExAllocatePoolWithTag(0x200,uVar10,0x72744c46);
    *param_3 = (longlong)puVar15;
    if (puVar15 == (undefined4 *)0x0) {
      return 0xc000009a;
    }
    lVar20 = *(longlong *)(param_1 + 0x10);
    uVar4 = *(undefined4 *)(lVar20 + 0x1c);
    uVar5 = *(undefined4 *)(lVar20 + 0x20);
    uVar6 = *(undefined4 *)(lVar20 + 0x24);
    *puVar15 = *(undefined4 *)(lVar20 + 0x18);
    puVar15[1] = uVar4;
    puVar15[2] = uVar5;
    puVar15[3] = uVar6;
    iVar12 = RtlAbsoluteToSelfRelativeSD
                       (*(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x20),*param_3 + 0x10,
                        &local_74);
    if (-1 < iVar12) goto LAB_14000dcd5;
    if (iVar12 == -0x3fffff19) {
      memmove((void *)(*param_3 + 0x10),*(void **)(*(longlong *)(param_1 + 0x10) + 0x20),
              (ulonglong)local_74);
      goto LAB_14000dcca;
    }
    ExFreePoolWithTag(*param_3,0x72744c46);
    goto LAB_14000d990;
  }
  if (bVar2 < 0xb) {
    if (bVar2 != 10) {
      if (bVar2 == 0) {
        uVar10 = 0x48;
        puVar13 = (undefined8 *)ExAllocatePoolWithTag(0x200,0x48,0x72744c46);
        *param_3 = (longlong)puVar13;
        if (puVar13 == (undefined8 *)0x0) {
          return 0xc000009a;
        }
        lVar20 = *(longlong *)(param_1 + 0x10);
        uVar7 = *(undefined8 *)(lVar20 + 0x20);
        *puVar13 = *(undefined8 *)(lVar20 + 0x18);
        puVar13[1] = uVar7;
        uVar7 = *(undefined8 *)(lVar20 + 0x30);
        puVar13[2] = *(undefined8 *)(lVar20 + 0x28);
        puVar13[3] = uVar7;
        uVar7 = *(undefined8 *)(lVar20 + 0x40);
        puVar13[4] = *(undefined8 *)(lVar20 + 0x38);
        puVar13[5] = uVar7;
        puVar13 = *(undefined8 **)(*(longlong *)(param_1 + 0x10) + 0x18);
        lVar20 = *param_3;
        uVar7 = puVar13[1];
        *(undefined8 *)(lVar20 + 0x30) = *puVar13;
        *(undefined8 *)(lVar20 + 0x38) = uVar7;
        *(undefined8 *)(lVar20 + 0x40) = puVar13[2];
        *(undefined8 *)*param_3 = 0x30;
        goto LAB_14000dcd5;
      }
      if ((bVar2 == 3) || (bVar2 == 4)) {
        uVar10 = 0x28;
        puVar13 = (undefined8 *)ExAllocatePoolWithTag(0x200,0x28,0x72744c46);
        *param_3 = (longlong)puVar13;
        if (puVar13 == (undefined8 *)0x0) {
          return 0xc000009a;
        }
        lVar20 = *(longlong *)(param_1 + 0x10);
        uVar7 = *(undefined8 *)(lVar20 + 0x20);
        *puVar13 = *(undefined8 *)(lVar20 + 0x18);
        puVar13[1] = uVar7;
        uVar7 = *(undefined8 *)(lVar20 + 0x30);
        puVar13[2] = *(undefined8 *)(lVar20 + 0x28);
        puVar13[3] = uVar7;
        puVar13[4] = *(undefined8 *)(lVar20 + 0x38);
        goto LAB_14000dcd5;
      }
      if (bVar2 != 5) {
        if (bVar2 == 6) {
          local_58 = 4;
          local_54 = 0;
          uVar18 = 0;
          local_52 = 0;
          bVar8 = false;
          local_4e = 0;
          uVar14 = Feature_1307199801__private_IsEnabledDeviceUsageNoInline();
          lVar20 = *(longlong *)(param_1 + 0x10);
          iVar12 = *(int *)(lVar20 + 0x18);
          uVar10 = iVar12 + 0x28;
          if (((int)uVar14 != 0) && (uVar10 < 0x28)) {
            return 0xc0000095;
          }
          if (((*(int *)(lVar20 + 0x20) - 10U < 2) &&
              (*(longlong *)(*(longlong *)(lVar20 + 0x38) + 8) != 0)) &&
             (((GlobalLateBoundFunctions != (code *)0x0 &&
               (cVar9 = (*GlobalLateBoundFunctions)(), cVar9 == '\0')) ||
              ((**(uint **)(param_1 + 0x10) & 2) == 0)))) {
            local_88 = 9;
            local_68 = 0;
            uStack_60 = 0;
            uVar11 = ZwQueryInformationFile
                               (*(undefined8 *)
                                 (*(longlong *)(*(longlong *)(param_1 + 0x10) + 0x38) + 8),&local_68
                                ,&local_58,0xc);
            if (((uVar11 + 0x80000000 & 0x80000000) == 0) && (uVar11 != 0x80000005)) {
              bVar8 = false;
            }
            else {
              uVar14 = Feature_1307199801__private_IsEnabledDeviceUsageNoInline();
              uVar18 = local_58;
              if ((int)uVar14 == 0) {
                uVar10 = iVar12 + 0x2c + local_58;
              }
              else {
                bVar21 = uVar11 == 0x80000005;
                uVar1 = iVar12 + 0x2c;
                if (uVar1 < uVar10) {
                  return 0xc0000095;
                }
                uVar17 = uVar1 + local_58;
                uVar10 = 0xffffffff;
                if (uVar17 >= uVar1) {
                  uVar10 = uVar17;
                }
                uVar11 = -(uint)(uVar17 < uVar1) & 0xc0000095;
                if (uVar17 < uVar1) {
                  return uVar11;
                }
              }
              uVar14 = Feature_1307199801__private_IsEnabledDeviceUsageNoInline();
              if (((int)uVar14 == 0) && (uVar11 == 0x80000005)) {
                bVar21 = true;
              }
              bVar8 = true;
            }
          }
          _Dst = (void *)ExAllocatePoolWithTag(0x200,uVar10,0x72744c46);
          *param_3 = (longlong)_Dst;
          if (_Dst == (void *)0x0) {
            return 0xc000009a;
          }
          memset(_Dst,0,(ulonglong)uVar10);
          lVar20 = *(longlong *)(param_1 + 0x10);
          puVar13 = (undefined8 *)*param_3;
          uVar7 = *(undefined8 *)(lVar20 + 0x20);
          *puVar13 = *(undefined8 *)(lVar20 + 0x18);
          puVar13[1] = uVar7;
          uVar7 = *(undefined8 *)(lVar20 + 0x30);
          puVar13[2] = *(undefined8 *)(lVar20 + 0x28);
          puVar13[3] = uVar7;
          puVar13[4] = *(undefined8 *)(lVar20 + 0x38);
          memmove((void *)(*param_3 + 0x28),*(void **)(*(longlong *)(param_1 + 0x10) + 0x38),
                  (ulonglong)*(uint *)(*(longlong *)(param_1 + 0x10) + 0x18));
          *(undefined8 *)(*param_3 + 0x20) = 0x28;
          if (bVar8) {
            lVar20 = *(longlong *)(param_1 + 0x10);
            if (bVar21) {
              local_88 = 9;
              local_68 = 0;
              uStack_60 = 0;
              iVar12 = ZwQueryInformationFile
                                 (*(undefined8 *)(*(longlong *)(lVar20 + 0x38) + 8),&local_68,
                                  *param_3 + 0x28 + (ulonglong)*(uint *)(lVar20 + 0x18),uVar18 + 4);
              if (iVar12 < 0) {
                uVar10 = uVar10 - uVar18;
              }
            }
            else {
              *(uint *)((ulonglong)*(uint *)(lVar20 + 0x18) + 0x28 + *param_3) = uVar18;
              memmove((void *)((ulonglong)*(uint *)(*(longlong *)(param_1 + 0x10) + 0x18) +
                              *param_3 + 0x2c),&local_54,(ulonglong)uVar18);
            }
          }
          goto LAB_14000dcd5;
        }
        if (bVar2 == 7) {
          uVar14 = Feature_1307199801__private_IsEnabledDeviceUsageNoInline();
          lVar20 = 0x30;
          uVar10 = *(int *)(*(longlong *)(param_1 + 0x10) + 0x28) + 0x30;
          if (((int)uVar14 != 0) && (uVar10 < 0x30)) {
            return 0xc0000095;
          }
          puVar13 = (undefined8 *)ExAllocatePoolWithTag(0x200,uVar10,0x72744c46);
          *param_3 = (longlong)puVar13;
          if (puVar13 == (undefined8 *)0x0) {
            return 0xc000009a;
          }
          lVar19 = *(longlong *)(param_1 + 0x10);
          uVar7 = *(undefined8 *)(lVar19 + 0x20);
          *puVar13 = *(undefined8 *)(lVar19 + 0x18);
          puVar13[1] = uVar7;
          uVar7 = *(undefined8 *)(lVar19 + 0x30);
          puVar13[2] = *(undefined8 *)(lVar19 + 0x28);
          puVar13[3] = uVar7;
          uVar7 = *(undefined8 *)(lVar19 + 0x40);
          puVar13[4] = *(undefined8 *)(lVar19 + 0x38);
          puVar13[5] = uVar7;
          lVar19 = *(longlong *)(param_1 + 0x10);
          uVar18 = *(uint *)(lVar19 + 0x28);
          goto LAB_14000d1d9;
        }
        if (bVar2 == 8) {
          uVar10 = *(int *)(lVar20 + 0x18) + 0x18;
          if (uVar10 < 0x18) {
            return 0xc0000095;
          }
          goto LAB_14000d127;
        }
        goto LAB_14000d990;
      }
    }
    goto LAB_14000d707;
  }
  if (bVar2 == 0xb) {
    uVar14 = Feature_1307199801__private_IsEnabledDeviceUsageNoInline();
    lVar20 = 0x18;
    uVar10 = *(int *)(*(longlong *)(param_1 + 0x10) + 0x18) + 0x18;
    if (((int)uVar14 != 0) && (uVar10 < 0x18)) {
      return 0xc0000095;
    }
    puVar13 = (undefined8 *)ExAllocatePoolWithTag(0x200,uVar10,0x72744c46);
    *param_3 = (longlong)puVar13;
    if (puVar13 == (undefined8 *)0x0) {
      return 0xc000009a;
    }
    lVar19 = *(longlong *)(param_1 + 0x10);
    uVar7 = *(undefined8 *)(lVar19 + 0x20);
    *puVar13 = *(undefined8 *)(lVar19 + 0x18);
    puVar13[1] = uVar7;
    puVar13[2] = *(undefined8 *)(lVar19 + 0x28);
    lVar19 = *(longlong *)(param_1 + 0x10);
    uVar18 = *(uint *)(lVar19 + 0x18);
LAB_14000d8ba:
    memmove((void *)(*param_3 + lVar20),*(void **)(lVar19 + 0x28),(ulonglong)uVar18);
    *(longlong *)(*param_3 + 0x10) = lVar20;
    goto LAB_14000dcd5;
  }
  if (bVar2 == 0xc) {
    if (*(char *)(lVar20 + 5) == '\x01') {
      uVar10 = 0x30;
      if (*(ushort **)(lVar20 + 0x20) != (ushort *)0x0) {
        uVar10 = **(ushort **)(lVar20 + 0x20) + 0x40;
      }
      puVar13 = (undefined8 *)ExAllocatePoolWithTag(0x200,uVar10,0x72744c46);
      *param_3 = (longlong)puVar13;
      if (puVar13 == (undefined8 *)0x0) {
        return 0xc000009a;
      }
      lVar20 = *(longlong *)(param_1 + 0x10);
      uVar7 = *(undefined8 *)(lVar20 + 0x20);
      *puVar13 = *(undefined8 *)(lVar20 + 0x18);
      puVar13[1] = uVar7;
      uVar7 = *(undefined8 *)(lVar20 + 0x30);
      puVar13[2] = *(undefined8 *)(lVar20 + 0x28);
      puVar13[3] = uVar7;
      uVar7 = *(undefined8 *)(lVar20 + 0x40);
      puVar13[4] = *(undefined8 *)(lVar20 + 0x38);
      puVar13[5] = uVar7;
      puVar13 = *(undefined8 **)(*(longlong *)(param_1 + 0x10) + 0x20);
      if (puVar13 != (undefined8 *)0x0) {
        uVar7 = puVar13[1];
        lVar20 = *param_3;
        *(undefined8 *)(lVar20 + 0x30) = *puVar13;
        *(undefined8 *)(lVar20 + 0x38) = uVar7;
        puVar3 = *(ushort **)(*(longlong *)(param_1 + 0x10) + 0x20);
        memmove((void *)(*param_3 + 0x40),*(void **)(puVar3 + 4),(ulonglong)*puVar3);
        *(undefined8 *)(*param_3 + 8) = 0x30;
        *(undefined8 *)(*param_3 + 0x38) = 0x10;
      }
      goto LAB_14000dcd5;
    }
    if (*(char *)(lVar20 + 5) == '\x02') {
      uVar10 = 0x30;
      puVar13 = (undefined8 *)ExAllocatePoolWithTag(0x200,0x30,0x72744c46);
      *param_3 = (longlong)puVar13;
      if (puVar13 == (undefined8 *)0x0) {
        return 0xc000009a;
      }
      lVar20 = *(longlong *)(param_1 + 0x10);
      uVar7 = *(undefined8 *)(lVar20 + 0x20);
      *puVar13 = *(undefined8 *)(lVar20 + 0x18);
      puVar13[1] = uVar7;
      uVar7 = *(undefined8 *)(lVar20 + 0x30);
      puVar13[2] = *(undefined8 *)(lVar20 + 0x28);
      puVar13[3] = uVar7;
      uVar7 = *(undefined8 *)(lVar20 + 0x40);
      puVar13[4] = *(undefined8 *)(lVar20 + 0x38);
      puVar13[5] = uVar7;
      goto LAB_14000dcd5;
    }
LAB_14000d990:
    uVar10 = 0;
    *param_3 = 0;
  }
  else {
    if (bVar2 == 0xd) {
      cVar9 = *(char *)(lVar20 + 5);
      if (cVar9 != '\0') {
        if (cVar9 == '\x02') goto LAB_14000da27;
        if (cVar9 != '\x04') goto LAB_14000d990;
      }
    }
    else if ((bVar2 != 0xe) && (bVar2 != 0xf)) {
      if (bVar2 == 0x11) {
        uVar10 = 0x30;
        puVar13 = (undefined8 *)ExAllocatePoolWithTag(0x200,0x30,0x72744c46);
        *param_3 = (longlong)puVar13;
        if (puVar13 == (undefined8 *)0x0) {
          return 0xc000009a;
        }
        lVar20 = *(longlong *)(param_1 + 0x10);
        cVar9 = *(char *)(lVar20 + 5);
        if (cVar9 == '\x01') {
          uVar7 = *(undefined8 *)(lVar20 + 0x20);
          *puVar13 = *(undefined8 *)(lVar20 + 0x18);
          puVar13[1] = uVar7;
          uVar7 = *(undefined8 *)(lVar20 + 0x30);
          puVar13[2] = *(undefined8 *)(lVar20 + 0x28);
          puVar13[3] = uVar7;
          puVar13[4] = *(undefined8 *)(lVar20 + 0x38);
          *(undefined8 *)(*param_3 + 0x28) = **(undefined8 **)(*(longlong *)(param_1 + 0x10) + 0x18)
          ;
          *(undefined8 *)*param_3 = 0x28;
        }
        else if (cVar9 == '\x02') {
          *puVar13 = 0x28;
          *(undefined4 *)(*param_3 + 8) = *(undefined4 *)(*(longlong *)(param_1 + 0x10) + 0x20);
          *(undefined8 *)(*param_3 + 0x10) = *(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x28);
          lVar20 = 0;
          do {
            *(undefined1 *)(lVar20 + 0x20 + *param_3) = 0;
            lVar20 = lVar20 + 1;
          } while (lVar20 < 2);
          *(undefined8 *)(*param_3 + 0x18) = *(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x30);
          *(undefined8 *)(*param_3 + 0x28) = **(undefined8 **)(*(longlong *)(param_1 + 0x10) + 0x18)
          ;
        }
        else {
          if (cVar9 == '\x03') {
            *puVar13 = 0x28;
            lVar20 = 0;
            *(undefined4 *)(*param_3 + 8) = 0;
            *(undefined8 *)(*param_3 + 0x10) = 0;
            do {
              *(undefined1 *)(lVar20 + 0x20 + *param_3) = 0;
              lVar20 = lVar20 + 1;
            } while (lVar20 < 2);
          }
          else {
            if (cVar9 != '\x04') goto LAB_14000dcd5;
            *puVar13 = 0x28;
            *(undefined4 *)(*param_3 + 8) = *(undefined4 *)(*(longlong *)(param_1 + 0x10) + 0x20);
            lVar20 = 0;
            *(undefined8 *)(*param_3 + 0x10) = 0;
            do {
              *(undefined1 *)(lVar20 + 0x20 + *param_3) = 0;
              lVar20 = lVar20 + 1;
            } while (lVar20 < 2);
          }
          *(undefined8 *)(*param_3 + 0x18) = *(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x30);
          *(undefined8 *)(*param_3 + 0x28) = 0;
        }
        goto LAB_14000dcd5;
      }
      if (bVar2 == 0x14) goto LAB_14000d53a;
      goto LAB_14000d990;
    }
LAB_14000d707:
    uVar10 = 0x18;
    puVar13 = (undefined8 *)ExAllocatePoolWithTag(0x200,0x18,0x72744c46);
    *param_3 = (longlong)puVar13;
    if (puVar13 == (undefined8 *)0x0) {
      return 0xc000009a;
    }
    lVar20 = *(longlong *)(param_1 + 0x10);
    uVar7 = *(undefined8 *)(lVar20 + 0x20);
    *puVar13 = *(undefined8 *)(lVar20 + 0x18);
    puVar13[1] = uVar7;
    puVar13[2] = *(undefined8 *)(lVar20 + 0x28);
  }
LAB_14000dcd5:
  *local_70 = uVar10;
  return 0;
}



===== GetLastAccessTime @ 14000dd08 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int GetLastAccessTime(longlong param_1,longlong param_2,undefined8 *param_3)

{
  longlong lVar1;
  int iVar2;
  undefined1 auStack_68 [32];
  undefined4 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_68;
  local_18 = 0;
  iVar2 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  if (param_3 == (undefined8 *)0x0) {
    iVar2 = -0x3ffffff3;
  }
  else {
    lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 8);
    if ((lVar1 != 0) && (*(longlong *)(lVar1 + 0x18) != 0)) {
      local_40 = 0;
      local_48 = 4;
      iVar2 = FltQueryInformationFile
                        (*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20),&local_38,
                         0x28);
      if (-1 < iVar2) {
        *param_3 = uStack_30;
      }
    }
  }
  return iVar2;
}



===== GetPreviousValue @ 14000ddb0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GetPreviousValue(longlong param_1,longlong param_2,int *param_3,longlong *param_4)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  undefined4 *puVar4;
  longlong lVar5;
  int iVar6;
  undefined1 auStack_c8 [32];
  int local_a8;
  ulonglong *local_a0;
  ulonglong local_98 [4];
  undefined1 uStack_74;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_c8;
  cVar2 = *(char *)(*(longlong *)(param_1 + 0x10) + 4);
  if (cVar2 == '\x06') {
    local_98[2] = 0;
    local_98[3] = 0;
    local_78 = 0;
    bVar1 = KeGetCurrentIrql();
    if (1 < bVar1) {
      return;
    }
    local_a8 = *(int *)(*(longlong *)(param_1 + 0x10) + 0x20);
    if (local_a8 == 0x13) {
      local_a0 = (ulonglong *)0x0;
      local_a8 = 5;
      iVar3 = FltQueryInformationFile
                        (*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20),
                         local_98 + 2,0x18);
      if (iVar3 < 0) {
        return;
      }
      lVar5 = ExAllocatePoolWithTag(0x200,0xc,0x72744c46);
      *param_4 = lVar5;
      if (lVar5 == 0) {
        return;
      }
      *param_3 = 0xc;
      *(undefined4 *)*param_4 = *(undefined4 *)(*(longlong *)(param_1 + 0x10) + 0x20);
    }
    else {
      if (local_a8 == 0xd) {
        local_a0 = (ulonglong *)0x0;
        local_a8 = 5;
        iVar3 = FltQueryInformationFile
                          (*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20),
                           local_98 + 2,0x18);
        if (iVar3 < 0) {
          return;
        }
        lVar5 = ExAllocatePoolWithTag(0x200,5,0x72744c46);
        *param_4 = lVar5;
        if (lVar5 == 0) {
          return;
        }
        *param_3 = 5;
        *(undefined4 *)*param_4 = *(undefined4 *)(*(longlong *)(param_1 + 0x10) + 0x20);
        *(undefined1 *)(*param_4 + 4) = uStack_74;
        return;
      }
      if (local_a8 == 0x14) {
        local_a0 = (ulonglong *)0x0;
        local_a8 = 5;
        iVar3 = FltQueryInformationFile
                          (*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20),
                           local_98 + 2,0x18);
        if (iVar3 < 0) {
          return;
        }
        lVar5 = ExAllocatePoolWithTag(0x200,0xc,0x72744c46);
        *param_4 = lVar5;
        if (lVar5 == 0) {
          return;
        }
        *param_3 = 0xc;
        *(undefined4 *)*param_4 = *(undefined4 *)(*(longlong *)(param_1 + 0x10) + 0x20);
        local_98[2] = local_98[3];
      }
      else {
        if (local_a8 != 0xe) {
          if (local_a8 != 4) {
            return;
          }
          local_a0 = (ulonglong *)0x0;
          local_70 = 0;
          uStack_68 = 0;
          local_50 = 0;
          local_60 = 0;
          uStack_58 = 0;
          iVar3 = FltQueryInformationFile
                            (*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20),
                             &local_70,0x28);
          if (iVar3 < 0) {
            return;
          }
          lVar5 = ExAllocatePoolWithTag(0x200,0x2c,0x72744c46);
          *param_4 = lVar5;
          if (lVar5 == 0) {
            return;
          }
          *param_3 = 0x2c;
          *(undefined4 *)*param_4 = *(undefined4 *)(*(longlong *)(param_1 + 0x10) + 0x20);
          lVar5 = *param_4;
          *(undefined8 *)(lVar5 + 4) = local_70;
          *(undefined8 *)(lVar5 + 0xc) = uStack_68;
          *(undefined8 *)(lVar5 + 0x14) = local_60;
          *(undefined8 *)(lVar5 + 0x1c) = uStack_58;
          *(undefined8 *)(lVar5 + 0x24) = local_50;
          return;
        }
        local_a0 = (ulonglong *)0x0;
        local_98[0] = 0;
        iVar3 = FltQueryInformationFile
                          (*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20),local_98,
                           8);
        if (iVar3 < 0) {
          return;
        }
        lVar5 = ExAllocatePoolWithTag(0x200,0xc,0x72744c46);
        *param_4 = lVar5;
        if (lVar5 == 0) {
          return;
        }
        *param_3 = 0xc;
        *(undefined4 *)*param_4 = *(undefined4 *)(*(longlong *)(param_1 + 0x10) + 0x20);
        local_98[2] = local_98[0];
      }
    }
    *(ulonglong *)(*param_4 + 4) = local_98[2];
    return;
  }
  if (cVar2 == '\v') {
    local_98[0] = 0;
    local_98[1] = 0;
    if (((GlobalLateBoundFunctions == (code *)0x0) ||
        (cVar2 = (*GlobalLateBoundFunctions)(), cVar2 != '\0')) &&
       ((**(uint **)(param_1 + 0x10) & 2) != 0)) {
      return;
    }
    iVar3 = *(int *)(*(longlong *)(param_1 + 0x10) + 0x20);
    if (iVar3 == 6) {
      lVar5 = ExAllocatePoolWithTag(0x200,0x34,0x72744c46);
      *param_4 = lVar5;
      if (lVar5 == 0) {
        return;
      }
      *param_3 = 0x34;
      local_a8 = 6;
      *(undefined4 *)*param_4 = *(undefined4 *)(*(longlong *)(param_1 + 0x10) + 0x20);
    }
    else {
      if (iVar3 == 2) {
        lVar5 = ExAllocatePoolWithTag(0x200,0x81c,0x72744c46);
        *param_4 = lVar5;
        if (lVar5 == 0) {
          return;
        }
        *param_3 = 0x81c;
        local_a8 = 1;
      }
      else {
        if (iVar3 != 8) {
          return;
        }
        lVar5 = ExAllocatePoolWithTag(0x200,0x44,0x72744c46);
        *param_4 = lVar5;
        if (lVar5 == 0) {
          return;
        }
        *param_3 = 0x44;
        local_a8 = 8;
      }
      *(undefined4 *)*param_4 = *(undefined4 *)(*(longlong *)(param_1 + 0x10) + 0x20);
    }
    iVar3 = FltQueryVolumeInformation
                      (*(undefined8 *)(param_2 + 0x18),local_98,*param_4 + 4,*param_3 + -4);
    if (-1 < iVar3) {
      return;
    }
    ExFreePoolWithTag(*param_4,0x72744c46);
    *param_4 = 0;
  }
  else {
    if (cVar2 != '\x15') {
      return;
    }
    local_98[0] = local_98[0] & 0xffffffff00000000;
    bVar1 = KeGetCurrentIrql();
    if (1 < bVar1) {
      return;
    }
    local_a0 = local_98;
    local_a8 = 0;
    iVar3 = FltQuerySecurityObject
                      (*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20),
                       *(undefined4 *)(*(longlong *)(param_1 + 0x10) + 0x18),0);
    if (iVar3 != -0x3fffffdd) {
      return;
    }
    iVar3 = (int)local_98[0];
    iVar6 = (int)local_98[0] + 4;
    puVar4 = (undefined4 *)ExAllocatePoolWithTag(0x200,iVar6,0x72744c46);
    *param_4 = (longlong)puVar4;
    if (puVar4 != (undefined4 *)0x0) {
      local_a0 = local_98;
      *puVar4 = *(undefined4 *)(*(longlong *)(param_1 + 0x10) + 0x18);
      local_a8 = iVar3;
      iVar3 = FltQuerySecurityObject
                        (*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20),
                         *(undefined4 *)(*(longlong *)(param_1 + 0x10) + 0x18),*param_4 + 4);
      if (iVar3 < 0) {
        ExFreePoolWithTag(*param_4,0x72744c46);
        *param_4 = 0;
      }
      *param_3 = iVar6;
      return;
    }
  }
  *param_3 = 0;
  return;
}



===== GetUserSidAndAcessToken @ 14000e308 =====

int GetUserSidAndAcessToken(longlong param_1,uint *param_2,undefined8 *param_3,longlong *param_4)

{
  bool bVar1;
  int iVar2;
  longlong lVar3;
  void *_Dst;
  uint uVar4;
  undefined1 local_res8 [8];
  undefined1 local_28 [4];
  undefined4 local_24;
  longlong *local_20;
  
  local_24 = 0;
  local_20 = (longlong *)0x0;
  local_28[0] = 0;
  local_res8[0] = 0;
  bVar1 = true;
  if (*(longlong *)(param_1 + 8) == 0) {
    iVar2 = -0x3ffffff3;
  }
  else {
    lVar3 = PsReferenceImpersonationToken(*(longlong *)(param_1 + 8),local_28,local_res8,&local_24);
    if (lVar3 == 0) {
      lVar3 = FltGetRequestorProcess(param_1);
      if (lVar3 == 0) {
        return -0x3fffffff;
      }
      lVar3 = PsReferencePrimaryToken(lVar3);
      bVar1 = false;
    }
    iVar2 = SeQueryInformationToken(lVar3,1,&local_20);
    if (-1 < iVar2) {
      *param_4 = lVar3;
      uVar4 = (uint)*(byte *)(*local_20 + 1) * 4 + 0x18;
      *param_2 = uVar4;
      _Dst = (void *)ExAllocatePoolWithTag(0x200,uVar4,0x72744c46);
      *param_3 = _Dst;
      if (_Dst == (void *)0x0) {
        iVar2 = -0x3fffff66;
      }
      else {
        memmove(_Dst,local_20,(ulonglong)*param_2);
      }
    }
    if (lVar3 != 0) {
      if (bVar1) {
        PsDereferenceImpersonationToken();
      }
      else {
        PsDereferencePrimaryToken(lVar3);
      }
    }
    if (local_20 != (longlong *)0x0) {
      ExFreePoolWithTag(local_20,0);
    }
  }
  return iVar2;
}



===== DeviceChangeNotificationRoutine @ 14000e480 =====

undefined8 DeviceChangeNotificationRoutine(longlong param_1,undefined8 param_2)

{
  int iVar1;
  longlong lVar2;
  
  if ((*(longlong *)(param_1 + 4) == 0x11d24c062de97f83) &&
     (*(longlong *)(param_1 + 0xc) == 0x5a051397600032a5)) {
    lVar2 = FltAllocateGenericWorkItem();
    if (lVar2 != 0) {
      iVar1 = FltQueueGenericWorkItem(lVar2,DAT_140008110,UpdateDosDriveLetter,1,param_2);
      if (iVar1 < 0) {
        FltFreeGenericWorkItem(lVar2);
      }
    }
  }
  return 0;
}



===== FTFilterUnload @ 14000e510 =====

undefined8 FTFilterUnload(void)

{
  undefined8 *puVar1;
  code *pcVar2;
  undefined8 *puVar3;
  undefined1 *puVar4;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  FltUnregisterFilter(DAT_140008110);
  ExDeleteNPagedLookasideList(&DAT_140008140);
  ExDeleteNPagedLookasideList(&DAT_1400081c0);
  IoWMIRegistrationControl(&WmiRegistrationContext,0x80000002);
  if (LogSessions != 0) {
    ExFreePoolWithTag(LogSessions,0x72744c46);
  }
  ExAcquireFastMutex(&DAT_140008258);
  puVar4 = auStack_28;
  do {
    puVar3 = DAT_140008248;
    if ((undefined8 **)DAT_140008248 == &DAT_140008248) {
LAB_14000e5f5:
      *(undefined8 *)(puVar4 + -8) = 0x14000e603;
      ExReleaseFastMutex(&DAT_140008258);
      *(undefined8 *)(puVar4 + -8) = 0x14000e60d;
      ThreadTableClear();
      if (g_wil_details_featureChangeNotification != 0) {
        *(undefined8 *)(puVar4 + -8) = 0x14000e620;
        RtlUnregisterFeatureConfigurationChangeNotification();
        g_wil_details_featureChangeNotification = 0;
      }
      if (g_wil_details_featureUsageProvider != 0) {
        *(undefined8 *)(puVar4 + -8) = 0x14000e640;
        RtlUnregisterFeatureUsageProvider();
        g_wil_details_featureUsageProvider = 0;
      }
      g_wil_details_isFeatureStagingInitialized = 0;
      return 0;
    }
    if (((undefined8 **)DAT_140008248[1] != &DAT_140008248) ||
       (puVar1 = (undefined8 *)*DAT_140008248, (undefined8 *)puVar1[1] != DAT_140008248)) {
      pcVar2 = (code *)swi(0x29);
      (*pcVar2)(3);
      puVar4 = auStack_20;
      goto LAB_14000e5f5;
    }
    DAT_140008248 = puVar1;
    puVar1[1] = &DAT_140008248;
    FltObjectDereference(puVar3[2]);
    ExFreePoolWithTag(puVar3,0x72744c46);
  } while( true );
}



===== FTInstanceQueryTeardown @ 14000e670 =====

undefined8 FTInstanceQueryTeardown(void)

{
  return 0;
}



===== FTInstanceSetup @ 14000e680 =====

int FTInstanceSetup(longlong param_1,undefined8 param_2,int param_3)

{
  uint uVar1;
  void *_Dst;
  longlong lVar2;
  code *pcVar3;
  bool bVar4;
  ushort uVar5;
  int iVar6;
  int iVar7;
  longlong *plVar8;
  undefined8 uVar9;
  undefined8 *puVar10;
  undefined1 *puVar11;
  uint uVar12;
  undefined1 auStack_a8 [8];
  undefined1 auStack_a0 [56];
  int local_68;
  undefined8 local_60;
  undefined4 local_58;
  uint uStack_54;
  int local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined2 *puStack_38;
  undefined8 local_30;
  longlong *local_28;
  
  local_68 = 0;
  local_60 = 0;
  local_48 = 0;
  local_58 = 0;
  local_30 = 0;
  plVar8 = (longlong *)0x0;
  local_28 = (longlong *)0x0;
  uVar12 = 0;
  local_40 = 0;
  puStack_38 = (undefined2 *)0x0;
  local_68 = FltGetDiskDeviceObject(*(undefined8 *)(param_1 + 0x10),&local_48);
  if ((-1 < local_68) && (local_68 = IoVolumeDeviceToDosName(local_48,&local_40), -1 < local_68)) {
    if (puStack_38 == (undefined2 *)0x0) {
      uVar12 = 8;
    }
    else if ((1 < (ushort)local_40) && (puStack_38[1] == 0x3a)) {
      uVar5 = RtlUpcaseUnicodeChar(*puStack_38);
      if (uVar5 - 0x41 < 0x1a) {
        uVar12 = 1 << ((byte)(uVar5 - 0x41) & 0x1f);
      }
    }
  }
  if (param_3 == 0x14) {
    uVar12 = uVar12 | 0x10000000;
  }
  else {
    uVar12 = uVar12 | 0x8000000;
  }
  local_50 = 0;
  bVar4 = false;
  uStack_54 = uVar12;
  ExAcquireFastMutex(&SessionLock);
  for (local_50 = 0; local_50 < 8; local_50 = local_50 + 1) {
    uVar1 = *(uint *)(LogSessions + 0x20 + (longlong)local_50 * 0x28);
    if (((uVar1 >> 0x1a & 1) != 0) || ((uVar12 & uVar1) != 0)) {
      bVar4 = true;
      break;
    }
  }
  ExReleaseFastMutex(&SessionLock);
  puVar11 = auStack_a8;
  if (bVar4) {
    plVar8 = (longlong *)ExAllocatePoolWithTag(1,0x20,0x72744c46);
    puVar11 = auStack_a8;
    local_28 = plVar8;
    if (plVar8 != (longlong *)0x0) {
      plVar8[2] = *(longlong *)(param_1 + 0x10);
      *(uint *)(plVar8 + 3) = uVar12;
      *(int *)((longlong)plVar8 + 0x1c) = param_3;
      iVar6 = FltObjectReference();
      puVar11 = auStack_a8;
      local_68 = iVar6;
      if (iVar6 < 0) goto LAB_14000eb09;
      ExAcquireFastMutex(&DAT_140008258);
      puVar11 = auStack_a8;
      puVar10 = &DAT_140008248;
      if ((longlong **)DAT_140008248[1] != &DAT_140008248) {
        puVar10 = (undefined8 *)0x3;
        pcVar3 = (code *)swi(0x29);
        DAT_140008248 = (longlong *)(*pcVar3)();
        puVar11 = auStack_a0;
      }
      *plVar8 = (longlong)DAT_140008248;
      plVar8[1] = (longlong)puVar10;
      DAT_140008248[1] = (longlong)plVar8;
      *(undefined8 *)(puVar11 + -8) = 0x14000e886;
      DAT_140008248 = plVar8;
      ExReleaseFastMutex(&DAT_140008258);
      *(undefined1 **)(puVar11 + 0x20) = puVar11 + 0x48;
      *(undefined8 *)(puVar11 + -8) = 0x14000e8b3;
      iVar6 = FltAllocateContext(DAT_140008110,1,0x1f8);
      *(int *)(puVar11 + 0x40) = iVar6;
      if (iVar6 < 0) goto LAB_14000eb09;
      *(undefined8 *)(puVar11 + -8) = 0x14000e8d5;
      memset(*(void **)(puVar11 + 0x48),0,0x1f8);
      uVar9 = *(undefined8 *)(param_1 + 0x10);
      *(undefined8 *)(puVar11 + -8) = 0x14000e8ec;
      iVar6 = FltSetVolumeContext(uVar9,0,*(undefined8 *)(puVar11 + 0x48),puVar11 + 0x78);
      *(int *)(puVar11 + 0x40) = iVar6;
      if (*(longlong *)(puVar11 + 0x78) != 0) {
        *(undefined8 *)(puVar11 + -8) = 0x14000e908;
        FltReleaseContext();
      }
      if (iVar6 < 0) goto LAB_14000eb09;
      *(int *)(*(longlong *)(puVar11 + 0x48) + 0x30) = param_3;
      *(uint *)(*(longlong *)(puVar11 + 0x48) + 0x1e0) = uVar12;
      *(longlong *)(*(longlong *)(puVar11 + 0x48) + 0x28) = *(longlong *)(puVar11 + 0x48) + 0xb4;
      *(undefined2 *)(*(longlong *)(puVar11 + 0x48) + 0x20) = 0;
      *(undefined2 *)(*(longlong *)(puVar11 + 0x48) + 0x22) = 300;
      *(undefined8 *)(puVar11 + -8) = 0x14000e966;
      memset((void *)(*(longlong *)(puVar11 + 0x48) + 0xb4),0,300);
      uVar5 = *(ushort *)(puVar11 + 0x68);
      if ((uVar5 != 0) && (uVar5 <= *(ushort *)(*(longlong *)(puVar11 + 0x48) + 0x22))) {
        _Dst = *(void **)(*(longlong *)(puVar11 + 0x48) + 0x28);
        *(undefined8 *)(puVar11 + -8) = 0x14000e98c;
        memmove(_Dst,*(void **)(puVar11 + 0x70),(ulonglong)uVar5);
        *(undefined2 *)(*(longlong *)(puVar11 + 0x48) + 0x20) = *(undefined2 *)(puVar11 + 0x68);
      }
      *(longlong *)(*(longlong *)(puVar11 + 0x48) + 0x18) = *(longlong *)(puVar11 + 0x48) + 0x34;
      *(undefined2 *)(*(longlong *)(puVar11 + 0x48) + 0x10) = 0;
      *(undefined2 *)(*(longlong *)(puVar11 + 0x48) + 0x12) = 0x80;
      *(undefined8 *)(puVar11 + -8) = 0x14000e9d1;
      memset((void *)(*(longlong *)(puVar11 + 0x48) + 0x34),0,0x80);
      uVar9 = *(undefined8 *)(param_1 + 0x10);
      *(undefined8 *)(puVar11 + -8) = 0x14000e9e3;
      iVar6 = FltGetVolumeName(uVar9,0,puVar11 + 0x50);
      *(int *)(puVar11 + 0x40) = iVar6;
      if (((iVar6 + 0x80000000U & 0x80000000) == 0) && (iVar6 != -0x3fffffdd)) goto LAB_14000eb09;
      if (*(uint *)(puVar11 + 0x50) < 0x10000) {
        *(undefined8 *)(puVar11 + -8) = 0x14000ea25;
        uVar9 = ExAllocatePoolWithTag(0x200,*(undefined4 *)(puVar11 + 0x50),0x72744c46);
        *(undefined8 *)(*(longlong *)(puVar11 + 0x48) + 8) = uVar9;
        if (*(longlong *)(*(longlong *)(puVar11 + 0x48) + 8) == 0) goto LAB_14000e808;
        *(short *)(*(longlong *)(puVar11 + 0x48) + 2) = (short)*(undefined4 *)(puVar11 + 0x50);
        uVar9 = *(undefined8 *)(param_1 + 0x10);
        *(undefined8 *)(puVar11 + -8) = 0x14000ea5d;
        iVar6 = FltGetVolumeName(uVar9,*(undefined8 *)(puVar11 + 0x48),0);
        *(int *)(puVar11 + 0x40) = iVar6;
        if (iVar6 < 0) goto LAB_14000eb09;
      }
      uVar9 = *(undefined8 *)(param_1 + 0x10);
      *(undefined8 *)(puVar11 + -8) = 0x14000ea87;
      FltGetVolumeGuidName(uVar9,*(longlong *)(puVar11 + 0x48) + 0x10,0);
      lVar2 = *(longlong *)(puVar11 + 0x48);
      if (*(longlong *)(lVar2 + 8) != 0) {
        *(undefined8 *)(puVar11 + 0x88) = 0;
        *(undefined8 *)(puVar11 + -8) = 0x14000eaba;
        iVar7 = IoGetDeviceObjectPointer(lVar2,0x100000,lVar2 + 0x1f0,puVar11 + 0x88);
        if (-1 < iVar7) {
          *(longlong *)(puVar11 + 0x30) = *(longlong *)(puVar11 + 0x48) + 0x1e8;
          *(undefined8 *)(puVar11 + 0x28) = *(undefined8 *)(param_1 + 0x10);
          *(code **)(puVar11 + 0x20) = DeviceChangeNotificationRoutine;
          uVar9 = *(undefined8 *)(*(longlong *)(puVar11 + 0x48) + 0x1f0);
          *(undefined8 *)(puVar11 + -8) = 0x14000eb03;
          IoRegisterPlugPlayNotification(3,0,uVar9,FileTraceData);
        }
      }
      goto LAB_14000eb09;
    }
LAB_14000e808:
    iVar6 = -0x3fffff66;
  }
  else {
    iVar6 = -0x3fffffff;
  }
  *(int *)(puVar11 + 0x40) = iVar6;
LAB_14000eb09:
  if (*(longlong *)(puVar11 + 0x60) != 0) {
    *(undefined8 *)(puVar11 + -8) = 0x14000eb1a;
    ObfDereferenceObject();
  }
  if (*(longlong *)(puVar11 + 0x70) != 0) {
    *(undefined8 *)(puVar11 + -8) = 0x14000eb32;
    ExFreePoolWithTag(*(longlong *)(puVar11 + 0x70),0);
  }
  if ((iVar6 < 0) && (plVar8 != (longlong *)0x0)) {
    *(undefined8 *)(puVar11 + -8) = 0x14000eb48;
    RemoveAttachedVolume(plVar8);
    *(undefined8 *)(puVar11 + -8) = 0x14000eb57;
    ExFreePoolWithTag(plVar8,0x72744c46);
  }
  if (*(longlong *)(puVar11 + 0x48) != 0) {
    *(undefined8 *)(puVar11 + -8) = 0x14000eb6d;
    FltReleaseContext();
  }
  return iVar6;
}



===== FTInstanceTeardownStart @ 14000eba0 =====

void FTInstanceTeardownStart(longlong param_1)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  int iVar4;
  longlong *plVar5;
  longlong local_res8;
  
  local_res8 = 0;
  iVar4 = FltGetVolumeContext(DAT_140008110,*(undefined8 *)(param_1 + 0x10),&local_res8);
  if ((-1 < iVar4) && (*(longlong *)(local_res8 + 0x1e8) != 0)) {
    IoUnregisterPlugPlayNotification();
  }
  ExAcquireFastMutex(&DAT_140008258);
  if ((longlong **)DAT_140008248 != &DAT_140008248) {
    plVar5 = DAT_140008248;
    do {
      if (plVar5[2] == *(longlong *)(param_1 + 0x10)) {
        FltObjectDereference();
        lVar1 = *plVar5;
        if ((*(longlong **)(lVar1 + 8) != plVar5) ||
           (plVar2 = (longlong *)plVar5[1], (longlong *)*plVar2 != plVar5)) {
          pcVar3 = (code *)swi(0x29);
          (*pcVar3)(3);
          pcVar3 = (code *)swi(3);
          (*pcVar3)();
          return;
        }
        *plVar2 = lVar1;
        *(longlong **)(lVar1 + 8) = plVar2;
        ExFreePoolWithTag(plVar5,0x72744c46);
        break;
      }
      plVar5 = (longlong *)*plVar5;
    } while ((longlong **)plVar5 != &DAT_140008248);
  }
  ExReleaseFastMutex(&DAT_140008258);
  if (local_res8 != 0) {
    FltReleaseContext();
  }
  return;
}



===== RemoveAttachedVolume @ 14000eca8 =====

void RemoveAttachedVolume(longlong *param_1)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  longlong *plVar5;
  
  ExAcquireFastMutex(&DAT_140008258);
  plVar5 = DAT_140008248;
  do {
    if ((longlong **)plVar5 == &DAT_140008248) {
LAB_14000ece5:
      ExReleaseFastMutex(&DAT_140008258);
      return;
    }
    if (plVar5 == param_1) {
      FltObjectDereference(plVar5[2]);
      plVar1 = *(longlong **)(*plVar5 + 8);
      lVar2 = *plVar1;
      if ((*(longlong **)(lVar2 + 8) != plVar1) ||
         (plVar3 = (longlong *)plVar1[1], (longlong *)*plVar3 != plVar1)) {
        pcVar4 = (code *)swi(0x29);
        (*pcVar4)(3);
        pcVar4 = (code *)swi(3);
        (*pcVar4)();
        return;
      }
      *plVar3 = lVar2;
      *(longlong **)(lVar2 + 8) = plVar3;
      ExFreePoolWithTag(plVar5,0x72744c46);
      goto LAB_14000ece5;
    }
    plVar5 = (longlong *)*plVar5;
  } while( true );
}



===== UpdateDosDriveLetter @ 14000ed60 =====

void UpdateDosDriveLetter(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined2 uVar1;
  uint uVar2;
  short sVar3;
  int iVar4;
  uint uVar5;
  longlong local_res18;
  undefined8 local_res20;
  undefined8 local_28;
  undefined2 *puStack_20;
  
  local_res20 = 0;
  local_res18 = 0;
  uVar5 = 0;
  local_28 = 0;
  puStack_20 = (undefined2 *)0x0;
  iVar4 = FltGetDiskDeviceObject(param_3,&local_res20);
  if (-1 < iVar4) {
    iVar4 = IoVolumeDeviceToDosName(local_res20,&local_28);
    if ((-1 < iVar4) && ((short)local_28 != 0)) {
      iVar4 = FltGetVolumeContext(DAT_140008110,param_3,&local_res18);
      if (-1 < iVar4) {
        sVar3 = RtlUpcaseUnicodeChar(*puStack_20);
        if ((ushort)(sVar3 - 0x41U) < 0x1a) {
          uVar1 = *puStack_20;
          *(undefined2 *)(local_res18 + 0xb4) = uVar1;
          uVar5 = 1 << ((char)uVar1 + 0xbfU & 0x1f);
        }
        uVar2 = *(uint *)(local_res18 + 0x1e0);
        ExAcquireFastMutex(&SessionLock);
        ExReleaseFastMutex(&SessionLock);
        *(uint *)(local_res18 + 0x1e0) = uVar5 | uVar2 & 0x18000000;
      }
    }
  }
  if (local_res18 != 0) {
    FltReleaseContext();
  }
  if (puStack_20 != (undefined2 *)0x0) {
    ExFreePoolWithTag(puStack_20,0);
  }
  FltFreeGenericWorkItem(param_1);
  return;
}



===== AttachToRequestedDrives$fin$0 @ 14000eec0 =====

void AttachToRequestedDrives_fin_0(undefined8 param_1,longlong param_2)

{
  ExFreePoolWithTag(*(undefined8 *)(param_2 + 0x100),0x72744c46);
  FltFreeGenericWorkItem(*(undefined8 *)(param_2 + 0xf0));
  return;
}



===== FTInitTracing$fin$0 @ 14000ef02 =====

void FTInitTracing_fin_0(undefined8 param_1,longlong param_2)

{
  if ((*(int *)(param_2 + 0x20) < 0) && (LogSessions != 0)) {
    ExFreePoolWithTag(LogSessions,0x72744c46);
    LogSessions = 0;
  }
  return;
}



===== FTInstanceSetup$fin$0 @ 14000ef43 =====

void FTInstanceSetup_fin_0(undefined8 param_1,longlong param_2)

{
  longlong *plVar1;
  
  if (*(longlong *)(param_2 + 0x60) != 0) {
    ObfDereferenceObject();
  }
  if (*(longlong *)(param_2 + 0x70) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 0x70),0);
  }
  if ((*(int *)(param_2 + 0x40) < 0) &&
     (plVar1 = *(longlong **)(param_2 + 0x80), plVar1 != (longlong *)0x0)) {
    RemoveAttachedVolume(plVar1);
    ExFreePoolWithTag(plVar1,0x72744c46);
  }
  if (*(longlong *)(param_2 + 0x48) != 0) {
    FltReleaseContext();
  }
  return;
}



===== entry @ 14000f010 =====

void entry(undefined8 param_1)

{
  __security_init_cookie();
  DriverEntry(param_1);
  return;
}



===== __security_init_cookie @ 14000f044 =====

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



===== DriverEntry @ 14000f078 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(undefined8 param_1)

{
  undefined8 *puVar1;
  int iVar2;
  ulonglong uVar3;
  undefined8 *puVar4;
  uint uVar5;
  undefined8 local_30;
  undefined8 uStack_28;
  
  local_30 = 0;
  uStack_28 = 0;
  wil_InitializeFeatureStaging();
  RtlInitUnicodeString(&local_30,L"KeAreAllApcsDisabled");
  GlobalLateBoundFunctions = MmGetSystemRoutineAddress(&local_30);
  _FTSequenceNumber = 0;
  _DAT_140008240 = 0;
  DAT_140008244 = 0x400;
  _DAT_140008250 = &DAT_140008248;
  DAT_140008248 = &DAT_140008248;
  _DAT_140008258 = 1;
  _DAT_140008260 = 0;
  _DAT_140008268 = 0;
  FileTraceData = param_1;
  KeInitializeEvent(&DAT_140008270,1,0);
  ExInitializeNPagedLookasideList(&DAT_140008140,0,0,0x200,0x110,0x72744c46,0);
  ExInitializeNPagedLookasideList(&DAT_1400081c0,0,0,0x200,0x800,0x72744c46,0);
  KeInitializeSpinLock(&DAT_1400082c0);
  memset(&ThreadTable,0,0x978);
  for (uVar5 = 0; uVar5 < 0x65; uVar5 = uVar5 + 1) {
    uVar3 = (ulonglong)uVar5;
    puVar1 = &DAT_140008328 + uVar3 * 3;
    *(undefined8 **)(&DAT_140008330 + uVar3 * 0x18) = puVar1;
    *puVar1 = puVar1;
    puVar4 = (undefined8 *)ExAllocatePoolWithTag(0x200,0x18,0x72744c46);
    if (puVar4 == (undefined8 *)0x0) break;
    *puVar4 = 0;
    puVar4[1] = 0;
    puVar4[2] = 0;
    ExInterlockedInsertHeadList(puVar1,puVar4 + 1,&DAT_1400082c0);
    LOCK();
    *(int *)(&ThreadTable + uVar3 * 0x18) = *(int *)(&ThreadTable + uVar3 * 0x18) + 1;
    UNLOCK();
  }
  iVar2 = FltRegisterFilter(param_1,&FilterRegistration,&DAT_140008110);
  if (-1 < iVar2) {
    iVar2 = FTInitTracing();
    if (-1 < iVar2) {
      InitBootLoggingIfSet();
      iVar2 = FltStartFiltering(DAT_140008110);
    }
  }
  if (iVar2 < 0) {
    if (DAT_140008110 != 0) {
      FltUnregisterFilter();
    }
    ExDeleteNPagedLookasideList(&DAT_140008140);
    ExDeleteNPagedLookasideList(&DAT_1400081c0);
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
  return iVar2;
}



===== wil_InitializeFeatureStaging @ 14000f34c =====

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
      if (*ppuVar3 != (undefined *)0x0) goto LAB_14000f3d3;
    }
LAB_14000f40d:
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
LAB_14000f3d3:
  if (ppuVar3 == (undefined **)0x0) goto LAB_14000f40d;
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
    goto LAB_14000f40d;
  }
  ppuVar3 = ppuVar3 + 7;
  while( true ) {
    if (&UNK_14000701f < ppuVar3) goto LAB_14000f40d;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_14000f3d3;
}



===== wil_details_PopulateInitialConfiguredFeatureStates @ 14000f460 =====

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
            if (&UNK_14000701f < ppuVar4) {
              return;
            }
            if (*ppuVar4 != (undefined *)0x0) break;
            ppuVar4 = ppuVar4 + 1;
          }
        } while (ppuVar4 != (undefined **)0x0);
        return;
      }
      if (iVar3 == -0x3ffffddb) goto LAB_14000f54a;
      if (iVar3 == 0) {
        local_28 = (ulonglong)(((local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0) << 3 | 0x206);
      }
      else {
        if (iVar3 != 0x117) goto LAB_14000f54a;
        local_28 = (ulonglong)((local_20._4_4_ & 0x80) << 3 | 0x206);
      }
    }
    else {
LAB_14000f54a:
      local_28 = 0x206;
    }
    puVar1 = (ulonglong *)*ppuVar4;
    ppuVar4 = ppuVar4 + 7;
    *puVar1 = local_28;
    while( true ) {
      if (&UNK_14000701f < ppuVar4) {
        return;
      }
      if (*ppuVar4 != (undefined *)0x0) break;
      ppuVar4 = ppuVar4 + 1;
    }
  } while( true );
}



===== InitBootLoggingIfSet @ 14000f5dc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void InitBootLoggingIfSet(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  longlong *plVar5;
  int iVar6;
  int iVar7;
  wchar_t *pwVar8;
  undefined8 uVar9;
  code *pcVar10;
  longlong lVar11;
  undefined1 auStack_138 [32];
  undefined8 local_118;
  int local_108;
  int local_104 [3];
  wchar_t *local_f8;
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 local_c8;
  undefined4 local_c0;
  wchar_t *local_b8;
  int *local_b0;
  undefined4 local_a8;
  int *local_a0;
  undefined4 local_98;
  undefined8 local_90;
  undefined4 local_88;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_138;
  local_f8 = (wchar_t *)0x0;
  local_108 = 0;
  local_104[0] = 0;
  local_104[1] = 0;
  pwVar8 = (wchar_t *)ExAllocatePoolWithTag(0x200,0x6c,0x72744c46);
  local_f8 = pwVar8;
  if (pwVar8 != (wchar_t *)0x0) {
    uVar9 = RtlStringCbPrintfW(pwVar8,0x6c,L"%ws",L"WMI\\GlobalLogger\\");
    if (-1 < (int)uVar9) {
      local_c8 = 0;
      local_c0 = 0x20;
      local_b8 = L"Start";
      local_b0 = local_104;
      local_a8 = 4;
      local_a0 = local_104 + 1;
      local_98 = 4;
      local_90 = 0;
      local_88 = 0;
      local_f0 = 0;
      uStack_e8 = 0;
      RtlInitUnicodeString(&local_f0,L"RtlQueryRegistryValuesEx");
      pcVar10 = (code *)MmGetSystemRoutineAddress(&local_f0);
      if (pcVar10 == (code *)0x0) {
        pcVar10 = RtlQueryRegistryValues_exref;
      }
      local_118 = 0;
      iVar6 = (*pcVar10)(0x80000002,pwVar8,&local_c8,0);
      if ((-1 < iVar6) && (local_104[0] != 0)) {
        ExAcquireFastMutex(&SessionLock);
        if (*LogSessions == 0) {
          local_104[2] = 0;
          while (iVar6 = local_104[2], local_104[2] < 4) {
            lVar11 = (longlong)local_104[2];
            puVar1 = (undefined8 *)(&ControlGuidStrings)[lVar11];
            uVar9 = puVar1[1];
            *(undefined8 *)(pwVar8 + 0x11) = *puVar1;
            *(undefined8 *)(pwVar8 + 0x15) = uVar9;
            uVar9 = puVar1[3];
            *(undefined8 *)(pwVar8 + 0x19) = puVar1[2];
            *(undefined8 *)(pwVar8 + 0x1d) = uVar9;
            uVar9 = puVar1[5];
            *(undefined8 *)(pwVar8 + 0x21) = puVar1[4];
            *(undefined8 *)(pwVar8 + 0x25) = uVar9;
            uVar2 = *(undefined4 *)((longlong)puVar1 + 0x34);
            uVar3 = *(undefined4 *)(puVar1 + 7);
            uVar4 = *(undefined4 *)((longlong)puVar1 + 0x3c);
            *(undefined4 *)(pwVar8 + 0x29) = *(undefined4 *)(puVar1 + 6);
            *(undefined4 *)(pwVar8 + 0x2b) = uVar2;
            *(undefined4 *)(pwVar8 + 0x2d) = uVar3;
            *(undefined4 *)(pwVar8 + 0x2f) = uVar4;
            *(undefined8 *)(pwVar8 + 0x31) = puVar1[8];
            pwVar8[0x35] = *(wchar_t *)(puVar1 + 9);
            local_c8 = 0;
            local_c0 = 0x20;
            local_b8 = L"Flags";
            local_b0 = &local_108;
            local_a8 = 4;
            local_a0 = local_104 + 1;
            local_98 = 4;
            local_90 = 0;
            local_88 = 0;
            local_e0 = 0;
            uStack_d8 = 0;
            RtlInitUnicodeString(&local_e0,L"RtlQueryRegistryValuesEx");
            pcVar10 = (code *)MmGetSystemRoutineAddress(&local_e0);
            if (pcVar10 == (code *)0x0) {
              pcVar10 = RtlQueryRegistryValues_exref;
            }
            local_118 = 0;
            iVar7 = (*pcVar10)(0x80000002,pwVar8,&local_c8,0);
            plVar5 = LogSessions;
            if ((-1 < iVar7) && (local_108 != 0)) {
              if (*LogSessions == 0) {
                iVar7 = SessionSerialNumber + 1;
                if (SessionSerialNumber + 1 == 0) {
                  iVar7 = SessionSerialNumber + 2;
                }
                SessionSerialNumber = iVar7;
                *(int *)((longlong)LogSessions + 0xc) = SessionSerialNumber;
                *(int *)(plVar5 + 1) = (int)plVar5[1] + 1;
                *plVar5 = 1;
              }
              *(int *)((longlong)plVar5 + lVar11 * 4 + 0x14) = local_108;
            }
            local_104[2] = iVar6 + 1;
          }
        }
        ExReleaseFastMutex(&SessionLock);
      }
    }
  }
  if (pwVar8 != (wchar_t *)0x0) {
    ExFreePoolWithTag(pwVar8,0);
  }
  return;
}



===== DriverEntry$fin$0 @ 14000f906 =====

void DriverEntry_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(int *)(param_2 + 0x40) < 0) {
    if (DAT_140008110 != 0) {
      FltUnregisterFilter();
    }
    ExDeleteNPagedLookasideList(&DAT_140008140);
    ExDeleteNPagedLookasideList(&DAT_1400081c0);
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
  return;
}



===== InitBootLoggingIfSet$fin$0 @ 14000f9ac =====

void InitBootLoggingIfSet_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(longlong *)(param_2 + 0x40) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 0x40),0);
  }
  return;
}


