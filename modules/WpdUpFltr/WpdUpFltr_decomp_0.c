
===== __report_gsfailure @ 1c0001010 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== __C_specific_handler @ 1c000101d =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001c000101d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== FilterEvtFileCleanup @ 1c0001030 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FilterEvtFileCleanup(undefined8 param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  longlong lVar5;
  char *pcVar6;
  undefined8 *puVar7;
  undefined *puVar8;
  
  uVar4 = (**(code **)(WdfFunctions_01015 + 0x458))(WdfDriverGlobals,param_1);
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar4,PTR__WDF_FILTER_EXTENSION_TYPE_INFO_1c0006018);
  pcVar6 = (char *)(**(code **)(WdfFunctions_01015 + 0x650))
                             (WdfDriverGlobals,param_1,PTR__WDF_FILE_CXT_TYPE_INFO_1c0006070);
  if ((*(int *)(lVar5 + 8) == 0) && (*pcVar6 != '\0')) {
    puVar8 = PTR__WDF_PROCESS_CXT_TYPE_INFO_1c0006048;
    puVar7 = (undefined8 *)
             (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,*(undefined8 *)(pcVar6 + 8))
    ;
    (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,puVar7[2]);
    (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(lVar5 + 0x18));
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) {
      uVar2 = *(uint *)(puVar7 + 1);
      puVar8 = (undefined *)(ulonglong)uVar2;
      WPP_SF_qqqqDDq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(ulonglong)(uVar2 - 1),puVar8,uVar4,
                     (char)param_1,(char)*(undefined8 *)(pcVar6 + 0x18),
                     (char)*(undefined8 *)(pcVar6 + 8),(char)uVar2,(char)(uVar2 - 1),(char)puVar7[5]
                    );
    }
    piVar1 = (int *)(puVar7 + 1);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      puVar8 = *(undefined **)(pcVar6 + 8);
      (**(code **)(WdfFunctions_01015 + 0x80))(WdfDriverGlobals,*(undefined8 *)(lVar5 + 0x10));
      pcVar6[0x10] = '\x01';
    }
    (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(lVar5 + 0x18));
    if (pcVar6[0x10] != '\0') {
      *(undefined1 *)(puVar7 + 6) = 0;
      if (puVar7[5] != 0) {
        iVar3 = IoDecrementKeepAliveCount(puVar7[5],*puVar7);
        ObfDereferenceObjectWithTag(puVar7[5],0x66754450);
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) {
          WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2e,puVar8,puVar7[5],(char)*puVar7);
        }
        puVar7[5] = 0;
        if (((iVar3 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
          WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,puVar8,iVar3);
        }
      }
    }
    (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,puVar7[2]);
  }
  return;
}



===== FilterEvtFileClose @ 1c00012b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FilterEvtFileClose(undefined8 param_1)

{
  int iVar1;
  uint uVar2;
  undefined8 uVar3;
  longlong lVar4;
  char *pcVar5;
  longlong *plVar6;
  longlong lVar7;
  undefined *puVar8;
  
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x458))(WdfDriverGlobals,param_1);
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar3,PTR__WDF_FILTER_EXTENSION_TYPE_INFO_1c0006018);
  pcVar5 = (char *)(**(code **)(WdfFunctions_01015 + 0x650))
                             (WdfDriverGlobals,param_1,PTR__WDF_FILE_CXT_TYPE_INFO_1c0006070);
  if (*(int *)(lVar4 + 8) != 0) {
    return;
  }
  if (*pcVar5 == '\0') {
    return;
  }
  lVar7 = 0;
  puVar8 = PTR__WDF_PROCESS_CXT_TYPE_INFO_1c0006048;
  plVar6 = (longlong *)
           (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,*(undefined8 *)(pcVar5 + 8));
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) {
    WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(ulonglong)(byte)pcVar5[0x10],puVar8,
              param_1,pcVar5[0x10]);
  }
  if (pcVar5[0x10] != '\0') {
    (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,plVar6[2]);
    if (*plVar6 != 0) {
      if (plVar6[5] != 0) {
        iVar1 = IoDecrementKeepAliveCount();
        ObfDereferenceObjectWithTag(plVar6[5],0x66754450);
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) {
          WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2e,puVar8,plVar6[5],(char)*plVar6);
        }
        plVar6[5] = 0;
        if (((iVar1 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
          WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,puVar8,iVar1);
        }
      }
      ObfDereferenceObjectWithTag(*plVar6,0x66754450);
      *plVar6 = 0;
      (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(lVar4 + 0x28));
      uVar2 = (**(code **)(WdfFunctions_01015 + 0x70))
                        (WdfDriverGlobals,*(undefined8 *)(lVar4 + 0x20));
      if ((2 < uVar2) ||
         (iVar1 = (**(code **)(WdfFunctions_01015 + 0x78))
                            (WdfDriverGlobals,*(undefined8 *)(lVar4 + 0x20),
                             *(undefined8 *)(pcVar5 + 8)), iVar1 < 0)) {
        lVar7 = plVar6[2];
      }
      (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(lVar4 + 0x28));
    }
    (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,plVar6[2]);
  }
  (**(code **)(WdfFunctions_01015 + 0x670))
            (WdfDriverGlobals,plVar6[2],FilterEvtFileClose,0x2c1,
             "multimedia\\wpd\\drivers\\class\\upfltr\\filter.c");
  (**(code **)(WdfFunctions_01015 + 0x670))
            (WdfDriverGlobals,*(undefined8 *)(pcVar5 + 8),FilterEvtFileClose,0x2c4,
             "multimedia\\wpd\\drivers\\class\\upfltr\\filter.c");
  if (lVar7 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,lVar7);
  }
  return;
}



===== FilterEvtIoDeviceControl @ 1c00015d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FilterEvtIoDeviceControl(undefined8 param_1,undefined8 param_2)

{
  bool bVar1;
  undefined1 uVar2;
  int iVar3;
  undefined8 uVar4;
  longlong lVar5;
  undefined8 uVar6;
  char *pcVar7;
  longlong *plVar8;
  undefined *puVar9;
  
  uVar4 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar4,PTR__WDF_FILTER_EXTENSION_TYPE_INFO_1c0006018);
  if (*(int *)(lVar5 + 8) == 0) {
    uVar6 = (**(code **)(WdfFunctions_01015 + 0x8a8))(WdfDriverGlobals,param_2);
    pcVar7 = (char *)(**(code **)(WdfFunctions_01015 + 0x650))
                               (WdfDriverGlobals,uVar6,PTR__WDF_FILE_CXT_TYPE_INFO_1c0006070);
  }
  else {
    pcVar7 = (char *)0x0;
  }
  if ((*(int *)(lVar5 + 8) != 0) || (*pcVar7 == '\0')) {
    uVar4 = (**(code **)(WdfFunctions_01015 + 0x150))(WdfDriverGlobals,uVar4);
    goto LAB_1c0001871;
  }
  iVar3 = 0;
  bVar1 = true;
  puVar9 = PTR__WDF_PROCESS_CXT_TYPE_INFO_1c0006048;
  plVar8 = (longlong *)
           (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,*(undefined8 *)(pcVar7 + 8));
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,plVar8[2]);
  if ((char)plVar8[6] != '\0') {
    iVar3 = 0;
    if ((plVar8[5] == 0) && (*plVar8 != 0)) {
      lVar5 = *(longlong *)(pcVar7 + 0x18);
      iVar3 = IoIncrementKeepAliveCount(lVar5);
      if (-1 < iVar3) {
        plVar8[5] = lVar5;
        ObfReferenceObjectWithTag(lVar5,0x66754450);
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) {
          WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2d,puVar9,plVar8[5],(char)*plVar8);
          goto LAB_1c0001777;
        }
      }
      if (iVar3 < 0) goto LAB_1c000177f;
    }
LAB_1c0001777:
    LOCK();
    *(int *)(plVar8 + 4) = (int)plVar8[4] + 1;
    UNLOCK();
    bVar1 = false;
  }
LAB_1c000177f:
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,plVar8[2]);
  if (iVar3 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) {
      uVar2 = (**(code **)(WdfFunctions_01015 + 0x660))(WdfDriverGlobals,pcVar7);
      WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,puVar9,uVar4,uVar2);
    }
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar3);
    return;
  }
  uVar4 = (**(code **)(WdfFunctions_01015 + 0x150))(WdfDriverGlobals,uVar4);
  if (!bVar1) {
    ForwardRequestWithCompletionRoutine(param_2,uVar4,FilterIoCtlCompletionRoutine);
    return;
  }
LAB_1c0001871:
  ForwardAndForgetRequest(param_2,uVar4);
  return;
}



===== FilterFileCreateCompletionRoutine @ 1c00018a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FilterFileCreateCompletionRoutine(undefined8 param_1,undefined8 param_2,longlong param_3)

{
  undefined1 uVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  longlong lVar5;
  undefined1 *puVar6;
  longlong lVar7;
  longlong lVar8;
  undefined8 uVar9;
  undefined2 uVar10;
  undefined8 uVar11;
  undefined *puVar12;
  undefined8 *puVar13;
  code *pcVar14;
  undefined8 local_res18;
  undefined1 uVar15;
  
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x8a8))(WdfDriverGlobals,param_1);
  uVar4 = (**(code **)(WdfFunctions_01015 + 0x458))(WdfDriverGlobals,uVar3);
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar4,PTR__WDF_FILTER_EXTENSION_TYPE_INFO_1c0006018);
  if ((*(int *)(param_3 + 8) < 0) || (*(int *)(lVar5 + 8) != 0)) goto LAB_1c0001bf0;
  local_res18 = 0;
  puVar12 = PTR__WDF_FILE_CXT_TYPE_INFO_1c0006070;
  puVar6 = (undefined1 *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,uVar3);
  lVar7 = (**(code **)(WdfFunctions_01015 + 0x460))(WdfDriverGlobals,uVar3);
  *(longlong *)(puVar6 + 0x18) = lVar7;
  uVar15 = (undefined1)uVar3;
  if (lVar7 == 0) {
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) == 0)) goto LAB_1c0001bf0;
    uVar10 = 0x27;
LAB_1c00019bc:
    WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar10,puVar12,uVar4,uVar15);
  }
  else {
    *(uint *)(lVar7 + 0x50) = *(uint *)(lVar7 + 0x50) | 0x20000000;
    lVar7 = IoGetInitiatorProcess(*(undefined8 *)(puVar6 + 0x18));
    if (lVar7 == 0) {
      uVar3 = (**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals,param_1);
      lVar7 = IoGetRequestorProcess(uVar3);
      if (lVar7 == 0) {
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) == 0)) goto LAB_1c0001bf0;
        uVar10 = 0x28;
        goto LAB_1c00019bc;
      }
    }
    (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(lVar5 + 0x18));
    puVar13 = &local_res18;
    lVar8 = lVar7;
    iVar2 = GetProcessObjectForEProcess(lVar5,lVar7,puVar13);
    uVar3 = local_res18;
    if (iVar2 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_qqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),lVar8,puVar13,uVar4,uVar15,(char)lVar7
                  );
      }
    }
    else {
      lVar8 = (**(code **)(WdfFunctions_01015 + 0x650))
                        (WdfDriverGlobals,local_res18,PTR__WDF_PROCESS_CXT_TYPE_INFO_1c0006048);
      *(undefined8 *)(puVar6 + 8) = uVar3;
      *(int *)(lVar8 + 8) = *(int *)(lVar8 + 8) + 1;
      (**(code **)(WdfFunctions_01015 + 0x668))
                (WdfDriverGlobals,*(undefined8 *)(lVar8 + 0x10),FilterEvtFileClose,0x4c7,
                 "multimedia\\wpd\\drivers\\class\\upfltr\\filter.c");
      pcVar14 = FilterEvtFileClose;
      (**(code **)(WdfFunctions_01015 + 0x668))
                (WdfDriverGlobals,uVar3,FilterEvtFileClose,0x4c8,
                 "multimedia\\wpd\\drivers\\class\\upfltr\\filter.c");
      *puVar6 = 1;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) {
        uVar11 = param_1;
        uVar9 = (**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals);
        uVar1 = IoGetRequestorProcessId(uVar9);
        WPP_SF_qqqqL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar11,pcVar14,uVar4,uVar15,
                     (char)uVar3,(char)lVar7,uVar1);
      }
    }
    (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(lVar5 + 0x18));
  }
LAB_1c0001bf0:
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_1,*(undefined4 *)(param_3 + 8));
  return;
}



===== FilterIoCtlCompletionRoutine @ 1c0001c40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FilterIoCtlCompletionRoutine(undefined8 param_1,undefined8 param_2,longlong param_3)

{
  longlong *plVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  longlong lVar5;
  char *pcVar6;
  longlong *plVar7;
  undefined *puVar8;
  
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x8a8))(WdfDriverGlobals,param_1);
  uVar4 = (**(code **)(WdfFunctions_01015 + 0x458))(WdfDriverGlobals,uVar3);
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar4,PTR__WDF_FILTER_EXTENSION_TYPE_INFO_1c0006018);
  pcVar6 = (char *)(**(code **)(WdfFunctions_01015 + 0x650))
                             (WdfDriverGlobals,uVar3,PTR__WDF_FILE_CXT_TYPE_INFO_1c0006070);
  if ((*(int *)(lVar5 + 8) == 0) && (*pcVar6 != '\0')) {
    puVar8 = PTR__WDF_PROCESS_CXT_TYPE_INFO_1c0006048;
    plVar7 = (longlong *)
             (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,*(undefined8 *)(pcVar6 + 8))
    ;
    LOCK();
    plVar1 = plVar7 + 4;
    lVar5 = *plVar1;
    *(int *)plVar1 = (int)*plVar1 + -1;
    UNLOCK();
    if ((int)lVar5 == 1) {
      lVar5 = plVar7[2];
      (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals);
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) {
        WPP_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),lVar5,puVar8,plVar7,(char)plVar7[5],
                   (char)plVar7[4]);
      }
      if (((*plVar7 != 0) && ((int)plVar7[4] == 0)) && (plVar7[5] != 0)) {
        iVar2 = IoDecrementKeepAliveCount(plVar7[5],*plVar7);
        ObfDereferenceObjectWithTag(plVar7[5],0x66754450);
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) {
          WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2e,puVar8,plVar7[5],(char)*plVar7);
        }
        plVar7[5] = 0;
        if (((iVar2 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
          WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2c,puVar8,iVar2);
        }
      }
      (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,plVar7[2]);
    }
  }
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_1,*(undefined4 *)(param_3 + 8));
  return;
}



===== GetProcessObjectForEProcess @ 1c0001e94 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int GetProcessObjectForEProcess(longlong param_1,longlong param_2,undefined8 *param_3)

{
  uint uVar1;
  int iVar2;
  longlong *plVar3;
  undefined *puVar4;
  longlong lVar5;
  undefined2 uVar6;
  uint uVar7;
  undefined **ppuVar8;
  wchar_t *pwVar9;
  bool bVar10;
  undefined *local_res8;
  undefined *local_res20;
  undefined4 local_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 local_68;
  undefined4 uStack_64;
  undefined8 uStack_60;
  undefined *local_58;
  undefined8 uStack_50;
  undefined *local_48;
  
  iVar2 = 0;
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x70))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x10))
  ;
  uVar7 = 0;
  if (uVar1 != 0) {
    do {
      local_res8 = (undefined *)
                   (**(code **)(WdfFunctions_01015 + 0x90))
                             (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x10),uVar7);
      puVar4 = PTR__WDF_PROCESS_CXT_TYPE_INFO_1c0006048;
      plVar3 = (longlong *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,local_res8);
      if (*plVar3 == param_2) {
        bVar10 = true;
        goto LAB_1c000221f;
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < uVar1);
  }
  local_48 = (undefined *)((ulonglong)local_48 & 0xffffffff00000000);
  local_78 = 0;
  uStack_74 = 0;
  uStack_70 = 0;
  uStack_6c = 0;
  local_res20 = (undefined *)0x0;
  local_68 = 0;
  uStack_64 = 0;
  uStack_60 = 0;
  local_58 = (undefined *)0x0;
  uStack_50 = 0;
  puVar4 = (undefined *)(**(code **)(WdfFunctions_01015 + 0x660))(WdfDriverGlobals,param_1);
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x28));
  local_res8 = (undefined *)
               (**(code **)(WdfFunctions_01015 + 0x98))
                         (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x20));
  bVar10 = local_res8 != (undefined *)0x0;
  if (bVar10) {
    (**(code **)(WdfFunctions_01015 + 0x88))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x20),0);
  }
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x28));
  if (bVar10) {
LAB_1c0002160:
    plVar3 = (longlong *)
             (**(code **)(WdfFunctions_01015 + 0x650))
                       (WdfDriverGlobals,local_res8,PTR__WDF_PROCESS_CXT_TYPE_INFO_1c0006048);
    puVar4 = local_res8;
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x78))
                      (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x10));
    if (iVar2 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x25,puVar4,iVar2);
      }
      (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,plVar3[2]);
    }
    else {
      *plVar3 = param_2;
      ObfReferenceObjectWithTag(param_2,0x66754450);
      *(undefined4 *)(plVar3 + 1) = 0;
      *(undefined4 *)(plVar3 + 4) = 0;
      plVar3[5] = 0;
      *(undefined1 *)(plVar3 + 6) = 1;
LAB_1c000221f:
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) {
        pwVar9 = L"Found";
        if (!bVar10) {
          pwVar9 = L"**New";
        }
        WPP_SF_Sqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),&WPP_GLOBAL_Control,puVar4,pwVar9,
                   (char)local_res8,(char)param_2);
      }
      *param_3 = local_res8;
    }
  }
  else {
    ppuVar8 = &local_res20;
    local_48 = (undefined *)0x0;
    local_68 = 0;
    uStack_64 = 0;
    uStack_74 = 0;
    uStack_70 = 0;
    uStack_6c = 0;
    local_78 = 0x38;
    uStack_50 = 0;
    uStack_60 = 0x100000001;
    local_58 = puVar4;
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x9d8))(WdfDriverGlobals,&local_78);
    if (iVar2 < 0) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return iVar2;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
        return iVar2;
      }
      uVar6 = 0x23;
    }
    else {
      ppuVar8 = &local_res8;
      local_48 = PTR__WDF_PROCESS_CXT_TYPE_INFO_1c0006048;
      local_58 = local_res20;
      uStack_74 = 0;
      uStack_70 = 0;
      uStack_6c = 0;
      local_68 = 0;
      uStack_64 = 0;
      uStack_50 = 0;
      local_78 = 0x38;
      uStack_60 = 0x100000001;
      iVar2 = (**(code **)(WdfFunctions_01015 + 0x678))(WdfDriverGlobals,&local_78);
      if (-1 < iVar2) {
        lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                          (WdfDriverGlobals,local_res8,PTR__WDF_PROCESS_CXT_TYPE_INFO_1c0006048);
        *(undefined **)(lVar5 + 0x10) = local_res20;
        goto LAB_1c0002160;
      }
      (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,local_res20);
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return iVar2;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
        return iVar2;
      }
      uVar6 = 0x24;
    }
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,ppuVar8,iVar2);
  }
  return iVar2;
}



===== WPP_SF_ @ 1c0002290 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_(undefined8 param_1,undefined2 param_2)

{
  (*pfnWppTraceMessage)(param_1,0x2b,&WPP_9721368aefcd34b78121f0eecca54846_Traceguids,param_2,0);
  return;
}



===== WPP_SF_Sqq @ 1c00022c4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Sqq(undefined8 param_1,undefined8 param_2,undefined8 param_3,wchar_t *param_4,
               undefined1 param_5,undefined1 param_6)

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
            (param_1,0x2b,&WPP_9721368aefcd34b78121f0eecca54846_Traceguids,0x26,param_4,lVar1,
             &param_5,8,&param_6,8,0);
  return;
}



===== WPP_SF_d @ 1c0002364 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_d(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_9721368aefcd34b78121f0eecca54846_Traceguids,param_2,local_res20,4,0);
  return;
}



===== WPP_SF_dq @ 1c00023ac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dq(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_9721368aefcd34b78121f0eecca54846_Traceguids,param_2,local_res20,4,
             &param_5,8,0);
  return;
}



===== WPP_SF_dqq @ 1c0002404 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dqq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_9721368aefcd34b78121f0eecca54846_Traceguids,0x1b,local_res20,4,
             &param_5,8,&param_6,8,0);
  return;
}



===== WPP_SF_q @ 1c000246c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_q(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_9721368aefcd34b78121f0eecca54846_Traceguids,param_2,&local_res20,8,0)
  ;
  return;
}



===== WPP_SF_qD @ 1c00024b4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_9721368aefcd34b78121f0eecca54846_Traceguids,0x1e,&local_res20,8,
             &param_5,4,0);
  return;
}



===== WPP_SF_qq @ 1c0002510 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qq(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_9721368aefcd34b78121f0eecca54846_Traceguids,param_2,&local_res20,8,
             &param_5,8,0);
  return;
}



===== WPP_SF_qqd @ 1c0002568 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_9721368aefcd34b78121f0eecca54846_Traceguids,0x2b,&local_res20,8,
             &param_5,8,&param_6,4,0);
  return;
}



===== WPP_SF_qqq @ 1c00025cc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_9721368aefcd34b78121f0eecca54846_Traceguids,0x29,&local_res20,8,
             &param_5,8,&param_6,8,0);
  return;
}



===== WPP_SF_qqqqDDq @ 1c0002630 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqqqDDq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                   undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
                   undefined1 param_9,undefined1 param_10)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_9721368aefcd34b78121f0eecca54846_Traceguids,0x1c,&local_res20,8,
             &param_5,8,&param_6,8,&param_7,8,&param_8,4,&param_9,4,&param_10,8,0);
  return;
}



===== WPP_SF_qqqqL @ 1c00026d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqqqL(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_9721368aefcd34b78121f0eecca54846_Traceguids,0x2a,&local_res20,8,
             &param_5,8,&param_6,8,&param_7,8,&param_8,4,0);
  return;
}



===== WppClassicProviderCallback @ 1c0002760 =====

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



===== FxStubDriverUnloadCommon @ 1c0002794 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl FxStubDriverUnloadCommon(void) */

void __cdecl FxStubDriverUnloadCommon(void)

{
  void **ppvVar1;
  void **ppvVar2;
  
  ppvVar1 = &__KMDF_CLASS_BIND_END;
  if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_1c0006158 != &__KMDF_CLASS_BIND_START) {
    ppvVar2 = (void **)(PTR___KMDF_CLASS_BIND_START_1c0006158 + 0x50);
    while( true ) {
      for (; (ppvVar1 + 1 <= ppvVar2 && (*ppvVar1 == (void *)0x0)); ppvVar1 = ppvVar1 + 1) {
      }
      if (ppvVar1 < ppvVar2) break;
      ppvVar1 = ppvVar2;
LAB_1c00027ed:
      if (ppvVar1 == (void **)0x0) goto LAB_1c0002843;
      if (ppvVar2 <= ppvVar1) goto LAB_1c000285b;
      if (ppvVar1[8] == (code *)0x0) {
        WdfVersionUnbindClass(&WdfBindInfo,WdfDriverGlobals,ppvVar1);
      }
      else {
        (*ppvVar1[8])(WdfVersionUnbindClass_exref,&WdfBindInfo,WdfDriverGlobals,ppvVar1);
      }
      ppvVar1 = (void **)((longlong)ppvVar1 + (ulonglong)*(uint *)ppvVar1);
    }
    if ((ppvVar1 + 10 <= ppvVar2) && (*(uint *)ppvVar1 == 0x50)) goto LAB_1c00027ed;
LAB_1c0002843:
    DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
  }
LAB_1c000285b:
  WdfVersionUnbind(&DAT_1c00063d0,&WdfBindInfo,WdfDriverGlobals);
  return;
}



===== entry @ 1c0002890 =====

void entry(_WDF_BIND_INFO *param_1,undefined8 param_2)

{
  __security_init_cookie();
  FxDriverEntryWorker(param_1,param_2);
  return;
}



===== FxDriverEntryWorker @ 1c00028c4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FxDriverEntryWorker(_WDF_BIND_INFO *param_1,undefined8 param_2)

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
    iVar1 = DriverEntry(0,param_2);
  }
  else {
    _DAT_1c00063d0 = 0x2080000;
    _DAT_1c00063d8 = &DAT_1c00061c0;
    RtlCopyUnicodeString(&DAT_1c00063d0);
    p_Var3 = param_1;
    iVar1 = WdfVersionBind(param_1,&DAT_1c00063d0,&WdfBindInfo,&WdfDriverGlobals);
    if (-1 < iVar1) {
      iVar1 = FxStubBindClasses(p_Var3);
      if ((-1 < iVar1) && (iVar1 = FxStubInitTypes(), -1 < iVar1)) {
        iVar1 = DriverEntry(param_1,param_2);
        if (-1 < iVar1) {
          if (*(char *)(WdfDriverGlobals + 0x30) != '\0') {
            if (*(longlong *)(param_1 + 0x68) != 0) {
              DAT_1c00063c8 = *(longlong *)(param_1 + 0x68);
            }
            *(code **)(param_1 + 0x68) = FxStubDriverUnload;
          }
          return 0;
        }
        DbgPrintEx(0x4d,0,"DriverEntry failed 0x%x for driver %wZ\n",iVar1,&DAT_1c00063d0);
        if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_1c0006158 != &__KMDF_CLASS_BIND_START) {
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



===== FxStubDriverUnload @ 1c0002a50 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FxStubDriverUnload(void)

{
  if ((DAT_1c00063c8 != (code *)0x0) && (DAT_1c00063c8 != FxStubDriverUnload)) {
    (*DAT_1c00063c8)();
  }
  FxStubDriverUnloadCommon();
  return;
}



===== FxStubBindClasses @ 1c0002a84 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x0001c0002aa9) */
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
    if ((void **)0x1c000614f < ppvVar2) break;
    if (((&__KMDF_CLASS_BIND_END < ppvVar2 + 10) || (*(uint *)ppvVar2 != 0x50)) ||
       (ppvVar2 == (void **)0x0)) {
      DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
      return -0x3fffff85;
    }
    PTR___KMDF_CLASS_BIND_START_1c0006158 = (undefined *)ppvVar2;
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



===== FxStubInitTypes @ 1c0002c0c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x0001c0002c29) */
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
    if ((void **)0x1c000616f < ppvVar2) break;
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



===== _guard_check_icall @ 1c0002ce0 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 1c0002cf8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c0002d1c =====

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



===== __cpu_features_init @ 1c0002d90 =====

/* WARNING: Removing unreachable block (ram,0x0001c0002dfa) */
/* WARNING: Removing unreachable block (ram,0x0001c0002da9) */
/* WARNING: Removing unreachable block (ram,0x0001c0002d9a) */

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



===== __security_check_cookie @ 1c0002e60 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c0002ea0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c0002ed0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c0002ed0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c0002f00 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcpy @ 1c0002f80 =====

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



===== memset @ 1c0003280 =====

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



===== __memset_repmovs @ 1c00033c0 =====

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



===== __memset_query @ 1c0003440 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c00034c0 =====

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



===== __memset_spec_ermsb_repmovsb @ 1c0003600 =====

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



===== __memset_spec_plain @ 1c0003680 =====

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



===== FilterEvtDeviceAdd @ 1c0009010 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int FilterEvtDeviceAdd(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  longlong lVar2;
  undefined2 uVar3;
  ulonglong *puVar4;
  undefined8 local_res10;
  undefined8 local_res18 [2];
  undefined4 local_d8;
  undefined4 local_d4;
  code *local_d0;
  code *local_c8;
  code *local_c0;
  undefined4 local_b8;
  undefined4 local_b4;
  ulonglong local_b0 [6];
  undefined *local_80;
  undefined8 local_78;
  undefined4 local_70;
  undefined1 local_6b;
  code *local_50;
  undefined4 local_28;
  
  local_res18[0] = 0;
  local_d4 = 0;
  local_b0[0] = (ulonglong)(uint)local_b0[0];
  local_res10 = param_2;
  (**(code **)(WdfFunctions_01015 + 0x408))(WdfDriverGlobals);
  local_80 = PTR__WDF_FILTER_EXTENSION_TYPE_INFO_1c0006018;
  local_d0 = FilterEvtDeviceFileCreate;
  local_c8 = FilterEvtFileClose;
  local_b0[2] = 0;
  local_c0 = FilterEvtFileCleanup;
  local_b0[1] = 0;
  local_b0[0] = 0x38;
  local_b0[4] = 0;
  local_b0[5] = 0;
  local_b0[3] = 0x100000001;
  local_d8 = 0x28;
  local_b4 = 4;
  local_b8 = 2;
  (**(code **)(WdfFunctions_01015 + 0x238))(WdfDriverGlobals,local_res10,&local_d8,0);
  puVar4 = local_b0;
  iVar1 = (**(code **)(WdfFunctions_01015 + 600))(WdfDriverGlobals,&local_res10,puVar4,local_res18);
  if (iVar1 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar1;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
      return iVar1;
    }
    uVar3 = 0xd;
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0')) {
      WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,puVar4,param_1,(char)local_res18[0]);
    }
    lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,local_res18[0],PTR__WDF_FILTER_EXTENSION_TYPE_INFO_1c0006018
                      );
    *(undefined4 *)(lVar2 + 8) = 2;
    memset(&local_78,0,0x60);
    local_28 = 0xffffffff;
    puVar4 = &local_78;
    local_50 = FilterEvtIoDeviceControl;
    local_78._0_4_ = 0x60;
    local_70 = 2;
    local_6b = 1;
    local_78._4_4_ = 2;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x4c0))(WdfDriverGlobals,local_res18[0],puVar4,0,0);
    if (-1 < iVar1) {
      return iVar1;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar1;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
      return iVar1;
    }
    uVar3 = 0xf;
  }
  WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar3,puVar4,iVar1);
  return iVar1;
}



===== FilterEvtDeviceFileCreate @ 1c0009250 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FilterEvtDeviceFileCreate(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined1 *puVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  undefined1 *local_res20;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined *local_30;
  
  puVar2 = (undefined1 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_FILTER_EXTENSION_TYPE_INFO_1c0006018);
  uVar3 = param_1;
  local_res20 = puVar2;
  iVar1 = RtlRunOnceExecuteOnce(puVar2,RunOnceIdentifyIfPassThrough,param_1,0);
  if (iVar1 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      WPP_SF_dq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,uVar3,iVar1,(char)param_1);
    }
LAB_1c0009320:
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar1);
  }
  else {
    if (*(int *)(puVar2 + 8) == 0) {
      local_res20 = (undefined1 *)0x0;
      uStack_58 = 0;
      local_50 = 0;
      local_40 = 0;
      uStack_38 = 0;
      local_60 = 0x38;
      uStack_48 = 0x100000001;
      local_30 = PTR__WDF_FILE_CXT_TYPE_INFO_1c0006070;
      puVar4 = &local_60;
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x658))
                        (WdfDriverGlobals,param_3,puVar4,&local_res20);
      if (iVar1 < 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
          WPP_SF_dqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),
                     (ulonglong)*(uint *)(WPP_GLOBAL_Control + 0x2c),puVar4,iVar1,(char)param_1,
                     (char)param_3);
        }
        goto LAB_1c0009320;
      }
      *local_res20 = 0;
      local_res20[0x10] = 0;
    }
    uVar3 = (**(code **)(WdfFunctions_01015 + 0x150))(WdfDriverGlobals,param_1);
    ForwardRequestWithCompletionRoutine(param_2,uVar3,FilterFileCreateCompletionRoutine);
  }
  return;
}



===== FilterEvtDriverUnload @ 1c0009460 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FilterEvtDriverUnload(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0')) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,param_3,param_1);
  }
  (**(code **)(WdfFunctions_01015 + 0x3b0))(WdfDriverGlobals,param_1);
  WppCleanupKm();
  return;
}



===== ForwardAndForgetRequest @ 1c00094c4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void ForwardAndForgetRequest(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  undefined4 uVar2;
  undefined1 auStack_58 [48];
  undefined4 local_28;
  undefined4 local_24;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  local_20 = 0;
  local_28 = 0x10;
  local_24 = 8;
  cVar1 = (**(code **)(WdfFunctions_01015 + 0x7e8))(WdfDriverGlobals,param_1,param_2,&local_28);
  if (cVar1 == '\0') {
    uVar2 = (**(code **)(WdfFunctions_01015 + 0x7f0))(WdfDriverGlobals,param_1);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,
               (ulonglong)*(uint *)(WPP_GLOBAL_Control + 0x2c),uVar2);
    }
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_1,uVar2);
  }
  return;
}



===== ForwardRequestWithCompletionRoutine @ 1c00095ac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ForwardRequestWithCompletionRoutine(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  char cVar1;
  undefined4 uVar2;
  
  (**(code **)(WdfFunctions_01015 + 0x7d8))(WdfDriverGlobals,param_1);
  (**(code **)(WdfFunctions_01015 + 0x820))(WdfDriverGlobals,param_1,param_3,0);
  cVar1 = (**(code **)(WdfFunctions_01015 + 0x7e8))(WdfDriverGlobals,param_1,param_2,0);
  if (cVar1 == '\0') {
    uVar2 = (**(code **)(WdfFunctions_01015 + 0x7f0))(WdfDriverGlobals,param_1);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,param_2,uVar2);
    }
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_1,uVar2);
  }
  return;
}



===== InitDeviceContext @ 1c00096b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int InitDeviceContext(longlong param_1)

{
  longlong *plVar1;
  int iVar2;
  longlong lVar3;
  undefined2 uVar4;
  longlong *plVar5;
  ulonglong local_58 [5];
  undefined8 uStack_30;
  undefined8 local_28;
  
  local_58[0] = (ulonglong)(uint)local_58[0];
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FILTER_EXTENSION_TYPE_INFO_1c0006018);
  local_58[2] = 0;
  local_28 = 0;
  local_58[1] = 0;
  plVar1 = (longlong *)(lVar3 + 0x18);
  uStack_30 = 0;
  local_58[0] = 0x38;
  local_58[3] = 0x100000001;
  plVar5 = plVar1;
  local_58[4] = param_1;
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x9d8))(WdfDriverGlobals,local_58);
  if (iVar2 < 0) {
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) goto LAB_1c00098e7;
    uVar4 = 0x15;
  }
  else {
    plVar5 = (longlong *)(lVar3 + 0x10);
    local_28 = 0;
    local_58[2] = 0;
    local_58[1] = 0;
    local_58[0] = 0x38;
    uStack_30 = 0;
    local_58[3] = 0x100000001;
    local_58[4] = *plVar1;
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x68))(WdfDriverGlobals,local_58);
    if (iVar2 < 0) {
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) goto LAB_1c00098e7;
      uVar4 = 0x16;
    }
    else {
      plVar5 = (longlong *)(lVar3 + 0x28);
      local_28 = 0;
      local_58[2] = 0;
      local_58[1] = 0;
      local_58[0] = 0x38;
      uStack_30 = 0;
      local_58[3] = 0x100000001;
      local_58[4] = param_1;
      iVar2 = (**(code **)(WdfFunctions_01015 + 0x9d8))(WdfDriverGlobals,local_58);
      if (iVar2 < 0) {
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) goto LAB_1c00098e7;
        uVar4 = 0x17;
      }
      else {
        plVar5 = (longlong *)(lVar3 + 0x20);
        local_28 = 0;
        local_58[2] = 0;
        local_58[1] = 0;
        local_58[0] = 0x38;
        uStack_30 = 0;
        local_58[3] = 0x100000001;
        local_58[4] = *(longlong *)(lVar3 + 0x28);
        iVar2 = (**(code **)(WdfFunctions_01015 + 0x68))(WdfDriverGlobals,local_58);
        if (-1 < iVar2) {
          return iVar2;
        }
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) goto LAB_1c00098e7;
        uVar4 = 0x18;
      }
    }
  }
  WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4);
LAB_1c00098e7:
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
    WPP_SF_dq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,plVar5,iVar2,(char)param_1);
  }
  *(undefined4 *)(lVar3 + 8) = 1;
  if (*plVar1 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
  if (*(longlong *)(lVar3 + 0x28) != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
  return iVar2;
}



===== RunOnceIdentifyIfPassThrough @ 1c0009980 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 RunOnceIdentifyIfPassThrough(undefined8 param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined2 uVar4;
  undefined *puVar5;
  short *local_res10;
  undefined1 uVar6;
  
  local_res10 = (short *)0x0;
  puVar5 = PTR__WDF_FILTER_EXTENSION_TYPE_INFO_1c0006018;
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
  uVar6 = (undefined1)param_2;
  if (*(int *)(lVar2 + 8) != 2) goto LAB_1c0009acc;
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x150))(WdfDriverGlobals,param_2);
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x598))(WdfDriverGlobals,uVar3);
  puVar5 = (undefined *)0x0;
  iVar1 = IoGetDeviceInterfaces(&GUID_DEVINTERFACE_MT_TRANSPORT,uVar3,0,&local_res10);
  if (iVar1 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      WPP_SF_dq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,puVar5,iVar1,uVar6);
    }
    *(undefined4 *)(lVar2 + 8) = 1;
    goto LAB_1c0009acc;
  }
  if (*local_res10 == 0) {
    *(undefined4 *)(lVar2 + 8) = 0;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) {
      uVar4 = 0x12;
      goto LAB_1c0009aa8;
    }
  }
  else {
    *(undefined4 *)(lVar2 + 8) = 1;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) {
      uVar4 = 0x11;
LAB_1c0009aa8:
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,puVar5,param_2);
    }
  }
  ExFreePoolWithTag(local_res10,0);
  local_res10 = (short *)0x0;
LAB_1c0009acc:
  if (*(int *)(lVar2 + 8) == 0) {
    iVar1 = InitDeviceContext(param_2);
    if (iVar1 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
        WPP_SF_dq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,puVar5,iVar1,uVar6);
      }
      *(undefined4 *)(lVar2 + 8) = 1;
    }
    else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) {
      WPP_SF_dq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,puVar5,iVar1,uVar6);
    }
  }
  return 1;
}



===== WppCleanupKm @ 1c0009b5c =====

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



===== WppInitKm @ 1c0009bdc =====

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



===== WppLoadTracingSupport @ 1c0009c6c =====

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



===== WppTraceCallback @ 1c0009db0 =====

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



===== __security_init_cookie @ 1c000b008 =====

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



===== DriverEntry @ 1c000b03c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 local_res18 [2];
  ulonglong local_28;
  code *local_20;
  code *local_18;
  undefined8 local_10;
  
  _DAT_1c0006408 = 1;
  local_res18[0] = 0;
  local_28 = (ulonglong)(uint)local_28;
  _WPP_MAIN_CB = 0;
  DAT_1c00063e8 = &WPP_ThisDir_CTLGUID_CtlGuidWpdUpFltr;
  DAT_1c00063f0 = 0;
  _DAT_1c0006400 = 0;
  WppLoadTracingSupport();
  _DAT_1c0006400 = 0;
  WppInitKm();
  local_28 = 0x20;
  local_20 = FilterEvtDeviceAdd;
  local_18 = FilterEvtDriverUnload;
  local_10 = 0;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x3a0))
                    (WdfDriverGlobals,param_1,param_2,0,&local_28,local_res18);
  if (iVar1 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,param_2,iVar1);
    }
    WppCleanupKm();
  }
  else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0')) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,param_2,local_res18[0]);
  }
  return iVar1;
}


