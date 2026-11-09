
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



===== TreeDetectSecureServices @ 140001020 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl TreeDetectSecureServices(struct WDFDEVICE__ * __ptr64) */

long __cdecl TreeDetectSecureServices(WDFDEVICE__ *param_1)

{
  longlong *plVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  _TREE_MASTER_DEVICE_CONTEXT **_Src;
  ulonglong uVar5;
  _TREE_MASTER_DEVICE_CONTEXT **pp_Var6;
  undefined8 uVar7;
  uint uVar8;
  char *pcVar9;
  _TREE_MASTER_DEVICE_CONTEXT **pp_Var10;
  _TREE_MASTER_DEVICE_CONTEXT **pp_Var11;
  undefined1 auStackY_198 [32];
  undefined *in_stack_fffffffffffffe88;
  uint local_128;
  uint local_124;
  _TREE_MASTER_DEVICE_CONTEXT **local_120;
  _TREE_MASTER_DEVICE_CONTEXT *local_118;
  ushort local_110 [4];
  undefined1 *local_108;
  longlong local_100;
  undefined4 local_f8;
  undefined8 local_f4;
  undefined8 uStack_ec;
  undefined4 local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  WDFDEVICE__ *local_d8;
  ulonglong local_d0;
  undefined *local_c8;
  undefined1 local_b8 [128];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_198;
  local_120 = (_TREE_MASTER_DEVICE_CONTEXT **)0x0;
  pp_Var10 = (_TREE_MASTER_DEVICE_CONTEXT **)PTR__WDF_TREE_MASTER_DEVICE_CONTEXT_TYPE_INFO_14000f0f0
  ;
  local_100 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  _Src = (_TREE_MASTER_DEVICE_CONTEXT **)0x0;
  local_e4 = 0;
  local_e0 = 1;
  pp_Var11 = (_TREE_MASTER_DEVICE_CONTEXT **)0x0;
  local_dc = 1;
  local_124 = 0;
  local_f4 = 0;
  uStack_ec = 0;
  local_d0 = 0;
  local_f8 = 0x38;
  local_c8 = PTR__WDF_TREE_SECURE_ENVIRONMENT_SERVICE_CONTEXT_TYPE_INFO_14000f168;
  local_128 = 0;
  local_d8 = param_1;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    in_stack_fffffffffffffe88 = &WPP_49bb3939113c3b574f8f0bbeefc4fba7_Traceguids;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                     &WPP_49bb3939113c3b574f8f0bbeefc4fba7_Traceguids,pp_Var10,0xc,
                     &WPP_49bb3939113c3b574f8f0bbeefc4fba7_Traceguids);
    local_128 = 0;
  }
  while( true ) {
    while( true ) {
      pp_Var6 = &local_118;
      local_118 = (_TREE_MASTER_DEVICE_CONTEXT *)0x0;
      iVar3 = TreeCxGetDeviceContext(param_1,pp_Var6);
      if (-1 < iVar3) {
        if (*(code **)(local_118 + 0x68) == (code *)0x0) {
          iVar3 = -0x3fffff45;
        }
        else {
          pp_Var6 = pp_Var11;
          pp_Var10 = _Src;
          iVar3 = (**(code **)(local_118 + 0x68))(param_1,pp_Var11,_Src,&local_128);
        }
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        pp_Var6 = (_TREE_MASTER_DEVICE_CONTEXT **)CONCAT71((int7)((ulonglong)pp_Var6 >> 8),2);
        in_stack_fffffffffffffe88 = &WPP_36fd475e9c0f3a4c5e3e805381d963da_Traceguids;
        WPP_RECORDER_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,pp_Var10,0x15,
                           &WPP_36fd475e9c0f3a4c5e3e805381d963da_Traceguids,(char)param_1,
                           (char)iVar3);
      }
      if ((iVar3 != -0x7ffffffb) && (iVar3 != -0x3fffffdd)) break;
      if (_Src != (_TREE_MASTER_DEVICE_CONTEXT **)0x0) {
        ExFreePoolWithTag(_Src,0x45457254);
      }
      pp_Var10 = (_TREE_MASTER_DEVICE_CONTEXT **)0x45457254;
      _Src = (_TREE_MASTER_DEVICE_CONTEXT **)ExAllocatePool2(0x100,local_128);
      if (_Src == (_TREE_MASTER_DEVICE_CONTEXT **)0x0) {
        iVar3 = -0x3fffff66;
        goto LAB_1400015c4;
      }
      local_124 = local_128;
    }
    if (iVar3 < 0) {
      if (iVar3 == -0x7fffffe6) {
        iVar3 = 0;
      }
      goto LAB_1400015c4;
    }
    if (_Src == (_TREE_MASTER_DEVICE_CONTEXT **)0x0) {
      iVar3 = -0x3fffff1b;
      goto LAB_1400015c4;
    }
    if ((*(uint *)_Src != local_128) || (local_128 < 0x24)) break;
    pp_Var10 = (_TREE_MASTER_DEVICE_CONTEXT **)(ulonglong)*(uint *)(_Src + 4);
    pp_Var6 = (_TREE_MASTER_DEVICE_CONTEXT **)((ulonglong)(local_128 - 0x24) / 0x18);
    if (pp_Var6 < pp_Var10) break;
    if (*(uint *)((longlong)_Src + 0x1c) == 0) {
      uVar5 = 0;
LAB_140001201:
      if ((ulonglong)*(uint *)_Src - 8 <= uVar5) goto LAB_14000120e;
    }
    else {
      uVar5 = (ulonglong)*(uint *)((longlong)_Src + 0x1c);
      if ((longlong)pp_Var10 * 0x18 + 0x24U <= uVar5) goto LAB_140001201;
LAB_14000120e:
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pp_Var6,pp_Var10,0xe,
                          in_stack_fffffffffffffe88,(char)pp_Var11);
      }
      local_108 = local_b8;
      in_stack_fffffffffffffe88 =
           (undefined *)
           CONCAT44((int)((ulonglong)in_stack_fffffffffffffe88 >> 0x20),
                    (uint)*(ushort *)((longlong)_Src + 10));
      local_110[0] = 0;
      local_110[1] = 0x78;
      local_110[2] = 0;
      local_110[3] = 0;
      RtlUnicodeStringPrintf
                (local_110,L"{%08lx-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x}",
                 (ulonglong)*(uint *)((longlong)_Src + 4),(ulonglong)*(ushort *)(_Src + 1));
      DbgPrintEx(0x4d,0,"Secure service (%wZ) descriptor\'s ExtensionOffset field is not valid.\n",
                 local_110);
      *(undefined4 *)((longlong)_Src + 0x1c) = 0;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF__guid_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
    local_d0 = (ulonglong)(*(int *)_Src + 0x10U);
    if (*(int *)_Src + 0x10U < 0x51) {
      local_d0 = 0;
    }
    iVar3 = (**(code **)(WdfFunctions_01015 + 0x678))(WdfDriverGlobals,&local_f8,&local_120);
    if (iVar3 < 0) goto LAB_1400015c4;
    lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,local_120,
                       PTR__WDF_TREE_SECURE_ENVIRONMENT_SERVICE_CONTEXT_TYPE_INFO_14000f168);
    memcpy((void *)(lVar4 + 0x10),_Src,(ulonglong)*(uint *)_Src);
    uVar5 = 0;
    if (*(int *)(_Src + 4) != 0) {
      do {
        pcVar9 = (char *)(uVar5 * 3);
        iVar2 = *(int *)(lVar4 + 0x34 + uVar5 * 0x18);
        if (iVar2 == 0) {
          plVar1 = (longlong *)(lVar4 + 0x3c + uVar5 * 0x18);
          if ((*plVar1 == 0x4497ad1a05272f96) && (plVar1[1] == -0x4c684e9a46e93d69)) {
            pcVar9 = 
            "GUID_TREE_RPMB_SERVICE is deprecated. Please use GUID_DEVINTERFACE_EMMC_PARTITION_ACCESS_RPMB instead.\n"
            ;
            uVar7 = 0;
            DbgPrintEx(0x4d);
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              in_stack_fffffffffffffe88 = &WPP_49bb3939113c3b574f8f0bbeefc4fba7_Traceguids;
              WPP_RECORDER_SF__guid_
                        (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar7,pcVar9,0x10,
                         &WPP_49bb3939113c3b574f8f0bbeefc4fba7_Traceguids,(longlong)_Src + 4);
            }
            *plVar1 = 0x4d07bcc327447c21;
            plVar1[1] = -0x18114ba4c65ca460;
          }
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF__guid__guid_
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),0x4497ad1a05272f96,pcVar9,0x11,
                       in_stack_fffffffffffffe88,(longlong)_Src + 4,plVar1);
          }
LAB_14000146b:
          if (iVar3 < 0) goto LAB_1400015c4;
        }
        else {
          if (iVar2 == 1) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF__guid__guid_
                        (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),0x4497ad1a05272f96,pcVar9,0x12,
                         in_stack_fffffffffffffe88,(longlong)_Src + 4,lVar4 + 0x3c + uVar5 * 0x18);
            }
            goto LAB_14000146b;
          }
          iVar3 = 0;
        }
        uVar8 = (int)uVar5 + 1;
        uVar5 = (ulonglong)uVar8;
      } while (uVar8 < *(uint *)(_Src + 4));
    }
    iVar3 = (**(code **)(WdfFunctions_01015 + 0x78))
                      (WdfDriverGlobals,*(undefined8 *)(local_100 + 0x10),local_120);
    if ((iVar3 < 0) ||
       (pp_Var10 = local_120,
       iVar3 = (**(code **)(WdfFunctions_01015 + 0x78))
                         (WdfDriverGlobals,TreeSecureServiceCollection), iVar3 < 0))
    goto LAB_1400015c4;
    pp_Var11 = (_TREE_MASTER_DEVICE_CONTEXT **)(ulonglong)((int)pp_Var11 + 1);
    local_128 = local_124;
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pp_Var6,pp_Var10,0xd,
                      in_stack_fffffffffffffe88,(char)pp_Var11);
  }
  iVar3 = -0x3ffffff3;
LAB_1400015c4:
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  if (_Src != (_TREE_MASTER_DEVICE_CONTEXT **)0x0) {
    ExFreePoolWithTag(_Src,0x45457254);
  }
  return iVar3;
}



===== RtlUnicodeStringPrintf @ 14000163c =====

undefined8
RtlUnicodeStringPrintf(ushort *param_1,wchar_t *param_2,undefined8 param_3,undefined8 param_4)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  ulonglong _Count;
  undefined8 local_res18;
  undefined8 local_res20;
  
  uVar1 = *param_1;
  if ((((((uVar1 & 1) == 0) && (uVar2 = param_1[1], (uVar2 & 1) == 0)) && (uVar1 <= uVar2)) &&
      (uVar2 != 0xffff)) &&
     ((uVar5 = 0, *(longlong *)(param_1 + 4) != 0 || ((uVar1 == 0 && (uVar2 == 0)))))) {
    _Count = (ulonglong)(param_1[1] >> 1);
    local_res18 = param_3;
    local_res20 = param_4;
    iVar3 = _vsnwprintf(*(wchar_t **)(param_1 + 4),_Count,param_2,(va_list)&local_res18);
    if ((iVar3 < 0) || (uVar4 = (longlong)iVar3, _Count < (ulonglong)(longlong)iVar3)) {
      uVar5 = 0x80000005;
      uVar4 = _Count;
    }
    *param_1 = (short)uVar4 * 2;
  }
  else {
    uVar5 = 0xc000000d;
  }
  return uVar5;
}



===== TreeConfigureSecureServices @ 1400016dc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

long TreeConfigureSecureServices(WDFDEVICE__ *param_1)

{
  long lVar1;
  uint uVar2;
  longlong lVar3;
  undefined8 uVar4;
  longlong lVar5;
  uint uVar6;
  undefined1 auStack_68 [48];
  undefined4 local_38;
  undefined8 local_34;
  undefined8 uStack_2c;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_68;
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,
                     PTR__WDF_TREE_MASTER_DEVICE_CONTEXT_TYPE_INFO_14000f0f0);
  lVar1 = TreeDetectSecureServices(param_1);
  if (-1 < lVar1) {
    local_34 = 0;
    uStack_2c = 0;
    local_38 = 0x14;
    uVar2 = (**(code **)(WdfFunctions_01015 + 0x70))(WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x10))
    ;
    uVar6 = 0;
    if (uVar2 != 0) {
      do {
        uVar4 = (**(code **)(WdfFunctions_01015 + 0x90))
                          (WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x10),uVar6);
        lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                          (WdfDriverGlobals,uVar4,
                           PTR__WDF_TREE_SECURE_ENVIRONMENT_SERVICE_CONTEXT_TYPE_INFO_14000f168);
        local_34 = *(undefined8 *)(lVar5 + 0x14);
        uStack_2c = *(undefined8 *)(lVar5 + 0x1c);
        uVar4 = (**(code **)(WdfFunctions_01015 + 0x420))(WdfDriverGlobals,param_1);
        lVar1 = (**(code **)(WdfFunctions_01015 + 0x48))(WdfDriverGlobals,uVar4,&local_38,0);
        if (lVar1 < 0) {
          return lVar1;
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 < uVar2);
    }
  }
  return lVar1;
}



===== TreeEnumerateServiceGuids @ 140001840 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TreeEnumerateServiceGuids(undefined8 param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  undefined8 uVar7;
  longlong lVar8;
  uint uVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  longlong lVar12;
  longlong local_res10 [3];
  
  uVar10 = 0;
  local_res10[1] = 0;
  local_res10[0] = 0;
  uVar5 = (**(code **)(WdfFunctions_01015 + 0x70))(WdfDriverGlobals,TreeSecureServiceCollection);
  uVar11 = (ulonglong)uVar5 << 4;
  iVar6 = (**(code **)(WdfFunctions_01015 + 0x870))
                    (WdfDriverGlobals,param_1,uVar11,local_res10,local_res10 + 1);
  if (iVar6 < 0) {
    if (iVar6 == -0x3fffffdd) {
      iVar6 = -0x7ffffffb;
      lVar12 = (**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals,param_1);
      *(uint *)(lVar12 + 0x10) = *(uint *)(lVar12 + 0x10) & 0xffffffbf;
      uVar10 = uVar11;
    }
  }
  else {
    if (uVar5 != 0) {
      lVar12 = 0;
      do {
        uVar7 = (**(code **)(WdfFunctions_01015 + 0x90))
                          (WdfDriverGlobals,TreeSecureServiceCollection,uVar10);
        lVar8 = (**(code **)(WdfFunctions_01015 + 0x650))
                          (WdfDriverGlobals,uVar7,
                           PTR__WDF_TREE_SECURE_ENVIRONMENT_SERVICE_CONTEXT_TYPE_INFO_14000f168);
        uVar9 = (int)uVar10 + 1;
        uVar10 = (ulonglong)uVar9;
        uVar2 = *(undefined4 *)(lVar8 + 0x18);
        uVar3 = *(undefined4 *)(lVar8 + 0x1c);
        uVar4 = *(undefined4 *)(lVar8 + 0x20);
        puVar1 = (undefined4 *)(lVar12 + local_res10[0]);
        *puVar1 = *(undefined4 *)(lVar8 + 0x14);
        puVar1[1] = uVar2;
        puVar1[2] = uVar3;
        puVar1[3] = uVar4;
        lVar12 = lVar12 + 0x10;
      } while (uVar9 < uVar5);
    }
    uVar10 = uVar11;
  }
  (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,param_1,iVar6,uVar10);
  return;
}



===== TreeEvtCleanupChildDeviceDescriptor @ 1400019a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TreeEvtCleanupChildDeviceDescriptor(undefined8 param_1,longlong param_2)

{
  uint uVar1;
  undefined8 uVar2;
  longlong lVar3;
  undefined8 *puVar4;
  uint uVar5;
  
  uVar2 = (**(code **)(WdfFunctions_01015 + 8))(WdfDriverGlobals,param_1);
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar2,PTR__WDF_TREE_MASTER_DEVICE_CONTEXT_TYPE_INFO_14000f0f0)
  ;
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x70))(WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x10));
  uVar5 = 0;
  if (uVar1 != 0) {
    do {
      uVar2 = (**(code **)(WdfFunctions_01015 + 0x90))
                        (WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x10),uVar5);
      puVar4 = (undefined8 *)
               (**(code **)(WdfFunctions_01015 + 0x650))
                         (WdfDriverGlobals,uVar2,
                          PTR__WDF_TREE_SECURE_ENVIRONMENT_SERVICE_CONTEXT_TYPE_INFO_14000f168);
      if ((*(longlong *)((longlong)puVar4 + 0x14) == *(longlong *)(param_2 + 4)) &&
         (*(longlong *)((longlong)puVar4 + 0x1c) == *(longlong *)(param_2 + 0xc))) break;
      uVar5 = uVar5 + 1;
    } while (uVar5 < uVar1);
    if (puVar4 != (undefined8 *)0x0) {
      *puVar4 = 0;
      puVar4[1] = 0;
    }
  }
  return;
}



===== TreeEvtCompareChildDeviceDescriptors @ 140001ab0 =====

bool TreeEvtCompareChildDeviceDescriptors(undefined8 param_1,longlong param_2,longlong param_3)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_2 + 4) - *(longlong *)(param_3 + 4);
  if (lVar1 == 0) {
    lVar1 = *(longlong *)(param_2 + 0xc) - *(longlong *)(param_3 + 0xc);
  }
  return lVar1 == 0;
}



===== TreeEvtCompleteSessionCallWorkItem @ 140001ad0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TreeEvtCompleteSessionCallWorkItem(undefined8 param_1)

{
  undefined8 *puVar1;
  longlong lVar2;
  
  puVar1 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,
                      PTR__WDF_TREE_SESSION_COMPLETION_WORKITEM_TYPE_INFO_14000f190);
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,*puVar1,PTR__WDF_TREE_SESSION_CALL_DATA_TYPE_INFO_14000f0c8);
  (**(code **)(lVar2 + 0x40))(*puVar1);
  (**(code **)(WdfFunctions_01015 + 0x670))
            (WdfDriverGlobals,*puVar1,0,0x41f,
             "onecore\\base\\basedrv\\tree\\treeclx\\driver\\treedrv.cxx");
  (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,param_1);
  return;
}



===== TreeEvtControlDeviceIoControl @ 140001ba0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TreeEvtControlDeviceIoControl
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               int param_5)

{
  if (param_5 == 0x560008) {
    TreeEnumerateServiceGuids(param_2);
  }
  else {
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,0xc000000d);
  }
  return;
}



===== TreeEvtControlWdmDeviceFileCreate @ 140001bf0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int TreeEvtControlWdmDeviceFileCreate(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  uint uVar4;
  undefined8 uVar5;
  longlong *plVar6;
  ushort uVar7;
  uint uVar8;
  undefined1 auStack_b8 [32];
  undefined8 local_98;
  longlong *local_90;
  longlong local_78;
  undefined4 local_70;
  undefined4 uStack_6c;
  short *psStack_68;
  longlong local_60;
  longlong local_58;
  longlong lStack_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_b8;
  uVar8 = 0;
  local_60 = 0;
  local_78 = 0;
  (**(code **)(WdfFunctions_01015 + 0x650))
            (WdfDriverGlobals,param_1,PTR__WDF_TREE_MASTER_DEVICE_CONTEXT_TYPE_INFO_14000f0f0);
  lVar1 = *(longlong *)(param_2 + 0xb8);
  lVar2 = *(longlong *)(lVar1 + 0x30);
  if ((*(short *)(lVar2 + 0x58) != 0) && (*(longlong *)(lVar2 + 0x60) != 0)) {
    local_70 = *(undefined4 *)(lVar2 + 0x58);
    uStack_6c = *(undefined4 *)(lVar2 + 0x5c);
    psStack_68 = *(short **)(lVar2 + 0x60);
    local_58 = 0;
    lStack_50 = 0;
    uVar7 = (ushort)local_70;
    if ((2 < uVar7) && (*psStack_68 == 0x5c)) {
      local_70._2_2_ = (short)((uint)local_70 >> 0x10);
      psStack_68 = psStack_68 + 1;
      local_70 = CONCAT22(local_70._2_2_ + -2,uVar7 - 2);
    }
    iVar3 = RtlGUIDFromString(&local_70,&local_58);
    if (-1 < iVar3) {
      uVar4 = (**(code **)(WdfFunctions_01015 + 0x70))(WdfDriverGlobals,TreeSecureServiceCollection)
      ;
      iVar3 = -0x3ffffddb;
      if (uVar4 != 0) {
        do {
          uVar5 = (**(code **)(WdfFunctions_01015 + 0x90))
                            (WdfDriverGlobals,TreeSecureServiceCollection,uVar8);
          plVar6 = (longlong *)
                   (**(code **)(WdfFunctions_01015 + 0x650))
                             (WdfDriverGlobals,uVar5,
                              PTR__WDF_TREE_SECURE_ENVIRONMENT_SERVICE_CONTEXT_TYPE_INFO_14000f168);
          if ((*(longlong *)((longlong)plVar6 + 0x14) == local_58) &&
             (*(longlong *)((longlong)plVar6 + 0x1c) == lStack_50)) {
            if ((plVar6[1] == 0) || (*plVar6 == 0)) {
              iVar3 = -0x3fffff5d;
            }
            else {
              local_90 = &local_78;
              local_98 = 0;
              iVar3 = (**(code **)(WdfFunctions_01015 + 0x290))
                                (WdfDriverGlobals,plVar6[1],0xb,0x200);
              if (iVar3 == 0) {
                uVar5 = (**(code **)(WdfFunctions_01015 + 0x610))
                                  (WdfDriverGlobals,local_78,&local_60);
                if (local_60 - 2U < 0xfffd) {
                  iVar3 = IoReplaceFileObjectName
                                    (*(undefined8 *)(lVar1 + 0x30),uVar5,(short)local_60 + -2);
                  if (-1 < iVar3) {
                    iVar3 = 0x104;
                  }
                }
                else {
                  iVar3 = -0x3fffffff;
                }
              }
            }
            break;
          }
          uVar8 = uVar8 + 1;
        } while (uVar8 < uVar4);
      }
      goto LAB_140001d60;
    }
  }
  iVar3 = 0;
LAB_140001d60:
  if (local_78 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
  if (iVar3 == 0) {
    *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
    *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
    iVar3 = (**(code **)(WdfFunctions_01015 + 0x110))(WdfDriverGlobals,param_1,param_2);
  }
  else {
    *(int *)(param_2 + 0x30) = iVar3;
    uVar5 = 2;
    if (iVar3 != 0x104) {
      uVar5 = 0;
    }
    *(undefined8 *)(param_2 + 0x38) = uVar5;
    IofCompleteRequest(param_2,0);
  }
  return iVar3;
}



===== TreeEvtCopyChildDeviceDescriptor @ 140001ee0 =====

undefined8
TreeEvtCopyChildDeviceDescriptor(undefined8 param_1,undefined8 *param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  
  uVar1 = param_2[1];
  *param_3 = *param_2;
  param_3[1] = uVar1;
  *(undefined4 *)(param_3 + 2) = *(undefined4 *)(param_2 + 2);
  return 0;
}



===== TreeEvtCreateChildDevicePdo @ 140001f00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong TreeEvtCreateChildDevicePdo(undefined8 param_1,longlong param_2,undefined8 param_3)

{
  uint uVar1;
  WDFDEVICE__ *pWVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  ulonglong uVar7;
  uint uVar8;
  uint uVar9;
  ulonglong uVar10;
  undefined1 auStack_268 [32];
  undefined1 *local_248;
  uint local_240;
  uint local_238;
  uint local_230;
  uint local_228;
  uint local_220;
  uint local_218;
  uint local_210;
  uint local_208;
  undefined1 local_1f8 [8];
  undefined8 local_1f0;
  undefined8 local_1e8;
  ushort local_1e0 [4];
  undefined1 *local_1d8;
  ushort local_1d0 [4];
  undefined1 *local_1c8;
  undefined8 local_1c0;
  undefined8 uStack_1b8;
  undefined8 local_1b0 [2];
  undefined4 local_1a0;
  undefined4 uStack_19c;
  undefined4 uStack_198;
  undefined4 uStack_194;
  undefined8 local_190;
  undefined8 uStack_188;
  undefined8 local_180;
  undefined8 uStack_178;
  undefined1 local_168 [80];
  undefined1 local_118 [208];
  ulonglong local_48;
  
  local_1c8 = local_168;
  local_48 = __security_cookie ^ (ulonglong)auStack_268;
  local_1d0[0] = 0;
  local_1d0[1] = 0x4c;
  local_1d0[2] = 0;
  local_1d0[3] = 0;
  local_1e0[0] = 0;
  local_1e0[1] = 200;
  local_1e0[2] = 0;
  local_1e0[3] = 0;
  local_1f8[0] = 0;
  local_1d8 = local_118;
  local_1e8 = 0;
  local_1a0 = 0;
  uStack_19c = 0;
  uStack_198 = 0;
  uStack_194 = 0;
  local_190 = 0;
  uStack_188 = 0;
  local_180 = 0;
  uStack_178 = 0;
  local_1c0 = 0;
  uStack_1b8 = 0;
  local_1f0 = param_3;
  pWVar2 = (WDFDEVICE__ *)(**(code **)(WdfFunctions_01015 + 8))(WdfDriverGlobals,param_1);
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,pWVar2,PTR__WDF_TREE_MASTER_DEVICE_CONTEXT_TYPE_INFO_14000f0f0
                    );
  uVar10 = (ulonglong)*(ushort *)(param_2 + 8);
  local_208 = (uint)*(byte *)(param_2 + 0x13);
  local_210 = (uint)*(byte *)(param_2 + 0x12);
  local_218 = (uint)*(byte *)(param_2 + 0x11);
  local_220 = (uint)*(byte *)(param_2 + 0x10);
  local_228 = (uint)*(byte *)(param_2 + 0xf);
  local_230 = (uint)*(byte *)(param_2 + 0xe);
  local_238 = (uint)*(byte *)(param_2 + 0xd);
  local_240 = (uint)*(byte *)(param_2 + 0xc);
  local_248 = (undefined1 *)CONCAT44(local_248._4_4_,(uint)*(ushort *)(param_2 + 10));
  uVar4 = RtlUnicodeStringPrintf
                    (local_1d0,L"{%08lx-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x}",
                     (ulonglong)*(uint *)(param_2 + 4),uVar10);
  uVar8 = 0;
  uVar7 = uVar4 & 0xffffffff;
  if (-1 < (int)uVar4) {
    uVar4 = RtlUnicodeStringPrintf
                      (local_1e0,L"{4E815EE1-20F8-41EF-8CFF-3C283F02D722}\\%wZ",local_1d0,uVar10);
    uVar7 = uVar4 & 0xffffffff;
    if (-1 < (int)uVar4) {
      uVar9 = (**(code **)(WdfFunctions_01015 + 0x6a0))(WdfDriverGlobals,local_1f0,local_1e0);
      uVar7 = (ulonglong)uVar9;
      if (-1 < (int)uVar9) {
        uVar9 = (**(code **)(WdfFunctions_01015 + 0x6b0))(WdfDriverGlobals,local_1f0,local_1e0);
        uVar7 = (ulonglong)uVar9;
        if (-1 < (int)uVar9) {
          uVar9 = (**(code **)(WdfFunctions_01015 + 0x6b8))
                            (WdfDriverGlobals,local_1f0,&DAT_14000d000);
          uVar7 = (ulonglong)uVar9;
          if (-1 < (int)uVar9) {
            local_248 = local_1f8;
            local_1f8[0] = 7;
            local_240 = 1;
            uVar9 = (**(code **)(WdfFunctions_01015 + 0x248))
                              (WdfDriverGlobals,local_1f0,TreeEvtIrpPreprocessQueryDevRelations,0x1b
                              );
            uVar7 = (ulonglong)uVar9;
            if (-1 < (int)uVar9) {
              (**(code **)(WdfFunctions_01015 + 0x1f8))(WdfDriverGlobals,local_1f0);
              uVar9 = (**(code **)(WdfFunctions_01015 + 600))
                                (WdfDriverGlobals,&local_1f0,0,&local_1e8);
              uVar7 = (ulonglong)uVar9;
              if (-1 < (int)uVar9) {
                uVar9 = (**(code **)(WdfFunctions_01015 + 0x70))
                                  (WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x10));
                puVar6 = (undefined8 *)0x0;
                if (uVar9 != 0) {
                  do {
                    uVar5 = (**(code **)(WdfFunctions_01015 + 0x90))
                                      (WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x10),uVar8);
                    puVar6 = (undefined8 *)
                             (**(code **)(WdfFunctions_01015 + 0x650))
                                       (WdfDriverGlobals,uVar5,
                                        PTR__WDF_TREE_SECURE_ENVIRONMENT_SERVICE_CONTEXT_TYPE_INFO_14000f168
                                       );
                    if ((*(longlong *)((longlong)puVar6 + 0x14) == *(longlong *)(param_2 + 4)) &&
                       (*(longlong *)((longlong)puVar6 + 0x1c) == *(longlong *)(param_2 + 0xc)))
                    break;
                    uVar8 = uVar8 + 1;
                  } while (uVar8 < uVar9);
                }
                *puVar6 = 0;
                puVar6[1] = local_1e8;
                uStack_19c = 2;
                uStack_198 = 0;
                local_190 = 0x200000002;
                uStack_188 = 2;
                local_180 = 0x200000002;
                uStack_178 = 0xffffffffffffffff;
                local_1a0 = 0x30;
                uStack_194 = 0;
                (**(code **)(WdfFunctions_01015 + 0x298))(WdfDriverGlobals,local_1e8,&local_1a0);
                uVar8 = *(uint *)(puVar6 + 6);
                uVar9 = 0;
                if (uVar8 != 0) {
                  while( true ) {
                    uVar1 = RtlStringFromGUID((longlong)puVar6 + (ulonglong)uVar9 * 0x18 + 0x3c,
                                              &local_1c0);
                    uVar7 = (ulonglong)uVar1;
                    if ((int)uVar1 < 0) break;
                    uVar5 = (**(code **)(WdfFunctions_01015 + 0xf8))(WdfDriverGlobals,local_1e8);
                    uVar1 = IoReserveDependency(uVar5,&local_1c0,2);
                    uVar7 = (ulonglong)uVar1;
                    if ((int)uVar1 < 0) break;
                    RtlFreeUnicodeString(&local_1c0);
                    uVar1 = TreeDriverServicesQuery
                                      (pWVar2,(_GUID *)((longlong)puVar6 +
                                                       (ulonglong)uVar9 * 0x18 + 0x3c),local_1b0);
                    uVar7 = 0;
                    if (uVar1 != 0xc000009d) {
                      uVar7 = (ulonglong)uVar1;
                    }
                    if (((int)uVar7 < 0) || (uVar9 = uVar9 + 1, uVar8 <= uVar9)) break;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  RtlFreeUnicodeString(&local_1c0);
  return uVar7;
}



===== TreeEvtDestroyDeviceObject @ 140002350 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TreeEvtDestroyDeviceObject(WDFDEVICE__ *param_1)

{
  undefined1 uVar1;
  uint uVar2;
  long lVar3;
  longlong lVar4;
  undefined *puVar5;
  uint uVar6;
  _TREE_MASTER_DEVICE_CONTEXT *local_res10;
  
  puVar5 = PTR__WDF_TREE_MASTER_DEVICE_CONTEXT_TYPE_INFO_14000f0f0;
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x70))(WdfDriverGlobals,*(undefined8 *)(lVar4 + 0x10));
  uVar6 = 0;
  if (uVar2 != 0) {
    do {
      puVar5 = (undefined *)
               (**(code **)(WdfFunctions_01015 + 0x90))
                         (WdfDriverGlobals,*(undefined8 *)(lVar4 + 0x10),uVar6);
      (**(code **)(WdfFunctions_01015 + 0x80))(WdfDriverGlobals,TreeSecureServiceCollection);
      uVar6 = uVar6 + 1;
    } while (uVar6 < uVar2);
  }
  local_res10 = (_TREE_MASTER_DEVICE_CONTEXT *)0x0;
  lVar3 = TreeCxGetDeviceContext(param_1,&local_res10);
  uVar1 = (undefined1)lVar3;
  if ((-1 < lVar3) && (uVar1 = 0, *(code **)(local_res10 + 0x40) != (code *)0x0)) {
    uVar1 = (**(code **)(local_res10 + 0x40))(param_1);
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar5,0x10,
                       &WPP_36fd475e9c0f3a4c5e3e805381d963da_Traceguids,(char)param_1,uVar1);
  }
  return;
}



===== TreeEvtDeviceCreateFile @ 140002490 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TreeEvtDeviceCreateFile
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined4 *puVar1;
  short *psVar2;
  short sVar3;
  undefined8 uVar4;
  
  (**(code **)(WdfFunctions_01015 + 0x650))
            (WdfDriverGlobals,param_3,PTR__WDF_TREE_MASTER_DEVICE_FILE_CONTEXT_TYPE_INFO_14000f140);
  puVar1 = (undefined4 *)(**(code **)(WdfFunctions_01015 + 0x448))(WdfDriverGlobals,param_3);
  uVar4 = 0;
  psVar2 = *(short **)(puVar1 + 2);
  sVar3 = (short)*puVar1;
  if (sVar3 != 0) {
    if (*psVar2 == 0x5c) {
      sVar3 = sVar3 + -2;
      psVar2 = psVar2 + 1;
    }
    if ((sVar3 != 0) && (psVar2 != (short *)0x0)) {
      uVar4 = 0xc000000e;
    }
  }
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,uVar4);
  return;
}



===== TreeEvtDeviceD0Entry @ 140002550 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

long TreeEvtDeviceD0Entry(WDFDEVICE__ *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  undefined1 *puVar5;
  undefined *puVar6;
  bool bVar7;
  _TREE_MASTER_DEVICE_CONTEXT *local_res18;
  undefined8 in_stack_ffffffffffffffd8;
  undefined4 uVar8;
  
  uVar8 = (undefined4)((ulonglong)in_stack_ffffffffffffffd8 >> 0x20);
  pcVar4 = (char *)(**(code **)(WdfFunctions_01015 + 0x650))
                             (WdfDriverGlobals,param_1,
                              PTR__WDF_TREE_MASTER_DEVICE_CONTEXT_TYPE_INFO_14000f0f0);
  uVar2 = *(uint *)(pcVar4 + 0x80);
  do {
    LOCK();
    uVar1 = *(uint *)(pcVar4 + 0x80);
    bVar7 = uVar2 == uVar1;
    if (bVar7) {
      *(uint *)(pcVar4 + 0x80) = uVar2 | 1;
    }
    else {
      uVar2 = uVar1;
    }
    UNLOCK();
  } while (!bVar7);
  if ((uVar2 != 0) ||
     (iVar3 = (**(code **)(WdfFunctions_01015 + 0xdb0))
                        (WdfDriverGlobals,param_1,0,0,CONCAT44(uVar8,0x5c1),
                         "onecore\\base\\basedrv\\tree\\treeclx\\driver\\treedrv.cxx"), -1 < iVar3))
  {
    if (param_2 < 4) {
      return 0;
    }
    puVar6 = PTR__WDF_TREE_DRIVER_SERVICES_CONTEXT_TYPE_INFO_14000f268;
    puVar5 = (undefined1 *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
    local_res18 = (_TREE_MASTER_DEVICE_CONTEXT *)0x0;
    *puVar5 = 1;
    iVar3 = TreeCxGetDeviceContext(param_1,&local_res18);
    if (-1 < iVar3) {
      if (*(code **)(local_res18 + 0x58) == (code *)0x0) {
        iVar3 = 0;
      }
      else {
        iVar3 = (**(code **)(local_res18 + 0x58))(param_1);
      }
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar6,0x13,
                         &WPP_36fd475e9c0f3a4c5e3e805381d963da_Traceguids,(char)param_1,(char)iVar3)
      ;
    }
    if (*pcVar4 == '\0') {
      *pcVar4 = '\x01';
      iVar3 = TreeConfigureSecureServices(param_1);
    }
  }
  return iVar3;
}



===== TreeEvtDeviceD0Exit @ 1400026d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

long TreeEvtDeviceD0Exit(WDFDEVICE__ *param_1)

{
  int iVar1;
  long lVar2;
  undefined1 *puVar3;
  undefined *puVar4;
  _TREE_MASTER_DEVICE_CONTEXT *local_res18 [2];
  
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x160))(WdfDriverGlobals,param_1);
  if (iVar1 < 4) {
    lVar2 = 0;
  }
  else {
    puVar4 = PTR__WDF_TREE_DRIVER_SERVICES_CONTEXT_TYPE_INFO_14000f268;
    puVar3 = (undefined1 *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
    local_res18[0] = (_TREE_MASTER_DEVICE_CONTEXT *)0x0;
    *puVar3 = 0;
    lVar2 = TreeCxGetDeviceContext(param_1,local_res18);
    if (-1 < lVar2) {
      if (*(code **)(local_res18[0] + 0x60) == (code *)0x0) {
        lVar2 = 0;
      }
      else {
        lVar2 = (**(code **)(local_res18[0] + 0x60))(param_1);
      }
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar4,0x14,
                         &WPP_36fd475e9c0f3a4c5e3e805381d963da_Traceguids,(char)param_1,(char)lVar2)
      ;
    }
  }
  return lVar2;
}



===== TreeEvtDeviceInternalIoControl @ 1400027c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TreeEvtDeviceInternalIoControl
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               int param_5)

{
  int iVar1;
  longlong lVar2;
  longlong *plVar3;
  undefined8 uVar4;
  
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x8a8))(WdfDriverGlobals);
  if (lVar2 == 0) {
    if (param_5 != 0x56000c) {
      iVar1 = -0x3fffff45;
      goto LAB_1400028c3;
    }
    uVar4 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
    lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,uVar4,
                       PTR__WDF_TREE_MASTER_DEVICE_CONTEXT_TYPE_INFO_14000f0f0);
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x8c8))
                      (WdfDriverGlobals,param_2,*(undefined8 *)(lVar2 + 0x28));
  }
  else {
    plVar3 = (longlong *)
             (**(code **)(WdfFunctions_01015 + 0x650))
                       (WdfDriverGlobals,lVar2,
                        PTR__WDF_TREE_MASTER_DEVICE_FILE_CONTEXT_TYPE_INFO_14000f140);
    if (*plVar3 == 0) {
      iVar1 = -0x3fffff45;
    }
    else {
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x8c8))(WdfDriverGlobals,param_2);
    }
  }
  if (-1 < iVar1) {
    return;
  }
LAB_1400028c3:
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar1);
  return;
}



===== TreeEvtDeviceIoControl @ 140002900 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void TreeEvtDeviceIoControl(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  WDFDEVICE__ *pWVar2;
  undefined1 auStack_a8 [40];
  WDFDEVICE__ *local_80;
  undefined4 local_78;
  long local_70;
  _TREE_MASTER_DEVICE_CONTEXT *local_68;
  code *local_60;
  WDFDEVICE__ *pWStack_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_a8;
  pWVar2 = (WDFDEVICE__ *)(**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
  local_68 = (_TREE_MASTER_DEVICE_CONTEXT *)0x0;
  local_50 = 0;
  local_28 = 0;
  uStack_40 = 0;
  local_48 = 0x28;
  local_60 = (code *)0x0;
  pWStack_58 = (WDFDEVICE__ *)0x0;
  local_38 = 0;
  uStack_30 = 0;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_48);
  local_70 = TreeCxGetDeviceContext(pWVar2,&local_68);
  if (-1 < local_70) {
    pcVar1 = *(code **)(local_68 + 0x70);
    if (pcVar1 == (code *)0x0) {
      local_70 = -0x3ffffff0;
      (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,0xc0000010);
    }
    else if (*(int *)(local_68 + 8) == 0) {
      (*pcVar1)(pWVar2,param_2);
      local_70 = 0x103;
    }
    else {
      local_60 = pcVar1;
      pWStack_58 = pWVar2;
      local_50 = param_2;
      local_70 = KeExpandKernelStackAndCallout
                           (TreeCxClientProcessOtherDeviceIoWorker,&local_60,
                            *(undefined4 *)(local_68 + 8));
    }
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    local_78 = (undefined4)uStack_30;
    local_80 = pWVar2;
    WPP_RECORDER_SF_qDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  return;
}



===== TreeEvtDevicePrepareHardware @ 140002a70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

long TreeEvtDevicePrepareHardware(WDFDEVICE__ *param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  undefined8 uVar2;
  _TREE_MASTER_DEVICE_CONTEXT *local_res20;
  
  local_res20 = (_TREE_MASTER_DEVICE_CONTEXT *)0x0;
  uVar2 = param_3;
  lVar1 = TreeCxGetDeviceContext(param_1,&local_res20);
  if (-1 < lVar1) {
    if (*(code **)(local_res20 + 0x48) == (code *)0x0) {
      lVar1 = 0;
    }
    else {
      lVar1 = (**(code **)(local_res20 + 0x48))(param_1,param_2);
      uVar2 = param_3;
    }
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar2,0x11,
                       &WPP_36fd475e9c0f3a4c5e3e805381d963da_Traceguids,(char)param_1,(char)lVar1);
  }
  return lVar1;
}



===== TreeEvtDeviceReleaseHardware @ 140002b20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

long TreeEvtDeviceReleaseHardware(WDFDEVICE__ *param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  _TREE_MASTER_DEVICE_CONTEXT *local_res18 [2];
  
  local_res18[0] = (_TREE_MASTER_DEVICE_CONTEXT *)0x0;
  lVar1 = TreeCxGetDeviceContext(param_1,local_res18);
  if (-1 < lVar1) {
    if (*(code **)(local_res18[0] + 0x50) == (code *)0x0) {
      lVar1 = 0;
    }
    else {
      lVar1 = (**(code **)(local_res18[0] + 0x50))(param_1,param_2);
    }
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,param_3,0x12,
                       &WPP_36fd475e9c0f3a4c5e3e805381d963da_Traceguids,(char)param_1,(char)lVar1);
  }
  return lVar1;
}



===== TreeEvtDeviceRequestSerialization @ 140002bc0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void TreeEvtDeviceRequestSerialization(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  longlong lVar2;
  undefined1 auStack_58 [32];
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_58;
  local_18 = 0;
  uStack_30 = 0;
  local_38 = 0x28;
  local_28 = 0;
  uStack_20 = 0;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_38);
  uVar1 = uStack_30;
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uStack_30,
                     PTR__WDF_TREE_SECURE_SERVICES_REQUEST_CONTEXT_TYPE_INFO_14000f0a0);
  *(undefined8 *)(lVar2 + 0x58) = param_2;
  TreeSecureServicesSessionQueueExecute(uVar1);
  return;
}



===== TreeEvtDriverUnload @ 140002c70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TreeEvtDriverUnload(undefined8 param_1)

{
  undefined8 uVar1;
  
  (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,TreeSecureServiceCollection);
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x3b0))(WdfDriverGlobals,param_1);
  WppCleanupKm(uVar1);
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



===== TreeEvtIrpPreprocessQueryDevRelations @ 140002d20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong TreeEvtIrpPreprocessQueryDevRelations(undefined8 param_1,longlong param_2)

{
  int iVar1;
  uint uVar2;
  ulonglong uVar3;
  longlong lVar4;
  undefined8 uVar5;
  longlong lVar6;
  uint *puVar7;
  uint uVar8;
  uint *puVar9;
  uint uVar10;
  undefined1 auStack_88 [32];
  undefined8 local_68;
  undefined8 local_60;
  undefined4 local_58;
  longlong local_54;
  longlong lStack_4c;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_88;
  local_68 = 0;
  local_54 = 0;
  lStack_4c = 0;
  if (*(int *)(*(longlong *)(param_2 + 0xb8) + 8) != 2) {
    *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
    *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
    goto LAB_140002d73;
  }
  if (*(int *)(param_2 + 0x30) < 0) {
    puVar9 = (uint *)0x0;
  }
  else {
    puVar9 = *(uint **)(param_2 + 0x38);
  }
  local_58 = 0x14;
  puVar7 = (uint *)0x0;
  lVar6 = 0;
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x6f0))(WdfDriverGlobals,param_1,&local_58);
  if (-1 < (int)uVar2) {
    local_60 = (**(code **)(WdfFunctions_01015 + 0x6e8))(WdfDriverGlobals,param_1);
    lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,local_60,
                       PTR__WDF_TREE_MASTER_DEVICE_CONTEXT_TYPE_INFO_14000f0f0);
    uVar2 = (**(code **)(WdfFunctions_01015 + 0x70))(WdfDriverGlobals,*(undefined8 *)(lVar4 + 0x10))
    ;
    uVar8 = 0;
    if (uVar2 != 0) {
      do {
        uVar5 = (**(code **)(WdfFunctions_01015 + 0x90))
                          (WdfDriverGlobals,*(undefined8 *)(lVar4 + 0x10),uVar8);
        lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))
                          (WdfDriverGlobals,uVar5,
                           PTR__WDF_TREE_SECURE_ENVIRONMENT_SERVICE_CONTEXT_TYPE_INFO_14000f168);
        if ((local_54 == *(longlong *)(lVar6 + 0x14)) && (lStack_4c == *(longlong *)(lVar6 + 0x1c)))
        break;
        uVar8 = uVar8 + 1;
      } while (uVar8 < uVar2);
    }
    uVar8 = *(uint *)(lVar6 + 0x30);
    if (uVar8 != 0) {
      if (puVar9 == (uint *)0x0) {
        uVar10 = 0;
        uVar2 = uVar8;
      }
      else {
        uVar10 = *puVar9;
        uVar2 = uVar10 + uVar8;
      }
      puVar7 = (uint *)ExAllocatePool2(0x100,(ulonglong)(uVar2 - 1) * 8 + 0x10,0x45457254);
      if (puVar7 == (uint *)0x0) {
        uVar2 = 0xc000009a;
        goto LAB_140002f7f;
      }
      *puVar7 = uVar2;
      if (puVar9 != (uint *)0x0) {
        memcpy(puVar7 + 2,puVar9 + 2,(ulonglong)*puVar9 << 3);
      }
      uVar3 = 0;
      if (uVar8 != 0) {
        do {
          uVar2 = TreeDriverServicesGetServicePdo
                            (local_60,(_GUID *)(uVar3 * 0x18 + 0x3c + lVar6),&local_68);
          if ((int)uVar2 < 0) goto LAB_140002f7f;
          iVar1 = (int)uVar3;
          uVar2 = iVar1 + 1;
          uVar3 = (ulonglong)uVar2;
          *(undefined8 *)(puVar7 + (ulonglong)(uVar10 + iVar1) * 2 + 2) = local_68;
        } while (uVar2 < uVar8);
        uVar2 = 0;
        do {
          ObfReferenceObject(*(undefined8 *)(puVar7 + (ulonglong)(uVar10 + uVar2) * 2 + 2));
          uVar2 = uVar2 + 1;
        } while (uVar2 < uVar8);
      }
      *(uint **)(param_2 + 0x38) = puVar7;
    }
    uVar2 = 0;
  }
LAB_140002f7f:
  if (*(uint **)(param_2 + 0x38) != puVar7) {
    ExFreePoolWithTag(puVar7,0);
  }
  *(uint *)(param_2 + 0x30) = uVar2;
  if ((int)uVar2 < 0) {
    IofCompleteRequest(param_2,0);
    return (ulonglong)uVar2;
  }
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
LAB_140002d73:
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x110))(WdfDriverGlobals,param_1,param_2);
  return uVar3;
}



===== TreeRPMBPnpNotification @ 140002ff0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 TreeRPMBPnpNotification(longlong param_1,undefined8 param_2)

{
  int iVar1;
  
  if ((*(longlong *)(param_1 + 4) == 0x11d046f0cb3a4004) &&
     (*(longlong *)(param_1 + 0xc) == 0x3f05139760008fb0)) {
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x268))
                      (WdfDriverGlobals,param_2,&GUID_TREE_RPMB_SERVICE,0);
    if (-1 < iVar1) {
      (**(code **)(WdfFunctions_01015 + 0x270))
                (WdfDriverGlobals,param_2,&GUID_TREE_RPMB_SERVICE,0,1);
    }
  }
  return 0;
}



===== TreeReportNewSecureServiceDevice @ 140003078 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
TreeReportNewSecureServiceDevice(undefined8 param_1,undefined8 *param_2,longlong *param_3)

{
  uint uVar1;
  undefined8 uVar2;
  longlong lVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  uint uVar7;
  
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x108))(WdfDriverGlobals,param_1);
  lVar3 = (**(code **)(WdfFunctions_01015 + 0xf0))(WdfDriverGlobals,uVar2);
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x6e8))(WdfDriverGlobals,lVar3);
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar2,PTR__WDF_TREE_MASTER_DEVICE_CONTEXT_TYPE_INFO_14000f0f0)
  ;
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x70))(WdfDriverGlobals,*(undefined8 *)(lVar4 + 0x10));
  uVar7 = 0;
  if (uVar1 != 0) {
    do {
      uVar5 = (**(code **)(WdfFunctions_01015 + 0x90))
                        (WdfDriverGlobals,*(undefined8 *)(lVar4 + 0x10),uVar7);
      puVar6 = (undefined8 *)
               (**(code **)(WdfFunctions_01015 + 0x650))
                         (WdfDriverGlobals,uVar5,
                          PTR__WDF_TREE_SECURE_ENVIRONMENT_SERVICE_CONTEXT_TYPE_INFO_14000f168);
      if (puVar6[1] == lVar3) {
        *puVar6 = param_1;
        *param_2 = uVar2;
        *param_3 = (longlong)(puVar6 + 2);
        return 0;
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < uVar1);
  }
  return 0xc0000225;
}



===== TreeServicesCompleteSessionCall @ 1400031dc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TreeServicesCompleteSessionCall
               (undefined8 param_1,undefined8 param_2,uint param_3,undefined8 param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  undefined8 *puVar5;
  bool bVar6;
  undefined8 local_res20;
  undefined8 local_68;
  code *pcStack_60;
  undefined8 local_58;
  undefined4 local_50;
  undefined8 local_4c;
  undefined8 uStack_44;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_30;
  undefined8 local_28;
  undefined *local_20;
  
  local_res20 = 0;
  puVar4 = (uint *)(**(code **)(WdfFunctions_01015 + 0x650))
                             (WdfDriverGlobals,param_2,
                              PTR__WDF_TREE_SESSION_CALL_DATA_TYPE_INFO_14000f0c8);
  puVar4[1] = param_3;
  *(undefined8 *)(puVar4 + 2) = param_4;
  uVar2 = *puVar4;
  do {
    LOCK();
    uVar1 = *puVar4;
    bVar6 = uVar2 == uVar1;
    if (bVar6) {
      *puVar4 = uVar2 | 2;
    }
    else {
      uVar2 = uVar1;
    }
    UNLOCK();
  } while (!bVar6);
  if (((uVar2 & 1) != 0) && (*(longlong *)(puVar4 + 0x10) != 0)) {
    local_3c = 0;
    local_28 = 0;
    local_38 = 1;
    local_34 = 1;
    pcStack_60 = TreeEvtCompleteSessionCallWorkItem;
    local_20 = PTR__WDF_TREE_SESSION_COMPLETION_WORKITEM_TYPE_INFO_14000f190;
    local_68 = 0x18;
    local_58 = 0;
    local_4c = 0;
    uStack_44 = 0;
    local_50 = 0x38;
    local_30 = param_1;
    iVar3 = (**(code **)(WdfFunctions_01015 + 0xbd8))
                      (WdfDriverGlobals,&local_68,&local_50,&local_res20);
    if (iVar3 < 0) {
      (**(code **)(puVar4 + 0x10))(param_2);
    }
    else {
      puVar5 = (undefined8 *)
               (**(code **)(WdfFunctions_01015 + 0x650))
                         (WdfDriverGlobals,local_res20,
                          PTR__WDF_TREE_SESSION_COMPLETION_WORKITEM_TYPE_INFO_14000f190);
      (**(code **)(WdfFunctions_01015 + 0x668))
                (WdfDriverGlobals,param_2,0,0x468,
                 "onecore\\base\\basedrv\\tree\\treeclx\\driver\\treedrv.cxx");
      *puVar5 = param_2;
      (**(code **)(WdfFunctions_01015 + 0xbe0))(WdfDriverGlobals,local_res20);
    }
  }
  return;
}



===== TreeServicesEvtAsyncSessionCallComplete @ 140003390 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TreeServicesEvtAsyncSessionCallComplete(undefined8 param_1)

{
  longlong lVar1;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_TREE_SESSION_CALL_DATA_TYPE_INFO_14000f0c8);
  KeSetEvent(*(undefined8 *)(lVar1 + 0x48),0,0);
  return;
}



===== WPP_RECORDER_SF_ @ 1400033dc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                     undefined8 param_5)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,param_5,param_4,0);
  }
  WppAutoLogTrace(param_1,4,1,param_5,param_4,0);
  return;
}



===== WPP_RECORDER_SF_D @ 140003460 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_D(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                      undefined8 param_5,undefined1 param_6)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,param_5,param_4,&param_6,4,0);
  }
  WppAutoLogTrace(param_1,2,1,param_5,param_4,&param_6,4,0);
  return;
}



===== WPP_RECORDER_SF__guid_ @ 140003508 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF__guid_
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,undefined8 param_6)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,param_5,param_4,param_6,0x10,0);
  }
  WppAutoLogTrace(param_1,4,1,param_5,param_4,param_6,0x10,0);
  return;
}



===== WPP_RECORDER_SF__guid__guid_ @ 1400035b4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF__guid__guid_
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,undefined8 param_6,undefined8 param_7)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_49bb3939113c3b574f8f0bbeefc4fba7_Traceguids,param_4,param_6,0x10,param_7,0x10,0)
    ;
  }
  WppAutoLogTrace(param_1,4,1,&WPP_49bb3939113c3b574f8f0bbeefc4fba7_Traceguids,param_4,param_6,0x10,
                  param_7,0x10,0);
  return;
}



===== WPP_RECORDER_SF__guid_d @ 140003694 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF__guid_d(undefined8 param_1)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_49bb3939113c3b574f8f0bbeefc4fba7_Traceguids,0xf);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_49bb3939113c3b574f8f0bbeefc4fba7_Traceguids,0xf);
  return;
}



===== WPP_RECORDER_SF_d @ 140003770 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_d(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                      undefined8 param_5,undefined1 param_6)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (2 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_49bb3939113c3b574f8f0bbeefc4fba7_Traceguids,param_4,&param_6,4,0);
  }
  WppAutoLogTrace(param_1,3,1,&WPP_49bb3939113c3b574f8f0bbeefc4fba7_Traceguids,param_4,&param_6,4,0)
  ;
  return;
}



===== WPP_RECORDER_SF_dD @ 14000381c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_dD(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_49bb3939113c3b574f8f0bbeefc4fba7_Traceguids,0x13,&uStack0000000000000030,4,
               &uStack0000000000000038,4,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_49bb3939113c3b574f8f0bbeefc4fba7_Traceguids,0x13,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,0);
  return;
}



===== WPP_RECORDER_SF_qD @ 1400038ec =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qD(undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,param_5,param_4,&param_6,8,&param_7,4
               ,0);
  }
  WppAutoLogTrace(param_1,param_2,1,param_5,param_4,&param_6,8,&param_7,4,0);
  return;
}



===== WppClassicProviderCallback @ 1400039d0 =====

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



===== wil_details_RecordCachedUsage @ 140003a2c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_RecordCachedUsage(undefined4 param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  bool bVar6;
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
    bVar6 = uVar2 == uVar4;
    if (bVar6) {
      *param_2 = uVar2 & 0xffc0401e;
    }
    else {
      uVar2 = uVar4;
    }
    UNLOCK();
  } while (!bVar6);
  uVar3 = uVar2 >> 1 & 0xf;
  uVar4 = 0;
  if (uVar3 != 0) {
    uVar4 = param_2[1];
    do {
      LOCK();
      uVar1 = param_2[1];
      bVar6 = uVar4 == uVar1;
      if (bVar6) {
        param_2[1] = uVar4 | uVar3;
      }
      else {
        uVar4 = uVar1;
      }
      UNLOCK();
    } while (!bVar6);
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
  if (0 < (longlong)puVar5 - (longlong)&local_48 >> 3) {
    wil_details_RecordFeatureUsageCallback();
  }
  return;
}



===== wil_details_RecordFeatureUsageReporting @ 140003b80 =====

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



===== TreeClassLibraryBindClient @ 140003c10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl TreeClassLibraryBindClient(struct _WDF_CLASS_BIND_INFO * __ptr64,void * __ptr64 *
   __ptr64) */

long __cdecl TreeClassLibraryBindClient(_WDF_CLASS_BIND_INFO *param_1,void **param_2)

{
  undefined8 *puVar1;
  undefined *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined8 local_res8;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined *local_18;
  
  puVar2 = PTR_TreeSecureDeviceHandoffServiceDeviceControl_14000f008;
  local_res8 = 0;
  iVar6 = -0x3ffffff3;
  if (((*(int *)(param_1 + 0x10) == 1) && (*(int *)(param_1 + 0x14) == 0)) &&
     (*(int *)(param_1 + 0x28) == 6)) {
    puVar1 = *(undefined8 **)(param_1 + 0x20);
    *puVar1 = TreeSecureEnvironmentCxFunctionTableV1;
    puVar1[1] = puVar2;
    puVar2 = PTR_TreeSecureDeviceQueryOSService_14000f018;
    puVar1[2] = PTR_TreeSecureDeviceLogMessage_14000f010;
    puVar1[3] = puVar2;
    uVar5 = PTR_TreeSecureDeviceCompleteAsyncRequest_14000f028._4_4_;
    uVar4 = PTR_TreeSecureDeviceCompleteAsyncRequest_14000f028._0_4_;
    uVar3 = PTR_TreeSecureDeviceCallOSService_14000f020._4_4_;
    *(undefined4 *)(puVar1 + 4) = PTR_TreeSecureDeviceCallOSService_14000f020._0_4_;
    *(undefined4 *)((longlong)puVar1 + 0x24) = uVar3;
    *(undefined4 *)(puVar1 + 5) = uVar4;
    *(undefined4 *)((longlong)puVar1 + 0x2c) = uVar5;
    local_38 = 0;
    uStack_30 = 0x100000001;
    local_18 = PTR__WDF_TREE_CX_BIND_CONTEXT_TYPE_INFO_14000f1c8;
    uStack_40 = 0;
    local_48 = 0x38;
    local_28 = 0;
    uStack_20 = 0;
    iVar6 = (**(code **)(WdfFunctions_01015 + 0x678))(WdfDriverGlobals,&local_48,&local_res8);
    if (-1 < iVar6) {
      puVar7 = (undefined4 *)
               (**(code **)(WdfFunctions_01015 + 0x650))
                         (WdfDriverGlobals,local_res8,
                          PTR__WDF_TREE_CX_BIND_CONTEXT_TYPE_INFO_14000f1c8);
      *puVar7 = *(undefined4 *)(param_1 + 0x10);
      puVar7[1] = *(undefined4 *)(param_1 + 0x14);
      **(undefined8 **)(param_1 + 0x30) = local_res8;
    }
  }
  return iVar6;
}



===== TreeClassLibraryDeinitialize @ 140003d20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl TreeClassLibraryDeinitialize(void) */

void __cdecl TreeClassLibraryDeinitialize(void)

{
  (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,TreeControlDevice);
  return;
}



===== TreeClassLibraryInitialize @ 140003d60 =====

/* long __cdecl TreeClassLibraryInitialize(void) */

long __cdecl TreeClassLibraryInitialize(void)

{
  return 0;
}



===== TreeClassLibraryUnbindClient @ 140003d70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl TreeClassLibraryUnbindClient(struct _WDF_CLASS_BIND_INFO * __ptr64,void * __ptr64 *
   __ptr64) */

void __cdecl TreeClassLibraryUnbindClient(_WDF_CLASS_BIND_INFO *param_1,void **param_2)

{
  longlong *plVar1;
  
  plVar1 = *(longlong **)(param_1 + 0x30);
  if (*plVar1 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
    *plVar1 = 0;
  }
  return;
}



===== TreeCxClientProcessOtherDeviceIoWorker @ 140003db0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl TreeCxClientProcessOtherDeviceIoWorker(void * __ptr64) */

void __cdecl TreeCxClientProcessOtherDeviceIoWorker(void *param_1)

{
  (**(code **)param_1)
            (*(undefined8 *)((longlong)param_1 + 8),*(undefined8 *)((longlong)param_1 + 0x10));
  return;
}



===== TreeCxClientProcessOtherSecureServiceIoWorker @ 140003dd0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl TreeCxClientProcessOtherSecureServiceIoWorker(void * __ptr64) */

void __cdecl TreeCxClientProcessOtherSecureServiceIoWorker(void *param_1)

{
  (**(code **)param_1)
            (*(undefined8 *)((longlong)param_1 + 8),*(undefined8 *)((longlong)param_1 + 0x10),
             *(undefined8 *)((longlong)param_1 + 0x18));
  return;
}



===== TreeCxClientProcessSecureServiceRequestWorker @ 140003e00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl TreeCxClientProcessSecureServiceRequestWorker(void * __ptr64) */

void __cdecl TreeCxClientProcessSecureServiceRequestWorker(void *param_1)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)param_1)
                    (*(undefined8 *)((longlong)param_1 + 8),
                     *(undefined8 *)((longlong)param_1 + 0x10),
                     *(undefined8 *)((longlong)param_1 + 0x18),
                     *(undefined4 *)((longlong)param_1 + 0x20),
                     *(undefined8 *)((longlong)param_1 + 0x28),
                     *(undefined4 *)((longlong)param_1 + 0x30),
                     *(undefined8 *)((longlong)param_1 + 0x38),
                     *(undefined8 *)((longlong)param_1 + 0x40));
  *(undefined4 *)((longlong)param_1 + 0x48) = uVar1;
  return;
}



===== TreeCxGetDeviceContext @ 140003e54 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl TreeCxGetDeviceContext(struct WDFDEVICE__ * __ptr64,struct
   _TREE_MASTER_DEVICE_CONTEXT * __ptr64 * __ptr64) */

long __cdecl TreeCxGetDeviceContext(WDFDEVICE__ *param_1,_TREE_MASTER_DEVICE_CONTEXT **param_2)

{
  longlong lVar1;
  _TREE_MASTER_DEVICE_CONTEXT *p_Var2;
  long lVar3;
  
  lVar1 = WdfFunctions_01015;
  *param_2 = (_TREE_MASTER_DEVICE_CONTEXT *)0x0;
  lVar3 = -0x3ffffff3;
  p_Var2 = (_TREE_MASTER_DEVICE_CONTEXT *)
           (**(code **)(lVar1 + 0x650))
                     (WdfDriverGlobals,param_1,
                      PTR__WDF_TREE_MASTER_DEVICE_CONTEXT_TYPE_INFO_14000f0f0);
  if (p_Var2 != (_TREE_MASTER_DEVICE_CONTEXT *)0x0) {
    *param_2 = p_Var2;
    lVar3 = 0;
  }
  return lVar3;
}



===== TreeCxGetServiceContext @ 140003eac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl TreeCxGetServiceContext(struct WDFDEVICE__ * __ptr64,struct
   _TREE_SERVICE_DEVICE_CONTEXT * __ptr64 * __ptr64,struct _TREE_MASTER_DEVICE_CONTEXT * __ptr64 *
   __ptr64) */

long __cdecl
TreeCxGetServiceContext
          (WDFDEVICE__ *param_1,_TREE_SERVICE_DEVICE_CONTEXT **param_2,
          _TREE_MASTER_DEVICE_CONTEXT **param_3)

{
  _TREE_MASTER_DEVICE_CONTEXT *p_Var1;
  _TREE_SERVICE_DEVICE_CONTEXT *p_Var2;
  long lVar3;
  
  *param_2 = (_TREE_SERVICE_DEVICE_CONTEXT *)0x0;
  lVar3 = -0x3ffffff3;
  if (param_3 != (_TREE_MASTER_DEVICE_CONTEXT **)0x0) {
    *param_3 = (_TREE_MASTER_DEVICE_CONTEXT *)0x0;
  }
  p_Var2 = (_TREE_SERVICE_DEVICE_CONTEXT *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,
                      PTR__WDF_TREE_SERVICE_DEVICE_CONTEXT_TYPE_INFO_14000f078);
  if ((p_Var2 != (_TREE_SERVICE_DEVICE_CONTEXT *)0x0) &&
     (p_Var1 = *(_TREE_MASTER_DEVICE_CONTEXT **)(p_Var2 + 0x68),
     p_Var1 != (_TREE_MASTER_DEVICE_CONTEXT *)0x0)) {
    *param_2 = p_Var2;
    if (param_3 != (_TREE_MASTER_DEVICE_CONTEXT **)0x0) {
      *param_3 = p_Var1;
    }
    lVar3 = 0;
  }
  return lVar3;
}



===== TreeCxGetSessionContext @ 140003f2c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl TreeCxGetSessionContext(struct WDFFILEOBJECT__ * __ptr64,struct
   _TREE_SERVICE_SESSION_CONTEXT * __ptr64 * __ptr64,struct _TREE_SERVICE_DEVICE_CONTEXT * __ptr64 *
   __ptr64,struct _TREE_MASTER_DEVICE_CONTEXT * __ptr64 * __ptr64) */

long __cdecl
TreeCxGetSessionContext
          (WDFFILEOBJECT__ *param_1,_TREE_SERVICE_SESSION_CONTEXT **param_2,
          _TREE_SERVICE_DEVICE_CONTEXT **param_3,_TREE_MASTER_DEVICE_CONTEXT **param_4)

{
  _TREE_SERVICE_DEVICE_CONTEXT *p_Var1;
  _TREE_MASTER_DEVICE_CONTEXT *p_Var2;
  _TREE_SERVICE_SESSION_CONTEXT *p_Var3;
  long lVar4;
  
  lVar4 = -0x3ffffff3;
  if (param_3 != (_TREE_SERVICE_DEVICE_CONTEXT **)0x0) {
    *param_3 = (_TREE_SERVICE_DEVICE_CONTEXT *)0x0;
  }
  if (param_4 != (_TREE_MASTER_DEVICE_CONTEXT **)0x0) {
    *param_4 = (_TREE_MASTER_DEVICE_CONTEXT *)0x0;
  }
  *param_2 = (_TREE_SERVICE_SESSION_CONTEXT *)0x0;
  if (param_1 != (WDFFILEOBJECT__ *)0x0) {
    p_Var3 = (_TREE_SERVICE_SESSION_CONTEXT *)
             (**(code **)(WdfFunctions_01015 + 0x650))
                       (WdfDriverGlobals,param_1,
                        PTR__WDF_TREE_SERVICE_SESSION_CONTEXT_TYPE_INFO_14000f118);
    if (((p_Var3 != (_TREE_SERVICE_SESSION_CONTEXT *)0x0) &&
        (p_Var1 = *(_TREE_SERVICE_DEVICE_CONTEXT **)p_Var3,
        p_Var1 != (_TREE_SERVICE_DEVICE_CONTEXT *)0x0)) &&
       (p_Var2 = *(_TREE_MASTER_DEVICE_CONTEXT **)(p_Var1 + 0x68),
       p_Var2 != (_TREE_MASTER_DEVICE_CONTEXT *)0x0)) {
      *param_2 = p_Var3;
      if (param_3 != (_TREE_SERVICE_DEVICE_CONTEXT **)0x0) {
        *param_3 = p_Var1;
      }
      if (param_4 != (_TREE_MASTER_DEVICE_CONTEXT **)0x0) {
        *param_4 = p_Var2;
      }
      lVar4 = 0;
    }
  }
  return lVar4;
}



===== TreeSecureDeviceCallOSService @ 140003fe0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl TreeSecureDeviceCallOSService(void * __ptr64,struct WDFDEVICE__ * __ptr64,struct
   _GUID const * __ptr64,struct _TR_SERVICE_REQUEST_V1 * __ptr64,unsigned __int64 * __ptr64) */

long __cdecl
TreeSecureDeviceCallOSService
          (void *param_1,WDFDEVICE__ *param_2,_GUID *param_3,_TR_SERVICE_REQUEST_V1 *param_4,
          __uint64 *param_5)

{
  long extraout_EAX;
  longlong lVar1;
  WDFDEVICE__ *pWVar2;
  undefined *puVar3;
  
  pWVar2 = param_2;
  puVar3 = PTR__WDF_TREE_SERVICE_DEVICE_CONTEXT_TYPE_INFO_14000f078;
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
  if ((*(longlong *)param_3 == 0x4497ad1a05272f96) &&
     (*(longlong *)(param_3 + 8) == -0x4c684e9a46e93d69)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF__guid_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pWVar2,puVar3,0xe,
                 &WPP_36fd475e9c0f3a4c5e3e805381d963da_Traceguids,lVar1 + 0x58);
    }
    param_3 = (_GUID *)&GUID_DEVINTERFACE_EMMC_PARTITION_ACCESS_RPMB;
  }
  TreeSecureServicesCallOSService(param_2,param_3,(undefined8 *)param_4,param_5);
  return extraout_EAX;
}



===== TreeSecureDeviceCompleteAsyncRequest @ 1400040a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl TreeSecureDeviceCompleteAsyncRequest(void * __ptr64,void * __ptr64,long,unsigned
   __int64) */

long __cdecl
TreeSecureDeviceCompleteAsyncRequest(void *param_1,void *param_2,long param_3,__uint64 param_4)

{
  longlong lVar1;
  undefined4 *puVar2;
  undefined4 *local_res20;
  undefined8 local_28 [2];
  
  local_res20 = (undefined4 *)0x0;
  local_28[0] = 0;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qDP(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,param_2,0x10,&local_res20,local_28);
  puVar2 = local_res20;
  for (lVar1 = 0x10; lVar1 != 0; lVar1 = lVar1 + -1) {
    *(undefined1 *)puVar2 = 0;
    puVar2 = (undefined4 *)((longlong)puVar2 + 1);
  }
  *(__uint64 *)(local_res20 + 2) = param_4;
  *local_res20 = 1;
  TreeSecureSessionCompleteRequest(param_2,param_3,0x10);
  return 0;
}



===== TreeSecureDeviceHandoffMasterDeviceControl @ 140004180 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl TreeSecureDeviceHandoffMasterDeviceControl(void * __ptr64,struct WDFDEVICE_INIT *
   __ptr64,struct _TR_SECURE_DEVICE_CALLBACKS_V1 * __ptr64,struct WDFDEVICE__ * __ptr64 * __ptr64)
    */

long __cdecl
TreeSecureDeviceHandoffMasterDeviceControl
          (void *param_1,WDFDEVICE_INIT *param_2,_TR_SECURE_DEVICE_CALLBACKS_V1 *param_3,
          WDFDEVICE__ **param_4)

{
  undefined8 uVar1;
  _TREE_MASTER_DEVICE_CONTEXT *p_Var2;
  int iVar3;
  int *piVar4;
  longlong lVar5;
  _TREE_MASTER_DEVICE_CONTEXT **pp_Var6;
  _TREE_MASTER_DEVICE_CONTEXT *local_res18;
  undefined1 uVar7;
  
  piVar4 = (int *)(**(code **)(WdfFunctions_01015 + 0x650))
                            (WdfDriverGlobals,param_1,
                             PTR__WDF_TREE_CX_BIND_CONTEXT_TYPE_INFO_14000f1c8);
  pp_Var6 = &local_res18;
  local_res18 = (_TREE_MASTER_DEVICE_CONTEXT *)0x0;
  iVar3 = TreeAddMasterDevice(param_2,*(uint *)param_3,pp_Var6);
  p_Var2 = local_res18;
  uVar7 = SUB81(local_res18,0);
  if (-1 < iVar3) {
    pp_Var6 = (_TREE_MASTER_DEVICE_CONTEXT **)
              PTR__WDF_TREE_MASTER_DEVICE_CONTEXT_TYPE_INFO_14000f0f0;
    lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,local_res18);
    *(void **)(lVar5 + 0x18) = param_1;
    if (*piVar4 == 1) {
      uVar1 = *(undefined8 *)(param_3 + 8);
      *(undefined8 *)(lVar5 + 0x30) = *(undefined8 *)param_3;
      *(undefined8 *)(lVar5 + 0x38) = uVar1;
      uVar1 = *(undefined8 *)(param_3 + 0x18);
      *(undefined8 *)(lVar5 + 0x40) = *(undefined8 *)(param_3 + 0x10);
      *(undefined8 *)(lVar5 + 0x48) = uVar1;
      uVar1 = *(undefined8 *)(param_3 + 0x28);
      *(undefined8 *)(lVar5 + 0x50) = *(undefined8 *)(param_3 + 0x20);
      *(undefined8 *)(lVar5 + 0x58) = uVar1;
      uVar1 = *(undefined8 *)(param_3 + 0x38);
      *(undefined8 *)(lVar5 + 0x60) = *(undefined8 *)(param_3 + 0x30);
      *(undefined8 *)(lVar5 + 0x68) = uVar1;
      uVar1 = *(undefined8 *)(param_3 + 0x48);
      *(undefined8 *)(lVar5 + 0x70) = *(undefined8 *)(param_3 + 0x40);
      *(undefined8 *)(lVar5 + 0x78) = uVar1;
    }
    if (param_4 != (WDFDEVICE__ **)0x0) {
      *param_4 = (WDFDEVICE__ *)p_Var2;
    }
    local_res18 = (_TREE_MASTER_DEVICE_CONTEXT *)0x0;
    iVar3 = TreeCxGetDeviceContext((WDFDEVICE__ *)p_Var2,&local_res18);
    if (-1 < iVar3) {
      if (*(code **)(local_res18 + 0x38) == (code *)0x0) {
        iVar3 = 0;
      }
      else {
        iVar3 = (**(code **)(local_res18 + 0x38))(p_Var2);
      }
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,pp_Var6,0xf,
                         &WPP_36fd475e9c0f3a4c5e3e805381d963da_Traceguids,uVar7,(char)iVar3);
    }
    if (-1 < iVar3) {
      iVar3 = 0;
    }
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,pp_Var6,10,
                       &WPP_36fd475e9c0f3a4c5e3e805381d963da_Traceguids,uVar7,(char)iVar3);
  }
  return iVar3;
}



===== TreeSecureDeviceHandoffServiceDeviceControl @ 140004340 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl TreeSecureDeviceHandoffServiceDeviceControl(void * __ptr64,struct WDFDEVICE_INIT *
   __ptr64,struct _GUID * __ptr64,struct _TR_SECURE_SERVICE_CALLBACKS_V1 * __ptr64,struct
   WDFDEVICE__ * __ptr64 * __ptr64) */

long __cdecl
TreeSecureDeviceHandoffServiceDeviceControl
          (void *param_1,WDFDEVICE_INIT *param_2,_GUID *param_3,
          _TR_SECURE_SERVICE_CALLBACKS_V1 *param_4,WDFDEVICE__ **param_5)

{
  undefined8 uVar1;
  WDFDEVICE__ *pWVar2;
  _TREE_MASTER_DEVICE_CONTEXT *p_Var3;
  long lVar4;
  int iVar5;
  ulonglong uVar6;
  longlong lVar7;
  int *piVar8;
  WDFDEVICE__ **ppWVar9;
  WDFDEVICE__ *local_28;
  _TREE_MASTER_DEVICE_CONTEXT *local_20;
  
  local_20 = (_TREE_MASTER_DEVICE_CONTEXT *)0x0;
  (**(code **)(WdfFunctions_01015 + 0x1f8))(WdfDriverGlobals);
  local_28 = (WDFDEVICE__ *)0x0;
  ppWVar9 = &local_28;
  uVar6 = TreeAddServiceDevice(param_2,(longlong *)param_3,ppWVar9,(longlong *)&local_20);
  p_Var3 = local_20;
  pWVar2 = local_28;
  iVar5 = (int)uVar6;
  if (-1 < iVar5) {
    if (param_4 == (_TR_SECURE_SERVICE_CALLBACKS_V1 *)0x0) {
      local_20 = (_TREE_MASTER_DEVICE_CONTEXT *)0x0;
      lVar4 = TreeCxGetDeviceContext((WDFDEVICE__ *)p_Var3,&local_20);
      if ((-1 < lVar4) && (*(code **)(local_20 + 0x78) != (code *)0x0)) {
        param_4 = (_TR_SECURE_SERVICE_CALLBACKS_V1 *)(**(code **)(local_20 + 0x78))(p_Var3,param_3);
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,ppWVar9,0x17,
                           &WPP_36fd475e9c0f3a4c5e3e805381d963da_Traceguids,(char)p_Var3,(char)lVar4
                          );
      }
      if (param_4 == (_TR_SECURE_SERVICE_CALLBACKS_V1 *)0x0) {
        iVar5 = -0x3ffffff3;
        goto LAB_140004579;
      }
    }
    lVar7 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,p_Var3,
                       PTR__WDF_TREE_MASTER_DEVICE_CONTEXT_TYPE_INFO_14000f0f0);
    piVar8 = (int *)(**(code **)(WdfFunctions_01015 + 0x650))
                              (WdfDriverGlobals,*(undefined8 *)(lVar7 + 0x18),
                               PTR__WDF_TREE_CX_BIND_CONTEXT_TYPE_INFO_14000f1c8);
    lVar7 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,pWVar2);
    if (*piVar8 == 1) {
      uVar1 = *(undefined8 *)(param_4 + 8);
      *(undefined8 *)(lVar7 + 0x70) = *(undefined8 *)param_4;
      *(undefined8 *)(lVar7 + 0x78) = uVar1;
      uVar1 = *(undefined8 *)(param_4 + 0x18);
      *(undefined8 *)(lVar7 + 0x80) = *(undefined8 *)(param_4 + 0x10);
      *(undefined8 *)(lVar7 + 0x88) = uVar1;
      uVar1 = *(undefined8 *)(param_4 + 0x28);
      *(undefined8 *)(lVar7 + 0x90) = *(undefined8 *)(param_4 + 0x20);
      *(undefined8 *)(lVar7 + 0x98) = uVar1;
      uVar1 = *(undefined8 *)(param_4 + 0x38);
      *(undefined8 *)(lVar7 + 0xa0) = *(undefined8 *)(param_4 + 0x30);
      *(undefined8 *)(lVar7 + 0xa8) = uVar1;
      uVar1 = *(undefined8 *)(param_4 + 0x48);
      *(undefined8 *)(lVar7 + 0xb0) = *(undefined8 *)(param_4 + 0x40);
      *(undefined8 *)(lVar7 + 0xb8) = uVar1;
    }
    local_20 = (_TREE_MASTER_DEVICE_CONTEXT *)0x0;
    iVar5 = TreeCxGetServiceContext
                      (pWVar2,(_TREE_SERVICE_DEVICE_CONTEXT **)&local_20,
                       (_TREE_MASTER_DEVICE_CONTEXT **)0x0);
    if ((-1 < iVar5) && (*(code **)(local_20 + 0x78) != (code *)0x0)) {
      iVar5 = (**(code **)(local_20 + 0x78))(p_Var3,param_3,pWVar2);
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qq_guid_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
    if (-1 < iVar5) {
      iVar5 = (**(code **)(WdfFunctions_01015 + 0x268))(WdfDriverGlobals,pWVar2,param_3,0);
      if (-1 < iVar5) {
        iVar5 = 0;
        if (param_5 != (WDFDEVICE__ **)0x0) {
          *param_5 = pWVar2;
        }
      }
    }
  }
LAB_140004579:
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF__guid_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  return iVar5;
}



===== TreeSecureDeviceLogMessage @ 1400045d0 =====

/* long __cdecl TreeSecureDeviceLogMessage(void * __ptr64,struct WDFDEVICE__ * __ptr64,unsigned
   long,char const * __ptr64,char * __ptr64) */

long __cdecl
TreeSecureDeviceLogMessage
          (void *param_1,WDFDEVICE__ *param_2,ulong param_3,char *param_4,char *param_5)

{
  long lVar1;
  ulong local_28 [2];
  char *local_20;
  char *local_18;
  
  local_28[1] = 0;
  local_18 = param_5;
  local_28[0] = param_3;
  local_20 = param_4;
  lVar1 = KeExpandKernelStackAndCalloutEx(TreeSecureDeviceLogMessageWorker,local_28,0x800,0,0);
  return lVar1;
}



===== TreeSecureDeviceLogMessageWorker @ 140004630 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl TreeSecureDeviceLogMessageWorker(void * __ptr64) */

void __cdecl TreeSecureDeviceLogMessageWorker(void *param_1)

{
  uint uVar1;
  undefined1 auStack_248 [40];
  char *local_220;
  char local_218 [511];
  undefined1 local_19;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_248;
  uVar1 = _vsnprintf(local_218,0x1ff,*(char **)((longlong)param_1 + 8),
                     *(va_list *)((longlong)param_1 + 0x10));
  if (((int)uVar1 < 0) || (0x1ff < uVar1)) {
    local_19 = 0;
    RtlStringCbPrintfA(local_218,0x200,"<<Error while formatting the message, Status = %08x>>",
                       0x80000005);
  }
  else if (uVar1 == 0x1ff) {
    local_19 = 0;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     ((*(byte *)param_1 < 5 || (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)))) {
    local_220 = local_218;
    WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),*(byte *)param_1);
  }
  return;
}



===== TreeSecureDeviceQueryOSService @ 140004720 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl TreeSecureDeviceQueryOSService(void * __ptr64,struct WDFDEVICE__ * __ptr64,struct
   _GUID const * __ptr64,struct _TR_SERVICE_INFORMATION_V1 * __ptr64) */

long __cdecl
TreeSecureDeviceQueryOSService
          (void *param_1,WDFDEVICE__ *param_2,_GUID *param_3,_TR_SERVICE_INFORMATION_V1 *param_4)

{
  long lVar1;
  longlong lVar2;
  WDFDEVICE__ *pWVar3;
  undefined *puVar4;
  
  pWVar3 = param_2;
  puVar4 = PTR__WDF_TREE_SERVICE_DEVICE_CONTEXT_TYPE_INFO_14000f078;
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
  if ((*(longlong *)param_3 == 0x4497ad1a05272f96) &&
     (*(longlong *)(param_3 + 8) == -0x4c684e9a46e93d69)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF__guid_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pWVar3,puVar4,0xd,
                 &WPP_36fd475e9c0f3a4c5e3e805381d963da_Traceguids,lVar2 + 0x58);
    }
    param_3 = (_GUID *)&GUID_DEVINTERFACE_EMMC_PARTITION_ACCESS_RPMB;
  }
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,
                     PTR__WDF_TREE_SERVICE_DEVICE_CONTEXT_TYPE_INFO_14000f078);
  if (lVar2 == 0) {
    lVar1 = -0x3ffffff3;
  }
  else {
    lVar1 = TreeDriverServicesQuery(param_2,param_3,(undefined8 *)param_4);
  }
  return lVar1;
}



===== RtlStringCbPrintfA @ 14000480c =====

undefined8 RtlStringCbPrintfA(char *param_1,longlong param_2,char *param_3,undefined8 param_4)

{
  ulonglong _Count;
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



===== TreeCxClientCancelSecureServiceRequest @ 140004880 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TreeCxClientCancelSecureServiceRequest
               (undefined8 param_1,WDFFILEOBJECT__ *param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  _TREE_SERVICE_SESSION_CONTEXT **pp_Var2;
  _TREE_SERVICE_DEVICE_CONTEXT **pp_Var3;
  _TREE_SERVICE_DEVICE_CONTEXT *local_28;
  _TREE_SERVICE_SESSION_CONTEXT *local_20;
  _TREE_MASTER_DEVICE_CONTEXT *local_18 [2];
  
  local_18[0] = (_TREE_MASTER_DEVICE_CONTEXT *)0x0;
  local_28 = (_TREE_SERVICE_DEVICE_CONTEXT *)0x0;
  pp_Var2 = &local_20;
  local_20 = (_TREE_SERVICE_SESSION_CONTEXT *)0x0;
  pp_Var3 = &local_28;
  lVar1 = TreeCxGetSessionContext(param_2,pp_Var2,pp_Var3,local_18);
  if (lVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pp_Var2,pp_Var3,0x25,
                       &WPP_36fd475e9c0f3a4c5e3e805381d963da_Traceguids);
    }
  }
  else {
    if (*(code **)(local_28 + 0xb0) != (code *)0x0) {
      (**(code **)(local_28 + 0xb0))(param_1,*(undefined8 *)(local_20 + 0x10),param_3,param_4);
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF__guid_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
  }
  return;
}



===== TreeCxClientConnectSecureService @ 140004974 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

long TreeCxClientConnectSecureService(WDFDEVICE__ *param_1)

{
  _TREE_SERVICE_DEVICE_CONTEXT *p_Var1;
  long lVar2;
  _TREE_SERVICE_DEVICE_CONTEXT **pp_Var3;
  _TREE_MASTER_DEVICE_CONTEXT **pp_Var4;
  _TREE_SERVICE_DEVICE_CONTEXT *local_res10;
  _TREE_MASTER_DEVICE_CONTEXT *local_res18;
  undefined8 in_stack_ffffffffffffffd8;
  
  local_res10 = (_TREE_SERVICE_DEVICE_CONTEXT *)0x0;
  pp_Var4 = &local_res18;
  pp_Var3 = &local_res10;
  lVar2 = TreeCxGetServiceContext(param_1,pp_Var3,pp_Var4);
  p_Var1 = local_res10;
  if (-1 < lVar2) {
    if (*(code **)(local_res10 + 0x88) == (code *)0x0) {
      lVar2 = 0;
    }
    else {
      lVar2 = (**(code **)(local_res10 + 0x88))(param_1);
    }
  }
  if (p_Var1 == (_TREE_SERVICE_DEVICE_CONTEXT *)0x0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pp_Var3,pp_Var4,0x1c,
                        &WPP_36fd475e9c0f3a4c5e3e805381d963da_Traceguids,(char)lVar2);
    }
  }
  else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF__guid_D
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,pp_Var4,0x1b,in_stack_ffffffffffffffd8,
               p_Var1 + 0x58,(char)lVar2);
  }
  return lVar2;
}



===== TreeCxClientCreateSecureSessionContext @ 140004a4c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

long TreeCxClientCreateSecureSessionContext(WDFDEVICE__ *param_1,undefined8 param_2)

{
  _TREE_SERVICE_DEVICE_CONTEXT *p_Var1;
  long lVar2;
  _TREE_SERVICE_DEVICE_CONTEXT **pp_Var3;
  _TREE_MASTER_DEVICE_CONTEXT **pp_Var4;
  _TREE_SERVICE_DEVICE_CONTEXT *local_res18;
  _TREE_MASTER_DEVICE_CONTEXT *local_res20;
  undefined8 in_stack_ffffffffffffffc8;
  
  local_res18 = (_TREE_SERVICE_DEVICE_CONTEXT *)0x0;
  pp_Var4 = &local_res20;
  pp_Var3 = &local_res18;
  lVar2 = TreeCxGetServiceContext(param_1,pp_Var3,pp_Var4);
  p_Var1 = local_res18;
  if (-1 < lVar2) {
    pp_Var4 = (_TREE_MASTER_DEVICE_CONTEXT **)
              PTR__WDF_TREE_SERVICE_SESSION_CONTEXT_TYPE_INFO_14000f118;
    pp_Var3 = (_TREE_SERVICE_DEVICE_CONTEXT **)
              (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_2);
    if (*(code **)(p_Var1 + 0x98) == (code *)0x0) {
      lVar2 = 0;
    }
    else {
      pp_Var3 = pp_Var3 + 2;
      lVar2 = (**(code **)(p_Var1 + 0x98))(param_1);
    }
  }
  if (p_Var1 == (_TREE_SERVICE_DEVICE_CONTEXT *)0x0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pp_Var3,pp_Var4,0x20,
                        &WPP_36fd475e9c0f3a4c5e3e805381d963da_Traceguids,(char)lVar2);
    }
  }
  else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF__guid_D
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,pp_Var4,0x1f,in_stack_ffffffffffffffc8,
               p_Var1 + 0x58,(char)lVar2);
  }
  return lVar2;
}



===== TreeCxClientDestroySecureSessionContext @ 140004b4c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

long TreeCxClientDestroySecureSessionContext(undefined8 param_1,WDFFILEOBJECT__ *param_2)

{
  _TREE_SERVICE_DEVICE_CONTEXT *p_Var1;
  long lVar2;
  _TREE_SERVICE_SESSION_CONTEXT *p_Var3;
  _TREE_SERVICE_DEVICE_CONTEXT **pp_Var4;
  _TREE_SERVICE_DEVICE_CONTEXT *local_res18;
  _TREE_SERVICE_SESSION_CONTEXT *local_res20;
  undefined8 in_stack_ffffffffffffffc8;
  _TREE_MASTER_DEVICE_CONTEXT *local_18 [2];
  
  local_18[0] = (_TREE_MASTER_DEVICE_CONTEXT *)0x0;
  local_res18 = (_TREE_SERVICE_DEVICE_CONTEXT *)0x0;
  pp_Var4 = &local_res18;
  local_res20 = (_TREE_SERVICE_SESSION_CONTEXT *)0x0;
  p_Var3 = (_TREE_SERVICE_SESSION_CONTEXT *)&local_res20;
  lVar2 = TreeCxGetSessionContext(param_2,(_TREE_SERVICE_SESSION_CONTEXT **)p_Var3,pp_Var4,local_18)
  ;
  p_Var1 = local_res18;
  if (-1 < lVar2) {
    if (*(code **)(local_res18 + 0xa0) == (code *)0x0) {
      lVar2 = 0;
    }
    else {
      p_Var3 = local_res20 + 0x10;
      lVar2 = (**(code **)(local_res18 + 0xa0))(param_1);
    }
  }
  if (p_Var1 == (_TREE_SERVICE_DEVICE_CONTEXT *)0x0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),p_Var3,pp_Var4,0x22,
                        &WPP_36fd475e9c0f3a4c5e3e805381d963da_Traceguids,(char)lVar2);
    }
  }
  else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF__guid_D
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,pp_Var4,0x21,in_stack_ffffffffffffffc8,
               p_Var1 + 0x58,(char)lVar2);
  }
  return lVar2;
}



===== TreeCxClientDisconnectSecureService @ 140004c40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

long TreeCxClientDisconnectSecureService(WDFDEVICE__ *param_1)

{
  _TREE_SERVICE_DEVICE_CONTEXT *p_Var1;
  long lVar2;
  _TREE_SERVICE_DEVICE_CONTEXT **pp_Var3;
  _TREE_MASTER_DEVICE_CONTEXT **pp_Var4;
  _TREE_SERVICE_DEVICE_CONTEXT *local_res10;
  _TREE_MASTER_DEVICE_CONTEXT *local_res18;
  undefined8 in_stack_ffffffffffffffd8;
  
  local_res10 = (_TREE_SERVICE_DEVICE_CONTEXT *)0x0;
  pp_Var4 = &local_res18;
  pp_Var3 = &local_res10;
  lVar2 = TreeCxGetServiceContext(param_1,pp_Var3,pp_Var4);
  p_Var1 = local_res10;
  if (-1 < lVar2) {
    if (*(code **)(local_res10 + 0x90) == (code *)0x0) {
      lVar2 = 0;
    }
    else {
      lVar2 = (**(code **)(local_res10 + 0x90))(param_1);
    }
  }
  if (p_Var1 == (_TREE_SERVICE_DEVICE_CONTEXT *)0x0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pp_Var3,pp_Var4,0x1e,
                        &WPP_36fd475e9c0f3a4c5e3e805381d963da_Traceguids,(char)lVar2);
    }
  }
  else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF__guid_D
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,pp_Var4,0x1d,in_stack_ffffffffffffffd8,
               p_Var1 + 0x58,(char)lVar2);
  }
  return lVar2;
}



===== TreeCxClientProcessOtherSecureServiceIo @ 140004d18 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TreeCxClientProcessOtherSecureServiceIo
               (undefined8 param_1,WDFFILEOBJECT__ *param_2,ulonglong param_3)

{
  _TREE_SERVICE_DEVICE_CONTEXT *p_Var1;
  long lVar2;
  uint uVar3;
  code *pcVar4;
  _TREE_SERVICE_SESSION_CONTEXT **pp_Var5;
  ulonglong uVar6;
  _TREE_SERVICE_DEVICE_CONTEXT **pp_Var7;
  ulonglong uVar8;
  _TREE_SERVICE_SESSION_CONTEXT *local_res20;
  undefined8 in_stack_ffffffffffffffa8;
  _TREE_SERVICE_DEVICE_CONTEXT *local_38;
  _TREE_MASTER_DEVICE_CONTEXT *local_30;
  code *local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  ulonglong uStack_10;
  
  local_30 = (_TREE_MASTER_DEVICE_CONTEXT *)0x0;
  local_38 = (_TREE_SERVICE_DEVICE_CONTEXT *)0x0;
  local_res20 = (_TREE_SERVICE_SESSION_CONTEXT *)0x0;
  pp_Var5 = &local_res20;
  pp_Var7 = &local_38;
  local_28 = (code *)0x0;
  uStack_20 = 0;
  local_18 = 0;
  uStack_10 = 0;
  lVar2 = TreeCxGetSessionContext(param_2,pp_Var5,pp_Var7,&local_30);
  p_Var1 = local_38;
  if (lVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return;
    }
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pp_Var5,pp_Var7,0x27,
                     &WPP_36fd475e9c0f3a4c5e3e805381d963da_Traceguids);
    return;
  }
  pcVar4 = *(code **)(local_38 + 0xb8);
  if (pcVar4 == (code *)0x0) {
    uVar6 = 0xc0000010;
    pcVar4 = *(code **)(WdfFunctions_01015 + 0x838);
  }
  else {
    if (*(int *)(local_30 + 8) == 0) {
      (*pcVar4)(param_1,*(undefined8 *)(local_res20 + 0x10));
      uVar3 = 0x103;
      uVar8 = param_3;
      goto LAB_140004e47;
    }
    local_18 = *(undefined8 *)(local_res20 + 0x10);
    uVar8 = (ulonglong)*(uint *)(local_30 + 8);
    local_28 = pcVar4;
    uStack_20 = param_1;
    uStack_10 = param_3;
    uVar3 = KeExpandKernelStackAndCallout(TreeCxClientProcessOtherSecureServiceIoWorker,&local_28);
    uVar6 = (ulonglong)uVar3;
    if (-1 < (int)uVar3) goto LAB_140004e47;
    pcVar4 = *(code **)(WdfFunctions_01015 + 0x838);
  }
  uVar3 = (uint)uVar6;
  (*pcVar4)(WdfDriverGlobals,param_3);
  uVar8 = uVar6;
LAB_140004e47:
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF__guid_D
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,uVar8,0x28,in_stack_ffffffffffffffa8,
               p_Var1 + 0x58,(char)uVar3);
  }
  return;
}



===== TreeCxClientProcessSecureServiceRequest @ 140004e9c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

long TreeCxClientProcessSecureServiceRequest
               (undefined8 param_1,WDFFILEOBJECT__ *param_2,undefined8 param_3,undefined4 param_4,
               undefined8 param_5,undefined4 param_6,undefined8 *param_7,undefined8 param_8)

{
  code *pcVar1;
  long lVar2;
  _TREE_SERVICE_SESSION_CONTEXT **pp_Var3;
  _TREE_SERVICE_DEVICE_CONTEXT **pp_Var4;
  undefined8 in_stack_ffffffffffffff30;
  undefined4 uVar5;
  _TREE_SERVICE_SESSION_CONTEXT *local_98;
  _TREE_SERVICE_DEVICE_CONTEXT *local_90;
  _TREE_MASTER_DEVICE_CONTEXT *local_88 [2];
  code *local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined4 local_58;
  undefined8 local_50;
  undefined4 local_48;
  undefined8 *local_40;
  undefined8 local_38;
  long local_30;
  
  uVar5 = (undefined4)((ulonglong)in_stack_ffffffffffffff30 >> 0x20);
  memset(&local_78,0,0x50);
  pp_Var4 = &local_90;
  local_88[0] = (_TREE_MASTER_DEVICE_CONTEXT *)0x0;
  pp_Var3 = &local_98;
  local_90 = (_TREE_SERVICE_DEVICE_CONTEXT *)0x0;
  local_98 = (_TREE_SERVICE_SESSION_CONTEXT *)0x0;
  lVar2 = TreeCxGetSessionContext(param_2,pp_Var3,pp_Var4,local_88);
  if (lVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pp_Var3,pp_Var4,0x23,
                       &WPP_36fd475e9c0f3a4c5e3e805381d963da_Traceguids);
    }
  }
  else {
    pcVar1 = *(code **)(local_90 + 0xa8);
    if (pcVar1 != (code *)0x0) {
      if (*(int *)(local_88[0] + 8) == 0) {
        lVar2 = (*pcVar1)(param_1,*(undefined8 *)(local_98 + 0x10),param_3,param_4,param_5,
                          CONCAT44(uVar5,param_6),param_7,param_8);
      }
      else {
        *param_7 = 0;
        local_68 = *(undefined8 *)(local_98 + 0x10);
        local_38 = param_8;
        local_50 = param_5;
        local_48 = param_6;
        local_40 = param_7;
        local_78 = pcVar1;
        local_70 = param_1;
        local_60 = param_3;
        local_58 = param_4;
        lVar2 = KeExpandKernelStackAndCallout
                          (TreeCxClientProcessSecureServiceRequestWorker,&local_78,
                           *(undefined4 *)(local_88[0] + 8));
        if (-1 < lVar2) {
          lVar2 = local_30;
        }
      }
      goto LAB_140005006;
    }
    lVar2 = -0x3fffff45;
  }
  *param_7 = 0;
LAB_140005006:
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF__guid_dDqDP(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  return lVar2;
}



===== WPP_RECORDER_SF__guid_D @ 140005078 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF__guid_D
               (undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,undefined8 param_6,undefined1 param_7)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_36fd475e9c0f3a4c5e3e805381d963da_Traceguids,param_4,param_6,0x10,&param_7,4,0);
  }
  WppAutoLogTrace(param_1,param_2,1,&WPP_36fd475e9c0f3a4c5e3e805381d963da_Traceguids,param_4,param_6
                  ,0x10,&param_7,4,0);
  return;
}



===== WPP_RECORDER_SF__guid_dDqDP @ 14000515c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF__guid_dDqDP(undefined8 param_1)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_36fd475e9c0f3a4c5e3e805381d963da_Traceguids,0x24);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_36fd475e9c0f3a4c5e3e805381d963da_Traceguids,0x24);
  return;
}



===== WPP_RECORDER_SF__guid_qD @ 1400052cc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF__guid_qD(undefined8 param_1)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_36fd475e9c0f3a4c5e3e805381d963da_Traceguids,0xb);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_36fd475e9c0f3a4c5e3e805381d963da_Traceguids,0xb);
  return;
}



===== WPP_RECORDER_SF__guid_qq @ 1400053d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF__guid_qq(undefined8 param_1)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_36fd475e9c0f3a4c5e3e805381d963da_Traceguids,0x26);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_36fd475e9c0f3a4c5e3e805381d963da_Traceguids,0x26);
  return;
}



===== WPP_RECORDER_SF_qDD @ 1400054d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qDD(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_36fd475e9c0f3a4c5e3e805381d963da_Traceguids,0x16,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,4,0);
  }
  WppAutoLogTrace(param_1,2,1,&WPP_36fd475e9c0f3a4c5e3e805381d963da_Traceguids,0x16,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,4,0);
  return;
}



===== WPP_RECORDER_SF_qq_guid_D @ 1400055c4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qq_guid_D(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_36fd475e9c0f3a4c5e3e805381d963da_Traceguids,0x18,&uStack0000000000000030,8,
               &uStack0000000000000038,8);
  }
  WppAutoLogTrace(param_1,2,1,&WPP_36fd475e9c0f3a4c5e3e805381d963da_Traceguids,0x18,
                  &uStack0000000000000030,8,&uStack0000000000000038,8);
  return;
}



===== WPP_RECORDER_SF_s @ 1400056e8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_s(undefined8 param_1,byte param_2)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  char *in_stack_00000030;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
    if (in_stack_00000030 == (char *)0x0) {
      lVar2 = 5;
    }
    else {
      lVar1 = -1;
      do {
        lVar2 = lVar1;
        lVar1 = lVar2 + 1;
      } while (in_stack_00000030[lVar1] != '\0');
      lVar2 = lVar2 + 2;
    }
    pcVar3 = in_stack_00000030;
    if (in_stack_00000030 == (char *)0x0) {
      pcVar3 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_36fd475e9c0f3a4c5e3e805381d963da_Traceguids,0xc,pcVar3,lVar2,0);
  }
  lVar2 = -1;
  if (in_stack_00000030 == (char *)0x0) {
    lVar1 = 5;
  }
  else {
    do {
      lVar1 = lVar2;
      lVar2 = lVar1 + 1;
    } while (in_stack_00000030[lVar2] != '\0');
    lVar1 = lVar1 + 2;
  }
  if (in_stack_00000030 == (char *)0x0) {
    in_stack_00000030 = "NULL";
  }
  WppAutoLogTrace(param_1,param_2,1,&WPP_36fd475e9c0f3a4c5e3e805381d963da_Traceguids,0xc,
                  in_stack_00000030,lVar1,0);
  return;
}



===== TreeSecureServicesEvtIoInCallerContextDeviceIoControl @ 1400057fc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl TreeSecureServicesEvtIoInCallerContextDeviceIoControl(struct WDFREQUEST__ *
   __ptr64,unsigned long,unsigned __int64,unsigned __int64) */

long __cdecl
TreeSecureServicesEvtIoInCallerContextDeviceIoControl
          (WDFREQUEST__ *param_1,ulong param_2,__uint64 param_3,__uint64 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  char cVar6;
  int iVar7;
  long lVar8;
  longlong lVar9;
  code *pcVar10;
  ulonglong uVar11;
  longlong lVar12;
  ulonglong uVar13;
  undefined8 *local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  WDFREQUEST__ *local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  
  local_70 = (undefined8 *)0x0;
  iVar7 = 0;
  lVar9 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  cVar6 = (**(code **)(WdfFunctions_01015 + 0x8c0))(WdfDriverGlobals,param_1);
  if (param_2 == 0x560000) {
    uVar11 = 0;
    uVar13 = 0xc;
  }
  else {
    if (param_2 != 0x568004) {
      return 0;
    }
    uVar11 = 0x30;
    uVar13 = 0x10;
  }
  if (param_3 < uVar11) {
    return -0x3ffffff3;
  }
  if ((uVar11 != 0) &&
     (iVar7 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_1,uVar11,&local_70,0)
     , iVar7 < 0)) {
    return iVar7;
  }
  puVar5 = local_70;
  if (param_4 < uVar13) {
    return -0x3ffffff3;
  }
  if (param_2 == 0x560000) {
    return iVar7;
  }
  if (param_2 != 0x568004) {
    return -0x3ffffff0;
  }
  uVar4 = local_70[1];
  *(undefined8 *)(lVar9 + 0x20) = *local_70;
  *(undefined8 *)(lVar9 + 0x28) = uVar4;
  uVar1 = *(undefined4 *)((longlong)local_70 + 0x14);
  uVar2 = *(undefined4 *)(local_70 + 3);
  uVar3 = *(undefined4 *)((longlong)local_70 + 0x1c);
  *(undefined4 *)(lVar9 + 0x30) = *(undefined4 *)(local_70 + 2);
  *(undefined4 *)(lVar9 + 0x34) = uVar1;
  *(undefined4 *)(lVar9 + 0x38) = uVar2;
  *(undefined4 *)(lVar9 + 0x3c) = uVar3;
  uVar1 = *(undefined4 *)((longlong)local_70 + 0x24);
  uVar2 = *(undefined4 *)(local_70 + 5);
  uVar3 = *(undefined4 *)((longlong)local_70 + 0x2c);
  *(undefined4 *)(lVar9 + 0x40) = *(undefined4 *)(local_70 + 4);
  *(undefined4 *)(lVar9 + 0x44) = uVar1;
  *(undefined4 *)(lVar9 + 0x48) = uVar2;
  *(undefined4 *)(lVar9 + 0x4c) = uVar3;
  if (cVar6 == '\x01') {
    if ((local_70[3] != 0) &&
       (iVar7 = (**(code **)(WdfFunctions_01015 + 0x8b0))
                          (WdfDriverGlobals,param_1,local_70[2],local_70[3],lVar9 + 0x10), iVar7 < 0
       )) {
      return iVar7;
    }
    lVar12 = puVar5[5];
    if (lVar12 == 0) {
      return iVar7;
    }
    pcVar10 = *(code **)(WdfFunctions_01015 + 0x8b8);
  }
  else {
    cVar6 = (**(code **)(WdfFunctions_01015 + 0xc50))(WdfDriverGlobals,param_1);
    if (cVar6 != '\0') {
      if ((puVar5[3] != 0) &&
         (iVar7 = (**(code **)(WdfFunctions_01015 + 0x618))
                            (WdfDriverGlobals,*(undefined8 *)(lVar9 + 0x10),puVar5[2]), iVar7 < 0))
      {
        return iVar7;
      }
      if (puVar5[5] == 0) {
        return iVar7;
      }
      lVar8 = (**(code **)(WdfFunctions_01015 + 0x618))
                        (WdfDriverGlobals,*(undefined8 *)(lVar9 + 0x18),puVar5[4]);
      return lVar8;
    }
    local_58 = 0;
    uStack_60 = 0;
    local_68 = 0x38;
    uStack_40 = 0;
    uStack_50 = 0x100000001;
    local_38 = 0;
    local_48 = param_1;
    if ((puVar5[3] != 0) &&
       (iVar7 = (**(code **)(WdfFunctions_01015 + 0x608))
                          (WdfDriverGlobals,&local_68,puVar5[2],puVar5[3],lVar9 + 0x10), iVar7 < 0))
    {
      return iVar7;
    }
    lVar12 = puVar5[5];
    if (lVar12 == 0) {
      return iVar7;
    }
    param_1 = (WDFREQUEST__ *)&local_68;
    pcVar10 = *(code **)(WdfFunctions_01015 + 0x608);
  }
  lVar8 = (*pcVar10)(WdfDriverGlobals,param_1,puVar5[4],lVar12,lVar9 + 0x18);
  return lVar8;
}



===== TreeSecureServicesSessionQueueExecuteDeferred @ 140005ae8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl TreeSecureServicesSessionQueueExecuteDeferred(struct WDFREQUEST__ * __ptr64) */

void __cdecl TreeSecureServicesSessionQueueExecuteDeferred(WDFREQUEST__ *param_1)

{
  longlong lVar1;
  longlong lVar2;
  char cVar3;
  int iVar4;
  undefined8 uVar5;
  longlong *plVar6;
  longlong lVar7;
  
  (**(code **)(WdfFunctions_01015 + 0x650))
            (WdfDriverGlobals,param_1,
             PTR__WDF_TREE_SECURE_SERVICES_REQUEST_CONTEXT_TYPE_INFO_14000f0a0);
  uVar5 = (**(code **)(WdfFunctions_01015 + 0x8a8))(WdfDriverGlobals,param_1);
  plVar6 = (longlong *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,uVar5,
                      PTR__WDF_TREE_SERVICE_SESSION_CONTEXT_TYPE_INFO_14000f118);
  lVar1 = *plVar6;
  lVar2 = *(longlong *)(lVar1 + 0x68);
  iVar4 = (**(code **)(WdfFunctions_01015 + 0x5f8))
                    (WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x20),*(undefined8 *)(lVar1 + 0x50),
                     0x56000c,0,0,0,0,0,0);
  if (-1 < iVar4) {
    (**(code **)(WdfFunctions_01015 + 0x820))
              (WdfDriverGlobals,*(undefined8 *)(lVar1 + 0x50),
               TreeSecureServicesSessionQueueCompletion,0);
    lVar7 = (**(code **)(WdfFunctions_01015 + 0x8e8))
                      (WdfDriverGlobals,*(undefined8 *)(lVar1 + 0x50));
    *(WDFREQUEST__ **)(*(longlong *)(lVar7 + 0xb8) + -0x40) = param_1;
    cVar3 = (**(code **)(WdfFunctions_01015 + 0x7e8))
                      (WdfDriverGlobals,*(undefined8 *)(lVar1 + 0x50),*(undefined8 *)(lVar2 + 0x20),
                       0);
    if (cVar3 != '\0') {
      return;
    }
    iVar4 = (**(code **)(WdfFunctions_01015 + 0x7f0))
                      (WdfDriverGlobals,*(undefined8 *)(lVar1 + 0x50));
    if (-1 < iVar4) {
      return;
    }
  }
  TreeSecureSessionCompleteRequest(param_1,iVar4,0);
  return;
}



===== TreeSecureServicesSessionQueueQueryService @ 140005c7c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl TreeSecureServicesSessionQueueQueryService(struct WDFREQUEST__ * __ptr64) */

void __cdecl TreeSecureServicesSessionQueueQueryService(WDFREQUEST__ *param_1)

{
  int iVar1;
  longlong *plVar2;
  undefined8 uVar3;
  undefined4 *local_res10;
  
  local_res10 = (undefined4 *)0x0;
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x8d0))(WdfDriverGlobals,param_1);
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,uVar3);
  plVar2 = (longlong *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,uVar3,
                      PTR__WDF_TREE_SERVICE_DEVICE_CONTEXT_TYPE_INFO_14000f078);
  uVar3 = 0xc;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,param_1,0xc,&local_res10,0);
  if (iVar1 < 0) {
    uVar3 = 0;
  }
  else {
    *local_res10 = 1;
    local_res10[1] = *(undefined4 *)(*plVar2 + 0x14);
    local_res10[2] = *(undefined4 *)(*plVar2 + 0x18);
    iVar1 = 0;
  }
  TreeSecureSessionCompleteRequest(param_1,iVar1,uVar3);
  return;
}



===== TreeCreateSecureSessionContext @ 140005d80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

long TreeCreateSecureSessionContext(WDFDEVICE__ *param_1,undefined8 param_2)

{
  int iVar1;
  long lVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  code *local_50;
  
  local_80 = 0;
  local_b0 = 0;
  uStack_a8 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  local_90 = 0;
  uStack_88 = 0;
  memset(&local_78,0,0x60);
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,
                     PTR__WDF_TREE_SERVICE_DEVICE_CONTEXT_TYPE_INFO_14000f078);
  plVar4 = (longlong *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_2,
                      PTR__WDF_TREE_SERVICE_SESSION_CONTEXT_TYPE_INFO_14000f118);
  *plVar4 = lVar3;
  local_d8 = 0;
  local_b8 = 0;
  uStack_e0 = 0;
  local_e8 = 0x38;
  uStack_c0 = 0;
  uStack_d0 = 0x100000001;
  local_c8 = param_2;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x9d8))(WdfDriverGlobals,&local_e8,plVar4 + 4);
  if (iVar1 < 0) {
    return iVar1;
  }
  plVar4 = plVar4 + 1;
  if (*(int *)(*(longlong *)(lVar3 + 0x68) + 4) == 1) {
    local_78 = 0x60;
    local_70 = 2;
    local_50 = TreeSecureServicesSessionQueueEvtDeviceIoControl;
    local_74 = 1;
    local_b0 = CONCAT44(local_b0._4_4_,0x38);
    uStack_98 = 0x300000002;
    local_90 = param_2;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x4c0))
                      (WdfDriverGlobals,param_1,&local_78,&local_b0,plVar4);
    if (iVar1 < 0) {
      return iVar1;
    }
    (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x38));
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x78))
                      (WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x40),*plVar4);
    (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x38));
    if (iVar1 < 0) {
      return iVar1;
    }
  }
  else {
    *plVar4 = 0;
  }
  lVar2 = TreeCxClientCreateSecureSessionContext(param_1,param_2);
  return lVar2;
}



===== TreeSecureServiceCreateChildDevice @ 140005f88 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int TreeSecureServiceCreateChildDevice(undefined8 param_1,undefined4 *param_2,undefined8 param_3)

{
  int iVar1;
  undefined1 auStack_b8 [48];
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 local_28;
  undefined4 local_24;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_b8;
  local_38 = *param_2;
  uStack_34 = param_2[1];
  uStack_30 = param_2[2];
  uStack_2c = param_2[3];
  local_80 = 0;
  local_24 = 0;
  local_28 = 0xf;
  local_78 = 0;
  uStack_70 = 0;
  (**(code **)(WdfFunctions_01015 + 0x2a8))(WdfDriverGlobals,param_1,&local_38);
  local_88 = (**(code **)(WdfFunctions_01015 + 0x690))(WdfDriverGlobals,param_1);
  RtlInitUnicodeString(&local_78,param_3);
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x6b0))(WdfDriverGlobals,local_88,&local_78);
  if (-1 < iVar1) {
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x6a0))(WdfDriverGlobals,local_88,&local_78);
    if (-1 < iVar1) {
      iVar1 = (**(code **)(WdfFunctions_01015 + 600))(WdfDriverGlobals,&local_88,0,&local_80);
      if (-1 < iVar1) {
        iVar1 = (**(code **)(WdfFunctions_01015 + 0x428))(WdfDriverGlobals,param_1,local_80);
        if (-1 < iVar1) {
          local_5c = 0;
          local_60 = 0;
          local_4c = 0;
          local_64 = 2;
          local_58 = 2;
          local_54 = 2;
          local_50 = 2;
          local_48 = 2;
          local_44 = 2;
          local_40 = 0xffffffff;
          local_3c = 0xffffffff;
          local_68 = 0x30;
          (**(code **)(WdfFunctions_01015 + 0x298))(WdfDriverGlobals,local_80,&local_68);
        }
      }
    }
  }
  return iVar1;
}



===== TreeSecureServicesCallOSService @ 140006140 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint TreeSecureServicesCallOSService
               (undefined8 param_1,_GUID *param_2,undefined8 *param_3,ulonglong *param_4)

{
  undefined8 uVar1;
  int iVar2;
  uint uVar3;
  longlong lVar4;
  void *_Dst;
  uint unaff_EBX;
  void *local_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined *local_38;
  
  local_88 = (void *)0x0;
  local_70 = 0;
  local_80 = 0;
  uStack_78 = 0;
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,
                     PTR__WDF_TREE_SERVICE_DEVICE_CONTEXT_TYPE_INFO_14000f078);
  if (lVar4 == 0) {
    return unaff_EBX;
  }
  local_58 = 0;
  uStack_50 = 0x100000001;
  local_38 = PTR__WDF_TREE_SESSION_CALL_DATA_TYPE_INFO_14000f0c8;
  uStack_60 = 0;
  local_68 = 0x38;
  local_48 = 0;
  uStack_40 = 0;
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x678))(WdfDriverGlobals,&local_68,&local_88);
  if (iVar2 < 0) {
    iVar2 = KeWaitForSingleObject(lVar4 + 0x10,0,0,0,0);
    if (iVar2 != 0) goto LAB_140006336;
    local_88 = *(void **)(lVar4 + 0x28);
  }
  _Dst = (void *)(**(code **)(WdfFunctions_01015 + 0x650))
                           (WdfDriverGlobals,local_88,
                            PTR__WDF_TREE_SESSION_CALL_DATA_TYPE_INFO_14000f0c8);
  memset(_Dst,0,0x50);
  KeInitializeEvent(&local_80,0,0);
  *(code **)((longlong)_Dst + 0x40) = TreeServicesEvtAsyncSessionCallComplete;
  *(undefined8 **)((longlong)_Dst + 0x48) = &local_80;
  uVar1 = param_3[1];
  *(undefined8 *)((longlong)_Dst + 0x10) = *param_3;
  *(undefined8 *)((longlong)_Dst + 0x18) = uVar1;
  uVar1 = param_3[3];
  *(undefined8 *)((longlong)_Dst + 0x20) = param_3[2];
  *(undefined8 *)((longlong)_Dst + 0x28) = uVar1;
  uVar1 = param_3[5];
  *(undefined8 *)((longlong)_Dst + 0x30) = param_3[4];
  *(undefined8 *)((longlong)_Dst + 0x38) = uVar1;
  uVar3 = TreeDriverServicesExecuteCommand(*(WDFDEVICE__ **)(lVar4 + 8),param_2,local_88);
  if (uVar3 == 0x103) {
    uVar3 = KeWaitForSingleObject(&local_80,0,0,0,0);
  }
  if ((-1 < (int)uVar3) && (param_4 != (ulonglong *)0x0)) {
    *param_4 = (ulonglong)*(uint *)((longlong)_Dst + 8);
  }
  if (local_88 == *(void **)(lVar4 + 0x28)) {
    KeSetEvent(lVar4 + 0x10,0,0);
  }
  else {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
LAB_140006336:
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF__guid_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  return unaff_EBX;
}



===== TreeSecureServicesEvtDefaultIo @ 1400063a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void TreeSecureServicesEvtDefaultIo(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  WDFDEVICE__ *pWVar2;
  undefined8 uVar3;
  longlong lVar4;
  undefined1 auStack_68 [32];
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_68;
  pWVar2 = (WDFDEVICE__ *)(**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
  (**(code **)(WdfFunctions_01015 + 0x650))
            (WdfDriverGlobals,pWVar2,PTR__WDF_TREE_SERVICE_DEVICE_CONTEXT_TYPE_INFO_14000f078);
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x8a8))(WdfDriverGlobals,param_2);
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar3,
                     PTR__WDF_TREE_SERVICE_SESSION_CONTEXT_TYPE_INFO_14000f118);
  local_28 = 0;
  uStack_40 = 0;
  local_48 = 0x28;
  local_38 = 0;
  uStack_30 = 0;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_48);
  lVar1 = -0x3fffff45;
  if (local_48._4_4_ == 0) {
    if (*(longlong *)(lVar4 + 8) == 0) {
      lVar1 = TreeCreateSecureSessionContext(pWVar2,uVar3);
    }
    else {
      lVar1 = -0x3ffffe7c;
    }
  }
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,lVar1);
  return;
}



===== TreeSecureServicesEvtDestroyFileObject @ 140006500 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TreeSecureServicesEvtDestroyFileObject(WDFFILEOBJECT__ *param_1)

{
  undefined8 uVar1;
  longlong lVar2;
  longlong *plVar3;
  
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x458))(WdfDriverGlobals,param_1);
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar1,PTR__WDF_TREE_SERVICE_DEVICE_CONTEXT_TYPE_INFO_14000f078
                    );
  plVar3 = (longlong *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,
                      PTR__WDF_TREE_SERVICE_SESSION_CONTEXT_TYPE_INFO_14000f118);
  if (plVar3[1] != 0) {
    (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x38));
    (**(code **)(WdfFunctions_01015 + 0x80))
              (WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x40),plVar3[1]);
    (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x38));
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,plVar3[1]);
    plVar3[1] = 0;
  }
  if (*plVar3 != 0) {
    TreeCxClientDestroySecureSessionContext(uVar1,param_1);
  }
  return;
}



===== TreeSecureServicesEvtDeviceCleanup @ 140006640 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TreeSecureServicesEvtDeviceCleanup(WDFDEVICE__ *param_1)

{
  _TREE_SERVICE_DEVICE_CONTEXT *p_Var1;
  long lVar2;
  longlong *plVar3;
  _TREE_SERVICE_DEVICE_CONTEXT **pp_Var4;
  _TREE_MASTER_DEVICE_CONTEXT **pp_Var5;
  _TREE_SERVICE_DEVICE_CONTEXT *local_res8;
  _TREE_MASTER_DEVICE_CONTEXT *local_res10;
  ulonglong in_stack_ffffffffffffffd8;
  
  plVar3 = (longlong *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,
                      PTR__WDF_TREE_SERVICE_DEVICE_CONTEXT_TYPE_INFO_14000f078);
  if (plVar3[9] != 0) {
    ExFreePoolWithTag(plVar3[9],0);
    plVar3[9] = 0;
  }
  in_stack_ffffffffffffffd8 = in_stack_ffffffffffffffd8 & 0xffffffffffffff00;
  (**(code **)(WdfFunctions_01015 + 0x270))(WdfDriverGlobals,param_1,*plVar3 + 4,0);
  local_res8 = (_TREE_SERVICE_DEVICE_CONTEXT *)0x0;
  pp_Var5 = &local_res10;
  pp_Var4 = &local_res8;
  lVar2 = TreeCxGetServiceContext(param_1,pp_Var4,pp_Var5);
  p_Var1 = local_res8;
  if (-1 < lVar2) {
    if (*(code **)(local_res8 + 0x80) == (code *)0x0) {
      lVar2 = 0;
    }
    else {
      lVar2 = (**(code **)(local_res8 + 0x80))(param_1);
    }
  }
  if (p_Var1 == (_TREE_SERVICE_DEVICE_CONTEXT *)0x0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pp_Var4,pp_Var5,0x1a,
                        &WPP_36fd475e9c0f3a4c5e3e805381d963da_Traceguids,(char)lVar2);
    }
  }
  else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF__guid_D
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,pp_Var5,0x19,in_stack_ffffffffffffffd8,
               p_Var1 + 0x58,(char)lVar2);
  }
  return;
}



===== TreeSecureServicesEvtDeviceD0Entry @ 140006780 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int TreeSecureServicesEvtDeviceD0Entry(WDFDEVICE__ *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  longlong lVar4;
  bool bVar5;
  
  iVar3 = 0;
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,
                     PTR__WDF_TREE_SERVICE_DEVICE_CONTEXT_TYPE_INFO_14000f078);
  uVar2 = *(uint *)(lVar4 + 0xc0);
  do {
    LOCK();
    uVar1 = *(uint *)(lVar4 + 0xc0);
    bVar5 = uVar2 == uVar1;
    if (bVar5) {
      *(uint *)(lVar4 + 0xc0) = uVar2 | 1;
    }
    else {
      uVar2 = uVar1;
    }
    UNLOCK();
  } while (!bVar5);
  if ((uVar2 == 0) &&
     (iVar3 = (**(code **)(WdfFunctions_01015 + 0xdb0))
                        (WdfDriverGlobals,param_1,0,0,0x5b4,
                         "onecore\\base\\basedrv\\tree\\treeclx\\driver\\secureservices.cxx"),
     iVar3 < 0)) {
    return iVar3;
  }
  if (3 < param_2) {
    iVar3 = TreeCxClientConnectSecureService(param_1);
  }
  return iVar3;
}



===== TreeSecureServicesEvtDeviceD0Exit @ 140006850 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

long TreeSecureServicesEvtDeviceD0Exit(WDFDEVICE__ *param_1)

{
  int iVar1;
  long lVar2;
  
  (**(code **)(WdfFunctions_01015 + 0x650))
            (WdfDriverGlobals,param_1,PTR__WDF_TREE_SERVICE_DEVICE_CONTEXT_TYPE_INFO_14000f078);
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x160))(WdfDriverGlobals,param_1);
  if (iVar1 < 4) {
    lVar2 = 0;
  }
  else {
    lVar2 = TreeCxClientDisconnectSecureService(param_1);
  }
  return lVar2;
}



===== TreeSecureServicesEvtDeviceIoControl @ 1400068c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TreeSecureServicesEvtDeviceIoControl
               (undefined8 param_1,WDFREQUEST__ *param_2,__uint64 param_3,__uint64 param_4,
               ulong param_5)

{
  int iVar1;
  char cVar2;
  long lVar3;
  longlong lVar4;
  longlong *plVar5;
  
  (**(code **)(WdfFunctions_01015 + 0x650))
            (WdfDriverGlobals,param_2,
             PTR__WDF_TREE_SECURE_SERVICES_REQUEST_CONTEXT_TYPE_INFO_14000f0a0);
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x8a8))(WdfDriverGlobals,param_2);
  if (lVar4 == 0) {
    lVar3 = -0x3ffffff0;
    goto LAB_140006a20;
  }
  plVar5 = (longlong *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,lVar4,
                      PTR__WDF_TREE_SERVICE_SESSION_CONTEXT_TYPE_INFO_14000f118);
  lVar4 = *(longlong *)(*plVar5 + 0x68);
  cVar2 = (**(code **)(WdfFunctions_01015 + 0xc50))(WdfDriverGlobals,param_2);
  if (cVar2 != '\0') {
    cVar2 = (**(code **)(WdfFunctions_01015 + 0x8c0))(WdfDriverGlobals,param_2);
    if (cVar2 == '\x01') {
      lVar3 = -0x3fffff5d;
      goto LAB_140006a20;
    }
    lVar3 = TreeSecureServicesEvtIoInCallerContextDeviceIoControl(param_2,param_5,param_4,param_3);
    if (lVar3 < 0) goto LAB_140006a20;
  }
  iVar1 = *(int *)(lVar4 + 4);
  if (iVar1 == 0) {
LAB_140006a3f:
    TreeSecureServicesSessionQueueEvtDeviceIoControl(param_1,param_2,param_3,param_4,param_5);
    return;
  }
  if (iVar1 == 1) {
    if (plVar5[1] == 0) {
      lVar3 = -0x3ffffe7c;
    }
    else {
      lVar3 = (**(code **)(WdfFunctions_01015 + 0x8c8))(WdfDriverGlobals,param_2);
    }
    if (-1 < lVar3) {
      return;
    }
  }
  else {
    if ((iVar1 == 2) || (iVar1 == 3)) goto LAB_140006a3f;
    lVar3 = -0x3ffffe7c;
  }
LAB_140006a20:
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,lVar3);
  return;
}



===== TreeSecureServicesEvtIoAllocateRequestResources @ 140006a80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TreeSecureServicesEvtIoAllocateRequestResources(undefined8 param_1,undefined8 param_2)

{
  longlong lVar1;
  undefined4 local_48;
  undefined8 local_44;
  undefined8 uStack_3c;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 local_28;
  undefined8 local_20;
  undefined *local_18;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,
                     PTR__WDF_TREE_SECURE_SERVICES_REQUEST_CONTEXT_TYPE_INFO_14000f0a0);
  local_34 = 0;
  local_20 = 0;
  local_18 = PTR__WDF_TREE_SESSION_CALL_DATA_TYPE_INFO_14000f0c8;
  local_44 = 0;
  uStack_3c = 0;
  local_48 = 0x38;
  local_30 = 1;
  local_2c = 1;
  local_28 = param_2;
  (**(code **)(WdfFunctions_01015 + 0x678))(WdfDriverGlobals,&local_48,lVar1 + 8);
  return;
}



===== TreeSecureServicesEvtIoAllocateResourcesForReservedRequest @ 140006b20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TreeSecureServicesEvtIoAllocateResourcesForReservedRequest
               (undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  longlong lVar2;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined4 local_40;
  undefined8 local_3c;
  undefined8 uStack_34;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined8 local_20;
  undefined8 local_18;
  undefined *local_10;
  
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,
                     PTR__WDF_TREE_SECURE_SERVICES_REQUEST_CONTEXT_TYPE_INFO_14000f0a0);
  local_2c = 0;
  local_18 = 0;
  local_10 = PTR__WDF_TREE_SESSION_CALL_DATA_TYPE_INFO_14000f0c8;
  local_3c = 0;
  uStack_34 = 0;
  local_40 = 0x38;
  local_28 = 1;
  local_24 = 1;
  local_20 = param_2;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x678))(WdfDriverGlobals,&local_40,lVar2 + 8);
  if (-1 < iVar1) {
    local_48 = 0;
    local_68 = 0;
    uStack_50 = 0;
    uStack_70 = 0;
    local_78 = 0x38;
    uStack_60 = 0x100000001;
    local_58 = param_2;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x608))
                      (WdfDriverGlobals,&local_78,lVar2 + 0x10,8,lVar2 + 0x10);
    if (-1 < iVar1) {
      (**(code **)(WdfFunctions_01015 + 0x608))
                (WdfDriverGlobals,&local_78,lVar2 + 0x18,8,lVar2 + 0x18);
    }
  }
  return;
}



===== TreeSecureServicesEvtIoInCallerContext @ 140006c70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void TreeSecureServicesEvtIoInCallerContext(undefined8 param_1,WDFREQUEST__ *param_2)

{
  char cVar1;
  undefined4 uVar2;
  long lVar3;
  undefined4 *puVar4;
  undefined1 auStack_58 [32];
  undefined8 local_38;
  __uint64 _Stack_30;
  __uint64 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_58;
  puVar4 = (undefined4 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_2,
                      PTR__WDF_TREE_SECURE_SERVICES_REQUEST_CONTEXT_TYPE_INFO_14000f0a0);
  cVar1 = KeGetCurrentIrql();
  if (cVar1 == '\0') {
    uVar2 = KeQueryPriorityThread(SystemReserved1[0xf]);
  }
  else {
    uVar2 = 0x10;
  }
  *puVar4 = uVar2;
  local_18 = 0;
  _Stack_30 = 0;
  local_38 = 0x28;
  local_28 = 0;
  uStack_20 = 0;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_38);
  if (local_38._4_4_ == 0xe) {
    lVar3 = TreeSecureServicesEvtIoInCallerContextDeviceIoControl
                      (param_2,(ulong)uStack_20,local_28,_Stack_30);
    if (lVar3 < 0) goto LAB_140006d71;
  }
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x2d8))(WdfDriverGlobals,param_1,param_2);
  if (-1 < lVar3) {
    return;
  }
LAB_140006d71:
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,lVar3);
  return;
}



===== TreeSecureServicesEvtRequestCancel @ 140006dc0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TreeSecureServicesEvtRequestCancel(undefined8 param_1)

{
  int iVar1;
  WDFFILEOBJECT__ *pWVar2;
  undefined8 uVar3;
  longlong lVar4;
  longlong lVar5;
  code *pcVar6;
  
  pWVar2 = (WDFFILEOBJECT__ *)(**(code **)(WdfFunctions_01015 + 0x8a8))(WdfDriverGlobals,param_1);
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x458))(WdfDriverGlobals,pWVar2);
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,pWVar2,
                     PTR__WDF_TREE_SERVICE_SESSION_CONTEXT_TYPE_INFO_14000f118);
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,
                     PTR__WDF_TREE_SECURE_SERVICES_REQUEST_CONTEXT_TYPE_INFO_14000f0a0);
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(lVar4 + 0x20));
  iVar1 = *(int *)(lVar5 + 0x70);
  *(undefined4 *)(lVar5 + 0x70) = 5;
  if (iVar1 == 2) {
    uVar3 = *(undefined8 *)(lVar4 + 0x20);
    pcVar6 = *(code **)(WdfFunctions_01015 + 0x9e8);
  }
  else {
    if ((iVar1 == 3) || (iVar1 == 4)) {
      (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(lVar4 + 0x20));
      TreeCxClientCancelSecureServiceRequest(uVar3,pWVar2,param_1,lVar5 + 0x50);
      return;
    }
    uVar3 = *(undefined8 *)(lVar4 + 0x20);
    pcVar6 = *(code **)(WdfFunctions_01015 + 0x9e8);
    if (iVar1 == 6) {
      (*pcVar6)();
      (**(code **)(WdfFunctions_01015 + 0x848))
                (WdfDriverGlobals,param_1,*(undefined4 *)(lVar5 + 0x60),
                 *(undefined8 *)(lVar5 + 0x68));
      return;
    }
  }
  (*pcVar6)(WdfDriverGlobals,uVar3);
  return;
}



===== TreeEvtDriverServicesPluginIoTargetRemoveComplete @ 140006f70 =====

/* void __cdecl TreeEvtDriverServicesPluginIoTargetRemoveComplete(struct WDFIOTARGET__ * __ptr64) */

void __cdecl TreeEvtDriverServicesPluginIoTargetRemoveComplete(WDFIOTARGET__ *param_1)

{
  return;
}



===== TreeSecureServicesSessionQueueCompletion @ 140006f80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TreeSecureServicesSessionQueueCompletion(undefined8 param_1)

{
  undefined8 local_28;
  undefined4 local_20;
  undefined8 local_1c;
  undefined4 local_14;
  
  local_28 = 0x18;
  local_1c = 0;
  local_14 = 0;
  local_20 = 0;
  (**(code **)(WdfFunctions_01015 + 0x7c8))(WdfDriverGlobals,param_1,&local_28);
  return;
}



===== TreeSecureServicesSessionQueueEvtDeviceIoControl @ 140006fd0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TreeSecureServicesSessionQueueEvtDeviceIoControl
               (undefined8 param_1,WDFREQUEST__ *param_2,undefined8 param_3,undefined8 param_4,
               int param_5)

{
  longlong lVar1;
  int iVar2;
  WDFFILEOBJECT__ *pWVar3;
  longlong *plVar4;
  longlong lVar5;
  undefined8 uVar6;
  
  pWVar3 = (WDFFILEOBJECT__ *)(**(code **)(WdfFunctions_01015 + 0x8a8))(WdfDriverGlobals);
  plVar4 = (longlong *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,pWVar3,
                      PTR__WDF_TREE_SERVICE_SESSION_CONTEXT_TYPE_INFO_14000f118);
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,
                     PTR__WDF_TREE_SECURE_SERVICES_REQUEST_CONTEXT_TYPE_INFO_14000f0a0);
  lVar1 = *(longlong *)(*plVar4 + 0x68);
  uVar6 = (**(code **)(WdfFunctions_01015 + 0x660))(WdfDriverGlobals);
  *(undefined4 *)(lVar5 + 0x70) = 0;
  *(undefined4 *)(lVar5 + 0x60) = 0xffffffff;
  *(undefined8 *)(lVar5 + 0x68) = 0;
  if (param_5 == 0x560000) {
    *(undefined4 *)(lVar5 + 0x70) = 2;
    iVar2 = (**(code **)(WdfFunctions_01015 + 0xc48))
                      (WdfDriverGlobals,param_2,TreeSecureServicesEvtRequestCancel);
    if (iVar2 < 0) {
      (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar2);
    }
    else {
      TreeSecureServicesSessionQueueQueryService(param_2);
    }
  }
  else if (param_5 == 0x568004) {
    *(undefined4 *)(lVar5 + 0x70) = 1;
    if (*(int *)(lVar1 + 4) == 3) {
      TreeSecureServicesSessionQueueExecuteDeferred(param_2);
    }
    else {
      TreeSecureServicesSessionQueueExecute(param_2);
    }
  }
  else {
    TreeCxClientProcessOtherSecureServiceIo(uVar6,pWVar3,(ulonglong)param_2);
  }
  return;
}



===== TreeSecureServicesSessionQueueExecute @ 140007138 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TreeSecureServicesSessionQueueExecute(undefined8 param_1)

{
  char cVar1;
  long lVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  WDFFILEOBJECT__ *pWVar6;
  longlong lVar7;
  undefined8 uVar8;
  undefined4 *local_res10;
  undefined8 local_res18 [2];
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  longlong lStack_40;
  undefined8 local_38;
  longlong lStack_30;
  
  local_res10 = (undefined4 *)0x0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  lStack_40 = 0;
  local_38 = 0;
  lStack_30 = 0;
  puVar5 = (undefined4 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,
                      PTR__WDF_TREE_SECURE_SERVICES_REQUEST_CONTEXT_TYPE_INFO_14000f0a0);
  pWVar6 = (WDFFILEOBJECT__ *)(**(code **)(WdfFunctions_01015 + 0x8a8))(WdfDriverGlobals,param_1);
  uVar8 = (**(code **)(WdfFunctions_01015 + 0x458))(WdfDriverGlobals,pWVar6);
  lVar7 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,pWVar6,
                     PTR__WDF_TREE_SERVICE_SESSION_CONTEXT_TYPE_INFO_14000f118);
  local_58 = *(undefined8 *)(puVar5 + 8);
  uStack_50 = *(undefined8 *)(puVar5 + 10);
  local_48 = *(undefined8 *)(puVar5 + 0xc);
  lStack_40 = *(longlong *)(puVar5 + 0xe);
  local_38 = *(undefined8 *)(puVar5 + 0x10);
  lStack_30 = *(longlong *)(puVar5 + 0x12);
  if (lStack_40 != 0) {
    local_48 = (**(code **)(WdfFunctions_01015 + 0x610))
                         (WdfDriverGlobals,*(undefined8 *)(puVar5 + 4),0);
  }
  if (lStack_30 != 0) {
    local_38 = (**(code **)(WdfFunctions_01015 + 0x610))
                         (WdfDriverGlobals,*(undefined8 *)(puVar5 + 6),0);
  }
  cVar1 = (**(code **)(WdfFunctions_01015 + 0x8c0))(WdfDriverGlobals,param_1);
  local_res18[0] = 0;
  lVar2 = TreeCxClientProcessSecureServiceRequest
                    (uVar8,pWVar6,param_1,*puVar5,&local_58,(uint)(cVar1 == '\x01'),local_res18,
                     puVar5 + 0x14);
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(lVar7 + 0x20));
  if (puVar5[0x1c] == 6) {
    (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(lVar7 + 0x20));
    (**(code **)(WdfFunctions_01015 + 0x848))
              (WdfDriverGlobals,param_1,puVar5[0x18],*(undefined8 *)(puVar5 + 0x1a));
  }
  else {
    iVar3 = (**(code **)(WdfFunctions_01015 + 0xc48))(WdfDriverGlobals,param_1);
    if (iVar3 < 0) {
      if (lVar2 == 0x103) {
        puVar5[0x1c] = 4;
        (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(lVar7 + 0x20));
        TreeSecureServicesEvtRequestCancel(param_1);
        return;
      }
      uVar4 = 5;
    }
    else {
      uVar4 = 3;
    }
    puVar5[0x1c] = uVar4;
    (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(lVar7 + 0x20));
    if (lVar2 < 0) {
      uVar8 = 0;
    }
    else {
      if (lVar2 == 0x103) {
        return;
      }
      uVar8 = 0x10;
      iVar3 = (**(code **)(WdfFunctions_01015 + 0x870))
                        (WdfDriverGlobals,param_1,0x10,&local_res10,0);
      if (iVar3 < 0) {
        uVar8 = 0;
        lVar2 = iVar3;
      }
      else {
        puVar5 = local_res10;
        for (lVar7 = 0x10; lVar7 != 0; lVar7 = lVar7 + -1) {
          *(undefined1 *)puVar5 = 0;
          puVar5 = (undefined4 *)((longlong)puVar5 + 1);
        }
        *(undefined8 *)(local_res10 + 2) = local_res18[0];
        *local_res10 = 1;
      }
    }
    TreeSecureSessionCompleteRequest(param_1,lVar2,uVar8);
  }
  return;
}



===== TreeSecureSessionCompleteRequest @ 140007448 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TreeSecureSessionCompleteRequest(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  longlong lVar4;
  longlong lVar5;
  
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x8a8))(WdfDriverGlobals,param_1);
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,
                     PTR__WDF_TREE_SECURE_SERVICES_REQUEST_CONTEXT_TYPE_INFO_14000f0a0);
  iVar2 = 0;
  if (*(longlong *)(lVar4 + 0x58) != 0) {
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,*(longlong *)(lVar4 + 0x58),0);
  }
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar3,
                     PTR__WDF_TREE_SERVICE_SESSION_CONTEXT_TYPE_INFO_14000f118);
  LOCK();
  *(undefined4 *)(lVar5 + 0x18) = 0;
  UNLOCK();
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(lVar5 + 0x20));
  iVar1 = *(int *)(lVar4 + 0x70);
  *(undefined4 *)(lVar4 + 0x70) = 6;
  *(undefined4 *)(lVar4 + 0x60) = param_2;
  *(undefined8 *)(lVar4 + 0x68) = param_3;
  if ((iVar1 == 2) || (iVar1 == 3)) {
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x800))(WdfDriverGlobals,param_1);
  }
  else if ((iVar1 == 4) || (iVar1 == 5)) {
    iVar2 = -0x3ffffee0;
  }
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(lVar5 + 0x20));
  if (iVar2 == -0x3ffffee0) {
    if (iVar1 != 5) {
      return;
    }
  }
  else if (iVar1 == 1) {
    return;
  }
  (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,param_1,param_2,param_3);
  return;
}



===== WPP_RECORDER_SF__guid_dD @ 1400075f4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF__guid_dD(undefined8 param_1)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_bdefa9cb8cda32fb69319cb0c5c251ff_Traceguids,10);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_bdefa9cb8cda32fb69319cb0c5c251ff_Traceguids,10);
  return;
}



===== WPP_RECORDER_SF_qDP @ 1400076f4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qDP(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_bdefa9cb8cda32fb69319cb0c5c251ff_Traceguids,0xb,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,8,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_bdefa9cb8cda32fb69319cb0c5c251ff_Traceguids,0xb,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,8,0);
  return;
}



===== TreeDriverServicesCompleteWork @ 1400077e8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl TreeDriverServicesCompleteWork(struct WDFREQUEST__ * __ptr64 * __ptr64,long,unsigned
   __int64) */

void __cdecl TreeDriverServicesCompleteWork(WDFREQUEST__ **param_1,long param_2,__uint64 param_3)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 uVar3;
  longlong lVar4;
  WDFREQUEST__ *local_res8;
  
  local_res8 = *param_1;
  *param_1 = (WDFREQUEST__ *)0x0;
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,local_res8,
                     PTR__WDF_TREE_DRIVER_SERVICES_REQUEST_CONTEXT_TYPE_INFO_14000f1f0);
  lVar1 = *(longlong *)(lVar4 + 0x18);
  *(undefined8 *)(lVar4 + 0x18) = 0;
  lVar2 = *(longlong *)(lVar4 + 0x20);
  uVar3 = *(undefined8 *)(lVar4 + 0x10);
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x40));
  *(uint *)(lVar4 + 0x3c) = *(uint *)(lVar4 + 0x3c) | 2;
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x40));
  if (lVar1 != 0) {
    TreeServicesCompleteSessionCall(uVar3,lVar1,param_2,param_3);
    (**(code **)(WdfFunctions_01015 + 0x670))
              (WdfDriverGlobals,lVar1,0,0x575,
               "onecore\\base\\basedrv\\tree\\treeclx\\driver\\driverservices.cxx");
  }
  TreeDriverServicesReturnRequest(&local_res8);
  return;
}



===== TreeDriverServicesCreatePluginRequest @ 1400078f8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl TreeDriverServicesCreatePluginRequest(struct WDFDEVICE__ * __ptr64,struct
   _TREE_DRIVER_SERVICES_PLUGIN * __ptr64,struct WDFREQUEST__ * __ptr64 * __ptr64,struct
   _TREE_DRIVER_SERVICES_REQUEST_CONTEXT * __ptr64 * __ptr64) */

long __cdecl
TreeDriverServicesCreatePluginRequest
          (WDFDEVICE__ *param_1,_TREE_DRIVER_SERVICES_PLUGIN *param_2,WDFREQUEST__ **param_3,
          _TREE_DRIVER_SERVICES_REQUEST_CONTEXT **param_4)

{
  int iVar1;
  undefined8 uVar2;
  _TREE_DRIVER_SERVICES_REQUEST_CONTEXT *p_Var3;
  WDFREQUEST__ *local_res10;
  longlong local_178 [2];
  code *pcStack_168;
  undefined8 local_160;
  undefined8 uStack_158;
  undefined8 local_150;
  undefined8 uStack_148;
  undefined *local_140;
  undefined8 local_138;
  undefined8 uStack_130;
  undefined8 local_128;
  undefined8 uStack_120;
  undefined8 local_118;
  undefined8 uStack_110;
  WDFREQUEST__ *local_108;
  undefined8 uStack_100;
  undefined8 local_f8;
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined4 local_b8;
  undefined4 local_b4;
  code *local_b0;
  code *local_a8;
  code *local_a0;
  undefined4 local_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 local_78;
  undefined4 local_6c;
  undefined4 local_68;
  
  memset(&local_b8,0,0x88);
  local_128 = 0;
  uStack_120 = 0;
  local_f8 = 0;
  local_118 = 0;
  uStack_110 = 0;
  local_140 = (undefined *)0x0;
  local_108 = (WDFREQUEST__ *)0x0;
  uStack_100 = 0;
  local_138 = 0;
  uStack_130 = 0;
  local_178[1] = 0;
  pcStack_168 = (code *)0x0;
  local_160 = 0;
  uStack_158 = 0;
  local_150 = 0;
  uStack_148 = 0;
  if (*(longlong *)param_2 == 0) {
    uVar2 = (**(code **)(WdfFunctions_01015 + 0x138))(WdfDriverGlobals,param_1);
    (**(code **)(WdfFunctions_01015 + 0x3b0))(WdfDriverGlobals,uVar2);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_Z_guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
    return -0x3fffff63;
  }
  local_178[0] = 0;
  local_res10 = (WDFREQUEST__ *)0x0;
  local_e0 = 0;
  local_c0 = 0;
  uStack_e8 = 0;
  local_f0 = 0x38;
  local_d0 = 0;
  uStack_c8 = 0;
  uStack_d8 = 0x100000001;
  local_d0 = (**(code **)(WdfFunctions_01015 + 0x660))(WdfDriverGlobals,param_2);
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x538))(WdfDriverGlobals,param_1,&local_f0,local_178);
  if (-1 < iVar1) {
    (**(code **)(WdfFunctions_01015 + 0x9a8))(WdfDriverGlobals,*(undefined8 *)param_2,&local_138);
    local_b0 = TreeEvtDriverServicesPluginIoTargetQueryRemove;
    local_a8 = TreeEvtDriverServicesPluginIoTargetRemoveCanceled;
    local_a0 = TreeEvtDriverServicesPluginIoTargetRemoveComplete;
    local_b8 = 0x88;
    local_b4 = 2;
    local_88 = (undefined4)local_138;
    uStack_84 = local_138._4_4_;
    uStack_80 = (undefined4)uStack_130;
    uStack_7c = uStack_130._4_4_;
    local_78 = 0x1f0000;
    local_68 = 0x40;
    local_6c = 1;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x540))(WdfDriverGlobals,local_178[0],&local_b8);
    if (-1 < iVar1) {
      local_160 = 0;
      uStack_148 = 0;
      local_140 = PTR__WDF_TREE_DRIVER_SERVICES_REQUEST_CONTEXT_TYPE_INFO_14000f1f0;
      local_178[1] = 0x38;
      uStack_158 = 0x100000001;
      local_150 = (**(code **)(WdfFunctions_01015 + 0x660))(WdfDriverGlobals,param_2);
      pcStack_168 = TreeEvtDriverServicesRequestContextCleanupCallback;
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x7b8))
                        (WdfDriverGlobals,local_178 + 1,local_178[0],&local_res10);
      if (-1 < iVar1) {
        p_Var3 = (_TREE_DRIVER_SERVICES_REQUEST_CONTEXT *)
                 (**(code **)(WdfFunctions_01015 + 0x650))
                           (WdfDriverGlobals,local_res10,
                            PTR__WDF_TREE_DRIVER_SERVICES_REQUEST_CONTEXT_TYPE_INFO_14000f1f0);
        *(WDFDEVICE__ **)(p_Var3 + 0x10) = param_1;
        *(_TREE_DRIVER_SERVICES_PLUGIN **)(p_Var3 + 0x20) = param_2;
        *(undefined4 *)(p_Var3 + 0x28) = *(undefined4 *)(param_2 + 0x34);
        local_108 = local_res10;
        local_128 = CONCAT44(local_128._4_4_,0x38);
        uStack_110 = 0x100000001;
        iVar1 = (**(code **)(WdfFunctions_01015 + 0x600))
                          (WdfDriverGlobals,&local_128,0x200,0x45457254,0x30,p_Var3,0);
        if (-1 < iVar1) {
          iVar1 = (**(code **)(WdfFunctions_01015 + 0x600))
                            (WdfDriverGlobals,&local_128,0x200,0x45457254,0x10,p_Var3 + 8,0);
          if ((-1 < iVar1) &&
             (iVar1 = (**(code **)(WdfFunctions_01015 + 0x5d8))
                                (WdfDriverGlobals,local_178[0],local_res10,0x568004,
                                 *(undefined8 *)p_Var3,0,*(undefined8 *)(p_Var3 + 8),0), -1 < iVar1)
             ) {
            *(longlong *)(p_Var3 + 0x30) = local_178[0];
            goto LAB_140007d19;
          }
        }
      }
    }
  }
  p_Var3 = (_TREE_DRIVER_SERVICES_REQUEST_CONTEXT *)0x0;
  if (local_res10 == (WDFREQUEST__ *)0x0) {
    if (local_178[0] != 0) {
      (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
    }
  }
  else {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,local_res10);
    local_res10 = (WDFREQUEST__ *)0x0;
  }
LAB_140007d19:
  *param_3 = local_res10;
  if (param_4 != (_TREE_DRIVER_SERVICES_REQUEST_CONTEXT **)0x0) {
    *param_4 = p_Var3;
  }
  return iVar1;
}



===== TreeDriverServicesFindPlugin @ 140007d4c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* unsigned char __cdecl TreeDriverServicesFindPlugin(struct _TREE_DRIVER_SERVICES_CONTEXT *
   __ptr64,struct _UNICODE_STRING const * __ptr64,struct _GUID const * __ptr64,void * __ptr64 *
   __ptr64,struct _TREE_DRIVER_SERVICES_PLUGIN * __ptr64 * __ptr64) */

uchar __cdecl
TreeDriverServicesFindPlugin
          (_TREE_DRIVER_SERVICES_CONTEXT *param_1,_UNICODE_STRING *param_2,_GUID *param_3,
          void **param_4,_TREE_DRIVER_SERVICES_PLUGIN **param_5)

{
  uchar uVar1;
  
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,*(undefined8 *)(param_1 + 8),0);
  uVar1 = TreeDriverServicesFindPluginLockHeld(param_1,param_2,param_3,param_4,param_5);
  (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,*(undefined8 *)(param_1 + 8));
  return uVar1;
}



===== TreeDriverServicesFindPluginLockHeld @ 140007de8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* unsigned char __cdecl TreeDriverServicesFindPluginLockHeld(struct _TREE_DRIVER_SERVICES_CONTEXT *
   __ptr64,struct _UNICODE_STRING const * __ptr64,struct _GUID const * __ptr64,void * __ptr64 *
   __ptr64,struct _TREE_DRIVER_SERVICES_PLUGIN * __ptr64 * __ptr64) */

uchar __cdecl
TreeDriverServicesFindPluginLockHeld
          (_TREE_DRIVER_SERVICES_CONTEXT *param_1,_UNICODE_STRING *param_2,_GUID *param_3,
          void **param_4,_TREE_DRIVER_SERVICES_PLUGIN **param_5)

{
  char cVar1;
  uint uVar2;
  void *pvVar3;
  _TREE_DRIVER_SERVICES_PLUGIN *p_Var4;
  uint uVar5;
  undefined8 local_38;
  undefined8 uStack_30;
  
  *param_4 = (void *)0x0;
  local_38 = 0;
  uStack_30 = 0;
  if (param_5 != (_TREE_DRIVER_SERVICES_PLUGIN **)0x0) {
    *param_5 = (_TREE_DRIVER_SERVICES_PLUGIN *)0x0;
  }
  uVar5 = 0;
  do {
    uVar2 = (**(code **)(WdfFunctions_01015 + 0x70))
                      (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x10));
    if (uVar2 <= uVar5) {
      return '\0';
    }
    pvVar3 = (void *)(**(code **)(WdfFunctions_01015 + 0x90))
                               (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x10),uVar5);
    p_Var4 = (_TREE_DRIVER_SERVICES_PLUGIN *)
             (**(code **)(WdfFunctions_01015 + 0x650))
                       (WdfDriverGlobals,pvVar3,
                        PTR__WDF_TREE_DRIVER_SERVICES_PLUGIN_TYPE_INFO_14000f218);
    if ((param_3 == (_GUID *)0x0) ||
       ((*(longlong *)param_3 == *(longlong *)(p_Var4 + 8) &&
        (*(longlong *)(param_3 + 8) == *(longlong *)(p_Var4 + 0x10))))) {
      if ((*(longlong *)p_Var4 == 0) || (param_2 == (_UNICODE_STRING *)0x0)) {
LAB_140007f0e:
        (**(code **)(WdfFunctions_01015 + 0x668))
                  (WdfDriverGlobals,pvVar3,0,0x181,
                   "onecore\\base\\basedrv\\tree\\treeclx\\driver\\driverservices.cxx");
        *param_4 = pvVar3;
        if (param_5 == (_TREE_DRIVER_SERVICES_PLUGIN **)0x0) {
          return '\x01';
        }
        *param_5 = p_Var4;
        return '\x01';
      }
      (**(code **)(WdfFunctions_01015 + 0x9a8))(WdfDriverGlobals,*(longlong *)p_Var4,&local_38);
      cVar1 = RtlEqualUnicodeString(param_2,&local_38,1);
      if (cVar1 != '\0') goto LAB_140007f0e;
    }
    uVar5 = uVar5 + 1;
  } while( true );
}



===== TreeDriverServicesGetRequest @ 140007f78 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl TreeDriverServicesGetRequest(struct WDFDEVICE__ * __ptr64,void * __ptr64,struct
   WDFREQUEST__ * __ptr64 * __ptr64) */

long __cdecl TreeDriverServicesGetRequest(WDFDEVICE__ *param_1,void *param_2,WDFREQUEST__ **param_3)

{
  int iVar1;
  int iVar2;
  _TREE_DRIVER_SERVICES_PLUGIN *p_Var3;
  WDFREQUEST__ *pWVar4;
  longlong lVar5;
  WDFREQUEST__ *local_res20;
  
  p_Var3 = (_TREE_DRIVER_SERVICES_PLUGIN *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_2,
                      PTR__WDF_TREE_DRIVER_SERVICES_PLUGIN_TYPE_INFO_14000f218);
  pWVar4 = (WDFREQUEST__ *)0x0;
  iVar2 = -0x3ffffddb;
  local_res20 = (WDFREQUEST__ *)0x0;
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(p_Var3 + 0x40));
  do {
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x70))
                      (WdfDriverGlobals,*(undefined8 *)(p_Var3 + 0x48));
    if (iVar1 == 0) break;
    pWVar4 = (WDFREQUEST__ *)
             (**(code **)(WdfFunctions_01015 + 0x98))
                       (WdfDriverGlobals,*(undefined8 *)(p_Var3 + 0x48));
    (**(code **)(WdfFunctions_01015 + 0x80))(WdfDriverGlobals,*(undefined8 *)(p_Var3 + 0x48),pWVar4)
    ;
    (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(p_Var3 + 0x40));
    lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,pWVar4,
                       PTR__WDF_TREE_DRIVER_SERVICES_REQUEST_CONTEXT_TYPE_INFO_14000f1f0);
    if (*(int *)(lVar5 + 0x28) == *(int *)(p_Var3 + 0x34)) {
      iVar2 = 0;
    }
    else {
      (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,pWVar4);
    }
    (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(p_Var3 + 0x40));
  } while (iVar2 == -0x3ffffddb);
  local_res20 = pWVar4;
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(p_Var3 + 0x40));
  if (iVar2 == -0x3ffffddb) {
    iVar2 = TreeDriverServicesCreatePluginRequest
                      (param_1,p_Var3,&local_res20,(_TREE_DRIVER_SERVICES_REQUEST_CONTEXT **)0x0);
    pWVar4 = local_res20;
  }
  if (-1 < iVar2) {
    (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(p_Var3 + 0x40));
    if (p_Var3[0x30] == (_TREE_DRIVER_SERVICES_PLUGIN)0x0) {
      (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(p_Var3 + 0x40));
      (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,pWVar4);
      iVar2 = -0x3fffff63;
    }
    else {
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x78))
                        (WdfDriverGlobals,*(undefined8 *)(p_Var3 + 0x50),pWVar4);
      (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(p_Var3 + 0x40));
      *param_3 = pWVar4;
      iVar2 = 0;
      if (-1 < iVar1) {
        iVar2 = iVar1;
      }
    }
  }
  return iVar2;
}



===== TreeDriverServicesPluginAvailable @ 1400081e4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl TreeDriverServicesPluginAvailable(struct WDFDEVICE__ * __ptr64,void * __ptr64,struct
   _UNICODE_STRING const * __ptr64) */

long __cdecl
TreeDriverServicesPluginAvailable(WDFDEVICE__ *param_1,void *param_2,_UNICODE_STRING *param_3)

{
  _TREE_DRIVER_SERVICES_PLUGIN *p_Var1;
  _TREE_DRIVER_SERVICES_REQUEST_CONTEXT *p_Var2;
  int iVar3;
  _TREE_DRIVER_SERVICES_PLUGIN *p_Var4;
  undefined8 uVar5;
  void *pvVar6;
  undefined *puVar7;
  WDFREQUEST__ *pWVar8;
  undefined1 auStackY_1a8 [32];
  undefined8 in_stack_fffffffffffffe78;
  WDFREQUEST__ *local_138;
  _TREE_DRIVER_SERVICES_REQUEST_CONTEXT *local_130;
  ulonglong local_128;
  ushort local_120 [4];
  undefined1 *local_118;
  undefined8 local_110;
  _TREE_DRIVER_SERVICES_PLUGIN *p_Stack_108;
  undefined8 local_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  void *local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined1 local_b8 [112];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_1a8;
  local_120[0] = 0;
  local_120[1] = 100;
  local_120[2] = 0;
  local_120[3] = 0;
  local_118 = local_b8;
  local_128 = 0;
  local_130 = (_TREE_DRIVER_SERVICES_REQUEST_CONTEXT *)0x0;
  local_100 = 0;
  local_110 = 0;
  p_Stack_108 = (_TREE_DRIVER_SERVICES_PLUGIN *)0x0;
  local_138 = (WDFREQUEST__ *)0x0;
  pvVar6 = param_2;
  puVar7 = PTR__WDF_TREE_DRIVER_SERVICES_PLUGIN_TYPE_INFO_14000f218;
  p_Var4 = (_TREE_DRIVER_SERVICES_PLUGIN *)
           (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF__guid_Z
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pvVar6,puVar7,0xb,
               in_stack_fffffffffffffe78,p_Var4 + 8,(wchar_t *)param_3);
  }
  local_e8 = 0;
  local_c8 = 0;
  uStack_f0 = 0;
  local_f8 = 0x38;
  uStack_d0 = 0;
  uStack_e0 = 0x100000001;
  local_d8 = param_2;
  iVar3 = (**(code **)(WdfFunctions_01015 + 0x9a0))(WdfDriverGlobals,param_3,&local_f8,p_Var4);
  if (iVar3 < 0) {
    return iVar3;
  }
  iVar3 = TreeDriverServicesCreatePluginRequest(param_1,p_Var4,&local_138,&local_130);
  p_Var2 = local_130;
  if (-1 < iVar3) {
    *(undefined8 *)(p_Var4 + 0x1c) = 0;
    p_Var1 = p_Var4 + 0x18;
    *(undefined4 *)p_Var1 = 1;
    if (*(code **)(p_Var4 + 0x60) != (code *)0x0) {
      (**(code **)(p_Var4 + 0x60))(param_2,*(undefined8 *)(local_130 + 0x30),p_Var1);
LAB_140008340:
      (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(p_Var4 + 0x40));
      pWVar8 = local_138;
      iVar3 = (**(code **)(WdfFunctions_01015 + 0x78))
                        (WdfDriverGlobals,*(undefined8 *)(p_Var4 + 0x48),local_138);
      *(int *)(p_Var4 + 0x34) = *(int *)(p_Var4 + 0x34) + 1;
      p_Var4[0x30] = (_TREE_DRIVER_SERVICES_PLUGIN)((byte)((uint)iVar3 >> 0x1f) ^ 1);
      (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(p_Var4 + 0x40));
      if (-1 < iVar3) {
        uVar5 = RtlUnicodeStringPrintf
                          (local_120,L"{%08lx-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x}",
                           (ulonglong)*(uint *)(p_Var4 + 8),(ulonglong)*(ushort *)(p_Var4 + 0xc));
        if ((int)uVar5 < 0) {
          return (int)uVar5;
        }
        uVar5 = (**(code **)(WdfFunctions_01015 + 0x598))
                          (WdfDriverGlobals,*(undefined8 *)(p_Var2 + 0x30));
        iVar3 = IoResolveDependency(local_120,uVar5);
        pWVar8 = (WDFREQUEST__ *)0x0;
      }
      goto LAB_1400084d3;
    }
    local_110 = 1;
    local_100 = 0xc;
    p_Stack_108 = p_Var1;
    iVar3 = (**(code **)(WdfFunctions_01015 + 0x5e0))
                      (WdfDriverGlobals,*(undefined8 *)(local_130 + 0x30),0,0x560000);
    if (-1 < iVar3) {
      if (0xb < local_128) goto LAB_140008340;
      iVar3 = -0x3fffffff;
    }
  }
  pWVar8 = local_138;
LAB_1400084d3:
  if (pWVar8 != (WDFREQUEST__ *)0x0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,pWVar8);
  }
  return iVar3;
}



===== TreeDriverServicesPluginUnavailable @ 140008528 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl TreeDriverServicesPluginUnavailable(struct WDFDEVICE__ * __ptr64,void *
   __ptr64,struct _UNICODE_STRING const * __ptr64) */

long __cdecl
TreeDriverServicesPluginUnavailable(WDFDEVICE__ *param_1,void *param_2,_UNICODE_STRING *param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  longlong *plVar4;
  undefined8 uVar5;
  longlong lVar6;
  longlong lVar7;
  undefined8 *puVar8;
  longlong local_res20;
  undefined8 in_stack_ffffffffffffffb8;
  undefined8 local_28;
  undefined8 uStack_20;
  
  local_res20 = 0;
  lVar7 = 0;
  local_28 = 0;
  uStack_20 = 0;
  plVar4 = (longlong *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_2,
                      PTR__WDF_TREE_DRIVER_SERVICES_PLUGIN_TYPE_INFO_14000f218);
  puVar8 = &local_28;
  lVar6 = *plVar4;
  (**(code **)(WdfFunctions_01015 + 0x9a8))(WdfDriverGlobals);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF__guid_Z
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar6,puVar8,0xc,in_stack_ffffffffffffffb8
               ,plVar4 + 1,(wchar_t *)param_3);
  }
  cVar1 = RtlEqualUnicodeString(param_3,&local_28,1);
  if (cVar1 == '\0') {
    iVar2 = 0;
  }
  else {
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x68))(WdfDriverGlobals,0,&local_res20);
    if (iVar2 < 0) {
      local_res20 = 0;
    }
    (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,plVar4[8]);
    if ((char)plVar4[6] != '\0') {
      *(undefined1 *)(plVar4 + 6) = 0;
      lVar7 = *plVar4;
      *plVar4 = 0;
      if (local_res20 != 0) {
        while( true ) {
          iVar3 = (**(code **)(WdfFunctions_01015 + 0x70))(WdfDriverGlobals,plVar4[0xb]);
          if (iVar3 == 0) break;
          uVar5 = (**(code **)(WdfFunctions_01015 + 0x98))(WdfDriverGlobals,plVar4[0xb]);
          iVar2 = (**(code **)(WdfFunctions_01015 + 0x78))(WdfDriverGlobals,local_res20,uVar5);
          if (iVar2 < 0) break;
          (**(code **)(WdfFunctions_01015 + 0x88))(WdfDriverGlobals,plVar4[0xb],0);
        }
      }
    }
    (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,plVar4[8]);
    if (local_res20 != 0) {
      while( true ) {
        iVar3 = (**(code **)(WdfFunctions_01015 + 0x70))(WdfDriverGlobals,local_res20);
        if (iVar3 == 0) break;
        uVar5 = (**(code **)(WdfFunctions_01015 + 0x98))();
        TreeServicesCompleteSessionCall(param_1,uVar5,0xc000009d,0);
        (**(code **)(WdfFunctions_01015 + 0x88))(WdfDriverGlobals,local_res20,0);
      }
      (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,local_res20);
    }
    if (lVar7 != 0) {
      (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,lVar7);
    }
  }
  return iVar2;
}



===== TreeDriverServicesRegisterNewPlugin @ 1400087c4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl TreeDriverServicesRegisterNewPlugin(struct WDFDEVICE__ * __ptr64,struct
   _TREE_DRIVER_SERVICES_CONTEXT * __ptr64,struct _GUID const * __ptr64) */

long __cdecl
TreeDriverServicesRegisterNewPlugin
          (WDFDEVICE__ *param_1,_TREE_DRIVER_SERVICES_CONTEXT *param_2,_GUID *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uchar uVar4;
  int iVar5;
  longlong lVar6;
  longlong *plVar7;
  undefined8 uVar8;
  longlong local_res20;
  void *local_f8;
  undefined8 local_f0;
  code *pcStack_e8;
  ulonglong local_e0;
  undefined4 local_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined4 local_c8;
  undefined4 uStack_c4;
  undefined8 uStack_c0;
  WDFDEVICE__ *local_b8;
  undefined8 uStack_b0;
  undefined *local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  longlong local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined4 local_68;
  undefined8 local_64;
  undefined8 uStack_5c;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined8 local_48;
  undefined8 local_40;
  undefined *local_38;
  
  local_68 = 0x38;
  local_70 = 0;
  local_a8 = (undefined *)0x0;
  local_e0 = 0;
  local_res20 = 0;
  local_50 = 1;
  local_4c = 1;
  local_38 = PTR__WDF_TREE_DRIVER_SERVICES_PLUGIN_TYPE_INFO_14000f218;
  local_a0 = 0;
  uStack_98 = 0;
  local_54 = 0;
  local_90 = 0;
  uStack_88 = 0;
  local_40 = 0;
  local_80 = 0;
  uStack_78 = 0;
  local_f8 = (void *)0x0;
  local_d8 = 0;
  uStack_d4 = 0;
  uStack_d0 = 0;
  uStack_cc = 0;
  local_c8 = 0;
  uStack_c4 = 0;
  uStack_c0 = 0;
  local_b8 = (WDFDEVICE__ *)0x0;
  uStack_b0 = 0;
  local_f0 = 0;
  pcStack_e8 = (code *)0x0;
  local_64 = 0;
  uStack_5c = 0;
  local_48 = (**(code **)(WdfFunctions_01015 + 0x660))(WdfDriverGlobals);
  iVar5 = (**(code **)(WdfFunctions_01015 + 0x678))(WdfDriverGlobals,&local_68,&local_res20);
  if (-1 < iVar5) {
    lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,local_res20,
                       PTR__WDF_TREE_DRIVER_SERVICES_PLUGIN_TYPE_INFO_14000f218);
    uVar1 = *(undefined4 *)(param_3 + 4);
    uVar2 = *(undefined4 *)(param_3 + 8);
    uVar3 = *(undefined4 *)(param_3 + 0xc);
    *(undefined4 *)(lVar6 + 8) = *(undefined4 *)param_3;
    *(undefined4 *)(lVar6 + 0xc) = uVar1;
    *(undefined4 *)(lVar6 + 0x10) = uVar2;
    *(undefined4 *)(lVar6 + 0x14) = uVar3;
    *(undefined4 *)(lVar6 + 0x34) = 0;
    local_80 = local_res20;
    local_a0 = CONCAT44(local_a0._4_4_,0x38);
    uStack_88 = 0x100000001;
    iVar5 = (**(code **)(WdfFunctions_01015 + 0x9d8))(WdfDriverGlobals,&local_a0,lVar6 + 0x40);
    if ((((-1 < iVar5) &&
         (iVar5 = (**(code **)(WdfFunctions_01015 + 0x68))(WdfDriverGlobals,&local_a0,lVar6 + 0x48),
         -1 < iVar5)) &&
        (iVar5 = (**(code **)(WdfFunctions_01015 + 0x68))(WdfDriverGlobals,&local_a0,lVar6 + 0x50),
        -1 < iVar5)) &&
       (iVar5 = (**(code **)(WdfFunctions_01015 + 0x68))(WdfDriverGlobals,&local_a0,lVar6 + 0x58),
       -1 < iVar5)) {
      if ((*(longlong *)param_3 == 0x4d07bcc327447c21) &&
         (*(longlong *)(param_3 + 8) == -0x18114ba4c65ca460)) {
        *(code **)(lVar6 + 0x60) = TreeRPMBPluginInitialize;
        *(code **)(lVar6 + 0x68) = TreeRPMBPluginHandler;
      }
      pcStack_e8 = TreeEvtPluginProcessQueue;
      local_f0 = CONCAT44(local_f0._4_4_,0x18);
      uStack_c0 = 0x100000001;
      local_a8 = PTR__WDF_TREE_PLUGIN_QUEUE_WORK_ITEM_CONTEXT_TYPE_INFO_14000f240;
      local_e0 = local_e0 & 0xffffffffffffff00;
      uStack_d4 = 0;
      uStack_d0 = 0;
      uStack_cc = 0;
      local_c8 = 0;
      uStack_c4 = 0;
      uStack_b0 = 0;
      local_d8 = 0x38;
      local_b8 = param_1;
      iVar5 = (**(code **)(WdfFunctions_01015 + 0xbd8))
                        (WdfDriverGlobals,&local_f0,&local_d8,lVar6 + 0x38);
      if (-1 < iVar5) {
        plVar7 = (longlong *)
                 (**(code **)(WdfFunctions_01015 + 0x650))
                           (WdfDriverGlobals,*(undefined8 *)(lVar6 + 0x38),
                            PTR__WDF_TREE_PLUGIN_QUEUE_WORK_ITEM_CONTEXT_TYPE_INFO_14000f240);
        *plVar7 = local_res20;
        (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,*(undefined8 *)(param_2 + 8),0);
        uVar4 = TreeDriverServicesFindPluginLockHeld
                          (param_2,(_UNICODE_STRING *)0x0,param_3,&local_f8,
                           (_TREE_DRIVER_SERVICES_PLUGIN **)0x0);
        if (uVar4 == '\0') {
          iVar5 = (**(code **)(WdfFunctions_01015 + 0x78))
                            (WdfDriverGlobals,*(undefined8 *)(param_2 + 0x10),local_res20);
          (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,*(undefined8 *)(param_2 + 8));
          if (-1 < iVar5) {
            uVar8 = (**(code **)(WdfFunctions_01015 + 0x138))(WdfDriverGlobals,param_1);
            uVar8 = (**(code **)(WdfFunctions_01015 + 0x3b0))(WdfDriverGlobals,uVar8);
            iVar5 = IoRegisterPlugPlayNotification
                              (2,1,lVar6 + 8,uVar8,TreeDriverServicesUpdate,param_1,lVar6 + 0x28);
            if (-1 < iVar5) {
              return iVar5;
            }
          }
        }
        else {
          (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,*(undefined8 *)(param_2 + 8));
          (**(code **)(WdfFunctions_01015 + 0x670))
                    (WdfDriverGlobals,local_f8,0,0x333,
                     "onecore\\base\\basedrv\\tree\\treeclx\\driver\\driverservices.cxx");
          iVar5 = -0x3ffff8e8;
        }
      }
    }
  }
  if (local_res20 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
  return iVar5;
}



===== TreeDriverServicesReturnRequest @ 140008c0c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl TreeDriverServicesReturnRequest(struct WDFREQUEST__ * __ptr64 * __ptr64) */

void __cdecl TreeDriverServicesReturnRequest(WDFREQUEST__ **param_1)

{
  longlong lVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  longlong lVar6;
  WDFREQUEST__ *pWVar7;
  undefined8 uVar8;
  uint uVar9;
  uint uVar10;
  WDFREQUEST__ *pWVar11;
  uint uVar12;
  undefined8 local_res10;
  longlong local_res18;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined8 local_4c;
  undefined4 local_44;
  
  local_res10 = 0;
  iVar5 = 0;
  pWVar11 = *param_1;
  lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,pWVar11,
                     PTR__WDF_TREE_DRIVER_SERVICES_REQUEST_CONTEXT_TYPE_INFO_14000f1f0);
  lVar1 = *(longlong *)(lVar6 + 0x20);
  local_res18 = lVar6;
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(lVar1 + 0x40));
  uVar9 = (**(code **)(WdfFunctions_01015 + 0x70))(WdfDriverGlobals,*(undefined8 *)(lVar1 + 0x50));
  uVar10 = 0;
  if (uVar9 != 0) {
    do {
      pWVar7 = (WDFREQUEST__ *)
               (**(code **)(WdfFunctions_01015 + 0x90))
                         (WdfDriverGlobals,*(undefined8 *)(lVar1 + 0x50),uVar10);
      if (pWVar7 == pWVar11) {
        (**(code **)(WdfFunctions_01015 + 0x88))
                  (WdfDriverGlobals,*(undefined8 *)(lVar1 + 0x50),uVar10);
        break;
      }
      uVar10 = uVar10 + 1;
    } while (uVar10 < uVar9);
  }
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(lVar1 + 0x40));
  *(undefined4 *)(lVar6 + 0x3c) = 0;
  bVar3 = false;
  bVar2 = false;
  local_4c = 0;
  local_44 = 0;
  local_54 = 0;
  local_50 = 0;
  local_58 = 0x18;
  do {
    if (!bVar2) {
      iVar5 = (**(code **)(WdfFunctions_01015 + 0x7c8))(WdfDriverGlobals,pWVar11,&local_58);
      bVar2 = bVar3;
      if (-1 < iVar5) {
        bVar2 = true;
        bVar3 = true;
      }
    }
    (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(lVar1 + 0x40));
    if ((*(char *)(lVar1 + 0x30) == '\0') || (*(int *)(lVar6 + 0x28) != *(int *)(lVar1 + 0x34))) {
      (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(lVar1 + 0x40));
      return;
    }
    bVar4 = true;
    uVar9 = (**(code **)(WdfFunctions_01015 + 0x70))(WdfDriverGlobals,*(undefined8 *)(lVar1 + 0x48))
    ;
    uVar10 = 0;
    if (uVar9 != 0) {
      do {
        uVar8 = (**(code **)(WdfFunctions_01015 + 0x90))
                          (WdfDriverGlobals,*(undefined8 *)(lVar1 + 0x48),uVar10);
        lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))
                          (WdfDriverGlobals,uVar8,
                           PTR__WDF_TREE_DRIVER_SERVICES_REQUEST_CONTEXT_TYPE_INFO_14000f1f0);
        if (*(int *)(lVar6 + 0x28) == *(int *)(lVar1 + 0x34)) {
          bVar4 = false;
          break;
        }
        uVar10 = uVar10 + 1;
      } while (uVar10 < uVar9);
    }
    uVar10 = (**(code **)(WdfFunctions_01015 + 0x70))
                       (WdfDriverGlobals,*(undefined8 *)(lVar1 + 0x50));
    uVar12 = 0;
    if (bVar4) {
      for (; uVar12 < uVar10; uVar12 = uVar12 + 1) {
        uVar8 = (**(code **)(WdfFunctions_01015 + 0x90))
                          (WdfDriverGlobals,*(undefined8 *)(lVar1 + 0x50),uVar12);
        lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))
                          (WdfDriverGlobals,uVar8,
                           PTR__WDF_TREE_DRIVER_SERVICES_REQUEST_CONTEXT_TYPE_INFO_14000f1f0);
        if (*(int *)(lVar6 + 0x28) == *(int *)(lVar1 + 0x34)) {
          bVar4 = false;
          break;
        }
      }
    }
    if ((bVar2) &&
       (iVar5 = (**(code **)(WdfFunctions_01015 + 0x78))
                          (WdfDriverGlobals,*(undefined8 *)(lVar1 + 0x48),pWVar11), -1 < iVar5)) {
      pWVar11 = (WDFREQUEST__ *)0x0;
      uVar9 = uVar9 + 1;
      *param_1 = (WDFREQUEST__ *)0x0;
      bVar4 = false;
    }
    (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(lVar1 + 0x40));
    if (((iVar5 < 0) && (uVar9 == 0)) && (uVar10 == 0)) {
      local_res10 = 0xfffffffffd050f80;
      KeDelayExecutionThread(0,0,&local_res10);
    }
    else if (!bVar4) {
      return;
    }
    lVar6 = local_res18;
  } while( true );
}



===== TreeDriverServicesSendRequest @ 140008f8c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl TreeDriverServicesSendRequest(struct WDFREQUEST__ * __ptr64,void * __ptr64) */

void __cdecl TreeDriverServicesSendRequest(WDFREQUEST__ *param_1,void *param_2)

{
  int iVar1;
  longlong lVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  char cVar7;
  long lVar8;
  undefined8 *puVar9;
  longlong lVar10;
  undefined8 *puVar11;
  WDFREQUEST__ *local_res8;
  
  local_res8 = param_1;
  puVar9 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,
                      PTR__WDF_TREE_DRIVER_SERVICES_REQUEST_CONTEXT_TYPE_INFO_14000f1f0);
  lVar2 = puVar9[4];
  lVar10 = (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_2,PTR__WDF_TREE_SESSION_CALL_DATA_TYPE_INFO_14000f0c8);
  (**(code **)(WdfFunctions_01015 + 0x668))
            (WdfDriverGlobals,param_2,0,0x5ac,
             "onecore\\base\\basedrv\\tree\\treeclx\\driver\\driverservices.cxx");
  puVar9[3] = param_2;
  puVar11 = (undefined8 *)(**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,*puVar9,0);
  uVar6 = *(undefined8 *)(lVar10 + 0x18);
  *puVar11 = *(undefined8 *)(lVar10 + 0x10);
  puVar11[1] = uVar6;
  uVar3 = *(undefined4 *)(lVar10 + 0x24);
  uVar4 = *(undefined4 *)(lVar10 + 0x28);
  uVar5 = *(undefined4 *)(lVar10 + 0x2c);
  *(undefined4 *)(puVar11 + 2) = *(undefined4 *)(lVar10 + 0x20);
  *(undefined4 *)((longlong)puVar11 + 0x14) = uVar3;
  *(undefined4 *)(puVar11 + 3) = uVar4;
  *(undefined4 *)((longlong)puVar11 + 0x1c) = uVar5;
  uVar3 = *(undefined4 *)(lVar10 + 0x34);
  uVar4 = *(undefined4 *)(lVar10 + 0x38);
  uVar5 = *(undefined4 *)(lVar10 + 0x3c);
  *(undefined4 *)(puVar11 + 4) = *(undefined4 *)(lVar10 + 0x30);
  *(undefined4 *)((longlong)puVar11 + 0x24) = uVar3;
  *(undefined4 *)(puVar11 + 5) = uVar4;
  *(undefined4 *)((longlong)puVar11 + 0x2c) = uVar5;
  lVar8 = (**(code **)(WdfFunctions_01015 + 0x5e8))
                    (WdfDriverGlobals,puVar9[6],param_1,0x568004,*puVar9,0,puVar9[1],0);
  if (-1 < lVar8) {
    (**(code **)(WdfFunctions_01015 + 0x820))
              (WdfDriverGlobals,param_1,TreeEvtDriverServicesRequestCompletionCallback,0);
    (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x40));
    iVar1 = *(int *)(puVar9 + 7);
    *(int *)(puVar9 + 7) = iVar1 + 1;
    (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x40));
    cVar7 = (**(code **)(WdfFunctions_01015 + 0x7e8))(WdfDriverGlobals,param_1,puVar9[6],0);
    if (cVar7 != '\0') {
      (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x40));
      if ((iVar1 + 1 == *(int *)(puVar9 + 7)) &&
         (*(uint *)((longlong)puVar9 + 0x3c) = *(uint *)((longlong)puVar9 + 0x3c) | 1,
         (*(uint *)((longlong)puVar9 + 0x3c) & 4) != 0)) {
        (**(code **)(WdfFunctions_01015 + 0x810))(WdfDriverGlobals,param_1);
      }
      (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x40));
      return;
    }
    lVar8 = (**(code **)(WdfFunctions_01015 + 0x7f0))(WdfDriverGlobals,param_1);
  }
  TreeDriverServicesCompleteWork(&local_res8,lVar8,0);
  return;
}



===== TreeDriverServicesUpdate @ 1400091f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl TreeDriverServicesUpdate(void * __ptr64,void * __ptr64) */

long __cdecl TreeDriverServicesUpdate(void *param_1,void *param_2)

{
  uchar uVar1;
  _TREE_DRIVER_SERVICES_CONTEXT *p_Var2;
  void *local_res8;
  
  local_res8 = (void *)0x0;
  p_Var2 = (_TREE_DRIVER_SERVICES_CONTEXT *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_2,
                      PTR__WDF_TREE_DRIVER_SERVICES_CONTEXT_TYPE_INFO_14000f268);
  uVar1 = TreeDriverServicesFindPlugin
                    (p_Var2,*(_UNICODE_STRING **)((longlong)param_1 + 0x28),
                     (_GUID *)((longlong)param_1 + 0x14),&local_res8,
                     (_TREE_DRIVER_SERVICES_PLUGIN **)0x0);
  if (uVar1 != '\0') {
    if ((*(longlong *)((longlong)param_1 + 4) == 0x11d046f0cb3a4004) &&
       (*(longlong *)((longlong)param_1 + 0xc) == 0x3f05139760008fb0)) {
      TreeDriverServicesPluginAvailable
                (param_2,local_res8,*(_UNICODE_STRING **)((longlong)param_1 + 0x28));
    }
    else if ((*(longlong *)((longlong)param_1 + 4) == 0x11d046f0cb3a4005) &&
            (*(longlong *)((longlong)param_1 + 0xc) == 0x3f05139760008fb0)) {
      TreeDriverServicesPluginUnavailable
                (param_2,local_res8,*(_UNICODE_STRING **)((longlong)param_1 + 0x28));
    }
  }
  if (local_res8 != (void *)0x0) {
    (**(code **)(WdfFunctions_01015 + 0x670))
              (WdfDriverGlobals,local_res8,0,0x4ce,
               "onecore\\base\\basedrv\\tree\\treeclx\\driver\\driverservices.cxx");
  }
  return 0;
}



===== TreeEvtDriverServicesContextCleanupCallback @ 1400092f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl TreeEvtDriverServicesContextCleanupCallback(void * __ptr64) */

void __cdecl TreeEvtDriverServicesContextCleanupCallback(void *param_1)

{
  bool bVar1;
  char cVar2;
  uint uVar3;
  longlong lVar4;
  undefined8 uVar5;
  longlong lVar6;
  uint uVar7;
  
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,
                     PTR__WDF_TREE_DRIVER_SERVICES_CONTEXT_TYPE_INFO_14000f268);
  do {
    bVar1 = false;
    (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,*(undefined8 *)(lVar4 + 8),0);
    uVar7 = 0;
    while( true ) {
      uVar3 = (**(code **)(WdfFunctions_01015 + 0x70))
                        (WdfDriverGlobals,*(undefined8 *)(lVar4 + 0x10));
      if (uVar3 <= uVar7) break;
      uVar5 = (**(code **)(WdfFunctions_01015 + 0x90))
                        (WdfDriverGlobals,*(undefined8 *)(lVar4 + 0x10),uVar7);
      lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,uVar5);
      if (*(longlong *)(lVar6 + 0x28) != 0) {
        (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,*(undefined8 *)(lVar4 + 8));
        cVar2 = KeGetCurrentIrql();
        if (cVar2 == '\0') {
          IoUnregisterPlugPlayNotification(*(undefined8 *)(lVar6 + 0x28));
        }
        *(undefined8 *)(lVar6 + 0x28) = 0;
        bVar1 = true;
        (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,*(undefined8 *)(lVar4 + 8));
        break;
      }
      uVar7 = uVar7 + 1;
    }
    (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,*(undefined8 *)(lVar4 + 8));
    if (!bVar1) {
      return;
    }
  } while( true );
}



===== TreeEvtDriverServicesPluginIoTargetQueryRemove @ 140009480 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl TreeEvtDriverServicesPluginIoTargetQueryRemove(struct WDFIOTARGET__ * __ptr64) */

long __cdecl TreeEvtDriverServicesPluginIoTargetQueryRemove(WDFIOTARGET__ *param_1)

{
  (**(code **)(WdfFunctions_01015 + 0x548))(WdfDriverGlobals,param_1);
  return -0x3fffffff;
}



===== TreeEvtDriverServicesPluginIoTargetRemoveCanceled @ 1400094c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl TreeEvtDriverServicesPluginIoTargetRemoveCanceled(struct WDFIOTARGET__ * __ptr64) */

void __cdecl TreeEvtDriverServicesPluginIoTargetRemoveCanceled(WDFIOTARGET__ *param_1)

{
  undefined4 local_98;
  undefined4 local_94;
  undefined1 local_90 [136];
  
  memset(local_90,0,0x80);
  local_98 = 0x88;
  local_94 = 3;
  (**(code **)(WdfFunctions_01015 + 0x540))(WdfDriverGlobals,param_1,&local_98);
  return;
}



===== TreeEvtDriverServicesRequestCompletionCallback @ 140009520 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl TreeEvtDriverServicesRequestCompletionCallback(struct WDFREQUEST__ * __ptr64,struct
   WDFIOTARGET__ * __ptr64,struct _WDF_REQUEST_COMPLETION_PARAMS * __ptr64,void * __ptr64) */

void __cdecl
TreeEvtDriverServicesRequestCompletionCallback
          (WDFREQUEST__ *param_1,WDFIOTARGET__ *param_2,_WDF_REQUEST_COMPLETION_PARAMS *param_3,
          void *param_4)

{
  long lVar1;
  longlong lVar2;
  ulonglong uVar3;
  __uint64 _Var4;
  WDFREQUEST__ *local_res8;
  
  local_res8 = param_1;
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,
                     PTR__WDF_TREE_DRIVER_SERVICES_REQUEST_CONTEXT_TYPE_INFO_14000f1f0);
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x8a0))(WdfDriverGlobals,param_1);
  if (uVar3 < 0x10) {
    _Var4 = 0;
  }
  else {
    lVar2 = (**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,*(undefined8 *)(lVar2 + 8),0)
    ;
    _Var4 = *(__uint64 *)(lVar2 + 8);
  }
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x7f0))(WdfDriverGlobals,param_1);
  TreeDriverServicesCompleteWork(&local_res8,lVar1,_Var4);
  return;
}



===== TreeEvtDriverServicesRequestContextCleanupCallback @ 1400095f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl TreeEvtDriverServicesRequestContextCleanupCallback(void * __ptr64) */

void __cdecl TreeEvtDriverServicesRequestContextCleanupCallback(void *param_1)

{
  longlong lVar1;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,
                     PTR__WDF_TREE_DRIVER_SERVICES_REQUEST_CONTEXT_TYPE_INFO_14000f1f0);
  if (*(longlong *)(lVar1 + 0x30) != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
    *(undefined8 *)(lVar1 + 0x30) = 0;
  }
  return;
}



===== TreeEvtPluginProcessQueue @ 140009660 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl TreeEvtPluginProcessQueue(struct WDFWORKITEM__ * __ptr64) */

void __cdecl TreeEvtPluginProcessQueue(WDFWORKITEM__ *param_1)

{
  int iVar1;
  long lVar2;
  WDFDEVICE__ *pWVar3;
  undefined8 *puVar4;
  longlong lVar5;
  void *pvVar6;
  longlong lVar7;
  WDFREQUEST__ *local_res10;
  
  local_res10 = (WDFREQUEST__ *)0x0;
  pWVar3 = (WDFDEVICE__ *)(**(code **)(WdfFunctions_01015 + 0xbe8))(WdfDriverGlobals,param_1);
  puVar4 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,
                      PTR__WDF_TREE_PLUGIN_QUEUE_WORK_ITEM_CONTEXT_TYPE_INFO_14000f240);
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,*puVar4,
                     PTR__WDF_TREE_DRIVER_SERVICES_PLUGIN_TYPE_INFO_14000f218);
  while( true ) {
    while( true ) {
      (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(lVar5 + 0x40));
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x70))
                        (WdfDriverGlobals,*(undefined8 *)(lVar5 + 0x58));
      (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(lVar5 + 0x40));
      if (iVar1 == 0) {
        return;
      }
      lVar2 = TreeDriverServicesGetRequest(pWVar3,(void *)*puVar4,&local_res10);
      if (lVar2 == 0) break;
      if (lVar2 < 0) {
        return;
      }
    }
    (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(lVar5 + 0x40));
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x70))(WdfDriverGlobals,*(undefined8 *)(lVar5 + 0x58))
    ;
    if (iVar1 == 0) break;
    pvVar6 = (void *)(**(code **)(WdfFunctions_01015 + 0x98))
                               (WdfDriverGlobals,*(undefined8 *)(lVar5 + 0x58));
    (**(code **)(WdfFunctions_01015 + 0x668))
              (WdfDriverGlobals,pvVar6,0,0x758,
               "onecore\\base\\basedrv\\tree\\treeclx\\driver\\driverservices.cxx");
    (**(code **)(WdfFunctions_01015 + 0x80))(WdfDriverGlobals,*(undefined8 *)(lVar5 + 0x58),pvVar6);
    (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(lVar5 + 0x40));
    if (*(longlong *)(lVar5 + 0x68) == 0) {
      TreeDriverServicesSendRequest(local_res10,pvVar6);
    }
    else {
      lVar7 = (**(code **)(WdfFunctions_01015 + 0x650))
                        (WdfDriverGlobals,local_res10,
                         PTR__WDF_TREE_DRIVER_SERVICES_REQUEST_CONTEXT_TYPE_INFO_14000f1f0);
      (**(code **)(lVar5 + 0x68))(*puVar4,*(undefined8 *)(lVar7 + 0x30),local_res10,pvVar6);
    }
    (**(code **)(WdfFunctions_01015 + 0x670))
              (WdfDriverGlobals,pvVar6,0,0x771,
               "onecore\\base\\basedrv\\tree\\treeclx\\driver\\driverservices.cxx");
    local_res10 = (WDFREQUEST__ *)0x0;
  }
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(lVar5 + 0x40));
  TreeDriverServicesReturnRequest(&local_res10);
  if (local_res10 == (WDFREQUEST__ *)0x0) {
    return;
  }
  (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  return;
}



===== TreeDriverServicesExecuteCommand @ 140009920 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint TreeDriverServicesExecuteCommand(WDFDEVICE__ *param_1,_GUID *param_2,void *param_3)

{
  uint uVar1;
  _TREE_DRIVER_SERVICES_PLUGIN *p_Var2;
  uchar uVar3;
  uint uVar4;
  _TREE_DRIVER_SERVICES_CONTEXT *p_Var5;
  undefined4 *puVar6;
  longlong lVar7;
  uint *puVar8;
  WDFREQUEST__ *pWVar9;
  void *pvVar10;
  bool bVar11;
  void *local_res20;
  WDFREQUEST__ *local_28;
  _TREE_DRIVER_SERVICES_PLUGIN *local_20;
  
  local_20 = (_TREE_DRIVER_SERVICES_PLUGIN *)0x0;
  local_res20 = (void *)0x0;
  local_28 = (WDFREQUEST__ *)0x0;
  p_Var5 = (_TREE_DRIVER_SERVICES_CONTEXT *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,
                      PTR__WDF_TREE_DRIVER_SERVICES_CONTEXT_TYPE_INFO_14000f268);
  if (*p_Var5 == (_TREE_DRIVER_SERVICES_CONTEXT)0x0) {
    return 0x8000000f;
  }
  uVar3 = TreeDriverServicesFindPlugin(p_Var5,(_UNICODE_STRING *)0x0,param_2,&local_res20,&local_20)
  ;
  if (uVar3 == '\0') {
    uVar4 = TreeDriverServicesRegisterNewPlugin(param_1,p_Var5,param_2);
    uVar3 = TreeDriverServicesFindPlugin
                      (p_Var5,(_UNICODE_STRING *)0x0,param_2,&local_res20,&local_20);
    if (uVar3 == '\0') {
      pvVar10 = local_res20;
      goto LAB_140009baf;
    }
  }
  uVar4 = TreeDriverServicesGetRequest(param_1,local_res20,&local_28);
  puVar6 = (undefined4 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_3,PTR__WDF_TREE_SESSION_CALL_DATA_TYPE_INFO_14000f0c8);
  p_Var2 = local_20;
  pWVar9 = local_28;
  pvVar10 = local_res20;
  puVar6[1] = 0;
  *(undefined8 *)(puVar6 + 2) = 0;
  LOCK();
  *puVar6 = 0;
  UNLOCK();
  if ((int)uVar4 < 0) {
    if (uVar4 != 0xc000009d) {
      (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(local_20 + 0x40));
      uVar4 = (**(code **)(WdfFunctions_01015 + 0x78))
                        (WdfDriverGlobals,*(undefined8 *)(p_Var2 + 0x58),param_3);
      (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(p_Var2 + 0x40));
      if ((int)uVar4 < 0) goto LAB_140009a85;
      (**(code **)(WdfFunctions_01015 + 0xbe0))(WdfDriverGlobals,*(undefined8 *)(p_Var2 + 0x38));
      goto LAB_140009a91;
    }
  }
  else {
    if (*(longlong *)(local_20 + 0x68) == 0) {
      TreeDriverServicesSendRequest(local_28,param_3);
    }
    else {
      lVar7 = (**(code **)(WdfFunctions_01015 + 0x650))
                        (WdfDriverGlobals,local_28,
                         PTR__WDF_TREE_DRIVER_SERVICES_REQUEST_CONTEXT_TYPE_INFO_14000f1f0);
      uVar4 = (**(code **)(p_Var2 + 0x68))(pvVar10,*(undefined8 *)(lVar7 + 0x30),pWVar9,param_3);
LAB_140009a85:
      if (uVar4 != 0x103) goto LAB_140009b7e;
    }
LAB_140009a91:
    puVar8 = (uint *)(**(code **)(WdfFunctions_01015 + 0x650))
                               (WdfDriverGlobals,param_3,
                                PTR__WDF_TREE_SESSION_CALL_DATA_TYPE_INFO_14000f0c8);
    uVar4 = *puVar8;
    do {
      LOCK();
      uVar1 = *puVar8;
      bVar11 = uVar4 == uVar1;
      if (bVar11) {
        *puVar8 = uVar4 | 1;
      }
      else {
        uVar4 = uVar1;
      }
      UNLOCK();
    } while (!bVar11);
    if ((uVar4 & 2) == 0) {
      uVar4 = 0x103;
    }
    else {
      uVar4 = puVar8[1];
    }
    pWVar9 = (WDFREQUEST__ *)0x0;
    local_28 = (WDFREQUEST__ *)0x0;
    pvVar10 = local_res20;
  }
LAB_140009b7e:
  if ((pWVar9 != (WDFREQUEST__ *)0x0) &&
     (TreeDriverServicesReturnRequest(&local_28), local_28 != (WDFREQUEST__ *)0x0)) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
LAB_140009baf:
  if (pvVar10 != (void *)0x0) {
    (**(code **)(WdfFunctions_01015 + 0x670))
              (WdfDriverGlobals,pvVar10,0,0x89c,
               "onecore\\base\\basedrv\\tree\\treeclx\\driver\\driverservices.cxx");
  }
  return uVar4;
}



===== TreeDriverServicesGetServicePdo @ 140009c08 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int TreeDriverServicesGetServicePdo(undefined8 param_1,_GUID *param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  uchar uVar2;
  int iVar3;
  _TREE_DRIVER_SERVICES_CONTEXT *p_Var4;
  undefined8 uVar5;
  undefined8 local_res20;
  _TREE_DRIVER_SERVICES_PLUGIN *local_b8;
  void *local_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 local_58;
  undefined4 local_4c;
  undefined4 local_48;
  
  local_res20 = 0;
  local_b0 = (void *)0x0;
  local_b8 = (_TREE_DRIVER_SERVICES_PLUGIN *)0x0;
  local_a8 = 0;
  uStack_a0 = 0;
  p_Var4 = (_TREE_DRIVER_SERVICES_CONTEXT *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,
                      PTR__WDF_TREE_DRIVER_SERVICES_CONTEXT_TYPE_INFO_14000f268);
  uVar2 = TreeDriverServicesFindPlugin(p_Var4,(_UNICODE_STRING *)0x0,param_2,&local_b0,&local_b8);
  if (uVar2 == '\0') {
    *param_3 = 0;
    return -0x3fffff5d;
  }
  iVar3 = (**(code **)(WdfFunctions_01015 + 0x538))(WdfDriverGlobals,param_1,0,&local_res20);
  if (-1 < iVar3) {
    (**(code **)(WdfFunctions_01015 + 0x9a8))(WdfDriverGlobals,*(undefined8 *)local_b8,&local_a8);
    memset(&local_98,0,0x88);
    local_68 = (undefined4)local_a8;
    uStack_64 = local_a8._4_4_;
    uStack_60 = (undefined4)uStack_a0;
    uStack_5c = uStack_a0._4_4_;
    local_98 = 0x88;
    local_94 = 2;
    local_58 = 0x1f0000;
    local_48 = 0x40;
    local_4c = 1;
    iVar3 = (**(code **)(WdfFunctions_01015 + 0x540))(WdfDriverGlobals,local_res20,&local_98);
    if (-1 < iVar3) {
      uVar5 = (**(code **)(WdfFunctions_01015 + 0x598))(WdfDriverGlobals,local_res20);
      uVar1 = WdfDriverGlobals;
      *param_3 = uVar5;
      (**(code **)(WdfFunctions_01015 + 0x550))(uVar1,local_res20);
    }
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,local_res20);
    if (-1 < iVar3) {
      return iVar3;
    }
  }
  *param_3 = 0;
  return iVar3;
}



===== TreeDriverServicesInitialize @ 140009dd0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TreeDriverServicesInitialize(undefined8 param_1)

{
  int iVar1;
  longlong local_res10 [3];
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined4 local_40;
  undefined4 local_3c;
  code *local_38;
  undefined8 local_30;
  undefined4 local_28;
  undefined4 local_24;
  undefined8 local_20;
  undefined8 uStack_18;
  undefined *local_10;
  
  local_res10[0] = 0;
  local_3c = 0;
  local_30 = 0;
  local_10 = PTR__WDF_TREE_DRIVER_SERVICES_CONTEXT_TYPE_INFO_14000f268;
  local_38 = TreeEvtDriverServicesContextCleanupCallback;
  local_20 = 0;
  uStack_18 = 0;
  local_40 = 0x38;
  local_28 = 1;
  local_24 = 1;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x658))(WdfDriverGlobals,param_1,&local_40,local_res10);
  if (-1 < iVar1) {
    local_48 = 0;
    local_68 = 0;
    uStack_70 = 0;
    local_78 = 0x38;
    uStack_50 = 0;
    uStack_60 = 0x100000001;
    local_58 = param_1;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x9c0))(WdfDriverGlobals,&local_78,local_res10[0] + 8)
    ;
    if (-1 < iVar1) {
      (**(code **)(WdfFunctions_01015 + 0x68))(WdfDriverGlobals,&local_78,local_res10[0] + 0x10);
    }
  }
  return;
}



===== TreeDriverServicesQuery @ 140009ee4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

long TreeDriverServicesQuery(WDFDEVICE__ *param_1,_GUID *param_2,undefined8 *param_3)

{
  uchar uVar1;
  long lVar2;
  _TREE_DRIVER_SERVICES_CONTEXT *p_Var3;
  _TREE_DRIVER_SERVICES_PLUGIN *local_res20;
  void *local_18 [2];
  
  local_res20 = (_TREE_DRIVER_SERVICES_PLUGIN *)0x0;
  local_18[0] = (void *)0x0;
  p_Var3 = (_TREE_DRIVER_SERVICES_CONTEXT *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,
                      PTR__WDF_TREE_DRIVER_SERVICES_CONTEXT_TYPE_INFO_14000f268);
  if (*p_Var3 == (_TREE_DRIVER_SERVICES_CONTEXT)0x0) {
    return -0x7ffffff1;
  }
  uVar1 = TreeDriverServicesFindPlugin(p_Var3,(_UNICODE_STRING *)0x0,param_2,local_18,&local_res20);
  if (uVar1 == '\0') {
    lVar2 = TreeDriverServicesRegisterNewPlugin(param_1,p_Var3,param_2);
    uVar1 = TreeDriverServicesFindPlugin
                      (p_Var3,(_UNICODE_STRING *)0x0,param_2,local_18,&local_res20);
    if (uVar1 == '\0') goto LAB_140009fb4;
  }
  if (local_res20[0x30] == (_TREE_DRIVER_SERVICES_PLUGIN)0x0) {
    lVar2 = -0x3fffff63;
  }
  else {
    lVar2 = 0;
    *param_3 = *(undefined8 *)(local_res20 + 0x18);
    *(undefined4 *)(param_3 + 1) = *(undefined4 *)(local_res20 + 0x20);
  }
LAB_140009fb4:
  if (local_18[0] != (void *)0x0) {
    (**(code **)(WdfFunctions_01015 + 0x670))
              (WdfDriverGlobals,local_18[0],0,0x808,
               "onecore\\base\\basedrv\\tree\\treeclx\\driver\\driverservices.cxx");
  }
  return lVar2;
}



===== WPP_RECORDER_SF_Z_guid_ @ 14000a00c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_Z_guid_(undefined8 param_1)

{
  wchar_t wVar1;
  wchar_t *pwVar2;
  wchar_t *pwVar3;
  wchar_t wVar4;
  wchar_t *pwVar5;
  wchar_t *in_stack_00000030;
  
  pwVar3 = L"NULL";
  wVar4 = L'\b';
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
  goto LAB_14000a0e6;
  if (in_stack_00000030 == (wchar_t *)0x0) {
    wVar1 = L'\b';
LAB_14000a086:
    pwVar5 = L"NULL";
  }
  else {
    wVar1 = *in_stack_00000030;
    if (*in_stack_00000030 == L'\0') goto LAB_14000a086;
    pwVar5 = *(wchar_t **)(in_stack_00000030 + 4);
  }
  pwVar2 = in_stack_00000030;
  if (in_stack_00000030 == (wchar_t *)0x0) {
    pwVar2 = L"\b";
  }
  (*pfnWppTraceMessage)
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
             &WPP_15e573b43f13303ed90e4244ba7a5915_Traceguids,10,pwVar2,2,pwVar5,wVar1);
LAB_14000a0e6:
  if ((in_stack_00000030 != (wchar_t *)0x0) &&
     (wVar4 = *in_stack_00000030, *in_stack_00000030 != L'\0')) {
    pwVar3 = *(wchar_t **)(in_stack_00000030 + 4);
  }
  if (in_stack_00000030 == (wchar_t *)0x0) {
    in_stack_00000030 = L"\b";
  }
  WppAutoLogTrace(param_1,2,1,&WPP_15e573b43f13303ed90e4244ba7a5915_Traceguids,10,in_stack_00000030,
                  2,pwVar3,wVar4);
  return;
}



===== WPP_RECORDER_SF__guid_Z @ 14000a170 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF__guid_Z
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,undefined8 param_6,wchar_t *param_7)

{
  wchar_t wVar1;
  wchar_t *pwVar2;
  wchar_t *pwVar3;
  wchar_t wVar4;
  wchar_t *pwVar5;
  
  pwVar3 = L"NULL";
  wVar4 = L'\b';
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
  goto LAB_14000a246;
  if (param_7 == (wchar_t *)0x0) {
    wVar1 = L'\b';
LAB_14000a1ec:
    pwVar5 = L"NULL";
  }
  else {
    wVar1 = *param_7;
    if (*param_7 == L'\0') goto LAB_14000a1ec;
    pwVar5 = *(wchar_t **)(param_7 + 4);
  }
  pwVar2 = param_7;
  if (param_7 == (wchar_t *)0x0) {
    pwVar2 = L"\b";
  }
  (*pfnWppTraceMessage)
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
             &WPP_15e573b43f13303ed90e4244ba7a5915_Traceguids,param_4,param_6,0x10,pwVar2,2,pwVar5,
             wVar1,0);
LAB_14000a246:
  if ((param_7 != (wchar_t *)0x0) && (wVar4 = *param_7, *param_7 != L'\0')) {
    pwVar3 = *(wchar_t **)(param_7 + 4);
  }
  if (param_7 == (wchar_t *)0x0) {
    param_7 = L"\b";
  }
  WppAutoLogTrace(param_1,4,1,&WPP_15e573b43f13303ed90e4244ba7a5915_Traceguids,param_4,param_6,0x10,
                  param_7,2,pwVar3,wVar4,0);
  return;
}



===== TreeRPMBPluginCleanup @ 14000a2e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl TreeRPMBPluginCleanup(void * __ptr64) */

void __cdecl TreeRPMBPluginCleanup(void *param_1)

{
  (**(code **)(WdfFunctions_01015 + 0x650))
            (WdfDriverGlobals,param_1,PTR__WDF_TREE_RPMB_SERVICE_CONTEXT_TYPE_INFO_14000f290);
  return;
}



===== TreeRPMBPluginProcessStorRequest @ 14000a314 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl TreeRPMBPluginProcessStorRequest(void * __ptr64,struct WDFIOTARGET__ *
   __ptr64,unsigned long,void * __ptr64,unsigned __int64,void * __ptr64,unsigned __int64,unsigned
   __int64 * __ptr64) */

long __cdecl
TreeRPMBPluginProcessStorRequest
          (void *param_1,WDFIOTARGET__ *param_2,ulong param_3,void *param_4,__uint64 param_5,
          void *param_6,__uint64 param_7,__uint64 *param_8)

{
  uint uVar1;
  size_t _Size;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  ulonglong uVar8;
  long local_b8;
  _RPMB_IOCTL_TYPE local_b4;
  void *local_b0;
  void *local_a8;
  __uint64 local_a0;
  longlong local_98;
  int *local_90;
  int *local_88;
  undefined8 local_80;
  __uint64 local_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  void *local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  
  local_40 = 0;
  local_88 = (int *)0x0;
  local_90 = (int *)0x0;
  local_a0 = 0;
  local_b8 = 0;
  local_a8 = (void *)0x0;
  local_80 = 0;
  uVar8 = 1;
  local_70 = 0;
  uStack_68 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = (void *)0x0;
  uStack_48 = 0;
  if ((param_3 == 0x10002) || (param_3 == 0x10003)) {
    if (param_3 == 0x10003) {
      uVar3 = *(uint *)((longlong)param_4 + 4);
    }
    else {
      uVar3 = 2;
    }
    local_90 = param_6;
    uVar4 = (uint)((param_7 - 8 >> 9 & 0xffffffff) / (ulonglong)uVar3);
    local_b4 = 0;
  }
  else {
    if (param_3 != 0x10004) {
      return -0x3ffffff3;
    }
    uVar3 = *(uint *)((longlong)param_4 + 4);
    uVar4 = (int)param_7 - 8U >> 9;
    local_88 = param_6;
    local_b4 = 1;
  }
  piVar6 = local_88;
  piVar5 = local_90;
  uVar1 = (int)param_5 - 8U >> 9;
  local_98 = (longlong)param_6 + 8;
  local_b0 = (void *)((longlong)param_4 + 8);
  if (uVar3 == 0) {
    uVar3 = 1;
  }
  if (uVar1 < uVar4) {
    local_70 = 0x38;
    uVar2 = (uint)((ulonglong)uVar4 / (ulonglong)uVar3);
    uStack_58 = 0x100000001;
    _Size = (ulonglong)uVar4 / (ulonglong)uVar3 << 9;
    local_50 = param_1;
    local_b8 = (**(code **)(WdfFunctions_01015 + 0x600))
                         (WdfDriverGlobals,&local_70,1,0x45457254,_Size,&local_80,&local_a8);
    memcpy(local_a8,local_b0,_Size);
    local_b0 = local_a8;
  }
  else {
    uVar8 = (ulonglong)uVar3;
    uVar2 = uVar1 / uVar3;
    if (uVar4 < uVar1) {
      uVar3 = 1;
    }
  }
  uVar4 = 0;
  *param_8 = 0;
  iVar7 = (int)uVar8;
  if (uVar2 != 0) {
    local_78 = uVar8 << 9;
    do {
      local_b8 = TreeRPMBPluginSendIoctlSynchronously
                           (param_1,param_2,local_b4,
                            (void *)((ulonglong)(uVar4 * iVar7) * 0x200 + (longlong)local_b0),
                            local_78,(void *)((ulonglong)(uVar4 * uVar3) * 0x200 + local_98),
                            (ulonglong)uVar3 << 9,&local_a0);
      if (local_b8 < 0) break;
      uVar4 = uVar4 + 1;
      *param_8 = *param_8 + local_a0;
    } while (uVar4 < uVar2);
    piVar5 = local_90;
    piVar6 = local_88;
  }
  if ((param_3 == 0x10002) || (param_3 == 0x10003)) {
    if (piVar5 != (int *)0x0) {
      piVar5[1] = uVar2 * iVar7;
      *piVar5 = uVar2 * uVar3;
    }
  }
  else if ((param_3 == 0x10004) && (piVar6 != (int *)0x0)) {
    piVar6[1] = uVar2 * iVar7;
    *piVar6 = uVar2 * uVar3;
  }
  if (local_a8 != (void *)0x0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,local_80);
  }
  return local_b8;
}



===== TreeRPMBPluginSendIoctlSynchronously @ 14000a5ec =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl TreeRPMBPluginSendIoctlSynchronously(void * __ptr64,struct WDFIOTARGET__ *
   __ptr64,enum _RPMB_IOCTL_TYPE,void * __ptr64,unsigned __int64,void * __ptr64,unsigned
   __int64,unsigned __int64 * __ptr64) */

long __cdecl
TreeRPMBPluginSendIoctlSynchronously
          (void *param_1,WDFIOTARGET__ *param_2,_RPMB_IOCTL_TYPE param_3,void *param_4,
          __uint64 param_5,void *param_6,__uint64 param_7,__uint64 *param_8)

{
  undefined8 *puVar1;
  undefined4 *_Dst;
  undefined8 uVar2;
  long lVar3;
  longlong lVar4;
  undefined8 *puVar5;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 *local_60;
  uint local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  void *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  void *local_30;
  int local_28;
  undefined4 local_24;
  
  if (param_7 < 0x200) {
    lVar3 = -0x3ffffff3;
  }
  else if (param_3 == 0) {
    lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,param_1,
                       PTR__WDF_TREE_RPMB_SERVICE_CONTEXT_TYPE_INFO_14000f290);
    _Dst = *(undefined4 **)(lVar4 + 8);
    memset(_Dst,0,(ulonglong)((int)param_5 + 0x220U));
    *_Dst = 0x420;
    _Dst[1] = 3;
    memcpy(_Dst + 0x88,param_4,param_5);
    _Dst[4] = (uint)(param_5 >> 9) & 0x7fffff;
    local_64 = 0;
    local_54 = 0;
    local_68 = 1;
    local_60 = _Dst;
    local_58 = (int)param_5 + 0x220U;
    lVar3 = (**(code **)(WdfFunctions_01015 + 0x5d0))
                      (WdfDriverGlobals,param_2,0,0x71e8c,&local_68,&local_68,0,param_8);
    lVar4 = 4;
    puVar5 = (undefined8 *)(_Dst + 8);
    do {
      uVar2 = puVar5[1];
      *(undefined8 *)param_6 = *puVar5;
      *(undefined8 *)((longlong)param_6 + 8) = uVar2;
      uVar2 = puVar5[3];
      *(undefined8 *)((longlong)param_6 + 0x10) = puVar5[2];
      *(undefined8 *)((longlong)param_6 + 0x18) = uVar2;
      uVar2 = puVar5[5];
      *(undefined8 *)((longlong)param_6 + 0x20) = puVar5[4];
      *(undefined8 *)((longlong)param_6 + 0x28) = uVar2;
      uVar2 = puVar5[7];
      *(undefined8 *)((longlong)param_6 + 0x30) = puVar5[6];
      *(undefined8 *)((longlong)param_6 + 0x38) = uVar2;
      uVar2 = puVar5[9];
      *(undefined8 *)((longlong)param_6 + 0x40) = puVar5[8];
      *(undefined8 *)((longlong)param_6 + 0x48) = uVar2;
      uVar2 = puVar5[0xb];
      *(undefined8 *)((longlong)param_6 + 0x50) = puVar5[10];
      *(undefined8 *)((longlong)param_6 + 0x58) = uVar2;
      uVar2 = puVar5[0xd];
      *(undefined8 *)((longlong)param_6 + 0x60) = puVar5[0xc];
      *(undefined8 *)((longlong)param_6 + 0x68) = uVar2;
      puVar1 = puVar5 + 0xe;
      uVar2 = puVar5[0xf];
      puVar5 = puVar5 + 0x10;
      *(undefined8 *)((longlong)param_6 + 0x70) = *puVar1;
      *(undefined8 *)((longlong)param_6 + 0x78) = uVar2;
      lVar4 = lVar4 + -1;
      param_6 = (undefined8 *)((longlong)param_6 + 0x80);
    } while (lVar4 != 0);
  }
  else if (param_3 == 1) {
    local_34 = 0;
    local_24 = 0;
    local_4c = 0;
    local_3c = 0;
    local_28 = (int)param_5;
    local_48 = param_6;
    local_38 = 1;
    local_50 = 1;
    local_40 = (undefined4)param_7;
    local_30 = param_4;
    lVar3 = (**(code **)(WdfFunctions_01015 + 0x5d0))
                      (WdfDriverGlobals,param_2,0,0x2d1c98,&local_38,&local_50,0,param_8);
  }
  else {
    lVar3 = -0x3fffff45;
  }
  return lVar3;
}



===== TreeRPMBPluginHandler @ 14000a810 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

long TreeRPMBPluginHandler
               (void *param_1,WDFIOTARGET__ *param_2,undefined8 param_3,undefined8 param_4)

{
  ulong uVar1;
  long lVar2;
  longlong lVar3;
  undefined8 local_38;
  undefined8 local_30;
  undefined4 local_28;
  undefined4 local_24;
  undefined8 local_20;
  undefined8 local_18;
  undefined4 local_10;
  undefined4 local_c;
  
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_4,PTR__WDF_TREE_SESSION_CALL_DATA_TYPE_INFO_14000f0c8);
  uVar1 = *(ulong *)(lVar3 + 0x1c);
  if (uVar1 == 0x10001) {
    local_30 = *(undefined8 *)(lVar3 + 0x30);
    local_18 = *(undefined8 *)(lVar3 + 0x20);
    local_10 = (undefined4)*(undefined8 *)(lVar3 + 0x28);
    *(undefined8 *)(lVar3 + 8) = 0;
    local_28 = (undefined4)*(undefined8 *)(lVar3 + 0x38);
    local_20 = 1;
    local_c = 0;
    local_38 = 1;
    local_24 = 0;
    lVar2 = (**(code **)(WdfFunctions_01015 + 0x5d0))
                      (WdfDriverGlobals,param_2,0,0x71e8c,&local_20,&local_38,0,
                       (undefined8 *)(lVar3 + 8));
  }
  else if (((uVar1 == 0x10002) || (uVar1 == 0x10003)) || (uVar1 == 0x10004)) {
    lVar2 = TreeRPMBPluginProcessStorRequest
                      (param_1,param_2,uVar1,*(void **)(lVar3 + 0x20),*(__uint64 *)(lVar3 + 0x28),
                       *(void **)(lVar3 + 0x30),*(__uint64 *)(lVar3 + 0x38),(__uint64 *)(lVar3 + 8))
    ;
  }
  else {
    lVar2 = -0x3ffffff3;
  }
  *(long *)(lVar3 + 4) = lVar2;
  (**(code **)(lVar3 + 0x40))(param_4);
  return lVar2;
}



===== TreeRPMBPluginInitialize @ 14000a980 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int TreeRPMBPluginInitialize(undefined8 *param_1,undefined8 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  undefined1 auStackY_578 [32];
  uint *local_528;
  ulonglong local_520;
  undefined8 local_518;
  undefined8 *puStack_510;
  undefined8 local_508;
  undefined8 local_500;
  undefined8 *puStack_4f8;
  undefined8 local_4f0;
  undefined8 local_4e8;
  undefined4 *puStack_4e0;
  undefined8 local_4d8;
  undefined8 local_4d0;
  code *pcStack_4c8;
  undefined8 local_4c0;
  undefined8 uStack_4b8;
  undefined8 *local_4b0;
  undefined8 uStack_4a8;
  undefined *local_4a0;
  undefined4 local_498;
  undefined4 uStack_494;
  undefined4 local_490;
  undefined8 local_488;
  undefined8 uStack_480;
  undefined4 local_478;
  undefined8 local_468 [2];
  int local_458;
  uint local_454;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_578;
  local_520 = 0;
  memset(local_468,0,0x420);
  local_528 = (uint *)0x0;
  local_4d8 = 0;
  local_508 = 0;
  puVar3 = &local_4d0;
  local_4f0 = 0;
  local_498 = 0;
  uStack_494 = 0;
  local_490 = 0;
  local_478 = 0;
  local_4a0 = PTR__WDF_TREE_RPMB_SERVICE_CONTEXT_TYPE_INFO_14000f290;
  pcStack_4c8 = TreeRPMBPluginCleanup;
  local_4e8 = 0;
  puStack_4e0 = (undefined4 *)0x0;
  local_4d0 = 0x38;
  local_518 = 0;
  puStack_510 = (undefined8 *)0x0;
  local_4c0 = 0;
  local_500 = 0;
  puStack_4f8 = (undefined8 *)0x0;
  local_488 = 0;
  uStack_480 = 0;
  uStack_4b8 = 0x100000001;
  local_4b0 = (undefined8 *)0x0;
  uStack_4a8 = 0;
  puVar2 = param_1;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x658))(WdfDriverGlobals,param_1,puVar3,&local_528);
  if (iVar1 < 0) goto LAB_14000ac51;
  puStack_4e0 = &local_498;
  local_488 = CONCAT44(0x14,(undefined4)local_488);
  puStack_4f8 = &local_488;
  puVar3 = (undefined8 *)0x0;
  uStack_494 = 0;
  local_490 = 0;
  local_498 = 0x10;
  local_4e8 = 1;
  local_4d8 = 0xc;
  local_500 = 1;
  local_4f0 = 0x14;
  puVar2 = param_2;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x5d0))(WdfDriverGlobals,param_2,0,0x2d1400);
  if (iVar1 < 0) {
    local_468[0] = 0x420;
    puStack_510 = local_468;
    puVar3 = (undefined8 *)0x0;
    local_518 = 1;
    local_508 = 0x420;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x5d0))(WdfDriverGlobals,param_2,0,0x71e8c);
    puVar2 = param_2;
    if (iVar1 < 0) goto LAB_14000ac51;
    if (local_520 < 0x420) {
      iVar1 = -0x3ffffff3;
      goto LAB_14000ac51;
    }
    if (local_458 != 0) {
      *local_528 = local_454 >> 9;
      local_528[6] = 0;
      goto LAB_14000abd5;
    }
  }
  else {
    if (local_520 != 0x14) {
      iVar1 = -0x3fffff1b;
      goto LAB_14000ac51;
    }
    param_2 = puVar2;
    if ((int)uStack_480 != 0) {
      *local_528 = uStack_480._4_4_ >> 9;
      local_528[6] = 1;
LAB_14000abd5:
      local_4a0 = (undefined *)0x0;
      local_4c0 = 0;
      pcStack_4c8 = (code *)0x0;
      local_4d0 = 0x38;
      puVar2 = &local_4d0;
      uStack_4a8 = 0;
      puVar3 = (undefined8 *)0x1;
      uStack_4b8 = 0x100000001;
      local_4b0 = param_1;
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x600))(WdfDriverGlobals,puVar2,1,0x45457254);
      if (-1 < iVar1) {
        *param_3 = 1;
        param_3[1] = 1;
        param_3[2] = 1;
      }
      goto LAB_14000ac51;
    }
  }
  iVar1 = -0x3fffff45;
  puVar2 = param_2;
LAB_14000ac51:
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar2,puVar3,10,
                      &WPP_b888e946083a39273847fa81d8a80bd6_Traceguids,(char)iVar1);
  }
  return iVar1;
}



===== FxStubDriverUnloadCommon @ 14000acbc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl FxStubDriverUnloadCommon(void) */

void __cdecl FxStubDriverUnloadCommon(void)

{
  void **ppvVar1;
  void **ppvVar2;
  
  ppvVar1 = &__KMDF_CLASS_BIND_END;
  if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_14000f458 != &__KMDF_CLASS_BIND_START) {
    ppvVar2 = (void **)(PTR___KMDF_CLASS_BIND_START_14000f458 + 0x50);
    while( true ) {
      for (; (ppvVar1 + 1 <= ppvVar2 && (*ppvVar1 == (void *)0x0)); ppvVar1 = ppvVar1 + 1) {
      }
      if (ppvVar1 < ppvVar2) break;
      ppvVar1 = ppvVar2;
LAB_14000ad15:
      if (ppvVar1 == (void **)0x0) goto LAB_14000ad6b;
      if (ppvVar2 <= ppvVar1) goto LAB_14000ad83;
      if (ppvVar1[8] == (code *)0x0) {
        WdfVersionUnbindClass(&WdfBindInfo,WdfDriverGlobals,ppvVar1);
      }
      else {
        (*ppvVar1[8])(WdfVersionUnbindClass_exref,&WdfBindInfo,WdfDriverGlobals,ppvVar1);
      }
      ppvVar1 = (void **)((longlong)ppvVar1 + (ulonglong)*(uint *)ppvVar1);
    }
    if ((ppvVar1 + 10 <= ppvVar2) && (*(uint *)ppvVar1 == 0x50)) goto LAB_14000ad15;
LAB_14000ad6b:
    DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
  }
LAB_14000ad83:
  WdfVersionUnbind(&DAT_14000f4f8,&WdfBindInfo,WdfDriverGlobals);
  return;
}



===== entry @ 14000adc0 =====

void entry(_WDF_BIND_INFO *param_1,undefined *param_2)

{
  __security_init_cookie();
  FxDriverEntryWorker(param_1,param_2);
  return;
}



===== FxDriverEntryWorker @ 14000adf4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FxDriverEntryWorker(_WDF_BIND_INFO *param_1,undefined *param_2)

{
  int iVar1;
  int iVar2;
  _WDF_BIND_INFO *p_Var3;
  undefined *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined4 local_14;
  
  if (param_1 == (_WDF_BIND_INFO *)0x0) {
    iVar1 = DriverEntry((undefined *)0x0,param_2);
  }
  else {
    _DAT_14000f4f8 = 0x2080000;
    _DAT_14000f500 = &DAT_14000f560;
    RtlCopyUnicodeString(&DAT_14000f4f8);
    p_Var3 = param_1;
    iVar1 = WdfVersionBind(param_1,&DAT_14000f4f8,&WdfBindInfo,&WdfDriverGlobals);
    if (-1 < iVar1) {
      iVar1 = FxStubBindClasses(p_Var3);
      if ((-1 < iVar1) && (iVar1 = FxStubInitTypes(), -1 < iVar1)) {
        iVar1 = DriverEntry(param_1,param_2);
        if (-1 < iVar1) {
          if (*(char *)(WdfDriverGlobals + 0x30) != '\0') {
            if (*(longlong *)(param_1 + 0x68) != 0) {
              DAT_14000f768 = *(longlong *)(param_1 + 0x68);
            }
            *(code **)(param_1 + 0x68) = FxStubDriverUnload;
          }
          return 0;
        }
        DbgPrintEx(0x4d,0,"DriverEntry failed 0x%x for driver %wZ\n",iVar1,&DAT_14000f4f8);
        if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_14000f458 != &__KMDF_CLASS_BIND_START) {
          local_1c = 0;
          uStack_18 = 0;
          local_28 = &GUID_WDF_LOADER_INTERFACE_DRIVER_ENTRY_FAILURE;
          local_14 = 0;
          local_20 = 0x18;
          iVar2 = WdfLdrQueryInterface(&local_28);
          if (-1 < iVar2) {
            (*(code *)CONCAT44(local_14,uStack_18))(&WdfBindInfo,WdfDriverGlobals);
          }
        }
      }
      FxStubDriverUnloadCommon();
    }
  }
  return iVar1;
}



===== FxStubDriverUnload @ 14000af80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FxStubDriverUnload(void)

{
  if ((DAT_14000f768 != (code *)0x0) && (DAT_14000f768 != FxStubDriverUnload)) {
    (*DAT_14000f768)();
  }
  FxStubDriverUnloadCommon();
  return;
}



===== FxStubBindClasses @ 14000afb4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x00014000afd9) */
/* long __cdecl FxStubBindClasses(struct _WDF_BIND_INFO * __ptr64) */

long __cdecl FxStubBindClasses(_WDF_BIND_INFO *param_1)

{
  int iVar1;
  void **ppvVar2;
  
  iVar1 = 0;
  ppvVar2 = &__KMDF_CLASS_BIND_END;
  while( true ) {
    for (; (ppvVar2 + 1 < (void **)((longlong)&__KMDF_CLASS_BIND_END + 1) &&
           (*ppvVar2 == (void *)0x0)); ppvVar2 = ppvVar2 + 1) {
    }
    if ((void **)0x14000f44f < ppvVar2) break;
    if (((&__KMDF_CLASS_BIND_END < ppvVar2 + 10) || (*(uint *)ppvVar2 != 0x50)) ||
       (ppvVar2 == (void **)0x0)) {
      DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
      return -0x3fffff85;
    }
    PTR___KMDF_CLASS_BIND_START_14000f458 = (undefined *)ppvVar2;
    if (ppvVar2[7] == (code *)0x0) {
      iVar1 = WdfVersionBindClass(&WdfBindInfo,WdfDriverGlobals,ppvVar2);
      if (iVar1 < 0) {
        DbgPrintEx(0x4d,0,
                   "FxStubBindClasses: VersionBindClass WDF_CLASS_BIND_INFO 0x%p, class %S, returned status 0x%x\n"
                   ,ppvVar2,ppvVar2[1],iVar1);
        return iVar1;
      }
    }
    else {
      iVar1 = (*ppvVar2[7])(WdfVersionBindClass_exref,&WdfBindInfo,WdfDriverGlobals,ppvVar2);
      if (iVar1 < 0) {
        DbgPrintEx(0x4d,0,
                   "FxStubBindClasses: ClientBindClass %p, WDF_CLASS_BIND_INFO 0x%p, class %S, returned status 0x%x\n"
                   ,ppvVar2[7],ppvVar2,ppvVar2[1],iVar1);
        return iVar1;
      }
    }
    ppvVar2 = (void **)((ulonglong)*(uint *)ppvVar2 + (longlong)ppvVar2);
  }
  return iVar1;
}



===== FxStubInitTypes @ 14000b13c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x00014000b159) */
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
    if ((void **)0x14000f46f < ppvVar2) break;
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



===== __GSHandlerCheck @ 14000b208 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 14000b22c =====

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



===== __cpu_features_init @ 14000b2a0 =====

/* WARNING: Removing unreachable block (ram,0x00014000b30a) */
/* WARNING: Removing unreachable block (ram,0x00014000b2b9) */
/* WARNING: Removing unreachable block (ram,0x00014000b2aa) */

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



===== __security_check_cookie @ 14000b370 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 14000b3b0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 14000b3e0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x00014000b3e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 14000b410 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcpy @ 14000b480 =====

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



===== memset @ 14000b780 =====

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



===== __memset_repmovs @ 14000b8c0 =====

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



===== __memset_query @ 14000b940 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 14000b9c0 =====

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



===== __memset_spec_ermsb_repmovsb @ 14000bb00 =====

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



===== __memset_spec_plain @ 14000bb80 =====

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



===== TreeAddMasterDevice @ 140012008 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int TreeAddMasterDevice(undefined8 param_1,uint param_2,undefined8 *param_3)

{
  undefined8 *puVar1;
  int iVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  uint uVar6;
  undefined1 auStackY_378 [32];
  undefined8 local_338;
  undefined8 local_330;
  undefined8 local_328;
  undefined8 uStack_320;
  undefined8 local_318;
  undefined8 uStack_310;
  undefined8 local_308;
  undefined8 uStack_300;
  undefined *local_2f8;
  undefined4 local_2f0;
  undefined8 local_2ec;
  undefined4 local_2e4;
  code *local_2e0;
  undefined4 local_2d8;
  undefined4 local_2d4;
  undefined8 local_2d0;
  undefined8 uStack_2c8;
  undefined *local_2c0;
  undefined4 local_2b8;
  undefined4 local_2b4;
  code *local_2b0;
  undefined8 local_2a8;
  undefined8 local_2a0;
  undefined4 local_298;
  undefined4 local_294;
  undefined4 local_288;
  undefined4 local_284;
  code *local_278;
  code *local_260;
  code *local_258;
  code *local_250;
  undefined4 local_228 [2];
  code *local_220;
  code *local_210;
  code *local_200;
  code *local_1f8;
  undefined8 local_198;
  undefined8 local_178;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined4 local_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 local_7c;
  undefined4 uStack_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_378;
  local_48 = 0;
  local_e8 = 0;
  local_2b4 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_108 = 0;
  uStack_100 = 0;
  local_f8 = 0;
  uStack_f0 = 0;
  local_330 = param_1;
  memset(&local_198,0,0x88);
  local_2ec = 0;
  local_2e4 = 0;
  local_2d0 = 0;
  uStack_2c8 = 0;
  local_e0 = 0;
  uStack_d8 = 0;
  local_d0 = 0;
  uStack_c8 = 0;
  local_c0 = 0;
  uStack_b8 = 0;
  memset(&local_a8,0,0x50);
  local_338 = 0;
  (**(code **)(WdfFunctions_01015 + 0x1e8))(WdfDriverGlobals,param_1,2);
  (**(code **)(WdfFunctions_01015 + 0x210))(WdfDriverGlobals,local_330,0x56);
  (**(code **)(WdfFunctions_01015 + 0x1f8))(WdfDriverGlobals);
  memset(local_228,0,0x90);
  local_200 = TreeEvtDevicePrepareHardware;
  local_1f8 = TreeEvtDeviceReleaseHardware;
  local_220 = TreeEvtDeviceD0Entry;
  local_210 = TreeEvtDeviceD0Exit;
  local_228[0] = 0x90;
  (**(code **)(WdfFunctions_01015 + 0x1b8))(WdfDriverGlobals,local_330,local_228);
  memset(&local_288,0,0x60);
  local_288 = 0x60;
  local_278 = TreeEvtCreateChildDevicePdo;
  local_260 = TreeEvtCopyChildDeviceDescriptor;
  local_250 = TreeEvtCompareChildDeviceDescriptors;
  local_284 = 0x14;
  local_258 = TreeEvtCleanupChildDeviceDescriptor;
  (**(code **)(WdfFunctions_01015 + 0x410))(WdfDriverGlobals,local_330,&local_288,0);
  (**(code **)(WdfFunctions_01015 + 0xd70))(WdfDriverGlobals,local_330,2);
  local_2c0 = PTR__WDF_TREE_MASTER_DEVICE_CONTEXT_TYPE_INFO_14000f0f0;
  local_2f0 = 0x38;
  local_318 = 0;
  local_2ec = 0;
  local_2e0 = TreeEvtDestroyDeviceObject;
  uStack_320 = 0;
  local_328 = 0x38;
  local_2b0 = TreeEvtDeviceCreateFile;
  local_2f8 = PTR__WDF_TREE_MASTER_DEVICE_FILE_CONTEXT_TYPE_INFO_14000f140;
  local_2e4 = 0;
  local_2d0 = 0;
  uStack_2c8 = 0;
  local_2d8 = 1;
  local_2d4 = 4;
  local_2b8 = 0x28;
  local_2a8 = 0;
  local_2a0 = 0;
  local_298 = 2;
  local_308 = 0;
  uStack_300 = 0;
  uStack_310 = 0x100000001;
  local_294 = 0x80000002;
  (**(code **)(WdfFunctions_01015 + 0x238))(WdfDriverGlobals,local_330,&local_2b8,&local_328);
  puVar5 = (undefined8 *)&local_2f0;
  iVar2 = (**(code **)(WdfFunctions_01015 + 600))(WdfDriverGlobals,&local_330,puVar5,&local_338);
  if (-1 < iVar2) {
    lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,local_338,
                       PTR__WDF_TREE_MASTER_DEVICE_CONTEXT_TYPE_INFO_14000f0f0);
    *(uint *)(lVar3 + 4) = param_2 & 3;
    uVar6 = param_2 & 0xc;
    if (uVar6 == 0) {
      *(undefined4 *)(lVar3 + 8) = 0;
    }
    else if (uVar6 == 4) {
      *(undefined4 *)(lVar3 + 8) = 0x900;
    }
    else if (uVar6 == 8) {
      *(undefined4 *)(lVar3 + 8) = 0x1100;
    }
    else if (uVar6 == 0xc) {
      *(undefined4 *)(lVar3 + 8) = 0x2100;
    }
    puVar5 = (undefined8 *)(lVar3 + 0x10);
    local_2f8 = (undefined *)0x0;
    local_318 = 0;
    uStack_300 = 0;
    local_308 = local_338;
    uStack_320 = 0;
    local_328 = 0x38;
    uStack_310 = 0x100000001;
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x68))(WdfDriverGlobals,&local_328);
    if (-1 < iVar2) {
      local_58 = 0x41ef20f84e815ee1;
      uStack_50 = 0x22d7023f283cff8c;
      local_48 = 0xf;
      (**(code **)(WdfFunctions_01015 + 0x2a8))(WdfDriverGlobals,local_338,&local_58);
      local_e0 = 0x200000030;
      uStack_d8 = 2;
      local_d0 = 0x200000002;
      uStack_c8 = 0x200000002;
      uStack_b8 = 0xffffffffffffffff;
      local_c0 = 0x100000002;
      (**(code **)(WdfFunctions_01015 + 0x298))(WdfDriverGlobals,local_338,&local_e0);
      local_8c = 5;
      local_68 = 0xffffffff;
      local_64 = 0xffffffff;
      local_60 = 0xffffffff;
      local_70 = 5;
      local_5c = 5;
      local_a8 = 0x50;
      local_a4 = 2;
      local_a0 = 2;
      local_9c = 2;
      local_98 = 2;
      local_94 = 2;
      local_90 = 2;
      local_6c = 7;
      uStack_88 = 1;
      uStack_84 = 1;
      uStack_80 = 1;
      local_7c = 1;
      uStack_78 = 4;
      local_74 = 4;
      (**(code **)(WdfFunctions_01015 + 0x2a0))(WdfDriverGlobals,local_338,&local_a8);
      puVar5 = &local_108;
      local_f8 = 0x200000002;
      local_e8 = 2;
      local_108 = 0x100000024;
      uStack_100 = 4;
      uStack_f0 = 0x100000002;
      iVar2 = (**(code **)(WdfFunctions_01015 + 0x170))(WdfDriverGlobals,local_338);
      if ((((-1 < iVar2) && (iVar2 = TreeSetupIoQueues(local_338), -1 < iVar2)) &&
          (iVar2 = TreeDriverServicesInitialize(local_338), -1 < iVar2)) &&
         (iVar2 = TreeClassLibraryInitialize(), -1 < iVar2)) {
        puVar1 = (undefined8 *)(lVar3 + 0x20);
        if (*(int *)(lVar3 + 4) == 3) {
          local_178 = (**(code **)(WdfFunctions_01015 + 0xf8))(WdfDriverGlobals,local_338);
          puVar5 = (undefined8 *)0x0;
          local_198._0_4_ = 0x88;
          local_198._4_4_ = 1;
          iVar2 = (**(code **)(WdfFunctions_01015 + 0x538))(WdfDriverGlobals,local_338,0,puVar1);
          if (iVar2 < 0) goto LAB_1400126d6;
          puVar5 = &local_198;
          iVar2 = (**(code **)(WdfFunctions_01015 + 0x540))(WdfDriverGlobals,*puVar1);
          if (iVar2 < 0) goto LAB_1400126d6;
        }
        else {
          *puVar1 = 0;
        }
        uVar4 = (**(code **)(WdfFunctions_01015 + 0x3b0))(WdfDriverGlobals,*WdfDriverGlobals);
        puVar5 = &GUID_DEVINTERFACE_EMMC_PARTITION_ACCESS_RPMB;
        iVar2 = IoRegisterPlugPlayNotification
                          (2,1,&GUID_DEVINTERFACE_EMMC_PARTITION_ACCESS_RPMB,uVar4);
      }
    }
  }
LAB_1400126d6:
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar5,0xb,
                       &WPP_49bb3939113c3b574f8f0bbeefc4fba7_Traceguids,(char)local_338,(char)iVar2)
    ;
  }
  if (param_3 != (undefined8 *)0x0) {
    uVar4 = 0;
    if (-1 < iVar2) {
      uVar4 = local_338;
    }
    *param_3 = uVar4;
  }
  return iVar2;
}



===== TreeSetupIoQueues @ 14001275c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int TreeSetupIoQueues(undefined8 param_1)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  undefined8 local_res10;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined8 local_94;
  undefined8 uStack_8c;
  undefined8 local_84;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined1 local_6b;
  code *local_50;
  code *local_48;
  undefined4 local_28;
  
  local_res10 = 0;
  local_94 = 0;
  uStack_8c = 0;
  local_84 = 0;
  local_7c = 0;
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,
                     PTR__WDF_TREE_MASTER_DEVICE_CONTEXT_TYPE_INFO_14000f0f0);
  memset(&local_78,0,0x60);
  local_28 = 0xffffffff;
  local_78 = 0x60;
  local_c8 = 0;
  local_70 = 2;
  local_50 = TreeEvtDeviceIoControl;
  uStack_d0 = 0;
  local_6b = 1;
  local_48 = TreeEvtDeviceInternalIoControl;
  local_74 = 2;
  local_a8 = 0;
  local_b8 = 0;
  uStack_b0 = 0;
  local_d8 = 0x38;
  uStack_c0 = 0x400000002;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x4c0))
                    (WdfDriverGlobals,param_1,&local_78,&local_d8,&local_res10);
  if (-1 < iVar1) {
    local_94 = 0;
    uStack_8c = 0;
    local_84 = 0;
    local_7c = 0;
    local_a0 = 0x28;
    local_9c = 1;
    local_98 = 1;
    iVar2 = (**(code **)(WdfFunctions_01015 + 0xc30))(WdfDriverGlobals,local_res10,&local_a0);
    iVar1 = 0;
    if (-1 < iVar2) {
      iVar1 = iVar2;
    }
    if (*(int *)(lVar3 + 4) == 3) {
      memset(&local_78,0,0x60);
      local_48 = TreeEvtDeviceRequestSerialization;
      local_78 = 0x60;
      local_a8 = 0;
      local_c8 = 0;
      local_70 = 2;
      uStack_d0 = 0;
      local_74 = 1;
      local_b8 = 0;
      uStack_b0 = 0;
      local_d8 = 0x38;
      uStack_c0 = 0x400000002;
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x4c0))
                        (WdfDriverGlobals,param_1,&local_78,&local_d8,(undefined8 *)(lVar3 + 0x28));
      if (-1 < iVar1) {
        iVar1 = (**(code **)(WdfFunctions_01015 + 0xc30))
                          (WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x28),&local_a0);
        if (iVar1 < 0) {
          iVar1 = 0;
        }
      }
    }
  }
  return iVar1;
}



===== WppCleanupKm @ 140012984 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WppCleanupKm(undefined8 param_1)

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
    WppAutoLogStop(WPP_GLOBAL_Control,param_1);
    WPP_GLOBAL_Control = (undefined *)&WPP_GLOBAL_Control;
    WPP_RECORDER_INITIALIZED = (undefined *)&WPP_RECORDER_INITIALIZED;
  }
  return;
}



===== WppInitKm @ 140012a34 =====

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



===== WppLoadTracingSupport @ 140012b10 =====

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



===== WppTraceCallback @ 140012c60 =====

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



===== wil_details_EvaluateFeatureDependencies @ 140012ee8 =====

/* WARNING: Removing unreachable block (ram,0x000140012f10) */
/* WARNING: Removing unreachable block (ram,0x000140012f20) */
/* WARNING: Removing unreachable block (ram,0x000140012f25) */
/* WARNING: Removing unreachable block (ram,0x000140012f2a) */
/* WARNING: Removing unreachable block (ram,0x000140012f35) */
/* WARNING: Removing unreachable block (ram,0x000140012f4a) */
/* WARNING: Removing unreachable block (ram,0x000140012f40) */
/* WARNING: Removing unreachable block (ram,0x000140012f5a) */
/* WARNING: Removing unreachable block (ram,0x000140012f77) */
/* WARNING: Removing unreachable block (ram,0x000140012f86) */
/* WARNING: Removing unreachable block (ram,0x000140012f8b) */
/* WARNING: Removing unreachable block (ram,0x000140012f7d) */
/* WARNING: Removing unreachable block (ram,0x000140012f8d) */
/* WARNING: Removing unreachable block (ram,0x000140012f92) */
/* WARNING: Removing unreachable block (ram,0x000140012f82) */
/* WARNING: Removing unreachable block (ram,0x000140012f15) */
/* WARNING: Removing unreachable block (ram,0x000140012f1e) */
/* WARNING: Removing unreachable block (ram,0x000140012f9d) */
/* WARNING: Removing unreachable block (ram,0x000140012fa2) */
/* WARNING: Removing unreachable block (ram,0x000140012f94) */
/* WARNING: Removing unreachable block (ram,0x000140012fc5) */
/* WARNING: Removing unreachable block (ram,0x000140012fa4) */
/* WARNING: Removing unreachable block (ram,0x000140012fbe) */
/* WARNING: Removing unreachable block (ram,0x000140012fc3) */
/* WARNING: Removing unreachable block (ram,0x000140012fb5) */
/* WARNING: Removing unreachable block (ram,0x000140012fba) */
/* WARNING: Removing unreachable block (ram,0x000140012f99) */

void wil_details_EvaluateFeatureDependencies(void)

{
  return;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 140012fd8 =====

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
          if (puVar1 == (undefined8 *)0x0) goto LAB_140013074;
          if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
             (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
          if ((uVar4 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
            uVar4 = 0;
            goto LAB_140013074;
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
LAB_140013074:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 1400130e0 =====

void wil_details_OnFeatureUsageProviderFlushNotification(int param_1)

{
  int iVar1;
  longlong *plVar2;
  
  iVar1 = g_wil_details_featureUsageCached;
  if (param_1 == 1) {
    LOCK();
    g_wil_details_featureUsageCached = 0;
    UNLOCK();
    if (iVar1 != 0) {
      for (plVar2 = &wil_details_featureDescriptors_z; plVar2 < &wil_details_featureDescriptors_z;
          plVar2 = plVar2 + 1) {
        if (*plVar2 != 0) {
          do {
            if (plVar2 == (longlong *)0x0) {
              return;
            }
            if ((*(uint *)plVar2[1] & 1) != 0) {
              wil_details_RecordCachedUsage((int)plVar2[3],(uint *)plVar2[1]);
            }
            plVar2 = plVar2 + 7;
            while( true ) {
              if (&UNK_14000ee67 < plVar2) {
                return;
              }
              if (*plVar2 != 0) break;
              plVar2 = plVar2 + 1;
            }
          } while( true );
        }
      }
    }
  }
  return;
}



===== wil_details_RecordFeatureUsageCallback @ 140013160 =====

void wil_details_RecordFeatureUsageCallback(void)

{
  RtlRecordFeatureUsage();
  return;
}



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 140013180 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_ReevaluateOnFeatureConfigurationChange(void)

{
  int iVar1;
  uint uVar2;
  longlong *plVar3;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined8 local_20;
  undefined4 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  for (plVar3 = &wil_details_featureDescriptors_z; plVar3 < &wil_details_featureDescriptors_z;
      plVar3 = plVar3 + 1) {
    if (*plVar3 != 0) goto LAB_14001327d;
  }
LAB_140013286:
  wil_details_EvaluateFeatureDependencies();
  return;
LAB_14001327d:
  if (plVar3 == (longlong *)0x0) goto LAB_140013286;
  if (((*(char *)((longlong)plVar3 + 0x1d) == '\0') && (*(char *)((longlong)plVar3 + 0x1e) == '\0'))
     && (*(char *)((longlong)plVar3 + 0x1c) == '\0')) {
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    iVar1 = RtlQueryFeatureConfiguration((int)plVar3[3],1,&local_28,&local_20);
    if ((iVar1 == -0x7fffffde) || (iVar1 == -0x3ffffddb)) {
LAB_14001324e:
      uVar2 = 0x206;
    }
    else {
      if (iVar1 == 0) {
        uVar2 = (local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0;
      }
      else {
        if (iVar1 != 0x117) goto LAB_14001324e;
        uVar2 = local_20._4_4_ & 0x80;
      }
      uVar2 = uVar2 << 3 | 0x206;
    }
    LOCK();
    *(uint *)*plVar3 = *(uint *)*plVar3 ^ (*(uint *)*plVar3 ^ uVar2) & 0xf80;
    UNLOCK();
  }
  plVar3 = plVar3 + 7;
  while( true ) {
    if (&UNK_14000ee67 < plVar3) goto LAB_140013286;
    if (*plVar3 != 0) break;
    plVar3 = plVar3 + 1;
  }
  goto LAB_14001327d;
}



===== TreeAddServiceDevice @ 1400132ac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong TreeAddServiceDevice
                    (undefined8 param_1,longlong *param_2,undefined8 *param_3,longlong *param_4)

{
  uint uVar1;
  longlong *plVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  longlong lVar5;
  ulonglong uVar6;
  longlong *plVar7;
  longlong *plVar8;
  longlong lVar9;
  undefined1 auStack_318 [48];
  undefined8 local_2e8;
  undefined8 local_2e0;
  ulonglong local_2d8;
  code *local_2d0;
  undefined8 local_2c8;
  undefined4 local_2c0;
  undefined4 local_2bc;
  undefined8 local_2b8;
  undefined8 uStack_2b0;
  undefined *local_2a8;
  undefined4 local_2a0;
  undefined4 local_29c;
  undefined8 local_298;
  undefined8 local_290;
  undefined8 local_288;
  undefined4 local_280;
  undefined4 local_27c;
  undefined8 local_278;
  undefined8 uStack_270;
  undefined8 local_268;
  undefined8 uStack_260;
  undefined8 local_258;
  undefined8 uStack_250;
  undefined8 local_248;
  undefined4 local_240;
  undefined8 local_23c;
  undefined4 local_234;
  code *local_230;
  undefined4 local_228;
  undefined4 local_224;
  undefined8 local_220;
  undefined8 uStack_218;
  undefined *local_210;
  undefined8 local_208;
  code *local_200;
  undefined8 local_1f8;
  undefined4 local_1f0;
  undefined4 local_1ec;
  undefined8 local_1e8;
  undefined8 uStack_1e0;
  undefined *local_1d8;
  undefined8 local_1d0;
  undefined8 uStack_1c8;
  undefined8 local_1c0;
  undefined8 uStack_1b8;
  undefined8 local_1b0;
  undefined8 uStack_1a8;
  undefined *local_1a0;
  undefined4 local_198 [2];
  code *local_190;
  code *local_180;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined4 local_e8;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 local_ac;
  undefined4 uStack_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 local_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 local_68;
  undefined4 uStack_64;
  undefined8 uStack_60;
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStack_318;
  local_248 = 0;
  local_e8 = 0;
  local_1a0 = (undefined *)0x0;
  local_278 = 0;
  uStack_270 = 0;
  local_29c = 0;
  local_268 = 0;
  uStack_260 = 0;
  local_2d8 = (ulonglong)(uint)local_2d8;
  local_258 = 0;
  uStack_250 = 0;
  local_2c8 = 0;
  local_108 = 0;
  uStack_100 = 0;
  local_2e8 = 0;
  local_f8 = 0;
  uStack_f0 = 0;
  local_88 = 0;
  uStack_84 = 0;
  uStack_80 = 0;
  uStack_7c = 0;
  local_78 = 0;
  uStack_74 = 0;
  uStack_70 = 0;
  uStack_6c = 0;
  local_68 = 0;
  uStack_64 = 0;
  uStack_60 = 0;
  local_2b8 = 0;
  uStack_2b0 = 0;
  local_1d0 = 0;
  uStack_1c8 = 0;
  local_1c0 = 0;
  uStack_1b8 = 0;
  local_1b0 = 0;
  uStack_1a8 = 0;
  local_2e0 = param_1;
  (**(code **)(WdfFunctions_01015 + 0x230))(WdfDriverGlobals,param_1,0x180,1);
  (**(code **)(WdfFunctions_01015 + 0x1e8))(WdfDriverGlobals,local_2e0,2);
  (**(code **)(WdfFunctions_01015 + 0x210))(WdfDriverGlobals,local_2e0,0x56);
  local_1d8 = PTR__WDF_TREE_SERVICE_DEVICE_CONTEXT_TYPE_INFO_14000f078;
  local_208 = 0x38;
  local_200 = TreeSecureServicesEvtDeviceCleanup;
  local_210 = PTR__WDF_TREE_SERVICE_SESSION_CONTEXT_TYPE_INFO_14000f118;
  local_230 = TreeSecureServicesEvtDestroyFileObject;
  local_1f8 = 0;
  local_1e8 = 0;
  uStack_1e0 = 0;
  local_1f0 = 1;
  local_1ec = 4;
  local_23c = 0;
  local_234 = 0;
  local_220 = 0;
  uStack_218 = 0;
  local_240 = 0x38;
  local_228 = 1;
  local_224 = 4;
  local_2a0 = 0x28;
  local_298 = 0;
  local_290 = 0;
  local_288 = 0;
  local_27c = 4;
  local_280 = 2;
  (**(code **)(WdfFunctions_01015 + 0x238))(WdfDriverGlobals,local_2e0,&local_2a0,&local_240);
  local_2a8 = PTR__WDF_TREE_SECURE_SERVICES_REQUEST_CONTEXT_TYPE_INFO_14000f0a0;
  local_2d0 = TreeEvtDriverServicesPluginIoTargetRemoveComplete;
  local_2d8 = 0x38;
  local_2c8 = 0;
  local_2b8 = 0;
  uStack_2b0 = 0;
  local_2c0 = 1;
  local_2bc = 1;
  (**(code **)(WdfFunctions_01015 + 0x240))(WdfDriverGlobals,local_2e0,&local_2d8);
  (**(code **)(WdfFunctions_01015 + 0x250))
            (WdfDriverGlobals,local_2e0,TreeSecureServicesEvtIoInCallerContext);
  memset(local_198,0,0x90);
  local_190 = TreeSecureServicesEvtDeviceD0Entry;
  local_180 = TreeSecureServicesEvtDeviceD0Exit;
  local_198[0] = 0x90;
  (**(code **)(WdfFunctions_01015 + 0x1b8))(WdfDriverGlobals,local_2e0,local_198);
  uVar1 = (**(code **)(WdfFunctions_01015 + 600))(WdfDriverGlobals,&local_2e0,&local_208,&local_2e8)
  ;
  uVar6 = (ulonglong)uVar1;
  if (-1 < (int)uVar1) {
    memset(&local_d8,0,0x50);
    local_bc = 5;
    local_a0 = 5;
    local_8c = 5;
    local_d8 = 0x50;
    local_98 = 0xffffffff;
    local_94 = 0xffffffff;
    local_90 = 0xffffffff;
    local_d4 = 2;
    local_d0 = 2;
    local_cc = 2;
    local_c8 = 2;
    local_c4 = 2;
    local_c0 = 2;
    local_9c = 7;
    uStack_b8 = 1;
    uStack_b4 = 1;
    uStack_b0 = 1;
    local_ac = 1;
    uStack_a8 = 4;
    local_a4 = 4;
    (**(code **)(WdfFunctions_01015 + 0x2a0))(WdfDriverGlobals,local_2e8,&local_d8);
    local_f8 = 0x200000002;
    local_e8 = 2;
    local_108 = 0x100000024;
    uStack_100 = 4;
    uStack_f0 = 0x100000002;
    uVar1 = (**(code **)(WdfFunctions_01015 + 0x170))(WdfDriverGlobals,local_2e8,&local_108);
    uVar6 = (ulonglong)uVar1;
    if (-1 < (int)uVar1) {
      plVar2 = (longlong *)
               (**(code **)(WdfFunctions_01015 + 0x650))
                         (WdfDriverGlobals,local_2e8,
                          PTR__WDF_TREE_SERVICE_DEVICE_CONTEXT_TYPE_INFO_14000f078);
      lVar5 = param_2[1];
      plVar2[0xb] = *param_2;
      plVar2[0xc] = lVar5;
      local_258 = local_2e8;
      local_278 = CONCAT44(local_278._4_4_,0x38);
      uStack_260 = 0x100000001;
      uVar1 = (**(code **)(WdfFunctions_01015 + 0x68))(WdfDriverGlobals,&local_278,plVar2 + 8);
      uVar6 = (ulonglong)uVar1;
      if (-1 < (int)uVar1) {
        uVar1 = (**(code **)(WdfFunctions_01015 + 0x9d8))(WdfDriverGlobals,&local_278,plVar2 + 7);
        uVar6 = (ulonglong)uVar1;
        if (-1 < (int)uVar1) {
          local_1a0 = PTR__WDF_TREE_SESSION_CALL_DATA_TYPE_INFO_14000f0c8;
          local_1d0 = CONCAT44(local_1d0._4_4_,0x38);
          uStack_1b8 = 0x100000001;
          uVar1 = (**(code **)(WdfFunctions_01015 + 0x678))(WdfDriverGlobals,&local_1d0,plVar2 + 5);
          uVar6 = (ulonglong)uVar1;
          if (-1 < (int)uVar1) {
            KeInitializeEvent(plVar2 + 2,1,1);
            uStack_60 = 0xffffffffffffffff;
            local_88 = 0x30;
            uStack_84 = 2;
            uStack_80 = 2;
            uStack_7c = 2;
            local_78 = 2;
            uStack_64 = 1;
            uStack_74 = 2;
            uStack_70 = 2;
            uStack_6c = 2;
            local_68 = 2;
            (**(code **)(WdfFunctions_01015 + 0x298))(WdfDriverGlobals,local_2e8,&local_88);
            plVar8 = &TreeSecureServiceChildHidMap;
            while( true ) {
              if ((*plVar8 == 0) && (plVar8[1] == 0)) goto LAB_14001385a;
              if ((*plVar8 == *param_2) && (plVar8[1] == param_2[1])) break;
              plVar8 = plVar8 + 3;
            }
            uVar1 = TreeSecureServiceCreateChildDevice(local_2e8,(undefined4 *)param_2,plVar8[2]);
            uVar6 = (ulonglong)uVar1;
            if (-1 < (int)uVar1) {
LAB_14001385a:
              plVar8 = plVar2 + 1;
              uVar3 = TreeReportNewSecureServiceDevice(local_2e8,plVar8,plVar2);
              uVar6 = uVar3 & 0xffffffff;
              if (-1 < (int)uVar3) {
                lVar5 = *plVar2;
                for (plVar7 = &TreeSecureServiceSecurityMap;
                    ((*plVar7 != 0 || (plVar7[1] != 0)) &&
                    ((*plVar7 != *param_2 || (plVar7[1] != param_2[1])))); plVar7 = plVar7 + 3) {
                }
                lVar9 = plVar7[2];
                if ((((*plVar7 == 0) && (plVar7[1] == 0)) && (*(uint *)(lVar5 + 0x1c) != 0)) &&
                   (uVar1 = *(uint *)((ulonglong)*(uint *)(lVar5 + 0x1c) + 4 + lVar5), uVar1 != 0))
                {
                  lVar9 = lVar5 + (ulonglong)uVar1;
                }
                uVar1 = SeConvertStringSecurityDescriptorToSecurityDescriptor(lVar9,1,plVar2 + 9,0);
                uVar6 = (ulonglong)uVar1;
                if (-1 < (int)uVar1) {
                  uVar4 = (**(code **)(WdfFunctions_01015 + 0x108))(WdfDriverGlobals,local_2e8);
                  uVar1 = ObSetSecurityObjectByPointer(uVar4,4,plVar2[9]);
                  uVar6 = (ulonglong)uVar1;
                  if (-1 < (int)uVar1) {
                    lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                                      (WdfDriverGlobals,*plVar8,
                                       PTR__WDF_TREE_MASTER_DEVICE_CONTEXT_TYPE_INFO_14000f0f0);
                    plVar2[0xd] = lVar5;
                    uVar3 = TreeSecureServicesCreateDefaultIoQueue(local_2e8);
                    uVar6 = uVar3 & 0xffffffff;
                    if (-1 < (int)uVar3) {
                      *param_3 = local_2e8;
                      *param_4 = *plVar8;
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
  return uVar6;
}



===== TreeSecureServicesCreateDefaultIoQueue @ 1400139a8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong TreeSecureServicesCreateDefaultIoQueue(undefined8 param_1)

{
  longlong lVar1;
  uint uVar2;
  longlong lVar3;
  ulonglong uVar4;
  int iVar5;
  undefined8 local_res10;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined8 local_cc;
  undefined4 local_c4;
  code *local_c0;
  code *local_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined4 local_78;
  int local_74;
  undefined4 local_70;
  undefined1 local_6b;
  code *local_68;
  code *local_50;
  undefined4 local_28;
  
  local_res10 = 0;
  local_cc = 0;
  local_c4 = 0;
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,
                     PTR__WDF_TREE_SERVICE_DEVICE_CONTEXT_TYPE_INFO_14000f078);
  lVar1 = *(longlong *)(lVar3 + 0x68);
  if ((*(int *)(lVar1 + 4) == 2) || (iVar5 = 2, *(int *)(lVar1 + 4) == 3)) {
    iVar5 = 1;
  }
  memset(&local_78,0,0x60);
  local_78 = 0x60;
  local_70 = 2;
  local_6b = 1;
  if (iVar5 == 2) {
    local_28 = 0xffffffff;
  }
  local_68 = TreeSecureServicesEvtDefaultIo;
  local_a0 = 0;
  local_50 = TreeSecureServicesEvtDeviceIoControl;
  uStack_98 = 0x400000002;
  local_80 = 0;
  uStack_a8 = 0;
  local_b0 = 0x38;
  local_90 = 0;
  uStack_88 = 0;
  local_74 = iVar5;
  uVar4 = (**(code **)(WdfFunctions_01015 + 0x4c0))
                    (WdfDriverGlobals,param_1,&local_78,&local_b0,&local_res10);
  if ((-1 < (int)uVar4) &&
     (uVar4 = (**(code **)(WdfFunctions_01015 + 0x2e8))(WdfDriverGlobals,param_1,local_res10,0),
     -1 < (int)uVar4)) {
    if ((*(int *)(lVar1 + 4) == 3) &&
       (uVar4 = (**(code **)(WdfFunctions_01015 + 0x7b8))
                          (WdfDriverGlobals,0,*(undefined8 *)(lVar1 + 0x20),lVar3 + 0x50),
       (int)uVar4 < 0)) {
      return uVar4;
    }
    local_b8 = TreeSecureServicesEvtIoAllocateRequestResources;
    local_c0 = TreeSecureServicesEvtIoAllocateResourcesForReservedRequest;
    local_cc = 0;
    local_c4 = 0;
    local_d8 = 0x28;
    local_d4 = 1;
    local_d0 = 1;
    uVar2 = (**(code **)(WdfFunctions_01015 + 0xc30))(WdfDriverGlobals,local_res10,&local_d8);
    uVar4 = (ulonglong)uVar2;
    if ((int)uVar2 < 0) {
      uVar4 = 0;
    }
  }
  return uVar4;
}



===== __security_init_cookie @ 140014008 =====

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



===== DriverEntry @ 14001403c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(undefined *param_1,undefined *param_2)

{
  int iVar1;
  undefined *puVar2;
  undefined8 local_res18 [2];
  undefined8 local_28;
  undefined8 local_20;
  code *local_18;
  undefined4 local_10;
  undefined4 local_c;
  
  local_res18[0] = 0;
  wil_InitializeFeatureStaging();
  _WPP_MAIN_CB = 0;
  DAT_14000f4a8 = &WPP_ThisDir_CTLGUID_WindowsTrustedRT;
  DAT_14000f4b0 = 0;
  _DAT_14000f4c0 = 0;
  _DAT_14000f4c8 = 1;
  _DAT_14000f4e0 = 0;
  _DAT_14000f4e8 = 0;
  WppLoadTracingSupport();
  _DAT_14000f4c0 = 0;
  WppInitKm(param_1,param_2);
  local_28 = 0x20;
  local_18 = TreeEvtDriverUnload;
  local_10 = 0;
  local_20 = 0;
  local_c = 0x45457254;
  puVar2 = param_2;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x3a0))
                    (WdfDriverGlobals,param_1,param_2,0,&local_28,local_res18);
  if (-1 < iVar1) {
    iVar1 = TreeInitControlDevice(local_res18[0]);
    if (-1 < iVar1) {
      puVar2 = &DAT_14000d030;
      iVar1 = WdfRegisterClassLibrary(&TreeClassLibraryInfo);
      param_1 = param_2;
    }
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_1,puVar2,10,
                      &WPP_49bb3939113c3b574f8f0bbeefc4fba7_Traceguids,(char)iVar1);
  }
  if (iVar1 < 0) {
    if (TreeControlDevice != 0) {
      (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
      TreeControlDevice = 0;
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
  }
  return iVar1;
}



===== TreeInitControlDevice @ 14001420c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int TreeInitControlDevice(undefined8 param_1)

{
  int iVar1;
  code *pcVar2;
  longlong lVar3;
  undefined1 auStack_178 [32];
  undefined8 *local_158;
  undefined4 local_150;
  longlong local_138 [2];
  undefined8 *local_128;
  undefined8 local_120;
  undefined8 uStack_118;
  undefined8 local_110;
  undefined8 uStack_108;
  undefined8 local_100;
  undefined8 uStack_f8;
  undefined8 local_f0;
  undefined8 local_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined1 local_ab;
  code *local_90;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined2 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_178;
  local_e8 = 0;
  local_c0 = 0;
  local_e0 = 0;
  uStack_d8 = 0;
  local_d0 = 0;
  uStack_c8 = 0;
  memset(&local_b8,0,0x60);
  local_138[0] = 0;
  TreeControlDevice = 0;
  local_58 = 0x73006f0044005c;
  uStack_50 = 0x69007600650044;
  local_20 = 0;
  local_128 = &local_58;
  local_f0 = 0;
  local_38 = 0x5400730077006f;
  uStack_30 = 0x74007300750072;
  local_138[1] = 0x3a0038;
  local_28 = 0x54005200640065;
  local_110 = 0;
  uStack_118 = 0;
  local_120 = 0x38;
  uStack_f8 = 0;
  uStack_108 = 0x100000001;
  local_48 = 0x650063;
  uStack_44 = 0x5c0073;
  uStack_40 = 0x690057;
  uStack_3c = 0x64006e;
  local_100 = param_1;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x68))
                    (WdfDriverGlobals,&local_120,&TreeSecureServiceCollection);
  if (-1 < iVar1) {
    local_138[0] = (**(code **)(WdfFunctions_01015 + 200))(WdfDriverGlobals,param_1,&DAT_14000d020);
    if (local_138[0] == 0) {
      iVar1 = -0x3fffff66;
    }
    else {
      (**(code **)(WdfFunctions_01015 + 0x1e8))(WdfDriverGlobals,local_138[0],2);
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x218))
                        (WdfDriverGlobals,local_138[0],&DAT_14000d010);
      if (-1 < iVar1) {
        uStack_d8 = 0;
        local_d0 = 0;
        uStack_c8 = 0;
        local_e0 = CONCAT44(local_e0._4_4_,0x28);
        local_c0 = 0x8000000200000002;
        (**(code **)(WdfFunctions_01015 + 0x238))(WdfDriverGlobals,local_138[0],&local_e0,0);
        local_150 = 0;
        local_158 = (undefined8 *)0x0;
        iVar1 = (**(code **)(WdfFunctions_01015 + 0x248))
                          (WdfDriverGlobals,local_138[0],TreeEvtControlWdmDeviceFileCreate,0);
        if (-1 < iVar1) {
          local_f0 = 0;
          local_110 = 0;
          uStack_118 = 0;
          local_120 = 0x38;
          local_100 = 0;
          uStack_f8 = 0;
          uStack_108 = 0x100000002;
          iVar1 = (**(code **)(WdfFunctions_01015 + 600))
                            (WdfDriverGlobals,local_138,&local_120,&TreeControlDevice);
          if (-1 < iVar1) {
            local_90 = TreeEvtControlDeviceIoControl;
            local_158 = &local_e8;
            local_b8 = 0x60;
            local_b0 = 2;
            local_ab = 1;
            local_b4 = 1;
            (**(code **)(WdfFunctions_01015 + 0x4c0))
                      (WdfDriverGlobals,TreeControlDevice,&local_b8,0);
            iVar1 = (**(code **)(WdfFunctions_01015 + 0x280))
                              (WdfDriverGlobals,TreeControlDevice,local_138 + 1);
            if (-1 < iVar1) {
              pcVar2 = *(code **)(WdfFunctions_01015 + 0xd8);
              lVar3 = TreeControlDevice;
              goto LAB_14001456c;
            }
          }
        }
      }
    }
  }
  if (TreeControlDevice != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,TreeControlDevice);
    TreeControlDevice = 0;
  }
  if (local_138[0] == 0) {
    return iVar1;
  }
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x1b0);
  lVar3 = local_138[0];
LAB_14001456c:
  (*pcVar2)(WdfDriverGlobals,lVar3);
  return iVar1;
}



===== wil_InitializeFeatureStaging @ 1400145a8 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int wil_InitializeFeatureStaging(void)

{
  bool bVar1;
  int iVar2;
  longlong *plVar3;
  undefined8 local_res8;
  
  bVar1 = false;
  if (g_wil_details_isFeatureStagingInitialized == 0) {
    g_wil_details_isFeatureStagingInitialized = 1;
    local_res8 = RtlQueryFeatureConfigurationChangeStamp();
    wil_details_PopulateInitialConfiguredFeatureStates();
    wil_details_EvaluateFeatureDependencies();
    for (plVar3 = &wil_details_featureDescriptors_z; plVar3 < &wil_details_featureDescriptors_z;
        plVar3 = plVar3 + 1) {
      if (*plVar3 != 0) goto LAB_14001462f;
    }
LAB_140014669:
    _g_wil_details_recordFeatureUsage = wil_details_RecordFeatureUsageReporting;
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
LAB_14001462f:
  if (plVar3 == (longlong *)0x0) goto LAB_140014669;
  if (((*(char *)((longlong)plVar3 + 0x1d) == '\0') && (*(char *)((longlong)plVar3 + 0x1e) == '\0'))
     && (*(char *)((longlong)plVar3 + 0x1c) == '\0')) {
    iVar2 = RtlRegisterFeatureConfigurationChangeNotification
                      (wil_details_ReevaluateOnFeatureConfigurationChange,0,&local_res8,
                       &g_wil_details_featureChangeNotification);
    if (iVar2 == 0) {
      bVar1 = true;
    }
    else {
      g_wil_details_featureChangeNotification = 0;
    }
    goto LAB_140014669;
  }
  plVar3 = plVar3 + 7;
  while( true ) {
    if (&UNK_14000ee67 < plVar3) goto LAB_140014669;
    if (*plVar3 != 0) break;
    plVar3 = plVar3 + 1;
  }
  goto LAB_14001462f;
}



===== wil_details_PopulateInitialConfiguredFeatureStates @ 1400146bc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_PopulateInitialConfiguredFeatureStates(void)

{
  ulonglong *puVar1;
  undefined8 *puVar2;
  int iVar3;
  longlong *plVar4;
  undefined1 auStack_48 [32];
  ulonglong local_28;
  undefined8 local_20;
  undefined4 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  plVar4 = &wil_details_featureDescriptors_z;
  while( true ) {
    if (&wil_details_featureDescriptors_z <= plVar4) {
      return;
    }
    if (*plVar4 != 0) break;
    plVar4 = plVar4 + 1;
  }
  do {
    if (plVar4 == (longlong *)0x0) {
      return;
    }
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    if ((*(char *)((longlong)plVar4 + 0x1d) == '\0') && (*(char *)((longlong)plVar4 + 0x1e) == '\0')
       ) {
      iVar3 = RtlQueryFeatureConfiguration
                        ((int)plVar4[3],1 < (byte)(*(char *)((longlong)plVar4 + 0x1c) - 2U),
                         &local_28,&local_20);
      if (iVar3 == -0x7fffffde) {
        do {
          puVar2 = (undefined8 *)*plVar4;
          plVar4 = plVar4 + 7;
          *puVar2 = 0x206;
          while( true ) {
            if (&UNK_14000ee67 < plVar4) {
              return;
            }
            if (*plVar4 != 0) break;
            plVar4 = plVar4 + 1;
          }
        } while (plVar4 != (longlong *)0x0);
        return;
      }
      if (iVar3 == -0x3ffffddb) goto LAB_1400147a6;
      if (iVar3 == 0) {
        local_28 = (ulonglong)(((local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0) << 3 | 0x206);
      }
      else {
        if (iVar3 != 0x117) goto LAB_1400147a6;
        local_28 = (ulonglong)((local_20._4_4_ & 0x80) << 3 | 0x206);
      }
    }
    else {
LAB_1400147a6:
      local_28 = 0x206;
    }
    puVar1 = (ulonglong *)*plVar4;
    plVar4 = plVar4 + 7;
    *puVar1 = local_28;
    while( true ) {
      if (&UNK_14000ee67 < plVar4) {
        return;
      }
      if (*plVar4 != 0) break;
      plVar4 = plVar4 + 1;
    }
  } while( true );
}


