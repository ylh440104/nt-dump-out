
===== BfGetMappingContexts @ 140001010 =====

undefined8 *
BfGetMappingContexts
          (undefined8 param_1,longlong param_2,longlong param_3,undefined8 *param_4,
          undefined8 *param_5,undefined8 *param_6)

{
  undefined8 uVar1;
  char cVar2;
  uint uVar3;
  uint extraout_EAX;
  longlong lVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  undefined2 uVar9;
  undefined8 uVar10;
  bool bVar11;
  undefined1 uVar12;
  undefined8 *local_68;
  longlong local_60;
  undefined8 *local_58;
  undefined8 local_50;
  longlong local_48;
  undefined8 uStack_40;
  longlong local_38;
  undefined8 uStack_30;
  
  puVar5 = (undefined8 *)0x0;
  uVar3 = 0;
  uVar6 = 0;
  uVar10 = 0;
  local_60 = 0;
  lVar4 = IoGetSilo();
  if (lVar4 == 0) {
LAB_14000105e:
    if (param_3 != 0) {
      local_48 = 0;
      uStack_40 = 0;
      local_38 = 0;
      uStack_30 = 0;
      bVar11 = *(char *)(*(longlong *)(param_3 + 0x10) + 4) != (char)puVar5;
      local_68 = puVar5;
      local_58 = puVar5;
      if (bVar11) {
        SeCaptureSubjectContext(&local_48);
      }
      else {
        lVar4 = *(longlong *)(*(longlong *)(*(longlong *)(param_3 + 0x10) + 0x18) + 8);
        local_48 = *(longlong *)(lVar4 + 0x20);
        uStack_40 = *(undefined8 *)(lVar4 + 0x28);
        local_38 = *(longlong *)(lVar4 + 0x30);
        uStack_30 = *(undefined8 *)(lVar4 + 0x38);
      }
      lVar4 = local_48;
      if (local_48 == 0) {
        lVar4 = local_38;
      }
      uVar3 = SeQueryInformationToken(lVar4,1,&local_68);
      puVar8 = (undefined8 *)(ulonglong)uVar3;
      if ((int)uVar3 < 0) {
LAB_14000120d:
        puVar7 = puVar5;
      }
      else {
        uVar3 = SeQueryAuthenticationIdToken(lVar4,&local_58);
        puVar8 = (undefined8 *)(ulonglong)uVar3;
        if ((int)uVar3 < 0) goto LAB_14000120d;
        local_50 = *local_68;
        FltAcquireResourceShared(&DAT_14000d2a8);
        for (puVar7 = DAT_14000d298; (undefined8 **)puVar7 != &DAT_14000d298;
            puVar7 = (undefined8 *)*puVar7) {
          cVar2 = RtlEqualSid(puVar7[2],local_50);
          if (cVar2 != '\0') goto LAB_14000113e;
        }
        puVar8 = (undefined8 *)0xc0000225;
        puVar7 = puVar5;
LAB_14000113e:
        FltReleaseResource(&DAT_14000d2a8);
      }
      uVar3 = (uint)puVar8;
      if (bVar11) {
        SeReleaseSubjectContext(&local_48);
      }
      if (local_68 != (undefined8 *)0x0) {
        ExFreePoolWithTag(local_68,0);
      }
      if (uVar3 != 0xc0000225) {
        if ((int)uVar3 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_1400011bb;
          uVar9 = 0xc;
          uVar12 = 0xfc;
          goto LAB_1400012d3;
        }
        uVar10 = puVar7[3];
      }
    }
    uVar1 = *(undefined8 *)(param_2 + 0x30);
    if (uVar3 != 0xc0000225) {
      puVar5 = (undefined8 *)(ulonglong)uVar3;
    }
    *param_4 = uVar6;
    *param_5 = uVar10;
    *param_6 = uVar1;
    puVar8 = puVar5;
  }
  else {
    uVar3 = BfGetOrCreateSiloContext(lVar4,'\x01',&local_60);
    puVar5 = (undefined8 *)(ulonglong)uVar3;
    puVar8 = (undefined8 *)(ulonglong)extraout_EAX;
    uVar3 = extraout_EAX;
    if (extraout_EAX == 0xc0000225) goto LAB_14000105e;
    if (-1 < (int)extraout_EAX) {
      uVar6 = *(undefined8 *)(local_60 + 8);
      goto LAB_14000105e;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400011bb;
    uVar9 = 0xb;
    uVar12 = 0xed;
LAB_1400012d3:
    WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,7,uVar9,
                        &WPP_ab4056511ca038337f1519c30a6fffbb_Traceguids,
                        "onecore\\base\\fs\\wci\\bindflt\\filter\\context.c",uVar12,(char)uVar3);
  }
LAB_1400011bb:
  if (local_60 != 0) {
    PsDereferenceSiloContext();
  }
  return puVar8;
}



===== WPP_RECORDER_SF_sDd @ 140001318 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDd(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                        undefined8 param_5,char *param_6,undefined1 param_7,undefined1 param_8)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  
  uVar4 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar4 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar4 * 0x50 + 0x29])) {
    if (param_6 == (char *)0x0) {
      lVar2 = 5;
    }
    else {
      lVar3 = -1;
      do {
        lVar2 = lVar3;
        lVar3 = lVar2 + 1;
      } while (param_6[lVar3] != '\0');
      lVar2 = lVar2 + 2;
    }
    pcVar1 = param_6;
    if (param_6 == (char *)0x0) {
      pcVar1 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar4 * 0x50 + 0x18),0x2b,param_5,param_4,pcVar1
               ,lVar2,&param_7,4,&param_8,4,0);
  }
  lVar2 = -1;
  if (param_6 == (char *)0x0) {
    lVar3 = 5;
  }
  else {
    do {
      lVar3 = lVar2;
      lVar2 = lVar3 + 1;
    } while (param_6[lVar2] != '\0');
    lVar3 = lVar3 + 2;
  }
  if (param_6 == (char *)0x0) {
    param_6 = "NULL";
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,param_6,lVar3,&param_7,4,&param_8,4,0);
  return;
}



===== BfPreCleanup @ 1400014e0 =====

undefined8 BfPreCleanup(longlong param_1,longlong param_2)

{
  byte bVar1;
  char cVar2;
  longlong lVar3;
  longlong lVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  int iVar7;
  longlong local_res10;
  
  lVar3 = *(longlong *)(param_2 + 0x20);
  local_res10 = 0;
  if ((*(short **)(lVar3 + 0x18) != (short *)0x0) && (**(short **)(lVar3 + 0x18) == 0x6431)) {
    iVar7 = FltGetStreamHandleContext(*(undefined8 *)(param_2 + 0x18),lVar3,&local_res10);
    if (-1 < iVar7) {
      bVar1 = *(byte *)(local_res10 + 0x50);
      FltReleaseContext();
      if ((bVar1 & 1) != 0) {
        lVar4 = *(longlong *)(lVar3 + 0x18);
        puVar5 = *(undefined8 **)(lVar3 + 0x20);
        ExAcquireFastMutex(*(undefined8 *)(lVar4 + 0x30));
        uVar6 = *puVar5;
        *puVar5 = 0;
        *(uint *)(lVar3 + 0x50) = *(uint *)(lVar3 + 0x50) | 0x4000;
        cVar2 = *(char *)(lVar3 + 0x48);
        *(undefined8 *)(lVar3 + 0x30) = 0;
        ExReleaseFastMutex(*(undefined8 *)(lVar4 + 0x30));
        if (cVar2 != '\0') {
          BfUnlockAll(puVar5[2],puVar5[1]);
        }
        FltClose(uVar6);
        BfUpdateFileSizes(puVar5[1],lVar3);
        *(undefined4 *)(param_1 + 0x18) = 0;
        *(undefined8 *)(param_1 + 0x20) = 0;
        return 4;
      }
    }
  }
  return 1;
}



===== BfPreClose @ 140001600 =====

undefined8 BfPreClose(longlong param_1,longlong param_2)

{
  byte bVar1;
  longlong lVar2;
  longlong lVar3;
  int iVar4;
  undefined8 uVar5;
  longlong local_res10 [2];
  longlong local_res20;
  
  lVar2 = *(longlong *)(param_2 + 0x20);
  uVar5 = 1;
  local_res10[0] = 0;
  local_res20 = 0;
  if ((((*(short **)(lVar2 + 0x18) != (short *)0x0) && (**(short **)(lVar2 + 0x18) == 0x6431)) &&
      (iVar4 = FltGetStreamHandleContext(*(undefined8 *)(param_2 + 0x18),lVar2,&local_res20),
      -1 < iVar4)) && (bVar1 = *(byte *)(local_res20 + 0x50), FltReleaseContext(), (bVar1 & 1) != 0)
     ) {
    lVar3 = *(longlong *)(lVar2 + 0x20);
    iVar4 = FltGetInstanceContext(*(undefined8 *)(param_2 + 0x18),local_res10);
    if (-1 < iVar4) {
      LOCK();
      *(int *)(local_res10[0] + 0x20) = *(int *)(local_res10[0] + 0x20) + -1;
      UNLOCK();
      *(undefined8 *)(lVar2 + 0x18) = 0;
      *(undefined8 *)(lVar2 + 0x20) = 0;
      *(undefined8 *)(lVar2 + 0x10) = 0;
      ObfDereferenceObject(*(undefined8 *)(lVar3 + 8));
      *(undefined8 *)(lVar3 + 8) = 0;
      uVar5 = 4;
      *(undefined4 *)(param_1 + 0x18) = 0;
      *(undefined8 *)(param_1 + 0x20) = 0;
    }
  }
  if (local_res10[0] != 0) {
    FltReleaseContext(local_res10[0]);
  }
  return uVar5;
}



===== BfPreReleaseForSectionSynchronization @ 140001720 =====

undefined8 BfPreReleaseForSectionSynchronization(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  int extraout_EAX;
  ulonglong uVar4;
  longlong lVar5;
  longlong local_res10 [2];
  undefined8 local_res20;
  
  lVar1 = *(longlong *)(param_2 + 0x20);
  local_res10[0] = 0;
  uVar4 = BfMapShadowFileObjectToReal
                    (*(undefined8 *)(param_2 + 0x18),lVar1,0,&local_res20,local_res10,
                     (undefined8 *)0x0);
  lVar2 = local_res10[0];
  if ((char)uVar4 != '\0') {
    iVar3 = FsRtlChangeBackingFileObject(*(undefined8 *)(param_2 + 0x20),local_res10[0],1);
    if ((iVar3 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x11,
                          &WPP_59754cb100fb33f1965e7b014742173a_Traceguids,
                          "onecore\\base\\fs\\wci\\bindflt\\filter\\bindflt.c",0xd0,(char)iVar3);
    }
    iVar3 = FsRtlChangeBackingFileObject(*(undefined8 *)(param_2 + 0x20),lVar2,0);
    if ((iVar3 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x12,
                          &WPP_59754cb100fb33f1965e7b014742173a_Traceguids,
                          "onecore\\base\\fs\\wci\\bindflt\\filter\\bindflt.c",0xdc,(char)iVar3);
    }
    lVar5 = lVar2;
    iVar3 = FsRtlChangeBackingFileObject(*(undefined8 *)(param_2 + 0x20));
    if ((iVar3 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      lVar5 = CONCAT71((int7)((ulonglong)lVar5 >> 8),2);
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x13,
                          &WPP_59754cb100fb33f1965e7b014742173a_Traceguids,
                          "onecore\\base\\fs\\wci\\bindflt\\filter\\bindflt.c",0xe8,(char)iVar3);
    }
    if (*(int *)(*(longlong *)(param_1 + 0x10) + 0x18) == 0) {
      BfUpdateHeaderFlagsReverse(lVar1,lVar5,lVar2);
    }
    BfCheckAndSwitchTarget(param_1,param_2,(longlong *)0x0,(undefined1 *)0x0);
    if (extraout_EAX < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0x14,
                            &WPP_59754cb100fb33f1965e7b014742173a_Traceguids,
                            "onecore\\base\\fs\\wci\\bindflt\\filter\\bindflt.c",0xfb,
                            (char)extraout_EAX);
      }
      *(int *)(param_1 + 0x18) = extraout_EAX;
      *(undefined8 *)(param_1 + 0x20) = 0;
      return 4;
    }
  }
  return 1;
}



===== WPP_RECORDER_SF_sDZZZd @ 140001960 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDZZZd
               (undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,undefined8 param_5,
               wchar_t *param_6,undefined1 param_7,wchar_t *param_8,wchar_t *param_9,
               wchar_t *param_10,undefined1 param_11)

{
  wchar_t *pwVar1;
  wchar_t *pwVar2;
  wchar_t wVar3;
  longlong lVar4;
  longlong lVar5;
  wchar_t *pwVar6;
  wchar_t *pwVar7;
  char *pcVar8;
  wchar_t wVar9;
  wchar_t *pwVar10;
  wchar_t wVar11;
  wchar_t *pwVar12;
  wchar_t *pwVar13;
  wchar_t *pwVar14;
  wchar_t *pwVar15;
  wchar_t *local_58;
  
  pwVar7 = param_10;
  pwVar14 = param_9;
  pwVar6 = param_8;
  pcVar8 = (char *)param_6;
  pwVar15 = L"NULL";
  local_58 = L"\b";
  pwVar10 = param_10;
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + (ulonglong)(param_3 >> 0x10) * 0x14) * 4 +
                 0x2c) >> (param_3 - 1 & 0x1f) & 1) != 0) &&
     (pwVar10 = (wchar_t *)(WPP_GLOBAL_Control + (ulonglong)(param_3 >> 0x10) * 0x50),
     param_2 <= *(byte *)((longlong)pwVar10 + 0x29))) {
    if (param_10 == (wchar_t *)0x0) {
      wVar11 = L'\b';
LAB_140001bd5:
      param_8 = L"NULL";
    }
    else {
      wVar11 = *param_10;
      if (*param_10 == L'\0') goto LAB_140001bd5;
      param_8 = *(wchar_t **)(param_10 + 4);
    }
    if (param_10 == (wchar_t *)0x0) {
      param_10 = L"\b";
    }
    if (param_9 == (wchar_t *)0x0) {
      wVar3 = L'\b';
LAB_140001c0f:
      pwVar13 = L"NULL";
    }
    else {
      wVar3 = *param_9;
      if (*param_9 == L'\0') goto LAB_140001c0f;
      pwVar13 = *(wchar_t **)(param_9 + 4);
    }
    if (param_9 == (wchar_t *)0x0) {
      param_9 = L"\b";
    }
    if (pwVar6 == (wchar_t *)0x0) {
      wVar9 = L'\b';
    }
    else {
      wVar9 = *pwVar6;
      if (*pwVar6 != L'\0') {
        pwVar15 = *(wchar_t **)(pwVar6 + 4);
      }
    }
    pwVar12 = pwVar6;
    if (pwVar6 == (wchar_t *)0x0) {
      pwVar12 = L"\b";
    }
    if (param_6 == (wchar_t *)0x0) {
      lVar4 = 5;
    }
    else {
      lVar5 = -1;
      do {
        lVar4 = lVar5;
        lVar5 = lVar4 + 1;
      } while (*(char *)((longlong)param_6 + lVar5) != '\0');
      lVar4 = lVar4 + 2;
    }
    if (param_6 == (wchar_t *)0x0) {
      param_6 = (wchar_t *)"NULL";
    }
    pwVar1 = param_9;
    param_9 = param_10;
    pwVar2 = param_10;
    param_10 = pwVar10;
    (*pfnWppTraceMessage)
              (*(undefined8 *)(pwVar10 + 0xc),0x2b,param_5,param_4,param_6,lVar4,&param_7,4,pwVar12,
               2,pwVar15,wVar9,pwVar1,2,pwVar13,wVar3,pwVar2,2,param_8,wVar11,&param_11,4,0);
    pwVar10 = param_10;
  }
  param_10 = pwVar10;
  pwVar15 = L"NULL";
  wVar11 = L'\b';
  if (pwVar7 == (wchar_t *)0x0) {
    wVar3 = L'\b';
LAB_140001d79:
    param_6 = L"NULL";
  }
  else {
    wVar3 = *pwVar7;
    if (*pwVar7 == L'\0') goto LAB_140001d79;
    param_6 = *(wchar_t **)(pwVar7 + 4);
  }
  if (pwVar7 == (wchar_t *)0x0) {
    pwVar7 = L"\b";
  }
  if (pwVar14 == (wchar_t *)0x0) {
    wVar9 = L'\b';
  }
  else {
    wVar9 = *pwVar14;
    if (*pwVar14 != L'\0') {
      pwVar10 = *(wchar_t **)(pwVar14 + 4);
      goto LAB_140001a5a;
    }
  }
  pwVar10 = L"NULL";
LAB_140001a5a:
  if (pwVar14 == (wchar_t *)0x0) {
    pwVar14 = local_58;
  }
  if ((pwVar6 != (wchar_t *)0x0) && (wVar11 = *pwVar6, *pwVar6 != L'\0')) {
    pwVar15 = *(wchar_t **)(pwVar6 + 4);
  }
  if (pwVar6 == (wchar_t *)0x0) {
    pwVar6 = L"\b";
  }
  lVar4 = -1;
  if ((wchar_t *)pcVar8 == (wchar_t *)0x0) {
    lVar5 = 5;
  }
  else {
    do {
      lVar5 = lVar4;
      lVar4 = lVar5 + 1;
    } while (*(char *)((longlong)pcVar8 + lVar4) != '\0');
    lVar5 = lVar5 + 2;
  }
  if ((wchar_t *)pcVar8 == (wchar_t *)0x0) {
    pcVar8 = "NULL";
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,pcVar8,lVar5,&param_7,4,pwVar6,2,pwVar15,
                  wVar11,pwVar14,2,pwVar10,wVar9,pwVar7,2,param_6,wVar3,&param_11,4,0);
  return;
}



===== BfGeneratePostCreateName @ 140001da0 =====

ulonglong BfGeneratePostCreateName
                    (longlong param_1,undefined8 param_2,uint param_3,longlong param_4,
                    longlong param_5,short *param_6)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  ushort *puVar4;
  undefined2 uVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  longlong local_28;
  ushort local_20 [12];
  
  local_28 = 0;
  local_20[0] = 0;
  local_20[1] = 0;
  local_20[2] = 0;
  local_20[3] = 0;
  local_20[4] = 0;
  local_20[5] = 0;
  local_20[6] = 0;
  local_20[7] = 0;
  uVar2 = BfGetFileNameInformation(0,param_1,param_2,param_3,&local_28);
  uVar3 = uVar2 & 0xffffffff;
  if ((int)uVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
    goto LAB_140001e64;
  }
  *(undefined2 *)(local_28 + 2) = 0;
  uVar2 = BfFormatPathFromFileNameInfo(local_28,'\x01',(undefined4 *)local_20);
  uVar3 = uVar2 & 0xffffffff;
  if ((int)uVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140001e64;
    uVar7 = (undefined1)uVar2;
    uVar5 = 0x20;
    uVar6 = 0x14;
  }
  else {
    if ((param_3 & 0xff) == 1) {
      puVar4 = (ushort *)(*(longlong *)(param_4 + 0x28) + 0x10);
    }
    else {
      puVar4 = (ushort *)(param_4 + 0x40);
    }
    uVar2 = BfReplaceFirstSubstring
                      (local_20,(ushort *)(*(longlong *)(param_4 + 0x30) + 0x28),puVar4,
                       (undefined4 *)param_6);
    uVar3 = uVar2 & 0xffffffff;
    if ((int)uVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140001e64;
      uVar7 = (undefined1)uVar2;
      uVar5 = 0x21;
      uVar6 = 0x30;
    }
    else {
      if (param_5 == 0) goto LAB_140001e64;
      uVar1 = BfPrependVolumeNameFromInstance(param_5,param_6);
      uVar3 = (ulonglong)uVar1;
      if ((-1 < (int)uVar1) || ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
         ) goto LAB_140001e64;
      uVar7 = (undefined1)uVar1;
      uVar5 = 0x22;
      uVar6 = 0x3d;
    }
  }
  WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,9,uVar5,
                      &WPP_c7f51acdbd3738713a5b9ea834ad885a_Traceguids,
                      "onecore\\base\\fs\\wci\\bindflt\\filter\\namesup.c",uVar6,uVar7);
LAB_140001e64:
  if (local_28 != 0) {
    FltReleaseFileNameInformation();
  }
  BfFreeUnicodeString((undefined4 *)local_20);
  return uVar3;
}



===== BfReplaceFirstSubstring @ 140001fa0 =====

ulonglong BfReplaceFirstSubstring
                    (ushort *param_1,ushort *param_2,ushort *param_3,undefined4 *param_4)

{
  int iVar1;
  bool bVar2;
  ushort uVar3;
  longlong lVar4;
  ulonglong uVar5;
  short sVar6;
  ushort uVar7;
  ulonglong uVar8;
  short sVar9;
  undefined2 uVar10;
  undefined4 local_res10 [2];
  undefined1 uVar11;
  uint uVar12;
  ulonglong local_48;
  longlong lStack_40;
  undefined8 local_38;
  undefined4 *local_30;
  
  local_38 = 0x40002;
  *(undefined8 *)(param_4 + 2) = 0;
  bVar2 = false;
  local_res10[0] = 0x5c;
  local_30 = local_res10;
  if ((((*param_2 == 2) && (**(short **)(param_2 + 4) == 0x5c)) && (2 < *param_1)) ||
     (((*param_3 == 0 && (*param_1 != 0)) && (*param_1 == *param_2)))) {
    bVar2 = true;
  }
  lVar4 = RtlFindUnicodeSubstring(param_1,param_2,1);
  if (lVar4 == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,8,0x15,
                         &WPP_529f93b0825532f67776c14f74ba0846_Traceguids,
                         "onecore\\base\\fs\\wci\\bindflt\\filter\\utils.c",0x19);
    }
    uVar8 = 0xc0000225;
    goto LAB_140002186;
  }
  iVar1 = *(int *)(param_1 + 4);
  uVar3 = *param_2;
  uVar7 = *param_1;
  if (*param_3 == uVar3) {
LAB_140002079:
    uVar3 = uVar7 + 2;
    if (!bVar2) {
      uVar3 = uVar7;
    }
    uVar8 = BfAllocateUnicodeString(uVar3,param_4);
    uVar12 = (uint)uVar8;
    uVar8 = uVar8 & 0xffffffff;
    if ((int)uVar12 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140002186;
      uVar10 = 0x18;
      uVar11 = 0x58;
    }
    else {
      sVar9 = (short)((longlong)(ulonglong)(uint)((int)lVar4 - iVar1) >> 1);
      sVar6 = sVar9 * 2;
      local_48 = (ulonglong)CONCAT22(sVar6,sVar6);
      lStack_40 = *(longlong *)(param_1 + 4);
      uVar12 = RtlAppendUnicodeStringToString(param_4,&local_48);
      uVar8 = (ulonglong)uVar12;
      if ((int)uVar12 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140002186;
        uVar10 = 0x19;
        uVar11 = 0x6b;
      }
      else {
        uVar12 = RtlAppendUnicodeStringToString(param_4,param_3);
        uVar8 = (ulonglong)uVar12;
        if ((int)uVar12 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_140002186;
          uVar10 = 0x1a;
          uVar11 = 0x78;
        }
        else {
          if (bVar2) {
            uVar12 = RtlAppendUnicodeStringToString(param_4,&local_38);
            uVar8 = (ulonglong)uVar12;
            if ((int)uVar12 < 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
              goto LAB_140002186;
              uVar10 = 0x1b;
              uVar11 = 0x86;
              goto LAB_140002317;
            }
          }
          uVar3 = (*param_2 >> 1) + sVar9;
          sVar6 = *param_1 + uVar3 * -2;
          local_48 = (ulonglong)CONCAT22(sVar6,sVar6);
          lStack_40 = *(longlong *)(param_1 + 4) + (ulonglong)uVar3 * 2;
          uVar5 = RtlAppendUnicodeStringToString(param_4,&local_48);
          uVar12 = (uint)uVar5;
          uVar8 = uVar5 & 0xffffffff;
          if (-1 < (int)uVar12) {
            return uVar5;
          }
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_140002186;
          uVar10 = 0x1c;
          uVar11 = 0x9a;
        }
      }
    }
  }
  else if (uVar7 < uVar3) {
    uVar8 = 0xc0000095;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140002186;
    uVar12 = 0xc0000095;
    uVar10 = 0x16;
    uVar11 = 0x38;
  }
  else {
    uVar3 = uVar7 - uVar3;
    uVar7 = *param_3 + uVar3;
    if (uVar3 <= uVar7) goto LAB_140002079;
    uVar8 = 0xc0000095;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140002186;
    uVar12 = 0xc0000095;
    uVar10 = 0x17;
    uVar11 = 0x41;
  }
LAB_140002317:
  WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,8,uVar10,
                      &WPP_529f93b0825532f67776c14f74ba0846_Traceguids,
                      "onecore\\base\\fs\\wci\\bindflt\\filter\\utils.c",uVar11,(char)uVar12);
LAB_140002186:
  BfFreeUnicodeString(param_4);
  return uVar8;
}



===== RtlUShortAdd @ 140002360 =====

uint RtlUShortAdd(ushort param_1,short param_2,ushort *param_3)

{
  ushort uVar1;
  ushort uVar2;
  
  uVar1 = param_2 + param_1;
  uVar2 = 0xffff;
  if (uVar1 >= param_1) {
    uVar2 = uVar1;
  }
  *param_3 = uVar2;
  return -(uint)(uVar1 < param_1) & 0xc0000095;
}



===== BfpDoesFileExistWithCrossVolumeECP @ 140002390 =====

ulonglong BfpDoesFileExistWithCrossVolumeECP
                    (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                    uint param_5)

{
  uint uVar1;
  ulonglong uVar2;
  longlong *local_res8;
  undefined8 local_res18 [2];
  undefined4 uVar3;
  undefined8 *puVar4;
  undefined4 uVar5;
  longlong local_b8;
  longlong local_b0 [6];
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  
  local_res18[0] = 0;
  local_80 = 0x30;
  puVar4 = &local_80;
  local_b0[2] = 0;
  local_68 = 0x240;
  local_50 = 0;
  uStack_48 = 0;
  local_res8 = (longlong *)0x0;
  local_b8 = 0;
  local_b0[0] = 0;
  local_b0[3] = 0;
  local_b0[4] = 0;
  local_b0[1] = 0x28;
  local_78 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_b0[5] = param_3;
  local_70 = param_1;
  uVar1 = FltCreateFileEx2(g_BindFltState,param_2,&local_b8,local_b0,0x80,puVar4,&local_50,0,0,7,1,
                           param_4,0,0,param_5 | 8,local_b0 + 1);
  uVar5 = (undefined4)((ulonglong)puVar4 >> 0x20);
  if (local_b8 != 0) {
    FltClose();
  }
  if (local_b0[0] != 0) {
    ObfDereferenceObject();
  }
  if (uVar1 == 0x8000002d) {
    return 0;
  }
  if (uVar1 + 0x3ffffc98 < 2) {
    uVar2 = FltAllocateExtraCreateParameterList(g_BindFltState,0,local_res18);
    if ((int)uVar2 < 0) {
      return uVar2;
    }
    uVar3 = 0;
    uVar2 = FltAllocateExtraCreateParameter
                      (g_BindFltState,&GUID_ECP_FLT_CREATEFILE_TARGET,0x20,0,0,
                       CONCAT44(uVar5,0x6d6e4642),&local_res8);
    if ((int)uVar2 < 0) {
      return uVar2;
    }
    *(undefined2 *)(local_res8 + 3) = 1;
    *local_res8 = 0;
    local_res8[1] = 0;
    local_res8[2] = 0;
    uVar2 = FltInsertExtraCreateParameter(g_BindFltState,local_res18[0],local_res8);
    if ((int)uVar2 < 0) {
      return uVar2;
    }
    local_b0[2] = local_res18[0];
    local_b0[3] = 0;
    local_b0[4] = 0;
    local_b0[1] = 0x28;
    local_80 = CONCAT44(local_80._4_4_,0x30);
    local_78 = 0;
    local_68 = CONCAT44(local_68._4_4_,0x240);
    local_60 = 0;
    uStack_58 = 0;
    local_b0[5] = param_3;
    local_70 = param_1;
    uVar1 = FltCreateFileEx2(g_BindFltState,param_2,&local_b8,local_b0,CONCAT44(uVar3,0x80),
                             &local_80,&local_50,0,0,7,1,0,0,0,0,local_b0 + 1);
    if (local_b8 != 0) {
      FltClose();
    }
    if (local_b0[0] != 0) {
      ObfDereferenceObject();
    }
    FltRemoveExtraCreateParameter
              (g_BindFltState,local_res18[0],&GUID_ECP_FLT_CREATEFILE_TARGET,&local_res8,0);
    if (*local_res8 != 0) {
      FltObjectDereference();
    }
    if (local_res8[1] != 0) {
      FltObjectDereference();
    }
    if (local_res8[2] != 0) {
      FltReleaseFileNameInformation();
    }
    FltFreeExtraCreateParameter(g_BindFltState,local_res8);
    FltFreeExtraCreateParameterList(g_BindFltState,local_res18[0]);
  }
  return (ulonglong)uVar1;
}



===== WPP_RECORDER_SF_sDD @ 140002700 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDD(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                        undefined8 param_5,char *param_6,undefined1 param_7,undefined1 param_8)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  
  uVar4 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar4 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar4 * 0x50 + 0x29])) {
    if (param_6 == (char *)0x0) {
      lVar2 = 5;
    }
    else {
      lVar3 = -1;
      do {
        lVar2 = lVar3;
        lVar3 = lVar2 + 1;
      } while (param_6[lVar3] != '\0');
      lVar2 = lVar2 + 2;
    }
    pcVar1 = param_6;
    if (param_6 == (char *)0x0) {
      pcVar1 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar4 * 0x50 + 0x18),0x2b,param_5,param_4,pcVar1
               ,lVar2,&param_7,4,&param_8,4,0);
  }
  lVar2 = -1;
  if (param_6 == (char *)0x0) {
    lVar3 = 5;
  }
  else {
    do {
      lVar3 = lVar2;
      lVar2 = lVar3 + 1;
    } while (param_6[lVar2] != '\0');
    lVar3 = lVar3 + 2;
  }
  if (param_6 == (char *)0x0) {
    param_6 = "NULL";
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,param_6,lVar3,&param_7,4,&param_8,4,0);
  return;
}



===== BfCreateFile @ 1400028d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong BfCreateFile(undefined8 param_1,longlong param_2,longlong param_3,undefined8 param_4,
                      byte param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8)

{
  char cVar1;
  longlong lVar2;
  bool bVar3;
  bool bVar4;
  uint uVar5;
  longlong lVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  undefined1 auStackY_1d8 [32];
  char local_158;
  char local_157;
  char local_156;
  undefined1 local_155;
  undefined1 local_154 [4];
  undefined4 local_150;
  undefined4 local_14c;
  uint local_148;
  uint local_144;
  uint local_140;
  uint local_13c;
  undefined4 local_138;
  undefined8 local_130;
  longlong alStack_128 [5];
  undefined8 local_100;
  undefined8 local_f8;
  undefined8 local_f0;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined8 local_e0;
  undefined8 local_d8;
  uint local_d0;
  undefined4 local_cc;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined4 local_b0;
  undefined1 local_a8 [12];
  undefined4 local_9c;
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStackY_1d8;
  local_f8 = param_7;
  local_100 = param_8;
  local_b8 = 0;
  local_e4 = 0;
  local_cc = 0;
  local_b0 = 0;
  local_9c = 0;
  local_f0 = param_4;
  memset(local_a8,0,0x44);
  cVar1 = *(char *)(param_2 + 0x50);
  local_154[0] = 0;
  local_155 = 0;
  local_150 = 2;
  bVar3 = false;
  local_156 = '\0';
  uVar5 = 0x200;
  local_157 = '\0';
  lVar6 = 0;
  local_158 = '\0';
  alStack_128[3] = 1;
  alStack_128[0] = 0;
  local_130 = 0x28;
  alStack_128[1] = 0;
  alStack_128[2] = 0;
  if ((cVar1 == '\x01') ||
     ((cVar1 == '\0' && ((*(byte *)(*(longlong *)(param_2 + 0x10) + 6) & 1) != 0)))) {
    uVar5 = 0x600;
  }
  lVar2 = *(longlong *)(param_2 + 0x10);
  local_e0 = 0;
  local_d0 = uVar5 | 0x40;
  if (*(char *)(lVar2 + 6) < '\0') {
    local_d0 = uVar5;
  }
  local_e8 = 0x30;
  local_c8 = *(undefined8 *)(*(longlong *)(*(longlong *)(lVar2 + 0x18) + 8) + 0x40);
  local_c0 = 0;
  local_138 = *(undefined4 *)(*(longlong *)(lVar2 + 0x18) + 0x10);
  local_13c = (uint)*(ushort *)(lVar2 + 0x28);
  local_140 = (uint)*(ushort *)(lVar2 + 0x2a);
  local_148 = *(uint *)(lVar2 + 0x20) & 0xffffff;
  local_144 = *(uint *)(lVar2 + 0x20) >> 0x18;
  alStack_128[4] = *(undefined8 *)(lVar2 + 0x38);
  local_14c = *(undefined4 *)(lVar2 + 0x30);
  local_d8 = param_1;
  if (cVar1 == '\0') {
    IoIsFileObjectIgnoringSharing(*(undefined8 *)(param_3 + 0x20));
  }
  bVar4 = false;
  if (*(char *)(param_2 + 0x50) == '\x01') {
    lVar6 = PsReferenceImpersonationToken(SystemReserved1[0xf],local_154,&local_155,&local_150);
    local_b8 = 0x20000000c;
    local_b0 = CONCAT22(local_b0._2_2_,1);
    uVar5 = SeCreateClientSecurityFromSubjectContext
                      (*(longlong *)(*(longlong *)(*(longlong *)(param_2 + 0x10) + 0x18) + 8) + 0x20
                       ,&local_b8,0,local_a8);
    uVar9 = (ulonglong)uVar5;
    if ((int)uVar5 < 0) goto LAB_140002bc2;
    uVar5 = SeImpersonateClientEx(local_a8,0);
    uVar9 = (ulonglong)uVar5;
    bVar4 = true;
    if ((int)uVar5 < 0) goto LAB_140002bc2;
  }
  bVar3 = bVar4;
  uVar5 = FltGetEcpListFromCallbackData(*(undefined8 *)(param_3 + 8),param_2,alStack_128);
  uVar9 = (ulonglong)uVar5;
  bVar4 = bVar3;
  if (-1 < (int)uVar5) {
    alStack_128[2] = IoGetTransactionParameterBlock(*(undefined8 *)(param_3 + 0x20));
    uVar7 = IoGetSilo(*(undefined8 *)(param_3 + 0x20));
    if ((param_5 & 4) == 0) {
      uVar7 = PsGetParentSilo(uVar7);
    }
    alStack_128[3] = uVar7;
    if ((param_5 & 0x20) != 0) {
      uVar8 = BfAddCloudFileECPs(param_2,param_3,(longlong)&local_130,&local_156,&local_157,
                                 &local_158);
      uVar9 = uVar8 & 0xffffffff;
      if ((int)uVar8 < 0) goto LAB_140002bc2;
    }
    uVar5 = FltCreateFileEx2(*(undefined8 *)(param_3 + 8),local_f0,local_f8,local_100);
    uVar9 = (ulonglong)uVar5;
  }
LAB_140002bc2:
  BfRemoveCloudFileECPs(param_3,alStack_128[0],local_156,local_157,local_158);
  if (bVar3) {
    PsRevertToSelf();
  }
  if (lVar6 != 0) {
    if (bVar3) {
      PsImpersonateClient(SystemReserved1[0xf],lVar6,local_154[0],local_155);
    }
    PsDereferenceImpersonationToken(lVar6);
  }
  if (bVar4) {
    SeDeleteClientSecurity(local_a8);
  }
  return uVar9;
}



===== RtlUShortSub @ 140002ce8 =====

uint RtlUShortSub(ushort param_1,ushort param_2,short *param_3)

{
  short sVar1;
  
  if (param_1 < param_2) {
    sVar1 = -1;
  }
  else {
    sVar1 = param_1 - param_2;
  }
  *param_3 = sVar1;
  return -(uint)(param_1 < param_2) & 0xc0000095;
}



===== BfInitShadowFileHandleContext @ 140002d14 =====

ulonglong BfInitShadowFileHandleContext
                    (undefined8 param_1,undefined8 param_2,longlong param_3,longlong *param_4,
                    short *param_5,longlong param_6,undefined8 param_7,undefined8 *param_8)

{
  undefined8 *puVar1;
  uint uVar2;
  ulonglong uVar3;
  
  uVar3 = 0;
  puVar1 = (undefined8 *)*param_8;
  if ((*(uint *)(puVar1 + 10) & 1) != 0) {
    return 0;
  }
  if (*param_5 != 0) {
    uVar3 = BfAllocateUnicodeString(*param_5,(undefined4 *)(puVar1 + 8));
    if ((int)uVar3 < 0) {
      return uVar3 & 0xffffffff;
    }
    uVar2 = RtlAppendUnicodeStringToString(puVar1 + 8,param_5);
    uVar3 = (ulonglong)uVar2;
    if ((int)uVar2 < 0) {
      return uVar3;
    }
  }
  puVar1[0xf] = param_7;
  BfInitFsContext2(param_1,param_2,param_3,param_6,param_4,puVar1);
  *(uint *)(puVar1 + 10) = *(uint *)(puVar1 + 10) | 1;
  return uVar3;
}



===== WPP_RECORDER_SF_sDZd @ 140002de0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDZd
               (undefined8 param_1,byte param_2,ulonglong param_3,undefined2 param_4,
               undefined8 param_5,char *param_6,undefined1 param_7,wchar_t *param_8,
               undefined1 param_9)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  wchar_t *pwVar4;
  wchar_t wVar5;
  wchar_t wVar6;
  wchar_t *pwVar7;
  uint uVar8;
  wchar_t *pwVar9;
  wchar_t *pwVar10;
  ulonglong uVar11;
  
  pwVar4 = param_8;
  uVar8 = (int)param_3 - 1;
  pwVar10 = L"NULL";
  uVar11 = (param_3 & 0xffffffff) >> 0x10;
  wVar5 = L'\b';
  if (((*(uint *)(WPP_GLOBAL_Control + ((ulonglong)(uVar8 >> 5 & 0x7ff) + uVar11 * 0x14) * 4 + 0x2c)
        >> (uVar8 & 0x1f) & 1) == 0) || ((byte)WPP_GLOBAL_Control[uVar11 * 0x50 + 0x29] < param_2))
  goto LAB_140002f79;
  if (param_8 == (wchar_t *)0x0) {
    wVar6 = L'\b';
LAB_140002e9e:
    pwVar9 = L"NULL";
  }
  else {
    wVar6 = *param_8;
    if (*param_8 == L'\0') goto LAB_140002e9e;
    pwVar9 = *(wchar_t **)(param_8 + 4);
  }
  pwVar7 = param_8;
  if (param_8 == (wchar_t *)0x0) {
    pwVar7 = L"\b";
  }
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
  pcVar1 = param_6;
  if (param_6 == (char *)0x0) {
    pcVar1 = "NULL";
  }
  (*pfnWppTraceMessage)
            (*(undefined8 *)(WPP_GLOBAL_Control + uVar11 * 0x50 + 0x18),0x2b,param_5,param_4,pcVar1,
             lVar3,&param_7,4,pwVar7,2,pwVar9,wVar6,&param_9,4,0);
  param_3 = param_3 & 0xffffffff;
LAB_140002f79:
  if ((pwVar4 != (wchar_t *)0x0) && (wVar5 = *pwVar4, *pwVar4 != L'\0')) {
    pwVar10 = *(wchar_t **)(pwVar4 + 4);
  }
  if (pwVar4 == (wchar_t *)0x0) {
    pwVar4 = L"\b";
  }
  lVar3 = -1;
  if (param_6 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    do {
      lVar2 = lVar3;
      lVar3 = lVar2 + 1;
    } while (param_6[lVar3] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (param_6 == (char *)0x0) {
    param_6 = "NULL";
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,param_6,lVar2,&param_7,4,pwVar4,2,pwVar10,
                  wVar5,&param_9,4,0);
  return;
}



===== BfInitializeSiloContext @ 14000304c =====

void BfInitializeSiloContext(undefined8 param_1,undefined8 *param_2)

{
  param_2[1] = 0;
  *param_2 = param_1;
  BfInitializeMappingContext(param_2 + 1);
  return;
}



===== BfInitializeMappingContext @ 140003070 =====

undefined8 BfInitializeMappingContext(longlong *param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  
  lVar1 = ExAllocatePool2(0x40,0x78,0x636d4642);
  if (lVar1 == 0) {
    uVar2 = 0xc000009a;
  }
  else {
    *(longlong *)(lVar1 + 8) = lVar1;
    *(longlong *)lVar1 = lVar1;
    ExInitializeResourceLite(lVar1 + 0x10);
    uVar2 = 0;
    *param_1 = lVar1;
  }
  return uVar2;
}



===== BfpDoMappingFlagsMatch @ 1400030d4 =====

bool BfpDoMappingFlagsMatch(uint param_1,uint param_2)

{
  return ((param_1 ^ param_2) & 0xdfffffff) == 0;
}



===== BfCleanupMappingContext @ 1400030e8 =====

void BfCleanupMappingContext(longlong *param_1)

{
  BfClearMappingTable(param_1);
  ExDeleteResourceLite(param_1 + 2);
  return;
}



===== WPP_RECORDER_SF_sDdd @ 140003114 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDdd
               (undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,undefined8 param_5,
               char *param_6,undefined1 param_7,undefined1 param_8,undefined1 param_9)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  
  uVar4 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar4 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar4 * 0x50 + 0x29])) {
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
    pcVar1 = param_6;
    if (param_6 == (char *)0x0) {
      pcVar1 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar4 * 0x50 + 0x18),0x2b,param_5,param_4,pcVar1
               ,lVar3,&param_7,4,&param_8,4,&param_9,4,0);
  }
  lVar3 = -1;
  if (param_6 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    do {
      lVar2 = lVar3;
      lVar3 = lVar2 + 1;
    } while (param_6[lVar3] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (param_6 == (char *)0x0) {
    param_6 = "NULL";
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,param_6,lVar2,&param_7,4,&param_8,4,
                  &param_9,4,0);
  return;
}



===== WPP_RECORDER_SF_sD @ 1400032ec =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sD(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                       undefined8 param_5,char *param_6,undefined1 param_7)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  
  uVar4 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar4 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar4 * 0x50 + 0x29])) {
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
    pcVar1 = param_6;
    if (param_6 == (char *)0x0) {
      pcVar1 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar4 * 0x50 + 0x18),0x2b,param_5,param_4,pcVar1
               ,lVar3,&param_7,4,0);
  }
  lVar3 = -1;
  if (param_6 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    do {
      lVar2 = lVar3;
      lVar3 = lVar2 + 1;
    } while (param_6[lVar3] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (param_6 == (char *)0x0) {
    param_6 = "NULL";
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,param_6,lVar2,&param_7,4,0);
  return;
}



===== __report_gsfailure @ 140003480 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== __C_specific_handler @ 14000348d =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00014000348d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== McGenEventWrite_EtwWriteTransfer @ 1400034a0 =====

void McGenEventWrite_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined8 *param_5)

{
  ushort *puVar1;
  undefined4 uVar2;
  uint uVar3;
  
  puVar1 = DAT_14000d008;
  uVar2 = 0;
  if (DAT_14000d008 == (ushort *)0x0) {
    *param_5 = 0;
    uVar3 = 0;
  }
  else {
    *param_5 = DAT_14000d008;
    uVar2 = 2;
    uVar3 = (uint)*puVar1;
  }
  *(uint *)(param_5 + 1) = uVar3;
  *(undefined4 *)((longlong)param_5 + 0xc) = uVar2;
  EtwWriteTransfer(PROV_BINDFLT_Context,param_2,0,0,param_4,param_5);
  return;
}



===== McTemplateK0dhzr1_EtwWriteTransfer @ 140003504 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0dhzr1_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               ushort param_5,undefined8 param_6)

{
  undefined4 local_res20 [2];
  undefined1 auStackY_88 [32];
  undefined8 local_58 [2];
  undefined4 *local_48;
  undefined8 local_40;
  ushort *local_38;
  undefined8 local_30;
  undefined8 local_28;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  local_48 = local_res20;
  local_30 = 2;
  local_38 = &param_5;
  local_28 = param_6;
  local_20 = (uint)param_5 * 2;
  local_40 = 4;
  local_1c = 0;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(0,&BindFltInstanceAttachFailure,param_3,4,local_58);
  return;
}



===== WPP_RECORDER_SF_sDsZZZd @ 14000358c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDsZZZd(undefined8 param_1)

{
  wchar_t *pwVar1;
  char *pcVar2;
  wchar_t wVar3;
  wchar_t wVar4;
  wchar_t *pwVar5;
  wchar_t *pwVar6;
  longlong lVar7;
  longlong lVar8;
  wchar_t wVar9;
  wchar_t wVar10;
  wchar_t *pwVar11;
  wchar_t *pwVar12;
  wchar_t *pwVar13;
  char *pcVar14;
  wchar_t *pwStack0000000000000030;
  wchar_t *in_stack_00000040;
  wchar_t *in_stack_00000048;
  wchar_t *in_stack_00000050;
  wchar_t *in_stack_00000058;
  undefined4 local_38 [2];
  undefined4 local_30 [2];
  
  pwVar5 = in_stack_00000048;
  pcVar14 = (char *)in_stack_00000040;
  pwVar12 = L"NULL";
  local_38[0] = 0xc0000278;
  local_30[0] = 0x6a2;
  wVar4 = L'\b';
  pwStack0000000000000030 = L"\b";
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) && (2 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    if (in_stack_00000058 == (wchar_t *)0x0) {
      wVar3 = L'\b';
LAB_14000363c:
      in_stack_00000040 = L"NULL";
    }
    else {
      wVar3 = *in_stack_00000058;
      if (*in_stack_00000058 == L'\0') goto LAB_14000363c;
      in_stack_00000040 = *(wchar_t **)(in_stack_00000058 + 4);
    }
    pwVar1 = in_stack_00000058;
    if (in_stack_00000058 == (wchar_t *)0x0) {
      pwVar1 = L"\b";
    }
    if (in_stack_00000050 == (wchar_t *)0x0) {
      wVar9 = L'\b';
LAB_140003676:
      in_stack_00000048 = L"NULL";
    }
    else {
      wVar9 = *in_stack_00000050;
      if (*in_stack_00000050 == L'\0') goto LAB_140003676;
      in_stack_00000048 = *(wchar_t **)(in_stack_00000050 + 4);
    }
    pwVar6 = in_stack_00000050;
    if (in_stack_00000050 == (wchar_t *)0x0) {
      pwVar6 = L"\b";
    }
    if (pwVar5 == (wchar_t *)0x0) {
      wVar10 = L'\b';
LAB_1400036af:
      pwVar13 = L"NULL";
    }
    else {
      wVar10 = *pwVar5;
      if (*pwVar5 == L'\0') goto LAB_1400036af;
      pwVar13 = *(wchar_t **)(pwVar5 + 4);
    }
    pwVar11 = pwVar5;
    if (pwVar5 == (wchar_t *)0x0) {
      pwVar11 = L"\b";
    }
    if (pcVar14 == (char *)0x0) {
      lVar8 = 5;
    }
    else {
      lVar7 = -1;
      do {
        lVar8 = lVar7;
        lVar7 = lVar8 + 1;
      } while (pcVar14[lVar7] != '\0');
      lVar8 = lVar8 + 2;
    }
    pcVar2 = pcVar14;
    if (pcVar14 == (char *)0x0) {
      pcVar2 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_48a527b79fd4344d8b4157379f595642_Traceguids,0x1e,
               "onecore\\base\\fs\\wci\\bindflt\\filter\\create.c",0x2c,local_30,4,pcVar2,lVar8,
               pwVar11,2,pwVar13,wVar10,pwVar6,2,in_stack_00000048,wVar9,pwVar1,2,in_stack_00000040,
               wVar3,local_38,4,0);
  }
  if (in_stack_00000058 == (wchar_t *)0x0) {
    wVar3 = L'\b';
LAB_14000380d:
    pwVar1 = L"NULL";
  }
  else {
    wVar3 = *in_stack_00000058;
    if (*in_stack_00000058 == L'\0') goto LAB_14000380d;
    pwVar1 = *(wchar_t **)(in_stack_00000058 + 4);
  }
  if (in_stack_00000058 == (wchar_t *)0x0) {
    in_stack_00000058 = L"\b";
  }
  if (in_stack_00000050 == (wchar_t *)0x0) {
    wVar9 = L'\b';
  }
  else {
    wVar9 = *in_stack_00000050;
    if (*in_stack_00000050 != L'\0') {
      pwVar6 = *(wchar_t **)(in_stack_00000050 + 4);
      goto LAB_140003831;
    }
  }
  pwVar6 = L"NULL";
LAB_140003831:
  if (in_stack_00000050 == (wchar_t *)0x0) {
    in_stack_00000050 = pwStack0000000000000030;
  }
  if ((pwVar5 != (wchar_t *)0x0) && (wVar4 = *pwVar5, *pwVar5 != L'\0')) {
    pwVar12 = *(wchar_t **)(pwVar5 + 4);
  }
  if (pwVar5 == (wchar_t *)0x0) {
    pwVar5 = L"\b";
  }
  lVar8 = -1;
  if (pcVar14 == (char *)0x0) {
    lVar7 = 5;
  }
  else {
    do {
      lVar7 = lVar8;
      lVar8 = lVar7 + 1;
    } while (pcVar14[lVar8] != '\0');
    lVar7 = lVar7 + 2;
  }
  if (pcVar14 == (char *)0x0) {
    pcVar14 = "NULL";
  }
  WppAutoLogTrace(param_1,3,5,&WPP_48a527b79fd4344d8b4157379f595642_Traceguids,0x1e,
                  "onecore\\base\\fs\\wci\\bindflt\\filter\\create.c",0x2c,local_30,4,pcVar14,lVar7,
                  pwVar5,2,pwVar12,wVar4,in_stack_00000050,2,pwVar6,wVar9,in_stack_00000058,2,pwVar1
                  ,wVar3,local_38,4,0);
  return;
}



===== Feature_4063646010__private_IsEnabledDeviceUsageNoInline @ 140003980 =====

ulonglong Feature_4063646010__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_4063646010__private_featureState;
  if ((Feature_4063646010__private_featureState & 0x10) == 0) {
    uVar1 = Feature_4063646010__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_4063646010__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_4063646010__private_IsEnabledFallback @ 1400039b8 =====

void Feature_4063646010__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_4063646010__private_descriptor);
  return;
}



===== wil_details_FeatureReporting_IncrementOpportunityInCache @ 1400039d4 =====

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



===== wil_details_FeatureReporting_IncrementUsageInCache @ 140003aac =====

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



===== wil_details_FeatureReporting_RecordUsageInCache @ 140003b90 =====

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
LAB_140003ce8:
    wil_details_FeatureReporting_IncrementUsageInCache(param_2,uVar5,param_3,param_1);
  }
  else {
    if (uVar5 == 1) {
LAB_140003cdb:
      wil_details_FeatureReporting_IncrementOpportunityInCache(param_2,uVar5,param_3,param_1);
      return param_1;
    }
    if ((uVar5 != 2) && (uVar5 != 3)) {
      if (uVar5 == 4) goto LAB_140003ce8;
      if (uVar5 == 5) goto LAB_140003cdb;
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



===== wil_details_FeatureReporting_ReportUsageToService @ 140003d10 =====

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



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 140003d94 =====

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



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 140003e84 =====

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



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 140003f94 =====

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



===== wil_details_GetCurrentFeatureEnabledState @ 140003ff8 =====

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



===== wil_details_IsEnabledFallback @ 140004158 =====

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



===== wil_details_MapReportingKind @ 1400041ec =====

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



===== Feature_2535612730__private_IsEnabledDeviceUsageNoInline @ 14000428c =====

ulonglong Feature_2535612730__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_2535612730__private_featureState;
  if ((Feature_2535612730__private_featureState & 0x10) == 0) {
    uVar1 = Feature_2535612730__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_2535612730__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_2535612730__private_IsEnabledFallback @ 1400042c4 =====

void Feature_2535612730__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_2535612730__private_descriptor);
  return;
}



===== BfpSetMappingNodeForTracking @ 1400042e0 =====

undefined8 BfpSetMappingNodeForTracking(undefined8 param_1,longlong param_2,undefined8 param_3)

{
  uint *puVar1;
  
  puVar1 = (uint *)(*(longlong *)(param_2 + 0x40) + 8);
  *puVar1 = *puVar1 | 0x10000000;
  *(undefined8 *)(*(longlong *)(param_2 + 0x40) + 0x38) = param_3;
  return 0;
}



===== BfpShouldVetoBinding @ 1400042fc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int BfpShouldVetoBinding(longlong param_1,undefined2 param_2,char param_3)

{
  char cVar1;
  int iVar2;
  ulonglong uVar3;
  undefined1 auStack_178 [32];
  undefined1 *local_158;
  undefined4 local_150;
  char **local_148;
  undefined8 *local_140;
  char *local_138;
  longlong local_130;
  longlong local_128;
  longlong local_120;
  longlong local_118;
  undefined2 local_110;
  undefined2 local_10e;
  undefined4 local_10c;
  undefined8 local_108;
  undefined8 local_100;
  longlong lStack_f8;
  undefined8 local_f0;
  undefined8 uStack_e8;
  ulonglong local_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  longlong local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  ulonglong uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined1 local_98 [112];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_178;
  local_120 = 0;
  local_10c = 0;
  local_128 = 0;
  local_138 = (char *)0x0;
  local_e0 = local_e0 & 0xffffffffffff0000;
  local_130 = 0;
  local_118 = 0;
  local_100 = 0;
  lStack_f8 = 0;
  local_b8 = 0;
  local_f0 = 0;
  uStack_e8 = 0;
  uStack_b0 = uStack_b0 & 0xffffffff00000000;
  local_d8 = 0;
  uStack_d0 = 0;
  local_c8 = 0;
  uStack_c0 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  memset(local_98,0,0x68);
  local_108 = *(undefined8 *)(param_1 + 8);
  local_110 = param_2;
  local_10e = param_2;
  iVar2 = FltGetVolumeFromName(g_BindFltState,&local_110,&local_130);
  if (-1 < iVar2) {
    iVar2 = FltGetDiskDeviceObject(local_130,&local_120);
    if (-1 < iVar2) {
      if ((*(uint *)(local_120 + 0x30) & 0x100) != 0) {
        iVar2 = FltAllocateExtraCreateParameterList(g_BindFltState,0,&local_128);
        if (iVar2 < 0) goto LAB_140004599;
        local_148 = &local_138;
        local_150 = 0x63654642;
        local_158 = (undefined1 *)0x0;
        iVar2 = FltAllocateExtraCreateParameter(g_BindFltState,&GUID_ECP_TYPE_VETO_BINDING,1);
        if (iVar2 < 0) goto LAB_140004599;
        *local_138 = '\0';
        iVar2 = FltInsertExtraCreateParameter(g_BindFltState,local_128,local_138);
        if (iVar2 < 0) goto LAB_140004599;
        lStack_f8 = local_128;
        local_100 = 0x28;
        local_f0 = 0;
        uStack_e8 = 0;
        local_e0 = 1;
        iVar2 = FltGetVolumeInstanceFromName(g_BindFltState,local_130,0,&local_118);
        if (iVar2 < 0) goto LAB_140004599;
        local_140 = &local_100;
        local_148 = (char **)CONCAT44(local_148._4_4_,0x4d);
        local_158 = local_98;
        local_150 = 0x68;
        local_d8 = CONCAT44(local_d8._4_4_,0x30);
        uStack_d0 = 0;
        uStack_c0 = CONCAT44(uStack_c0._4_4_,0x200);
        local_b8 = 0;
        uStack_b0 = 0;
        local_c8 = param_1;
        iVar2 = FltQueryInformationByName(g_BindFltState,local_118,&local_d8,&local_a8);
        uVar3 = Feature_AnchorlessBindingVeto__private_IsEnabledDeviceUsageNoInline();
        if ((((int)uVar3 == 0) || (param_3 == '\0')) ||
           ((iVar2 != -0x3fffffcc && (iVar2 != -0x3fffffc6)))) {
          if (iVar2 < 0) goto LAB_140004599;
        }
        else {
          iVar2 = 0;
        }
        cVar1 = FltIsEcpAcknowledged(g_BindFltState,local_138);
        if (cVar1 != '\0') {
          if (*local_138 != '\0') {
            iVar2 = -0x3fffffde;
          }
          goto LAB_140004599;
        }
      }
      iVar2 = 0;
    }
  }
LAB_140004599:
  if (local_130 != 0) {
    FltObjectDereference();
  }
  if (local_120 != 0) {
    ObfDereferenceObject();
  }
  if (local_128 != 0) {
    FltFreeExtraCreateParameterList(g_BindFltState);
  }
  if (local_118 != 0) {
    FltObjectDereference();
  }
  return iVar2;
}



===== Feature_2657777978__private_IsEnabledDeviceUsageNoInline @ 140004628 =====

ulonglong Feature_2657777978__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_2657777978__private_featureState;
  if ((Feature_2657777978__private_featureState & 0x10) == 0) {
    uVar1 = Feature_2657777978__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_2657777978__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_2657777978__private_IsEnabledFallback @ 140004660 =====

void Feature_2657777978__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_2657777978__private_descriptor);
  return;
}



===== Feature_AnchorlessBindingVeto__private_IsEnabledDeviceUsageNoInline @ 14000467c =====

ulonglong Feature_AnchorlessBindingVeto__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_AnchorlessBindingVeto__private_featureState;
  if ((Feature_AnchorlessBindingVeto__private_featureState & 0x10) == 0) {
    uVar1 = Feature_AnchorlessBindingVeto__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_AnchorlessBindingVeto__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_AnchorlessBindingVeto__private_IsEnabledFallback @ 1400046b4 =====

void Feature_AnchorlessBindingVeto__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_AnchorlessBindingVeto__private_descriptor);
  return;
}



===== WPP_RECORDER_SF_sDDD @ 1400046d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDDD
               (undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
               undefined8 param_5,undefined8 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,
               &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,param_4,
               "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",0x2d,&param_7,4,&param_8,4,
               &param_9,4,0);
  }
  WppAutoLogTrace(param_1,2,param_3,&WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,param_4,
                  "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",0x2d,&param_7,4,&param_8,4,
                  &param_9,4,0);
  return;
}



===== WPP_RECORDER_SF_sDL @ 140004840 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDL(undefined8 param_1)

{
  undefined1 uStack0000000000000040;
  undefined4 local_18 [4];
  
  local_18[0] = 0x308;
  if (((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0') &&
     (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,0x11,
               "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",0x2d,local_18,4,
               &uStack0000000000000040,4,0);
  }
  WppAutoLogTrace(param_1,2,8,&WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,0x11,
                  "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",0x2d,local_18,4,
                  &uStack0000000000000040,4,0);
  return;
}



===== WPP_RECORDER_SF_sDZ @ 140004940 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDZ(undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
                        undefined8 param_5,undefined8 param_6,undefined1 param_7,wchar_t *param_8)

{
  wchar_t *pwVar1;
  wchar_t wVar2;
  wchar_t *pwVar3;
  wchar_t *pwVar4;
  wchar_t wVar5;
  wchar_t *pwVar6;
  ulonglong uVar7;
  
  pwVar3 = param_8;
  pwVar4 = L"NULL";
  uVar7 = (ulonglong)(param_3 >> 0x10);
  wVar5 = L'\b';
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar7 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) == 0) || ((byte)WPP_GLOBAL_Control[uVar7 * 0x50 + 0x29] < 2))
  goto LAB_140004a71;
  if (param_8 == (wchar_t *)0x0) {
    wVar2 = L'\b';
LAB_1400049ee:
    pwVar6 = L"NULL";
  }
  else {
    wVar2 = *param_8;
    if (*param_8 == L'\0') goto LAB_1400049ee;
    pwVar6 = *(wchar_t **)(param_8 + 4);
  }
  pwVar1 = param_8;
  if (param_8 == (wchar_t *)0x0) {
    pwVar1 = L"\b";
  }
  (*pfnWppTraceMessage)
            (*(undefined8 *)(WPP_GLOBAL_Control + uVar7 * 0x50 + 0x18),0x2b,
             &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,param_4,
             "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",0x2d,&param_7,4,pwVar1,2,pwVar6,
             wVar2,0);
LAB_140004a71:
  if ((pwVar3 != (wchar_t *)0x0) && (wVar5 = *pwVar3, *pwVar3 != L'\0')) {
    pwVar4 = *(wchar_t **)(pwVar3 + 4);
  }
  if (pwVar3 == (wchar_t *)0x0) {
    pwVar3 = L"\b";
  }
  WppAutoLogTrace(param_1,2,param_3,&WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,param_4,
                  "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",0x2d,&param_7,4,pwVar3,2,
                  pwVar4,wVar5,0);
  return;
}



===== WPP_RECORDER_SF_sDZZ @ 140004b14 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDZZ
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,undefined8 param_6,undefined1 param_7,wchar_t *param_8,
               wchar_t *param_9)

{
  wchar_t wVar1;
  wchar_t *pwVar2;
  wchar_t *pwVar3;
  wchar_t *pwVar4;
  wchar_t *pwVar5;
  wchar_t wVar6;
  wchar_t *pwVar7;
  wchar_t *pwVar8;
  wchar_t *pwVar9;
  
  pwVar3 = param_9;
  pwVar5 = param_8;
  pwVar4 = L"NULL";
  if (((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0') &&
     (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    if (param_9 == (wchar_t *)0x0) {
      wVar1 = L'\b';
LAB_140004b9f:
      pwVar7 = L"NULL";
    }
    else {
      wVar1 = *param_9;
      if (*param_9 == L'\0') goto LAB_140004b9f;
      pwVar7 = *(wchar_t **)(param_9 + 4);
    }
    pwVar8 = param_9;
    if (param_9 == (wchar_t *)0x0) {
      pwVar8 = L"\b";
    }
    if (param_8 == (wchar_t *)0x0) {
      wVar6 = L'\b';
LAB_140004bc4:
      pwVar9 = L"NULL";
    }
    else {
      wVar6 = *param_8;
      if (*param_8 == L'\0') goto LAB_140004bc4;
      pwVar9 = *(wchar_t **)(param_8 + 4);
    }
    pwVar2 = param_8;
    if (param_8 == (wchar_t *)0x0) {
      pwVar2 = L"\b";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,param_4,
               "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",0x2d,&param_7,4,pwVar2,2,pwVar9,
               wVar6,pwVar8,2,pwVar7,wVar1,0);
  }
  if (pwVar3 == (wchar_t *)0x0) {
    wVar1 = L'\b';
  }
  else {
    wVar1 = *pwVar3;
    if (*pwVar3 != L'\0') {
      pwVar7 = *(wchar_t **)(pwVar3 + 4);
      goto LAB_140004c7d;
    }
  }
  pwVar7 = L"NULL";
LAB_140004c7d:
  if (pwVar3 == (wchar_t *)0x0) {
    pwVar3 = L"\b";
  }
  if (pwVar5 == (wchar_t *)0x0) {
    wVar6 = L'\b';
  }
  else {
    wVar6 = *pwVar5;
    if (*pwVar5 != L'\0') {
      pwVar4 = *(wchar_t **)(pwVar5 + 4);
    }
  }
  if (pwVar5 == (wchar_t *)0x0) {
    pwVar5 = L"\b";
  }
  WppAutoLogTrace(param_1,2,8,&WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,param_4,
                  "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",0x2d,&param_7,4,pwVar5,2,
                  pwVar4,wVar6,pwVar3,2,pwVar7,wVar1,0);
  return;
}



===== WPP_RECORDER_SF_sDsd @ 140004d44 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDsd(undefined8 param_1)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  char *in_stack_00000040;
  undefined1 uStack0000000000000048;
  undefined4 local_18 [4];
  
  local_18[0] = 0x306;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    if (in_stack_00000040 == (char *)0x0) {
      lVar3 = 5;
    }
    else {
      lVar2 = -1;
      do {
        lVar3 = lVar2;
        lVar2 = lVar3 + 1;
      } while (in_stack_00000040[lVar2] != '\0');
      lVar3 = lVar3 + 2;
    }
    pcVar1 = in_stack_00000040;
    if (in_stack_00000040 == (char *)0x0) {
      pcVar1 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_c7f51acdbd3738713a5b9ea834ad885a_Traceguids,0x1f,
               "onecore\\base\\fs\\wci\\bindflt\\filter\\namesup.c",0x2d,local_18,4,pcVar1,lVar3,
               &uStack0000000000000048,4,0);
  }
  lVar3 = -1;
  if (in_stack_00000040 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    do {
      lVar2 = lVar3;
      lVar3 = lVar2 + 1;
    } while (in_stack_00000040[lVar3] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (in_stack_00000040 == (char *)0x0) {
    in_stack_00000040 = "NULL";
  }
  WppAutoLogTrace(param_1,2,9,&WPP_c7f51acdbd3738713a5b9ea834ad885a_Traceguids,0x1f,
                  "onecore\\base\\fs\\wci\\bindflt\\filter\\namesup.c",0x2d,local_18,4,
                  in_stack_00000040,lVar2,&uStack0000000000000048,4,0);
  return;
}



===== WPP_RECORDER_SF_sDZZd @ 140004ee8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDZZd(undefined8 param_1)

{
  wchar_t wVar1;
  wchar_t *pwVar2;
  wchar_t *pwVar3;
  wchar_t wVar4;
  wchar_t *pwVar5;
  wchar_t *pwVar6;
  wchar_t *pwVar7;
  wchar_t *in_stack_00000040;
  wchar_t *in_stack_00000048;
  undefined1 uStack0000000000000050;
  undefined4 local_38 [4];
  
  pwVar3 = L"NULL";
  local_38[0] = 0x6c7;
  if (((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0') &&
     (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    if (in_stack_00000048 == (wchar_t *)0x0) {
      wVar1 = L'\b';
LAB_140004f7a:
      pwVar5 = L"NULL";
    }
    else {
      wVar1 = *in_stack_00000048;
      if (*in_stack_00000048 == L'\0') goto LAB_140004f7a;
      pwVar5 = *(wchar_t **)(in_stack_00000048 + 4);
    }
    pwVar6 = in_stack_00000048;
    if (in_stack_00000048 == (wchar_t *)0x0) {
      pwVar6 = L"\b";
    }
    if (in_stack_00000040 == (wchar_t *)0x0) {
      wVar4 = L'\b';
LAB_140004f9f:
      pwVar7 = L"NULL";
    }
    else {
      wVar4 = *in_stack_00000040;
      if (*in_stack_00000040 == L'\0') goto LAB_140004f9f;
      pwVar7 = *(wchar_t **)(in_stack_00000040 + 4);
    }
    pwVar2 = in_stack_00000040;
    if (in_stack_00000040 == (wchar_t *)0x0) {
      pwVar2 = L"\b";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_529f93b0825532f67776c14f74ba0846_Traceguids,0x24,
               "onecore\\base\\fs\\wci\\bindflt\\filter\\utils.c",0x2b,local_38,4,pwVar2,2,pwVar7,
               wVar4,pwVar6,2,pwVar5,wVar1,&uStack0000000000000050,4,0);
  }
  if (in_stack_00000048 == (wchar_t *)0x0) {
    wVar1 = L'\b';
  }
  else {
    wVar1 = *in_stack_00000048;
    if (*in_stack_00000048 != L'\0') {
      pwVar5 = *(wchar_t **)(in_stack_00000048 + 4);
      goto LAB_14000506e;
    }
  }
  pwVar5 = L"NULL";
LAB_14000506e:
  if (in_stack_00000048 == (wchar_t *)0x0) {
    in_stack_00000048 = L"\b";
  }
  if (in_stack_00000040 == (wchar_t *)0x0) {
    wVar4 = L'\b';
  }
  else {
    wVar4 = *in_stack_00000040;
    if (*in_stack_00000040 != L'\0') {
      pwVar3 = *(wchar_t **)(in_stack_00000040 + 4);
    }
  }
  if (in_stack_00000040 == (wchar_t *)0x0) {
    in_stack_00000040 = L"\b";
  }
  WppAutoLogTrace(param_1,2,8,&WPP_529f93b0825532f67776c14f74ba0846_Traceguids,0x24,
                  "onecore\\base\\fs\\wci\\bindflt\\filter\\utils.c",0x2b,local_38,4,
                  in_stack_00000040,2,pwVar3,wVar4,in_stack_00000048,2,pwVar5,wVar1,
                  &uStack0000000000000050,4,0);
  return;
}



===== Feature_Servicing_BindfltUnloadDisabled__private_IsEnabledDeviceUsageNoInline @ 140005150 =====

ulonglong Feature_Servicing_BindfltUnloadDisabled__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_Servicing_BindfltUnloadDisabled__private_featureState;
  if ((Feature_Servicing_BindfltUnloadDisabled__private_featureState & 0x10) == 0) {
    uVar1 = Feature_Servicing_BindfltUnloadDisabled__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_Servicing_BindfltUnloadDisabled__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_Servicing_BindfltUnloadDisabled__private_IsEnabledFallback @ 140005188 =====

void Feature_Servicing_BindfltUnloadDisabled__private_IsEnabledFallback
               (ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback
            (param_1,param_2,&Feature_Servicing_BindfltUnloadDisabled__private_descriptor);
  return;
}



===== McGenControlCallbackV2 @ 1400051b0 =====

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



===== McGenEventRegister_EtwRegister @ 1400052c0 =====

void McGenEventRegister_EtwRegister(void)

{
  if (PROV_BINDFLT_Context == 0) {
    EtwRegister(&PROV_BINDFLT,McGenControlCallbackV2,&PROV_BINDFLT_Context,&PROV_BINDFLT_Context);
  }
  return;
}



===== McGenEventUnregister_EtwUnregister @ 140005300 =====

undefined8 McGenEventUnregister_EtwUnregister(void)

{
  undefined8 uVar1;
  
  if (PROV_BINDFLT_Context == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = EtwUnregister();
    PROV_BINDFLT_Context = 0;
  }
  return uVar1;
}



===== McTemplateK0_EtwWriteTransfer @ 140005334 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0_EtwWriteTransfer(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 auStackY_58 [32];
  undefined8 local_28 [2];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_58;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,param_3,1,local_28);
  return;
}



===== McTemplateK0d_EtwWriteTransfer @ 140005378 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0d_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  undefined1 auStackY_68 [32];
  undefined8 local_38 [2];
  undefined4 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  local_28 = local_res20;
  local_1c = 0;
  local_20 = 4;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&BindFltDriverEntryFailure,param_3,2,local_38);
  return;
}



===== wil_details_FeatureDescriptors_SkipPadding @ 1400053dc =====

longlong * wil_details_FeatureDescriptors_SkipPadding(longlong *param_1)

{
  while( true ) {
    if (&UNK_14000c06f < param_1) {
      return (longlong *)0x0;
    }
    if (*param_1 != 0) break;
    param_1 = param_1 + 1;
  }
  return param_1;
}



===== wil_details_RecordCachedUsage @ 140005404 =====

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



===== wil_details_RecordFeatureUsageReporting @ 140005560 =====

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



===== WppClassicProviderCallback @ 1400055f0 =====

void WppClassicProviderCallback
               (undefined8 param_1,byte param_2,undefined8 *param_3,longlong param_4)

{
  undefined8 uVar1;
  
  if (param_2 < 2) {
    if (param_2 == 0) {
      *(undefined1 *)(param_4 + 0x29) = 0;
      *(undefined4 *)(param_4 + 0x2c) = 0;
      *(undefined8 *)(param_4 + 0x18) = 0;
    }
    else {
      *(undefined4 *)(param_4 + 0x2c) = *(undefined4 *)((longlong)param_3 + 4);
      *(undefined1 *)(param_4 + 0x29) = *(undefined1 *)((longlong)param_3 + 2);
      uVar1 = *param_3;
      *(undefined8 *)(param_4 + 0x18) = uVar1;
      imp_WppRecorderReplay
                (WPP_GLOBAL_Control,uVar1,*(undefined4 *)((longlong)param_3 + 4),
                 *(undefined1 *)((longlong)param_3 + 2));
    }
  }
  return;
}



===== _tlgDefineProvider_annotation__TlgBindFltTelemetryProviderProv @ 14000564c =====

void _tlgDefineProvider_annotation__TlgBindFltTelemetryProviderProv(void)

{
  return;
}



===== Feature_ProbeForReadProcessParameters__private_IsEnabledDeviceUsageNoInline @ 140005658 =====

ulonglong Feature_ProbeForReadProcessParameters__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_ProbeForReadProcessParameters__private_featureState;
  if ((Feature_ProbeForReadProcessParameters__private_featureState & 0x10) == 0) {
    uVar1 = Feature_ProbeForReadProcessParameters__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_ProbeForReadProcessParameters__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_ProbeForReadProcessParameters__private_IsEnabledFallback @ 140005690 =====

void Feature_ProbeForReadProcessParameters__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback
            (param_1,param_2,&Feature_ProbeForReadProcessParameters__private_descriptor);
  return;
}



===== _guard_check_icall @ 1400056c0 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 1400056d8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1400056fc =====

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



===== __GSHandlerCheck_SEH @ 140005764 =====

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



===== __cpu_features_init @ 140005800 =====

/* WARNING: Removing unreachable block (ram,0x00014000586a) */
/* WARNING: Removing unreachable block (ram,0x000140005819) */
/* WARNING: Removing unreachable block (ram,0x00014000580a) */

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



===== __security_check_cookie @ 1400058d0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140005910 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 140005940 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140005940. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140005970 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memmove @ 1400059c0 =====

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



===== memset @ 140005cc0 =====

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



===== __memset_repmovs @ 140005e00 =====

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



===== __memset_query @ 140005e80 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140005f00 =====

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



===== __memset_spec_ermsb_repmovsb @ 140006040 =====

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



===== __memset_spec_plain @ 1400060c0 =====

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



===== BfCheckAndSwitchTarget @ 140007010 =====

int BfCheckAndSwitchTarget(longlong param_1,longlong param_2,longlong *param_3,undefined1 *param_4)

{
  int iVar1;
  ulonglong uVar2;
  int unaff_EBX;
  undefined1 uVar3;
  longlong local_res10;
  
  local_res10 = 0;
  uVar3 = 0;
  iVar1 = FltGetStreamHandleContext
                    (*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20),&local_res10);
  if (iVar1 < 0) {
    if ((iVar1 == -0x3ffffddb) || (iVar1 == -0x3fffff45)) {
LAB_140007067:
      iVar1 = 0;
    }
    else {
LAB_14000711a:
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0x37,
                            &WPP_529f93b0825532f67776c14f74ba0846_Traceguids,
                            "onecore\\base\\fs\\wci\\bindflt\\filter\\utils.c",0xac,(char)iVar1);
      }
    }
  }
  else {
    if ((*(uint *)(local_res10 + 0x50) & 1) == 0) {
      if ((*(uint *)(local_res10 + 0x50) & 2) == 0) goto LAB_14000711a;
      goto LAB_140007067;
    }
    uVar2 = BfMapShadowFileObjectToReal
                      (*(undefined8 *)(param_2 + 0x18),*(longlong *)(param_2 + 0x20),local_res10,
                       (undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x10),
                       (undefined8 *)(*(longlong *)(param_1 + 0x10) + 8),(undefined8 *)0x0);
    if ((char)uVar2 != '\0') {
      FltSetCallbackDataDirty(param_1);
      uVar3 = 1;
      if (param_3 != (longlong *)0x0) {
        *param_3 = local_res10;
        goto LAB_1400070c0;
      }
    }
  }
  if (local_res10 != 0) {
    FltReleaseContext();
  }
  if (iVar1 < 0) {
    return unaff_EBX;
  }
LAB_1400070c0:
  if (param_4 != (undefined1 *)0x0) {
    *param_4 = uVar3;
  }
  return unaff_EBX;
}



===== BfPostReadWrite @ 140007180 =====

undefined4 BfPostReadWrite(longlong param_1,longlong param_2,ulonglong param_3,undefined4 param_4)

{
  longlong lVar1;
  longlong lVar2;
  undefined4 uVar3;
  ulonglong uVar4;
  undefined4 local_res10 [2];
  
  lVar1 = *(longlong *)(param_2 + 0x20);
  local_res10[0] = 0;
  uVar4 = param_3 & 0xfffffffffffffffe;
  uVar3 = 0;
  if (uVar4 != 0) {
    if ((param_3 & 1) != 0) {
      ExReleaseRundownProtection(uVar4 + 0x18);
    }
    lVar2 = *(longlong *)(uVar4 + 8);
    if ((lVar1 != 0) && (lVar2 != 0)) {
      if (((*(uint *)(lVar1 + 0x50) & 0x4000) == 0) && ((**(uint **)(param_1 + 0x10) & 1) == 0)) {
        *(undefined8 *)(lVar1 + 0x30) = *(undefined8 *)(lVar2 + 0x30);
      }
      if (-1 < *(int *)(param_1 + 0x18)) {
        if ((((*(uint *)(lVar2 + 0x50) & 2) != 0) && ((**(uint **)(param_1 + 0x10) & 2) == 0)) &&
           (*(longlong *)(param_1 + 0x20) != 0)) {
          *(undefined8 *)(lVar1 + 0x68) = *(undefined8 *)(lVar2 + 0x68);
        }
        if ((*(char *)(*(longlong *)(param_1 + 0x10) + 4) == '\x04') && ((param_3 & 1) == 0)) {
          FltDoCompletionProcessingWhenSafe
                    (param_1,param_2,lVar2,param_4,BfUpdateFileSizesWorker,local_res10);
        }
      }
    }
    FltReleaseContext(uVar4);
    uVar3 = local_res10[0];
  }
  return uVar3;
}



===== BfUpdateFileSizesWorker @ 1400072a0 =====

undefined8 BfUpdateFileSizesWorker(undefined8 param_1,longlong param_2,longlong param_3)

{
  BfUpdateFileSizes(param_3,*(longlong *)(param_2 + 0x20));
  return 0;
}



===== BfUpdateFileSizes @ 1400072c0 =====

void BfUpdateFileSizes(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar1 = *(longlong *)(param_2 + 0x18);
  lVar2 = *(longlong *)(param_1 + 0x18);
  ExAcquireFastMutex(*(undefined8 *)(lVar1 + 0x30));
  ExAcquireFastMutex(*(undefined8 *)(lVar2 + 0x30));
  *(undefined8 *)(lVar1 + 0x18) = *(undefined8 *)(lVar2 + 0x18);
  *(undefined8 *)(lVar1 + 0x20) = *(undefined8 *)(lVar2 + 0x20);
  *(undefined8 *)(lVar1 + 0x28) = *(undefined8 *)(lVar2 + 0x28);
  ExReleaseFastMutex(*(undefined8 *)(lVar2 + 0x30));
  ExReleaseFastMutex(*(undefined8 *)(lVar1 + 0x30));
  return;
}



===== BfUpdateHeaderFlagsReverse @ 14000733c =====

void BfUpdateHeaderFlagsReverse(longlong param_1,undefined8 param_2,longlong param_3)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar1 = *(longlong *)(param_1 + 0x18);
  lVar2 = *(longlong *)(param_3 + 0x18);
  ExAcquireFastMutex(*(undefined8 *)(lVar1 + 0x30));
  ExAcquireFastMutex(*(undefined8 *)(lVar2 + 0x30));
  *(byte *)(lVar2 + 4) = *(byte *)(lVar2 + 4) | *(byte *)(lVar1 + 4) & 0x20;
  ExReleaseFastMutex(*(undefined8 *)(lVar2 + 0x30));
  ExReleaseFastMutex(*(undefined8 *)(lVar1 + 0x30));
  return;
}



===== BfPreReadWrite @ 1400073b0 =====

undefined8 BfPreReadWrite(longlong param_1,longlong param_2,ulonglong *param_3)

{
  longlong lVar1;
  ulonglong uVar2;
  longlong lVar3;
  char cVar4;
  int extraout_EAX;
  int iVar5;
  longlong lVar6;
  char local_res8 [8];
  
  local_res8[0] = '\0';
  if ((*(longlong *)(*(longlong *)(param_1 + 0x10) + 8) != 0) &&
     ((*(uint *)(*(longlong *)(param_2 + 0x20) + 0x50) >> 0x16 & 1) == 0)) {
    iVar5 = BfCheckAndSwitchTarget(param_1,param_2,(longlong *)param_3,local_res8);
    if ((-1 < extraout_EAX) && (local_res8[0] != '\0')) {
      lVar1 = *(longlong *)(CONCAT44((int)((ulonglong)param_1 >> 0x20),iVar5) + 0x10);
      if (((*(char *)(lVar1 + 4) == '\x04') && (uVar2 = *param_3, uVar2 != 0)) &&
         (*(longlong *)(uVar2 + 8) != 0)) {
        lVar3 = *(longlong *)(*(longlong *)(uVar2 + 8) + 0x18);
        lVar6 = (ulonglong)*(uint *)(lVar1 + 0x18) + *(longlong *)(lVar1 + 0x28);
        if (lVar6 < *(longlong *)(lVar1 + 0x28)) {
          lVar6 = 0x7fffffffffffffff;
        }
        if (lVar6 <= *(longlong *)(lVar3 + 0x28)) {
          cVar4 = ExAcquireRundownProtection(uVar2 + 0x18);
          if (cVar4 != '\0') {
            if (lVar6 <= *(longlong *)(lVar3 + 0x28)) {
              *param_3 = *param_3 | 1;
              return 0;
            }
            ExReleaseRundownProtection(uVar2 + 0x18);
          }
        }
      }
      return 0;
    }
  }
  return 1;
}



===== BfpGetInstanceTierNode @ 140011008 =====

int BfpGetInstanceTierNode
              (short *param_1,longlong param_2,longlong param_3,char param_4,undefined8 *param_5,
              undefined8 *param_6,undefined8 *param_7)

{
  code *pcVar1;
  int iVar2;
  ulonglong uVar3;
  undefined8 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  longlong *plVar7;
  undefined8 *puVar8;
  undefined2 uVar9;
  undefined1 auStackY_88 [8];
  undefined1 auStackY_80 [24];
  undefined1 uVar10;
  longlong *local_48;
  undefined8 *local_40;
  undefined8 *local_38 [2];
  
  local_48 = (longlong *)0x0;
  local_38[0] = (undefined8 *)0x0;
  local_40 = (undefined8 *)0x0;
  iVar2 = BfpGetMappingContext((uint *)0x0,param_1,param_2,param_3,(longlong *)&local_48,local_38);
  puVar8 = local_38[0];
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,0x8d,
                          &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                          "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",0xa1,(char)iVar2);
    }
    puVar5 = auStackY_88;
    plVar7 = local_48;
    goto LAB_140011203;
  }
  FltAcquireResourceExclusive(local_38[0] + 2);
  plVar7 = local_48;
  puVar6 = auStackY_88;
  puVar5 = auStackY_88;
  for (puVar4 = (undefined8 *)*puVar8; puVar4 != puVar8; puVar4 = (undefined8 *)*puVar4) {
    if (*(longlong *)puVar4[2] == *local_48) goto LAB_14001115d;
    local_40 = (undefined8 *)0x0;
  }
  if (param_4 == '\0') {
    iVar2 = -0x3ffffddb;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      iVar2 = -0x3ffffddb;
      uVar9 = 0x8f;
      uVar10 = 199;
LAB_1400111c3:
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,uVar9,
                          &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                          "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",uVar10,(char)iVar2);
      puVar6 = auStackY_88;
    }
  }
  else {
    uVar3 = BfpCreateInstanceTierNode(local_48,(longlong *)&local_40);
    puVar5 = auStackY_88;
    puVar6 = auStackY_88;
    iVar2 = (int)uVar3;
    if (iVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar9 = 0x8e;
        uVar10 = 0xba;
        goto LAB_1400111c3;
      }
    }
    else {
      puVar4 = (undefined8 *)puVar8[1];
      if ((undefined8 *)*puVar4 != puVar8) {
        pcVar1 = (code *)swi(0x29);
        puVar4 = (undefined8 *)(*pcVar1)(3);
        puVar5 = auStackY_80;
      }
      *local_40 = puVar8;
      local_40[1] = puVar4;
      *puVar4 = local_40;
      puVar8[1] = local_40;
      puVar4 = local_40;
LAB_14001115d:
      if (param_6 != (undefined8 *)0x0) {
        *(undefined8 *)(puVar5 + -8) = 0x140011171;
        FltReleaseResource(puVar8 + 2);
        *param_6 = puVar8;
        puVar8 = (undefined8 *)0x0;
      }
      if (param_5 != (undefined8 *)0x0) {
        *param_5 = plVar7;
        plVar7 = (longlong *)0x0;
      }
      *param_7 = puVar4;
      puVar6 = puVar5;
      if (param_6 != (undefined8 *)0x0) goto LAB_140011203;
    }
  }
  *(undefined8 *)(puVar6 + -8) = 0x1400111fe;
  FltReleaseResource(puVar8 + 2);
  puVar5 = puVar6;
LAB_140011203:
  if (plVar7 != (longlong *)0x0) {
    *(undefined8 *)(puVar5 + -8) = 0x140011212;
    FltReleaseContext(plVar7);
  }
  return iVar2;
}



===== BfInstanceQueryTeardown @ 140011240 =====

int BfInstanceQueryTeardown(longlong param_1)

{
  int iVar1;
  undefined2 uVar2;
  longlong local_res8 [4];
  undefined1 uVar3;
  
  local_res8[0] = 0;
  iVar1 = FltGetInstanceContext(*(undefined8 *)(param_1 + 0x18),local_res8);
  if (-1 < iVar1) {
    if (*(int *)(local_res8[0] + 0x20) == 0) {
      if ((*(int *)(local_res8[0] + 0x24) == 0) ||
         (iVar1 = -0x3fe3fff0, (undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED))
      goto LAB_140011307;
      uVar2 = 0x12;
      uVar3 = 0xe9;
    }
    else {
      iVar1 = -0x3fe3fff0;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140011307;
      uVar2 = 0x11;
      uVar3 = 0xe2;
    }
    iVar1 = -0x3fe3fff0;
    WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,7,uVar2,
                        &WPP_ab4056511ca038337f1519c30a6fffbb_Traceguids,
                        "onecore\\base\\fs\\wci\\bindflt\\filter\\context.c",uVar3,0x10);
  }
LAB_140011307:
  if (local_res8[0] != 0) {
    FltReleaseContext();
  }
  return iVar1;
}



===== BfInstanceTeardownComplete @ 140011330 =====

void BfInstanceTeardownComplete(void)

{
  return;
}



===== BfInstanceTeardownStart @ 140011340 =====

void BfInstanceTeardownStart(longlong param_1)

{
  int iVar1;
  longlong local_res8 [4];
  
  local_res8[0] = 0;
  iVar1 = FltGetInstanceContext(*(undefined8 *)(param_1 + 0x18),local_res8);
  if (-1 < iVar1) {
    BfCleanupMappingContext(*(longlong **)(local_res8[0] + 0x30));
    ExFreePoolWithTag(*(undefined8 *)(local_res8[0] + 0x30),0x636d4642);
  }
  if (local_res8[0] != 0) {
    FltReleaseContext();
  }
  return;
}



===== BfPostCreate @ 1400113b0 =====

undefined8 BfPostCreate(longlong param_1,longlong param_2)

{
  int iVar1;
  
  iVar1 = BfSetWriteTrackingEa(*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20));
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x25,
                          &WPP_48a527b79fd4344d8b4157379f595642_Traceguids,
                          "onecore\\base\\fs\\wci\\bindflt\\filter\\create.c",0xca,(char)iVar1);
    }
    *(undefined8 *)(param_1 + 0x20) = 0;
    *(int *)(param_1 + 0x18) = iVar1;
  }
  return 0;
}



===== BfSetWriteTrackingEa @ 140011440 =====

undefined4 BfSetWriteTrackingEa(undefined8 param_1,undefined8 param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)ExAllocatePool2(0x100,0x26,0x77744642);
  if (puVar2 == (undefined4 *)0x0) {
    uVar1 = 0xc000009a;
  }
  else {
    *puVar2 = 0;
    puVar2[1] = 0x11800;
    builtin_strncpy((char *)(puVar2 + 2),"$BINDFLT",8);
    builtin_strncpy((char *)(puVar2 + 4),".WRITTEN",8);
    *(undefined8 *)(puVar2 + 6) = 0x4f4c49532e4e492e;
    uVar1 = FltSetEaFile(param_1,param_2,puVar2,0x26);
    ExFreePoolWithTag(puVar2,0x77744642);
  }
  return uVar1;
}



===== wil_RtlStagingConfig_QueryFeatureState @ 1400114ec =====

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



===== BfFsctlGetMappings @ 1400115b8 =====

undefined8 BfFsctlGetMappings(longlong param_1)

{
  void *_Dst;
  bool bVar1;
  bool bVar2;
  void *_Src;
  char cVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  void *_Dst_00;
  uint *_Src_00;
  ulonglong uVar6;
  ulonglong uVar7;
  longlong lVar8;
  byte bVar9;
  int iVar10;
  undefined2 uVar11;
  uint uVar12;
  uint local_res18 [2];
  void *local_res20;
  undefined1 uVar13;
  uint uVar14;
  undefined1 uVar15;
  longlong local_60 [5];
  
  iVar10 = 0;
  _Dst_00 = (void *)0x0;
  local_res18[0] = 0;
  _Src_00 = (uint *)0x0;
  local_60[0] = 0;
  local_60[1] = 0;
  local_60[2] = 0;
  local_60[3] = 0;
  bVar2 = false;
  lVar8 = *(longlong *)(param_1 + 0x10);
  uVar12 = *(uint *)(lVar8 + 0x20);
  uVar6 = (ulonglong)uVar12;
  uVar14 = *(uint *)(lVar8 + 0x18);
  uVar7 = (ulonglong)uVar14;
  local_res20 = *(void **)(lVar8 + 0x30);
  _Dst = *(void **)(lVar8 + 0x38);
  uVar4 = PsGetCurrentSilo();
  cVar3 = PsIsHostSilo(uVar4);
  if (cVar3 == '\0') {
    uVar5 = Feature_2535612730__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar5 != 0) {
      cVar3 = ExGetPreviousMode();
      if (cVar3 == '\x01') {
        SeCaptureSubjectContext(local_60);
        bVar2 = true;
        SeLockSubjectContext(local_60);
        lVar8 = local_60[2];
        if (local_60[0] != 0) {
          lVar8 = local_60[0];
        }
        if (lVar8 == 0) {
LAB_140011704:
          bVar1 = false;
        }
        else {
          cVar3 = SeTokenIsAdmin();
          if (cVar3 == '\0') goto LAB_140011704;
          bVar1 = true;
        }
        SeUnlockSubjectContext(local_60);
        if (!bVar1) {
          iVar10 = -0x3fffffde;
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar11 = 0xb;
            uVar13 = 0x72;
            goto LAB_140011659;
          }
          goto LAB_14001196e;
        }
      }
    }
    if (uVar12 < 0x28) {
      iVar10 = -0x3ffffff3;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar11 = 0xc;
        uVar15 = 0x28;
        uVar13 = 0x7b;
        uVar14 = uVar12;
LAB_140011783:
        iVar10 = -0x3ffffff3;
        WPP_RECORDER_SF_sDdd
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,3,uVar11,
                   &WPP_3ec1b3d31795302c14eabb0ee55df402_Traceguids,
                   "onecore\\base\\fs\\wci\\bindflt\\filter\\fsctrl.c",uVar13,(char)uVar14,uVar15);
      }
    }
    else if (uVar14 < 0xc) {
      iVar10 = -0x3ffffff3;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar11 = 0xd;
        uVar15 = 0xc;
        uVar13 = 0x81;
        goto LAB_140011783;
      }
    }
    else {
      _Dst_00 = (void *)ExAllocatePool2(0x100,uVar6,0x736d4642);
      if (_Dst_00 == (void *)0x0) {
        iVar10 = -0x3fffff66;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar11 = 0xe;
          uVar13 = 0x89;
LAB_140011847:
          iVar10 = -0x3fffff66;
          bVar9 = 2;
          goto LAB_140011662;
        }
      }
      else {
        cVar3 = ExGetPreviousMode();
        _Src = local_res20;
        if (cVar3 == '\x01') {
          ProbeForRead(local_res20,uVar6,1);
          ProbeForWrite(_Dst,uVar7,1);
        }
        memmove(_Dst_00,_Src,uVar6);
        _Src_00 = (uint *)ExAllocatePool2(0x100,uVar7,0x736d4642);
        if (_Src_00 != (uint *)0x0) {
          uVar6 = Feature_2535612730__private_IsEnabledDeviceUsageNoInline();
          if ((int)uVar6 != 0) {
            *(undefined4 *)((longlong)_Dst_00 + 0xc) = 2;
            *(undefined8 *)((longlong)_Dst_00 + 0x10) = 0;
            *(undefined8 *)((longlong)_Dst_00 + 0x18) = 0;
            *(undefined8 *)((longlong)_Dst_00 + 0x20) = 0;
          }
          uVar6 = BfProcessGetMappingsRequest
                            ((longlong)_Dst_00 + 8,uVar14,(ulonglong)_Src_00,local_res18);
          uVar12 = local_res18[0];
          _Src_00[1] = (uint)uVar6;
          *_Src_00 = local_res18[0];
          memmove(_Dst,_Src_00,uVar7);
          goto LAB_140011976;
        }
        iVar10 = -0x3fffff66;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar11 = 0xf;
          uVar13 = 0xa4;
          goto LAB_140011847;
        }
      }
    }
  }
  else {
    iVar10 = -0x3fffff45;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar11 = 10;
      uVar13 = 0x3e;
      iVar10 = -0x3fffff45;
LAB_140011659:
      bVar9 = 3;
LAB_140011662:
      WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),bVar9,3,uVar11,
                         &WPP_3ec1b3d31795302c14eabb0ee55df402_Traceguids,
                         "onecore\\base\\fs\\wci\\bindflt\\filter\\fsctrl.c",uVar13);
    }
  }
LAB_14001196e:
  uVar12 = local_res18[0];
LAB_140011976:
  *(int *)(param_1 + 0x18) = iVar10;
  if (iVar10 < 0) {
    uVar7 = 0;
  }
  else {
    uVar7 = (ulonglong)uVar12;
  }
  *(ulonglong *)(param_1 + 0x20) = uVar7;
  if (_Dst_00 != (void *)0x0) {
    ExFreePoolWithTag(_Dst_00,0x736d4642);
  }
  if (_Src_00 != (uint *)0x0) {
    ExFreePoolWithTag(_Src_00,0x736d4642);
  }
  if (bVar2) {
    SeReleaseSubjectContext(local_60);
  }
  return 4;
}



===== BfLogMappingsCallback @ 1400119f8 =====

void BfLogMappingsCallback(undefined8 *param_1,char *param_2)

{
  undefined8 *puVar1;
  ulonglong *puVar2;
  bool bVar3;
  ulonglong *puVar4;
  ulonglong uVar5;
  ulonglong *puVar6;
  byte bVar7;
  ulonglong *puVar8;
  
  puVar1 = (undefined8 *)*param_1;
  do {
    if (puVar1 == param_1) {
      return;
    }
    if ((undefined4 *)puVar1[4] != (undefined4 *)0x0) {
      BfLogPathTierNode((undefined4 *)puVar1[4],param_2);
    }
    puVar2 = (ulonglong *)puVar1[3];
    bVar3 = BfpPathTreeEmpty(puVar2);
    if ((!bVar3) && (puVar8 = (ulonglong *)*puVar2, puVar8 != (ulonglong *)0x0)) {
      while (uVar5 = BfLogRBNode((longlong)puVar8,param_2), -1 < (int)uVar5) {
        puVar6 = (ulonglong *)*puVar8;
        if (puVar6 == (ulonglong *)0x0) {
          puVar6 = (ulonglong *)puVar8[1];
          if (puVar6 == (ulonglong *)0x0) {
            bVar7 = (byte)puVar2[1] & 1;
            do {
              puVar4 = (ulonglong *)(puVar8[2] & 0xfffffffffffffffc);
              if (bVar7 != 0) {
                if (puVar4 == (ulonglong *)0x0) goto LAB_140011ad6;
                puVar4 = (ulonglong *)((ulonglong)puVar4 ^ (ulonglong)puVar8);
              }
              if (puVar4 == (ulonglong *)0x0) goto LAB_140011ad6;
              puVar6 = (ulonglong *)puVar4[1];
              if (bVar7 == 0) {
LAB_140011ab5:
                if ((puVar6 != (ulonglong *)0x0) && (puVar6 != puVar8)) goto LAB_140011ac4;
              }
              else if (puVar6 != (ulonglong *)0x0) {
                puVar6 = (ulonglong *)((ulonglong)puVar6 ^ (ulonglong)puVar4);
                goto LAB_140011ab5;
              }
              puVar8 = puVar4;
            } while( true );
          }
          if (((byte)puVar2[1] & 1) == 0) {
            puVar8 = puVar6;
          }
          else {
            puVar8 = (ulonglong *)((ulonglong)puVar8 ^ (ulonglong)puVar6);
          }
        }
        else if ((puVar2[1] & 1) == 0) {
LAB_140011ac4:
          puVar8 = puVar6;
        }
        else {
          puVar8 = (ulonglong *)((ulonglong)puVar8 ^ (ulonglong)puVar6);
        }
      }
    }
LAB_140011ad6:
    puVar1 = (undefined8 *)*puVar1;
  } while( true );
}



===== BfLogPathTierNode @ 140011b04 =====

ulonglong BfLogPathTierNode(undefined4 *param_1,char *param_2)

{
  uint uVar1;
  ushort uVar2;
  longlong lVar3;
  bool bVar4;
  uint uVar5;
  ulonglong uVar6;
  undefined8 *puVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  undefined2 *puVar11;
  undefined8 *puVar12;
  int iVar13;
  longlong *plVar14;
  uint uVar15;
  int local_res18;
  undefined8 local_68;
  void *pvStack_60;
  ushort local_58;
  undefined2 uStack_56;
  uint uStack_54;
  undefined4 uStack_50;
  int iStack_4c;
  
  uVar5 = 0;
  local_68 = 0;
  pvStack_60 = (void *)0x0;
  if (((byte)*param_1 & 3) != 1) goto LAB_140011c2d;
  iVar8 = 0;
  local_res18 = 0;
  uVar10 = 0;
  bVar4 = false;
  plVar14 = *(longlong **)(*(longlong *)(param_1 + 0x12) + 0x40);
  uVar9 = uVar10;
  if (plVar14 != (longlong *)(*(longlong *)(param_1 + 0x12) + 0x40)) {
    while( true ) {
      iVar8 = iVar8 + 8;
      uVar6 = Feature_2657777978__private_IsEnabledDeviceUsageNoInline();
      uVar10 = uVar9 + 8 + (uint)*(ushort *)(plVar14 + 3);
      local_res18 = iVar8;
      if (((int)uVar6 != 0) && (uVar10 < uVar9)) break;
      plVar14 = (longlong *)*plVar14;
      if (plVar14 == (longlong *)(*(longlong *)(param_1 + 0x12) + 0x40)) goto LAB_140011b92;
      uVar9 = uVar10;
    }
    uVar10 = 0xffffffff;
    bVar4 = true;
  }
LAB_140011b92:
  uVar2 = *(ushort *)(param_1 + 0xe);
  uVar15 = (uint)uVar2;
  uVar9 = 0;
  uVar6 = Feature_2657777978__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar6 == 0) {
    uVar9 = uVar15 + 0x14 + uVar10;
  }
  else {
    if (!bVar4) {
      uVar1 = uVar15 + uVar10;
      if ((uVar15 <= uVar1) && (uVar9 = uVar1 + 0x14, uVar1 <= uVar9)) goto LAB_140011bd7;
      uVar9 = 0xffffffff;
    }
    bVar4 = true;
  }
LAB_140011bd7:
  if (*param_2 == '\0') {
    uVar6 = Feature_2657777978__private_IsEnabledDeviceUsageNoInline();
    iVar8 = 0;
    if ((int)uVar6 == 0) {
      uVar9 = *(uint *)(param_2 + 0xc);
      uVar15 = *(uint *)(param_2 + 8);
LAB_140011c1e:
      if (uVar2 + uVar10 <= uVar15 - uVar9) {
        uStack_56 = 0;
        uStack_50 = *(undefined4 *)(*(longlong *)(param_1 + 0x12) + 8);
        iStack_4c = 0;
        local_58 = uVar2;
        uStack_54 = uVar9;
        memmove((void *)((ulonglong)uVar9 + *(longlong *)(param_2 + 0x10)),
                *(void **)(param_1 + 0x10),(ulonglong)uVar2);
        iVar13 = *(int *)(param_2 + 0xc) + (uint)uVar2;
        *(int *)(param_2 + 0xc) = iVar13;
        local_res18 = local_res18 + iVar13;
        puVar7 = (undefined8 *)(*(longlong *)(param_1 + 0x12) + 0x40);
        for (puVar12 = (undefined8 *)*puVar7; puVar12 != puVar7; puVar12 = (undefined8 *)*puVar12) {
          local_68._0_4_ = CONCAT22(*(short *)(puVar12 + 3),(ushort)local_68);
          uVar6 = BfAllocateUnicodeString(*(short *)(puVar12 + 3),(undefined4 *)&local_68);
          if ((int)uVar6 < 0) {
            return uVar6;
          }
          uVar5 = RtlAppendUnicodeStringToString(&local_68,puVar12 + 3);
          if ((int)uVar5 < 0) goto LAB_140011c2d;
          puVar11 = (undefined2 *)
                    ((ulonglong)*(uint *)(param_2 + 0xc) + *(longlong *)(param_2 + 0x10));
          *puVar11 = (ushort)local_68;
          *(int *)(puVar11 + 2) = local_res18;
          *(int *)(param_2 + 0xc) = *(int *)(param_2 + 0xc) + 8;
          memmove((void *)((ulonglong)*(uint *)(puVar11 + 2) + *(longlong *)(param_2 + 0x10)),
                  pvStack_60,local_68 & 0xffff);
          local_res18 = local_res18 + (uint)(ushort)local_68;
          BfFreeUnicodeString((undefined4 *)&local_68);
          iVar8 = iVar8 + 1;
          pvStack_60 = (void *)0x0;
          puVar7 = (undefined8 *)(*(longlong *)(param_1 + 0x12) + 0x40);
        }
        lVar3 = *(longlong *)(param_2 + 0x10);
        *(int *)(param_2 + 0xc) = local_res18;
        uVar9 = *(uint *)(lVar3 + 8);
        puVar12 = (undefined8 *)(lVar3 + 0xc + (ulonglong)uVar9 * 0x14);
        *puVar12 = CONCAT44(uStack_54,CONCAT22(uStack_56,local_58));
        puVar12[1] = CONCAT44(iVar8,uStack_50);
        *(int *)(lVar3 + 0x1c + (ulonglong)uVar9 * 0x14) = iVar13;
        *(int *)(lVar3 + 8) = *(int *)(lVar3 + 8) + 1;
        iStack_4c = iVar8;
        goto LAB_140011c2d;
      }
    }
    else if (!bVar4) {
      uVar9 = *(uint *)(param_2 + 0xc);
      uVar15 = *(uint *)(param_2 + 8);
      if (uVar9 <= uVar15) goto LAB_140011c1e;
    }
    uVar5 = 0xc0000023;
    goto LAB_140011c2d;
  }
  uVar6 = Feature_2657777978__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar6 == 0) {
    *(uint *)(param_2 + 0xc) = *(int *)(param_2 + 0xc) + uVar9;
  }
  else {
    if (!bVar4) {
      uVar9 = *(uint *)(param_2 + 0xc) + uVar9;
      if (*(uint *)(param_2 + 0xc) <= uVar9) {
        *(uint *)(param_2 + 0xc) = uVar9;
        goto LAB_140011c07;
      }
      param_2[0xc] = -1;
      param_2[0xd] = -1;
      param_2[0xe] = -1;
      param_2[0xf] = -1;
    }
    param_2[0xc] = -1;
    param_2[0xd] = -1;
    param_2[0xe] = -1;
    param_2[0xf] = -1;
  }
LAB_140011c07:
  *(int *)(param_2 + 4) = *(int *)(param_2 + 4) + 1;
LAB_140011c2d:
  BfFreeUnicodeString((undefined4 *)&local_68);
  return (ulonglong)uVar5;
}



===== BfLogRBNode @ 140011d74 =====

ulonglong BfLogRBNode(longlong param_1,char *param_2)

{
  ulonglong *puVar1;
  bool bVar2;
  ulonglong uVar3;
  ulonglong *puVar4;
  ulonglong *puVar5;
  byte bVar6;
  ulonglong *puVar7;
  ulonglong uVar8;
  
  uVar3 = BfLogPathTierNode((uint *)(param_1 + -8),param_2);
  uVar8 = uVar3 & 0xffffffff;
  if ((-1 < (int)uVar3) && ((*(uint *)(param_1 + -8) & 2) == 0)) {
    puVar1 = *(ulonglong **)(param_1 + 0x48);
    bVar2 = BfpPathTreeEmpty(puVar1);
    if ((!bVar2) && (puVar7 = (ulonglong *)*puVar1, puVar7 != (ulonglong *)0x0)) {
      while (uVar3 = BfLogRBNode((longlong)puVar7,param_2), -1 < (int)uVar3) {
        puVar5 = (ulonglong *)*puVar7;
        if (puVar5 == (ulonglong *)0x0) {
          puVar5 = (ulonglong *)puVar7[1];
          if (puVar5 == (ulonglong *)0x0) {
            bVar6 = (byte)puVar1[1] & 1;
            do {
              puVar4 = (ulonglong *)(puVar7[2] & 0xfffffffffffffffc);
              if (bVar6 != 0) {
                if (puVar4 == (ulonglong *)0x0) {
                  return uVar8;
                }
                puVar4 = (ulonglong *)((ulonglong)puVar4 ^ (ulonglong)puVar7);
              }
              if (puVar4 == (ulonglong *)0x0) {
                return uVar8;
              }
              puVar5 = (ulonglong *)puVar4[1];
              if (bVar6 == 0) {
LAB_140011e2b:
                if ((puVar5 != (ulonglong *)0x0) && (puVar5 != puVar7)) goto LAB_140011e3a;
              }
              else if (puVar5 != (ulonglong *)0x0) {
                puVar5 = (ulonglong *)((ulonglong)puVar5 ^ (ulonglong)puVar4);
                goto LAB_140011e2b;
              }
              puVar7 = puVar4;
            } while( true );
          }
          if (((byte)puVar1[1] & 1) == 0) {
            puVar7 = puVar5;
          }
          else {
            puVar7 = (ulonglong *)((ulonglong)puVar7 ^ (ulonglong)puVar5);
          }
        }
        else if ((puVar1[1] & 1) == 0) {
LAB_140011e3a:
          puVar7 = puVar5;
        }
        else {
          puVar7 = (ulonglong *)((ulonglong)puVar7 ^ (ulonglong)puVar5);
        }
      }
    }
  }
  return uVar8;
}



===== BfProcessGetMappingsRequest @ 140011e6c =====

ulonglong BfProcessGetMappingsRequest(longlong param_1,uint param_2,ulonglong param_3,uint *param_4)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined8 *puVar5;
  undefined2 uVar6;
  undefined8 local_res8;
  undefined1 uVar7;
  undefined8 local_68;
  uint uStack_60;
  uint uStack_5c;
  ulonglong local_58;
  longlong local_50;
  longlong local_48;
  longlong local_40;
  longlong local_38;
  longlong local_30;
  longlong local_28;
  longlong local_20;
  
  local_40 = 0;
  local_30 = 0;
  local_28 = 0;
  local_50 = 0;
  local_48 = 0;
  local_38 = 0;
  local_res8 = 0;
  local_20 = 0;
  local_58 = local_58 & 0xffffff0000000000;
  uVar3 = *(uint *)(param_1 + 4);
  local_68 = 0;
  uStack_60 = 0;
  uStack_5c = 0;
  if ((uVar3 & 1) == 0) {
    if ((uVar3 & 2) == 0) {
      if ((uVar3 & 4) == 0) {
        uVar4 = 0xc000000d;
        goto LAB_1400121f9;
      }
      uVar4 = BfGetOrCreateUser(*(undefined8 *)(param_1 + 0x18),&local_20);
      uVar3 = (uint)uVar4;
      uVar4 = uVar4 & 0xffffffff;
      if (-1 < (int)uVar3) {
        puVar5 = *(undefined8 **)(local_20 + 0x18);
        goto LAB_140012173;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400121f9;
      uVar6 = 0x5c;
      uVar7 = 0x3c;
    }
    else {
      if (*(longlong *)(param_1 + 0x10) == 0) {
        local_res8 = PsGetCurrentSilo();
LAB_1400120f8:
        uVar3 = PsGetSiloContext(local_res8,DAT_14000d290,&local_28);
        uVar4 = (ulonglong)uVar3;
        if ((int)uVar3 < 0) goto LAB_1400121f9;
        puVar5 = *(undefined8 **)(local_28 + 8);
LAB_140012173:
        if (param_2 < 4) {
          uVar4 = 0xc0000023;
        }
        else {
          uStack_5c = 0xc;
          local_68 = CONCAT71(local_68._1_7_,1);
          local_58 = param_3;
          uStack_60 = param_2;
          FltAcquireResourceExclusive(puVar5 + 2);
          BfLogMappingsCallback(puVar5,(char *)&local_68);
          if (uStack_60 < uStack_5c) {
            uVar4 = 0x80000005;
          }
          else {
            iVar1 = local_68._4_4_;
            local_68 = local_68 & 0xffffffffffffff00;
            uStack_5c = iVar1 * 0x14 + 0xc;
            BfLogMappingsCallback(puVar5,(char *)&local_68);
          }
          FltReleaseResource(puVar5 + 2);
          *param_4 = uStack_5c;
        }
        goto LAB_1400121f9;
      }
      cVar2 = ObIsKernelHandle();
      uVar3 = ObReferenceObjectByHandle
                        (*(undefined8 *)(param_1 + 0x10),4,*(undefined8 *)PsJobType_exref,
                         cVar2 == '\0',&local_38,0);
      uVar4 = (ulonglong)uVar3;
      if ((int)uVar3 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400121f9;
        uVar6 = 0x5a;
        uVar7 = 0x17;
      }
      else {
        uVar3 = PsGetJobSilo(local_38,&local_res8);
        uVar4 = (ulonglong)uVar3;
        if (-1 < (int)uVar3) goto LAB_1400120f8;
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400121f9;
        uVar6 = 0x5b;
        uVar7 = 0x1f;
      }
    }
  }
  else {
    cVar2 = ObIsKernelHandle(*(undefined8 *)(param_1 + 8));
    uVar3 = ObReferenceObjectByHandle
                      (*(undefined8 *)(param_1 + 8),0,*(undefined8 *)IoFileObjectType_exref,
                       cVar2 == '\0',&local_40,0);
    uVar4 = (ulonglong)uVar3;
    if ((int)uVar3 < 0) goto LAB_1400121f9;
    uVar3 = FltGetVolumeFromFileObject(g_BindFltState,local_40,&local_50);
    uVar4 = (ulonglong)uVar3;
    if ((int)uVar3 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400121f9;
      uVar6 = 0x58;
      uVar7 = 0xf7;
    }
    else {
      uVar3 = FltGetVolumeInstanceFromName(g_BindFltState,local_50,0,&local_48);
      uVar4 = (ulonglong)uVar3;
      if (-1 < (int)uVar3) {
        uVar3 = FltGetInstanceContext(local_48,&local_30);
        uVar4 = (ulonglong)uVar3;
        if ((int)uVar3 < 0) goto LAB_1400121f9;
        puVar5 = *(undefined8 **)(local_30 + 0x30);
        goto LAB_140012173;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400121f9;
      uVar6 = 0x59;
      uVar7 = 0xfe;
    }
  }
  WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,3,uVar6,
                      &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                      "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",uVar7,(char)uVar3);
LAB_1400121f9:
  if (local_50 != 0) {
    FltObjectDereference();
  }
  if (local_48 != 0) {
    FltObjectDereference();
  }
  if (local_40 != 0) {
    ObfDereferenceObject();
  }
  if (local_38 != 0) {
    ObfDereferenceObject();
  }
  if (local_30 != 0) {
    FltReleaseContext();
  }
  if (local_28 != 0) {
    PsDereferenceSiloContext();
  }
  return uVar4;
}



===== BfProcessTrackWritesRequest @ 1400122a0 =====

ulonglong BfProcessTrackWritesRequest(uint *param_1,uint param_2)

{
  short *psVar1;
  longlong lVar2;
  char cVar3;
  uint uVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  uint uVar7;
  undefined2 uVar8;
  longlong local_res18;
  short *local_res20;
  undefined1 uVar9;
  longlong local_48;
  undefined8 local_40;
  longlong local_38;
  short local_30 [4];
  short *psStack_28;
  
  local_res18 = 0;
  local_40 = 0;
  local_48 = 0;
  local_38 = 0;
  local_res20 = (short *)0x0;
  uVar5 = PsGetCurrentSilo();
  cVar3 = PsIsHostSilo(uVar5);
  if (cVar3 == '\0') {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,0xc5,
                         &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                         "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",0x9c);
    }
    uVar6 = 0xc0000022;
    goto LAB_14001276b;
  }
  if (param_2 < 0x20) {
    uVar6 = 0xc000000d;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,0xc6,
                         &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                         "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",0xa8);
    }
    goto LAB_14001276b;
  }
  if (param_2 < *param_1) {
    uVar6 = 0xc000000d;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDdd
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,199,
                 &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                 "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",0xaf,(char)*param_1,
                 (char)param_2);
    }
    goto LAB_14001276b;
  }
  ExAcquireFastMutex(&DAT_14000d248);
  if (DAT_14000d280 != '\0') {
    ExReleaseFastMutex();
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,200,
                         &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                         "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",0xbd);
    }
    uVar6 = 0xc00000bb;
    goto LAB_14001276b;
  }
  ExReleaseFastMutex(&DAT_14000d248);
  if (*(longlong *)(param_1 + 4) == 0) {
LAB_140012594:
    local_30[0] = 0;
    local_30[1] = 0;
    local_30[2] = 0;
    local_30[3] = 0;
    psStack_28 = (short *)0x0;
    uVar6 = BfpValidateVirtualizationRoot((ushort *)param_1,param_1 + 6,param_2,&local_res20);
    psVar1 = local_res20;
    uVar4 = (uint)uVar6;
    uVar6 = uVar6 & 0xffffffff;
    if (-1 < (int)uVar4) {
      psStack_28 = local_res20 + 3;
      local_30[1] = local_res20[1];
      local_30[0] = local_res20[1];
      uVar4 = BfpGetInstanceTierNode
                        (local_30,0,*(longlong *)(param_1 + 2),'\0',(undefined8 *)0x0,&local_48,
                         &local_38);
      lVar2 = local_48;
      uVar6 = (ulonglong)uVar4;
      if (uVar4 == 0xc0000225) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,8,0xcc,
                             &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                             "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",4);
        }
        uVar6 = 0xc000000d;
        goto LAB_14001276b;
      }
      if (-1 < (int)uVar4) {
        FltAcquireResourceExclusive(local_48 + 0x10);
        if (psVar1[(ulonglong)((ushort)psVar1[2] >> 1) + 2] == 0x5c) {
          psVar1[2] = psVar1[2] - 2;
          *psVar1 = *psVar1 + -2;
        }
        uVar4 = BfpExecuteCallbackOnVirtualizationRootNode
                          (local_38,(longlong)psVar1,BfpSetMappingNodeForTracking,local_40);
        uVar6 = (ulonglong)uVar4;
        if (((int)uVar4 < 0) &&
           ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,0xce,
                              &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                              "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",0x25,(char)uVar4)
          ;
        }
        FltReleaseResource(lVar2 + 0x10);
        goto LAB_14001276b;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001276b;
      uVar8 = 0xcd;
      uVar9 = 10;
      goto LAB_14001251d;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001276b;
    uVar8 = 0xcb;
    uVar9 = 0xe9;
    uVar7 = 3;
  }
  else {
    cVar3 = ObIsKernelHandle();
    uVar4 = ObReferenceObjectByHandle
                      (*(undefined8 *)(param_1 + 4),4,*(undefined8 *)PsJobType_exref,cVar3 == '\0',
                       &local_res18,0);
    uVar6 = (ulonglong)uVar4;
    if ((int)uVar4 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001276b;
      uVar8 = 0xc9;
      uVar9 = 0xd3;
    }
    else {
      uVar4 = PsGetJobSilo(local_res18,&local_40);
      uVar6 = (ulonglong)uVar4;
      if (-1 < (int)uVar4) goto LAB_140012594;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001276b;
      uVar8 = 0xca;
      uVar9 = 0xdb;
    }
LAB_14001251d:
    uVar7 = 6;
  }
  WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar7,uVar8,
                      &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                      "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",uVar9,(char)uVar4);
LAB_14001276b:
  if (local_res18 != 0) {
    ObfDereferenceObject();
  }
  return uVar6;
}



===== BfRemoveBatchedVirtualizationMapping @ 14001279c =====

ulonglong BfRemoveBatchedVirtualizationMapping(uint *param_1,ulonglong param_2)

{
  bool bVar1;
  char cVar2;
  uint uVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  ushort *puVar7;
  undefined2 uVar8;
  longlong lVar9;
  longlong lVar10;
  longlong lVar11;
  ushort *local_res18;
  longlong local_res20;
  undefined1 uVar12;
  longlong local_88;
  longlong local_80;
  longlong local_78;
  longlong local_70;
  undefined8 local_68;
  short *psStack_60;
  ushort local_58;
  ushort local_56;
  undefined4 local_54;
  longlong local_50;
  ulonglong local_48;
  longlong lStack_40;
  
  bVar1 = false;
  local_res18 = (ushort *)0x0;
  local_res20 = 0;
  local_80 = 0;
  lVar11 = 0;
  local_88 = 0;
  uVar4 = PsGetCurrentSilo();
  cVar2 = PsIsHostSilo(uVar4);
  if (cVar2 == '\0') {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,0xb5,
                         &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                         "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",0x18);
    }
    uVar6 = 0xc0000022;
  }
  else {
    uVar5 = BfpValidateBatchedMappingConfig(param_1,param_2 & 0xffffffff);
    uVar6 = uVar5 & 0xffffffff;
    if ((int)uVar5 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,0xb6,
                           &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                           "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",0x20);
      }
    }
    else {
      ExAcquireFastMutex(&DAT_14000d248);
      if (DAT_14000d280 == '\0') {
        ExReleaseFastMutex(&DAT_14000d248);
        local_70 = (ulonglong)param_1[6] + (longlong)param_1;
        local_78 = (ulonglong)param_1[7] + (longlong)param_1;
        lVar10 = (ulonglong)*(uint *)(local_70 + 0x20) - 1;
        lVar9 = lVar10 * 0x20;
        for (; puVar7 = (ushort *)0x0, -1 < lVar10; lVar10 = lVar10 + -1) {
          uVar5 = *(ulonglong *)(lVar9 + 0x24 + local_70);
          uVar6 = *(ulonglong *)(lVar9 + 0x34 + local_70);
          local_54 = 0;
          lStack_40 = (uVar5 >> 0x20) + 0x20 + (longlong)param_1;
          local_58 = (ushort)uVar6;
          local_48 = uVar5 >> 0x10 & 0xffff;
          local_50 = (uVar6 >> 0x20) + 0x20 + (longlong)param_1;
          uVar8 = *(undefined2 *)(local_78 + 0x24 + (uVar5 & 0xffff) * 8);
          psStack_60 = (short *)((ulonglong)*(uint *)(local_78 + 0x28 + (uVar5 & 0xffff) * 8) + 0x20
                                + (longlong)param_1);
          local_68 = (ulonglong)CONCAT22(uVar8,uVar8);
          local_56 = local_58;
          uVar5 = BfpInitializeContainerRootId
                            ((ushort *)&local_48,(ushort *)&local_68,0,&local_58,&local_res18);
          puVar7 = local_res18;
          uVar6 = uVar5 & 0xffffffff;
          if ((int)uVar5 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,0xb8,
                                  &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                                  "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",0x67,
                                  (char)uVar5);
            }
            puVar7 = local_res18;
            break;
          }
          uVar6 = BfValidateContainerRootId(local_res18,(uint)*local_res18);
          uVar3 = (uint)uVar6;
          uVar6 = uVar6 & 0xffffffff;
          if ((int)uVar3 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar8 = 0xb9;
              uVar12 = 0x6f;
LAB_140012b89:
              WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,uVar8,
                                  &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                                  "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",uVar12,
                                  (char)uVar3);
            }
            break;
          }
          if (((*psStack_60 == 0x5c) && (psStack_60[1] == 0x5c)) && (psStack_60[2] == 0x3f)) {
            puVar7[1] = 0x60;
          }
          if (lVar11 == 0) {
            uVar3 = BfpGetInstanceTierNode
                              ((short *)&local_68,*(longlong *)(param_1 + 2),
                               *(longlong *)(param_1 + 4),'\0',&local_80,&local_res20,&local_88);
            uVar6 = (ulonglong)uVar3;
            if ((int)uVar3 < 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                uVar8 = 0xba;
                uVar12 = 0x88;
                goto LAB_140012b89;
              }
              break;
            }
            FltAcquireResourceExclusive(local_res20 + 0x10);
            bVar1 = true;
            lVar11 = local_88;
          }
          if (puVar7[(ulonglong)(puVar7[2] >> 1) + 2] == 0x5c) {
            puVar7[2] = puVar7[2] - 2;
            *puVar7 = *puVar7 - 2;
          }
          uVar3 = BfpExecuteCallbackOnVirtualizationRootNode
                            (lVar11,(longlong)puVar7,BfpRemoveMapping,0);
          uVar6 = 0;
          if (uVar3 != 0xc0000225) {
            uVar6 = (ulonglong)uVar3;
          }
          uVar3 = (uint)uVar6;
          if ((int)uVar3 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar8 = 0xbb;
              uVar12 = 0xaf;
              goto LAB_140012b89;
            }
            break;
          }
          ExFreePoolWithTag(puVar7,0x706d4642);
          local_res18 = (ushort *)0x0;
          lVar9 = lVar9 + -0x20;
        }
        if (bVar1) {
          FltReleaseResource(local_res20 + 0x10);
        }
        if (local_80 != 0) {
          FltReleaseContext();
        }
        if (puVar7 != (ushort *)0x0) {
          ExFreePoolWithTag(puVar7,0x706d4642);
        }
      }
      else {
        ExReleaseFastMutex();
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,0xb7,
                             &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                             "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",0x2e);
        }
        uVar6 = 0xc00000bb;
      }
    }
  }
  return uVar6;
}



===== BfRemoveVirtualizationMapping @ 140012c7c =====

ulonglong BfRemoveVirtualizationMapping(uint *param_1,uint param_2)

{
  longlong lVar1;
  short sVar2;
  longlong lVar3;
  short *psVar4;
  char cVar5;
  uint uVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  undefined2 uVar9;
  longlong local_res18;
  short *local_res20;
  undefined1 uVar10;
  longlong local_68;
  longlong local_60;
  undefined8 local_58;
  longlong lStack_50;
  undefined8 local_48;
  longlong lStack_40;
  undefined8 local_38;
  longlong lStack_30;
  
  local_68 = 0;
  local_60 = 0;
  local_res18 = 0;
  local_res20 = (short *)0x0;
  uVar7 = PsGetCurrentSilo();
  cVar5 = PsIsHostSilo(uVar7);
  if (cVar5 == '\0') {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,0xbc,
                         &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                         "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",0xf4);
    }
    return 0xc0000022;
  }
  if (param_2 < 0x28) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0xc000000d;
    }
    WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,0xbd,
                       &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                       "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",0);
    return 0xc000000d;
  }
  if (param_2 < *param_1) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0xc000000d;
    }
    WPP_RECORDER_SF_sDdd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,0xbe,
               &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
               "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",7,(char)*param_1,(char)param_2);
    return 0xc000000d;
  }
  ExAcquireFastMutex(&DAT_14000d248);
  if (DAT_14000d280 != '\0') {
    ExReleaseFastMutex();
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,0xbf,
                         &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                         "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",0x15);
    }
    return 0xc00000bb;
  }
  ExReleaseFastMutex(&DAT_14000d248);
  uVar8 = BfpValidateVirtualizationRoot((ushort *)param_1,param_1 + 8,param_2,&local_res18);
  lVar3 = local_res18;
  if ((int)uVar8 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return uVar8 & 0xffffffff;
    }
    WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,3,0xc0,
                        &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                        "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",0x23,(char)uVar8);
    return uVar8 & 0xffffffff;
  }
  sVar2 = (short)param_1[6];
  lVar1 = local_res18 + 6;
  local_48 = (ulonglong)CONCAT22(*(undefined2 *)(local_res18 + 4),*(undefined2 *)(local_res18 + 4));
  local_58 = 0;
  lStack_50 = 0;
  if (sVar2 != 0) {
    lStack_50 = (ulonglong)param_1[7] + (longlong)param_1;
    local_58 = (ulonglong)CONCAT22(sVar2,sVar2);
  }
  lStack_40 = lVar1;
  uVar8 = BfpInitializeContainerRootId
                    ((ushort *)&local_48,(ushort *)0x0,*(short *)(local_res18 + 2),
                     (ushort *)&local_58,&local_res20);
  psVar4 = local_res20;
  uVar6 = (uint)uVar8;
  uVar8 = uVar8 & 0xffffffff;
  if ((int)uVar6 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140013140;
    uVar9 = 0xc1;
    uVar10 = 0x37;
  }
  else {
    if (local_res20[(ulonglong)((ushort)local_res20[2] >> 1) + 2] == 0x5c) {
      local_res20[2] = local_res20[2] - 2;
      *local_res20 = *local_res20 + -2;
    }
    local_38 = (ulonglong)CONCAT22(*(undefined2 *)(lVar3 + 2),*(undefined2 *)(lVar3 + 2));
    lStack_30 = lVar1;
    uVar6 = BfpGetInstanceTierNode
                      ((short *)&local_38,*(longlong *)(param_1 + 2),*(longlong *)(param_1 + 4),'\0'
                       ,(undefined8 *)0x0,&local_68,&local_60);
    lVar3 = local_68;
    uVar8 = (ulonglong)uVar6;
    if (uVar6 == 0xc0000225) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,8,0xc2,
                           &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                           "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",0x5e);
      }
      uVar8 = 0xc000000d;
      goto LAB_140013140;
    }
    if (-1 < (int)uVar6) {
      FltAcquireResourceExclusive(local_68 + 0x10);
      uVar6 = BfpExecuteCallbackOnVirtualizationRootNode
                        (local_60,(longlong)psVar4,BfpRemoveMapping,0);
      uVar8 = (ulonglong)uVar6;
      if (((int)uVar6 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,0xc4,
                            &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                            "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",0x73,(char)uVar6);
      }
      FltReleaseResource(lVar3 + 0x10);
      goto LAB_140013140;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140013140;
    uVar9 = 0xc3;
    uVar10 = 100;
  }
  WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,uVar9,
                      &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                      "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",uVar10,(char)uVar6);
LAB_140013140:
  if (psVar4 != (short *)0x0) {
    ExFreePoolWithTag(psVar4,0x706d4642);
  }
  return uVar8;
}



===== BfpCanRemoveMapping @ 140013180 =====

undefined8 BfpCanRemoveMapping(longlong param_1,undefined1 *param_2)

{
  ulonglong *puVar1;
  bool bVar2;
  ulonglong *puVar3;
  undefined8 uVar4;
  byte bVar5;
  undefined1 *puVar6;
  ulonglong *puVar7;
  ulonglong *puVar8;
  
  if ((*(uint *)(param_1 + -8) & 1) == 0) {
    if ((*(uint *)(param_1 + -8) & 2) == 0) {
      puVar1 = *(ulonglong **)(param_1 + 0x48);
      puVar6 = param_2;
      bVar2 = BfpPathTreeEmpty(puVar1);
      if ((!bVar2) && (puVar8 = (ulonglong *)*puVar1, puVar8 != (ulonglong *)0x0)) {
        while (uVar4 = BfpCanRemoveMapping((longlong)puVar8,puVar6), -1 < (int)uVar4) {
          puVar7 = (ulonglong *)*puVar8;
          if (puVar7 == (ulonglong *)0x0) {
            puVar7 = (ulonglong *)puVar8[1];
            if (puVar7 == (ulonglong *)0x0) {
              bVar5 = (byte)puVar1[1] & 1;
              do {
                puVar3 = (ulonglong *)(puVar8[2] & 0xfffffffffffffffc);
                if (bVar5 != 0) {
                  if (puVar3 == (ulonglong *)0x0) {
                    return 0;
                  }
                  puVar3 = (ulonglong *)((ulonglong)puVar3 ^ (ulonglong)puVar8);
                }
                if (puVar3 == (ulonglong *)0x0) {
                  return 0;
                }
                puVar7 = (ulonglong *)puVar3[1];
                if (bVar5 == 0) {
LAB_140013228:
                  if ((puVar7 != (ulonglong *)0x0) && (puVar7 != puVar8)) goto LAB_14001323a;
                }
                else if (puVar7 != (ulonglong *)0x0) {
                  puVar7 = (ulonglong *)((ulonglong)puVar7 ^ (ulonglong)puVar3);
                  goto LAB_140013228;
                }
                puVar8 = puVar3;
              } while( true );
            }
            if (((byte)puVar1[1] & 1) != 0) {
              puVar7 = (ulonglong *)((ulonglong)puVar8 ^ (ulonglong)puVar7);
            }
          }
          else if ((puVar1[1] & 1) != 0) {
            puVar7 = (ulonglong *)((ulonglong)puVar8 ^ (ulonglong)puVar7);
          }
LAB_14001323a:
          puVar6 = param_2;
          puVar8 = puVar7;
        }
      }
    }
  }
  else {
    *param_2 = 0;
  }
  return 0;
}



===== BfpExecuteCallbackOnVirtualizationRootNode @ 140013264 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int BfpExecuteCallbackOnVirtualizationRootNode
              (longlong param_1,longlong param_2,undefined *param_3,undefined8 param_4)

{
  ulonglong uVar1;
  bool bVar2;
  int iVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  ulonglong *puVar8;
  undefined2 uVar9;
  undefined1 uVar10;
  short local_48 [8];
  short *local_38;
  undefined8 uStack_30;
  
  local_48[0] = 0;
  local_48[1] = 0;
  local_48[2] = 0;
  local_48[3] = 0;
  local_48[4] = 0;
  local_48[5] = 0;
  local_48[6] = 0;
  local_48[7] = 0;
  uVar4 = BfWalkContainerRootId(param_2,local_48);
  puVar8 = *(ulonglong **)(param_1 + 0x18);
  if (local_48[0] == 0) {
    if (*(longlong *)(param_1 + 0x20) != 0) {
      iVar3 = (*(code *)param_3)(0,*(longlong *)(param_1 + 0x20) + 8,param_4);
      if ((iVar3 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,8,0x46,
                            &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                            "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",199,(char)iVar3);
      }
      *(undefined8 *)(param_1 + 0x20) = 0;
      return iVar3;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return -0x3ffffddb;
    }
    uVar9 = 0x45;
    uVar10 = 0xbe;
  }
  else {
    do {
      local_38 = local_48;
      puVar7 = (undefined8 *)*puVar8;
      uStack_30 = 0;
      if ((puVar8[1] & 1) != 0) {
        if (puVar7 == (undefined8 *)0x0) {
          puVar7 = (undefined8 *)0x0;
        }
        else {
          puVar7 = (undefined8 *)((ulonglong)puVar7 ^ (ulonglong)puVar8);
        }
      }
      uVar1 = puVar8[1];
      while (puVar7 != (undefined8 *)0x0) {
        uVar5 = BfpRBComparePathNodes(&local_38,(longlong)puVar7);
        if ((int)uVar5 < 0) {
          puVar6 = (undefined8 *)*puVar7;
        }
        else {
          if ((int)uVar5 < 1) break;
          puVar6 = (undefined8 *)puVar7[1];
        }
        if (((uVar1 & 1) == 0) || (puVar6 == (undefined8 *)0x0)) {
          puVar7 = puVar6;
        }
        else {
          puVar7 = (undefined8 *)((ulonglong)puVar7 ^ (ulonglong)puVar6);
        }
      }
      if (puVar7 == (undefined8 *)0x0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return -0x3ffffddb;
        }
        uVar9 = 0x49;
        uVar10 = 0x1b;
        goto LAB_14001352f;
      }
      if ((*(uint *)(puVar7 + -1) & 2) != 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,8,0x47,
                             &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                             "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",0xec);
        }
        return -0x3ffffff3;
      }
      if ((char)uVar4 == '\0') {
        if ((*(uint *)(puVar7 + -1) & 1) != 0) {
          iVar3 = (*(code *)param_3)(puVar8,puVar7,param_4);
          if (-1 < iVar3) {
            return iVar3;
          }
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return iVar3;
          }
          WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,8,0x4b,
                              &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                              "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",0x2e,(char)iVar3)
          ;
          return iVar3;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return -0x3ffffddb;
        }
        uVar9 = 0x4a;
        uVar10 = 0x22;
        goto LAB_14001352f;
      }
      uVar4 = BfWalkContainerRootId(param_2,local_48);
      puVar8 = (ulonglong *)puVar7[9];
      bVar2 = BfpPathTreeEmpty(puVar8);
    } while (!bVar2);
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return -0x3ffffddb;
    }
    uVar9 = 0x48;
    uVar10 = 0x12;
  }
LAB_14001352f:
  WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,8,uVar9,
                     &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                     "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",uVar10);
  return -0x3ffffddb;
}



===== BfpRemoveMapping @ 140013590 =====

undefined8 BfpRemoveMapping(longlong param_1,longlong param_2)

{
  ulonglong *puVar1;
  bool bVar2;
  ulonglong *puVar3;
  undefined8 uVar4;
  ulonglong *puVar5;
  byte bVar6;
  ulonglong *puVar7;
  char local_res10 [8];
  
  puVar1 = *(ulonglong **)(param_2 + 0x48);
  local_res10[0] = '\x01';
  bVar2 = BfpPathTreeEmpty(puVar1);
  if ((!bVar2) && (puVar7 = (ulonglong *)*puVar1, (ulonglong *)*puVar1 != (ulonglong *)0x0)) {
    while (uVar4 = BfpCanRemoveMapping((longlong)puVar7,local_res10), -1 < (int)uVar4) {
      puVar5 = (ulonglong *)*puVar7;
      if (puVar5 == (ulonglong *)0x0) {
        puVar5 = (ulonglong *)puVar7[1];
        if (puVar5 == (ulonglong *)0x0) {
          bVar6 = (byte)puVar1[1] & 1;
          do {
            puVar3 = (ulonglong *)(puVar7[2] & 0xfffffffffffffffc);
            if (bVar6 != 0) {
              if (puVar3 == (ulonglong *)0x0) goto LAB_1400136bc;
              puVar3 = (ulonglong *)((ulonglong)puVar3 ^ (ulonglong)puVar7);
            }
            if (puVar3 == (ulonglong *)0x0) goto LAB_1400136bc;
            puVar5 = (ulonglong *)puVar3[1];
            if (bVar6 == 0) {
LAB_140013695:
              if ((puVar5 != (ulonglong *)0x0) && (puVar5 != puVar7)) goto LAB_1400136a4;
            }
            else if (puVar5 != (ulonglong *)0x0) {
              puVar5 = (ulonglong *)((ulonglong)puVar5 ^ (ulonglong)puVar3);
              goto LAB_140013695;
            }
            puVar7 = puVar3;
          } while( true );
        }
        if (((byte)puVar1[1] & 1) == 0) {
          puVar7 = puVar5;
        }
        else {
          puVar7 = (ulonglong *)((ulonglong)puVar7 ^ (ulonglong)puVar5);
        }
      }
      else if ((puVar1[1] & 1) == 0) {
LAB_1400136a4:
        puVar7 = puVar5;
      }
      else {
        puVar7 = (ulonglong *)((ulonglong)puVar7 ^ (ulonglong)puVar5);
      }
    }
LAB_1400136bc:
    if (local_res10[0] == '\0') {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,8,0x1a,
                           &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                           "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",0x24);
      }
      return 0xc0000022;
    }
  }
  if (*(longlong *)(param_2 + 0x50) != 0) {
    if (param_1 != 0) {
      RtlRbRemoveNode(param_1,*(longlong *)(param_2 + 0x50) + 8);
    }
    BfpDeletePathTierNode(*(uint **)(param_2 + 0x50));
  }
  if (param_1 != 0) {
    RtlRbRemoveNode(param_1,param_2);
  }
  BfpDeletePathTierNode((uint *)(param_2 + -8));
  return 0;
}



===== BfFltUnload @ 140013730 =====

undefined8 BfFltUnload(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  ulonglong uVar1;
  
  ExAcquireFastMutex(&DAT_14000d248);
  DAT_14000d280 = 1;
  ExReleaseFastMutex(&DAT_14000d248);
  BfCleanupUserList(&DAT_14000d298);
  ExDeleteResourceLite(&DAT_14000d2a8);
  ExDeletePagedLookasideList(&DAT_14000d340);
  ExDeleteNPagedLookasideList(&DAT_14000d3c0);
  ExDeletePagedLookasideList(&DAT_14000d440);
  ExDeletePagedLookasideList(&DAT_14000d4c0);
  ExDeletePagedLookasideList(&DAT_14000d540);
  ExDeletePagedLookasideList(&DAT_14000d5c0);
  FltCloseCommunicationPort(DAT_14000d288);
  FltUnregisterFilter(g_BindFltState);
  uVar1 = (ulonglong)DAT_14000d290;
  PsFreeSiloContextSlot();
  if ((Microsoft_Windows_Containers_BindFltEnableBits & 2) != 0) {
    McTemplateK0_EtwWriteTransfer(uVar1,&BindFltUnloadSuccessful,param_3);
  }
  McGenEventUnregister_EtwUnregister();
  BfTelemetryAndTracingCleanup();
  wil_UninitializeFeatureStaging();
  return 0;
}



===== BfPreQuerySetQuota @ 140013860 =====

undefined8 BfPreQuerySetQuota(longlong param_1,longlong param_2)

{
  int extraout_EAX;
  int iVar1;
  longlong lVar2;
  char local_res20 [8];
  
  local_res20[0] = '\0';
  iVar1 = BfCheckAndSwitchTarget(param_1,param_2,(longlong *)0x0,local_res20);
  lVar2 = CONCAT44((int)((ulonglong)param_1 >> 0x20),iVar1);
  if (extraout_EAX < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,4,0xf,
                          &WPP_59754cb100fb33f1965e7b014742173a_Traceguids,
                          "onecore\\base\\fs\\wci\\bindflt\\filter\\bindflt.c",0x84,
                          (char)extraout_EAX);
    }
  }
  else if (local_res20[0] != '\0') {
    *(undefined8 *)(lVar2 + 0x20) = 0;
    *(undefined4 *)(lVar2 + 0x18) = 0xc0000022;
    return 4;
  }
  return 1;
}



===== wil_UninitializeFeatureStaging @ 1400138fc =====

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



===== wil_details_BuildFeatureStateCacheFromQueryResults @ 140013954 =====

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
      goto LAB_1400139b1;
    }
    if (param_1 == 0x117) {
      uVar1 = (*(uint *)(param_2 + 4) & 0x80) << 3 | 0x206;
      goto LAB_1400139b1;
    }
  }
  uVar1 = 0x206;
LAB_1400139b1:
  *param_3 = uVar1;
  return;
}



===== wil_details_EvaluateFeatureDependencies @ 1400139bc =====

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



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 140013a74 =====

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



===== wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState @ 140013aac =====

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
        if (puVar1 == (undefined8 *)0x0) goto LAB_140013b2e;
        if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
           (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
        if ((uVar5 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
          uVar5 = 0;
          goto LAB_140013b2e;
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
LAB_140013b2e:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 140013b80 =====

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



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 140013be0 =====

void wil_details_ReevaluateOnFeatureConfigurationChange(void)

{
  wil_details_UpdateFeatureConfiguredStates();
  wil_details_EvaluateFeatureDependencies();
  return;
}



===== wil_details_UpdateFeatureConfiguredStates @ 140013bfc =====

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



===== BfTelemetryAndTracingCleanup @ 140013cb0 =====

void BfTelemetryAndTracingCleanup(void)

{
  undefined8 uVar1;
  
  uVar1 = DAT_14000d078;
  DAT_14000d078 = 0;
  DAT_14000d058._0_4_ = 0;
  EtwUnregister(uVar1);
  imp_WppRecorderLogDelete(WPP_GLOBAL_Control,_BfTraceRecorder);
  WppCleanupKm();
  return;
}



===== TraceLoggingRegisterEx_EtwRegister_EtwSetInformation @ 140013d04 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

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
  local_28 = *(undefined4 *)(PTR_DAT_14000d060 + -0x10);
  uStack_24 = *(undefined4 *)(PTR_DAT_14000d060 + -0xc);
  uStack_20 = *(undefined4 *)(PTR_DAT_14000d060 + -8);
  uStack_1c = *(undefined4 *)(PTR_DAT_14000d060 + -4);
  if (DAT_14000d078 != 0) {
    pcVar2 = (code *)swi(0x29);
    (*pcVar2)(5);
    puVar4 = auStack_40;
  }
  DAT_14000d080 = 0;
  DAT_14000d088 = 0;
  *(undefined8 *)(puVar4 + -8) = 0x140013d67;
  iVar3 = EtwRegister(puVar4 + 0x20,_tlgEnableCallback,&DAT_14000d058,&DAT_14000d078);
  if (iVar3 == 0) {
    uVar1 = *(undefined2 *)PTR_DAT_14000d060;
    *(undefined8 *)(puVar4 + -8) = 0x140013d8e;
    EtwSetInformation(DAT_14000d078,2,PTR_DAT_14000d060,uVar1);
  }
  *(undefined8 *)(puVar4 + -8) = 0x140013da2;
  return iVar3;
}



===== WppCleanupKm @ 140013db0 =====

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
    WppAutoLogStop(WPP_GLOBAL_Control,0);
    WPP_GLOBAL_Control = (undefined *)&WPP_GLOBAL_Control;
    WPP_RECORDER_INITIALIZED = (undefined *)&WPP_RECORDER_INITIALIZED;
  }
  return;
}



===== WppInitKm @ 140013e54 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void WppInitKm(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  undefined *puVar2;
  
  if (WPP_GLOBAL_Control != &WPP_MAIN_CB) {
    WPP_GLOBAL_Control = &WPP_MAIN_CB;
    if (WPPTraceSuite == 4) {
      puVar2 = &WPP_MAIN_CB;
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
    WppAutoLogStart(WPP_GLOBAL_Control,param_1,param_2);
    WPP_RECORDER_INITIALIZED = &WPP_MAIN_CB;
  }
  return;
}



===== WppLoadTracingSupport @ 140013f30 =====

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



===== WppTraceCallback @ 140014080 =====

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



===== BfFillOutEcpFields @ 140014308 =====

void BfFillOutEcpFields(longlong param_1,longlong param_2,longlong param_3)

{
  undefined4 uVar1;
  undefined8 uVar2;
  
  uVar2 = PsGetCurrentProcess();
  uVar1 = PsGetProcessId(uVar2);
  *(undefined4 *)(param_1 + 0x18) = uVar1;
  uVar2 = PsGetCurrentProcess();
  uVar1 = PsGetProcessSessionId(uVar2);
  *(undefined4 *)(param_1 + 0x1c) = uVar1;
  *(undefined8 *)(param_1 + 0x20) = *(undefined8 *)(param_2 + 0x2c8);
  *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(param_2 + 0x7a8);
  *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(param_2 + 0x7ac);
  *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(param_2 + 0x128);
  *(undefined1 *)(param_1 + 0x34) = *(undefined1 *)(param_2 + 0x7b0);
  *(undefined1 *)(param_1 + 0x38) = *(undefined1 *)(param_3 + 0x280);
  *(undefined1 *)(param_1 + 0x39) = *(undefined1 *)(param_3 + 0x281);
  return;
}



===== BfGetProcessParameters @ 1400143b4 =====

undefined8 BfGetProcessParameters(longlong param_1,ulonglong *param_2)

{
  ulonglong uVar1;
  
  uVar1 = *(ulonglong *)(param_1 + 0x20);
  *param_2 = uVar1;
  if ((uVar1 & 3) != 0) {
                    /* WARNING: Subroutine does not return */
    ExRaiseDatatypeMisalignment();
  }
  return 0;
}



===== BfQueryPackageIdentity @ 140014400 =====

undefined4
BfQueryPackageIdentity
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
          undefined8 param_5)

{
  undefined4 uVar1;
  longlong lVar2;
  
  lVar2 = PsReferencePrimaryToken();
  if (lVar2 == 0) {
    uVar1 = 0xc0000001;
  }
  else {
    uVar1 = RtlQueryPackageIdentity(lVar2,param_2,param_3,param_4,param_5,0);
    PsDereferencePrimaryToken(lVar2);
  }
  return uVar1;
}



===== BfAddCloudFileECPs @ 140014490 =====

ulonglong BfAddCloudFileECPs(longlong param_1,longlong param_2,longlong param_3,undefined1 *param_4,
                            undefined1 *param_5,undefined1 *param_6)

{
  longlong *plVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined2 uVar4;
  undefined1 uVar5;
  
  plVar1 = (longlong *)(param_3 + 8);
  if (*plVar1 == 0) {
    uVar2 = FltAllocateExtraCreateParameterList(*(undefined8 *)(param_2 + 8),0,plVar1);
    if ((int)uVar2 < 0) {
      return (ulonglong)uVar2;
    }
    *param_4 = 1;
  }
  uVar2 = BfAttachRedirHandleCollapseEcp(param_2,*plVar1,param_5);
  uVar3 = (ulonglong)uVar2;
  if ((int)uVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return uVar3;
    }
    uVar4 = 10;
    uVar5 = 0xa5;
  }
  else {
    uVar3 = BfAttachAttributionInformationEcp(param_1,param_2,*plVar1,param_6);
    uVar2 = (uint)uVar3;
    uVar3 = uVar3 & 0xffffffff;
    if (-1 < (int)uVar2) {
      return uVar3;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return uVar3;
    }
    uVar4 = 0xb;
    uVar5 = 0xb0;
  }
  WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,uVar4,
                      &WPP_ad24bb045f593b9ce950612e8c87293a_Traceguids,
                      "onecore\\base\\fs\\wci\\bindflt\\filter\\sfo.c",uVar5,(char)uVar2);
  return uVar3;
}



===== BfAttachAttributionInformationEcp @ 1400145a8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong BfAttachAttributionInformationEcp
                    (longlong param_1,longlong param_2,undefined8 param_3,undefined1 *param_4)

{
  ushort *puVar1;
  ushort *puVar2;
  longlong lVar3;
  void *_Src;
  void *_Src_00;
  ulonglong _Size;
  uint uVar4;
  int iVar5;
  longlong lVar6;
  longlong lVar7;
  longlong lVar8;
  ulonglong uVar9;
  short sVar10;
  undefined1 auStackY_258 [32];
  uint *local_218;
  uint local_210;
  uint local_20c;
  ulonglong local_208;
  ulonglong local_200;
  ulonglong local_1f8;
  ulonglong local_1f0;
  undefined8 local_1e8;
  longlong local_1e0;
  undefined1 local_1d8 [144];
  undefined1 local_148 [256];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_258;
  local_218 = (uint *)0x0;
  local_210 = 0;
  lVar7 = 0;
  lVar8 = 0;
  local_1f8 = 0;
  local_208 = 0x100;
  local_200 = 0x84;
  *param_4 = 0;
  local_1e8 = param_3;
  local_1e0 = param_2;
  uVar4 = FltFindExtraCreateParameter
                    (*(undefined8 *)(param_2 + 8),param_3,&GUID_ECP_CLOUDFILES_ATTRIBUTION,
                     &local_218);
  uVar9 = (ulonglong)uVar4;
  if (uVar4 == 0xc0000225) {
    lVar6 = FltGetRequestorProcess(param_1);
    lVar3 = *(longlong *)(param_1 + 8);
    if ((lVar6 != 0) && (lVar3 != 0)) {
      lVar7 = PsGetProcessPeb(lVar6);
      lVar8 = PsGetThreadTeb(lVar3);
    }
    if ((lVar7 == 0) || (lVar8 == 0)) {
      uVar9 = 0;
    }
    else {
      iVar5 = BfQueryPackageIdentity(lVar6,local_148,&local_208,local_1d8,&local_200);
      if (iVar5 < 0) {
        local_208 = 0;
        local_200 = 0;
      }
      local_210 = 0x50;
      uVar9 = Feature_ProbeForReadProcessParameters__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar9 == 0) {
        local_1f8 = *(ulonglong *)(lVar7 + 0x20);
      }
      else {
        uVar9 = BfGetProcessParameters(lVar7,&local_1f8);
        local_20c = (uint)uVar9;
        if ((int)local_20c < 0) {
          return uVar9 & 0xffffffff;
        }
      }
      puVar1 = (ushort *)(local_1f8 + 0x60);
      puVar2 = (ushort *)(local_1f8 + 0x70);
      _Src = *(void **)(local_1f8 + 0x68);
      _Src_00 = *(void **)(local_1f8 + 0x78);
      local_1f8 = (ulonglong)*puVar2;
      local_1f0 = (ulonglong)*puVar1;
      local_210 = (int)local_208 + *puVar2 + local_210 + (uint)*puVar1 + (int)local_200 + 8;
      local_20c = FltAllocateExtraCreateParameter
                            (*(undefined8 *)(param_2 + 8),&GUID_ECP_CLOUDFILES_ATTRIBUTION,local_210
                             ,0);
      uVar9 = (ulonglong)local_20c;
      if (-1 < (int)local_20c) {
        memset(local_218,0,(ulonglong)local_210);
        *local_218 = local_210;
        BfFillOutEcpFields((longlong)local_218,lVar7,lVar8);
        _Size = local_1f0;
        uVar9 = local_1f8;
        *(undefined2 *)((longlong)local_218 + 0x3a) = 0;
        sVar10 = (short)(local_1f8 >> 1);
        *(short *)(local_218 + 0xf) = sVar10;
        *(short *)((longlong)local_218 + 0x3e) = sVar10 + 1;
        sVar10 = (short)(local_1f0 >> 1);
        *(short *)(local_218 + 0x10) = sVar10;
        *(short *)((longlong)local_218 + 0x42) = sVar10 + *(short *)((longlong)local_218 + 0x3e) + 1
        ;
        sVar10 = (short)(local_208 >> 1);
        *(short *)(local_218 + 0x11) = sVar10;
        *(short *)((longlong)local_218 + 0x46) = sVar10 + *(short *)((longlong)local_218 + 0x42) + 1
        ;
        *(short *)(local_218 + 0x12) = (short)(local_200 >> 1);
        ProbeForRead(_Src_00,local_1f8,2);
        ProbeForRead(_Src,_Size,2);
        memmove((void *)((longlong)local_218 +
                        (ulonglong)*(ushort *)((longlong)local_218 + 0x3a) * 2 + 0x4a),_Src_00,uVar9
               );
        memmove((void *)((longlong)local_218 +
                        (ulonglong)*(ushort *)((longlong)local_218 + 0x3e) * 2 + 0x4a),_Src,_Size);
        memmove((void *)((longlong)local_218 +
                        (ulonglong)*(ushort *)((longlong)local_218 + 0x42) * 2 + 0x4a),local_148,
                local_208);
        memmove((void *)((longlong)local_218 +
                        (ulonglong)*(ushort *)((longlong)local_218 + 0x46) * 2 + 0x4a),local_1d8,
                local_200);
        uVar4 = FltInsertExtraCreateParameter(*(undefined8 *)(param_2 + 8),local_1e8,local_218);
        uVar9 = (ulonglong)uVar4;
        if ((int)uVar4 < 0) {
          FltFreeExtraCreateParameter(*(undefined8 *)(param_2 + 8),local_218);
        }
        else {
          *param_4 = 1;
        }
      }
    }
  }
  return uVar9;
}



===== BfAttachRedirHandleCollapseEcp @ 140014998 =====

int BfAttachRedirHandleCollapseEcp(longlong param_1,undefined8 param_2,undefined1 *param_3)

{
  int iVar1;
  undefined4 local_res8 [2];
  undefined8 *local_res18 [2];
  
  *param_3 = 0;
  local_res18[0] = (undefined8 *)0x0;
  local_res8[0] = 0;
  iVar1 = FltFindExtraCreateParameter
                    (*(undefined8 *)(param_1 + 8),param_2,&GUID_ECP_NETWORK_OPEN_CONTEXT,local_res18
                     ,local_res8);
  if (iVar1 == -0x3ffffddb) {
    iVar1 = FltAllocateExtraCreateParameter
                      (*(undefined8 *)(param_1 + 8),&GUID_ECP_NETWORK_OPEN_CONTEXT,0x1c,0,0,
                       0x68634642,local_res18);
    if (iVar1 < 0) {
      return iVar1;
    }
    *local_res18[0] = 0;
    local_res18[0][1] = 0;
    local_res18[0][2] = 0;
    *(undefined4 *)(local_res18[0] + 3) = 0;
    *(undefined2 *)local_res18[0] = 0x1c;
    *(undefined2 *)((longlong)local_res18[0] + 2) = 0;
    iVar1 = FltInsertExtraCreateParameter(*(undefined8 *)(param_1 + 8),param_2,local_res18[0]);
    if (iVar1 < 0) {
      FltFreeExtraCreateParameter(*(undefined8 *)(param_1 + 8),local_res18[0]);
      return iVar1;
    }
    *param_3 = 1;
  }
  else if (iVar1 < 0) {
    return iVar1;
  }
  *(uint *)((longlong)local_res18[0] + 0xc) = *(uint *)((longlong)local_res18[0] + 0xc) | 1;
  return iVar1;
}



===== BfRemoveEcp @ 140014ad0 =====

int BfRemoveEcp(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined4 local_res8 [2];
  undefined8 local_res20;
  
  local_res20 = 0;
  local_res8[0] = 0;
  iVar1 = FltRemoveExtraCreateParameter
                    (*(undefined8 *)(param_1 + 8),param_2,param_3,&local_res20,local_res8);
  if (-1 < iVar1) {
    FltFreeExtraCreateParameter(*(undefined8 *)(param_1 + 8),local_res20);
  }
  return iVar1;
}



===== BfCleanupUserList @ 140014b34 =====

void BfCleanupUserList(longlong *param_1)

{
  longlong *plVar1;
  undefined8 *puVar2;
  code *pcVar3;
  undefined1 *puVar4;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  FltAcquireResourceExclusive(&DAT_14000d2a8);
  puVar4 = auStack_28;
  do {
    if ((longlong *)*param_1 == param_1) {
LAB_140014bc2:
      *(undefined8 *)(puVar4 + -8) = 0x140014bd0;
      FltReleaseResource(&DAT_14000d2a8);
      return;
    }
    plVar1 = (longlong *)param_1[1];
    if (((longlong *)*plVar1 != param_1) ||
       (puVar2 = (undefined8 *)plVar1[1], (longlong *)*puVar2 != plVar1)) {
      pcVar3 = (code *)swi(0x29);
      (*pcVar3)(3);
      puVar4 = auStack_20;
      goto LAB_140014bc2;
    }
    param_1[1] = (longlong)puVar2;
    *puVar2 = param_1;
    BfCleanupMappingContext((longlong *)plVar1[3]);
    ExFreePoolWithTag(plVar1[3],0x636d4642);
    ExFreePoolWithTag(plVar1[2],0x73754642);
    ExFreePoolWithTag(plVar1,0x73754642);
  } while( true );
}



===== BfGetOrCreateUser @ 140014be8 =====

ulonglong BfGetOrCreateUser(undefined8 param_1,undefined8 *param_2)

{
  code *pcVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  longlong lVar7;
  undefined8 *puVar8;
  ulonglong uVar9;
  undefined8 *puVar10;
  ulonglong uVar11;
  undefined1 *puVar12;
  undefined1 *puVar13;
  undefined1 auStack_58 [8];
  undefined1 auStack_50 [24];
  uint local_38;
  longlong local_30;
  
  puVar8 = (undefined8 *)0x0;
  local_30 = 0;
  bVar2 = false;
  cVar3 = ExGetPreviousMode();
  if (cVar3 == '\x01') {
    ProbeForRead(param_1,0xc,1);
  }
  iVar4 = RtlLengthSid(param_1);
  lVar7 = ExAllocatePool2(0x100,iVar4,0x73754642);
  local_30 = lVar7;
  if (lVar7 == 0) {
    uVar11 = 0xc000009a;
    local_38 = 0xc000009a;
    puVar13 = auStack_58;
  }
  else {
    uVar5 = RtlCopySid(iVar4,lVar7,param_1);
    uVar11 = (ulonglong)uVar5;
    local_38 = uVar5;
    iVar6 = RtlLengthSid(lVar7);
    if (iVar6 == iVar4) {
      puVar13 = auStack_58;
      if (-1 < (int)uVar5) {
        cVar3 = RtlValidSid(lVar7);
        if (cVar3 == '\0') {
          uVar11 = 0xc000000d;
          puVar13 = auStack_58;
        }
        else {
          FltAcquireResourceExclusive(&DAT_14000d2a8);
          puVar12 = auStack_58;
          bVar2 = true;
          for (puVar10 = DAT_14000d298; (undefined8 **)puVar10 != &DAT_14000d298;
              puVar10 = (undefined8 *)*puVar10) {
            cVar3 = RtlEqualSid(puVar10[2],lVar7);
            if (cVar3 != '\0') {
              *param_2 = puVar10;
              puVar13 = auStack_58;
              goto LAB_140014db3;
            }
          }
          puVar8 = (undefined8 *)ExAllocatePool2(0x100,0x20,0x73754642);
          if (puVar8 == (undefined8 *)0x0) {
            uVar11 = 0xc000009a;
            puVar13 = auStack_58;
          }
          else {
            puVar8[2] = lVar7;
            lVar7 = 0;
            uVar9 = BfInitializeMappingContext(puVar8 + 3);
            uVar11 = uVar9 & 0xffffffff;
            puVar13 = auStack_58;
            if (-1 < (int)uVar9) {
              puVar10 = &DAT_14000d298;
              if ((undefined8 **)DAT_14000d298[1] != &DAT_14000d298) {
                puVar10 = (undefined8 *)0x3;
                pcVar1 = (code *)swi(0x29);
                DAT_14000d298 = (undefined8 *)(*pcVar1)();
                puVar12 = auStack_50;
              }
              *puVar8 = DAT_14000d298;
              puVar8[1] = puVar10;
              DAT_14000d298[1] = puVar8;
              DAT_14000d298 = puVar8;
              *param_2 = puVar8;
              puVar8 = (undefined8 *)0x0;
              puVar13 = puVar12;
            }
          }
        }
      }
    }
    else {
      uVar11 = 0xc000000d;
      local_38 = 0xc000000d;
      puVar13 = auStack_58;
    }
  }
LAB_140014db3:
  if (bVar2) {
    *(undefined8 *)(puVar13 + -8) = 0x140014dc6;
    FltReleaseResource(&DAT_14000d2a8);
  }
  if (puVar8 != (undefined8 *)0x0) {
    *(undefined8 *)(puVar13 + -8) = 0x140014ddf;
    ExFreePoolWithTag(puVar8,0x73754642);
  }
  if (lVar7 != 0) {
    *(undefined8 *)(puVar13 + -8) = 0x140014df8;
    ExFreePoolWithTag(lVar7,0x73754642);
  }
  return uVar11;
}



===== BfpValidateMappingExceptions @ 140014e20 =====

ulonglong BfpValidateMappingExceptions
                    (ushort *param_1,uint param_2,longlong param_3,longlong *param_4)

{
  uint uVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  longlong lVar5;
  ulonglong uVar6;
  ushort *puVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  longlong lVar10;
  ulonglong uVar11;
  wchar_t wVar12;
  undefined2 uVar13;
  uint uVar14;
  longlong lVar15;
  longlong lVar16;
  ulonglong in_stack_ffffffffffffff78;
  undefined8 in_stack_ffffffffffffff80;
  undefined1 uVar17;
  undefined1 uVar18;
  wchar_t local_58;
  short sStack_56;
  undefined4 uStack_54;
  ulonglong uStack_50;
  undefined8 local_48;
  longlong lStack_40;
  
  _local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  lStack_40 = 0;
  lVar5 = ExAllocatePool2(0x100,(ulonglong)*(uint *)(param_1 + 2) << 3,0x706d4642);
  if (lVar5 == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,0x1b,
                          &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                          "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",0x75,
                          (char)(*(int *)(param_1 + 2) << 3));
    }
    return 0xc000009a;
  }
  if ((ulonglong)*(uint *)(param_1 + 2) * 8 < 0x100000000) {
    uVar3 = (int)((ulonglong)*(uint *)(param_1 + 2) * 8) + 0x38;
    if (0x37 < uVar3) {
      if (uVar3 <= param_2) {
        sVar2 = *(short *)(param_3 + 4) - *(ushort *)(param_3 + 2);
        uVar11 = 0;
        _local_58 = CONCAT22(sVar2,sVar2);
        uStack_50 = param_3 + 6 + (ulonglong)(*(ushort *)(param_3 + 2) >> 1) * 2;
        uVar3 = 0x38;
        do {
          if (*(uint *)(param_1 + 2) <= (uint)uVar11) {
            *param_4 = lVar5;
            return 0;
          }
          uVar1 = *(uint *)(param_1 + uVar11 * 4 + 0x1c);
          uVar14 = param_1[uVar11 * 4 + 0x1e] + uVar1;
          if (uVar14 < uVar1) {
            uVar9 = 0xc0000095;
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar18 = 0x95;
              uVar13 = 0x1f;
              uVar17 = 0xad;
              goto LAB_1400152d9;
            }
            goto LAB_140015063;
          }
          if (param_2 < uVar14) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar13 = 0x20;
              uVar18 = 0xb3;
LAB_140015275:
              WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,uVar13,
                                  &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                                  "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",uVar18,
                                  (char)uVar11);
            }
            goto LAB_140015170;
          }
          if (uVar1 < uVar3) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar13 = 0x21;
              uVar18 = 0xc1;
              goto LAB_140015275;
            }
            goto LAB_140015170;
          }
          puVar7 = (ushort *)((ulonglong)uVar1 + (longlong)param_1);
          if (puVar7 < param_1) {
            uVar9 = 0xc0000095;
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar18 = 0x95;
              uVar13 = 0x22;
              uVar17 = 0xd1;
LAB_1400152d9:
              WPP_RECORDER_SF_sDdd
                        (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,uVar13,
                         &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                         "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",uVar17,(char)uVar11,
                         uVar18);
            }
            goto LAB_140015063;
          }
          *(ushort **)(lVar5 + uVar11 * 8) = puVar7;
          uVar8 = (ulonglong)param_1[uVar11 * 4 + 0x1e];
          uVar6 = BfValidateContainerRootId(puVar7,(uint)param_1[uVar11 * 4 + 0x1e]);
          uVar9 = uVar6 & 0xffffffff;
          if ((int)uVar6 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar18 = (undefined1)uVar6;
              uVar13 = 0x23;
              uVar17 = 0xdc;
              goto LAB_1400152d9;
            }
            goto LAB_140015063;
          }
          lVar10 = *(longlong *)(lVar5 + uVar11 * 8);
          wVar12 = *(short *)(lVar10 + 4) - *(short *)(lVar10 + 2);
          uVar9 = (ulonglong)(ushort)wVar12;
          local_48._0_4_ = CONCAT22(wVar12,wVar12);
          lVar10 = *(longlong *)(lVar5 + uVar11 * 8);
          lVar10 = lVar10 + ((ulonglong)(*(ushort *)(lVar10 + 2) >> 1) + 3) * 2;
          lStack_40 = lVar10;
          if ((ushort)wVar12 <= (ushort)local_58) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_sDZZ
                        (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar8,uVar9,0x24,
                         in_stack_ffffffffffffff78,in_stack_ffffffffffffff80,0xf0,
                         (wchar_t *)&local_48,&local_58);
            }
            goto LAB_140015170;
          }
          lVar15 = 0;
          if ((ushort)local_58 <= (ushort)wVar12) {
            lVar16 = 0;
            while (uVar8 = (ulonglong)(ushort)local_58, uVar8 <= uVar9 - lVar16) {
              uVar8 = (ulonglong)((ushort)local_58 >> 1);
              in_stack_ffffffffffffff78 = in_stack_ffffffffffffff78 & 0xffffffffffffff00;
              uVar9 = uStack_50;
              iVar4 = RtlCompareUnicodeStrings(lVar10,uVar8,uStack_50,uVar8);
              if (iVar4 == 0) {
                lVar15 = lVar10;
                break;
              }
              lVar16 = lVar16 + 2;
              uVar9 = local_48 & 0xffff;
              lVar10 = lVar10 + 2;
            }
          }
          if (lVar15 != lStack_40) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_sDZZ
                        (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar8,uVar9,0x25,
                         in_stack_ffffffffffffff78,in_stack_ffffffffffffff80,3,&local_58,
                         (wchar_t *)&local_48);
            }
            uVar9 = 0xc000000d;
            goto LAB_140015063;
          }
          uVar11 = (ulonglong)((uint)uVar11 + 1);
          uVar3 = uVar14;
        } while( true );
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,0x1e,
                           &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                           "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",0x93);
      }
LAB_140015170:
      uVar9 = 0xc000000d;
      goto LAB_140015063;
    }
    uVar9 = 0xc0000095;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140015063;
    uVar13 = 0x1d;
    uVar18 = 0x8d;
  }
  else {
    uVar9 = 0xc0000095;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140015063;
    uVar13 = 0x1c;
    uVar18 = 0x85;
  }
  uVar9 = 0xc0000095;
  WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,uVar13,
                      &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                      "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",uVar18,0x95);
LAB_140015063:
  ExFreePoolWithTag(lVar5,0x706d4642);
  return uVar9;
}



===== BfpMappingInsertExceptions @ 140015344 =====

int BfpMappingInsertExceptions
              (longlong *param_1,longlong param_2,undefined8 *param_3,uint param_4,longlong param_5)

{
  longlong lVar1;
  bool bVar2;
  ushort uVar3;
  short sVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  undefined8 uVar10;
  ulonglong uVar11;
  undefined8 uVar12;
  ulonglong *puVar13;
  ushort uVar14;
  short *psVar15;
  undefined8 *puVar16;
  undefined8 *puVar17;
  ulonglong *puVar18;
  ulonglong *puVar19;
  ushort uVar20;
  ulonglong uVar21;
  uint7 uVar22;
  undefined2 uVar23;
  uint uVar24;
  undefined1 uVar25;
  undefined1 uVar26;
  char local_d8;
  ushort local_d6;
  ushort local_d4;
  longlong local_c8;
  short *local_c0;
  undefined8 uStack_b8;
  short local_b0 [8];
  short *local_a0;
  ulonglong uStack_98;
  ushort local_90 [4];
  longlong lStack_88;
  short local_80 [12];
  longlong lStack_68;
  longlong local_60;
  ulonglong local_58;
  
  local_60 = 0;
  local_b0[0] = 0;
  local_b0[1] = 0;
  local_b0[2] = 0;
  local_b0[3] = 0;
  local_b0[4] = 0;
  local_b0[5] = 0;
  local_b0[6] = 0;
  local_b0[7] = 0;
  iVar5 = 0;
  local_80[0] = 0;
  local_80[1] = 0;
  local_80[2] = 0;
  local_80[3] = 0;
  local_80[4] = 0;
  local_80[5] = 0;
  local_80[6] = 0;
  local_80[7] = 0;
  uVar3 = *(ushort *)(*param_1 + 4) >> 1;
  local_d6 = 0;
  local_d4 = 0;
  local_90[0] = 0;
  local_90[1] = 0;
  local_90[2] = 0;
  local_90[3] = 0;
  lStack_88 = 0;
  local_80[8] = 0;
  local_80[9] = 0;
  local_80[10] = 0;
  local_80[0xb] = 0;
  lStack_68 = 0;
  if (uVar3 != 0) {
    psVar15 = (short *)(*param_1 + 6);
    uVar21 = (ulonglong)uVar3;
    uVar14 = 0;
    do {
      sVar4 = *psVar15;
      psVar15 = psVar15 + 1;
      local_d6 = uVar14 + 1;
      if (sVar4 != 0x5c) {
        local_d6 = uVar14;
      }
      uVar21 = uVar21 - 1;
      uVar14 = local_d6;
    } while (uVar21 != 0);
    local_d4 = uVar3;
  }
  uVar7 = 0;
LAB_1400153ec:
  local_c8 = 0;
  if (param_4 <= uVar7) {
    return iVar5;
  }
  uVar21 = (ulonglong)uVar7;
  local_58 = uVar21;
  psVar15 = BfConvertContainerRootIdToShortNames(*(ushort **)(param_5 + uVar21 * 8),&local_c8);
  iVar5 = (int)psVar15;
  if (iVar5 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400158d3;
    uVar26 = SUB81(psVar15,0);
    uVar23 = 0x37;
    uVar25 = 0x7e;
  }
  else {
    lStack_88 = *(longlong *)(param_5 + uVar21 * 8);
    sVar4 = *(short *)(lStack_88 + 4) - *(short *)(*param_1 + 4);
    uVar20 = *(ushort *)(local_c8 + 4) >> 1;
    local_90[1] = sVar4;
    local_90[0] = sVar4;
    lStack_88 = lStack_88 + ((ulonglong)local_d4 + 3) * 2;
    uVar14 = 0;
    uVar3 = 0;
    if (uVar20 != 0) {
      do {
        if ((*(short *)(local_c8 + 6 + (ulonglong)uVar3 * 2) == 0x5c) &&
           (uVar14 = uVar14 + 1, local_d6 < uVar14)) break;
        uVar3 = uVar3 + 1;
      } while (uVar3 < uVar20);
      uVar21 = local_58;
    }
    sVar4 = *(ushort *)(local_c8 + 4) + uVar3 * -2;
    local_80[9] = sVar4;
    local_80[8] = sVar4;
    lStack_68 = local_c8 + 6 + (ulonglong)uVar3 * 2;
    uVar8 = BfpWalkPath(local_90,0,local_b0);
    local_d8 = (char)uVar8;
    psVar15 = local_80;
    uVar8 = uVar8 & 0xff;
    BfpWalkPath((ushort *)(local_80 + 8),0,psVar15);
    puVar18 = *(ulonglong **)(param_2 + 0x50);
    do {
      local_c0 = local_b0;
      puVar16 = (undefined8 *)*puVar18;
      uStack_b8 = 0;
      if ((puVar18[1] & 1) != 0) {
        if (puVar16 == (undefined8 *)0x0) {
          puVar16 = (undefined8 *)0x0;
        }
        else {
          puVar16 = (undefined8 *)((ulonglong)puVar16 ^ (ulonglong)puVar18);
        }
      }
      uVar11 = puVar18[1];
      if (puVar16 == (undefined8 *)0x0) goto LAB_1400155f5;
      do {
        uVar9 = BfpRBComparePathNodes(&local_c0,(longlong)puVar16);
        if ((int)uVar9 < 0) {
          puVar17 = (undefined8 *)*puVar16;
        }
        else {
          puVar17 = puVar16;
          if ((int)uVar9 < 1) break;
          puVar17 = (undefined8 *)puVar16[1];
        }
        if (((uVar11 & 1) != 0) && (puVar17 != (undefined8 *)0x0)) {
          puVar17 = (undefined8 *)((ulonglong)puVar16 ^ (ulonglong)puVar17);
        }
        puVar16 = puVar17;
      } while (puVar17 != (undefined8 *)0x0);
      if (puVar17 == (undefined8 *)0x0) goto LAB_1400155f5;
      if ((*(uint *)(puVar17 + -1) & 2) != 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400158ce;
        uVar23 = 0x38;
        uVar26 = 0xc9;
        goto LAB_140015a94;
      }
      if ((char)uVar8 == '\0') {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400158ce;
        uVar23 = 0x39;
        uVar26 = 0xd7;
        goto LAB_140015a94;
      }
      uVar8 = BfpWalkPath(local_90,0,local_b0);
      local_d8 = (char)uVar8;
      psVar15 = local_80;
      uVar8 = uVar8 & 0xff;
      BfpWalkPath((ushort *)(local_80 + 8),0,psVar15);
      puVar16 = puVar17 + 9;
      puVar18 = (ulonglong *)*puVar16;
      bVar2 = BfpPathTreeEmpty(puVar18);
    } while (!bVar2);
    if ((*(uint *)(puVar17 + -1) & 1) == 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar23 = 0x3a;
        uVar26 = 0xfa;
LAB_140015a94:
        WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,8,uVar23,
                           &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                           "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",uVar26);
      }
LAB_1400158ce:
      iVar5 = -0x3ffffff3;
      goto LAB_1400158d3;
    }
    if (puVar18 != (ulonglong *)0x0) {
LAB_1400155f2:
      puVar18 = (ulonglong *)*puVar16;
LAB_1400155f5:
      local_c0 = (short *)0x0;
LAB_1400155fc:
      uVar22 = (uint7)((ulonglong)psVar15 >> 8);
      uVar24 = ~-(uint)((char)uVar8 != '\0') & 4;
      local_a0 = (short *)0x0;
      uStack_98 = 0;
      uVar21 = BfpCreatePathTierNode
                         ((longlong)local_b0,uVar24,(char)uVar8,0,param_3,
                          *(longlong *)(param_5 + uVar21 * 8),(longlong *)0x0,0,&local_c0);
      psVar15 = local_c0;
      iVar5 = (int)uVar21;
      if (-1 < iVar5) {
        puVar19 = (ulonglong *)*puVar18;
        uStack_98 = uStack_98 & 0xffffffffffffff00;
        local_a0 = local_c0 + 0x10;
        if ((puVar18[1] & 1) != 0) {
          if (puVar19 == (ulonglong *)0x0) {
            puVar19 = (ulonglong *)0x0;
          }
          else {
            puVar19 = (ulonglong *)((ulonglong)puVar19 ^ (ulonglong)puVar18);
          }
        }
        uVar21 = puVar18[1];
        uVar8 = (ulonglong)uVar22 << 8;
        if (puVar19 != (ulonglong *)0x0) {
          do {
            uVar11 = BfpRBComparePathNodes(&local_a0,(longlong)puVar19);
            if ((int)uVar11 < 0) {
              puVar13 = (ulonglong *)*puVar19;
              if ((uVar21 & 1) == 0) {
LAB_140015873:
                if (puVar13 != (ulonglong *)0x0) goto LAB_1400156ae;
              }
              else if (puVar13 != (ulonglong *)0x0) {
                puVar13 = (ulonglong *)((ulonglong)puVar13 ^ (ulonglong)puVar19);
                goto LAB_140015873;
              }
              uVar8 = uVar8 & 0xffffffffffffff00;
              break;
            }
            puVar13 = (ulonglong *)puVar19[1];
            if ((uVar21 & 1) != 0) {
              if (puVar13 == (ulonglong *)0x0) goto LAB_1400156b3;
              puVar13 = (ulonglong *)((ulonglong)puVar13 ^ (ulonglong)puVar19);
            }
            if (puVar13 == (ulonglong *)0x0) goto LAB_1400156b3;
LAB_1400156ae:
            puVar19 = puVar13;
          } while( true );
        }
        goto LAB_1400156b9;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400158d3;
      uVar26 = (undefined1)uVar21;
      uVar23 = 0x3c;
      uVar25 = 0x44;
      goto LAB_14001596c;
    }
    uVar10 = BfpCreatePathTree(puVar16);
    iVar5 = (int)uVar10;
    if (-1 < iVar5) goto LAB_1400155f2;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400158d3;
    uVar26 = (undefined1)uVar10;
    uVar23 = 0x3b;
    uVar25 = 0xb;
  }
LAB_14001596c:
  WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,8,uVar23,
                      &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                      "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",uVar25,uVar26);
LAB_1400158d3:
  if (local_c8 == 0) {
    return iVar5;
  }
  ExFreePoolWithTag(local_c8,0x706d4642);
  return iVar5;
LAB_1400156b3:
  uVar8 = 1;
LAB_1400156b9:
  RtlRbInsertNodeEx(puVar18,puVar19,uVar8);
  iVar6 = RtlCompareUnicodeString(local_80,&g_NoShortComponent,0);
  if (iVar6 == 0) goto LAB_1400157e8;
  uVar10 = 0;
  iVar6 = RtlCompareUnicodeString(local_80,local_b0,0);
  if (iVar6 == 0) goto LAB_1400157e8;
  local_a0 = (short *)0x0;
  uStack_98 = 0;
  if (local_d8 == '\0') {
    uVar12 = 0;
  }
  else {
    uVar12 = *(undefined8 *)(psVar15 + 0x28);
  }
  uVar22 = (uint7)((ulonglong)uVar10 >> 8);
  uVar21 = BfpCreatePathTierNode
                     ((longlong)local_80,uVar24 | 2,local_d8,0,(undefined8 *)0x0,0,(longlong *)0x0,
                      uVar12,&local_60);
  lVar1 = local_60;
  iVar5 = (int)uVar21;
  if (iVar5 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400158d3;
    uVar26 = (undefined1)uVar21;
    uVar23 = 0x3d;
    uVar25 = 0x76;
    goto LAB_14001596c;
  }
  puVar19 = (ulonglong *)*puVar18;
  uStack_98 = uStack_98 & 0xffffffffffffff00;
  local_a0 = (short *)(local_60 + 0x20);
  if ((puVar18[1] & 1) != 0) {
    if (puVar19 == (ulonglong *)0x0) {
      puVar19 = (ulonglong *)0x0;
    }
    else {
      puVar19 = (ulonglong *)((ulonglong)puVar19 ^ (ulonglong)puVar18);
    }
  }
  uVar21 = puVar18[1];
  uVar8 = (ulonglong)uVar22 << 8;
  if (puVar19 != (ulonglong *)0x0) {
    do {
      uVar11 = BfpRBComparePathNodes(&local_a0,(longlong)puVar19);
      if ((int)uVar11 < 0) {
        puVar13 = (ulonglong *)*puVar19;
        if ((uVar21 & 1) == 0) {
LAB_140015898:
          if (puVar13 != (ulonglong *)0x0) goto LAB_1400157c1;
        }
        else if (puVar13 != (ulonglong *)0x0) {
          puVar13 = (ulonglong *)((ulonglong)puVar13 ^ (ulonglong)puVar19);
          goto LAB_140015898;
        }
        uVar8 = uVar8 & 0xffffffffffffff00;
        break;
      }
      puVar13 = (ulonglong *)puVar19[1];
      if ((uVar21 & 1) != 0) {
        if (puVar13 == (ulonglong *)0x0) goto LAB_1400157c6;
        puVar13 = (ulonglong *)((ulonglong)puVar13 ^ (ulonglong)puVar19);
      }
      if (puVar13 == (ulonglong *)0x0) goto LAB_1400157c6;
LAB_1400157c1:
      puVar19 = puVar13;
    } while( true );
  }
LAB_1400157cc:
  RtlRbInsertNodeEx(puVar18,puVar19,uVar8);
  *(longlong *)(psVar15 + 0x2c) = lVar1;
LAB_1400157e8:
  if (local_d8 != '\0') {
    puVar18 = *(ulonglong **)(psVar15 + 0x28);
  }
  uVar8 = BfpWalkPath(local_90,0,local_b0);
  local_d8 = (char)uVar8;
  psVar15 = local_80;
  uVar8 = uVar8 & 0xff;
  BfpWalkPath((ushort *)(local_80 + 8),0,psVar15);
  uVar21 = local_58;
  if (local_b0[0] == 0) goto code_r0x00014001582e;
  goto LAB_1400155fc;
LAB_1400157c6:
  uVar8 = 1;
  goto LAB_1400157cc;
code_r0x00014001582e:
  ExFreePoolWithTag(local_c8,0x706d4642);
  uVar7 = uVar7 + 1;
  goto LAB_1400153ec;
}



===== BfpWalkPath @ 140015af0 =====

undefined8 BfpWalkPath(ushort *param_1,ushort param_2,short *param_3)

{
  short sVar1;
  ushort uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  ushort uVar5;
  undefined8 uVar6;
  longlong lVar7;
  
  uVar6 = 0;
  if (*param_3 == 0) {
    uVar5 = param_2 >> 1;
    uVar2 = uVar5 + 1;
    if (*(short *)(*(longlong *)(param_1 + 4) + (ulonglong)uVar5 * 2) != 0x5c) {
      uVar2 = uVar5;
    }
    uVar3 = (ulonglong)uVar2;
    *(ulonglong *)(param_3 + 4) = *(longlong *)(param_1 + 4) + uVar3 * 2;
    lVar7 = *(longlong *)(param_1 + 4);
  }
  else {
    lVar7 = *(longlong *)(param_1 + 4);
    uVar3 = *(longlong *)(param_3 + 4) - lVar7 >> 1;
    uVar2 = (ushort)uVar3;
    while (uVar2 < *param_1 >> 1) {
      uVar2 = (ushort)uVar3;
      if (*(short *)(lVar7 + (uVar3 & 0xffff) * 2) == 0x5c) goto LAB_140015b65;
      uVar2 = uVar2 + 1;
      uVar3 = (ulonglong)uVar2;
    }
    if (uVar2 == *param_1 >> 1) {
      param_3[4] = 0;
      param_3[5] = 0;
      param_3[6] = 0;
      param_3[7] = 0;
      param_3[1] = 0;
      *param_3 = 0;
      return 0;
    }
LAB_140015b65:
    uVar3 = (ulonglong)(ushort)(uVar2 + 1);
  }
  uVar4 = uVar3;
  do {
    uVar2 = (ushort)uVar4;
    if (*param_1 >> 1 <= uVar2) {
LAB_140015b9e:
      sVar1 = (uVar2 - (short)uVar3) * 2;
      *(ulonglong *)(param_3 + 4) = lVar7 + uVar3 * 2;
      param_3[1] = sVar1;
      *param_3 = sVar1;
      return uVar6;
    }
    if (*(short *)(lVar7 + uVar4 * 2) == 0x5c) {
      uVar6 = 1;
      goto LAB_140015b9e;
    }
    uVar4 = (ulonglong)(ushort)(uVar2 + 1);
  } while( true );
}



===== BfConvertContainerRootIdToShortNames @ 140015be4 =====

short * BfConvertContainerRootIdToShortNames(ushort *param_1,undefined8 *param_2)

{
  ushort uVar1;
  bool bVar2;
  short sVar3;
  ushort uVar4;
  uint uVar5;
  ulonglong uVar6;
  short *psVar7;
  ushort uVar8;
  ushort *puVar9;
  short *psVar10;
  short sVar11;
  ushort uVar12;
  undefined2 uVar13;
  longlong lVar14;
  longlong local_res20;
  undefined8 in_stack_fffffffffffffe98;
  undefined4 uVar15;
  undefined1 uVar16;
  longlong local_108;
  longlong local_100;
  longlong local_f8;
  ushort *local_f0;
  undefined8 local_e8;
  ushort *puStack_e0;
  undefined8 local_d8;
  short *psStack_d0;
  undefined8 local_c8;
  ushort *puStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  ulonglong local_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 *local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  
  *param_2 = 0;
  local_100 = 0;
  local_98 = local_98 & 0xffffffffffff0000;
  local_108 = 0;
  bVar2 = true;
  psVar7 = (short *)0x0;
  sVar11 = 0;
  local_res20 = 0;
  local_e8 = 0;
  puStack_e0 = (ushort *)0x0;
  local_f8 = 0;
  local_d8 = 0;
  psStack_d0 = (short *)0x0;
  local_90 = 0;
  uStack_88 = 0;
  local_80 = (undefined8 *)0x0;
  uStack_78 = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_b8 = 0;
  uStack_b0 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  local_60 = 0;
  uStack_58 = 0;
  uVar6 = BfValidateContainerRootId(param_1,(uint)*param_1);
  psVar10 = (short *)(uVar6 & 0xffffffff);
  if ((int)uVar6 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,10,
                          &WPP_529f93b0825532f67776c14f74ba0846_Traceguids,
                          "onecore\\base\\fs\\wci\\bindflt\\filter\\utils.c",0x4b,(char)uVar6);
    }
  }
  else {
    if (param_1[2] >> 1 != 0) {
      puVar9 = param_1 + 3;
      uVar6 = (ulonglong)(param_1[2] >> 1);
      do {
        sVar3 = sVar11 + 1;
        if (*puVar9 != 0x5c) {
          sVar3 = sVar11;
        }
        sVar11 = sVar3;
        puVar9 = puVar9 + 1;
        uVar6 = uVar6 - 1;
      } while (uVar6 != 0);
    }
    local_f0 = param_1 + 2;
    puVar9 = param_1 + 3;
    sVar11 = sVar11 * 0x1a + param_1[1];
    psVar7 = (short *)ExAllocatePool2(0x100,sVar11 + 6,0x706d4642);
    if (psVar7 == (short *)0x0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,0xb,
                           &WPP_529f93b0825532f67776c14f74ba0846_Traceguids,
                           "onecore\\base\\fs\\wci\\bindflt\\filter\\utils.c",0x73);
      }
      psVar10 = (short *)0xc000009a;
    }
    else {
      *psVar7 = sVar11 + 6;
      uVar1 = param_1[1];
      psVar7[1] = uVar1;
      memmove(psVar7 + 3,puVar9,(ulonglong)uVar1);
      psVar7[2] = psVar7[1];
      uVar1 = param_1[1];
      if ((uint)*local_f0 - (uint)uVar1 == 2) {
        psVar7[(ulonglong)((ushort)psVar7[1] >> 1) + 3] = 0x5c;
        psVar7[2] = psVar7[2] + 2;
        lVar14 = local_f8;
      }
      else {
        local_e8 = CONCAT62(CONCAT42(local_e8._4_4_,sVar11),uVar1);
        uVar12 = uVar1 + 4;
        local_c8 = (ulonglong)CONCAT22(uVar1,uVar1);
        local_d8 = CONCAT62(CONCAT42(local_d8._4_4_,sVar11),psVar7[1]);
        puStack_e0 = puVar9;
        psStack_d0 = psVar7 + 3;
        puStack_c0 = puVar9;
        BfGetInstanceFromVolumeName(&local_c8,&local_f8);
        lVar14 = local_f8;
        do {
          uVar15 = (undefined4)((ulonglong)in_stack_fffffffffffffe98 >> 0x20);
          uVar1 = *local_f0;
          uVar8 = uVar1 >> 1;
          if ((uVar8 == 0) || (puStack_e0 == (ushort *)0x0)) {
LAB_140015db1:
            bVar2 = false;
          }
          else {
            uVar4 = uVar12 >> 1;
            if ((uint)uVar4 < (uint)uVar8) {
              do {
                if (puStack_e0[(short)uVar4] == 0x5c) break;
                uVar4 = uVar4 + 1;
              } while ((int)(short)uVar4 < (int)(uint)uVar8);
            }
            if ((int)(uint)uVar8 <= (int)(short)uVar4) goto LAB_140015db1;
            uVar1 = uVar4 * 2;
            uVar12 = uVar1 + 4;
          }
          local_e8 = CONCAT62(local_e8._2_6_,uVar1);
          local_98 = 0;
          uStack_b0 = 0;
          local_b8 = 0x28;
          local_a8 = 0;
          uStack_a0 = 0;
          local_98 = PsGetHostSilo();
          local_80 = &local_e8;
          local_90 = CONCAT44(local_90._4_4_,0x30);
          uStack_88 = 0;
          in_stack_fffffffffffffe98 = CONCAT44(uVar15,0x120089);
          uStack_78 = CONCAT44(uStack_78._4_4_,0x240);
          local_70 = 0;
          uStack_68 = 0;
          uVar5 = FltCreateFileEx2(g_BindFltState,lVar14,&local_100,&local_108,
                                   in_stack_fffffffffffffe98,&local_90,&local_60,0,0,7,1,0x200000,0,
                                   0,0,&local_b8);
          if ((int)uVar5 < 0) {
LAB_140015e80:
            psVar10 = (short *)(ulonglong)uVar5;
            if (((uVar5 == 0xc0000034) || (uVar5 == 0xc000003a)) || (uVar5 == 0xc01c0005)) {
              uVar5 = RtlAppendUnicodeToString(&local_d8,L"\\");
              if (((int)uVar5 < 0) ||
                 (uVar5 = RtlAppendUnicodeStringToString(&local_d8,&g_NoShortComponent),
                 (int)uVar5 < 0)) {
                psVar10 = (short *)(ulonglong)uVar5;
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  uVar13 = 0xe;
                  uVar16 = 0x62;
                  goto LAB_140016091;
                }
                goto LAB_140015f1d;
              }
              psVar7[2] = psVar7[2] + 4;
            }
            else if ((int)uVar5 < 0) goto LAB_140016136;
          }
          else {
            local_res20 = 0;
            if ((local_108 == 0) ||
               (((uVar5 = FltGetFileNameInformationUnsafe(local_108,lVar14,0x103,&local_res20),
                 -1 < (int)uVar5 && (*(short *)(local_res20 + 8) == 0)) &&
                (*(short *)(local_res20 + 0x18) != 0)))) {
              psVar10 = (short *)0xc000000d;
LAB_140016136:
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                uVar5 = (uint)psVar10;
                uVar13 = 0xf;
                uVar16 = 0x6b;
LAB_140016091:
                WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,uVar13,
                                    &WPP_529f93b0825532f67776c14f74ba0846_Traceguids,
                                    "onecore\\base\\fs\\wci\\bindflt\\filter\\utils.c",uVar16,
                                    (char)uVar5);
              }
              goto LAB_140015f1d;
            }
            if ((int)uVar5 < 0) goto LAB_140015e80;
            uVar5 = RtlAppendUnicodeToString(&local_d8,L"\\");
            if (((int)uVar5 < 0) ||
               (uVar5 = RtlAppendUnicodeStringToString(&local_d8,local_res20 + 8), (int)uVar5 < 0))
            {
              psVar10 = (short *)(ulonglong)uVar5;
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                uVar13 = 0xd;
                uVar16 = 0x3f;
                goto LAB_140016091;
              }
              goto LAB_140015f1d;
            }
            psVar7[2] = psVar7[2] + 2;
            psVar7[2] = psVar7[2] + *(short *)(local_res20 + 8);
            FltReleaseFileNameInformation(local_res20);
            local_res20 = 0;
          }
          if (local_100 != 0) {
            FltClose();
            local_100 = 0;
          }
          if (local_108 != 0) {
            ObfDereferenceObject();
            local_108 = 0;
          }
        } while (bVar2);
      }
      psVar10 = (short *)0x0;
      *param_2 = psVar7;
      psVar7 = psVar10;
LAB_140015f1d:
      if (lVar14 != 0) {
        FltObjectDereference(lVar14);
      }
    }
  }
  if (local_100 != 0) {
    FltClose();
  }
  if (local_108 != 0) {
    ObfDereferenceObject();
  }
  if (local_res20 != 0) {
    FltReleaseFileNameInformation();
  }
  if (psVar7 != (short *)0x0) {
    ExFreePoolWithTag(psVar7,0x706d4642);
  }
  return psVar10;
}



===== BfpInitializeMappingEntry @ 1400162a8 =====

ulonglong BfpInitializeMappingEntry
                    (ushort *param_1,ushort *param_2,ushort *param_3,ushort *param_4,short param_5,
                    ushort *param_6,short param_7,undefined8 *param_8)

{
  int iVar1;
  ulonglong uVar2;
  undefined2 uVar3;
  undefined1 uVar4;
  
  uVar2 = BfpInitializeContainerRootId(param_1,param_4,param_5,param_3,param_8);
  iVar1 = (int)uVar2;
  uVar2 = uVar2 & 0xffffffff;
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return uVar2;
    }
    uVar3 = 0x35;
    uVar4 = 0xbb;
  }
  else {
    uVar2 = BfpInitializeContainerRootId(param_2,param_6,param_7,(ushort *)0x0,param_8 + 1);
    iVar1 = (int)uVar2;
    uVar2 = uVar2 & 0xffffffff;
    if (-1 < iVar1) {
      return uVar2;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return uVar2;
    }
    uVar3 = 0x36;
    uVar4 = 0xc3;
  }
  WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,8,uVar3,
                      &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                      "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",uVar4,(char)iVar1);
  return uVar2;
}



===== BfStoreBatchedVirtualizationMapping @ 1400163a0 =====

ulonglong BfStoreBatchedVirtualizationMapping(uint *param_1,uint param_2)

{
  undefined1 auVar1 [16];
  bool bVar2;
  bool bVar3;
  char cVar4;
  int iVar5;
  uint uVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  ushort *puVar9;
  ulonglong uVar10;
  longlong lVar11;
  undefined2 uVar12;
  ushort *puVar13;
  undefined1 uVar14;
  undefined1 uVar15;
  longlong local_128;
  uint local_120;
  ushort local_118;
  ushort local_116;
  undefined4 local_114;
  short *local_110;
  ushort *local_108;
  ushort *puStack_100;
  ushort *local_f8;
  undefined8 *local_f0;
  ushort local_e8;
  ushort local_e6;
  undefined4 local_e4;
  short *local_e0;
  ulonglong local_d8;
  longlong lStack_d0;
  longlong local_c8;
  longlong local_c0;
  longlong *local_b8;
  ulonglong local_b0;
  uint *local_a8;
  ushort local_a0;
  ushort local_9e;
  undefined4 local_9c;
  longlong local_98;
  ushort local_90;
  ushort local_8e;
  undefined4 local_8c;
  longlong local_88;
  void *local_80;
  ulonglong local_78;
  ulonglong local_70;
  longlong local_68;
  ulonglong local_60;
  longlong lStack_58;
  
  local_f8 = (ushort *)0x0;
  puVar13 = (ushort *)0x0;
  bVar3 = false;
  local_108 = (ushort *)0x0;
  puStack_100 = (ushort *)0x0;
  lVar11 = 0;
  local_128 = 0;
  local_d8 = 0;
  lStack_d0 = 0;
  local_f0 = (undefined8 *)0x0;
  bVar2 = false;
  local_c0 = 0;
  local_b8 = (longlong *)0x0;
  local_c8 = 0;
  uVar7 = PsGetCurrentSilo();
  cVar4 = PsIsHostSilo(uVar7);
  if (cVar4 == '\0') {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,0x90,
                         &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                         "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",0x1b);
    }
    uVar10 = 0xc0000022;
  }
  else {
    uVar8 = BfpValidateBatchedMappingConfig(param_1,(ulonglong)param_2);
    uVar10 = uVar8 & 0xffffffff;
    if ((int)uVar8 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,0x91,
                           &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                           "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",0x23);
      }
    }
    else {
      ExAcquireFastMutex(&DAT_14000d248);
      if (DAT_14000d280 == '\0') {
        ExReleaseFastMutex();
        uVar8 = 0;
        local_a8 = (uint *)((ulonglong)param_1[6] + 0x20 + (longlong)param_1);
        local_68 = (ulonglong)param_1[7] + 0x20 + (longlong)param_1;
        while( true ) {
          local_120 = (uint)uVar8;
          bVar3 = false;
          if (*local_a8 <= local_120) break;
          local_9c = 0;
          local_8c = 0;
          local_70 = *(ulonglong *)(local_a8 + uVar8 * 8 + 5);
          local_78 = *(ulonglong *)((longlong)(local_a8 + uVar8 * 8 + 5) + 8);
          local_e4 = 0;
          auVar1 = *(undefined1 (*) [16])(local_a8 + uVar8 * 8 + 1);
          local_114 = 0;
          local_a0 = (ushort)local_70;
          lStack_58 = (auVar1._0_8_ >> 0x20) + 0x20 + (longlong)param_1;
          uVar8 = auVar1._8_8_;
          local_60 = (ulonglong)auVar1._2_2_;
          local_80 = (void *)((uVar8 >> 0x20) + 0x20 + (longlong)param_1);
          local_b0 = uVar8 >> 0x10;
          local_98 = (local_70 >> 0x20) + 0x20 + (longlong)param_1;
          local_90 = (ushort)local_78;
          local_88 = (local_78 >> 0x20) + 0x20 + (longlong)param_1;
          uVar10 = *(ulonglong *)(local_68 + 4 + (auVar1._0_8_ & 0xffff) * 8);
          local_e8 = (ushort)uVar10;
          local_e0 = (short *)((uVar10 >> 0x20) + 0x20 + (longlong)param_1);
          uVar10 = *(ulonglong *)(local_68 + 4 + (uVar8 & 0xffff) * 8);
          local_118 = (ushort)uVar10;
          local_110 = (short *)((uVar10 >> 0x20) + 0x20 + (longlong)param_1);
          local_116 = local_118;
          local_e6 = local_e8;
          local_9e = local_a0;
          local_8e = local_90;
          uVar8 = BfpInitializeContainerRootId((ushort *)&local_60,&local_e8,0,&local_a0,&local_108)
          ;
          uVar10 = uVar8 & 0xffffffff;
          if ((int)uVar8 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar15 = (undefined1)uVar8;
              uVar12 = 0x35;
              uVar14 = 0xbb;
LAB_140016dcc:
              WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,8,uVar12,
                                  &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                                  "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",uVar14,uVar15
                                 );
            }
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,0x93,
                                  &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                                  "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",0x8a,
                                  (char)uVar10);
            }
LAB_140016e2c:
            bVar3 = false;
LAB_1400168ba:
            if (local_120 == 0) goto LAB_1400168c6;
            *local_a8 = local_120;
            uVar8 = BfRemoveBatchedVirtualizationMapping(param_1,(ulonglong)param_2);
            if ((int)uVar8 < 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
              goto LAB_1400168c6;
              WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,0x9d,
                                  &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                                  "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",0x73,
                                  (char)uVar8);
            }
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_sDdd
                        (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,0x9e,
                         &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                         "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",0x76,(char)local_120,
                         (char)uVar10);
            }
            goto LAB_1400168c6;
          }
          puVar9 = (ushort *)
                   ExAllocatePool2(0x100,(uint)(ushort)local_b0 + local_118 + 6,0x706d4642);
          if (puVar9 == (ushort *)0x0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,8,0x34,
                                 &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                                 "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",0x37);
            }
            uVar10 = 0xc000009a;
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar15 = 0x9a;
              uVar12 = 0x36;
              uVar14 = 0xc3;
              goto LAB_140016dcc;
            }
            goto LAB_140016e2c;
          }
          puVar9[0] = 6;
          puVar9[1] = 0;
          puVar9[2] = 0;
          *puVar9 = local_118 + 6;
          puVar9[2] = local_118;
          puVar9[1] = local_118;
          memmove(puVar9 + 3,local_110,(ulonglong)local_118);
          *puVar9 = *puVar9 + (short)local_b0;
          puVar9[2] = puVar9[2] + (short)local_b0;
          memmove((void *)((ulonglong)(local_118 + 6) + (longlong)puVar9),local_80,local_b0 & 0xffff
                 );
          bVar3 = true;
          if (((*local_e0 == 0x5c) && (local_e0[1] == 0x5c)) && (local_e0[2] == 0x3f)) {
            local_108[1] = 0x60;
          }
          if (((*local_110 == 0x5c) && (local_110[1] == 0x5c)) && (local_110[2] == 0x3f)) {
            puVar9[1] = 0x60;
          }
          puStack_100 = puVar9;
          uVar8 = BfValidateContainerRootId(local_108,(uint)*local_108);
          uVar10 = uVar8 & 0xffffffff;
          if ((int)uVar8 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
            goto LAB_1400168ba;
            uVar15 = (undefined1)uVar8;
            uVar12 = 0x94;
            uVar14 = 0xa0;
LAB_140016d6f:
            uVar6 = 6;
LAB_140016d72:
            WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar6,uVar12,
                                &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                                "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",uVar14,uVar15);
            goto LAB_1400168ba;
          }
          uVar8 = BfValidateContainerRootId(puStack_100,(uint)*puStack_100);
          uVar10 = uVar8 & 0xffffffff;
          if ((int)uVar8 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar15 = (undefined1)uVar8;
              uVar12 = 0x95;
              uVar14 = 0xa8;
              goto LAB_140016d6f;
            }
            goto LAB_1400168ba;
          }
          if ((short)local_78 != 0) {
            uVar8 = BfpInitializeContainerRootId(&local_90,&local_e8,0,(ushort *)0x0,&local_f8);
            puVar13 = local_f8;
            uVar10 = uVar8 & 0xffffffff;
            if ((int)uVar8 < 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,0x96,
                                    &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                                    "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",0xb6,
                                    (char)uVar8);
              }
              puVar13 = local_f8;
            }
            else {
              if (((*local_e0 == 0x5c) && (local_e0[1] == 0x5c)) && (local_e0[2] == 0x3f)) {
                local_f8[1] = 0x60;
              }
              uVar8 = BfValidateContainerRootId(local_f8,(uint)*local_f8);
              uVar10 = uVar8 & 0xffffffff;
              if (-1 < (int)uVar8) goto LAB_140016706;
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                uVar15 = (undefined1)uVar8;
                uVar12 = 0x97;
                uVar14 = 0xc2;
                goto LAB_140016d6f;
              }
            }
            goto LAB_1400168ba;
          }
LAB_140016706:
          if (lVar11 == 0) {
LAB_140016aea:
            if (local_f0 != (undefined8 *)0x0) {
              FltReleaseContext();
              local_f0 = (undefined8 *)0x0;
            }
            BfFreeUnicodeString((undefined4 *)&local_d8);
            if ((*local_110 == 0x5c) && (local_110[1] == 0x5c)) {
              if (local_110[2] == 0x3f) {
                uVar10 = BfGetInstanceFromFileObject((short *)&local_118,'\x01',&local_128);
                uVar6 = (uint)uVar10;
                goto LAB_140016b5b;
              }
              uVar10 = BfGetInstanceFromFileObject((short *)&local_118,'\0',&local_128);
              uVar10 = uVar10 & 0xffffffff;
              puStack_100[1] = 2;
            }
            else {
              uVar6 = BfGetInstanceFromVolumeName(&local_118,&local_128);
LAB_140016b5b:
              uVar10 = (ulonglong)uVar6;
            }
            lVar11 = local_128;
            if ((int)uVar10 < 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                uVar12 = 0x98;
                uVar14 = 1;
LAB_140016cef:
                uVar15 = (undefined1)uVar10;
                uVar6 = 8;
                goto LAB_140016d72;
              }
            }
            else {
              uVar6 = FltGetInstanceContext(local_128,&local_f0);
              uVar10 = (ulonglong)uVar6;
              if ((int)uVar6 < 0) {
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  uVar10 = (ulonglong)uVar6;
                  uVar12 = 0x99;
                  uVar14 = 9;
                  goto LAB_140016cef;
                }
              }
              else {
                uVar8 = BfAllocateUnicodeString(local_116,(undefined4 *)&local_d8);
                uVar10 = uVar8 & 0xffffffff;
                if (-1 < (int)uVar8) {
                  RtlCopyUnicodeString(&local_d8,&local_118);
                  goto LAB_14001674c;
                }
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  uVar10 = uVar8 & 0xffffffff;
                  uVar12 = 0x9a;
                  uVar14 = 0x16;
                  goto LAB_140016cef;
                }
              }
            }
            goto LAB_1400168ba;
          }
          iVar5 = RtlCompareUnicodeString(&local_118,&local_d8,1);
          if (iVar5 != 0) {
            FltObjectDereference(lVar11);
            local_128 = 0;
            goto LAB_140016aea;
          }
          if (((*local_110 == 0x5c) && (local_110[1] == 0x5c)) && (local_110[2] != 0x3f)) {
            puStack_100[1] = 2;
          }
LAB_14001674c:
          if (local_c8 == 0) {
            uVar6 = BfpGetInstanceTierNode
                              ((short *)&local_e8,*(longlong *)(param_1 + 2),
                               *(longlong *)(param_1 + 4),'\x01',&local_b8,&local_c0,&local_c8);
            uVar10 = (ulonglong)uVar6;
            if ((int)uVar6 < 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                uVar15 = (undefined1)uVar6;
                uVar12 = 0x9b;
                uVar14 = 0x39;
                goto LAB_140016d6f;
              }
              goto LAB_1400168ba;
            }
            FltAcquireResourceExclusive(local_c0 + 0x10);
            bVar2 = true;
          }
          uVar6 = param_1[1] | 0x20000000;
          if ((short)local_70 == 0) {
            uVar6 = param_1[1];
          }
          uVar8 = BfpMappingInsertIntoTable
                            ((longlong *)&local_108,uVar6,local_b8,local_c8,local_f0,0,0,
                             (longlong)puVar13);
          uVar10 = uVar8 & 0xffffffff;
          if ((int)uVar8 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar15 = (undefined1)uVar8;
              uVar12 = 0x9c;
              uVar14 = 0x56;
              goto LAB_140016d6f;
            }
            goto LAB_1400168ba;
          }
          if (puVar13 != (ushort *)0x0) {
            ExFreePoolWithTag(puVar13,0x706d4642);
            puVar13 = (ushort *)0x0;
            local_f8 = (ushort *)0x0;
          }
          ExFreePoolWithTag(local_108,0x706d4642);
          ExFreePoolWithTag(puStack_100,0x706d4642);
          uVar8 = (ulonglong)(local_120 + 1);
        }
        goto LAB_1400168cb;
      }
      ExReleaseFastMutex(&DAT_14000d248);
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,0x92,
                           &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                           "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",0x31);
      }
      uVar10 = 0xc00000bb;
    }
  }
LAB_1400168c6:
  lVar11 = local_128;
LAB_1400168cb:
  if (lStack_d0 != 0) {
    ExFreePoolWithTag(lStack_d0,0x74734642);
    lStack_d0 = 0;
  }
  local_d8 = local_d8 & 0xffffffff00000000;
  if (bVar2) {
    FltReleaseResource(local_c0 + 0x10);
  }
  if (local_b8 != (longlong *)0x0) {
    FltReleaseContext(local_b8);
  }
  if (lVar11 != 0) {
    FltObjectDereference(lVar11);
  }
  if (local_f0 != (undefined8 *)0x0) {
    FltReleaseContext();
  }
  if (puVar13 != (ushort *)0x0) {
    ExFreePoolWithTag(puVar13,0x706d4642);
  }
  if (bVar3) {
    BfpCleanupMappingEntry(&local_108);
  }
  return uVar10;
}



===== BfValidateContainerRootId @ 140016f60 =====

undefined8 BfValidateContainerRootId(ushort *param_1,uint param_2)

{
  uint uVar1;
  undefined2 uVar2;
  undefined1 uVar3;
  
  if (*param_1 == param_2) {
    uVar1 = param_1[2] + 6;
    if (uVar1 < 6) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return 0xc0000095;
      }
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,0x11,
                          &WPP_529f93b0825532f67776c14f74ba0846_Traceguids,
                          "onecore\\base\\fs\\wci\\bindflt\\filter\\utils.c",0xa6,0x95);
      return 0xc0000095;
    }
    if (*param_1 == uVar1) {
      if (param_1[1] <= param_1[2]) {
        return 0;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return 0xc000000d;
      }
      uVar2 = 0x13;
      uVar3 = 0xb3;
    }
    else {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return 0xc000000d;
      }
      uVar2 = 0x12;
      uVar3 = 0xac;
    }
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0xc000000d;
    }
    uVar2 = 0x10;
    uVar3 = 0x9d;
  }
  WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,uVar2,
                     &WPP_529f93b0825532f67776c14f74ba0846_Traceguids,
                     "onecore\\base\\fs\\wci\\bindflt\\filter\\utils.c",uVar3);
  return 0xc000000d;
}



===== BfpInitializeContainerRootId @ 140017094 =====

undefined8
BfpInitializeContainerRootId
          (ushort *param_1,ushort *param_2,short param_3,ushort *param_4,undefined8 *param_5)

{
  ushort uVar1;
  short *psVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  int iVar6;
  
  uVar5 = 0;
  uVar3 = 6;
  iVar6 = *param_1 + 6;
  if (param_2 != (ushort *)0x0) {
    iVar6 = iVar6 + (uint)*param_2;
  }
  if (param_4 != (ushort *)0x0) {
    iVar6 = iVar6 + *param_4 + 2;
  }
  psVar2 = (short *)ExAllocatePool2(0x100,iVar6,0x706d4642);
  if (psVar2 == (short *)0x0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,8,0x34,
                         &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                         "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",0x37);
    }
    uVar5 = 0xc000009a;
  }
  else {
    psVar2[0] = 6;
    psVar2[1] = 0;
    psVar2[2] = 0;
    if (param_2 == (ushort *)0x0) {
      psVar2[1] = param_3;
    }
    else {
      *psVar2 = *param_2 + 6;
      psVar2[2] = *param_2;
      psVar2[1] = *param_2;
      memmove(psVar2 + 3,*(void **)(param_2 + 4),(ulonglong)*param_2);
      uVar3 = *param_2 + 6;
    }
    *psVar2 = *psVar2 + *param_1;
    psVar2[2] = psVar2[2] + *param_1;
    memmove((void *)((ulonglong)uVar3 + (longlong)psVar2),*(void **)(param_1 + 4),
            (ulonglong)*param_1);
    uVar1 = *param_1;
    uVar4 = (ulonglong)(uVar3 + uVar1);
    if ((param_4 != (ushort *)0x0) && (*param_4 != 0)) {
      if (psVar2[(ulonglong)((ushort)psVar2[2] >> 1) + 2] != 0x5c) {
        *psVar2 = *psVar2 + 2;
        psVar2[2] = psVar2[2] + 2;
        *(undefined2 *)(uVar4 + (longlong)psVar2) = 0x5c;
        uVar4 = (ulonglong)(uVar3 + uVar1 + 2);
      }
      psVar2[2] = psVar2[2] + *param_4;
      *psVar2 = *psVar2 + *param_4;
      memmove((void *)(uVar4 + (longlong)psVar2),*(void **)(param_4 + 4),(ulonglong)*param_4);
    }
    *param_5 = psVar2;
  }
  return uVar5;
}



===== BfGetInstanceFromVolumeName @ 140017268 =====

int BfGetInstanceFromVolumeName(undefined8 param_1,undefined8 *param_2)

{
  int iVar1;
  undefined2 uVar2;
  longlong local_res18;
  undefined8 local_res20;
  undefined1 uVar3;
  
  local_res18 = 0;
  local_res20 = 0;
  iVar1 = FltGetVolumeFromName(g_BindFltState,param_1,&local_res18);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400172d3;
    uVar2 = 0x2c;
    uVar3 = 0x93;
  }
  else {
    iVar1 = FltGetVolumeInstanceFromName(g_BindFltState,local_res18,0,&local_res20);
    if (-1 < iVar1) {
      *param_2 = local_res20;
      goto LAB_1400172d3;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400172d3;
    uVar2 = 0x2d;
    uVar3 = 0x9a;
  }
  WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,3,uVar2,
                      &WPP_529f93b0825532f67776c14f74ba0846_Traceguids,
                      "onecore\\base\\fs\\wci\\bindflt\\filter\\utils.c",uVar3,(char)iVar1);
LAB_1400172d3:
  if (local_res18 != 0) {
    FltObjectDereference();
  }
  return iVar1;
}



===== BfpMappingInsert @ 140017380 =====

int BfpMappingInsert(undefined8 *param_1,longlong *param_2,uint param_3,uint param_4,
                    longlong param_5)

{
  longlong *plVar1;
  undefined8 uVar2;
  code *pcVar3;
  longlong lVar4;
  int iVar5;
  int iVar6;
  short *psVar7;
  ulonglong uVar8;
  undefined1 *puVar9;
  longlong lVar10;
  uint uVar11;
  undefined2 uVar12;
  undefined8 *puVar13;
  longlong local_res10;
  uint local_res18;
  uint local_res20;
  undefined1 auStackY_c8 [8];
  undefined1 auStackY_c0 [24];
  undefined1 uVar14;
  longlong *local_88;
  longlong local_80;
  undefined8 *local_78;
  undefined8 *local_70;
  longlong local_68;
  undefined8 local_60;
  longlong lStack_58;
  undefined8 local_50;
  longlong lStack_48;
  
  local_88 = (longlong *)0x0;
  local_50 = 0;
  lStack_48 = 0;
  local_70 = (undefined8 *)0x0;
  uVar12 = *(undefined2 *)(*param_2 + 2);
  lVar10 = 0;
  local_60 = (ulonglong)CONCAT22(uVar12,uVar12);
  lStack_58 = *param_2 + 6;
  local_80 = 0;
  local_res10 = 0;
  local_78 = (undefined8 *)0x0;
  local_68 = 0;
  local_res18 = param_3;
  local_res20 = param_4;
  iVar5 = BfGetInstanceFromVolumeName(&local_60,&local_80);
  puVar9 = auStackY_c8;
  if (iVar5 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140017511;
    uVar12 = 0x3e;
    uVar14 = 0xf8;
  }
  else {
    iVar5 = FltGetInstanceContext(local_80,&local_88);
    puVar9 = auStackY_c8;
    if (iVar5 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140017511;
      uVar12 = 0x3f;
      uVar14 = 0;
    }
    else {
      uVar12 = *(undefined2 *)(param_2[1] + 2);
      local_50._0_4_ = CONCAT22(uVar12,uVar12);
      lStack_48 = param_2[1] + 6;
      iVar5 = BfGetInstanceFromVolumeName(&local_50,&local_res10);
      lVar10 = local_res10;
      if (iVar5 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,8,0x40,
                              &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                              "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",0xc,(char)iVar5);
        }
        puVar9 = auStackY_c8;
        lVar10 = local_res10;
        goto LAB_140017511;
      }
      iVar5 = FltGetInstanceContext(local_res10,&local_70);
      puVar9 = auStackY_c8;
      if (-1 < iVar5) {
        psVar7 = BfConvertContainerRootIdToShortNames((ushort *)*param_2,&local_68);
        lVar4 = local_68;
        puVar9 = auStackY_c8;
        iVar5 = (int)psVar7;
        iVar6 = iVar5;
        if (iVar5 < 0) {
LAB_14001760f:
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            *(int *)(puVar9 + 0x38) = iVar6;
            *(undefined4 *)(puVar9 + 0x30) = 0xb22;
            *(char **)(puVar9 + 0x28) = "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c";
            uVar2 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
            *(undefined **)(puVar9 + 0x20) = &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids;
            *(undefined8 *)(puVar9 + -8) = 0x140017663;
            WPP_RECORDER_SF_sDd(uVar2,2,8,0x42,*(undefined8 *)(puVar9 + 0x20),
                                *(char **)(puVar9 + 0x28),puVar9[0x30],puVar9[0x38]);
          }
        }
        else {
          FltAcquireResourceExclusive(param_1 + 2);
          for (puVar13 = (undefined8 *)*param_1; puVar13 != param_1;
              puVar13 = (undefined8 *)*puVar13) {
            if (*(longlong *)puVar13[2] == *local_88) goto LAB_1400174b5;
            local_78 = (undefined8 *)0x0;
          }
          uVar8 = BfpCreateInstanceTierNode(local_88,(longlong *)&local_78);
          iVar5 = (int)uVar8;
          if (iVar5 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar12 = 0x43;
              uVar14 = 0x47;
              uVar11 = 8;
LAB_14001778b:
              WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar11,uVar12,
                                  &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                                  "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",uVar14,
                                  (char)uVar8);
            }
          }
          else {
            plVar1 = (longlong *)param_1[1];
            if ((undefined8 *)*plVar1 != param_1) {
              pcVar3 = (code *)swi(0x29);
              iVar6 = (*pcVar3)(3);
              puVar9 = auStackY_c0;
              goto LAB_14001760f;
            }
            *local_78 = param_1;
            local_78[1] = plVar1;
            *plVar1 = (longlong)local_78;
            param_1[1] = local_78;
            puVar13 = local_78;
LAB_1400174b5:
            uVar8 = BfpMappingInsertIntoTable
                              (param_2,local_res18,local_88,(longlong)puVar13,local_70,local_res20,
                               param_5,lVar4);
            iVar5 = (int)uVar8;
            if ((iVar5 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)
               ) {
              uVar12 = 0x44;
              uVar14 = 0x5d;
              uVar11 = 6;
              goto LAB_14001778b;
            }
          }
          puVar9 = auStackY_c8;
          FltReleaseResource(param_1 + 2);
        }
        if (lVar4 != 0) {
          *(undefined8 *)(puVar9 + -8) = 0x14001750c;
          ExFreePoolWithTag(lVar4,0x706d4642);
        }
        goto LAB_140017511;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140017511;
      uVar12 = 0x41;
      uVar14 = 0x14;
    }
  }
  WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,8,uVar12,
                      &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                      "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",uVar14,(char)iVar5);
  puVar9 = auStackY_c8;
LAB_140017511:
  if (local_88 != (longlong *)0x0) {
    *(undefined8 *)(puVar9 + -8) = 0x140017521;
    FltReleaseContext();
  }
  if (local_80 != 0) {
    *(undefined8 *)(puVar9 + -8) = 0x140017537;
    FltObjectDereference(local_80);
  }
  if (local_70 != (undefined8 *)0x0) {
    *(undefined8 *)(puVar9 + -8) = 0x14001754c;
    FltReleaseContext();
  }
  if (lVar10 != 0) {
    *(undefined8 *)(puVar9 + -8) = 0x140017560;
    FltObjectDereference(lVar10);
  }
  return iVar5;
}



===== BfpGetMappingContext @ 1400177c0 =====

int BfpGetMappingContext
              (uint *param_1,short *param_2,longlong param_3,longlong param_4,longlong *param_5,
              undefined8 *param_6)

{
  short *psVar1;
  longlong lVar2;
  char cVar3;
  int iVar4;
  int extraout_EAX;
  ulonglong uVar5;
  undefined8 uVar6;
  longlong lVar7;
  uint uVar8;
  undefined2 uVar9;
  longlong local_res8;
  undefined1 uVar10;
  longlong local_58;
  longlong local_50;
  longlong local_48;
  longlong local_40;
  undefined8 local_38;
  longlong local_30;
  undefined8 local_28;
  longlong lStack_20;
  
  local_res8 = 0;
  lVar7 = 0;
  local_30 = 0;
  local_40 = 0;
  local_58 = 0;
  local_48 = 0;
  local_38 = 0;
  local_50 = 0;
  local_28 = 0;
  lStack_20 = 0;
  if (param_1 == (uint *)0x0) {
    psVar1 = *(short **)(param_2 + 4);
    if ((*psVar1 == 0x5c) && (psVar1[1] == 0x5c)) {
      if (psVar1[2] != 0x3f) {
        iVar4 = -0x3fffff45;
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return -0x3fffff45;
        }
        WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,0xa0,
                            &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                            "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",0xda,0xbb);
        goto LAB_14001793d;
      }
      uVar5 = BfGetInstanceFromFileObject(param_2,'\x01',&local_res8);
      iVar4 = (int)uVar5;
    }
    else {
      iVar4 = BfGetInstanceFromVolumeName(param_2,&local_res8);
    }
    if (-1 < iVar4) goto LAB_140017863;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140017928;
    uVar9 = 0xa1;
    uVar10 = 0xe5;
    goto LAB_140017a19;
  }
  BfpValidateVirtualizationRoot((ushort *)param_1,param_1 + 10,*param_1,&local_40);
  lStack_20 = local_40 + 6;
  local_28._0_4_ = CONCAT22(*(undefined2 *)(local_40 + 2),*(undefined2 *)(local_40 + 2));
  iVar4 = BfGetInstanceFromVolumeName(&local_28,&local_res8);
  if (iVar4 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar9 = 0x9f;
      uVar10 = 0xbe;
LAB_1400179e9:
      uVar8 = 3;
LAB_140017a1f:
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar8,uVar9,
                          &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                          "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",uVar10,(char)iVar4);
    }
  }
  else {
    param_3 = *(longlong *)(param_1 + 4);
    param_4 = *(longlong *)(param_1 + 6);
LAB_140017863:
    iVar4 = FltGetInstanceContext(local_res8,&local_58);
    if (iVar4 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar9 = 0xa2;
        uVar10 = 0xf0;
        goto LAB_1400179e9;
      }
    }
    else if (param_3 == 0) {
      if (param_4 == 0) {
        uVar6 = *(undefined8 *)(local_58 + 0x30);
      }
      else {
        uVar5 = BfGetOrCreateUser(param_4,&local_30);
        iVar4 = (int)uVar5;
        if (iVar4 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar9 = 0xa6;
            uVar10 = 0x1f;
            goto LAB_140017a19;
          }
          goto LAB_140017928;
        }
        uVar6 = *(undefined8 *)(local_30 + 0x18);
      }
LAB_140017914:
      lVar2 = local_58;
      if (param_5 != (longlong *)0x0) {
        local_58 = 0;
        *param_5 = lVar2;
      }
      *param_6 = uVar6;
    }
    else {
      cVar3 = ObIsKernelHandle(param_3);
      iVar4 = ObReferenceObjectByHandle
                        (param_3,4,*(undefined8 *)PsJobType_exref,cVar3 == '\0',&local_48,0);
      if (iVar4 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar9 = 0xa3;
          uVar10 = 3;
LAB_140017a19:
          uVar8 = 6;
          goto LAB_140017a1f;
        }
      }
      else {
        iVar4 = PsGetJobSilo(local_48);
        if (iVar4 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar9 = 0xa4;
            uVar10 = 0xb;
            goto LAB_140017a19;
          }
        }
        else {
          BfGetOrCreateSiloContext(local_38,'\0',&local_50);
          iVar4 = extraout_EAX;
          if (-1 < extraout_EAX) {
            uVar6 = *(undefined8 *)(local_50 + 8);
            lVar7 = local_50;
            goto LAB_140017914;
          }
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,0xa5,
                                &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                                "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",0x13,
                                (char)extraout_EAX);
          }
          lVar7 = local_50;
        }
      }
    }
  }
LAB_140017928:
  if (local_res8 != 0) {
    FltObjectDereference();
  }
LAB_14001793d:
  if (local_58 != 0) {
    FltReleaseContext();
  }
  if (lVar7 != 0) {
    PsDereferenceSiloContext(lVar7);
  }
  if (local_48 != 0) {
    ObfDereferenceObject();
  }
  return iVar4;
}



===== BfpValidateVirtualizationRoot @ 140017c18 =====

ulonglong BfpValidateVirtualizationRoot
                    (ushort *param_1,uint *param_2,uint param_3,undefined8 *param_4)

{
  ushort *puVar1;
  uint uVar2;
  ulonglong uVar3;
  uint uVar4;
  undefined2 uVar5;
  undefined1 uVar6;
  int iVar7;
  
  *param_4 = 0;
  uVar2 = *param_2;
  uVar4 = (ushort)param_2[1] + uVar2;
  if (uVar4 < uVar2) {
    uVar3 = 0xc0000095;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0xc0000095;
    }
    iVar7 = -0x3fffff6b;
    uVar5 = 0x26;
    uVar6 = 0x42;
  }
  else {
    if (param_3 < uVar4) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,0x27,
                           &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                           "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",0x48);
      }
      return 0xc000000d;
    }
    puVar1 = (ushort *)((longlong)param_1 + (ulonglong)uVar2);
    if (puVar1 < param_1) {
      uVar3 = 0xc0000095;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return 0xc0000095;
      }
      iVar7 = -0x3fffff6b;
      uVar5 = 0x28;
      uVar6 = 0x57;
    }
    else {
      uVar3 = BfValidateContainerRootId(puVar1,(uint)(ushort)param_2[1]);
      iVar7 = (int)uVar3;
      uVar3 = uVar3 & 0xffffffff;
      if (-1 < iVar7) {
        *param_4 = puVar1;
        return 0;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return uVar3;
      }
      uVar5 = 0x29;
      uVar6 = 0x61;
    }
  }
  WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,uVar5,
                      &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                      "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",uVar6,(char)iVar7);
  return uVar3;
}



===== BfpValidateVirtualizationRoots @ 140017d90 =====

ulonglong BfpValidateVirtualizationRoots
                    (ushort *param_1,uint param_2,undefined8 *param_3,undefined8 *param_4)

{
  ushort *puVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  ulonglong uVar5;
  uint uVar6;
  uint uVar7;
  ushort *puVar8;
  undefined2 uVar9;
  undefined1 uVar10;
  int iVar11;
  
  *param_4 = 0;
  uVar3 = *(uint *)(param_1 + 0x14);
  uVar2 = param_1[0x16];
  *param_3 = 0;
  uVar6 = uVar2 + uVar3;
  if (uVar6 < uVar3) {
    uVar5 = 0xc0000095;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0xc0000095;
    }
    iVar11 = -0x3fffff6b;
    uVar9 = 0x2a;
    uVar10 = 0xa5;
LAB_140017eae:
    WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,uVar9,
                        &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                        "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",uVar10,(char)iVar11);
  }
  else {
    if (param_2 < uVar6) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar9 = 0x2b;
        uVar10 = 0xab;
        goto LAB_140017f49;
      }
    }
    else {
      uVar4 = *(uint *)(param_1 + 0x18);
      uVar7 = param_1[0x1a] + uVar4;
      if (uVar7 < uVar4) {
        uVar5 = 0xc0000095;
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return 0xc0000095;
        }
        iVar11 = -0x3fffff6b;
        uVar9 = 0x2c;
        uVar10 = 0xb6;
        goto LAB_140017eae;
      }
      if (param_2 < uVar7) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar9 = 0x2d;
          uVar10 = 0xbc;
LAB_140017f49:
          WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,uVar9,
                             &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                             "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",uVar10);
        }
      }
      else if ((uVar3 < 8) || (uVar4 < 8)) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar9 = 0x2e;
          uVar10 = 200;
          goto LAB_140017f49;
        }
      }
      else {
        if (((uVar6 <= uVar4) || (uVar7 <= uVar6)) && ((uVar6 <= uVar7 || (uVar7 <= uVar3)))) {
          puVar1 = (ushort *)((longlong)param_1 + (ulonglong)uVar3);
          if (puVar1 < param_1) {
            uVar5 = 0xc0000095;
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
              return 0xc0000095;
            }
            iVar11 = -0x3fffff6b;
            uVar9 = 0x30;
            uVar10 = 0xe5;
          }
          else {
            uVar5 = BfValidateContainerRootId(puVar1,(uint)uVar2);
            iVar11 = (int)uVar5;
            uVar5 = uVar5 & 0xffffffff;
            if (iVar11 < 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
                return uVar5;
              }
              uVar9 = 0x31;
              uVar10 = 0xef;
            }
            else {
              puVar8 = (ushort *)((ulonglong)*(uint *)(param_1 + 0x18) + (longlong)param_1);
              if (puVar8 < param_1) {
                uVar5 = 0xc0000095;
                if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
                  return 0xc0000095;
                }
                iVar11 = -0x3fffff6b;
                uVar9 = 0x32;
                uVar10 = 0xf9;
              }
              else {
                uVar5 = BfValidateContainerRootId(puVar8,(uint)param_1[0x1a]);
                iVar11 = (int)uVar5;
                uVar5 = uVar5 & 0xffffffff;
                if (-1 < iVar11) {
                  *param_3 = puVar1;
                  *param_4 = puVar8;
                  return 0;
                }
                if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
                  return uVar5;
                }
                uVar9 = 0x33;
                uVar10 = 3;
              }
            }
          }
          goto LAB_140017eae;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar9 = 0x2f;
          uVar10 = 0xd6;
          goto LAB_140017f49;
        }
      }
    }
    uVar5 = 0xc000000d;
  }
  return uVar5;
}



===== BfGetOrCreateSiloContext @ 1400180b0 =====

int BfGetOrCreateSiloContext(undefined8 param_1,char param_2,longlong *param_3)

{
  char cVar1;
  int iVar2;
  int unaff_EBX;
  undefined2 uVar3;
  undefined8 *local_res18 [2];
  undefined1 uVar4;
  
  local_res18[0] = (undefined8 *)0x0;
  *param_3 = 0;
  cVar1 = PsIsHostSilo();
  if (cVar1 == '\0') {
    iVar2 = PsGetSiloContext(param_1,DAT_14000d290,local_res18);
    if (iVar2 == -0x3ffffddb) {
      if (param_2 != '\0') goto LAB_14001811c;
      iVar2 = PsCreateSiloContext(param_1,0x10,0x200,BfCleanupSiloContext,local_res18);
      if (iVar2 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001811c;
        uVar3 = 0x1c;
        uVar4 = 0x30;
      }
      else {
        iVar2 = BfInitializeSiloContext(param_1,local_res18[0]);
        if (iVar2 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_14001811c;
          uVar3 = 0x1d;
          uVar4 = 0x38;
        }
        else {
          iVar2 = PsInsertSiloContext(param_1,DAT_14000d290,local_res18[0]);
          if (iVar2 == -0x3fffff45) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,7,0x1e,
                                 &WPP_ab4056511ca038337f1519c30a6fffbb_Traceguids,
                                 "onecore\\base\\fs\\wci\\bindflt\\filter\\context.c",0x49);
            }
            PsDereferenceSiloContext(local_res18[0]);
            local_res18[0] = (undefined8 *)0x0;
            iVar2 = PsGetSiloContext(param_1,DAT_14000d290,local_res18);
            if (-1 < iVar2) {
LAB_14001814f:
              *param_3 = (longlong)local_res18[0];
              return unaff_EBX;
            }
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
            goto LAB_14001811c;
            uVar3 = 0x1f;
            uVar4 = 0x52;
          }
          else {
            if (-1 < iVar2) goto LAB_14001814f;
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
            goto LAB_14001811c;
            uVar3 = 0x20;
            uVar4 = 0x58;
          }
        }
      }
    }
    else {
      if (-1 < iVar2) goto LAB_14001814f;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001811c;
      uVar3 = 0x21;
      uVar4 = 0x5e;
    }
    WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,7,uVar3,
                        &WPP_ab4056511ca038337f1519c30a6fffbb_Traceguids,
                        "onecore\\base\\fs\\wci\\bindflt\\filter\\context.c",uVar4,(char)iVar2);
  }
  else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,7,0x1b,
                       &WPP_ab4056511ca038337f1519c30a6fffbb_Traceguids,
                       "onecore\\base\\fs\\wci\\bindflt\\filter\\context.c",0x15);
  }
LAB_14001811c:
  if (local_res18[0] != (undefined8 *)0x0) {
    PsDereferenceSiloContext();
  }
  return unaff_EBX;
}



===== BfpCreateInstanceTierNode @ 1400183d8 =====

ulonglong BfpCreateInstanceTierNode(undefined8 param_1,longlong *param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  
  *param_2 = 0;
  lVar1 = ExAllocatePool2(0x100,0x28,0x706d4642);
  if (lVar1 == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,8,10,
                         &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                         "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",0x6e);
    }
    uVar3 = 0xc000009a;
  }
  else {
    *(undefined8 *)(lVar1 + 0x10) = param_1;
    FltReferenceContext(param_1);
    uVar2 = BfpCreatePathTree((undefined8 *)(lVar1 + 0x18));
    uVar3 = uVar2 & 0xffffffff;
    if ((int)uVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,8,0xb,
                            &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                            "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",0x80,(char)uVar2);
      }
      if (*(undefined8 **)(lVar1 + 0x18) != (undefined8 *)0x0) {
        BfpDeletePathTree(*(undefined8 **)(lVar1 + 0x18));
      }
      if (*(longlong *)(lVar1 + 0x10) != 0) {
        FltReleaseContext();
      }
      ExFreePoolWithTag(lVar1,0x706d4642);
    }
    else {
      *param_2 = lVar1;
      uVar3 = 0;
    }
  }
  return uVar3;
}



===== BfpCreatePathTree @ 140018538 =====

undefined8 BfpCreatePathTree(undefined8 *param_1)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  
  uVar2 = 0;
  *param_1 = 0;
  puVar1 = (undefined8 *)ExAllocatePool2(0x100,0x10,0x706d4642);
  if (puVar1 == (undefined8 *)0x0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,8,0xc,
                         &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                         "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",0xf3);
    }
    uVar2 = 0xc000009a;
  }
  else {
    *puVar1 = 0;
    puVar1[1] = 0;
    *param_1 = puVar1;
  }
  return uVar2;
}



===== BfPrependVolumeDeviceName @ 1400185dc =====

ulonglong BfPrependVolumeDeviceName(longlong param_1,wchar_t *param_2)

{
  wchar_t *pwVar1;
  wchar_t wVar2;
  uint uVar3;
  ulonglong uVar4;
  wchar_t wVar5;
  ulonglong uVar6;
  undefined2 uVar7;
  undefined1 uVar8;
  undefined1 uVar9;
  wchar_t local_18 [4];
  undefined8 uStack_10;
  
  pwVar1 = (wchar_t *)(param_1 + 8);
  wVar2 = *pwVar1;
  local_18[0] = L'\0';
  local_18[1] = L'\0';
  local_18[2] = L'\0';
  local_18[3] = L'\0';
  uStack_10 = 0;
  wVar5 = wVar2 + *param_2;
  if ((ushort)wVar5 < (ushort)wVar2) {
    uVar6 = 0xc0000095;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0xc0000095;
    }
    uVar9 = 0x95;
    uVar7 = 0x1d;
    uVar8 = 0x24;
LAB_1400186d6:
    WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,8,uVar7,
                        &WPP_529f93b0825532f67776c14f74ba0846_Traceguids,
                        "onecore\\base\\fs\\wci\\bindflt\\filter\\utils.c",uVar8,uVar9);
    return uVar6;
  }
  if ((ushort)param_2[1] < (ushort)wVar5) {
    uVar4 = BfAllocateUnicodeString(wVar5,(undefined4 *)local_18);
    uVar6 = uVar4 & 0xffffffff;
    if ((int)uVar4 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return uVar6;
      }
      uVar9 = (undefined1)uVar4;
      uVar7 = 0x1e;
      uVar8 = 0x41;
      goto LAB_1400186d6;
    }
    uVar3 = RtlAppendUnicodeStringToString(local_18,pwVar1);
    if (((int)uVar3 < 0) ||
       (uVar3 = RtlAppendUnicodeStringToString(local_18,param_2), (int)uVar3 < 0)) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDZd
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,8,0x1f,
                   &WPP_529f93b0825532f67776c14f74ba0846_Traceguids,
                   "onecore\\base\\fs\\wci\\bindflt\\filter\\utils.c",0x4e,local_18,(char)uVar3);
      }
      BfFreeUnicodeString((undefined4 *)local_18);
      return (ulonglong)uVar3;
    }
    ExFreePoolWithTag(*(undefined8 *)(param_2 + 4),0x74734642);
    *(undefined8 *)(param_2 + 4) = uStack_10;
    *param_2 = local_18[0];
    param_2[1] = local_18[1];
  }
  else {
    memmove((void *)((longlong)*(void **)(param_2 + 4) + (ulonglong)((ushort)wVar2 >> 1) * 2),
            *(void **)(param_2 + 4),(ulonglong)(ushort)*param_2);
    *param_2 = *param_2 + *pwVar1;
    memmove(*(void **)(param_2 + 4),*(void **)(param_1 + 0x10),(ulonglong)(ushort)*pwVar1);
  }
  return 0;
}



===== BfpCreateTargetEntry @ 1400187d0 =====

ulonglong BfpCreateTargetEntry(undefined8 *param_1,longlong param_2,longlong *param_3)

{
  short *_Src;
  short *psVar1;
  short sVar2;
  ushort uVar3;
  ushort uVar4;
  uint uVar5;
  longlong lVar6;
  ulonglong uVar7;
  short sVar8;
  longlong lVar9;
  undefined2 uVar10;
  undefined1 uVar11;
  
  lVar6 = ExAllocatePool2(0x100,0x38,0x706d4642);
  if (lVar6 == 0) {
    return 0xc000009a;
  }
  uVar5 = FltObjectReference(*param_1);
  uVar7 = (ulonglong)uVar5;
  if ((int)uVar5 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001894c;
    uVar10 = 0xf;
    uVar11 = 0xc0;
  }
  else {
    FltReferenceContext(param_1);
    *(undefined8 **)(lVar6 + 0x10) = param_1;
    _Src = (short *)(param_2 + 6);
    psVar1 = (short *)(lVar6 + 0x18);
    sVar2 = *_Src;
    sVar8 = *(short *)(param_2 + 4);
    uVar3 = *(ushort *)(param_2 + 2);
    if (sVar2 != 0x5c) {
      sVar8 = *(short *)(param_2 + 4) + 8;
      uVar3 = *(ushort *)(param_2 + 2) + 8;
    }
    uVar7 = BfAllocateUnicodeString(sVar8,(undefined4 *)psVar1);
    uVar5 = (uint)uVar7;
    uVar7 = uVar7 & 0xffffffff;
    if (-1 < (int)uVar5) {
      if (sVar2 != 0x5c) {
        RtlAppendUnicodeStringToString(psVar1,&g_ntNamePrefix);
      }
      *psVar1 = *psVar1 + *(short *)(param_2 + 4);
      *(short *)(lVar6 + 0x1a) = *(short *)(lVar6 + 0x1a) + *(short *)(param_2 + 4);
      if (sVar2 == 0x5c) {
        memmove(*(void **)(lVar6 + 0x20),_Src,(ulonglong)*(ushort *)(param_2 + 4));
        if ((*(short *)(param_2 + 8) == 0x5c) && (*(short *)(param_2 + 10) == 0x3f)) {
          *(undefined2 *)(*(longlong *)(lVar6 + 0x20) + 2) = 0x3f;
        }
      }
      else {
        memmove((void *)((longlong)*(void **)(lVar6 + 0x20) + 8),_Src,
                (ulonglong)*(ushort *)(param_2 + 4));
      }
      uVar4 = *psVar1 - uVar3;
      lVar9 = (ulonglong)uVar3 + *(longlong *)(lVar6 + 0x20);
      *(ushort *)(lVar6 + 0x28) = uVar4;
      *(ushort *)(lVar6 + 0x2a) = uVar4;
      *(longlong *)(lVar6 + 0x30) = lVar9;
      if (*(short *)(lVar9 + -2 + (ulonglong)(uVar4 >> 1) * 2) == 0x5c) {
        if ((*(int *)(param_1 + 3) == 6) || (*(int *)(param_1 + 3) == 0xd)) {
          if (2 < uVar4) {
            *(ushort *)(lVar6 + 0x28) = uVar4 - 2;
          }
        }
        else if (2 < uVar4) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_sDL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
          }
          uVar7 = 0xc000000d;
          goto LAB_14001894c;
        }
      }
      *param_3 = lVar6;
      return 0;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001894c;
    uVar10 = 0x10;
    uVar11 = 0xd9;
  }
  WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,8,uVar10,
                      &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                      "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",uVar11,(char)uVar5);
LAB_14001894c:
  BfpDeleteTargetEntry(lVar6);
  return uVar7;
}



===== BfpCreatePathTierNode @ 140018a54 =====

ulonglong BfpCreatePathTierNode
                    (longlong param_1,uint param_2,char param_3,undefined4 param_4,
                    undefined8 *param_5,longlong param_6,longlong *param_7,undefined8 param_8,
                    undefined8 *param_9)

{
  longlong lVar1;
  short sVar2;
  undefined8 uVar3;
  code *pcVar4;
  uint *puVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined2 uVar10;
  undefined1 auStackY_78 [8];
  undefined1 auStackY_70 [24];
  undefined8 local_38;
  longlong lStack_30;
  
  *param_9 = 0;
  puVar5 = (uint *)ExAllocatePool2(0x100,0x60,0x706d4642);
  if (puVar5 == (uint *)0x0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,8,0x13,
                         &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                         "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",0x36);
    }
    return 0xc000009a;
  }
  uVar6 = BfAllocateUnicodeString(*(short *)(param_1 + 2),puVar5 + 8);
  puVar8 = auStackY_78;
  puVar9 = auStackY_78;
  uVar7 = uVar6 & 0xffffffff;
  if ((int)uVar6 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140018c4e;
    uVar10 = 0x14;
  }
  else {
    RtlCopyUnicodeString(puVar5 + 8,param_1);
    puVar5[0x16] = 0;
    puVar5[0x17] = 0;
    *puVar5 = param_2;
    if (param_3 != '\0') {
      if ((param_2 & 10) == 0) {
        uVar6 = BfpCreatePathTree((undefined8 *)(puVar5 + 0x14));
        puVar8 = auStackY_78;
        puVar9 = auStackY_78;
        uVar7 = uVar6 & 0xffffffff;
        if ((int)uVar6 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_140018c4e;
          uVar10 = 0x15;
          goto LAB_140018ca1;
        }
      }
      else {
        *(undefined8 *)(puVar5 + 0x14) = param_8;
      }
    }
    puVar8 = auStackY_78;
    if ((param_2 & 1) == 0) {
      if ((param_2 & 2) != 0) goto LAB_140018bf6;
LAB_140018ba1:
      if ((param_2 & 5) == 0) {
LAB_140018bf6:
        *param_9 = puVar5;
        return 0;
      }
      sVar2 = *(short *)(param_6 + 4);
      lStack_30 = param_6 + 6;
      local_38 = (ulonglong)CONCAT22(sVar2,sVar2);
      uVar6 = BfAllocateUnicodeString(sVar2,puVar5 + 0xe);
      uVar7 = uVar6 & 0xffffffff;
      if (-1 < (int)uVar6) {
        RtlCopyUnicodeString(puVar5 + 0xe,&local_38);
        *(undefined8 *)(puVar5 + 0xc) = *param_5;
        goto LAB_140018bf6;
      }
      puVar8 = auStackY_78;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140018c4e;
      uVar10 = 0x19;
      puVar9 = auStackY_78;
    }
    else if ((param_2 & 2) == 0) {
      if ((*(int *)(param_5 + 3) == 6) || (*(int *)(param_5 + 3) == 0xd)) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,8,0x17,
                             &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                             "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",0x88);
        }
        uVar7 = 0xc00000bb;
        goto LAB_140018c4e;
      }
      uVar6 = BfpCreateMappingInformation(param_6,param_4,(undefined8 *)(puVar5 + 0x12));
      uVar7 = uVar6 & 0xffffffff;
      if (-1 < (int)uVar6) goto LAB_140018ba1;
      puVar8 = auStackY_78;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140018c4e;
      uVar10 = 0x18;
      puVar9 = auStackY_78;
    }
    else {
      LOCK();
      lVar1 = *param_7;
      *param_7 = *param_7 + 1;
      UNLOCK();
      puVar8 = auStackY_78;
      if (lVar1 + 1 < 2) {
        pcVar4 = (code *)swi(0x29);
        (*pcVar4)(0xe);
        puVar8 = auStackY_70;
      }
      *(longlong **)(puVar5 + 0x12) = param_7;
      sVar2 = *(short *)(param_1 + 2);
      *(undefined8 *)(puVar8 + -8) = 0x140018d21;
      uVar6 = BfAllocateUnicodeString(sVar2,(undefined4 *)(param_7 + 4));
      uVar7 = uVar6 & 0xffffffff;
      if (-1 < (int)uVar6) {
        lVar1 = *(longlong *)(puVar5 + 0x12);
        *(undefined8 *)(puVar8 + -8) = 0x140018d39;
        RtlCopyUnicodeString(lVar1 + 0x20,param_1);
        goto LAB_140018bf6;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140018c4e;
      *(int *)(puVar8 + 0x38) = (int)uVar6;
      uVar10 = 0x16;
      *(undefined4 *)(puVar8 + 0x30) = 0x47a;
      puVar9 = puVar8;
    }
  }
LAB_140018ca1:
  *(char **)(puVar9 + 0x28) = "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c";
  *(undefined **)(puVar9 + 0x20) = &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids;
  uVar3 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
  *(undefined8 *)(puVar9 + -8) = 0x140018cd1;
  WPP_RECORDER_SF_sDd(uVar3,2,8,uVar10,*(undefined8 *)(puVar9 + 0x20),*(char **)(puVar9 + 0x28),
                      puVar9[0x30],puVar9[0x38]);
  puVar8 = puVar9;
LAB_140018c4e:
  *(undefined8 *)(puVar8 + -8) = 0x140018c56;
  BfpDeletePathTierNode(puVar5);
  return uVar7;
}



===== BfAllocateUnicodeString @ 140018e10 =====

undefined8 BfAllocateUnicodeString(short param_1,undefined4 *param_2)

{
  short sVar1;
  longlong lVar2;
  undefined8 uVar3;
  
  *param_2 = 0;
  sVar1 = 1;
  if (param_1 != 0) {
    sVar1 = param_1;
  }
  lVar2 = ExAllocatePool2(0x100,sVar1,0x74734642);
  *(longlong *)(param_2 + 2) = lVar2;
  if (lVar2 == 0) {
    uVar3 = 0xc000009a;
  }
  else {
    *(short *)((longlong)param_2 + 2) = sVar1;
    uVar3 = 0;
  }
  return uVar3;
}



===== BfpCreateMappingInformation @ 140018e74 =====

ulonglong BfpCreateMappingInformation(longlong param_1,undefined4 param_2,undefined8 *param_3)

{
  ushort *puVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  ulonglong uVar4;
  ushort uVar5;
  
  puVar3 = (undefined8 *)ExAllocatePool2(0x100,0x50,0x706d4642);
  if (puVar3 == (undefined8 *)0x0) {
    uVar4 = 0xc000009a;
  }
  else {
    puVar1 = (ushort *)(puVar3 + 2);
    if ((uint)*(ushort *)(param_1 + 4) - (uint)*(ushort *)(param_1 + 2) == 2) {
      *puVar1 = 0;
      puVar3[3] = 0;
    }
    else {
      uVar4 = BfAllocateUnicodeString
                        (*(ushort *)(param_1 + 4) - *(ushort *)(param_1 + 2),(undefined4 *)puVar1);
      if ((int)uVar4 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,8,0x12,
                              &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                              "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",0x5d,(char)uVar4)
          ;
        }
        BfpDeleteMappingInformation((longlong)puVar3);
        return uVar4 & 0xffffffff;
      }
      uVar5 = *(short *)(param_1 + 4) - *(short *)(param_1 + 2);
      *puVar1 = uVar5;
      memmove((void *)puVar3[3],
              (void *)(param_1 + ((ulonglong)(*(ushort *)(param_1 + 2) >> 1) + 3) * 2),
              (ulonglong)uVar5);
    }
    puVar2 = puVar3 + 8;
    uVar4 = 0;
    puVar3[9] = puVar2;
    *puVar2 = puVar2;
    *(undefined4 *)(puVar3 + 1) = param_2;
    *(undefined1 *)(puVar3 + 6) = 0;
    *puVar3 = 1;
    *param_3 = puVar3;
  }
  return uVar4;
}



===== BfpDeletePathTree @ 140018fcc =====

void BfpDeletePathTree(undefined8 *param_1)

{
  byte *pbVar1;
  byte bVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  
  pbVar1 = (byte *)(param_1 + 1);
  puVar3 = (undefined8 *)*param_1;
  if (((*pbVar1 & 1) != 0) && (puVar3 != (undefined8 *)0x0)) {
    puVar3 = (undefined8 *)((ulonglong)puVar3 ^ (ulonglong)param_1);
  }
  bVar2 = *pbVar1;
  if (puVar3 == (undefined8 *)0x0) {
LAB_140019004:
    bVar2 = *pbVar1;
    *param_1 = 0;
    param_1[1] = 0;
    if ((bVar2 & 1) != 0) {
      *(undefined1 *)(param_1 + 1) = 1;
    }
    ExFreePoolWithTag(param_1,0x706d4642);
    return;
  }
  do {
    while (puVar5 = (undefined8 *)*puVar3, puVar5 != (undefined8 *)0x0) {
      puVar4 = puVar3;
LAB_14001907e:
      if ((bVar2 & 1) == 0) {
        puVar3 = puVar5;
      }
      else {
        puVar3 = (undefined8 *)((ulonglong)puVar3 ^ (ulonglong)puVar5);
      }
      *puVar4 = 0;
    }
    puVar5 = (undefined8 *)puVar3[1];
    puVar4 = puVar3 + 1;
    if (puVar5 != (undefined8 *)0x0) goto LAB_14001907e;
    puVar5 = (undefined8 *)(puVar3[2] & 0xfffffffffffffffc);
    if (((bVar2 & 1) != 0) && (puVar5 != (undefined8 *)0x0)) {
      puVar5 = (undefined8 *)((ulonglong)puVar5 ^ (ulonglong)puVar3);
    }
    BfpRBTreeDeletePathTierNode((longlong)puVar3);
    if (puVar5 == (undefined8 *)0x0) goto LAB_140019004;
    puVar3 = puVar5;
  } while( true );
}



===== BfpDeleteMappingInformation @ 1400190c0 =====

void BfpDeleteMappingInformation(longlong param_1)

{
  longlong *plVar1;
  code *pcVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  undefined1 *puVar5;
  undefined8 uStack_30;
  undefined1 auStack_28 [32];
  
  puVar5 = auStack_28;
  plVar1 = (longlong *)(param_1 + 0x40);
  while ((longlong *)*plVar1 != plVar1) {
    puVar4 = *(undefined8 **)(param_1 + 0x48);
    if (((longlong *)*puVar4 != plVar1) ||
       (plVar3 = (longlong *)puVar4[1], (undefined8 *)*plVar3 != puVar4)) {
      puVar4 = (undefined8 *)0x3;
      pcVar2 = (code *)swi(0x29);
      plVar3 = (longlong *)(*pcVar2)();
      puVar5 = puVar5 + 8;
    }
    *(longlong **)(param_1 + 0x48) = plVar3;
    *plVar3 = (longlong)plVar1;
    *(undefined8 *)(puVar5 + -8) = 0x1400190fb;
    BfpDeleteTargetEntry((longlong)puVar4);
  }
  *(undefined8 *)(puVar5 + -8) = 0x140019106;
  BfFreeUnicodeString((undefined4 *)(param_1 + 0x10));
  *(undefined8 *)(puVar5 + -8) = 0x14001910f;
  BfFreeUnicodeString((undefined4 *)(param_1 + 0x20));
  *(undefined8 *)(puVar5 + -8) = 0x14001911e;
  ExFreePoolWithTag(param_1,0x706d4642);
  return;
}



===== BfpDeleteTargetEntry @ 140019138 =====

void BfpDeleteTargetEntry(longlong param_1)

{
  int *piVar1;
  
  if (*(longlong *)(param_1 + 0x10) != 0) {
    LOCK();
    piVar1 = (int *)(*(longlong *)(param_1 + 0x10) + 0x24);
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    FltObjectDereference(**(undefined8 **)(param_1 + 0x10));
    FltReleaseContext(*(undefined8 *)(param_1 + 0x10));
  }
  BfFreeUnicodeString((undefined4 *)(param_1 + 0x18));
  ExFreePoolWithTag(param_1,0x706d4642);
  return;
}



===== BfpRBTreeDeletePathTierNode @ 14001919c =====

void BfpRBTreeDeletePathTierNode(longlong param_1)

{
  if (((*(uint *)(param_1 + -8) & 2) == 0) &&
     (*(undefined8 **)(param_1 + 0x48) != (undefined8 *)0x0)) {
    BfpDeletePathTree(*(undefined8 **)(param_1 + 0x48));
    *(undefined8 *)(param_1 + 0x48) = 0;
  }
  BfpDeletePathTierNode((uint *)(param_1 + -8));
  return;
}



===== BfpDeletePathTierNode @ 1400191d4 =====

void BfpDeletePathTierNode(uint *param_1)

{
  if (((*param_1 & 10) == 0) && (*(undefined8 **)(param_1 + 0x14) != (undefined8 *)0x0)) {
    BfpDeletePathTree(*(undefined8 **)(param_1 + 0x14));
    param_1[0x14] = 0;
    param_1[0x15] = 0;
  }
  if (*(longlong **)(param_1 + 0x12) != (longlong *)0x0) {
    BfReleaseMappingInformation(*(longlong **)(param_1 + 0x12));
  }
  BfFreeUnicodeString(param_1 + 8);
  BfFreeUnicodeString(param_1 + 0xe);
  ExFreePoolWithTag(param_1,0x706d4642);
  return;
}



===== BfCreateHandleContext @ 14001923c =====

ulonglong BfCreateHandleContext
                    (undefined8 param_1,undefined8 param_2,longlong param_3,longlong *param_4,
                    short *param_5,longlong param_6,undefined8 param_7,undefined8 *param_8)

{
  undefined8 uVar1;
  void *pvVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined2 uVar5;
  undefined1 uVar6;
  void *local_28 [2];
  
  uVar1 = g_BindFltState;
  local_28[0] = (void *)0x0;
  *param_8 = 0;
  uVar3 = FltAllocateContext(uVar1,0x10,0x98,0x200,local_28);
  uVar4 = (ulonglong)uVar3;
  if ((int)uVar3 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140019330;
    uVar5 = 0x14;
    uVar6 = 0xd2;
  }
  else {
    memset(local_28[0],0,0x98);
    KeInitializeEvent((longlong)local_28[0] + 0x80,1,1);
    uVar4 = BfInitShadowFileHandleContext
                      (param_1,param_2,param_3,param_4,param_5,param_6,param_7,local_28);
    pvVar2 = local_28[0];
    uVar3 = (uint)uVar4;
    uVar4 = uVar4 & 0xffffffff;
    if (-1 < (int)uVar3) {
      local_28[0] = (void *)0x0;
      *param_8 = pvVar2;
      goto LAB_140019330;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140019330;
    uVar5 = 0x15;
    uVar6 = 0xe4;
  }
  WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,7,uVar5,
                      &WPP_ab4056511ca038337f1519c30a6fffbb_Traceguids,
                      "onecore\\base\\fs\\wci\\bindflt\\filter\\context.c",uVar6,(char)uVar3);
LAB_140019330:
  if (local_28[0] != (void *)0x0) {
    FltReleaseContext();
  }
  return uVar4;
}



===== BfFreeMappingLookupEntry @ 1400193f4 =====

void BfFreeMappingLookupEntry(longlong param_1)

{
  BfFreeUnicodeString((undefined4 *)(param_1 + 0x10));
  BfReleaseMappingInformation(*(longlong **)(param_1 + 0x20));
  ExFreePoolWithTag(param_1,0x706d4642);
  return;
}



===== BfFreeUnicodeString @ 140019430 =====

void BfFreeUnicodeString(undefined4 *param_1)

{
  if (*(longlong *)(param_1 + 2) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 2),0x74734642);
    *(undefined8 *)(param_1 + 2) = 0;
  }
  *param_1 = 0;
  return;
}



===== BfpValidateReadOnlyCreate @ 140019474 =====

ulonglong BfpValidateReadOnlyCreate(longlong param_1,char param_2)

{
  byte bVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined2 uVar6;
  undefined1 uVar7;
  
  uVar4 = *(uint *)(*(longlong *)(*(longlong *)(param_1 + 0x10) + 0x18) + 0x10);
  uVar3 = uVar4 | 0x1200a9;
  uVar5 = (ulonglong)uVar3;
  if (uVar3 != 0x1200a9) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar5 = WPP_RECORDER_SF_sDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,5,0x10,
                                  &WPP_48a527b79fd4344d8b4157379f595642_Traceguids,
                                  "onecore\\base\\fs\\wci\\bindflt\\filter\\create.c",0xce,
                                  (char)uVar4);
    }
    goto LAB_140019535;
  }
  bVar1 = *(byte *)(*(longlong *)(param_1 + 0x10) + 0x23);
  uVar5 = 0;
  if (bVar1 == 0) {
LAB_140019609:
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140019535;
    uVar6 = 0x11;
    uVar7 = 0xdd;
  }
  else {
    uVar4 = (uint)bVar1;
    uVar5 = (ulonglong)(uVar4 - 1);
    if (uVar4 - 1 != 0) {
      uVar5 = (ulonglong)(uVar4 - 2);
      if (uVar4 - 2 != 0) {
        if (uVar4 == 3) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,5,0x12,
                               &WPP_48a527b79fd4344d8b4157379f595642_Traceguids,
                               "onecore\\base\\fs\\wci\\bindflt\\filter\\create.c",0xe8);
          }
          uVar5 = *(ulonglong *)(param_1 + 0x10);
          *(uint *)(uVar5 + 0x20) = *(uint *)(uVar5 + 0x20) ^ 0x2000000;
          goto LAB_1400194fc;
        }
        uVar4 = uVar4 - 4;
        uVar5 = (ulonglong)uVar4;
        if ((uVar4 != 0) && (uVar4 != 1)) goto LAB_140019535;
      }
      goto LAB_140019609;
    }
LAB_1400194fc:
    if (param_2 != '\0') {
LAB_140019505:
      return CONCAT71((int7)(uVar5 >> 8),1);
    }
    lVar2 = *(longlong *)(param_1 + 0x10);
    if ((*(ushort *)(lVar2 + 0x2a) & 1) != 0) goto LAB_140019505;
    uVar5 = *(ulonglong *)(lVar2 + 8);
    if ((*(uint *)(uVar5 + 0x50) & 0x2000000) == 0) {
      *(ushort *)(lVar2 + 0x2a) = *(ushort *)(lVar2 + 0x2a) | 1;
      goto LAB_140019505;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140019535;
    uVar6 = 0x13;
    uVar7 = 0xb;
  }
  uVar5 = WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,5,uVar6,
                             &WPP_48a527b79fd4344d8b4157379f595642_Traceguids,
                             "onecore\\base\\fs\\wci\\bindflt\\filter\\create.c",uVar7);
LAB_140019535:
  return uVar5 & 0xffffffffffffff00;
}



===== BfGetSetHandleContext @ 140019668 =====

ulonglong BfGetSetHandleContext
                    (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                    longlong param_5,longlong *param_6,short *param_7,longlong param_8,
                    undefined8 param_9,undefined8 *param_10)

{
  undefined8 uVar1;
  uint uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  undefined8 local_38;
  undefined8 local_30;
  
  local_30 = 0;
  local_38 = 0;
  uVar3 = BfCreateHandleContext(param_3,param_4,param_5,param_6,param_7,param_8,param_9,&local_30);
  uVar1 = local_30;
  if ((int)uVar3 < 0) {
    *param_10 = 0;
  }
  else {
    uVar2 = FltSetStreamHandleContext(param_2,param_1,1,local_30,&local_38);
    uVar3 = (ulonglong)uVar2;
    if ((int)uVar2 < 0) {
      FltReleaseContext(uVar1);
      if (uVar2 == 0xc01c0002) {
        uVar4 = BfInitShadowFileHandleContext
                          (param_3,param_4,param_5,param_6,param_7,param_8,param_9,&local_38);
        uVar3 = uVar4 & 0xffffffff;
        if ((int)uVar4 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,7,0x17,
                                &WPP_ab4056511ca038337f1519c30a6fffbb_Traceguids,
                                "onecore\\base\\fs\\wci\\bindflt\\filter\\context.c",0x57,
                                (char)uVar4);
          }
          *param_10 = 0;
        }
        else {
          *param_10 = local_38;
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,7,0x18,
                               &WPP_ab4056511ca038337f1519c30a6fffbb_Traceguids,
                               "onecore\\base\\fs\\wci\\bindflt\\filter\\context.c",0x5d);
          }
          uVar3 = 0;
        }
      }
      else {
        *param_10 = 0;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,7,0x16,
                              &WPP_ab4056511ca038337f1519c30a6fffbb_Traceguids,
                              "onecore\\base\\fs\\wci\\bindflt\\filter\\context.c",0x49,(char)uVar2)
          ;
        }
      }
    }
    else {
      *param_10 = uVar1;
    }
  }
  return uVar3;
}



===== BfpHandleNetworkQueryOpen @ 1400198cc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int BfpHandleNetworkQueryOpen
              (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
              char param_5)

{
  longlong lVar1;
  undefined8 *puVar2;
  int iVar3;
  undefined1 auStack_138 [32];
  undefined8 *local_118;
  undefined4 local_110;
  undefined4 local_108;
  undefined8 *local_100;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined8 local_f0;
  undefined8 local_e8;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined8 local_48;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_138;
  local_dc = 0;
  local_f4 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  memset(&local_88,0,0x48);
  local_a8 = 0;
  uStack_c0 = 0;
  local_c8 = 0x28;
  local_b8 = 0;
  uStack_b0 = 0;
  if (param_5 == '\0') {
    local_a8 = PsGetHostSilo();
  }
  else {
    local_a8 = IoGetSilo(param_2);
  }
  local_f0 = 0;
  local_100 = &local_c8;
  local_f8 = 0x30;
  local_108 = 0x44;
  local_118 = &local_88;
  local_110 = 0x48;
  local_e0 = 0x200;
  local_d8 = 0;
  uStack_d0 = 0;
  local_e8 = param_4;
  iVar3 = FltQueryInformationByName(g_BindFltState,param_3,&local_f8,&local_a0);
  if (-1 < iVar3) {
    lVar1 = *(longlong *)(param_1 + 0x10);
    if (*(char *)(lVar1 + 4) == -0xe) {
      *(undefined8 *)(*(longlong *)(lVar1 + 0x20) + 0x20) = uStack_60;
      *(undefined8 *)(*(longlong *)(*(longlong *)(param_1 + 0x10) + 0x20) + 0x18) = local_68;
      **(undefined8 **)(*(longlong *)(param_1 + 0x10) + 0x20) = uStack_80;
      *(undefined8 *)(*(longlong *)(*(longlong *)(param_1 + 0x10) + 0x20) + 0x28) = local_58;
      *(undefined4 *)(*(longlong *)(*(longlong *)(param_1 + 0x10) + 0x20) + 0x30) = uStack_50;
      *(undefined8 *)(*(longlong *)(*(longlong *)(param_1 + 0x10) + 0x20) + 8) = local_78;
      *(undefined8 *)(*(longlong *)(*(longlong *)(param_1 + 0x10) + 0x20) + 0x10) = uStack_70;
    }
    else if (*(char *)(lVar1 + 4) == -7) {
      if (*(int *)(lVar1 + 0x30) != 0x44) {
        return -0x3fffff45;
      }
      puVar2 = *(undefined8 **)(lVar1 + 0x20);
      *puVar2 = local_88;
      puVar2[1] = uStack_80;
      puVar2[2] = local_78;
      puVar2[3] = uStack_70;
      puVar2[4] = local_68;
      puVar2[5] = uStack_60;
      puVar2[6] = local_58;
      puVar2[7] = CONCAT44(uStack_4c,uStack_50);
      puVar2[8] = local_48;
    }
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  return iVar3;
}



===== BfPreCreate @ 140019ac0 =====

/* WARNING: Removing unreachable block (ram,0x00014001af01) */

char BfPreCreate(longlong param_1,longlong param_2)

{
  byte *pbVar1;
  short *psVar2;
  undefined8 ****ppppuVar3;
  code *pcVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  longlong *plVar8;
  uint uVar9;
  int iVar10;
  undefined8 *puVar11;
  ulonglong uVar12;
  undefined8 *****pppppuVar13;
  longlong lVar14;
  ulonglong uVar15;
  undefined8 uVar16;
  wchar_t *pwVar17;
  undefined8 ***pppuVar18;
  uint uVar19;
  uint *puVar20;
  byte bVar21;
  char cVar22;
  uint uVar23;
  undefined1 *puVar24;
  longlong *plVar25;
  undefined8 *****pppppuVar26;
  uint uVar27;
  longlong *plVar28;
  undefined2 uVar29;
  char cVar30;
  ulonglong local_res8;
  ulonglong local_res10;
  char local_res20 [8];
  undefined8 uStackY_1b0;
  undefined1 auStackY_1a8 [32];
  char *pcVar31;
  undefined1 uVar32;
  undefined1 uVar33;
  ulonglong local_140;
  uint local_134;
  longlong local_130;
  undefined8 ****local_128;
  longlong lStack_120;
  uint local_118;
  uint local_114;
  uint *local_110;
  undefined8 *****local_108;
  undefined2 local_100;
  uint local_fc;
  undefined8 *****local_f8;
  undefined8 *****local_f0;
  longlong *local_e8;
  longlong local_e0;
  undefined8 *****local_d8;
  undefined8 *****local_d0;
  longlong local_c8;
  longlong *local_c0;
  undefined8 ****local_b8;
  longlong local_b0;
  uint local_a8;
  uint local_a4;
  uint local_a0;
  undefined8 *****local_98;
  undefined8 *****local_90;
  uint local_88;
  longlong local_80;
  longlong local_78;
  ulonglong local_70;
  longlong lStack_68;
  ulonglong local_60;
  longlong lStack_58;
  longlong *local_50;
  undefined8 ****local_48;
  undefined8 *****local_40;
  
  pppppuVar26 = *(undefined8 ******)(param_2 + 0x18);
  local_130 = 0;
  lVar14 = *(longlong *)(param_1 + 0x10);
  local_134 = 0xc0000034;
  local_f8 = pppppuVar26;
  local_98 = (undefined8 *****)0x0;
  bVar21 = *(byte *)(lVar14 + 6);
  uVar12 = 0;
  local_b0 = 0;
  local_128 = (undefined8 ****)0x0;
  lStack_120 = 0;
  local_e0 = 0;
  local_80 = 0;
  local_88 = *(uint *)(lVar14 + 0x20);
  local_a4 = *(uint *)(lVar14 + 0x20) >> 0x18;
  local_d0 = &local_d8;
  local_d8 = &local_d8;
  local_c8 = 0;
  local_110 = (uint *)0x0;
  local_140 = 0;
  local_78 = 0;
  local_res20[0] = '\0';
  local_50 = (longlong *)0x0;
  local_e8 = (longlong *)0x0;
  local_c0 = (longlong *)0x0;
  local_a8 = local_a8 & 0xffffff00;
  local_res8 = local_res8 & 0xffffffffffffff00;
  bVar7 = false;
  local_a0 = 0xc000003a;
  local_res10 = local_res10 & 0xffffffffffffff00;
  local_100 = *(undefined2 *)(lVar14 + 0x2a);
  local_fc = 1;
  local_b8 = (undefined8 ****)0x0;
  local_90 = (undefined8 *****)0x0;
  local_48 = (undefined8 ****)0x0;
  local_118 = 0;
  if ((*(uint *)(*(longlong *)(lVar14 + 8) + 0x50) & 0x400000) != 0) {
    cVar30 = '\x01';
    goto LAB_140019fa0;
  }
  if (((*(char *)(lVar14 + 4) == '\0') &&
      (FltGetEcpListFromCallbackData(g_BindFltState,param_1,&local_c8), local_c8 != 0)) &&
     (FltFindExtraCreateParameter(g_BindFltState,local_c8,&ECP_TYPE_REPARSED_BY_BINDFLT,&local_110),
     local_110 != (uint *)0x0)) {
    if ((((*local_110 & 1) != 0) &&
        (lVar14 = IoGetSilo(*(undefined8 *)(param_2 + 0x20)), lVar14 == *(longlong *)(local_110 + 2)
        )) && ((*(uint *)(*(longlong *)(*(longlong *)(param_1 + 0x10) + 0x18) + 0x10) & 6) != 0)) {
      cVar30 = '\0';
      goto LAB_140019fa0;
    }
    goto LAB_140019f9b;
  }
  uVar9 = FltGetInstanceContext(pppppuVar26,&local_b0);
  if ((int)uVar9 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001a9f1;
    uVar33 = (undefined1)uVar9;
    uVar29 = 0x14;
    uVar32 = 0x8c;
LAB_14001ac44:
    WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,uVar29,
                        &WPP_48a527b79fd4344d8b4157379f595642_Traceguids,
                        "onecore\\base\\fs\\wci\\bindflt\\filter\\create.c",uVar32,uVar33);
    goto LAB_14001a9f1;
  }
  pcVar31 = (char *)&local_c0;
  puVar11 = BfGetMappingContexts
                      (*(undefined8 *)(param_2 + 0x20),local_b0,param_1,&local_50,&local_e8,
                       (undefined8 *)pcVar31);
  plVar8 = local_50;
  uVar9 = (uint)puVar11;
  if ((int)uVar9 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar33 = SUB81(puVar11,0);
      uVar29 = 0x15;
      uVar32 = 0x94;
      goto LAB_14001ac44;
    }
    goto LAB_14001a9f1;
  }
  if (local_50 == (longlong *)0x0) {
LAB_140019c3f:
    plVar25 = local_e8;
    if (local_e8 != (longlong *)0x0) {
      FltAcquireResourceShared(local_e8 + 2);
      if ((longlong *)*plVar25 == plVar25) {
        FltReleaseResource();
        goto LAB_140019c4e;
      }
      FltReleaseResource(plVar25 + 2);
      plVar28 = local_c0;
      goto LAB_140019c88;
    }
LAB_140019c4e:
    plVar28 = local_c0;
    if (local_c0 != (longlong *)0x0) {
      FltAcquireResourceShared(local_c0 + 2);
      if ((longlong *)*plVar28 != plVar28) {
        FltReleaseResource();
        goto LAB_140019c84;
      }
      FltReleaseResource(plVar28 + 2);
    }
    lVar14 = *(longlong *)(*(longlong *)(param_2 + 0x20) + 0x40);
    if (lVar14 != 0) {
      local_res8 = 0;
      if ((((*(short **)(lVar14 + 0x18) != (short *)0x0) && (**(short **)(lVar14 + 0x18) == 0x6431))
          && (iVar10 = FltGetStreamHandleContext(*(undefined8 *)(param_2 + 0x18),lVar14,&local_res8)
             , -1 < iVar10)) &&
         (bVar21 = *(byte *)(local_res8 + 0x50), FltReleaseContext(), (bVar21 & 1) != 0)) {
        uVar9 = 0xc000003a;
        goto LAB_14001a9f1;
      }
    }
  }
  else {
    FltAcquireResourceShared(local_50 + 2);
    if ((longlong *)*plVar8 == plVar8) {
      FltReleaseResource();
      goto LAB_140019c3f;
    }
    FltReleaseResource(plVar8 + 2);
    plVar28 = local_c0;
LAB_140019c84:
    plVar25 = local_e8;
LAB_140019c88:
    if ((*(char *)(*(longlong *)(param_1 + 0x10) + 4) == '\0') &&
       ((*(uint *)(*(longlong *)(param_1 + 0x10) + 0x20) & 0x2000) != 0)) {
      lVar14 = *(longlong *)(*(longlong *)(param_2 + 0x20) + 0x40);
      if (lVar14 != 0) {
        local_res8 = 0;
        if ((((*(short **)(lVar14 + 0x18) != (short *)0x0) &&
             (**(short **)(lVar14 + 0x18) == 0x6431)) &&
            (iVar10 = FltGetStreamHandleContext(*(undefined8 *)(param_2 + 0x18),lVar14,&local_res8),
            -1 < iVar10)) &&
           (bVar21 = *(byte *)(local_res8 + 0x50), FltReleaseContext(), (bVar21 & 1) != 0)) {
          uVar9 = 0xc00000bb;
          goto LAB_14001a9f1;
        }
      }
    }
    else {
      uVar12 = BfGetPreCreateFileName
                         (param_1,*(longlong *)(param_2 + 0x20),*(longlong *)(param_2 + 0x18),
                          &local_130,(short *)local_res20);
      uVar9 = (uint)uVar12;
      if ((int)uVar9 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar33 = (undefined1)uVar12;
          uVar29 = 0x16;
          uVar32 = 0xce;
          goto LAB_14001ac44;
        }
        goto LAB_14001a9f1;
      }
      if (*(short *)(local_130 + 8) != *(short *)(local_130 + 0x18)) {
        uVar12 = BfCombinedMappingLookup
                           (plVar28,plVar25,plVar8,(longlong)local_f8,local_130,pcVar31,
                            (byte)~bVar21 >> 7,(longlong *)&local_d8);
        uVar9 = (uint)uVar12;
        if (uVar9 != 0xc000003a) {
          if ((int)uVar9 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar33 = (undefined1)uVar12;
              uVar29 = 0x17;
              uVar32 = 0xe;
              goto LAB_14001ac44;
            }
            goto LAB_14001a9f1;
          }
          bVar21 = *(byte *)(*(longlong *)(param_1 + 0x10) + 6);
          uVar12 = local_140;
          if (((bVar21 & 4) != 0) && (*(longlong *)(*(longlong *)(param_2 + 0x20) + 0x40) == 0)) {
            *(byte *)(*(longlong *)(param_1 + 0x10) + 6) = bVar21 & 0xfb;
            FltReleaseFileNameInformation(local_130);
            local_130 = 0;
            uVar9 = FltGetFileNameInformation(param_1,0x302);
            if (((int)uVar9 < 0) ||
               ((*(short *)(local_130 + 8) != 0 || (*(short *)(local_130 + 0x18) == 0)))) {
              if (-1 < (int)uVar9) {
                iVar10 = FltParseFileNameInformation();
                if (iVar10 < 0) {
                  if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
                    cVar30 = '\x04';
                    uVar12 = 0;
                  }
                  else {
                    WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x19,
                                        &WPP_48a527b79fd4344d8b4157379f595642_Traceguids,
                                        "onecore\\base\\fs\\wci\\bindflt\\filter\\create.c",0x4c,
                                        (char)iVar10);
                    cVar30 = '\x04';
                  }
                  goto LAB_140019fa0;
                }
                pbVar1 = (byte *)(*(longlong *)(param_1 + 0x10) + 6);
                *pbVar1 = *pbVar1 | 4;
                goto LAB_140019d2a;
              }
            }
            else {
              uVar9 = 0xc000000d;
            }
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar33 = (undefined1)uVar9;
              uVar29 = 0x18;
              uVar32 = 0x45;
              goto LAB_14001ac44;
            }
            goto LAB_14001a9f1;
          }
LAB_140019d2a:
          bVar6 = false;
          uVar23 = local_118;
          if (*(char *)(*(longlong *)(param_1 + 0x10) + 4) == '\0') {
            pppppuVar26 = local_d8;
            uVar9 = 0;
LAB_14001a624:
            local_f0 = pppppuVar26;
            if ((undefined8 ******)pppppuVar26 != &local_d8) {
              local_108 = pppppuVar26 + 4;
              local_114 = uVar9 + 1;
              if (uVar23 == 1) {
                if (((ulonglong)(*local_108)[1] & 2) == 0) goto LAB_140019d49;
              }
              else {
              }
              pppppuVar13 = (undefined8 *****)(*local_108)[8];
LAB_14001a664:
              do {
                if (pppppuVar13 == (undefined8 *****)(*local_108 + 8)) goto LAB_14001a864;
                if ((uVar23 == 1) && (pppppuVar13 == (undefined8 *****)(*local_108)[9])) {
                  bVar6 = true;
                }
                else if (local_114 != 1) {
                  bVar6 = true;
                }
                local_98 = pppppuVar13;
                if (lStack_120 != 0) {
                  ExFreePoolWithTag();
                  lStack_120 = 0;
                }
                lVar14 = local_130;
                local_128 = (undefined8 ****)((ulonglong)local_128 & 0xffffffff00000000);
                bVar5 = false;
                local_70 = 0;
                lStack_68 = 0;
                local_f8 = (undefined8 *****)*pppppuVar13[2];
                uVar15 = BfFormatPathFromFileNameInfo(local_130,'\0',(undefined4 *)&local_70);
                pppppuVar26 = local_f0;
                uVar9 = (uint)uVar15;
                if ((int)uVar9 < 0) {
                  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                    pcVar31 = "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c";
                    WPP_RECORDER_SF_sDZd
                              (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,8,0x55,
                               &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                               "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",0xa1,
                               (wchar_t *)(lVar14 + 8),(char)uVar15);
                  }
                  pppppuVar26 = local_f0;
                }
                else {
                  uVar15 = BfReplaceFirstSubstring
                                     ((ushort *)&local_70,(ushort *)(local_f0 + 2),
                                      (ushort *)(pppppuVar13 + 5),(undefined4 *)&local_128);
                  uVar9 = (uint)uVar15;
                  if ((int)uVar9 < 0) {
                    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                      pcVar31 = "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c";
                      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,8,0x56,
                                          &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                                          "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",0xa9,
                                          (char)uVar15);
                    }
                  }
                  else {
                    bVar5 = true;
                    uVar9 = BfPrependVolumeNameFromInstance(local_f8,(short *)&local_128);
                    if ((int)uVar9 < 0) {
                      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                        pcVar31 = "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c";
                        WPP_RECORDER_SF_sDZd
                                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,8,0x57,
                                   &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                                   "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",0xb4,
                                   (wchar_t *)&local_128,(char)uVar9);
                      }
                    }
                    else {
                      bVar5 = false;
                    }
                  }
                }
                if (lStack_68 != 0) {
                  ExFreePoolWithTag(lStack_68,0x74734642);
                  lStack_68 = 0;
                }
                local_70 = local_70 & 0xffffffff00000000;
                if (bVar5) {
                  BfFreeUnicodeString((undefined4 *)&local_128);
                }
                if ((int)uVar9 < 0) {
                  if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                  goto LAB_14001a9f1;
                  pppppuVar13 = pppppuVar13 + 5;
                  pppppuVar26 = pppppuVar26 + 2;
                  pwVar17 = (wchar_t *)(local_130 + 8);
                  uVar29 = 0x1a;
                  uVar33 = 0xa3;
                  goto LAB_14001b157;
                }
                if (((ulonglong)(*local_108)[1] & 4) == 0) {
                  uVar16 = PsGetHostSilo();
                }
                else {
                  uVar16 = IoGetSilo(*(undefined8 *)(param_2 + 0x20));
                }
                uVar15 = BfpDoesFileExistWithCrossVolumeECP
                                   (&local_128,*pppppuVar13[2],uVar16,0,
                                    (uint)*(byte *)(*(longlong *)(param_1 + 0x10) + 6));
                uVar9 = (uint)uVar15;
                if ((int)uVar9 < 0) {
                  if (uVar9 == 0xc0000034) {
                    local_a0 = 0xc0000034;
                  }
                  else if (uVar9 != 0xc000003a) {
                    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                    goto LAB_14001a9f1;
                    uVar33 = (undefined1)uVar15;
                    uVar29 = 0x1b;
                    uVar32 = 0xc9;
                    goto LAB_14001ac44;
                  }
                  if (bVar6) {
                    bVar7 = false;
                  }
                }
                else if (bVar6) {
                  bVar7 = true;
                }
                uVar23 = local_118;
                if (local_a4 == 2) {
                  if (bVar7) {
                    uVar9 = 0xc0000035;
                    goto LAB_14001a9f1;
                  }
                }
                else {
                  if (local_a4 != 3) {
                    if (local_a4 != 5) goto LAB_14001a835;
                    local_fc = 4;
                  }
                  if (bVar7) {
                    puVar20 = (uint *)(*(longlong *)(param_1 + 0x10) + 0x20);
                    *puVar20 = *puVar20 ^ (local_fc ^ local_a4) << 0x18;
                    pppppuVar13 = (undefined8 *****)*pppppuVar13;
                    local_res10 = CONCAT71(local_res10._1_7_,1);
                    goto LAB_14001a664;
                  }
                }
LAB_14001a835:
                pppppuVar13 = (undefined8 *****)*pppppuVar13;
              } while( true );
            }
          }
LAB_140019d49:
          uVar15 = 0xc0000034;
          local_f8 = local_d8;
          uVar19 = 0;
          while( true ) {
            uVar9 = (uint)uVar15;
            if ((undefined8 ******)local_f8 == &local_d8) break;
            local_b8 = local_f8[4];
            pppppuVar13 = (undefined8 *****)local_b8[8];
            local_90 = local_f8 + 2;
            bVar6 = false;
            uVar27 = *(uint *)(local_b8 + 1);
            local_48 = local_f8[5];
            local_40 = (undefined8 *****)(local_b8 + 8);
            local_114 = uVar19 + 1;
            local_f0 = (undefined8 *****)CONCAT44(local_f0._4_4_,uVar27);
            for (; local_108 = pppppuVar13, pppppuVar13 != local_40;
                pppppuVar13 = (undefined8 *****)*pppppuVar13) {
              if (uVar23 == 1) {
                if (((uVar27 & 2) != 0) && ((undefined8 *****)*pppppuVar13 == local_40)) {
                  bVar6 = true;
                }
              }
              else if (1 < uVar23) {
                if ((local_114 < uVar23) && ((undefined8 *****)*pppppuVar13 == local_40)) break;
                if (1 < local_114) {
                  bVar6 = true;
                }
              }
              local_98 = pppppuVar13;
              if (lStack_120 != 0) {
                ExFreePoolWithTag();
                lStack_120 = 0;
              }
              lVar14 = local_130;
              local_128 = (undefined8 ****)((ulonglong)local_128 & 0xffffffff00000000);
              bVar5 = false;
              local_60 = 0;
              lStack_58 = 0;
              pppuVar18 = *pppppuVar13[2];
              uVar15 = BfFormatPathFromFileNameInfo(local_130,'\0',(undefined4 *)&local_60);
              pppppuVar13 = local_108;
              uVar9 = (uint)uVar15;
              if ((int)uVar9 < 0) {
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  pcVar31 = "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c";
                  WPP_RECORDER_SF_sDZd
                            (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,8,0x55,
                             &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                             "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",0xa1,
                             (wchar_t *)(lVar14 + 8),(char)uVar15);
                }
                pppppuVar13 = local_108;
              }
              else {
                uVar15 = BfReplaceFirstSubstring
                                   ((ushort *)&local_60,(ushort *)local_90,(ushort *)(local_108 + 5)
                                    ,(undefined4 *)&local_128);
                uVar9 = (uint)uVar15;
                if ((int)uVar9 < 0) {
                  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                    pcVar31 = "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c";
                    WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,8,0x56,
                                        &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                                        "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",0xa9,
                                        (char)uVar15);
                  }
                }
                else {
                  bVar5 = true;
                  uVar9 = BfPrependVolumeNameFromInstance(pppuVar18,(short *)&local_128);
                  if ((int)uVar9 < 0) {
                    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                      pcVar31 = "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c";
                      WPP_RECORDER_SF_sDZd
                                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,8,0x57,
                                 &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                                 "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",0xb4,
                                 (wchar_t *)&local_128,(char)uVar9);
                    }
                  }
                  else {
                    bVar5 = false;
                  }
                }
              }
              if (lStack_58 != 0) {
                ExFreePoolWithTag(lStack_58,0x74734642);
                lStack_58 = 0;
              }
              local_60 = local_60 & 0xffffffff00000000;
              if (bVar5) {
                BfFreeUnicodeString((undefined4 *)&local_128);
              }
              pppppuVar26 = local_f0;
              if ((int)uVar9 < 0) {
                if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                goto LAB_14001a9f1;
                pppppuVar13 = pppppuVar13 + 5;
                pwVar17 = (wchar_t *)(local_130 + 8);
                pppppuVar26 = local_f8 + 2;
                uVar29 = 0x1c;
                uVar33 = 0x50;
                goto LAB_14001b157;
              }
              cVar30 = *(char *)(*(longlong *)(param_1 + 0x10) + 4);
              uVar27 = (uint)local_f0;
              if ((cVar30 == -0xe) || (cVar30 == -7)) {
                local_134 = BfpHandleNetworkQueryOpen
                                      (param_1,*(undefined8 *)(param_2 + 0x20),*pppppuVar13[2],
                                       &local_128,(byte)((uint)local_f0 >> 2) & 1);
                if ((local_134 == 0xc0000034) || (local_134 == 0xc000003a)) goto LAB_14001a609;
                if ((*(char *)(*(longlong *)(param_1 + 0x10) + 4) == -7) &&
                   (local_134 == 0xc00000bb)) {
                  cVar30 = '\x06';
                }
                else {
                  cVar30 = (-1 < (int)local_134) + '\x03';
                  uVar12 = 0;
                }
                goto LAB_140019fa0;
              }
              if (((ulonglong)local_f0 & 1) == 0) {
LAB_14001a44e:
                lVar14 = *(longlong *)(param_1 + 0x10);
                uVar9 = *(uint *)(lVar14 + 0x20);
                puVar20 = (uint *)(lVar14 + 0x20);
                uVar23 = uVar9 >> 0x18;
                if (bVar6) {
                  cVar30 = (char)local_res8;
                  goto LAB_14001a5ee;
                }
                if ((((ulonglong)pppppuVar26 & 8) == 0) || ((*(byte *)(lVar14 + 6) & 4) != 0)) {
LAB_14001aa6f:
                  cVar30 = (char)local_res8;
                  goto LAB_14001aa8f;
                }
                if (((ulonglong)pppppuVar26 & 4) == 0) {
                  uVar16 = PsGetHostSilo();
                }
                else {
                  uVar16 = IoGetSilo(*(undefined8 *)(param_2 + 0x20));
                }
                uVar15 = BfpDoesFileExistWithCrossVolumeECP
                                   (&local_128,*pppppuVar13[2],uVar16,0x40,
                                    (uint)*(byte *)(*(longlong *)(param_1 + 0x10) + 6));
                ppppuVar3 = local_b8;
                uVar9 = (uint)uVar15;
                if (-1 < (int)uVar9) {
LAB_14001a4ef:
                  if (local_c8 == 0) {
                    uVar9 = FltAllocateExtraCreateParameterList(g_BindFltState,0,&local_c8);
                    if ((int)uVar9 < 0) goto LAB_14001a9f1;
                    FltSetEcpListIntoCallbackData(g_BindFltState,param_1,local_c8);
                  }
                  if (local_110 == (uint *)0x0) {
                    uVar9 = FltAllocateExtraCreateParameter
                                      (g_BindFltState,&ECP_TYPE_REPARSED_BY_BINDFLT,0x10,0);
                    if ((int)uVar9 < 0) goto LAB_14001a9f1;
                    local_110[0] = 0;
                    local_110[1] = 0;
                    local_110[2] = 0;
                    local_110[3] = 0;
                    if (((ulonglong)ppppuVar3[1] & 0x10000000) != 0) {
                      *local_110 = 1;
                      *(undefined8 ****)(local_110 + 2) = ppppuVar3[7];
                    }
                    FsRtlInsertExtraCreateParameter(local_c8,local_110);
                  }
                  uVar9 = IoReplaceFileObjectName
                                    (*(undefined8 *)(param_2 + 0x20),lStack_120,
                                     (ulonglong)local_128 & 0xffff);
                  if ((int)uVar9 < 0) goto LAB_14001a9f1;
                  cVar30 = '\x04';
                  *(undefined4 *)(param_1 + 0x18) = 0x104;
                  *(undefined8 *)(param_1 + 0x20) = 0;
                  goto LAB_140019fa0;
                }
                local_134 = uVar9;
                if (uVar9 == 0xc0000034) {
                  if (((uVar23 < 6) && (!bVar7)) && ((0x2dU >> (uVar23 & 0x1f) & 1) != 0))
                  goto LAB_14001a4ef;
                }
                else if (uVar9 != 0xc000003a) {
                  if (uVar9 == 0xc00000ba) {
                    if (((bVar7) || (*(char *)(local_b8 + 6) != '\0')) ||
                       ((uint)*(ushort *)(local_130 + 0x68) + (uint)*(ushort *)(local_130 + 0x58) <=
                        (uint)*(ushort *)local_90)) goto LAB_14001aa6f;
                    goto LAB_14001a4ef;
                  }
                  if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                  goto LAB_14001a9f1;
                  uVar29 = 0x1d;
                  bVar21 = 3;
                  uVar33 = 0x2d;
                  goto LAB_14001acb2;
                }
              }
              else {
                *(uint *)(*(longlong *)(param_1 + 0x10) + 0x20) = local_88;
                *(undefined2 *)(*(longlong *)(param_1 + 0x10) + 0x2a) = local_100;
                if (!bVar6) {
                  uVar15 = BfpValidateReadOnlyCreate(param_1,(byte)((uint)local_f0 >> 4) & 1);
                  if ((char)uVar15 != '\0') goto LAB_14001a44e;
                  local_res8 = CONCAT71(local_res8._1_7_,1);
                  local_134 = 0xc0000022;
                  if (((ulonglong)pppppuVar26 & 2) != 0) goto LAB_14001a609;
                  goto LAB_14001a8c3;
                }
                cVar30 = '\0';
                puVar20 = (uint *)(*(longlong *)(param_1 + 0x10) + 0x20);
                local_res8 = local_res8 & 0xffffffffffffff00;
                uVar9 = *puVar20;
                uVar23 = uVar9 >> 0x18;
LAB_14001a5ee:
                if ((bVar7) || ((uVar23 != 4 && (uVar23 != 1)))) {
                  if ((char)local_res10 != '\0') {
                    *puVar20 = (local_fc ^ local_a4) << 0x18 ^ uVar9;
                  }
LAB_14001aa8f:
                  local_a8 = local_a8 & 0xff;
                  if ((*(byte *)(*(longlong *)(param_1 + 0x10) + 6) & 8) == 0) {
                    local_a8 = 1;
                  }
                  cVar22 = (char)local_a8;
                  pcVar31 = (char *)CONCAT71((int7)((ulonglong)pcVar31 >> 8),cVar22);
                  uVar15 = BfCreateFile(&local_128,param_1,param_2,*pppppuVar13[2],(byte)pppppuVar26
                                        ,pcVar31,&local_80,&local_e0);
                  local_134 = (uint)uVar15;
                  uVar15 = uVar15 & 0xffffffff;
                  if ((cVar22 != '\0') && (local_134 == 0x8000002d)) {
                    puVar20 = *(uint **)(param_1 + 0x20);
                    if ((puVar20 == (uint *)0x0) || (0x4000 < (ushort)puVar20[1])) {
                      uVar9 = 0xc0000278;
                      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                        WPP_RECORDER_SF_sDsZZZd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
                      }
                      goto LAB_14001a9f1;
                    }
                    *(uint **)(param_1 + 0x28) = puVar20;
                    FltSetCallbackDataDirty(param_1);
                    *(undefined4 *)(param_1 + 0x18) = 0x104;
                    *(ulonglong *)(param_1 + 0x20) = (ulonglong)*puVar20;
                    if (*(short *)(*(longlong *)(*(longlong *)(param_2 + 0x20) + 0x60) + -2 +
                                  (ulonglong)
                                  (*(ushort *)(*(longlong *)(param_2 + 0x20) + 0x58) >> 1) * 2) ==
                        0x5c) {
                      psVar2 = (short *)(*(longlong *)(param_1 + 0x28) + 6);
                      *psVar2 = *psVar2 + 2;
                    }
                    cVar30 = '\x04';
                    goto LAB_140019fa0;
                  }
                  if ((local_134 != 0xc0000034) && (local_134 != 0xc000003a)) {
                    uVar23 = local_118;
                    goto LAB_14001ab0a;
                  }
                }
                else {
                  local_134 = local_a0;
                }
              }
LAB_14001a609:
              uVar23 = local_118;
            }
            uVar15 = (ulonglong)local_134;
            if (local_134 != 0xc0000034) {
              cVar30 = (char)local_res8;
LAB_14001ab0a:
              uVar9 = (uint)uVar15;
              if (uVar9 != 0xc000003a) goto LAB_140019d6c;
            }
            local_f8 = (undefined8 *****)*local_f8;
            uVar19 = local_114;
          }
          cVar30 = (char)local_res8;
LAB_140019d6c:
          pppppuVar13 = local_98;
          lVar14 = local_e0;
          cVar22 = *(char *)(*(longlong *)(param_1 + 0x10) + 4);
          if (cVar22 == -0xe) {
            cVar30 = '\x03';
            goto LAB_140019fa0;
          }
          if (cVar22 == -7) {
            cVar30 = '\x06';
            goto LAB_140019fa0;
          }
          if ((int)uVar9 < 0) {
            if ((cVar30 == '\0') || ((uVar9 != 0xc0000034 && (uVar9 != 0xc000003a)))) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                uVar29 = 0x1f;
                pwVar17 = (wchar_t *)(local_130 + 8);
                pppppuVar13 = local_98 + 5;
                bVar21 = 4;
                pppppuVar26 = &local_128;
                uVar33 = 0xf7;
LAB_14001ae1d:
                WPP_RECORDER_SF_sDZZZd
                          (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),bVar21,5,uVar29,
                           &WPP_48a527b79fd4344d8b4157379f595642_Traceguids,
                           (wchar_t *)"onecore\\base\\fs\\wci\\bindflt\\filter\\create.c",uVar33,
                           (wchar_t *)pppppuVar26,(wchar_t *)pppppuVar13,pwVar17,(char)uVar9);
              }
            }
            else {
LAB_14001a8c3:
              uVar9 = 0xc0000022;
            }
          }
          else {
            pppuVar18 = *local_98[2];
            local_res8 = 0;
            local_res10 = 0;
            local_140 = 0;
            uVar9 = FltGetStreamContext(pppuVar18,local_e0,&local_res8);
            if (uVar9 == 0xc0000225) {
LAB_14001ad13:
              uVar9 = BfCreateStreamContext(lVar14,'\x01',&local_res8);
              if (-1 < (int)uVar9) {
                uVar9 = FltSetStreamContext(pppuVar18,lVar14,0,local_res8);
                if ((int)uVar9 < 0) {
                  if (uVar9 == 0xc01c0002) {
                    FltReleaseContext(local_res10);
                    uVar9 = 0;
                    local_140 = local_res8;
                  }
                  else {
                    FltReleaseContext(local_res8);
                  }
                }
                else {
                  local_140 = local_res8;
                }
              }
LAB_140019de1:
              if (uVar9 == 0xc01c000b) {
                if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                goto LAB_14001a9f1;
                WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x20,
                                   &WPP_48a527b79fd4344d8b4157379f595642_Traceguids,
                                   "onecore\\base\\fs\\wci\\bindflt\\filter\\create.c",0x15);
              }
              else if (-1 < (int)uVar9) goto LAB_140019dff;
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                uVar29 = 0x21;
                uVar33 = 0x1b;
                bVar21 = 2;
LAB_14001acb2:
                WPP_RECORDER_SF_sDZd
                          (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),bVar21,5,uVar29,
                           &WPP_48a527b79fd4344d8b4157379f595642_Traceguids,
                           "onecore\\base\\fs\\wci\\bindflt\\filter\\create.c",uVar33,
                           (wchar_t *)&local_128,(char)uVar9);
              }
            }
            else {
              if ((int)uVar9 < 0) goto LAB_140019de1;
              if (*(longlong *)(local_res8 + 0x70) == 0) goto LAB_14001ad13;
              local_140 = local_res8;
LAB_140019dff:
              ppppuVar3 = local_b8;
              *(undefined8 *)(*(longlong *)(param_2 + 0x20) + 0x18) =
                   *(undefined8 *)(local_140 + 0x70);
              uVar12 = BfGetSetHandleContext
                                 (*(undefined8 *)(param_2 + 0x20),*(undefined8 *)(param_2 + 0x18),
                                  local_e0,local_80,(longlong)pppppuVar13,(longlong *)local_b8,
                                  (short *)local_90,*(longlong *)(local_140 + 0x70),local_48,
                                  &local_78);
              uVar9 = (uint)uVar12;
              if ((int)uVar9 < 0) {
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  uVar29 = 0x22;
                  bVar21 = 2;
                  uVar33 = 0x39;
                  goto LAB_14001acb2;
                }
              }
              else {
                lVar14 = *(longlong *)(param_2 + 0x20);
                *(longlong *)(lVar14 + 0x20) = local_78;
                *(undefined1 *)(lVar14 + 0x48) = *(undefined1 *)(*(longlong *)(local_78 + 8) + 0x48)
                ;
                *(undefined1 *)(lVar14 + 0x49) = *(undefined1 *)(*(longlong *)(local_78 + 8) + 0x49)
                ;
                *(undefined1 *)(lVar14 + 0x4a) = *(undefined1 *)(*(longlong *)(local_78 + 8) + 0x4a)
                ;
                *(undefined1 *)(lVar14 + 0x4b) = *(undefined1 *)(*(longlong *)(local_78 + 8) + 0x4b)
                ;
                *(undefined1 *)(lVar14 + 0x4c) = *(undefined1 *)(*(longlong *)(local_78 + 8) + 0x4c)
                ;
                *(undefined1 *)(lVar14 + 0x4d) = *(undefined1 *)(*(longlong *)(local_78 + 8) + 0x4d)
                ;
                *(undefined1 *)(lVar14 + 0x4e) = *(undefined1 *)(*(longlong *)(local_78 + 8) + 0x4e)
                ;
                *(undefined1 *)(lVar14 + 0x4f) = *(undefined1 *)(*(longlong *)(local_78 + 8) + 0x4f)
                ;
                *(undefined8 *)(lVar14 + 0x28) = *(undefined8 *)(*(longlong *)(local_78 + 8) + 0x28)
                ;
                *(undefined8 *)(lVar14 + 0x10) = *(undefined8 *)(local_b0 + 0x28);
                uVar9 = IoSetShadowFileInformation
                                  (*(undefined8 *)(param_2 + 0x20),local_e0,*pppppuVar13[2]);
                if ((int)uVar9 < 0) {
                  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                    pppppuVar13 = pppppuVar13 + 5;
                    pwVar17 = (wchar_t *)(local_130 + 8);
                    uVar29 = 0x23;
                    pppppuVar26 = &local_128;
                    uVar33 = 0x50;
LAB_14001b157:
                    bVar21 = 2;
                    goto LAB_14001ae1d;
                  }
                }
                else {
                  BfUpdateFileSizes(local_e0,*(longlong *)(param_2 + 0x20));
                  LOCK();
                  *(int *)(local_b0 + 0x20) = *(int *)(local_b0 + 0x20) + 1;
                  UNLOCK();
                  if ((((((ulonglong)ppppuVar3[1] & 0x10000000) == 0) ||
                       (*(char *)(*(longlong *)(param_1 + 0x10) + 4) != '\0')) ||
                      (pppuVar18 = (undefined8 ***)IoGetSilo(*(undefined8 *)(param_2 + 0x20)),
                      pppuVar18 != ppppuVar3[7])) ||
                     (((*(uint *)(*(longlong *)(*(longlong *)(param_1 + 0x10) + 0x18) + 0x10) & 6)
                       == 0 || (uVar9 = BfSetWriteTrackingEa(*pppppuVar13[2],local_e0),
                               -1 < (int)uVar9)))) {
                    cVar30 = '\x04';
                    *(uint *)(param_1 + 0x18) = local_134;
                    uVar12 = local_140;
                    goto LAB_140019fa0;
                  }
                  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                    uVar33 = (undefined1)uVar9;
                    uVar29 = 0x24;
                    uVar32 = 0x6a;
                    goto LAB_14001ac44;
                  }
                }
              }
            }
          }
LAB_14001a9f1:
          cVar30 = '\x04';
          if (local_80 != 0) {
            FltClose();
          }
          if (local_e0 != 0) {
            ObfDereferenceObject();
          }
          *(undefined8 *)(*(longlong *)(param_2 + 0x20) + 0x18) = 0;
          *(undefined8 *)(*(longlong *)(param_2 + 0x20) + 0x20) = 0;
          *(uint *)(param_1 + 0x18) = uVar9;
          uVar12 = local_140;
          goto LAB_140019fa0;
        }
        lVar14 = *(longlong *)(*(longlong *)(param_2 + 0x20) + 0x40);
        if (lVar14 != 0) {
          local_res8 = 0;
          if (((*(short **)(lVar14 + 0x18) != (short *)0x0) &&
              (**(short **)(lVar14 + 0x18) == 0x6431)) &&
             ((iVar10 = FltGetStreamHandleContext
                                  (*(undefined8 *)(param_2 + 0x18),lVar14,&local_res8), -1 < iVar10
              && (bVar21 = *(byte *)(local_res8 + 0x50), FltReleaseContext(), (bVar21 & 1) != 0))))
          {
            uVar9 = IoReplaceFileObjectName
                              (*(undefined8 *)(param_2 + 0x20),*(undefined8 *)(local_130 + 0x70),
                               *(short *)(local_130 + 0x68) + *(short *)(local_130 + 0x58));
            if ((int)uVar9 < 0) goto LAB_14001a9f1;
            *(undefined8 *)(*(longlong *)(param_2 + 0x20) + 0x40) = 0;
          }
        }
      }
    }
  }
LAB_140019f9b:
  uVar12 = 0;
  cVar30 = '\x01';
LAB_140019fa0:
  puVar24 = auStackY_1a8;
  if (lStack_120 != 0) {
    ExFreePoolWithTag(lStack_120,0x74734642);
    lStack_120 = 0;
  }
  local_128 = (undefined8 ****)((ulonglong)local_128 & 0xffffffff00000000);
  while (pppppuVar26 = local_d0, (undefined8 ******)local_d8 != &local_d8) {
    if (((undefined8 ******)*local_d0 != &local_d8) ||
       (pppppuVar13 = (undefined8 *****)local_d0[1], (undefined8 *****)*pppppuVar13 != local_d0)) {
      pcVar4 = (code *)swi(0x29);
      pppppuVar13 = (undefined8 *****)(*pcVar4)(3);
      puVar24 = puVar24 + 8;
    }
    *pppppuVar13 = &local_d8;
    local_d0 = pppppuVar13;
    *(undefined8 *)(puVar24 + -8) = 0x14001a000;
    BfFreeUnicodeString((undefined4 *)(pppppuVar26 + 2));
    ppppuVar3 = pppppuVar26[4];
    *(undefined8 *)(puVar24 + -8) = 0x14001a009;
    BfReleaseMappingInformation((longlong *)ppppuVar3);
    *(undefined8 *)(puVar24 + -8) = 0x14001a018;
    ExFreePoolWithTag(pppppuVar26,0x706d4642);
  }
  if (local_b0 != 0) {
    *(undefined8 *)(puVar24 + -8) = 0x14001a02f;
    FltReleaseContext();
  }
  if (*(longlong *)(puVar24 + 0x78) != 0) {
    if (local_res20[0] == '\0') {
      *(undefined8 *)(puVar24 + -8) = 0x14001a124;
      FltReleaseFileNameInformation();
    }
    else {
      *(undefined8 *)(puVar24 + -8) = 0x14001abd6;
      BfFreeUnicodeString((undefined4 *)(*(longlong *)(puVar24 + 0x78) + 8));
      *(undefined8 *)(puVar24 + -8) = 0x14001abe7;
      ExFreePoolWithTag(*(undefined8 *)(puVar24 + 0x78),0x6d6e4642);
    }
  }
  if (uVar12 != 0) {
    *(undefined8 *)(puVar24 + -8) = 0x14001a0f2;
    FltReleaseContext(uVar12);
  }
  lVar14 = local_78;
  if (local_78 != 0) {
    *(undefined8 *)(puVar24 + -8) = 0x14001a106;
    FltReleaseContext(lVar14);
  }
  return cVar30;
LAB_14001a864:
  if (bVar7) goto LAB_140019d49;
  pppppuVar26 = (undefined8 *****)*pppppuVar26;
  uVar9 = local_114;
  goto LAB_14001a624;
}



===== BfReleaseMappingInformation @ 14001b540 =====

void BfReleaseMappingInformation(longlong *param_1)

{
  longlong lVar1;
  code *pcVar2;
  
  LOCK();
  lVar1 = *param_1;
  *param_1 = *param_1 + -1;
  UNLOCK();
  if (lVar1 < 2) {
    if (lVar1 == 1) {
      BfpDeleteMappingInformation((longlong)param_1);
    }
    else {
      pcVar2 = (code *)swi(0x29);
      (*pcVar2)(0xe);
    }
  }
  return;
}



===== BfGetPreCreateFileName @ 14001b580 =====

ulonglong BfGetPreCreateFileName
                    (longlong param_1,longlong param_2,longlong param_3,longlong *param_4,
                    short *param_5)

{
  longlong *plVar1;
  short *psVar2;
  longlong lVar3;
  short *psVar4;
  uint uVar5;
  ulonglong uVar6;
  undefined4 *puVar7;
  longlong lVar8;
  longlong lVar9;
  ulonglong uVar10;
  short sVar11;
  undefined2 uVar12;
  short *psVar13;
  undefined4 local_res10 [2];
  longlong local_res18;
  undefined1 uVar14;
  longlong local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  ushort local_50 [4];
  longlong lStack_48;
  
  psVar4 = param_5;
  lVar3 = *(longlong *)(param_2 + 0x40);
  puVar7 = (undefined4 *)0x0;
  local_68 = 0;
  psVar13 = (short *)0x0;
  *(undefined1 *)param_5 = 0;
  local_res10[0] = 0;
  local_50[0] = 0;
  local_50[1] = 0;
  local_50[2] = 0;
  local_50[3] = 0;
  lStack_48 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_res18 = param_3;
  if (lVar3 == 0) {
LAB_14001b5e9:
    *param_4 = 0;
    if ((param_1 == 0) ||
       (((uVar5 = FltGetFileNameInformation(param_1,0x102,param_4), -1 < (int)uVar5 &&
         (*(short *)(*param_4 + 8) == 0)) && (*(short *)(*param_4 + 0x18) != 0)))) {
      uVar10 = 0xc000000d;
      uVar5 = 0xc000000d;
    }
    else {
      uVar10 = (ulonglong)uVar5;
      if (-1 < (int)uVar5) goto LAB_14001b62a;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001b62a;
    uVar12 = 0xb;
    uVar14 = 0xbd;
  }
  else {
    param_5 = (short *)0x0;
    uVar5 = FltGetStreamHandleContext(param_3,lVar3,&param_5);
    uVar10 = (ulonglong)uVar5;
    if (uVar5 == 0xc0000225) {
      psVar13 = param_5;
LAB_14001b775:
      param_5 = (short *)0x0;
      uVar10 = 0;
    }
    else {
      if (-1 < (int)uVar5) {
        psVar13 = param_5;
        if ((*(uint *)(param_5 + 0x28) & 1) == 0) {
          FltReleaseContext();
          psVar13 = (short *)0x0;
        }
        goto LAB_14001b775;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,7,0x19,
                            &WPP_ab4056511ca038337f1519c30a6fffbb_Traceguids,
                            "onecore\\base\\fs\\wci\\bindflt\\filter\\context.c",0xad,(char)uVar5);
      }
    }
    if (param_5 != (short *)0x0) {
      FltReleaseContext();
    }
    lVar3 = local_res18;
    uVar5 = (uint)uVar10;
    if ((int)uVar5 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001b62a;
      uVar12 = 10;
      uVar14 = 0xa8;
    }
    else {
      if (psVar13 == (short *)0x0) goto LAB_14001b5e9;
      lVar8 = *(longlong *)(param_2 + 0x40);
      if (((*(short **)(lVar8 + 0x18) == (short *)0x0) || (**(short **)(lVar8 + 0x18) != 0x6431)) ||
         ((*(byte *)(psVar13 + 0x28) & 1) == 0)) {
        lVar9 = local_res18;
      }
      else {
        plVar1 = (longlong *)(lVar8 + 0x20);
        lVar8 = *(longlong *)(*plVar1 + 8);
        lVar9 = *(longlong *)(*plVar1 + 0x10);
      }
      uVar10 = BfGeneratePostCreateName
                         (lVar8,lVar9,0x1000102,(longlong)psVar13,local_res18,(short *)local_50);
      uVar5 = (uint)uVar10;
      uVar10 = uVar10 & 0xffffffff;
      if ((int)uVar5 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001b62a;
        uVar12 = 0xc;
        uVar14 = 0xdc;
        goto LAB_14001b6f2;
      }
      if (*(short *)(lStack_48 + -2 + (ulonglong)(local_50[0] >> 1) * 2) == 0x5c) {
LAB_14001b8ec:
        sVar11 = local_50[0] + *(short *)(param_2 + 0x58);
        param_5 = (short *)((ulonglong)param_5 & 0xffffffffffffff00);
      }
      else {
        psVar2 = (short *)(param_2 + 0x58);
        param_5 = psVar2;
        if ((*psVar2 == 0) || (**(short **)(param_2 + 0x60) == 0x3a)) goto LAB_14001b8ec;
        param_5 = (short *)CONCAT71((int7)((ulonglong)psVar2 >> 8),1);
        sVar11 = local_50[0] + 2 + *psVar2;
      }
      local_60._0_4_ = CONCAT22(sVar11,(undefined2)local_60);
      uVar6 = BfAllocateUnicodeString(sVar11,(undefined4 *)&local_60);
      uVar10 = uVar6 & 0xffffffff;
      if ((int)uVar6 < 0) goto LAB_14001b62a;
      uVar5 = RtlAppendUnicodeStringToString(&local_60,local_50);
      uVar10 = (ulonglong)uVar5;
      if ((int)uVar5 < 0) goto LAB_14001b62a;
      if ((char)param_5 != '\0') {
        uVar5 = RtlAppendUnicodeToString(&local_60,L"\\");
        uVar10 = (ulonglong)uVar5;
        if ((int)uVar5 < 0) goto LAB_14001b62a;
      }
      uVar5 = RtlAppendUnicodeStringToString(&local_60,param_2 + 0x58);
      uVar10 = (ulonglong)uVar5;
      if ((int)uVar5 < 0) goto LAB_14001b62a;
      puVar7 = (undefined4 *)ExAllocatePool2(0x100,0x78,0x6d6e4642);
      if (puVar7 == (undefined4 *)0x0) {
        uVar10 = 0xc000009a;
        goto LAB_14001b62a;
      }
      puVar7[2] = (undefined4)local_60;
      puVar7[3] = local_60._4_4_;
      puVar7[4] = (undefined4)uStack_58;
      puVar7[5] = uStack_58._4_4_;
      uVar5 = FltGetVolumeFromInstance(lVar3,&local_68);
      uVar10 = (ulonglong)uVar5;
      if ((int)uVar5 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001b62a;
        uVar12 = 0xd;
        uVar14 = 0x1c;
      }
      else {
        uVar5 = FltGetVolumeName(local_68,0,local_res10);
        uVar10 = (ulonglong)uVar5;
        if (((uVar5 + 0x80000000 & 0x80000000) != 0) || (uVar5 == 0xc0000023)) {
          *(undefined8 *)(puVar7 + 8) = *(undefined8 *)(puVar7 + 4);
          *(undefined2 *)(puVar7 + 6) = (undefined2)local_res10[0];
          *(undefined2 *)((longlong)puVar7 + 0x1a) = (undefined2)local_res10[0];
          *puVar7 = 0x78;
          puVar7[1] = 2;
          uVar5 = FltParseFileNameInformation(puVar7);
          uVar10 = (ulonglong)uVar5;
          if ((int)uVar5 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0xf,
                                  &WPP_48a527b79fd4344d8b4157379f595642_Traceguids,
                                  "onecore\\base\\fs\\wci\\bindflt\\filter\\create.c",0x32,
                                  (char)uVar5);
            }
          }
          else {
            *param_4 = (longlong)puVar7;
            puVar7 = (undefined4 *)0x0;
            *(undefined1 *)psVar4 = 1;
          }
          goto LAB_14001b62a;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001b62a;
        uVar12 = 0xe;
        uVar14 = 0x23;
      }
    }
  }
LAB_14001b6f2:
  WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,uVar12,
                      &WPP_48a527b79fd4344d8b4157379f595642_Traceguids,
                      "onecore\\base\\fs\\wci\\bindflt\\filter\\create.c",uVar14,(char)uVar5);
LAB_14001b62a:
  if (local_68 != 0) {
    FltObjectDereference();
  }
  if (psVar13 != (short *)0x0) {
    FltReleaseContext(psVar13);
  }
  if ((char)*psVar4 == '\0') {
    if (uStack_58 != 0) {
      ExFreePoolWithTag(uStack_58,0x74734642);
      uStack_58 = 0;
    }
    local_60 = local_60 & 0xffffffff00000000;
  }
  if (puVar7 != (undefined4 *)0x0) {
    ExFreePoolWithTag(puVar7,0x6d6e4642);
  }
  if (lStack_48 != 0) {
    ExFreePoolWithTag(lStack_48,0x74734642);
  }
  return uVar10;
}



===== BfCombinedMappingLookup @ 14001bb70 =====

ulonglong BfCombinedMappingLookup
                    (longlong *param_1,longlong *param_2,longlong *param_3,longlong param_4,
                    longlong param_5,undefined8 param_6,undefined1 param_7,longlong *param_8)

{
  longlong *plVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  code *pcVar4;
  int iVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  int iVar11;
  undefined2 uVar12;
  undefined8 *local_res18;
  undefined1 auStackY_68 [32];
  undefined1 auStack_35 [5];
  
  uVar7 = 0;
  iVar11 = 0;
  local_res18 = (undefined8 *)0x0;
  if (param_3 != (longlong *)0x0) {
    uVar6 = BfMappingLookup(param_3,param_4,param_5,(ulonglong *)0x0,param_7,
                            (longlong *)&local_res18);
    puVar10 = auStackY_68;
    puVar9 = auStackY_68;
    puVar8 = auStackY_68;
    uVar7 = uVar6 & 0xffffffff;
    if ((int)uVar6 < 0) {
      if ((int)uVar6 != -0x3fffffc6) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,8,0x4c,
                              &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                              "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",0x70,(char)uVar6)
          ;
          puVar8 = auStackY_68;
        }
        goto LAB_14001bc37;
      }
    }
    else {
      plVar1 = (longlong *)param_8[1];
      if ((longlong *)*plVar1 != param_8) goto LAB_14001bcce;
      iVar11 = 1;
      *local_res18 = param_8;
      local_res18[1] = plVar1;
      *plVar1 = (longlong)local_res18;
      param_8[1] = (longlong)local_res18;
      if ((*(uint *)(local_res18[4] + 8) & 2) == 0) goto LAB_14001bc79;
    }
  }
  puVar10 = auStackY_68;
  puVar8 = auStackY_68;
  if (param_2 != (longlong *)0x0) goto LAB_14001bcd5;
LAB_14001bbf5:
  do {
    puVar8 = puVar10;
    if (param_1 == (longlong *)0x0) break;
    *(undefined1 **)(puVar10 + 0x28) = puVar10 + 0x80;
    puVar10[0x20] = param_7;
    *(undefined8 *)(puVar10 + -8) = 0x14001bc1d;
    uVar7 = BfMappingLookup(param_1,param_4,param_5,(ulonglong *)0x0,puVar10[0x20],
                            *(longlong **)(puVar10 + 0x28));
    iVar5 = (int)uVar7;
    uVar7 = uVar7 & 0xffffffff;
    if (iVar5 < 0) {
      if ((iVar5 != -0x3fffffc6) &&
         ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        *(int *)(puVar10 + 0x38) = iVar5;
        uVar12 = 0x4e;
        *(undefined4 *)(puVar10 + 0x30) = 0xcb2;
LAB_14001bdeb:
        *(char **)(puVar10 + 0x28) = "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c";
        *(undefined **)(puVar10 + 0x20) = &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids;
        uVar3 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
        *(undefined8 *)(puVar10 + -8) = 0x14001be1b;
        WPP_RECORDER_SF_sDd(uVar3,2,8,uVar12,*(undefined8 *)(puVar10 + 0x20),
                            *(char **)(puVar10 + 0x28),puVar10[0x30],puVar10[0x38]);
        puVar8 = puVar10;
      }
      break;
    }
    plVar1 = (longlong *)param_8[1];
    if ((longlong *)*plVar1 == param_8) {
      puVar2 = *(undefined8 **)(puVar10 + 0x80);
      iVar11 = iVar11 + 1;
      *puVar2 = param_8;
      puVar2[1] = plVar1;
      *plVar1 = (longlong)puVar2;
      param_8[1] = (longlong)puVar2;
      break;
    }
LAB_14001bcce:
    do {
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)(3);
      puVar8 = puVar10 + 8;
LAB_14001bcd5:
      puVar10 = puVar8;
      *(undefined1 **)(puVar10 + 0x28) = puVar10 + 0x80;
      puVar10[0x20] = param_7;
      *(undefined8 *)(puVar10 + -8) = 0x14001bcf8;
      uVar7 = BfMappingLookup(param_2,param_4,param_5,(ulonglong *)0x0,puVar10[0x20],
                              *(longlong **)(puVar10 + 0x28));
      iVar5 = (int)uVar7;
      uVar7 = uVar7 & 0xffffffff;
      puVar8 = puVar10;
      if (iVar5 < 0) {
        if (iVar5 == -0x3fffffc6) goto LAB_14001bbf5;
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001bc32;
        *(int *)(puVar10 + 0x38) = iVar5;
        uVar12 = 0x4d;
        *(undefined4 *)(puVar10 + 0x30) = 0xc91;
        goto LAB_14001bdeb;
      }
      plVar1 = (longlong *)param_8[1];
    } while ((longlong *)*plVar1 != param_8);
    puVar2 = *(undefined8 **)(puVar10 + 0x80);
    iVar11 = iVar11 + 1;
    *puVar2 = param_8;
    puVar2[1] = plVar1;
    *plVar1 = (longlong)puVar2;
    param_8[1] = (longlong)puVar2;
    if ((*(uint *)(puVar2[4] + 8) & 2) == 0) break;
  } while( true );
LAB_14001bc32:
  puVar9 = puVar8;
  if (iVar11 != 0) {
LAB_14001bc79:
    **(int **)(puVar9 + 0xb0) = iVar11;
    return 0;
  }
LAB_14001bc37:
  *(undefined8 *)(puVar8 + -8) = 0x14001bc3f;
  BfFreeMappingLookupList(param_8);
  return uVar7;
}



===== BfGetMappingList @ 14001be30 =====

ulonglong BfGetMappingList(longlong param_1,longlong param_2,undefined8 param_3,
                          undefined8 ***param_4,undefined1 *param_5)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  bool bVar4;
  short sVar5;
  bool bVar6;
  undefined8 ****ppppuVar7;
  longlong *plVar8;
  bool bVar9;
  uint uVar10;
  int iVar11;
  undefined8 *puVar12;
  ulonglong uVar13;
  undefined8 ****ppppuVar14;
  ulonglong *puVar15;
  ulonglong uVar16;
  ushort uVar17;
  ulonglong *puVar18;
  ulonglong *puVar19;
  byte bVar20;
  ushort uVar21;
  ulonglong uVar22;
  short *psVar23;
  undefined8 ***pppuVar24;
  undefined8 *puVar25;
  ulonglong *puVar26;
  undefined8 *puVar27;
  undefined8 *puVar28;
  undefined1 *puVar29;
  undefined1 *puVar30;
  ushort uVar31;
  undefined2 uVar32;
  undefined1 auStackY_118 [32];
  undefined1 uVar33;
  char local_d8 [4];
  uint local_d4;
  undefined8 local_d0;
  short *psStack_c8;
  ulonglong local_c0;
  short *psStack_b8;
  undefined8 local_b0;
  short *psStack_a8;
  undefined8 ****local_a0;
  undefined8 ****local_98;
  undefined8 *local_90;
  undefined8 uStack_88;
  longlong local_80;
  longlong local_78;
  longlong local_70;
  longlong local_68;
  undefined8 ****local_60;
  undefined8 local_58;
  char *local_50;
  longlong *local_48 [2];
  
  local_98 = &local_a0;
  local_78 = 0;
  local_48[0] = (longlong *)0x0;
  local_a0 = &local_a0;
  local_d0 = (undefined8 *)0x0;
  local_b0 = (undefined8 *)0x0;
  local_80 = 0;
  local_d8[0] = '\0';
  local_c0 = 0;
  psStack_b8 = (short *)0x0;
  uVar10 = FltGetInstanceContext(*(undefined8 *)(param_2 + 0x18),&local_78);
  puVar30 = auStackY_118;
  if ((int)uVar10 < 0) {
    uVar13 = (ulonglong)uVar10;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001c122;
    uVar32 = 0xf;
    uVar33 = 0x7a;
LAB_14001c1ad:
    bVar20 = 2;
  }
  else {
    puVar12 = BfGetMappingContexts
                        (*(undefined8 *)(param_2 + 0x20),local_78,param_1,&local_b0,&local_d0,
                         local_48);
    puVar30 = auStackY_118;
    uVar10 = (uint)puVar12;
    if (-1 < (int)uVar10) {
      if ((param_1 == 0) ||
         (((uVar10 = FltGetFileNameInformation(param_1,0x1000102,&local_80), -1 < (int)uVar10 &&
           (*(short *)(local_80 + 8) == 0)) && (*(short *)(local_80 + 0x18) != 0)))) {
        uVar13 = 0xc000000d;
        uVar10 = 0xc000000d;
      }
      else {
        uVar13 = (ulonglong)uVar10;
        if (-1 < (int)uVar10) {
          uVar13 = BfFormatPathFromFileNameInfo(local_80,'\0',(undefined4 *)&local_c0);
          puVar12 = local_b0;
          puVar30 = auStackY_118;
          uVar10 = (uint)uVar13;
          uVar13 = uVar13 & 0xffffffff;
          local_d4 = uVar10;
          if (-1 < (int)uVar10) {
            if (local_b0 != (undefined8 *)0x0) {
              local_70 = *(longlong *)(param_2 + 0x20);
              puVar28 = local_b0 + 2;
              lVar1 = *(longlong *)(param_2 + 0x18);
              local_60 = &local_a0;
              bVar4 = true;
              local_50 = local_d8;
              local_b0 = (undefined8 *)0x0;
              psStack_a8 = (short *)0x0;
              local_90 = (undefined8 *)0x0;
              uStack_88 = 0;
              local_68 = lVar1;
              local_58 = param_3;
              FltAcquireResourceShared(puVar28);
              for (puVar28 = (undefined8 *)*puVar12; puVar28 != puVar12;
                  puVar28 = (undefined8 *)*puVar28) {
                if (*(longlong *)puVar28[2] == lVar1) {
                  if (puVar28 != puVar12) {
                    uVar13 = local_c0 & 0xffff;
                    psVar23 = psStack_b8;
                    puVar26 = (ulonglong *)puVar28[3];
                    goto LAB_14001c6ce;
                  }
                  break;
                }
              }
              goto LAB_14001bf9d;
            }
            goto LAB_14001bfb1;
          }
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_14001c122;
          uVar32 = 0x12;
          uVar33 = 0x98;
          goto LAB_14001c1ad;
        }
      }
      puVar30 = auStackY_118;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001c122;
      uVar32 = 0x11;
      uVar33 = 0x90;
      goto LAB_14001c1ad;
    }
    uVar13 = (ulonglong)puVar12 & 0xffffffff;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001c122;
    uVar32 = 0x10;
    uVar33 = 0x82;
    bVar20 = 4;
  }
  WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),bVar20,0xc,uVar32,
                      &WPP_4bfd87d54ffb3323a752b550f6ae0533_Traceguids,
                      "onecore\\base\\fs\\wci\\bindflt\\filter\\dirctrl.c",uVar33,(char)uVar10);
  puVar30 = auStackY_118;
  goto LAB_14001c122;
LAB_14001c6ce:
  do {
    bVar6 = false;
    if ((short)local_b0 == 0) {
      uVar16 = (ulonglong)(*psVar23 == 0x5c);
    }
    else {
      uVar17 = (ushort)uVar13 >> 1;
      uVar16 = (longlong)psStack_a8 - (longlong)psVar23 >> 1;
      uVar21 = (ushort)uVar16;
      uVar16 = uVar16 & 0xffff;
      while (uVar31 = (ushort)uVar16, uVar21 < uVar17) {
        if (psVar23[uVar16] == 0x5c) goto LAB_14001c72b;
        uVar21 = uVar31 + 1;
        uVar16 = (ulonglong)uVar21;
      }
      if (uVar31 == uVar17) {
        local_b0 = (undefined8 *)((ulonglong)local_b0._4_4_ << 0x20);
        psStack_a8 = (short *)0x0;
        puVar19 = puVar26;
        break;
      }
LAB_14001c72b:
      uVar16 = (ulonglong)(ushort)(uVar31 + 1);
    }
    uVar22 = uVar16;
    while (uVar21 = (ushort)uVar22, uVar21 < ((ushort)(uVar13 >> 1) & 0x7fff)) {
      if (psVar23[uVar22] == 0x5c) {
        bVar6 = true;
        break;
      }
      uVar22 = (ulonglong)(ushort)(uVar21 + 1);
    }
    psStack_a8 = psVar23 + uVar16;
    sVar5 = (uVar21 - (short)uVar16) * 2;
    local_b0 = (undefined8 *)CONCAT62(CONCAT42(local_b0._4_4_,sVar5),sVar5);
    if (sVar5 == 0) {
LAB_14001c54d:
      if ((bVar6) || (puVar19 = puVar26, !bVar4)) goto LAB_14001bf9d;
      break;
    }
    puVar28 = (undefined8 *)*puVar26;
    local_90 = &local_b0;
    uVar13 = puVar26[1];
    uStack_88 = CONCAT71(uStack_88._1_7_,1);
    if ((uVar13 & 1) != 0) {
      if (puVar28 == (undefined8 *)0x0) goto LAB_14001bf9d;
      puVar28 = (undefined8 *)((ulonglong)puVar28 ^ (ulonglong)puVar26);
    }
    if (puVar28 == (undefined8 *)0x0) goto LAB_14001bf9d;
    do {
      uVar16 = BfpRBComparePathNodes(&local_90,(longlong)puVar28);
      if ((int)uVar16 < 0) {
        puVar25 = (undefined8 *)*puVar28;
        puVar27 = puVar25;
        if ((uVar13 & 1) != 0) goto LAB_14001c68c;
      }
      else {
        puVar27 = puVar28;
        if ((int)uVar16 < 1) break;
        puVar25 = (undefined8 *)puVar28[1];
        puVar27 = puVar25;
        if ((uVar13 & 1) != 0) {
LAB_14001c68c:
          puVar27 = (undefined8 *)0x0;
          if (puVar25 != (undefined8 *)0x0) {
            puVar27 = (undefined8 *)((ulonglong)puVar28 ^ (ulonglong)puVar25);
          }
        }
      }
      puVar28 = puVar27;
    } while (puVar27 != (undefined8 *)0x0);
    uVar13 = local_c0 & 0xffff;
    if (puVar27 == (undefined8 *)0x0) goto LAB_14001bf9d;
    if (((*(uint *)(puVar27 + -1) & 1) != 0) && ((*(uint *)(puVar27[8] + 8) & 2) != 0)) {
      *param_5 = 1;
    }
    if ((*(uint *)(puVar27 + -1) & 4) != 0) {
LAB_14001c77b:
      bVar4 = false;
      goto LAB_14001c54d;
    }
    puVar19 = (ulonglong *)puVar27[9];
    psVar23 = psStack_b8;
    bVar9 = BfpPathTreeEmpty(puVar19);
    if (bVar9) goto LAB_14001c77b;
    puVar26 = puVar19;
  } while (bVar6);
  puVar26 = (ulonglong *)*puVar19;
  if (puVar26 != (ulonglong *)0x0) {
    while (iVar11 = BfWalkMappingTree(puVar26,&local_70), -1 < iVar11) {
      puVar18 = (ulonglong *)*puVar26;
      if (puVar18 == (ulonglong *)0x0) {
        puVar18 = (ulonglong *)puVar26[1];
        if (puVar18 == (ulonglong *)0x0) {
          bVar20 = (byte)puVar19[1] & 1;
          do {
            puVar15 = (ulonglong *)(puVar26[2] & 0xfffffffffffffffc);
            if (bVar20 != 0) {
              if (puVar15 == (ulonglong *)0x0) goto LAB_14001bf9d;
              puVar15 = (ulonglong *)((ulonglong)puVar15 ^ (ulonglong)puVar26);
            }
            if (puVar15 == (ulonglong *)0x0) goto LAB_14001bf9d;
            puVar18 = (ulonglong *)puVar15[1];
            if (bVar20 == 0) {
LAB_14001c5bd:
              if ((puVar18 != (ulonglong *)0x0) && (puVar18 != puVar26)) goto LAB_14001c5c7;
            }
            else if (puVar18 != (ulonglong *)0x0) {
              puVar18 = (ulonglong *)((ulonglong)puVar18 ^ (ulonglong)puVar15);
              goto LAB_14001c5bd;
            }
            puVar26 = puVar15;
          } while( true );
        }
        if (((byte)puVar19[1] & 1) == 0) {
          puVar26 = puVar18;
        }
        else {
          puVar26 = (ulonglong *)((ulonglong)puVar26 ^ (ulonglong)puVar18);
        }
      }
      else if ((puVar19[1] & 1) == 0) {
LAB_14001c5c7:
        puVar26 = puVar18;
      }
      else {
        puVar26 = (ulonglong *)((ulonglong)puVar26 ^ (ulonglong)puVar18);
      }
    }
  }
LAB_14001bf9d:
  FltReleaseResource(puVar12 + 2);
LAB_14001bfb1:
  puVar12 = local_d0;
  puVar29 = auStackY_118;
  if (local_d0 != (undefined8 *)0x0) {
    local_70 = *(longlong *)(param_2 + 0x20);
    puVar28 = local_d0 + 2;
    lVar1 = *(longlong *)(param_2 + 0x18);
    local_60 = &local_a0;
    bVar4 = true;
    local_50 = local_d8;
    local_d0 = (undefined8 *)0x0;
    psStack_c8 = (short *)0x0;
    local_90 = (undefined8 *)0x0;
    uStack_88 = 0;
    local_68 = lVar1;
    local_58 = param_3;
    FltAcquireResourceShared(puVar28);
    for (puVar28 = (undefined8 *)*puVar12; puVar28 != puVar12; puVar28 = (undefined8 *)*puVar28) {
      if (*(longlong *)puVar28[2] == lVar1) {
        if (puVar28 != puVar12) {
          uVar13 = local_c0 & 0xffff;
          psVar23 = psStack_b8;
          puVar26 = (ulonglong *)puVar28[3];
          goto LAB_14001c94e;
        }
        break;
      }
    }
    goto LAB_14001c00d;
  }
  goto LAB_14001c021;
LAB_14001c452:
  do {
    bVar6 = false;
    if ((short)local_d0 == 0) {
      uVar16 = (ulonglong)(*psVar23 == 0x5c);
    }
    else {
      for (uVar21 = (ushort)((longlong)psStack_c8 - (longlong)psVar23 >> 1);
          uVar21 < (ushort)((ushort)uVar13 >> 1); uVar21 = uVar21 + 1) {
        if (psVar23[uVar21] == 0x5c) goto LAB_14001c4af;
      }
      if (uVar21 == ((ushort)(uVar13 >> 1) & 0x7fff)) {
        local_d0 = (undefined8 *)((ulonglong)local_d0._4_4_ << 0x20);
        psStack_c8 = (short *)0x0;
        puVar19 = puVar26;
        break;
      }
LAB_14001c4af:
      uVar16 = (ulonglong)(ushort)(uVar21 + 1);
    }
    uVar22 = uVar16;
    while (uVar21 = (ushort)uVar22, uVar21 < (ushort)((ushort)uVar13 >> 1)) {
      if (psVar23[uVar22] == 0x5c) {
        bVar6 = true;
        break;
      }
      uVar22 = (ulonglong)(ushort)(uVar21 + 1);
    }
    psStack_c8 = psVar23 + uVar16;
    sVar5 = (uVar21 - (short)uVar16) * 2;
    local_d0 = (undefined8 *)CONCAT62(CONCAT42(local_d0._4_4_,sVar5),sVar5);
    if (sVar5 == 0) {
LAB_14001c2c4:
      if ((bVar6) || (puVar19 = puVar26, !bVar4)) goto LAB_14001c078;
      break;
    }
    puVar12 = (undefined8 *)*puVar26;
    local_90 = &local_d0;
    uVar13 = puVar26[1];
    uStack_88 = CONCAT71(uStack_88._1_7_,1);
    if ((uVar13 & 1) != 0) {
      if (puVar12 == (undefined8 *)0x0) goto LAB_14001c078;
      puVar12 = (undefined8 *)((ulonglong)puVar12 ^ (ulonglong)puVar26);
    }
    if (puVar12 == (undefined8 *)0x0) goto LAB_14001c078;
    do {
      uVar16 = BfpRBComparePathNodes(&local_90,(longlong)puVar12);
      if ((int)uVar16 < 0) {
        puVar28 = (undefined8 *)*puVar12;
        puVar25 = puVar28;
        if ((uVar13 & 1) != 0) goto LAB_14001c410;
      }
      else {
        puVar25 = puVar12;
        if ((int)uVar16 < 1) break;
        puVar28 = (undefined8 *)puVar12[1];
        puVar25 = puVar28;
        if ((uVar13 & 1) != 0) {
LAB_14001c410:
          puVar25 = (undefined8 *)0x0;
          if (puVar28 != (undefined8 *)0x0) {
            puVar25 = (undefined8 *)((ulonglong)puVar12 ^ (ulonglong)puVar28);
          }
        }
      }
      puVar12 = puVar25;
    } while (puVar25 != (undefined8 *)0x0);
    uVar13 = local_c0 & 0xffff;
    if (puVar25 == (undefined8 *)0x0) goto LAB_14001c078;
    if (((*(uint *)(puVar25 + -1) & 1) != 0) && ((*(uint *)(puVar25[8] + 8) & 2) != 0)) {
      *param_5 = 1;
    }
    if ((*(uint *)(puVar25 + -1) & 4) != 0) {
LAB_14001c4fa:
      bVar4 = false;
      goto LAB_14001c2c4;
    }
    puVar19 = (ulonglong *)puVar25[9];
    psVar23 = psStack_b8;
    bVar9 = BfpPathTreeEmpty(puVar19);
    if (bVar9) goto LAB_14001c4fa;
    puVar26 = puVar19;
  } while (bVar6);
  puVar26 = (ulonglong *)*puVar19;
  if ((ulonglong *)*puVar19 != (ulonglong *)0x0) {
    while (iVar11 = BfWalkMappingTree(puVar26,&local_70), -1 < iVar11) {
      puVar18 = (ulonglong *)*puVar26;
      if (puVar18 == (ulonglong *)0x0) {
        puVar18 = (ulonglong *)puVar26[1];
        if (puVar18 == (ulonglong *)0x0) {
          bVar20 = (byte)puVar19[1] & 1;
          do {
            puVar15 = (ulonglong *)(puVar26[2] & 0xfffffffffffffffc);
            if (bVar20 != 0) {
              if (puVar15 == (ulonglong *)0x0) goto LAB_14001c078;
              puVar15 = (ulonglong *)((ulonglong)puVar15 ^ (ulonglong)puVar26);
            }
            if (puVar15 == (ulonglong *)0x0) goto LAB_14001c078;
            puVar18 = (ulonglong *)puVar15[1];
            if (bVar20 == 0) {
LAB_14001c339:
              if ((puVar18 != (ulonglong *)0x0) && (puVar18 != puVar26)) goto LAB_14001c343;
            }
            else if (puVar18 != (ulonglong *)0x0) {
              puVar18 = (ulonglong *)((ulonglong)puVar18 ^ (ulonglong)puVar15);
              goto LAB_14001c339;
            }
            puVar26 = puVar15;
          } while( true );
        }
        if (((byte)puVar19[1] & 1) == 0) {
          puVar26 = puVar18;
        }
        else {
          puVar26 = (ulonglong *)((ulonglong)puVar26 ^ (ulonglong)puVar18);
        }
      }
      else if ((puVar19[1] & 1) == 0) {
LAB_14001c343:
        puVar26 = puVar18;
      }
      else {
        puVar26 = (ulonglong *)((ulonglong)puVar26 ^ (ulonglong)puVar18);
      }
    }
  }
  goto LAB_14001c078;
LAB_14001c94e:
  do {
    bVar6 = false;
    if ((short)local_d0 == 0) {
      uVar16 = (ulonglong)(*psVar23 == 0x5c);
    }
    else {
      for (uVar21 = (ushort)((longlong)psStack_c8 - (longlong)psVar23 >> 1);
          uVar21 < (ushort)((ushort)uVar13 >> 1); uVar21 = uVar21 + 1) {
        if (psVar23[uVar21] == 0x5c) goto LAB_14001c9b2;
      }
      if (uVar21 == ((ushort)(uVar13 >> 1) & 0x7fff)) {
        local_d0 = (undefined8 *)((ulonglong)local_d0._4_4_ << 0x20);
        psStack_c8 = (short *)0x0;
        puVar19 = puVar26;
        break;
      }
LAB_14001c9b2:
      uVar16 = (ulonglong)(ushort)(uVar21 + 1);
    }
    uVar22 = uVar16;
    while (uVar21 = (ushort)uVar22, uVar21 < (ushort)((ushort)uVar13 >> 1)) {
      if (psVar23[uVar22] == 0x5c) {
        bVar6 = true;
        break;
      }
      uVar22 = (ulonglong)(ushort)(uVar21 + 1);
    }
    psStack_c8 = psVar23 + uVar16;
    sVar5 = (uVar21 - (short)uVar16) * 2;
    local_d0 = (undefined8 *)CONCAT62(CONCAT42(local_d0._4_4_,sVar5),sVar5);
    if (sVar5 == 0) {
LAB_14001c7ce:
      if ((bVar6) || (puVar19 = puVar26, !bVar4)) goto LAB_14001c00d;
      break;
    }
    puVar28 = (undefined8 *)*puVar26;
    local_90 = &local_d0;
    uVar13 = puVar26[1];
    uStack_88 = CONCAT71(uStack_88._1_7_,1);
    if ((uVar13 & 1) != 0) {
      if (puVar28 == (undefined8 *)0x0) goto LAB_14001c00d;
      puVar28 = (undefined8 *)((ulonglong)puVar28 ^ (ulonglong)puVar26);
    }
    if (puVar28 == (undefined8 *)0x0) goto LAB_14001c00d;
    do {
      uVar16 = BfpRBComparePathNodes(&local_90,(longlong)puVar28);
      if ((int)uVar16 < 0) {
        puVar25 = (undefined8 *)*puVar28;
        puVar27 = puVar25;
        if ((uVar13 & 1) != 0) goto LAB_14001c90c;
      }
      else {
        puVar27 = puVar28;
        if ((int)uVar16 < 1) break;
        puVar25 = (undefined8 *)puVar28[1];
        puVar27 = puVar25;
        if ((uVar13 & 1) != 0) {
LAB_14001c90c:
          puVar27 = (undefined8 *)0x0;
          if (puVar25 != (undefined8 *)0x0) {
            puVar27 = (undefined8 *)((ulonglong)puVar28 ^ (ulonglong)puVar25);
          }
        }
      }
      puVar28 = puVar27;
    } while (puVar27 != (undefined8 *)0x0);
    uVar13 = local_c0 & 0xffff;
    if (puVar27 == (undefined8 *)0x0) goto LAB_14001c00d;
    if (((*(uint *)(puVar27 + -1) & 1) != 0) && ((*(uint *)(puVar27[8] + 8) & 2) != 0)) {
      *param_5 = 1;
    }
    if ((*(uint *)(puVar27 + -1) & 4) != 0) {
LAB_14001ca00:
      bVar4 = false;
      goto LAB_14001c7ce;
    }
    puVar19 = (ulonglong *)puVar27[9];
    psVar23 = psStack_b8;
    bVar9 = BfpPathTreeEmpty(puVar19);
    if (bVar9) goto LAB_14001ca00;
    puVar26 = puVar19;
  } while (bVar6);
  puVar26 = (ulonglong *)*puVar19;
  if ((ulonglong *)*puVar19 != (ulonglong *)0x0) {
    while (iVar11 = BfWalkMappingTree(puVar26,&local_70), -1 < iVar11) {
      puVar18 = (ulonglong *)*puVar26;
      if (puVar18 == (ulonglong *)0x0) {
        puVar18 = (ulonglong *)puVar26[1];
        if (puVar18 == (ulonglong *)0x0) {
          bVar20 = (byte)puVar19[1] & 1;
          do {
            puVar15 = (ulonglong *)(puVar26[2] & 0xfffffffffffffffc);
            if (bVar20 != 0) {
              if (puVar15 == (ulonglong *)0x0) goto LAB_14001c00d;
              puVar15 = (ulonglong *)((ulonglong)puVar15 ^ (ulonglong)puVar26);
            }
            if (puVar15 == (ulonglong *)0x0) goto LAB_14001c00d;
            puVar18 = (ulonglong *)puVar15[1];
            if (bVar20 == 0) {
LAB_14001c83d:
              if ((puVar18 != (ulonglong *)0x0) && (puVar18 != puVar26)) goto LAB_14001c847;
            }
            else if (puVar18 != (ulonglong *)0x0) {
              puVar18 = (ulonglong *)((ulonglong)puVar18 ^ (ulonglong)puVar15);
              goto LAB_14001c83d;
            }
            puVar26 = puVar15;
          } while( true );
        }
        if (((byte)puVar19[1] & 1) == 0) {
          puVar26 = puVar18;
        }
        else {
          puVar26 = (ulonglong *)((ulonglong)puVar26 ^ (ulonglong)puVar18);
        }
      }
      else if ((puVar19[1] & 1) == 0) {
LAB_14001c847:
        puVar26 = puVar18;
      }
      else {
        puVar26 = (ulonglong *)((ulonglong)puVar26 ^ (ulonglong)puVar18);
      }
    }
  }
LAB_14001c00d:
  FltReleaseResource(puVar12 + 2);
LAB_14001c021:
  plVar8 = local_48[0];
  local_70 = *(longlong *)(param_2 + 0x20);
  lVar1 = *(longlong *)(param_2 + 0x18);
  bVar4 = true;
  local_60 = &local_a0;
  local_50 = local_d8;
  local_d0 = (undefined8 *)0x0;
  psStack_c8 = (short *)0x0;
  local_90 = (undefined8 *)0x0;
  uStack_88 = 0;
  local_68 = lVar1;
  local_58 = param_3;
  FltAcquireResourceShared(local_48[0] + 2);
  for (plVar2 = (longlong *)*plVar8; plVar2 != plVar8; plVar2 = (longlong *)*plVar2) {
    if (*(longlong *)plVar2[2] == lVar1) {
      if (plVar2 != plVar8) {
        uVar13 = local_c0 & 0xffff;
        psVar23 = psStack_b8;
        puVar26 = (ulonglong *)plVar2[3];
        goto LAB_14001c452;
      }
      break;
    }
  }
LAB_14001c078:
  FltReleaseResource(plVar8 + 2);
  puVar30 = auStackY_118;
  if (local_d8[0] != '\0') {
LAB_14001c0a0:
    ppppuVar7 = local_98;
    puVar30 = puVar29;
    if ((undefined8 *****)local_a0 != &local_a0) {
      if (((undefined8 *****)*local_98 == &local_a0) &&
         (ppppuVar14 = (undefined8 ****)local_98[1], (undefined8 ****)*ppppuVar14 == local_98))
      goto LAB_14001c0c7;
      do {
        pcVar3 = (code *)swi(0x29);
        ppppuVar14 = (undefined8 ****)(*pcVar3)(3);
        puVar29 = puVar29 + 8;
LAB_14001c0c7:
        *ppppuVar14 = &local_a0;
        local_98 = ppppuVar14;
        for (pppuVar24 = (undefined8 ***)*param_4; pppuVar24 != param_4;
            pppuVar24 = (undefined8 ***)*pppuVar24) {
          *(undefined8 *)(puVar29 + -8) = 0x14001c0f0;
          iVar11 = RtlCompareUnicodeString(ppppuVar7 + 10,pppuVar24 + 10,1);
          if (iVar11 < 0) {
            *pppuVar24[1] = ppppuVar7;
            ppppuVar7[1] = (undefined8 ***)pppuVar24[1];
            pppuVar24[1] = ppppuVar7;
            *ppppuVar7 = pppuVar24;
            goto LAB_14001c0a0;
          }
          if (iVar11 == 0) {
            *(undefined8 *)(puVar29 + -8) = 0x14001c1ea;
            BfDereferenceMappingListEntry((longlong)ppppuVar7);
            goto LAB_14001c0a0;
          }
        }
        pppuVar24 = (undefined8 ***)param_4[1];
      } while ((undefined8 ***)*pppuVar24 != param_4);
      *ppppuVar7 = param_4;
      ppppuVar7[1] = pppuVar24;
      *pppuVar24 = ppppuVar7;
      param_4[1] = ppppuVar7;
      goto LAB_14001c0a0;
    }
  }
  uVar13 = (ulonglong)local_d4;
LAB_14001c122:
  psVar23 = psStack_b8;
  if (psStack_b8 != (short *)0x0) {
    *(undefined8 *)(puVar30 + -8) = 0x14001c137;
    ExFreePoolWithTag(psVar23,0x74734642);
    psStack_b8 = (short *)0x0;
  }
  local_c0 = local_c0 & 0xffffffff00000000;
  if (local_78 != 0) {
    *(undefined8 *)(puVar30 + -8) = 0x14001c157;
    FltReleaseContext();
  }
  if (local_80 != 0) {
    *(undefined8 *)(puVar30 + -8) = 0x14001c16c;
    FltReleaseFileNameInformation();
  }
  return uVar13;
}



===== BfWalkMappingTree @ 14001ca90 =====

int BfWalkMappingTree(undefined8 *param_1,longlong *param_2)

{
  ushort uVar1;
  uint uVar2;
  longlong *plVar3;
  longlong lVar4;
  undefined8 *puVar5;
  code *pcVar6;
  bool bVar7;
  undefined1 *puVar8;
  int iVar9;
  int iVar10;
  longlong *_Dst;
  longlong lVar11;
  undefined8 uVar12;
  longlong *plVar13;
  undefined8 *puVar14;
  undefined1 *puVar15;
  undefined1 *puVar16;
  undefined1 *puVar17;
  undefined1 *puVar18;
  longlong *plVar19;
  longlong *plVar20;
  undefined1 auStack_178 [32];
  undefined8 *local_158;
  undefined8 *local_150;
  undefined8 *local_148;
  undefined8 local_140;
  undefined4 local_138 [2];
  undefined4 local_130;
  undefined4 local_128;
  undefined4 local_120;
  undefined8 local_118;
  undefined4 local_110;
  undefined4 local_108;
  ulonglong *local_100;
  longlong *local_f8;
  longlong local_f0;
  longlong local_e8;
  undefined8 local_e0;
  longlong lStack_d8;
  longlong *local_d0;
  ulonglong local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  ulonglong local_a8;
  undefined8 local_a0;
  longlong local_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 *local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  ulonglong uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  
  local_98 = param_2[2];
  local_e8 = 0;
  local_a8 = local_a8 & 0xffffffffffff0000;
  local_70 = 0;
  uStack_68 = uStack_68 & 0xffffffff00000000;
  iVar10 = 0;
  bVar7 = false;
  _Dst = (longlong *)0x0;
  uVar2 = *(uint *)(param_1 + -1);
  plVar20 = (longlong *)0x0;
  local_f0 = 0;
  local_d0 = (longlong *)0x0;
  local_e0 = 0;
  lStack_d8 = 0;
  local_c8 = 0;
  uStack_c0 = 0;
  local_b8 = 0;
  uStack_b0 = 0;
  local_90 = 0;
  uStack_88 = 0;
  local_80 = (undefined8 *)0x0;
  uStack_78 = 0;
  local_60 = 0;
  uStack_58 = 0;
  puVar15 = auStack_178;
  if (((uVar2 & 2) != 0) || (puVar15 = auStack_178, (uVar2 & 5) == 0)) goto LAB_14001cb15;
  if ((uVar2 & 1) == 0) {
LAB_14001cbf3:
    plVar20 = local_d0;
    puVar18 = auStack_178;
    puVar15 = auStack_178;
    puVar16 = auStack_178;
    puVar17 = auStack_178;
    puVar14 = *(undefined8 **)param_2[3];
    while (puVar14 != (undefined8 *)0x0) {
      iVar9 = BfReturnedWalkContextAvlCompareRoutine(param_1 + 3,(longlong)puVar14);
      if (iVar9 < 0) {
        puVar14 = (undefined8 *)*puVar14;
      }
      else {
        if (iVar9 < 1) {
          puVar8 = auStack_178;
          if (puVar14 != (undefined8 *)0x0) goto LAB_14001d233;
          break;
        }
        puVar14 = (undefined8 *)puVar14[1];
      }
    }
    puVar14 = (undefined8 *)0x0;
    _Dst = (longlong *)ExAllocateFromPagedLookasideList(&DAT_14000d440);
    if (_Dst == (longlong *)0x0) {
      iVar10 = -0x3fffff66;
    }
    else {
      memset(_Dst,0,0x100);
      if (bVar7) {
        FltAcquireResourceShared(plVar20 + 1);
        puVar14 = (undefined8 *)*local_d0;
        while (puVar14 != (undefined8 *)0x0) {
          iVar10 = BfCachedWalkContextAvlCompareRoutine(param_1 + 3,(longlong)puVar14);
          if (iVar10 < 0) {
            puVar14 = (undefined8 *)*puVar14;
          }
          else {
            if (iVar10 < 1) break;
            puVar14 = (undefined8 *)puVar14[1];
          }
        }
        FltReleaseResource(plVar20 + 1);
        if (puVar14 != (undefined8 *)0x0) {
          uVar1 = *(ushort *)((longlong)puVar14 + 0x2a);
          plVar19 = (longlong *)(ulonglong)uVar1;
          *(undefined4 *)(_Dst + 10) = 0;
          if (uVar1 == 0) {
            plVar19 = (longlong *)0x1;
          }
          lVar11 = ExAllocatePool2(0x100,plVar19);
          _Dst[0xb] = lVar11;
          if (lVar11 == 0) {
            iVar10 = -0x3fffff66;
            puVar15 = auStack_178;
          }
          else {
            *(short *)((longlong)_Dst + 0x52) = (short)plVar19;
            iVar10 = RtlAppendUnicodeStringToString(_Dst + 10,puVar14 + 5);
            puVar15 = auStack_178;
            if (-1 < iVar10) {
              *(undefined1 *)(_Dst + 0xc) = *(undefined1 *)(puVar14 + 7);
              _Dst[9] = puVar14[4];
              lVar11 = puVar14[0xb];
              _Dst[0xf] = puVar14[10];
              _Dst[0x10] = lVar11;
              _Dst[0x11] = puVar14[0xc];
              *(undefined4 *)(_Dst + 0x12) = *(undefined4 *)(puVar14 + 0xd);
              lVar11 = puVar14[0xf];
              _Dst[0x13] = puVar14[0xe];
              _Dst[0x14] = lVar11;
              lVar11 = puVar14[0x11];
              _Dst[0x15] = puVar14[0x10];
              _Dst[0x16] = lVar11;
              lVar11 = puVar14[0x13];
              _Dst[0x17] = puVar14[0x12];
              _Dst[0x18] = lVar11;
              lVar11 = puVar14[0x15];
              _Dst[0x19] = puVar14[0x14];
              _Dst[0x1a] = lVar11;
              lVar11 = puVar14[0x17];
              _Dst[0x1b] = puVar14[0x16];
              _Dst[0x1c] = lVar11;
              lVar11 = puVar14[0x19];
              _Dst[0x1d] = puVar14[0x18];
              _Dst[0x1e] = lVar11;
              _Dst[0x1f] = puVar14[0x1a];
              _Dst[8] = 1;
              plVar3 = *(longlong **)(local_98 + 8);
              if (*plVar3 != local_98) goto LAB_14001d2d0;
              _Dst[1] = (longlong)plVar3;
              *_Dst = local_98;
              *plVar3 = (longlong)_Dst;
              *(longlong **)(local_98 + 8) = _Dst;
              _Dst = (longlong *)0x0;
              *(undefined1 *)param_2[4] = 1;
              puVar15 = auStack_178;
              goto LAB_14001cb15;
            }
          }
          goto LAB_14001ce62;
        }
      }
      local_e0._0_4_ = CONCAT22(*(short *)(param_1 + 3),(undefined2)local_e0);
      uVar12 = BfAllocateUnicodeString(*(short *)(param_1 + 3),(undefined4 *)&local_e0);
      iVar10 = (int)uVar12;
      puVar15 = auStack_178;
      if ((-1 < iVar10) &&
         (iVar10 = RtlAppendUnicodeStringToString(&local_e0,param_1 + 3), puVar15 = auStack_178,
         -1 < iVar10)) {
        _Dst[10] = local_e0;
        _Dst[0xb] = lStack_d8;
        lStack_d8 = 0;
        if (param_1[10] == 0) {
          *(undefined4 *)(_Dst + 0xf) = 0;
        }
        else {
          *(uint *)(_Dst + 0xf) = (uint)*(ushort *)(param_1[10] + 0x20);
          memmove((void *)((longlong)_Dst + 0x7c),*(void **)(param_1[10] + 0x28),
                  (ulonglong)*(ushort *)(param_1[10] + 0x20));
        }
        if ((*(uint *)(param_1 + -1) & 1) != 0) {
          plVar19 = (longlong *)0x28;
          puVar14 = *(undefined8 **)(param_1[8] + 0x40);
          puVar17 = auStack_178;
          goto LAB_14001cf5e;
        }
        plVar19 = param_2;
        if ((*(uint *)(param_1 + -1) & 4) == 0) goto LAB_14001d13f;
        plVar19 = (longlong *)0x28;
        _Dst[9] = param_1[5];
        uStack_c0 = 0;
        local_a8 = 0;
        local_b8 = 0;
        uStack_b0 = 0;
        local_c8 = 0x28;
        local_a8 = PsGetHostSilo();
        local_90 = CONCAT44(local_90._4_4_,0x30);
        uStack_88 = 0;
        local_80 = param_1 + 6;
        local_100 = &local_c8;
        uStack_78 = CONCAT44(uStack_78._4_4_,0x240);
        local_108 = 0;
        local_148 = &local_60;
        local_110 = 0;
        local_118 = 0;
        local_120 = 0;
        local_128 = 1;
        local_130 = 7;
        local_138[0] = 0;
        local_140 = 0;
        local_150 = &local_90;
        local_70 = 0;
        uStack_68 = 0;
        local_158 = (undefined8 *)CONCAT44(local_158._4_4_,0x80);
        iVar10 = FltCreateFileEx2(g_BindFltState,_Dst[9],&local_e8,&local_f0);
        puVar14 = param_1;
LAB_14001d11c:
        if ((iVar10 == -0x3fffffcc) || (iVar10 == -0x3fffffc6)) {
          puVar8 = puVar17;
          if (bVar7) {
            iVar10 = 0;
            *(undefined1 *)(_Dst + 0xc) = 0;
            puVar18 = puVar17;
            while( true ) {
              _Dst[8] = 1;
              plVar3 = *(longlong **)(local_98 + 8);
              if (*plVar3 == local_98) break;
LAB_14001d2d0:
              pcVar6 = (code *)swi(0x29);
              (*pcVar6)();
              puVar17 = puVar18 + 8;
LAB_14001d2d7:
              *(undefined8 *)(puVar17 + -8) = 0x14001d2de;
              local_a8 = PsGetCurrentSilo();
LAB_14001cf99:
              uStack_88 = 0;
              local_80 = puVar14 + 3;
              local_90 = CONCAT44(local_90._4_4_,0x30);
              *(ulonglong **)(puVar17 + 0x78) = &local_c8;
              *(undefined4 *)(puVar17 + 0x70) = 0;
              *(undefined4 *)(puVar17 + 0x68) = 0;
              *(undefined8 *)(puVar17 + 0x60) = 0;
              *(undefined4 *)(puVar17 + 0x58) = 0;
              *(undefined4 *)(puVar17 + 0x50) = 1;
              *(undefined4 *)(puVar17 + 0x48) = 7;
              *(undefined4 *)(puVar17 + 0x40) = 0;
              *(undefined8 *)(puVar17 + 0x38) = 0;
              *(undefined8 **)(puVar17 + 0x30) = &local_60;
              uStack_78 = CONCAT44(uStack_78._4_4_,0x240);
              local_70 = 0;
              uStack_68 = 0;
              puVar5 = (undefined8 *)puVar14[2];
              *(undefined8 **)(puVar17 + 0x28) = &local_90;
              *(undefined4 *)(puVar17 + 0x20) = 0x80;
              uVar12 = *puVar5;
              *(undefined8 *)(puVar17 + -8) = 0x14001d028;
              iVar10 = FltCreateFileEx2(g_BindFltState,uVar12,&local_e8,&local_f0);
              if (iVar10 < 0) {
                puVar14 = (undefined8 *)*puVar14;
LAB_14001cf5e:
                if (puVar14 == (undefined8 *)(param_1[8] + 0x40)) goto LAB_14001d11c;
                local_a8 = 1;
                uStack_c0 = 0;
                local_c8 = (ulonglong)plVar19 & 0xffff;
                local_b8 = 0;
                uStack_b0 = 0;
                if ((*(uint *)(param_1[8] + 8) & 4) == 0) goto code_r0x00014001cf8d;
                goto LAB_14001d2d7;
              }
              _Dst[9] = *(longlong *)puVar14[2];
              puVar16 = puVar17;
LAB_14001d13f:
              *(undefined1 *)(_Dst + 0xc) = 1;
              _Dst[0xd] = local_f0;
              _Dst[0xe] = local_e8;
              puVar18 = puVar16;
              if (bVar7) {
                *(undefined8 *)(puVar16 + -8) = 0x14001d264;
                iVar10 = BfGenerateDirectoryEntryForCache((longlong)_Dst);
                puVar15 = puVar16;
                if (iVar10 < 0) goto LAB_14001ce62;
                _Dst[0xd] = 0;
                _Dst[0xe] = 0;
              }
              else {
                local_f0 = 0;
                local_e8 = 0;
              }
            }
            _Dst[1] = (longlong)plVar3;
            *_Dst = local_98;
            *plVar3 = (longlong)_Dst;
            *(longlong **)(local_98 + 8) = _Dst;
            *(undefined1 *)param_2[4] = 1;
            if (bVar7) {
              *(undefined8 *)(puVar18 + -8) = 0x14001d1b7;
              FltAcquireResourceExclusive(plVar20 + 1);
              LOCK();
              plVar19 = _Dst + 8;
              lVar11 = *plVar19;
              *plVar19 = *plVar19 + 1;
              UNLOCK();
              if (lVar11 + 1 < 2) {
                pcVar6 = (code *)swi(0x29);
                (*pcVar6)(0xe);
                puVar18 = puVar18 + 8;
              }
              plVar3 = local_d0;
              uVar12 = 0;
              plVar19 = (longlong *)*local_d0;
              if (plVar19 != (longlong *)0x0) {
                do {
                  *(undefined8 *)(puVar18 + -8) = 0x14001d1ed;
                  iVar9 = BfCachedWalkContextAvlCompareRoutine(_Dst + 10,(longlong)plVar19);
                  if (iVar9 < 0) {
                    plVar13 = (longlong *)*plVar19;
                    if (plVar13 == (longlong *)0x0) {
                      uVar12 = 0;
                      break;
                    }
                  }
                  else {
                    plVar13 = (longlong *)plVar19[1];
                    if (plVar13 == (longlong *)0x0) {
                      uVar12 = 1;
                      break;
                    }
                  }
                  plVar19 = plVar13;
                } while( true );
              }
              *(undefined8 *)(puVar18 + -8) = 0x14001d218;
              RtlAvlInsertNodeEx(plVar3,plVar19,uVar12,_Dst + 5);
              *(undefined8 *)(puVar18 + -8) = 0x14001d228;
              FltReleaseResource(plVar20 + 1);
            }
            _Dst = (longlong *)0x0;
            puVar8 = puVar18;
          }
LAB_14001d233:
          puVar15 = puVar8;
          if (-1 < iVar10) goto LAB_14001cb15;
        }
        else {
          puVar15 = puVar17;
          puVar16 = puVar17;
          if (-1 < iVar10) goto LAB_14001d13f;
        }
      }
    }
  }
  else {
    if (-1 < (char)*(undefined4 *)(param_1[8] + 8)) {
      bVar7 = false;
      goto LAB_14001cbf3;
    }
    lVar11 = param_2[1];
    lVar4 = *param_2;
    local_f8 = (longlong *)0x0;
    local_a0 = 0;
    bVar7 = true;
    iVar10 = FltGetStreamContext(lVar11);
    puVar15 = auStack_178;
    if (iVar10 == -0x3ffffddb) {
      iVar10 = BfCreateStreamContext(lVar4,'\0',&local_f8);
      if (-1 < iVar10) {
        local_158 = &local_a0;
        iVar10 = FltSetStreamContext(lVar11,lVar4,0,local_f8);
        if (iVar10 < 0) {
          if (iVar10 == -0x3fe3fffe) {
            FltReleaseContext(local_a0);
            iVar10 = 0;
            plVar20 = local_f8;
          }
          else {
            FltReleaseContext(local_f8);
          }
        }
        else {
          plVar20 = local_f8;
        }
      }
      puVar15 = auStack_178;
      if (-1 < iVar10) goto LAB_14001cbef;
    }
    else if (-1 < iVar10) {
      plVar20 = local_f8;
LAB_14001cbef:
      local_d0 = plVar20;
      goto LAB_14001cbf3;
    }
  }
LAB_14001ce62:
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    *(int *)(puVar15 + 0x40) = iVar10;
    *(undefined8 **)(puVar15 + 0x38) = param_1 + 6;
    uVar12 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
    *(undefined4 *)(puVar15 + 0x30) = 0x2b2;
    *(char **)(puVar15 + 0x28) = "onecore\\base\\fs\\wci\\bindflt\\filter\\dirctrl.c";
    *(undefined **)(puVar15 + 0x20) = &WPP_4bfd87d54ffb3323a752b550f6ae0533_Traceguids;
    *(undefined8 *)(puVar15 + -8) = 0x14001cec3;
    WPP_RECORDER_SF_sDZd
              (uVar12,3,0xc,0xe,*(undefined8 *)(puVar15 + 0x20),*(char **)(puVar15 + 0x28),
               puVar15[0x30],*(wchar_t **)(puVar15 + 0x38),puVar15[0x40]);
  }
  iVar10 = 0;
LAB_14001cb15:
  lVar11 = lStack_d8;
  if (lStack_d8 != 0) {
    *(undefined8 *)(puVar15 + -8) = 0x14001cb2a;
    ExFreePoolWithTag(lVar11,0x74734642);
    lStack_d8 = 0;
  }
  local_e0 = local_e0 & 0xffffffff00000000;
  if (local_f0 != 0) {
    *(undefined8 *)(puVar15 + -8) = 0x14001cb99;
    ObfDereferenceObject();
  }
  if (local_e8 != 0) {
    *(undefined8 *)(puVar15 + -8) = 0x14001cb8b;
    FltClose();
  }
  if (_Dst != (longlong *)0x0) {
    *(undefined8 *)(puVar15 + -8) = 0x14001d370;
    BfFreeUnicodeString((undefined4 *)(_Dst + 10));
    *(undefined8 *)(puVar15 + -8) = 0x14001d381;
    ExFreeToPagedLookasideList(&DAT_14000d440,_Dst);
  }
  if (plVar20 != (longlong *)0x0) {
    *(undefined8 *)(puVar15 + -8) = 0x14001cb67;
    FltReleaseContext(plVar20);
  }
  return iVar10;
code_r0x00014001cf8d:
  *(undefined8 *)(puVar17 + -8) = 0x14001cf94;
  local_a8 = PsGetHostSilo();
  goto LAB_14001cf99;
}



===== BfReturnedWalkContextAvlCompareRoutine @ 14001d3a0 =====

void BfReturnedWalkContextAvlCompareRoutine(undefined8 param_1,longlong param_2)

{
  RtlCompareUnicodeString(param_1,param_2 + 0x40,0);
  return;
}



===== BfMappingLookup @ 14001d3d0 =====

ulonglong BfMappingLookup(longlong *param_1,longlong param_2,longlong param_3,ulonglong *param_4,
                         undefined1 param_5,longlong *param_6)

{
  uint *puVar1;
  short *psVar2;
  longlong *plVar3;
  code *pcVar4;
  bool bVar5;
  char cVar6;
  uint uVar7;
  longlong lVar8;
  longlong lVar9;
  ulonglong uVar10;
  undefined8 *puVar11;
  longlong *plVar12;
  ushort uVar13;
  short sVar14;
  ulonglong uVar15;
  undefined8 *puVar16;
  undefined8 *puVar17;
  undefined1 *puVar18;
  ushort uVar19;
  undefined2 uVar20;
  ulonglong *puVar21;
  undefined1 auStackY_b8 [8];
  undefined1 auStackY_b0 [24];
  undefined1 uVar22;
  uint *local_70;
  undefined8 local_68;
  longlong lStack_60;
  undefined8 local_58;
  short *psStack_50;
  ulonglong local_48;
  longlong lStack_40;
  undefined8 *local_38;
  undefined8 uStack_30;
  
  local_70 = (uint *)0x0;
  lVar8 = 0;
  local_48 = 0;
  lStack_40 = 0;
  local_38 = (undefined8 *)0x0;
  uStack_30 = 0;
  local_58 = 0;
  psStack_50 = (short *)0x0;
  local_68 = 0;
  lStack_60 = 0;
  FltAcquireResourceShared(param_1 + 2);
  plVar3 = (longlong *)*param_1;
  if ((longlong *)*param_1 == param_1) {
LAB_14001d449:
    uVar15 = 0xc000003a;
  }
  else {
    do {
      plVar12 = plVar3;
      if (*(longlong *)plVar12[2] == param_2) break;
      plVar3 = (longlong *)*plVar12;
    } while ((longlong *)*plVar12 != param_1);
    if (param_3 == 0) {
LAB_14001d541:
      lVar8 = ExAllocatePool2(0x100,0x30,0x706d4642);
      if (lVar8 == 0) {
        uVar15 = 0xc000009a;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar7 = 0xc000009a;
          uVar20 = 0x50;
          uVar22 = 0x5a;
LAB_14001d909:
          WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,8,uVar20,
                              &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                              "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",uVar22,
                              (char)uVar7);
        }
      }
      else {
        uVar13 = *(ushort *)((longlong)param_4 + 2);
        *(undefined4 *)(lVar8 + 0x10) = 0;
        if (uVar13 == 0) {
          uVar13 = 1;
        }
        lVar9 = ExAllocatePool2(0x100,uVar13,0x74734642);
        *(longlong *)(lVar8 + 0x18) = lVar9;
        if (lVar9 != 0) {
          *(ushort *)(lVar8 + 0x12) = uVar13;
          puVar1 = (uint *)plVar12[4];
          if (puVar1 != (uint *)0x0) {
            cVar6 = RtlEqualUnicodeString(param_4,&g_rootName,0);
            local_70 = puVar1;
            if (cVar6 != '\0') {
              uVar7 = RtlAppendUnicodeStringToString(lVar8 + 0x10,puVar1 + 8);
              uVar15 = (ulonglong)uVar7;
              if ((int)uVar7 < 0) {
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  uVar20 = 0x52;
                  uVar22 = 0x84;
                  goto LAB_14001d909;
                }
              }
              else {
                uVar10 = BfAllocateUnicodeString(*(short *)(lVar8 + 0x10),(undefined4 *)&local_68);
                uVar15 = uVar10 & 0xffffffff;
                if (-1 < (int)uVar10) {
                  RtlCopyUnicodeString(&local_68,lVar8 + 0x10);
                  goto LAB_14001d5b5;
                }
              }
              goto LAB_14001d44e;
            }
          }
LAB_14001d5b5:
          puVar21 = (ulonglong *)plVar12[3];
LAB_14001d5be:
          psVar2 = (short *)param_4[1];
          bVar5 = false;
          if ((short)local_58 == 0) {
            uVar15 = (ulonglong)(*psVar2 == 0x5c);
LAB_14001d620:
            uVar10 = uVar15;
            while (uVar13 = (ushort)uVar10, uVar13 < (ushort)((ushort)*param_4 >> 1)) {
              if (psVar2[uVar10] == 0x5c) {
                bVar5 = true;
                break;
              }
              uVar10 = (ulonglong)(ushort)(uVar13 + 1);
            }
            psStack_50 = psVar2 + uVar15;
            sVar14 = (uVar13 - (short)uVar15) * 2;
            local_58 = CONCAT62(CONCAT42(local_58._4_4_,sVar14),sVar14);
            if (sVar14 == 0) goto LAB_14001d75c;
            puVar17 = (undefined8 *)*puVar21;
            local_38 = &local_58;
            uVar15 = puVar21[1];
            uStack_30 = CONCAT71(uStack_30._1_7_,param_5);
            if ((uVar15 & 1) != 0) {
              if (puVar17 == (undefined8 *)0x0) goto LAB_14001d75c;
              puVar17 = (undefined8 *)((ulonglong)puVar17 ^ (ulonglong)puVar21);
            }
            if (puVar17 == (undefined8 *)0x0) goto LAB_14001d75c;
            do {
              uVar10 = BfpRBComparePathNodes(&local_38,(longlong)puVar17);
              if ((int)uVar10 < 0) {
                puVar11 = (undefined8 *)*puVar17;
                puVar16 = puVar11;
                if ((uVar15 & 1) != 0) goto LAB_14001d742;
              }
              else {
                puVar16 = puVar17;
                if ((int)uVar10 < 1) break;
                puVar11 = (undefined8 *)puVar17[1];
                puVar16 = puVar11;
                if ((uVar15 & 1) != 0) {
LAB_14001d742:
                  puVar16 = (undefined8 *)0x0;
                  if (puVar11 != (undefined8 *)0x0) {
                    puVar16 = (undefined8 *)((ulonglong)puVar17 ^ (ulonglong)puVar11);
                  }
                }
              }
              puVar17 = puVar16;
            } while (puVar16 != (undefined8 *)0x0);
            if (puVar16 == (undefined8 *)0x0) goto LAB_14001d75c;
            uVar7 = RtlAppendUnicodeToString(lVar8 + 0x10,L"\\");
            uVar15 = (ulonglong)uVar7;
            if ((int)uVar7 < 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
              goto LAB_14001d44e;
              uVar20 = 0x53;
              uVar22 = 0xe1;
              goto LAB_14001d909;
            }
            uVar7 = RtlAppendUnicodeStringToString(lVar8 + 0x10,puVar16 + 3);
            uVar15 = (ulonglong)uVar7;
            if ((int)uVar7 < 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
              goto LAB_14001d44e;
              uVar20 = 0x54;
              uVar22 = 0xea;
              goto LAB_14001d909;
            }
            uVar7 = *(uint *)(puVar16 + -1);
            if ((uVar7 & 4) != 0) goto LAB_14001d449;
            if ((uVar7 & 1) != 0) {
              if (lStack_60 != 0) {
                ExFreePoolWithTag(lStack_60,0x74734642);
                lStack_60 = 0;
              }
              sVar14 = *(short *)(lVar8 + 0x10);
              local_68 = local_68 & 0xffffffff00000000;
              if (sVar14 == 0) {
                sVar14 = 1;
              }
              lStack_60 = ExAllocatePool2(0x100,sVar14,0x74734642);
              if (lStack_60 == 0) {
                uVar15 = 0xc000009a;
                goto LAB_14001d44e;
              }
              local_68._0_4_ = CONCAT22(sVar14,(undefined2)local_68);
              RtlCopyUnicodeString(&local_68,lVar8 + 0x10);
              local_70 = (uint *)(puVar16 + -1);
            }
            puVar21 = (ulonglong *)puVar16[9];
            if (puVar21 == (ulonglong *)0x0) goto LAB_14001d75c;
            uVar15 = *puVar21;
            if ((puVar21[1] & 1) != 0) {
              if (uVar15 == 0) goto LAB_14001d75c;
              uVar15 = uVar15 ^ (ulonglong)puVar21;
            }
            if ((uVar15 == 0) || (!bVar5)) goto LAB_14001d75c;
            goto LAB_14001d5be;
          }
          uVar19 = (ushort)*param_4 >> 1;
          for (uVar13 = (ushort)((longlong)psStack_50 - (longlong)psVar2 >> 1); uVar13 < uVar19;
              uVar13 = uVar13 + 1) {
            if (psVar2[uVar13] == 0x5c) goto LAB_14001d61d;
          }
          if (uVar13 != uVar19) {
LAB_14001d61d:
            uVar15 = (ulonglong)(ushort)(uVar13 + 1);
            goto LAB_14001d620;
          }
          local_58 = (ulonglong)local_58._4_4_ << 0x20;
          psStack_50 = (short *)0x0;
LAB_14001d75c:
          puVar18 = auStackY_b8;
          if (local_70 != (uint *)0x0) {
            RtlCopyUnicodeString(lVar8 + 0x10,&local_68);
            plVar3 = *(longlong **)(local_70 + 0x12);
            LOCK();
            lVar9 = *plVar3;
            *plVar3 = *plVar3 + 1;
            UNLOCK();
            if (lVar9 + 1 < 2) {
              pcVar4 = (code *)swi(0x29);
              (*pcVar4)(0xe);
              puVar18 = auStackY_b0;
            }
            uVar15 = 0;
            *(undefined8 *)(lVar8 + 0x20) = *(undefined8 *)(local_70 + 0x12);
            *(longlong **)(lVar8 + 0x28) = param_1;
            *param_6 = lVar8;
            lVar8 = 0;
            goto LAB_14001d450;
          }
          goto LAB_14001d449;
        }
        uVar15 = 0xc000009a;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar7 = 0xc000009a;
          uVar20 = 0x51;
          uVar22 = 0x68;
          goto LAB_14001d909;
        }
      }
    }
    else {
      uVar15 = BfFormatPathFromFileNameInfo(param_3,'\0',(undefined4 *)&local_48);
      uVar7 = (uint)uVar15;
      uVar15 = uVar15 & 0xffffffff;
      if (-1 < (int)uVar7) {
        param_4 = &local_48;
        goto LAB_14001d541;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar20 = 0x4f;
        uVar22 = 0x4f;
        goto LAB_14001d909;
      }
    }
  }
LAB_14001d44e:
  puVar18 = auStackY_b8;
LAB_14001d450:
  if (lStack_60 != 0) {
    *(undefined8 *)(puVar18 + -8) = 0x14001d465;
    ExFreePoolWithTag(lStack_60,0x74734642);
    lStack_60 = 0;
  }
  local_68 = local_68 & 0xffffffff00000000;
  if (lStack_40 != 0) {
    *(undefined8 *)(puVar18 + -8) = 0x14001d48a;
    ExFreePoolWithTag(lStack_40,0x74734642);
    lStack_40 = 0;
  }
  local_48 = local_48 & 0xffffffff00000000;
  *(undefined8 *)(puVar18 + -8) = 0x14001d4a4;
  FltReleaseResource(param_1 + 2);
  if (lVar8 != 0) {
    lVar9 = *(longlong *)(lVar8 + 0x18);
    if (lVar9 != 0) {
      *(undefined8 *)(puVar18 + -8) = 0x14001d4c3;
      ExFreePoolWithTag(lVar9,0x74734642);
      *(undefined8 *)(lVar8 + 0x18) = 0;
    }
    *(undefined4 *)(lVar8 + 0x10) = 0;
    *(undefined8 *)(puVar18 + -8) = 0x14001d4e3;
    ExFreePoolWithTag(lVar8,0x706d4642);
  }
  return uVar15;
}



===== BfpRBComparePathNodes @ 14001da40 =====

ulonglong BfpRBComparePathNodes(undefined8 *param_1,longlong param_2)

{
  char cVar1;
  undefined8 uVar2;
  int iVar3;
  
  uVar2 = *param_1;
  cVar1 = *(char *)(param_1 + 1);
  iVar3 = RtlCompareUnicodeString(uVar2,param_2 + 0x18,1);
  if (-1 < iVar3) {
    if (0 < iVar3) {
      return 1;
    }
    if (cVar1 != '\0') {
      return 0;
    }
    iVar3 = RtlCompareUnicodeString(uVar2,param_2 + 0x18,0);
    if (-1 < iVar3) {
      return (ulonglong)(0 < iVar3);
    }
  }
  return 0xffffffff;
}



===== BfFormatPathFromFileNameInfo @ 14001dae0 =====

ulonglong BfFormatPathFromFileNameInfo(longlong param_1,char param_2,undefined4 *param_3)

{
  uint uVar1;
  longlong lVar2;
  ulonglong uVar3;
  ushort uVar4;
  ushort uVar5;
  ulonglong uVar6;
  undefined2 uVar7;
  undefined1 uVar8;
  
  if ((*(byte *)(param_1 + 2) & 9) == 9) {
LAB_14001db19:
    uVar4 = *(ushort *)(param_1 + 0x68) + *(short *)(param_1 + 0x58);
    if ((uVar4 < *(ushort *)(param_1 + 0x68)) ||
       ((uVar5 = uVar4, param_2 != '\0' &&
        (uVar5 = uVar4 + *(short *)(param_1 + 0x28), uVar5 < uVar4)))) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,8,0x27,
                           &WPP_529f93b0825532f67776c14f74ba0846_Traceguids,
                           "onecore\\base\\fs\\wci\\bindflt\\filter\\utils.c",0x3e);
      }
      uVar6 = 0xc0000106;
      goto LAB_14001dcc7;
    }
    *param_3 = 0;
    if (uVar5 == 0) {
      uVar5 = 1;
    }
    lVar2 = ExAllocatePool2(0x100,uVar5,0x74734642);
    *(longlong *)(param_3 + 2) = lVar2;
    if (lVar2 == 0) {
      uVar6 = 0xc000009a;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001dcc7;
      uVar1 = 0xc000009a;
      uVar7 = 0x28;
      uVar8 = 0x47;
    }
    else {
      *(ushort *)((longlong)param_3 + 2) = uVar5;
      if (param_2 != '\0') {
        uVar1 = RtlAppendUnicodeStringToString(param_3,param_1 + 0x28);
        uVar6 = (ulonglong)uVar1;
        if ((int)uVar1 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_14001dcc7;
          uVar7 = 0x29;
          uVar8 = 0x51;
          goto LAB_14001dd7f;
        }
      }
      uVar1 = RtlAppendUnicodeStringToString(param_3,param_1 + 0x68);
      uVar6 = (ulonglong)uVar1;
      if ((int)uVar1 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001dcc7;
        uVar7 = 0x2a;
        uVar8 = 0x5a;
      }
      else {
        uVar3 = RtlAppendUnicodeStringToString(param_3,param_1 + 0x58);
        uVar1 = (uint)uVar3;
        uVar6 = uVar3 & 0xffffffff;
        if (-1 < (int)uVar1) {
          return uVar3;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001dcc7;
        uVar7 = 0x2b;
        uVar8 = 0x62;
      }
    }
  }
  else {
    uVar1 = FltParseFileNameInformation();
    uVar6 = (ulonglong)uVar1;
    if (-1 < (int)uVar1) {
      if ((*(byte *)(param_1 + 2) & 9) != 9) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,8,0x26,
                             &WPP_529f93b0825532f67776c14f74ba0846_Traceguids,
                             "onecore\\base\\fs\\wci\\bindflt\\filter\\utils.c",0x26);
        }
        uVar6 = 0xc000000d;
        goto LAB_14001dcc7;
      }
      goto LAB_14001db19;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001dcc7;
    uVar7 = 0x25;
    uVar8 = 0x1f;
  }
LAB_14001dd7f:
  WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,8,uVar7,
                      &WPP_529f93b0825532f67776c14f74ba0846_Traceguids,
                      "onecore\\base\\fs\\wci\\bindflt\\filter\\utils.c",uVar8,(char)uVar1);
LAB_14001dcc7:
  if (*(longlong *)(param_3 + 2) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_3 + 2),0x74734642);
    *(undefined8 *)(param_3 + 2) = 0;
  }
  *param_3 = 0;
  return uVar6;
}



===== BfRemapPath @ 14001de00 =====

ulonglong BfRemapPath(longlong param_1,ushort *param_2,undefined8 param_3,ushort *param_4,
                     wchar_t *param_5)

{
  bool bVar1;
  uint uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  undefined2 uVar5;
  undefined1 uVar6;
  wchar_t *pwVar7;
  ulonglong local_28;
  longlong lStack_20;
  
  local_28 = 0;
  lStack_20 = 0;
  bVar1 = false;
  uVar3 = BfFormatPathFromFileNameInfo(param_1,'\0',(undefined4 *)&local_28);
  uVar2 = (uint)uVar3;
  uVar3 = uVar3 & 0xffffffff;
  if ((int)uVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001de8b;
    pwVar7 = (wchar_t *)(param_1 + 8);
    uVar5 = 0x55;
    uVar6 = 0xa1;
  }
  else {
    uVar4 = BfReplaceFirstSubstring((ushort *)&local_28,param_2,param_4,(undefined4 *)param_5);
    uVar3 = uVar4 & 0xffffffff;
    if ((int)uVar4 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,8,0x56,
                            &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                            "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",0xa9,(char)uVar4);
      }
      goto LAB_14001de8b;
    }
    bVar1 = true;
    uVar2 = BfPrependVolumeNameFromInstance(param_3,param_5);
    uVar3 = (ulonglong)uVar2;
    if (-1 < (int)uVar2) {
      bVar1 = false;
      goto LAB_14001de8b;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001de8b;
    uVar5 = 0x57;
    uVar6 = 0xb4;
    pwVar7 = param_5;
  }
  WPP_RECORDER_SF_sDZd
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,8,uVar5,
             &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
             "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",uVar6,pwVar7,(char)uVar2);
LAB_14001de8b:
  if (lStack_20 != 0) {
    ExFreePoolWithTag(lStack_20,0x74734642);
    lStack_20 = 0;
  }
  local_28 = local_28 & 0xffffffff00000000;
  if (bVar1) {
    BfFreeUnicodeString((undefined4 *)param_5);
  }
  return uVar3;
}



===== BfPrependVolumeNameFromInstance @ 14001dfe0 =====

int BfPrependVolumeNameFromInstance(undefined8 param_1,short *param_2)

{
  int iVar1;
  short sVar2;
  ushort uVar3;
  undefined2 uVar4;
  undefined4 local_res18 [2];
  longlong local_res20;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined8 local_38;
  longlong lStack_30;
  undefined8 local_28;
  longlong lStack_20;
  
  local_res20 = 0;
  local_res18[0] = 0;
  local_28 = 0;
  lStack_20 = 0;
  local_38 = 0;
  lStack_30 = 0;
  iVar1 = FltGetVolumeFromInstance(0,&local_res20);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001e130;
    uVar6 = (undefined1)iVar1;
    uVar4 = 0x20;
    uVar5 = 0x93;
  }
  else {
    FltGetVolumeName(local_res20,0,local_res18);
    sVar2 = (short)local_res18[0];
    if ((short)local_res18[0] == 0) {
      sVar2 = 1;
    }
    lStack_20 = ExAllocatePool2(0x100,sVar2,0x74734642);
    if (lStack_20 == 0) {
      iVar1 = -0x3fffff66;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001e130;
      uVar6 = 0x9a;
      uVar4 = 0x21;
      uVar5 = 0xa4;
      iVar1 = -0x3fffff66;
    }
    else {
      local_28._0_4_ = CONCAT22(sVar2,(ushort)local_28);
      FltGetVolumeName(local_res20,&local_28,0);
      uVar3 = (ushort)local_28 + *param_2;
      if (uVar3 < (ushort)local_28) {
        iVar1 = -0x3fffff6b;
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001e130;
        uVar6 = 0x95;
        uVar4 = 0x22;
        uVar5 = 0xb2;
        iVar1 = -0x3fffff6b;
      }
      else {
        local_38 = local_38 & 0xffffffff00000000;
        if (uVar3 == 0) {
          uVar3 = 1;
        }
        lStack_30 = ExAllocatePool2(0x100,uVar3,0x74734642);
        if (lStack_30 != 0) {
          local_38._0_4_ = CONCAT22(uVar3,(short)local_38);
          RtlCopyUnicodeString(&local_38,&local_28);
          iVar1 = RtlAppendUnicodeStringToString(&local_38,param_2);
          if (iVar1 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_sDZZd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
            }
            BfFreeUnicodeString((undefined4 *)&local_38);
          }
          else {
            ExFreePoolWithTag(*(undefined8 *)(param_2 + 4),0x74734642);
            iVar1 = 0;
            *(longlong *)(param_2 + 4) = lStack_30;
            *param_2 = (short)local_38;
            param_2[1] = local_38._2_2_;
          }
          goto LAB_14001e130;
        }
        iVar1 = -0x3fffff66;
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001e130;
        uVar6 = 0x9a;
        uVar4 = 0x23;
        uVar5 = 0xba;
        iVar1 = -0x3fffff66;
      }
    }
  }
  WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,8,uVar4,
                      &WPP_529f93b0825532f67776c14f74ba0846_Traceguids,
                      "onecore\\base\\fs\\wci\\bindflt\\filter\\utils.c",uVar5,uVar6);
LAB_14001e130:
  if (lStack_20 != 0) {
    ExFreePoolWithTag(lStack_20,0x74734642);
    lStack_20 = 0;
  }
  local_28 = local_28 & 0xffffffff00000000;
  if (local_res20 != 0) {
    FltObjectDereference();
  }
  return iVar1;
}



===== BfpPathTreeEmpty @ 14001e2b0 =====

bool BfpPathTreeEmpty(ulonglong *param_1)

{
  ulonglong uVar1;
  
  if (param_1 == (ulonglong *)0x0) {
    return true;
  }
  uVar1 = *param_1;
  if ((param_1[1] & 1) != 0) {
    if (uVar1 == 0) {
      return true;
    }
    uVar1 = uVar1 ^ (ulonglong)param_1;
  }
  return uVar1 == 0;
}



===== BfConvertWalkContextToDirectoryEnumeration @ 14001e2e0 =====

void BfConvertWalkContextToDirectoryEnumeration
               (longlong *param_1,int param_2,longlong param_3,longlong param_4,longlong param_5,
               char *param_6)

{
  longlong *plVar1;
  longlong lVar2;
  undefined8 *puVar3;
  code *pcVar4;
  char cVar5;
  int iVar6;
  longlong *plVar7;
  uint uVar8;
  ulonglong uVar9;
  longlong *plVar10;
  undefined8 *puVar11;
  undefined1 *puVar12;
  undefined8 uVar13;
  ulonglong uVar14;
  undefined4 *puVar15;
  char local_res8;
  undefined1 auStackY_98 [8];
  undefined1 auStackY_90 [24];
  uint local_58;
  uint local_54 [3];
  undefined8 local_48;
  undefined8 uStack_40;
  
  puVar12 = auStackY_98;
  uVar9 = 0;
  local_58 = 0;
  local_res8 = '\x01';
  *param_6 = '\0';
  puVar15 = (undefined4 *)0x0;
  local_54[0] = 0;
LAB_14001e32a:
  do {
    plVar1 = (longlong *)*param_1;
    uVar8 = (uint)uVar9;
    if (plVar1 == param_1) {
LAB_14001e760:
      local_58 = uVar8;
      param_5 = *(longlong *)(puVar12 + 0xc0);
      goto LAB_14001e4eb;
    }
    if (((longlong *)plVar1[1] != param_1) || (lVar2 = *plVar1, *(longlong **)(lVar2 + 8) != plVar1)
       ) goto LAB_14001e759;
    *param_1 = lVar2;
    *(longlong **)(lVar2 + 8) = param_1;
    if ((char)plVar1[0xc] == '\0') {
      plVar10 = *(longlong **)(param_4 + 0x58);
      uVar13 = 0;
      if (plVar10 != (longlong *)0x0) {
        do {
          iVar6 = BfReturnedWalkContextAvlCompareRoutine(plVar1 + 10,(longlong)plVar10);
          if (iVar6 < 0) {
            plVar7 = (longlong *)*plVar10;
            if (plVar7 == (longlong *)0x0) {
              uVar13 = 0;
              break;
            }
          }
          else {
            plVar7 = (longlong *)plVar10[1];
            if (plVar7 == (longlong *)0x0) goto LAB_14001e542;
          }
          plVar10 = plVar7;
        } while( true );
      }
      goto LAB_14001e54c;
    }
    if (param_3 != 0) {
      cVar5 = FsRtlDoesNameContainWildCards(param_3);
      if (cVar5 == '\0') {
        iVar6 = RtlCompareUnicodeString(param_3,plVar1 + 10);
        if (iVar6 == 0) {
LAB_14001e5db:
          uVar9 = (ulonglong)local_58;
          goto LAB_14001e408;
        }
      }
      else {
        local_48 = 0;
        uStack_40 = 0;
        iVar6 = RtlUpcaseUnicodeString(&local_48,param_3);
        if (iVar6 < 0) {
          BfDereferenceMappingListEntry((longlong)plVar1);
          uVar9 = (ulonglong)local_58;
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,0xc,0x1b,
                                &WPP_4bfd87d54ffb3323a752b550f6ae0533_Traceguids,
                                "onecore\\base\\fs\\wci\\bindflt\\filter\\dirctrl.c",0xba,
                                (char)iVar6);
            uVar9 = (ulonglong)local_58;
          }
          goto LAB_14001e32a;
        }
        cVar5 = FsRtlIsNameInExpression(&local_48,plVar1 + 10,1,0);
        RtlFreeUnicodeString(&local_48);
        if (cVar5 != '\0') goto LAB_14001e5db;
      }
      puVar11 = *(undefined8 **)(param_4 + 0x58);
      if (puVar11 != (undefined8 *)0x0) {
        while( true ) {
          iVar6 = BfReturnedWalkContextAvlCompareRoutine(plVar1 + 10,(longlong)puVar11);
          if (iVar6 < 0) {
            puVar3 = (undefined8 *)*puVar11;
          }
          else {
            puVar3 = (undefined8 *)puVar11[1];
          }
          if (puVar3 == (undefined8 *)0x0) break;
          puVar11 = puVar3;
        }
      }
      RtlAvlInsertNodeEx(param_4 + 0x58,puVar11);
      uVar9 = (ulonglong)local_58;
      goto LAB_14001e32a;
    }
LAB_14001e408:
    local_54[0] = 0;
    iVar6 = BfGenerateDirectoryEntry
                      ((longlong)plVar1,local_res8,param_2,*(int *)(param_5 + 0x38) - (int)uVar9,
                       (void *)(uVar9 + *(longlong *)(param_5 + 0x40)),local_54);
    if ((local_res8 == '\0') || (iVar6 != -0x7ffffffb)) {
      if ((iVar6 == -0x3ffffffc) || (iVar6 == -0x7ffffffb)) {
        lVar2 = *param_1;
        if (*(longlong **)(lVar2 + 8) != param_1) goto LAB_14001e759;
        *plVar1 = lVar2;
        plVar1[1] = (longlong)param_1;
        *(longlong **)(lVar2 + 8) = plVar1;
        *param_1 = (longlong)plVar1;
        goto LAB_14001e4eb;
      }
      if (iVar6 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,0xc,0x1c,
                              &WPP_4bfd87d54ffb3323a752b550f6ae0533_Traceguids,
                              "onecore\\base\\fs\\wci\\bindflt\\filter\\dirctrl.c",2,(char)iVar6);
        }
        puVar11 = *(undefined8 **)(param_4 + 0x58);
        local_54[0] = 0;
        if (puVar11 != (undefined8 *)0x0) {
          while( true ) {
            iVar6 = BfReturnedWalkContextAvlCompareRoutine(plVar1 + 10,(longlong)puVar11);
            if (iVar6 < 0) {
              puVar3 = (undefined8 *)*puVar11;
            }
            else {
              puVar3 = (undefined8 *)puVar11[1];
            }
            if (puVar3 == (undefined8 *)0x0) break;
            puVar11 = puVar3;
          }
        }
      }
      else {
        puVar11 = *(undefined8 **)(param_4 + 0x58);
        if (puVar11 != (undefined8 *)0x0) {
          while( true ) {
            iVar6 = BfReturnedWalkContextAvlCompareRoutine(plVar1 + 10,(longlong)puVar11);
            if (iVar6 < 0) {
              puVar3 = (undefined8 *)*puVar11;
            }
            else {
              puVar3 = (undefined8 *)puVar11[1];
            }
            if (puVar3 == (undefined8 *)0x0) break;
            puVar11 = puVar3;
          }
        }
      }
      RtlAvlInsertNodeEx(param_4 + 0x58,puVar11);
    }
    else {
      lVar2 = *param_1;
      if (*(longlong **)(lVar2 + 8) != param_1) {
LAB_14001e759:
        uVar8 = 3;
        pcVar4 = (code *)swi(0x29);
        (*pcVar4)();
        puVar12 = auStackY_90;
        goto LAB_14001e760;
      }
      *plVar1 = lVar2;
      plVar1[1] = (longlong)param_1;
      *(longlong **)(lVar2 + 8) = plVar1;
      *param_1 = (longlong)plVar1;
      *param_6 = '\x01';
    }
    uVar14 = (ulonglong)local_58;
    local_58 = local_58 + local_54[0];
    uVar9 = (ulonglong)local_58;
    puVar15 = (undefined4 *)(uVar14 + *(longlong *)(param_5 + 0x40));
    local_res8 = '\0';
    if (*param_6 != '\0') {
LAB_14001e4eb:
      if (puVar15 != (undefined4 *)0x0) {
        *puVar15 = 0;
      }
      *(uint *)(param_5 + 0x30) = local_58;
      return;
    }
  } while( true );
LAB_14001e542:
  uVar13 = 1;
LAB_14001e54c:
  RtlAvlInsertNodeEx(param_4 + 0x58,plVar10,uVar13,plVar1 + 2);
  uVar9 = (ulonglong)local_58;
  goto LAB_14001e32a;
}



===== BfpMappingInsertIntoTable @ 14001e774 =====

/* WARNING: Type propagation algorithm not settling */

ulonglong BfpMappingInsertIntoTable
                    (longlong *param_1,uint param_2,longlong *param_3,longlong param_4,
                    undefined8 *param_5,uint param_6,longlong param_7,longlong param_8)

{
  longlong *plVar1;
  short sVar2;
  undefined8 *puVar3;
  bool bVar4;
  char cVar5;
  bool bVar6;
  int iVar7;
  uint uVar8;
  undefined8 uVar9;
  ulonglong uVar10;
  ulonglong *puVar11;
  ulonglong uVar12;
  uint *puVar13;
  ulonglong uVar14;
  undefined8 *puVar15;
  ulonglong *puVar16;
  ulonglong *puVar17;
  uint *puVar18;
  uint *puVar19;
  undefined2 uVar20;
  char cVar21;
  longlong *in_stack_ffffffffffffff08;
  longlong in_stack_ffffffffffffff10;
  undefined1 uVar22;
  undefined1 uVar23;
  wchar_t *pwVar24;
  char local_c8;
  longlong *local_c0;
  longlong *local_b8;
  wchar_t *local_b0;
  ulonglong uStack_a8;
  uint *local_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  uint local_88;
  undefined8 *local_80;
  uint *local_78;
  undefined8 local_70;
  undefined8 uStack_68;
  ulonglong *local_60;
  undefined8 local_58;
  longlong lStack_50;
  
  bVar6 = false;
  local_a0 = (uint *)0x0;
  local_78 = (uint *)0x0;
  local_60 = (ulonglong *)0x0;
  local_80 = (undefined8 *)0x0;
  local_c0 = (longlong *)0x0;
  local_b8 = (longlong *)0x0;
  local_98 = 0;
  uStack_90 = 0;
  local_70 = 0;
  uStack_68 = 0;
  if (((byte)param_2 & 0x11) == 0x10) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0xc000000d;
    }
    uVar20 = 0x5d;
    uVar23 = 0xe6;
LAB_14001f068:
    WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,8,uVar20,
                       &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                       "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",uVar23);
    return 0xc000000d;
  }
  uVar9 = BfWalkContainerRootId(*param_1,(short *)&local_98);
  local_c8 = (char)uVar9;
  if (param_8 != 0) {
    BfWalkContainerRootId(param_8,(short *)&local_70);
  }
  puVar13 = (uint *)0x0;
  puVar17 = *(ulonglong **)(param_4 + 0x18);
  if ((wchar_t)local_98 != L'\0') {
    do {
      local_b0 = (wchar_t *)&local_98;
      puVar19 = (uint *)*puVar17;
      uStack_a8 = (ulonglong)puVar13 & 0xff;
      if ((puVar17[1] & 1) != 0) {
        if (puVar19 == (uint *)0x0) {
          puVar19 = puVar13;
        }
        else {
          puVar19 = (uint *)((ulonglong)puVar19 ^ (ulonglong)puVar17);
        }
      }
      uVar12 = puVar17[1];
      if (puVar19 == (uint *)0x0) {
LAB_14001e8f9:
        if ((param_2 >> 8 & 1) == 0) goto LAB_14001e906;
        puVar19 = (uint *)*puVar17;
        uStack_a8 = CONCAT71(uStack_a8._1_7_,1);
        if ((puVar17[1] & 1) != 0) {
          if (puVar19 == (uint *)0x0) {
            puVar19 = puVar13;
          }
          else {
            puVar19 = (uint *)((ulonglong)puVar19 ^ (ulonglong)puVar17);
          }
        }
        uVar12 = puVar17[1];
        goto LAB_14001f448;
      }
      do {
        uVar10 = BfpRBComparePathNodes(&local_b0,(longlong)puVar19);
        if ((int)uVar10 < 0) {
          puVar18 = *(uint **)puVar19;
        }
        else {
          puVar18 = puVar19;
          if ((int)uVar10 < 1) break;
          puVar18 = *(uint **)(puVar19 + 2);
        }
        if (((uVar12 & 1) != 0) && (puVar18 != (uint *)0x0)) {
          puVar18 = (uint *)((ulonglong)puVar19 ^ (ulonglong)puVar18);
        }
        puVar19 = puVar18;
      } while (puVar18 != (uint *)0x0);
      puVar13 = (uint *)0x0;
      if (puVar18 == (uint *)0x0) goto LAB_14001e8f9;
      if ((puVar18[-2] & 2) != 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return 0xc000000d;
        }
        uVar20 = 100;
        uVar23 = 0x8e;
        goto LAB_14001f068;
      }
      if (local_c8 == '\0') goto LAB_14001eb4a;
      uVar9 = BfWalkContainerRootId(*param_1,(short *)&local_98);
      local_c8 = (char)uVar9;
      if (param_8 != 0) {
        BfWalkContainerRootId(param_8,(short *)&local_70);
      }
      puVar13 = (uint *)0x0;
      puVar19 = puVar18 + 0x12;
      puVar17 = *(ulonglong **)puVar19;
      bVar4 = BfpPathTreeEmpty(puVar17);
      if (bVar4) goto LAB_14001f0ae;
      local_a0 = puVar13;
    } while( true );
  }
  plVar1 = (longlong *)(param_4 + 0x20);
  if ((*plVar1 != 0) || (bVar6 = BfpPathTreeEmpty(puVar17), !bVar6)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0xc000000d;
    }
    uVar20 = 0x5e;
    uVar23 = 0xb;
    goto LAB_14001f068;
  }
  uVar12 = BfpCreatePathTierNode
                     (0x1400097c0,9,'\x01',param_2,param_3,*param_1,(longlong *)puVar13,puVar17,
                      plVar1);
  uVar10 = uVar12 & 0xffffffff;
  if ((int)uVar12 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return uVar10;
    }
    uVar23 = (undefined1)uVar12;
    uVar20 = 0x5f;
    uVar22 = 0x2c;
    goto LAB_14001f0ed;
  }
  bVar6 = true;
  if ((param_2 & 2) == 0) {
LAB_14001f332:
    uVar12 = BfpCreateTargetEntry(param_5,param_1[1],(longlong *)&local_c0);
    uVar10 = uVar12 & 0xffffffff;
    if ((int)uVar12 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar23 = (undefined1)uVar12;
        uVar20 = 0x62;
        uVar22 = 0x57;
LAB_14001f2a8:
        WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,8,uVar20,
                            &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                            "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",uVar22,uVar23);
      }
    }
    else {
      uVar12 = BfpInsertTargetEntryIntoMappingInformation
                         (*param_3,local_c0,*(longlong *)(*plVar1 + 0x48));
      uVar10 = uVar12 & 0xffffffff;
      if ((int)uVar12 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar23 = (undefined1)uVar12;
          uVar20 = 99;
          uVar22 = 0x61;
          goto LAB_14001f2a8;
        }
      }
      else {
        local_c0 = (longlong *)0x0;
        puVar13 = (uint *)*plVar1;
LAB_14001eb02:
        if (param_6 == 0) {
          return 0;
        }
        uVar8 = BfpMappingInsertExceptions(param_1,(longlong)puVar13,param_3,param_6,param_7);
        uVar10 = (ulonglong)uVar8;
        if (-1 < (int)uVar8) {
          return 0;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar23 = (undefined1)uVar8;
          uVar20 = 0x78;
          uVar22 = 0xb2;
LAB_14001ef71:
          WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,8,uVar20,
                              &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                              "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",uVar22,uVar23);
        }
LAB_14001ec7d:
        puVar13 = local_78;
        if (local_78 != (uint *)0x0) {
          RtlRbRemoveNode(local_60,local_78 + 2);
          BfpDeletePathTierNode(puVar13);
        }
        if (!bVar6) goto LAB_14001ec97;
      }
    }
  }
  else {
    uVar12 = BfpCreateTargetEntry(param_3,*param_1,(longlong *)&local_c0);
    uVar10 = uVar12 & 0xffffffff;
    if ((int)uVar12 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar23 = (undefined1)uVar12;
        uVar20 = 0x60;
        uVar22 = 0x3e;
        goto LAB_14001f2a8;
      }
    }
    else {
      uVar12 = BfpInsertTargetEntryIntoMappingInformation
                         (*param_3,local_c0,*(longlong *)(*plVar1 + 0x48));
      uVar10 = uVar12 & 0xffffffff;
      if (-1 < (int)uVar12) {
        local_c0 = (longlong *)0x0;
        goto LAB_14001f332;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar23 = (undefined1)uVar12;
        uVar20 = 0x61;
        uVar22 = 0x48;
        goto LAB_14001f2a8;
      }
    }
  }
  BfpDeletePathTierNode(*(uint **)(param_4 + 0x20));
  *(undefined8 *)(param_4 + 0x20) = 0;
LAB_14001ec97:
  if (local_c0 != (longlong *)0x0) {
    BfpDeleteTargetEntry((longlong)local_c0);
  }
  if (local_b8 == (longlong *)0x0) {
    return uVar10;
  }
  BfpDeleteTargetEntry((longlong)local_b8);
  return uVar10;
LAB_14001f448:
  if (puVar19 != (uint *)0x0) {
    puVar13 = puVar19;
    uVar10 = BfpRBComparePathNodes(&local_b0,(longlong)puVar19);
    if ((int)uVar10 < 0) {
      puVar18 = *(uint **)puVar19;
    }
    else {
      if ((int)uVar10 < 1) goto LAB_14001f44d;
      puVar18 = *(uint **)(puVar19 + 2);
    }
    if (((uVar12 & 1) == 0) || (puVar18 == (uint *)0x0)) {
      puVar19 = puVar18;
    }
    else {
      puVar19 = (uint *)((ulonglong)puVar19 ^ (ulonglong)puVar18);
    }
    goto LAB_14001f448;
  }
LAB_14001f44d:
  if (puVar19 != (uint *)0x0) {
    uVar12 = 0xc00000bd;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0xc00000bd;
    }
    pwVar24 = (wchar_t *)(puVar19 + 0xc);
    uVar20 = 0x66;
    uVar23 = 0xe6;
    goto LAB_14001f4a5;
  }
LAB_14001e906:
  if (((param_2 >> 9 & 1) != 0) && (local_c8 != '\0')) {
    uVar12 = 0xc000003a;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0xc000003a;
    }
    pwVar24 = (wchar_t *)&local_98;
    uVar20 = 0x67;
    uVar23 = 0xfa;
LAB_14001f4a5:
    WPP_RECORDER_SF_sDZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar13,8,uVar20,
                        in_stack_ffffffffffffff08,in_stack_ffffffffffffff10,uVar23,pwVar24);
    return uVar12;
  }
LAB_14001e911:
  cVar21 = '\0';
  if ((local_c8 != '\0') || (param_6 != 0)) {
    cVar21 = '\x01';
  }
  puVar15 = (undefined8 *)*puVar17;
  local_b0 = (wchar_t *)&local_98;
  uStack_a8 = 0;
  if (((puVar17[1] & 1) != 0) && (puVar15 != (undefined8 *)0x0)) {
    puVar15 = (undefined8 *)((ulonglong)puVar15 ^ (ulonglong)puVar17);
  }
  uVar12 = puVar17[1];
  local_88 = (uint)(local_c8 == '\0');
  while (puVar3 = puVar15, puVar3 != (undefined8 *)0x0) {
    uVar10 = BfpRBComparePathNodes(&local_b0,(longlong)puVar3);
    if ((int)uVar10 < 0) {
      puVar15 = (undefined8 *)*puVar3;
    }
    else {
      if ((int)uVar10 < 1) break;
      puVar15 = (undefined8 *)puVar3[1];
    }
    if (((uVar12 & 1) != 0) && (puVar15 != (undefined8 *)0x0)) {
      puVar15 = (undefined8 *)((ulonglong)puVar3 ^ (ulonglong)puVar15);
    }
  }
  if (puVar3 == (undefined8 *)0x0) {
    in_stack_ffffffffffffff10 = *param_1;
    in_stack_ffffffffffffff08 = param_3;
    uVar12 = BfpCreatePathTierNode
                       ((longlong)&local_98,(uint)(local_c8 == '\0'),cVar21,param_2,param_3,
                        in_stack_ffffffffffffff10,(longlong *)0x0,0,&local_a0);
    puVar13 = local_a0;
    uVar10 = uVar12 & 0xffffffff;
    if ((int)uVar12 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001ec7d;
      uVar23 = (undefined1)uVar12;
      uVar20 = 0x68;
      uVar22 = 0x38;
      goto LAB_14001ef71;
    }
    if (local_c8 == '\0') {
      if ((param_2 & 2) != 0) {
        uVar12 = BfpCreateTargetEntry(param_3,*param_1,(longlong *)&local_b8);
        uVar10 = uVar12 & 0xffffffff;
        if ((int)uVar12 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_14001ec7d;
          uVar23 = (undefined1)uVar12;
          uVar20 = 0x69;
          uVar22 = 0x49;
          goto LAB_14001ef71;
        }
        uVar12 = BfpInsertTargetEntryIntoMappingInformation
                           (*param_3,local_b8,*(longlong *)(puVar13 + 0x12));
        uVar10 = uVar12 & 0xffffffff;
        if ((int)uVar12 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_14001ec7d;
          uVar23 = (undefined1)uVar12;
          uVar20 = 0x6a;
          uVar22 = 0x53;
          goto LAB_14001ef71;
        }
        local_b8 = (longlong *)0x0;
      }
      uVar12 = BfpCreateTargetEntry(param_5,param_1[1],(longlong *)&local_c0);
      uVar10 = uVar12 & 0xffffffff;
      if ((int)uVar12 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001ec7d;
        uVar23 = (undefined1)uVar12;
        uVar20 = 0x6b;
        uVar22 = 0x62;
        goto LAB_14001ef71;
      }
      uVar12 = BfpInsertTargetEntryIntoMappingInformation
                         (*param_3,local_c0,*(longlong *)(puVar13 + 0x12));
      uVar10 = uVar12 & 0xffffffff;
      if ((int)uVar12 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001ec7d;
        uVar23 = (undefined1)uVar12;
        uVar20 = 0x6c;
        uVar22 = 0x6c;
        goto LAB_14001ef71;
      }
      local_c0 = (longlong *)0x0;
    }
    puVar16 = (ulonglong *)*puVar17;
    if (((puVar17[1] & 1) != 0) && (puVar16 != (ulonglong *)0x0)) {
      puVar16 = (ulonglong *)((ulonglong)puVar16 ^ (ulonglong)puVar17);
    }
    uVar12 = puVar17[1];
    uVar9 = 0;
    if (puVar16 != (ulonglong *)0x0) {
      do {
        uVar10 = BfpRBComparePathNodes(&local_b0,(longlong)puVar16);
        if ((int)uVar10 < 0) {
          puVar11 = (ulonglong *)*puVar16;
          if ((uVar12 & 1) == 0) {
LAB_14001eb5e:
            if (puVar11 != (ulonglong *)0x0) goto LAB_14001ea73;
          }
          else if (puVar11 != (ulonglong *)0x0) {
            puVar11 = (ulonglong *)((ulonglong)puVar11 ^ (ulonglong)puVar16);
            goto LAB_14001eb5e;
          }
          uVar9 = 0;
          break;
        }
        puVar11 = (ulonglong *)puVar16[1];
        if ((uVar12 & 1) != 0) {
          if (puVar11 == (ulonglong *)0x0) goto LAB_14001ea80;
          puVar11 = (ulonglong *)((ulonglong)puVar11 ^ (ulonglong)puVar16);
        }
        if (puVar11 == (ulonglong *)0x0) goto LAB_14001ea80;
LAB_14001ea73:
        puVar16 = puVar11;
      } while( true );
    }
    goto LAB_14001ea85;
  }
  puVar13 = (uint *)(puVar3 + -1);
  local_a0 = puVar13;
  if (local_c8 != '\0') goto LAB_14001ea9b;
  if ((*puVar13 & 1) != 0) {
    uVar12 = (ulonglong)param_2;
    if ((param_2 & 0x40) == 0) {
      if (puVar3[8] != 0) {
        uVar8 = *(uint *)(puVar3[8] + 8);
        uVar14 = (ulonglong)uVar8;
        bVar4 = BfpDoMappingFlagsMatch(param_2,uVar8);
        if (!bVar4) {
          uVar10 = 0xc000000d;
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_sDDD
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar14,8,0x6e,
                       in_stack_ffffffffffffff08,in_stack_ffffffffffffff10,0x9b,(char)uVar14,
                       (char)uVar12);
          }
          goto LAB_14001ec7d;
        }
      }
      if ((uVar12 & 1) != 0) goto LAB_14001ebbf;
      uVar10 = 0xc000000d;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001ec7d;
      uVar20 = 0x6f;
      uVar23 = 0xa7;
    }
    else {
      uVar10 = 0xc000000d;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001ec7d;
      uVar20 = 0x6d;
      uVar23 = 0x8f;
    }
    uVar10 = 0xc000000d;
    WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,8,uVar20,
                       &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                       "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",uVar23);
    goto LAB_14001ec7d;
  }
LAB_14001ebbf:
  uVar12 = BfpCreateTargetEntry(param_5,param_1[1],(longlong *)&local_c0);
  uVar10 = uVar12 & 0xffffffff;
  if ((int)uVar12 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001ec7d;
    uVar23 = (undefined1)uVar12;
    uVar20 = 0x70;
    uVar22 = 0xb4;
    goto LAB_14001ef71;
  }
  plVar1 = puVar3 + 8;
  if (*plVar1 == 0) {
    *puVar13 = 1;
    uVar12 = BfpCreateMappingInformation(*param_1,param_2,plVar1);
    uVar10 = uVar12 & 0xffffffff;
    if ((int)uVar12 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001ec7d;
      uVar23 = (undefined1)uVar12;
      uVar20 = 0x72;
      uVar22 = 0xd4;
      goto LAB_14001ef71;
    }
    sVar2 = *(short *)(*param_1 + 4);
    lStack_50 = *param_1 + 6;
    local_58 = (ulonglong)CONCAT22(sVar2,sVar2);
    uVar12 = BfAllocateUnicodeString(sVar2,(undefined4 *)(puVar3 + 6));
    uVar10 = uVar12 & 0xffffffff;
    if ((int)uVar12 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001ec7d;
      uVar23 = (undefined1)uVar12;
      uVar20 = 0x73;
      uVar22 = 0xe0;
      goto LAB_14001ef71;
    }
    RtlCopyUnicodeString(puVar3 + 6,&local_58);
    puVar3[5] = *param_3;
  }
  else {
    cVar5 = BfTargetEntryExistsInMappingInformation((longlong)local_c0,*plVar1);
    if (cVar5 != '\0') {
      uVar10 = 0xc000000d;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001ec7d;
      uVar23 = 0xd;
      uVar20 = 0x71;
      uVar22 = 0xc0;
      goto LAB_14001ef71;
    }
    *(undefined1 *)(*plVar1 + 0x30) = 1;
  }
  if ((param_2 & 2) != 0) {
    uVar12 = BfpCreateTargetEntry(param_3,*param_1,(longlong *)&local_b8);
    uVar10 = uVar12 & 0xffffffff;
    if ((int)uVar12 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001ec7d;
      uVar23 = (undefined1)uVar12;
      uVar20 = 0x74;
      uVar22 = 0xf4;
      goto LAB_14001ef71;
    }
    uVar12 = BfpInsertTargetEntryIntoMappingInformation(*param_3,local_b8,*plVar1);
    uVar10 = uVar12 & 0xffffffff;
    if ((int)uVar12 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001ec7d;
      uVar23 = (undefined1)uVar12;
      uVar20 = 0x75;
      uVar22 = 0xfe;
      goto LAB_14001ef71;
    }
    local_b8 = (longlong *)0x0;
  }
  uVar12 = BfpInsertTargetEntryIntoMappingInformation(*param_3,local_c0,puVar3[8]);
  uVar10 = uVar12 & 0xffffffff;
  if ((int)uVar12 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001ec7d;
    uVar23 = (undefined1)uVar12;
    uVar20 = 0x76;
    uVar22 = 0xb;
    goto LAB_14001ef71;
  }
  local_c0 = (longlong *)0x0;
LAB_14001ea9b:
  uVar9 = 0;
  if (local_78 == (uint *)0x0) {
    local_78 = puVar13;
    local_60 = puVar17;
  }
  if (((param_8 != 0) &&
      (iVar7 = RtlCompareUnicodeString(&local_70,&g_NoShortComponent,0), iVar7 != 0)) &&
     (iVar7 = RtlCompareUnicodeString(&local_70,&local_98), iVar7 != 0)) {
    if (cVar21 != '\0') {
      uVar9 = *(undefined8 *)(puVar13 + 0x14);
    }
    local_b0 = (wchar_t *)&local_70;
    puVar15 = (undefined8 *)*puVar17;
    uStack_a8 = 0;
    if (((puVar17[1] & 1) != 0) && (puVar15 != (undefined8 *)0x0)) {
      puVar15 = (undefined8 *)((ulonglong)puVar15 ^ (ulonglong)puVar17);
    }
    uVar12 = puVar17[1];
    while (puVar3 = puVar15, puVar3 != (undefined8 *)0x0) {
      uVar10 = BfpRBComparePathNodes(&local_b0,(longlong)puVar3);
      if ((int)uVar10 < 0) {
        puVar15 = (undefined8 *)*puVar3;
      }
      else {
        if ((int)uVar10 < 1) break;
        puVar15 = (undefined8 *)puVar3[1];
      }
      if (((uVar12 & 1) != 0) && (puVar15 != (undefined8 *)0x0)) {
        puVar15 = (undefined8 *)((ulonglong)puVar3 ^ (ulonglong)puVar15);
      }
    }
    if (puVar3 == (undefined8 *)0x0) {
      in_stack_ffffffffffffff10 = 0;
      in_stack_ffffffffffffff08 = (longlong *)0x0;
      uVar12 = BfpCreatePathTierNode
                         ((longlong)&local_70,local_88 | 2,cVar21,0,(undefined8 *)0x0,0,
                          *(longlong **)(puVar13 + 0x12),uVar9,&local_80);
      puVar15 = local_80;
      uVar10 = uVar12 & 0xffffffff;
      if ((int)uVar12 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001ec7d;
        uVar23 = (undefined1)uVar12;
        uVar20 = 0x77;
        uVar22 = 0x60;
        goto LAB_14001ef71;
      }
      puVar16 = (ulonglong *)*puVar17;
      if (((puVar17[1] & 1) != 0) && (puVar16 != (ulonglong *)0x0)) {
        puVar16 = (ulonglong *)((ulonglong)puVar16 ^ (ulonglong)puVar17);
      }
      uVar12 = puVar17[1];
      if (puVar16 != (ulonglong *)0x0) {
        do {
          uVar10 = BfpRBComparePathNodes(&local_b0,(longlong)puVar16);
          if ((int)uVar10 < 0) {
            puVar11 = (ulonglong *)*puVar16;
            if ((uVar12 & 1) != 0) {
              if (puVar11 == (ulonglong *)0x0) break;
              puVar11 = (ulonglong *)((ulonglong)puVar11 ^ (ulonglong)puVar16);
            }
          }
          else {
            puVar11 = (ulonglong *)puVar16[1];
            if ((uVar12 & 1) != 0) {
              if (puVar11 == (ulonglong *)0x0) break;
              puVar11 = (ulonglong *)((ulonglong)puVar11 ^ (ulonglong)puVar16);
            }
          }
          if (puVar11 == (ulonglong *)0x0) break;
          puVar16 = puVar11;
        } while( true );
      }
      RtlRbInsertNodeEx(puVar17,puVar16);
      *(undefined8 **)(puVar13 + 0x16) = puVar15;
    }
    else {
      local_80 = puVar3 + -1;
    }
  }
  if (local_c8 != '\0') {
    puVar17 = *(ulonglong **)(puVar13 + 0x14);
  }
  uVar9 = BfWalkContainerRootId(*param_1,(short *)&local_98);
  local_c8 = (char)uVar9;
  if (param_8 != 0) {
    BfWalkContainerRootId(param_8,(short *)&local_70);
  }
  if ((wchar_t)local_98 == L'\0') goto LAB_14001eb02;
  goto LAB_14001e911;
LAB_14001f0ae:
  if (puVar17 == (ulonglong *)0x0) {
    uVar12 = BfpCreatePathTree((undefined8 *)puVar19);
    uVar10 = uVar12 & 0xffffffff;
    if ((int)uVar12 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return uVar10;
      }
      uVar23 = (undefined1)uVar12;
      uVar20 = 0x65;
      uVar22 = 0xc5;
LAB_14001f0ed:
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,8,uVar20,
                          &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                          "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",uVar22,uVar23);
      return uVar10;
    }
    if (*(longlong *)(puVar18 + 0x14) != 0) {
      *(undefined8 *)(*(longlong *)(puVar18 + 0x14) + 0x50) = *(undefined8 *)puVar19;
    }
  }
  puVar17 = *(ulonglong **)puVar19;
LAB_14001eb4a:
  local_a0 = (uint *)0x0;
  goto LAB_14001e906;
LAB_14001ea80:
  uVar9 = 1;
LAB_14001ea85:
  RtlRbInsertNodeEx(puVar17,puVar16,uVar9);
  goto LAB_14001ea9b;
}



===== BfGenerateDirectoryEntry @ 14001f780 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int BfGenerateDirectoryEntry
              (longlong param_1,char param_2,int param_3,uint param_4,void *param_5,uint *param_6)

{
  ushort uVar1;
  undefined8 uVar2;
  int iVar3;
  undefined8 *puVar4;
  void *_Dst;
  int *_Src;
  uint uVar5;
  uint uVar6;
  undefined1 auStackY_138 [32];
  int local_d8 [3];
  undefined4 local_cc;
  int local_c8 [2];
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined4 local_90;
  uint local_8c;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 uStack_70;
  undefined8 local_68;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_138;
  iVar3 = 0;
  puVar4 = (undefined8 *)ExAllocatePool2(0x100,0x70,0x65644642);
  if (puVar4 == (undefined8 *)0x0) {
    return -0x3fffff66;
  }
  uVar5 = 0;
  if (param_3 < 0x3d) {
    if (param_3 == 0x3c) {
      uVar5 = 0x58;
    }
    else if (param_3 == 1) {
      uVar5 = 0x40;
    }
    else if (param_3 == 2) {
      uVar5 = 0x44;
    }
    else if (param_3 == 3) {
      uVar5 = 0x5e;
    }
    else if (param_3 == 0xc) {
      uVar5 = 0xc;
    }
    else if (param_3 == 0x25) {
      uVar5 = 0x68;
    }
    else if (param_3 == 0x26) goto LAB_14001fd98;
  }
  else if (param_3 == 0x3f) {
    uVar5 = 0x72;
  }
  else if (param_3 == 0x4e) {
LAB_14001fd98:
    uVar5 = 0x50;
  }
  else if (param_3 == 0x4f) {
    uVar5 = 0x6a;
  }
  else if (param_3 == 0x50) {
    uVar5 = 0x60;
  }
  else if (param_3 == 0x51) {
    uVar5 = 0x7a;
  }
  if ((param_4 < *(ushort *)(param_1 + 0x50) + uVar5) && (param_2 == '\0')) {
    iVar3 = -0x7ffffffb;
    goto LAB_14001f9ce;
  }
  if (param_4 < uVar5) {
    iVar3 = -0x3ffffffc;
    goto LAB_14001f9ce;
  }
  if (*(longlong *)(param_1 + 0x68) == 0) {
    puVar4[3] = *(undefined8 *)(param_1 + 0xb8);
    *puVar4 = *(undefined8 *)(param_1 + 0xa0);
    puVar4[1] = *(undefined8 *)(param_1 + 0xa8);
    puVar4[2] = *(undefined8 *)(param_1 + 0xb0);
    *(undefined4 *)(puVar4 + 4) = *(undefined4 *)(param_1 + 0xd0);
    puVar4[5] = *(undefined8 *)(param_1 + 200);
    puVar4[6] = *(undefined8 *)(param_1 + 0xc0);
    *(undefined4 *)(puVar4 + 8) = *(undefined4 *)(param_1 + 0xd8);
    puVar4[9] = *(undefined8 *)(param_1 + 0xe0);
    uVar2 = *(undefined8 *)(param_1 + 0xf0);
    puVar4[0xc] = *(undefined8 *)(param_1 + 0xe8);
    puVar4[0xd] = uVar2;
    *(undefined4 *)((longlong)puVar4 + 0x54) = *(undefined4 *)(param_1 + 0xdc);
  }
  else {
    if (param_3 == 0xc) {
LAB_14001febd:
      if ((param_3 - 0x25U < 0x2d) &&
         ((0x1e0004800001U >> ((ulonglong)(param_3 - 0x25U) & 0x3f) & 1) != 0)) goto LAB_14001fb1d;
LAB_14001fb86:
      if (param_3 == 0x51) goto LAB_14001fce1;
    }
    else {
      iVar3 = FltQueryInformationFile
                        (*(undefined8 *)(param_1 + 0x48),*(longlong *)(param_1 + 0x68),puVar4,0x28);
      if ((iVar3 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        WPP_RECORDER_SF_sDdd
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,0xc,0x13,
                   &WPP_4bfd87d54ffb3323a752b550f6ae0533_Traceguids,
                   "onecore\\base\\fs\\wci\\bindflt\\filter\\dirctrl.c",0x97,(char)iVar3,4);
      }
      *(uint *)(puVar4 + 4) = *(uint *)(puVar4 + 4) & 0xfffffff9;
      iVar3 = FltQueryInformationFile
                        (*(undefined8 *)(param_1 + 0x48),*(undefined8 *)(param_1 + 0x68),puVar4 + 5,
                         0x18);
      if ((iVar3 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        WPP_RECORDER_SF_sDdd
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,0xc,0x14,
                   &WPP_4bfd87d54ffb3323a752b550f6ae0533_Traceguids,
                   "onecore\\base\\fs\\wci\\bindflt\\filter\\dirctrl.c",0xa9,(char)iVar3,5);
      }
      if ((1 < param_3 - 2U) && (param_3 != 0x26)) goto LAB_14001febd;
LAB_14001fb1d:
      iVar3 = FltQueryInformationFile
                        (*(undefined8 *)(param_1 + 0x48),*(undefined8 *)(param_1 + 0x68),puVar4 + 8,
                         4);
      if ((iVar3 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        WPP_RECORDER_SF_sDdd
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,0xc,0x15,
                   &WPP_4bfd87d54ffb3323a752b550f6ae0533_Traceguids,
                   "onecore\\base\\fs\\wci\\bindflt\\filter\\dirctrl.c",0xc0,(char)iVar3,7);
      }
      if ((((param_3 != 0x26) && (param_3 != 0x25)) && (param_3 != 0x4e)) &&
         ((param_3 != 0x4f && (param_3 != 0x50)))) goto LAB_14001fb86;
LAB_14001fce1:
      iVar3 = FltQueryInformationFile
                        (*(undefined8 *)(param_1 + 0x48),*(undefined8 *)(param_1 + 0x68),puVar4 + 9,
                         8);
      if ((iVar3 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        WPP_RECORDER_SF_sDdd
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,0xc,0x16,
                   &WPP_4bfd87d54ffb3323a752b550f6ae0533_Traceguids,
                   "onecore\\base\\fs\\wci\\bindflt\\filter\\dirctrl.c",0xd4,(char)iVar3,6);
      }
    }
    if ((param_3 - 0x3cU < 0x16) && ((0x300009U >> (param_3 - 0x3cU & 0x1f) & 1) != 0)) {
      iVar3 = FltQueryInformationFile
                        (*(undefined8 *)(param_1 + 0x48),*(undefined8 *)(param_1 + 0x68),
                         puVar4 + 0xb,0x18);
      if (iVar3 == -0x3fffff45) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sDdd
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,0xc,0x17,
                     &WPP_4bfd87d54ffb3323a752b550f6ae0533_Traceguids,
                     "onecore\\base\\fs\\wci\\bindflt\\filter\\dirctrl.c",0xe6,0xbb,0x3b);
        }
        puVar4[0xc] = 0xffffffffffffffff;
        puVar4[0xd] = 0xffffffffffffffff;
      }
      else if ((iVar3 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_SF_sDdd
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,0xc,0x18,
                   &WPP_4bfd87d54ffb3323a752b550f6ae0533_Traceguids,
                   "onecore\\base\\fs\\wci\\bindflt\\filter\\dirctrl.c",0xea,(char)iVar3,0x3b);
      }
      if ((param_3 != 0x3c) && (param_3 != 0x3f)) goto LAB_14001fc5e;
    }
    else {
LAB_14001fc5e:
      if (3 < param_3 - 0x4eU) goto LAB_14001f8d8;
    }
    iVar3 = FltQueryInformationFile
                      (*(undefined8 *)(param_1 + 0x48),*(undefined8 *)(param_1 + 0x68),puVar4 + 10,8
                      );
    if ((iVar3 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_SF_sDdd
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,0xc,0x19,
                 &WPP_4bfd87d54ffb3323a752b550f6ae0533_Traceguids,
                 "onecore\\base\\fs\\wci\\bindflt\\filter\\dirctrl.c",0xfd,(char)iVar3,0x23);
    }
  }
LAB_14001f8d8:
  if (param_3 < 0x3d) {
    if (param_3 == 0x3c) {
      local_80 = puVar4[0xc];
      uStack_78 = puVar4[0xd];
      local_c8[1] = 0;
      uStack_70 = 0;
      local_8c = (uint)*(ushort *)(param_1 + 0x50);
      local_c8[0] = local_8c + uVar5;
      local_98 = puVar4[5];
      local_a8 = puVar4[3];
      local_c0 = *puVar4;
      local_a0 = puVar4[6];
      local_90 = *(undefined4 *)(puVar4 + 4);
      local_b8 = puVar4[1];
      local_b0 = puVar4[2];
      local_88 = CONCAT44(*(undefined4 *)((longlong)puVar4 + 0x54),*(undefined4 *)(puVar4 + 8));
LAB_14001fa95:
      _Src = local_c8;
    }
    else {
      if (param_3 == 1) {
        uVar1 = *(ushort *)(param_1 + 0x50);
        local_88 = 0;
        local_98 = puVar4[5];
        local_a8 = puVar4[3];
        local_c0 = *puVar4;
      }
      else {
        if (param_3 != 2) {
          if (param_3 != 3) {
            if (param_3 != 0xc) {
              if (param_3 == 0x25) {
                memset(local_c8,0,0x70);
                local_8c = (uint)*(ushort *)(param_1 + 0x50);
                local_c8[0] = local_8c + uVar5;
                local_98 = puVar4[5];
                local_a8 = puVar4[3];
                local_c0 = *puVar4;
                local_a0 = puVar4[6];
                local_90 = *(undefined4 *)(puVar4 + 4);
                local_b8 = puVar4[1];
                local_b0 = puVar4[2];
                local_68 = puVar4[9];
                local_88._0_5_ = CONCAT14(*(char *)(param_1 + 0x78),*(undefined4 *)(puVar4 + 8));
                if ('\0' < *(char *)(param_1 + 0x78)) {
                  _Dst = (void *)((longlong)&local_88 + 6);
                  goto LAB_140020199;
                }
                goto LAB_1400201a6;
              }
              if (param_3 != 0x26) goto LAB_1400202d0;
              uVar1 = *(ushort *)(param_1 + 0x50);
              local_98 = puVar4[5];
              local_a8 = puVar4[3];
              local_c0 = *puVar4;
              local_88 = (ulonglong)*(uint *)(puVar4 + 8);
              local_a0 = puVar4[6];
              local_90 = *(undefined4 *)(puVar4 + 4);
              local_b8 = puVar4[1];
              local_b0 = puVar4[2];
              local_80 = puVar4[9];
              goto LAB_14002011e;
            }
            _Src = local_d8;
            local_cc = 0;
            local_d8[1] = 0;
            local_d8[2] = (int)*(ushort *)(param_1 + 0x50);
            local_d8[0] = local_d8[2] + uVar5;
            goto LAB_14001f991;
          }
          memset(local_c8,0,0x60);
          local_8c = (uint)*(ushort *)(param_1 + 0x50);
          local_c8[0] = local_8c + uVar5;
          local_98 = puVar4[5];
          local_a8 = puVar4[3];
          local_c0 = *puVar4;
          local_a0 = puVar4[6];
          local_90 = *(undefined4 *)(puVar4 + 4);
          local_b8 = puVar4[1];
          local_b0 = puVar4[2];
          local_88._0_5_ = CONCAT14(*(char *)(param_1 + 0x78),*(undefined4 *)(puVar4 + 8));
          if ('\0' < *(char *)(param_1 + 0x78)) {
            memmove((void *)((longlong)&local_88 + 6),(void *)(param_1 + 0x7c),
                    (ulonglong)*(uint *)(param_1 + 0x78));
          }
          goto LAB_14001fa95;
        }
        uVar1 = *(ushort *)(param_1 + 0x50);
        local_98 = puVar4[5];
        local_a8 = puVar4[3];
        local_c0 = *puVar4;
        local_88 = (ulonglong)*(uint *)(puVar4 + 8);
      }
      local_8c = (uint)uVar1;
      local_c8[0] = local_8c + uVar5;
      local_c8[1] = 0;
      local_a0 = puVar4[6];
      _Src = local_c8;
      local_90 = *(undefined4 *)(puVar4 + 4);
      local_b8 = puVar4[1];
      local_b0 = puVar4[2];
    }
LAB_14001f991:
    memmove(param_5,_Src,(ulonglong)uVar5);
  }
  else {
    if (param_3 == 0x3f) {
      memset(local_c8,0,0x78);
      local_80 = puVar4[0xc];
      uStack_78 = puVar4[0xd];
      local_8c = (uint)*(ushort *)(param_1 + 0x50);
      local_c8[0] = local_8c + uVar5;
      local_98 = puVar4[5];
      local_a8 = puVar4[3];
      local_c0 = *puVar4;
      local_a0 = puVar4[6];
      local_90 = *(undefined4 *)(puVar4 + 4);
      local_b8 = puVar4[1];
      local_b0 = puVar4[2];
      local_88 = CONCAT44(*(undefined4 *)((longlong)puVar4 + 0x54),*(undefined4 *)(puVar4 + 8));
      uStack_70 = CONCAT71(uStack_70._1_7_,*(char *)(param_1 + 0x78));
      if ('\0' < *(char *)(param_1 + 0x78)) {
        memmove((void *)((longlong)&uStack_70 + 2),(void *)(param_1 + 0x7c),
                (ulonglong)*(uint *)(param_1 + 0x78));
      }
      _Src = local_c8;
      goto LAB_14001f991;
    }
    if (param_3 == 0x4e) {
      uVar1 = *(ushort *)(param_1 + 0x50);
      local_98 = puVar4[5];
      local_a8 = puVar4[3];
      local_c0 = *puVar4;
      local_a0 = puVar4[6];
      local_90 = *(undefined4 *)(puVar4 + 4);
      local_b8 = puVar4[1];
      local_b0 = puVar4[2];
      local_80 = puVar4[9];
      local_88 = CONCAT44(*(undefined4 *)((longlong)puVar4 + 0x54),*(undefined4 *)(puVar4 + 8));
LAB_14002011e:
      local_8c = (uint)uVar1;
      local_c8[0] = local_8c + uVar5;
      uStack_78 = 0;
      local_c8[1] = 0;
      _Src = local_c8;
      goto LAB_14001f991;
    }
    if (param_3 == 0x4f) {
      memset(local_c8,0,0x70);
      local_8c = (uint)*(ushort *)(param_1 + 0x50);
      local_c8[0] = local_8c + uVar5;
      local_98 = puVar4[5];
      local_a8 = puVar4[3];
      local_c0 = *puVar4;
      local_a0 = puVar4[6];
      local_90 = *(undefined4 *)(puVar4 + 4);
      local_b8 = puVar4[1];
      local_b0 = puVar4[2];
      local_80 = puVar4[9];
      local_88 = CONCAT44(*(undefined4 *)((longlong)puVar4 + 0x54),*(undefined4 *)(puVar4 + 8));
      uStack_78 = CONCAT71(uStack_78._1_7_,*(char *)(param_1 + 0x78));
      if ('\0' < *(char *)(param_1 + 0x78)) {
        _Dst = (void *)((longlong)&uStack_78 + 2);
LAB_140020199:
        memmove(_Dst,(void *)(param_1 + 0x7c),(ulonglong)*(uint *)(param_1 + 0x78));
      }
LAB_1400201a6:
      _Src = local_c8;
      goto LAB_14001f991;
    }
    if (param_3 == 0x50) {
      uStack_78 = puVar4[0xc];
      uStack_70 = puVar4[0xd];
      _Src = local_c8;
      local_c8[1] = 0;
      local_68 = 0;
      local_8c = (uint)*(ushort *)(param_1 + 0x50);
      local_c8[0] = local_8c + uVar5;
      local_98 = puVar4[5];
      local_a8 = puVar4[3];
      local_c0 = *puVar4;
      local_a0 = puVar4[6];
      local_90 = *(undefined4 *)(puVar4 + 4);
      local_b8 = puVar4[1];
      local_b0 = puVar4[2];
      local_80 = puVar4[9];
      local_88 = CONCAT44(*(undefined4 *)((longlong)puVar4 + 0x54),*(undefined4 *)(puVar4 + 8));
      goto LAB_14001f991;
    }
    if (param_3 == 0x51) {
      memset(local_c8,0,0x80);
      uStack_78 = puVar4[0xc];
      uStack_70 = puVar4[0xd];
      local_8c = (uint)*(ushort *)(param_1 + 0x50);
      local_c8[0] = local_8c + uVar5;
      local_98 = puVar4[5];
      local_a8 = puVar4[3];
      local_c0 = *puVar4;
      local_a0 = puVar4[6];
      local_90 = *(undefined4 *)(puVar4 + 4);
      local_b8 = puVar4[1];
      local_b0 = puVar4[2];
      local_80 = puVar4[9];
      local_88 = CONCAT44(*(undefined4 *)((longlong)puVar4 + 0x54),*(undefined4 *)(puVar4 + 8));
      local_68 = CONCAT71(local_68._1_7_,*(char *)(param_1 + 0x78));
      if ('\0' < *(char *)(param_1 + 0x78)) {
        memmove((void *)((longlong)&local_68 + 2),(void *)(param_1 + 0x7c),
                (ulonglong)*(uint *)(param_1 + 0x78));
      }
      _Src = local_c8;
      goto LAB_14001f991;
    }
LAB_1400202d0:
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0xc,0x1a,
                          &WPP_4bfd87d54ffb3323a752b550f6ae0533_Traceguids,
                          "onecore\\base\\fs\\wci\\bindflt\\filter\\dirctrl.c",0x38,(char)param_3);
    }
  }
  *param_6 = uVar5;
  uVar6 = (uint)*(ushort *)(param_1 + 0x50);
  if (param_4 < uVar5 + uVar6) {
    iVar3 = -0x7ffffffb;
    uVar6 = param_4 - uVar5;
  }
  memmove((void *)((ulonglong)uVar5 + (longlong)param_5),*(void **)(param_1 + 0x58),(ulonglong)uVar6
         );
  *param_6 = *param_6 + uVar6;
LAB_14001f9ce:
  ExFreePoolWithTag(puVar4,0x65644642);
  return iVar3;
}



===== BfWalkContainerRootId @ 1400204b4 =====

undefined8 BfWalkContainerRootId(longlong param_1,short *param_2)

{
  longlong lVar1;
  ushort uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  ushort uVar5;
  undefined1 uVar6;
  short sVar7;
  ushort uVar8;
  
  lVar1 = param_1 + 6;
  sVar7 = 0;
  uVar8 = *(ushort *)(param_1 + 4) >> 1;
  uVar6 = 0;
  if (*param_2 == 0) {
    uVar5 = *(ushort *)(param_1 + 2) >> 1;
    uVar2 = uVar5 + 1;
    if (*(short *)(lVar1 + (ulonglong)uVar5 * 2) != 0x5c) {
      uVar2 = uVar5;
    }
    uVar3 = (ulonglong)uVar2;
    *(ulonglong *)(param_2 + 4) = lVar1 + uVar3 * 2;
  }
  else {
    for (uVar2 = (ushort)(*(longlong *)(param_2 + 4) - lVar1 >> 1); uVar2 < uVar8; uVar2 = uVar2 + 1
        ) {
      if (*(short *)(lVar1 + (ulonglong)uVar2 * 2) == 0x5c) goto LAB_14002052e;
    }
    if (uVar2 == uVar8) {
      lVar1 = 0;
      goto LAB_14002055a;
    }
LAB_14002052e:
    uVar3 = (ulonglong)(ushort)(uVar2 + 1);
  }
  uVar4 = uVar3;
  while (uVar2 = (ushort)uVar4, uVar2 < uVar8) {
    if (*(short *)(lVar1 + uVar4 * 2) == 0x5c) {
      uVar6 = 1;
      break;
    }
    uVar4 = (ulonglong)(ushort)(uVar2 + 1);
  }
  lVar1 = lVar1 + uVar3 * 2;
  sVar7 = (uVar2 - (short)uVar3) * 2;
LAB_14002055a:
  *(longlong *)(param_2 + 4) = lVar1;
  param_2[1] = sVar7;
  *param_2 = sVar7;
  return CONCAT71((int7)((ulonglong)lVar1 >> 8),uVar6);
}



===== BfTargetEntryExistsInMappingInformation @ 140020580 =====

undefined1 BfTargetEntryExistsInMappingInformation(longlong param_1,longlong param_2)

{
  int iVar1;
  undefined8 *puVar2;
  
  puVar2 = *(undefined8 **)(param_2 + 0x40);
  while( true ) {
    if (puVar2 == (undefined8 *)(param_2 + 0x40)) {
      return 0;
    }
    if ((puVar2[2] == *(longlong *)(param_1 + 0x10)) &&
       (iVar1 = RtlCompareUnicodeString(puVar2 + 5,param_1 + 0x28,1), iVar1 == 0)) break;
    puVar2 = (undefined8 *)*puVar2;
  }
  return 1;
}



===== BfpInsertTargetEntryIntoMappingInformation @ 1400205f4 =====

ulonglong BfpInsertTargetEntryIntoMappingInformation
                    (longlong param_1,longlong *param_2,longlong param_3)

{
  longlong *plVar1;
  longlong lVar2;
  code *pcVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined2 uVar6;
  char local_res8 [8];
  undefined1 uVar7;
  
  uVar5 = 0;
  if (param_1 != *(longlong *)param_2[2]) {
    local_res8[0] = '\0';
    uVar4 = FltIsIoRedirectionAllowed(param_1,*(longlong *)param_2[2],local_res8);
    uVar5 = (ulonglong)uVar4;
    if ((int)uVar4 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return uVar5;
      }
      uVar6 = 0xd;
      uVar7 = 0x56;
LAB_1400206b0:
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,8,uVar6,
                          &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                          "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",uVar7,(char)uVar4);
      return uVar5;
    }
    if (local_res8[0] == '\0') {
      uVar4 = FltAdjustDeviceStackSizeForIoRedirection(param_1,*(undefined8 *)param_2[2],0);
      uVar5 = (ulonglong)uVar4;
      if ((int)uVar4 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return uVar5;
        }
        uVar6 = 0xe;
        uVar7 = 99;
        goto LAB_1400206b0;
      }
    }
  }
  LOCK();
  *(int *)(param_2[2] + 0x24) = *(int *)(param_2[2] + 0x24) + 1;
  UNLOCK();
  plVar1 = (longlong *)(param_3 + 0x40);
  lVar2 = *plVar1;
  if (*(longlong **)(lVar2 + 8) == plVar1) {
    *param_2 = lVar2;
    param_2[1] = (longlong)plVar1;
    *(longlong **)(lVar2 + 8) = param_2;
    *plVar1 = (longlong)param_2;
    return uVar5;
  }
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  pcVar3 = (code *)swi(3);
  uVar5 = (*pcVar3)();
  return uVar5;
}



===== BfpGeneratePreCreateOpenedName @ 140020740 =====

ulonglong BfpGeneratePreCreateOpenedName
                    (longlong param_1,longlong param_2,longlong param_3,uint param_4,short *param_5)

{
  uint uVar1;
  longlong lVar2;
  ulonglong uVar3;
  longlong lVar4;
  undefined2 uVar5;
  longlong local_res10;
  undefined1 uVar6;
  longlong local_38;
  longlong local_30;
  
  local_30 = 0;
  local_res10 = 0;
  lVar4 = 0;
  if (*(longlong *)(param_2 + 0x40) == 0) {
    local_res10 = 0;
    if ((param_3 == 0) ||
       (((uVar1 = FltGetFileNameInformation(param_3,param_4 & 0xff00ff02 | 2,&local_res10),
         -1 < (int)uVar1 && (*(short *)(local_res10 + 8) == 0)) &&
        (*(short *)(local_res10 + 0x18) != 0)))) {
      uVar3 = 0xc000000d;
      uVar1 = 0xc000000d;
LAB_140020891:
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar5 = 0x24;
        uVar6 = 0xb3;
LAB_1400208ac:
        WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,9,uVar5,
                            &WPP_c7f51acdbd3738713a5b9ea834ad885a_Traceguids,
                            "onecore\\base\\fs\\wci\\bindflt\\filter\\namesup.c",uVar6,(char)uVar1);
      }
    }
    else {
      uVar3 = (ulonglong)uVar1;
      if ((int)uVar1 < 0) goto LAB_140020891;
      uVar1 = FltCheckAndGrowNameControl(param_5,*(undefined2 *)(local_res10 + 8));
      uVar3 = (ulonglong)uVar1;
      if ((int)uVar1 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14002082e;
        uVar5 = 0x25;
        uVar6 = 0xbb;
        goto LAB_1400208ac;
      }
      RtlCopyUnicodeString(param_5,local_res10 + 8);
    }
LAB_14002082e:
    if (local_res10 != 0) {
      FltReleaseFileNameInformation();
    }
    if ((int)uVar3 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return uVar3;
      }
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,9,10,
                          &WPP_c7f51acdbd3738713a5b9ea834ad885a_Traceguids,
                          "onecore\\base\\fs\\wci\\bindflt\\filter\\namesup.c",0x8b,(char)uVar3);
      return uVar3;
    }
LAB_140020847:
    uVar3 = 0;
  }
  else {
    uVar1 = BfGetContextsForFileObject(*(longlong *)(param_2 + 0x40),param_1,&local_30,&local_res10)
    ;
    lVar4 = local_res10;
    uVar3 = (ulonglong)uVar1;
    if ((int)uVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,9,0xb,
                            &WPP_c7f51acdbd3738713a5b9ea834ad885a_Traceguids,
                            "onecore\\base\\fs\\wci\\bindflt\\filter\\namesup.c",0x9b,(char)uVar1);
      }
      lVar4 = local_res10;
    }
    else {
      if (local_res10 == 0) {
        uVar1 = BfpPassthroughNameQuery(param_3,0,0,param_4 & 0xff00ff02 | 2,param_5);
        uVar3 = (ulonglong)uVar1;
        if ((int)uVar1 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,9,0xc,
                                &WPP_c7f51acdbd3738713a5b9ea834ad885a_Traceguids,
                                "onecore\\base\\fs\\wci\\bindflt\\filter\\namesup.c",0xb9,
                                (char)uVar1);
          }
          goto LAB_140020853;
        }
        goto LAB_140020847;
      }
      local_res10 = 0;
      local_38 = 0;
      uVar3 = BfMapShadowFileObjectToReal
                        (param_1,*(longlong *)(param_2 + 0x40),lVar4,&local_res10,&local_38,
                         (undefined8 *)0x0);
      if ((char)uVar3 == '\0') {
        lVar2 = *(longlong *)(param_2 + 0x40);
      }
      else {
        lVar2 = local_38;
        param_1 = local_res10;
      }
      uVar3 = BfpGeneratePostCreateName
                        (lVar2,param_1,param_4 & 0xff00ff02 | 2,lVar4,param_1,param_5);
      uVar1 = (uint)uVar3;
      uVar3 = uVar3 & 0xffffffff;
      if ((int)uVar1 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar5 = 0xd;
          uVar6 = 0xdc;
          goto LAB_140020b11;
        }
      }
      else {
        if (*(ushort *)(param_2 + 0x58) < 2) goto LAB_140020847;
        uVar1 = FltCheckAndGrowNameControl(param_5,*(ushort *)(param_2 + 0x58) + 2 + *param_5);
        uVar3 = (ulonglong)uVar1;
        if ((int)uVar1 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar5 = 0xe;
            uVar6 = 0xf0;
LAB_140020b11:
            WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,9,uVar5,
                                &WPP_c7f51acdbd3738713a5b9ea834ad885a_Traceguids,
                                "onecore\\base\\fs\\wci\\bindflt\\filter\\namesup.c",uVar6,
                                (char)uVar1);
          }
        }
        else {
          if (((**(short **)(param_2 + 0x60) == 0x5c) ||
              (uVar1 = RtlAppendUnicodeToString(param_5,L"\\"), -1 < (int)uVar1)) &&
             (uVar1 = RtlAppendUnicodeStringToString(param_5,param_2 + 0x58), -1 < (int)uVar1))
          goto LAB_140020847;
          uVar3 = (ulonglong)uVar1;
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar5 = 0xf;
            uVar6 = 0;
            goto LAB_140020b11;
          }
        }
      }
    }
  }
  if (lVar4 != 0) {
    FltReleaseContext(lVar4);
  }
LAB_140020853:
  if (local_30 != 0) {
    FltReleaseContext();
  }
  return uVar3;
}



===== BfGenerateFileNameCallback @ 140020c20 =====

ulonglong BfGenerateFileNameCallback
                    (longlong *param_1,longlong param_2,longlong param_3,uint param_4,
                    undefined1 *param_5,short *param_6)

{
  uint uVar1;
  int iVar2;
  undefined8 *puVar3;
  ulonglong uVar4;
  longlong *plVar5;
  longlong *plVar6;
  uint uVar7;
  undefined2 uVar8;
  longlong lVar9;
  longlong *plVar10;
  undefined8 local_res10;
  undefined1 uVar11;
  undefined8 local_78;
  longlong *local_70;
  undefined8 *local_68;
  longlong local_60;
  longlong *local_58;
  longlong local_50;
  ulonglong local_48;
  longlong lStack_40;
  
  local_50 = *(longlong *)(param_2 + 0x18);
  local_res10 = CONCAT44(local_res10._4_4_,param_4) & 0xffffffff000000ff;
  local_60 = 0;
  plVar10 = (longlong *)0x0;
  local_68 = (undefined8 *)0x0;
  local_70 = (longlong *)0x0;
  local_78 = (longlong *)0x0;
  local_58 = (longlong *)0x0;
  local_48 = 0;
  lStack_40 = 0;
  uVar1 = FltGetInstanceContext(0,&local_68);
  uVar4 = (ulonglong)uVar1;
  if ((int)uVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140020f11;
    uVar8 = 0x26;
    uVar11 = 0x1e;
    goto LAB_140021460;
  }
  puVar3 = BfGetMappingContexts(param_2,(longlong)local_68,param_3,&local_70,&local_78,&local_58);
  plVar6 = local_70;
  uVar1 = (uint)puVar3;
  uVar4 = (ulonglong)puVar3 & 0xffffffff;
  if ((int)uVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140020f11;
    uVar8 = 0x27;
    uVar11 = 0x26;
    uVar7 = 5;
LAB_140021466:
    WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar7,uVar8,
                        &WPP_c7f51acdbd3738713a5b9ea834ad885a_Traceguids,
                        "onecore\\base\\fs\\wci\\bindflt\\filter\\namesup.c",uVar11,(char)uVar1);
  }
  else {
    if (local_70 == (longlong *)0x0) {
LAB_140020ced:
      plVar6 = local_78;
      if (local_78 != (longlong *)0x0) {
        FltAcquireResourceShared(local_78 + 2);
        plVar5 = plVar6 + 2;
        if ((longlong *)*plVar6 != plVar6) goto LAB_140020fea;
        FltReleaseResource();
      }
      plVar6 = local_58;
      if (local_58 != (longlong *)0x0) {
        FltAcquireResourceShared(local_58 + 2);
        if ((longlong *)*plVar6 != plVar6) {
          FltReleaseResource();
          goto LAB_140020d30;
        }
        FltReleaseResource(plVar6 + 2);
      }
LAB_140020e57:
      uVar1 = param_4 & 0xfe00ff00 | (uint)local_res10;
      local_res10 = 0;
      if (param_3 == 0) {
        uVar1 = FltGetFileNameInformationUnsafe(param_2,param_1,uVar1,&local_res10);
      }
      else {
        uVar1 = FltGetFileNameInformation(param_3,uVar1,&local_res10);
      }
      if ((((int)uVar1 < 0) || (*(short *)(local_res10 + 8) != 0)) ||
         (*(short *)(local_res10 + 0x18) == 0)) {
        uVar4 = (ulonglong)uVar1;
        if ((int)uVar1 < 0) goto LAB_140021002;
        uVar1 = FltCheckAndGrowNameControl(param_6,*(undefined2 *)(local_res10 + 8));
        uVar4 = (ulonglong)uVar1;
        if ((int)uVar1 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_140020eed;
          uVar8 = 0x25;
          uVar11 = 0xbb;
          goto LAB_140021021;
        }
        RtlCopyUnicodeString(param_6,local_res10 + 8);
      }
      else {
        uVar4 = 0xc000000d;
        uVar1 = 0xc000000d;
LAB_140021002:
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar8 = 0x24;
          uVar11 = 0xb3;
LAB_140021021:
          WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,9,uVar8,
                              &WPP_c7f51acdbd3738713a5b9ea834ad885a_Traceguids,
                              "onecore\\base\\fs\\wci\\bindflt\\filter\\namesup.c",uVar11,
                              (char)uVar1);
        }
      }
LAB_140020eed:
      if (local_res10 != 0) {
        FltReleaseFileNameInformation();
      }
      uVar1 = (uint)uVar4;
      if ((int)uVar1 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140020f11;
        uVar8 = 0x28;
        uVar11 = 0x39;
LAB_140021460:
        uVar7 = 9;
        goto LAB_140021466;
      }
    }
    else {
      FltAcquireResourceShared(local_70 + 2);
      plVar5 = plVar6 + 2;
      if ((longlong *)*plVar6 == plVar6) {
        FltReleaseResource(plVar5);
        goto LAB_140020ced;
      }
LAB_140020fea:
      FltReleaseResource(plVar5);
LAB_140020d30:
      uVar1 = *(uint *)(param_2 + 0x50);
      if ((uVar1 >> 0x16 & 1) != 0) goto LAB_140020e57;
      if (local_50 == 0) {
        if (param_3 == 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,9,0x29,
                               &WPP_c7f51acdbd3738713a5b9ea834ad885a_Traceguids,
                               "onecore\\base\\fs\\wci\\bindflt\\filter\\namesup.c",0x58);
          }
LAB_1400215ee:
          uVar4 = 0xc000000d;
          goto LAB_140020f11;
        }
        if ((uint)local_res10 != 1) {
          if ((uint)local_res10 != 2) goto LAB_1400215ee;
          uVar4 = BfpGeneratePreCreateOpenedName
                            ((longlong)param_1,param_2,param_3,param_4 & 0xfe00ff00 | 0x2000000,
                             param_6);
          uVar1 = (uint)uVar4;
          uVar4 = uVar4 & 0xffffffff;
          if ((int)uVar1 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
            goto LAB_140020f11;
            uVar8 = 0x2a;
            uVar11 = 0x70;
            goto LAB_140021460;
          }
          goto LAB_140020f06;
        }
        uVar4 = BfpGeneratePreCreateNormalizedName
                          ((longlong)param_1,param_2,param_3,param_4 & 0xfe00ff00 | 0x2000000,
                           (longlong)local_68,param_6);
        uVar1 = (uint)uVar4;
        uVar4 = uVar4 & 0xffffffff;
        if (-1 < (int)uVar1) goto LAB_140020f06;
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140020f11;
        uVar8 = 0x2b;
        uVar11 = 0x82;
        goto LAB_140021460;
      }
      local_70 = (longlong *)0x0;
      local_78 = (longlong *)
                 (CONCAT44(local_78._4_4_,CONCAT31((uint3)(uVar1 >> 0x19),~(byte)(uVar1 >> 0x11))) &
                 0xffffffffffffff01);
      uVar1 = FltGetStreamHandleContext(param_1,param_2,&local_70);
      uVar4 = (ulonglong)uVar1;
      if (uVar1 == 0xc0000225) {
        plVar10 = local_70;
LAB_140020da8:
        local_70 = (longlong *)0x0;
        uVar4 = 0;
      }
      else {
        if (-1 < (int)uVar1) {
          plVar10 = local_70;
          if ((*(uint *)(local_70 + 10) & 1) == 0) {
            FltReleaseContext();
            plVar10 = (longlong *)0x0;
          }
          goto LAB_140020da8;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,7,0x19,
                              &WPP_ab4056511ca038337f1519c30a6fffbb_Traceguids,
                              "onecore\\base\\fs\\wci\\bindflt\\filter\\context.c",0xad,(char)uVar1)
          ;
        }
      }
      if (local_70 != (longlong *)0x0) {
        FltReleaseContext();
      }
      uVar1 = (uint)uVar4;
      if ((int)uVar1 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140020f11;
        uVar8 = 0x2c;
        uVar11 = 0xac;
        goto LAB_140021460;
      }
      if (local_68 == (undefined8 *)0x0) {
        local_58 = param_1;
      }
      else {
        local_58 = (longlong *)*local_68;
      }
      if (plVar10 == (longlong *)0x0) {
        uVar1 = BfpPassthroughNameQuery
                          (param_3,param_2,local_58,(uint)local_res10 | param_4 & 0xfe00ff00,param_6
                          );
        uVar4 = (ulonglong)uVar1;
        if (-1 < (int)uVar1) goto LAB_140020f06;
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140020f11;
        uVar8 = 0x2d;
        uVar11 = 0xcf;
        goto LAB_140021460;
      }
      if (((*(short **)(param_2 + 0x18) == (short *)0x0) || (**(short **)(param_2 + 0x18) != 0x6431)
          ) || ((*(byte *)(plVar10 + 10) & 1) == 0)) {
        plVar6 = param_1;
        lVar9 = param_2;
      }
      else {
        lVar9 = *(longlong *)(*(longlong *)(param_2 + 0x20) + 8);
        plVar6 = *(longlong **)(*(longlong *)(param_2 + 0x20) + 0x10);
      }
      if ((uint)local_res10 != 3) {
        if ((uint)local_res10 == 1) {
          uVar4 = BfpGeneratePostCreateName
                            (lVar9,plVar6,param_4 & 0xfe00ff00 | 1,(longlong)plVar10,
                             (longlong)param_1,param_6);
          uVar1 = (uint)uVar4;
          uVar4 = uVar4 & 0xffffffff;
          if ((int)uVar1 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
            goto LAB_140020f11;
            uVar8 = 0x2f;
            uVar11 = 2;
            goto LAB_140021460;
          }
        }
        else {
          if ((uint)local_res10 != 2) goto LAB_1400215ee;
          uVar4 = BfpGeneratePostCreateName
                            (lVar9,plVar6,param_4 & 0xfe00ff00 | 2,(longlong)plVar10,
                             (longlong)param_1,param_6);
          uVar1 = (uint)uVar4;
          uVar4 = uVar4 & 0xffffffff;
          if ((int)uVar1 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
            goto LAB_140020f11;
            uVar8 = 0x2e;
            uVar11 = 0xf0;
            goto LAB_140021460;
          }
        }
        goto LAB_140020f06;
      }
      local_60 = 0;
      if (lVar9 == 0) {
LAB_14002136c:
        uVar4 = 0xc000000d;
        uVar1 = 0xc000000d;
LAB_140021373:
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140020f11;
        uVar8 = 0x30;
        uVar11 = 0x1f;
        goto LAB_140021460;
      }
      uVar1 = FltGetFileNameInformationUnsafe(lVar9,plVar6,param_4 & 0xfe00ff00 | 1,&local_60);
      if (((-1 < (int)uVar1) && (*(short *)(local_60 + 8) == 0)) &&
         (*(short *)(local_60 + 0x18) != 0)) goto LAB_14002136c;
      uVar4 = (ulonglong)uVar1;
      if ((int)uVar1 < 0) goto LAB_140021373;
      uVar4 = BfFormatPathFromFileNameInfo(local_60,'\0',(undefined4 *)&local_48);
      uVar1 = (uint)uVar4;
      uVar4 = uVar4 & 0xffffffff;
      if ((int)uVar1 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140020f11;
        uVar8 = 0x31;
        uVar11 = 0x2b;
        goto LAB_140021460;
      }
      iVar2 = RtlCompareUnicodeString(&local_48,plVar10[6] + 0x28,(ulonglong)local_78 & 0xff);
      if (iVar2 == 0) {
        if (*(short *)(plVar10[5] + 0x20) == 0) {
          uVar4 = 0xc0000034;
          goto LAB_140020f11;
        }
        uVar1 = FltCheckAndGrowNameControl(param_6);
        uVar4 = (ulonglong)uVar1;
        if ((int)uVar1 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_140020f11;
          uVar8 = 0x32;
          uVar11 = 0x47;
          goto LAB_140021460;
        }
        RtlCopyUnicodeString(param_6,plVar10[5] + 0x20);
      }
      else {
        uVar1 = BfpPassthroughNameQuery(param_3,param_2,local_58,param_4 & 0xfe00ff00 | 3,param_6);
        uVar4 = (ulonglong)uVar1;
        if ((int)uVar1 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_140020f11;
          uVar8 = 0x33;
          uVar11 = 0x5d;
          goto LAB_140021460;
        }
      }
    }
LAB_140020f06:
    uVar4 = 0;
    *param_5 = 1;
  }
LAB_140020f11:
  if (lStack_40 != 0) {
    ExFreePoolWithTag(lStack_40,0x74734642);
    lStack_40 = 0;
  }
  local_48 = local_48 & 0xffffffff00000000;
  if (plVar10 != (longlong *)0x0) {
    FltReleaseContext(plVar10);
  }
  if (local_68 != (undefined8 *)0x0) {
    FltReleaseContext();
  }
  if (local_60 != 0) {
    FltReleaseFileNameInformation();
  }
  return uVar4;
}



===== BfpGeneratePostCreateName @ 140021600 =====

ulonglong BfpGeneratePostCreateName
                    (longlong param_1,undefined8 param_2,uint param_3,longlong param_4,
                    longlong param_5,undefined8 param_6)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  ulonglong local_18;
  longlong lStack_10;
  
  local_18 = 0;
  lStack_10 = 0;
  uVar2 = BfGeneratePostCreateName(param_1,param_2,param_3,param_4,param_5,(short *)&local_18);
  uVar3 = uVar2 & 0xffffffff;
  if (-1 < (int)uVar2) {
    uVar1 = FltCheckAndGrowNameControl(param_6,local_18 & 0xffff);
    uVar3 = (ulonglong)uVar1;
    if ((int)uVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,9,0x23,
                            &WPP_c7f51acdbd3738713a5b9ea834ad885a_Traceguids,
                            "onecore\\base\\fs\\wci\\bindflt\\filter\\namesup.c",0x6f,(char)uVar1);
      }
    }
    else {
      RtlCopyUnicodeString(param_6,&local_18);
    }
  }
  if (lStack_10 != 0) {
    ExFreePoolWithTag(lStack_10,0x74734642);
  }
  return uVar3;
}



===== BfpPassthroughNameQuery @ 1400216f0 =====

int BfpPassthroughNameQuery
              (longlong param_1,longlong param_2,undefined8 param_3,undefined4 param_4,
              undefined8 param_5)

{
  int iVar1;
  undefined2 uVar2;
  longlong local_res8;
  undefined1 uVar3;
  
  local_res8 = 0;
  if (param_1 == 0) {
    if (param_2 != 0) {
      iVar1 = FltGetFileNameInformationUnsafe(param_2,param_3,param_4,&local_res8);
      goto LAB_14002172e;
    }
LAB_1400217ce:
    iVar1 = -0x3ffffff3;
LAB_1400217d5:
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14002178b;
    uVar2 = 0x24;
    uVar3 = 0xb3;
  }
  else {
    iVar1 = FltGetFileNameInformation(param_1,param_4,&local_res8);
LAB_14002172e:
    if (((-1 < iVar1) && (*(short *)(local_res8 + 8) == 0)) && (*(short *)(local_res8 + 0x18) != 0))
    goto LAB_1400217ce;
    if (iVar1 < 0) goto LAB_1400217d5;
    iVar1 = FltCheckAndGrowNameControl(param_5,*(undefined2 *)(local_res8 + 8));
    if (-1 < iVar1) {
      RtlCopyUnicodeString(param_5,local_res8 + 8);
      goto LAB_14002178b;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14002178b;
    uVar2 = 0x25;
    uVar3 = 0xbb;
  }
  WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,9,uVar2,
                      &WPP_c7f51acdbd3738713a5b9ea834ad885a_Traceguids,
                      "onecore\\base\\fs\\wci\\bindflt\\filter\\namesup.c",uVar3,(char)iVar1);
LAB_14002178b:
  if (local_res8 != 0) {
    FltReleaseFileNameInformation();
  }
  return iVar1;
}



===== BfpGeneratePreCreateNormalizedName @ 14002186c =====

ulonglong BfpGeneratePreCreateNormalizedName
                    (longlong param_1,longlong param_2,longlong param_3,uint param_4,
                    longlong param_5,undefined8 param_6)

{
  uint uVar1;
  uint uVar2;
  undefined8 *puVar3;
  ulonglong uVar4;
  longlong lVar5;
  ulonglong uVar6;
  undefined8 ***pppuVar7;
  undefined2 uVar8;
  undefined8 ***pppuVar9;
  undefined8 ****ppppuVar10;
  longlong local_res18;
  undefined4 local_res20 [2];
  wchar_t *pwVar11;
  undefined4 uVar13;
  longlong lVar12;
  longlong **pplVar14;
  undefined1 uVar15;
  undefined1 uVar16;
  undefined4 *puVar17;
  longlong *local_128;
  ulonglong local_120;
  longlong lStack_118;
  longlong local_110;
  ulonglong local_108;
  longlong lStack_100;
  ushort local_f8 [4];
  longlong lStack_f0;
  undefined8 ****local_e8;
  undefined8 ****local_e0;
  longlong *local_d8;
  longlong *local_d0;
  undefined8 ***local_c8;
  longlong local_c0 [6];
  undefined8 local_90;
  undefined8 uStack_88;
  ulonglong *local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  ulonglong uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  
  uVar2 = *(uint *)(param_2 + 0x50);
  local_c0[5] = local_c0[5] & 0xffffffffffff0000;
  local_70 = 0;
  uStack_68 = uStack_68 & 0xffffffff00000000;
  local_e0 = &local_e8;
  local_c0[0] = 0;
  local_110 = 0;
  local_d0 = (longlong *)0x0;
  local_e8 = &local_e8;
  local_d8 = (longlong *)0x0;
  local_128 = (longlong *)0x0;
  lVar5 = 0;
  local_c8 = (undefined8 ***)0x0;
  pppuVar9 = (undefined8 ***)0x0;
  local_res20[0] = 0;
  local_res18 = 0;
  local_120 = 0;
  lStack_118 = 0;
  local_f8[0] = 0;
  local_f8[1] = 0;
  local_f8[2] = 0;
  local_f8[3] = 0;
  lStack_f0 = 0;
  local_c0[1] = 0;
  local_c0[2] = 0;
  local_c0[3] = 0;
  local_c0[4] = 0;
  local_90 = 0;
  uStack_88 = 0;
  local_80 = (ulonglong *)0x0;
  uStack_78 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_108 = 0;
  lStack_100 = 0;
  if (param_3 == 0) {
LAB_140022070:
    uVar6 = 0xc000000d;
    uVar1 = 0xc000000d;
LAB_140022077:
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400220c9;
    uVar15 = (undefined1)uVar1;
    uVar8 = 0x10;
    uVar16 = 0x81;
LAB_140022099:
    uVar2 = 9;
  }
  else {
    uVar1 = FltGetFileNameInformation(param_3,param_4 & 0xff00ff02 | 0x3000002);
    if (((-1 < (int)uVar1) && (*(short *)(local_res18 + 8) == 0)) &&
       (*(short *)(local_res18 + 0x18) != 0)) goto LAB_140022070;
    uVar6 = (ulonglong)uVar1;
    if ((int)uVar1 < 0) goto LAB_140022077;
    pplVar14 = &local_d0;
    puVar3 = BfGetMappingContexts(param_2,param_5,param_3,&local_128,&local_d8,pplVar14);
    uVar6 = (ulonglong)puVar3 & 0xffffffff;
    if (-1 < (int)puVar3) {
      puVar17 = local_res20;
      lVar12 = local_res18;
      puVar3 = (undefined8 *)
               BfCombinedMappingLookup
                         (local_d0,local_d8,local_128,param_1,local_res18,pplVar14,
                          ~(byte)(uVar2 >> 0x11) & 1,(longlong *)&local_e8);
      uVar6 = (ulonglong)puVar3 & 0xffffffff;
      if ((int)puVar3 == -0x3fffffc6) {
        uVar2 = BfpPassthroughNameQuery(param_3,param_2,param_1,param_4 & 0xff00ff01 | 1,param_6);
        uVar6 = (ulonglong)uVar2;
        if ((-1 < (int)uVar2) ||
           ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED))
        goto LAB_1400220c9;
        uVar15 = (undefined1)uVar2;
        uVar8 = 0x12;
        uVar16 = 0xa7;
        goto LAB_140022099;
      }
      if ((int)puVar3 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400220c9;
        uVar8 = 0x13;
        uVar16 = 0xae;
        goto LAB_1400219ca;
      }
      for (ppppuVar10 = local_e8; uVar13 = (undefined4)((ulonglong)lVar12 >> 0x20),
          (undefined8 *****)ppppuVar10 != &local_e8; ppppuVar10 = (undefined8 ****)*ppppuVar10) {
        pppuVar9 = ppppuVar10[4];
        for (pppuVar7 = (undefined8 ***)pppuVar9[8]; pppuVar7 != pppuVar9 + 8;
            pppuVar7 = (undefined8 ***)*pppuVar7) {
          pwVar11 = (wchar_t *)&local_120;
          local_c8 = pppuVar7;
          uVar4 = BfRemapPath(local_res18,(ushort *)(ppppuVar10 + 2),*pppuVar7[2],
                              (ushort *)(pppuVar7 + 5),pwVar11);
          uVar13 = (undefined4)((ulonglong)pwVar11 >> 0x20);
          uVar6 = uVar4 & 0xffffffff;
          if ((int)uVar4 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
            goto LAB_1400220c9;
            uVar15 = (undefined1)uVar4;
            uVar8 = 0x14;
            uVar16 = 0xce;
            goto LAB_140022099;
          }
          local_128 = (longlong *)0x0;
          local_res20[0] = 0;
          uVar2 = FltGetVolumeFromInstance(*pppuVar7[2],&local_128);
          uVar6 = (ulonglong)uVar2;
          if ((int)uVar2 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
            goto LAB_1400220c9;
            uVar15 = (undefined1)uVar2;
            uVar8 = 0x15;
            uVar16 = 0xe3;
            goto LAB_140022099;
          }
          FltGetVolumeName(local_128,0,local_res20);
          FltObjectDereference(local_128);
          BfRemoveFinalComponent((ushort *)&local_120,(ushort)local_res20[0],local_f8);
          local_c0[2] = 0;
          local_c0[1] = 0x28;
          local_c0[3] = 0;
          local_c0[4] = 0;
          local_c0[5] = 1;
          if (((ulonglong)pppuVar9[1] & 4) == 0) {
            local_c0[5] = PsGetHostSilo();
          }
          else {
            local_c0[5] = IoGetSilo();
          }
          uStack_88 = 0;
          local_80 = &local_120;
          local_90 = CONCAT44(local_90._4_4_,0x30);
          puVar17 = (undefined4 *)((ulonglong)puVar17 & 0xffffffff00000000);
          uStack_78 = CONCAT44(uStack_78._4_4_,0x200);
          local_70 = 0;
          uStack_68 = 0;
          lVar12 = CONCAT44(uVar13,0x80);
          uVar2 = FltCreateFileEx2(g_BindFltState,*pppuVar7[2],local_c0,&local_110,lVar12,&local_90,
                                   &local_60,0,puVar17,7,1,0x20,0,0,0,local_c0 + 1);
          uVar6 = (ulonglong)uVar2;
          if ((uVar2 != 0xc0000034) && (uVar2 != 0xc000003a)) {
            if ((int)uVar2 < 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
              goto LAB_1400220c9;
              uVar8 = 0x16;
              uVar15 = 0x1e;
              goto LAB_140021ca4;
            }
            break;
          }
          BfFreeUnicodeString((undefined4 *)&local_120);
        }
      }
      uVar2 = (uint)uVar6;
      if ((int)uVar2 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar8 = 0x17;
          uVar15 = 0x2b;
LAB_140021ca4:
          WPP_RECORDER_SF_sDZd
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,9,uVar8,
                     &WPP_c7f51acdbd3738713a5b9ea834ad885a_Traceguids,
                     "onecore\\base\\fs\\wci\\bindflt\\filter\\namesup.c",uVar15,
                     (wchar_t *)&local_120,(char)uVar2);
        }
        goto LAB_1400220c9;
      }
      FltReleaseFileNameInformation(local_res18);
      pppuVar7 = local_c8;
      local_res18 = 0;
      uVar2 = FltGetFileNameInformationUnsafe
                        (local_110,*local_c8[2],param_4 & 0xff00ff01 | 1,&local_res18);
      uVar6 = (ulonglong)uVar2;
      if ((int)uVar2 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400220c9;
        uVar15 = (undefined1)uVar2;
        uVar8 = 0x18;
        uVar16 = 0x3e;
        goto LAB_140022099;
      }
      lVar5 = ExAllocatePool2(0x100,0x400,0x6d6e4642);
      if (lVar5 == 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,9,0x19,
                             &WPP_c7f51acdbd3738713a5b9ea834ad885a_Traceguids,
                             "onecore\\base\\fs\\wci\\bindflt\\filter\\namesup.c",0x4b);
        }
        uVar6 = 0xc000009a;
        goto LAB_1400220c9;
      }
      uVar2 = FltQueryDirectoryFile
                        (*pppuVar7[2],local_110,lVar5,0x400,CONCAT44(uVar13,0xc),1,local_f8,1,0);
      uVar6 = (ulonglong)uVar2;
      if ((int)uVar2 < 0) {
        if (uVar2 != 0xc000000f) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_1400220c9;
          uVar15 = (undefined1)uVar2;
          uVar8 = 0x1a;
          uVar16 = 0x72;
          goto LAB_140022099;
        }
      }
      else {
        lStack_f0 = lVar5 + 0xc;
        local_f8[1] = *(undefined2 *)(lVar5 + 8);
        local_f8[0] = *(undefined2 *)(lVar5 + 8);
      }
      uVar4 = BfRemapPath(local_res18,(ushort *)(pppuVar7 + 5),param_1,(ushort *)(pppuVar9 + 2),
                          (wchar_t *)&local_108);
      uVar6 = uVar4 & 0xffffffff;
      if ((int)uVar4 == -0x3ffffddb) {
        uVar4 = BfAllocateUnicodeString(*(short *)(local_res18 + 8),(undefined4 *)&local_108);
        uVar6 = uVar4 & 0xffffffff;
        if ((int)uVar4 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_1400220c9;
          uVar15 = (undefined1)uVar4;
          uVar8 = 0x1b;
          uVar16 = 0x95;
        }
        else {
          RtlCopyUnicodeString(&local_108,local_res18 + 8);
LAB_140021f7e:
          uVar2 = FltCheckAndGrowNameControl(param_6,(wchar_t)local_108 + L'\x02' + local_f8[0]);
          uVar6 = (ulonglong)uVar2;
          if ((int)uVar2 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
            goto LAB_1400220c9;
            uVar15 = (undefined1)uVar2;
            uVar8 = 0x1d;
            uVar16 = 0xab;
          }
          else {
            RtlCopyUnicodeString(param_6,&local_108);
            uVar2 = RtlAppendUnicodeToString(param_6,L"\\");
            if (-1 < (int)uVar2) {
              uVar2 = RtlAppendUnicodeStringToString(param_6,local_f8);
              if (-1 < (int)uVar2) {
                uVar6 = 0;
                goto LAB_1400220c9;
              }
            }
            uVar6 = (ulonglong)uVar2;
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
            goto LAB_1400220c9;
            uVar15 = (undefined1)uVar2;
            uVar8 = 0x1e;
            uVar16 = 0xbb;
          }
        }
      }
      else {
        if (-1 < (int)uVar4) goto LAB_140021f7e;
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400220c9;
        uVar15 = (undefined1)uVar4;
        uVar8 = 0x1c;
        uVar16 = 0x9d;
      }
      goto LAB_140022099;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400220c9;
    uVar8 = 0x11;
    uVar16 = 0x89;
LAB_1400219ca:
    uVar15 = SUB81(puVar3,0);
    uVar2 = 5;
  }
  WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar2,uVar8,
                      &WPP_c7f51acdbd3738713a5b9ea834ad885a_Traceguids,
                      "onecore\\base\\fs\\wci\\bindflt\\filter\\namesup.c",uVar16,uVar15);
LAB_1400220c9:
  BfFreeMappingLookupList((longlong *)&local_e8);
  if (lVar5 != 0) {
    ExFreePoolWithTag(lVar5,0x6d6e4642);
  }
  if (local_c0[0] != 0) {
    FltClose();
  }
  if (local_110 != 0) {
    ObfDereferenceObject();
  }
  if (lStack_118 != 0) {
    ExFreePoolWithTag(lStack_118,0x74734642);
    lStack_118 = 0;
  }
  local_120 = local_120 & 0xffffffff00000000;
  if (lStack_100 != 0) {
    ExFreePoolWithTag(lStack_100,0x74734642);
    lStack_100 = 0;
  }
  local_108 = local_108 & 0xffffffff00000000;
  if (local_res18 != 0) {
    FltReleaseFileNameInformation();
  }
  return uVar6;
}



===== BfGetContextsForFileObject @ 140022190 =====

int BfGetContextsForFileObject
              (undefined8 param_1,undefined8 param_2,longlong *param_3,longlong *param_4)

{
  longlong lVar1;
  int iVar2;
  undefined2 uVar3;
  longlong local_res18;
  longlong local_res20;
  undefined1 uVar4;
  
  local_res20 = 0;
  local_res18 = 0;
  if (param_3 != (longlong *)0x0) {
    *param_3 = 0;
  }
  if (param_4 == (longlong *)0x0) {
LAB_140022209:
    if (param_3 != (longlong *)0x0) {
      iVar2 = FltGetInstanceContext(param_2,&local_res20);
      lVar1 = local_res20;
      if (iVar2 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140022225;
        uVar3 = 0x1a;
        uVar4 = 0xc2;
        goto LAB_14002227f;
      }
      local_res20 = 0;
      *param_3 = lVar1;
    }
    lVar1 = local_res18;
    if (param_4 != (longlong *)0x0) {
      local_res18 = 0;
      *param_4 = lVar1;
    }
    iVar2 = 0;
  }
  else {
    *param_4 = 0;
    iVar2 = FltGetStreamHandleContext(param_2,param_1,&local_res18);
    if (iVar2 == -0x3ffffddb) goto LAB_140022209;
    if (-1 < iVar2) {
      if ((*(uint *)(local_res18 + 0x50) & 1) == 0) {
        FltReleaseContext();
        local_res18 = 0;
      }
      goto LAB_140022209;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140022225;
    uVar3 = 0x19;
    uVar4 = 0xad;
LAB_14002227f:
    WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,7,uVar3,
                        &WPP_ab4056511ca038337f1519c30a6fffbb_Traceguids,
                        "onecore\\base\\fs\\wci\\bindflt\\filter\\context.c",uVar4,(char)iVar2);
  }
LAB_140022225:
  if (local_res20 != 0) {
    FltReleaseContext();
  }
  if (local_res18 != 0) {
    FltReleaseContext();
  }
  return iVar2;
}



===== BfSetupEnumerationContexts @ 140022328 =====

int BfSetupEnumerationContexts
              (longlong param_1,longlong param_2,longlong param_3,longlong param_4,longlong param_5,
              uint param_6,longlong param_7)

{
  bool bVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  ulonglong uVar5;
  uint uVar6;
  undefined8 ***pppuVar7;
  undefined2 uVar8;
  undefined8 ***pppuVar9;
  undefined8 ****ppppuVar10;
  wchar_t *pwVar11;
  undefined4 uVar12;
  longlong **pplVar13;
  undefined1 uVar14;
  uint *puVar15;
  uint local_d8 [2];
  ulonglong local_d0;
  longlong lStack_c8;
  longlong *local_c0;
  longlong *local_b8;
  longlong local_b0;
  longlong local_a8;
  undefined8 ****local_a0;
  undefined8 ****local_98;
  longlong *local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  ulonglong *local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  ulonglong uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  
  local_b0 = 0;
  local_98 = &local_a0;
  local_a8 = 0;
  local_a0 = &local_a0;
  iVar2 = 0;
  bVar1 = true;
  local_90 = (longlong *)0x0;
  local_d0 = 0;
  lStack_c8 = 0;
  local_c0 = (longlong *)0x0;
  local_b8 = (longlong *)0x0;
  local_d8[0] = 0;
  if (*(char *)(param_7 + 0x70) == '\0') {
    uVar3 = BfCreateEnumerationContext(param_4,param_5,0,0,param_6,param_7);
    iVar2 = (int)uVar3;
    if (-1 < iVar2) {
      if ((*(uint *)(param_7 + 0x50) & 1) == 0) {
LAB_14002269f:
        *(undefined1 *)(param_7 + 0x70) = 1;
LAB_1400226a3:
        if (!bVar1) goto LAB_1400226ac;
      }
      else {
        if ((param_3 == 0) ||
           (((iVar2 = FltGetFileNameInformationUnsafe(param_3,param_2,0x1000102,&local_b0),
             -1 < iVar2 && (*(short *)(local_b0 + 8) == 0)) && (*(short *)(local_b0 + 0x18) != 0))))
        {
          iVar2 = -0x3ffffff3;
LAB_140022811:
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_140022733;
          uVar8 = 0x20;
          uVar14 = 0x3d;
LAB_140022837:
          uVar6 = 0xc;
        }
        else {
          if (iVar2 < 0) goto LAB_140022811;
          iVar2 = FltGetInstanceContext(param_2,&local_a8);
          if (-1 < iVar2) {
            pplVar13 = &local_90;
            puVar4 = BfGetMappingContexts(param_3,local_a8,param_1,&local_b8,&local_c0,pplVar13);
            iVar2 = (int)puVar4;
            if (iVar2 < 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                uVar8 = 0x22;
                uVar14 = 0x4d;
                goto LAB_1400228a6;
              }
              goto LAB_140022733;
            }
            puVar15 = local_d8;
            uVar5 = BfCombinedMappingLookup
                              (local_90,local_c0,local_b8,param_2,local_b0,pplVar13,
                               ~(byte)(*(uint *)(param_3 + 0x50) >> 0x11) & 1,(longlong *)&local_a0)
            ;
            iVar2 = (int)uVar5;
            if (iVar2 == -0x3fffffc6) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0xc,0x23,
                                   &WPP_4bfd87d54ffb3323a752b550f6ae0533_Traceguids,
                                   "onecore\\base\\fs\\wci\\bindflt\\filter\\dirctrl.c",99);
              }
              goto LAB_140022733;
            }
            if (-1 < iVar2) {
              uVar6 = 0;
              for (ppppuVar10 = local_a0; (undefined8 *****)ppppuVar10 != &local_a0;
                  ppppuVar10 = (undefined8 ****)*ppppuVar10) {
                uVar6 = uVar6 + 1;
                pppuVar9 = ppppuVar10[4] + 8;
                for (pppuVar7 = (undefined8 ***)*pppuVar9;
                    (pppuVar7 != pppuVar9 &&
                    (((local_d8[0] < 2 || (local_d8[0] <= uVar6)) ||
                     ((undefined8 ***)*pppuVar7 != pppuVar9))));
                    pppuVar7 = (undefined8 ***)*pppuVar7) {
                  if (pppuVar7 != *(undefined8 ****)(param_7 + 0x30)) {
                    pwVar11 = (wchar_t *)&local_d0;
                    uVar5 = BfRemapPath(local_b0,(ushort *)(ppppuVar10 + 2),*pppuVar7[2],
                                        (ushort *)(pppuVar7 + 5),pwVar11);
                    uVar12 = (undefined4)((ulonglong)pwVar11 >> 0x20);
                    iVar2 = (int)uVar5;
                    if (iVar2 < 0) {
                      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                        WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0xc,0x25,
                                            &WPP_4bfd87d54ffb3323a752b550f6ae0533_Traceguids,
                                            "onecore\\base\\fs\\wci\\bindflt\\filter\\dirctrl.c",
                                            0x98,(char)uVar5);
                      }
                      goto LAB_1400226a3;
                    }
                    bVar1 = false;
                    local_60 = 0;
                    uStack_58 = uStack_58 & 0xffffffff00000000;
                    uStack_48 = 0;
                    local_c0 = (longlong *)0x0;
                    local_b8 = (longlong *)0x0;
                    local_50 = 0x28;
                    local_80 = 0;
                    uStack_78 = 0;
                    local_30 = 1;
                    local_70 = (ulonglong *)0x0;
                    uStack_68 = 0;
                    local_90 = (longlong *)0x0;
                    uStack_88 = 0;
                    local_40 = 0;
                    uStack_38 = 0;
                    if ((*(uint *)(*(longlong *)(param_7 + 0x28) + 8) & 4) == 0) {
                      local_30 = PsGetHostSilo();
                    }
                    else {
                      local_30 = IoGetSilo(param_3);
                    }
                    local_70 = &local_d0;
                    local_80 = CONCAT44(local_80._4_4_,0x30);
                    puVar15 = (uint *)((ulonglong)puVar15 & 0xffffffff00000000);
                    uStack_78 = 0;
                    uStack_68 = CONCAT44(uStack_68._4_4_,0x200);
                    local_60 = 0;
                    uStack_58 = 0;
                    iVar2 = FltCreateFileEx2(g_BindFltState,*pppuVar7[2],&local_c0,&local_b8,
                                             CONCAT44(uVar12,1),&local_80,&local_90,0,puVar15,1,1,1,
                                             0,0,0,&local_50);
                    if (((iVar2 == -0x3fffffcc) || (iVar2 == -0x3fffffc6)) || (iVar2 == -0x3ffffefd)
                       ) {
                      if (lStack_c8 != 0) {
                        ExFreePoolWithTag(lStack_c8,0x74734642);
                        lStack_c8 = 0;
                      }
                      iVar2 = 0;
                    }
                    else {
                      if (iVar2 < 0) {
                        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                          WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0xc,0x26,
                                              &WPP_4bfd87d54ffb3323a752b550f6ae0533_Traceguids,
                                              "onecore\\base\\fs\\wci\\bindflt\\filter\\dirctrl.c",
                                              0xcd,(char)iVar2);
                        }
                        goto LAB_140022733;
                      }
                      uVar3 = BfCreateEnumerationContext
                                        ((longlong)*pppuVar7[2],(longlong)local_b8,
                                         (longlong)local_c0,1,param_6,param_7);
                      iVar2 = (int)uVar3;
                      if (iVar2 < 0) {
                        FltClose(local_c0);
                        ObfDereferenceObject(local_b8);
                        goto LAB_140022733;
                      }
                      if (lStack_c8 != 0) {
                        ExFreePoolWithTag(lStack_c8,0x74734642);
                        lStack_c8 = 0;
                      }
                    }
                    local_d0 = local_d0 & 0xffffffff00000000;
                  }
                }
              }
              goto LAB_14002269f;
            }
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
            goto LAB_140022733;
            uVar8 = 0x24;
            uVar14 = 0x68;
            goto LAB_140022837;
          }
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_140022733;
          uVar8 = 0x21;
          uVar14 = 0x45;
LAB_1400228a6:
          uVar6 = 5;
        }
        WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar6,uVar8,
                            &WPP_4bfd87d54ffb3323a752b550f6ae0533_Traceguids,
                            "onecore\\base\\fs\\wci\\bindflt\\filter\\dirctrl.c",uVar14,(char)iVar2)
        ;
      }
    }
  }
  else {
    for (puVar4 = *(undefined8 **)(param_7 + 0x60); puVar4 != (undefined8 *)(param_7 + 0x60);
        puVar4 = (undefined8 *)*puVar4) {
      if ((*(int *)(puVar4 + 6) == 0) && (*(uint *)(puVar4 + 7) < param_6)) {
        *(uint *)(puVar4 + 7) = param_6;
      }
    }
  }
LAB_140022733:
  if (lStack_c8 != 0) {
    ExFreePoolWithTag(lStack_c8,0x74734642);
    lStack_c8 = 0;
  }
  local_d0 = local_d0 & 0xffffffff00000000;
LAB_1400226ac:
  if (local_a8 != 0) {
    FltReleaseContext();
  }
  BfFreeMappingLookupList((longlong *)&local_a0);
  if (local_b0 != 0) {
    FltReleaseFileNameInformation();
  }
  if (*(char *)(param_7 + 0x70) == '\0') {
    BfFreeEnumerationContextList((longlong *)(param_7 + 0x60));
  }
  return iVar2;
}



===== BfFreeMappingLookupList @ 140022a00 =====

void BfFreeMappingLookupList(longlong *param_1)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  undefined8 *puVar5;
  undefined1 *puVar6;
  undefined1 auStack_28 [32];
  
  puVar6 = auStack_28;
  while ((longlong *)*param_1 != param_1) {
    plVar1 = (longlong *)param_1[1];
    if (((longlong *)*plVar1 != param_1) ||
       (puVar5 = (undefined8 *)plVar1[1], (longlong *)*puVar5 != plVar1)) {
      pcVar4 = (code *)swi(0x29);
      puVar5 = (undefined8 *)(*pcVar4)(3);
      puVar6 = puVar6 + 8;
    }
    param_1[1] = (longlong)puVar5;
    *puVar5 = param_1;
    lVar2 = plVar1[3];
    if (lVar2 != 0) {
      *(undefined8 *)(puVar6 + -8) = 0x140022a4e;
      ExFreePoolWithTag(lVar2,0x74734642);
      plVar1[3] = 0;
    }
    *(undefined4 *)(plVar1 + 2) = 0;
    plVar3 = (longlong *)plVar1[4];
    LOCK();
    lVar2 = *plVar3;
    *plVar3 = *plVar3 + -1;
    UNLOCK();
    if (lVar2 < 2) {
      if (lVar2 == 1) {
        *(undefined8 *)(puVar6 + -8) = 0x140022aa8;
        BfpDeleteMappingInformation((longlong)plVar3);
      }
      else {
        pcVar4 = (code *)swi(0x29);
        (*pcVar4)(0xe);
        puVar6 = puVar6 + 8;
      }
    }
    *(undefined8 *)(puVar6 + -8) = 0x140022a8b;
    ExFreePoolWithTag(plVar1,0x706d4642);
  }
  return;
}



===== BfCreateEnumerationContext @ 140022ab0 =====

undefined8
BfCreateEnumerationContext
          (longlong param_1,longlong param_2,longlong param_3,undefined1 param_4,undefined4 param_5,
          longlong param_6)

{
  longlong *plVar1;
  code *pcVar2;
  longlong *_Dst;
  longlong lVar3;
  undefined8 uVar4;
  
  _Dst = (longlong *)ExAllocateFromPagedLookasideList(&DAT_14000d4c0);
  if (_Dst != (longlong *)0x0) {
    memset(_Dst,0,0x48);
    lVar3 = ExAllocateFromPagedLookasideList(&DAT_14000d540);
    _Dst[8] = lVar3;
    if (lVar3 != 0) {
      *(undefined4 *)(_Dst + 7) = param_5;
      _Dst[3] = param_3;
      _Dst[4] = param_2;
      _Dst[5] = param_1;
      *(undefined1 *)(_Dst + 2) = param_4;
      _Dst[6] = 0;
      plVar1 = *(longlong **)(param_6 + 0x68);
      if (*plVar1 == param_6 + 0x60) {
        *_Dst = param_6 + 0x60;
        _Dst[1] = (longlong)plVar1;
        *plVar1 = (longlong)_Dst;
        *(longlong **)(param_6 + 0x68) = _Dst;
        return 0;
      }
      pcVar2 = (code *)swi(0x29);
      (*pcVar2)(3);
      pcVar2 = (code *)swi(3);
      uVar4 = (*pcVar2)();
      return uVar4;
    }
    BfDeleteEnumerationContext((longlong)_Dst);
  }
  return 0xc000009a;
}



===== BfFreeEnumerationContextList @ 140022b94 =====

void BfFreeEnumerationContextList(longlong *param_1)

{
  longlong *plVar1;
  undefined8 *puVar2;
  code *pcVar3;
  
  while( true ) {
    if ((longlong *)*param_1 == param_1) {
      return;
    }
    plVar1 = (longlong *)param_1[1];
    if (((longlong *)*plVar1 != param_1) ||
       (puVar2 = (undefined8 *)plVar1[1], (longlong *)*puVar2 != plVar1)) break;
    param_1[1] = (longlong)puVar2;
    *puVar2 = param_1;
    BfDeleteEnumerationContext((longlong)plVar1);
  }
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  return;
}



===== BfContextCleanup @ 140022be0 =====

void BfContextCleanup(longlong *param_1,short param_2)

{
  undefined8 *puVar1;
  ulonglong uVar2;
  code *pcVar3;
  undefined8 *puVar4;
  longlong *plVar5;
  
  if (param_2 == 0x10) {
    if (param_1[9] != 0) {
      ExFreePoolWithTag(param_1[9],0x74734642);
      param_1[9] = 0;
    }
    *(undefined4 *)(param_1 + 8) = 0;
    if ((*(uint *)(param_1 + 10) & 1) != 0) {
      BfCleanupFsContext2(param_1);
    }
    if ((*(uint *)(param_1 + 10) & 2) != 0) {
      puVar4 = (undefined8 *)param_1[0xb];
      if (puVar4 != (undefined8 *)0x0) {
        while( true ) {
          while( true ) {
            while (puVar1 = (undefined8 *)*puVar4, puVar1 != (undefined8 *)0x0) {
              *puVar4 = 0;
              puVar4 = puVar1;
            }
            puVar1 = (undefined8 *)puVar4[1];
            if (puVar1 == (undefined8 *)0x0) break;
            puVar4[1] = 0;
            puVar4 = puVar1;
          }
          uVar2 = puVar4[2];
          BfReturnedWalkContextAvlDeleteFunction((longlong)puVar4);
          if ((undefined8 *)(uVar2 & 0xfffffffffffffffc) == (undefined8 *)0x0) break;
          puVar4 = (undefined8 *)(uVar2 & 0xfffffffffffffffc);
        }
      }
      param_1[0xb] = 0;
      plVar5 = param_1 + 0xc;
      while ((longlong *)*plVar5 != plVar5) {
        puVar4 = (undefined8 *)param_1[0xd];
        if (((longlong *)*puVar4 != plVar5) ||
           (puVar1 = (undefined8 *)puVar4[1], (undefined8 *)*puVar1 != puVar4)) {
          pcVar3 = (code *)swi(0x29);
          (*pcVar3)(3);
          return;
        }
        param_1[0xd] = (longlong)puVar1;
        *puVar1 = plVar5;
        BfDeleteEnumerationContext((longlong)puVar4);
      }
    }
  }
  else {
    if (param_2 == 8) {
      BfCleanupStreamContext(param_1);
      return;
    }
    if (param_2 == 2) {
      if (param_1[2] != 0) {
        BfFreeUnicodeString((undefined4 *)(param_1 + 1));
      }
    }
    else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,7,10,
                          &WPP_ab4056511ca038337f1519c30a6fffbb_Traceguids,
                          "onecore\\base\\fs\\wci\\bindflt\\filter\\context.c",0xa7,(char)param_2);
    }
  }
  return;
}



===== BfReturnedWalkContextAvlDeleteFunction @ 140022d54 =====

void BfReturnedWalkContextAvlDeleteFunction(longlong param_1)

{
  BfDereferenceMappingListEntry(param_1 + -0x10);
  return;
}



===== BfDeleteEnumerationContext @ 140022d70 =====

void BfDeleteEnumerationContext(longlong param_1)

{
  if ((*(char *)(param_1 + 0x10) != '\0') && (*(longlong *)(param_1 + 0x18) != 0)) {
    FltClose();
    if (*(longlong *)(param_1 + 0x20) != 0) {
      ObfDereferenceObject();
    }
  }
  if (*(longlong *)(param_1 + 0x40) != 0) {
    ExFreeToPagedLookasideList(&DAT_14000d540);
  }
  ExFreeToPagedLookasideList(&DAT_14000d4c0,param_1);
  return;
}



===== BfCleanupFsContext2 @ 140022dec =====

void BfCleanupFsContext2(longlong *param_1)

{
  if (*param_1 != 0) {
    FltClose();
  }
  if (param_1[1] != 0) {
    ObfDereferenceObject();
  }
  if (param_1[2] != 0) {
    FltObjectDereference();
  }
  BfReleaseMappingInformation((longlong *)param_1[5]);
  FltReleaseContext(param_1[7]);
  return;
}



===== BfDereferenceMappingListEntry @ 140022e60 =====

void BfDereferenceMappingListEntry(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  code *pcVar3;
  
  LOCK();
  plVar1 = (longlong *)(param_1 + 0x40);
  lVar2 = *plVar1;
  *plVar1 = *plVar1 + -1;
  UNLOCK();
  if (lVar2 < 2) {
    if (lVar2 != 1) {
      pcVar3 = (code *)swi(0x29);
      (*pcVar3)(0xe);
      return;
    }
    if (*(longlong *)(param_1 + 0x58) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_1 + 0x58),0x74734642);
      *(undefined8 *)(param_1 + 0x58) = 0;
    }
    *(undefined4 *)(param_1 + 0x50) = 0;
    if (*(longlong *)(param_1 + 0x68) != 0) {
      ObfDereferenceObject();
    }
    if (*(longlong *)(param_1 + 0x70) != 0) {
      FltClose();
    }
    ExFreeToPagedLookasideList(&DAT_14000d440,param_1);
  }
  return;
}



===== BfCleanupStreamContext @ 140022f10 =====

void BfCleanupStreamContext(undefined8 *param_1)

{
  undefined8 *puVar1;
  longlong lVar2;
  undefined8 *puVar3;
  ulonglong uVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  
  lVar2 = param_1[0xe];
  if (lVar2 != 0) {
    FsRtlTeardownPerStreamContexts(lVar2);
    ExFreeToNPagedLookasideList(&DAT_14000d3c0,*(undefined8 *)(lVar2 + 0x78));
    ExFreeToPagedLookasideList(&DAT_14000d340,lVar2);
  }
  puVar1 = param_1 + 1;
  FltAcquireResourceExclusive(puVar1);
  puVar6 = (undefined8 *)*param_1;
  if (puVar6 != (undefined8 *)0x0) {
    do {
      while ((undefined8 *)*puVar6 != (undefined8 *)0x0) {
        puVar5 = puVar6;
        puVar3 = (undefined8 *)*puVar6;
LAB_140022fe0:
        puVar6 = puVar3;
        *puVar5 = 0;
      }
      puVar3 = (undefined8 *)puVar6[1];
      puVar5 = puVar6 + 1;
      if (puVar3 != (undefined8 *)0x0) goto LAB_140022fe0;
      uVar4 = puVar6[2];
      BfCachedWalkContextAvlDeleteFunction((longlong)puVar6);
      puVar6 = (undefined8 *)(uVar4 & 0xfffffffffffffffc);
    } while (puVar6 != (undefined8 *)0x0);
  }
  *param_1 = 0;
  FltReleaseResource(puVar1);
  ExDeleteResourceLite(puVar1);
  return;
}



===== BfCachedWalkContextAvlDeleteFunction @ 140022ff0 =====

void BfCachedWalkContextAvlDeleteFunction(longlong param_1)

{
  BfDereferenceMappingListEntry(param_1 + -0x28);
  return;
}



===== BfPreQueryInfo @ 140023010 =====

int BfPreQueryInfo(longlong param_1,longlong param_2)

{
  byte bVar1;
  short *psVar2;
  longlong lVar3;
  uint *puVar4;
  int iVar5;
  int extraout_EAX;
  ulonglong uVar6;
  uint uVar7;
  longlong lVar8;
  undefined8 uVar9;
  int iVar10;
  longlong lVar11;
  undefined2 uVar12;
  longlong local_res10;
  undefined1 uVar13;
  ulonglong local_38;
  void *pvStack_30;
  
  iVar10 = 1;
  local_38 = 0;
  pvStack_30 = (void *)0x0;
  lVar11 = 0;
  local_res10 = 0;
  psVar2 = *(short **)(*(longlong *)(param_2 + 0x20) + 0x18);
  if ((((psVar2 == (short *)0x0) || (*psVar2 != 0x6431)) ||
      (iVar5 = FltGetStreamHandleContext(*(undefined8 *)(param_2 + 0x18)), iVar5 < 0)) ||
     (bVar1 = *(byte *)(local_res10 + 0x50), FltReleaseContext(), (bVar1 & 1) == 0))
  goto LAB_14002306b;
  iVar10 = *(int *)(*(longlong *)(param_1 + 0x10) + 0x20);
  if (iVar10 == 9) {
LAB_1400231ba:
    local_res10 = 0;
    iVar5 = FltGetStreamHandleContext
                      (*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20),&local_res10)
    ;
    if (iVar5 == -0x3ffffddb) {
      lVar11 = local_res10;
LAB_140023224:
      local_res10 = 0;
      iVar5 = 0;
    }
    else {
      if (-1 < iVar5) {
        lVar11 = local_res10;
        if ((*(uint *)(local_res10 + 0x50) & 1) == 0) {
          FltReleaseContext();
          lVar11 = 0;
        }
        goto LAB_140023224;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,7,0x19,
                            &WPP_ab4056511ca038337f1519c30a6fffbb_Traceguids,
                            "onecore\\base\\fs\\wci\\bindflt\\filter\\context.c",0xad,(char)iVar5);
      }
    }
    if (local_res10 != 0) {
      FltReleaseContext();
    }
    if (iVar5 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar12 = 0x3b;
        uVar13 = 0x34;
        goto LAB_14002314b;
      }
      goto LAB_140023190;
    }
    lVar3 = *(longlong *)(param_2 + 0x20);
    local_res10 = lVar11;
    if ((*(short **)(lVar3 + 0x18) == (short *)0x0) || (**(short **)(lVar3 + 0x18) != 0x6431)) {
LAB_140023268:
      uVar9 = *(undefined8 *)(param_2 + 0x18);
      lVar8 = *(longlong *)(param_2 + 0x20);
    }
    else {
      if (lVar11 == 0) {
        iVar5 = FltGetStreamHandleContext(*(undefined8 *)(param_2 + 0x18),lVar3,&local_res10);
        if (iVar5 < 0) goto LAB_140023268;
        bVar1 = *(byte *)(local_res10 + 0x50);
        FltReleaseContext();
      }
      else {
        bVar1 = *(byte *)(lVar11 + 0x50);
      }
      if ((bVar1 & 1) == 0) goto LAB_140023268;
      lVar8 = *(longlong *)(*(longlong *)(lVar3 + 0x20) + 8);
      uVar9 = *(undefined8 *)(*(longlong *)(lVar3 + 0x20) + 0x10);
    }
    uVar6 = BfGeneratePostCreateName
                      (lVar8,uVar9,(iVar10 != 0x30) + 0x2000301,lVar11,0,(short *)&local_38);
    iVar5 = (int)uVar6;
    if (iVar5 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar12 = 0x3c;
        uVar13 = 0x4e;
        goto LAB_14002314b;
      }
      goto LAB_140023190;
    }
    puVar4 = *(uint **)(*(longlong *)(param_1 + 0x10) + 0x28);
    uVar7 = *(uint *)(*(longlong *)(param_1 + 0x10) + 0x18);
    if (uVar7 < (ushort)local_38 + 4) {
      memmove(puVar4 + 1,pvStack_30,(ulonglong)(uVar7 - 4));
      iVar5 = -0x7ffffffb;
      *puVar4 = (uint)(ushort)local_38;
      uVar7 = *(int *)(*(longlong *)(param_1 + 0x10) + 0x18) - 4;
    }
    else {
      *puVar4 = (uint)(ushort)local_38;
      memmove(puVar4 + 1,pvStack_30,local_38 & 0xffff);
      uVar7 = (ushort)local_38 + 4;
    }
    *(ulonglong *)(param_1 + 0x20) = (ulonglong)uVar7;
    *(int *)(param_1 + 0x18) = iVar5;
    if (iVar5 < 0) goto LAB_140023190;
  }
  else {
    if (iVar10 == 0x37) {
      iVar5 = -0x3ffffff3;
      *(undefined8 *)(param_1 + 0x20) = 0;
      goto LAB_140023190;
    }
    if (iVar10 == 0x30) goto LAB_1400231ba;
    iVar10 = BfCheckAndSwitchTarget(param_1,param_2,(longlong *)0x0,(undefined1 *)&local_res10);
    if (-1 < extraout_EAX) goto LAB_14002306b;
    iVar5 = extraout_EAX;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140023190;
    uVar12 = 0x3d;
    uVar13 = 0x86;
LAB_14002314b:
    WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0xb,uVar12,
                        &WPP_c7f51acdbd3738713a5b9ea834ad885a_Traceguids,
                        "onecore\\base\\fs\\wci\\bindflt\\filter\\namesup.c",uVar13,(char)iVar5);
LAB_140023190:
    *(int *)(param_1 + 0x18) = iVar5;
  }
  iVar10 = 4;
  if (lVar11 != 0) {
    FltReleaseContext(lVar11);
  }
LAB_14002306b:
  if (pvStack_30 != (void *)0x0) {
    ExFreePoolWithTag(pvStack_30,0x74734642);
  }
  return iVar10;
}



===== BfCommonPreOp @ 140023430 =====

undefined8 BfCommonPreOp(longlong param_1,longlong param_2)

{
  int extraout_EAX;
  int iVar1;
  longlong lVar2;
  
  if (*(longlong *)(param_2 + 0x20) == 0) {
    return 1;
  }
  iVar1 = BfCheckAndSwitchTarget(param_1,param_2,(longlong *)0x0,(undefined1 *)0x0);
  lVar2 = CONCAT44((int)((ulonglong)param_1 >> 0x20),iVar1);
  if (-1 < extraout_EAX) {
    return 1;
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0x15,
                        &WPP_59754cb100fb33f1965e7b014742173a_Traceguids,
                        "onecore\\base\\fs\\wci\\bindflt\\filter\\bindflt.c",0x40,(char)extraout_EAX
                       );
  }
  *(int *)(lVar2 + 0x18) = extraout_EAX;
  *(undefined8 *)(lVar2 + 0x20) = 0;
  return 4;
}



===== BfGetSetDirectoryEnumerationHandleContext @ 1400234f0 =====

int BfGetSetDirectoryEnumerationHandleContext
              (longlong param_1,undefined1 *param_2,longlong *param_3)

{
  int iVar1;
  longlong lVar2;
  undefined2 uVar3;
  void *local_res8;
  undefined1 uVar4;
  
  local_res8 = (void *)0x0;
  iVar1 = FltGetStreamHandleContext
                    (*(undefined8 *)(param_1 + 0x18),*(undefined8 *)(param_1 + 0x20),&local_res8);
  if (iVar1 == -0x3ffffddb) {
    iVar1 = FltAllocateContext(g_BindFltState,0x10,0x98,0x200,&local_res8);
    if (iVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return iVar1;
      }
      uVar3 = 0x1d;
      uVar4 = 0x78;
    }
    else {
      memset(local_res8,0,0x98);
      KeInitializeEvent((longlong)local_res8 + 0x80,1,1);
      iVar1 = FltSetStreamHandleContext
                        (*(undefined8 *)(param_1 + 0x18),*(undefined8 *)(param_1 + 0x20),0,
                         local_res8,0);
      if (-1 < iVar1) goto LAB_140023540;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return iVar1;
      }
      uVar3 = 0x1e;
      uVar4 = 0x87;
    }
  }
  else {
    if (-1 < iVar1) {
LAB_140023540:
      KeWaitForSingleObject((longlong)local_res8 + 0x80,0,0,0,0);
      *param_2 = 1;
      if ((*(uint *)((longlong)local_res8 + 0x50) & 2) == 0) {
        *(undefined4 *)((longlong)local_res8 + 0x54) = 0;
        *(undefined8 *)((longlong)local_res8 + 0x58) = 0;
        lVar2 = (longlong)local_res8 + 0x60;
        *(longlong *)((longlong)local_res8 + 0x68) = lVar2;
        *(longlong *)lVar2 = lVar2;
        *(undefined1 *)((longlong)local_res8 + 0x70) = 0;
        *(uint *)((longlong)local_res8 + 0x50) = *(uint *)((longlong)local_res8 + 0x50) | 2;
      }
      *param_3 = (longlong)local_res8;
      return iVar1;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    uVar3 = 0x1f;
    uVar4 = 0x8d;
  }
  WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,7,uVar3,
                      &WPP_4bfd87d54ffb3323a752b550f6ae0533_Traceguids,
                      "onecore\\base\\fs\\wci\\bindflt\\filter\\dirctrl.c",uVar4,(char)iVar1);
  return iVar1;
}



===== BfGetFileNameInformation @ 140023710 =====

ulonglong BfGetFileNameInformation
                    (longlong param_1,longlong param_2,undefined8 param_3,undefined4 param_4,
                    longlong *param_5)

{
  ulonglong uVar1;
  
  *param_5 = 0;
  if (param_1 == 0) {
    if (param_2 == 0) {
      return 0xc000000d;
    }
    uVar1 = FltGetFileNameInformationUnsafe(param_2,param_3,param_4,param_5);
  }
  else {
    uVar1 = FltGetFileNameInformation(param_1,param_4,param_5);
  }
  if (((int)uVar1 < 0) || (*(short *)(*param_5 + 8) != 0)) {
    return uVar1;
  }
  uVar1 = uVar1 & 0xffffffff;
  if (*(short *)(*param_5 + 0x18) != 0) {
    uVar1 = 0xc000000d;
  }
  return uVar1;
}



===== BfMapShadowFileObjectToReal @ 1400237a0 =====

ulonglong BfMapShadowFileObjectToReal
                    (undefined8 param_1,longlong param_2,longlong param_3,undefined8 *param_4,
                    undefined8 *param_5,undefined8 *param_6)

{
  byte bVar1;
  undefined8 *puVar2;
  short *psVar3;
  undefined8 uVar4;
  longlong local_res10;
  
  psVar3 = *(short **)(param_2 + 0x18);
  if (((psVar3 != (short *)0x0) && (*psVar3 == 0x6431)) &&
     ((local_res10 = param_3, param_3 != 0 ||
      (psVar3 = (short *)FltGetStreamHandleContext(param_1,param_2,&local_res10), -1 < (int)psVar3))
     )) {
    bVar1 = *(byte *)(local_res10 + 0x50);
    if (param_3 == 0) {
      psVar3 = (short *)FltReleaseContext();
    }
    if ((bVar1 & 1) != 0) {
      puVar2 = *(undefined8 **)(param_2 + 0x20);
      *param_5 = puVar2[1];
      uVar4 = puVar2[2];
      *param_4 = uVar4;
      if (param_6 != (undefined8 *)0x0) {
        uVar4 = *puVar2;
        *param_6 = uVar4;
      }
      return CONCAT71((int7)((ulonglong)uVar4 >> 8),1);
    }
  }
  return (ulonglong)psVar3 & 0xffffffffffffff00;
}



===== BfPreSetInfo @ 140023880 =====

int BfPreSetInfo(longlong param_1,longlong param_2,ulonglong *param_3)

{
  void *_Dst;
  byte bVar1;
  uint uVar2;
  bool bVar3;
  int extraout_EAX;
  undefined4 uVar4;
  int iVar5;
  ulonglong uVar6;
  int iVar7;
  longlong lVar8;
  undefined8 uVar9;
  ulonglong uVar10;
  longlong lVar11;
  ulonglong local_res20;
  ulonglong *puVar12;
  char local_78;
  byte local_77;
  longlong local_70;
  ulonglong local_68;
  void *pvStack_60;
  undefined8 local_58;
  void *pvStack_50;
  longlong local_48 [2];
  
  local_68 = 0;
  uVar9 = 0;
  local_78 = '\0';
  local_48[0] = 0;
  local_58 = 0;
  local_res20 = local_res20 & 0xffffffffffffff00;
  iVar7 = BfCheckAndSwitchTarget(param_1,param_2,(longlong *)&local_68,&local_78);
  uVar10 = local_68;
  if (extraout_EAX < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0xb,0x3e,
                          &WPP_c7f51acdbd3738713a5b9ea834ad885a_Traceguids,
                          "onecore\\base\\fs\\wci\\bindflt\\filter\\namesup.c",0xd4,
                          (char)extraout_EAX);
    }
    uVar10 = local_68;
    iVar5 = extraout_EAX;
    goto LAB_140023ab8;
  }
  lVar11 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x28);
  uVar2 = *(uint *)(*(longlong *)(param_1 + 0x10) + 0x20);
  if (lVar11 != 0) {
    if (((*(short **)(lVar11 + 0x18) == (short *)0x0) || (**(short **)(lVar11 + 0x18) != 0x6431)) ||
       ((local_68 == 0 &&
        (iVar5 = FltGetStreamHandleContext(*(undefined8 *)(param_2 + 0x18),lVar11,&local_68),
        iVar5 < 0)))) {
LAB_140023ae2:
      lVar8 = 0;
    }
    else {
      local_77 = *(byte *)(local_68 + 0x50) & (byte)iVar7;
      if (uVar10 == 0) {
        FltReleaseContext();
      }
      if (local_77 == 0) goto LAB_140023ae2;
      lVar8 = (*(longlong **)(lVar11 + 0x20))[1];
      local_48[0] = **(longlong **)(lVar11 + 0x20);
      *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x28) = lVar8;
      FltSetCallbackDataDirty(param_1);
    }
    if (*(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x10) + 8) + 8) ==
        *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x10) + 0x28) + 8)) goto LAB_1400238fe;
    *(undefined8 *)(param_1 + 0x20) = 0;
    *(undefined4 *)(param_1 + 0x18) = 0xc00000d4;
    iVar7 = 4;
    goto switchD_140023971_caseD_c;
  }
  lVar8 = 0;
LAB_1400238fe:
  if (((local_78 != '\0') && (uVar2 < 0x28)) &&
     ((0x8000184000U >> ((longlong)(int)uVar2 & 0x3fU) & 1) != 0)) {
    iVar7 = 0;
    *param_3 = uVar10;
    if (((uVar2 - 0x13 < 2) || (uVar2 == 0x27)) &&
       (local_70 = *(longlong *)(*(longlong *)(uVar10 + 8) + 0x18),
       **(longlong **)(*(longlong *)(param_1 + 0x10) + 0x38) < *(longlong *)(local_70 + 0x28))) {
      ExAcquireFastMutex(*(undefined8 *)(local_70 + 0x30));
      *(int *)(uVar10 + 0x20) = *(int *)(uVar10 + 0x20) + 1;
      ExReleaseFastMutex(*(undefined8 *)(local_70 + 0x30));
      ExWaitForRundownProtectionRelease(uVar10 + 0x18);
      *param_3 = *param_3 | 1;
    }
    uVar10 = 0;
  }
  switch(uVar2) {
  case 10:
  case 0x41:
    lVar11 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x38);
    if (lVar8 != 0) {
      _Dst = (void *)(lVar11 + 0x14);
      local_58._0_4_ = CONCAT22(*(undefined2 *)(lVar11 + 0x10),*(undefined2 *)(lVar11 + 0x10));
      local_58 = (ulonglong)(uint)local_58;
      local_68 = 0;
      pvStack_60 = (void *)0x0;
      pvStack_50 = _Dst;
      iVar5 = BfRemoveFinalComponent((ushort *)&local_58,0,(ushort *)&local_68);
joined_r0x000140023c07:
      if (-1 < iVar5) {
        *(uint *)(lVar11 + 0x10) = (uint)(ushort)local_68;
        memmove(_Dst,pvStack_60,(ulonglong)(uint)(ushort)local_68);
        iVar7 = 0;
        *param_3 = *(ulonglong *)(lVar11 + 8);
        *(longlong *)(lVar11 + 8) = local_48[0];
        goto LAB_140023915;
      }
      goto LAB_140023ab8;
    }
    goto LAB_140023b79;
  case 0xb:
  case 0x48:
    lVar11 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x38);
    if (lVar8 != 0) {
      _Dst = (void *)(lVar11 + 0x14);
      local_58._0_4_ = CONCAT22(*(undefined2 *)(lVar11 + 0x10),*(undefined2 *)(lVar11 + 0x10));
      local_58 = (ulonglong)(uint)local_58;
      local_68 = 0;
      pvStack_60 = (void *)0x0;
      pvStack_50 = _Dst;
      iVar5 = BfRemoveFinalComponent((ushort *)&local_58,0,(ushort *)&local_68);
      goto joined_r0x000140023c07;
    }
LAB_140023b79:
    if (*(longlong *)(lVar11 + 8) != 0) {
      uVar6 = BfMapShadowFileHandleToReal
                        (param_1,*(longlong *)(lVar11 + 8),*(undefined8 *)(param_2 + 0x18),&local_58
                         ,(undefined1 *)&local_res20);
      iVar5 = (int)uVar6;
      if (-1 < iVar5) {
        if ((char)local_res20 != '\0') {
          *(ulonglong *)(lVar11 + 8) = local_58;
        }
        goto LAB_140023915;
      }
LAB_140023ab8:
      *(undefined8 *)(param_1 + 0x20) = 0;
      iVar7 = 4;
      *(int *)(param_1 + 0x18) = iVar5;
    }
    break;
  case 0xd:
  case 0x40:
    lVar11 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x30);
    if (lVar11 != 0) {
      local_58 = *(ulonglong *)(param_2 + 0x18);
      puVar12 = &local_res20;
      local_res20 = 0;
      iVar5 = ObReferenceObjectByHandle
                        (lVar11,0,*(undefined8 *)IoFileObjectType_exref,
                         *(undefined1 *)(param_1 + 0x50),puVar12,0);
      uVar4 = (undefined4)((ulonglong)puVar12 >> 0x20);
      if (iVar5 != -0x3fffffdc) {
        if (iVar5 < 0) goto LAB_140023ab8;
        bVar3 = false;
        local_68 = local_res20;
        local_48[0] = 0;
        if (((*(short **)(local_res20 + 0x18) != (short *)0x0) &&
            (**(short **)(local_res20 + 0x18) == 0x6431)) &&
           (iVar5 = FltGetStreamHandleContext(local_58,local_res20,local_48), -1 < iVar5)) {
          bVar1 = *(byte *)(local_48[0] + 0x50);
          FltReleaseContext();
          if ((bVar1 & 1) == 0) {
            bVar3 = false;
          }
          else {
            bVar3 = true;
            uVar9 = **(undefined8 **)(local_68 + 0x20);
          }
        }
        ObfDereferenceObject(local_res20);
        if (bVar3) {
          uVar4 = ZwSetInformationFile
                            (uVar9,param_1 + 0x18,
                             *(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x38),
                             *(undefined4 *)(*(longlong *)(param_1 + 0x10) + 0x18),
                             CONCAT44(uVar4,uVar2));
          iVar7 = 4;
          *(undefined1 *)(*(longlong *)(param_2 + 0x20) + 0x49) =
               *(undefined1 *)(*(longlong *)(*(longlong *)(param_1 + 0x10) + 8) + 0x49);
          *(undefined4 *)(param_1 + 0x18) = uVar4;
          *(undefined8 *)(param_1 + 0x20) = 0;
        }
      }
    }
  }
switchD_140023971_caseD_c:
LAB_140023915:
  if (uVar10 != 0) {
    FltReleaseContext(uVar10);
  }
  if (iVar7 == 4) {
    *param_3 = 0;
    FltClearCallbackDataDirty(param_1);
  }
  return iVar7;
}



===== BfRemoveFinalComponent @ 140023dc8 =====

undefined4 BfRemoveFinalComponent(ushort *param_1,ushort param_2,ushort *param_3)

{
  short *psVar1;
  ushort uVar2;
  short sVar3;
  longlong lVar4;
  ushort uVar5;
  undefined4 uVar6;
  short sVar7;
  
  uVar2 = *param_1;
  lVar4 = *(longlong *)(param_1 + 4);
  uVar6 = 0xc000000d;
  sVar7 = 0;
  if (uVar2 == 0) {
    *(longlong *)(param_3 + 4) = lVar4;
LAB_140023e9b:
    param_3[0] = 0;
    param_3[1] = 0;
LAB_140023e9e:
    uVar6 = 0;
  }
  else {
    uVar5 = (uVar2 >> 1) - 1;
    psVar1 = (short *)(lVar4 + (ulonglong)uVar5 * 2);
    if (*psVar1 == 0x5c) {
      if (uVar5 == 0) {
        *(short **)(param_3 + 4) = psVar1;
        goto LAB_140023e9b;
      }
      uVar5 = (uVar2 >> 1) - 2;
      sVar7 = 1;
    }
    for (; (int)((param_2 >> 1) - 1) < (int)(uint)uVar5; uVar5 = uVar5 - 1) {
      sVar3 = *(short *)(lVar4 + (ulonglong)uVar5 * 2);
      if (sVar3 == 0x5c) {
        *param_1 = uVar2 + sVar7 * -2;
        uVar6 = 0;
        *(ulonglong *)(param_3 + 4) = lVar4 + (ulonglong)(uVar5 + 1) * 2;
        *param_3 = sVar7 * 2;
        param_3[1] = sVar7 * 2;
        break;
      }
      if (sVar3 == 0x3a) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,8,0x14,
                             &WPP_529f93b0825532f67776c14f74ba0846_Traceguids,
                             "onecore\\base\\fs\\wci\\bindflt\\filter\\utils.c",0x8e);
        }
        break;
      }
      if (uVar5 == 0) {
        *(longlong *)(param_3 + 4) = lVar4;
        uVar2 = *param_1;
        *param_3 = uVar2;
        param_3[1] = uVar2;
        *param_1 = 0;
        goto LAB_140023e9e;
      }
      sVar7 = sVar7 + 1;
    }
  }
  return uVar6;
}



===== BfPreFsControl @ 140023f30 =====

ulonglong BfPreFsControl(longlong param_1,longlong param_2)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  char cVar5;
  ulonglong uVar6;
  char cVar7;
  int extraout_EAX;
  ulonglong uVar8;
  int iVar9;
  longlong lVar10;
  ulonglong uVar11;
  undefined8 uVar12;
  char local_res8 [8];
  ulonglong local_res20;
  undefined8 local_48;
  undefined8 local_40;
  
  local_res8[0] = '\0';
  uVar11 = 1;
  local_res20 = 0;
  lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 8);
  if (lVar2 == 0) {
    return 1;
  }
  local_40 = *(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x10);
  iVar9 = BfCheckAndSwitchTarget(param_1,param_2,(longlong *)&local_res20,local_res8);
  uVar6 = local_res20;
  cVar5 = local_res8[0];
  lVar10 = CONCAT44((int)((ulonglong)param_1 >> 0x20),iVar9);
  if (extraout_EAX < 0) {
    iVar9 = extraout_EAX;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0x15,
                          &WPP_3ec1b3d31795302c14eabb0ee55df402_Traceguids,
                          "onecore\\base\\fs\\wci\\bindflt\\filter\\fsctrl.c",0xea,
                          (char)extraout_EAX);
    }
  }
  else {
    lVar3 = *(longlong *)(lVar10 + 0x10);
    iVar9 = *(int *)(lVar3 + 0x28);
    if (iVar9 == 0x90394) {
      uVar11 = BfFsctlSetLayerRoot(lVar10,*(longlong *)(param_2 + 0x18),local_res8[0],local_res20);
      uVar11 = uVar11 & 0xffffffff;
      goto LAB_140024042;
    }
    if (iVar9 == 0x900fc) {
      uVar1 = *(uint *)(lVar3 + 0x20);
      lVar3 = *(longlong *)(lVar3 + 0x30);
      local_48 = 0;
      local_res8[0] = '\0';
      local_res20 = CONCAT44(local_res20._4_4_,uVar1);
      cVar7 = FltIs32bitProcess(lVar10);
      if (cVar7 == '\0') {
        if (uVar1 < 0x18) {
          iVar9 = -0x3fffffdd;
        }
        else {
          if (*(longlong *)(lVar3 + 8) == 0) goto LAB_140024042;
          uVar8 = BfMapShadowFileHandleToReal
                            (lVar10,*(longlong *)(lVar3 + 8),*(undefined8 *)(param_2 + 0x18),
                             &local_48,local_res8);
          iVar9 = (int)uVar8;
          if (-1 < iVar9) {
            if ((local_res8[0] == '\0') ||
               (*(undefined8 *)(lVar3 + 8) = local_48, *(char *)(lVar10 + 0x50) != '\x01'))
            goto LAB_140024042;
            uVar12 = 0x900fc;
            goto LAB_140023ff8;
          }
        }
      }
      else if (uVar1 < 0xc) {
        iVar9 = -0x3fffffdd;
      }
      else {
        if ((longlong)*(int *)(lVar3 + 8) == 0) goto LAB_140024042;
        uVar8 = BfMapShadowFileHandleToReal
                          (lVar10,(longlong)*(int *)(lVar3 + 8),*(undefined8 *)(param_2 + 0x18),
                           &local_48,local_res8);
        iVar9 = (int)uVar8;
        if (-1 < iVar9) {
          if (local_res8[0] == '\0') goto LAB_140024042;
          *(undefined4 *)(lVar3 + 4) = (undefined4)local_48;
          if (*(char *)(lVar10 + 0x50) != '\x01') goto LAB_140024042;
          uVar12 = 0x90074;
LAB_140023ff8:
          lVar4 = *(longlong *)(lVar10 + 0x10);
          iVar9 = FltFsControlFile(*(undefined8 *)(lVar4 + 0x10),*(undefined8 *)(lVar4 + 8),uVar12,
                                   lVar3,local_res20 & 0xffffffff,*(undefined8 *)(lVar4 + 0x30),
                                   *(undefined4 *)(lVar4 + 0x18),0);
          if (-1 < iVar9) goto LAB_140024042;
        }
      }
    }
    else {
      if (iVar9 == 0x90c1f) {
        uVar11 = BfFsctlGetMappings(lVar10);
        uVar11 = uVar11 & 0xffffffff;
        goto LAB_140024042;
      }
      if ((iVar9 != 0x98344) && (iVar9 != 0x983e8)) {
        if (local_res8[0] != '\0') {
          uVar11 = BfFsctlDefaultFilter(lVar10,param_2);
          uVar11 = uVar11 & 0xffffffff;
        }
        goto LAB_140024042;
      }
      iVar9 = -0x3fffff45;
    }
  }
  uVar11 = 4;
  *(int *)(lVar10 + 0x18) = iVar9;
  *(undefined8 *)(lVar10 + 0x20) = 0;
LAB_140024042:
  if ((cVar5 != '\0') && ((int)uVar11 == 4)) {
    *(longlong *)(*(longlong *)(lVar10 + 0x10) + 8) = lVar2;
    *(undefined8 *)(*(longlong *)(lVar10 + 0x10) + 0x10) = local_40;
  }
  if (uVar6 != 0) {
    FltReleaseContext(uVar6);
  }
  return uVar11;
}



===== BfFsctlSetLayerRoot @ 140024254 =====

undefined8 BfFsctlSetLayerRoot(longlong param_1,longlong param_2,char param_3,longlong param_4)

{
  longlong lVar1;
  ushort uVar2;
  uint uVar3;
  ulonglong uVar4;
  byte bVar5;
  ulonglong uVar6;
  undefined2 uVar7;
  ushort *puVar8;
  short sVar9;
  undefined8 uVar10;
  ushort local_res8 [4];
  undefined1 uVar11;
  undefined4 local_58 [2];
  longlong local_50;
  longlong local_48;
  ulonglong local_40;
  void *pvStack_38;
  
  lVar1 = *(longlong *)(param_1 + 0x10);
  local_50 = 0;
  local_48 = 0;
  uVar10 = 4;
  local_40 = 0;
  pvStack_38 = (void *)0x0;
  local_res8[0] = 0;
  if (((*(uint **)(lVar1 + 0x30) == (uint *)0x0) || (*(int *)(lVar1 + 0x20) != 4)) ||
     (uVar3 = **(uint **)(lVar1 + 0x30), (uVar3 & 0xfffffc00) != 0)) {
    uVar3 = 0xc000000d;
    goto LAB_1400242c0;
  }
  if ((uVar3 & 0xe0) == 0) {
    uVar10 = 1;
    goto LAB_1400242ec;
  }
  uVar6 = 2;
  if (*(uint *)(lVar1 + 0x18) < 2) {
    uVar3 = 0xc0000023;
LAB_1400242c0:
    uVar6 = 0;
  }
  else {
    if ((param_3 != '\0') && ((uVar3 >> 8 & 1) != 0)) {
      local_58[0] = 0;
      uVar4 = BfGeneratePostCreateName
                        (*(longlong *)(lVar1 + 8),*(undefined8 *)(lVar1 + 0x10),0x2000301,param_4,
                         param_2,(short *)&local_40);
      uVar3 = (uint)uVar4;
      if ((int)uVar3 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar7 = 0x11;
          uVar11 = 0xb1;
LAB_140024496:
          bVar5 = 2;
LAB_1400244ad:
          WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),bVar5,5,uVar7,
                              &WPP_3ec1b3d31795302c14eabb0ee55df402_Traceguids,
                              "onecore\\base\\fs\\wci\\bindflt\\filter\\fsctrl.c",uVar11,(char)uVar3
                             );
        }
      }
      else {
        uVar3 = FltGetVolumeFromInstance(param_2,&local_48);
        if ((int)uVar3 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar7 = 0x12;
            uVar11 = 0xbc;
            goto LAB_140024496;
          }
        }
        else {
          uVar3 = FltGetVolumeName(local_48,0,local_58);
          if (((uVar3 + 0x80000000 & 0x80000000) == 0) && (uVar3 != 0xc0000023)) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar7 = 0x13;
              uVar11 = 199;
              goto LAB_140024496;
            }
          }
          else {
            if (*(short *)((longlong)pvStack_38 + (ulonglong)((ushort)local_40 >> 1) * 2 + -2) ==
                0x5c) {
              bVar5 = 2;
              uVar3 = RtlUShortSub((ushort)local_40,2,(short *)&local_40);
              if ((int)uVar3 < 0) {
                if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                goto LAB_1400242c0;
                uVar7 = 0x14;
                uVar11 = 0xd9;
                goto LAB_1400244ad;
              }
            }
            sVar9 = 6;
            puVar8 = *(ushort **)(*(longlong *)(param_1 + 0x10) + 0x30);
            uVar3 = RtlUShortAdd(6,(ushort)local_40,puVar8);
            if (-1 < (int)uVar3) {
              uVar3 = RtlUShortAdd(2,*puVar8,local_res8);
              if (-1 < (int)uVar3) {
                if (*(uint *)(*(longlong *)(param_1 + 0x10) + 0x18) < (uint)local_res8[0])
                goto LAB_14002440f;
                puVar8[1] = (ushort)local_40 + sVar9;
                puVar8[2] = (ushort)local_58[0];
                puVar8[3] = (ushort)local_40;
                memmove(puVar8 + 4,pvStack_38,local_40 & 0xffff);
                uVar6 = (ulonglong)local_res8[0];
                goto LAB_140024407;
              }
            }
          }
        }
      }
      goto LAB_1400242c0;
    }
    uVar3 = FltGetFileNameInformation(param_1,0x101,&local_50);
    if ((int)uVar3 < 0) {
      local_50 = 0;
      goto LAB_1400242c0;
    }
    uVar3 = FltParseFileNameInformation(local_50);
    if ((int)uVar3 < 0) goto LAB_1400242c0;
    sVar9 = 6;
    puVar8 = *(ushort **)(*(longlong *)(param_1 + 0x10) + 0x30);
    uVar3 = RtlUShortAdd(6,*(short *)(local_50 + 8),puVar8);
    if ((int)uVar3 < 0) goto LAB_1400242c0;
    uVar2 = *puVar8 + 2;
    if (uVar2 < 2) {
      uVar3 = 0xc0000095;
      goto LAB_1400242c0;
    }
    if (*(uint *)(*(longlong *)(param_1 + 0x10) + 0x18) < (uint)uVar2) {
LAB_14002440f:
      uVar3 = 0x80000005;
    }
    else {
      puVar8[1] = *(short *)(local_50 + 8) + sVar9;
      puVar8[2] = *(ushort *)(local_50 + 0x18);
      puVar8[3] = *(ushort *)(local_50 + 8);
      memmove(puVar8 + 4,*(void **)(local_50 + 0x10),(ulonglong)*(ushort *)(local_50 + 8));
      uVar6 = (ulonglong)(uint)uVar2;
LAB_140024407:
      uVar3 = 0;
    }
  }
  *(uint *)(param_1 + 0x18) = uVar3;
  *(ulonglong *)(param_1 + 0x20) = uVar6;
  if (local_48 != 0) {
    FltObjectDereference();
  }
  if (local_50 != 0) {
    FltReleaseFileNameInformation();
  }
LAB_1400242ec:
  if (pvStack_38 != (void *)0x0) {
    ExFreePoolWithTag(pvStack_38,0x74734642);
  }
  return uVar10;
}



===== BfFsctlDefaultFilter @ 140024660 =====

undefined8 BfFsctlDefaultFilter(longlong param_1,undefined8 param_2)

{
  uint uVar1;
  longlong lVar2;
  int iVar3;
  
  lVar2 = *(longlong *)(param_1 + 0x10);
  uVar1 = *(uint *)(lVar2 + 0x28);
  if (uVar1 < 0x900f0) {
    if (uVar1 == 0x900ef) {
      return 1;
    }
    if ((((uVar1 != 0x90073) && (uVar1 != 0x900b3)) && (uVar1 != 0x900bb)) && (uVar1 != 0x900e7)) {
      return 1;
    }
  }
  else {
    if (uVar1 == 0x900f4) {
      return 1;
    }
    if ((uVar1 != 0x900f8) && (uVar1 != 0x901fc)) {
      if (uVar1 != 0x90448) {
        return 1;
      }
      if (*(uint *)(lVar2 + 0x20) < 0x18) {
        iVar3 = -0x3ffffdfa;
      }
      else {
        if ((**(int **)(lVar2 + 0x30) - 1U & 0xfffffffd) != 0) {
          return 1;
        }
        iVar3 = FltVetoBypassIo(param_1,param_2,0xc00004d0,&bypassVetoReason);
        if (-1 < iVar3) {
          *(undefined8 *)(param_1 + 0x20) = 0x160;
        }
      }
      goto LAB_1400246d4;
    }
  }
  iVar3 = -0x3fffffde;
LAB_1400246d4:
  FltClearCallbackDataDirty(param_1);
  *(int *)(param_1 + 0x18) = iVar3;
  if (iVar3 < 0) {
    *(undefined8 *)(param_1 + 0x20) = 0;
  }
  return 4;
}



===== BfPreQueryVolumeInfo @ 140024740 =====

undefined8 BfPreQueryVolumeInfo(longlong param_1,longlong param_2)

{
  int extraout_EAX;
  undefined8 uVar1;
  int iVar2;
  longlong lVar3;
  
  iVar2 = BfCheckAndSwitchTarget(param_1,param_2,(longlong *)0x0,(undefined1 *)0x0);
  lVar3 = CONCAT44((int)((ulonglong)param_1 >> 0x20),iVar2);
  if (extraout_EAX < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0x10,
                          &WPP_59754cb100fb33f1965e7b014742173a_Traceguids,
                          "onecore\\base\\fs\\wci\\bindflt\\filter\\bindflt.c",0xbd,
                          (char)extraout_EAX);
    }
    *(int *)(lVar3 + 0x18) = extraout_EAX;
    uVar1 = 4;
    *(undefined8 *)(lVar3 + 0x20) = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}



===== BfCachedWalkContextAvlCompareRoutine @ 1400247e0 =====

void BfCachedWalkContextAvlCompareRoutine(undefined8 param_1,longlong param_2)

{
  RtlCompareUnicodeString(param_1,param_2 + 0x28,0);
  return;
}



===== RtlFindUnicodeSubstring @ 140024810 =====

longlong RtlFindUnicodeSubstring(ushort *param_1,ushort *param_2,undefined1 param_3)

{
  ushort uVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  
  lVar4 = *(longlong *)(param_1 + 4);
  if (*param_2 <= *param_1) {
    for (lVar3 = 0; (ulonglong)*param_2 <= (ulonglong)*param_1 - lVar3; lVar3 = lVar3 + 2) {
      uVar1 = *param_2 >> 1;
      iVar2 = RtlCompareUnicodeStrings(lVar4,uVar1,*(undefined8 *)(param_2 + 4),uVar1,param_3);
      if (iVar2 == 0) {
        return lVar4;
      }
      lVar4 = lVar4 + 2;
    }
  }
  return 0;
}



===== BfCreateStreamContext @ 1400248ac =====

int BfCreateStreamContext(longlong param_1,char param_2,undefined8 *param_3)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  int iVar6;
  undefined8 *puVar7;
  undefined4 *puVar8;
  undefined8 *local_res20;
  
  local_res20 = (undefined8 *)0x0;
  puVar7 = (undefined8 *)0x0;
  iVar6 = FltAllocateContext(g_BindFltState,8,0x78,0x200,&local_res20);
  if (iVar6 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar6;
    }
    WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x13,
                        &WPP_ab4056511ca038337f1519c30a6fffbb_Traceguids,
                        "onecore\\base\\fs\\wci\\bindflt\\filter\\context.c",0x78,(char)iVar6);
    return iVar6;
  }
  memset(local_res20,0,0x78);
  if (param_2 != '\0') {
    puVar7 = (undefined8 *)ExAllocateFromPagedLookasideList(&DAT_14000d340);
    if (puVar7 == (undefined8 *)0x0) {
      return -0x3fffff66;
    }
    puVar8 = (undefined4 *)ExAllocateFromNPagedLookasideList(&DAT_14000d3c0);
    if (puVar8 == (undefined4 *)0x0) {
      ExFreeToPagedLookasideList(&DAT_14000d340,puVar7);
      return -0x3fffff66;
    }
    *(undefined8 *)(puVar8 + 2) = 0;
    puVar8[4] = 0;
    *puVar8 = 1;
    KeInitializeEvent(puVar8 + 6,1,0);
    puVar7[0xf] = puVar8;
    puVar7[0x10] = local_res20;
    puVar1 = *(undefined8 **)(param_1 + 0x18);
    uVar5 = puVar1[1];
    *puVar7 = *puVar1;
    puVar7[1] = uVar5;
    uVar5 = puVar1[3];
    puVar7[2] = puVar1[2];
    puVar7[3] = uVar5;
    uVar2 = *(undefined4 *)((longlong)puVar1 + 0x24);
    uVar3 = *(undefined4 *)(puVar1 + 5);
    uVar4 = *(undefined4 *)((longlong)puVar1 + 0x2c);
    *(undefined4 *)(puVar7 + 4) = *(undefined4 *)(puVar1 + 4);
    *(undefined4 *)((longlong)puVar7 + 0x24) = uVar2;
    *(undefined4 *)(puVar7 + 5) = uVar3;
    *(undefined4 *)((longlong)puVar7 + 0x2c) = uVar4;
    *(byte *)((longlong)puVar7 + 4) = *(byte *)((longlong)puVar7 + 4) | 0x40;
    *(byte *)((longlong)puVar7 + 6) = *(byte *)((longlong)puVar7 + 6) | 2;
    *(byte *)((longlong)puVar7 + 7) = *(byte *)((longlong)puVar7 + 7) & 0xf | 0x50;
    puVar1 = puVar7 + 7;
    *(undefined4 *)puVar7 = 0x886431;
    puVar7[8] = puVar1;
    *puVar1 = puVar1;
    puVar7[9] = 0;
    puVar7[10] = 0;
    puVar7[0xb] = 0;
    puVar7[0xc] = 0;
    *(undefined4 *)(puVar7 + 0xd) = 0;
    puVar7[0xe] = 0;
    puVar7[6] = puVar8;
  }
  ExInitializeResourceLite(local_res20 + 1);
  *local_res20 = 0;
  local_res20[0xe] = puVar7;
  *param_3 = local_res20;
  return iVar6;
}



===== BfMapShadowFileHandleToReal @ 140024ab0 =====

ulonglong BfMapShadowFileHandleToReal
                    (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 *param_4,
                    undefined1 *param_5)

{
  undefined1 uVar1;
  byte bVar2;
  undefined8 uVar3;
  longlong lVar4;
  undefined1 *puVar5;
  int iVar6;
  ulonglong uVar7;
  undefined1 uVar8;
  longlong local_res8;
  
  puVar5 = param_5;
  uVar8 = 0;
  uVar1 = *(undefined1 *)(param_1 + 0x50);
  uVar3 = *(undefined8 *)IoFileObjectType_exref;
  local_res8 = 0;
  *param_5 = 0;
  uVar7 = ObReferenceObjectByHandle(param_2,0,uVar3,uVar1,&local_res8,0);
  lVar4 = local_res8;
  if ((int)uVar7 == -0x3fffffdc) {
    *puVar5 = 0;
    uVar7 = 0;
  }
  else if (-1 < (int)uVar7) {
    param_5 = (undefined1 *)0x0;
    if ((((*(short **)(local_res8 + 0x18) != (short *)0x0) &&
         (**(short **)(local_res8 + 0x18) == 0x6431)) &&
        (iVar6 = FltGetStreamHandleContext(param_3,local_res8,&param_5), -1 < iVar6)) &&
       (bVar2 = param_5[0x50], FltReleaseContext(), (bVar2 & 1) != 0)) {
      if (param_4 != (undefined8 *)0x0) {
        *param_4 = **(undefined8 **)(lVar4 + 0x20);
      }
      uVar8 = 1;
    }
    *puVar5 = uVar8;
    ObfDereferenceObject(local_res8);
    uVar7 = uVar7 & 0xffffffff;
  }
  return uVar7;
}



===== BfpValidateBatchedMappingConfig @ 140024bc8 =====

undefined8 BfpValidateBatchedMappingConfig(uint *param_1,ulonglong param_2)

{
  undefined8 *puVar1;
  undefined1 auVar2 [16];
  uint uVar3;
  uint uVar4;
  undefined8 uVar5;
  uint uVar6;
  uint uVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  uint uVar10;
  undefined2 uVar11;
  uint uVar12;
  undefined8 in_stack_ffffffffffffff78;
  undefined8 in_stack_ffffffffffffff80;
  undefined1 uVar13;
  uint uVar14;
  wchar_t local_58;
  wchar_t local_56;
  undefined4 local_54;
  longlong local_50;
  undefined1 local_48 [16];
  undefined8 local_38;
  ulonglong uStack_30;
  
  if ((uint)param_2 < 0x28) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0xc000000d;
    }
    uVar11 = 0x79;
    uVar13 = 0xef;
    goto LAB_140024dd1;
  }
  uVar10 = *param_1;
  if ((uint)param_2 < uVar10) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0xc000000d;
    }
    WPP_RECORDER_SF_sDdd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,0x7a,
               &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
               "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",0xf6,(char)uVar10,(char)param_2)
    ;
    return 0xc000000d;
  }
  if ((param_1[1] & 0xcffffc00) != 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0xc000000d;
    }
    WPP_RECORDER_SF_sDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,0x7b,
                        &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                        "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",0xfd,(char)param_1[1]);
    return 0xc000000d;
  }
  uVar14 = param_1[6];
  uVar10 = uVar10 - 0x20;
  if (uVar14 < uVar10) {
    uVar3 = param_1[7];
    param_2 = (ulonglong)uVar3;
    if (uVar3 < uVar10) {
      uVar3 = *(uint *)((longlong)param_1 + (ulonglong)uVar14 + 0x20);
      if ((ulonglong)uVar3 << 5 < (ulonglong)uVar10) {
        uVar4 = *(uint *)((longlong)param_1 + param_2 + 0x20);
        if ((ulonglong)uVar4 << 3 < (ulonglong)uVar10) {
          for (uVar8 = 0; (uint)uVar8 < uVar4; uVar8 = (ulonglong)((uint)uVar8 + 1)) {
            uVar5 = *(undefined8 *)((longlong)param_1 + uVar8 * 8 + param_2 + 0x24);
            uVar12 = (uint)((ulonglong)uVar5 >> 0x20);
            if (uVar10 <= uVar12) {
              if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
                return 0xc000000d;
              }
              uVar11 = 0x80;
              uVar13 = 0x29;
              param_2 = uVar8;
              uVar14 = uVar12;
              goto LAB_140025269;
            }
            uVar12 = ((uint)uVar5 & 0xffff) + uVar12;
            if (uVar10 < uVar12) {
              if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
                return 0xc000000d;
              }
              uVar11 = 0x81;
              uVar13 = 0x2f;
              param_2 = uVar8;
              uVar14 = uVar12;
              goto LAB_140025269;
            }
          }
          uVar12 = 0;
          while( true ) {
            if (uVar3 <= uVar12) {
              return 0;
            }
            auVar2 = *(undefined1 (*) [16])
                      ((longlong)param_1 + (ulonglong)uVar12 * 0x20 + 0x24 + (ulonglong)uVar14);
            puVar1 = (undefined8 *)
                     ((longlong)param_1 + (ulonglong)uVar12 * 0x20 + 0x34 + (ulonglong)uVar14);
            local_38 = *puVar1;
            uVar9 = puVar1[1];
            uVar6 = auVar2._4_4_;
            param_2 = uVar8;
            local_48 = auVar2;
            uStack_30 = uVar9;
            if (uVar10 <= uVar6) break;
            uVar6 = uVar6 + auVar2._2_2_;
            if (uVar10 < uVar6) {
              if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
                return 0xc000000d;
              }
              uVar11 = 0x83;
              uVar13 = 0x41;
              uVar14 = uVar6;
              goto LAB_140025269;
            }
            uVar6 = auVar2._12_4_;
            if (uVar10 <= uVar6) {
              if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
                return 0xc000000d;
              }
              uVar11 = 0x84;
              uVar13 = 0x47;
              uVar14 = uVar6;
              goto LAB_140025269;
            }
            uVar6 = auVar2._10_2_ + uVar6;
            param_2 = (ulonglong)uVar6;
            if (uVar10 < uVar6) {
              if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
                return 0xc000000d;
              }
              uVar11 = 0x85;
              uVar13 = 0x4d;
              uVar14 = uVar6;
              goto LAB_140025269;
            }
            uVar7 = (uint)((ulonglong)local_38 >> 0x20);
            if (uVar10 <= uVar7) {
              if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
                return 0xc000000d;
              }
              uVar11 = 0x86;
              uVar13 = 0x53;
              uVar14 = uVar7;
              goto LAB_140025269;
            }
            uVar7 = (ushort)local_38 + uVar7;
            if (uVar10 < uVar7) {
              if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
                return 0xc000000d;
              }
              uVar11 = 0x87;
              uVar13 = 0x59;
              param_2 = (ulonglong)uVar7;
              uVar14 = uVar7;
              goto LAB_140025269;
            }
            uVar6 = (uint)(uVar9 >> 0x20);
            param_2 = uVar9;
            if (uVar10 <= uVar6) {
              if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
                return 0xc000000d;
              }
              uVar11 = 0x88;
              uVar13 = 0x5f;
              uVar14 = uVar6;
              goto LAB_140025269;
            }
            uVar6 = ((uint)uVar9 & 0xffff) + uVar6;
            if (uVar10 < uVar6) {
              if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
                return 0xc000000d;
              }
              uVar11 = 0x89;
              uVar13 = 0x65;
              uVar14 = uVar6;
              goto LAB_140025269;
            }
            local_54 = 0;
            local_50 = (uVar9 >> 0x20) + 0x20 + (longlong)param_1;
            local_58 = (wchar_t)uVar9;
            local_56 = (wchar_t)uVar9;
            uVar5 = BfValidateShortName((ushort *)&local_58);
            if ((char)uVar5 == '\0') {
              if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
                return 0xc000000d;
              }
              WPP_RECORDER_SF_sDZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar9,6,0x8a,
                                  in_stack_ffffffffffffff78,in_stack_ffffffffffffff80,0x71,&local_58
                                 );
              return 0xc000000d;
            }
            if (uVar4 <= (auVar2._0_4_ & 0xffff)) {
              if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
                return 0xc000000d;
              }
              uVar6 = auVar2._0_4_ & 0xffff;
              uVar11 = 0x8b;
              uVar13 = 0x77;
LAB_140025047:
              WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,uVar11,
                                  &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                                  "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",uVar13,
                                  (char)uVar6);
              return 0xc000000d;
            }
            uVar6 = (uint)(ushort)local_48._8_2_;
            if (uVar4 <= uVar6) {
              if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
                return 0xc000000d;
              }
              uVar11 = 0x8c;
              uVar13 = 0x7d;
              goto LAB_140025047;
            }
            uVar12 = uVar12 + 1;
            uVar8 = uVar9;
          }
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return 0xc000000d;
          }
          uVar11 = 0x82;
          uVar13 = 0x3b;
          uVar14 = uVar6;
          goto LAB_140025269;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return 0xc000000d;
        }
        uVar11 = 0x7f;
        uVar13 = 0x1f;
      }
      else {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return 0xc000000d;
        }
        uVar11 = 0x7e;
        uVar13 = 0x16;
      }
LAB_140024dd1:
      WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,uVar11,
                         &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                         "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",uVar13);
      return 0xc000000d;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0xc000000d;
    }
    uVar11 = 0x7d;
    uVar13 = 0xd;
    uVar14 = uVar3;
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0xc000000d;
    }
    uVar11 = 0x7c;
    uVar13 = 6;
  }
LAB_140025269:
  WPP_RECORDER_SF_sDDD
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,6,uVar11,in_stack_ffffffffffffff78,
             in_stack_ffffffffffffff80,uVar13,(char)uVar14,(char)uVar10);
  return 0xc000000d;
}



===== BfValidateShortName @ 14002528c =====

undefined8 BfValidateShortName(ushort *param_1)

{
  ushort uVar1;
  ushort uVar2;
  ulonglong uVar3;
  ushort uVar4;
  ushort uVar5;
  bool bVar6;
  
  uVar1 = *param_1;
  uVar5 = uVar1 >> 1;
  bVar6 = true;
  uVar4 = 0;
  if ((uVar5 == 0) || (uVar4 = 0, *(longlong *)(param_1 + 4) == 0)) {
LAB_1400252b5:
    uVar3 = (ulonglong)uVar4;
    bVar6 = uVar1 - uVar3 < 0x19;
  }
  else {
    do {
      uVar2 = uVar4 >> 1;
      if ((uint)uVar2 < (uint)uVar5) {
        do {
          if (*(short *)(*(longlong *)(param_1 + 4) + (longlong)(short)uVar2 * 2) == 0x5c) break;
          uVar2 = uVar2 + 1;
        } while ((int)(short)uVar2 < (int)(uint)uVar5);
      }
      if ((int)(uint)uVar5 <= (int)(short)uVar2) goto LAB_1400252b5;
      uVar2 = (uVar2 + 1) * 2;
      uVar3 = (ulonglong)uVar4;
      if (0x18 < uVar2 - uVar3) {
        bVar6 = false;
        break;
      }
      uVar4 = uVar2 + 2;
    } while (uVar4 < uVar1);
  }
  return CONCAT71((int7)(uVar3 >> 8),bVar6);
}



===== BfInitFsContext2 @ 140025340 =====

void BfInitFsContext2(undefined8 param_1,undefined8 param_2,longlong param_3,longlong param_4,
                     longlong *param_5,undefined8 *param_6)

{
  longlong lVar1;
  undefined8 uVar2;
  code *pcVar3;
  undefined1 *puVar4;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  FltObjectReference(**(undefined8 **)(param_3 + 0x10));
  puVar4 = auStack_28;
  param_6[1] = param_1;
  *param_6 = param_2;
  param_6[2] = **(undefined8 **)(param_3 + 0x10);
  param_6[5] = param_5;
  param_6[6] = param_3;
  LOCK();
  lVar1 = *param_5;
  *param_5 = *param_5 + 1;
  UNLOCK();
  if (lVar1 + 1 < 2) {
    pcVar3 = (code *)swi(0x29);
    (*pcVar3)(0xe);
    puVar4 = auStack_20;
  }
  *(undefined8 *)(puVar4 + -8) = 0x1400253ba;
  ExInitializeRundownProtection(param_6 + 3);
  uVar2 = *(undefined8 *)(param_4 + 0x80);
  *(undefined8 *)(puVar4 + -8) = 0x1400253cd;
  FltReferenceContext(uVar2);
  param_6[7] = *(undefined8 *)(param_4 + 0x80);
  return;
}



===== BfInstanceSetup @ 140025410 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0001400254bc) */

int BfInstanceSetup(longlong param_1,ulonglong param_2,undefined4 *param_3,uint param_4)

{
  int iVar1;
  undefined8 uVar2;
  undefined2 uVar3;
  ushort uVar4;
  wchar_t *pwVar5;
  undefined1 auStackY_b8 [32];
  undefined1 uVar6;
  undefined4 *local_78;
  undefined4 local_70 [2];
  longlong local_68;
  wchar_t local_60 [20];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_b8;
  pwVar5 = local_60;
  local_78 = (undefined4 *)0x0;
  uVar4 = 0x13;
  local_68 = 0;
  builtin_wcsncpy(local_60,L"Name Not Available",0x13);
  if ((((param_2 & 2) == 0) || (0x1e < param_4)) || ((0x58002044U >> (param_4 & 0x1f) & 1) == 0)) {
    iVar1 = -0x3fe3fff1;
    goto LAB_140025492;
  }
  param_2 = 2;
  param_3 = (undefined4 *)0x38;
  iVar1 = FltAllocateContext();
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140025492;
    uVar3 = 0xd;
    uVar6 = 0x4c;
  }
  else {
    uRam0000000000000008 = 0;
    pwRam0000000000000010 = (wchar_t *)0x0;
    uRam0000000000000018 = 0;
    uRam0000000000000020 = 0;
    uRam0000000000000028 = 0;
    uRam0000000000000030 = 0;
    uRam0000000000000000 = *(undefined8 *)(param_1 + 0x18);
    iVar1 = FltGetDiskDeviceObject(*(undefined8 *)(param_1 + 0x10),&local_68);
    if (-1 < iVar1) {
      uRam0000000000000028 = *(undefined8 *)(local_68 + 0x38);
    }
    param_3 = local_70;
    local_70[0] = 0;
    FltGetVolumeName(*(undefined8 *)(param_1 + 0x10),0);
    param_2 = 8;
    uVar2 = BfAllocateUnicodeString((short)local_70[0],(undefined4 *)0x8);
    iVar1 = (int)uVar2;
    if (iVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140025492;
      uVar3 = 0xe;
      uVar6 = 0x77;
    }
    else {
      param_3 = (undefined4 *)0x0;
      param_2 = 8;
      FltGetVolumeName(*(undefined8 *)(param_1 + 0x10));
      pwVar5 = pwRam0000000000000010;
      uRam0000000000000018 = CONCAT44(uRam0000000000000018._4_4_,param_4);
      uVar4 = (ushort)uRam0000000000000008 >> 1;
      uVar2 = BfInitializeMappingContext((longlong *)0x30);
      iVar1 = (int)uVar2;
      if (iVar1 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140025492;
        uVar3 = 0xf;
        uVar6 = 0x88;
      }
      else {
        param_2 = 1;
        iVar1 = FltSetInstanceContext(*(undefined8 *)(param_1 + 0x18));
        param_3 = local_78;
        if (-1 < iVar1) {
          iVar1 = 0;
          goto LAB_140025492;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140025492;
        uVar3 = 0x10;
        uVar6 = 0x93;
      }
    }
  }
  param_3 = (undefined4 *)0x2;
  param_2 = CONCAT71((int7)(param_2 >> 8),2);
  WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,uVar3,
                      &WPP_ab4056511ca038337f1519c30a6fffbb_Traceguids,
                      "onecore\\base\\fs\\wci\\bindflt\\filter\\context.c",uVar6,(char)iVar1);
LAB_140025492:
  if (local_68 != 0) {
    ObfDereferenceObject();
  }
  if ((((iVar1 + 0x80000000U & 0x80000000) == 0) && (iVar1 != -0x3fe3fff1)) &&
     ((Microsoft_Windows_Containers_BindFltEnableBits & 1) != 0)) {
    McTemplateK0dhzr1_EtwWriteTransfer(0x80000000,param_2,param_3,iVar1,uVar4,pwVar5);
  }
  return iVar1;
}



===== BfGetFileInformationClassOffsets @ 140025728 =====

void BfGetFileInformationClassOffsets(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = 0;
  uVar2 = 0;
  if (param_1 < 0x3d) {
    if (param_1 == 0x3c) {
      uVar1 = 0x58;
    }
    else if (param_1 == 1) {
      uVar1 = 0x40;
    }
    else if (param_1 == 2) {
      uVar1 = 0x44;
    }
    else if (param_1 == 3) {
      uVar1 = 0x5e;
    }
    else {
      if (param_1 == 0xc) {
        uVar1 = 0xc;
        uVar2 = 8;
        goto LAB_140025753;
      }
      if (param_1 != 0x25) {
        if (param_1 != 0x26) goto LAB_140025753;
        goto LAB_1400257ad;
      }
      uVar1 = 0x68;
    }
  }
  else if (param_1 == 0x3f) {
    uVar1 = 0x72;
  }
  else if (param_1 == 0x4e) {
LAB_1400257ad:
    uVar1 = 0x50;
  }
  else if (param_1 == 0x4f) {
    uVar1 = 0x6a;
  }
  else if (param_1 == 0x50) {
    uVar1 = 0x60;
  }
  else {
    if (param_1 != 0x51) goto LAB_140025753;
    uVar1 = 0x7a;
  }
  uVar2 = 0x3c;
LAB_140025753:
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = uVar1;
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = uVar2;
  }
  return;
}



===== BfRemoveCloudFileECPs @ 1400257ec =====

void BfRemoveCloudFileECPs(longlong param_1,longlong param_2,char param_3,char param_4,char param_5)

{
  if (param_2 == 0) {
    return;
  }
  if (param_4 != '\0') {
    BfRemoveEcp(param_1,param_2,&GUID_ECP_NETWORK_OPEN_CONTEXT);
  }
  if (param_5 != '\0') {
    BfRemoveEcp(param_1,param_2,&GUID_ECP_CLOUDFILES_ATTRIBUTION);
  }
  if (param_3 != '\0') {
    FltFreeExtraCreateParameterList(*(undefined8 *)(param_1 + 8),param_2);
  }
  return;
}



===== BfFreeEnumerationConflictList @ 14002586c =====

void BfFreeEnumerationConflictList(longlong *param_1)

{
  longlong *plVar1;
  code *pcVar2;
  undefined8 *puVar3;
  undefined1 *puVar4;
  undefined1 auStack_28 [32];
  
  puVar4 = auStack_28;
  while ((longlong *)*param_1 != param_1) {
    plVar1 = (longlong *)param_1[1];
    if (((longlong *)*plVar1 != param_1) ||
       (puVar3 = (undefined8 *)plVar1[1], (longlong *)*puVar3 != plVar1)) {
      pcVar2 = (code *)swi(0x29);
      puVar3 = (undefined8 *)(*pcVar2)(3);
      puVar4 = puVar4 + 8;
    }
    param_1[1] = (longlong)puVar3;
    *puVar3 = param_1;
    *(undefined8 *)(puVar4 + -8) = 0x1400258af;
    ExFreeToPagedLookasideList(&DAT_14000d5c0);
  }
  return;
}



===== BfpCleanupMappingEntry @ 1400258bc =====

void BfpCleanupMappingEntry(undefined8 *param_1)

{
  ExFreePoolWithTag(*param_1,0x706d4642);
  ExFreePoolWithTag(param_1[1],0x706d4642);
  return;
}



===== BfGenerateDirectoryEntryForCache @ 1400258fc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int BfGenerateDirectoryEntryForCache(longlong param_1)

{
  int iVar1;
  undefined2 uVar2;
  undefined1 auStackY_f8 [32];
  undefined1 uVar3;
  undefined1 uVar4;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined4 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_48;
  undefined4 local_40;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_f8;
  memset(&local_88,0,0x68);
  local_a8 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  local_90 = 0;
  iVar1 = FltQueryInformationFile
                    (*(undefined8 *)(param_1 + 0x48),*(undefined8 *)(param_1 + 0x68),&local_88,0x68)
  ;
  if (((iVar1 + 0x80000000U & 0x80000000) == 0) && (iVar1 != -0x7ffffffb)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    uVar4 = 0x12;
    uVar2 = 10;
    uVar3 = 0x26;
  }
  else {
    iVar1 = FltQueryInformationFile
                      (*(undefined8 *)(param_1 + 0x48),*(undefined8 *)(param_1 + 0x68),&local_a8,8);
    if (-1 < iVar1) {
      iVar1 = FltQueryInformationFile
                        (*(undefined8 *)(param_1 + 0x48),*(undefined8 *)(param_1 + 0x68),&local_a0,
                         0x18);
      if (iVar1 == -0x3fffff45) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sDdd
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,0xc,0xc,
                     &WPP_4bfd87d54ffb3323a752b550f6ae0533_Traceguids,
                     "onecore\\base\\fs\\wci\\bindflt\\filter\\dirctrl.c",0x3f,0xbb,0x3b);
        }
        uStack_98 = 0xffffffffffffffff;
        local_90 = 0xffffffffffffffff;
      }
      else if (iVar1 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return iVar1;
        }
        uVar4 = 0x3b;
        uVar2 = 0xd;
        uVar3 = 0x44;
        goto LAB_140025b12;
      }
      *(undefined8 *)(param_1 + 200) = local_60;
      *(undefined8 *)(param_1 + 0xb8) = local_70;
      *(undefined8 *)(param_1 + 0xa0) = local_88;
      *(undefined4 *)(param_1 + 0xd8) = local_40;
      *(undefined8 *)(param_1 + 0xc0) = local_58;
      *(undefined4 *)(param_1 + 0xd0) = local_68;
      *(undefined8 *)(param_1 + 0xa8) = local_80;
      *(undefined8 *)(param_1 + 0xb0) = local_78;
      *(undefined4 *)(param_1 + 0xdc) = local_a8._4_4_;
      *(undefined8 *)(param_1 + 0xe0) = local_48;
      *(undefined8 *)(param_1 + 0xe8) = uStack_98;
      *(undefined8 *)(param_1 + 0xf0) = local_90;
      return iVar1;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    uVar4 = 0x23;
    uVar2 = 0xb;
    uVar3 = 0x32;
  }
LAB_140025b12:
  WPP_RECORDER_SF_sDdd
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,0xc,uVar2,
             &WPP_4bfd87d54ffb3323a752b550f6ae0533_Traceguids,
             "onecore\\base\\fs\\wci\\bindflt\\filter\\dirctrl.c",uVar3,(char)iVar1,uVar4);
  return iVar1;
}



===== BfNormalizeNameComponentExCallback @ 140025bd0 =====

ulonglong BfNormalizeNameComponentExCallback
                    (longlong param_1,undefined8 param_2,wchar_t *param_3,ushort param_4,
                    short *param_5,undefined8 *param_6,uint param_7,byte param_8)

{
  wchar_t *pwVar1;
  longlong *plVar2;
  bool bVar3;
  char cVar4;
  uint uVar5;
  ulonglong uVar6;
  short sVar7;
  ulonglong uVar8;
  undefined8 *puVar9;
  longlong lVar10;
  uint uVar11;
  undefined2 uVar12;
  undefined8 in_stack_fffffffffffffe98;
  undefined4 uVar15;
  undefined8 uVar13;
  ulonglong uVar14;
  undefined1 uVar16;
  ulonglong in_stack_fffffffffffffeb8;
  undefined4 uVar17;
  ulonglong in_stack_fffffffffffffec0;
  ulonglong local_108;
  longlong lStack_100;
  longlong local_f8;
  ulonglong local_f0;
  longlong lStack_e8;
  longlong local_e0;
  longlong local_d8;
  longlong local_d0;
  wchar_t local_c8;
  short sStack_c6;
  undefined4 uStack_c4;
  longlong lStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  ulonglong local_98;
  longlong local_90 [2];
  wchar_t *local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  ulonglong uStack_68;
  ulonglong local_60;
  void *pvStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  
  local_d0 = 0;
  local_d8 = 0;
  local_f8 = 0;
  local_98 = local_98 & 0xffffffffffff0000;
  local_70 = 0;
  uStack_68 = uStack_68 & 0xffffffff00000000;
  lVar10 = 0;
  local_e0 = 0;
  _local_c8 = 0;
  lStack_c0 = 0;
  local_b8 = 0;
  uStack_b0 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  local_90[0] = 0;
  local_90[1] = 0;
  local_80 = (wchar_t *)0x0;
  uStack_78 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_108 = 0;
  lStack_100 = 0;
  local_f0 = 0;
  lStack_e8 = 0;
  uVar5 = FltGetStreamHandleContext(param_1);
  uVar15 = (undefined4)((ulonglong)in_stack_fffffffffffffe98 >> 0x20);
  uVar17 = (undefined4)(in_stack_fffffffffffffeb8 >> 0x20);
  uVar8 = (ulonglong)uVar5;
  if (((uVar5 + 0x80000000 & 0x80000000) == 0) && (uVar5 != 0xc0000225)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar12 = 0x34;
      uVar16 = 0xea;
      uVar11 = 9;
LAB_140025f51:
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar11,uVar12,
                          &WPP_c7f51acdbd3738713a5b9ea834ad885a_Traceguids,
                          "onecore\\base\\fs\\wci\\bindflt\\filter\\namesup.c",uVar16,(char)uVar5);
    }
    goto LAB_140025c9d;
  }
  local_98 = 1;
  uStack_b0 = 0;
  local_b8 = 0x28;
  local_a8 = 0;
  uStack_a0 = 0;
  if ((uVar5 == 0xc0000225) || ((*(uint *)(local_d0 + 0x50) & 1) == 0)) {
    local_98 = PsGetHostSilo();
    local_90[0] = CONCAT44(local_90[0]._4_4_,0x30);
    uStack_78 = CONCAT44(uStack_78._4_4_,(uint)(~param_8 & 1) << 6) | 0x200;
    local_90[1] = 0;
    uVar13 = CONCAT44(uVar15,0x21);
    local_70 = 0;
    uStack_68 = 0;
    local_80 = param_3;
    uVar5 = FltCreateFileEx2(g_BindFltState,param_1,&local_d8,&local_f8,uVar13,local_90,&local_50,0,
                             CONCAT44(uVar17,0x80),in_stack_fffffffffffffec0 & 0xffffffff00000000,1,
                             1,0,0,0x800,&local_b8);
    uVar15 = (undefined4)((ulonglong)uVar13 >> 0x20);
    uVar8 = (ulonglong)uVar5;
    if ((int)uVar5 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDZd
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,9,0x35,
                   &WPP_c7f51acdbd3738713a5b9ea834ad885a_Traceguids,
                   "onecore\\base\\fs\\wci\\bindflt\\filter\\namesup.c",0x12,param_3,(char)uVar5);
      }
      goto LAB_140025c9d;
    }
  }
  else {
    plVar2 = *(longlong **)(local_d0 + 0x78);
    lStack_c0 = (ulonglong)param_4 + *(longlong *)(param_3 + 4);
    sVar7 = *param_3 - param_4;
    _local_c8 = CONCAT22(sVar7,sVar7);
    bVar3 = true;
    local_60 = 0;
    pvStack_58 = (void *)0x0;
    uVar6 = BfAllocateUnicodeString(sVar7 + 2 + *param_5,(undefined4 *)&local_108);
    uVar8 = uVar6 & 0xffffffff;
    if ((int)uVar6 < 0) goto LAB_140025c9d;
    uVar5 = RtlAppendUnicodeStringToString(&local_108,&local_c8);
    uVar8 = (ulonglong)uVar5;
    if ((int)uVar5 < 0) goto LAB_140025c9d;
    uVar5 = RtlAppendUnicodeToString(&local_108,L"\\");
    uVar8 = (ulonglong)uVar5;
    if ((int)uVar5 < 0) goto LAB_140025c9d;
    uVar5 = RtlAppendUnicodeStringToString(&local_108,param_5);
    uVar8 = (ulonglong)uVar5;
    if ((int)uVar5 < 0) goto LAB_140025c9d;
    uVar14 = CONCAT71((int7)((ulonglong)in_stack_fffffffffffffe98 >> 8),~param_8) &
             0xffffffffffffff01;
    uVar6 = BfMappingLookup(plVar2,param_1,0,&local_108,(char)uVar14,&local_e0);
    lVar10 = local_e0;
    uVar8 = uVar6 & 0xffffffff;
    if ((int)uVar6 < 0) goto LAB_140025c9d;
    pwVar1 = (wchar_t *)(local_e0 + 0x10);
    cVar4 = RtlEqualUnicodeString(&local_108,pwVar1,0);
    if (cVar4 != '\0') {
      uVar5 = BfRemoveFinalComponent((ushort *)pwVar1,0,(ushort *)&local_60);
      uVar8 = (ulonglong)uVar5;
      if (-1 < (int)uVar5) {
        if (param_7 < (ushort)local_60 + 0xc) {
          uVar8 = 0x80000005;
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,9,0x36,
                               &WPP_c7f51acdbd3738713a5b9ea834ad885a_Traceguids,
                               "onecore\\base\\fs\\wci\\bindflt\\filter\\namesup.c",0x60);
          }
        }
        else {
          *(uint *)(param_6 + 1) = (uint)(ushort)local_60;
          *param_6 = 0;
          memmove((void *)((longlong)param_6 + 0xc),pvStack_58,local_60 & 0xffff);
        }
      }
      goto LAB_140025c9d;
    }
    puVar9 = *(undefined8 **)(*(longlong *)(lVar10 + 0x20) + 0x40);
    while( true ) {
      uVar17 = (undefined4)(in_stack_fffffffffffffec0 >> 0x20);
      uVar15 = (undefined4)(uVar14 >> 0x20);
      if (puVar9 == (undefined8 *)(*(longlong *)(lVar10 + 0x20) + 0x40)) break;
      if (bVar3) {
        bVar3 = false;
      }
      else {
        BfFreeUnicodeString((undefined4 *)&local_f0);
      }
      uVar6 = BfReplaceFirstSubstring
                        ((ushort *)&local_c8,(ushort *)pwVar1,(ushort *)(puVar9 + 5),
                         (undefined4 *)&local_f0);
      uVar8 = uVar6 & 0xffffffff;
      if ((int)uVar6 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sDZZZd
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,9,0x37,
                     &WPP_c7f51acdbd3738713a5b9ea834ad885a_Traceguids,
                     (wchar_t *)"onecore\\base\\fs\\wci\\bindflt\\filter\\namesup.c",0x84,pwVar1,
                     (wchar_t *)(puVar9 + 5),&local_c8,(char)uVar6);
        }
        goto LAB_140025c9d;
      }
      uVar8 = BfPrependVolumeDeviceName(puVar9[2],(wchar_t *)&local_f0);
      uVar5 = (uint)uVar8;
      uVar8 = uVar8 & 0xffffffff;
      if ((int)uVar5 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140025c9d;
        uVar12 = 0x38;
        uVar16 = 0x8c;
        uVar11 = 5;
        goto LAB_140025f51;
      }
      if ((*(uint *)(*(longlong *)(lVar10 + 0x20) + 8) & 4) == 0) {
        local_98 = PsGetHostSilo();
      }
      else {
        local_98 = IoGetSilo(param_2);
      }
      local_90[0] = CONCAT44(local_90[0]._4_4_,0x30);
      local_80 = (wchar_t *)&local_f0;
      local_90[1] = 0;
      in_stack_fffffffffffffec0 = CONCAT44(uVar17,7);
      in_stack_fffffffffffffeb8 = in_stack_fffffffffffffeb8 & 0xffffffff00000000;
      uStack_78 = CONCAT44(uStack_78._4_4_,0x200);
      local_70 = 0;
      uStack_68 = 0;
      uVar14 = CONCAT44(uVar15,0x80);
      uVar5 = FltCreateFileEx2(g_BindFltState,*(undefined8 *)puVar9[2],&local_d8,&local_f8,uVar14,
                               local_90,&local_50,0,in_stack_fffffffffffffeb8,
                               in_stack_fffffffffffffec0,1,0x20,0,0,0,&local_b8);
      uVar8 = (ulonglong)uVar5;
      if (((uVar5 != 0xc0000034) && (uVar5 != 0xc000003a)) && ((int)uVar5 < 0)) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sDZd
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,9,0x39,
                     &WPP_c7f51acdbd3738713a5b9ea834ad885a_Traceguids,
                     "onecore\\base\\fs\\wci\\bindflt\\filter\\namesup.c",0xb4,(wchar_t *)&local_f0,
                     (char)uVar5);
        }
        goto LAB_140025c9d;
      }
      puVar9 = (undefined8 *)*puVar9;
    }
  }
  uVar5 = FltQueryDirectoryFile(param_1,local_f8,param_6,param_7,CONCAT44(uVar15,0xc),1,param_5,1,0)
  ;
  uVar8 = (ulonglong)uVar5;
  if (local_d8 != 0) {
    FltClose();
  }
  if (local_f8 != 0) {
    ObfDereferenceObject();
  }
  if (((int)uVar5 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,9,0x3a,
                        &WPP_c7f51acdbd3738713a5b9ea834ad885a_Traceguids,
                        "onecore\\base\\fs\\wci\\bindflt\\filter\\namesup.c",0xcd,(char)uVar5);
  }
LAB_140025c9d:
  if (lStack_e8 != 0) {
    ExFreePoolWithTag(lStack_e8,0x74734642);
    lStack_e8 = 0;
  }
  local_f0 = local_f0 & 0xffffffff00000000;
  if (lStack_100 != 0) {
    ExFreePoolWithTag(lStack_100,0x74734642);
    lStack_100 = 0;
  }
  local_108 = local_108 & 0xffffffff00000000;
  if (lVar10 != 0) {
    BfFreeMappingLookupEntry(lVar10);
  }
  if (local_d0 != 0) {
    FltReleaseContext();
  }
  return uVar8;
}



===== BfPostSetInfo @ 140026390 =====

undefined8 BfPostSetInfo(longlong param_1,longlong param_2,ulonglong param_3)

{
  int *piVar1;
  uint uVar2;
  longlong lVar3;
  ulonglong uVar4;
  longlong lVar5;
  byte bVar6;
  longlong lVar7;
  
  bVar6 = 0;
  lVar3 = 0;
  lVar7 = 0;
  lVar5 = 0;
  uVar4 = 0;
  uVar2 = *(uint *)(*(longlong *)(param_1 + 0x10) + 0x20);
  if ((uVar2 < 0x28) && ((0x8000184000U >> ((longlong)(int)uVar2 & 0x3fU) & 1) != 0)) {
    lVar3 = *(longlong *)(param_2 + 0x20);
    uVar4 = param_3 & 0xfffffffffffffffe;
    bVar6 = (byte)param_3 & 1;
    lVar7 = *(longlong *)(uVar4 + 8);
    lVar5 = *(longlong *)(lVar7 + 0x18);
  }
  else if ((uVar2 == 10) || (((uVar2 == 0x41 || (uVar2 == 0xb)) || (uVar2 == 0x48)))) {
    *(ulonglong *)(*(longlong *)(*(longlong *)(param_1 + 0x10) + 0x38) + 8) = param_3;
    return 0;
  }
  if (uVar2 == 0xe) {
    *(undefined8 *)(lVar3 + 0x68) = *(undefined8 *)(lVar7 + 0x68);
  }
  else if (((uVar2 == 0x13) || (uVar2 == 0x14)) || (uVar2 == 0x27)) {
    BfUpdateFileSizes(lVar7,lVar3);
  }
  if (bVar6 != 0) {
    ExAcquireFastMutex(*(undefined8 *)(lVar5 + 0x30));
    piVar1 = (int *)(uVar4 + 0x20);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      ExReInitializeRundownProtection(uVar4 + 0x18);
    }
    ExReleaseFastMutex(*(undefined8 *)(lVar5 + 0x30));
  }
  if (uVar4 != 0) {
    FltReleaseContext(uVar4);
  }
  return 0;
}



===== BfPortMessage @ 1400264b0 =====

undefined8
BfPortMessage(undefined8 param_1,void *param_2,uint param_3,undefined4 *param_4,uint param_5,
             uint *param_6)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  int *_Dst;
  uint *_Src;
  ulonglong uVar4;
  undefined8 uVar5;
  undefined2 uVar6;
  uint local_res18 [2];
  undefined1 uVar7;
  uint uVar8;
  
  uVar4 = (ulonglong)param_3;
  uVar5 = 0;
  local_res18[0] = 0;
  _Dst = (int *)0x0;
  _Src = (uint *)0x0;
  if (param_3 < 0xc) {
    uVar5 = 0xc000000d;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140026502;
    uVar6 = 10;
    uVar8 = 0xc;
    uVar7 = 0xa2;
  }
  else {
    if (0xb < param_5) {
      _Dst = (int *)ExAllocatePool2(0x100,uVar4,0x736d4642);
      if (_Dst == (int *)0x0) {
        uVar5 = 0xc000009a;
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140026502;
        uVar6 = 0xc;
        uVar7 = 0xb0;
      }
      else {
        cVar2 = ExGetPreviousMode();
        if (cVar2 == '\x01') {
          ProbeForRead(param_2,uVar4,1);
          ProbeForWrite(param_4,param_5,1);
        }
        memmove(_Dst,param_2,uVar4);
        _Src = (uint *)ExAllocatePool2(0x100,(ulonglong)param_5,0x736d4642);
        if (_Src != (uint *)0x0) {
          uVar8 = _Dst[1];
          if (uVar8 == param_3) {
            iVar1 = *_Dst;
            if (iVar1 == 0) {
              *param_4 = 1;
              param_4[1] = 0xc;
              uVar4 = BfStoreVirtualizationMapping((uint *)(_Dst + 2),_Dst[1] - 8);
              uVar3 = (undefined4)uVar4;
            }
            else if (iVar1 == 2) {
              *param_4 = 3;
              param_4[1] = 0xc;
              uVar4 = BfRemoveVirtualizationMapping((uint *)(_Dst + 2),_Dst[1] - 8);
              uVar3 = (undefined4)uVar4;
            }
            else if (iVar1 == 4) {
              *param_4 = 5;
              param_4[1] = 0xc;
              uVar4 = BfStoreBatchedVirtualizationMapping((uint *)(_Dst + 2),_Dst[1] - 8);
              uVar3 = (undefined4)uVar4;
            }
            else if (iVar1 == 6) {
              *param_4 = 7;
              param_4[1] = 0xc;
              uVar4 = BfRemoveBatchedVirtualizationMapping
                                ((uint *)(_Dst + 2),(ulonglong)(_Dst[1] - 8));
              uVar3 = (undefined4)uVar4;
            }
            else {
              if (iVar1 == 8) {
                uVar4 = BfProcessGetMappingsRequest
                                  ((longlong)(_Dst + 2),param_5,(ulonglong)_Src,local_res18);
                _Src[1] = (uint)uVar4;
                *_Src = local_res18[0];
                *param_6 = local_res18[0];
                memmove(param_4,_Src,(ulonglong)param_5);
                goto LAB_140026502;
              }
              if (iVar1 != 10) {
                uVar5 = 0xc000000d;
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  WPP_RECORDER_SF_sDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,3,0x1b,
                                      &WPP_6d7c48c734c233e7b7f87674c7f4df79_Traceguids,
                                      "onecore\\base\\fs\\wci\\bindflt\\filter\\message.c",0xbc,
                                      (char)iVar1);
                }
                goto LAB_140026502;
              }
              *param_4 = 0xb;
              param_4[1] = 0xc;
              uVar4 = BfProcessTrackWritesRequest((uint *)(_Dst + 2),_Dst[1] - 8);
              uVar3 = (undefined4)uVar4;
            }
            param_4[2] = uVar3;
            *param_6 = 0xc;
            goto LAB_140026502;
          }
          uVar5 = 0xc000000d;
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_140026502;
          uVar6 = 0xe;
          uVar7 = 0xd2;
          goto LAB_1400266c1;
        }
        uVar5 = 0xc000009a;
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140026502;
        uVar6 = 0xd;
        uVar7 = 0xca;
      }
      uVar5 = 0xc000009a;
      WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,3,uVar6,
                         &WPP_6d7c48c734c233e7b7f87674c7f4df79_Traceguids,
                         "onecore\\base\\fs\\wci\\bindflt\\filter\\message.c",uVar7);
      goto LAB_140026502;
    }
    uVar5 = 0xc000000d;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140026502;
    uVar6 = 0xb;
    uVar8 = 0xc;
    uVar7 = 0xa8;
    param_3 = param_5;
  }
LAB_1400266c1:
  uVar5 = 0xc000000d;
  WPP_RECORDER_SF_sDdd
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,3,uVar6,
             &WPP_6d7c48c734c233e7b7f87674c7f4df79_Traceguids,
             "onecore\\base\\fs\\wci\\bindflt\\filter\\message.c",uVar7,(char)param_3,(char)uVar8);
LAB_140026502:
  if (_Dst != (int *)0x0) {
    ExFreePoolWithTag(_Dst,0x736d4642);
  }
  if (_Src != (uint *)0x0) {
    ExFreePoolWithTag(_Src,0x736d4642);
  }
  return uVar5;
}



===== BfStoreVirtualizationMapping @ 140026904 =====

ulonglong BfStoreVirtualizationMapping(uint *param_1,uint param_2)

{
  short sVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  longlong lVar8;
  undefined2 uVar9;
  longlong lVar10;
  longlong local_res18;
  longlong local_res20;
  undefined1 uVar11;
  undefined1 uVar12;
  longlong local_88;
  undefined8 *local_80;
  undefined8 local_78;
  longlong lStack_70;
  undefined8 local_68;
  longlong lStack_60;
  undefined8 local_58;
  longlong lStack_50;
  longlong local_48 [2];
  
  local_res18 = 0;
  lVar10 = 0;
  local_88 = 0;
  local_48[0] = 0;
  local_48[1] = 0;
  local_res20 = 0;
  local_80 = (undefined8 *)0x0;
  uVar5 = PsGetCurrentSilo();
  cVar2 = PsIsHostSilo(uVar5);
  if (cVar2 == '\0') {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,0xa7,
                         &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                         "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",0x19);
    }
    return 0xc0000022;
  }
  if (param_2 < 0x40) {
    uVar6 = 0xc000000d;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0xc000000d;
    }
    uVar9 = 0xa8;
    uVar11 = 0x25;
    goto LAB_1400269e5;
  }
  if (param_2 < *param_1) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0xc000000d;
    }
    WPP_RECORDER_SF_sDdd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,0xa9,
               &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
               "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",0x2c,(char)*param_1,
               (char)param_2);
    return 0xc000000d;
  }
  if ((param_1[2] & 0xcffffc00) != 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0xc000000d;
    }
    WPP_RECORDER_SF_sDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,0xaa,
                        &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                        "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",0x33,(char)param_1[2]);
    return 0xc000000d;
  }
  ExAcquireFastMutex(&DAT_14000d248);
  if (DAT_14000d280 != '\0') {
    ExReleaseFastMutex();
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,0xab,
                         &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                         "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",0x41);
    }
    return 0xc00000bb;
  }
  ExReleaseFastMutex(&DAT_14000d248);
  uVar6 = BfpValidateVirtualizationRoots((ushort *)param_1,param_2,&local_res18,&local_88);
  lVar8 = local_res18;
  uVar7 = uVar6 & 0xffffffff;
  if ((int)uVar6 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return uVar7;
    }
    uVar11 = (undefined1)uVar6;
    uVar12 = 0x53;
    uVar9 = 0xac;
    goto LAB_140026bd1;
  }
  lStack_70 = local_res18 + 6;
  local_78 = (ulonglong)CONCAT22(*(undefined2 *)(local_res18 + 4),*(undefined2 *)(local_res18 + 4));
  lStack_50 = local_88 + 6;
  local_58 = (ulonglong)CONCAT22(*(undefined2 *)(local_88 + 4),*(undefined2 *)(local_88 + 4));
  uVar6 = Feature_AnchorlessBindingVeto__private_IsEnabledDeviceUsageNoInline();
  if (*(longlong *)(param_1 + 4) == 0) {
    if ((int)uVar6 == 0) {
      if ((short)param_1[8] != 0) goto LAB_140026d5c;
      iVar3 = BfpShouldVetoBinding((longlong)&local_78,*(undefined2 *)(lVar8 + 2),'\0');
      if (iVar3 == -0x3fffffde) {
        uVar6 = 0xc0000022;
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return 0xc0000022;
        }
        uVar9 = 0xaf;
        uVar11 = 0x87;
        goto LAB_1400269e5;
      }
      if ((iVar3 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        uVar9 = 0xb0;
        uVar11 = 0x8c;
        goto LAB_140026d36;
      }
    }
    else {
      iVar3 = BfpShouldVetoBinding
                        ((longlong)&local_78,*(undefined2 *)(lVar8 + 2),(short)param_1[8] != 0);
      if (iVar3 == -0x3fffffde) {
        uVar6 = 0xc0000022;
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return 0xc0000022;
        }
        uVar9 = 0xad;
        uVar11 = 0x70;
LAB_1400269e5:
        WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,uVar9,
                           &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                           "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",uVar11);
        return uVar6;
      }
      if ((iVar3 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        uVar9 = 0xae;
        uVar11 = 0x75;
LAB_140026d36:
        WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,6,uVar9,
                            &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                            "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",uVar11,(char)iVar3)
        ;
      }
    }
    lVar8 = local_res18;
  }
LAB_140026d5c:
  sVar1 = (short)param_1[8];
  local_68 = 0;
  lStack_60 = 0;
  if (sVar1 != 0) {
    lStack_60 = (ulonglong)param_1[9] + (longlong)param_1;
    param_1[2] = param_1[2] | 0x20000000;
    local_68 = (ulonglong)CONCAT22(sVar1,sVar1);
  }
  uVar6 = BfpInitializeMappingEntry
                    ((ushort *)&local_78,(ushort *)&local_58,(ushort *)&local_68,(ushort *)0x0,
                     *(short *)(lVar8 + 2),(ushort *)0x0,*(short *)(local_88 + 2),local_48);
  uVar7 = uVar6 & 0xffffffff;
  if ((int)uVar6 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return uVar7;
    }
    uVar11 = (undefined1)uVar6;
    uVar9 = 0xb1;
    uVar12 = 0xb4;
LAB_140026bd1:
    WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,uVar9,
                        &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                        "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",uVar12,uVar11);
    return uVar7;
  }
  if (param_1[1] != 0) {
    uVar6 = BfpValidateMappingExceptions((ushort *)param_1,param_2,local_48[0],&local_res20);
    if ((int)uVar6 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,0xb2,
                            &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                            "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",0xc5,(char)uVar6);
      }
      uVar6 = uVar6 & 0xffffffff;
      lVar10 = local_res20;
      goto LAB_140026efe;
    }
    lVar10 = local_res20;
  }
  uVar6 = 0;
  uVar4 = BfpGetMappingContext(param_1,(short *)0x0,0,0,(longlong *)0x0,&local_80);
  uVar7 = (ulonglong)uVar4;
  if ((int)uVar4 < 0) {
    uVar6 = uVar7;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140026efe;
    uVar9 = 0xb3;
    uVar11 = 0xd2;
  }
  else {
    uVar4 = BfpMappingInsert(local_80,local_48,param_1[2],param_1[1],lVar10);
    uVar7 = (ulonglong)uVar4;
    if ((-1 < (int)uVar4) ||
       (uVar6 = uVar7, (undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED))
    goto LAB_140026efe;
    uVar9 = 0xb4;
    uVar11 = 0xde;
  }
  WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,uVar9,
                      &WPP_64bd3c744a813145b0e4eacc228c9621_Traceguids,
                      "onecore\\base\\fs\\wci\\bindflt\\filter\\mapping.c",uVar11,(char)uVar4);
  uVar6 = uVar7;
LAB_140026efe:
  if (lVar10 != 0) {
    ExFreePoolWithTag(lVar10,0x706d4642);
  }
  BfpCleanupMappingEntry(local_48);
  return uVar6;
}



===== BfGetInstanceFromFileObject @ 140026f44 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong BfGetInstanceFromFileObject(short *param_1,char param_2,undefined8 *param_3)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  short sVar4;
  undefined2 uVar5;
  undefined1 auStackY_168 [32];
  undefined1 uVar6;
  undefined1 uVar7;
  ulonglong local_e8;
  longlong lStack_e0;
  ulonglong local_d8;
  longlong lStack_d0;
  longlong local_c8;
  longlong local_c0;
  undefined8 local_b8;
  longlong local_b0;
  undefined8 local_a8;
  wchar_t *local_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  ulonglong *local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  ulonglong uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  wchar_t local_58 [8];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_168;
  local_a8 = 0x10000e;
  local_c0 = 0;
  local_b8 = 0;
  local_78 = 0;
  uStack_70 = uStack_70 & 0xffffffff00000000;
  local_a0 = local_58;
  local_b0 = 0;
  local_c8 = 0;
  sVar4 = *param_1 + 2;
  local_d8 = 0;
  lStack_d0 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_88 = (ulonglong *)0x0;
  uStack_80 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_e8 = 0;
  lStack_e0 = 0;
  builtin_wcsncpy(local_58,L"\\??\\UNC",8);
  uVar2 = BfAllocateUnicodeString(*param_1,(undefined4 *)&local_e8);
  uVar3 = uVar2 & 0xffffffff;
  if ((int)uVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140027357;
    uVar7 = (undefined1)uVar2;
    uVar5 = 0x2e;
    uVar6 = 0xd6;
  }
  else {
    RtlCopyUnicodeString(&local_e8,param_1);
    if (param_2 == '\0') {
      sVar4 = sVar4 + (short)local_a8;
    }
    uVar2 = BfAllocateUnicodeString(sVar4,(undefined4 *)&local_d8);
    uVar3 = uVar2 & 0xffffffff;
    if ((int)uVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140027357;
      uVar7 = (undefined1)uVar2;
      uVar5 = 0x2f;
      uVar6 = 0xe3;
    }
    else if (param_2 == '\0') {
      uVar1 = RtlAppendUnicodeStringToString(&local_d8,&local_a8);
      uVar3 = (ulonglong)uVar1;
      if ((int)uVar1 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140027357;
        uVar7 = (undefined1)uVar1;
        uVar5 = 0x30;
        uVar6 = 0xec;
      }
      else {
        lStack_e0 = lStack_e0 + 2;
        local_e8 = CONCAT62(local_e8._2_6_,(short)local_e8 + -2);
        uVar1 = RtlAppendUnicodeStringToString(&local_d8,&local_e8);
        uVar3 = (ulonglong)uVar1;
        if (-1 < (int)uVar1) goto LAB_140027180;
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140027357;
        uVar7 = (undefined1)uVar1;
        uVar5 = 0x31;
        uVar6 = 0xfb;
      }
    }
    else {
      *(undefined2 *)(lStack_e0 + 2) = 0x3f;
      uVar1 = RtlAppendUnicodeStringToString(&local_d8,&local_e8);
      uVar3 = (ulonglong)uVar1;
      if ((int)uVar1 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140027357;
        uVar7 = (undefined1)uVar1;
        uVar5 = 0x32;
        uVar6 = 0xb;
      }
      else {
LAB_140027180:
        uVar1 = RtlAppendUnicodeToString(&local_d8,L"\\");
        uVar3 = (ulonglong)uVar1;
        if ((int)uVar1 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_140027357;
          uVar7 = (undefined1)uVar1;
          uVar5 = 0x33;
          uVar6 = 0x13;
        }
        else {
          local_88 = &local_d8;
          local_98 = CONCAT44(local_98._4_4_,0x30);
          uStack_90 = 0;
          uStack_80 = CONCAT44(uStack_80._4_4_,0x240);
          local_78 = 0;
          uStack_70 = 0;
          uVar1 = FltCreateFileEx2(g_BindFltState,0,&local_b0,&local_c8);
          uVar3 = (ulonglong)uVar1;
          if ((int)uVar1 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_sDZd
                        (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,3,0x34,
                         &WPP_529f93b0825532f67776c14f74ba0846_Traceguids,
                         "onecore\\base\\fs\\wci\\bindflt\\filter\\utils.c",0x2f,
                         (wchar_t *)&local_d8,(char)uVar1);
            }
            goto LAB_140027357;
          }
          uVar1 = FltGetVolumeFromFileObject(g_BindFltState,local_c8,&local_c0);
          uVar3 = (ulonglong)uVar1;
          if ((int)uVar1 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
            goto LAB_140027357;
            uVar7 = (undefined1)uVar1;
            uVar5 = 0x35;
            uVar6 = 0x36;
          }
          else {
            uVar1 = FltGetVolumeInstanceFromName(g_BindFltState,local_c0,0,&local_b8);
            uVar3 = (ulonglong)uVar1;
            if (-1 < (int)uVar1) {
              *param_3 = local_b8;
              goto LAB_140027357;
            }
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
            goto LAB_140027357;
            uVar7 = (undefined1)uVar1;
            uVar5 = 0x36;
            uVar6 = 0x3d;
          }
        }
      }
    }
  }
  WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,3,uVar5,
                      &WPP_529f93b0825532f67776c14f74ba0846_Traceguids,
                      "onecore\\base\\fs\\wci\\bindflt\\filter\\utils.c",uVar6,uVar7);
LAB_140027357:
  if (lStack_d0 != 0) {
    ExFreePoolWithTag(lStack_d0,0x74734642);
    lStack_d0 = 0;
  }
  local_d8 = local_d8 & 0xffffffff00000000;
  if (lStack_e0 != 0) {
    ExFreePoolWithTag(lStack_e0,0x74734642);
    lStack_e0 = 0;
  }
  local_e8 = local_e8 & 0xffffffff00000000;
  if (local_b0 != 0) {
    FltClose();
  }
  if (local_c8 != 0) {
    ObfDereferenceObject();
  }
  if (local_c0 != 0) {
    FltObjectDereference();
  }
  return uVar3;
}



===== BfUnlockAll @ 14002740c =====

int BfUnlockAll(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  longlong local_res18 [2];
  
  local_res18[0] = 0;
  iVar1 = FltAllocateCallbackData(param_1,param_2,local_res18);
  if (-1 < iVar1) {
    *(undefined1 *)(*(longlong *)(local_res18[0] + 0x10) + 4) = 0x11;
    *(undefined1 *)(*(longlong *)(local_res18[0] + 0x10) + 5) = 3;
    FltPerformSynchronousIo(local_res18[0]);
    FltFreeCallbackData(local_res18[0]);
  }
  return iVar1;
}



===== BfClearMappingTable @ 14002747c =====

void BfClearMappingTable(longlong *param_1)

{
  longlong *plVar1;
  longlong lVar2;
  code *pcVar3;
  
  FltAcquireResourceExclusive(param_1 + 2);
  while( true ) {
    plVar1 = (longlong *)*param_1;
    if (plVar1 == param_1) {
      FltReleaseResource(param_1 + 2);
      return;
    }
    if (((longlong *)plVar1[1] != param_1) || (lVar2 = *plVar1, *(longlong **)(lVar2 + 8) != plVar1)
       ) break;
    *param_1 = lVar2;
    *(longlong **)(lVar2 + 8) = param_1;
    BfpDeleteInstanceTierNode((longlong)plVar1);
  }
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  pcVar3 = (code *)swi(3);
  (*pcVar3)();
  return;
}



===== BfpDeleteInstanceTierNode @ 1400274e8 =====

void BfpDeleteInstanceTierNode(longlong param_1)

{
  BfpDeletePathTree(*(undefined8 **)(param_1 + 0x18));
  if (*(uint **)(param_1 + 0x20) != (uint *)0x0) {
    BfpDeletePathTierNode(*(uint **)(param_1 + 0x20));
  }
  FltReleaseContext(*(undefined8 *)(param_1 + 0x10));
  ExFreePoolWithTag(param_1,0x706d4642);
  return;
}



===== BfPortDisconnect @ 140027540 =====

void BfPortDisconnect(undefined8 param_1)

{
  undefined8 local_res8 [4];
  
  local_res8[0] = param_1;
  FltCloseClientPort(g_BindFltState,local_res8);
  return;
}



===== _tlgEnableCallback @ 140027570 =====

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



===== BfPortConnect @ 1400275f0 =====

undefined8 BfPortConnect(undefined8 param_1)

{
  undefined8 *in_stack_00000028;
  
  *in_stack_00000028 = param_1;
  return 0;
}



===== BfCleanupSiloContext @ 140027610 =====

void BfCleanupSiloContext(longlong param_1)

{
  BfCleanupMappingContext(*(longlong **)(param_1 + 8));
  ExFreePoolWithTag(*(undefined8 *)(param_1 + 8),0x636d4642);
  return;
}



===== BfMergeEnumerationContexts @ 140027644 =====

undefined8
BfMergeEnumerationContexts
          (int param_1,longlong param_2,char param_3,uint param_4,longlong param_5,uint *param_6,
          undefined8 *param_7)

{
  longlong lVar1;
  code *pcVar2;
  uint uVar3;
  int iVar4;
  ulonglong uVar5;
  undefined8 ****ppppuVar6;
  uint uVar7;
  undefined8 uVar8;
  undefined1 *puVar9;
  uint uVar10;
  undefined8 ***pppuVar11;
  uint *_Dst;
  ulonglong uVar12;
  uint uVar13;
  undefined4 *puVar14;
  uint uVar15;
  undefined1 auStack_b8 [8];
  undefined1 auStack_b0 [24];
  undefined1 local_98;
  char local_88;
  uint local_84;
  undefined8 ****local_80;
  undefined8 ****local_78;
  uint local_70;
  uint uStack_6c;
  undefined4 *local_68;
  uint local_60 [2];
  uint *local_58;
  longlong local_50;
  ulonglong local_48;
  
  uVar8 = 0;
  local_84 = 0;
  local_60[0] = 0;
  uStack_6c = 0;
  uVar13 = 0;
  local_58 = (uint *)0x0;
  _Dst = (uint *)0x0;
  local_70 = param_4;
  BfGetFileInformationClassOffsets(param_1,&local_84,local_60);
  uVar3 = local_84;
  puVar9 = auStack_b8;
  uVar12 = (ulonglong)local_84;
  local_78 = &local_80;
  local_80 = &local_80;
  uVar10 = param_4;
  do {
    uVar5 = Feature_4063646010__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar5 == 0) {
      if (param_4 <= uVar13 + uVar3) goto LAB_14002787f;
    }
    else if (uVar10 <= uVar3) goto LAB_14002787f;
    local_68 = (undefined4 *)0x0;
    local_50 = 0;
    local_84 = 0;
    pppuVar11 = *(undefined8 ****)(param_2 + 0x60);
    local_88 = param_3;
    if (pppuVar11 == (undefined8 ***)(param_2 + 0x60)) goto LAB_14002787f;
    do {
      ppppuVar6 = (undefined8 ****)ExAllocateFromPagedLookasideList(&DAT_14000d5c0);
      if (ppppuVar6 == (undefined8 ****)0x0) goto LAB_140027a4b;
      uVar13 = *(uint *)(pppuVar11 + 6);
      if (uVar13 == 0) {
LAB_140027822:
        ExFreeToPagedLookasideList(&DAT_14000d5c0,ppppuVar6);
LAB_140027838:
        puVar14 = local_68;
        uVar15 = local_84;
      }
      else {
        puVar14 = (undefined4 *)
                  ((ulonglong)*(uint *)((longlong)pppuVar11 + 0x34) + (longlong)pppuVar11[8]);
        lVar1 = (longlong)puVar14 + uVar12;
        uVar15 = *(uint *)((ulonglong)local_60[0] + (longlong)puVar14);
        if (uVar13 < uVar15 + uVar3) {
          uVar15 = uVar13 - uVar3;
        }
        if (puVar14 == (undefined4 *)0x0) goto LAB_140027822;
        if (local_68 != (undefined4 *)0x0) {
          local_48 = (ulonglong)(uVar15 >> 1);
          local_98 = 1;
          iVar4 = RtlCompareUnicodeStrings(lVar1,local_48,local_50,local_84 >> 1);
          if (iVar4 < 1) {
            if (iVar4 < 0) goto LAB_1400278bc;
            ppppuVar6[2] = pppuVar11;
            *(undefined4 *)(ppppuVar6 + 3) = *puVar14;
            if ((undefined8 *****)*local_78 == &local_80) {
              ppppuVar6[1] = local_78;
              *ppppuVar6 = &local_80;
              *local_78 = ppppuVar6;
              local_78 = ppppuVar6;
              goto LAB_140027838;
            }
          }
          else {
            local_98 = 1;
            iVar4 = RtlCompareUnicodeStrings(lVar1,local_48,L".",1);
            if (iVar4 != 0) {
              local_98 = 1;
              iVar4 = RtlCompareUnicodeStrings(lVar1,local_48,L"..",2);
              if (iVar4 != 0) goto LAB_140027822;
            }
LAB_1400278bc:
            local_84 = uVar15;
            local_68 = puVar14;
            local_50 = lVar1;
            BfFreeEnumerationConflictList((longlong *)&local_80);
            ppppuVar6[2] = pppuVar11;
            *(undefined4 *)(ppppuVar6 + 3) = *puVar14;
            if ((undefined8 *****)*local_78 == &local_80) {
              ppppuVar6[1] = local_78;
              *ppppuVar6 = &local_80;
              *local_78 = ppppuVar6;
              local_78 = ppppuVar6;
              goto LAB_140027840;
            }
          }
          goto LAB_140027a44;
        }
        ppppuVar6[2] = pppuVar11;
        *(undefined4 *)(ppppuVar6 + 3) = *puVar14;
        local_84 = uVar15;
        local_68 = puVar14;
        local_50 = lVar1;
        if ((undefined8 *****)*local_78 != &local_80) goto LAB_140027a44;
        ppppuVar6[1] = local_78;
        *ppppuVar6 = &local_80;
        *local_78 = ppppuVar6;
        local_78 = ppppuVar6;
      }
LAB_140027840:
      pppuVar11 = (undefined8 ***)*pppuVar11;
    } while (pppuVar11 != (undefined8 ***)(param_2 + 0x60));
    if (puVar14 == (undefined4 *)0x0) {
LAB_14002787b:
      _Dst = local_58;
      goto LAB_14002787f;
    }
    uVar5 = Feature_4063646010__private_IsEnabledDeviceUsageNoInline();
    uVar13 = uStack_6c;
    uVar15 = uVar15 + uVar3;
    if ((int)uVar5 == 0) {
      if (param_4 < uVar15 + uStack_6c) goto LAB_14002787b;
    }
    else if ((uVar15 < uVar3) || (local_70 < uVar15)) goto LAB_14002787b;
    _Dst = (uint *)((ulonglong)uStack_6c + param_5);
    local_58 = _Dst;
    memmove(_Dst,local_68,(ulonglong)uVar15);
    uVar10 = uVar15 + 7 & 0xfffffff8;
    uVar5 = Feature_4063646010__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar5 == 0) {
      uVar7 = param_4;
LAB_140027983:
      if (uVar7 < uVar10) goto LAB_140027985;
    }
    else {
      if (uVar15 <= uVar10) {
        uVar7 = local_70;
        goto LAB_140027983;
      }
LAB_140027985:
      uVar10 = uVar15;
    }
    memset((void *)((ulonglong)uVar15 + (longlong)_Dst),0,(ulonglong)(uVar10 - uVar15));
    uVar13 = uVar13 + uVar10;
    *_Dst = uVar10;
    uStack_6c = uVar13;
    uVar5 = Feature_4063646010__private_IsEnabledDeviceUsageNoInline();
    uVar10 = local_70 - uVar10;
    if ((int)uVar5 == 0) {
      uVar10 = local_70;
    }
    local_70 = uVar10;
    while ((undefined8 *****)local_80 != &local_80) {
      if (((undefined8 *****)*local_78 != &local_80) ||
         (ppppuVar6 = (undefined8 ****)local_78[1], (undefined8 ****)*ppppuVar6 != local_78))
      goto LAB_140027a44;
      *ppppuVar6 = &local_80;
      uVar7 = *(uint *)(local_78 + 3);
      if (*(uint *)(local_78 + 3) == 0) {
        *(uint *)(local_78 + 3) = uVar15;
        uVar7 = uVar15;
      }
      *(int *)((longlong)local_78[2] + 0x34) = *(int *)((longlong)local_78[2] + 0x34) + uVar7;
      *(int *)(local_78[2] + 6) = *(int *)(local_78[2] + 6) - *(int *)(local_78 + 3);
      if (*(uint *)(local_78[2] + 6) < uVar3) {
        *(undefined4 *)(local_78[2] + 6) = 0;
        local_88 = '\x01';
        *(undefined4 *)((longlong)local_78[2] + 0x34) = 0;
      }
      local_78 = ppppuVar6;
      ExFreeToPagedLookasideList(&DAT_14000d5c0);
    }
    if (local_88 != '\0') {
LAB_14002787f:
      *param_6 = uStack_6c;
      puVar9 = auStack_b8;
      if (uStack_6c != 0) {
        *param_7 = _Dst;
        puVar9 = auStack_b8;
      }
LAB_140027893:
      *(undefined8 *)(puVar9 + -8) = 0x14002789c;
      BfFreeEnumerationConflictList((longlong *)&local_80);
      return uVar8;
    }
  } while( true );
LAB_140027a44:
  pcVar2 = (code *)swi(0x29);
  (*pcVar2)(3);
  puVar9 = auStack_b0;
LAB_140027a4b:
  uVar8 = 0xc000009a;
  goto LAB_140027893;
}



===== BfPreDirectoryControl @ 140027a60 =====

int BfPreDirectoryControl(longlong param_1,longlong param_2)

{
  byte bVar1;
  undefined4 uVar2;
  undefined8 *puVar3;
  short *psVar4;
  undefined8 *****pppppuVar5;
  code *pcVar6;
  bool bVar7;
  undefined8 *****pppppuVar8;
  int iVar9;
  int extraout_EAX;
  ulonglong uVar10;
  undefined8 uVar11;
  int iVar12;
  uint uVar13;
  undefined8 *puVar14;
  longlong lVar15;
  undefined1 *puVar16;
  undefined2 uVar17;
  longlong lVar18;
  uint uVar19;
  longlong lVar20;
  byte local_res20;
  undefined1 auStackY_f8 [8];
  undefined1 auStackY_f0 [24];
  undefined1 uVar21;
  char local_a7;
  char local_a6 [6];
  undefined8 *****local_a0;
  longlong local_98;
  uint local_90;
  int local_8c;
  int local_88;
  undefined1 local_84 [4];
  uint local_80;
  longlong local_78;
  undefined8 *****local_70;
  undefined8 *****local_68;
  int local_60;
  uint local_5c;
  longlong local_58;
  longlong local_50;
  int local_48;
  int local_44;
  longlong local_40;
  int *local_38;
  undefined8 local_30;
  
  iVar9 = 0;
  local_8c = 1;
  local_5c = 0;
  uVar19 = 0;
  local_80 = 0;
  local_60 = 0;
  lVar20 = 0;
  local_78 = 0;
  local_38 = &local_60;
  local_a0 = &local_70;
  local_68 = &local_70;
  local_70 = &local_70;
  local_a7 = '\0';
  local_a6[0] = '\0';
  lVar15 = *(longlong *)(param_1 + 0x10);
  local_res20 = *(byte *)(lVar15 + 6);
  local_90 = *(uint *)(lVar15 + 0x18);
  local_58 = *(longlong *)(lVar15 + 0x38);
  local_40 = *(longlong *)(lVar15 + 0x38);
  local_50 = *(longlong *)(lVar15 + 0x40);
  local_88 = *(int *)(lVar15 + 0x28);
  local_44 = local_88;
  if (0x10000 < local_90) {
    local_90 = 0x10000;
  }
  if (*(longlong *)(lVar15 + 8) != 0) {
    if (*(char *)(lVar15 + 5) == '\x01') {
      switch(local_88) {
      case 1:
      case 2:
      case 3:
      case 0xc:
      case 0x25:
      case 0x26:
      case 0x3c:
      case 0x3f:
      case 0x4e:
      case 0x4f:
      case 0x50:
      case 0x51:
        goto switchD_140027b66_caseD_1;
      case 4:
      case 5:
      case 6:
      case 7:
      case 8:
      case 9:
      case 10:
      case 0xb:
      case 0xd:
      case 0xe:
      case 0xf:
      case 0x10:
      case 0x11:
      case 0x12:
      case 0x13:
      case 0x14:
      case 0x15:
      case 0x16:
      case 0x17:
      case 0x18:
      case 0x19:
      case 0x1a:
      case 0x1b:
      case 0x1c:
      case 0x1d:
      case 0x1e:
      case 0x1f:
      case 0x20:
      case 0x21:
      case 0x22:
      case 0x23:
      case 0x24:
      case 0x27:
      case 0x28:
      case 0x29:
      case 0x2a:
      case 0x2b:
      case 0x2c:
      case 0x2d:
      case 0x2e:
      case 0x2f:
      case 0x30:
      case 0x31:
      case 0x32:
      case 0x33:
      case 0x34:
      case 0x35:
      case 0x36:
      case 0x37:
      case 0x38:
      case 0x39:
      case 0x3a:
      case 0x3b:
      case 0x3d:
      case 0x3e:
      case 0x40:
      case 0x41:
      case 0x42:
      case 0x43:
      case 0x44:
      case 0x45:
      case 0x46:
      case 0x47:
      case 0x48:
      case 0x49:
      case 0x4a:
      case 0x4b:
      case 0x4c:
      case 0x4d:
      default:
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0xc,0x30,
                              &WPP_4bfd87d54ffb3323a752b550f6ae0533_Traceguids,
                              "onecore\\base\\fs\\wci\\bindflt\\filter\\dirctrl.c",0x10,
                              (char)local_88);
          iVar9 = 0;
        }
        goto LAB_140028507;
      }
    }
    goto LAB_140028499;
  }
  goto LAB_140028507;
switchD_140027b66_caseD_1:
  iVar9 = BfGetSetDirectoryEnumerationHandleContext(param_2,local_a6,&local_78);
  lVar20 = local_78;
  if (iVar9 < 0) {
LAB_140028499:
    BfCheckAndSwitchTarget(param_1,param_2,(longlong *)0x0,(undefined1 *)0x0);
    iVar9 = extraout_EAX;
    if ((-1 < extraout_EAX) || ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
       ) goto LAB_140028507;
    uVar17 = 0x31;
    uVar21 = 0x1f;
  }
  else {
    if ((*(byte *)(*(longlong *)(param_1 + 0x10) + 6) & 1) != 0) {
      *(undefined4 *)(local_78 + 0x54) = 0;
      puVar14 = *(undefined8 **)(local_78 + 0x58);
      if (*(undefined8 **)(local_78 + 0x58) != (undefined8 *)0x0) {
        do {
          while( true ) {
            while (puVar3 = (undefined8 *)*puVar14, puVar3 != (undefined8 *)0x0) {
              *puVar14 = 0;
              puVar14 = puVar3;
            }
            puVar3 = (undefined8 *)puVar14[1];
            if (puVar3 == (undefined8 *)0x0) break;
            puVar14[1] = 0;
            puVar14 = puVar3;
          }
          uVar10 = puVar14[2];
          BfReturnedWalkContextAvlDeleteFunction((longlong)puVar14);
          puVar14 = (undefined8 *)(uVar10 & 0xfffffffffffffffc);
        } while (puVar14 != (undefined8 *)0x0);
      }
      *(undefined8 *)(lVar20 + 0x58) = 0;
      if (*(char *)(lVar20 + 0x70) != '\0') {
        BfFreeEnumerationContextList((longlong *)(lVar20 + 0x60));
        *(undefined1 *)(lVar20 + 0x70) = 0;
      }
    }
    uVar10 = BfGetMappingList(param_1,param_2,lVar20 + 0x58,&local_70,local_84);
    if ((((int)uVar10 + 0x80000000U & 0x80000000) == 0) && ((int)uVar10 != -0x3fffffc6))
    goto LAB_140028499;
    bVar7 = true;
    for (puVar14 = *(undefined8 **)(lVar20 + 0x60); puVar14 != (undefined8 *)(lVar20 + 0x60);
        puVar14 = (undefined8 *)*puVar14) {
      if (*(int *)(puVar14 + 6) != 0) {
        bVar7 = false;
        break;
      }
    }
    if ((((undefined8 ******)local_70 == &local_70) && (bVar7)) &&
       ((*(uint *)(lVar20 + 0x50) & 1) == 0)) goto LAB_140028499;
    lVar15 = *(longlong *)(param_2 + 0x20);
    local_98 = lVar20;
    psVar4 = *(short **)(lVar15 + 0x18);
    if (((psVar4 == (short *)0x0) || (*psVar4 != 0x6431)) ||
       ((lVar20 == 0 && (iVar9 = FltGetStreamHandleContext(), iVar9 < 0)))) {
LAB_140027cf5:
      lVar18 = *(longlong *)(param_2 + 0x18);
      lVar15 = *(longlong *)(param_2 + 0x20);
    }
    else {
      bVar1 = *(byte *)(local_98 + 0x50);
      if (lVar20 == 0) {
        FltReleaseContext();
      }
      if ((bVar1 & 1) == 0) goto LAB_140027cf5;
      lVar18 = *(longlong *)(lVar15 + 0x20);
      lVar15 = *(longlong *)(lVar18 + 8);
      lVar18 = *(longlong *)(lVar18 + 0x10);
    }
    if ((undefined8 ******)local_70 != &local_70) {
      uVar11 = BfCreateEnumerationContext(0,0,0,0,local_90,lVar20);
      iVar9 = (int)uVar11;
      if (iVar9 < 0) goto LAB_140028507;
    }
    iVar9 = BfSetupEnumerationContexts
                      (param_1,*(longlong *)(param_2 + 0x18),*(longlong *)(param_2 + 0x20),lVar18,
                       lVar15,local_90,lVar20);
    lVar15 = local_50;
    uVar13 = local_90;
    if (-1 < iVar9) {
      if (local_50 == 0) {
        ProbeForRead(local_58,local_90,1);
      }
      else {
        iVar9 = FltLockUserBuffer(param_1);
        if (iVar9 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_140027e9d;
          uVar17 = 0x29;
          uVar21 = 0x6f;
          goto LAB_1400284d2;
        }
        if ((*(byte *)(lVar15 + 10) & 5) == 0) {
          local_40 = MmMapLockedPagesSpecifyCache(lVar15,0,1,0);
        }
        else {
          local_40 = *(longlong *)(lVar15 + 0x18);
        }
        local_58 = local_40;
        if (local_40 == 0) {
          iVar9 = -0x3fffffe9;
          iVar12 = -0x3fffffe9;
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0xc,0x2a,
                                &WPP_4bfd87d54ffb3323a752b550f6ae0533_Traceguids,
                                "onecore\\base\\fs\\wci\\bindflt\\filter\\dirctrl.c",0x78,0x17);
            iVar12 = 1;
            goto LAB_14002850d;
          }
          goto LAB_140027ea3;
        }
        uVar13 = local_90;
      }
      while (local_60 + uVar19 < uVar13) {
        if ((local_70 != local_a0) && (*(int *)(*(longlong *)(lVar20 + 0x60) + 0x30) == 0)) {
          BfConvertWalkContextToDirectoryEnumeration
                    ((longlong *)&local_70,local_88,
                     *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x20),lVar20,
                     *(longlong *)(lVar20 + 0x60),&local_a7);
        }
        local_50 = CONCAT44(local_50._4_4_,*(undefined4 *)(*(longlong *)(param_1 + 0x10) + 0x30));
        local_30 = *(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x20);
        iVar9 = 0;
        for (puVar14 = *(undefined8 **)(lVar20 + 0x60); puVar14 != (undefined8 *)(lVar20 + 0x60);
            puVar14 = (undefined8 *)*puVar14) {
          if ((*(int *)(puVar14 + 6) == 0) && (puVar14[4] != 0)) {
            uVar11 = puVar14[8];
            uVar2 = *(undefined4 *)(puVar14 + 7);
            local_98 = 0;
            iVar9 = FltAllocateCallbackData(puVar14[5],puVar14[4],&local_98);
            if (-1 < iVar9) {
              *(undefined1 *)(*(longlong *)(local_98 + 0x10) + 4) = 0xc;
              *(undefined1 *)(*(longlong *)(local_98 + 0x10) + 5) = 1;
              *(undefined4 *)(*(longlong *)(local_98 + 0x10) + 0x18) = uVar2;
              *(int *)(*(longlong *)(local_98 + 0x10) + 0x28) = local_88;
              *(undefined8 *)(*(longlong *)(local_98 + 0x10) + 0x20) = local_30;
              *(undefined4 *)(*(longlong *)(local_98 + 0x10) + 0x30) = (undefined4)local_50;
              *(undefined8 *)(*(longlong *)(local_98 + 0x10) + 0x38) = uVar11;
              *(undefined8 *)(*(longlong *)(local_98 + 0x10) + 0x40) = 0;
              *(byte *)(*(longlong *)(local_98 + 0x10) + 6) = local_res20;
              FltPerformSynchronousIo(local_98);
              iVar9 = *(int *)(local_98 + 0x18);
              *(undefined4 *)(puVar14 + 6) = *(undefined4 *)(local_98 + 0x20);
            }
            FltFreeCallbackData(local_98);
            if (((iVar9 < 0) && (1 < iVar9 + 0x7ffffffbU)) && (iVar9 != -0x3ffffff1)) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0xc,0x27,
                                    &WPP_4bfd87d54ffb3323a752b550f6ae0533_Traceguids,
                                    "onecore\\base\\fs\\wci\\bindflt\\filter\\dirctrl.c",0x4f,
                                    (char)iVar9);
              }
              break;
            }
            *(undefined4 *)((longlong)puVar14 + 0x34) = 0;
          }
        }
        uVar19 = local_80;
        if (((iVar9 < 0) && (1 < iVar9 + 0x7ffffffbU)) && (iVar9 != -0x3ffffff1)) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar17 = 0x2c;
            uVar21 = 0xb6;
LAB_1400280f3:
            WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0xc,uVar17,
                                &WPP_4bfd87d54ffb3323a752b550f6ae0533_Traceguids,
                                "onecore\\base\\fs\\wci\\bindflt\\filter\\dirctrl.c",uVar21,
                                (char)iVar9);
          }
LAB_140028115:
          iVar12 = local_8c;
          goto LAB_14002850d;
        }
        uVar11 = BfMergeEnumerationContexts
                           (local_88,lVar20,local_res20 & 2,local_90 - local_80,
                            (ulonglong)local_80 + local_58,&local_5c,&local_38);
        iVar9 = (int)uVar11;
        local_48 = iVar9;
        if (iVar9 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar17 = 0x2e;
            uVar21 = 0xd1;
            goto LAB_1400280f3;
          }
          goto LAB_140028115;
        }
        if (local_5c == 0) break;
        uVar19 = uVar19 + local_5c;
        local_80 = uVar19;
        if ((local_res20 & 2) != 0) break;
        local_res20 = local_res20 & 0xfe;
        uVar13 = local_90;
      }
      if (local_38 != (int *)0x0) {
        *local_38 = 0;
      }
      iVar12 = *(int *)(lVar20 + 0x54) + uVar19;
      *(int *)(lVar20 + 0x54) = iVar12;
      if (local_a7 == '\0') {
        if (uVar19 == 0) {
          iVar9 = -0x3ffffff1;
          if (iVar12 != 0) {
            iVar9 = -0x7ffffffa;
          }
        }
        else {
          iVar9 = 0;
        }
      }
      else {
        iVar9 = -0x7ffffffb;
      }
      *(int *)(param_1 + 0x18) = iVar9;
      *(ulonglong *)(param_1 + 0x20) = (ulonglong)uVar19;
      iVar12 = 4;
      goto LAB_14002850d;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
LAB_140027e9d:
      iVar12 = iVar9;
LAB_140027ea3:
      iVar9 = iVar12;
      iVar12 = 1;
      goto LAB_14002850d;
    }
    uVar17 = 0x28;
    uVar21 = 0x5f;
  }
LAB_1400284d2:
  WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0xc,uVar17,
                      &WPP_4bfd87d54ffb3323a752b550f6ae0533_Traceguids,
                      "onecore\\base\\fs\\wci\\bindflt\\filter\\dirctrl.c",uVar21,(char)iVar9);
LAB_140028507:
  iVar12 = 1;
LAB_14002850d:
  puVar16 = auStackY_f8;
  if ((iVar12 != 4) && (iVar9 < 0)) {
    *(int *)(param_1 + 0x18) = iVar9;
    *(undefined8 *)(param_1 + 0x20) = 0;
    iVar12 = 4;
  }
  do {
    pppppuVar8 = local_68;
    if (local_70 == local_a0) {
LAB_140028576:
      if (puVar16[0x52] != '\0') {
        *(undefined8 *)(puVar16 + -8) = 0x140028590;
        KeSetEvent(lVar20 + 0x80,0,0);
      }
      if (lVar20 != 0) {
        *(undefined8 *)(puVar16 + -8) = 0x1400285a4;
        FltReleaseContext(lVar20);
      }
      return iVar12;
    }
    pppppuVar5 = (undefined8 *****)local_68[1];
    if (((undefined8 *****)*local_68 != local_a0) || ((undefined8 *****)*pppppuVar5 != local_68)) {
      pcVar6 = (code *)swi(0x29);
      (*pcVar6)(3);
      puVar16 = auStackY_f0;
      goto LAB_140028576;
    }
    *pppppuVar5 = &local_70;
    local_68 = pppppuVar5;
    BfDereferenceMappingListEntry((longlong)pppppuVar8);
  } while( true );
}



===== BfGetOrCreateUser$filt$0 @ 1400285d0 =====

bool BfGetOrCreateUser_filt_0(void)

{
  char cVar1;
  
  cVar1 = ExGetPreviousMode();
  return cVar1 == '\x01';
}



===== entry @ 140029010 =====

void entry(undefined8 *******param_1,undefined8 param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 140029044 =====

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



===== DriverEntry @ 140029078 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(undefined8 *******param_1,undefined8 param_2)

{
  int iVar1;
  ulonglong uVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined2 uVar5;
  bool bVar6;
  undefined8 ***********local_res18;
  undefined8 in_stack_ffffffffffffffa0;
  undefined4 uVar7;
  undefined1 uVar8;
  ulonglong in_stack_ffffffffffffffa8;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 *local_28;
  undefined8 uStack_20;
  undefined8 ************local_18;
  ulonglong local_10;
  
  uVar7 = (undefined4)((ulonglong)in_stack_ffffffffffffffa0 >> 0x20);
  local_38 = 0;
  uStack_30 = 0;
  local_28 = (undefined8 *)0x0;
  uStack_20 = 0;
  local_18 = (undefined8 ************)0x0;
  local_10 = local_10 & 0xffffffff00000000;
  local_48 = 0;
  uStack_40 = 0;
  local_res18 = (undefined8 ************)0x0;
  wil_InitializeFeatureStaging();
  BfTelemetryAndTracingInit(param_1,param_2);
  _DAT_14000d250 = 0;
  _DAT_14000d248 = 1;
  _DAT_14000d258 = 0;
  KeInitializeEvent(&DAT_14000d260,1,0);
  in_stack_ffffffffffffffa8 = in_stack_ffffffffffffffa8 & 0xffffffffffff0000;
  ExInitializePagedLookasideList
            (&DAT_14000d340,0,0,0,0x88,CONCAT44(uVar7,0x63704642),in_stack_ffffffffffffffa8);
  in_stack_ffffffffffffffa8 = in_stack_ffffffffffffffa8 & 0xffffffffffff0000;
  ExInitializeNPagedLookasideList
            (&DAT_14000d3c0,0,0,0x200,0x38,0x636e4642,in_stack_ffffffffffffffa8);
  in_stack_ffffffffffffffa8 = in_stack_ffffffffffffffa8 & 0xffffffffffff0000;
  ExInitializePagedLookasideList(&DAT_14000d440,0,0,0,0x100,0x65644642,in_stack_ffffffffffffffa8);
  in_stack_ffffffffffffffa8 = in_stack_ffffffffffffffa8 & 0xffffffffffff0000;
  ExInitializePagedLookasideList(&DAT_14000d4c0,0,0,0,0x48,0x65644642,in_stack_ffffffffffffffa8);
  in_stack_ffffffffffffffa8 = in_stack_ffffffffffffffa8 & 0xffffffffffff0000;
  ExInitializePagedLookasideList(&DAT_14000d540,0,0,0,0x10000,0x65644642,in_stack_ffffffffffffffa8);
  ExInitializePagedLookasideList
            (&DAT_14000d5c0,0,0,0,0x20,0x65644642,in_stack_ffffffffffffffa8 & 0xffffffffffff0000);
  uVar2 = Feature_Servicing_BindfltUnloadDisabled__private_IsEnabledDeviceUsageNoInline();
  bVar6 = (int)uVar2 != 0;
  if (bVar6) {
    _DAT_14000d650 = 0x902030070;
    puRam000000014000d658 = &ContextRegistration;
    _DAT_14000d660 = &Callbacks;
    _DAT_14000d670 = BfInstanceSetup;
    pcRam000000014000d678 = BfInstanceQueryTeardown;
    _DAT_14000d690 = BfGenerateFileNameCallback;
    uRam000000014000d698 = 0;
    _DAT_14000d680 = BfInstanceTeardownStart;
    pcRam000000014000d688 = BfInstanceTeardownComplete;
    _DAT_14000d6b0 = 0x40025bd0;
    uRam000000014000d6b4 = 1;
    uRam000000014000d6b8 = 0;
    uRam000000014000d6bc = 0;
    _DAT_14000d6a0 = 0;
    uRam000000014000d6a8 = 0;
    _DAT_14000d668 = 0;
  }
  puVar3 = (undefined8 *)&DAT_14000d650;
  if (!bVar6) {
    puVar3 = (undefined8 *)&FilterRegistration;
  }
  puVar4 = &g_BindFltState;
  iVar1 = FltRegisterFilter();
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400294ed;
    uVar5 = 10;
    uVar8 = 0xcd;
  }
  else {
    McGenEventRegister_EtwRegister();
    RtlInitUnicodeString(&local_48,L"\\BindFltPort");
    puVar3 = (undefined8 *)0x1f0001;
    param_1 = &local_res18;
    iVar1 = FltBuildDefaultSecurityDescriptor();
    if (iVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400294ed;
      uVar5 = 0xb;
      uVar8 = 0xe0;
    }
    else {
      local_28 = &local_48;
      puVar4 = &local_38;
      puVar3 = &DAT_14000d288;
      local_18 = (undefined8 ************)local_res18;
      local_38 = CONCAT44(local_38._4_4_,0x30);
      uStack_30 = 0;
      uStack_20 = CONCAT44(uStack_20._4_4_,0x240);
      local_10 = 0;
      iVar1 = FltCreateCommunicationPort
                        (g_BindFltState,&DAT_14000d288,puVar4,0,BfPortConnect,BfPortDisconnect,
                         BfPortMessage,1000);
      param_1 = local_res18;
      FltFreeSecurityDescriptor();
      if (iVar1 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400294ed;
        uVar5 = 0xc;
        uVar8 = 0xf6;
      }
      else {
        puVar3 = (undefined8 *)&DAT_14000d290;
        param_1 = (undefined8 ************)0x0;
        iVar1 = PsAllocSiloContextSlot();
        if (iVar1 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_1400294ed;
          uVar5 = 0xd;
          uVar8 = 0xfd;
        }
        else {
          ExInitializeResourceLite(&DAT_14000d2a8);
          _DAT_14000d2a0 = &DAT_14000d298;
          DAT_14000d298 = &DAT_14000d298;
          param_1 = g_BindFltState;
          iVar1 = FltStartFiltering();
          if (-1 < iVar1) {
            if ((Microsoft_Windows_Containers_BindFltEnableBits & 2) == 0) {
              return iVar1;
            }
            McTemplateK0_EtwWriteTransfer(param_1,&BindFltDriverEntrySuccess,puVar4);
            return iVar1;
          }
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_1400294ed;
          uVar5 = 0xe;
          uVar8 = 8;
        }
      }
    }
  }
  puVar4 = (undefined8 *)0x1;
  puVar3 = (undefined8 *)CONCAT71((int7)((ulonglong)puVar3 >> 8),2);
  param_1 = *(undefined8 ********)(WPP_GLOBAL_Control + 0x40);
  WPP_RECORDER_SF_sDd(param_1,2,1,uVar5,&WPP_59754cb100fb33f1965e7b014742173a_Traceguids,
                      "onecore\\base\\fs\\wci\\bindflt\\filter\\bindflt.c",uVar8,(char)iVar1);
LAB_1400294ed:
  if ((Microsoft_Windows_Containers_BindFltEnableBits & 1) != 0) {
    McTemplateK0d_EtwWriteTransfer(param_1,puVar3,puVar4,iVar1);
  }
  ExDeletePagedLookasideList(&DAT_14000d340);
  ExDeleteNPagedLookasideList(&DAT_14000d3c0);
  ExDeletePagedLookasideList(&DAT_14000d440);
  ExDeletePagedLookasideList(&DAT_14000d4c0);
  ExDeletePagedLookasideList(&DAT_14000d540);
  ExDeletePagedLookasideList(&DAT_14000d5c0);
  if (DAT_14000d288 != 0) {
    FltCloseCommunicationPort();
  }
  if (g_BindFltState != (undefined8 ************)0x0) {
    FltUnregisterFilter();
  }
  BfTelemetryAndTracingCleanup();
  wil_UninitializeFeatureStaging();
  return iVar1;
}



===== wil_InitializeFeatureStaging @ 1400295e4 =====

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



===== wil_details_PopulateInitialConfiguredFeatureStates @ 1400296d4 =====

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



===== BfTelemetryAndTracingInit @ 1400297bc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void BfTelemetryAndTracingInit(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined1 auStackY_68 [32];
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  _DAT_14000d6e8 = 1;
  _WPP_MAIN_CB = 0;
  DAT_14000d6c8 = &WPP_ThisDir_CTLGUID_BindFltTrace;
  DAT_14000d6d0 = 0;
  _DAT_14000d6e0 = 0;
  _DAT_14000d700 = 0;
  _DAT_14000d708 = 0;
  WppLoadTracingSupport();
  _DAT_14000d6e0 = 0;
  WppInitKm(param_1,param_2);
  local_28 = 0x100000010;
  uStack_20 = 0x200000002;
  imp_WppRecorderConfigure(WPP_GLOBAL_Control,&local_28);
  _BfTraceRecorder = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
  iVar1 = TraceLoggingRegisterEx_EtwRegister_EtwSetInformation();
  if ((iVar1 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,10,
                        &WPP_cdf94b27e759309871abc3849a751d26_Traceguids,
                        "onecore\\base\\fs\\wci\\bindflt\\filter\\telemetry.c",0x57,(char)iVar1);
  }
  return;
}


