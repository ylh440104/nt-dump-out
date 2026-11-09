
===== RhpCommonOperationRegionHandler @ 1c0001010 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong RhpCommonOperationRegionHandler
                    (int param_1,longlong **param_2,longlong **param_3,longlong **param_4)

{
  uint uVar1;
  longlong *plVar2;
  longlong lVar3;
  code *pcVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  uint uVar8;
  ulonglong uVar9;
  undefined *puVar10;
  undefined8 *puVar11;
  longlong **pplVar12;
  longlong *plVar13;
  ulonglong uVar14;
  undefined1 *puVar15;
  undefined1 *puVar16;
  longlong *plVar17;
  longlong **pplVar18;
  longlong *local_res10 [2];
  undefined8 local_res20;
  undefined1 auStackY_98 [8];
  undefined1 auStackY_90 [24];
  undefined8 in_stack_ffffffffffffff88;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48 [2];
  
  puVar15 = auStackY_98;
  plVar2 = param_2[5];
  plVar17 = (longlong *)0x0;
  uVar1 = *(uint *)param_4;
  local_res20 = 0;
  pplVar18 = param_3;
  if (plVar2 == (longlong *)0x0) {
    uVar14 = 0xc00000bb;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      pplVar18 = (longlong **)0x9;
      WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),0,9,0x49,
                        &WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,
                        "RhpCommonOperationRegionHandler");
      puVar15 = auStackY_98;
    }
    goto LAB_1c000131b;
  }
  if (*(int *)((longlong)param_2 + 0x34) == 0) {
    uVar14 = 0xc00000bb;
    puVar15 = auStackY_98;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,param_3,0x4a,
                         in_stack_ffffffffffffff88,"RhpCommonOperationRegionHandler",(char)plVar2);
      puVar15 = auStackY_98;
    }
    goto LAB_1c000131b;
  }
  pplVar12 = param_2;
  if (param_1 == 8) {
    pplVar18 = param_4;
    uVar9 = RhpValidateGpioRegionSpaceAccess((longlong)param_2,param_2,(uint *)param_4);
LAB_1c0001079:
    uVar14 = uVar9 & 0xffffffff;
    if ((((int)uVar9 + 0x80000000U & 0x80000000) == 0) && ((int)uVar9 != -0x3fffffdd))
    goto LAB_1c00013eb;
  }
  else {
    if (param_1 == 9) {
      pplVar12 = param_3;
      pplVar18 = param_4;
      uVar9 = RhpValidateSerialBusRegionSpaceAccess
                        ((longlong)param_2,(undefined1 *)param_3,(uint *)param_4);
      goto LAB_1c0001079;
    }
    uVar14 = 0xc00000bb;
LAB_1c00013eb:
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      pplVar18 = (longlong **)0x9;
      WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pplVar12,9,0x45,
                         &WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,
                         "RhpValidateRegionSpaceAccess",(char)uVar14);
    }
  }
  puVar15 = auStackY_98;
  puVar16 = auStackY_98;
  plVar13 = plVar17;
  if (-1 < (int)uVar14) {
    if (uVar1 < *(uint *)param_4) {
      uVar14 = 0xc0000001;
      puVar15 = auStackY_98;
      goto LAB_1c000131b;
    }
    local_58 = 0;
    plVar13 = (longlong *)0x0;
    local_50 = 0;
    local_res10[0] = (longlong *)0x0;
    ExAcquireFastMutex(&RhOpRegionLock);
    if (RhOpRegionRequestAvailable != 0) {
      for (plVar13 = RhOpRegionRequestListHead; (longlong **)plVar13 != &RhOpRegionRequestListHead;
          plVar13 = (longlong *)*plVar13) {
        if ((char)plVar13[2] == '\0') {
          (**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,plVar13[3],&local_58);
          pplVar12 = (longlong **)plVar13[4];
          (**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,pplVar12,&local_50);
          goto LAB_1c00010e6;
        }
      }
      plVar13 = (longlong *)0x0;
LAB_1c00010e6:
      RhOpRegionRequestAvailable = RhOpRegionRequestAvailable + -1;
      *(undefined1 *)(plVar13 + 2) = 1;
      local_res10[0] = plVar13;
    }
    puVar10 = &RhOpRegionLock;
    ExReleaseFastMutex();
    pplVar18 = local_res10;
    if (plVar13 == (longlong *)0x0) {
      uVar8 = RhpCreateRequestContext(puVar10,pplVar12,(longlong *)pplVar18);
      plVar13 = local_res10[0];
      uVar14 = (ulonglong)uVar8;
      if ((int)uVar8 < 0) {
        puVar15 = auStackY_98;
        if (local_res10[0] != (longlong *)0x0) {
          RhpReleaseRequestContext((longlong)local_res10[0]);
          puVar15 = auStackY_98;
        }
        goto LAB_1c000131b;
      }
      *(undefined1 *)(local_res10[0] + 2) = 1;
      ExAcquireFastMutex(&RhOpRegionLock);
      puVar11 = &RhOpRegionRequestListHead;
      puVar15 = auStackY_98;
      if ((longlong **)*DAT_1c0016768 != &RhOpRegionRequestListHead) {
        puVar11 = (undefined8 *)0x3;
        pcVar4 = (code *)swi(0x29);
        DAT_1c0016768 = (longlong *)(*pcVar4)();
        puVar15 = auStackY_90;
      }
      *plVar13 = (longlong)puVar11;
      plVar13[1] = (longlong)DAT_1c0016768;
      *DAT_1c0016768 = (longlong)plVar13;
      DAT_1c0016768 = plVar13;
      *(undefined8 *)(puVar15 + -8) = 0x1c00014a4;
      ExReleaseFastMutex(&RhOpRegionLock);
      *(longlong **)(puVar15 + 0xa8) = plVar13;
    }
    else {
      local_res10[0] = (longlong *)0x0;
      (**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,plVar13[3]);
      local_48[0] = 0;
      (**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,plVar13[4],local_48);
      local_res10[0] = plVar13;
    }
    lVar3 = *(longlong *)(puVar15 + 200);
    *(int *)(plVar13 + 8) = param_1;
    plVar13[0x14] = lVar3;
    plVar13[0x15] = *(longlong *)(puVar15 + 0xd0);
    plVar13[0x12] = (longlong)param_3;
    *(undefined4 *)(plVar13 + 0x13) = *(undefined4 *)param_4;
    plVar13[0x16] = (longlong)plVar2;
    *(undefined8 *)(puVar15 + -8) = 0x1c00011b8;
    ObfReferenceObject(plVar2);
    plVar2 = *param_2;
    plVar17 = param_2[1];
    *(undefined1 **)(puVar15 + 0x30) = puVar15 + 0xb8;
    plVar13[9] = (longlong)plVar2;
    plVar13[10] = (longlong)plVar17;
    *(longlong **)(puVar15 + 0x28) = plVar13 + 0x11;
    pplVar18 = (longlong **)0x200;
    plVar2 = param_2[3];
    plVar13[0xb] = (longlong)param_2[2];
    plVar13[0xc] = (longlong)plVar2;
    uVar5 = *(undefined4 *)((longlong)param_2 + 0x24);
    uVar6 = *(undefined4 *)(param_2 + 5);
    uVar7 = *(undefined4 *)((longlong)param_2 + 0x2c);
    *(undefined4 *)(plVar13 + 0xd) = *(undefined4 *)(param_2 + 4);
    *(undefined4 *)((longlong)plVar13 + 0x6c) = uVar5;
    *(undefined4 *)(plVar13 + 0xe) = uVar6;
    *(undefined4 *)((longlong)plVar13 + 0x74) = uVar7;
    uVar5 = *(undefined4 *)((longlong)param_2 + 0x34);
    uVar6 = *(undefined4 *)(param_2 + 7);
    uVar7 = *(undefined4 *)((longlong)param_2 + 0x3c);
    *(undefined4 *)(plVar13 + 0xf) = *(undefined4 *)(param_2 + 6);
    *(undefined4 *)((longlong)plVar13 + 0x7c) = uVar5;
    *(undefined4 *)(plVar13 + 0x10) = uVar6;
    *(undefined4 *)((longlong)plVar13 + 0x84) = uVar7;
    *(undefined4 *)((longlong)plVar13 + 0x7c) = 0;
    *(undefined4 *)((longlong)plVar13 + 0x4c) = 0x40;
    *(ulonglong *)(puVar15 + 0x20) = (ulonglong)*(uint *)((longlong)param_2 + 0x34);
    pcVar4 = *(code **)(WdfFunctions_01015 + 0x600);
    *(undefined8 *)(puVar15 + -8) = 0x1c0001233;
    uVar8 = (*pcVar4)(WdfDriverGlobals,0,0x200,0x48736552);
    uVar14 = (ulonglong)uVar8;
    puVar16 = puVar15;
    if (-1 < (int)uVar8) {
      pplVar18 = (longlong **)(ulonglong)*(uint *)((longlong)param_2 + 0x34);
      *(undefined8 *)(puVar15 + -8) = 0x1c000124e;
      memcpy(*(void **)(puVar15 + 0xb8),param_2 + 7,(size_t)pplVar18);
      *(undefined8 *)(puVar15 + -8) = 0x1c0001263;
      uVar8 = RhpProcessRegionSpaceAccessAsync
                        (*(undefined8 *)(puVar15 + 0xc0),(longlong *)(puVar15 + 0xa8));
      plVar13 = *(longlong **)(puVar15 + 0xa8);
      uVar14 = (ulonglong)uVar8;
    }
  }
  puVar15 = puVar16;
  plVar17 = plVar13;
  if ((int)uVar14 == 0x103) {
    return uVar14;
  }
LAB_1c000131b:
  *(uint *)(puVar15 + 0x20) = uVar1;
  *(undefined8 *)(puVar15 + -8) = 0x1c000132d;
  RhpCompleteRegionSpaceAccess
            (param_1,(int)uVar14,pplVar18,(char *)param_3,*(int *)(puVar15 + 0x20));
  if (plVar17 != (longlong *)0x0) {
    *(undefined8 *)(puVar15 + -8) = 0x1c000133e;
    RhpCleanAndReleaseRequestContext((longlong)plVar17);
  }
  return uVar14;
}



===== RhSerialBusOperationRegionHandler @ 1c00014c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong RhSerialBusOperationRegionHandler
                    (longlong *param_1,char *param_2,longlong **param_3,undefined8 param_4)

{
  uint uVar1;
  longlong lVar2;
  code *pcVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  ulonglong uVar8;
  undefined *puVar9;
  undefined8 *puVar10;
  longlong lVar11;
  longlong *plVar12;
  ulonglong uVar13;
  undefined1 *puVar14;
  longlong *plVar15;
  longlong **pplVar16;
  longlong *local_res8;
  undefined8 local_res20;
  undefined1 auStackY_98 [8];
  undefined1 auStackY_90 [24];
  undefined8 in_stack_ffffffffffffff88;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48 [2];
  
  puVar14 = auStackY_98;
  lVar2 = param_1[5];
  plVar15 = (longlong *)0x0;
  uVar1 = *(uint *)param_3;
  if (lVar2 == 0) {
    uVar13 = 0xc00000bb;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      param_3 = (longlong **)0x9;
      WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),0,9,0x49,
                        &WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,
                        "RhpCommonOperationRegionHandler");
      puVar14 = auStackY_98;
    }
  }
  else if (*(int *)((longlong)param_1 + 0x34) == 0) {
    uVar13 = 0xc00000bb;
    puVar14 = auStackY_98;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,param_3,0x4a,
                         in_stack_ffffffffffffff88,"RhpCommonOperationRegionHandler",(char)lVar2);
      puVar14 = auStackY_98;
    }
  }
  else {
    pplVar16 = param_3;
    uVar8 = RhpValidateSerialBusRegionSpaceAccess((longlong)param_1,param_2,(uint *)param_3);
    puVar14 = auStackY_98;
    lVar11 = 0x80000000;
    iVar6 = (int)uVar8;
    uVar13 = uVar8 & 0xffffffff;
    if ((((iVar6 + 0x80000000U & 0x80000000) == 0) && (iVar6 != -0x3fffffdd)) &&
       ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      param_3 = (longlong **)0x9;
      WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),0x80000000,9,0x45,
                         &WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,
                         "RhpValidateRegionSpaceAccess",(char)uVar8);
      puVar14 = auStackY_98;
    }
    else {
      plVar12 = plVar15;
      if (-1 < iVar6) {
        if (uVar1 < *(uint *)param_3) {
          uVar13 = 0xc0000001;
          puVar14 = auStackY_98;
          param_3 = pplVar16;
          goto LAB_1c00017fa;
        }
        local_res20 = 0;
        plVar12 = (longlong *)0x0;
        local_58 = 0;
        local_res8 = (longlong *)0x0;
        ExAcquireFastMutex(&RhOpRegionLock);
        if (RhOpRegionRequestAvailable != 0) {
          for (plVar12 = RhOpRegionRequestListHead;
              (longlong **)plVar12 != &RhOpRegionRequestListHead; plVar12 = (longlong *)*plVar12) {
            if ((char)plVar12[2] == '\0') {
              (**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,plVar12[3],&local_res20);
              lVar11 = plVar12[4];
              (**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,lVar11,&local_58);
              goto LAB_1c000157c;
            }
          }
          plVar12 = (longlong *)0x0;
LAB_1c000157c:
          RhOpRegionRequestAvailable = RhOpRegionRequestAvailable + -1;
          *(undefined1 *)(plVar12 + 2) = 1;
          local_res8 = plVar12;
        }
        puVar14 = auStackY_98;
        puVar9 = &RhOpRegionLock;
        ExReleaseFastMutex();
        if (plVar12 == (longlong *)0x0) {
          pplVar16 = &local_res8;
          uVar7 = RhpCreateRequestContext(puVar9,lVar11,(longlong *)pplVar16);
          plVar12 = local_res8;
          uVar13 = (ulonglong)uVar7;
          if ((int)uVar7 < 0) {
            puVar14 = auStackY_98;
            param_3 = pplVar16;
            if (local_res8 != (longlong *)0x0) {
              RhpReleaseRequestContext((longlong)local_res8);
              puVar14 = auStackY_98;
              param_3 = pplVar16;
            }
            goto LAB_1c00017fa;
          }
          *(undefined1 *)(local_res8 + 2) = 1;
          ExAcquireFastMutex(&RhOpRegionLock);
          puVar10 = &RhOpRegionRequestListHead;
          puVar14 = auStackY_98;
          if ((longlong **)*DAT_1c0016768 != &RhOpRegionRequestListHead) {
            puVar10 = (undefined8 *)0x3;
            pcVar3 = (code *)swi(0x29);
            DAT_1c0016768 = (longlong *)(*pcVar3)();
            puVar14 = auStackY_90;
          }
          *plVar12 = (longlong)puVar10;
          plVar12[1] = (longlong)DAT_1c0016768;
          *DAT_1c0016768 = (longlong)plVar12;
          DAT_1c0016768 = plVar12;
          *(undefined8 *)(puVar14 + -8) = 0x1c000191e;
          ExReleaseFastMutex(&RhOpRegionLock);
          *(longlong **)(puVar14 + 0xa0) = plVar12;
        }
        else {
          local_50 = 0;
          (**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,plVar12[3],&local_50);
          local_48[0] = 0;
          (**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,plVar12[4],local_48);
          local_res8 = plVar12;
        }
        lVar11 = *(longlong *)(puVar14 + 0xc0);
        *(undefined4 *)(plVar12 + 8) = 9;
        plVar12[0x14] = lVar11;
        plVar12[0x15] = *(longlong *)(puVar14 + 200);
        plVar12[0x12] = (longlong)param_2;
        *(undefined4 *)(plVar12 + 0x13) = *(undefined4 *)param_3;
        plVar12[0x16] = lVar2;
        *(undefined8 *)(puVar14 + -8) = 0x1c000164b;
        ObfReferenceObject(lVar2);
        lVar2 = *param_1;
        lVar11 = param_1[1];
        *(undefined1 **)(puVar14 + 0x30) = puVar14 + 0xb0;
        plVar12[9] = lVar2;
        plVar12[10] = lVar11;
        *(longlong **)(puVar14 + 0x28) = plVar12 + 0x11;
        pplVar16 = (longlong **)0x200;
        lVar2 = param_1[3];
        plVar12[0xb] = param_1[2];
        plVar12[0xc] = lVar2;
        uVar4 = *(undefined4 *)((longlong)param_1 + 0x24);
        lVar2 = param_1[5];
        uVar5 = *(undefined4 *)((longlong)param_1 + 0x2c);
        *(int *)(plVar12 + 0xd) = (int)param_1[4];
        *(undefined4 *)((longlong)plVar12 + 0x6c) = uVar4;
        *(int *)(plVar12 + 0xe) = (int)lVar2;
        *(undefined4 *)((longlong)plVar12 + 0x74) = uVar5;
        uVar4 = *(undefined4 *)((longlong)param_1 + 0x34);
        lVar2 = param_1[7];
        uVar5 = *(undefined4 *)((longlong)param_1 + 0x3c);
        *(int *)(plVar12 + 0xf) = (int)param_1[6];
        *(undefined4 *)((longlong)plVar12 + 0x7c) = uVar4;
        *(int *)(plVar12 + 0x10) = (int)lVar2;
        *(undefined4 *)((longlong)plVar12 + 0x84) = uVar5;
        *(undefined4 *)((longlong)plVar12 + 0x7c) = 0;
        *(undefined4 *)((longlong)plVar12 + 0x4c) = 0x40;
        *(ulonglong *)(puVar14 + 0x20) = (ulonglong)*(uint *)((longlong)param_1 + 0x34);
        pcVar3 = *(code **)(WdfFunctions_01015 + 0x600);
        *(undefined8 *)(puVar14 + -8) = 0x1c00016c6;
        uVar7 = (*pcVar3)(WdfDriverGlobals,0,0x200,0x48736552);
        uVar13 = (ulonglong)uVar7;
        if (-1 < (int)uVar7) {
          pplVar16 = (longlong **)(ulonglong)*(uint *)((longlong)param_1 + 0x34);
          *(undefined8 *)(puVar14 + -8) = 0x1c00016e1;
          memcpy(*(void **)(puVar14 + 0xb0),param_1 + 7,(size_t)pplVar16);
          *(undefined8 *)(puVar14 + -8) = 0x1c00016f1;
          uVar7 = RhpProcessRegionSpaceAccessAsync(param_4,(longlong *)(puVar14 + 0xa0));
          plVar12 = *(longlong **)(puVar14 + 0xa0);
          uVar13 = (ulonglong)uVar7;
        }
      }
      plVar15 = plVar12;
      param_3 = pplVar16;
      if ((int)uVar13 == 0x103) {
        return uVar13;
      }
    }
  }
LAB_1c00017fa:
  *(uint *)(puVar14 + 0x20) = uVar1;
  *(undefined8 *)(puVar14 + -8) = 0x1c000180e;
  RhpCompleteRegionSpaceAccess(9,(int)uVar13,param_3,param_2,*(int *)(puVar14 + 0x20));
  if (plVar15 != (longlong *)0x0) {
    *(undefined8 *)(puVar14 + -8) = 0x1c000181f;
    RhpCleanAndReleaseRequestContext((longlong)plVar15);
  }
  return uVar13;
}



===== RhpValidateSerialBusRegionSpaceAccess @ 1c0001940 =====

undefined8 RhpValidateSerialBusRegionSpaceAccess(longlong param_1,undefined1 *param_2,uint *param_3)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  undefined8 uVar8;
  uint uVar9;
  ulonglong uVar10;
  undefined2 uVar11;
  byte bVar12;
  undefined1 uVar13;
  byte bVar14;
  undefined8 in_stack_ffffffffffffff98;
  char *in_stack_ffffffffffffffa0;
  
  uVar10 = (ulonglong)param_3 & 0xffffffffffffff00;
  bVar14 = 0;
  uVar2 = *param_3;
  uVar13 = 1;
  if ((*(byte *)(param_1 + 9) & 0xf) != 5) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sdi(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,uVar10,0x34,
                          in_stack_ffffffffffffff98,"RhpValidateSerialBusRegionSpaceAccess",
                          *(byte *)(param_1 + 9),(char)*(undefined8 *)(param_1 + 0x28));
    }
    goto LAB_1c0001adb;
  }
  if (*(char *)(param_1 + 8) == '\0') {
    bVar4 = true;
    bVar6 = false;
  }
  else {
    bVar4 = false;
    bVar6 = true;
    if (uVar2 < 2) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sdi(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,uVar10,0x35,
                            in_stack_ffffffffffffff98,"RhpValidateSerialBusRegionSpaceAccess",
                            (char)uVar2,(char)*(undefined8 *)(param_1 + 0x28));
      }
      uVar8 = 0xc0000001;
      goto LAB_1c00019ae;
    }
  }
  cVar1 = *(char *)(param_1 + 10);
  bVar12 = 1;
  bVar5 = true;
  if (cVar1 == '\x0f') {
    if (bVar4) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar11 = 0x38;
        goto LAB_1c0001cee;
      }
      goto LAB_1c0001d13;
    }
    uVar10 = (ulonglong)*(byte *)(param_1 + 0xb);
    bVar5 = false;
LAB_1c00019e9:
    bVar12 = param_2[1];
  }
  else if (cVar1 == '\x04') {
    bVar5 = false;
  }
  else {
    bVar7 = true;
    switch(cVar1) {
    case '\x02':
      bVar5 = false;
      bVar12 = 0;
      break;
    default:
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sdi(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,uVar10,0x39,
                            in_stack_ffffffffffffff98,"RhpValidateSerialBusRegionSpaceAccess",cVar1,
                            (char)*(undefined8 *)(param_1 + 0x28));
      }
      uVar13 = 0x19;
      goto LAB_1c0001adb;
    case '\x06':
      break;
    case '\b':
      bVar12 = 2;
      break;
    case '\n':
      bVar5 = true;
      if (!bVar4) goto LAB_1c00019e9;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar11 = 0x37;
LAB_1c0001cee:
        WPP_RECORDER_SF_sq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,uVar10,uVar11,
                           in_stack_ffffffffffffff98,"RhpValidateSerialBusRegionSpaceAccess",
                           (char)*(undefined8 *)(param_1 + 0x28));
      }
LAB_1c0001d13:
      uVar13 = 0x19;
      uVar8 = 0xc0000001;
      goto LAB_1c00019ae;
    case '\f':
      uVar10 = 2;
      bVar6 = true;
      bVar14 = 2;
      bVar4 = bVar5;
      break;
    case '\r':
      if (bVar4) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar11 = 0x36;
          goto LAB_1c0001cee;
        }
        goto LAB_1c0001d13;
      }
      bVar12 = param_2[1];
      uVar10 = (ulonglong)bVar12;
      bVar6 = true;
      bVar4 = true;
      break;
    case '\x0e':
      bVar7 = false;
    case '\v':
      bVar5 = bVar7;
      bVar12 = *(byte *)(param_1 + 0xb);
    }
  }
  if (!bVar4) {
    bVar14 = bVar12;
  }
  uVar9 = (uint)bVar12;
  if (!bVar4) {
    uVar9 = (uint)uVar10 & 0xff;
  }
  uVar10 = (ulonglong)*(uint *)(param_1 + 0x18) + *(ulonglong *)(param_1 + 0x10);
  if ((uVar10 < *(ulonglong *)(param_1 + 0x10)) || (0xffffffff < uVar10)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sqDDq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
LAB_1c0001adb:
    uVar8 = 0xc00000bb;
    goto LAB_1c00019ae;
  }
  if (bVar5) {
    if ((*(int *)(param_1 + 0x1c) != 0) &&
       ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_SF_sqDq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
    uVar3 = *(uint *)(param_1 + 0x20);
    if (((uVar3 & 7) != 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
    {
      in_stack_ffffffffffffffa0 = "RhpValidateSerialBusRegionSpaceAccess";
      WPP_RECORDER_SF_sDDq
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),(ulonglong)uVar3,uVar10,0x3d,
                 in_stack_ffffffffffffff98,"RhpValidateSerialBusRegionSpaceAccess",(char)uVar3,
                 (char)(uVar3 >> 3) + '\x01',(char)*(undefined8 *)(param_1 + 0x28));
    }
  }
  else if (((uVar10 != 0) || (*(int *)(param_1 + 0x1c) != 0)) &&
          ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_sdqDq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  uVar3 = *param_3;
  uVar9 = uVar9 + 2;
  if (uVar3 < uVar9) {
    if (!bVar6) {
      *param_3 = uVar9;
      uVar8 = 0xc0000023;
      goto LAB_1c00019ae;
    }
    uVar8 = 0xc0000001;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c00019ae;
    uVar11 = 0x3e;
  }
  else {
    uVar9 = bVar14 + 2;
    if (uVar9 <= uVar3) {
      return 0;
    }
    uVar8 = 0xc0000001;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c00019ae;
    uVar11 = 0x3f;
  }
  uVar8 = 0xc0000001;
  WPP_RECORDER_SF_sdDDq
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),(ulonglong)uVar3,(ulonglong)uVar9,uVar11,
             in_stack_ffffffffffffff98,in_stack_ffffffffffffffa0,*(undefined1 *)(param_1 + 10),
             (char)uVar9,(char)uVar3,(char)*(undefined8 *)(param_1 + 0x28));
LAB_1c00019ae:
  if (uVar2 != 0) {
    *param_2 = uVar13;
  }
  return uVar8;
}



===== RhpProcessRegionSpaceAccessAsync @ 1c0001e20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int RhpProcessRegionSpaceAccessAsync(undefined8 param_1,longlong *param_2)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  undefined4 *puVar4;
  undefined8 in_stack_ffffffffffffff88;
  undefined8 local_58;
  code *pcStack_50;
  ulonglong local_48;
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined8 uStack_28;
  undefined8 local_20;
  undefined8 uStack_18;
  undefined *local_10;
  
  local_40 = 0;
  uStack_3c = 0;
  uStack_38 = 0;
  uStack_34 = 0;
  local_10 = (undefined *)((ulonglong)local_10 & 0xffffffff00000000);
  local_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  local_48 = local_48 & 0xffffffff00000000;
  local_20 = 0;
  uStack_18 = 0;
  local_58 = 0;
  pcStack_50 = (code *)0x0;
  if (*(longlong *)(*param_2 + 0x38) == 0) {
    puVar4 = &local_40;
    puVar2 = &local_58;
    pcStack_50 = RhpEvtOpRegionProcessRegionSpaceWorkItem;
    local_10 = PTR__WDF_RH_OPREGION_WORKITEM_TYPE_INFO_1c0016110;
    local_58 = 0x18;
    local_48 = 0;
    uStack_3c = 0;
    uStack_38 = 0;
    uStack_34 = 0;
    local_30 = 0;
    uStack_2c = 0;
    uStack_18 = 0;
    local_40 = 0x38;
    uStack_28 = 0x100000001;
    local_20 = param_1;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0xbd8))(WdfDriverGlobals);
    if (iVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return iVar1;
      }
      WPP_RECORDER_SF_sdi(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar2,puVar4,0x1e,
                          in_stack_ffffffffffffff88,"RhpProcessRegionSpaceAccessAsync",(char)iVar1,
                          (char)*(undefined8 *)(*param_2 + 0xb0));
      return iVar1;
    }
    puVar2 = (undefined8 *)
             (**(code **)(WdfFunctions_01015 + 0x650))
                       (WdfDriverGlobals,*(undefined8 *)(*param_2 + 0x38),
                        PTR__WDF_RH_OPREGION_WORKITEM_TYPE_INFO_1c0016110);
    uVar3 = (**(code **)(WdfFunctions_01015 + 0x660))(WdfDriverGlobals,*param_2);
    *puVar2 = uVar3;
  }
  (**(code **)(WdfFunctions_01015 + 0xbe0))(WdfDriverGlobals,*(undefined8 *)(*param_2 + 0x38));
  *param_2 = 0;
  return 0x103;
}



===== RhpCleanAndReleaseRequestContext @ 1c0001fe0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void RhpCleanAndReleaseRequestContext(longlong param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  longlong *plVar3;
  longlong lVar4;
  undefined8 local_28;
  undefined4 local_20;
  undefined8 local_1c;
  undefined4 local_14;
  
  local_28 = 0x18;
  local_1c = 0;
  local_14 = 0;
  local_20 = 0;
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x660))(WdfDriverGlobals,param_1);
  (**(code **)(WdfFunctions_01015 + 0x7c8))(WdfDriverGlobals,uVar2,&local_28);
  lVar1 = *(longlong *)(param_1 + 0x30);
  if (lVar1 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x550))(WdfDriverGlobals,lVar1);
  }
  if (*(longlong *)(param_1 + 0xb0) != 0) {
    ObfDereferenceObject();
  }
  if (*(longlong *)(param_1 + 0x88) != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
  if (*(longlong *)(param_1 + 0xd8) != 0) {
    ExFreePoolWithTag();
  }
  *(undefined8 *)(param_1 + 0xd0) = 0;
  *(undefined8 *)(param_1 + 0xd8) = 0;
  if (*(longlong *)(param_1 + 200) != 0) {
    ExFreePoolWithTag();
  }
  *(undefined8 *)(param_1 + 0xc0) = 0;
  *(undefined8 *)(param_1 + 200) = 0;
  lVar4 = *(longlong *)(param_1 + 0x38);
  if (lVar4 != 0) {
    plVar3 = (longlong *)
             (**(code **)(WdfFunctions_01015 + 0x650))
                       (WdfDriverGlobals,lVar4,PTR__WDF_RH_OPREGION_WORKITEM_TYPE_INFO_1c0016110);
    if (*plVar3 == 0) {
      (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
      lVar4 = 0;
    }
  }
  memset((void *)(param_1 + 0x28),0,0xb8);
  *(longlong *)(param_1 + 0x38) = lVar4;
  *(longlong *)(param_1 + 0x30) = lVar1;
  RhpReleaseRequestContext(param_1);
  return;
}



===== RhpReleaseRequestContext @ 1c00021a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void RhpReleaseRequestContext(longlong param_1)

{
  bool bVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  undefined4 *puVar5;
  undefined8 local_res8;
  ulonglong local_res10;
  undefined8 local_res18;
  undefined8 in_stack_ffffffffffffff78;
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
  
  local_res8 = 0;
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
  if (*(longlong *)(param_1 + 0x30) != 0) {
    pcStack_60 = RhpEvtOpRegionReleaseWorkItem;
    local_20 = PTR__WDF_RH_OPREGION_WORKITEM_TYPE_INFO_1c0016110;
    local_68 = 0x18;
    local_58 = 0;
    uStack_4c = 0;
    uStack_48 = 0;
    uStack_44 = 0;
    local_40 = 0;
    uStack_3c = 0;
    uStack_28 = 0;
    local_50 = 0x38;
    uStack_38 = 0x100000001;
    local_30 = (**(code **)(WdfFunctions_01015 + 0x570))(WdfDriverGlobals);
    puVar5 = &local_50;
    puVar4 = &local_68;
    iVar2 = (**(code **)(WdfFunctions_01015 + 0xbd8))(WdfDriverGlobals,puVar4,puVar5,&local_res8);
    if (-1 < iVar2) {
      puVar4 = (undefined8 *)
               (**(code **)(WdfFunctions_01015 + 0x650))
                         (WdfDriverGlobals,local_res8,
                          PTR__WDF_RH_OPREGION_WORKITEM_TYPE_INFO_1c0016110);
      uVar3 = (**(code **)(WdfFunctions_01015 + 0x660))(WdfDriverGlobals,param_1);
      *puVar4 = uVar3;
      (**(code **)(WdfFunctions_01015 + 0xbe0))(WdfDriverGlobals,local_res8);
      return;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sqD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar4,puVar5,10,
                          in_stack_ffffffffffffff78,"RhpReleaseRequestContext",
                          (char)*(undefined8 *)(param_1 + 0x30),(char)iVar2);
    }
    *(undefined8 *)(param_1 + 0x30) = 0;
  }
  bVar1 = false;
  local_res10 = 0;
  local_res18 = 0;
  (**(code **)(WdfFunctions_01015 + 0x610))
            (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x18),&local_res10);
  if (0x400 < local_res10) {
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x600))
                      (WdfDriverGlobals,0,0x200,0x48736552,0x400,&local_res18,0);
    if (iVar2 < 0) {
      bVar1 = true;
    }
    else {
      (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x18));
      *(undefined8 *)(param_1 + 0x18) = local_res18;
    }
  }
  local_res10 = 0;
  local_res18 = 0;
  (**(code **)(WdfFunctions_01015 + 0x610))
            (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x20),&local_res10);
  if (0x400 < local_res10) {
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x600))
                      (WdfDriverGlobals,0,0x200,0x48736552,0x400,&local_res18,0);
    if (iVar2 < 0) {
      bVar1 = true;
    }
    else {
      (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x20));
      *(undefined8 *)(param_1 + 0x20) = local_res18;
    }
  }
  ExAcquireFastMutex(&RhOpRegionLock);
  if ((2 < RhOpRegionRequestAvailable) || ((bVar1 && (RhOpRegionRequestAvailable != 0)))) {
    ExReleaseFastMutex(&RhOpRegionLock);
    uVar3 = (**(code **)(WdfFunctions_01015 + 0x660))(WdfDriverGlobals,param_1);
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,uVar3);
  }
  else {
    RhOpRegionRequestAvailable = RhOpRegionRequestAvailable + 1;
    *(undefined1 *)(param_1 + 0x10) = 0;
    ExReleaseFastMutex(&RhOpRegionLock);
  }
  return;
}



===== RhpCleanRequestContext @ 1c0002550 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void RhpCleanRequestContext(longlong param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  longlong *plVar3;
  longlong lVar4;
  undefined8 local_28;
  undefined4 local_20;
  undefined8 local_1c;
  undefined4 local_14;
  
  local_28 = 0x18;
  local_1c = 0;
  local_14 = 0;
  local_20 = 0;
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x660))(WdfDriverGlobals,param_1);
  (**(code **)(WdfFunctions_01015 + 0x7c8))(WdfDriverGlobals,uVar2,&local_28);
  lVar1 = *(longlong *)(param_1 + 0x30);
  if (lVar1 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x550))(WdfDriverGlobals,lVar1);
  }
  if (*(longlong *)(param_1 + 0xb0) != 0) {
    ObfDereferenceObject();
  }
  if (*(longlong *)(param_1 + 0x88) != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
  if (*(longlong *)(param_1 + 0xd8) != 0) {
    ExFreePoolWithTag();
  }
  *(undefined8 *)(param_1 + 0xd0) = 0;
  *(undefined8 *)(param_1 + 0xd8) = 0;
  if (*(longlong *)(param_1 + 200) != 0) {
    ExFreePoolWithTag();
  }
  *(undefined8 *)(param_1 + 0xc0) = 0;
  *(undefined8 *)(param_1 + 200) = 0;
  lVar4 = *(longlong *)(param_1 + 0x38);
  if (lVar4 != 0) {
    plVar3 = (longlong *)
             (**(code **)(WdfFunctions_01015 + 0x650))
                       (WdfDriverGlobals,lVar4,PTR__WDF_RH_OPREGION_WORKITEM_TYPE_INFO_1c0016110);
    if (*plVar3 == 0) {
      (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
      lVar4 = 0;
    }
  }
  memset((void *)(param_1 + 0x28),0,0xb8);
  *(longlong *)(param_1 + 0x30) = lVar1;
  *(longlong *)(param_1 + 0x38) = lVar4;
  return;
}



===== RhpGetRequestContext @ 1c0002710 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int RhpGetRequestContext(undefined8 param_1,longlong param_2,undefined8 *param_3)

{
  code *pcVar1;
  int iVar2;
  undefined *puVar3;
  undefined1 *puVar4;
  longlong *plVar5;
  longlong *local_res18;
  undefined8 local_res20;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  undefined8 local_28;
  undefined8 local_20;
  
  iVar2 = 0;
  local_res20 = 0;
  plVar5 = (longlong *)0x0;
  local_28 = 0;
  local_res18 = (longlong *)0x0;
  *param_3 = 0;
  ExAcquireFastMutex(&RhOpRegionLock);
  if (RhOpRegionRequestAvailable != 0) {
    for (plVar5 = RhOpRegionRequestListHead; (longlong **)plVar5 != &RhOpRegionRequestListHead;
        plVar5 = (longlong *)*plVar5) {
      if ((char)plVar5[2] == '\0') {
        (**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,plVar5[3],&local_res20);
        param_2 = plVar5[4];
        (**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,param_2,&local_28);
        goto LAB_1c000276a;
      }
    }
    plVar5 = (longlong *)0x0;
LAB_1c000276a:
    RhOpRegionRequestAvailable = RhOpRegionRequestAvailable + -1;
    *(undefined1 *)(plVar5 + 2) = 1;
    local_res18 = plVar5;
  }
  puVar4 = auStack_48;
  puVar3 = &RhOpRegionLock;
  ExReleaseFastMutex();
  if (plVar5 == (longlong *)0x0) {
    iVar2 = RhpCreateRequestContext(puVar3,param_2,(longlong *)&local_res18);
    plVar5 = local_res18;
    if (iVar2 < 0) {
      if (local_res18 == (longlong *)0x0) {
        return iVar2;
      }
      RhpReleaseRequestContext((longlong)local_res18);
      return iVar2;
    }
    *(undefined1 *)(local_res18 + 2) = 1;
    ExAcquireFastMutex(&RhOpRegionLock);
    if ((longlong **)*DAT_1c0016768 != &RhOpRegionRequestListHead) {
      pcVar1 = (code *)swi(0x29);
      DAT_1c0016768 = (longlong *)(*pcVar1)(3);
      puVar4 = auStack_40;
    }
    *plVar5 = (longlong)&RhOpRegionRequestListHead;
    plVar5[1] = (longlong)DAT_1c0016768;
    *DAT_1c0016768 = (longlong)plVar5;
    DAT_1c0016768 = plVar5;
    *(undefined8 *)(puVar4 + -8) = 0x1c00028bc;
    ExReleaseFastMutex(&RhOpRegionLock);
  }
  else {
    local_res18 = (longlong *)0x0;
    (**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,plVar5[3]);
    local_20 = 0;
    (**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,plVar5[4],&local_20);
  }
  *param_3 = plVar5;
  return iVar2;
}



===== RhpFreeUnicodeString @ 1c00028d0 =====

void RhpFreeUnicodeString(undefined8 *param_1)

{
  if (param_1[1] != 0) {
    ExFreePoolWithTag(param_1[1],0x48736552);
  }
  *param_1 = 0;
  param_1[1] = 0;
  return;
}



===== RtlUnicodeStringPrintf @ 1c0002910 =====

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
      (uVar2 != 0xffff)) && ((*(longlong *)(param_1 + 4) != 0 || ((uVar1 == 0 && (uVar2 == 0)))))) {
    uVar5 = 0;
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



===== RhpSetBufferSizeRequestContext @ 1c00029d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 RhpSetBufferSizeRequestContext(undefined8 param_1,uint param_2,longlong param_3)

{
  undefined8 uVar1;
  ulonglong local_res18;
  undefined8 local_res20;
  
  local_res18 = 0;
  (**(code **)(WdfFunctions_01015 + 0x610))
            (WdfDriverGlobals,*(undefined8 *)(param_3 + 0x18),&local_res18);
  local_res18 = 0;
  local_res20 = 0;
  (**(code **)(WdfFunctions_01015 + 0x610))
            (WdfDriverGlobals,*(undefined8 *)(param_3 + 0x20),&local_res18);
  if (local_res18 < param_2) {
    uVar1 = (**(code **)(WdfFunctions_01015 + 0x600))
                      (WdfDriverGlobals,0,0x200,0x48736552,(ulonglong)param_2,&local_res20,0);
    if ((int)uVar1 < 0) {
      return uVar1;
    }
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,*(undefined8 *)(param_3 + 0x20));
    *(undefined8 *)(param_3 + 0x20) = local_res20;
  }
  return 0;
}



===== RhpAcquireOpRegionLock @ 1c0002ad0 =====

void RhpAcquireOpRegionLock(void)

{
  ExAcquireFastMutex(&RhOpRegionLock);
  return;
}



===== RhpCompleteRegionSpaceAccess @ 1c0002b00 =====

void RhpCompleteRegionSpaceAccess
               (int param_1,int param_2,undefined8 param_3,char *param_4,int param_5)

{
  if ((((param_1 == 8) || (param_1 != 9)) || (param_5 == 0)) ||
     ((-1 < param_2 || (*param_4 != '\0')))) {
    return;
  }
  *param_4 = '\x01';
  return;
}



===== PlExtpProcessNativeMethodEvalRequest @ 1c0002b30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint PlExtpProcessNativeMethodEvalRequest(longlong *param_1,undefined8 *param_2)

{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined8 uVar6;
  int iVar7;
  undefined1 auStackY_98 [32];
  uint local_68;
  undefined4 uStack_64;
  uint uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  uint local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_98;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x13,
                     &WPP_691b4491ef5f310687b9ddd4db0f5bab_Traceguids);
  }
  uStack_64 = 0;
  uStack_60 = 0;
  bVar2 = false;
  local_68 = 0;
  if (param_2 == (undefined8 *)0x0) {
    uStack_50 = 0;
    local_48 = 0;
    local_58 = 0;
  }
  else {
    local_58 = *param_2;
    uStack_50 = param_2[1];
    local_48 = *(uint *)(param_2 + 2);
  }
  LOCK();
  *(int *)((longlong)param_1 + 0x3c) = *(int *)((longlong)param_1 + 0x3c) + 1;
  UNLOCK();
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,param_1[5]);
  do {
    uVar4 = PlExtpNativeMethodEvalStateTransition((longlong)param_1,(int *)&local_58,&local_68);
    uVar5 = local_68;
    bVar1 = 2 < local_68;
    if (bVar1) {
      (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals);
    }
    uVar3 = uStack_60;
    if (uVar5 == 0) {
LAB_1c0002cab:
      uVar5 = 0;
    }
    else {
      if ((uVar5 == 1) || (uVar5 == 2)) {
        bVar2 = true;
        uVar4 = uStack_60;
        uVar5 = uStack_60;
      }
      else {
        if (uVar5 == 0x11) {
          uVar5 = PlExtpPepNativeEvalMethod((longlong)param_1);
        }
        else if (uVar5 == 0x12) {
          uVar5 = PlExtpAllocateMethodResources((longlong)param_1);
        }
        else {
          if (uVar5 == 0x13) goto LAB_1c0002cab;
          if (uVar5 == 0x14) {
            iVar7 = 0;
          }
          else {
            if (uVar5 != 0x15) {
              uVar5 = 0xc0000001;
              uVar4 = 0xc0000001;
              goto LAB_1c0002cae;
            }
            iVar7 = 1;
          }
          uVar5 = PlExtpCheckDeviceStateMachine((longlong)param_1,iVar7);
        }
      }
      if (uVar5 == 0x103) {
        uVar6 = PlExtpPendRequest(param_1);
        uVar4 = (uint)uVar6;
        if (uVar4 != 0x103) {
          uVar5 = *(uint *)((longlong)param_1 + 0x74);
        }
      }
    }
LAB_1c0002cae:
    uStack_50 = CONCAT44(uStack_64,local_68);
    local_48 = uVar3;
    local_58 = CONCAT44(uVar5,1);
    if (bVar1) {
      (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,param_1[5]);
    }
    if (uVar4 != 0xc0000016) {
      (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,param_1[5]);
      PlExtpDereferenceRequest((longlong)param_1);
      if (bVar2) {
        PlExtpCompleteRequestFinal(param_1);
      }
      return uVar4;
    }
  } while( true );
}



===== PlExtpNativeMethodEvalStateTransition @ 1c0002d58 =====

undefined4 PlExtpNativeMethodEvalStateTransition(longlong param_1,int *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x12,
                     &WPP_691b4491ef5f310687b9ddd4db0f5bab_Traceguids);
  }
  iVar5 = param_2[1];
  iVar6 = *param_2;
  iVar4 = -0x3fffffea;
  uVar8 = 0;
  if (*(int *)(param_1 + 0x14) != 2) {
    *(undefined4 *)(param_1 + 0x34) = 3;
  }
  iVar2 = *(int *)(param_1 + 0x34);
  *(int *)(param_1 + 0x38) = iVar2;
  iVar3 = iVar5;
  uVar7 = 0;
  do {
    if (iVar2 < 8) {
      if (iVar2 == 7) {
        if (iVar6 == 0) {
          uVar7 = 0x12;
          goto LAB_1c0002f30;
        }
        if (iVar5 < 0) goto LAB_1c0002f5b;
        iVar2 = 0xb;
      }
      else if ((iVar2 == 0) || (iVar2 == 1)) {
LAB_1c0002edb:
        uVar7 = 1;
        uVar8 = 0xc0000001;
        iVar4 = -0x3fffffff;
        *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(param_1 + 0x38);
      }
      else {
        if (iVar2 != 2) {
          if (iVar2 == 3) {
            uVar7 = 1;
          }
          else {
            if (iVar2 != 5) {
              if (iVar2 != 6) goto LAB_1c0002edb;
              if (iVar6 == 0) {
                uVar7 = 0x11;
                goto LAB_1c0002f30;
              }
              if (iVar5 < 0) {
                if (iVar5 != -0x3fffffdd) goto LAB_1c0002f5b;
                *(undefined1 *)(param_1 + 0x148) = 1;
                iVar2 = 0xc;
              }
              else {
                *(undefined1 *)(param_1 + 0x148) = 0;
                iVar2 = 10;
              }
              goto LAB_1c0002f61;
            }
            uVar7 = 2;
            iVar2 = 0;
          }
          uVar8 = 0;
          goto LAB_1c0002f33;
        }
        *(undefined4 *)(param_1 + 0x108) = 0;
        iVar2 = 9;
        *(undefined1 *)(param_1 + 0x148) = 0;
      }
    }
    else {
      if (iVar2 == 8) {
        if (iVar6 == 0) {
          uVar7 = 0x13;
LAB_1c0002f30:
          uVar8 = 0xc0000016;
LAB_1c0002f33:
          iVar4 = 0;
          goto LAB_1c0002f61;
        }
        iVar5 = *(int *)(param_1 + 0x108);
        if (*(char *)(param_1 + 0x148) != '\0') {
LAB_1c0002f4a:
          iVar2 = 7;
          goto LAB_1c0002f61;
        }
        iVar2 = 5;
        if (iVar5 < 0) goto LAB_1c0002f5b;
      }
      else {
        if (iVar2 != 9) {
          if (iVar2 == 10) {
            if (iVar6 == 0) {
              uVar7 = 0x15;
              goto LAB_1c0002f30;
            }
            if (iVar6 == 1) goto LAB_1c0002f0e;
          }
          else if (iVar2 == 0xb) {
            iVar2 = 6;
          }
          else {
            if (iVar2 != 0xc) goto LAB_1c0002edb;
LAB_1c0002f0e:
            iVar2 = 8;
          }
          goto LAB_1c0002f61;
        }
        if (iVar6 == 0) {
          uVar7 = 0x14;
          goto LAB_1c0002f30;
        }
        if (-1 < iVar5) goto LAB_1c0002f4a;
LAB_1c0002f5b:
        iVar2 = 3;
      }
      iVar3 = iVar5;
    }
LAB_1c0002f61:
    *(undefined4 *)(param_1 + 0x154 + (ulonglong)*(byte *)(param_1 + 0x150) * 4) =
         *(undefined4 *)(param_1 + 0x34);
    *(int *)(param_1 + 0x34) = iVar2;
    *(byte *)(param_1 + 0x150) = *(char *)(param_1 + 0x150) + 1U & 3;
    uVar1 = 0;
    if (iVar4 != -0x3fffffea) {
      uVar1 = uVar7;
    }
    iVar6 = 0;
    uVar7 = uVar1;
    if (iVar4 != -0x3fffffea) {
      *param_3 = uVar1;
      param_3[2] = iVar3;
      param_3[1] = iVar2;
      return uVar8;
    }
  } while( true );
}



===== PlExtpPepNativeEvalMethod @ 1c0002fd8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int PlExtpPepNativeEvalMethod(longlong param_1)

{
  undefined8 *_Dst;
  longlong lVar1;
  int iVar2;
  ushort *puVar3;
  ulonglong uVar4;
  int *_Dst_00;
  ulonglong uVar5;
  longlong lVar6;
  int local_58 [2];
  undefined8 local_50;
  undefined4 local_48;
  undefined8 local_40;
  undefined8 *local_38;
  undefined8 local_30;
  char local_28;
  
  local_58[1] = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x28,
                     &WPP_a3b1741888e13d4a1c14bd4949ad3719_Traceguids);
  }
  lVar1 = *(longlong *)(param_1 + 0x20);
  _Dst = (undefined8 *)(param_1 + 0xe8);
  memset(_Dst,0,0x60);
  lVar6 = 0;
  *_Dst = *(undefined8 *)(lVar1 + 0x48);
  *(undefined4 *)(param_1 + 0xf0) = 1;
  *(undefined4 *)(param_1 + 0xf8) = *(undefined4 *)(param_1 + 0x90);
  *(undefined4 *)(param_1 + 0x118) = *(undefined4 *)(param_1 + 0x94);
  *(undefined8 *)(param_1 + 0x128) = *(undefined8 *)(param_1 + 0x98);
  if (*(uint *)(param_1 + 0x94) != 0) {
    puVar3 = (ushort *)(*(longlong *)(param_1 + 0x98) + 2);
    uVar5 = (ulonglong)*(uint *)(param_1 + 0x94);
    do {
      uVar4 = (ulonglong)*puVar3;
      if (*puVar3 < 4) {
        uVar4 = 4;
      }
      puVar3 = puVar3 + 4;
      lVar6 = lVar6 + 4 + uVar4;
      uVar5 = uVar5 - 1;
    } while (uVar5 != 0);
  }
  *(longlong *)(param_1 + 0x120) = lVar6;
  _Dst_00 = local_58;
  *(undefined4 *)(param_1 + 0x130) = *(undefined4 *)(param_1 + 0xa0);
  *(undefined8 *)(param_1 + 0x140) = *(undefined8 *)(param_1 + 0xd0);
  lVar6 = 0x50;
  *(undefined8 *)(param_1 + 0x138) = *(undefined8 *)(param_1 + 0xd8);
  *(undefined8 *)(param_1 + 0x110) = *(undefined8 *)(param_1 + 0x18);
  memset(_Dst_00,0,0x50);
  local_50 = PlExtPoFxRequestContext;
  local_48 = 7;
  local_30 = 0x60;
  local_40 = *(undefined8 *)(lVar1 + 0x40);
  local_38 = _Dst;
  if (PlExtVerifyMode == '\0') {
    if (PlExtPoFxRequestHandler != (code *)0x0) {
      _Dst_00 = local_58;
      iVar2 = (*PlExtPoFxRequestHandler)();
      goto LAB_1c0003155;
    }
    iVar2 = -0x3fffffff;
  }
  else {
    _Dst_00 = local_58;
    uVar5 = PlExtpVerifyPoFxRequestHandler(_Dst_00,lVar1,lVar6);
    iVar2 = (int)uVar5;
LAB_1c0003155:
  }
  if (iVar2 < 0) {
LAB_1c000316b:
    *(int *)(param_1 + 0x108) = iVar2;
  }
  else {
    if (local_28 == '\0') {
      if (-1 < iVar2) {
        iVar2 = -0x3fffff45;
        *(undefined4 *)(param_1 + 0x108) = 0xc00000bb;
        goto LAB_1c000318b;
      }
      goto LAB_1c000316b;
    }
    iVar2 = *(int *)(param_1 + 0x108);
  }
  if (iVar2 == -0x3fffffdd) {
    *(undefined8 *)(param_1 + 0xe0) = *(undefined8 *)(param_1 + 0x138);
  }
LAB_1c000318b:
  PlExtpLogMethodEval(_Dst_00,lVar1,(longlong)_Dst,iVar2);
  return iVar2;
}



===== PlExtpLogMethodEval @ 1c00031c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PlExtpLogMethodEval(undefined8 param_1,longlong param_2,longlong param_3,int param_4)

{
  char *pcVar1;
  byte bVar2;
  undefined2 uVar3;
  undefined1 auStackY_68 [32];
  undefined8 in_stack_ffffffffffffffb8;
  undefined4 local_18;
  undefined1 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_68;
  if (param_4 == 0x103) {
    pcVar1 = "PENDING";
  }
  else if (param_4 == -0x3fffffdd) {
    pcVar1 = "[STATUS_BUFFER_TOO_SMALL]";
  }
  else {
    pcVar1 = "SUCCESS";
    if (param_4 < 0) {
      pcVar1 = "FAILED";
    }
  }
  local_18 = *(undefined4 *)(param_3 + 0x10);
  local_14 = 0;
  if (((param_4 + 0x80000000U & 0x80000000) == 0) && (param_4 != -0x3fffffdd)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return;
    }
    uVar3 = 0xb;
    bVar2 = 2;
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return;
    }
    uVar3 = 10;
    bVar2 = 4;
  }
  WPP_RECORDER_SF_SssD
            (*(undefined8 *)(param_2 + 0x98),bVar2,param_3,uVar3,in_stack_ffffffffffffffb8,
             *(wchar_t **)(param_2 + 0x18),(char *)&local_18,pcVar1,(char)param_4);
  return;
}



===== PlExtpProcessAcpiNotifyRequest @ 1c00032b0 =====

uint PlExtpProcessAcpiNotifyRequest(longlong *param_1)

{
  longlong lVar1;
  uint uVar2;
  longlong local_res8;
  
  local_res8 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x1b,
                     &WPP_691b4491ef5f310687b9ddd4db0f5bab_Traceguids);
  }
  LOCK();
  *(int *)((longlong)param_1 + 0x3c) = *(int *)((longlong)param_1 + 0x3c) + 1;
  UNLOCK();
  uVar2 = PlExtpFindDeviceByNameOrHandle(2,0,param_1[0x11],&local_res8);
  lVar1 = local_res8;
  if (uVar2 == 0) {
    param_1[4] = local_res8;
    uVar2 = PlExtpCheckDeviceStateMachine((longlong)param_1,0);
    if ((int)uVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qDD();
      }
    }
    else {
      uVar2 = PlExtpAcpiNotify(lVar1,(longlong)param_1);
      PlExtpCheckDeviceStateMachine((longlong)param_1,1);
    }
    IoReleaseRemoveLockEx(lVar1 + 0x78,0x78466550,0x20);
    param_1[4] = 0;
  }
  else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qDD();
  }
  PlExtpDereferenceRequest((longlong)param_1);
  PlExtpCompleteRequestFinal(param_1);
  return uVar2;
}



===== PlExtpFindDeviceByNameOrHandle @ 1c0003410 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int PlExtpFindDeviceByNameOrHandle
              (int param_1,undefined8 param_2,longlong param_3,undefined8 *param_4)

{
  int iVar1;
  int iVar2;
  undefined8 *puVar3;
  bool bVar4;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x15,
                     &WPP_a31fe4b5b02930fb8029abd8f99eeaaf_Traceguids);
  }
  iVar2 = -0x3ffffddb;
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,PlExtAcpiDeviceListLock,0);
  puVar3 = PlExtAcpiDeviceList;
  do {
    if ((undefined8 **)puVar3 == &PlExtAcpiDeviceList) {
LAB_1c000352e:
      (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,PlExtAcpiDeviceListLock);
      return iVar2;
    }
    if (param_1 == 0) {
      iVar1 = RtlCompareUnicodeString(puVar3 + 2,param_2,0);
      bVar4 = iVar1 == 0;
LAB_1c00034e9:
      if (bVar4) {
        iVar2 = 0;
        if (puVar3 != (undefined8 *)0x0) {
          iVar2 = IoAcquireRemoveLockEx(puVar3 + 0xf,0x78466550,"",1,0x20);
          if (-1 < iVar2) {
            *param_4 = puVar3;
            iVar2 = 0;
          }
        }
        goto LAB_1c000352e;
      }
    }
    else {
      if (param_1 == 1) {
        bVar4 = puVar3[4] == param_3;
        goto LAB_1c00034e9;
      }
      if (param_1 == 2) {
        bVar4 = puVar3[8] == param_3;
        goto LAB_1c00034e9;
      }
    }
    puVar3 = (undefined8 *)*puVar3;
  } while( true );
}



===== PlExtpCompleteRequestFinal @ 1c0003578 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PlExtpCompleteRequestFinal(longlong *param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  code *pcVar3;
  undefined1 uVar4;
  bool bVar5;
  undefined1 *puVar6;
  undefined8 unaff_RDI;
  longlong *plVar7;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  if ((code *)(&PTR_PlExtpBuildDestroyFinalCompletion_1c0016008)
              [(longlong)*(int *)((longlong)param_1 + 0x14) * 2] != (code *)0x0) {
    (*(code *)(&PTR_PlExtpBuildDestroyFinalCompletion_1c0016008)
              [(longlong)*(int *)((longlong)param_1 + 0x14) * 2])(param_1);
  }
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,param_1[5]);
  *(undefined4 *)(param_1 + 6) = 6;
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,param_1[5]);
  uVar4 = ExAcquireSpinLockExclusive(&PlExtRequestListLock);
  plVar1 = (longlong *)*param_1;
  plVar7 = (longlong *)CONCAT71((int7)((ulonglong)unaff_RDI >> 8),uVar4);
  if (plVar1 == param_1) {
LAB_1c0003627:
    PlExtpDereferenceRequest((longlong)param_1);
    ExReleaseSpinLockExclusive(&PlExtRequestListLock);
    puVar6 = auStack_28;
    plVar7 = (longlong *)param_1[9];
    if (plVar7 != (longlong *)0x0) {
      bVar5 = PlExtpRemoveRequestFromParentQueue((longlong)param_1);
      puVar6 = auStack_28;
      param_1[9] = 0;
      goto LAB_1c000366a;
    }
  }
  else {
    if (((longlong *)plVar1[1] == param_1) &&
       (plVar2 = (longlong *)param_1[1], (longlong *)*plVar2 == param_1)) {
      *plVar2 = (longlong)plVar1;
      plVar1[1] = (longlong)plVar2;
      param_1[1] = (longlong)param_1;
      *param_1 = (longlong)param_1;
      goto LAB_1c0003627;
    }
    pcVar3 = (code *)swi(0x29);
    (*pcVar3)(3);
    puVar6 = auStack_20;
  }
  bVar5 = false;
LAB_1c000366a:
  *(undefined8 *)(puVar6 + -8) = 0x1c0003672;
  PlExtpDereferenceRequest((longlong)param_1);
  if ((plVar7 != (longlong *)0x0) && (bVar5 != false)) {
    *(undefined8 *)(puVar6 + -8) = 0x1c0003686;
    PlExtpCompleteRequest(plVar7,0);
  }
  return;
}



===== PlExtpDereferenceRequest @ 1c00036a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PlExtpDereferenceRequest(longlong param_1)

{
  int *piVar1;
  int iVar2;
  
  LOCK();
  piVar1 = (int *)(param_1 + 0x3c);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    if (*(longlong *)(param_1 + 0x48) != 0) {
      PlExtpRemoveRequestFromParentQueue(param_1);
    }
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x18));
  }
  return;
}



===== PlExtpCheckDeviceStateMachine @ 1c00036f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint PlExtpCheckDeviceStateMachine(longlong param_1,int param_2)

{
  longlong lVar1;
  uint uVar2;
  int local_38 [4];
  int local_28 [8];
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x17,
                     &WPP_691b4491ef5f310687b9ddd4db0f5bab_Traceguids);
  }
  lVar1 = *(longlong *)(param_1 + 0x20);
  local_28[2] = 0;
  local_28[3] = 0;
  local_28[4] = 0;
  local_28[1] = 0;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[0] = 0;
  local_28[0] = param_2;
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(lVar1 + 0x28));
  uVar2 = PlExtpDeviceStateTransition(param_1,local_28,local_38);
  if (local_38[0] != 0) {
    if (local_38[0] == 1) {
      uVar2 = 0xc0000010;
    }
    else if (local_38[0] == 3) {
      uVar2 = 0;
    }
    else {
      uVar2 = 0xc0000001;
    }
  }
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(lVar1 + 0x28));
  return uVar2;
}



===== PlExtpDeviceStateTransition @ 1c00037f8 =====

uint PlExtpDeviceStateTransition(longlong param_1,int *param_2,int *param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  longlong lVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  bool bVar11;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x19,
                     &WPP_a31fe4b5b02930fb8029abd8f99eeaaf_Traceguids);
  }
  lVar4 = *(longlong *)(param_1 + 0x20);
  uVar2 = *(uint *)(param_1 + 0x14);
  iVar6 = 0;
  iVar8 = *param_2;
  iVar10 = -0x3fffffea;
  iVar3 = param_2[1];
  uVar7 = 0;
  *(undefined4 *)(lVar4 + 0x34) = *(undefined4 *)(lVar4 + 0x30);
  iVar9 = *(int *)(lVar4 + 0x30);
  do {
    if (iVar9 < 0xb) {
      if (iVar9 == 10) {
        if (uVar2 != 0) goto LAB_1c00039ca;
        if (iVar8 == 0) goto LAB_1c0003cd2;
        iVar9 = 0xf;
        if (-1 < iVar3) {
          iVar9 = 0xc;
        }
      }
      else if ((iVar9 == 0) || (iVar9 == 1)) {
LAB_1c0003a9a:
        uVar7 = 0xc0000001;
        iVar10 = -0x3fffffff;
        *(undefined4 *)(lVar4 + 0x30) = *(undefined4 *)(lVar4 + 0x34);
      }
      else if (iVar9 == 2) {
        if (uVar2 == 0) {
          iVar9 = 4;
        }
        else {
          iVar6 = 1;
          uVar7 = 0;
          iVar10 = 0;
        }
      }
      else if (iVar9 == 4) {
        if (uVar2 != 0) goto LAB_1c00039ca;
        if (iVar8 == 0) {
          iVar6 = 4;
          goto LAB_1c0003cd7;
        }
        uVar5 = *(uint *)(lVar4 + 0x38);
        do {
          LOCK();
          uVar1 = *(uint *)(lVar4 + 0x38);
          bVar11 = uVar5 == uVar1;
          if (bVar11) {
            *(uint *)(lVar4 + 0x38) = uVar5;
          }
          else {
            uVar5 = uVar1;
          }
          UNLOCK();
        } while (!bVar11);
        if ((iVar3 < 0) || ((uVar5 & 1) == 0)) {
LAB_1c0003a0b:
          iVar9 = 0xf;
        }
        else {
          iVar9 = 5;
        }
      }
      else if (iVar9 == 5) {
        if (uVar2 != 0) goto LAB_1c00039ca;
        if (iVar8 == 0) {
          iVar6 = 5;
          goto LAB_1c0003cd7;
        }
        uVar5 = *(uint *)(lVar4 + 0x38);
        do {
          LOCK();
          uVar1 = *(uint *)(lVar4 + 0x38);
          bVar11 = uVar5 == uVar1;
          if (bVar11) {
            *(uint *)(lVar4 + 0x38) = uVar5;
          }
          else {
            uVar5 = uVar1;
          }
          UNLOCK();
        } while (!bVar11);
        if ((iVar3 < 0) || ((uVar5 & 2) == 0)) goto LAB_1c0003a0b;
        iVar9 = 6;
      }
      else if (iVar9 == 6) {
        if (uVar2 != 0) goto LAB_1c00039ca;
        if (iVar8 == 0) {
          iVar6 = 6;
          goto LAB_1c0003cd7;
        }
        if (iVar3 < 0) goto LAB_1c0003a0b;
        iVar9 = 8 - (uint)(*(int *)(lVar4 + 0x60) != 0);
      }
      else if (iVar9 == 7) {
        if (uVar2 != 0) goto LAB_1c00039ca;
        if (iVar8 == 0) {
          iVar6 = 7;
          goto LAB_1c0003cd7;
        }
        iVar9 = 0xf;
        if (-1 < iVar3) {
          iVar9 = 8;
        }
      }
      else if (iVar9 == 8) {
        if (uVar2 != 0) goto LAB_1c00039ca;
        if (iVar8 == 0) {
          iVar6 = 0xe;
          goto LAB_1c0003cd7;
        }
        iVar9 = 0xf;
        if (-1 < iVar3) {
          iVar9 = 9;
        }
      }
      else {
        if (iVar9 != 9) goto LAB_1c0003a9a;
        if (uVar2 != 0) goto LAB_1c00039ca;
        if (iVar8 == 0) {
          iVar6 = 0xf;
          goto LAB_1c0003cd7;
        }
        iVar9 = (iVar3 < 0) + 10;
      }
    }
    else if (iVar9 == 0xb) {
      if (uVar2 == 0) {
        if (iVar8 != 0) {
          iVar9 = 0xf;
          goto LAB_1c0003ce7;
        }
LAB_1c0003cd2:
        iVar6 = 0x10;
LAB_1c0003cd7:
        uVar7 = 0xc0000016;
      }
      else {
LAB_1c00039ca:
        iVar6 = 1;
        uVar7 = 0;
      }
      iVar10 = 0;
    }
    else if (iVar9 == 0xc) {
      if (uVar2 != 0) goto LAB_1c00039ca;
      if (iVar8 == 0) {
        iVar6 = 8;
        goto LAB_1c0003cd7;
      }
      iVar9 = 0xe - (uint)(*(int *)(lVar4 + 0x74) != 0);
    }
    else if (iVar9 == 0xd) {
      if (uVar2 != 0) goto LAB_1c00039ca;
      if (iVar8 == 0) {
        iVar6 = 9;
        goto LAB_1c0003cd7;
      }
      iVar9 = 0xe;
    }
    else if (iVar9 == 0xe) {
      if (uVar2 == 0) {
        IoAcquireRemoveLockEx(lVar4 + 0x78,0x78466550,"",1,0x20);
        iVar6 = 2;
      }
      else {
        if (uVar2 == 1) {
          iVar9 = 0x12;
          goto LAB_1c0003ce7;
        }
        if (2 < uVar2 - 2) goto LAB_1c00039ca;
        if (iVar8 != 0) goto LAB_1c0003b81;
        iVar6 = IoAcquireRemoveLockEx(lVar4 + 0x78,0x78466550,"",1,0x20);
        iVar6 = (iVar6 >> 0x1f & 0xfffffffeU) + 3;
      }
LAB_1c0003b9c:
      uVar7 = 0;
LAB_1c0003bd6:
      iVar10 = 0;
    }
    else if (iVar9 == 0xf) {
      iVar9 = 0x13;
    }
    else {
      if (iVar9 == 0x12) {
        if ((uVar2 - 2 < 3) && (iVar8 == 1)) {
LAB_1c0003b81:
          IoReleaseRemoveLockEx(lVar4 + 0x78,0x78466550,0x20);
          iVar6 = 0;
          goto LAB_1c0003b9c;
        }
        if (uVar2 != 1) goto LAB_1c00039ca;
        if (iVar8 != 0) {
          iVar9 = 0x13;
          goto LAB_1c0003ce7;
        }
        IoReleaseRemoveLockEx(lVar4 + 0x78,0x78466550,0x20);
        iVar6 = 0xd;
        uVar7 = 0xc0000016;
        goto LAB_1c0003bd6;
      }
      if (iVar9 == 0x13) {
        if (1 < uVar2) goto LAB_1c00039ca;
        if (iVar8 == 0) {
          uVar5 = *(uint *)(lVar4 + 0x38);
          do {
            LOCK();
            uVar1 = *(uint *)(lVar4 + 0x38);
            bVar11 = uVar5 == uVar1;
            if (bVar11) {
              *(uint *)(lVar4 + 0x38) = uVar5;
            }
            else {
              uVar5 = uVar1;
            }
            UNLOCK();
          } while (!bVar11);
          if ((uVar5 & 2) != 0) {
            iVar6 = 10;
            goto LAB_1c0003cd7;
          }
          iVar9 = 0x14;
        }
        else {
          iVar9 = 0x14;
        }
      }
      else if (iVar9 == 0x14) {
        if (1 < uVar2) goto LAB_1c00039ca;
        uVar5 = *(uint *)(lVar4 + 0x38);
        do {
          LOCK();
          uVar1 = *(uint *)(lVar4 + 0x38);
          bVar11 = uVar5 == uVar1;
          if (bVar11) {
            *(uint *)(lVar4 + 0x38) = uVar5;
          }
          else {
            uVar5 = uVar1;
          }
          UNLOCK();
        } while (!bVar11);
        if (iVar8 == 0) {
          if ((uVar5 & 1) != 0) {
            iVar6 = 0xb;
            goto LAB_1c0003cd7;
          }
          iVar9 = 0x15;
        }
        else {
          iVar9 = 0x15;
        }
      }
      else {
        if (iVar9 != 0x15) goto LAB_1c0003a9a;
        iVar10 = 0;
        if (uVar2 < 2) {
          LOCK();
          *(undefined4 *)(lVar4 + 0x38) = *(undefined4 *)(lVar4 + 0x38);
          UNLOCK();
          if (iVar8 != 0) {
            iVar9 = 1;
          }
          iVar6 = (-(uint)(iVar8 != 0) & 0xfffffff6) + 0xc;
          uVar7 = ~-(uint)(iVar8 != 0) & 0xc0000016;
        }
        else {
          iVar6 = 1;
          uVar7 = 0;
        }
      }
    }
LAB_1c0003ce7:
    *(undefined4 *)(lVar4 + 0xa4 + (ulonglong)*(byte *)(lVar4 + 0xa0) * 4) =
         *(undefined4 *)(lVar4 + 0x30);
    *(byte *)(lVar4 + 0xa0) = *(char *)(lVar4 + 0xa0) + 1U & 3;
    *(int *)(lVar4 + 0x30) = iVar9;
    iVar8 = 0;
    if (iVar10 != -0x3fffffea) {
      iVar8 = iVar6;
    }
    iVar6 = iVar8;
    iVar8 = 0;
    if (iVar10 != -0x3fffffea) {
      iVar9 = *(int *)(lVar4 + 0x30);
      *param_3 = iVar6;
      param_3[1] = iVar9;
      return uVar7;
    }
  } while( true );
}



===== PlExtpAcpiNotify @ 1c0003d64 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 PlExtpAcpiNotify(longlong param_1,longlong param_2)

{
  undefined4 uVar1;
  undefined8 local_18;
  undefined4 local_10;
  undefined4 local_c;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x10,
                     &WPP_a2afeb96eade37b8f9cc5211bf7c269d_Traceguids);
  }
  local_18 = *(undefined8 *)(param_1 + 0x58);
  local_10 = *(undefined4 *)(param_2 + 0x90);
  local_c = 0;
  uVar1 = (*DAT_1c00165d0)(&local_18);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x11,
                     &WPP_a2afeb96eade37b8f9cc5211bf7c269d_Traceguids);
  }
  return uVar1;
}



===== PlExtQueryPlatformExtensionRegistered @ 1c0003e40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined1 PlExtQueryPlatformExtensionRegistered(void)

{
  int iVar1;
  ulonglong uVar2;
  undefined1 uVar3;
  longlong lVar4;
  int local_58 [4];
  undefined4 local_48;
  undefined1 local_44;
  
  lVar4 = 0x50;
  memset(local_58,0,0x50);
  local_58[0] = 2;
  local_48 = 1;
  if (PlExtVerifyMode == '\0') {
    if (PlExtPoFxRequestHandler == (code *)0x0) {
      iVar1 = -0x3fffffff;
    }
    else {
      iVar1 = (*PlExtPoFxRequestHandler)(local_58);
    }
  }
  else {
    uVar2 = PlExtpVerifyPoFxRequestHandler(local_58,0,lVar4);
    iVar1 = (int)uVar2;
  }
  uVar3 = 0;
  if (-1 < iVar1) {
    uVar3 = local_44;
  }
  return uVar3;
}



===== PlExtNativeMethodEvalRequest @ 1c0003ec0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int PlExtNativeMethodEvalRequest(longlong *param_1)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  longlong lVar5;
  longlong *plVar6;
  undefined8 *puVar7;
  uint uVar8;
  char *pcVar9;
  longlong **pplVar10;
  undefined2 uVar11;
  undefined8 *puVar12;
  longlong *local_res8;
  undefined *in_stack_ffffffffffffffa8;
  
  local_res8 = (longlong *)0x0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_stack_ffffffffffffffa8 = &WPP_691b4491ef5f310687b9ddd4db0f5bab_Traceguids;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,10,
                     &WPP_691b4491ef5f310687b9ddd4db0f5bab_Traceguids);
  }
  lVar1 = *param_1;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_stack_ffffffffffffffa8 = &WPP_a31fe4b5b02930fb8029abd8f99eeaaf_Traceguids;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x15,
                     &WPP_a31fe4b5b02930fb8029abd8f99eeaaf_Traceguids);
  }
  iVar3 = -0x3ffffddb;
  pcVar9 = (char *)0x0;
  iVar2 = -0x3ffffddb;
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,PlExtAcpiDeviceListLock);
  for (puVar12 = PlExtAcpiDeviceList; puVar7 = (undefined8 *)0x0,
      (undefined8 **)puVar12 != &PlExtAcpiDeviceList; puVar12 = (undefined8 *)*puVar12) {
    if (puVar12[4] == lVar1) {
      in_stack_ffffffffffffffa8 =
           (undefined *)CONCAT44((int)((ulonglong)in_stack_ffffffffffffffa8 >> 0x20),0x20);
      pcVar9 = "";
      iVar2 = IoAcquireRemoveLockEx(puVar12 + 0xf,0x78466550,"",1);
      if (-1 < iVar2) {
        iVar2 = 0;
        puVar7 = puVar12;
      }
      break;
    }
  }
  uVar4 = WdfDriverGlobals;
  lVar5 = PlExtAcpiDeviceListLock;
  (**(code **)(WdfFunctions_01015 + 0x9d0))();
  if (iVar2 < 0) {
    iVar3 = -0x3fffffff;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qD(uVar4,4,pcVar9,0xb,&WPP_691b4491ef5f310687b9ddd4db0f5bab_Traceguids,
                         (char)lVar1,(char)param_1[1]);
    }
  }
  else {
    for (uVar8 = 0; uVar8 < *(uint *)(puVar7 + 0xc); uVar8 = uVar8 + 1) {
      lVar5 = puVar7[0xd] + (ulonglong)uVar8 * 0x28;
      if (*(int *)(lVar5 + 8) == (int)param_1[1]) {
        if (lVar5 != 0) {
          iVar2 = *(int *)(lVar5 + 0x14);
          iVar3 = *(int *)((longlong)param_1 + 0xc);
          if (iVar2 == iVar3) {
            iVar3 = (int)param_1[3];
            if ((iVar3 == 0) || (iVar2 = *(int *)(lVar5 + 0x18), iVar2 == iVar3)) {
              pplVar10 = &local_res8;
              plVar6 = param_1;
              iVar3 = PlExtpCreateNativeMethodEvalRequest
                                ((longlong)puVar7,param_1,(longlong *)pplVar10);
              if (-1 < iVar3) {
                PlExtpReadyRequestAndScheduleWorker(local_res8);
                return 0x103;
              }
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_SDD(puVar7[0x13],plVar6,pplVar10,0xf,in_stack_ffffffffffffffa8,
                                    (wchar_t *)puVar7[3],(char)param_1[1],(char)iVar3);
              }
              goto LAB_1c0004192;
            }
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar11 = 0xe;
              goto LAB_1c000409a;
            }
          }
          else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar11 = 0xd;
LAB_1c000409a:
            WPP_RECORDER_SF_SDDD
                      (puVar7[0x13],2,9,uVar11,&WPP_691b4491ef5f310687b9ddd4db0f5bab_Traceguids,
                       (wchar_t *)puVar7[3],(char)param_1[1],(char)iVar2,(char)iVar3);
          }
          iVar3 = -0x3ffffff3;
          goto LAB_1c0004192;
        }
        break;
      }
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_SD(puVar7[0x13],lVar5,9,0xc,&WPP_691b4491ef5f310687b9ddd4db0f5bab_Traceguids,
                         (wchar_t *)puVar7[3],(char)param_1[1]);
    }
LAB_1c0004192:
    IoReleaseRemoveLockEx(puVar7 + 0xf,0x78466550,0x20);
  }
  return iVar3;
}



===== PlExtpPepAcpiNotifyHandler @ 1c00041d4 =====

int PlExtpPepAcpiNotifyHandler(longlong param_1,longlong *param_2)

{
  longlong lVar1;
  int iVar2;
  longlong *local_res18;
  
  local_res18 = (longlong *)0x0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x19,
                     &WPP_691b4491ef5f310687b9ddd4db0f5bab_Traceguids);
  }
  iVar2 = PlExtpCreateRequest(3,0,0,param_1,&local_res18);
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qDD();
    }
    if (local_res18 != (longlong *)0x0) {
      PlExtpDereferenceRequest((longlong)local_res18);
    }
  }
  else {
    lVar1 = param_2[1];
    local_res18[0x11] = *param_2;
    local_res18[0x12] = lVar1;
    PlExtpReadyRequestAndScheduleWorker(local_res18);
    iVar2 = 0;
  }
  return iVar2;
}



===== PlExtpCreateRequest @ 1c00042bc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int PlExtpCreateRequest(int param_1,longlong param_2,longlong param_3,longlong param_4,
                       undefined8 *param_5)

{
  longlong *plVar1;
  code *pcVar2;
  int iVar3;
  void *_Dst;
  longlong lVar4;
  longlong *plVar5;
  undefined4 *puVar6;
  undefined8 uVar7;
  undefined1 *puVar8;
  wchar_t *pwVar9;
  longlong local_res10;
  undefined1 auStackY_a8 [8];
  undefined1 auStackY_a0 [24];
  undefined4 local_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 local_54;
  undefined8 local_50;
  longlong local_48;
  undefined8 uStack_40;
  undefined *local_38;
  
  uStack_64 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x1f,
                     &WPP_014e28a2725035dd75100948d63f8491_Traceguids);
  }
  local_res10 = 0;
  if (param_2 == 0) {
    uVar7 = PlExtLogHandle;
    if (param_3 == 0) {
      pwVar9 = L"<no device>";
      goto LAB_1c0004396;
    }
    pwVar9 = L"<no device>";
  }
  else {
    uVar7 = *(undefined8 *)(param_2 + 0x98);
    pwVar9 = *(wchar_t **)(param_2 + 0x18);
    if ((param_1 != 0) && (param_1 != 1)) {
      param_4 = *(longlong *)(param_2 + 0x20);
      goto LAB_1c0004396;
    }
    if (param_3 == 0) goto LAB_1c0004396;
  }
  param_4 = *(longlong *)(param_3 + 0x18);
LAB_1c0004396:
  local_38 = PTR__WDF_PLEXT_REQUEST_CONTEXT_TYPE_INFO_1c0016190;
  local_54 = 0;
  uStack_40 = 0;
  puVar6 = &local_68;
  uStack_64 = 0;
  uStack_60 = 0;
  uStack_5c = 0;
  uStack_58 = 0;
  local_68 = 0x38;
  local_50 = 0x100000001;
  local_48 = param_4;
  iVar3 = (**(code **)(WdfFunctions_01015 + 0x678))(WdfDriverGlobals,puVar6,&local_res10);
  if (iVar3 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_SD(uVar7,puVar6,8,0x20,&WPP_014e28a2725035dd75100948d63f8491_Traceguids,pwVar9
                         ,(char)iVar3);
    }
  }
  else {
    _Dst = (void *)(**(code **)(WdfFunctions_01015 + 0x650))
                             (WdfDriverGlobals,local_res10,
                              PTR__WDF_PLEXT_REQUEST_CONTEXT_TYPE_INFO_1c0016190);
    memset(_Dst,0,0x168);
    local_38 = (undefined *)0x0;
    uStack_58 = 0;
    local_54 = 0;
    uStack_40 = 0;
    local_48 = local_res10;
    uStack_64 = 0;
    uStack_60 = 0;
    uStack_5c = 0;
    local_68 = 0x38;
    local_50 = 0x100000001;
    iVar3 = (**(code **)(WdfFunctions_01015 + 0x9d8))
                      (WdfDriverGlobals,&local_68,(longlong)_Dst + 0x28);
    if (-1 < iVar3) {
      *(undefined4 *)((longlong)_Dst + 0x10) = 0x72466550;
      plVar1 = (longlong *)((longlong)_Dst + 0x50);
      *(int *)((longlong)_Dst + 0x14) = param_1;
      *(undefined4 *)((longlong)_Dst + 0x38) = 0;
      *(longlong *)((longlong)_Dst + 0x18) = local_res10;
      lVar4 = (longlong)_Dst + 0x60;
      *(longlong *)((longlong)_Dst + 0x20) = param_2;
      *(undefined4 *)((longlong)_Dst + 0x34) = 2;
      *(undefined4 *)((longlong)_Dst + 0x30) = 1;
      *(void **)((longlong)_Dst + 8) = _Dst;
      *(void **)_Dst = _Dst;
      *(longlong **)((longlong)_Dst + 0x58) = plVar1;
      *plVar1 = (longlong)plVar1;
      *(longlong *)((longlong)_Dst + 0x68) = lVar4;
      *(longlong *)lVar4 = lVar4;
      *(undefined4 *)((longlong)_Dst + 0x70) = 0;
      *(undefined4 *)((longlong)_Dst + 0x3c) = 1;
      if (param_3 != 0) {
        *(longlong *)((longlong)_Dst + 0x48) = param_3;
        LOCK();
        *(int *)(param_3 + 0x3c) = *(int *)(param_3 + 0x3c) + 1;
        UNLOCK();
        (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(param_3 + 0x28));
        puVar8 = auStackY_a8;
        lVar4 = param_3 + 0x60;
        plVar5 = *(longlong **)(param_3 + 0x68);
        if (*plVar5 != lVar4) {
          plVar5 = (longlong *)0x3;
          pcVar2 = (code *)swi(0x29);
          lVar4 = (*pcVar2)();
          puVar8 = auStackY_a0;
        }
        *plVar1 = lVar4;
        *(longlong **)((longlong)_Dst + 0x58) = plVar5;
        *plVar5 = (longlong)plVar1;
        *(longlong **)(lVar4 + 8) = plVar1;
        uVar7 = *(undefined8 *)(param_3 + 0x28);
        pcVar2 = *(code **)(WdfFunctions_01015 + 0x9e8);
        *(undefined8 *)(puVar8 + -8) = 0x1c00045df;
        (*pcVar2)(WdfDriverGlobals,uVar7);
      }
      *param_5 = _Dst;
      return iVar3;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_SqD(*(undefined8 *)(param_2 + 0x98));
    }
    if ((_Dst != (void *)0x0) && (*(longlong *)((longlong)_Dst + 0x48) != 0)) {
      PlExtpRemoveRequestFromParentQueue((longlong)_Dst);
    }
  }
  if (local_res10 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
  return iVar3;
}



===== PlExtpReadyRequestAndScheduleWorker @ 1c0004610 =====

void PlExtpReadyRequestAndScheduleWorker(longlong *param_1)

{
  undefined1 uVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x1b,
                     &WPP_014e28a2725035dd75100948d63f8491_Traceguids);
  }
  uVar1 = ExAcquireSpinLockExclusive(&PlExtRequestListLock);
  *(undefined4 *)(param_1 + 6) = 3;
  LOCK();
  *(int *)((longlong)param_1 + 0x3c) = *(int *)((longlong)param_1 + 0x3c) + 1;
  UNLOCK();
  PlExtpMoveRequestToTargetQueue(0x1c0016600,param_1);
  PlExtpScheduleWorkerLocked(1);
  ExReleaseSpinLockExclusive(&PlExtRequestListLock,uVar1);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x1c,
                     &WPP_014e28a2725035dd75100948d63f8491_Traceguids);
  }
  return;
}



===== PlExtpCreateNativeMethodEvalRequest @ 1c0004704 =====

int PlExtpCreateNativeMethodEvalRequest(longlong param_1,undefined8 *param_2,longlong *param_3)

{
  undefined8 uVar1;
  int iVar2;
  longlong lVar3;
  undefined8 uVar4;
  longlong local_res20;
  longlong *plVar5;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x10,
                     &WPP_691b4491ef5f310687b9ddd4db0f5bab_Traceguids);
  }
  local_res20 = 0;
  plVar5 = &local_res20;
  uVar4 = 0;
  lVar3 = param_1;
  iVar2 = PlExtpCreateRequest(2,param_1,0,0,plVar5);
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_SDD(*(undefined8 *)(param_1 + 0x98),lVar3,uVar4,0x11,plVar5,
                          *(wchar_t **)(param_1 + 0x18),(char)*(undefined4 *)(param_2 + 1),
                          (char)iVar2);
    }
    if (local_res20 != 0) {
      PlExtpDereferenceRequest(local_res20);
    }
  }
  else {
    uVar4 = *param_2;
    uVar1 = param_2[1];
    *param_3 = local_res20;
    *(undefined8 *)(local_res20 + 0x88) = uVar4;
    *(undefined8 *)(local_res20 + 0x90) = uVar1;
    uVar4 = param_2[3];
    *(undefined8 *)(local_res20 + 0x98) = param_2[2];
    *(undefined8 *)(local_res20 + 0xa0) = uVar4;
    uVar4 = param_2[5];
    *(undefined8 *)(local_res20 + 0xa8) = param_2[4];
    *(undefined8 *)(local_res20 + 0xb0) = uVar4;
    uVar4 = param_2[7];
    *(undefined8 *)(local_res20 + 0xb8) = param_2[6];
    *(undefined8 *)(local_res20 + 0xc0) = uVar4;
    *(undefined8 *)(local_res20 + 200) = param_2[8];
  }
  return iVar2;
}



===== PlExtpScheduleWorkerLocked @ 1c000482c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PlExtpScheduleWorkerLocked(int param_1)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  longlong lVar4;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x19,
                     &WPP_014e28a2725035dd75100948d63f8491_Traceguids);
  }
  iVar2 = 1;
  if (param_1 != 0) {
    iVar2 = param_1;
  }
  if (PlExtWorkerRunning == '\0') {
    iVar2 = iVar2 + -1;
  }
  PlExtWorkerRunning = 1;
  KeSetEvent(&PlExtWorkerProcessQueueEvent,0,0);
  uVar3 = 0;
  lVar4 = 0;
  do {
    lVar1 = PlExtRequestWorkItems;
    if (iVar2 == 0) break;
    if (*(char *)(*(longlong *)(lVar4 + PlExtRequestWorkItems) + 8) == '\0') {
      *(undefined1 *)(*(longlong *)(lVar4 + PlExtRequestWorkItems) + 8) = 1;
      (**(code **)(WdfFunctions_01015 + 0xbe0))(WdfDriverGlobals,**(undefined8 **)(lVar4 + lVar1));
      iVar2 = iVar2 + -1;
      if (iVar2 == 0) break;
    }
    uVar3 = uVar3 + 1;
    lVar4 = lVar4 + 8;
  } while (uVar3 < 8);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x1a,
                     &WPP_014e28a2725035dd75100948d63f8491_Traceguids);
  }
  return;
}



===== PlExtpInvokePoFxRequestHandler @ 1c0004958 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong PlExtpInvokePoFxRequestHandler(int *param_1,longlong param_2,longlong param_3)

{
  ulonglong uVar1;
  
  if (PlExtVerifyMode == '\0') {
    if (PlExtPoFxRequestHandler == (code *)0x0) {
      uVar1 = 0xc0000001;
    }
    else {
      uVar1 = (*PlExtPoFxRequestHandler)();
    }
  }
  else {
    uVar1 = PlExtpVerifyPoFxRequestHandler(param_1,param_2,param_3);
  }
  return uVar1;
}



===== RhpReleaseOpRegionLock @ 1c0004990 =====

void RhpReleaseOpRegionLock(void)

{
  ExReleaseFastMutex(&RhOpRegionLock);
  return;
}



===== WPP_RECORDER_SF_siD @ 1c00049b4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_siD(undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
                        undefined8 param_5,char *param_6,undefined1 param_7,undefined1 param_8)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  
  if ((*(uint *)(WPP_GLOBAL_Control +
                ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + (ulonglong)(param_3 >> 0x10) * 0x14) * 4 +
                0x2c) >> (param_3 - 1 & 0x1f) & 1) != 0) {
    if (param_6 == (char *)0x0) {
      lVar2 = 5;
    }
    else {
      lVar1 = -1;
      do {
        lVar2 = lVar1;
        lVar1 = lVar2 + 1;
      } while (param_6[lVar1] != '\0');
      lVar2 = lVar2 + 2;
    }
    pcVar3 = param_6;
    if (param_6 == (char *)0x0) {
      pcVar3 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + (ulonglong)(param_3 >> 0x10) * 0x50 + 0x18),0x2b
               ,param_5,param_4,pcVar3,lVar2,&param_7,8,&param_8,4,0);
  }
  lVar2 = -1;
  if (param_6 == (char *)0x0) {
    lVar1 = 5;
  }
  else {
    do {
      lVar1 = lVar2;
      lVar2 = lVar1 + 1;
    } while (param_6[lVar2] != '\0');
    lVar1 = lVar1 + 2;
  }
  if (param_6 == (char *)0x0) {
    param_6 = "NULL";
  }
  WppAutoLogTrace(param_1,0,param_3,param_5,param_4,param_6,lVar1,&param_7,8,&param_8,4,0);
  return;
}



===== WPP_RECORDER_SF_SssD @ 1c0004b5c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_SssD
               (undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,wchar_t *param_6,char *param_7,char *param_8,undefined1 param_9)

{
  wchar_t *pwVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  char *pcVar7;
  char *pcVar8;
  
  lVar4 = -1;
  lVar3 = 5;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
    if (param_8 == (char *)0x0) {
      lVar6 = 5;
    }
    else {
      lVar5 = -1;
      do {
        lVar6 = lVar5;
        lVar5 = lVar6 + 1;
      } while (param_8[lVar5] != '\0');
      lVar6 = lVar6 + 2;
    }
    pcVar8 = param_8;
    if (param_8 == (char *)0x0) {
      pcVar8 = "NULL";
    }
    if (param_7 == (char *)0x0) {
      lVar5 = 5;
    }
    else {
      lVar2 = -1;
      do {
        lVar5 = lVar2;
        lVar2 = lVar5 + 1;
      } while (param_7[lVar2] != '\0');
      lVar5 = lVar5 + 2;
    }
    pcVar7 = param_7;
    if (param_7 == (char *)0x0) {
      pcVar7 = "NULL";
    }
    if (param_6 == (wchar_t *)0x0) {
      lVar2 = 10;
    }
    else {
      lVar2 = -1;
      do {
        lVar2 = lVar2 + 1;
      } while (param_6[lVar2] != L'\0');
      lVar2 = lVar2 * 2 + 2;
    }
    pwVar1 = param_6;
    if (param_6 == (wchar_t *)0x0) {
      pwVar1 = L"NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_727a4a35c5ba3b497e5d1810384d3270_Traceguids,param_4,pwVar1,lVar2,pcVar7,lVar5,
               pcVar8,lVar6,&param_9,4,0);
  }
  if (param_8 == (char *)0x0) {
    lVar6 = 5;
  }
  else {
    lVar5 = -1;
    do {
      lVar6 = lVar5;
      lVar5 = lVar6 + 1;
    } while (param_8[lVar5] != '\0');
    lVar6 = lVar6 + 2;
  }
  if (param_8 == (char *)0x0) {
    param_8 = "NULL";
  }
  if (param_7 != (char *)0x0) {
    lVar5 = -1;
    do {
      lVar3 = lVar5;
      lVar5 = lVar3 + 1;
    } while (param_7[lVar5] != '\0');
    lVar3 = lVar3 + 2;
  }
  if (param_7 == (char *)0x0) {
    param_7 = "NULL";
  }
  if (param_6 == (wchar_t *)0x0) {
    lVar4 = 10;
  }
  else {
    do {
      lVar4 = lVar4 + 1;
    } while (param_6[lVar4] != L'\0');
    lVar4 = lVar4 * 2 + 2;
  }
  if (param_6 == (wchar_t *)0x0) {
    param_6 = L"NULL";
  }
  WppAutoLogTrace(param_1,param_2,10,&WPP_727a4a35c5ba3b497e5d1810384d3270_Traceguids,param_4,
                  param_6,lVar4,param_7,lVar3,param_8,lVar6,&param_9,4,0);
  return;
}



===== PlExtpNativeMethodEvalFinalCompletion @ 1c0004db0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PlExtpNativeMethodEvalFinalCompletion(longlong param_1)

{
  (**(code **)(param_1 + 0xb8))(*(undefined8 *)(param_1 + 0xc0));
  IoReleaseRemoveLockEx(*(longlong *)(param_1 + 0x20) + 0x78,0x78466550,0x20);
  return;
}



===== PlExtpCreateChildDeviceRequests @ 1c0004df8 =====

undefined8 PlExtpCreateChildDeviceRequests(longlong param_1)

{
  char cVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  longlong lVar4;
  longlong lVar5;
  uint uVar6;
  undefined8 uVar7;
  undefined8 *puVar8;
  longlong lVar9;
  longlong local_res8;
  longlong local_res10;
  
  puVar2 = *(undefined8 **)(param_1 + 0x88);
  local_res8 = 0;
  local_res10 = 0;
  cVar1 = *(char *)(puVar2 + 2);
  puVar3 = (undefined8 *)*puVar2;
  lVar4 = puVar2[3];
  do {
    if (puVar3 == puVar2) {
      return 0;
    }
    if (cVar1 == '\0') {
      lVar5 = puVar3[4];
      uVar7 = 1;
      lVar9 = lVar5;
      uVar6 = PlExtpFindDeviceByNameOrHandle(1,0,lVar5,&local_res8);
      if (uVar6 == 0) goto LAB_1c0004efa;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qD(uVar7,2,lVar9,0x20,&WPP_a31fe4b5b02930fb8029abd8f99eeaaf_Traceguids,
                           (char)lVar5,(char)uVar6);
      }
    }
    else {
      puVar8 = puVar3;
      uVar6 = PlExtpCreateDevice(lVar4,(longlong)puVar3,&local_res8);
      if ((int)uVar6 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_SD(PlExtLogHandle,puVar8,9,0x1f,
                             &WPP_a31fe4b5b02930fb8029abd8f99eeaaf_Traceguids,(wchar_t *)puVar3[8],
                             (char)uVar6);
        }
      }
      else {
LAB_1c0004efa:
        uVar6 = PlExtpCreateBuildDestroyDeviceRequest
                          (local_res8,puVar3,cVar1 != '\0',param_1,&local_res10);
        if (-1 < (int)uVar6) {
          uVar6 = 0x103;
        }
      }
    }
    *(uint *)(puVar3 + 3) = uVar6;
    puVar3 = (undefined8 *)*puVar3;
  } while( true );
}



===== PlExtProcessPoFxRequest @ 1c0004f60 =====

int PlExtProcessPoFxRequest(int *param_1)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  
  if (*param_1 == 0) {
    piVar1 = *(int **)(param_1 + 6);
    if (*piVar1 == 7) {
      iVar3 = PlExtpPepAcpiNotifyHandler(*(longlong *)(param_1 + 2),(longlong *)(piVar1 + 2));
      return iVar3;
    }
    if (*piVar1 == 8) {
      iVar3 = PlExtpProcessControlMethodCompletion((longlong)(piVar1 + 2));
      return iVar3;
    }
  }
  else if (((*param_1 == 1) && (param_1[4] == 1)) && (cVar2 = KeGetCurrentIrql(), cVar2 == '\0')) {
    iVar3 = PlExtpProcessConvertToBiosResources(*(int **)(param_1 + 6));
    return iVar3;
  }
  return -0x3fffff45;
}



===== WPP_RECORDER_SF_DDSq @ 1c0004fd4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_DDSq(undefined8 param_1)

{
  longlong lVar1;
  wchar_t *pwVar2;
  longlong lVar3;
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  wchar_t *in_stack_00000040;
  undefined1 uStack0000000000000048;
  
  lVar3 = -1;
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0) {
    if (in_stack_00000040 == (wchar_t *)0x0) {
      lVar1 = 10;
    }
    else {
      lVar1 = -1;
      do {
        lVar1 = lVar1 + 1;
      } while (in_stack_00000040[lVar1] != L'\0');
      lVar1 = lVar1 * 2 + 2;
    }
    pwVar2 = in_stack_00000040;
    if (in_stack_00000040 == (wchar_t *)0x0) {
      pwVar2 = L"NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_cf4f8fa19d3932c70975ae2eca242000_Traceguids,10,&uStack0000000000000030,4,
               &uStack0000000000000038,4,pwVar2,lVar1,&uStack0000000000000048,8,0);
  }
  if (in_stack_00000040 == (wchar_t *)0x0) {
    lVar3 = 10;
  }
  else {
    do {
      lVar3 = lVar3 + 1;
    } while (in_stack_00000040[lVar3] != L'\0');
    lVar3 = lVar3 * 2 + 2;
  }
  if (in_stack_00000040 == (wchar_t *)0x0) {
    in_stack_00000040 = L"NULL";
  }
  WppAutoLogTrace(param_1,0,7,&WPP_cf4f8fa19d3932c70975ae2eca242000_Traceguids,10,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,in_stack_00000040,lVar3,
                  &uStack0000000000000048,8,0);
  return;
}



===== PlExtRequestWorker @ 1c0005170 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PlExtRequestWorker(undefined8 param_1)

{
  longlong lVar1;
  undefined1 local_res10 [8];
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x1d,
                     &WPP_014e28a2725035dd75100948d63f8491_Traceguids);
  }
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,
                     PTR__WDF_PLEXT_REQUEST_WORK_ITEM_CONTEXT_TYPE_INFO_1c00161b8);
  local_res10[0] = ExAcquireSpinLockExclusive(&PlExtRequestListLock);
  PlExtProcessReadyList(local_res10);
  *(undefined1 *)(lVar1 + 8) = 0;
  ExReleaseSpinLockExclusive(&PlExtRequestListLock,local_res10[0]);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x1e,
                     &WPP_014e28a2725035dd75100948d63f8491_Traceguids);
  }
  return;
}



===== PlExtpMoveRequestToTargetQueue @ 1c0005270 =====

void PlExtpMoveRequestToTargetQueue(longlong param_1,longlong *param_2)

{
  longlong *plVar1;
  longlong *plVar2;
  code *pcVar3;
  
  plVar1 = (longlong *)*param_2;
  if (plVar1 != param_2) {
    if (((longlong *)plVar1[1] != param_2) ||
       (plVar2 = (longlong *)param_2[1], (longlong *)*plVar2 != param_2)) goto LAB_1c00052af;
    *plVar2 = (longlong)plVar1;
    plVar1[1] = (longlong)plVar2;
  }
  plVar1 = *(longlong **)(param_1 + 8);
  if (*plVar1 == param_1) {
    *param_2 = param_1;
    param_2[1] = (longlong)plVar1;
    *plVar1 = (longlong)param_2;
    *(longlong **)(param_1 + 8) = param_2;
    return;
  }
LAB_1c00052af:
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  pcVar3 = (code *)swi(3);
  (*pcVar3)();
  return;
}



===== RtlStringCbLengthA @ 1c00052bc =====

void RtlStringCbLengthA(char *param_1,ulonglong param_2,ulonglong *param_3)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  
  uVar3 = 0;
  if ((param_1 == (char *)0x0) || (uVar2 = param_2, 0x7fffffff < param_2)) {
    uVar1 = 0xc000000d;
  }
  else {
    for (; (uVar2 != 0 && (*param_1 != '\0')); param_1 = param_1 + 1) {
      uVar2 = uVar2 - 1;
    }
    uVar1 = ~-(uint)(uVar2 != 0) & 0xc000000d;
    uVar3 = -(ulonglong)(uVar2 != 0) & param_2 - uVar2;
  }
  if (param_3 != (ulonglong *)0x0) {
    uVar2 = 0;
    if (-1 < (int)uVar1) {
      uVar2 = uVar3;
    }
    *param_3 = uVar2;
  }
  return;
}



===== entry @ 1c0005320 =====

void entry(_WDF_BIND_INFO *param_1,undefined8 param_2)

{
  __security_init_cookie();
  FxDriverEntryWorker(param_1,param_2);
  return;
}



===== FxDriverEntryWorker @ 1c0005354 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FxDriverEntryWorker(_WDF_BIND_INFO *param_1,undefined8 param_2)

{
  int iVar1;
  _WDF_BIND_INFO *p_Var2;
  
  if (param_1 == (_WDF_BIND_INFO *)0x0) {
    iVar1 = DriverEntry((undefined8 ****)0x0,param_2);
  }
  else {
    _DAT_1c0016530 = 0x2080000;
    _DAT_1c0016538 = &DAT_1c0016300;
    RtlCopyUnicodeString(&DAT_1c0016530);
    p_Var2 = param_1;
    iVar1 = WdfVersionBind(param_1,&DAT_1c0016530,&WdfBindInfo,&WdfDriverGlobals);
    if (-1 < iVar1) {
      iVar1 = FxStubBindClasses(p_Var2);
      if ((-1 < iVar1) && (iVar1 = FxStubInitTypes(), -1 < iVar1)) {
        iVar1 = DriverEntry((undefined8 ****)param_1,param_2);
        if (-1 < iVar1) {
          if (*(char *)(WdfDriverGlobals + 0x30) != '\0') {
            if (*(longlong *)(param_1 + 0x68) != 0) {
              DAT_1c0016508 = *(longlong *)(param_1 + 0x68);
            }
            *(code **)(param_1 + 0x68) = FxStubDriverUnload;
          }
          return 0;
        }
        DbgPrintEx(0x4d,0,"DriverEntry failed 0x%x for driver %wZ\n",iVar1,&DAT_1c0016530);
        FxStubDriverEntryFailure();
      }
      FxStubDriverUnloadCommon();
    }
  }
  return iVar1;
}



===== PlExtpBuildDestroyFinalCompletion @ 1c0005480 =====

void PlExtpBuildDestroyFinalCompletion(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = *(int *)(param_1 + 0x14);
  *(int *)(*(longlong *)(param_1 + 0x88) + 0x18) = (int)param_2;
  if (iVar1 == 0) {
    bVar2 = *(char *)(param_1 + 0xb0) == '\0';
    if (bVar2) {
      *(undefined8 *)(*(longlong *)(param_1 + 0x88) + 0x20) =
           *(undefined8 *)(*(longlong *)(param_1 + 0x20) + 0x20);
    }
    else {
      *(undefined8 *)(*(longlong *)(param_1 + 0x88) + 0x20) = 0;
    }
    if (*(longlong *)(param_1 + 0xa8) != 0) {
      param_2 = 0x78466550;
      ExFreePoolWithTag();
    }
    if (*(longlong *)(param_1 + 0x98) != 0) {
      param_2 = 0x78466550;
      ExFreePoolWithTag();
    }
    if (*(longlong *)(param_1 + 0xa8) != 0) {
      param_2 = 0x78466550;
      ExFreePoolWithTag();
    }
    if (bVar2) {
      return;
    }
  }
  PlExtpDeleteDevice(*(longlong **)(param_1 + 0x20),param_2,param_3);
  return;
}



===== PlExtpDeleteDevice @ 1c0005548 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PlExtpDeleteDevice(longlong *param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  undefined *in_stack_ffffffffffffffd8;
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      param_3 = 1;
      in_stack_ffffffffffffffd8 = &WPP_a31fe4b5b02930fb8029abd8f99eeaaf_Traceguids;
      param_2 = CONCAT71((int7)((ulonglong)param_2 >> 8),5);
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x12,
                       &WPP_a31fe4b5b02930fb8029abd8f99eeaaf_Traceguids);
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_Sq(param_1[0x13],param_2,param_3,0x13,in_stack_ffffffffffffffd8,
                         (wchar_t *)param_1[3],(char)param_1[4]);
    }
  }
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,PlExtAcpiDeviceListLock,0);
  lVar1 = *param_1;
  if ((*(longlong **)(lVar1 + 8) != param_1) ||
     (plVar2 = (longlong *)param_1[1], (longlong *)*plVar2 != param_1)) {
    pcVar3 = (code *)swi(0x29);
    (*pcVar3)(3);
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  *plVar2 = lVar1;
  *(longlong **)(lVar1 + 8) = plVar2;
  (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,PlExtAcpiDeviceListLock);
  if (param_1[3] != 0) {
    ExFreePoolWithTag(param_1[3],0x78466550);
    param_1[3] = 0;
  }
  if (param_1[0xd] != 0) {
    ExFreePoolWithTag(param_1[0xd],0x78466550);
    param_1[0xd] = 0;
  }
  if (param_1[0x13] != PlExtLogHandle) {
    imp_WppRecorderLogDelete(WPP_GLOBAL_Control);
  }
  (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,param_1[4]);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x14,
                     &WPP_a31fe4b5b02930fb8029abd8f99eeaaf_Traceguids);
  }
  return;
}



===== WPP_RECORDER_SF_DSq @ 1c0005704 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_DSq(undefined8 param_1)

{
  longlong lVar1;
  wchar_t *pwVar2;
  longlong lVar3;
  longlong lVar4;
  undefined1 uStack0000000000000030;
  wchar_t *in_stack_00000038;
  undefined1 uStack0000000000000040;
  
  lVar4 = -1;
  lVar3 = 10;
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0) {
    if (in_stack_00000038 == (wchar_t *)0x0) {
      lVar1 = 10;
    }
    else {
      lVar1 = -1;
      do {
        lVar1 = lVar1 + 1;
      } while (in_stack_00000038[lVar1] != L'\0');
      lVar1 = lVar1 * 2 + 2;
    }
    pwVar2 = in_stack_00000038;
    if (in_stack_00000038 == (wchar_t *)0x0) {
      pwVar2 = L"NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_cf4f8fa19d3932c70975ae2eca242000_Traceguids,0xb,&uStack0000000000000030,4,pwVar2
               ,lVar1,&uStack0000000000000040,8,0);
  }
  if (in_stack_00000038 != (wchar_t *)0x0) {
    do {
      lVar4 = lVar4 + 1;
    } while (in_stack_00000038[lVar4] != L'\0');
    lVar3 = lVar4 * 2 + 2;
  }
  if (in_stack_00000038 == (wchar_t *)0x0) {
    in_stack_00000038 = L"NULL";
  }
  WppAutoLogTrace(param_1,0,7,&WPP_cf4f8fa19d3932c70975ae2eca242000_Traceguids,0xb,
                  &uStack0000000000000030,4,in_stack_00000038,lVar3,&uStack0000000000000040,8,0);
  return;
}



===== WPP_RECORDER_SF_sD @ 1c0005878 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sD(undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
                       undefined8 param_5,char *param_6,undefined1 param_7)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  
  if ((*(uint *)(WPP_GLOBAL_Control +
                ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + (ulonglong)(param_3 >> 0x10) * 0x14) * 4 +
                0x2c) >> (param_3 - 1 & 0x1f) & 1) != 0) {
    if (param_6 == (char *)0x0) {
      lVar2 = 5;
    }
    else {
      lVar1 = -1;
      do {
        lVar2 = lVar1;
        lVar1 = lVar2 + 1;
      } while (param_6[lVar1] != '\0');
      lVar2 = lVar2 + 2;
    }
    pcVar3 = param_6;
    if (param_6 == (char *)0x0) {
      pcVar3 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + (ulonglong)(param_3 >> 0x10) * 0x50 + 0x18),0x2b
               ,param_5,param_4,pcVar3,lVar2,&param_7,4,0);
  }
  lVar2 = -1;
  if (param_6 == (char *)0x0) {
    lVar1 = 5;
  }
  else {
    do {
      lVar1 = lVar2;
      lVar2 = lVar1 + 1;
    } while (param_6[lVar2] != '\0');
    lVar1 = lVar1 + 2;
  }
  if (param_6 == (char *)0x0) {
    param_6 = "NULL";
  }
  WppAutoLogTrace(param_1,0,param_3,param_5,param_4,param_6,lVar1,&param_7,4,0);
  return;
}



===== RhpCreateRequestContext @ 1c00059f4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int RhpCreateRequestContext(undefined8 param_1,undefined8 param_2,longlong *param_3)

{
  int iVar1;
  longlong lVar2;
  longlong local_res18;
  undefined4 local_48;
  undefined4 local_44;
  code *local_40;
  undefined8 local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined *local_18;
  
  local_res18 = 0;
  *param_3 = 0;
  local_44 = 0;
  local_38 = 0;
  local_30 = 1;
  local_2c = 1;
  local_18 = PTR__WDF_RH_OPREGION_REQUEST_TYPE_INFO_1c0016138;
  local_40 = RhpEvtCleanupOpRegionRequestCallback;
  local_28 = 0;
  uStack_20 = 0;
  local_48 = 0x38;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x7b8))(WdfDriverGlobals,&local_48,0,&local_res18);
  if (-1 < iVar1) {
    lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,local_res18,PTR__WDF_RH_OPREGION_REQUEST_TYPE_INFO_1c0016138
                      );
    memset((void *)(lVar2 + 0x10),0,0xd0);
    *(longlong *)(lVar2 + 8) = lVar2;
    *(longlong *)lVar2 = lVar2;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x600))
                      (WdfDriverGlobals,0,0x200,0x48736552,0x104,lVar2 + 0x18,0);
    if ((-1 < iVar1) &&
       (iVar1 = (**(code **)(WdfFunctions_01015 + 0x600))
                          (WdfDriverGlobals,0,0x200,0x48736552,0x80,lVar2 + 0x20,0), -1 < iVar1)) {
      *param_3 = lVar2;
      return iVar1;
    }
  }
  if (local_res18 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
  return iVar1;
}



===== PlExtpRemoveRequestFromParentQueue @ 1c0005b98 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

bool PlExtpRemoveRequestFromParentQueue(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  longlong *plVar4;
  code *pcVar5;
  undefined1 uVar6;
  
  lVar2 = *(longlong *)(param_1 + 0x48);
  plVar1 = (longlong *)(param_1 + 0x50);
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x28));
  lVar3 = *plVar1;
  if ((*(longlong **)(lVar3 + 8) == plVar1) &&
     (plVar4 = *(longlong **)(param_1 + 0x58), (longlong *)*plVar4 == plVar1)) {
    *plVar4 = lVar3;
    *(longlong **)(lVar3 + 8) = plVar4;
    plVar4 = *(longlong **)(lVar2 + 0x60);
    (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x28));
    *(longlong **)(param_1 + 0x58) = plVar1;
    *plVar1 = (longlong)plVar1;
    PlExtpDereferenceRequest(lVar2);
    return plVar4 == (longlong *)(lVar2 + 0x60);
  }
  pcVar5 = (code *)swi(0x29);
  (*pcVar5)(3);
  pcVar5 = (code *)swi(3);
  uVar6 = (*pcVar5)();
  return (bool)uVar6;
}



===== RhGpioOperationRegionHandler @ 1c0005c40 =====

void RhGpioOperationRegionHandler(longlong **param_1,longlong **param_2,longlong **param_3)

{
  RhpCommonOperationRegionHandler(8,param_1,param_2,param_3);
  return;
}



===== WPP_RECORDER_SF_sDDDqD @ 1c0005c7c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDDDqD
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,undefined8 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9,undefined1 param_10,undefined1 param_11)

{
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,param_4,"RhpGpioRegionSpaceAccess",
               0x19,&param_7,4,&param_8,4,&param_9,4,&param_10,8,&param_11,4,0);
  }
  WppAutoLogTrace(param_1,0,9,&WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,param_4,
                  "RhpGpioRegionSpaceAccess",0x19,&param_7,4,&param_8,4,&param_9,4,&param_10,8,
                  &param_11,4,0);
  return;
}



===== PlExtpVerifyPoFxRequestHandler @ 1c0005de0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong PlExtpVerifyPoFxRequestHandler(int *param_1,longlong param_2,longlong param_3)

{
  int iVar1;
  ulonglong uVar2;
  int *piVar3;
  uint uVar4;
  longlong lVar5;
  int *piVar6;
  int iVar7;
  
  piVar6 = (int *)0x0;
  piVar3 = param_1;
  if (*param_1 == 0) {
    piVar6 = param_1 + 4;
    uVar4 = *piVar6 - 5;
    uVar2 = (ulonglong)uVar4;
    if ((uVar4 == 0) || (uVar4 == 1)) {
      PlExtpVerifyBoolean((byte)*(undefined4 *)(param_2 + 0x38) & 1,uVar2,
                          *(longlong *)(param_2 + 0x98));
      param_3 = *(longlong *)(param_2 + 0x98);
      PlExtpVerifyBoolean((byte)(*(uint *)(param_2 + 0x38) >> 1) & 1,uVar2,param_3);
      PlExtpVerifyNotNull(*(longlong *)(param_2 + 0x40),*(longlong *)(param_2 + 0x98));
      piVar3 = *(int **)(param_2 + 0x48);
      PlExtpVerifyNotNull((longlong)piVar3,*(longlong *)(param_2 + 0x98));
    }
    PlExtpVerifyIrqlLessThanOrEqual(piVar3,*(longlong *)(param_2 + 0x98),param_3);
  }
  if (PlExtPoFxRequestHandler == (code *)0x0) {
    uVar2 = 0xc0000001;
  }
  else {
    piVar3 = param_1;
    uVar4 = (*PlExtPoFxRequestHandler)();
    uVar2 = (ulonglong)uVar4;
  }
  if (*param_1 == 0) {
    PlExtpVerifyIrqlLessThanOrEqual(piVar3,*(longlong *)(param_2 + 0x98),param_3);
    iVar1 = *piVar6;
    iVar7 = (int)uVar2;
    if (iVar1 == 1) {
      if ((-1 < iVar7) && ((char)piVar6[8] != '\0')) {
        PlExtpVerifyStatusSuccessStrict(iVar7,*(longlong *)(param_2 + 0x98));
        PlExtpVerifyNotNull(*(longlong *)(piVar6 + 10),*(longlong *)(param_2 + 0x98));
      }
    }
    else {
      if (iVar1 != 2) {
        if (iVar1 == 3) {
          if (iVar7 < 0) {
            return uVar2;
          }
          if ((char)piVar6[8] == '\0') {
            return uVar2;
          }
          PlExtpVerifyStatusSuccessStrict(iVar7,*(longlong *)(param_2 + 0x98));
          PlExtpVerifyNotNull(*(longlong *)(piVar6 + 0xc),*(longlong *)(param_2 + 0x98));
          uVar2 = PlExtpVerifyNotNull(*(longlong *)(piVar6 + 0xe),*(longlong *)(param_2 + 0x98));
          return uVar2 & 0xffffffff;
        }
        if (iVar1 != 4) {
          return uVar2;
        }
      }
      lVar5 = *(longlong *)(param_2 + 0x98);
      PlExtpVerifyStatusSuccessStrict(iVar7,lVar5);
      PlExtpVerifyBoolean((char)piVar6[8],lVar5,*(longlong *)(param_2 + 0x98));
    }
  }
  return uVar2;
}



===== RhpValidateGpioRegionSpaceAccess @ 1c0005f50 =====

undefined8 RhpValidateGpioRegionSpaceAccess(longlong param_1,undefined8 param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined8 in_stack_ffffffffffffffd8;
  undefined8 in_stack_ffffffffffffffe0;
  
  uVar1 = *(int *)(param_1 + 0x20) + 7U >> 3;
  uVar5 = (ulonglong)*(uint *)(param_1 + 0x18) * 8;
  puVar3 = param_3;
  if (uVar5 < 0x100000000) {
    uVar4 = (uint)uVar5;
    uVar2 = *(int *)(param_1 + 0x1c) + uVar4;
    puVar3 = (uint *)(ulonglong)uVar2;
    if (uVar4 <= uVar2) {
      if (*(uint *)(param_1 + 0x30) == uVar2) {
        if (uVar1 <= *param_3) {
          return 0;
        }
        if (*(char *)(param_1 + 8) == '\0') {
          *param_3 = uVar1;
          return 0xc0000023;
        }
      }
      else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sll(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),(ulonglong)uVar1,puVar3,0x29,
                            in_stack_ffffffffffffffd8,in_stack_ffffffffffffffe0,
                            (char)*(uint *)(param_1 + 0x30),(char)uVar2);
      }
      return 0xc0000001;
    }
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_sll(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),(ulonglong)uVar1,puVar3,0x28,
                        in_stack_ffffffffffffffd8,in_stack_ffffffffffffffe0,
                        (char)*(uint *)(param_1 + 0x18),(char)*(undefined4 *)(param_1 + 0x1c));
  }
  return 0xc00000bb;
}



===== __report_gsfailure @ 1c0006030 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== RESOURCE_HUB_STRING_PRINTF @ 1c0006040 =====

undefined8
RESOURCE_HUB_STRING_PRINTF(wchar_t *param_1,ulonglong param_2,wchar_t *param_3,undefined8 param_4)

{
  ulonglong _Count;
  int iVar1;
  undefined8 uVar2;
  undefined8 local_res20;
  
  uVar2 = 0;
  if ((param_2 >> 1) - 1 < 0x7fffffff) {
    _Count = (param_2 >> 1) - 1;
    local_res20 = param_4;
    iVar1 = _vsnwprintf(param_1,_Count,param_3,(va_list)&local_res20);
    if ((iVar1 < 0) || (_Count < (ulonglong)(longlong)iVar1)) {
      param_1[_Count] = L'\0';
      uVar2 = 0x80000005;
    }
    else if ((longlong)iVar1 == _Count) {
      param_1[_Count] = L'\0';
    }
  }
  else {
    uVar2 = 0xc000000d;
  }
  return uVar2;
}



===== WPP_RECORDER_SF_s @ 1c00060b4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_s(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                      undefined8 param_5,char *param_6)

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
               ,lVar3,0);
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
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,param_6,lVar2,0);
  return;
}



===== WPP_RECORDER_SF_sS @ 1c000620c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sS(undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
                       undefined8 param_5,char *param_6,wchar_t *param_7)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  char *pcVar5;
  wchar_t *pwVar6;
  
  lVar2 = 10;
  if ((*(uint *)(WPP_GLOBAL_Control +
                ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + (ulonglong)(param_3 >> 0x10) * 0x14) * 4 +
                0x2c) >> (param_3 - 1 & 0x1f) & 1) != 0) {
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
    pwVar6 = param_7;
    if (param_7 == (wchar_t *)0x0) {
      pwVar6 = L"NULL";
    }
    if (param_6 == (char *)0x0) {
      lVar4 = 5;
    }
    else {
      lVar3 = -1;
      do {
        lVar4 = lVar3;
        lVar3 = lVar4 + 1;
      } while (param_6[lVar3] != '\0');
      lVar4 = lVar4 + 2;
    }
    pcVar5 = param_6;
    if (param_6 == (char *)0x0) {
      pcVar5 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + (ulonglong)(param_3 >> 0x10) * 0x50 + 0x18),0x2b
               ,param_5,param_4,pcVar5,lVar4,pwVar6,lVar1,0);
  }
  if (param_7 != (wchar_t *)0x0) {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (param_7[lVar2] != L'\0');
    lVar2 = lVar2 * 2 + 2;
  }
  if (param_7 == (wchar_t *)0x0) {
    param_7 = L"NULL";
  }
  lVar1 = -1;
  if (param_6 == (char *)0x0) {
    lVar4 = 5;
  }
  else {
    do {
      lVar4 = lVar1;
      lVar1 = lVar4 + 1;
    } while (param_6[lVar1] != '\0');
    lVar4 = lVar4 + 2;
  }
  if (param_6 == (char *)0x0) {
    param_6 = "NULL";
  }
  WppAutoLogTrace(param_1,0,param_3,param_5,param_4,param_6,lVar4,param_7,lVar2,0);
  return;
}



===== WPP_RECORDER_SF_sSD @ 1c00063dc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sSD(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                        undefined8 param_5,char *param_6,wchar_t *param_7,undefined1 param_8)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  longlong lVar4;
  longlong lVar5;
  wchar_t *pwVar6;
  ulonglong uVar7;
  
  uVar7 = (ulonglong)(param_3 >> 0x10);
  lVar2 = 10;
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar7 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar7 * 0x50 + 0x29])) {
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
    pwVar6 = param_7;
    if (param_7 == (wchar_t *)0x0) {
      pwVar6 = L"NULL";
    }
    if (param_6 == (char *)0x0) {
      lVar5 = 5;
    }
    else {
      lVar4 = -1;
      do {
        lVar5 = lVar4;
        lVar4 = lVar5 + 1;
      } while (param_6[lVar4] != '\0');
      lVar5 = lVar5 + 2;
    }
    pcVar3 = param_6;
    if (param_6 == (char *)0x0) {
      pcVar3 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar7 * 0x50 + 0x18),0x2b,param_5,param_4,pcVar3
               ,lVar5,pwVar6,lVar1,&param_8,4,0);
  }
  if (param_7 != (wchar_t *)0x0) {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (param_7[lVar2] != L'\0');
    lVar2 = lVar2 * 2 + 2;
  }
  if (param_7 == (wchar_t *)0x0) {
    param_7 = L"NULL";
  }
  lVar1 = -1;
  if (param_6 == (char *)0x0) {
    lVar5 = 5;
  }
  else {
    do {
      lVar5 = lVar1;
      lVar1 = lVar5 + 1;
    } while (param_6[lVar1] != '\0');
    lVar5 = lVar5 + 2;
  }
  if (param_6 == (char *)0x0) {
    param_6 = "NULL";
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,param_6,lVar5,param_7,lVar2,&param_8,4,0);
  return;
}



===== WPP_RECORDER_SF_sSSqSq @ 1c00065f4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sSSqSq(undefined8 param_1)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  wchar_t *pwVar4;
  longlong lVar5;
  longlong lVar6;
  wchar_t *pwVar7;
  wchar_t *pwVar8;
  wchar_t *in_stack_00000038;
  wchar_t *in_stack_00000040;
  undefined1 uStack0000000000000048;
  wchar_t *in_stack_00000050;
  undefined1 uStack0000000000000058;
  
  lVar6 = -1;
  lVar5 = 10;
  if ((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0') {
    if (in_stack_00000050 == (wchar_t *)0x0) {
      lVar1 = 10;
    }
    else {
      lVar1 = -1;
      do {
        lVar1 = lVar1 + 1;
      } while (in_stack_00000050[lVar1] != L'\0');
      lVar1 = lVar1 * 2 + 2;
    }
    pwVar8 = in_stack_00000050;
    if (in_stack_00000050 == (wchar_t *)0x0) {
      pwVar8 = L"NULL";
    }
    if (in_stack_00000040 == (wchar_t *)0x0) {
      lVar2 = 10;
    }
    else {
      lVar2 = -1;
      do {
        lVar2 = lVar2 + 1;
      } while (in_stack_00000040[lVar2] != L'\0');
      lVar2 = lVar2 * 2 + 2;
    }
    pwVar7 = in_stack_00000040;
    if (in_stack_00000040 == (wchar_t *)0x0) {
      pwVar7 = L"NULL";
    }
    if (in_stack_00000038 == (wchar_t *)0x0) {
      lVar3 = 10;
    }
    else {
      lVar3 = -1;
      do {
        lVar3 = lVar3 + 1;
      } while (in_stack_00000038[lVar3] != L'\0');
      lVar3 = lVar3 * 2 + 2;
    }
    pwVar4 = in_stack_00000038;
    if (in_stack_00000038 == (wchar_t *)0x0) {
      pwVar4 = L"NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_5a306037547032d76a1bb21b8aa3fd30_Traceguids,0xd,"RhpAddProviderTarget",0x15,
               pwVar4,lVar3,pwVar7,lVar2,&uStack0000000000000048,8,pwVar8,lVar1,
               &uStack0000000000000058,8,0);
  }
  if (in_stack_00000050 == (wchar_t *)0x0) {
    lVar1 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (in_stack_00000050[lVar1] != L'\0');
    lVar1 = lVar1 * 2 + 2;
  }
  if (in_stack_00000050 == (wchar_t *)0x0) {
    in_stack_00000050 = L"NULL";
  }
  if (in_stack_00000040 == (wchar_t *)0x0) {
    lVar2 = 10;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (in_stack_00000040[lVar2] != L'\0');
    lVar2 = lVar2 * 2 + 2;
  }
  if (in_stack_00000040 == (wchar_t *)0x0) {
    in_stack_00000040 = L"NULL";
  }
  if (in_stack_00000038 != (wchar_t *)0x0) {
    do {
      lVar6 = lVar6 + 1;
    } while (in_stack_00000038[lVar6] != L'\0');
    lVar5 = lVar6 * 2 + 2;
  }
  if (in_stack_00000038 == (wchar_t *)0x0) {
    in_stack_00000038 = L"NULL";
  }
  WppAutoLogTrace(param_1,0,8,&WPP_5a306037547032d76a1bb21b8aa3fd30_Traceguids,0xd,
                  "RhpAddProviderTarget",0x15,in_stack_00000038,lVar5,in_stack_00000040,lVar2,
                  &uStack0000000000000048,8,in_stack_00000050,lVar1,&uStack0000000000000058,8,0);
  return;
}



===== WPP_RECORDER_SF_sSq @ 1c0006894 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sSq(undefined8 param_1)

{
  longlong lVar1;
  wchar_t *pwVar2;
  longlong lVar3;
  longlong lVar4;
  wchar_t *in_stack_00000038;
  undefined1 uStack0000000000000040;
  
  lVar4 = -1;
  lVar3 = 10;
  if ((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0') {
    if (in_stack_00000038 == (wchar_t *)0x0) {
      lVar1 = 10;
    }
    else {
      lVar1 = -1;
      do {
        lVar1 = lVar1 + 1;
      } while (in_stack_00000038[lVar1] != L'\0');
      lVar1 = lVar1 * 2 + 2;
    }
    pwVar2 = in_stack_00000038;
    if (in_stack_00000038 == (wchar_t *)0x0) {
      pwVar2 = L"NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_5a306037547032d76a1bb21b8aa3fd30_Traceguids,0x16,"RhpGetControllerNameFromCache"
               ,0x1e,pwVar2,lVar1,&uStack0000000000000040,8,0);
  }
  if (in_stack_00000038 != (wchar_t *)0x0) {
    do {
      lVar4 = lVar4 + 1;
    } while (in_stack_00000038[lVar4] != L'\0');
    lVar3 = lVar4 * 2 + 2;
  }
  if (in_stack_00000038 == (wchar_t *)0x0) {
    in_stack_00000038 = L"NULL";
  }
  WppAutoLogTrace(param_1,0,8,&WPP_5a306037547032d76a1bb21b8aa3fd30_Traceguids,0x16,
                  "RhpGetControllerNameFromCache",0x1e,in_stack_00000038,lVar3,
                  &uStack0000000000000040,8,0);
  return;
}



===== WPP_RECORDER_SF_sSqD @ 1c0006a08 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sSqD(undefined8 param_1)

{
  longlong lVar1;
  wchar_t *pwVar2;
  longlong lVar3;
  longlong lVar4;
  wchar_t *in_stack_00000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  
  lVar4 = -1;
  lVar3 = 10;
  if ((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0') {
    if (in_stack_00000038 == (wchar_t *)0x0) {
      lVar1 = 10;
    }
    else {
      lVar1 = -1;
      do {
        lVar1 = lVar1 + 1;
      } while (in_stack_00000038[lVar1] != L'\0');
      lVar1 = lVar1 * 2 + 2;
    }
    pwVar2 = in_stack_00000038;
    if (in_stack_00000038 == (wchar_t *)0x0) {
      pwVar2 = L"NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_5a306037547032d76a1bb21b8aa3fd30_Traceguids,0x11,"RhpCacheAddConnection",0x16,
               pwVar2,lVar1,&uStack0000000000000040,8,&uStack0000000000000048,4,0);
  }
  if (in_stack_00000038 != (wchar_t *)0x0) {
    do {
      lVar4 = lVar4 + 1;
    } while (in_stack_00000038[lVar4] != L'\0');
    lVar3 = lVar4 * 2 + 2;
  }
  if (in_stack_00000038 == (wchar_t *)0x0) {
    in_stack_00000038 = L"NULL";
  }
  WppAutoLogTrace(param_1,0,8,&WPP_5a306037547032d76a1bb21b8aa3fd30_Traceguids,0x11,
                  "RhpCacheAddConnection",0x16,in_stack_00000038,lVar3,&uStack0000000000000040,8,
                  &uStack0000000000000048,4,0);
  return;
}



===== WPP_RECORDER_SF_sZ @ 1c0006bb0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sZ(undefined8 param_1)

{
  wchar_t wVar1;
  wchar_t *pwVar2;
  wchar_t *pwVar3;
  wchar_t *pwVar4;
  wchar_t *in_stack_00000038;
  
  pwVar3 = L"NULL";
  if (-1 < (char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c)) goto LAB_1c0006c77;
  if (in_stack_00000038 == (wchar_t *)0x0) {
    wVar1 = L'\b';
LAB_1c0006c16:
    pwVar4 = L"NULL";
  }
  else {
    wVar1 = *in_stack_00000038;
    if (*in_stack_00000038 == L'\0') goto LAB_1c0006c16;
    pwVar4 = *(wchar_t **)(in_stack_00000038 + 4);
  }
  pwVar2 = in_stack_00000038;
  if (in_stack_00000038 == (wchar_t *)0x0) {
    pwVar2 = L"\b";
  }
  (*pfnWppTraceMessage)
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
             &WPP_5a306037547032d76a1bb21b8aa3fd30_Traceguids,0xf,"RhpInsertConnection",0x14,pwVar2,
             2,pwVar4,wVar1,0);
LAB_1c0006c77:
  if (in_stack_00000038 == (wchar_t *)0x0) {
    wVar1 = L'\b';
  }
  else {
    wVar1 = *in_stack_00000038;
    if (*in_stack_00000038 != L'\0') {
      pwVar3 = *(wchar_t **)(in_stack_00000038 + 4);
    }
  }
  if (in_stack_00000038 == (wchar_t *)0x0) {
    in_stack_00000038 = L"\b";
  }
  WppAutoLogTrace(param_1,0,8,&WPP_5a306037547032d76a1bb21b8aa3fd30_Traceguids,0xf,
                  "RhpInsertConnection",0x14,in_stack_00000038,2,pwVar3,wVar1,0);
  return;
}



===== WPP_RECORDER_SF_sqSD @ 1c0006d08 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sqSD
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,undefined8 param_6,undefined1 param_7,wchar_t *param_8,
               undefined1 param_9)

{
  longlong lVar1;
  wchar_t *pwVar2;
  wchar_t *pwVar3;
  longlong lVar4;
  longlong lVar5;
  
  pwVar3 = param_8;
  lVar5 = -1;
  lVar4 = 10;
  if ((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0') {
    if (param_8 == (wchar_t *)0x0) {
      lVar1 = 10;
    }
    else {
      lVar1 = -1;
      do {
        lVar1 = lVar1 + 1;
      } while (param_8[lVar1] != L'\0');
      lVar1 = lVar1 * 2 + 2;
    }
    pwVar2 = param_8;
    if (param_8 == (wchar_t *)0x0) {
      pwVar2 = L"NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_5a306037547032d76a1bb21b8aa3fd30_Traceguids,param_4,"RhpConnectProviderDevice",
               0x19,&param_7,8,pwVar2,lVar1,&param_9,4,0);
  }
  if (pwVar3 != (wchar_t *)0x0) {
    do {
      lVar5 = lVar5 + 1;
    } while (pwVar3[lVar5] != L'\0');
    lVar4 = lVar5 * 2 + 2;
  }
  if (pwVar3 == (wchar_t *)0x0) {
    pwVar3 = L"NULL";
  }
  WppAutoLogTrace(param_1,0,8,&WPP_5a306037547032d76a1bb21b8aa3fd30_Traceguids,param_4,
                  "RhpConnectProviderDevice",0x19,&param_7,8,pwVar3,lVar4,&param_9,4,0);
  return;
}



===== WPP_RECORDER_SF_sqddSD @ 1c0006ea8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sqddSD(undefined8 param_1)

{
  longlong lVar1;
  wchar_t *pwVar2;
  longlong lVar3;
  longlong lVar4;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  wchar_t *in_stack_00000050;
  undefined1 uStack0000000000000058;
  
  lVar4 = -1;
  lVar3 = 10;
  if ((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0') {
    if (in_stack_00000050 == (wchar_t *)0x0) {
      lVar1 = 10;
    }
    else {
      lVar1 = -1;
      do {
        lVar1 = lVar1 + 1;
      } while (in_stack_00000050[lVar1] != L'\0');
      lVar1 = lVar1 * 2 + 2;
    }
    pwVar2 = in_stack_00000050;
    if (in_stack_00000050 == (wchar_t *)0x0) {
      pwVar2 = L"NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_5a306037547032d76a1bb21b8aa3fd30_Traceguids,0x15,"RhpConnectProviderDevice",0x19
               ,&uStack0000000000000038,8,&uStack0000000000000040,4,&uStack0000000000000048,4,pwVar2
               ,lVar1,&uStack0000000000000058,4,0);
  }
  if (in_stack_00000050 != (wchar_t *)0x0) {
    do {
      lVar4 = lVar4 + 1;
    } while (in_stack_00000050[lVar4] != L'\0');
    lVar3 = lVar4 * 2 + 2;
  }
  if (in_stack_00000050 == (wchar_t *)0x0) {
    in_stack_00000050 = L"NULL";
  }
  WppAutoLogTrace(param_1,0,8,&WPP_5a306037547032d76a1bb21b8aa3fd30_Traceguids,0x15,
                  "RhpConnectProviderDevice",0x19,&uStack0000000000000038,8,&uStack0000000000000040,
                  4,&uStack0000000000000048,4,in_stack_00000050,lVar3,&uStack0000000000000058,4,0);
  return;
}



===== RhpAcceptDeviceFirmwareLockWorker @ 1c00070a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x0001c00071e4) */

ulonglong RhpAcceptDeviceFirmwareLockWorker(longlong param_1)

{
  longlong lVar1;
  ulonglong uVar2;
  longlong *plVar3;
  longlong lVar4;
  ulonglong uVar5;
  longlong local_res8;
  undefined4 local_res10;
  undefined4 uStackX_14;
  
  local_res8 = 0;
  plVar3 = (longlong *)(*(longlong *)(param_1 + 0x28) + 0xc);
  local_res10 = *(undefined4 *)plVar3;
  uStackX_14 = *(undefined4 *)(*(longlong *)(param_1 + 0x28) + 0x10);
  lVar1 = *plVar3;
  lVar4 = lVar1;
  uVar2 = RhpGetConnectionTarget(*(undefined8 *)(param_1 + 8),lVar1,0x1f0000,&local_res8);
  uVar5 = uVar2 & 0xffffffff;
  if ((int)uVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_siD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar4,9,0xd,
                          &WPP_bd1a3646fa4f350d9a91c6886f68217f_Traceguids,
                          "RhpAcceptDeviceFirmwareLockWorker",(char)lVar1,(char)uVar2);
    }
  }
  else {
    plVar3 = (longlong *)ExAllocatePool2(0x40,0x10,0x48736552);
    if (plVar3 != (longlong *)0x0) {
      *plVar3 = local_res8;
      plVar3[1] = lVar1;
      goto LAB_1c0007208;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),0,10,0xe,
                        &WPP_bd1a3646fa4f350d9a91c6886f68217f_Traceguids,
                        "RhpAcceptDeviceFirmwareLockWorker");
    }
    uVar5 = 0xc000009a;
  }
  if (local_res8 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x670))
              (WdfDriverGlobals,local_res8,0,0x2db,
               "minkernel\\busdrv\\acpi\\reshub\\driver\\sys\\devlock.c");
  }
  plVar3 = (longlong *)0x0;
LAB_1c0007208:
  if (*(code **)(param_1 + 0x30) != (code *)0x0) {
    (**(code **)(param_1 + 0x30))(*(undefined8 *)(param_1 + 0x38),uVar5,plVar3);
  }
  return uVar5;
}



===== RhpAcquireDeviceFirmwareLockHandler @ 1c0007238 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int RhpAcquireDeviceFirmwareLockHandler(undefined8 *param_1)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  char cVar6;
  int iVar7;
  undefined8 *puVar8;
  undefined2 uVar9;
  undefined1 auStackY_b8 [32];
  longlong local_68 [2];
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined *local_28;
  undefined8 local_20;
  longlong lStack_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_b8;
  puVar8 = &local_58;
  local_20 = 0;
  lStack_18 = 0;
  puVar1 = *(undefined8 **)param_1[2];
  local_68[0] = 0;
  local_48 = 0;
  local_28 = PTR__WDF_RH_DEVICE_FIRMWARE_LOCK_REQUEST_CONTEXT_TYPE_INFO_1c00160e8;
  uStack_50 = 0;
  local_58 = 0x38;
  local_38 = 0;
  uStack_30 = 0;
  uStack_40 = 0x100000001;
  iVar7 = (**(code **)(WdfFunctions_01015 + 0x7b8))(WdfDriverGlobals,puVar8,puVar1,local_68);
  if (iVar7 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0007469;
    uVar9 = 0xf;
  }
  else {
    puVar8 = (undefined8 *)
             (**(code **)(WdfFunctions_01015 + 0x650))
                       (WdfDriverGlobals,local_68[0],
                        PTR__WDF_RH_DEVICE_FIRMWARE_LOCK_REQUEST_CONTEXT_TYPE_INFO_1c00160e8);
    uVar5 = param_1[1];
    *puVar8 = *param_1;
    puVar8[1] = uVar5;
    uVar5 = param_1[3];
    puVar8[2] = param_1[2];
    puVar8[3] = uVar5;
    uVar2 = *(undefined4 *)((longlong)param_1 + 0x24);
    uVar3 = *(undefined4 *)(param_1 + 5);
    uVar4 = *(undefined4 *)((longlong)param_1 + 0x2c);
    *(undefined4 *)(puVar8 + 4) = *(undefined4 *)(param_1 + 4);
    *(undefined4 *)((longlong)puVar8 + 0x24) = uVar2;
    *(undefined4 *)(puVar8 + 5) = uVar3;
    *(undefined4 *)((longlong)puVar8 + 0x2c) = uVar4;
    uVar2 = *(undefined4 *)((longlong)param_1 + 0x34);
    uVar3 = *(undefined4 *)(param_1 + 7);
    uVar4 = *(undefined4 *)((longlong)param_1 + 0x3c);
    *(undefined4 *)(puVar8 + 6) = *(undefined4 *)(param_1 + 6);
    *(undefined4 *)((longlong)puVar8 + 0x34) = uVar2;
    *(undefined4 *)(puVar8 + 7) = uVar3;
    *(undefined4 *)((longlong)puVar8 + 0x3c) = uVar4;
    puVar8 = puVar1;
    iVar7 = (**(code **)(WdfFunctions_01015 + 0x5d8))(WdfDriverGlobals,puVar1,local_68[0],0x4180c);
    if (-1 < iVar7) {
      (**(code **)(WdfFunctions_01015 + 0x820))
                (WdfDriverGlobals,local_68[0],RhpEvtDeviceFirmwareLockCompletionRoutine,0);
      lStack_18 = 0;
      local_20 = 0x10;
      if (*(uint *)(param_1 + 3) != 0) {
        lStack_18 = (ulonglong)*(uint *)(param_1 + 3) * -10000;
        local_20 = 0x100000010;
      }
      cVar6 = (**(code **)(WdfFunctions_01015 + 0x7e8))
                        (WdfDriverGlobals,local_68[0],puVar1,&local_20);
      if (cVar6 != '\0') {
        return 0x103;
      }
      iVar7 = (**(code **)(WdfFunctions_01015 + 0x7f0))(WdfDriverGlobals,local_68[0]);
      if (-1 < iVar7) {
        return iVar7;
      }
      goto LAB_1c0007469;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0007469;
    uVar9 = 0x10;
  }
  WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar8,10,uVar9,
                     &WPP_bd1a3646fa4f350d9a91c6886f68217f_Traceguids,
                     "RhpAcquireDeviceFirmwareLockHandler",(char)iVar7);
LAB_1c0007469:
  if (local_68[0] != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
  return iVar7;
}



===== RhpDeviceFirmwareLockHandler @ 1c00074d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong RhpDeviceFirmwareLockHandler(int *param_1)

{
  longlong *plVar1;
  longlong lVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  undefined8 uVar6;
  int iVar7;
  ulonglong uVar8;
  undefined4 extraout_var;
  undefined4 extraout_var_00;
  int *_Dst;
  ulonglong *puVar9;
  undefined8 local_res10;
  ulonglong local_a8;
  code *pcStack_a0;
  undefined8 local_98;
  undefined4 local_90;
  ulonglong local_8c;
  undefined8 uStack_84;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined8 local_70;
  undefined8 local_68;
  undefined *local_60;
  int local_58 [16];
  
  local_res10 = 0;
  iVar7 = *param_1;
  local_8c = local_8c & 0xffffffff00000000;
  local_58[0xc] = 0;
  local_58[0xd] = 0;
  local_58[0xe] = 0;
  local_a8 = (ulonglong)(uint)local_a8;
  local_58[0] = 0;
  local_58[1] = 0;
  local_58[2] = 0;
  local_58[3] = 0;
  local_58[4] = 0;
  local_58[5] = 0;
  local_58[6] = 0;
  local_58[7] = 0;
  local_58[8] = 0;
  local_58[9] = 0;
  local_58[10] = 0;
  local_58[0xb] = 0;
  if (iVar7 == 0) {
    lVar2 = *(longlong *)(param_1 + 10);
    uVar8 = 0xc00000bb;
    if (((lVar2 != 0) && (*(char *)(lVar2 + 1) == -0x7c)) && (*(char *)(lVar2 + 8) == '\x02')) {
      uVar8 = 0x103;
    }
  }
  else if (iVar7 == 1) {
    plVar1 = *(longlong **)(param_1 + 4);
    lVar2 = *plVar1;
    if (lVar2 != 0) {
      (**(code **)(WdfFunctions_01015 + 0x670))
                (WdfDriverGlobals,lVar2,0,0x479,
                 "minkernel\\busdrv\\acpi\\reshub\\driver\\sys\\devlock.c");
    }
    ExFreePoolWithTag(plVar1,0x48736552);
    uVar8 = 0;
  }
  else if (iVar7 == 2) {
    iVar7 = RhpAcquireDeviceFirmwareLockHandler((undefined8 *)param_1);
    uVar8 = CONCAT44(extraout_var_00,iVar7);
  }
  else if (iVar7 == 3) {
    iVar7 = RhpReleaseDeviceFirmwareLockHandler((undefined8 *)param_1);
    uVar8 = CONCAT44(extraout_var,iVar7);
  }
  else {
    uVar8 = 0xc00000bb;
  }
  if (*param_1 != 0) {
    return uVar8;
  }
  if ((int)uVar8 != 0x103) {
    return uVar8;
  }
  local_7c = 0;
  local_68 = 0;
  puVar9 = &local_a8;
  local_60 = PTR__WDF_RH_DEVICE_FIRMWARE_LOCK_WORK_ITEM_CONTEXT_TYPE_INFO_1c00160c0;
  bVar3 = true;
  local_70 = *(undefined8 *)(param_1 + 2);
  pcStack_a0 = RhpEvtDeviceFirmwareLockWorkerWrapper;
  local_8c = 0;
  uStack_84 = 0;
  local_90 = 0x38;
  local_78 = 1;
  local_74 = 1;
  local_a8 = 0x18;
  local_98 = 0;
  iVar7 = (**(code **)(WdfFunctions_01015 + 0xbd8))(WdfDriverGlobals,puVar9,&local_90,&local_res10);
  if (iVar7 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar9,10,0xc,
                         &WPP_bd1a3646fa4f350d9a91c6886f68217f_Traceguids,
                         "RhpDeviceFirmwareLockHandler",(char)iVar7);
    }
  }
  else {
    _Dst = (int *)(**(code **)(WdfFunctions_01015 + 0x650))
                            (WdfDriverGlobals,local_res10,
                             PTR__WDF_RH_DEVICE_FIRMWARE_LOCK_WORK_ITEM_CONTEXT_TYPE_INFO_1c00160c0)
    ;
    bVar3 = false;
    if (_Dst != (int *)0x0) goto LAB_1c00076c2;
  }
  _Dst = local_58;
LAB_1c00076c2:
  memset(_Dst,0,0x40);
  uVar6 = *(undefined8 *)(param_1 + 2);
  *(undefined8 *)_Dst = *(undefined8 *)param_1;
  *(undefined8 *)(_Dst + 2) = uVar6;
  uVar6 = *(undefined8 *)(param_1 + 6);
  *(undefined8 *)(_Dst + 4) = *(undefined8 *)(param_1 + 4);
  *(undefined8 *)(_Dst + 6) = uVar6;
  iVar7 = param_1[9];
  iVar4 = param_1[10];
  iVar5 = param_1[0xb];
  _Dst[8] = param_1[8];
  _Dst[9] = iVar7;
  _Dst[10] = iVar4;
  _Dst[0xb] = iVar5;
  iVar7 = param_1[0xd];
  iVar4 = param_1[0xe];
  iVar5 = param_1[0xf];
  _Dst[0xc] = param_1[0xc];
  _Dst[0xd] = iVar7;
  _Dst[0xe] = iVar4;
  _Dst[0xf] = iVar5;
  if (bVar3) {
    uVar8 = RhpDeviceFirmwareLockWorker(_Dst);
  }
  else {
    (**(code **)(WdfFunctions_01015 + 0xbe0))(WdfDriverGlobals,local_res10);
    uVar8 = 0x103;
  }
  return uVar8;
}



===== RhpEvtDeviceFirmwareLockCompletionRoutine @ 1c0007740 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void RhpEvtDeviceFirmwareLockCompletionRoutine
               (undefined8 param_1,undefined8 param_2,longlong param_3)

{
  undefined4 uVar1;
  int *piVar2;
  code *pcVar3;
  undefined8 uVar4;
  
  piVar2 = (int *)(**(code **)(WdfFunctions_01015 + 0x650))
                            (WdfDriverGlobals,param_1,
                             PTR__WDF_RH_DEVICE_FIRMWARE_LOCK_REQUEST_CONTEXT_TYPE_INFO_1c00160e8);
  if (*piVar2 == 2) {
    pcVar3 = *(code **)(piVar2 + 8);
    uVar4 = *(undefined8 *)(piVar2 + 10);
  }
  else {
    if (*piVar2 != 3) {
      return;
    }
    pcVar3 = *(code **)(piVar2 + 6);
    uVar4 = *(undefined8 *)(piVar2 + 8);
  }
  uVar1 = *(undefined4 *)(param_3 + 8);
  (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,param_1);
  if (pcVar3 != (code *)0x0) {
    (*pcVar3)(uVar4,uVar1);
  }
  return;
}



===== RhpReleaseDeviceFirmwareLockHandler @ 1c00077f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int RhpReleaseDeviceFirmwareLockHandler(undefined8 *param_1)

{
  longlong *plVar1;
  undefined8 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  char cVar7;
  int iVar8;
  undefined8 *puVar9;
  undefined2 uVar10;
  longlong local_res10;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined *local_28;
  
  plVar1 = (longlong *)param_1[2];
  local_res10 = 0;
  puVar9 = &local_58;
  local_48 = 0;
  uStack_40 = 0x100000001;
  local_28 = PTR__WDF_RH_DEVICE_FIRMWARE_LOCK_REQUEST_CONTEXT_TYPE_INFO_1c00160e8;
  uStack_50 = 0;
  local_58 = 0x38;
  local_38 = 0;
  uStack_30 = 0;
  iVar8 = (**(code **)(WdfFunctions_01015 + 0x7b8))(WdfDriverGlobals,puVar9,0,&local_res10);
  if (iVar8 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c00079d2;
    uVar10 = 0x11;
  }
  else {
    puVar9 = (undefined8 *)
             (**(code **)(WdfFunctions_01015 + 0x650))
                       (WdfDriverGlobals,local_res10,
                        PTR__WDF_RH_DEVICE_FIRMWARE_LOCK_REQUEST_CONTEXT_TYPE_INFO_1c00160e8);
    uVar6 = param_1[1];
    *puVar9 = *param_1;
    puVar9[1] = uVar6;
    uVar6 = param_1[3];
    puVar9[2] = param_1[2];
    puVar9[3] = uVar6;
    uVar3 = *(undefined4 *)((longlong)param_1 + 0x24);
    uVar4 = *(undefined4 *)(param_1 + 5);
    uVar5 = *(undefined4 *)((longlong)param_1 + 0x2c);
    *(undefined4 *)(puVar9 + 4) = *(undefined4 *)(param_1 + 4);
    *(undefined4 *)((longlong)puVar9 + 0x24) = uVar3;
    *(undefined4 *)(puVar9 + 5) = uVar4;
    *(undefined4 *)((longlong)puVar9 + 0x2c) = uVar5;
    uVar3 = *(undefined4 *)((longlong)param_1 + 0x34);
    uVar4 = *(undefined4 *)(param_1 + 7);
    uVar5 = *(undefined4 *)((longlong)param_1 + 0x3c);
    *(undefined4 *)(puVar9 + 6) = *(undefined4 *)(param_1 + 6);
    *(undefined4 *)((longlong)puVar9 + 0x34) = uVar3;
    *(undefined4 *)(puVar9 + 7) = uVar4;
    *(undefined4 *)((longlong)puVar9 + 0x3c) = uVar5;
    puVar2 = (undefined8 *)*plVar1;
    puVar9 = puVar2;
    iVar8 = (**(code **)(WdfFunctions_01015 + 0x5d8))
                      (WdfDriverGlobals,puVar2,local_res10,0x41810,0,0,0,0);
    if (-1 < iVar8) {
      (**(code **)(WdfFunctions_01015 + 0x820))
                (WdfDriverGlobals,local_res10,RhpEvtDeviceFirmwareLockCompletionRoutine,0);
      cVar7 = (**(code **)(WdfFunctions_01015 + 0x7e8))(WdfDriverGlobals,local_res10,puVar2,0);
      if (cVar7 != '\0') {
        return 0x103;
      }
      iVar8 = (**(code **)(WdfFunctions_01015 + 0x7f0))(WdfDriverGlobals,local_res10);
      if (-1 < iVar8) {
        return iVar8;
      }
      goto LAB_1c00079d2;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c00079d2;
    uVar10 = 0x12;
  }
  WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar9,10,uVar10,
                     &WPP_bd1a3646fa4f350d9a91c6886f68217f_Traceguids,
                     "RhpReleaseDeviceFirmwareLockHandler",(char)iVar8);
LAB_1c00079d2:
  if (local_res10 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
  return iVar8;
}



===== WPP_RECORDER_SF_sDD @ 1c0007a18 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDD(undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
                        undefined8 param_5,char *param_6,undefined1 param_7,undefined1 param_8)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  
  if ((*(uint *)(WPP_GLOBAL_Control +
                ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + (ulonglong)(param_3 >> 0x10) * 0x14) * 4 +
                0x2c) >> (param_3 - 1 & 0x1f) & 1) != 0) {
    if (param_6 == (char *)0x0) {
      lVar2 = 5;
    }
    else {
      lVar1 = -1;
      do {
        lVar2 = lVar1;
        lVar1 = lVar2 + 1;
      } while (param_6[lVar1] != '\0');
      lVar2 = lVar2 + 2;
    }
    pcVar3 = param_6;
    if (param_6 == (char *)0x0) {
      pcVar3 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + (ulonglong)(param_3 >> 0x10) * 0x50 + 0x18),0x2b
               ,param_5,param_4,pcVar3,lVar2,&param_7,4,&param_8,4,0);
  }
  lVar2 = -1;
  if (param_6 == (char *)0x0) {
    lVar1 = 5;
  }
  else {
    do {
      lVar1 = lVar2;
      lVar2 = lVar1 + 1;
    } while (param_6[lVar2] != '\0');
    lVar1 = lVar1 + 2;
  }
  if (param_6 == (char *)0x0) {
    param_6 = "NULL";
  }
  WppAutoLogTrace(param_1,0,param_3,param_5,param_4,param_6,lVar1,&param_7,4,&param_8,4,0);
  return;
}



===== RhpEvtCleanupOpRegionRequestCallback @ 1c0007bb0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void RhpEvtCleanupOpRegionRequestCallback(undefined8 param_1)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  longlong *plVar4;
  
  plVar4 = (longlong *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_RH_OPREGION_REQUEST_TYPE_INFO_1c0016138);
  ExAcquireFastMutex(&RhOpRegionLock);
  lVar1 = *plVar4;
  if ((*(longlong **)(lVar1 + 8) != plVar4) ||
     (plVar2 = (longlong *)plVar4[1], (longlong *)*plVar2 != plVar4)) {
    pcVar3 = (code *)swi(0x29);
    (*pcVar3)(3);
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  *plVar2 = lVar1;
  *(longlong **)(lVar1 + 8) = plVar2;
  plVar4[1] = (longlong)plVar4;
  *plVar4 = (longlong)plVar4;
  ExReleaseFastMutex(&RhOpRegionLock);
  RhpCleanRequestContext((longlong)plVar4);
  if (plVar4[3] != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
    plVar4[3] = 0;
  }
  if (plVar4[4] != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
    plVar4[4] = 0;
  }
  if (plVar4[6] != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
    plVar4[6] = 0;
  }
  if (plVar4[7] != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
    plVar4[7] = 0;
  }
  return;
}



===== RhpEvtOpRegionRequestCompletionRoutine @ 1c0007cf0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void RhpEvtOpRegionRequestCompletionRoutine(undefined8 param_1)

{
  uint uVar1;
  uint uVar2;
  undefined8 uVar3;
  bool bVar4;
  longlong local_18 [3];
  
  local_18[0] = (**(code **)(WdfFunctions_01015 + 0x650))
                          (WdfDriverGlobals,param_1,PTR__WDF_RH_OPREGION_REQUEST_TYPE_INFO_1c0016138
                          );
  uVar2 = *(uint *)(local_18[0] + 0x28);
  do {
    LOCK();
    uVar1 = *(uint *)(local_18[0] + 0x28);
    bVar4 = uVar2 == uVar1;
    if (bVar4) {
      *(uint *)(local_18[0] + 0x28) = uVar2 | 2;
    }
    else {
      uVar2 = uVar1;
    }
    UNLOCK();
  } while (!bVar4);
  if ((uVar2 & 1) != 0) {
    uVar3 = (**(code **)(WdfFunctions_01015 + 0x570))
                      (WdfDriverGlobals,*(undefined8 *)(local_18[0] + 0x30));
    RhpProcessRegionSpaceAccessAsync(uVar3,local_18);
    if (local_18[0] != 0) {
      RhpCleanAndReleaseRequestContext(local_18[0]);
    }
  }
  return;
}



===== WPP_RECORDER_SF_sDDDDq @ 1c0007d84 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDDDDq(undefined8 param_1)

{
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,0x2d,"RhpGpioRegionSpaceAccess",0x19
               ,&uStack0000000000000038,4,&uStack0000000000000040,4,&uStack0000000000000048,4,
               &uStack0000000000000050,4,&uStack0000000000000058,8,0);
  }
  WppAutoLogTrace(param_1,0,9,&WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,0x2d,
                  "RhpGpioRegionSpaceAccess",0x19,&uStack0000000000000038,4,&uStack0000000000000040,
                  4,&uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,8,0)
  ;
  return;
}



===== WPP_RECORDER_SF_sDDDq @ 1c0007ee8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDDDq(undefined8 param_1)

{
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,0x2c,"RhpGpioRegionSpaceAccess",0x19
               ,&uStack0000000000000038,4,&uStack0000000000000040,4,&uStack0000000000000048,4,
               &uStack0000000000000050,8,0);
  }
  WppAutoLogTrace(param_1,0,9,&WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,0x2c,
                  "RhpGpioRegionSpaceAccess",0x19,&uStack0000000000000038,4,&uStack0000000000000040,
                  4,&uStack0000000000000048,4,&uStack0000000000000050,8,0);
  return;
}



===== WPP_RECORDER_SF_sDDq @ 1c0008028 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDDq
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,char *param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 8 & 1) != 0) {
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
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,param_4,pcVar1,lVar3,&param_7,4,
               &param_8,4,&param_9,8,0);
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
  WppAutoLogTrace(param_1,0,9,&WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,param_4,param_6,lVar2
                  ,&param_7,4,&param_8,4,&param_9,8,0);
  return;
}



===== WPP_RECORDER_SF_sDSq @ 1c00081bc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDSq(undefined8 param_1)

{
  longlong lVar1;
  wchar_t *pwVar2;
  longlong lVar3;
  longlong lVar4;
  undefined1 uStack0000000000000038;
  wchar_t *in_stack_00000040;
  undefined1 uStack0000000000000048;
  
  lVar4 = -1;
  lVar3 = 10;
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0) {
    if (in_stack_00000040 == (wchar_t *)0x0) {
      lVar1 = 10;
    }
    else {
      lVar1 = -1;
      do {
        lVar1 = lVar1 + 1;
      } while (in_stack_00000040[lVar1] != L'\0');
      lVar1 = lVar1 * 2 + 2;
    }
    pwVar2 = in_stack_00000040;
    if (in_stack_00000040 == (wchar_t *)0x0) {
      pwVar2 = L"NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,0x51,
               "RhpGetOpRegionCacheEntryByName",0x1f,&uStack0000000000000038,4,pwVar2,lVar1,
               &uStack0000000000000048,8,0);
  }
  if (in_stack_00000040 != (wchar_t *)0x0) {
    do {
      lVar4 = lVar4 + 1;
    } while (in_stack_00000040[lVar4] != L'\0');
    lVar3 = lVar4 * 2 + 2;
  }
  if (in_stack_00000040 == (wchar_t *)0x0) {
    in_stack_00000040 = L"NULL";
  }
  WppAutoLogTrace(param_1,0,9,&WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,0x51,
                  "RhpGetOpRegionCacheEntryByName",0x1f,&uStack0000000000000038,4,in_stack_00000040,
                  lVar3,&uStack0000000000000048,8,0);
  return;
}



===== WPP_RECORDER_SF_sDddq @ 1c0008364 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDddq(undefined8 param_1)

{
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,0x41,"RhpSerialBusRegionSpaceAccess"
               ,0x1e,&uStack0000000000000038,4,&uStack0000000000000040,4,&uStack0000000000000048,4,
               &uStack0000000000000050,8,0);
  }
  WppAutoLogTrace(param_1,0,9,&WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,0x41,
                  "RhpSerialBusRegionSpaceAccess",0x1e,&uStack0000000000000038,4,
                  &uStack0000000000000040,4,&uStack0000000000000048,4,&uStack0000000000000050,8,0);
  return;
}



===== WPP_RECORDER_SF_sDdq @ 1c00084a4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDdq(undefined8 param_1)

{
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,0x25,
               "RhpRetryGetRegionConnectionData",0x20,&uStack0000000000000038,4,
               &uStack0000000000000040,4,&uStack0000000000000048,8,0);
  }
  WppAutoLogTrace(param_1,0,9,&WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,0x25,
                  "RhpRetryGetRegionConnectionData",0x20,&uStack0000000000000038,4,
                  &uStack0000000000000040,4,&uStack0000000000000048,8,0);
  return;
}



===== WPP_RECORDER_SF_sdi @ 1c00085c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sdi(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4
                        ,undefined8 param_5,char *param_6,undefined1 param_7,undefined1 param_8)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 8 & 1) != 0) {
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
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,param_4,pcVar1,lVar3,&param_7,4,
               &param_8,8,0);
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
  WppAutoLogTrace(param_1,0,9,&WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,param_4,param_6,lVar2
                  ,&param_7,4,&param_8,8,0);
  return;
}



===== WPP_RECORDER_SF_sLdq @ 1c000872c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sLdq(undefined8 param_1)

{
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,0x19,
               "RhpAssociateContextWithDescriptor",0x22,&uStack0000000000000038,4,
               &uStack0000000000000040,4,&uStack0000000000000048,8,0);
  }
  WppAutoLogTrace(param_1,0,9,&WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,0x19,
                  "RhpAssociateContextWithDescriptor",0x22,&uStack0000000000000038,4,
                  &uStack0000000000000040,4,&uStack0000000000000048,8,0);
  return;
}



===== WPP_RECORDER_SF_sLi @ 1c0008848 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sLi(undefined8 param_1)

{
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,0x44,"RhpSerialBusRegionSpaceAccess"
               ,0x1e,&uStack0000000000000038,4,&uStack0000000000000040,8,0);
  }
  WppAutoLogTrace(param_1,0,9,&WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,0x44,
                  "RhpSerialBusRegionSpaceAccess",0x1e,&uStack0000000000000038,4,
                  &uStack0000000000000040,8,0);
  return;
}



===== WPP_RECORDER_SF_sSDq @ 1c0008944 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sSDq(undefined8 param_1)

{
  longlong lVar1;
  wchar_t *pwVar2;
  longlong lVar3;
  longlong lVar4;
  wchar_t *in_stack_00000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  
  lVar4 = -1;
  lVar3 = 10;
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0) {
    if (in_stack_00000038 == (wchar_t *)0x0) {
      lVar1 = 10;
    }
    else {
      lVar1 = -1;
      do {
        lVar1 = lVar1 + 1;
      } while (in_stack_00000038[lVar1] != L'\0');
      lVar1 = lVar1 * 2 + 2;
    }
    pwVar2 = in_stack_00000038;
    if (in_stack_00000038 == (wchar_t *)0x0) {
      pwVar2 = L"NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,0x23,"RhpSendAcpiAsyncEvalIoctl",
               0x1a,pwVar2,lVar1,&uStack0000000000000040,4,&uStack0000000000000048,8,0);
  }
  if (in_stack_00000038 != (wchar_t *)0x0) {
    do {
      lVar4 = lVar4 + 1;
    } while (in_stack_00000038[lVar4] != L'\0');
    lVar3 = lVar4 * 2 + 2;
  }
  if (in_stack_00000038 == (wchar_t *)0x0) {
    in_stack_00000038 = L"NULL";
  }
  WppAutoLogTrace(param_1,0,9,&WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,0x23,
                  "RhpSendAcpiAsyncEvalIoctl",0x1a,in_stack_00000038,lVar3,&uStack0000000000000040,4
                  ,&uStack0000000000000048,8,0);
  return;
}



===== WPP_RECORDER_SF_sSS @ 1c0008aec =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sSS(undefined8 param_1)

{
  longlong lVar1;
  longlong lVar2;
  wchar_t *pwVar3;
  wchar_t *pwVar4;
  longlong lVar5;
  longlong lVar6;
  wchar_t *in_stack_00000038;
  wchar_t *in_stack_00000040;
  
  lVar6 = -1;
  lVar5 = 10;
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0) {
    if (in_stack_00000040 == (wchar_t *)0x0) {
      lVar1 = 10;
    }
    else {
      lVar1 = -1;
      do {
        lVar1 = lVar1 + 1;
      } while (in_stack_00000040[lVar1] != L'\0');
      lVar1 = lVar1 * 2 + 2;
    }
    pwVar4 = in_stack_00000040;
    if (in_stack_00000040 == (wchar_t *)0x0) {
      pwVar4 = L"NULL";
    }
    if (in_stack_00000038 == (wchar_t *)0x0) {
      lVar2 = 10;
    }
    else {
      lVar2 = -1;
      do {
        lVar2 = lVar2 + 1;
      } while (in_stack_00000038[lVar2] != L'\0');
      lVar2 = lVar2 * 2 + 2;
    }
    pwVar3 = in_stack_00000038;
    if (in_stack_00000038 == (wchar_t *)0x0) {
      pwVar3 = L"NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,0xd,"RhpValidateOpRegionDescriptor",
               0x1e,pwVar3,lVar2,pwVar4,lVar1,0);
  }
  if (in_stack_00000040 == (wchar_t *)0x0) {
    lVar1 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (in_stack_00000040[lVar1] != L'\0');
    lVar1 = lVar1 * 2 + 2;
  }
  if (in_stack_00000040 == (wchar_t *)0x0) {
    in_stack_00000040 = L"NULL";
  }
  if (in_stack_00000038 != (wchar_t *)0x0) {
    do {
      lVar6 = lVar6 + 1;
    } while (in_stack_00000038[lVar6] != L'\0');
    lVar5 = lVar6 * 2 + 2;
  }
  if (in_stack_00000038 == (wchar_t *)0x0) {
    in_stack_00000038 = L"NULL";
  }
  WppAutoLogTrace(param_1,0,9,&WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,0xd,
                  "RhpValidateOpRegionDescriptor",0x1e,in_stack_00000038,lVar5,in_stack_00000040,
                  lVar1,0);
  return;
}



===== WPP_RECORDER_SF_sd @ 1c0008cac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                       undefined8 param_5,char *param_6,undefined1 param_7)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0) {
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
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,param_4,pcVar1,lVar3,&param_7,4,0);
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
  WppAutoLogTrace(param_1,0,9,&WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,param_4,param_6,lVar2
                  ,&param_7,4,0);
  return;
}



===== WPP_RECORDER_SF_sdDDq @ 1c0008de8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sdDDq
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,undefined8 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9,undefined1 param_10)

{
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,param_4,
               "RhpValidateSerialBusRegionSpaceAccess",0x26,&param_7,4,&param_8,4,&param_9,4,
               &param_10,8,0);
  }
  WppAutoLogTrace(param_1,0,9,&WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,param_4,
                  "RhpValidateSerialBusRegionSpaceAccess",0x26,&param_7,4,&param_8,4,&param_9,4,
                  &param_10,8,0);
  return;
}



===== WPP_RECORDER_SF_sdDq @ 1c0008f28 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sdDq(undefined8 param_1)

{
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,0x43,"RhpSerialBusRegionSpaceAccess"
               ,0x1e,&uStack0000000000000038,4,&uStack0000000000000040,4,&uStack0000000000000048,8,0
              );
  }
  WppAutoLogTrace(param_1,0,9,&WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,0x43,
                  "RhpSerialBusRegionSpaceAccess",0x1e,&uStack0000000000000038,4,
                  &uStack0000000000000040,4,&uStack0000000000000048,8,0);
  return;
}



===== WPP_RECORDER_SF_sdS @ 1c0009044 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sdS(undefined8 param_1)

{
  longlong lVar1;
  wchar_t *pwVar2;
  longlong lVar3;
  longlong lVar4;
  undefined1 uStack0000000000000038;
  wchar_t *in_stack_00000040;
  
  lVar4 = -1;
  lVar3 = 10;
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0) {
    if (in_stack_00000040 == (wchar_t *)0x0) {
      lVar1 = 10;
    }
    else {
      lVar1 = -1;
      do {
        lVar1 = lVar1 + 1;
      } while (in_stack_00000040[lVar1] != L'\0');
      lVar1 = lVar1 * 2 + 2;
    }
    pwVar2 = in_stack_00000040;
    if (in_stack_00000040 == (wchar_t *)0x0) {
      pwVar2 = L"NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,0xb,"RhpValidateOpRegionDescriptor",
               0x1e,&uStack0000000000000038,4,pwVar2,lVar1,0);
  }
  if (in_stack_00000040 != (wchar_t *)0x0) {
    do {
      lVar4 = lVar4 + 1;
    } while (in_stack_00000040[lVar4] != L'\0');
    lVar3 = lVar4 * 2 + 2;
  }
  if (in_stack_00000040 == (wchar_t *)0x0) {
    in_stack_00000040 = L"NULL";
  }
  WppAutoLogTrace(param_1,0,9,&WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,0xb,
                  "RhpValidateOpRegionDescriptor",0x1e,&uStack0000000000000038,4,in_stack_00000040,
                  lVar3,0);
  return;
}



===== WPP_RECORDER_SF_sddS @ 1c00091bc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sddS(undefined8 param_1)

{
  longlong lVar1;
  wchar_t *pwVar2;
  longlong lVar3;
  longlong lVar4;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  wchar_t *in_stack_00000048;
  
  lVar4 = -1;
  lVar3 = 10;
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0) {
    if (in_stack_00000048 == (wchar_t *)0x0) {
      lVar1 = 10;
    }
    else {
      lVar1 = -1;
      do {
        lVar1 = lVar1 + 1;
      } while (in_stack_00000048[lVar1] != L'\0');
      lVar1 = lVar1 * 2 + 2;
    }
    pwVar2 = in_stack_00000048;
    if (in_stack_00000048 == (wchar_t *)0x0) {
      pwVar2 = L"NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,0xc,"RhpValidateOpRegionDescriptor",
               0x1e,&uStack0000000000000038,4,&uStack0000000000000040,4,pwVar2,lVar1,0);
  }
  if (in_stack_00000048 != (wchar_t *)0x0) {
    do {
      lVar4 = lVar4 + 1;
    } while (in_stack_00000048[lVar4] != L'\0');
    lVar3 = lVar4 * 2 + 2;
  }
  if (in_stack_00000048 == (wchar_t *)0x0) {
    in_stack_00000048 = L"NULL";
  }
  WppAutoLogTrace(param_1,0,9,&WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,0xc,
                  "RhpValidateOpRegionDescriptor",0x1e,&uStack0000000000000038,4,
                  &uStack0000000000000040,4,in_stack_00000048,lVar3,0);
  return;
}



===== WPP_RECORDER_SF_sdqDq @ 1c000935c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sdqDq(undefined8 param_1)

{
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,0x3b,
               "RhpValidateSerialBusRegionSpaceAccess",0x26,&uStack0000000000000038,4,
               &uStack0000000000000040,8,&uStack0000000000000048,4,&uStack0000000000000050,8,0);
  }
  WppAutoLogTrace(param_1,0,9,&WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,0x3b,
                  "RhpValidateSerialBusRegionSpaceAccess",0x26,&uStack0000000000000038,4,
                  &uStack0000000000000040,8,&uStack0000000000000048,4,&uStack0000000000000050,8,0);
  return;
}



===== WPP_RECORDER_SF_sidq @ 1c00094a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sidq(undefined8 param_1)

{
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,0x1c,"RhpParseOpRegionRequestResult"
               ,0x1e,&uStack0000000000000038,8,&uStack0000000000000040,4,&uStack0000000000000048,8,0
              );
  }
  WppAutoLogTrace(param_1,0,9,&WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,0x1c,
                  "RhpParseOpRegionRequestResult",0x1e,&uStack0000000000000038,8,
                  &uStack0000000000000040,4,&uStack0000000000000048,8,0);
  return;
}



===== WPP_RECORDER_SF_sii @ 1c00095bc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sii(undefined8 param_1)

{
  undefined1 uStack0000000000000040;
  undefined8 local_18 [2];
  
  local_18[0] = 0x14;
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,0xf,
               "RhpValidateAcpiEvalOutputBuffer",0x20,local_18,8,&uStack0000000000000040,8,0);
  }
  WppAutoLogTrace(param_1,0,9,&WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,0xf,
                  "RhpValidateAcpiEvalOutputBuffer",0x20,local_18,8,&uStack0000000000000040,8,0);
  return;
}



===== WPP_RECORDER_SF_siiq @ 1c00096b8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_siiq
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,undefined8 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9)

{
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,param_4,
               "RhpParseOpRegionRequestResult",0x1e,&param_7,8,&param_8,8,&param_9,8,0);
  }
  WppAutoLogTrace(param_1,0,9,&WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,param_4,
                  "RhpParseOpRegionRequestResult",0x1e,&param_7,8,&param_8,8,&param_9,8,0);
  return;
}



===== WPP_RECORDER_SF_sll @ 1c00097cc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sll(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4
                        ,undefined8 param_5,undefined8 param_6,undefined1 param_7,undefined1 param_8
                        )

{
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,param_4,
               "RhpValidateGpioRegionSpaceAccess",0x21,&param_7,4,&param_8,4,0);
  }
  WppAutoLogTrace(param_1,0,9,&WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,param_4,
                  "RhpValidateGpioRegionSpaceAccess",0x21,&param_7,4,&param_8,4,0);
  return;
}



===== WPP_RECORDER_SF_sllq @ 1c00098c4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sllq(undefined8 param_1)

{
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,0x2a,"RhpGpioRegionSpaceAccess",0x19
               ,&uStack0000000000000038,4,&uStack0000000000000040,4,&uStack0000000000000048,8,0);
  }
  WppAutoLogTrace(param_1,0,9,&WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,0x2a,
                  "RhpGpioRegionSpaceAccess",0x19,&uStack0000000000000038,4,&uStack0000000000000040,
                  4,&uStack0000000000000048,8,0);
  return;
}



===== WPP_RECORDER_SF_sq @ 1c00099e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                       undefined8 param_5,char *param_6,undefined1 param_7)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0) {
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
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,param_4,pcVar1,lVar3,&param_7,8,0);
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
  WppAutoLogTrace(param_1,0,9,&WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,param_4,param_6,lVar2
                  ,&param_7,8,0);
  return;
}



===== WPP_RECORDER_SF_sqD @ 1c0009b1c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sqD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4
                        ,undefined8 param_5,char *param_6,undefined1 param_7,undefined1 param_8)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 8 & 1) != 0) {
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
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,param_4,pcVar1,lVar3,&param_7,8,
               &param_8,4,0);
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
  WppAutoLogTrace(param_1,0,9,&WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,param_4,param_6,lVar2
                  ,&param_7,8,&param_8,4,0);
  return;
}



===== WPP_RECORDER_SF_sqDDq @ 1c0009c88 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sqDDq(undefined8 param_1)

{
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,0x3a,
               "RhpValidateSerialBusRegionSpaceAccess",0x26,&uStack0000000000000038,8,
               &uStack0000000000000040,4,&uStack0000000000000048,4,&uStack0000000000000050,8,0);
  }
  WppAutoLogTrace(param_1,0,9,&WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,0x3a,
                  "RhpValidateSerialBusRegionSpaceAccess",0x26,&uStack0000000000000038,8,
                  &uStack0000000000000040,4,&uStack0000000000000048,4,&uStack0000000000000050,8,0);
  return;
}



===== WPP_RECORDER_SF_sqDq @ 1c0009dcc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sqDq(undefined8 param_1)

{
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,0x3c,
               "RhpValidateSerialBusRegionSpaceAccess",0x26,&uStack0000000000000038,8,
               &uStack0000000000000040,4,&uStack0000000000000048,8,0);
  }
  WppAutoLogTrace(param_1,0,9,&WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,0x3c,
                  "RhpValidateSerialBusRegionSpaceAccess",0x26,&uStack0000000000000038,8,
                  &uStack0000000000000040,4,&uStack0000000000000048,8,0);
  return;
}



===== WPP_RECORDER_SF_sqq @ 1c0009ee8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sqq(undefined8 param_1)

{
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,0x32,"RhpSendSpbIoctl",0x10,
               &uStack0000000000000038,8,&uStack0000000000000040,8,0);
  }
  WppAutoLogTrace(param_1,0,9,&WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,0x32,
                  "RhpSendSpbIoctl",0x10,&uStack0000000000000038,8,&uStack0000000000000040,8,0);
  return;
}



===== WPP_RECORDER_SF_ssDq @ 1c0009fdc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_ssDq(undefined8 param_1)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  char *in_stack_00000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 8 & 1) != 0) {
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
               &WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,0x1f,"RhpProcessRegionSpaceAccess",
               0x1c,pcVar1,lVar3,&uStack0000000000000040,4,&uStack0000000000000048,8,0);
  }
  lVar3 = -1;
  if (in_stack_00000038 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    do {
      lVar2 = lVar3;
      lVar3 = lVar2 + 1;
    } while (in_stack_00000038[lVar3] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (in_stack_00000038 == (char *)0x0) {
    in_stack_00000038 = "NULL";
  }
  WppAutoLogTrace(param_1,0,9,&WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,0x1f,
                  "RhpProcessRegionSpaceAccess",0x1c,in_stack_00000038,lVar2,&uStack0000000000000040
                  ,4,&uStack0000000000000048,8,0);
  return;
}



===== RhpProcessNativeMethodInterfaceQueryIoctl @ 1c000a16c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong RhpProcessNativeMethodInterfaceQueryIoctl
                    (undefined8 param_1,ushort *param_2,undefined4 *param_3)

{
  uint uVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  ushort *puVar4;
  undefined2 uVar5;
  undefined4 *local_res20;
  ushort *local_18;
  undefined8 local_10;
  
  local_18 = (ushort *)0x0;
  local_10 = 0;
  local_res20 = (undefined4 *)0x0;
  puVar4 = param_2;
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x868))
                    (WdfDriverGlobals,param_2,0x60,&local_18,&local_10);
  uVar3 = (ulonglong)uVar1;
  if ((int)uVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return uVar3;
    }
    uVar5 = 0x33;
    param_2 = puVar4;
  }
  else {
    uVar1 = (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,param_2,0x60,&local_res20,0);
    uVar3 = (ulonglong)uVar1;
    if ((int)uVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return uVar3;
      }
      uVar5 = 0x34;
    }
    else {
      uVar2 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
      param_2 = local_18;
      uVar3 = PlExtProcessNativeMethodInterfaceRequest(uVar2,local_18,local_res20);
      uVar1 = (uint)uVar3;
      uVar3 = uVar3 & 0xffffffff;
      if (-1 < (int)uVar1) {
        *param_3 = 0x60;
        return uVar3;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return uVar3;
      }
      uVar5 = 0x35;
    }
  }
  WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,6,uVar5,
                     &WPP_a781b87147d030366b419d92a3dc1ed1_Traceguids,
                     "RhpProcessNativeMethodInterfaceQueryIoctl",(char)uVar1);
  return uVar3;
}



===== WPP_RECORDER_SF_Dq @ 1c000a2e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_Dq(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_a781b87147d030366b419d92a3dc1ed1_Traceguids,0xd,&uStack0000000000000030,4,
               &uStack0000000000000038,8,0);
  }
  WppAutoLogTrace(param_1,0,2,&WPP_a781b87147d030366b419d92a3dc1ed1_Traceguids,0xd,
                  &uStack0000000000000030,4,&uStack0000000000000038,8,0);
  return;
}



===== WPP_RECORDER_SF_sDDD @ 1c000a3ac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDDD(undefined8 param_1)

{
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_a781b87147d030366b419d92a3dc1ed1_Traceguids,0x3b,
               "RhpProcessUpdateActiveBothInitialPolarityIoctl",0x2f,&uStack0000000000000038,4,
               &uStack0000000000000040,4,&uStack0000000000000048,4,0);
  }
  WppAutoLogTrace(param_1,0,6,&WPP_a781b87147d030366b419d92a3dc1ed1_Traceguids,0x3b,
                  "RhpProcessUpdateActiveBothInitialPolarityIoctl",0x2f,&uStack0000000000000038,4,
                  &uStack0000000000000040,4,&uStack0000000000000048,4,0);
  return;
}



===== _guard_check_icall @ 1c000a4c0 =====

void _guard_check_icall(void)

{
  return;
}



===== WppClassicProviderCallback @ 1c000a4d0 =====

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



===== WPP_RECORDER_SF_sSDD @ 1c000a52c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sSDD(undefined8 param_1)

{
  longlong lVar1;
  wchar_t *pwVar2;
  longlong lVar3;
  longlong lVar4;
  wchar_t *in_stack_00000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  
  lVar4 = -1;
  lVar3 = 10;
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0) {
    if (in_stack_00000038 == (wchar_t *)0x0) {
      lVar1 = 10;
    }
    else {
      lVar1 = -1;
      do {
        lVar1 = lVar1 + 1;
      } while (in_stack_00000038[lVar1] != L'\0');
      lVar1 = lVar1 * 2 + 2;
    }
    pwVar2 = in_stack_00000038;
    if (in_stack_00000038 == (wchar_t *)0x0) {
      pwVar2 = L"NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_cf4f8fa19d3932c70975ae2eca242000_Traceguids,0x13,
               "RhpBiosGpioInterruptToNtResource",0x21,pwVar2,lVar1,&uStack0000000000000040,4,
               &uStack0000000000000048,4,0);
  }
  if (in_stack_00000038 != (wchar_t *)0x0) {
    do {
      lVar4 = lVar4 + 1;
    } while (in_stack_00000038[lVar4] != L'\0');
    lVar3 = lVar4 * 2 + 2;
  }
  if (in_stack_00000038 == (wchar_t *)0x0) {
    in_stack_00000038 = L"NULL";
  }
  WppAutoLogTrace(param_1,0,7,&WPP_cf4f8fa19d3932c70975ae2eca242000_Traceguids,0x13,
                  "RhpBiosGpioInterruptToNtResource",0x21,in_stack_00000038,lVar3,
                  &uStack0000000000000040,4,&uStack0000000000000048,4,0);
  return;
}



===== WPP_RECORDER_SF_sqdd @ 1c000a6c8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sqdd(undefined8 param_1)

{
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_cf4f8fa19d3932c70975ae2eca242000_Traceguids,0x16,"RhpBiosSerialBusToNtResource",
               0x1d,&uStack0000000000000038,8,&uStack0000000000000040,4,&uStack0000000000000048,4,0)
    ;
  }
  WppAutoLogTrace(param_1,0,7,&WPP_cf4f8fa19d3932c70975ae2eca242000_Traceguids,0x16,
                  "RhpBiosSerialBusToNtResource",0x1d,&uStack0000000000000038,8,
                  &uStack0000000000000040,4,&uStack0000000000000048,4,0);
  return;
}



===== RtlStringCbLengthW @ 1c000a7e4 =====

uint RtlStringCbLengthW(short *param_1,ulonglong param_2,longlong *param_3)

{
  ulonglong uVar1;
  ulonglong uVar2;
  uint uVar3;
  ulonglong uVar4;
  
  uVar4 = param_2 >> 1;
  uVar2 = 0;
  if ((param_1 == (short *)0x0) || (uVar1 = uVar4, 0x7fffffff < uVar4)) {
    uVar3 = 0xc000000d;
  }
  else {
    for (; (uVar1 != 0 && (*param_1 != 0)); param_1 = param_1 + 1) {
      uVar1 = uVar1 - 1;
    }
    uVar3 = ~-(uint)(uVar1 != 0) & 0xc000000d;
    uVar2 = -(ulonglong)(uVar1 != 0) & uVar4 - uVar1;
  }
  if (param_3 != (longlong *)0x0) {
    if ((int)uVar3 < 0) {
      *param_3 = 0;
    }
    else {
      *param_3 = uVar2 * 2;
    }
  }
  return uVar3;
}



===== FxStubDriverEntryFailure @ 1c000a858 =====

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
  
  if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_1c0016298 != &__KMDF_CLASS_BIND_START) {
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



===== FxStubDriverUnloadCommon @ 1c000a8c4 =====

/* void __cdecl FxStubDriverUnloadCommon(void) */

void __cdecl FxStubDriverUnloadCommon(void)

{
  _WDF_BIND_INFO *in_RCX;
  
  FxStubUnbindClasses(in_RCX);
  WdfVersionUnbind(&DAT_1c0016530,&WdfBindInfo,WdfDriverGlobals);
  return;
}



===== FxStubDriverUnload @ 1c000a900 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FxStubDriverUnload(void)

{
  if ((DAT_1c0016508 != (code *)0x0) && (DAT_1c0016508 != FxStubDriverUnload)) {
    (*DAT_1c0016508)();
  }
  FxStubDriverUnloadCommon();
  return;
}



===== FxStubBindClasses @ 1c000a934 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x0001c000a959) */
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
    if ((uint *)0x1c001628f < puVar2) break;
    PTR___KMDF_CLASS_BIND_START_1c0016298 = (undefined *)puVar2;
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



===== FxStubUnbindClasses @ 1c000aa94 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl FxStubUnbindClasses(struct _WDF_BIND_INFO * __ptr64) */

void __cdecl FxStubUnbindClasses(_WDF_BIND_INFO *param_1)

{
  uint *puVar1;
  uint *puVar2;
  void **ppvVar3;
  
  ppvVar3 = &__KMDF_CLASS_BIND_END;
  if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_1c0016298 != &__KMDF_CLASS_BIND_START) {
    puVar1 = (uint *)(PTR___KMDF_CLASS_BIND_START_1c0016298 + 0x50);
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



===== FxGetNextClassBindInfo @ 1c000ab50 =====

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



===== FxStubInitTypes @ 1c000ab98 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x0001c000abb5) */
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
    if ((void **)0x1c00162af < ppvVar2) break;
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



===== PlExtProcessReadyList @ 1c000ac60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PlExtProcessReadyList(undefined1 *param_1)

{
  longlong *plVar1;
  code *pcVar2;
  longlong *plVar3;
  undefined1 uVar4;
  undefined1 *puVar5;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  longlong local_28;
  longlong lStack_20;
  undefined4 local_18;
  ulonglong local_10;
  
  puVar5 = auStack_48;
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  uVar4 = *param_1;
  local_28 = 0;
  lStack_20 = 0;
  local_18 = 0;
  do {
    plVar3 = PlExtReadyRequestsList;
    if ((longlong **)PlExtReadyRequestsList == &PlExtReadyRequestsList) {
LAB_1c000ad52:
      *param_1 = uVar4;
      *(undefined8 *)(puVar5 + -8) = 0x1c000ad62;
      return;
    }
    if (((longlong **)PlExtReadyRequestsList[1] != &PlExtReadyRequestsList) ||
       (plVar1 = (longlong *)*PlExtReadyRequestsList,
       (longlong *)plVar1[1] != PlExtReadyRequestsList)) {
      pcVar2 = (code *)swi(0x29);
      (*pcVar2)(3);
      puVar5 = auStack_40;
      goto LAB_1c000ad52;
    }
    PlExtReadyRequestsList = plVar1;
    plVar1[1] = (longlong)&PlExtReadyRequestsList;
    plVar3[1] = (longlong)plVar3;
    *plVar3 = (longlong)plVar3;
    PlExtpMoveRequestToTargetQueue(0x1c0016610,plVar3);
    *(undefined4 *)(plVar3 + 6) = 4;
    ExReleaseSpinLockExclusive(&PlExtRequestListLock,uVar4);
    local_28 = plVar3[0xe];
    lStack_20 = plVar3[0xf];
    local_18 = (undefined4)plVar3[0x10];
    (*(code *)(&PlExtRequestProcessAndCompletionRoutines)
              [(longlong)*(int *)((longlong)plVar3 + 0x14) * 2])(plVar3,&local_28);
    uVar4 = ExAcquireSpinLockExclusive(&PlExtRequestListLock);
  } while( true );
}



===== PlExtRequestWorkerRoutine @ 1c000ad80 =====

void PlExtRequestWorkerRoutine(void)

{
  int iVar1;
  undefined1 local_res10 [24];
  undefined *in_stack_ffffffffffffffc8;
  undefined *local_18;
  undefined *local_10;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_stack_ffffffffffffffc8 = &WPP_014e28a2725035dd75100948d63f8491_Traceguids;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,10,
                     &WPP_014e28a2725035dd75100948d63f8491_Traceguids);
  }
  PlExtRequestWorkerThread = SystemReserved1[0xf];
  KeSetPriorityThread(SystemReserved1[0xf],0x10);
  local_10 = &PlExtWorkerTerminateEvent;
  local_18 = &PlExtWorkerProcessQueueEvent;
  do {
    in_stack_ffffffffffffffc8 =
         (undefined *)((ulonglong)in_stack_ffffffffffffffc8 & 0xffffffffffffff00);
    iVar1 = KeWaitForMultipleObjects(2,&local_18,1,0,in_stack_ffffffffffffffc8,0,0,&DAT_1c0016540);
    if (iVar1 == 1) {
      PsTerminateSystemThread(0);
    }
    local_res10[0] = ExAcquireSpinLockExclusive(&PlExtRequestListLock);
    PlExtProcessReadyList(local_res10);
    KeClearEvent(&PlExtWorkerProcessQueueEvent);
    PlExtWorkerRunning = 0;
    ExReleaseSpinLockExclusive(&PlExtRequestListLock,local_res10[0]);
  } while( true );
}



===== PlExtpCompleteRequest @ 1c000aeac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PlExtpCompleteRequest(longlong *param_1,undefined4 param_2)

{
  bool bVar1;
  undefined1 uVar2;
  
  bVar1 = false;
  uVar2 = ExAcquireSpinLockExclusive(&PlExtRequestListLock);
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,param_1[5]);
  if ((int)param_1[6] == 5) {
    *(undefined4 *)(param_1 + 6) = 3;
    PlExtpMoveRequestToTargetQueue(0x1c0016600,param_1);
    bVar1 = true;
  }
  else {
    if ((int)param_1[6] != 4) goto LAB_1c000af35;
    *(undefined4 *)(param_1 + 6) = 3;
    bVar1 = false;
  }
  *(undefined4 *)(param_1 + 0xe) = 1;
  *(undefined4 *)((longlong)param_1 + 0x74) = param_2;
LAB_1c000af35:
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,param_1[5]);
  if (bVar1) {
    PlExtpScheduleWorkerLocked(1);
  }
  ExReleaseSpinLockExclusive(&PlExtRequestListLock,uVar2);
  return;
}



===== PlExtpPendRequest @ 1c000af94 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 PlExtpPendRequest(longlong *param_1)

{
  undefined1 uVar1;
  undefined8 uVar2;
  
  uVar1 = ExAcquireSpinLockExclusive(&PlExtRequestListLock);
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,param_1[5]);
  if ((int)param_1[6] == 4) {
    *(undefined4 *)(param_1 + 6) = 5;
    PlExtpMoveRequestToTargetQueue(0x1c0016620,param_1);
    uVar2 = 0x103;
  }
  else if ((int)param_1[6] == 3) {
    *(undefined4 *)(param_1 + 6) = 4;
    uVar2 = 0xc0000016;
  }
  else {
    uVar2 = 0xc0000001;
  }
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,param_1[5]);
  ExReleaseSpinLockExclusive(&PlExtRequestListLock,uVar1);
  return uVar2;
}



===== RtlStringCbPrintfA @ 1c000b064 =====

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



===== WPP_RECORDER_SF_ @ 1c000b0d8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                     undefined8 param_5)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,0);
  return;
}



===== WPP_RECORDER_SF_D @ 1c000b1b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_D(undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
                      undefined8 param_5,undefined1 param_6)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,4,0);
  }
  WppAutoLogTrace(param_1,2,param_3,param_5,param_4,&param_6,4,0);
  return;
}



===== WPP_RECORDER_SF_SD @ 1c000b2a4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_SD(undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
                       undefined8 param_5,wchar_t *param_6,undefined1 param_7)

{
  longlong lVar1;
  wchar_t *pwVar2;
  longlong lVar3;
  longlong lVar4;
  ulonglong uVar5;
  
  lVar4 = -1;
  uVar5 = (ulonglong)(param_3 >> 0x10);
  lVar3 = 10;
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar5 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[uVar5 * 0x50 + 0x29])) {
    if (param_6 == (wchar_t *)0x0) {
      lVar1 = 10;
    }
    else {
      lVar1 = -1;
      do {
        lVar1 = lVar1 + 1;
      } while (param_6[lVar1] != L'\0');
      lVar1 = lVar1 * 2 + 2;
    }
    pwVar2 = param_6;
    if (param_6 == (wchar_t *)0x0) {
      pwVar2 = L"NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar5 * 0x50 + 0x18),0x2b,param_5,param_4,pwVar2
               ,lVar1,&param_7,4,0);
  }
  if (param_6 != (wchar_t *)0x0) {
    do {
      lVar4 = lVar4 + 1;
    } while (param_6[lVar4] != L'\0');
    lVar3 = lVar4 * 2 + 2;
  }
  if (param_6 == (wchar_t *)0x0) {
    param_6 = L"NULL";
  }
  WppAutoLogTrace(param_1,2,param_3,param_5,param_4,param_6,lVar3,&param_7,4,0);
  return;
}



===== WPP_RECORDER_SF_SqD @ 1c000b430 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_SqD(undefined8 param_1)

{
  longlong lVar1;
  wchar_t *pwVar2;
  longlong lVar3;
  longlong lVar4;
  wchar_t *in_stack_00000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  lVar4 = -1;
  lVar3 = 10;
  if (((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0') &&
     (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    if (in_stack_00000030 == (wchar_t *)0x0) {
      lVar1 = 10;
    }
    else {
      lVar1 = -1;
      do {
        lVar1 = lVar1 + 1;
      } while (in_stack_00000030[lVar1] != L'\0');
      lVar1 = lVar1 * 2 + 2;
    }
    pwVar2 = in_stack_00000030;
    if (in_stack_00000030 == (wchar_t *)0x0) {
      pwVar2 = L"NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_014e28a2725035dd75100948d63f8491_Traceguids,0x21,pwVar2,lVar1,
               &uStack0000000000000038,8,&uStack0000000000000040,4,0);
  }
  if (in_stack_00000030 != (wchar_t *)0x0) {
    do {
      lVar4 = lVar4 + 1;
    } while (in_stack_00000030[lVar4] != L'\0');
    lVar3 = lVar4 * 2 + 2;
  }
  if (in_stack_00000030 == (wchar_t *)0x0) {
    in_stack_00000030 = L"NULL";
  }
  WppAutoLogTrace(param_1,2,8,&WPP_014e28a2725035dd75100948d63f8491_Traceguids,0x21,
                  in_stack_00000030,lVar3,&uStack0000000000000038,8,&uStack0000000000000040,4,0);
  return;
}



===== PlExtNotifyDiscoverDestroyDevices @ 1c000b5b0 =====

int PlExtNotifyDiscoverDestroyDevices(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  longlong lVar2;
  longlong *local_res10;
  
  local_res10 = (longlong *)0x0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    param_3 = 1;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,10,
                     &WPP_a31fe4b5b02930fb8029abd8f99eeaaf_Traceguids);
  }
  lVar2 = param_1;
  iVar1 = PlExtpCreateDiscoverDestroyParentRequest(param_1,(longlong *)&local_res10);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qD(lVar2,2,param_3,0xb,&WPP_a31fe4b5b02930fb8029abd8f99eeaaf_Traceguids,
                         (char)param_1,(char)iVar1);
    }
  }
  else {
    PlExtpReadyRequestAndScheduleWorker(local_res10);
    iVar1 = 0x103;
  }
  return iVar1;
}



===== PlExtpBiosToNtDeviceControlResources @ 1c000b66c =====

int PlExtpBiosToNtDeviceControlResources(undefined *param_1,longlong param_2)

{
  ushort uVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  undefined *puVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  longlong lVar8;
  uint local_res10 [2];
  undefined4 local_res18 [4];
  undefined1 uVar9;
  undefined1 uVar10;
  
  iVar4 = 0;
  local_res10[0] = 0;
  local_res18[0] = 0;
  puVar5 = param_1;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (puVar5 = WPP_GLOBAL_Control, *(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    puVar5 = *(undefined **)(WPP_GLOBAL_Control + 0x40);
    WPP_RECORDER_SF_(puVar5,5,1,0x21,&WPP_a31fe4b5b02930fb8029abd8f99eeaaf_Traceguids);
  }
  lVar2 = *(longlong *)(param_2 + 0x98);
  lVar8 = 0;
  *(undefined8 *)(param_2 + 0xa8) = 0;
  *(undefined4 *)(param_2 + 0xa0) = 0;
  if (lVar2 != 0) {
    if ((*(longlong *)(lVar2 + 0x10) != 0) && (uVar1 = *(ushort *)(lVar2 + 0x1a), uVar1 != 0)) {
      iVar4 = PlExtpAcpiTranslatePepDeviceControlResources
                        (puVar5,param_2,lVar2 + 0x1c,(uint)uVar1,0,0,local_res10);
      uVar3 = local_res10[0];
      uVar9 = SUB81(param_1,0);
      uVar10 = (undefined1)param_2;
      if (((iVar4 + 0x80000000U & 0x80000000) == 0) && (iVar4 != -0x3fffffdd)) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qqD(*(undefined8 *)(param_1 + 0x98),4,8,0x22,
                              &WPP_a31fe4b5b02930fb8029abd8f99eeaaf_Traceguids,uVar9,uVar10,
                              (char)iVar4);
        }
      }
      else {
        uVar7 = (ulonglong)local_res10[0];
        if (local_res10[0] == 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_qqD(*(undefined8 *)(param_1 + 0x98),4,8,0x23,
                                &WPP_a31fe4b5b02930fb8029abd8f99eeaaf_Traceguids,uVar9,uVar10,
                                (char)iVar4);
          }
          iVar4 = 0;
        }
        else {
          uVar6 = 0x100;
          lVar8 = ExAllocatePool2(0x100,uVar7,0x78466550);
          if (lVar8 == 0) {
            iVar4 = -0x3fffff66;
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_qqDD
                        (*(undefined8 *)(param_1 + 0x98),uVar7,8,0x24,
                         &WPP_a31fe4b5b02930fb8029abd8f99eeaaf_Traceguids,uVar9,uVar10,(char)uVar3,
                         0x9a);
            }
          }
          else {
            iVar4 = PlExtpAcpiTranslatePepDeviceControlResources
                              (uVar6,param_2,lVar2 + 0x1c,(uint)uVar1,lVar8,uVar3,local_res18);
            if (-1 < iVar4) {
              *(longlong *)(param_2 + 0xa8) = lVar8;
              *(uint *)(param_2 + 0xa0) = uVar3;
            }
          }
        }
      }
    }
    ExFreePoolWithTag(lVar2,0x78466550);
    *(undefined8 *)(param_2 + 0x98) = 0;
    if ((iVar4 < 0) && (lVar8 != 0)) {
      ExFreePoolWithTag(lVar8,0x78466550);
    }
  }
  return iVar4;
}



===== PlExtpCreateBuildDestroyDeviceRequest @ 1c000b8d8 =====

int PlExtpCreateBuildDestroyDeviceRequest
              (longlong param_1,undefined8 param_2,char param_3,longlong param_4,longlong *param_5)

{
  longlong lVar1;
  int iVar2;
  char *pcVar3;
  longlong lVar4;
  longlong local_38 [2];
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x16,
                     &WPP_a31fe4b5b02930fb8029abd8f99eeaaf_Traceguids);
  }
  local_38[0] = 0;
  lVar4 = param_1;
  iVar2 = PlExtpCreateRequest((uint)(param_3 == '\0'),param_1,param_4,0,local_38);
  lVar1 = local_38[0];
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_SD(*(undefined8 *)(param_1 + 0x98),lVar4,9,0x17,
                         &WPP_a31fe4b5b02930fb8029abd8f99eeaaf_Traceguids,
                         *(wchar_t **)(param_1 + 0x18),(char)iVar2);
    }
    if (local_38[0] != 0) {
      PlExtpDereferenceRequest(local_38[0]);
    }
  }
  else {
    *(undefined8 *)(local_38[0] + 0x88) = param_2;
    if (param_3 != '\0') {
      *(undefined8 *)(local_38[0] + 0x90) = 0;
      *(undefined8 *)(local_38[0] + 0x98) = 0;
      *(undefined4 *)(local_38[0] + 0xb4) = 0;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      pcVar3 = "BUILD";
      if (param_3 == '\0') {
        pcVar3 = "DESTROY";
      }
      WPP_RECORDER_SF_sSD(*(undefined8 *)(param_1 + 0x98),4,9,0x18,
                          &WPP_a31fe4b5b02930fb8029abd8f99eeaaf_Traceguids,pcVar3,
                          *(wchar_t **)(param_1 + 0x18),(char)iVar2);
    }
    *param_5 = lVar1;
  }
  return iVar2;
}



===== PlExtpCreateDevice @ 1c000ba58 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint PlExtpCreateDevice(longlong param_1,longlong param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  code *pcVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  undefined4 *puVar8;
  undefined8 uVar9;
  undefined1 *puVar10;
  undefined2 uVar11;
  longlong local_res10 [2];
  longlong local_res20;
  undefined1 auStackY_c8 [8];
  undefined1 auStackY_c0 [24];
  wchar_t *pwVar12;
  undefined8 local_88;
  wchar_t *pwStack_80;
  undefined4 local_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 local_68;
  undefined4 uStack_64;
  undefined8 uStack_60;
  longlong local_58;
  undefined8 uStack_50;
  undefined *local_48;
  
  local_48 = (undefined *)((ulonglong)local_48 & 0xffffffff00000000);
  local_res20 = 0;
  local_78 = 0;
  uStack_74 = 0;
  uStack_70 = 0;
  uStack_6c = 0;
  local_68 = 0;
  uStack_64 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0xc,
                     &WPP_a31fe4b5b02930fb8029abd8f99eeaaf_Traceguids);
  }
  local_res10[0] = 0;
  puVar7 = &local_88;
  local_88 = 0;
  pwStack_80 = (wchar_t *)0x0;
  uVar3 = PlExtpDuplicateUnicodeString((ushort *)(param_2 + 0x38),(undefined2 *)puVar7);
  if ((int)uVar3 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000bcef;
    uVar11 = 0xd;
    pwVar12 = *(wchar_t **)(param_2 + 0x40);
  }
  else {
    iVar4 = PlExtpFindDeviceByNameOrHandle(0,&local_88,0,&local_res20);
    if (iVar4 < 0) {
      uStack_64 = 0;
      puVar8 = &local_78;
      uStack_60 = 0x100000001;
      local_48 = PTR__WDF_PLEXT_ACPI_DEVICE_CONTEXT_TYPE_INFO_1c00161e0;
      uStack_74 = 0;
      uStack_70 = 0;
      uStack_6c = 0;
      local_68 = 0;
      uStack_50 = 0;
      local_78 = 0x38;
      local_58 = param_1;
      uVar3 = (**(code **)(WdfFunctions_01015 + 0x678))(WdfDriverGlobals,puVar8,local_res10);
      if ((int)uVar3 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000bcef;
        uVar11 = 0xf;
        uVar5 = PlExtLogHandle;
      }
      else {
        puVar7 = (undefined8 *)
                 (**(code **)(WdfFunctions_01015 + 0x650))
                           (WdfDriverGlobals,local_res10[0],
                            PTR__WDF_PLEXT_ACPI_DEVICE_CONTEXT_TYPE_INFO_1c00161e0);
        memset(puVar7,0,0xb8);
        puVar8 = &local_78;
        puVar7[2] = local_88;
        puVar7[3] = pwStack_80;
        puVar7[4] = local_res10[0];
        puVar7[0xb] = *(undefined8 *)(param_2 + 0x10);
        *(undefined4 *)(puVar7 + 6) = 2;
        *(undefined4 *)((longlong)puVar7 + 0x34) = 0;
        puVar7[0x13] = PlExtLogHandle;
        local_48 = (undefined *)0x0;
        local_68 = 0;
        uStack_64 = 0;
        uStack_60 = 0x100000001;
        uStack_50 = 0;
        local_58 = local_res10[0];
        uStack_74 = 0;
        uStack_70 = 0;
        uStack_6c = 0;
        local_78 = 0x38;
        uVar3 = (**(code **)(WdfFunctions_01015 + 0x9d8))(WdfDriverGlobals);
        if (-1 < (int)uVar3) {
          IoInitializeRemoveLockEx(puVar7 + 0xf,0x78466550,0,0);
          uVar5 = 0;
          (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,PlExtAcpiDeviceListLock);
          puVar10 = auStackY_c8;
          puVar6 = &PlExtAcpiDeviceList;
          if ((undefined8 *)*DAT_1c00165f8 != &PlExtAcpiDeviceList) {
            puVar6 = (undefined8 *)0x3;
            pcVar2 = (code *)swi(0x29);
            DAT_1c00165f8 = (undefined8 *)(*pcVar2)();
            puVar10 = auStackY_c0;
          }
          *puVar7 = puVar6;
          puVar7[1] = DAT_1c00165f8;
          *DAT_1c00165f8 = puVar7;
          pcVar2 = *(code **)(WdfFunctions_01015 + 0x9d0);
          *(undefined8 *)(puVar10 + -8) = 0x1c000bdc8;
          uVar9 = PlExtAcpiDeviceListLock;
          DAT_1c00165f8 = puVar7;
          (*pcVar2)(WdfDriverGlobals);
          *param_3 = puVar7;
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return uVar3;
          }
          uVar1 = puVar7[0x13];
          *(undefined8 *)(puVar10 + 0x30) = puVar7[4];
          *(undefined8 *)(puVar10 + 0x28) = puVar7[3];
          *(undefined8 *)(puVar10 + -8) = 0x1c000bdf8;
          WPP_RECORDER_SF_Sq(uVar1,uVar9,uVar5,0x11,*(undefined8 *)(puVar10 + 0x20),
                             *(wchar_t **)(puVar10 + 0x28),puVar10[0x30]);
          return uVar3;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000bcef;
        uVar5 = puVar7[0x13];
        uVar11 = 0x10;
      }
      WPP_RECORDER_SF_SD(uVar5,puVar8,8,uVar11,&WPP_a31fe4b5b02930fb8029abd8f99eeaaf_Traceguids,
                         pwStack_80,(char)uVar3);
      goto LAB_1c000bcef;
    }
    puVar7 = (undefined8 *)0x78466550;
    IoReleaseRemoveLockEx(local_res20 + 0x78,0x78466550,0x20);
    uVar3 = 0xc0000001;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000bcef;
    uVar11 = 0xe;
    pwVar12 = pwStack_80;
  }
  WPP_RECORDER_SF_S(PlExtLogHandle,puVar7,8,uVar11,&WPP_a31fe4b5b02930fb8029abd8f99eeaaf_Traceguids,
                    pwVar12);
LAB_1c000bcef:
  if (local_res10[0] != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
  if (pwStack_80 != (wchar_t *)0x0) {
    ExFreePoolWithTag(pwStack_80,0x78466550);
  }
  return uVar3;
}



===== PlExtpCreateDiscoverDestroyParentRequest @ 1c000be1c =====

int PlExtpCreateDiscoverDestroyParentRequest(longlong param_1,longlong *param_2)

{
  int iVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  longlong local_res8;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x1b,
                     &WPP_a31fe4b5b02930fb8029abd8f99eeaaf_Traceguids);
  }
  local_res8 = 0;
  uVar2 = 6 - (*(char *)(param_1 + 0x10) != '\0');
  uVar3 = (ulonglong)uVar2;
  uVar4 = 0;
  iVar1 = PlExtpCreateRequest(uVar2,0,0,*(longlong *)(param_1 + 0x18),&local_res8);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qD(uVar3,2,uVar4,0x1c,&WPP_a31fe4b5b02930fb8029abd8f99eeaaf_Traceguids,
                         (char)param_1,(char)iVar1);
    }
    if (local_res8 != 0) {
      PlExtpDereferenceRequest(local_res8);
    }
  }
  else {
    *param_2 = local_res8;
    *(longlong *)(local_res8 + 0x88) = param_1;
  }
  return iVar1;
}



===== PlExtpDiscoverDestroyFinalCompletion @ 1c000bf10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PlExtpDiscoverDestroyFinalCompletion(longlong param_1)

{
  (**(code **)(*(longlong *)(param_1 + 0x88) + 0x20))
            (*(undefined8 *)(*(longlong *)(param_1 + 0x88) + 0x28));
  return;
}



===== PlExtpDiscoverDestroyParentRequestStateTransition @ 1c000bf34 =====

uint PlExtpDiscoverDestroyParentRequestStateTransition
               (longlong param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x1d,
                     &WPP_a31fe4b5b02930fb8029abd8f99eeaaf_Traceguids);
  }
  uVar7 = 0;
  iVar9 = *param_2;
  iVar1 = param_2[1];
  uVar8 = 0;
  iVar2 = *(int *)(param_1 + 0x14);
  uVar5 = 0xc0000016;
  *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x34);
  iVar6 = *(int *)(param_1 + 0x34);
  do {
    iVar4 = iVar6;
    if ((iVar6 == 0) || (iVar6 == 1)) {
LAB_1c000c09b:
      uVar5 = 0xc0000001;
      uVar8 = 0xc0000001;
      iVar6 = *(int *)(param_1 + 0x38);
LAB_1c000c0a7:
      uVar7 = 1;
    }
    else {
      if (iVar6 == 2) {
        if ((iVar2 == 5) || (iVar4 = 3, iVar2 == 6)) {
          iVar4 = 0xd;
        }
        goto LAB_1c000c0ad;
      }
      if (iVar6 == 3) {
        uVar8 = 0;
        uVar5 = 0;
        goto LAB_1c000c0a7;
      }
      if (iVar6 == 4) {
        iVar4 = 5;
        uVar8 = 0;
        uVar7 = 2;
LAB_1c000c078:
        uVar5 = 0;
      }
      else if (iVar6 == 0xd) {
        if (iVar9 == 0) {
          uVar7 = 0x16;
          uVar8 = 0xc0000016;
          goto LAB_1c000c078;
        }
        if (iVar1 < 0) {
          iVar4 = 3;
        }
        else {
          iVar4 = 0xe;
          if (*(longlong **)(param_1 + 0x60) == (longlong *)(param_1 + 0x60)) {
            iVar4 = 4;
          }
        }
      }
      else {
        if (iVar6 == 0xe) {
          if (iVar9 == 0) {
            uVar7 = 0x17;
            uVar8 = 0xc0000016;
          }
          else {
            iVar4 = 0xf;
          }
        }
        else {
          if (iVar6 != 0xf) goto LAB_1c000c09b;
          if (iVar9 == 0) {
            uVar7 = 0x18;
          }
          else {
            iVar4 = 4;
          }
          uVar8 = uVar8 & -(uint)(iVar9 != 0);
        }
        uVar5 = uVar5 & -(uint)(iVar9 != 0);
      }
    }
LAB_1c000c0ad:
    *(int *)(param_1 + 0x154 + (ulonglong)*(byte *)(param_1 + 0x150) * 4) = iVar6;
    *(int *)(param_1 + 0x34) = iVar4;
    *(byte *)(param_1 + 0x150) = *(char *)(param_1 + 0x150) + 1U & 3;
    uVar3 = 0;
    if (uVar5 != 0xc0000016) {
      uVar3 = uVar7;
    }
    uVar7 = uVar3;
    iVar9 = 0;
    iVar6 = iVar4;
    if (uVar5 != 0xc0000016) {
      *param_3 = uVar7;
      param_3[1] = iVar4;
      return uVar8;
    }
  } while( true );
}



===== PlExtpProcessDeviceRequest @ 1c000c130 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint PlExtpProcessDeviceRequest(longlong *param_1,undefined8 *param_2)

{
  int iVar1;
  undefined *puVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  longlong *plVar9;
  uint *puVar10;
  bool bVar11;
  undefined1 auStackY_98 [32];
  int local_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined4 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_98;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x1a,
                     &WPP_a31fe4b5b02930fb8029abd8f99eeaaf_Traceguids);
  }
  puVar2 = (undefined *)param_1[4];
  bVar3 = false;
  iVar1 = *(int *)((longlong)param_1 + 0x14);
  uStack_64 = 0;
  uStack_60 = 0;
  local_68 = 0;
  if (param_2 == (undefined8 *)0x0) {
    uStack_50 = 0;
    local_48 = 0;
    local_58 = 0;
  }
  else {
    local_58 = *param_2;
    uStack_50 = param_2[1];
    local_48 = *(undefined4 *)(param_2 + 2);
  }
  LOCK();
  *(int *)((longlong)param_1 + 0x3c) = *(int *)((longlong)param_1 + 0x3c) + 1;
  UNLOCK();
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(puVar2 + 0x28));
  do {
    uVar5 = PlExtpDeviceStateTransition((longlong)param_1,(int *)&local_58,&local_68);
    iVar4 = local_68;
    bVar11 = local_68 != 0;
    if (bVar11) {
      (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(puVar2 + 0x28));
    }
    if (iVar4 < 10) {
      if (iVar4 != 9) {
        if (iVar4 != 0) {
          if (iVar4 == 1) {
            puVar10 = (uint *)((longlong)param_1 + 0xb4);
            if (iVar1 != 0) {
              puVar10 = (uint *)&DAT_0000002c;
            }
            bVar3 = true;
            uVar5 = 0xc0000010;
            if ((int)*puVar10 < 0) {
              uVar5 = *puVar10;
            }
            uVar6 = uVar5;
            goto LAB_1c000c3f9;
          }
          if (iVar4 != 2) {
            if (iVar4 == 4) {
              uVar8 = PlExtpPepPrepareDevice((longlong)puVar2);
              uVar6 = (uint)uVar8;
            }
            else if (iVar4 == 5) {
              uVar8 = PlExtpPepRegisterDevice((longlong)puVar2);
              uVar6 = (uint)uVar8;
            }
            else if (iVar4 == 6) {
              uVar8 = PlExtpPepEnumerateDeviceNamespace((longlong)puVar2,(longlong)param_1);
              uVar6 = (uint)uVar8;
            }
            else {
              if (iVar4 != 7) {
                if (iVar4 != 8) goto LAB_1c000c355;
                uVar7 = PlExtpAcpiReflectObjects((longlong)puVar2,(longlong)param_1);
                uVar6 = (uint)uVar7;
                puVar10 = (uint *)((longlong)param_1 + 0xb4);
                if (iVar1 != 0) {
                  puVar10 = (uint *)&DAT_0000002c;
                }
                *puVar10 = uVar6;
                goto LAB_1c000c38e;
              }
              uVar7 = PlExtpPepQueryObjectInformation((longlong)puVar2,(longlong)param_1);
              uVar6 = (uint)uVar7;
            }
            goto LAB_1c000c2c9;
          }
          uVar5 = 0;
          bVar3 = true;
        }
        goto LAB_1c000c3f7;
      }
      uVar7 = PlExtpNotifyAcpiNewChildDevices((longlong)puVar2);
      uVar6 = (uint)uVar7;
LAB_1c000c2c9:
      puVar10 = (uint *)((longlong)param_1 + 0xb4);
      if (iVar1 != 0) {
        puVar10 = (uint *)&DAT_0000002c;
      }
      *puVar10 = uVar6;
LAB_1c000c38e:
      if (uVar6 == 0x103) {
        uVar7 = PlExtpPendRequest(param_1);
        uVar5 = (uint)uVar7;
        if (uVar5 != 0x103) {
          uVar6 = *(uint *)((longlong)param_1 + 0x74);
        }
      }
    }
    else {
      if (iVar4 == 10) {
        PlExtpPepUnregisterDevice((longlong)puVar2);
      }
      else if (iVar4 == 0xb) {
        PlExtpPepAbandonDevice((longlong)puVar2);
      }
      else if (iVar4 == 0xc) {
        if (*(int *)((longlong)param_1 + 0x14) == 0) {
          plVar9 = param_1 + 0x16;
          if (iVar1 != 0) {
            plVar9 = (longlong *)&DAT_00000028;
          }
          *(undefined1 *)plVar9 = 1;
        }
      }
      else {
        if (iVar4 != 0xd) {
          if (iVar4 == 0xe) {
            uVar8 = PlExtpPepQueryDeviceControlResources((longlong)puVar2,(longlong)param_1);
            uVar6 = (uint)uVar8;
          }
          else {
            if (iVar4 == 0xf) {
              uVar6 = PlExtpBiosToNtDeviceControlResources(puVar2,(longlong)param_1);
              goto LAB_1c000c2c9;
            }
            if (iVar4 != 0x10) {
LAB_1c000c355:
              uVar5 = 0xc0000001;
              uVar6 = 0xc0000001;
              goto LAB_1c000c3f9;
            }
            uVar6 = PlExtpPepNotifyTranslatedResources((longlong)puVar2,(longlong)param_1);
          }
          goto LAB_1c000c38e;
        }
        IoReleaseRemoveLockAndWaitEx(puVar2 + 0x78,0x78466550,0x20);
      }
LAB_1c000c3f7:
      uVar6 = 0;
    }
LAB_1c000c3f9:
    uStack_50 = CONCAT44(uStack_64,local_68);
    local_48 = uStack_60;
    local_58 = CONCAT44(uVar6,1);
    if (bVar11) {
      (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(puVar2 + 0x28));
    }
    if (uVar5 != 0xc0000016) {
      (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(puVar2 + 0x28));
      PlExtpDereferenceRequest((longlong)param_1);
      if (bVar3) {
        PlExtpCompleteRequestFinal(param_1);
      }
      return uVar5;
    }
  } while( true );
}



===== PlExtpProcessDiscoverDestroyParentRequest @ 1c000c4b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint PlExtpProcessDiscoverDestroyParentRequest(longlong *param_1,undefined8 *param_2)

{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined8 uVar6;
  undefined1 auStackY_88 [32];
  uint local_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined4 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_88;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x1e,
                     &WPP_a31fe4b5b02930fb8029abd8f99eeaaf_Traceguids);
  }
  uStack_54 = 0;
  uStack_50 = 0;
  bVar2 = false;
  local_58 = 0;
  if (param_2 == (undefined8 *)0x0) {
    uStack_40 = 0;
    local_38 = 0;
    local_48 = 0;
  }
  else {
    local_48 = *param_2;
    uStack_40 = param_2[1];
    local_38 = *(undefined4 *)(param_2 + 2);
  }
  LOCK();
  *(int *)((longlong)param_1 + 0x3c) = *(int *)((longlong)param_1 + 0x3c) + 1;
  UNLOCK();
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,param_1[5]);
  do {
    uVar4 = PlExtpDiscoverDestroyParentRequestStateTransition
                      ((longlong)param_1,(int *)&local_48,&local_58);
    uVar3 = local_58;
    bVar1 = 2 < local_58;
    if (bVar1) {
      (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,param_1[5]);
    }
    if (uVar3 == 0) {
LAB_1c000c616:
      iVar5 = 0;
    }
    else if (uVar3 == 1) {
      bVar2 = true;
      uVar4 = 0xc0000001;
      iVar5 = -0x3fffffff;
    }
    else {
      if (uVar3 == 2) {
        uVar4 = 0;
        bVar2 = true;
        goto LAB_1c000c616;
      }
      if (uVar3 == 0x16) {
        uVar6 = PlExtpCreateChildDeviceRequests((longlong)param_1);
        iVar5 = (int)uVar6;
LAB_1c000c5f1:
        if (iVar5 != 0x103) goto LAB_1c000c619;
      }
      else {
        if (uVar3 == 0x17) {
          uVar6 = PlExtpReadyChildDeviceRequests((longlong)param_1);
          iVar5 = (int)uVar6;
          goto LAB_1c000c5f1;
        }
        if (uVar3 != 0x18) {
          iVar5 = -0x3fffffff;
          uVar4 = 0xc0000001;
          goto LAB_1c000c619;
        }
        iVar5 = 0x103;
      }
      uVar6 = PlExtpPendRequest(param_1);
      uVar4 = (uint)uVar6;
      if (uVar4 != 0x103) {
        iVar5 = *(int *)((longlong)param_1 + 0x74);
      }
    }
LAB_1c000c619:
    uStack_40 = CONCAT44(uStack_54,local_58);
    local_38 = uStack_50;
    local_48 = CONCAT44(iVar5,1);
    if (bVar1) {
      (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,param_1[5]);
    }
    if (uVar4 != 0xc0000016) {
      (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,param_1[5]);
      PlExtpDereferenceRequest((longlong)param_1);
      if (bVar2) {
        PlExtpCompleteRequestFinal(param_1);
      }
      return uVar4;
    }
  } while( true );
}



===== PlExtpReadyChildDeviceRequests @ 1c000c6d8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 PlExtpReadyChildDeviceRequests(longlong param_1)

{
  undefined1 uVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  
  uVar1 = ExAcquireSpinLockExclusive(&PlExtRequestListLock);
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x28));
  puVar4 = (undefined8 *)(param_1 + 0x60);
  iVar2 = 0;
  for (puVar3 = (undefined8 *)*puVar4; puVar3 != puVar4; puVar3 = (undefined8 *)*puVar3) {
    *(undefined4 *)(puVar3 + -4) = 3;
    LOCK();
    *(int *)((longlong)puVar3 + -0x14) = *(int *)((longlong)puVar3 + -0x14) + 1;
    UNLOCK();
    PlExtpMoveRequestToTargetQueue(0x1c0016600,puVar3 + -10);
    iVar2 = iVar2 + 1;
  }
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x28));
  if (iVar2 != 0) {
    PlExtpScheduleWorkerLocked(iVar2);
  }
  ExReleaseSpinLockExclusive(&PlExtRequestListLock,uVar1);
  return 0;
}



===== WPP_RECORDER_SF_S @ 1c000c7a8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_S(undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
                      undefined8 param_5,wchar_t *param_6)

{
  longlong lVar1;
  wchar_t *pwVar2;
  longlong lVar3;
  longlong lVar4;
  ulonglong uVar5;
  
  lVar4 = -1;
  uVar5 = (ulonglong)(param_3 >> 0x10);
  lVar3 = 10;
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar5 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[uVar5 * 0x50 + 0x29])) {
    if (param_6 == (wchar_t *)0x0) {
      lVar1 = 10;
    }
    else {
      lVar1 = -1;
      do {
        lVar1 = lVar1 + 1;
      } while (param_6[lVar1] != L'\0');
      lVar1 = lVar1 * 2 + 2;
    }
    pwVar2 = param_6;
    if (param_6 == (wchar_t *)0x0) {
      pwVar2 = L"NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar5 * 0x50 + 0x18),0x2b,param_5,param_4,pwVar2
               ,lVar1,0);
  }
  if (param_6 != (wchar_t *)0x0) {
    do {
      lVar4 = lVar4 + 1;
    } while (param_6[lVar4] != L'\0');
    lVar3 = lVar4 * 2 + 2;
  }
  if (param_6 == (wchar_t *)0x0) {
    param_6 = L"NULL";
  }
  WppAutoLogTrace(param_1,4,param_3,param_5,param_4,param_6,lVar3,0);
  return;
}



===== WPP_RECORDER_SF_Sq @ 1c000c904 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_Sq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                       undefined8 param_5,wchar_t *param_6,undefined1 param_7)

{
  longlong lVar1;
  wchar_t *pwVar2;
  longlong lVar3;
  longlong lVar4;
  
  lVar4 = -1;
  lVar3 = 10;
  if (((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0') &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    if (param_6 == (wchar_t *)0x0) {
      lVar1 = 10;
    }
    else {
      lVar1 = -1;
      do {
        lVar1 = lVar1 + 1;
      } while (param_6[lVar1] != L'\0');
      lVar1 = lVar1 * 2 + 2;
    }
    pwVar2 = param_6;
    if (param_6 == (wchar_t *)0x0) {
      pwVar2 = L"NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_a31fe4b5b02930fb8029abd8f99eeaaf_Traceguids,param_4,pwVar2,lVar1,&param_7,8,0);
  }
  if (param_6 != (wchar_t *)0x0) {
    do {
      lVar4 = lVar4 + 1;
    } while (param_6[lVar4] != L'\0');
    lVar3 = lVar4 * 2 + 2;
  }
  if (param_6 == (wchar_t *)0x0) {
    param_6 = L"NULL";
  }
  WppAutoLogTrace(param_1,4,8,&WPP_a31fe4b5b02930fb8029abd8f99eeaaf_Traceguids,param_4,param_6,lVar3
                  ,&param_7,8,0);
  return;
}



===== WPP_RECORDER_SF_qD @ 1c000ca58 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qD(undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined8 uVar1;
  
  uVar1 = PlExtLogHandle;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,param_5,param_4,&param_6,8,&param_7,4
               ,0);
  }
  WppAutoLogTrace(uVar1,param_2,9,param_5,param_4,&param_6,8,&param_7,4,0);
  return;
}



===== WPP_RECORDER_SF_qqD @ 1c000cb40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqD(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                        undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,8,&param_7,8,&param_8,4,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,&param_6,8,&param_7,8,&param_8,4,0);
  return;
}



===== WPP_RECORDER_SF_qqDD @ 1c000cc90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqDD
               (undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
               undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,8,&param_7,8,&param_8,4,&param_9,4,0);
  }
  WppAutoLogTrace(param_1,2,param_3,param_5,param_4,&param_6,8,&param_7,8,&param_8,4,&param_9,4,0);
  return;
}



===== PlExtpAllocateMethodResources @ 1c000ce04 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int PlExtpAllocateMethodResources(longlong param_1)

{
  longlong lVar1;
  ulonglong uVar2;
  int iVar3;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x14,
                     &WPP_691b4491ef5f310687b9ddd4db0f5bab_Traceguids);
  }
  iVar3 = 0;
  lVar1 = *(longlong *)(param_1 + 0x20);
  if (*(char *)(param_1 + 0x148) == '\0') {
    *(undefined8 *)(param_1 + 0xd0) = *(undefined8 *)(param_1 + 0xb0);
    *(undefined8 *)(param_1 + 0xd8) = *(undefined8 *)(param_1 + 0xa8);
  }
  else {
    uVar2 = *(ulonglong *)(param_1 + 0xe0);
    if (*(ulonglong *)(param_1 + 0xd8) < uVar2) {
      iVar3 = (**(code **)(param_1 + 200))
                        (*(undefined8 *)(param_1 + 0xc0),*(undefined8 *)(param_1 + 0xb0),uVar2,
                         param_1 + 0xd0);
      if (iVar3 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_SDPqD(*(undefined8 *)(lVar1 + 0x98));
        }
      }
      else {
        *(ulonglong *)(param_1 + 0xd8) = uVar2;
      }
    }
    else {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_SDPPq(*(undefined8 *)(lVar1 + 0x98));
      }
      iVar3 = -0x3fffffff;
    }
  }
  return iVar3;
}



===== PlExtpProcessControlMethodCompletion @ 1c000cf6c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int PlExtpProcessControlMethodCompletion(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  int iVar3;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x18,
                     &WPP_691b4491ef5f310687b9ddd4db0f5bab_Traceguids);
  }
  if (*(longlong *)(param_1 + 0x10) == 0) {
    iVar3 = -0x3ffffff0;
  }
  else {
    lVar2 = WdfDriverGlobals;
    plVar1 = (longlong *)
             (**(code **)(WdfFunctions_01015 + 0x650))
                       (WdfDriverGlobals,*(longlong *)(param_1 + 0x10),
                        PTR__WDF_PLEXT_REQUEST_CONTEXT_TYPE_INFO_1c0016190);
    iVar3 = *(int *)(param_1 + 0xc);
    *(int *)(plVar1 + 0x21) = iVar3;
    if (iVar3 == -0x3fffffdd) {
      lVar2 = *(longlong *)(param_1 + 0x18);
      plVar1[0x1c] = lVar2;
    }
    PlExtpLogMethodEval(lVar2,plVar1[4],(longlong)(plVar1 + 0x1d),iVar3);
    PlExtpCompleteRequest(plVar1,iVar3);
  }
  return iVar3;
}



===== WPP_RECORDER_SF_SDD @ 1c000d044 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_SDD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4
                        ,undefined8 param_5,wchar_t *param_6,undefined1 param_7,undefined1 param_8)

{
  longlong lVar1;
  wchar_t *pwVar2;
  longlong lVar3;
  longlong lVar4;
  
  lVar4 = -1;
  lVar3 = 10;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    if (param_6 == (wchar_t *)0x0) {
      lVar1 = 10;
    }
    else {
      lVar1 = -1;
      do {
        lVar1 = lVar1 + 1;
      } while (param_6[lVar1] != L'\0');
      lVar1 = lVar1 * 2 + 2;
    }
    pwVar2 = param_6;
    if (param_6 == (wchar_t *)0x0) {
      pwVar2 = L"NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_691b4491ef5f310687b9ddd4db0f5bab_Traceguids,param_4,pwVar2,lVar1,&param_7,4,
               &param_8,4,0);
  }
  if (param_6 != (wchar_t *)0x0) {
    do {
      lVar4 = lVar4 + 1;
    } while (param_6[lVar4] != L'\0');
    lVar3 = lVar4 * 2 + 2;
  }
  if (param_6 == (wchar_t *)0x0) {
    param_6 = L"NULL";
  }
  WppAutoLogTrace(param_1,2,9,&WPP_691b4491ef5f310687b9ddd4db0f5bab_Traceguids,param_4,param_6,lVar3
                  ,&param_7,4,&param_8,4,0);
  return;
}



===== WPP_RECORDER_SF_SDDD @ 1c000d1c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_SDDD
               (undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,undefined8 param_5,
               wchar_t *param_6,undefined1 param_7,undefined1 param_8,undefined1 param_9)

{
  longlong lVar1;
  wchar_t *pwVar2;
  longlong lVar3;
  ulonglong uVar4;
  longlong lVar5;
  
  lVar5 = -1;
  uVar4 = (ulonglong)(param_3 >> 0x10);
  lVar3 = 10;
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar4 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar4 * 0x50 + 0x29])) {
    if (param_6 == (wchar_t *)0x0) {
      lVar1 = 10;
    }
    else {
      lVar1 = -1;
      do {
        lVar1 = lVar1 + 1;
      } while (param_6[lVar1] != L'\0');
      lVar1 = lVar1 * 2 + 2;
    }
    pwVar2 = param_6;
    if (param_6 == (wchar_t *)0x0) {
      pwVar2 = L"NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar4 * 0x50 + 0x18),0x2b,param_5,param_4,pwVar2
               ,lVar1,&param_7,4,&param_8,4,&param_9,4,0);
  }
  if (param_6 != (wchar_t *)0x0) {
    do {
      lVar5 = lVar5 + 1;
    } while (param_6[lVar5] != L'\0');
    lVar3 = lVar5 * 2 + 2;
  }
  if (param_6 == (wchar_t *)0x0) {
    param_6 = L"NULL";
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,param_6,lVar3,&param_7,4,&param_8,4,
                  &param_9,4,0);
  return;
}



===== WPP_RECORDER_SF_SDPPq @ 1c000d3a8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_SDPPq(undefined8 param_1)

{
  longlong lVar1;
  wchar_t *pwVar2;
  longlong lVar3;
  wchar_t *in_stack_00000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  
  lVar3 = -1;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    if (in_stack_00000030 == (wchar_t *)0x0) {
      lVar1 = 10;
    }
    else {
      lVar1 = -1;
      do {
        lVar1 = lVar1 + 1;
      } while (in_stack_00000030[lVar1] != L'\0');
      lVar1 = lVar1 * 2 + 2;
    }
    pwVar2 = in_stack_00000030;
    if (in_stack_00000030 == (wchar_t *)0x0) {
      pwVar2 = L"NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_691b4491ef5f310687b9ddd4db0f5bab_Traceguids,0x15,pwVar2,lVar1,
               &uStack0000000000000038,4,&uStack0000000000000040,8,&uStack0000000000000048,8,
               &uStack0000000000000050,8,0);
  }
  if (in_stack_00000030 == (wchar_t *)0x0) {
    lVar3 = 10;
  }
  else {
    do {
      lVar3 = lVar3 + 1;
    } while (in_stack_00000030[lVar3] != L'\0');
    lVar3 = lVar3 * 2 + 2;
  }
  if (in_stack_00000030 == (wchar_t *)0x0) {
    in_stack_00000030 = L"NULL";
  }
  WppAutoLogTrace(param_1,2,10,&WPP_691b4491ef5f310687b9ddd4db0f5bab_Traceguids,0x15,
                  in_stack_00000030,lVar3,&uStack0000000000000038,4,&uStack0000000000000040,8,
                  &uStack0000000000000048,8,&uStack0000000000000050,8,0);
  return;
}



===== WPP_RECORDER_SF_SDPqD @ 1c000d578 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_SDPqD(undefined8 param_1)

{
  longlong lVar1;
  wchar_t *pwVar2;
  longlong lVar3;
  wchar_t *in_stack_00000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  
  lVar3 = -1;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    if (in_stack_00000030 == (wchar_t *)0x0) {
      lVar1 = 10;
    }
    else {
      lVar1 = -1;
      do {
        lVar1 = lVar1 + 1;
      } while (in_stack_00000030[lVar1] != L'\0');
      lVar1 = lVar1 * 2 + 2;
    }
    pwVar2 = in_stack_00000030;
    if (in_stack_00000030 == (wchar_t *)0x0) {
      pwVar2 = L"NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_691b4491ef5f310687b9ddd4db0f5bab_Traceguids,0x16,pwVar2,lVar1,
               &uStack0000000000000038,4,&uStack0000000000000040,8,&uStack0000000000000048,8,
               &uStack0000000000000050,4,0);
  }
  if (in_stack_00000030 == (wchar_t *)0x0) {
    lVar3 = 10;
  }
  else {
    do {
      lVar3 = lVar3 + 1;
    } while (in_stack_00000030[lVar3] != L'\0');
    lVar3 = lVar3 * 2 + 2;
  }
  if (in_stack_00000030 == (wchar_t *)0x0) {
    in_stack_00000030 = L"NULL";
  }
  WppAutoLogTrace(param_1,2,10,&WPP_691b4491ef5f310687b9ddd4db0f5bab_Traceguids,0x16,
                  in_stack_00000030,lVar3,&uStack0000000000000038,4,&uStack0000000000000040,8,
                  &uStack0000000000000048,8,&uStack0000000000000050,4,0);
  return;
}



===== WPP_RECORDER_SF_qDD @ 1c000d750 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qDD(void)

{
  undefined8 uVar1;
  undefined2 in_R9W;
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  uVar1 = PlExtLogHandle;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_691b4491ef5f310687b9ddd4db0f5bab_Traceguids,in_R9W,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,4,0);
  }
  WppAutoLogTrace(uVar1,2,9,&WPP_691b4491ef5f310687b9ddd4db0f5bab_Traceguids,in_R9W,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,4,0);
  return;
}



===== PlExtpPepAbandonDevice @ 1c000d84c =====

void PlExtpPepAbandonDevice(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  longlong local_68 [2];
  int local_58 [2];
  undefined8 local_50;
  undefined4 local_48;
  longlong *local_38;
  undefined8 local_30;
  undefined8 local_20;
  
  local_58[1] = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x11,
                     &WPP_a3b1741888e13d4a1c14bd4949ad3719_Traceguids);
  }
  local_68[1] = 0;
  local_68[0] = param_1 + 0x10;
  lVar2 = 0x50;
  memset(local_58,0,0x50);
  local_50 = PlExtPoFxRequestContext;
  local_38 = local_68;
  local_48 = 2;
  local_20 = *(undefined8 *)(param_1 + 0x50);
  local_30 = 0x10;
  lVar1 = param_1;
  PlExtpInvokePoFxRequestHandler(local_58,param_1,lVar2);
  LOCK();
  *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) & 0xfffffffe;
  UNLOCK();
  *(undefined8 *)(param_1 + 0x50) = 0;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_S(*(undefined8 *)(param_1 + 0x98),lVar1,10,0x12,
                      &WPP_a3b1741888e13d4a1c14bd4949ad3719_Traceguids,*(wchar_t **)(param_1 + 0x18)
                     );
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x13,
                       &WPP_a3b1741888e13d4a1c14bd4949ad3719_Traceguids);
    }
  }
  return;
}



===== PlExtpPepEnumerateDeviceNamespace @ 1c000d98c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong PlExtpPepEnumerateDeviceNamespace(longlong param_1,longlong param_2)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  longlong lVar4;
  int iVar5;
  ulonglong uVar6;
  undefined8 *puVar7;
  longlong lVar8;
  longlong lVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  undefined1 auStackY_118 [32];
  undefined *in_stack_ffffffffffffff08;
  undefined1 uVar13;
  undefined1 uVar14;
  undefined1 uVar15;
  int local_b8 [2];
  undefined8 local_b0;
  undefined4 local_a8;
  undefined8 local_a0;
  undefined8 *local_98;
  longlong local_90;
  undefined8 local_68;
  ulonglong local_60;
  ulonglong uStack_58;
  undefined8 local_50;
  undefined8 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_118;
  local_b8[1] = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_stack_ffffffffffffff08 = &WPP_a3b1741888e13d4a1c14bd4949ad3719_Traceguids;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x14,
                     &WPP_a3b1741888e13d4a1c14bd4949ad3719_Traceguids);
  }
  local_68 = *(undefined8 *)(param_1 + 0x48);
  local_48 = 0;
  puVar7 = (undefined8 *)0x0;
  local_50 = 8;
  iVar11 = 0;
  iVar10 = 0;
  lVar8 = 0x50;
  local_60 = 0;
  uStack_58 = 0;
  memset(local_b8,0,0x50);
  local_b0 = PlExtPoFxRequestContext;
  local_98 = &local_68;
  local_a8 = 5;
  local_a0 = *(undefined8 *)(param_1 + 0x40);
  local_90 = 0x28;
  uVar3 = PlExtpInvokePoFxRequestHandler(local_b8,param_1,lVar8);
  uVar2 = uStack_58;
  if (-1 < (int)uVar3) {
    uVar3 = local_60 >> 0x20;
  }
  iVar5 = (int)uVar3;
  if (iVar5 == 0x103) {
    return 0xc0000001;
  }
  uVar12 = (uint)uStack_58;
  if (((iVar5 < 0) || (1 < uVar12)) && (iVar5 != -0x3fffffdd)) {
    if (iVar5 < 0) {
      return uVar3 & 0xffffffff;
    }
    return 0xc0000001;
  }
  if (uVar12 != 0) {
    lVar8 = (ulonglong)(uVar12 - 1) * 8 + 0x28;
    puVar7 = (undefined8 *)ExAllocatePool2(0x40,lVar8,0x78466550);
    uVar13 = (undefined1)param_1;
    uVar14 = (undefined1)param_2;
    if (puVar7 == (undefined8 *)0x0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return 0xc000009a;
      }
      WPP_RECORDER_SF_qqD(*(undefined8 *)(param_1 + 0x98),2,10,0x15,
                          &WPP_a3b1741888e13d4a1c14bd4949ad3719_Traceguids,uVar13,uVar14,0x9a);
      return 0xc000009a;
    }
    *puVar7 = *(undefined8 *)(param_1 + 0x48);
    puVar7[3] = (uVar2 & 0xffffffff) << 3;
    if ((int)uStack_58 != 1) {
      lVar9 = 0x50;
      memset(local_b8,0,0x50);
      local_b0 = PlExtPoFxRequestContext;
      local_a0 = *(undefined8 *)(param_1 + 0x40);
      local_a8 = 5;
      lVar4 = param_1;
      local_98 = puVar7;
      local_90 = lVar8;
      uVar3 = PlExtpInvokePoFxRequestHandler(local_b8,param_1,lVar9);
      uVar6 = uVar3 & 0xffffffff;
      if (-1 < (int)uVar3) {
        uVar1 = *(uint *)((longlong)puVar7 + 0xc);
        uVar6 = (ulonglong)uVar1;
        if (-1 < (int)uVar1) {
          if (uVar1 == 0x103) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_qq(*(undefined8 *)(param_1 + 0x98),lVar4,&WPP_RECORDER_INITIALIZED,
                                 0x17,in_stack_ffffffffffffff08,uVar13,uVar14);
            }
          }
          else {
            uVar15 = (undefined1)uVar2;
            if (*(uint *)(puVar7 + 2) == uVar12) {
              for (uVar3 = 0; (uint)uVar3 < uVar12; uVar3 = (ulonglong)((uint)uVar3 + 1)) {
                iVar5 = *(int *)((longlong)puVar7 + uVar3 * 8 + 0x24);
                if (iVar5 == 0) {
                  iVar10 = iVar10 + 1;
                }
                else {
                  if (iVar5 != 1) {
                    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                      WPP_RECORDER_SF_qqDDD(*(undefined8 *)(param_1 + 0x98));
                    }
                    goto LAB_1c000dbe0;
                  }
                  iVar11 = iVar11 + 1;
                }
              }
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_Sd(*(undefined8 *)(param_1 + 0x98),4,10,0x1a,
                                   &WPP_a3b1741888e13d4a1c14bd4949ad3719_Traceguids,
                                   *(wchar_t **)(param_1 + 0x18),uVar15);
              }
              goto LAB_1c000dd44;
            }
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_qqDD
                        (*(undefined8 *)(param_1 + 0x98),lVar4,10,0x18,
                         &WPP_a3b1741888e13d4a1c14bd4949ad3719_Traceguids,uVar13,uVar14,
                         (char)*(uint *)(puVar7 + 2),uVar15);
            }
          }
LAB_1c000dbe0:
          uVar6 = 0xc0000001;
          goto LAB_1c000dd2a;
        }
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qqD(*(undefined8 *)(param_1 + 0x98),2,10,0x16,
                            &WPP_a3b1741888e13d4a1c14bd4949ad3719_Traceguids,uVar13,uVar14,
                            (char)uVar6);
      }
      if ((int)uVar6 < 0) {
LAB_1c000dd2a:
        ExFreePoolWithTag(puVar7,0x78466550);
        return uVar6;
      }
      iVar10 = 0;
      goto LAB_1c000dd44;
    }
    *(undefined4 *)(puVar7 + 2) = 1;
    puVar7[4] = local_48;
  }
  uVar6 = 0;
LAB_1c000dd44:
  *(undefined8 **)(param_2 + 0x90) = puVar7;
  *(uint *)(param_1 + 0x60) = uVar12;
  *(int *)(param_1 + 0x70) = iVar10;
  *(int *)(param_1 + 0x74) = iVar11;
  return uVar6;
}



===== PlExtpPepNotifyTranslatedResources @ 1c000dd88 =====

undefined4 PlExtpPepNotifyTranslatedResources(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined4 uVar2;
  ulonglong uVar3;
  longlong lVar4;
  undefined8 local_78;
  undefined4 local_70;
  int local_6c;
  ulonglong local_68;
  longlong local_60;
  int local_58 [2];
  undefined8 local_50;
  undefined4 local_48;
  undefined8 local_40;
  undefined8 *local_38;
  undefined8 local_30;
  
  local_58[1] = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x27,
                     &WPP_a3b1741888e13d4a1c14bd4949ad3719_Traceguids);
  }
  local_6c = *(int *)(param_2 + 0xb4);
  lVar1 = *(longlong *)(param_2 + 0xa8);
  if ((local_6c < 0) || (lVar1 != 0)) {
    local_78 = *(undefined8 *)(param_1 + 0x48);
    local_68 = (ulonglong)*(uint *)(param_2 + 0xa0);
    lVar4 = 0x50;
    local_70 = 0;
    local_60 = lVar1;
    memset(local_58,0,0x50);
    local_50 = PlExtPoFxRequestContext;
    local_38 = &local_78;
    local_48 = 9;
    local_40 = *(undefined8 *)(param_1 + 0x40);
    local_30 = 0x20;
    uVar3 = PlExtpInvokePoFxRequestHandler(local_58,param_1,lVar4);
    uVar2 = (undefined4)uVar3;
    if (lVar1 != 0) {
      ExFreePoolWithTag(lVar1,0x78466550);
      *(undefined8 *)(param_2 + 0xa8) = 0;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



===== PlExtpPepPrepareDevice @ 1c000debc =====

ulonglong PlExtpPepPrepareDevice(longlong param_1)

{
  ulonglong uVar1;
  longlong lVar2;
  longlong local_88;
  undefined4 local_80;
  undefined8 local_7c;
  undefined4 local_74;
  int local_68 [2];
  undefined8 local_60;
  undefined4 local_58;
  longlong *local_48;
  undefined8 local_40;
  char local_38;
  undefined8 local_30;
  char local_28;
  
  local_68[1] = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,10,
                     &WPP_a3b1741888e13d4a1c14bd4949ad3719_Traceguids);
  }
  local_7c = 0;
  local_88 = param_1 + 0x10;
  local_74 = 0;
  local_80 = 0;
  lVar2 = 0x50;
  memset(local_68,0,0x50);
  local_60 = PlExtPoFxRequestContext;
  local_48 = &local_88;
  local_58 = 1;
  local_40 = 0x18;
  uVar1 = PlExtpInvokePoFxRequestHandler(local_68,param_1,lVar2);
  if (((-1 < (int)uVar1) && (local_38 != '\0')) && (local_28 != '\0')) {
    LOCK();
    *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 1;
    UNLOCK();
    *(undefined8 *)(param_1 + 0x50) = local_30;
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_Sd(*(undefined8 *)(param_1 + 0x98),4,10,0xb,
                       &WPP_a3b1741888e13d4a1c14bd4949ad3719_Traceguids,
                       *(wchar_t **)(param_1 + 0x18),local_28);
  }
  return uVar1 & 0xffffffff;
}



===== PlExtpPepQueryDeviceControlResources @ 1c000dfec =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong PlExtpPepQueryDeviceControlResources(longlong param_1,longlong param_2)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  longlong lVar4;
  int iVar5;
  ulonglong uVar6;
  undefined8 *puVar7;
  longlong lVar8;
  longlong lVar9;
  undefined2 uVar10;
  undefined1 auStackY_108 [32];
  undefined *in_stack_ffffffffffffff18;
  undefined1 uVar11;
  undefined1 uVar12;
  int local_b8 [2];
  undefined8 local_b0;
  undefined4 local_a8;
  undefined8 local_a0;
  undefined8 *local_98;
  longlong local_90;
  undefined8 local_60;
  ulonglong local_58;
  ulonglong local_50;
  undefined8 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_108;
  local_b8[1] = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_stack_ffffffffffffff18 = &WPP_a3b1741888e13d4a1c14bd4949ad3719_Traceguids;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x1f,
                     &WPP_a3b1741888e13d4a1c14bd4949ad3719_Traceguids);
  }
  local_60 = *(undefined8 *)(param_1 + 0x48);
  local_58 = 0;
  local_48 = 0;
  puVar7 = (undefined8 *)0x0;
  local_50 = 8;
  lVar8 = 0x50;
  memset(local_b8,0,0x50);
  local_b0 = PlExtPoFxRequestContext;
  local_98 = &local_60;
  local_a8 = 8;
  local_a0 = *(undefined8 *)(param_1 + 0x40);
  local_90 = 0x20;
  uVar3 = PlExtpInvokePoFxRequestHandler(local_b8,param_1,lVar8);
  uVar2 = local_50;
  if (-1 < (int)uVar3) {
    uVar3 = local_58 >> 0x20;
  }
  uVar6 = uVar3 & 0xffffffff;
  iVar5 = (int)uVar3;
  if (iVar5 != 0x103) {
    if (iVar5 == -0x3fffffdd) {
      if (local_50 < 9) {
        return 0xc0000001;
      }
    }
    else if ((-1 < iVar5) && (local_50 == 0)) goto LAB_1c000e35c;
  }
  lVar8 = local_50 + 0x18;
  puVar7 = (undefined8 *)ExAllocatePool2(0x100,lVar8,0x78466550);
  uVar11 = (undefined1)param_1;
  uVar12 = (undefined1)param_2;
  if (puVar7 == (undefined8 *)0x0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0xc000009a;
    }
    WPP_RECORDER_SF_qqD(*(undefined8 *)(param_1 + 0x98),2,10,0x20,
                        &WPP_a3b1741888e13d4a1c14bd4949ad3719_Traceguids,uVar11,uVar12,0x9a);
    return 0xc000009a;
  }
  *puVar7 = *(undefined8 *)(param_1 + 0x48);
  puVar7[2] = uVar2;
  lVar9 = 0x50;
  memset(local_b8,0,0x50);
  local_b0 = PlExtPoFxRequestContext;
  local_a0 = *(undefined8 *)(param_1 + 0x40);
  local_a8 = 8;
  lVar4 = param_1;
  local_98 = puVar7;
  local_90 = lVar8;
  uVar3 = PlExtpInvokePoFxRequestHandler(local_b8,param_1,lVar9);
  uVar6 = uVar3 & 0xffffffff;
  if (-1 < (int)uVar3) {
    uVar1 = *(uint *)((longlong)puVar7 + 0xc);
    uVar6 = (ulonglong)uVar1;
    if (-1 < (int)uVar1) {
      if (uVar1 == 0x103) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qq(*(undefined8 *)(param_1 + 0x98),lVar4,lVar9,0x22,
                             in_stack_ffffffffffffff18,uVar11,uVar12);
        }
      }
      else {
        uVar3 = puVar7[2];
        if ((uVar2 < uVar3) || (uVar3 - 1 < 7)) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar10 = 0x23;
LAB_1c000e26d:
            WPP_RECORDER_SF_qqPP
                      (*(undefined8 *)(param_1 + 0x98),lVar4,lVar9,uVar10,in_stack_ffffffffffffff18,
                       uVar11,uVar12,(char)uVar2,(char)uVar3);
          }
        }
        else {
          if (*(ushort *)((longlong)puVar7 + 0x1a) < uVar3) {
            if ((uVar3 == 0) || (*(ushort *)((longlong)puVar7 + 0x1a) == 0)) {
              uVar6 = 0;
              goto LAB_1c000e35c;
            }
            if (*(short *)(puVar7 + 3) == 2) goto LAB_1c000e35c;
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_qqD(*(undefined8 *)(param_1 + 0x98),2,10,0x25,
                                  &WPP_a3b1741888e13d4a1c14bd4949ad3719_Traceguids,uVar11,uVar12,
                                  (char)*(short *)(puVar7 + 3));
            }
            uVar6 = 0xc014000f;
            goto LAB_1c000e1fc;
          }
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar10 = 0x24;
            goto LAB_1c000e26d;
          }
        }
      }
      uVar6 = 0xc0000001;
      goto LAB_1c000e1fc;
    }
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qqD(*(undefined8 *)(param_1 + 0x98),2,10,0x21,
                        &WPP_a3b1741888e13d4a1c14bd4949ad3719_Traceguids,uVar11,uVar12,(char)uVar6);
  }
  if (-1 < (int)uVar6) {
LAB_1c000e35c:
    *(undefined8 **)(param_2 + 0x98) = puVar7;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return uVar6;
    }
    WPP_RECORDER_SF_SP(*(undefined8 *)(param_1 + 0x98));
    return uVar6;
  }
LAB_1c000e1fc:
  ExFreePoolWithTag(puVar7,0x78466550);
  return uVar6;
}



===== PlExtpPepQueryObjectInformation @ 1c000e3a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 PlExtpPepQueryObjectInformation(longlong param_1,longlong param_2)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  uint uVar5;
  undefined8 uVar6;
  int *piVar7;
  longlong lVar8;
  int *piVar9;
  undefined1 auStackY_118 [32];
  int local_b8 [2];
  undefined8 local_b0;
  undefined4 local_a8;
  undefined8 local_a0;
  undefined8 *local_98;
  undefined8 local_90;
  char local_88;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_118;
  local_b8[1] = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  memset(local_b8,0,0x4c);
  uVar5 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x1b,
                     &WPP_a3b1741888e13d4a1c14bd4949ad3719_Traceguids);
  }
  uVar1 = *(uint *)(param_1 + 0x60);
  lVar2 = *(longlong *)(param_2 + 0x90);
  lVar3 = ExAllocatePool2(0x40,(ulonglong)uVar1 * 0x28,0x78466550);
  if (lVar3 == 0) {
    uVar6 = 0xc000009a;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qqD(*(undefined8 *)(param_1 + 0x98),2,10,0x1c,
                          &WPP_a3b1741888e13d4a1c14bd4949ad3719_Traceguids,(char)param_1,
                          (char)param_2,0x9a);
    }
  }
  else {
    lVar8 = 0x50;
    memset(local_b8,0,0x50);
    local_b0 = PlExtPoFxRequestContext;
    local_98 = &local_68;
    local_a0 = *(undefined8 *)(param_1 + 0x40);
    local_a8 = 6;
    local_90 = 0x20;
    if (uVar1 != 0) {
      piVar7 = (int *)(lVar3 + 0xc);
      piVar9 = (int *)(lVar2 + 0x24);
      do {
        piVar7[-1] = piVar9[-1];
        *piVar7 = *piVar9;
        local_68 = *(undefined8 *)(param_1 + 0x48);
        local_58 = 0;
        uStack_50 = 0;
        uStack_60 = CONCAT44(*piVar7,piVar7[-1]);
        local_88 = '\0';
        if (*piVar7 == 0) {
          uVar4 = PlExtpInvokePoFxRequestHandler(local_b8,param_1,lVar8);
          if (((int)uVar4 < 0) || (local_88 == '\0')) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_SDd(*(undefined8 *)(param_1 + 0x98));
            }
          }
          else {
            piVar7[1] = (int)local_58;
            piVar7[2] = local_58._4_4_;
            piVar7[3] = (int)uStack_50;
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_SDdd(*(undefined8 *)(param_1 + 0x98));
            }
          }
        }
        uVar5 = uVar5 + 1;
        piVar9 = piVar9 + 2;
        piVar7 = piVar7 + 10;
      } while (uVar5 < uVar1);
    }
    *(longlong *)(param_1 + 0x68) = lVar3;
    uVar6 = 0;
  }
  ExFreePoolWithTag(lVar2,0x78466550);
  *(undefined8 *)(param_2 + 0x90) = 0;
  return uVar6;
}



===== PlExtpPepRegisterDevice @ 1c000e63c =====

ulonglong PlExtpPepRegisterDevice(longlong param_1)

{
  ulonglong uVar1;
  longlong lVar2;
  longlong lVar3;
  undefined *in_stack_ffffffffffffff58;
  longlong local_88;
  undefined4 local_80;
  undefined8 local_7c;
  undefined8 uStack_74;
  undefined8 local_6c;
  undefined4 local_64;
  int local_58 [2];
  undefined8 local_50;
  undefined4 local_48;
  longlong *local_38;
  undefined8 local_30;
  char local_28;
  undefined8 local_20;
  undefined8 local_18;
  longlong local_10;
  
  local_58[1] = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_stack_ffffffffffffff58 = &WPP_a3b1741888e13d4a1c14bd4949ad3719_Traceguids;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0xc,
                     &WPP_a3b1741888e13d4a1c14bd4949ad3719_Traceguids);
  }
  local_6c = 0;
  local_64 = 0;
  local_88 = param_1 + 0x10;
  local_80 = 0;
  lVar3 = 0x50;
  local_7c = 0;
  uStack_74 = 0;
  memset(local_58,0,0x50);
  local_50 = PlExtPoFxRequestContext;
  local_38 = &local_88;
  local_48 = 3;
  local_20 = *(undefined8 *)(param_1 + 0x50);
  local_30 = 0x28;
  lVar2 = param_1;
  uVar1 = PlExtpInvokePoFxRequestHandler(local_58,param_1,lVar3);
  if (((-1 < (int)uVar1) && (local_28 != '\0')) && (local_10 != 0)) {
    LOCK();
    *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 2;
    UNLOCK();
    *(undefined8 *)(param_1 + 0x40) = local_18;
    *(longlong *)(param_1 + 0x48) = local_10;
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_Sqq(*(undefined8 *)(param_1 + 0x98),lVar2,lVar3,0xd,in_stack_ffffffffffffff58,
                        *(wchar_t **)(param_1 + 0x18),(char)local_18,(char)local_10);
  }
  return uVar1 & 0xffffffff;
}



===== PlExtpPepUnregisterDevice @ 1c000e788 =====

void PlExtpPepUnregisterDevice(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  undefined *in_stack_ffffffffffffff78;
  undefined8 local_68;
  undefined8 local_60;
  int local_58 [2];
  undefined8 local_50;
  undefined4 local_48;
  undefined8 local_40;
  undefined8 *local_38;
  undefined8 local_30;
  
  local_58[1] = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_stack_ffffffffffffff78 = &WPP_a3b1741888e13d4a1c14bd4949ad3719_Traceguids;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0xe,
                     &WPP_a3b1741888e13d4a1c14bd4949ad3719_Traceguids);
  }
  local_68 = *(undefined8 *)(param_1 + 0x48);
  local_60 = 0;
  lVar2 = 0x50;
  memset(local_58,0,0x50);
  local_50 = PlExtPoFxRequestContext;
  local_38 = &local_68;
  local_48 = 4;
  local_40 = *(undefined8 *)(param_1 + 0x40);
  local_30 = 0x10;
  lVar1 = param_1;
  PlExtpInvokePoFxRequestHandler(local_58,param_1,lVar2);
  LOCK();
  *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) & 0xfffffffd;
  UNLOCK();
  *(undefined8 *)(param_1 + 0x40) = 0;
  *(undefined8 *)(param_1 + 0x48) = 0;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_Sqq(*(undefined8 *)(param_1 + 0x98),lVar1,lVar2,0xf,in_stack_ffffffffffffff78,
                        *(wchar_t **)(param_1 + 0x18),0,0);
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x10,
                       &WPP_a3b1741888e13d4a1c14bd4949ad3719_Traceguids);
    }
  }
  return;
}



===== WPP_RECORDER_SF_SDd @ 1c000e8d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_SDd(undefined8 param_1)

{
  longlong lVar1;
  wchar_t *pwVar2;
  longlong lVar3;
  wchar_t *in_stack_00000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  lVar3 = -1;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    if (in_stack_00000030 == (wchar_t *)0x0) {
      lVar1 = 10;
    }
    else {
      lVar1 = -1;
      do {
        lVar1 = lVar1 + 1;
      } while (in_stack_00000030[lVar1] != L'\0');
      lVar1 = lVar1 * 2 + 2;
    }
    pwVar2 = in_stack_00000030;
    if (in_stack_00000030 == (wchar_t *)0x0) {
      pwVar2 = L"NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_a3b1741888e13d4a1c14bd4949ad3719_Traceguids,0x1e,pwVar2,lVar1,
               &uStack0000000000000038,4,&uStack0000000000000040,4,0);
  }
  if (in_stack_00000030 == (wchar_t *)0x0) {
    lVar3 = 10;
  }
  else {
    do {
      lVar3 = lVar3 + 1;
    } while (in_stack_00000030[lVar3] != L'\0');
    lVar3 = lVar3 * 2 + 2;
  }
  if (in_stack_00000030 == (wchar_t *)0x0) {
    in_stack_00000030 = L"NULL";
  }
  WppAutoLogTrace(param_1,2,10,&WPP_a3b1741888e13d4a1c14bd4949ad3719_Traceguids,0x1e,
                  in_stack_00000030,lVar3,&uStack0000000000000038,4,&uStack0000000000000040,4,0);
  return;
}



===== WPP_RECORDER_SF_SDdd @ 1c000ea50 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_SDdd(undefined8 param_1)

{
  longlong lVar1;
  wchar_t *pwVar2;
  longlong lVar3;
  wchar_t *in_stack_00000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  
  lVar3 = -1;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    if (in_stack_00000030 == (wchar_t *)0x0) {
      lVar1 = 10;
    }
    else {
      lVar1 = -1;
      do {
        lVar1 = lVar1 + 1;
      } while (in_stack_00000030[lVar1] != L'\0');
      lVar1 = lVar1 * 2 + 2;
    }
    pwVar2 = in_stack_00000030;
    if (in_stack_00000030 == (wchar_t *)0x0) {
      pwVar2 = L"NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_a3b1741888e13d4a1c14bd4949ad3719_Traceguids,0x1d,pwVar2,lVar1,
               &uStack0000000000000038,4,&uStack0000000000000040,4,&uStack0000000000000048,4,0);
  }
  if (in_stack_00000030 == (wchar_t *)0x0) {
    lVar3 = 10;
  }
  else {
    do {
      lVar3 = lVar3 + 1;
    } while (in_stack_00000030[lVar3] != L'\0');
    lVar3 = lVar3 * 2 + 2;
  }
  if (in_stack_00000030 == (wchar_t *)0x0) {
    in_stack_00000030 = L"NULL";
  }
  WppAutoLogTrace(param_1,4,10,&WPP_a3b1741888e13d4a1c14bd4949ad3719_Traceguids,0x1d,
                  in_stack_00000030,lVar3,&uStack0000000000000038,4,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,0);
  return;
}



===== WPP_RECORDER_SF_SP @ 1c000ebf4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_SP(undefined8 param_1)

{
  longlong lVar1;
  wchar_t *pwVar2;
  longlong lVar3;
  wchar_t *in_stack_00000030;
  undefined1 uStack0000000000000038;
  
  lVar3 = -1;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    if (in_stack_00000030 == (wchar_t *)0x0) {
      lVar1 = 10;
    }
    else {
      lVar1 = -1;
      do {
        lVar1 = lVar1 + 1;
      } while (in_stack_00000030[lVar1] != L'\0');
      lVar1 = lVar1 * 2 + 2;
    }
    pwVar2 = in_stack_00000030;
    if (in_stack_00000030 == (wchar_t *)0x0) {
      pwVar2 = L"NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_a3b1741888e13d4a1c14bd4949ad3719_Traceguids,0x26,pwVar2,lVar1,
               &uStack0000000000000038,8,0);
  }
  if (in_stack_00000030 == (wchar_t *)0x0) {
    lVar3 = 10;
  }
  else {
    do {
      lVar3 = lVar3 + 1;
    } while (in_stack_00000030[lVar3] != L'\0');
    lVar3 = lVar3 * 2 + 2;
  }
  if (in_stack_00000030 == (wchar_t *)0x0) {
    in_stack_00000030 = L"NULL";
  }
  WppAutoLogTrace(param_1,4,10,&WPP_a3b1741888e13d4a1c14bd4949ad3719_Traceguids,0x26,
                  in_stack_00000030,lVar3,&uStack0000000000000038,8,0);
  return;
}



===== WPP_RECORDER_SF_Sd @ 1c000ed44 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_Sd(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                       undefined8 param_5,wchar_t *param_6,undefined1 param_7)

{
  longlong lVar1;
  wchar_t *pwVar2;
  longlong lVar3;
  ulonglong uVar4;
  longlong lVar5;
  
  lVar5 = -1;
  uVar4 = (ulonglong)(param_3 >> 0x10);
  lVar3 = 10;
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar4 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar4 * 0x50 + 0x29])) {
    if (param_6 == (wchar_t *)0x0) {
      lVar1 = 10;
    }
    else {
      lVar1 = -1;
      do {
        lVar1 = lVar1 + 1;
      } while (param_6[lVar1] != L'\0');
      lVar1 = lVar1 * 2 + 2;
    }
    pwVar2 = param_6;
    if (param_6 == (wchar_t *)0x0) {
      pwVar2 = L"NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar4 * 0x50 + 0x18),0x2b,param_5,param_4,pwVar2
               ,lVar1,&param_7,4,0);
  }
  if (param_6 != (wchar_t *)0x0) {
    do {
      lVar5 = lVar5 + 1;
    } while (param_6[lVar5] != L'\0');
    lVar3 = lVar5 * 2 + 2;
  }
  if (param_6 == (wchar_t *)0x0) {
    param_6 = L"NULL";
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,param_6,lVar3,&param_7,4,0);
  return;
}



===== WPP_RECORDER_SF_Sqq @ 1c000eed8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_Sqq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4
                        ,undefined8 param_5,wchar_t *param_6,undefined1 param_7,undefined1 param_8)

{
  longlong lVar1;
  wchar_t *pwVar2;
  longlong lVar3;
  
  lVar3 = -1;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    if (param_6 == (wchar_t *)0x0) {
      lVar1 = 10;
    }
    else {
      lVar1 = -1;
      do {
        lVar1 = lVar1 + 1;
      } while (param_6[lVar1] != L'\0');
      lVar1 = lVar1 * 2 + 2;
    }
    pwVar2 = param_6;
    if (param_6 == (wchar_t *)0x0) {
      pwVar2 = L"NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_a3b1741888e13d4a1c14bd4949ad3719_Traceguids,param_4,pwVar2,lVar1,&param_7,8,
               &param_8,8,0);
  }
  if (param_6 == (wchar_t *)0x0) {
    lVar3 = 10;
  }
  else {
    do {
      lVar3 = lVar3 + 1;
    } while (param_6[lVar3] != L'\0');
    lVar3 = lVar3 * 2 + 2;
  }
  if (param_6 == (wchar_t *)0x0) {
    param_6 = L"NULL";
  }
  WppAutoLogTrace(param_1,4,10,&WPP_a3b1741888e13d4a1c14bd4949ad3719_Traceguids,param_4,param_6,
                  lVar3,&param_7,8,&param_8,8,0);
  return;
}



===== WPP_RECORDER_SF_qq @ 1c000f05c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_a3b1741888e13d4a1c14bd4949ad3719_Traceguids,param_4,&param_6,8,&param_7,8,0);
  }
  WppAutoLogTrace(param_1,2,10,&WPP_a3b1741888e13d4a1c14bd4949ad3719_Traceguids,param_4,&param_6,8,
                  &param_7,8,0);
  return;
}



===== WPP_RECORDER_SF_qqDDD @ 1c000f130 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqDDD(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_a3b1741888e13d4a1c14bd4949ad3719_Traceguids,0x19,&uStack0000000000000030,8,
               &uStack0000000000000038,8,&uStack0000000000000040,4,&uStack0000000000000048,4,
               &uStack0000000000000050,4,0);
  }
  WppAutoLogTrace(param_1,2,10,&WPP_a3b1741888e13d4a1c14bd4949ad3719_Traceguids,0x19,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,0);
  return;
}



===== WPP_RECORDER_SF_qqPP @ 1c000f270 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqPP
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_a3b1741888e13d4a1c14bd4949ad3719_Traceguids,param_4,&param_6,8,&param_7,8,
               &param_8,8,&param_9,8,0);
  }
  WppAutoLogTrace(param_1,2,10,&WPP_a3b1741888e13d4a1c14bd4949ad3719_Traceguids,param_4,&param_6,8,
                  &param_7,8,&param_8,8,&param_9,8,0);
  return;
}



===== PlExtpDuplicateUnicodeString @ 1c000f380 =====

uint PlExtpDuplicateUnicodeString(ushort *param_1,undefined2 *param_2)

{
  ulonglong uVar1;
  longlong lVar2;
  size_t _Size;
  uint uVar3;
  void *_Dst;
  size_t local_res8;
  
  local_res8 = 0;
  if ((*param_1 < 0x7fff) && (uVar1 = (ulonglong)*param_1 + 2, uVar1 <= param_1[1])) {
    uVar3 = RtlStringCbLengthW(*(short **)(param_1 + 4),uVar1,(longlong *)&local_res8);
    _Size = local_res8;
    if (-1 < (int)uVar3) {
      lVar2 = local_res8 + 2;
      _Dst = (void *)ExAllocatePool2(0x40,lVar2,0x78466550);
      if (_Dst == (void *)0x0) {
        uVar3 = 0xc000009a;
      }
      else {
        memcpy(_Dst,*(void **)(param_1 + 4),_Size);
        *(undefined2 *)((longlong)_Dst + (_Size & 0xfffffffffffffffe)) = 0;
        *(void **)(param_2 + 4) = _Dst;
        *param_2 = (short)_Size;
        param_2[1] = (short)lVar2;
      }
    }
  }
  else {
    uVar3 = 0xc0000001;
  }
  return uVar3;
}



===== PlExtpAcpiReflectObjects @ 1c000f454 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 PlExtpAcpiReflectObjects(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  int iVar3;
  undefined8 *puVar4;
  ulonglong uVar5;
  uint uVar6;
  longlong lVar7;
  ulonglong uVar8;
  undefined8 *puVar9;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0xc,
                     &WPP_a2afeb96eade37b8f9cc5211bf7c269d_Traceguids);
  }
  lVar1 = *(longlong *)(param_1 + 0x68);
  if ((lVar1 != 0) && (*(int *)(param_1 + 0x60) != 0)) {
    iVar3 = *(int *)(param_1 + 0x60) * 0x28 + 0x20;
    puVar4 = (undefined8 *)ExAllocatePool2(0x40,iVar3,0x78466550);
    if (puVar4 == (undefined8 *)0x0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return 0;
      }
      WPP_RECORDER_SF_Sd(*(undefined8 *)(param_1 + 0x98),2,0xb,0xd,
                         &WPP_a2afeb96eade37b8f9cc5211bf7c269d_Traceguids,
                         *(wchar_t **)(param_1 + 0x18),(char)iVar3);
    }
    else {
      lVar7 = 2;
      puVar9 = puVar4;
      do {
        *puVar9 = *(undefined8 *)
                   ((longlong)puVar9 + *(longlong *)(param_2 + 0x88) + (0x28 - (longlong)puVar4));
        puVar9 = puVar9 + 1;
        lVar7 = lVar7 + -1;
      } while (lVar7 != 0);
      uVar8 = 0;
      puVar4[2] = *(undefined8 *)(*(longlong *)(param_2 + 0x88) + 0x10);
      uVar5 = uVar8;
      if (*(int *)(param_1 + 0x60) != 0) {
        do {
          uVar6 = (int)uVar5 + 1;
          uVar8 = (ulonglong)uVar6;
          puVar9 = (undefined8 *)(lVar1 + uVar5 * 0x28);
          uVar2 = puVar9[1];
          puVar4[uVar5 * 5 + 4] = *puVar9;
          (puVar4 + uVar5 * 5 + 4)[1] = uVar2;
          puVar9 = (undefined8 *)(lVar1 + 0x10 + uVar5 * 0x28);
          uVar2 = puVar9[1];
          puVar4[uVar5 * 5 + 6] = *puVar9;
          (puVar4 + uVar5 * 5 + 6)[1] = uVar2;
          puVar4[uVar5 * 5 + 8] = *(undefined8 *)(lVar1 + 0x20 + uVar5 * 0x28);
          puVar4[uVar5 * 5 + 4] = 0;
          *(undefined4 *)(puVar4 + uVar5 * 5 + 8) = 0;
          uVar5 = uVar8;
        } while (uVar6 < *(uint *)(param_1 + 0x60));
      }
      *(int *)(puVar4 + 3) = (int)uVar8;
      (*DAT_1c00165c8)(puVar4);
      uVar6 = 0;
      if (*(int *)(param_1 + 0x60) != 0) {
        do {
          uVar5 = (ulonglong)uVar6;
          iVar3 = *(int *)(lVar1 + 0x20 + uVar5 * 0x28);
          if (iVar3 == 0) {
            iVar3 = *(int *)(puVar4 + uVar5 * 5 + 8);
            *(int *)(lVar1 + 0x20 + uVar5 * 0x28) = iVar3;
          }
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_SDDD
                      (*(undefined8 *)(param_1 + 0x98),4,0xb,0xe,
                       &WPP_a2afeb96eade37b8f9cc5211bf7c269d_Traceguids,
                       *(wchar_t **)(param_1 + 0x18),(char)*(undefined4 *)(lVar1 + 8 + uVar5 * 0x28)
                       ,(char)*(undefined4 *)(lVar1 + 0xc + uVar5 * 0x28),(char)iVar3);
          }
          uVar6 = uVar6 + 1;
        } while (uVar6 < *(uint *)(param_1 + 0x60));
      }
      ExFreePoolWithTag(puVar4,0x78466550);
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0xf,
                     &WPP_a2afeb96eade37b8f9cc5211bf7c269d_Traceguids);
  }
  return 0;
}



===== PlExtpNotifyAcpiNewChildDevices @ 1c000f698 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 PlExtpNotifyAcpiNewChildDevices(longlong param_1)

{
  undefined8 local_18;
  undefined8 local_10;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,10,
                     &WPP_a2afeb96eade37b8f9cc5211bf7c269d_Traceguids);
  }
  local_18 = *(undefined8 *)(param_1 + 0x58);
  local_10 = 0xffff;
  (*DAT_1c00165d0)(&local_18);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0xb,
                     &WPP_a2afeb96eade37b8f9cc5211bf7c269d_Traceguids);
  }
  return 0;
}



===== PlExtpCopyExtendedAddressResource @ 1c000f760 =====

int PlExtpCopyExtendedAddressResource(int *param_1,undefined1 *param_2,uint param_3,uint *param_4)

{
  ushort *puVar1;
  uint uVar2;
  int iVar3;
  uint local_res8 [2];
  short local_28;
  short local_26;
  undefined4 local_24;
  undefined1 *local_20;
  
  local_res8[0] = 0;
  local_24 = 0;
  iVar3 = PlExtpGetResourceBufferLength(1,(longlong)param_1,(int *)local_res8);
  uVar2 = local_res8[0];
  if (-1 < iVar3) {
    if (param_3 < local_res8[0]) {
      iVar3 = -0x3fffffdd;
    }
    else {
      *param_2 = 0x8b;
      *(short *)(param_2 + 1) = (short)local_res8[0] + -3;
      param_2[3] = *param_1 != 8;
      param_2[4] = *(undefined1 *)((longlong)param_1 + 9);
      param_2[5] = *(undefined1 *)((longlong)param_1 + 10);
      param_2[6] = 1;
      param_2[7] = (char)param_1[3];
      *(undefined8 *)(param_2 + 8) = *(undefined8 *)(param_1 + 4);
      *(undefined8 *)(param_2 + 0x10) = *(undefined8 *)(param_1 + 6);
      *(undefined8 *)(param_2 + 0x18) = *(undefined8 *)(param_1 + 8);
      *(undefined8 *)(param_2 + 0x20) = *(undefined8 *)(param_1 + 10);
      *(undefined8 *)(param_2 + 0x28) = *(undefined8 *)(param_1 + 0xc);
      *(undefined8 *)(param_2 + 0x30) = *(undefined8 *)(param_1 + 0xe);
      puVar1 = *(ushort **)(param_1 + 0x10);
      if (puVar1 != (ushort *)0x0) {
        local_28 = (*puVar1 >> 1) + 1;
        local_26 = (*puVar1 >> 1) + 2;
        local_20 = param_2 + 0x38;
        RtlUnicodeStringToAnsiString(&local_28,puVar1,0);
      }
      *param_4 = uVar2;
      iVar3 = 0;
    }
  }
  return iVar3;
}



===== PlExtpCopyGpioResource @ 1c000f878 =====

int PlExtpCopyGpioResource(int *param_1,undefined1 *param_2,uint param_3,uint *param_4)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  byte bVar4;
  byte bVar5;
  int iVar6;
  ushort uVar7;
  uint uVar8;
  uint local_res8 [2];
  undefined8 local_38;
  undefined1 *puStack_30;
  
  local_res8[0] = 0;
  local_38 = 0;
  puStack_30 = (undefined1 *)0x0;
  iVar6 = PlExtpGetResourceBufferLength(1,(longlong)param_1,(int *)local_res8);
  uVar3 = local_res8[0];
  if (-1 < iVar6) {
    if ((param_3 < local_res8[0]) || (param_3 < 0x17)) {
      iVar6 = -0x3fffffdd;
    }
    else {
      *param_2 = 0x8c;
      *(short *)(param_2 + 1) = (short)local_res8[0] + -3;
      bVar5 = 0;
      param_2[3] = 1;
      param_2[4] = *param_1 != 4;
      *(ushort *)(param_2 + 5) = (ushort)((uint)param_1[1] >> 2) & 1;
      iVar6 = param_1[3];
      if (iVar6 != 1) {
        if (iVar6 == 2) {
          bVar5 = 2;
        }
        else if (iVar6 == 3) {
          bVar5 = 4;
        }
      }
      bVar4 = (byte)param_1[1];
      if (*param_1 == 4) {
        bVar5 = (bVar4 & 3) << 3 | param_1[2] != 0 | bVar5;
      }
      else {
        bVar5 = (bVar4 & 2) << 3 | *(byte *)(param_1 + 5) | (bVar4 & 1) << 3;
      }
      *(ushort *)(param_2 + 7) = (ushort)bVar5;
      param_2[9] = (char)param_1[4];
      *(short *)(param_2 + 10) = (short)param_1[6];
      *(undefined2 *)(param_2 + 0xc) = *(undefined2 *)((longlong)param_1 + 0x1a);
      param_2[0x10] = *(undefined1 *)((longlong)param_1 + 0x2a);
      *(undefined2 *)(param_2 + 0xe) = 0x17;
      uVar2 = (short)param_1[10] * 2;
      *(ushort *)(param_2 + 0x11) = uVar2 + 0x17;
      uVar1 = **(ushort **)(param_1 + 0xc);
      uVar7 = (uVar1 >> 1) + 1;
      *(ushort *)(param_2 + 0x13) = uVar2 + 0x17 + uVar7;
      *(short *)(param_2 + 0x15) = (short)param_1[0x10];
      if ((uint)uVar2 <= param_3 - 0x17) {
        memcpy(param_2 + 0x17,*(void **)(param_1 + 8),(ulonglong)uVar2);
      }
      uVar8 = (param_3 - 0x17) - (uint)uVar2;
      if (uVar7 <= uVar8) {
        puStack_30 = param_2 + *(ushort *)(param_2 + 0x11);
        local_38._0_4_ = CONCAT22((uVar1 >> 1) + 2,uVar7);
        RtlUnicodeStringToAnsiString(&local_38,*(undefined8 *)(param_1 + 0xc),0);
      }
      uVar1 = *(ushort *)(param_1 + 0x10);
      if ((((uint)uVar1 <= uVar8 - uVar7) && (*(void **)(param_1 + 0xe) != (void *)0x0)) &&
         (uVar1 != 0)) {
        memcpy(param_2 + *(ushort *)(param_2 + 0x13),*(void **)(param_1 + 0xe),
               (ulonglong)(uint)uVar1);
      }
      *param_4 = uVar3;
      iVar6 = 0;
    }
  }
  return iVar6;
}



===== PlExtpCopyInterruptResource @ 1c000fa58 =====

int PlExtpCopyInterruptResource(longlong param_1,undefined1 *param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  int iVar2;
  uint local_res8 [2];
  
  local_res8[0] = 0;
  iVar2 = PlExtpGetResourceBufferLength(1,param_1,(int *)local_res8);
  uVar1 = local_res8[0];
  if (-1 < iVar2) {
    if ((param_3 < local_res8[0]) || (param_3 < (uint)*(byte *)(param_1 + 0x10) * 4 + 5)) {
      iVar2 = -0x3fffffdd;
    }
    else {
      *param_2 = 0x89;
      *(short *)(param_2 + 1) = (short)local_res8[0] + -3;
      param_2[4] = *(undefined1 *)(param_1 + 0x10);
      param_2[3] = (byte)(*(uint *)(param_1 + 0xc) >> 2) & 1 | -(*(int *)(param_1 + 8) != 1) & 4U |
                   -(*(int *)(param_1 + 4) != 0) & 2U | ((byte)*(uint *)(param_1 + 0xc) & 3) << 3;
      memcpy(param_2 + 5,*(void **)(param_1 + 0x18),(ulonglong)*(byte *)(param_1 + 0x10) << 2);
      iVar2 = 0;
      *param_4 = uVar1;
    }
  }
  return iVar2;
}



===== PlExtpCopySpbI2cResource @ 1c000fb34 =====

int PlExtpCopySpbI2cResource(longlong param_1,undefined1 *param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  byte bVar2;
  byte bVar3;
  ushort uVar4;
  int iVar5;
  uint local_res8 [2];
  short local_38;
  short local_36;
  undefined4 local_34;
  undefined1 *local_30;
  
  local_res8[0] = 0;
  local_34 = 0;
  iVar5 = PlExtpGetResourceBufferLength(1,param_1,(int *)local_res8);
  uVar1 = local_res8[0];
  if (-1 < iVar5) {
    if (param_3 < local_res8[0]) {
      iVar5 = -0x3fffffdd;
    }
    else {
      *param_2 = 0x8e;
      *(short *)(param_2 + 1) = (short)local_res8[0] + -3;
      param_2[3] = 2;
      param_2[4] = *(undefined1 *)(param_1 + 10);
      param_2[5] = 1;
      bVar2 = (byte)(*(uint *)(param_1 + 4) >> 1) & 2;
      param_2[6] = bVar2;
      bVar3 = bVar2 | 1;
      if ((*(byte *)(param_1 + 4) & 8) == 0) {
        bVar3 = bVar2;
      }
      param_2[6] = bVar3;
      if ((*(uint *)(param_1 + 4) & 0x20) != 0) {
        bVar3 = bVar3 | 4;
      }
      param_2[6] = bVar3;
      *(ushort *)(param_2 + 7) = (ushort)(*(uint *)(param_1 + 4) >> 4) & 1;
      param_2[9] = 1;
      *(undefined2 *)(param_2 + 10) = 6;
      *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)(param_1 + 0x28);
      *(undefined2 *)(param_2 + 0x10) = *(undefined2 *)(param_1 + 0x2c);
      if (*(ushort *)(param_1 + 0x20) != 0) {
        memcpy(param_2 + 0x12,*(void **)(param_1 + 0x18),(ulonglong)*(ushort *)(param_1 + 0x20));
      }
      uVar4 = **(ushort **)(param_1 + 0x10) >> 1;
      local_38 = uVar4 + 1;
      local_36 = uVar4 + 2;
      local_30 = param_2 + 0x12 + *(ushort *)(param_1 + 0x20);
      RtlUnicodeStringToAnsiString(&local_38,*(ushort **)(param_1 + 0x10),0);
      iVar5 = 0;
      *param_4 = uVar1;
    }
  }
  return iVar5;
}



===== PlExtpCopySpbSpiResource @ 1c000fc7c =====

int PlExtpCopySpbSpiResource(longlong param_1,undefined1 *param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  byte bVar2;
  byte bVar3;
  ushort uVar4;
  int iVar5;
  uint local_res8 [2];
  short local_38;
  short local_36;
  undefined4 local_34;
  undefined1 *local_30;
  
  local_res8[0] = 0;
  local_34 = 0;
  iVar5 = PlExtpGetResourceBufferLength(1,param_1,(int *)local_res8);
  uVar1 = local_res8[0];
  if (-1 < iVar5) {
    if (param_3 < local_res8[0]) {
      iVar5 = -0x3fffffdd;
    }
    else {
      *param_2 = 0x8e;
      *(short *)(param_2 + 1) = (short)local_res8[0] + -3;
      param_2[3] = 2;
      param_2[4] = *(undefined1 *)(param_1 + 10);
      param_2[5] = 2;
      bVar2 = (byte)(*(uint *)(param_1 + 4) >> 1) & 2;
      param_2[6] = bVar2;
      bVar3 = bVar2 | 1;
      if ((*(byte *)(param_1 + 4) & 8) == 0) {
        bVar3 = bVar2;
      }
      param_2[6] = bVar3;
      if ((*(uint *)(param_1 + 4) & 0x20) != 0) {
        bVar3 = bVar3 | 4;
      }
      param_2[6] = bVar3;
      *(undefined2 *)(param_2 + 7) = *(undefined2 *)(param_1 + 8);
      param_2[9] = 1;
      *(undefined2 *)(param_2 + 10) = 0xc;
      *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)(param_1 + 0x28);
      param_2[0x10] = *(undefined1 *)(param_1 + 0x2c);
      *(undefined2 *)(param_2 + 0x13) = *(undefined2 *)(param_1 + 0x30);
      param_2[0x11] = *(undefined1 *)(param_1 + 0x2d);
      param_2[0x12] = *(undefined1 *)(param_1 + 0x2e);
      if (*(ushort *)(param_1 + 0x20) != 0) {
        memcpy(param_2 + 0x15,*(void **)(param_1 + 0x18),(ulonglong)*(ushort *)(param_1 + 0x20));
      }
      uVar4 = **(ushort **)(param_1 + 0x10) >> 1;
      local_38 = uVar4 + 1;
      local_36 = uVar4 + 2;
      local_30 = param_2 + 0x15 + *(ushort *)(param_1 + 0x20);
      RtlUnicodeStringToAnsiString(&local_38,*(ushort **)(param_1 + 0x10),0);
      iVar5 = 0;
      *param_4 = uVar1;
    }
  }
  return iVar5;
}



===== PlExtpCopySpbUartResource @ 1c000fdd0 =====

int PlExtpCopySpbUartResource(longlong param_1,undefined1 *param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  byte bVar2;
  ushort uVar3;
  int iVar4;
  byte bVar5;
  uint local_res8 [2];
  short local_38;
  short local_36;
  undefined4 local_34;
  undefined1 *local_30;
  
  local_res8[0] = 0;
  local_34 = 0;
  iVar4 = PlExtpGetResourceBufferLength(1,param_1,(int *)local_res8);
  uVar1 = local_res8[0];
  if (-1 < iVar4) {
    if (param_3 < local_res8[0]) {
      iVar4 = -0x3fffffdd;
    }
    else {
      *param_2 = 0x8e;
      *(short *)(param_2 + 1) = (short)local_res8[0] + -3;
      param_2[3] = 2;
      param_2[4] = *(undefined1 *)(param_1 + 10);
      param_2[5] = 3;
      bVar2 = (byte)(*(uint *)(param_1 + 4) >> 1) & 2;
      param_2[6] = bVar2;
      bVar5 = bVar2 | 4;
      if ((*(byte *)(param_1 + 4) & 0x20) == 0) {
        bVar5 = bVar2;
      }
      param_2[6] = bVar5;
      *(undefined2 *)(param_2 + 7) = *(undefined2 *)(param_1 + 8);
      param_2[9] = 1;
      *(undefined2 *)(param_2 + 10) = 10;
      *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)(param_1 + 0x28);
      *(undefined2 *)(param_2 + 0x10) = *(undefined2 *)(param_1 + 0x2c);
      *(undefined2 *)(param_2 + 0x12) = *(undefined2 *)(param_1 + 0x2e);
      param_2[0x14] = *(undefined1 *)(param_1 + 0x30);
      param_2[0x15] = *(undefined1 *)(param_1 + 0x31);
      if (*(ushort *)(param_1 + 0x20) != 0) {
        memcpy(param_2 + 0x16,*(void **)(param_1 + 0x18),(ulonglong)*(ushort *)(param_1 + 0x20));
      }
      uVar3 = **(ushort **)(param_1 + 0x10) >> 1;
      local_38 = uVar3 + 1;
      local_36 = uVar3 + 2;
      local_30 = param_2 + 0x16 + *(ushort *)(param_1 + 0x20);
      RtlUnicodeStringToAnsiString(&local_38,*(ushort **)(param_1 + 0x10),0);
      iVar4 = 0;
      *param_4 = uVar1;
    }
  }
  return iVar4;
}



===== PlExtpGetResourceBufferLength @ 1c000ff18 =====

int PlExtpGetResourceBufferLength(uint param_1,longlong param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  ushort *puVar6;
  
  iVar5 = 0;
  puVar6 = (ushort *)(param_2 + 0x40);
  uVar3 = 0;
  iVar2 = 0;
  iVar4 = 0;
  do {
    iVar1 = *(int *)(puVar6 + -0x20);
    if (iVar1 < 6) {
      if (iVar1 == 5) {
LAB_1c0010015:
        iVar5 = 0;
        if (*(ushort **)(puVar6 + -0x18) == (ushort *)0x0) {
LAB_1c0010055:
          iVar5 = -0x3ffffff3;
        }
        else {
          iVar4 = (**(ushort **)(puVar6 + -0x18) >> 1) + 0xd + (uint)puVar6[-0x10];
          if (iVar1 == 5) {
            iVar4 = iVar4 + 6;
          }
          else if (iVar1 == 6) {
            iVar4 = iVar4 + 0xc;
          }
          else {
            if (iVar1 != 7) goto LAB_1c0010055;
            iVar4 = iVar4 + 10;
          }
        }
      }
      else if (iVar1 == 0) {
        iVar4 = 0x14;
      }
      else if (iVar1 == 1) {
        iVar4 = 8;
      }
      else if (iVar1 == 2) {
        if ((byte)puVar6[-0x18] == 0) goto LAB_1c0010055;
        iVar5 = 0;
        iVar4 = (uint)(byte)puVar6[-0x18] * 4 + 5;
      }
      else {
        if ((iVar1 != 3) && (iVar1 != 4)) {
          return -0x3ffffff3;
        }
        if ((puVar6[-0xc] == 0) || (*(ushort **)(puVar6 + -8) == (ushort *)0x0)) goto LAB_1c0010055;
        iVar5 = 0;
        iVar4 = (**(ushort **)(puVar6 + -8) >> 1) + 0x18 + (uint)puVar6[-0xc] * 2 + (uint)*puVar6;
      }
      if (iVar5 < 0) {
        return iVar5;
      }
    }
    else {
      if ((iVar1 == 6) || (iVar1 == 7)) goto LAB_1c0010015;
      if ((iVar1 != 8) && (iVar1 != 9)) {
        return -0x3ffffff3;
      }
      iVar4 = 0x38;
      if (*(ushort **)puVar6 != (ushort *)0x0) {
        iVar4 = (**(ushort **)puVar6 >> 1) + 0x39;
      }
      iVar5 = 0;
    }
    iVar2 = iVar2 + iVar4;
    uVar3 = uVar3 + 1;
    puVar6 = puVar6 + 0x24;
    if (param_1 <= uVar3) {
      *param_3 = iVar2;
      return iVar5;
    }
  } while( true );
}



===== PlExtpPepAcpiGetBiosResourceBuffer @ 1c0010098 =====

int PlExtpPepAcpiGetBiosResourceBuffer
              (longlong param_1,uint param_2,undefined2 *param_3,ulonglong *param_4,uint param_5)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  uint local_res8 [2];
  uint local_res10;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    iVar2 = -0x3ffffff3;
  }
  else {
    local_res8[0] = 0;
    iVar2 = PlExtpGetResourceBufferLength(param_2 / 0x48,param_1,(int *)local_res8);
    if (-1 < iVar2) {
      uVar3 = local_res8[0];
      if ((param_5 & 1) == 0) {
        uVar3 = local_res8[0] + 2;
      }
      uVar4 = (uint)*param_4;
      if ((uVar4 < uVar3) || (param_3 == (undefined2 *)0x0)) {
        iVar2 = -0x3fffffdd;
        *param_4 = (ulonglong)uVar3;
      }
      else {
        local_res10 = 0;
        puVar5 = (undefined4 *)(param_1 + 8);
        do {
          local_res8[0] = 0;
          local_res10 = local_res10 + 1;
          piVar1 = puVar5 + -2;
          iVar2 = *piVar1;
          if (iVar2 < 6) {
            if (iVar2 == 5) {
              iVar2 = PlExtpCopySpbI2cResource
                                ((longlong)piVar1,(undefined1 *)param_3,uVar4,local_res8);
            }
            else if (iVar2 == 0) {
              if (0x13 < uVar4) {
                *(undefined1 *)param_3 = 0x85;
                *(undefined2 *)((longlong)param_3 + 1) = 0x11;
                *(undefined1 *)((longlong)param_3 + 3) = *(undefined1 *)(puVar5 + -1);
                *(undefined4 *)(param_3 + 2) = *puVar5;
                *(undefined4 *)(param_3 + 4) = puVar5[2];
                *(undefined4 *)(param_3 + 6) = puVar5[4];
                *(undefined4 *)(param_3 + 8) = puVar5[5];
                local_res8[0] = 0x14;
                goto LAB_1c00101cb;
              }
LAB_1c001020c:
              iVar2 = -0x3fffffdd;
            }
            else if (iVar2 == 1) {
              if (uVar4 < 8) goto LAB_1c001020c;
              *(undefined1 *)param_3 = 0x47;
              *(undefined1 *)((longlong)param_3 + 1) = *(undefined1 *)(puVar5 + -1);
              param_3[1] = *(undefined2 *)puVar5;
              param_3[2] = *(undefined2 *)(puVar5 + 2);
              *(undefined1 *)(param_3 + 3) = *(undefined1 *)(puVar5 + 4);
              *(undefined1 *)((longlong)param_3 + 7) = *(undefined1 *)(puVar5 + 5);
              local_res8[0] = 8;
LAB_1c00101cb:
              iVar2 = 0;
            }
            else if (iVar2 == 2) {
              iVar2 = PlExtpCopyInterruptResource
                                ((longlong)piVar1,(undefined1 *)param_3,uVar4,local_res8);
            }
            else {
              if ((iVar2 != 3) && (iVar2 != 4)) {
                return -0x3fffff45;
              }
              iVar2 = PlExtpCopyGpioResource(piVar1,(undefined1 *)param_3,uVar4,local_res8);
            }
          }
          else if (iVar2 == 6) {
            iVar2 = PlExtpCopySpbSpiResource
                              ((longlong)piVar1,(undefined1 *)param_3,uVar4,local_res8);
          }
          else if (iVar2 == 7) {
            iVar2 = PlExtpCopySpbUartResource
                              ((longlong)piVar1,(undefined1 *)param_3,uVar4,local_res8);
          }
          else {
            if ((iVar2 != 8) && (iVar2 != 9)) {
              return -0x3fffff45;
            }
            iVar2 = PlExtpCopyExtendedAddressResource(piVar1,(undefined1 *)param_3,uVar4,local_res8)
            ;
          }
          if (iVar2 < 0) {
            return iVar2;
          }
          puVar5 = puVar5 + 0x12;
          uVar4 = uVar4 - local_res8[0];
          param_3 = (undefined2 *)((longlong)param_3 + (ulonglong)local_res8[0]);
        } while ((local_res10 < param_2 / 0x48) && (uVar4 != 0));
        if ((param_5 & 1) == 0) {
          if (uVar4 < 2) {
            iVar2 = -0x3fffffdd;
            *param_4 = (ulonglong)uVar3;
          }
          else {
            *param_3 = 0x79;
          }
        }
      }
    }
  }
  return iVar2;
}



===== PlExtpVerifyBoolean @ 1c00102ec =====

undefined8 PlExtpVerifyBoolean(char param_1,undefined8 param_2,longlong param_3)

{
  undefined8 uVar1;
  longlong lVar2;
  undefined8 in_stack_ffffffffffffffd8;
  
  uVar1 = 0;
  if (param_1 != '\x01') {
    lVar2 = param_3;
    if (param_3 == 0) {
      lVar2 = PlExtLogHandle;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_dd(lVar2,0,param_3,0x10,in_stack_ffffffffffffffd8,param_1,1);
    }
    PlExtpVerifyDbgBreak("BOOLEAN value not as expected!",uVar1,lVar2);
    uVar1 = 0xc0000001;
  }
  return uVar1;
}



===== PlExtpVerifyDbgBreak @ 1c0010358 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PlExtpVerifyDbgBreak(char *param_1,undefined8 param_2,longlong param_3)

{
  code *pcVar1;
  char cVar2;
  
  if (param_3 == 0) {
    param_3 = PlExtLogHandle;
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_s(param_3,2,10,10,&WPP_4fa6b16d3a0539e0ea6f2e58de9517c5_Traceguids,param_1);
  }
  if (PlExtDbgBreakOverride == 0) {
LAB_1c00103c6:
    (**(code **)(WdfFunctions_01015 + 0xb78))(WdfDriverGlobals);
    return;
  }
  if (PlExtDbgBreakOverride != 1) {
    if (PlExtDbgBreakOverride == 2) goto LAB_1c00103c6;
    if (PlExtDbgBreakOverride != 3) {
      if (PlExtDbgBreakOverride != 4) {
        if (PlExtDbgBreakOverride == 5) {
          return;
        }
        if (PlExtDbgBreakOverride == 6) goto LAB_1c00103c6;
      }
      goto LAB_1c00103f6;
    }
  }
  cVar2 = KdRefreshDebuggerNotPresent();
  if (cVar2 != '\0') {
    return;
  }
LAB_1c00103f6:
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== PlExtpVerifyIrqlLessThanOrEqual @ 1c0010400 =====

undefined8 PlExtpVerifyIrqlLessThanOrEqual(undefined8 param_1,longlong param_2,undefined8 param_3)

{
  char cVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined8 in_stack_ffffffffffffffd8;
  
  lVar2 = param_2;
  cVar1 = KeGetCurrentIrql();
  uVar3 = 0;
  if (cVar1 != '\0') {
    uVar3 = 0xc0000010;
    if (param_2 == 0) {
      param_2 = PlExtLogHandle;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_dd(param_2,lVar2,param_3,0xc,in_stack_ffffffffffffffd8,0,cVar1);
    }
    PlExtpVerifyDbgBreak("Incorrect IRQL level!",lVar2,param_2);
  }
  return uVar3;
}



===== PlExtpVerifyNotNull @ 1c001047c =====

undefined8 PlExtpVerifyNotNull(longlong param_1,longlong param_2)

{
  undefined1 uVar1;
  undefined7 uVar2;
  undefined8 uVar3;
  
  uVar1 = (undefined1)param_2;
  uVar2 = (undefined7)((ulonglong)param_2 >> 8);
  uVar3 = 0;
  if (param_1 == 0) {
    uVar3 = 0xc000000d;
    if (param_2 == 0) {
      param_2 = PlExtLogHandle;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar1 = 2;
      WPP_RECORDER_SF_(param_2,2,10,0xb,&WPP_4fa6b16d3a0539e0ea6f2e58de9517c5_Traceguids);
    }
    PlExtpVerifyDbgBreak("Null Parameter is not allowed",CONCAT71(uVar2,uVar1),param_2);
  }
  return uVar3;
}



===== PlExtpVerifyStatusSuccessStrict @ 1c00104f4 =====

int PlExtpVerifyStatusSuccessStrict(int param_1,longlong param_2)

{
  longlong lVar1;
  
  if (param_1 != 0) {
    lVar1 = param_2;
    if (param_2 == 0) {
      lVar1 = PlExtLogHandle;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_D(lVar1,param_2,10,0xf,&WPP_4fa6b16d3a0539e0ea6f2e58de9517c5_Traceguids,
                        (char)param_1);
    }
    PlExtpVerifyDbgBreak("Incorrect Status code",param_2,lVar1);
    if (-1 < param_1) {
      param_1 = -0x3fffffff;
    }
  }
  return param_1;
}



===== WPP_RECORDER_SF_dd @ 1c0010574 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_dd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_4fa6b16d3a0539e0ea6f2e58de9517c5_Traceguids,param_4,&param_6,4,&param_7,4,0);
  }
  WppAutoLogTrace(param_1,2,10,&WPP_4fa6b16d3a0539e0ea6f2e58de9517c5_Traceguids,param_4,&param_6,4,
                  &param_7,4,0);
  return;
}



===== __GSHandlerCheck @ 1c0010648 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c001066c =====

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



===== __cpu_features_init @ 1c00106e0 =====

/* WARNING: Removing unreachable block (ram,0x0001c001074a) */
/* WARNING: Removing unreachable block (ram,0x0001c00106f9) */
/* WARNING: Removing unreachable block (ram,0x0001c00106ea) */

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



===== __security_check_cookie @ 1c00107b0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c00107f0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c0010820 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c0010820. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c0010850 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcmp @ 1c00108a0 =====

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
      if ((byte)*(ulonglong *)_Buf1 != *(byte *)((longlong)_Buf1 + lVar3)) goto LAB_1c00108e3;
      _Size = _Size - 1;
    }
    if (_Size >> 3 != 0) {
      uVar4 = _Size >> 5;
      if (uVar4 != 0) {
        do {
          uVar2 = *(ulonglong *)_Buf1;
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3)) goto LAB_1c0010954;
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 8);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 8)) {
LAB_1c0010950:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_1c0010954;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x10);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x10)) {
LAB_1c001094c:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_1c0010950;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x18);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x18)) {
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_1c001094c;
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
LAB_1c0010954:
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
LAB_1c00108e3:
  return (1 - (uint)bVar5) - (uint)(bVar5 != 0);
}



===== memcpy @ 1c00109c0 =====

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



===== memset @ 1c0010cc0 =====

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



===== __memset_repmovs @ 1c0010e00 =====

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



===== __memset_query @ 1c0010e80 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c0010f00 =====

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



===== __memset_spec_ermsb_repmovsb @ 1c0011040 =====

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



===== __memset_spec_plain @ 1c00110c0 =====

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



===== RhpModifyConnectionData @ 1c001a008 =====

ulonglong RhpModifyConnectionData
                    (longlong param_1,int param_2,longlong param_3,longlong *param_4,
                    undefined4 *param_5)

{
  longlong *plVar1;
  ulonglong uVar2;
  longlong *plVar3;
  ulonglong uVar4;
  undefined4 local_28 [2];
  longlong local_20;
  
  local_20 = 0;
  local_28[0] = 0;
  plVar1 = RhpFindAndReferenceConnectionById(param_1);
  if (plVar1 == (longlong *)0x0) {
    return 0xc0000225;
  }
  plVar3 = &local_20;
  uVar2 = RhpCacheGetConnectionDataFromId(param_1,plVar3,local_28);
  uVar4 = uVar2 & 0xffffffff;
  if ((int)uVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_siD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),plVar3,8,0x18,
                          &WPP_5a306037547032d76a1bb21b8aa3fd30_Traceguids,"RhpModifyConnectionData"
                          ,(char)param_1,(char)uVar2);
    }
    goto LAB_1c001a244;
  }
  if (param_2 == 0) {
    if (((short)plVar1[8] != 1) || (*(short *)((longlong)plVar1 + 0x42) != 2)) {
LAB_1c001a23f:
      uVar4 = 0xc000000d;
      goto LAB_1c001a244;
    }
    *(undefined1 *)(local_20 + 9) = *(undefined1 *)(param_3 + 10);
    *(undefined2 *)(local_20 + 0xc) = *(undefined2 *)(param_3 + 0xc);
    *(undefined2 *)(local_20 + 10) = *(undefined2 *)(param_3 + 0xe);
  }
  else if (param_2 == 2) {
    if (((short)plVar1[8] != 2) || (*(short *)((longlong)plVar1 + 0x42) != 2)) goto LAB_1c001a23f;
    *(undefined2 *)(local_20 + 0x13) = *(undefined2 *)(param_3 + 10);
    *(undefined4 *)(local_20 + 0xc) = *(undefined4 *)(param_3 + 0xc);
    *(ushort *)(local_20 + 7) =
         (ushort)*(byte *)(param_3 + 0x12) * 2 | *(ushort *)(local_20 + 7) & 0xfffd;
    *(undefined1 *)(local_20 + 0x12) = *(undefined1 *)(param_3 + 0x10);
    *(undefined1 *)(local_20 + 0x11) = *(undefined1 *)(param_3 + 0x11);
    *(undefined1 *)(local_20 + 0x10) = *(undefined1 *)(param_3 + 0x13);
  }
  else if (param_2 == 3) {
    if (((short)plVar1[8] != 2) || (*(short *)((longlong)plVar1 + 0x42) != 1)) goto LAB_1c001a23f;
    *(undefined4 *)(local_20 + 0xc) = *(undefined4 *)(param_3 + 0xc);
    *(undefined2 *)(local_20 + 0x10) = *(undefined2 *)(param_3 + 0x10);
    *(undefined2 *)(local_20 + 7) = *(undefined2 *)(param_3 + 10);
  }
  else {
    if (param_2 != 4) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),plVar3,8,0x19,
                           &WPP_5a306037547032d76a1bb21b8aa3fd30_Traceguids,
                           "RhpModifyConnectionData",(char)param_2);
      }
      uVar4 = 0xc00000bb;
      goto LAB_1c001a244;
    }
    if (((short)plVar1[8] != 2) || (*(short *)((longlong)plVar1 + 0x42) != 3)) goto LAB_1c001a23f;
    *(undefined4 *)(local_20 + 0xc) = *(undefined4 *)(param_3 + 0xc);
    *(undefined2 *)(local_20 + 7) = *(undefined2 *)(param_3 + 0x10);
    *(undefined2 *)(local_20 + 0x10) = *(undefined2 *)(param_3 + 0x12);
    *(undefined2 *)(local_20 + 0x12) = *(undefined2 *)(param_3 + 0x14);
    *(undefined1 *)(local_20 + 0x14) = *(undefined1 *)(param_3 + 0x16);
  }
  *param_4 = local_20;
  *param_5 = local_28[0];
LAB_1c001a244:
  RhpDereferenceConnection(plVar1);
  return uVar4;
}



===== RhpFindAndReferenceConnectionById @ 1c001a270 =====

undefined8 * RhpFindAndReferenceConnectionById(longlong param_1)

{
  undefined8 *puVar1;
  
  ExAcquireFastMutex(&RhTranslationCacheLock);
  puVar1 = RhpFindAndReferenceConnectionByIdLocked(param_1);
  ExReleaseFastMutex(&RhTranslationCacheLock);
  return puVar1;
}



===== WppLoadTracingSupport @ 1c001a2bc =====

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



===== RhpSetupIoQueues @ 1c001a400 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int RhpSetupIoQueues(undefined8 param_1)

{
  int iVar1;
  undefined8 local_res10 [3];
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined1 local_5b;
  code *local_50;
  code *local_48;
  code *local_40;
  undefined4 local_18;
  
  local_res10[0] = 0;
  memset(&local_68,0,0x60);
  local_18 = 0xffffffff;
  local_50 = RhEvtProcessWriteRequest;
  local_68 = 0x60;
  local_98 = 0;
  local_60 = 2;
  local_48 = RhEvtProcessWriteRequest;
  uStack_a0 = 0;
  local_5b = 1;
  local_40 = RhEvtProcessDeviceIoControl;
  local_64 = 2;
  local_78 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_a8 = 0x38;
  uStack_90 = 0x400000002;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x4c0))
                    (WdfDriverGlobals,param_1,&local_68,&local_a8,local_res10);
  if ((iVar1 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_1,2,0x3d,
                       &WPP_a781b87147d030366b419d92a3dc1ed1_Traceguids,"RhpSetupIoQueues",
                       (char)iVar1);
  }
  return iVar1;
}



===== RhpGetResourceNameFromFunctionConfigDescriptor @ 1c001a528 =====

undefined8
RhpGetResourceNameFromFunctionConfigDescriptor(char *param_1,uint param_2,ulonglong *param_3)

{
  ushort uVar1;
  char cVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  ulonglong local_res20;
  
  cVar2 = RhpIsBiosFunctionConfigDescriptorValid(param_1,param_2);
  if (cVar2 == '\0') {
    uVar3 = 0xc0000001;
  }
  else {
    uVar1 = *(ushort *)(param_1 + 0xc);
    local_res20 = (ulonglong)*(ushort *)(param_1 + 0xe) - (ulonglong)uVar1;
    uVar4 = 0x7fff;
    if (local_res20 < 0x7fff) {
      uVar4 = local_res20;
    }
    uVar3 = RtlStringCbLengthA(param_1 + uVar1,local_res20,&local_res20);
    if (-1 < (int)uVar3) {
      *param_3 = (ulonglong)CONCAT22((short)uVar4,(undefined2)local_res20);
      param_3[1] = (ulonglong)(param_1 + uVar1);
    }
  }
  return uVar3;
}



===== RhpIsBiosFunctionConfigDescriptorValid @ 1c001a5ac =====

undefined1 RhpIsBiosFunctionConfigDescriptorValid(char *param_1,uint param_2)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  uint uVar4;
  undefined1 uVar5;
  uint uVar6;
  
  uVar5 = 0;
  if ((((0x11 < param_2) && (*param_1 == -0x73)) && (uVar1 = *(ushort *)(param_1 + 9), 0x11 < uVar1)
      ) && (uVar1 < param_2)) {
    uVar2 = *(ushort *)(param_1 + 0xc);
    uVar6 = (uint)uVar2;
    if (uVar6 < param_2) {
      uVar3 = *(ushort *)(param_1 + 0xe);
      if (((((uVar3 <= param_2) && (uVar1 < uVar2)) &&
           ((uVar2 < uVar3 && ((param_1[3] != '\0' && (uVar4 = uVar6 - uVar1, 1 < uVar4)))))) &&
          ((uVar4 & 1) == 0)) && (uVar4 < 0x80000000)) {
        uVar5 = 0;
        if (((ulonglong)uVar3 - (ulonglong)uVar6) - 1 < 0x7fff) {
          uVar5 = 1;
        }
      }
    }
  }
  return uVar5;
}



===== RhpTranslateAndCacheConnection @ 1c001a64c =====

ulonglong RhpTranslateAndCacheConnection
                    (ushort *param_1,char *param_2,uint param_3,undefined8 param_4,
                    undefined2 *param_5)

{
  char cVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  undefined2 uVar4;
  
  uVar2 = (ulonglong)param_3;
  if ((param_2 != (char *)0x0) && (param_3 != 0)) {
    cVar1 = *param_2;
    if (cVar1 == -0x74) {
      uVar3 = uVar2;
      cVar1 = RhpIsBiosGpioDescriptorValid(param_2,param_3);
      if (cVar1 != '\0') {
        if (param_2[4] == '\0') {
          uVar2 = RhpBiosGpioInterruptToNtResource(param_1,param_2,uVar2,param_4,param_5);
          return uVar2;
        }
        uVar2 = RhpBiosGpioIoToNtResource(param_1,param_2,param_3,param_4,param_5);
        return uVar2;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return 0xc000000d;
      }
      uVar4 = 0xc;
    }
    else if (cVar1 == -0x73) {
      cVar1 = RhpIsBiosFunctionConfigDescriptorValid(param_2,param_3);
      if (cVar1 != '\0') {
        uVar2 = RhpBiosFunctionConfigToNtResource(param_1,param_2,param_3,param_4,param_5);
        return uVar2;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return 0xc000000d;
      }
      uVar4 = 0xd;
      uVar3 = uVar2;
    }
    else {
      if (cVar1 != -0x72) {
        return 0xc00000bb;
      }
      if (0xb < param_3) {
        uVar2 = RhpBiosSerialBusToNtResource(param_1,param_2,param_3,param_4,param_5);
        return uVar2;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return 0xc000000d;
      }
      uVar4 = 0xe;
      uVar3 = 1;
    }
    WPP_RECORDER_SF_siD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar3,7,uVar4,
                        &WPP_cf4f8fa19d3932c70975ae2eca242000_Traceguids,
                        "RhpTranslateAndCacheConnection",(char)param_2,(char)param_3);
  }
  return 0xc000000d;
}



===== RhpReadGpioPins @ 1c001a7b4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void RhpReadGpioPins(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  undefined8 local_28;
  undefined8 local_20;
  undefined4 local_18;
  undefined4 local_14;
  
  local_28 = 1;
  local_14 = 0;
  local_20 = param_2;
  local_18 = param_3;
  (**(code **)(WdfFunctions_01015 + 0x5d0))(WdfDriverGlobals,param_1,0,0x480000,0,&local_28,0,0);
  return;
}



===== RhpInsertContext @ 1c001a818 =====

ulonglong RhpInsertContext(longlong param_1,longlong *param_2)

{
  undefined8 *puVar1;
  code *pcVar2;
  int iVar3;
  undefined8 *puVar4;
  ulonglong uVar5;
  
  puVar1 = (undefined8 *)(param_1 + 0x20);
  puVar4 = (undefined8 *)*puVar1;
  do {
    if (puVar4 == puVar1) {
      puVar4 = *(undefined8 **)(param_1 + 0x28);
      uVar5 = 0;
      if ((undefined8 *)*puVar4 != puVar1) {
        uVar5 = 3;
        pcVar2 = (code *)swi(0x29);
        puVar4 = (undefined8 *)(*pcVar2)();
      }
      *param_2 = (longlong)puVar1;
      param_2[1] = (longlong)puVar4;
      *puVar4 = param_2;
      *(longlong **)(param_1 + 0x28) = param_2;
LAB_1c001a8a4:
      if (*(longlong *)(param_1 + 0x48) == 0) {
        *(undefined1 *)((longlong)param_2 + 0x24) = 1;
      }
LAB_1c001a8af:
      return uVar5 & 0xffffffff;
    }
    iVar3 = RtlCompareUnicodeString(param_2 + 5,puVar4 + 5,0);
    if ((iVar3 == 0) && (*(char *)((longlong)puVar4 + 0x24) == '\0')) {
      uVar5 = 0xc0000718;
      goto LAB_1c001a8af;
    }
    if (0 < iVar3) {
      puVar1 = (undefined8 *)puVar4[1];
      uVar5 = 0;
      param_2[1] = (longlong)puVar1;
      *param_2 = (longlong)puVar4;
      puVar4[1] = param_2;
      *puVar1 = param_2;
      goto LAB_1c001a8a4;
    }
    puVar4 = (undefined8 *)*puVar4;
  } while( true );
}



===== WppInitKm @ 1c001a8d0 =====

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



===== RhpAddProviderTarget @ 1c001a9ac =====

ulonglong RhpAddProviderTarget(ushort *param_1)

{
  undefined8 *puVar1;
  longlong lVar2;
  longlong *plVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  longlong lVar6;
  longlong *local_res8;
  
  lVar6 = 0;
  local_res8 = (longlong *)0x0;
  uVar4 = RhpFindOrCreateProvider(param_1,(ulonglong *)&local_res8);
  uVar5 = uVar4 & 0xffffffff;
  if ((int)uVar4 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sSD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),0,8,0xc,
                          &WPP_5a306037547032d76a1bb21b8aa3fd30_Traceguids,"RhpAddProviderTarget",
                          *(wchar_t **)(param_1 + 4),(char)uVar4);
    }
  }
  else {
    ExAcquireFastMutex(&RhTranslationCacheLock);
    plVar3 = local_res8;
    puVar1 = (undefined8 *)local_res8[9];
    if (puVar1 == (undefined8 *)0x0) {
      lVar2 = local_res8[8];
      if (lVar2 != 0) {
        local_res8[8] = 0;
        lVar6 = lVar2;
      }
    }
    else if (puVar1[4] != *(longlong *)(param_1 + 0x10)) {
      LOCK();
      *(int *)(puVar1 + 6) = *(int *)(puVar1 + 6) + 1;
      UNLOCK();
      ExReleaseFastMutex(&RhTranslationCacheLock);
      RhpCleanOrRemoveProviderTarget(puVar1,'\x01');
      RhpDereferenceTargetData(puVar1);
      ExAcquireFastMutex(&RhTranslationCacheLock);
    }
    puVar1 = (undefined8 *)plVar3[9];
    if (puVar1 == (undefined8 *)0x0) {
      LOCK();
      *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;
      UNLOCK();
      LOCK();
      *(int *)(local_res8 + 10) = (int)local_res8[10] + 1;
      UNLOCK();
      plVar3[9] = (longlong)param_1;
      local_res8[8] = *(longlong *)(param_1 + 0x10);
      ObfReferenceObject();
      ExReleaseFastMutex(&RhTranslationCacheLock);
      uVar5 = 0;
    }
    else {
      LOCK();
      *(int *)(puVar1 + 6) = *(int *)(puVar1 + 6) + 1;
      UNLOCK();
      ExReleaseFastMutex(&RhTranslationCacheLock);
      if (puVar1[4] == *(longlong *)(param_1 + 0x10)) {
        uVar5 = 0x40000000;
      }
      else {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sSSqSq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
        }
        uVar5 = 0xc0000718;
      }
      RhpDereferenceTargetData(puVar1);
    }
    if (lVar6 != 0) {
      ObfDereferenceObject(lVar6);
    }
  }
  if (local_res8 != (longlong *)0x0) {
    RhpDereferenceProvider(local_res8);
  }
  return uVar5;
}



===== RhpAllocateConnectionUsingId @ 1c001abbc =====

ulonglong RhpAllocateConnectionUsingId
                    (longlong param_1,uint param_2,longlong param_3,longlong *param_4)

{
  undefined1 uVar1;
  int iVar2;
  longlong *plVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined2 uVar6;
  uint local_28 [2];
  void *local_20;
  longlong local_18;
  
  local_18 = 0;
  local_20 = (void *)0x0;
  local_28[0] = 0;
  plVar3 = RhpFindAndReferenceConnectionById(param_1);
  if (plVar3 == (longlong *)0x0) {
    return 0xc0000225;
  }
  uVar5 = (ulonglong)param_2;
  uVar4 = RhpModifyConnectionData(param_1,param_2,param_3,(longlong *)&local_20,local_28);
  iVar2 = (int)uVar4;
  uVar4 = uVar4 & 0xffffffff;
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c001ad0d;
    uVar6 = 0x1a;
LAB_1c001ac41:
    uVar1 = (undefined1)iVar2;
  }
  else {
    uVar5 = (ulonglong)*(ushort *)(plVar3 + 8);
    uVar4 = RhpCacheAddConnection
                      ((ushort *)(plVar3[6] + 0x30),*(ushort *)(plVar3 + 8),
                       *(short *)((longlong)plVar3 + 0x42),0,local_20,local_28[0],1);
    iVar2 = (int)uVar4;
    uVar4 = uVar4 & 0xffffffff;
    if (iVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c001ad0d;
      uVar6 = 0x1b;
      goto LAB_1c001ac41;
    }
    if (local_18 != param_1) {
      *param_4 = local_18;
      goto LAB_1c001ad0d;
    }
    uVar4 = 0xc000000d;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c001ad0d;
    uVar6 = 0x1c;
    uVar1 = 0xd;
  }
  WPP_RECORDER_SF_siD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar5,8,uVar6,
                      &WPP_5a306037547032d76a1bb21b8aa3fd30_Traceguids,
                      "RhpAllocateConnectionUsingId",(char)param_1,uVar1);
LAB_1c001ad0d:
  RhpDereferenceConnection(plVar3);
  return uVar4;
}



===== RhpAllocateProvider @ 1c001ad3c =====

undefined8 RhpAllocateProvider(longlong *param_1)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 uVar3;
  
  lVar1 = ExAllocatePool2(0x100,0x58,0x48736552);
  if (lVar1 == 0) {
    uVar3 = 0xc000009a;
    lVar1 = 0;
  }
  else {
    *(longlong *)(lVar1 + 8) = lVar1;
    *(longlong *)lVar1 = lVar1;
    lVar2 = lVar1 + 0x10;
    *(longlong *)(lVar1 + 0x18) = lVar2;
    *(longlong *)lVar2 = lVar2;
    lVar2 = lVar1 + 0x20;
    *(longlong *)(lVar1 + 0x28) = lVar2;
    *(longlong *)lVar2 = lVar2;
    uVar3 = 0;
    *(undefined4 *)(lVar1 + 0x50) = 1;
  }
  *param_1 = lVar1;
  return uVar3;
}



===== RhpCacheAddConnection @ 1c001ada8 =====

ulonglong RhpCacheAddConnection
                    (ushort *param_1,short param_2,short param_3,int param_4,void *param_5,
                    uint param_6,undefined1 param_7)

{
  code *pcVar1;
  longlong *plVar2;
  ulonglong uVar3;
  longlong *plVar4;
  longlong *plVar5;
  undefined8 *puVar6;
  undefined1 *puVar7;
  ulonglong uVar8;
  undefined1 auStackY_68 [8];
  undefined1 auStackY_60 [24];
  longlong *local_18 [2];
  
  local_18[0] = (longlong *)0x0;
  uVar3 = RhpFindOrCreateConnection
                    (param_1,param_2,param_3,param_5,param_6,param_7,(longlong *)local_18);
  plVar2 = local_18[0];
  puVar7 = auStackY_68;
  uVar8 = uVar3 & 0xffffffff;
  if ((int)uVar3 < 0) {
    puVar7 = auStackY_68;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sSqD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
      puVar7 = auStackY_68;
    }
  }
  else {
    if (param_4 != 0) {
      ExAcquireFastMutex(&RhTranslationCacheLock);
      puVar7 = auStackY_68;
      if (*(int *)((longlong)plVar2 + 0x44) == 0) {
        *(int *)((longlong)plVar2 + 0x44) = param_4;
        puVar6 = &RhInterruptListHead;
        plVar4 = plVar2 + 4;
        plVar5 = DAT_1c0016798;
        if ((undefined8 *)*DAT_1c0016798 != &RhInterruptListHead) {
          plVar5 = (longlong *)0x3;
          pcVar1 = (code *)swi(0x29);
          plVar4 = (longlong *)(*pcVar1)();
          puVar7 = auStackY_60;
        }
        *plVar4 = (longlong)puVar6;
        plVar4[1] = (longlong)plVar5;
        *plVar5 = (longlong)plVar4;
        DAT_1c0016798 = plVar4;
      }
      else {
        puVar7 = auStackY_68;
        if (param_4 != *(int *)((longlong)plVar2 + 0x44)) {
          uVar8 = 0x40000000;
          puVar7 = auStackY_68;
        }
      }
      *(undefined8 *)(puVar7 + -8) = 0x1c001aea9;
      ExReleaseFastMutex(&RhTranslationCacheLock);
    }
    if (*(longlong **)(puVar7 + 0xa8) != (longlong *)0x0) {
      **(longlong **)(puVar7 + 0xa8) = plVar2[7];
    }
  }
  if (plVar2 != (longlong *)0x0) {
    *(undefined8 *)(puVar7 + -8) = 0x1c001aecf;
    RhpDereferenceConnection(plVar2);
  }
  return uVar8;
}



===== RhpCacheGetInterruptVector @ 1c001aef4 =====

uint RhpCacheGetInterruptVector
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,void *param_4,uint param_5,
               undefined4 *param_6)

{
  undefined8 *puVar1;
  
  ExAcquireFastMutex(&RhTranslationCacheLock);
  puVar1 = RhpFindConnection(param_1,0,1,1,param_4,param_5);
  if (puVar1 != (undefined8 *)0x0) {
    *param_6 = *(undefined4 *)((longlong)puVar1 + 0x44);
  }
  ExReleaseFastMutex(&RhTranslationCacheLock);
  return ~-(uint)(puVar1 != (undefined8 *)0x0) & 0xc0000225;
}



===== RhpCleanContext @ 1c001af84 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void RhpCleanContext(longlong param_1)

{
  if (*(code **)(param_1 + 0x18) != (code *)0x0) {
    (**(code **)(param_1 + 0x18))(param_1 + 0x40,*(undefined4 *)(param_1 + 0x38));
  }
  RhpFreeUnicodeString((undefined8 *)(param_1 + 0x28));
  ExFreePoolWithTag(param_1,0x48736552);
  return;
}



===== RhpCleanOrRemoveProviderTarget @ 1c001afcc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 RhpCleanOrRemoveProviderTarget(undefined8 *param_1,char param_2)

{
  longlong lVar1;
  code *pcVar2;
  longlong *plVar3;
  longlong *plVar4;
  longlong *plVar5;
  undefined1 *puVar6;
  longlong lVar7;
  longlong *plVar8;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  
  ExAcquireFastMutex(&RhTranslationCacheLock);
  puVar6 = auStack_48;
  plVar8 = RhProviderListHead;
  while( true ) {
    if ((longlong **)plVar8 == &RhProviderListHead) {
      ExReleaseFastMutex(&RhTranslationCacheLock);
      return 0xc0000225;
    }
    if ((undefined8 *)plVar8[9] == param_1) break;
    plVar8 = (longlong *)*plVar8;
  }
  if (param_2 == '\0') {
    lVar7 = 0;
  }
  else {
    plVar8[9] = 0;
    lVar7 = plVar8[8];
    plVar8[8] = 0;
  }
  plVar4 = plVar8 + 4;
  plVar5 = (longlong *)*plVar4;
  while (plVar5 != plVar4) {
    *(undefined1 *)((longlong)plVar5 + 0x24) = 1;
    plVar5 = (longlong *)*plVar5;
  }
  plVar5 = (longlong *)plVar8[2];
  while (plVar3 = plVar5, plVar3 != plVar8 + 2) {
    plVar5 = (longlong *)*plVar3;
    if (plVar3[0xb] != 0) {
      *(undefined1 *)(plVar3 + 0xc) = 1;
    }
  }
  while( true ) {
    plVar5 = (longlong *)*plVar4;
    while( true ) {
      if (plVar5 == plVar4) goto LAB_1c001b0dd;
      if ((*(char *)((longlong)plVar5 + 0x24) != '\0') && ((int)plVar5[4] == 0)) break;
      plVar5 = (longlong *)*plVar5;
    }
    lVar1 = *plVar5;
    if ((*(longlong **)(lVar1 + 8) != plVar5) ||
       (plVar3 = (longlong *)plVar5[1], (longlong *)*plVar3 != plVar5)) break;
    *plVar3 = lVar1;
    *(longlong **)(lVar1 + 8) = plVar3;
    plVar5[1] = (longlong)plVar5;
    *plVar5 = (longlong)plVar5;
    ExReleaseFastMutex(&RhTranslationCacheLock);
    RhpCleanContext((longlong)plVar5);
    ExAcquireFastMutex(&RhTranslationCacheLock);
  }
  pcVar2 = (code *)swi(0x29);
  (*pcVar2)(3);
  puVar6 = auStack_40;
LAB_1c001b0dd:
  do {
    plVar4 = (longlong *)plVar8[2];
    while( true ) {
      if (plVar4 == plVar8 + 2) {
        *(undefined8 *)(puVar6 + -8) = 0x1c001b147;
        ExReleaseFastMutex(&RhTranslationCacheLock);
        if (param_2 == '\0') {
          return 0;
        }
        *(undefined8 *)(puVar6 + -8) = 0x1c001b159;
        RhpDereferenceTargetData(param_1);
        *(undefined8 *)(puVar6 + -8) = 0x1c001b161;
        RhpDereferenceProvider(plVar8);
        if (lVar7 == 0) {
          return 0;
        }
        *(undefined8 *)(puVar6 + -8) = 0x1c001b170;
        ObfDereferenceObject(lVar7);
        return 0;
      }
      if ((char)plVar4[0xc] != '\0') break;
      plVar4 = (longlong *)*plVar4;
    }
    lVar1 = plVar4[0xb];
    plVar4[0xb] = 0;
    *(undefined1 *)(plVar4 + 0xc) = 0;
    *(undefined8 *)(puVar6 + -8) = 0x1c001b10a;
    ExReleaseFastMutex(&RhTranslationCacheLock);
    pcVar2 = *(code **)(WdfFunctions_01015 + 0x680);
    *(undefined8 *)(puVar6 + -8) = 0x1c001b12c;
    (*pcVar2)(WdfDriverGlobals,lVar1);
    *(undefined8 *)(puVar6 + -8) = 0x1c001b136;
    ExAcquireFastMutex(&RhTranslationCacheLock);
  } while( true );
}



===== RhpCloseTargetData @ 1c001b1b4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void RhpCloseTargetData(longlong param_1)

{
  longlong lVar1;
  
  ExAcquireFastMutex(&RhTranslationCacheLock);
  lVar1 = *(longlong *)(param_1 + 0x28);
  *(undefined8 *)(param_1 + 0x28) = 0;
  ExReleaseFastMutex(&RhTranslationCacheLock);
  if (lVar1 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,lVar1);
  }
  return;
}



===== RhpDestroyTranslationCache @ 1c001b224 =====

void RhpDestroyTranslationCache(void)

{
  undefined8 *puVar1;
  undefined8 ***pppuVar2;
  longlong *plVar3;
  undefined8 ***pppuVar4;
  undefined8 ***local_28;
  undefined8 ***pppuStack_20;
  
  local_28 = (undefined8 ***)0x0;
  pppuStack_20 = (undefined8 ***)0x0;
  ExAcquireFastMutex(&RhTranslationCacheLock);
  while( true ) {
    plVar3 = DAT_1c00167a8;
    while( true ) {
      if ((undefined8 **)plVar3 == &RhProviderListHead) goto LAB_1c001b2cf;
      if (plVar3[9] != 0) break;
      plVar3 = (longlong *)plVar3[1];
    }
    LOCK();
    *(int *)(plVar3 + 10) = (int)plVar3[10] + 1;
    UNLOCK();
    puVar1 = (undefined8 *)plVar3[9];
    LOCK();
    *(int *)(puVar1 + 6) = *(int *)(puVar1 + 6) + 1;
    UNLOCK();
    if (puVar1 == (undefined8 *)0x0) break;
    ExReleaseFastMutex(&RhTranslationCacheLock);
    RhpCleanOrRemoveProviderTarget(puVar1,'\x01');
    RhpCloseTargetData((longlong)puVar1);
    RhpDereferenceTargetData(puVar1);
    RhpDereferenceProvider(plVar3);
    ExAcquireFastMutex(&RhTranslationCacheLock);
  }
LAB_1c001b2cf:
  pppuStack_20 = &local_28;
  local_28 = &local_28;
  if ((undefined8 ****)RhConnectionListHead == &RhConnectionListHead) {
    ExReleaseFastMutex(&RhTranslationCacheLock);
  }
  else {
    pppuStack_20 = DAT_1c0016788;
    local_28 = RhConnectionListHead;
    *DAT_1c0016788 = &local_28;
    RhConnectionListHead[1] = &local_28;
    DAT_1c0016788 = &RhConnectionListHead;
    RhConnectionListHead = &RhConnectionListHead;
    ExReleaseFastMutex(&RhTranslationCacheLock);
    pppuVar4 = pppuStack_20;
    while ((undefined8 ****)pppuVar4 != &local_28) {
      pppuVar2 = (undefined8 ***)pppuVar4[1];
      RhpDereferenceConnection((longlong *)pppuVar4);
      pppuVar4 = pppuVar2;
    }
  }
  if (((undefined8 ****)local_28 != &local_28) &&
     ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),0,8,10,
                      &WPP_5a306037547032d76a1bb21b8aa3fd30_Traceguids,"RhpDestroyTranslationCache")
    ;
  }
  if (((undefined8 **)RhProviderListHead != &RhProviderListHead) &&
     ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),0,8,0xb,
                      &WPP_5a306037547032d76a1bb21b8aa3fd30_Traceguids,"RhpDestroyTranslationCache")
    ;
  }
  return;
}



===== RhpEvtDestroyWdfTargetCallback @ 1c001b400 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void RhpEvtDestroyWdfTargetCallback(undefined8 param_1)

{
  longlong *plVar1;
  
  plVar1 = (longlong *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_RH_WDF_TARGET_CONTEXT_TYPE_INFO_1c0016088);
  *(undefined8 *)(*plVar1 + 0x28) = 0;
  RhpDereferenceTargetData((undefined8 *)*plVar1);
  return;
}



===== RhpEvtIoTargetQueryRemove @ 1c001b450 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 RhpEvtIoTargetQueryRemove(undefined8 param_1)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_RH_WDF_TARGET_CONTEXT_TYPE_INFO_1c0016088);
  RhpCleanOrRemoveProviderTarget((undefined8 *)*puVar1,'\0');
  return 0;
}



===== RhpEvtIoTargetRemoveCanceled @ 1c001b490 =====

void RhpEvtIoTargetRemoveCanceled(void)

{
  return;
}



===== RhpEvtIoTargetRemoveComplete @ 1c001b4a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void RhpEvtIoTargetRemoveComplete(undefined8 param_1)

{
  longlong *plVar1;
  
  plVar1 = (longlong *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_RH_WDF_TARGET_CONTEXT_TYPE_INFO_1c0016088);
  RhpCleanOrRemoveProviderTarget((undefined8 *)*plVar1,'\x01');
  RhpCloseTargetData(*plVar1);
  return;
}



===== RhpFreeProvider @ 1c001b4ec =====

void RhpFreeProvider(longlong param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  
  puVar2 = *(undefined8 **)(param_1 + 0x20);
  while (puVar2 != (undefined8 *)(param_1 + 0x20)) {
    puVar1 = (undefined8 *)*puVar2;
    RhpCleanContext((longlong)puVar2);
    puVar2 = puVar1;
  }
  RhpFreeUnicodeString((undefined8 *)(param_1 + 0x30));
  ExFreePoolWithTag(param_1,0x48736552);
  return;
}



===== RhpFreeTargetData @ 1c001b54c =====

void RhpFreeTargetData(undefined8 *param_1)

{
  RhpFreeUnicodeString(param_1 + 2);
  RhpFreeUnicodeString(param_1);
  if (param_1[4] != 0) {
    ObfDereferenceObject();
    param_1[4] = 0;
  }
  ExFreePoolWithTag(param_1,0x48736552);
  return;
}



===== RhpInsertConnection @ 1c001b5a4 =====

ulonglong RhpInsertConnection(undefined8 param_1,longlong *param_2)

{
  code *pcVar1;
  longlong *plVar2;
  ulonglong uVar3;
  longlong lVar4;
  longlong *plVar5;
  longlong *plVar6;
  ulonglong uVar7;
  
  uVar3 = RhpFindProvider(param_1);
  uVar7 = 0;
  if (uVar3 == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
    uVar7 = 0xc000000d;
    goto LAB_1c001b6bc;
  }
  if ((longlong **)RhConnectionListHead == &RhConnectionListHead) {
LAB_1c001b5f0:
    param_2[7] = 1;
    if ((longlong **)RhConnectionListHead[1] == &RhConnectionListHead) {
      *param_2 = (longlong)RhConnectionListHead;
      param_2[1] = (longlong)&RhConnectionListHead;
      RhConnectionListHead[1] = (longlong)param_2;
      RhConnectionListHead = param_2;
      goto LAB_1c001b658;
    }
LAB_1c001b672:
    plVar6 = (longlong *)0x3;
    pcVar1 = (code *)swi(0x29);
    lVar4 = (*pcVar1)();
  }
  else {
    plVar6 = DAT_1c0016788;
    if (DAT_1c0016788[7] == -1) {
      if ((ulonglong)RhConnectionListHead[7] < 2) {
        plVar2 = (longlong *)*RhConnectionListHead;
        plVar6 = RhConnectionListHead;
        while (plVar5 = plVar2, (longlong **)plVar5 != &RhConnectionListHead) {
          if (plVar6[7] + 1U < (ulonglong)plVar5[7]) goto LAB_1c001b639;
          plVar6 = plVar5;
          plVar2 = (longlong *)*plVar5;
        }
        uVar7 = 0x8000001a;
        goto LAB_1c001b6bc;
      }
      goto LAB_1c001b5f0;
    }
LAB_1c001b639:
    param_2[7] = plVar6[7] + 1;
    lVar4 = *plVar6;
    param_2[1] = (longlong)plVar6;
    *param_2 = *plVar6;
    *plVar6 = (longlong)param_2;
    *(longlong **)(lVar4 + 8) = param_2;
LAB_1c001b658:
    LOCK();
    *(int *)(uVar3 + 0x50) = *(int *)(uVar3 + 0x50) + 1;
    UNLOCK();
    param_2[6] = uVar3;
    lVar4 = uVar3 + 0x10;
    plVar6 = *(longlong **)(uVar3 + 0x18);
    param_2 = param_2 + 2;
    if (*plVar6 != lVar4) goto LAB_1c001b672;
  }
  *param_2 = lVar4;
  param_2[1] = (longlong)plVar6;
  *plVar6 = (longlong)param_2;
  *(longlong **)(lVar4 + 8) = param_2;
LAB_1c001b6bc:
  return uVar7 & 0xffffffff;
}



===== RhpRegisterProviderDevice @ 1c001b6d4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong RhpRegisterProviderDevice
                    (undefined8 param_1,ushort *param_2,ushort *param_3,undefined8 param_4)

{
  uint uVar1;
  ushort *puVar2;
  ulonglong uVar3;
  undefined8 *puVar4;
  ulonglong uVar5;
  undefined8 local_e8;
  undefined4 local_e0;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  code *local_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined *local_b0;
  undefined4 local_a8;
  undefined4 local_a4;
  code *local_a0;
  code *local_98;
  code *local_90;
  undefined4 local_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 local_68;
  undefined4 local_5c;
  undefined4 local_58;
  
  local_b0 = (undefined *)((ulonglong)local_b0 & 0xffffffff00000000);
  local_e0 = 0;
  uStack_dc = 0;
  uStack_d8 = 0;
  uStack_d4 = 0;
  local_d0 = (code *)0x0;
  uStack_c8 = 0;
  local_c0 = 0;
  uStack_b8 = 0;
  memset(&local_a8,0,0x88);
  local_e8 = 0;
  puVar2 = (ushort *)ExAllocatePool2(0x100,0x38,0x48736552);
  if (puVar2 == (ushort *)0x0) {
    uVar5 = 0xc000009a;
  }
  else {
    puVar2[0x18] = 1;
    puVar2[0x19] = 0;
    *(undefined8 *)(puVar2 + 0x10) = param_4;
    ObfReferenceObject(param_4);
    uVar3 = RhpCopyUnicodeString(puVar2,param_2);
    uVar5 = uVar3 & 0xffffffff;
    if (-1 < (int)uVar3) {
      uVar3 = RhpCopyUnicodeString(puVar2 + 8,param_3);
      uVar5 = uVar3 & 0xffffffff;
      if (-1 < (int)uVar3) {
        uStack_dc = 0;
        uStack_d8 = 0;
        uStack_d4 = 0;
        local_b0 = PTR__WDF_RH_WDF_TARGET_CONTEXT_TYPE_INFO_1c0016088;
        local_d0 = RhpEvtDestroyWdfTargetCallback;
        local_c0 = 0;
        uStack_b8 = 0;
        local_e0 = 0x38;
        uStack_c8 = 0x100000001;
        uVar1 = (**(code **)(WdfFunctions_01015 + 0x538))
                          (WdfDriverGlobals,param_1,&local_e0,&local_e8);
        uVar5 = (ulonglong)uVar1;
        if (-1 < (int)uVar1) {
          *(undefined8 *)(puVar2 + 0x14) = local_e8;
          local_e8 = 0;
          puVar4 = (undefined8 *)
                   (**(code **)(WdfFunctions_01015 + 0x650))
                             (WdfDriverGlobals,*(undefined8 *)(puVar2 + 0x14),
                              PTR__WDF_RH_WDF_TARGET_CONTEXT_TYPE_INFO_1c0016088);
          *puVar4 = puVar2;
          memset(&local_a8,0,0x88);
          local_78 = *(undefined4 *)param_3;
          uStack_74 = *(undefined4 *)(param_3 + 2);
          uStack_70 = *(undefined4 *)(param_3 + 4);
          uStack_6c = *(undefined4 *)(param_3 + 6);
          local_a0 = RhpEvtIoTargetQueryRemove;
          local_a8 = 0x88;
          local_90 = RhpEvtIoTargetRemoveComplete;
          local_98 = RhpEvtIoTargetRemoveCanceled;
          local_a4 = 2;
          local_68 = 0x20000;
          local_58 = 0x40;
          local_5c = 1;
          uVar1 = (**(code **)(WdfFunctions_01015 + 0x540))
                            (WdfDriverGlobals,*(undefined8 *)(puVar2 + 0x14),&local_a8);
          uVar5 = (ulonglong)uVar1;
          if (-1 < (int)uVar1) {
            (**(code **)(WdfFunctions_01015 + 0x548))
                      (WdfDriverGlobals,*(undefined8 *)(puVar2 + 0x14));
            uVar3 = RhpAddProviderTarget(puVar2);
            uVar5 = uVar3 & 0xffffffff;
            if (-1 < (int)uVar3) {
              return uVar5;
            }
          }
        }
      }
    }
    if (*(longlong *)(puVar2 + 0x14) == 0) {
      RhpDereferenceTargetData((undefined8 *)puVar2);
    }
    else {
      (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
    }
  }
  return uVar5;
}



===== RhpUpdateActiveBothInitialPolarity @ 1c001b954 =====

undefined8 RhpUpdateActiveBothInitialPolarity(int param_1,undefined1 param_2)

{
  longlong *plVar1;
  undefined8 uVar2;
  
  ExAcquireFastMutex(&RhTranslationCacheLock);
  plVar1 = RhpFindConnectionByInterruptVector(param_1);
  uVar2 = 0;
  if (plVar1 != (longlong *)0x0) {
    LOCK();
    *(int *)((longlong)plVar1 + 0x74) = *(int *)((longlong)plVar1 + 0x74) + 1;
    UNLOCK();
  }
  ExReleaseFastMutex(&RhTranslationCacheLock);
  if (plVar1 == (longlong *)0x0) {
    uVar2 = 0xc0000225;
  }
  else {
    if ((((short)plVar1[8] == 1) && (*(short *)((longlong)plVar1 + 0x42) == 1)) &&
       ((*(byte *)(plVar1[9] + 7) & 4) != 0)) {
      *(undefined1 *)((longlong)plVar1 + 0x79) = param_2;
    }
    else {
      uVar2 = 0xc000000d;
    }
    RhpDereferenceConnection(plVar1);
  }
  return uVar2;
}



===== RhpUpdateConnectionById @ 1c001ba00 =====

undefined8 RhpUpdateConnectionById(longlong param_1,void *param_2,longlong param_3)

{
  uint uVar1;
  longlong lVar2;
  longlong *plVar3;
  void *_Dst;
  void *_Src;
  undefined8 uVar4;
  int iVar5;
  
  _Src = param_2;
  ExAcquireFastMutex(&RhTranslationCacheLock);
  plVar3 = RhpFindAndReferenceConnectionByIdLocked(param_1);
  uVar4 = 0;
  if (plVar3 == (longlong *)0x0) {
    ExReleaseFastMutex(&RhTranslationCacheLock);
    return 0xc0000225;
  }
  if (((char)plVar3[0xf] == '\0') && (plVar3[0xb] == 0)) {
    uVar1 = *(uint *)(plVar3 + 10);
    _Dst = (void *)ExAllocatePool2(0x100,(ulonglong)uVar1,0x48736552);
    plVar3[0xb] = (longlong)_Dst;
    *(uint *)(plVar3 + 0xc) = uVar1;
    if (_Dst == (void *)0x0) {
      uVar4 = 0xc000009a;
      goto LAB_1c001bbc1;
    }
    _Src = (void *)plVar3[9];
    memcpy(_Dst,_Src,(ulonglong)uVar1);
  }
  iVar5 = (int)param_2;
  if (iVar5 == 0) {
    lVar2 = plVar3[9];
    *(undefined1 *)(lVar2 + 9) = *(undefined1 *)(param_3 + 10);
    *(undefined2 *)(lVar2 + 0xc) = *(undefined2 *)(param_3 + 0xc);
    *(undefined2 *)(lVar2 + 10) = *(undefined2 *)(param_3 + 0xe);
  }
  else if (iVar5 == 2) {
    lVar2 = plVar3[9];
    *(undefined2 *)(lVar2 + 0x13) = *(undefined2 *)(param_3 + 10);
    *(undefined4 *)(lVar2 + 0xc) = *(undefined4 *)(param_3 + 0xc);
    *(ushort *)(lVar2 + 7) = (ushort)*(byte *)(param_3 + 0x12) * 2 | *(ushort *)(lVar2 + 7) & 0xfffd
    ;
    *(undefined1 *)(lVar2 + 0x12) = *(undefined1 *)(param_3 + 0x10);
    *(undefined1 *)(lVar2 + 0x11) = *(undefined1 *)(param_3 + 0x11);
    *(undefined1 *)(lVar2 + 0x10) = *(undefined1 *)(param_3 + 0x13);
  }
  else if (iVar5 == 3) {
    lVar2 = plVar3[9];
    *(undefined4 *)(lVar2 + 0xc) = *(undefined4 *)(param_3 + 0xc);
    *(undefined2 *)(lVar2 + 0x10) = *(undefined2 *)(param_3 + 0x10);
    *(undefined2 *)(lVar2 + 7) = *(undefined2 *)(param_3 + 10);
  }
  else if (iVar5 == 4) {
    lVar2 = plVar3[9];
    *(undefined4 *)(lVar2 + 0xc) = *(undefined4 *)(param_3 + 0xc);
    *(undefined2 *)(lVar2 + 7) = *(undefined2 *)(param_3 + 0x10);
    *(undefined2 *)(lVar2 + 0x10) = *(undefined2 *)(param_3 + 0x12);
    *(undefined2 *)(lVar2 + 0x12) = *(undefined2 *)(param_3 + 0x14);
    *(undefined1 *)(lVar2 + 0x14) = *(undefined1 *)(param_3 + 0x16);
  }
  else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),_Src,6,0x1d,
                       &WPP_5a306037547032d76a1bb21b8aa3fd30_Traceguids,"RhpUpdateConnectionById",
                       (char)param_2);
  }
LAB_1c001bbc1:
  ExReleaseFastMutex(&RhTranslationCacheLock);
  RhpDereferenceConnection(plVar3);
  return uVar4;
}



===== RhpUpdateConnectionByInterruptVector @ 1c001bc00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int RhpUpdateConnectionByInterruptVector(uint param_1,longlong param_2)

{
  byte bVar1;
  longlong lVar2;
  code *pcVar3;
  int iVar4;
  longlong *plVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  undefined2 uVar8;
  
  ExAcquireFastMutex(&RhTranslationCacheLock);
  plVar5 = RhpFindConnectionByInterruptVector(param_1);
  if (plVar5 != (longlong *)0x0) {
    LOCK();
    *(int *)((longlong)plVar5 + 0x74) = *(int *)((longlong)plVar5 + 0x74) + 1;
    UNLOCK();
  }
  ExReleaseFastMutex(&RhTranslationCacheLock);
  if (plVar5 == (longlong *)0x0) {
    return -0x3ffffddb;
  }
  bVar1 = *(byte *)(param_2 + 7);
  uVar6 = (ulonglong)(*(char *)(param_2 + 6) != '\0');
  if (bVar1 == 0) {
    uVar7 = 1;
LAB_1c001bcde:
    lVar2 = plVar5[9];
    *(undefined2 *)(lVar2 + 0xc) = *(undefined2 *)(param_2 + 10);
    *(undefined1 *)(lVar2 + 9) = *(undefined1 *)(param_2 + 8);
    pcVar3 = RHUpdateInterruptPropertiesImport;
    *(ushort *)(lVar2 + 7) =
         (ushort)(*(byte *)(param_2 + 6) & 1) | *(ushort *)(lVar2 + 7) & 0xfff8 |
         (ushort)(*(byte *)(param_2 + 7) & 6);
    iVar4 = (*pcVar3)(param_1,uVar6,uVar7);
    if (-1 < iVar4) {
      iVar4 = 0;
      goto LAB_1c001bd59;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c001bd59;
    uVar8 = 0x1f;
  }
  else {
    uVar7 = 2;
    if (bVar1 == 2) goto LAB_1c001bcde;
    if (bVar1 == 4) {
      uVar7 = 3;
      goto LAB_1c001bcde;
    }
    iVar4 = -0x3ffffff3;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c001bd59;
    uVar8 = 0x1e;
    param_1 = (uint)bVar1;
    iVar4 = -0x3ffffff3;
  }
  WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar6,8,uVar8,
                     &WPP_5a306037547032d76a1bb21b8aa3fd30_Traceguids,
                     "RhpUpdateConnectionByInterruptVector",(char)param_1);
LAB_1c001bd59:
  RhpDereferenceConnection(plVar5);
  return iVar4;
}



===== RhpDeviceFirmwareLockWorker @ 1c001bd7c =====

ulonglong RhpDeviceFirmwareLockWorker(int *param_1)

{
  ulonglong uVar1;
  
  if (*param_1 == 0) {
    uVar1 = RhpAcceptDeviceFirmwareLockWorker((longlong)param_1);
  }
  else {
    uVar1 = 0xc00000bb;
  }
  return uVar1;
}



===== RhpEvtDeviceFirmwareLockWorkerWrapper @ 1c001bda0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void RhpEvtDeviceFirmwareLockWorkerWrapper(undefined8 param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(**(code **)(WdfFunctions_01015 + 0x650))
                            (WdfDriverGlobals,param_1,
                             PTR__WDF_RH_DEVICE_FIRMWARE_LOCK_WORK_ITEM_CONTEXT_TYPE_INFO_1c00160c0)
  ;
  RhpDeviceFirmwareLockWorker(piVar1);
  (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,param_1);
  return;
}



===== RhpRegisterDeviceFirmwareLockHandler @ 1c001be00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int RhpRegisterDeviceFirmwareLockHandler(undefined8 param_1)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 local_res10;
  undefined8 local_48;
  undefined4 *local_40;
  undefined8 local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 local_28;
  code *local_20;
  undefined8 local_18;
  
  local_20 = RhpDeviceFirmwareLockHandler;
  local_40 = &local_30;
  local_2c = 1;
  local_28 = 0x84;
  local_res10 = 0;
  local_30 = 0x52664441;
  local_48 = 1;
  local_38 = 0x20;
  uVar2 = AcpiConnection;
  local_18 = param_1;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x5d0))
                    (WdfDriverGlobals,AcpiConnection,0,0x32c030,&local_48,0,0,&local_res10);
  if ((iVar1 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_sDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar2,10,10,
                        &WPP_bd1a3646fa4f350d9a91c6886f68217f_Traceguids,
                        "RhpRegisterDeviceFirmwareLockHandler",(char)local_28,(char)iVar1);
  }
  return iVar1;
}



===== RhpUnregisterDeviceFirmwareLockHandler @ 1c001bf10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void RhpUnregisterDeviceFirmwareLockHandler(void)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 local_res8;
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_30;
  code *local_28;
  undefined8 local_20;
  undefined4 *local_18;
  undefined8 local_10;
  
  local_28 = RhpDeviceFirmwareLockHandler;
  local_18 = &local_38;
  local_34 = 1;
  local_30 = 0x84;
  local_res8 = 0;
  local_38 = 0x55664441;
  local_20 = 1;
  local_10 = 0x18;
  uVar2 = AcpiConnection;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x5d0))
                    (WdfDriverGlobals,AcpiConnection,0,0x32c034,&local_20,0,0,&local_res8);
  if ((iVar1 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_sDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar2,10,0xb,
                        &WPP_bd1a3646fa4f350d9a91c6886f68217f_Traceguids,
                        "RhpUnregisterDeviceFirmwareLockHandler",(char)local_30,(char)iVar1);
  }
  return;
}



===== RhpAssociateContextWithDescriptor @ 1c001c010 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong RhpAssociateContextWithDescriptor
                    (uint *param_1,uint param_2,longlong param_3,longlong param_4)

{
  short sVar1;
  undefined2 uVar2;
  uint uVar3;
  longlong lVar4;
  longlong lVar5;
  ulonglong uVar6;
  longlong *plVar7;
  uint *puVar8;
  ushort *puVar9;
  uint *puVar10;
  longlong *plVar11;
  ulonglong uVar12;
  undefined8 uVar13;
  undefined1 auStackY_e8 [32];
  undefined8 *puVar14;
  uint local_98 [2];
  longlong *local_90;
  undefined4 local_88;
  undefined4 uStack_84;
  ushort local_80 [8];
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  ulonglong local_50;
  
  local_50 = __security_cookie ^ (ulonglong)auStackY_e8;
  plVar11 = (longlong *)0x0;
  local_98[0] = 0;
  puVar9 = (ushort *)(*(longlong *)(param_4 + -0x30) + 0x30);
  local_90 = (longlong *)0x0;
  puVar8 = (uint *)0x0;
  local_70 = 0;
  uStack_68 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_80[0] = 0;
  local_80[1] = 0;
  local_80[2] = 0;
  local_80[3] = 0;
  local_80[4] = 0;
  local_80[5] = 0;
  local_80[6] = 0;
  local_80[7] = 0;
  uVar6 = RhpCopyUnicodeString(local_80,puVar9);
  uVar12 = uVar6 & 0xffffffff;
  if ((int)uVar6 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar9,9,0x16,
                         &WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,
                         "RhpAssociateContextWithDescriptor",(char)uVar6);
    }
  }
  else {
    puVar14 = &local_70;
    puVar9 = local_80;
    uVar6 = RhpGetOpRegionConnection
                      (param_1,param_2,puVar9,*(undefined8 *)(param_3 + 0xb0),(undefined2 *)puVar14)
    ;
    uVar12 = uVar6 & 0xffffffff;
    if (-1 < (int)uVar6) {
      local_88 = uStack_68._4_4_;
      uStack_84 = (undefined4)local_60;
      lVar4 = CONCAT44((undefined4)local_60,uStack_68._4_4_);
      plVar7 = RhpFindAndReferenceConnectionById(lVar4);
      if (plVar7 == (longlong *)0x0) {
        uVar12 = 0xc0000225;
      }
      else {
        lVar5 = plVar7[8];
        sVar1 = (short)lVar5;
        uVar2 = *(undefined2 *)((longlong)plVar7 + 0x42);
        RhpDereferenceConnection(plVar7);
        uVar3 = *(uint *)(param_3 + 0x40);
        if (((uVar3 == 8) && (sVar1 != 1)) || ((uVar3 == 9 && (sVar1 != 2)))) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_sDDq
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),(ulonglong)uVar3,puVar9,0x17,
                       puVar14,"RhpAssociateContextWithDescriptor",(char)uVar3,(char)lVar5,
                       (char)*(undefined8 *)(param_3 + 0xb0));
          }
          uVar12 = 0xc0000001;
        }
        else {
          puVar10 = local_98;
          *(short *)(param_4 + 0x18) = sVar1;
          *(undefined2 *)(param_4 + 0x1a) = uVar2;
          uVar6 = RhpEnsureArraySize(&local_90,puVar10);
          plVar11 = local_90;
          uVar12 = uVar6 & 0xffffffff;
          if ((int)uVar6 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_sq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar10,puVar9,0x18,
                                 puVar14,"RhpAssociateContextWithDescriptor",
                                 (char)*(undefined8 *)(param_3 + 0xb0));
            }
            plVar11 = local_90;
          }
          else {
            local_98[0] = 0;
            *local_90 = lVar4;
            uVar6 = RhpPrepareNewConnectionsRegionSpaceAccess
                              ((ulonglong)*(uint *)(param_3 + 0x40),puVar10,puVar9,
                               (longlong)local_90,puVar14,(uint *)0x0,local_98);
            if ((int)uVar6 == -0x3fffffdd) {
              uVar6 = (ulonglong)local_98[0];
              uVar13 = 0x48736552;
              puVar8 = (uint *)ExAllocatePool2(0x100);
              if (puVar8 == (uint *)0x0) {
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  WPP_RECORDER_SF_sLdq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
                }
                uVar12 = 0xc000009a;
                goto LAB_1c001c2c6;
              }
              uVar6 = RhpPrepareNewConnectionsRegionSpaceAccess
                                ((ulonglong)*(uint *)(param_3 + 0x40),uVar6,uVar13,(longlong)plVar11
                                 ,puVar14,puVar8,local_98);
            }
            uVar12 = uVar6 & 0xffffffff;
            if (-1 < (int)uVar6) {
              *(longlong **)(param_4 + 0x20) = plVar11;
              plVar11 = (longlong *)0x0;
              *(uint **)(param_4 + 0x28) = puVar8;
              puVar8 = (uint *)0x0;
              *(undefined4 *)(param_4 + 0x1c) = 1;
              *(uint *)(param_4 + 0x30) = local_98[0];
            }
          }
        }
      }
    }
  }
LAB_1c001c2c6:
  RhpFreeUnicodeString((undefined8 *)local_80);
  if (plVar11 != (longlong *)0x0) {
    ExFreePoolWithTag(plVar11,0x48736552);
  }
  if (puVar8 != (uint *)0x0) {
    ExFreePoolWithTag(puVar8,0x48736552);
  }
  return uVar12;
}



===== RhpCleanupCacheContext @ 1c001c330 =====

void RhpCleanupCacheContext(longlong param_1)

{
  if (*(longlong *)(param_1 + 0x20) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x20),0x48736552);
    *(undefined8 *)(param_1 + 0x20) = 0;
    *(undefined4 *)(param_1 + 0x1c) = 0;
  }
  if (*(longlong *)(param_1 + 0x28) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x28),0x48736552);
    *(undefined8 *)(param_1 + 0x28) = 0;
  }
  if (*(longlong *)(param_1 + 8) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 8),0x48736552);
    *(undefined8 *)(param_1 + 8) = 0;
  }
  return;
}



===== RhpDestroyOpRegion @ 1c001c3a8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void RhpDestroyOpRegion(void)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  
  if (AcpiConnection != 0) {
    RhpUnregisterOpRegionHandlers(AcpiConnection);
  }
  RhpAcquireOpRegionLock();
  puVar3 = DAT_1c0016768;
  while (puVar3 != &RhOpRegionRequestListHead) {
    RhOpRegionRequestAvailable = RhOpRegionRequestAvailable + -1;
    puVar1 = (undefined8 *)puVar3[1];
    *(undefined1 *)(puVar3 + 2) = 1;
    RhpReleaseOpRegionLock();
    uVar2 = (**(code **)(WdfFunctions_01015 + 0x660))(WdfDriverGlobals,puVar3);
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,uVar2);
    RhpAcquireOpRegionLock();
    puVar3 = puVar1;
  }
  RhpReleaseOpRegionLock();
  return;
}



===== RhpEvtOpRegionReleaseWorkItem @ 1c001c460 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void RhpEvtOpRegionReleaseWorkItem(undefined8 param_1)

{
  undefined8 *puVar1;
  longlong lVar2;
  
  puVar1 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_RH_OPREGION_WORKITEM_TYPE_INFO_1c0016110);
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,*puVar1,PTR__WDF_RH_OPREGION_REQUEST_TYPE_INFO_1c0016138);
  (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,param_1);
  (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x30));
  *(undefined8 *)(lVar2 + 0x30) = 0;
  RhpReleaseRequestContext(lVar2);
  return;
}



===== RhpGetRegionConnectionData @ 1c001c514 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong RhpGetRegionConnectionData(undefined8 param_1,ushort *param_2,longlong param_3)

{
  longlong lVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  ushort *puVar5;
  ulonglong uVar6;
  longlong local_res18 [2];
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  ulonglong local_b8;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined8 local_88;
  
  local_b8 = local_b8 & 0xffffffff00000000;
  local_e8 = 0;
  uStack_e0 = 0;
  local_d8 = 0;
  uStack_d0 = 0;
  local_c8 = 0;
  uStack_c0 = 0;
  memset(&local_a8,0,0x88);
  local_res18[0] = 0;
  puVar5 = param_2;
  uVar3 = RhpCopyUnicodeString((ushort *)(param_3 + 0xc0),param_2);
  uVar6 = uVar3 & 0xffffffff;
  if ((int)uVar3 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar5,9,0x24,
                         &WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,
                         "RhpGetRegionConnectionData",(char)uVar3);
    }
  }
  else {
    uVar4 = (**(code **)(WdfFunctions_01015 + 0x660))(WdfDriverGlobals,param_3);
    (**(code **)(WdfFunctions_01015 + 0x820))
              (WdfDriverGlobals,uVar4,RhpEvtOpRegionRequestCompletionRoutine,0);
    local_b8 = 0;
    local_d8 = 0;
    uStack_e0 = 0;
    local_e8 = 0x38;
    local_c8 = 0;
    uStack_c0 = 0;
    uStack_d0 = 0x100000001;
    uVar2 = (**(code **)(WdfFunctions_01015 + 0x538))
                      (WdfDriverGlobals,param_1,&local_e8,local_res18);
    uVar6 = (ulonglong)uVar2;
    if (-1 < (int)uVar2) {
      if (**(short **)(param_2 + 4) == 0x5c) {
        local_88 = (**(code **)(WdfFunctions_01015 + 0x590))(WdfDriverGlobals,AcpiConnection);
      }
      else {
        local_88 = *(undefined8 *)(param_3 + 0xb0);
      }
      local_a4 = 1;
      local_a8 = 0x88;
      uVar2 = (**(code **)(WdfFunctions_01015 + 0x540))(WdfDriverGlobals,local_res18[0],&local_a8);
      lVar1 = local_res18[0];
      uVar6 = (ulonglong)uVar2;
      if (-1 < (int)uVar2) {
        local_res18[0] = 0;
        *(longlong *)(param_3 + 0x30) = lVar1;
        uVar2 = RhpSendAcpiAsyncEvalIoctl(param_3);
        uVar6 = (ulonglong)uVar2;
      }
    }
  }
  if (local_res18[0] != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
  return uVar6;
}



===== RhpParseOpRegionRequestResult @ 1c001c73c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong RhpParseOpRegionRequestResult(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  undefined2 uVar5;
  ulonglong local_res8;
  undefined8 in_stack_ffffffffffffffb8;
  undefined8 in_stack_ffffffffffffffc0;
  ulonglong uVar6;
  undefined1 uVar7;
  
  local_res8 = 0;
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x610))
                    (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x20),&local_res8);
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x660))(WdfDriverGlobals,param_1);
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x8a0))(WdfDriverGlobals,uVar2);
  uVar4 = (**(code **)(WdfFunctions_01015 + 0x7f0))(WdfDriverGlobals);
  uVar6 = local_res8;
  if ((int)uVar4 == -0x7ffffffb) {
    if (*(int *)(param_1 + 0xb8) == 0) {
      if (uVar3 < 0x14) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar7 = (undefined1)*(undefined8 *)(param_1 + 0xb0);
          uVar5 = 0x1b;
          uVar6 = 0x14;
          goto LAB_1c001c825;
        }
      }
      else {
        if (local_res8 < *(uint *)(lVar1 + 4)) {
          *(uint *)(param_1 + 0xb8) = *(uint *)(lVar1 + 4);
          return 0x80000005;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sidq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
        }
      }
    }
    else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar7 = (undefined1)*(undefined8 *)(param_1 + 0xb0);
      uVar5 = 0x1a;
LAB_1c001c825:
      WPP_RECORDER_SF_siiq
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar2,0x80000005,uVar5,
                 in_stack_ffffffffffffffb8,in_stack_ffffffffffffffc0,(char)uVar6,(char)uVar3,uVar7);
    }
  }
  else {
    if ((int)uVar4 < 0) goto LAB_1c001c92d;
    if (uVar3 <= local_res8) {
      uVar4 = RhpValidateAcpiEvalOutputBuffer(lVar1,uVar3 & 0xffffffff,0x80000005);
      if (-1 < (int)uVar4) {
        uVar4 = RhpAssociateContextWithDescriptor
                          ((uint *)(lVar1 + 0x10),(uint)*(ushort *)(lVar1 + 0xe),param_1,param_2);
      }
      goto LAB_1c001c92d;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar7 = (undefined1)*(undefined8 *)(param_1 + 0xb0);
      uVar5 = 0x1d;
      goto LAB_1c001c825;
    }
  }
  uVar4 = 0xc0000001;
LAB_1c001c92d:
  *(undefined1 *)(param_2 + 0x11) = 1;
  *(int *)(param_2 + 0x14) = (int)uVar4;
  return uVar4;
}



===== RhpPrepareNewConnectionsGpioRegionSpaceAccess @ 1c001c954 =====

ulonglong RhpPrepareNewConnectionsGpioRegionSpaceAccess
                    (undefined8 param_1,undefined8 param_2,longlong param_3,undefined8 param_4,
                    uint *param_5,uint *param_6)

{
  longlong lVar1;
  byte bVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  longlong lVar5;
  uint local_res8 [2];
  longlong local_res20;
  
  local_res8[0] = 0;
  if (*param_6 < 0x10) {
    *param_6 = 0x10;
    uVar3 = 0xc0000023;
  }
  else {
    param_5[0] = 0;
    param_5[1] = 0;
    param_5[2] = 0;
    param_5[3] = 0;
    lVar5 = 0;
    while (local_res20 = 0, (int)lVar5 == 0) {
      uVar3 = RhpCacheGetConnectionDataFromId
                        (*(longlong *)(param_3 + lVar5 * 8),&local_res20,local_res8);
      lVar1 = local_res20;
      uVar4 = uVar3 & 0xffffffff;
      if ((int)uVar3 < 0) goto LAB_1c001cadf;
      if (local_res8[0] < 0x17) {
LAB_1c001ca96:
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),0,9,0x26,
                            &WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,
                            "RhpPrepareNewConnectionsGpioRegionSpaceAccess");
        }
        uVar4 = 0xc00000bb;
LAB_1c001cadf:
        if (lVar1 == 0) {
          return uVar4;
        }
        ExFreePoolWithTag(lVar1,0x48736552);
        return uVar4;
      }
      if (*(ushort *)(local_res20 + 0x11) < *(ushort *)(local_res20 + 0xe)) goto LAB_1c001ca96;
      param_5[lVar5 * 2 + 2] =
           (uint)((ulonglong)*(ushort *)(local_res20 + 0x11) -
                  (ulonglong)*(ushort *)(local_res20 + 0xe) >> 1);
      bVar2 = *(byte *)(local_res20 + 7) & 3;
      if (bVar2 == 1) {
        param_5[lVar5 * 2 + 3] = 0x80000000;
      }
      else if (bVar2 == 2) {
        param_5[lVar5 * 2 + 3] = 0x40000000;
      }
      ExFreePoolWithTag(local_res20,0x48736552);
      local_res20 = 0;
      if (~param_5[lVar5 * 2 + 2] < *param_5) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),0,9,0x27,
                            &WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,
                            "RhpPrepareNewConnectionsGpioRegionSpaceAccess");
        }
        return 0x80000005;
      }
      *param_5 = *param_5 + param_5[lVar5 * 2 + 2];
      lVar5 = 1;
    }
    uVar3 = 0;
  }
  return uVar3;
}



===== RhpPrepareNewConnectionsRegionSpaceAccess @ 1c001cb18 =====

ulonglong RhpPrepareNewConnectionsRegionSpaceAccess
                    (undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4,
                    undefined8 param_5,uint *param_6,uint *param_7)

{
  ulonglong uVar1;
  undefined8 in_stack_ffffffffffffffd8;
  
  if ((int)param_1 == 8) {
    uVar1 = RhpPrepareNewConnectionsGpioRegionSpaceAccess
                      (param_1,param_2,param_4,param_4,param_6,param_7);
  }
  else if ((int)param_1 == 9) {
    uVar1 = 0;
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,param_3,0x46,
                         in_stack_ffffffffffffffd8,"RhpPrepareNewConnectionsRegionSpaceAccess",
                         (char)param_1);
    }
    uVar1 = 0xc00000bb;
  }
  return uVar1;
}



===== RhpRegisterOpRegionHandler @ 1c001cb94 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int RhpRegisterOpRegionHandler
              (undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  undefined8 uVar2;
  ulonglong local_res18;
  undefined4 *puVar3;
  undefined4 local_58;
  undefined4 local_54;
  undefined8 *local_50;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 local_10;
  
  local_1c = 0;
  local_res18 = 0;
  local_3c = 0;
  local_54 = 0;
  local_28 = 0x486f7241;
  local_24 = 1;
  local_20 = param_2;
  local_18 = param_3;
  local_10 = (**(code **)(WdfFunctions_01015 + 0x570))(WdfDriverGlobals,param_1);
  local_3c = 0;
  local_2c = 0;
  local_54 = 0;
  local_44 = 0;
  uVar2 = 0;
  local_38 = &local_28;
  *param_4 = 0;
  param_4[1] = 0;
  puVar3 = &local_40;
  local_40 = 1;
  local_30 = 0x20;
  local_58 = 1;
  local_48 = 0x10;
  local_50 = param_4;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x5d0))
                    (WdfDriverGlobals,param_1,0,0x32c008,puVar3,&local_58,0,&local_res18);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_1,9,0x4b,
                          &WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,
                          "RhpRegisterOpRegionHandler",(char)param_2,(char)iVar1);
    }
  }
  else if ((local_res18 < 0x10) &&
          ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_sdi(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_1,uVar2,0x4c,puVar3,
                        "RhpRegisterOpRegionHandler",0x10,(char)local_res18);
  }
  return iVar1;
}



===== RhpRegisterOpRegionHandlers @ 1c001cd44 =====

int RhpRegisterOpRegionHandlers(void)

{
  undefined8 uVar1;
  int iVar2;
  undefined8 uVar3;
  undefined2 uVar4;
  
  uVar1 = AcpiConnection;
  uVar3 = 8;
  iVar2 = RhpRegisterOpRegionHandler
                    (AcpiConnection,8,RhGpioOperationRegionHandler,
                     (undefined8 *)&RhpOpRegionGpioUnregistrationInfo);
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar2;
    }
    uVar4 = 0x4d;
  }
  else {
    uVar3 = 9;
    iVar2 = RhpRegisterOpRegionHandler
                      (uVar1,9,RhSerialBusOperationRegionHandler,
                       (undefined8 *)&RhpOpRegionSpbUnregistrationInfo);
    if (-1 < iVar2) {
      return iVar2;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar2;
    }
    uVar4 = 0x4e;
  }
  WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar3,9,uVar4,
                     &WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,"RhpRegisterOpRegionHandlers",
                     (char)iVar2);
  return iVar2;
}



===== RhpRetryGetRegionConnectionData @ 1c001ce0c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong RhpRetryGetRegionConnectionData(longlong param_1)

{
  uint uVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined8 local_1c;
  undefined4 local_14;
  
  local_1c = 0;
  local_14 = 0;
  local_24 = 0;
  local_20 = 0;
  local_28 = 0x18;
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x660))(WdfDriverGlobals,param_1);
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x7c8))(WdfDriverGlobals,uVar2,&local_28);
  uVar5 = (ulonglong)uVar1;
  if (-1 < (int)uVar1) {
    uVar4 = WdfDriverGlobals;
    (**(code **)(WdfFunctions_01015 + 0x820))
              (WdfDriverGlobals,uVar2,RhpEvtOpRegionRequestCompletionRoutine,0);
    uVar3 = RhpSetBufferSizeRequestContext(uVar4,*(uint *)(param_1 + 0xb8),param_1);
    uVar5 = uVar3 & 0xffffffff;
    if ((int)uVar3 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDdq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
      }
    }
    else {
      uVar1 = RhpSendAcpiAsyncEvalIoctl(param_1);
      uVar5 = (ulonglong)uVar1;
    }
  }
  return uVar5;
}



===== RhpSendAcpiAsyncEvalIoctl @ 1c001cf20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int RhpSendAcpiAsyncEvalIoctl(longlong param_1)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined8 uVar6;
  bool bVar7;
  undefined8 local_res8;
  undefined8 local_18;
  undefined4 *puStack_10;
  
  local_res8 = 0;
  puVar5 = (undefined4 *)
           (**(code **)(WdfFunctions_01015 + 0x610))
                     (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x18),&local_res8);
  memset(puVar5 + 1,0,0x100);
  *puVar5 = 0x41696541;
  puStack_10 = puVar5 + 1;
  local_18 = 0x1000000;
  iVar3 = RtlUnicodeStringToAnsiString(&local_18,param_1 + 0xc0,0);
  if (iVar3 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sSDq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
  }
  else {
    uVar6 = (**(code **)(WdfFunctions_01015 + 0x660))(WdfDriverGlobals,param_1);
    iVar3 = (**(code **)(WdfFunctions_01015 + 0x5d8))
                      (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x30),uVar6,0x32c01c,
                       *(undefined8 *)(param_1 + 0x18),0,*(undefined8 *)(param_1 + 0x20),0);
    if (-1 < iVar3) {
      LOCK();
      *(undefined4 *)(param_1 + 0x28) = 0;
      UNLOCK();
      cVar2 = (**(code **)(WdfFunctions_01015 + 0x7e8))
                        (WdfDriverGlobals,uVar6,*(undefined8 *)(param_1 + 0x30),0);
      if (cVar2 == '\0') {
        iVar3 = (**(code **)(WdfFunctions_01015 + 0x7f0))(WdfDriverGlobals,uVar6);
      }
      else {
        iVar3 = 0x103;
        uVar4 = *(uint *)(param_1 + 0x28);
        do {
          LOCK();
          uVar1 = *(uint *)(param_1 + 0x28);
          bVar7 = uVar4 == uVar1;
          if (bVar7) {
            *(uint *)(param_1 + 0x28) = uVar4 | 1;
          }
          else {
            uVar4 = uVar1;
          }
          UNLOCK();
        } while (!bVar7);
        if ((uVar4 & 2) != 0) {
          iVar3 = 0;
        }
      }
    }
  }
  return iVar3;
}



===== RhpUnregisterOpRegionHandler @ 1c001d0e4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void RhpUnregisterOpRegionHandler(undefined8 param_1,undefined8 param_2)

{
  undefined8 local_28;
  undefined8 local_20;
  undefined8 local_18;
  
  local_28 = 1;
  local_18 = 0x10;
  local_20 = param_2;
  (**(code **)(WdfFunctions_01015 + 0x5d0))(WdfDriverGlobals,param_1,0,0x32c00c,&local_28,0,0,0);
  return;
}



===== RhpUnregisterOpRegionHandlers @ 1c001d148 =====

void RhpUnregisterOpRegionHandlers(undefined8 param_1)

{
  int iVar1;
  undefined *puVar2;
  
  if (DAT_1c0016748 != 0) {
    puVar2 = &RhpOpRegionGpioUnregistrationInfo;
    iVar1 = RhpUnregisterOpRegionHandler(param_1,&RhpOpRegionGpioUnregistrationInfo);
    if ((iVar1 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar2,9,0x4f,
                         &WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,
                         "RhpUnregisterOpRegionHandlers",(char)iVar1);
    }
  }
  if (DAT_1c0016758 != 0) {
    puVar2 = &RhpOpRegionSpbUnregistrationInfo;
    iVar1 = RhpUnregisterOpRegionHandler(param_1,&RhpOpRegionSpbUnregistrationInfo);
    if ((iVar1 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar2,9,0x50,
                         &WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,
                         "RhpUnregisterOpRegionHandlers",(char)iVar1);
    }
  }
  return;
}



===== RhEvtDriverUnload @ 1c001d230 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void RhEvtDriverUnload(undefined8 param_1)

{
  undefined8 uVar1;
  
  PlExtpUninitialize();
  if (RHUnloadTranslationInterface != (code *)0x0) {
    (*RHUnloadTranslationInterface)();
  }
  RhpDestroyTranslationCache();
  RhpDestroyOpRegion();
  RhpUnregisterDeviceFirmwareLockHandler();
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),0,1,0x16,
                      &WPP_a781b87147d030366b419d92a3dc1ed1_Traceguids,"RhEvtDriverUnload");
  }
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x3b0))(WdfDriverGlobals,param_1);
  WppCleanupKm(uVar1);
  return;
}



===== RhEvtProcessWriteRequest @ 1c001d2e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void RhEvtProcessWriteRequest(undefined8 param_1,undefined8 param_2)

{
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,0xc0000002);
  return;
}



===== RhQueryTranslatedDescriptorForGsiv @ 1c001d310 =====

ulonglong RhQueryTranslatedDescriptorForGsiv
                    (int param_1,undefined8 param_2,undefined2 *param_3,undefined8 param_4)

{
  ulonglong uVar1;
  ulonglong uVar2;
  longlong *plVar3;
  undefined4 *puVar4;
  undefined4 local_res20 [2];
  longlong local_18 [2];
  
  local_res20[0] = 0;
  plVar3 = local_18;
  local_18[0] = 0;
  puVar4 = local_res20;
  uVar1 = RhpCacheGetConnectionDataFromInterruptVector(param_1,plVar3,puVar4);
  uVar2 = uVar1 & 0xffffffff;
  if ((int)uVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),plVar3,7,0x1a,
                          &WPP_a781b87147d030366b419d92a3dc1ed1_Traceguids,
                          "RhQueryTranslatedDescriptorForGsiv",(char)param_1,(char)uVar1);
    }
  }
  else {
    uVar2 = RhpBiosGpioInterruptToIoDescriptor(param_1,local_18[0],puVar4,param_4,param_3);
    uVar2 = uVar2 & 0xffffffff;
  }
  if (local_18[0] != 0) {
    ExFreePoolWithTag(local_18[0],0x48736552);
  }
  return uVar2;
}



===== RhpConnectToAcpi @ 1c001d3d8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int RhpConnectToAcpi(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined4 local_98;
  undefined4 local_94;
  undefined8 local_78;
  
  memset(&local_98,0,0x88);
  local_a8 = 0;
  local_c8 = 0;
  uStack_d0 = 0;
  local_d8 = 0x38;
  local_b8 = 0;
  uStack_b0 = 0;
  uStack_c0 = 0x100000001;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x538))
                    (WdfDriverGlobals,param_1,&local_d8,&AcpiConnection);
  if (-1 < iVar1) {
    local_98 = 0x88;
    local_94 = 1;
    local_78 = param_2;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x540))(WdfDriverGlobals,AcpiConnection,&local_98);
    if (-1 < iVar1) {
      return iVar1;
    }
  }
  if (AcpiConnection != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
    AcpiConnection = 0;
  }
  return iVar1;
}



===== RhpInitialize @ 1c001d4e8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int RhpInitialize(undefined8 param_1)

{
  int iVar1;
  undefined *puVar2;
  longlong lVar3;
  undefined1 auStackY_a8 [32];
  longlong local_68 [2];
  wchar_t *local_58;
  wchar_t local_50 [28];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  builtin_wcsncpy(local_50,L"\\DosDevices\\RESOURCE_HUB",0x19);
  local_58 = local_50;
  local_68[1] = 0x320030;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x280))(WdfDriverGlobals,param_1,local_68 + 1);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_1,2,0x1e,
                         &WPP_a781b87147d030366b419d92a3dc1ed1_Traceguids,"RhpInitialize",
                         (char)iVar1);
    }
  }
  else {
    _DAT_1c00167c8 = 0;
    _DAT_1c00167d0 = 0;
    _RhTranslationCacheLock = 1;
    KeInitializeEvent(&DAT_1c00167d8,1,0);
    local_68[0] = 0;
    _DAT_1c0016708 = 0;
    puVar2 = &DAT_1c0016718;
    _DAT_1c0016710 = 0;
    DAT_1c0016788 = &RhConnectionListHead;
    lVar3 = 1;
    RhConnectionListHead = &RhConnectionListHead;
    DAT_1c0016798 = &RhInterruptListHead;
    RhInterruptListHead = &RhInterruptListHead;
    DAT_1c00167a8 = &RhProviderListHead;
    RhProviderListHead = &RhProviderListHead;
    _RhOpRegionLock = 1;
    KeInitializeEvent(&DAT_1c0016718,1,0);
    RhOpRegionRequestAvailable = 0;
    DAT_1c0016768 = &RhOpRegionRequestListHead;
    RhOpRegionRequestListHead = &RhOpRegionRequestListHead;
    iVar1 = RhpGetRequestContext(puVar2,lVar3,local_68);
    if (-1 < iVar1) {
      RhpReleaseRequestContext(local_68[0]);
    }
  }
  return iVar1;
}



===== RhpProcessTranslationInterfaceQueryIoctl @ 1c001d6b8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int RhpProcessTranslationInterfaceQueryIoctl
              (undefined8 param_1,undefined8 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  uint uVar5;
  undefined2 uVar6;
  undefined4 *local_res20;
  ushort *local_38;
  undefined8 local_30;
  
  local_38 = (ushort *)0x0;
  local_30 = 0;
  local_res20 = (undefined4 *)0x0;
  uVar3 = param_2;
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x868))
                    (WdfDriverGlobals,param_2,0x78,&local_38,&local_30);
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar2;
    }
    uVar6 = 0x30;
    param_2 = uVar3;
  }
  else {
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,param_2,0x78,&local_res20,0);
    puVar1 = local_res20;
    if (-1 < iVar2) {
      if ((*local_38 < 0x28) ||
         (uVar4 = (ulonglong)local_38[0x10], (ulonglong)*local_38 - 0x28 < uVar4)) {
        return -0x3ffffff3;
      }
      RHUnloadTranslationInterface = *(undefined8 *)(uVar4 + 8 + (longlong)local_38);
      param_2 = *(undefined8 *)(uVar4 + (longlong)local_38);
      RHGetFullyQualifiedBiosName = *(undefined8 *)(uVar4 + 0x10 + (longlong)local_38);
      RHAllocateNewSecondaryInterruptGsivImport = *(undefined8 *)(uVar4 + 0x18 + (longlong)local_38)
      ;
      RHUpdateInterruptPropertiesImport = *(undefined8 *)(uVar4 + 0x20 + (longlong)local_38);
      memset(local_res20,0,0x78);
      *puVar1 = 0x10078;
      *(code **)(puVar1 + 4) = _guard_check_icall;
      *(undefined2 *)(puVar1 + 8) = 0x50;
      *(code **)(puVar1 + 6) = _guard_check_icall;
      uVar3 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
      *param_3 = 0x78;
      *(undefined8 *)(local_res20 + 10) = uVar3;
      *(code **)(local_res20 + 0xe) = RhTranslateBiosToNtResources;
      *(code **)(local_res20 + 0x10) = RhBiosNameToDeviceCallback;
      *(code **)(local_res20 + 0x12) = RhQueryTranslatedDescriptorForGsiv;
      if (AcpiConnection != 0) {
        return 0;
      }
      uVar3 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
      iVar2 = RhpConnectToAcpi(uVar3,param_2);
      if (-1 < iVar2) {
        iVar2 = RhpRegisterOpRegionHandlers();
        if (iVar2 < 0) {
          return iVar2;
        }
        iVar2 = RhpRegisterDeviceFirmwareLockHandler(uVar3);
        return iVar2;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return iVar2;
      }
      uVar6 = 0x32;
      uVar5 = 1;
      goto LAB_1c001d73d;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar2;
    }
    uVar6 = 0x31;
  }
  uVar5 = 6;
LAB_1c001d73d:
  WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,uVar5,uVar6,
                     &WPP_a781b87147d030366b419d92a3dc1ed1_Traceguids,
                     "RhpProcessTranslationInterfaceQueryIoctl",(char)iVar2);
  return iVar2;
}



===== RhpProcessUpdateActiveBothInitialPolarityIoctl @ 1c001d93c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong RhpProcessUpdateActiveBothInitialPolarityIoctl
                    (undefined8 param_1,undefined8 param_2,undefined4 *param_3)

{
  longlong lVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  undefined2 uVar7;
  longlong local_res8;
  undefined8 local_res18;
  undefined8 local_res20;
  undefined8 local_18 [2];
  
  lVar1 = WdfFunctions_01015;
  local_res8 = 0;
  local_res18 = 0;
  local_18[0] = 0;
  local_res20 = 0;
  *param_3 = 0;
  uVar4 = param_2;
  uVar2 = (**(code **)(lVar1 + 0x868))(WdfDriverGlobals,param_2,0xc,&local_res8,&local_res18);
  uVar3 = (ulonglong)uVar2;
  if ((int)uVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return uVar3;
    }
    uVar7 = 0x39;
    param_2 = uVar4;
  }
  else {
    uVar2 = (**(code **)(WdfFunctions_01015 + 0x870))
                      (WdfDriverGlobals,param_2,4,local_18,&local_res20);
    uVar3 = (ulonglong)uVar2;
    if (-1 < (int)uVar2) {
      uVar5 = CONCAT71((int7)((ulonglong)param_2 >> 8),~-(*(char *)(local_res8 + 8) != '\0')) &
              0xffffffffffffff02;
      uVar3 = RhpUpdateActiveBothInitialPolarity(*(int *)(local_res8 + 4),(char)uVar5);
      uVar6 = uVar3 & 0xffffffff;
      if ((int)uVar3 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return uVar6;
        }
        WPP_RECORDER_SF_sDDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return uVar6;
      }
      WPP_RECORDER_SF_sDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar5,6,0x3c,
                          &WPP_a781b87147d030366b419d92a3dc1ed1_Traceguids,
                          "RhpProcessUpdateActiveBothInitialPolarityIoctl",
                          (char)*(undefined4 *)(local_res8 + 4),*(undefined1 *)(local_res8 + 8));
      return uVar6;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return uVar3;
    }
    uVar7 = 0x3a;
  }
  WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,6,uVar7,
                     &WPP_a781b87147d030366b419d92a3dc1ed1_Traceguids,
                     "RhpProcessUpdateActiveBothInitialPolarityIoctl",(char)uVar2);
  return uVar3;
}



===== RhpProcessUpdateConnectionPropertiesIoctl @ 1c001db00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong RhpProcessUpdateConnectionPropertiesIoctl
                    (undefined8 param_1,undefined8 param_2,undefined4 *param_3)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  ulonglong uVar4;
  void *pvVar5;
  uint *puVar6;
  ulonglong uVar7;
  undefined2 uVar8;
  longlong local_res8;
  undefined8 local_res18 [2];
  
  lVar1 = WdfFunctions_01015;
  local_res8 = 0;
  local_res18[0] = 0;
  *param_3 = 0;
  uVar2 = (**(code **)(lVar1 + 0x868))(WdfDriverGlobals,param_2,0x10,&local_res8,local_res18);
  uVar7 = (ulonglong)uVar2;
  if ((int)uVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,6,0x2a,
                         &WPP_a781b87147d030366b419d92a3dc1ed1_Traceguids,
                         "RhpProcessUpdateConnectionPropertiesIoctl",(char)uVar2);
    }
  }
  else {
    uVar2 = *(uint *)(local_res8 + 4);
    pvVar5 = (void *)(ulonglong)uVar2;
    if (uVar2 == 1) {
      puVar6 = (uint *)(local_res8 + 8);
      uVar2 = *puVar6;
      uVar3 = RhpUpdateConnectionByInterruptVector(uVar2,(longlong)puVar6);
      uVar7 = (ulonglong)uVar3;
      if ((int)uVar3 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return uVar7;
        }
        uVar8 = 0x2b;
      }
      else {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return uVar7;
        }
        uVar8 = 0x2c;
      }
      WPP_RECORDER_SF_sDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar6,6,uVar8,
                          &WPP_a781b87147d030366b419d92a3dc1ed1_Traceguids,
                          "RhpProcessUpdateConnectionPropertiesIoctl",(char)uVar2,(char)uVar3);
    }
    else if ((((uVar2 == 0) || (uVar2 == 2)) || (uVar2 == 3)) || (uVar2 == 4)) {
      lVar1 = *(longlong *)(local_res8 + 8);
      uVar4 = RhpUpdateConnectionById(lVar1,pvVar5,local_res8 + 8);
      uVar7 = uVar4 & 0xffffffff;
      if ((int)uVar4 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return uVar7;
        }
        uVar8 = 0x2e;
      }
      else {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return uVar7;
        }
        uVar8 = 0x2f;
      }
      WPP_RECORDER_SF_siD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pvVar5,6,uVar8,
                          &WPP_a781b87147d030366b419d92a3dc1ed1_Traceguids,
                          "RhpProcessUpdateConnectionPropertiesIoctl",(char)lVar1,(char)uVar4);
    }
    else {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pvVar5,6,0x2d,
                           &WPP_a781b87147d030366b419d92a3dc1ed1_Traceguids,
                           "RhpProcessUpdateConnectionPropertiesIoctl",(char)uVar2);
      }
      uVar7 = 0xc00000bb;
    }
  }
  return uVar7;
}



===== WppCleanupKm @ 1c001dd28 =====

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



===== WppTraceCallback @ 1c001dde0 =====

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



===== RhBiosNameToDeviceCallback @ 1c001e070 =====

void RhBiosNameToDeviceCallback(undefined8 param_1,ushort *param_2,longlong param_3)

{
  RhpConnectProviderDevice(param_1,param_2,param_3);
  return;
}



===== RhTranslateBiosToNtResources @ 1c001e090 =====

uint RhTranslateBiosToNtResources
               (undefined8 param_1,undefined8 param_2,char *param_3,uint param_4,undefined8 param_5,
               undefined8 *param_6,uint *param_7)

{
  uint uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  ushort *puVar4;
  ushort local_28 [8];
  
  local_28[0] = 0;
  local_28[1] = 0;
  local_28[2] = 0;
  local_28[3] = 0;
  local_28[4] = 0;
  local_28[5] = 0;
  local_28[6] = 0;
  local_28[7] = 0;
  if ((((param_3 == (char *)0x0) || (param_4 == 0)) || (param_6 == (undefined8 *)0x0)) ||
     (*param_7 < 0x38)) {
    uVar1 = 0xc000000d;
  }
  else {
    *param_6 = 0;
    param_6[1] = 0;
    puVar4 = local_28;
    param_6[2] = 0;
    param_6[3] = 0;
    param_6[4] = 0;
    param_6[5] = 0;
    param_6[6] = 0;
    *(undefined4 *)param_6 = 1;
    uVar1 = RhpGetProviderBiosNameFromDescriptor(param_2,param_3,param_4,(undefined8 *)puVar4);
    if (-1 < (int)uVar1) {
      uVar2 = RhpTranslateAndCacheConnection
                        (local_28,param_3,param_4,puVar4,(undefined2 *)(param_6 + 1));
      uVar1 = (uint)uVar2;
      if (-1 < (int)uVar1) {
        uVar3 = RhpAddBiosNameToResult(local_28,(longlong)param_6,param_7);
        uVar1 = (uint)uVar3;
        if (-1 < (int)uVar1) {
          if (*(char *)((longlong)param_6 + 9) == -0x7c) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_DDSq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
            }
          }
          else if ((*(char *)((longlong)param_6 + 9) == '\x02') &&
                  ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
            WPP_RECORDER_SF_DSq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
          }
        }
      }
    }
  }
  RhpFreeUnicodeString((undefined8 *)local_28);
  return uVar1;
}



===== RhpAddBiosNameToResult @ 1c001e214 =====

undefined8 RhpAddBiosNameToResult(undefined8 param_1,longlong param_2,uint *param_3)

{
  uint uVar1;
  undefined8 uVar2;
  uint uVar3;
  longlong local_18;
  longlong lStack_10;
  
  uVar1 = RtlxUnicodeStringToAnsiSize();
  if (uVar1 < 0x8000) {
    uVar3 = uVar1 + 0x30;
    if (uVar3 < 0x38) {
      uVar3 = 0x38;
    }
    if (*param_3 < uVar3) {
      uVar2 = 0xc0000023;
    }
    else {
      local_18 = (ulonglong)(ushort)uVar1 << 0x10;
      lStack_10 = param_2 + 0x30;
      uVar2 = RtlUnicodeStringToAnsiString(&local_18,param_1,0);
      if ((int)uVar2 < 0) {
        return uVar2;
      }
      *(undefined4 *)(param_2 + 0x28) = 0x30;
      *(uint *)(param_2 + 0x2c) = (ushort)local_18 + 1;
      uVar2 = 0;
    }
    *param_3 = uVar3;
  }
  else {
    uVar2 = 0xc000000d;
  }
  return uVar2;
}



===== RhpBiosFunctionConfigToNtResource @ 1c001e2c8 =====

ulonglong RhpBiosFunctionConfigToNtResource
                    (ushort *param_1,void *param_2,uint param_3,undefined8 param_4,
                    undefined2 *param_5)

{
  ulonglong uVar1;
  
  uVar1 = RhpCacheAddConnection(param_1,3,1,0,param_2,param_3,0);
  if ((int)uVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sSD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),0,7,0x14,
                          &WPP_cf4f8fa19d3932c70975ae2eca242000_Traceguids,
                          "RhpBiosFunctionConfigToNtResource",*(wchar_t **)(param_1 + 4),(char)uVar1
                         );
    }
  }
  else {
    *(undefined4 *)(param_5 + 6) = 0;
    *(undefined4 *)(param_5 + 8) = 0;
    *param_5 = 0x8400;
    param_5[4] = 0x103;
  }
  return uVar1 & 0xffffffff;
}



===== RhpBiosGpioInterruptToIoDescriptor @ 1c001e39c =====

undefined8
RhpBiosGpioInterruptToIoDescriptor
          (undefined4 param_1,longlong param_2,undefined8 param_3,undefined8 param_4,
          undefined2 *param_5)

{
  ushort uVar1;
  ushort uVar2;
  undefined8 uVar3;
  
  uVar3 = 0;
  *param_5 = 0x200;
  param_5[2] = 0x10;
  *(undefined4 *)(param_5 + 6) = param_1;
  *(undefined4 *)(param_5 + 4) = param_1;
  uVar1 = *(ushort *)(param_2 + 7);
  uVar2 = (uVar1 & 1) + 0x10;
  param_5[2] = uVar2;
  *(byte *)(param_5 + 1) = (byte)uVar1 >> 2 & 2 | 1;
  if ((uVar1 & 0x10) != 0) {
    param_5[2] = uVar2 | 0x20;
  }
  uVar1 = uVar1 & 6;
  if (uVar1 == 4) {
    *(undefined4 *)(param_5 + 8) = 10;
  }
  else if (uVar1 == 2) {
    *(undefined4 *)(param_5 + 8) = 2;
  }
  else if (uVar1 == 0) {
    *(undefined4 *)(param_5 + 8) = 0;
  }
  else {
    uVar3 = 0xc00000bb;
  }
  return uVar3;
}



===== RhpBiosGpioInterruptToNtResource @ 1c001e42c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong RhpBiosGpioInterruptToNtResource
                    (ushort *param_1,void *param_2,undefined8 param_3,undefined8 param_4,
                    undefined2 *param_5)

{
  undefined1 uVar1;
  uint uVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  undefined2 uVar6;
  void *pvVar7;
  uint local_res20 [2];
  
  local_res20[0] = 0;
  uVar3 = (uint)param_3;
  uVar4 = (ulonglong)*(ushort *)((longlong)param_2 + 0x11) -
          (ulonglong)*(ushort *)((longlong)param_2 + 0xe) >> 1;
  if ((short)uVar4 == 1) {
    if (*(short *)((ulonglong)*(ushort *)((longlong)param_2 + 0xe) + (longlong)param_2) != -1) {
      pvVar7 = param_2;
      uVar2 = RhpCacheGetInterruptVector(param_1,param_2,param_3,param_2,uVar3,local_res20);
      if (((int)uVar2 < 0) || (local_res20[0] == 0)) {
        if (RHAllocateNewSecondaryInterruptGsivImport == (code *)0x0) {
          return 0xc0000001;
        }
        uVar2 = (*RHAllocateNewSecondaryInterruptGsivImport)(0,0,local_res20);
        if ((int)uVar2 < 0) {
          return (ulonglong)uVar2;
        }
        param_3 = 1;
        pvVar7 = (void *)(ulonglong)local_res20[0];
        uVar5 = 1;
        uVar4 = RhpCacheAddConnection(param_1,1,1,local_res20[0],param_2,uVar3,0);
        if ((int)uVar4 == 0x40000000) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            param_3 = 7;
            WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar5,7,0x11,
                               &WPP_cf4f8fa19d3932c70975ae2eca242000_Traceguids,
                               "RhpBiosGpioInterruptToNtResource",(char)local_res20[0]);
          }
          pvVar7 = param_2;
          uVar3 = RhpCacheGetInterruptVector(param_1,uVar5,param_3,param_2,uVar3,local_res20);
          if ((int)uVar3 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
              return (ulonglong)uVar3;
            }
            WPP_RECORDER_SF_sS(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar5,7,0x12,
                               &WPP_cf4f8fa19d3932c70975ae2eca242000_Traceguids,
                               "RhpBiosGpioInterruptToNtResource",*(wchar_t **)(param_1 + 4));
            return (ulonglong)uVar3;
          }
        }
        else if ((int)uVar4 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return uVar4 & 0xffffffff;
          }
          WPP_RECORDER_SF_sSDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
          return uVar4 & 0xffffffff;
        }
      }
      uVar4 = RhpBiosGpioInterruptToIoDescriptor
                        (local_res20[0],(longlong)param_2,param_3,pvVar7,param_5);
      return uVar4 & 0xffffffff;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0xc000000d;
    }
    uVar6 = 0x10;
    uVar1 = (undefined1)param_3;
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0xc000000d;
    }
    uVar6 = 0xf;
    uVar1 = (undefined1)uVar4;
  }
  WPP_RECORDER_SF_siD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,7,uVar6,
                      &WPP_cf4f8fa19d3932c70975ae2eca242000_Traceguids,
                      "RhpBiosGpioInterruptToNtResource",(char)param_2,uVar1);
  return 0xc000000d;
}



===== RhpBiosGpioIoToNtResource @ 1c001e6b4 =====

ulonglong RhpBiosGpioIoToNtResource
                    (ushort *param_1,void *param_2,uint param_3,undefined8 param_4,
                    undefined2 *param_5)

{
  ulonglong uVar1;
  
  uVar1 = RhpCacheAddConnection(param_1,1,2,0,param_2,param_3,0);
  if ((int)uVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sSD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),0,7,0x15,
                          &WPP_cf4f8fa19d3932c70975ae2eca242000_Traceguids,
                          "RhpBiosGpioIoToNtResource",*(wchar_t **)(param_1 + 4),(char)uVar1);
    }
  }
  else {
    *(undefined4 *)(param_5 + 6) = 0;
    *(undefined4 *)(param_5 + 8) = 0;
    *param_5 = 0x8400;
    param_5[4] = 0x201;
  }
  return uVar1 & 0xffffffff;
}



===== RhpBiosSerialBusToNtResource @ 1c001e788 =====

ulonglong RhpBiosSerialBusToNtResource
                    (ushort *param_1,void *param_2,uint param_3,undefined8 param_4,
                    undefined2 *param_5)

{
  uint uVar1;
  byte bVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  
  uVar1 = *(ushort *)((longlong)param_2 + 1) + 3;
  if ((uVar1 < 0xc) || (param_3 < uVar1)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sqdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
    uVar4 = 0xc000000d;
  }
  else {
    bVar2 = *(byte *)((longlong)param_2 + 5);
    uVar3 = RhpCacheAddConnection(param_1,2,(ushort)bVar2,0,param_2,param_3,0);
    uVar4 = uVar3 & 0xffffffff;
    if ((int)uVar3 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sSD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),0,7,0x17,
                            &WPP_cf4f8fa19d3932c70975ae2eca242000_Traceguids,
                            "RhpBiosSerialBusToNtResource",*(wchar_t **)(param_1 + 4),(char)uVar3);
      }
    }
    else {
      *(undefined4 *)(param_5 + 6) = 0;
      *(undefined4 *)(param_5 + 8) = 0;
      *param_5 = 0x8400;
      *(undefined1 *)(param_5 + 4) = 2;
      *(byte *)((longlong)param_5 + 9) = bVar2;
      if (1 < *(byte *)((longlong)param_2 + 3)) {
        *(byte *)(param_5 + 1) = (*(byte *)((longlong)param_2 + 6) & 4 | 2) >> 1;
      }
    }
  }
  return uVar4;
}



===== RhpGetResourceNameFromGpioDescriptor @ 1c001e8d8 =====

undefined8 RhpGetResourceNameFromGpioDescriptor(char *param_1,uint param_2,ulonglong *param_3)

{
  ushort uVar1;
  char cVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  ulonglong local_res20;
  
  cVar2 = RhpIsBiosGpioDescriptorValid(param_1,param_2);
  if (cVar2 == '\0') {
    uVar3 = 0xc0000001;
  }
  else {
    uVar1 = *(ushort *)(param_1 + 0x11);
    local_res20 = (ulonglong)*(ushort *)(param_1 + 0x13) - (ulonglong)uVar1;
    uVar4 = 0x7fff;
    if (local_res20 < 0x7fff) {
      uVar4 = local_res20;
    }
    uVar3 = RtlStringCbLengthA(param_1 + uVar1,local_res20,&local_res20);
    if (-1 < (int)uVar3) {
      *param_3 = (ulonglong)CONCAT22((short)uVar4,(undefined2)local_res20);
      param_3[1] = (ulonglong)(param_1 + uVar1);
    }
  }
  return uVar3;
}



===== RhpIsBiosGpioDescriptorValid @ 1c001e95c =====

undefined1 RhpIsBiosGpioDescriptorValid(char *param_1,uint param_2)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  uint uVar4;
  undefined1 uVar5;
  uint uVar6;
  
  uVar5 = 0;
  if ((((0x16 < param_2) && (*param_1 == -0x74)) &&
      (uVar1 = *(ushort *)(param_1 + 0xe), 0x16 < uVar1)) && (uVar1 < param_2)) {
    uVar2 = *(ushort *)(param_1 + 0x11);
    uVar6 = (uint)uVar2;
    if (uVar6 < param_2) {
      uVar3 = *(ushort *)(param_1 + 0x13);
      if (((((uVar3 <= param_2) && (uVar1 < uVar2)) &&
           ((uVar2 < uVar3 && ((param_1[3] != '\0' && ((byte)param_1[4] < 2)))))) &&
          (uVar4 = uVar6 - uVar1, 1 < uVar4)) && ((uVar4 & 1) == 0)) {
        uVar5 = 0;
        if (((ulonglong)uVar3 - (ulonglong)uVar6) - 1 < 0x7fff) {
          uVar5 = 1;
        }
      }
    }
  }
  return uVar5;
}



===== RhpEnsureArraySize @ 1c001e9fc =====

/* WARNING: Removing unreachable block (ram,0x0001c001ea37) */

undefined8 RhpEnsureArraySize(undefined8 *param_1,uint *param_2)

{
  uint uVar1;
  void *_Src;
  void *_Dst;
  uint uVar2;
  undefined8 uVar3;
  
  uVar3 = 0;
  uVar1 = *param_2;
  uVar2 = uVar1;
  while (uVar2 == 0) {
    uVar2 = 1;
  }
  if (uVar1 < uVar2) {
    _Dst = (void *)ExAllocatePool2(0x100,uVar2 * 8,0x48736552);
    if (_Dst == (void *)0x0) {
      uVar3 = 0xc000009a;
    }
    else {
      _Src = (void *)*param_1;
      if (_Src != (void *)0x0) {
        memcpy(_Dst,_Src,(ulonglong)(uVar1 * 8));
        ExFreePoolWithTag(_Src,0x48736552);
      }
      *param_1 = _Dst;
      *param_2 = uVar2;
    }
  }
  return uVar3;
}



===== RhpGetDevicePdo @ 1c001eacc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int RhpGetDevicePdo(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  int iVar1;
  undefined8 uVar2;
  longlong local_res20;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined4 local_98;
  undefined4 local_94;
  undefined8 local_78;
  
  local_res20 = 0;
  memset(&local_98,0,0x88);
  local_a8 = 0;
  local_c8 = 0;
  uStack_d0 = 0;
  local_d8 = 0x38;
  local_b8 = 0;
  uStack_b0 = 0;
  uStack_c0 = 0x100000001;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x538))(WdfDriverGlobals,param_1,&local_d8,&local_res20)
  ;
  if (-1 < iVar1) {
    local_98 = 0x88;
    local_94 = 1;
    local_78 = param_2;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x540))(WdfDriverGlobals,local_res20,&local_98);
    if (-1 < iVar1) {
      uVar2 = (**(code **)(WdfFunctions_01015 + 0x598))(WdfDriverGlobals,local_res20);
      *param_3 = uVar2;
    }
  }
  if (local_res20 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
  return iVar1;
}



===== PlExtpRegisterPowerInterfaces @ 1c001ebfc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int PlExtpRegisterPowerInterfaces(undefined8 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined8 in_stack_ffffffffffffffb8;
  undefined4 uVar3;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined4 local_28;
  undefined4 local_24;
  code *local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  uVar3 = (undefined4)((ulonglong)in_stack_ffffffffffffffb8 >> 0x20);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    uVar3 = 1;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x15,
                     &WPP_014e28a2725035dd75100948d63f8491_Traceguids);
  }
  local_20 = PlExtProcessPoFxRequest;
  local_28 = 0;
  local_24 = 1;
  local_18 = param_1;
  local_10 = (**(code **)(WdfFunctions_01015 + 0xf8))(WdfDriverGlobals,param_1);
  puVar2 = &local_28;
  local_38 = 0;
  uStack_30 = 0;
  iVar1 = ZwPowerInformation(0x57,puVar2,0x20,&local_38,CONCAT44(uVar3,0x10));
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_D(PlExtLogHandle,puVar2,2,0x16,
                        &WPP_014e28a2725035dd75100948d63f8491_Traceguids,(char)iVar1);
    }
  }
  else {
    PlExtPoFxRequestHandler = local_38;
    PlExtPoFxRequestContext = uStack_30;
  }
  return iVar1;
}



===== PlExtpUninitialize @ 1c001ed28 =====

void PlExtpUninitialize(void)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x13,
                     &WPP_014e28a2725035dd75100948d63f8491_Traceguids);
  }
  KeSetEvent(&PlExtWorkerTerminateEvent,0,0);
  KeWaitForSingleObject(PlExtRequestWorkerThread,0,0,0,0);
  ObfDereferenceObject(PlExtRequestWorkerThread);
  if (PlExtRequestWorkItems != 0) {
    ExFreePoolWithTag(PlExtRequestWorkItems,0x78466550);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x14,
                     &WPP_014e28a2725035dd75100948d63f8491_Traceguids);
  }
  if (PlExtLogHandle != 0) {
    imp_WppRecorderLogDelete(WPP_GLOBAL_Control);
    PlExtLogHandle = 0;
  }
  return;
}



===== PlExtpProcessConvertToBiosResources @ 1c001ee4c =====

void PlExtpProcessConvertToBiosResources(int *param_1)

{
  int iVar1;
  
  iVar1 = PlExtpPepAcpiGetBiosResourceBuffer
                    (*(longlong *)(param_1 + 2),(uint)*(undefined8 *)(param_1 + 4),
                     *(undefined2 **)(param_1 + 6),(ulonglong *)(param_1 + 8),param_1[10]);
  *param_1 = iVar1;
  return;
}



===== PlExtpAcpiTranslatePepDeviceControlResources @ 1c001ee80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4
PlExtpAcpiTranslatePepDeviceControlResources
          (undefined8 param_1,longlong param_2,undefined8 param_3,undefined4 param_4,
          undefined8 param_5,undefined4 param_6,undefined4 *param_7)

{
  undefined4 uVar1;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x12,
                     &WPP_a2afeb96eade37b8f9cc5211bf7c269d_Traceguids);
  }
  local_40 = 0;
  local_2c = 0;
  local_1c = 0;
  local_48 = *(undefined8 *)(*(longlong *)(param_2 + 0x88) + 0x10);
  local_28 = param_5;
  local_20 = param_6;
  local_38 = param_3;
  local_30 = param_4;
  uVar1 = (*DAT_1c00165d8)(&local_48);
  *param_7 = local_20;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x13,
                     &WPP_a2afeb96eade37b8f9cc5211bf7c269d_Traceguids);
  }
  return uVar1;
}



===== RhpGetOpRegionCacheEntryByName @ 1c001efa0 =====

int RhpGetOpRegionCacheEntryByName(longlong param_1,ushort *param_2,undefined8 *param_3)

{
  code *pcVar1;
  bool bVar2;
  longlong lVar3;
  int iVar4;
  longlong *plVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  undefined1 *puVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong *plVar11;
  undefined1 auStack_78 [8];
  undefined1 auStack_70 [72];
  
  puVar8 = auStack_78;
  *param_3 = 0;
  if (param_1 == 0) {
    iVar4 = -0x3ffffff3;
    goto LAB_1c001f119;
  }
  ExAcquireFastMutex(&RhTranslationCacheLock);
  bVar2 = false;
  plVar9 = (longlong *)0x0;
  for (plVar10 = RhProviderListHead; (longlong **)plVar10 != &RhProviderListHead;
      plVar10 = (longlong *)*plVar10) {
    plVar9 = plVar10;
    if (plVar10[8] == param_1) {
      bVar2 = true;
      break;
    }
  }
  plVar10 = (longlong *)0x0;
  if (bVar2) {
    plVar10 = plVar9;
  }
  if (plVar10 == (longlong *)0x0) {
    ExReleaseFastMutex(&RhTranslationCacheLock);
    puVar8 = auStack_78;
    iVar4 = -0x3ffffddb;
    goto LAB_1c001f119;
  }
  LOCK();
  *(int *)(plVar10 + 10) = (int)plVar10[10] + 1;
  UNLOCK();
  bVar2 = false;
  plVar9 = (longlong *)0x0;
  for (plVar11 = (longlong *)plVar10[4]; plVar11 != plVar10 + 4; plVar11 = (longlong *)*plVar11) {
    iVar4 = RtlCompareUnicodeString(param_2,plVar11 + 5,0);
    plVar9 = plVar11;
    if (iVar4 == 0) {
      if (*(char *)((longlong)plVar11 + 0x24) == '\0') {
        bVar2 = true;
        break;
      }
    }
    else if (0 < iVar4) break;
  }
  if (!bVar2) {
    plVar9 = (longlong *)0x0;
  }
  if (plVar9 != (longlong *)0x0) {
    plVar11 = (longlong *)0x0;
    goto LAB_1c001f094;
  }
  ExReleaseFastMutex(&RhTranslationCacheLock);
  plVar5 = (longlong *)ExAllocatePool2(0x100,0x80,0x48736552);
  if (plVar5 == (longlong *)0x0) {
    iVar4 = -0x3fffff66;
  }
  else {
    uVar6 = RhpCopyUnicodeString((ushort *)(plVar5 + 5),param_2);
    iVar4 = (int)uVar6;
    if (-1 < iVar4) {
      plVar5[1] = (longlong)plVar5;
      *plVar5 = (longlong)plVar5;
      plVar5[3] = (longlong)RhpCleanupCacheContext;
      plVar5[2] = (longlong)plVar10;
      *(undefined4 *)(plVar5 + 7) = 0x38;
      ExAcquireFastMutex(&RhTranslationCacheLock);
      uVar7 = RhpInsertContext((longlong)plVar10,plVar5);
      if ((int)uVar7 < 0) {
        plVar9 = RhpFindContext((longlong)plVar10,param_2);
        plVar11 = plVar5;
        if (plVar9 == (longlong *)0x0) {
          ExReleaseFastMutex(&RhTranslationCacheLock);
          iVar4 = -0x3fffffff;
          goto LAB_1c001f0c2;
        }
      }
      else {
        plVar11 = (longlong *)0x0;
        plVar9 = plVar5;
      }
LAB_1c001f094:
      *(int *)(plVar9 + 4) = (int)plVar9[4] + 1;
      LOCK();
      *(int *)(plVar9[2] + 0x50) = *(int *)(plVar9[2] + 0x50) + 1;
      UNLOCK();
      ExReleaseFastMutex(&RhTranslationCacheLock);
      iVar4 = 0;
      *param_3 = plVar9 + 8;
      plVar5 = plVar11;
    }
  }
LAB_1c001f0c2:
  LOCK();
  plVar9 = plVar10 + 10;
  lVar3 = *plVar9;
  *(int *)plVar9 = (int)*plVar9 + -1;
  UNLOCK();
  puVar8 = auStack_78;
  if ((int)lVar3 == 1) {
    ExAcquireFastMutex(&RhTranslationCacheLock);
    puVar8 = auStack_78;
    if ((int)plVar10[10] == 0) {
      lVar3 = *plVar10;
      if ((*(longlong **)(lVar3 + 8) == plVar10) &&
         (plVar9 = (longlong *)plVar10[1], (longlong *)*plVar9 == plVar10)) {
        *plVar9 = lVar3;
        *(longlong **)(lVar3 + 8) = plVar9;
        plVar10[1] = (longlong)plVar10;
        *plVar10 = (longlong)plVar10;
        ExReleaseFastMutex(&RhTranslationCacheLock);
        RhpFreeProvider((longlong)plVar10);
        puVar8 = auStack_78;
        goto LAB_1c001f0dd;
      }
      pcVar1 = (code *)swi(0x29);
      (*pcVar1)(3);
      puVar8 = auStack_70;
    }
    *(undefined8 *)(puVar8 + -8) = 0x1c001f2a9;
    ExReleaseFastMutex(&RhTranslationCacheLock);
  }
LAB_1c001f0dd:
  if (plVar5 != (longlong *)0x0) {
    *(undefined8 *)(puVar8 + -8) = 0x1c001f2bc;
    RhpFreeUnicodeString(plVar5 + 5);
    *(undefined8 *)(puVar8 + -8) = 0x1c001f2cb;
    ExFreePoolWithTag(plVar5,0x48736552);
  }
  if (-1 < iVar4) {
    return iVar4;
  }
LAB_1c001f119:
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    uVar6 = *(undefined8 *)(param_2 + 4);
    *(longlong *)(puVar8 + 0x40) = param_1;
    *(undefined8 *)(puVar8 + 0x38) = uVar6;
    *(int *)(puVar8 + 0x30) = iVar4;
    uVar6 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
    *(undefined8 *)(puVar8 + -8) = 0x1c001f14b;
    WPP_RECORDER_SF_sDSq(uVar6);
  }
  return iVar4;
}



===== RhpCopyUnicodeString @ 1c001f2e0 =====

undefined8 RhpCopyUnicodeString(ushort *param_1,ushort *param_2)

{
  ushort uVar1;
  uint uVar2;
  void *_Dst;
  undefined8 uVar3;
  uint uVar4;
  
  uVar1 = *param_2;
  uVar2 = uVar1 + 2;
  param_1[0] = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  if (0x10000 < uVar2) {
    return 0xc0000106;
  }
  if (uVar2 < 2) {
    uVar3 = 0xc0000023;
  }
  else {
    uVar4 = uVar1 + 3;
    if ((uVar2 & 1) == 0) {
      uVar4 = uVar2;
    }
    _Dst = (void *)ExAllocatePool2(0x100,uVar4,0x48736552);
    if (_Dst == (void *)0x0) {
      return 0xc000009a;
    }
    *(undefined2 *)(((ulonglong)uVar4 - 2) + (longlong)_Dst) = 0;
    param_1[0] = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
    param_1[4] = 0;
    param_1[5] = 0;
    param_1[6] = 0;
    param_1[7] = 0;
    *(void **)(param_1 + 4) = _Dst;
    uVar2 = 0xfffe;
    if (uVar4 < 0xfffe) {
      uVar2 = uVar4;
    }
    param_1[1] = (ushort)uVar2;
    memcpy(_Dst,*(void **)(param_2 + 4),(ulonglong)*param_2);
    uVar3 = 0;
    *param_1 = *param_2;
    *(undefined2 *)((ulonglong)*param_2 + *(longlong *)(param_1 + 4)) = 0;
  }
  return uVar3;
}



===== RhpFindContext @ 1c001f3d0 =====

undefined8 * RhpFindContext(longlong param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 *puVar2;
  
  puVar2 = *(undefined8 **)(param_1 + 0x20);
  while( true ) {
    if (puVar2 == (undefined8 *)(param_1 + 0x20)) {
      return (undefined8 *)0x0;
    }
    iVar1 = RtlCompareUnicodeString(param_2,puVar2 + 5,0);
    if (0 < iVar1) break;
    if ((iVar1 == 0) && (*(char *)((longlong)puVar2 + 0x24) == '\0')) {
      return puVar2;
    }
    puVar2 = (undefined8 *)*puVar2;
  }
  return (undefined8 *)0x0;
}



===== RhpGetOpRegionConnection @ 1c001f444 =====

ulonglong RhpGetOpRegionConnection
                    (uint *param_1,uint param_2,ushort *param_3,undefined8 param_4,
                    undefined2 *param_5)

{
  ulonglong uVar1;
  uint *puVar2;
  ulonglong uVar3;
  ushort *puVar4;
  undefined2 uVar5;
  undefined8 uVar6;
  uint local_res10 [2];
  undefined2 *in_stack_ffffffffffffffd8;
  
  puVar2 = local_res10;
  puVar4 = param_3;
  uVar6 = param_4;
  local_res10[0] = param_2;
  uVar1 = RhpValidateOpRegionDescriptor((char *)param_1,puVar2,param_3,param_4);
  uVar3 = uVar1 & 0xffffffff;
  if ((int)uVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return uVar3;
    }
    uVar5 = 0x14;
    param_1 = puVar2;
  }
  else {
    puVar4 = (ushort *)(ulonglong)local_res10[0];
    uVar1 = RhpTranslateAndCacheConnection(param_3,(char *)param_1,local_res10[0],uVar6,param_5);
    uVar3 = uVar1 & 0xffffffff;
    if (-1 < (int)uVar1) {
      return uVar3;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return uVar3;
    }
    uVar5 = 0x15;
    in_stack_ffffffffffffffd8 = param_5;
  }
  WPP_RECORDER_SF_sqD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_1,puVar4,uVar5,
                      in_stack_ffffffffffffffd8,"RhpGetOpRegionConnection",(char)param_4,(char)uVar3
                     );
  return uVar3;
}



===== RhpValidateOpRegionDescriptor @ 1c001f504 =====

undefined8
RhpValidateOpRegionDescriptor(char *param_1,uint *param_2,undefined8 param_3,undefined8 param_4)

{
  char cVar1;
  uint uVar2;
  undefined8 uVar3;
  uint uVar4;
  undefined8 local_18;
  undefined8 uStack_10;
  
  uVar3 = 0;
  uVar2 = *param_2;
  *param_2 = 0;
  local_18 = 0;
  uStack_10 = 0;
  if (uVar2 < 3) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sdS(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
  }
  else {
    uVar4 = *(ushort *)(param_1 + 1) + 3;
    if (uVar2 < uVar4) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sddS(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
      }
    }
    else {
      uVar2 = RhpGetProviderBiosNameFromDescriptor(param_4,param_1,uVar4,&local_18);
      if (-1 < (int)uVar2) {
        cVar1 = RtlEqualUnicodeString(&local_18,param_3,0);
        if ((cVar1 == '\0') && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)
           ) {
          WPP_RECORDER_SF_sSS(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
        }
        *param_2 = uVar4;
        goto LAB_1c001f66a;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_1,9,0xe,
                           &WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,
                           "RhpValidateOpRegionDescriptor",(char)uVar2);
      }
    }
  }
  uVar3 = 0xc0000001;
LAB_1c001f66a:
  RhpFreeUnicodeString(&local_18);
  return uVar3;
}



===== RhpEvtOpRegionProcessRegionSpaceWorkItem @ 1c001f6a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void RhpEvtOpRegionProcessRegionSpaceWorkItem(undefined8 param_1)

{
  longlong *plVar1;
  ulonglong uVar2;
  ulonglong *puVar3;
  longlong *plVar4;
  code *pcVar5;
  bool bVar6;
  ulonglong *puVar7;
  int iVar8;
  undefined8 *puVar9;
  undefined8 uVar10;
  longlong lVar11;
  wchar_t *pwVar12;
  ulonglong *puVar13;
  undefined1 *puVar14;
  ulonglong *local_res10;
  longlong local_res18;
  undefined8 local_res20;
  undefined1 auStackY_48 [8];
  undefined1 auStackY_40 [24];
  
  bVar6 = false;
  local_res20 = 0;
  puVar9 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_RH_OPREGION_WORKITEM_TYPE_INFO_1c0016110);
  uVar10 = (**(code **)(WdfFunctions_01015 + 0xbe8))(WdfDriverGlobals,param_1);
  lVar11 = (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,*puVar9,PTR__WDF_RH_OPREGION_REQUEST_TYPE_INFO_1c0016138);
  local_res10 = (ulonglong *)0x0;
  local_res18 = lVar11;
  if ((*(ushort *)(lVar11 + 0xd0) == 0) ||
     (iVar8 = RhpGetOpRegionCacheEntryByName
                        (*(longlong *)(lVar11 + 0xb0),(ushort *)(lVar11 + 0xd0),&local_res10),
     iVar8 < 0)) {
    pwVar12 = (wchar_t *)
              (**(code **)(WdfFunctions_01015 + 0x610))
                        (WdfDriverGlobals,*(undefined8 *)(lVar11 + 0x88),&local_res20);
    RhpGetOpRegionCacheEntry
              (uVar10,*(wchar_t **)(lVar11 + 0xb0),pwVar12,(uint)local_res20,&local_res10);
  }
  puVar7 = local_res10;
  RhpProcessRegionSpaceAccess(uVar10,&local_res18,local_res10);
  if (local_res18 != 0) {
    RhpCleanAndReleaseRequestContext(local_res18);
    local_res18 = 0;
  }
  if (puVar7 == (ulonglong *)0x0) {
    return;
  }
  puVar13 = puVar7 + -8;
  ExAcquireFastMutex(&RhTranslationCacheLock);
  *(int *)(puVar7 + -4) = (int)puVar7[-4] + -1;
  if (((int)puVar7[-4] == 0) && (*(char *)((longlong)puVar7 + -0x1c) != '\0')) {
    uVar2 = *puVar13;
    if ((*(ulonglong **)(uVar2 + 8) == puVar13) &&
       (puVar3 = (ulonglong *)puVar7[-7], (ulonglong *)*puVar3 == puVar13)) {
      *puVar3 = uVar2;
      bVar6 = true;
      *(ulonglong **)(uVar2 + 8) = puVar3;
      puVar7[-7] = (ulonglong)puVar13;
      *puVar13 = (ulonglong)puVar13;
      goto LAB_1c001f7cf;
    }
LAB_1c001f8c1:
    pcVar5 = (code *)swi(0x29);
    (*pcVar5)(3);
    puVar14 = auStackY_40;
  }
  else {
LAB_1c001f7cf:
    ExReleaseFastMutex(&RhTranslationCacheLock);
    plVar1 = (longlong *)puVar7[-6];
    LOCK();
    plVar4 = plVar1 + 10;
    lVar11 = *plVar4;
    *(int *)plVar4 = (int)*plVar4 + -1;
    UNLOCK();
    puVar14 = auStackY_48;
    if ((int)lVar11 != 1) goto LAB_1c001f7f5;
    ExAcquireFastMutex(&RhTranslationCacheLock);
    puVar14 = auStackY_48;
    if ((int)plVar1[10] == 0) {
      lVar11 = *plVar1;
      if ((*(longlong **)(lVar11 + 8) == plVar1) &&
         (plVar4 = (longlong *)plVar1[1], (longlong *)*plVar4 == plVar1)) {
        *plVar4 = lVar11;
        *(longlong **)(lVar11 + 8) = plVar4;
        plVar1[1] = (longlong)plVar1;
        *plVar1 = (longlong)plVar1;
        ExReleaseFastMutex(&RhTranslationCacheLock);
        RhpFreeProvider((longlong)plVar1);
        puVar14 = auStackY_48;
        goto LAB_1c001f7f5;
      }
      goto LAB_1c001f8c1;
    }
  }
  *(undefined8 *)(puVar14 + -8) = 0x1c001f8d6;
  ExReleaseFastMutex(&RhTranslationCacheLock);
LAB_1c001f7f5:
  if (bVar6) {
    *(undefined8 *)(puVar14 + -8) = 0x1c001f8e8;
    RhpCleanContext((longlong)puVar13);
  }
  return;
}



===== RhpProcessRegionSpaceAccess @ 1c001f900 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int RhpProcessRegionSpaceAccess(undefined8 param_1,undefined8 *param_2,ulonglong *param_3)

{
  ulonglong *puVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  ulonglong *puVar8;
  uint uVar9;
  ulonglong *puVar10;
  ulonglong *puVar11;
  uint local_res10 [2];
  ulonglong local_res18 [2];
  ulonglong *in_stack_ffffffffffffff78;
  ulonglong in_stack_ffffffffffffff90;
  undefined1 uVar12;
  undefined8 in_stack_ffffffffffffff98;
  ulonglong local_58 [4];
  
  puVar1 = (ulonglong *)*param_2;
  uVar9 = 0;
  local_res18[0] = 0;
  local_res10[0] = 0;
  *param_2 = 0;
  local_58[2] = 0;
  local_58[3] = 0;
  local_58[0] = 0;
  local_58[1] = 0;
  if (param_3 == (ulonglong *)0x0) {
    iVar3 = -0x3fffffff;
    RhpFreeUnicodeString(local_58);
    goto LAB_1c001fa0f;
  }
  puVar11 = local_res18;
  puVar8 = (ulonglong *)puVar1[0x11];
  puVar4 = (uint *)(**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals);
  ExAcquireFastMutex(param_3[1]);
  uVar12 = (undefined1)in_stack_ffffffffffffff98;
  if (*(char *)((longlong)param_3 + 0x11) == '\0') {
    if (((char)*puVar4 + 0x74U & 0xfd) == 0) {
      puVar8 = (ulonglong *)(local_res18[0] & 0xffffffff);
      puVar11 = puVar1;
      uVar7 = RhpAssociateContextWithDescriptor
                        (puVar4,(uint)local_res18[0],(longlong)puVar1,(longlong)param_3);
      *(int *)((longlong)param_3 + 0x14) = (int)uVar7;
      *(undefined1 *)((longlong)param_3 + 0x11) = 1;
      goto LAB_1c001f992;
    }
    if ((short)puVar1[0x18] != 0) {
LAB_1c001fbfe:
      if (*(char *)((longlong)param_3 + 0x11) == '\0') {
        puVar8 = param_3;
        uVar7 = RhpParseOpRegionRequestResult((longlong)puVar1,(longlong)param_3);
        iVar3 = (int)uVar7;
        if (iVar3 == -0x7ffffffb) {
          ExReleaseFastMutex(param_3[1]);
          uVar7 = RhpRetryGetRegionConnectionData((longlong)puVar1);
          iVar3 = (int)uVar7;
          if (iVar3 != 0) goto LAB_1c001f9fd;
          ExAcquireFastMutex(param_3[1]);
          if (*(char *)((longlong)param_3 + 0x11) != (char)uVar7) goto LAB_1c001f992;
          puVar8 = param_3;
          uVar7 = RhpParseOpRegionRequestResult((longlong)puVar1,(longlong)param_3);
          iVar3 = (int)uVar7;
        }
        if (iVar3 != 0) {
          ExReleaseFastMutex(param_3[1]);
          goto LAB_1c001f9fd;
        }
      }
      goto LAB_1c001f992;
    }
    ExReleaseFastMutex(param_3[1]);
    RtlInitAnsiString(local_58 + 2,puVar4);
    uVar2 = RtlxAnsiStringToUnicodeSize(local_58 + 2);
    if (uVar2 < 0x41) {
      local_res10[0] = 0x40;
    }
    else {
      local_res10[0] = RtlxAnsiStringToUnicodeSize(local_58 + 2);
    }
    do {
      uVar6 = RhpAllocateUnicodeString(local_res10[0],local_58);
      iVar3 = (int)uVar6;
      if (iVar3 < 0) break;
      puVar11 = local_58;
      iVar3 = (*RHGetFullyQualifiedBiosName)(puVar1[0x16],local_58 + 2,puVar11,local_res10);
      if (iVar3 < 0) {
        RhpFreeUnicodeString(local_58);
      }
      uVar12 = (undefined1)in_stack_ffffffffffffff98;
      if (iVar3 != -0x3fffffdd) {
        if (-1 < iVar3) {
          puVar8 = param_3 + -3;
          uVar6 = RhpCopyUnicodeString((ushort *)(puVar1 + 0x1a),(ushort *)puVar8);
          if (((int)uVar6 != 0) &&
             ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
            in_stack_ffffffffffffff90 = puVar1[0x16];
            WPP_RECORDER_SF_sdi(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar8,puVar11,0x20,
                                in_stack_ffffffffffffff78,"RhpProcessRegionSpaceAccess",(char)uVar6,
                                (char)in_stack_ffffffffffffff90);
          }
          puVar8 = local_58;
          puVar11 = puVar1;
          uVar7 = RhpGetRegionConnectionData(param_1,(ushort *)puVar8,(longlong)puVar1);
          iVar3 = (int)uVar7;
          if (iVar3 != 0) goto LAB_1c001f9fd;
          ExAcquireFastMutex(param_3[1]);
          goto LAB_1c001fbfe;
        }
        break;
      }
      uVar9 = uVar9 + 1;
    } while (uVar9 < 2);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_ssDq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
  }
  else {
LAB_1c001f992:
    iVar3 = *(int *)((longlong)param_3 + 0x14);
    ExReleaseFastMutex(param_3[1]);
    if (iVar3 < 0) {
      param_3 = puVar11;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sqD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar8,puVar11,0x21,
                            in_stack_ffffffffffffff78,"RhpProcessRegionSpaceAccess",
                            (char)puVar1[0x16],(char)iVar3);
        param_3 = puVar11;
      }
      RhpFreeUnicodeString(local_58);
      goto LAB_1c001fa0f;
    }
    iVar3 = (int)puVar1[8];
    puVar8 = puVar1 + 9;
    uVar9 = (uint)puVar1[0x13];
    uVar7 = (ulonglong)uVar9;
    puVar11 = (ulonglong *)puVar1[0x12];
    if (iVar3 == 8) {
      puVar10 = (ulonglong *)(ulonglong)*(uint *)((longlong)param_3 + 0x1c);
      uVar5 = RhpGpioRegionSpaceAccess
                        (param_1,uVar7,*(uint *)((longlong)param_3 + 0x1c),param_3[4],
                         (longlong)puVar8,(longlong)puVar11,uVar9,(uint *)param_3[5],
                         (uint)param_3[6]);
      iVar3 = (int)uVar5;
      puVar11 = puVar10;
      in_stack_ffffffffffffff78 = puVar8;
LAB_1c001f9f3:
      if (-1 < iVar3) goto LAB_1c001f9fd;
    }
    else {
      if (iVar3 == 9) {
        puVar10 = (ulonglong *)(ulonglong)*(uint *)((longlong)param_3 + 0x1c);
        uVar5 = RhpSerialBusRegionSpaceAccess
                          (param_1,(short)puVar1[0x13],*(uint *)((longlong)param_3 + 0x1c),
                           (longlong *)param_3[4],(longlong)puVar8,(undefined1 *)puVar11,uVar9,
                           in_stack_ffffffffffffff90,uVar12);
        iVar3 = (int)uVar5;
        puVar11 = puVar10;
        in_stack_ffffffffffffff78 = puVar8;
        goto LAB_1c001f9f3;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar7,puVar11,0x47,
                           in_stack_ffffffffffffff78,"RhpPerformRegionSpaceAccess",(char)puVar1[8]);
      }
      iVar3 = -0x3fffff45;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      in_stack_ffffffffffffff78 = (ulonglong *)&WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids;
      puVar11 = (ulonglong *)0x9;
      WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar7,9,0x48,
                         &WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,
                         "RhpPerformRegionSpaceAccess",(char)iVar3);
    }
    if ((iVar3 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_SF_sdi(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar7,puVar11,0x22,
                          in_stack_ffffffffffffff78,"RhpProcessRegionSpaceAccess",(char)iVar3,
                          (char)puVar1[0x16]);
      RhpFreeUnicodeString(local_58);
      param_3 = puVar11;
      goto LAB_1c001fa0f;
    }
  }
LAB_1c001f9fd:
  RhpFreeUnicodeString(local_58);
  param_3 = puVar11;
  if (iVar3 == 0x103) {
    return 0x103;
  }
LAB_1c001fa0f:
  RhpCompleteRegionSpaceAccess((int)puVar1[8],iVar3,param_3,(char *)puVar1[0x12],(int)puVar1[0x13]);
  (*(code *)puVar1[0x14])(puVar1[0x15]);
  RhpCleanAndReleaseRequestContext((longlong)puVar1);
  return iVar3;
}



===== RhpGetOpRegionCacheEntry @ 1c001fdf0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong RhpGetOpRegionCacheEntry
                    (undefined8 param_1,wchar_t *param_2,wchar_t *param_3,uint param_4,
                    undefined8 *param_5)

{
  longlong *plVar1;
  longlong *plVar2;
  code *pcVar3;
  bool bVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  ulonglong uVar8;
  void *_Dst;
  longlong lVar9;
  undefined8 uVar10;
  wchar_t *pwVar11;
  undefined4 *puVar12;
  uint uVar13;
  wchar_t *pwVar14;
  wchar_t *pwVar15;
  undefined1 *puVar16;
  wchar_t *pwVar17;
  wchar_t *pwVar18;
  wchar_t *_Size;
  undefined8 uVar19;
  undefined2 uVar20;
  char cVar21;
  wchar_t *pwVar22;
  undefined1 auStackY_128 [8];
  undefined1 auStackY_120 [24];
  undefined8 *in_stack_fffffffffffffef8;
  undefined1 uVar23;
  wchar_t *local_d8;
  uint local_d0 [2];
  wchar_t local_c8 [4];
  longlong lStack_c0;
  wchar_t *local_b8;
  ulonglong local_b0;
  void *pvStack_a8;
  wchar_t local_a0 [4];
  wchar_t *local_98;
  undefined8 *local_90;
  undefined8 local_88;
  undefined8 uStack_80;
  ulonglong local_78;
  undefined8 uStack_70;
  wchar_t local_68 [12];
  ulonglong local_50;
  
  local_50 = __security_cookie ^ (ulonglong)auStackY_128;
  builtin_wcsncpy(local_68,L"RS:DEFAULT",0xb);
  local_98 = local_68;
  *param_5 = 0;
  local_90 = param_5;
  pwVar15 = (wchar_t *)0x0;
  local_a0[0] = L'\x14';
  local_a0[1] = L'\x16';
  local_a0[2] = L'\0';
  local_a0[3] = L'\0';
  local_d8 = (wchar_t *)0x0;
  local_b0 = 0;
  pvStack_a8 = (void *)0x0;
  local_c8[0] = L'\0';
  local_c8[1] = L'\0';
  local_c8[2] = L'\0';
  local_c8[3] = L'\0';
  lStack_c0 = 0;
  _Size = param_2;
  local_d0[0] = param_4;
  local_b8 = param_3;
  uVar8 = RhpConnectProviderDevice(param_1,(ushort *)0x0,(longlong)param_2);
  puVar16 = auStackY_128;
  pwVar18 = (wchar_t *)(uVar8 & 0xffffffff);
  uVar23 = SUB81(param_2,0);
  if ((int)uVar8 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sdi(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pwVar15,_Size,0x52,
                          in_stack_fffffffffffffef8,"RhpGetOpRegionCacheEntry",(char)uVar8,uVar23);
      puVar16 = auStackY_128;
    }
    goto LAB_1c0020016;
  }
  pwVar14 = (wchar_t *)0x0;
  if (param_2 == (wchar_t *)0x0) {
    pwVar18 = (wchar_t *)0xc000000d;
LAB_1c001ff9b:
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar20 = 0x53;
LAB_1c0020289:
      pwVar14 = pwVar18;
LAB_1c00203eb:
      WPP_RECORDER_SF_sdi(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pwVar15,_Size,uVar20,
                          in_stack_fffffffffffffef8,"RhpGetOpRegionCacheEntry",(char)pwVar14,uVar23)
      ;
    }
LAB_1c001ffaf:
    puVar16 = auStackY_128;
    if (local_d8 == (wchar_t *)0x0) goto LAB_1c0020016;
    param_2 = local_d8 + -0x20;
    ExAcquireFastMutex(&RhTranslationCacheLock);
    pwVar22 = (wchar_t *)0x0;
    *(uint *)(local_d8 + -0x10) = *(uint *)(local_d8 + -0x10) - 1;
    if ((*(uint *)(local_d8 + -0x10) == 0) && ((char)local_d8[-0xe] != '\0')) {
      lVar9 = *(longlong *)param_2;
      if ((*(wchar_t **)(lVar9 + 8) != param_2) ||
         (plVar2 = *(longlong **)(local_d8 + -0x1c), (wchar_t *)*plVar2 != param_2))
      goto LAB_1c0020997;
      *plVar2 = lVar9;
      pwVar22 = (wchar_t *)0x1;
      *(longlong **)(lVar9 + 8) = plVar2;
      *(wchar_t **)(local_d8 + -0x1c) = param_2;
      *(wchar_t **)param_2 = param_2;
    }
    cVar21 = (char)pwVar22;
    ExReleaseFastMutex(&RhTranslationCacheLock);
    plVar1 = *(longlong **)(local_d8 + -0x18);
    LOCK();
    plVar2 = plVar1 + 10;
    lVar9 = *plVar2;
    *(int *)plVar2 = (int)*plVar2 + -1;
    UNLOCK();
    puVar16 = auStackY_128;
    if ((int)lVar9 == 1) {
      ExAcquireFastMutex(&RhTranslationCacheLock);
      puVar16 = auStackY_128;
      if ((int)plVar1[10] != 0) goto LAB_1c002099e;
      lVar9 = *plVar1;
      if ((*(longlong **)(lVar9 + 8) != plVar1) ||
         (plVar2 = (longlong *)plVar1[1], (longlong *)*plVar2 != plVar1)) goto LAB_1c0020997;
      *plVar2 = lVar9;
      *(longlong **)(lVar9 + 8) = plVar2;
      plVar1[1] = (longlong)plVar1;
      *plVar1 = (longlong)plVar1;
      ExReleaseFastMutex(&RhTranslationCacheLock);
      RhpFreeProvider((longlong)plVar1);
      puVar16 = auStackY_128;
    }
  }
  else {
    ExAcquireFastMutex(&RhTranslationCacheLock);
    _Size = (wchar_t *)&RhProviderListHead;
    uVar8 = (ulonglong)pwVar15 >> 8;
    pwVar15 = (wchar_t *)((ulonglong)pwVar15 & 0xffffffffffffff00);
    pwVar18 = RhProviderListHead;
    pwVar22 = (wchar_t *)0x0;
    while( true ) {
      if ((wchar_t **)pwVar18 == &RhProviderListHead) break;
      pwVar22 = pwVar18;
      if (*(wchar_t **)(pwVar18 + 0x20) == param_2) {
        pwVar15 = (wchar_t *)CONCAT71((int7)uVar8,1);
        break;
      }
      pwVar18 = *(wchar_t **)pwVar18;
    }
    pwVar17 = (wchar_t *)0x0;
    if ((char)pwVar15 != '\0') {
      pwVar17 = pwVar22;
    }
    if (pwVar17 == (wchar_t *)0x0) {
      ExReleaseFastMutex(&RhTranslationCacheLock);
      pwVar18 = (wchar_t *)0xc0000225;
      goto LAB_1c001ff9b;
    }
    LOCK();
    *(uint *)(pwVar17 + 0x28) = *(uint *)(pwVar17 + 0x28) + 1;
    UNLOCK();
    bVar4 = false;
    pwVar18 = (wchar_t *)0x0;
    for (pwVar22 = *(wchar_t **)(pwVar17 + 0x10); pwVar22 != pwVar17 + 0x10;
        pwVar22 = *(wchar_t **)pwVar22) {
      pwVar15 = pwVar22 + 0x14;
      _Size = (wchar_t *)0x0;
      iVar5 = RtlCompareUnicodeString(local_a0);
      pwVar18 = pwVar22;
      if (iVar5 == 0) {
        if ((char)pwVar22[0x12] == '\0') {
          bVar4 = true;
          break;
        }
      }
      else if (0 < iVar5) break;
    }
    pwVar22 = (wchar_t *)0xc000009a;
    uVar7 = 0xc000009a;
    if (!bVar4) {
      pwVar18 = pwVar14;
    }
    pwVar11 = pwVar14;
    if (pwVar18 != (wchar_t *)0x0) goto LAB_1c001ff44;
    ExReleaseFastMutex(&RhTranslationCacheLock);
    pwVar15 = (wchar_t *)0x48;
    _Size = (wchar_t *)0x48736552;
    pwVar11 = (wchar_t *)ExAllocatePool2(0x100);
    if (pwVar11 == (wchar_t *)0x0) {
      pwVar18 = (wchar_t *)0xc000009a;
    }
    else {
      pwVar15 = local_a0;
      uVar8 = RhpCopyUnicodeString((ushort *)(pwVar11 + 0x14),(ushort *)pwVar15);
      pwVar18 = (wchar_t *)(uVar8 & 0xffffffff);
      if (-1 < (int)uVar8) {
        *(wchar_t **)(pwVar11 + 4) = pwVar11;
        *(wchar_t **)pwVar11 = pwVar11;
        *(wchar_t **)(pwVar11 + 8) = pwVar17;
        pwVar11[0x1c] = L'\0';
        pwVar11[0x1d] = L'\0';
        pwVar11[0xc] = L'\0';
        pwVar11[0xd] = L'\0';
        pwVar11[0xe] = L'\0';
        pwVar11[0xf] = L'\0';
        ExAcquireFastMutex(&RhTranslationCacheLock);
        pwVar15 = pwVar11;
        uVar8 = RhpInsertContext((longlong)pwVar17,(longlong *)pwVar11);
        if ((int)uVar8 < 0) {
          pwVar15 = local_a0;
          pwVar18 = (wchar_t *)RhpFindContext((longlong)pwVar17,pwVar15);
          if (pwVar18 == (wchar_t *)0x0) {
            ExReleaseFastMutex(&RhTranslationCacheLock);
            pwVar18 = (wchar_t *)0xc0000001;
            goto LAB_1c001ff73;
          }
        }
        else {
          pwVar18 = pwVar11;
          pwVar11 = pwVar14;
        }
LAB_1c001ff44:
        *(uint *)(pwVar18 + 0x10) = *(uint *)(pwVar18 + 0x10) + 1;
        LOCK();
        *(int *)(*(longlong *)(pwVar18 + 8) + 0x50) =
             *(int *)(*(longlong *)(pwVar18 + 8) + 0x50) + 1;
        UNLOCK();
        ExReleaseFastMutex(&RhTranslationCacheLock);
        local_d8 = pwVar18 + 0x20;
        pwVar18 = pwVar14;
      }
    }
LAB_1c001ff73:
    LOCK();
    pwVar14 = pwVar17 + 0x28;
    uVar13 = *(uint *)pwVar14;
    *(uint *)pwVar14 = *(uint *)pwVar14 - 1;
    UNLOCK();
    if (uVar13 != 1) {
LAB_1c001ff8a:
      if (pwVar11 != (wchar_t *)0x0) {
        RhpFreeUnicodeString((undefined8 *)(pwVar11 + 0x14));
        pwVar15 = (wchar_t *)0x48736552;
        ExFreePoolWithTag(pwVar11);
      }
      if ((int)pwVar18 < 0) goto LAB_1c001ff9b;
      lVar9 = *(longlong *)(local_d8 + -0x18);
      uVar13 = *(ushort *)(lVar9 + 0x30) + 2;
      if (uVar13 < 0x10001) {
        if (uVar13 < 2) {
          pwVar18 = (wchar_t *)0xc0000023;
          uVar7 = 0xc0000023;
          goto LAB_1c0020325;
        }
        _Size = (wchar_t *)0x48736552;
        uVar6 = *(ushort *)(lVar9 + 0x30) + 3;
        if ((uVar13 & 1) == 0) {
          uVar6 = uVar13;
        }
        pwVar15 = (wchar_t *)(ulonglong)uVar6;
        _Dst = (void *)ExAllocatePool2(0x100);
        if (_Dst == (void *)0x0) {
          pwVar18 = (wchar_t *)0xc000009a;
          goto LAB_1c0020325;
        }
        *(undefined2 *)(((ulonglong)uVar6 - 2) + (longlong)_Dst) = 0;
        uVar7 = 0xfffe;
        if (uVar6 < 0xfffe) {
          uVar7 = uVar6;
        }
        local_b0 = (ulonglong)CONCAT22((short)uVar7,(short)local_b0);
        _Size = (wchar_t *)(ulonglong)*(ushort *)(lVar9 + 0x30);
        pvStack_a8 = _Dst;
        memcpy(_Dst,*(void **)(lVar9 + 0x38),(size_t)_Size);
        pwVar15 = local_b8;
        local_b0 = CONCAT62(local_b0._2_6_,*(undefined2 *)(lVar9 + 0x30));
        local_88 = 0;
        uStack_80 = 0;
        *(undefined2 *)((ulonglong)*(ushort *)(lVar9 + 0x30) + (longlong)pvStack_a8) = 0;
        local_78 = 0;
        uStack_70 = 0;
        local_c8[0] = L'\0';
        local_c8[1] = L'\0';
        local_c8[2] = L'\0';
        local_c8[3] = L'\0';
        lStack_c0 = 0;
        if (((char)*local_b8 + 0x74U & 0xfd) != 0) {
          uVar7 = local_d0[0] * 2 + 6;
          if (0x10000 < uVar7) {
            pwVar18 = (wchar_t *)0xc0000106;
            pwVar15 = (wchar_t *)0x0;
            goto LAB_1c0020265;
          }
          if (uVar7 < 2) {
            pwVar18 = (wchar_t *)0xc0000023;
            pwVar15 = (wchar_t *)0x0;
            goto LAB_1c0020265;
          }
          _Size = (wchar_t *)0x48736552;
          pwVar14 = (wchar_t *)(ulonglong)uVar7;
          lVar9 = ExAllocatePool2();
          if (lVar9 == 0) {
            pwVar18 = (wchar_t *)0xc000009a;
            pwVar15 = pwVar14;
            goto LAB_1c0020265;
          }
          _Size = L"RS:";
          *(undefined2 *)((longlong)(ulonglong)uVar7 + lVar9 + -2) = 0;
          pwVar14 = L"%s%S";
          uVar20 = 0xfffe;
          if (uVar7 < 0xfffe) {
            uVar20 = (undefined2)uVar7;
          }
          local_c8[1] = uVar20;
          lStack_c0 = lVar9;
          uVar10 = RtlUnicodeStringPrintf((ushort *)local_c8,L"%s%S",L"RS:",pwVar15);
          uVar7 = (uint)uVar10;
LAB_1c0020183:
          pwVar18 = (wchar_t *)(ulonglong)uVar7;
          pwVar15 = pwVar14;
          if ((int)uVar7 < 0) goto LAB_1c0020265;
LAB_1c002018d:
          pwVar14 = (wchar_t *)0x0;
          ExAcquireFastMutex(&RhTranslationCacheLock);
          _Size = (wchar_t *)&RhProviderListHead;
          uVar8 = (ulonglong)pwVar15 >> 8;
          pwVar15 = (wchar_t *)((ulonglong)pwVar15 & 0xffffffffffffff00);
          pwVar18 = RhProviderListHead;
          pwVar22 = (wchar_t *)0x0;
          while( true ) {
            if ((wchar_t **)pwVar18 == &RhProviderListHead) break;
            pwVar22 = pwVar18;
            if (*(wchar_t **)(pwVar18 + 0x20) == param_2) {
              pwVar15 = (wchar_t *)CONCAT71((int7)uVar8,1);
              break;
            }
            pwVar18 = *(wchar_t **)pwVar18;
          }
          pwVar18 = (wchar_t *)0x0;
          if ((char)pwVar15 != '\0') {
            pwVar18 = pwVar22;
          }
          if (pwVar18 == (wchar_t *)0x0) {
            ExReleaseFastMutex(&RhTranslationCacheLock);
            pwVar18 = (wchar_t *)0xc0000225;
            uVar7 = 0xc0000225;
LAB_1c00203a0:
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
            goto LAB_1c0020301;
            WPP_RECORDER_SF_sDSq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
          }
          else {
            LOCK();
            *(uint *)(pwVar18 + 0x28) = *(uint *)(pwVar18 + 0x28) + 1;
            UNLOCK();
            pwVar22 = *(wchar_t **)(pwVar18 + 0x10);
            pwVar17 = (wchar_t *)0x0;
            while( true ) {
              if (pwVar22 == pwVar18 + 0x10) break;
              pwVar15 = pwVar22 + 0x14;
              _Size = (wchar_t *)0x0;
              iVar5 = RtlCompareUnicodeString(local_c8);
              pwVar17 = pwVar22;
              if (iVar5 == 0) {
                if ((char)pwVar22[0x12] == '\0') {
                  bVar4 = true;
                  goto LAB_1c0020299;
                }
              }
              else if (0 < iVar5) break;
              pwVar22 = *(wchar_t **)pwVar22;
            }
            bVar4 = false;
            pwVar22 = pwVar17;
LAB_1c0020299:
            if (!bVar4) {
              pwVar22 = (wchar_t *)0x0;
            }
            if (pwVar22 != (wchar_t *)0x0) {
              pwVar17 = (wchar_t *)0x0;
              goto LAB_1c00202ae;
            }
            ExReleaseFastMutex(&RhTranslationCacheLock);
            pwVar15 = (wchar_t *)0x80;
            _Size = (wchar_t *)0x48736552;
            pwVar22 = (wchar_t *)ExAllocatePool2(0x100);
            if (pwVar22 == (wchar_t *)0x0) {
              uVar7 = 0xc000009a;
            }
            else {
              pwVar15 = local_c8;
              uVar10 = RhpCopyUnicodeString((ushort *)(pwVar22 + 0x14),(ushort *)pwVar15);
              uVar7 = (uint)uVar10;
              if (-1 < (int)uVar7) {
                *(wchar_t **)(pwVar22 + 4) = pwVar22;
                *(wchar_t **)pwVar22 = pwVar22;
                *(code **)(pwVar22 + 0xc) = RhpCleanupCacheContext;
                *(wchar_t **)(pwVar22 + 8) = pwVar18;
                pwVar22[0x1c] = L'8';
                pwVar22[0x1d] = L'\0';
                ExAcquireFastMutex(&RhTranslationCacheLock);
                pwVar15 = pwVar22;
                uVar8 = RhpInsertContext((longlong)pwVar18,(longlong *)pwVar22);
                if ((int)uVar8 < 0) {
                  pwVar15 = local_c8;
                  pwVar11 = (wchar_t *)RhpFindContext((longlong)pwVar18,pwVar15);
                  if (pwVar11 == (wchar_t *)0x0) {
                    ExReleaseFastMutex(&RhTranslationCacheLock);
                    uVar7 = 0xc0000001;
                    goto LAB_1c00202d7;
                  }
                  pwVar17 = pwVar22;
                  pwVar22 = pwVar11;
                }
                else {
                  pwVar17 = (wchar_t *)0x0;
                }
LAB_1c00202ae:
                uVar7 = 0;
                *(uint *)(pwVar22 + 0x10) = *(uint *)(pwVar22 + 0x10) + 1;
                LOCK();
                *(int *)(*(longlong *)(pwVar22 + 8) + 0x50) =
                     *(int *)(*(longlong *)(pwVar22 + 8) + 0x50) + 1;
                UNLOCK();
                ExReleaseFastMutex(&RhTranslationCacheLock);
                pwVar14 = pwVar22 + 0x20;
                pwVar22 = pwVar17;
              }
            }
LAB_1c00202d7:
            LOCK();
            pwVar17 = pwVar18 + 0x28;
            uVar13 = *(uint *)pwVar17;
            *(uint *)pwVar17 = *(uint *)pwVar17 - 1;
            UNLOCK();
            if (uVar13 == 1) {
              ExAcquireFastMutex(&RhTranslationCacheLock);
              if (*(uint *)(pwVar18 + 0x28) == 0) {
                lVar9 = *(longlong *)pwVar18;
                if ((*(wchar_t **)(lVar9 + 8) != pwVar18) ||
                   (plVar2 = *(longlong **)(pwVar18 + 4), (wchar_t *)*plVar2 != pwVar18))
                goto LAB_1c0020997;
                *plVar2 = lVar9;
                *(longlong **)(lVar9 + 8) = plVar2;
                *(wchar_t **)(pwVar18 + 4) = pwVar18;
                *(wchar_t **)pwVar18 = pwVar18;
                ExReleaseFastMutex(&RhTranslationCacheLock);
                RhpFreeProvider((longlong)pwVar18);
              }
              else {
                ExReleaseFastMutex(&RhTranslationCacheLock);
              }
            }
            if (pwVar22 != (wchar_t *)0x0) {
              RhpFreeUnicodeString((undefined8 *)(pwVar22 + 0x14));
              pwVar15 = (wchar_t *)0x48736552;
              ExFreePoolWithTag(pwVar22);
            }
            pwVar18 = (wchar_t *)(ulonglong)uVar7;
            if ((int)uVar7 < 0) goto LAB_1c00203a0;
LAB_1c0020301:
            pwVar18 = (wchar_t *)(ulonglong)uVar7;
            if (-1 < (int)uVar7) {
              if ((char)*pwVar14 == '\0') {
                RhpAcquireOpRegionLock();
                if ((char)*pwVar14 == '\0') {
                  uVar10 = 0x38;
                  uVar19 = 0x48736552;
                  puVar12 = (undefined4 *)ExAllocatePool2();
                  *(undefined4 **)(pwVar14 + 4) = puVar12;
                  if (puVar12 == (undefined4 *)0x0) {
                    pwVar18 = (wchar_t *)0xc000009a;
                    RhpReleaseOpRegionLock();
                    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                      WPP_RECORDER_SF_sq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar10,uVar19,
                                         0x57,in_stack_fffffffffffffef8,"RhpGetOpRegionCacheEntry",
                                         uVar23);
                    }
                    goto LAB_1c001ffaf;
                  }
                  *puVar12 = 1;
                  *(undefined8 *)(puVar12 + 2) = 0;
                  puVar12[4] = 0;
                  KeInitializeEvent(puVar12 + 6,1);
                  *(undefined1 *)pwVar14 = 1;
                }
                RhpReleaseOpRegionLock();
              }
              *local_90 = pwVar14;
              goto LAB_1c001ffaf;
            }
          }
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar20 = 0x56;
            pwVar14 = (wchar_t *)(ulonglong)uVar7;
            goto LAB_1c00203eb;
          }
          goto LAB_1c001ffaf;
        }
        _Size = (wchar_t *)&local_b0;
        pwVar14 = (wchar_t *)local_d0;
        pwVar22 = param_2;
        uVar8 = RhpValidateOpRegionDescriptor((char *)local_b8,(uint *)pwVar14,_Size,param_2);
        iVar5 = (int)uVar8;
        pwVar18 = (wchar_t *)(uVar8 & 0xffffffff);
        if (iVar5 < 0) {
          pwVar15 = pwVar14;
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar20 = 0x14;
            goto LAB_1c0020783;
          }
        }
        else {
          _Size = (wchar_t *)(ulonglong)local_d0[0];
          in_stack_fffffffffffffef8 = &local_88;
          uVar8 = RhpTranslateAndCacheConnection
                            ((ushort *)&local_b0,(char *)pwVar15,local_d0[0],pwVar22,
                             (undefined2 *)in_stack_fffffffffffffef8);
          iVar5 = (int)uVar8;
          pwVar18 = (wchar_t *)(uVar8 & 0xffffffff);
          if ((iVar5 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
          {
            uVar20 = 0x15;
            pwVar14 = pwVar15;
LAB_1c0020783:
            WPP_RECORDER_SF_sqD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pwVar14,_Size,uVar20,
                                in_stack_fffffffffffffef8,"RhpGetOpRegionConnection",uVar23,
                                (char)iVar5);
            pwVar15 = pwVar14;
          }
          else if (-1 < iVar5) {
            pwVar15 = local_c8;
            uVar8 = RhpAllocateUnicodeString(0x28,(undefined8 *)pwVar15);
            pwVar18 = (wchar_t *)(uVar8 & 0xffffffff);
            if (-1 < (int)uVar8) {
              _Size = L"RS:";
              pwVar14 = L"%s%08x%08x";
              in_stack_fffffffffffffef8 =
                   (undefined8 *)
                   CONCAT44((int)((ulonglong)in_stack_fffffffffffffef8 >> 0x20),uStack_80._4_4_);
              uVar10 = RtlUnicodeStringPrintf
                                 ((ushort *)local_c8,L"%s%08x%08x",L"RS:",local_78 & 0xffffffff);
              uVar7 = (uint)uVar10;
              goto LAB_1c0020183;
            }
          }
        }
LAB_1c0020265:
        RhpFreeUnicodeString((undefined8 *)local_c8);
        if (-1 < (int)pwVar18) goto LAB_1c002018d;
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c001ffaf;
        uVar20 = 0x55;
        goto LAB_1c0020289;
      }
      pwVar18 = (wchar_t *)0xc0000106;
      uVar7 = 0xc0000106;
LAB_1c0020325:
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c001ffaf;
      uVar20 = 0x54;
      pwVar14 = (wchar_t *)(ulonglong)uVar7;
      goto LAB_1c00203eb;
    }
    ExAcquireFastMutex(&RhTranslationCacheLock);
    if (*(uint *)(pwVar17 + 0x28) != 0) {
      ExReleaseFastMutex(&RhTranslationCacheLock);
      goto LAB_1c001ff8a;
    }
    lVar9 = *(longlong *)pwVar17;
    if ((*(wchar_t **)(lVar9 + 8) == pwVar17) &&
       (plVar2 = *(longlong **)(pwVar17 + 4), (wchar_t *)*plVar2 == pwVar17)) {
      *plVar2 = lVar9;
      *(longlong **)(lVar9 + 8) = plVar2;
      *(wchar_t **)(pwVar17 + 4) = pwVar17;
      *(wchar_t **)pwVar17 = pwVar17;
      ExReleaseFastMutex(&RhTranslationCacheLock);
      RhpFreeProvider((longlong)pwVar17);
      goto LAB_1c001ff8a;
    }
LAB_1c0020997:
    cVar21 = (char)pwVar22;
    pcVar3 = (code *)swi(0x29);
    (*pcVar3)(3);
    puVar16 = auStackY_120;
LAB_1c002099e:
    *(undefined8 *)(puVar16 + -8) = 0x1c00209ac;
    ExReleaseFastMutex(&RhTranslationCacheLock);
  }
  if (cVar21 != '\0') {
    *(undefined8 *)(puVar16 + -8) = 0x1c00209be;
    RhpCleanContext((longlong)param_2);
  }
LAB_1c0020016:
  *(undefined8 *)(puVar16 + -8) = 0x1c002001f;
  RhpFreeUnicodeString(&local_b0);
  *(undefined8 *)(puVar16 + -8) = 0x1c0020028;
  RhpFreeUnicodeString((undefined8 *)local_c8);
  *(undefined8 *)(puVar16 + -8) = 0x1c0020036;
  return (ulonglong)pwVar18 & 0xffffffff;
}



===== RhpConnectProviderDevice @ 1c00209d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong RhpConnectProviderDevice(undefined8 param_1,ushort *param_2,longlong param_3)

{
  code *pcVar1;
  bool bVar2;
  undefined6 uVar3;
  uint uVar4;
  uint uVar5;
  short *_Dst;
  longlong *plVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  longlong *plVar9;
  undefined8 uVar10;
  longlong lVar11;
  undefined1 *puVar12;
  ulonglong uVar13;
  undefined8 uVar14;
  undefined2 uVar15;
  uint local_res10 [4];
  longlong local_res20;
  undefined1 auStackY_1b8 [8];
  undefined1 auStackY_1b0 [24];
  uint *in_stack_fffffffffffffe68;
  uint *puVar16;
  longlong *in_stack_fffffffffffffe70;
  longlong lVar17;
  wchar_t *pwVar18;
  undefined8 local_158;
  short *psStack_150;
  ushort local_148 [4];
  undefined8 uStack_140;
  ulonglong local_138;
  longlong local_130;
  longlong local_128 [2];
  short *psStack_118;
  uint local_110;
  undefined4 local_10c;
  undefined4 local_108;
  undefined8 local_104;
  undefined8 uStack_fc;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  longlong local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  
  local_128[0] = 0;
  local_res10[0] = 0;
  local_158 = 0;
  psStack_150 = (short *)0x0;
  local_148[0] = 0;
  local_148[1] = 0;
  local_148[2] = 0;
  local_148[3] = 0;
  uStack_140 = 0;
  ExAcquireFastMutex(&RhTranslationCacheLock);
  if (param_2 == (ushort *)0x0) {
    bVar2 = false;
    plVar6 = RhProviderListHead;
    plVar9 = (longlong *)0x0;
    while( true ) {
      if ((longlong **)plVar6 == &RhProviderListHead) break;
      plVar9 = plVar6;
      if (plVar6[8] == param_3) {
        bVar2 = true;
        break;
      }
      plVar6 = (longlong *)*plVar6;
    }
    plVar6 = (longlong *)0x0;
    if (bVar2) {
      plVar6 = plVar9;
    }
    if (plVar6 == (longlong *)0x0) {
      ExReleaseFastMutex(&RhTranslationCacheLock);
      local_138 = 0;
      local_res20 = 0;
      local_48 = 0;
      local_110 = 0;
      local_c8 = 0;
      uStack_c0 = 0;
      local_f4 = 0;
      local_b8 = 0;
      uStack_b0 = 0;
      local_d8 = 0;
      local_a8 = 0;
      uStack_a0 = 0;
      local_108 = 0x38;
      local_98 = 0;
      uStack_90 = 0;
      local_f0 = 1;
      local_88 = 0;
      uStack_80 = 0;
      local_ec = 1;
      local_78 = 0;
      uStack_70 = 0;
      local_130 = 0;
      local_68 = 0;
      uStack_60 = 0;
      local_58 = 0;
      uStack_50 = 0;
      local_128[1] = 0;
      psStack_118 = (short *)0x0;
      local_104 = 0;
      uStack_fc = 0;
      local_e8 = 0;
      uStack_e0 = 0;
      uVar4 = (**(code **)(WdfFunctions_01015 + 0x538))(WdfDriverGlobals,param_1,&local_108);
      uVar13 = (ulonglong)uVar4;
      if ((int)uVar4 < 0) {
LAB_1c0020b54:
        RhpFreeUnicodeString(&local_158);
      }
      else {
        local_c8 = 0x100000088;
        local_a8 = param_3;
        uVar4 = (**(code **)(WdfFunctions_01015 + 0x540))(WdfDriverGlobals,local_res20,&local_c8);
        uVar13 = (ulonglong)uVar4;
        if ((int)uVar4 < 0) goto LAB_1c0020b54;
        uVar8 = 0x80;
        for (uVar4 = 0; uVar4 < 2; uVar4 = uVar4 + 1) {
          uVar7 = RhpAllocateUnicodeString((uint)uVar8,&local_158);
          uVar13 = uVar7 & 0xffffffff;
          if ((int)uVar7 < 0) goto LAB_1c0020b54;
          in_stack_fffffffffffffe70 = local_128 + 1;
          *psStack_150 = 0;
          psStack_118 = psStack_150;
          local_128[1] = 1;
          local_10c = 0;
          in_stack_fffffffffffffe68 = (uint *)0x0;
          local_110 = (uint)uVar8;
          uVar5 = (**(code **)(WdfFunctions_01015 + 0x5d0))(WdfDriverGlobals,local_res20,0);
          uVar13 = (ulonglong)uVar5;
          if (uVar5 != 0xc0000023) {
            if ((int)uVar5 < 0) goto LAB_1c0020b54;
            break;
          }
          RhpFreeUnicodeString(&local_158);
          uVar8 = local_138;
          if (0xffffffff < local_138) {
            uVar13 = 0x80000005;
            goto LAB_1c0020b54;
          }
          uVar7 = RhpAllocateUnicodeString((uint)local_138,&local_158);
          uVar13 = uVar7 & 0xffffffff;
          if ((int)uVar7 < 0) goto LAB_1c0020b54;
        }
        uVar4 = RtlStringCbLengthW(psStack_150,local_158 >> 0x10 & 0xffff,&local_130);
        uVar13 = (ulonglong)uVar4;
        uVar3 = local_158._2_6_;
        if ((int)uVar4 < 0) {
          uVar13 = 0;
          local_158 = CONCAT62(uVar3,local_158._2_2_);
        }
        else {
          local_158 = CONCAT62(local_158._2_6_,(undefined2)local_130);
        }
      }
      if (local_res20 != 0) {
        (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
      }
      puVar12 = auStackY_1b8;
      if ((int)uVar13 < 0) goto LAB_1c0020b76;
      ExAcquireFastMutex(&RhTranslationCacheLock);
      param_2 = (ushort *)&local_158;
      goto LAB_1c0020ce3;
    }
    uVar4 = *(ushort *)(plVar6 + 6) + 2;
    if (uVar4 < 0x10001) {
      if (uVar4 < 2) {
        uVar13 = 0xc0000023;
        goto LAB_1c0020d59;
      }
      uVar5 = *(ushort *)(plVar6 + 6) + 3;
      if ((uVar4 & 1) == 0) {
        uVar5 = uVar4;
      }
      _Dst = (short *)ExAllocatePool2(0x100,uVar5,0x48736552);
      if (_Dst == (short *)0x0) {
        uVar13 = 0xc000009a;
        goto LAB_1c0020d59;
      }
      *(undefined2 *)(((ulonglong)uVar5 - 2) + (longlong)_Dst) = 0;
      uVar4 = 0xfffe;
      if (uVar5 < 0xfffe) {
        uVar4 = uVar5;
      }
      local_158 = (ulonglong)CONCAT22((short)uVar4,(short)local_158);
      psStack_150 = _Dst;
      memcpy(_Dst,(void *)plVar6[7],(ulonglong)*(ushort *)(plVar6 + 6));
      param_2 = (ushort *)&local_158;
      local_158 = CONCAT62(local_158._2_6_,(short)plVar6[6]);
      *(undefined2 *)((ulonglong)*(ushort *)(plVar6 + 6) + (longlong)psStack_150) = 0;
      goto LAB_1c0020c3d;
    }
    uVar13 = 0xc0000106;
LAB_1c0020d59:
    ExReleaseFastMutex(&RhTranslationCacheLock);
  }
  else {
LAB_1c0020ce3:
    plVar6 = (longlong *)RhpFindProvider(param_2);
    if (plVar6 == (longlong *)0x0) {
LAB_1c0020cf7:
      puVar12 = auStackY_1b8;
      ExReleaseFastMutex(&RhTranslationCacheLock);
      plVar9 = local_128;
      lVar11 = param_3;
      uVar4 = RhpGetDevicePdo(param_1,param_3,plVar9);
      lVar17 = local_128[0];
      uVar13 = (ulonglong)uVar4;
      if ((int)uVar4 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          pwVar18 = *(wchar_t **)(param_2 + 4);
          uVar15 = 0x12;
          lVar17 = param_3;
LAB_1c0020ef0:
          WPP_RECORDER_SF_sqSD
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar11,plVar9,uVar15,
                     in_stack_fffffffffffffe68,in_stack_fffffffffffffe70,(char)lVar17,pwVar18,
                     (char)uVar4);
        }
      }
      else {
        puVar16 = local_res10;
        local_res10[0] = 0;
        uVar14 = 0;
        uVar10 = 0xb;
        uVar4 = IoGetDeviceProperty(local_128[0]);
        uVar13 = (ulonglong)uVar4;
        if ((uVar4 == 0xc0000023) && (local_res10[0] != 0)) {
          uVar8 = RhpAllocateUnicodeString(local_res10[0],(undefined8 *)local_148);
          uVar13 = uVar8 & 0xffffffff;
          if (-1 < (int)uVar8) {
            plVar9 = (longlong *)(ulonglong)local_148[1];
            in_stack_fffffffffffffe68 = local_res10;
            uVar5 = (uint)local_148[1];
            lVar11 = 0xb;
            uVar4 = IoGetDeviceProperty(lVar17,0xb,plVar9,uStack_140);
            uVar13 = (ulonglong)uVar4;
            if ((int)uVar4 < 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                pwVar18 = *(wchar_t **)(param_2 + 4);
                uVar15 = 0x14;
                goto LAB_1c0020ef0;
              }
            }
            else if ((local_res10[0] < 3) || (uVar5 < local_res10[0])) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_sqddSD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
              }
              uVar13 = 0xc0000001;
            }
            else {
              local_148[0] = (short)local_res10[0] + -2;
              uVar8 = RhpRegisterProviderDevice(param_1,param_2,local_148,param_3);
              uVar13 = uVar8 & 0xffffffff;
              if ((int)uVar8 < 0) {
                if (plVar6 == (longlong *)0x0) goto LAB_1c0020b76;
                ExAcquireFastMutex(&RhTranslationCacheLock);
                if (plVar6[9] == 0) {
                  if (plVar6[8] != 0) {
                    ObfDereferenceObject();
                  }
                  plVar6[8] = param_3;
                  ObfReferenceObject(param_3);
                }
                goto LAB_1c0020d59;
              }
            }
          }
        }
        else {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_sqSD
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar10,uVar14,0x13,puVar16,
                       in_stack_fffffffffffffe70,(char)lVar17,*(wchar_t **)(param_2 + 4),(char)uVar4
                      );
          }
          if (-1 < (int)uVar4) {
            uVar13 = 0xc0000001;
          }
        }
      }
    }
    else {
LAB_1c0020c3d:
      LOCK();
      *(int *)(plVar6 + 10) = (int)plVar6[10] + 1;
      UNLOCK();
      if (plVar6[9] == 0) goto LAB_1c0020cf7;
      ExReleaseFastMutex(&RhTranslationCacheLock);
      uVar13 = 0;
    }
    puVar12 = auStackY_1b8;
    if (plVar6 == (longlong *)0x0) goto LAB_1c0020b76;
  }
  LOCK();
  plVar9 = plVar6 + 10;
  lVar17 = *plVar9;
  *(int *)plVar9 = (int)*plVar9 + -1;
  UNLOCK();
  puVar12 = auStackY_1b8;
  if ((int)lVar17 == 1) {
    ExAcquireFastMutex(&RhTranslationCacheLock);
    puVar12 = auStackY_1b8;
    if ((int)plVar6[10] == 0) {
      lVar17 = *plVar6;
      if ((*(longlong **)(lVar17 + 8) == plVar6) &&
         (plVar9 = (longlong *)plVar6[1], (longlong *)*plVar9 == plVar6)) {
        *plVar9 = lVar17;
        *(longlong **)(lVar17 + 8) = plVar9;
        plVar6[1] = (longlong)plVar6;
        *plVar6 = (longlong)plVar6;
        ExReleaseFastMutex(&RhTranslationCacheLock);
        RhpFreeProvider((longlong)plVar6);
        puVar12 = auStackY_1b8;
        goto LAB_1c0020b76;
      }
      pcVar1 = (code *)swi(0x29);
      (*pcVar1)(3);
      puVar12 = auStackY_1b0;
    }
    *(undefined8 *)(puVar12 + -8) = 0x1c00210e0;
    ExReleaseFastMutex(&RhTranslationCacheLock);
  }
LAB_1c0020b76:
  *(undefined8 *)(puVar12 + -8) = 0x1c0020b80;
  RhpFreeUnicodeString((undefined8 *)(puVar12 + 0x60));
  *(undefined8 *)(puVar12 + -8) = 0x1c0020b8a;
  RhpFreeUnicodeString((undefined8 *)(puVar12 + 0x70));
  return uVar13;
}



===== RhpSerialBusRegionSpaceAccess @ 1c00210f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong RhpSerialBusRegionSpaceAccess
                    (undefined8 param_1,undefined2 param_2,uint param_3,longlong *param_4,
                    longlong param_5,undefined1 *param_6,uint param_7,longlong param_8,
                    undefined1 param_9)

{
  char cVar1;
  bool bVar2;
  longlong lVar3;
  char cVar4;
  ulonglong uVar5;
  byte bVar6;
  char cVar7;
  uint uVar8;
  longlong lVar9;
  ulonglong uVar10;
  byte bVar11;
  char cVar12;
  uint local_res10 [4];
  longlong *local_res20;
  
  uVar8 = param_7;
  local_res10[0] = CONCAT22(local_res10[0]._2_2_,param_2);
  _param_9 = 0;
  param_8 = 0;
  if (param_7 < 3) {
    return 0xc0000001;
  }
  local_res20 = param_4;
  if ((1 < param_3) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_siD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                        &WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,9,0x40,
                        &WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,
                        "RhpSerialBusRegionSpaceAccess",(char)*(undefined8 *)(param_5 + 0x28),
                        (char)param_3);
  }
  cVar7 = *(char *)(param_5 + 10);
  bVar2 = false;
  cVar1 = *(char *)(param_5 + 8);
  bVar11 = 1;
  local_res10[0] = 0;
  cVar12 = '\x01';
  if (cVar7 == '\x0f') {
    local_res10[0] = (uint)*(byte *)(param_5 + 0xb);
    bVar11 = param_6[1];
    cVar12 = '\0';
    goto LAB_1c002119b;
  }
  if (cVar7 == '\x06') goto LAB_1c00211a2;
  switch(cVar7) {
  case '\x02':
    cVar12 = '\0';
    bVar11 = 0;
    break;
  default:
    uVar10 = 0xc00000bb;
    goto LAB_1c00215b4;
  case '\x04':
    cVar12 = '\0';
    break;
  case '\b':
    bVar11 = 2;
    break;
  case '\n':
    bVar11 = param_6[1];
    break;
  case '\f':
    bVar11 = 2;
    local_res10[0] = 2;
    goto LAB_1c002119b;
  case '\r':
    bVar11 = param_6[1];
    local_res10[0] = (uint)bVar11;
LAB_1c002119b:
    bVar2 = true;
    break;
  case '\x0e':
    cVar12 = '\0';
  case '\v':
    bVar11 = *(byte *)(param_5 + 0xb);
  }
LAB_1c00211a2:
  if (cVar1 == '\0') {
    local_res10[0] = (uint)bVar11;
  }
  bVar6 = 0;
  if (cVar1 != '\0') {
    bVar6 = bVar11;
  }
  if (cVar12 == '\0') {
    param_7 = 0;
    _param_9 = 0;
LAB_1c00211d3:
    if ((local_res10[0] + 2 <= uVar8) && (bVar6 + 2 <= uVar8)) {
      if ((bVar2) &&
         (((local_res10[0] == 0 || (bVar6 == 0)) &&
          ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)))) {
        WPP_RECORDER_SF_sDddq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
      }
      lVar9 = *local_res20;
      uVar5 = RhpGetConnectionTarget(param_1,lVar9,0x1f0000,&param_8);
      lVar3 = param_8;
      uVar10 = uVar5 & 0xffffffff;
      if ((int)uVar5 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_siD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar9,9,0x42,
                              &WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,
                              "RhpSerialBusRegionSpaceAccess",(char)*local_res20,(char)uVar5);
        }
      }
      else {
        if ((cVar1 != '\0') || (bVar2)) {
          cVar4 = '\x01';
          cVar7 = '\x01';
          if ((cVar1 == '\0') || (bVar2)) goto LAB_1c0021251;
          cVar7 = '\0';
        }
        else {
          cVar7 = '\0';
LAB_1c0021251:
          cVar4 = cVar7;
          cVar7 = '\x01';
        }
        uVar5 = RhpSendSpbIoctl(param_8,&param_9,param_7,(ulonglong)(param_6 + 2),local_res10,
                                (ulonglong *)(param_6 + 2),(uint)bVar6,cVar12,cVar7,cVar4);
        uVar10 = uVar5 & 0xffffffff;
        if ((int)uVar5 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_sdDq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
          }
        }
        else {
          *param_6 = 0;
          if ((cVar1 == '\0') || (bVar2)) {
            uVar8 = local_res10[0];
            if (0xff < local_res10[0]) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_sLi(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
              }
              uVar8 = 0xff;
            }
            param_6[1] = (char)uVar8;
          }
          uVar10 = 0;
        }
      }
      if (lVar3 != 0) {
        (**(code **)(WdfFunctions_01015 + 0x670))
                  (WdfDriverGlobals,lVar3,0,0x14e0,
                   "minkernel\\busdrv\\acpi\\reshub\\driver\\sys\\opregion.c");
      }
      if (-1 < (int)uVar10) {
        return uVar10;
      }
      goto LAB_1c00215b4;
    }
  }
  else if (*(ulonglong *)(param_5 + 0x10) <= (ulonglong)~*(uint *)(param_5 + 0x18)) {
    _param_9 = *(uint *)(param_5 + 0x18) + (int)*(ulonglong *)(param_5 + 0x10);
    param_7 = *(int *)(param_5 + 0x20) + 7U >> 3;
    goto LAB_1c00211d3;
  }
  uVar10 = 0xc0000001;
LAB_1c00215b4:
  *param_6 = 1;
  return uVar10;
}



===== RhpGetConnectionTarget @ 1c00215d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong RhpGetConnectionTarget
                    (undefined8 param_1,longlong param_2,undefined4 param_3,longlong *param_4)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  longlong *plVar4;
  longlong *plVar5;
  undefined8 *puVar6;
  code *pcVar7;
  uint uVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  longlong *plVar11;
  undefined1 auStackY_1b8 [32];
  longlong local_178;
  undefined4 local_170;
  undefined4 uStack_16c;
  undefined8 local_168;
  undefined8 uStack_160;
  ushort local_158 [4];
  undefined8 uStack_150;
  undefined4 local_148;
  undefined4 uStack_144;
  undefined4 uStack_140;
  undefined4 uStack_13c;
  undefined4 local_138;
  undefined4 uStack_134;
  undefined8 uStack_130;
  undefined8 local_128;
  undefined8 uStack_120;
  ulonglong local_118;
  short local_10e;
  undefined4 local_10c;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  wchar_t local_68 [20];
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_1b8;
  local_10e = 0x22;
  *param_4 = 0;
  local_10c = 0;
  local_118 = local_118 & 0xffffffff00000000;
  local_78 = 0;
  local_178 = 0;
  local_148 = 0;
  uStack_144 = 0;
  uStack_140 = 0;
  uStack_13c = 0;
  local_138 = 0;
  uStack_134 = 0;
  uStack_130 = 0;
  local_128 = 0;
  uStack_120 = 0;
  local_f8 = 0;
  uStack_f0 = 0;
  local_e8 = 0;
  uStack_e0 = 0;
  local_d8 = 0;
  uStack_d0 = 0;
  local_c8 = 0;
  uStack_c0 = 0;
  local_b8 = 0;
  uStack_b0 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_168 = 0;
  uStack_160 = 0;
  local_158[0] = 0;
  local_158[1] = 0;
  local_158[2] = 0;
  local_158[3] = 0;
  uStack_150 = 0;
  ExAcquireFastMutex(&RhTranslationCacheLock);
  for (plVar11 = RhConnectionListHead;
      ((longlong **)plVar11 != &RhConnectionListHead && (plVar11[7] <= param_2));
      plVar11 = (longlong *)*plVar11) {
    if (plVar11[7] == param_2) {
      LOCK();
      *(int *)((longlong)plVar11 + 0x74) = *(int *)((longlong)plVar11 + 0x74) + 1;
      UNLOCK();
      if (plVar11 == (longlong *)0x0) goto LAB_1c002169d;
      if ((char)plVar11[0xe] != '\0') {
        local_178 = plVar11[0xd];
        plVar11[0xd] = 0;
        *(undefined1 *)(plVar11 + 0xe) = 0;
        ExReleaseFastMutex(&RhTranslationCacheLock);
        (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,local_178);
        local_178 = 0;
        ExAcquireFastMutex(&RhTranslationCacheLock);
      }
      if (plVar11[0xd] == 0) {
        ExReleaseFastMutex(&RhTranslationCacheLock);
        uVar9 = RhpGetControllerNameFromCacheById(param_1,plVar11[7],local_158);
        uVar10 = uVar9 & 0xffffffff;
        if ((int)uVar9 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_sSD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),0,8,0x17,
                                &WPP_5a306037547032d76a1bb21b8aa3fd30_Traceguids,
                                "RhpGetConnectionTarget",*(wchar_t **)(plVar11[6] + 0x38),
                                (char)uVar9);
          }
          goto LAB_1c00216c3;
        }
        local_170 = (undefined4)plVar11[7];
        uStack_16c = *(undefined4 *)((longlong)plVar11 + 0x3c);
        RESOURCE_HUB_STRING_PRINTF(local_68,0x22,L"%0*I64x",0x10);
        uVar9 = RhpAllocateUnicodeString
                          ((uint)(ushort)(local_10e - 2) + local_158[0] + 0xe,&local_168);
        uVar10 = uVar9 & 0xffffffff;
        if ((int)uVar9 < 0) goto LAB_1c00216c3;
        uVar9 = RtlUnicodeStringPrintf((ushort *)&local_168,L"%s\\%s\\%s",uStack_150,local_68);
        uVar10 = uVar9 & 0xffffffff;
        if ((int)uVar9 < 0) goto LAB_1c00216c3;
        uStack_134 = 0;
        local_118 = 0;
        uStack_144 = 0;
        uStack_140 = 0;
        uStack_13c = 0;
        local_138 = 0;
        local_148 = 0x38;
        local_128 = 0;
        uStack_120 = 0;
        uStack_130 = 0x100000001;
        uVar8 = (**(code **)(WdfFunctions_01015 + 0x538))
                          (WdfDriverGlobals,param_1,&local_148,&local_178);
        uVar10 = (ulonglong)uVar8;
        if ((int)uVar8 < 0) goto LAB_1c00216c3;
        local_c8 = local_168;
        uStack_c0 = uStack_160;
        local_f8 = 0x200000088;
        local_b8 = CONCAT44(local_b8._4_4_,param_3);
        local_a8 = CONCAT44(local_a8._4_4_,0x40);
        uStack_b0 = CONCAT44(1,(undefined4)uStack_b0);
        uVar8 = (**(code **)(WdfFunctions_01015 + 0x540))(WdfDriverGlobals,local_178,&local_f8);
        uVar10 = (ulonglong)uVar8;
        if ((int)uVar8 < 0) goto LAB_1c00216c3;
        ExAcquireFastMutex(&RhTranslationCacheLock);
        if (plVar11[0xd] == 0) {
          plVar11[0xd] = local_178;
          local_178 = 0;
        }
      }
      lVar3 = plVar11[0xd];
      *param_4 = lVar3;
      (**(code **)(WdfFunctions_01015 + 0x668))(WdfDriverGlobals,lVar3,0,0x13cf);
      ExReleaseFastMutex(&RhTranslationCacheLock);
      uVar10 = 0;
      goto LAB_1c00216c3;
    }
  }
  plVar11 = (longlong *)0x0;
LAB_1c002169d:
  ExReleaseFastMutex(&RhTranslationCacheLock);
  uVar10 = 0xc0000225;
LAB_1c00216c3:
  if (local_178 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
    local_178 = 0;
  }
  if (plVar11 != (longlong *)0x0) {
    ExAcquireFastMutex(&RhTranslationCacheLock);
    LOCK();
    piVar1 = (int *)((longlong)plVar11 + 0x74);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if ((iVar2 == 1) && (*(int *)((longlong)plVar11 + 0x74) == 0)) {
      lVar3 = *plVar11;
      if ((*(longlong **)(lVar3 + 8) != plVar11) ||
         (plVar4 = (longlong *)plVar11[1], (longlong *)*plVar4 != plVar11)) {
LAB_1c0021b14:
        pcVar7 = (code *)swi(0x29);
        (*pcVar7)(3);
        pcVar7 = (code *)swi(3);
        uVar9 = (*pcVar7)();
        return uVar9;
      }
      *plVar4 = lVar3;
      *(longlong **)(lVar3 + 8) = plVar4;
      plVar4 = plVar11 + 2;
      plVar11[1] = (longlong)plVar11;
      *plVar11 = (longlong)plVar11;
      lVar3 = *plVar4;
      if ((*(longlong **)(lVar3 + 8) != plVar4) ||
         (plVar5 = (longlong *)plVar11[3], (longlong *)*plVar5 != plVar4)) goto LAB_1c0021b14;
      *plVar5 = lVar3;
      *(longlong **)(lVar3 + 8) = plVar5;
      plVar11[3] = (longlong)plVar4;
      *plVar4 = (longlong)plVar4;
      plVar4 = plVar11 + 4;
      plVar5 = (longlong *)*plVar4;
      if (plVar5 != plVar4) {
        if (((longlong *)plVar5[1] != plVar4) ||
           (puVar6 = (undefined8 *)plVar11[5], (longlong *)*puVar6 != plVar4)) goto LAB_1c0021b14;
        *puVar6 = plVar5;
        plVar5[1] = (longlong)puVar6;
        plVar11[5] = (longlong)plVar4;
        *plVar4 = (longlong)plVar4;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sS(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar6,8,0xe,
                             &WPP_5a306037547032d76a1bb21b8aa3fd30_Traceguids,
                             "RhpDereferenceConnectionLocked",*(wchar_t **)(plVar11[6] + 0x38));
        }
      }
      RhpFreeConnection((longlong)plVar11);
    }
    ExReleaseFastMutex(&RhTranslationCacheLock);
  }
  RhpFreeUnicodeString(&local_168);
  RhpFreeUnicodeString((undefined8 *)local_158);
  return uVar10;
}



===== RhpSendSpbIoctl @ 1c0021b30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0001c0021d3f) */
/* WARNING: Removing unreachable block (ram,0x0001c0021d4f) */
/* WARNING: Type propagation algorithm not settling */

ulonglong RhpSendSpbIoctl(undefined8 param_1,undefined8 param_2,uint param_3,ulonglong param_4,
                         undefined4 *param_5,ulonglong *param_6,uint param_7,char param_8,
                         char param_9,char param_10)

{
  undefined4 uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  uint uVar4;
  undefined1 auStackY_128 [32];
  ulonglong *local_a8 [3];
  ulonglong auStack_90 [11];
  ulonglong *local_38;
  ulonglong uStack_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_128;
  uVar3 = 0;
  uVar4 = 0;
  local_a8[0] = (ulonglong *)0x0;
  local_a8[1] = (ulonglong *)0x0;
  local_a8[2] = (ulonglong *)0x0;
  auStack_90[0] = 0;
  auStack_90[1] = 0;
  auStack_90[2] = 0;
  auStack_90[3] = 0;
  auStack_90[4] = 0;
  auStack_90[5] = 0;
  auStack_90[6] = 0;
  auStack_90[7] = 0;
  auStack_90[8] = 0;
  auStack_90[9] = 0;
  auStack_90[10] = 0;
  local_38 = (ulonglong *)0x0;
  uStack_30 = 0;
  if (param_8 == '\0') {
    if (param_10 != '\0') {
      uVar4 = 1;
      local_a8[2] = param_6;
      auStack_90[0] = (ulonglong)param_7;
      uVar3 = (ulonglong)param_7;
      local_a8[0] = (ulonglong *)0x2;
      local_a8[1] = (ulonglong *)0x1;
    }
  }
  else {
    local_a8[2] = auStack_90 + 9;
    local_a8[0] = (ulonglong *)0x2;
    uVar4 = 1;
    local_a8[1] = (ulonglong *)0x2;
    auStack_90[0] = 1;
    auStack_90[10] = (ulonglong)param_3;
    uVar3 = (ulonglong)param_3;
    auStack_90[9] = param_2;
    if (param_10 != '\0') {
      auStack_90[0] = 2;
      local_38 = param_6;
      uStack_30 = (ulonglong)param_7;
      uVar3 = uVar3 + param_7;
    }
  }
  if (param_9 != '\0') {
    uVar2 = (ulonglong)uVar4;
    uVar1 = *param_5;
    local_a8[uVar2 * 4] = (ulonglong *)0x1;
    *(undefined4 *)(auStack_90 + uVar2 * 4 + -2) = 1;
    local_a8[uVar2 * 4 + 2] = (ulonglong *)param_4;
    *(undefined4 *)(auStack_90 + uVar2 * 4) = uVar1;
  }
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x5d0))(WdfDriverGlobals,param_1,0,0x41808);
  if (-1 < (int)uVar2) {
    if (uVar3 == 0) {
      *param_5 = 0;
    }
    else if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      *param_5 = 0;
    }
    else {
      WPP_RECORDER_SF_sqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
      *param_5 = 0;
    }
    uVar2 = uVar2 & 0xffffffff;
  }
  return uVar2;
}



===== RhpFindProvider @ 1c0021d84 =====

ulonglong RhpFindProvider(undefined8 param_1)

{
  byte bVar1;
  char cVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  
  bVar1 = 0;
  puVar3 = (undefined8 *)0x0;
  puVar4 = RhProviderListHead;
  do {
    if ((undefined8 **)puVar4 == &RhProviderListHead) {
LAB_1c0021dd6:
      return -(ulonglong)bVar1 & (ulonglong)puVar3;
    }
    cVar2 = RtlEqualUnicodeString(puVar4 + 6,param_1,0);
    puVar3 = puVar4;
    if (cVar2 != '\0') {
      bVar1 = 1;
      goto LAB_1c0021dd6;
    }
    puVar4 = (undefined8 *)*puVar4;
  } while( true );
}



===== RhpGpioRegionSpaceAccess @ 1c0021dfc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong RhpGpioRegionSpaceAccess
                    (undefined8 param_1,undefined8 param_2,uint param_3,longlong param_4,
                    longlong param_5,longlong param_6,uint param_7,uint *param_8,uint param_9)

{
  char cVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  undefined1 *_Dst;
  ulonglong uVar5;
  uint uVar6;
  uint uVar7;
  longlong lVar8;
  undefined1 *puVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  uint uVar12;
  undefined8 uVar13;
  undefined2 uVar14;
  uint *puVar15;
  longlong lVar16;
  undefined1 auStackY_f8 [32];
  char *in_stack_ffffffffffffff28;
  undefined8 in_stack_ffffffffffffff30;
  uint local_94;
  uint local_90;
  longlong local_88;
  uint local_80;
  uint local_7c;
  uint local_78;
  uint local_74;
  uint local_70;
  uint local_6c;
  uint *local_68;
  longlong local_60;
  longlong local_58;
  undefined8 local_50;
  undefined1 local_48 [8];
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_f8;
  lVar16 = 0;
  _Dst = (undefined1 *)0x0;
  local_60 = param_6;
  local_68 = param_8;
  local_88 = 0;
  local_7c = param_3;
  local_58 = param_4;
  local_50 = param_1;
  if ((param_3 < 0x20000000) && ((ulonglong)param_3 * 8 < 0xfffffff8)) {
    if (param_3 * 8 + 8 <= param_9) {
      *(undefined4 *)(param_5 + 0x18) = 0;
      *(undefined4 *)(param_5 + 0x1c) = 0;
      if (*param_8 != *(uint *)(param_5 + 0x20)) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sllq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
        }
        return 0xc00000bb;
      }
      uVar3 = *(uint *)(param_5 + 0x20) + 7 >> 3;
      if (uVar3 <= param_7) {
        if (uVar3 < 9) {
          _Dst = local_48;
        }
        else {
          uVar10 = (ulonglong)uVar3;
          uVar13 = 0x48736552;
          _Dst = (undefined1 *)ExAllocatePool2(0x100);
          if (_Dst == (undefined1 *)0x0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_sdi(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar10,uVar13,0x2b,
                                  in_stack_ffffffffffffff28,"RhpGpioRegionSpaceAccess",
                                  (char)*(undefined4 *)(param_5 + 0x20),
                                  (char)*(undefined8 *)(param_5 + 0x28));
            }
            return 0xc000009a;
          }
        }
        uVar10 = (ulonglong)*(uint *)(param_5 + 0x18) * 8;
        if (uVar10 < 0x100000000) {
          uVar4 = (uint)uVar10;
          uVar6 = *(int *)(param_5 + 0x1c) + uVar4;
          uVar3 = 0xffffffff;
          if (uVar6 >= uVar4) {
            uVar3 = uVar6;
          }
          if (-1 < (int)-(uint)(uVar6 < uVar4)) {
            uVar6 = *(uint *)(param_5 + 0x20);
            uVar4 = (uVar6 - 1) + uVar3;
            if (uVar3 <= uVar4) {
              if (uVar4 < *local_68) {
                cVar1 = *(char *)(param_5 + 8);
                uVar7 = 0;
                local_78 = 0;
                local_90 = 0;
                local_6c = (-(uint)(cVar1 != '\0') & 0xc0000000) + 0x80000000;
                uVar11 = 0;
                puVar15 = local_68;
                uVar4 = local_7c;
                while( true ) {
                  local_74 = (uint)uVar11;
                  if ((uVar6 == 0) || (uVar4 <= local_74)) goto LAB_1c0022427;
                  local_80 = puVar15[uVar11 * 2 + 2];
                  if (uVar3 < local_78 + local_80) break;
LAB_1c002236c:
                  local_78 = local_78 + local_80;
                  uVar11 = (ulonglong)((int)uVar11 + 1);
                }
                uVar4 = local_80 + 7 >> 3;
                if (local_78 < uVar3) {
                  local_94 = uVar3 - local_78;
                  uVar12 = (local_78 - uVar3) + local_80;
                }
                else {
                  local_94 = 0;
                  uVar12 = local_80;
                }
                if (uVar6 < uVar12) {
                  uVar12 = uVar6;
                }
                local_70 = uVar4;
                if ((param_7 < uVar7 >> 3) || (param_7 * 8 - uVar7 < uVar4)) goto LAB_1c002237e;
                if (lVar16 != 0) {
                  in_stack_ffffffffffffff28 =
                       "minkernel\\busdrv\\acpi\\reshub\\driver\\sys\\opregion.c";
                  (**(code **)(WdfFunctions_01015 + 0x670))(WdfDriverGlobals,lVar16,0,0x102a);
                  local_88 = 0;
                  puVar15 = local_68;
                }
                uVar7 = local_6c;
                if (puVar15[uVar11 * 2 + 3] != 0) {
                  uVar7 = puVar15[uVar11 * 2 + 3];
                }
                lVar8 = *(longlong *)(local_58 + uVar11 * 8);
                uVar5 = RhpGetConnectionTarget(local_50,lVar8,uVar7,&local_88);
                lVar16 = local_88;
                uVar10 = uVar5 & 0xffffffff;
                if ((int)uVar5 < 0) {
                  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                    WPP_RECORDER_SF_siD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar8,9,0x2e,
                                        &WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,
                                        "RhpGpioRegionSpaceAccess",
                                        (char)*(undefined8 *)(local_58 + uVar11 * 8),(char)uVar5);
                    lVar16 = local_88;
                  }
                  goto LAB_1c002226e;
                }
                puVar9 = _Dst;
                if (cVar1 != '\0') {
                  if ((local_94 != 0) || (uVar12 != local_80)) {
                    cVar2 = *(char *)(param_5 + 0xc);
                    if (cVar2 == '\0') {
                      uVar11 = (ulonglong)uVar4;
                      uVar4 = RhpReadGpioPins(local_88,_Dst,uVar4);
                      uVar10 = (ulonglong)uVar4;
                      if ((int)uVar4 < 0) {
                        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                          uVar14 = 0x2f;
                          goto LAB_1c0022235;
                        }
                        goto LAB_1c002226e;
                      }
                    }
                    else if ((cVar2 == '\x02') || (cVar2 == '\x04')) {
                      memset(_Dst,(uint)(cVar2 == '\x02'),(ulonglong)uVar4);
                    }
                  }
                  if (uVar12 + local_90 + 7 >> 3 <= param_7) {
                    in_stack_ffffffffffffff28 =
                         (char *)CONCAT44((int)((ulonglong)in_stack_ffffffffffffff28 >> 0x20),uVar12
                                         );
                    RhpCopyMemoryBitOffset((longlong)_Dst,local_60,local_94,local_90,uVar12);
                    uVar11 = (ulonglong)local_70;
                    puVar9 = _Dst;
                    uVar4 = RhpWriteGpioPins(lVar16,_Dst,local_70);
                    uVar10 = (ulonglong)uVar4;
                    if (-1 < (int)uVar4) goto LAB_1c002233c;
                    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                      uVar14 = 0x30;
                      goto LAB_1c0022235;
                    }
                    goto LAB_1c002226e;
                  }
LAB_1c002237e:
                  uVar10 = 0xc0000001;
                  goto LAB_1c002226e;
                }
                uVar11 = (ulonglong)uVar4;
                uVar4 = RhpReadGpioPins(local_88,_Dst,uVar4);
                uVar10 = (ulonglong)uVar4;
                if ((int)uVar4 < 0) {
                  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                    uVar14 = 0x31;
LAB_1c0022235:
                    WPP_RECORDER_SF_sDDDqD
                              (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar9,uVar11,uVar14,
                               in_stack_ffffffffffffff28,in_stack_ffffffffffffff30,
                               (char)*(undefined4 *)(param_5 + 0x18),
                               (char)*(undefined4 *)(param_5 + 0x1c),
                               (char)*(undefined4 *)(param_5 + 0x20),
                               (char)*(undefined8 *)(param_5 + 0x28),(char)uVar10);
                  }
                  goto LAB_1c002226e;
                }
                if (param_7 < uVar12 + local_90 + 7 >> 3) goto LAB_1c002237e;
                in_stack_ffffffffffffff28 =
                     (char *)CONCAT44((int)((ulonglong)in_stack_ffffffffffffff28 >> 0x20),uVar12);
                RhpCopyMemoryBitOffset(local_60,(longlong)_Dst,local_90,local_94,uVar12);
LAB_1c002233c:
                uVar7 = uVar12 + local_90;
                uVar6 = uVar6 - uVar12;
                if (uVar6 != 0) {
                  uVar11 = (ulonglong)local_74;
                  puVar15 = local_68;
                  uVar4 = local_7c;
                  local_90 = uVar7;
                  goto LAB_1c002236c;
                }
LAB_1c0022427:
                uVar10 = 0;
                goto LAB_1c002226e;
              }
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_sDDDDq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
              }
              uVar10 = 0xc0000001;
              goto LAB_1c002229e;
            }
          }
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sDDDq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
        }
        uVar10 = 0x80000005;
        goto LAB_1c002229e;
      }
    }
    uVar10 = 0xc0000001;
  }
  else {
    uVar10 = 0xc0000001;
LAB_1c002226e:
    if (lVar16 != 0) {
      (**(code **)(WdfFunctions_01015 + 0x670))(WdfDriverGlobals,lVar16,0,0x10fb);
    }
LAB_1c002229e:
    if ((_Dst != (undefined1 *)0x0) && (_Dst != local_48)) {
      ExFreePoolWithTag(_Dst,0x48736552);
    }
  }
  return uVar10;
}



===== RhpFindOrCreateConnection @ 1c0022488 =====

ulonglong RhpFindOrCreateConnection
                    (ushort *param_1,short param_2,short param_3,void *param_4,uint param_5,
                    undefined1 param_6,longlong *param_7)

{
  byte bVar1;
  int iVar2;
  ulonglong uVar3;
  longlong *plVar4;
  ulonglong uVar5;
  void *_Dst;
  ulonglong uVar6;
  longlong *plVar7;
  longlong *plVar8;
  longlong *local_48;
  longlong *local_40;
  
  local_40 = (longlong *)0x0;
  plVar7 = (longlong *)0x0;
  local_48 = (longlong *)0x0;
  uVar3 = RhpFindOrCreateProvider(param_1,(ulonglong *)&local_40);
  uVar6 = uVar3 & 0xffffffff;
  if ((int)uVar3 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sSD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),0,8,0x10,
                          &WPP_5a306037547032d76a1bb21b8aa3fd30_Traceguids,
                          "RhpFindOrCreateConnection",*(wchar_t **)(param_1 + 4),(char)uVar3);
    }
    goto LAB_1c00226b5;
  }
  ExAcquireFastMutex(&RhTranslationCacheLock);
  bVar1 = 0;
  plVar4 = local_40;
  if (local_40 == (longlong *)0x0) {
    plVar4 = (longlong *)RhpFindProvider(param_1);
  }
  uVar3 = (ulonglong)param_5;
  if (plVar4 != (longlong *)0x0) {
    for (plVar8 = (longlong *)plVar4[2]; plVar8 != plVar4 + 2; plVar8 = (longlong *)*plVar8) {
      plVar7 = plVar8 + -2;
      if (((((short)plVar8[6] == param_2) && (*(short *)((longlong)plVar8 + 0x32) == param_3)) &&
          (*(uint *)(plVar8 + 8) == param_5)) &&
         (iVar2 = memcmp((void *)plVar8[7],param_4,uVar3), iVar2 == 0)) {
        bVar1 = 1;
        break;
      }
    }
  }
  plVar7 = (longlong *)(-(ulonglong)bVar1 & (ulonglong)plVar7);
  if (plVar7 != (longlong *)0x0) {
    LOCK();
    *(int *)((longlong)plVar7 + 0x74) = *(int *)((longlong)plVar7 + 0x74) + 1;
    UNLOCK();
  }
  ExReleaseFastMutex(&RhTranslationCacheLock);
  if (plVar7 != (longlong *)0x0) goto LAB_1c00226b5;
  uVar5 = RhpAllocateConnection((longlong *)&local_48);
  uVar6 = uVar5 & 0xffffffff;
  if ((int)uVar5 < 0) {
LAB_1c00226a3:
    plVar8 = local_48;
  }
  else {
    _Dst = (void *)ExAllocatePool2(0x100,uVar3,0x48736552);
    plVar4 = local_48;
    local_48[9] = (longlong)_Dst;
    plVar8 = plVar4;
    if (_Dst == (void *)0x0) {
      uVar6 = 0xc000009a;
    }
    else {
      memcpy(_Dst,param_4,uVar3);
      *(short *)(plVar4 + 8) = param_2;
      *(short *)((longlong)plVar4 + 0x42) = param_3;
      *(uint *)(plVar4 + 10) = param_5;
      *(undefined1 *)(plVar4 + 0xf) = param_6;
      *(undefined1 *)((longlong)plVar4 + 0x79) = 0xff;
      ExAcquireFastMutex(&RhTranslationCacheLock);
      plVar7 = RhpFindConnection(param_1,(ulonglong)local_40,param_2,param_3,param_4,param_5);
      if (plVar7 != (longlong *)0x0) {
        LOCK();
        *(int *)((longlong)plVar7 + 0x74) = *(int *)((longlong)plVar7 + 0x74) + 1;
        UNLOCK();
        ExReleaseFastMutex(&RhTranslationCacheLock);
        goto LAB_1c00226a3;
      }
      uVar3 = RhpInsertConnection(param_1,plVar4);
      uVar6 = uVar3 & 0xffffffff;
      ExReleaseFastMutex(&RhTranslationCacheLock);
      if (-1 < (int)uVar3) {
        LOCK();
        *(int *)((longlong)plVar4 + 0x74) = *(int *)((longlong)plVar4 + 0x74) + 1;
        UNLOCK();
        plVar8 = (longlong *)0x0;
        plVar7 = plVar4;
      }
    }
  }
  if (plVar8 != (longlong *)0x0) {
    RhpDereferenceConnection(plVar8);
  }
LAB_1c00226b5:
  if (local_40 != (longlong *)0x0) {
    RhpDereferenceProvider(local_40);
  }
  *param_7 = (longlong)plVar7;
  return uVar6;
}



===== RhpFindOrCreateProvider @ 1c0022720 =====

ulonglong RhpFindOrCreateProvider(ushort *param_1,ulonglong *param_2)

{
  code *pcVar1;
  longlong *plVar2;
  ulonglong uVar3;
  undefined8 *puVar4;
  longlong *plVar5;
  undefined1 *puVar6;
  ulonglong uVar7;
  longlong *plVar8;
  longlong *local_res10;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  
  local_res10 = (longlong *)0x0;
  *param_2 = 0;
  ExAcquireFastMutex(&RhTranslationCacheLock);
  plVar2 = (longlong *)RhpFindProvider(param_1);
  if (plVar2 != (longlong *)0x0) {
    LOCK();
    *(int *)(plVar2 + 10) = (int)plVar2[10] + 1;
    UNLOCK();
  }
  ExReleaseFastMutex(&RhTranslationCacheLock);
  if (plVar2 == (longlong *)0x0) {
    uVar3 = RhpAllocateProvider((longlong *)&local_res10);
    plVar5 = local_res10;
    puVar6 = auStack_38;
    uVar7 = uVar3 & 0xffffffff;
    plVar8 = plVar5;
    if (-1 < (int)uVar3) {
      uVar3 = RhpCopyUnicodeString((ushort *)(local_res10 + 6),param_1);
      puVar6 = auStack_38;
      uVar7 = uVar3 & 0xffffffff;
      if (-1 < (int)uVar3) {
        ExAcquireFastMutex(&RhTranslationCacheLock);
        plVar2 = (longlong *)RhpFindProvider(param_1);
        puVar6 = auStack_38;
        if (plVar2 == (longlong *)0x0) {
          puVar4 = &RhProviderListHead;
          if ((undefined8 *)*DAT_1c00167a8 != &RhProviderListHead) {
            puVar4 = (undefined8 *)0x3;
            pcVar1 = (code *)swi(0x29);
            DAT_1c00167a8 = (longlong *)(*pcVar1)();
            puVar6 = auStack_30;
          }
          *plVar5 = (longlong)puVar4;
          plVar5[1] = (longlong)DAT_1c00167a8;
          *DAT_1c00167a8 = (longlong)plVar5;
          DAT_1c00167a8 = plVar5;
          plVar8 = (longlong *)0x0;
        }
        else {
          LOCK();
          *(int *)(plVar2 + 10) = (int)plVar2[10] + 1;
          UNLOCK();
          plVar5 = plVar2;
          puVar6 = auStack_38;
          plVar8 = local_res10;
        }
        *(undefined8 *)(puVar6 + -8) = 0x1c0022833;
        ExReleaseFastMutex(&RhTranslationCacheLock);
        uVar7 = 0;
        plVar2 = plVar5;
      }
    }
    if (plVar8 != (longlong *)0x0) {
      *(undefined8 *)(puVar6 + -8) = 0x1c0022847;
      RhpDereferenceProvider(plVar8);
    }
    if ((int)uVar7 < 0) {
      if (plVar2 == (longlong *)0x0) {
        return uVar7;
      }
      *(undefined8 *)(puVar6 + -8) = 0x1c0022860;
      RhpDereferenceProvider(plVar2);
      return uVar7;
    }
  }
  else {
    uVar7 = 0;
  }
  *param_2 = (ulonglong)plVar2;
  return uVar7;
}



===== RhpAllocateConnection @ 1c002286c =====

undefined8 RhpAllocateConnection(longlong *param_1)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 uVar3;
  
  lVar1 = ExAllocatePool2(0x100,0x80,0x48736552);
  if (lVar1 == 0) {
    uVar3 = 0xc000009a;
    lVar1 = 0;
  }
  else {
    *(longlong *)(lVar1 + 8) = lVar1;
    *(longlong *)lVar1 = lVar1;
    lVar2 = lVar1 + 0x20;
    *(longlong *)(lVar1 + 0x28) = lVar2;
    *(longlong *)lVar2 = lVar2;
    lVar2 = lVar1 + 0x10;
    *(longlong *)(lVar1 + 0x18) = lVar2;
    *(longlong *)lVar2 = lVar2;
    uVar3 = 0;
    *(undefined4 *)(lVar1 + 0x74) = 1;
  }
  *param_1 = lVar1;
  return uVar3;
}



===== RhpWriteGpioPins @ 1c00228d8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void RhpWriteGpioPins(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  undefined8 local_28;
  undefined8 local_20;
  undefined4 local_18;
  undefined4 local_14;
  
  local_28 = 1;
  local_14 = 0;
  local_20 = param_2;
  local_18 = param_3;
  (**(code **)(WdfFunctions_01015 + 0x5d0))(WdfDriverGlobals,param_1,0,0x480004,&local_28,0,0,0);
  return;
}



===== RhpCopyMemoryBitOffset @ 1c002293c =====

void RhpCopyMemoryBitOffset
               (longlong param_1,longlong param_2,uint param_3,uint param_4,uint param_5)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  byte bVar7;
  uint uVar8;
  uint uVar9;
  
  uVar6 = param_3 & 7;
  uVar5 = param_4 & 7;
  uVar1 = param_3 >> 3;
  uVar2 = param_4 >> 3;
  for (; param_5 != 0; param_5 = param_5 + iVar3) {
    if (((uVar6 == 0) && (uVar5 == 0)) && (7 < param_5)) {
      uVar4 = param_5 >> 3;
      memcpy((void *)((ulonglong)uVar1 + param_1),(void *)((ulonglong)uVar2 + param_2),
             (ulonglong)uVar4);
      iVar3 = uVar4 * -8;
      uVar9 = uVar1 + uVar4;
      uVar4 = uVar2 + uVar4;
      uVar6 = 0;
      uVar5 = 0;
    }
    else {
      uVar4 = 8 - uVar5;
      uVar9 = uVar4;
      if (param_5 <= uVar4) {
        uVar9 = param_5;
      }
      uVar8 = 8 - uVar6;
      if ((uVar9 <= 8 - uVar6) && (uVar8 = param_5, uVar4 < param_5)) {
        uVar8 = uVar4;
      }
      iVar3 = -uVar8;
      bVar7 = ('\x01' << ((byte)uVar8 & 0x1f)) - 1;
      uVar9 = uVar8 + uVar5;
      uVar8 = uVar8 + uVar6;
      *(byte *)((ulonglong)uVar1 + param_1) =
           ~(bVar7 << ((byte)uVar6 & 0x1f)) & *(byte *)((ulonglong)uVar1 + param_1) |
           (*(byte *)((ulonglong)uVar2 + param_2) >> ((byte)uVar5 & 0x1f) & bVar7) <<
           ((byte)uVar6 & 0x1f);
      uVar5 = 0;
      uVar4 = uVar2 + 1;
      if (uVar9 != 8) {
        uVar5 = uVar9;
        uVar4 = uVar2;
      }
      uVar6 = 0;
      uVar9 = uVar1 + 1;
      if (uVar8 != 8) {
        uVar6 = uVar8;
        uVar9 = uVar1;
      }
    }
    uVar1 = uVar9;
    uVar2 = uVar4;
  }
  return;
}



===== RhpFindConnection @ 1c0022a78 =====

undefined8 *
RhpFindConnection(undefined8 param_1,ulonglong param_2,short param_3,short param_4,void *param_5,
                 uint param_6)

{
  int iVar1;
  undefined8 *puVar2;
  
  if ((param_2 != 0) || (param_2 = RhpFindProvider(param_1), param_2 != 0)) {
    for (puVar2 = *(undefined8 **)(param_2 + 0x10); puVar2 != (undefined8 *)(param_2 + 0x10);
        puVar2 = (undefined8 *)*puVar2) {
      if ((((*(short *)(puVar2 + 6) == param_3) && (*(short *)((longlong)puVar2 + 0x32) == param_4))
          && (*(uint *)(puVar2 + 8) == param_6)) &&
         (iVar1 = memcmp((void *)puVar2[7],param_5,(ulonglong)param_6), iVar1 == 0)) {
        return puVar2 + -2;
      }
    }
  }
  return (undefined8 *)0x0;
}



===== RhpProcessQueryActiveBothInitialPolarityIoctl @ 1c0022b10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int RhpProcessQueryActiveBothInitialPolarityIoctl
              (undefined8 param_1,undefined8 param_2,undefined4 *param_3)

{
  longlong lVar1;
  int iVar2;
  longlong *plVar3;
  undefined8 uVar4;
  undefined1 uVar5;
  undefined2 uVar6;
  longlong local_res18;
  undefined4 *local_res20;
  undefined8 local_38;
  undefined8 local_30;
  
  lVar1 = WdfFunctions_01015;
  local_res18 = 0;
  local_38 = 0;
  local_res20 = (undefined4 *)0x0;
  local_30 = 0;
  uVar5 = 0;
  *param_3 = 0;
  uVar4 = param_2;
  iVar2 = (**(code **)(lVar1 + 0x868))(WdfDriverGlobals,param_2,8,&local_res18,&local_38);
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar2;
    }
    uVar6 = 0x36;
    param_2 = uVar4;
LAB_1c0022b91:
    WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,6,uVar6,
                       &WPP_a781b87147d030366b419d92a3dc1ed1_Traceguids,
                       "RhpProcessQueryActiveBothInitialPolarityIoctl",(char)iVar2);
    return iVar2;
  }
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x870))
                    (WdfDriverGlobals,param_2,8,&local_res20,&local_30);
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar2;
    }
    uVar6 = 0x37;
    goto LAB_1c0022b91;
  }
  iVar2 = *(int *)(local_res18 + 4);
  ExAcquireFastMutex(&RhTranslationCacheLock);
  plVar3 = RhpFindConnectionByInterruptVector(iVar2);
  if (plVar3 != (longlong *)0x0) {
    LOCK();
    *(int *)((longlong)plVar3 + 0x74) = *(int *)((longlong)plVar3 + 0x74) + 1;
    UNLOCK();
  }
  ExReleaseFastMutex(&RhTranslationCacheLock);
  if (plVar3 == (longlong *)0x0) {
    iVar2 = -0x3ffffddb;
  }
  else {
    if (((short)plVar3[8] == 1) && (*(short *)((longlong)plVar3 + 0x42) == 1)) {
      uVar5 = *(undefined1 *)((longlong)plVar3 + 0x79);
      iVar2 = 0;
    }
    else {
      iVar2 = -0x3ffffff3;
    }
    RhpDereferenceConnection(plVar3);
    if (-1 < iVar2) goto LAB_1c0022cec;
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_sDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,6,0x38,
                        &WPP_a781b87147d030366b419d92a3dc1ed1_Traceguids,
                        "RhpProcessQueryActiveBothInitialPolarityIoctl",
                        (char)*(undefined4 *)(local_res18 + 4),(char)iVar2);
  }
LAB_1c0022cec:
  *param_3 = 8;
  *local_res20 = 1;
  *(undefined1 *)(local_res20 + 1) = uVar5;
  return iVar2;
}



===== RhpCacheGetConnectionDataFromInterruptVector @ 1c0022d20 =====

undefined8
RhpCacheGetConnectionDataFromInterruptVector(int param_1,undefined8 *param_2,undefined4 *param_3)

{
  undefined8 *puVar1;
  void *_Dst;
  undefined8 uVar2;
  
  uVar2 = 0;
  *param_2 = 0;
  *param_3 = 0;
  ExAcquireFastMutex(&RhTranslationCacheLock);
  puVar1 = RhInterruptListHead;
  while( true ) {
    if ((undefined8 **)puVar1 == &RhInterruptListHead) {
      ExReleaseFastMutex(&RhTranslationCacheLock);
      return 0xc0000225;
    }
    if (*(int *)((longlong)puVar1 + 0x24) == param_1) break;
    puVar1 = (undefined8 *)*puVar1;
  }
  LOCK();
  *(int *)((longlong)puVar1 + 0x54) = *(int *)((longlong)puVar1 + 0x54) + 1;
  UNLOCK();
  ExReleaseFastMutex(&RhTranslationCacheLock);
  if (puVar1 + -4 == (longlong *)0x0) {
    return 0xc0000225;
  }
  _Dst = (void *)ExAllocatePool2(0x100,*(undefined4 *)(puVar1 + 6),0x48736552);
  if (_Dst == (void *)0x0) {
    uVar2 = 0xc000009a;
  }
  else {
    memcpy(_Dst,(void *)puVar1[5],(ulonglong)*(uint *)(puVar1 + 6));
    *param_3 = *(undefined4 *)(puVar1 + 6);
    *param_2 = _Dst;
  }
  RhpDereferenceConnection(puVar1 + -4);
  return uVar2;
}



===== RhpCacheGetConnectionDataFromId @ 1c0022e30 =====

undefined8 RhpCacheGetConnectionDataFromId(longlong param_1,undefined8 *param_2,undefined4 *param_3)

{
  void *_Dst;
  undefined8 uVar1;
  longlong *plVar2;
  
  uVar1 = 0;
  *param_2 = 0;
  *param_3 = 0;
  ExAcquireFastMutex(&RhTranslationCacheLock);
  for (plVar2 = RhConnectionListHead;
      ((longlong **)plVar2 != &RhConnectionListHead && (plVar2[7] <= param_1));
      plVar2 = (longlong *)*plVar2) {
    if (plVar2[7] == param_1) {
      LOCK();
      *(int *)((longlong)plVar2 + 0x74) = *(int *)((longlong)plVar2 + 0x74) + 1;
      UNLOCK();
      ExReleaseFastMutex(&RhTranslationCacheLock);
      if (plVar2 == (longlong *)0x0) {
        return 0xc0000225;
      }
      _Dst = (void *)ExAllocatePool2(0x100,(int)plVar2[10],0x48736552);
      if (_Dst == (void *)0x0) {
        uVar1 = 0xc000009a;
      }
      else {
        memcpy(_Dst,(void *)plVar2[9],(ulonglong)*(uint *)(plVar2 + 10));
        *param_3 = (int)plVar2[10];
        *param_2 = _Dst;
      }
      RhpDereferenceConnection(plVar2);
      return uVar1;
    }
  }
  ExReleaseFastMutex(&RhTranslationCacheLock);
  return 0xc0000225;
}



===== RhEvtProcessDeviceIoControl @ 1c0022f40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void RhEvtProcessDeviceIoControl
               (ulonglong param_1,ushort *param_2,undefined8 param_3,undefined8 param_4,uint param_5
               )

{
  int iVar1;
  ulonglong uVar2;
  uint uVar3;
  ushort *puVar4;
  int local_18 [4];
  
  local_18[0] = 0;
  if (param_5 == 0x2ac000) {
    uVar2 = RhpProcessQueryConnectionPropertiesIoctl(param_1,param_2,local_18);
    iVar1 = (int)uVar2;
    goto LAB_1c0022f6f;
  }
  if (param_5 < 0x2ac011) {
    if (param_5 == 0x2ac010) {
      iVar1 = RhpProcessQueryActiveBothInitialPolarityIoctl(param_1,param_2,local_18);
      goto LAB_1c0022f6f;
    }
    if (param_5 == 0x2ac004) {
      uVar2 = RhpProcessAllocateConnectionIoctl(0,param_2,local_18);
      iVar1 = (int)uVar2;
      goto LAB_1c0022f6f;
    }
    if (param_5 == 0x2ac008) {
      uVar2 = RhpProcessFreeConnectionIoctl(0,param_2,local_18);
      iVar1 = (int)uVar2;
      goto LAB_1c0022f6f;
    }
    puVar4 = param_2;
    if (param_5 == 0x2ac00c) {
      uVar2 = RhpProcessUpdateConnectionPropertiesIoctl(4,param_2,local_18);
      iVar1 = (int)uVar2;
      goto LAB_1c0022f6f;
    }
  }
  else {
    if (param_5 == 0x2ac014) {
      uVar2 = RhpProcessUpdateActiveBothInitialPolarityIoctl(param_1,param_2,local_18);
      iVar1 = (int)uVar2;
      goto LAB_1c0022f6f;
    }
    uVar3 = param_5 - 0x2ac028;
    puVar4 = (ushort *)(ulonglong)uVar3;
    if (uVar3 == 0) {
      iVar1 = RhpProcessTranslationInterfaceQueryIoctl(param_1,param_2,local_18);
      goto LAB_1c0022f6f;
    }
    if (uVar3 == 0x1d8) {
      uVar2 = RhpProcessNativeMethodInterfaceQueryIoctl(param_1,param_2,local_18);
      iVar1 = (int)uVar2;
      goto LAB_1c0022f6f;
    }
  }
  iVar1 = -0x3ffffff0;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar4,2,0x17,
                       &WPP_a781b87147d030366b419d92a3dc1ed1_Traceguids,
                       "RhEvtProcessDeviceIoControl",(char)param_5);
  }
LAB_1c0022f6f:
  (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,param_2,iVar1,local_18[0]);
  return;
}



===== RhpProcessQueryConnectionPropertiesIoctl @ 1c00230a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong RhpProcessQueryConnectionPropertiesIoctl
                    (ulonglong param_1,undefined8 param_2,int *param_3)

{
  longlong lVar1;
  void *_Dst;
  ulonglong uVar2;
  int iVar3;
  ulonglong uVar4;
  uint uVar5;
  longlong *plVar6;
  undefined2 uVar7;
  ulonglong local_res8;
  undefined4 *local_res20;
  longlong local_48;
  void *local_40;
  longlong local_38 [2];
  
  local_48 = 0;
  local_38[1] = 0;
  local_res20 = (undefined4 *)0x0;
  local_38[0] = 0;
  local_40 = (void *)0x0;
  local_res8 = param_1 & 0xffffffff00000000;
  uVar4 = (**(code **)(WdfFunctions_01015 + 0x868))
                    (WdfDriverGlobals,param_2,0x10,&local_48,local_38 + 1);
  if ((int)uVar4 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return uVar4;
    }
    uVar7 = 0x1f;
LAB_1c002334e:
    WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),&WPP_RECORDER_INITIALIZED,6,uVar7,
                       &WPP_a781b87147d030366b419d92a3dc1ed1_Traceguids,
                       "RhpProcessQueryConnectionPropertiesIoctl",(char)uVar4);
    return uVar4 & 0xffffffff;
  }
  uVar4 = (**(code **)(WdfFunctions_01015 + 0x870))
                    (WdfDriverGlobals,param_2,0xc,&local_res20,local_38);
  if ((int)uVar4 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return uVar4;
    }
    uVar7 = 0x20;
    goto LAB_1c002334e;
  }
  iVar3 = *(int *)(local_48 + 4);
  if (iVar3 == 0) {
    lVar1 = *(longlong *)(local_48 + 8);
    ExAcquireFastMutex(&RhTranslationCacheLock);
    for (plVar6 = RhConnectionListHead;
        ((longlong **)plVar6 != &RhConnectionListHead && (plVar6[7] <= lVar1));
        plVar6 = (longlong *)*plVar6) {
      if (plVar6[7] == lVar1) {
        LOCK();
        *(int *)((longlong)plVar6 + 0x74) = *(int *)((longlong)plVar6 + 0x74) + 1;
        UNLOCK();
        ExReleaseFastMutex(&RhTranslationCacheLock);
        if (plVar6 == (longlong *)0x0) goto LAB_1c00231a9;
        _Dst = (void *)ExAllocatePool2(0x100,(int)plVar6[10],0x48736552);
        if (_Dst == (void *)0x0) {
          uVar4 = 0xc000009a;
          uVar5 = (uint)local_res8;
        }
        else {
          memcpy(_Dst,(void *)plVar6[9],(ulonglong)*(uint *)(plVar6 + 10));
          uVar4 = 0;
          uVar5 = *(uint *)(plVar6 + 10);
          local_40 = _Dst;
        }
        RhpDereferenceConnection(plVar6);
        iVar3 = (int)uVar4;
        if (-1 < iVar3) goto LAB_1c002329c;
        goto LAB_1c00231b0;
      }
    }
    ExReleaseFastMutex(&RhTranslationCacheLock);
LAB_1c00231a9:
    uVar4 = 0xc0000225;
    iVar3 = -0x3ffffddb;
LAB_1c00231b0:
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_siD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),&WPP_RECORDER_INITIALIZED,6,
                          0x21,&WPP_a781b87147d030366b419d92a3dc1ed1_Traceguids,
                          "RhpProcessQueryConnectionPropertiesIoctl",
                          (char)*(undefined8 *)(local_48 + 8),(char)iVar3);
    }
  }
  else if (iVar3 == 1) {
    uVar2 = RhpCacheGetConnectionDataFromInterruptVector
                      (*(int *)(local_48 + 8),&local_40,(undefined4 *)&local_res8);
    uVar4 = uVar2 & 0xffffffff;
    if (-1 < (int)uVar2) {
      uVar5 = (uint)local_res8;
LAB_1c002329c:
      *param_3 = 8;
      *local_res20 = 1;
      if (local_38[0] - 8U < (ulonglong)uVar5) {
        uVar4 = 0xc0000023;
        local_res20[1] = uVar5;
      }
      else {
        memcpy(local_res20 + 2,local_40,(ulonglong)uVar5);
        uVar4 = 0;
        local_res20[1] = uVar5;
        *param_3 = uVar5 + 8;
      }
      goto LAB_1c00232de;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                          (ulonglong)*(uint *)(local_48 + 8),6,0x22,
                          &WPP_a781b87147d030366b419d92a3dc1ed1_Traceguids,
                          "RhpProcessQueryConnectionPropertiesIoctl",(char)*(uint *)(local_48 + 8),
                          (char)uVar2);
    }
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),&WPP_RECORDER_INITIALIZED,6,0x23
                         ,&WPP_a781b87147d030366b419d92a3dc1ed1_Traceguids,
                         "RhpProcessQueryConnectionPropertiesIoctl",(char)iVar3);
    }
    uVar4 = 0xc00000bb;
  }
  *param_3 = 0;
LAB_1c00232de:
  if (local_40 == (void *)0x0) {
    return uVar4;
  }
  ExFreePoolWithTag(local_40,0x48736552);
  return uVar4;
}



===== RhpDereferenceConnection @ 1c0023460 =====

void RhpDereferenceConnection(longlong *param_1)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  longlong *plVar4;
  longlong *plVar5;
  longlong *plVar6;
  code *pcVar7;
  
  ExAcquireFastMutex(&RhTranslationCacheLock);
  LOCK();
  piVar1 = (int *)((longlong)param_1 + 0x74);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if ((iVar2 != 1) || (*(int *)((longlong)param_1 + 0x74) != 0)) {
LAB_1c002348b:
    ExReleaseFastMutex(&RhTranslationCacheLock);
    return;
  }
  lVar3 = *param_1;
  if ((*(longlong **)(lVar3 + 8) == param_1) &&
     (plVar4 = (longlong *)param_1[1], (longlong *)*plVar4 == param_1)) {
    *plVar4 = lVar3;
    *(longlong **)(lVar3 + 8) = plVar4;
    plVar4 = param_1 + 2;
    param_1[1] = (longlong)param_1;
    *param_1 = (longlong)param_1;
    lVar3 = *plVar4;
    if ((*(longlong **)(lVar3 + 8) == plVar4) &&
       (plVar5 = (longlong *)param_1[3], (longlong *)*plVar5 == plVar4)) {
      *plVar5 = lVar3;
      *(longlong **)(lVar3 + 8) = plVar5;
      param_1[3] = (longlong)plVar4;
      *plVar4 = (longlong)plVar4;
      plVar4 = param_1 + 4;
      plVar5 = (longlong *)*plVar4;
      if (plVar5 != plVar4) {
        if (((longlong *)plVar5[1] != plVar4) ||
           (plVar6 = (longlong *)param_1[5], (longlong *)*plVar6 != plVar4)) goto LAB_1c0023585;
        *plVar6 = (longlong)plVar5;
        plVar5[1] = (longlong)plVar6;
        param_1[5] = (longlong)plVar4;
        *plVar4 = (longlong)plVar4;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sS(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),plVar6,8,0xe,
                             &WPP_5a306037547032d76a1bb21b8aa3fd30_Traceguids,
                             "RhpDereferenceConnectionLocked",*(wchar_t **)(param_1[6] + 0x38));
        }
      }
      RhpFreeConnection((longlong)param_1);
      goto LAB_1c002348b;
    }
  }
LAB_1c0023585:
  pcVar7 = (code *)swi(0x29);
  (*pcVar7)(3);
  pcVar7 = (code *)swi(3);
  (*pcVar7)();
  return;
}



===== RhpFindConnectionByInterruptVector @ 1c00235a0 =====

undefined8 * RhpFindConnectionByInterruptVector(int param_1)

{
  undefined8 *puVar1;
  
  puVar1 = RhInterruptListHead;
  while( true ) {
    if ((undefined8 **)puVar1 == &RhInterruptListHead) {
      return (undefined8 *)0x0;
    }
    if (*(int *)((longlong)puVar1 + 0x24) == param_1) break;
    puVar1 = (undefined8 *)*puVar1;
  }
  return puVar1 + -4;
}



===== RhpProcessFreeConnectionIoctl @ 1c00235d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong RhpProcessFreeConnectionIoctl(undefined8 param_1,undefined8 param_2,undefined4 *param_3)

{
  longlong lVar1;
  uint uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  longlong local_res8 [2];
  undefined8 local_res18 [2];
  
  lVar1 = WdfFunctions_01015;
  local_res8[0] = 0;
  local_res18[0] = 0;
  *param_3 = 0;
  uVar2 = (**(code **)(lVar1 + 0x868))(WdfDriverGlobals,param_2,0x10,local_res8,local_res18);
  uVar4 = (ulonglong)uVar2;
  if ((int)uVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,6,0x28,
                         &WPP_a781b87147d030366b419d92a3dc1ed1_Traceguids,
                         "RhpProcessFreeConnectionIoctl",(char)uVar2);
    }
  }
  else {
    uVar3 = RhpFreeConnectionUsingId(*(longlong *)(local_res8[0] + 8));
    uVar4 = uVar3 & 0xffffffff;
    if (((int)uVar3 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_SF_siD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,6,0x29,
                          &WPP_a781b87147d030366b419d92a3dc1ed1_Traceguids,
                          "RhpProcessFreeConnectionIoctl",(char)*(undefined8 *)(local_res8[0] + 8),
                          (char)uVar3);
    }
  }
  return uVar4;
}



===== RhpFreeConnectionUsingId @ 1c00236e0 =====

undefined8 RhpFreeConnectionUsingId(longlong param_1)

{
  longlong *plVar1;
  undefined8 uVar2;
  
  uVar2 = 0;
  ExAcquireFastMutex(&RhTranslationCacheLock);
  plVar1 = RhpFindConnectionById(param_1);
  if (plVar1 != (longlong *)0x0) {
    if ((char)plVar1[0xf] == '\0') {
      uVar2 = 0xc000000d;
    }
    else {
      RhpDereferenceConnectionLocked(plVar1);
    }
  }
  ExReleaseFastMutex(&RhTranslationCacheLock);
  if (plVar1 == (longlong *)0x0) {
    uVar2 = 0xc0000225;
  }
  return uVar2;
}



===== RhpFindConnectionById @ 1c0023760 =====

undefined8 * RhpFindConnectionById(longlong param_1)

{
  undefined8 *puVar1;
  
  for (puVar1 = RhConnectionListHead;
      ((undefined8 **)puVar1 != &RhConnectionListHead && ((longlong)puVar1[7] <= param_1));
      puVar1 = (undefined8 *)*puVar1) {
    if (puVar1[7] == param_1) {
      return puVar1;
    }
  }
  return (undefined8 *)0x0;
}



===== RhpDereferenceConnectionLocked @ 1c0023790 =====

void RhpDereferenceConnectionLocked(longlong *param_1)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  longlong *plVar4;
  longlong *plVar5;
  longlong *plVar6;
  code *pcVar7;
  
  LOCK();
  piVar1 = (int *)((longlong)param_1 + 0x74);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if ((iVar2 != 1) || (*(int *)((longlong)param_1 + 0x74) != 0)) {
    return;
  }
  lVar3 = *param_1;
  if ((*(longlong **)(lVar3 + 8) == param_1) &&
     (plVar4 = (longlong *)param_1[1], (longlong *)*plVar4 == param_1)) {
    *plVar4 = lVar3;
    *(longlong **)(lVar3 + 8) = plVar4;
    plVar4 = param_1 + 2;
    param_1[1] = (longlong)param_1;
    *param_1 = (longlong)param_1;
    lVar3 = *plVar4;
    if ((*(longlong **)(lVar3 + 8) == plVar4) &&
       (plVar5 = (longlong *)param_1[3], (longlong *)*plVar5 == plVar4)) {
      *plVar5 = lVar3;
      *(longlong **)(lVar3 + 8) = plVar5;
      param_1[3] = (longlong)plVar4;
      *plVar4 = (longlong)plVar4;
      plVar4 = param_1 + 4;
      plVar5 = (longlong *)*plVar4;
      if (plVar5 != plVar4) {
        if (((longlong *)plVar5[1] != plVar4) ||
           (plVar6 = (longlong *)param_1[5], (longlong *)*plVar6 != plVar4)) goto LAB_1c002388f;
        *plVar6 = (longlong)plVar5;
        plVar5[1] = (longlong)plVar6;
        param_1[5] = (longlong)plVar4;
        *plVar4 = (longlong)plVar4;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sS(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),plVar6,8,0xe,
                             &WPP_5a306037547032d76a1bb21b8aa3fd30_Traceguids,
                             "RhpDereferenceConnectionLocked",*(wchar_t **)(param_1[6] + 0x38));
        }
      }
      RhpFreeConnection((longlong)param_1);
      return;
    }
  }
LAB_1c002388f:
  pcVar7 = (code *)swi(0x29);
  (*pcVar7)(3);
  pcVar7 = (code *)swi(3);
  (*pcVar7)();
  return;
}



===== RhpProcessAllocateConnectionIoctl @ 1c002389c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong RhpProcessAllocateConnectionIoctl
                    (undefined8 param_1,undefined8 param_2,undefined4 *param_3)

{
  longlong lVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  undefined2 uVar6;
  undefined4 *local_res8;
  longlong local_res18;
  longlong local_res20;
  undefined8 local_28;
  undefined8 local_20;
  
  lVar1 = WdfFunctions_01015;
  local_res18 = 0;
  local_28 = 0;
  local_res8 = (undefined4 *)0x0;
  local_20 = 0;
  *param_3 = 0;
  local_res20 = 0;
  uVar4 = param_2;
  uVar2 = (**(code **)(lVar1 + 0x868))(WdfDriverGlobals,param_2,0x20,&local_res18,&local_28);
  uVar5 = (ulonglong)uVar2;
  if ((int)uVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return uVar5;
    }
    uVar6 = 0x24;
    param_2 = uVar4;
  }
  else {
    uVar2 = (**(code **)(WdfFunctions_01015 + 0x870))
                      (WdfDriverGlobals,param_2,0x10,&local_res8,&local_20);
    uVar5 = (ulonglong)uVar2;
    if (-1 < (int)uVar2) {
      uVar2 = *(uint *)(local_res18 + 4);
      uVar5 = (ulonglong)uVar2;
      if ((((uVar2 != 0) && (uVar2 != 2)) && (uVar2 != 3)) && (uVar2 != 4)) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar5,6,0x26,
                             &WPP_a781b87147d030366b419d92a3dc1ed1_Traceguids,
                             "RhpProcessAllocateConnectionIoctl",(char)uVar2);
        }
        return 0xc00000bb;
      }
      lVar1 = *(longlong *)(local_res18 + 8);
      uVar3 = RhpAllocateConnectionUsingId(lVar1,uVar2,local_res18 + 8,&local_res20);
      if (((int)uVar3 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_SF_siD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar5,6,0x27,
                            &WPP_a781b87147d030366b419d92a3dc1ed1_Traceguids,
                            "RhpProcessAllocateConnectionIoctl",(char)lVar1,(char)uVar3);
      }
      *param_3 = 0x10;
      *local_res8 = 1;
      *(longlong *)(local_res8 + 2) = local_res20;
      return uVar3 & 0xffffffff;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return uVar5;
    }
    uVar6 = 0x25;
  }
  WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,6,uVar6,
                     &WPP_a781b87147d030366b419d92a3dc1ed1_Traceguids,
                     "RhpProcessAllocateConnectionIoctl",(char)uVar2);
  return uVar5;
}



===== RhpGetControllerNameFromCacheById @ 1c0023ab0 =====

undefined8 RhpGetControllerNameFromCacheById(undefined8 param_1,longlong param_2,ushort *param_3)

{
  int *piVar1;
  int iVar2;
  ushort uVar3;
  void *_Src;
  longlong *plVar4;
  longlong *plVar5;
  code *pcVar6;
  bool bVar7;
  bool bVar8;
  uint uVar9;
  void *_Dst;
  undefined8 uVar10;
  uint uVar11;
  undefined8 *puVar12;
  longlong lVar13;
  longlong *plVar14;
  undefined8 *puVar15;
  
  lVar13 = 0;
  puVar15 = (undefined8 *)0x0;
  ExAcquireFastMutex(&RhTranslationCacheLock);
  for (plVar14 = RhConnectionListHead;
      ((longlong **)plVar14 != &RhConnectionListHead && (plVar14[7] <= param_2));
      plVar14 = (longlong *)*plVar14) {
    if (plVar14[7] == param_2) {
      LOCK();
      *(int *)((longlong)plVar14 + 0x74) = *(int *)((longlong)plVar14 + 0x74) + 1;
      UNLOCK();
      puVar12 = *(undefined8 **)(plVar14[6] + 0x48);
      if (puVar12 != (undefined8 *)0x0) {
        LOCK();
        *(int *)(puVar12 + 6) = *(int *)(puVar12 + 6) + 1;
        UNLOCK();
        puVar15 = puVar12;
      }
      ExReleaseFastMutex(&RhTranslationCacheLock);
      if (plVar14 == (longlong *)0x0) goto LAB_1c0023b2c;
      bVar7 = false;
      puVar12 = puVar15;
      bVar8 = false;
      if (puVar15 == (undefined8 *)0x0) {
        ExAcquireFastMutex(&RhTranslationCacheLock);
        lVar13 = *(longlong *)(plVar14[6] + 0x40);
        if (lVar13 == 0) {
          ExReleaseFastMutex(&RhTranslationCacheLock);
        }
        else {
          ObfReferenceObject(lVar13);
          ExReleaseFastMutex(&RhTranslationCacheLock);
          RhpConnectProviderDevice(param_1,(ushort *)(plVar14[6] + 0x30),lVar13);
          ExAcquireFastMutex(&RhTranslationCacheLock);
          puVar12 = *(undefined8 **)(plVar14[6] + 0x48);
          if (puVar12 != (undefined8 *)0x0) {
            LOCK();
            *(int *)(puVar12 + 6) = *(int *)(puVar12 + 6) + 1;
            UNLOCK();
            ExReleaseFastMutex();
            bVar8 = true;
            goto LAB_1c0023c00;
          }
          ExReleaseFastMutex(&RhTranslationCacheLock);
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sSq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
        }
        uVar10 = 0xc00000a3;
        puVar12 = puVar15;
      }
      else {
LAB_1c0023c00:
        bVar7 = bVar8;
        uVar3 = *(ushort *)(puVar12 + 2);
        uVar11 = uVar3 + 2;
        param_3[0] = 0;
        param_3[1] = 0;
        param_3[2] = 0;
        param_3[3] = 0;
        param_3[4] = 0;
        param_3[5] = 0;
        param_3[6] = 0;
        param_3[7] = 0;
        if (uVar11 < 0x10001) {
          if (uVar11 < 2) {
            uVar10 = 0xc0000023;
          }
          else {
            uVar9 = uVar3 + 3;
            if ((uVar11 & 1) == 0) {
              uVar9 = uVar11;
            }
            _Dst = (void *)ExAllocatePool2(0x100,uVar9,0x48736552);
            if (_Dst == (void *)0x0) {
              uVar10 = 0xc000009a;
            }
            else {
              *(undefined2 *)(((ulonglong)uVar9 - 2) + (longlong)_Dst) = 0;
              uVar11 = 0xfffe;
              if (uVar9 < 0xfffe) {
                uVar11 = uVar9;
              }
              uVar10 = 0;
              param_3[2] = 0;
              param_3[3] = 0;
              uVar3 = *(ushort *)(puVar12 + 2);
              _Src = (void *)puVar12[3];
              param_3[1] = (ushort)uVar11;
              *(void **)(param_3 + 4) = _Dst;
              memcpy(_Dst,_Src,(ulonglong)uVar3);
              uVar3 = *(ushort *)(puVar12 + 2);
              *(undefined2 *)((ulonglong)uVar3 + (longlong)_Dst) = 0;
              *param_3 = uVar3;
            }
          }
        }
        else {
          uVar10 = 0xc0000106;
        }
      }
      if ((bVar7) && (puVar12 != (undefined8 *)0x0)) {
        RhpDereferenceTargetData(puVar12);
      }
      if (lVar13 != 0) {
        ObfDereferenceObject(lVar13);
      }
      if ((int)uVar10 < 0) {
        param_3[0] = 0;
        param_3[1] = 0;
        param_3[2] = 0;
        param_3[3] = 0;
        param_3[4] = 0;
        param_3[5] = 0;
        param_3[6] = 0;
        param_3[7] = 0;
      }
      goto LAB_1c0023b39;
    }
  }
  plVar14 = (longlong *)0x0;
  ExReleaseFastMutex(&RhTranslationCacheLock);
LAB_1c0023b2c:
  uVar10 = 0xc0000225;
LAB_1c0023b39:
  if (puVar15 != (undefined8 *)0x0) {
    LOCK();
    piVar1 = (int *)(puVar15 + 6);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      ExAcquireFastMutex(&RhTranslationCacheLock);
      if (*(int *)(puVar15 + 6) == 0) {
        ExReleaseFastMutex();
        RhpFreeTargetData(puVar15);
      }
      else {
        ExReleaseFastMutex(&RhTranslationCacheLock);
      }
    }
  }
  if (plVar14 != (longlong *)0x0) {
    ExAcquireFastMutex(&RhTranslationCacheLock);
    LOCK();
    piVar1 = (int *)((longlong)plVar14 + 0x74);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if ((iVar2 == 1) && (*(int *)((longlong)plVar14 + 0x74) == 0)) {
      lVar13 = *plVar14;
      if ((*(longlong **)(lVar13 + 8) != plVar14) ||
         (plVar4 = (longlong *)plVar14[1], (longlong *)*plVar4 != plVar14)) {
LAB_1c0023f5d:
        pcVar6 = (code *)swi(0x29);
        (*pcVar6)(3);
        pcVar6 = (code *)swi(3);
        uVar10 = (*pcVar6)();
        return uVar10;
      }
      *plVar4 = lVar13;
      *(longlong **)(lVar13 + 8) = plVar4;
      plVar4 = plVar14 + 2;
      plVar14[1] = (longlong)plVar14;
      *plVar14 = (longlong)plVar14;
      lVar13 = *plVar4;
      if ((*(longlong **)(lVar13 + 8) != plVar4) ||
         (plVar5 = (longlong *)plVar14[3], (longlong *)*plVar5 != plVar4)) goto LAB_1c0023f5d;
      *plVar5 = lVar13;
      *(longlong **)(lVar13 + 8) = plVar5;
      plVar14[3] = (longlong)plVar4;
      *plVar4 = (longlong)plVar4;
      plVar4 = plVar14 + 4;
      plVar5 = (longlong *)*plVar4;
      if (plVar5 != plVar4) {
        if (((longlong *)plVar5[1] != plVar4) ||
           (puVar15 = (undefined8 *)plVar14[5], (longlong *)*puVar15 != plVar4)) goto LAB_1c0023f5d;
        *puVar15 = plVar5;
        plVar5[1] = (longlong)puVar15;
        plVar14[5] = (longlong)plVar4;
        *plVar4 = (longlong)plVar4;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sS(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar15,8,0xe,
                             &WPP_5a306037547032d76a1bb21b8aa3fd30_Traceguids,
                             "RhpDereferenceConnectionLocked",*(wchar_t **)(plVar14[6] + 0x38));
        }
      }
      RhpFreeConnection((longlong)plVar14);
    }
    ExReleaseFastMutex(&RhTranslationCacheLock);
  }
  return uVar10;
}



===== RhWdmDeviceFileCreate @ 1c0023f70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong RhWdmDeviceFileCreate(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined2 uVar5;
  wchar_t *pwVar6;
  ulonglong local_18;
  wchar_t *pwStack_10;
  
  lVar1 = *(longlong *)(param_2 + 0xb8);
  local_18 = 0;
  pwStack_10 = (wchar_t *)0x0;
  lVar2 = *(longlong *)(lVar1 + 0x30);
  if ((*(short *)(lVar2 + 0x58) == 0) || (*(longlong *)(lVar2 + 0x60) == 0)) {
    RhpFreeUnicodeString(&local_18);
    uVar4 = (**(code **)(WdfFunctions_01015 + 0x110))(WdfDriverGlobals,param_1,param_2);
    return uVar4;
  }
  uVar4 = RhpBuildReparseName(param_1,(ushort *)(lVar2 + 0x58),(ushort *)&local_18);
  pwVar6 = pwStack_10;
  uVar3 = (uint)uVar4;
  if ((int)uVar3 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c002402c;
    pwVar6 = *(wchar_t **)(lVar2 + 0x60);
    uVar5 = 0x18;
  }
  else {
    uVar3 = IoReplaceFileObjectName(*(undefined8 *)(lVar1 + 0x30),pwStack_10,local_18 & 0xffff);
    if (-1 < (int)uVar3) {
      uVar3 = 0x104;
      goto LAB_1c002402c;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c002402c;
    uVar5 = 0x19;
  }
  WPP_RECORDER_SF_sSD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),0,5,uVar5,
                      &WPP_a781b87147d030366b419d92a3dc1ed1_Traceguids,"RhWdmDeviceFileCreate",
                      pwVar6,(char)uVar3);
LAB_1c002402c:
  RhpFreeUnicodeString(&local_18);
  *(uint *)(param_2 + 0x30) = uVar3;
  *(undefined8 *)(param_2 + 0x38) = 0;
  IofCompleteRequest(param_2,0);
  return (ulonglong)uVar3;
}



===== RhpBuildReparseName @ 1c00240e0 =====

ulonglong RhpBuildReparseName(undefined8 param_1,ushort *param_2,ushort *param_3)

{
  int *piVar1;
  int iVar2;
  short sVar3;
  longlong *plVar4;
  longlong *plVar5;
  undefined8 uVar6;
  code *pcVar7;
  bool bVar8;
  undefined6 uVar9;
  undefined1 *puVar10;
  bool bVar11;
  uint uVar12;
  short *psVar13;
  ulonglong uVar14;
  void *_Dst;
  ushort uVar15;
  longlong lVar16;
  ulonglong uVar17;
  undefined1 *puVar18;
  undefined1 *puVar19;
  undefined8 *puVar20;
  longlong *plVar21;
  uint uVar22;
  ushort local_res20;
  undefined1 auStackY_d8 [8];
  undefined1 auStackY_d0 [24];
  short *local_98;
  undefined8 *local_90;
  undefined8 local_88;
  ulonglong local_80;
  void *pvStack_78;
  undefined8 local_70;
  short *psStack_68;
  undefined8 local_60;
  short *psStack_58;
  
  param_3[0] = 0;
  param_3[1] = 0;
  param_3[2] = 0;
  param_3[3] = 0;
  param_3[4] = 0;
  param_3[5] = 0;
  param_3[6] = 0;
  param_3[7] = 0;
  local_res20 = *param_2;
  local_98 = *(short **)(param_2 + 4);
  local_88 = 0;
  local_80 = 0;
  pvStack_78 = (void *)0x0;
  if (local_res20 < 2) {
LAB_1c0024137:
    uVar17 = 0xc000000d;
    puVar10 = auStackY_d8;
LAB_1c00248c5:
    puVar18 = puVar10;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar6 = *(undefined8 *)(param_2 + 4);
      *(int *)(puVar18 + 0x38) = (int)uVar17;
      *(undefined8 *)(puVar18 + 0x30) = uVar6;
      *(char **)(puVar18 + 0x28) = "RhpBuildReparseName";
      uVar6 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
      *(undefined **)(puVar18 + 0x20) = &WPP_a781b87147d030366b419d92a3dc1ed1_Traceguids;
      *(undefined8 *)(puVar18 + -8) = 0x1c002490f;
      WPP_RECORDER_SF_sSD(uVar6,0,5,0x1d,*(undefined8 *)(puVar18 + 0x20),*(char **)(puVar18 + 0x28),
                          *(wchar_t **)(puVar18 + 0x30),puVar18[0x38]);
    }
  }
  else {
    if (*local_98 == 0x5c) {
      local_98 = local_98 + 1;
      local_res20 = local_res20 - 2;
      if (local_res20 < 2) goto LAB_1c0024137;
    }
    local_70 = 0;
    psStack_68 = (short *)0x0;
    local_60 = 0;
    psStack_58 = (short *)0x0;
    if (local_98 == (short *)0x0) {
      uVar15 = 0;
LAB_1c00241d6:
      lVar16 = local_70;
      uVar17 = 0xc000000d;
      if (uVar15 < 0x20) {
LAB_1c0024222:
        uVar12 = 0xc000000d;
      }
      else {
        uVar9 = local_70._2_6_;
        local_70 = CONCAT62(local_70._2_6_,0x20);
        for (uVar15 = 0; uVar15 < 0x10; uVar15 = uVar15 + 1) {
          sVar3 = psStack_68[uVar15];
          if (((9 < (ushort)(sVar3 - 0x30U)) && (5 < (ushort)(sVar3 - 0x61U))) &&
             (5 < (ushort)(sVar3 - 0x41U))) goto LAB_1c0024222;
        }
        if ((psStack_68[uVar15] == 0x5c) || (psStack_68[uVar15] == 0)) {
          psStack_58 = psStack_68 + 8;
          local_70._2_2_ = SUB82(lVar16,2);
          uVar15 = local_70._2_2_ - 0x10;
          local_70 = CONCAT62(uVar9,0x10);
          local_60 = CONCAT62((uint6)uVar15,0x10);
          uVar12 = RtlUnicodeStringToInteger(&local_70,0x10,(longlong)&local_88 + 4);
          if (-1 < (int)uVar12) {
            uVar12 = RtlUnicodeStringToInteger(&local_60,0x10,&local_88);
            lVar16 = local_88;
            if (-1 < (int)uVar12) {
              local_90 = (undefined8 *)0x0;
              ExAcquireFastMutex(&RhTranslationCacheLock);
              for (plVar21 = RhConnectionListHead;
                  ((longlong **)plVar21 != &RhConnectionListHead && (plVar21[7] <= lVar16));
                  plVar21 = (longlong *)*plVar21) {
                if (plVar21[7] == lVar16) {
                  LOCK();
                  *(int *)((longlong)plVar21 + 0x74) = *(int *)((longlong)plVar21 + 0x74) + 1;
                  UNLOCK();
                  puVar20 = *(undefined8 **)(plVar21[6] + 0x48);
                  if (puVar20 != (undefined8 *)0x0) {
                    LOCK();
                    *(int *)(puVar20 + 6) = *(int *)(puVar20 + 6) + 1;
                    UNLOCK();
                    local_90 = puVar20;
                  }
                  ExReleaseFastMutex(&RhTranslationCacheLock);
                  if (plVar21 == (longlong *)0x0) goto LAB_1c002430c;
                  bVar8 = false;
                  lVar16 = 0;
                  puVar20 = local_90;
                  bVar11 = false;
                  if (local_90 == (undefined8 *)0x0) {
                    ExAcquireFastMutex(&RhTranslationCacheLock);
                    lVar16 = *(longlong *)(plVar21[6] + 0x40);
                    if (lVar16 == 0) {
                      ExReleaseFastMutex(&RhTranslationCacheLock);
                    }
                    else {
                      ObfReferenceObject(lVar16);
                      ExReleaseFastMutex(&RhTranslationCacheLock);
                      RhpConnectProviderDevice(param_1,(ushort *)(plVar21[6] + 0x30),lVar16);
                      ExAcquireFastMutex(&RhTranslationCacheLock);
                      puVar20 = *(undefined8 **)(plVar21[6] + 0x48);
                      if (puVar20 != (undefined8 *)0x0) {
                        LOCK();
                        *(int *)(puVar20 + 6) = *(int *)(puVar20 + 6) + 1;
                        UNLOCK();
                        ExReleaseFastMutex();
                        bVar11 = true;
                        goto LAB_1c002449e;
                      }
                      ExReleaseFastMutex(&RhTranslationCacheLock);
                    }
                    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                      WPP_RECORDER_SF_sSq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
                    }
                    uVar17 = 0xc00000a3;
                    puVar20 = local_90;
                  }
                  else {
LAB_1c002449e:
                    bVar8 = bVar11;
                    uVar12 = *(ushort *)(puVar20 + 2) + 2;
                    local_80 = 0;
                    pvStack_78 = (void *)0x0;
                    if (uVar12 < 0x10001) {
                      if (uVar12 < 2) {
                        uVar17 = 0xc0000023;
                      }
                      else {
                        if ((uVar12 & 1) != 0) {
                          uVar12 = *(ushort *)(puVar20 + 2) + 3;
                        }
                        _Dst = (void *)ExAllocatePool2(0x100,(ulonglong)uVar12,0x48736552);
                        if (_Dst == (void *)0x0) {
                          uVar17 = 0xc000009a;
                        }
                        else {
                          *(undefined2 *)(((ulonglong)uVar12 - 2) + (longlong)_Dst) = 0;
                          uVar22 = 0xfffe;
                          if (uVar12 < 0xfffe) {
                            uVar22 = uVar12;
                          }
                          uVar17 = 0;
                          local_80 = (ulonglong)CONCAT22((short)uVar22,(short)local_80);
                          pvStack_78 = _Dst;
                          memcpy(_Dst,(void *)puVar20[3],(ulonglong)*(ushort *)(puVar20 + 2));
                          local_80 = CONCAT62(local_80._2_6_,*(ushort *)(puVar20 + 2));
                          *(undefined2 *)((ulonglong)*(ushort *)(puVar20 + 2) + (longlong)_Dst) = 0;
                        }
                      }
                    }
                    else {
                      uVar17 = 0xc0000106;
                    }
                  }
                  if ((bVar8) && (puVar20 != (undefined8 *)0x0)) {
                    RhpDereferenceTargetData(puVar20);
                  }
                  if (lVar16 != 0) {
                    ObfDereferenceObject(lVar16);
                  }
                  if ((int)uVar17 < 0) {
                    pvStack_78 = (void *)0x0;
                    local_80 = 0;
                  }
                  goto LAB_1c002431e;
                }
              }
              plVar21 = (longlong *)0x0;
              ExReleaseFastMutex(&RhTranslationCacheLock);
              local_90 = (undefined8 *)0x0;
LAB_1c002430c:
              uVar17 = 0xc0000225;
LAB_1c002431e:
              puVar18 = auStackY_d8;
              puVar19 = auStackY_d8;
              if (local_90 != (undefined8 *)0x0) {
                LOCK();
                piVar1 = (int *)(local_90 + 6);
                iVar2 = *piVar1;
                *piVar1 = *piVar1 + -1;
                UNLOCK();
                if (iVar2 == 1) {
                  ExAcquireFastMutex(&RhTranslationCacheLock);
                  if (*(int *)(local_90 + 6) == 0) {
                    ExReleaseFastMutex();
                    RhpFreeTargetData(local_90);
                  }
                  else {
                    ExReleaseFastMutex(&RhTranslationCacheLock);
                  }
                }
              }
              if (plVar21 != (longlong *)0x0) {
                ExAcquireFastMutex(&RhTranslationCacheLock);
                LOCK();
                piVar1 = (int *)((longlong)plVar21 + 0x74);
                iVar2 = *piVar1;
                *piVar1 = *piVar1 + -1;
                UNLOCK();
                if ((iVar2 == 1) && (*(int *)((longlong)plVar21 + 0x74) == 0)) {
                  lVar16 = *plVar21;
                  if ((*(longlong **)(lVar16 + 8) == plVar21) &&
                     (plVar4 = (longlong *)plVar21[1], (longlong *)*plVar4 == plVar21)) {
                    *plVar4 = lVar16;
                    *(longlong **)(lVar16 + 8) = plVar4;
                    plVar4 = plVar21 + 2;
                    plVar21[1] = (longlong)plVar21;
                    *plVar21 = (longlong)plVar21;
                    lVar16 = *plVar4;
                    if ((*(longlong **)(lVar16 + 8) == plVar4) &&
                       (plVar5 = (longlong *)plVar21[3], (longlong *)*plVar5 == plVar4)) {
                      *plVar5 = lVar16;
                      *(longlong **)(lVar16 + 8) = plVar5;
                      plVar21[3] = (longlong)plVar4;
                      *plVar4 = (longlong)plVar4;
                      plVar4 = plVar21 + 4;
                      plVar5 = (longlong *)*plVar4;
                      if (plVar5 != plVar4) {
                        if (((longlong *)plVar5[1] != plVar4) ||
                           (puVar20 = (undefined8 *)plVar21[5], (longlong *)*puVar20 != plVar4))
                        goto LAB_1c00248ba;
                        *puVar20 = plVar5;
                        plVar5[1] = (longlong)puVar20;
                        plVar21[5] = (longlong)plVar4;
                        *plVar4 = (longlong)plVar4;
                        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                          WPP_RECORDER_SF_sS(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar20,8,
                                             0xe,&WPP_5a306037547032d76a1bb21b8aa3fd30_Traceguids,
                                             "RhpDereferenceConnectionLocked",
                                             *(wchar_t **)(plVar21[6] + 0x38));
                        }
                      }
                      RhpFreeConnection((longlong)plVar21);
                      goto LAB_1c0024367;
                    }
                  }
LAB_1c00248ba:
                  pcVar7 = (code *)swi(0x29);
                  (*pcVar7)(3);
                  puVar10 = auStackY_d0;
                  goto LAB_1c00248c5;
                }
LAB_1c0024367:
                ExReleaseFastMutex(&RhTranslationCacheLock);
              }
              puVar10 = auStackY_d8;
              if ((int)uVar17 < 0) goto LAB_1c00248c5;
              uVar12 = (ushort)local_80 + 4 + (uint)local_res20;
              param_3[0] = 0;
              param_3[1] = 0;
              param_3[2] = 0;
              param_3[3] = 0;
              param_3[4] = 0;
              param_3[5] = 0;
              param_3[6] = 0;
              param_3[7] = 0;
              if (0x10000 < uVar12) {
                RhpFreeUnicodeString(&local_80);
                RhpFreeUnicodeString((undefined8 *)param_3);
                return 0xc0000106;
              }
              if (uVar12 < 2) {
                uVar17 = 0xc0000023;
                RhpFreeUnicodeString(&local_80);
                goto LAB_1c0024436;
              }
              if ((uVar12 & 1) != 0) {
                uVar12 = uVar12 + 1;
              }
              lVar16 = ExAllocatePool2(0x100,(ulonglong)uVar12,0x48736552);
              if (lVar16 == 0) {
                uVar17 = 0xc000009a;
                RhpFreeUnicodeString(&local_80);
                puVar19 = auStackY_d8;
                goto LAB_1c0024436;
              }
              *(undefined2 *)(((ulonglong)uVar12 - 2) + lVar16) = 0;
              param_3[0] = 0;
              param_3[1] = 0;
              param_3[2] = 0;
              param_3[3] = 0;
              param_3[4] = 0;
              param_3[5] = 0;
              param_3[6] = 0;
              param_3[7] = 0;
              uVar22 = 0xfffe;
              if (uVar12 < 0xfffe) {
                uVar22 = uVar12;
              }
              *(longlong *)(param_3 + 4) = lVar16;
              param_3[1] = (ushort)uVar22;
              uVar14 = RtlUnicodeStringPrintf(param_3,L"%s\\%s",pvStack_78,local_98);
              uVar17 = uVar14 & 0xffffffff;
              if ((int)uVar14 < 0) {
                RhpFreeUnicodeString(&local_80);
                RhpFreeUnicodeString((undefined8 *)param_3);
                return uVar17;
              }
              goto LAB_1c00242ab;
            }
          }
          uVar17 = (ulonglong)uVar12;
        }
        else {
          uVar12 = 0xc000000d;
        }
      }
    }
    else {
      lVar16 = 0x7fff;
      psVar13 = local_98;
      do {
        if (*psVar13 == 0) break;
        psVar13 = psVar13 + 1;
        lVar16 = lVar16 + -1;
      } while (lVar16 != 0);
      uVar17 = 0xc000000d;
      uVar12 = 0xc000000d;
      if (lVar16 == 0) {
        uVar15 = 0;
      }
      else {
        uVar17 = 0;
        uVar12 = 0;
        uVar15 = (0x7fff - (short)lVar16) * 2;
        local_70 = (ulonglong)(ushort)(uVar15 + 2) << 0x10;
        psStack_68 = local_98;
      }
      if (-1 < (int)uVar12) goto LAB_1c00241d6;
    }
    puVar18 = auStackY_d8;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sSD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),0,5,0x1c,
                          &WPP_a781b87147d030366b419d92a3dc1ed1_Traceguids,"RhpBuildReparseName",
                          *(wchar_t **)(param_2 + 4),(char)uVar12);
      RhpFreeUnicodeString(&local_80);
      puVar19 = auStackY_d8;
      goto LAB_1c0024436;
    }
  }
LAB_1c00242ab:
  *(undefined8 *)(puVar18 + -8) = 0x1c00242b4;
  RhpFreeUnicodeString(&local_80);
  puVar19 = puVar18;
  if (-1 < (int)uVar17) {
    return uVar17;
  }
LAB_1c0024436:
  *(undefined8 *)(puVar19 + -8) = 0x1c002443e;
  RhpFreeUnicodeString((undefined8 *)param_3);
  return uVar17;
}



===== RhpGetProviderBiosNameFromDescriptor @ 1c0024934 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint RhpGetProviderBiosNameFromDescriptor
               (undefined8 param_1,char *param_2,uint param_3,undefined8 *param_4)

{
  char cVar1;
  ushort uVar2;
  ushort uVar3;
  uint uVar4;
  uint uVar5;
  undefined8 uVar6;
  uint uVar7;
  ulonglong uVar8;
  uint local_res10 [2];
  undefined8 local_38;
  void *pvStack_30;
  ulonglong local_28;
  void *pvStack_20;
  
  local_res10[0] = 0;
  local_38 = 0;
  pvStack_30 = (void *)0x0;
  *param_4 = 0;
  param_4[1] = 0;
  local_28 = 0;
  pvStack_20 = (void *)0x0;
  if ((param_2 == (char *)0x0) || (param_3 == 0)) {
    uVar4 = 0xc000000d;
  }
  else {
    cVar1 = *param_2;
    if (cVar1 == -0x74) {
      uVar6 = RhpGetResourceNameFromGpioDescriptor(param_2,param_3,&local_28);
      uVar4 = (uint)uVar6;
    }
    else if (cVar1 == -0x73) {
      uVar6 = RhpGetResourceNameFromFunctionConfigDescriptor(param_2,param_3,&local_28);
      uVar4 = (uint)uVar6;
    }
    else {
      if (cVar1 != -0x72) {
        uVar4 = 0xc00000bb;
        goto LAB_1c0024a9b;
      }
      uVar4 = RhpGetResourceNameFromSerialBusDescriptor
                        ((longlong)param_2,param_3,(short *)&local_28);
    }
    if (-1 < (int)uVar4) {
      uVar3 = (ushort)local_28;
      uVar8 = local_28 & 0xffff;
      uVar6 = RhpAllocateAnsiString((ushort)local_28 + 1,&local_38);
      uVar4 = (uint)uVar6;
      if (-1 < (int)uVar4) {
        uVar2 = uVar3;
        if (local_38._2_2_ < uVar3) {
          uVar2 = local_38._2_2_;
        }
        memcpy(pvStack_30,pvStack_20,(ulonglong)uVar2);
        local_38 = CONCAT62(local_38._2_6_,uVar3);
        *(undefined1 *)(uVar8 + (longlong)pvStack_30) = 0;
        uVar4 = RtlxAnsiStringToUnicodeSize(&local_38);
        uVar5 = 0x80;
        if (0x80 < uVar4) {
          uVar5 = RtlxAnsiStringToUnicodeSize(&local_38);
        }
        uVar7 = 0;
        while( true ) {
          uVar6 = RhpAllocateUnicodeString(uVar5,param_4);
          uVar4 = (uint)uVar6;
          if ((int)uVar4 < 0) break;
          uVar4 = (*RHGetFullyQualifiedBiosName)(param_1,&local_38,param_4,local_res10);
          if ((int)uVar4 < 0) {
            RhpFreeUnicodeString(param_4);
          }
          if ((uVar4 != 0xc0000023) || (uVar7 = uVar7 + 1, uVar5 = local_res10[0], 1 < uVar7))
          break;
        }
      }
    }
  }
LAB_1c0024a9b:
  if (pvStack_30 != (void *)0x0) {
    ExFreePoolWithTag(pvStack_30,0x48736552);
  }
  local_38 = 0;
  pvStack_30 = (void *)0x0;
  if ((int)uVar4 < 0) {
    RhpFreeUnicodeString(param_4);
  }
  return uVar4;
}



===== RhpAllocateUnicodeString @ 1c0024af0 =====

undefined8 RhpAllocateUnicodeString(uint param_1,undefined8 *param_2)

{
  uint uVar1;
  longlong lVar2;
  undefined8 uVar3;
  uint uVar4;
  
  *param_2 = 0;
  param_2[1] = 0;
  if (0x10000 < param_1) {
    return 0xc0000106;
  }
  if (param_1 < 2) {
    uVar3 = 0xc0000023;
  }
  else {
    uVar1 = param_1 + 1;
    if ((param_1 & 1) == 0) {
      uVar1 = param_1;
    }
    lVar2 = ExAllocatePool2(0x100,uVar1,0x48736552);
    if (lVar2 == 0) {
      return 0xc000009a;
    }
    *(undefined2 *)(((ulonglong)uVar1 - 2) + lVar2) = 0;
    uVar4 = 0xfffe;
    if (uVar1 < 0xfffe) {
      uVar4 = uVar1;
    }
    *param_2 = 0;
    param_2[1] = 0;
    param_2[1] = lVar2;
    uVar3 = 0;
    *(short *)((longlong)param_2 + 2) = (short)uVar4;
  }
  return uVar3;
}



===== RhpAllocateAnsiString @ 1c0024b94 =====

undefined8 RhpAllocateAnsiString(uint param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  longlong lVar2;
  ulonglong uVar3;
  
  uVar3 = (ulonglong)param_1;
  *param_2 = 0;
  param_2[1] = 0;
  if (param_1 < 0x8001) {
    if (param_1 == 0) {
      uVar1 = 0xc0000023;
    }
    else {
      lVar2 = ExAllocatePool2(0x100,uVar3,0x48736552);
      uVar1 = 0;
      if (lVar2 == 0) {
        uVar1 = 0xc000009a;
      }
      else {
        *(undefined1 *)((uVar3 - 1) + lVar2) = 0;
        *param_2 = 0;
        param_2[1] = 0;
        if (0x7ffe < param_1) {
          uVar3 = 0x7fff;
        }
        param_2[1] = lVar2;
        *(short *)((longlong)param_2 + 2) = (short)uVar3;
      }
    }
  }
  else {
    uVar1 = 0xc0000106;
  }
  return uVar1;
}



===== RhpDereferenceProvider @ 1c0024c30 =====

void RhpDereferenceProvider(longlong *param_1)

{
  longlong *plVar1;
  code *pcVar2;
  longlong lVar3;
  undefined1 *puVar4;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  LOCK();
  plVar1 = param_1 + 10;
  lVar3 = *plVar1;
  *(int *)plVar1 = (int)*plVar1 + -1;
  UNLOCK();
  if ((int)lVar3 == 1) {
    ExAcquireFastMutex(&RhTranslationCacheLock);
    puVar4 = auStack_28;
    if ((int)param_1[10] == 0) {
      lVar3 = *param_1;
      if ((*(longlong **)(lVar3 + 8) == param_1) &&
         (plVar1 = (longlong *)param_1[1], (longlong *)*plVar1 == param_1)) {
        *plVar1 = lVar3;
        *(longlong **)(lVar3 + 8) = plVar1;
        param_1[1] = (longlong)param_1;
        *param_1 = (longlong)param_1;
        ExReleaseFastMutex(&RhTranslationCacheLock);
        RhpFreeProvider((longlong)param_1);
        return;
      }
      pcVar2 = (code *)swi(0x29);
      (*pcVar2)(3);
      puVar4 = auStack_20;
    }
    *(undefined8 *)(puVar4 + -8) = 0x1c0024cbb;
    ExReleaseFastMutex(&RhTranslationCacheLock);
  }
  return;
}



===== RhpFindAndReferenceConnectionByIdLocked @ 1c0024cd0 =====

undefined8 * RhpFindAndReferenceConnectionByIdLocked(longlong param_1)

{
  undefined8 *puVar1;
  
  for (puVar1 = RhConnectionListHead;
      ((undefined8 **)puVar1 != &RhConnectionListHead && ((longlong)puVar1[7] <= param_1));
      puVar1 = (undefined8 *)*puVar1) {
    if (puVar1[7] == param_1) {
      LOCK();
      *(int *)((longlong)puVar1 + 0x74) = *(int *)((longlong)puVar1 + 0x74) + 1;
      UNLOCK();
      return puVar1;
    }
  }
  return (undefined8 *)0x0;
}



===== RhpDereferenceTargetData @ 1c0024d04 =====

void RhpDereferenceTargetData(undefined8 *param_1)

{
  int *piVar1;
  int iVar2;
  
  LOCK();
  piVar1 = (int *)(param_1 + 6);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    ExAcquireFastMutex(&RhTranslationCacheLock);
    if (*(int *)(param_1 + 6) == 0) {
      ExReleaseFastMutex();
      RhpFreeTargetData(param_1);
    }
    else {
      ExReleaseFastMutex(&RhTranslationCacheLock);
    }
  }
  return;
}



===== RhpFreeConnection @ 1c0024d6c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void RhpFreeConnection(longlong param_1)

{
  if (*(longlong *)(param_1 + 0x68) != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
    *(undefined8 *)(param_1 + 0x68) = 0;
    *(undefined1 *)(param_1 + 0x70) = 0;
  }
  if (*(longlong **)(param_1 + 0x30) != (longlong *)0x0) {
    RhpDereferenceProvider(*(longlong **)(param_1 + 0x30));
    *(undefined8 *)(param_1 + 0x30) = 0;
  }
  if (*(longlong *)(param_1 + 0x48) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x48),0x48736552);
    *(undefined8 *)(param_1 + 0x48) = 0;
    *(undefined4 *)(param_1 + 0x50) = 0;
  }
  ExFreePoolWithTag(param_1,0x48736552);
  return;
}



===== RhpGetResourceNameFromSerialBusDescriptor @ 1c0024df8 =====

uint RhpGetResourceNameFromSerialBusDescriptor(longlong param_1,uint param_2,short *param_3)

{
  uint uVar1;
  ulonglong uVar2;
  uint uVar3;
  short sVar4;
  char *pcVar5;
  uint uVar6;
  
  uVar6 = 0;
  if (*(ushort *)(param_1 + 1) + 3 <= param_2) {
    param_2 = *(ushort *)(param_1 + 1) + 3;
  }
  uVar1 = *(ushort *)(param_1 + 10) + 0xc;
  if (param_2 < uVar1) {
    param_3[0] = 0;
    param_3[1] = 0;
    param_3[2] = 0;
    param_3[3] = 0;
    param_3[4] = 0;
    param_3[5] = 0;
    param_3[6] = 0;
    param_3[7] = 0;
    return 0xc000000d;
  }
  uVar3 = param_2 - uVar1;
  pcVar5 = (char *)((ulonglong)uVar1 + param_1);
  *(char **)(param_3 + 4) = pcVar5;
  if (0x7fffffff < uVar3) {
    uVar3 = 0x7fffffff;
  }
  sVar4 = (short)uVar3;
  param_3[1] = sVar4;
  if (sVar4 == 0) {
    sVar4 = 0;
    uVar1 = uVar6;
LAB_1c0024e9d:
    *param_3 = sVar4;
    uVar6 = uVar1;
  }
  else {
    if (pcVar5 != (char *)0x0) {
      uVar2 = (ulonglong)(uVar3 & 0xffff);
      for (; (uVar2 != 0 && (*pcVar5 != '\0')); pcVar5 = pcVar5 + 1) {
        uVar2 = uVar2 - 1;
      }
      uVar1 = ~-(uint)(uVar2 != 0) & 0xc000000d;
      if (uVar2 != 0) {
        sVar4 = sVar4 - (short)uVar2;
        goto LAB_1c0024e9d;
      }
    }
    *param_3 = sVar4;
  }
  return uVar6;
}



===== PlExtProcessNativeMethodInterfaceRequest @ 1c0024eb4 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
PlExtProcessNativeMethodInterfaceRequest(undefined8 param_1,ushort *param_2,undefined4 *param_3)

{
  undefined8 *puVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined2 uVar4;
  
  uVar3 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0xb,
                     &WPP_014e28a2725035dd75100948d63f8491_Traceguids);
  }
  if ((*param_2 < 0x20) || (uVar2 = (ulonglong)param_2[0x10], (ulonglong)*param_2 - 0x20 < uVar2)) {
    uVar3 = 0xc000000d;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0xc000000d;
    }
    uVar4 = 0xc;
  }
  else {
    _PlExtAcpiNativeMethodInterface = *(undefined8 *)(uVar2 + (longlong)param_2);
    DAT_1c00165c8 = ((undefined8 *)(uVar2 + (longlong)param_2))[1];
    puVar1 = (undefined8 *)(uVar2 + 0x10 + (longlong)param_2);
    DAT_1c00165d0 = *puVar1;
    DAT_1c00165d8 = puVar1[1];
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(PlExtLogHandle,4,2,0xd,&WPP_014e28a2725035dd75100948d63f8491_Traceguids);
    }
    memset(param_3,0,0x60);
    *param_3 = 0x10060;
    *(code **)(param_3 + 4) = _guard_check_icall;
    *(code **)(param_3 + 6) = _guard_check_icall;
    *(code **)(param_3 + 10) = PlExtNativeMethodEvalRequest;
    *(code **)(param_3 + 0xc) = PlExtNotifyDiscoverDestroyDevices;
    *(code **)(param_3 + 0xe) = PlExtQueryPlatformExtensionRegistered;
    *(undefined2 *)(param_3 + 8) = 0x40;
    *(undefined8 *)(param_3 + 2) = param_1;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0;
    }
    uVar4 = 0xe;
  }
  WPP_RECORDER_SF_(PlExtLogHandle,4,2,uVar4,&WPP_014e28a2725035dd75100948d63f8491_Traceguids);
  return uVar3;
}



===== RhpValidateAcpiEvalOutputBuffer @ 1c0025034 =====

undefined8 RhpValidateAcpiEvalOutputBuffer(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  undefined8 in_stack_ffffffffffffffd8;
  
  if ((uint)param_2 < 0x14) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sii(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
  }
  else if ((uint)param_2 < *(uint *)(param_1 + 4)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sdi(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,param_3,0x10,
                          in_stack_ffffffffffffffd8,"RhpValidateAcpiEvalOutputBuffer",
                          (char)*(uint *)(param_1 + 4),(char)param_2);
    }
  }
  else {
    uVar1 = *(uint *)(param_1 + 8);
    if (uVar1 == 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),0,9,0x11,
                          &WPP_f39dd610b3443aa27f2e95d1e10c41be_Traceguids,
                          "RhpValidateAcpiEvalOutputBuffer");
      }
    }
    else {
      if ((1 < uVar1) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        WPP_RECORDER_SF_sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,param_3,0x12,
                           in_stack_ffffffffffffffd8,"RhpValidateAcpiEvalOutputBuffer",(char)uVar1);
      }
      if (*(short *)(param_1 + 0xc) == 2) {
        return 0;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,param_3,0x13,
                           in_stack_ffffffffffffffd8,"RhpValidateAcpiEvalOutputBuffer",
                           (char)*(short *)(param_1 + 0xc));
      }
    }
  }
  return 0xc0000001;
}



===== DriverEntry @ 1c0026008 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(undefined8 ****param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 *******pppppppuVar2;
  uint uVar3;
  undefined2 uVar4;
  undefined8 uVar5;
  longlong *plVar6;
  undefined1 auStackY_178 [32];
  undefined8 *******local_138;
  longlong local_130;
  undefined8 local_128;
  undefined8 local_120;
  wchar_t *local_118;
  undefined8 local_110;
  wchar_t *local_108;
  ulonglong local_100;
  undefined8 local_f8;
  code *local_f0;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  ulonglong local_b0;
  wchar_t local_a8 [24];
  wchar_t local_78 [40];
  ulonglong local_28;
  
  local_118 = local_78;
  local_28 = __security_cookie ^ (ulonglong)auStackY_178;
  builtin_wcsncpy(local_78,L"D:P(A;;GA;;;SY)(A;;GA;;;BA)(A;;G",0x20);
  builtin_wcsncpy(local_78 + 0x20,L"A;;;UD)",8);
  local_100 = (ulonglong)(uint)local_100;
  local_b0 = local_b0 & 0xffffffff00000000;
  local_e0 = 0;
  uStack_d8 = 0;
  builtin_wcsncpy(local_a8 + 0x10,L"_HUB",5);
  local_108 = local_a8;
  local_d0 = 0;
  uStack_c8 = 0;
  local_c0 = 0;
  uStack_b8 = 0;
  local_120 = 0x50004e;
  local_110 = 0x2a0028;
  AcpiConnection = 0;
  builtin_wcsncpy(local_a8,L"\\Device\\RESOURCE",0x10);
  local_130 = 0;
  local_138 = (undefined8 *******)0x0;
  local_128 = 0;
  _WPP_MAIN_CB = 0;
  DAT_1c00166a8 = &WPP_ThisDir_CTLGUID_RhTraceGuid;
  DAT_1c00166b0 = 0;
  _DAT_1c00166c0 = 0;
  _DAT_1c00166c8 = 1;
  _DAT_1c00166e0 = 0;
  _DAT_1c00166e8 = 0;
  WppLoadTracingSupport();
  _DAT_1c00166c0 = 0;
  WppInitKm(param_1,param_2);
  local_100 = 0x20;
  local_f0 = RhEvtDriverUnload;
  local_f8 = 0;
  local_e8 = 1;
  local_e4 = 0x48736552;
  pppppppuVar2 = (undefined8 *******)param_1;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x3a0))(WdfDriverGlobals,param_1,param_2);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0026470;
    uVar4 = 10;
    goto LAB_1c0026441;
  }
  local_138 = (undefined8 *******)
              (**(code **)(WdfFunctions_01015 + 200))(WdfDriverGlobals,local_128,&local_120);
  if (local_138 == (undefined8 *******)0x0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),0,1,0xc,
                        &WPP_a781b87147d030366b419d92a3dc1ed1_Traceguids,"DriverEntry");
    }
    iVar1 = -0x3fffffff;
    goto LAB_1c0026470;
  }
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x218))(WdfDriverGlobals,local_138,&local_110);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_Dq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
    goto LAB_1c0026470;
  }
  uVar5 = 0;
  pppppppuVar2 = local_138;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x248))();
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0026470;
    uVar4 = 0xe;
LAB_1c00262ea:
    uVar3 = 2;
  }
  else {
    iVar1 = PlExtpInitialize(0,pppppppuVar2,0,uVar5);
    if (-1 < iVar1) {
      (**(code **)(WdfFunctions_01015 + 0x1e8))(WdfDriverGlobals,local_138,2);
      plVar6 = &local_130;
      local_b0 = 0;
      pppppppuVar2 = &local_138;
      local_d0 = 0;
      uStack_d8 = 0;
      local_e0 = 0x38;
      local_c0 = 0;
      uStack_b8 = 0;
      uStack_c8 = 0x400000001;
      iVar1 = (**(code **)(WdfFunctions_01015 + 600))(WdfDriverGlobals,pppppppuVar2,&local_e0);
      if (iVar1 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0026470;
        uVar4 = 0x10;
      }
      else {
        iVar1 = RhpSetupIoQueues(local_130);
        if (-1 < iVar1) {
          iVar1 = RhpInitialize(local_130);
          if (iVar1 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
            goto LAB_1c0026470;
            uVar4 = 0x12;
          }
          else {
            iVar1 = PlExtpInitialize(1,pppppppuVar2,local_130,plVar6);
            if (-1 < iVar1) {
              (**(code **)(WdfFunctions_01015 + 0xd8))(WdfDriverGlobals,local_130);
              return iVar1;
            }
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
            goto LAB_1c0026470;
            uVar4 = 0x13;
          }
          goto LAB_1c0026441;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0026470;
        uVar4 = 0x11;
      }
      goto LAB_1c00262ea;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0026470;
    uVar4 = 0xf;
LAB_1c0026441:
    uVar3 = 1;
  }
  WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pppppppuVar2,uVar3,uVar4,
                     &WPP_a781b87147d030366b419d92a3dc1ed1_Traceguids,"DriverEntry",(char)iVar1);
LAB_1c0026470:
  if (local_130 == 0) {
    if (local_138 != (undefined8 *******)0x0) {
      (**(code **)(WdfFunctions_01015 + 0x1b0))(WdfDriverGlobals);
      local_138 = (undefined8 *******)0x0;
    }
  }
  else {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
    local_130 = 0;
  }
  WppCleanupKm(param_1);
  return iVar1;
}



===== __security_init_cookie @ 1c002651c =====

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



===== PlExtpInitialize @ 1c0026550 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int PlExtpInitialize(int param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  undefined8 *puVar2;
  longlong lVar3;
  uint uVar4;
  undefined2 uVar5;
  undefined1 auStackY_138 [32];
  undefined8 local_f8;
  undefined8 local_f0;
  undefined4 local_e8;
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  undefined4 local_d8;
  undefined4 uStack_d4;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined *local_b8;
  undefined8 local_b0;
  code *pcStack_a8;
  ulonglong local_a0;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  ulonglong uStack_78;
  undefined8 local_70;
  ulonglong uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  char local_40 [24];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_138;
  local_b8 = (undefined *)((ulonglong)local_b8 & 0xffffffff00000000);
  local_70 = 0;
  uStack_68 = uStack_68 & 0xffffffff00000000;
  local_f0 = 0;
  local_f8 = 0;
  local_a0 = local_a0 & 0xffffffff00000000;
  local_40[0x10] = '\0';
  local_40[0x11] = '\0';
  local_40[0x12] = '\0';
  local_40[0x13] = '\0';
  local_40[0x14] = '\0';
  local_40[0x15] = '\0';
  local_40[0x16] = '\0';
  local_40[0x17] = '\0';
  local_e8 = 0;
  uStack_e4 = 0;
  uStack_e0 = 0;
  uStack_dc = 0;
  local_d8 = 0;
  uStack_d4 = 0;
  uStack_d0 = 0;
  local_c8 = 0;
  uStack_c0 = 0;
  local_90 = 0;
  uStack_88 = 0;
  local_80 = 0;
  uStack_78 = 0;
  local_b0 = 0;
  pcStack_a8 = (code *)0x0;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40[0] = '\0';
  local_40[1] = '\0';
  local_40[2] = '\0';
  local_40[3] = '\0';
  local_40[4] = '\0';
  local_40[5] = '\0';
  local_40[6] = '\0';
  local_40[7] = '\0';
  local_40[8] = '\0';
  local_40[9] = '\0';
  local_40[10] = '\0';
  local_40[0xb] = '\0';
  local_40[0xc] = '\0';
  local_40[0xd] = '\0';
  local_40[0xe] = '\0';
  local_40[0xf] = '\0';
  if (param_1 == 0) {
    local_60 = 0x38;
    local_40[0] = '\0';
    local_40[1] = '\0';
    local_40[2] = '\0';
    local_40[3] = '\0';
    local_40[4] = '\0';
    local_40[5] = '\0';
    local_40[6] = '\0';
    local_40[7] = '\0';
    local_50 = 0;
    uStack_48 = 0x1000000000;
    local_40[0x10] = '\x02';
    local_40[0x11] = '\0';
    local_40[0x12] = '\0';
    local_40[0x13] = '\0';
    local_40[0x14] = '\x02';
    local_40[0x15] = '\0';
    local_40[0x16] = '\0';
    local_40[0x17] = '\0';
    uStack_58 = 0xc800002000;
    RtlStringCbPrintfA(local_40,0x10,"PlExt Log",param_4);
    iVar1 = imp_WppRecorderLogCreate(WPP_GLOBAL_Control,&local_60,&PlExtLogHandle);
    if (-1 < iVar1) {
      _DAT_1c0016608 = &PlExtReadyRequestsList;
      PlExtReadyRequestsList = &PlExtReadyRequestsList;
      _DAT_1c0016618 = &PlExtActiveRequestsList;
      _PlExtActiveRequestsList = &PlExtActiveRequestsList;
      _DAT_1c0016628 = &PlExtPendingRequestsList;
      _PlExtPendingRequestsList = &PlExtPendingRequestsList;
      return iVar1;
    }
    goto LAB_1c0026971;
  }
  DAT_1c00165f8 = &PlExtAcpiDeviceList;
  PlExtAcpiDeviceList = &PlExtAcpiDeviceList;
  puVar2 = (undefined8 *)&local_e8;
  local_d8 = 0;
  uStack_d4 = 0;
  local_b8 = (undefined *)0x0;
  uStack_e4 = 0;
  uStack_e0 = 0;
  uStack_dc = 0;
  local_e8 = 0x38;
  uStack_c0 = 0;
  uStack_d0 = 0x100000001;
  local_c8 = param_3;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x9c0))
                    (WdfDriverGlobals,puVar2,&PlExtAcpiDeviceListLock);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0026971;
    uVar5 = 0xf;
  }
  else {
    puVar2 = (undefined8 *)0x40;
    PlExtRequestWorkItems = ExAllocatePool2(0x40,0x40,0x78466550);
    if (PlExtRequestWorkItems == 0) {
      iVar1 = -0x3fffff66;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0026971;
      uVar5 = 0x10;
      iVar1 = -0x3fffff66;
    }
    else {
      local_b8 = PTR__WDF_PLEXT_REQUEST_WORK_ITEM_CONTEXT_TYPE_INFO_1c00161b8;
      uVar4 = 0;
      uStack_d4 = 0;
      lVar3 = 0;
      uStack_c0 = 0;
      pcStack_a8 = PlExtRequestWorker;
      uStack_e4 = 0;
      uStack_e0 = 0;
      uStack_dc = 0;
      local_d8 = 0;
      local_e8 = 0x38;
      uStack_d0 = 0x100000001;
      local_b0 = 0x18;
      local_a0 = 0;
      local_c8 = param_3;
      do {
        puVar2 = &local_b0;
        iVar1 = (**(code **)(WdfFunctions_01015 + 0xbd8))
                          (WdfDriverGlobals,puVar2,&local_e8,&local_f8);
        if (iVar1 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_1c0026971;
          uVar5 = 0x11;
          goto LAB_1c0026953;
        }
        puVar2 = (undefined8 *)
                 (**(code **)(WdfFunctions_01015 + 0x650))
                           (WdfDriverGlobals,local_f8,
                            PTR__WDF_PLEXT_REQUEST_WORK_ITEM_CONTEXT_TYPE_INFO_1c00161b8);
        uVar4 = uVar4 + 1;
        *(undefined8 **)(lVar3 + PlExtRequestWorkItems) = puVar2;
        lVar3 = lVar3 + 8;
        *puVar2 = local_f8;
      } while (uVar4 < 8);
      KeInitializeEvent(&PlExtWorkerProcessQueueEvent,0,0);
      KeInitializeEvent(&PlExtWorkerTerminateEvent,0,0);
      PlExtWorkerRunning = 0;
      local_90 = CONCAT44(local_90._4_4_,0x30);
      puVar2 = (undefined8 *)0x1fffff;
      uStack_88 = 0;
      uStack_78 = uStack_78 & 0xffffffff00000000;
      local_80 = 0;
      local_70 = 0;
      uStack_68 = 0;
      iVar1 = PsCreateSystemThread(&local_f0,0x1fffff,&local_90,0);
      if (-1 < iVar1) {
        ObReferenceObjectByHandle(local_f0,0x1fffff,0,0);
        ZwClose(local_f0);
        iVar1 = PlExtpRegisterPowerInterfaces(param_3);
        if (-1 < iVar1) {
          return iVar1;
        }
        goto LAB_1c0026971;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0026971;
      uVar5 = 0x12;
    }
  }
LAB_1c0026953:
  WPP_RECORDER_SF_D(PlExtLogHandle,puVar2,2,uVar5,&WPP_014e28a2725035dd75100948d63f8491_Traceguids,
                    (char)iVar1);
LAB_1c0026971:
  if (PlExtRequestWorkItems != 0) {
    ExFreePoolWithTag(PlExtRequestWorkItems,0x78466550);
    PlExtRequestWorkItems = 0;
  }
  return iVar1;
}


