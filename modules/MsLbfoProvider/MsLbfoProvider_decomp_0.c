
===== _tlgWriteTransfer_EtwWriteTransfer @ 1c0001008 =====

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
  *param_6 = PTR_DAT_1c00182f8;
  *(uint *)(param_6 + 1) = (uint)*(ushort *)PTR_DAT_1c00182f8;
  param_6[2] = param_2 + 0xb;
  *(undefined4 *)((longlong)param_6 + 0xc) = 2;
  *(uint *)(param_6 + 3) = (uint)*(ushort *)(param_2 + 0xb);
  *(undefined4 *)((longlong)param_6 + 0x1c) = 1;
  EtwWriteTransfer(DAT_1c0018310,&local_18,0,0,param_5,param_6);
  return;
}



===== __report_gsfailure @ 1c00010c0 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== McGenEventWrite_EtwWriteTransfer @ 1c00010d0 =====

void McGenEventWrite_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined8 *param_5)

{
  ushort *puVar1;
  undefined4 uVar2;
  uint uVar3;
  
  puVar1 = DAT_1c0018258;
  uVar2 = 0;
  if (DAT_1c0018258 == (ushort *)0x0) {
    *param_5 = 0;
    uVar3 = 0;
  }
  else {
    *param_5 = DAT_1c0018258;
    uVar2 = 2;
    uVar3 = (uint)*puVar1;
  }
  *(uint *)(param_5 + 1) = uVar3;
  *(undefined4 *)((longlong)param_5 + 0xc) = uVar2;
  EtwWriteTransfer(MsLbfoEventProvider_Context,param_2,param_3,0,param_4,param_5);
  return;
}



===== McTemplateK0jd_EtwWriteTransfer @ 1c0001134 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0jd_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5)

{
  undefined1 auStackY_78 [32];
  undefined8 local_48 [2];
  undefined8 local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined1 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  local_28 = &param_5;
  local_2c = 0;
  local_30 = 0x10;
  local_1c = 0;
  local_20 = 4;
  local_38 = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,param_3,3,local_48);
  return;
}



===== McTemplateK0pjd_EtwWriteTransfer @ 1c000119c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0pjd_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  undefined1 auStackY_88 [32];
  undefined8 local_58 [2];
  undefined8 *local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  local_48 = &local_res20;
  local_40 = 8;
  local_38 = param_5;
  local_28 = &param_6;
  local_30 = 0x10;
  local_20 = 4;
  local_res20 = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,0,4,local_58);
  return;
}



===== WPP_SF_ds @ 1c000121c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_ds(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
              char *param_5)

{
  longlong lVar1;
  longlong lVar2;
  undefined4 local_res20 [2];
  
  if (param_5 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar2 = lVar1;
      lVar1 = lVar2 + 1;
    } while (param_5[lVar1] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (param_5 == (char *)0x0) {
    param_5 = "NULL";
  }
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,param_5,lVar2,0);
  return;
}



===== WPP_SF_dq @ 1c00012a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dq(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,&param_5,8,0);
  return;
}



===== WPP_SF_qL @ 1c00012f4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qL(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,&param_5,4,0);
  return;
}



===== WPP_SF_qq @ 1c0001348 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qq(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,&param_5,8,0);
  return;
}



===== WPP_SF_qqd @ 1c0001398 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,&param_5,8,&param_6,4,0);
  return;
}



===== WPP_SF_qqd_guid__MAC_ @ 1c00013f8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void WPP_SF_qqd_guid__MAC_
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined1 param_6,undefined8 param_7,undefined4 *param_8)

{
  undefined1 auStack_b8 [32];
  undefined8 *local_98;
  undefined8 local_90;
  undefined8 *local_88;
  undefined8 local_80;
  undefined1 *local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined4 *local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_38;
  undefined8 local_30;
  undefined4 local_28;
  undefined2 local_24;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_b8;
  local_48 = 0;
  local_50 = 6;
  local_38 = param_5;
  local_28 = *param_8;
  local_24 = *(undefined2 *)(param_8 + 1);
  local_58 = &local_28;
  local_78 = &param_6;
  local_60 = 0x10;
  local_68 = param_7;
  local_70 = 4;
  local_88 = &local_38;
  local_80 = 8;
  local_98 = &local_30;
  local_90 = 8;
  local_30 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,&WPP_fcac40b5fded30eddc607eed6843ce7c_Traceguids);
  return;
}



===== WPP_SF_qqdq @ 1c00014d8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqdq(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_fcac40b5fded30eddc607eed6843ce7c_Traceguids,param_2,&local_res20,8,
             &param_5,8,&param_6,4,&param_7,8,0);
  return;
}



===== WPP_SF_s @ 1c000154c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_s(undefined8 param_1,undefined2 param_2,undefined8 param_3,char *param_4)

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
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,param_4,lVar2,0);
  return;
}



===== lbfoAddNic @ 1c00015b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong lbfoAddNic(longlong param_1,longlong *param_2)

{
  undefined8 *puVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  bool bVar5;
  uint uVar6;
  char *pcVar7;
  longlong *plVar8;
  ulonglong uVar9;
  undefined8 uVar10;
  undefined2 uVar11;
  longlong *plVar12;
  undefined2 local_res8;
  undefined1 local_resa;
  
  local_res8 = 0;
  plVar8 = (longlong *)0x0;
  local_resa = 0;
  bVar5 = false;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
               &WPP_fcac40b5fded30eddc607eed6843ce7c_Traceguids,param_1,(char)param_2,
               (char)param_2[0x51]);
  }
  NdisAcquireRWLockWrite(*(undefined8 *)(param_1 + 0x5e8),&local_res8,0);
  plVar12 = param_2 + 0x5e;
  uVar6 = lbfoAllocateTimer(DAT_1c0018468,lbfoTFOConnectNicTimer);
  uVar9 = (ulonglong)uVar6;
  if (uVar6 == 0) {
    *(undefined4 *)(param_2 + 0x5d) = 0;
    plVar8 = (longlong *)
             (*(code *)(&PTR_lbfoSTGetAggregatorForNic_1c0018010)
                       [(longlong)*(int *)(param_1 + 0x5a8) * 9])(param_1,param_2);
    if (plVar8 != (longlong *)0x0) {
      puVar1 = (undefined8 *)plVar8[4];
      if ((longlong *)*puVar1 != plVar8 + 3) goto LAB_1c000192f;
      *param_2 = (longlong)(plVar8 + 3);
      param_2[1] = (longlong)puVar1;
      *puVar1 = param_2;
      plVar8[4] = (longlong)param_2;
      param_2[4] = (longlong)plVar8;
      *(short *)(plVar8 + 5) = (short)plVar8[5] + 1;
      *(short *)(param_1 + 0x8ea) = *(short *)(param_1 + 0x8ea) + 1;
      *(longlong **)(param_1 + 0x658 + (ulonglong)*(byte *)(param_2 + 0x51) * 8) = param_2;
      if (*(code **)(&DAT_1c0018020 + (longlong)*(int *)(param_1 + 0x5a8) * 0x48) != (code *)0x0) {
        plVar12 = plVar8;
        uVar6 = (**(code **)(&DAT_1c0018020 + (longlong)*(int *)(param_1 + 0x5a8) * 0x48))
                          (param_1,param_2);
        uVar9 = (ulonglong)uVar6;
        if (uVar6 != 0) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar11 = 0x13;
            pcVar7 = 
            "CALL_IF_PRESENT(TeamingModeOperations[Team->TeamingMode].AddNic, NDIS_STATUS_SUCCESS, Team, Nic, Aggregator)"
            ;
            goto LAB_1c00017f9;
          }
          goto LAB_1c0001811;
        }
      }
      bVar5 = true;
      if ((code *)(&PTR_lbfoNTHAddNic_1c0018110)[(longlong)*(int *)(param_1 + 0x5a4) * 0xf] ==
          (code *)0x0) {
        uVar9 = 0;
      }
      else {
        uVar6 = (*(code *)(&PTR_lbfoNTHAddNic_1c0018110)[(longlong)*(int *)(param_1 + 0x5a4) * 0xf])
                          (param_1,param_2);
        uVar9 = (ulonglong)uVar6;
        if (uVar6 != 0) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar11 = 0x14;
            pcVar7 = 
            "CALL_IF_PRESENT(LBAlgoOperations[Team->LBAlgo].AddNic, NDIS_STATUS_SUCCESS, Team, Nic)"
            ;
            goto LAB_1c00017f9;
          }
          goto LAB_1c0001811;
        }
      }
      *(undefined4 *)(param_2 + 0x14) = 1;
      goto LAB_1c00018d2;
    }
    uVar9 = 0xc000009a;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      plVar12 = (longlong *)&WPP_fcac40b5fded30eddc607eed6843ce7c_Traceguids;
      WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
               &WPP_fcac40b5fded30eddc607eed6843ce7c_Traceguids,"Aggregator");
    }
  }
  else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    uVar11 = 0x11;
    pcVar7 = 
    "lbfoAllocateTimer(Global.FilterDriverHandle, lbfoTFOConnectNicTimer, &Nic->TFO.ConnectTimer)";
LAB_1c00017f9:
    plVar12 = (longlong *)&WPP_fcac40b5fded30eddc607eed6843ce7c_Traceguids;
    WPP_SF_ds(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar11,
              &WPP_fcac40b5fded30eddc607eed6843ce7c_Traceguids,(int)uVar9,pcVar7);
  }
LAB_1c0001811:
  if (param_2[0x5e] != 0) {
    NdisFreeTimerObject();
  }
  if (plVar8 != (longlong *)0x0) {
    lVar2 = *param_2;
    if ((*(longlong **)(lVar2 + 8) != param_2) ||
       (plVar3 = (longlong *)param_2[1], (longlong *)*plVar3 != param_2)) {
LAB_1c000192f:
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)(3);
      pcVar4 = (code *)swi(3);
      uVar9 = (*pcVar4)();
      return uVar9;
    }
    *plVar3 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar3;
    *(short *)(plVar8 + 5) = (short)plVar8[5] + -1;
    *(short *)(param_1 + 0x8ea) = *(short *)(param_1 + 0x8ea) + -1;
    *(undefined8 *)(param_1 + 0x658 + (ulonglong)*(byte *)(param_2 + 0x51) * 8) = 0;
    if ((short)plVar8[5] == 0) {
      lbfoTMRemoveAggregator(param_1,plVar8,plVar12);
    }
    if ((bVar5) &&
       (*(code **)(&DAT_1c0018028 + (longlong)*(int *)(param_1 + 0x5a8) * 0x48) != (code *)0x0)) {
      plVar12 = (longlong *)&local_res8;
      (**(code **)(&DAT_1c0018028 + (longlong)*(int *)(param_1 + 0x5a8) * 0x48))(param_1,param_2);
    }
  }
LAB_1c00018d2:
  uVar10 = *(undefined8 *)(param_1 + 0x5e8);
  NdisReleaseRWLock(uVar10,&local_res8);
  if ((Microsoft_Windows_MsLbfoEventProviderEnableBits & 1) != 0) {
    McTemplateK0pjd_EtwWriteTransfer
              (uVar10,&MemberTeamedInfo,plVar12,param_1,param_2 + 6,(char)uVar9);
  }
  return uVar9;
}



===== lbfoCancelSoftFailTimer @ 1c000193c =====

void lbfoCancelSoftFailTimer(longlong param_1)

{
  char cVar1;
  
  if (*(char *)(param_1 + 0x289) != '\0') {
    *(undefined1 *)(param_1 + 0x289) = 0;
    cVar1 = NdisCancelTimerObject(*(undefined8 *)(param_1 + 0x290));
    if (cVar1 != '\0') {
      *(short *)(param_1 + 0xae) = *(short *)(param_1 + 0xae) + -1;
    }
  }
  return;
}



===== lbfoFindNicByGuid @ 1c0001988 =====

longlong lbfoFindNicByGuid(longlong param_1,longlong *param_2)

{
  longlong lVar1;
  byte bVar2;
  
  bVar2 = 1;
  while (((lVar1 = *(longlong *)(param_1 + 0x658 + (ulonglong)bVar2 * 8), lVar1 == 0 ||
          (*(longlong *)(lVar1 + 0x30) != *param_2)) || (*(longlong *)(lVar1 + 0x38) != param_2[1]))
        ) {
    bVar2 = bVar2 + 1;
    if (0x40 < bVar2) {
      return 0;
    }
  }
  return lVar1;
}



===== lbfoRemoveNic @ 1c00019c8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void lbfoRemoveNic(longlong *param_1,longlong *param_2)

{
  byte bVar1;
  short sVar2;
  code *pcVar3;
  longlong lVar4;
  longlong *plVar5;
  undefined2 *puVar6;
  undefined8 uVar7;
  undefined *puVar8;
  undefined2 local_res8;
  undefined1 local_resa;
  undefined2 local_res10;
  undefined1 local_res12;
  undefined2 local_res18;
  undefined1 local_res1a;
  undefined4 local_38;
  undefined2 local_34;
  
  local_res10 = 0;
  local_res12 = 0;
  local_res8 = 0;
  local_resa = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
               &WPP_fcac40b5fded30eddc607eed6843ce7c_Traceguids,param_1,(char)param_2,
               (char)param_2[0x51]);
  }
  NdisAcquireRWLockWrite(param_1[0xbe],&local_res10,0);
  NdisAcquireRWLockWrite(param_1[0xbd],&local_res8,1);
  *(undefined1 *)(param_2 + 0x5c) = 1;
  NdisReleaseRWLock(param_1[0xbd],&local_res8);
  NdisReleaseRWLock(param_1[0xbe],&local_res10);
  uVar7 = 0;
  NdisAcquireRWLockWrite(param_1[0xbd],&local_res8,0);
  puVar8 = (undefined *)CONCAT71((int7)((ulonglong)uVar7 >> 8),1);
  lbfoSetNicFailureReason((longlong)param_2,6,puVar8,0);
  lVar4 = param_2[0x58];
  *(undefined4 *)(param_2 + 0x58) = 0;
  if ((int)lVar4 == 1) {
    lbfoTFODisconnectNic((longlong)param_1,(longlong)param_2);
  }
  lbfoCancelSoftFailTimer((longlong)param_2);
  *(short *)((longlong)param_2 + 0xae) = *(short *)((longlong)param_2 + 0xae) + -1;
  plVar5 = (longlong *)param_1[0xbd];
  sVar2 = *(short *)((longlong)param_2 + 0xae);
  NdisReleaseRWLock(plVar5,&local_res8);
  if (sVar2 != 0) {
    plVar5 = param_2 + 0x16;
    puVar8 = (undefined *)0x0;
    KeWaitForSingleObject(plVar5,0,0,0,0);
  }
  if ((DAT_1c001849c & 8) != 0) {
    puVar8 = (undefined *)0x0;
    local_res18 = 0;
    local_res1a = 0;
    NdisAcquireRWLockWrite(param_1[0xbd],&local_res18);
    bVar1 = *(byte *)(param_2 + 0x69);
    puVar6 = &local_res18;
    *(byte *)(param_2 + 0x69) = bVar1 & 0xf9;
    plVar5 = (longlong *)param_1[0xbd];
    NdisReleaseRWLock();
    if ((bVar1 & 4) != 0) {
      local_38 = (undefined4)param_2[5];
      local_34 = *(undefined2 *)((longlong)param_2 + 0x2c);
      plVar5 = param_1;
      lbfoIssueOidRequestOnNic((longlong)param_1,puVar6,puVar8,*(byte *)(param_2 + 0x51),&local_38);
    }
  }
  if ((Microsoft_Windows_MsLbfoEventProviderEnableBits & 1) != 0) {
    McTemplateK0pjd_EtwWriteTransfer(plVar5,&MemberUnteamedInfo,puVar8,param_1,param_2 + 6,0);
  }
  puVar6 = (undefined2 *)0x0;
  NdisAcquireRWLockWrite(param_1[0xbd],&local_res8);
  if (param_2[0x5e] != 0) {
    NdisFreeTimerObject();
  }
  if (*(code **)(&DAT_1c0018028 + (longlong)(int)param_1[0xb5] * 0x48) != (code *)0x0) {
    puVar6 = &local_res8;
    (**(code **)(&DAT_1c0018028 + (longlong)(int)param_1[0xb5] * 0x48))(param_1,param_2);
  }
  if ((code *)(&PTR_lbfoNTHRemoveNic_1c0018118)[(longlong)*(int *)((longlong)param_1 + 0x5a4) * 0xf]
      != (code *)0x0) {
    (*(code *)(&PTR_lbfoNTHRemoveNic_1c0018118)[(longlong)*(int *)((longlong)param_1 + 0x5a4) * 0xf]
    )(param_1,param_2);
  }
  lVar4 = *param_2;
  if ((*(longlong **)(lVar4 + 8) != param_2) ||
     (plVar5 = (longlong *)param_2[1], (longlong *)*plVar5 != param_2)) {
    pcVar3 = (code *)swi(0x29);
    (*pcVar3)(3);
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  *plVar5 = lVar4;
  *(longlong **)(lVar4 + 8) = plVar5;
  *(short *)(param_2[4] + 0x28) = *(short *)(param_2[4] + 0x28) + -1;
  *(short *)((longlong)param_1 + 0x8ea) = *(short *)((longlong)param_1 + 0x8ea) + -1;
  param_1[(ulonglong)*(byte *)(param_2 + 0x51) + 0xcb] = 0;
  if ((short)((longlong *)param_2[4])[5] == 0) {
    lbfoTMRemoveAggregator((longlong)param_1,(longlong *)param_2[4],puVar6);
  }
  NdisReleaseRWLock(param_1[0xbd],&local_res8);
  return;
}



===== lbfoSetNicFailureReason @ 1c0001cec =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void lbfoSetNicFailureReason
               (longlong param_1,undefined4 param_2,undefined *param_3,longlong param_4)

{
  bool bVar1;
  char cVar2;
  undefined1 auStackY_a8 [32];
  undefined4 local_78 [4];
  undefined8 local_68 [4];
  longlong local_48;
  undefined4 local_40;
  undefined4 local_3c;
  longlong local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  if (((char)param_3 == '\0') && (*(char *)(param_1 + 0x289) == '\0')) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,
                &WPP_fcac40b5fded30eddc607eed6843ce7c_Traceguids,param_1,(char)param_2);
    }
    if ((char)param_4 == '\0') {
      lbfoCancelSoftFailTimer(param_1);
    }
    else {
      *(undefined1 *)(param_1 + 0x289) = 1;
      cVar2 = NdisSetCoalescableTimerObject
                        (*(undefined8 *)(param_1 + 0x290),0xfffffffffe363c80,0,param_1);
      if (cVar2 == '\0') {
        *(short *)(param_1 + 0xae) = *(short *)(param_1 + 0xae) + 1;
      }
    }
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      param_3 = &WPP_fcac40b5fded30eddc607eed6843ce7c_Traceguids;
      param_4 = param_1;
      WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,
                &WPP_fcac40b5fded30eddc607eed6843ce7c_Traceguids,param_1,(char)param_2);
    }
    if (5 < DAT_1c00182f0) {
      if (((DAT_1c0018300 & 0x200000000000) == 0) ||
         ((DAT_1c0018308 & 0x200000000000) != DAT_1c0018308)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (bVar1) {
        local_3c = 0;
        local_48 = *(longlong *)(param_1 + 0x298) + 0x24;
        local_2c = 0;
        local_1c = 0;
        local_38 = param_1 + 0x30;
        local_78[0] = *(undefined4 *)(param_1 + 0x2a0);
        local_28 = local_78;
        local_40 = 0x10;
        local_30 = 0x10;
        local_20 = 4;
        _tlgWriteTransfer_EtwWriteTransfer(0x10,&DAT_1c0016b11,param_3,param_4,5,local_68);
      }
    }
    lbfoCancelSoftFailTimer(param_1);
    *(short *)(param_1 + 0xaa) = *(short *)(param_1 + 0xaa) + 1;
  }
  *(undefined4 *)(param_1 + 0x2a0) = param_2;
  return;
}



===== lbfoSetOriginalMacOnNic @ 1c0001ed4 =====

void lbfoSetOriginalMacOnNic(longlong param_1,undefined8 *param_2)

{
  byte bVar1;
  
  bVar1 = *(byte *)(param_2 + 8);
  *(byte *)(param_2 + 8) = bVar1 & 0xfd;
  if ((((bVar1 & 4) != 0) && (*(char *)(param_1 + 0x2e0) == '\0')) && ((bVar1 & 1) == 0)) {
    *(short *)(param_1 + 0xae) = *(short *)(param_1 + 0xae) + 1;
    *(byte *)(param_2 + 8) = *(byte *)(param_2 + 8) | 1;
    NdisQueueIoWorkItem(*param_2,lbfoUpdateNicMacWorkItem,param_1);
  }
  return;
}



===== lbfoSetTeamMacOnNic @ 1c0001f2c =====

void lbfoSetTeamMacOnNic(longlong param_1,longlong param_2,undefined8 *param_3)

{
  byte bVar1;
  
  if ((*(int *)(param_2 + 0x28) != *(int *)(param_1 + 0x96)) ||
     (*(short *)(param_2 + 0x2c) != *(short *)(param_1 + 0x9a))) {
    bVar1 = *(byte *)(param_3 + 8);
    *(byte *)(param_3 + 8) = bVar1 | 2;
    if (((bVar1 & 4) == 0) && ((*(char *)(param_2 + 0x2e0) == '\0' && ((bVar1 & 1) == 0)))) {
      *(short *)(param_2 + 0xae) = *(short *)(param_2 + 0xae) + 1;
      *(byte *)(param_3 + 8) = *(byte *)(param_3 + 8) | 1;
      NdisQueueIoWorkItem(*param_3,lbfoUpdateNicMacWorkItem,param_2);
    }
  }
  return;
}



===== lbfoSoftFailTimer @ 1c0001fa0 =====

void lbfoSoftFailTimer(undefined8 param_1,longlong param_2,undefined8 param_3)

{
  short *psVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined2 local_res10;
  undefined1 local_res12;
  
  lVar2 = *(longlong *)(param_2 + 0x298);
  local_res10 = 0;
  local_res12 = 0;
  uVar3 = CONCAT71((int7)((ulonglong)param_3 >> 8),1);
  NdisAcquireRWLockWrite(*(undefined8 *)(lVar2 + 0x5e8),&local_res10,uVar3);
  if (*(char *)(param_2 + 0x289) != '\0') {
    lbfoSetNicFailureReason
              (param_2,*(undefined4 *)(param_2 + 0x2a0),
               (undefined *)CONCAT71((int7)((ulonglong)uVar3 >> 8),1),0);
  }
  psVar1 = (short *)(param_2 + 0xae);
  *psVar1 = *psVar1 + -1;
  if (*psVar1 == 0) {
    KeSetEvent(param_2 + 0xb0,0,0);
  }
  NdisReleaseRWLock(*(undefined8 *)(lVar2 + 0x5e8),&local_res10);
  return;
}



===== lbfoUpdateInitialNicState @ 1c0002048 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int lbfoUpdateInitialNicState(longlong param_1,longlong param_2)

{
  byte bVar1;
  longlong lVar2;
  longlong lVar3;
  int iVar4;
  undefined8 uVar5;
  uint uVar6;
  undefined1 auStackY_a8 [32];
  undefined2 local_68;
  undefined1 local_66;
  undefined4 local_64;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_a8;
  lVar2 = *(longlong *)(param_1 + 0x10);
  bVar1 = *(byte *)((ulonglong)*(byte *)(param_2 + 0x288) + 0x89 + param_1);
  local_64 = 0;
  local_68 = 0;
  local_66 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  uStack_38 = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
              &WPP_fcac40b5fded30eddc607eed6843ce7c_Traceguids,lVar2,(char)param_2);
  }
  uVar6 = (uint)bVar1;
  if ((DAT_1c001849c & 8) != 0) {
    iVar4 = lbfoIssueOidRequestOnFilter
                      (*(undefined8 *)(param_1 + 0x18),0x2021f,0,uVar6,&local_64,4,(undefined4 *)0x0
                      );
    if (iVar4 == 0) goto LAB_1c0002114;
  }
  local_64 = 1;
LAB_1c0002114:
  iVar4 = lbfoIssueOidRequestOnFilter
                    (*(undefined8 *)(param_1 + 0x18),0x1020e,0,uVar6,&local_60,0x30,
                     (undefined4 *)0x0);
  if (iVar4 == 0) {
    uVar5 = 0;
    NdisAcquireRWLockWrite(*(undefined8 *)(lVar2 + 0x5e8),&local_68);
    if (((*(int *)(param_2 + 0x2dc) == -1) && (*(byte *)(param_2 + 0x288) != 0)) &&
       (lVar3 = *(longlong *)(lVar2 + 0x658 + (ulonglong)*(byte *)(param_2 + 0x288) * 8), lVar3 != 0
       )) {
      *(undefined4 *)(lVar3 + 0x2dc) = local_64;
      lbfoUpdateNicPHYState(lVar2,lVar3,uVar5);
    }
    if (*(int *)(param_2 + 0x2d8) == -1) {
      lbfoUpdateNicState(lVar2,*(byte *)(param_2 + 0x288),(longlong)&local_60);
    }
    *(undefined4 *)(param_2 + 0xa0) = 2;
    NdisReleaseRWLock(*(undefined8 *)(lVar2 + 0x5e8),&local_68);
  }
  else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_ds(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
              &WPP_fcac40b5fded30eddc607eed6843ce7c_Traceguids,iVar4,
              "lbfoIssueOidRequestOnFilter(FilterContext->FilterModuleHandle, OID_GEN_PORT_STATE, NdisRequestQueryInformation, Port, &PortState, sizeof(PortState), NULL)"
             );
  }
  return iVar4;
}



===== lbfoUpdateNicMacWorkItem @ 1c0002240 =====

void lbfoUpdateNicMacWorkItem(longlong param_1)

{
  short *psVar1;
  byte bVar2;
  longlong lVar3;
  bool bVar4;
  int iVar5;
  byte bVar6;
  undefined2 *puVar7;
  undefined8 uVar8;
  uint uVar9;
  undefined2 uVar10;
  undefined2 local_res8;
  undefined1 local_resa;
  uint local_res18;
  undefined2 local_res1c;
  
  lVar3 = *(longlong *)(param_1 + 0x298);
  uVar9 = 0;
  local_res8 = 0;
  local_resa = 0;
  bVar4 = false;
  uVar10 = 0;
  ExAcquireFastMutex(param_1 + 0x310);
  uVar8 = 0;
  NdisAcquireRWLockWrite(*(undefined8 *)(lVar3 + 0x5e8),&local_res8);
  bVar2 = *(byte *)(param_1 + 0x348);
  bVar6 = bVar2 >> 2 & 1;
  if ((bVar2 >> 1 & 1) != bVar6) {
    bVar4 = true;
    if (bVar6 == 0) {
      uVar9 = *(uint *)(lVar3 + 0x96);
      uVar10 = *(undefined2 *)(lVar3 + 0x9a);
    }
    else {
      uVar9 = *(uint *)(param_1 + 0x28);
      uVar10 = *(undefined2 *)(param_1 + 0x2c);
    }
  }
  puVar7 = &local_res8;
  *(byte *)(param_1 + 0x348) = ((bVar2 & 2) * '\x02' ^ bVar2 & 0xfb) & 0xfe;
  NdisReleaseRWLock(*(undefined8 *)(lVar3 + 0x5e8));
  if (bVar4) {
    local_res18 = uVar9;
    local_res1c = uVar10;
    iVar5 = lbfoIssueOidRequestOnNic(lVar3,puVar7,uVar8,*(byte *)(param_1 + 0x288),&local_res18);
    if (iVar5 != 0) {
      uVar8 = 0;
      NdisAcquireRWLockWrite(*(undefined8 *)(lVar3 + 0x5e8),&local_res8);
      *(byte *)(param_1 + 0x348) =
           ((bVar2 >> 2) << 2 ^ *(byte *)(param_1 + 0x348)) & 4 ^ *(byte *)(param_1 + 0x348);
      *(undefined4 *)(param_1 + 0x2dc) = 0;
      lbfoUpdateNicPHYState(lVar3,param_1,uVar8);
      NdisReleaseRWLock(*(undefined8 *)(lVar3 + 0x5e8),&local_res8);
    }
  }
  ExReleaseFastMutex(param_1 + 0x310);
  local_res18 = local_res18 & 0xff000000;
  NdisAcquireRWLockWrite(*(undefined8 *)(lVar3 + 0x5e8),&local_res18,0);
  psVar1 = (short *)(param_1 + 0xae);
  *psVar1 = *psVar1 + -1;
  if (*psVar1 == 0) {
    KeSetEvent(param_1 + 0xb0,0,0);
  }
  NdisReleaseRWLock(*(undefined8 *)(lVar3 + 0x5e8),&local_res18);
  return;
}



===== LbfoFilterAttach @ 1c0002430 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong LbfoFilterAttach(longlong param_1,undefined8 param_2,longlong *param_3)

{
  uint uVar1;
  longlong *plVar2;
  longlong lVar3;
  ulonglong uVar4;
  byte bVar5;
  undefined8 uVar6;
  longlong *plVar7;
  ulonglong uVar8;
  undefined8 uVar9;
  undefined8 *puVar10;
  char *pcVar11;
  undefined1 auStackY_188 [32];
  undefined2 local_148;
  undefined1 local_146;
  undefined8 local_140;
  undefined8 local_138;
  undefined8 local_130;
  undefined4 local_128;
  undefined4 local_124;
  undefined4 local_120;
  undefined4 local_11c;
  undefined1 local_118 [4];
  undefined4 local_114;
  ushort local_100;
  byte local_fe;
  undefined4 local_fd;
  undefined2 local_f9;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_188;
  local_114 = 0;
  memset(local_118,0,0xc4);
  local_148 = 0;
  local_146 = 0;
  local_140 = 0x8018d;
  local_128 = 0x100180;
  local_124 = 0x100;
  local_120 = 0x5463694e;
  local_11c = 0x7c;
  if (((int)param_3[9] != 0) || ((short)param_3[0xc] != 6)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
               &WPP_1f756999873135a83baf07d5dbd19e82_Traceguids,(int)param_3[9]);
    }
    return 0xc000000d;
  }
  uVar9 = 0x5463694e;
  local_130 = 0x10;
  local_138 = 1;
  uVar6 = 0x140;
  plVar2 = (longlong *)ExAllocatePool3(0x40,0x140,0x5463694e,&local_138);
  if (plVar2 == (longlong *)0x0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc000009a;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return 0xc000009a;
    }
    WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
             &WPP_1f756999873135a83baf07d5dbd19e82_Traceguids,"FilterContext");
    return 0xc000009a;
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qdZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,uVar9,plVar2,(char)param_3[3],
               (wchar_t *)param_3[4]);
  }
  *(undefined4 *)(plVar2 + 0x1d) = 0;
  *(undefined2 *)((longlong)plVar2 + 0xce) = 1;
  KeInitializeEvent(plVar2 + 0x1a,0,0);
  plVar2[3] = param_1;
  *(int *)(plVar2 + 0x23) = (int)param_3[3];
  uVar1 = KeGetRecommendedSharedDataAlignment();
  uVar4 = (ulonglong)uVar1;
  puVar10 = (undefined8 *)0x5463694e;
  plVar7 = (longlong *)((ulonglong)DAT_1c0018498 * 0x140 + -1 + uVar4);
  lVar3 = ExAllocatePool3(0x40,plVar7,0x5463694e,&local_138);
  plVar2[0x21] = lVar3;
  if (lVar3 == 0) {
    uVar8 = 0xc000009a;
    param_3 = plVar7;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1c0002add;
    param_3 = (longlong *)0xd;
    pcVar11 = "FilterContext->PerProcNblTrackersBuffer";
  }
  else {
    puVar10 = (undefined8 *)0x5463694e;
    plVar7 = (longlong *)(ulonglong)*(ushort *)(param_3[4] + 2);
    lVar3 = ExAllocatePool3(0x40);
    plVar2[0x25] = lVar3;
    if (lVar3 == 0) {
      uVar8 = 0xc000009a;
      param_3 = plVar7;
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1c0002add;
      param_3 = (longlong *)0xe;
      pcVar11 = "FilterContext->MiniportInstanceName.Buffer";
    }
    else {
      *(undefined2 *)((longlong)plVar2 + 0x122) = *(undefined2 *)(param_3[4] + 2);
      RtlCopyUnicodeString(plVar2 + 0x24,param_3[4]);
      plVar7 = (longlong *)&local_128;
      plVar2[8] = plVar2[0x21] + -1 + uVar4 & -uVar4;
      lVar3 = NdisAllocateNetBufferListPool(param_1);
      plVar2[0x1e] = lVar3;
      if (lVar3 == 0) {
        uVar8 = 0xc000009a;
        param_3 = plVar7;
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1c0002add;
        param_3 = (longlong *)0xf;
        pcVar11 = "FilterContext->NblPool";
      }
      else {
        lVar3 = NdisAllocateIoWorkItem(DAT_1c0018468);
        plVar2[0x1f] = lVar3;
        if (lVar3 != 0) {
          uVar4 = lbfoFindOrCreateTeam(plVar2,(longlong)param_3);
          uVar8 = uVar4 & 0xffffffff;
          if ((int)uVar4 == 0) {
            lVar3 = plVar2[2];
            puVar10 = &local_140;
            param_3 = plVar2;
            uVar1 = NdisFSetAttributes(param_1);
            uVar8 = (ulonglong)uVar1;
            if (uVar1 == 0) {
              puVar10 = (undefined8 *)0x0;
              param_3 = (longlong *)0xfa010101;
              *(undefined4 *)(plVar2 + 0x1d) = 1;
              uVar1 = lbfoIssueOidRequestOnFilter
                                (param_1,0xfa010101,0,0,local_118,200,(undefined4 *)0x0);
              uVar8 = (ulonglong)uVar1;
              if (uVar1 == 0) {
                uVar4 = CONCAT71((int7)((ulonglong)param_3 >> 8),
                                 *(undefined1 *)((longlong)plVar2 + 0xcc)) & 0xfffffffffffffffe;
                bVar5 = (byte)uVar4 | local_fe & 1;
                param_3 = (longlong *)CONCAT71((int7)(uVar4 >> 8),bVar5);
                *(byte *)((longlong)plVar2 + 0xcc) = bVar5;
                *(ushort *)((longlong)plVar2 + 0xca) =
                     local_100 & 0xfff | *(ushort *)((longlong)plVar2 + 0xca) & 0xf000;
                if (((((local_fe & 1) != 0) && (*(int *)(lVar3 + 0x5a4) - 1U < 2)) &&
                    (*(int *)(lVar3 + 0x5a8) == 1)) && ((DAT_1c001849c & 0x10) == 0)) {
                  KeInitializeEvent(lVar3 + 0x588,0,0);
                  plVar7 = (longlong *)(lVar3 + 0x240);
                  memset((void *)(lVar3 + 0x248),0,0x340);
                  vmqClearCapabilities((undefined4 *)(lVar3 + 0x248));
                  *plVar7 = param_1;
                  ExAcquireFastMutex(lVar3 + 0x5b0);
                  NdisAcquireRWLockWrite(*(undefined8 *)(lVar3 + 0x5e8),&local_148,0);
                  *(byte *)(lVar3 + 0x56c) = local_fe >> 1 & 1;
                  *(byte *)(lVar3 + 0x56d) = local_fe >> 3 & 1;
                  *(byte *)(lVar3 + 0x56e) = local_fe >> 2 & 1;
                  vmqClearCapabilities((undefined4 *)(lVar3 + 0x3dc));
                  if (*(char *)(lVar3 + 0x3d8) == '\0') {
                    vmqIndicateQueueAllocState(plVar7,'\0');
                    if (*(int *)(lVar3 + 0x570) == 0) {
                      vmqIndicateNewCaps(plVar7);
                    }
                    else {
                      *(undefined1 *)(lVar3 + 0x3d8) = 1;
                    }
                  }
                  *(byte *)((longlong)plVar2 + 0xcc) = *(byte *)((longlong)plVar2 + 0xcc) | 2;
                  param_3 = (longlong *)&local_148;
                  *(longlong **)(lVar3 + 0xa8) = plVar2;
                  NdisReleaseRWLock(*(undefined8 *)(lVar3 + 0x5e8));
                  ExReleaseFastMutex(lVar3 + 0x5b0);
                  lbfoQueryMuxVmqCaps((longlong)plVar2);
                }
                puVar10 = (undefined8 *)WPP_GLOBAL_Control;
                if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   (3 < (byte)WPP_GLOBAL_Control[0x29])) {
                  bVar5 = *(byte *)((longlong)plVar2 + 0xcc);
                  pcVar11 = "sum";
                  if ((bVar5 & 2) == 0) {
                    pcVar11 = "min";
                  }
                  param_3 = (longlong *)(ulonglong)(bVar5 & 1);
                  WPP_SF_qqdls(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),param_3,WPP_GLOBAL_Control
                               ,plVar2,(char)lVar3,(char)*(undefined2 *)((longlong)plVar2 + 0xca),
                               bVar5 & 1,pcVar11);
                }
                if (*(int *)(lVar3 + 0x20) == 0) {
                  *(undefined4 *)(lVar3 + 0x9c) = local_fd;
                  *(undefined2 *)(lVar3 + 0xa0) = local_f9;
                  uVar1 = lbfoInitTeamWithPnP(lVar3);
                  uVar8 = (ulonglong)uVar1;
                  if (uVar1 != 0) {
                    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                       ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1c0002add;
                    param_3 = (longlong *)0x15;
                    pcVar11 = "lbfoInitTeamWithPnP(Team)";
                    goto LAB_1c0002ac5;
                  }
                }
                uVar1 = lbfoCheckNics((longlong)plVar2,param_3,(undefined *)puVar10);
                uVar8 = (ulonglong)uVar1;
                if (uVar1 == 0) {
                  NdisAcquireRWLockWrite(*(undefined8 *)(lVar3 + 0x5e8),&local_148,0);
                  if ((*(byte *)((longlong)plVar2 + 0xcc) & 2) != 0) {
                    lbfoCalculateVmqCaps(lVar3);
                  }
                  lbfoGenerateStatusIndication(param_1,0x40010017,lVar3 + 0x890,0x28);
                  NdisReleaseRWLock(*(undefined8 *)(lVar3 + 0x5e8),&local_148);
                  return 0;
                }
                if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                   ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1c0002add;
                param_3 = (longlong *)0x16;
                pcVar11 = "lbfoCheckNics(FilterContext)";
              }
              else {
                if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                   ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1c0002add;
                param_3 = (longlong *)0x13;
                pcVar11 = 
                "lbfoIssueOidRequestOnFilter(FilterModuleHandle, OID_IMPLAT_ADAPTER_INFORMATION, NdisRequestQueryInformation, 0, &TeamInfo, sizeof(TeamInfo), NULL)"
                ;
              }
            }
            else {
              if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                 ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1c0002add;
              param_3 = (longlong *)0x12;
              pcVar11 = "NdisFSetAttributes(FilterModuleHandle, FilterContext, &FilterAttribs)";
            }
          }
          else {
            if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
               ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1c0002add;
            param_3 = (longlong *)0x11;
            pcVar11 = "lbfoFindOrCreateTeam(FilterContext, Params)";
          }
LAB_1c0002ac5:
          puVar10 = (undefined8 *)&WPP_1f756999873135a83baf07d5dbd19e82_Traceguids;
          WPP_SF_ds(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(short)param_3,
                    &WPP_1f756999873135a83baf07d5dbd19e82_Traceguids,(int)uVar8,pcVar11);
          goto LAB_1c0002add;
        }
        uVar8 = 0xc000009a;
        param_3 = plVar7;
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1c0002add;
        param_3 = (longlong *)0x10;
        pcVar11 = "FilterContext->OidWorkItem = NdisAllocateIoWorkItem(Global.FilterDriverHandle)";
      }
    }
  }
  uVar8 = 0xc000009a;
  puVar10 = (undefined8 *)&WPP_1f756999873135a83baf07d5dbd19e82_Traceguids;
  WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(short)param_3,
           &WPP_1f756999873135a83baf07d5dbd19e82_Traceguids,pcVar11);
LAB_1c0002add:
  LbfoFilterDetach(plVar2,(undefined *)param_3,(undefined *)puVar10);
  return uVar8;
}



===== LbfoFilterDetach @ 1c0002bb0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void LbfoFilterDetach(longlong *param_1,undefined *param_2,undefined *param_3)

{
  short *psVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  longlong lVar5;
  undefined *puVar6;
  longlong *plVar7;
  undefined1 auStack_78 [32];
  undefined2 local_48;
  undefined1 local_46;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_78;
  lVar2 = param_1[2];
  local_48 = 0;
  local_46 = 0;
  local_40 = 0;
  uStack_38 = 0;
  local_30 = 0;
  puVar6 = WPP_GLOBAL_Control;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_3 = &WPP_1f756999873135a83baf07d5dbd19e82_Traceguids;
    puVar6 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
    param_2 = (undefined *)0x1a;
    WPP_SF_qL(puVar6,0x1a,&WPP_1f756999873135a83baf07d5dbd19e82_Traceguids,param_1,
              (char)param_1[0x23]);
  }
  if ((Microsoft_Windows_MsLbfoEventProviderEnableBits & 1) != 0) {
    param_2 = &RemovingTeamNicInfo;
    param_3 = (undefined *)0x0;
    McTemplateK0pd_EtwWriteTransfer(puVar6,&RemovingTeamNicInfo,0,param_1,0);
  }
  lVar5 = param_1[0x1d];
  *(undefined4 *)(param_1 + 0x1d) = 5;
  if (lVar2 != 0) {
    if (((int)lVar5 == 1) && ((*(byte *)((longlong)param_1 + 0xcc) & 4) == 0)) {
      lbfoFilterPreDetach((longlong)param_1,param_2,param_3);
    }
    NdisAcquireRWLockWrite(*(undefined8 *)(lVar2 + 0x5e8),&local_48,0);
    psVar1 = (short *)((longlong)param_1 + 0xce);
    *psVar1 = *psVar1 + -1;
    if (*psVar1 != 0) {
      NdisReleaseRWLock(*(undefined8 *)(lVar2 + 0x5e8),&local_48);
      KeWaitForSingleObject(param_1 + 0x1a,0,0,0);
      NdisAcquireRWLockWrite(*(undefined8 *)(lVar2 + 0x5e8),&local_48,0);
    }
    lVar5 = *param_1;
    if ((*(longlong **)(lVar5 + 8) != param_1) ||
       (plVar7 = (longlong *)param_1[1], (longlong *)*plVar7 != param_1)) {
LAB_1c0002e8f:
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)(3);
      pcVar4 = (code *)swi(3);
      (*pcVar4)();
      return;
    }
    *plVar7 = lVar5;
    *(longlong **)(lVar5 + 8) = plVar7;
    if (*(longlong **)(lVar2 + 0x10) == (longlong *)(lVar2 + 0x10)) {
      local_28 = *(undefined4 *)(lVar2 + 0x24);
      uStack_24 = *(undefined4 *)(lVar2 + 0x28);
      uStack_20 = *(undefined4 *)(lVar2 + 0x2c);
      uStack_1c = *(undefined4 *)(lVar2 + 0x30);
      NdisReleaseRWLock();
      KeAcquireInStackQueuedSpinLock(&DAT_1c0018478,&local_40);
      for (plVar7 = DAT_1c0018480; (longlong **)plVar7 != &DAT_1c0018480;
          plVar7 = (longlong *)*plVar7) {
        if ((*(longlong *)((longlong)plVar7 + 0x24) == CONCAT44(uStack_24,local_28)) &&
           (*(longlong *)((longlong)plVar7 + 0x2c) == CONCAT44(uStack_1c,uStack_20))) {
          if ((plVar7 != (longlong *)0x0) && ((longlong *)plVar7[2] == plVar7 + 2)) {
            lVar2 = *plVar7;
            if ((*(longlong **)(lVar2 + 8) != plVar7) ||
               (plVar3 = (longlong *)plVar7[1], (longlong *)*plVar3 != plVar7)) goto LAB_1c0002e8f;
            *plVar3 = lVar2;
            *(longlong **)(lVar2 + 8) = plVar3;
            KeReleaseInStackQueuedSpinLock(&local_40);
            lbfoRemoveTeam((longlong)plVar7);
            param_1[2] = 0;
            goto LAB_1c0002d94;
          }
          break;
        }
      }
      KeReleaseInStackQueuedSpinLock(&local_40);
    }
    else {
      NdisReleaseRWLock(*(undefined8 *)(lVar2 + 0x5e8),&local_48);
    }
  }
LAB_1c0002d94:
  if (param_1[0x1e] != 0) {
    NdisFreeNetBufferListPool();
  }
  if (param_1[0x21] != 0) {
    ExFreePoolWithTag(param_1[0x21],0x5463694e);
  }
  if (param_1[0x25] != 0) {
    ExFreePoolWithTag(param_1[0x25],0x5463694e);
  }
  if (param_1[0x1f] != 0) {
    NdisFreeIoWorkItem();
  }
  ExFreePoolWithTag(param_1,0x5463694e);
  return;
}



===== LbfoFilterPause @ 1c0002ea0 =====

uint LbfoFilterPause(longlong param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  undefined4 uVar3;
  undefined2 local_res8;
  undefined1 local_resa;
  
  local_res8 = 0;
  local_resa = 0;
  lVar2 = *(longlong *)(param_1 + 0x10);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
               &WPP_1f756999873135a83baf07d5dbd19e82_Traceguids,param_1,
               (char)*(undefined4 *)(param_1 + 0x118),(char)*(undefined4 *)(param_2 + 8));
  }
  NdisAcquireRWLockWrite(*(undefined8 *)(lVar2 + 0x5e8),&local_res8,0);
  iVar1 = *(int *)(param_1 + 0xec);
  uVar3 = 4;
  if (iVar1 == 0) {
    uVar3 = 2;
  }
  *(undefined4 *)(param_1 + 0xe8) = uVar3;
  NdisReleaseRWLock(*(undefined8 *)(lVar2 + 0x5e8),&local_res8);
  return -(uint)(iVar1 != 0) & 0x103;
}



===== LbfoFilterRestart @ 1c0002f80 =====

undefined8 LbfoFilterRestart(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  undefined2 local_res8;
  undefined1 local_resa;
  
  lVar1 = *(longlong *)(param_1 + 0x10);
  local_res8 = 0;
  local_resa = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
              &WPP_1f756999873135a83baf07d5dbd19e82_Traceguids,param_1,
              (char)*(undefined4 *)(param_1 + 0x118));
  }
  lVar2 = *(longlong *)(param_2 + 0x10);
  if (((lVar2 != 0) && (*(int *)(lVar2 + 8) == 0x1021d)) && (0x53 < *(uint *)(lVar2 + 0xc))) {
    *(undefined2 *)(param_1 + 0x48) = *(undefined2 *)(lVar2 + 0x54);
    *(int *)(lVar2 + 0x54) = *(int *)(lVar2 + 0x54) + 0x10;
  }
  NdisAcquireRWLockWrite(*(undefined8 *)(lVar1 + 0x5e8),&local_res8,0);
  *(undefined4 *)(param_1 + 0xe8) = 3;
  NdisReleaseRWLock(*(undefined8 *)(lVar1 + 0x5e8),&local_res8);
  lbfoPrimeSwitchIfNeeded(lVar1);
  return 0;
}



===== LbfoStatusIndication @ 1c0003070 =====

void LbfoStatusIndication(longlong param_1,longlong param_2,undefined8 param_3)

{
  ushort uVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  bool bVar6;
  uint uVar7;
  byte bVar8;
  undefined2 local_res8;
  undefined1 local_resa;
  
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_res8 = 0;
  local_resa = 0;
  bVar6 = true;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),param_2,param_3,
              *(undefined4 *)(param_2 + 0x14),(char)*(undefined4 *)(param_1 + 0x118));
  }
  NdisAcquireRWLockWrite(*(undefined8 *)(lVar3 + 0x5e8),&local_res8,0);
  bVar8 = *(byte *)(param_1 + 0xcc) & 2;
  if ((bVar8 == 0) ||
     ((((iVar2 = *(int *)(param_2 + 0x14), iVar2 != 0x4002000d && (iVar2 != 0x40020010)) &&
       (iVar2 != 0x40020020)) && ((iVar2 != 0x40020040 && (iVar2 != 0x40020050)))))) {
    iVar2 = *(int *)(param_2 + 0x14);
    if (iVar2 == 0x40010017) {
      if ((*(byte *)(param_1 + 0xcc) & 4) == 0) {
        uVar7 = 0x28;
        uVar1 = *(ushort *)((longlong)*(void **)(param_2 + 0x30) + 2);
        if (uVar1 < 0x28) {
          uVar7 = (uint)uVar1;
        }
        memcpy((void *)(lVar3 + 0x868),*(void **)(param_2 + 0x30),(ulonglong)uVar7);
        *(short *)(lVar3 + 0x86a) = (short)uVar7;
        lbfoUpdateLinkState(lVar3);
        bVar6 = false;
      }
    }
    else if (iVar2 == 0x40010022) {
      if (*(int *)(param_2 + 0x10) - 1U < 0x40) {
        lbfoUpdateNicState(lVar3,*(byte *)((ulonglong)(*(int *)(param_2 + 0x10) - 1) + 0x4a +
                                          param_1),*(longlong *)(param_2 + 0x30));
      }
    }
    else if (iVar2 == 0x40050001) {
      lVar4 = *(longlong *)(param_2 + 0x30);
      if (*(int *)(lVar4 + 0x14) == 0x40020060) {
        if (((*(int *)(param_2 + 0x10) - 1U < 0x40) && (3 < *(uint *)(lVar4 + 0x38))) &&
           ((bVar8 = *(byte *)((ulonglong)(*(int *)(param_2 + 0x10) - 1) + 0x4a + param_1),
            bVar8 != 0 && (lVar5 = *(longlong *)(lVar3 + 0x658 + (ulonglong)bVar8 * 8), lVar5 != 0))
           )) {
          *(undefined4 *)(lVar5 + 0x2dc) = **(undefined4 **)(lVar4 + 0x30);
          lbfoUpdateNicPHYState(lVar3,lVar5,lVar4);
        }
      }
      else if ((((bVar8 != 0) &&
                (bVar8 = *(byte *)((ulonglong)(*(int *)(param_2 + 0x10) - 1) + 0x4a + param_1),
                bVar8 != 0)) &&
               ((lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x658 + (ulonglong)bVar8 * 8)
                , lVar5 != 0 &&
                (((*(int *)(lVar4 + 0x14) == 0x4002000d && (*(longlong *)(lVar4 + 0x30) != 0)) &&
                 (0xf < *(uint *)(lVar4 + 0x38))))))) &&
              ((*(int *)(lVar5 + 0x260) != 0 && (*(int *)(*(longlong *)(lVar4 + 0x30) + 0xc) == 3)))
              ) {
        KeSetEvent(lVar5 + 0x270,0,0);
      }
    }
  }
  else {
    bVar6 = false;
    lbfoProcessMuxVmqStatusIndication(lVar3,param_2);
  }
  NdisReleaseRWLock(*(undefined8 *)(lVar3 + 0x5e8),&local_res8);
  if (bVar6) {
    NdisFIndicateStatus(*(undefined8 *)(param_1 + 0x18),param_2);
  }
  return;
}



===== McTemplateK0pd_EtwWriteTransfer @ 1c00032d4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0pd_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5)

{
  undefined8 local_res20;
  undefined1 auStackY_78 [32];
  undefined8 local_48 [2];
  undefined8 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined1 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  local_38 = &local_res20;
  local_28 = &param_5;
  local_2c = 0;
  local_30 = 8;
  local_1c = 0;
  local_20 = 4;
  local_res20 = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,param_3,3,local_48);
  return;
}



===== WPP_SF_LD @ 1c0003344 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_LD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_1f756999873135a83baf07d5dbd19e82_Traceguids,0x1b,local_res20,4,
             &param_5,4,0);
  return;
}



===== WPP_SF_d @ 1c000339c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_d(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,0);
  return;
}



===== WPP_SF_dD @ 1c00033e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_1f756999873135a83baf07d5dbd19e82_Traceguids,0x1c,local_res20,4,
             &param_5,4,0);
  return;
}



===== WPP_SF_qdZ @ 1c0003438 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qdZ(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,wchar_t *param_6)

{
  wchar_t *pwVar1;
  wchar_t *pwVar2;
  wchar_t wVar3;
  undefined8 local_res20;
  
  if (param_6 == (wchar_t *)0x0) {
    wVar3 = L'\b';
  }
  else {
    wVar3 = *param_6;
    if (*param_6 != L'\0') {
      pwVar1 = *(wchar_t **)(param_6 + 4);
      goto LAB_1c0003471;
    }
  }
  pwVar1 = L"NULL";
LAB_1c0003471:
  pwVar2 = param_6;
  if (param_6 == (wchar_t *)0x0) {
    pwVar2 = L"\b";
  }
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_1f756999873135a83baf07d5dbd19e82_Traceguids,0xc,&local_res20,8,
             &param_5,4,pwVar2,2,pwVar1,wVar3,0);
  return;
}



===== WPP_SF_qdd @ 1c00034f4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qdd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,&param_5,4,&param_6,4,0);
  return;
}



===== WPP_SF_qqdls @ 1c0003554 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqdls(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined1 param_5,undefined1 param_6,undefined1 param_7,char *param_8)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  undefined8 local_res20;
  
  if (param_8 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar2 = lVar1;
      lVar1 = lVar2 + 1;
    } while (param_8[lVar1] != '\0');
    lVar2 = lVar2 + 2;
  }
  pcVar3 = param_8;
  if (param_8 == (char *)0x0) {
    pcVar3 = "NULL";
  }
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_1f756999873135a83baf07d5dbd19e82_Traceguids,0x14,&local_res20,8,
             &param_5,8,&param_6,4,&param_7,4,pcVar3,lVar2,0);
  return;
}



===== lbfoFilterPreDetach @ 1c0003620 =====

void lbfoFilterPreDetach(longlong param_1,undefined8 param_2,undefined *param_3)

{
  undefined8 *puVar1;
  byte bVar2;
  longlong lVar3;
  ushort uVar4;
  undefined8 uVar5;
  undefined2 local_res8;
  undefined1 local_resa;
  undefined8 local_1a8 [50];
  
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_res8 = 0;
  local_resa = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_3 = &WPP_1f756999873135a83baf07d5dbd19e82_Traceguids;
    WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
              &WPP_1f756999873135a83baf07d5dbd19e82_Traceguids,param_1,
              (char)*(undefined4 *)(param_1 + 0x118));
  }
  bVar2 = *(byte *)(param_1 + 0xcc);
  *(byte *)(param_1 + 0xcc) = bVar2 | 4;
  if ((bVar2 & 2) != 0) {
    uVar5 = 400;
    memset(local_1a8,0,400);
    KeClearEvent(lVar3 + 0x588);
    vmqClearCapabilities((undefined4 *)local_1a8);
    vmqSetNewCapabilities((undefined8 *)(lVar3 + 0x240),local_1a8,uVar5,'\0');
    param_3 = (undefined *)0x0;
    KeWaitForSingleObject(lVar3 + 0x588,0,0,0,0);
  }
  ExAcquireFastMutex(lVar3 + 0x5b0);
  uVar4 = 1;
  do {
    bVar2 = *(byte *)((ulonglong)(uVar4 - 1) + 0x4a + param_1);
    if ((bVar2 != 0) &&
       (*(longlong *)(*(longlong *)(param_1 + 0x10) + 0x658 + (ulonglong)bVar2 * 8) != 0)) {
      lbfoRemoveNicFromFC(param_1,(uint)uVar4,param_3);
    }
    uVar4 = uVar4 + 1;
  } while (uVar4 < 0x41);
  NdisAcquireRWLockWrite(*(undefined8 *)(lVar3 + 0x5e8),&local_res8,0);
  if ((*(byte *)(param_1 + 0xcc) & 2) != 0) {
    puVar1 = (undefined8 *)(lVar3 + 0x240);
    vmqIndicateQueueAllocState(puVar1,'\0');
    vmqGenerateCapsChangeIndications(puVar1,lVar3 + 0xb0);
    vmqIndicateQueueAllocState(puVar1,'\x01');
    if (*(longlong *)(lVar3 + 0x578) != 0) {
      ExFreePoolWithTag(*(longlong *)(lVar3 + 0x578),0x5156544e);
      *(undefined8 *)(lVar3 + 0x578) = 0;
    }
    *(byte *)(param_1 + 0xcc) = *(byte *)(param_1 + 0xcc) & 0xfd;
    *(undefined8 *)(lVar3 + 0xa8) = 0;
  }
  if (*(char *)(lVar3 + 0x868) != '\0') {
    lbfoGenerateStatusIndication
              (*(undefined8 *)(param_1 + 0x18),0x40010017,(char *)(lVar3 + 0x868),0x28);
  }
  NdisReleaseRWLock(*(undefined8 *)(lVar3 + 0x5e8),&local_res8);
  ExReleaseFastMutex(lVar3 + 0x5b0);
  return;
}



===== McGenControlCallbackV2 @ 1c0003840 =====

void McGenControlCallbackV2
               (undefined8 param_1,int param_2,undefined1 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6,longlong param_7)

{
  uint *puVar1;
  ulonglong uVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  ulonglong uVar7;
  
  if (param_7 != 0) {
    if (param_2 == 0) {
      *(undefined4 *)(param_7 + 0x24) = 0;
      *(undefined1 *)(param_7 + 0x28) = 0;
      *(undefined8 *)(param_7 + 0x10) = 0;
      *(undefined8 *)(param_7 + 0x18) = 0;
      if (*(ushort *)(param_7 + 0x2a) != 0) {
        iVar4 = *(ushort *)(param_7 + 0x2a) - 1;
        memset(*(void **)(param_7 + 0x30),0,
               (longlong)(((int)(iVar4 + (iVar4 >> 0x1f & 0x1fU)) >> 5) + 1) << 2);
      }
    }
    else if (param_2 == 1) {
      *(undefined1 *)(param_7 + 0x28) = param_3;
      uVar7 = 0;
      *(undefined8 *)(param_7 + 0x18) = param_5;
      *(undefined8 *)(param_7 + 0x10) = param_4;
      *(undefined4 *)(param_7 + 0x24) = 1;
      if (*(short *)(param_7 + 0x2a) != 0) {
        do {
          uVar2 = *(ulonglong *)(*(longlong *)(param_7 + 0x38) + uVar7 * 8);
          if (((*(byte *)(param_7 + 0x28) < *(byte *)(uVar7 + *(longlong *)(param_7 + 0x40))) &&
              (*(byte *)(param_7 + 0x28) != 0)) ||
             ((uVar2 != 0 &&
              (((*(ulonglong *)(param_7 + 0x10) & uVar2) == 0 ||
               ((*(ulonglong *)(param_7 + 0x18) & uVar2) != *(ulonglong *)(param_7 + 0x18))))))) {
            bVar3 = false;
          }
          else {
            bVar3 = true;
          }
          uVar5 = 1 << ((byte)uVar7 & 0x1f);
          puVar1 = (uint *)(*(longlong *)(param_7 + 0x30) + (uVar7 >> 5) * 4);
          uVar6 = *puVar1;
          if (bVar3) {
            uVar5 = uVar5 | uVar6;
          }
          else {
            uVar5 = ~uVar5 & uVar6;
          }
          *puVar1 = uVar5;
          uVar6 = (int)uVar7 + 1;
          uVar7 = (ulonglong)uVar6;
        } while (uVar6 < *(ushort *)(param_7 + 0x2a));
      }
    }
  }
  return;
}



===== McGenEventRegister_EtwRegister @ 1c0003950 =====

void McGenEventRegister_EtwRegister
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong *param_4)

{
  if (*param_4 == 0) {
    EtwRegister(param_1,McGenControlCallbackV2);
  }
  return;
}



===== McGenEventUnregister_EtwUnregister @ 1c000397c =====

undefined8 McGenEventUnregister_EtwUnregister(longlong *param_1)

{
  undefined8 uVar1;
  
  if (*param_1 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = EtwUnregister();
    *param_1 = 0;
  }
  return uVar1;
}



===== McTemplateK0_EtwWriteTransfer @ 1c00039b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0_EtwWriteTransfer(undefined8 param_1)

{
  undefined1 auStackY_58 [32];
  undefined8 local_28 [2];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_58;
  McGenEventWrite_EtwWriteTransfer(param_1,&DriverUnloadingInfo,0,1,local_28);
  return;
}



===== McTemplateK0d_EtwWriteTransfer @ 1c00039fc =====

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
  McGenEventWrite_EtwWriteTransfer(param_1,&DriverEntryInfo,0,2,local_38);
  return;
}



===== McTemplateK0pqbr1_EtwWriteTransfer @ 1c0003a64 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0pqbr1_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6)

{
  undefined8 local_res20;
  undefined1 auStackY_98 [32];
  undefined4 local_68 [4];
  undefined8 local_58 [2];
  undefined8 *local_48;
  undefined8 local_40;
  undefined4 *local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  local_40 = 8;
  local_48 = &local_res20;
  local_68[0] = 0x28;
  local_38 = local_68;
  local_20 = 0x28;
  local_28 = param_6;
  local_30 = 4;
  local_res20 = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&TnicLinkStatusIndicationInfo,0,4,local_58);
  return;
}



===== MergeSortList @ 1c0003aec =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void MergeSortList(undefined8 *param_1,undefined *param_2,char param_3)

{
  longlong *plVar1;
  undefined8 *puVar2;
  int iVar3;
  undefined8 *puVar4;
  int iVar5;
  longlong *plVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  longlong *plVar9;
  undefined8 *puVar10;
  undefined8 *puVar11;
  
  plVar9 = (longlong *)*param_1;
  if ((plVar9 != param_1) && ((undefined8 *)*plVar9 != param_1)) {
    puVar7 = param_1 + 1;
    *puVar7 = plVar9;
    puVar4 = (undefined8 *)*plVar9;
    plVar6 = plVar9;
    while (puVar4 != param_1) {
      iVar3 = (*(code *)param_2)(plVar6,puVar4);
      plVar1 = (longlong *)*plVar6;
      iVar5 = -iVar3;
      if (param_3 == '\0') {
        iVar5 = iVar3;
      }
      if (0 < iVar5) {
        plVar9[1] = (longlong)plVar1;
        *plVar6 = 0;
        plVar9 = plVar1;
      }
      plVar6 = plVar1;
      puVar4 = (undefined8 *)*plVar1;
    }
    if ((longlong *)*puVar7 == plVar9) {
      *puVar7 = plVar6;
    }
    else {
      *plVar6 = 0;
      plVar9[1] = 0;
      while( true ) {
        plVar9 = param_1 + 1;
        puVar7 = (undefined8 *)*plVar9;
        if (puVar7[1] == 0) break;
        do {
          puVar4 = (undefined8 *)puVar7[1];
          puVar2 = (undefined8 *)puVar4[1];
          iVar3 = (*(code *)param_2)(puVar7,puVar4);
          iVar5 = -iVar3;
          if (param_3 == '\0') {
            iVar5 = iVar3;
          }
          if (iVar5 < 1) {
            puVar8 = puVar7;
            puVar10 = (undefined8 *)*puVar7;
            puVar11 = puVar4;
            puVar4 = puVar7;
          }
          else {
            puVar11 = (undefined8 *)*puVar4;
            puVar8 = puVar4;
            puVar10 = puVar7;
          }
          while ((puVar10 != (undefined8 *)0x0 && (puVar11 != (undefined8 *)0x0))) {
            iVar3 = (*(code *)param_2)(puVar10,puVar11);
            iVar5 = -iVar3;
            if (param_3 == '\0') {
              iVar5 = iVar3;
            }
            if (iVar5 < 1) {
              *puVar8 = puVar10;
              puVar8 = puVar10;
              puVar10 = (undefined8 *)*puVar10;
            }
            else {
              *puVar8 = puVar11;
              puVar8 = puVar11;
              puVar11 = (undefined8 *)*puVar11;
            }
          }
          if (puVar10 == (undefined8 *)0x0) {
            puVar10 = puVar11;
          }
          *puVar8 = puVar10;
          *plVar9 = (longlong)puVar4;
          plVar9 = puVar4 + 1;
          *plVar9 = (longlong)puVar2;
        } while ((puVar2 != (undefined8 *)0x0) && (puVar7 = puVar2, puVar2[1] != 0));
      }
      *param_1 = puVar7;
      puVar4 = param_1;
      for (; puVar7 != (undefined8 *)0x0; puVar7 = (undefined8 *)*puVar7) {
        puVar7[1] = puVar4;
        puVar4 = puVar7;
      }
      *puVar4 = param_1;
      *plVar9 = (longlong)puVar4;
    }
  }
  return;
}



===== WPP_SF_ @ 1c0003c8c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_(undefined8 param_1,undefined2 param_2,undefined8 param_3)

{
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,0);
  return;
}



===== WPP_SF_ddd @ 1c0003cb8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_ddd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_b7202525798e3186f26c2d40dc3ccbc1_Traceguids,0x10,local_res20,4,
             &param_5,4,&param_6,4,0);
  return;
}



===== WPP_SF_q @ 1c0003d1c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_q(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,0);
  return;
}



===== WppClassicProviderCallback @ 1c0003d60 =====

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



===== _tlgDefineProvider_annotation__Tlgg_hTraceLogMSLbfoProviderProv @ 1c0003d94 =====

void _tlgDefineProvider_annotation__Tlgg_hTraceLogMSLbfoProviderProv(void)

{
  return;
}



===== lbfoAllocateTimer @ 1c0003da0 =====

void lbfoAllocateTimer(undefined8 param_1,undefined8 param_2)

{
  undefined4 local_28;
  undefined4 local_24;
  undefined8 local_20;
  undefined8 local_18;
  
  local_18 = 0;
  local_28 = 0x180197;
  local_24 = 0x5463694e;
  local_20 = param_2;
  NdisAllocateTimerObject(param_1,&local_28);
  return;
}



===== lbfoCfgMacRebalanceTimer @ 1c0003de0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void lbfoCfgMacRebalanceTimer(undefined8 param_1,longlong param_2)

{
  short *psVar1;
  undefined2 local_res10;
  undefined1 local_res12;
  
  local_res10 = 0;
  local_res12 = 0;
  NdisAcquireRWLockWrite(*(undefined8 *)(param_2 + 0x5e8),&local_res10,1);
  if ((*(byte *)(param_2 + 0x922) & 4) != 0) {
    (**(code **)(&DAT_1c0018148 + (longlong)*(int *)(param_2 + 0x5a4) * 0x78))(param_2);
  }
  if ((*(byte *)(param_2 + 0x922) & 0x10) != 0) {
    lbfoCalculateVmqCaps(param_2);
  }
  psVar1 = (short *)(param_2 + 0x920);
  *psVar1 = *psVar1 + -1;
  if (*psVar1 == 0) {
    KeSetEvent(param_2 + 0x908,0,0);
  }
  NdisReleaseRWLock(*(undefined8 *)(param_2 + 0x5e8),&local_res10);
  return;
}



===== lbfoDecrementTeamRefCount @ 1c0003e94 =====

bool lbfoDecrementTeamRefCount(longlong param_1)

{
  short *psVar1;
  short sVar2;
  undefined2 local_res8;
  undefined1 local_resa;
  
  local_res8 = 0;
  local_resa = 0;
  NdisAcquireRWLockWrite(*(undefined8 *)(param_1 + 0x5e8),&local_res8,0);
  psVar1 = (short *)(param_1 + 0x920);
  *psVar1 = *psVar1 + -1;
  sVar2 = *psVar1;
  if (sVar2 == 0) {
    KeSetEvent(param_1 + 0x908,0,0);
  }
  NdisReleaseRWLock(*(undefined8 *)(param_1 + 0x5e8),&local_res8);
  return sVar2 == 0;
}



===== lbfoFindOrCreateTeam @ 1c0003f24 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong lbfoFindOrCreateTeam(undefined8 *param_1,longlong param_2)

{
  char *pcVar1;
  code *pcVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  wchar_t *pwVar10;
  undefined4 uVar11;
  uint uVar12;
  int iVar13;
  longlong lVar14;
  char *pcVar15;
  char *pcVar16;
  undefined8 *puVar17;
  undefined2 uVar18;
  wchar_t *pwVar19;
  short sVar20;
  ulonglong uVar21;
  undefined8 *puVar22;
  undefined8 uVar23;
  undefined1 auStackY_338 [32];
  undefined2 local_308;
  undefined1 local_306;
  int local_304;
  longlong local_300;
  longlong local_2f8;
  undefined8 local_2f0;
  undefined8 *puStack_2e8;
  undefined8 local_2e0;
  undefined8 uStack_2d8;
  undefined8 *local_2d0;
  undefined8 uStack_2c8;
  undefined8 local_2c0;
  ulonglong uStack_2b8;
  undefined8 local_2b0;
  undefined8 uStack_2a8;
  undefined8 local_2a0;
  undefined8 local_298;
  undefined8 uStack_290;
  char local_288 [16];
  longlong local_278;
  longlong lStack_270;
  undefined1 local_268 [12];
  uint local_25c;
  undefined8 local_258;
  undefined8 uStack_250;
  undefined8 local_248;
  undefined8 uStack_240;
  undefined8 local_238;
  undefined8 uStack_230;
  undefined4 local_228;
  undefined4 uStack_224;
  undefined4 uStack_220;
  undefined4 uStack_21c;
  undefined8 local_218;
  undefined4 local_210;
  undefined2 local_20c;
  undefined8 local_1a8 [21];
  undefined8 uStack_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined8 local_c0;
  undefined4 local_b8;
  undefined1 local_90 [88];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_338;
  local_304 = 0;
  sVar20 = 0;
  local_278 = 0;
  lStack_270 = 0;
  local_2f0 = 0;
  puStack_2e8 = (undefined8 *)0x0;
  memset(local_268,0,0xc0);
  lVar14 = 2;
  puVar22 = local_1a8;
  pwVar10 = 
  L"\\Registry\\Machine\\System\\CurrentControlSet\\Services\\NdisImPlatform\\Parameters\\Teams\\{00000000-0000-0000-0000-000000000000}\\VirtualMiniports\\{00000000-0000-0000-0000-000000000000}"
  ;
  do {
    pwVar19 = pwVar10;
    puVar17 = puVar22;
    uVar23 = *(undefined8 *)(pwVar19 + 4);
    uVar7 = *(undefined8 *)(pwVar19 + 8);
    uVar8 = *(undefined8 *)(pwVar19 + 0xc);
    *puVar17 = *(undefined8 *)pwVar19;
    puVar17[1] = uVar23;
    uVar23 = *(undefined8 *)(pwVar19 + 0x10);
    uVar9 = *(undefined8 *)(pwVar19 + 0x14);
    puVar17[2] = uVar7;
    puVar17[3] = uVar8;
    uVar7 = *(undefined8 *)(pwVar19 + 0x18);
    uVar8 = *(undefined8 *)(pwVar19 + 0x1c);
    puVar17[4] = uVar23;
    puVar17[5] = uVar9;
    uVar23 = *(undefined8 *)(pwVar19 + 0x20);
    uVar9 = *(undefined8 *)(pwVar19 + 0x24);
    puVar17[6] = uVar7;
    puVar17[7] = uVar8;
    uVar7 = *(undefined8 *)(pwVar19 + 0x28);
    uVar8 = *(undefined8 *)(pwVar19 + 0x2c);
    puVar17[8] = uVar23;
    puVar17[9] = uVar9;
    uVar23 = *(undefined8 *)(pwVar19 + 0x30);
    uVar9 = *(undefined8 *)(pwVar19 + 0x34);
    puVar17[10] = uVar7;
    puVar17[0xb] = uVar8;
    uVar7 = *(undefined8 *)(pwVar19 + 0x38);
    uVar8 = *(undefined8 *)(pwVar19 + 0x3c);
    puVar17[0xc] = uVar23;
    puVar17[0xd] = uVar9;
    puVar17[0xe] = uVar7;
    puVar17[0xf] = uVar8;
    lVar14 = lVar14 + -1;
    puVar22 = puVar17 + 0x10;
    pwVar10 = pwVar19 + 0x40;
  } while (lVar14 != 0);
  uVar11 = *(undefined4 *)(pwVar19 + 0x70);
  uVar23 = *(undefined8 *)(pwVar19 + 0x44);
  local_300 = 0;
  uVar7 = *(undefined8 *)(pwVar19 + 0x48);
  uVar8 = *(undefined8 *)(pwVar19 + 0x4c);
  local_2f8 = 0;
  puVar17[0x10] = *(undefined8 *)(pwVar19 + 0x40);
  puVar17[0x11] = uVar23;
  uVar23 = *(undefined8 *)(pwVar19 + 0x50);
  uVar9 = *(undefined8 *)(pwVar19 + 0x54);
  puVar17[0x12] = uVar7;
  puVar17[0x13] = uVar8;
  uVar7 = *(undefined8 *)(pwVar19 + 0x58);
  uVar8 = *(undefined8 *)(pwVar19 + 0x5c);
  puVar17[0x14] = uVar23;
  puVar17[0x15] = uVar9;
  uVar23 = *(undefined8 *)(pwVar19 + 0x60);
  uVar9 = *(undefined8 *)(pwVar19 + 100);
  puVar17[0x16] = uVar7;
  puVar17[0x17] = uVar8;
  uVar3 = *(undefined4 *)(pwVar19 + 0x68);
  uVar4 = *(undefined4 *)(pwVar19 + 0x6a);
  uVar5 = *(undefined4 *)(pwVar19 + 0x6c);
  uVar6 = *(undefined4 *)(pwVar19 + 0x6e);
  puVar17[0x18] = uVar23;
  puVar17[0x19] = uVar9;
  *(undefined4 *)(puVar17 + 0x1a) = uVar3;
  *(undefined4 *)((longlong)puVar17 + 0xd4) = uVar4;
  *(undefined4 *)(puVar17 + 0x1b) = uVar5;
  *(undefined4 *)((longlong)puVar17 + 0xdc) = uVar6;
  *(undefined4 *)(puVar17 + 0x1c) = uVar11;
  *(wchar_t *)((longlong)puVar17 + 0xe4) = pwVar19[0x72];
  local_2c0 = 0;
  uStack_2b8 = uStack_2b8 & 0xffffffff00000000;
  local_308 = 0;
  local_306 = 0;
  local_2a0 = 0;
  local_2e0 = 0;
  uStack_2d8 = 0;
  local_2d0 = (undefined8 *)0x0;
  uStack_2c8 = 0;
  local_298 = 0;
  uStack_290 = 0;
  local_2b0 = 0;
  uStack_2a8 = 0;
  uVar11 = IoGetDeviceProperty(*(undefined8 *)(param_2 + 0xb8),10,0x4e,local_90);
  uVar12 = NdisConvertNtStatusToNdisStatus(uVar11);
  uVar21 = (ulonglong)uVar12;
  if (uVar12 == 0) {
    if (local_304 != 0x4e) {
      return 0xc0000001;
    }
    RtlInitUnicodeString
              (&local_298,
               L"\\Registry\\Machine\\System\\CurrentControlSet\\Services\\NdisImPlatform\\Parameters\\Teams"
              );
    local_2d0 = &local_298;
    local_2e0 = CONCAT44(local_2e0._4_4_,0x30);
    uStack_2d8 = 0;
    uStack_2c8 = CONCAT44(uStack_2c8._4_4_,0x240);
    local_2c0 = 0;
    uStack_2b8 = 0;
    uVar11 = ZwOpenKey(&local_300,8);
    uVar12 = NdisConvertNtStatusToNdisStatus(uVar11);
    uVar21 = (ulonglong)uVar12;
    if (uVar12 == 0) {
      while( true ) {
        uVar11 = ZwEnumerateKey(local_300,sVar20,0,local_268);
        uVar12 = NdisConvertNtStatusToNdisStatus(uVar11);
        uVar21 = (ulonglong)uVar12;
        if (uVar12 != 0) break;
        if (local_25c == 0x4c) {
          uStack_100 = local_258;
          local_f8 = uStack_250;
          local_b8 = local_210;
          uStack_e0 = local_238;
          local_d8 = uStack_230;
          uStack_f0 = local_248;
          local_e8 = uStack_240;
          local_c0 = local_218;
          uStack_d0 = local_228;
          uStack_cc = uStack_224;
          local_c8 = uStack_220;
          local_c4 = uStack_21c;
          RtlInitUnicodeString(&local_298,local_1a8);
          local_2d0 = &local_298;
          local_2e0 = CONCAT44(local_2e0._4_4_,0x30);
          uStack_2d8 = 0;
          uStack_2c8 = CONCAT44(uStack_2c8._4_4_,0x240);
          local_2c0 = 0;
          uStack_2b8 = 0;
          iVar13 = ZwOpenKey(&local_2f8,1);
          if (-1 < iVar13) {
            *(undefined2 *)(local_268 + (ulonglong)(local_25c >> 1) * 2 + 0x12) = 0;
            puStack_2e8 = &local_258;
            local_2f0 = CONCAT44(local_2f0._4_4_,0xb00000);
            local_2f0 = CONCAT62(local_2f0._2_6_,(undefined2)local_25c);
            uVar11 = RtlGUIDFromString(&local_2f0,&local_278);
            uVar12 = NdisConvertNtStatusToNdisStatus(uVar11);
            uVar21 = (ulonglong)uVar12;
            if (uVar12 == 0) {
              ZwClose(local_300);
              local_300 = 0;
              ZwClose(local_2f8);
              local_2f8 = 0;
              KeAcquireInStackQueuedSpinLock(&DAT_1c0018478,&local_2b0);
              puVar22 = DAT_1c0018480;
              goto LAB_1c00043b9;
            }
            if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
               ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1c000460f;
            uVar18 = 0x15;
            pcVar15 = "RtlGUIDFromString(&GuidStr, &Guid)";
            goto LAB_1c00040cd;
          }
          local_2f8 = 0;
        }
        sVar20 = sVar20 + 1;
      }
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1c000460f;
      uVar18 = 0x14;
      pcVar15 = 
      "ZwEnumerateKey(regTeamKey, Index, KeyBasicInformation, KeyInfoBuffer, sizeof(KeyInfoBuffer), &ResultLength)"
      ;
    }
    else {
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1c000460f;
      uVar18 = 0x13;
      pcVar15 = "ZwOpenKey(&regTeamKey, KEY_ENUMERATE_SUB_KEYS, &ObjectAttributes)";
    }
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1c000460f;
    uVar18 = 0x12;
    pcVar15 = 
    "IoGetDeviceProperty(Parms->MiniportPhysicalDeviceObject, DevicePropertyLocationInformation, LBFO_GUID_STR_LENGTH * sizeof(WCHAR), VirtMiniKey + RTL_NUMBER_OF(LBFO_REG_TEAM_VIRTMINI), &ResultLength)"
    ;
  }
LAB_1c00040cd:
  WPP_SF_ds(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar18,
            &WPP_b7202525798e3186f26c2d40dc3ccbc1_Traceguids,(int)uVar21,pcVar15);
LAB_1c000460f:
  if (local_300 != 0) {
    ZwClose();
  }
  lVar14 = local_2f8;
  if (local_2f8 != 0) {
    ZwClose();
  }
  if ((Microsoft_Windows_MsLbfoEventProviderEnableBits & 1) != 0) {
    McTemplateK0pd_EtwWriteTransfer(lVar14,&InitializingTNicInfo,0,param_1,(char)uVar21);
  }
  return uVar21;
LAB_1c00043b9:
  if ((undefined8 **)puVar22 == &DAT_1c0018480) goto LAB_1c00043be;
  if ((*(longlong *)((longlong)puVar22 + 0x24) == local_278) &&
     (*(longlong *)((longlong)puVar22 + 0x2c) == lStack_270)) {
    if (puVar22 != (undefined8 *)0x0) goto LAB_1c000448c;
    goto LAB_1c00043be;
  }
  puVar22 = (undefined8 *)*puVar22;
  goto LAB_1c00043b9;
LAB_1c00043be:
  local_288[8] = '\x10';
  local_288[9] = '\0';
  local_288[10] = '\0';
  local_288[0xb] = '\0';
  local_288[0xc] = '\0';
  local_288[0xd] = '\0';
  local_288[0xe] = '\0';
  local_288[0xf] = '\0';
  pcVar15 = local_288;
  local_288[0] = '\x01';
  local_288[1] = '\0';
  local_288[2] = '\0';
  local_288[3] = '\0';
  local_288[4] = '\0';
  local_288[5] = '\0';
  local_288[6] = '\0';
  local_288[7] = '\0';
  uVar23 = 0x5463694e;
  pcVar16 = (char *)ExAllocatePool3(0x40,0xee8);
  if (pcVar16 != (char *)0x0) {
    pcVar16[0x20] = '\0';
    pcVar16[0x21] = '\0';
    pcVar16[0x22] = '\0';
    pcVar16[0x23] = '\0';
    *(longlong *)(pcVar16 + 0x24) = local_278;
    *(longlong *)(pcVar16 + 0x2c) = lStack_270;
    *(undefined8 *)(pcVar16 + 0x48) = local_258;
    *(undefined8 *)(pcVar16 + 0x50) = uStack_250;
    *(undefined8 *)(pcVar16 + 0x58) = local_248;
    *(undefined8 *)(pcVar16 + 0x60) = uStack_240;
    *(undefined8 *)(pcVar16 + 0x68) = local_238;
    *(undefined8 *)(pcVar16 + 0x70) = uStack_230;
    *(undefined4 *)(pcVar16 + 0x78) = local_228;
    *(undefined4 *)(pcVar16 + 0x7c) = uStack_224;
    *(undefined4 *)(pcVar16 + 0x80) = uStack_220;
    *(undefined4 *)(pcVar16 + 0x84) = uStack_21c;
    *(undefined8 *)(pcVar16 + 0x88) = local_218;
    *(undefined4 *)(pcVar16 + 0x90) = local_210;
    *(undefined2 *)(pcVar16 + 0x94) = local_20c;
    *(char **)(pcVar16 + 0x40) = pcVar16 + 0x48;
    pcVar16[0x3a] = 'N';
    pcVar16[0x3b] = '\0';
    *(undefined2 *)(pcVar16 + 0x38) = (undefined2)local_2f0;
    if ((undefined8 **)*(undefined8 **)DAT_1c0018488 != &DAT_1c0018480) {
LAB_1c0004688:
      pcVar2 = (code *)swi(0x29);
      (*pcVar2)(3);
      pcVar2 = (code *)swi(3);
      uVar21 = (*pcVar2)();
      return uVar21;
    }
    *(char **)(pcVar16 + 8) = DAT_1c0018488;
    *(undefined8 ***)pcVar16 = &DAT_1c0018480;
    *(char **)DAT_1c0018488 = pcVar16;
    pcVar1 = pcVar16 + 0x10;
    DAT_1c0018488 = pcVar16;
    *param_1 = pcVar1;
    param_1[1] = pcVar1;
    *(undefined8 **)pcVar1 = param_1;
    *(undefined8 **)(pcVar16 + 0x18) = param_1;
    KeReleaseInStackQueuedSpinLock(&local_2b0);
    *(undefined4 *)(pcVar16 + 0x96) = *(undefined4 *)(param_2 + 0x62);
    *(undefined2 *)(pcVar16 + 0x9a) = *(undefined2 *)(param_2 + 0x66);
    param_1[2] = pcVar16;
    pcVar15 = lbfoInitTeam((longlong)param_1,pcVar16,uVar23,pcVar15);
    uVar21 = (ulonglong)pcVar15 & 0xffffffff;
    if ((((int)pcVar15 != 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_ds(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
                &WPP_b7202525798e3186f26c2d40dc3ccbc1_Traceguids,(int)pcVar15,
                "lbfoInitTeam(FilterContext, Team)");
    }
    goto LAB_1c000460f;
  }
  uVar21 = 0xc000009a;
  goto LAB_1c0004402;
  while( true ) {
    KeReleaseInStackQueuedSpinLock(&local_2b0);
    NdisMSleep(1000);
    KeAcquireInStackQueuedSpinLock(&DAT_1c0018478,&local_2b0);
    puVar22 = DAT_1c0018480;
    while( true ) {
      if ((undefined8 **)puVar22 == &DAT_1c0018480) goto LAB_1c000447d;
      if ((*(longlong *)((longlong)puVar22 + 0x24) == local_278) &&
         (*(longlong *)((longlong)puVar22 + 0x2c) == lStack_270)) break;
      puVar22 = (undefined8 *)*puVar22;
    }
    if (puVar22 == (undefined8 *)0x0) break;
LAB_1c000448c:
    if (*(int *)(puVar22 + 4) == 2) {
      NdisAcquireRWLockWrite(puVar22[0xbd],&local_308);
      puVar17 = (undefined8 *)puVar22[3];
      if ((undefined8 *)*puVar17 != puVar22 + 2) goto LAB_1c0004688;
      *param_1 = puVar22 + 2;
      param_1[1] = puVar17;
      *puVar17 = param_1;
      puVar22[3] = param_1;
      NdisReleaseRWLock(puVar22[0xbd],&local_308);
      KeReleaseInStackQueuedSpinLock(&local_2b0);
      param_1[2] = puVar22;
      goto LAB_1c000460f;
    }
  }
LAB_1c000447d:
  uVar21 = 0xc0000001;
LAB_1c0004402:
  KeReleaseInStackQueuedSpinLock(&local_2b0);
  return uVar21;
}



===== lbfoGenerateStatusIndication @ 1c0004698 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void lbfoGenerateStatusIndication
               (undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined1 auStack_c8 [32];
  undefined8 local_98;
  undefined8 local_90;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined4 local_60;
  undefined8 local_5c;
  undefined8 uStack_54;
  undefined8 local_4c;
  undefined8 uStack_44;
  undefined8 local_3c;
  undefined8 uStack_34;
  undefined4 local_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_c8;
  local_88 = 0;
  local_80 = 0;
  local_98 = 0x700198;
  local_7c = 0;
  local_2c = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_5c = 0;
  uStack_54 = 0;
  local_4c = 0;
  uStack_44 = 0;
  local_3c = 0;
  uStack_34 = 0;
  local_90 = param_1;
  local_84 = param_2;
  local_68 = param_3;
  local_60 = param_4;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_dq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
              &WPP_b7202525798e3186f26c2d40dc3ccbc1_Traceguids,param_2,(char)param_1);
  }
  NdisFIndicateStatus(param_1,&local_98);
  return;
}



===== lbfoIndicateTeamLinkState @ 1c000475c =====

void lbfoIndicateTeamLinkState(longlong param_1,undefined8 param_2,longlong param_3)

{
  longlong lVar1;
  undefined8 *puVar2;
  undefined8 in_stack_ffffffffffffffe8;
  
  lVar1 = param_1;
  for (puVar2 = *(undefined8 **)(param_1 + 0x10); puVar2 != (undefined8 *)(param_1 + 0x10);
      puVar2 = (undefined8 *)*puVar2) {
    if (((*(int *)(puVar2 + 0x1d) != 0) && (*(int *)(puVar2 + 0x1d) != 5)) &&
       ((*(byte *)((longlong)puVar2 + 0xcc) & 4) == 0)) {
      lVar1 = puVar2[3];
      param_3 = param_1 + 0x890;
      param_2 = 0x40010017;
      lbfoGenerateStatusIndication(lVar1,0x40010017,param_3,0x28);
    }
  }
  if ((Microsoft_Windows_MsLbfoEventProviderEnableBits & 1) != 0) {
    McTemplateK0pqbr1_EtwWriteTransfer
              (lVar1,param_2,param_3,param_1,in_stack_ffffffffffffffe8,param_1 + 0x890);
  }
  return;
}



===== lbfoIndicateTeamLinkStateTimer @ 1c00047f0 =====

void lbfoIndicateTeamLinkStateTimer(undefined8 param_1,longlong param_2,undefined8 param_3)

{
  short *psVar1;
  undefined2 *puVar2;
  longlong lVar3;
  undefined2 local_res10;
  undefined1 local_res12;
  
  lVar3 = CONCAT71((int7)((ulonglong)param_3 >> 8),1);
  local_res10 = 0;
  puVar2 = &local_res10;
  local_res12 = 0;
  NdisAcquireRWLockWrite(*(undefined8 *)(param_2 + 0x5e8));
  lbfoIndicateTeamLinkState(param_2,puVar2,lVar3);
  psVar1 = (short *)(param_2 + 0x920);
  *psVar1 = *psVar1 + -1;
  if (*psVar1 == 0) {
    KeSetEvent(param_2 + 0x908,0,0);
  }
  NdisReleaseRWLock(*(undefined8 *)(param_2 + 0x5e8),&local_res10);
  return;
}



===== lbfoInitTeamWithPnP @ 1c0004874 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int lbfoInitTeamWithPnP(longlong param_1)

{
  int iVar1;
  char *pcVar2;
  undefined2 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_98 [32];
  undefined2 local_68;
  undefined1 local_66;
  undefined4 local_58;
  undefined2 local_54;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStackY_98;
  local_48 = 0;
  uStack_40 = 0;
  local_28 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_68 = 0;
  local_66 = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,
             &WPP_b7202525798e3186f26c2d40dc3ccbc1_Traceguids,param_1);
  }
  local_58 = *(undefined4 *)(param_1 + 0x9c);
  local_54 = *(undefined2 *)(param_1 + 0xa0);
  uVar5 = 0xfff;
  uVar4 = 0;
  *(undefined4 *)(param_1 + 0x20) = 1;
  iVar1 = lbfoAddVmsPortInner(param_1,0,0xfff,&local_58,0);
  if (iVar1 == 0) {
    iVar1 = lbfoIssueOidRequestAnyFilter(param_1,uVar4,uVar5,&local_48);
    if (iVar1 == 0) {
      NdisAcquireRWLockWrite(*(undefined8 *)(param_1 + 0x5e8),&local_68,0);
      if (*(char *)(param_1 + 0x868) == '\0') {
        *(undefined8 *)(param_1 + 0x868) = local_48;
        *(undefined8 *)(param_1 + 0x870) = uStack_40;
        *(undefined8 *)(param_1 + 0x878) = local_38;
        *(undefined8 *)(param_1 + 0x880) = uStack_30;
        *(undefined8 *)(param_1 + 0x888) = local_28;
      }
      NdisReleaseRWLock(*(undefined8 *)(param_1 + 0x5e8),&local_68);
      *(undefined4 *)(param_1 + 0x20) = 2;
      return 0;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar1;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return iVar1;
    }
    uVar3 = 0x23;
    pcVar2 = 
    "lbfoIssueOidRequestAnyFilter(Team, OID_GEN_LINK_STATE, NdisRequestQueryInformation, &tmpMuxLinkState, sizeof(NDIS_LINK_STATE), NULL)"
    ;
  }
  else {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar1;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return iVar1;
    }
    uVar3 = 0x22;
    pcVar2 = 
    "lbfoAddVmsPortInner(Team, NDIS_SWITCH_DEFAULT_PORT_ID, 0xfff, Team->OutgoingMacAddr, 0)";
  }
  WPP_SF_ds(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar3,
            &WPP_b7202525798e3186f26c2d40dc3ccbc1_Traceguids,iVar1,pcVar2);
  return iVar1;
}



===== lbfoRemoveTeam @ 1c0004a28 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void lbfoRemoveTeam(longlong param_1)

{
  longlong lVar1;
  short *psVar2;
  longlong *plVar3;
  char cVar4;
  longlong lVar5;
  longlong lVar6;
  undefined8 uVar7;
  undefined2 local_res8;
  undefined1 local_resa;
  undefined2 local_res10;
  undefined1 local_res12;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  
  local_res8 = 0;
  local_resa = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x24,
             &WPP_b7202525798e3186f26c2d40dc3ccbc1_Traceguids,param_1);
  }
  *(undefined4 *)(param_1 + 0x20) = 3;
  uVar7 = 0;
  local_res10 = 0;
  local_res12 = 0;
  NdisAcquireRWLockWrite(*(undefined8 *)(param_1 + 0x5e8),&local_res10);
  while (plVar3 = *(longlong **)(param_1 + 0x8c8), plVar3 != (longlong *)(param_1 + 0x8c8)) {
    lbfoTMRemoveAggregator(param_1,plVar3,uVar7);
  }
  NdisReleaseRWLock(*(undefined8 *)(param_1 + 0x5e8),&local_res10);
  if (*(code **)(&DAT_1c0018008 + (longlong)*(int *)(param_1 + 0x5a8) * 0x48) != (code *)0x0) {
    (**(code **)(&DAT_1c0018008 + (longlong)*(int *)(param_1 + 0x5a8) * 0x48))(param_1);
  }
  if (*(code **)(&DAT_1c00180e8 + (longlong)*(int *)(param_1 + 0x5a4) * 0x78) != (code *)0x0) {
    (**(code **)(&DAT_1c00180e8 + (longlong)*(int *)(param_1 + 0x5a4) * 0x78))(param_1);
  }
  NdisAcquireRWLockWrite(*(undefined8 *)(param_1 + 0x5e8),&local_res8,0);
  if ((*(longlong *)(param_1 + 0x8b8) != 0) && (cVar4 = NdisCancelTimerObject(), cVar4 != '\0')) {
    *(short *)(param_1 + 0x920) = *(short *)(param_1 + 0x920) + -1;
  }
  if ((*(longlong *)(param_1 + 0x900) != 0) && (cVar4 = NdisCancelTimerObject(), cVar4 != '\0')) {
    *(short *)(param_1 + 0x920) = *(short *)(param_1 + 0x920) + -1;
  }
  lVar1 = param_1 + 0x600;
  local_38 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  cVar4 = RtlInitEnumerationHashTable(lVar1,&local_58);
  if (cVar4 != '\0') {
    while (lVar5 = RtlEnumerateEntryHashTable(lVar1,&local_58), lVar5 != 0) {
      RtlRemoveEntryHashTable(lVar1,lVar5,0);
      ExFreePoolWithTag(lVar5,0x5463694e);
    }
    RtlEndEnumerationHashTable(lVar1,&local_58);
  }
  lVar5 = param_1 + 0x628;
  cVar4 = RtlInitEnumerationHashTable(lVar5,&local_58);
  if (cVar4 != '\0') {
    while (lVar6 = RtlEnumerateEntryHashTable(lVar5,&local_58), lVar6 != 0) {
      RtlRemoveEntryHashTable(lVar5,lVar6,0);
      ExFreePoolWithTag(lVar6,0x5463694e);
    }
    RtlEndEnumerationHashTable(lVar5,&local_58);
  }
  if (*(longlong *)(param_1 + 0x650) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x650),0x5463694e);
    *(undefined8 *)(param_1 + 0x650) = 0;
  }
  psVar2 = (short *)(param_1 + 0x920);
  *psVar2 = *psVar2 + -1;
  lVar6 = param_1 + 0x8f0;
  *(longlong *)(param_1 + 0x8f8) = lVar6;
  *(longlong *)lVar6 = lVar6;
  *(undefined2 *)(param_1 + 0x8ee) = 0;
  *(undefined2 *)(param_1 + 0x5f8) = 0;
  if (*psVar2 == 0) {
    NdisReleaseRWLock(*(undefined8 *)(param_1 + 0x5e8),&local_res8);
  }
  else {
    NdisReleaseRWLock();
    KeWaitForSingleObject(param_1 + 0x908,0,0,0,0);
  }
  RtlDeleteHashTable(lVar1);
  RtlDeleteHashTable(lVar5);
  if (*(longlong *)(param_1 + 0x5f0) != 0) {
    NdisFreeRWLock();
  }
  if (*(longlong *)(param_1 + 0x8b8) != 0) {
    NdisFreeTimerObject();
  }
  if (*(longlong *)(param_1 + 0x900) != 0) {
    NdisFreeTimerObject();
  }
  if (*(longlong *)(param_1 + 0x5e8) != 0) {
    NdisFreeRWLock();
  }
  ExFreePoolWithTag(param_1,0x5463694e);
  return;
}



===== lbfoSetCfgMacRebalanceTimer @ 1c0004dc8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void lbfoSetCfgMacRebalanceTimer(longlong param_1)

{
  char cVar1;
  
  if (*(code **)(&DAT_1c0018148 + (longlong)*(int *)(param_1 + 0x5a4) * 0x78) != (code *)0x0) {
    if (DAT_1c0018476 == 0) {
      (**(code **)(&DAT_1c0018148 + (longlong)*(int *)(param_1 + 0x5a4) * 0x78))();
      if ((*(byte *)(param_1 + 0x922) & 0x10) != 0) {
        lbfoCalculateVmqCaps(param_1);
      }
    }
    else {
      *(byte *)(param_1 + 0x922) = *(byte *)(param_1 + 0x922) | 4;
      cVar1 = NdisSetCoalescableTimerObject
                        (*(undefined8 *)(param_1 + 0x900),(ulonglong)(uint)DAT_1c0018476 * -10000000
                         ,0,param_1,DAT_1c0018476 / 10);
      if (cVar1 == '\0') {
        *(short *)(param_1 + 0x920) = *(short *)(param_1 + 0x920) + 1;
      }
    }
  }
  return;
}



===== lbfoUpdateLinkState @ 1c0004e70 =====

void lbfoUpdateLinkState(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  bool bVar4;
  bool bVar5;
  char cVar6;
  int iVar7;
  longlong *plVar8;
  longlong lVar9;
  longlong lVar10;
  longlong lVar11;
  longlong *plVar12;
  undefined8 local_48;
  int iStack_40;
  undefined4 uStack_3c;
  undefined8 local_38;
  undefined8 uStack_30;
  int iStack_24;
  
  bVar4 = false;
  bVar5 = false;
  if (*(int *)(param_1 + 0x20) != 2) {
    return;
  }
  lVar10 = 0;
  plVar1 = (longlong *)(param_1 + 0x8c8);
  plVar12 = (longlong *)*plVar1;
  lVar9 = 0;
  local_38 = 0;
  lVar11 = 2;
  local_48._0_4_ = (undefined4)*(undefined8 *)(param_1 + 0x868);
  local_48 = CONCAT44(2,(undefined4)local_48);
  uStack_30 = 0;
  if (plVar12 == plVar1) {
LAB_1c0004fbc:
    iVar7 = *(int *)(param_1 + 0x894);
    if (iVar7 != 1) goto LAB_1c0004fc9;
  }
  else {
    do {
      for (plVar8 = (longlong *)plVar12[3]; plVar8 != plVar12 + 3; plVar8 = (longlong *)*plVar8) {
        if ((int)plVar8[0x54] == 0) {
          lVar2 = plVar8[0x59];
          lVar11 = 1;
          local_48 = CONCAT44(1,(undefined4)local_48);
          if (lVar2 == -1) {
            bVar4 = true;
          }
          lVar3 = plVar8[0x5a];
          local_38 = lVar10 + lVar2;
          if (lVar2 == -1) {
            local_38 = lVar10;
          }
          if (lVar3 == -1) {
            bVar5 = true;
          }
          uStack_30 = lVar9 + lVar3;
          if (lVar3 == -1) {
            uStack_30 = lVar9;
          }
          lVar9 = uStack_30;
          lVar10 = local_38;
        }
        else if (((int)lVar11 == 2) &&
                (((int)plVar8[0x5b] == 0 || (*(int *)((longlong)plVar8 + 0x2dc) == 0)))) {
          lVar11 = 0;
          local_48 = local_48 & 0xffffffff;
        }
      }
      plVar12 = (longlong *)*plVar12;
    } while (plVar12 != plVar1);
    if ((int)lVar11 != 1) goto LAB_1c0004fbc;
    if (lVar10 == 0) {
      if (bVar4) {
        lVar10 = -1;
      }
      local_38 = lVar10;
    }
    if (lVar9 == 0) {
      if (bVar5) {
        lVar9 = -1;
      }
      uStack_30 = lVar9;
    }
    iVar7 = *(int *)(param_1 + 0x894);
LAB_1c0004fc9:
    if (((int)lVar11 != 2) || (iVar7 != 0)) goto LAB_1c0004fe2;
  }
  *(int *)(param_1 + 0x8c0) = *(int *)(param_1 + 0x8c0) + 1;
LAB_1c0004fe2:
  iStack_40 = (int)*(undefined8 *)(param_1 + 0x870);
  if (((((int)lVar11 != iVar7) || (iStack_40 != *(int *)(param_1 + 0x898))) ||
      (lVar9 != *(longlong *)(param_1 + 0x8a8))) ||
     ((lVar10 != *(longlong *)(param_1 + 0x8a0) ||
      (iStack_24 = (int)((ulonglong)*(undefined8 *)(param_1 + 0x888) >> 0x20),
      iStack_24 != *(int *)(param_1 + 0x8b4))))) {
    uStack_3c = (undefined4)((ulonglong)*(undefined8 *)(param_1 + 0x870) >> 0x20);
    *(undefined4 *)(param_1 + 0x890) = (undefined4)local_48;
    *(undefined4 *)(param_1 + 0x894) = local_48._4_4_;
    *(int *)(param_1 + 0x898) = iStack_40;
    *(undefined4 *)(param_1 + 0x89c) = uStack_3c;
    *(undefined4 *)(param_1 + 0x8a0) = (undefined4)local_38;
    *(undefined4 *)(param_1 + 0x8a4) = local_38._4_4_;
    *(undefined4 *)(param_1 + 0x8a8) = (undefined4)uStack_30;
    *(undefined4 *)(param_1 + 0x8ac) = uStack_30._4_4_;
    *(undefined8 *)(param_1 + 0x8b0) = *(undefined8 *)(param_1 + 0x888);
    if (((DAT_1c001849c & 8) == 0) || ((int)lVar11 == 1)) {
      lbfoIndicateTeamLinkState(param_1,lVar10,lVar11);
    }
    else {
      cVar6 = NdisSetCoalescableTimerObject
                        (*(undefined8 *)(param_1 + 0x8b8),0xfffffffffd050f80,0,param_1,500);
      if (cVar6 == '\0') {
        *(short *)(param_1 + 0x920) = *(short *)(param_1 + 0x920) + 1;
      }
    }
  }
  return;
}



===== McTemplateK0jpp_EtwWriteTransfer @ 1c00050a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0jpp_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined1 auStackY_88 [32];
  undefined8 local_58 [2];
  undefined8 local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  local_38 = &param_5;
  local_28 = &param_6;
  local_40 = 0x10;
  local_30 = 8;
  local_20 = 8;
  local_48 = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&MemberAggrChangeInfo,0,4,local_58);
  return;
}



===== McTemplateK0p_EtwWriteTransfer @ 1c0005120 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0p_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res20;
  undefined1 auStackY_68 [32];
  undefined8 local_38 [2];
  undefined8 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  local_28 = &local_res20;
  local_1c = 0;
  local_20 = 8;
  local_res20 = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&AggregatorCreatedInfo,0,2,local_38);
  return;
}



===== McTemplateK0pp_EtwWriteTransfer @ 1c0005188 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0pp_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5)

{
  undefined8 local_res20;
  undefined1 auStackY_78 [32];
  undefined8 local_48 [2];
  undefined8 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined1 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  local_38 = &local_res20;
  local_2c = 0;
  local_28 = &param_5;
  local_30 = 8;
  local_1c = 0;
  local_20 = 8;
  local_res20 = param_4;
  McGenEventWrite_EtwWriteTransfer(8,param_2,0,3,local_48);
  return;
}



===== lbfoCreateAggregator @ 1c00051f8 =====

longlong * lbfoCreateAggregator(longlong param_1)

{
  code *pcVar1;
  longlong *plVar2;
  longlong lVar3;
  ulonglong uVar4;
  longlong *plVar5;
  byte bVar6;
  undefined8 uVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  ulonglong uVar10;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  undefined4 local_28;
  undefined8 local_18;
  undefined4 local_10;
  undefined4 local_c;
  
  local_c = 0;
  local_10 = 0x10;
  local_18 = 1;
  uVar10 = 0x5463694e;
  local_28 = 1;
  uVar7 = 0x40;
  uVar4 = 0x40;
  plVar2 = (longlong *)ExAllocatePool3();
  puVar8 = auStack_48;
  puVar9 = auStack_48;
  if (plVar2 != (longlong *)0x0) {
    plVar5 = plVar2 + 3;
    plVar2[1] = (longlong)plVar2;
    *plVar2 = (longlong)plVar2;
    plVar2[2] = param_1;
    lVar3 = param_1 + 0x8c8;
    plVar2[4] = (longlong)plVar5;
    *plVar5 = (longlong)plVar5;
    *(short *)(param_1 + 0x8e8) = *(short *)(param_1 + 0x8e8) + 1;
    plVar5 = *(longlong **)(param_1 + 0x8d0);
    if (*plVar5 != lVar3) {
      plVar5 = (longlong *)0x3;
      pcVar1 = (code *)swi(0x29);
      lVar3 = (*pcVar1)();
      puVar8 = auStack_40;
    }
    *plVar2 = lVar3;
    uVar7 = CONCAT71((int7)((ulonglong)uVar7 >> 8),1);
    plVar2[1] = (longlong)plVar5;
    *plVar5 = (longlong)plVar2;
    *(longlong **)(lVar3 + 8) = plVar2;
    uVar10 = *(ulonglong *)(param_1 + 0x860);
    do {
      if ((uVar10 >> ((ulonglong)(((uint)uVar7 & 0xff) - 1 & 0xff) & 0x3f) & 1) == 0) break;
      bVar6 = (char)uVar7 + 1;
      uVar7 = CONCAT71((int7)((ulonglong)uVar7 >> 8),bVar6);
    } while (bVar6 < 0x41);
    *(char *)((longlong)plVar2 + 0x2c) = (char)uVar7;
    uVar4 = (ulonglong)(((uint)uVar7 & 0xff) - 1);
    *(ulonglong *)(param_1 + 0x860) = *(ulonglong *)(param_1 + 0x860) | 1L << (uVar4 & 0x3f);
    puVar9 = puVar8;
  }
  if ((Microsoft_Windows_MsLbfoEventProviderEnableBits & 1) != 0) {
    *(undefined8 *)(puVar9 + -8) = 0x1c00052d0;
    McTemplateK0p_EtwWriteTransfer(uVar4,uVar7,uVar10,plVar2);
  }
  return plVar2;
}



===== lbfoTMConnectNic @ 1c00052f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void lbfoTMConnectNic(longlong param_1,longlong param_2,undefined *param_3,longlong param_4)

{
  short *psVar1;
  code *pcVar2;
  bool bVar3;
  undefined1 uVar4;
  short sVar5;
  longlong lVar6;
  byte bVar7;
  longlong *plVar8;
  longlong *plVar9;
  undefined1 *puVar10;
  undefined1 auStack_c8 [8];
  undefined1 auStack_c0 [24];
  undefined4 local_98;
  uint auStack_94 [3];
  undefined1 local_88 [32];
  longlong local_68;
  undefined4 local_60;
  undefined4 local_5c;
  longlong local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  uint *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_c8;
  bVar3 = true;
  if ((Microsoft_Windows_MsLbfoEventProviderEnableBits & 1) != 0) {
    param_4 = param_2 + 0x30;
    param_3 = (undefined *)0x0;
    McTemplateK0jd_EtwWriteTransfer(param_1,&UsingMemberInfo,0,param_4,0);
  }
  SysEventWriteGuid(0x40004236,param_2 + 0x40);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_3 = &WPP_c3f71c645abb3e40145ee3bc863f34b2_Traceguids;
    param_4 = param_2;
    WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
              &WPP_c3f71c645abb3e40145ee3bc863f34b2_Traceguids,param_2,
              *(undefined1 *)(param_2 + 0x288));
  }
  lbfoCancelSoftFailTimer(param_2);
  puVar10 = auStack_c8;
  lVar6 = param_1 + 0x8d8;
  plVar9 = *(longlong **)(param_1 + 0x8e0);
  plVar8 = (longlong *)(param_2 + 0x10);
  if (*plVar9 != lVar6) {
    plVar8 = (longlong *)0x3;
    pcVar2 = (code *)swi(0x29);
    lVar6 = (*pcVar2)();
    puVar10 = auStack_c0;
  }
  *plVar8 = lVar6;
  plVar8[1] = (longlong)plVar9;
  *plVar9 = (longlong)plVar8;
  *(longlong **)(lVar6 + 8) = plVar8;
  *(undefined4 *)(param_2 + 0x2a0) = 0;
  psVar1 = (short *)(*(longlong *)(param_2 + 0x20) + 0x2a);
  *psVar1 = *psVar1 + 1;
  sVar5 = *(short *)(param_1 + 0x8ec) + 1;
  *(short *)(param_1 + 0x8ec) = sVar5;
  if (sVar5 == 1) {
    uVar4 = *(undefined1 *)(param_2 + 0x288);
  }
  else {
    uVar4 = 0;
  }
  *(undefined1 *)(param_1 + 0x5fa) = uVar4;
  bVar7 = *(byte *)(param_1 + 0x5fb);
  if (*(byte *)(param_1 + 0x5fb) <= *(byte *)(param_2 + 0x288)) {
    bVar7 = *(byte *)(param_2 + 0x288);
  }
  *(byte *)(param_1 + 0x5fb) = bVar7;
  pcVar2 = (code *)(&PTR_lbfoNTHConnectNic_1c0018120)[(longlong)*(int *)(param_1 + 0x5a4) * 0xf];
  if (pcVar2 != (code *)0x0) {
    *(undefined8 *)(puVar10 + -8) = 0x1c0005433;
    (*pcVar2)(param_1,param_2);
  }
  if ((*(byte *)(param_1 + 0x922) & 2) == 0) {
    pcVar2 = *(code **)(&DAT_1c0018148 + (longlong)*(int *)(param_1 + 0x5a4) * 0x78);
    if (pcVar2 != (code *)0x0) {
      *(undefined8 *)(puVar10 + -8) = 0x1c0005459;
      (*pcVar2)(param_1);
    }
    *(undefined8 *)(puVar10 + -8) = 0x1c0005461;
    lbfoCalculateVmqCaps(param_1);
    *(undefined8 *)(puVar10 + -8) = 0x1c0005469;
    lbfoUpdateLinkState(param_1);
  }
  if (5 < DAT_1c00182f0) {
    if (((DAT_1c0018300 & 0x200000000000) == 0) ||
       ((DAT_1c0018308 & 0x200000000000) != DAT_1c0018308)) {
      bVar3 = false;
    }
    if (bVar3) {
      local_5c = 0;
      local_68 = param_1 + 0x24;
      local_4c = 0;
      local_3c = 0;
      local_2c = 0;
      local_58 = param_2 + 0x30;
      local_98 = *(undefined4 *)(param_2 + 0x2a0);
      local_48 = &local_98;
      auStack_94[0] = (uint)*(ushort *)(param_1 + 0x8ec);
      local_38 = auStack_94;
      *(undefined1 **)(puVar10 + 0x28) = local_88;
      *(undefined4 *)(puVar10 + 0x20) = 6;
      local_60 = 0x10;
      local_50 = 0x10;
      local_40 = 4;
      local_30 = 4;
      *(undefined8 *)(puVar10 + -8) = 0x1c000551d;
      _tlgWriteTransfer_EtwWriteTransfer
                (0x10,&DAT_1c0016c67,param_3,param_4,*(undefined4 *)(puVar10 + 0x20),
                 *(undefined8 **)(puVar10 + 0x28));
    }
  }
  *(undefined8 *)(puVar10 + -8) = 0x1c0005529;
  return;
}



===== lbfoTMCreateNewNicAggregator @ 1c0005550 =====

void lbfoTMCreateNewNicAggregator(longlong param_1)

{
  lbfoCreateAggregator(param_1);
  return;
}



===== lbfoTMDisconnectNic @ 1c0005570 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void lbfoTMDisconnectNic(longlong param_1,longlong param_2,undefined8 param_3,longlong param_4)

{
  longlong *plVar1;
  short *psVar2;
  byte bVar3;
  longlong *plVar4;
  code *pcVar5;
  bool bVar6;
  undefined1 uVar7;
  undefined *puVar8;
  longlong lVar9;
  short sVar10;
  longlong *plVar11;
  undefined1 auStackY_d8 [32];
  undefined4 local_a8;
  uint local_a4 [3];
  undefined8 local_98 [4];
  longlong local_78;
  undefined8 local_70;
  longlong local_68;
  undefined8 local_60;
  undefined4 *local_58;
  undefined8 local_50;
  uint *local_48;
  undefined8 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_d8;
  puVar8 = WPP_GLOBAL_Control;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    puVar8 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
    param_4 = param_2;
    WPP_SF_qL(puVar8,0xb,&WPP_c3f71c645abb3e40145ee3bc863f34b2_Traceguids,param_2,
              *(undefined1 *)(param_2 + 0x288));
  }
  bVar6 = true;
  if ((Microsoft_Windows_MsLbfoEventProviderEnableBits & 1) != 0) {
    param_4 = param_2 + 0x30;
    McTemplateK0jd_EtwWriteTransfer(puVar8,&StoppingToUseMemberInfo,0,param_4,0);
  }
  SysEventWriteGuid(0x80004235,param_2 + 0x40);
  plVar1 = (longlong *)(param_2 + 0x10);
  lVar9 = *plVar1;
  if ((*(longlong **)(lVar9 + 8) == plVar1) &&
     (plVar4 = *(longlong **)(param_2 + 0x18), (longlong *)*plVar4 == plVar1)) {
    *plVar4 = lVar9;
    *(longlong **)(lVar9 + 8) = plVar4;
    psVar2 = (short *)(*(longlong *)(param_2 + 0x20) + 0x2a);
    *psVar2 = *psVar2 + -1;
    bVar3 = *(byte *)(param_1 + 0x5fb);
    sVar10 = *(short *)(param_1 + 0x8ec) + -1;
    *(short *)(param_1 + 0x8ec) = sVar10;
    if (bVar3 == *(byte *)(param_2 + 0x288)) {
      do {
        bVar3 = bVar3 - 1;
        if (bVar3 == 0) break;
        lVar9 = *(longlong *)(param_1 + 0x658 + (ulonglong)bVar3 * 8);
      } while ((lVar9 == 0) || (*(int *)(lVar9 + 0x2a0) != 0));
      *(byte *)(param_1 + 0x5fb) = bVar3;
    }
    if (sVar10 == 1) {
      uVar7 = *(undefined1 *)(*(longlong *)(param_1 + 0x8d8) + 0x278);
    }
    else {
      uVar7 = 0;
    }
    *(undefined1 *)(param_1 + 0x5fa) = uVar7;
    plVar1 = (longlong *)(param_1 + 0x8f0);
    plVar4 = (longlong *)(param_2 + 0x2a8);
    plVar11 = *(longlong **)(param_1 + 0x8f8);
    if ((((*(longlong **)(*plVar1 + 8) == plVar1) && ((longlong *)*plVar11 == plVar1)) &&
        (*(longlong **)(*plVar4 + 8) == plVar4)) &&
       ((longlong *)**(undefined8 **)(param_2 + 0x2b0) == plVar4)) {
      *plVar11 = (longlong)plVar4;
      *(undefined8 *)(param_1 + 0x8f8) = *(undefined8 *)(param_2 + 0x2b0);
      **(longlong **)(param_2 + 0x2b0) = (longlong)plVar1;
      lVar9 = *plVar4;
      *(longlong **)(param_2 + 0x2b0) = plVar11;
      if ((*(longlong **)(lVar9 + 8) == plVar4) && ((longlong *)*plVar11 == plVar4)) {
        *plVar11 = lVar9;
        *(longlong **)(lVar9 + 8) = plVar11;
        *(longlong **)(param_2 + 0x2b0) = plVar4;
        *plVar4 = (longlong)plVar4;
        *(short *)(param_1 + 0x8ee) = *(short *)(param_1 + 0x8ee) + *(short *)(param_2 + 0x2b8);
        *(ushort *)(param_2 + 0x2ba) = *(ushort *)(param_2 + 0x2ba) & 0x8000;
        *(byte *)(param_2 + 700) = *(byte *)(param_2 + 700) & 0xfe;
        *(undefined2 *)(param_2 + 0x2b8) = 0;
        lVar9 = (longlong)*(int *)(param_1 + 0x5a4) * 0x78;
        if ((code *)(&PTR_lbfoNTHDisconnectNic_1c0018128)[(longlong)*(int *)(param_1 + 0x5a4) * 0xf]
            != (code *)0x0) {
          lVar9 = param_1;
          (*(code *)(&PTR_lbfoNTHDisconnectNic_1c0018128)[(longlong)*(int *)(param_1 + 0x5a4) * 0xf]
          )(param_1,param_2);
        }
        if ((*(byte *)(param_1 + 0x922) & 2) == 0) {
          if (*(code **)(&DAT_1c0018148 + (longlong)*(int *)(param_1 + 0x5a4) * 0x78) != (code *)0x0
             ) {
            (**(code **)(&DAT_1c0018148 + (longlong)*(int *)(param_1 + 0x5a4) * 0x78))(param_1);
          }
          lbfoCalculateVmqCaps(param_1);
          lVar9 = param_1;
          lbfoUpdateLinkState(param_1);
        }
        if (5 < DAT_1c00182f0) {
          if (((DAT_1c0018300 & 0x200000000000) == 0) ||
             ((DAT_1c0018308 & 0x200000000000) != DAT_1c0018308)) {
            bVar6 = false;
          }
          if (bVar6) {
            local_78 = param_1 + 0x24;
            local_70 = 0x10;
            local_68 = param_2 + 0x30;
            local_60 = 0x10;
            local_a8 = *(undefined4 *)(param_2 + 0x2a0);
            local_58 = &local_a8;
            local_a4[0] = (uint)*(ushort *)(param_1 + 0x8ec);
            local_48 = local_a4;
            local_50 = 4;
            local_40 = 4;
            _tlgWriteTransfer_EtwWriteTransfer(lVar9,&DAT_1c0016bf1,plVar11,param_4,6,local_98);
          }
        }
        return;
      }
    }
  }
  pcVar5 = (code *)swi(0x29);
  (*pcVar5)(3);
  pcVar5 = (code *)swi(3);
  (*pcVar5)();
  return;
}



===== lbfoTMEndBatchUpdate @ 1c0005884 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void lbfoTMEndBatchUpdate(longlong param_1)

{
  *(byte *)(param_1 + 0x922) = *(byte *)(param_1 + 0x922) & 0xfd;
  if (*(code **)(&DAT_1c0018148 + (longlong)*(int *)(param_1 + 0x5a4) * 0x78) != (code *)0x0) {
    (**(code **)(&DAT_1c0018148 + (longlong)*(int *)(param_1 + 0x5a4) * 0x78))();
  }
  lbfoCalculateVmqCaps(param_1);
  lbfoUpdateLinkState(param_1);
  return;
}



===== lbfoTMRemoveAggregator @ 1c00058d4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void lbfoTMRemoveAggregator(longlong param_1,longlong *param_2,undefined8 param_3)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  
  if ((Microsoft_Windows_MsLbfoEventProviderEnableBits & 1) != 0) {
    McTemplateK0pp_EtwWriteTransfer(param_1,&RemovingAggregatorInfo,param_3,param_1,(char)param_2);
  }
  if (*(code **)(&DAT_1c0018018 + (longlong)*(int *)(param_1 + 0x5a8) * 0x48) != (code *)0x0) {
    (**(code **)(&DAT_1c0018018 + (longlong)*(int *)(param_1 + 0x5a8) * 0x48))(param_1,param_2);
  }
  *(short *)(param_1 + 0x8e8) = *(short *)(param_1 + 0x8e8) + -1;
  lVar1 = *param_2;
  if ((*(longlong **)(lVar1 + 8) == param_2) &&
     (plVar2 = (longlong *)param_2[1], (longlong *)*plVar2 == param_2)) {
    *plVar2 = lVar1;
    *(longlong **)(lVar1 + 8) = plVar2;
    *(ulonglong *)(param_1 + 0x860) =
         *(ulonglong *)(param_1 + 0x860) &
         ~(1L << ((ulonglong)(*(byte *)((longlong)param_2 + 0x2c) - 1) & 0x3f));
    ExFreePoolWithTag(param_2,0x5463694e);
    return;
  }
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  pcVar3 = (code *)swi(3);
  (*pcVar3)();
  return;
}



===== GetNblVlan @ 1c0005994 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort GetNblVlan(longlong param_1,longlong param_2)

{
  longlong lVar1;
  ushort uVar2;
  uint uVar3;
  longlong lVar4;
  
  uVar3 = *(uint *)(param_2 + 0xb0) >> 4;
  uVar2 = (ushort)uVar3 & 0xfff;
  if ((*(byte *)(param_1 + 0xcc) & 1) == 0) {
    if (((uVar3 & 0xfff) != 0) && (uVar2 != (*(ushort *)(param_1 + 0xca) & 0xfff))) {
      lVar1 = _DAT_fffff78000000320 - *(longlong *)(param_1 + 0x110);
      lVar4 = 0;
      if (-1 < lVar1) {
        lVar4 = lVar1;
      }
      if (30000000 < lVar4 * (ulonglong)DAT_1c0018470) {
        *(longlong *)(param_1 + 0x110) = _DAT_fffff78000000320;
        SysEventWriteGuid(0x80004232,param_1 + 0x120);
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}



===== WPP_SF__MAC_d @ 1c0005a34 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void WPP_SF__MAC_d(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 *param_4,
                  undefined1 param_5)

{
  undefined1 auStack_78 [32];
  undefined4 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined4 local_28;
  undefined2 local_24;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_78;
  local_28 = *param_4;
  local_48 = &param_5;
  local_38 = 0;
  local_40 = 4;
  local_58 = &local_28;
  local_24 = *(undefined2 *)(param_4 + 1);
  local_50 = 6;
  (*pfnWppTraceMessage)(param_1,0x2b,&WPP_4faf8ad2ef6a3eb9902bc53cbc535b3e_Traceguids);
  return;
}



===== WPP_SF_q_MAC_d @ 1c0005ab8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void WPP_SF_q_MAC_d(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
                   undefined4 *param_5,undefined1 param_6)

{
  undefined1 auStack_98 [32];
  undefined8 *local_78;
  undefined8 local_70;
  undefined4 *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_38 [2];
  undefined4 local_28;
  undefined2 local_24;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_98;
  local_48 = 0;
  local_50 = 4;
  local_28 = *param_5;
  local_24 = *(undefined2 *)(param_5 + 1);
  local_58 = &param_6;
  local_68 = &local_28;
  local_60 = 6;
  local_78 = local_38;
  local_70 = 8;
  local_38[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2);
  return;
}



===== WPP_SF_q_MAC_dd @ 1c0005b60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void WPP_SF_q_MAC_dd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                    undefined4 *param_5,undefined1 param_6,undefined1 param_7)

{
  undefined1 auStack_a8 [32];
  undefined8 *local_88;
  undefined8 local_80;
  undefined4 *local_78;
  undefined8 local_70;
  undefined1 *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_38 [2];
  undefined4 local_28;
  undefined2 local_24;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_a8;
  local_48 = 0;
  local_28 = *param_5;
  local_24 = *(undefined2 *)(param_5 + 1);
  local_58 = &param_7;
  local_50 = 4;
  local_68 = &param_6;
  local_60 = 4;
  local_78 = &local_28;
  local_70 = 6;
  local_88 = local_38;
  local_80 = 8;
  local_38[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b);
  return;
}



===== WPP_SF_qqq @ 1c0005c14 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqq(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,&param_5,8,&param_6,8,0);
  return;
}



===== lbfoLBCompareCfgMacs @ 1c0005c70 =====

int lbfoLBCompareCfgMacs(longlong param_1,longlong param_2)

{
  int iVar1;
  
  iVar1 = (uint)(ushort)((*(ushort *)(param_1 + 0x20) & 0x3fff) -
                        (ushort)(*(byte *)(param_1 + 0x22) >> 1 & 1)) -
          (uint)(ushort)((*(ushort *)(param_2 + 0x20) & 0x3fff) -
                        (ushort)(*(byte *)(param_2 + 0x22) >> 1 & 1));
  if (iVar1 == 0) {
    iVar1 = (uint)(*(longlong *)(param_1 + -8) != 0) - (uint)(*(longlong *)(param_2 + -8) != 0);
  }
  return iVar1;
}



===== lbfoLBCompareNics @ 1c0005cd0 =====

int lbfoLBCompareNics(longlong param_1,longlong param_2)

{
  return (uint)(ushort)((*(ushort *)(param_1 + 0x2aa) & 0x7fff) -
                       (ushort)(*(byte *)(param_1 + 0x2ac) & 1)) -
         (uint)(ushort)((*(ushort *)(param_2 + 0x2aa) & 0x7fff) -
                       (ushort)(*(byte *)(param_2 + 0x2ac) & 1));
}



===== lbfoLBComputeHash @ 1c0005d20 =====

void lbfoLBComputeHash(byte *param_1,uint param_2,uint *param_3)

{
  uint uVar1;
  byte *pbVar2;
  
  pbVar2 = param_1 + param_2;
  for (; param_1 != pbVar2; param_1 = param_1 + 1) {
    uVar1 = *param_3;
    *param_3 = (uint)*param_1 + uVar1 * 0x40 + -0x61c88647 + (uVar1 >> 2) ^ uVar1;
  }
  return;
}



===== lbfoLBComputeMinVmsPortsPerNic @ 1c0005d64 =====

ulonglong lbfoLBComputeMinVmsPortsPerNic(longlong param_1,short *param_2,undefined1 *param_3)

{
  undefined8 *puVar1;
  longlong *plVar2;
  ushort uVar3;
  undefined8 *puVar4;
  undefined **ppuVar5;
  longlong *plVar6;
  uint uVar7;
  ushort uVar8;
  short sVar9;
  ulonglong uVar10;
  short sVar11;
  
  puVar1 = (undefined8 *)(param_1 + 0x8d8);
  MergeSortList(puVar1,lbfoLBCompareNics,'\0');
  uVar10 = 0;
  plVar2 = (longlong *)(param_1 + 0x8f0);
  plVar6 = (longlong *)*plVar2;
  uVar7 = 0;
  if (plVar6 != plVar2) {
    do {
      uVar8 = (short)uVar7 +
              ((*(ushort *)(plVar6 + 4) & 0x3fff) -
              (ushort)(*(byte *)((longlong)plVar6 + 0x22) >> 1 & 1));
      uVar7 = (uint)uVar8;
      plVar6 = (longlong *)*plVar6;
    } while (plVar6 != plVar2);
    if (uVar8 != 0) {
      puVar4 = (undefined8 *)*puVar1;
      sVar9 = 0;
      while( true ) {
        uVar8 = (ushort)uVar7;
        if (puVar4 == puVar1) break;
        sVar11 = (*(ushort *)((longlong)puVar4 + 0x2aa) & 0x7fff) -
                 (ushort)(*(byte *)((longlong)puVar4 + 0x2ac) & 1);
        uVar3 = (sVar11 - sVar9) * (ushort)uVar10;
        if (uVar8 <= uVar3) break;
        uVar7 = (uint)(ushort)(uVar8 - uVar3);
        puVar4 = (undefined8 *)*puVar4;
        uVar10 = (ulonglong)(byte)((char)uVar10 + 1);
        sVar9 = sVar11;
      }
      if ((ushort)uVar10 <= uVar8) {
        sVar9 = sVar9 + (short)(uVar7 / uVar10);
        uVar7 = (uint)((ulonglong)uVar7 % uVar10);
      }
      ppuVar5 = &WPP_GLOBAL_Control;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])) {
        ppuVar5 = (undefined **)
                  WPP_SF_qdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
                             &WPP_4faf8ad2ef6a3eb9902bc53cbc535b3e_Traceguids,param_1,(char)sVar9,
                             (char)uVar7);
      }
      *param_2 = sVar9;
      *param_3 = (char)uVar7;
      return CONCAT71((int7)((ulonglong)ppuVar5 >> 8),1);
    }
  }
  return (ulonglong)plVar6 & 0xffffffffffffff00;
}



===== lbfoLBDistributeSinglePortCfgMacs @ 1c0005edc =====

undefined8
lbfoLBDistributeSinglePortCfgMacs
          (longlong param_1,longlong param_2,ushort param_3,ushort param_4,char *param_5,
          char param_6)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  bool bVar3;
  bool bVar4;
  undefined8 *puVar5;
  ushort uVar6;
  
  bVar3 = true;
  do {
    for (puVar1 = *(undefined8 **)(param_1 + 0x8d8); puVar1 != (undefined8 *)(param_1 + 0x8d8);
        puVar1 = (undefined8 *)*puVar1) {
      uVar6 = (*(ushort *)((longlong)puVar1 + 0x2aa) & 0x7fff) -
              (ushort)(*(byte *)((longlong)puVar1 + 0x2ac) & 1);
      if ((uVar6 < param_4) || ((uVar6 == param_4 && (*param_5 != '\0')))) {
        puVar2 = *(undefined8 **)(param_1 + 0x8f0);
        do {
          while( true ) {
            do {
              puVar5 = puVar2;
              if (puVar5 == (undefined8 *)(param_1 + 0x8f0)) goto LAB_1c0006019;
              puVar2 = (undefined8 *)*puVar5;
            } while ((((*(ushort *)(puVar5 + 4) & 0x3fff) ==
                       (ushort)(*(byte *)((longlong)puVar5 + 0x22) >> 1 & 1)) ||
                     ((param_6 != '\0' &&
                      (*(short *)(puVar5[2] + 0x14) != *(short *)((longlong)puVar1 + 0x94))))) ||
                    ((bVar3 && ((undefined8 *)puVar5[-1] != puVar1 + -2))));
            lbfoLBMapCfgMacToNic
                      (param_1,param_2,param_3,(longlong)(puVar5 + -6),(longlong)(puVar1 + -2));
            uVar6 = (*(ushort *)((longlong)puVar1 + 0x2aa) & 0x7fff) -
                    (ushort)(*(byte *)((longlong)puVar1 + 0x2ac) & 1);
            if (uVar6 != param_4) break;
            if (*param_5 == '\0') goto LAB_1c0006019;
          }
        } while (uVar6 <= param_4);
        *param_5 = *param_5 + -1;
      }
LAB_1c0006019:
    }
    bVar4 = !bVar3;
    bVar3 = false;
    if (bVar4) {
      return CONCAT71((int7)((ulonglong)puVar1 >> 8),*(short *)(param_1 + 0x8ee) == 0);
    }
  } while( true );
}



===== lbfoLBGetMappedNicId @ 1c0006074 =====

char lbfoLBGetMappedNicId(longlong param_1,longlong param_2,char *param_3,ushort param_4)

{
  ushort uVar1;
  longlong lVar2;
  char cVar3;
  longlong lVar4;
  undefined2 local_res8;
  undefined1 local_resa;
  
  uVar1 = *(ushort *)(param_2 + 0x12a);
  lVar2 = *(longlong *)(param_1 + 0x10);
  if (uVar1 == 0) {
    cVar3 = lbfoLBGetMappedNicIdFromMac(param_1,param_2);
    if (cVar3 == '\0') {
      cVar3 = *param_3;
    }
  }
  else {
    local_res8 = 0;
    local_resa = 0;
    if ((uint)uVar1 < (uint)param_4) {
      cVar3 = param_3[uVar1];
    }
    else {
      NdisAcquireRWLockRead(*(undefined8 *)(lVar2 + 0x5e8),&local_res8,1);
      lVar4 = lbfoGetVmsPortFromVmsId(lVar2,(uint)uVar1);
      if ((lVar4 == 0) || (*(longlong *)(lVar4 + 0x48) == 0)) {
        cVar3 = '\0';
      }
      else {
        cVar3 = *(char *)(*(longlong *)(lVar4 + 0x48) + 0x288);
      }
      NdisReleaseRWLock(*(undefined8 *)(lVar2 + 0x5e8),&local_res8);
    }
  }
  return cVar3;
}



===== lbfoLBGetMappedNicIdFromMac @ 1c000612c =====

undefined1 lbfoLBGetMappedNicIdFromMac(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined6 uVar2;
  ushort uVar3;
  longlong lVar4;
  undefined1 uVar5;
  undefined2 local_res8;
  undefined1 local_resa;
  
  lVar1 = *(longlong *)(param_1 + 0x10);
  local_res8 = 0;
  local_resa = 0;
  uVar5 = 0;
  lVar4 = NdisGetDataBuffer(*(undefined8 *)(param_2 + 8),0xe,0,1,0);
  if (lVar4 != 0) {
    NdisAcquireRWLockRead(*(undefined8 *)(lVar1 + 0x5e8),&local_res8,1);
    uVar2 = *(undefined6 *)(lVar4 + 6);
    uVar3 = GetNblVlan(param_1,param_2);
    lVar4 = RtlLookupEntryHashTable(lVar1 + 0x628,CONCAT26(uVar3,uVar2) | 0x8000000000000000,0);
    if ((lVar4 != 0) && (*(longlong *)(lVar4 + 0x28) != 0)) {
      uVar5 = *(undefined1 *)(*(longlong *)(lVar4 + 0x28) + 0x288);
    }
    NdisReleaseRWLock(*(undefined8 *)(lVar1 + 0x5e8),&local_res8);
  }
  return uVar5;
}



===== lbfoLBGetNblHash @ 1c000623c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint lbfoLBGetNblHash(longlong param_1,int param_2,undefined1 *param_3)

{
  longlong lVar1;
  bool bVar2;
  longlong lVar3;
  longlong lVar4;
  byte *pbVar5;
  uint uVar6;
  byte *pbVar7;
  uint uVar8;
  ulonglong uVar9;
  uint uVar10;
  ushort uVar11;
  undefined1 auStack_98 [32];
  undefined4 local_78;
  undefined4 local_70;
  uint local_68 [2];
  undefined1 *local_60;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_98;
  local_68[0] = *(uint *)(param_1 + 0xd0);
  uVar8 = 0;
  lVar4 = *(longlong *)(param_1 + 8);
  bVar2 = false;
  lVar1 = *(longlong *)(lVar4 + 8);
  *param_3 = 0;
  if ((local_68[0] == 0) || (param_2 != 0)) {
    local_68[0] = 0;
  }
  else {
    bVar2 = true;
  }
  local_60 = param_3;
  if ((*(byte *)(lVar1 + 10) & 5) == 0) {
    local_70 = 0x40000000;
    local_78 = 0;
    lVar3 = MmMapLockedPagesSpecifyCache(lVar1,0,1);
  }
  else {
    lVar3 = *(longlong *)(lVar1 + 0x18);
  }
  if (lVar3 == 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
              &WPP_4faf8ad2ef6a3eb9902bc53cbc535b3e_Traceguids);
    }
    return 0;
  }
  uVar10 = *(uint *)(lVar4 + 0x10);
  pbVar7 = (byte *)(lVar3 + (ulonglong)uVar10);
  uVar10 = *(int *)(lVar1 + 0x28) - uVar10;
  if ((uVar10 < 0xe) || (((ulonglong)pbVar7 & 1) != 0)) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return local_68[0];
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 5) {
      return local_68[0];
    }
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
            &WPP_4faf8ad2ef6a3eb9902bc53cbc535b3e_Traceguids);
    return local_68[0];
  }
  uVar11 = *(ushort *)(pbVar7 + 0xc);
  lVar4 = 0xe;
  if (((((ushort)(uVar11 >> 8 | uVar11 << 8) < 0x600) && (0x15 < uVar10)) && (pbVar7[0xe] == 0xaa))
     && (pbVar7[0xf] == 0xaa)) {
    uVar11 = *(ushort *)(pbVar7 + 0x14);
    lVar4 = 0x16;
  }
  uVar6 = 8;
  uVar9 = (ulonglong)uVar10;
  if ((uVar11 == 8) && (lVar4 + 0x14U <= uVar9)) {
    uVar8 = (uint)pbVar7[lVar4 + 9];
    if (*(int *)(pbVar7 + lVar4 + 0x10) == -1) {
      *local_60 = 1;
    }
    if (!bVar2) {
      if (2 < param_2) goto LAB_1c00063e2;
      pbVar5 = pbVar7 + lVar4 + 0xc;
      goto LAB_1c00063ea;
    }
  }
  else {
    if ((uVar11 == 0xdd86) && (lVar4 + 0x28U <= uVar9)) {
      uVar8 = (uint)pbVar7[lVar4 + 6];
      if (bVar2) goto LAB_1c000643a;
      if (param_2 < 3) {
        uVar6 = 0x20;
        pbVar5 = pbVar7 + lVar4 + 8;
        goto LAB_1c00063ea;
      }
    }
    else if (bVar2) goto LAB_1c0006443;
LAB_1c00063e2:
    uVar6 = 0xc;
    pbVar5 = pbVar7;
LAB_1c00063ea:
    lbfoLBComputeHash(pbVar5,uVar6,local_68);
    if (param_2 < 2) {
      if ((uVar8 != 6) && (uVar8 != 0x11)) goto LAB_1c0006443;
      uVar10 = *(ushort *)(param_1 + 0x92) & 0x3ff;
      if ((((*(ushort *)(param_1 + 0x92) & 0x3ff) != 0) ||
          (uVar10 = *(uint *)(param_1 + 0xa0) >> 0x14 & 0x3ff, uVar10 != 0)) &&
         ((ulonglong)uVar10 + 4 <= uVar9)) {
        lbfoLBComputeHash(pbVar7 + uVar10,4,local_68);
      }
    }
  }
LAB_1c000643a:
  if (uVar8 == 6) {
    return local_68[0];
  }
LAB_1c0006443:
  if (((((uVar8 - 1 < 2) || (uVar8 == 0x3a)) || (uVar11 == 0x608)) ||
      ((*(int *)pbVar7 == -1 && (*(short *)(pbVar7 + 4) == -1)))) ||
     ((*(int *)pbVar7 == 0x3333 && (*(short *)(pbVar7 + 4) == 0x100)))) {
    *local_60 = 1;
  }
  return local_68[0];
}



===== lbfoLBGetSwitchPrimingNbls @ 1c00064fc =====

int lbfoLBGetSwitchPrimingNbls(longlong param_1,longlong param_2,undefined8 param_3)

{
  undefined8 *puVar1;
  byte bVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  uint uVar5;
  int iVar6;
  undefined8 *puVar7;
  
  iVar6 = 0;
  puVar7 = (undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x8d8);
  for (puVar3 = (undefined8 *)*puVar7; puVar3 != puVar7; puVar3 = (undefined8 *)*puVar3) {
    bVar2 = *(byte *)(puVar3 + 0x4f);
    puVar1 = puVar3 + 0x53;
    puVar4 = (undefined8 *)*puVar1;
    if (puVar4 != puVar1) {
      do {
        uVar5 = lbfoLBGetSwitchPrimingNblsForCfgMac
                          (param_1,(longlong)(puVar4 + -6),
                           (undefined8 *)(param_2 + ((ulonglong)bVar2 - 1) * 8),param_3);
        puVar4 = (undefined8 *)*puVar4;
        iVar6 = iVar6 + uVar5;
      } while (puVar4 != puVar1);
    }
  }
  return iVar6;
}



===== lbfoLBGetSwitchPrimingNblsForCfgMac @ 1c00065ac =====

uint lbfoLBGetSwitchPrimingNblsForCfgMac
               (longlong param_1,longlong param_2,undefined8 *param_3,undefined8 param_4)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = 0;
  if ((*(byte *)(param_2 + 0x52) & 1) != 0) {
    iVar3 = lbfoAddEtherBcastNbl(param_1,param_2,param_3,param_4);
    if (iVar3 == 0) {
      *(byte *)(param_2 + 0x52) = *(byte *)(param_2 + 0x52) & 0xfe;
    }
    uVar5 = (uint)(iVar3 == 0);
    for (puVar1 = *(undefined8 **)(param_2 + 0x40); puVar1 != (undefined8 *)(param_2 + 0x40);
        puVar1 = (undefined8 *)*puVar1) {
      for (puVar2 = (undefined8 *)puVar1[3]; puVar2 != puVar1 + 3; puVar2 = (undefined8 *)*puVar2) {
        iVar3 = lbfoAddEtherBcastNbl(param_1,(longlong)(puVar2 + -6),param_3,param_4);
        uVar4 = uVar5 + 1;
        if (iVar3 != 0) {
          uVar4 = uVar5;
        }
        uVar5 = uVar4;
      }
    }
  }
  return uVar5;
}



===== lbfoLBInitialMapVmsPort @ 1c0006668 =====

void lbfoLBInitialMapVmsPort(longlong param_1,int param_2,longlong param_3,ushort param_4)

{
  longlong lVar1;
  undefined8 *puVar2;
  bool bVar3;
  ushort uVar4;
  longlong lVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  ushort uVar8;
  
  lVar5 = lbfoGetVmsPortFromVmsId(param_1,param_2);
  lVar1 = *(longlong *)(lVar5 + 0x40);
  if ((*(longlong *)(lVar1 + 0x28) == 0) && (*(short *)(param_1 + 0x8ec) != 0)) {
    puVar6 = (undefined8 *)0x0;
    if (((DAT_1c001849c & 0x40) == 0) ||
       (bVar3 = true,
       (ushort)((*(ushort *)(lVar1 + 0x50) & 0x3fff) - (ushort)(*(byte *)(lVar1 + 0x52) >> 1 & 1))
       != 1)) {
      bVar3 = false;
    }
    for (puVar2 = *(undefined8 **)(param_1 + 0x8d8);
        (puVar7 = puVar6, puVar2 != (undefined8 *)(param_1 + 0x8d8) &&
        ((puVar7 = puVar2 + -2, *(int *)(puVar2 + 3) != *(int *)(lVar1 + 0x18) ||
         (*(short *)((longlong)puVar2 + 0x1c) != *(short *)(lVar1 + 0x1c)))));
        puVar2 = (undefined8 *)*puVar2) {
      if ((puVar6 == (undefined8 *)0x0) ||
         ((uVar8 = (*(ushort *)((longlong)puVar6 + 0x2ba) & 0x7fff) -
                   (ushort)(*(byte *)((longlong)puVar6 + 700) & 1),
          uVar4 = (*(ushort *)((longlong)puVar2 + 0x2aa) & 0x7fff) -
                  (ushort)(*(byte *)((longlong)puVar2 + 0x2ac) & 1), uVar4 < uVar8 ||
          (((uVar4 == uVar8 && (bVar3)) &&
           (*(short *)(lVar5 + 0x2c) == *(short *)((longlong)puVar2 + 0x94))))))) {
        puVar6 = puVar7;
      }
    }
    lbfoLBMapCfgMacToNic(param_1,param_3,param_4,lVar1,(longlong)puVar7);
  }
  return;
}



===== lbfoLBMapCfgMacToNic @ 1c00067c0 =====

void lbfoLBMapCfgMacToNic
               (longlong param_1,longlong param_2,ushort param_3,longlong param_4,longlong param_5)

{
  longlong *plVar1;
  ushort uVar2;
  longlong lVar3;
  longlong *plVar4;
  code *pcVar5;
  uint uVar6;
  undefined4 local_18;
  undefined2 local_14;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    local_18 = *(undefined4 *)(param_4 + 0x18);
    uVar6 = *(ushort *)(param_4 + 0x1e) & 0xfff;
    local_14 = *(undefined2 *)(param_4 + 0x1c);
    WPP_SF_q_MAC_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(ulonglong)uVar6,
                    &WPP_4faf8ad2ef6a3eb9902bc53cbc535b3e_Traceguids,param_1,&local_18,(char)uVar6,
                    *(undefined1 *)(param_5 + 0x288));
  }
  plVar1 = (longlong *)(param_4 + 0x30);
  lVar3 = *plVar1;
  if ((*(longlong **)(lVar3 + 8) == plVar1) &&
     (plVar4 = *(longlong **)(param_4 + 0x38), (longlong *)*plVar4 == plVar1)) {
    *plVar4 = lVar3;
    *(longlong **)(lVar3 + 8) = plVar4;
    *(short *)(param_1 + 0x8ee) = *(short *)(param_1 + 0x8ee) + -1;
    plVar4 = *(longlong **)(param_5 + 0x2b0);
    if (*plVar4 == param_5 + 0x2a8) {
      *plVar1 = param_5 + 0x2a8;
      *(longlong **)(param_4 + 0x38) = plVar4;
      *plVar4 = (longlong)plVar1;
      *(longlong **)(param_5 + 0x2b0) = plVar1;
      uVar2 = *(ushort *)(param_5 + 0x2ba);
      *(short *)(param_5 + 0x2b8) = *(short *)(param_5 + 0x2b8) + 1;
      *(ushort *)(param_5 + 0x2ba) =
           ((*(ushort *)(param_4 + 0x50) & 0x3fff) + uVar2 ^ uVar2) & 0x7fff ^ uVar2;
      *(byte *)(param_5 + 700) =
           (*(byte *)(param_4 + 0x52) >> 1 | *(byte *)(param_5 + 700)) & 1 ^
           *(byte *)(param_5 + 700) & 0xfe;
      if ((*(longlong *)(param_4 + 0x28) != 0) &&
         (*(longlong *)(*(longlong *)(param_4 + 0x28) + 0x20) != *(longlong *)(param_5 + 0x20))) {
        *(byte *)(param_4 + 0x52) = *(byte *)(param_4 + 0x52) | 1;
        *(byte *)(param_1 + 0x922) = *(byte *)(param_1 + 0x922) | 8;
        lbfoQueuePrimeSwitchIfNeededWorkItem(param_1);
      }
      *(longlong *)(param_4 + 0x28) = param_5;
      lbfoLBUpdateCfgMacVmsPorts(param_4,param_2,param_3);
      return;
    }
  }
  pcVar5 = (code *)swi(0x29);
  (*pcVar5)(3);
  pcVar5 = (code *)swi(3);
  (*pcVar5)();
  return;
}



===== lbfoLBRebalanceCfgMacs @ 1c0006950 =====

void lbfoLBRebalanceCfgMacs(longlong param_1,longlong param_2,ushort param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined8 *puVar4;
  longlong *plVar5;
  longlong lVar6;
  code *pcVar7;
  ushort uVar8;
  undefined8 *puVar9;
  undefined8 *puVar10;
  undefined8 uVar11;
  undefined1 *puVar12;
  undefined8 *puVar13;
  undefined **ppuVar14;
  ushort uVar15;
  uint local_res8;
  undefined2 local_resc;
  longlong local_res10;
  ushort local_res18;
  ushort local_res20 [4];
  undefined1 auStackY_88 [8];
  undefined1 auStackY_80 [24];
  undefined4 local_58;
  undefined2 local_54;
  
  local_res20[0] = 0;
  local_res8 = local_res8 & 0xffffff00;
  local_res10 = param_2;
  local_res18 = param_3;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
             &WPP_4faf8ad2ef6a3eb9902bc53cbc535b3e_Traceguids,param_1);
  }
  ppuVar14 = &WPP_GLOBAL_Control;
  *(byte *)(param_1 + 0x922) = *(byte *)(param_1 + 0x922) & 0xf3;
  if (*(short *)(param_1 + 0x8ec) == 0) {
    for (puVar9 = *(undefined8 **)(param_1 + 0x8f0); puVar9 != (undefined8 *)(param_1 + 0x8f0);
        puVar9 = (undefined8 *)*puVar9) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])) {
        local_res8 = *(uint *)(puVar9 + -3);
        local_resc = *(undefined2 *)((longlong)puVar9 + -0x14);
        WPP_SF_q_MAC_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                       &WPP_4faf8ad2ef6a3eb9902bc53cbc535b3e_Traceguids,param_1,&local_res8,
                       (char)*(undefined2 *)((longlong)puVar9 + -0x12));
      }
      *(byte *)((longlong)puVar9 + 0x22) = *(byte *)((longlong)puVar9 + 0x22) & 0xfe;
      puVar9[-1] = 0;
      lbfoLBUpdateCfgMacVmsPorts((longlong)(puVar9 + -6),param_2,param_3);
    }
    return;
  }
  puVar9 = (undefined8 *)(param_1 + 0x8d8);
  plVar1 = (longlong *)(param_1 + 0x8f0);
  puVar10 = (undefined8 *)*puVar9;
  while( true ) {
    puVar12 = auStackY_88;
    puVar13 = puVar10 + -2;
    if (puVar10 == puVar9) break;
    plVar5 = puVar13 + 0x55;
    plVar2 = *(longlong **)(param_1 + 0x8f8);
    if ((((*(longlong **)(*plVar1 + 8) != plVar1) || ((longlong *)*plVar2 != plVar1)) ||
        (*(longlong **)(*plVar5 + 8) != plVar5)) || (*(longlong **)puVar13[0x56] != plVar5)) {
LAB_1c0006b27:
      pcVar7 = (code *)swi(0x29);
      (*pcVar7)(3);
      puVar12 = auStackY_80;
      break;
    }
    *plVar2 = (longlong)plVar5;
    *(undefined8 *)(param_1 + 0x8f8) = puVar13[0x56];
    *(longlong **)puVar13[0x56] = plVar1;
    lVar3 = *plVar5;
    puVar13[0x56] = plVar2;
    if ((*(longlong **)(lVar3 + 8) != plVar5) || ((longlong *)*plVar2 != plVar5))
    goto LAB_1c0006b27;
    *plVar2 = lVar3;
    *(longlong **)(lVar3 + 8) = plVar2;
    puVar13[0x56] = plVar5;
    *plVar5 = (longlong)plVar5;
    *(short *)(param_1 + 0x8ee) = *(short *)(param_1 + 0x8ee) + *(short *)(puVar13 + 0x57);
    *(ushort *)((longlong)puVar10 + 0x2aa) = *(ushort *)((longlong)puVar10 + 0x2aa) & 0x8000;
    puVar4 = (undefined8 *)puVar13[2];
    *(byte *)((longlong)puVar10 + 0x2ac) = *(byte *)((longlong)puVar10 + 0x2ac) & 0xfe;
    *(undefined2 *)(puVar13 + 0x57) = 0;
    puVar10 = puVar4;
  }
  plVar5 = (longlong *)*plVar1;
  if ((longlong *)*plVar1 != plVar1) {
    do {
      plVar2 = (longlong *)*plVar5;
      for (puVar10 = *(undefined8 **)(param_1 + 0x8d8); puVar10 != puVar9;
          puVar10 = (undefined8 *)*puVar10) {
        if ((*(int *)(puVar10 + 3) == (int)plVar5[-3]) &&
           (*(short *)((longlong)puVar10 + 0x1c) == *(short *)((longlong)plVar5 + -0x14))) {
          if ((*(ushort *)(plVar5 + 4) & 0x3fff) !=
              (ushort)(*(byte *)((longlong)plVar5 + 0x22) >> 1 & 1)) {
            if (((undefined **)WPP_GLOBAL_Control != ppuVar14) &&
               (2 < (byte)WPP_GLOBAL_Control[0x29])) {
              uVar11 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
              local_58 = *(undefined4 *)(puVar10 + 3);
              local_54 = *(undefined2 *)((longlong)puVar10 + 0x1c);
              *(uint *)(puVar12 + 0x20) = (uint)*(byte *)(puVar10 + 0x4f);
              *(undefined8 *)(puVar12 + -8) = 0x1c0006bce;
              WPP_SF__MAC_d(uVar11,0x3fff,puVar13,&local_58,puVar12[0x20]);
            }
            lVar3 = *(longlong *)(param_1 + 0x10);
            *(undefined8 *)(puVar12 + -8) = 0x1c0006be3;
            SysEventWriteGuid(0x80004231,lVar3 + 0x120);
          }
          puVar13 = (undefined8 *)(ulonglong)local_res18;
          *(undefined8 **)(puVar12 + 0x20) = puVar10 + -2;
          *(undefined8 *)(puVar12 + -8) = 0x1c0006bfc;
          lbfoLBMapCfgMacToNic
                    (param_1,local_res10,local_res18,(longlong)(plVar5 + -6),
                     *(longlong *)(puVar12 + 0x20));
          break;
        }
      }
      ppuVar14 = &WPP_GLOBAL_Control;
      plVar5 = plVar2;
    } while (plVar2 != plVar1);
    param_3 = local_res18;
  }
  if (*(short *)(param_1 + 0x8ee) == 0) goto LAB_1c0006e0a;
  *(undefined8 *)(puVar12 + -8) = 0x1c0006c4b;
  MergeSortList(plVar1,lbfoLBCompareCfgMacs,'\x01');
  lVar3 = local_res10;
  while ((plVar1 = *(longlong **)(param_1 + 0x8f0), plVar1 != (longlong *)(param_1 + 0x8f0) &&
         (1 < (ushort)((*(ushort *)(plVar1 + 4) & 0x3fff) -
                      (ushort)(*(byte *)((longlong)plVar1 + 0x22) >> 1 & 1))))) {
    puVar10 = *(undefined8 **)(param_1 + 0x8d8);
    puVar13 = (undefined8 *)0x0;
    if (puVar10 != puVar9) {
      do {
        if (((puVar13 == (undefined8 *)0x0) ||
            (uVar15 = (*(ushort *)((longlong)puVar13 + 0x2ba) & 0x7fff) -
                      (ushort)(*(byte *)((longlong)puVar13 + 700) & 1),
            uVar8 = (*(ushort *)((longlong)puVar10 + 0x2aa) & 0x7fff) -
                    (ushort)(*(byte *)((longlong)puVar10 + 0x2ac) & 1), uVar8 < uVar15)) ||
           ((uVar8 == uVar15 && ((undefined8 *)plVar1[-1] == puVar10 + -2)))) {
          puVar13 = puVar10 + -2;
        }
        puVar10 = (undefined8 *)*puVar10;
      } while (puVar10 != puVar9);
      param_3 = local_res18;
    }
    *(undefined8 **)(puVar12 + 0x20) = puVar13;
    *(undefined8 *)(puVar12 + -8) = 0x1c0006d13;
    lbfoLBMapCfgMacToNic
              (param_1,lVar3,param_3,(longlong)(plVar1 + -6),*(longlong *)(puVar12 + 0x20));
  }
  if (*(short *)(param_1 + 0x8ee) == 0) goto LAB_1c0006e0a;
  *(undefined8 *)(puVar12 + -8) = 0x1c0006d36;
  uVar11 = lbfoLBComputeMinVmsPortsPerNic(param_1,(short *)local_res20,(undefined1 *)&local_res8);
  if ((char)uVar11 != '\0') {
    if ((DAT_1c001849c & 0x40) == 0) {
LAB_1c0006d69:
      puVar12[0x28] = 0;
      *(uint **)(puVar12 + 0x20) = &local_res8;
      *(undefined8 *)(puVar12 + -8) = 0x1c0006d8b;
      lbfoLBDistributeSinglePortCfgMacs
                (param_1,lVar3,param_3,local_res20[0],*(char **)(puVar12 + 0x20),puVar12[0x28]);
    }
    else {
      puVar12[0x28] = 1;
      *(uint **)(puVar12 + 0x20) = &local_res8;
      *(undefined8 *)(puVar12 + -8) = 0x1c0006d65;
      uVar11 = lbfoLBDistributeSinglePortCfgMacs
                         (param_1,lVar3,param_3,local_res20[0],*(char **)(puVar12 + 0x20),
                          puVar12[0x28]);
      if ((char)uVar11 == '\0') goto LAB_1c0006d69;
    }
    if (*(short *)(param_1 + 0x8ee) == 0) goto LAB_1c0006e0a;
  }
  puVar10 = *(undefined8 **)(param_1 + 0x8d8);
  puVar13 = (undefined8 *)0x0;
  lVar6 = *(longlong *)(param_1 + 0x8f0);
  if (puVar10 != puVar9) {
    do {
      if (((puVar13 == (undefined8 *)0x0) ||
          (uVar8 = *(ushort *)((longlong)puVar13 + 0x2ba) & 0x7fff,
          uVar15 = *(ushort *)((longlong)puVar10 + 0x2aa) & 0x7fff, uVar15 < uVar8)) ||
         ((uVar15 == uVar8 && (*(undefined8 **)(lVar6 + -8) == puVar10 + -2)))) {
        puVar13 = puVar10 + -2;
      }
      puVar10 = (undefined8 *)*puVar10;
    } while (puVar10 != puVar9);
    param_3 = local_res18;
  }
  *(undefined8 **)(puVar12 + 0x20) = puVar13;
  *(undefined8 *)(puVar12 + -8) = 0x1c0006e0a;
  lbfoLBMapCfgMacToNic(param_1,lVar3,param_3,lVar6 + -0x30,*(longlong *)(puVar12 + 0x20));
LAB_1c0006e0a:
  if ((*(byte *)(param_1 + 0x922) & 8) != 0) {
    *(byte *)(param_1 + 0x922) = *(byte *)(param_1 + 0x922) | 0x11;
  }
  return;
}



===== lbfoLBReplaceNblMacAddress @ 1c0006e34 =====

undefined8 lbfoLBReplaceNblMacAddress(longlong param_1,undefined4 *param_2)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  longlong *plVar5;
  undefined4 local_res8;
  undefined2 local_resc;
  
  lVar1 = *(longlong *)(param_1 + 0x10);
  uVar3 = 0;
  uVar4 = (ulonglong)*(ushort *)(lVar1 + 10);
  if ((*(ulonglong *)(param_1 + 0x70) >> 0x28 & 1) == 0) {
    plVar5 = *(longlong **)(param_1 + 8);
    lVar2 = NdisGetDataBuffer(plVar5,0xe,0,1,0);
    if (lVar2 != 0) {
      *(undefined1 *)(lVar1 + 0x18 + uVar4) = 1;
      *(undefined4 *)(lVar1 + 0x10 + uVar4) = *(undefined4 *)(lVar2 + 6);
      *(undefined2 *)(lVar1 + 0x14 + uVar4) = *(undefined2 *)(lVar2 + 10);
      do {
        *(undefined4 *)(lVar2 + 6) = *param_2;
        *(undefined2 *)(lVar2 + 10) = *(undefined2 *)(param_2 + 1);
        plVar5 = (longlong *)*plVar5;
        if (plVar5 == (longlong *)0x0) {
          return 0;
        }
        lVar2 = NdisGetDataBuffer(plVar5,0xe,0,1,0);
      } while (lVar2 != 0);
    }
    uVar3 = 0xc0010016;
    if (*(char *)(lVar1 + 0x18 + uVar4) != '\0') {
      local_res8 = *(undefined4 *)(lVar1 + 0x10 + uVar4);
      local_resc = *(undefined2 *)(lVar1 + 0x14 + uVar4);
      lbfoLBRevertMacAddress(*(longlong **)(param_1 + 8),plVar5,&local_res8);
    }
  }
  return uVar3;
}



===== lbfoLBRevertMacAddress @ 1c0006f3c =====

void lbfoLBRevertMacAddress(longlong *param_1,longlong *param_2,undefined4 *param_3)

{
  longlong lVar1;
  
  if (param_1 != param_2) {
    do {
      lVar1 = NdisGetDataBuffer(param_1,0xe,0,1,0);
      *(undefined4 *)(lVar1 + 6) = *param_3;
      *(undefined2 *)(lVar1 + 10) = *(undefined2 *)(param_3 + 1);
      param_1 = (longlong *)*param_1;
    } while (param_1 != param_2);
  }
  return;
}



===== lbfoLBUpdateCfgMacVmsPorts @ 1c0006fa8 =====

void lbfoLBUpdateCfgMacVmsPorts(longlong param_1,longlong param_2,ushort param_3)

{
  undefined8 *puVar1;
  longlong lVar2;
  undefined8 *puVar3;
  undefined1 uVar4;
  
  for (puVar1 = *(undefined8 **)(param_1 + 0x40); puVar1 != (undefined8 *)(param_1 + 0x40);
      puVar1 = (undefined8 *)*puVar1) {
    lVar2 = *(longlong *)(param_1 + 0x28);
    puVar1[6] = lVar2;
    if (*(uint *)(puVar1 + 2) < (uint)param_3) {
      if (lVar2 == 0) {
        uVar4 = 0;
      }
      else {
        uVar4 = *(undefined1 *)(lVar2 + 0x288);
      }
      *(undefined1 *)((ulonglong)*(uint *)(puVar1 + 2) + param_2) = uVar4;
    }
    for (puVar3 = (undefined8 *)puVar1[3]; puVar3 != puVar1 + 3; puVar3 = (undefined8 *)*puVar3) {
      puVar3[-1] = puVar1[6];
    }
  }
  return;
}



===== lbfoSTGetAggregatorForNic @ 1c0007030 =====

longlong * lbfoSTGetAggregatorForNic(longlong param_1)

{
  longlong *plVar1;
  
  plVar1 = *(longlong **)(param_1 + 0x8c8);
  if (plVar1 == (longlong *)(param_1 + 0x8c8)) {
    plVar1 = lbfoCreateAggregator(param_1);
  }
  return plVar1;
}



===== lbfoSIAddNic @ 1c0007060 =====

undefined8 lbfoSIAddNic(longlong param_1,longlong param_2)

{
  byte bVar1;
  char cVar2;
  undefined4 uVar3;
  longlong lVar4;
  
  uVar3 = 0;
  lVar4 = 0;
  *(undefined4 *)(param_2 + 0x300) = 0;
  bVar1 = *(byte *)(param_1 + 0x942);
  if ((bVar1 & 1) == 0) {
    if ((bVar1 & 2) == 0) {
      lVar4 = -300000000;
      *(byte *)(param_1 + 0x942) = bVar1 | 2;
      uVar3 = 1000;
    }
    if (*(short *)(param_1 + 0x940) == *(short *)(param_1 + 0x8ea)) {
      lVar4 = -30000000;
      uVar3 = 500;
    }
    else if (lVar4 == 0) {
      return 0;
    }
    cVar2 = NdisSetCoalescableTimerObject(*(undefined8 *)(param_1 + 0x938),lVar4,0,param_1,uVar3);
    if (cVar2 == '\0') {
      *(short *)(param_1 + 0x920) = *(short *)(param_1 + 0x920) + 1;
    }
  }
  return 0;
}



===== lbfoSIConnectDesiredNumNics @ 1c00070f4 =====

void lbfoSIConnectDesiredNumNics
               (longlong param_1,undefined8 param_2,undefined *param_3,longlong param_4)

{
  int iVar1;
  undefined8 *puVar2;
  bool bVar3;
  char cVar4;
  byte bVar5;
  ushort uVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  undefined8 uVar9;
  longlong lVar10;
  
  puVar8 = (undefined8 *)0x0;
  bVar3 = true;
  for (puVar2 = *(undefined8 **)(param_1 + 0x8c8); puVar2 != (undefined8 *)(param_1 + 0x8c8);
      puVar2 = (undefined8 *)*puVar2) {
    for (puVar7 = (undefined8 *)puVar2[3]; puVar7 != puVar2 + 3; puVar7 = (undefined8 *)*puVar7) {
      if (*(int *)(puVar7 + 0x60) == 0) {
        bVar3 = false;
      }
      else if ((*(longlong *)(puVar7[0x53] + 0x928) == puVar7[6]) &&
              (*(longlong *)(puVar7[0x53] + 0x930) == puVar7[7])) {
        puVar8 = puVar7;
      }
      else if (*(int *)(puVar7 + 0x60) != 2) {
        *(undefined4 *)(puVar7 + 0x60) = 2;
        lbfoTMConnectNic(param_1,(longlong)puVar7,param_3,param_4);
      }
    }
  }
  bVar5 = *(byte *)(param_1 + 0x942);
  if ((((bVar5 & 1) == 0) && (*(short *)(param_1 + 0x940) == *(short *)(param_1 + 0x8ea))) &&
     (bVar3)) {
    bVar5 = bVar5 | 1;
    *(byte *)(param_1 + 0x942) = bVar5;
  }
  if (((bVar5 & 1) != 0) &&
     (cVar4 = NdisCancelTimerObject(*(undefined8 *)(param_1 + 0x938)), cVar4 != '\0')) {
    *(short *)(param_1 + 0x920) = *(short *)(param_1 + 0x920) + -1;
  }
  if (puVar8 != (undefined8 *)0x0) {
    uVar6 = *(ushort *)(param_1 + 0x8ec) - 1;
    if (*(int *)(puVar8 + 0x54) != 0) {
      uVar6 = *(ushort *)(param_1 + 0x8ec);
    }
    if (((*(byte *)(param_1 + 0x942) & 1) == 0) ||
       (((uint)*(ushort *)(param_1 + 0x940) <= uVar6 + 1 && (uVar6 != 0)))) {
      lVar10 = 0;
      uVar9 = 0;
      lbfoSetNicFailureReason((longlong)puVar8,1,(undefined *)0x0,0);
      iVar1 = *(int *)(puVar8 + 0x60);
      *(undefined4 *)(puVar8 + 0x60) = 3;
      if (iVar1 == 2) {
        lbfoTMDisconnectNic(param_1,(longlong)puVar8,uVar9,lVar10);
      }
    }
    else if (*(int *)(puVar8 + 0x60) != 2) {
      *(undefined4 *)(puVar8 + 0x60) = 2;
      lbfoTMConnectNic(param_1,(longlong)puVar8,param_3,param_4);
    }
  }
  return;
}



===== lbfoSIConnectNic @ 1c00072b0 =====

void lbfoSIConnectNic(longlong param_1,longlong param_2,undefined *param_3,longlong param_4)

{
  *(byte *)(param_1 + 0x922) = *(byte *)(param_1 + 0x922) | 2;
  *(undefined4 *)(param_2 + 0x300) = 1;
  lbfoSIConnectDesiredNumNics(param_1,param_2,param_3,param_4);
  lbfoTMEndBatchUpdate(param_1);
  return;
}



===== lbfoSIDisconnectNic @ 1c00072f0 =====

void lbfoSIDisconnectNic(longlong param_1,longlong param_2,undefined *param_3,longlong param_4)

{
  int iVar1;
  
  *(byte *)(param_1 + 0x922) = *(byte *)(param_1 + 0x922) | 2;
  iVar1 = *(int *)(param_2 + 0x300);
  *(undefined4 *)(param_2 + 0x300) = 0;
  if (iVar1 == 2) {
    lbfoTMDisconnectNic(param_1,param_2,param_3,param_4);
  }
  lbfoSIConnectDesiredNumNics(param_1,param_2,param_3,param_4);
  lbfoTMEndBatchUpdate(param_1);
  return;
}



===== lbfoSIStabilizationTimer @ 1c0007340 =====

void lbfoSIStabilizationTimer
               (undefined8 param_1,longlong param_2,undefined8 param_3,longlong param_4)

{
  undefined2 *puVar1;
  undefined1 uVar2;
  undefined7 uVar3;
  undefined2 local_res10;
  undefined1 local_res12;
  
  uVar3 = (undefined7)((ulonglong)param_3 >> 8);
  uVar2 = 1;
  local_res10 = 0;
  puVar1 = &local_res10;
  local_res12 = 0;
  NdisAcquireRWLockWrite(*(undefined8 *)(param_2 + 0x5e8));
  *(byte *)(param_2 + 0x942) = *(byte *)(param_2 + 0x942) | 1;
  lbfoSIConnectDesiredNumNics(param_2,puVar1,(undefined *)CONCAT71(uVar3,uVar2),param_4);
  *(short *)(param_2 + 0x920) = *(short *)(param_2 + 0x920) + -1;
  NdisReleaseRWLock(*(undefined8 *)(param_2 + 0x5e8),&local_res10);
  return;
}



===== McTemplateK0jdd_EtwWriteTransfer @ 1c00073b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0jdd_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined1 auStackY_88 [32];
  undefined8 local_58 [2];
  undefined8 local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  local_38 = &param_5;
  local_28 = &param_6;
  local_40 = 0x10;
  local_30 = 4;
  local_20 = 4;
  local_48 = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,0,4,local_58);
  return;
}



===== McTemplateK0jddd_EtwWriteTransfer @ 1c0007424 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0jddd_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined1 auStackY_98 [32];
  undefined8 local_68 [2];
  undefined8 local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  local_48 = &param_5;
  local_38 = &param_6;
  local_50 = 0x10;
  local_28 = &param_7;
  local_40 = 4;
  local_30 = 4;
  local_20 = 4;
  local_58 = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&LACPChurnDetectionInfo,0,5,local_68);
  return;
}



===== McTemplateK0jppt_EtwWriteTransfer @ 1c00074b8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0jppt_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined1 auStackY_98 [32];
  undefined8 local_68 [2];
  undefined8 local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  local_48 = &param_5;
  local_38 = &param_6;
  local_50 = 0x10;
  local_28 = &param_7;
  local_40 = 8;
  local_30 = 8;
  local_20 = 4;
  local_58 = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,0,5,local_68);
  return;
}



===== McTemplateK0jqbr1_EtwWriteTransfer @ 1c0007544 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0jqbr1_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6)

{
  undefined1 auStackY_98 [32];
  undefined4 local_68 [4];
  undefined8 local_58 [2];
  undefined8 local_48;
  undefined8 local_40;
  undefined4 *local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  local_38 = local_68;
  local_68[0] = 0x7c;
  local_28 = param_6;
  local_20 = 0x7c;
  local_40 = 0x10;
  local_30 = 4;
  local_48 = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,0,4,local_58);
  return;
}



===== WPP_SF_qddd @ 1c00075c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qddd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,param_3,param_2,&local_res20,8,&param_5,4,&param_6,4,&param_7,4,0);
  return;
}



===== lbfoLACPAddNic @ 1c0007630 =====

int lbfoLACPAddNic(undefined *param_1,longlong *param_2)

{
  byte bVar1;
  undefined8 uVar2;
  code *pcVar3;
  int iVar4;
  longlong *plVar5;
  undefined *puVar6;
  longlong *plVar7;
  undefined1 *puVar8;
  longlong *plVar9;
  undefined1 auStack_78 [8];
  undefined1 auStack_70 [24];
  undefined4 local_58;
  longlong local_48 [3];
  code *pcStack_30;
  longlong *local_28;
  
  local_48[1] = 0x10;
  local_28 = (longlong *)0x0;
  local_48[0] = 1;
  local_58 = 1;
  puVar6 = (undefined *)0x40;
  plVar9 = local_48;
  local_48[2] = 0;
  pcStack_30 = (code *)0x0;
  plVar5 = (longlong *)ExAllocatePool3(0x40,0xd8);
  puVar8 = auStack_78;
  if (plVar5 == (longlong *)0x0) {
    iVar4 = -0x3fffff66;
  }
  else {
    param_2[0x60] = (longlong)plVar5;
    plVar5[2] = (longlong)param_2;
    plVar5[3] = (longlong)param_1;
    puVar6 = param_1 + 0x930;
    plVar7 = *(longlong **)(param_1 + 0x938);
    puVar8 = auStack_78;
    if ((undefined *)*plVar7 != puVar6) {
      plVar7 = (longlong *)0x3;
      pcVar3 = (code *)swi(0x29);
      puVar6 = (undefined *)(*pcVar3)();
      puVar8 = auStack_70;
    }
    plVar5[1] = (longlong)plVar7;
    *plVar5 = (longlong)puVar6;
    *plVar7 = (longlong)plVar5;
    *(longlong **)(puVar6 + 8) = plVar5;
    *(undefined4 *)(plVar5 + 5) = 6;
    *(undefined4 *)((longlong)plVar5 + 0x2c) = 4;
    *(undefined4 *)(plVar5 + 6) = 5;
    *(undefined4 *)((longlong)plVar5 + 0x34) = 3;
    *(undefined4 *)(plVar5 + 7) = 3;
    *(undefined4 *)(plVar5 + 0x14) = 3;
    *(undefined *)((longlong)plVar5 + 0x89) = param_1[0x928];
    *(undefined4 *)((longlong)plVar5 + 0x7d) = *(undefined4 *)(param_1 + 0x96);
    *(undefined2 *)((longlong)plVar5 + 0x81) = *(undefined2 *)(param_1 + 0x9a);
    *(ushort *)((longlong)plVar5 + 0x87) = (ushort)*(byte *)(param_2 + 0x51);
    *(undefined4 *)((longlong)plVar5 + 0x8a) = 0;
    *(undefined8 *)((longlong)plVar5 + 0x8e) = 0;
    *(undefined4 *)((longlong)plVar5 + 0x96) = 0;
    *(undefined1 *)((longlong)plVar5 + 0x9a) = 0xf8;
    bVar1 = *(byte *)((longlong)plVar5 + 0x9a);
    *(byte *)((longlong)plVar5 + 0x9a) = (bVar1 * '\x02' ^ bVar1) & 0x10 ^ bVar1;
    local_48[2] = 0x5463694e00180197;
    pcStack_30 = lbfoLACPTimerCurrentWhile;
    *(undefined8 *)(puVar8 + -8) = 0x1c00077a6;
    puVar6 = DAT_1c0018468;
    local_28 = plVar5;
    iVar4 = NdisAllocateTimerObject(DAT_1c0018468,local_48 + 2);
    if (iVar4 == 0) {
      pcStack_30 = lbfoLACPTimerPeriodic;
      *(undefined8 *)(puVar8 + -8) = 0x1c00077d6;
      puVar6 = DAT_1c0018468;
      iVar4 = NdisAllocateTimerObject(DAT_1c0018468,local_48 + 2);
      if (iVar4 == 0) {
        pcStack_30 = lbfoLACPTimerWaitWhile;
        *(undefined8 *)(puVar8 + -8) = 0x1c0007806;
        puVar6 = DAT_1c0018468;
        iVar4 = NdisAllocateTimerObject(DAT_1c0018468,local_48 + 2);
        if (iVar4 == 0) {
          pcStack_30 = lbfoLACPTimerActorChurn;
          *(undefined8 *)(puVar8 + -8) = 0x1c0007836;
          puVar6 = DAT_1c0018468;
          iVar4 = NdisAllocateTimerObject(DAT_1c0018468,local_48 + 2);
          if (iVar4 == 0) {
            plVar7 = plVar5 + 0xc;
            pcStack_30 = lbfoLACPTimerPartnerChurn;
            *(undefined8 *)(puVar8 + -8) = 0x1c0007866;
            puVar6 = DAT_1c0018468;
            iVar4 = NdisAllocateTimerObject(DAT_1c0018468,local_48 + 2);
            if (iVar4 == 0) {
              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 (3 < (byte)WPP_GLOBAL_Control[0x29])) {
                uVar2 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
                plVar7 = (longlong *)&WPP_4ef88d54200138cb1a5bbf4ec4cd4989_Traceguids;
                *(undefined8 *)(puVar8 + -8) = 0x1c00078a4;
                plVar9 = param_2;
                WPP_SF_q(uVar2,10,&WPP_4ef88d54200138cb1a5bbf4ec4cd4989_Traceguids,param_2);
              }
              *(undefined2 *)((longlong)plVar5 + 0x9c) = 0x101;
              *(undefined1 *)((longlong)plVar5 + 0x9b) = 0;
              plVar5[4] = param_2[4];
              *(undefined8 *)(puVar8 + -8) = 0x1c00078c7;
              lbfoLACPUpdateOwningAggregatorData((longlong)param_1,(longlong)param_2);
              *(undefined8 *)(puVar8 + -8) = 0x1c00078d2;
              puVar6 = param_1;
              lbfoLACPReceiveMachine(param_1,param_2);
              *(undefined8 *)(puVar8 + -8) = 0x1c00078da;
              lbfoLACPPeriodicTransmissionMachine(puVar6,(longlong)param_2);
              *(undefined8 *)(puVar8 + -8) = 0x1c00078e5;
              lbfoLACPSelectionLogic(param_1,param_2,plVar7,plVar9);
              *(undefined8 *)(puVar8 + -8) = 0x1c00078f0;
              puVar6 = param_1;
              lbfoLACPMuxMachine(param_1,param_2,plVar7,plVar9);
              *(undefined8 *)(puVar8 + -8) = 0x1c00078f8;
              lbfoLACPTransmitMachine(puVar6,(longlong)param_2);
              *(undefined8 *)(puVar8 + -8) = 0x1c0007905;
              lbfoLACPChurnDetectionMachine((ulonglong)param_2,1);
              *(undefined8 *)(puVar8 + -8) = 0x1c000790f;
              lbfoLACPChurnDetectionMachine((ulonglong)param_2,0);
              *(undefined1 *)((longlong)plVar5 + 0x9c) = 0;
              *(undefined8 *)(puVar8 + -8) = 0x1c0007921;
              puVar6 = param_1;
              lbfoLACPReceiveMachine(param_1,param_2);
              *(undefined8 *)(puVar8 + -8) = 0x1c0007929;
              lbfoLACPPeriodicTransmissionMachine(puVar6,(longlong)param_2);
              *(undefined8 *)(puVar8 + -8) = 0x1c0007934;
              lbfoLACPSelectionLogic(param_1,param_2,plVar7,plVar9);
              *(undefined8 *)(puVar8 + -8) = 0x1c000793f;
              puVar6 = param_1;
              lbfoLACPMuxMachine(param_1,param_2,plVar7,plVar9);
              *(undefined8 *)(puVar8 + -8) = 0x1c0007947;
              lbfoLACPTransmitMachine(puVar6,(longlong)param_2);
              *(undefined8 *)(puVar8 + -8) = 0x1c0007954;
              lbfoLACPChurnDetectionMachine((ulonglong)param_2,1);
              *(undefined8 *)(puVar8 + -8) = 0x1c000795e;
              lbfoLACPChurnDetectionMachine((ulonglong)param_2,0);
              puVar6 = WPP_GLOBAL_Control;
              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 (3 < (byte)WPP_GLOBAL_Control[0x29])) {
                puVar6 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
                *(undefined8 *)(puVar8 + -8) = 0x1c0007988;
                plVar9 = param_2;
                WPP_SF_q(puVar6,0xb,&WPP_4ef88d54200138cb1a5bbf4ec4cd4989_Traceguids,param_2);
              }
            }
          }
        }
      }
    }
  }
  if ((Microsoft_Windows_MsLbfoEventProviderEnableBits & 1) != 0) {
    plVar9 = param_2 + 6;
    *(int *)(puVar8 + 0x20) = iVar4;
    *(undefined8 *)(puVar8 + -8) = 0x1c00079a8;
    McTemplateK0jd_EtwWriteTransfer(puVar6,&LacpInitingInfo,0,plVar9,puVar8[0x20]);
  }
  if (iVar4 != 0) {
    *(undefined8 *)(puVar8 + -8) = 0x1c00079ba;
    lbfoLACPRemoveNic(param_1,param_2,(longlong *)0x0,plVar9);
  }
  return iVar4;
}



===== lbfoLACPChangeAggregator @ 1c00079e4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void lbfoLACPChangeAggregator(longlong *param_1,longlong param_2,undefined8 param_3)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  longlong *plVar4;
  code *pcVar5;
  
  lVar1 = param_1[4];
  lVar2 = *(longlong *)(lVar1 + 0x10);
  if (lVar1 == param_2) {
    return;
  }
  if ((Microsoft_Windows_MsLbfoEventProviderEnableBits & 1) != 0) {
    McTemplateK0jpp_EtwWriteTransfer(param_1,param_2,param_3,param_1 + 6,(char)lVar1,(char)param_2);
  }
  param_1[4] = param_2;
  lVar3 = *param_1;
  if ((*(longlong **)(lVar3 + 8) == param_1) &&
     (plVar4 = (longlong *)param_1[1], (longlong *)*plVar4 == param_1)) {
    *plVar4 = lVar3;
    *(longlong **)(lVar3 + 8) = plVar4;
    plVar4 = *(longlong **)(param_2 + 0x20);
    if (*plVar4 == param_2 + 0x18) {
      *param_1 = param_2 + 0x18;
      param_1[1] = (longlong)plVar4;
      *plVar4 = (longlong)param_1;
      *(longlong **)(param_2 + 0x20) = param_1;
      *(short *)(param_2 + 0x28) = *(short *)(param_2 + 0x28) + 1;
      *(short *)(lVar1 + 0x28) = *(short *)(lVar1 + 0x28) + -1;
      if ((int)param_1[0x54] == 0) {
        *(short *)(lVar1 + 0x2a) = *(short *)(lVar1 + 0x2a) + -1;
        *(short *)(param_2 + 0x2a) = *(short *)(param_2 + 0x2a) + 1;
      }
      if ((code *)(&PTR_lbfoNTHChangeNicAggregator_1c00180f0)
                  [(longlong)*(int *)(lVar2 + 0x5a4) * 0xf] == (code *)0x0) {
        return;
      }
      (*(code *)(&PTR_lbfoNTHChangeNicAggregator_1c00180f0)[(longlong)*(int *)(lVar2 + 0x5a4) * 0xf]
      )(lVar2,param_1,lVar1,param_2);
      return;
    }
  }
  pcVar5 = (code *)swi(0x29);
  (*pcVar5)(3);
  pcVar5 = (code *)swi(3);
  (*pcVar5)();
  return;
}



===== lbfoLACPChangeByteOrder @ 1c0007ad8 =====

ulonglong lbfoLACPChangeByteOrder(longlong param_1)

{
  ushort uVar1;
  ulonglong in_RAX;
  
  if ((((*(char *)(param_1 + 0x10) == '\x01') && (*(char *)(param_1 + 0x11) == '\x14')) &&
      (*(char *)(param_1 + 0x24) == '\x02')) &&
     (((*(char *)(param_1 + 0x25) == '\x14' && (*(char *)(param_1 + 0x38) == '\x03')) &&
      (*(char *)(param_1 + 0x39) == '\x10')))) {
    *(ushort *)(param_1 + 0x12) =
         *(ushort *)(param_1 + 0x12) >> 8 | *(ushort *)(param_1 + 0x12) << 8;
    *(ushort *)(param_1 + 0x1a) =
         *(ushort *)(param_1 + 0x1a) >> 8 | *(ushort *)(param_1 + 0x1a) << 8;
    *(ushort *)(param_1 + 0x1c) =
         *(ushort *)(param_1 + 0x1c) >> 8 | *(ushort *)(param_1 + 0x1c) << 8;
    *(ushort *)(param_1 + 0x1e) =
         *(ushort *)(param_1 + 0x1e) >> 8 | *(ushort *)(param_1 + 0x1e) << 8;
    uVar1 = *(ushort *)(param_1 + 0x26);
    *(ushort *)(param_1 + 0x26) = uVar1 >> 8 | uVar1 << 8;
    *(ushort *)(param_1 + 0x2e) =
         *(ushort *)(param_1 + 0x2e) >> 8 | *(ushort *)(param_1 + 0x2e) << 8;
    *(ushort *)(param_1 + 0x30) =
         *(ushort *)(param_1 + 0x30) >> 8 | *(ushort *)(param_1 + 0x30) << 8;
    *(ushort *)(param_1 + 0x32) =
         *(ushort *)(param_1 + 0x32) >> 8 | *(ushort *)(param_1 + 0x32) << 8;
    *(ushort *)(param_1 + 0x3a) =
         *(ushort *)(param_1 + 0x3a) >> 8 | *(ushort *)(param_1 + 0x3a) << 8;
    return CONCAT71((uint7)(byte)uVar1,1);
  }
  return in_RAX & 0xffffffffffffff00;
}



===== lbfoLACPChurnDetectionMachine @ 1c0007b88 =====

void lbfoLACPChurnDetectionMachine(ulonglong param_1,int param_2)

{
  longlong lVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined2 uVar4;
  byte bVar5;
  undefined8 uVar6;
  longlong lVar7;
  longlong lVar8;
  undefined1 uVar9;
  uint uVar10;
  
  lVar1 = *(longlong *)(param_1 + 0x300);
  if (param_2 == 0) {
    uVar6 = *(undefined8 *)(lVar1 + 0x60);
    lVar7 = 0x38;
    bVar5 = *(byte *)(lVar1 + 0x9a);
    lVar8 = 0x6b;
  }
  else {
    uVar6 = *(undefined8 *)(lVar1 + 0x58);
    lVar7 = 0x34;
    bVar5 = *(byte *)(lVar1 + 0x89);
    lVar8 = 0x6a;
  }
  bVar5 = bVar5 >> 3 & 1;
  uVar9 = (undefined1)param_2;
  uVar3 = param_1;
  if ((*(char *)(lVar1 + 0x9c) == '\0') && (*(char *)(lVar1 + 0x9b) != '\0')) {
    uVar10 = *(uint *)(lVar1 + lVar7);
    if (uVar10 == 0) {
      uVar3 = 0;
      if (bVar5 != 0) {
LAB_1c0007c37:
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return;
        }
        if ((byte)WPP_GLOBAL_Control[0x29] < 4) {
          return;
        }
        uVar4 = 0x23;
        goto LAB_1c0007c62;
      }
      goto LAB_1c0007c7e;
    }
    uVar2 = uVar10 - 1;
    uVar3 = (ulonglong)uVar2;
    if (uVar2 == 0) {
      if (bVar5 != 0) goto LAB_1c0007c1c;
      if (*(char *)(lVar1 + lVar8) == '\0') goto LAB_1c0007c37;
      uVar2 = 2;
    }
    else {
      if ((uVar2 != 1) || (bVar5 == 0)) goto LAB_1c0007c37;
LAB_1c0007c1c:
      uVar2 = 0;
    }
  }
  else {
LAB_1c0007c7e:
    uVar2 = 1;
  }
  uVar10 = *(uint *)(lVar1 + lVar7);
  if (uVar2 != uVar10) {
    if ((Microsoft_Windows_MsLbfoEventProviderEnableBits & 1) != 0) {
      McTemplateK0jddd_EtwWriteTransfer
                (uVar3,1,(ulonglong)uVar10,param_1 + 0x30,uVar9,(char)uVar10,(char)uVar2);
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_qddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x25,
                  &WPP_4ef88d54200138cb1a5bbf4ec4cd4989_Traceguids,param_1,uVar9,
                  (char)*(undefined4 *)(lVar1 + lVar7),(char)uVar2);
    }
    *(uint *)(lVar1 + lVar7) = uVar2;
    if (uVar2 == 1) {
      *(undefined1 *)(lVar1 + lVar8) = 0;
      NdisSetTimerObject(uVar6,0xffffffffdc3cba00,0,0);
      return;
    }
    if (uVar2 == 2) {
      SysEventWriteGuid(0x80004233,param_1 + 0x40);
      return;
    }
    return;
  }
  if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
    return;
  }
  if ((byte)WPP_GLOBAL_Control[0x29] < 4) {
    return;
  }
  uVar4 = 0x24;
LAB_1c0007c62:
  WPP_SF_qdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,
             &WPP_4ef88d54200138cb1a5bbf4ec4cd4989_Traceguids,param_1,uVar9,(char)uVar10);
  return;
}



===== lbfoLACPConnectNic @ 1c0007d80 =====

void lbfoLACPConnectNic(undefined *param_1,longlong *param_2,longlong *param_3,longlong *param_4)

{
  longlong lVar1;
  undefined *puVar2;
  
  lVar1 = param_2[0x60];
  if (*(char *)(lVar1 + 0xd2) == '\0') {
    param_3 = (longlong *)0x0;
    param_4 = (longlong *)CONCAT71((int7)((ulonglong)param_4 >> 8),1);
    lbfoSetNicFailureReason((longlong)param_2,5,(undefined *)0x0,(longlong)param_4);
  }
  else {
    lbfoTMConnectNic((longlong)param_1,(longlong)param_2,(undefined *)param_3,(longlong)param_4);
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_3 = (longlong *)&WPP_4ef88d54200138cb1a5bbf4ec4cd4989_Traceguids;
    param_4 = param_2;
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
             &WPP_4ef88d54200138cb1a5bbf4ec4cd4989_Traceguids,param_2);
  }
  *(undefined1 *)(lVar1 + 0x9b) = 1;
  puVar2 = param_1;
  lbfoLACPReceiveMachine(param_1,param_2);
  lbfoLACPPeriodicTransmissionMachine(puVar2,(longlong)param_2);
  lbfoLACPSelectionLogic(param_1,param_2,param_3,param_4);
  lbfoLACPMuxMachine(param_1,param_2,param_3,param_4);
  lbfoLACPTransmitMachine(param_1,(longlong)param_2);
  lbfoLACPChurnDetectionMachine((ulonglong)param_2,1);
  lbfoLACPChurnDetectionMachine((ulonglong)param_2,0);
  return;
}



===== lbfoLACPDisconnectNic @ 1c0007e60 =====

void lbfoLACPDisconnectNic(undefined *param_1,longlong *param_2,longlong *param_3,longlong *param_4)

{
  char cVar1;
  longlong lVar2;
  undefined *puVar3;
  
  lVar2 = param_2[0x60];
  cVar1 = *(char *)(lVar2 + 0xd2);
  *(undefined1 *)(lVar2 + 0xd2) = 0;
  if (cVar1 != '\0') {
    lbfoTMDisconnectNic((longlong)param_1,(longlong)param_2,param_3,(longlong)param_4);
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_3 = (longlong *)&WPP_4ef88d54200138cb1a5bbf4ec4cd4989_Traceguids;
    param_4 = param_2;
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
             &WPP_4ef88d54200138cb1a5bbf4ec4cd4989_Traceguids,param_2);
  }
  *(undefined1 *)(lVar2 + 0x9b) = 0;
  puVar3 = param_1;
  lbfoLACPReceiveMachine(param_1,param_2);
  lbfoLACPPeriodicTransmissionMachine(puVar3,(longlong)param_2);
  lbfoLACPSelectionLogic(param_1,param_2,param_3,param_4);
  lbfoLACPMuxMachine(param_1,param_2,param_3,param_4);
  lbfoLACPTransmitMachine(param_1,(longlong)param_2);
  lbfoLACPChurnDetectionMachine((ulonglong)param_2,1);
  lbfoLACPChurnDetectionMachine((ulonglong)param_2,0);
  return;
}



===== lbfoLACPMuxMachine @ 1c0007f2c =====

void lbfoLACPMuxMachine(undefined *param_1,longlong *param_2,undefined8 param_3,longlong *param_4)

{
  longlong lVar1;
  undefined *puVar2;
  undefined2 uVar3;
  uint uVar4;
  uint uVar5;
  undefined *puVar6;
  longlong lVar7;
  bool bVar8;
  
  lVar1 = param_2[0x60];
  puVar2 = param_1;
  if (*(char *)(lVar1 + 0x9c) == '\0') {
    uVar5 = *(uint *)(lVar1 + 0x30);
    if (uVar5 == 0) {
      if ((*(uint *)(lVar1 + 0xa0) & 0xfffffffd) == 0) {
        uVar4 = 1;
        puVar2 = (undefined *)0x0;
        goto LAB_1c000807e;
      }
    }
    else if (uVar5 == 1) {
      puVar2 = (undefined *)0x0;
      if (*(int *)(lVar1 + 0xa0) == 1) goto LAB_1c0007f5a;
      if ((*(int *)(lVar1 + 0xa0) == 0) &&
         (puVar2 = (undefined *)0x0, *(char *)(lVar1 + 0x9e) != '\0')) {
LAB_1c0007fd9:
        uVar4 = 2;
        goto LAB_1c000807e;
      }
    }
    else if (uVar5 == 2) {
      uVar4 = *(uint *)(lVar1 + 0xa0);
      puVar2 = (undefined *)(ulonglong)uVar4;
      if (uVar4 - 1 < 2) goto LAB_1c0007f5a;
      if (uVar4 == 0) {
        bVar8 = (*(byte *)(lVar1 + 0x9a) & 8) == 0;
LAB_1c0007fa3:
        if (!bVar8) goto LAB_1c0007fa5;
      }
    }
    else if (uVar5 == 3) {
      uVar4 = *(uint *)(lVar1 + 0xa0);
      puVar2 = (undefined *)(ulonglong)uVar4;
      if ((uVar4 - 1 < 2) || ((*(byte *)(lVar1 + 0x9a) & 8) == 0)) goto LAB_1c0007fd9;
      if ((uVar4 == 0) && ((*(byte *)(lVar1 + 0x9a) & 0x18) == 0x18)) {
        uVar4 = 4;
        goto LAB_1c000807e;
      }
    }
    else if (uVar5 == 4) {
      puVar2 = (undefined *)0x1;
      if (1 < *(int *)(lVar1 + 0xa0) - 1U) {
        bVar8 = (*(byte *)(lVar1 + 0x9a) & 0x18) == 0x18;
        goto LAB_1c0007fa3;
      }
LAB_1c0007fa5:
      uVar4 = 3;
      goto LAB_1c000807e;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 4) {
      return;
    }
    uVar3 = 0x1e;
LAB_1c000803b:
    WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar3,
              &WPP_4ef88d54200138cb1a5bbf4ec4cd4989_Traceguids,param_2,(char)uVar5);
    return;
  }
LAB_1c0007f5a:
  uVar4 = 0;
LAB_1c000807e:
  uVar5 = *(uint *)(lVar1 + 0x30);
  puVar6 = (undefined *)(ulonglong)uVar5;
  if (uVar4 == uVar5) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 4) {
      return;
    }
    uVar3 = 0x1f;
    goto LAB_1c000803b;
  }
  if ((Microsoft_Windows_MsLbfoEventProviderEnableBits & 1) != 0) {
    param_4 = param_2 + 6;
    McTemplateK0jdd_EtwWriteTransfer
              (puVar2,&LACPMuxMcTransitionInfo,puVar6,param_4,(char)uVar5,(char)uVar4);
  }
  puVar2 = WPP_GLOBAL_Control;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    puVar6 = &WPP_4ef88d54200138cb1a5bbf4ec4cd4989_Traceguids;
    puVar2 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
    param_4 = param_2;
    WPP_SF_qdd(puVar2,0x20,&WPP_4ef88d54200138cb1a5bbf4ec4cd4989_Traceguids,param_2,
               (char)*(undefined4 *)(lVar1 + 0x30),(char)uVar4);
  }
  *(uint *)(lVar1 + 0x30) = uVar4;
  if (uVar4 == 0) {
    lbfoLACPChangeAggregator(param_2,*(longlong *)(param_2[0x60] + 0x20),puVar6);
    *(byte *)(lVar1 + 0x89) = *(byte *)(lVar1 + 0x89) & 0xf7;
    if (*(char *)(lVar1 + 0xd2) != '\0') {
      lVar7 = 0;
      *(undefined1 *)(lVar1 + 0xd2) = 0;
      puVar2 = (undefined *)CONCAT71((int7)((ulonglong)puVar6 >> 8),1);
      lbfoSetNicFailureReason((longlong)param_2,5,puVar2,0);
      lbfoTMDisconnectNic((longlong)param_1,(longlong)param_2,puVar2,lVar7);
    }
    *(byte *)(lVar1 + 0x89) = *(byte *)(lVar1 + 0x89) & 0xcf;
    *(undefined1 *)(lVar1 + 0x9f) = 0;
  }
  else {
    if (uVar4 == 1) {
      puVar2 = *(undefined **)(lVar1 + 0x48);
      NdisSetTimerObject(puVar2,0xfffffffffeced300,0,0);
      goto LAB_1c000825e;
    }
    if (uVar4 != 2) {
      if (uVar4 == 3) {
        *(byte *)(lVar1 + 0x89) = *(byte *)(lVar1 + 0x89) | 0x10;
        *(undefined1 *)(lVar1 + 0xd1) = 1;
        if (*(char *)(lVar1 + 0xd2) != '\0') {
          lVar7 = 0;
          *(undefined1 *)(lVar1 + 0xd2) = 0;
          puVar2 = (undefined *)CONCAT71((int7)((ulonglong)puVar6 >> 8),1);
          lbfoSetNicFailureReason((longlong)param_2,5,puVar2,0);
          lbfoTMDisconnectNic((longlong)param_1,(longlong)param_2,puVar2,lVar7);
          puVar2 = param_1;
        }
        *(byte *)(lVar1 + 0x89) = *(byte *)(lVar1 + 0x89) & 0xdf;
        *(undefined1 *)(lVar1 + 0x78) = 1;
      }
      else if (uVar4 == 4) {
        if (*(char *)(lVar1 + 0xd2) == '\0') {
          *(undefined1 *)(lVar1 + 0xd2) = 1;
          lbfoTMConnectNic((longlong)param_1,(longlong)param_2,puVar6,(longlong)param_4);
          puVar2 = param_1;
        }
        *(byte *)(lVar1 + 0x89) = *(byte *)(lVar1 + 0x89) | 0x20;
      }
      goto LAB_1c000825e;
    }
    if (*(longlong *)(param_2[0x60] + 0x70) != 0) {
      lbfoLACPChangeAggregator(param_2,*(longlong *)(param_2[0x60] + 0x70),puVar6);
    }
    *(byte *)(lVar1 + 0x89) = *(byte *)(lVar1 + 0x89) & 0xef | 8;
  }
  *(undefined1 *)(lVar1 + 0xd1) = 0;
  *(undefined1 *)(lVar1 + 0x78) = 1;
  lbfoLACPUpdateOwningAggregatorData((longlong)param_1,(longlong)param_2);
  puVar2 = param_1;
LAB_1c000825e:
  lbfoLACPTransmitMachine(puVar2,(longlong)param_2);
  lbfoLACPChurnDetectionMachine((ulonglong)param_2,1);
  lbfoLACPChurnDetectionMachine((ulonglong)param_2,0);
  return;
}



===== lbfoLACPPeriodicTransmissionMachine @ 1c0008288 =====

void lbfoLACPPeriodicTransmissionMachine(undefined *param_1,longlong param_2)

{
  longlong lVar1;
  byte bVar2;
  uint uVar3;
  undefined2 uVar4;
  undefined8 uVar5;
  uint uVar6;
  
  do {
    lVar1 = *(longlong *)(param_2 + 0x300);
    if ((((*(char *)(lVar1 + 0x9c) == '\0') && (*(char *)(lVar1 + 0x9d) != '\0')) &&
        (*(char *)(lVar1 + 0x9b) != '\0')) &&
       (((*(byte *)(lVar1 + 0x89) & 1) != 0 || ((*(byte *)(lVar1 + 0x9a) & 1) != 0)))) {
      uVar6 = *(uint *)(lVar1 + 0x2c);
      param_1 = (undefined *)(ulonglong)uVar6;
      if (uVar6 == 0) {
LAB_1c000836d:
        uVar6 = 1;
      }
      else if (uVar6 == 1) {
        param_1 = (undefined *)0x0;
        if ((*(byte *)(lVar1 + 0x9a) & 2) != 0) {
          bVar2 = *(byte *)(lVar1 + 0x69);
LAB_1c0008332:
          if (bVar2 != 0) goto LAB_1c0008334;
          goto LAB_1c0008342;
        }
        uVar6 = 2;
      }
      else {
        uVar3 = uVar6 - 2;
        param_1 = (undefined *)(ulonglong)uVar3;
        if (uVar3 == 0) {
          if (*(char *)(lVar1 + 0x69) == '\0') {
            bVar2 = *(byte *)(lVar1 + 0x9a) & 2;
            goto LAB_1c0008332;
          }
LAB_1c0008334:
          *(undefined1 *)(lVar1 + 0x69) = 0;
          uVar6 = 3;
        }
        else {
          if (uVar3 != 1) goto LAB_1c0008342;
          if ((*(byte *)(lVar1 + 0x9a) & 2) != 0) goto LAB_1c000836d;
          uVar6 = uVar6 - 1;
        }
        if (uVar6 == 4) {
LAB_1c0008342:
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return;
          }
          if ((byte)WPP_GLOBAL_Control[0x29] < 4) {
            return;
          }
          uVar3 = *(uint *)(lVar1 + 0x2c);
          uVar4 = 0x18;
          goto LAB_1c0008457;
        }
      }
    }
    else {
      uVar6 = 0;
    }
    uVar3 = *(uint *)(lVar1 + 0x2c);
    if (uVar6 == uVar3) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar4 = 0x19;
LAB_1c0008457:
        WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,
                  &WPP_4ef88d54200138cb1a5bbf4ec4cd4989_Traceguids,param_2,(char)uVar3);
      }
      return;
    }
    if ((Microsoft_Windows_MsLbfoEventProviderEnableBits & 1) != 0) {
      McTemplateK0jdd_EtwWriteTransfer
                (param_1,&LACPPeriodicTrMcTransitionInfo,(ulonglong)uVar3,param_2 + 0x30,(char)uVar3
                 ,(char)uVar6);
    }
    param_1 = WPP_GLOBAL_Control;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      param_1 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
      WPP_SF_qdd(param_1,0x1a,&WPP_4ef88d54200138cb1a5bbf4ec4cd4989_Traceguids,param_2,
                 (char)*(undefined4 *)(lVar1 + 0x2c),(char)uVar6);
    }
    *(uint *)(lVar1 + 0x2c) = uVar6;
    if (uVar6 == 0) {
      param_1 = *(undefined **)(lVar1 + 0x50);
      NdisCancelTimerObject();
    }
    else {
      if (uVar6 == 1) {
        uVar5 = 0xffffffffff676980;
      }
      else {
        if (uVar6 != 2) {
          if (uVar6 == 3) {
            *(undefined1 *)(lVar1 + 0x78) = 1;
          }
          goto LAB_1c000842e;
        }
        uVar5 = 0xffffffffee1e5d00;
      }
      param_1 = *(undefined **)(lVar1 + 0x50);
      NdisSetTimerObject(param_1,uVar5,0,0);
    }
LAB_1c000842e:
    lbfoLACPTransmitMachine(param_1,param_2);
  } while( true );
}



===== lbfoLACPProcessLacpdu @ 1c0008488 =====

void lbfoLACPProcessLacpdu(undefined *param_1,longlong *param_2,undefined *param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined2 local_res8;
  undefined1 local_resa;
  undefined *in_stack_ffffffffffffffe8;
  
  local_res8 = 0;
  local_resa = 0;
  puVar1 = WPP_GLOBAL_Control;
  puVar2 = param_3;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    puVar1 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
    puVar2 = &WPP_4ef88d54200138cb1a5bbf4ec4cd4989_Traceguids;
    in_stack_ffffffffffffffe8 = param_3;
    WPP_SF_qq(puVar1,0x11,&WPP_4ef88d54200138cb1a5bbf4ec4cd4989_Traceguids,param_2,(char)param_3);
  }
  if ((Microsoft_Windows_MsLbfoEventProviderEnableBits & 1) != 0) {
    McTemplateK0jqbr1_EtwWriteTransfer
              (puVar1,&ReceivedLACPDUInfo,puVar2,param_2 + 6,in_stack_ffffffffffffffe8,param_3);
  }
  NdisAcquireRWLockWrite(*(undefined8 *)(param_1 + 0x5e8),&local_res8,1);
  *(undefined1 *)(param_2[0x60] + 0xa5) = 1;
  *(undefined **)(param_2[0x60] + 0xa8) = param_3;
  lbfoLACPReceiveMachine(param_1,param_2);
  *(undefined1 *)(param_2[0x60] + 0xa5) = 0;
  *(undefined8 *)(param_2[0x60] + 0xa8) = 0;
  NdisReleaseRWLock(*(undefined8 *)(param_1 + 0x5e8),&local_res8);
  return;
}



===== lbfoLACPProcessMarkerRequestPdu @ 1c0008590 =====

void lbfoLACPProcessMarkerRequestPdu(longlong param_1,longlong param_2,longlong param_3)

{
  ushort uVar1;
  uint uVar2;
  longlong lVar3;
  int iVar4;
  longlong *plVar5;
  undefined4 *puVar6;
  undefined2 local_res8;
  undefined1 local_resa;
  ulonglong uVar7;
  
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_res8 = 0;
  local_resa = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
              &WPP_4ef88d54200138cb1a5bbf4ec4cd4989_Traceguids,param_2,(char)param_3);
  }
  plVar5 = (longlong *)NdisAllocateNetBufferList(*(undefined8 *)(param_1 + 0xf0),0,0);
  if (plVar5 != (longlong *)0x0) {
    uVar7 = 0;
    plVar5[0xf] = *(longlong *)(param_1 + 0x18);
    iVar4 = NdisRetreatNetBufferListDataStart(plVar5,0x7c,0,0,0);
    if ((iVar4 == 0) &&
       (puVar6 = (undefined4 *)NdisGetDataBuffer(plVar5[1],0x7c,0,1,uVar7 & 0xffffffff00000000),
       puVar6 != (undefined4 *)0x0)) {
      memset((void *)((longlong)puVar6 + 6),0,0x76);
      *puVar6 = 0xc28001;
      *(undefined2 *)(puVar6 + 1) = 0x200;
      *(undefined4 *)((longlong)puVar6 + 6) = *(undefined4 *)(param_2 + 0x28);
      *(undefined2 *)((longlong)puVar6 + 10) = *(undefined2 *)(param_2 + 0x2c);
      puVar6[3] = 0x1020988;
      *(undefined2 *)(puVar6 + 4) = 0x1002;
      uVar1 = *(ushort *)(param_3 + 0x12);
      *(ushort *)((longlong)puVar6 + 0x12) = uVar1;
      puVar6[5] = *(undefined4 *)(param_3 + 0x14);
      *(undefined2 *)(puVar6 + 6) = *(undefined2 *)(param_3 + 0x18);
      uVar2 = *(uint *)(param_3 + 0x1a);
      *(undefined2 *)(puVar6 + 8) = 0;
      *(uint *)((longlong)puVar6 + 0x1a) =
           uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
      *(ushort *)((longlong)puVar6 + 0x12) = uVar1 >> 8 | uVar1 << 8;
      NdisAcquireRWLockWrite(*(undefined8 *)(lVar3 + 0x5e8),&local_res8,1);
      if (*(int *)(param_1 + 0xe8) == 3) {
        *(int *)(param_1 + 0xec) = *(int *)(param_1 + 0xec) + 1;
        NdisReleaseRWLock(*(undefined8 *)(lVar3 + 0x5e8),&local_res8);
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
                    &WPP_4ef88d54200138cb1a5bbf4ec4cd4989_Traceguids,param_2,(char)plVar5);
        }
        lbfoSendInternalNblsOnNic(param_1,plVar5,*(byte *)(param_2 + 0x288),1);
        return;
      }
      NdisReleaseRWLock(*(undefined8 *)(lVar3 + 0x5e8));
    }
    NdisFreeNetBufferList(plVar5);
  }
  return;
}



===== lbfoLACPProcessReceiveIndication @ 1c00087b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool lbfoLACPProcessReceiveIndication(longlong param_1,longlong *param_2,longlong param_3)

{
  char cVar1;
  uint uVar2;
  undefined *puVar3;
  undefined8 uVar4;
  bool bVar5;
  int *piVar6;
  undefined *puVar7;
  ulonglong uVar8;
  longlong lVar9;
  undefined1 auStack_108 [32];
  undefined1 local_c8 [128];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_108;
  puVar3 = *(undefined **)(param_1 + 0x10);
  memset(local_c8,0,0x7c);
  uVar4 = *(undefined8 *)(param_3 + 8);
  bVar5 = false;
  piVar6 = (int *)NdisGetDataBuffer(uVar4,0x10,local_c8);
  if ((((piVar6 == (int *)0x0) || (*piVar6 != 0xc28001)) || ((short)piVar6[1] != 0x200)) ||
     (((short)piVar6[3] != 0x988 || (1 < (byte)(*(char *)((longlong)piVar6 + 0xe) - 1U))))) {
    return *(char *)(param_2[0x60] + 0xd1) == '\0';
  }
  if (((*(uint *)(param_3 + 0x80) & 0x8000) == 0) &&
     ((*(int *)((longlong)piVar6 + 6) != (int)param_2[5] ||
      (*(short *)((longlong)piVar6 + 10) != *(short *)((longlong)param_2 + 0x2c))))) {
    if ((*(char *)((longlong)piVar6 + 0xe) == '\x01') &&
       (((*(char *)((longlong)piVar6 + 0xf) == '\x01' &&
         (puVar7 = (undefined *)NdisGetDataBuffer(uVar4,0x7c,local_c8), puVar7 != (undefined *)0x0))
        && (uVar8 = lbfoLACPChangeByteOrder((longlong)puVar7), (char)uVar8 != '\0')))) {
      bVar5 = true;
      lbfoLACPProcessLacpdu(puVar3,param_2,puVar7);
    }
    if ((((*(char *)((longlong)piVar6 + 0xe) == '\x02') &&
         (*(char *)((longlong)piVar6 + 0xf) == '\x01')) &&
        ((lVar9 = NdisGetDataBuffer(uVar4,0x7c,local_c8,1), lVar9 != 0 &&
         ((cVar1 = *(char *)(lVar9 + 0x10), cVar1 == '\x01' || (cVar1 == '\x02')))))) &&
       (*(char *)(lVar9 + 0x11) == '\x10')) {
      *(ushort *)(lVar9 + 0x12) = *(ushort *)(lVar9 + 0x12) >> 8 | *(ushort *)(lVar9 + 0x12) << 8;
      uVar2 = *(uint *)(lVar9 + 0x1a);
      *(uint *)(lVar9 + 0x1a) =
           uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
      if (cVar1 == '\x01') {
        lbfoLACPProcessMarkerRequestPdu(param_1,(longlong)param_2,lVar9);
        return true;
      }
      if (cVar1 != '\x02') {
        return true;
      }
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return true;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 4) {
        return true;
      }
      WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
                &WPP_4ef88d54200138cb1a5bbf4ec4cd4989_Traceguids,param_2,(char)lVar9);
      return true;
    }
    if (bVar5) {
      return true;
    }
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
            &WPP_4ef88d54200138cb1a5bbf4ec4cd4989_Traceguids);
  }
  return true;
}



===== lbfoLACPReceiveMachine @ 1c0008a2c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void lbfoLACPReceiveMachine(undefined *param_1,longlong *param_2)

{
  byte bVar1;
  byte bVar2;
  longlong lVar3;
  longlong lVar4;
  uint uVar5;
  undefined *puVar6;
  undefined2 uVar7;
  longlong *plVar8;
  longlong *plVar9;
  uint uVar10;
  
  lVar3 = param_2[0x60];
  plVar9 = (longlong *)0x5;
  puVar6 = param_1;
  if (*(char *)(lVar3 + 0x9c) != '\0') {
LAB_1c0008a7c:
    uVar5 = 0;
    goto LAB_1c0008b6f;
  }
  if ((*(char *)(lVar3 + 0xa4) == '\0') && (*(char *)(lVar3 + 0x9b) == '\0')) {
LAB_1c0008b6c:
    uVar5 = 1;
  }
  else {
    uVar5 = *(uint *)(lVar3 + 0x28);
    puVar6 = (undefined *)(ulonglong)uVar5;
    if (uVar5 == 0) goto LAB_1c0008b6c;
    if (uVar5 != 1) {
      if (uVar5 == 2) {
        puVar6 = (undefined *)0x0;
        if (*(char *)(lVar3 + 0xa5) != '\0') {
LAB_1c0008aeb:
          uVar5 = 5;
          goto LAB_1c0008b6f;
        }
        if (*(char *)(lVar3 + 0x68) != '\0') {
          uVar5 = 4;
          puVar6 = (undefined *)0x0;
LAB_1c0008afb:
          *(undefined1 *)(lVar3 + 0x68) = 0;
          goto LAB_1c0008b22;
        }
      }
      else {
        uVar5 = uVar5 - 4;
        puVar6 = (undefined *)(ulonglong)uVar5;
        if (uVar5 == 0) {
          uVar5 = 6 - (*(char *)(lVar3 + 0xa5) != '\0');
LAB_1c0008b22:
          if (uVar5 != 6) goto LAB_1c0008b6f;
        }
        else if (uVar5 == 1) {
          if (*(char *)(lVar3 + 0xa5) != '\0') goto LAB_1c0008aeb;
          if (*(char *)(lVar3 + 0x68) != '\0') {
            uVar5 = 2;
            goto LAB_1c0008afb;
          }
        }
      }
LAB_1c0008b27:
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 4) {
        return;
      }
      uVar10 = *(uint *)(lVar3 + 0x28);
      uVar7 = 0x15;
      goto LAB_1c0008b54;
    }
    puVar6 = (undefined *)0x0;
    if (*(char *)(lVar3 + 0xa4) != '\0') goto LAB_1c0008a7c;
    if (*(char *)(lVar3 + 0x9b) == '\0') goto LAB_1c0008b27;
    if (*(char *)(lVar3 + 0x9d) == '\0') {
      uVar5 = 3;
      goto LAB_1c0008b22;
    }
    uVar5 = 2;
  }
LAB_1c0008b6f:
  uVar10 = *(uint *)(lVar3 + 0x28);
  plVar8 = (longlong *)(ulonglong)uVar10;
  if ((uVar5 == uVar10) && ((uVar5 != 5 || (*(char *)(lVar3 + 0xa5) == '\0')))) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 4) {
      return;
    }
    uVar7 = 0x16;
LAB_1c0008b54:
    WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar7,
              &WPP_4ef88d54200138cb1a5bbf4ec4cd4989_Traceguids,param_2,(char)uVar10);
    return;
  }
  if ((Microsoft_Windows_MsLbfoEventProviderEnableBits & 1) != 0) {
    plVar9 = param_2 + 6;
    McTemplateK0jdd_EtwWriteTransfer
              (puVar6,&LACPRcvMcTransitionInfo,plVar8,plVar9,(char)uVar10,(char)uVar5);
  }
  puVar6 = WPP_GLOBAL_Control;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    plVar8 = (longlong *)&WPP_4ef88d54200138cb1a5bbf4ec4cd4989_Traceguids;
    puVar6 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
    plVar9 = param_2;
    WPP_SF_qdd(puVar6,0x17,&WPP_4ef88d54200138cb1a5bbf4ec4cd4989_Traceguids,param_2,
               (char)*(undefined4 *)(lVar3 + 0x28),(char)uVar5);
  }
  *(uint *)(lVar3 + 0x28) = uVar5;
  if (uVar5 == 0) {
    *(undefined4 *)(lVar3 + 0xa0) = 1;
    puVar6 = param_1;
    lbfoLACPRecordDefault((longlong)param_1,(longlong)param_2);
    *(undefined1 *)(lVar3 + 0xa4) = 0;
LAB_1c0008e06:
    *(byte *)(lVar3 + 0x89) = *(byte *)(lVar3 + 0x89) & 0x7f;
  }
  else {
    if (uVar5 == 1) {
      *(byte *)(lVar3 + 0x9a) = *(byte *)(lVar3 + 0x9a) & 0xf7;
    }
    else if (uVar5 == 2) {
      plVar9 = (longlong *)0x0;
      plVar8 = (longlong *)0x0;
      *(byte *)(lVar3 + 0x9a) = *(byte *)(lVar3 + 0x9a) & 0xf7 | 2;
      NdisSetTimerObject(*(undefined8 *)(lVar3 + 0x40),0xfffffffffe363c80);
      *(byte *)(lVar3 + 0x89) = *(byte *)(lVar3 + 0x89) | 0x80;
    }
    else {
      if (uVar5 != 3) {
        if (uVar5 == 4) {
          if ((((*(longlong *)(lVar3 + 0x8c) != 0) || (*(int *)(lVar3 + 0x94) != 0)) ||
              (*(short *)(lVar3 + 0x98) != 0)) || ((*(byte *)(lVar3 + 0x9a) & 4) != 0)) {
            *(undefined4 *)(lVar3 + 0xa0) = 1;
          }
          puVar6 = param_1;
          lbfoLACPRecordDefault((longlong)param_1,(longlong)param_2);
          goto LAB_1c0008e06;
        }
        if (uVar5 != 5) goto LAB_1c0008e0d;
        lVar4 = *(longlong *)(lVar3 + 0xa8);
        if (lVar4 != 0) {
          if (((*(longlong *)(lVar3 + 0x8c) != *(longlong *)(lVar4 + 0x12)) ||
              (*(int *)(lVar3 + 0x94) != *(int *)(lVar4 + 0x1a))) ||
             ((*(short *)(lVar3 + 0x98) != *(short *)(lVar4 + 0x1e) ||
              (((*(byte *)(lVar4 + 0x20) ^ *(byte *)(lVar3 + 0x9a)) & 4) != 0)))) {
            *(undefined4 *)(lVar3 + 0xa0) = 1;
          }
          if (((*(longlong *)(lVar3 + 0x7b) == *(longlong *)(lVar4 + 0x26)) &&
              (*(int *)(lVar3 + 0x83) == *(int *)(lVar4 + 0x2e))) &&
             (*(short *)(lVar3 + 0x87) == *(short *)(lVar4 + 0x32))) {
            bVar1 = *(byte *)(lVar3 + 0x89);
            bVar2 = *(byte *)(lVar4 + 0x34);
            if ((((((bVar1 ^ bVar2) & 1) == 0) && (((bVar1 ^ bVar2) & 2) == 0)) &&
                (((bVar1 ^ bVar2) & 8) == 0)) && (((bVar1 ^ bVar2) & 4) == 0)) goto LAB_1c0008ce7;
          }
          *(undefined1 *)(lVar3 + 0x78) = 1;
        }
LAB_1c0008ce7:
        lbfoLACPRecordPDU((longlong)param_1,(longlong)param_2);
        puVar6 = *(undefined **)(lVar3 + 0x40);
        plVar9 = (longlong *)0x0;
        plVar8 = (longlong *)0x0;
        NdisSetTimerObject(puVar6,(ulonglong)
                                  (-(uint)((*(byte *)(lVar3 + 0x89) & 2) != 0) & 870000000) -
                                  900000000);
        *(undefined1 *)(lVar3 + 0xa5) = 0;
        goto LAB_1c0008e06;
      }
      *(undefined4 *)(lVar3 + 0xa0) = 1;
      lbfoLACPRecordDefault((longlong)param_1,(longlong)param_2);
      *(byte *)(lVar3 + 0x9a) = *(byte *)(lVar3 + 0x9a) & 0xfb;
      *(byte *)(lVar3 + 0x89) = *(byte *)(lVar3 + 0x89) & 0x7f;
    }
    puVar6 = param_1;
    lbfoLACPUpdateOwningAggregatorData((longlong)param_1,(longlong)param_2);
  }
LAB_1c0008e0d:
  lbfoLACPPeriodicTransmissionMachine(puVar6,(longlong)param_2);
  lbfoLACPSelectionLogic(param_1,param_2,plVar8,plVar9);
  puVar6 = param_1;
  lbfoLACPMuxMachine(param_1,param_2,plVar8,plVar9);
  lbfoLACPTransmitMachine(puVar6,(longlong)param_2);
  lbfoLACPReceiveMachine(param_1,param_2);
  lbfoLACPChurnDetectionMachine((ulonglong)param_2,1);
  lbfoLACPChurnDetectionMachine((ulonglong)param_2,0);
  return;
}



===== lbfoLACPRecordDefault @ 1c0008e80 =====

void lbfoLACPRecordDefault(longlong param_1,longlong param_2)

{
  byte bVar1;
  longlong lVar2;
  
  lVar2 = *(longlong *)(param_2 + 0x300);
  *(byte *)(lVar2 + 0x89) = *(byte *)(lVar2 + 0x89) | 0x40;
  *(undefined4 *)(lVar2 + 0x8a) = 0;
  *(undefined8 *)(lVar2 + 0x8e) = 0;
  *(undefined4 *)(lVar2 + 0x96) = 0;
  *(undefined1 *)(lVar2 + 0x9a) = 0xf8;
  bVar1 = *(byte *)(lVar2 + 0x9a);
  *(byte *)(lVar2 + 0x9a) = (bVar1 * '\x02' ^ bVar1) & 0x10 ^ bVar1;
  lbfoLACPUpdateOwningAggregatorData(param_1,param_2);
  return;
}



===== lbfoLACPRecordPDU @ 1c0008ee4 =====

void lbfoLACPRecordPDU(longlong param_1,longlong param_2)

{
  byte bVar1;
  byte bVar2;
  longlong lVar3;
  longlong lVar4;
  bool bVar5;
  byte bVar6;
  byte bVar7;
  
  lVar3 = *(longlong *)(param_2 + 0x300);
  lVar4 = *(longlong *)(lVar3 + 0xa8);
  if (lVar4 != 0) {
    bVar5 = true;
    bVar1 = *(byte *)(lVar3 + 0x9a);
    bVar2 = *(byte *)(lVar3 + 0x89);
    *(undefined8 *)(lVar3 + 0x8c) = *(undefined8 *)(lVar4 + 0x12);
    bVar6 = bVar2 & 0xbf;
    *(undefined4 *)(lVar3 + 0x94) = *(undefined4 *)(lVar4 + 0x1a);
    *(undefined2 *)(lVar3 + 0x98) = *(undefined2 *)(lVar4 + 0x1e);
    bVar7 = *(byte *)(lVar4 + 0x20);
    *(byte *)(lVar3 + 0x9a) = bVar7;
    *(byte *)(lVar3 + 0x89) = bVar6;
    bVar7 = (bVar1 ^ bVar7) & 8 ^ bVar7;
    *(byte *)(lVar3 + 0x9a) = bVar7;
    bVar1 = *(byte *)(lVar4 + 0x20);
    if (((bVar1 & 1) == 0) && (((bVar2 & 1) == 0 || ((*(byte *)(lVar4 + 0x34) & 1) == 0)))) {
      bVar5 = false;
    }
    if ((((((*(longlong *)(lVar3 + 0x7b) == *(longlong *)(lVar4 + 0x26)) &&
           (*(int *)(lVar3 + 0x83) == *(int *)(lVar4 + 0x2e))) &&
          (*(short *)(lVar3 + 0x87) == *(short *)(lVar4 + 0x32))) &&
         ((((bVar6 ^ *(byte *)(lVar4 + 0x34)) & 4) == 0 && ((bVar1 & 8) != 0)))) && (bVar5)) ||
       ((((bVar1 & 4) == 0 && ((bVar1 & 8) != 0)) && (bVar5)))) {
      bVar7 = bVar7 | 8;
    }
    else {
      bVar7 = bVar7 & 0xf7;
    }
    *(byte *)(lVar3 + 0x9a) = bVar7;
    lbfoLACPUpdateOwningAggregatorData(param_1,param_2);
  }
  return;
}



===== lbfoLACPRemoveNic @ 1c0009000 =====

void lbfoLACPRemoveNic(undefined *param_1,longlong *param_2,longlong *param_3,longlong *param_4)

{
  longlong lVar1;
  code *pcVar2;
  undefined *puVar3;
  longlong *plVar4;
  longlong *plVar5;
  
  plVar4 = (longlong *)param_2[0x60];
  if (plVar4 != (longlong *)0x0) {
    plVar5 = param_3;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      plVar5 = (longlong *)&WPP_4ef88d54200138cb1a5bbf4ec4cd4989_Traceguids;
      param_4 = param_2;
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
               &WPP_4ef88d54200138cb1a5bbf4ec4cd4989_Traceguids,param_2);
    }
    *(undefined1 *)((longlong)plVar4 + 0x9c) = 1;
    puVar3 = param_1;
    lbfoLACPReceiveMachine(param_1,param_2);
    lbfoLACPPeriodicTransmissionMachine(puVar3,(longlong)param_2);
    lbfoLACPSelectionLogic(param_1,param_2,plVar5,param_4);
    puVar3 = param_1;
    lbfoLACPMuxMachine(param_1,param_2,plVar5,param_4);
    lbfoLACPTransmitMachine(puVar3,(longlong)param_2);
    lbfoLACPChurnDetectionMachine((ulonglong)param_2,1);
    lbfoLACPChurnDetectionMachine((ulonglong)param_2,0);
    lVar1 = *plVar4;
    if ((*(longlong **)(lVar1 + 8) != plVar4) ||
       (plVar5 = (longlong *)plVar4[1], (longlong *)*plVar5 != plVar4)) {
      pcVar2 = (code *)swi(0x29);
      (*pcVar2)(3);
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    *plVar5 = lVar1;
    *(longlong **)(lVar1 + 8) = plVar5;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
               &WPP_4ef88d54200138cb1a5bbf4ec4cd4989_Traceguids,param_2);
    }
    if (plVar4[8] != 0) {
      NdisCancelTimerObject();
    }
    if (plVar4[10] != 0) {
      NdisCancelTimerObject();
    }
    if (plVar4[9] != 0) {
      NdisCancelTimerObject();
    }
    if (plVar4[0xb] != 0) {
      NdisCancelTimerObject();
    }
    if (plVar4[0xc] != 0) {
      NdisCancelTimerObject();
    }
    NdisReleaseRWLock(*(undefined8 *)(param_1 + 0x5e8),param_3);
    KeFlushQueuedDpcs();
    while( true ) {
      NdisAcquireRWLockWrite(*(undefined8 *)(param_1 + 0x5e8),param_3);
      if ((char)plVar4[0x16] == '\0') break;
      NdisReleaseRWLock(*(undefined8 *)(param_1 + 0x5e8),param_3);
      NdisMSleep(10);
    }
    if (plVar4[8] != 0) {
      NdisFreeTimerObject();
      plVar4[8] = 0;
    }
    if (plVar4[10] != 0) {
      NdisFreeTimerObject();
      plVar4[10] = 0;
    }
    if (plVar4[9] != 0) {
      NdisFreeTimerObject();
      plVar4[9] = 0;
    }
    if (plVar4[0xb] != 0) {
      NdisFreeTimerObject();
      plVar4[0xb] = 0;
    }
    if (plVar4[0xc] != 0) {
      NdisFreeTimerObject();
      plVar4[0xc] = 0;
    }
    ExFreePoolWithTag(plVar4,0x5463694e);
    param_2[0x60] = 0;
    if ((Microsoft_Windows_MsLbfoEventProviderEnableBits & 1) != 0) {
      McTemplateK0jd_EtwWriteTransfer(plVar4,&LacpDeinitingInfo,0,param_2 + 6,0);
    }
  }
  return;
}



===== lbfoLACPSelectionLogic @ 1c00092bc =====

void lbfoLACPSelectionLogic
               (undefined *param_1,longlong *param_2,longlong *param_3,longlong *param_4)

{
  char cVar1;
  longlong lVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  uint7 uVar7;
  longlong lVar5;
  undefined *puVar6;
  undefined8 *puVar8;
  char cVar9;
  undefined1 uVar10;
  
  do {
    lVar2 = param_2[0x60];
    puVar8 = (undefined8 *)0x0;
    if (((*(byte *)(lVar2 + 0x89) & 4) == 0) || ((*(byte *)(lVar2 + 0x9a) & 4) == 0)) {
      puVar8 = *(undefined8 **)(lVar2 + 0x20);
    }
    else {
      for (puVar3 = *(undefined8 **)(param_1 + 0x8c8); puVar3 != (undefined8 *)(param_1 + 0x8c8);
          puVar3 = (undefined8 *)*puVar3) {
        if ((((*(char *)((longlong)puVar3 + 0x3e) != '\0') &&
             (*(int *)((longlong)puVar3 + 0x2e) == *(int *)(lVar2 + 0x7d))) &&
            (*(short *)((longlong)puVar3 + 0x32) == *(short *)(lVar2 + 0x81))) &&
           (((*(short *)((longlong)puVar3 + 0x34) == *(short *)(lVar2 + 0x83) &&
             (*(int *)((longlong)puVar3 + 0x36) == *(int *)(lVar2 + 0x8e))) &&
            ((*(short *)((longlong)puVar3 + 0x3a) == *(short *)(lVar2 + 0x92) &&
             (*(short *)((longlong)puVar3 + 0x3c) == *(short *)(lVar2 + 0x94))))))) {
          if ((*(int *)(lVar2 + 0x7d) != *(int *)(lVar2 + 0x8e)) ||
             (*(short *)(lVar2 + 0x81) != *(short *)(lVar2 + 0x92))) {
LAB_1c00093e6:
            puVar8 = puVar3;
            break;
          }
          param_4 = puVar3 + 3;
          param_3 = (longlong *)*param_4;
          while( true ) {
            if (param_3 == param_4) goto LAB_1c00093e6;
            lVar5 = param_3[0x60];
            if ((((*(int *)(lVar5 + 0x7d) == *(int *)(lVar5 + 0x8e)) &&
                 (*(short *)(lVar5 + 0x81) == *(short *)(lVar5 + 0x92))) &&
                (*(short *)(lVar2 + 0x98) == *(short *)(lVar5 + 0x87))) &&
               (*(short *)(lVar2 + 0x87) == *(short *)(lVar5 + 0x98))) break;
            param_3 = (longlong *)*param_3;
          }
        }
      }
    }
    puVar3 = *(undefined8 **)(lVar2 + 0x70);
    uVar10 = SUB81(puVar8,0);
    if (puVar8 == puVar3) {
      *(undefined4 *)(lVar2 + 0xa0) = 0;
      for (puVar3 = *(undefined8 **)(param_1 + 0x930); puVar3 != (undefined8 *)(param_1 + 0x930);
          puVar3 = (undefined8 *)*puVar3) {
        if (((*(int *)(puVar3 + 0x14) == 0) && ((undefined8 *)puVar3[0xe] == puVar8)) &&
           (*(char *)((longlong)puVar3 + 0x9f) == '\0')) {
          cVar9 = '\0';
          goto LAB_1c0009440;
        }
      }
      cVar9 = '\x01';
LAB_1c0009440:
      cVar1 = *(char *)(lVar2 + 0x9e);
      *(char *)(lVar2 + 0x9e) = cVar9;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])) {
        param_3 = (longlong *)&WPP_4ef88d54200138cb1a5bbf4ec4cd4989_Traceguids;
        param_4 = param_2;
        WPP_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
                   &WPP_4ef88d54200138cb1a5bbf4ec4cd4989_Traceguids,param_2,uVar10,cVar9);
      }
      if (cVar9 != cVar1) goto LAB_1c00095dc;
    }
    else {
      if ((*(int *)(lVar2 + 0x30) == 0) || (*(int *)(lVar2 + 0x30) == 5)) {
        *(undefined4 *)(lVar2 + 0xa0) = 0;
        puVar3 = (undefined8 *)(param_1 + 0x930);
        *(undefined8 **)(lVar2 + 0x70) = puVar8;
        for (puVar4 = (undefined8 *)*puVar3; uVar7 = (uint7)((ulonglong)puVar3 >> 8),
            puVar4 != puVar3; puVar4 = (undefined8 *)*puVar4) {
          if (((*(int *)(puVar4 + 0x14) == 0) && ((undefined8 *)puVar4[0xe] == puVar8)) &&
             (*(char *)((longlong)puVar4 + 0x9f) == '\0')) {
            lVar5 = (ulonglong)uVar7 << 8;
            goto LAB_1c0009571;
          }
        }
        lVar5 = CONCAT71(uVar7,1);
LAB_1c0009571:
        *(char *)(lVar2 + 0x9e) = (char)lVar5;
        if ((Microsoft_Windows_MsLbfoEventProviderEnableBits & 1) != 0) {
          param_4 = param_2 + 6;
          McTemplateK0jppt_EtwWriteTransfer
                    (lVar5,&LACPSelectAggrInfo,param_3,param_4,0,uVar10,(char)lVar5);
        }
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          param_3 = (longlong *)&WPP_4ef88d54200138cb1a5bbf4ec4cd4989_Traceguids;
          param_4 = param_2;
          WPP_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
                     &WPP_4ef88d54200138cb1a5bbf4ec4cd4989_Traceguids,param_2,uVar10,
                     *(undefined1 *)(lVar2 + 0x9e));
        }
      }
      else {
        if ((Microsoft_Windows_MsLbfoEventProviderEnableBits & 1) != 0) {
          param_4 = param_2 + 6;
          McTemplateK0jppt_EtwWriteTransfer
                    (puVar3,&LACPUnselectAggrInfo,param_3,param_4,(char)puVar3,uVar10,
                     *(undefined1 *)(lVar2 + 0x9e));
        }
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          param_3 = (longlong *)&WPP_4ef88d54200138cb1a5bbf4ec4cd4989_Traceguids;
          param_4 = param_2;
          WPP_SF_qqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
                     &WPP_4ef88d54200138cb1a5bbf4ec4cd4989_Traceguids,param_2,
                     (char)*(undefined8 *)(lVar2 + 0x70),uVar10);
        }
        *(undefined8 *)(lVar2 + 0x70) = 0;
        *(undefined4 *)(lVar2 + 0xa0) = 1;
        *(undefined1 *)(lVar2 + 0x9e) = 0;
      }
LAB_1c00095dc:
      puVar6 = param_1;
      lbfoLACPMuxMachine(param_1,param_2,param_3,param_4);
      lbfoLACPTransmitMachine(puVar6,(longlong)param_2);
    }
    if (*(int *)(lVar2 + 0xa0) != 1) {
      return;
    }
  } while( true );
}



===== lbfoLACPSendLacpduWorkItem @ 1c0009630 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void lbfoLACPSendLacpduWorkItem(longlong param_1,undefined8 param_2)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  int iVar4;
  longlong lVar5;
  longlong *plVar6;
  undefined4 *puVar7;
  uint uVar8;
  longlong lVar9;
  undefined8 *puVar10;
  undefined8 uVar11;
  undefined2 local_res8;
  undefined1 local_resa;
  ulonglong uVar12;
  
  lVar1 = *(longlong *)(param_1 + 0x18);
  lVar2 = *(longlong *)(param_1 + 0x10);
  local_res8 = 0;
  local_resa = 0;
  NdisAcquireRWLockWrite(*(undefined8 *)(lVar1 + 0x5e8),&local_res8,0);
  lVar3 = *(longlong *)(param_1 + 0xb8 + (ulonglong)*(byte *)(param_1 + 0xd0) * 8);
  while( true ) {
    lVar5 = _DAT_fffff78000000320 - lVar3;
    lVar9 = 0;
    if (-1 < lVar5) {
      lVar9 = lVar5;
    }
    if (9999999 < lVar9 * (ulonglong)DAT_1c0018470) break;
    NdisReleaseRWLock(*(undefined8 *)(lVar1 + 0x5e8),&local_res8);
    NdisMSleep(50000);
    NdisAcquireRWLockWrite(*(undefined8 *)(lVar1 + 0x5e8));
  }
  puVar10 = *(undefined8 **)(lVar1 + 0x10);
  do {
    if (puVar10 == (undefined8 *)(lVar1 + 0x10)) {
LAB_1c00099da:
      NdisFreeIoWorkItem(param_2);
      *(undefined1 *)(param_1 + 0xb0) = 0;
      if (*(longlong *)(lVar2 + 0x300) != 0) {
        lbfoLACPTransmitMachine(lVar1,lVar2);
      }
      NdisReleaseRWLock(*(undefined8 *)(lVar1 + 0x5e8),&local_res8);
      return;
    }
    if (*(int *)(puVar10 + 0x1d) == 3) {
      if ((((puVar10 == (undefined8 *)0x0) || (*(int *)(lVar2 + 0x2e8) != 2)) ||
          (*(char *)(param_1 + 0x78) == '\0')) ||
         (plVar6 = (longlong *)NdisAllocateNetBufferList(puVar10[0x1e],0,0),
         plVar6 == (longlong *)0x0)) goto LAB_1c00099da;
      plVar6[0xf] = puVar10[3];
      uVar12 = 0;
      iVar4 = NdisRetreatNetBufferListDataStart(plVar6,0x7c,0,0,0);
      if (iVar4 == 0) {
        uVar12 = uVar12 & 0xffffffff00000000;
        puVar7 = (undefined4 *)NdisGetDataBuffer(plVar6[1],0x7c,0,1);
        if (puVar7 != (undefined4 *)0x0) {
          memset((void *)((longlong)puVar7 + 6),0,0x76);
          uVar11 = 0;
          *puVar7 = 0xc28001;
          iVar4 = 1;
          *(undefined2 *)(puVar7 + 1) = 0x200;
          *(undefined4 *)((longlong)puVar7 + 6) = *(undefined4 *)(lVar2 + 0x28);
          *(undefined2 *)((longlong)puVar7 + 10) = *(undefined2 *)(lVar2 + 0x2c);
          puVar7[3] = 0x1010988;
          *(undefined2 *)(puVar7 + 4) = 0x1401;
          *(undefined2 *)((longlong)puVar7 + 0x12) = *(undefined2 *)(param_1 + 0x7b);
          puVar7[5] = *(undefined4 *)(param_1 + 0x7d);
          *(undefined2 *)(puVar7 + 6) = *(undefined2 *)(param_1 + 0x81);
          *(undefined2 *)((longlong)puVar7 + 0x1a) = *(undefined2 *)(param_1 + 0x83);
          *(undefined2 *)(puVar7 + 7) = *(undefined2 *)(param_1 + 0x85);
          *(undefined2 *)((longlong)puVar7 + 0x1e) = *(undefined2 *)(param_1 + 0x87);
          *(undefined1 *)(puVar7 + 8) = *(undefined1 *)(param_1 + 0x89);
          *(undefined2 *)(puVar7 + 9) = 0x1402;
          *(undefined2 *)((longlong)puVar7 + 0x26) = *(undefined2 *)(param_1 + 0x8c);
          puVar7[10] = *(undefined4 *)(param_1 + 0x8e);
          *(undefined2 *)(puVar7 + 0xb) = *(undefined2 *)(param_1 + 0x92);
          *(undefined2 *)((longlong)puVar7 + 0x2e) = *(undefined2 *)(param_1 + 0x94);
          *(undefined2 *)(puVar7 + 0xc) = *(undefined2 *)(param_1 + 0x96);
          *(undefined2 *)((longlong)puVar7 + 0x32) = *(undefined2 *)(param_1 + 0x98);
          *(undefined1 *)(puVar7 + 0xd) = *(undefined1 *)(param_1 + 0x9a);
          puVar7[0xe] = 0x11003;
          *(undefined2 *)(puVar7 + 0x12) = 0;
          lbfoLACPChangeByteOrder((longlong)puVar7);
          *(int *)((longlong)puVar10 + 0xec) = *(int *)((longlong)puVar10 + 0xec) + iVar4;
          *(char *)(param_1 + 0x78) = (char)uVar11;
          *(longlong *)(param_1 + 0xb8 + (ulonglong)*(byte *)(param_1 + 0xd0) * 8) =
               _DAT_fffff78000000320;
          uVar8 = (uint)*(byte *)(param_1 + 0xd0) + iVar4;
          *(char *)(param_1 + 0xd0) = (char)uVar8 + (char)(uVar8 / 3) * -3;
          NdisReleaseRWLock(*(undefined8 *)(lVar1 + 0x5e8),&local_res8);
          if ((Microsoft_Windows_MsLbfoEventProviderEnableBits & 1) != 0) {
            McTemplateK0jqbr1_EtwWriteTransfer
                      (1,&SendingLACPDUInfo,uVar11,lVar2 + 0x30,uVar12,puVar7);
          }
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (3 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,
                      &WPP_4ef88d54200138cb1a5bbf4ec4cd4989_Traceguids,lVar2,(char)plVar6);
          }
          lbfoSendInternalNblsOnNic((longlong)puVar10,plVar6,*(byte *)(lVar2 + 0x288),0);
          NdisAcquireRWLockWrite(*(undefined8 *)(lVar1 + 0x5e8),&local_res8,0);
          goto LAB_1c00099da;
        }
      }
      NdisFreeNetBufferList(plVar6);
      goto LAB_1c00099da;
    }
    puVar10 = (undefined8 *)*puVar10;
  } while( true );
}



===== lbfoLACPTimerActorChurn @ 1c0009a40 =====

void lbfoLACPTimerActorChurn(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  undefined2 local_res10;
  undefined1 local_res12;
  
  lVar1 = *(longlong *)(param_2 + 0x18);
  uVar2 = *(ulonglong *)(param_2 + 0x10);
  local_res10 = 0;
  local_res12 = 0;
  NdisAcquireRWLockWrite(*(undefined8 *)(lVar1 + 0x5e8),&local_res10,1);
  if (*(longlong *)(uVar2 + 0x300) != 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x29,
               &WPP_4ef88d54200138cb1a5bbf4ec4cd4989_Traceguids,uVar2);
    }
    *(undefined1 *)(*(longlong *)(uVar2 + 0x300) + 0x6a) = 1;
    lbfoLACPChurnDetectionMachine(uVar2,1);
  }
  NdisReleaseRWLock(*(undefined8 *)(lVar1 + 0x5e8),&local_res10);
  return;
}



===== lbfoLACPTimerCurrentWhile @ 1c0009b00 =====

void lbfoLACPTimerCurrentWhile(undefined8 param_1,longlong param_2)

{
  longlong *plVar1;
  undefined *puVar2;
  undefined2 local_res10;
  undefined1 local_res12;
  
  plVar1 = *(longlong **)(param_2 + 0x10);
  puVar2 = (undefined *)plVar1[0x53];
  local_res10 = 0;
  local_res12 = 0;
  NdisAcquireRWLockWrite(*(undefined8 *)(puVar2 + 0x5e8),&local_res10,1);
  if (plVar1[0x60] != 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x26,
               &WPP_4ef88d54200138cb1a5bbf4ec4cd4989_Traceguids,plVar1);
    }
    *(undefined1 *)(plVar1[0x60] + 0x68) = 1;
    lbfoLACPReceiveMachine(puVar2,plVar1);
    *(undefined1 *)(plVar1[0x60] + 0x68) = 0;
    lbfoLACPReceiveMachine(puVar2,plVar1);
  }
  NdisReleaseRWLock(*(undefined8 *)(puVar2 + 0x5e8),&local_res10);
  return;
}



===== lbfoLACPTimerPartnerChurn @ 1c0009bd0 =====

void lbfoLACPTimerPartnerChurn(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  undefined2 local_res10;
  undefined1 local_res12;
  
  lVar1 = *(longlong *)(param_2 + 0x18);
  uVar2 = *(ulonglong *)(param_2 + 0x10);
  local_res10 = 0;
  local_res12 = 0;
  NdisAcquireRWLockWrite(*(undefined8 *)(lVar1 + 0x5e8),&local_res10,1);
  if (*(longlong *)(uVar2 + 0x300) != 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2a,
               &WPP_4ef88d54200138cb1a5bbf4ec4cd4989_Traceguids,uVar2);
    }
    *(undefined1 *)(*(longlong *)(uVar2 + 0x300) + 0x6b) = 1;
    lbfoLACPChurnDetectionMachine(uVar2,0);
  }
  NdisReleaseRWLock(*(undefined8 *)(lVar1 + 0x5e8),&local_res10);
  return;
}



===== lbfoLACPTimerPeriodic @ 1c0009c90 =====

void lbfoLACPTimerPeriodic(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  undefined *puVar3;
  undefined2 local_res10;
  undefined1 local_res12;
  
  lVar1 = *(longlong *)(param_2 + 0x18);
  lVar2 = *(longlong *)(param_2 + 0x10);
  local_res10 = 0;
  local_res12 = 0;
  NdisAcquireRWLockWrite(*(undefined8 *)(lVar1 + 0x5e8),&local_res10,1);
  if (*(longlong *)(lVar2 + 0x300) != 0) {
    puVar3 = WPP_GLOBAL_Control;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      puVar3 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
      WPP_SF_q(puVar3,0x27,&WPP_4ef88d54200138cb1a5bbf4ec4cd4989_Traceguids,lVar2);
    }
    *(undefined1 *)(*(longlong *)(lVar2 + 0x300) + 0x69) = 1;
    lbfoLACPPeriodicTransmissionMachine(puVar3,lVar2);
    *(undefined1 *)(*(longlong *)(lVar2 + 0x300) + 0x69) = 0;
    lbfoLACPPeriodicTransmissionMachine(puVar3,lVar2);
  }
  NdisReleaseRWLock(*(undefined8 *)(lVar1 + 0x5e8),&local_res10);
  return;
}



===== lbfoLACPTimerWaitWhile @ 1c0009d60 =====

void lbfoLACPTimerWaitWhile
               (undefined8 param_1,longlong param_2,undefined8 param_3,longlong *param_4)

{
  undefined *puVar1;
  longlong *plVar2;
  longlong *plVar3;
  undefined2 local_res10;
  undefined1 local_res12;
  
  puVar1 = *(undefined **)(param_2 + 0x18);
  plVar2 = *(longlong **)(param_2 + 0x10);
  plVar3 = (longlong *)CONCAT71((int7)((ulonglong)param_3 >> 8),1);
  local_res10 = 0;
  local_res12 = 0;
  NdisAcquireRWLockWrite(*(undefined8 *)(puVar1 + 0x5e8),&local_res10);
  if (plVar2[0x60] != 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      plVar3 = (longlong *)&WPP_4ef88d54200138cb1a5bbf4ec4cd4989_Traceguids;
      param_4 = plVar2;
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x28,
               &WPP_4ef88d54200138cb1a5bbf4ec4cd4989_Traceguids,plVar2);
    }
    *(undefined1 *)(plVar2[0x60] + 0x9f) = 1;
    lbfoLACPSelectionLogic(puVar1,plVar2,plVar3,param_4);
  }
  NdisReleaseRWLock(*(undefined8 *)(puVar1 + 0x5e8),&local_res10);
  return;
}



===== lbfoLACPTransmitMachine @ 1c0009e18 =====

void lbfoLACPTransmitMachine(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar1 = *(longlong *)(param_2 + 0x300);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,
              &WPP_4ef88d54200138cb1a5bbf4ec4cd4989_Traceguids,param_2,*(undefined1 *)(lVar1 + 0x78)
             );
  }
  if (*(char *)(lVar1 + 0x78) != '\0') {
    if ((*(int *)(lVar1 + 0x2c) == 0) || (*(char *)(lVar1 + 0x9d) == '\0')) {
      *(undefined1 *)(lVar1 + 0x78) = 0;
    }
    else if (*(char *)(lVar1 + 0xb0) == '\0') {
      lVar2 = NdisAllocateIoWorkItem(DAT_1c0018468);
      if (lVar2 != 0) {
        NdisQueueIoWorkItem(lVar2,lbfoLACPSendLacpduWorkItem,lVar1);
        *(undefined1 *)(lVar1 + 0xb0) = 1;
      }
    }
  }
  return;
}



===== lbfoLACPUpdateOwningAggregatorData @ 1c0009ec8 =====

void lbfoLACPUpdateOwningAggregatorData(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong *plVar2;
  longlong *plVar3;
  char cVar4;
  
  lVar1 = *(longlong *)(param_2 + 0x300);
  plVar3 = *(longlong **)(lVar1 + 0x20);
  cVar4 = '\0';
  if ((*(byte *)(lVar1 + 0x89) & 4) != 0) {
    cVar4 = '\0';
    if ((*(byte *)(lVar1 + 0x9a) & 4) != 0) {
      cVar4 = '\x01';
    }
  }
  if (((((*(char *)((longlong)plVar3 + 0x3e) != cVar4) ||
        (*(int *)((longlong)plVar3 + 0x2e) != *(int *)(lVar1 + 0x7d))) ||
       (*(short *)((longlong)plVar3 + 0x32) != *(short *)(lVar1 + 0x81))) ||
      ((*(short *)((longlong)plVar3 + 0x34) != *(short *)(lVar1 + 0x83) ||
       (*(int *)((longlong)plVar3 + 0x36) != *(int *)(lVar1 + 0x8e))))) ||
     ((*(short *)((longlong)plVar3 + 0x3a) != *(short *)(lVar1 + 0x92) ||
      (*(short *)((longlong)plVar3 + 0x3c) != *(short *)(lVar1 + 0x94))))) {
    if ((1 < *(ushort *)(plVar3 + 5)) &&
       (plVar2 = lbfoCreateAggregator(param_1), plVar2 != (longlong *)0x0)) {
      *(longlong **)(lVar1 + 0x20) = plVar2;
      plVar3 = plVar2;
    }
    *(char *)((longlong)plVar3 + 0x3e) = cVar4;
    *(undefined4 *)((longlong)plVar3 + 0x2e) = *(undefined4 *)(lVar1 + 0x7d);
    *(undefined2 *)((longlong)plVar3 + 0x32) = *(undefined2 *)(lVar1 + 0x81);
    *(undefined2 *)((longlong)plVar3 + 0x34) = *(undefined2 *)(lVar1 + 0x83);
    *(undefined4 *)((longlong)plVar3 + 0x36) = *(undefined4 *)(lVar1 + 0x8e);
    *(undefined2 *)((longlong)plVar3 + 0x3a) = *(undefined2 *)(lVar1 + 0x92);
    *(undefined2 *)((longlong)plVar3 + 0x3c) = *(undefined2 *)(lVar1 + 0x94);
  }
  return;
}



===== lbfoNTHAddNic @ 1c0009fd0 =====

undefined8 lbfoNTHAddNic(longlong param_1,longlong param_2)

{
  byte bVar1;
  longlong lVar2;
  
  if ((DAT_1c001849c & 8) != 0) {
    *(undefined4 *)(param_2 + 0x310) = 1;
    *(undefined8 *)(param_2 + 0x318) = 0;
    *(undefined4 *)(param_2 + 800) = 0;
    KeInitializeEvent(param_2 + 0x328,1,0);
    lVar2 = NdisAllocateIoWorkItem(DAT_1c0018468);
    *(longlong *)(param_2 + 0x308) = lVar2;
    if (lVar2 == 0) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 0xc000009a;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
        return 0xc000009a;
      }
      WPP_SF_ds(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                &WPP_a8ffaab75a7e35c68405167139691130_Traceguids,0xc000009a,
                "lbfoLBSrIovAddNic(Team, &Nic->NTH.SrIov)");
      return 0xc000009a;
    }
  }
  bVar1 = *(byte *)(param_2 + 0x288);
  *(undefined4 *)(param_1 + 0x992 + (ulonglong)bVar1 * 6) = *(undefined4 *)(param_2 + 0x28);
  *(undefined2 *)(param_1 + 0x996 + (ulonglong)bVar1 * 6) = *(undefined2 *)(param_2 + 0x2c);
  if (*(longlong *)(param_2 + 0x20) != *(longlong *)(param_1 + 0x948)) {
    *(ulonglong *)(param_1 + 0x990) =
         *(ulonglong *)(param_1 + 0x990) |
         1L << ((ulonglong)(*(byte *)(param_2 + 0x288) - 1) & 0x3f);
  }
  return 0;
}



===== lbfoNTHAddVmsPort @ 1c000a0f0 =====

void lbfoNTHAddVmsPort(longlong param_1)

{
  if (*(short *)(param_1 + 0x5f8) == 2) {
    *(undefined1 *)(param_1 + 0x658) = 1;
  }
  return;
}



===== lbfoNTHChangeNicAggregator @ 1c000a110 =====

void lbfoNTHChangeNicAggregator(longlong param_1,longlong param_2,longlong param_3,longlong param_4)

{
  ulonglong *puVar1;
  longlong lVar2;
  
  lVar2 = *(longlong *)(param_1 + 0x948);
  puVar1 = (ulonglong *)(param_1 + 0x990);
  if (param_3 == lVar2) {
    *puVar1 = *puVar1 | 1L << ((ulonglong)(*(byte *)(param_2 + 0x288) - 1) & 0x3f);
  }
  if (param_4 == lVar2) {
    *puVar1 = *puVar1 & ~(1L << ((ulonglong)(*(byte *)(param_2 + 0x288) - 1) & 0x3f));
  }
  if ((DAT_1c001849c & 8) != 0) {
    if (param_3 == lVar2) {
      lbfoSetOriginalMacOnNic(param_2,(undefined8 *)(param_2 + 0x308));
    }
    if (param_4 == lVar2) {
      lbfoSetTeamMacOnNic(param_1,param_2,(undefined8 *)(param_2 + 0x308));
    }
  }
  lbfoNTHUpdateUnicastReceiver(param_1);
  return;
}



===== lbfoNTHConnectNic @ 1c000a1d0 =====

void lbfoNTHConnectNic(longlong param_1,longlong param_2)

{
  lbfoNTHUpdateUnicastReceiver(param_1);
  if ((DAT_1c001849c & 8) != 0) {
    if (*(longlong *)(param_2 + 0x20) == *(longlong *)(param_1 + 0x948)) {
      lbfoSetTeamMacOnNic(param_1,param_2,(undefined8 *)(param_2 + 0x308));
    }
    else {
      lbfoSetOriginalMacOnNic(param_2,(undefined8 *)(param_2 + 0x308));
    }
  }
  lbfoNTHSetHashToNicIdTable(param_1);
  return;
}



===== lbfoNTHDisconnectNic @ 1c000a240 =====

void lbfoNTHDisconnectNic(longlong param_1,longlong param_2)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined1 uVar3;
  
  lbfoNTHUpdateUnicastReceiver(param_1);
  if (*(char *)(param_2 + 0x288) == *(char *)(param_1 + 0xb18)) {
    uVar3 = 0;
    if (*(longlong *)(param_1 + 0x948) != 0) {
      puVar2 = (undefined8 *)(*(longlong *)(param_1 + 0x948) + 0x18);
      for (puVar1 = (undefined8 *)*puVar2; puVar1 != puVar2; puVar1 = (undefined8 *)*puVar1) {
        if (*(int *)(puVar1 + 0x54) == 0) {
          uVar3 = *(undefined1 *)(puVar1 + 0x51);
          break;
        }
      }
    }
    *(undefined1 *)(param_1 + 0xb18) = uVar3;
  }
  lbfoNTHSetHashToNicIdTable(param_1);
  return;
}



===== lbfoNTHGetOutgoingNicId @ 1c000a2c0 =====

ulonglong lbfoNTHGetOutgoingNicId(longlong param_1,longlong param_2)

{
  longlong lVar1;
  uint uVar2;
  undefined4 extraout_var;
  ulonglong uVar3;
  byte local_res8 [8];
  
  lVar1 = *(longlong *)(param_1 + 0x10);
  local_res8[0] = 0;
  uVar2 = lbfoLBGetNblHash(param_2,*(int *)(lVar1 + 0x5a0),local_res8);
  *(ulonglong *)(param_2 + 0x70) =
       ((ulonglong)local_res8[0] << 0x28 ^ *(ulonglong *)(param_2 + 0x70)) & 0xfffffeffffffffff ^
       (ulonglong)local_res8[0] << 0x28;
  if (local_res8[0] == 0) {
    uVar3 = (ulonglong)*(byte *)((ulonglong)(uVar2 & 0x3f) + 0x950 + lVar1);
  }
  else {
    uVar3 = CONCAT71((int7)(CONCAT44(extraout_var,uVar2) >> 8),*(undefined1 *)(lVar1 + 0xb18));
  }
  return uVar3;
}



===== lbfoNTHGetSwitchPrimingNbls @ 1c000a340 =====

int lbfoNTHGetSwitchPrimingNbls(longlong param_1,longlong param_2,undefined8 param_3)

{
  byte *pbVar1;
  byte bVar2;
  longlong lVar3;
  undefined8 *puVar4;
  uint uVar5;
  int iVar6;
  
  iVar6 = 0;
  lVar3 = *(longlong *)(param_1 + 0x10);
  bVar2 = *(byte *)(lVar3 + 0xb18);
  if (bVar2 != 0) {
    pbVar1 = (byte *)(*(longlong *)(*(longlong *)(lVar3 + 0x650) + 0x40) + 0x52);
    *pbVar1 = *pbVar1 | 1;
    for (puVar4 = *(undefined8 **)(lVar3 + 0x8f0); puVar4 != (undefined8 *)(lVar3 + 0x8f0);
        puVar4 = (undefined8 *)*puVar4) {
      uVar5 = lbfoLBGetSwitchPrimingNblsForCfgMac
                        (param_1,(longlong)(puVar4 + -6),
                         (undefined8 *)(param_2 + (ulonglong)bVar2 * 8 + -8),param_3);
      iVar6 = iVar6 + uVar5;
    }
  }
  return iVar6;
}



===== lbfoNTHPrepareForSend @ 1c000a3e0 =====

ulonglong lbfoNTHPrepareForSend(longlong param_1,longlong param_2,byte param_3)

{
  longlong lVar1;
  uint uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  longlong lVar5;
  undefined4 local_res8;
  undefined2 local_resc;
  
  lVar1 = *(longlong *)(param_1 + 0x10);
  uVar2 = NdisAllocateNetBufferListContext(param_2,0x10,*(undefined2 *)(param_1 + 0x48),0x5463694e);
  uVar4 = (ulonglong)uVar2;
  if (uVar2 == 0) {
    lVar5 = *(longlong *)(param_2 + 0x10) + 0x10 +
            (ulonglong)*(ushort *)(*(longlong *)(param_2 + 0x10) + 10);
    *(undefined1 *)(lVar5 + 8) = 0;
    if ((*(ulonglong *)(lVar1 + 0x990) >> ((ulonglong)(param_3 - 1 & 0xff) & 0x3f) & 1) != 0) {
      local_res8 = *(undefined4 *)(lVar1 + 0x992 + (ulonglong)param_3 * 6);
      local_resc = *(undefined2 *)(lVar1 + 0x996 + (ulonglong)param_3 * 6);
      uVar3 = lbfoLBReplaceNblMacAddress(param_2,&local_res8);
      uVar4 = uVar3 & 0xffffffff;
      if (((int)uVar3 != 0) && (lVar5 != 0)) {
        NdisFreeNetBufferListContext(param_2,0x10);
      }
    }
  }
  else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_ds(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
              &WPP_a8ffaab75a7e35c68405167139691130_Traceguids,uVar2,
              "NdisAllocateNetBufferListContext(Nbl, sizeof(LBFO_NBL_CONTEXT), FilterContext->NblContextBackfill, LBFO_POOLTAG)"
             );
  }
  return uVar4;
}



===== lbfoNTHRemoveNic @ 1c000a500 =====

void lbfoNTHRemoveNic(longlong param_1,longlong param_2)

{
  byte bVar1;
  
  if ((DAT_1c001849c & 8) != 0) {
    NdisFreeIoWorkItem(*(undefined8 *)(param_2 + 0x308));
  }
  bVar1 = *(byte *)(param_2 + 0x288);
  *(undefined4 *)(param_1 + 0x992 + (ulonglong)bVar1 * 6) = 0;
  *(undefined2 *)(param_1 + 0x996 + (ulonglong)bVar1 * 6) = 0;
  *(ulonglong *)(param_1 + 0x990) =
       *(ulonglong *)(param_1 + 0x990) &
       ~(1L << ((ulonglong)(*(byte *)(param_2 + 0x288) - 1) & 0x3f));
  return;
}



===== lbfoNTHRemoveVmsPort @ 1c000a580 =====

void lbfoNTHRemoveVmsPort(longlong param_1)

{
  if (*(short *)(param_1 + 0x5f8) == 1) {
    *(undefined1 *)(param_1 + 0x658) = 0;
  }
  return;
}



===== lbfoNTHSendComplete @ 1c000a5a0 =====

void lbfoNTHSendComplete(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  undefined4 local_res18;
  undefined2 local_res1c;
  
  lVar1 = *(longlong *)(param_2 + 0x10);
  uVar2 = (ulonglong)*(ushort *)(lVar1 + 10);
  if (*(char *)(uVar2 + 0x18 + lVar1) != '\0') {
    local_res18 = *(undefined4 *)(uVar2 + 0x10 + lVar1);
    local_res1c = *(undefined2 *)(uVar2 + 0x14 + lVar1);
    lbfoLBRevertMacAddress(*(longlong **)(param_2 + 8),(longlong *)0x0,&local_res18);
  }
  NdisFreeNetBufferListContext(param_2,0x10);
  return;
}



===== lbfoNTHSetHashToNicIdTable @ 1c000a5fc =====

void lbfoNTHSetHashToNicIdTable(longlong param_1)

{
  undefined8 *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  byte bVar4;
  uint uVar5;
  ulonglong uVar6;
  
  uVar5 = 1;
  uVar6 = 0;
  if (*(short *)(param_1 + 0x8ec) == 0) {
    memset((void *)(param_1 + 0x950),0,0x40);
  }
  else {
    for (puVar1 = *(undefined8 **)(param_1 + 0x8d8); uVar2 = 0,
        puVar1 != (undefined8 *)(param_1 + 0x8d8); puVar1 = (undefined8 *)*puVar1) {
      uVar6 = uVar6 | 1L << ((ulonglong)(*(byte *)(puVar1 + 0x4f) - 1) & 0x3f);
    }
    do {
      uVar3 = uVar2;
      if ((uVar6 >> ((ulonglong)(uVar5 - 1 & 0xff) & 0x3f) & 1) != 0) {
        uVar3 = (ulonglong)(byte)((char)uVar2 + 1);
        *(char *)(uVar2 + 0x950 + param_1) = (char)uVar5;
      }
      bVar4 = (char)uVar5 + 1;
      uVar5 = 1;
      if (bVar4 < 0x41) {
        uVar5 = (uint)bVar4;
      }
      uVar2 = uVar3;
    } while ((byte)uVar3 < 0x40);
  }
  return;
}



===== lbfoNTHUpdateUnicastReceiver @ 1c000a690 =====

void lbfoNTHUpdateUnicastReceiver(longlong param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined1 uVar3;
  undefined *puVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  
  puVar1 = *(undefined8 **)(param_1 + 0x948);
  puVar6 = (undefined8 *)0x0;
  if (puVar1 != (undefined8 *)0x0) {
    for (puVar7 = (undefined8 *)puVar1[3]; puVar7 != puVar1 + 3; puVar7 = (undefined8 *)*puVar7) {
      *(ulonglong *)(puVar1[2] + 0x990) =
           *(ulonglong *)(puVar1[2] + 0x990) |
           1L << ((ulonglong)(*(byte *)(puVar7 + 0x51) - 1) & 0x3f);
    }
  }
  puVar7 = (undefined8 *)(param_1 + 0x8c8);
  puVar2 = (undefined8 *)*puVar7;
  if (puVar2 != puVar7) {
    do {
      if (*(short *)((longlong)puVar2 + 0x2a) != 0) {
        for (puVar5 = (undefined8 *)puVar2[3]; puVar6 = puVar2, puVar5 != puVar2 + 3;
            puVar5 = (undefined8 *)*puVar5) {
          if ((*(int *)(puVar5 + 5) == *(int *)(puVar5[0x53] + 0x96)) &&
             (*(short *)((longlong)puVar5 + 0x2c) == *(short *)(puVar5[0x53] + 0x9a)))
          goto LAB_1c000a748;
        }
      }
      puVar2 = (undefined8 *)*puVar2;
    } while (puVar2 != puVar7);
LAB_1c000a748:
    if (puVar6 != (undefined8 *)0x0) {
      for (puVar7 = (undefined8 *)puVar6[3]; puVar7 != puVar6 + 3; puVar7 = (undefined8 *)*puVar7) {
        *(ulonglong *)(puVar6[2] + 0x990) =
             *(ulonglong *)(puVar6[2] + 0x990) &
             ~(1L << ((ulonglong)(*(byte *)(puVar7 + 0x51) - 1) & 0x3f));
      }
      uVar3 = 0;
      for (puVar2 = (undefined8 *)puVar6[3]; puVar2 != puVar6 + 3; puVar2 = (undefined8 *)*puVar2) {
        if (*(int *)(puVar2 + 0x54) == 0) {
          uVar3 = *(undefined1 *)(puVar2 + 0x51);
          break;
        }
      }
      *(undefined1 *)(param_1 + 0xb18) = uVar3;
    }
  }
  *(undefined8 **)(param_1 + 0x948) = puVar6;
  if (puVar6 != puVar1) {
    *(byte *)(param_1 + 0x922) = puVar6 != (undefined8 *)0x0 | *(byte *)(param_1 + 0x922) & 0xfe;
    if (puVar6 != (undefined8 *)0x0) {
      lbfoQueuePrimeSwitchIfNeededWorkItem(param_1);
    }
    puVar4 = WPP_GLOBAL_Control;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      puVar4 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
      puVar7 = (undefined8 *)&WPP_4faf8ad2ef6a3eb9902bc53cbc535b3e_Traceguids;
      WPP_SF_qqq(puVar4,0x12,&WPP_4faf8ad2ef6a3eb9902bc53cbc535b3e_Traceguids,param_1,(char)puVar1,
                 (char)puVar6);
    }
    if ((Microsoft_Windows_MsLbfoEventProviderEnableBits & 1) != 0) {
      McTemplateK0pp_EtwWriteTransfer(puVar4,&TNicDefaultAggChangedInfo,puVar7,param_1,(char)puVar6)
      ;
    }
    if ((DAT_1c001849c & 8) != 0) {
      if (puVar6 != (undefined8 *)0x0) {
        for (puVar7 = (undefined8 *)puVar6[3]; puVar7 != puVar6 + 3; puVar7 = (undefined8 *)*puVar7)
        {
          lbfoSetTeamMacOnNic(param_1,(longlong)puVar7,puVar7 + 0x61);
        }
      }
      if (puVar1 != (undefined8 *)0x0) {
        for (puVar6 = (undefined8 *)puVar1[3]; puVar6 != puVar1 + 3; puVar6 = (undefined8 *)*puVar6)
        {
          lbfoSetOriginalMacOnNic((longlong)puVar6,puVar6 + 0x61);
        }
      }
    }
  }
  return;
}



===== WPP_SF_DLIL @ 1c000a8a8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DLIL(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_9610058feb5536e51556e6eab0a9e872_Traceguids,0xe,local_res20,4,
             &param_5,4,&param_6,8,&param_7,4,0);
  return;
}



===== WPP_SF_I @ 1c000a91c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_I(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_9610058feb5536e51556e6eab0a9e872_Traceguids,0xc,&local_res20,8,0);
  return;
}



===== WPP_SF_IsDL @ 1c000a968 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_IsDL(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                char *param_5,undefined1 param_6,undefined1 param_7)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 local_res20;
  
  if (param_5 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar2 = lVar1;
      lVar1 = lVar2 + 1;
    } while (param_5[lVar1] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (param_5 == (char *)0x0) {
    param_5 = "NULL";
  }
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_9610058feb5536e51556e6eab0a9e872_Traceguids,0xd,&local_res20,8,
             param_5,lVar2,&param_6,4,&param_7,4,0);
  return;
}



===== WPP_SF_LLdd @ 1c000aa20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_LLdd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_9610058feb5536e51556e6eab0a9e872_Traceguids,0xf,local_res20,4,
             &param_5,4,&param_6,4,&param_7,4,0);
  return;
}



===== WPP_SF_qI @ 1c000aa90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qI(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_9610058feb5536e51556e6eab0a9e872_Traceguids,0x1a,&local_res20,8,
             &param_5,8,0);
  return;
}



===== WPP_SF_qIIId @ 1c000aae8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qIIId(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_9610058feb5536e51556e6eab0a9e872_Traceguids,0x15,&local_res20,8,
             &param_5,8,&param_6,8,&param_7,8,&param_8,4,0);
  return;
}



===== WPP_SF_qSdIddI @ 1c000ab6c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qSdIddI(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                   wchar_t *param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
                   undefined1 param_9,undefined1 param_10)

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
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_9610058feb5536e51556e6eab0a9e872_Traceguids,0x14,&local_res20,8,
             param_5,lVar1,&param_6,4,&param_7,8,&param_8,4,&param_9,4,&param_10,8,0);
  return;
}



===== WPP_SF_qddII @ 1c000ac74 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qddII(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_9610058feb5536e51556e6eab0a9e872_Traceguids,0x16,&local_res20,8,
             &param_5,4,&param_6,4,&param_7,8,&param_8,8,0);
  return;
}



===== WPP_SF_qddiI @ 1c000acfc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qddiI(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_9610058feb5536e51556e6eab0a9e872_Traceguids,0x17,&local_res20,8,
             &param_5,4,&param_6,4,&param_7,8,&param_8,8,0);
  return;
}



===== WPP_SF_qqdi @ 1c000ad84 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqdi(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_9610058feb5536e51556e6eab0a9e872_Traceguids,0x12,&local_res20,8,
             &param_5,8,&param_6,4,&param_7,8,0);
  return;
}



===== lbfoDAddNic @ 1c000ae00 =====

undefined8 lbfoDAddNic(longlong param_1,longlong param_2)

{
  byte bVar1;
  longlong lVar2;
  longlong *plVar3;
  undefined4 *puVar4;
  
  bVar1 = *(byte *)(param_1 + 0xee0);
  lVar2 = *(longlong *)(param_1 + 0xed8);
  puVar4 = (undefined4 *)(((ulonglong)*(byte *)(param_2 + 0x288) + 3) * 0x10 + param_1 + 0x948);
  *(undefined1 *)((longlong)puVar4 + 6) = 1;
  plVar3 = *(longlong **)(param_1 + 0xed8);
  do {
    if (plVar3 == (longlong *)((ulonglong)bVar1 * 0x11 + lVar2)) {
LAB_1c000ae62:
      *puVar4 = *(undefined4 *)(param_2 + 0x28);
      *(undefined2 *)(puVar4 + 1) = *(undefined2 *)(param_2 + 0x2c);
      *(undefined1 *)((longlong)puVar4 + 7) = *(undefined1 *)(*(longlong *)(param_2 + 0x20) + 0x2c);
      return 0;
    }
    if ((*plVar3 == *(longlong *)(param_2 + 0x30)) && (plVar3[1] == *(longlong *)(param_2 + 0x38)))
    {
      *(char *)((longlong)puVar4 + 6) = (char)plVar3[2];
      goto LAB_1c000ae62;
    }
    plVar3 = (longlong *)((longlong)plVar3 + 0x11);
  } while( true );
}



===== lbfoDAddVmsPort @ 1c000ae90 =====

void lbfoDAddVmsPort(longlong param_1,int param_2)

{
  lbfoLBInitialMapVmsPort(param_1,param_2,param_1 + 0xdb0,0x100);
  return;
}



===== lbfoDChangeNicAggregator @ 1c000aec0 =====

void lbfoDChangeNicAggregator(longlong param_1,longlong param_2,undefined8 param_3,longlong param_4)

{
  undefined8 *puVar1;
  
  *(undefined1 *)(param_1 + 0x97f + (ulonglong)*(byte *)(param_2 + 0x288) * 0x10) =
       *(undefined1 *)(param_4 + 0x2c);
  for (puVar1 = *(undefined8 **)(param_2 + 0x2a8); puVar1 != (undefined8 *)(param_2 + 0x2a8);
      puVar1 = (undefined8 *)*puVar1) {
    *(byte *)((longlong)puVar1 + 0x22) = *(byte *)((longlong)puVar1 + 0x22) | 1;
    lbfoQueuePrimeSwitchIfNeededWorkItem(param_1);
  }
  return;
}



===== lbfoDConnectNic @ 1c000af30 =====

void lbfoDConnectNic(longlong param_1,longlong param_2)

{
  longlong lVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  
  bVar2 = *(byte *)(param_2 + 0x288);
  uVar4 = 0;
  lVar1 = (ulonglong)bVar2 + 3;
  if (DAT_1c0018498 != 0) {
    do {
      uVar3 = *(ushort *)(param_1 + 0xec0) * uVar4;
      uVar4 = uVar4 + 1;
      *(undefined8 *)((ulonglong)uVar3 + *(longlong *)(param_1 + 0xd90) + (ulonglong)bVar2 * 8 + -8)
           = 0;
    } while (uVar4 < DAT_1c0018498);
  }
  *(undefined8 *)(param_1 + 0x950 + lVar1 * 0x10) = 0;
  *(short *)(param_1 + 0xec2) =
       *(short *)(param_1 + 0xec2) + (ushort)*(byte *)(param_1 + 0x94e + lVar1 * 0x10);
  *(ulonglong *)(param_1 + 0xd98) =
       *(ulonglong *)(param_1 + 0xd98) | 1L << ((ulonglong)(*(byte *)(param_2 + 0x288) - 1) & 0x3f);
  lbfoDQueueDpc(param_1 + 0x948,1);
  return;
}



===== lbfoDDisconnectNic @ 1c000afd0 =====

void lbfoDDisconnectNic(longlong param_1,longlong param_2)

{
  byte bVar1;
  ushort uVar2;
  longlong lVar3;
  
  bVar1 = *(byte *)(param_2 + 0x288);
  *(ulonglong *)(param_1 + 0xd98) =
       *(ulonglong *)(param_1 + 0xd98) & ~(1L << ((ulonglong)(bVar1 - 1) & 0x3f));
  *(short *)(param_1 + 0xec2) =
       *(short *)(param_1 + 0xec2) - (ushort)*(byte *)(param_1 + 0x97e + (ulonglong)bVar1 * 0x10);
  bVar1 = lbfoDGetNicWithHighestTokenCount(param_1,'\0',0);
  for (uVar2 = 0; uVar2 < *(ushort *)(param_1 + 0xebc); uVar2 = uVar2 + 1) {
    lVar3 = (ulonglong)uVar2 * 0x36 + *(longlong *)(param_1 + 0xd88);
    if (*(char *)(lVar3 + 0x35) == *(char *)(param_2 + 0x288)) {
      *(byte *)(lVar3 + 0x35) = bVar1;
    }
  }
  lbfoDQueueDpc(param_1 + 0x948,1);
  return;
}



===== lbfoDDpcCallback @ 1c000b070 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void lbfoDDpcCallback(undefined8 param_1,longlong param_2,char param_3)

{
  longlong lVar1;
  longlong lVar2;
  ulonglong uVar3;
  longlong lVar4;
  
  if ((*(byte *)(param_2 + 0x5fc) & 1) == 0) {
    lVar1 = _DAT_fffff78000000320;
  }
  else {
    lVar1 = KeQueryPerformanceCounter(0);
  }
  lbfoDResetTokenCounters(param_2,lVar1);
  lVar4 = lVar1 - *(longlong *)(param_2 + 0xed0);
  if ((*(byte *)(param_2 + 0x5fc) & 1) == 0) {
    lVar2 = 0;
    if (-1 < lVar4) {
      lVar2 = lVar4;
    }
    uVar3 = lVar2 * (ulonglong)DAT_1c0018470;
  }
  else {
    lVar2 = 0;
    if (-1 < lVar4) {
      lVar2 = lVar4;
    }
    uVar3 = (lVar2 * 10000000) / DAT_1c0018490;
  }
  if ((*(uint *)(param_2 + 0xeb8) < uVar3) || (param_3 != '\0')) {
    lbfoDRebalanceBuckets(param_2);
  }
  if ((*(byte *)(param_2 + 0x5fc) & 1) == 0) {
    lVar4 = _DAT_fffff78000000320;
  }
  else {
    lVar4 = KeQueryPerformanceCounter(0);
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    lVar4 = lVar4 - lVar1;
    if ((*(byte *)(param_2 + 0x5fc) & 1) == 0) {
      lVar1 = 0;
      if (-1 < lVar4) {
        lVar1 = lVar4;
      }
      uVar3 = lVar1 * (ulonglong)DAT_1c0018470;
    }
    else {
      lVar1 = 0;
      if (-1 < lVar4) {
        lVar1 = lVar4;
      }
      uVar3 = (lVar1 * 10000000) / DAT_1c0018490;
    }
    WPP_SF_qI(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar3 / 10000,WPP_GLOBAL_Control,param_2,
              (char)(uVar3 / 10000));
  }
  *(undefined1 *)(param_2 + 0xee1) = 0;
  return;
}



===== lbfoDGetNicWithHighestTokenCount @ 1c000b1d4 =====

byte lbfoDGetNicWithHighestTokenCount(longlong param_1,char param_2,byte param_3)

{
  ulonglong uVar1;
  ulonglong uVar2;
  longlong lVar3;
  longlong lVar4;
  byte bVar5;
  ulonglong uVar6;
  int iVar7;
  uint uVar8;
  byte bVar9;
  
  bVar9 = 1;
  bVar5 = 0;
  lVar4 = -0x8000000000000000;
  if (*(char *)(param_1 + 0x5fb) != '\0') {
    do {
      uVar6 = 0;
      if ((*(ulonglong *)(param_1 + 0xd98) >> ((ulonglong)(bVar9 - 1 & 0xff) & 0x3f) & 1) != 0) {
        lVar3 = (ulonglong)bVar9 - 1;
        uVar1 = 0x400;
        if (*(char *)(param_1 + 0x98f + lVar3 * 0x10) != param_2) {
          uVar1 = uVar6;
        }
        uVar2 = uVar1 + 0x400;
        if (bVar9 != param_3) {
          uVar2 = uVar1;
        }
        if (DAT_1c0018498 != 0) {
          do {
            iVar7 = (int)uVar6;
            uVar8 = iVar7 + 1;
            uVar6 = (ulonglong)uVar8;
            uVar2 = uVar2 + *(longlong *)
                             ((ulonglong)((uint)*(ushort *)(param_1 + 0xec0) * iVar7) + lVar3 * 8 +
                             *(longlong *)(param_1 + 0xd90));
          } while (uVar8 < DAT_1c0018498);
        }
        lVar3 = uVar2 - *(longlong *)(param_1 + 0x990 + lVar3 * 0x10);
        if (lVar4 < lVar3) {
          lVar4 = lVar3;
          bVar5 = bVar9;
        }
      }
      bVar9 = bVar9 + 1;
    } while (bVar9 <= *(byte *)(param_1 + 0x5fb));
  }
  return bVar5;
}



===== lbfoDGetOutgoingNicId @ 1c000b2e0 =====

byte lbfoDGetOutgoingNicId(longlong param_1,longlong param_2,longlong param_3)

{
  longlong lVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  ushort uVar7;
  longlong lVar8;
  uint uVar9;
  byte local_res8 [8];
  
  lVar1 = *(longlong *)(param_1 + 0x10);
  local_res8[0] = 0;
  uVar4 = lbfoLBGetNblHash(param_2,0,local_res8);
  bVar3 = local_res8[0];
  uVar9 = 0;
  for (puVar6 = *(undefined8 **)(param_2 + 8); puVar6 != (undefined8 *)0x0;
      puVar6 = (undefined8 *)*puVar6) {
    uVar9 = uVar9 + *(int *)(puVar6 + 3);
  }
  *(ulonglong *)(param_2 + 0x70) =
       ((ulonglong)uVar9 << 8 | *(ulonglong *)(param_2 + 0x70) & 0xfffffe00000000ff) ^
       ((ulonglong)local_res8[0] & 1) << 0x28;
  bVar2 = lbfoLBGetMappedNicId
                    (param_1,param_2,(char *)(*(longlong *)(param_1 + 0x10) + 0xdb0),0x100);
  if (bVar3 == 0) {
    uVar7 = *(ushort *)(lVar1 + 0xebe) & (ushort)uVar4;
    lVar8 = (ulonglong)uVar7 * 0x36 + *(longlong *)(lVar1 + 0xd88);
    uVar5 = lbfoDUpdateBucketStats(lVar1,uVar7,*(ulonglong *)(param_2 + 0x70) >> 8,param_3);
    if ((char)uVar5 != '\0') {
      bVar3 = lbfoDGetNicWithHighestTokenCount
                        (lVar1,*(char *)(lVar1 + 0x97f + (ulonglong)bVar2 * 0x10),
                         *(byte *)(lVar8 + 0x35));
      *(byte *)(lVar8 + 0x35) = bVar3;
    }
    bVar2 = *(byte *)(lVar8 + 0x35);
  }
  return bVar2;
}



===== lbfoDGetSwitchPrimingNbls @ 1c000b410 =====

void lbfoDGetSwitchPrimingNbls(longlong param_1,longlong param_2,undefined8 param_3)

{
  byte *pbVar1;
  
  pbVar1 = (byte *)(*(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x10) + 0x650) + 0x40) +
                   0x52);
  *pbVar1 = *pbVar1 | 1;
  lbfoLBGetSwitchPrimingNbls(param_1,param_2,param_3);
  return;
}



===== lbfoDMoveBucket @ 1c000b438 =====

longlong lbfoDMoveBucket(longlong param_1,longlong param_2,longlong param_3,longlong param_4)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  ulonglong uVar4;
  longlong lVar5;
  int iVar6;
  
  *(longlong *)(param_3 + 0x318) = *(longlong *)(param_3 + 0x318) - *(longlong *)(param_2 + 0x20);
  *(longlong *)(param_4 + 0x318) = *(longlong *)(param_4 + 0x318) + *(longlong *)(param_2 + 0x20);
  lVar1 = *(longlong *)(param_3 + 800);
  lVar2 = *(longlong *)(param_4 + 800);
  iVar6 = (uint)*(byte *)(param_1 + 0x36 + (ulonglong)*(byte *)(param_3 + 0x288) * 0x10) *
          *(int *)(param_1 + 0x458) - (uint)*(ushort *)(param_1 + 0x57a) * *(int *)(param_3 + 0x318)
  ;
  iVar3 = -iVar6;
  if (iVar3 < 0) {
    iVar3 = iVar6;
  }
  uVar4 = ((longlong)iVar3 * (*(ulonglong *)(param_1 + 0x460) / 10000)) /
          ((ulonglong)*(ushort *)(param_1 + 0x57a) * 1000) >> 4;
  *(ulonglong *)(param_3 + 800) = uVar4 * uVar4;
  iVar6 = (uint)*(byte *)(param_1 + 0x36 + (ulonglong)*(byte *)(param_4 + 0x288) * 0x10) *
          *(int *)(param_1 + 0x458) - (uint)*(ushort *)(param_1 + 0x57a) * *(int *)(param_4 + 0x318)
  ;
  iVar3 = -iVar6;
  if (iVar3 < 0) {
    iVar3 = iVar6;
  }
  uVar4 = ((longlong)iVar3 * (*(ulonglong *)(param_1 + 0x460) / 10000)) /
          ((ulonglong)*(ushort *)(param_1 + 0x57a) * 1000) >> 4;
  lVar5 = uVar4 * uVar4;
  *(longlong *)(param_4 + 800) = lVar5;
  return ((lVar1 + lVar2) - *(longlong *)(param_3 + 800)) - lVar5;
}



===== lbfoDPrepareForSend @ 1c000b580 =====

ulonglong lbfoDPrepareForSend(longlong param_1,longlong param_2,byte param_3,longlong param_4)

{
  longlong lVar1;
  byte bVar2;
  uint uVar3;
  ulonglong uVar4;
  longlong lVar5;
  undefined4 *puVar6;
  undefined4 local_res8;
  undefined2 local_resc;
  
  lVar1 = *(longlong *)(param_1 + 0x10);
  uVar3 = NdisAllocateNetBufferListContext(param_2,0x10,*(undefined2 *)(param_1 + 0x48),0x5463694e);
  uVar4 = (ulonglong)uVar3;
  if (uVar3 == 0) {
    lVar5 = *(longlong *)(param_2 + 0x10) + 0x10 +
            (ulonglong)*(ushort *)(*(longlong *)(param_2 + 0x10) + 10);
    *(undefined1 *)(lVar5 + 8) = 0;
    if (((*(byte *)(param_1 + 0xcc) & 2) != 0) &&
       (*(undefined2 *)
         ((ulonglong)*(ushort *)(*(longlong *)(param_2 + 0x10) + 10) + 0x16 +
         *(longlong *)(param_2 + 0x10)) = *(undefined2 *)(param_2 + 0x102),
       *(int *)(lVar1 + 0x570) != 0)) {
      *(undefined2 *)(param_2 + 0x102) =
           *(undefined2 *)
            (*(longlong *)(lVar1 + 0x578) +
            ((ulonglong)(*(byte *)((ulonglong)param_3 + 0x89 + param_1) - 1) +
            (ulonglong)*(ushort *)(param_2 + 0x102) * 0x15a) * 4);
    }
    puVar6 = (undefined4 *)(((ulonglong)param_3 + 3) * 0x10 + lVar1 + 0x948);
    bVar2 = lbfoLBGetMappedNicId
                      (param_1,param_2,(char *)(*(longlong *)(param_1 + 0x10) + 0xdb0),0x100);
    if (*(char *)((longlong)puVar6 + 7) != *(char *)(lVar1 + 0x97f + (ulonglong)bVar2 * 0x10)) {
      local_res8 = *puVar6;
      local_resc = *(undefined2 *)(puVar6 + 1);
      uVar4 = lbfoLBReplaceNblMacAddress(param_2,&local_res8);
      uVar4 = uVar4 & 0xffffffff;
    }
    lbfoDUpdateTokenCounters
              (lVar1,(int)((ulonglong)*(undefined8 *)(param_2 + 0x70) >> 8),param_3,param_4);
    if (((int)uVar4 != 0) && (lVar5 != 0)) {
      NdisFreeNetBufferListContext(param_2,0x10);
    }
  }
  else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_ds(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
              &WPP_9610058feb5536e51556e6eab0a9e872_Traceguids,uVar3,
              "NdisAllocateNetBufferListContext(Nbl, sizeof(LBFO_NBL_CONTEXT), FilterContext->NblContextBackfill, LBFO_POOLTAG)"
             );
  }
  return uVar4;
}



===== lbfoDQueueDpc @ 1c000b744 =====

bool lbfoDQueueDpc(longlong param_1,undefined1 param_2)

{
  char cVar1;
  
  if (*(char *)(param_1 + 0x599) == '\0') {
    LOCK();
    cVar1 = *(char *)(param_1 + 0x599);
    *(char *)(param_1 + 0x599) = '\x01';
    UNLOCK();
    if (cVar1 == '\0') {
      cVar1 = KeInsertQueueDpc(param_1,param_2,0);
      return cVar1 != '\0';
    }
  }
  return false;
}



===== lbfoDRebalanceBuckets @ 1c000b788 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void lbfoDRebalanceBuckets(longlong param_1)

{
  undefined8 *puVar1;
  longlong *plVar2;
  undefined8 uVar3;
  code *pcVar4;
  undefined1 auVar5 [16];
  int iVar6;
  longlong lVar7;
  ulonglong uVar8;
  undefined8 *puVar9;
  ulonglong uVar10;
  int iVar11;
  longlong lVar12;
  uint uVar13;
  undefined8 *puVar14;
  byte bVar15;
  undefined1 *puVar16;
  undefined1 *puVar17;
  byte bVar18;
  undefined *puVar19;
  ulonglong uVar20;
  longlong *plVar21;
  ulonglong uVar22;
  ushort uVar23;
  ulonglong uVar24;
  ushort uVar25;
  ushort uVar26;
  ulonglong uVar27;
  undefined1 auStackY_128 [8];
  undefined1 auStackY_120 [24];
  ushort local_d8 [2];
  undefined2 local_d4;
  undefined1 local_d2;
  longlong local_d0;
  ulonglong local_c8;
  ulonglong local_c0;
  undefined1 local_b8 [8];
  longlong local_b0 [15];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_128;
  local_d0 = 0;
  local_d4 = 0;
  local_d2 = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
             &WPP_9610058feb5536e51556e6eab0a9e872_Traceguids,param_1);
  }
  NdisAcquireRWLockRead(*(undefined8 *)(param_1 + 0x5e8),&local_d4);
  if ((*(byte *)(param_1 + 0x5fc) & 1) == 0) {
    lVar7 = _DAT_fffff78000000320;
  }
  else {
    lVar7 = KeQueryPerformanceCounter(0);
  }
  puVar16 = auStackY_128;
  uVar27 = *(ulonglong *)(param_1 + 0xed0);
  *(longlong *)(param_1 + 0xed0) = lVar7;
  lVar7 = lVar7 - uVar27;
  if ((*(byte *)(param_1 + 0x5fc) & 1) == 0) {
    lVar12 = 0;
    if (-1 < lVar7) {
      lVar12 = lVar7;
    }
    uVar8 = lVar12 * (ulonglong)DAT_1c0018470;
  }
  else {
    lVar12 = 0;
    if (-1 < lVar7) {
      lVar12 = lVar7;
    }
    uVar8 = (lVar12 * 10000000) / DAT_1c0018490;
  }
  puVar14 = (undefined8 *)(param_1 + 0x8d8);
  *(ulonglong *)(param_1 + 0xda8) = uVar8;
  uVar20 = (ulonglong)(uint)(*(int *)(param_1 + 0xeb8) * 2);
  for (puVar9 = (undefined8 *)*puVar14; puVar9 != puVar14; puVar9 = (undefined8 *)*puVar9) {
    puVar1 = puVar9 + 0x5f;
    puVar9[0x61] = 0;
    puVar9[0x60] = puVar1;
    *puVar1 = puVar1;
  }
  uVar26 = 0;
  local_d8[0] = 0;
  uVar25 = 0;
  *(undefined8 *)(param_1 + 0xda0) = 0;
  lVar7 = 0;
  local_c8 = uVar20;
  local_c0 = uVar27;
  if (*(short *)(param_1 + 0xebc) != 0) {
    do {
      uVar10 = 0;
      plVar21 = (longlong *)((ulonglong)uVar25 * 0x36 + *(longlong *)(param_1 + 0xd88));
      uVar24 = uVar10;
      uVar22 = uVar10;
      if (DAT_1c0018498 != 0) {
        do {
          iVar6 = (int)uVar10;
          uVar13 = iVar6 + 1;
          uVar10 = (ulonglong)uVar13;
          lVar7 = (ulonglong)((uint)*(ushort *)(param_1 + 0xec0) * iVar6) + (ulonglong)uVar25 * 0xc;
          uVar24 = uVar24 + *(longlong *)(lVar7 + 0x200 + *(longlong *)(param_1 + 0xd90));
          uVar22 = (ulonglong)
                   (uint)((int)uVar22 + *(int *)(lVar7 + 0x208 + *(longlong *)(param_1 + 0xd90)));
        } while (uVar13 < DAT_1c0018498);
        uVar27 = local_c0;
        uVar20 = local_c8;
      }
      if (uVar8 < uVar20) {
        puVar14 = (undefined8 *)((plVar21[4] + (uVar24 - plVar21[3]) * 4) / 5);
      }
      else {
        puVar14 = (undefined8 *)0x0;
      }
      plVar21[4] = (longlong)puVar14;
      uVar13 = (int)uVar22 - (int)plVar21[6];
      plVar21[3] = uVar24;
      if (uVar13 <= *(byte *)(param_1 + 0xec5)) {
        *(undefined1 *)((longlong)plVar21 + 0x34) = 1;
      }
      *(int *)(plVar21 + 6) = (int)uVar22;
      puVar19 = (undefined *)0x0;
      if (((longlong)uVar27 < plVar21[2]) && (puVar14 != (undefined8 *)0x0)) {
        bVar15 = *(byte *)((longlong)plVar21 + 0x35);
        uVar20 = (ulonglong)bVar15;
        if ((bVar15 == 0) ||
           ((lVar7 = *(longlong *)(param_1 + 0x658 + uVar20 * 8), lVar7 == 0 ||
            (*(char *)((longlong)plVar21 + 0x34) != '\x01')))) {
          uVar20 = plVar21[4];
          local_d0 = local_d0 + uVar20;
        }
        else {
          uVar26 = uVar26 + 1;
          *(longlong *)(param_1 + 0xda0) = *(longlong *)(param_1 + 0xda0) + plVar21[4];
          *(longlong *)(lVar7 + 0x318) = *(longlong *)(lVar7 + 0x318) + plVar21[4];
          plVar2 = *(longlong **)(lVar7 + 0x310);
          local_d8[0] = uVar26;
          if (*plVar2 != lVar7 + 0x308) {
            uVar24 = 0;
            pcVar4 = (code *)swi(0x29);
            (*pcVar4)();
            puVar16 = auStackY_120;
            goto LAB_1c000bb4c;
          }
          *plVar21 = lVar7 + 0x308;
          plVar21[1] = (longlong)plVar2;
          *plVar2 = (longlong)plVar21;
          *(longlong **)(lVar7 + 0x310) = plVar21;
          uVar20 = plVar21[4];
          uVar24 = (*(ulonglong *)(param_1 + 0xda8) / 10000) * uVar20 * 2;
          auVar5._8_8_ = 0;
          auVar5._0_8_ = uVar24;
          puVar14 = SUB168(ZEXT816(0x624dd2f1a9fbe77) * auVar5,8);
          plVar21[5] = ((uVar24 - (longlong)puVar14 >> 1) + (longlong)puVar14 >> 9) + 0x2000;
        }
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          puVar14 = (undefined8 *)(ulonglong)*(byte *)((longlong)plVar21 + 0x34);
          WPP_SF_qSdIddI(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),puVar14,
                         (ulonglong)plVar21[5] >> 10,param_1,
                         (wchar_t *)(&BucketClassString)[(longlong)puVar14],(char)uVar25,
                         (char)(uVar20 >> 10),(char)uVar13,bVar15,
                         (char)((ulonglong)plVar21[5] >> 10));
        }
        uVar20 = local_c8;
      }
      uVar25 = uVar25 + 1;
    } while (uVar25 < *(ushort *)(param_1 + 0xebc));
    lVar7 = local_d0;
  }
  uVar24 = *(longlong *)(param_1 + 0xda0) + lVar7;
  uVar27 = 0;
  puVar17 = auStackY_128;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (puVar17 = auStackY_128, 4 < (byte)WPP_GLOBAL_Control[0x29])) {
    puVar19 = WPP_GLOBAL_Control;
    if (uVar24 == 0) {
LAB_1c000bb4c:
      puVar17 = puVar16;
      uVar22 = uVar27;
      uVar10 = uVar27;
    }
    else {
      uVar10 = *(longlong *)(param_1 + 0xda0) * 100;
      puVar14 = (undefined8 *)(uVar10 % uVar24);
      puVar17 = auStackY_128;
      uVar22 = (ulonglong)(lVar7 * 100) / uVar24;
      uVar10 = uVar10 / uVar24;
    }
    *(uint *)(puVar17 + 0x38) = (uint)uVar26;
    *(ulonglong *)(puVar17 + 0x30) = uVar10;
    *(ulonglong *)(puVar17 + 0x28) = uVar22;
    *(ulonglong *)(puVar17 + 0x20) = uVar24 >> 10;
    uVar3 = *(undefined8 *)(puVar19 + 0x18);
    *(undefined8 *)(puVar17 + -8) = 0x1c000bb79;
    WPP_SF_qIIId(uVar3,puVar14,puVar19,param_1,puVar17[0x20],puVar17[0x28],puVar17[0x30],
                 puVar17[0x38]);
  }
  if (((uVar8 < uVar20) && (uVar26 != 0)) && (*(ulonglong *)(param_1 + 0xda0) != uVar27)) {
    plVar21 = *(longlong **)(param_1 + 0x8d8);
    if (plVar21 != (longlong *)(param_1 + 0x8d8)) {
      do {
        bVar15 = *(byte *)(plVar21 + 0x4f);
        iVar11 = (uint)*(byte *)(param_1 + 0x97e + (ulonglong)bVar15 * 0x10) *
                 *(int *)(param_1 + 0xda0) - (uint)*(ushort *)(param_1 + 0xec2) * (int)plVar21[0x61]
        ;
        iVar6 = -iVar11;
        if (iVar6 < 0) {
          iVar6 = iVar11;
        }
        uVar8 = ((longlong)iVar6 * (*(ulonglong *)(param_1 + 0xda8) / 10000)) /
                ((ulonglong)*(ushort *)(param_1 + 0xec2) * 1000) >> 4;
        uVar8 = uVar8 * uVar8;
        plVar21[0x62] = uVar8;
        uVar27 = uVar27 + uVar8;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar20 = plVar21[0x61];
          bVar18 = *(byte *)(param_1 + 0x97e + (ulonglong)bVar15 * 0x10);
          uVar3 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
          *(ulonglong *)(puVar17 + 0x38) = uVar8 >> 10;
          *(ulonglong *)(puVar17 + 0x30) = uVar20 >> 10;
          *(uint *)(puVar17 + 0x28) = (uint)bVar18;
          *(uint *)(puVar17 + 0x20) = (uint)bVar15;
          *(undefined8 *)(puVar17 + -8) = 0x1c000bc81;
          WPP_SF_qddII(uVar3,uVar20 >> 10,uVar8 >> 10,param_1,puVar17[0x20],puVar17[0x28],
                       puVar17[0x30],puVar17[0x38]);
        }
        plVar21 = (longlong *)*plVar21;
      } while (plVar21 != (longlong *)(param_1 + 0x8d8));
      uVar26 = local_d8[0];
    }
    uVar25 = *(short *)(param_1 + 0x8ec) - 1;
    uVar23 = 1;
    uVar24 = 1;
    uVar20 = (ulonglong)(int)((uint)uVar26 * (uint)uVar25);
    uVar8 = uVar20;
    for (bVar15 = 1; (1 < uVar26 && (bVar15 < 5)); bVar15 = bVar15 + 1) {
      uVar23 = uVar23 + 1;
      uVar26 = uVar26 - 1;
      uVar24 = uVar24 * uVar23;
      uVar8 = uVar8 * (ulonglong)uVar26 * (ulonglong)uVar25;
      uVar20 = uVar20 + uVar8 / uVar24;
      if ((ulonglong)
          (longlong)
          ((int)((uint)*(ushort *)(param_1 + 0xebc) * (uint)*(ushort *)(param_1 + 0xebc) *
                 (uint)uVar25 * (uint)uVar25) / 2) < uVar20) break;
    }
    lVar7 = *(longlong *)(param_1 + 0x8d8);
    local_d8[0] = CONCAT11(local_d8[0]._1_1_,bVar15 + 1);
    *(undefined1 **)(puVar17 + 0x38) = local_b8;
    local_d0 = 0;
    *(longlong *)(puVar17 + 0x30) = lVar7 + 0x2f8;
    *(longlong *)(puVar17 + 0x28) = lVar7 + -0x10;
    *(ushort **)(puVar17 + 0x20) = local_d8;
    *(undefined8 *)(puVar17 + -8) = 0x1c000bd6e;
    lbfoDSearchHelper(param_1,0,bVar15,&local_d0,*(byte **)(puVar17 + 0x20),
                      *(undefined8 **)(puVar17 + 0x28),*(undefined8 **)(puVar17 + 0x30),
                      *(undefined8 **)(puVar17 + 0x38));
    lVar7 = local_d0;
    bVar18 = (bVar15 - (char)local_d8[0]) + 1;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      *(ulonglong *)(puVar17 + 0x38) = uVar27 >> 10;
      uVar27 = (ulonglong)((uint)(local_d0 >> 0x3f) & 0x3ff);
      *(longlong *)(puVar17 + 0x30) = (longlong)(local_d0 + uVar27) >> 10;
      *(uint *)(puVar17 + 0x28) = (uint)bVar18;
      *(uint *)(puVar17 + 0x20) = (uint)bVar15;
      uVar3 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
      *(undefined8 *)(puVar17 + -8) = 0x1c000bdd2;
      WPP_SF_qddiI(uVar3,uVar27,(ulonglong)bVar18,param_1,puVar17[0x20],puVar17[0x28],puVar17[0x30],
                   puVar17[0x38]);
    }
    if ((0 < lVar7) && (bVar18 != 0)) {
      plVar21 = local_b0;
      uVar27 = (ulonglong)bVar18;
      do {
        uVar13 = (int)(plVar21[1] - *(longlong *)(param_1 + 0xd88) >> 1) * 0x684bda13;
        if (*(char *)(plVar21[1] + 0x34) == '\x01') {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (4 < (byte)WPP_GLOBAL_Control[0x29])) {
            lVar7 = plVar21[-1];
            *(uint *)(puVar17 + 0x30) = (uint)*(byte *)(*plVar21 + 0x288);
            *(uint *)(puVar17 + 0x28) = (uint)*(byte *)(lVar7 + 0x288);
            uVar3 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
            *(uint *)(puVar17 + 0x20) = uVar13 & 0xffff;
            *(undefined8 *)(puVar17 + -8) = 0x1c000be69;
            WPP_SF_qddd(uVar3,0x18,&WPP_9610058feb5536e51556e6eab0a9e872_Traceguids,param_1,
                        puVar17[0x20],puVar17[0x28],puVar17[0x30]);
          }
          *(undefined1 *)(plVar21[1] + 0x35) = *(undefined1 *)(*plVar21 + 0x288);
        }
        else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar3 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
          *(uint *)(puVar17 + 0x20) = uVar13 & 0xffff;
          *(undefined8 *)(puVar17 + -8) = 0x1c000beac;
          WPP_SF_qL(uVar3,0x19,&WPP_9610058feb5536e51556e6eab0a9e872_Traceguids,param_1,
                    puVar17[0x20]);
        }
        plVar21 = plVar21 + 3;
        uVar27 = uVar27 - 1;
      } while (uVar27 != 0);
    }
  }
  uVar3 = *(undefined8 *)(param_1 + 0x5e8);
  *(undefined8 *)(puVar17 + -8) = 0x1c000bed2;
  NdisReleaseRWLock(uVar3,&local_d4);
  *(undefined8 *)(puVar17 + -8) = 0x1c000bee3;
  return;
}



===== lbfoDRebalanceCfgMacs @ 1c000bf10 =====

void lbfoDRebalanceCfgMacs(longlong param_1)

{
  lbfoLBRebalanceCfgMacs(param_1,param_1 + 0xdb0,0x100);
  return;
}



===== lbfoDRemoveNic @ 1c000bf40 =====

void lbfoDRemoveNic(longlong param_1,longlong param_2)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)(param_1 + 0x978 + (ulonglong)*(byte *)(param_2 + 0x288) * 0x10);
  *puVar1 = 0;
  puVar1[1] = 0;
  return;
}



===== lbfoDRemoveVmsPort @ 1c000bf60 =====

void lbfoDRemoveVmsPort(longlong param_1,uint param_2)

{
  if (param_2 < 0x100) {
    *(undefined1 *)((ulonglong)param_2 + 0xdb0 + param_1) = 0;
  }
  return;
}



===== lbfoDResetTokenCounters @ 1c000bf7c =====

void lbfoDResetTokenCounters(longlong param_1,longlong param_2)

{
  int iVar1;
  ulonglong uVar2;
  longlong lVar3;
  uint uVar4;
  longlong lVar5;
  uint uVar6;
  longlong lVar7;
  byte bVar8;
  ulonglong uVar9;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
             &WPP_9610058feb5536e51556e6eab0a9e872_Traceguids,param_1);
  }
  lVar5 = param_2 - *(longlong *)(param_1 + 0xec8);
  if ((*(byte *)(param_1 + 0x5fc) & 1) == 0) {
    lVar7 = 0;
    if (-1 < lVar5) {
      lVar7 = lVar5;
    }
    uVar2 = lVar7 * (ulonglong)DAT_1c0018470;
  }
  else {
    lVar7 = 0;
    if (-1 < lVar5) {
      lVar7 = lVar5;
    }
    uVar2 = (lVar7 * 10000000) / DAT_1c0018490;
  }
  iVar1 = *(int *)(param_1 + 0xeb4);
  uVar9 = 1;
  *(longlong *)(param_1 + 0xec8) = param_2;
  if (*(char *)(param_1 + 0x5fb) != '\0') {
    do {
      if ((*(ulonglong *)(param_1 + 0xd98) >> ((ulonglong)((int)uVar9 - 1U & 0xff) & 0x3f) & 1) != 0
         ) {
        lVar5 = 0;
        uVar6 = 0;
        if (DAT_1c0018498 != 0) {
          do {
            uVar4 = *(ushort *)(param_1 + 0xec0) * uVar6;
            uVar6 = uVar6 + 1;
            lVar5 = lVar5 + *(longlong *)
                             ((ulonglong)uVar4 + uVar9 * 8 + -8 + *(longlong *)(param_1 + 0xd90));
          } while (uVar6 < DAT_1c0018498);
        }
        lVar7 = (uVar9 + 3) * 0x10 + param_1 + 0x948;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          lVar3 = lVar5 - *(longlong *)(lVar7 + 8);
          WPP_SF_qqdi(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar9,uVar9,param_1,
                      (char)*(undefined8 *)(param_1 + 0x658 + uVar9 * 8),(char)uVar9,
                      (char)((longlong)(lVar3 + (ulonglong)((uint)(lVar3 >> 0x3f) & 0x3ff)) >> 10));
        }
        if (uVar2 < (uint)(iVar1 * 2)) {
          *(longlong *)(lVar7 + 8) = (lVar5 * 0x400 + *(longlong *)(lVar7 + 8)) / 0x401;
        }
        else {
          *(longlong *)(lVar7 + 8) = lVar5;
        }
      }
      bVar8 = (char)uVar9 + 1;
      uVar9 = (ulonglong)bVar8;
    } while (bVar8 <= *(byte *)(param_1 + 0x5fb));
  }
  return;
}



===== lbfoDSearchHelper @ 1c000c154 =====

void lbfoDSearchHelper(longlong param_1,longlong param_2,byte param_3,longlong *param_4,
                      byte *param_5,undefined8 *param_6,undefined8 *param_7,undefined8 *param_8)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  byte bVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  
  puVar2 = (undefined8 *)(param_1 + 0x8d8);
  puVar7 = (undefined8 *)*param_7;
  while( true ) {
    for (; puVar7 != param_6 + 0x61; puVar7 = (undefined8 *)*puVar7) {
      for (puVar6 = (undefined8 *)*puVar2; puVar1 = puVar6 + -2, puVar6 != puVar2;
          puVar6 = (undefined8 *)*puVar6) {
        if (param_6 != puVar1) {
          lVar4 = *param_4;
          bVar3 = *param_5;
          lVar5 = lbfoDMoveBucket(param_1 + 0x948,(longlong)puVar7,(longlong)param_6,
                                  (longlong)puVar1);
          lVar5 = (lVar5 + param_2) - puVar7[5];
          if ((lVar4 < lVar5) || ((lVar5 == lVar4 && (bVar3 < param_3)))) {
            *param_4 = lVar5;
            *param_5 = param_3;
          }
          if (1 < param_3) {
            lbfoDSearchHelper(param_1,lVar5,param_3 - 1,param_4,param_5,param_6,puVar7,param_8 + 3);
          }
          if ((lVar4 < *param_4) || (bVar3 < *param_5)) {
            param_8[2] = puVar7;
            *param_8 = param_6;
            param_8[1] = puVar1;
          }
          lbfoDMoveBucket(param_1 + 0x948,(longlong)puVar7,(longlong)puVar1,(longlong)param_6);
        }
      }
    }
    puVar7 = (undefined8 *)param_6[2];
    param_6 = puVar7 + -2;
    if (puVar7 == puVar2) break;
    puVar7 = (undefined8 *)puVar7[0x5f];
  }
  return;
}



===== lbfoDSendComplete @ 1c000c2f0 =====

void lbfoDSendComplete(longlong param_1,longlong param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  undefined4 local_res8;
  undefined2 local_resc;
  
  if ((*(byte *)(param_1 + 0xcc) & 2) != 0) {
    *(undefined2 *)(param_2 + 0x102) =
         *(undefined2 *)
          ((ulonglong)*(ushort *)(*(longlong *)(param_2 + 0x10) + 10) + 0x16 +
          *(longlong *)(param_2 + 0x10));
  }
  lVar1 = *(longlong *)(param_2 + 0x10);
  uVar2 = (ulonglong)*(ushort *)(lVar1 + 10);
  if (*(char *)(uVar2 + 0x18 + lVar1) != '\0') {
    local_res8 = *(undefined4 *)(uVar2 + 0x10 + lVar1);
    local_resc = *(undefined2 *)(uVar2 + 0x14 + lVar1);
    lbfoLBRevertMacAddress(*(longlong **)(param_2 + 8),(longlong *)0x0,&local_res8);
  }
  NdisFreeNetBufferListContext(param_2,0x10);
  return;
}



===== lbfoDUpdateBucketStats @ 1c000c368 =====

undefined8
lbfoDUpdateBucketStats(longlong param_1,ushort param_2,ulonglong param_3,longlong param_4)

{
  longlong *plVar1;
  int *piVar2;
  longlong lVar3;
  longlong lVar4;
  ulonglong uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  longlong lVar9;
  undefined1 uVar10;
  ulonglong uVar11;
  longlong lVar12;
  longlong lVar13;
  bool bVar14;
  
  lVar3 = *(longlong *)(param_1 + 0xd90);
  lVar13 = (ulonglong)param_2 * 0xc;
  lVar12 = (ulonglong)param_2 * 0x36 + *(longlong *)(param_1 + 0xd88);
  lVar9 = (ulonglong)((uint)*(ushort *)(param_1 + 0xec0) * SystemReserved1[0x12]._4_4_) + lVar13;
  uVar10 = 0;
  iVar8 = 0;
  uVar5 = 0;
  lVar4 = *(longlong *)(lVar12 + 0x10);
  if (lVar4 < param_4) {
    LOCK();
    bVar14 = lVar4 == *(longlong *)(lVar12 + 0x10);
    if (bVar14) {
      *(longlong *)(lVar12 + 0x10) = param_4;
    }
    UNLOCK();
    if (bVar14) {
      uVar11 = param_4 - lVar4;
      if ((*(byte *)(param_1 + 0x5fc) & 1) == 0) {
        if (-1 < (longlong)uVar11) {
          uVar5 = uVar11;
        }
        uVar5 = uVar5 * DAT_1c0018470;
      }
      else {
        uVar5 = 0;
        if (-1 < (longlong)uVar11) {
          uVar5 = uVar11;
        }
        uVar5 = (longlong)(uVar5 * 10000000) / DAT_1c0018490;
      }
    }
  }
  plVar1 = (longlong *)(lVar9 + 0x200 + lVar3);
  *plVar1 = *plVar1 + (param_3 & 0xffffffff);
  if (uVar5 < *(uint *)(param_1 + 0xeb0)) {
LAB_1c000c48d:
    uVar11 = *(ulonglong *)(param_1 + 0xd98);
    if ((uVar11 >> ((ulonglong)(*(byte *)(lVar12 + 0x35) - 1 & 0xff) & 0x3f) & 1) != 0)
    goto LAB_1c000c4a7;
  }
  else {
    uVar11 = (ulonglong)*(uint *)(param_1 + 0xeb4);
    if (uVar5 < uVar11) {
      piVar2 = (int *)(lVar9 + 0x208 + lVar3);
      *piVar2 = *piVar2 + 1;
      uVar7 = 0;
      if (DAT_1c0018498 != 0) {
        do {
          uVar6 = *(ushort *)(param_1 + 0xec0) * uVar7;
          uVar7 = uVar7 + 1;
          iVar8 = iVar8 + *(int *)((ulonglong)uVar6 + *(longlong *)(param_1 + 0xd90) + 0x208 +
                                  lVar13);
        } while (uVar7 < DAT_1c0018498);
      }
      uVar11 = 0;
      if ((uint)*(byte *)(param_1 + 0xec4) <= (uint)(iVar8 - *(int *)(lVar12 + 0x30))) {
        *(undefined1 *)(lVar12 + 0x34) = 0;
      }
      if (*(char *)(lVar12 + 0x34) != '\0') goto LAB_1c000c48d;
    }
    else {
      *(undefined1 *)(lVar12 + 0x34) = 0;
    }
  }
  uVar10 = 1;
LAB_1c000c4a7:
  return CONCAT71((int7)(uVar11 >> 8),uVar10);
}



===== lbfoDUpdateTokenCounters @ 1c000c4c8 =====

void lbfoDUpdateTokenCounters(longlong param_1,int param_2,byte param_3,longlong param_4)

{
  ulonglong uVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong lVar4;
  byte bVar5;
  
  bVar5 = 1;
  if (*(char *)(param_1 + 0x5fb) != '\0') {
    do {
      if ((*(ulonglong *)(param_1 + 0xd98) >> ((ulonglong)(bVar5 - 1 & 0xff) & 0x3f) & 1) != 0) {
        plVar2 = (longlong *)
                 ((ulonglong)(SystemReserved1[0x12]._4_4_ * (uint)*(ushort *)(param_1 + 0xec0)) +
                  ((ulonglong)bVar5 - 1) * 8 + *(longlong *)(param_1 + 0xd90));
        *plVar2 = *plVar2 + (ulonglong)
                            ((uint)*(byte *)(param_1 + 0x98e + ((ulonglong)bVar5 - 1) * 0x10) *
                            param_2);
      }
      bVar5 = bVar5 + 1;
    } while (bVar5 <= *(byte *)(param_1 + 0x5fb));
  }
  plVar2 = (longlong *)
           ((ulonglong)(SystemReserved1[0x12]._4_4_ * (uint)*(ushort *)(param_1 + 0xec0)) +
            (ulonglong)param_3 * 8 + -8 + *(longlong *)(param_1 + 0xd90));
  *plVar2 = *plVar2 - (ulonglong)((uint)*(ushort *)(param_1 + 0xec2) * param_2);
  lVar4 = param_4 - *(longlong *)(param_1 + 0xec8);
  if ((*(byte *)(param_1 + 0x5fc) & 1) == 0) {
    lVar3 = 0;
    if (-1 < lVar4) {
      lVar3 = lVar4;
    }
    uVar1 = lVar3 * (ulonglong)DAT_1c0018470;
  }
  else {
    lVar3 = 0;
    if (-1 < lVar4) {
      lVar3 = lVar4;
    }
    uVar1 = (lVar3 * 10000000) / DAT_1c0018490;
  }
  if (*(uint *)(param_1 + 0xeb4) < uVar1) {
    lbfoDQueueDpc(param_1 + 0x948,0);
  }
  return;
}



===== lbfoDUpdateVmsPort @ 1c000c5f0 =====

void lbfoDUpdateVmsPort(longlong param_1,uint param_2)

{
  if (param_2 < 0x100) {
    *(undefined1 *)((ulonglong)param_2 + 0xdb0 + param_1) = 0;
  }
  lbfoLBInitialMapVmsPort(param_1,param_2,param_1 + 0xdb0,0x100);
  return;
}



===== WPP_SF__MAC_dd @ 1c000c624 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void WPP_SF__MAC_dd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 *param_4,
                   undefined1 param_5,undefined1 param_6)

{
  undefined1 auStack_88 [32];
  undefined4 *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined4 local_28;
  undefined2 local_24;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_88;
  local_38 = 0;
  local_48 = &param_6;
  local_28 = *param_4;
  local_24 = *(undefined2 *)(param_4 + 1);
  local_40 = 4;
  local_58 = &param_5;
  local_50 = 4;
  local_68 = &local_28;
  local_60 = 6;
  (*pfnWppTraceMessage)(param_1,0x2b,&WPP_5cef1389656e33e18d36d18b27edf8f1_Traceguids);
  return;
}



===== WPP_SF__MAC_i @ 1c000c6b8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void WPP_SF__MAC_i(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 *param_4,
                  undefined1 param_5)

{
  undefined1 auStack_78 [32];
  undefined4 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined4 local_28;
  undefined2 local_24;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_78;
  local_28 = *param_4;
  local_48 = &param_5;
  local_38 = 0;
  local_40 = 8;
  local_58 = &local_28;
  local_24 = *(undefined2 *)(param_4 + 1);
  local_50 = 6;
  (*pfnWppTraceMessage)(param_1,0x2b,&WPP_5cef1389656e33e18d36d18b27edf8f1_Traceguids);
  return;
}



===== WPP_SF_qd_MAC_d @ 1c000c73c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void WPP_SF_qd_MAC_d(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                    undefined1 param_5,undefined4 *param_6,undefined1 param_7)

{
  undefined1 auStack_a8 [32];
  undefined8 *local_88;
  undefined8 local_80;
  undefined1 *local_78;
  undefined8 local_70;
  undefined4 *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_38 [2];
  undefined4 local_28;
  undefined2 local_24;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_a8;
  local_48 = 0;
  local_28 = *param_6;
  local_50 = 4;
  local_24 = *(undefined2 *)(param_6 + 1);
  local_58 = &param_7;
  local_68 = &local_28;
  local_60 = 6;
  local_78 = &param_5;
  local_70 = 4;
  local_88 = local_38;
  local_80 = 8;
  local_38[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,&WPP_5cef1389656e33e18d36d18b27edf8f1_Traceguids);
  return;
}



===== lbfoGetVmsPortFromVmsId @ 1c000c7f8 =====

undefined8 lbfoGetVmsPortFromVmsId(longlong param_1,int param_2)

{
  undefined8 uVar1;
  
  if (param_2 == 0) {
    uVar1 = *(undefined8 *)(param_1 + 0x650);
  }
  else {
    uVar1 = RtlLookupEntryHashTable(param_1 + 0x600,param_2,0);
  }
  return uVar1;
}



===== lbfoLearnMacAddr @ 1c000c830 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void lbfoLearnMacAddr(longlong param_1,undefined8 *param_2)

{
  longlong lVar1;
  ushort uVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  undefined2 local_res8;
  undefined1 local_resa;
  undefined4 local_res18;
  undefined2 local_res1c;
  
  lVar1 = *(longlong *)(param_1 + 0x10);
  local_res8 = 0;
  local_resa = 0;
  NdisAcquireRWLockRead(*(undefined8 *)(lVar1 + 0x5e8),&local_res8,1);
  for (; param_2 != (undefined8 *)0x0; param_2 = (undefined8 *)*param_2) {
    lVar3 = NdisGetDataBuffer(param_2[1],0xe,0,1,0);
    if (lVar3 != 0) {
      uVar2 = GetNblVlan(param_1,(longlong)param_2);
      lVar4 = lbfoGetVmsPortFromVmsId(lVar1,(uint)*(ushort *)((longlong)param_2 + 0x12a));
      lVar5 = RtlLookupEntryHashTable
                        (lVar1 + 0x628,
                         CONCAT26(uVar2,*(undefined6 *)(lVar3 + 6)) | 0x8000000000000000);
      if ((lVar5 == 0) ||
         (((*(byte *)(lVar5 + 0x20) & 1) != 0 && (*(longlong *)(lVar5 + 0x40) != lVar4)))) {
        NdisReleaseRWLock(*(undefined8 *)(lVar1 + 0x5e8),&local_res8);
        NdisAcquireRWLockWrite(*(undefined8 *)(lVar1 + 0x5e8),&local_res8,1);
        lVar4 = lbfoGetVmsPortFromVmsId(lVar1,(uint)*(ushort *)((longlong)param_2 + 0x12a));
        if (lVar4 == 0) break;
        local_res18 = *(undefined4 *)(lVar3 + 6);
        local_res1c = *(undefined2 *)(lVar3 + 10);
        lVar3 = lbfoLearnMacOnVmsPort(lVar1,lVar4,(undefined6 *)&local_res18,uVar2);
        if (lVar3 != 0) {
          *(undefined8 *)(lVar3 + 0x58) = _DAT_fffff78000000320;
        }
        NdisReleaseRWLock(*(undefined8 *)(lVar1 + 0x5e8),&local_res8);
        NdisAcquireRWLockRead(*(undefined8 *)(lVar1 + 0x5e8),&local_res8);
      }
      else {
        *(undefined8 *)(lVar5 + 0x58) = _DAT_fffff78000000320;
      }
    }
  }
  NdisReleaseRWLock(*(undefined8 *)(lVar1 + 0x5e8),&local_res8);
  return;
}



===== lbfoLearnMacOnVmsPort @ 1c000ca30 =====

longlong lbfoLearnMacOnVmsPort(longlong param_1,longlong param_2,undefined6 *param_3,ushort param_4)

{
  char *pcVar1;
  longlong *plVar2;
  code *pcVar3;
  undefined6 uVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  longlong *plVar8;
  undefined8 *puVar9;
  undefined8 *puVar10;
  undefined4 local_res8;
  undefined2 uStackX_c;
  undefined8 local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  
  local_38 = 0;
  lVar6 = param_1 + 0x628;
  local_res8 = *(undefined4 *)param_3;
  uStackX_c = *(undefined2 *)((longlong)param_3 + 4);
  puVar10 = &local_48;
  local_48 = 0;
  uStack_40 = 0;
  lVar5 = RtlLookupEntryHashTable(lVar6,CONCAT26(param_4,*param_3) | 0x8000000000000000);
  if (lVar5 == 0) {
    local_4c = 0;
    local_58 = 1;
    local_50 = 0x10;
    lVar5 = ExAllocatePool3(0x40,0x60,0x5463694e,&local_58,1);
    if (lVar5 == 0) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 0;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
        return 0;
      }
      WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
               &WPP_5cef1389656e33e18d36d18b27edf8f1_Traceguids,"LearnedMac");
      return 0;
    }
    *(byte *)(lVar5 + 0x20) = *(byte *)(lVar5 + 0x20) | 1;
    *(undefined4 *)(lVar5 + 0x18) = *(undefined4 *)param_3;
    *(undefined2 *)(lVar5 + 0x1c) = *(undefined2 *)((longlong)param_3 + 4);
    local_res8 = *(undefined4 *)param_3;
    uStackX_c = *(undefined2 *)((longlong)param_3 + 4);
    uVar4 = *param_3;
    *(ushort *)(lVar5 + 0x1e) =
         (*(ushort *)(lVar5 + 0x1e) ^ param_4) & 0xfff ^ *(ushort *)(lVar5 + 0x1e);
    puVar10 = (undefined8 *)(CONCAT26(param_4,uVar4) | 0x8000000000000000);
    lVar7 = lVar5;
    RtlInsertEntryHashTable(lVar6,lVar5,puVar10,&local_48);
  }
  else {
    if ((*(byte *)(lVar5 + 0x20) & 1) == 0) {
      return lVar5;
    }
    if (*(longlong *)(lVar5 + 0x40) == param_2) {
      return lVar5;
    }
    pcVar1 = (char *)(*(longlong *)(lVar5 + 0x40) + 0x2e);
    *pcVar1 = *pcVar1 + -1;
    plVar2 = (longlong *)(lVar5 + 0x30);
    lVar7 = *plVar2;
    if ((*(longlong **)(lVar7 + 8) != plVar2) ||
       (plVar8 = *(longlong **)(lVar5 + 0x38), (longlong *)*plVar8 != plVar2)) goto LAB_1c000ccf2;
    *plVar8 = lVar7;
    *(longlong **)(lVar7 + 8) = plVar8;
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    local_res8 = *(undefined4 *)param_3;
    uStackX_c = *(undefined2 *)((longlong)param_3 + 4);
    WPP_SF__MAC_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),lVar7,puVar10,&local_res8,
                   (char)param_4,(char)*(undefined4 *)(param_2 + 0x28));
  }
  *(longlong *)(lVar5 + 0x40) = param_2;
  *(undefined8 *)(lVar5 + 0x28) = *(undefined8 *)(param_2 + 0x48);
  if (*(char *)(param_2 + 0x2e) == -1) {
    puVar9 = (undefined8 *)0x0;
    for (puVar10 = *(undefined8 **)(param_2 + 0x30); puVar10 != (undefined8 *)(param_2 + 0x30);
        puVar10 = (undefined8 *)*puVar10) {
      if ((puVar9 == (undefined8 *)0x0) || ((longlong)puVar10[5] < (longlong)puVar9[0xb])) {
        puVar9 = puVar10 + -6;
      }
    }
    plVar2 = puVar9 + 6;
    lVar7 = *plVar2;
    if ((*(longlong **)(lVar7 + 8) != plVar2) ||
       (plVar8 = (longlong *)puVar9[7], (longlong *)*plVar8 != plVar2)) goto LAB_1c000ccf2;
    *plVar8 = lVar7;
    *(longlong **)(lVar7 + 8) = plVar8;
    RtlRemoveEntryHashTable(lVar6,puVar9,0);
    ExFreePoolWithTag(puVar9,0x5463694e);
  }
  else {
    *(char *)(param_2 + 0x2e) = *(char *)(param_2 + 0x2e) + '\x01';
  }
  plVar8 = (longlong *)(param_2 + 0x30);
  lVar6 = *plVar8;
  plVar2 = (longlong *)(lVar5 + 0x30);
  if (*(longlong **)(lVar6 + 8) == plVar8) {
    *plVar2 = lVar6;
    *(longlong **)(lVar5 + 0x38) = plVar8;
    *(longlong **)(lVar6 + 8) = plVar2;
    *plVar8 = (longlong)plVar2;
    return lVar5;
  }
LAB_1c000ccf2:
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  pcVar3 = (code *)swi(3);
  lVar6 = (*pcVar3)();
  return lVar6;
}



===== lbfoRemoveVmsPortInner @ 1c000cd00 =====

void lbfoRemoveVmsPortInner(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  short *psVar2;
  ushort uVar3;
  longlong *plVar4;
  longlong lVar5;
  longlong lVar6;
  code *pcVar7;
  undefined8 uVar8;
  undefined4 local_res8;
  undefined2 local_resc;
  
  uVar8 = 0;
  RtlRemoveEntryHashTable(param_1 + 0x600);
  plVar1 = (longlong *)(param_2 + 0x30);
  while (plVar4 = (longlong *)*plVar1, plVar4 != plVar1) {
    if (((longlong *)plVar4[1] != plVar1) ||
       (lVar5 = *plVar4, (longlong *)*(longlong *)(lVar5 + 8) != plVar4)) goto LAB_1c000cf9c;
    *plVar1 = lVar5;
    *(longlong **)(lVar5 + 8) = plVar1;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      local_res8 = *(undefined4 *)(plVar4 + -3);
      local_resc = *(undefined2 *)((longlong)plVar4 + -0x14);
      WPP_SF_q_MAC_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),
                      (ulonglong)(*(ushort *)((longlong)plVar4 + -0x12) & 0xfff),
                      &WPP_5cef1389656e33e18d36d18b27edf8f1_Traceguids,param_1,&local_res8,
                      (char)*(ushort *)((longlong)plVar4 + -0x12),
                      (char)*(undefined4 *)(param_2 + 0x28));
    }
    uVar8 = 0;
    RtlRemoveEntryHashTable(param_1 + 0x628,plVar4 + -6);
    ExFreePoolWithTag(plVar4 + -6,0x5463694e);
  }
  plVar1 = (longlong *)(param_2 + 0x18);
  *(short *)(param_1 + 0x5f8) = *(short *)(param_1 + 0x5f8) + -1;
  lVar5 = *plVar1;
  lVar6 = *(longlong *)(param_2 + 0x40);
  if ((*(longlong **)(lVar5 + 8) != plVar1) ||
     (plVar4 = *(longlong **)(param_2 + 0x20), (longlong *)*plVar4 != plVar1)) {
LAB_1c000cf9c:
    pcVar7 = (code *)swi(0x29);
    (*pcVar7)(3);
    pcVar7 = (code *)swi(3);
    (*pcVar7)();
    return;
  }
  *plVar4 = lVar5;
  *(longlong **)(lVar5 + 8) = plVar4;
  uVar3 = *(ushort *)(lVar6 + 0x50);
  lVar5 = *(longlong *)(lVar6 + 0x28);
  *(ushort *)(lVar6 + 0x50) = (uVar3 - 1 ^ uVar3) & 0x3fff ^ uVar3;
  if (lVar5 != 0) {
    uVar3 = *(ushort *)(lVar5 + 0x2ba);
    uVar8 = 0x7fff;
    *(ushort *)(lVar5 + 0x2ba) = (uVar3 - 1 ^ uVar3) & 0x7fff ^ uVar3;
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    local_res8 = *(undefined4 *)(lVar6 + 0x18);
    local_resc = *(undefined2 *)(lVar6 + 0x1c);
    WPP_SF_qd_MAC_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),lVar5,uVar8,param_1,
                    (char)*(undefined4 *)(param_2 + 0x28),&local_res8,
                    (char)*(undefined2 *)(lVar6 + 0x1e));
  }
  ExFreePoolWithTag(param_2,0x5463694e);
  if ((*(ushort *)(lVar6 + 0x50) & 0x3fff) == 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      local_res8 = *(undefined4 *)(lVar6 + 0x18);
      local_resc = *(undefined2 *)(lVar6 + 0x1c);
      WPP_SF_q_MAC_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
                     &WPP_5cef1389656e33e18d36d18b27edf8f1_Traceguids,param_1,&local_res8,
                     (char)*(undefined2 *)(lVar6 + 0x1e));
    }
    plVar1 = (longlong *)(lVar6 + 0x30);
    lVar5 = *plVar1;
    if ((*(longlong **)(lVar5 + 8) != plVar1) ||
       (plVar4 = *(longlong **)(lVar6 + 0x38), (longlong *)*plVar4 != plVar1)) goto LAB_1c000cf9c;
    *plVar4 = lVar5;
    *(longlong **)(lVar5 + 8) = plVar4;
    if (*(longlong *)(lVar6 + 0x28) == 0) {
      *(short *)(param_1 + 0x8ee) = *(short *)(param_1 + 0x8ee) + -1;
    }
    else {
      psVar2 = (short *)(*(longlong *)(lVar6 + 0x28) + 0x2b8);
      *psVar2 = *psVar2 + -1;
    }
    RtlRemoveEntryHashTable(param_1 + 0x628,lVar6,0);
    ExFreePoolWithTag(lVar6,0x5463694e);
  }
  return;
}



===== lbfoVMSAddVmsPort @ 1c000cfb0 =====

void lbfoVMSAddVmsPort(longlong param_1,int param_2)

{
  lbfoLBInitialMapVmsPort(param_1,param_2,param_1 + 0x948,0x5a0);
  return;
}



===== lbfoVMSGetOutgoingNicId @ 1c000cfe0 =====

void lbfoVMSGetOutgoingNicId(longlong param_1,longlong param_2)

{
  lbfoLBGetMappedNicId(param_1,param_2,(char *)(*(longlong *)(param_1 + 0x10) + 0x948),0x5a0);
  return;
}



===== lbfoVMSGetSwitchPrimingNbls @ 1c000d010 =====

void lbfoVMSGetSwitchPrimingNbls(longlong param_1,longlong param_2,undefined8 param_3)

{
  lbfoLBGetSwitchPrimingNbls(param_1,param_2,param_3);
  return;
}



===== lbfoVMSIsLoopedBackVMPacket @ 1c000d028 =====

undefined1 lbfoVMSIsLoopedBackVMPacket(longlong param_1,longlong param_2,longlong param_3)

{
  longlong lVar1;
  ushort uVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  undefined1 uVar7;
  undefined1 uVar6;
  undefined2 local_res8;
  undefined1 local_resa;
  ulonglong in_stack_ffffffffffffffc8;
  undefined4 local_28;
  undefined2 uStack_24;
  
  lVar1 = *(longlong *)(param_1 + 0x10);
  local_res8 = 0;
  local_resa = 0;
  uVar7 = 0;
  uVar6 = 0;
  lVar3 = NdisGetDataBuffer(*(undefined8 *)(param_2 + 8),0xe,0,1,
                            in_stack_ffffffffffffffc8 & 0xffffffff00000000);
  if (lVar3 != 0) {
    NdisAcquireRWLockRead(*(undefined8 *)(lVar1 + 0x5e8),&local_res8,1);
    local_28 = *(undefined4 *)(lVar3 + 6);
    uStack_24 = *(undefined2 *)(lVar3 + 10);
    uVar2 = GetNblVlan(param_1,param_2);
    lVar3 = RtlLookupEntryHashTable
                      (lVar1 + 0x628,
                       CONCAT26(uVar2,CONCAT24(uStack_24,local_28)) | 0x8000000000000000,0);
    uVar6 = uVar7;
    if (lVar3 != 0) {
      lVar5 = param_3 - *(longlong *)(lVar3 + 0x58);
      lVar4 = 0;
      if (-1 < lVar5) {
        lVar4 = lVar5;
      }
      lVar4 = lVar4 * (ulonglong)DAT_1c0018470;
      if (lVar4 < 10000000) {
        uVar6 = 1;
      }
      else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              (3 < (byte)WPP_GLOBAL_Control[0x29])) {
        local_28 = *(undefined4 *)(lVar3 + 0x18);
        uStack_24 = *(undefined2 *)(lVar3 + 0x1c);
        WPP_SF__MAC_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),lVar4 / 10000,-(lVar4 >> 0x3f),
                      &local_28,(char)(lVar4 / 10000));
      }
    }
    NdisReleaseRWLock(*(undefined8 *)(lVar1 + 0x5e8),&local_res8);
  }
  return uVar6;
}



===== lbfoVMSPrepareForSend @ 1c000d1c0 =====

int lbfoVMSPrepareForSend(longlong param_1,longlong param_2,byte param_3)

{
  int iVar1;
  
  if ((*(byte *)(param_1 + 0xcc) & 2) == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = NdisAllocateNetBufferListContext
                      (param_2,0x10,*(undefined2 *)(param_1 + 0x48),0x5463694e);
    if (iVar1 == 0) {
      *(undefined2 *)
       ((ulonglong)*(ushort *)(*(longlong *)(param_2 + 0x10) + 10) + 0x16 +
       *(longlong *)(param_2 + 0x10)) = *(undefined2 *)(param_2 + 0x102);
      if (*(int *)(*(longlong *)(param_1 + 0x10) + 0x570) != 0) {
        *(undefined2 *)(param_2 + 0x102) =
             *(undefined2 *)
              (*(longlong *)(*(longlong *)(param_1 + 0x10) + 0x578) +
              ((ulonglong)(*(byte *)((ulonglong)param_3 + 0x89 + param_1) - 1) +
              (ulonglong)*(ushort *)(param_2 + 0x102) * 0x15a) * 4);
      }
    }
    else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_ds(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
                &WPP_5cef1389656e33e18d36d18b27edf8f1_Traceguids,iVar1,
                "NdisAllocateNetBufferListContext(Nbl, sizeof(LBFO_NBL_CONTEXT), FilterContext->NblContextBackfill, LBFO_POOLTAG)"
               );
    }
  }
  return iVar1;
}



===== lbfoVMSRebalanceCfgMacs @ 1c000d2c0 =====

void lbfoVMSRebalanceCfgMacs(longlong param_1)

{
  lbfoLBRebalanceCfgMacs(param_1,param_1 + 0x948,0x5a0);
  return;
}



===== lbfoVMSRemoveVmsPort @ 1c000d2f0 =====

void lbfoVMSRemoveVmsPort(longlong param_1,uint param_2)

{
  if (param_2 < 0x5a0) {
    *(undefined1 *)((ulonglong)param_2 + 0x948 + param_1) = 0;
  }
  return;
}



===== lbfoVMSSendComplete @ 1c000d310 =====

void lbfoVMSSendComplete(longlong param_1,longlong param_2)

{
  if ((*(byte *)(param_1 + 0xcc) & 2) != 0) {
    *(undefined2 *)(param_2 + 0x102) =
         *(undefined2 *)
          ((ulonglong)*(ushort *)(*(longlong *)(param_2 + 0x10) + 10) + 0x16 +
          *(longlong *)(param_2 + 0x10));
    NdisFreeNetBufferListContext(param_2,0x10);
  }
  return;
}



===== lbfoVMSUpdateVmsPort @ 1c000d360 =====

void lbfoVMSUpdateVmsPort(longlong param_1,uint param_2)

{
  if (param_2 < 0x5a0) {
    *(undefined1 *)((ulonglong)param_2 + 0x948 + param_1) = 0;
  }
  lbfoLBInitialMapVmsPort(param_1,param_2,param_1 + 0x948,0x5a0);
  return;
}



===== LbfoOidRequest @ 1c000d3a0 =====

undefined8 LbfoOidRequest(longlong param_1,undefined8 param_2)

{
  *(undefined8 *)(param_1 + 0x100) = param_2;
  NdisQueueIoWorkItem(*(undefined8 *)(param_1 + 0xf8),LbfoOidRequestWorkItem,param_1);
  return 0x103;
}



===== LbfoOidRequestComplete @ 1c000d3e0 =====

void LbfoOidRequestComplete(longlong param_1,longlong param_2,undefined8 param_3)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  int iVar8;
  undefined2 local_res8;
  undefined1 local_resa;
  
  lVar1 = *(longlong *)(param_2 + 0xe0);
  iVar8 = (int)param_3;
  if (lVar1 == 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_DdL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),param_2,param_3,
                 *(undefined4 *)(param_2 + 0x20),(char)*(undefined4 *)(param_2 + 8),
                 (char)*(undefined4 *)(param_2 + 4));
    }
    *(int *)(param_2 + 0xe0) = iVar8;
    KeSetEvent(*(undefined8 *)(param_2 + 0xd8),0,0);
    return;
  }
  *(undefined8 *)(param_1 + 0x100) = 0;
  if ((iVar8 == 0) && ((*(uint *)(param_2 + 4) & 0xfffffffd) == 0)) {
    if (*(int *)(param_2 + 0x20) == -0x5fefeff) {
      lVar2 = *(longlong *)(param_1 + 0x10);
      local_res8 = 0;
      local_resa = 0;
      if ((((*(uint *)(param_2 + 0x30) < 200) ||
           (pcVar3 = *(char **)(param_2 + 0x28), *pcVar3 != -0x80)) || (pcVar3[1] != '\x01')) ||
         (*(ushort *)(pcVar3 + 2) < 200)) {
        iVar8 = -0x3ffeffeb;
      }
      else {
        if (*(int *)(lVar2 + 0x5a4) != 1) {
          if (*(int *)(lVar2 + 0x20) != 2) {
            iVar8 = -0x3ffeffef;
            goto LAB_1c000d52b;
          }
          NdisAcquireRWLockRead(*(undefined8 *)(lVar2 + 0x5e8),&local_res8,0);
          *(undefined8 *)(pcVar3 + 0x40) = *(undefined8 *)(lVar2 + 0x878);
          NdisReleaseRWLock(*(undefined8 *)(lVar2 + 0x5e8),&local_res8);
        }
        iVar8 = 0;
      }
    }
    else if (*(int *)(param_2 + 0x20) == -0x5fefefd) {
      uVar7 = lbfoHandleOidQueryCurrentState(*(longlong *)(param_1 + 0x10),param_2);
      iVar8 = (int)uVar7;
    }
  }
LAB_1c000d52b:
  uVar7 = *(undefined8 *)(param_2 + 0x28);
  *(undefined8 *)(lVar1 + 0x20) = *(undefined8 *)(param_2 + 0x20);
  *(undefined8 *)(lVar1 + 0x28) = uVar7;
  uVar4 = *(undefined4 *)(param_2 + 0x34);
  uVar5 = *(undefined4 *)(param_2 + 0x38);
  uVar6 = *(undefined4 *)(param_2 + 0x3c);
  *(undefined4 *)(lVar1 + 0x30) = *(undefined4 *)(param_2 + 0x30);
  *(undefined4 *)(lVar1 + 0x34) = uVar4;
  *(undefined4 *)(lVar1 + 0x38) = uVar5;
  *(undefined4 *)(lVar1 + 0x3c) = uVar6;
  *(undefined8 *)(lVar1 + 0x40) = *(undefined8 *)(param_2 + 0x40);
  NdisFreeCloneOidRequest(*(undefined8 *)(param_1 + 0x18),param_2);
  NdisFOidRequestComplete(*(undefined8 *)(param_1 + 0x18),lVar1,iVar8);
  return;
}



===== WPP_SF_DD @ 1c000d58c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_dce82a7e4eab3c5b73974bacaa7b552c_Traceguids,0x18,local_res20,4,
             &param_5,4,0);
  return;
}



===== WPP_SF_DL @ 1c000d5e4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DL(undefined8 param_1)

{
  undefined4 local_18 [2];
  undefined4 local_10 [4];
  
  local_18[0] = 0;
  local_10[0] = 0x10207;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_dce82a7e4eab3c5b73974bacaa7b552c_Traceguids,0xf,local_10,4,local_18,4
             ,0);
  return;
}



===== WPP_SF_DLd @ 1c000d644 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DLd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_dce82a7e4eab3c5b73974bacaa7b552c_Traceguids,param_2,local_res20,4,
             &param_5,4,&param_6,4,0);
  return;
}



===== WPP_SF_DLddd @ 1c000d6a8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DLddd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined4 local_18 [2];
  undefined4 local_10 [4];
  
  local_18[0] = 1;
  local_10[0] = 0xfa010203;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_dce82a7e4eab3c5b73974bacaa7b552c_Traceguids,0xe,local_10,4,local_18,4
             ,&uStack0000000000000030,4,&uStack0000000000000038,4,&uStack0000000000000040,4,0);
  return;
}



===== WPP_SF_DLdq @ 1c000d734 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DLdq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_dce82a7e4eab3c5b73974bacaa7b552c_Traceguids,0xb,local_res20,4,
             &param_5,4,&param_6,4,&param_7,8,0);
  return;
}



===== WPP_SF_DLdqd @ 1c000d7a8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DLdqd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                 undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_dce82a7e4eab3c5b73974bacaa7b552c_Traceguids,0xc,local_res20,4,
             &param_5,4,&param_6,4,&param_7,8,&param_8,4,0);
  return;
}



===== WPP_SF_DdL @ 1c000d82c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DdL(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_dce82a7e4eab3c5b73974bacaa7b552c_Traceguids,0x11,local_res20,4,
             &param_5,4,&param_6,4,0);
  return;
}



===== WPP_SF_Ddd @ 1c000d890 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Ddd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_dce82a7e4eab3c5b73974bacaa7b552c_Traceguids,10,local_res20,4,&param_5
             ,4,&param_6,4,0);
  return;
}



===== WPP_SF__MAC__MAC_dd @ 1c000d8f4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void WPP_SF__MAC__MAC_dd(undefined8 param_1,undefined8 param_2,undefined8 param_3,
                        undefined4 *param_4,undefined4 *param_5,undefined1 param_6,
                        undefined1 param_7)

{
  undefined1 auStack_a8 [32];
  undefined4 *local_88;
  undefined8 local_80;
  undefined4 *local_78;
  undefined8 local_70;
  undefined1 *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined4 local_38;
  undefined2 local_34;
  undefined4 local_28;
  undefined2 local_24;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_a8;
  local_48 = 0;
  local_28 = *param_4;
  local_24 = *(undefined2 *)(param_4 + 1);
  local_38 = *param_5;
  local_34 = *(undefined2 *)(param_5 + 1);
  local_50 = 4;
  local_58 = &param_7;
  local_68 = &param_6;
  local_60 = 4;
  local_78 = &local_38;
  local_70 = 6;
  local_88 = &local_28;
  local_80 = 6;
  (*pfnWppTraceMessage)(param_1,0x2b,&WPP_dce82a7e4eab3c5b73974bacaa7b552c_Traceguids);
  return;
}



===== WPP_SF_qd_MAC_dd @ 1c000d9b8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void WPP_SF_qd_MAC_dd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                     undefined1 param_5,undefined4 *param_6,undefined1 param_7,undefined1 param_8)

{
  undefined1 auStack_b8 [32];
  undefined8 *local_98;
  undefined8 local_90;
  undefined1 *local_88;
  undefined8 local_80;
  undefined4 *local_78;
  undefined8 local_70;
  undefined1 *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_38 [2];
  undefined4 local_28;
  undefined2 local_24;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_b8;
  local_48 = 0;
  local_28 = *param_6;
  local_50 = 4;
  local_24 = *(undefined2 *)(param_6 + 1);
  local_58 = &param_8;
  local_68 = &param_7;
  local_60 = 4;
  local_78 = &local_28;
  local_70 = 6;
  local_88 = &param_5;
  local_80 = 4;
  local_98 = local_38;
  local_90 = 8;
  local_38[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,&WPP_dce82a7e4eab3c5b73974bacaa7b552c_Traceguids);
  return;
}



===== lbfoAddVmsPortInner @ 1c000da84 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int lbfoAddVmsPortInner(longlong param_1,uint param_2,undefined2 param_3,undefined4 *param_4,
                       ushort param_5)

{
  int iVar1;
  undefined2 local_res8;
  undefined1 local_resa;
  undefined4 local_18;
  undefined2 local_14;
  
  local_res8 = 0;
  local_resa = 0;
  NdisAcquireRWLockWrite(*(undefined8 *)(param_1 + 0x5e8),&local_res8,0);
  local_18 = *param_4;
  local_14 = *(undefined2 *)(param_4 + 1);
  iVar1 = lbfoAddVmsPortInner2(param_1,param_2,param_3,(uint6 *)&local_18,param_5);
  if (iVar1 == 0) {
    (*(code *)(&PTR_lbfoNTHAddVmsPort_1c0018130)[(longlong)*(int *)(param_1 + 0x5a4) * 0xf])
              (param_1,param_2);
    lbfoSetCfgMacRebalanceTimer(param_1);
  }
  NdisReleaseRWLock(*(undefined8 *)(param_1 + 0x5e8),&local_res8);
  return iVar1;
}



===== lbfoAddVmsPortInner2 @ 1c000db5c =====

undefined4
lbfoAddVmsPortInner2(longlong param_1,uint param_2,undefined2 param_3,uint6 *param_4,ushort param_5)

{
  ushort uVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined8 uVar4;
  code *pcVar5;
  uint6 uVar6;
  longlong *plVar7;
  longlong lVar8;
  longlong *plVar9;
  longlong lVar10;
  undefined1 *puVar11;
  undefined4 uVar12;
  undefined *puVar13;
  undefined *puVar14;
  undefined1 auStackY_98 [8];
  undefined1 auStackY_90 [24];
  undefined4 local_58;
  ushort uStack_54;
  ulonglong local_48;
  undefined8 local_40;
  undefined8 local_38;
  
  uVar12 = 0;
  puVar14 = (undefined *)(ulonglong)param_2;
  local_38 = 0x10;
  puVar13 = (undefined *)0x5463694e;
  local_40 = 1;
  plVar7 = (longlong *)ExAllocatePool3(0x40,0x50,0x5463694e,&local_40);
  puVar11 = auStackY_98;
  if (plVar7 == (longlong *)0x0) {
    uVar12 = 0xc000009a;
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc000009a;
    }
    if (1 < (byte)WPP_GLOBAL_Control[0x29]) {
      puVar13 = &WPP_dce82a7e4eab3c5b73974bacaa7b552c_Traceguids;
      WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
               &WPP_dce82a7e4eab3c5b73974bacaa7b552c_Traceguids,"VmsPort");
      puVar11 = auStackY_98;
    }
    goto LAB_1c000df67;
  }
  *(uint *)(plVar7 + 5) = param_2;
  *(undefined2 *)((longlong)plVar7 + 0x2c) = param_3;
  plVar9 = plVar7 + 6;
  plVar7[7] = (longlong)plVar9;
  *plVar9 = (longlong)plVar9;
  local_58 = (undefined4)*param_4;
  uStack_54 = *(undefined2 *)((longlong)param_4 + 4);
  local_48 = (ulonglong)param_5 << 0x30;
  puVar13 = (undefined *)0x0;
  lVar8 = RtlLookupEntryHashTable(param_1 + 0x628,CONCAT26(param_5,*param_4) | 0x8000000000000000);
  if (lVar8 == 0) {
    puVar13 = (undefined *)0x5463694e;
    lVar8 = ExAllocatePool3(0x40,0x60,0x5463694e,&local_40);
    if (lVar8 == 0) {
      ExFreePoolWithTag(plVar7,0x5463694e);
      puVar11 = auStackY_98;
      uVar12 = 0xc000009a;
      goto LAB_1c000df67;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      local_58 = (undefined4)*param_4;
      uStack_54 = *(undefined2 *)((longlong)param_4 + 4);
      WPP_SF_q_MAC_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
                     &WPP_dce82a7e4eab3c5b73974bacaa7b552c_Traceguids,param_1,&local_58,
                     (char)param_5);
    }
    uVar6 = *param_4;
    *(byte *)(lVar8 + 0x20) = *(byte *)(lVar8 + 0x20) & 0xfe;
    *(int *)(lVar8 + 0x18) = (int)uVar6;
    *(undefined2 *)(lVar8 + 0x1c) = *(undefined2 *)((longlong)param_4 + 4);
    *(undefined8 *)(lVar8 + 0x28) = 0;
    lVar10 = lVar8 + 0x40;
    *(longlong *)(lVar8 + 0x48) = lVar10;
    *(longlong *)lVar10 = lVar10;
    local_58 = (undefined4)*param_4;
    uStack_54 = *(undefined2 *)((longlong)param_4 + 4);
    uVar6 = *param_4;
    *(ushort *)(lVar8 + 0x1e) =
         (*(ushort *)(lVar8 + 0x1e) ^ param_5) & 0xfff ^ *(ushort *)(lVar8 + 0x1e);
    puVar13 = (undefined *)(uVar6 | local_48 | 0x8000000000000000);
    RtlInsertEntryHashTable(param_1 + 0x628,lVar8,puVar13,0);
    *(short *)(param_1 + 0x8ee) = *(short *)(param_1 + 0x8ee) + 1;
    plVar9 = (longlong *)(lVar8 + 0x30);
    plVar2 = *(longlong **)(param_1 + 0x8f8);
    if (*plVar2 != param_1 + 0x8f0) goto LAB_1c000df4b;
    *plVar9 = param_1 + 0x8f0;
    *(longlong **)(lVar8 + 0x38) = plVar2;
    *plVar2 = (longlong)plVar9;
    *(longlong **)(param_1 + 0x8f8) = plVar9;
    lVar10 = lVar8;
LAB_1c000dead:
    *(short *)(param_1 + 0x5f8) = *(short *)(param_1 + 0x5f8) + 1;
    if (param_2 == 0) {
      *(byte *)(lVar10 + 0x52) = *(byte *)(lVar10 + 0x52) | 2;
      *(longlong **)(param_1 + 0x650) = plVar7;
    }
    else {
      RtlInsertEntryHashTable(param_1 + 0x600,plVar7,puVar14,0);
      puVar13 = puVar14;
    }
    puVar11 = auStackY_98;
    plVar7[8] = lVar10;
    plVar7[9] = *(longlong *)(lVar10 + 0x28);
    lVar8 = *(longlong *)(lVar10 + 0x28);
    if (lVar8 != 0) {
      uVar1 = *(ushort *)(lVar8 + 0x2ba);
      puVar13 = (undefined *)0x7fff;
      *(ushort *)(lVar8 + 0x2ba) = (uVar1 + 1 ^ uVar1) & 0x7fff ^ uVar1;
    }
    uVar1 = *(ushort *)(lVar10 + 0x50);
    plVar7 = plVar7 + 3;
    *(ushort *)(lVar10 + 0x50) = (uVar1 + 1 ^ uVar1) & 0x3fff ^ uVar1;
    lVar8 = lVar10 + 0x40;
    plVar9 = *(longlong **)(lVar10 + 0x48);
    if (*plVar9 != lVar8) goto LAB_1c000df4b;
  }
  else {
    lVar10 = lVar8;
    if ((*(byte *)(lVar8 + 0x20) & 1) == 0) goto LAB_1c000dead;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      local_58 = (undefined4)*param_4;
      puVar13 = &WPP_dce82a7e4eab3c5b73974bacaa7b552c_Traceguids;
      uStack_54 = *(undefined2 *)((longlong)param_4 + 4);
      WPP_SF_q_MAC_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
                     &WPP_dce82a7e4eab3c5b73974bacaa7b552c_Traceguids,param_1,&local_58,
                     (char)param_5);
    }
    plVar9 = (longlong *)(lVar8 + 0x30);
    lVar3 = *plVar9;
    if ((*(longlong **)(lVar3 + 8) == plVar9) &&
       (plVar2 = *(longlong **)(lVar8 + 0x38), (longlong *)*plVar2 == plVar9)) {
      *plVar2 = lVar3;
      *(longlong **)(lVar3 + 8) = plVar2;
      plVar2 = (longlong *)(lVar8 + 0x40);
      *(char *)(*plVar2 + 0x2e) = *(char *)(*plVar2 + 0x2e) + -1;
      *(byte *)(lVar8 + 0x20) = *(byte *)(lVar8 + 0x20) & 0xfe;
      *(undefined8 *)(lVar8 + 0x28) = 0;
      *(undefined8 *)(lVar8 + 0x30) = 0;
      *(undefined8 *)(lVar8 + 0x38) = 0;
      *(undefined8 *)(lVar8 + 0x48) = 0;
      *(undefined8 *)(lVar8 + 0x50) = 0;
      *(longlong **)(lVar8 + 0x48) = plVar2;
      *plVar2 = (longlong)plVar2;
      *(short *)(param_1 + 0x8ee) = *(short *)(param_1 + 0x8ee) + 1;
      plVar2 = *(longlong **)(param_1 + 0x8f8);
      if (*plVar2 == param_1 + 0x8f0) {
        *plVar9 = param_1 + 0x8f0;
        *(longlong **)(lVar8 + 0x38) = plVar2;
        *plVar2 = (longlong)plVar9;
        *(longlong **)(param_1 + 0x8f8) = plVar9;
        goto LAB_1c000dead;
      }
    }
LAB_1c000df4b:
    pcVar5 = (code *)swi(0x29);
    plVar9 = (longlong *)(*pcVar5)(3);
    puVar11 = auStackY_90;
  }
  *plVar7 = lVar8;
  plVar7[1] = (longlong)plVar9;
  *plVar9 = (longlong)plVar7;
  *(longlong **)(lVar8 + 8) = plVar7;
LAB_1c000df67:
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    uVar6 = *param_4;
    uVar4 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
    *(undefined4 *)(puVar11 + 0x38) = uVar12;
    local_58 = (int)uVar6;
    uStack_54 = *(ushort *)((longlong)param_4 + 4);
    *(uint *)(puVar11 + 0x30) = (uint)param_5;
    *(undefined4 **)(puVar11 + 0x28) = &local_58;
    *(uint *)(puVar11 + 0x20) = param_2;
    *(undefined8 *)(puVar11 + -8) = 0x1c000dfab;
    WPP_SF_qd_MAC_dd(uVar4,(ulonglong)uStack_54,puVar13,param_1,puVar11[0x20],
                     *(undefined4 **)(puVar11 + 0x28),puVar11[0x30],puVar11[0x38]);
  }
  return uVar12;
}



===== lbfoChangeInstanceParameters @ 1c000dfe0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
lbfoChangeInstanceParameters(longlong param_1,longlong param_2,undefined8 param_3,longlong param_4)

{
  longlong *plVar1;
  short sVar2;
  short sVar3;
  longlong lVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  bool bVar8;
  char cVar9;
  longlong lVar10;
  longlong *plVar11;
  undefined *puVar12;
  undefined1 auStackY_a8 [32];
  undefined2 local_78;
  undefined1 local_76;
  undefined8 local_68 [4];
  longlong local_48;
  undefined4 local_40;
  undefined4 local_3c;
  longlong *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_a8;
  lVar4 = *(longlong *)(param_1 + 0x10);
  local_78 = 0;
  local_76 = 0;
  if (*(int *)(lVar4 + 0x5a8) == 1) {
    puVar12 = (undefined *)0x0;
    NdisAcquireRWLockWrite(*(undefined8 *)(lVar4 + 0x5e8),&local_78);
    sVar2 = *(short *)(lVar4 + 0x940);
    plVar1 = (longlong *)(lVar4 + 0x928);
    sVar3 = *(short *)(param_2 + 4);
    lVar10 = *plVar1 - *(longlong *)(param_2 + 8);
    if (lVar10 == 0) {
      lVar10 = *(longlong *)(lVar4 + 0x930) - *(longlong *)(param_2 + 0x10);
    }
    if ((sVar2 != sVar3) || (lVar10 != 0)) {
      uVar5 = *(undefined4 *)(param_2 + 0xc);
      uVar6 = *(undefined4 *)(param_2 + 0x10);
      uVar7 = *(undefined4 *)(param_2 + 0x14);
      *(undefined4 *)plVar1 = *(undefined4 *)(param_2 + 8);
      *(undefined4 *)(lVar4 + 0x92c) = uVar5;
      *(undefined4 *)(lVar4 + 0x930) = uVar6;
      *(undefined4 *)(lVar4 + 0x934) = uVar7;
      plVar11 = plVar1;
      if (5 < DAT_1c00182f0) {
        puVar12 = (undefined *)0x200000000000;
        if (((DAT_1c0018300 & 0x200000000000) == 0) ||
           ((DAT_1c0018308 & 0x200000000000) != DAT_1c0018308)) {
          bVar8 = false;
        }
        else {
          bVar8 = true;
        }
        if (bVar8) {
          local_3c = 0;
          local_48 = lVar4 + 0x24;
          local_2c = 0;
          local_40 = 0x10;
          local_30 = 0x10;
          plVar11 = (longlong *)&DAT_1c0016cda;
          local_38 = plVar1;
          _tlgWriteTransfer_EtwWriteTransfer
                    (lVar10,&DAT_1c0016cda,0x200000000000,param_4,4,local_68);
        }
      }
      if (sVar2 == sVar3) {
        lbfoSIConnectDesiredNumNics(lVar4,plVar11,puVar12,param_4);
      }
      else {
        *(undefined2 *)(lVar4 + 0x940) = *(undefined2 *)(param_2 + 4);
        if ((*(byte *)(lVar4 + 0x942) & 1) != 0) {
          cVar9 = NdisSetCoalescableTimerObject
                            (*(undefined8 *)(lVar4 + 0x938),0xfffffffffd050f80,0,lVar4);
          if (cVar9 == '\0') {
            *(short *)(lVar4 + 0x920) = *(short *)(lVar4 + 0x920) + 1;
          }
        }
      }
    }
    NdisReleaseRWLock(*(undefined8 *)(lVar4 + 0x5e8),&local_78);
  }
  return 0;
}



===== lbfoDerefFilterContextsForOid @ 1c000e1a0 =====

void lbfoDerefFilterContextsForOid(longlong param_1,longlong *param_2,ushort param_3)

{
  short *psVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined2 local_res18;
  undefined1 local_res1a;
  
  uVar3 = (ulonglong)param_3;
  local_res18 = 0;
  local_res1a = 0;
  NdisAcquireRWLockWrite(*(undefined8 *)(param_1 + 0x5e8),&local_res18,0);
  if (param_3 != 0) {
    do {
      lVar2 = *param_2;
      psVar1 = (short *)(lVar2 + 0xce);
      *psVar1 = *psVar1 + -1;
      if (*psVar1 == 0) {
        KeSetEvent(lVar2 + 0xd0,0,0);
      }
      param_2 = param_2 + 1;
      uVar3 = uVar3 - 1;
    } while (uVar3 != 0);
  }
  NdisReleaseRWLock(*(undefined8 *)(param_1 + 0x5e8),&local_res18);
  return;
}



===== lbfoHandleOidQueryCurrentState @ 1c000e248 =====

undefined8 lbfoHandleOidQueryCurrentState(longlong param_1,longlong param_2)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  longlong *plVar7;
  byte bVar8;
  undefined2 local_res10;
  undefined1 local_res12;
  
  lVar2 = *(longlong *)(param_2 + 0x28);
  local_res10 = 0;
  local_res12 = 0;
  if (*(uint *)(param_2 + 0x30) < 0x24) {
    uVar6 = 0xc0010015;
  }
  else if (*(int *)(param_1 + 0x20) == 2) {
    NdisAcquireRWLockRead(*(undefined8 *)(param_1 + 0x5e8),&local_res10,0);
    *(undefined4 *)(lVar2 + 0x10) = *(undefined4 *)(param_1 + 0x5a8);
    *(undefined4 *)(lVar2 + 0x14) = *(undefined4 *)(param_1 + 0x5a0);
    *(undefined4 *)(lVar2 + 0x18) = *(undefined4 *)(param_1 + 0x8c0);
    uVar1 = *(uint *)(param_2 + 0x30);
    for (plVar7 = (longlong *)((ulonglong)*(uint *)(lVar2 + 0x20) + lVar2);
        plVar7 + 7 <= (longlong *)((ulonglong)uVar1 + lVar2);
        plVar7 = (longlong *)((longlong)plVar7 + (ulonglong)*(uint *)(plVar7 + 2))) {
      bVar8 = 1;
      do {
        lVar3 = *(longlong *)(param_1 + 0x658 + (ulonglong)bVar8 * 8);
        if (((lVar3 != 0) && (*(longlong *)(lVar3 + 0x30) == *plVar7)) &&
           (*(longlong *)(lVar3 + 0x38) == plVar7[1])) {
          lVar4 = *(longlong *)(lVar3 + 0x298);
          if (((*(int *)(lVar4 + 0x5a8) == 1) &&
              (*(longlong *)(lVar4 + 0x928) == *(longlong *)(lVar3 + 0x30))) &&
             (*(longlong *)(lVar4 + 0x930) == *(longlong *)(lVar3 + 0x38))) {
            uVar5 = 1;
          }
          else {
            uVar5 = 0;
          }
          *(undefined4 *)(plVar7 + 5) = uVar5;
          if (*(int *)(lVar3 + 0x2a0) == 0) {
            uVar5 = 0;
          }
          else {
            uVar5 = 0x1000;
            if (*(int *)(lVar3 + 0x2a0) == 1) {
              uVar5 = 1;
            }
          }
          *(undefined4 *)((longlong)plVar7 + 0x2c) = uVar5;
          *(uint *)((longlong)plVar7 + 0x34) = (uint)*(ushort *)(lVar3 + 0xaa);
          uVar5 = *(undefined4 *)(lVar3 + 0x2a0);
          goto LAB_1c000e3b8;
        }
        bVar8 = bVar8 + 1;
      } while (bVar8 < 0x41);
      if (((*(int *)(param_1 + 0x5a8) == 1) && (*(longlong *)(param_1 + 0x928) == *plVar7)) &&
         (*(longlong *)(param_1 + 0x930) == plVar7[1])) {
        uVar5 = 1;
      }
      else {
        uVar5 = 0;
      }
      *(undefined4 *)(plVar7 + 5) = uVar5;
      uVar5 = 6;
      *(undefined4 *)((longlong)plVar7 + 0x2c) = 0x1000;
      *(undefined4 *)((longlong)plVar7 + 0x34) = 1;
LAB_1c000e3b8:
      *(undefined4 *)(plVar7 + 6) = uVar5;
      if (*(uint *)(plVar7 + 2) == 0) break;
    }
    NdisReleaseRWLock(*(undefined8 *)(param_1 + 0x5e8),&local_res10);
    uVar6 = 0;
  }
  else {
    uVar6 = 0xc0010011;
  }
  return uVar6;
}



===== lbfoRefFilterContextsForOid @ 1c000e404 =====

ushort lbfoRefFilterContextsForOid(longlong param_1,longlong param_2)

{
  undefined8 *puVar1;
  ulonglong uVar2;
  undefined8 *puVar3;
  ushort uVar4;
  undefined2 local_res18;
  undefined1 local_res1a;
  
  local_res18 = 0;
  uVar4 = 0;
  local_res1a = 0;
  NdisAcquireRWLockWrite(*(undefined8 *)(param_1 + 0x5e8),&local_res18,0);
  puVar1 = (undefined8 *)(param_1 + 0x10);
  for (puVar3 = (undefined8 *)*puVar1; puVar3 != puVar1; puVar3 = (undefined8 *)*puVar3) {
    if (*(int *)(puVar3 + 0x1d) == 3) {
      *(short *)((longlong)puVar3 + 0xce) = *(short *)((longlong)puVar3 + 0xce) + 1;
      uVar2 = (ulonglong)uVar4;
      uVar4 = uVar4 + 1;
      *(undefined8 **)(param_2 + uVar2 * 8) = puVar3;
      if (uVar4 == 0x20) goto LAB_1c000e4b9;
    }
  }
  for (puVar3 = (undefined8 *)*puVar1; puVar3 != puVar1; puVar3 = (undefined8 *)*puVar3) {
    if (((*(int *)(puVar3 + 0x1d) - 1U & 0xfffffffc) == 0) && (*(int *)(puVar3 + 0x1d) != 3)) {
      *(short *)((longlong)puVar3 + 0xce) = *(short *)((longlong)puVar3 + 0xce) + 1;
      uVar2 = (ulonglong)uVar4;
      uVar4 = uVar4 + 1;
      *(undefined8 **)(param_2 + uVar2 * 8) = puVar3;
      if (uVar4 == 0x20) break;
    }
  }
LAB_1c000e4b9:
  NdisReleaseRWLock(*(undefined8 *)(param_1 + 0x5e8),&local_res18);
  return uVar4;
}



===== lbfoRemoveVmsPort @ 1c000e4f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 lbfoRemoveVmsPort(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined2 local_res8;
  undefined1 local_resa;
  
  lVar1 = *(longlong *)(param_1 + 0x10);
  uVar3 = 0;
  local_res8 = 0;
  local_resa = 0;
  if (*(int *)(param_2 + 0x418) != 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
               &WPP_dce82a7e4eab3c5b73974bacaa7b552c_Traceguids,*(undefined4 *)(param_2 + 0x410));
    }
    NdisAcquireRWLockWrite(*(undefined8 *)(lVar1 + 0x5e8),&local_res8,0);
    lVar2 = lbfoGetVmsPortFromVmsId(lVar1,*(int *)(param_2 + 0x410));
    if ((lVar2 == 0) || (lVar2 == *(longlong *)(lVar1 + 0x650))) {
      uVar3 = 0xc000000d;
    }
    else {
      lbfoRemoveVmsPortInner(lVar1,lVar2);
      (*(code *)(&PTR_lbfoNTHRemoveVmsPort_1c0018138)[(longlong)*(int *)(lVar1 + 0x5a4) * 0xf])
                (lVar1,*(undefined4 *)(param_2 + 0x410));
      lbfoSetCfgMacRebalanceTimer(lVar1);
    }
    NdisReleaseRWLock(*(undefined8 *)(lVar1 + 0x5e8),&local_res8);
  }
  return uVar3;
}



===== lbfoUpdateVmsPort @ 1c000e600 =====

int lbfoUpdateVmsPort(longlong param_1,longlong param_2)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  undefined2 uVar4;
  ushort uVar5;
  undefined2 local_48;
  undefined1 local_46;
  int local_38;
  undefined2 local_34;
  
  lVar1 = *(longlong *)(param_1 + 0x10);
  iVar2 = 0;
  local_48 = 0;
  local_46 = 0;
  if (*(int *)(param_2 + 0x418) != 0) {
    if ((*(int *)(param_2 + 0x8a0) == 0) && (*(short *)(param_2 + 0x8a4) == 0)) {
      iVar2 = *(int *)(param_2 + 0x83e);
      uVar5 = 0;
      uVar4 = *(undefined2 *)(param_2 + 0x842);
    }
    else {
      iVar2 = *(int *)(param_2 + 0x8a0);
      uVar4 = *(undefined2 *)(param_2 + 0x8a4);
      uVar5 = *(ushort *)(param_2 + 0x8a6);
    }
    NdisAcquireRWLockWrite(*(undefined8 *)(lVar1 + 0x5e8),&local_48,0);
    lVar3 = lbfoGetVmsPortFromVmsId(lVar1,*(int *)(param_2 + 0x410));
    if ((lVar3 == 0) || (lVar3 == *(longlong *)(lVar1 + 0x650))) {
      iVar2 = -0x3ffffff3;
    }
    else {
      local_38 = iVar2;
      local_34 = uVar4;
      iVar2 = lbfoUpdateVmsPortInner
                        (lVar1,lVar3,*(uint *)(param_2 + 0x410),*(short *)(param_2 + 0x83c),
                         &local_38,uVar5);
    }
    NdisReleaseRWLock(*(undefined8 *)(lVar1 + 0x5e8),&local_48);
  }
  return iVar2;
}



===== lbfoUpdateVmsPortInner @ 1c000e714 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int lbfoUpdateVmsPortInner
              (longlong param_1,longlong param_2,uint param_3,short param_4,int *param_5,
              ushort param_6)

{
  short sVar1;
  int iVar2;
  longlong lVar3;
  int iVar4;
  undefined1 local_58 [16];
  int local_48;
  short local_44;
  
  lVar3 = *(longlong *)(param_2 + 0x40);
  iVar4 = 0;
  iVar2 = *param_5;
  sVar1 = (short)param_5[1];
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    local_58._0_4_ = *(int *)(lVar3 + 0x18);
    local_58._4_2_ = *(short *)(lVar3 + 0x1c);
    local_48 = iVar2;
    local_44 = sVar1;
    WPP_SF__MAC__MAC_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),WPP_GLOBAL_Control,0xfff,
                        (undefined4 *)local_58,&local_48,(char)*(undefined2 *)(lVar3 + 0x1e),
                        (char)param_6);
  }
  if (((iVar2 == *(int *)(lVar3 + 0x18)) && (sVar1 == *(short *)(lVar3 + 0x1c))) &&
     (param_6 == (*(ushort *)(lVar3 + 0x1e) & 0xfff))) {
    if (param_4 == *(short *)(param_2 + 0x2c)) {
      return 0;
    }
    *(short *)(param_2 + 0x2c) = param_4;
  }
  else {
    lbfoRemoveVmsPortInner(param_1,param_2);
    local_58._0_4_ = iVar2;
    local_58._4_2_ = sVar1;
    iVar4 = lbfoAddVmsPortInner2(param_1,param_3,param_4,(uint6 *)local_58,param_6);
    if (iVar4 == 0) {
      if (*(code **)(&DAT_1c0018140 + (longlong)*(int *)(param_1 + 0x5a4) * 0x78) != (code *)0x0) {
        (**(code **)(&DAT_1c0018140 + (longlong)*(int *)(param_1 + 0x5a4) * 0x78))(param_1,param_3);
      }
      *(byte *)(param_1 + 0x922) = *(byte *)(param_1 + 0x922) | 0x10;
    }
    else {
      (*(code *)(&PTR_lbfoNTHRemoveVmsPort_1c0018138)[(longlong)*(int *)(param_1 + 0x5a4) * 0xf])
                (param_1,param_3);
    }
  }
  lbfoSetCfgMacRebalanceTimer(param_1);
  return iVar4;
}



===== LbfoReceiveNetBufferLists @ 1c000e890 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void LbfoReceiveNetBufferLists
               (longlong param_1,longlong *param_2,int param_3,ulonglong param_4,uint param_5)

{
  byte bVar1;
  longlong lVar2;
  longlong lVar3;
  char cVar4;
  longlong *plVar5;
  longlong *plVar6;
  longlong lVar7;
  int iVar8;
  longlong *plVar9;
  undefined4 in_register_00000084;
  ulonglong uVar10;
  char local_res8;
  undefined2 local_68;
  undefined1 local_66;
  longlong *local_60;
  longlong *local_58;
  longlong *local_50;
  
  uVar10 = CONCAT44(in_register_00000084,param_3);
  iVar8 = (int)param_4;
  lVar2 = *(longlong *)(param_1 + 0x10);
  local_60 = (longlong *)0x0;
  local_58 = (longlong *)0x0;
  local_68 = 0;
  plVar9 = (longlong *)0x0;
  local_66 = 0;
  plVar6 = (longlong *)0x0;
  if ((param_5 & 1) == 0) {
    local_res8 = KfRaiseIrql(2);
    param_4 = param_4 & 0xffffffff;
    param_5 = param_5 | 1;
    uVar10 = (ulonglong)(uint)param_3;
  }
  else {
    local_res8 = '\x02';
  }
  lVar7 = 0;
  if (((((*(char *)(lVar2 + 0x658) == '\0') || (*(int *)(lVar2 + 0x5a8) != 1)) ||
       (lVar7 = _DAT_fffff78000000320, _DAT_fffff78000000320 == 0)) &&
      ((*(longlong *)(&DAT_1c0018040 + (longlong)*(int *)(lVar2 + 0x5a8) * 0x48) == 0 &&
       (((*(byte *)(param_1 + 0xcc) & 2) == 0 || (*(int *)(lVar2 + 0x570) == 0)))))) &&
     ((*(int *)(lVar2 + 0x5a8) != 1 || ((*(byte *)(lVar2 + 0x942) & 4) == 0)))) {
    NdisFIndicateReceiveNetBufferLists(*(undefined8 *)(param_1 + 0x18),param_2,0,param_4,param_5);
    goto LAB_1c000ece1;
  }
  if ((int)uVar10 == 0) {
LAB_1c000ecb6:
    lbfoEtwWritePerNblEvent(2,lVar2,param_2);
LAB_1c000ecc3:
    if ((param_5 & 2) != 0) goto LAB_1c000ece1;
    plVar6 = param_2;
  }
  else {
    local_50 = *(longlong **)(param_1 + 0x10);
    NdisAcquireRWLockRead(local_50[0xbe],&local_68,CONCAT71((int7)(uVar10 >> 8),1),param_4);
    bVar1 = *(byte *)((ulonglong)(param_3 - 1) + 0x4a + param_1);
    if (((bVar1 == 0) ||
        (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x658 + (ulonglong)bVar1 * 8),
        lVar3 == 0)) || (*(char *)(lVar3 + 0x2e0) != '\0')) {
      NdisReleaseRWLock(local_50[0xbe],&local_68);
      goto LAB_1c000ecb6;
    }
    if (((*(int *)(lVar2 + 0x5a8) == 1) && ((*(byte *)(lVar2 + 0x942) & 4) != 0)) &&
       (*(int *)(lVar3 + 0x2a0) != 0)) {
      lbfoEtwWritePerNblEvent(2,lVar2,param_2);
      NdisReleaseRWLock(*(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x5f0),&local_68);
      goto LAB_1c000ecc3;
    }
    if (param_2 == (longlong *)0x0) {
LAB_1c000ec3b:
      NdisReleaseRWLock(*(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x5f0),&local_68);
    }
    else {
      plVar5 = param_2;
      do {
        local_50 = (longlong *)*plVar5;
        *plVar5 = 0;
        if (((lVar7 == 0) ||
            (cVar4 = lbfoVMSIsLoopedBackVMPacket(param_1,(longlong)plVar5,lVar7), cVar4 == '\0')) &&
           ((*(code **)(&DAT_1c0018040 + (longlong)*(int *)(lVar2 + 0x5a8) * 0x48) == (code *)0x0 ||
            (cVar4 = (**(code **)(&DAT_1c0018040 + (longlong)*(int *)(lVar2 + 0x5a8) * 0x48))
                               (param_1,lVar3,plVar5), cVar4 == '\0')))) {
          if (plVar9 == (longlong *)0x0) {
            plVar9 = plVar5;
          }
          else {
            *local_60 = (longlong)plVar5;
          }
          local_60 = plVar5;
        }
        else {
          iVar8 = iVar8 + -1;
          if (plVar6 == (longlong *)0x0) {
            plVar6 = plVar5;
          }
          else {
            *local_58 = (longlong)plVar5;
          }
          local_58 = plVar5;
        }
        plVar5 = local_50;
      } while (local_50 != (longlong *)0x0);
      if (plVar9 == (longlong *)0x0) goto LAB_1c000ec3b;
      if ((((*(byte *)(param_1 + 0xcc) & 2) != 0) && (*(int *)(lVar2 + 0x570) != 0)) &&
         (plVar5 = plVar9, *(int *)(lVar3 + 0x260) != 0)) {
        do {
          *(undefined2 *)((longlong)plVar5 + 0x102) =
               *(undefined2 *)
                (*(longlong *)(lVar3 + 0x268) + (ulonglong)*(ushort *)((longlong)plVar5 + 0x102) * 4
                );
          plVar5 = (longlong *)*plVar5;
        } while (plVar5 != (longlong *)0x0);
      }
      NdisReleaseRWLock(*(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x5f0),&local_68);
      NdisFIndicateReceiveNetBufferLists(*(undefined8 *)(param_1 + 0x18),plVar9,0,iVar8,param_5);
      if (((((*(byte *)(param_1 + 0xcc) & 2) != 0) && (*(int *)(lVar2 + 0x570) != 0)) &&
          ((param_5 & 2) != 0)) && (plVar9 != (longlong *)0x0)) {
        plVar5 = plVar9;
        do {
          *(undefined2 *)((longlong)plVar5 + 0x102) =
               *(undefined2 *)
                (*(longlong *)(lVar2 + 0x578) +
                ((ulonglong)*(ushort *)((longlong)plVar5 + 0x102) * 0x15a + (ulonglong)(param_3 - 1)
                ) * 4);
          plVar5 = (longlong *)*plVar5;
        } while (plVar5 != (longlong *)0x0);
      }
    }
    if (plVar6 == (longlong *)0x0) goto LAB_1c000ece1;
    if ((param_5 & 2) != 0) {
      if (plVar9 != (longlong *)0x0) {
        if (param_2 == plVar9) {
          *local_60 = (longlong)plVar6;
        }
        else {
          *local_58 = (longlong)plVar9;
        }
      }
      goto LAB_1c000ece1;
    }
  }
  NdisFReturnNetBufferLists(*(undefined8 *)(param_1 + 0x18),plVar6,1);
LAB_1c000ece1:
  if (local_res8 != '\x02') {
    KeLowerIrql(local_res8);
  }
  return;
}



===== LbfoReceiveNetBufferListsComplete @ 1c000ed20 =====

void LbfoReceiveNetBufferListsComplete(longlong param_1,undefined8 *param_2,uint param_3)

{
  longlong lVar1;
  undefined8 *puVar2;
  char cVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  longlong local_res8;
  uint local_res18 [2];
  
  lVar1 = *(longlong *)(param_1 + 0x10);
  if ((param_3 & 1) == 0) {
    cVar3 = KfRaiseIrql(2);
    param_3 = param_3 | 1;
  }
  else {
    cVar3 = '\x02';
  }
  if (*(int *)(lVar1 + 0x570) != 0) {
    local_res18[0] = 0;
    puVar5 = param_2;
    while (puVar5 != (undefined8 *)0x0) {
      puVar2 = (undefined8 *)*puVar5;
      *puVar5 = 0;
      if ((*(ushort *)((longlong)puVar5 + 0x102) != 0) &&
         (vmqcGetFirstMappedMNic
                    (lVar1 + 0x240,
                     (ulonglong)*(ushort *)((longlong)puVar5 + 0x102) * 0x568 +
                     *(longlong *)(lVar1 + 0x578),&local_res8,local_res18),
         *(int *)(lVar1 + 0x570) != 0)) {
        puVar4 = puVar5;
        do {
          *(undefined2 *)((longlong)puVar4 + 0x102) =
               *(undefined2 *)
                (*(longlong *)(lVar1 + 0x578) +
                ((ulonglong)*(ushort *)((longlong)puVar4 + 0x102) * 0x15a +
                (ulonglong)(local_res18[0] - 1)) * 4);
          puVar4 = (undefined8 *)*puVar4;
        } while (puVar4 != (undefined8 *)0x0);
      }
      *puVar5 = puVar2;
      puVar5 = puVar2;
    }
  }
  NdisFReturnNetBufferLists(*(undefined8 *)(param_1 + 0x18),param_2,param_3);
  if (cVar3 != '\x02') {
    KeLowerIrql(cVar3);
  }
  return;
}



===== LbfoSendNetBufferLists @ 1c000ee60 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void LbfoSendNetBufferLists(longlong param_1,longlong *param_2,undefined8 param_3,uint param_4)

{
  byte bVar1;
  longlong lVar2;
  longlong lVar3;
  char cVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  int iVar8;
  
  lVar2 = *(longlong *)(param_1 + 0x10);
  uVar6 = param_3;
  if ((param_4 & 1) == 0) {
    cVar4 = KfRaiseIrql(2);
    param_4 = param_4 | 1;
  }
  else {
    cVar4 = '\x02';
  }
  if ((*(byte *)(lVar2 + 0x5fc) & 1) == 0) {
    uVar5 = _DAT_fffff78000000320;
  }
  else {
    uVar5 = KeQueryPerformanceCounter(0);
  }
  iVar8 = (int)param_3;
  if (iVar8 == 0) {
    if (*(char *)(lVar2 + 0x658) != '\0') {
      lbfoLearnMacAddr(param_1,param_2);
    }
    uVar7 = CONCAT71((int7)((ulonglong)uVar6 >> 8),*(char *)(lVar2 + 0x5fa));
    if (*(char *)(lVar2 + 0x5fa) == '\0') {
      lbfoDistributeSentNbls(param_1,param_2,param_4,uVar5);
      goto LAB_1c000efb2;
    }
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
               &WPP_8350595e1e5e37925dc3459e6a3cbd5a_Traceguids,iVar8);
    }
    bVar1 = *(byte *)((ulonglong)(iVar8 - 1) + 0x4a + param_1);
    if (((bVar1 == 0) ||
        (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x658 + (ulonglong)bVar1 * 8),
        lVar3 == 0)) || (*(int *)(lVar3 + 0x2a0) != 0)) {
      lbfoEtwWritePerNblEvent(0,lVar2,param_2);
      NdisFSendNetBufferListsComplete(*(undefined8 *)(param_1 + 0x18),param_2,1);
      goto LAB_1c000efb2;
    }
    uVar7 = CONCAT71((int7)((ulonglong)lVar3 >> 8),*(undefined1 *)(lVar3 + 0x288));
  }
  lbfoSendNblsOnNic(param_1,param_2,uVar7,param_4,uVar5);
LAB_1c000efb2:
  if (cVar4 != '\x02') {
    KeLowerIrql(cVar4);
  }
  return;
}



===== LbfoSendNetBufferListsComplete @ 1c000eff0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void LbfoSendNetBufferListsComplete(longlong param_1,undefined8 *param_2,uint param_3)

{
  longlong lVar1;
  undefined8 *puVar2;
  char cVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  undefined8 *local_res10;
  uint local_res18;
  
  lVar1 = *(longlong *)(param_1 + 0x10);
  puVar4 = (undefined8 *)0x0;
  local_res10 = (undefined8 *)0x0;
  puVar6 = (undefined8 *)0x0;
  puVar5 = (undefined8 *)0x0;
  if ((param_3 & 1) == 0) {
    cVar3 = KfRaiseIrql(2);
    local_res18 = param_3 | 1;
  }
  else {
    cVar3 = '\x02';
    local_res18 = param_3;
  }
  if (param_2 != (undefined8 *)0x0) {
    do {
      puVar2 = (undefined8 *)*param_2;
      *param_2 = 0;
      if ((*(int *)(param_1 + 0xec) == 0) || (param_2[0xf] != *(longlong *)(param_1 + 0x18))) {
        (*(code *)(&PTR_lbfoNTHSendComplete_1c0018108)[(longlong)*(int *)(lVar1 + 0x5a4) * 0xf])
                  (param_1,param_2);
        if (puVar4 == (undefined8 *)0x0) {
          puVar4 = param_2;
        }
        else {
          *local_res10 = param_2;
        }
        local_res10 = param_2;
      }
      else {
        if (puVar6 == (undefined8 *)0x0) {
          puVar6 = param_2;
        }
        else {
          *puVar5 = param_2;
        }
        puVar5 = param_2;
      }
      param_2 = puVar2;
    } while (puVar2 != (undefined8 *)0x0);
    if (puVar6 != (undefined8 *)0x0) {
      lbfoSendCompleteInternalNbls(param_1,puVar6,'\x01');
    }
    if (puVar4 != (undefined8 *)0x0) {
      NdisFSendNetBufferListsComplete(*(undefined8 *)(param_1 + 0x18),puVar4,local_res18);
    }
  }
  if (cVar3 != '\x02') {
    KeLowerIrql(cVar3);
  }
  return;
}



===== WPP_SF_qdq @ 1c000f13c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qdq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_8350595e1e5e37925dc3459e6a3cbd5a_Traceguids,0xb,&local_res20,8,
             &param_5,4,&param_6,8,0);
  return;
}



===== lbfoBucketizeNblsByOutgoingNic @ 1c000f1a4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void lbfoBucketizeNblsByOutgoingNic
               (longlong param_1,undefined8 *param_2,longlong param_3,longlong *param_4,
               longlong *param_5,undefined8 param_6)

{
  longlong lVar1;
  undefined8 *puVar2;
  longlong lVar3;
  byte bVar4;
  ulonglong uVar5;
  
  if (param_2 != (undefined8 *)0x0) {
    lVar1 = *(longlong *)(param_1 + 0x10);
    do {
      puVar2 = (undefined8 *)*param_2;
      *param_2 = 0;
      bVar4 = (*(code *)(&PTR_lbfoNTHGetOutgoingNicId_1c00180f8)
                        [(longlong)*(int *)(lVar1 + 0x5a4) * 0xf])(param_1,param_2,param_6);
      if (bVar4 == 0) {
        if (*param_5 == 0) {
          *param_5 = (longlong)param_2;
        }
        else {
          *(undefined8 **)param_5[1] = param_2;
        }
        param_5[1] = (longlong)param_2;
      }
      else if (bVar4 < 10) {
        uVar5 = (ulonglong)bVar4;
        if (*(longlong *)(param_3 + -0x10 + uVar5 * 0x10) == 0) {
          *(undefined8 **)(param_3 + -0x10 + uVar5 * 0x10) = param_2;
        }
        else {
          **(undefined8 **)(param_3 + -8 + uVar5 * 0x10) = param_2;
        }
        *(undefined8 **)(param_3 + -8 + uVar5 * 0x10) = param_2;
      }
      else {
        lVar3 = *param_4;
        *(byte *)(param_2 + 0xe) = bVar4;
        if (lVar3 == 0) {
          *param_4 = (longlong)param_2;
        }
        else {
          *(undefined8 **)param_4[1] = param_2;
        }
        param_4[1] = (longlong)param_2;
      }
      param_2 = puVar2;
    } while (puVar2 != (undefined8 *)0x0);
  }
  return;
}



===== lbfoDistributeSentNbls @ 1c000f29c =====

void lbfoDistributeSentNbls
               (longlong param_1,longlong *param_2,undefined4 param_3,undefined8 param_4)

{
  uint uVar1;
  longlong *plVar2;
  bool bVar3;
  longlong *plVar4;
  uint *puVar5;
  longlong *plVar6;
  uint *puVar7;
  uint *puVar8;
  uint *puVar9;
  byte bVar10;
  undefined8 local_80;
  undefined4 local_78;
  undefined4 local_74;
  longlong *local_70;
  undefined8 uStack_68;
  longlong *local_60;
  undefined8 uStack_58;
  
  local_60 = (longlong *)0x0;
  uStack_58 = 0;
  puVar7 = (uint *)((ulonglong)SystemReserved1[0x12]._4_4_ * 0x140 + *(longlong *)(param_1 + 0x40));
  local_70 = (longlong *)0x0;
  uStack_68 = 0;
  uVar1 = *puVar7;
  if (uVar1 < 2) {
    bVar3 = true;
    *puVar7 = uVar1 + 1;
    puVar5 = puVar7 + (ulonglong)uVar1 * 0x24 + 2;
  }
  else {
    local_74 = 0;
    local_80 = 1;
    local_78 = 0x10;
    bVar3 = false;
    puVar5 = (uint *)ExAllocatePool3(0x40,0x90,0x5463694e,&local_80,1);
    if (puVar5 == (uint *)0x0) {
      plVar4 = param_2;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                 &WPP_8350595e1e5e37925dc3459e6a3cbd5a_Traceguids,"PerNicNbls");
      }
      for (; plVar4 != (longlong *)0x0; plVar4 = (longlong *)*plVar4) {
        *(undefined4 *)((longlong)plVar4 + 0x8c) = 0xc000009a;
      }
      lbfoEtwWritePerNblEvent(0,*(undefined8 *)(param_1 + 0x10),param_2);
      NdisFSendNetBufferListsComplete(*(undefined8 *)(param_1 + 0x18),param_2,1);
      return;
    }
  }
  puVar9 = puVar5;
  lbfoBucketizeNblsByOutgoingNic
            (param_1,param_2,(longlong)puVar5,(longlong *)&local_70,(longlong *)&local_60,param_4);
  bVar10 = 1;
  puVar8 = puVar5;
  do {
    if (*(longlong **)puVar8 != (longlong *)0x0) {
      puVar9 = (uint *)CONCAT71((int7)((ulonglong)puVar9 >> 8),bVar10);
      lbfoSendNblsOnNic(param_1,*(longlong **)puVar8,(ulonglong)puVar9,param_3,param_4);
      puVar8[2] = 0;
      puVar8[3] = 0;
      puVar8[0] = 0;
      puVar8[1] = 0;
    }
    bVar10 = bVar10 + 1;
    puVar8 = puVar8 + 4;
  } while (bVar10 < 10);
  if (local_70 != (longlong *)0x0) {
    plVar4 = local_70;
    plVar6 = local_70;
    do {
      plVar2 = (longlong *)*plVar4;
      puVar9 = (uint *)CONCAT71((int7)((ulonglong)puVar9 >> 8),(char)plVar4[0xe]);
      if ((plVar2 == (longlong *)0x0) || ((char)plVar4[0xe] != (char)plVar2[0xe])) {
        *plVar4 = 0;
        lbfoSendNblsOnNic(param_1,plVar6,(ulonglong)puVar9,param_3,param_4);
        plVar6 = plVar2;
      }
      plVar4 = plVar2;
    } while (plVar2 != (longlong *)0x0);
  }
  plVar4 = local_60;
  if (local_60 != (longlong *)0x0) {
    lbfoEtwWritePerNblEvent(0,*(undefined8 *)(param_1 + 0x10),local_60);
    NdisFSendNetBufferListsComplete(*(undefined8 *)(param_1 + 0x18),plVar4,1);
  }
  if (bVar3) {
    *puVar7 = *puVar7 - 1;
  }
  else if (puVar5 != (uint *)0x0) {
    ExFreePoolWithTag(puVar5,0x5463694e);
  }
  return;
}



===== lbfoSendCompleteInternalNbls @ 1c000f504 =====

void lbfoSendCompleteInternalNbls(longlong param_1,undefined8 *param_2,char param_3)

{
  int *piVar1;
  longlong lVar2;
  undefined8 *puVar3;
  bool bVar4;
  int iVar5;
  undefined2 local_res18;
  undefined1 local_res1a;
  
  lVar2 = *(longlong *)(param_1 + 0x10);
  bVar4 = false;
  local_res18 = 0;
  iVar5 = 0;
  local_res1a = 0;
  while (param_2 != (undefined8 *)0x0) {
    puVar3 = (undefined8 *)*param_2;
    iVar5 = iVar5 + 1;
    NdisFreeNetBufferList(param_2);
    param_2 = puVar3;
  }
  NdisAcquireRWLockWrite(*(undefined8 *)(lVar2 + 0x5e8),&local_res18,param_3 != '\0');
  piVar1 = (int *)(param_1 + 0xec);
  *piVar1 = *piVar1 - iVar5;
  if (*piVar1 == 0) {
    if (*(int *)(param_1 + 0xe8) == 4) {
      *(undefined4 *)(param_1 + 0xe8) = 2;
      NdisFPauseComplete(*(undefined8 *)(param_1 + 0x18));
    }
    else {
      bVar4 = true;
    }
  }
  NdisReleaseRWLock(*(undefined8 *)(lVar2 + 0x5e8),&local_res18);
  if (bVar4) {
    lbfoPrimeSwitchIfNeeded(lVar2);
  }
  return;
}



===== lbfoSendInternalNblsOnNic @ 1c000f5f0 =====

void lbfoSendInternalNblsOnNic(longlong param_1,longlong *param_2,byte param_3,undefined4 param_4)

{
  char cVar1;
  undefined8 uVar2;
  
  uVar2 = *(undefined8 *)(param_1 + 0x10);
  cVar1 = *(char *)((ulonglong)param_3 + 0x89 + param_1);
  if (cVar1 == '\0') {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
                &WPP_8350595e1e5e37925dc3459e6a3cbd5a_Traceguids,uVar2,param_3);
    }
    lbfoEtwWritePerNblEvent(0,uVar2,param_2);
    lbfoSendCompleteInternalNbls(param_1,param_2,(byte)param_4 & 1);
  }
  else {
    NdisFSendNetBufferLists(*(undefined8 *)(param_1 + 0x18),param_2,cVar1,param_4);
  }
  return;
}



===== lbfoSendNblsOnNic @ 1c000f6a8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void lbfoSendNblsOnNic(longlong param_1,longlong *param_2,ulonglong param_3,undefined4 param_4,
                      undefined8 param_5)

{
  char cVar1;
  longlong lVar2;
  longlong *plVar3;
  longlong lVar4;
  int iVar5;
  longlong *plVar6;
  longlong *plVar7;
  ulonglong uVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong *plVar11;
  bool bVar12;
  undefined2 local_res8;
  undefined1 local_resa;
  
  lVar2 = *(longlong *)(param_1 + 0x10);
  plVar11 = (longlong *)0x0;
  local_res8 = 0;
  plVar9 = (longlong *)0x0;
  local_resa = 0;
  plVar7 = (longlong *)0x0;
  cVar1 = *(char *)((param_3 & 0xff) + 0x89 + param_1);
  plVar10 = (longlong *)0x0;
  if (cVar1 == '\0') {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_qdq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),&WPP_GLOBAL_Control,param_3,lVar2,
                 (char)param_3,(char)param_1);
    }
    lbfoEtwWritePerNblEvent(0,lVar2,param_2);
  }
  else {
    bVar12 = param_2 != (longlong *)0x0;
    plVar6 = param_2;
    param_2 = plVar7;
    uVar8 = param_3;
    if (bVar12) {
      do {
        plVar3 = (longlong *)*plVar6;
        *plVar6 = 0;
        iVar5 = (*(code *)(&PTR_lbfoNTHPrepareForSend_1c0018100)
                          [(longlong)*(int *)(lVar2 + 0x5a4) * 0xf])(param_1,plVar6,uVar8,param_5);
        *(int *)((longlong)plVar6 + 0x8c) = iVar5;
        if (iVar5 == 0) {
          if (plVar11 == (longlong *)0x0) {
            plVar11 = plVar6;
          }
          else {
            *plVar9 = (longlong)plVar6;
          }
          plVar9 = plVar6;
        }
        else {
          if (plVar7 == (longlong *)0x0) {
            plVar7 = plVar6;
          }
          else {
            *plVar10 = (longlong)plVar6;
          }
          plVar10 = plVar6;
        }
        uVar8 = param_3 & 0xff;
        plVar6 = plVar3;
      } while (plVar3 != (longlong *)0x0);
      param_2 = plVar7;
      if (plVar11 != (longlong *)0x0) {
        NdisFSendNetBufferLists(*(undefined8 *)(param_1 + 0x18),plVar11,cVar1,param_4);
      }
    }
    if (param_2 == (longlong *)0x0) {
      return;
    }
    NdisAcquireRWLockRead(*(undefined8 *)(lVar2 + 0x5f0),&local_res8,1);
    lVar4 = *(longlong *)(lVar2 + 0x658 + (param_3 & 0xff) * 8);
    if (lVar4 != 0) {
      lbfoEtwWritePerNblEvent(1,lVar4 + 0x30,param_2);
    }
    NdisReleaseRWLock(*(undefined8 *)(lVar2 + 0x5f0),&local_res8);
  }
  NdisFSendNetBufferListsComplete(*(undefined8 *)(param_1 + 0x18),param_2,1);
  return;
}



===== lbfoAddEtherBcastNbl @ 1c000f87c =====

int lbfoAddEtherBcastNbl(longlong param_1,longlong param_2,undefined8 *param_3,undefined8 param_4)

{
  int iVar1;
  undefined8 *puVar2;
  undefined4 *_Dst;
  ulonglong uVar3;
  
  puVar2 = (undefined8 *)NdisAllocateNetBufferList(*(undefined8 *)(param_1 + 0xf0),0,0);
  if (puVar2 == (undefined8 *)0x0) {
    iVar1 = -0x3fffff66;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
               &WPP_dbe193d5c0c43814dc24485ea343060a_Traceguids,"Nbl");
    }
  }
  else {
    uVar3 = 0;
    puVar2[0xf] = *(undefined8 *)(param_1 + 0x18);
    iVar1 = NdisRetreatNetBufferListDataStart(puVar2,0x40,0,0,0);
    if (iVar1 == 0) {
      if ((*(ushort *)(param_2 + 0x1e) & 0xfff) != 0) {
        *(uint *)(puVar2 + 0x16) =
             ((uint)*(ushort *)(param_2 + 0x1e) << 4 ^ *(uint *)(puVar2 + 0x16)) & 0xfff0 ^
             *(uint *)(puVar2 + 0x16);
      }
      _Dst = (undefined4 *)NdisGetDataBuffer(puVar2[1],0x40,0,2,uVar3 & 0xffffffff00000000);
      if (_Dst != (undefined4 *)0x0) {
        memset(_Dst,0,0x40);
        *(undefined4 *)((longlong)_Dst + 6) = *(undefined4 *)(param_2 + 0x18);
        *(undefined2 *)((longlong)_Dst + 10) = *(undefined2 *)(param_2 + 0x1c);
        *_Dst = 0xffffffff;
        *(undefined2 *)(_Dst + 1) = 0xffff;
        *(undefined2 *)(_Dst + 3) = 0x4000;
        *(undefined8 *)(param_2 + 0x58) = param_4;
        *puVar2 = *param_3;
        *param_3 = puVar2;
        return 0;
      }
      iVar1 = -0x3fffff66;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                 &WPP_dbe193d5c0c43814dc24485ea343060a_Traceguids,"EthHeader");
      }
    }
    else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_ds(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                &WPP_dbe193d5c0c43814dc24485ea343060a_Traceguids,iVar1,
                "NdisRetreatNetBufferListDataStart(Nbl, ETH_MIN_FRAME_SIZE, 0, NULL, NULL)");
    }
    NdisFreeNetBufferList(puVar2);
  }
  return iVar1;
}



===== lbfoPrimeSwitchIfNeeded @ 1c000fa78 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void lbfoPrimeSwitchIfNeeded(longlong param_1)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  byte bVar4;
  undefined1 auStack_248 [32];
  undefined2 local_228;
  undefined1 local_226;
  undefined8 local_218 [64];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_248;
  local_228 = 0;
  local_226 = 0;
  NdisAcquireRWLockWrite(*(undefined8 *)(param_1 + 0x5e8),&local_228,0);
  for (puVar2 = *(undefined8 **)(param_1 + 0x10); puVar2 != (undefined8 *)(param_1 + 0x10);
      puVar2 = (undefined8 *)*puVar2) {
    if (*(int *)(puVar2 + 0x1d) == 3) goto LAB_1c000fae1;
  }
  puVar2 = (undefined8 *)0x0;
LAB_1c000fae1:
  bVar4 = *(byte *)(param_1 + 0x922);
  if ((((bVar4 & 1) == 0) || (puVar2 == (undefined8 *)0x0)) ||
     (*(int *)((longlong)puVar2 + 0xec) != 0)) {
    NdisReleaseRWLock(*(undefined8 *)(param_1 + 0x5e8),&local_228);
  }
  else {
    memset(local_218,0,0x200);
    *(byte *)(param_1 + 0x922) = bVar4 & 0xfe;
    iVar1 = (*(code *)(&PTR_lbfoNTHGetSwitchPrimingNbls_1c0018150)
                      [(longlong)*(int *)(param_1 + 0x5a4) * 0xf])
                      (puVar2,local_218,_DAT_fffff78000000320);
    *(int *)((longlong)puVar2 + 0xec) = *(int *)((longlong)puVar2 + 0xec) + iVar1;
    NdisReleaseRWLock(*(undefined8 *)(param_1 + 0x5e8),&local_228);
    bVar4 = 1;
    puVar3 = local_218;
    do {
      if ((longlong *)*puVar3 != (longlong *)0x0) {
        lbfoSendInternalNblsOnNic((longlong)puVar2,(longlong *)*puVar3,bVar4,0);
      }
      bVar4 = bVar4 + 1;
      puVar3 = puVar3 + 1;
    } while (bVar4 < 0x41);
  }
  return;
}



===== lbfoQueuePrimeSwitchIfNeededWorkItem @ 1c000fbe4 =====

void lbfoQueuePrimeSwitchIfNeededWorkItem(longlong param_1)

{
  longlong lVar1;
  
  lVar1 = NdisAllocateIoWorkItem(DAT_1c0018468);
  if (lVar1 != 0) {
    *(short *)(param_1 + 0x920) = *(short *)(param_1 + 0x920) + 1;
    NdisQueueIoWorkItem(lVar1,lbfoPrimeSwitchIfNeededWorkItem,param_1);
  }
  return;
}



===== lbfoTFOConnectNic @ 1c000fc34 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void lbfoTFOConnectNic(longlong param_1,longlong param_2)

{
  bool bVar1;
  char cVar2;
  ulonglong uVar3;
  longlong lVar4;
  
  if ((((*(short *)(param_2 + 0xaa) == 0) || (*(int *)(param_1 + 0x5a8) == 2)) ||
      ((lVar4 = param_1, *(short *)(param_1 + 0x8ec) == 0 &&
       (bVar1 = lbfoTFOConnectOldestNic(param_1), !bVar1)))) || (DAT_1c0018474 == 0)) {
    *(undefined4 *)(param_2 + 0x2e8) = 2;
    (*(code *)(&PTR_lbfoTMConnectNic_1c0018030)[(longlong)*(int *)(param_1 + 0x5a8) * 9])
              (param_1,param_2);
    return;
  }
  if ((Microsoft_Windows_MsLbfoEventProviderEnableBits & 1) != 0) {
    McTemplateK0jd_EtwWriteTransfer(lVar4,&StartingConnectTimerInfo,0,param_2 + 0x30,0);
  }
  SysEventWriteGuid(0x40004234,param_2 + 0x40);
  lbfoSetNicFailureReason(param_2,4,(undefined *)0x0,0);
  *(undefined4 *)(param_2 + 0x2e8) = 1;
  uVar3 = (ulonglong)DAT_1c0018474;
  *(undefined8 *)(param_2 + 0x2f8) = _DAT_fffff78000000320;
  cVar2 = NdisSetCoalescableTimerObject
                    (*(undefined8 *)(param_2 + 0x2f0),uVar3 * -10000000,0,param_2,
                     (uint)DAT_1c0018474 * 100);
  if (cVar2 == '\0') {
    *(short *)(param_2 + 0xae) = *(short *)(param_2 + 0xae) + 1;
    return;
  }
  return;
}



===== lbfoTFOConnectNicTimer @ 1c000fd70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void lbfoTFOConnectNicTimer(undefined8 param_1,longlong param_2)

{
  short *psVar1;
  longlong lVar2;
  undefined2 local_res10;
  undefined1 local_res12;
  
  lVar2 = *(longlong *)(param_2 + 0x298);
  local_res10 = 0;
  local_res12 = 0;
  NdisAcquireRWLockWrite(*(undefined8 *)(lVar2 + 0x5e8),&local_res10,1);
  if (*(int *)(param_2 + 0x2e8) == 1) {
    *(undefined4 *)(param_2 + 0x2e8) = 2;
    (*(code *)(&PTR_lbfoTMConnectNic_1c0018030)[(longlong)*(int *)(lVar2 + 0x5a8) * 9])
              (lVar2,param_2);
  }
  psVar1 = (short *)(param_2 + 0xae);
  *psVar1 = *psVar1 + -1;
  if (*psVar1 == 0) {
    KeSetEvent(param_2 + 0xb0,0,0);
  }
  NdisReleaseRWLock(*(undefined8 *)(lVar2 + 0x5e8),&local_res10);
  return;
}



===== lbfoTFOConnectOldestNic @ 1c000fe30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

bool lbfoTFOConnectOldestNic(longlong param_1)

{
  longlong *plVar1;
  char cVar2;
  longlong *plVar3;
  longlong *plVar4;
  longlong *plVar5;
  
  plVar1 = (longlong *)(param_1 + 0x8c8);
  plVar3 = (longlong *)0x0;
  plVar5 = (longlong *)*plVar1;
  if (plVar5 != plVar1) {
    do {
      for (plVar4 = (longlong *)plVar5[3]; plVar4 != plVar5 + 3; plVar4 = (longlong *)*plVar4) {
        if (((int)plVar4[0x5d] == 1) &&
           ((plVar3 == (longlong *)0x0 || ((ulonglong)plVar4[0x5f] < (ulonglong)plVar3[0x5f])))) {
          plVar3 = plVar4;
        }
      }
      plVar5 = (longlong *)*plVar5;
    } while (plVar5 != plVar1);
    if (plVar3 != (longlong *)0x0) {
      cVar2 = NdisCancelTimerObject(plVar3[0x5e]);
      if (cVar2 != '\0') {
        *(short *)((longlong)plVar3 + 0xae) = *(short *)((longlong)plVar3 + 0xae) + -1;
      }
      *(undefined4 *)(plVar3 + 0x5d) = 2;
      (*(code *)(&PTR_lbfoTMConnectNic_1c0018030)[(longlong)*(int *)(param_1 + 0x5a8) * 9])
                (param_1,plVar3);
    }
  }
  return plVar3 != (longlong *)0x0;
}



===== lbfoTFODisconnectNic @ 1c000ff00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void lbfoTFODisconnectNic(longlong param_1,longlong param_2)

{
  int iVar1;
  char cVar2;
  
  if (*(int *)(param_2 + 0x2e8) == 1) {
    cVar2 = NdisCancelTimerObject(*(undefined8 *)(param_2 + 0x2f0));
    if (cVar2 != '\0') {
      *(short *)(param_2 + 0xae) = *(short *)(param_2 + 0xae) + -1;
    }
  }
  iVar1 = *(int *)(param_2 + 0x2e8);
  *(undefined4 *)(param_2 + 0x2e8) = 0;
  if (iVar1 == 2) {
    (*(code *)(&PTR_lbfoTMDisconnectNic_1c0018038)[(longlong)*(int *)(param_1 + 0x5a8) * 9])
              (param_1,param_2);
  }
  if (*(short *)(param_1 + 0x8ec) == 0) {
    lbfoTFOConnectOldestNic(param_1);
  }
  return;
}



===== lbfoUpdateNicPHYState @ 1c000ffa0 =====

void lbfoUpdateNicPHYState(longlong param_1,longlong param_2,undefined8 param_3)

{
  int iVar1;
  
  if (*(int *)(param_2 + 0x2d8) == 1) {
    if (*(int *)(param_2 + 0x2dc) == 1) {
      if (*(int *)(param_2 + 0x2c0) == 1) {
        return;
      }
      if (*(char *)(param_2 + 0x2e0) == '\0') {
        *(undefined4 *)(param_2 + 0x2c0) = 1;
        lbfoTFOConnectNic(param_1,param_2);
        return;
      }
      return;
    }
    iVar1 = 9;
  }
  else {
    iVar1 = 3;
  }
  if ((*(int *)(param_2 + 0x2a0) != iVar1) &&
     (lbfoSetNicFailureReason
                (param_2,iVar1,(undefined *)CONCAT71((int7)((ulonglong)param_3 >> 8),1),0),
     *(int *)(param_2 + 0x2c0) == 1)) {
    *(undefined4 *)(param_2 + 0x2c0) = 0;
    lbfoTFODisconnectNic(param_1,param_2);
  }
  return;
}



===== lbfoUpdateNicState @ 1c0010034 =====

void lbfoUpdateNicState(longlong param_1,byte param_2,longlong param_3)

{
  longlong lVar1;
  int iVar2;
  
  if ((param_2 != 0) &&
     (lVar1 = *(longlong *)(param_1 + 0x658 + (ulonglong)param_2 * 8), lVar1 != 0)) {
    *(undefined8 *)(lVar1 + 0x2c8) = *(undefined8 *)(param_3 + 8);
    *(undefined8 *)(lVar1 + 0x2d0) = *(undefined8 *)(param_3 + 0x10);
    iVar2 = *(int *)(param_3 + 4);
    if ((iVar2 == 1) &&
       (((*(int *)(param_3 + 0x1c) == 1 && (*(int *)(param_3 + 0x24) != 1)) ||
        ((iVar2 = 1, *(int *)(param_3 + 0x20) == 1 && (*(int *)(param_3 + 0x28) != 1)))))) {
      iVar2 = 2;
    }
    *(int *)(lVar1 + 0x2d8) = iVar2;
    lbfoUpdateNicPHYState(param_1,lVar1,param_3);
  }
  return;
}



===== lbfoCalculateVmqCaps @ 1c00100b0 =====

void lbfoCalculateVmqCaps(longlong param_1)

{
  longlong *plVar1;
  bool bVar2;
  longlong *plVar3;
  longlong *plVar4;
  undefined *puVar5;
  undefined8 local_338 [50];
  undefined4 local_1a8 [100];
  
  *(byte *)(param_1 + 0x922) = *(byte *)(param_1 + 0x922) & 0xef;
  if (*(longlong *)(param_1 + 0xa8) == 0) {
    return;
  }
  if ((*(byte *)(*(longlong *)(param_1 + 0xa8) + 0xcc) & 4) != 0) {
    return;
  }
  memset(local_338,0,400);
  puVar5 = (undefined *)0x190;
  memset(local_1a8,0,400);
  bVar2 = false;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    puVar5 = &WPP_ab38e9d2c0e2302a9f2206f49afa20f5_Traceguids;
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
             &WPP_ab38e9d2c0e2302a9f2206f49afa20f5_Traceguids,param_1);
  }
  vmqClearCapabilities((undefined4 *)local_338);
  vmqInitCombinedCapabilities((longlong)local_338,'\x01');
  plVar1 = (longlong *)(param_1 + 0x8c8);
  plVar4 = (longlong *)*plVar1;
  if (plVar4 != plVar1) {
    do {
      if (*(short *)((longlong)plVar4 + 0x2a) != 0) {
        vmqClearCapabilities(local_1a8);
        vmqInitCombinedCapabilities((longlong)local_1a8,'\0');
        for (plVar3 = (longlong *)plVar4[3]; plVar3 != plVar4 + 3; plVar3 = (longlong *)*plVar3) {
          if ((int)plVar3[0x54] == 0) {
            puVar5 = (undefined *)0x0;
            vmqIncludeMemberCapabilities((longlong)local_1a8,(longlong)(plVar3 + 0x1a),'\0');
          }
        }
        puVar5 = (undefined *)CONCAT71((int7)((ulonglong)puVar5 >> 8),1);
        vmqIncludeMemberCapabilities((longlong)local_338,(longlong)local_1a8,'\x01');
        bVar2 = true;
      }
      plVar4 = (longlong *)*plVar4;
    } while (plVar4 != plVar1);
    if (bVar2) goto LAB_1c00101f2;
  }
  vmqClearCapabilities((undefined4 *)local_338);
LAB_1c00101f2:
  vmqSetNewCapabilities((undefined8 *)(param_1 + 0x240),local_338,puVar5,'\x01');
  return;
}



===== lbfoProcessMuxVmqStatusIndication @ 1c001022c =====

void lbfoProcessMuxVmqStatusIndication(longlong param_1,longlong param_2)

{
  int iVar1;
  ushort uVar2;
  uint uVar3;
  
  iVar1 = *(int *)(param_2 + 0x14);
  if (iVar1 == 0x40020010) {
    uVar3 = *(uint *)(param_2 + 0x38);
    if (0x54 < uVar3) {
      uVar3 = 0x54;
    }
    memcpy((void *)(param_1 + 0xb0),*(void **)(param_2 + 0x30),(ulonglong)uVar3);
    uVar2 = *(ushort *)(param_1 + 0xb2);
    if ((ushort)uVar3 <= *(ushort *)(param_1 + 0xb2)) {
      uVar2 = (ushort)uVar3;
    }
    *(ushort *)(param_1 + 0xb2) = uVar2;
  }
  else if (iVar1 == 0x40020020) {
    uVar3 = *(uint *)(param_2 + 0x38);
    if (0x54 < uVar3) {
      uVar3 = 0x54;
    }
    memcpy((void *)(param_1 + 0x178),*(void **)(param_2 + 0x30),(ulonglong)uVar3);
    uVar2 = *(ushort *)(param_1 + 0x17a);
    if ((ushort)uVar3 <= *(ushort *)(param_1 + 0x17a)) {
      uVar2 = (ushort)uVar3;
    }
    *(ushort *)(param_1 + 0x17a) = uVar2;
  }
  else if (iVar1 == 0x40020040) {
    uVar3 = *(uint *)(param_2 + 0x38);
    if (0x74 < uVar3) {
      uVar3 = 0x74;
    }
    memcpy((void *)(param_1 + 0x104),*(void **)(param_2 + 0x30),(ulonglong)uVar3);
    uVar2 = *(ushort *)(param_1 + 0x106);
    if ((ushort)uVar3 <= *(ushort *)(param_1 + 0x106)) {
      uVar2 = (ushort)uVar3;
    }
    *(ushort *)(param_1 + 0x106) = uVar2;
  }
  else if (iVar1 == 0x40020050) {
    uVar3 = *(uint *)(param_2 + 0x38);
    if (0x74 < *(uint *)(param_2 + 0x38)) {
      uVar3 = 0x74;
    }
    memcpy((void *)(param_1 + 0x1cc),*(void **)(param_2 + 0x30),(ulonglong)uVar3);
    uVar2 = *(ushort *)(param_1 + 0x1ce);
    if ((ushort)uVar3 <= *(ushort *)(param_1 + 0x1ce)) {
      uVar2 = (ushort)uVar3;
    }
    *(ushort *)(param_1 + 0x1ce) = uVar2;
  }
  return;
}



===== lbfoQueryMuxVmqCaps @ 1c0010354 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void lbfoQueryMuxVmqCaps(longlong param_1)

{
  longlong lVar1;
  undefined1 auStackY_1f8 [32];
  undefined2 local_1b8;
  undefined1 local_1b6;
  undefined8 local_1a8;
  undefined8 uStack_1a0;
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
  undefined4 local_158;
  undefined8 local_154;
  undefined8 uStack_14c;
  undefined8 local_144;
  undefined8 uStack_13c;
  undefined8 local_134;
  undefined8 uStack_12c;
  undefined8 local_124;
  undefined8 uStack_11c;
  undefined8 local_114;
  undefined8 uStack_10c;
  undefined8 local_104;
  undefined8 uStack_fc;
  undefined4 local_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  undefined4 uStack_e8;
  undefined4 local_e4;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined4 local_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 local_90;
  undefined8 local_8c;
  undefined8 uStack_84;
  undefined8 local_7c;
  undefined8 uStack_74;
  undefined8 local_6c;
  undefined8 uStack_64;
  undefined8 local_5c;
  undefined8 uStack_54;
  undefined8 local_4c;
  undefined8 uStack_44;
  undefined8 local_3c;
  undefined8 uStack_34;
  undefined4 local_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_1f8;
  lVar1 = *(longlong *)(param_1 + 0x10);
  local_1b8 = 0;
  local_1b6 = 0;
  memset(&local_1a8,0,400);
  lbfoIssueOidRequestOnFilter
            (*(undefined8 *)(param_1 + 0x18),0x1022d,0,0,&local_1a8,0x54,(undefined4 *)0x0);
  lbfoIssueOidRequestOnFilter
            (*(undefined8 *)(param_1 + 0x18),0x10221,0,0,&local_e0,0x54,(undefined4 *)0x0);
  lbfoIssueOidRequestOnFilter
            (*(undefined8 *)(param_1 + 0x18),0x1022f,0,0,&local_154,0x74,(undefined4 *)0x0);
  lbfoIssueOidRequestOnFilter
            (*(undefined8 *)(param_1 + 0x18),0x1022e,0,0,&local_8c,0x74,(undefined4 *)0x0);
  NdisAcquireRWLockWrite(*(undefined8 *)(lVar1 + 0x5e8),&local_1b8,0);
  if (*(short *)(lVar1 + 0xb2) == 0) {
    *(undefined8 *)(lVar1 + 0xb0) = local_1a8;
    *(undefined8 *)(lVar1 + 0xb8) = uStack_1a0;
    *(undefined8 *)(lVar1 + 0xc0) = local_198;
    *(undefined8 *)(lVar1 + 200) = uStack_190;
    *(undefined8 *)(lVar1 + 0xd0) = local_188;
    *(undefined8 *)(lVar1 + 0xd8) = uStack_180;
    *(undefined8 *)(lVar1 + 0xe0) = local_178;
    *(undefined8 *)(lVar1 + 0xe8) = uStack_170;
    *(undefined4 *)(lVar1 + 0xf0) = local_168;
    *(undefined4 *)(lVar1 + 0xf4) = uStack_164;
    *(undefined4 *)(lVar1 + 0xf8) = uStack_160;
    *(undefined4 *)(lVar1 + 0xfc) = uStack_15c;
    *(undefined4 *)(lVar1 + 0x100) = local_158;
  }
  if (*(short *)(lVar1 + 0x17a) == 0) {
    *(undefined8 *)(lVar1 + 0x178) = local_e0;
    *(undefined8 *)(lVar1 + 0x180) = uStack_d8;
    *(undefined8 *)(lVar1 + 0x188) = local_d0;
    *(undefined8 *)(lVar1 + 400) = uStack_c8;
    *(undefined8 *)(lVar1 + 0x198) = local_c0;
    *(undefined8 *)(lVar1 + 0x1a0) = uStack_b8;
    *(undefined8 *)(lVar1 + 0x1a8) = local_b0;
    *(undefined8 *)(lVar1 + 0x1b0) = uStack_a8;
    *(undefined4 *)(lVar1 + 0x1b8) = local_a0;
    *(undefined4 *)(lVar1 + 0x1bc) = uStack_9c;
    *(undefined4 *)(lVar1 + 0x1c0) = uStack_98;
    *(undefined4 *)(lVar1 + 0x1c4) = uStack_94;
    *(undefined4 *)(lVar1 + 0x1c8) = local_90;
  }
  if (*(short *)(lVar1 + 0x106) == 0) {
    *(undefined8 *)(lVar1 + 0x104) = local_154;
    *(undefined8 *)(lVar1 + 0x10c) = uStack_14c;
    *(undefined8 *)(lVar1 + 0x114) = local_144;
    *(undefined8 *)(lVar1 + 0x11c) = uStack_13c;
    *(undefined8 *)(lVar1 + 0x124) = local_134;
    *(undefined8 *)(lVar1 + 300) = uStack_12c;
    *(undefined8 *)(lVar1 + 0x134) = local_124;
    *(undefined8 *)(lVar1 + 0x13c) = uStack_11c;
    *(undefined8 *)(lVar1 + 0x144) = local_114;
    *(undefined8 *)(lVar1 + 0x14c) = uStack_10c;
    *(undefined8 *)(lVar1 + 0x154) = local_104;
    *(undefined8 *)(lVar1 + 0x15c) = uStack_fc;
    *(undefined4 *)(lVar1 + 0x164) = local_f4;
    *(undefined4 *)(lVar1 + 0x168) = uStack_f0;
    *(undefined4 *)(lVar1 + 0x16c) = uStack_ec;
    *(undefined4 *)(lVar1 + 0x170) = uStack_e8;
    *(undefined4 *)(lVar1 + 0x174) = local_e4;
  }
  if (*(short *)(lVar1 + 0x1ce) == 0) {
    *(undefined8 *)(lVar1 + 0x1cc) = local_8c;
    *(undefined8 *)(lVar1 + 0x1d4) = uStack_84;
    *(undefined8 *)(lVar1 + 0x1dc) = local_7c;
    *(undefined8 *)(lVar1 + 0x1e4) = uStack_74;
    *(undefined8 *)(lVar1 + 0x1ec) = local_6c;
    *(undefined8 *)(lVar1 + 500) = uStack_64;
    *(undefined8 *)(lVar1 + 0x1fc) = local_5c;
    *(undefined8 *)(lVar1 + 0x204) = uStack_54;
    *(undefined8 *)(lVar1 + 0x20c) = local_4c;
    *(undefined8 *)(lVar1 + 0x214) = uStack_44;
    *(undefined8 *)(lVar1 + 0x21c) = local_3c;
    *(undefined8 *)(lVar1 + 0x224) = uStack_34;
    *(undefined4 *)(lVar1 + 0x22c) = local_2c;
    *(undefined4 *)(lVar1 + 0x230) = uStack_28;
    *(undefined4 *)(lVar1 + 0x234) = uStack_24;
    *(undefined4 *)(lVar1 + 0x238) = uStack_20;
    *(undefined4 *)(lVar1 + 0x23c) = local_1c;
  }
  NdisReleaseRWLock(*(undefined8 *)(lVar1 + 0x5e8),&local_1b8);
  return;
}



===== vmqcGetFirstMappedMNic @ 1c0010620 =====

void vmqcGetFirstMappedMNic(longlong param_1,longlong param_2,longlong *param_3,uint *param_4)

{
  byte bVar1;
  longlong lVar2;
  
  lVar2 = *(longlong *)(param_2 + 0x560);
  *param_3 = 0;
  *param_4 = 0;
  if ((lVar2 != 0) && (*(short *)(lVar2 + 0x28) != 0)) {
    bVar1 = *(byte *)(*(longlong *)(lVar2 + 0x18) + 0x288);
    *param_3 = *(longlong *)(lVar2 + 0x18) + 200;
    *param_4 = (uint)*(byte *)((ulonglong)bVar1 + 0x89 + *(longlong *)(param_1 + -0x198));
  }
  return;
}



===== vmqcIssueOidRequest @ 1c001066c =====

void vmqcIssueOidRequest(undefined8 *param_1,undefined4 param_2,int param_3,undefined8 param_4,
                        undefined4 param_5)

{
  lbfoIssueOidRequestOnFilter
            (*param_1,param_2,param_3,
             (uint)*(byte *)(*(longlong *)(param_1[0x3a] + 0xa8) + 0x89 +
                            (ulonglong)*(byte *)(param_1 + 0x38)),param_4,param_5,(undefined4 *)0x0)
  ;
  return;
}



===== SysEventWriteGuid @ 1c00106bc =====

void SysEventWriteGuid(undefined4 param_1,longlong param_2)

{
  NdisWriteEventLogEntry(Global,param_1,0,1,param_2 + 8,0,0);
  return;
}



===== lbfoEtwWritePerNblEvent @ 1c0010700 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void lbfoEtwWritePerNblEvent(int param_1,undefined8 param_2,longlong *param_3)

{
  uint uVar1;
  undefined *puVar2;
  undefined1 auStack_58 [32];
  ulonglong local_28 [4];
  
  if (param_3 != (longlong *)0x0) {
    local_28[2] = __security_cookie ^ (ulonglong)auStack_58;
    do {
      local_28[1] = 0;
      local_28[0] = param_3[0x1f] & 0x7fffffffffffffff;
      if (param_1 == 0) {
        if ((Microsoft_Windows_MsLbfoEventProviderEnableBits & 2) != 0) {
          McTemplateK0pd_EtwWriteTransfer(0,&FailingSendOnTeamNicWarn,local_28,param_2,1);
        }
      }
      else {
        uVar1 = param_1 - 1;
        if (uVar1 == 0) {
          if ((Microsoft_Windows_MsLbfoEventProviderEnableBits & 2) != 0) {
            puVar2 = &FailingSendOnMemberWarn;
            goto LAB_1c001076e;
          }
        }
        else if ((uVar1 == 1) && ((Microsoft_Windows_MsLbfoEventProviderEnableBits & 2) != 0)) {
          puVar2 = &DroppingNBLsOnMemberWarn;
LAB_1c001076e:
          McTemplateK0jd_EtwWriteTransfer((ulonglong)uVar1,puVar2,local_28,param_2,1);
        }
      }
      param_3 = (longlong *)*param_3;
    } while (param_3 != (longlong *)0x0);
  }
  return;
}



===== vmqAllocateAllQueuesOnMNic @ 1c00107ec =====

void vmqAllocateAllQueuesOnMNic(longlong param_1,undefined8 *param_2,int param_3)

{
  int iVar1;
  undefined4 *_Dst;
  longlong lVar2;
  uint uVar3;
  undefined4 *puVar4;
  uint uVar5;
  ulonglong uVar6;
  int local_res8;
  
  local_res8 = 0;
  if ((*(longlong *)(param_1 + 0x338) != 0) && (*(char *)(param_1 + 0x198) == '\0')) {
    uVar3 = *(int *)(param_1 + 0x330) * 0x10 + 0x14;
    _Dst = (undefined4 *)ExAllocatePoolWithTagPriority(0x200,uVar3,0x5156544e,0x10);
    if (_Dst != (undefined4 *)0x0) {
      memset(_Dst,0,(ulonglong)uVar3);
      _Dst[2] = 0x14;
      *_Dst = 0x140180;
      puVar4 = _Dst + 5;
      _Dst[4] = 0x10;
      vmqSetFiltersOnMNic(param_1,param_2,param_3,*(longlong *)(param_1 + 0x338));
      uVar6 = 1;
      if (*(int *)(param_1 + 0x18) != 0) {
        do {
          lVar2 = uVar6 * 0x568 + *(longlong *)(param_1 + 0x338);
          if (((*(int *)(lVar2 + 0x548) != 0) && (param_2[-0x15] == *(longlong *)(lVar2 + 0x560)))
             && (iVar1 = vmqAllocateQueueOnMNic(param_1,param_2,param_3,(void *)(lVar2 + 0x100)),
                iVar1 == 0)) {
            local_res8 = local_res8 + 1;
            iVar1 = vmqSetFiltersOnMNic(param_1,param_2,param_3,lVar2);
            if ((iVar1 == 0) && (*(int *)(lVar2 + 0x548) == 2)) {
              _Dst[3] = _Dst[3] + 1;
              *puVar4 = 0x100180;
              puVar4[2] = *(undefined4 *)(lVar2 + (ulonglong)(param_3 - 1) * 4);
              puVar4 = puVar4 + 4;
            }
          }
          uVar5 = (int)uVar6 + 1;
          uVar6 = (ulonglong)uVar5;
        } while (uVar5 <= *(uint *)(param_1 + 0x18));
        if (((local_res8 != 0) &&
            (iVar1 = vmqcIssueOidRequest(param_2,0x1022b,0xc,_Dst,uVar3), iVar1 == 0)) &&
           (uVar3 = 0, _Dst[3] != 0)) {
          do {
            if (_Dst[(ulonglong)uVar3 * 4 + 8] != 0) {
              lVar2 = (ulonglong)*(uint *)(param_2[0x34] + (ulonglong)(uint)_Dst[7] * 4) * 0x568 +
                      *(longlong *)(param_1 + 0x338);
              vmqClearFiltersOnMNic(param_1,param_2,param_3,lVar2);
              vmqFreeQueueOnMNic(param_2,param_3,lVar2);
            }
            uVar3 = uVar3 + 1;
          } while (uVar3 < (uint)_Dst[3]);
        }
      }
      ExFreePoolWithTag(_Dst,0x5156544e);
    }
  }
  return;
}



===== vmqAllocateQueue @ 1c0010a00 =====

int vmqAllocateQueue(longlong param_1,void *param_2)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  uint uVar4;
  int iVar5;
  void *_Dst;
  size_t _Size;
  undefined2 local_res8;
  undefined1 local_resa;
  uint local_res10 [2];
  undefined8 *local_res18 [2];
  
  local_res8 = 0;
  local_resa = 0;
  iVar2 = -0x3fffffff;
  local_res10[0] = 0;
  local_res18[0] = (undefined8 *)0x0;
  if (*(uint *)(param_1 + 0x18) < *(uint *)((longlong)param_2 + 0xc)) {
    return -0x3ffffff3;
  }
  NdisAcquireRWLockWrite(*(undefined8 *)(param_1 + 0x3a8),&local_res8,0);
  if (*(char *)(param_1 + 0x198) == '\0') {
    uVar4 = *(uint *)((longlong)param_2 + 0xc);
    if (uVar4 == 0) {
      uVar4 = 1;
      if (*(uint *)(param_1 + 0x18) != 0) {
        do {
          if (*(int *)((ulonglong)uVar4 * 0x568 + 0x548 + *(longlong *)(param_1 + 0x338)) == 0)
          goto LAB_1c0010aa9;
          uVar4 = uVar4 + 1;
        } while (uVar4 <= *(uint *)(param_1 + 0x18));
      }
      uVar4 = 0;
LAB_1c0010aa9:
      *(uint *)((longlong)param_2 + 0xc) = uVar4;
      if (uVar4 == 0) {
        iVar5 = -0x3fffff66;
        goto LAB_1c0010ab5;
      }
    }
    _Size = 0x448;
    _Dst = (void *)((ulonglong)uVar4 * 0x568 + *(longlong *)(param_1 + 0x338));
    *(undefined4 *)((longlong)_Dst + 0x548) = 1;
    *(int *)(param_1 + 0x330) = *(int *)(param_1 + 0x330) + 1;
    if (*(ushort *)((longlong)param_2 + 2) < 0x448) {
      _Size = (size_t)*(ushort *)((longlong)param_2 + 2);
    }
    memcpy((void *)((longlong)_Dst + 0x100),param_2,_Size);
    lVar1 = (longlong)_Dst + 0x550;
    *(longlong *)((longlong)_Dst + 0x558) = lVar1;
    *(longlong *)lVar1 = lVar1;
    lVar1 = *(longlong *)(param_1 + -0x198);
    lVar3 = lbfoGetVmsPortFromVmsId(param_1 + -0x240,*(int *)((longlong)_Dst + 0x53c));
    if ((lVar3 == 0) || (*(longlong *)(lVar3 + 0x48) == 0)) {
      uVar4 = 0xffffffff;
    }
    else {
      *(undefined8 *)((longlong)_Dst + 0x560) = *(undefined8 *)(*(longlong *)(lVar3 + 0x48) + 0x20);
      uVar4 = (uint)*(byte *)((ulonglong)*(byte *)(*(longlong *)(lVar3 + 0x48) + 0x288) + 0x89 +
                             lVar1);
    }
    *(uint *)((longlong)_Dst + 0x540) = uVar4;
    *(uint *)((longlong)param_2 + 0x440) = uVar4;
    NdisReleaseRWLock(*(undefined8 *)(param_1 + 0x3a8),&local_res8);
    vmqcGetFirstMappedMNic(param_1,(longlong)_Dst,(longlong *)local_res18,local_res10);
    if ((local_res18[0] == (undefined8 *)0x0) ||
       (iVar2 = vmqAllocateQueueOnMNic
                          (param_1,local_res18[0],local_res10[0],(void *)((longlong)_Dst + 0x100)),
       iVar5 = 0, iVar2 != 0)) {
      memset(_Dst,0,0x568);
      *(int *)(param_1 + 0x330) = *(int *)(param_1 + 0x330) + -1;
      iVar5 = iVar2;
    }
  }
  else {
    iVar5 = -0x3fdcefff;
LAB_1c0010ab5:
    NdisReleaseRWLock(*(undefined8 *)(param_1 + 0x3a8),&local_res8);
  }
  return iVar5;
}



===== vmqAllocateQueueOnMNic @ 1c0010bfc =====

int vmqAllocateQueueOnMNic(longlong param_1,undefined8 *param_2,int param_3,void *param_4)

{
  uint uVar1;
  int iVar2;
  void *_Dst;
  
  uVar1 = 0x448;
  if (*(ushort *)((longlong)param_4 + 2) < 0x448) {
    uVar1 = (uint)*(ushort *)((longlong)param_4 + 2);
  }
  _Dst = (void *)ExAllocatePoolWithTagPriority(0x200,uVar1,0x5156544e,0x10);
  if (_Dst == (void *)0x0) {
    iVar2 = -0x3fffff66;
  }
  else {
    memcpy(_Dst,param_4,(ulonglong)uVar1);
    *(undefined4 *)((longlong)_Dst + 0xc) = 0;
    if (*(longlong *)((longlong)param_4 + 0x18) == 0xffffffff) {
      *(longlong *)((longlong)_Dst + 0x18) = 1L << (*(byte *)(param_2 + -4) & 0x3f);
      *(undefined2 *)((longlong)_Dst + 0x20) = *(undefined2 *)((longlong)param_2 + -0x22);
    }
    iVar2 = vmqcIssueOidRequest(param_2,0x10223,0xc,_Dst,uVar1);
    if (iVar2 == 0) {
      *(undefined4 *)(param_2[0x34] + (ulonglong)*(uint *)((longlong)_Dst + 0xc) * 4) =
           *(undefined4 *)((longlong)param_4 + 0xc);
      *(undefined4 *)
       (*(longlong *)(param_1 + 0x338) +
       ((ulonglong)*(uint *)((longlong)param_4 + 0xc) * 0x15a + (ulonglong)(param_3 - 1)) * 4) =
           *(undefined4 *)((longlong)_Dst + 0xc);
      *(int *)(param_2 + 0x33) = *(int *)(param_2 + 0x33) + 1;
    }
    ExFreePoolWithTag(_Dst,0x5156544e);
  }
  return iVar2;
}



===== vmqAllocateTNicQueueArray @ 1c0010d34 =====

undefined8 vmqAllocateTNicQueueArray(longlong param_1)

{
  uint uVar1;
  void *in_RAX;
  void *_Dst;
  longlong lVar2;
  
  if (*(char *)(param_1 + 0x32c) != '\0') {
    uVar1 = *(int *)(param_1 + 0x18) + 1;
    in_RAX = (void *)(ulonglong)uVar1;
    uVar1 = uVar1 * 0x568;
    if (*(uint *)(param_1 + 0x340) < uVar1) {
      if (*(longlong *)(param_1 + 0x338) != 0) {
        ExFreePoolWithTag(*(longlong *)(param_1 + 0x338),0x5156544e);
      }
      _Dst = (void *)ExAllocatePoolWithTagPriority(0x200,uVar1,0x5156544e,0x10);
      *(void **)(param_1 + 0x338) = _Dst;
      if (_Dst == (void *)0x0) {
        *(undefined4 *)(param_1 + 0x340) = 0;
        return 0;
      }
      *(uint *)(param_1 + 0x340) = uVar1;
      in_RAX = memset(_Dst,0,(ulonglong)uVar1);
      *(undefined4 *)(*(longlong *)(param_1 + 0x338) + 0x548) = 2;
      lVar2 = *(longlong *)(param_1 + 0x338) + 0x550;
      *(longlong *)(*(longlong *)(param_1 + 0x338) + 0x558) = lVar2;
      *(longlong *)lVar2 = lVar2;
    }
  }
  return CONCAT71((int7)((ulonglong)in_RAX >> 8),1);
}



===== vmqChangeQueueParams @ 1c0010e10 =====

int vmqChangeQueueParams(longlong param_1,void *param_2)

{
  undefined8 *puVar1;
  uint uVar2;
  undefined8 uVar3;
  int iVar4;
  undefined8 *puVar5;
  longlong lVar6;
  longlong lVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  longlong *plVar10;
  uint *puVar11;
  uint *puVar12;
  uint *puVar13;
  ulonglong uVar14;
  uint local_res10 [2];
  undefined8 *local_res18;
  longlong local_res20;
  
  puVar13 = (uint *)((longlong)param_2 + 0xc);
  uVar2 = *puVar13;
  local_res10[0] = 0;
  local_res18 = (undefined8 *)0x0;
  if ((uVar2 == 0) || (*(uint *)(param_1 + 0x18) < uVar2)) {
    return -0x3ffffff3;
  }
  plVar10 = (longlong *)(param_1 + 0x338);
  lVar6 = *plVar10;
  lVar7 = (ulonglong)uVar2 * 0x568 + lVar6;
  if (*(int *)(lVar7 + 0x548) == 0) {
    return -0x3ffffff3;
  }
  puVar12 = (uint *)((longlong)param_2 + 4);
  if ((*puVar12 & 0xffff0000) == 0) {
    return -0x3ffffff3;
  }
  vmqcGetFirstMappedMNic(param_1,lVar7,(longlong *)&local_res18,local_res10);
  if (local_res18 != (undefined8 *)0x0) {
    if ((*(int *)(lVar6 + ((ulonglong)(local_res10[0] - 1) + (ulonglong)uVar2 * 0x15a) * 4) != 0) &&
       (iVar4 = vmqSetQueueParamsOnMNic(param_1,local_res18,local_res10[0],param_2), iVar4 != 0)) {
      uVar14 = (ulonglong)*(uint *)((longlong)param_2 + 0xc);
      lVar6 = *plVar10;
      local_res20 = uVar14 * 0x568 + lVar6;
      vmqcGetFirstMappedMNic(param_1,local_res20,(longlong *)&local_res18,local_res10);
      if (local_res18 == (undefined8 *)0x0) {
        return iVar4;
      }
      if (*(int *)(lVar6 + ((ulonglong)(local_res10[0] - 1) + uVar14 * 0x15a) * 4) == 0) {
        return iVar4;
      }
      *(uint *)(local_res20 + 0x104) = *(uint *)(local_res20 + 0x104) | *puVar12 & 0xffff0000;
      vmqSetQueueParamsOnMNic
                (param_1,local_res18,local_res10[0],
                 (void *)(*plVar10 + (ulonglong)*(uint *)((longlong)param_2 + 0xc) * 0x568 + 0x100))
      ;
      *(undefined2 *)((ulonglong)*(uint *)((longlong)param_2 + 0xc) * 0x568 + 0x106 + *plVar10) = 0;
      return iVar4;
    }
    puVar13 = (uint *)((longlong)param_2 + 0xc);
  }
  puVar11 = (uint *)((longlong)param_2 + 4);
  plVar10 = (longlong *)(param_1 + 0x338);
  if ((*puVar12 >> 0x10 & 1) != 0) {
    *(uint *)((ulonglong)*puVar13 * 0x568 + 0x104 + *plVar10) = *puVar12 & 0xffff;
  }
  puVar12 = puVar13;
  if ((*puVar11 & 0x20000) != 0) {
    puVar12 = (uint *)((longlong)param_2 + 0xc);
    uVar3 = *(undefined8 *)((longlong)param_2 + 0x20);
    puVar5 = (undefined8 *)((ulonglong)*puVar13 * 0x568 + 0x118 + *plVar10);
    *puVar5 = *(undefined8 *)((longlong)param_2 + 0x18);
    puVar5[1] = uVar3;
  }
  if ((*puVar11 & 0x40000) != 0) {
    *(undefined4 *)((ulonglong)*puVar13 * 0x568 + 0x128 + *plVar10) =
         *(undefined4 *)((longlong)param_2 + 0x28);
    puVar13 = puVar12;
  }
  if ((*puVar11 & 0x80000) != 0) {
    puVar5 = (undefined8 *)((longlong)param_2 + 0x238);
    lVar6 = 4;
    puVar8 = (undefined8 *)(*(longlong *)(param_1 + 0x338) + (ulonglong)*puVar13 * 0x568 + 0x338);
    do {
      uVar3 = puVar5[1];
      *puVar8 = *puVar5;
      puVar8[1] = uVar3;
      uVar3 = puVar5[3];
      puVar8[2] = puVar5[2];
      puVar8[3] = uVar3;
      uVar3 = puVar5[5];
      puVar8[4] = puVar5[4];
      puVar8[5] = uVar3;
      uVar3 = puVar5[7];
      puVar8[6] = puVar5[6];
      puVar8[7] = uVar3;
      uVar3 = puVar5[9];
      puVar8[8] = puVar5[8];
      puVar8[9] = uVar3;
      uVar3 = puVar5[0xb];
      puVar8[10] = puVar5[10];
      puVar8[0xb] = uVar3;
      uVar3 = puVar5[0xd];
      puVar8[0xc] = puVar5[0xc];
      puVar8[0xd] = uVar3;
      puVar9 = puVar8 + 0x10;
      puVar1 = puVar5 + 0xe;
      uVar3 = puVar5[0xf];
      puVar5 = puVar5 + 0x10;
      puVar8[0xe] = *puVar1;
      puVar8[0xf] = uVar3;
      lVar6 = lVar6 + -1;
      puVar8 = puVar9;
    } while (lVar6 != 0);
    *(undefined4 *)puVar9 = *(undefined4 *)puVar5;
  }
  return 0;
}



===== vmqCleanupMNicState @ 1c00110a4 =====

void vmqCleanupMNicState(longlong param_1)

{
  if (*(longlong *)(param_1 + 0x1a0) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x1a0),0x5156544e);
  }
  return;
}



===== vmqClearCapabilities @ 1c00110d4 =====

void vmqClearCapabilities(undefined4 *param_1)

{
  memset(param_1 + 1,0,0x50);
  *param_1 = 0x540280;
  memset((void *)((longlong)param_1 + 0xc9),0,0x53);
  param_1[0x32] = 0x540280;
  memset((void *)((longlong)param_1 + 0x55),0,0x73);
  param_1[0x15] = 0x200180;
  memset((void *)((longlong)param_1 + 0x11d),0,0x73);
  param_1[0x47] = 0x200180;
  return;
}



===== vmqClearFilter @ 1c0011160 =====

int vmqClearFilter(longlong param_1,longlong param_2)

{
  uint uVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  int iVar5;
  longlong *plVar6;
  
  uVar1 = *(uint *)(param_2 + 8);
  if (((*(uint *)(param_1 + 0x18) < uVar1) ||
      (*(int *)((ulonglong)uVar1 * 0x568 + 0x548 + *(longlong *)(param_1 + 0x338)) == 0)) ||
     (plVar6 = vmqFindFilter(param_1,uVar1,*(int *)(param_2 + 0xc)), plVar6 == (longlong *)0x0)) {
    return -0x3ffffff3;
  }
  iVar5 = vmqClearFilterOnMNics(param_1,(longlong)plVar6);
  if (iVar5 == 0) {
    lVar2 = *plVar6;
    if ((*(longlong **)(lVar2 + 8) != plVar6) ||
       (plVar3 = (longlong *)plVar6[1], (longlong *)*plVar3 != plVar6)) {
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)(3);
      return -0x3ffffff3;
    }
    *plVar3 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar3;
    ExFreePoolWithTag(plVar6,0x5156544e);
  }
  return iVar5;
}



===== vmqClearFilterOnMNic @ 1c0011204 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void vmqClearFilterOnMNic
               (longlong param_1,undefined8 *param_2,int param_3,ulonglong param_4,longlong param_5)

{
  ulonglong uVar1;
  undefined1 auStackY_68 [32];
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_68;
  local_34 = 0;
  uVar1 = (ulonglong)(param_3 - 1);
  local_38 = 0x100180;
  local_30 = *(undefined4 *)
              (*(longlong *)(param_1 + 0x338) + ((param_4 & 0xffffffff) * 0x15a + uVar1) * 4);
  local_2c = *(undefined4 *)(param_5 + 0x10 + uVar1 * 4);
  vmqcIssueOidRequest(param_2,0x10228,1,&local_38,0x10);
  *(undefined4 *)(param_5 + 0x10 + uVar1 * 4) = 0;
  return;
}



===== vmqClearFilterOnMNics @ 1c001129c =====

int vmqClearFilterOnMNics(longlong param_1,longlong param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint local_res8 [2];
  undefined8 *local_res10;
  
  uVar1 = *(uint *)(param_2 + 0x11c);
  local_res8[0] = 0;
  local_res10 = (undefined8 *)0x0;
  vmqcGetFirstMappedMNic
            (param_1,(ulonglong)uVar1 * 0x568 + *(longlong *)(param_1 + 0x338),
             (longlong *)&local_res10,local_res8);
  iVar3 = 0;
  if ((local_res10 != (undefined8 *)0x0) &&
     (*(int *)(param_2 + 0x10 + (ulonglong)(local_res8[0] - 1) * 4) != 0)) {
    iVar2 = vmqClearFilterOnMNic(param_1,local_res10,local_res8[0],(ulonglong)uVar1,param_2);
    iVar3 = 0;
    if (iVar2 != 0) {
      iVar3 = iVar2;
    }
  }
  return iVar3;
}



===== vmqClearFiltersOnMNic @ 1c0011324 =====

void vmqClearFiltersOnMNic(longlong param_1,undefined8 *param_2,int param_3,longlong param_4)

{
  longlong *plVar1;
  longlong *plVar2;
  
  plVar1 = (longlong *)(param_4 + 0x550);
  plVar2 = (longlong *)*plVar1;
  if (plVar2 != plVar1) {
    do {
      if (*(int *)((longlong)plVar2 + (ulonglong)(param_3 - 1) * 4 + 0x10) != 0) {
        vmqClearFilterOnMNic
                  (param_1,param_2,param_3,(ulonglong)*(uint *)(param_4 + 0x10c),(longlong)plVar2);
      }
      plVar2 = (longlong *)*plVar2;
    } while (plVar2 != plVar1);
  }
  return;
}



===== vmqEnumFilters @ 1c00113b0 =====

undefined8 vmqEnumFilters(longlong param_1,longlong param_2)

{
  undefined8 *puVar1;
  undefined4 *puVar2;
  undefined8 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  longlong lVar6;
  int iVar7;
  
  *(undefined4 *)(param_2 + 0x3c) = 0;
  puVar2 = *(undefined4 **)(param_2 + 0x28);
  if ((puVar2 == (undefined4 *)0x0) || (*(uint *)(param_2 + 0x30) < 0x1c)) {
    *(undefined4 *)(param_2 + 0x40) = 0;
    *(undefined4 *)(param_2 + 0x44) = 0x1c;
  }
  else {
    if ((*(byte *)((longlong)puVar2 + 1) < 2) || (*(ushort *)((longlong)puVar2 + 2) < 0x1c)) {
      *(undefined4 *)(param_2 + 0x40) = 4;
      return 0xc00000bb;
    }
    lVar6 = (ulonglong)(uint)puVar2[1] * 0x568 + *(longlong *)(param_1 + 0x338);
    puVar4 = puVar2 + 7;
    *(undefined4 *)(param_2 + 0x40) = 0x1c;
    if ((*(uint *)(param_1 + 0x18) < (uint)puVar2[1]) || (*(int *)(lVar6 + 0x548) == 0)) {
      return 0xc000000d;
    }
    puVar1 = (undefined8 *)(lVar6 + 0x550);
    iVar7 = 0;
    for (puVar3 = (undefined8 *)*puVar1; puVar3 != puVar1; puVar3 = (undefined8 *)*puVar3) {
      iVar7 = iVar7 + 1;
    }
    uVar5 = iVar7 * 0x10 + 0x1c;
    if (uVar5 <= *(uint *)(param_2 + 0x34)) {
      puVar2[5] = 0;
      puVar2[6] = 0;
      puVar2[2] = 0x1c;
      puVar2[4] = 0x10;
      *puVar2 = 0x1c0280;
      puVar2[3] = iVar7;
      for (puVar3 = (undefined8 *)*puVar1; puVar3 != puVar1; puVar3 = (undefined8 *)*puVar3) {
        *puVar4 = 0x100180;
        puVar4[3] = *(undefined4 *)(puVar3 + 0x24);
        puVar4[2] = *(undefined4 *)(puVar3 + 0x23);
        puVar4[1] = *(undefined4 *)((longlong)puVar3 + 0x114);
        puVar4 = puVar4 + 4;
      }
      *(uint *)(param_2 + 0x3c) = uVar5;
      return 0;
    }
    *(uint *)(param_2 + 0x44) = uVar5;
  }
  return 0xc0010016;
}



===== vmqEnumQueues @ 1c00114e0 =====

undefined8 vmqEnumQueues(longlong param_1,longlong param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined8 uVar4;
  longlong lVar5;
  uint uVar6;
  ulonglong uVar7;
  undefined4 *puVar8;
  
  iVar3 = *(int *)(param_1 + 0x330) * 0x448;
  iVar1 = *(int *)(param_2 + 4);
  puVar2 = *(undefined4 **)(param_2 + 0x28);
  uVar6 = iVar3 + 0x458;
  if (iVar1 != 2) {
    uVar6 = iVar3 + 0x10;
  }
  if ((puVar2 == (undefined4 *)0x0) || (*(uint *)(param_2 + 0x30) < uVar6)) {
    *(undefined4 *)(param_2 + 0x34) = 0;
    uVar4 = 0xc0010016;
    *(uint *)(param_2 + 0x38) = uVar6;
  }
  else {
    *puVar2 = 0x100180;
    uVar7 = 1;
    puVar2[3] = 0x448;
    puVar8 = puVar2 + 4;
    puVar2[1] = 0x10;
    iVar3 = *(int *)(param_1 + 0x330);
    puVar2[2] = iVar3;
    if (iVar1 == 2) {
      puVar2[2] = iVar3 + 1;
      uVar7 = 0;
    }
    for (; (uint)uVar7 <= *(uint *)(param_1 + 0x18); uVar7 = (ulonglong)((uint)uVar7 + 1)) {
      lVar5 = uVar7 * 0x568 + *(longlong *)(param_1 + 0x338);
      if (*(int *)(lVar5 + 0x548) != 0) {
        vmqSetQueueInfo(puVar8,lVar5);
        puVar8 = puVar8 + 0x112;
      }
    }
    *(uint *)(param_2 + 0x34) = uVar6;
    uVar4 = 0;
  }
  return uVar4;
}



===== vmqEqualRcvFilterCaps @ 1c00115c0 =====

ulonglong vmqEqualRcvFilterCaps(longlong param_1,longlong param_2)

{
  uint uVar1;
  ulonglong uVar2;
  
  uVar2 = (ulonglong)*(uint *)(param_2 + 8);
  if ((((((*(uint *)(param_1 + 8) == *(uint *)(param_2 + 8)) &&
         (uVar2 = (ulonglong)*(uint *)(param_2 + 0xc),
         *(uint *)(param_1 + 0xc) == *(uint *)(param_2 + 0xc))) &&
        (uVar2 = (ulonglong)*(uint *)(param_2 + 0x14),
        *(uint *)(param_1 + 0x14) == *(uint *)(param_2 + 0x14))) &&
       ((uVar2 = (ulonglong)*(uint *)(param_2 + 0x18),
        *(uint *)(param_1 + 0x18) == *(uint *)(param_2 + 0x18) &&
        (uVar2 = (ulonglong)*(uint *)(param_2 + 0x1c),
        *(uint *)(param_1 + 0x1c) == *(uint *)(param_2 + 0x1c))))) &&
      ((uVar2 = (ulonglong)*(uint *)(param_2 + 0x20),
       *(uint *)(param_1 + 0x20) == *(uint *)(param_2 + 0x20) &&
       ((uVar2 = (ulonglong)*(uint *)(param_2 + 0x10),
        *(uint *)(param_1 + 0x10) == *(uint *)(param_2 + 0x10) &&
        (uVar2 = (ulonglong)*(uint *)(param_2 + 0x24),
        *(uint *)(param_1 + 0x24) == *(uint *)(param_2 + 0x24))))))) &&
     ((uVar2 = (ulonglong)*(uint *)(param_2 + 0x2c),
      *(uint *)(param_1 + 0x2c) == *(uint *)(param_2 + 0x2c) &&
      ((uVar2 = (ulonglong)*(uint *)(param_2 + 0x28),
       *(uint *)(param_1 + 0x28) == *(uint *)(param_2 + 0x28) &&
       (uVar2 = (ulonglong)*(uint *)(param_2 + 0x30),
       *(uint *)(param_1 + 0x30) == *(uint *)(param_2 + 0x30))))))) {
    uVar1 = *(uint *)(param_2 + 0x34);
    uVar2 = (ulonglong)uVar1;
    if (*(uint *)(param_1 + 0x34) == uVar1) {
      return CONCAT71((uint7)(uint3)(uVar1 >> 8),1);
    }
  }
  return uVar2 & 0xffffffffffffff00;
}



===== vmqFindFilter @ 1c0011630 =====

undefined8 * vmqFindFilter(longlong param_1,uint param_2,int param_3)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  
  if ((param_2 <= *(uint *)(param_1 + 0x18)) &&
     (*(int *)(*(longlong *)(param_1 + 0x338) + 0x548 + (ulonglong)param_2 * 0x568) != 0)) {
    puVar2 = (undefined8 *)(*(longlong *)(param_1 + 0x338) + 0x550 + (ulonglong)param_2 * 0x568);
    for (puVar1 = (undefined8 *)*puVar2; puVar1 != puVar2; puVar1 = (undefined8 *)*puVar1) {
      if (*(int *)(puVar1 + 0x24) == param_3) {
        return puVar1;
      }
    }
  }
  return (undefined8 *)0x0;
}



===== vmqFreeAllQueuesOnMNic @ 1c0011684 =====

void vmqFreeAllQueuesOnMNic(longlong param_1,undefined8 *param_2,int param_3)

{
  longlong lVar1;
  uint uVar2;
  ulonglong uVar3;
  
  if (*(longlong *)(param_1 + 0x338) != 0) {
    vmqClearFiltersOnMNic(param_1,param_2,param_3,*(longlong *)(param_1 + 0x338));
    uVar3 = 1;
    if (*(int *)(param_2 + 3) != 0) {
      do {
        uVar2 = *(uint *)(param_2[0x34] + uVar3 * 4);
        if ((uVar2 != 0) &&
           (lVar1 = (ulonglong)uVar2 * 0x568 + *(longlong *)(param_1 + 0x338),
           *(int *)(lVar1 + 0x548) != 0)) {
          vmqClearFiltersOnMNic(param_1,param_2,param_3,lVar1);
          vmqFreeQueueOnMNic(param_2,param_3,lVar1);
        }
        uVar2 = (int)uVar3 + 1;
        uVar3 = (ulonglong)uVar2;
      } while (uVar2 <= *(uint *)(param_2 + 3));
    }
  }
  return;
}



===== vmqFreeQueue @ 1c0011730 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int vmqFreeQueue(undefined8 *param_1,longlong param_2)

{
  uint uVar1;
  longlong lVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  undefined1 auStack_68 [32];
  uint local_48 [2];
  undefined8 *local_40;
  undefined4 local_38;
  undefined4 local_34;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_68;
  uVar1 = *(uint *)(param_2 + 8);
  if ((uVar1 == 0) || (*(uint *)(param_1 + 3) < uVar1)) {
    return -0x3ffffff3;
  }
  lVar2 = param_1[0x67];
  lVar5 = (ulonglong)uVar1 * 0x568 + lVar2;
  if (*(int *)(lVar5 + 0x548) == 0) {
    return -0x3ffffff3;
  }
  local_48[0] = 0;
  local_40 = (undefined8 *)0x0;
  vmqcGetFirstMappedMNic((longlong)param_1,lVar5,(longlong *)&local_40,local_48);
  if (local_40 != (undefined8 *)0x0) {
    iVar4 = 0;
    if (*(int *)(lVar2 + ((ulonglong)(local_48[0] - 1) + (ulonglong)uVar1 * 0x15a) * 4) != 0) {
      iVar3 = vmqFreeQueueOnMNic(local_40,local_48[0],lVar5);
      iVar4 = 0;
      if (iVar3 != 0) {
        iVar4 = iVar3;
      }
    }
    if (iVar4 != 0) {
      return iVar4;
    }
  }
  local_38 = *(undefined4 *)(param_2 + 8);
  local_40 = (undefined8 *)0x100180;
  local_34 = 3;
  lbfoGenerateStatusIndication(*param_1,0x4002000d,&local_40,0x10);
  memset((void *)((ulonglong)*(uint *)(param_2 + 8) * 0x568 + param_1[0x67]),0,0x568);
  return 0;
}



===== vmqFreeQueueOnMNic @ 1c0011858 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void vmqFreeQueueOnMNic(undefined8 *param_1,int param_2,longlong param_3)

{
  int iVar1;
  undefined1 auStackY_68 [32];
  undefined4 local_38;
  undefined4 local_34;
  uint local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_68;
  local_34 = 0;
  local_30 = *(uint *)(param_3 + (ulonglong)(param_2 - 1U) * 4);
  local_38 = 0xc0180;
  KeClearEvent(param_1 + 0x35);
  iVar1 = vmqcIssueOidRequest(param_1,0x10224,1,&local_38,0xc);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1[0x34] + (ulonglong)local_30 * 4) = 0;
    *(int *)(param_1 + 0x33) = *(int *)(param_1 + 0x33) + -1;
    *(undefined4 *)(param_3 + (ulonglong)(param_2 - 1U) * 4) = 0;
  }
  return;
}



===== vmqGenerateCapsChangeIndications @ 1c0011904 =====

void vmqGenerateCapsChangeIndications(undefined8 *param_1,longlong param_2)

{
  lbfoGenerateStatusIndication(*param_1,0x40020020,param_2 + 200,0x54);
  lbfoGenerateStatusIndication(*param_1,0x40020050,param_2 + 0x11c,0x74);
  if (*(char *)((longlong)param_1 + 0x32c) != '\0') {
    lbfoGenerateStatusIndication(*param_1,0x40020010,param_2,0x54);
    lbfoGenerateStatusIndication(*param_1,0x40020040,param_2 + 0x54,0x74);
  }
  return;
}



===== vmqIncludeMemberCapabilities @ 1c0011990 =====

void vmqIncludeMemberCapabilities(longlong param_1,longlong param_2,char param_3)

{
  uint uVar1;
  uint uVar2;
  
  vmqUpdateRcvFilterCaps(param_1 + 200,param_2 + 200,param_3);
  uVar2 = *(uint *)(param_1 + 0x128);
  uVar1 = *(uint *)(param_2 + 0x128);
  if (param_3 == '\0') {
    if (uVar1 <= uVar2) {
      uVar2 = uVar1;
    }
    *(uint *)(param_1 + 0x128) = uVar2;
  }
  else {
    *(uint *)(param_1 + 0x128) = uVar2 + uVar1;
    if (*(int *)(param_2 + 0x128) == 0) goto LAB_1c0011a18;
  }
  uVar2 = *(uint *)(param_1 + 300);
  if (*(uint *)(param_2 + 300) <= *(uint *)(param_1 + 300)) {
    uVar2 = *(uint *)(param_2 + 300);
  }
  *(uint *)(param_1 + 300) = uVar2;
  uVar2 = *(uint *)(param_1 + 0x130);
  if (*(uint *)(param_2 + 0x130) <= *(uint *)(param_1 + 0x130)) {
    uVar2 = *(uint *)(param_2 + 0x130);
  }
  *(uint *)(param_1 + 0x130) = uVar2;
LAB_1c0011a18:
  vmqUpdateRcvFilterCaps(param_1,param_2,param_3);
  uVar2 = *(uint *)(param_1 + 0x60);
  uVar1 = *(uint *)(param_2 + 0x60);
  if (param_3 == '\0') {
    if (uVar1 <= uVar2) {
      uVar2 = uVar1;
    }
    *(uint *)(param_1 + 0x60) = uVar2;
  }
  else {
    *(uint *)(param_1 + 0x60) = uVar2 + uVar1;
    if (*(int *)(param_2 + 0x60) == 0) {
      return;
    }
  }
  uVar2 = *(uint *)(param_1 + 100);
  if (*(uint *)(param_2 + 100) <= *(uint *)(param_1 + 100)) {
    uVar2 = *(uint *)(param_2 + 100);
  }
  *(uint *)(param_1 + 100) = uVar2;
  uVar2 = *(uint *)(param_1 + 0x68);
  if (*(uint *)(param_2 + 0x68) <= *(uint *)(param_1 + 0x68)) {
    uVar2 = *(uint *)(param_2 + 0x68);
  }
  *(uint *)(param_1 + 0x68) = uVar2;
  return;
}



===== vmqIndicateNewCaps @ 1c0011a7c =====

void vmqIndicateNewCaps(undefined8 *param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  undefined8 uVar7;
  undefined8 *puVar8;
  longlong lVar9;
  
  lVar9 = 3;
  puVar4 = param_1 + 1;
  puVar5 = (undefined8 *)((longlong)param_1 + 0x19c);
  do {
    puVar8 = puVar5;
    puVar6 = puVar4;
    uVar7 = puVar8[1];
    uVar1 = puVar8[2];
    uVar2 = puVar8[3];
    *puVar6 = *puVar8;
    puVar6[1] = uVar7;
    uVar7 = puVar8[4];
    uVar3 = puVar8[5];
    puVar6[2] = uVar1;
    puVar6[3] = uVar2;
    uVar1 = puVar8[6];
    uVar2 = puVar8[7];
    puVar6[4] = uVar7;
    puVar6[5] = uVar3;
    uVar7 = puVar8[8];
    uVar3 = puVar8[9];
    puVar6[6] = uVar1;
    puVar6[7] = uVar2;
    uVar1 = puVar8[10];
    uVar2 = puVar8[0xb];
    puVar6[8] = uVar7;
    puVar6[9] = uVar3;
    uVar7 = puVar8[0xc];
    uVar3 = puVar8[0xd];
    puVar6[10] = uVar1;
    puVar6[0xb] = uVar2;
    uVar1 = puVar8[0xe];
    uVar2 = puVar8[0xf];
    puVar6[0xc] = uVar7;
    puVar6[0xd] = uVar3;
    puVar6[0xe] = uVar1;
    puVar6[0xf] = uVar2;
    lVar9 = lVar9 + -1;
    puVar4 = puVar6 + 0x10;
    puVar5 = puVar8 + 0x10;
  } while (lVar9 != 0);
  uVar7 = puVar8[0x11];
  puVar6[0x10] = puVar8[0x10];
  puVar6[0x11] = uVar7;
  vmqGenerateCapsChangeIndications(param_1,(longlong)(param_1 + 1));
  if ((*(char *)((longlong)param_1 + 0x32c) == '\0') ||
     (uVar7 = vmqAllocateTNicQueueArray((longlong)param_1), (char)uVar7 != '\0')) {
    KeSetEvent(param_1 + 0x69,0,0);
    vmqIndicateQueueAllocState(param_1,'\x01');
    return;
  }
  return;
}



===== vmqIndicateQueueAllocState @ 1c0011b3c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void vmqIndicateQueueAllocState(undefined8 *param_1,char param_2)

{
  undefined1 auStack_1c8 [32];
  undefined4 local_1a8 [100];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_1c8;
  memset(local_1a8,0,400);
  if (param_2 == '\0') {
    vmqClearCapabilities(local_1a8);
    lbfoGenerateStatusIndication(*param_1,0x40020010,local_1a8,0x54);
  }
  return;
}



===== vmqInitCombinedCapabilities @ 1c0011bc0 =====

void vmqInitCombinedCapabilities(longlong param_1,char param_2)

{
  *(undefined4 *)(param_1 + 0xcc) = 0;
  *(undefined8 *)(param_1 + 0xf0) = 0;
  *(undefined4 *)(param_1 + 0xf8) = 0;
  *(undefined4 *)(param_1 + 0xfc) = 0xffffffff;
  *(undefined4 *)(param_1 + 0xd0) = 1;
  *(undefined4 *)(param_1 + 0xd4) = 1;
  *(undefined4 *)(param_1 + 0xe4) = 1;
  *(undefined4 *)(param_1 + 0xe0) = 3;
  *(undefined4 *)(param_1 + 0xe8) = 0x1f;
  *(uint *)(param_1 + 0xdc) = (-(uint)(param_2 != '\0') & 0x40) + 0x7f;
  *(uint *)(param_1 + 0xec) = ~-(uint)(param_2 != '\0');
  *(uint *)(param_1 + 0xd8) = ~-(uint)(param_2 != '\0');
  *(undefined8 *)(param_1 + 0x120) = 0;
  *(undefined8 *)(param_1 + 0x134) = 0;
  *(undefined4 *)(param_1 + 300) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x130) = 0xffffffff;
  *(uint *)(param_1 + 0x128) = ~-(uint)(param_2 != '\0');
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined8 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 8) = 1;
  *(undefined4 *)(param_1 + 0xc) = 1;
  *(undefined4 *)(param_1 + 0x1c) = 1;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x18) = 3;
  *(undefined4 *)(param_1 + 0x20) = 0x1f;
  *(uint *)(param_1 + 0x14) = (-(uint)(param_2 != '\0') & 0x40) + 0x7f;
  *(uint *)(param_1 + 0x24) = ~-(uint)(param_2 != '\0');
  *(uint *)(param_1 + 0x10) = ~-(uint)(param_2 != '\0');
  *(undefined8 *)(param_1 + 0x58) = 0;
  *(undefined8 *)(param_1 + 0x6c) = 0;
  *(undefined4 *)(param_1 + 100) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x68) = 0xffffffff;
  *(uint *)(param_1 + 0x60) = ~-(uint)(param_2 != '\0');
  return;
}



===== vmqInitMNicState @ 1c0011cec =====

void vmqInitMNicState(undefined8 *param_1,undefined8 param_2)

{
  void *_Dst;
  
  *param_1 = param_2;
  vmqcIssueOidRequest(param_1,0x1022d,0,param_1 + 1,0x54);
  vmqcIssueOidRequest(param_1,0x10221,0,param_1 + 0x1a,0x54);
  vmqcIssueOidRequest(param_1,0x1022f,0,(longlong)param_1 + 0x5c,0x74);
  vmqcIssueOidRequest(param_1,0x1022e,0,(longlong)param_1 + 0x124,0x74);
  if (*(int *)(param_1 + 3) != 0) {
    _Dst = (void *)ExAllocatePoolWithTagPriority
                             (0x200,(ulonglong)(*(int *)(param_1 + 3) + 1) << 2,0x5156544e,0x10);
    param_1[0x34] = _Dst;
    if (_Dst == (void *)0x0) {
      memset((void *)((longlong)param_1 + 9),0,0x53);
      *(undefined4 *)(param_1 + 1) = 0x540280;
      memset((void *)((longlong)param_1 + 0x5d),0,0x73);
      *(undefined4 *)((longlong)param_1 + 0x5c) = 0x200180;
    }
    else {
      memset(_Dst,0,(ulonglong)(*(int *)(param_1 + 3) + 1) << 2);
      KeInitializeEvent(param_1 + 0x35,0,0);
    }
  }
  return;
}



===== vmqInterceptOidRequest @ 1c0011e2c =====

undefined8 vmqInterceptOidRequest(undefined8 *param_1,longlong param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  undefined8 uVar3;
  ushort uVar4;
  undefined2 local_res10;
  undefined1 local_res12;
  byte bVar5;
  undefined1 uVar6;
  code *pcVar7;
  
  iVar2 = *(int *)(param_2 + 4);
  local_res10 = 0;
  local_res12 = 0;
  if (iVar2 == 0) {
LAB_1c001200d:
    iVar2 = *(int *)(param_2 + 0x20);
    if (iVar2 == 0x10221) {
      pcVar7 = vmqQueryRcvFilterHwCaps;
LAB_1c001207f:
      uVar4 = 0x54;
      uVar6 = 2;
    }
    else {
      if (iVar2 == 0x10222) {
        uVar4 = 0x10;
        pcVar7 = vmqQueryRcvFilterGlobalParams;
      }
      else {
        if (iVar2 == 0x10225) {
          uVar3 = vmqEnumQueues((longlong)param_1,param_2);
          goto LAB_1c0011ec6;
        }
        if (iVar2 == 0x1022d) {
          pcVar7 = vmqQueryRcvFilterCaps;
          goto LAB_1c001207f;
        }
        if ((iVar2 != 0x1022e) && (iVar2 != 0x1022f)) {
          return 0;
        }
        pcVar7 = vmqQueryNicSwitchHwCaps;
        uVar4 = 0x20;
      }
      uVar6 = 1;
    }
    uVar3 = vmqVerifyQueryOidParamsAndCallHandler(param_1,param_2,param_3,uVar4,uVar6,pcVar7);
    goto LAB_1c0012097;
  }
  if (iVar2 == 1) {
    iVar2 = *(int *)(param_2 + 0x20);
    if (iVar2 == 0x10224) {
      uVar3 = vmqVerifySetOidParamsAndCallHandler
                        ((longlong)param_1,param_2,param_3,0xc,1,vmqFreeQueue);
      if (*param_3 == 0) {
        NdisAcquireRWLockWrite(param_1[0x75],&local_res10,0);
        piVar1 = (int *)(param_1 + 0x66);
        *piVar1 = *piVar1 + -1;
        if ((*piVar1 == 0) && (*(char *)(param_1 + 0x33) != '\0')) {
          iVar2 = *param_3;
          *(undefined8 *)(param_1[-0x33] + 0x100) = 0;
          NdisFOidRequestComplete(*param_1,param_2,iVar2);
          vmqIndicateNewCaps(param_1);
          *(undefined1 *)(param_1 + 0x33) = 0;
          *param_3 = 0x103;
        }
        uVar3 = NdisReleaseRWLock(param_1[0x75],&local_res10);
      }
    }
    else {
      if (iVar2 == 0x10226) {
        uVar4 = 0x444;
        pcVar7 = vmqChangeQueueParams;
        bVar5 = 2;
      }
      else {
        if (iVar2 != 0x10228) {
          return 0;
        }
        pcVar7 = vmqClearFilter;
        uVar4 = 0x10;
        bVar5 = 1;
      }
      uVar3 = vmqVerifySetOidParamsAndCallHandler
                        ((longlong)param_1,param_2,param_3,uVar4,bVar5,pcVar7);
    }
    goto LAB_1c0012097;
  }
  if (iVar2 == 2) goto LAB_1c001200d;
  if (iVar2 != 0xc) {
    return 0;
  }
  iVar2 = *(int *)(param_2 + 0x20);
  if (iVar2 == 0x10223) {
    uVar4 = 0x444;
    pcVar7 = vmqAllocateQueue;
LAB_1c0011ee4:
    bVar5 = 2;
  }
  else {
    if (iVar2 == 0x10226) {
      uVar4 = 0x444;
      pcVar7 = vmqQueryQueueParams;
      goto LAB_1c0011ee4;
    }
    if (iVar2 == 0x10227) {
      uVar4 = 0x2c;
      pcVar7 = vmqSetFilter;
      goto LAB_1c0011ee4;
    }
    if (iVar2 == 0x10229) {
      uVar3 = vmqEnumFilters((longlong)param_1,param_2);
LAB_1c0011ec6:
      *param_3 = (int)uVar3;
      goto LAB_1c0012097;
    }
    if (iVar2 == 0x1022a) {
      uVar3 = vmqQueryFilterParams((longlong)param_1,param_2);
      goto LAB_1c0011ec6;
    }
    if (iVar2 != 0x1022b) {
      return 0;
    }
    uVar4 = 0x14;
    pcVar7 = vmqQueueAllocationComplete;
    bVar5 = 1;
  }
  uVar3 = vmqVerifyMethodOidParamsAndCallHandler
                    ((longlong)param_1,param_2,param_3,uVar4,bVar5,pcVar7);
LAB_1c0012097:
  return CONCAT71((int7)((ulonglong)uVar3 >> 8),1);
}



===== vmqQueryFilterParams @ 1c00120b0 =====

undefined8 vmqQueryFilterParams(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 *puVar2;
  uint uVar3;
  int iVar4;
  
  *(undefined4 *)(param_2 + 0x3c) = 0;
  lVar1 = *(longlong *)(param_2 + 0x28);
  iVar4 = 0x2c;
  if ((lVar1 == 0) || (*(uint *)(param_2 + 0x30) < 0x2c)) {
    *(undefined4 *)(param_2 + 0x40) = 0;
    *(undefined4 *)(param_2 + 0x44) = 0x2c;
  }
  else {
    if ((*(byte *)(lVar1 + 1) < 2) || (*(ushort *)(lVar1 + 2) < 0x2c)) {
      *(undefined4 *)(param_2 + 0x40) = 4;
      return 0xc00000bb;
    }
    puVar2 = vmqFindFilter(param_1,*(uint *)(lVar1 + 0xc),*(int *)(lVar1 + 0x10));
    *(int *)(param_2 + 0x40) = iVar4;
    if (puVar2 == (undefined8 *)0x0) {
      return 0xc000000d;
    }
    uVar3 = *(int *)((longlong)puVar2 + 300) * *(int *)(puVar2 + 0x25) + iVar4;
    if (uVar3 <= *(uint *)(param_2 + 0x34)) {
      memcpy(*(void **)(param_2 + 0x28),puVar2 + 0x22,(ulonglong)uVar3);
      *(uint *)(param_2 + 0x3c) = uVar3;
      return 0;
    }
    *(uint *)(param_2 + 0x44) = uVar3;
  }
  return 0xc0010016;
}



===== vmqQueryNicSwitchHwCaps @ 1c0012160 =====

undefined8 vmqQueryNicSwitchHwCaps(longlong param_1,void *param_2)

{
  memcpy(param_2,(void *)(param_1 + 0x5c),(ulonglong)*(ushort *)((longlong)param_2 + 2));
  return 0;
}



===== vmqQueryQueueParams @ 1c0012190 =====

undefined8 vmqQueryQueueParams(longlong param_1,void *param_2)

{
  uint uVar1;
  undefined8 uVar2;
  size_t _Size;
  
  uVar1 = *(uint *)((longlong)param_2 + 0xc);
  if (((uVar1 == 0) || (*(uint *)(param_1 + 0x18) < uVar1)) ||
     (*(int *)((ulonglong)uVar1 * 0x568 + 0x548 + *(longlong *)(param_1 + 0x338)) == 0)) {
    uVar2 = 0xc000000d;
  }
  else {
    _Size = 0x448;
    if (*(ushort *)((longlong)param_2 + 2) < 0x448) {
      _Size = (size_t)*(ushort *)((longlong)param_2 + 2);
    }
    memcpy(param_2,(void *)((ulonglong)uVar1 * 0x568 + *(longlong *)(param_1 + 0x338) + 0x100),_Size
          );
    uVar2 = 0;
  }
  return uVar2;
}



===== vmqQueryRcvFilterCaps @ 1c0012200 =====

undefined8 vmqQueryRcvFilterCaps(longlong param_1,void *param_2)

{
  memcpy(param_2,(void *)(param_1 + 8),(ulonglong)*(ushort *)((longlong)param_2 + 2));
  return 0;
}



===== vmqQueryRcvFilterGlobalParams @ 1c0012230 =====

undefined8 vmqQueryRcvFilterGlobalParams(longlong param_1,longlong param_2)

{
  *(undefined4 *)(param_2 + 4) = 0;
  *(undefined4 *)(param_2 + 8) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)(param_1 + 0x14);
  return 0;
}



===== vmqQueryRcvFilterHwCaps @ 1c0012250 =====

undefined8 vmqQueryRcvFilterHwCaps(longlong param_1,void *param_2)

{
  memcpy(param_2,(void *)(param_1 + 0xd0),(ulonglong)*(ushort *)((longlong)param_2 + 2));
  return 0;
}



===== vmqQueueAllocationComplete @ 1c0012280 =====

undefined8 vmqQueueAllocationComplete(longlong param_1,void *param_2)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  void *_Dst;
  longlong lVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  undefined8 *puVar11;
  longlong local_res20;
  
  if (*(int *)((longlong)param_2 + 0xc) != 0) {
    uVar7 = *(int *)((longlong)param_2 + 0xc) * *(int *)((longlong)param_2 + 0x10) +
            *(int *)((longlong)param_2 + 8);
    _Dst = (void *)ExAllocatePoolWithTagPriority(0x200,uVar7,0x5156544e,0x10);
    if (_Dst == (void *)0x0) {
      return 0xc000009a;
    }
    for (uVar10 = *(uint *)((longlong)param_2 + 8); uVar10 < uVar7;
        uVar10 = uVar10 + *(int *)((longlong)param_2 + 0x10)) {
      *(undefined4 *)((ulonglong)uVar10 + 0xc + (longlong)param_2) = 0xc0000001;
    }
    uVar10 = 1;
    local_res20 = 0;
    do {
      bVar1 = *(byte *)(local_res20 + 0x4a + *(longlong *)(param_1 + -0x198));
      if (bVar1 == 0) {
        puVar11 = (undefined8 *)0xc8;
LAB_1c001233a:
        memcpy(_Dst,param_2,(ulonglong)uVar7);
        uVar8 = *(uint *)((longlong)param_2 + 8);
        if (uVar8 < uVar7) {
          iVar4 = *(int *)((longlong)param_2 + 0x10);
          uVar9 = uVar8;
          do {
            iVar2 = *(int *)(*(longlong *)(param_1 + 0x338) +
                            ((ulonglong)*(uint *)((ulonglong)uVar8 + 8 + (longlong)param_2) * 0x15a
                            + local_res20) * 4);
            if (iVar2 == 0) {
              uVar9 = uVar9 - iVar4;
              *(int *)((longlong)_Dst + 0xc) = *(int *)((longlong)_Dst + 0xc) + -1;
            }
            else {
              *(undefined4 *)((ulonglong)uVar9 + 0xc + (longlong)_Dst) = 0;
              *(int *)((ulonglong)uVar9 + 8 + (longlong)_Dst) = iVar2;
            }
            iVar4 = *(int *)((longlong)param_2 + 0x10);
            uVar8 = uVar8 + iVar4;
            uVar9 = uVar9 + iVar4;
          } while (uVar8 < uVar7);
        }
        if (*(int *)((longlong)_Dst + 0xc) != 0) {
          iVar4 = vmqcIssueOidRequest(puVar11,0x1022b,0xc,_Dst,uVar7);
          uVar8 = *(uint *)((longlong)_Dst + 8);
          uVar9 = 0;
          if (*(int *)((longlong)_Dst + 0xc) != 0) {
            do {
              uVar3 = *(uint *)(puVar11[0x34] +
                               (ulonglong)*(uint *)((ulonglong)uVar8 + 8 + (longlong)_Dst) * 4);
              if ((iVar4 == 0) && (*(int *)((ulonglong)uVar8 + 0xc + (longlong)_Dst) == 0)) {
                for (uVar5 = *(uint *)((longlong)param_2 + 8); uVar5 < uVar7;
                    uVar5 = uVar5 + *(int *)((longlong)param_2 + 0x10)) {
                  if (*(uint *)((ulonglong)uVar5 + 8 + (longlong)param_2) == uVar3) {
                    *(undefined4 *)((ulonglong)uVar5 + 0xc + (longlong)param_2) = 0;
                  }
                }
              }
              else {
                lVar6 = (ulonglong)uVar3 * 0x568;
                vmqClearFiltersOnMNic(param_1,puVar11,uVar10,*(longlong *)(param_1 + 0x338) + lVar6)
                ;
                vmqFreeQueueOnMNic(puVar11,uVar10,*(longlong *)(param_1 + 0x338) + lVar6);
              }
              uVar8 = uVar8 + *(int *)((longlong)_Dst + 0x10);
              uVar9 = uVar9 + 1;
            } while (uVar9 < *(uint *)((longlong)_Dst + 0xc));
          }
        }
      }
      else {
        puVar11 = (undefined8 *)
                  (*(longlong *)
                    (*(longlong *)(*(longlong *)(param_1 + -0x198) + 0x10) + 0x658 +
                    (ulonglong)bVar1 * 8) + 200);
        if (puVar11 != (undefined8 *)0x0) goto LAB_1c001233a;
      }
      local_res20 = local_res20 + 1;
      uVar10 = uVar10 + 1;
    } while (uVar10 < 0x41);
    for (uVar10 = *(uint *)((longlong)param_2 + 8); uVar10 < uVar7;
        uVar10 = uVar10 + *(int *)((longlong)param_2 + 0x10)) {
      if (*(int *)((ulonglong)uVar10 + 0xc + (longlong)param_2) == 0) {
        *(undefined4 *)
         ((ulonglong)*(uint *)((ulonglong)uVar10 + 8 + (longlong)param_2) * 0x568 + 0x548 +
         *(longlong *)(param_1 + 0x338)) = 2;
      }
    }
    ExFreePoolWithTag(_Dst,0x5156544e);
  }
  return 0;
}



===== vmqSetFilter @ 1c0012500 =====

int vmqSetFilter(longlong param_1,void *param_2)

{
  longlong *plVar1;
  code *pcVar2;
  bool bVar3;
  uint uVar4;
  int iVar5;
  longlong *_Dst;
  undefined8 *puVar6;
  uint uVar7;
  longlong lVar8;
  undefined8 *puVar9;
  uint uVar10;
  size_t _Size;
  ulonglong uVar11;
  uint local_res8 [2];
  undefined8 *local_res10;
  
  local_res8[0] = 0;
  iVar5 = 0;
  local_res10 = (undefined8 *)0x0;
  uVar4 = *(uint *)((longlong)param_2 + 0xc);
  uVar10 = *(int *)((longlong)param_2 + 0x1c) * *(int *)((longlong)param_2 + 0x18);
  if ((*(uint *)(param_1 + 0x18) < uVar4) || (uVar4 == 0)) {
    return -0x3ffffff3;
  }
  if (*(int *)((ulonglong)uVar4 * 0x568 + 0x548 + *(longlong *)(param_1 + 0x338)) == 0) {
    return -0x3ffffff3;
  }
  bVar3 = true;
  if (*(int *)((longlong)param_2 + 0x10) == 0) {
    uVar7 = 1;
    puVar9 = (undefined8 *)((ulonglong)uVar4 * 0x568 + *(longlong *)(param_1 + 0x338) + 0x550);
    for (puVar6 = (undefined8 *)*puVar9; (puVar6 != puVar9 && (*(uint *)(puVar6 + 0x24) <= uVar7));
        puVar6 = (undefined8 *)*puVar6) {
      uVar7 = uVar7 + 1;
    }
    uVar4 = 0;
    if (uVar7 <= *(uint *)(param_1 + 0x2c)) {
      uVar4 = uVar7;
    }
    *(uint *)((longlong)param_2 + 0x10) = uVar4;
    if (uVar4 == 0) {
      return -0x3fffff66;
    }
  }
  _Dst = (longlong *)ExAllocatePoolWithTagPriority(0x200,(ulonglong)uVar10 + 0x140,0x5156544e,0x10);
  if (_Dst == (longlong *)0x0) {
    return -0x3fffff66;
  }
  memset(_Dst,0,0x140);
  _Size = (size_t)*(ushort *)((longlong)param_2 + 2);
  if (0x2b < *(ushort *)((longlong)param_2 + 2)) {
    _Size = 0x2c;
  }
  memcpy(_Dst + 0x22,param_2,_Size);
  *(undefined4 *)((longlong)_Dst + 0x124) = 0x2c;
  memcpy((void *)((longlong)_Dst + 0x13c),
         (void *)((ulonglong)*(uint *)((longlong)param_2 + 0x14) + (longlong)param_2),
         (ulonglong)uVar10);
  uVar11 = (ulonglong)*(uint *)((longlong)param_2 + 0xc);
  lVar8 = *(longlong *)(param_1 + 0x338);
  vmqcGetFirstMappedMNic(param_1,uVar11 * 0x568 + lVar8,(longlong *)&local_res10,local_res8);
  if (((local_res10 == (undefined8 *)0x0) ||
      (*(int *)(lVar8 + ((ulonglong)(local_res8[0] - 1) + uVar11 * 0x15a) * 4) == 0)) ||
     (iVar5 = vmqSetFilterOnMNic(param_1,local_res10,local_res8[0],(longlong)_Dst), iVar5 == 0)) {
    uVar4 = *(uint *)((longlong)param_2 + 0x10);
    *(uint *)(_Dst + 0x24) = uVar4;
    *(undefined4 *)((longlong)_Dst + 0x11c) = *(undefined4 *)((longlong)param_2 + 0xc);
    lVar8 = (ulonglong)*(uint *)((longlong)param_2 + 0xc) * 0x568 + *(longlong *)(param_1 + 0x338);
    for (puVar6 = *(undefined8 **)(lVar8 + 0x550); puVar6 != (undefined8 *)(lVar8 + 0x550);
        puVar6 = (undefined8 *)*puVar6) {
      if (uVar4 < *(uint *)(puVar6 + 0x24)) {
        if (!bVar3) goto LAB_1c00126ed;
        plVar1 = (longlong *)(lVar8 + 0x550);
        lVar8 = *plVar1;
        if (*(longlong **)(lVar8 + 8) == plVar1) {
          *_Dst = lVar8;
          _Dst[1] = (longlong)plVar1;
          *(longlong **)(lVar8 + 8) = _Dst;
          *plVar1 = (longlong)_Dst;
          return iVar5;
        }
        goto LAB_1c001272d;
      }
      bVar3 = false;
    }
    puVar6 = (undefined8 *)(lVar8 + 0x550);
LAB_1c00126ed:
    puVar9 = (undefined8 *)puVar6[1];
    if ((undefined8 *)*puVar9 != puVar6) {
LAB_1c001272d:
      pcVar2 = (code *)swi(0x29);
      (*pcVar2)(3);
      return -0x3ffffff3;
    }
    *_Dst = (longlong)puVar6;
    _Dst[1] = (longlong)puVar9;
    *puVar9 = _Dst;
    puVar6[1] = _Dst;
  }
  else {
    vmqClearFilterOnMNics(param_1,(longlong)_Dst);
    ExFreePoolWithTag(_Dst,0x5156544e);
  }
  return iVar5;
}



===== vmqSetFilterOnMNic @ 1c0012758 =====

void vmqSetFilterOnMNic(longlong param_1,undefined8 *param_2,int param_3,longlong param_4)

{
  uint *puVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  bool bVar6;
  int iVar7;
  ulonglong uVar8;
  
  bVar6 = false;
  uVar2 = *(uint *)(param_4 + 0x11c);
  uVar3 = *(undefined4 *)(param_4 + 0x120);
  uVar8 = (ulonglong)*(uint *)(param_4 + 0x124);
  uVar4 = *(undefined4 *)
           (*(longlong *)(param_1 + 0x338) +
           ((ulonglong)uVar2 * 0x15a + (ulonglong)(param_3 - 1)) * 4);
  *(undefined4 *)(param_4 + 0x120) = 0;
  *(undefined4 *)(param_4 + 0x11c) = uVar4;
  if ((((*(int *)(param_4 + 0x128) == 1) && ((*(uint *)(param_2 + 5) & 8) != 0)) &&
      ((*(uint *)(param_1 + 0x28) & 8) == 0)) &&
     (((*(char *)(uVar8 + 0x111 + param_4) != '\0' && (0x37 < *(ushort *)(uVar8 + 0x112 + param_4)))
      && ((*(int *)(uVar8 + 0x120 + param_4) != 4 &&
          (uVar5 = *(uint *)(uVar8 + 0x114 + param_4), (uVar5 & 1) == 0)))))) {
    bVar6 = true;
    *(uint *)(uVar8 + 0x114 + param_4) = uVar5 | 1;
  }
  iVar7 = vmqcIssueOidRequest(param_2,0x10227,0xc,param_4 + 0x110,
                              *(int *)(param_4 + 300) * *(int *)(param_4 + 0x128) + 0x2c);
  if (iVar7 == 0) {
    *(undefined4 *)(param_4 + 0x10 + (ulonglong)(param_3 - 1) * 4) =
         *(undefined4 *)(param_4 + 0x120);
  }
  *(undefined4 *)(param_4 + 0x120) = uVar3;
  *(uint *)(param_4 + 0x11c) = uVar2;
  if (bVar6) {
    puVar1 = (uint *)(uVar8 + 0x114 + param_4);
    *puVar1 = *puVar1 & 0xfffffffe;
  }
  return;
}



===== vmqSetFiltersOnMNic @ 1c001287c =====

int vmqSetFiltersOnMNic(longlong param_1,undefined8 *param_2,int param_3,longlong param_4)

{
  int iVar1;
  undefined8 *puVar2;
  
  puVar2 = *(undefined8 **)(param_4 + 0x550);
  while( true ) {
    if (puVar2 == (undefined8 *)(param_4 + 0x550)) {
      return 0;
    }
    iVar1 = vmqSetFilterOnMNic(param_1,param_2,param_3,(longlong)puVar2);
    if (iVar1 != 0) break;
    puVar2 = (undefined8 *)*puVar2;
  }
  vmqClearFiltersOnMNic(param_1,param_2,param_3,param_4);
  vmqFreeQueueOnMNic(param_2,param_3,param_4);
  return iVar1;
}



===== vmqSetNewCapabilities @ 1c001291c =====

void vmqSetNewCapabilities(undefined8 *param_1,undefined8 *param_2,undefined8 param_3,char param_4)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  ulonglong uVar3;
  undefined8 *puVar4;
  longlong lVar5;
  undefined8 *puVar6;
  
  if (*(char *)((longlong)param_1 + 0x32c) == '\0') {
    memset((void *)((longlong)param_2 + 4),0,0x50);
    *(undefined4 *)param_2 = 0x540280;
    memset((void *)((longlong)param_2 + 0x55),0,0x73);
    *(undefined4 *)((longlong)param_2 + 0x54) = 0x200180;
  }
  else {
    if (*(char *)((longlong)param_1 + 0x32d) == '\0') {
      *(undefined4 *)((longlong)param_2 + 0x34) = 0;
      *(undefined4 *)(param_2 + 6) = 0;
      *(uint *)((longlong)param_2 + 0x14) = *(uint *)((longlong)param_2 + 0x14) & 0xfffffffb;
    }
    if (*(char *)((longlong)param_1 + 0x32e) == '\0') {
      *(uint *)(param_2 + 4) = *(uint *)(param_2 + 4) & 0xfffffff7;
      *(undefined4 *)(param_2 + 0xd) = 0;
    }
  }
  uVar3 = vmqEqualRcvFilterCaps((longlong)(param_1 + 1),(longlong)param_2);
  if (((((((char)uVar3 != '\0') &&
         (uVar3 = vmqEqualRcvFilterCaps((longlong)(param_1 + 0x1a),(longlong)(param_2 + 0x19)),
         (char)uVar3 != '\0')) &&
        (*(int *)((longlong)param_1 + 0x6c) == *(int *)((longlong)param_2 + 100))) &&
       ((*(int *)(param_1 + 0xe) == *(int *)(param_2 + 0xd) &&
        (*(int *)(param_1 + 0xd) == *(int *)(param_2 + 0xc))))) &&
      ((*(int *)((longlong)param_1 + 0x134) == *(int *)((longlong)param_2 + 300) &&
       ((*(int *)(param_1 + 0x27) == *(int *)(param_2 + 0x26) &&
        (*(int *)(param_1 + 0x26) == *(int *)(param_2 + 0x25))))))) && (param_4 == '\0')) {
    KeSetEvent(param_1 + 0x69,0,0);
    return;
  }
  lVar5 = 3;
  puVar2 = (undefined8 *)((longlong)param_1 + 0x19c);
  do {
    puVar6 = param_2;
    puVar4 = puVar2;
    uVar1 = puVar6[1];
    *puVar4 = *puVar6;
    puVar4[1] = uVar1;
    uVar1 = puVar6[3];
    puVar4[2] = puVar6[2];
    puVar4[3] = uVar1;
    uVar1 = puVar6[5];
    puVar4[4] = puVar6[4];
    puVar4[5] = uVar1;
    uVar1 = puVar6[7];
    puVar4[6] = puVar6[6];
    puVar4[7] = uVar1;
    uVar1 = puVar6[9];
    puVar4[8] = puVar6[8];
    puVar4[9] = uVar1;
    uVar1 = puVar6[0xb];
    puVar4[10] = puVar6[10];
    puVar4[0xb] = uVar1;
    uVar1 = puVar6[0xd];
    puVar4[0xc] = puVar6[0xc];
    puVar4[0xd] = uVar1;
    uVar1 = puVar6[0xf];
    puVar4[0xe] = puVar6[0xe];
    puVar4[0xf] = uVar1;
    lVar5 = lVar5 + -1;
    puVar2 = puVar4 + 0x10;
    param_2 = puVar6 + 0x10;
  } while (lVar5 != 0);
  uVar1 = puVar6[0x11];
  puVar4[0x10] = puVar6[0x10];
  puVar4[0x11] = uVar1;
  if (*(char *)(param_1 + 0x33) == '\0') {
    vmqIndicateQueueAllocState(param_1,'\0');
    if (*(int *)(param_1 + 0x66) == 0) {
      vmqIndicateNewCaps(param_1);
    }
    else {
      *(undefined1 *)(param_1 + 0x33) = 1;
    }
  }
  return;
}



===== vmqSetQueueInfo @ 1c0012ac4 =====

void vmqSetQueueInfo(undefined4 *param_1,longlong param_2)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  undefined4 uVar6;
  longlong lVar7;
  int iVar8;
  longlong lVar9;
  
  *param_1 = 0x4480280;
  param_1[1] = *(undefined4 *)(param_2 + 0x104);
  param_1[0xc] = *(undefined4 *)(param_2 + 0x130);
  lVar7 = 4;
  param_1[0xb] = *(undefined4 *)(param_2 + 300);
  lVar9 = 4;
  param_1[10] = *(undefined4 *)(param_2 + 0x128);
  uVar2 = *(undefined8 *)(param_2 + 0x120);
  *(undefined8 *)(param_1 + 6) = *(undefined8 *)(param_2 + 0x118);
  *(undefined8 *)(param_1 + 8) = uVar2;
  param_1[4] = *(undefined4 *)(param_2 + 0x110);
  param_1[3] = *(undefined4 *)(param_2 + 0x10c);
  puVar3 = (undefined8 *)(param_2 + 0x338);
  puVar4 = (undefined8 *)(param_1 + 0x8e);
  do {
    uVar2 = puVar3[1];
    *puVar4 = *puVar3;
    puVar4[1] = uVar2;
    uVar2 = puVar3[3];
    puVar4[2] = puVar3[2];
    puVar4[3] = uVar2;
    uVar2 = puVar3[5];
    puVar4[4] = puVar3[4];
    puVar4[5] = uVar2;
    uVar2 = puVar3[7];
    puVar4[6] = puVar3[6];
    puVar4[7] = uVar2;
    uVar2 = puVar3[9];
    puVar4[8] = puVar3[8];
    puVar4[9] = uVar2;
    uVar2 = puVar3[0xb];
    puVar4[10] = puVar3[10];
    puVar4[0xb] = uVar2;
    uVar2 = puVar3[0xd];
    puVar4[0xc] = puVar3[0xc];
    puVar4[0xd] = uVar2;
    puVar5 = puVar4 + 0x10;
    puVar1 = puVar3 + 0xe;
    uVar2 = puVar3[0xf];
    puVar3 = puVar3 + 0x10;
    puVar4[0xe] = *puVar1;
    puVar4[0xf] = uVar2;
    lVar9 = lVar9 + -1;
    puVar4 = puVar5;
  } while (lVar9 != 0);
  *(undefined4 *)puVar5 = *(undefined4 *)puVar3;
  param_1[2] = *(undefined4 *)(param_2 + 0x108);
  puVar3 = (undefined8 *)(param_2 + 0x134);
  puVar4 = (undefined8 *)(param_1 + 0xd);
  do {
    uVar2 = puVar3[1];
    *puVar4 = *puVar3;
    puVar4[1] = uVar2;
    uVar2 = puVar3[3];
    puVar4[2] = puVar3[2];
    puVar4[3] = uVar2;
    uVar2 = puVar3[5];
    puVar4[4] = puVar3[4];
    puVar4[5] = uVar2;
    uVar2 = puVar3[7];
    puVar4[6] = puVar3[6];
    puVar4[7] = uVar2;
    uVar2 = puVar3[9];
    puVar4[8] = puVar3[8];
    puVar4[9] = uVar2;
    uVar2 = puVar3[0xb];
    puVar4[10] = puVar3[10];
    puVar4[0xb] = uVar2;
    uVar2 = puVar3[0xd];
    puVar4[0xc] = puVar3[0xc];
    puVar4[0xd] = uVar2;
    puVar5 = puVar4 + 0x10;
    puVar1 = puVar3 + 0xe;
    uVar2 = puVar3[0xf];
    puVar3 = puVar3 + 0x10;
    puVar4[0xe] = *puVar1;
    puVar4[0xf] = uVar2;
    lVar7 = lVar7 + -1;
    puVar4 = puVar5;
  } while (lVar7 != 0);
  iVar8 = 0;
  *(undefined4 *)puVar5 = *(undefined4 *)puVar3;
  puVar3 = (undefined8 *)(param_2 + 0x550);
  uVar6 = 1;
  for (puVar4 = (undefined8 *)*puVar3; puVar4 != puVar3; puVar4 = (undefined8 *)*puVar4) {
    iVar8 = iVar8 + 1;
  }
  param_1[0x10f] = iVar8;
  param_1[0x110] = *(undefined4 *)(param_2 + 0x540);
  if ((*(int *)(param_2 + 0x548) != 2) || ((undefined8 *)*puVar3 == puVar3)) {
    uVar6 = 2;
  }
  param_1[5] = uVar6;
  return;
}



===== vmqSetQueueParamsOnMNic @ 1c0012c30 =====

undefined4 vmqSetQueueParamsOnMNic(longlong param_1,undefined8 *param_2,int param_3,void *param_4)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  void *_Dst;
  
  uVar2 = 0x448;
  uVar1 = *(uint *)((longlong)param_4 + 0xc);
  if (*(ushort *)((longlong)param_4 + 2) < 0x448) {
    uVar2 = (uint)*(ushort *)((longlong)param_4 + 2);
  }
  _Dst = (void *)ExAllocatePoolWithTagPriority(0x200,uVar2,0x5156544e,0x10);
  if (_Dst == (void *)0x0) {
    uVar3 = 0xc000009a;
  }
  else {
    memcpy(_Dst,param_4,(ulonglong)uVar2);
    *(undefined4 *)((longlong)_Dst + 0xc) =
         *(undefined4 *)
          (*(longlong *)(param_1 + 0x338) +
          ((ulonglong)uVar1 * 0x15a + (ulonglong)(param_3 - 1)) * 4);
    uVar3 = vmqcIssueOidRequest(param_2,0x10226,1,_Dst,uVar2);
    ExFreePoolWithTag(_Dst,0x5156544e);
  }
  return uVar3;
}



===== vmqUpdateRcvFilterCaps @ 1c0012d20 =====

void vmqUpdateRcvFilterCaps(longlong param_1,longlong param_2,char param_3)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  longlong lVar6;
  
  uVar3 = *(uint *)(param_2 + 0x10);
  if (param_3 == '\0') {
    uVar2 = *(uint *)(param_1 + 0x10);
    if (uVar3 <= *(uint *)(param_1 + 0x10)) {
      uVar2 = uVar3;
    }
    *(uint *)(param_1 + 0x10) = uVar2;
    uVar3 = *(uint *)(param_1 + 0x24);
    if (*(uint *)(param_2 + 0x24) <= *(uint *)(param_1 + 0x24)) {
      uVar3 = *(uint *)(param_2 + 0x24);
    }
    *(uint *)(param_1 + 0x24) = uVar3;
  }
  else if (uVar3 != 0) {
    *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + uVar3;
    *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + *(int *)(param_2 + 0x24);
  }
  puVar1 = (uint *)(param_1 + 0x14);
  *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & *(uint *)(param_2 + 8);
  lVar6 = 4;
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & *(uint *)(param_2 + 0xc);
  puVar4 = puVar1;
  do {
    *puVar4 = *puVar4 & *(uint *)((param_2 - param_1) + (longlong)puVar4);
    puVar4 = puVar4 + 1;
    lVar6 = lVar6 + -1;
  } while (lVar6 != 0);
  uVar3 = *(uint *)(param_1 + 0x30);
  if (*(uint *)(param_1 + 0x30) <= *(uint *)(param_2 + 0x30)) {
    uVar3 = *(uint *)(param_2 + 0x30);
  }
  *(uint *)(param_1 + 0x30) = uVar3;
  uVar2 = *(uint *)(param_1 + 0x34);
  if (*(uint *)(param_2 + 0x34) <= *(uint *)(param_1 + 0x34)) {
    uVar2 = *(uint *)(param_2 + 0x34);
  }
  *(uint *)(param_1 + 0x34) = uVar2;
  uVar5 = *puVar1 | 0x80;
  if (param_3 == '\0') {
    uVar5 = *puVar1 | 0x40;
  }
  *puVar1 = uVar5;
  if (uVar2 < uVar3) {
    *(undefined4 *)(param_1 + 0x34) = 0;
    *(undefined4 *)(param_1 + 0x30) = 0;
    *puVar1 = uVar5 & 0xfffffffb;
  }
  return;
}



===== vmqVerifyMethodOidParamsAndCallHandler @ 1c0012dec =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void vmqVerifyMethodOidParamsAndCallHandler
               (longlong param_1,longlong param_2,int *param_3,ushort param_4,byte param_5,
               undefined *param_6)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  
  lVar1 = *(longlong *)(param_2 + 0x28);
  if (((lVar1 == 0) || (*(uint *)(param_2 + 0x30) < (uint)param_4)) ||
     (*(uint *)(param_2 + 0x34) < (uint)param_4)) {
    iVar2 = -0x3ffeffea;
    *(uint *)(param_2 + 0x44) = (uint)param_4;
    *(undefined4 *)(param_2 + 0x40) = 0;
  }
  else {
    if ((param_5 <= *(byte *)(lVar1 + 1)) && (param_4 <= *(ushort *)(lVar1 + 2))) {
      *(uint *)(param_2 + 0x40) = (uint)param_4;
      ExAcquireFastMutex(param_1 + 0x370);
      iVar2 = (*(code *)param_6)(param_1,lVar1);
      *param_3 = iVar2;
      ExReleaseFastMutex(param_1 + 0x370);
      iVar2 = *param_3;
      goto LAB_1c0012e9d;
    }
    *(undefined4 *)(param_2 + 0x40) = 4;
    iVar2 = -0x3fffff45;
  }
  *param_3 = iVar2;
LAB_1c0012e9d:
  uVar3 = (uint)param_4;
  if (iVar2 != 0) {
    uVar3 = 0;
  }
  *(uint *)(param_2 + 0x3c) = uVar3;
  return;
}



===== vmqVerifyQueryOidParamsAndCallHandler @ 1c0012ecc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void vmqVerifyQueryOidParamsAndCallHandler
               (undefined8 param_1,longlong param_2,int *param_3,ushort param_4,undefined1 param_5,
               undefined *param_6)

{
  undefined1 *puVar1;
  int iVar2;
  uint uVar3;
  
  puVar1 = *(undefined1 **)(param_2 + 0x28);
  uVar3 = 0;
  if ((puVar1 == (undefined1 *)0x0) || (*(uint *)(param_2 + 0x30) < (uint)param_4)) {
    *(uint *)(param_2 + 0x38) = (uint)param_4;
    *param_3 = -0x3ffeffea;
  }
  else {
    puVar1[1] = param_5;
    *puVar1 = 0x80;
    *(ushort *)(puVar1 + 2) = param_4;
    iVar2 = (*(code *)param_6)(param_1,puVar1);
    *param_3 = iVar2;
    if (iVar2 == 0) {
      uVar3 = (uint)*(ushort *)(puVar1 + 2);
    }
  }
  *(uint *)(param_2 + 0x34) = uVar3;
  return;
}



===== vmqVerifySetOidParamsAndCallHandler @ 1c0012f50 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void vmqVerifySetOidParamsAndCallHandler
               (longlong param_1,longlong param_2,undefined4 *param_3,ushort param_4,byte param_5,
               undefined *param_6)

{
  longlong lVar1;
  undefined4 uVar2;
  
  lVar1 = *(longlong *)(param_2 + 0x28);
  if ((lVar1 == 0) || (*(uint *)(param_2 + 0x30) < (uint)param_4)) {
    *(undefined4 *)(param_2 + 0x34) = 0;
    *(uint *)(param_2 + 0x38) = (uint)param_4;
    *param_3 = 0xc0010016;
  }
  else if ((*(byte *)(lVar1 + 1) < param_5) || (*(ushort *)(lVar1 + 2) < param_4)) {
    *(undefined4 *)(param_2 + 0x34) = 4;
    *param_3 = 0xc00000bb;
  }
  else {
    ExAcquireFastMutex(param_1 + 0x370);
    uVar2 = (*(code *)param_6)(param_1,lVar1);
    *param_3 = uVar2;
    ExReleaseFastMutex(param_1 + 0x370);
  }
  return;
}



===== Microsoft_Windows_Networking_Correlation_EtwEnableCallback @ 1c0013000 =====

void Microsoft_Windows_Networking_Correlation_EtwEnableCallback
               (undefined8 param_1,undefined4 param_2,undefined8 param_3,ulonglong param_4)

{
  LOCK();
  Microsoft_Windows_Networking_CorrelationEnabled = param_2;
  UNLOCK();
  LOCK();
  Microsoft_Windows_Networking_CorrelationTraceActivityPayload = (uint)(param_4 >> 3) & 1;
  UNLOCK();
  return;
}



===== _guard_check_icall @ 1c0013030 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 1c0013048 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c001306c =====

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



===== __cpu_features_init @ 1c00130e0 =====

/* WARNING: Removing unreachable block (ram,0x0001c001314a) */
/* WARNING: Removing unreachable block (ram,0x0001c00130f9) */
/* WARNING: Removing unreachable block (ram,0x0001c00130ea) */

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



===== __security_check_cookie @ 1c00131b0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c00131f0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c0013220 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c0013220. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c0013250 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcpy @ 1c00132c0 =====

void * __cdecl memcpy(void *_Dst,void *_Src,size_t _Size)

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



===== memset @ 1c00135c0 =====

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



===== __memset_repmovs @ 1c0013700 =====

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



===== __memset_query @ 1c0013780 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c0013800 =====

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



===== __memset_spec_ermsb_repmovsb @ 1c0013940 =====

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



===== __memset_spec_plain @ 1c00139c0 =====

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



===== lbfoAddNicToFC @ 1c001b008 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int lbfoAddNicToFC(longlong param_1,longlong param_2)

{
  bool bVar1;
  longlong *plVar2;
  int iVar3;
  char *pcVar4;
  ulonglong uVar5;
  undefined2 uVar6;
  longlong lVar7;
  undefined *puVar8;
  longlong lVar9;
  undefined1 auStackY_188 [32];
  longlong local_140;
  uint local_138 [2];
  longlong *local_130;
  longlong local_128;
  undefined1 local_118 [4];
  undefined4 local_114;
  longlong local_64 [3];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_188;
  lVar7 = *(longlong *)(param_1 + 0x10);
  bVar1 = false;
  local_114 = 0;
  local_128 = lVar7;
  memset(local_118,0,0xc4);
  lVar9 = 0;
  local_140 = 0;
  local_138[0] = 0;
  if (*(char *)((ulonglong)(*(int *)(param_2 + 4) - 1) + 0x4a + param_1) != '\0') {
    return 0;
  }
  puVar8 = (undefined *)0x0;
  iVar3 = lbfoIssueOidRequestOnFilter
                    (*(undefined8 *)(param_1 + 0x18),0xfa010101,0,*(int *)(param_2 + 4),local_118,
                     200,(undefined4 *)0x0);
  if (iVar3 != 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      puVar8 = &WPP_fcac40b5fded30eddc607eed6843ce7c_Traceguids;
      WPP_SF_ds(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
                &WPP_fcac40b5fded30eddc607eed6843ce7c_Traceguids,iVar3,
                "lbfoIssueOidRequestOnFilter(FilterContext->FilterModuleHandle, OID_IMPLAT_ADAPTER_INFORMATION, NdisRequestQueryInformation, PortChars->PortNumber, &NicInfo, sizeof(NicInfo), NULL)"
               );
    }
    goto LAB_1c001b336;
  }
  local_130 = (longlong *)lbfoFindNicByGuid(lVar7,local_64);
  if (local_130 == (longlong *)0x0) {
    iVar3 = lbfoIssueOidRequestOnFilterEx
                      (*(undefined8 *)(param_1 + 0x18),0xfa010102,puVar8,
                       *(undefined4 *)(param_2 + 4),&local_140,local_138);
    lVar9 = local_140;
    if (iVar3 == 0) {
      puVar8 = local_118;
      iVar3 = lbfoCreateNicObject(lVar7,param_2,(longlong)puVar8,local_140,(longlong *)&local_130);
      if (iVar3 == 0) {
        bVar1 = true;
        goto LAB_1c001b1ec;
      }
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1c001b319;
      uVar6 = 0x18;
      pcVar4 = "lbfoCreateNicObject(Team, PortChars, &NicInfo, NicRssInfo, &Nic)";
      goto LAB_1c001b301;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      puVar8 = &WPP_fcac40b5fded30eddc607eed6843ce7c_Traceguids;
      WPP_SF_ds(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
                &WPP_fcac40b5fded30eddc607eed6843ce7c_Traceguids,iVar3,
                "lbfoIssueOidRequestOnFilterEx(FilterContext->FilterModuleHandle, OID_IMPLAT_RSS_PROCESSOR_INFO, NdisRequestQueryInformation, PortChars->PortNumber, (VOID **) &NicRssInfo, &BufLen)"
               );
    }
    lVar9 = local_140;
  }
  else {
LAB_1c001b1ec:
    plVar2 = local_130;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_qqdq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,puVar8,lVar7,(char)local_130,
                  (char)local_130[0x51],(char)param_1);
    }
    *(short *)((longlong)plVar2 + 0xac) = *(short *)((longlong)plVar2 + 0xac) + 1;
    *(char *)((ulonglong)(*(int *)(param_2 + 4) - 1) + 0x4a + param_1) = (char)plVar2[0x51];
    *(undefined1 *)((ulonglong)*(byte *)(plVar2 + 0x51) + 0x89 + param_1) =
         *(undefined1 *)(param_2 + 4);
    if ((*(byte *)(param_1 + 0xcc) & 2) != 0) {
      vmqInitMNicState(plVar2 + 0x19,*(undefined8 *)(param_1 + 0x18));
      puVar8 = (undefined *)(ulonglong)*(uint *)(param_2 + 4);
      vmqAllocateAllQueuesOnMNic
                (*(longlong *)(param_1 + 0x10) + 0x240,plVar2 + 0x19,*(uint *)(param_2 + 4));
      lVar7 = local_128;
    }
    if (bVar1) {
      uVar5 = lbfoAddNic(lVar7,plVar2);
      iVar3 = (int)uVar5;
      if (iVar3 == 0) {
        iVar3 = lbfoUpdateInitialNicState(param_1,(longlong)plVar2);
        if (((iVar3 != 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar6 = 0x1b;
          pcVar4 = "lbfoUpdateInitialNicState(FilterContext, Nic)";
          goto LAB_1c001b301;
        }
      }
      else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar6 = 0x1a;
        pcVar4 = "lbfoAddNic(Team, Nic)";
LAB_1c001b301:
        puVar8 = &WPP_fcac40b5fded30eddc607eed6843ce7c_Traceguids;
        WPP_SF_ds(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,
                  &WPP_fcac40b5fded30eddc607eed6843ce7c_Traceguids,iVar3,pcVar4);
      }
    }
  }
LAB_1c001b319:
  if (lVar9 != 0) {
    ExFreePoolWithTag(lVar9,0x5463694e);
  }
  if (iVar3 == 0) {
    return 0;
  }
LAB_1c001b336:
  lbfoRemoveNicFromFC(param_1,*(int *)(param_2 + 4),puVar8);
  return iVar3;
}



===== lbfoAddNicsToFC @ 1c001b374 =====

int lbfoAddNicsToFC(longlong param_1,undefined8 *param_2)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  int iVar4;
  
  lVar2 = *(longlong *)(param_1 + 0x10);
  iVar4 = 0;
  lVar1 = lVar2 + 0x5b0;
  ExAcquireFastMutex(lVar1);
  if ((*(int *)(lVar2 + 0x20) == 2) && ((*(byte *)(param_1 + 0xcc) & 4) == 0)) {
    for (; param_2 != (undefined8 *)0x0; param_2 = (undefined8 *)*param_2) {
      if ((((*(int *)((longlong)param_2 + 0x24) - 1U < 0x40) &&
           (iVar3 = lbfoAddNicToFC(param_1,(longlong)(param_2 + 4)), iVar3 != 0)) &&
          (iVar4 = iVar3, (undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_dq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
                  &WPP_fcac40b5fded30eddc607eed6843ce7c_Traceguids,
                  *(undefined4 *)((longlong)param_2 + 0x24),(char)param_1);
      }
    }
  }
  ExReleaseFastMutex(lVar1);
  return iVar4;
}



===== lbfoCheckNics @ 1c001b450 =====

int lbfoCheckNics(longlong param_1,undefined8 param_2,undefined *param_3)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  char *pcVar4;
  undefined2 uVar5;
  longlong lVar6;
  ushort uVar7;
  uint local_res8 [2];
  longlong local_res10;
  
  lVar1 = *(longlong *)(param_1 + 0x10);
  local_res10 = 0;
  local_res8[0] = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_3 = &WPP_fcac40b5fded30eddc607eed6843ce7c_Traceguids;
    WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
              &WPP_fcac40b5fded30eddc607eed6843ce7c_Traceguids,lVar1,(char)param_1);
  }
  lVar1 = lVar1 + 0x5b0;
  ExAcquireFastMutex(lVar1);
  iVar3 = lbfoIssueOidRequestOnFilterEx
                    (*(undefined8 *)(param_1 + 0x18),0x1020d,param_3,0,&local_res10,local_res8);
  lVar2 = local_res10;
  if (iVar3 == 0) {
    uVar7 = 0;
    lVar6 = (ulonglong)*(uint *)(local_res10 + 8) + local_res10;
    if (*(int *)(local_res10 + 4) != 0) {
      do {
        if ((*(int *)(lVar6 + 4) - 1U < 0x40) && (iVar3 = lbfoAddNicToFC(param_1,lVar6), iVar3 != 0)
           ) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar5 = 0xc;
            pcVar4 = "lbfoAddNicToFC(FilterContext, PortChars)";
            goto LAB_1c001b581;
          }
          break;
        }
        uVar7 = uVar7 + 1;
        lVar6 = lVar6 + (ulonglong)*(uint *)(lVar2 + 0xc);
      } while ((uint)uVar7 < *(uint *)(lVar2 + 4));
    }
  }
  else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    uVar5 = 0xb;
    pcVar4 = 
    "lbfoIssueOidRequestOnFilterEx(FilterContext->FilterModuleHandle, OID_GEN_ENUMERATE_PORTS, NdisRequestQueryInformation, 0, (VOID **) &PortArray, &AllocSize)"
    ;
LAB_1c001b581:
    WPP_SF_ds(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,
              &WPP_fcac40b5fded30eddc607eed6843ce7c_Traceguids,iVar3,pcVar4);
  }
  ExReleaseFastMutex(lVar1);
  if (lVar2 != 0) {
    ExFreePoolWithTag(lVar2,0x5463694e);
  }
  return iVar3;
}



===== lbfoCreateNicObject @ 1c001b5e4 =====

int lbfoCreateNicObject(longlong param_1,longlong param_2,longlong param_3,longlong param_4,
                       longlong *param_5)

{
  undefined4 *puVar1;
  longlong lVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  longlong lVar7;
  byte bVar8;
  undefined8 *puVar9;
  undefined8 uVar10;
  undefined4 local_58;
  undefined2 local_54;
  undefined8 local_48;
  longlong lStack_40;
  undefined8 local_38;
  undefined4 local_30;
  undefined4 local_2c;
  
  local_2c = 0;
  local_38 = 1;
  local_30 = 0x10;
  local_48 = 0;
  lStack_40 = 0;
  lVar7 = ExAllocatePool3(0x40,0x350,0x5463694e,&local_38,1);
  if (lVar7 == 0) {
    iVar5 = -0x3fffff66;
    puVar9 = (undefined8 *)WPP_GLOBAL_Control;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      puVar9 = *(undefined8 **)(WPP_GLOBAL_Control + 0x18);
      WPP_SF_s(puVar9,0x1d,&WPP_fcac40b5fded30eddc607eed6843ce7c_Traceguids,"Nic");
    }
  }
  else {
    iVar5 = lbfoAllocateTimer(DAT_1c0018468,lbfoSoftFailTimer);
    if (iVar5 == 0) {
      *(longlong *)(lVar7 + 0x298) = param_1;
      bVar8 = 1;
      *(undefined4 *)(lVar7 + 0x2a0) = 6;
      *(undefined4 *)(lVar7 + 0xa0) = 0;
      do {
        if (*(longlong *)(param_1 + 0x658 + (ulonglong)bVar8 * 8) == 0) break;
        bVar8 = bVar8 + 1;
      } while (bVar8 < 0x41);
      *(byte *)(lVar7 + 0x288) = bVar8;
      *(undefined2 *)(lVar7 + 0xae) = 1;
      uVar10 = 0;
      *(undefined8 *)(lVar7 + 0x2c8) = *(undefined8 *)(param_2 + 0x18);
      *(undefined8 *)(lVar7 + 0x2d0) = *(undefined8 *)(param_2 + 0x20);
      *(undefined4 *)(lVar7 + 0x2d8) = 0xffffffff;
      *(undefined4 *)(lVar7 + 0x2dc) = 0xffffffff;
      *(longlong *)(lVar7 + 0x48) = lVar7 + 0x50;
      lVar2 = lVar7 + 0x2a8;
      *(longlong *)(lVar7 + 0x2b0) = lVar2;
      *(longlong *)lVar2 = lVar2;
      *(undefined4 *)(lVar7 + 0x2c0) = 0;
      *(undefined2 *)(lVar7 + 0x42) = 0x4e;
      KeInitializeEvent(lVar7 + 0xb0);
      *(undefined2 *)(lVar7 + 0xa4) = *(undefined2 *)(param_4 + 0x10);
      puVar1 = (undefined4 *)(lVar7 + 0x30);
      *(undefined4 *)(lVar7 + 0xa6) = *(undefined4 *)(param_4 + 8);
      *(undefined4 *)(lVar7 + 0x28) = *(undefined4 *)(param_3 + 0x48);
      *(undefined2 *)(lVar7 + 0x2c) = *(undefined2 *)(param_3 + 0x4c);
      uVar6 = *(undefined4 *)(param_3 + 0xb8);
      uVar3 = *(undefined4 *)(param_3 + 0xbc);
      uVar4 = *(undefined4 *)(param_3 + 0xc0);
      *puVar1 = *(undefined4 *)(param_3 + 0xb4);
      *(undefined4 *)(lVar7 + 0x34) = uVar6;
      *(undefined4 *)(lVar7 + 0x38) = uVar3;
      *(undefined4 *)(lVar7 + 0x3c) = uVar4;
      uVar6 = RtlStringFromGUID(puVar1,&local_48);
      iVar5 = NdisConvertNtStatusToNdisStatus(uVar6);
      if (iVar5 == 0) {
        RtlCopyUnicodeString(lVar7 + 0x40,&local_48);
        puVar9 = (undefined8 *)WPP_GLOBAL_Control;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          local_58 = *(undefined4 *)(lVar7 + 0x28);
          puVar9 = *(undefined8 **)(WPP_GLOBAL_Control + 0x18);
          local_54 = *(undefined2 *)(lVar7 + 0x2c);
          WPP_SF_qqd_guid__MAC_
                    (puVar9,&local_58,uVar10,param_1,lVar7,*(undefined1 *)(lVar7 + 0x288),puVar1,
                     &local_58);
        }
      }
      else {
        puVar9 = (undefined8 *)WPP_GLOBAL_Control;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          puVar9 = *(undefined8 **)(WPP_GLOBAL_Control + 0x18);
          WPP_SF_ds(puVar9,0x1f,&WPP_fcac40b5fded30eddc607eed6843ce7c_Traceguids,iVar5,
                    "RtlStringFromGUID(&Nic->Guid, &GuidStr)");
        }
      }
    }
    else {
      puVar9 = (undefined8 *)WPP_GLOBAL_Control;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        puVar9 = *(undefined8 **)(WPP_GLOBAL_Control + 0x18);
        WPP_SF_ds(puVar9,0x1e,&WPP_fcac40b5fded30eddc607eed6843ce7c_Traceguids,iVar5,
                  "lbfoAllocateTimer(Global.FilterDriverHandle, lbfoSoftFailTimer, &Nic->SoftFailTimer)"
                 );
      }
    }
  }
  if (lStack_40 != 0) {
    puVar9 = &local_48;
    RtlFreeUnicodeString();
  }
  if (iVar5 == 0) {
    if ((lVar7 != 0) && ((Microsoft_Windows_MsLbfoEventProviderEnableBits & 1) != 0)) {
      McTemplateK0jd_EtwWriteTransfer(puVar9,&MemberCreatedInfo,0,lVar7 + 0x30,0);
    }
  }
  else if (lVar7 != 0) {
    lbfoDestroyNicObject(param_1,lVar7);
    lVar7 = 0;
  }
  *param_5 = lVar7;
  return iVar5;
}



===== lbfoDestroyNicObject @ 1c001b938 =====

void lbfoDestroyNicObject(undefined8 param_1,longlong param_2)

{
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,
               &WPP_fcac40b5fded30eddc607eed6843ce7c_Traceguids,param_1,(char)param_2,
               *(undefined1 *)(param_2 + 0x288));
  }
  if (*(longlong *)(param_2 + 0x290) != 0) {
    NdisFreeTimerObject();
  }
  ExFreePoolWithTag(param_2,0x5463694e);
  return;
}



===== lbfoRemoveNicFromFC @ 1c001b9bc =====

void lbfoRemoveNicFromFC(longlong param_1,int param_2,undefined8 param_3)

{
  short *psVar1;
  byte bVar2;
  longlong *plVar3;
  longlong *plVar4;
  
  plVar3 = *(longlong **)(param_1 + 0x10);
  bVar2 = *(byte *)((ulonglong)(param_2 - 1U) + 0x4a + param_1);
  if ((bVar2 != 0) &&
     (plVar4 = (longlong *)plVar3[(ulonglong)bVar2 + 0xcb], plVar4 != (longlong *)0x0)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_qqdq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,param_3,plVar3,(char)plVar4,
                  (char)plVar4[0x51],(char)param_1);
    }
    if ((*(byte *)(param_1 + 0xcc) & 2) != 0) {
      vmqFreeAllQueuesOnMNic((longlong)(plVar3 + 0x48),plVar4 + 0x19,param_2);
      vmqCleanupMNicState((longlong)(plVar4 + 0x19));
    }
    *(undefined1 *)((ulonglong)(param_2 - 1U) + 0x4a + param_1) = 0;
    *(undefined1 *)((ulonglong)*(byte *)(plVar4 + 0x51) + 0x89 + param_1) = 0;
    psVar1 = (short *)((longlong)plVar4 + 0xac);
    *psVar1 = *psVar1 + -1;
    if (*psVar1 == 0) {
      if (((int)plVar4[0x14] == 1) || ((int)plVar4[0x14] == 2)) {
        lbfoRemoveNic(plVar3,plVar4);
      }
      lbfoDestroyNicObject(plVar3,(longlong)plVar4);
    }
  }
  return;
}



===== LbfoNetPnPEvent @ 1c001bae0 =====

undefined4 LbfoNetPnPEvent(longlong param_1,longlong param_2,undefined *param_3)

{
  int iVar1;
  longlong lVar2;
  undefined4 uVar3;
  longlong lVar4;
  ushort uVar5;
  ulonglong uVar6;
  uint uVar7;
  
  uVar6 = 0;
  lVar4 = param_2;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_LD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),param_2,param_3,
              *(undefined4 *)(param_2 + 8),(char)*(undefined4 *)(param_1 + 0x118));
  }
  iVar1 = *(int *)(param_2 + 8);
  if (iVar1 == 10) {
    lbfoAddNicsToFC(param_1,*(undefined8 **)(param_2 + 0x10));
  }
  else {
    if (iVar1 == 0xb) {
      uVar3 = NdisFNetPnPEvent(*(undefined8 *)(param_1 + 0x18),param_2);
      lVar4 = *(longlong *)(param_2 + 0x10);
      lVar2 = *(longlong *)(param_1 + 0x10);
      uVar7 = *(uint *)(param_2 + 0x18) >> 2;
      ExAcquireFastMutex(lVar2 + 0x5b0);
      if (uVar7 != 0) {
        do {
          iVar1 = *(int *)(lVar4 + uVar6 * 4);
          if (iVar1 - 1U < 0x40) {
            lbfoRemoveNicFromFC(param_1,iVar1,param_3);
          }
          uVar5 = (short)uVar6 + 1;
          uVar6 = (ulonglong)uVar5;
        } while (uVar5 < uVar7);
      }
      ExReleaseFastMutex(lVar2 + 0x5b0);
      return uVar3;
    }
    if (iVar1 == 0xf) {
      lbfoFilterPreDetach(param_1,lVar4,param_3);
      return 0;
    }
  }
  uVar3 = NdisFNetPnPEvent(*(undefined8 *)(param_1 + 0x18),param_2);
  return uVar3;
}



===== LbfoDriverUnload @ 1c001bc10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void LbfoDriverUnload(void)

{
  undefined8 uVar1;
  undefined *puVar2;
  
  puVar2 = WPP_GLOBAL_Control;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    puVar2 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
    WPP_SF_(puVar2,0x25,&WPP_b7202525798e3186f26c2d40dc3ccbc1_Traceguids);
  }
  if ((Microsoft_Windows_MsLbfoEventProviderEnableBits & 1) != 0) {
    McTemplateK0_EtwWriteTransfer(puVar2);
  }
  if (DAT_1c0018468 != 0) {
    NdisFDeregisterFilterDriver();
  }
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    puVar2 = WPP_GLOBAL_Control;
    if (WPPTraceSuite == 4) {
      for (; puVar2 != (undefined *)0x0; puVar2 = *(undefined **)(puVar2 + 0x10)) {
        if (*(longlong *)(puVar2 + 0x38) != 0) {
          (*pfnEtwUnregister)();
          *(undefined8 *)(puVar2 + 0x38) = 0;
        }
      }
    }
    else if (WPPTraceSuite == 2) {
      IoWMIRegistrationControl(WPP_GLOBAL_Control,0x80000002);
    }
    WPP_GLOBAL_Control = (undefined *)&WPP_GLOBAL_Control;
  }
  uVar1 = DAT_1c0018310;
  DAT_1c0018310 = 0;
  DAT_1c00182f0 = 0;
  EtwUnregister(uVar1);
  if ((DAT_1c001849c & 4) != 0) {
    EtwUnregister(Microsoft_Windows_Networking_CorrelationHandle);
    Microsoft_Windows_Networking_CorrelationHandle = 0;
  }
  if ((DAT_1c001849c & 1) != 0) {
    McGenEventUnregister_EtwUnregister((longlong *)&MsLbfoSystemEventProvider_Context);
  }
  if ((DAT_1c001849c & 2) != 0) {
    McGenEventUnregister_EtwUnregister(&MsLbfoEventProvider_Context);
  }
  return;
}



===== LbfoSetOptions @ 1c001bd60 =====

int LbfoSetOptions(undefined8 param_1)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  undefined8 uVar5;
  longlong local_res8;
  undefined8 local_28;
  undefined8 local_20;
  undefined4 local_18;
  undefined4 local_14;
  
  local_res8 = 0;
  local_18 = 0;
  local_14 = 0;
  local_28 = 0x1401a9;
  local_20 = param_1;
  iVar3 = NdisOpenConfigurationEx(&local_28,&local_res8);
  if (iVar3 == 0) {
    uVar4 = lbfoReadConfigValue(local_res8,L"NicActivationDelay",0,600,0x1e);
    DAT_1c0018474 = (ushort)uVar4;
    uVar4 = lbfoReadConfigValue(local_res8,L"CfgMacRebalanceDelay",0,600,0x1e);
    DAT_1c0018476 = (undefined2)uVar4;
    uVar4 = lbfoReadConfigValue(local_res8,L"ForceMinModeVmq",0,1,0);
    DAT_1c001849c = ((byte)uVar4 & 1) << 4 | DAT_1c001849c & 0xef;
    uVar5 = 0;
    uVar4 = lbfoReadConfigValue(local_res8,L"UseHighResTimestampOnDatapath",0,1,0);
    bVar2 = ((byte)uVar4 & 1) << 5 | DAT_1c001849c & 0xdf;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      uVar4 = bVar2 >> 5 & 1;
      bVar1 = DAT_1c001849c & 0x10;
      DAT_1c001849c = bVar2;
      WPP_SF_ddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(ulonglong)uVar4,uVar5,
                 (uint)DAT_1c0018474,bVar1 >> 4,(char)uVar4);
      bVar2 = DAT_1c001849c;
    }
  }
  else {
    bVar2 = DAT_1c001849c;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_ds(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                &WPP_b7202525798e3186f26c2d40dc3ccbc1_Traceguids,iVar3,
                "lbfoGetConfigHandle(NdisDriverHandle, &ConfigHandle)");
      bVar2 = DAT_1c001849c;
    }
  }
  DAT_1c001849c = bVar2;
  if (local_res8 != 0) {
    NdisCloseConfiguration();
  }
  return iVar3;
}



===== WppInitKm @ 1c001bf10 =====

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



===== WppLoadTracingSupport @ 1c001bfa0 =====

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



===== WppTraceCallback @ 1c001c0f0 =====

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
        memcpy((ushort *)((ulonglong)uVar11 + (longlong)param_4) + 1,*(void **)(puVar3 + 4),
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



===== _tlgEnableCallback @ 1c001c380 =====

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



===== lbfoInitTeam @ 1c001c3fc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

char * lbfoInitTeam(longlong param_1,char *param_2,undefined8 param_3,char *param_4)

{
  bool bVar1;
  char cVar2;
  uint uVar3;
  longlong lVar4;
  char *pcVar5;
  undefined2 uVar6;
  char *pcVar7;
  undefined1 auStackY_138 [32];
  longlong local_108;
  undefined4 local_100;
  int local_fc;
  undefined4 local_f8 [2];
  undefined8 local_f0;
  undefined8 local_e8;
  undefined8 local_e0;
  char *local_d8;
  char *local_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8 [4];
  char *local_98;
  undefined8 local_90;
  undefined4 *local_88;
  undefined8 local_80;
  int *local_78;
  undefined8 local_70;
  undefined8 *local_68;
  undefined8 local_60;
  undefined4 *local_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_138;
  local_d0 = param_2 + 0x628;
  local_d8 = param_2 + 0x600;
  local_108 = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_4 = param_2;
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
             &WPP_b7202525798e3186f26c2d40dc3ccbc1_Traceguids,param_2);
  }
  local_c8 = 0;
  uStack_c0 = 0;
  lVar4 = NdisAllocateRWLock(DAT_1c0018468);
  *(longlong *)(param_2 + 0x5e8) = lVar4;
  bVar1 = true;
  if (lVar4 == 0) {
    pcVar7 = (char *)0xc000009a;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1c001c8a7;
    uVar6 = 0x18;
    param_4 = "Team->Lock";
  }
  else {
    lVar4 = NdisAllocateRWLock(DAT_1c0018468);
    *(longlong *)(param_2 + 0x5f0) = lVar4;
    if (lVar4 != 0) {
      cVar2 = RtlCreateHashTable(&local_d8,0);
      if (cVar2 != '\0') {
        cVar2 = RtlCreateHashTable(&local_d0,0);
        if (cVar2 != '\0') {
          if ((DAT_1c001849c & 8) == 0) {
LAB_1c001c5ce:
            pcVar7 = param_2 + 0x8d8;
            *(char **)(param_2 + 0x8e0) = pcVar7;
            *(char **)pcVar7 = pcVar7;
            pcVar7 = param_2 + 0x8c8;
            *(char **)(param_2 + 0x8d0) = pcVar7;
            *(char **)pcVar7 = pcVar7;
            pcVar7 = param_2 + 0x8f0;
            *(char **)(param_2 + 0x8f8) = pcVar7;
            *(char **)pcVar7 = pcVar7;
            KeInitializeEvent(param_2 + 0x908,0);
            param_2[0x5b0] = '\x01';
            param_2[0x5b1] = '\0';
            param_2[0x5b2] = '\0';
            param_2[0x5b3] = '\0';
            param_2[0x5b8] = '\0';
            param_2[0x5b9] = '\0';
            param_2[0x5ba] = '\0';
            param_2[0x5bb] = '\0';
            param_2[0x5bc] = '\0';
            param_2[0x5bd] = '\0';
            param_2[0x5be] = '\0';
            param_2[0x5bf] = '\0';
            param_2[0x5c0] = '\0';
            param_2[0x5c1] = '\0';
            param_2[0x5c2] = '\0';
            param_2[0x5c3] = '\0';
            KeInitializeEvent(param_2 + 0x5c8,1);
            local_e8 = *(undefined8 *)(param_1 + 0x18);
            local_f0 = 0x1401a9;
            local_e0 = 0;
            uVar3 = NdisOpenConfigurationEx(&local_f0,&local_108);
            pcVar7 = (char *)(ulonglong)uVar3;
            if (uVar3 == 0) {
              param_2[0x5fc] = (DAT_1c001849c >> 5 ^ param_2[0x5fc]) & 1 ^ param_2[0x5fc];
              param_4 = (char *)0x5;
              uVar3 = lbfoReadConfigValue(local_108,L"LBAlgo",0,5,5);
              *(uint *)(param_2 + 0x5a0) = uVar3;
              if ((DAT_1c001849c & 8) == 0) {
                param_4 = (char *)0x2;
                uVar3 = lbfoReadConfigValue(local_108,L"TeamingMode",0,2,1);
              }
              else {
                if (3 < (int)uVar3) {
                  param_2[0x5a0] = '\0';
                  param_2[0x5a1] = '\0';
                  param_2[0x5a2] = '\0';
                  param_2[0x5a3] = '\0';
                }
                uVar3 = 1;
              }
              *(uint *)(param_2 + 0x5a8) = uVar3;
              param_2[0x920] = '\x01';
              param_2[0x921] = '\0';
              *(undefined4 *)(param_2 + 0x5a4) =
                   *(undefined4 *)(&LbAlgoConfigToLbAlgo + (longlong)*(int *)(param_2 + 0x5a0) * 4);
              if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
                if (3 < (byte)WPP_GLOBAL_Control[0x29]) {
                  param_4 = param_2;
                  WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
                            &WPP_b7202525798e3186f26c2d40dc3ccbc1_Traceguids,param_2,
                            (char)*(int *)(param_2 + 0x5a0));
                }
                if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   (3 < (byte)WPP_GLOBAL_Control[0x29])) {
                  param_4 = param_2;
                  WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
                            &WPP_b7202525798e3186f26c2d40dc3ccbc1_Traceguids,param_2,
                            (char)*(undefined4 *)(param_2 + 0x5a8));
                }
              }
              if ((*(longlong *)(&DAT_1c0018148 + (longlong)*(int *)(param_2 + 0x5a4) * 0x78) != 0)
                 && (DAT_1c0018476 != 0)) {
                uVar3 = lbfoAllocateTimer(DAT_1c0018468,lbfoCfgMacRebalanceTimer);
                pcVar7 = (char *)(ulonglong)uVar3;
                if (uVar3 != 0) {
                  if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                     ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1c001c8a7;
                  uVar6 = 0x1e;
                  pcVar5 = 
                  "lbfoAllocateTimer(Global.FilterDriverHandle, lbfoCfgMacRebalanceTimer, &Team->CfgMacRebalanceTimer)"
                  ;
                  goto LAB_1c001c5b5;
                }
              }
              if (*(code **)(&TeamingModeOperations + (longlong)*(int *)(param_2 + 0x5a8) * 0x48) !=
                  (code *)0x0) {
                uVar3 = (**(code **)(&TeamingModeOperations +
                                    (longlong)*(int *)(param_2 + 0x5a8) * 0x48))(param_2,local_108);
                pcVar7 = (char *)(ulonglong)uVar3;
                if (uVar3 != 0) {
                  if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                     ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1c001c8a7;
                  uVar6 = 0x1f;
                  pcVar5 = 
                  "CALL_IF_PRESENT(TeamingModeOperations[Team->TeamingMode].Init, NDIS_STATUS_SUCCESS, Team, ConfigHandle)"
                  ;
                  goto LAB_1c001c5b5;
                }
              }
              if ((code *)(&LBAlgoOperations)[(longlong)*(int *)(param_2 + 0x5a4) * 0xf] ==
                  (code *)0x0) {
                pcVar7 = (char *)0x0;
                goto LAB_1c001c8a7;
              }
              uVar3 = (*(code *)(&LBAlgoOperations)[(longlong)*(int *)(param_2 + 0x5a4) * 0xf])
                                (param_2,local_108);
              pcVar7 = (char *)(ulonglong)uVar3;
              if (((uVar3 == 0) || ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control)) ||
                 ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1c001c8a7;
              uVar6 = 0x20;
              pcVar5 = 
              "CALL_IF_PRESENT(LBAlgoOperations[Team->LBAlgo].Init, NDIS_STATUS_SUCCESS, Team, ConfigHandle)"
              ;
            }
            else {
              if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                 ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1c001c8a7;
              uVar6 = 0x1b;
              pcVar5 = "lbfoGetConfigHandle(FilterContext->FilterModuleHandle,&ConfigHandle)";
            }
          }
          else {
            uVar3 = lbfoAllocateTimer(DAT_1c0018468,lbfoIndicateTeamLinkStateTimer);
            pcVar7 = (char *)(ulonglong)uVar3;
            if (uVar3 == 0) goto LAB_1c001c5ce;
            if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
               ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1c001c8a7;
            uVar6 = 0x1a;
            pcVar5 = 
            "lbfoAllocateTimer(Global.FilterDriverHandle, lbfoIndicateTeamLinkStateTimer, &Team->LinkStateIndicationTimer)"
            ;
          }
LAB_1c001c5b5:
          param_4 = pcVar7;
          WPP_SF_ds(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,
                    &WPP_b7202525798e3186f26c2d40dc3ccbc1_Traceguids,(int)pcVar7,pcVar5);
          goto LAB_1c001c8a7;
        }
      }
      pcVar7 = (char *)0xc000009a;
      goto LAB_1c001c8a7;
    }
    pcVar7 = (char *)0xc000009a;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1c001c8a7;
    uVar6 = 0x19;
    param_4 = "Team->NicRemovalLock";
  }
  pcVar7 = (char *)0xc000009a;
  WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,
           &WPP_b7202525798e3186f26c2d40dc3ccbc1_Traceguids,param_4);
LAB_1c001c8a7:
  lVar4 = local_108;
  if (local_108 != 0) {
    NdisCloseConfiguration();
  }
  local_fc = *(int *)(param_2 + 0x5a8);
  if (local_fc == 1) {
    local_c8 = *(undefined8 *)(param_2 + 0x928);
    uStack_c0 = *(undefined8 *)(param_2 + 0x930);
  }
  local_f8[0] = SUB84(pcVar7,0);
  if (5 < DAT_1c00182f0) {
    if (((DAT_1c0018300 & 0x200000000000) == 0) ||
       ((DAT_1c0018308 & 0x200000000000) != DAT_1c0018308)) {
      bVar1 = false;
    }
    if (bVar1) {
      local_98 = param_2 + 0x24;
      local_100 = *(undefined4 *)(param_2 + 0x5a0);
      local_88 = &local_100;
      local_78 = &local_fc;
      local_68 = &local_c8;
      local_58 = local_f8;
      local_90 = 0x10;
      local_80 = 4;
      local_70 = 4;
      local_60 = 0x10;
      local_50 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(lVar4,&DAT_1c0016b78,0x200000000000,param_4,7,local_b8);
    }
  }
  return pcVar7;
}



===== lbfoReadConfigValue @ 1c001c9c4 =====

uint lbfoReadConfigValue(undefined8 param_1,undefined8 param_2,uint param_3,uint param_4,
                        uint param_5)

{
  uint uVar1;
  int local_28 [2];
  int *local_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_28[0] = 0;
  local_20 = (int *)0x0;
  local_18 = 0;
  uStack_10 = 0;
  RtlInitUnicodeString(&local_18);
  NdisReadConfiguration(local_28,&local_20,param_1,&local_18,0);
  if ((((local_28[0] == 0) && (*local_20 == 0)) && (uVar1 = local_20[2], uVar1 <= param_4)) &&
     (param_3 <= uVar1)) {
    param_5 = uVar1;
  }
  return param_5;
}



===== lbfoSIDeInit @ 1c001ca70 =====

void lbfoSIDeInit(longlong param_1)

{
  char cVar1;
  
  if (*(longlong *)(param_1 + 0x938) != 0) {
    cVar1 = NdisCancelTimerObject();
    if (cVar1 != '\0') {
      lbfoDecrementTeamRefCount(param_1);
    }
    KeFlushQueuedDpcs();
    NdisFreeTimerObject(*(undefined8 *)(param_1 + 0x938));
  }
  return;
}



===== lbfoSIInit @ 1c001cad0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong lbfoSIInit(longlong param_1,undefined8 param_2)

{
  uint uVar1;
  int iVar2;
  ulonglong uVar3;
  short sVar4;
  int iVar5;
  undefined1 auStackY_98 [32];
  uint local_68 [2];
  undefined8 local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_98;
  local_60 = 0;
  sVar4 = 0;
  iVar5 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  uVar3 = lbfoAllocateTimer(DAT_1c0018468,lbfoSIStabilizationTimer);
  local_68[0] = (uint)uVar3;
  if (local_68[0] == 0) {
    uVar1 = lbfoReadConfigValue(param_2,L"DropStandbyReceive",0,1,0);
    *(byte *)(param_1 + 0x942) = -(uVar1 != 0) & 4U | *(byte *)(param_1 + 0x942) & 0xfb;
    do {
      NdisOpenConfigurationKeyByIndex(local_68,param_2,iVar5,&local_58);
      iVar5 = iVar5 + 1;
      if (local_68[0] != 0) break;
      iVar2 = RtlGUIDFromString(&local_58,&local_48);
      if (-1 < iVar2) {
        sVar4 = sVar4 + 1;
        uVar1 = lbfoReadConfigValue(local_60,L"AdminMode",0,1,0);
        if (uVar1 == 1) {
          *(undefined8 *)(param_1 + 0x928) = local_48;
          *(undefined8 *)(param_1 + 0x930) = uStack_40;
        }
      }
      NdisCloseConfiguration(local_60);
    } while (local_68[0] == 0);
    if (sVar4 == 0) {
      uVar3 = 0xc0000001;
    }
    else {
      uVar3 = 0;
      *(short *)(param_1 + 0x940) = sVar4;
    }
  }
  else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_ds(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
              &WPP_dd64ea0bd6af3676b26094f7b23735c2_Traceguids,local_68[0],
              "lbfoAllocateTimer(Global.FilterDriverHandle, lbfoSIStabilizationTimer, &Team->SI.StabilizationTimer)"
             );
    uVar3 = (ulonglong)local_68[0];
  }
  return uVar3;
}



===== lbfoLACPInit @ 1c001cc90 =====

undefined8 lbfoLACPInit(longlong param_1,undefined8 param_2)

{
  longlong lVar1;
  uint uVar2;
  
  lVar1 = param_1 + 0x930;
  *(longlong *)(param_1 + 0x938) = lVar1;
  *(longlong *)lVar1 = lVar1;
  *(undefined1 *)(param_1 + 0x928) = 7;
  uVar2 = lbfoReadConfigValue(param_2,L"LacpTimeout",0,1,1);
  *(byte *)(param_1 + 0x928) =
       ((char)uVar2 * '\x02' ^ *(byte *)(param_1 + 0x928)) & 2 ^ *(byte *)(param_1 + 0x928);
  return 0;
}



===== lbfoNTHInit @ 1c001cd00 =====

undefined8 lbfoNTHInit(longlong param_1)

{
  memset((void *)(param_1 + 0x950),0,0x40);
  return 0;
}



===== lbfoDDeInit @ 1c001cd30 =====

void lbfoDDeInit(longlong param_1)

{
  KeFlushQueuedDpcs();
  if (*(longlong *)(param_1 + 0xd88) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0xd88),0x5463694e);
  }
  if (*(longlong *)(param_1 + 0xed8) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0xed8),0x5463694e);
  }
  return;
}



===== lbfoDInit @ 1c001cd90 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int lbfoDInit(longlong param_1,undefined8 param_2)

{
  ushort uVar1;
  ulonglong uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  longlong lVar6;
  void *_Dst;
  ushort uVar7;
  undefined2 uVar8;
  ulonglong uVar9;
  byte bVar10;
  size_t sVar11;
  char *pcVar12;
  size_t _Size;
  int iVar13;
  undefined1 auStackY_518 [32];
  int local_4d8;
  uint local_4d4;
  undefined8 local_4d0;
  undefined8 local_4c8;
  undefined4 local_4c0;
  undefined4 local_4bc;
  ulonglong local_4b8;
  undefined8 local_4b0;
  undefined8 uStack_4a8;
  undefined8 local_4a0;
  undefined8 uStack_498;
  undefined8 local_488 [2];
  char acStack_478 [1072];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_518;
  local_4d8 = 0;
  _Size = 0;
  local_4d0 = 0;
  local_4b0 = 0;
  uStack_4a8 = 0;
  uVar9 = 0;
  local_4a0 = 0;
  uStack_498 = 0;
  KeInitializeDpc(param_1 + 0x948,lbfoDDpcCallback,param_1);
  uVar3 = lbfoReadConfigValue(param_2,L"NumberOfBuckets",0x20,0x400,0x100);
  if ((uVar3 & uVar3 - 1) != 0) {
    uVar3 = 0x100;
  }
  *(short *)(param_1 + 0xebc) = (short)uVar3;
  uVar3 = lbfoReadConfigValue(param_2,L"MinimumTimeBeforeSwitchAbility",0x14,100,0x1e);
  *(uint *)(param_1 + 0xeb0) = uVar3 * 10000;
  uVar3 = lbfoReadConfigValue(param_2,L"TokenResetInterval",500,2000,1000);
  *(uint *)(param_1 + 0xeb4) = uVar3 * 10000;
  uVar3 = lbfoReadConfigValue(param_2,L"RebalanceMultiple",1,5,1);
  *(uint *)(param_1 + 0xeb8) = uVar3 * *(int *)(param_1 + 0xeb4);
  uVar4 = lbfoReadConfigValue(param_2,L"FlowletThreshold",10,0x32,0x19);
  *(char *)(param_1 + 0xec4) = (char)((ulonglong)(uVar4 * uVar3) / 10);
  uVar4 = lbfoReadConfigValue(param_2,L"NonFlowletThreshold",10,0x1e,0xf);
  *(char *)(param_1 + 0xec5) = (char)((ulonglong)(uVar4 * uVar3) / 10);
  uVar1 = *(ushort *)(param_1 + 0xebc);
  local_4bc = 0;
  local_4c8 = 1;
  *(ushort *)(param_1 + 0xebe) = uVar1 - 1;
  local_4c0 = 0x10;
  uVar7 = uVar1 * 0xc + 0x200;
  local_4d4 = (uint)uVar1 * 0x36;
  *(ushort *)(param_1 + 0xec0) = uVar7;
  uVar4 = (uint)uVar7 * DAT_1c0018498 + local_4d4;
  local_4b8 = (ulonglong)uVar4;
  lVar6 = ExAllocatePool3(0x40,uVar4,0x5463694e,&local_4c8);
  *(longlong *)(param_1 + 0xd88) = lVar6;
  *(ulonglong *)(param_1 + 0xd90) = (ulonglong)local_4d4 + lVar6;
  uVar2 = 0;
  if (lVar6 == 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3fffff66;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return -0x3fffff66;
    }
    uVar8 = 10;
    pcVar12 = "Dynamic->Buckets";
LAB_1c001cffe:
    local_4d8 = -0x3fffff66;
    WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar8,
             &WPP_9610058feb5536e51556e6eab0a9e872_Traceguids,pcVar12);
  }
  else {
    while( true ) {
      sVar11 = uVar2;
      bVar10 = (byte)uVar9;
      iVar13 = (int)sVar11;
      NdisOpenConfigurationKeyByIndex(&local_4d8,param_2,sVar11,&local_4b0);
      if (local_4d8 != 0) break;
      iVar5 = RtlGUIDFromString(&local_4b0,&local_4a0);
      if (-1 < iVar5) {
        sVar11 = 1;
        uVar4 = lbfoReadConfigValue(local_4d0,L"NicWeight",1,0xff,1);
        if ((char)uVar4 != '\x01') {
          lVar6 = uVar9 * 0x11;
          uVar9 = (ulonglong)(byte)(bVar10 + 1);
          *(undefined8 *)((longlong)local_488 + lVar6) = local_4a0;
          *(undefined8 *)((longlong)local_488 + lVar6 + 8) = uStack_498;
          acStack_478[lVar6] = (char)uVar4;
        }
      }
      bVar10 = (byte)uVar9;
      NdisCloseConfiguration(local_4d0);
      if ((local_4d8 != 0) || (uVar2 = (ulonglong)(iVar13 + 1), 0x3f < bVar10)) break;
    }
    local_4d8 = 0;
    if (bVar10 != 0) {
      _Size = (ulonglong)bVar10 * 0x11;
      _Dst = (void *)ExAllocatePool3(0x40,_Size,0x5463694e,&local_4c8);
      *(void **)(param_1 + 0xed8) = _Dst;
      if (_Dst == (void *)0x0) {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return -0x3fffff66;
        }
        if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
          return -0x3fffff66;
        }
        uVar8 = 0xb;
        pcVar12 = "Dynamic->GuidWeightMap";
        goto LAB_1c001cffe;
      }
      sVar11 = _Size;
      memcpy(_Dst,local_488,_Size);
      *(byte *)(param_1 + 0xee0) = bVar10;
    }
    bVar10 = *(byte *)(param_1 + 0x5fc);
    if (((bVar10 & 1) == 0) && (*(uint *)(param_1 + 0xeb0) <= DAT_1c0018470)) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (2 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_I(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(ulonglong)DAT_1c0018470,sVar11,
                 (ulonglong)DAT_1c0018470);
      }
      *(byte *)(param_1 + 0x5fc) = *(byte *)(param_1 + 0x5fc) | 1;
      bVar10 = *(byte *)(param_1 + 0x5fc);
    }
    *(undefined1 *)(param_1 + 0x658) = 1;
    if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
      if (4 < (byte)WPP_GLOBAL_Control[0x29]) {
        pcVar12 = "High";
        if ((bVar10 & 1) == 0) {
          pcVar12 = "Low";
        }
        sVar11 = (size_t)local_4d4;
        WPP_SF_IsDL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),
                    (ulonglong)*(ushort *)(param_1 + 0xebc),sVar11,(ulonglong)DAT_1c0018470,pcVar12,
                    (char)*(ushort *)(param_1 + 0xebc),(char)local_4d4);
      }
      if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
        if (4 < (byte)WPP_GLOBAL_Control[0x29]) {
          uVar9 = (ulonglong)*(uint *)(param_1 + 0xeb0) / 10000;
          WPP_SF_DLIL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar9,sVar11,
                      (uint)*(ushort *)(param_1 + 0xec0),(char)DAT_1c0018498,
                      (char)local_4b8 + (char)_Size,(char)uVar9);
        }
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar9 = (ulonglong)*(uint *)(param_1 + 0xeb4) / 10000;
          WPP_SF_LLdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar9,
                      (ulonglong)*(byte *)(param_1 + 0xec4),(int)uVar9,(char)uVar3,
                      *(undefined1 *)(param_1 + 0xec5),*(byte *)(param_1 + 0xec4));
        }
      }
    }
  }
  return local_4d8;
}



===== lbfoVMSInit @ 1c001d2e0 =====

undefined8 lbfoVMSInit(longlong param_1)

{
  *(undefined1 *)(param_1 + 0x658) = 1;
  return 0;
}



===== LbfoOidRequestWorkItem @ 1c001d300 =====

void LbfoOidRequestWorkItem(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  undefined8 uVar4;
  code *pcVar5;
  ushort uVar6;
  ulonglong local_res8;
  byte bVar7;
  
  lVar1 = *(longlong *)(param_1 + 0x100);
  local_res8 = local_res8 & 0xffffffff00000000;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),param_2,param_3,
              *(undefined4 *)(lVar1 + 0x20),(char)*(undefined4 *)(param_1 + 0x118));
  }
  if (*(int *)(lVar1 + 8) != 0) {
LAB_1c001d458:
    local_res8 = 0;
    iVar2 = NdisAllocateCloneOidRequest
                      (*(undefined8 *)(param_1 + 0x18),lVar1,0x5463694e,&local_res8);
    if (iVar2 == 0) {
      *(longlong *)(local_res8 + 0xe0) = lVar1;
      uVar3 = NdisFOidRequest(*(undefined8 *)(param_1 + 0x18),local_res8);
      if (uVar3 == 0x103) {
        return;
      }
      LbfoOidRequestComplete(param_1,local_res8,(ulonglong)uVar3);
      return;
    }
    goto LAB_1c001d4b8;
  }
  if (((*(byte *)(param_1 + 0xcc) & 2) == 0) ||
     (uVar4 = vmqInterceptOidRequest
                        ((undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x240),lVar1,
                         (int *)&local_res8), (char)uVar4 == '\0')) {
    if ((*(int *)(lVar1 + 4) == 0) || (*(int *)(lVar1 + 4) != 1)) goto LAB_1c001d458;
    iVar2 = *(int *)(lVar1 + 0x20);
    if (iVar2 == 0x10277) {
      lbfoVerifySetOidParamsAndCallHandler
                (param_1,lVar1,(undefined4 *)&local_res8,0x14,1,lbfoAddVmsPorts);
      if ((int)local_res8 == 0) {
        *(undefined4 *)(lVar1 + 0x34) = *(undefined4 *)(lVar1 + 0x30);
      }
      goto LAB_1c001d449;
    }
    if (iVar2 == 0x1027a) {
      pcVar5 = lbfoAddVmsPort;
LAB_1c001d3f6:
      uVar6 = 0x89f;
LAB_1c001d3fc:
      bVar7 = 1;
    }
    else {
      if (iVar2 == 0x1027d) {
        pcVar5 = lbfoRemoveVmsPort;
        goto LAB_1c001d3f6;
      }
      if (iVar2 != 0x10294) {
        if (iVar2 != -0x5fefdfe) goto LAB_1c001d458;
        uVar6 = 0x18;
        pcVar5 = lbfoChangeInstanceParameters;
        goto LAB_1c001d3fc;
      }
      uVar6 = 0x8b0;
      pcVar5 = lbfoUpdateVmsPort;
      bVar7 = 2;
    }
    lbfoVerifySetOidParamsAndCallHandler(param_1,lVar1,(undefined4 *)&local_res8,uVar6,bVar7,pcVar5)
    ;
  }
LAB_1c001d449:
  iVar2 = (int)local_res8;
  if ((int)local_res8 == 0x103) {
    return;
  }
LAB_1c001d4b8:
  *(undefined8 *)(param_1 + 0x100) = 0;
  NdisFOidRequestComplete(*(undefined8 *)(param_1 + 0x18),lVar1,iVar2);
  return;
}



===== lbfoAddVmsPort @ 1c001d4f0 =====

void lbfoAddVmsPort(longlong param_1,longlong param_2)

{
  ushort uVar1;
  undefined4 local_18;
  undefined2 local_14;
  
  uVar1 = 0;
  if (*(int *)(param_2 + 0x418) != 0) {
    if ((*(int *)(param_2 + 0x8a0) == 0) && (*(short *)(param_2 + 0x8a4) == 0)) {
      local_18 = *(undefined4 *)(param_2 + 0x83e);
      local_14 = *(undefined2 *)(param_2 + 0x842);
    }
    else {
      local_18 = *(undefined4 *)(param_2 + 0x8a0);
      local_14 = *(undefined2 *)(param_2 + 0x8a4);
      uVar1 = *(ushort *)(param_2 + 0x8a6);
    }
    lbfoAddVmsPortInner(*(longlong *)(param_1 + 0x10),*(uint *)(param_2 + 0x410),
                        *(undefined2 *)(param_2 + 0x83c),&local_18,uVar1);
  }
  return;
}



===== lbfoAddVmsPorts @ 1c001d570 =====

int lbfoAddVmsPorts(longlong param_1,longlong param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar2 = 0;
  uVar4 = 0;
  iVar3 = 0;
  if (*(int *)(param_2 + 0xc) != 0) {
    do {
      iVar1 = lbfoAddVmsPort(param_1,(ulonglong)*(ushort *)(param_2 + 8) +
                                     (ulonglong)(uVar4 * *(int *)(param_2 + 0x10)) + param_2);
      iVar2 = iVar3;
      if (iVar1 != 0) {
        iVar2 = iVar1;
      }
      uVar4 = uVar4 + 1;
      iVar3 = iVar2;
    } while (uVar4 < *(uint *)(param_2 + 0xc));
  }
  return iVar2;
}



===== lbfoIssueOidRequestAnyFilter @ 1c001d5e8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int lbfoIssueOidRequestAnyFilter
              (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  ushort uVar1;
  int iVar2;
  ushort uVar3;
  ulonglong uVar4;
  undefined1 auStackY_178 [32];
  longlong local_138 [32];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_178;
  memset(local_138,0,0x100);
  iVar2 = -0x3fffffff;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_DL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18));
  }
  uVar1 = lbfoRefFilterContextsForOid(param_1,(longlong)local_138);
  uVar3 = 0;
  if (uVar1 != 0) {
    while( true ) {
      iVar2 = lbfoIssueOidRequestOnFilter
                        (*(undefined8 *)(local_138[uVar3] + 0x18),0x10207,0,0,param_4,0x28,
                         (undefined4 *)0x0);
      if (((iVar2 == 0) || (iVar2 == -0x7ffffffb)) || (iVar2 == -0x3ffeffea)) break;
      if ((iVar2 == -0x3ffeffec) || (uVar3 = uVar3 + 1, uVar1 <= uVar3)) break;
    }
  }
  uVar4 = (ulonglong)uVar1;
  lbfoDerefFilterContextsForOid(param_1,local_138,uVar1);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_DLd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,uVar4,0x10207,0,(char)iVar2);
  }
  return iVar2;
}



===== lbfoIssueOidRequestOnFilter @ 1c001d738 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int lbfoIssueOidRequestOnFilter
              (undefined8 param_1,undefined4 param_2,int param_3,undefined4 param_4,
              undefined8 param_5,undefined4 param_6,undefined4 *param_7)

{
  int iVar1;
  undefined8 uVar2;
  undefined4 *puVar3;
  undefined8 uVar4;
  undefined1 auStackY_198 [32];
  undefined8 local_158;
  undefined8 uStack_150;
  undefined8 local_148;
  undefined4 local_138;
  int local_134;
  undefined4 local_130;
  undefined4 local_12c;
  undefined8 local_128;
  undefined8 local_120;
  undefined4 local_118;
  undefined8 local_110;
  undefined4 local_108;
  undefined4 local_104;
  undefined4 local_100;
  undefined4 local_f4;
  undefined8 *local_60;
  int local_58;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_198;
  memset(&local_138,0,0xf0);
  local_138 = 0xec0196;
  local_12c = 0;
  local_128 = 0;
  local_148 = 0;
  local_158 = 0;
  uStack_150 = 0;
  if ((param_3 == 0) || (param_3 == 1)) {
LAB_1c001d7d8:
    local_110 = param_5;
    local_118 = param_2;
    local_108 = param_6;
  }
  else if (param_3 == 0xc) {
    local_104 = param_6;
    goto LAB_1c001d7d8;
  }
  uVar4 = 0;
  uVar2 = 0;
  local_134 = param_3;
  local_130 = param_4;
  local_120 = param_1;
  KeInitializeEvent(&local_158);
  local_60 = &local_158;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_DLdq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar2,uVar4,param_2,(char)param_3,
                (char)param_4,(char)param_1);
  }
  puVar3 = &local_138;
  iVar1 = NdisFOidRequest(param_1);
  if (iVar1 == 0x103) {
    uVar4 = 0;
    puVar3 = (undefined4 *)0x0;
    KeWaitForSingleObject(&local_158,0,0,0);
    iVar1 = local_58;
  }
  if (param_7 != (undefined4 *)0x0) {
    if (((iVar1 == -0x7ffffffb) || (iVar1 == -0x3ffeffea)) || (iVar1 == -0x3ffeffec)) {
      if ((param_3 == 0) || (param_3 == 1)) {
        local_f4 = local_100;
      }
      else if (param_3 != 0xc) goto LAB_1c001d8b0;
      *param_7 = local_f4;
    }
    else {
      *param_7 = 0;
    }
  }
LAB_1c001d8b0:
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_DLdqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),puVar3,uVar4,param_2,(char)param_3,
                 (char)param_4,(char)param_1,(char)iVar1);
  }
  return iVar1;
}



===== lbfoIssueOidRequestOnFilterEx @ 1c001d910 =====

int lbfoIssueOidRequestOnFilterEx
              (undefined8 param_1,ulonglong param_2,undefined8 param_3,undefined4 param_4,
              longlong *param_5,uint *param_6)

{
  uint uVar1;
  int iVar2;
  ulonglong uVar3;
  uint uVar4;
  undefined8 uVar5;
  uint local_res18 [2];
  longlong lVar6;
  undefined8 local_30;
  undefined4 local_28;
  undefined4 local_24;
  
  local_30 = 1;
  local_res18[0] = 0;
  local_24 = 0;
  local_28 = 0x10;
  lVar6 = 0;
  uVar3 = param_2;
  uVar4 = 0;
  do {
    uVar5 = 0;
    iVar2 = lbfoIssueOidRequestOnFilter(param_1,(int)uVar3,0,param_4,lVar6,uVar4,local_res18);
    uVar1 = local_res18[0];
    if (((iVar2 != -0x3ffeffec) && (iVar2 != -0x7ffffffb)) && (iVar2 != -0x3ffeffea)) {
      if (iVar2 != 0) {
LAB_1c001da38:
        uVar4 = 0;
        if (lVar6 != 0) {
          ExFreePoolWithTag(lVar6,0x5463694e);
          lVar6 = 0;
        }
      }
      goto LAB_1c001da55;
    }
    if (local_res18[0] <= uVar4) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_Ddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar3,uVar5,(int)param_2,
                   (char)local_res18[0],(char)uVar4);
      }
      iVar2 = -0x3fffffff;
      goto LAB_1c001da38;
    }
    if (lVar6 != 0) {
      ExFreePoolWithTag(lVar6,0x5463694e);
    }
    lVar6 = ExAllocatePool3(0x40,uVar1,0x5463694e,&local_30,1);
    if (lVar6 == 0) {
      iVar2 = -0x3fffff66;
      uVar4 = 0;
LAB_1c001da55:
      *param_5 = lVar6;
      *param_6 = uVar4;
      return iVar2;
    }
    uVar3 = param_2 & 0xffffffff;
    uVar4 = uVar1;
  } while( true );
}



===== lbfoIssueOidRequestOnNic @ 1c001da90 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int lbfoIssueOidRequestOnNic
              (longlong param_1,undefined8 param_2,undefined8 param_3,byte param_4,
              undefined8 param_5)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  ushort uVar4;
  undefined8 uVar5;
  undefined1 auStackY_198 [32];
  longlong local_148 [32];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_198;
  uVar5 = 0x100;
  memset(local_148,0,0x100);
  iVar2 = -0x3fffffff;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_DLd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,uVar5,0xfa010203,1,param_4);
  }
  uVar1 = lbfoRefFilterContextsForOid(param_1,(longlong)local_148);
  uVar4 = 0;
  if (uVar1 != 0) {
    do {
      uVar3 = (uint)*(byte *)(local_148[uVar4] + 0x89 + (ulonglong)param_4);
      if ((uVar3 != 0) &&
         ((((iVar2 = lbfoIssueOidRequestOnFilter
                               (*(undefined8 *)(local_148[uVar4] + 0x18),0xfa010203,1,uVar3,param_5,
                                6,(undefined4 *)0x0), iVar2 == 0 || (iVar2 == -0x7ffffffb)) ||
           (iVar2 == -0x3ffeffea)) || (iVar2 == -0x3ffeffec)))) break;
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar1);
  }
  lbfoDerefFilterContextsForOid(param_1,local_148,uVar1);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_DLddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18));
  }
  return iVar2;
}



===== lbfoVerifySetOidParamsAndCallHandler @ 1c001dc1c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void lbfoVerifySetOidParamsAndCallHandler
               (undefined8 param_1,longlong param_2,undefined4 *param_3,ushort param_4,byte param_5,
               undefined *param_6)

{
  longlong lVar1;
  undefined4 uVar2;
  
  lVar1 = *(longlong *)(param_2 + 0x28);
  if ((lVar1 == 0) || (*(uint *)(param_2 + 0x30) < (uint)param_4)) {
    *(undefined4 *)(param_2 + 0x34) = 0;
    uVar2 = 0xc0010016;
    *(uint *)(param_2 + 0x38) = (uint)param_4;
  }
  else if ((*(byte *)(lVar1 + 1) < param_5) || (*(ushort *)(lVar1 + 2) < param_4)) {
    *(undefined4 *)(param_2 + 0x34) = 4;
    uVar2 = 0xc00000bb;
  }
  else {
    *(uint *)(param_2 + 0x34) = (uint)param_4;
    uVar2 = (*(code *)param_6)(param_1,lVar1,param_2);
  }
  *param_3 = uVar2;
  return;
}



===== lbfoPrimeSwitchIfNeededWorkItem @ 1c001dc90 =====

void lbfoPrimeSwitchIfNeededWorkItem(longlong param_1,undefined8 param_2)

{
  lbfoPrimeSwitchIfNeeded(param_1);
  lbfoDecrementTeamRefCount(param_1);
  NdisFreeIoWorkItem(param_2);
  return;
}



===== entry @ 1c001e010 =====

void entry(undefined *param_1,undefined *param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 1c001e044 =====

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



===== DriverEntry @ 1c001e078 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0001c001e479) */
/* WARNING: Removing unreachable block (ram,0x0001c001e44f) */
/* WARNING: Removing unreachable block (ram,0x0001c001e435) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DriverEntry(undefined *param_1,undefined *param_2)

{
  undefined2 uVar1;
  undefined8 uVar2;
  undefined4 *puVar3;
  ulonglong *puVar4;
  short sVar5;
  undefined4 uVar6;
  int iVar7;
  char *pcVar8;
  byte bVar9;
  undefined *puVar10;
  code *pcVar11;
  undefined1 *puVar12;
  undefined8 *puVar13;
  undefined1 auStackY_148 [8];
  undefined1 auStackY_140 [24];
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_148;
  puVar13 = &MsLbfoEventProvider_Context;
  Global = param_1;
  uVar6 = McGenEventRegister_EtwRegister
                    (&MsLbfoEventProvider,param_2,&MsLbfoEventProvider_Context,
                     &MsLbfoEventProvider_Context);
  iVar7 = NdisConvertNtStatusToNdisStatus(uVar6);
  if (iVar7 == 0) {
    DAT_1c001849c = DAT_1c001849c | 2;
    puVar13 = (undefined8 *)&MsLbfoSystemEventProvider_Context;
    uVar6 = McGenEventRegister_EtwRegister
                      (&MsLbfoSystemEventProvider,param_2,&MsLbfoSystemEventProvider_Context,
                       (longlong *)&MsLbfoSystemEventProvider_Context);
    iVar7 = NdisConvertNtStatusToNdisStatus(uVar6);
    if (iVar7 == 0) {
      DAT_1c001849c = DAT_1c001849c | 1;
      iVar7 = 0;
      if (Microsoft_Windows_Networking_CorrelationHandle == 0) {
        puVar13 = (undefined8 *)0x0;
        pcVar11 = Microsoft_Windows_Networking_Correlation_EtwEnableCallback;
        iVar7 = EtwRegister(&Microsoft_Windows_Networking_CorrelationId,
                            Microsoft_Windows_Networking_Correlation_EtwEnableCallback,0,
                            &Microsoft_Windows_Networking_CorrelationHandle);
        param_2 = pcVar11;
        if (iVar7 == 0) goto LAB_1c001e2bd;
      }
      else {
LAB_1c001e2bd:
        _Microsoft_Windows_Networking_ProviderId = 0xb72c6994;
        uRam00000001c0018404 = 0x45ad9fe0;
        uRam00000001c0018408 = 0x588fb383;
        uRam00000001c001840c = 0xe0ef285;
      }
      iVar7 = NdisConvertNtStatusToNdisStatus(iVar7);
      puVar12 = auStackY_148;
      if (iVar7 == 0) {
        DAT_1c001849c = DAT_1c001849c | 4;
        local_38 = *(undefined4 *)(PTR_DAT_1c00182f8 + -0x10);
        uStack_34 = *(undefined4 *)(PTR_DAT_1c00182f8 + -0xc);
        uStack_30 = *(undefined4 *)(PTR_DAT_1c00182f8 + -8);
        uStack_2c = *(undefined4 *)(PTR_DAT_1c00182f8 + -4);
        if (DAT_1c0018310 != 0) {
          pcVar11 = (code *)swi(0x29);
          (*pcVar11)(5);
          puVar12 = auStackY_140;
        }
        _DAT_1c0018318 = 0;
        DAT_1c0018320 = 0;
        *(undefined8 *)(puVar12 + -8) = 0x1c001e364;
        iVar7 = EtwRegister(&local_38,_tlgEnableCallback,&DAT_1c00182f0,&DAT_1c0018310);
        if (iVar7 == 0) {
          uVar1 = *(undefined2 *)PTR_DAT_1c00182f8;
          *(undefined8 *)(puVar12 + -8) = 0x1c001e389;
          EtwSetInformation(DAT_1c0018310,2,PTR_DAT_1c00182f8,uVar1);
        }
        _WPP_MAIN_CB = 0;
        DAT_1c0018428 = &WPP_ThisDir_CTLGUID_LBFOProviderGUID;
        DAT_1c0018430 = 0;
        _DAT_1c0018440 = 0;
        _DAT_1c0018448 = 1;
        *(undefined8 *)(puVar12 + -8) = 0x1c001e3c1;
        WppLoadTracingSupport();
        _DAT_1c0018440 = 0;
        *(undefined8 *)(puVar12 + -8) = 0x1c001e3cd;
        WppInitKm();
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar2 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
          *(undefined8 *)(puVar12 + -8) = 0x1c001e3fb;
          WPP_SF_(uVar2,0xd,&WPP_b7202525798e3186f26c2d40dc3ccbc1_Traceguids);
        }
        *(code **)(param_1 + 0x68) = LbfoDriverUnload;
        DAT_1c0018488 = &DAT_1c0018480;
        DAT_1c0018480 = &DAT_1c0018480;
        *(undefined8 *)(puVar12 + -8) = 0x1c001e429;
        KeInitializeSpinLock(&DAT_1c0018478);
        puVar3 = (undefined4 *)cpuid_Version_info(1);
        local_38 = *puVar3;
        uStack_34 = puVar3[1];
        uStack_30 = 0;
        uStack_2c = 0;
        if ((int)puVar3[3] < 0) {
          puVar3 = (undefined4 *)cpuid(0x40000000);
          local_38 = *puVar3;
          uStack_34 = puVar3[1];
          uStack_30 = puVar3[3];
          if ((CONCAT44(uStack_30,uStack_34) != 0x666f736f7263694d) || (puVar3[2] != 0x76482074))
          goto LAB_1c001e490;
          puVar4 = (ulonglong *)cpuid(0x40000003);
          local_38 = (undefined4)*puVar4;
          uStack_34 = *(undefined4 *)((longlong)puVar4 + 4);
          bVar9 = ~(byte)(*puVar4 >> 0x29) & 8;
        }
        else {
LAB_1c001e490:
          bVar9 = 0;
        }
        DAT_1c001849c = DAT_1c001849c & 0xf7 | bVar9;
        *(undefined8 *)(puVar12 + -8) = 0x1c001e4aa;
        sVar5 = KeQueryHighestNodeNumber();
        DAT_1c001849c = DAT_1c001849c & 0xbf | -(sVar5 != 0) & 0x40U;
        *(undefined8 *)(puVar12 + -8) = 0x1c001e4d5;
        DAT_1c0018498 = NdisGroupMaxProcessorCount(0xffff);
        *(undefined8 *)(puVar12 + -8) = 0x1c001e4e7;
        DAT_1c0018470 = KeQueryTimeIncrement();
        *(undefined8 *)(puVar12 + -8) = 0x1c001e500;
        KeQueryPerformanceCounter(&DAT_1c0018490);
        param_2 = (code *)0x0;
        puVar13 = (undefined8 *)(puVar12 + 0x30);
        *(undefined8 *)(puVar12 + -8) = 0x1c001e51d;
        iVar7 = NdisFRegisterFilterDriver();
        puVar10 = param_1;
        if (((iVar7 != 0) &&
            (puVar10 = WPP_GLOBAL_Control, (undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control))
           && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          puVar10 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
          param_2 = (code *)0xe;
          *(char **)(puVar12 + 0x20) =
               "NdisFRegisterFilterDriver(DriverObj,NULL,&DriverChars,&Global.FilterDriverHandle)";
          puVar13 = (undefined8 *)&WPP_b7202525798e3186f26c2d40dc3ccbc1_Traceguids;
          *(undefined8 *)(puVar12 + -8) = 0x1c001e55e;
          WPP_SF_ds(puVar10,0xe,&WPP_b7202525798e3186f26c2d40dc3ccbc1_Traceguids,iVar7,
                    *(char **)(puVar12 + 0x20));
        }
        goto LAB_1c001e55e;
      }
      puVar10 = WPP_GLOBAL_Control;
      puVar12 = auStackY_148;
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         (puVar12 = auStackY_148, (byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1c001e55e;
      param_2 = (code *)0xc;
      pcVar8 = 
      "NetTrcRegisterCorrelationProviderEx(&MsLbfoEventProvider, &Microsoft_Windows_MsLbfoEventProviderHandle)"
      ;
    }
    else {
      puVar10 = WPP_GLOBAL_Control;
      puVar12 = auStackY_148;
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         (puVar12 = auStackY_148, (byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1c001e55e;
      param_2 = &DAT_0000000b;
      pcVar8 = "EventRegisterMicrosoft_Windows_MsLbfoSysEvtProvider()";
    }
  }
  else {
    puVar10 = WPP_GLOBAL_Control;
    puVar12 = auStackY_148;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       (puVar12 = auStackY_148, (byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1c001e55e;
    param_2 = (code *)0xa;
    pcVar8 = "EventRegisterMicrosoft_Windows_MsLbfoEventProvider()";
  }
  puVar10 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
  puVar13 = (undefined8 *)&WPP_b7202525798e3186f26c2d40dc3ccbc1_Traceguids;
  WPP_SF_ds(puVar10,(short)param_2,&WPP_b7202525798e3186f26c2d40dc3ccbc1_Traceguids,iVar7,pcVar8);
  puVar12 = auStackY_148;
LAB_1c001e55e:
  if (((DAT_1c001849c & 2) != 0) && ((Microsoft_Windows_MsLbfoEventProviderEnableBits & 1) != 0)) {
    *(undefined8 *)(puVar12 + -8) = 0x1c001e578;
    McTemplateK0d_EtwWriteTransfer(puVar10,param_2,puVar13,iVar7);
  }
  if (iVar7 != 0) {
    *(undefined8 *)(puVar12 + -8) = 0x1c001e584;
    LbfoDriverUnload();
  }
  *(undefined8 *)(puVar12 + -8) = 0x1c001e58d;
  NdisConvertNdisStatusToNtStatus(iVar7);
  *(undefined8 *)(puVar12 + -8) = 0x1c001e59e;
  return;
}


