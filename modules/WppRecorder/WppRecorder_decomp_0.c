
===== _tlgCreate1Sz_char @ 140001008 =====

void _tlgCreate1Sz_char(longlong *param_1,char *param_2)

{
  int iVar1;
  longlong lVar2;
  
  if (param_2 == (char *)0x0) {
    param_2 = "";
    iVar1 = 1;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (param_2[lVar2] != '\0');
    iVar1 = (int)lVar2 + 1;
  }
  *(undefined4 *)((longlong)param_1 + 0xc) = 0;
  *param_1 = (longlong)param_2;
  *(int *)(param_1 + 1) = iVar1;
  return;
}



===== _tlgKeywordOn @ 14000103c =====

undefined1 _tlgKeywordOn(longlong param_1,ulonglong param_2)

{
  undefined1 uVar1;
  
  uVar1 = 0;
  if ((param_2 == 0) ||
     (((*(ulonglong *)(param_1 + 0x10) & param_2) != 0 &&
      ((*(ulonglong *)(param_1 + 0x18) & param_2) == *(ulonglong *)(param_1 + 0x18))))) {
    uVar1 = 1;
  }
  return uVar1;
}



===== _tlgWriteTransfer_EtwWriteTransfer @ 140001068 =====

void _tlgWriteTransfer_EtwWriteTransfer
               (undefined8 param_1,byte *param_2,undefined8 param_3,undefined8 param_4,
               undefined4 param_5,undefined8 *param_6)

{
  int local_18;
  uint local_14;
  undefined8 local_10;
  
  local_18 = (uint)*param_2 << 0x18;
  local_14 = (uint)*(ushort *)(param_2 + 1);
  local_10 = *(undefined8 *)(param_2 + 3);
  *param_6 = PTR_DAT_14000d048;
  *(uint *)(param_6 + 1) = (uint)*(ushort *)PTR_DAT_14000d048;
  param_6[2] = param_2 + 0xb;
  *(undefined4 *)((longlong)param_6 + 0xc) = 2;
  *(uint *)(param_6 + 3) = (uint)*(ushort *)(param_2 + 0xb);
  *(undefined4 *)((longlong)param_6 + 0x1c) = 1;
  EtwWriteTransfer(DAT_14000d060,&local_18,0,0,param_5,param_6);
  return;
}



===== imp_WppRecorderConfigure @ 140001120 =====

void imp_WppRecorderConfigure(longlong param_1,uint *param_2)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  undefined1 *puVar4;
  uint uVar5;
  uint uVar6;
  
                    /* 0x1120  6  imp_WppRecorderConfigure */
  lVar3 = WppAutoLogGetDriverContext(param_1);
  if ((lVar3 != 0) && (lVar1 = *(longlong *)(lVar3 + 200), lVar1 != 0)) {
    *(undefined1 *)(lVar3 + 0x30) = 1;
    uVar5 = *param_2;
    if ((uVar5 - 8 & 0xfffffff7) != 0) {
      uVar5 = 8;
    }
    if ((char)param_2[1] == '\0') {
      iVar2 = KeWaitForSingleObject(&WppRecorderGlobals);
      if (-1 < iVar2) {
        *(undefined1 *)(*(longlong *)(lVar3 + 200) + 0x62) = 1;
        WppAutoLogDeleteLog(*(longlong *)(lVar3 + 200));
        puVar4 = WppAutoLogCreateLog(lVar3,0,0,(uint *)0x0);
        if (puVar4 == (undefined1 *)0x0) {
          DbgPrint("Error: failed to re-allocate memory for WPP recorder\n");
          WppAutoLogpUnregisterBugCheckCallbackHelper(lVar3 + 0x38);
          ExFreePoolWithTag(lVar3,0x674c5057);
        }
        else {
          *(undefined1 **)(lVar3 + 200) = puVar4;
        }
        *(undefined1 **)(param_1 + 0x40) = puVar4;
        KeSetEvent(&WppRecorderGlobals,0,0);
      }
    }
    else if ((*(int *)(lVar1 + 0x9c) == 0) && (*(int *)(lVar1 + 0x8c) == 0)) {
      if (uVar5 < 9) {
        uVar5 = 2;
        uVar6 = 2;
      }
      else {
        uVar5 = param_2[2];
        uVar6 = param_2[3];
      }
      WppAutoLogpConfigureTimeStamp(uVar5,uVar6,lVar1);
    }
  }
  return;
}



===== WppAutoLogStop @ 140001270 =====

void WppAutoLogStop(longlong param_1)

{
  undefined8 *puVar1;
  int iVar2;
  longlong lVar3;
  longlong local_res18 [2];
  
                    /* 0x1270  4  WppAutoLogStop */
  lVar3 = WppAutoLogGetDriverContext(param_1);
  if (lVar3 != 0) {
    local_res18[0] = lVar3;
    if (*(longlong *)(lVar3 + 200) != 0) {
      *(undefined8 *)(param_1 + 0x40) = 0;
      WppAutoLogpUnregisterBugCheckCallbackHelper(lVar3 + 0x38);
      for (puVar1 = *(undefined8 **)(lVar3 + 0xb8); (undefined8 *)(lVar3 + 0xb8) != puVar1;
          puVar1 = (undefined8 *)*puVar1) {
        if ((*(char *)((longlong)puVar1 + 0x42) == '\0') &&
           (puVar1 + -4 != *(longlong **)(lVar3 + 200))) {
          WppAutoLogMarkLogDeleted(puVar1 + -4);
        }
      }
      WppAutoLogMarkLogDeleted(*(longlong **)(lVar3 + 200));
      if ((DAT_14000a218 != 0) &&
         (iVar2 = KeWaitForSingleObject(&DAT_14000a228,0,0,0,0), -1 < iVar2)) {
        WppAutoLogpMoveContextToRecentlyUnloadedList(lVar3,local_res18);
        KeSetEvent(&DAT_14000a228,0,0);
        lVar3 = local_res18[0];
      }
    }
    if (lVar3 != 0) {
      WppAutoLogDeleteAutoLogContext(lVar3);
    }
  }
  return;
}



===== imp_WppRecorderLogDelete @ 140001380 =====

void imp_WppRecorderLogDelete(undefined8 param_1,longlong *param_2)

{
                    /* 0x1380  13  imp_WppRecorderLogDelete */
  if (((param_2 != (longlong *)0x0) && (*(char *)((longlong)param_2 + 0x62) == '\0')) &&
     (*(longlong **)(param_2[0xf] + 200) != param_2)) {
    WppAutoLogMarkLogDeleted(param_2);
  }
  return;
}



===== WppAutoLogMarkLogDeleted @ 1400013b0 =====

void WppAutoLogMarkLogDeleted(longlong *param_1)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  longlong lVar4;
  code *pcVar5;
  undefined1 uVar6;
  longlong *plVar7;
  longlong *plVar8;
  
  lVar2 = param_1[0xf];
  plVar7 = (longlong *)0x0;
  *(undefined1 *)((longlong)param_1 + 0x62) = 1;
  if (*(int *)(lVar2 + 0x14c) == 0) {
    plVar7 = param_1;
  }
  else {
    uVar6 = KeAcquireSpinLockRaiseToDpc(lVar2 + 0xb0);
    plVar1 = (longlong *)(lVar2 + 0x138);
    plVar8 = param_1 + 0xd;
    plVar3 = *(longlong **)(lVar2 + 0x140);
    if ((longlong *)*plVar3 != plVar1) {
LAB_140001489:
      pcVar5 = (code *)swi(0x29);
      (*pcVar5)(3,plVar3,uVar6);
      pcVar5 = (code *)swi(3);
      (*pcVar5)();
      return;
    }
    *plVar8 = (longlong)plVar1;
    param_1[0xe] = (longlong)plVar3;
    *plVar3 = (longlong)plVar8;
    *(longlong **)(lVar2 + 0x140) = plVar8;
    if (*(uint *)(lVar2 + 0x148) < *(uint *)(lVar2 + 0x14c)) {
      *(uint *)(lVar2 + 0x148) = *(uint *)(lVar2 + 0x148) + 1;
    }
    else {
      plVar7 = (longlong *)*plVar1;
      if (((longlong *)plVar7[1] != plVar1) ||
         (lVar4 = *plVar7, *(longlong **)(lVar4 + 8) != plVar7)) goto LAB_140001489;
      *plVar1 = lVar4;
      plVar7 = plVar7 + -0xd;
      *(longlong **)(lVar4 + 8) = plVar1;
    }
    KeReleaseSpinLock(lVar2 + 0xb0,uVar6);
  }
  if (plVar7 != (longlong *)0x0) {
    WppAutoLogDeleteLog((longlong)plVar7);
  }
  return;
}



===== imp_WppRecorderLogCreate @ 1400014a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 imp_WppRecorderLogCreate(longlong param_1,uint *param_2,undefined8 *param_3)

{
  longlong lVar1;
  undefined8 uVar2;
  char *pcVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  undefined1 auStack_78 [32];
  uint local_58 [2];
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  
                    /* 0x14a0  12  imp_WppRecorderLogCreate */
  local_28 = __security_cookie ^ (ulonglong)auStack_78;
  *param_3 = 0;
  local_58[0] = 0;
  local_58[1] = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  puVar5 = param_2;
  if ((*param_2 - 0x30 & 0xfffffff7) != 0) {
    uStack_50 = *(undefined8 *)(param_2 + 2);
    puVar5 = local_58;
    local_48 = *(undefined8 *)(param_2 + 4);
    uStack_40 = *(undefined8 *)(param_2 + 6);
    local_58[1] = (uint)((ulonglong)*(undefined8 *)param_2 >> 0x20);
    local_58[0] = 0x30;
    local_38 = *(undefined8 *)(param_2 + 8);
    uStack_30 = *(undefined8 *)(param_2 + 10);
  }
  lVar1 = WppAutoLogGetDriverContext(param_1);
  if (lVar1 == 0) {
    uVar2 = 0xc000009a;
    if (g_IsDllDisabled != '\0') {
      uVar2 = 0;
    }
  }
  else {
    uVar6 = puVar5[2];
    uVar4 = *(uint *)(lVar1 + 0x28);
    if ((*(uint *)(lVar1 + 0x28) <= uVar6) && (uVar4 = uVar6, *(uint *)(lVar1 + 0x2c) < uVar6)) {
      uVar4 = *(uint *)(lVar1 + 0x2c);
    }
    uVar6 = uVar4 >> 1;
    if (puVar5[3] <= uVar4 >> 1) {
      uVar6 = puVar5[3];
    }
    pcVar3 = WppAutoLogCreateLog(lVar1,uVar4,uVar6,puVar5);
    if (pcVar3 == (char *)0x0) {
      uVar2 = 0xc000009a;
    }
    else {
      RtlStringCbCopyNA(pcVar3,0x10,puVar5 + 8,(ulonglong)puVar5[7]);
      uVar2 = 0;
      pcVar3[0x18] = (char)puVar5[6];
      *(undefined8 *)(pcVar3 + 0x10) = *(undefined8 *)(puVar5 + 4);
      *param_3 = pcVar3;
    }
  }
  return uVar2;
}



===== imp_WppRecorderLogGetDefault @ 1400015b0 =====

undefined8 imp_WppRecorderLogGetDefault(longlong param_1)

{
  longlong lVar1;
  
                    /* 0x15b0  15  imp_WppRecorderLogGetDefault */
  lVar1 = WppAutoLogGetDriverContext(param_1);
  if (lVar1 == 0) {
    return 0;
  }
  return *(undefined8 *)(lVar1 + 200);
}



===== WppAutoLogGetDriverContext @ 1400015e0 =====

undefined8 WppAutoLogGetDriverContext(longlong param_1)

{
  if (*(longlong *)(param_1 + 0x40) == 0) {
    return 0;
  }
  return *(undefined8 *)(*(longlong *)(param_1 + 0x40) + 0x78);
}



===== WppAutoLogCreateLog @ 140001600 =====

undefined1 * WppAutoLogCreateLog(longlong param_1,int param_2,int param_3,uint *param_4)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  undefined1 uVar5;
  undefined1 *puVar6;
  uint uVar7;
  uint uVar8;
  
  if ((param_4 == (uint *)0x0) || (uVar8 = param_4[1], uVar8 == 0)) {
    uVar8 = 0x674c5057;
  }
  puVar6 = (undefined1 *)ExAllocatePool2(0x40,param_2 + 0xa8,uVar8);
  if (puVar6 != (undefined1 *)0x0) {
    *(longlong *)(puVar6 + 0x78) = param_1;
    *puVar6 = 0;
    *(uint *)(puVar6 + 0x1c) = uVar8;
    *(int *)(puVar6 + 0xa0) = param_2;
    puVar6[0x62] = 0;
    if ((param_4 == (uint *)0x0) || (*param_4 < 0x31)) {
      uVar8 = 2;
      uVar7 = 2;
    }
    else {
      uVar8 = param_4[0xc];
      uVar7 = param_4[0xd];
    }
    WppAutoLogpConfigureTimeStamp(uVar8,uVar7,(longlong)puVar6);
    *(int *)(puVar6 + 0x98) = param_2 - param_3;
    *(undefined4 *)(puVar6 + 0x9c) = 0;
    *(undefined1 **)(puVar6 + 0x90) = puVar6 + 0xa8;
    *(int *)(puVar6 + 0x88) = param_3;
    *(undefined1 **)(puVar6 + 0x80) = puVar6 + 0xa8 + (uint)(param_2 - param_3);
    *(undefined4 *)(puVar6 + 0x8c) = 0;
    uVar5 = KeAcquireSpinLockRaiseToDpc(param_1 + 0xb0);
    lVar2 = param_1 + 0xb8;
    plVar3 = *(longlong **)(param_1 + 0xc0);
    plVar1 = (longlong *)(puVar6 + 0x20);
    if (*plVar3 != lVar2) {
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)(3,lVar2,plVar3,uVar5);
      pcVar4 = (code *)swi(3);
      puVar6 = (undefined1 *)(*pcVar4)();
      return puVar6;
    }
    *plVar1 = lVar2;
    *(longlong **)(puVar6 + 0x28) = plVar3;
    *plVar3 = (longlong)plVar1;
    *(longlong **)(param_1 + 0xc0) = plVar1;
    *(short *)(param_1 + 0xa8) = *(short *)(param_1 + 0xa8) + 1;
    *(short *)(param_1 + 0xaa) = *(short *)(param_1 + 0xaa) + 1;
    *(undefined2 *)(puVar6 + 0x60) = *(undefined2 *)(param_1 + 0xa8);
    KeReleaseSpinLock(param_1 + 0xb0,uVar5);
    WppAutoLogpRegisterBugCheckCallbackHelper
              (*(longlong *)(puVar6 + 0x78),WppAutoLogpBugCheckCallbackForLog,
               (longlong)(puVar6 + 0x30));
  }
  return puVar6;
}



===== RtlStringCbCopyNA @ 140001790 =====

undefined8 RtlStringCbCopyNA(char *param_1,longlong param_2,undefined8 param_3,ulonglong param_4)

{
  undefined8 uVar1;
  
  if (param_2 - 1U < 0x7fffffff) {
    if (param_4 < 0x7fffffff) {
      uVar1 = RtlStringCopyWorkerA(param_1,param_2,param_3,param_3,param_4);
      return uVar1;
    }
    *param_1 = '\0';
  }
  return 0xc000000d;
}



===== WppAutoLogpConfigureTimeStamp @ 1400017d0 =====

void WppAutoLogpConfigureTimeStamp(int param_1,int param_2,longlong param_3)

{
  int iVar1;
  bool bVar2;
  bool bVar3;
  
  iVar1 = *(int *)(*(longlong *)(param_3 + 0x78) + 0x150);
  if (param_1 != 2) {
    iVar1 = param_1;
  }
  bVar3 = iVar1 == 1;
  bVar2 = false;
  if (bVar3) {
    bVar2 = *(int *)(*(longlong *)(param_3 + 0x78) + 0x154) == 1;
    *(bool *)(param_3 + 0xa4) = bVar3;
    if (param_2 != 2) {
      *(bool *)(param_3 + 0xa5) = param_2 == 1;
      return;
    }
  }
  else {
    *(bool *)(param_3 + 0xa4) = bVar3;
  }
  *(bool *)(param_3 + 0xa5) = bVar2;
  return;
}



===== WppAutoLogpRegisterBugCheckCallbackHelper @ 140001840 =====

void WppAutoLogpRegisterBugCheckCallbackHelper(longlong param_1,undefined8 param_2,longlong param_3)

{
  *(undefined1 *)(param_3 + 0x2c) = 0;
  KeRegisterBugCheckReasonCallback(param_3,param_2,2,param_1 + 0x68);
  return;
}



===== RtlStringCopyWorkerA @ 140001880 =====

undefined8
RtlStringCopyWorkerA
          (char *param_1,longlong param_2,undefined8 param_3,longlong param_4,longlong param_5)

{
  undefined8 uVar1;
  char *pcVar2;
  longlong lVar3;
  
  if (param_2 != 0) {
    lVar3 = param_4 - (longlong)param_1;
    do {
      if ((param_5 == 0) || (param_1[lVar3] == '\0')) break;
      *param_1 = param_1[lVar3];
      param_5 = param_5 + -1;
      param_1 = param_1 + 1;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  uVar1 = 0x80000005;
  pcVar2 = param_1 + -1;
  if (param_2 != 0) {
    uVar1 = 0;
    pcVar2 = param_1;
  }
  *pcVar2 = '\0';
  return uVar1;
}



===== RtlpImageNtHeader @ 1400018d0 =====

int * RtlpImageNtHeader(short *param_1)

{
  uint uVar1;
  int *piVar2;
  
  piVar2 = (int *)0x0;
  if (((longlong)param_1 - 1U < 0xfffffffffffffffe) && (*param_1 == 0x5a4d)) {
    uVar1 = *(uint *)(param_1 + 0x1e);
    if ((-1 < (int)uVar1) &&
       ((uVar1 < 0x10000000 &&
        (piVar2 = (int *)((longlong)(int)uVar1 + (longlong)param_1), *piVar2 != 0x4550)))) {
      piVar2 = (int *)0x0;
    }
  }
  return piVar2;
}



===== WppAutoLogDeleteLog @ 140001930 =====

void WppAutoLogDeleteLog(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  undefined1 uVar5;
  
  WppAutoLogpUnregisterBugCheckCallbackHelper(param_1 + 0x30);
  lVar1 = *(longlong *)(param_1 + 0x78);
  uVar5 = KeAcquireSpinLockRaiseToDpc(lVar1 + 0xb0);
  lVar2 = *(longlong *)(param_1 + 0x20);
  if ((*(longlong *)(lVar2 + 8) == param_1 + 0x20) &&
     (plVar3 = *(longlong **)(param_1 + 0x28), *plVar3 == param_1 + 0x20)) {
    *plVar3 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar3;
    KeReleaseSpinLock(lVar1 + 0xb0,uVar5);
    ExFreePoolWithTag(param_1,*(undefined4 *)(param_1 + 0x1c));
    return;
  }
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  pcVar4 = (code *)swi(3);
  (*pcVar4)();
  return;
}



===== imp_WppRecorderReplay @ 1400019c0 =====

/* WARNING: Removing unreachable block (ram,0x000140001c6b) */

void imp_WppRecorderReplay(longlong param_1,longlong param_2,int param_3)

{
  undefined8 *puVar1;
  char cVar2;
  undefined1 uVar3;
  int iVar4;
  longlong lVar5;
  char *pcVar6;
  char *pcVar7;
  char cVar8;
  char *pcVar9;
  char local_res18 [8];
  undefined8 uVar10;
  
                    /* 0x19c0  17  imp_WppRecorderReplay */
  if (param_3 == 0x40000000) {
    cVar8 = '\0';
    local_res18[0] = '\0';
    if (param_2 != 0) {
      uVar10 = 0;
      iVar4 = KeWaitForSingleObject(&WppRecorderGlobals,0,0,0);
      if (-1 < iVar4) {
        lVar5 = WppAutoLogGetDriverContext(param_1);
        if (((lVar5 != 0) && (*(longlong *)(lVar5 + 200) != 0)) && (*(char *)(lVar5 + 0xdc) != '\0')
           ) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_s(*(longlong *)(WPP_GLOBAL_Control + 0x40));
          }
          uVar3 = KeAcquireSpinLockRaiseToDpc(lVar5 + 0xb0);
          for (puVar1 = *(undefined8 **)(lVar5 + 0xb8); (undefined8 *)(lVar5 + 0xb8) != puVar1;
              puVar1 = (undefined8 *)*puVar1) {
            pcVar6 = WppAutoLogCreateLogSnapshot((char *)(puVar1 + -4),local_res18);
            cVar2 = local_res18[0];
            if (pcVar6 != (char *)0x0) {
              cVar8 = cVar8 + '\x01';
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_dscs(*(longlong *)(WPP_GLOBAL_Control + 0x40));
              }
              pcVar9 = pcVar6 + 0x90;
              pcVar7 = pcVar6;
              iVar4 = WppAutoLogSendRecordsToWpp(param_2,(longlong)pcVar6,(undefined8 *)pcVar9);
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_dd(*(longlong *)(WPP_GLOBAL_Control + 0x40),pcVar7,pcVar9,0xc,uVar10
                                   ,cVar8,(char)iVar4);
              }
              if ((cVar2 == '\0') && (*(int *)(pcVar6 + 0x88) != 0)) {
                pcVar9 = pcVar6 + 0x80;
                pcVar7 = pcVar6;
                iVar4 = WppAutoLogSendRecordsToWpp(param_2,(longlong)pcVar6,(undefined8 *)pcVar9);
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  WPP_RECORDER_SF_dd(*(longlong *)(WPP_GLOBAL_Control + 0x40),pcVar7,pcVar9,0xd,
                                     uVar10,cVar8,(char)iVar4);
                  goto LAB_140001b9a;
                }
              }
              else {
LAB_140001b9a:
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  WPP_RECORDER_SF_ds(*(longlong *)(WPP_GLOBAL_Control + 0x40));
                }
              }
              ExFreePoolWithTag(pcVar6,0x674c5057);
            }
          }
          KeReleaseSpinLock(lVar5 + 0xb0,uVar3);
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_sd(*(longlong *)(WPP_GLOBAL_Control + 0x40));
          }
        }
        KeSetEvent(&WppRecorderGlobals,0,0);
      }
    }
  }
  return;
}



===== imp_WppRecorderLogSetIdentifier @ 140001c90 =====

void imp_WppRecorderLogSetIdentifier(undefined8 param_1,char *param_2,undefined8 param_3)

{
                    /* 0x1c90  16  imp_WppRecorderLogSetIdentifier */
  if ((param_2 != (char *)0x0) && (param_2 != *(char **)(*(longlong *)(param_2 + 0x78) + 200))) {
    RtlStringCopyWorkerA(param_2,0x10,param_3,param_3,0x7ffffffe);
  }
  return;
}



===== WppAutoLogpMoveContextToRecentlyUnloadedList @ 140001cd0 =====

void WppAutoLogpMoveContextToRecentlyUnloadedList(longlong param_1,longlong *param_2)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  int iVar4;
  ushort uVar5;
  bool bVar6;
  
  uVar5 = 0;
  while( true ) {
    if (DAT_14000a222 <= uVar5) {
      plVar1 = (longlong *)(DAT_14000a218 + (ulonglong)DAT_14000a220 * 8);
      DAT_14000a220 = DAT_14000a220 + 1;
      lVar2 = *plVar1;
      *plVar1 = param_1;
      bVar6 = DAT_14000a222 <= DAT_14000a220;
      *param_2 = lVar2;
      if (bVar6) {
        DAT_14000a220 = 0;
      }
      return;
    }
    lVar2 = *(longlong *)((ulonglong)uVar5 * 8 + DAT_14000a218);
    if ((lVar2 != 0) &&
       (iVar4 = _stricmp((char *)(param_1 + 0x68),(char *)(lVar2 + 0x68)), lVar3 = DAT_14000a218,
       iVar4 == 0)) break;
    uVar5 = uVar5 + 1;
  }
  *param_2 = lVar2;
  *(longlong *)((ulonglong)uVar5 * 8 + lVar3) = param_1;
  return;
}



===== GetWppAutoLogRegistrySettings @ 140001da0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void GetWppAutoLogRegistrySettings
               (undefined8 *param_1,longlong param_2,int *param_3,undefined2 *param_4,
               undefined2 *param_5,longlong param_6)

{
  longlong lVar1;
  int iVar2;
  code *pcVar3;
  uint uVar4;
  uint uVar5;
  undefined1 auStack_378 [32];
  longlong *local_358;
  uint local_348;
  uint local_344;
  uint local_340 [4];
  undefined4 local_330;
  undefined4 local_32c;
  int local_328;
  undefined4 local_324;
  undefined4 local_320 [2];
  longlong local_318;
  undefined4 local_310;
  undefined4 local_30c;
  undefined4 local_308 [2];
  longlong local_300;
  undefined8 local_2f8;
  longlong lStack_2f0;
  undefined8 *local_2e8;
  undefined8 uStack_2e0;
  undefined8 local_2d8;
  ulonglong uStack_2d0;
  undefined8 local_2c8;
  wchar_t *local_2c0;
  undefined2 *local_2b8;
  undefined8 local_2b0;
  undefined8 uStack_2a8;
  undefined1 local_298 [8];
  undefined4 local_290;
  wchar_t *local_288;
  undefined4 *local_280;
  undefined4 local_278;
  uint *local_270;
  undefined4 local_268;
  undefined4 local_258;
  wchar_t *local_250;
  uint *local_248;
  undefined4 local_240;
  undefined4 *local_238;
  undefined4 local_230;
  undefined4 local_220;
  wchar_t *local_218;
  undefined4 *local_210;
  undefined4 local_208;
  uint *local_200;
  undefined4 local_1f8;
  undefined4 local_1e8;
  wchar_t *local_1e0;
  uint *local_1d8;
  undefined4 local_1d0;
  uint *local_1c8;
  undefined4 local_1c0;
  undefined4 local_1b0;
  wchar_t *local_1a8;
  uint *local_1a0;
  undefined4 local_198;
  uint *local_190;
  undefined4 local_188;
  undefined4 local_178;
  wchar_t *local_170;
  int *local_168;
  undefined4 local_160;
  undefined4 *local_158;
  undefined4 local_150;
  undefined4 local_140;
  wchar_t *local_138;
  uint *local_130;
  undefined4 local_128;
  undefined4 *local_120;
  undefined4 local_118;
  undefined4 local_108;
  wchar_t *local_100;
  undefined4 *local_f8;
  undefined4 local_f0;
  uint *local_e8;
  undefined4 local_e0;
  undefined4 local_d0;
  wchar_t *local_c8;
  undefined4 *local_c0;
  undefined4 local_b8;
  uint *local_b0;
  undefined4 local_a8;
  wchar_t local_68 [12];
  ulonglong local_50;
  
  local_50 = __security_cookie ^ (ulonglong)auStack_378;
  uVar4 = 0x100;
  local_2b8 = param_5;
  uVar5 = 0x2000;
  local_2d8 = 0;
  uStack_2d0 = uStack_2d0 & 0xffffffff00000000;
  builtin_wcsncpy(local_68,L"Parameters",0xb);
  local_2c0 = local_68;
  local_2f8 = 0;
  lStack_2f0 = 0;
  local_2c8 = 0x160014;
  local_348 = 1;
  local_310 = 1;
  local_340[0] = 0;
  local_30c = 1;
  local_32c = 0;
  local_330 = 0;
  local_340[2] = 0;
  local_340[3] = 0;
  local_328 = 1;
  local_308[0] = 2;
  local_344 = 2;
  local_340[1] = 2;
  local_324 = 2;
  local_320[0] = 2;
  local_318 = 0;
  local_300 = 0;
  local_2e8 = (undefined8 *)0x0;
  uStack_2e0 = 0;
  if (param_2 == 0) {
    local_2f8 = 0x30;
    lStack_2f0 = 0;
    uStack_2e0 = 0x240;
    local_2d8 = 0;
    uStack_2d0 = 0;
    local_2e8 = param_1;
    iVar2 = ZwOpenKey(&local_300,0x20019,&local_2f8);
    if (iVar2 < 0) goto LAB_1400022b7;
    lStack_2f0 = local_300;
    local_2e8 = &local_2c8;
    local_2f8 = CONCAT44(local_2f8._4_4_,0x30);
    uStack_2e0 = CONCAT44(uStack_2e0._4_4_,0x240);
    local_2d8 = 0;
    uStack_2d0 = 0;
    iVar2 = ZwOpenKey(&local_318,0x20019,&local_2f8);
  }
  else {
    local_358 = &local_318;
    iVar2 = IoOpenDriverRegistryKey(param_2,0,0x20019,0);
  }
  if (-1 < iVar2) {
    memset(local_298,0,0x230);
    lVar1 = local_318;
    local_290 = 0x120;
    local_288 = L"VerboseOn";
    local_280 = &local_330;
    local_270 = local_340;
    local_250 = L"LogPages";
    local_248 = &local_348;
    local_238 = &local_310;
    local_218 = L"ForceLogsInMiniDump";
    local_210 = &local_32c;
    local_200 = local_340;
    local_1e0 = L"WppRecorder_PerBufferMinBytes";
    local_1d8 = local_340 + 2;
    local_1c8 = local_340;
    local_1a8 = L"WppRecorder_PerBufferMaxBytes";
    local_1a0 = local_340 + 3;
    local_190 = local_340;
    local_170 = L"WppRecorder_ReplayEnabled";
    local_168 = &local_328;
    local_158 = &local_30c;
    local_138 = L"WppRecorder_RetainLastNDeletedLogs";
    local_130 = &local_344;
    local_120 = local_308;
    local_100 = L"WppRecorder_UseTimeStamp";
    local_f8 = &local_324;
    local_e8 = local_340 + 1;
    local_c8 = L"WppRecorder_PreciseTimeStamp";
    local_c0 = local_320;
    local_278 = 0x4000004;
    local_268 = 4;
    local_258 = 0x120;
    local_240 = 0x4000004;
    local_230 = 4;
    local_220 = 0x120;
    local_208 = 0x4000004;
    local_1f8 = 4;
    local_1e8 = 0x120;
    local_1d0 = 0x4000004;
    local_1c0 = 4;
    local_1b0 = 0x120;
    local_198 = 0x4000004;
    local_188 = 4;
    local_178 = 0x120;
    local_160 = 0x4000004;
    local_150 = 4;
    local_140 = 0x120;
    local_128 = 0x4000004;
    local_118 = 4;
    local_108 = 0x120;
    local_f0 = 0x4000004;
    local_e0 = 4;
    local_d0 = 0x120;
    local_b0 = local_340 + 1;
    local_b8 = 0x4000004;
    local_a8 = 4;
    local_2b0 = 0;
    uStack_2a8 = 0;
    RtlInitUnicodeString(&local_2b0,L"RtlQueryRegistryValuesEx");
    pcVar3 = (code *)MmGetSystemRoutineAddress(&local_2b0);
    local_358 = (longlong *)0x0;
    if (pcVar3 == (code *)0x0) {
      pcVar3 = RtlQueryRegistryValues_exref;
    }
    (*pcVar3)(0xc0000000,lVar1,local_298,0);
    if (local_348 < 0x11) {
      if (local_348 == 0) {
        local_348 = 1;
      }
    }
    else {
      local_348 = 0x10;
    }
    uVar4 = 0x100;
    if (local_340[2] != local_340[0]) {
      uVar4 = local_340[2];
    }
    uVar5 = 0x2000;
    if (local_340[3] != local_340[0]) {
      uVar5 = local_340[3];
    }
    if (uVar5 < uVar4) {
      if (local_340[2] == local_340[0]) {
        if (local_340[3] != local_340[0]) {
          uVar4 = uVar5;
        }
      }
      else {
        if (local_340[3] == local_340[0]) {
          uVar5 = uVar4;
        }
        if ((local_340[2] != local_340[0]) && (local_340[3] != local_340[0])) {
          uVar5 = uVar4;
        }
      }
    }
    if (0x10000 < uVar4) {
      uVar4 = 0x10000;
    }
    if (0x10000 < uVar5) {
      uVar5 = 0x10000;
    }
    if (param_2 != 0) {
      iVar2 = MmIsDriverVerifying(param_2);
      if ((iVar2 != 0) && (local_344 == 2)) {
        local_344 = 4;
        goto LAB_1400022b7;
      }
    }
    if (100 < local_344) {
      local_344 = 100;
    }
  }
LAB_1400022b7:
  *param_4 = (undefined2)local_330;
  *local_2b8 = (undefined2)local_32c;
  *param_3 = local_348 << 0xc;
  *(bool *)(param_6 + 0xdc) = local_328 != 0;
  *(uint *)(param_6 + 0x14c) = local_344;
  *(undefined4 *)(param_6 + 0x150) = local_324;
  *(uint *)(param_6 + 0x28) = uVar4;
  *(uint *)(param_6 + 0x2c) = uVar5;
  *(undefined4 *)(param_6 + 0x154) = local_320[0];
  if (local_318 != 0) {
    ZwClose();
  }
  if (local_300 != 0) {
    ZwClose();
  }
  return;
}



===== SetWppAutoLogRegistrySettings @ 140002390 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SetWppAutoLogRegistrySettings(undefined8 *param_1,longlong param_2,undefined8 param_3)

{
  int iVar1;
  undefined1 auStack_f8 [32];
  longlong *local_d8;
  uint local_d0;
  longlong local_c8;
  longlong local_c0;
  undefined8 local_b8;
  longlong lStack_b0;
  undefined8 *local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  ulonglong uStack_90;
  undefined8 local_88;
  wchar_t *local_80;
  undefined8 local_78;
  wchar_t *local_70;
  undefined8 local_68;
  longlong *plStack_60;
  wchar_t local_58 [12];
  wchar_t local_40 [24];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_f8;
  local_88 = 0x160014;
  local_98 = 0;
  uStack_90 = uStack_90 & 0xffffffff00000000;
  builtin_wcsncpy(local_58,L"Parameters",0xb);
  local_80 = local_58;
  builtin_wcsncpy(local_40,L"WppRecorder_TraceGuid",0x16);
  local_70 = local_40;
  local_c8 = 0;
  local_c0 = 0;
  local_78 = 0x2c002a;
  local_b8 = 0;
  lStack_b0 = 0;
  local_a8 = (undefined8 *)0x0;
  uStack_a0 = 0;
  local_68 = 0;
  plStack_60 = (longlong *)0x0;
  if (param_2 == 0) {
    lStack_b0 = 0;
    local_b8 = 0x30;
    uStack_a0 = 0x240;
    local_98 = 0;
    uStack_90 = 0;
    local_a8 = param_1;
    iVar1 = ZwOpenKey(&local_c0,0x2001f,&local_b8);
    if (iVar1 < 0) goto LAB_140002546;
    lStack_b0 = local_c0;
    local_a8 = &local_88;
    local_b8 = CONCAT44(local_b8._4_4_,0x30);
    uStack_a0 = CONCAT44(uStack_a0._4_4_,0x240);
    local_98 = 0;
    uStack_90 = 0;
    iVar1 = ZwOpenKey(&local_c8,0x2001f,&local_b8);
  }
  else {
    local_d8 = &local_c8;
    iVar1 = IoOpenDriverRegistryKey(param_2,2,0x20006);
  }
  if (-1 < iVar1) {
    iVar1 = RtlStringFromGUID(param_3,&local_68);
    if (-1 < iVar1) {
      local_d0 = (uint)local_68._2_2_;
      local_d8 = plStack_60;
      ZwSetValueKey(local_c8,&local_78,0,1);
      RtlFreeUnicodeString(&local_68);
    }
  }
LAB_140002546:
  if (local_c8 != 0) {
    ZwClose();
  }
  if (local_c0 != 0) {
    ZwClose();
  }
  return;
}



===== WppAutoLogStart @ 1400025a0 =====

void WppAutoLogStart(ulonglong param_1,short *param_2,ushort *param_3)

{
  ulonglong *puVar1;
  uint *puVar2;
  undefined4 *puVar3;
  short sVar4;
  uint uVar5;
  ushort uVar6;
  longlong lVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined4 *puVar11;
  undefined8 uVar12;
  ulonglong uVar13;
  ulonglong *puVar14;
  int *piVar15;
  char *pcVar16;
  char *pcVar17;
  short *psVar18;
  ulonglong *puVar19;
  uint *puVar20;
  char *pcVar21;
  longlong lVar22;
  uint uVar23;
  int *_Str;
  uint uVar24;
  short *psVar25;
  short *psVar26;
  ulonglong uVar27;
  bool bVar28;
  uint local_res8 [2];
  int local_res10 [2];
  
                    /* 0x25a0  3  WppAutoLogStart */
  local_res10[0] = 0;
  if ((param_2 != (short *)0x0) && (*param_2 != 4)) {
    param_2 = (short *)0x0;
  }
  bVar28 = g_IsDllDisabled != '\0';
  *(undefined2 *)(param_1 + 0x4a) = 0;
  *(undefined8 *)(param_1 + 0x40) = 0;
  *(undefined2 *)(param_1 + 0x48) = 0;
  if (bVar28) {
    return;
  }
  puVar11 = (undefined4 *)ExAllocatePool2(0x40,0x158,0x674c5057);
  if (puVar11 == (undefined4 *)0x0) {
    DbgPrint("Error: failed to allocate memory for autoLogContext\n");
    return;
  }
  *(undefined1 *)(puVar11 + 0xc) = 0;
  *puVar11 = 0;
  *(undefined4 **)(puVar11 + 0x34) = puVar11;
  puVar11[0x36] = 0;
  puVar11[0x2a] = 0;
  *(undefined1 *)(puVar11 + 0x37) = 1;
  *(undefined1 *)((longlong)puVar11 + 0xdd) = 0;
  GetWppAutoLogRegistrySettings
            ((undefined8 *)param_3,(longlong)param_2,local_res10,(undefined2 *)(param_1 + 0x48),
             (undefined2 *)(param_1 + 0x4a),(longlong)puVar11);
  SetWppAutoLogRegistrySettings
            ((undefined8 *)param_3,(longlong)param_2,*(undefined8 *)(param_1 + 8));
  uVar12 = (*(undefined8 **)(param_1 + 8))[1];
  *(undefined8 *)(puVar11 + 5) = **(undefined8 **)(param_1 + 8);
  *(undefined8 *)(puVar11 + 7) = uVar12;
  if (param_3 != (ushort *)0x0) {
    param_2 = *(short **)(param_3 + 4);
    uVar6 = *param_3 >> 1;
    psVar18 = param_2 + ((ulonglong)uVar6 - 1);
    sVar4 = param_2[(ulonglong)uVar6 - 1];
    while (sVar4 != 0x5c) {
      if (psVar18 == param_2) goto LAB_140002703;
      psVar18 = psVar18 + -1;
      sVar4 = *psVar18;
    }
    if ((psVar18 != param_2) && (*psVar18 == 0x5c)) {
      psVar26 = (short *)((longlong)
                          ((longlong)param_2 + ((ulonglong)uVar6 * 2 - (longlong)(psVar18 + 1))) >>
                         1);
      if (psVar26 < (short *)0x40) {
        if (psVar26 == (short *)0x0) goto LAB_140002703;
      }
      else {
        psVar26 = (short *)0x3f;
      }
      psVar25 = (short *)0x0;
      do {
        param_2 = (short *)(ulonglong)((int)psVar25 + 1);
        *(char *)((longlong)(psVar25 + 0x34) + (longlong)puVar11) =
             (char)(psVar18 + 1)[(longlong)psVar25];
        psVar25 = param_2;
      } while (param_2 < psVar26);
    }
  }
LAB_140002703:
  puVar1 = (ulonglong *)(puVar11 + 2);
  local_res8[0] = 0;
  puVar2 = puVar11 + 4;
  if ((((puVar1 == (ulonglong *)0x0) || (puVar2 == (uint *)0x0)) ||
      (uVar12 = AuxKlibInitialize(), (int)uVar12 < 0)) ||
     (uVar13 = AuxKlibQueryModuleInformation(local_res8,param_2,0), (int)uVar13 < 0))
  goto LAB_1400029e2;
  if (local_res8[0] != 0) {
    uVar13 = (ulonglong)local_res8[0];
    uVar23 = local_res8[0] / 0x110;
    puVar14 = (ulonglong *)ExAllocatePool2(0x40);
    if (puVar14 == (ulonglong *)0x0) goto LAB_1400029e2;
    uVar13 = AuxKlibQueryModuleInformation(local_res8,uVar13,(ulonglong)puVar14);
    iVar10 = (int)uVar13;
    if (-1 < iVar10) {
      uVar24 = 0;
      puVar19 = puVar14;
      if (uVar23 != 0) {
        do {
          uVar13 = *puVar19;
          if ((uVar13 <= param_1) && (param_1 < (uint)puVar19[1] + uVar13)) {
            *puVar1 = uVar13;
            iVar10 = 0;
            *puVar2 = (uint)puVar19[1];
            goto LAB_1400027de;
          }
          puVar19 = puVar19 + 0x22;
          uVar24 = uVar24 + 1;
        } while (uVar24 < uVar23);
      }
      iVar10 = -0x3ffffddb;
    }
LAB_1400027de:
    ExFreePoolWithTag(puVar14,0x33304c57);
    if (iVar10 < 0) goto LAB_1400029e2;
  }
  psVar18 = (short *)*puVar1;
  if (((psVar18 != (short *)0x0) && (uVar23 = *puVar2, uVar23 != 0)) &&
     ((puVar11 + 0x38 != (int *)0x0 &&
      ((puVar11 + 0x3c != (int *)0x0 &&
       (piVar15 = RtlpImageNtHeader(psVar18), piVar15 != (int *)0x0)))))) {
    uVar24 = piVar15[0x2e];
    if (uVar24 != 0) {
      uVar5 = piVar15[0x2f];
      if (uVar5 + uVar24 <= uVar23) {
        uVar13 = 0;
        uVar27 = ((ulonglong)uVar5 - (ulonglong)uVar5 / 7 >> 1) + (ulonglong)uVar5 / 7 >> 4;
        if (uVar27 != 0) {
          puVar20 = (uint *)((ulonglong)uVar24 + 0x14 + (longlong)psVar18);
          do {
            if (puVar20[-2] == 2) {
              uVar24 = *puVar20;
              if ((uVar24 == 0) || (uVar5 = puVar20[-1], uVar23 < uVar5 + uVar24)) break;
              piVar15 = (int *)((ulonglong)uVar24 + (longlong)psVar18);
              if (*piVar15 == 0x53445352) {
                if (0x1b < uVar5) {
                  lVar22 = (longlong)(int)(uVar5 - 1);
                  goto joined_r0x0001400028fa;
                }
                break;
              }
            }
            uVar13 = (ulonglong)((int)uVar13 + 1);
            puVar20 = puVar20 + 7;
          } while (uVar13 < uVar27);
        }
      }
    }
  }
LAB_1400029e2:
  *(undefined1 *)(puVar11 + 9) = *(undefined1 *)(param_1 + 0x4a);
  puVar3 = puVar11 + 0x2e;
  *(undefined8 *)(puVar11 + 0x2c) = 0;
  *(undefined4 **)(puVar11 + 0x30) = puVar3;
  *(undefined4 **)puVar3 = puVar3;
  puVar3 = puVar11 + 0x4e;
  puVar11[0x52] = 0;
  *(undefined4 **)(puVar11 + 0x50) = puVar3;
  *(undefined4 **)puVar3 = puVar3;
  pcVar16 = WppAutoLogCreateLog((longlong)puVar11,local_res10[0] + -0xa8,0,(uint *)0x0);
  if (pcVar16 == (char *)0x0) {
    DbgPrint("Error: failed to allocate memory for WPP recorder\n");
    ExFreePoolWithTag(puVar11,0x674c5057);
  }
  else {
    lVar22 = 0x10;
    pcVar21 = pcVar16;
    do {
      if ((lVar22 == -0x7fffffee) || (pcVar21[(longlong)"DriverLog" - (longlong)pcVar16] == '\0'))
      break;
      *pcVar21 = pcVar21[(longlong)"DriverLog" - (longlong)pcVar16];
      pcVar21 = pcVar21 + 1;
      lVar22 = lVar22 + -1;
    } while (lVar22 != 0);
    pcVar17 = pcVar21 + -1;
    if (lVar22 != 0) {
      pcVar17 = pcVar21;
    }
    *pcVar17 = '\0';
    if ((*puVar1 != 0) && (*puVar2 != 0)) {
      *(undefined1 *)(puVar11 + 0x19) = 0;
      KeRegisterBugCheckReasonCallback
                (puVar11 + 0xe,WppAutoLogpBugCheckCallbackForDriver,2,puVar11 + 0x1a);
    }
    *(char **)(puVar11 + 0x32) = pcVar16;
    *(char **)(param_1 + 0x40) = pcVar16;
  }
  return;
joined_r0x0001400028fa:
  if (lVar22 < 0x18) goto LAB_1400029e2;
  if (*(char *)(lVar22 + (longlong)piVar15) == '\0') {
    iVar10 = piVar15[2];
    iVar8 = piVar15[3];
    iVar9 = piVar15[4];
    _Str = piVar15 + 6;
    puVar11[0x38] = piVar15[1];
    puVar11[0x39] = iVar10;
    puVar11[0x3a] = iVar8;
    puVar11[0x3b] = iVar9;
    puVar11[0x3c] = piVar15[5];
    if (_Str != (int *)0x0) {
      pcVar16 = strrchr((char *)_Str,0x5c);
      if (((pcVar16 != (char *)0x0) ||
          (pcVar16 = strrchr((char *)_Str,0x2f), pcVar16 != (char *)0x0)) &&
         (_Str = (int *)(pcVar16 + 1), _Str == (int *)0x0)) goto LAB_1400029c3;
      lVar22 = 0x40;
      piVar15 = _Str;
      goto LAB_140002970;
    }
    goto LAB_1400029e2;
  }
  lVar22 = lVar22 + -1;
  goto joined_r0x0001400028fa;
  while( true ) {
    piVar15 = (int *)((longlong)piVar15 + 1);
    lVar22 = lVar22 + -1;
    if (lVar22 == 0) break;
LAB_140002970:
    if ((char)*piVar15 == '\0') break;
  }
  lVar7 = -lVar22;
  uVar13 = lVar7 + 0x40;
  if (lVar22 == 0) {
LAB_1400029c3:
    uVar13 = 0;
  }
  else if ((4 < uVar13) &&
          (iVar10 = _stricmp((char *)(lVar7 + 0x3c + (longlong)_Str),".pdb"), iVar10 == 0)) {
    uVar13 = lVar7 + 0x3c;
  }
  RtlStringCbCopyNA((char *)(puVar11 + 0x3d),0x40,_Str,uVar13);
  goto LAB_1400029e2;
}



===== WppAutoLogTrace @ 140002b00 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
WppAutoLogTrace(longlong param_1,char param_2,undefined8 param_3,undefined4 *param_4,
               undefined2 param_5,void *param_6,size_t param_7)

{
  size_t *psVar1;
  uint *puVar2;
  byte bVar3;
  int iVar4;
  int *piVar5;
  size_t _Size;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  ulonglong *puVar9;
  byte bVar10;
  uint uVar11;
  uint uVar12;
  longlong lVar13;
  undefined8 uVar14;
  uint uVar15;
  size_t *psVar16;
  ulonglong uVar17;
  undefined2 *puVar18;
  longlong lVar19;
  void *pvVar20;
  longlong lVar21;
  ulonglong uVar22;
  undefined2 uVar23;
  longlong lVar24;
  bool bVar25;
  undefined8 local_40;
  undefined8 local_38 [2];
  
                    /* 0x2b00  5  WppAutoLogTrace */
  if (param_1 == 0) {
    return 0xc0000001;
  }
  if (*(char *)(param_1 + 0x62) != '\0') {
    lVar24 = *(longlong *)(param_1 + 0x78);
    bVar10 = *(byte *)(lVar24 + 0xdd);
    do {
      LOCK();
      bVar3 = *(byte *)(lVar24 + 0xdd);
      bVar25 = bVar10 == bVar3;
      if (bVar25) {
        *(byte *)(lVar24 + 0xdd) = bVar10 | 1;
      }
      else {
        bVar10 = bVar3;
      }
      UNLOCK();
    } while (!bVar25);
    if (bVar10 != 0) {
      return 0xc0000001;
    }
    if (*(char *)(param_1 + 0x62) == '\0') {
      return 0xc0000001;
    }
    MicrosoftTelemetryAssertTriggeredArgsKM((char *)(lVar24 + 0x68));
    return 0xc0000001;
  }
  if ((param_2 != '\x02') || (lVar24 = 0x80, *(int *)(param_1 + 0x88) == 0)) {
    lVar24 = 0x90;
  }
  lVar21 = 0;
  puVar9 = &param_7;
  pvVar20 = param_6;
  while (pvVar20 != (void *)0x0) {
    uVar22 = *puVar9;
    if (uVar22 != 0) {
      if (0x100 < uVar22) goto LAB_140002e42;
      lVar21 = lVar21 + (uVar22 & 0xffff);
    }
    pvVar20 = (void *)puVar9[1];
    puVar9 = puVar9 + 2;
  }
  local_40 = 0;
  uVar22 = (ulonglong)((uint)lVar21 & 3);
  lVar13 = 4 - uVar22;
  if (uVar22 == 0) {
    lVar13 = 0;
  }
  if (0x100 < (ulonglong)(lVar21 + lVar13)) {
LAB_140002e42:
    piVar5 = *(int **)(*(longlong *)(param_1 + 0x78) + 0xd0);
    LOCK();
    *piVar5 = *piVar5 + 1;
    UNLOCK();
    return 0xc0000001;
  }
  lVar19 = 0x24;
  if (*(char *)(param_1 + 0xa4) == '\0') {
    lVar19 = 0x1c;
  }
  uVar22 = lVar21 + lVar13 + lVar19;
  if (*(uint *)(lVar24 + 8 + param_1) < uVar22) goto LAB_140002e42;
  uVar12 = *(uint *)(lVar24 + 0xc + param_1);
  do {
    uVar11 = uVar12;
    if ((ulonglong)*(uint *)(lVar24 + 8 + param_1) + *(longlong *)(lVar24 + param_1) <
        (ulonglong)(uVar11 & 0xffff) + *(longlong *)(lVar24 + param_1) + uVar22) {
      uVar17 = 0;
      uVar15 = (uint)uVar22 & 0xffff;
    }
    else {
      uVar15 = CONCAT22((short)uVar11,(short)uVar11 + (short)uVar22);
      uVar17 = (ulonglong)uVar11 & 0xffff;
    }
    puVar2 = (uint *)(lVar24 + 0xc + param_1);
    LOCK();
    uVar12 = *puVar2;
    if (uVar11 == uVar12) {
      *puVar2 = uVar15;
      uVar12 = uVar11;
    }
    else {
    }
    UNLOCK();
  } while (uVar12 != uVar11);
  puVar18 = (undefined2 *)(uVar17 + *(longlong *)(lVar24 + param_1));
  bVar25 = DAT_14000a240 == '\0';
  puVar18[1] = (short)uVar22;
  uVar23 = (undefined2)(uVar11 >> 0x10);
  if (bVar25) {
    puVar18[4] = uVar23;
    puVar18[5] = param_5;
    piVar5 = *(int **)(*(longlong *)(param_1 + 0x78) + 0xd0);
    LOCK();
    iVar4 = *piVar5;
    *piVar5 = *piVar5 + 1;
    UNLOCK();
    *(int *)(puVar18 + 2) = iVar4 + 1;
    uVar6 = param_4[1];
    uVar7 = param_4[2];
    uVar8 = param_4[3];
    *(undefined4 *)(puVar18 + 6) = *param_4;
    *(undefined4 *)(puVar18 + 8) = uVar6;
    *(undefined4 *)(puVar18 + 10) = uVar7;
    *(undefined4 *)(puVar18 + 0xc) = uVar8;
    if (*(char *)(param_1 + 0xa4) == '\0') {
      *puVar18 = 0x524c;
      goto LAB_140002dd3;
    }
    *puVar18 = 0x324c;
    local_40 = 0;
    if (*(char *)(param_1 + 0xa5) == '\0') {
      uVar14 = _DAT_fffff78000000014;
    }
    else {
      KeQuerySystemTimePrecise(&local_40);
      uVar14 = local_40;
    }
  }
  else {
    puVar18[4] = uVar23;
    puVar18[5] = param_5;
    piVar5 = *(int **)(*(longlong *)(param_1 + 0x78) + 0xd0);
    LOCK();
    iVar4 = *piVar5;
    *piVar5 = *piVar5 + 1;
    UNLOCK();
    *(int *)(puVar18 + 2) = iVar4 + 1;
    RtlCopyVolatileMemory(puVar18 + 6,param_4,0x10);
    if (*(char *)(param_1 + 0xa4) == '\0') {
      *puVar18 = 0x524c;
      goto LAB_140002dd3;
    }
    local_38[0] = 0;
    *puVar18 = 0x324c;
    if (*(char *)(param_1 + 0xa5) == '\0') {
      local_38[0] = _DAT_fffff78000000014;
      uVar14 = _DAT_fffff78000000014;
    }
    else {
      KeQuerySystemTimePrecise(local_38);
      uVar14 = local_38[0];
    }
  }
  *(int *)(puVar18 + 0xe) = (int)uVar14;
  *(int *)(puVar18 + 0x10) = (int)((ulonglong)uVar14 >> 0x20);
LAB_140002dd3:
  psVar16 = &param_7;
  pvVar20 = (void *)(lVar19 + (longlong)puVar18);
  while (param_6 != (void *)0x0) {
    _Size = *psVar16;
    psVar1 = psVar16 + 1;
    if (_Size != 0) {
      if (DAT_14000a240 == '\0') {
        memmove(pvVar20,param_6,_Size);
      }
      else {
        RtlCopyVolatileMemory(pvVar20,param_6,_Size);
      }
      pvVar20 = (void *)((longlong)pvVar20 + _Size);
    }
    psVar16 = psVar16 + 2;
    param_6 = (void *)*psVar1;
  }
  return 0;
}



===== WppAutoLogpUnregisterBugCheckCallbackHelper @ 140002e70 =====

void WppAutoLogpUnregisterBugCheckCallbackHelper(longlong param_1)

{
  char cVar1;
  
  if (*(longlong *)(param_1 + 0x10) != 0) {
    cVar1 = KeDeregisterBugCheckReasonCallback();
    if (cVar1 != '\0') {
      *(undefined8 *)(param_1 + 0x10) = 0;
    }
  }
  return;
}



===== WppAutoLogDeleteAutoLogContext @ 140002eb0 =====

void WppAutoLogDeleteAutoLogContext(longlong param_1)

{
  longlong *plVar1;
  
  if (param_1 != 0) {
    while (plVar1 = *(longlong **)(param_1 + 0xb8), plVar1 != (longlong *)(param_1 + 0xb8)) {
      WppAutoLogDeleteLog((longlong)(plVar1 + -4));
    }
    ExFreePoolWithTag(param_1,0x674c5057);
  }
  return;
}



===== imp_WppRecorderIsDefaultLogAvailable @ 140002f10 =====

ulonglong imp_WppRecorderIsDefaultLogAvailable(longlong param_1)

{
  longlong lVar1;
  ulonglong uVar2;
  
                    /* 0x2f10  10  imp_WppRecorderIsDefaultLogAvailable */
  uVar2 = 0;
  lVar1 = WppAutoLogGetDriverContext(param_1);
  if ((lVar1 == 0) || (*(longlong *)(lVar1 + 200) == 0)) {
    uVar2 = uVar2 & 0xff;
  }
  else {
    uVar2 = uVar2 & 0xff;
    if (*(int *)(*(longlong *)(lVar1 + 200) + 0x98) != 0) {
      uVar2 = 1;
    }
  }
  return uVar2;
}



===== RtlStringCbLengthA @ 140002f50 =====

void RtlStringCbLengthA(char *param_1,ulonglong param_2,longlong *param_3)

{
  ulonglong uVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  
  lVar4 = 0;
  if ((param_1 == (char *)0x0) || (uVar1 = param_2, 0x7fffffff < param_2)) {
    iVar2 = -0x3ffffff3;
  }
  else {
    for (; (uVar1 != 0 && (*param_1 != '\0')); param_1 = param_1 + 1) {
      uVar1 = uVar1 - 1;
    }
    iVar2 = -0x3ffffff3;
    if (uVar1 != 0) {
      iVar2 = 0;
    }
    lVar4 = param_2 - uVar1;
    if (uVar1 == 0) {
      lVar4 = 0;
    }
  }
  if (param_3 != (longlong *)0x0) {
    lVar3 = 0;
    if (-1 < iVar2) {
      lVar3 = lVar4;
    }
    *param_3 = lVar3;
  }
  return;
}



===== __report_gsfailure @ 140002fc0 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== __C_specific_handler @ 140002fcd =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000140002fcd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== __cpu_features_init @ 140002ff0 =====

/* WARNING: Removing unreachable block (ram,0x00014000305a) */
/* WARNING: Removing unreachable block (ram,0x000140003009) */
/* WARNING: Removing unreachable block (ram,0x000140002ffa) */

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



===== imp_WppRecorderDumpLiveDriverData @ 1400030c0 =====

void imp_WppRecorderDumpLiveDriverData
               (longlong param_1,longlong *param_2,undefined4 *param_3,undefined8 *param_4)

{
  longlong lVar1;
  
                    /* 0x30c0  7  imp_WppRecorderDumpLiveDriverData */
  lVar1 = WppAutoLogGetDriverContext(param_1);
  WppAutoLogGetBugCheckDataForDriver(lVar1,0,param_2,param_3,param_4);
  return;
}



===== imp_WppRecorderGetCounterHandle @ 1400030f0 =====

void imp_WppRecorderGetCounterHandle(longlong param_1)

{
                    /* 0x30f0  8  imp_WppRecorderGetCounterHandle */
  WppAutoLogGetDriverContext(param_1);
  return;
}



===== imp_WppRecorderGetTriageInfo @ 140003110 =====

undefined8 imp_WppRecorderGetTriageInfo(undefined8 param_1,undefined4 *param_2)

{
  undefined8 uVar1;
  
                    /* 0x3110  9  imp_WppRecorderGetTriageInfo */
  uVar1 = 0xc0000001;
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0xa8;
    uVar1 = 0;
    param_2[1] = 0x78;
    param_2[2] = 0xa0;
    param_2[3] = 4;
    param_2[4] = 0x158;
  }
  return uVar1;
}



===== imp_WppRecorderLinkCounters @ 140003150 =====

undefined8 imp_WppRecorderLinkCounters(longlong param_1,int *param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
                    /* 0x3150  11  imp_WppRecorderLinkCounters */
  piVar2 = (int *)WppAutoLogGetDriverContext(param_1);
  if ((param_2 != (int *)0x0) && (piVar2 != (int *)0x0)) {
    LOCK();
    piVar1 = piVar2 + 0x36;
    iVar3 = *piVar1;
    *piVar1 = *piVar1 + 1;
    UNLOCK();
    if (iVar3 == 0) {
      iVar3 = *piVar2;
      if (*piVar2 <= *param_2) {
        iVar3 = *param_2;
      }
      *param_2 = iVar3 + 10;
      *(int **)(piVar2 + 0x34) = param_2;
      return 0;
    }
  }
  return 0xc0000001;
}



===== imp_WppRecorderLogDumpLiveData @ 1400031b0 =====

void imp_WppRecorderLogDumpLiveData
               (undefined8 param_1,longlong param_2,longlong *param_3,uint *param_4,
               undefined8 *param_5)

{
                    /* 0x31b0  14  imp_WppRecorderLogDumpLiveData */
  WppAutoLogGetBugCheckDataForLog(param_2,0,param_3,param_4,param_5);
  return;
}



===== WppAutoLogGetBugCheckDataForDriver @ 1400031d4 =====

undefined8
WppAutoLogGetBugCheckDataForDriver
          (longlong param_1,int param_2,longlong *param_3,undefined4 *param_4,undefined8 *param_5)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar2 = 0;
  *param_3 = 0;
  *param_4 = 0;
  if (param_1 == 0) {
    uVar2 = 0xc0000001;
  }
  else if (param_2 - 1U < 0x43) {
    uVar2 = 0xc0000023;
  }
  else {
    *param_3 = param_1 + 0x68;
    *param_4 = 0x44;
    uVar1 = *(undefined8 *)(param_1 + 0x1c);
    *param_5 = *(undefined8 *)(param_1 + 0x14);
    param_5[1] = uVar1;
  }
  return uVar2;
}



===== WppAutoLogGetBugCheckDataForLog @ 140003224 =====

undefined8
WppAutoLogGetBugCheckDataForLog
          (longlong param_1,uint param_2,longlong *param_3,uint *param_4,undefined8 *param_5)

{
  ushort uVar1;
  longlong lVar2;
  ushort uVar3;
  undefined2 uVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  uint uVar7;
  undefined8 uVar8;
  
  uVar8 = 0;
  if (param_1 == 0) {
    uVar8 = 0xc0000001;
  }
  else {
    *param_3 = 0;
    *param_4 = 0;
    uVar7 = *(int *)(param_1 + 0xa0) + 0xa8;
    if ((param_2 == 0) || (uVar7 <= param_2)) {
      lVar2 = *(longlong *)(param_1 + 0x78);
      uVar5 = *(undefined4 *)(lVar2 + 0x14);
      uVar3 = *(ushort *)(lVar2 + 0x18);
      uVar4 = *(undefined2 *)(lVar2 + 0x1a);
      uVar6 = *(undefined8 *)(lVar2 + 0x1c);
      uVar1 = *(ushort *)(param_1 + 0x60);
      *param_3 = param_1;
      *param_4 = uVar7;
      *param_5 = CONCAT26(uVar4,CONCAT24(uVar3 ^ uVar1,uVar5));
      param_5[1] = uVar6;
    }
    else {
      uVar8 = 0xc0000023;
    }
  }
  return uVar8;
}



===== WppAutoLogpBugCheckCallbackFilter @ 1400032a0 =====

char WppAutoLogpBugCheckCallbackFilter(longlong param_1)

{
  int iVar1;
  ulonglong uVar2;
  
  if ((*(char *)(param_1 + 0x24) != '\0') || (*(short *)(WPP_GLOBAL_Control + 0x4a) != 0)) {
    return '\x01';
  }
  iVar1 = *(int *)KiBugCheckData_exref;
  if (iVar1 == 10) {
LAB_1400032fa:
    uVar2 = *(ulonglong *)(KiBugCheckData_exref + 0x20);
  }
  else {
    if (iVar1 != 0x1e) {
      uVar2 = *(ulonglong *)(KiBugCheckData_exref + 8);
      if (iVar1 == 0x20) goto LAB_1400032fd;
      if (iVar1 == 0x50) {
        uVar2 = *(ulonglong *)(KiBugCheckData_exref + 0x18);
        goto LAB_1400032fd;
      }
      if ((iVar1 != 0x7e) && (iVar1 != 0x8e)) {
        if (iVar1 != 0xd1) {
          return '\0';
        }
        goto LAB_1400032fa;
      }
    }
    uVar2 = *(ulonglong *)(KiBugCheckData_exref + 0x10);
  }
LAB_1400032fd:
  uVar2 = WppAutoLogpIsAddressKnownToWdf(uVar2,param_1);
  if ((char)uVar2 != '\0') {
    *(undefined1 *)(param_1 + 0x24) = 1;
  }
  return (char)uVar2;
}



===== WppAutoLogpBugCheckCallbackForDriver @ 140003330 =====

void WppAutoLogpBugCheckCallbackForDriver(undefined8 param_1,longlong param_2,longlong param_3)

{
  char cVar1;
  
  cVar1 = WppAutoLogpBugCheckCallbackFilter(param_2 + -0x38);
  if ((cVar1 != '\0') && (*(int *)(param_3 + 0xc) != 0)) {
    WppAutoLogGetBugCheckDataForDriver
              (param_2 + -0x38,*(int *)(param_3 + 0xc),(longlong *)(param_3 + 0x20),
               (undefined4 *)(param_3 + 0x28),(undefined8 *)(param_3 + 0x10));
  }
  return;
}



===== WppAutoLogpBugCheckCallbackForLog @ 140003380 =====

void WppAutoLogpBugCheckCallbackForLog(undefined8 param_1,longlong param_2,longlong param_3)

{
  char cVar1;
  
  if (*(longlong *)(param_2 + 0x48) != 0) {
    cVar1 = WppAutoLogpBugCheckCallbackFilter(*(longlong *)(param_2 + 0x48));
    if ((cVar1 != '\0') && (*(uint *)(param_3 + 0xc) != 0)) {
      WppAutoLogGetBugCheckDataForLog
                (param_2 + -0x30,*(uint *)(param_3 + 0xc),(longlong *)(param_3 + 0x20),
                 (uint *)(param_3 + 0x28),(undefined8 *)(param_3 + 0x10));
    }
  }
  return;
}



===== WppAutoLogpIsAddressKnownToWdf @ 1400033d8 =====

ulonglong WppAutoLogpIsAddressKnownToWdf(ulonglong param_1,longlong param_2)

{
  ulonglong in_RAX;
  
  if ((((param_1 == 0) || (param_2 == 0)) || (param_1 < *(ulonglong *)(param_2 + 8))) ||
     (in_RAX = (ulonglong)*(uint *)(param_2 + 0x10) + *(ulonglong *)(param_2 + 8), in_RAX <= param_1
     )) {
    return in_RAX & 0xffffffffffffff00;
  }
  return CONCAT71((int7)(in_RAX >> 8),1);
}



===== WPP_RECORDER_SF_dd @ 140003404 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_dd(longlong param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
     (3 < *(byte *)(WPP_GLOBAL_Control + 0x29))) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_9441f7a406c53635e5b2b216da900c72_Traceguids,param_4,&param_6,4,&param_7,4,0);
  }
  WppAutoLogTrace(param_1,'\x04',1,(undefined4 *)&WPP_9441f7a406c53635e5b2b216da900c72_Traceguids,
                  param_4,&param_6,4);
  return;
}



===== WPP_RECORDER_SF_ds @ 1400034cc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_ds(longlong param_1)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  undefined1 uStack0000000000000030;
  char *in_stack_00000038;
  
  lVar4 = -1;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
     (3 < *(byte *)(WPP_GLOBAL_Control + 0x29))) {
    if (in_stack_00000038 == (char *)0x0) {
      lVar3 = 5;
    }
    else {
      lVar2 = -1;
      do {
        lVar3 = lVar2;
        lVar2 = lVar3 + 1;
      } while (in_stack_00000038[lVar2] != '\0');
      lVar3 = lVar3 + 2;
    }
    pcVar1 = in_stack_00000038;
    if (in_stack_00000038 == (char *)0x0) {
      pcVar1 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_9441f7a406c53635e5b2b216da900c72_Traceguids,0xe,&uStack0000000000000030,4,pcVar1
               ,lVar3,0);
  }
  if (in_stack_00000038 != (char *)0x0) {
    do {
      lVar4 = lVar4 + 1;
    } while (in_stack_00000038[lVar4] != '\0');
  }
  WppAutoLogTrace(param_1,'\x04',1,(undefined4 *)&WPP_9441f7a406c53635e5b2b216da900c72_Traceguids,
                  0xe,&uStack0000000000000030,4);
  return;
}



===== WPP_RECORDER_SF_dscs @ 14000360c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_dscs(longlong param_1)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  char *pcVar6;
  undefined1 uStack0000000000000030;
  char *in_stack_00000038;
  undefined1 uStack0000000000000040;
  char *in_stack_00000048;
  
  lVar3 = -1;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
     (3 < *(byte *)(WPP_GLOBAL_Control + 0x29))) {
    if (in_stack_00000048 == (char *)0x0) {
      lVar5 = 5;
    }
    else {
      lVar4 = -1;
      do {
        lVar5 = lVar4;
        lVar4 = lVar5 + 1;
      } while (in_stack_00000048[lVar4] != '\0');
      lVar5 = lVar5 + 2;
    }
    pcVar6 = in_stack_00000048;
    if (in_stack_00000048 == (char *)0x0) {
      pcVar6 = "NULL";
    }
    if (in_stack_00000038 == (char *)0x0) {
      lVar4 = 5;
    }
    else {
      lVar2 = -1;
      do {
        lVar4 = lVar2;
        lVar2 = lVar4 + 1;
      } while (in_stack_00000038[lVar2] != '\0');
      lVar4 = lVar4 + 2;
    }
    pcVar1 = in_stack_00000038;
    if (in_stack_00000038 == (char *)0x0) {
      pcVar1 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_9441f7a406c53635e5b2b216da900c72_Traceguids,0xb,&uStack0000000000000030,4,pcVar1
               ,lVar4,&uStack0000000000000040,1,pcVar6,lVar5,0);
  }
  if (in_stack_00000048 != (char *)0x0) {
    lVar5 = -1;
    do {
      lVar5 = lVar5 + 1;
    } while (in_stack_00000048[lVar5] != '\0');
  }
  if (in_stack_00000038 != (char *)0x0) {
    do {
      lVar3 = lVar3 + 1;
    } while (in_stack_00000038[lVar3] != '\0');
  }
  WppAutoLogTrace(param_1,'\x04',1,(undefined4 *)&WPP_9441f7a406c53635e5b2b216da900c72_Traceguids,
                  0xb,&uStack0000000000000030,4);
  return;
}



===== WPP_RECORDER_SF_s @ 1400037e8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_s(longlong param_1)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  size_t sVar4;
  char *in_stack_00000030;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
     (3 < *(byte *)(WPP_GLOBAL_Control + 0x29))) {
    if (in_stack_00000030 == (char *)0x0) {
      lVar3 = 5;
    }
    else {
      lVar2 = -1;
      do {
        lVar3 = lVar2;
        lVar2 = lVar3 + 1;
      } while (in_stack_00000030[lVar2] != '\0');
      lVar3 = lVar3 + 2;
    }
    pcVar1 = in_stack_00000030;
    if (in_stack_00000030 == (char *)0x0) {
      pcVar1 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_9441f7a406c53635e5b2b216da900c72_Traceguids,10,pcVar1,lVar3,0);
  }
  lVar3 = -1;
  if (in_stack_00000030 == (char *)0x0) {
    sVar4 = 5;
  }
  else {
    do {
      lVar2 = lVar3;
      lVar3 = lVar2 + 1;
    } while (in_stack_00000030[lVar3] != '\0');
    sVar4 = lVar2 + 2;
  }
  if (in_stack_00000030 == (char *)0x0) {
    in_stack_00000030 = "NULL";
  }
  WppAutoLogTrace(param_1,'\x04',1,(undefined4 *)&WPP_9441f7a406c53635e5b2b216da900c72_Traceguids,10
                  ,in_stack_00000030,sVar4);
  return;
}



===== WPP_RECORDER_SF_sd @ 1400038f8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sd(longlong param_1)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  size_t sVar4;
  char *in_stack_00000030;
  undefined1 uStack0000000000000038;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
     (3 < *(byte *)(WPP_GLOBAL_Control + 0x29))) {
    if (in_stack_00000030 == (char *)0x0) {
      lVar3 = 5;
    }
    else {
      lVar2 = -1;
      do {
        lVar3 = lVar2;
        lVar2 = lVar3 + 1;
      } while (in_stack_00000030[lVar2] != '\0');
      lVar3 = lVar3 + 2;
    }
    pcVar1 = in_stack_00000030;
    if (in_stack_00000030 == (char *)0x0) {
      pcVar1 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_9441f7a406c53635e5b2b216da900c72_Traceguids,0xf,pcVar1,lVar3,
               &uStack0000000000000038,4,0);
  }
  lVar3 = -1;
  if (in_stack_00000030 == (char *)0x0) {
    sVar4 = 5;
  }
  else {
    do {
      lVar2 = lVar3;
      lVar3 = lVar2 + 1;
    } while (in_stack_00000030[lVar3] != '\0');
    sVar4 = lVar2 + 2;
  }
  if (in_stack_00000030 == (char *)0x0) {
    in_stack_00000030 = "NULL";
  }
  WppAutoLogTrace(param_1,'\x04',1,(undefined4 *)&WPP_9441f7a406c53635e5b2b216da900c72_Traceguids,
                  0xf,in_stack_00000030,sVar4);
  return;
}



===== WppAutoLogCreateLogSnapshot @ 140003a38 =====

char * WppAutoLogCreateLogSnapshot(char *param_1,char *param_2)

{
  uint uVar1;
  undefined8 uVar2;
  char *_Dst;
  char cVar3;
  char local_res10 [8];
  char local_res18 [8];
  
  _Dst = (char *)0x0;
  cVar3 = '\0';
  local_res18[0] = '\0';
  local_res10[0] = '\0';
  uVar2 = WppAutoLogValidateLogHeader(param_1,local_res18);
  if ((-1 < (int)uVar2) &&
     (uVar1 = *(uint *)(param_1 + 0xa0) + 0xa8, *(uint *)(param_1 + 0xa0) <= uVar1)) {
    _Dst = (char *)ExAllocatePool2(0x40,uVar1,0x674c5057);
    if (_Dst != (char *)0x0) {
      memmove(_Dst,param_1,(ulonglong)uVar1);
      uVar2 = WppAutoLogValidateLogHeader(_Dst,local_res10);
      cVar3 = local_res10[0];
      if (((int)uVar2 < 0) || (local_res10[0] != local_res18[0])) {
        ExFreePoolWithTag(_Dst,0x674c5057);
        _Dst = (char *)0x0;
      }
      else {
        if (*(int *)(_Dst + 0x98) != 0) {
          *(char **)(_Dst + 0x90) = _Dst + 0xa8;
        }
        if (*(int *)(_Dst + 0x88) != 0) {
          *(char **)(_Dst + 0x80) =
               _Dst + (ulonglong)(uint)(*(int *)(_Dst + 0xa0) - *(int *)(_Dst + 0x88)) + 0xa8;
        }
      }
    }
  }
  *param_2 = cVar3;
  return _Dst;
}



===== WppAutoLogSendRecordsToWpp @ 140003b44 =====

int WppAutoLogSendRecordsToWpp(undefined8 param_1,longlong param_2,undefined8 *param_3)

{
  ushort uVar1;
  short *psVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  undefined8 uVar6;
  longlong lVar7;
  ulonglong uVar8;
  longlong lVar9;
  uint uVar10;
  short *psVar11;
  uint uVar12;
  short *psVar13;
  longlong lVar14;
  uint uVar15;
  short *psVar16;
  short *psVar17;
  ushort local_res20;
  
  uVar15 = *(uint *)(param_3 + 1);
  bVar3 = false;
  bVar4 = false;
  iVar5 = 0;
  if (uVar15 != 0) {
    psVar2 = (short *)*param_3;
    psVar16 = (short *)((ulonglong)(uVar15 - 1) + (longlong)psVar2);
    uVar12 = (-(uint)(*(char *)(param_2 + 0xa4) != '\0') & 8) + 0x1c;
    psVar13 = (short *)(ulonglong)uVar12;
    uVar8 = (ulonglong)uVar15 / (ulonglong)psVar13;
    uVar15 = (uint)uVar8;
    if ((psVar2 <= psVar16) && (psVar13 <= psVar16)) {
      psVar17 = (short *)((longlong)psVar16 - (longlong)psVar13);
      uVar1 = *(ushort *)((longlong)param_3 + 0xc);
      local_res20 = *(ushort *)((longlong)param_3 + 0xe);
      psVar11 = (short *)((ulonglong)local_res20 + (longlong)psVar2);
      if (psVar2 <= psVar11) {
        if (((psVar11 <= psVar17) && (*psVar11 == 0)) && (psVar11[1] == 0)) {
          return 0;
        }
        uVar6 = WppAutoLogValidateRecord
                          ((ulonglong)psVar11,param_2,(ulonglong)psVar17,(ulonglong)psVar16);
        iVar5 = (int)uVar6;
        if (iVar5 < 0) {
          return iVar5;
        }
        uVar10 = 0;
        lVar7 = ExAllocatePool2(0x40,uVar8 * 2,0x674c5057);
        if (lVar7 == 0) {
          return -0x3fffff66;
        }
        lVar14 = lVar7;
        if (uVar15 != 0) {
          do {
            uVar6 = WppAutoLogValidateRecord
                              ((ulonglong)psVar11,param_2,(ulonglong)psVar17,(ulonglong)psVar16);
            iVar5 = (int)uVar6;
            if ((iVar5 < 0) || ((*psVar11 + 0xcdb4U & 0xdfff) != 0)) break;
            uVar8 = (ulonglong)uVar10;
            uVar10 = uVar10 + 1;
            if (psVar11 == psVar2) {
              bVar3 = true;
            }
            *(ushort *)(lVar14 + uVar8 * 2) = local_res20;
            local_res20 = psVar11[4];
            psVar11 = (short *)((ulonglong)local_res20 + (longlong)psVar2);
            if (psVar11 < psVar2) {
              iVar5 = -0x3fffff6b;
              break;
            }
            if (bVar3) {
              iVar5 = 0;
              if (local_res20 == 0) break;
            }
            if (bVar4) {
              iVar5 = 0;
              if (local_res20 <= uVar1) break;
            }
            if ((bVar3) && (local_res20 != 0)) {
              bVar4 = true;
              bVar3 = false;
            }
            iVar5 = 0;
          } while (uVar10 < uVar15);
joined_r0x000140003d10:
          if (uVar10 != 0) {
            uVar10 = uVar10 - 1;
            lVar9 = (ulonglong)*(ushort *)(lVar14 + (ulonglong)uVar10 * 2) + (longlong)psVar2;
            uVar1 = *(ushort *)(lVar9 + 2);
            if (uVar12 < uVar1) {
              WmiTraceMessage(param_1,0x2b,lVar9 + 0xc,*(undefined2 *)(lVar9 + 10),
                              (longlong)psVar13 + lVar9,uVar1 - uVar12,0,0);
              lVar14 = lVar7;
            }
            else {
              if (uVar1 != uVar12) goto LAB_140003da3;
              WmiTraceMessage(param_1,0x2b,lVar9 + 0xc,*(undefined2 *)(lVar9 + 10),0,0);
              lVar14 = lVar7;
            }
            goto joined_r0x000140003d10;
          }
        }
LAB_140003da3:
        ExFreePoolWithTag(lVar14,0x674c5057);
        return iVar5;
      }
    }
    iVar5 = -0x3fffff6b;
  }
  return iVar5;
}



===== WppAutoLogValidateLogHeader @ 140003dd8 =====

undefined8 WppAutoLogValidateLogHeader(char *param_1,undefined1 *param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  undefined1 uVar5;
  
  uVar1 = *(uint *)(param_1 + 0xa0);
  if (((uVar1 < 0xff59) && ((-(uint)(param_1[0xa4] != '\0') & 8) + 0x1c <= uVar1)) &&
     (uVar2 = *(uint *)(param_1 + 0x98), uVar2 != 0)) {
    if (*(int *)(param_1 + 0x88) + uVar2 < uVar2) {
      return 0xc0000095;
    }
    if (((*(int *)(param_1 + 0x88) + uVar2 == uVar1) && (*(ushort *)(param_1 + 0x9c) <= uVar1)) &&
       ((*(ushort *)(param_1 + 0x9e) <= uVar1 &&
        ((*(ushort *)(param_1 + 0x8c) <= uVar1 && (*(ushort *)(param_1 + 0x8e) <= uVar1)))))) {
      uVar4 = RtlStringCbLengthA(param_1,0x10,(longlong *)0x0);
      if ((int)uVar4 < 0) {
        return uVar4;
      }
      iVar3 = _stricmp(param_1,"DriverLog");
      if (iVar3 == 0) {
        uVar5 = 1;
        if ((0xf57 < *(uint *)(param_1 + 0xa0)) && (*(int *)(param_1 + 0x88) == 0)) {
LAB_140003ee2:
          *param_2 = uVar5;
          return 0;
        }
      }
      else {
        uVar5 = 0;
        if (((*(uint *)(*(longlong *)(param_1 + 0x78) + 0x28) <= *(uint *)(param_1 + 0xa0)) &&
            (*(uint *)(param_1 + 0xa0) <= *(uint *)(*(longlong *)(param_1 + 0x78) + 0x2c))) &&
           (*(uint *)(param_1 + 0x88) <= *(uint *)(param_1 + 0x98))) goto LAB_140003ee2;
      }
    }
  }
  return 0xc0000206;
}



===== WppAutoLogValidateRecord @ 140003ef8 =====

undefined8
WppAutoLogValidateRecord(ulonglong param_1,longlong param_2,ulonglong param_3,ulonglong param_4)

{
  ushort uVar1;
  ulonglong uVar2;
  
  if (param_1 <= param_3) {
    uVar1 = *(ushort *)(param_1 + 2);
    if (((ushort)((-(ushort)(*(char *)(param_2 + 0xa4) != '\0') & 8) + 0x1c) <= uVar1) &&
       (uVar1 < 0x101)) {
      uVar2 = (param_1 - 1) + (ulonglong)uVar1;
      if (uVar2 < param_1) {
        return 0xc0000095;
      }
      if (uVar2 <= param_4) {
        return 0;
      }
    }
  }
  return 0xc0000206;
}



===== DllInitialize @ 140003f50 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 DllInitialize(void)

{
  int iVar1;
  ulonglong uVar2;
  code *pcVar3;
  undefined *puVar4;
  undefined1 auStack_1c8 [32];
  undefined8 local_1a8;
  uint local_198;
  undefined4 local_194;
  undefined8 local_190;
  undefined8 uStack_188;
  undefined8 local_178;
  undefined8 uStack_170;
  ushort local_168 [4];
  wchar_t *local_160;
  undefined8 local_158;
  undefined8 uStack_150;
  undefined8 local_148;
  undefined4 local_140;
  wchar_t *local_138;
  uint *local_130;
  undefined4 local_128;
  uint *local_120;
  undefined4 local_118;
  undefined8 local_110;
  undefined4 local_108;
  wchar_t *local_100;
  undefined4 *local_f8;
  undefined4 local_f0;
  undefined4 *local_e8;
  undefined4 local_e0;
  undefined8 local_d8;
  undefined4 local_d0;
  undefined8 local_c8;
  wchar_t local_98 [64];
  ulonglong local_18;
  
                    /* 0x3f50  1  DllInitialize */
  local_18 = __security_cookie ^ (ulonglong)auStack_1c8;
  builtin_wcsncpy(local_98,L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\WppRecorder",
                  0x3f);
  local_160 = local_98;
  local_190 = 0;
  uStack_188 = 0;
  local_168[0] = 0x7c;
  local_168[1] = 0x7e;
  local_168[2] = 0;
  local_168[3] = 0;
  local_178 = 0;
  uStack_170 = 0;
  LOCK();
  UNLOCK();
  if (g_AssertsOperational == 0) {
    RtlInitAnsiString(&local_178,"WppRecorder.sys");
    local_158 = local_178;
    uStack_150 = uStack_170;
    InitializeTelemetryAssertsKMWorkerInternal((ushort *)&local_158);
  }
  wil_InitializeFeatureStaging();
  uVar2 = Feature_IFR01__private_IsEnabledDeviceUsageNoInline();
  DAT_14000a240 = (int)uVar2 != 0;
  KeInitializeEvent(&WppRecorderGlobals,1,1);
  local_138 = L"ForceDisabledCrashLogs";
  local_118 = 4;
  local_128 = 0x4000004;
  local_130 = &local_198;
  local_f0 = 0x4000004;
  local_120 = &local_198;
  local_e0 = 4;
  local_148 = 0;
  local_100 = L"RecentlyUnloadedDriversMaxCount";
  local_f8 = &local_194;
  local_140 = 0x120;
  local_e8 = &local_194;
  local_110 = 0;
  local_108 = 0x120;
  local_198 = (uint)(g_IsDllDisabled != '\0');
  local_d8 = 0;
  local_d0 = 0;
  local_c8 = 0;
  DAT_14000a222 = 2;
  local_194 = 2;
  local_178 = 0;
  uStack_170 = 0;
  RtlInitUnicodeString(&local_178,L"RtlQueryRegistryValuesEx");
  pcVar3 = (code *)MmGetSystemRoutineAddress(&local_178);
  local_1a8 = 0;
  puVar4 = (undefined *)0x2;
  if (pcVar3 == (code *)0x0) {
    pcVar3 = RtlQueryRegistryValues_exref;
  }
  iVar1 = (*pcVar3)(2,L"WppRecorder",&local_148,0);
  if (-1 < iVar1) {
    g_IsDllDisabled = local_198 != 0;
    DAT_14000a222 = (ushort)local_194;
  }
  DAT_14000a218 = 0;
  DAT_14000a220 = 0;
  if (DAT_14000a222 != 0) {
    puVar4 = (undefined *)0x40;
    DAT_14000a218 = ExAllocatePool2(0x40,(ulonglong)DAT_14000a222 << 3,0x674c5057);
    if (DAT_14000a218 == 0) {
      DAT_14000a222 = 0;
    }
    else {
      puVar4 = &DAT_14000a228;
      KeInitializeEvent(&DAT_14000a228,1,1);
    }
  }
  _WPP_MAIN_CB = 0;
  DAT_14000a1a8 = &WPP_ThisDir_CTLGUID_TestTraceGuid;
  DAT_14000a1b0 = 0;
  _DAT_14000a1c0 = 0;
  _DAT_14000a1c8 = 1;
  _DAT_14000a1e0 = 0;
  _DAT_14000a1e8 = 0;
  WppLoadTracingSupport();
  _DAT_14000a1c0 = 0;
  WppInitKm(puVar4,local_168);
  uStack_188 = 0x200000002;
  local_190 = CONCAT35(local_190._5_3_,0x10);
  imp_WppRecorderConfigure(WPP_GLOBAL_Control,(uint *)&local_190);
  return 0;
}



===== DllUnload @ 140004290 =====

undefined8 DllUnload(void)

{
  ulonglong uVar1;
  
                    /* 0x4290  2  DllUnload */
  WppCleanupKm();
  uVar1 = 0;
  if (DAT_14000a218 != 0) {
    for (; (ushort)uVar1 < DAT_14000a222; uVar1 = (ulonglong)(ushort)((ushort)uVar1 + 1)) {
      WppAutoLogDeleteAutoLogContext(*(longlong *)(DAT_14000a218 + uVar1 * 8));
    }
    ExFreePoolWithTag(DAT_14000a218,0x674c5057);
  }
  wil_UninitializeFeatureStaging();
  UninitializeTelemetryAssertsKM();
  return 0;
}



===== DriverEntry @ 1400042f4 =====

void DriverEntry(void)

{
  DllInitialize();
  return;
}



===== Feature_IFR01__private_IsEnabledDeviceUsageNoInline @ 14000430c =====

ulonglong Feature_IFR01__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  undefined4 *local_res8;
  
  local_res8 = (undefined4 *)(ulonglong)Feature_IFR01__private_featureState;
  if ((Feature_IFR01__private_featureState & 0x10) == 0) {
    uVar1 = Feature_IFR01__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_IFR01__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_IFR01__private_IsEnabledFallback @ 140004344 =====

void Feature_IFR01__private_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2);
  return;
}



===== WppClassicProviderCallback @ 140004360 =====

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



===== wil_details_FeatureDescriptors_SkipPadding @ 140004394 =====

longlong * wil_details_FeatureDescriptors_SkipPadding(longlong *param_1)

{
  while( true ) {
    if (&UNK_14000972f < param_1) {
      return (longlong *)0x0;
    }
    if (*param_1 != 0) break;
    param_1 = param_1 + 1;
  }
  return param_1;
}



===== wil_details_FeatureReporting_IncrementOpportunityInCache @ 1400043c0 =====

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



===== wil_details_FeatureReporting_IncrementUsageInCache @ 140004498 =====

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



===== wil_details_FeatureReporting_RecordUsageInCache @ 14000457c =====

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
LAB_1400046d4:
    wil_details_FeatureReporting_IncrementUsageInCache(param_2,uVar5,param_3,param_1);
  }
  else {
    if (uVar5 == 1) {
LAB_1400046c7:
      wil_details_FeatureReporting_IncrementOpportunityInCache(param_2,uVar5,param_3,param_1);
      return param_1;
    }
    if ((uVar5 != 2) && (uVar5 != 3)) {
      if (uVar5 == 4) goto LAB_1400046d4;
      if (uVar5 == 5) goto LAB_1400046c7;
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



===== wil_details_FeatureReporting_ReportUsageToService @ 1400046fc =====

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
              (0x3401a38,&Feature_IFR01_logged_traits,0,uVar4,local_res18,0,0,1);
  }
  return;
}



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 140004778 =====

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
                     (local_50,(uint *)&Feature_IFR01__private_reporting,param_3,
                      (uint)((ulonglong)param_2 >> 0x20));
  local_38 = *puVar2;
  uStack_34 = puVar2[1];
  uStack_30 = puVar2[2];
  uStack_2c = puVar2[3];
  local_28 = *(undefined8 *)(puVar2 + 4);
  if (g_wil_details_recordFeatureUsage != (code *)0x0) {
    local_68 = &local_38;
    (*g_wil_details_recordFeatureUsage)
              (0x3401a38,param_3 & 0xffffffff,1,&Feature_IFR01__private_reporting);
  }
  if ((((uint)param_2 >> 10 & 1) != 0) && ((int)param_3 != 0xfe)) {
    local_58._0_6_ = CONCAT24((short)(param_3 & 0xffffffff),0x3401a38);
    uVar1 = (uint6)local_58;
    local_58 = (ulonglong)(uint6)local_58;
    if (((uint)param_2 >> 0xb & 1) != 0) {
      local_58 = CONCAT26(1,uVar1);
    }
    RtlNotifyFeatureUsage(&local_58);
  }
  return (int)local_28 == 0;
}



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 140004864 =====

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



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 140004974 =====

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
  if ((Feature_IFR01__private_featureState & 2) != 0) {
    uVar1 = Feature_IFR01__private_featureState;
    while ((uVar1 & 1) == (param_1 & 1)) {
      LOCK();
      bVar3 = uVar1 == Feature_IFR01__private_featureState;
      if (bVar3) {
        Feature_IFR01__private_featureState = uVar2 | uVar1;
      }
      else {
        uVar1 = Feature_IFR01__private_featureState;
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



===== wil_details_GetCurrentFeatureEnabledState @ 1400049c8 =====

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



===== wil_details_IsEnabledFallback @ 140004b28 =====

uint wil_details_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  undefined4 *puVar1;
  ulonglong local_res18;
  
  local_res18 = (ulonglong)param_1 & 0xffffffff;
  if (((ulonglong)param_1 & 2) == 0) {
    puVar1 = &Feature_IFR01__private_featureState;
    local_res18 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                            (&Feature_IFR01__private_featureState,(ulonglong)param_1,0x140009570);
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



===== wil_details_MapReportingKind @ 140004bb8 =====

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



===== wil_details_RecordCachedUsage @ 140004c58 =====

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



===== wil_details_RecordFeatureUsageReporting @ 140004db0 =====

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



===== GetImageTuple @ 140004e34 =====

/* WARNING: Removing unreachable block (ram,0x000140004e6a) */

undefined8 GetImageTuple(undefined8 param_1,dword *param_2,dword *param_3)

{
  *param_2 = 0xb3cf2bc8;
  *param_3 = 0x14000;
  return 1;
}



===== InitializeTelemetryAssertsKMWorkerInternal @ 140004e84 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 InitializeTelemetryAssertsKMWorkerInternal(ushort *param_1)

{
  undefined8 uVar1;
  
  KeInitializeSpinLock(&g_AssertSpinLock);
  uVar1 = 0;
  g_ModuleName = (void *)ExAllocatePool2(0x40,(ulonglong)*param_1 + 1,0x74727341);
  if (g_ModuleName == (void *)0x0) {
    uVar1 = 0xc0000017;
  }
  else {
    memmove(g_ModuleName,*(void **)(param_1 + 4),(ulonglong)*param_1);
    _DAT_14000a188 = &g_MicrosoftTelemetryAssertsTriggeredList;
    g_MicrosoftTelemetryAssertsTriggeredList = &g_MicrosoftTelemetryAssertsTriggeredList;
    TraceLoggingRegisterEx_EtwRegister_EtwSetInformation(0x14000d040);
    TraceLoggingRegisterEx_EtwRegister_EtwSetInformation(0x14000d008);
    TraceLoggingRegisterEx_EtwRegister_EtwSetInformation(0x14000d078);
    LOCK();
    g_AssertsOperational = g_AssertsOperational + 1;
    UNLOCK();
  }
  return uVar1;
}



===== MicrosoftTelemetryAssertTriggeredArgsKM @ 140004f38 =====

void MicrosoftTelemetryAssertTriggeredArgsKM(char *param_1)

{
  IMAGE_DOS_HEADER *unaff_retaddr;
  
  MicrosoftTelemetryAssertTriggeredWorker(unaff_retaddr,1,param_1);
  return;
}



===== MicrosoftTelemetryAssertTriggeredWorker @ 140004f68 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void MicrosoftTelemetryAssertTriggeredWorker
               (IMAGE_DOS_HEADER *param_1,undefined8 param_2,char *param_3)

{
  code *pcVar1;
  longlong lVar2;
  undefined1 uVar3;
  char cVar4;
  byte bVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  longlong *plVar9;
  longlong *plVar10;
  undefined8 uVar11;
  longlong *plVar12;
  char *pcVar13;
  int iVar14;
  undefined1 *puVar15;
  dword *pdVar16;
  char *pcVar17;
  uint uVar18;
  longlong lVar19;
  undefined1 auStack_1a8 [8];
  undefined1 auStack_1a0 [120];
  undefined4 local_128;
  undefined1 local_118 [32];
  undefined1 *local_f8;
  undefined8 local_f0;
  undefined1 *local_e8;
  undefined8 local_e0;
  undefined1 *local_d8;
  undefined8 local_d0;
  undefined1 *local_c8;
  undefined8 local_c0;
  longlong local_b8 [2];
  undefined1 *local_a8;
  undefined8 local_a0;
  undefined1 *local_98;
  undefined8 local_90;
  undefined1 *local_88;
  undefined8 local_80;
  longlong local_78 [2];
  undefined1 *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  longlong local_48 [2];
  ulonglong local_38;
  
  puVar15 = auStack_1a8;
  local_38 = __security_cookie ^ (ulonglong)auStack_1a8;
  LOCK();
  UNLOCK();
  if (g_AssertsOperational == 0) goto LAB_1400054fc;
  uVar3 = KeAcquireSpinLockRaiseToDpc(&g_AssertSpinLock);
  puVar15 = auStack_1a8;
  for (plVar10 = g_MicrosoftTelemetryAssertsTriggeredList;
      (longlong **)plVar10 != &g_MicrosoftTelemetryAssertsTriggeredList;
      plVar10 = (longlong *)*plVar10) {
    plVar9 = plVar10 + -4;
    if ((IMAGE_DOS_HEADER *)*plVar9 == param_1) goto LAB_14000509a;
  }
  plVar9 = (longlong *)ExAllocatePool2(0x42,0x30,0x74727341);
  lVar19 = _DAT_fffff78000000320;
  puVar15 = auStack_1a8;
  if (plVar9 != (longlong *)0x0) {
    *plVar9 = (longlong)param_1;
    uVar6 = KeQueryTimeIncrement();
    puVar15 = auStack_1a8;
    *(undefined4 *)(plVar9 + 2) = 0;
    *(undefined4 *)((longlong)plVar9 + 0x14) = 0;
    *(undefined4 *)(plVar9 + 3) = 0;
    plVar9[1] = (longlong)((ulonglong)uVar6 * lVar19) / 10000 + -0xea61;
    plVar10 = plVar9 + 4;
    plVar12 = g_MicrosoftTelemetryAssertsTriggeredList;
    if ((longlong **)g_MicrosoftTelemetryAssertsTriggeredList[1] !=
        &g_MicrosoftTelemetryAssertsTriggeredList) {
      plVar12 = (longlong *)0x3;
      pcVar1 = (code *)swi(0x29);
      plVar10 = (longlong *)(*pcVar1)();
      puVar15 = auStack_1a0;
    }
    *plVar10 = (longlong)plVar12;
    plVar10[1] = (longlong)&g_MicrosoftTelemetryAssertsTriggeredList;
    plVar12[1] = (longlong)plVar10;
    g_MicrosoftTelemetryAssertsTriggeredList = plVar10;
LAB_14000509a:
    *(int *)(plVar9 + 2) = (int)plVar9[2] + 1;
    *(int *)((longlong)plVar9 + 0x14) = *(int *)((longlong)plVar9 + 0x14) + 1;
    lVar2 = _DAT_fffff78000000320;
    *(undefined8 *)(puVar15 + -8) = 0x1400050aa;
    uVar6 = KeQueryTimeIncrement();
    *(undefined4 *)(puVar15 + 0x54) = 0;
    *(undefined4 *)(puVar15 + 0x50) = 0;
    lVar19 = (longlong)((ulonglong)uVar6 * lVar2) / 10000;
    if (60000 < (ulonglong)(lVar19 - plVar9[1])) {
      pdVar16 = (dword *)(puVar15 + 0x50);
      *(undefined8 *)(puVar15 + -8) = 0x1400050ff;
      uVar11 = GetImageTuple((ulonglong)uVar6 * lVar2,(dword *)(puVar15 + 0x54),pdVar16);
      iVar7 = (int)uVar11;
      if ((((iVar7 == 0) || (param_1 < &IMAGE_DOS_HEADER_140000000)) ||
          ((IMAGE_DOS_HEADER *)(IMAGE_DOS_HEADER_140000000.e_magic + *(uint *)(puVar15 + 0x50)) <
           (IMAGE_DOS_HEADER *)(IMAGE_DOS_HEADER_140000000.e_magic + 1))) ||
         ((IMAGE_DOS_HEADER *)(IMAGE_DOS_HEADER_140000000.e_magic + *(uint *)(puVar15 + 0x50)) <
          param_1)) {
        iVar14 = 0;
      }
      else {
        iVar14 = (int)param_1 + -0x40000000;
      }
      *(int *)(puVar15 + 0x7c) = (int)plVar9[2];
      local_128 = *(undefined4 *)((longlong)plVar9 + 0x14);
      *(int *)(puVar15 + 0x78) = (int)plVar9[3];
      plVar9[1] = lVar19;
      *(undefined8 *)(puVar15 + -8) = 0x140005158;
      KeReleaseSpinLock(&g_AssertSpinLock,uVar3);
      uVar6 = *(uint *)(puVar15 + 0x54);
      uVar18 = 0;
      if (param_3 == (char *)0x0) {
        param_3 = g_ModuleName;
      }
      if (5 < DAT_14000d040) {
        *(undefined8 *)(puVar15 + -8) = 0x14000519d;
        pcVar17 = g_ModuleName;
        uVar18 = 0;
        cVar4 = _tlgKeywordOn(0x14000d040,0x400000000000);
        if (cVar4 != '\0') {
          local_f8 = puVar15 + 0x54;
          *(undefined4 *)(puVar15 + 0x54) = 10;
          local_e8 = puVar15 + 0x58;
          local_f0 = 4;
          *(int *)(puVar15 + 0x58) = iVar14;
          local_d8 = puVar15 + 0x5c;
          local_e0 = 4;
          local_d0 = 4;
          *(uint *)(puVar15 + 0x5c) = -(uint)(iVar7 != 0) & uVar6;
          local_c0 = 4;
          local_c8 = puVar15 + 0x60;
          *(uint *)(puVar15 + 0x60) = -(uint)(iVar7 != 0) & *(uint *)(puVar15 + 0x50);
          pcVar13 = "<unknown>";
          if (pcVar17 != (char *)0x0) {
            pcVar13 = pcVar17;
          }
          *(undefined8 *)(puVar15 + -8) = 0x140005225;
          _tlgCreate1Sz_char(local_b8,pcVar13);
          local_a8 = puVar15 + 100;
          *(undefined4 *)(puVar15 + 0x68) = local_128;
          local_98 = puVar15 + 0x68;
          *(undefined4 *)(puVar15 + 100) = *(undefined4 *)(puVar15 + 0x7c);
          local_a0 = 4;
          local_90 = 4;
          *(undefined8 *)(puVar15 + -8) = 0x14000525d;
          bVar5 = KeGetCurrentIrql();
          local_80 = 4;
          *(uint *)(puVar15 + 0x6c) = (uint)bVar5;
          uVar11 = 0;
          local_88 = puVar15 + 0x6c;
          *(undefined8 *)(puVar15 + -8) = 0x140005289;
          _tlgCreate1Sz_char(local_78,param_3);
          local_68 = puVar15 + 0x70;
          *(int *)(puVar15 + 0x70) = (int)uVar11;
          local_58 = puVar15 + 0x74;
          local_60 = 4;
          *(int *)(puVar15 + 0x74) = (int)uVar11;
          local_50 = 4;
          *(undefined8 *)(puVar15 + -8) = 0x1400052c1;
          _tlgCreate1Sz_char(local_48,"<unknown>");
          *(undefined1 **)(puVar15 + 0x28) = local_118;
          *(undefined4 *)(puVar15 + 0x20) = 0xe;
          *(undefined8 *)(puVar15 + -8) = 0x1400052de;
          _tlgWriteTransfer_EtwWriteTransfer
                    (local_118,&DAT_140008811,pdVar16,uVar11,*(undefined4 *)(puVar15 + 0x20),
                     *(undefined8 **)(puVar15 + 0x28));
          uVar18 = 0;
        }
      }
      if ((DAT_14000d078 <= uVar18) || (*(uint *)(puVar15 + 0x78) != uVar18)) goto LAB_1400054fc;
      *(undefined8 *)(puVar15 + -8) = 0x140005300;
      cVar4 = KeGetCurrentIrql();
      if (cVar4 != '\0') goto LAB_1400054fc;
      *(undefined4 *)(puVar15 + 0x40) = 0;
      *(undefined8 *)(puVar15 + 0x38) = 0;
      *(undefined8 *)(puVar15 + 0x30) = 0;
      *(ulonglong *)(puVar15 + 0x28) = (ulonglong)*(uint *)(puVar15 + 0x50);
      *(ulonglong *)(puVar15 + 0x20) = (ulonglong)uVar6;
      *(undefined8 *)(puVar15 + -8) = 0x14000534a;
      pcVar17 = g_ModuleName;
      iVar8 = DbgkWerCaptureLiveKernelDump(L"TELASSERT",0x1d1);
      if (5 < DAT_14000d040) {
        *(undefined8 *)(puVar15 + -8) = 0x140005374;
        cVar4 = _tlgKeywordOn(0x14000d040,0x400000000000);
        uVar11 = 0;
        if (cVar4 != '\0') {
          local_f8 = puVar15 + 0x78;
          *(undefined4 *)(puVar15 + 0x78) = 10;
          local_e8 = puVar15 + 0x74;
          local_f0 = 4;
          *(int *)(puVar15 + 0x74) = iVar14;
          local_d8 = puVar15 + 0x70;
          local_e0 = 4;
          local_d0 = 4;
          *(uint *)(puVar15 + 0x70) = -(uint)(iVar7 != 0) & uVar6;
          local_c0 = 4;
          *(uint *)(puVar15 + 0x6c) = -(uint)(iVar7 != 0) & *(uint *)(puVar15 + 0x50);
          local_c8 = puVar15 + 0x6c;
          pcVar13 = "<unknown>";
          if (g_ModuleName != (char *)0x0) {
            pcVar13 = g_ModuleName;
          }
          *(undefined8 *)(puVar15 + -8) = 0x140005408;
          _tlgCreate1Sz_char(local_b8,pcVar13);
          plVar10 = local_78;
          *(undefined4 *)(puVar15 + 0x68) = *(undefined4 *)(puVar15 + 0x7c);
          local_a8 = puVar15 + 0x68;
          local_a0 = 4;
          *(undefined4 *)(puVar15 + 100) = local_128;
          local_98 = puVar15 + 100;
          local_88 = puVar15 + 0x60;
          local_90 = 4;
          *(int *)(puVar15 + 0x60) = iVar8;
          local_80 = 4;
          *(undefined8 *)(puVar15 + -8) = 0x14000545a;
          _tlgCreate1Sz_char(plVar10,param_3);
          local_68 = puVar15 + 0x5c;
          *(int *)(puVar15 + 0x5c) = (int)uVar11;
          local_58 = puVar15 + 0x58;
          local_60 = 4;
          *(undefined1 **)(puVar15 + 0x28) = local_118;
          *(undefined4 *)(puVar15 + 0x20) = 0xd;
          *(int *)(puVar15 + 0x58) = (int)uVar11;
          local_50 = 4;
          *(undefined8 *)(puVar15 + -8) = 0x1400054a3;
          _tlgWriteTransfer_EtwWriteTransfer
                    (plVar10,&DAT_1400088bb,uVar11,pcVar17,*(undefined4 *)(puVar15 + 0x20),
                     *(undefined8 **)(puVar15 + 0x28));
        }
      }
      if (iVar8 != 0) goto LAB_1400054fc;
      *(undefined8 *)(puVar15 + -8) = 0x1400054b5;
      uVar3 = KeAcquireSpinLockRaiseToDpc(&g_AssertSpinLock);
      plVar10 = g_MicrosoftTelemetryAssertsTriggeredList;
      if ((longlong **)g_MicrosoftTelemetryAssertsTriggeredList !=
          &g_MicrosoftTelemetryAssertsTriggeredList) {
        do {
          if ((IMAGE_DOS_HEADER *)plVar10[-4] == param_1) {
            *(int *)(plVar10 + -1) = (int)plVar10[-1] + 1;
            break;
          }
          plVar10 = (longlong *)*plVar10;
        } while ((longlong **)plVar10 != &g_MicrosoftTelemetryAssertsTriggeredList);
      }
    }
  }
  *(undefined8 *)(puVar15 + -8) = 0x1400054f7;
  KeReleaseSpinLock(&g_AssertSpinLock,uVar3);
LAB_1400054fc:
  *(undefined8 *)(puVar15 + -8) = 0x140005508;
  return;
}



===== UninitializeTelemetryAssertsKM @ 14000552c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void UninitializeTelemetryAssertsKM(void)

{
  undefined8 *puVar1;
  code *pcVar2;
  undefined8 uVar3;
  undefined1 uVar4;
  undefined8 *puVar5;
  undefined1 *puVar6;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  LOCK();
  UNLOCK();
  if (g_AssertsOperational != 0) {
    LOCK();
    g_AssertsOperational = g_AssertsOperational + -1;
    UNLOCK();
    uVar4 = KeAcquireSpinLockRaiseToDpc(&g_AssertSpinLock);
    puVar6 = auStack_28;
    while ((undefined8 **)g_MicrosoftTelemetryAssertsTriggeredList !=
           &g_MicrosoftTelemetryAssertsTriggeredList) {
      if (((undefined8 **)g_MicrosoftTelemetryAssertsTriggeredList[1] !=
           &g_MicrosoftTelemetryAssertsTriggeredList) ||
         (puVar1 = (undefined8 *)*g_MicrosoftTelemetryAssertsTriggeredList,
         (undefined8 *)puVar1[1] != g_MicrosoftTelemetryAssertsTriggeredList)) {
        pcVar2 = (code *)swi(0x29);
        (*pcVar2)(3);
        puVar6 = auStack_20;
        break;
      }
      puVar5 = g_MicrosoftTelemetryAssertsTriggeredList + -4;
      g_MicrosoftTelemetryAssertsTriggeredList = puVar1;
      puVar1[1] = &g_MicrosoftTelemetryAssertsTriggeredList;
      ExFreePoolWithTag(puVar5,0x74727341);
    }
    *(undefined8 *)(puVar6 + -8) = 0x1400055bf;
    KeReleaseSpinLock(&g_AssertSpinLock,uVar4);
    if (g_ModuleName != 0) {
      *(undefined8 *)(puVar6 + -8) = 0x1400055dc;
      ExFreePoolWithTag(g_ModuleName,0x74727341);
      g_ModuleName = 0;
    }
    uVar3 = DAT_14000d098;
    DAT_14000d098 = 0;
    DAT_14000d078 = 0;
    *(undefined8 *)(puVar6 + -8) = 0x140005606;
    EtwUnregister(uVar3);
    uVar3 = DAT_14000d028;
    DAT_14000d028 = 0;
    _DAT_14000d008 = 0;
    *(undefined8 *)(puVar6 + -8) = 0x140005628;
    EtwUnregister(uVar3);
    uVar3 = DAT_14000d060;
    DAT_14000d060 = 0;
    DAT_14000d040 = 0;
    *(undefined8 *)(puVar6 + -8) = 0x14000564a;
    EtwUnregister(uVar3);
  }
  return;
}



===== _tlgDefineProvider_annotation__Tlgmtakm_hTelemetryAssertProv @ 140005664 =====

void _tlgDefineProvider_annotation__Tlgmtakm_hTelemetryAssertProv(void)

{
  return;
}



===== _guard_check_icall @ 140005680 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 140005698 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1400056bc =====

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



===== __GSHandlerCheck_SEH @ 140005724 =====

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



===== __security_check_cookie @ 1400057c0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== RtlCopyVolatileMemory @ 1400057f0 =====

void * __cdecl RtlCopyVolatileMemory(void *_Dst,void *_Src,size_t _Size)

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



===== RtlMoveVolatileMemory @ 140005800 =====

void * __cdecl RtlMoveVolatileMemory(void *_Dst,void *_Src,size_t _Size)

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



===== RtlSetVolatileMemory @ 140005810 =====

void * __cdecl RtlSetVolatileMemory(void *_Dst,int _Val,size_t _Size)

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



===== _guard_dispatch_icall @ 140005840 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 140005870 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140005870. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1400058a0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memmove @ 140005900 =====

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



===== memset @ 140005c00 =====

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



===== __memset_repmovs @ 140005d40 =====

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



===== __memset_query @ 140005dc0 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140005e40 =====

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



===== __memset_spec_ermsb_repmovsb @ 140005f80 =====

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



===== __memset_spec_plain @ 140006000 =====

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



===== memset$thunk$772440563353939046 @ 140007020 =====

void * __cdecl memset_thunk_772440563353939046(void *_Dst,int _Val,size_t _Size)

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



===== WppCleanupKm @ 14000e008 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WppCleanupKm(void)

{
  undefined8 *puVar1;
  
  if ((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    puVar1 = WPP_GLOBAL_Control;
    if (WPPTraceSuite == 4) {
      for (; puVar1 != (undefined8 *)0x0; puVar1 = (undefined8 *)puVar1[2]) {
        if (puVar1[7] != 0) {
          (*pfnEtwUnregister)();
          puVar1[7] = 0;
        }
      }
    }
    else if (WPPTraceSuite == 2) {
      IoWMIRegistrationControl(WPP_GLOBAL_Control,0x80000002);
    }
    WppAutoLogStop((longlong)WPP_GLOBAL_Control);
    WPP_GLOBAL_Control = &WPP_GLOBAL_Control;
    WPP_RECORDER_INITIALIZED = (undefined *)&WPP_RECORDER_INITIALIZED;
  }
  return;
}



===== WppInitKm @ 14000e0a4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void WppInitKm(undefined8 param_1,ushort *param_2)

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
      IoWMIRegistrationControl(&WPP_MAIN_CB);
    }
    WppAutoLogStart((ulonglong)WPP_GLOBAL_Control,(short *)0x0,param_2);
    WPP_RECORDER_INITIALIZED = &WPP_MAIN_CB;
  }
  return;
}



===== WppLoadTracingSupport @ 14000e16c =====

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



===== WppTraceCallback @ 14000e2b0 =====

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



===== wil_RtlStagingConfig_QueryFeatureState @ 14000e538 =====

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



===== wil_UninitializeFeatureStaging @ 14000e604 =====

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



===== wil_details_BuildFeatureStateCacheFromQueryResults @ 14000e65c =====

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
      goto LAB_14000e6b9;
    }
    if (param_1 == 0x117) {
      uVar1 = (*(uint *)(param_2 + 4) & 0x80) << 3 | 0x206;
      goto LAB_14000e6b9;
    }
  }
  uVar1 = 0x206;
LAB_14000e6b9:
  *param_3 = uVar1;
  return;
}



===== wil_details_EvaluateFeatureDependencies @ 14000e6c4 =====

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



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 14000e77c =====

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



===== wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState @ 14000e7b4 =====

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
        if (puVar1 == (undefined8 *)0x0) goto LAB_14000e836;
        if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
           (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
        if ((uVar5 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
          uVar5 = 0;
          goto LAB_14000e836;
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
LAB_14000e836:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 14000e880 =====

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



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 14000e8e0 =====

void wil_details_ReevaluateOnFeatureConfigurationChange(void)

{
  wil_details_UpdateFeatureConfiguredStates();
  wil_details_EvaluateFeatureDependencies();
  return;
}



===== wil_details_UpdateFeatureConfiguredStates @ 14000e8fc =====

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



===== TraceLoggingRegisterEx_EtwRegister_EtwSetInformation @ 14000e9b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int TraceLoggingRegisterEx_EtwRegister_EtwSetInformation(longlong param_1)

{
  longlong *plVar1;
  undefined2 uVar2;
  longlong lVar3;
  undefined2 *puVar4;
  code *pcVar5;
  int iVar6;
  undefined1 *puVar7;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  ulonglong local_18;
  
  puVar7 = auStack_48;
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  lVar3 = *(longlong *)(param_1 + 8);
  plVar1 = (longlong *)(param_1 + 0x20);
  local_28 = *(undefined4 *)(lVar3 + -0x10);
  uStack_24 = *(undefined4 *)(lVar3 + -0xc);
  uStack_20 = *(undefined4 *)(lVar3 + -8);
  uStack_1c = *(undefined4 *)(lVar3 + -4);
  if (*plVar1 != 0) {
    pcVar5 = (code *)swi(0x29);
    (*pcVar5)(5);
    puVar7 = auStack_40;
  }
  *(undefined8 *)(param_1 + 0x28) = 0;
  *(undefined8 *)(param_1 + 0x30) = 0;
  *(undefined8 *)(puVar7 + -8) = 0x14000ea13;
  iVar6 = EtwRegister(puVar7 + 0x20,_tlgEnableCallback,param_1,plVar1);
  if (iVar6 == 0) {
    puVar4 = *(undefined2 **)(param_1 + 8);
    lVar3 = *plVar1;
    uVar2 = *puVar4;
    *(undefined8 *)(puVar7 + -8) = 0x14000ea33;
    EtwSetInformation(lVar3,2,puVar4,uVar2);
  }
  *(undefined8 *)(puVar7 + -8) = 0x14000ea47;
  return iVar6;
}



===== _tlgEnableCallback @ 14000ea60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _tlgEnableCallback(undefined8 param_1,int param_2,byte param_3,undefined8 param_4,
                       undefined8 param_5,undefined8 param_6,int *param_7)

{
  if (param_7 != (int *)0x0) {
    if (param_2 == 0) {
      *param_7 = 0;
    }
    else if (param_2 == 1) {
      if (param_3 == 0) {
        *(undefined8 *)(param_7 + 4) = param_4;
        *param_7 = 0x100;
        *(undefined8 *)(param_7 + 6) = param_5;
      }
      else {
        *(undefined8 *)(param_7 + 4) = param_4;
        *param_7 = param_3 + 1;
        *(undefined8 *)(param_7 + 6) = param_5;
      }
    }
    if (*(code **)(param_7 + 10) != (code *)0x0) {
      (**(code **)(param_7 + 10))(param_1);
    }
  }
  return;
}



===== AuxKlibQueryModuleInformation @ 14000eb00 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong AuxKlibQueryModuleInformation(uint *param_1,undefined8 param_2,ulonglong param_3)

{
  uint uVar1;
  uint uVar2;
  undefined8 uVar3;
  uint uVar4;
  ulonglong uVar5;
  longlong lVar6;
  uint *puVar7;
  uint *puVar8;
  undefined8 *puVar9;
  uint uVar10;
  ulonglong uVar11;
  undefined4 uVar12;
  undefined1 auStack_188 [32];
  undefined4 local_168 [2];
  uint *local_160;
  uint local_158 [76];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_188;
  uVar11 = 0;
  local_168[0] = 0;
  local_158[1] = 0;
  memset(local_158,0,300);
  if (DAT_14000a170 == 1) {
    if (DAT_14000a168 == (code *)0x0) {
      uVar5 = (ulonglong)(-(uint)((param_3 & 7) != 0) & 0xc00000f1);
      if ((param_3 & 7) == 0) {
        puVar7 = local_158;
        uVar12 = 0x130;
        while( true ) {
          uVar4 = ZwQuerySystemInformation(0xb,puVar7,uVar12,local_168);
          uVar5 = (ulonglong)uVar4;
          if (-1 < (int)uVar4) break;
          if (uVar4 != 0xc0000004) goto LAB_14000ecb2;
          if (puVar7 != local_158) {
            ExFreePoolWithTag(puVar7,0);
          }
          puVar7 = (uint *)ExAllocatePoolWithQuotaTag(0x409,local_168[0],0x4b787541);
          if (puVar7 == (uint *)0x0) {
            return 0xc000009a;
          }
          local_160 = puVar7;
          uVar12 = local_168[0];
        }
        uVar4 = *puVar7;
        if ((ulonglong)uVar4 * 0x110 < 0x100000000) {
          if (param_3 != 0) {
            if (*param_1 < uVar4 * 0x110) {
              uVar5 = 0xc0000023;
            }
            else if (uVar4 != 0) {
              do {
                puVar9 = (undefined8 *)(uVar11 * 0x110 + param_3);
                *puVar9 = *(undefined8 *)(puVar7 + uVar11 * 0x4a + 6);
                *(uint *)(puVar9 + 1) = puVar7[uVar11 * 0x4a + 8];
                *(undefined2 *)((longlong)puVar9 + 0xc) =
                     *(undefined2 *)((longlong)puVar7 + uVar11 * 0x128 + 0x2e);
                puVar8 = puVar7 + uVar11 * 0x4a + 0xc;
                lVar6 = 2;
                puVar9 = (undefined8 *)((longlong)puVar9 + 0xe);
                do {
                  uVar3 = *(undefined8 *)(puVar8 + 2);
                  *puVar9 = *(undefined8 *)puVar8;
                  puVar9[1] = uVar3;
                  uVar3 = *(undefined8 *)(puVar8 + 6);
                  puVar9[2] = *(undefined8 *)(puVar8 + 4);
                  puVar9[3] = uVar3;
                  uVar3 = *(undefined8 *)(puVar8 + 10);
                  puVar9[4] = *(undefined8 *)(puVar8 + 8);
                  puVar9[5] = uVar3;
                  uVar3 = *(undefined8 *)(puVar8 + 0xe);
                  puVar9[6] = *(undefined8 *)(puVar8 + 0xc);
                  puVar9[7] = uVar3;
                  uVar3 = *(undefined8 *)(puVar8 + 0x12);
                  puVar9[8] = *(undefined8 *)(puVar8 + 0x10);
                  puVar9[9] = uVar3;
                  uVar3 = *(undefined8 *)(puVar8 + 0x16);
                  puVar9[10] = *(undefined8 *)(puVar8 + 0x14);
                  puVar9[0xb] = uVar3;
                  uVar10 = puVar8[0x19];
                  uVar1 = puVar8[0x1a];
                  uVar2 = puVar8[0x1b];
                  *(uint *)(puVar9 + 0xc) = puVar8[0x18];
                  *(uint *)((longlong)puVar9 + 100) = uVar10;
                  *(uint *)(puVar9 + 0xd) = uVar1;
                  *(uint *)((longlong)puVar9 + 0x6c) = uVar2;
                  uVar3 = *(undefined8 *)(puVar8 + 0x1e);
                  puVar9[0xe] = *(undefined8 *)(puVar8 + 0x1c);
                  puVar9[0xf] = uVar3;
                  puVar8 = puVar8 + 0x20;
                  lVar6 = lVar6 + -1;
                  puVar9 = puVar9 + 0x10;
                } while (lVar6 != 0);
                uVar10 = (int)uVar11 + 1;
                uVar11 = (ulonglong)uVar10;
              } while (uVar10 < *puVar7);
            }
          }
          *param_1 = uVar4 * 0x110;
        }
        else {
          uVar5 = 0xc0000095;
        }
LAB_14000ecb2:
        if (puVar7 != local_158) {
          ExFreePoolWithTag(puVar7,0);
        }
      }
    }
    else {
      uVar5 = (*DAT_14000a168)(param_1,0x110,param_3);
    }
  }
  else {
    uVar5 = 0xc0000001;
  }
  return uVar5;
}



===== AuxKlibInitialize @ 14000ed60 =====

undefined8 AuxKlibInitialize(void)

{
  uint local_res8 [8];
  
  local_res8[0] = 0;
  if (DAT_14000a170 == 0) {
    PsGetVersion(local_res8,0,0,0);
    if (local_res8[0] < 5) {
      return 0xc00000bb;
    }
    DAT_14000a168 = MmGetSystemRoutineAddress(&DAT_140008058);
    LOCK();
    DAT_14000a170 = 1;
    UNLOCK();
  }
  return 0;
}



===== AuxKlibQueryModuleInformation$filt$0 @ 14000edd0 =====

bool AuxKlibQueryModuleInformation_filt_0(undefined8 *param_1)

{
  return *(int *)*param_1 == -0x3fffff66;
}



===== entry @ 140010010 =====

void entry(void)

{
  __security_init_cookie();
  DriverEntry();
  return;
}



===== __security_init_cookie @ 140010044 =====

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



===== wil_InitializeFeatureStaging @ 140010078 =====

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



===== wil_details_PopulateInitialConfiguredFeatureStates @ 140010168 =====

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


