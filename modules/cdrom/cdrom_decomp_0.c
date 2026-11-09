
===== WPP_RECORDER_SF_DDDD @ 140001008 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_DDDD
               (undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,undefined8 param_5,
               undefined1 param_6,undefined1 param_7,undefined1 param_8,undefined1 param_9)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,4,&param_7,4,&param_8,4,&param_9,4,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,&param_6,4,&param_7,4,&param_8,4,&param_9,
                  4,0);
  return;
}



===== ScratchBuffer_EndUse @ 140001190 =====

longlong ScratchBuffer_EndUse(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  
  *(undefined8 *)(param_1 + 0x438) = 0;
  *(undefined4 *)(param_1 + 0x440) = 0;
  if (*(char *)(param_1 + 0x428) != '\0') {
    lVar1 = *(longlong *)(param_1 + 0x420);
    if ((*(byte *)(lVar1 + 10) & 0x20) != 0) {
      MmUnmapLockedPages(*(undefined8 *)(lVar1 + 0x18),lVar1);
    }
    *(undefined1 *)(param_1 + 0x428) = 0;
  }
  lVar2 = -1;
  LOCK();
  lVar1 = *(longlong *)(param_1 + 0x430);
  if (lVar1 == -1) {
    *(longlong *)(param_1 + 0x430) = 0;
  }
  else {
    lVar2 = lVar1;
  }
  UNLOCK();
  return lVar2;
}



===== ScratchBuffer_ReadWriteCompletionRoutine @ 140001200 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ScratchBuffer_ReadWriteCompletionRoutine
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  byte bVar1;
  undefined8 uVar2;
  longlong lVar3;
  undefined8 *puVar4;
  code *pcVar5;
  longlong lVar6;
  undefined1 uVar7;
  int iVar8;
  longlong lVar9;
  longlong lVar10;
  longlong lVar11;
  ulonglong uVar12;
  longlong lVar13;
  uint uVar14;
  int local_res20 [2];
  longlong local_48;
  longlong local_40;
  longlong local_38;
  
  local_res20[0] = 0;
  lVar9 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,*(undefined8 *)(param_4 + 0x400),
                     PTR__WDF_CDROM_REQUEST_CONTEXT_TYPE_INFO_14001a018);
  uVar2 = *(undefined8 *)(lVar9 + 8);
  lVar10 = (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,uVar2,PTR__WDF_CDROM_REQUEST_CONTEXT_TYPE_INFO_14001a018);
  local_38 = lVar10;
  lVar11 = (**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals,uVar2);
  lVar3 = *(longlong *)(lVar11 + 0xb8);
  lVar13 = *(longlong *)(*(longlong *)(param_4 + 0x38) + 0x18);
  local_40 = lVar11;
  iVar8 = (**(code **)(WdfFunctions_01015 + 0x7f0))(WdfDriverGlobals);
  if ((iVar8 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    uVar7 = (**(code **)(WdfFunctions_01015 + 0x7f0))(WdfDriverGlobals,param_1);
    WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,9,0x13,
                      &WPP_7774703dbdbe384c966e4c3ee8bb8942_Traceguids,uVar7);
  }
  puVar4 = *(undefined8 **)(param_4 + 0x408);
  if ((*(byte *)((longlong)puVar4 + 3) == 2) && (*(int *)(puVar4 + 8) == -0x3ffffee0))
  goto LAB_1400013fb;
  if ((*(byte *)((longlong)puVar4 + 3) & 0x3f) == 1) {
    *(longlong *)(param_4 + 0x458) =
         *(longlong *)(param_4 + 0x458) + (ulonglong)*(uint *)(puVar4 + 2);
    *(longlong *)(param_4 + 0x460) =
         *(longlong *)(param_4 + 0x460) + (ulonglong)*(uint *)(puVar4 + 2);
    *(int *)(param_4 + 0x44c) = *(int *)(param_4 + 0x44c) + *(int *)(puVar4 + 2);
    *(int *)(param_4 + 0x448) = *(int *)(param_4 + 0x448) + -1;
    if (*(longlong *)(param_4 + 0x470) != 0) {
      *(undefined8 *)(*(longlong *)(param_4 + 0x470) + 8) = _DAT_fffff78000000320;
      *(undefined1 *)(*(longlong *)(param_4 + 0x470) + 0x26) =
           *(undefined1 *)(*(longlong *)(param_4 + 0x408) + 3);
      bVar1 = *(byte *)(*(longlong *)(param_4 + 0x408) + 0xb);
      uVar14 = (uint)bVar1;
      if ((7 < bVar1) &&
         (uVar14 = *(byte *)(*(longlong *)(*(longlong *)(param_4 + 0x408) + 0x20) + 7) + 8,
         0x11 < uVar14)) {
        uVar14 = 0x12;
      }
      lVar9 = *(longlong *)(param_4 + 0x470);
      *(undefined8 *)(lVar9 + 0x14) = 0;
      *(undefined8 *)(lVar9 + 0x1c) = 0;
      *(undefined2 *)(lVar9 + 0x24) = 0;
      memmove((void *)(*(longlong *)(param_4 + 0x470) + 0x14),
              *(void **)(*(longlong *)(param_4 + 0x408) + 0x20),(ulonglong)uVar14);
    }
    if (*(int *)(param_4 + 0x448) == 0) goto LAB_1400013fb;
    local_res20[0] = ScratchBuffer_PerformNextReadWrite(param_4,'\x01');
  }
  else {
    local_48 = 0;
    uVar12 = RequestSenseInfoInterpret
                       (param_4,*(undefined8 *)(param_4 + 0x400),puVar4,*(uint *)(param_4 + 0x444),
                        (undefined **)local_res20,&local_48);
    lVar6 = local_48;
    if ((char)uVar12 == '\0') goto LAB_1400013fb;
    *(int *)(param_4 + 0x444) = *(int *)(param_4 + 0x444) + 1;
    if (local_48 != 0) {
      lVar11 = (**(code **)(WdfFunctions_01015 + 0x650))
                         (WdfDriverGlobals,uVar2,PTR__WDF_CDROM_REQUEST_CONTEXT_TYPE_INFO_14001a018)
      ;
      lVar10 = lVar11 + 0x50;
      local_48 = lVar10;
      if (*(char *)(lVar11 + 0xd1) == '\0') {
        KeInitializeSpinLock(lVar11 + 0x48);
        KeInitializeTimer(lVar10);
        KeInitializeDpc(lVar11 + 0x90,ScratchBuffer_ReadWriteTimerRoutine,uVar2);
        *(undefined1 *)(lVar11 + 0xd1) = 1;
      }
      uVar7 = KeAcquireSpinLockRaiseToDpc(lVar9 + 0x48);
      local_res20[0] =
           (**(code **)(WdfFunctions_01015 + 0xc48))
                     (WdfDriverGlobals,uVar2,ScratchBuffer_ReadWriteEvtRequestCancel);
      if (local_res20[0] != -0x3ffffee0) {
        (**(code **)(WdfFunctions_01015 + 0x668))
                  (WdfDriverGlobals,uVar2,0,0x2e6,"minkernel\\storage\\cdrom\\scratch.c");
        KeSetTimer(local_48,-lVar6,lVar11 + 0x90);
        KeReleaseSpinLock(lVar9 + 0x48,uVar7);
        return;
      }
      *(undefined1 *)(lVar9 + 0xd0) = 1;
      KeReleaseSpinLock(lVar9 + 0x48,uVar7);
      lVar10 = local_38;
      lVar11 = local_40;
      goto LAB_1400013fb;
    }
    local_res20[0] = ScratchBuffer_PerformNextReadWrite(param_4,'\0');
  }
  if (-1 < local_res20[0]) {
    return;
  }
LAB_1400013fb:
  ScratchBuffer_EndUse(param_4);
  pcVar5 = *(code **)(lVar13 + 0x10);
  if ((pcVar5 != (code *)0x0) && (*(longlong *)(lVar10 + 0x28) != 0)) {
    lVar13 = KeQueryPerformanceCounter(0);
    (*pcVar5)(*(undefined4 *)(lVar3 + 0x10),*(undefined4 *)(param_4 + 0x68),lVar11,
              lVar13 - *(longlong *)(lVar10 + 0x28));
  }
  RequestCompletion(param_4,uVar2,local_res20[0],(ulonglong)*(uint *)(param_4 + 0x44c));
  return;
}



===== SequentialQueueEvtIoReadWrite @ 1400016a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SequentialQueueEvtIoReadWrite(undefined8 param_1,longlong param_2,longlong param_3)

{
  bool bVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  undefined8 uVar5;
  longlong lVar6;
  undefined8 *puVar7;
  undefined2 uVar8;
  undefined1 auStackY_a8 [32];
  undefined8 in_stack_ffffffffffffff78;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStackY_a8;
  uVar5 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,uVar5,DAT_14001a0f0);
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals,param_2);
  puVar7 = &local_48;
  lVar4 = *(longlong *)(lVar4 + 0xb8);
  local_28 = 0;
  uStack_40 = 0;
  local_48 = 0x28;
  local_38 = 0;
  uStack_30 = 0;
  lVar6 = param_2;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals);
  if (local_48._4_4_ == 3) {
    if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
       (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) goto LAB_140001791;
    uVar8 = 0x53;
  }
  else {
    if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
       (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) goto LAB_140001791;
    uVar8 = 0x54;
  }
  WPP_RECORDER_SF_P(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar6,puVar7,uVar8,
                    in_stack_ffffffffffffff78,(char)param_3);
LAB_140001791:
  if ((((*(uint *)(*(longlong *)(lVar3 + 0x40) + 0x30) & 2) == 0) || (local_48._2_1_ == '4')) ||
     ((*(byte *)(lVar4 + 2) & 2) != 0)) {
    *(undefined1 *)(lVar4 + 1) = 0x34;
    if (*(char *)(lVar3 + 0x350) == '\0') {
      if ((*(longlong *)(lVar3 + 0x378) == 0) ||
         (lVar4 = (**(code **)(WdfFunctions_01015 + 0x8a8))(WdfDriverGlobals,param_2),
         *(longlong *)(lVar3 + 0x378) == lVar4)) {
        if (param_3 == 0) {
          iVar2 = 0;
        }
        else {
          if ((local_48._4_4_ == 4) && (*(char *)(lVar3 + 0x28b) == '\0')) {
            *(undefined4 *)(lVar3 + 0x290) = 1;
          }
          bVar1 = DeviceIsMmcUpdateRequired(*(undefined8 *)(lVar3 + 0x10));
          if (bVar1) {
            *(longlong *)(lVar3 + 0x488) = param_2;
            (**(code **)(WdfFunctions_01015 + 0xbe0))
                      (WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x480));
            return;
          }
          local_78 = local_48;
          uStack_70 = uStack_40;
          local_58 = local_28;
          local_68 = local_38;
          uStack_60 = uStack_30;
          uVar5 = RequestValidateReadWrite(lVar3,param_2,(longlong)&local_78);
          iVar2 = (int)uVar5;
          if (-1 < iVar2) {
            local_78 = local_48;
            uStack_70 = uStack_40;
            local_58 = local_28;
            local_68 = local_38;
            uStack_60 = uStack_30;
            uVar5 = RequestHandleReadWrite(lVar3,param_2,(longlong)&local_78);
            iVar2 = (int)uVar5;
            if (-1 < iVar2) {
              return;
            }
          }
        }
      }
      else {
        iVar2 = -0x3fffffde;
      }
    }
    else {
      iVar2 = -0x7fffffef;
    }
  }
  else {
    iVar2 = -0x7fffffea;
  }
  RequestCompletion(lVar3,param_2,iVar2,0);
  return;
}



===== RequestValidateReadWrite @ 1400019a4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 RequestValidateReadWrite(longlong param_1,undefined8 param_2,longlong param_3)

{
  char cVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  bool bVar4;
  byte bVar5;
  int iVar6;
  longlong lVar7;
  undefined2 uVar8;
  undefined8 uVar9;
  
  uVar9 = 0;
  bVar4 = true;
  lVar7 = (**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals);
  if ((((*(uint *)(*(longlong *)(param_1 + 0x40) + 0x30) & 2) != 0) &&
      (*(char *)(*(longlong *)(lVar7 + 0xb8) + 1) != '4')) &&
     ((*(byte *)(*(longlong *)(lVar7 + 0xb8) + 2) & 2) == 0)) {
    return 0x80000016;
  }
  if (*(char *)(param_1 + 0x350) != '\0') {
    return 0x80000011;
  }
  if ((*(longlong *)(param_1 + 0x378) != 0) &&
     (lVar7 = (**(code **)(WdfFunctions_01015 + 0x8a8))(WdfDriverGlobals,param_2),
     *(longlong *)(param_1 + 0x378) != lVar7)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0x37,
                       &WPP_7cea3eca420c34d4f6f4315c54c616a1_Traceguids);
    }
    return 0xc0000022;
  }
  iVar6 = *(int *)(param_1 + 0x9c);
  uVar2 = *(ulonglong *)(param_3 + 8);
  uVar3 = *(ulonglong *)(param_3 + 0x18);
  if (iVar6 == 0) {
    iVar6 = 0x800;
    *(undefined4 *)(param_1 + 0x9c) = 0x800;
  }
  bVar5 = *(byte *)(param_1 + 0xa0);
  if (bVar5 == 0) {
    bVar5 = 0xb;
    *(undefined1 *)(param_1 + 0xa0) = 0xb;
  }
  if ((uVar2 & iVar6 - 1) != 0 || (uVar3 & iVar6 - 1) != 0) {
    return 0xc0000010;
  }
  iVar6 = *(int *)(param_1 + 0x294);
  if (*(int *)(param_3 + 4) == 3) {
    if ((*(char *)(param_1 + 0x28b) != '\0') && (iVar6 == 0x21)) goto LAB_140001aae;
LAB_140001abc:
    if (*(char *)(param_1 + 0x28a) == '\0') {
      if ((*(longlong *)(param_1 + 0xa8) <= (longlong)uVar3) || ((longlong)uVar3 < 0)) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return 0xc0000010;
        }
        uVar8 = 0x39;
        goto LAB_140001baa;
      }
      if (*(longlong *)(param_1 + 0xa8) - uVar3 < uVar2) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return 0xc0000010;
        }
        uVar8 = 0x3a;
        goto LAB_140001baa;
      }
    }
  }
  else {
    if ((*(int *)(param_3 + 4) == 4) && (*(char *)(param_1 + 0x28b) == '\0')) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return 0xc0000010;
      }
      uVar8 = 0x38;
      goto LAB_140001baa;
    }
LAB_140001aae:
    if (iVar6 == 0x20) goto LAB_140001abc;
    if (iVar6 != 0x21) {
      if (iVar6 == 0x24) goto LAB_140001abc;
      if (iVar6 != 0x26) {
        if (iVar6 != 0x2c) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return 0xc0000010;
          }
          WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0x3d,
                            &WPP_7cea3eca420c34d4f6f4315c54c616a1_Traceguids,(char)iVar6);
          return 0xc0000010;
        }
        if ((uVar2 >> (bVar5 & 0x3f)) % (ulonglong)*(uint *)(param_1 + 0x298) != 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0x3b,
                              &WPP_7cea3eca420c34d4f6f4315c54c616a1_Traceguids,
                              (char)*(uint *)(param_1 + 0x298));
            bVar5 = *(byte *)(param_1 + 0xa0);
          }
          bVar4 = false;
        }
      }
      if ((uVar3 >> (bVar5 & 0x3f)) % (ulonglong)*(uint *)(param_1 + 0x298) != 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0x3c,
                            &WPP_7cea3eca420c34d4f6f4315c54c616a1_Traceguids,
                            (char)*(uint *)(param_1 + 0x298));
        }
        bVar4 = false;
      }
      if (!bVar4) {
        return 0xc0000010;
      }
    }
  }
  iVar6 = *(int *)(param_3 + 4);
  bVar5 = RequestGetCurrentStackLocationFlags(param_2);
  if ((bVar5 & 0x20) == 0) {
    lVar7 = (**(code **)(WdfFunctions_01015 + 0x8a8))(WdfDriverGlobals,param_2);
    if (lVar7 == 0) {
      return 0;
    }
    lVar7 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,lVar7,PTR__WDF_FILE_OBJECT_CONTEXT_TYPE_INFO_14001a090);
    if (iVar6 == 3) {
      cVar1 = *(char *)(lVar7 + 0x18);
    }
    else {
      cVar1 = *(char *)(lVar7 + 0x19);
    }
    if (cVar1 == '\0') {
      return 0;
    }
  }
  iVar6 = *(int *)(param_3 + 4);
  if (iVar6 == 3) {
    if (*(char *)(param_1 + 0x28d) != '\0') {
      return 0;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0x3e,
                       &WPP_7cea3eca420c34d4f6f4315c54c616a1_Traceguids);
      iVar6 = *(int *)(param_3 + 4);
    }
    uVar9 = 0xc0000010;
  }
  if (iVar6 != 4) {
    return uVar9;
  }
  if (*(char *)(param_1 + 0x28e) != '\0') {
    return uVar9;
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
    return 0xc0000010;
  }
  uVar8 = 0x3f;
LAB_140001baa:
  WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,uVar8,
                   &WPP_7cea3eca420c34d4f6f4315c54c616a1_Traceguids);
  return 0xc0000010;
}



===== RequestHandleReadWrite @ 140001e60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 RequestHandleReadWrite(longlong param_1,longlong param_2,longlong param_3)

{
  uint uVar1;
  int iVar2;
  longlong lVar3;
  code *pcVar4;
  longlong lVar5;
  longlong *plVar6;
  longlong *plVar7;
  undefined8 uVar8;
  longlong lVar9;
  uint uVar10;
  longlong lVar11;
  ulonglong uVar12;
  uint uVar13;
  
  lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 0x18);
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals);
  lVar3 = *(longlong *)(lVar5 + 0xb8);
  uVar12 = (ulonglong)*(uint *)(*(longlong *)(lVar5 + 8) + 0x2c) +
           *(longlong *)(*(longlong *)(lVar5 + 8) + 0x20);
  if (*(longlong *)(param_3 + 8) == 0) {
    RequestCompletion(param_1,param_2,0,0);
    uVar8 = 0;
  }
  else {
    lVar11 = *(longlong *)(param_1 + 0xb0) + *(longlong *)(lVar3 + 0x18);
    *(longlong *)(lVar3 + 0x18) = lVar11;
    *(longlong *)(param_3 + 0x18) = lVar11;
    uVar1 = *(uint *)(lVar3 + 8);
    if ((uVar12 & 0xfff) == 0) {
      uVar13 = *(uint *)(param_1 + 0x368);
    }
    else {
      uVar13 = *(uint *)(param_1 + 0x36c);
    }
    uVar10 = uVar1 / uVar13 + 1;
    if (uVar1 % uVar13 == 0) {
      uVar10 = uVar1 / uVar13;
    }
    plVar6 = (longlong *)
             (**(code **)(WdfFunctions_01015 + 0x650))
                       (WdfDriverGlobals,param_2,PTR__WDF_CDROM_REQUEST_CONTEXT_TYPE_INFO_14001a018)
    ;
    pcVar4 = *(code **)(lVar9 + 0x18);
    lVar9 = *(longlong *)(lVar9 + 0x10);
    if (pcVar4 != (code *)0x0) {
      (*pcVar4)(lVar5);
    }
    if (lVar9 != 0) {
      lVar9 = KeQueryPerformanceCounter(0);
      plVar6[5] = lVar9;
    }
    ScratchBuffer_BeginUseX(param_1);
    plVar7 = (longlong *)
             (**(code **)(WdfFunctions_01015 + 0x650))
                       (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x400),
                        PTR__WDF_CDROM_REQUEST_CONTEXT_TYPE_INFO_14001a018);
    iVar2 = *(int *)(param_3 + 4);
    *(uint *)(param_1 + 0x448) = uVar10;
    *(uint *)(param_1 + 0x450) = uVar1;
    *(uint *)(param_1 + 0x454) = uVar13;
    *(undefined8 *)(param_1 + 0x460) = *(undefined8 *)(lVar3 + 0x18);
    *(bool *)(param_1 + 0x468) = iVar2 == 3;
    *(ulonglong *)(param_1 + 0x458) = uVar12;
    *(undefined4 *)(param_1 + 0x44c) = 0;
    plVar7[1] = param_2;
    *plVar7 = param_1;
    *(undefined2 *)(plVar6 + 0x1a) = 0;
    *plVar6 = param_1;
    uVar8 = ScratchBuffer_PerformNextReadWrite(param_1,'\x01');
  }
  return uVar8;
}



===== DeviceIsMmcUpdateRequired @ 140002050 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

bool DeviceIsMmcUpdateRequired(undefined8 param_1)

{
  longlong lVar1;
  bool bVar2;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1,DAT_14001a0f0);
  if (*(char *)(lVar1 + 0x288) == '\0') {
    bVar2 = false;
  }
  else {
    bVar2 = *(int *)(lVar1 + 0x290) == 1;
  }
  return bVar2;
}



===== ScratchBuffer_BeginUseX @ 1400020a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ScratchBuffer_BeginUseX(longlong param_1)

{
  undefined8 *puVar1;
  int iVar2;
  longlong lVar3;
  undefined8 local_28;
  undefined4 local_20;
  undefined8 local_1c;
  undefined4 local_14;
  
  LOCK();
  if (*(longlong *)(param_1 + 0x430) == 0) {
    *(longlong *)(param_1 + 0x430) = -1;
  }
  UNLOCK();
  *(undefined8 *)(param_1 + 0x438) = 0;
  *(undefined4 *)(param_1 + 0x440) = 0xffffffff;
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals);
  puVar1 = *(undefined8 **)(param_1 + 0x418);
  memset(puVar1 + 5,0,(ulonglong)*(uint *)(puVar1 + 4) * 0x28);
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  puVar1[3] = 0;
  *(undefined4 *)((longlong)puVar1 + 0x24) = 0;
  if (*(longlong *)(lVar3 + 8) != 0) {
    *(undefined8 *)(lVar3 + 8) = 0;
  }
  local_1c = 0;
  local_14 = 0;
  local_28 = 0x18;
  local_20 = 0xc00000bb;
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x7c8))
                    (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x400),&local_28);
  if (-1 < iVar2) {
    (**(code **)(WdfFunctions_01015 + 0x820))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x400),0,0)
    ;
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x5f8))
                      (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x18),
                       *(undefined8 *)(param_1 + 0x400),0x1b0011,0,0,0,0,0,0);
    if ((iVar2 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x12,
                        &WPP_7774703dbdbe384c966e4c3ee8bb8942_Traceguids,(char)iVar2);
    }
  }
  puVar1 = *(undefined8 **)(param_1 + 0x410);
  *puVar1 = 0;
  puVar1[1] = 0;
  *(undefined2 *)(puVar1 + 2) = 0;
  memset(*(void **)(param_1 + 0x408),0,0x58);
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x400),
                     PTR__WDF_CDROM_REQUEST_CONTEXT_TYPE_INFO_14001a018);
  *(undefined8 *)(lVar3 + 0x18) = 0;
  *(undefined8 *)(lVar3 + 0x20) = 0;
  return;
}



===== ScratchBuffer_PerformNextReadWrite @ 1400022b4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ScratchBuffer_PerformNextReadWrite(longlong param_1,char param_2)

{
  undefined8 uVar1;
  longlong lVar2;
  uint uVar3;
  char cVar4;
  
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x400),
                     PTR__WDF_CDROM_REQUEST_CONTEXT_TYPE_INFO_14001a018);
  uVar3 = *(int *)(param_1 + 0x450) - *(int *)(param_1 + 0x44c);
  uVar1 = *(undefined8 *)(lVar2 + 8);
  if (*(uint *)(param_1 + 0x454) <= uVar3) {
    uVar3 = *(uint *)(param_1 + 0x454);
  }
  cVar4 = '\0';
  if (param_2 != '\0') {
    *(undefined4 *)(param_1 + 0x444) = 0;
  }
  ScratchBuffer_ResetItems(param_1,'\0');
  if ((1 < *(uint *)(param_1 + 0x448)) || (*(int *)(param_1 + 0x44c) != 0)) {
    cVar4 = '\x01';
  }
  ScratchBuffer_SetupReadWriteSrb
            (param_1,uVar1,*(ulonglong *)(param_1 + 0x460),uVar3,*(undefined8 *)(param_1 + 0x458),
             *(char *)(param_1 + 0x468),cVar4);
  (**(code **)(WdfFunctions_01015 + 0x820))
            (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x400),
             ScratchBuffer_ReadWriteCompletionRoutine,param_1);
  ScratchBuffer_SendSrb
            (param_1,'\0',(undefined8 *)(-(ulonglong)(param_2 != '\0') & param_1 + 0x470U));
  return;
}



===== ScratchBuffer_SendSrb @ 1400023f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 ScratchBuffer_SendSrb(longlong param_1,char param_2,undefined8 *param_3)

{
  longlong lVar1;
  longlong *plVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  char cVar5;
  undefined4 uVar6;
  longlong lVar7;
  longlong lVar8;
  undefined8 uVar9;
  uint uVar10;
  undefined *puVar11;
  longlong *plVar12;
  undefined1 auStackY_88 [32];
  undefined4 local_58;
  uint local_54;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_88;
  lVar1 = *(longlong *)(param_1 + 0x408);
  plVar2 = *(longlong **)(param_1 + 0x418);
  plVar12 = (longlong *)0x0;
  *(undefined4 *)(lVar1 + 0x40) = 0;
  *(undefined1 *)(lVar1 + 3) = 0;
  if ((param_2 != '\0') || (param_3 != (undefined8 *)0x0)) {
    if (*(int *)((longlong)plVar2 + 0x24) == (int)plVar2[4]) {
      CompressSrbHistoryData(plVar2);
    }
    uVar10 = *(uint *)((longlong)plVar2 + 0x24);
    *(uint *)((longlong)plVar2 + 0x24) = uVar10 + 1;
    plVar12 = plVar2 + ((ulonglong)uVar10 + 1) * 5;
    if (param_3 != (undefined8 *)0x0) {
      *param_3 = plVar12;
    }
    *plVar12 = 0;
    plVar12[1] = 0;
    plVar12[2] = 0;
    plVar12[3] = 0;
    plVar12[4] = 0;
    *plVar12 = _DAT_fffff78000000320;
  }
  uVar9 = WdfDriverGlobals;
  puVar11 = PTR__WDF_CDROM_REQUEST_CONTEXT_TYPE_INFO_14001a018;
  lVar7 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x400));
  if ((*(longlong *)(lVar7 + 8) == 0) ||
     (uVar9 = WdfDriverGlobals, cVar5 = (**(code **)(WdfFunctions_01015 + 0x808))(), cVar5 == '\0'))
  {
    uVar3 = *(undefined8 *)(param_1 + 0x400);
    uVar4 = *(undefined8 *)(param_1 + 0x18);
    if (((*(longlong *)(param_1 + 0x120) != 0) &&
        (*(char *)(*(longlong *)(param_1 + 0x120) + 0x51) != '\0')) &&
       ((Microsoft_Windows_CDROMEnableBits & 2) != 0)) {
      McTemplateK0_EtwWriteTransfer(uVar9,&ZeroPowerODDPowerOnStart,puVar11);
    }
    local_50 = 0;
    local_58 = 0x10;
    local_54 = -(uint)(param_2 != '\0') & 2;
    lVar8 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,uVar3,PTR__WDF_CDROM_REQUEST_CONTEXT_TYPE_INFO_14001a018);
    lVar7 = _DAT_fffff78000000320;
    if (*(longlong *)(lVar8 + 0x18) == 0) {
      *(longlong *)(lVar8 + 0x18) = _DAT_fffff78000000320;
    }
    *(longlong *)(lVar8 + 0x20) = lVar7;
    if (*(longlong *)(lVar8 + 8) != 0) {
      lVar8 = (**(code **)(WdfFunctions_01015 + 0x650))
                        (WdfDriverGlobals,*(longlong *)(lVar8 + 8),
                         PTR__WDF_CDROM_REQUEST_CONTEXT_TYPE_INFO_14001a018);
      if (*(longlong *)(lVar8 + 0x18) == 0) {
        *(longlong *)(lVar8 + 0x18) = lVar7;
      }
      *(longlong *)(lVar8 + 0x20) = lVar7;
    }
    cVar5 = (**(code **)(WdfFunctions_01015 + 0x7e8))(WdfDriverGlobals,uVar3,uVar4,&local_58);
    if ((cVar5 == '\0') || (param_2 != '\0')) {
      uVar6 = (**(code **)(WdfFunctions_01015 + 0x7f0))(WdfDriverGlobals,uVar3);
      if ((cVar5 == '\0') && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,1,0x68,
                          &WPP_8ec010589a13368bcaefd70a9b2ee310_Traceguids,(char)uVar6);
      }
      if (param_2 != '\0') {
        plVar12[1] = _DAT_fffff78000000320;
        *(undefined1 *)((longlong)plVar12 + 0x26) = *(undefined1 *)(lVar1 + 3);
        if (*(byte *)(lVar1 + 0xb) < 8) {
          uVar10 = (uint)*(byte *)(lVar1 + 0xb);
        }
        else {
          uVar10 = *(byte *)(*(longlong *)(lVar1 + 0x20) + 7) + 8;
          if (0x11 < uVar10) {
            uVar10 = 0x12;
          }
        }
        *(undefined8 *)((longlong)plVar12 + 0x14) = 0;
        *(undefined8 *)((longlong)plVar12 + 0x1c) = 0;
        *(undefined2 *)((longlong)plVar12 + 0x24) = 0;
        memmove((undefined8 *)((longlong)plVar12 + 0x14),*(void **)(lVar1 + 0x20),(ulonglong)uVar10)
        ;
      }
    }
    else {
      uVar6 = 0;
    }
  }
  else {
    *(undefined1 *)(*(longlong *)(param_1 + 0x408) + 3) = 2;
    *(undefined4 *)(*(longlong *)(param_1 + 0x408) + 0x40) = 0xc0000120;
    uVar6 = 0xc0000120;
  }
  return uVar6;
}



===== ScratchBuffer_ResetItems @ 140002730 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ScratchBuffer_ResetItems(longlong param_1,char param_2)

{
  undefined8 *puVar1;
  int iVar2;
  longlong lVar3;
  undefined8 local_28;
  undefined4 local_20;
  undefined8 local_1c;
  undefined4 local_14;
  
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals);
  if (param_2 != '\0') {
    puVar1 = *(undefined8 **)(param_1 + 0x418);
    memset(puVar1 + 5,0,(ulonglong)*(uint *)(puVar1 + 4) * 0x28);
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    *(undefined4 *)((longlong)puVar1 + 0x24) = 0;
  }
  if (*(longlong *)(lVar3 + 8) != 0) {
    *(undefined8 *)(lVar3 + 8) = 0;
  }
  local_1c = 0;
  local_14 = 0;
  local_28 = 0x18;
  local_20 = 0xc00000bb;
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x7c8))
                    (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x400),&local_28);
  if (-1 < iVar2) {
    (**(code **)(WdfFunctions_01015 + 0x820))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x400),0,0)
    ;
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x5f8))
                      (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x18),
                       *(undefined8 *)(param_1 + 0x400),0x1b0011,0,0,0,0,0,0);
    if ((iVar2 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x12,
                        &WPP_7774703dbdbe384c966e4c3ee8bb8942_Traceguids,(char)iVar2);
    }
  }
  puVar1 = *(undefined8 **)(param_1 + 0x410);
  *puVar1 = 0;
  puVar1[1] = 0;
  *(undefined2 *)(puVar1 + 2) = 0;
  puVar1 = *(undefined8 **)(param_1 + 0x408);
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  puVar1[3] = 0;
  puVar1[4] = 0;
  puVar1[5] = 0;
  puVar1[6] = 0;
  puVar1[7] = 0;
  puVar1[8] = 0;
  puVar1[9] = 0;
  puVar1[10] = 0;
  return;
}



===== ScratchBuffer_SetupReadWriteSrb @ 140002910 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ScratchBuffer_SetupReadWriteSrb
               (longlong param_1,undefined8 param_2,ulonglong param_3,uint param_4,
               undefined8 param_5,char param_6,char param_7)

{
  char cVar1;
  undefined4 *puVar2;
  byte bVar3;
  uint uVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  undefined8 uVar8;
  undefined1 uVar9;
  undefined1 uVar10;
  ulonglong uVar11;
  uint uVar12;
  undefined1 uStackX_9;
  undefined1 uStackX_a;
  undefined1 uStackX_b;
  undefined1 uStackX_21;
  undefined1 uStackX_22;
  undefined1 uStackX_23;
  
  puVar2 = *(undefined4 **)(param_1 + 0x408);
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals);
  lVar6 = (**(code **)(WdfFunctions_01015 + 0x8e8))
                    (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x400));
  lVar7 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x400),
                     PTR__WDF_CDROM_REQUEST_CONTEXT_TYPE_INFO_14001a018);
  *(undefined8 *)(lVar7 + 8) = param_2;
  lVar7 = *(longlong *)(lVar6 + 0xb8);
  uVar11 = param_3 >> (*(byte *)(param_1 + 0xa0) & 0x3f);
  uVar12 = param_4 >> (*(byte *)(param_1 + 0xa0) & 0x1f);
  *(undefined1 *)(lVar7 + -0x48) = 0xf;
  *(uint *)(lVar7 + -0x30) = 0x1b0012 - (uint)(param_6 != '\0');
  *(undefined4 **)(lVar7 + -0x40) = puVar2;
  *puVar2 = 0x58;
  *(undefined1 *)((longlong)puVar2 + 9) = 0x20;
  *(undefined1 *)(puVar2 + 1) = 0;
  *(undefined8 *)(puVar2 + 10) = 0;
  *(undefined1 *)((longlong)puVar2 + 0xb) = 0x12;
  *(undefined8 *)(puVar2 + 8) = *(undefined8 *)(param_1 + 0x410);
  *(undefined8 *)(puVar2 + 6) = param_5;
  puVar2[4] = param_4;
  puVar2[0x10] = (int)uVar11;
  if (0xffffffff < (longlong)uVar11) {
    puVar2[0x10] = 0xffffffff;
  }
  *(longlong *)(puVar2 + 0xc) = lVar6;
  puVar2[5] = *(undefined4 *)(param_1 + 0x78);
  bVar3 = RequestGetCurrentStackLocationFlags(param_2);
  uStackX_9 = (undefined1)(uVar11 >> 8);
  uStackX_a = (undefined1)(uVar11 >> 0x10);
  uStackX_b = (undefined1)(uVar11 >> 0x18);
  uStackX_21 = (undefined1)(uVar12 >> 8);
  if ((bVar3 & 0x20) == 0) {
    lVar7 = (**(code **)(WdfFunctions_01015 + 0x8a8))(WdfDriverGlobals,param_2);
    if (lVar7 != 0) {
      lVar7 = (**(code **)(WdfFunctions_01015 + 0x650))
                        (WdfDriverGlobals,lVar7,PTR__WDF_FILE_OBJECT_CONTEXT_TYPE_INFO_14001a090);
      if (param_6 == '\0') {
        cVar1 = *(char *)(lVar7 + 0x19);
      }
      else {
        cVar1 = *(char *)(lVar7 + 0x18);
      }
      if (cVar1 != '\0') goto LAB_140002a4c;
    }
  }
  else {
LAB_140002a4c:
    if ((*(byte *)(*(longlong *)(param_1 + 0x478) + 0x10) & 0x20) == 0) {
      *(undefined8 *)(puVar2 + 0x12) = 0;
      puVar2[0x14] = 0;
      *(undefined1 *)(puVar2 + 0x13) = uStackX_9;
      *(undefined1 *)((longlong)puVar2 + 0x4b) = uStackX_a;
      *(undefined1 *)((longlong)puVar2 + 0x4a) = uStackX_b;
      *(undefined1 *)(puVar2 + 0x14) = uStackX_21;
      uStackX_22 = (undefined1)(uVar12 >> 0x10);
      *(undefined1 *)((longlong)puVar2 + 0x4f) = uStackX_22;
      uStackX_23 = (undefined1)(uVar12 >> 0x18);
      *(undefined1 *)((longlong)puVar2 + 0x4e) = uStackX_23;
      *(char *)((longlong)puVar2 + 0x4d) = (char)uVar11;
      *(char *)((longlong)puVar2 + 0x51) = (char)uVar12;
      *(byte *)((longlong)puVar2 + 0x52) = *(byte *)((longlong)puVar2 + 0x52) | 0x80;
      if (param_6 == '\0') {
        uVar9 = 0xaa;
      }
      else {
        uVar9 = 0xa8;
      }
      uVar10 = 0xc;
      goto LAB_140002b18;
    }
  }
  *(undefined8 *)(puVar2 + 0x12) = 0;
  *(undefined2 *)(puVar2 + 0x14) = 0;
  uVar10 = 10;
  *(undefined1 *)((longlong)puVar2 + 0x4a) = uStackX_b;
  *(undefined1 *)((longlong)puVar2 + 0x4b) = uStackX_a;
  *(undefined1 *)(puVar2 + 0x13) = uStackX_9;
  *(undefined1 *)((longlong)puVar2 + 0x4f) = uStackX_21;
  uVar9 = 0x28;
  if (param_6 == '\0') {
    uVar9 = 0x2a;
  }
  *(char *)((longlong)puVar2 + 0x4d) = (char)uVar11;
  *(char *)(puVar2 + 0x14) = (char)uVar12;
LAB_140002b18:
  *(undefined1 *)(puVar2 + 0x12) = uVar9;
  *(undefined1 *)((longlong)puVar2 + 10) = uVar10;
  uVar12 = *(uint *)(param_1 + 0x74);
  puVar2[3] = uVar12;
  if ((*(uint *)(lVar5 + 0x10) & 0x42) != 0) {
    uVar12 = uVar12 | 0x40000000;
  }
  uVar4 = 0x40;
  if (param_6 == '\0') {
    uVar4 = 0x80;
  }
  puVar2[3] = uVar4 | uVar12 | 0x200;
  if (param_7 == '\0') {
    uVar8 = *(undefined8 *)(lVar5 + 8);
  }
  else {
    if ((*(char *)(param_1 + 0x428) != '\0') &&
       (lVar7 = *(longlong *)(param_1 + 0x420), (*(byte *)(lVar7 + 10) & 0x20) != 0)) {
      MmUnmapLockedPages(*(undefined8 *)(lVar7 + 0x18),lVar7,puVar2);
    }
    IoBuildPartialMdl(*(undefined8 *)(lVar5 + 8),*(undefined8 *)(param_1 + 0x420),
                      *(undefined8 *)(puVar2 + 6),puVar2[4]);
    uVar8 = *(undefined8 *)(param_1 + 0x420);
    *(undefined1 *)(param_1 + 0x428) = 1;
  }
  *(undefined8 *)(lVar6 + 8) = uVar8;
  *(longlong *)(puVar2 + 0xe) = lVar5;
  return;
}



===== RequestGetCurrentStackLocationFlags @ 140002c30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined1 RequestGetCurrentStackLocationFlags(undefined8 param_1)

{
  longlong lVar1;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals,param_1);
  return *(undefined1 *)(*(longlong *)(lVar1 + 0xb8) + 2);
}



===== WPP_RECORDER_SF_DDD @ 140002c70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_DDD(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
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
               &param_6,4,&param_7,4,&param_8,4,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,&param_6,4,&param_7,4,&param_8,4,0);
  return;
}



===== WPP_RECORDER_SF_L @ 140002de0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_L(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                      undefined8 param_5,undefined1 param_6)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,4,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,&param_6,4,0);
  return;
}



===== RequestCompletion @ 140002ef0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void RequestCompletion(longlong param_1,undefined8 param_2,int param_3,undefined8 param_4)

{
  longlong lVar1;
  undefined2 uVar2;
  undefined1 auStackY_a8 [32];
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_38 = 0;
  uStack_50 = 0;
  local_58 = 0x28;
  local_48 = 0;
  uStack_40 = 0;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_58);
  uVar4 = (undefined1)param_3;
  uVar5 = (undefined1)param_4;
  uVar3 = (undefined1)uStack_40;
  if (local_58._4_4_ == 0xe) {
    if ((int)uStack_40 == 0x7c0c8) {
      if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
         (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
        WPP_RECORDER_SF_DDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,100,
                            &WPP_8ec010589a13368bcaefd70a9b2ee310_Traceguids,uVar3,uVar4,uVar5);
      }
    }
    else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_DDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,99,
                          &WPP_8ec010589a13368bcaefd70a9b2ee310_Traceguids,uVar3,uVar4,uVar5);
    }
  }
  else {
    if (local_58._4_4_ == 3) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140002fc5;
      uVar2 = 0x65;
    }
    else {
      if ((local_58._4_4_ != 4) ||
         ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)) goto LAB_140002fc5;
      uVar2 = 0x66;
    }
    WPP_RECORDER_SF_DDDD
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,uVar2,
               &WPP_8ec010589a13368bcaefd70a9b2ee310_Traceguids,uVar3,(char)uStack_50,uVar5,uVar4);
  }
LAB_140002fc5:
  if (((((param_3 + 0x3fffff5eU < 2) || (param_3 + 0x3fffffeeU < 3)) || (param_3 == -0x7fffffea)) ||
      (param_3 == -0x3fffff4b)) &&
     (lVar1 = (**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals,param_2),
     *(longlong *)(lVar1 + 0x98) != 0)) {
    IoSetHardErrorOrVerifyDevice(lVar1,*(undefined8 *)(param_1 + 0x40));
  }
  if ((param_3 < 0) && (*(char *)(param_1 + 10) == '\x01')) {
    param_3 = -0x3fffff40;
  }
  (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,param_2,param_3,param_4);
  return;
}



===== RequestSetSentTime @ 140003170 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void RequestSetSentTime(undefined8 param_1)

{
  undefined8 uVar1;
  longlong lVar2;
  
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_CDROM_REQUEST_CONTEXT_TYPE_INFO_14001a018);
  uVar1 = _DAT_fffff78000000320;
  if (*(longlong *)(lVar2 + 0x18) == 0) {
    *(undefined8 *)(lVar2 + 0x18) = _DAT_fffff78000000320;
  }
  *(undefined8 *)(lVar2 + 0x20) = uVar1;
  if (*(longlong *)(lVar2 + 8) != 0) {
    lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,*(longlong *)(lVar2 + 8),
                       PTR__WDF_CDROM_REQUEST_CONTEXT_TYPE_INFO_14001a018);
    if (*(longlong *)(lVar2 + 0x18) == 0) {
      *(undefined8 *)(lVar2 + 0x18) = uVar1;
    }
    *(undefined8 *)(lVar2 + 0x20) = uVar1;
  }
  return;
}



===== RequestHandleUnknownIoctl @ 140003200 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int RequestHandleUnknownIoctl(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  undefined8 uVar2;
  char cVar3;
  int iVar4;
  longlong lVar5;
  longlong lVar6;
  undefined8 uVar7;
  int iVar8;
  code *pcVar9;
  undefined2 uVar10;
  undefined1 auStackY_c8 [32];
  undefined1 uVar11;
  undefined1 uVar12;
  undefined1 uVar13;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined4 local_50;
  int local_4c;
  undefined8 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_c8;
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1,DAT_14001a0f0);
  pcVar9 = (code *)PTR__WDF_CDROM_REQUEST_CONTEXT_TYPE_INFO_14001a018;
  lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_2);
  iVar4 = 0;
  iVar8 = 0;
  cVar1 = *(char *)(lVar6 + 0x34);
  uVar7 = WdfDriverGlobals;
  (**(code **)(WdfFunctions_01015 + 0x7d8))(WdfDriverGlobals,param_2);
  if (cVar1 == '\0') {
    pcVar9 = RequestDummyCompletionRoutine;
    uVar7 = WdfDriverGlobals;
    (**(code **)(WdfFunctions_01015 + 0x820))
              (WdfDriverGlobals,param_2,RequestDummyCompletionRoutine,0);
  }
  else {
    iVar8 = 2;
  }
  uVar2 = *(undefined8 *)(lVar5 + 0x18);
  if (((*(longlong *)(lVar5 + 0x120) != 0) &&
      (*(char *)(*(longlong *)(lVar5 + 0x120) + 0x51) != '\0')) &&
     ((Microsoft_Windows_CDROMEnableBits & 2) != 0)) {
    McTemplateK0_EtwWriteTransfer(uVar7,&ZeroPowerODDPowerOnStart,pcVar9);
  }
  local_48 = 0;
  local_50 = 0x10;
  local_4c = iVar8;
  RequestSetSentTime(param_2);
  cVar3 = (**(code **)(WdfFunctions_01015 + 0x7e8))(WdfDriverGlobals,param_2,uVar2,&local_50);
  if (((cVar3 != '\0') && (iVar8 == 0)) ||
     (iVar4 = (**(code **)(WdfFunctions_01015 + 0x7f0))(WdfDriverGlobals,param_2), cVar3 != '\0')) {
    if (cVar1 == '\0') {
      return iVar4;
    }
    uVar7 = (**(code **)(WdfFunctions_01015 + 0x8a0))(WdfDriverGlobals,param_2);
    uStack_70 = 0;
    local_78 = 0x28;
    local_68 = 0;
    uStack_60 = 0;
    local_58 = 0;
    (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_78);
    uVar11 = (undefined1)iVar4;
    uVar12 = (undefined1)uVar7;
    uVar13 = (undefined1)uStack_60;
    if (local_78._4_4_ == 0xe) {
      if ((int)uStack_60 == 0x7c0c8) {
        if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
           (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
          WPP_RECORDER_SF_DDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,100,
                              &WPP_8ec010589a13368bcaefd70a9b2ee310_Traceguids,uVar13,uVar11,uVar12)
          ;
        }
      }
      else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_DDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,99,
                            &WPP_8ec010589a13368bcaefd70a9b2ee310_Traceguids,uVar13,uVar11,uVar12);
      }
    }
    else if (local_78._4_4_ == 3) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar10 = 0x65;
        goto LAB_140003656;
      }
    }
    else if ((local_78._4_4_ == 4) &&
            ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      uVar10 = 0x66;
LAB_140003656:
      WPP_RECORDER_SF_DDDD
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,uVar10,
                 &WPP_8ec010589a13368bcaefd70a9b2ee310_Traceguids,uVar13,(char)uStack_70,uVar12,
                 uVar11);
    }
    if (((((iVar4 + 0x3fffff5eU < 2) || (iVar4 + 0x3fffffeeU < 3)) || (iVar4 == -0x7fffffea)) ||
        (iVar4 == -0x3fffff4b)) &&
       (lVar6 = (**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals,param_2),
       *(longlong *)(lVar6 + 0x98) != 0)) {
      IoSetHardErrorOrVerifyDevice(lVar6,*(undefined8 *)(lVar5 + 0x40));
    }
    iVar8 = iVar4;
    if ((iVar4 < 0) && (*(char *)(lVar5 + 10) == '\x01')) {
      iVar8 = -0x3fffff40;
    }
    pcVar9 = *(code **)(WdfFunctions_01015 + 0x848);
    goto LAB_1400034e0;
  }
  uVar13 = (undefined1)iVar4;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,1,0x68,
                      &WPP_8ec010589a13368bcaefd70a9b2ee310_Traceguids,uVar13);
  }
  uVar7 = (**(code **)(WdfFunctions_01015 + 0x8a0))(WdfDriverGlobals,param_2);
  uStack_70 = 0;
  local_78 = 0x28;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_78);
  uVar11 = (undefined1)uStack_60;
  uVar12 = (undefined1)uVar7;
  if (local_78._4_4_ == 0xe) {
    if ((int)uStack_60 == 0x7c0c8) {
      if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
         (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
        WPP_RECORDER_SF_DDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,100,
                            &WPP_8ec010589a13368bcaefd70a9b2ee310_Traceguids,uVar11,uVar13,uVar12);
      }
    }
    else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_DDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,99,
                          &WPP_8ec010589a13368bcaefd70a9b2ee310_Traceguids,uVar11,uVar13,uVar12);
    }
  }
  else if (local_78._4_4_ == 3) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar10 = 0x65;
      goto LAB_140003602;
    }
  }
  else if ((local_78._4_4_ == 4) &&
          ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    uVar10 = 0x66;
LAB_140003602:
    WPP_RECORDER_SF_DDDD
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,uVar10,
               &WPP_8ec010589a13368bcaefd70a9b2ee310_Traceguids,uVar11,(char)uStack_70,uVar12,uVar13
              );
  }
  if (((((iVar4 + 0x3fffff5eU < 2) || (iVar4 + 0x3fffffeeU < 3)) || (iVar4 == -0x7fffffea)) ||
      (iVar4 == -0x3fffff4b)) &&
     (lVar6 = (**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals,param_2),
     *(longlong *)(lVar6 + 0x98) != 0)) {
    IoSetHardErrorOrVerifyDevice(lVar6,*(undefined8 *)(lVar5 + 0x40));
  }
  iVar8 = iVar4;
  if ((iVar4 < 0) && (*(char *)(lVar5 + 10) == '\x01')) {
    iVar8 = -0x3fffff40;
  }
  pcVar9 = *(code **)(WdfFunctions_01015 + 0x848);
LAB_1400034e0:
  (*pcVar9)(WdfDriverGlobals,param_2,iVar8,uVar7);
  return iVar4;
}



===== RequestSynchronizeProcessWithSerialQueue @ 140003880 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int RequestSynchronizeProcessWithSerialQueue(undefined8 param_1,undefined8 param_2)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  undefined8 uVar8;
  undefined2 uVar9;
  longlong lVar10;
  undefined1 auStackY_d8 [32];
  undefined8 uVar11;
  undefined1 uVar12;
  char local_88 [16];
  longlong local_78;
  longlong local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_d8;
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1,DAT_14001a0f0);
  local_78 = lVar5;
  lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_CDROM_REQUEST_CONTEXT_TYPE_INFO_14001a018);
  lVar10 = *(longlong *)(lVar6 + 0x38);
  local_70 = lVar10;
  bVar1 = KeGetCurrentIrql();
  if (bVar1 < 2) {
    KeInitializeEvent(*(undefined8 *)(lVar6 + 0x38),0,0);
    iVar4 = (**(code **)(WdfFunctions_01015 + 0x2d8))(WdfDriverGlobals,param_1,param_2);
    if (iVar4 < 0) {
      KeSetEvent(*(undefined8 *)(lVar6 + 0x38),1);
      uVar8 = (**(code **)(WdfFunctions_01015 + 0x8a0))(WdfDriverGlobals,param_2);
      RequestCompletion(lVar5,param_2,iVar4,uVar8);
    }
    else {
      uVar8 = (**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals,param_2);
LAB_140003993:
      uVar11 = 0;
      iVar3 = KeWaitForSingleObject(*(undefined8 *)(lVar6 + 0x38),0,0);
      if (iVar3 != 0) {
        if (iVar3 != 0x101) goto code_r0x000140003ca2;
        cVar2 = PsIsThreadTerminating(SystemReserved1[0xf]);
        if (cVar2 == '\0') {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar9 = 0x5a;
            bVar1 = 3;
            iVar3 = iVar4;
            goto LAB_140003cc9;
          }
          goto LAB_140003993;
        }
        cVar2 = IoCancelIrp(uVar8);
        if (cVar2 == '\0') {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_140003993;
          uVar9 = 0x59;
        }
        else {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_140003993;
          uVar9 = 0x58;
        }
        WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,5,uVar9,
                           &WPP_d2ddb5c132d1335dbff1b624de01ec23_Traceguids,(char)param_2,
                           (char)param_1);
        goto LAB_140003993;
      }
      cVar2 = (**(code **)(WdfFunctions_01015 + 0x808))(WdfDriverGlobals,param_2);
      lVar10 = local_70;
      lVar5 = local_78;
      if (cVar2 == '\0') {
        if ((*(longlong *)(local_78 + 0x378) != 0) &&
           (lVar7 = (**(code **)(WdfFunctions_01015 + 0x8a8))(WdfDriverGlobals,param_2),
           *(longlong *)(lVar5 + 0x378) != lVar7)) {
          local_88[0] = '\0';
          local_48 = 0;
          uStack_60 = 0;
          local_68 = 0x28;
          local_58 = 0;
          uStack_50 = 0;
          (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_68);
          iVar4 = RequestIsIoctlBlockedByExclusiveAccess(param_2,local_88);
          if (local_88[0] != '\0') {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x5b,
                                &WPP_d2ddb5c132d1335dbff1b624de01ec23_Traceguids,(char)uStack_50);
            }
            RequestCompletion(lVar5,param_2,-0x3fffffde,0);
            goto LAB_140003a05;
          }
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x5c,
                              &WPP_d2ddb5c132d1335dbff1b624de01ec23_Traceguids,(char)uStack_50);
          }
        }
        iVar4 = (**(code **)(lVar6 + 0x40))(param_1,param_2);
      }
      else {
        iVar4 = -0x3ffffee0;
        RequestCompletion(local_78,param_2,-0x3ffffee0,0);
      }
    }
LAB_140003a05:
    if (lVar10 == 0) {
      return iVar4;
    }
    ExFreePoolWithTag(lVar10,0);
    return iVar4;
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x56,
                     &WPP_d2ddb5c132d1335dbff1b624de01ec23_Traceguids);
  }
  local_48 = 0;
  uStack_60 = 0;
  local_68 = 0x28;
  local_58 = 0;
  uStack_50 = 0;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_68);
  uVar12 = (undefined1)uStack_50;
  if (local_68._4_4_ == 0xe) {
    if ((int)uStack_50 == 0x7c0c8) {
      if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
         (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
        WPP_RECORDER_SF_DDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,100,
                            &WPP_8ec010589a13368bcaefd70a9b2ee310_Traceguids,uVar12,0x48,0);
      }
    }
    else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_DDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,99,
                          &WPP_8ec010589a13368bcaefd70a9b2ee310_Traceguids,uVar12,0x48,0);
    }
  }
  else {
    if (local_68._4_4_ == 3) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140003a39;
      uVar9 = 0x65;
    }
    else {
      if ((local_68._4_4_ != 4) ||
         ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)) goto LAB_140003a39;
      uVar9 = 0x66;
    }
    WPP_RECORDER_SF_DDDD
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,uVar9,
               &WPP_8ec010589a13368bcaefd70a9b2ee310_Traceguids,uVar12,(char)uStack_60,0,0x48);
  }
LAB_140003a39:
  uVar8 = 0xc00000c0;
  if (*(char *)(lVar5 + 10) != '\x01') {
    uVar8 = 0xc0000148;
  }
  (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,param_2,uVar8,0);
  return -0x3ffffeb8;
code_r0x000140003ca2:
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    uVar9 = 0x57;
    bVar1 = 1;
LAB_140003cc9:
    WPP_RECORDER_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),bVar1,5,uVar9,uVar11,
                        (char)param_2,(char)param_1,(char)iVar3);
  }
  goto LAB_140003993;
}



===== DeviceEvtIoInCallerContext @ 140003ed0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DeviceEvtIoInCallerContext(undefined8 param_1,longlong param_2)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  longlong lVar4;
  longlong *plVar5;
  longlong lVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  longlong lVar9;
  byte bVar10;
  uint uVar11;
  undefined2 uVar12;
  undefined1 auStackY_118 [32];
  undefined1 uVar13;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  uint uStack_b0;
  undefined4 uStack_ac;
  undefined8 local_a8;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  uint uStack_78;
  undefined4 uStack_74;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_118;
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1,DAT_14001a0f0);
  plVar5 = (longlong *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_2,PTR__WDF_CDROM_REQUEST_CONTEXT_TYPE_INFO_14001a018);
  *plVar5 = lVar4;
  lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_CDROM_REQUEST_CONTEXT_TYPE_INFO_14001a018);
  *(undefined8 *)(lVar6 + 0x10) = _DAT_fffff78000000320;
  local_70 = 0;
  uStack_88 = 0;
  local_90 = 0x28;
  local_80 = 0;
  uStack_78 = 0;
  uStack_74 = 0;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_90);
  if (local_90._4_4_ != 0xe) {
    if (local_90._4_4_ == 0xf) {
      RequestProcessInternalDeviceControl(param_2,lVar4);
      return;
    }
    iVar3 = (**(code **)(WdfFunctions_01015 + 0x2d8))(WdfDriverGlobals,param_1,param_2);
    if (iVar3 < 0) {
      uVar8 = (**(code **)(WdfFunctions_01015 + 0x8a0))(WdfDriverGlobals,param_2);
      RequestCompletion(lVar4,param_2,iVar3,uVar8);
      return;
    }
    return;
  }
  pcVar1 = *(char **)(lVar4 + 0x118);
  if (uStack_78 == 0x7c0c8) {
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      uVar8 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
      bVar10 = 5;
      uVar11 = 0x7c0c8;
      uVar12 = 0x2a;
      goto LAB_1400044d2;
    }
  }
  else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    uVar12 = 0x29;
    bVar10 = 4;
    uVar8 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
    uVar11 = uStack_78;
LAB_1400044d2:
    WPP_RECORDER_SF_L(uVar8,bVar10,5,uVar12,&WPP_d2ddb5c132d1335dbff1b624de01ec23_Traceguids,
                      (char)uVar11);
  }
  if ((*(longlong *)(lVar4 + 0x378) != 0) &&
     (lVar6 = (**(code **)(WdfFunctions_01015 + 0x8a8))(WdfDriverGlobals,param_2),
     *(longlong *)(lVar4 + 0x378) != lVar6)) {
    local_48 = 0;
    uStack_60 = 0;
    local_68 = 0x28;
    local_58 = 0;
    uStack_50 = 0;
    (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_68);
    if (local_68._4_4_ - 0xeU < 2) {
      if ((((((uint)uStack_50 != 0x41018) && ((uint)uStack_50 != 0x2d0c14)) &&
           ((uint)uStack_50 != 0x2d1080)) &&
          (((uint)uStack_50 != 0x2d0c04 && ((uint)uStack_50 != 0x2c05c)))) &&
         ((uint)uStack_50 != 0x24064)) {
        if ((uint)uStack_50 == 0x2d1400) {
          local_98 = 0;
          (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_2,local_58);
        }
        else if (((uint)uStack_50 >> 0x10 < 0x34) &&
                ((0x8200000000094U >> ((ulonglong)((uint)uStack_50 >> 0x10) & 0x3f) & 1) != 0)) {
          if ((uStack_78 == 0x2d1c90) && ((pcVar1 != (char *)0x0 && (*pcVar1 != '\0')))) {
            pcVar1[1] = '\x01';
          }
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x2b,
                              &WPP_d2ddb5c132d1335dbff1b624de01ec23_Traceguids,(char)uStack_78);
          }
          local_48 = 0;
          uStack_60 = 0;
          local_68 = 0x28;
          local_58 = 0;
          uStack_50 = 0;
          (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_68);
          uVar13 = (undefined1)uStack_50;
          if (local_68._4_4_ == 0xe) {
            if ((uint)uStack_50 == 0x7c0c8) {
              if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
                 (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
                WPP_RECORDER_SF_DDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,100,
                                    &WPP_8ec010589a13368bcaefd70a9b2ee310_Traceguids,uVar13,0x22,0);
              }
            }
            else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_DDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,99,
                                  &WPP_8ec010589a13368bcaefd70a9b2ee310_Traceguids,uVar13,0x22,0);
            }
          }
          else {
            if (local_68._4_4_ == 3) {
              if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
              goto LAB_1400041d8;
              uVar12 = 0x65;
            }
            else {
              if ((local_68._4_4_ != 4) ||
                 ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED))
              goto LAB_1400041d8;
              uVar12 = 0x66;
            }
            WPP_RECORDER_SF_DDDD
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,uVar12,
                       &WPP_8ec010589a13368bcaefd70a9b2ee310_Traceguids,uVar13,(char)uStack_60,0,
                       0x22);
          }
LAB_1400041d8:
          uVar8 = 0xc00000c0;
          if (*(char *)(lVar4 + 10) != '\x01') {
            uVar8 = 0xc0000022;
          }
          (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,param_2,uVar8,0);
          return;
        }
      }
    }
  }
  if ((((uStack_78 >> 0x10 < 0x34) &&
       ((0x8000080000094U >> ((ulonglong)(uStack_78 >> 0x10) & 0x3f) & 1) != 0)) &&
      (0x7ff < (uStack_78 & 0x3ffc))) && ((uStack_78 & 0x3ffc) < 0xc01)) {
    uVar11 = uStack_78 & 0xffff;
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x28,
                        &WPP_d2ddb5c132d1335dbff1b624de01ec23_Traceguids,(char)uVar11);
    }
    uStack_78 = uVar11 | 0x2d0000;
  }
  local_c8 = local_90;
  uStack_c0 = uStack_88;
  local_a8 = local_70;
  local_b8 = local_80;
  uStack_b0 = uStack_78;
  uStack_ac = uStack_74;
  uVar7 = RequestDispatchProcessDirectly(param_1,param_2,&local_c8);
  if ((char)uVar7 == '\0') {
    local_c8 = local_90;
    uStack_c0 = uStack_88;
    local_a8 = local_70;
    local_b8 = local_80;
    uStack_b0 = uStack_78;
    uStack_ac = uStack_74;
    uVar7 = RequestDispatchToSequentialQueue(param_1,param_2,&local_c8);
    if ((char)uVar7 == '\0') {
      local_c8 = local_90;
      uStack_c0 = uStack_88;
      local_a8 = local_70;
      local_b8 = local_80;
      uStack_b0 = uStack_78;
      uStack_ac = uStack_74;
      uVar8 = RequestDispatchSyncWithSequentialQueue(param_1,param_2,&local_c8);
      if ((char)uVar8 == '\0') {
        local_c8 = local_90;
        uStack_c0 = uStack_88;
        local_a8 = local_70;
        local_b8 = local_80;
        uStack_b0 = uStack_78;
        uStack_ac = uStack_74;
        uVar8 = RequestDispatchSpecialIoctls(param_1,param_2,&local_c8);
        if ((char)uVar8 == '\0') {
          local_b8 = local_80;
          _uStack_b0 = CONCAT44(uStack_74,uStack_78);
          lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1,DAT_14001a0f0);
          cVar2 = KeGetCurrentIrql();
          if ((cVar2 == '\0') && ((uStack_b0 & 0xffff0000) != 0x320000)) {
            lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))
                              (WdfDriverGlobals,param_2,
                               PTR__WDF_CDROM_REQUEST_CONTEXT_TYPE_INFO_14001a018);
            lVar9 = ExAllocatePool2(0x40,0x18,0x65436353);
            if (lVar9 == 0) {
              RequestCompletion(lVar4,param_2,-0x3fffff66,0);
            }
            else {
              *(longlong *)(lVar6 + 0x38) = lVar9;
              *(undefined1 *)(lVar6 + 0x34) = 1;
              *(code **)(lVar6 + 0x40) = RequestHandleUnknownIoctl;
              RequestSynchronizeProcessWithSerialQueue(param_1,param_2);
            }
          }
          else {
            RequestHandleUnknownIoctl(param_1,param_2);
          }
        }
      }
    }
  }
  return;
}



===== RequestDispatchProcessDirectly @ 140004660 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong RequestDispatchProcessDirectly(undefined8 param_1,longlong param_2,undefined8 *param_3)

{
  ushort uVar1;
  ushort *puVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  longlong lVar6;
  longlong lVar7;
  undefined8 uVar8;
  ulonglong uVar9;
  ushort *puVar10;
  undefined2 uVar11;
  undefined1 auStackY_e8 [32];
  undefined1 uVar12;
  undefined1 uVar13;
  undefined1 uVar14;
  ushort *local_98;
  undefined8 local_90;
  ushort *local_88;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_e8;
  iVar5 = 0;
  puVar10 = (ushort *)0x0;
  local_98 = (ushort *)0x0;
  local_90 = param_1;
  lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1,DAT_14001a0f0);
  uVar4 = *(uint *)(param_3 + 3);
  if (uVar4 == 0x4d0008) {
    local_68 = param_3[2];
    uStack_60 = param_3[3];
    uVar9 = param_3[1];
    local_58 = param_3[4];
    local_98 = (ushort *)0x0;
    if (uVar9 < 4) {
      puVar10 = (ushort *)0x4;
      iVar5 = -0x3fffffdd;
    }
    else {
      iVar5 = (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,param_2,uVar9,&local_98);
      if (-1 < iVar5) {
        memset(local_98,0,uVar9);
        uVar1 = *(ushort *)(lVar6 + 0x58);
        *local_98 = uVar1;
        if (uVar9 < (ulonglong)*(ushort *)(lVar6 + 0x58) + 2) {
          puVar10 = (ushort *)0x4;
          iVar5 = -0x7ffffffb;
        }
        else {
          memmove(local_98 + 1,*(void **)(lVar6 + 0x60),(ulonglong)uVar1);
          iVar5 = 0;
          puVar10 = (ushort *)((ulonglong)*local_98 + 2);
        }
      }
    }
    goto LAB_1400047da;
  }
  if (uVar4 < 0x2d1c91) {
    if (uVar4 == 0x2d1c90) {
      iVar5 = RequestHandleEventNotification(lVar6,param_2,(longlong)param_3,&local_98);
      puVar10 = local_98;
    }
    else {
      if (uVar4 == 0x24064) {
        local_68 = param_3[2];
        uStack_60 = param_3[3];
        puVar2 = (ushort *)param_3[1];
        local_58 = param_3[4];
        if (puVar2 == (ushort *)0x0) {
          iVar5 = -0x3fffffdd;
        }
        else {
          local_98 = (ushort *)0x0;
          if ((ushort *)(ulonglong)*(uint *)(lVar6 + 0x3e0) < puVar2) {
            local_88 = (ushort *)(ulonglong)*(uint *)(lVar6 + 0x3e0);
          }
          else {
            local_88 = puVar2;
          }
          puVar10 = local_88;
          iVar5 = (**(code **)(WdfFunctions_01015 + 0x870))
                            (WdfDriverGlobals,param_2,puVar2,&local_98);
          if ((-1 < iVar5) && (local_98 != (ushort *)0x0)) {
            memmove(local_98,*(void **)(lVar6 + 0x3d8),(size_t)local_88);
          }
          if (puVar2 < (ushort *)(ulonglong)*(uint *)(lVar6 + 0x3e0)) {
            iVar5 = -0x7ffffffb;
          }
        }
      }
      else {
        if (uVar4 == 0x2d0c04) {
          uVar8 = RequestHandleGetMediaTypeEx(lVar6,param_2,(size_t *)&local_98);
          iVar5 = (int)uVar8;
          puVar10 = local_98;
          goto LAB_1400047e1;
        }
        uVar4 = uVar4 - 0x2d0c14;
        if (uVar4 == 0) {
          local_68 = param_3[2];
          uStack_60 = param_3[3];
          local_58 = param_3[4];
          if ((ulonglong)param_3[1] < 8) {
            iVar5 = -0x3fffffdd;
          }
          else {
            local_98 = (ushort *)0x0;
            iVar5 = (**(code **)(WdfFunctions_01015 + 0x870))
                              (WdfDriverGlobals,param_2,param_3[1],&local_98);
            if (iVar5 < 0) goto LAB_1400047da;
            iVar5 = 0;
            *(undefined8 *)local_98 = *(undefined8 *)(*(longlong *)(lVar6 + 0x478) + 0x18);
          }
          puVar10 = (ushort *)0x8;
        }
        else {
          if (uVar4 != 0x46c) goto LAB_14000470c;
          local_68 = param_3[2];
          uStack_60 = param_3[3];
          local_58 = param_3[4];
          if ((ulonglong)param_3[1] < 0xc) {
            iVar5 = -0x3fffffdd;
          }
          else {
            local_98 = (ushort *)0x0;
            iVar5 = (**(code **)(WdfFunctions_01015 + 0x870))
                              (WdfDriverGlobals,param_2,param_3[1],&local_98);
            if (iVar5 < 0) goto LAB_1400047da;
            iVar5 = 0;
            *(undefined4 *)local_98 = *(undefined4 *)(*(longlong *)(lVar6 + 0x40) + 0x48);
            *(undefined4 *)(local_98 + 2) = *(undefined4 *)(lVar6 + 0x68);
            local_98[4] = 0xffff;
            local_98[5] = 0xffff;
          }
          puVar10 = (ushort *)0xc;
        }
      }
LAB_1400047da:
      param_1 = local_90;
    }
LAB_1400047e1:
    uVar9 = 1;
  }
  else {
    if (uVar4 == 0x2dcc18) {
      local_78 = *param_3;
      uStack_70 = param_3[1];
      local_68 = param_3[2];
      uStack_60 = param_3[3];
      local_58 = param_3[4];
      iVar5 = RequestHandleSetHotPlugInfo(lVar6,param_2,(longlong)&local_78,&local_98);
      puVar10 = local_98;
      goto LAB_1400047e1;
    }
    if (uVar4 == 0x4d0000) {
      local_78 = *param_3;
      uStack_70 = param_3[1];
      local_68 = param_3[2];
      uStack_60 = param_3[3];
      local_58 = param_3[4];
      uVar8 = RequestHandleMountQueryUniqueId
                        (lVar6,param_2,(longlong)&local_78,(longlong *)&local_98);
      iVar5 = (int)uVar8;
      puVar10 = local_98;
      goto LAB_1400047e1;
    }
    uVar4 = uVar4 - 0x4d000c;
    if (uVar4 == 0) {
      local_78 = *param_3;
      uStack_70 = param_3[1];
      local_68 = param_3[2];
      uStack_60 = param_3[3];
      local_58 = param_3[4];
      iVar5 = RequestHandleMountQuerySuggestedLinkName(lVar6,param_2,(longlong)&local_78,&local_98);
      puVar10 = local_98;
      goto LAB_1400047e1;
    }
    if (uVar4 != 0x9bffc) {
LAB_14000470c:
      return (ulonglong)uVar4 & 0xffffffffffffff00;
    }
    cVar3 = (**(code **)(WdfFunctions_01015 + 0x8c0))(WdfDriverGlobals,param_2);
    uVar9 = (ulonglong)(cVar3 == '\0');
    if (cVar3 != '\0') {
      return uVar9;
    }
  }
  lVar7 = (**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals,param_2);
  if ((iVar5 == -0x7fffffea) && ((*(byte *)(*(longlong *)(lVar7 + 0xb8) + 2) & 2) != 0)) {
    local_78 = *param_3;
    uStack_70 = param_3[1];
    local_68 = param_3[2];
    uStack_60 = param_3[3];
    local_58 = param_3[4];
    uVar9 = RequestDispatchProcessDirectly(param_1,param_2,&local_78);
    return uVar9;
  }
  local_58 = 0;
  uStack_70 = 0;
  local_78 = 0x28;
  local_68 = 0;
  uStack_60 = 0;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_78);
  uVar13 = (undefined1)iVar5;
  uVar14 = SUB81(puVar10,0);
  uVar12 = (undefined1)uStack_60;
  if (local_78._4_4_ == 0xe) {
    if ((int)uStack_60 == 0x7c0c8) {
      if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
         (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
        WPP_RECORDER_SF_DDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,100,
                            &WPP_8ec010589a13368bcaefd70a9b2ee310_Traceguids,uVar12,uVar13,uVar14);
      }
    }
    else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_DDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,99,
                          &WPP_8ec010589a13368bcaefd70a9b2ee310_Traceguids,uVar12,uVar13,uVar14);
    }
  }
  else {
    if (local_78._4_4_ == 3) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400048b6;
      uVar11 = 0x65;
    }
    else {
      if ((local_78._4_4_ != 4) ||
         ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)) goto LAB_1400048b6;
      uVar11 = 0x66;
    }
    WPP_RECORDER_SF_DDDD
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,uVar11,
               &WPP_8ec010589a13368bcaefd70a9b2ee310_Traceguids,uVar12,(char)uStack_70,uVar14,uVar13
              );
  }
LAB_1400048b6:
  if (((((iVar5 + 0x3fffff5eU < 2) || (iVar5 + 0x3fffffeeU < 3)) || (iVar5 == -0x7fffffea)) ||
      (iVar5 == -0x3fffff4b)) &&
     (lVar7 = (**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals,param_2),
     *(longlong *)(lVar7 + 0x98) != 0)) {
    IoSetHardErrorOrVerifyDevice(lVar7,*(undefined8 *)(lVar6 + 0x40));
  }
  if ((iVar5 < 0) && (*(char *)(lVar6 + 10) == '\x01')) {
    iVar5 = -0x3fffff40;
  }
  (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,param_2,iVar5,puVar10);
  return uVar9;
}



===== RequestDispatchSpecialIoctls @ 140004da0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 RequestDispatchSpecialIoctls(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  bool bVar1;
  char cVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  code *pcVar6;
  longlong lVar7;
  longlong lVar8;
  undefined4 extraout_var;
  longlong lVar9;
  undefined4 extraout_var_00;
  undefined4 extraout_var_01;
  code *pcVar10;
  undefined4 extraout_var_02;
  undefined8 uVar11;
  undefined2 uVar12;
  ulonglong uVar13;
  undefined1 auStackY_e8 [32];
  undefined1 uVar14;
  code *local_90;
  ulonglong local_88 [2];
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_e8;
  uVar13 = 0;
  bVar1 = false;
  local_88[0] = 0;
  pcVar6 = (code *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1,DAT_14001a0f0)
  ;
  iVar4 = *(int *)(param_3 + 3);
  if (iVar4 == 0x7c0c8) {
    pcVar10 = (code *)(**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals,param_2);
    if (((((*(longlong *)(pcVar6 + 0x118) == 0) ||
          (pcVar10 != *(code **)(*(longlong *)(pcVar6 + 0x118) + 0x40))) ||
         (pcVar10 = (code *)(**(code **)(WdfFunctions_01015 + 0x8c0))(WdfDriverGlobals,param_2),
         (char)pcVar10 != '\0')) ||
        ((pcVar10 = RequestSetupMcnSyncIrp, (code *)param_3[1] != RequestSetupMcnSyncIrp ||
         ((code *)param_3[2] != RequestSetupMcnSyncIrp)))) ||
       ((code *)param_3[4] != RequestSetupMcnSyncIrp)) {
LAB_140005212:
      return (ulonglong)pcVar10 & 0xffffffffffffff00;
    }
    pcVar10 = (code *)(**(code **)(WdfFunctions_01015 + 0x2d8))(WdfDriverGlobals,param_1,param_2);
    if ((int)pcVar10 < 0) {
      uVar11 = RequestCompletion((longlong)pcVar6,param_2,(int)pcVar10,0);
      return CONCAT71((int7)((ulonglong)uVar11 >> 8),1);
    }
    goto LAB_140004f76;
  }
  if (((iVar4 == 0x4d048) || (iVar4 == 0x4d004)) || ((iVar4 == 0x4d014 || (iVar4 == 0x4d044)))) {
    cVar2 = (**(code **)(WdfFunctions_01015 + 0x818))(WdfDriverGlobals,param_2);
    if (cVar2 == '\0') {
      if ((iVar4 - 0x4d004U & 0xffffffef) == 0) {
        if ((ulonglong)param_3[2] < 0x38) {
LAB_140005175:
          local_58 = 0;
          uStack_70 = 0;
          local_78 = 0x28;
          local_68 = 0;
          uStack_60 = 0;
          (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_78);
          uVar14 = (undefined1)uStack_60;
          if (local_78._4_4_ == 0xe) {
            if ((uint)uStack_60 == 0x7c0c8) {
              if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
                 (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
                WPP_RECORDER_SF_DDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,100,
                                    &WPP_8ec010589a13368bcaefd70a9b2ee310_Traceguids,uVar14,0xd,0);
              }
            }
            else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_DDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,99,
                                  &WPP_8ec010589a13368bcaefd70a9b2ee310_Traceguids,uVar14,0xd,0);
            }
          }
          else if (local_78._4_4_ == 3) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar12 = 0x65;
              goto LAB_140005312;
            }
          }
          else if ((local_78._4_4_ == 4) &&
                  ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
            uVar12 = 0x66;
LAB_140005312:
            WPP_RECORDER_SF_DDDD
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,uVar12,
                       &WPP_8ec010589a13368bcaefd70a9b2ee310_Traceguids,uVar14,(char)uStack_70,0,0xd
                      );
          }
          uVar11 = 0xc00000c0;
          if (pcVar6[10] != (code)0x1) {
            uVar11 = 0xc000000d;
          }
          pcVar10 = (code *)(**(code **)(WdfFunctions_01015 + 0x848))
                                      (WdfDriverGlobals,param_2,uVar11,0);
          goto LAB_140004f76;
        }
      }
      else if ((ulonglong)param_3[2] < 0x40) goto LAB_140005175;
    }
    else if ((iVar4 - 0x4d004U & 0xffffffef) == 0) {
      if ((ulonglong)param_3[2] < 0x2c) goto LAB_140005175;
    }
    else if ((ulonglong)param_3[2] < 0x34) goto LAB_140005175;
    lVar7 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,param_2,PTR__WDF_CDROM_REQUEST_CONTEXT_TYPE_INFO_14001a018);
    lVar8 = ExAllocatePool2(0x40,0x18,0x65436353);
    if (lVar8 == 0) {
      pcVar10 = (code *)RequestCompletion((longlong)pcVar6,param_2,-0x3fffff66,0);
    }
    else {
      *(longlong *)(lVar7 + 0x38) = lVar8;
      *(undefined1 *)(lVar7 + 0x34) = 1;
      *(code **)(lVar7 + 0x40) = RequestHandleScsiPassThrough;
      iVar4 = RequestSynchronizeProcessWithSerialQueue(param_1,param_2);
      pcVar10 = (code *)CONCAT44(extraout_var,iVar4);
    }
    goto LAB_140004f76;
  }
  pcVar10 = pcVar6;
  if (iVar4 != 0x2d1400) goto LAB_140005212;
  if ((ulonglong)param_3[2] < 0xc) {
    iVar4 = -0x3ffffffc;
  }
  else {
    local_90 = (code *)0x0;
    pcVar10 = (code *)(**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_2);
    iVar4 = (int)pcVar10;
    if (-1 < iVar4) {
      if (((*(longlong *)(pcVar6 + 0x378) == 0) ||
          (lVar7 = (**(code **)(WdfFunctions_01015 + 0x8a8))(WdfDriverGlobals,param_2),
          *(longlong *)(pcVar6 + 0x378) == lVar7)) || (iRam0000000000000004 == 1)) {
        if (uRam0000000000000000 == 3) {
          pcVar10 = RequestHandleQueryPropertyDeviceUniqueId;
LAB_1400053f4:
          pcVar10 = (code *)RequestSetContextFields(param_2,pcVar10);
          iVar4 = (int)pcVar10;
          if (iVar4 < 0) goto LAB_14000510d;
          iVar4 = RequestSynchronizeProcessWithSerialQueue(param_1,param_2);
          pcVar10 = (code *)CONCAT44(extraout_var_02,iVar4);
        }
        else {
          if (uRam0000000000000000 == 4) {
            pcVar10 = RequestHandleQueryPropertyWriteCache;
            goto LAB_1400053f4;
          }
          local_78 = *param_3;
          uStack_70 = param_3[1];
          local_68 = param_3[2];
          uStack_60 = param_3[3];
          local_58 = param_3[4];
          lVar7 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1,DAT_14001a0f0);
          cVar2 = KeGetCurrentIrql();
          if ((cVar2 == '\0') && (((uint)uStack_60 & 0xffff0000) != 0x320000)) {
            lVar8 = (**(code **)(WdfFunctions_01015 + 0x650))
                              (WdfDriverGlobals,param_2,
                               PTR__WDF_CDROM_REQUEST_CONTEXT_TYPE_INFO_14001a018);
            lVar9 = ExAllocatePool2(0x40,0x18,0x65436353);
            if (lVar9 == 0) {
              pcVar10 = (code *)RequestCompletion(lVar7,param_2,-0x3fffff66,0);
            }
            else {
              *(longlong *)(lVar8 + 0x38) = lVar9;
              *(undefined1 *)(lVar8 + 0x34) = 1;
              *(code **)(lVar8 + 0x40) = RequestHandleUnknownIoctl;
              iVar5 = RequestSynchronizeProcessWithSerialQueue(param_1,param_2);
              pcVar10 = (code *)CONCAT44(extraout_var_00,iVar5);
            }
          }
          else {
            iVar5 = RequestHandleUnknownIoctl(param_1,param_2);
            pcVar10 = (code *)CONCAT44(extraout_var_01,iVar5);
          }
        }
        bVar1 = true;
      }
      else if ((iRam0000000000000004 == 0) && (uRam0000000000000000 < 2)) {
        local_78 = *param_3;
        uStack_70 = param_3[1];
        local_68 = param_3[2];
        uStack_60 = param_3[3];
        local_58 = param_3[4];
        pcVar10 = (code *)RequestHandleQueryPropertyRetrieveCachedData
                                    ((longlong)pcVar6,param_2,(longlong)&local_78,local_88);
        iVar4 = (int)pcVar10;
        uVar13 = local_88[0];
      }
      else {
        iVar4 = -0x3fffffde;
        pcVar10 = local_90;
      }
    }
  }
LAB_14000510d:
  if (!bVar1) {
    bVar3 = RequestGetCurrentStackLocationFlags(param_2);
    if ((iVar4 == -0x7fffffea) && ((bVar3 & 2) != 0)) {
      local_78 = *param_3;
      uStack_70 = param_3[1];
      local_68 = param_3[2];
      uStack_60 = param_3[3];
      local_58 = param_3[4];
      uVar11 = RequestDispatchSpecialIoctls(param_1,param_2,&local_78);
      return uVar11;
    }
    uVar11 = RequestCompletion((longlong)pcVar6,param_2,iVar4,uVar13);
    return CONCAT71((int7)((ulonglong)uVar11 >> 8),1);
  }
LAB_140004f76:
  return CONCAT71((int7)((ulonglong)pcVar10 >> 8),1);
}



===== RequestDispatchSyncWithSequentialQueue @ 140005490 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
RequestDispatchSyncWithSequentialQueue(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  byte bVar1;
  int iVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined4 extraout_var;
  code *pcVar5;
  int *local_res18;
  undefined8 local_res20;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  local_res20 = 0;
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1,DAT_14001a0f0);
  if (*(int *)(param_3 + 3) != 0x2c05c) {
    return uVar3 & 0xffffffffffffff00;
  }
  local_48 = *param_3;
  uStack_40 = param_3[1];
  local_38 = param_3[2];
  uStack_30 = param_3[3];
  local_28 = param_3[4];
  uVar4 = RequestValidateExclusiveAccess(param_2,(longlong)&local_48,&local_res20);
  iVar2 = (int)uVar4;
  if (-1 < iVar2) {
    local_res18 = (int *)0x0;
    uVar4 = (**(code **)(WdfFunctions_01015 + 0x868))
                      (WdfDriverGlobals,param_2,param_3[2],&local_res18,0);
    iVar2 = (int)uVar4;
    if (-1 < iVar2) {
      iVar2 = *local_res18;
      if (iVar2 == 0) {
        pcVar5 = RequestHandleExclusiveAccessQueryLockState;
LAB_1400055ae:
        uVar4 = RequestSetContextFields(param_2,pcVar5);
        iVar2 = (int)uVar4;
        if (iVar2 < 0) goto LAB_1400055ca;
      }
      else {
        if (iVar2 == 1) {
          pcVar5 = RequestHandleExclusiveAccessLockDevice;
          goto LAB_1400055ae;
        }
        if (iVar2 == 2) {
          pcVar5 = RequestHandleExclusiveAccessUnlockDevice;
          goto LAB_1400055ae;
        }
      }
      iVar2 = RequestSynchronizeProcessWithSerialQueue(param_1,param_2);
      uVar4 = CONCAT44(extraout_var,iVar2);
      goto LAB_140005628;
    }
  }
LAB_1400055ca:
  if (iVar2 < 0) {
    bVar1 = RequestGetCurrentStackLocationFlags(param_2);
    if ((iVar2 == -0x7fffffea) && ((bVar1 & 2) != 0)) {
      local_48 = *param_3;
      uStack_40 = param_3[1];
      local_38 = param_3[2];
      uStack_30 = param_3[3];
      local_28 = param_3[4];
      uVar4 = RequestDispatchSyncWithSequentialQueue(param_1,param_2,&local_48);
      return uVar4;
    }
    uVar4 = RequestCompletion(uVar3,param_2,iVar2,local_res20);
  }
LAB_140005628:
  return CONCAT71((int7)((ulonglong)uVar4 >> 8),1);
}



===== RequestDispatchToSequentialQueue @ 140005640 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Type propagation algorithm not settling */

ulonglong RequestDispatchToSequentialQueue
                    (undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  char cVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  char *pcVar8;
  undefined1 uVar9;
  uint uVar10;
  undefined2 uVar11;
  bool bVar12;
  int *local_res18;
  ulonglong local_res20;
  int *local_78 [2];
  undefined8 local_68;
  ulonglong uStack_60;
  ulonglong local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  
  uVar10 = 0;
  bVar12 = false;
  local_res20 = 0;
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1,DAT_14001a0f0);
  uVar2 = *(uint *)(param_3 + 3);
  if (*(longlong *)(lVar3 + 0x120) != 0) {
    bVar12 = *(char *)(*(longlong *)(lVar3 + 0x120) + 0x51) != '\0';
  }
  if (uVar2 == 0x335014) goto LAB_1400056b0;
  uVar9 = (undefined1)param_2;
  if (uVar2 == 0x2d0800) {
LAB_1400056dc:
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x35,
                        &WPP_d2ddb5c132d1335dbff1b624de01ec23_Traceguids,uVar9);
    }
    if (2 < param_3[1] - 1) goto LAB_140005701;
    uVar10 = 0xc0000023;
    local_res20 = 4;
    goto LAB_14000570c;
  }
  if (0x2c06c < uVar2) {
    if (uVar2 < 0x2d5019) {
      if (uVar2 != 0x2d5018) {
        if (uVar2 < 0x2d0941) {
          if (uVar2 != 0x2d0940) {
            if (uVar2 < 0x700a1) {
              if (uVar2 == 0x700a0) goto switchD_1400057aa_caseD_50;
              if (uVar2 == 0x70000) goto switchD_1400057aa_caseD_4c;
              if (uVar2 == 0x70014) {
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x3f,
                                     &WPP_d2ddb5c132d1335dbff1b624de01ec23_Traceguids,(char)param_1,
                                     uVar9);
                }
LAB_1400060df:
                bVar12 = (ulonglong)param_3[2] < 0x10;
                uVar10 = 0xc000000d;
                goto LAB_140005708;
              }
              if (uVar2 == 0x70024) goto LAB_1400056b0;
              uVar2 = uVar2 - 0x70048;
              if (uVar2 == 0) {
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x3e,
                                   &WPP_d2ddb5c132d1335dbff1b624de01ec23_Traceguids);
                }
                if ((ulonglong)param_3[1] < 0x90) {
                  uVar10 = 0xc0000023;
                  local_res20 = 0x90;
                }
              }
              else {
                uVar5 = (ulonglong)uVar2;
                if (uVar2 != 8) goto switchD_1400057aa_caseD_1;
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x3c,
                                   &WPP_d2ddb5c132d1335dbff1b624de01ec23_Traceguids);
                }
                if ((ulonglong)param_3[1] < 0xc0) {
                  uVar10 = 0xc0000023;
                  local_res20 = 0xc0;
                }
              }
            }
            else if (uVar2 == 0x74004) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x3d,
                                 &WPP_d2ddb5c132d1335dbff1b624de01ec23_Traceguids);
              }
              if ((ulonglong)param_3[1] < 0x20) {
                uVar10 = 0xc0000023;
                local_res20 = 0x20;
              }
            }
            else if (uVar2 == 0x7400c) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x3b,
                                 &WPP_d2ddb5c132d1335dbff1b624de01ec23_Traceguids);
              }
              if ((ulonglong)param_3[1] < 0x28) {
                uVar10 = 0xc0000023;
                local_res20 = 0x28;
              }
            }
            else {
              if (uVar2 != 0x7405c) {
                uVar2 = uVar2 - 0x7421c;
                uVar5 = (ulonglong)uVar2;
                if ((uVar2 != 0) && (uVar2 != 0x25c5f0)) goto switchD_1400057aa_caseD_1;
                goto LAB_1400056b0;
              }
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x40,
                                 &WPP_d2ddb5c132d1335dbff1b624de01ec23_Traceguids);
              }
              if (7 < (ulonglong)param_3[1]) goto LAB_140005701;
              uVar10 = 0xc0000023;
              local_res20 = 8;
            }
            goto LAB_14000570c;
          }
          goto LAB_140006242;
        }
        if (uVar2 < 0x2d4809) {
          if (uVar2 != 0x2d4808) {
            if (uVar2 == 0x2d0944) {
LAB_140006242:
              uVar10 = -(uint)(param_3[2] == 0) & 0xc0000004;
              goto LAB_14000570c;
            }
            if (uVar2 == 0x2d1880) {
              uVar10 = 0xc00000bb;
              (**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals,param_2);
              goto LAB_1400062c9;
            }
            if (uVar2 != 0x2d4400) {
              uVar2 = uVar2 - 0x2d4800;
              if (uVar2 == 0) goto LAB_1400056dc;
              uVar5 = (ulonglong)uVar2;
              if (uVar2 != 4) goto switchD_1400057aa_caseD_1;
              goto LAB_140006242;
            }
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
            goto LAB_1400060df;
            WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x3a,
                              &WPP_d2ddb5c132d1335dbff1b624de01ec23_Traceguids,uVar9);
            bVar12 = (ulonglong)param_3[2] < 0x10;
            uVar10 = 0xc000000d;
            goto LAB_140005708;
          }
        }
        else if ((uVar2 != 0x2d480c) && (uVar2 != 0x2d4810)) {
          uVar2 = uVar2 - 0x2d4814;
          if (uVar2 != 0) {
            uVar5 = (ulonglong)uVar2;
            if (uVar2 != 4) goto switchD_1400057aa_caseD_1;
            IoInvalidateDeviceRelations(*(undefined8 *)(lVar3 + 0x48),0);
          }
        }
        goto LAB_1400056b0;
      }
LAB_14000633c:
      local_68 = *param_3;
      uStack_60 = param_3[1];
      local_58 = param_3[2];
      uStack_50 = param_3[3];
      local_48 = param_3[4];
      uVar10 = RequestValidatePersistentReserve(lVar3,param_2,(longlong)&local_68,&local_res20);
    }
    else if (uVar2 < 0x335001) {
      if (uVar2 == 0x335000) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x38,
                            &WPP_d2ddb5c132d1335dbff1b624de01ec23_Traceguids,uVar9);
        }
        local_68 = *param_3;
        uStack_60 = param_3[1];
        local_58 = param_3[2];
        uStack_50 = param_3[3];
        local_48 = param_3[4];
        uVar6 = RequestValidateDvdStartSession(lVar3,(longlong)&local_68,&local_res20);
        uVar10 = (uint)uVar6;
      }
      else {
        if (uVar2 != 0x2d5140) {
          uVar5 = (ulonglong)uVar2;
          if (uVar2 != 0x2dd01c) goto switchD_1400057aa_caseD_1;
          goto LAB_14000633c;
        }
        if (0x1f < (ulonglong)param_3[1]) goto LAB_140005701;
        local_res20 = 0x20;
        uVar10 = 0xc0000023;
      }
    }
    else if (uVar2 < 0x335141) {
      if (uVar2 == 0x335140) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x36,
                            &WPP_d2ddb5c132d1335dbff1b624de01ec23_Traceguids,uVar9);
        }
        local_68 = *param_3;
        uStack_60 = param_3[1];
        local_58 = param_3[2];
        uStack_50 = param_3[3];
        local_48 = param_3[4];
        uVar10 = RequestValidateDvdReadStructure(lVar3,(longlong)&local_68,&local_res20);
      }
      else {
        uVar7 = (ulonglong)(uVar2 - 0x335004);
        uVar5 = uVar7;
        if (0xe8 < uVar2 - 0x335004) {
switchD_1400057aa_caseD_1:
          return uVar5 & 0xffffffffffffff00;
        }
        uVar5 = (ulonglong)(&switchD_140006439::switchdataD_140016fc1)[uVar7];
        pcVar8 = IMAGE_DOS_HEADER_140000000.e_magic +
                 (&switchD_140006439::switchdataD_140016f85)[uVar5];
        switch(uVar7) {
        case 0:
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x37,
                              &WPP_d2ddb5c132d1335dbff1b624de01ec23_Traceguids,uVar9);
          }
          local_68 = *param_3;
          uStack_60 = param_3[1];
          local_58 = param_3[2];
          uStack_50 = param_3[3];
          local_48 = param_3[4];
          uVar10 = RequestValidateDvdReadKey(lVar3,param_2,(longlong)&local_68,&local_res20);
          break;
        default:
          goto switchD_1400057aa_caseD_1;
        case 4:
          goto switchD_140006439_caseD_4;
        case 8:
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            pcVar8 = *(char **)(WPP_GLOBAL_Control + 0x40);
            WPP_RECORDER_SF_q(pcVar8,4,5,0x43,&WPP_d2ddb5c132d1335dbff1b624de01ec23_Traceguids,uVar9
                             );
          }
          local_68 = *param_3;
          uStack_60 = param_3[1];
          local_58 = param_3[2];
          uStack_50 = param_3[3];
          local_48 = param_3[4];
          uVar6 = RequestValidateDvdEndSession(pcVar8,uVar9,(longlong)&local_68,&local_res20);
          uVar10 = (uint)uVar6;
          break;
        case 0xc0:
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,5,0x45,
                              &WPP_d2ddb5c132d1335dbff1b624de01ec23_Traceguids,
                              (char)*(undefined4 *)(param_3 + 1));
          }
          local_68 = *param_3;
          uStack_60 = param_3[1];
          local_58 = param_3[2];
          uStack_50 = param_3[3];
          local_48 = param_3[4];
          uVar5 = RequestValidateAacsReadMediaKeyBlock
                            (lVar3,param_2,(longlong)&local_68,&local_res20);
          uVar10 = (uint)uVar5;
          break;
        case 0xc4:
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,5,0x46,
                             &WPP_d2ddb5c132d1335dbff1b624de01ec23_Traceguids);
          }
          local_68 = *param_3;
          uStack_60 = param_3[1];
          local_58 = param_3[2];
          uStack_50 = param_3[3];
          local_48 = param_3[4];
          if (*(char *)(lVar3 + 0x289) == '\0') {
            uVar10 = 0xc0000010;
          }
          else if (uStack_60 < 4) {
            local_res20 = 4;
            uVar10 = 0xc0000023;
          }
          else {
            uVar10 = 0;
            if (4 < uStack_60) {
              uVar10 = 0xc0000206;
            }
          }
          break;
        case 200:
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x44,
                              &WPP_d2ddb5c132d1335dbff1b624de01ec23_Traceguids,uVar9);
          }
          local_68 = *param_3;
          uStack_60 = param_3[1];
          local_58 = param_3[2];
          uStack_50 = param_3[3];
          local_48 = param_3[4];
          uVar5 = RequestValidateAacsEndSession(lVar3,param_2,(longlong)&local_68,&local_res20);
          uVar10 = (uint)uVar5;
          break;
        case 0xcc:
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,5,0x47,
                             &WPP_d2ddb5c132d1335dbff1b624de01ec23_Traceguids);
          }
          local_68 = *param_3;
          uStack_60 = param_3[1];
          local_58 = param_3[2];
          uStack_50 = param_3[3];
          local_48 = param_3[4];
          uVar5 = RequestValidateAacsSendCertificate(lVar3,param_2,(longlong)&local_68,&local_res20)
          ;
          uVar10 = (uint)uVar5;
          break;
        case 0xd0:
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,5,0x48,
                             &WPP_d2ddb5c132d1335dbff1b624de01ec23_Traceguids);
          }
          local_68 = *param_3;
          uStack_60 = param_3[1];
          local_58 = param_3[2];
          uStack_50 = param_3[3];
          local_48 = param_3[4];
          uVar5 = RequestValidateAacsGetCertificate(lVar3,param_2,(longlong)&local_68,&local_res20);
          uVar10 = (uint)uVar5;
          break;
        case 0xd4:
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,5,0x49,
                             &WPP_d2ddb5c132d1335dbff1b624de01ec23_Traceguids);
          }
          local_68 = *param_3;
          uStack_60 = param_3[1];
          local_58 = param_3[2];
          uStack_50 = param_3[3];
          local_48 = param_3[4];
          uVar5 = RequestValidateAacsGetChallengeKey(lVar3,param_2,(longlong)&local_68,&local_res20)
          ;
          uVar10 = (uint)uVar5;
          break;
        case 0xd8:
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,5,0x4a,
                             &WPP_d2ddb5c132d1335dbff1b624de01ec23_Traceguids);
          }
          local_68 = *param_3;
          uStack_60 = param_3[1];
          local_58 = param_3[2];
          uStack_50 = param_3[3];
          local_48 = param_3[4];
          uVar5 = RequestValidateAacsSendChallengeKey
                            (lVar3,param_2,(longlong)&local_68,&local_res20);
          uVar10 = (uint)uVar5;
          break;
        case 0xdc:
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,5,0x4b,
                             &WPP_d2ddb5c132d1335dbff1b624de01ec23_Traceguids);
          }
          local_68 = *param_3;
          uStack_60 = param_3[1];
          local_58 = param_3[2];
          uStack_50 = param_3[3];
          local_48 = param_3[4];
          uVar5 = RequestValidateAacsReadMediaId(lVar3,param_2,(longlong)&local_68,&local_res20);
          uVar10 = (uint)uVar5;
          break;
        case 0xe0:
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,5,0x4c,
                             &WPP_d2ddb5c132d1335dbff1b624de01ec23_Traceguids);
          }
          local_68 = *param_3;
          uStack_60 = param_3[1];
          local_58 = param_3[2];
          uStack_50 = param_3[3];
          local_48 = param_3[4];
          uVar5 = RequestValidateAacsReadMediaId(lVar3,param_2,(longlong)&local_68,&local_res20);
          uVar10 = (uint)uVar5;
          break;
        case 0xe4:
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,5,0x4d,
                             &WPP_d2ddb5c132d1335dbff1b624de01ec23_Traceguids);
          }
          local_68 = *param_3;
          uStack_60 = param_3[1];
          local_58 = param_3[2];
          uStack_50 = param_3[3];
          local_48 = param_3[4];
          uVar5 = RequestValidateAacsReadMediaId(lVar3,param_2,(longlong)&local_68,&local_res20);
          uVar10 = (uint)uVar5;
          break;
        case 0xe8:
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar11 = 0x4f;
            goto LAB_140006a6c;
          }
          goto LAB_140006a90;
        }
      }
    }
    else if (uVar2 == 0x33d018) {
switchD_140006439_caseD_4:
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x39,
                          &WPP_d2ddb5c132d1335dbff1b624de01ec23_Traceguids,uVar9);
      }
      local_68 = *param_3;
      uStack_60 = param_3[1];
      local_58 = param_3[2];
      uStack_50 = param_3[3];
      local_48 = param_3[4];
      uVar5 = RequestValidateDvdSendKey(lVar3,param_2,(longlong)&local_68,&local_res20);
      uVar10 = (uint)uVar5;
    }
    else {
      if (uVar2 != 0x33d0f0) {
        uVar2 = uVar2 - 0x56c008;
        uVar5 = (ulonglong)uVar2;
        if ((uVar2 != 0) && (uVar2 != 0x5c)) goto switchD_1400057aa_caseD_1;
        goto LAB_1400056b0;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar11 = 0x4e;
LAB_140006a6c:
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,5,uVar11,
                         &WPP_d2ddb5c132d1335dbff1b624de01ec23_Traceguids);
      }
LAB_140006a90:
      local_68 = *param_3;
      uStack_60 = param_3[1];
      local_58 = param_3[2];
      uStack_50 = param_3[3];
      local_48 = param_3[4];
      uVar10 = RequestValidateAacsBindingNonce(lVar3,param_2,(longlong)&local_68,&local_res20);
    }
    goto LAB_14000570c;
  }
  if (uVar2 == 0x2c06c) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x51,
                        &WPP_d2ddb5c132d1335dbff1b624de01ec23_Traceguids,uVar9);
    }
    local_68 = *param_3;
    uStack_60 = param_3[1];
    local_58 = param_3[2];
    uStack_50 = param_3[3];
    local_48 = param_3[4];
    uVar5 = RequestValidateSendOpcInformation(param_2,(longlong)&local_68,&local_res20);
    uVar10 = (uint)uVar5;
    goto LAB_14000570c;
  }
  uVar5 = 0;
  switch(uVar2 - 0x24000) {
  case 0:
    local_58 = param_3[2];
    uStack_50 = param_3[3];
    local_48 = param_3[4];
    if ((ulonglong)param_3[1] < 0x324) {
      uVar10 = 0xc0000023;
      local_res20 = 0x324;
    }
    else {
      uVar10 = 0;
      if ((param_3[1] & (ulonglong)*(uint *)(*(longlong *)(lVar3 + 0xd0) + 0x10)) != 0) {
        uVar10 = 0xc000000d;
      }
    }
    if (bVar12) {
      uVar10 = 0xc0000013;
    }
    break;
  default:
    goto switchD_1400057aa_caseD_1;
  case 4:
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x2f,
                       &WPP_d2ddb5c132d1335dbff1b624de01ec23_Traceguids);
    }
    uVar10 = -(uint)((ulonglong)param_3[2] < 3) & 0xc0000004;
    break;
  case 8:
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar11 = 0x34;
LAB_140005c37:
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,uVar11,
                       &WPP_d2ddb5c132d1335dbff1b624de01ec23_Traceguids);
    }
    goto LAB_1400056b0;
  case 0xc:
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar11 = 0x30;
      goto LAB_140005c37;
    }
    goto LAB_1400056b0;
  case 0x10:
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar11 = 0x31;
      goto LAB_140005c37;
    }
LAB_1400056b0:
    (**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals,param_2);
    goto LAB_14000573f;
  case 0x14:
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x32,
                       &WPP_d2ddb5c132d1335dbff1b624de01ec23_Traceguids);
    }
    if ((ulonglong)param_3[1] < 4) {
      uVar10 = 0xc0000023;
      local_res20 = 4;
    }
    break;
  case 0x18:
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x2e,
                       &WPP_d2ddb5c132d1335dbff1b624de01ec23_Traceguids);
    }
    uVar10 = -(uint)((ulonglong)param_3[2] < 6) & 0xc0000004;
    break;
  case 0x28:
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x33,
                       &WPP_d2ddb5c132d1335dbff1b624de01ec23_Traceguids);
    }
    uVar10 = -(uint)((ulonglong)param_3[2] < 4) & 0xc0000004;
    break;
  case 0x2c:
    local_68 = *param_3;
    uStack_60 = param_3[1];
    local_58 = param_3[2];
    uStack_50 = param_3[3];
    local_48 = param_3[4];
    uVar6 = RequestValidateReadQChannel(param_2,(longlong)&local_68,&local_res20);
    uVar10 = (uint)uVar6;
    break;
  case 0x38:
    local_58 = param_3[2];
    uStack_50 = param_3[3];
    local_48 = param_3[4];
    if ((ulonglong)param_3[1] < 0xc) {
      uVar10 = 0xc0000023;
      local_res20 = 0xc;
    }
    else {
      uVar10 = 0;
      if ((param_3[1] & (ulonglong)*(uint *)(*(longlong *)(lVar3 + 0xd0) + 0x10)) != 0) {
        uVar10 = 0xc000000d;
      }
    }
    break;
  case 0x3e:
    local_68 = *param_3;
    uStack_60 = param_3[1];
    local_58 = param_3[2];
    uStack_50 = param_3[3];
    local_48 = param_3[4];
    uVar10 = RequestValidateRawRead(lVar3,param_2,(longlong)&local_68,&local_res20);
    break;
  case 0x4c:
switchD_1400057aa_caseD_4c:
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x2d,
                       &WPP_d2ddb5c132d1335dbff1b624de01ec23_Traceguids);
    }
    if ((ulonglong)param_3[1] < 0x18) {
      uVar10 = 0xc0000023;
      local_res20 = 0x18;
    }
    else {
LAB_140005701:
      uVar10 = 0xc0000013;
LAB_140005708:
      uVar10 = uVar10 & -(uint)bVar12;
    }
    break;
  case 0x50:
switchD_1400057aa_caseD_50:
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x2c,
                       &WPP_d2ddb5c132d1335dbff1b624de01ec23_Traceguids);
    }
    if (0x1f < (ulonglong)param_3[1]) goto LAB_140005701;
    uVar10 = 0xc0000023;
    local_res20 = 0x20;
    break;
  case 0x54:
    local_68 = *param_3;
    uStack_60 = param_3[1];
    local_58 = param_3[2];
    uStack_50 = param_3[3];
    local_48 = param_3[4];
    uVar10 = RequestValidateReadTocEx(lVar3,param_2,(longlong)&local_68,&local_res20);
    if (bVar12) {
      uVar10 = 0xc0000013;
    }
    break;
  case 0x58:
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x41,
                        &WPP_d2ddb5c132d1335dbff1b624de01ec23_Traceguids,uVar9);
    }
    local_58 = param_3[2];
    uStack_50 = param_3[3];
    uVar5 = param_3[1];
    local_48 = param_3[4];
    if (uVar5 < 8) {
      uVar10 = 0xc0000023;
      local_res20 = 8;
    }
    else if (uVar5 < 0x10000) {
      if ((uVar5 & *(uint *)(*(longlong *)(lVar3 + 0xd0) + 0x10)) == 0) {
        cVar1 = (**(code **)(WdfFunctions_01015 + 0x818))(WdfDriverGlobals,param_2);
        if (cVar1 == '\0') {
          local_78[0] = (int *)0x0;
          if (local_58 < 0x18) {
            uVar10 = 0xc0000004;
          }
          else {
            uVar10 = (**(code **)(WdfFunctions_01015 + 0x868))
                               (WdfDriverGlobals,param_2,local_58,local_78,0);
            if ((-1 < (int)uVar10) &&
               (((0xffff < *local_78[0] || (2 < (uint)local_78[0][1])) ||
                ((*(longlong *)(local_78[0] + 2) != 0 || (*(longlong *)(local_78[0] + 4) != 0))))))
            goto LAB_140005833;
          }
        }
        else {
          local_res18 = (int *)0x0;
          if (local_58 < 0x10) {
            uVar10 = 0xc0000004;
          }
          else {
            uVar10 = (**(code **)(WdfFunctions_01015 + 0x868))
                               (WdfDriverGlobals,param_2,local_58,&local_res18,0);
            if ((-1 < (int)uVar10) &&
               ((((0xffff < *local_res18 || (2 < (uint)local_res18[1])) || (local_res18[2] != 0)) ||
                (local_res18[3] != 0)))) goto LAB_140005833;
          }
        }
      }
      else {
LAB_140005833:
        uVar10 = 0xc000000d;
      }
    }
    else {
      uVar10 = 0xc0000206;
    }
    break;
  case 0x60:
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x42,
                        &WPP_d2ddb5c132d1335dbff1b624de01ec23_Traceguids,uVar9);
    }
    local_68 = *param_3;
    uStack_60 = param_3[1];
    local_58 = param_3[2];
    uStack_50 = param_3[3];
    local_48 = param_3[4];
    uVar10 = RequestValidateSetSpeed(lVar3,param_2,(longlong)&local_68,&local_res20);
    break;
  case 0x68:
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x50,
                        &WPP_d2ddb5c132d1335dbff1b624de01ec23_Traceguids,uVar9);
    }
    local_68 = *param_3;
    uStack_60 = param_3[1];
    local_58 = param_3[2];
    uStack_50 = param_3[3];
    local_48 = param_3[4];
    uVar5 = RequestValidateEnableStreaming(param_2,(longlong)&local_68,&local_res20);
    uVar10 = (uint)uVar5;
    break;
  case 0x70:
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x52,
                        &WPP_d2ddb5c132d1335dbff1b624de01ec23_Traceguids,uVar9);
    }
    local_68 = *param_3;
    uStack_60 = param_3[1];
    local_58 = param_3[2];
    uStack_50 = param_3[3];
    local_48 = param_3[4];
    uVar10 = RequestValidateGetPerformance(param_2,(longlong)&local_68,&local_res20);
  }
LAB_14000570c:
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals,param_2);
  if (uVar10 == 0x80000016) {
    if ((*(byte *)(*(longlong *)(lVar4 + 0xb8) + 2) & 2) != 0) {
      local_68 = *param_3;
      uStack_60 = param_3[1];
      local_58 = param_3[2];
      uStack_50 = param_3[3];
      local_48 = param_3[4];
      uVar5 = RequestDispatchToSequentialQueue(param_1,param_2,&local_68);
      return uVar5;
    }
  }
  else if (-1 < (int)uVar10) {
LAB_14000573f:
    uVar10 = (**(code **)(WdfFunctions_01015 + 0x2d8))(WdfDriverGlobals,param_1,param_2);
    if (-1 < (int)uVar10) {
      return 1;
    }
  }
LAB_1400062c9:
  RequestCompletion(lVar3,param_2,uVar10,local_res20);
  return 1;
}



===== WPP_RECORDER_SF_q @ 140006b70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_q(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                      undefined8 param_5,undefined1 param_6)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,8,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,&param_6,8,0);
  return;
}



===== RequestValidateRawRead @ 140006c70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int RequestValidateRawRead(longlong param_1,undefined8 param_2,longlong param_3,undefined8 *param_4)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  int iVar5;
  int iVar6;
  longlong lVar7;
  ulonglong *puVar8;
  ulonglong uVar9;
  uint uVar10;
  ulonglong uVar11;
  short sVar12;
  ulonglong *local_res8;
  
  uVar4 = WdfDriverGlobals;
  lVar1 = WdfFunctions_01015;
  local_res8 = (ulonglong *)0x0;
  uVar11 = 0;
  *param_4 = 0;
  lVar7 = (**(code **)(lVar1 + 0x8e8))(uVar4);
  lVar1 = *(longlong *)(lVar7 + 0xb8);
  iVar5 = (**(code **)(WdfFunctions_01015 + 0x868))
                    (WdfDriverGlobals,param_2,*(undefined8 *)(param_3 + 0x10),&local_res8,0);
  if (iVar5 < 0) {
    return iVar5;
  }
  puVar8 = *(ulonglong **)(param_3 + 0x20);
  if (*(ulonglong **)(param_3 + 0x20) == (ulonglong *)0x0) {
    if (local_res8 == (ulonglong *)0x0) {
      return -0x3ffffff3;
    }
    uVar2 = *(ulonglong *)(param_3 + 0x10);
    *(ulonglong **)(lVar1 + 0x20) = local_res8;
    *(ulonglong **)(param_3 + 0x20) = local_res8;
    puVar8 = local_res8;
    if (uVar2 < 0x10) {
      *param_4 = 0x10;
      iVar5 = -0x3fffffdd;
    }
  }
  if (iVar5 < 0) {
    return iVar5;
  }
  uVar3 = *puVar8;
  uVar2 = puVar8[1];
  iVar6 = (int)(uVar2 >> 0x20);
  if (((uVar2 >> 0x20 & 0xfffffffd) == 0) || (iVar6 == 1)) {
    uVar11 = (uVar2 & 0xffffffff) * 0x930;
  }
  else if (iVar6 == 5) {
    uVar11 = (uVar2 & 0xffffffff) * 0x990;
  }
  else if (iVar6 == 4) {
    uVar11 = (uVar2 & 0xffffffff) * 0xa58;
  }
  else if (iVar6 == 3) {
    uVar11 = (uVar2 & 0xffffffff) * 0xab8;
  }
  else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,5,0xd,
                      &WPP_7cea3eca420c34d4f6f4315c54c616a1_Traceguids,(char)(uVar2 >> 0x20));
  }
  uVar9 = (uVar2 & 0xffffffff) * 0x800 + uVar3;
  if ((int)uVar2 == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return -0x3ffffff3;
    }
    sVar12 = (short)uVar2 + 0xe;
  }
  else if (uVar11 < (uVar2 & 0xffffffff)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return -0x3ffffff3;
    }
    sVar12 = 0xf;
  }
  else if (uVar9 < uVar3) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return -0x3ffffff3;
    }
    sVar12 = 0x10;
  }
  else if (*(ulonglong *)(param_3 + 8) < uVar11) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return -0x3ffffff3;
    }
    sVar12 = 0x11;
  }
  else {
    if (uVar9 <= *(ulonglong *)(param_1 + 0xa8)) {
      lVar7 = *(longlong *)(lVar7 + 8);
      if (*(uint *)(lVar7 + 0x28) < uVar11) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return -0x3ffffff3;
        }
        WPP_RECORDER_SF_sq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
        return -0x3ffffff3;
      }
      uVar10 = *(uint *)(*(longlong *)(param_1 + 0xd0) + 0x10);
      if (((ulonglong)uVar10 & (ulonglong)*(uint *)(lVar7 + 0x2c) + *(longlong *)(lVar7 + 0x20)) !=
          0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return -0x3ffffff3;
        }
        WPP_RECORDER_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,5,0x14,
                           &WPP_7cea3eca420c34d4f6f4315c54c616a1_Traceguids,
                           (char)*(undefined8 *)(param_3 + 0x20),(char)uVar10);
        return -0x3ffffff3;
      }
      if ((*(int *)(lVar7 + 0x2c) + *(int *)(lVar7 + 0x20) & 0xfffU) == 0) {
        uVar10 = *(uint *)(param_1 + 0x368);
      }
      else {
        uVar10 = *(uint *)(param_1 + 0x36c);
      }
      if (uVar11 <= uVar10) {
        *(undefined1 *)(lVar1 + 1) = 4;
        return iVar5;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return -0x3ffffff3;
      }
      WPP_RECORDER_SF_DiDs(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
      return -0x3ffffff3;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return -0x3ffffff3;
    }
    sVar12 = 0x12;
  }
  WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,5,sVar12,
                   &WPP_7cea3eca420c34d4f6f4315c54c616a1_Traceguids);
  return -0x3ffffff3;
}



===== WPP_RECORDER_SF_DDDDDDDDDDDDDDDDDd @ 140006fd0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_DDDDDDDDDDDDDDDDDd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  undefined1 uStack0000000000000068;
  undefined1 uStack0000000000000070;
  undefined1 uStack0000000000000078;
  undefined1 uStack0000000000000080;
  undefined1 uStack0000000000000088;
  undefined1 uStack0000000000000090;
  undefined1 uStack0000000000000098;
  undefined1 uStack00000000000000a0;
  undefined1 uStack00000000000000a8;
  undefined1 uStack00000000000000b0;
  undefined1 uStack00000000000000b8;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (2 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_14ceea506f553d1aa69114b6e3475b08_Traceguids,0x3e,&uStack0000000000000030,4,
               &uStack0000000000000038,4,&uStack0000000000000040,4,&uStack0000000000000048,4,
               &uStack0000000000000050,4,&uStack0000000000000058,4,&uStack0000000000000060,4,
               &uStack0000000000000068,4,&uStack0000000000000070,4,&uStack0000000000000078,4,
               &uStack0000000000000080,4,&uStack0000000000000088,4,&uStack0000000000000090,4,
               &uStack0000000000000098,4,&uStack00000000000000a0,4,&uStack00000000000000a8,4,
               &uStack00000000000000b0,4,&uStack00000000000000b8,4,0);
  }
  WppAutoLogTrace(param_1,3,1,&WPP_14ceea506f553d1aa69114b6e3475b08_Traceguids,0x3e,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,
                  &uStack0000000000000060,4,&uStack0000000000000068,4,&uStack0000000000000070,4,
                  &uStack0000000000000078,4,&uStack0000000000000080,4,&uStack0000000000000088,4,
                  &uStack0000000000000090,4,&uStack0000000000000098,4,&uStack00000000000000a0,4,
                  &uStack00000000000000a8,4,&uStack00000000000000b0,4,&uStack00000000000000b8,4,0);
  return;
}



===== RequestSend @ 1400072d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
RequestSend(longlong param_1,undefined8 param_2,undefined8 param_3,uint param_4,char *param_5)

{
  undefined8 uVar1;
  char cVar2;
  undefined4 uVar3;
  longlong lVar4;
  undefined1 auStackY_78 [32];
  undefined4 local_48;
  uint local_44;
  undefined8 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_78;
  if (((*(longlong *)(param_1 + 0x120) != 0) &&
      (*(char *)(*(longlong *)(param_1 + 0x120) + 0x51) != '\0')) &&
     ((Microsoft_Windows_CDROMEnableBits & 2) != 0)) {
    McTemplateK0_EtwWriteTransfer(param_1,&ZeroPowerODDPowerOnStart,param_3);
  }
  uVar3 = 0;
  local_40 = 0;
  local_48 = 0x10;
  local_44 = param_4;
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_CDROM_REQUEST_CONTEXT_TYPE_INFO_14001a018);
  uVar1 = _DAT_fffff78000000320;
  if (*(longlong *)(lVar4 + 0x18) == 0) {
    *(undefined8 *)(lVar4 + 0x18) = _DAT_fffff78000000320;
  }
  *(undefined8 *)(lVar4 + 0x20) = uVar1;
  if (*(longlong *)(lVar4 + 8) != 0) {
    lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,*(longlong *)(lVar4 + 8),
                       PTR__WDF_CDROM_REQUEST_CONTEXT_TYPE_INFO_14001a018);
    if (*(longlong *)(lVar4 + 0x18) == 0) {
      *(undefined8 *)(lVar4 + 0x18) = uVar1;
    }
    *(undefined8 *)(lVar4 + 0x20) = uVar1;
  }
  cVar2 = (**(code **)(WdfFunctions_01015 + 0x7e8))(WdfDriverGlobals,param_2,param_3,&local_48);
  if ((cVar2 == '\0') || ((param_4 & 2) != 0)) {
    uVar3 = (**(code **)(WdfFunctions_01015 + 0x7f0))(WdfDriverGlobals,param_2);
    if ((cVar2 == '\0') && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,1,0x68,
                        &WPP_8ec010589a13368bcaefd70a9b2ee310_Traceguids,(char)uVar3);
    }
  }
  if (param_5 != (char *)0x0) {
    *param_5 = cVar2;
  }
  return uVar3;
}



===== DeviceSendPowerDownProcessRequest @ 1400074a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DeviceSendPowerDownProcessRequest(longlong param_1,longlong param_2,undefined8 param_3)

{
  longlong *plVar1;
  int iVar2;
  longlong lVar3;
  ulonglong uVar4;
  byte bVar5;
  uint uVar6;
  uint uVar7;
  char local_res8 [8];
  int local_res20 [2];
  ulonglong local_48 [2];
  
  uVar6 = *(uint *)(param_1 + 0x78);
  plVar1 = (longlong *)(param_1 + 0x268);
  local_res8[0] = '\0';
  *plVar1 = 0;
  uVar7 = 1;
  local_res20[0] = PowerContextReuseRequest(param_1);
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x1f0),
                     PTR__WDF_CDROM_REQUEST_CONTEXT_TYPE_INFO_14001a018);
  *(undefined8 *)(lVar3 + 0x18) = 0;
  *(undefined8 *)(lVar3 + 0x20) = 0;
  if (local_res20[0] < 0) {
    return local_res20[0];
  }
  iVar2 = *(int *)(param_1 + 0x1e8);
  if (iVar2 == 0) goto LAB_1400075a0;
  if (iVar2 == 1) {
    uVar6 = *(uint *)(param_1 + 0x78);
  }
  else {
    if (iVar2 == 2) goto LAB_1400075a0;
    if (iVar2 != 3) {
      if (iVar2 != 4) {
        return -0x3ffffffe;
      }
      goto LAB_1400075a0;
    }
    local_48[0] = local_48[0] & 0xffffffff00000000;
    PoQueryWatchdogTime(*(undefined8 *)(param_1 + 0x48),local_48);
    if ((uint)local_48[0] == 0) {
      uVar6 = 10;
    }
    else {
      if ((uint)local_48[0] < 0x20) {
        uVar6 = 2;
        goto LAB_1400075a0;
      }
      uVar6 = 10;
      uVar7 = ((uint)local_48[0] - 0x1e) / 10 + 1;
      if (uVar7 < 5) {
        if (uVar7 == 1) {
          uVar6 = (uint)local_48[0] - 0x1e;
        }
        goto LAB_1400075a0;
      }
    }
  }
  uVar7 = 4;
LAB_1400075a0:
  *(uint *)(param_1 + 0x264) = uVar7;
  do {
    iVar2 = *(int *)(param_1 + 0x1e8);
    *(undefined4 *)(param_1 + 0x204) = 0x80908;
    *(undefined1 *)(param_1 + 0x1fa) = 0;
    *(uint *)(param_1 + 0x20c) = uVar6;
    if (iVar2 == 0) {
      *(undefined1 *)(param_1 + 0x1fa) = 0x18;
    }
    else if (iVar2 == 1) {
      *(undefined1 *)(param_1 + 0x1fa) = 0x1a;
    }
    else if (iVar2 == 2) {
      *(undefined1 *)(param_1 + 0x202) = 10;
      *(undefined1 *)(param_1 + 0x240) = 0x35;
    }
    else if (iVar2 == 3) {
      *(undefined1 *)(param_1 + 0x202) = 6;
      *(byte *)(param_1 + 0x244) = *(byte *)(param_1 + 0x244) & 0xfe;
      *(byte *)(param_1 + 0x241) = *(byte *)(param_1 + 0x241) | 1;
      *(undefined1 *)(param_1 + 0x240) = 0x1b;
    }
    else if (iVar2 == 4) {
      *(undefined1 *)(param_1 + 0x1fa) = 0x19;
    }
    if (param_2 != 0) {
      (**(code **)(WdfFunctions_01015 + 0x820))
                (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x1f0),param_2,param_3);
    }
    local_res20[0] =
         RequestSend(param_1,*(undefined8 *)(param_1 + 0x1f0),*(undefined8 *)(param_1 + 0x18),
                     ~-(uint)(param_2 != 0) & 2,local_res8);
    if (local_res8[0] == '\0') break;
    if ((param_2 == 0) && ((*(byte *)(param_1 + 0x1fb) & 0x3f) != 1)) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qsqD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
      }
      uVar4 = RequestSenseInfoInterpret
                        (param_1,*(undefined8 *)(param_1 + 0x1f0),(undefined8 *)(param_1 + 0x1f8),
                         uVar7 - *(int *)(param_1 + 0x264),(undefined **)local_res20,plVar1);
      if ((byte)uVar4 == 0) break;
      iVar2 = *(int *)(param_1 + 0x264);
      *(int *)(param_1 + 0x264) = iVar2 + -1;
      bVar5 = -(iVar2 != 0) & (byte)uVar4;
    }
    else {
      bVar5 = 0;
    }
    if (bVar5 == 0) break;
    local_48[0] = -*plVar1;
    KeDelayExecutionThread(0,0,local_48);
    local_res20[0] = PowerContextReuseRequest(param_1);
  } while (-1 < local_res20[0]);
  if (*(int *)(param_1 + 0x1e8) == 2) {
    *(undefined8 *)(param_1 + 0x1d8) = _DAT_fffff78000000320;
  }
  return local_res20[0];
}



===== WPP_RECORDER_SF_ii @ 1400077c4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_ii(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_14ceea506f553d1aa69114b6e3475b08_Traceguids,param_4,&param_6,8,&param_7,8,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_14ceea506f553d1aa69114b6e3475b08_Traceguids,param_4,&param_6,8,
                  &param_7,8,0);
  return;
}



===== RequestSenseInfoInterpretForScratchBuffer @ 1400078a0 =====

char RequestSenseInfoInterpretForScratchBuffer
               (longlong param_1,uint param_2,undefined **param_3,undefined8 *param_4)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  char cVar6;
  undefined *local_res8;
  
  puVar1 = *(undefined8 **)(param_1 + 0x408);
  uVar2 = *(undefined8 *)(param_1 + 0x400);
  lVar3 = *(longlong *)(param_1 + 0x120);
  local_res8 = (undefined *)0x0;
  if ((*(byte *)((longlong)puVar1 + 3) & 0x3f) == 1) {
    if ((lVar3 != 0) && (*(int *)(lVar3 + 0x54) != 0)) {
      *(undefined4 *)(lVar3 + 0x54) = 0;
    }
    *(undefined4 *)param_3 = 0;
    cVar6 = '\0';
  }
  else {
    if ((*(byte *)((longlong)puVar1 + 3) & 0x40) != 0) {
      DeviceReleaseQueue(*(undefined8 *)(param_1 + 0x10));
    }
    if ((lVar3 != 0) && ((*(char *)(lVar3 + 0x52) != '\0' || (*(int *)(lVar3 + 0x54) != 0)))) {
      uVar5 = SenseInfoInterpretForZPODD
                        (param_1,(longlong)puVar1,(undefined4 *)param_3,(longlong *)&local_res8);
      cVar6 = (char)uVar5;
      if (cVar6 != '\0') goto LAB_1400078fc;
      if (*(int *)(lVar3 + 0x54) != 0) {
        *(undefined4 *)(lVar3 + 0x54) = 0;
      }
    }
    uVar4 = SenseInfoInterpret(param_1,uVar2,puVar1,param_2,param_3,&local_res8);
    cVar6 = (char)uVar4;
  }
LAB_1400078fc:
  if (param_4 != (undefined8 *)0x0) {
    *param_4 = local_res8;
  }
  return cVar6;
}



===== RequestSenseInfoInterpret @ 1400079b0 =====

ulonglong RequestSenseInfoInterpret
                    (longlong param_1,undefined8 param_2,undefined8 *param_3,uint param_4,
                    undefined **param_5,undefined8 *param_6)

{
  longlong lVar1;
  ulonglong uVar2;
  undefined *local_res8;
  
  lVar1 = *(longlong *)(param_1 + 0x120);
  local_res8 = (undefined *)0x0;
  if ((*(byte *)((longlong)param_3 + 3) & 0x3f) == 1) {
    if ((lVar1 != 0) && (*(int *)(lVar1 + 0x54) != 0)) {
      *(undefined4 *)(lVar1 + 0x54) = 0;
    }
    uVar2 = 0;
    *(undefined4 *)param_5 = 0;
    goto LAB_140007a0e;
  }
  if ((*(byte *)((longlong)param_3 + 3) & 0x40) != 0) {
    DeviceReleaseQueue(*(undefined8 *)(param_1 + 0x10));
  }
  if ((lVar1 == 0) || ((*(char *)(lVar1 + 0x52) == '\0' && (*(int *)(lVar1 + 0x54) == 0)))) {
LAB_140007a62:
    uVar2 = SenseInfoInterpret(param_1,param_2,param_3,param_4,param_5,&local_res8);
  }
  else {
    uVar2 = SenseInfoInterpretForZPODD
                      (param_1,(longlong)param_3,(undefined4 *)param_5,(longlong *)&local_res8);
    if ((char)uVar2 == '\0') {
      if (*(int *)(lVar1 + 0x54) != 0) {
        *(undefined4 *)(lVar1 + 0x54) = 0;
      }
      goto LAB_140007a62;
    }
  }
  uVar2 = uVar2 & 0xff;
LAB_140007a0e:
  if (param_6 != (undefined8 *)0x0) {
    *param_6 = local_res8;
  }
  return uVar2;
}



===== SenseInfoInterpret @ 140007af0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong SenseInfoInterpret(longlong param_1,undefined8 param_2,undefined8 *param_3,uint param_4,
                            undefined **param_5,undefined **param_6)

{
  byte bVar1;
  byte bVar2;
  char *pcVar3;
  undefined *puVar4;
  undefined4 uVar5;
  char cVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  longlong lVar10;
  undefined8 uVar11;
  ulonglong uVar12;
  longlong lVar13;
  longlong lVar14;
  undefined1 auStackY_188 [32];
  undefined8 in_stack_fffffffffffffe98;
  undefined **ppuVar15;
  undefined4 uVar17;
  undefined8 *puVar16;
  undefined8 local_b8;
  uint local_b0;
  uint local_ac;
  uint local_a8;
  int local_a4;
  uint local_a0;
  uint local_9c;
  uint local_98;
  uint local_94;
  uint local_90;
  longlong local_88;
  undefined **local_80;
  longlong local_78;
  undefined **local_70;
  longlong local_68;
  longlong local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  ulonglong local_40;
  
  uVar17 = (undefined4)((ulonglong)in_stack_fffffffffffffe98 >> 0x20);
  local_40 = __security_cookie ^ (ulonglong)auStackY_188;
  local_60 = *(longlong *)(param_1 + 0x120);
  lVar13 = param_3[4];
  uStack_48 = 0;
  *(undefined4 *)param_5 = 0xc0000185;
  local_68 = -1;
  local_50 = 0xffffffff00000000;
  local_ac = 0;
  local_b8._0_1_ = 1;
  local_80 = param_5;
  local_70 = param_6;
  local_b0 = param_4;
  local_88 = param_1;
  local_78 = lVar13;
  local_58 = param_2;
  lVar14 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
  local_b8._5_1_ = '\0';
  local_a4 = 0;
  local_b8._4_1_ = 0;
  if (((*(longlong *)(lVar14 + 8) != 0) &&
      (lVar10 = (**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals), lVar10 != 0)) &&
     (pcVar3 = *(char **)(lVar10 + 0xb8), pcVar3 != (char *)0x0)) {
    local_b8._5_1_ = *pcVar3;
    if (local_b8._5_1_ == '\x0e') {
      local_a4 = *(int *)(pcVar3 + 0x18);
    }
    local_b8._4_1_ = (byte)pcVar3[2] >> 1 & 1;
  }
  if (0 < *(longlong *)(lVar14 + 0x18)) {
    lVar14 = _DAT_fffff78000000320 - *(longlong *)(lVar14 + 0x18);
    uVar8 = KeQueryTimeIncrement();
    local_68 = (ulonglong)uVar8 * lVar14;
  }
  if ((*(uint *)((longlong)param_3 + 0xc) & 0x40000000) != 0) {
    local_50 = CONCAT71(local_50._1_7_,1);
    uStack_48 = CONCAT44(uStack_48._4_4_,0x12d);
    local_50 = CONCAT44(0x80040033,(undefined4)local_50);
  }
  bVar1 = *(byte *)((longlong)param_3 + 3);
  if ((bVar1 & 0xffffff3f) == 0x30) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar17 = 1;
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x3b,
                        &WPP_14ceea506f553d1aa69114b6e3475b08_Traceguids,
                        (char)*(undefined4 *)(param_3 + 8));
    }
    *(undefined4 *)param_5 = *(undefined4 *)(param_3 + 8);
    local_b8._0_1_ = 0;
LAB_140007d2e:
    uVar8 = local_b0;
  }
  else {
    if (*(char *)((longlong)param_3 + 4) == '\x18') {
      local_b8._0_1_ = 0;
      *(undefined4 *)param_5 = 0x80000011;
      local_50 = local_50 & 0xffffffffffffff00;
      goto LAB_140007d2e;
    }
    if (((char)bVar1 < '\0') && (bVar2 = *(byte *)((longlong)param_3 + 0xb), 7 < bVar2)) {
      local_b8._3_1_ = *(byte *)(lVar13 + 2) & 0xf;
      uVar9 = *(byte *)(lVar13 + 7) + 7;
      uVar8 = (uint)bVar2;
      if (uVar9 <= bVar2) {
        uVar8 = uVar9;
      }
      if (uVar8 < 0xd) {
        local_b8._1_1_ = '\0';
LAB_140008327:
        local_b8._2_1_ = '\0';
      }
      else {
        local_b8._1_1_ = *(char *)(lVar13 + 0xc);
        if (uVar8 < 0xe) goto LAB_140008327;
        local_b8._2_1_ = *(char *)(lVar13 + 0xd);
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        local_a8 = bVar1 & 0xffffff3f;
        local_90 = (uint)*(byte *)((longlong)param_3 + 0x57);
        local_9c = (uint)*(byte *)((longlong)param_3 + 0x4a);
        local_98 = (uint)*(byte *)((longlong)param_3 + 0x49);
        local_94 = (uint)*(byte *)(param_3 + 9);
        local_a0 = (uint)*(byte *)((longlong)param_3 + 0x56);
        WPP_RECORDER_SF_DDDDDDDDDDDDDDDDDDDDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
        param_1 = local_88;
        param_6 = local_70;
        lVar13 = local_78;
        param_5 = local_80;
      }
      bVar1 = local_b8._3_1_;
      if (local_b8._3_1_ == 6) {
        LOCK();
        *(int *)(param_1 + 0x148) = *(int *)(param_1 + 0x148) + 1;
        UNLOCK();
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_dL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
        }
      }
      if ((local_60 != 0) && (*(char *)(param_3 + 9) == '\0')) {
        *(byte *)(local_60 + 0x58) = bVar1;
        *(char *)(local_60 + 0x59) = local_b8._1_1_;
        *(char *)(local_60 + 0x5a) = local_b8._2_1_;
      }
      ppuVar15 = param_5;
      uVar11 = SenseInfoInterpretByAdditionalSenseCode
                         (param_1,(longlong)param_3,local_b8._1_1_,local_b8._2_1_,
                          (undefined4 *)param_5,(undefined1 *)&local_b8,&local_ac,(byte *)&local_50)
      ;
      uVar17 = (undefined4)((ulonglong)ppuVar15 >> 0x20);
      if ((char)uVar11 != '\0') {
        puVar16 = &local_b8;
        SenseInfoInterpretBySenseKey
                  (param_1,lVar13,bVar1,(undefined4 *)param_5,(undefined1 *)puVar16,&local_ac,
                   (undefined1 *)&local_50);
        uVar17 = (undefined4)((ulonglong)puVar16 >> 0x20);
      }
      bVar1 = *(byte *)(param_3 + 9);
      if (((bVar1 < 0x30) && ((0x850000000500U >> ((ulonglong)bVar1 & 0x3f) & 1) != 0)) ||
         (((byte)(bVar1 + 0x78) < 0x23 &&
          ((0x500000085U >> ((ulonglong)(byte)(bVar1 + 0x78) & 0x3f) & 1) != 0)))) {
        uVar5 = (undefined4)uStack_48;
        uVar9 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(lVar13 + 3),*(undefined1 *)(lVar13 + 4)),
                                  *(undefined1 *)(lVar13 + 5)),*(undefined1 *)(lVar13 + 6));
        uVar8 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)((longlong)param_3 + 0x4a),
                                           *(undefined1 *)((longlong)param_3 + 0x4b)),
                                  *(undefined1 *)((longlong)param_3 + 0x4c)),
                         *(undefined1 *)((longlong)param_3 + 0x4d));
        uStack_48 = CONCAT44(uVar9,uVar5);
        if ((uVar9 < uVar8) ||
           (CONCAT11(*(undefined1 *)((longlong)param_3 + 0x4f),*(undefined1 *)(param_3 + 10)) +
            uVar8 <= uVar9)) {
          uStack_48 = CONCAT44(uVar8,uVar5);
        }
      }
      goto LAB_140007d2e;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      local_a8 = bVar1 & 0xffffff3f;
      local_94 = (uint)*(byte *)((longlong)param_3 + 0x57);
      local_98 = (uint)*(byte *)((longlong)param_3 + 0x4a);
      local_9c = (uint)*(byte *)((longlong)param_3 + 0x49);
      local_a0 = (uint)*(byte *)(param_3 + 9);
      WPP_RECORDER_SF_DDDDDDDDDDDDDDDDDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
      param_1 = local_88;
      param_6 = local_70;
      lVar13 = local_78;
      param_5 = local_80;
    }
    uVar8 = local_b0;
    puVar16 = &local_b8;
    SenseInfoInterpretBySrbStatus
              (param_1,(longlong)param_3,local_b0,(int *)param_5,(undefined1 *)puVar16,&local_ac,
               (undefined2 *)&local_50);
    uVar17 = (undefined4)((ulonglong)puVar16 >> 0x20);
  }
  *param_6 = (undefined *)((ulonglong)local_ac * 10000000);
  if (*(code **)(param_1 + 0x348) != (code *)0x0) {
    (**(code **)(param_1 + 0x348))(param_1,param_3,param_5,&local_b8);
  }
  bVar1 = local_b8._4_1_;
  SenseInfoInterpretRefineByScsiCommand
            (param_1,(longlong)param_3,uVar8,local_68,local_b8._4_1_,(undefined **)&local_b8,param_5
             ,param_6);
  iVar7 = local_a4;
  cVar6 = local_b8._5_1_;
  if (local_b8._5_1_ == '\x0e') {
    ppuVar15 = param_5;
    SenseInfoInterpretRefineByIoControl
              (param_1,local_a4,bVar1,(undefined1 *)&local_b8,(int *)param_5);
    uVar17 = (undefined4)((ulonglong)ppuVar15 >> 0x20);
  }
  uVar11 = CONCAT44(uVar17,local_b0);
  SenseInfoLogError(param_1,param_3,cVar6,iVar7,(char)local_b0,(int *)param_5,(char *)&local_b8,
                    (char *)&local_50);
  if (*(int *)param_5 < 0) {
    uVar12 = (ulonglong)(byte)local_b8;
    if ((byte)local_b8 != 0) {
      lVar14 = (**(code **)(WdfFunctions_01015 + 0x650))
                         (WdfDriverGlobals,local_58,
                          PTR__WDF_CDROM_REQUEST_CONTEXT_TYPE_INFO_14001a018);
      if ((*(longlong *)(lVar14 + 8) == 0) ||
         (uVar12 = (**(code **)(WdfFunctions_01015 + 0x808))(WdfDriverGlobals), (char)uVar12 == '\0'
         )) goto LAB_140007e45;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar12 = WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,1,0x3f,
                                   &WPP_14ceea506f553d1aa69114b6e3475b08_Traceguids,
                                   (char)*(undefined8 *)(lVar14 + 8));
      }
      uVar12 = uVar12 & 0xffffffffffffff00;
      *(undefined4 *)param_5 = 0xc0000120;
      local_b8._0_1_ = 0;
      *param_6 = (undefined *)0x0;
    }
  }
  else {
LAB_140007e45:
    uVar12 = (ulonglong)(byte)local_b8;
    if ((byte)local_b8 != 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return uVar12;
      }
      puVar4 = *param_6;
      lVar14 = ((longlong)puVar4 / 10000) % 1000;
      lVar13 = ((longlong)
                (puVar4 + SUB168(SEXT816(-0x29406b2a1a85bd43) * SEXT816((longlong)puVar4),8)) >>
               0x17) - ((longlong)
                        (puVar4 + SUB168(SEXT816(-0x29406b2a1a85bd43) * SEXT816((longlong)puVar4),8)
                        ) >> 0x3f);
      WPP_RECORDER_SF_ii(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar13,lVar14,0x40,uVar11,
                         (char)lVar13,(char)lVar14);
      goto LAB_140008186;
    }
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
    return uVar12;
  }
  WPP_RECORDER_SF_DDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,1,0x41,
                      &WPP_14ceea506f553d1aa69114b6e3475b08_Traceguids,*(byte *)(lVar13 + 2) & 0xf,
                      *(undefined1 *)(lVar13 + 0xc),*(undefined1 *)(lVar13 + 0xd));
LAB_140008186:
  return (ulonglong)(byte)local_b8;
}



===== SenseInfoLogError @ 140008400 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SenseInfoLogError(longlong param_1,undefined8 *param_2,undefined1 param_3,undefined4 param_4,
                      undefined1 param_5,int *param_6,char *param_7,char *param_8)

{
  int *piVar1;
  uint *puVar2;
  undefined4 *puVar3;
  void *_Src;
  longlong lVar4;
  undefined1 uVar5;
  uint uVar6;
  undefined8 *puVar7;
  longlong lVar8;
  uint uVar9;
  uint uVar10;
  byte bVar11;
  size_t _Size;
  undefined1 auStack_178 [32];
  uint local_158;
  undefined1 local_150;
  undefined1 uStack_14f;
  short sStack_14e;
  undefined4 uStack_14c;
  undefined4 uStack_148;
  int iStack_144;
  undefined4 local_140;
  int iStack_13c;
  undefined4 uStack_138;
  undefined4 uStack_134;
  longlong local_130;
  undefined8 uStack_128;
  undefined8 local_120;
  undefined8 uStack_118;
  undefined8 local_110;
  undefined8 uStack_108;
  undefined8 local_100;
  undefined8 uStack_f8;
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 local_c8;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined4 local_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_178;
  _Src = (void *)param_2[4];
  uStack_14c = 0;
  uStack_148 = 0;
  uStack_128 = 0;
  uVar10 = 0;
  memset(&uStack_bc,0,0x74);
  sStack_14e = 0xb0;
  _Size = 0x12;
  local_158 = 0xb0;
  if (*(char *)((longlong)param_2 + 3) < '\0') {
    uVar9 = (uint)*(byte *)((longlong)param_2 + 0xb);
    if ((longlong)_Src + (ulonglong)*(byte *)((longlong)param_2 + 0xb) < (longlong)_Src + 8U) {
      uVar10 = uVar9;
    }
    else {
      uVar6 = *(byte *)((longlong)_Src + 7) + 7;
      uVar10 = 0x12;
      if (0x12 < uVar6) {
        uVar10 = uVar6;
      }
      if (uVar9 <= uVar10) {
        uVar10 = uVar9;
      }
    }
    if (0x12 < uVar10) {
      local_158 = uVar10 + 0x9e;
      sStack_14e = (short)local_158;
      if (0xf0 < local_158) {
        sStack_14e = 0xf0;
        uVar10 = 0x52;
        local_158 = 0xf0;
      }
    }
  }
  if (*param_7 == '\0') {
    iStack_13c = *param_6;
    bVar11 = (byte)uStack_bc;
  }
  else {
    iStack_13c = 0;
    bVar11 = (byte)uStack_bc | 2;
  }
  iStack_144 = *(int *)(param_8 + 4);
  if ((iStack_144 == -0x7ffbffcd) && ((*param_7 != '\0' || (-1 < *param_6)))) {
    *param_8 = '\0';
  }
  if ((*(uint *)((longlong)param_2 + 0xc) & 0x40000000) != 0) {
    bVar11 = bVar11 | 1;
  }
  uStack_138 = 0;
  uStack_bc = CONCAT31(uStack_bc._1_3_,(param_8[1] & 1U) << 2 | bVar11 & 0xfb);
  local_130 = (ulonglong)*(uint *)(param_1 + 0x9c) * (ulonglong)*(uint *)(param_8 + 0xc);
  if (iStack_144 == -1) {
    iStack_144 = -0x3ffffe7b;
  }
  uStack_14f = param_5;
  sStack_14e = sStack_14e + -0x30;
  local_140 = *(undefined4 *)(param_8 + 8);
  local_c8 = _DAT_fffff78000000320;
  uStack_c0 = 0xffffffff;
  local_120 = *param_2;
  uStack_118 = param_2[1];
  local_110 = param_2[2];
  uStack_108 = param_2[3];
  local_100 = param_2[4];
  uStack_f8 = param_2[5];
  local_f0 = param_2[6];
  uStack_e8 = param_2[7];
  local_e0 = param_2[8];
  uStack_d8 = param_2[9];
  local_68 = param_2[10];
  local_150 = param_3;
  uStack_134 = param_4;
  local_b8 = local_120;
  uStack_b0 = uStack_118;
  local_a8 = local_110;
  uStack_a0 = uStack_108;
  local_98 = local_100;
  uStack_90 = uStack_f8;
  local_88 = local_f0;
  uStack_80 = uStack_e8;
  local_78 = local_e0;
  uStack_70 = uStack_d8;
  if (uVar10 != 0) {
    if (uVar10 < 0x12) {
      _Size = (size_t)uVar10;
    }
    memmove(&uStack_60,_Src,_Size);
  }
  local_120 = local_b8;
  uStack_118 = uStack_b0;
  local_110 = local_a8;
  uStack_108 = uStack_a0;
  local_100 = local_98;
  uStack_f8 = uStack_90;
  local_f0 = local_88;
  uStack_e8 = uStack_80;
  local_e0 = local_78;
  uStack_d8 = uStack_70;
  uVar5 = KeAcquireSpinLockRaiseToDpc(*(longlong *)(param_1 + 0x478) + 0x28);
  lVar4 = *(longlong *)(param_1 + 0x478);
  lVar8 = (ulonglong)*(uint *)(lVar4 + 0x30) * 0x80;
  puVar7 = (undefined8 *)(lVar8 + 0x38 + lVar4);
  *puVar7 = local_c8;
  puVar7[1] = CONCAT44(uStack_bc,uStack_c0);
  puVar7 = (undefined8 *)(lVar8 + 0x48 + lVar4);
  *puVar7 = local_120;
  puVar7[1] = uStack_118;
  puVar7 = (undefined8 *)(lVar8 + 0x58 + lVar4);
  *puVar7 = local_110;
  puVar7[1] = uStack_108;
  puVar7 = (undefined8 *)(lVar8 + 0x68 + lVar4);
  *puVar7 = local_100;
  puVar7[1] = uStack_f8;
  puVar3 = (undefined4 *)(lVar8 + 0x78 + lVar4);
  *puVar3 = (undefined4)local_f0;
  puVar3[1] = local_f0._4_4_;
  puVar3[2] = (undefined4)uStack_e8;
  puVar3[3] = uStack_e8._4_4_;
  puVar7 = (undefined8 *)(lVar8 + 0x88 + lVar4);
  *puVar7 = local_e0;
  puVar7[1] = uStack_d8;
  puVar7 = (undefined8 *)(lVar8 + 0x98 + lVar4);
  *puVar7 = local_68;
  puVar7[1] = uStack_60;
  puVar3 = (undefined4 *)(lVar8 + 0xa8 + lVar4);
  *puVar3 = local_58;
  puVar3[1] = uStack_54;
  puVar3[2] = uStack_50;
  puVar3[3] = uStack_4c;
  piVar1 = (int *)(*(longlong *)(param_1 + 0x478) + 0x30);
  *piVar1 = *piVar1 + 1;
  puVar2 = (uint *)(*(longlong *)(param_1 + 0x478) + 0x30);
  *puVar2 = *puVar2 & 0xf;
  KeReleaseSpinLock(*(longlong *)(param_1 + 0x478) + 0x28,uVar5);
  if (*param_8 == '\0') {
    return;
  }
  if (*(char *)(param_2 + 9) == '\0') {
    if (*(char *)(*(longlong *)(param_1 + 0x478) + 0x21) == '\0') {
      *(undefined1 *)(*(longlong *)(param_1 + 0x478) + 0x21) = 1;
      goto LAB_140008777;
    }
  }
  else {
    if (*(char *)(param_2 + 9) != '5') goto LAB_140008777;
    if (*(char *)(*(longlong *)(param_1 + 0x478) + 0x22) == '\0') {
      *(undefined1 *)(*(longlong *)(param_1 + 0x478) + 0x22) = 1;
      goto LAB_140008777;
    }
  }
  *param_8 = '\0';
LAB_140008777:
  if ((((uVar10 < 0xf) || ((*(byte *)((longlong)_Src + 2) & 0xf) != 5)) ||
      (*(char *)((longlong)_Src + 0xc) != '!')) ||
     ((*(char *)((longlong)_Src + 0xd) != '\0' || ((*(char *)(param_2 + 9) - 8U & 0x5f) != 0)))) {
    if (*param_8 != '\0') {
      puVar7 = (undefined8 *)
               IoAllocateErrorLogEntry(*(undefined8 *)(param_1 + 0x40),(undefined1)local_158);
      if (puVar7 != (undefined8 *)0x0) {
        *puVar7 = CONCAT44(uStack_14c,CONCAT22(sStack_14e,CONCAT11(uStack_14f,local_150)));
        puVar7[1] = CONCAT44(iStack_144,uStack_148);
        puVar7[2] = CONCAT44(iStack_13c,local_140);
        puVar7[3] = CONCAT44(uStack_134,uStack_138);
        puVar7[4] = local_130;
        puVar7[5] = uStack_128;
        puVar7[5] = local_c8;
        puVar7[6] = CONCAT44(uStack_bc,uStack_c0);
        puVar7[7] = local_120;
        puVar7[8] = uStack_118;
        puVar7[9] = local_110;
        puVar7[10] = uStack_108;
        puVar7[0xb] = local_100;
        puVar7[0xc] = uStack_f8;
        puVar7[0xd] = local_f0;
        puVar7[0xe] = uStack_e8;
        puVar7[0xf] = local_e0;
        puVar7[0x10] = uStack_d8;
        puVar7[0x11] = local_68;
        puVar7[0x12] = uStack_60;
        *(undefined4 *)(puVar7 + 0x13) = local_58;
        *(undefined4 *)((longlong)puVar7 + 0x9c) = uStack_54;
        *(undefined4 *)(puVar7 + 0x14) = uStack_50;
        *(undefined4 *)((longlong)puVar7 + 0xa4) = uStack_4c;
        if (uVar10 != 0) {
          memmove(puVar7 + 0x12,_Src,(ulonglong)uVar10);
        }
        IoWriteErrorLogEntry(puVar7);
      }
    }
  }
  else {
    *param_8 = '\0';
  }
  return;
}



===== SenseInfoInterpretRefineByScsiCommand @ 140008870 =====

undefined **
SenseInfoInterpretRefineByScsiCommand
          (longlong param_1,longlong param_2,uint param_3,longlong param_4,char param_5,
          undefined **param_6,undefined **param_7,undefined **param_8)

{
  ulonglong *puVar1;
  int iVar2;
  longlong lVar3;
  byte bVar4;
  uint uVar5;
  undefined **ppuVar6;
  undefined *puVar7;
  undefined **ppuVar8;
  
  bVar4 = *(byte *)(param_2 + 0x48);
  ppuVar6 = (undefined **)(ulonglong)bVar4;
  lVar3 = *(longlong *)(param_2 + 0x20);
  if (bVar4 == 0x1e) {
    if ((((*(char *)(param_2 + 0x49) == '\0') && (*(char *)(param_2 + 0x4a) == '\0')) &&
        (*(char *)(param_2 + 0x4b) == '\0')) && ((*(byte *)(param_2 + 0x4c) & 0xfc) == 0)) {
      if ((*(byte *)(param_2 + 0x4c) & 1) == 0) {
        if (param_3 < 4) {
          *(undefined1 *)param_6 = 1;
        }
      }
      else if (1 < param_3) {
        *(undefined1 *)param_6 = 0;
      }
    }
    if (((*(int *)param_7 != -0x3fffff5d) || (*(char *)(lVar3 + 0xc) != '\x04')) &&
       (uVar5 = *(byte *)(param_2 + 3) & 0xffffff3f, (char)uVar5 != '\n')) {
      return (undefined **)(ulonglong)uVar5;
    }
    ppuVar6 = (undefined **)*param_8;
    ppuVar8 = (undefined **)0x1312d00;
    if (20000000 < (longlong)ppuVar6) {
      ppuVar8 = ppuVar6;
    }
    *param_8 = (undefined *)ppuVar8;
    return ppuVar6;
  }
  if ((bVar4 - 0x1a & 0xbf) != 0) {
    if ((bVar4 == 0x25) || (bVar4 == 0x9e)) {
      if (*(int *)param_7 == -0x7fffffea) {
        *(undefined1 *)param_6 = 1;
      }
      if (param_3 < 2) {
        return param_7;
      }
      goto LAB_1400088f1;
    }
    if ((byte)(bVar4 - 0x16) < 2) {
      if (*(int *)param_7 == -0x3ffffff0) {
        *(undefined1 *)(param_2 + 10) = 10;
        *(char *)(param_2 + 0x48) = (bVar4 != 0x16) + 'V';
        puVar1 = (ulonglong *)(*(longlong *)(param_1 + 0x478) + 0x10);
        *puVar1 = *puVar1 | 8;
        *(undefined1 *)param_6 = 1;
        return param_6;
      }
      return ppuVar6;
    }
    if ((bVar4 - 8 & 0x5d) != 0) {
      if (bVar4 == 0xac) {
        uVar5 = *(byte *)(param_2 + 3) & 0xffffff3f;
        ppuVar6 = (undefined **)(ulonglong)uVar5;
        if ((char)uVar5 == '\x12') {
          *(undefined4 *)param_7 = 0;
          *(undefined1 *)param_6 = 0;
          ppuVar6 = param_7;
        }
        if ((*(byte *)(param_2 + 0xb) < 0xe) || (-1 < *(char *)(param_2 + 3))) {
          uVar5 = *(byte *)(param_2 + 3) & 0xffffff3f;
          ppuVar6 = (undefined **)(ulonglong)uVar5;
          if ((uVar5 != 1) &&
             ((uVar5 != 0x12 &&
              (bVar4 = *(byte *)(param_2 + 0x49) & 3, ppuVar6 = (undefined **)(ulonglong)bVar4,
              bVar4 == 2)))) {
            ppuVar6 = &WPP_RECORDER_INITIALIZED;
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              ppuVar6 = (undefined **)
                        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,1,0x39,
                                         &WPP_14ceea506f553d1aa69114b6e3475b08_Traceguids);
            }
            *(ulonglong *)(param_1 + 0x340) = *(ulonglong *)(param_1 + 0x340) | 0x800;
            *(undefined1 *)param_6 = 1;
          }
        }
        if (param_3 < 5) {
          return ppuVar6;
        }
        *(undefined1 *)param_6 = 0;
        return ppuVar6;
      }
      if (param_3 < 5) {
        return ppuVar6;
      }
      goto LAB_1400088c9;
    }
    if ((param_5 != '\0') && (*(int *)param_7 == -0x7fffffea)) {
      *(undefined4 *)param_7 = 0xc0000185;
      *(undefined1 *)param_6 = 1;
    }
    if (bVar4 == 0xa8) {
      bVar4 = *(byte *)(param_2 + 0x52);
joined_r0x000140008aaf:
      ppuVar6 = (undefined **)(ulonglong)bVar4;
      if ((char)bVar4 < '\0') {
        uVar5 = *(byte *)(param_2 + 3) & 0xffffff3f;
        if ((2 < uVar5 - 9) && (uVar5 != 0xe)) {
          bVar4 = *(byte *)(lVar3 + 2) & 0xf;
          param_7 = (undefined **)(ulonglong)bVar4;
          if (bVar4 == 6) {
            bVar4 = *(byte *)(lVar3 + 0xc);
            param_7 = (undefined **)(ulonglong)bVar4;
            if ((bVar4 != 0x29) && (bVar4 != 0x2e)) {
LAB_1400088f1:
              *(undefined1 *)param_6 = 0;
              return param_7;
            }
          }
          else if ((bVar4 != 5) || (*(char *)(lVar3 + 0xc) == '!')) goto LAB_1400088f1;
        }
        puVar1 = (ulonglong *)(*(longlong *)(param_1 + 0x478) + 0x10);
        *puVar1 = *puVar1 | 0x20;
        *(undefined1 *)param_6 = 1;
        goto LAB_140008b1a;
      }
    }
    else if (bVar4 == 0xaa) {
      bVar4 = *(byte *)(param_2 + 0x52);
      goto joined_r0x000140008aaf;
    }
    if (*(char *)param_6 == '\0') {
      return ppuVar6;
    }
LAB_140008b1a:
    if ((param_4 < 0) || (((*(byte *)(lVar3 + 2) & 0xf) == 4 && (*(char *)(lVar3 + 0xc) == '\t'))))
    {
      *(bool *)param_6 = param_3 < 5;
    }
    else if (1600000000 < param_4) {
      *(undefined1 *)param_6 = 0;
    }
    *param_8 = *(undefined **)(param_1 + 0x3c8);
    return param_8;
  }
  iVar2 = *(int *)param_7;
  if ((iVar2 == -0x3fffff5d) && (*(char *)(lVar3 + 0xc) == '\x04')) {
    puVar7 = (undefined *)0x1312d00;
    if (20000000 < (longlong)*param_8) {
      puVar7 = *param_8;
    }
    *param_8 = puVar7;
LAB_140008bbe:
    uVar5 = *(byte *)(param_2 + 3) & 0xffffff3f;
    ppuVar6 = (undefined **)(ulonglong)uVar5;
    if ((char)uVar5 == '\x12') {
      *(undefined4 *)param_7 = 0;
      *(undefined1 *)param_6 = 0;
    }
  }
  else {
    uVar5 = *(byte *)(param_2 + 3) & 0xffffff3f;
    ppuVar6 = (undefined **)(ulonglong)uVar5;
    if ((char)uVar5 == '\n') {
      ppuVar6 = (undefined **)*param_8;
      ppuVar8 = (undefined **)0x1312d00;
      if (20000000 < (longlong)ppuVar6) {
        ppuVar8 = ppuVar6;
      }
      *param_8 = (undefined *)ppuVar8;
    }
    if (iVar2 != -0x7fffffea) goto LAB_140008bbe;
    *(undefined1 *)param_6 = 1;
  }
  if (param_3 < 2) {
    return ppuVar6;
  }
LAB_1400088c9:
  *(undefined1 *)param_6 = 0;
  return ppuVar6;
}



===== SenseInfoInterpretByAdditionalSenseCode @ 140008c10 =====

undefined8
SenseInfoInterpretByAdditionalSenseCode
          (longlong param_1,longlong param_2,char param_3,char param_4,undefined4 *param_5,
          undefined1 *param_6,undefined4 *param_7,byte *param_8)

{
  byte bVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  undefined1 uVar5;
  int iVar6;
  undefined8 uVar7;
  longlong lVar8;
  longlong lVar9;
  undefined4 uVar10;
  undefined8 local_res10;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  
  puVar4 = param_7;
  puVar3 = param_6;
  puVar2 = param_5;
  uVar10 = 0xc0000185;
  lVar8 = *(longlong *)(param_2 + 0x20);
  *param_5 = 0xc0000185;
  *param_6 = 1;
  *param_7 = 0;
  local_res10 = param_2;
  if (param_3 == ':') {
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x1c,
                       &WPP_14ceea506f553d1aa69114b6e3475b08_Traceguids);
    }
    *puVar2 = 0xc0000013;
    *puVar3 = 0;
    lVar8 = *(longlong *)(param_1 + 0x118);
    param_5 = (undefined4 *)0x0;
    if (param_4 == -0x34) {
      if (lVar8 == 0) {
        return 0;
      }
      iVar6 = KeWaitForSingleObject(lVar8 + 8,0,0,0,&param_5);
      if (iVar6 == 0x102) {
        return 0;
      }
      lVar9 = *(longlong *)(param_1 + 0x118);
      if (((lVar9 == 0) || (*(undefined4 *)(lVar9 + 0x48) = 3, *(int *)(lVar9 + 0x50) != 0)) ||
         (*(int *)(lVar9 + 0x4c) == 3)) goto LAB_140008d99;
      local_res10 = CONCAT44(3,*(undefined4 *)(param_1 + 0x148));
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
LAB_1400096a1:
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,0xd,0x1c,
                         &WPP_bfcef3ce16aa3c5196ed71474c974d5c_Traceguids);
      }
    }
    else {
      if (lVar8 == 0) {
        return 0;
      }
      iVar6 = KeWaitForSingleObject(lVar8 + 8,0,0,0,&param_5);
      if (iVar6 == 0x102) {
        return 0;
      }
      lVar9 = *(longlong *)(param_1 + 0x118);
      if (((lVar9 == 0) || (*(undefined4 *)(lVar9 + 0x48) = 2, *(int *)(lVar9 + 0x50) != 0)) ||
         (*(int *)(lVar9 + 0x4c) == 2)) goto LAB_140008d99;
      local_res10 = CONCAT44(2,*(undefined4 *)(param_1 + 0x148));
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) goto LAB_1400096a1;
    }
    DeviceSendNotification(param_1,(undefined4 *)&GUID_IO_MEDIA_REMOVAL,8,&local_res10);
    *(undefined4 *)(lVar9 + 0x4c) = *(undefined4 *)(lVar9 + 0x48);
LAB_140008d99:
    KeReleaseMutex(lVar8 + 8,0);
    return 0;
  }
  switch(param_3) {
  case '\x02':
    if (param_4 == '\0') {
      *param_5 = 0xc000009c;
      *param_6 = 1;
      *param_8 = 1;
      param_8[8] = 0;
      param_8[9] = 1;
      param_8[10] = 0;
      param_8[0xb] = 0;
      param_8[4] = 7;
      param_8[5] = 0;
      param_8[6] = 4;
      param_8[7] = 0xc0;
      return 0;
    }
  default:
    goto switchD_140008df1_caseD_3;
  case '\x04':
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,1,0x15,
                       &WPP_14ceea506f553d1aa69114b6e3475b08_Traceguids);
    }
    if (param_4 == '\a') {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x16,
                         &WPP_14ceea506f553d1aa69114b6e3475b08_Traceguids);
      }
      local_34 = 2;
LAB_140008e52:
      *puVar3 = 1;
      uVar7 = 0;
      *puVar2 = 0xc00000a3;
      local_38 = 1;
      *puVar4 = 10;
      local_30 = 100;
      DeviceSendNotification(param_1,(undefined4 *)&GUID_IO_DEVICE_BECOMING_READY,0xc,&local_38);
    }
    else {
      switch(param_4) {
      default:
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x1b,
                           &WPP_14ceea506f553d1aa69114b6e3475b08_Traceguids);
        }
        *puVar2 = 0xc00000a3;
        uVar7 = 0;
        *puVar3 = 1;
        bVar1 = *(byte *)(param_1 + 0x6c);
        *puVar4 = 0;
        if (((bVar1 & 4) != 0) && ((*(uint *)(local_res10 + 0xc) & 0x10000000) == 0)) {
          DeviceSendStartUnit(*(undefined8 *)(param_1 + 0x10));
        }
        break;
      case '\x01':
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x17,
                           &WPP_14ceea506f553d1aa69114b6e3475b08_Traceguids);
        }
        local_34 = 1;
        goto LAB_140008e52;
      case '\x03':
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x19,
                           &WPP_14ceea506f553d1aa69114b6e3475b08_Traceguids);
        }
        uVar7 = 0;
        *puVar2 = 0xc0000013;
        *puVar3 = 0;
        *puVar4 = 10;
        break;
      case '\x04':
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x1a,
                           &WPP_14ceea506f553d1aa69114b6e3475b08_Traceguids);
        }
        uVar7 = 0;
        *puVar2 = 0xc00000a3;
        *puVar3 = 0;
        *puVar4 = 10;
        break;
      case '\b':
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x18,
                           &WPP_14ceea506f553d1aa69114b6e3475b08_Traceguids);
        }
        *puVar2 = 0xc00000a3;
        uVar7 = 0;
        *puVar3 = 1;
        *puVar4 = 0;
      }
    }
    break;
  case '\b':
    if (param_4 == '\x03') {
      *param_5 = 0xc0000185;
      *param_6 = 1;
      *param_7 = 1;
      *param_8 = 1;
      param_8[8] = 1;
      param_8[9] = 1;
      param_8[10] = 0;
      param_8[0xb] = 0;
      param_8[4] = 0xb;
      param_8[5] = 0;
      param_8[6] = 4;
      param_8[7] = 0xc0;
      return 0;
    }
    goto switchD_140008df1_caseD_3;
  case '\x17':
  case '\x18':
    *param_5 = 0;
    *param_6 = 0;
    bVar1 = *(byte *)(lVar8 + 2);
    *param_8 = 1;
    param_8[8] = 2;
    param_8[9] = 1;
    param_8[10] = 0;
    param_8[0xb] = 0;
    param_8[4] = 0x21;
    param_8[5] = 0;
    param_8[6] = 4;
    param_8[7] = 0x80;
    if ((bVar1 & 0x20) == 0) {
      return 0;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x2a,
                       &WPP_14ceea506f553d1aa69114b6e3475b08_Traceguids);
    }
    goto LAB_1400095ca;
  case '!':
    uVar7 = 0;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x1d,
                       &WPP_14ceea506f553d1aa69114b6e3475b08_Traceguids);
    }
    *puVar2 = 0xc0000015;
    *puVar3 = 0;
    break;
  case '$':
    uVar7 = 0;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x26,
                       &WPP_14ceea506f553d1aa69114b6e3475b08_Traceguids);
    }
    *puVar2 = 0xc0000010;
    *puVar3 = 0;
    *puVar4 = 3;
    break;
  case '%':
    uVar7 = 0;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x1e,
                       &WPP_14ceea506f553d1aa69114b6e3475b08_Traceguids);
    }
    *puVar2 = 0xc000000e;
    *puVar3 = 0;
    break;
  case '(':
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,0xd,0x27,
                       &WPP_14ceea506f553d1aa69114b6e3475b08_Traceguids);
    }
    DeviceSetMediaChangeStateEx(param_1,1,(int *)0x0);
    lVar8 = *(longlong *)(param_1 + 0x40);
    uVar7 = IsVolumeMounted(lVar8);
    if ((char)uVar7 == '\0') {
LAB_140009449:
      uVar5 = 1;
    }
    else {
      *(uint *)(lVar8 + 0x30) = *(uint *)(lVar8 + 0x30) | 2;
      uVar10 = 0x80000016;
      uVar5 = 0;
    }
    goto LAB_140009459;
  case '0':
    if (param_4 == '\x01') {
      *param_5 = 0xc0000014;
      *param_6 = 0;
      uVar10 = *(undefined4 *)(param_2 + 0xc);
      param_8[8] = 0;
      param_8[9] = 1;
      param_8[10] = 0;
      param_8[0xb] = 0;
      *param_8 = (byte)((uint)uVar10 >> 0x1e) & 1;
      param_8[4] = 7;
      param_8[5] = 0;
      param_8[6] = 4;
      param_8[7] = 0xc0;
      return 0;
    }
    if (param_4 == '\x02') {
      *param_5 = 0xc0000014;
      *param_6 = 0;
      *param_8 = 0;
      return 0;
    }
    if (param_4 == '\x03') {
      *param_5 = 0x80000027;
      *param_6 = 0;
      *param_8 = 0;
      param_8[8] = 0;
      param_8[9] = 1;
      param_8[10] = 0;
      param_8[0xb] = 0;
      param_8[4] = 7;
      param_8[5] = 0;
      param_8[6] = 4;
      param_8[7] = 0xc0;
      return 0;
    }
    goto switchD_140008df1_caseD_3;
  case '?':
    *param_7 = 5;
    LOCK();
    *(int *)(param_1 + 0x148) = *(int *)(param_1 + 0x148) + 1;
    UNLOCK();
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x29,
                       &WPP_14ceea506f553d1aa69114b6e3475b08_Traceguids);
    }
    IoInvalidateDeviceRelations(*(undefined8 *)(param_1 + 0x48),0);
    lVar8 = *(longlong *)(param_1 + 0x40);
    uVar7 = IsVolumeMounted(lVar8);
    if ((char)uVar7 == '\0') goto LAB_140009449;
    *(uint *)(lVar8 + 0x30) = *(uint *)(lVar8 + 0x30) | 2;
    uVar10 = 0x80000016;
    uVar5 = 0;
LAB_140009459:
    uVar7 = 0;
    *puVar2 = uVar10;
    *puVar3 = uVar5;
    break;
  case 'W':
    if (param_4 == '\0') {
      *param_5 = 0xc0000014;
      *param_6 = 0;
      return 0;
    }
    goto switchD_140008df1_caseD_3;
  case 'Z':
    if (param_4 == '\x01') {
      LOCK();
      *(int *)(param_1 + 0x148) = *(int *)(param_1 + 0x148) + 1;
      UNLOCK();
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x28,
                         &WPP_14ceea506f553d1aa69114b6e3475b08_Traceguids);
      }
      DeviceSendNotification(param_1,(undefined4 *)&GUID_IO_MEDIA_EJECT_REQUEST,0,(void *)0x0);
      lVar8 = *(longlong *)(param_1 + 0x40);
      uVar7 = IsVolumeMounted(lVar8);
      if ((char)uVar7 == '\0') {
        *puVar2 = 0xc0000185;
        *puVar3 = 1;
        return 0;
      }
      *(uint *)(lVar8 + 0x30) = *(uint *)(lVar8 + 0x30) | 2;
      *puVar2 = 0x80000016;
      *puVar3 = 0;
      return 0;
    }
switchD_140008df1_caseD_3:
    uVar7 = 1;
    break;
  case ']':
    *param_5 = 0;
    *param_6 = 0;
    bVar1 = *(byte *)(lVar8 + 2);
    param_8[8] = 2;
    param_8[9] = 1;
    param_8[10] = 0;
    param_8[0xb] = 0;
    *param_8 = 1;
    param_8[4] = 0x34;
    param_8[5] = 0;
    param_8[6] = 4;
    param_8[7] = 0x80;
    if ((bVar1 & 0x20) == 0) {
      return 0;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x2b,
                       &WPP_14ceea506f553d1aa69114b6e3475b08_Traceguids);
      *puVar2 = 0xc0000173;
      return 0;
    }
LAB_1400095ca:
    uVar7 = 0;
    *puVar2 = 0xc0000173;
    break;
  case 'o':
    uVar7 = 0;
    *param_6 = 0;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x1f,
                       &WPP_14ceea506f553d1aa69114b6e3475b08_Traceguids);
    }
    switch(param_4) {
    case '\0':
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x20,
                         &WPP_14ceea506f553d1aa69114b6e3475b08_Traceguids);
      }
      *puVar2 = 0xc0000306;
      break;
    case '\x01':
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x21,
                         &WPP_14ceea506f553d1aa69114b6e3475b08_Traceguids);
      }
      *puVar2 = 0xc0000307;
      break;
    case '\x02':
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x22,
                         &WPP_14ceea506f553d1aa69114b6e3475b08_Traceguids);
      }
      *puVar2 = 0xc0000308;
      break;
    case '\x03':
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x23,
                         &WPP_14ceea506f553d1aa69114b6e3475b08_Traceguids);
      }
      *puVar2 = 0xc0000309;
      break;
    case '\x04':
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x24,
                         &WPP_14ceea506f553d1aa69114b6e3475b08_Traceguids);
      }
      *puVar2 = 0xc000030a;
      break;
    case '\x05':
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x25,
                         &WPP_14ceea506f553d1aa69114b6e3475b08_Traceguids);
      }
      *puVar2 = 0xc000030b;
      break;
    default:
      *puVar2 = 0xc0000305;
    }
  }
  return uVar7;
}



===== SenseInfoInterpretBySenseKey @ 1400096f4 =====

void SenseInfoInterpretBySenseKey
               (longlong param_1,longlong param_2,byte param_3,undefined4 *param_4,
               undefined1 *param_5,undefined4 *param_6,undefined1 *param_7)

{
  byte bVar1;
  undefined8 uVar2;
  longlong lVar3;
  undefined1 uVar4;
  undefined4 uVar5;
  
  uVar4 = 0;
  uVar5 = 0xc0000185;
  *param_4 = 0xc0000185;
  *param_5 = 1;
  *param_6 = 0;
  if (param_3 == 5) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x30,
                       &WPP_14ceea506f553d1aa69114b6e3475b08_Traceguids);
    }
    *param_4 = 0xc0000010;
LAB_140009b87:
    *param_5 = uVar4;
  }
  else {
    if (param_3 < 6) {
      if (param_3 == 0) {
        if ((*(byte *)(param_2 + 2) & 0x20) == 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,1,0x37,
                             &WPP_14ceea506f553d1aa69114b6e3475b08_Traceguids);
          }
          uVar4 = 1;
        }
        else {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x36,
                             &WPP_14ceea506f553d1aa69114b6e3475b08_Traceguids);
          }
          uVar5 = 0xc0000173;
          uVar4 = 0;
        }
        *param_4 = uVar5;
        goto LAB_140009b87;
      }
      if (param_3 == 1) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x34,
                           &WPP_14ceea506f553d1aa69114b6e3475b08_Traceguids);
        }
        *param_4 = 0;
        *param_5 = 0;
        bVar1 = *(byte *)(param_2 + 2);
        *param_7 = 1;
        *(undefined4 *)(param_7 + 8) = 0x102;
        *(undefined4 *)(param_7 + 4) = 0xc004000b;
        if ((bVar1 & 0x20) == 0) {
          return;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x35,
                           &WPP_14ceea506f553d1aa69114b6e3475b08_Traceguids);
        }
        *param_4 = 0xc0000173;
        return;
      }
      if (param_3 != 2) {
        if (param_3 == 3) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x2e,
                             &WPP_14ceea506f553d1aa69114b6e3475b08_Traceguids);
          }
          *param_4 = 0xc000009c;
          *param_5 = 0;
          *param_7 = 1;
          *(undefined4 *)(param_7 + 8) = 0x100;
          *(undefined4 *)(param_7 + 4) = 0xc0040007;
          return;
        }
        if (param_3 == 4) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x2f,
                             &WPP_14ceea506f553d1aa69114b6e3475b08_Traceguids);
          }
          *param_7 = 1;
          *(undefined4 *)(param_7 + 8) = 0x101;
          *(undefined4 *)(param_7 + 4) = 0xc004000b;
        }
        else {
LAB_140009a1d:
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x38,
                             &WPP_14ceea506f553d1aa69114b6e3475b08_Traceguids);
          }
          *param_6 = 0;
        }
        goto LAB_1400097cb;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x2c,
                         &WPP_14ceea506f553d1aa69114b6e3475b08_Traceguids);
      }
      *param_4 = 0xc00000a3;
      *param_6 = 0;
    }
    else {
      if (param_3 == 6) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x31,
                           &WPP_14ceea506f553d1aa69114b6e3475b08_Traceguids);
        }
        LOCK();
        *(int *)(param_1 + 0x148) = *(int *)(param_1 + 0x148) + 1;
        UNLOCK();
        lVar3 = *(longlong *)(param_1 + 0x40);
        uVar2 = IsVolumeMounted(lVar3);
        if ((char)uVar2 != '\0') {
          *(uint *)(lVar3 + 0x30) = *(uint *)(lVar3 + 0x30) | 2;
          *param_4 = 0x80000016;
          goto LAB_140009b87;
        }
      }
      else {
        if (param_3 == 7) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,1,0x2d,
                             &WPP_14ceea506f553d1aa69114b6e3475b08_Traceguids);
          }
          *param_4 = 0xc00000a2;
          goto LAB_140009b87;
        }
        if (param_3 == 8) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,1,0x33,
                             &WPP_14ceea506f553d1aa69114b6e3475b08_Traceguids);
          }
          *param_5 = 0;
          *param_4 = 0x80000022;
          return;
        }
        if (param_3 != 0xb) goto LAB_140009a1d;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x32,
                           &WPP_14ceea506f553d1aa69114b6e3475b08_Traceguids);
        }
        *param_6 = 1;
      }
LAB_1400097cb:
      *param_4 = 0xc0000185;
    }
    *param_5 = 1;
  }
  return;
}



===== SenseInfoInterpretBySrbStatus @ 140009b98 =====

void SenseInfoInterpretBySrbStatus
               (longlong param_1,longlong param_2,uint param_3,int *param_4,undefined1 *param_5,
               undefined4 *param_6,undefined2 *param_7)

{
  uint uVar1;
  byte bVar2;
  bool bVar3;
  
  *param_4 = -0x3ffffe7b;
  bVar3 = false;
  *param_5 = 1;
  bVar2 = *(byte *)(param_2 + 3);
  *param_6 = 0;
  bVar2 = bVar2 & 0x3f;
  if (bVar2 < 0xf) {
    if (bVar2 == 0xe) {
LAB_140009d36:
      *param_4 = -0x3ffffe7b;
      *param_5 = 1;
LAB_140009d3c:
      if (!bVar3) {
        return;
      }
    }
    else {
      if (bVar2 != 2) {
        if (bVar2 == 4) {
          *param_4 = -0x3ffffe7b;
          *param_5 = 1;
          bVar3 = *(char *)(param_2 + 4) == '\0';
          if (*(char *)(param_2 + 4) == '\b') {
            *param_4 = -0x3fffff5d;
          }
          goto LAB_140009d3c;
        }
        if (bVar2 == 6) {
          *param_4 = -0x3ffffff0;
          goto LAB_140009c66;
        }
        if ((bVar2 == 7) || (bVar2 == 8)) goto LAB_140009d27;
        if (bVar2 != 9) {
          if (bVar2 == 10) {
            *param_4 = -0x3fffff63;
            *param_5 = 0;
            *param_6 = 2;
            *(undefined1 *)param_7 = 1;
            *(undefined4 *)(param_7 + 2) = 0xc004000f;
            *(undefined4 *)(param_7 + 4) = 0x104;
            return;
          }
          if (bVar2 != 0xb) goto LAB_140009cc9;
        }
      }
      *param_4 = -0x3fffff4b;
      *param_5 = 1;
    }
LAB_140009d41:
    *param_6 = 1;
    DevicePerfIncrementErrorCount(param_1);
  }
  else {
    if (bVar2 == 0xf) {
LAB_140009d33:
      bVar3 = true;
      goto LAB_140009d36;
    }
    if (bVar2 == 0x11) {
LAB_140009d27:
      *param_4 = -0x3ffffff2;
    }
    else {
      if (bVar2 != 0x12) {
        if (bVar2 == 0x13) goto LAB_140009d33;
        if (bVar2 != 0x14) {
          if (bVar2 == 0x16) {
            uVar1 = *(uint *)(*(longlong *)(param_1 + 0x40) + 0x30) & 2;
            *param_4 = (-(uint)(uVar1 != 0) & 0xbffffe91) + 0xc0000185;
            *param_5 = uVar1 == 0;
            return;
          }
          if ((bVar2 != 0x20) && (bVar2 != 0x21)) {
LAB_140009cc9:
            *param_4 = -0x3ffffe7b;
            *param_5 = 1;
            *param_7 = 0x101;
            *(undefined4 *)(param_7 + 2) = 0xc004000b;
            *(undefined4 *)(param_7 + 4) = 0x103;
            return;
          }
          goto LAB_140009d27;
        }
        *param_4 = -0x3ffffe7b;
        *param_5 = param_3 < 2;
        goto LAB_140009d41;
      }
      *param_4 = -0x3fffffc4;
    }
LAB_140009c66:
    *param_5 = 0;
  }
  return;
}



===== WPP_RECORDER_SF_DDDDDDDDDDDDDDDDDDDDd @ 140009d70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_DDDDDDDDDDDDDDDDDDDDd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  undefined1 uStack0000000000000068;
  undefined1 uStack0000000000000070;
  undefined1 uStack0000000000000078;
  undefined1 uStack0000000000000080;
  undefined1 uStack0000000000000088;
  undefined1 uStack0000000000000090;
  undefined1 uStack0000000000000098;
  undefined1 uStack00000000000000a0;
  undefined1 uStack00000000000000a8;
  undefined1 uStack00000000000000b0;
  undefined1 uStack00000000000000b8;
  undefined1 uStack00000000000000c0;
  undefined1 uStack00000000000000c8;
  undefined1 uStack00000000000000d0;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (2 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_14ceea506f553d1aa69114b6e3475b08_Traceguids,0x3c,&uStack0000000000000030,4,
               &uStack0000000000000038,4,&uStack0000000000000040,4,&uStack0000000000000048,4,
               &uStack0000000000000050,4,&uStack0000000000000058,4,&uStack0000000000000060,4,
               &uStack0000000000000068,4,&uStack0000000000000070,4,&uStack0000000000000078,4,
               &uStack0000000000000080,4,&uStack0000000000000088,4,&uStack0000000000000090,4,
               &uStack0000000000000098,4,&uStack00000000000000a0,4,&uStack00000000000000a8,4,
               &uStack00000000000000b0,4,&uStack00000000000000b8,4,&uStack00000000000000c0,4,
               &uStack00000000000000c8,4,&uStack00000000000000d0,4,0);
  }
  WppAutoLogTrace(param_1,3,1,&WPP_14ceea506f553d1aa69114b6e3475b08_Traceguids,0x3c,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,
                  &uStack0000000000000060,4,&uStack0000000000000068,4,&uStack0000000000000070,4,
                  &uStack0000000000000078,4,&uStack0000000000000080,4,&uStack0000000000000088,4,
                  &uStack0000000000000090,4,&uStack0000000000000098,4,&uStack00000000000000a0,4,
                  &uStack00000000000000a8,4,&uStack00000000000000b0,4,&uStack00000000000000b8,4,
                  &uStack00000000000000c0,4,&uStack00000000000000c8,4,&uStack00000000000000d0,4,0);
  return;
}



===== WPP_RECORDER_SF_ @ 14000a1e0 =====

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



===== DeviceSendNotification @ 14000a2b8 =====

void DeviceSendNotification(longlong param_1,undefined4 *param_2,uint param_3,void *param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined2 *_Dst;
  uint uVar4;
  
  uVar4 = param_3 + 0x27;
  if (uVar4 < 0x27) {
    uVar4 = 0xffffffff;
  }
  else if (uVar4 < 0x10000) {
    _Dst = (undefined2 *)ExAllocatePool2(0x40,uVar4,0x6f436353);
    if (_Dst == (undefined2 *)0x0) {
      return;
    }
    memset(_Dst,0,(ulonglong)uVar4);
    *(undefined8 *)(_Dst + 0xc) = 0;
    *(undefined4 *)(_Dst + 0x10) = 0xffffffff;
    *_Dst = 1;
    _Dst[1] = (short)uVar4;
    uVar1 = param_2[1];
    uVar2 = param_2[2];
    uVar3 = param_2[3];
    *(undefined4 *)(_Dst + 2) = *param_2;
    *(undefined4 *)(_Dst + 4) = uVar1;
    *(undefined4 *)(_Dst + 6) = uVar2;
    *(undefined4 *)(_Dst + 8) = uVar3;
    if (param_4 != (void *)0x0) {
      memmove(_Dst + 0x12,param_4,(ulonglong)param_3);
    }
    IoReportTargetDeviceChangeAsynchronous(*(undefined8 *)(param_1 + 0x48),_Dst,0,0);
    ExFreePoolWithTag(_Dst,0);
    return;
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,0xd,0x11,
                      &WPP_8ec010589a13368bcaefd70a9b2ee310_Traceguids,(char)uVar4);
  }
  return;
}



===== WPP_RECORDER_SF_qqd @ 14000a3f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqd(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                        undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,
               &WPP_d2ddb5c132d1335dbff1b624de01ec23_Traceguids,param_4,&param_6,8,&param_7,8,
               &param_8,4,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,&WPP_d2ddb5c132d1335dbff1b624de01ec23_Traceguids,param_4,
                  &param_6,8,&param_7,8,&param_8,4,0);
  return;
}



===== DeviceMainTimerTickHandler @ 14000a570 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined ** DeviceMainTimerTickHandler(undefined8 param_1)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  undefined8 uVar4;
  longlong lVar5;
  undefined **ppuVar6;
  int iVar7;
  
  uVar4 = (**(code **)(WdfFunctions_01015 + 0xa08))(WdfDriverGlobals,param_1);
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,uVar4,DAT_14001a0f0);
  iVar7 = 0;
  lVar1 = *(longlong *)(lVar5 + 0x118);
  if ((*(char *)(lVar5 + 8) == '\0') || (lVar1 == 0)) {
    iVar7 = -0x3fffffff;
  }
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x158))(WdfDriverGlobals,*(undefined8 *)(lVar5 + 0x10));
  uVar3 = iVar2 - 0x10c;
  ppuVar6 = (undefined **)(ulonglong)uVar3;
  if (((0x18 < uVar3) || ((0x1010081U >> (uVar3 & 0x1f) & 1) == 0)) && (-1 < iVar7)) {
    if (*(int *)(lVar1 + 0x50) == 0) {
      ppuVar6 = (undefined **)0x0;
      LOCK();
      uVar3 = *(uint *)(lVar1 + 0x78);
      if (uVar3 == 0) {
        *(uint *)(lVar1 + 0x78) = 1;
      }
      else {
        ppuVar6 = (undefined **)(ulonglong)uVar3;
      }
      UNLOCK();
      if (uVar3 == 0) {
        RequestSetupMcnSyncIrp(lVar5);
        ppuVar6 = (undefined **)
                  IofCallDriver(*(undefined8 *)(lVar5 + 0x40),*(undefined8 *)(lVar1 + 0x40));
      }
    }
    else {
      ppuVar6 = &WPP_RECORDER_INITIALIZED;
      if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
         (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
        ppuVar6 = (undefined **)
                  WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,0xd,0x34,
                                    &WPP_7cea3eca420c34d4f6f4315c54c616a1_Traceguids,
                                    (char)*(undefined8 *)(lVar5 + 0x40));
      }
    }
  }
  return ppuVar6;
}



===== RequestHandleEventNotification @ 14000a6c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int RequestHandleEventNotification
              (longlong param_1,longlong param_2,longlong param_3,undefined8 *param_4)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  int *local_res20;
  
  lVar1 = *(longlong *)(param_1 + 0x118);
  iVar3 = 0;
  local_res20 = (int *)0x0;
  *param_4 = 0;
  if ((*(char *)(param_1 + 8) == '\0') || (lVar1 == 0)) {
    iVar3 = -0x3fffffff;
  }
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x158))
                    (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x10));
  if ((0x18 < iVar2 - 0x10cU) || ((0x1010081U >> (iVar2 - 0x10cU & 0x1f) & 1) == 0)) {
    if (iVar3 < 0) {
      return iVar3;
    }
    if ((param_2 != 0) && (param_3 != 0)) {
      if (*(ulonglong *)(param_3 + 0x10) < 0x10) {
        return -0x3ffffffc;
      }
      iVar3 = (**(code **)(WdfFunctions_01015 + 0x868))
                        (WdfDriverGlobals,param_2,*(ulonglong *)(param_3 + 0x10),&local_res20,0);
      if (iVar3 < 0) {
        return iVar3;
      }
      if ((*local_res20 != 1) || (local_res20[1] != 0x10)) {
        return -0x3ffffff3;
      }
      if ((*(byte *)(local_res20 + 2) & 7) == 0) {
        return -0x3fffff45;
      }
    }
    if (*(int *)(lVar1 + 0x50) == 0) {
      LOCK();
      bVar4 = *(int *)(lVar1 + 0x78) == 0;
      if (bVar4) {
        *(int *)(lVar1 + 0x78) = 1;
      }
      UNLOCK();
      if (bVar4) {
        RequestSetupMcnSyncIrp(param_1);
        IofCallDriver(*(undefined8 *)(param_1 + 0x40),*(undefined8 *)(lVar1 + 0x40));
        return iVar3;
      }
    }
    else if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
            (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,0xd,0x34,
                        &WPP_7cea3eca420c34d4f6f4315c54c616a1_Traceguids,
                        (char)*(undefined8 *)(param_1 + 0x40));
    }
  }
  return -0x3fffffff;
}



===== RequestSetupMcnSyncIrp @ 14000a870 =====

void RequestSetupMcnSyncIrp(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x118) + 0x40);
  lVar2 = *(longlong *)(lVar1 + 0xb8);
  *(char *)(lVar1 + 0x43) = *(char *)(lVar1 + 0x43) + -1;
  *(longlong *)(lVar1 + 0xb8) = lVar2 + -0x48;
  *(undefined8 *)(lVar2 + -0x20) = *(undefined8 *)(param_1 + 0x40);
  lVar2 = *(longlong *)(lVar1 + 0xb8);
  *(byte *)(lVar2 + -0x46) = *(byte *)(lVar2 + -0x46) | 2;
  *(code **)(lVar2 + -0x40) = RequestSetupMcnSyncIrp;
  *(code **)(lVar2 + -0x38) = RequestSetupMcnSyncIrp;
  *(code **)(lVar2 + -0x28) = RequestSetupMcnSyncIrp;
  *(undefined1 *)(lVar2 + -0x48) = 0xe;
  *(undefined4 *)(lVar2 + -0x30) = 0x7c0c8;
  lVar1 = *(longlong *)(lVar1 + 0xb8);
  *(code **)(lVar1 + -0x10) = RequestMcnSyncIrpCompletion;
  *(longlong *)(lVar1 + -8) = param_1;
  *(undefined1 *)(lVar1 + -0x45) = 0xe0;
  return;
}



===== SequentialQueueEvtIoDeviceControl @ 14000a8f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SequentialQueueEvtIoDeviceControl(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  undefined1 auStackY_78 [32];
  char local_48 [8];
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,uVar2,DAT_14001a0f0);
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_CDROM_REQUEST_CONTEXT_TYPE_INFO_14001a018);
  local_20 = 0;
  uStack_38 = 0;
  local_40 = 0x28;
  local_30 = 0;
  uStack_28 = 0;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_40);
  if ((*(longlong *)(lVar3 + 0x378) != 0) &&
     (lVar5 = (**(code **)(WdfFunctions_01015 + 0x8a8))(WdfDriverGlobals,param_2),
     *(longlong *)(lVar3 + 0x378) != lVar5)) {
    local_48[0] = '\0';
    iVar1 = RequestIsIoctlBlockedByExclusiveAccess(param_2,local_48);
    if ((-1 < iVar1) && (local_48[0] != '\0')) {
      if (*(char *)(lVar4 + 0x34) == '\0') {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x55,
                            &WPP_d2ddb5c132d1335dbff1b624de01ec23_Traceguids,(char)uStack_28);
        }
        RequestCompletion(lVar3,param_2,-0x3fffffde,0);
        return;
      }
      goto LAB_14000aa3d;
    }
  }
  if ((*(char *)(lVar3 + 0x28b) == '\0') && (((int)uStack_28 - 0x70014U & 0xffffffef) == 0)) {
    *(undefined4 *)(lVar3 + 0x290) = 1;
  }
  if (*(char *)(lVar4 + 0x34) == '\0') {
    *(undefined8 *)(lVar3 + 0x498) = param_2;
    (**(code **)(WdfFunctions_01015 + 0xbe0))(WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x490));
    return;
  }
LAB_14000aa3d:
  KeSetEvent(*(undefined8 *)(lVar4 + 0x38),1);
  return;
}



===== RequestEvtCleanup @ 14000ab10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void RequestEvtCleanup(undefined8 param_1)

{
  (**(code **)(WdfFunctions_01015 + 0x650))
            (WdfDriverGlobals,param_1,PTR__WDF_CDROM_REQUEST_CONTEXT_TYPE_INFO_14001a018);
  return;
}



===== NormalizeIoctl @ 14000ab50 =====

void NormalizeIoctl(longlong param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0x18);
  if ((((uVar1 >> 0x10 < 0x34) &&
       ((0x8000080000094U >> ((ulonglong)(uVar1 >> 0x10) & 0x3f) & 1) != 0)) &&
      (0x7ff < (uVar1 & 0x3ffc))) && ((uVar1 & 0x3ffc) < 0xc01)) {
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x28,
                        &WPP_d2ddb5c132d1335dbff1b624de01ec23_Traceguids,(char)(uVar1 & 0xffff));
    }
    *(uint *)(param_1 + 0x18) = uVar1 & 0xffff | 0x2d0000;
  }
  return;
}



===== RequestClearSendTime @ 14000ac00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void RequestClearSendTime(undefined8 param_1)

{
  longlong lVar1;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_CDROM_REQUEST_CONTEXT_TYPE_INFO_14001a018);
  *(undefined8 *)(lVar1 + 0x18) = 0;
  *(undefined8 *)(lVar1 + 0x20) = 0;
  return;
}



===== WPP_RECORDER_SF_D @ 14000ac40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_D(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                      undefined8 param_5,undefined1 param_6)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,4,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,&param_6,4,0);
  return;
}



===== RequestMcnSyncIrpCompletion @ 14000ad40 =====

undefined8 RequestMcnSyncIrpCompletion(undefined8 param_1,undefined8 param_2,longlong param_3)

{
  int *piVar1;
  longlong lVar2;
  
  if (param_3 != 0) {
    lVar2 = *(longlong *)(param_3 + 0x118);
    IoReuseIrp(*(undefined8 *)(lVar2 + 0x40),0xc00000bb);
    piVar1 = (int *)(lVar2 + 0x78);
    LOCK();
    if (*piVar1 == 1) {
      *piVar1 = 0;
    }
    UNLOCK();
  }
  return 0xc0000016;
}



===== DeviceSetMediaChangeStateEx @ 14000ad90 =====

void DeviceSetMediaChangeStateEx(longlong param_1,uint param_2,int *param_3)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_res8;
  uint local_resc;
  undefined8 local_res20;
  
  local_res20 = 0;
  if (*(longlong *)(param_1 + 0x118) == 0) {
    return;
  }
  lVar1 = *(longlong *)(param_1 + 0x118) + 8;
  iVar3 = KeWaitForSingleObject(lVar1,0,0,0,&local_res20);
  if (iVar3 == 0x102) {
    return;
  }
  lVar2 = *(longlong *)(param_1 + 0x118);
  if ((param_2 < 4) && (lVar2 != 0)) {
    iVar3 = *(int *)(lVar2 + 0x48);
    if (param_3 != (int *)0x0) {
      *param_3 = iVar3;
    }
    *(uint *)(lVar2 + 0x48) = param_2;
    if ((param_2 == 1) && (iVar3 != 1)) {
      LOCK();
      *(int *)(param_1 + 0x148) = *(int *)(param_1 + 0x148) + 1;
      UNLOCK();
    }
    if ((*(int *)(lVar2 + 0x50) == 0) && (*(int *)(lVar2 + 0x4c) != *(int *)(lVar2 + 0x48))) {
      local_res8 = *(undefined4 *)(param_1 + 0x148);
      local_resc = param_2;
      if (param_2 == 1) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,0xd,0x1b,
                           &WPP_bfcef3ce16aa3c5196ed71474c974d5c_Traceguids);
        }
        puVar4 = (undefined4 *)&GUID_IO_MEDIA_ARRIVAL;
      }
      else {
        if (1 < param_2 - 2) goto LAB_14000ae1f;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,0xd,0x1c,
                           &WPP_bfcef3ce16aa3c5196ed71474c974d5c_Traceguids);
        }
        puVar4 = (undefined4 *)&GUID_IO_MEDIA_REMOVAL;
      }
      DeviceSendNotification(param_1,puVar4,8,&local_res8);
      *(undefined4 *)(lVar2 + 0x4c) = *(undefined4 *)(lVar2 + 0x48);
    }
  }
LAB_14000ae1f:
  KeReleaseMutex(lVar1,0);
  return;
}



===== RequestSetContextFields @ 14000af20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 RequestSetContextFields(undefined8 param_1,undefined8 param_2)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_CDROM_REQUEST_CONTEXT_TYPE_INFO_14001a018);
  lVar2 = ExAllocatePool2(0x40,0x18,0x65436353);
  if (lVar2 == 0) {
    return 0xc000009a;
  }
  *(longlong *)(lVar1 + 0x38) = lVar2;
  *(undefined1 *)(lVar1 + 0x34) = 1;
  *(undefined8 *)(lVar1 + 0x40) = param_2;
  return 0;
}



===== DeviceErrorHandlerForMmc @ 14000afb0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
DeviceErrorHandlerForMmc(longlong param_1,longlong param_2,int *param_3,undefined1 *param_4)

{
  char cVar1;
  longlong lVar2;
  bool bVar3;
  int iVar4;
  char *pcVar5;
  byte bVar6;
  undefined8 uVar7;
  undefined2 uVar8;
  undefined8 local_res10;
  undefined8 local_78;
  code *pcStack_70;
  undefined8 local_68;
  undefined4 local_60;
  undefined8 local_5c;
  undefined8 uStack_54;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  
  bVar3 = false;
  if (-1 < *(char *)(param_2 + 3)) {
    return 0;
  }
  lVar2 = *(longlong *)(param_2 + 0x20);
  bVar6 = *(byte *)(lVar2 + 2) & 0xf;
  if (bVar6 == 2) {
    if (*(char *)(lVar2 + 0xc) == ':') {
      if ((*(char *)(param_1 + 0x28b) != '\0') &&
         ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        uVar8 = 10;
        bVar6 = 4;
LAB_14000b236:
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),bVar6,1,uVar8,
                         &WPP_14ceea506f553d1aa69114b6e3475b08_Traceguids);
      }
LAB_14000b01d:
      *(undefined1 *)(param_1 + 0x28b) = 0;
    }
    else if (*(char *)(lVar2 + 0xc) == '\x04') {
      if (*(char *)(lVar2 + 0xd) == '\x01') {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0xb,
                           &WPP_14ceea506f553d1aa69114b6e3475b08_Traceguids);
        }
      }
      else if (((byte)(*(char *)(lVar2 + 0xd) - 7U) < 2) &&
              ((((bVar6 = *(byte *)(param_2 + 0x48), bVar6 == 0xb9 || ((byte)(bVar6 + 0xaf) < 2)) ||
                (((byte)(bVar6 - 8) < 0x3c &&
                 ((0x800000520000005U >> ((ulonglong)(bVar6 - 8) & 0x3f) & 1) != 0)))) ||
               (bVar6 == 0xbe)))) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar8 = 0xc;
          bVar6 = 3;
LAB_14000b2e4:
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),bVar6,1,uVar8,
                           &WPP_14ceea506f553d1aa69114b6e3475b08_Traceguids);
        }
LAB_14000b2ff:
        *param_4 = 1;
        *param_3 = -0x7fffffef;
      }
    }
  }
  else if (bVar6 == 5) {
    if (*(char *)(lVar2 + 0xc) == '\'') {
      if ((*(char *)(param_1 + 0x28b) != '\0') &&
         ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        uVar8 = 0x12;
        bVar6 = 3;
        goto LAB_14000b236;
      }
      goto LAB_14000b01d;
    }
  }
  else if (bVar6 == 6) {
    cVar1 = *(char *)(lVar2 + 0xc);
    if (cVar1 == ')') {
      *(undefined1 *)(param_1 + 0x28b) = 0;
      *(undefined4 *)(param_1 + 0x290) = 1;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0xe,
                         &WPP_14ceea506f553d1aa69114b6e3475b08_Traceguids);
      }
    }
    else if (cVar1 == '(') {
      *(undefined1 *)(param_1 + 0x28b) = 0;
      *(undefined4 *)(param_1 + 0x290) = 1;
      if ((Microsoft_Windows_CDROMEnableBits & 1) != 0) {
        McTemplateK0z_EtwWriteTransfer(0x28,1,param_3,*(wchar_t **)(param_1 + 0x60));
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0xd,
                         &WPP_14ceea506f553d1aa69114b6e3475b08_Traceguids);
      }
      bVar3 = true;
    }
    else if (cVar1 == 'Z') {
      cVar1 = *(char *)(lVar2 + 0xd);
      uVar7 = 0;
      if (cVar1 == '\x01') {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar8 = 0xf;
          bVar6 = 4;
          goto LAB_14000b2e4;
        }
        goto LAB_14000b2ff;
      }
      if (cVar1 != '\x02') {
        if (cVar1 != '\x03') goto LAB_14000b024;
        uVar7 = 1;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        pcVar5 = "disable";
        if ((char)uVar7 == '\0') {
          pcVar5 = "enable";
        }
        WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar7,1,0x10,
                          &WPP_14ceea506f553d1aa69114b6e3475b08_Traceguids,pcVar5);
      }
      *param_4 = 1;
      *param_3 = -0x7fffffef;
      *(undefined1 *)(param_1 + 0x28b) = 0;
      *(undefined4 *)(param_1 + 0x290) = 1;
    }
    else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,1,0x11,
                         &WPP_14ceea506f553d1aa69114b6e3475b08_Traceguids,cVar1,
                         *(undefined1 *)(lVar2 + 0xd));
    }
  }
LAB_14000b024:
  if ((*(char *)(param_2 + 0x48) == -0x5d) && ((*(byte *)(param_2 + 0x52) & 0x3f) == 6)) {
    cVar1 = *(char *)(lVar2 + 0xc);
    if (cVar1 == ':') {
      *param_3 = -0x3fffffed;
    }
    else {
      if ((*(byte *)(lVar2 + 2) & 0xf) != 5) goto LAB_14000b02e;
      if (cVar1 == 'o') {
        if (*(char *)(lVar2 + 0xd) != '\x04') goto LAB_14000b02e;
      }
      else if ((cVar1 != '0') || (*(char *)(lVar2 + 0xd) != '\x02')) goto LAB_14000b02e;
      *param_3 = -0x3ffffcf6;
    }
    *param_4 = 0;
  }
LAB_14000b02e:
  if (((bVar3) && (*param_3 != -0x7fffffe4)) && (*(char *)(param_1 + 0x3c0) == '\x01')) {
    local_60 = 0x38;
    local_res10 = 0;
    local_4c = 0;
    local_40 = *(undefined8 *)(param_1 + 0x10);
    local_48 = 1;
    pcStack_70 = DeviceRestoreDefaultSpeed;
    local_5c = 0;
    uStack_54 = 0;
    local_44 = 1;
    local_38 = 0;
    uStack_30 = 0;
    local_78 = 0x18;
    local_68 = 1;
    iVar4 = (**(code **)(WdfFunctions_01015 + 0xbd8))
                      (WdfDriverGlobals,&local_78,&local_60,&local_res10);
    if ((-1 < iVar4) &&
       ((**(code **)(WdfFunctions_01015 + 0xbe0))(WdfDriverGlobals,local_res10),
       (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x13,
                        &WPP_14ceea506f553d1aa69114b6e3475b08_Traceguids,
                        (char)*(undefined8 *)(param_1 + 0x40));
    }
  }
  return 0;
}



===== DeviceInternalSetMediaChangeState @ 14000b490 =====

void DeviceInternalSetMediaChangeState(longlong param_1,uint param_2,int *param_3)

{
  int iVar1;
  longlong lVar2;
  undefined4 *puVar3;
  undefined4 local_res8;
  uint local_resc;
  
  if ((param_2 < 4) && (lVar2 = *(longlong *)(param_1 + 0x118), lVar2 != 0)) {
    iVar1 = *(int *)(lVar2 + 0x48);
    if (param_3 != (int *)0x0) {
      *param_3 = iVar1;
    }
    *(uint *)(lVar2 + 0x48) = param_2;
    if ((param_2 == 1) && (iVar1 != 1)) {
      LOCK();
      *(int *)(param_1 + 0x148) = *(int *)(param_1 + 0x148) + 1;
      UNLOCK();
    }
    if ((*(int *)(lVar2 + 0x50) == 0) && (*(int *)(lVar2 + 0x4c) != *(int *)(lVar2 + 0x48))) {
      local_res8 = *(undefined4 *)(param_1 + 0x148);
      local_resc = param_2;
      if (param_2 == 1) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,0xd,0x1b,
                           &WPP_bfcef3ce16aa3c5196ed71474c974d5c_Traceguids);
        }
        puVar3 = (undefined4 *)&GUID_IO_MEDIA_ARRIVAL;
      }
      else {
        if (1 < param_2 - 2) {
          return;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,0xd,0x1c,
                           &WPP_bfcef3ce16aa3c5196ed71474c974d5c_Traceguids);
        }
        puVar3 = (undefined4 *)&GUID_IO_MEDIA_REMOVAL;
      }
      DeviceSendNotification(param_1,puVar3,8,&local_res8);
      *(undefined4 *)(lVar2 + 0x4c) = *(undefined4 *)(lVar2 + 0x48);
    }
  }
  return;
}



===== RequestHandleGetMediaTypeEx @ 14000b5a8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x00014000b657) */
/* WARNING: Removing unreachable block (ram,0x00014000b6c5) */
/* WARNING: Removing unreachable block (ram,0x00014000b704) */
/* WARNING: Removing unreachable block (ram,0x00014000b70f) */
/* WARNING: Removing unreachable block (ram,0x00014000b739) */
/* WARNING: Removing unreachable block (ram,0x00014000b73e) */
/* WARNING: Removing unreachable block (ram,0x00014000b748) */
/* WARNING: Removing unreachable block (ram,0x00014000b7b0) */
/* WARNING: Removing unreachable block (ram,0x00014000b7c0) */
/* WARNING: Removing unreachable block (ram,0x00014000b78f) */
/* WARNING: Removing unreachable block (ram,0x00014000b798) */
/* WARNING: Removing unreachable block (ram,0x00014000b7a9) */
/* WARNING: Removing unreachable block (ram,0x00014000b7a1) */
/* WARNING: Removing unreachable block (ram,0x00014000b7ec) */

undefined8 RequestHandleGetMediaTypeEx(longlong param_1,undefined8 param_2,size_t *param_3)

{
  byte bVar1;
  undefined8 uVar2;
  size_t sVar3;
  
  *param_3 = 0;
  bVar1 = KeGetCurrentIrql();
  if (bVar1 < 2) {
    sVar3 = (ulonglong)(-(uint)(*(char *)(param_1 + 0x288) != '\0') & 0x20) + 0x28;
    uVar2 = (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,param_2,sVar3);
    *param_3 = sVar3;
  }
  else {
    uVar2 = 0xc0000148;
  }
  return uVar2;
}



===== RequestIsIoctlBlockedByExclusiveAccess @ 14000b824 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int RequestIsIoctlBlockedByExclusiveAccess(undefined8 param_1,undefined1 *param_2)

{
  int iVar1;
  undefined1 auStack_78 [32];
  undefined8 local_58;
  uint *local_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_78;
  uStack_38 = 0;
  iVar1 = 0;
  local_30 = 0;
  uStack_28 = 0;
  local_20 = 0;
  local_40 = 0x28;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_1,&local_40);
  if (param_2 == (undefined1 *)0x0) {
    iVar1 = -0x3ffffff3;
  }
  else {
    *param_2 = 0;
    if (local_40._4_4_ - 0xeU < 2) {
      if ((((((uint)uStack_28 != 0x41018) && ((uint)uStack_28 != 0x2d0c14)) &&
           ((uint)uStack_28 != 0x2d1080)) &&
          (((uint)uStack_28 != 0x2d0c04 && ((uint)uStack_28 != 0x2c05c)))) &&
         ((uint)uStack_28 != 0x24064)) {
        if ((uint)uStack_28 == 0x2d1400) {
          local_48 = (uint *)0x0;
          local_58 = 0;
          iVar1 = (**(code **)(WdfFunctions_01015 + 0x868))
                            (WdfDriverGlobals,param_1,local_30,&local_48);
          if (((-1 < iVar1) && (local_48 != (uint *)0x0)) &&
             ((local_48[1] == 1 || ((local_48[1] == 0 && (*local_48 < 2)))))) {
            *param_2 = 0;
          }
        }
        else if (((uint)uStack_28 >> 0x10 < 0x34) &&
                ((0x8200000000094U >> ((ulonglong)((uint)uStack_28 >> 0x10) & 0x3f) & 1) != 0)) {
          *param_2 = 1;
        }
      }
    }
    else {
      iVar1 = -0x3ffffff3;
    }
  }
  return iVar1;
}



===== SenseInfoInterpretForZPODD @ 14000b990 =====

undefined8
SenseInfoInterpretForZPODD(longlong param_1,longlong param_2,undefined4 *param_3,longlong *param_4)

{
  int *piVar1;
  byte bVar2;
  uint3 uVar3;
  uint uVar4;
  undefined1 *puVar5;
  char cVar6;
  uint uVar7;
  longlong lVar8;
  undefined1 uVar9;
  longlong lVar10;
  undefined *in_stack_ffffffffffffffb8;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  lVar8 = *(longlong *)(param_1 + 0x120);
  lVar10 = *(longlong *)(param_2 + 0x20);
  uVar9 = 0;
  *param_3 = 0xc0000185;
  *param_4 = 0;
  if (*(char *)(lVar8 + 0x52) == '\0') {
    puVar5 = (undefined1 *)register0x00000020;
    if ((*(char *)(param_2 + 3) < '\0') && (bVar2 = *(byte *)(param_2 + 0xb), 7 < bVar2)) {
      uVar4 = *(byte *)(lVar10 + 7) + 7;
      uVar7 = (uint)bVar2;
      if (uVar4 <= bVar2) {
        uVar7 = uVar4;
      }
      uVar3 = (uint3)(uVar4 >> 8);
      if (uVar7 < 0xd) {
        puVar5 = (undefined1 *)((ulonglong)uVar3 << 8);
LAB_14000ba2f:
        cVar6 = '\0';
      }
      else {
        puVar5 = (undefined1 *)(ulonglong)CONCAT31(uVar3,*(undefined1 *)(lVar10 + 0xc));
        if (uVar7 < 0xe) goto LAB_14000ba2f;
        cVar6 = *(char *)(lVar10 + 0xd);
      }
      if ((((*(byte *)(lVar10 + 2) & 0xf) == 2) && ((char)puVar5 == '\x04')) && (cVar6 == '\x01')) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          in_stack_ffffffffffffffb8 = &WPP_14ceea506f553d1aa69114b6e3475b08_Traceguids;
          puVar5 = (undefined1 *)
                   WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x42,
                                    &WPP_14ceea506f553d1aa69114b6e3475b08_Traceguids);
        }
        piVar1 = (int *)(lVar8 + 0x54);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 != 0) {
          *param_3 = 0xc00000a3;
          *param_4 = 2000000;
          local_28 = 1;
          local_24 = 1;
          local_20 = 2;
          register0x00000020 =
               (BADSPACEBASE *)
               DeviceSendNotification
                         (param_1,(undefined4 *)&GUID_IO_DEVICE_BECOMING_READY,0xc,&local_28);
          goto LAB_14000baca;
        }
      }
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      puVar5 = (undefined1 *)
               WPP_RECORDER_SF_DDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,1,0x44,
                                   &WPP_14ceea506f553d1aa69114b6e3475b08_Traceguids,
                                   *(byte *)(lVar10 + 2) & 0xf,*(undefined1 *)(lVar10 + 0xc),
                                   *(undefined1 *)(lVar10 + 0xd));
    }
  }
  else {
    *(undefined1 *)(lVar8 + 0x52) = 0;
LAB_14000baca:
    uVar9 = 1;
    puVar5 = (undefined1 *)register0x00000020;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      lVar8 = *param_4;
      lVar10 = (lVar8 / 10000) % 1000;
      lVar8 = SUB168(SEXT816(-0x29406b2a1a85bd43) * SEXT816(lVar8),8) + lVar8;
      lVar8 = (lVar8 >> 0x17) - (lVar8 >> 0x3f);
      puVar5 = (undefined1 *)
               WPP_RECORDER_SF_ii(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar8,lVar10,0x43,
                                  in_stack_ffffffffffffffb8,(char)lVar8,(char)lVar10);
    }
  }
  return CONCAT71((int7)((ulonglong)puVar5 >> 8),uVar9);
}



===== RequestProcessSetPower @ 14000bbd0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 RequestProcessSetPower(undefined8 param_1,longlong param_2)

{
  byte *pbVar1;
  undefined8 *puVar2;
  longlong lVar3;
  bool bVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  
  uVar6 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1,DAT_14001a0f0);
  bVar4 = false;
  puVar2 = *(undefined8 **)(param_2 + 0xb8);
  if ((*(int *)(puVar2 + 2) == 1) && (*(int *)(puVar2 + 3) != 1)) {
    puVar2[-9] = *puVar2;
    puVar2[-8] = puVar2[1];
    puVar2[-7] = puVar2[2];
    puVar2[-6] = puVar2[3];
    *(undefined4 *)(puVar2 + -5) = *(undefined4 *)(puVar2 + 4);
    *(undefined4 *)((longlong)puVar2 + -0x24) = *(undefined4 *)((longlong)puVar2 + 0x24);
    *(undefined4 *)(puVar2 + -4) = *(undefined4 *)(puVar2 + 5);
    *(undefined4 *)((longlong)puVar2 + -0x1c) = *(undefined4 *)((longlong)puVar2 + 0x2c);
    puVar2[-3] = puVar2[6];
    *(undefined1 *)((longlong)puVar2 + -0x45) = 0;
    bVar4 = true;
    lVar3 = *(longlong *)(param_2 + 0xb8);
    *(code **)(lVar3 + -0x10) = RequestProcessPowerIrpCompletion;
    *(undefined8 *)(lVar3 + -8) = uVar6;
    *(undefined1 *)(lVar3 + -0x45) = 0xe0;
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
  }
  else {
    *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
    *(undefined8 **)(param_2 + 0xb8) = puVar2 + 9;
  }
  uVar5 = (**(code **)(WdfFunctions_01015 + 0x110))(WdfDriverGlobals,param_1,param_2);
  if (bVar4) {
    uVar5 = 0x103;
  }
  return uVar5;
}



===== DeviceEnableMainTimer @ 14000bcc4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int DeviceEnableMainTimer(longlong param_1)

{
  longlong *plVar1;
  int iVar2;
  undefined8 local_68;
  code *pcStack_60;
  ulonglong local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  undefined8 uStack_18;
  undefined8 local_10;
  
  iVar2 = 0;
  if ((*(char **)(param_1 + 0x118) == (char *)0x0) || (**(char **)(param_1 + 0x118) != '\0')) {
    return 0;
  }
  plVar1 = (longlong *)(param_1 + 0x30);
  if (*plVar1 == 0) {
    local_48 = 0;
    uStack_50 = 500;
    pcStack_60 = DeviceMainTimerTickHandler;
    local_68 = 0x28;
    local_30 = 0;
    local_10 = 0;
    local_20 = *(undefined8 *)(param_1 + 0x10);
    local_58 = (ulonglong)((-(uint)((*(uint *)(param_1 + 0x340) & 0x2000) != 0) & 1000) + 1000);
    uStack_18 = 0;
    uStack_38 = 0;
    uStack_28 = 0x100000001;
    local_40 = 0x38;
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x9f0))(WdfDriverGlobals,&local_68,&local_40,plVar1);
    if (iVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return iVar2;
      }
      WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
      return iVar2;
    }
  }
  (**(code **)(WdfFunctions_01015 + 0x9f8))(WdfDriverGlobals,*plVar1,0xfffffffffff0bdc0);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,0xd,0x52,
                      &WPP_bfcef3ce16aa3c5196ed71474c974d5c_Traceguids,
                      (char)*(undefined8 *)(param_1 + 0x10));
  }
  return iVar2;
}



===== WPP_RECORDER_SF_dddDDD @ 14000be68 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_dddDDD(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_8ec010589a13368bcaefd70a9b2ee310_Traceguids,0x5f,&uStack0000000000000030,4,
               &uStack0000000000000038,4,&uStack0000000000000040,4,&uStack0000000000000048,4,
               &uStack0000000000000050,4,&uStack0000000000000058,4,0);
  }
  WppAutoLogTrace(param_1,4,5,&WPP_8ec010589a13368bcaefd70a9b2ee310_Traceguids,0x5f,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,0);
  return;
}



===== DeviceEvtD0Entry @ 14000bfb0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 DeviceEvtD0Entry(undefined8 param_1)

{
  char *pcVar1;
  longlong lVar2;
  ulonglong uVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined1 auStackY_58 [32];
  undefined8 local_28;
  int local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_58;
  local_28 = 0;
  local_20 = 0;
  uVar5 = DAT_14001a0f0;
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  if (*(char *)(lVar2 + 8) != '\0') {
    pcVar1 = *(char **)(lVar2 + 0x120);
    if ((pcVar1 != (char *)0x0) && (pcVar1[0x51] != '\0')) {
      pcVar1[0x51] = '\0';
      pcVar1[0x52] = '\x01';
      pcVar1[0x54] = '\x0f';
      pcVar1[0x55] = '\0';
      pcVar1[0x56] = '\0';
      pcVar1[0x57] = '\0';
      lVar4 = lVar2;
      uVar3 = DeviceZPODDGetPowerupReason(lVar2,(undefined4 *)&local_28);
      if (((int)uVar3 < 0) || (local_20 != 2)) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          lVar4 = *(longlong *)(WPP_GLOBAL_Control + 0x40);
          uVar5 = 3;
          WPP_RECORDER_SF_(lVar4,4,3,0x1d,&WPP_d2ddb5c132d1335dbff1b624de01ec23_Traceguids);
        }
        if ((Microsoft_Windows_CDROMEnableBits & 2) != 0) {
          McTemplateK0_EtwWriteTransfer(lVar4,&ZeroPowerODDPowerOnStop,uVar5);
        }
      }
      else {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,3,0x1c,
                           &WPP_d2ddb5c132d1335dbff1b624de01ec23_Traceguids);
        }
        if ((*pcVar1 == '\x01') && (pcVar1[1] == '\0')) {
          DeviceSendIoctlAsynchronously(lVar2,0x2d4808,*(undefined8 *)(lVar2 + 0x40));
        }
      }
    }
    DeviceEnableMainTimer(lVar2);
  }
  return 0;
}



===== WPP_RECORDER_SF_s @ 14000c110 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_s(undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
                      undefined8 param_5,char *param_6)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  
  uVar4 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar4 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[uVar4 * 0x50 + 0x29])) {
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
  WppAutoLogTrace(param_1,4,param_3,param_5,param_4,param_6,lVar2,0);
  return;
}



===== DeviceZPODDGetPowerupReason @ 14000c25c =====

ulonglong DeviceZPODDGetPowerupReason(longlong param_1,undefined4 *param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong local_38 [6];
  
  local_38[4] = 0;
  local_38[0] = 0;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  param_2[2] = 0;
  param_2[1] = 0xc;
  *param_2 = 1;
  KeInitializeEvent(local_38 + 2,0,0);
  lVar1 = IoBuildDeviceIoControlRequest
                    (0x2d1c84,*(undefined8 *)(param_1 + 0x48),param_2,0xc,param_2,0xc,0,local_38 + 2
                     ,local_38);
  if (lVar1 == 0) {
    uVar2 = 0xc000009a;
  }
  else {
    uVar2 = IofCallDriver(*(undefined8 *)(param_1 + 0x48),lVar1);
    if ((int)uVar2 == 0x103) {
      KeWaitForSingleObject(local_38 + 2,0,0,0,0);
      uVar2 = local_38[0] & 0xffffffff;
    }
  }
  return uVar2;
}



===== entry @ 14000c360 =====

void entry(_WDF_BIND_INFO *param_1,undefined8 param_2)

{
  __security_init_cookie();
  FxDriverEntryWorker(param_1,param_2);
  return;
}



===== FxDriverEntryWorker @ 14000c394 =====

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
    _DAT_14001a4a0 = 0x2080000;
    _DAT_14001a4a8 = &DAT_14001a290;
    RtlCopyUnicodeString(&DAT_14001a4a0);
    p_Var3 = param_1;
    iVar1 = WdfVersionBind(param_1,&DAT_14001a4a0,&WdfBindInfo,&WdfDriverGlobals);
    if (-1 < iVar1) {
      iVar1 = FxStubBindClasses(p_Var3);
      if ((-1 < iVar1) && (iVar1 = FxStubInitTypes(), -1 < iVar1)) {
        iVar1 = DriverEntry(param_1,param_2);
        if (-1 < iVar1) {
          if (*(char *)(WdfDriverGlobals + 0x30) != '\0') {
            if (*(longlong *)(param_1 + 0x68) != 0) {
              DAT_14001a498 = *(longlong *)(param_1 + 0x68);
            }
            *(code **)(param_1 + 0x68) = FxStubDriverUnload;
          }
          return 0;
        }
        DbgPrintEx(0x4d,0,"DriverEntry failed 0x%x for driver %wZ\n",iVar1,&DAT_14001a4a0);
        if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_14001a1d8 != &__KMDF_CLASS_BIND_START) {
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



===== FxStubDriverUnloadCommon @ 14000c51c =====

/* void __cdecl FxStubDriverUnloadCommon(void) */

void __cdecl FxStubDriverUnloadCommon(void)

{
  _WDF_BIND_INFO *in_RCX;
  
  FxStubUnbindClasses(in_RCX);
  WdfVersionUnbind(&DAT_14001a4a0,&WdfBindInfo,WdfDriverGlobals);
  return;
}



===== FxStubUnbindClasses @ 14000c554 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl FxStubUnbindClasses(struct _WDF_BIND_INFO * __ptr64) */

void __cdecl FxStubUnbindClasses(_WDF_BIND_INFO *param_1)

{
  uint *puVar1;
  uint *puVar2;
  void **ppvVar3;
  
  ppvVar3 = &__KMDF_CLASS_BIND_END;
  if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_14001a1d8 != &__KMDF_CLASS_BIND_START) {
    puVar1 = (uint *)(PTR___KMDF_CLASS_BIND_START_14001a1d8 + 0x50);
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



===== FxStubInitTypes @ 14000c610 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x00014000c62d) */
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
    if ((void **)0x14001a1ef < ppvVar2) break;
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



===== FxStubBindClasses @ 14000c6d8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x00014000c6fd) */
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
    if ((uint *)0x14001a1cf < puVar2) break;
    PTR___KMDF_CLASS_BIND_START_14001a1d8 = (undefined *)puVar2;
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



===== RequestProcessShutdownFlush @ 14000c840 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int RequestProcessShutdownFlush(undefined8 param_1,longlong param_2)

{
  char *pcVar1;
  int iVar2;
  longlong lVar3;
  
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1,DAT_14001a0f0);
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x280),0);
  pcVar1 = *(char **)(param_2 + 0xb8);
  (**(code **)(WdfFunctions_01015 + 0x4e0))(WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x20));
  iVar2 = DeviceScratchSyncCache(lVar3);
  if (-1 < iVar2) {
    if (*pcVar1 == '\x10') {
      iVar2 = DeviceScratchPreventMediaRemoval(lVar3);
      if (iVar2 < 0) goto LAB_14000c8f6;
    }
    iVar2 = RequestIssueShutdownFlush(lVar3,param_2);
  }
LAB_14000c8f6:
  (**(code **)(WdfFunctions_01015 + 0x4d0))(WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x20));
  (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x280));
  *(int *)(param_2 + 0x30) = iVar2;
  IofCompleteRequest(param_2,0);
  return iVar2;
}



===== DeviceScratchSyncCache @ 14000c968 =====

undefined4 DeviceScratchSyncCache(longlong param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined8 local_18;
  undefined8 uStack_10;
  
  ScratchBuffer_BeginUseX(param_1);
  uVar1 = *(uint *)(param_1 + 0x78);
  uStack_10 = 0;
  local_18 = 0x35;
  uVar3 = uVar1;
  if (uVar1 < 0x105) {
    uVar3 = 0x104;
    if (uVar1 * 4 < 0x104) {
      uVar3 = uVar1 * 4;
    }
  }
  uVar2 = ScratchBuffer_ExecuteCdbEx(param_1,0,0,'\0',&local_18,10,uVar3);
  ScratchBuffer_EndUse(param_1);
  return uVar2;
}



===== PowerContextBeginUse @ 14000c9e4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int PowerContextBeginUse(longlong param_1)

{
  int iVar1;
  longlong lVar2;
  
  *(undefined8 *)(param_1 + 0x268) = 0;
  *(undefined1 *)(param_1 + 0x1c8) = 1;
  *(undefined4 *)(param_1 + 0x264) = 4;
  *(undefined8 *)(param_1 + 0x1d0) = _DAT_fffff78000000320;
  *(undefined8 *)(param_1 + 0x1e8) = 0;
  iVar1 = PowerContextReuseRequest(param_1);
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x1f0),
                     PTR__WDF_CDROM_REQUEST_CONTEXT_TYPE_INFO_14001a018);
  *(undefined8 *)(lVar2 + 0x18) = 0;
  *(undefined8 *)(lVar2 + 0x20) = 0;
  return iVar1;
}



===== PowerContextReuseRequest @ 14000ca74 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int PowerContextReuseRequest(longlong param_1)

{
  undefined2 *_Dst;
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined8 local_2c;
  undefined4 local_24;
  
  _Dst = (undefined2 *)(param_1 + 0x1f8);
  *(undefined8 *)(param_1 + 0x250) = 0;
  *(undefined8 *)(param_1 + 600) = 0;
  *(undefined2 *)(param_1 + 0x260) = 0;
  memset(_Dst,0,0x58);
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x8e8))
                    (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x1f0));
  local_2c = 0;
  local_24 = 0;
  local_34 = 0;
  local_38 = 0x18;
  local_30 = 0xc00000bb;
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x7c8))
                    (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x1f0),&local_38);
  if (-1 < iVar2) {
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x5f8))
                      (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x18),
                       *(undefined8 *)(param_1 + 0x1f0),0x1b0011,0,0,0,0,0,0);
    if (iVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,10,
                          &WPP_dac79f1042503e9c1b16124056e5083c_Traceguids,(char)iVar2);
      }
    }
    else {
      lVar1 = *(longlong *)(lVar3 + 0xb8);
      *(undefined1 *)(lVar1 + -0x48) = 0xf;
      *(undefined2 **)(lVar1 + -0x40) = _Dst;
      *_Dst = 0x58;
      *(longlong *)(param_1 + 0x228) = lVar3;
      *(undefined8 **)(param_1 + 0x218) = (undefined8 *)(param_1 + 0x250);
      *(undefined1 *)(param_1 + 0x203) = 0x12;
    }
  }
  return iVar2;
}



===== WPP_RECORDER_SF_qs @ 14000cc14 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qs(undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,char *param_7)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  char *pcVar4;
  ulonglong uVar5;
  
  pcVar4 = param_7;
  uVar5 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar5 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[uVar5 * 0x50 + 0x29])) {
    if (param_7 == (char *)0x0) {
      lVar3 = 5;
    }
    else {
      lVar2 = -1;
      do {
        lVar3 = lVar2;
        lVar2 = lVar3 + 1;
      } while (param_7[lVar2] != '\0');
      lVar3 = lVar3 + 2;
    }
    pcVar1 = param_7;
    if (param_7 == (char *)0x0) {
      pcVar1 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar5 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,8,pcVar1,lVar3,0);
  }
  lVar3 = -1;
  if (pcVar4 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    do {
      lVar2 = lVar3;
      lVar3 = lVar2 + 1;
    } while (pcVar4[lVar3] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (pcVar4 == (char *)0x0) {
    pcVar4 = "NULL";
  }
  WppAutoLogTrace(param_1,4,param_3,param_5,param_4,&param_6,8,pcVar4,lVar2,0);
  return;
}



===== DeviceReleaseQueueCompletion @ 14000cd90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void DeviceReleaseQueueCompletion
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  char cVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  undefined8 local_28;
  undefined4 local_20;
  undefined8 local_1c;
  undefined4 local_14;
  
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_4,DAT_14001a0f0);
  local_28 = 0x18;
  local_1c = 0;
  local_14 = 0;
  local_20 = 0;
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x150));
  cVar1 = *(char *)(lVar3 + 0x1c0);
  *(undefined2 *)(lVar3 + 0x1c0) = 0;
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x7c8))(WdfDriverGlobals,param_1,&local_28);
  if (-1 < iVar2) {
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x5f8))
                      (WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x18),param_1,0x1b0013,
                       *(undefined8 *)(lVar3 + 0x1b8),0,0,0,0,0);
    if (-1 < iVar2) goto LAB_14000ced6;
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x13,
                      &WPP_8ec010589a13368bcaefd70a9b2ee310_Traceguids,(char)iVar2);
  }
LAB_14000ced6:
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_CDROM_REQUEST_CONTEXT_TYPE_INFO_14001a018);
  *(undefined8 *)(lVar4 + 0x18) = 0;
  *(undefined8 *)(lVar4 + 0x20) = 0;
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x150));
  if (cVar1 != '\0') {
    DeviceReleaseQueue(param_4);
  }
  return;
}



===== DevicePerfIncrementErrorCount @ 14000cf58 =====

void DevicePerfIncrementErrorCount(longlong param_1)

{
  longlong lVar1;
  int *piVar2;
  int iVar3;
  longlong lVar4;
  undefined1 uVar5;
  
  lVar4 = *(longlong *)(param_1 + 0x478);
  lVar1 = lVar4 + 0x28;
  uVar5 = KeAcquireSpinLockRaiseToDpc(lVar1);
  *(undefined4 *)(lVar4 + 4) = 0;
  LOCK();
  piVar2 = (int *)(param_1 + 0xe8);
  iVar3 = *piVar2;
  *piVar2 = *piVar2 + 1;
  UNLOCK();
  if ((3 < iVar3 + 1U) &&
     (*(uint *)(param_1 + 0x74) = *(uint *)(param_1 + 0x74) & 0xfffffefd | 8,
     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x14,
                     &WPP_8ec010589a13368bcaefd70a9b2ee310_Traceguids);
  }
  if ((7 < iVar3 + 1U) &&
     (*(uint *)(param_1 + 0x74) = *(uint *)(param_1 + 0x74) | 4,
     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x15,
                     &WPP_8ec010589a13368bcaefd70a9b2ee310_Traceguids);
  }
  KeReleaseSpinLock(lVar1,uVar5);
  return;
}



===== WPP_RECORDER_SF_qsqD @ 14000d054 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qsqD(undefined8 param_1)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 uStack0000000000000030;
  char *in_stack_00000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
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
               &WPP_8ec010589a13368bcaefd70a9b2ee310_Traceguids,0x67,&uStack0000000000000030,8,
               pcVar1,lVar3,&uStack0000000000000040,8,&uStack0000000000000048,4,0);
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
  WppAutoLogTrace(param_1,2,3,&WPP_8ec010589a13368bcaefd70a9b2ee310_Traceguids,0x67,
                  &uStack0000000000000030,8,in_stack_00000038,lVar2,&uStack0000000000000040,8,
                  &uStack0000000000000048,4,0);
  return;
}



===== DeviceReleaseQueue @ 14000d1f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void DeviceReleaseQueue(undefined8 param_1)

{
  undefined1 uVar1;
  longlong lVar2;
  undefined8 uVar3;
  
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1,DAT_14001a0f0);
  uVar1 = KfRaiseIrql(2);
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x150));
  if (*(char *)(lVar2 + 0x1c1) == '\0') {
    *(undefined1 *)(lVar2 + 0x1c1) = 1;
    (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x150));
    *(undefined1 *)(lVar2 + 0x162) = 0x15;
    uVar3 = (**(code **)(WdfFunctions_01015 + 0x8e8))
                      (WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x158));
    *(undefined8 *)(lVar2 + 400) = uVar3;
    (**(code **)(WdfFunctions_01015 + 0x820))
              (WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x158),DeviceReleaseQueueCompletion,param_1)
    ;
    RequestSend(lVar2,*(undefined8 *)(lVar2 + 0x158),*(undefined8 *)(lVar2 + 0x18),4,(char *)0x0);
  }
  else {
    *(undefined1 *)(lVar2 + 0x1c0) = 1;
    (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals);
  }
  KeLowerIrql(uVar1);
  return;
}



===== WPP_RECORDER_SF_dd @ 14000d354 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_dd(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,4,&param_7,4,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,&param_6,4,&param_7,4,0);
  return;
}



===== RequestProcessInternalDeviceControl @ 14000d47c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void RequestProcessInternalDeviceControl(undefined8 param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  undefined8 uVar3;
  char local_res10 [8];
  
  local_res10[0] = '\0';
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals,param_1);
  lVar2 = *(longlong *)(lVar2 + 0xb8);
  *(undefined8 *)(lVar2 + -0x40) = *(undefined8 *)(lVar2 + 8);
  *(undefined2 *)(lVar2 + -0x48) = 0x10f;
  (**(code **)(WdfFunctions_01015 + 0x820))(WdfDriverGlobals,param_1,RequestDummyCompletionRoutine);
  iVar1 = RequestSend(param_2,param_1,*(undefined8 *)(param_2 + 0x18),0,local_res10);
  if (local_res10[0] == '\0') {
    uVar3 = (**(code **)(WdfFunctions_01015 + 0x8a0))(WdfDriverGlobals,param_1);
    RequestCompletion(param_2,param_1,iVar1,uVar3);
  }
  return;
}



===== RtlStringCchPrintfW @ 14000d55c =====

undefined8
RtlStringCchPrintfW(wchar_t *param_1,longlong param_2,wchar_t *param_3,undefined8 param_4)

{
  ulonglong _Count;
  int iVar1;
  undefined8 uVar2;
  undefined8 local_res20;
  
  if (param_2 - 1U < 0x7fffffff) {
    _Count = param_2 - 1;
    uVar2 = 0;
    local_res20 = param_4;
    iVar1 = _vsnwprintf(param_1,_Count,param_3,(va_list)&local_res20);
    if ((iVar1 < 0) || (_Count < (ulonglong)(longlong)iVar1)) {
      uVar2 = 0x80000005;
    }
    else if ((longlong)iVar1 != _Count) {
      return 0;
    }
    param_1[_Count] = L'\0';
  }
  else {
    uVar2 = 0xc000000d;
    if (param_2 != 0) {
      *param_1 = L'\0';
    }
  }
  return uVar2;
}



===== RequestUnlockQueueCompletion @ 14000d5e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void RequestUnlockQueueCompletion(void)

{
  undefined8 uVar1;
  longlong lVar2;
  
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x570))(WdfDriverGlobals);
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,uVar1,DAT_14001a0f0);
  *(uint *)(lVar2 + 0x1ec) = *(uint *)(lVar2 + 0x1ec) & 0xfffffffd;
  *(undefined1 *)(lVar2 + 0x1c8) = 0;
  *(undefined8 *)(lVar2 + 0x1e0) = _DAT_fffff78000000320;
  IofCompleteRequest();
  return;
}



===== McGenEventRegister_EtwRegister @ 14000d668 =====

void McGenEventRegister_EtwRegister(void)

{
  if (CDROM_DIAG_TRACE_PROVIDER_Context == 0) {
    EtwRegister(&CDROM_DIAG_TRACE_PROVIDER,McGenControlCallbackV2,&CDROM_DIAG_TRACE_PROVIDER_Context
                ,&CDROM_DIAG_TRACE_PROVIDER_Context);
  }
  return;
}



===== PowerContextEndUse @ 14000d6a8 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 PowerContextEndUse(longlong param_1)

{
  *(undefined1 *)(param_1 + 0x1c8) = 0;
  *(undefined8 *)(param_1 + 0x1e0) = _DAT_fffff78000000320;
  return 0;
}



===== __report_gsfailure @ 14000d6e0 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== __C_specific_handler @ 14000d6ed =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00014000d6ed. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== McGenControlCallbackV2 @ 14000d700 =====

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



===== McGenEventUnregister_EtwUnregister @ 14000d810 =====

undefined8 McGenEventUnregister_EtwUnregister(void)

{
  undefined8 uVar1;
  
  if (CDROM_DIAG_TRACE_PROVIDER_Context == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = EtwUnregister();
    CDROM_DIAG_TRACE_PROVIDER_Context = 0;
  }
  return uVar1;
}



===== McGenEventWrite_EtwWriteTransfer @ 14000d844 =====

void McGenEventWrite_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined8 *param_5)

{
  ushort *puVar1;
  undefined4 uVar2;
  uint uVar3;
  
  puVar1 = DAT_14001a038;
  uVar2 = 0;
  if (DAT_14001a038 == (ushort *)0x0) {
    *param_5 = 0;
    uVar3 = 0;
  }
  else {
    *param_5 = DAT_14001a038;
    uVar2 = 2;
    uVar3 = (uint)*puVar1;
  }
  *(uint *)(param_5 + 1) = uVar3;
  *(undefined4 *)((longlong)param_5 + 0xc) = uVar2;
  EtwWriteTransfer(CDROM_DIAG_TRACE_PROVIDER_Context,param_2,0,0,param_4,param_5);
  return;
}



===== McTemplateK0_EtwWriteTransfer @ 14000d8a8 =====

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



===== SequentialQueueEvtCanceledOnQueue @ 14000d8f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SequentialQueueEvtCanceledOnQueue(undefined8 param_1,undefined8 param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_CDROM_REQUEST_CONTEXT_TYPE_INFO_14001a018);
  if (*(char *)(lVar1 + 0x34) == '\0') {
    uVar2 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
    lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,uVar2,DAT_14001a0f0);
    RequestCompletion(lVar1,param_2,-0x3ffffee0,0);
  }
  else {
    KeSetEvent(*(undefined8 *)(lVar1 + 0x38),1);
  }
  return;
}



===== WPP_RECORDER_SF_P @ 14000d9a8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_P(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                      undefined8 param_5,undefined1 param_6)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_d2ddb5c132d1335dbff1b624de01ec23_Traceguids,param_4,&param_6,8,0);
  }
  WppAutoLogTrace(param_1,5,1,&WPP_d2ddb5c132d1335dbff1b624de01ec23_Traceguids,param_4,&param_6,8,0)
  ;
  return;
}



===== WPP_RECORDER_SF_qd @ 14000da54 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_d2ddb5c132d1335dbff1b624de01ec23_Traceguids,param_4,&param_6,8,&param_7,4,0);
  }
  WppAutoLogTrace(param_1,4,9,&WPP_d2ddb5c132d1335dbff1b624de01ec23_Traceguids,param_4,&param_6,8,
                  &param_7,4,0);
  return;
}



===== WPP_RECORDER_SF_qq @ 14000db2c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qq(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,8,&param_7,8,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,&param_6,8,&param_7,8,0);
  return;
}



===== WppClassicProviderCallback @ 14000dc60 =====

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



===== wil_details_FeatureDescriptors_SkipPadding @ 14000dcbc =====

longlong * wil_details_FeatureDescriptors_SkipPadding(longlong *param_1)

{
  while( true ) {
    if (&UNK_1400196f7 < param_1) {
      return (longlong *)0x0;
    }
    if (*param_1 != 0) break;
    param_1 = param_1 + 1;
  }
  return param_1;
}



===== wil_details_RecordCachedUsage @ 14000dce4 =====

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



===== wil_details_RecordFeatureUsageReporting @ 14000de40 =====

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



===== Feature_3408814395__private_IsEnabledDeviceUsageNoInline @ 14000dec4 =====

ulonglong Feature_3408814395__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_3408814395__private_featureState;
  if ((Feature_3408814395__private_featureState & 0x10) == 0) {
    uVar1 = Feature_3408814395__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_3408814395__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_3408814395__private_IsEnabledFallback @ 14000defc =====

void Feature_3408814395__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&wil_details_featureDescriptors_a);
  return;
}



===== WPP_RECORDER_SF_Dq @ 14000df18 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_Dq(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,4,&param_7,8,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,&param_6,4,&param_7,8,0);
  return;
}



===== WPP_RECORDER_SF_LZZ @ 14000e044 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_LZZ(undefined8 param_1)

{
  wchar_t wVar1;
  wchar_t *pwVar2;
  wchar_t *pwVar3;
  wchar_t *pwVar4;
  wchar_t wVar5;
  wchar_t wVar6;
  wchar_t *pwVar7;
  wchar_t *pwVar8;
  undefined1 uStack0000000000000030;
  wchar_t *in_stack_00000038;
  wchar_t *in_stack_00000040;
  
  pwVar4 = L"NULL";
  wVar5 = L'\b';
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    if (in_stack_00000040 == (wchar_t *)0x0) {
      wVar1 = L'\b';
LAB_14000e0cb:
      pwVar3 = L"NULL";
    }
    else {
      wVar1 = *in_stack_00000040;
      if (*in_stack_00000040 == L'\0') goto LAB_14000e0cb;
      pwVar3 = *(wchar_t **)(in_stack_00000040 + 4);
    }
    pwVar7 = in_stack_00000040;
    if (in_stack_00000040 == (wchar_t *)0x0) {
      pwVar7 = L"\b";
    }
    if (in_stack_00000038 == (wchar_t *)0x0) {
      wVar6 = L'\b';
LAB_14000e0f0:
      pwVar8 = L"NULL";
    }
    else {
      wVar6 = *in_stack_00000038;
      if (*in_stack_00000038 == L'\0') goto LAB_14000e0f0;
      pwVar8 = *(wchar_t **)(in_stack_00000038 + 4);
    }
    pwVar2 = in_stack_00000038;
    if (in_stack_00000038 == (wchar_t *)0x0) {
      pwVar2 = L"\b";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_c6cef56efab5359de7c6f40b77738682_Traceguids,0x14,&uStack0000000000000030,4,
               pwVar2,2,pwVar8,wVar6,pwVar7,2,pwVar3,wVar1,0);
  }
  if (in_stack_00000040 == (wchar_t *)0x0) {
    wVar1 = L'\b';
  }
  else {
    wVar1 = *in_stack_00000040;
    if (*in_stack_00000040 != L'\0') {
      pwVar3 = *(wchar_t **)(in_stack_00000040 + 4);
      goto LAB_14000e18f;
    }
  }
  pwVar3 = L"NULL";
LAB_14000e18f:
  if (in_stack_00000040 == (wchar_t *)0x0) {
    in_stack_00000040 = L"\b";
  }
  if ((in_stack_00000038 != (wchar_t *)0x0) &&
     (wVar5 = *in_stack_00000038, *in_stack_00000038 != L'\0')) {
    pwVar4 = *(wchar_t **)(in_stack_00000038 + 4);
  }
  if (in_stack_00000038 == (wchar_t *)0x0) {
    in_stack_00000038 = L"\b";
  }
  WppAutoLogTrace(param_1,2,9,&WPP_c6cef56efab5359de7c6f40b77738682_Traceguids,0x14,
                  &uStack0000000000000030,4,in_stack_00000038,2,pwVar4,wVar5,in_stack_00000040,2,
                  pwVar3,wVar1,0);
  return;
}



===== WPP_RECORDER_SF_ZZ @ 14000e240 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_ZZ(undefined8 param_1)

{
  wchar_t wVar1;
  wchar_t *pwVar2;
  wchar_t *pwVar3;
  wchar_t *pwVar4;
  wchar_t wVar5;
  wchar_t wVar6;
  wchar_t *pwVar7;
  wchar_t *pwVar8;
  wchar_t *in_stack_00000030;
  wchar_t *in_stack_00000038;
  
  pwVar4 = L"NULL";
  wVar5 = L'\b';
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    if (in_stack_00000038 == (wchar_t *)0x0) {
      wVar1 = L'\b';
LAB_14000e2c6:
      pwVar3 = L"NULL";
    }
    else {
      wVar1 = *in_stack_00000038;
      if (*in_stack_00000038 == L'\0') goto LAB_14000e2c6;
      pwVar3 = *(wchar_t **)(in_stack_00000038 + 4);
    }
    pwVar7 = in_stack_00000038;
    if (in_stack_00000038 == (wchar_t *)0x0) {
      pwVar7 = L"\b";
    }
    if (in_stack_00000030 == (wchar_t *)0x0) {
      wVar6 = L'\b';
LAB_14000e2eb:
      pwVar8 = L"NULL";
    }
    else {
      wVar6 = *in_stack_00000030;
      if (*in_stack_00000030 == L'\0') goto LAB_14000e2eb;
      pwVar8 = *(wchar_t **)(in_stack_00000030 + 4);
    }
    pwVar2 = in_stack_00000030;
    if (in_stack_00000030 == (wchar_t *)0x0) {
      pwVar2 = L"\b";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_c6cef56efab5359de7c6f40b77738682_Traceguids,0x15,pwVar2,2,pwVar8,wVar6,pwVar7,2,
               pwVar3,wVar1,0);
  }
  if (in_stack_00000038 == (wchar_t *)0x0) {
    wVar1 = L'\b';
  }
  else {
    wVar1 = *in_stack_00000038;
    if (*in_stack_00000038 != L'\0') {
      pwVar3 = *(wchar_t **)(in_stack_00000038 + 4);
      goto LAB_14000e368;
    }
  }
  pwVar3 = L"NULL";
LAB_14000e368:
  if (in_stack_00000038 == (wchar_t *)0x0) {
    in_stack_00000038 = L"\b";
  }
  if ((in_stack_00000030 != (wchar_t *)0x0) &&
     (wVar5 = *in_stack_00000030, *in_stack_00000030 != L'\0')) {
    pwVar4 = *(wchar_t **)(in_stack_00000030 + 4);
  }
  if (in_stack_00000030 == (wchar_t *)0x0) {
    in_stack_00000030 = L"\b";
  }
  WppAutoLogTrace(param_1,4,9,&WPP_c6cef56efab5359de7c6f40b77738682_Traceguids,0x15,
                  in_stack_00000030,2,pwVar4,wVar5,in_stack_00000038,2,pwVar3,wVar1,0);
  return;
}



===== WPP_RECORDER_SF_qDD @ 14000e400 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qDD(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                        undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,
               &WPP_c6cef56efab5359de7c6f40b77738682_Traceguids,param_4,&param_6,8,&param_7,4,
               &param_8,4,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,&WPP_c6cef56efab5359de7c6f40b77738682_Traceguids,param_4,
                  &param_6,8,&param_7,4,&param_8,4,0);
  return;
}



===== WPP_RECORDER_SF_sD @ 14000e550 =====

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



===== WPP_RECORDER_SF_sss @ 14000e6d8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sss(undefined8 param_1)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  char *pcVar6;
  char *pcVar7;
  char *in_stack_00000030;
  char *in_stack_00000038;
  char *in_stack_00000040;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    if (in_stack_00000040 == (char *)0x0) {
      lVar5 = 5;
    }
    else {
      lVar4 = -1;
      do {
        lVar5 = lVar4;
        lVar4 = lVar5 + 1;
      } while (in_stack_00000040[lVar4] != '\0');
      lVar5 = lVar5 + 2;
    }
    pcVar7 = in_stack_00000040;
    if (in_stack_00000040 == (char *)0x0) {
      pcVar7 = "NULL";
    }
    if (in_stack_00000038 == (char *)0x0) {
      lVar4 = 5;
    }
    else {
      lVar3 = -1;
      do {
        lVar4 = lVar3;
        lVar3 = lVar4 + 1;
      } while (in_stack_00000038[lVar3] != '\0');
      lVar4 = lVar4 + 2;
    }
    pcVar6 = in_stack_00000038;
    if (in_stack_00000038 == (char *)0x0) {
      pcVar6 = "NULL";
    }
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
               &WPP_c6cef56efab5359de7c6f40b77738682_Traceguids,0x20,pcVar1,lVar3,pcVar6,lVar4,
               pcVar7,lVar5,0);
  }
  if (in_stack_00000040 == (char *)0x0) {
    lVar5 = 5;
  }
  else {
    lVar4 = -1;
    do {
      lVar5 = lVar4;
      lVar4 = lVar5 + 1;
    } while (in_stack_00000040[lVar4] != '\0');
    lVar5 = lVar5 + 2;
  }
  if (in_stack_00000040 == (char *)0x0) {
    in_stack_00000040 = "NULL";
  }
  if (in_stack_00000038 == (char *)0x0) {
    lVar4 = 5;
  }
  else {
    lVar3 = -1;
    do {
      lVar4 = lVar3;
      lVar3 = lVar4 + 1;
    } while (in_stack_00000038[lVar3] != '\0');
    lVar4 = lVar4 + 2;
  }
  if (in_stack_00000038 == (char *)0x0) {
    in_stack_00000038 = "NULL";
  }
  lVar3 = -1;
  if (in_stack_00000030 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    do {
      lVar2 = lVar3;
      lVar3 = lVar2 + 1;
    } while (in_stack_00000030[lVar3] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (in_stack_00000030 == (char *)0x0) {
    in_stack_00000030 = "NULL";
  }
  WppAutoLogTrace(param_1,4,9,&WPP_c6cef56efab5359de7c6f40b77738682_Traceguids,0x20,
                  in_stack_00000030,lVar2,in_stack_00000038,lVar4,in_stack_00000040,lVar5,0);
  return;
}



===== wil_details_FeatureReporting_IncrementOpportunityInCache @ 14000e8cc =====

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



===== wil_details_FeatureReporting_IncrementUsageInCache @ 14000e9a4 =====

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



===== wil_details_FeatureReporting_RecordUsageInCache @ 14000ea88 =====

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
LAB_14000ebe0:
    wil_details_FeatureReporting_IncrementUsageInCache(param_2,uVar5,param_3,param_1);
  }
  else {
    if (uVar5 == 1) {
LAB_14000ebd3:
      wil_details_FeatureReporting_IncrementOpportunityInCache(param_2,uVar5,param_3,param_1);
      return param_1;
    }
    if ((uVar5 != 2) && (uVar5 != 3)) {
      if (uVar5 == 4) goto LAB_14000ebe0;
      if (uVar5 == 5) goto LAB_14000ebd3;
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



===== wil_details_FeatureReporting_ReportUsageToService @ 14000ec08 =====

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



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 14000ec8c =====

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



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 14000ed7c =====

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



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 14000ee8c =====

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



===== wil_details_GetCurrentFeatureEnabledState @ 14000eef0 =====

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



===== wil_details_IsEnabledFallback @ 14000f050 =====

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



===== wil_details_MapReportingKind @ 14000f0e4 =====

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



===== DeviceAsynchronousCompletion @ 14000f190 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void DeviceAsynchronousCompletion
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 *param_4)

{
  (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,*param_4,DAT_14001a0f0);
  if ((*(char *)((longlong)param_4 + 10) == '\0') &&
     ((*(byte *)((longlong)param_4 + 0xb) & 0x40) != 0)) {
    DeviceReleaseQueue(*param_4);
  }
  if ((*(uint *)((longlong)param_4 + 0x14) & 0x200400) == 0x200400) {
    ExFreePoolWithTag(param_4[5],0);
    param_4[5] = 0;
    *(uint *)((longlong)param_4 + 0x14) = *(uint *)((longlong)param_4 + 0x14) & 0xfffffbff;
    *(undefined1 *)((longlong)param_4 + 0x13) = 0;
  }
  ExFreePoolWithTag(param_4,0);
  (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,param_1);
  return;
}



===== DeviceSendIoctlAsynchronously @ 14000f248 =====

void DeviceSendIoctlAsynchronously(longlong param_1,undefined4 param_2,undefined8 param_3)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar2 = IoAllocateIrp(CONCAT71((int7)((ulonglong)*(longlong *)(param_1 + 0x40) >> 8),
                                 *(undefined1 *)(*(longlong *)(param_1 + 0x40) + 0x4c)),0);
  if (lVar2 != 0) {
    lVar1 = *(longlong *)(lVar2 + 0xb8);
    *(undefined4 *)(lVar1 + -0x40) = 0;
    *(undefined4 *)(lVar1 + -0x38) = 0;
    *(undefined8 *)(lVar1 + -0x28) = 0;
    *(undefined1 *)(lVar1 + -0x48) = 0xe;
    *(undefined4 *)(lVar1 + -0x30) = param_2;
    lVar1 = *(longlong *)(lVar2 + 0xb8);
    *(code **)(lVar1 + -0x10) = RequestAsynchronousIrpCompletion;
    *(longlong *)(lVar1 + -8) = param_1;
    *(undefined1 *)(lVar1 + -0x45) = 0xe0;
    IofCallDriver(param_3,lVar2);
  }
  return;
}



===== DeviceSendStartUnit @ 14000f2dc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void DeviceSendStartUnit(undefined8 param_1)

{
  int iVar1;
  longlong lVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  longlong local_res10;
  undefined8 local_res18 [2];
  undefined4 local_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 local_58;
  undefined4 uStack_54;
  undefined8 uStack_50;
  longlong local_48;
  undefined8 uStack_40;
  undefined *local_38;
  
  local_res10 = 0;
  local_res18[0] = 0;
  local_38 = (undefined *)((ulonglong)local_38 & 0xffffffff00000000);
  local_68 = 0;
  uStack_64 = 0;
  uStack_60 = 0;
  uStack_5c = 0;
  local_58 = 0;
  uStack_54 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1,DAT_14001a0f0);
  puVar3 = (undefined8 *)ExAllocatePool2(0x40,0x60,0x63436353);
  if (puVar3 == (undefined8 *)0x0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x12,
                       &WPP_8ec010589a13368bcaefd70a9b2ee310_Traceguids);
    }
  }
  else {
    *puVar3 = param_1;
    memset((void *)((longlong)puVar3 + 10),0,0x56);
    *(undefined1 *)((longlong)puVar3 + 10) = 0;
    *(undefined4 *)((longlong)puVar3 + 0x1c) = 0xf0;
    *(undefined2 *)(puVar3 + 1) = 0x58;
    *(undefined4 *)((longlong)puVar3 + 0x14) = 8;
    *(undefined1 *)((longlong)puVar3 + 0x12) = 6;
    *(undefined1 *)(puVar3 + 10) = 0x1b;
    *(byte *)((longlong)puVar3 + 0x54) = *(byte *)((longlong)puVar3 + 0x54) | 1;
    *(byte *)((longlong)puVar3 + 0x51) =
         *(char *)((longlong)puVar3 + 0xf) << 5 | *(byte *)((longlong)puVar3 + 0x51) & 0x1e;
    uStack_54 = 0;
    uStack_40 = 0;
    local_38 = PTR__WDF_CDROM_REQUEST_CONTEXT_TYPE_INFO_14001a018;
    uStack_64 = 0;
    uStack_60 = 0;
    uStack_5c = 0;
    local_58 = 0;
    local_68 = 0x38;
    uStack_50 = 0x100000001;
    local_48 = *(longlong *)(lVar2 + 0x18);
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x7b8))
                      (WdfDriverGlobals,&local_68,*(undefined8 *)(lVar2 + 0x18),&local_res10);
    if (-1 < iVar1) {
      uVar4 = (**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals,local_res10);
      puVar3[7] = uVar4;
      local_38 = (undefined *)0x0;
      local_58 = 0;
      uStack_54 = 0;
      uStack_40 = 0;
      local_48 = local_res10;
      uStack_64 = 0;
      uStack_60 = 0;
      uStack_5c = 0;
      local_68 = 0x38;
      uStack_50 = 0x100000001;
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x608))
                        (WdfDriverGlobals,&local_68,puVar3 + 1,0x58,local_res18);
      if ((-1 < iVar1) &&
         (iVar1 = (**(code **)(WdfFunctions_01015 + 0x5f8))
                            (WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x18),local_res10,0x1b0013,
                             local_res18[0],0,0,0,0,0), -1 < iVar1)) {
        (**(code **)(WdfFunctions_01015 + 0x820))
                  (WdfDriverGlobals,local_res10,DeviceAsynchronousCompletion);
        iVar1 = RequestSend(lVar2,local_res10,*(undefined8 *)(lVar2 + 0x18),0,(char *)0x0);
        if (-1 < iVar1) {
          return;
        }
      }
    }
    ExFreePoolWithTag(puVar3,0);
  }
  if (local_res10 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
  return;
}



===== IsVolumeMounted @ 14000f5b8 =====

undefined8 IsVolumeMounted(longlong param_1)

{
  longlong lVar1;
  undefined1 uVar2;
  
  lVar1 = *(longlong *)(param_1 + 0x38);
  if ((lVar1 == 0) || (uVar2 = 1, (*(byte *)(lVar1 + 4) & 1) == 0)) {
    uVar2 = 0;
  }
  return CONCAT71((int7)((ulonglong)lVar1 >> 8),uVar2);
}



===== RequestAsynchronousIrpCompletion @ 14000f5e0 =====

undefined8 RequestAsynchronousIrpCompletion(undefined8 param_1,undefined8 param_2)

{
  IoFreeIrp(param_2);
  return 0xc0000016;
}



===== RequestDuidGetDeviceIdProperty @ 14000f604 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong RequestDuidGetDeviceIdProperty
                    (longlong param_1,undefined8 param_2,longlong param_3,ulonglong *param_4)

{
  undefined8 uVar1;
  longlong lVar2;
  void *_Src;
  uint uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  uint uVar6;
  uint local_res8 [2];
  longlong local_res20;
  void *local_28 [2];
  
  uVar1 = *(undefined8 *)(param_1 + 0x10);
  local_28[0] = (void *)0x0;
  local_res20 = 0;
  *param_4 = 0;
  local_res8[0] = 2;
  uVar4 = DeviceRetrieveDescriptor(uVar1,local_res8,local_28);
  _Src = local_28[0];
  uVar5 = uVar4 & 0xffffffff;
  if (-1 < (int)uVar4) {
    if (local_28[0] == (void *)0x0) {
      uVar5 = 0xc0000225;
    }
    else {
      uVar3 = (**(code **)(WdfFunctions_01015 + 0x870))
                        (WdfDriverGlobals,param_2,*(undefined8 *)(param_3 + 8),&local_res20,0);
      lVar2 = local_res20;
      uVar5 = (ulonglong)uVar3;
      if (-1 < (int)uVar3) {
        uVar4 = *(ulonglong *)(param_3 + 8);
        uVar3 = *(uint *)(local_res20 + 4);
        uVar6 = *(int *)((longlong)_Src + 4) + uVar3;
        if (uVar6 < uVar3) {
          *(undefined4 *)(local_res20 + 4) = 0xffffffff;
          uVar5 = 0xc0000095;
        }
        else {
          *(uint *)(local_res20 + 4) = uVar6;
          if (uVar4 < *(uint *)(local_res20 + 4)) {
            *param_4 = (ulonglong)*(uint *)(local_res20 + 4);
            uVar5 = 0x80000005;
          }
          else {
            *(uint *)(local_res20 + 8) = uVar3;
            memmove((void *)(local_res20 + (ulonglong)uVar3),_Src,
                    (ulonglong)*(uint *)((longlong)_Src + 4));
            uVar5 = 0;
            *param_4 = (ulonglong)*(uint *)(lVar2 + 4);
          }
        }
        ExFreePoolWithTag(_Src,0);
      }
    }
  }
  return uVar5;
}



===== RequestDuidGetDeviceProperty @ 14000f720 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
RequestDuidGetDeviceProperty
          (longlong param_1,undefined8 param_2,longlong param_3,ulonglong *param_4)

{
  uint uVar1;
  void *_Src;
  ulonglong uVar2;
  longlong lVar3;
  undefined8 uVar4;
  uint uVar5;
  longlong local_res8;
  
  _Src = *(void **)(param_1 + 200);
  local_res8 = 0;
  if (_Src != (void *)0x0) {
    uVar4 = (**(code **)(WdfFunctions_01015 + 0x870))
                      (WdfDriverGlobals,param_2,*(undefined8 *)(param_3 + 8),&local_res8,0);
    lVar3 = local_res8;
    if ((int)uVar4 < 0) {
      return uVar4;
    }
    if (*(int *)((longlong)_Src + 0x18) != 0) {
      uVar2 = *(ulonglong *)(param_3 + 8);
      uVar1 = *(uint *)(local_res8 + 4);
      uVar5 = *(int *)((longlong)_Src + 4) + uVar1;
      if (uVar5 < uVar1) {
        *(undefined4 *)(local_res8 + 4) = 0xffffffff;
        return 0xc0000095;
      }
      *(uint *)(local_res8 + 4) = uVar5;
      if (uVar2 < *(uint *)(local_res8 + 4)) {
        *param_4 = (ulonglong)*(uint *)(local_res8 + 4);
        return 0x80000005;
      }
      *(uint *)(local_res8 + 0xc) = uVar1;
      memmove((void *)(local_res8 + (ulonglong)uVar1),_Src,(ulonglong)*(uint *)((longlong)_Src + 4))
      ;
      *param_4 = (ulonglong)*(uint *)(lVar3 + 4);
      return 0;
    }
  }
  return 0xc0000225;
}



===== RequestDummyCompletionRoutine @ 14000f800 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void RequestDummyCompletionRoutine(undefined8 param_1)

{
  undefined4 uVar1;
  undefined8 uVar2;
  
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x8a0))(WdfDriverGlobals,param_1);
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x7f0))(WdfDriverGlobals,param_1);
  (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,param_1,uVar1,uVar2);
  return;
}



===== WPP_RECORDER_SF_qD @ 14000f884 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qD(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,8,&param_7,4,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,&param_6,8,&param_7,4,0);
  return;
}



===== WPP_RECORDER_SF_qsL @ 14000f9b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qsL(undefined8 param_1)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 uStack0000000000000030;
  char *in_stack_00000038;
  undefined1 uStack0000000000000040;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0) && (2 < (byte)WPP_GLOBAL_Control[0x29]))
  {
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
               &WPP_8ec010589a13368bcaefd70a9b2ee310_Traceguids,0x5a,&uStack0000000000000030,8,
               pcVar1,lVar3,&uStack0000000000000040,4,0);
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
  WppAutoLogTrace(param_1,3,9,&WPP_8ec010589a13368bcaefd70a9b2ee310_Traceguids,0x5a,
                  &uStack0000000000000030,8,in_stack_00000038,lVar2,&uStack0000000000000040,4,0);
  return;
}



===== Feature_1211600187__private_IsEnabledDeviceUsageNoInline @ 14000fb28 =====

ulonglong Feature_1211600187__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_1211600187__private_featureState;
  if ((Feature_1211600187__private_featureState & 0x10) == 0) {
    uVar1 = Feature_1211600187__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_1211600187__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_1211600187__private_IsEnabledFallback @ 14000fb60 =====

void Feature_1211600187__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_1211600187__private_descriptor);
  return;
}



===== Feature_3934489913__private_IsEnabledDeviceUsageNoInline @ 14000fb7c =====

ulonglong Feature_3934489913__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_3934489913__private_featureState;
  if ((Feature_3934489913__private_featureState & 0x10) == 0) {
    uVar1 = Feature_3934489913__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_3934489913__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_3934489913__private_IsEnabledFallback @ 14000fbb4 =====

void Feature_3934489913__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_3934489913__private_descriptor);
  return;
}



===== Feature_637773113__private_IsEnabledDeviceUsageNoInline @ 14000fbd0 =====

ulonglong Feature_637773113__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_637773113__private_featureState;
  if ((Feature_637773113__private_featureState & 0x10) == 0) {
    uVar1 = Feature_637773113__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_637773113__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_637773113__private_IsEnabledFallback @ 14000fc08 =====

void Feature_637773113__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_637773113__private_descriptor);
  return;
}



===== RequestHandleAreVolumesReady @ 14000fc24 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int RequestHandleAreVolumesReady
              (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  
  *param_4 = 0;
  if (*(char *)(param_1 + 0x271) == '\0') {
    iVar1 = 0;
  }
  else {
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x8c8))
                      (WdfDriverGlobals,param_2,*(undefined8 *)(param_1 + 0x278));
    if (-1 < iVar1) {
      return 0x103;
    }
  }
  RequestCompletion(param_1,param_2,iVar1,0);
  return iVar1;
}



===== RequestHandleMountQuerySuggestedLinkName @ 14000fca0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int RequestHandleMountQuerySuggestedLinkName
              (longlong param_1,undefined8 param_2,longlong param_3,undefined8 *param_4)

{
  ulonglong _Size;
  int iVar1;
  void *_Dst;
  code *pcVar2;
  undefined1 auStack_138 [32];
  undefined8 local_118;
  undefined1 *local_108;
  undefined4 local_100;
  undefined4 local_fc;
  short *local_f8;
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined1 local_d8 [8];
  undefined4 local_d0;
  void *local_c8;
  undefined4 *local_c0;
  undefined4 local_b8;
  short local_68 [12];
  ulonglong local_50;
  
  local_50 = __security_cookie ^ (ulonglong)auStack_138;
  _Size = *(ulonglong *)(param_3 + 8);
  local_108 = (undefined1 *)0x0;
  local_68[8] = 0;
  local_68[9] = 0;
  local_68[0] = 0;
  local_68[1] = 0;
  local_68[2] = 0;
  local_68[3] = 0;
  local_68[4] = 0;
  local_68[5] = 0;
  local_68[6] = 0;
  local_68[7] = 0;
  memset(local_d8,0,0x70);
  local_fc = 0;
  *param_4 = 0;
  if (_Size < 6) {
    *param_4 = 6;
    return -0x3fffffdd;
  }
  _Dst = (void *)ExAllocatePool2(0x100,(ulonglong)*(ushort *)(param_1 + 0x58) + 2,0x73436353);
  if (_Dst == (void *)0x0) {
    return -0x3fffff66;
  }
  memmove(_Dst,*(void **)(param_1 + 0x60),(ulonglong)*(ushort *)(param_1 + 0x58));
  local_f0 = 0;
  uStack_e8 = 0;
  *(undefined2 *)((longlong)_Dst + (ulonglong)(*(ushort *)(param_1 + 0x58) >> 1) * 2) = 0;
  local_f8 = local_68;
  local_c0 = &local_100;
  local_100 = 0x140000;
  local_d0 = 0x124;
  local_b8 = 0x1000000;
  local_c8 = _Dst;
  RtlInitUnicodeString(&local_f0,L"RtlQueryRegistryValuesEx");
  pcVar2 = (code *)MmGetSystemRoutineAddress(&local_f0);
  local_118 = 0;
  if (pcVar2 == (code *)0x0) {
    pcVar2 = RtlQueryRegistryValues_exref;
  }
  iVar1 = (*pcVar2)(0,L"\\Registry\\Machine\\System\\DISK",local_d8,0);
  if (iVar1 < 0) goto LAB_14000ff04;
  if ((short)local_100 == 4) {
    if (*local_f8 == 0x25) {
      if (local_f8[1] != 0x3a) goto LAB_14000feff;
      *local_f8 = 0xff;
    }
    else if ((0x17 < (ushort)(*local_f8 - 0x43U)) || (local_f8[1] != 0x3a)) goto LAB_14000feff;
    local_118 = 0;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,param_2,_Size,&local_108);
    if (-1 < iVar1) {
      memset(local_108,0,_Size);
      *local_108 = 1;
      *(undefined2 *)(local_108 + 2) = 0x1c;
      *param_4 = 0x20;
      if (_Size < 0x20) {
        *param_4 = 6;
        iVar1 = -0x7ffffffb;
      }
      else {
        RtlDeleteRegistryValue(0,L"\\Registry\\Machine\\System\\DISK",_Dst);
        builtin_wcsncpy((wchar_t *)(local_108 + 4),L"\\Dos",4);
        builtin_wcsncpy((wchar_t *)(local_108 + 0xc),L"Devi",4);
        *(undefined8 *)(local_108 + 0x14) = 0x5c007300650063;
        *(short *)(local_108 + 0x1c) = *local_f8;
        *(undefined2 *)(local_108 + 0x1e) = 0x3a;
      }
    }
  }
  else {
LAB_14000feff:
    iVar1 = -0x3ffffddb;
  }
LAB_14000ff04:
  ExFreePoolWithTag(_Dst,0);
  return iVar1;
}



===== RequestHandleMountQueryUniqueId @ 14000ff40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
RequestHandleMountQueryUniqueId
          (longlong param_1,undefined8 param_2,longlong param_3,longlong *param_4)

{
  ushort uVar1;
  ulonglong _Size;
  undefined8 uVar2;
  ushort *local_res8;
  
  local_res8 = (ushort *)0x0;
  *param_4 = 0;
  if (*(longlong *)(param_1 + 0xc0) == 0) {
    uVar2 = 0xc000000d;
  }
  else if (*(ulonglong *)(param_3 + 8) < 4) {
    *param_4 = 4;
    uVar2 = 0xc0000023;
  }
  else {
    uVar2 = (**(code **)(WdfFunctions_01015 + 0x870))
                      (WdfDriverGlobals,param_2,*(ulonglong *)(param_3 + 8),&local_res8,0);
    if (-1 < (int)uVar2) {
      _Size = *(ulonglong *)(param_3 + 8);
      memset(local_res8,0,_Size);
      uVar1 = *(ushort *)(param_1 + 0xb8);
      *local_res8 = uVar1;
      if (_Size < (ulonglong)*(ushort *)(param_1 + 0xb8) + 2) {
        *param_4 = 4;
        uVar2 = 0x80000005;
      }
      else {
        memmove(local_res8 + 1,*(void **)(param_1 + 0xc0),(ulonglong)uVar1);
        *param_4 = (ulonglong)*local_res8 + 2;
        uVar2 = 0;
      }
    }
  }
  return uVar2;
}



===== RequestHandleQueryPropertyDeviceUniqueId @ 140010040 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint RequestHandleQueryPropertyDeviceUniqueId(undefined8 param_1,undefined8 param_2)

{
  size_t _Size;
  byte bVar1;
  uint uVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  uint uVar6;
  ulonglong uVar7;
  undefined1 auStack_d8 [32];
  undefined8 local_b8;
  undefined4 *local_a8;
  ulonglong local_a0;
  longlong local_98 [2];
  undefined8 local_88;
  size_t sStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 local_58;
  size_t sStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_d8;
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1,DAT_14001a0f0);
  local_98[0] = 0;
  local_a8 = (undefined4 *)0x0;
  local_38 = 0;
  sStack_50 = 0;
  uVar7 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0x28;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_58);
  local_b8 = 0;
  uVar6 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_2,local_48,local_98);
  if (-1 < (int)uVar6) {
    bVar1 = KeGetCurrentIrql();
    _Size = sStack_50;
    if (bVar1 < 2) {
      if (*(int *)(local_98[0] + 4) == 1) {
        local_b8 = 0;
        local_a0 = sStack_50;
        uVar6 = (**(code **)(WdfFunctions_01015 + 0x870))
                          (WdfDriverGlobals,param_2,sStack_50,&local_a8);
        uVar7 = _Size;
        if (-1 < (int)uVar6) {
          memset(local_a8,0,_Size);
          *local_a8 = 1;
          local_a8[1] = 0x14;
          local_88 = local_58;
          sStack_80 = sStack_50;
          local_68 = local_38;
          local_78 = local_48;
          uStack_70 = uStack_40;
          uVar4 = RequestDuidGetDeviceIdProperty(lVar3,param_2,(longlong)&local_88,&local_a0);
          uVar6 = 0x80000005;
          local_88 = local_58;
          sStack_80 = sStack_50;
          local_68 = local_38;
          bVar1 = (byte)(uVar4 >> 0x1f) & 1 ^ 1;
          local_78 = local_48;
          uStack_70 = uStack_40;
          uVar5 = RequestDuidGetDeviceProperty(lVar3,param_2,(longlong)&local_88,&local_a0);
          uVar7 = local_a0;
          if ((int)uVar5 != -0x7ffffffb) {
            if (-1 < (int)uVar5) {
              bVar1 = 1;
            }
            if ((int)uVar4 != -0x7ffffffb) {
              uVar6 = ~-(uint)(bVar1 != 0) & 0xc0000225;
              goto LAB_140010274;
            }
          }
          if (local_a0 == 8) {
            uVar6 = 0;
          }
          else {
            uVar2 = (**(code **)(WdfFunctions_01015 + 0x8a0))(WdfDriverGlobals,param_2);
            uVar7 = (ulonglong)uVar2;
          }
        }
      }
      else if (*(int *)(local_98[0] + 4) == 0) {
        if (*(byte *)(local_98[0] + 8) < 2) {
          uVar6 = 0xc0000004;
        }
        else {
          uVar6 = 0xc000000d;
        }
      }
      else {
        uVar6 = 0xc00000bb;
      }
    }
    else {
      uVar6 = 0xc0000148;
    }
  }
LAB_140010274:
  RequestCompletion(lVar3,param_2,uVar6,uVar7);
  return uVar6;
}



===== RequestHandleQueryPropertyRetrieveCachedData @ 1400102b4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
RequestHandleQueryPropertyRetrieveCachedData
          (longlong param_1,undefined8 param_2,longlong param_3,ulonglong *param_4)

{
  uint uVar1;
  longlong lVar2;
  void *pvVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  longlong lVar6;
  longlong lVar7;
  ulonglong uVar8;
  void *local_res18;
  int *local_res20;
  
  lVar2 = WdfFunctions_01015;
  local_res20 = (int *)0x0;
  *param_4 = 0;
  uVar4 = (**(code **)(lVar2 + 0x868))
                    (WdfDriverGlobals,param_2,*(undefined8 *)(param_3 + 0x10),&local_res20,0);
  if ((int)uVar4 < 0) {
    return uVar4;
  }
  if (*local_res20 == 0) {
    uVar8 = *(ulonglong *)(param_3 + 8);
    if (uVar8 != 0) {
      lVar2 = *(longlong *)(param_1 + 200);
      if (uVar8 < 8) {
        *param_4 = (ulonglong)*(uint *)(lVar2 + 4);
        return 0xc0000023;
      }
      local_res18 = (void *)0x0;
      uVar4 = (**(code **)(WdfFunctions_01015 + 0x870))
                        (WdfDriverGlobals,param_2,uVar8,&local_res18,0);
      if ((int)uVar4 < 0) {
        return uVar4;
      }
      pvVar3 = *(void **)(param_1 + 200);
      uVar5 = (ulonglong)*(uint *)((longlong)pvVar3 + 4);
      uVar8 = *(ulonglong *)(param_3 + 8);
      if (uVar5 <= *(ulonglong *)(param_3 + 8)) {
        uVar8 = uVar5;
      }
      *param_4 = uVar8;
      memmove(local_res18,pvVar3,uVar8);
      lVar7 = -1;
      if (0xf < uVar8) {
        uVar1 = *(uint *)(*(longlong *)(param_1 + 200) + 0xc);
        if (uVar1 - 1 < 0xfffffffe) {
          lVar6 = -1;
          do {
            lVar6 = lVar6 + 1;
          } while (*(char *)((ulonglong)uVar1 + lVar2 + lVar6) != '\0');
          if (uVar8 < lVar6 + (ulonglong)uVar1) {
            *(undefined4 *)((longlong)local_res18 + 0xc) = 0;
          }
        }
      }
      if (0x13 < uVar8) {
        uVar1 = *(uint *)(*(longlong *)(param_1 + 200) + 0x10);
        if (uVar1 - 1 < 0xfffffffe) {
          lVar6 = -1;
          do {
            lVar6 = lVar6 + 1;
          } while (*(char *)((ulonglong)uVar1 + lVar2 + lVar6) != '\0');
          if (uVar8 < lVar6 + (ulonglong)uVar1) {
            *(undefined4 *)((longlong)local_res18 + 0x10) = 0;
          }
        }
      }
      if (0x17 < uVar8) {
        uVar1 = *(uint *)(*(longlong *)(param_1 + 200) + 0x14);
        if (uVar1 - 1 < 0xfffffffe) {
          lVar6 = -1;
          do {
            lVar6 = lVar6 + 1;
          } while (*(char *)((ulonglong)uVar1 + lVar2 + lVar6) != '\0');
          if (uVar8 < lVar6 + (ulonglong)uVar1) {
            *(undefined4 *)((longlong)local_res18 + 0x14) = 0;
          }
        }
      }
      if (uVar8 < 0x1c) {
        return 0;
      }
      uVar1 = *(uint *)(*(longlong *)(param_1 + 200) + 0x18);
      if (0xfffffffd < uVar1 - 1) {
        return 0;
      }
      do {
        lVar7 = lVar7 + 1;
      } while (*(char *)((ulonglong)uVar1 + lVar2 + lVar7) != '\0');
      if (uVar8 < lVar7 + (ulonglong)uVar1) {
        *(undefined4 *)((longlong)local_res18 + 0x18) = 0;
        return 0;
      }
      return 0;
    }
  }
  else {
    if (*local_res20 != 1) {
      return uVar4;
    }
    uVar8 = *(ulonglong *)(param_3 + 8);
    if (uVar8 != 0) {
      if (uVar8 < 8) {
        *param_4 = (ulonglong)*(uint *)(*(longlong *)(param_1 + 0xd0) + 4);
        return 0xc0000023;
      }
      local_res18 = (void *)0x0;
      uVar4 = (**(code **)(WdfFunctions_01015 + 0x870))
                        (WdfDriverGlobals,param_2,uVar8,&local_res18,0);
      if ((int)uVar4 < 0) {
        return uVar4;
      }
      pvVar3 = *(void **)(param_1 + 0xd0);
      uVar5 = (ulonglong)*(uint *)((longlong)pvVar3 + 4);
      uVar8 = *(ulonglong *)(param_3 + 8);
      if (uVar5 <= *(ulonglong *)(param_3 + 8)) {
        uVar8 = uVar5;
      }
      *param_4 = uVar8;
      memmove(local_res18,pvVar3,uVar8);
      return 0;
    }
  }
  *param_4 = 0;
  return 0;
}



===== RequestHandleQueryPropertyWriteCache @ 140010540 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int RequestHandleQueryPropertyWriteCache(undefined8 param_1,undefined8 param_2)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  longlong lVar4;
  undefined2 *puVar5;
  byte *_Dst;
  byte *pbVar6;
  uint uVar7;
  ulonglong uVar8;
  ulonglong _Size;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined4 **ppuVar11;
  undefined8 uVar12;
  undefined1 auStackY_a8 [32];
  undefined4 *local_78;
  undefined4 *local_70;
  longlong local_68;
  ulonglong uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_a8;
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1,DAT_14001a0f0);
  local_70 = (undefined4 *)0x0;
  local_48 = 0;
  uStack_60 = 0;
  local_78 = (undefined4 *)0x0;
  local_68 = 0x28;
  _Dst = (byte *)0x0;
  local_58 = 0;
  uStack_50 = 0;
  _Size = 0;
  puVar5 = (undefined2 *)0x0;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_68);
  ppuVar11 = &local_70;
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_2,local_58,ppuVar11);
  if (iVar2 < 0) goto LAB_14001088c;
  bVar1 = KeGetCurrentIrql();
  _Size = uStack_60;
  if (bVar1 < 2) {
    if ((uint)local_70[1] < 2) {
      if (7 < uStack_60) {
        ppuVar11 = &local_78;
        iVar2 = (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,param_2,uStack_60);
        if (iVar2 < 0) goto LAB_14001088c;
        memset(local_78,0,_Size);
        *local_78 = 0x1c;
        local_78[1] = 0x1c;
        if (_Size < 0x1c) {
          RequestCompletion(lVar4,param_2,0,8);
          return 0;
        }
        puVar5 = (undefined2 *)ExAllocatePool2(0x40);
        if (puVar5 == (undefined2 *)0x0) {
          iVar2 = -0x3fffff66;
          goto LAB_140010626;
        }
        *(undefined1 *)((longlong)local_78 + 0x1a) = 0;
        *(byte *)((longlong)local_78 + 0x19) = *(byte *)(lVar4 + 0x6c) >> 4 & 1;
        *puVar5 = 0x58;
        uVar3 = *(uint *)(lVar4 + 0x78);
        uVar7 = uVar3;
        if (uVar3 < 0x105) {
          uVar7 = 0x104;
          if (uVar3 * 4 < 0x104) {
            uVar7 = uVar3 * 4;
          }
        }
        *(uint *)(puVar5 + 10) = uVar7;
        ppuVar11 = (undefined4 **)0x0;
        puVar5[4] = 0x20ff;
        *(undefined4 *)(puVar5 + 6) = *(undefined4 *)(lVar4 + 0x74);
        *(undefined1 *)(puVar5 + 1) = 0;
        *(undefined1 *)(puVar5 + 5) = 10;
        *(undefined1 *)(puVar5 + 0x24) = 0x35;
        iVar2 = DeviceSendSrbSynchronously(param_1,puVar5,0,0,'\x01',param_2);
        if (iVar2 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            ppuVar11 = (undefined4 **)0x28;
            WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x28,
                              &WPP_7cea3eca420c34d4f6f4315c54c616a1_Traceguids,(char)iVar2);
          }
          iVar2 = 0;
          *(undefined1 *)(local_78 + 6) = 0;
        }
        else {
          *(undefined1 *)(local_78 + 6) = 1;
        }
        _Dst = (byte *)ExAllocatePool2(0x48,0xc0,0x4d436353);
        if (_Dst == (byte *)0x0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,5,0x29,
                             &WPP_7cea3eca420c34d4f6f4315c54c616a1_Traceguids);
          }
          iVar2 = -0x3fffff66;
LAB_14001080d:
          uVar9 = 0;
LAB_140010a45:
          ExFreePoolWithTag(puVar5,0);
        }
        else {
          uVar9 = 0xc0;
          memset(_Dst,0,0xc0);
          uVar3 = DeviceRetrieveModeSenseUsingScratch(lVar4,_Dst,uVar9,ppuVar11,'\0');
          _Size = (ulonglong)uVar3;
          if (_Size < 4) {
            uVar3 = DeviceRetrieveModeSenseUsingScratch(lVar4,_Dst,uVar9,ppuVar11,'\0');
            _Size = (ulonglong)uVar3;
            if (_Size < 4) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,5,0x2a,
                                 &WPP_7cea3eca420c34d4f6f4315c54c616a1_Traceguids);
              }
              iVar2 = -0x3ffffe7b;
              goto LAB_14001080d;
            }
          }
LAB_14001088c:
          uVar9 = 0;
          if (iVar2 < 0) {
LAB_1400109bf:
            if (-1 < iVar2) goto LAB_1400109cd;
          }
          else {
            uVar12 = CONCAT71((int7)((ulonglong)ppuVar11 >> 8),1);
            uVar8 = (ulonglong)*_Dst + 1;
            if (_Size <= (ulonglong)*_Dst + 1) {
              uVar8 = _Size;
            }
            pbVar6 = ModeSenseFindSpecificPage((longlong)_Dst,uVar8,8,'\x01');
            if (pbVar6 == (byte *)0x0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                uVar12 = 0x2b;
                WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x2b,
                                 &WPP_7cea3eca420c34d4f6f4315c54c616a1_Traceguids);
              }
              local_78[3] = 0;
              local_78[2] = 0;
            }
            else {
              local_78[3] = ((pbVar6[2] & 4) != 0) + 1;
              local_78[2] = pbVar6[2] >> 1 & 2;
            }
            uVar10 = 0xc0;
            local_78[5] = ((_Dst[2] & 0x10) != 0) + 1;
            memset(_Dst,0,0xc0);
            uVar3 = DeviceRetrieveModeSenseUsingScratch(lVar4,_Dst,uVar10,uVar12,'@');
            _Size = (ulonglong)uVar3;
            if (3 < _Size) goto LAB_1400109bf;
            uVar3 = DeviceRetrieveModeSenseUsingScratch(lVar4,_Dst,uVar10,uVar12,'@');
            _Size = (ulonglong)uVar3;
            if (3 < _Size) goto LAB_1400109bf;
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x2c,
                               &WPP_7cea3eca420c34d4f6f4315c54c616a1_Traceguids);
            }
            local_78[4] = 0;
LAB_1400109cd:
            uVar8 = (ulonglong)*_Dst + 1;
            if (_Size <= (ulonglong)*_Dst + 1) {
              uVar8 = _Size;
            }
            pbVar6 = ModeSenseFindSpecificPage((longlong)_Dst,uVar8,8,'\x01');
            if (pbVar6 == (byte *)0x0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x2d,
                                 &WPP_7cea3eca420c34d4f6f4315c54c616a1_Traceguids);
              }
              local_78[4] = 0;
            }
            else {
              local_78[4] = ((pbVar6[2] & 4) != 0) + 1;
            }
            uVar9 = 0x1c;
          }
          if (puVar5 != (undefined2 *)0x0) goto LAB_140010a45;
        }
        if (_Dst != (byte *)0x0) {
          ExFreePoolWithTag(_Dst,0);
        }
        goto LAB_140010a6c;
      }
      iVar2 = -0x3ffffffc;
    }
    else {
      iVar2 = -0x3fffff45;
    }
  }
  else {
    iVar2 = -0x3ffffeb8;
  }
LAB_140010626:
  uVar9 = 0;
LAB_140010a6c:
  RequestCompletion(lVar4,param_2,iVar2,uVar9);
  return iVar2;
}



===== RequestHandleSetHotPlugInfo @ 140010aac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int RequestHandleSetHotPlugInfo
              (longlong param_1,undefined8 param_2,longlong param_3,undefined8 *param_4)

{
  longlong lVar1;
  int iVar2;
  
  *param_4 = 0;
  if (*(ulonglong *)(param_3 + 0x10) < 8) {
    iVar2 = -0x3ffffffc;
  }
  else {
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals);
    if (-1 < iVar2) {
      lVar1 = *(longlong *)(param_1 + 0x478);
      if (iRam0000000000000000 != *(int *)(lVar1 + 0x18)) {
        iVar2 = -0x3fffff11;
      }
      if (cRam0000000000000004 != *(char *)(lVar1 + 0x1c)) {
        iVar2 = -0x3fffff10;
      }
      if (cRam0000000000000005 != *(char *)(lVar1 + 0x1d)) {
        iVar2 = -0x3fffff0f;
      }
      if (cRam0000000000000007 == *(char *)(lVar1 + 0x1f)) {
        if (-1 < iVar2) {
          *(char *)(lVar1 + 0x1e) = cRam0000000000000006;
          DeviceSetParameter(param_1,0x140015260,L"UserRemovalPolicy",
                             (cRam0000000000000006 != '\0') + 2);
        }
      }
      else {
        iVar2 = -0x3fffff0d;
      }
    }
  }
  return iVar2;
}



===== RequestHandleVolumeOnline @ 140010b90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
RequestHandleVolumeOnline
          (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 *param_4)

{
  longlong lVar1;
  undefined8 uVar2;
  int iVar3;
  longlong lVar4;
  
  *param_4 = 0;
  *(undefined1 *)(param_1 + 0x271) = 0;
  while( true ) {
    iVar3 = (**(code **)(WdfFunctions_01015 + 0x4f0))
                      (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x278));
    if (iVar3 < 0) break;
    RequestCompletion(param_1,0,0,0);
  }
  (**(code **)(WdfFunctions_01015 + 0x7d8))(WdfDriverGlobals,param_2);
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals,param_2);
  lVar1 = *(longlong *)(lVar4 + 0xb8);
  uVar2 = *(undefined8 *)(lVar4 + 0x18);
  *(longlong *)(lVar4 + 0x18) = param_1 + 0x68;
  *(undefined4 *)(lVar1 + -0x40) = 0;
  *(undefined4 *)(lVar1 + -0x38) = 4;
  *(undefined4 *)(lVar1 + -0x30) = 0x7c220;
  RequestSend(param_1,param_2,*(undefined8 *)(param_1 + 0x18),2,(char *)0x0);
  *(undefined8 *)(lVar4 + 0x18) = uVar2;
  return 0;
}



===== RequestValidateAacsBindingNonce @ 140010c9c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int RequestValidateAacsBindingNonce
              (longlong param_1,undefined8 param_2,longlong param_3,undefined8 *param_4)

{
  int iVar1;
  int iVar2;
  uint *local_res8 [4];
  
  local_res8[0] = (uint *)0x0;
  *param_4 = 0;
  if (*(char *)(param_1 + 0x289) == '\0') {
    iVar2 = -0x3ffffff0;
  }
  else if (*(longlong *)(param_3 + 0x10) == 0x18) {
    if (*(ulonglong *)(param_3 + 8) < 0x20) {
      *param_4 = 0x20;
      iVar2 = -0x3fffffdd;
    }
    else if (*(ulonglong *)(param_3 + 8) < 0x21) {
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_2,0x18,local_res8,0);
      iVar2 = iVar1;
      if (-1 < iVar1) {
        iVar2 = -0x3ffffff3;
        if ((*local_res8[0] < 5) && (local_res8[0][1] < 0x100)) {
          if (0xffffffff < *(ulonglong *)(local_res8[0] + 2)) {
            iVar1 = -0x3ffffff3;
          }
          iVar2 = iVar1;
        }
      }
    }
    else {
      iVar2 = -0x3ffffdfa;
    }
  }
  else {
    iVar2 = -0x3ffffffc;
  }
  return iVar2;
}



===== RequestValidateAacsEndSession @ 140010d50 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong RequestValidateAacsEndSession
                    (longlong param_1,undefined8 param_2,longlong param_3,undefined8 *param_4)

{
  longlong lVar1;
  ulonglong uVar2;
  undefined8 local_res8;
  
  lVar1 = WdfFunctions_01015;
  local_res8 = 0;
  *param_4 = 0;
  uVar2 = (**(code **)(lVar1 + 0x868))
                    (WdfDriverGlobals,param_2,*(undefined8 *)(param_3 + 0x10),&local_res8,0);
  if (-1 < (int)uVar2) {
    if (*(char *)(param_1 + 0x289) == '\0') {
      uVar2 = 0xc0000010;
    }
    else {
      uVar2 = uVar2 & 0xffffffff;
      if (*(longlong *)(param_3 + 0x10) != 4) {
        uVar2 = 0xc000000d;
      }
    }
  }
  return uVar2;
}



===== RequestValidateAacsGetCertificate @ 140010dc8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong RequestValidateAacsGetCertificate
                    (longlong param_1,undefined8 param_2,longlong param_3,undefined8 *param_4)

{
  ulonglong uVar1;
  uint *local_res8 [4];
  
  local_res8[0] = (uint *)0x0;
  *param_4 = 0;
  if (*(char *)(param_1 + 0x289) == '\0') {
    uVar1 = 0xc0000010;
  }
  else if (*(longlong *)(param_3 + 0x10) == 4) {
    if (*(ulonglong *)(param_3 + 8) < 0x70) {
      *param_4 = 0x70;
      uVar1 = 0xc0000023;
    }
    else if (*(ulonglong *)(param_3 + 8) < 0x71) {
      uVar1 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_2,4,local_res8,0);
      if ((-1 < (int)uVar1) && (uVar1 = uVar1 & 0xffffffff, 4 < *local_res8[0])) {
        uVar1 = 0xc000000d;
      }
    }
    else {
      uVar1 = 0xc0000206;
    }
  }
  else {
    uVar1 = 0xc0000004;
  }
  return uVar1;
}



===== RequestValidateAacsGetChallengeKey @ 140010e60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong RequestValidateAacsGetChallengeKey
                    (longlong param_1,undefined8 param_2,longlong param_3,undefined8 *param_4)

{
  ulonglong uVar1;
  uint *local_res8 [4];
  
  local_res8[0] = (uint *)0x0;
  *param_4 = 0;
  if (*(char *)(param_1 + 0x289) == '\0') {
    uVar1 = 0xc0000010;
  }
  else if (*(longlong *)(param_3 + 0x10) == 4) {
    if (*(ulonglong *)(param_3 + 8) < 0x50) {
      *param_4 = 0x50;
      uVar1 = 0xc0000023;
    }
    else if (*(ulonglong *)(param_3 + 8) < 0x51) {
      uVar1 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_2,4,local_res8,0);
      if ((-1 < (int)uVar1) && (uVar1 = uVar1 & 0xffffffff, 4 < *local_res8[0])) {
        uVar1 = 0xc000000d;
      }
    }
    else {
      uVar1 = 0xc0000206;
    }
  }
  else {
    uVar1 = 0xc0000004;
  }
  return uVar1;
}



===== RequestValidateAacsReadMediaId @ 140010ef8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong RequestValidateAacsReadMediaId
                    (longlong param_1,undefined8 param_2,longlong param_3,undefined8 *param_4)

{
  ulonglong uVar1;
  uint *local_res8 [4];
  
  local_res8[0] = (uint *)0x0;
  *param_4 = 0;
  if (*(char *)(param_1 + 0x289) == '\0') {
    uVar1 = 0xc0000010;
  }
  else if (*(longlong *)(param_3 + 0x10) == 4) {
    if (*(ulonglong *)(param_3 + 8) < 0x20) {
      *param_4 = 0x20;
      uVar1 = 0xc0000023;
    }
    else if (*(ulonglong *)(param_3 + 8) < 0x21) {
      uVar1 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_2,4,local_res8,0);
      if ((-1 < (int)uVar1) && (uVar1 = uVar1 & 0xffffffff, 4 < *local_res8[0])) {
        uVar1 = 0xc000000d;
      }
    }
    else {
      uVar1 = 0xc0000206;
    }
  }
  else {
    uVar1 = 0xc0000004;
  }
  return uVar1;
}



===== RequestValidateAacsReadMediaKeyBlock @ 140010f90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong RequestValidateAacsReadMediaKeyBlock
                    (longlong param_1,undefined8 param_2,longlong param_3,undefined8 *param_4)

{
  ulonglong uVar1;
  uint *local_res8 [4];
  
  local_res8[0] = (uint *)0x0;
  *param_4 = 0;
  if (*(char *)(param_1 + 0x289) == '\0') {
    uVar1 = 0xc0000010;
  }
  else if (*(longlong *)(param_3 + 0x10) == 4) {
    if (*(ulonglong *)(param_3 + 8) < 8) {
      *param_4 = 8;
      uVar1 = 0xc0000023;
    }
    else {
      uVar1 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_2,4,local_res8,0);
      if ((-1 < (int)uVar1) && (uVar1 = uVar1 & 0xffffffff, 0xff < *local_res8[0])) {
        uVar1 = 0xc000000d;
      }
    }
  }
  else {
    uVar1 = 0xc0000004;
  }
  return uVar1;
}



===== RequestValidateAacsSendCertificate @ 140011020 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong RequestValidateAacsSendCertificate
                    (longlong param_1,undefined8 param_2,longlong param_3,undefined8 *param_4)

{
  ulonglong uVar1;
  uint *local_res8 [4];
  
  local_res8[0] = (uint *)0x0;
  *param_4 = 0;
  if (*(char *)(param_1 + 0x289) == '\0') {
    uVar1 = 0xc0000010;
  }
  else if (*(longlong *)(param_3 + 0x10) == 0x74) {
    uVar1 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_2,0x74,local_res8,0);
    if ((-1 < (int)uVar1) && (uVar1 = uVar1 & 0xffffffff, 4 < *local_res8[0])) {
      uVar1 = 0xc000000d;
    }
  }
  else {
    uVar1 = 0xc0000004;
  }
  return uVar1;
}



===== RequestValidateAacsSendChallengeKey @ 140011094 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong RequestValidateAacsSendChallengeKey
                    (longlong param_1,undefined8 param_2,longlong param_3,undefined8 *param_4)

{
  ulonglong uVar1;
  uint *local_res8 [4];
  
  local_res8[0] = (uint *)0x0;
  *param_4 = 0;
  if (*(char *)(param_1 + 0x289) == '\0') {
    uVar1 = 0xc0000010;
  }
  else if (*(longlong *)(param_3 + 0x10) == 0x54) {
    uVar1 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_2,0x54,local_res8,0);
    if ((-1 < (int)uVar1) && (uVar1 = uVar1 & 0xffffffff, 4 < *local_res8[0])) {
      uVar1 = 0xc000000d;
    }
  }
  else {
    uVar1 = 0xc0000004;
  }
  return uVar1;
}



===== RequestValidateDvdEndSession @ 140011108 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
RequestValidateDvdEndSession
          (undefined8 param_1,undefined1 param_2,longlong param_3,undefined8 *param_4)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined8 local_res8 [4];
  
  lVar1 = WdfFunctions_01015;
  local_res8[0] = 0;
  *param_4 = 0;
  uVar2 = (**(code **)(lVar1 + 0x868))
                    (WdfDriverGlobals,param_2,*(undefined8 *)(param_3 + 0x10),local_res8,0);
  if ((-1 < (int)uVar2) && (*(ulonglong *)(param_3 + 0x10) < 4)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x30,
                       &WPP_7cea3eca420c34d4f6f4315c54c616a1_Traceguids);
    }
    uVar2 = 0xc000000d;
  }
  return uVar2;
}



===== RequestValidateDvdReadKey @ 14001119c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int RequestValidateDvdReadKey
              (longlong param_1,undefined8 param_2,longlong param_3,ulonglong *param_4)

{
  int iVar1;
  longlong lVar2;
  int iVar3;
  ulonglong uVar4;
  longlong local_res18;
  
  lVar2 = WdfFunctions_01015;
  local_res18 = 0;
  *param_4 = 0;
  iVar3 = (**(code **)(lVar2 + 0x868))
                    (WdfDriverGlobals,param_2,*(undefined8 *)(param_3 + 0x10),&local_res18,0);
  if (iVar3 < 0) {
    return iVar3;
  }
  uVar4 = 0x18;
  if (*(ulonglong *)(param_3 + 0x10) < 0x18) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x2e,
                       &WPP_7cea3eca420c34d4f6f4315c54c616a1_Traceguids);
    }
  }
  else {
    iVar1 = *(int *)(local_res18 + 8);
    if (iVar1 == 1) {
      uVar4 = 0x24;
    }
    else if (((iVar1 == 2) || (iVar1 == 3)) || (iVar1 == 4)) {
      uVar4 = 0x20;
    }
    else if ((iVar1 == 5) || (iVar1 == 8)) {
      uVar4 = 0x1c;
    }
    else if (iVar1 == 0x80) {
      uVar4 = 0x818;
    }
    if (*(ulonglong *)(param_3 + 8) < uVar4) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x2f,
                         &WPP_7cea3eca420c34d4f6f4315c54c616a1_Traceguids);
      }
      *param_4 = uVar4;
      return -0x3fffffdd;
    }
    if ((*(ulonglong *)(param_3 + 8) & (ulonglong)*(uint *)(*(longlong *)(param_1 + 0xd0) + 0x10))
        == 0) {
      if (*(int *)(param_1 + 0x3d0) == 0x33) {
        return iVar3;
      }
      return -0x3ffffff0;
    }
  }
  return -0x3ffffff3;
}



===== RequestValidateDvdReadStructure @ 140011318 =====

undefined4 RequestValidateDvdReadStructure(longlong param_1,longlong param_2,undefined8 *param_3)

{
  ulonglong uVar1;
  
  uVar1 = *(ulonglong *)(param_2 + 0x10);
  *param_3 = 0;
  if (uVar1 < 0x11) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x16,
                         &WPP_7cea3eca420c34d4f6f4315c54c616a1_Traceguids,
                         (char)*(undefined4 *)(param_2 + 0x10),0x11);
    }
  }
  else {
    uVar1 = *(ulonglong *)(param_2 + 8);
    if (uVar1 < 4) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x17,
                         &WPP_7cea3eca420c34d4f6f4315c54c616a1_Traceguids);
      }
      *param_3 = 4;
      return 0xc0000023;
    }
    if (uVar1 < 0x10000) {
      if ((uVar1 & *(uint *)(*(longlong *)(param_1 + 0xd0) + 0x10)) == 0) {
        if (*(int *)(param_1 + 0x3d0) == 0x33) {
          return 0;
        }
        return 0xc0000010;
      }
    }
    else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x18,
                       &WPP_7cea3eca420c34d4f6f4315c54c616a1_Traceguids);
    }
  }
  return 0xc000000d;
}



===== RequestValidateDvdSendKey @ 140011450 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong RequestValidateDvdSendKey
                    (longlong param_1,undefined8 param_2,longlong param_3,undefined8 *param_4)

{
  uint uVar1;
  longlong lVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  uint *local_res18 [2];
  
  lVar2 = WdfFunctions_01015;
  local_res18[0] = (uint *)0x0;
  *param_4 = 0;
  uVar3 = (**(code **)(lVar2 + 0x868))
                    (WdfDriverGlobals,param_2,*(undefined8 *)(param_3 + 0x10),local_res18,0);
  uVar4 = uVar3 & 0xffffffff;
  if ((int)uVar3 < 0) {
    return uVar3;
  }
  if ((*(ulonglong *)(param_3 + 0x10) < 0x18) ||
     (*(ulonglong *)(param_3 + 0x10) != (ulonglong)*local_res18[0])) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x1a,
                        &WPP_7cea3eca420c34d4f6f4315c54c616a1_Traceguids,(char)param_2);
    }
  }
  else if (*(int *)(param_3 + 0x18) == 0x335008) {
    uVar1 = local_res18[0][2];
    if (uVar1 == 1) {
      return uVar4;
    }
    if (uVar1 == 3) {
      return uVar4;
    }
    if (uVar1 == 0x3f) {
      return uVar4;
    }
  }
  else {
    uVar1 = local_res18[0][2];
    if (((uVar1 < 0x40) && ((0x800000000000017eU >> ((longlong)(int)uVar1 & 0x3fU) & 1) != 0)) ||
       (uVar1 == 0x80)) {
      if (*(int *)(param_1 + 0x3d0) == 0x33) {
        return uVar4;
      }
      return 0xc0000010;
    }
  }
  return 0xc000000d;
}



===== RequestValidateDvdStartSession @ 14001156c =====

undefined8 RequestValidateDvdStartSession(longlong param_1,longlong param_2,undefined8 *param_3)

{
  ulonglong uVar1;
  undefined8 uVar2;
  
  uVar1 = *(ulonglong *)(param_2 + 8);
  *param_3 = 0;
  if (uVar1 < 4) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x19,
                       &WPP_7cea3eca420c34d4f6f4315c54c616a1_Traceguids);
    }
    uVar2 = 0xc0000023;
    *param_3 = 4;
  }
  else {
    uVar2 = 0;
    if (*(int *)(param_1 + 0x3d0) != 0x33) {
      uVar2 = 0xc0000010;
    }
  }
  return uVar2;
}



===== RequestValidateEnableStreaming @ 1400115e4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong RequestValidateEnableStreaming(undefined8 param_1,longlong param_2,undefined8 *param_3)

{
  ulonglong uVar1;
  int *local_res10 [3];
  
  *param_3 = 0;
  local_res10[0] = (int *)0x0;
  if (*(ulonglong *)(param_2 + 0x10) < 4) {
    uVar1 = 0xc0000004;
  }
  else {
    uVar1 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_1,4,local_res10,0);
    if ((-1 < (int)uVar1) && (uVar1 = uVar1 & 0xffffffff, 3 < *local_res10[0] - 1U)) {
      uVar1 = 0xc000000d;
    }
  }
  return uVar1;
}



===== RequestValidateExclusiveAccess @ 140011654 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 RequestValidateExclusiveAccess(undefined8 param_1,longlong param_2,undefined8 *param_3)

{
  int iVar1;
  char cVar2;
  undefined8 uVar3;
  undefined2 uVar4;
  int *local_res18 [2];
  
  local_res18[0] = (int *)0x0;
  *param_3 = 0;
  cVar2 = KeGetCurrentIrql();
  if (cVar2 != '\0') {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x1b,
                       &WPP_7cea3eca420c34d4f6f4315c54c616a1_Traceguids);
    }
    return 0xc0000010;
  }
  if (*(ulonglong *)(param_2 + 0x10) < 8) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0xc0000004;
    }
    uVar4 = 0x1c;
  }
  else {
    uVar3 = (**(code **)(WdfFunctions_01015 + 0x868))
                      (WdfDriverGlobals,param_1,*(ulonglong *)(param_2 + 0x10),local_res18,0);
    if ((int)uVar3 < 0) {
      return uVar3;
    }
    iVar1 = *local_res18[0];
    if (iVar1 == 0) {
      if (0x40 < *(ulonglong *)(param_2 + 8)) {
        return uVar3;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x1d,
                         &WPP_7cea3eca420c34d4f6f4315c54c616a1_Traceguids);
      }
      *param_3 = 0x41;
      return 0xc0000023;
    }
    if (iVar1 != 1) {
      if (iVar1 == 2) {
        return uVar3;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x1f,
                         &WPP_7cea3eca420c34d4f6f4315c54c616a1_Traceguids);
      }
      return 0xc000000d;
    }
    if (0x47 < *(ulonglong *)(param_2 + 0x10)) {
      return uVar3;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0xc0000004;
    }
    uVar4 = 0x1e;
  }
  WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,uVar4,
                   &WPP_7cea3eca420c34d4f6f4315c54c616a1_Traceguids);
  return 0xc0000004;
}



===== RequestValidateGetPerformance @ 140011834 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int RequestValidateGetPerformance(undefined8 param_1,longlong param_2,undefined8 *param_3)

{
  int iVar1;
  int *local_res10;
  longlong local_res18 [2];
  
  *param_3 = 0;
  local_res10 = (int *)0x0;
  local_res18[0] = 0;
  if (*(ulonglong *)(param_2 + 0x10) < 4) {
LAB_140011865:
    iVar1 = -0x3ffffffc;
  }
  else {
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_1,4,&local_res10,0);
    if (iVar1 < 0) {
      return iVar1;
    }
    if (*local_res10 == 1) {
      if (*(ulonglong *)(param_2 + 0x10) < 0x14) goto LAB_140011865;
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_1,0x14,local_res18,0)
      ;
      if (iVar1 < 0) {
        return iVar1;
      }
      if ((*(int *)(local_res18[0] + 4) - 1U < 2) && (*(int *)(local_res18[0] + 8) - 1U < 3)) {
        if (*(int *)(local_res18[0] + 0xc) != 1) {
          iVar1 = -0x3ffffff3;
        }
        if (iVar1 < 0) {
          return iVar1;
        }
        goto LAB_140011919;
      }
    }
    else if (*local_res10 == 2) {
LAB_140011919:
      if (*(ulonglong *)(param_2 + 8) < 8) {
        *param_3 = 8;
        return -0x3fffffdd;
      }
      if (*(ulonglong *)(param_2 + 8) < 0x10000) {
        return iVar1;
      }
      return -0x3ffffff3;
    }
    iVar1 = -0x3ffffff3;
  }
  return iVar1;
}



===== RequestValidatePersistentReserve @ 140011950 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int RequestValidatePersistentReserve
              (longlong param_1,undefined8 param_2,longlong param_3,undefined8 *param_4)

{
  undefined8 uVar1;
  code *pcVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  byte bVar5;
  int iVar6;
  int iVar7;
  bool bVar8;
  ulonglong local_res20;
  
  uVar4 = WdfDriverGlobals;
  iVar7 = *(int *)(param_3 + 0x18);
  local_res20 = 0;
  uVar1 = *(undefined8 *)(param_3 + 0x10);
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x868);
  *param_4 = 0;
  iVar6 = (*pcVar2)(uVar4,param_2,uVar1,&local_res20,0);
  if (iVar6 < 0) {
    return iVar6;
  }
  uVar3 = *(ulonglong *)(param_3 + 0x10);
  if ((uVar3 < 0xc) || (*(uint *)(local_res20 + 4) < 0xc)) {
    iVar7 = -0x3ffffffc;
    goto LAB_140011a8b;
  }
  if ((local_res20 & *(uint *)(*(longlong *)(param_1 + 0xd0) + 0x10)) != 0) {
    iVar7 = -0x3fffff18;
    goto LAB_140011a8b;
  }
  if (iVar7 == 0x2d5018) {
    if (((ulonglong)*(ushort *)(local_res20 + 10) <= *(ulonglong *)(param_3 + 8)) &&
       (((*(byte *)(local_res20 + 8) & 0x1f) == 0 || ((*(byte *)(local_res20 + 8) & 0x1f) == 1)))) {
      bVar8 = *(ushort *)(local_res20 + 10) < 8;
LAB_140011a16:
      if (!bVar8) {
        return iVar6;
      }
    }
  }
  else {
    bVar5 = *(byte *)(local_res20 + 8) & 0x1f;
    if ((*(byte *)(local_res20 + 8) & 0x1f) != 0) {
      if ((bVar5 == 1) || (bVar5 == 2)) {
LAB_140011a47:
        bVar5 = *(byte *)(local_res20 + 9) >> 4;
        if ((bVar5 != 0) && (bVar5 != 2)) goto LAB_1400119f7;
        bVar5 = *(byte *)(local_res20 + 9) & 0xf;
        if (((bVar5 != 1) && (bVar5 != 3)) && (bVar5 != 5)) goto joined_r0x000140011a6e;
      }
      else if (bVar5 != 3) {
        if ((bVar5 == 4) || (bVar5 == 5)) goto LAB_140011a47;
joined_r0x000140011a6e:
        if (bVar5 != 6) goto LAB_1400119f7;
      }
    }
    if (0x23 < uVar3) {
      bVar8 = *(uint *)(local_res20 + 4) < uVar3;
      goto LAB_140011a16;
    }
  }
LAB_1400119f7:
  iVar7 = -0x3ffffff3;
LAB_140011a8b:
  *param_4 = 0;
  return iVar7;
}



===== RequestValidateReadQChannel @ 140011aac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 RequestValidateReadQChannel(undefined8 param_1,longlong param_2,ulonglong *param_3)

{
  char cVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  char *local_res10 [3];
  
  *param_3 = 0;
  local_res10[0] = (char *)0x0;
  if (*(ulonglong *)(param_2 + 0x10) < 2) {
    uVar2 = 0xc0000004;
  }
  else {
    uVar2 = (**(code **)(WdfFunctions_01015 + 0x868))
                      (WdfDriverGlobals,param_1,*(ulonglong *)(param_2 + 0x10),local_res10,0);
    if (-1 < (int)uVar2) {
      cVar1 = *local_res10[0];
      if (cVar1 == '\x01') {
        uVar3 = 0x10;
      }
      else {
        if ((cVar1 != '\x02') && (cVar1 != '\x03')) {
          return 0xc000000d;
        }
        uVar3 = 0x18;
      }
      if (*(ulonglong *)(param_2 + 8) < uVar3) {
        uVar2 = 0xc0000023;
        *param_3 = uVar3;
      }
    }
  }
  return uVar2;
}



===== RequestValidateReadTocEx @ 140011b4c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int RequestValidateReadTocEx
              (longlong param_1,undefined8 param_2,longlong param_3,undefined8 *param_4)

{
  ulonglong uVar1;
  int iVar2;
  byte bVar3;
  byte *local_res18 [2];
  
  local_res18[0] = (byte *)0x0;
  *param_4 = 0;
  if (*(ulonglong *)(param_3 + 0x10) < 4) {
    iVar2 = -0x3ffffffc;
  }
  else {
    uVar1 = *(ulonglong *)(param_3 + 8);
    if (uVar1 < 2) {
      iVar2 = -0x3fffffdd;
      *param_4 = 2;
    }
    else {
      if ((uVar1 < 0x10000) && ((uVar1 & *(uint *)(*(longlong *)(param_1 + 0xd0) + 0x10)) == 0)) {
        iVar2 = (**(code **)(WdfFunctions_01015 + 0x868))
                          (WdfDriverGlobals,param_2,*(ulonglong *)(param_3 + 0x10),local_res18,0);
        if (iVar2 < 0) {
          return iVar2;
        }
        if ((((*local_res18[0] & 0x70) == 0) && (local_res18[0][2] == 0)) &&
           (local_res18[0][3] == 0)) {
          bVar3 = *local_res18[0] & 0xf;
          if ((bVar3 < 6) && ((0x25U >> bVar3 & 1) != 0)) {
            return iVar2;
          }
          if ((((bVar3 - 1 & 0xfc) == 0) && (bVar3 != 2)) && (local_res18[0][1] == 0)) {
            return iVar2;
          }
        }
      }
      iVar2 = -0x3ffffff3;
    }
  }
  return iVar2;
}



===== RequestValidateSendOpcInformation @ 140011c30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong RequestValidateSendOpcInformation(undefined8 param_1,longlong param_2,undefined8 *param_3)

{
  ulonglong uVar1;
  int *local_res10 [3];
  
  *param_3 = 0;
  local_res10[0] = (int *)0x0;
  if (*(ulonglong *)(param_2 + 0x10) < 8) {
    uVar1 = 0xc0000004;
  }
  else {
    uVar1 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_1,8,local_res10,0);
    if ((-1 < (int)uVar1) && (uVar1 = uVar1 & 0xffffffff, *local_res10[0] != 1)) {
      uVar1 = 0xc000000d;
    }
  }
  return uVar1;
}



===== RequestValidateSetSpeed @ 140011c9c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int RequestValidateSetSpeed
              (longlong param_1,undefined8 param_2,longlong param_3,undefined8 *param_4)

{
  int iVar1;
  ulonglong uVar2;
  int *local_res8;
  
  local_res8 = (int *)0x0;
  uVar2 = 0xc;
  *param_4 = 0;
  if (*(ulonglong *)(param_3 + 0x10) < 0xc) {
    iVar1 = -0x3ffffffc;
  }
  else {
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_2,0xc,&local_res8,0);
    if (-1 < iVar1) {
      if (*local_res8 < 2) {
        if (*local_res8 != 0) {
          uVar2 = 0x24;
          if (*(char *)(param_1 + 0x288) == '\0') {
            iVar1 = -0x3ffffff0;
          }
          if (iVar1 < 0) {
            return iVar1;
          }
        }
        if (*(ulonglong *)(param_3 + 0x10) < uVar2) {
          iVar1 = -0x3ffffffc;
        }
      }
      else {
        iVar1 = -0x3ffffff3;
      }
    }
  }
  return iVar1;
}



===== WPP_RECORDER_SF_DiDs @ 140011d54 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_DiDs(undefined8 param_1)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  char *in_stack_00000048;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) && (2 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    if (in_stack_00000048 == (char *)0x0) {
      lVar3 = 5;
    }
    else {
      lVar2 = -1;
      do {
        lVar3 = lVar2;
        lVar2 = lVar3 + 1;
      } while (in_stack_00000048[lVar2] != '\0');
      lVar3 = lVar3 + 2;
    }
    pcVar1 = in_stack_00000048;
    if (in_stack_00000048 == (char *)0x0) {
      pcVar1 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_7cea3eca420c34d4f6f4315c54c616a1_Traceguids,0x15,&uStack0000000000000030,4,
               &uStack0000000000000038,8,&uStack0000000000000040,4,pcVar1,lVar3,0);
  }
  lVar3 = -1;
  if (in_stack_00000048 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    do {
      lVar2 = lVar3;
      lVar3 = lVar2 + 1;
    } while (in_stack_00000048[lVar3] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (in_stack_00000048 == (char *)0x0) {
    in_stack_00000048 = "NULL";
  }
  WppAutoLogTrace(param_1,3,5,&WPP_7cea3eca420c34d4f6f4315c54c616a1_Traceguids,0x15,
                  &uStack0000000000000030,4,&uStack0000000000000038,8,&uStack0000000000000040,4,
                  in_stack_00000048,lVar2,0);
  return;
}



===== WPP_RECORDER_SF_qdd @ 140011ef4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qdd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4
                        ,undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8
                        )

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_7cea3eca420c34d4f6f4315c54c616a1_Traceguids,param_4,&param_6,8,&param_7,4,
               &param_8,4,0);
  }
  WppAutoLogTrace(param_1,4,5,&WPP_7cea3eca420c34d4f6f4315c54c616a1_Traceguids,param_4,&param_6,8,
                  &param_7,4,&param_8,4,0);
  return;
}



===== WPP_RECORDER_SF_qqqL @ 140011fe8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqqL(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_7cea3eca420c34d4f6f4315c54c616a1_Traceguids,0x53,&uStack0000000000000030,8,
               &uStack0000000000000038,8,&uStack0000000000000040,8,&uStack0000000000000048,4,0);
  }
  WppAutoLogTrace(param_1,4,5,&WPP_7cea3eca420c34d4f6f4315c54c616a1_Traceguids,0x53,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,&uStack0000000000000040,8,
                  &uStack0000000000000048,4,0);
  return;
}



===== WPP_RECORDER_SF_sq @ 1400120fc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sq(undefined8 param_1)

{
  undefined1 uStack0000000000000038;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) && (2 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_7cea3eca420c34d4f6f4315c54c616a1_Traceguids,0x13,"size (5)",9,
               &uStack0000000000000038,8,0);
  }
  WppAutoLogTrace(param_1,3,5,&WPP_7cea3eca420c34d4f6f4315c54c616a1_Traceguids,0x13,"size (5)",9,
                  &uStack0000000000000038,8,0);
  return;
}



===== DeviceErrorHandlerForHitachiGD2000 @ 1400121e0 =====

undefined8
DeviceErrorHandlerForHitachiGD2000
          (longlong param_1,longlong param_2,undefined4 *param_3,undefined1 *param_4)

{
  if (((*(char *)(param_2 + 3) < '\0') &&
      ((*(byte *)(*(longlong *)(param_2 + 0x20) + 2) & 0xf) == 4)) &&
     (*(char *)(*(longlong *)(param_2 + 0x20) + 0xc) == 'D')) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x14,
                        &WPP_14ceea506f553d1aa69114b6e3475b08_Traceguids,
                        (char)*(undefined8 *)(param_1 + 0x10));
    }
    *param_4 = 1;
    *param_3 = 0xc00000a3;
    DeviceSendStartUnit(*(undefined8 *)(param_1 + 0x10));
  }
  return 0;
}



===== McTemplateK0z_EtwWriteTransfer @ 140012280 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0z_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,wchar_t *param_4)

{
  longlong lVar1;
  undefined1 auStackY_68 [32];
  undefined8 local_38 [2];
  wchar_t *local_28;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  if (param_4 == (wchar_t *)0x0) {
    local_20 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_4[lVar1] != L'\0');
    local_20 = (int)lVar1 * 2 + 2;
  }
  local_1c = 0;
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"NULL";
  }
  local_28 = param_4;
  McGenEventWrite_EtwWriteTransfer(L"NULL",&CHANGE_EVENT,param_3,2,local_38);
  return;
}



===== WPP_RECORDER_SF_dL @ 140012308 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_dL(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])
     ) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_14ceea506f553d1aa69114b6e3475b08_Traceguids,0x3d,&uStack0000000000000030,4,
               &uStack0000000000000038,4,0);
  }
  WppAutoLogTrace(param_1,4,0xd,&WPP_14ceea506f553d1aa69114b6e3475b08_Traceguids,0x3d,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,0);
  return;
}



===== WPP_RECORDER_SF_qL @ 1400123d8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qL(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])
     ) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_bfcef3ce16aa3c5196ed71474c974d5c_Traceguids,0x53,&uStack0000000000000030,8,
               &uStack0000000000000038,4,0);
  }
  WppAutoLogTrace(param_1,4,0xd,&WPP_bfcef3ce16aa3c5196ed71474c974d5c_Traceguids,0x53,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,0);
  return;
}



===== CompressSrbHistoryData @ 1400124ac =====

void CompressSrbHistoryData(longlong *param_1)

{
  longlong *_Dst;
  byte bVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  longlong lVar5;
  uint uVar6;
  ulonglong uVar7;
  uint uVar8;
  uint uVar9;
  
  uVar6 = *(uint *)((longlong)param_1 + 0x24);
  if (uVar6 != 0) {
    uVar7 = 0;
    do {
      uVar8 = (int)uVar7 + 1;
      bVar1 = *(byte *)((longlong)param_1 + uVar7 * 0x28 + 0x3e);
      cVar2 = *(char *)((longlong)param_1 + uVar7 * 0x28 + 0x4e);
      lVar5 = param_1[uVar7 * 5 + 9];
      cVar3 = *(char *)((longlong)param_1 + uVar7 * 0x28 + 0x49);
      for (uVar9 = uVar8;
          (cVar4 = *(char *)((longlong)param_1 + uVar7 * 0x28 + 0x4f), cVar4 != -1 &&
          (uVar9 < uVar6)); uVar9 = uVar9 + 1) {
        _Dst = param_1 + ((ulonglong)uVar9 + 1) * 5;
        if ((cVar2 == *(char *)((longlong)_Dst + 0x26)) &&
           ((((bVar1 & 0xf) == (*(byte *)((longlong)_Dst + 0x16) & 0xf) &&
             ((char)lVar5 == (char)_Dst[4])) && (cVar3 == *(char *)((longlong)_Dst + 0x21))))) {
          uVar6 = (int)_Dst[2] + *(uint *)(param_1 + uVar7 * 5 + 7);
          if (uVar6 < *(uint *)(param_1 + uVar7 * 5 + 7)) {
            uVar6 = 0xffffffff;
          }
          *(uint *)(param_1 + uVar7 * 5 + 7) = uVar6;
          *(char *)((longlong)param_1 + uVar7 * 0x28 + 0x4f) = cVar4 + '\x01';
          uVar6 = *(uint *)((longlong)param_1 + 0x24);
          if (uVar9 != uVar6 - 1) {
            memmove(_Dst,_Dst + 5,(ulonglong)((uVar6 - uVar9) - 1) * 0x28);
            *(int *)((longlong)param_1 + 0x24) = *(int *)((longlong)param_1 + 0x24) + -1;
            uVar6 = *(uint *)((longlong)param_1 + 0x24);
            uVar9 = uVar9 - 1;
          }
        }
      }
      uVar7 = (ulonglong)uVar8;
    } while (uVar8 < uVar6);
  }
  uVar9 = *(uint *)(param_1 + 4);
  if (uVar6 == uVar9) {
    *param_1 = *param_1 +
               (ulonglong)*(byte *)((longlong)param_1 + (ulonglong)(uVar9 - 1) * 0x28 + 0x4f);
    uVar6 = uVar6 - 1;
    *(uint *)((longlong)param_1 + 0x24) = uVar6;
  }
  memset(param_1 + ((ulonglong)uVar6 + 1) * 5,0,(ulonglong)(uVar9 - uVar6) * 0x28);
  return;
}



===== ScratchBuffer_ReadWriteEvtRequestCancel @ 140012610 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ScratchBuffer_ReadWriteEvtRequestCancel(undefined8 param_1)

{
  longlong lVar1;
  undefined1 uVar2;
  char cVar3;
  longlong *plVar4;
  
  plVar4 = (longlong *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_CDROM_REQUEST_CONTEXT_TYPE_INFO_14001a018);
  lVar1 = *plVar4;
  uVar2 = KeAcquireSpinLockRaiseToDpc(plVar4 + 9);
  cVar3 = KeCancelTimer(plVar4 + 10);
  if (cVar3 != '\0') {
    (**(code **)(WdfFunctions_01015 + 0x670))
              (WdfDriverGlobals,param_1,0,0x25a,"minkernel\\storage\\cdrom\\scratch.c");
  }
  *(undefined1 *)(plVar4 + 0x1a) = 1;
  KeReleaseSpinLock(plVar4 + 9,uVar2);
  ScratchBuffer_EndUse(lVar1);
  RequestCompletion(lVar1,param_1,-0x3ffffee0,(ulonglong)*(uint *)(lVar1 + 0x44c));
  return;
}



===== ScratchBuffer_ReadWriteTimerRoutine @ 140012710 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ScratchBuffer_ReadWriteTimerRoutine(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  int iVar2;
  longlong *plVar3;
  
  if (param_2 != 0) {
    plVar3 = (longlong *)
             (**(code **)(WdfFunctions_01015 + 0x650))
                       (WdfDriverGlobals,param_2,PTR__WDF_CDROM_REQUEST_CONTEXT_TYPE_INFO_14001a018)
    ;
    KeAcquireSpinLockRaiseToDpc(plVar3 + 9);
    if ((char)plVar3[0x1a] == '\0') {
      iVar2 = (**(code **)(WdfFunctions_01015 + 0x800))(WdfDriverGlobals,param_2);
    }
    else {
      iVar2 = -0x3ffffee0;
    }
    KeReleaseSpinLock(plVar3 + 9);
    if (iVar2 != -0x3ffffee0) {
      lVar1 = *plVar3;
      iVar2 = ScratchBuffer_PerformNextReadWrite(lVar1,'\0');
      if (iVar2 < 0) {
        ScratchBuffer_EndUse(lVar1);
        RequestCompletion(lVar1,param_2,iVar2,(ulonglong)*(uint *)(lVar1 + 0x44c));
      }
    }
    (**(code **)(WdfFunctions_01015 + 0x670))
              (WdfDriverGlobals,param_2,0,0x232,"minkernel\\storage\\cdrom\\scratch.c");
  }
  return;
}



===== DeviceScratchPreventMediaRemoval @ 14001283c =====

undefined4 DeviceScratchPreventMediaRemoval(longlong param_1)

{
  undefined4 uVar1;
  undefined8 local_18;
  undefined8 uStack_10;
  
  ScratchBuffer_BeginUseX(param_1);
  uStack_10 = 0;
  local_18 = 0x1e;
  uVar1 = ScratchBuffer_ExecuteCdbEx(param_1,0,0,'\0',&local_18,6,0);
  ScratchBuffer_EndUse(param_1);
  return uVar1;
}



===== RequestIssueShutdownFlush @ 1400128a4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 RequestIssueShutdownFlush(longlong param_1,longlong param_2)

{
  uint uVar1;
  char *pcVar2;
  longlong lVar3;
  code *pcVar4;
  longlong lVar5;
  longlong lVar6;
  uint uVar7;
  code *pcVar8;
  undefined4 local_res8 [2];
  undefined8 local_res10;
  
  pcVar2 = *(char **)(param_2 + 0xb8);
  pcVar8 = (code *)0x0;
  local_res8[0] = 0;
  lVar5 = 0;
  lVar6 = *(longlong *)(param_1 + 0x408);
  if (*pcVar2 == '\t') {
    lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 0x18);
    pcVar4 = *(code **)(lVar3 + 0x18);
    pcVar8 = *(code **)(lVar3 + 0x10);
    if (pcVar4 != (code *)0x0) {
      (*pcVar4)(param_2);
    }
    if (pcVar8 != (code *)0x0) {
      lVar5 = KeQueryPerformanceCounter(0);
    }
  }
  ScratchBuffer_BeginUseX(param_1);
  ScratchBuffer_SetupSrb(param_1,0,0,'\0');
  *(undefined2 *)(lVar6 + 8) = 0x20ff;
  uVar1 = *(uint *)(param_1 + 0x78);
  uVar7 = uVar1;
  if (uVar1 < 0x105) {
    uVar7 = 0x104;
    if (uVar1 * 4 < 0x104) {
      uVar7 = uVar1 * 4;
    }
  }
  *(uint *)(lVar6 + 0x14) = uVar7;
  *(undefined1 *)(lVar6 + 10) = 0;
  *(char *)(lVar6 + 2) = (*pcVar2 != '\x10') + '\a';
  ScratchBuffer_SendSrb(param_1,'\x01',(undefined8 *)0x0);
  RequestSenseInfoInterpret
            (param_1,*(undefined8 *)(param_1 + 0x400),*(undefined8 **)(param_1 + 0x408),0,
             (undefined **)local_res8,&local_res10);
  local_res8[0] =
       (**(code **)(WdfFunctions_01015 + 0x7f0))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x400));
  ScratchBuffer_EndUse(param_1);
  if ((*pcVar2 == '\t') && (pcVar8 != (code *)0x0)) {
    lVar6 = KeQueryPerformanceCounter(0);
    (*pcVar8)(0,*(undefined4 *)(param_1 + 0x68),param_2,lVar6 - lVar5);
  }
  return local_res8[0];
}



===== RequestProcessPowerIrpCompletion @ 140012a10 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 RequestProcessPowerIrpCompletion(undefined8 param_1,longlong param_2,longlong param_3)

{
  byte *pbVar1;
  undefined8 uVar2;
  
  if (*(char *)(param_2 + 0x41) != '\0') {
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
  }
  *(int *)(param_3 + 0x1e8) = *(int *)(param_3 + 0x1e8) + 1;
  if ((*(uint *)(param_3 + 0x1ec) & 2) == 0) {
    if (*(char *)(param_3 + 0x1c8) != '\0') {
      *(undefined1 *)(param_3 + 0x1c8) = 0;
      *(undefined8 *)(param_3 + 0x1e0) = _DAT_fffff78000000320;
    }
    uVar2 = 0;
  }
  else {
    DeviceSendPowerDownProcessRequest(param_3,0x14000d5e0,param_2);
    uVar2 = 0xc0000016;
  }
  return uVar2;
}



===== Feature_1596350777__private_IsEnabledDeviceUsageNoInline @ 140012a84 =====

ulonglong Feature_1596350777__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_1596350777__private_featureState;
  if ((Feature_1596350777__private_featureState & 0x10) == 0) {
    uVar1 = Feature_1596350777__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_1596350777__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_1596350777__private_IsEnabledFallback @ 140012abc =====

void Feature_1596350777__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_1596350777__private_descriptor);
  return;
}



===== WPP_RECORDER_SF_Ldd @ 140012ad8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_Ldd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0) && (2 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_9bb309afef393e3146adaf4bb6d607a2_Traceguids,0xd,&uStack0000000000000030,4,
               &uStack0000000000000038,4,&uStack0000000000000040,4,0);
  }
  WppAutoLogTrace(param_1,3,9,&WPP_9bb309afef393e3146adaf4bb6d607a2_Traceguids,0xd,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,&uStack0000000000000040,4,0);
  return;
}



===== WPP_RECORDER_SF_DqDD @ 140012bc8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_DqDD(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined4 local_18 [4];
  
  local_18[0] = 60000;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_af14ec63502f3054fdb449d0dcf290f5_Traceguids,0x12,&uStack0000000000000030,4,
               &uStack0000000000000038,8,&uStack0000000000000040,4,local_18,4,0);
  }
  WppAutoLogTrace(param_1,4,3,&WPP_af14ec63502f3054fdb449d0dcf290f5_Traceguids,0x12,
                  &uStack0000000000000030,4,&uStack0000000000000038,8,&uStack0000000000000040,4,
                  local_18,4,0);
  return;
}



===== FxStubDriverUnload @ 140012cf0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FxStubDriverUnload(void)

{
  if ((DAT_14001a498 != (code *)0x0) && (DAT_14001a498 != FxStubDriverUnload)) {
    (*DAT_14001a498)();
  }
  FxStubDriverUnloadCommon();
  return;
}



===== FxGetNextClassBindInfo @ 140012d24 =====

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



===== _guard_check_icall @ 140012d80 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 140012d98 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 140012dbc =====

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



===== __cpu_features_init @ 140012e30 =====

/* WARNING: Removing unreachable block (ram,0x000140012e9a) */
/* WARNING: Removing unreachable block (ram,0x000140012e49) */
/* WARNING: Removing unreachable block (ram,0x000140012e3a) */

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



===== __security_check_cookie @ 140012f00 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140012f40 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 140012f70 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140012f70. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140012fa0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memmove @ 140013000 =====

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



===== memset @ 140013300 =====

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



===== __memset_repmovs @ 140013440 =====

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



===== __memset_query @ 1400134c0 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140013540 =====

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



===== __memset_spec_ermsb_repmovsb @ 140013680 =====

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



===== __memset_spec_plain @ 140013700 =====

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



===== DeviceInitializeDvd @ 14001f008 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 DeviceInitializeDvd(undefined8 param_1)

{
  uint uVar1;
  longlong lVar2;
  longlong *plVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  longlong *plVar6;
  ulonglong local_res10;
  undefined8 in_stack_ffffffffffffffd8;
  
  local_res10 = 0;
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1,DAT_14001a0f0);
  if (*(int *)(lVar2 + 0x3d0) == 0x33) {
    plVar3 = (longlong *)ExAllocatePool2(0x100,0x1c);
    if (plVar3 == (longlong *)0x0) {
      return 0xc000009a;
    }
    *(undefined4 *)((longlong)plVar3 + 4) = 0;
    *(undefined8 *)((longlong)plVar3 + 0xc) = 0;
    uVar5 = 0;
    *(undefined8 *)((longlong)plVar3 + 0x14) = 0;
    uVar4 = 0x335004;
    *(undefined4 *)plVar3 = 0x1c;
    *(undefined4 *)(plVar3 + 1) = 8;
    plVar6 = plVar3;
    uVar1 = DvdStartSessionReadKey
                      (lVar2,0x335004,0,plVar3,in_stack_ffffffffffffffd8,(uint *)plVar3,0x1c,
                       &local_res10);
    if ((-1 < (int)uVar1) && (*(byte *)(plVar3 + 3) < 0x40)) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        plVar6 = (longlong *)0x3d;
        uVar4 = CONCAT71((int7)((ulonglong)uVar4 >> 8),3);
        uVar5 = 2;
        WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,2,0x3d,
                          &WPP_c6cef56efab5359de7c6f40b77738682_Traceguids,(char)param_1);
      }
      *(undefined4 *)(lVar2 + 0x354) = 1;
      if (*(char *)(lVar2 + 0x28c) != '\0') {
        DevicePickDvdRegion(param_1,uVar4,uVar5,plVar6);
      }
    }
    ExFreePoolWithTag(plVar3,0);
  }
  return 0;
}



===== DeviceDeallocateMmcResources @ 14001f154 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void DeviceDeallocateMmcResources(undefined8 param_1)

{
  longlong lVar1;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1,DAT_14001a0f0);
  if (*(longlong *)(lVar1 + 0x2f8) != 0) {
    IoFreeIrp();
    *(undefined8 *)(lVar1 + 0x2f8) = 0;
  }
  if (*(longlong *)(lVar1 + 0x330) != 0) {
    IoFreeMdl();
    *(undefined8 *)(lVar1 + 0x330) = 0;
  }
  if (*(longlong *)(lVar1 + 800) != 0) {
    ExFreePoolWithTag(*(longlong *)(lVar1 + 800),0);
    *(undefined8 *)(lVar1 + 800) = 0;
  }
  if (*(longlong *)(lVar1 + 0x300) != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
    *(undefined8 *)(lVar1 + 0x300) = 0;
  }
  *(undefined4 *)(lVar1 + 0x328) = 0;
  *(undefined1 *)(lVar1 + 0x288) = 0;
  *(undefined1 *)(lVar1 + 0x28b) = 0;
  return;
}



===== WppInitKm @ 14001f224 =====

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



===== RequestGetScsiPassThroughCdb @ 14001f300 =====

longlong RequestGetScsiPassThroughCdb(longlong param_1)

{
  int iVar1;
  uint uVar2;
  longlong lVar3;
  char cVar4;
  longlong lVar5;
  bool bVar6;
  
  lVar5 = 0;
  iVar1 = *(int *)(*(longlong *)(param_1 + 0xb8) + 0x18);
  if (((iVar1 == 0x4d004) ||
      ((iVar1 - 0x4d014U < 0x35 &&
       ((0x11000000000001U >> ((ulonglong)(iVar1 - 0x4d014U) & 0x3f) & 1) != 0)))) &&
     (lVar3 = *(longlong *)(param_1 + 0x18), lVar3 != 0)) {
    uVar2 = *(uint *)(*(longlong *)(param_1 + 0xb8) + 0x10);
    bVar6 = (iVar1 - 0x4d044U & 0xfffffffb) == 0;
    cVar4 = IoIs32bitProcess();
    if (cVar4 == '\0') {
      if (bVar6) {
        if (uVar2 < 0x40) {
          return 0;
        }
        return lVar3 + 0x38;
      }
      lVar5 = lVar3 + 0x24;
      bVar6 = uVar2 < 0x38;
    }
    else {
      if (bVar6) {
        if (uVar2 < 0x34) {
          return 0;
        }
        return lVar3 + 0x30;
      }
      lVar5 = lVar3 + 0x1c;
      bVar6 = uVar2 < 0x2c;
    }
    if (bVar6) {
      lVar5 = 0;
    }
  }
  return lVar5;
}



===== DevicePowerSettingCallback @ 14001f3d0 =====

undefined8
DevicePowerSettingCallback(longlong *param_1,char *param_2,undefined8 param_3,longlong param_4)

{
  uint *puVar1;
  longlong lVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar4 = (undefined4)((ulonglong)param_3 >> 0x20);
  lVar2 = *param_1 + -0x470feaa4e1233993;
  if (lVar2 == 0) {
    lVar2 = param_1[1] + -0x71fbb6c151a3e79d;
  }
  if ((((lVar2 == 0) && ((int)param_3 == 4)) && (param_2 != (char *)0x0)) &&
     ((*(char *)(param_4 + 8) != '\0' && (*(longlong *)(param_4 + 0x120) == 0)))) {
    uVar3 = CONCAT31((int3)((ulonglong)param_3 >> 8),1);
    if (*param_2 == '\0') {
      puVar1 = (uint *)(*(longlong *)(param_4 + 0x118) + 0xe8);
      *puVar1 = *puVar1 & 0xffefffff;
      DeviceMarkActive(param_4,(longlong *)CONCAT71((int7)((ulonglong)param_2 >> 8),1),
                       (uint *)CONCAT44(uVar4,uVar3));
    }
    else {
      DeviceMarkActive(param_4,(longlong *)0x0,(uint *)CONCAT44(uVar4,uVar3));
      puVar1 = (uint *)(*(longlong *)(param_4 + 0x118) + 0xe8);
      *puVar1 = *puVar1 | 0x100000;
    }
  }
  return 0;
}



===== DeviceIsMediaChangeDisabledDueToHardwareLimitation @ 14001f45c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 DeviceIsMediaChangeDisabledDueToHardwareLimitation(longlong param_1)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  longlong lVar4;
  code *pcVar5;
  ulonglong uVar6;
  short sVar7;
  longlong lVar8;
  size_t _Size;
  void *_Src;
  size_t sVar9;
  undefined1 uVar10;
  void *_Src_00;
  void *_Src_01;
  uint local_res8 [2];
  undefined8 local_res10;
  undefined8 local_d8;
  void *local_d0;
  undefined8 local_c8;
  longlong local_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  code *local_a8;
  undefined4 local_a0;
  wchar_t *local_98;
  uint *local_90;
  undefined4 local_88;
  wchar_t *local_80;
  undefined4 local_78;
  
  lVar4 = *(longlong *)(param_1 + 200);
  _Src_01 = (void *)0x0;
  local_res10 = 0;
  memset(&local_a8,0,0x70);
  local_c8 = 0;
  local_d8 = 0;
  local_res8[0] = 0;
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x3b8))
                    (WdfDriverGlobals,*WdfDriverGlobals,0xf003f,0,&local_res10);
  if ((int)uVar3 < 0) {
    return CONCAT62((int6)((ulonglong)uVar3 >> 0x10),1);
  }
  local_d0 = (void *)0x0;
  local_c0 = 0;
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x740))(WdfDriverGlobals,local_res10);
  uVar1 = *(uint *)(lVar4 + 0xc);
  uVar10 = 1;
  if ((uVar1 != 0) || (*(int *)(lVar4 + 0x10) != 0)) {
    _Size = 0xffffffffffffffff;
    lVar8 = 0;
    if (uVar1 == 0) {
      _Src = (void *)0x0;
    }
    else {
      _Src = (void *)(lVar4 + (ulonglong)uVar1);
      lVar8 = -1;
      do {
        lVar8 = lVar8 + 1;
      } while (*(char *)((longlong)_Src + lVar8) != '\0');
    }
    sVar7 = (short)lVar8;
    if (*(uint *)(lVar4 + 0x10) == 0) {
      _Src_00 = (void *)0x0;
    }
    else {
      _Src_00 = (void *)(lVar4 + (ulonglong)*(uint *)(lVar4 + 0x10));
      lVar8 = -1;
      do {
        lVar8 = lVar8 + 1;
      } while (*(char *)((longlong)_Src_00 + lVar8) != '\0');
      sVar7 = sVar7 + (short)lVar8;
    }
    if (*(uint *)(lVar4 + 0x14) != 0) {
      _Src_01 = (void *)(lVar4 + (ulonglong)*(uint *)(lVar4 + 0x14));
      lVar4 = -1;
      do {
        lVar4 = lVar4 + 1;
      } while (*(char *)((longlong)_Src_01 + lVar4) != '\0');
      sVar7 = sVar7 + (short)lVar4;
    }
    local_d8._0_4_ = CONCAT22(sVar7 + 1,sVar7);
    local_d0 = (void *)ExAllocatePool2(0x40,sVar7 + 1,0x41436353);
    if (local_d0 == (void *)0x0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,0xd,0x46,
                         &WPP_bfcef3ce16aa3c5196ed71474c974d5c_Traceguids);
      }
    }
    else {
      lVar4 = 0;
      if (_Src != (void *)0x0) {
        sVar9 = 0xffffffffffffffff;
        do {
          sVar9 = sVar9 + 1;
        } while (*(char *)((longlong)_Src + sVar9) != '\0');
        memmove(local_d0,_Src,sVar9);
        lVar4 = -1;
        do {
          lVar4 = lVar4 + 1;
        } while (*(char *)((longlong)_Src + lVar4) != '\0');
      }
      if (_Src_00 != (void *)0x0) {
        sVar9 = 0xffffffffffffffff;
        do {
          sVar9 = sVar9 + 1;
        } while (*(char *)((longlong)_Src_00 + sVar9) != '\0');
        memmove((void *)((longlong)local_d0 + lVar4),_Src_00,sVar9);
        lVar8 = -1;
        do {
          lVar8 = lVar8 + 1;
        } while (*(char *)((longlong)_Src_00 + lVar8) != '\0');
        lVar4 = lVar4 + lVar8;
      }
      if (_Src_01 != (void *)0x0) {
        do {
          _Size = _Size + 1;
        } while (*(char *)((longlong)_Src_01 + _Size) != '\0');
        memmove((void *)((longlong)local_d0 + lVar4),_Src_01,_Size);
      }
      *(undefined1 *)((local_d8 & 0xffff) + (longlong)local_d0) = 0;
      iVar2 = RtlAnsiStringToUnicodeString(&local_c8,&local_d8,1);
      if (iVar2 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,0xd,0x47,
                            &WPP_bfcef3ce16aa3c5196ed71474c974d5c_Traceguids,(char)iVar2);
        }
      }
      else {
        local_a0 = 4;
        local_a8 = DeviceMediaChangeRegistryCallBack;
        local_88 = 7;
        local_98 = L"AutoRunAlwaysDisable";
        local_90 = local_res8;
        local_78 = 0;
        local_80 = L"";
        local_b8 = 0;
        uStack_b0 = 0;
        RtlInitUnicodeString(&local_b8,L"RtlQueryRegistryValuesEx");
        pcVar5 = (code *)MmGetSystemRoutineAddress(&local_b8);
        if (pcVar5 == (code *)0x0) {
          pcVar5 = RtlQueryRegistryValues_exref;
        }
        (*pcVar5)(0x40000000,uVar3,&local_a8,&local_c8,0);
      }
    }
  }
  if (local_d0 != (void *)0x0) {
    ExFreePoolWithTag(local_d0,0);
    local_d0 = (void *)0x0;
  }
  if (local_c0 != 0) {
    RtlFreeUnicodeString(&local_c8);
  }
  (**(code **)(WdfFunctions_01015 + 0x738))(WdfDriverGlobals,local_res10);
  uVar6 = (ulonglong)local_res8[0];
  if (local_res8[0] != 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,0xd,0x48,
                       &WPP_bfcef3ce16aa3c5196ed71474c974d5c_Traceguids);
      uVar6 = (ulonglong)local_res8[0];
    }
    if ((int)uVar6 != 0) goto LAB_14001f7fd;
  }
  uVar10 = 0;
LAB_14001f7fd:
  return CONCAT71((int7)(uVar6 >> 8),uVar10);
}



===== DeviceHandleDvdSendKey @ 14001f824 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void DeviceHandleDvdSendKey
               (longlong param_1,undefined8 param_2,longlong param_3,undefined8 *param_4)

{
  longlong lVar1;
  int iVar2;
  uint **ppuVar3;
  uint *local_res18 [2];
  
  lVar1 = WdfFunctions_01015;
  local_res18[0] = (uint *)0x0;
  *param_4 = 0;
  ppuVar3 = local_res18;
  iVar2 = (**(code **)(lVar1 + 0x868))
                    (WdfDriverGlobals,param_2,*(undefined8 *)(param_3 + 0x10),ppuVar3,0);
  if (-1 < iVar2) {
    DvdSendKey(param_1,param_2,local_res18[0],ppuVar3,param_4);
  }
  return;
}



===== DeviceSendEnableIdlePowerIoctl @ 14001f8a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int DeviceSendEnableIdlePowerIoctl(longlong param_1,uint param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  longlong lVar2;
  undefined1 auStack_b8 [32];
  undefined8 local_98;
  int local_90;
  ulonglong local_88;
  undefined8 local_80;
  undefined8 *local_78;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined4 local_40;
  undefined4 local_3c;
  uint local_38;
  undefined4 local_34;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_b8;
  local_58 = 0;
  local_40 = 1;
  local_3c = 0x10;
  local_38 = (param_3 & 1) * 2 | param_2 & 1;
  local_50 = 0;
  uStack_48 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_34 = param_4;
  KeInitializeEvent(&local_68,0,0);
  local_78 = &local_50;
  local_80 = &local_68;
  local_88 = local_88 & 0xffffffffffffff00;
  local_90 = 0;
  local_98 = 0;
  lVar2 = IoBuildDeviceIoControlRequest(0x2d1c80,*(undefined8 *)(param_1 + 0x48),&local_40,0x10);
  if (lVar2 == 0) {
    iVar1 = -0x3fffff66;
  }
  else {
    iVar1 = IofCallDriver(*(undefined8 *)(param_1 + 0x48),lVar2);
    if (iVar1 == 0x103) {
      local_98 = 0;
      KeWaitForSingleObject(&local_68,0,0,0);
      iVar1 = (int)local_50;
    }
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    local_88 = *(undefined8 *)(param_1 + 0x40);
    local_80 = (undefined8 *)(CONCAT44(local_80._4_4_,param_3) & 0xffffffff000000ff);
    local_90 = iVar1;
    WPP_RECORDER_SF_DqDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  return iVar1;
}



===== DeviceEvtSurpriseRemoval @ 14001fa00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void DeviceEvtSurpriseRemoval(undefined8 param_1)

{
  longlong lVar1;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1,DAT_14001a0f0);
  *(undefined1 *)(lVar1 + 10) = 1;
  DeviceDisableMainTimer(lVar1);
  *(undefined8 *)(lVar1 + 0xa8) = 0;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,9,0x1f,
                      &WPP_d2ddb5c132d1335dbff1b624de01ec23_Traceguids,(char)param_1);
  }
  return;
}



===== DeviceIsPortable @ 14001fa98 =====

void DeviceIsPortable(longlong param_1,undefined1 *param_2)

{
  int iVar1;
  undefined1 uVar2;
  char local_res8 [8];
  undefined4 local_res10 [2];
  undefined4 local_res18 [2];
  
  *param_2 = 0;
  local_res8[0] = '\0';
  uVar2 = 1;
  local_res18[0] = 0;
  local_res10[0] = 0;
  iVar1 = IoGetDevicePropertyData
                    (*(undefined8 *)(param_1 + 0x48),&DEVPKEY_Device_InLocalMachineContainer,0,0,1,
                     local_res8,local_res18,local_res10);
  if ((-1 < iVar1) && (local_res8[0] != -1)) {
    iVar1 = *(int *)(*(longlong *)(param_1 + 200) + 0x1c);
    if (((iVar1 - 6U & 0xfffffffc) == 0) && (uVar2 = 1, iVar1 != 7)) {
      uVar2 = 0;
    }
    *param_2 = uVar2;
  }
  return;
}



===== DeviceEvtCleanup @ 14001fb40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void DeviceEvtCleanup(undefined8 param_1)

{
  longlong lVar1;
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,9,0x1a,
                      &WPP_d2ddb5c132d1335dbff1b624de01ec23_Traceguids,(char)param_1);
  }
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1,DAT_14001a0f0);
  if (*(longlong *)(lVar1 + 0x60) != 0) {
    ExFreePoolWithTag(*(longlong *)(lVar1 + 0x60),0);
    *(undefined8 *)(lVar1 + 0x60) = 0;
  }
  RtlInitUnicodeString(lVar1 + 0x58,0);
  if (*(longlong *)(lVar1 + 0x360) != 0) {
    IoDeleteSymbolicLink(lVar1 + 0x358);
  }
  if (*(longlong *)(lVar1 + 0x360) != 0) {
    ExFreePoolWithTag(*(longlong *)(lVar1 + 0x360),0);
    *(undefined8 *)(lVar1 + 0x360) = 0;
  }
  RtlInitUnicodeString(lVar1 + 0x358,0);
  return;
}



===== DeviceEvtSelfManagedIoCleanup @ 14001fc40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void DeviceEvtSelfManagedIoCleanup(undefined8 param_1)

{
  longlong lVar1;
  longlong lVar2;
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x1b,
                      &WPP_d2ddb5c132d1335dbff1b624de01ec23_Traceguids,(char)param_1);
  }
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1,DAT_14001a0f0);
  (**(code **)(WdfFunctions_01015 + 0x528))(WdfDriverGlobals,*(undefined8 *)(lVar1 + 0x20),0,0);
  (**(code **)(WdfFunctions_01015 + 0x528))(WdfDriverGlobals,*(undefined8 *)(lVar1 + 0x28),0,0);
  if (*(longlong *)(lVar1 + 0x18) != 0) {
    (**(code **)(WdfFunctions_01015 + 0x550))(WdfDriverGlobals);
  }
  if (*(char *)(lVar1 + 10) == '\0') {
    DeviceClaimRelease(lVar1,'\x01');
  }
  KeFlushQueuedDpcs();
  DeviceDeallocateMmcResources(param_1);
  ScratchBuffer_Deallocate(lVar1);
  memset((void *)(lVar1 + 0x288),0,0xb8);
  if (*(longlong *)(lVar1 + 200) != 0) {
    ExFreePoolWithTag(*(longlong *)(lVar1 + 200),0);
    *(undefined8 *)(lVar1 + 200) = 0;
  }
  if (*(longlong *)(lVar1 + 0xd0) != 0) {
    ExFreePoolWithTag(*(longlong *)(lVar1 + 0xd0),0);
    *(undefined8 *)(lVar1 + 0xd0) = 0;
  }
  if (*(longlong *)(lVar1 + 0xd8) != 0) {
    ExFreePoolWithTag(*(longlong *)(lVar1 + 0xd8),0);
    *(undefined8 *)(lVar1 + 0xd8) = 0;
  }
  if (*(longlong *)(lVar1 + 0xe0) != 0) {
    ExFreePoolWithTag(*(longlong *)(lVar1 + 0xe0),0);
    *(undefined8 *)(lVar1 + 0xe0) = 0;
  }
  if (*(longlong *)(lVar1 + 0x3d8) != 0) {
    ExFreePoolWithTag(*(longlong *)(lVar1 + 0x3d8),0);
    *(undefined8 *)(lVar1 + 0x3d8) = 0;
    *(undefined4 *)(lVar1 + 0x3e0) = 0;
  }
  if (*(longlong *)(lVar1 + 0x478) != 0) {
    ExFreePoolWithTag(*(longlong *)(lVar1 + 0x478),0);
    *(undefined8 *)(lVar1 + 0x478) = 0;
  }
  DeviceReleaseMcnResources(lVar1);
  lVar2 = *(longlong *)(lVar1 + 0x120);
  if (lVar2 != 0) {
    if (*(longlong *)(lVar2 + 0x60) != 0) {
      ExFreePoolWithTag(*(longlong *)(lVar2 + 0x60),0);
      *(undefined8 *)(lVar2 + 0x60) = 0;
    }
    ExFreePoolWithTag(lVar2,0);
  }
  lVar2 = IoGetConfigurationInformation();
  *(int *)(lVar2 + 8) = *(int *)(lVar2 + 8) + -1;
  *(undefined8 *)(lVar1 + 0xa8) = 0;
  return;
}



===== DriverEvtCleanup @ 14001fea0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void DriverEvtCleanup(undefined8 param_1)

{
  undefined8 uVar1;
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,9,0xd,
                      &WPP_d2ddb5c132d1335dbff1b624de01ec23_Traceguids,(char)param_1);
  }
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x3b0))(WdfDriverGlobals,param_1);
  WppCleanupKm(uVar1);
  McGenEventUnregister_EtwUnregister();
  wil_UninitializeFeatureStaging();
  return;
}



===== ReadWriteWorkItemRoutine @ 14001ff30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void ReadWriteWorkItemRoutine(undefined8 param_1)

{
  longlong lVar1;
  bool bVar2;
  int iVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined1 auStack_88 [32];
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_88;
  uVar5 = (**(code **)(WdfFunctions_01015 + 0xbe8))(WdfDriverGlobals,param_1);
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,uVar5,DAT_14001a0f0);
  lVar1 = *(longlong *)(lVar4 + 0x488);
  *(undefined8 *)(lVar4 + 0x488) = 0;
  local_18 = 0;
  uStack_30 = 0;
  local_38 = 0x28;
  local_28 = 0;
  uStack_20 = 0;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,lVar1,&local_38);
  bVar2 = DeviceIsMmcUpdateRequired(*(undefined8 *)(lVar4 + 0x10));
  if (bVar2) {
    DeviceUpdateMmcCapabilities(*(undefined8 *)(lVar4 + 0x10));
  }
  local_68 = local_38;
  uStack_60 = uStack_30;
  local_48 = local_18;
  local_58 = local_28;
  uStack_50 = uStack_20;
  uVar5 = RequestValidateReadWrite(lVar4,lVar1,(longlong)&local_68);
  iVar3 = (int)uVar5;
  if (-1 < iVar3) {
    local_68 = local_38;
    uStack_60 = uStack_30;
    local_48 = local_18;
    local_58 = local_28;
    uStack_50 = uStack_20;
    uVar5 = RequestHandleReadWrite(lVar4,lVar1,(longlong)&local_68);
    iVar3 = (int)uVar5;
    if (-1 < iVar3) {
      return;
    }
  }
  RequestCompletion(lVar4,lVar1,iVar3,0);
  return;
}



===== WppTraceCallback @ 140020090 =====

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



===== wil_UninitializeFeatureStaging @ 140020318 =====

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



===== wil_details_BuildFeatureStateCacheFromQueryResults @ 140020370 =====

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
      goto LAB_1400203cd;
    }
    if (param_1 == 0x117) {
      uVar1 = (*(uint *)(param_2 + 4) & 0x80) << 3 | 0x206;
      goto LAB_1400203cd;
    }
  }
  uVar1 = 0x206;
LAB_1400203cd:
  *param_3 = uVar1;
  return;
}



===== wil_details_EvaluateFeatureDependencies @ 1400203d8 =====

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



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 140020490 =====

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



===== wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState @ 1400204c8 =====

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
        if (puVar1 == (undefined8 *)0x0) goto LAB_14002054a;
        if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
           (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
        if ((uVar5 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
          uVar5 = 0;
          goto LAB_14002054a;
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
LAB_14002054a:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 1400205a0 =====

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



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 140020600 =====

void wil_details_ReevaluateOnFeatureConfigurationChange(void)

{
  wil_details_UpdateFeatureConfiguredStates();
  wil_details_EvaluateFeatureDependencies();
  return;
}



===== wil_details_UpdateFeatureConfiguredStates @ 14002061c =====

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



===== DeviceCacheDeviceInquiryData @ 1400206d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int DeviceCacheDeviceInquiryData(longlong param_1)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  bool bVar8;
  undefined1 auStackY_d8 [32];
  undefined2 local_98;
  char local_95;
  undefined1 local_8e;
  uint local_88;
  undefined1 local_50;
  undefined2 local_4d;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_d8;
  memset(&local_98,0,0x58);
  if (*(longlong *)(param_1 + 0x3d8) != 0) {
    return 0;
  }
  piVar4 = (int *)ExAllocatePool2(0x40,0x24,0x69436353);
  if (piVar4 == (int *)0x0) {
    return -0x3fffff66;
  }
  local_8e = 6;
  local_50 = 0x12;
  local_4d = 0x2400;
  iVar3 = DeviceSendSrbSynchronously
                    (*(undefined8 *)(param_1 + 0x10),&local_98,(longlong)piVar4,0x24,'\0',0);
  if (iVar3 < 0) goto LAB_14002092c;
  if ((local_88 == 0x24) && (uVar7 = 0x24, (char)piVar4[1] == '\x1f')) {
LAB_140020917:
    *(int **)(param_1 + 0x3d8) = piVar4;
    *(uint *)(param_1 + 0x3e0) = uVar7;
    return iVar3;
  }
  bVar2 = *(byte *)(piVar4 + 1);
  bVar8 = bVar2 != 0;
  if (!bVar8) {
    *(undefined1 *)(piVar4 + 1) = 0x1f;
    bVar2 = 0x1f;
  }
  uVar7 = bVar2 + 5;
  if (uVar7 < 0x24) {
    iVar3 = -0x3ffffe7a;
    goto LAB_14002092c;
  }
  ExFreePoolWithTag(piVar4);
  memset(&local_98,0,0x58);
  piVar4 = (int *)ExAllocatePool2(0x40,uVar7,0x69436353);
  if (piVar4 == (int *)0x0) {
    return -0x3fffff66;
  }
  local_8e = 6;
  local_50 = 0x12;
  local_4d = CONCAT11((char)uVar7,(char)(uVar7 >> 8));
  iVar3 = DeviceSendSrbSynchronously
                    (*(undefined8 *)(param_1 + 0x10),&local_98,(longlong)piVar4,uVar7,'\0',0);
  uVar1 = local_88;
  if (iVar3 < 0) {
    if (((local_95 != '\x12') || (uVar7 <= local_88)) || (local_88 < 0x24)) goto LAB_14002092c;
    ExFreePoolWithTag(piVar4);
    memset(&local_98,0,0x58);
    piVar4 = (int *)ExAllocatePool2(0x40,uVar1,0x69436353);
    if (piVar4 == (int *)0x0) {
      return -0x3fffff66;
    }
    local_8e = 6;
    local_50 = 0x12;
    local_4d = CONCAT11((char)uVar1,(char)(uVar1 >> 8));
    iVar3 = DeviceSendSrbSynchronously
                      (*(undefined8 *)(param_1 + 0x10),&local_98,(longlong)piVar4,uVar1,'\0',0);
    if (iVar3 < 0) goto LAB_14002092c;
  }
  if (0x23 < local_88) {
    uVar7 = local_88;
    if (bVar8) goto LAB_140020917;
    iVar6 = 9;
    piVar5 = piVar4;
    do {
      if (*piVar5 != 0) goto LAB_140020917;
      piVar5 = piVar5 + 1;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
  }
  iVar3 = -0x3ffffe7a;
  if (piVar4 == (int *)0x0) {
    return -0x3ffffe7a;
  }
LAB_14002092c:
  ExFreePoolWithTag(piVar4,0);
  return iVar3;
}



===== DeviceClaimRelease @ 140020974 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int DeviceClaimRelease(longlong param_1,char param_2)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  undefined1 auStackY_138 [32];
  undefined8 local_e8;
  ulonglong local_e0;
  undefined2 *local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined *local_98;
  undefined2 local_88;
  char local_86;
  undefined8 local_58;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_138;
  memset(&local_88,0,0x58);
  local_b8 = 0;
  local_98 = PTR__WDF_CDROM_REQUEST_CONTEXT_TYPE_INFO_14001a018;
  uStack_c0 = 0;
  local_e0 = (ulonglong)(uint)local_e0;
  local_e8 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  local_c8 = 0x38;
  uStack_b0 = 0x100000001;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x7b8))
                    (WdfDriverGlobals,&local_c8,*(undefined8 *)(param_1 + 0x18),&local_e8);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,2,0xb,
                        &WPP_c6cef56efab5359de7c6f40b77738682_Traceguids,(char)iVar1);
    }
  }
  else {
    local_58 = (**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals,local_e8);
    local_d8 = &local_88;
    local_86 = (-(param_2 != '\0') & 5U) + 1;
    local_88 = 0x58;
    local_e0 = 1;
    local_d0 = 0x58;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x5f0))
                      (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x18),local_e8,0x1b0013);
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,local_e8);
    if ((iVar1 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      pcVar2 = "Release";
      if (param_2 == '\0') {
        pcVar2 = "Claim";
      }
      WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,2,10,
                         &WPP_c6cef56efab5359de7c6f40b77738682_Traceguids,pcVar2,(char)iVar1);
    }
  }
  iVar3 = 0;
  if (param_2 == '\0') {
    iVar3 = iVar1;
  }
  return iVar3;
}



===== DeviceCreateWellKnownName @ 140020bb8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong DeviceCreateWellKnownName(longlong param_1)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  void *_Dst;
  uint uVar4;
  undefined1 auStackY_e8 [32];
  undefined8 local_a8;
  void *pvStack_a0;
  wchar_t local_98 [64];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_e8;
  local_a8 = 0;
  pvStack_a0 = (void *)0x0;
  memset(local_98,0,0x80);
  uVar4 = *(uint *)(param_1 + 0x68);
  if (*(longlong *)(param_1 + 0x360) == 0) {
    do {
      uVar3 = RtlStringCchPrintfW(local_98,0x40,L"\\DosDevices\\CdRom%d",(ulonglong)uVar4);
      uVar2 = uVar3 & 0xffffffff;
      if ((int)uVar3 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,9,0x13,
                            &WPP_c6cef56efab5359de7c6f40b77738682_Traceguids,(char)uVar3);
        }
        goto LAB_140020df9;
      }
      RtlInitUnicodeString(&local_a8,local_98);
      uVar1 = (**(code **)(WdfFunctions_01015 + 0x280))
                        (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x10),&local_a8);
      uVar4 = uVar4 + 1;
      uVar2 = (ulonglong)uVar1;
    } while ((uVar1 == 0xc0000035) || (uVar1 == 0x40000000));
    if ((int)uVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_LZZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
      }
    }
    else {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_ZZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
      }
      _Dst = (void *)ExAllocatePool2(0x100,local_a8._2_2_,0x73436353);
      if (_Dst == (void *)0x0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,9,0x16,
                           &WPP_c6cef56efab5359de7c6f40b77738682_Traceguids);
        }
        uVar2 = 0xc000009a;
      }
      else {
        memmove(_Dst,pvStack_a0,local_a8 >> 0x10 & 0xffff);
        RtlInitUnicodeString(param_1 + 0x358,_Dst);
        uVar2 = 0;
      }
    }
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,9,0x12,
                        &WPP_c6cef56efab5359de7c6f40b77738682_Traceguids,
                        (char)*(longlong *)(param_1 + 0x360));
    }
    uVar2 = 0xc0000001;
  }
LAB_140020df9:
  return uVar2;
}



===== DeviceGetMmcSupportInfo @ 140020e28 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong DeviceGetMmcSupportInfo(longlong param_1,undefined1 *param_2)

{
  ulonglong *puVar1;
  byte bVar2;
  int iVar3;
  ulonglong uVar4;
  undefined1 *puVar5;
  uint uVar6;
  undefined2 uVar7;
  undefined1 auStackY_98 [32];
  int local_58;
  uint local_54;
  undefined4 local_50;
  undefined1 uStack_4c;
  undefined2 local_4b;
  undefined1 local_49;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_98;
  *param_2 = 0;
  local_58 = 0;
  DeviceGetParameter(param_1,0x140015820,L"NonMmc",&local_58);
  puVar1 = (ulonglong *)(param_1 + 0x340);
  if (local_58 != 0) {
    *puVar1 = *puVar1 | 0x100;
  }
  local_58 = 0;
  DeviceGetParameter(param_1,0x140015820,L"NonMmcVendorSpecificProfile",&local_58);
  if (local_58 != 0) {
    *puVar1 = *puVar1 | 0x1000;
  }
  local_50._0_1_ = 0;
  local_50._1_1_ = 0;
  local_50._2_1_ = 0;
  local_50._3_1_ = 0;
  uStack_4c = 0;
  local_4b = 0;
  local_49 = 0;
  local_54 = 0;
  uVar4 = DeviceGetConfiguration
                    (*(undefined8 *)(param_1 + 0x10),(undefined1 *)&local_50,8,&local_54,0,0);
  bVar2 = local_50._3_1_;
  iVar3 = (int)uVar4;
  if ((((iVar3 == -0x3ffffff0) || (iVar3 == -0x3fffffed)) || (iVar3 == -0x3ffffe7b)) ||
     (iVar3 == -0x3fffff4b)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_Dq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,9,0x2e,
                         &WPP_c6cef56efab5359de7c6f40b77738682_Traceguids,(char)uVar4,
                         (char)*(undefined8 *)(param_1 + 0x40));
    }
    goto LAB_14002125e;
  }
  if (iVar3 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0;
    }
    WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,9,0x2f,
                      &WPP_c6cef56efab5359de7c6f40b77738682_Traceguids,(char)uVar4);
    return 0;
  }
  if (local_54 < 8) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14002125e;
    uVar7 = 0x30;
    uVar6 = local_54;
  }
  else {
    uVar6 = CONCAT31(CONCAT21(CONCAT11((undefined1)local_50,local_50._1_1_),local_50._2_1_),
                     local_50._3_1_);
    if ((4 < uVar6) && (uVar6 <= uVar6 + 4)) {
      if ((local_50._3_1_ & 3) != 0) {
        if ((local_50._3_1_ & 1) != 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_14002125e;
          uVar7 = 0x32;
          goto LAB_1400211f3;
        }
        if ((*(uint *)(param_1 + 0x340) >> 0xc & 1) == 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,9,0x33,
                              &WPP_c6cef56efab5359de7c6f40b77738682_Traceguids,local_50._3_1_);
          }
          local_58 = 1;
          DeviceSetParameter(param_1,0x140015820,L"NonMmcVendorSpecificProfile",1);
        }
      }
      *param_2 = 1;
      local_50._0_1_ = 0;
      local_50._1_1_ = 0;
      local_50._2_1_ = 0;
      local_50._3_1_ = 0;
      puVar5 = (undefined1 *)ExAllocatePool2(0x40,0xc,0x43436353);
      if (puVar5 == (undefined1 *)0x0) {
        return 0xc000009a;
      }
      local_58 = 0;
      DeviceGetParameter(param_1,0x140015820,L"NoTypeOneGetConfig",&local_58);
      if (local_58 != 0) {
        *(ulonglong *)(param_1 + 0x340) = *(ulonglong *)(param_1 + 0x340) | 0x800;
        ExFreePoolWithTag(puVar5,0);
        return 0;
      }
      uVar4 = DeviceGetConfiguration(*(undefined8 *)(param_1 + 0x10),puVar5,0xc,&local_50,0,2);
      if (((int)uVar4 < 0) ||
         (CONCAT13(local_50._3_1_,
                   CONCAT12(local_50._2_1_,CONCAT11(local_50._1_1_,(undefined1)local_50))) < 0xc)) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,9,0x34,
                            &WPP_c6cef56efab5359de7c6f40b77738682_Traceguids,(undefined1)local_50);
        }
      }
      else {
        local_54 = CONCAT31(CONCAT21(CONCAT11(*puVar5,puVar5[1]),puVar5[2]),puVar5[3]);
        if (local_54 + 4 <= (byte)puVar5[0xb] + 0xc) goto LAB_140021195;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,9,0x35,
                             &WPP_c6cef56efab5359de7c6f40b77738682_Traceguids,bVar2 + 4,0xc);
        }
      }
      local_58 = 1;
LAB_140021195:
      ExFreePoolWithTag(puVar5,0);
      if (local_58 == 1) {
        DeviceSetParameter(param_1,0x140015820,L"NoTypeOneGetConfig",1);
        *(ulonglong *)(param_1 + 0x340) = *(ulonglong *)(param_1 + 0x340) | 0x800;
      }
      return uVar4 & 0xffffffff;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14002125e;
    uVar7 = 0x31;
  }
LAB_1400211f3:
  WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,9,uVar7,
                    &WPP_c6cef56efab5359de7c6f40b77738682_Traceguids,(char)uVar6);
LAB_14002125e:
  local_58 = 1;
  DeviceSetParameter(param_1,0x140015820,L"NonMmc",1);
  return 0;
}



===== DeviceGetTimeOutValueFromRegistry @ 1400212a8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 DeviceGetTimeOutValueFromRegistry(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_88 [32];
  undefined8 *local_68;
  undefined4 local_58 [2];
  undefined8 local_50;
  undefined8 local_48;
  wchar_t *local_40;
  wchar_t local_38 [16];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_88;
  local_68 = &local_50;
  builtin_wcsncpy(local_38,L"TimeOutValue",0xd);
  local_40 = local_38;
  local_50 = 0;
  local_58[0] = 0;
  local_48 = 0x1a0018;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x3b8))(WdfDriverGlobals,*WdfDriverGlobals,0x20019,0);
  uVar2 = 0;
  if (-1 < iVar1) {
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x780))(WdfDriverGlobals,local_50,&local_48,local_58);
    (**(code **)(WdfFunctions_01015 + 0x738))(WdfDriverGlobals,local_50);
    if (-1 < iVar1) {
      uVar2 = local_58[0];
    }
  }
  return uVar2;
}



===== DeviceHackFlagsScan @ 1400213c0 =====

void DeviceHackFlagsScan(longlong param_1,uint param_2)

{
  ulonglong *puVar1;
  
  puVar1 = (ulonglong *)(*(longlong *)(param_1 + 0x478) + 0x10);
  *puVar1 = *puVar1 | (ulonglong)(param_2 & 0x7f);
  return;
}



===== DeviceInitAllocateBuffers @ 1400213d8 =====

uint DeviceInitAllocateBuffers(longlong param_1)

{
  byte bVar1;
  longlong lVar2;
  longlong lVar3;
  uint uVar4;
  
  lVar2 = *(longlong *)(param_1 + 0x478);
  if (lVar2 == 0) {
    lVar2 = ExAllocatePool2(0x40,0x838,0x43506353);
    *(longlong *)(param_1 + 0x478) = lVar2;
  }
  lVar3 = ExAllocatePool2(0x48,0x12,0x49436353);
  if (lVar3 == 0) {
    uVar4 = 0xc000009a;
  }
  else {
    *(longlong *)(param_1 + 0xe0) = lVar3;
    uVar4 = ~-(uint)(lVar2 != 0) & 0xc000009a;
  }
  bVar1 = ScratchBuffer_Allocate(param_1);
  if ((bVar1 == 0) &&
     (uVar4 = 0xc000009a, (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,9,0x19,
                      &WPP_c6cef56efab5359de7c6f40b77738682_Traceguids,0x9a);
  }
  return uVar4;
}



===== DeviceInitMmcContext @ 1400214b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int DeviceInitMmcContext(longlong param_1)

{
  char *pcVar1;
  undefined1 uVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined1 *puVar5;
  int iVar6;
  undefined2 uVar7;
  undefined8 *puVar8;
  uint local_res8 [2];
  undefined4 local_res10 [2];
  
  *(undefined2 *)(param_1 + 0x28b) = 0;
  pcVar1 = (char *)(param_1 + 0x288);
  *pcVar1 = '\0';
  *(undefined1 *)(param_1 + 0x289) = 0;
  *(undefined1 *)(param_1 + 0x28a) = 0;
  *(undefined4 *)(param_1 + 0x3d0) = 2;
  uVar4 = DeviceGetMmcSupportInfo(param_1,pcVar1);
  iVar6 = (int)uVar4;
  if (iVar6 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,9,0x24,
                        &WPP_c6cef56efab5359de7c6f40b77738682_Traceguids,(char)uVar4);
    }
    *pcVar1 = '\0';
    iVar6 = 0;
  }
  if (*pcVar1 != '\0') {
    uVar4 = DeviceAllocateMmcResources(*(undefined8 *)(param_1 + 0x10));
    iVar6 = (int)uVar4;
  }
  if ((-1 < iVar6) && (*(char *)(param_1 + 0x288) != '\0')) {
    local_res10[0] = 0;
    local_res8[0] = 0;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,9,0x25,
                         &WPP_c6cef56efab5359de7c6f40b77738682_Traceguids,
                         (char)*(undefined8 *)(param_1 + 0x10),(char)*(undefined8 *)(param_1 + 800))
      ;
    }
    puVar5 = DeviceFindFeaturePage(*(undefined1 **)(param_1 + 800),*(uint *)(param_1 + 0x328),0x10d)
    ;
    if (puVar5 != (undefined1 *)0x0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,9,0x26,
                         &WPP_c6cef56efab5359de7c6f40b77738682_Traceguids);
      }
      *(undefined1 *)(param_1 + 0x289) = 1;
    }
    puVar5 = DeviceFindFeaturePage(*(undefined1 **)(param_1 + 800),*(uint *)(param_1 + 0x328),0x1f);
    if (puVar5 != (undefined1 *)0x0) {
      *(undefined4 *)(param_1 + 0x3d0) = 0x33;
    }
    DeviceUpdateMmcWriteCapability
              (*(undefined1 **)(param_1 + 800),*(uint *)(param_1 + 0x328),'\0',
               (undefined1 *)(param_1 + 0x28a),local_res10,local_res8);
    puVar5 = DeviceFindFeaturePage(*(undefined1 **)(param_1 + 800),*(uint *)(param_1 + 0x328),0x106)
    ;
    if ((puVar5 == (undefined1 *)0x0) || ((puVar5[2] & 1) == 0)) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
    *(ushort *)(param_1 + 0x6c) = *(ushort *)(param_1 + 0x6c) | 4;
    *(undefined1 *)(param_1 + 0x28c) = uVar2;
    *(code **)(param_1 + 0x348) = DeviceErrorHandlerForMmc;
    *(undefined4 *)(param_1 + 0x290) = 1;
    DeviceSetRawReadInfo(param_1);
  }
  puVar8 = (undefined8 *)(param_1 + 0x10);
  if (*(char *)(param_1 + 0x288) == '\0') {
    uVar3 = (**(code **)(WdfFunctions_01015 + 0x198))(WdfDriverGlobals,*puVar8);
    (**(code **)(WdfFunctions_01015 + 400))(WdfDriverGlobals,*puVar8,uVar3 | 2);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,9,0x27,
                        &WPP_c6cef56efab5359de7c6f40b77738682_Traceguids,(char)*puVar8);
    }
  }
  if (*(int *)(param_1 + 0x3d0) == 0x33) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400217ab;
    uVar7 = 0x28;
  }
  else {
    if (*(uint *)(*(longlong *)(param_1 + 200) + 0x1c) < 3) {
      return iVar6;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400217ab;
    uVar7 = 0x29;
  }
  WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,9,uVar7,
                   &WPP_c6cef56efab5359de7c6f40b77738682_Traceguids);
LAB_1400217ab:
  *(ushort *)(param_1 + 0x6c) = *(ushort *)(param_1 + 0x6c) | 4;
  return iVar6;
}



===== DeviceInitPowerContext @ 1400217d4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong DeviceInitPowerContext(longlong param_1)

{
  uint uVar1;
  ulonglong uVar2;
  undefined4 local_48;
  undefined8 local_44;
  undefined8 uStack_3c;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 local_28;
  undefined8 local_20;
  undefined *local_18;
  
  local_34 = 0;
  local_44 = 0;
  uStack_3c = 0;
  local_20 = 0;
  local_30 = 1;
  local_2c = 1;
  local_48 = 0x38;
  local_18 = PTR__WDF_CDROM_REQUEST_CONTEXT_TYPE_INFO_14001a018;
  local_28 = *(undefined8 *)(param_1 + 0x10);
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x7b8))
                    (WdfDriverGlobals,&local_48,*(undefined8 *)(param_1 + 0x18),
                     (undefined8 *)(param_1 + 0x1f0));
  uVar2 = (ulonglong)uVar1;
  if ((int)uVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x11,
                       &WPP_c6cef56efab5359de7c6f40b77738682_Traceguids);
    }
  }
  else {
    uVar2 = (**(code **)(WdfFunctions_01015 + 0x5f8))
                      (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x18),
                       *(undefined8 *)(param_1 + 0x1f0),0x1b0011,0,0,0,0,0,0);
  }
  return uVar2;
}



===== DeviceInitReleaseQueueContext @ 1400218fc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong DeviceInitReleaseQueueContext(longlong param_1)

{
  undefined8 *puVar1;
  uint uVar2;
  int iVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined2 uVar6;
  undefined4 local_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined *local_28;
  
  puVar1 = (undefined8 *)(param_1 + 0x158);
  uStack_44 = 0;
  uStack_30 = 0;
  local_28 = PTR__WDF_CDROM_REQUEST_CONTEXT_TYPE_INFO_14001a018;
  local_38 = *(undefined8 *)(param_1 + 0x10);
  uStack_54 = 0;
  uStack_50 = 0;
  uStack_4c = 0;
  uStack_48 = 0;
  local_58 = 0x38;
  uStack_40 = 0x100000001;
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x7b8))
                    (WdfDriverGlobals,&local_58,*(undefined8 *)(param_1 + 0x18),puVar1);
  uVar5 = (ulonglong)uVar2;
  if ((int)uVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return uVar5;
    }
    uVar6 = 0xe;
  }
  else {
    local_28 = (undefined *)0x0;
    local_38 = *puVar1;
    uStack_48 = 0;
    uStack_44 = 0;
    uStack_30 = 0;
    uStack_54 = 0;
    uStack_50 = 0;
    uStack_4c = 0;
    local_58 = 0x38;
    uStack_40 = 0x100000001;
    uVar2 = (**(code **)(WdfFunctions_01015 + 0x608))
                      (WdfDriverGlobals,&local_58,(undefined2 *)(param_1 + 0x160),0x58,
                       (undefined8 *)(param_1 + 0x1b8));
    uVar5 = (ulonglong)uVar2;
    if ((int)uVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return uVar5;
      }
      uVar6 = 0xf;
    }
    else {
      iVar3 = (**(code **)(WdfFunctions_01015 + 0x5f8))
                        (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x18),*puVar1,0x1b0013,
                         *(undefined8 *)(param_1 + 0x1b8),0,0,0,0,0);
      if (-1 < iVar3) {
        (**(code **)(WdfFunctions_01015 + 0x820))
                  (WdfDriverGlobals,*puVar1,DeviceReleaseQueueCompletion,
                   *(undefined8 *)(param_1 + 0x10));
      }
      local_28 = (undefined *)0x0;
      local_38 = *(undefined8 *)(param_1 + 0x10);
      uStack_48 = 0;
      uStack_44 = 0;
      uStack_30 = 0;
      uStack_54 = 0;
      uStack_50 = 0;
      uStack_4c = 0;
      local_58 = 0x38;
      uStack_40 = 0x100000001;
      uVar4 = (**(code **)(WdfFunctions_01015 + 0x9d8))(WdfDriverGlobals,&local_58,param_1 + 0x150);
      uVar5 = uVar4 & 0xffffffff;
      if (-1 < (int)uVar4) {
        *(undefined2 *)(param_1 + 0x1c0) = 0;
        *(undefined2 *)(param_1 + 0x160) = 0x58;
        return uVar4;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return uVar5;
      }
      uVar6 = 0x10;
    }
  }
  WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,uVar6,
                   &WPP_c6cef56efab5359de7c6f40b77738682_Traceguids);
  return uVar5;
}



===== DeviceInitializeHotplugInfo @ 140021b78 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int DeviceInitializeHotplugInfo(longlong param_1)

{
  longlong lVar1;
  int iVar2;
  int local_res8 [2];
  int local_res10 [2];
  int local_res18 [2];
  int local_res20 [2];
  
  lVar1 = *(longlong *)(param_1 + 0x478);
  local_res8[0] = 0;
  local_res10[0] = 0;
  *(undefined8 *)(lVar1 + 0x18) = 0;
  *(undefined4 *)(lVar1 + 0x18) = 8;
  *(bool *)(lVar1 + 0x1c) = *(char *)(*(longlong *)(param_1 + 200) + 10) != '\0';
  *(byte *)(lVar1 + 0x1d) = *(byte *)(*(longlong *)(param_1 + 0x478) + 0x10) & 1;
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x288))
                    (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x10),0x13,4,local_res8,local_res10)
  ;
  if (-1 < iVar2) {
    if (local_res10[0] == 4) {
      if (local_res8[0] - 2U < 2) {
        local_res18[0] = 0;
        DeviceGetParameter(param_1,0x140015260,L"UserRemovalPolicy",local_res18);
        if (local_res18[0] - 2U < 2) {
          local_res8[0] = local_res18[0];
        }
      }
      *(bool *)(lVar1 + 0x1e) = local_res8[0] == 3;
      local_res20[0] = 0;
      DeviceGetParameter(param_1,0x140015260,L"WriteCacheEnableOverride",local_res20);
      *(bool *)(lVar1 + 0x1f) = local_res20[0] != 0;
      return iVar2;
    }
    iVar2 = -0x3fffffff;
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,9,0x23,
                      &WPP_c6cef56efab5359de7c6f40b77738682_Traceguids,(char)iVar2);
  }
  return iVar2;
}



===== DeviceRetrieveDescriptorsAndTransferLength @ 140021ccc =====

ulonglong DeviceRetrieveDescriptorsAndTransferLength(longlong param_1)

{
  longlong lVar1;
  uint uVar2;
  ulonglong uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  ulonglong uVar7;
  uint local_res10 [2];
  undefined8 in_stack_ffffffffffffffd8;
  
  local_res10[0] = 1;
  uVar3 = DeviceRetrieveDescriptor
                    (*(undefined8 *)(param_1 + 0x10),local_res10,(longlong *)(param_1 + 0xd0));
  uVar7 = uVar3 & 0xffffffff;
  if (-1 < (int)uVar3) {
    local_res10[0] = 0;
    uVar3 = DeviceRetrieveDescriptor
                      (*(undefined8 *)(param_1 + 0x10),local_res10,(undefined8 *)(param_1 + 200));
    uVar7 = uVar3 & 0xffffffff;
    if (-1 < (int)uVar3) {
      local_res10[0] = 0xc;
      DeviceRetrieveDescriptor
                (*(undefined8 *)(param_1 + 0x10),local_res10,(undefined8 *)(param_1 + 0xd8));
      lVar1 = *(longlong *)(param_1 + 0xd0);
      uVar2 = *(uint *)(lVar1 + 0xc);
      uVar5 = uVar2 - 1;
      if (uVar2 < 2) {
        uVar5 = uVar2;
      }
      uVar4 = 0xffffffff;
      if (uVar2 < 0xfffff) {
        uVar2 = uVar2 << 0xc;
      }
      else {
        uVar2 = 0xffffffff;
      }
      if (uVar5 < 0xfffff) {
        uVar4 = uVar5 << 0xc;
      }
      uVar5 = *(uint *)(lVar1 + 8);
      uVar6 = uVar5;
      if (uVar2 < uVar5) {
        uVar6 = uVar2;
      }
      if (uVar4 < uVar5) {
        uVar5 = uVar4;
      }
      if (uVar6 < 0x1001) {
        uVar6 = 0x1000;
      }
      if (uVar5 < 0x1001) {
        uVar5 = 0x1000;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,9,0x1a,
                            in_stack_ffffffffffffffd8,(char)*(undefined8 *)(param_1 + 0x10),
                            (char)uVar6,(char)uVar5);
      }
      *(uint *)(param_1 + 0x368) = uVar6;
      *(uint *)(param_1 + 0x36c) = uVar5;
      return uVar7;
    }
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x1b,
                      &WPP_c6cef56efab5359de7c6f40b77738682_Traceguids,(char)uVar7);
  }
  return uVar7;
}



===== DeviceRetrieveHackFlagsFromRegistry @ 140021e40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void DeviceRetrieveHackFlagsFromRegistry(longlong param_1)

{
  ulonglong *puVar1;
  int iVar2;
  undefined1 auStack_b8 [32];
  undefined8 local_98;
  undefined8 *local_90;
  uint local_78 [2];
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  wchar_t *local_58;
  undefined8 local_50;
  wchar_t *local_48;
  wchar_t local_40 [12];
  wchar_t local_28 [12];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_b8;
  local_68 = 0;
  local_90 = &local_68;
  local_70 = 0;
  local_78[0] = 0;
  builtin_wcsncpy(local_40,L"Classpnp",9);
  local_58 = local_40;
  builtin_wcsncpy(local_28,L"HackMask",9);
  local_48 = local_28;
  local_98 = 0;
  local_60 = 0x120010;
  local_50 = 0x120010;
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x180))
                    (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x10),1,0x20019);
  if (-1 < iVar2) {
    local_90 = &local_70;
    local_98 = 0;
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x728))(WdfDriverGlobals,local_68,&local_60,0x20019);
    if (-1 < iVar2) {
      iVar2 = (**(code **)(WdfFunctions_01015 + 0x780))
                        (WdfDriverGlobals,local_70,&local_50,local_78);
      if (-1 < iVar2) {
        local_78[0] = local_78[0] & 0x7f;
        puVar1 = (ulonglong *)(*(longlong *)(param_1 + 0x478) + 0x10);
        *puVar1 = *puVar1 | (ulonglong)local_78[0];
      }
      (**(code **)(WdfFunctions_01015 + 0x738))(WdfDriverGlobals,local_70);
    }
    (**(code **)(WdfFunctions_01015 + 0x738))(WdfDriverGlobals,local_68);
  }
  return;
}



===== DeviceRetrieveScsiAddress @ 140021fdc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int DeviceRetrieveScsiAddress(longlong param_1,longlong param_2)

{
  int iVar1;
  undefined4 local_28;
  undefined4 local_24;
  longlong local_20;
  undefined4 local_18;
  undefined4 local_14;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    iVar1 = -0x3ffffff3;
  }
  else {
    local_24 = 0;
    local_14 = 0;
    local_28 = 1;
    local_18 = 8;
    local_20 = param_2;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x5d0))
                      (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x18),0,0x41018,0,&local_28,0,0);
    if (iVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,9,0x17,
                          &WPP_c6cef56efab5359de7c6f40b77738682_Traceguids,(char)iVar1);
      }
    }
    else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_DDDD
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,9,0x18,
                 &WPP_c6cef56efab5359de7c6f40b77738682_Traceguids,*(undefined1 *)(param_2 + 4),
                 *(undefined1 *)(param_2 + 5),*(undefined1 *)(param_2 + 6),
                 *(undefined1 *)(param_2 + 7));
    }
  }
  return iVar1;
}



===== DeviceScanSpecialDevices @ 14002211c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void DeviceScanSpecialDevices(longlong param_1)

{
  ulonglong uVar1;
  int iVar2;
  longlong lVar3;
  undefined1 auStackY_a8 [32];
  undefined2 local_78 [5];
  undefined1 local_6e;
  undefined4 local_64;
  undefined1 local_30;
  byte local_2f;
  undefined1 local_2c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  DeviceScanForSpecial(param_1,(undefined8 *)&CdromHackItems,ScanForSpecialHandler);
  uVar1 = *(ulonglong *)(param_1 + 0x340);
  if ((uVar1 & 0x10) == 0) {
    if ((uVar1 & 8) == 0) {
      if ((uVar1 & 2) == 0) {
        if ((uVar1 & 1) != 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,9,0x2c,
                             &WPP_c6cef56efab5359de7c6f40b77738682_Traceguids);
          }
          *(undefined1 *)(param_1 + 0x370) = 1;
          lVar3 = ExAllocatePool2(0x40,0xc,0x4d436353);
          if (lVar3 != 0) {
            memset(local_78,0,0x58);
            *(undefined1 *)(lVar3 + 3) = 8;
            *(undefined2 *)(lVar3 + 9) = 0x800;
            *(undefined1 *)(lVar3 + 0xb) = 0;
            local_64 = *(undefined4 *)(param_1 + 0x78);
            local_2f = local_2f | 0x10;
            local_6e = 6;
            local_30 = 0x15;
            local_2c = 0xc;
            iVar2 = DeviceSendSrbSynchronously
                              (*(undefined8 *)(param_1 + 0x10),local_78,lVar3,0xc,'\x01',0);
            if ((iVar2 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)
               ) {
              WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,9,0x2d,
                                &WPP_c6cef56efab5359de7c6f40b77738682_Traceguids,(char)iVar2);
            }
            ExFreePoolWithTag(lVar3,0);
          }
        }
      }
      else {
        *(undefined4 *)(param_1 + 0x78) = 0x14;
      }
    }
    else {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,9,0x2b,
                         &WPP_c6cef56efab5359de7c6f40b77738682_Traceguids);
      }
      *(ushort *)(param_1 + 0x6c) = *(ushort *)(param_1 + 0x6c) | 4;
      *(code **)(param_1 + 0x348) = DeviceErrorHandlerForHitachiGD2000;
    }
  }
  else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,9,0x2a,
                     &WPP_c6cef56efab5359de7c6f40b77738682_Traceguids);
  }
  return;
}



===== DeviceSetRawReadInfo @ 140022348 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int DeviceSetRawReadInfo(longlong param_1)

{
  int iVar1;
  undefined1 *puVar2;
  longlong lVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  longlong lVar6;
  byte *pbVar7;
  uint uVar8;
  uint uVar9;
  undefined1 auStackY_d8 [32];
  undefined *in_stack_ffffffffffffff48;
  undefined2 local_98 [5];
  undefined1 local_8e;
  undefined4 local_84;
  undefined1 local_50;
  byte local_4f;
  byte local_4e;
  undefined1 local_4c;
  undefined2 local_49;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_d8;
  puVar2 = DeviceFindFeaturePage(*(undefined1 **)(param_1 + 800),*(uint *)(param_1 + 0x328),0x1e);
  if (((puVar2 != (undefined1 *)0x0) && (3 < (byte)puVar2[3])) && ((puVar2[4] & 2) != 0)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      in_stack_ffffffffffffff48 = &WPP_c6cef56efab5359de7c6f40b77738682_Traceguids;
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x36,
                        &WPP_c6cef56efab5359de7c6f40b77738682_Traceguids,
                        (char)*(undefined8 *)(param_1 + 0x40));
    }
    *(undefined1 *)(param_1 + 0x338) = 1;
  }
  uVar9 = 0;
  uVar8 = 0;
  do {
    memset(local_98,0,0x58);
    local_4f = local_4f | 8;
    local_4e = local_4e & 0xea | 0x2a;
    if (uVar8 < 3) {
      uVar5 = 0x28;
      local_50 = 0x5a;
      local_49 = 0x2800;
      local_8e = 10;
    }
    else {
      uVar5 = 0x24;
      local_50 = 0x1a;
      local_4c = 0x24;
      local_8e = 6;
    }
    local_84 = *(undefined4 *)(param_1 + 0x78);
    lVar3 = ExAllocatePool2(0x40,uVar5,0x4d436353);
    if (lVar3 == 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x37,
                          &WPP_c6cef56efab5359de7c6f40b77738682_Traceguids,
                          (char)*(undefined8 *)(param_1 + 0x40));
      }
      return -0x3fffff66;
    }
    in_stack_ffffffffffffff48 =
         (undefined *)((ulonglong)in_stack_ffffffffffffff48 & 0xffffffffffffff00);
    iVar1 = DeviceSendSrbSynchronously
                      (*(undefined8 *)(param_1 + 0x10),local_98,lVar3,(int)uVar5,'\0',0);
    if (((iVar1 < 0) && (iVar1 != -0x3fffffc4)) && (iVar1 != -0x7ffffffb)) {
LAB_140022671:
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,5,0x3b,
                            in_stack_ffffffffffffff48,(char)*(undefined8 *)(param_1 + 0x40),
                            (-(uVar9 < 3) & 4U) + 6,(char)iVar1);
      }
      ExFreePoolWithTag(lVar3);
    }
    else {
      uVar4 = Feature_3408814395__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar4 == 0) {
        if (uVar8 < 3) {
          uVar4 = (ulonglong)*(byte *)(lVar3 + 7);
          lVar6 = (ulonglong)*(byte *)(lVar3 + 6) * 0x100 + 8 + lVar3;
          goto LAB_14002252a;
        }
        pbVar7 = (byte *)((ulonglong)*(byte *)(lVar3 + 3) + 4 + lVar3);
LAB_14002252d:
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          in_stack_ffffffffffffff48 = &WPP_c6cef56efab5359de7c6f40b77738682_Traceguids;
          WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x38,
                             &WPP_c6cef56efab5359de7c6f40b77738682_Traceguids,
                             (char)*(undefined8 *)(param_1 + 0x40),(char)lVar3);
        }
        if ((*pbVar7 & 0x3f) != 0x2a) goto LAB_140022671;
        if ((pbVar7[5] & 0x10) != 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x39,
                              &WPP_c6cef56efab5359de7c6f40b77738682_Traceguids,
                              (char)*(undefined8 *)(param_1 + 0x40));
          }
          *(undefined1 *)(param_1 + 0x338) = 1;
        }
        if ((pbVar7[5] & 4) != 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x3a,
                              &WPP_c6cef56efab5359de7c6f40b77738682_Traceguids,
                              (char)*(undefined8 *)(param_1 + 0x40));
          }
          *(undefined1 *)(param_1 + 0x339) = 1;
        }
        break;
      }
      if (uVar8 < 3) {
        uVar4 = (ulonglong)CONCAT11(*(undefined1 *)(lVar3 + 6),*(undefined1 *)(lVar3 + 7));
        if (uVar4 + 0x20 <= uVar5) {
          lVar6 = lVar3 + 8;
LAB_14002252a:
          pbVar7 = (byte *)(lVar6 + uVar4);
          goto LAB_14002252d;
        }
      }
      else {
        uVar4 = (ulonglong)*(byte *)(lVar3 + 3);
        if (uVar4 + 0x1c <= uVar5) {
          lVar6 = lVar3 + 4;
          goto LAB_14002252a;
        }
      }
      iVar1 = -0x3ffffe7b;
      ExFreePoolWithTag(lVar3);
    }
    lVar3 = 0;
    uVar9 = uVar9 + 1;
    uVar8 = uVar8 + 1;
  } while (uVar9 < 6);
  if ((uVar9 == 6) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,5,0x3c,
                      &WPP_c6cef56efab5359de7c6f40b77738682_Traceguids,
                      (char)*(undefined8 *)(param_1 + 0x40));
  }
  if (lVar3 != 0) {
    ExFreePoolWithTag(lVar3,0);
  }
  return iVar1;
}



===== ScanForSpecialHandler @ 140022760 =====

void ScanForSpecialHandler(longlong param_1,uint param_2)

{
  *(ulonglong *)(param_1 + 0x340) = (ulonglong)(param_2 & 0x3fff);
  return;
}



===== wil_RtlStagingConfig_QueryFeatureState @ 140022778 =====

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



===== DevicePickDvdRegion @ 140022844 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void DevicePickDvdRegion(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4
                        )

{
  uint uVar1;
  int iVar2;
  longlong lVar3;
  uint *puVar4;
  byte bVar5;
  undefined2 uVar6;
  uint *puVar7;
  int iVar8;
  byte bVar9;
  byte bVar10;
  undefined1 auStackY_c8 [32];
  undefined1 uVar11;
  uint local_88 [2];
  undefined8 local_80;
  ulonglong local_78 [2];
  wchar_t *local_68;
  wchar_t local_60 [20];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_c8;
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1,DAT_14001a0f0);
  local_78[0] = 0;
  local_68 = local_60;
  local_88[0] = 0;
  local_80 = 0;
  builtin_wcsncpy(local_60,L"DefaultDvdRegion",0x11);
  local_78[1] = 0x220020;
  LOCK();
  iVar8 = *(int *)(lVar3 + 0x354);
  *(int *)(lVar3 + 0x354) = 0;
  UNLOCK();
  if (iVar8 == 0) {
    return;
  }
  puVar4 = (uint *)ExAllocatePool2(0x100,0x1c,0x76436353);
  if (puVar4 == (uint *)0x0) goto LAB_140022f07;
  puVar4[2] = 1;
  uVar11 = (undefined1)param_1;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    param_4 = 0x47;
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x47,
                      &WPP_8ec010589a13368bcaefd70a9b2ee310_Traceguids,uVar11);
  }
  uVar1 = ReadDvdStructure(lVar3,0,(longlong *)puVar4,param_4,(undefined2 *)puVar4,8,local_78);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x48,
                       &WPP_8ec010589a13368bcaefd70a9b2ee310_Traceguids,uVar11,(char)uVar1);
  }
  if (((int)uVar1 < 0) || ((char)puVar4[1] != '\x01')) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140022ef6;
    uVar6 = 0x4a;
LAB_140022ede:
    WPP_RECORDER_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,5,uVar6,
                       &WPP_8ec010589a13368bcaefd70a9b2ee310_Traceguids,uVar11,(char)uVar1);
  }
  else {
    bVar10 = *(byte *)((longlong)puVar4 + 5);
    if (bVar10 == 0xff) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x49,
                          &WPP_8ec010589a13368bcaefd70a9b2ee310_Traceguids,uVar11);
      }
      *(undefined1 *)((longlong)puVar4 + 5) = 0;
      bVar10 = 0;
    }
    puVar4[0] = 0x1c;
    puVar4[1] = 0;
    bVar10 = ~bVar10;
    puVar4[3] = 0;
    puVar4[4] = 0;
    puVar4[5] = 0;
    puVar4[6] = 0;
    puVar4[2] = 8;
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x4b,
                        &WPP_8ec010589a13368bcaefd70a9b2ee310_Traceguids,uVar11);
    }
    uVar1 = DvdStartSessionReadKey(lVar3,0x335004,0,(longlong *)puVar4,0x1c,puVar4,0x1c,local_78);
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x4c,
                         &WPP_8ec010589a13368bcaefd70a9b2ee310_Traceguids,uVar11,(char)uVar1);
    }
    if ((int)uVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140022ef6;
      uVar6 = 0x4d;
LAB_140022b2c:
      bVar10 = 3;
LAB_140022b2e:
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),bVar10,5,uVar6,
                        &WPP_8ec010589a13368bcaefd70a9b2ee310_Traceguids,uVar11);
    }
    else if (*(char *)((longlong)puVar4 + 0x19) == -1) {
      if (((byte)puVar4[6] & 7) < 2) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar6 = 0x4f;
          goto LAB_140022b2c;
        }
        goto LAB_140022ef6;
      }
      puVar7 = (uint *)0x0;
      iVar2 = (**(code **)(WdfFunctions_01015 + 0x3b8))(WdfDriverGlobals,*WdfDriverGlobals,0x20019);
      if (iVar2 < 0) {
LAB_140022c1e:
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          puVar7 = (uint *)0x50;
          WPP_RECORDER_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,5,0x50,
                             &WPP_8ec010589a13368bcaefd70a9b2ee310_Traceguids,uVar11,(char)iVar2);
        }
        local_88[0] = 0;
      }
      else {
        puVar7 = local_88;
        iVar2 = (**(code **)(WdfFunctions_01015 + 0x780))(WdfDriverGlobals,local_80,local_78 + 1);
        (**(code **)(WdfFunctions_01015 + 0x738))(WdfDriverGlobals);
        if (iVar2 < 0) goto LAB_140022c1e;
      }
      if (8 < local_88[0]) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          puVar7 = (uint *)0x51;
          WPP_RECORDER_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,5,0x51,
                             &WPP_8ec010589a13368bcaefd70a9b2ee310_Traceguids,uVar11,
                             (char)local_88[0]);
        }
        local_88[0] = 0;
      }
      if ((local_88[0] == 0) ||
         (bVar5 = (byte)(1 << ((char)local_88[0] - 1U & 0x1f)), (bVar5 & bVar10) == 0)) {
        if (bVar10 == 0) {
          if (local_88[0] == 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar6 = 0x55;
              goto LAB_140022b2c;
            }
            goto LAB_140022ef6;
          }
          bVar5 = (byte)(1 << ((char)local_88[0] - 1U & 0x1f));
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            puVar7 = (uint *)0x54;
            goto LAB_140022d4d;
          }
        }
        else {
          bVar5 = 0;
          bVar9 = 1;
          while (bVar5 == 0) {
            bVar5 = bVar10 & bVar9;
            bVar9 = bVar9 * '\x02';
          }
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            puVar7 = (uint *)0x53;
            goto LAB_140022d4d;
          }
        }
      }
      else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        puVar7 = (uint *)0x52;
LAB_140022d4d:
        WPP_RECORDER_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,(short)puVar7,
                           &WPP_8ec010589a13368bcaefd70a9b2ee310_Traceguids,uVar11,bVar5);
      }
      puVar4[0] = 0;
      puVar4[1] = 0;
      puVar4[2] = 0;
      puVar4[3] = 0;
      puVar4[4] = 0;
      puVar4[5] = 0;
      puVar4[6] = 0;
      *puVar4 = 0x1c;
      *(byte *)(puVar4 + 6) = ~bVar5;
      puVar4[2] = 6;
      if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
         (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
        puVar7 = (uint *)0x56;
        WPP_RECORDER_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x56,
                           &WPP_8ec010589a13368bcaefd70a9b2ee310_Traceguids,uVar11,bVar5);
      }
      uVar1 = DvdSendKey(lVar3,0,puVar4,puVar7,local_78);
      if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
         (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
        WPP_RECORDER_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x57,
                           &WPP_8ec010589a13368bcaefd70a9b2ee310_Traceguids,uVar11,(char)uVar1);
      }
      if ((int)uVar1 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar6 = 0x58;
          goto LAB_140022ede;
        }
      }
      else {
        if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
           (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
          WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x59,
                            &WPP_8ec010589a13368bcaefd70a9b2ee310_Traceguids,uVar11);
        }
        iVar8 = 0;
      }
    }
    else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar6 = 0x4e;
      bVar10 = 4;
      goto LAB_140022b2e;
    }
  }
LAB_140022ef6:
  ExFreePoolWithTag(puVar4,0);
LAB_140022f07:
  LOCK();
  *(int *)(lVar3 + 0x354) = iVar8;
  UNLOCK();
  return;
}



===== DeviceRegisterInterface @ 140022f44 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int DeviceRegisterInterface(longlong param_1,int param_2)

{
  int iVar1;
  undefined *puVar2;
  longlong lVar3;
  undefined8 local_res18;
  
  local_res18 = 0;
  lVar3 = 0;
  if (param_2 == 0) {
    puVar2 = &GUID_DEVINTERFACE_CDROM;
  }
  else if (param_2 == 1) {
    puVar2 = &MOUNTDEV_MOUNTED_DEVICE_GUID;
    lVar3 = param_1 + 0xb8;
  }
  else {
    if (param_2 != 2) {
      return -0x3ffffff3;
    }
    puVar2 = &GUID_DEVINTERFACE_HIDDEN_VOLUME;
    lVar3 = param_1 + 0xb8;
  }
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x268))
                    (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x10),puVar2,0);
  if ((iVar1 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_qsL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  if ((((param_2 != 0) && (-1 < iVar1)) &&
      (iVar1 = (**(code **)(WdfFunctions_01015 + 0x9a0))(WdfDriverGlobals,0,0,&local_res18),
      -1 < iVar1)) &&
     (iVar1 = (**(code **)(WdfFunctions_01015 + 0x278))
                        (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x10),puVar2,0,local_res18),
     -1 < iVar1)) {
    (**(code **)(WdfFunctions_01015 + 0x9a8))(WdfDriverGlobals,local_res18,lVar3);
  }
  return iVar1;
}



===== DeviceRestoreDefaultSpeed @ 1400230d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void DeviceRestoreDefaultSpeed(undefined8 param_1)

{
  int iVar1;
  undefined8 uVar2;
  longlong lVar3;
  undefined8 *puVar4;
  undefined1 auStackY_b8 [32];
  undefined2 local_88 [5];
  undefined1 local_7e;
  undefined4 local_74;
  undefined1 local_40;
  undefined2 local_37;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_b8;
  uVar2 = (**(code **)(WdfFunctions_01015 + 0xbe8))(WdfDriverGlobals,param_1);
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,uVar2,DAT_14001a0f0);
  memset(local_88,0,0x58);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x5b,
                      &WPP_8ec010589a13368bcaefd70a9b2ee310_Traceguids,(char)uVar2);
  }
  puVar4 = (undefined8 *)ExAllocatePool2(0x48,0x1c,0x4f434353);
  if (puVar4 != (undefined8 *)0x0) {
    *puVar4 = 0;
    puVar4[1] = 0;
    puVar4[2] = 0;
    *(undefined4 *)(puVar4 + 3) = 0;
    *(undefined1 *)puVar4 = 4;
    local_74 = *(undefined4 *)(lVar3 + 0x78);
    local_7e = 0xc;
    local_40 = 0xb6;
    local_37 = 0x1c00;
    iVar1 = DeviceSendSrbSynchronously(uVar2,local_88,(longlong)puVar4,0x1c,'\x01',0);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x5c,
                        &WPP_8ec010589a13368bcaefd70a9b2ee310_Traceguids,(char)iVar1);
    }
    ExFreePoolWithTag(puVar4,0);
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,param_1);
  }
  return;
}



===== DeviceRetrieveModeSenseUsingScratch @ 140023298 =====

uint DeviceRetrieveModeSenseUsingScratch
               (longlong param_1,void *param_2,undefined8 param_3,undefined8 param_4,char param_5)

{
  int iVar1;
  uint uVar2;
  undefined8 local_18;
  undefined8 uStack_10;
  
  uVar2 = *(uint *)(param_1 + 1000);
  if (0xc0 < uVar2) {
    uVar2 = 0xc0;
  }
  ScratchBuffer_BeginUseX(param_1);
  uStack_10 = 0;
  local_18 = (ulonglong)(byte)(param_5 << 6 | 8) << 0x10;
  local_18 = CONCAT71(local_18._1_7_,0x1a);
  local_18 = (ulonglong)CONCAT14((char)uVar2,(undefined4)local_18);
  iVar1 = ScratchBuffer_ExecuteCdbEx(param_1,0,uVar2,'\x01',&local_18,6,0);
  if (-1 < iVar1) {
    uVar2 = *(uint *)(*(longlong *)(param_1 + 0x408) + 0x10);
    if (0xc0 < uVar2) {
      uVar2 = 0xc0;
    }
    memmove(param_2,*(void **)(param_1 + 0x3f0),(ulonglong)uVar2);
  }
  ScratchBuffer_EndUse(param_1);
  return uVar2;
}



===== DeviceSetParameter @ 140023358 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int DeviceSetParameter(longlong param_1,longlong param_2,undefined8 param_3,undefined4 param_4)

{
  int iVar1;
  longlong lVar2;
  longlong local_res8;
  longlong local_res10;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  
  local_res8 = 0;
  local_res10 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  RtlInitUnicodeString(&local_28,param_3);
  if (param_2 != 0) {
    RtlInitUnicodeString(&local_38,param_2);
  }
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x180))
                    (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x10),1,0x2001f,0,&local_res8);
  if (-1 < iVar1) {
    if ((param_2 == 0) ||
       (iVar1 = (**(code **)(WdfFunctions_01015 + 0x728))
                          (WdfDriverGlobals,local_res8,&local_38,0x2001f,0,&local_res10), -1 < iVar1
       )) {
      if (local_res8 != 0) {
        lVar2 = local_res8;
        if (local_res10 != 0) {
          lVar2 = local_res10;
        }
        iVar1 = (**(code **)(WdfFunctions_01015 + 0x7b0))(WdfDriverGlobals,lVar2,&local_28,param_4);
      }
    }
    else {
      (**(code **)(WdfFunctions_01015 + 0x738))(WdfDriverGlobals);
      local_res8 = 0;
    }
  }
  if (local_res10 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x738))(WdfDriverGlobals,local_res10);
    local_res10 = 0;
  }
  if (local_res8 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x738))(WdfDriverGlobals);
  }
  return iVar1;
}



===== DeviceUnlockExclusive @ 140023500 =====

undefined8 DeviceUnlockExclusive(longlong param_1,longlong param_2,char param_3)

{
  char cVar1;
  char *pcVar2;
  undefined8 uVar3;
  longlong lVar4;
  undefined8 uVar5;
  bool bVar6;
  uint local_res8 [2];
  
  uVar5 = 0;
  pcVar2 = *(char **)(param_1 + 0x118);
  if (*(longlong *)(param_1 + 0x378) == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x60,
                       &WPP_8ec010589a13368bcaefd70a9b2ee310_Traceguids);
    }
    uVar5 = 0xc0000010;
  }
  else if (*(longlong *)(param_1 + 0x378) == param_2) {
    if (param_3 == '\0') {
      local_res8[0] = 0;
      DeviceSetMediaChangeStateEx(param_1,3,(int *)local_res8);
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x62,
                         &WPP_8ec010589a13368bcaefd70a9b2ee310_Traceguids);
      }
      DeviceSetMediaChangeStateEx(param_1,local_res8[0],(int *)0x0);
    }
    lVar4 = *(longlong *)(param_1 + 0x40);
    uVar3 = IsVolumeMounted(lVar4);
    if ((char)uVar3 != '\0') {
      *(uint *)(lVar4 + 0x30) = *(uint *)(lVar4 + 0x30) | 2;
    }
    *(undefined1 *)(param_1 + 0x28b) = 0;
    *(undefined4 *)(param_1 + 0x290) = 1;
    DeviceSendNotification(param_1,(undefined4 *)&GUID_IO_CDROM_EXCLUSIVE_UNLOCK,0,(void *)0x0);
    LOCK();
    *(undefined8 *)(param_1 + 0x378) = 0;
    UNLOCK();
    if ((((pcVar2 != (char *)0x0) && (*pcVar2 != '\0')) &&
        (cVar1 = pcVar2[1], pcVar2[1] = '\0', cVar1 != '\0')) && (*(int *)(pcVar2 + 0x50) == 0)) {
      LOCK();
      bVar6 = *(int *)(pcVar2 + 0x78) == 0;
      if (bVar6) {
        *(int *)(pcVar2 + 0x78) = 1;
      }
      UNLOCK();
      if (bVar6) {
        RequestSetupMcnSyncIrp(param_1);
        IofCallDriver(*(undefined8 *)(param_1 + 0x40),*(undefined8 *)(pcVar2 + 0x40));
      }
    }
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x61,
                       &WPP_8ec010589a13368bcaefd70a9b2ee310_Traceguids);
    }
    uVar5 = 0xc0000008;
  }
  return uVar5;
}



===== ModeSenseFindSpecificPage @ 1400236b0 =====

byte * ModeSenseFindSpecificPage(longlong param_1,ulonglong param_2,byte param_3,char param_4)

{
  byte bVar1;
  byte *pbVar2;
  uint uVar3;
  
  uVar3 = (-(uint)(param_4 != '\0') & 0xfffffffc) + 8;
  if (uVar3 <= param_2) {
    if (param_4 == '\0') {
      bVar1 = *(byte *)(param_1 + 7);
    }
    else {
      bVar1 = *(byte *)(param_1 + 3);
    }
    for (pbVar2 = (byte *)(param_1 + (ulonglong)(bVar1 + uVar3));
        pbVar2 + 2 < (byte *)(param_1 + param_2); pbVar2 = pbVar2 + pbVar2[1] + 2) {
      if ((*pbVar2 & 0x3f) == param_3) {
        if ((byte *)(param_1 + param_2) < pbVar2 + pbVar2[1]) {
          pbVar2 = (byte *)0x0;
        }
        return pbVar2;
      }
    }
  }
  return (byte *)0x0;
}



===== DeviceHandleDvdEndSession @ 140023720 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int DeviceHandleDvdEndSession
              (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 *param_4)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined8 local_28;
  longlong lStack_20;
  
  lVar1 = WdfFunctions_01015;
  *param_4 = 0;
  iVar2 = (**(code **)(lVar1 + 0x868))(WdfDriverGlobals);
  if (-1 < iVar2) {
    uVar3 = uRam0000000000000000;
    if (uRam0000000000000000 == 0xffffffff) {
      uVar3 = 3;
    }
    ScratchBuffer_BeginUseX(param_1);
    uVar4 = 0;
    if (uRam0000000000000000 != 0xffffffff) {
      uVar4 = uRam0000000000000000;
    }
    do {
      lStack_20 = (ulonglong)(byte)((char)uVar4 << 6 | 0x3f) << 0x10;
      local_28 = 0xa3;
      iVar2 = ScratchBuffer_ExecuteCdbEx(param_1,param_2,0,'\0',&local_28,0xc,0);
      uVar4 = uVar4 + 1;
      if (uVar3 < uVar4) break;
    } while (-1 < iVar2);
    ScratchBuffer_EndUse(param_1);
  }
  return iVar2;
}



===== DeviceHandleDvdStartSessionReadKey @ 140023804 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void DeviceHandleDvdStartSessionReadKey
               (longlong param_1,undefined8 param_2,longlong param_3,ulonglong *param_4)

{
  int iVar1;
  undefined8 uVar2;
  uint *local_18;
  longlong *local_10;
  
  local_10 = (longlong *)0x0;
  local_18 = (uint *)0x0;
  uVar2 = 0;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x870))
                    (WdfDriverGlobals,param_2,*(undefined8 *)(param_3 + 8),&local_18);
  if (-1 < iVar1) {
    if (*(int *)(param_3 + 0x18) == 0x335004) {
      uVar2 = 0;
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x868))
                        (WdfDriverGlobals,param_2,*(undefined8 *)(param_3 + 0x10),&local_10);
      if (iVar1 < 0) {
        return;
      }
    }
    DvdStartSessionReadKey
              (param_1,*(int *)(param_3 + 0x18),param_2,local_10,uVar2,local_18,
               (uint)*(undefined8 *)(param_3 + 8),param_4);
  }
  return;
}



===== DeviceHandleGetSetVolume @ 1400238dc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int DeviceHandleGetSetVolume
              (longlong param_1,undefined8 param_2,longlong param_3,undefined8 *param_4)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  longlong lVar5;
  longlong lVar6;
  byte *pbVar7;
  longlong lVar8;
  longlong lVar9;
  longlong lVar10;
  longlong local_res20;
  undefined1 local_38;
  undefined1 uStack_37;
  undefined1 uStack_36;
  undefined4 uStack_35;
  undefined1 uStack_31;
  undefined1 uStack_30;
  undefined7 uStack_2f;
  
  lVar5 = 0;
  *param_4 = 0;
  ScratchBuffer_BeginUseX(param_1);
  uStack_37 = 0;
  uStack_35 = 0;
  uStack_2f = 0;
  local_38 = 0x5a;
  uStack_36 = 0xe;
  uStack_31 = 0;
  uStack_30 = 0x40;
  iVar3 = ScratchBuffer_ExecuteCdbEx(param_1,param_2,0x40,'\x01',(undefined8 *)&local_38,10,0);
  if (iVar3 < 0) goto LAB_140023b0a;
  local_res20 = 0;
  if (*(int *)(param_3 + 0x18) == 0x24014) {
    iVar3 = (**(code **)(WdfFunctions_01015 + 0x870))
                      (WdfDriverGlobals,param_2,*(undefined8 *)(param_3 + 8));
    if (iVar3 < 0) goto LAB_140023b0a;
    lVar8 = *(longlong *)(param_1 + 0x408);
    uVar2 = *(uint *)(lVar8 + 0x10);
    pbVar4 = ModeSenseFindSpecificPage(*(longlong *)(lVar8 + 0x18),(ulonglong)uVar2,0xe,'\0');
    if ((pbVar4 != (byte *)0x0) && (((int)pbVar4 - *(int *)(lVar8 + 0x18)) + 0x10U <= uVar2)) {
      lVar8 = 4;
      pbVar4 = pbVar4 + 9;
      do {
        bVar1 = *pbVar4;
        pbVar4 = pbVar4 + 2;
        *(byte *)(lVar5 + local_res20) = bVar1;
        lVar5 = lVar5 + 1;
        lVar8 = lVar8 + -1;
      } while (lVar8 != 0);
      *param_4 = 4;
      goto LAB_140023b0a;
    }
LAB_140023a70:
    iVar3 = -0x3ffffff0;
  }
  else {
    iVar3 = (**(code **)(WdfFunctions_01015 + 0x868))
                      (WdfDriverGlobals,param_2,*(undefined8 *)(param_3 + 0x10),&local_res20,0);
    if (-1 < iVar3) {
      pbVar4 = ModeSenseFindSpecificPage
                         (*(longlong *)(*(longlong *)(param_1 + 0x408) + 0x18),
                          (ulonglong)*(uint *)(*(longlong *)(param_1 + 0x408) + 0x10),0xe,'\0');
      if (pbVar4 == (byte *)0x0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,5,0x4f,
                            &WPP_7cea3eca420c34d4f6f4315c54c616a1_Traceguids,0xe);
        }
        goto LAB_140023a70;
      }
      ScratchBuffer_ResetItems(param_1,'\x01');
      lVar5 = *(longlong *)(param_1 + 0x3f0);
      pbVar7 = pbVar4 + 8;
      lVar10 = 0;
      lVar9 = (lVar5 + 8) - (longlong)pbVar4;
      lVar8 = 4;
      do {
        lVar6 = lVar8;
        pbVar4 = (byte *)(lVar10 + local_res20);
        lVar10 = lVar10 + 1;
        pbVar7[lVar9 + 1] = *pbVar4;
        pbVar7[lVar9] = *pbVar7;
        pbVar7 = pbVar7 + 2;
        lVar8 = lVar6 + -1;
      } while (lVar8 != 0);
      *(undefined1 *)(lVar5 + 10) = 4;
      *(undefined2 *)(lVar5 + 8) = 0xe0e;
      uStack_36 = 0;
      uStack_35 = 0;
      uStack_2f = 0;
      uStack_37 = 0x10;
      local_38 = 0x55;
      uStack_31 = 0;
      uStack_30 = 0x18;
      iVar3 = ScratchBuffer_ExecuteCdbEx
                        (param_1,param_2,(int)lVar6 + 0x17,'\0',(undefined8 *)&local_38,10,0);
    }
  }
  *param_4 = 0;
LAB_140023b0a:
  ScratchBuffer_EndUse(param_1);
  return iVar3;
}



===== DeviceHandlePauseAudio @ 140023b34 =====

int DeviceHandlePauseAudio(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  int iVar1;
  undefined8 local_18;
  undefined8 uStack_10;
  
  *param_3 = 0;
  ScratchBuffer_BeginUseX(param_1);
  local_18 = 0x4b;
  uStack_10 = 0;
  iVar1 = ScratchBuffer_ExecuteCdbEx(param_1,param_2,0,'\0',&local_18,10,0);
  if (-1 < iVar1) {
    *param_3 = 0;
    *(undefined1 *)(param_1 + 0x350) = 0;
  }
  ScratchBuffer_EndUse(param_1);
  return iVar1;
}



===== DeviceHandlePlayAudioMsf @ 140023bc0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int DeviceHandlePlayAudioMsf
              (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 *param_4)

{
  longlong lVar1;
  int iVar2;
  longlong local_28;
  ulonglong uStack_20;
  
  lVar1 = WdfFunctions_01015;
  *param_4 = 0;
  iVar2 = (**(code **)(lVar1 + 0x868))(WdfDriverGlobals);
  if (-1 < iVar2) {
    ScratchBuffer_BeginUseX(param_1);
    local_28 = (ulonglong)
               CONCAT14(uRam0000000000000004,
                        CONCAT13(uRam0000000000000003,
                                 CONCAT12(uRam0000000000000002,
                                          CONCAT11(uRam0000000000000001,uRam0000000000000000)))) <<
               0x18;
    uStack_20 = (ulonglong)bRam0000000000000005;
    local_28 = CONCAT71(local_28._1_7_,0x47);
    iVar2 = ScratchBuffer_ExecuteCdbEx(param_1,param_2,0,'\0',&local_28,10,0);
    if (-1 < iVar2) {
      *param_4 = 0;
      *(undefined1 *)(param_1 + 0x350) = 1;
    }
    ScratchBuffer_EndUse(param_1);
  }
  return iVar2;
}



===== DeviceHandleReadDvdStructure @ 140023ca8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void DeviceHandleReadDvdStructure
               (longlong param_1,undefined8 param_2,longlong param_3,ulonglong *param_4)

{
  longlong lVar1;
  int iVar2;
  undefined2 **ppuVar3;
  undefined2 *local_res18;
  longlong *local_res20;
  
  lVar1 = WdfFunctions_01015;
  local_res20 = (longlong *)0x0;
  local_res18 = (undefined2 *)0x0;
  *param_4 = 0;
  iVar2 = (**(code **)(lVar1 + 0x868))
                    (WdfDriverGlobals,param_2,*(undefined8 *)(param_3 + 0x10),&local_res20,0);
  if (-1 < iVar2) {
    ppuVar3 = &local_res18;
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x870))
                      (WdfDriverGlobals,param_2,*(undefined8 *)(param_3 + 8),ppuVar3,0);
    if (-1 < iVar2) {
      ReadDvdStructure(param_1,param_2,local_res20,ppuVar3,local_res18,
                       (ushort)*(undefined8 *)(param_3 + 8),param_4);
    }
  }
  return;
}



===== DeviceHandleReadQChannel @ 140023d68 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void DeviceHandleReadQChannel
               (longlong param_1,undefined8 param_2,longlong param_3,ulonglong *param_4)

{
  longlong lVar1;
  int iVar2;
  void **ppvVar3;
  void *local_res18;
  byte *local_res20;
  
  lVar1 = WdfFunctions_01015;
  local_res20 = (byte *)0x0;
  local_res18 = (void *)0x0;
  *param_4 = 0;
  iVar2 = (**(code **)(lVar1 + 0x868))
                    (WdfDriverGlobals,param_2,*(undefined8 *)(param_3 + 0x10),&local_res20,0);
  if (-1 < iVar2) {
    ppvVar3 = &local_res18;
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x870))
                      (WdfDriverGlobals,param_2,*(undefined8 *)(param_3 + 8),ppvVar3,0);
    if (-1 < iVar2) {
      ReadQChannel(param_1,param_2,local_res20,ppvVar3,local_res18,*(ulonglong *)(param_3 + 8),
                   param_4);
    }
  }
  return;
}



===== DeviceHandleResumeAudio @ 140023e28 =====

int DeviceHandleResumeAudio(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  int iVar1;
  undefined8 local_18;
  undefined8 uStack_10;
  
  *param_3 = 0;
  ScratchBuffer_BeginUseX(param_1);
  local_18 = 0x4b;
  uStack_10 = 1;
  iVar1 = ScratchBuffer_ExecuteCdbEx(param_1,param_2,0,'\0',&local_18,10,0);
  if (-1 < iVar1) {
    *param_3 = 0;
    *(undefined1 *)(param_1 + 0x350) = 1;
  }
  ScratchBuffer_EndUse(param_1);
  return iVar1;
}



===== DeviceHandleSeekAudioMsf @ 140023eb4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int DeviceHandleSeekAudioMsf
              (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 *param_4)

{
  uint5 uVar1;
  longlong lVar2;
  int iVar3;
  undefined1 uStackX_19;
  undefined1 uStackX_1a;
  undefined1 uStackX_1b;
  undefined8 local_28;
  undefined8 uStack_20;
  
  lVar2 = WdfFunctions_01015;
  *param_4 = 0;
  iVar3 = (**(code **)(lVar2 + 0x868))(WdfDriverGlobals);
  if (-1 < iVar3) {
    iVar3 = (bRam0000000000000002 - 0x96) +
            ((uint)bRam0000000000000000 * 0x3c + (uint)bRam0000000000000001) * 0x4b;
    ScratchBuffer_BeginUseX(param_1);
    uStackX_1b = (undefined1)((uint)iVar3 >> 0x18);
    uStack_20 = 0;
    uStackX_1a = (undefined1)((uint)iVar3 >> 0x10);
    uStackX_19 = (undefined1)((uint)iVar3 >> 8);
    local_28._0_5_ = (uint5)CONCAT12(uStackX_19,CONCAT11(uStackX_1a,uStackX_1b)) << 0x10;
    uVar1 = (uint5)(int5)local_28 >> 8;
    local_28 = CONCAT71((uint7)(uint)uVar1,0x2b);
    local_28 = (ulonglong)CONCAT15((char)iVar3,(int5)local_28);
    iVar3 = ScratchBuffer_ExecuteCdbEx(param_1,param_2,0,'\0',&local_28,10,0);
    if (-1 < iVar3) {
      *param_4 = 0;
    }
    ScratchBuffer_EndUse(param_1);
  }
  return iVar3;
}



===== DeviceHandleSetReadAhead @ 140023fb8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int DeviceHandleSetReadAhead
              (longlong param_1,undefined8 param_2,longlong param_3,undefined8 *param_4)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  longlong *local_res18 [2];
  undefined1 local_28;
  undefined7 uStack_27;
  ulonglong uStack_20;
  
  lVar2 = WdfFunctions_01015;
  local_res18[0] = (longlong *)0x0;
  *param_4 = 0;
  iVar1 = (**(code **)(lVar2 + 0x868))
                    (WdfDriverGlobals,param_2,*(undefined8 *)(param_3 + 0x10),local_res18,0);
  if (-1 < iVar1) {
    ScratchBuffer_BeginUseX(param_1);
    lVar2 = *local_res18[0] >> (*(byte *)(param_1 + 0xa0) & 0x3f);
    lVar3 = local_res18[0][1] >> (*(byte *)(param_1 + 0xa0) & 0x3f);
    uStack_20 = CONCAT71((int7)lVar3,(char)((ulonglong)lVar3 >> 8)) & 0xffff;
    _local_28 = CONCAT71((int7)(CONCAT17((char)((ulonglong)lVar3 >> 0x10),
                                         CONCAT16((char)((ulonglong)lVar3 >> 0x18),
                                                  CONCAT33((int3)lVar2,
                                                           CONCAT12((char)((ulonglong)lVar2 >> 8),
                                                                    CONCAT11((char)((ulonglong)lVar2
                                                                                   >> 0x10),
                                                                             (char)((ulonglong)lVar2
                                                                                   >> 0x18)))) <<
                                                  0x10)) >> 8),0xa7);
    iVar1 = ScratchBuffer_ExecuteCdbEx(param_1,param_2,0,'\0',(undefined8 *)&local_28,0xc,0);
    if (-1 < iVar1) {
      *param_4 = 0;
    }
    ScratchBuffer_EndUse(param_1);
  }
  return iVar1;
}



===== DeviceHandleSetSpeed @ 1400240c4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int DeviceHandleSetSpeed(longlong param_1,undefined8 param_2,longlong param_3,undefined8 *param_4)

{
  byte *pbVar1;
  char cVar2;
  byte bVar3;
  int iVar4;
  char *pcVar5;
  uint uVar6;
  undefined1 auStackY_98 [32];
  undefined8 local_50;
  undefined8 uStack_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_98;
  *param_4 = 0;
  iVar4 = (**(code **)(WdfFunctions_01015 + 0x868))
                    (WdfDriverGlobals,param_2,*(undefined8 *)(param_3 + 0x10));
  if (-1 < iVar4) {
    uVar6 = 0;
    ScratchBuffer_BeginUseX(param_1);
    uStack_48 = 0;
    if (iRam0000000000000000 == 0) {
      local_50._0_3_ = CONCAT12(bRam0000000000000005,0xbb);
      local_50._0_5_ =
           CONCAT14(bRam0000000000000007,CONCAT13(bRam0000000000000004,(undefined3)local_50));
      local_50 = CONCAT62(CONCAT15(bRam0000000000000006,(undefined5)local_50) >> 0x10,
                          CONCAT11(bRam0000000000000008,0xbb)) & 0xffffffff03ff;
    }
    else {
      pbVar1 = *(byte **)(param_1 + 0x3f0);
      uVar6 = 0x1c;
      local_50 = 0xb6;
      uStack_48 = 0x1c0000;
      pbVar1[0] = 0;
      pbVar1[1] = 0;
      pbVar1[2] = 0;
      pbVar1[3] = 0;
      pbVar1[4] = 0;
      pbVar1[5] = 0;
      pbVar1[6] = 0;
      pbVar1[7] = 0;
      pbVar1[8] = 0;
      pbVar1[9] = 0;
      pbVar1[10] = 0;
      pbVar1[0xb] = 0;
      pbVar1[0xc] = 0;
      pbVar1[0xd] = 0;
      pbVar1[0xe] = 0;
      pbVar1[0xf] = 0;
      pbVar1[0x10] = 0;
      pbVar1[0x11] = 0;
      pbVar1[0x12] = 0;
      pbVar1[0x13] = 0;
      pbVar1[0x14] = 0;
      pbVar1[0x15] = 0;
      pbVar1[0x16] = 0;
      pbVar1[0x17] = 0;
      pbVar1[0x18] = 0;
      pbVar1[0x19] = 0;
      pbVar1[0x1a] = 0;
      pbVar1[0x1b] = 0;
      bVar3 = bRam0000000000000022 & 1;
      *pbVar1 = bVar3;
      bVar3 = (bRam0000000000000021 & 1) * '\x02' ^ bVar3;
      *pbVar1 = bVar3;
      bVar3 = (bRam0000000000000020 & 1) << 2 ^ bVar3;
      *pbVar1 = bVar3;
      *pbVar1 = (bRam000000000000001c & 3) << 3 ^ bVar3;
      pbVar1[7] = bRam0000000000000014;
      pbVar1[6] = bRam0000000000000015;
      pbVar1[5] = bRam0000000000000016;
      pbVar1[4] = bRam0000000000000017;
      pbVar1[0xb] = bRam0000000000000018;
      pbVar1[10] = bRam0000000000000019;
      pbVar1[9] = bRam000000000000001a;
      pbVar1[8] = bRam000000000000001b;
      pbVar1[0xf] = bRam0000000000000004;
      pbVar1[0xe] = bRam0000000000000005;
      pbVar1[0xd] = bRam0000000000000006;
      pbVar1[0xc] = bRam0000000000000007;
      pbVar1[0x13] = bRam0000000000000008;
      pbVar1[0x12] = bRam0000000000000009;
      pbVar1[0x11] = bRam000000000000000a;
      pbVar1[0x10] = bRam000000000000000b;
      pbVar1[0x17] = bRam000000000000000c;
      pbVar1[0x16] = bRam000000000000000d;
      pbVar1[0x15] = bRam000000000000000e;
      pbVar1[0x14] = bRam000000000000000f;
      pbVar1[0x1b] = bRam0000000000000010;
      pbVar1[0x1a] = bRam0000000000000011;
      pbVar1[0x19] = bRam0000000000000012;
      pbVar1[0x18] = bRam0000000000000013;
      cVar2 = cRam0000000000000023;
      *(bool *)(param_1 + 0x3c0) = cRam0000000000000023 == '\0';
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        pcVar5 = "true";
        if (cVar2 != '\0') {
          pcVar5 = "false";
        }
        WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),"false",5,100,
                          &WPP_7cea3eca420c34d4f6f4315c54c616a1_Traceguids,pcVar5);
      }
    }
    iVar4 = ScratchBuffer_ExecuteCdbEx(param_1,param_2,uVar6,'\0',&local_50,0xc,0);
    if (-1 < iVar4) {
      *param_4 = 0;
    }
    ScratchBuffer_EndUse(param_1);
  }
  return iVar4;
}



===== DeviceHandleStopAudio @ 14002434c =====

int DeviceHandleStopAudio(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  int iVar1;
  undefined8 local_18;
  undefined8 uStack_10;
  
  *param_3 = 0;
  ScratchBuffer_BeginUseX(param_1);
  uStack_10 = 0;
  local_18 = 0x11b;
  iVar1 = ScratchBuffer_ExecuteCdbEx(param_1,param_2,0,'\0',&local_18,6,0);
  if (-1 < iVar1) {
    *param_3 = 0;
    *(undefined1 *)(param_1 + 0x350) = 0;
  }
  ScratchBuffer_EndUse(param_1);
  return iVar1;
}



===== DvdSendKey @ 1400243dc =====

uint DvdSendKey(longlong param_1,undefined8 param_2,uint *param_3,undefined8 param_4,
               undefined8 *param_5)

{
  undefined1 *puVar1;
  uint uVar2;
  ulonglong uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined8 local_18;
  undefined8 uStack_10;
  
  *param_5 = 0;
  uVar3 = Feature_637773113__private_IsEnabledDeviceUsageNoInline();
  uVar2 = *param_3;
  if ((int)uVar3 == 0) {
    if ((0x17 < uVar2) &&
       (uVar5 = *(uint *)(param_1 + 1000), (ulonglong)uVar2 - 0x18 <= (ulonglong)uVar5)) {
LAB_14002446a:
      uVar4 = uVar2 - 0x18;
      if (uVar2 < 0x18) {
        return -(uint)(uVar2 < 0x18) & 0xc0000095;
      }
      uVar2 = uVar2 - 0x14;
      uVar6 = 0xffffffff;
      if (uVar2 >= uVar4) {
        uVar6 = uVar2;
      }
      if (uVar2 < uVar4) {
        return -(uint)(uVar2 < uVar4) & 0xc0000095;
      }
      if (uVar5 <= uVar6) {
        uVar6 = uVar5;
      }
      if (uVar6 < 2) {
        return 0xc000000d;
      }
      ScratchBuffer_BeginUseX(param_1);
      puVar1 = *(undefined1 **)(param_1 + 0x3f0);
      puVar1[1] = (char)(uVar6 - 2);
      *puVar1 = (char)(uVar6 - 2 >> 8);
      memmove(puVar1 + 4,param_3 + 6,(ulonglong)*param_3 - 0x18);
      local_18 = 0xa3;
      uStack_10._0_2_ = CONCAT11((char)uVar6,(char)(uVar6 >> 8));
      uStack_10 = (ulonglong)
                  CONCAT12((byte)param_3[2] & 0x3f | (char)param_3[1] << 6,(undefined2)uStack_10);
      uVar2 = ScratchBuffer_ExecuteCdbEx(param_1,param_2,uVar6,'\0',&local_18,0xc,0);
      ScratchBuffer_EndUse(param_1);
      return uVar2;
    }
  }
  else if ((0x17 < uVar2) &&
          (uVar5 = *(uint *)(param_1 + 1000), (ulonglong)uVar2 - 0x18 <= (ulonglong)(uVar5 - 4)))
  goto LAB_14002446a;
  return 0xc00000e5;
}



===== DvdStartSessionReadKey @ 140024544 =====

uint DvdStartSessionReadKey
               (longlong param_1,int param_2,undefined8 param_3,longlong *param_4,undefined8 param_5
               ,uint *param_6,uint param_7,ulonglong *param_8)

{
  byte bVar1;
  undefined1 *puVar2;
  longlong lVar3;
  ulonglong *puVar4;
  uint uVar5;
  uint uVar6;
  longlong *plVar7;
  char *pcVar8;
  ulonglong uVar9;
  uint uVar10;
  longlong lVar11;
  ulonglong uVar12;
  ulonglong uVar13;
  undefined2 uVar14;
  longlong *plVar15;
  uint local_res20;
  undefined8 *puVar16;
  undefined1 uVar17;
  undefined8 local_48;
  undefined8 uStack_40;
  
  puVar4 = param_8;
  uVar12 = 0;
  local_res20 = 0xffffffff;
  *param_8 = 0;
  if (param_2 == 0x335004) {
    if (param_4 == (longlong *)0x0) {
      return 0xc00000e5;
    }
    plVar15 = param_4;
    if (((int)param_4[1] == 8) && (*(char *)(param_1 + 0x28c) != '\0')) {
      DevicePickDvdRegion(*(undefined8 *)(param_1 + 0x10),0xffffffff,param_3,param_4);
    }
    if ((int)param_4[1] == 0x80) {
      plVar7 = (longlong *)ExAllocatePool2(0x40,0x18,0x75436353);
      if (plVar7 == (longlong *)0x0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x5e,
                           &WPP_7cea3eca420c34d4f6f4315c54c616a1_Traceguids);
        }
        uVar5 = 0xc000009a;
      }
      else {
        lVar11 = param_4[1];
        *plVar7 = *param_4;
        plVar7[1] = lVar11;
        plVar7[2] = param_4[2];
        *(undefined4 *)(param_4 + 1) = 2;
        *param_4 = 0;
        *(undefined1 *)(param_4 + 2) = 0;
        *(undefined4 *)((longlong)param_4 + 0xc) = *(undefined4 *)((longlong)plVar7 + 4);
        uVar5 = ReadDvdStructure(param_1,param_3,param_4,plVar15,(undefined2 *)param_6,0x804,param_8
                                );
        if ((int)uVar5 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_DDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,5,0x5f,
                                &WPP_7cea3eca420c34d4f6f4315c54c616a1_Traceguids,(char)uVar5,
                                (char)*param_8,*(undefined1 *)((longlong)param_6 + 1));
          }
        }
        else {
          memmove(param_6 + 6,param_6 + 1,0x800);
          lVar11 = *plVar7;
          lVar3 = plVar7[1];
          *param_8 = 0x818;
          *(longlong *)param_6 = lVar11;
          *(longlong *)(param_6 + 2) = lVar3;
          *(longlong *)(param_6 + 4) = plVar7[2];
          *param_6 = 0x818;
        }
        ExFreePoolWithTag(plVar7,0);
      }
      return uVar5;
    }
    uVar10 = param_7 - 0x18;
    if (param_7 < 0x18) {
      uVar10 = 0xffffffff;
    }
    if (param_7 < 0x18) {
      return -(uint)(param_7 < 0x18) & 0xc0000095;
    }
    uVar6 = uVar10 + 4;
    uVar5 = 0xffffffff;
    if (uVar6 >= uVar10) {
      uVar5 = uVar6;
    }
    param_8._1_1_ = (undefined1)(uVar5 >> 8);
    if (uVar6 < uVar10) {
      return -(uint)(uVar6 < uVar10) & 0xc0000095;
    }
    if (0xfffe < uVar5) {
      uVar5 = 0xffff;
      param_8._1_1_ = 0xff;
    }
  }
  else {
    uVar5 = 8;
    param_4 = (longlong *)0x0;
    param_8._1_1_ = 0;
  }
  lVar11 = 0xffffffff;
  ScratchBuffer_BeginUseX(param_1);
  local_48 = 0xa4;
  uStack_40._0_2_ = CONCAT11((char)uVar5,param_8._1_1_);
  uVar17 = (undefined1)param_3;
  if (param_2 == 0x335004) {
    if ((int)param_4[1] == 4) {
      lVar11 = param_4[2] >> (*(byte *)(param_1 + 0xa0) & 0x3f);
      local_48._0_5_ =
           CONCAT14((char)((ulonglong)lVar11 >> 8),
                    CONCAT13((char)((ulonglong)lVar11 >> 0x10),
                             CONCAT12((char)((ulonglong)lVar11 >> 0x18),0xa4)));
      local_48 = (ulonglong)CONCAT15((char)lVar11,(undefined5)local_48);
    }
    uStack_40 = (ulonglong)
                CONCAT12(*(char *)((longlong)param_4 + 4) << 6 | *(byte *)(param_4 + 1) & 0x3f,
                         (ushort)uStack_40);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar14 = 0x60;
      pcVar8 = "READ_KEY";
      goto LAB_14002481d;
    }
  }
  else {
    uStack_40 = (ulonglong)(ushort)uStack_40;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar14 = 0x61;
      pcVar8 = "START_SESSION";
LAB_14002481d:
      WPP_RECORDER_SF_qs(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar11,5,uVar14,
                         &WPP_7cea3eca420c34d4f6f4315c54c616a1_Traceguids,uVar17,pcVar8);
    }
  }
  puVar16 = &local_48;
  uVar13 = (ulonglong)uVar5;
  uVar5 = ScratchBuffer_ExecuteCdbEx(param_1,param_3,uVar5,'\x01',puVar16,0xc,0);
  if ((int)uVar5 < 0) goto LAB_140024a3d;
  puVar2 = *(undefined1 **)(*(longlong *)(param_1 + 0x408) + 0x18);
  if (param_2 != 0x335004) {
    bVar1 = puVar2[7];
    *puVar4 = 4;
    *param_6 = (uint)(bVar1 >> 6);
    goto LAB_140024a3d;
  }
  uVar10 = *(uint *)(*(longlong *)(param_1 + 0x408) + 0x10);
  if (3 < uVar10) {
    local_res20 = uVar10 - 4;
  }
  uVar6 = (uint)CONCAT11(*puVar2,puVar2[1]);
  uVar9 = Feature_1211600187__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar9 == 0) {
    if ((uVar10 < 4) || (uVar6 < 2)) goto LAB_140024a20;
    uVar6 = uVar6 - 2;
    uVar10 = uVar6;
    if (local_res20 <= uVar6) {
      uVar10 = local_res20;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_3,uVar13,99,puVar16,
                          uVar17,(char)uVar6,
                          (char)*(undefined4 *)(*(longlong *)(param_1 + 0x408) + 0x10) + -2);
    }
    if (param_6[2] == 4) {
      memmove(param_6 + 6,puVar2 + 5,(ulonglong)(uVar10 - 1));
      *(undefined1 *)((ulonglong)(uVar10 - 1) + 0x18 + (longlong)param_6) = 0;
      param_6[3] = (uint)(byte)puVar2[4];
    }
    else {
      memmove(param_6 + 6,puVar2 + 4,(ulonglong)uVar10);
    }
LAB_140024a17:
    uVar12 = (ulonglong)(uVar10 + 0x18);
    *param_6 = uVar10 + 0x18;
  }
  else {
    if ((3 < uVar10) && (1 < uVar6)) {
      uVar6 = uVar6 - 2;
      uVar10 = uVar6;
      if (local_res20 <= uVar6) {
        uVar10 = local_res20;
      }
      if ((param_6[2] != 4) || (uVar10 != 0)) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_3,uVar13,0x62,puVar16
                              ,uVar17,(char)uVar6,
                              (char)*(undefined4 *)(*(longlong *)(param_1 + 0x408) + 0x10) + -2);
        }
        if (param_6[2] == 4) {
          memmove(param_6 + 6,puVar2 + 5,(ulonglong)(uVar10 - 1));
          *(undefined1 *)((ulonglong)(uVar10 - 1) + 0x18 + (longlong)param_6) = 0;
          param_6[3] = (uint)(byte)puVar2[4];
        }
        else {
          memmove(param_6 + 6,puVar2 + 4,(ulonglong)uVar10);
        }
        goto LAB_140024a17;
      }
    }
LAB_140024a20:
    uVar5 = 0;
  }
  *puVar4 = uVar12;
LAB_140024a3d:
  ScratchBuffer_EndUse(param_1);
  return uVar5;
}



===== GetConfigurationDataConversionTypeAllToTypeOne @ 140024a68 =====

void GetConfigurationDataConversionTypeAllToTypeOne
               (uint param_1,longlong param_2,ulonglong *param_3)

{
  undefined1 *puVar1;
  uint uVar2;
  ulonglong uVar3;
  int iVar4;
  uint uVar5;
  int local_res10;
  
  iVar4 = 0;
  *param_3 = 0;
  uVar5 = *(uint *)(param_2 + 0x10);
  if (3 < uVar5) {
    puVar1 = *(undefined1 **)(param_2 + 0x18);
    local_res10 = CONCAT31(CONCAT21(CONCAT11(*puVar1,puVar1[1]),puVar1[2]),puVar1[3]);
    uVar2 = local_res10 + 4U;
    if (uVar5 <= local_res10 + 4U) {
      uVar2 = uVar5;
    }
    if ((0xb < uVar2) && (CONCAT11(puVar1[8],puVar1[9]) == param_1)) {
      iVar4 = (byte)puVar1[0xb] + 4;
    }
    uVar5 = iVar4 + 8;
    puVar1[3] = (char)(iVar4 + 4);
    puVar1[2] = (char)((uint)(iVar4 + 4) >> 8);
    *puVar1 = 0;
    puVar1[1] = 0;
    uVar3 = Feature_3934489913__private_IsEnabledDeviceUsageNoInline();
    if (((int)uVar3 != 0) && (*(uint *)(param_2 + 0x10) <= uVar5)) {
      uVar5 = *(uint *)(param_2 + 0x10);
    }
    *param_3 = (ulonglong)uVar5;
  }
  return;
}



===== GetConfigurationDataSynthesize @ 140024b30 =====

void GetConfigurationDataSynthesize
               (undefined1 *param_1,uint param_2,undefined1 *param_3,ulonglong param_4,uint param_5,
               int param_6,ulonglong *param_7)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  ulonglong _Size;
  undefined1 *_Src;
  uint uVar4;
  ulonglong _Size_00;
  uint uVar5;
  bool bVar6;
  int local_res10;
  
  iVar3 = 8;
  if (param_2 < 8) {
    _Size_00 = 0;
  }
  else {
    local_res10 = CONCAT31(CONCAT21(CONCAT11(*param_1,param_1[1]),param_1[2]),param_1[3]);
    uVar4 = local_res10 + 4U;
    if (param_2 <= local_res10 + 4U) {
      uVar4 = param_2;
    }
    _Size_00 = param_4;
    if (7 < param_4) {
      _Size_00 = 8;
    }
    memmove(param_3,param_1,_Size_00);
    if (8 < uVar4) {
      _Src = param_1 + 8;
      iVar3 = 8;
      for (uVar4 = uVar4 - 8; 3 < uVar4; uVar4 = uVar4 - uVar2) {
        bVar1 = _Src[3];
        uVar5 = bVar1 + 4;
        if ((int)param_5 <= (int)(uint)CONCAT11(*_Src,_Src[1])) {
          if (param_6 != 0) {
            if (param_6 == 1) {
              bVar6 = (bool)(_Src[2] & 1);
            }
            else {
              if (param_6 != 2) goto LAB_140024c3a;
              bVar6 = CONCAT11(*_Src,_Src[1]) == param_5;
            }
            if (bVar6 == false) goto LAB_140024c3a;
          }
          uVar2 = uVar4;
          if (uVar5 < uVar4) {
            uVar2 = uVar5;
          }
          _Size = param_4 - _Size_00;
          if ((ulonglong)uVar2 < param_4 - _Size_00) {
            _Size = (ulonglong)uVar2;
          }
          memmove(param_3 + _Size_00,_Src,_Size);
          _Size_00 = _Size_00 + _Size;
          iVar3 = iVar3 + bVar1 + 4;
        }
LAB_140024c3a:
        uVar2 = uVar4;
        if (uVar5 < uVar4) {
          uVar2 = uVar5;
        }
        _Src = _Src + uVar2;
        uVar2 = uVar4;
        if (uVar5 < uVar4) {
          uVar2 = uVar5;
        }
      }
    }
    if (3 < _Size_00) {
      iVar3 = iVar3 + -4;
      param_3[3] = (char)iVar3;
      param_3[2] = (char)((uint)iVar3 >> 8);
      *param_3 = (char)((uint)iVar3 >> 0x18);
      param_3[1] = (char)((uint)iVar3 >> 0x10);
    }
  }
  *param_7 = _Size_00;
  return;
}



===== ReadDvdStructure @ 140024cac =====

int ReadDvdStructure(longlong param_1,undefined8 param_2,longlong *param_3,undefined8 param_4,
                    undefined2 *param_5,ushort param_6,ulonglong *param_7)

{
  undefined1 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  int iVar4;
  longlong lVar5;
  undefined4 *puVar6;
  uint uVar7;
  undefined1 uStackX_21;
  undefined1 uStackX_22;
  undefined1 uStackX_23;
  undefined1 local_38 [6];
  undefined1 uStack_32;
  undefined1 uStack_31;
  undefined8 uStack_30;
  
  if (*(int *)(param_1 + 0x3d0) == 0x33) {
    lVar5 = *param_3 >> (*(byte *)(param_1 + 0xa0) & 0x3f);
    ScratchBuffer_BeginUseX(param_1);
    uStackX_23 = (undefined1)((ulonglong)lVar5 >> 0x18);
    uStack_30 = 0;
    uStackX_22 = (undefined1)((ulonglong)lVar5 >> 0x10);
    uStackX_21 = (undefined1)((ulonglong)lVar5 >> 8);
    local_38 = (undefined1  [6])
               ((uint6)CONCAT12(uStackX_21,CONCAT11(uStackX_22,uStackX_23)) << 0x10);
    _local_38 = CONCAT17((char)param_3[1],CONCAT16((char)param_3[2],local_38));
    uVar2 = _local_38;
    _local_38 = CONCAT71(stack0xffffffffffffffc9,0xad);
    uVar3 = _local_38;
    _uStack_32 = SUB82(uVar2,6);
    local_38 = (undefined1  [6])CONCAT15((char)lVar5,(int5)uVar3);
    if ((int)param_3[1] == 2) {
      uStack_30 = (ulonglong)(byte)(*(char *)((longlong)param_3 + 0xc) << 6) << 0x10;
    }
    uStack_30._0_2_ = CONCAT11((char)param_6,(char)(param_6 >> 8));
    iVar4 = ScratchBuffer_ExecuteCdbEx
                      (param_1,param_2,(uint)param_6,'\x01',(undefined8 *)local_38,0xc,0);
    if (-1 < iVar4) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x52,
                          &WPP_7cea3eca420c34d4f6f4315c54c616a1_Traceguids,(char)param_3[1]);
      }
      memmove(param_5,*(void **)(*(longlong *)(param_1 + 0x408) + 0x18),
              (ulonglong)*(uint *)(*(longlong *)(param_1 + 0x408) + 0x10));
      if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
         (WPP_RECORDER_SF_qqqL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40)),
         (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x54,
                          &WPP_7cea3eca420c34d4f6f4315c54c616a1_Traceguids,(char)*param_5);
      }
      uVar1 = *(undefined1 *)param_5;
      *(undefined1 *)param_5 = *(undefined1 *)((longlong)param_5 + 1);
      *(undefined1 *)((longlong)param_5 + 1) = uVar1;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x55,
                          &WPP_7cea3eca420c34d4f6f4315c54c616a1_Traceguids,(char)*param_5);
      }
      if (((int)param_3[1] == 0) &&
         (uVar7 = *(uint *)(*(longlong *)(param_1 + 0x408) + 0x10), 4 < uVar7)) {
        uVar7 = uVar7 - 4;
        if (7 < uVar7) {
          puVar6 = (undefined4 *)(param_5 + 4);
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x56,
                              &WPP_7cea3eca420c34d4f6f4315c54c616a1_Traceguids,(char)*puVar6);
          }
          uVar1 = *(undefined1 *)((longlong)param_5 + 0xb);
          *(undefined1 *)((longlong)param_5 + 0xb) = *(undefined1 *)puVar6;
          *(undefined1 *)puVar6 = uVar1;
          uVar1 = *(undefined1 *)(param_5 + 5);
          *(undefined1 *)(param_5 + 5) = *(undefined1 *)((longlong)param_5 + 9);
          *(undefined1 *)((longlong)param_5 + 9) = uVar1;
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x57,
                              &WPP_7cea3eca420c34d4f6f4315c54c616a1_Traceguids,(char)*puVar6);
          }
        }
        if (0xb < uVar7) {
          puVar6 = (undefined4 *)(param_5 + 6);
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x58,
                              &WPP_7cea3eca420c34d4f6f4315c54c616a1_Traceguids,(char)*puVar6);
          }
          uVar1 = *(undefined1 *)((longlong)param_5 + 0xf);
          *(undefined1 *)((longlong)param_5 + 0xf) = *(undefined1 *)puVar6;
          *(undefined1 *)puVar6 = uVar1;
          uVar1 = *(undefined1 *)(param_5 + 7);
          *(undefined1 *)(param_5 + 7) = *(undefined1 *)((longlong)param_5 + 0xd);
          *(undefined1 *)((longlong)param_5 + 0xd) = uVar1;
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x59,
                              &WPP_7cea3eca420c34d4f6f4315c54c616a1_Traceguids,(char)*puVar6);
          }
        }
        if (0xf < uVar7) {
          puVar6 = (undefined4 *)(param_5 + 8);
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x5a,
                              &WPP_7cea3eca420c34d4f6f4315c54c616a1_Traceguids,(char)*puVar6);
          }
          uVar1 = *(undefined1 *)((longlong)param_5 + 0x13);
          *(undefined1 *)((longlong)param_5 + 0x13) = *(undefined1 *)puVar6;
          *(undefined1 *)puVar6 = uVar1;
          uVar1 = *(undefined1 *)(param_5 + 9);
          *(undefined1 *)(param_5 + 9) = *(undefined1 *)((longlong)param_5 + 0x11);
          *(undefined1 *)((longlong)param_5 + 0x11) = uVar1;
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x5b,
                              &WPP_7cea3eca420c34d4f6f4315c54c616a1_Traceguids,(char)*puVar6);
          }
        }
      }
      *param_7 = (ulonglong)*(uint *)(*(longlong *)(param_1 + 0x408) + 0x10);
    }
    ScratchBuffer_EndUse(param_1);
  }
  else {
    *param_7 = 0;
    iVar4 = -0x3ffffff0;
  }
  return iVar4;
}



===== ReadQChannel @ 1400250b0 =====

int ReadQChannel(longlong param_1,undefined8 param_2,byte *param_3,undefined8 param_4,void *param_5,
                ulonglong param_6,ulonglong *param_7)

{
  byte bVar1;
  longlong lVar2;
  void *_Src;
  int iVar3;
  undefined1 uVar4;
  uint uVar5;
  undefined8 local_18;
  ulonglong uStack_10;
  
  uVar5 = 0;
  bVar1 = *param_3;
  *param_7 = 0;
  if (bVar1 == 1) {
    uVar5 = 0x10;
  }
  else if ((bVar1 == 2) || (bVar1 == 3)) {
    uVar5 = 0x18;
  }
  ScratchBuffer_BeginUseX(param_1);
  bVar1 = *param_3;
  uVar4 = 0;
  if (bVar1 == 1) {
    uVar4 = 2;
  }
  local_18 = CONCAT53((uint5)bVar1,0x400000);
  local_18 = (ulonglong)CONCAT61(local_18._2_6_,uVar4) << 8;
  if (bVar1 == 3) {
    local_18 = (ulonglong)CONCAT16(param_3[1],(undefined6)local_18);
  }
  uStack_10 = (ulonglong)(byte)uVar5;
  local_18 = CONCAT71(local_18._1_7_,0x42);
  iVar3 = ScratchBuffer_ExecuteCdbEx(param_1,param_2,uVar5,'\x01',&local_18,10,0);
  if (-1 < iVar3) {
    lVar2 = *(longlong *)(param_1 + 0x408);
    _Src = *(void **)(lVar2 + 0x18);
    *(bool *)(param_1 + 0x350) = *(char *)((longlong)_Src + 1) == '\x11';
    if (param_6 < *(uint *)(lVar2 + 0x10)) {
      *(int *)(lVar2 + 0x10) = (int)param_6;
    }
    memmove(param_5,_Src,(ulonglong)*(uint *)(*(longlong *)(param_1 + 0x408) + 0x10));
    *param_7 = (ulonglong)*(uint *)(*(longlong *)(param_1 + 0x408) + 0x10);
  }
  ScratchBuffer_EndUse(param_1);
  return iVar3;
}



===== RequestHandleDiskVerify @ 1400251fc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int RequestHandleDiskVerify
              (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 *param_4)

{
  uint5 uVar1;
  int iVar2;
  uint uVar3;
  longlong lVar4;
  uint uVar5;
  undefined8 local_28;
  ulonglong uStack_20;
  
  *param_4 = 0;
  if (*(char *)(param_1 + 0x28b) == '\0') {
    iVar2 = -0x3fffff5e;
  }
  else {
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals);
    if (-1 < iVar2) {
      lVar4 = lRam0000000000000000 + *(longlong *)(param_1 + 0xb0);
      if (((lVar4 < *(longlong *)(param_1 + 0xb0)) ||
          (0xffff < uRam0000000000000008 >> (*(byte *)(param_1 + 0xa0) & 0x1f))) ||
         (0xffffffff < lVar4 >> (*(byte *)(param_1 + 0xa0) & 0x3f))) {
        iVar2 = -0x3ffffff3;
      }
      else {
        ScratchBuffer_BeginUseX(param_1);
        lVar4 = lVar4 >> (*(byte *)(param_1 + 0xa0) & 0x3f);
        uVar3 = uRam0000000000000008 >> (*(byte *)(param_1 + 0xa0) & 0x1f);
        local_28._0_5_ =
             (uint5)CONCAT12((char)((ulonglong)lVar4 >> 8),
                             CONCAT11((char)((ulonglong)lVar4 >> 0x10),
                                      (char)((ulonglong)lVar4 >> 0x18))) << 0x10;
        uVar1 = (uint5)(int5)local_28 >> 8;
        local_28 = CONCAT71((uint7)(uint)uVar1,0x2f);
        local_28._0_7_ = (uint7)CONCAT15((char)lVar4,(int5)local_28);
        local_28 = CONCAT17((char)(uVar3 >> 8),(uint7)local_28);
        uStack_20 = (ulonglong)(byte)uVar3;
        uVar5 = 0;
        if (((short)uVar3 != 0) && (uVar5 = *(uint *)(param_1 + 0x78), uVar5 < 0x105)) {
          uVar3 = ((uVar3 & 0xffff) + 0x80 >> 7) * uVar5;
          uVar5 = 0x104;
          if (uVar3 < 0x104) {
            uVar5 = uVar3;
          }
        }
        iVar2 = ScratchBuffer_ExecuteCdbEx(param_1,param_2,0,'\0',&local_28,10,uVar5);
        ScratchBuffer_EndUse(param_1);
      }
    }
  }
  return iVar2;
}



===== RequestHandleEnableStreaming @ 140025370 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int RequestHandleEnableStreaming(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  int iVar1;
  longlong lVar2;
  bool bVar3;
  bool bVar4;
  char cVar5;
  int iVar6;
  longlong lVar7;
  char cVar8;
  char cVar9;
  int *local_res8;
  
  lVar7 = WdfFunctions_01015;
  lVar2 = *(longlong *)(param_1 + 0x478);
  local_res8 = (int *)0x0;
  *param_3 = 0;
  cVar8 = '\0';
  cVar9 = '\0';
  iVar6 = (**(code **)(lVar7 + 0x868))(WdfDriverGlobals,param_2,4,&local_res8,0);
  if (iVar6 < 0) {
    return iVar6;
  }
  lVar7 = (**(code **)(WdfFunctions_01015 + 0x8a8))(WdfDriverGlobals,param_2);
  if ((lVar7 == 0) ||
     (lVar7 = (**(code **)(WdfFunctions_01015 + 0x650))
                        (WdfDriverGlobals,lVar7,PTR__WDF_FILE_OBJECT_CONTEXT_TYPE_INFO_14001a090),
     lVar7 == 0)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x35,
                       &WPP_7cea3eca420c34d4f6f4315c54c616a1_Traceguids);
    }
    return -0x3ffffff8;
  }
  iVar1 = *local_res8;
  bVar3 = true;
  if (iVar1 == 1) goto LAB_140025454;
  cVar5 = '\0';
  if (iVar1 != 2) {
    if (iVar1 == 3) {
      cVar9 = '\x01';
      goto LAB_140025454;
    }
    if (iVar1 != 4) goto LAB_140025454;
    cVar5 = '\x01';
  }
  cVar9 = cVar5;
  cVar8 = '\x01';
LAB_140025454:
  if ((*(char *)(param_1 + 0x28d) == '\0') || ((*(byte *)(lVar2 + 0x10) & 0x20) != 0)) {
    bVar4 = false;
  }
  else {
    bVar4 = true;
  }
  if ((*(char *)(param_1 + 0x28e) == '\0') || ((*(byte *)(lVar2 + 0x10) & 0x20) != 0)) {
    bVar3 = false;
  }
  if (((cVar8 == '\0') || (bVar4)) && ((cVar9 == '\0' || (bVar3)))) {
    *(char *)(lVar7 + 0x18) = cVar8;
    *(char *)(lVar7 + 0x19) = cVar9;
    return iVar6;
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x36,
                     &WPP_7cea3eca420c34d4f6f4315c54c616a1_Traceguids);
  }
  return -0x3ffffff0;
}



===== RequestHandleExclusiveAccessLockDevice @ 140025540 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int RequestHandleExclusiveAccessLockDevice(undefined8 param_1,undefined8 param_2)

{
  undefined8 *_Dst;
  byte bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  longlong lVar6;
  longlong lVar7;
  char *pcVar8;
  undefined8 uVar9;
  undefined4 *puVar10;
  longlong lVar11;
  uint uVar12;
  ulonglong uVar13;
  undefined2 uVar14;
  bool bVar15;
  longlong local_res18 [2];
  
  lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1,DAT_14001a0f0);
  local_res18[0] = 0;
  lVar7 = (**(code **)(WdfFunctions_01015 + 0x8a8))(WdfDriverGlobals,param_2);
  if (lVar7 == 0) {
    iVar5 = -0x3ffffff8;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x20,
                       &WPP_7cea3eca420c34d4f6f4315c54c616a1_Traceguids);
    }
  }
  else {
    iVar5 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_2,0x48,local_res18,0);
    if (-1 < iVar5) {
      uVar13 = 0;
      lVar11 = local_res18[0];
      while ((uVar12 = (uint)uVar13, uVar12 < 0x40 &&
             (bVar1 = *(byte *)(uVar13 + 8 + lVar11), bVar1 != 0))) {
        if ((9 < (byte)(bVar1 - 0x30)) && (0x19 < (byte)((bVar1 | 0x20) + 0x9f))) {
          pcVar8 = strchr(" .,:;_-",(uint)bVar1);
          if (pcVar8 == (char *)0x0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
            goto LAB_14002586a;
            uVar14 = 0x21;
            goto LAB_140025846;
          }
          lVar11 = local_res18[0];
        }
        uVar13 = (ulonglong)(uVar12 + 1);
      }
      if (uVar12 - 1 < 0x3f) {
        if (((*(uint *)(lVar11 + 4) & 1) == 0) &&
           (uVar9 = IsVolumeMounted(*(longlong *)(lVar6 + 0x40)), (char)uVar9 != '\0')) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x23,
                             &WPP_7cea3eca420c34d4f6f4315c54c616a1_Traceguids);
          }
          iVar5 = -0x3ffffe7c;
        }
        else {
          LOCK();
          bVar15 = *(longlong *)(lVar6 + 0x378) == 0;
          if (bVar15) {
            *(longlong *)(lVar6 + 0x378) = lVar7;
          }
          UNLOCK();
          if (bVar15) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x24,
                                &WPP_7cea3eca420c34d4f6f4315c54c616a1_Traceguids,(char)lVar7);
            }
            _Dst = (undefined8 *)(lVar6 + 0x380);
            memset(_Dst,0,0x40);
            memmove(_Dst,(void *)(local_res18[0] + 8),(ulonglong)(uVar12 + 1));
            DeviceSendNotification(lVar6,(undefined4 *)&GUID_IO_CDROM_EXCLUSIVE_LOCK,0,(void *)0x0);
            puVar10 = (undefined4 *)IoAllocateErrorLogEntry(*(undefined8 *)(lVar6 + 0x40),0x70);
            if (puVar10 != (undefined4 *)0x0) {
              puVar10[5] = 0;
              puVar10[6] = 0;
              puVar10[3] = 0x40040085;
              *puVar10 = 0x40000e;
              puVar10[7] = 0x2c05c;
              puVar10[4] = 1;
              uVar9 = *(undefined8 *)(lVar6 + 0x388);
              *(undefined8 *)(puVar10 + 10) = *_Dst;
              *(undefined8 *)(puVar10 + 0xc) = uVar9;
              uVar9 = *(undefined8 *)(lVar6 + 0x398);
              *(undefined8 *)(puVar10 + 0xe) = *(undefined8 *)(lVar6 + 0x390);
              *(undefined8 *)(puVar10 + 0x10) = uVar9;
              uVar2 = *(undefined4 *)(lVar6 + 0x3a4);
              uVar3 = *(undefined4 *)(lVar6 + 0x3a8);
              uVar4 = *(undefined4 *)(lVar6 + 0x3ac);
              puVar10[0x12] = *(undefined4 *)(lVar6 + 0x3a0);
              puVar10[0x13] = uVar2;
              puVar10[0x14] = uVar3;
              puVar10[0x15] = uVar4;
              uVar2 = *(undefined4 *)(lVar6 + 0x3b4);
              uVar3 = *(undefined4 *)(lVar6 + 0x3b8);
              uVar4 = *(undefined4 *)(lVar6 + 0x3bc);
              puVar10[0x16] = *(undefined4 *)(lVar6 + 0x3b0);
              puVar10[0x17] = uVar2;
              puVar10[0x18] = uVar3;
              puVar10[0x19] = uVar4;
              IoWriteErrorLogEntry(puVar10);
            }
          }
          else {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x25,
                               &WPP_7cea3eca420c34d4f6f4315c54c616a1_Traceguids);
            }
            iVar5 = -0x3fffffde;
          }
        }
      }
      else {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar14 = 0x22;
LAB_140025846:
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,uVar14,
                           &WPP_7cea3eca420c34d4f6f4315c54c616a1_Traceguids);
        }
LAB_14002586a:
        iVar5 = -0x3ffffff3;
      }
    }
  }
  RequestCompletion(lVar6,param_2,iVar5,0);
  return iVar5;
}



===== RequestHandleExclusiveAccessQueryLockState @ 1400258a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int RequestHandleExclusiveAccessQueryLockState(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  int iVar2;
  longlong lVar3;
  undefined1 *local_res18;
  
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1,DAT_14001a0f0);
  local_res18 = (undefined1 *)0x0;
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,param_2,0x41,&local_res18,0);
  memset(local_res18,0,0x41);
  if (*(longlong *)(lVar3 + 0x378) == 0) {
    *local_res18 = 0;
  }
  else {
    *local_res18 = 1;
    uVar1 = *(undefined8 *)(lVar3 + 0x388);
    *(undefined8 *)(local_res18 + 1) = *(undefined8 *)(lVar3 + 0x380);
    *(undefined8 *)(local_res18 + 9) = uVar1;
    uVar1 = *(undefined8 *)(lVar3 + 0x398);
    *(undefined8 *)(local_res18 + 0x11) = *(undefined8 *)(lVar3 + 0x390);
    *(undefined8 *)(local_res18 + 0x19) = uVar1;
    uVar1 = *(undefined8 *)(lVar3 + 0x3a8);
    *(undefined8 *)(local_res18 + 0x21) = *(undefined8 *)(lVar3 + 0x3a0);
    *(undefined8 *)(local_res18 + 0x29) = uVar1;
    uVar1 = *(undefined8 *)(lVar3 + 0x3b8);
    *(undefined8 *)(local_res18 + 0x31) = *(undefined8 *)(lVar3 + 0x3b0);
    *(undefined8 *)(local_res18 + 0x39) = uVar1;
  }
  RequestCompletion(lVar3,param_2,iVar2,0x41);
  return iVar2;
}



===== RequestHandleExclusiveAccessUnlockDevice @ 1400259b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int RequestHandleExclusiveAccessUnlockDevice(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 uVar4;
  byte bVar5;
  undefined2 uVar6;
  longlong local_res18;
  
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1,DAT_14001a0f0);
  local_res18 = 0;
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x8a8))(WdfDriverGlobals,param_2);
  if (lVar3 == 0) {
    iVar1 = -0x3ffffff8;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140025ac5;
    uVar6 = 0x26;
    bVar5 = 2;
    iVar1 = -0x3ffffff8;
  }
  else {
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_2,8,&local_res18,0);
    if (iVar1 < 0) goto LAB_140025ac5;
    uVar4 = DeviceUnlockExclusive(lVar2,lVar3,(byte)(*(uint *)(local_res18 + 4) >> 1) & 1);
    iVar1 = (int)uVar4;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140025ac5;
    uVar6 = 0x27;
    bVar5 = 4;
  }
  WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),bVar5,5,uVar6,
                   &WPP_7cea3eca420c34d4f6f4315c54c616a1_Traceguids);
LAB_140025ac5:
  RequestCompletion(lVar2,param_2,iVar1,0);
  return iVar1;
}



===== RequestHandleFakePartitionInfo @ 140025af4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int RequestHandleFakePartitionInfo
              (longlong param_1,undefined8 param_2,longlong param_3,undefined8 *param_4)

{
  int iVar1;
  int iVar2;
  undefined8 *local_res18;
  
  iVar1 = *(int *)(param_3 + 0x18);
  local_res18 = (undefined8 *)0x0;
  *param_4 = 0;
  if ((((iVar1 != 0x7400c) && (iVar1 != 0x70050)) && (iVar1 != 0x74004)) && (iVar1 != 0x70048)) {
    return -0x3fffff1b;
  }
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x870))
                    (WdfDriverGlobals,param_2,*(undefined8 *)(param_3 + 8),&local_res18,0);
  if (iVar2 < 0) {
    return iVar2;
  }
  if (iVar1 == 0x70048) {
    *param_4 = 0x90;
    memset(local_res18,0,0x90);
    goto LAB_140025c78;
  }
  if (iVar1 == 0x70050) {
    *param_4 = 0xc0;
    memset(local_res18,0,0xc0);
LAB_140025c45:
    *(undefined4 *)local_res18 = 0;
    *(undefined4 *)((longlong)local_res18 + 4) = 1;
    *(undefined4 *)(local_res18 + 1) = 1;
    local_res18 = local_res18 + 6;
LAB_140025c78:
    *(undefined4 *)local_res18 = 0;
    *(undefined1 *)((longlong)local_res18 + 0x1c) = 0;
    *(undefined2 *)((longlong)local_res18 + 0x21) = 0x100;
    *(undefined1 *)(local_res18 + 4) = 0xb;
    *(undefined4 *)((longlong)local_res18 + 0x24) = 0;
    local_res18[1] = 0;
    local_res18[2] = *(undefined8 *)(param_1 + 0xa8);
    *(undefined4 *)(local_res18 + 3) = 0;
    return iVar2;
  }
  if (iVar1 == 0x74004) {
    *param_4 = 0x20;
    *local_res18 = 0;
    local_res18[1] = 0;
    local_res18[2] = 0;
    local_res18[3] = 0;
    goto LAB_140025c12;
  }
  if (iVar1 == 0x7400c) {
    *param_4 = 0x28;
    *local_res18 = 0;
    local_res18[1] = 0;
    local_res18[2] = 0;
    local_res18[3] = 0;
    local_res18[4] = 0;
  }
  else if (iVar1 != 0x7400c) {
    if (iVar1 != 0x70050) {
      if (iVar1 != 0x74004) goto LAB_140025c78;
      goto LAB_140025c12;
    }
    goto LAB_140025c45;
  }
  *(undefined4 *)local_res18 = 1;
  *(undefined4 *)((longlong)local_res18 + 4) = 1;
  local_res18 = local_res18 + 1;
LAB_140025c12:
  *(undefined4 *)(local_res18 + 3) = 0x1000b;
  *(undefined4 *)(local_res18 + 2) = 0;
  *local_res18 = 0;
  local_res18[1] = *(undefined8 *)(param_1 + 0xa8);
  *(undefined4 *)((longlong)local_res18 + 0x14) = 0;
  return iVar2;
}



===== RequestHandleGetDvdRegion @ 140025cc4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint RequestHandleGetDvdRegion(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  int iVar1;
  undefined1 *puVar2;
  byte bVar3;
  uint uVar4;
  longlong *plVar5;
  longlong *plVar6;
  undefined1 **ppuVar7;
  undefined1 *puVar8;
  undefined1 *local_res8;
  ulonglong local_res18 [2];
  longlong *plVar9;
  
  local_res8 = (undefined1 *)0x0;
  local_res18[0] = 0;
  plVar5 = (longlong *)0x0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0xb,
                      &WPP_7cea3eca420c34d4f6f4315c54c616a1_Traceguids,(char)param_2);
  }
  iVar1 = *(int *)(param_1 + 0x3d0);
  *param_3 = 0;
  if (iVar1 == 0x33) {
    ppuVar7 = &local_res8;
    uVar4 = (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,param_2,4,ppuVar7,0);
    plVar6 = (longlong *)0x0;
    puVar8 = (undefined1 *)0x0;
    if (-1 < (int)uVar4) {
      plVar5 = (longlong *)ExAllocatePool2(0x40,0x20,0x75436353);
      if (plVar5 == (longlong *)0x0) {
        return 0xc000009a;
      }
      *(undefined4 *)(plVar5 + 1) = 1;
      plVar9 = plVar5;
      uVar4 = ReadDvdStructure(param_1,param_2,plVar5,ppuVar7,(undefined2 *)plVar5,8,local_res18);
      puVar2 = local_res8;
      if (-1 < (int)uVar4) {
        *local_res8 = *(undefined1 *)((longlong)plVar5 + 4);
        local_res8[1] = *(undefined1 *)((longlong)plVar5 + 5);
        *plVar5 = 0x1c;
        *(undefined8 *)((longlong)plVar5 + 0xc) = 0;
        *(undefined8 *)((longlong)plVar5 + 0x14) = 0;
        *(undefined4 *)(plVar5 + 1) = 8;
        uVar4 = DvdStartSessionReadKey
                          (param_1,0x335004,param_2,plVar5,plVar9,(uint *)plVar5,0x1c,local_res18);
        plVar6 = plVar5;
        puVar8 = puVar2;
      }
    }
    if (-1 < (int)uVar4) {
      if (*(char *)((longlong)plVar6 + 0x1a) == '\x01') {
        if (*(byte *)(plVar6 + 3) < 0x40) {
          bVar3 = 0;
        }
        else {
          bVar3 = ~*(byte *)((longlong)plVar6 + 0x19);
        }
        puVar8[2] = bVar3;
        puVar8[3] = *(byte *)(plVar6 + 3) & 7;
        *param_3 = 4;
      }
      else {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,5,0xc,
                           &WPP_7cea3eca420c34d4f6f4315c54c616a1_Traceguids);
        }
        uVar4 = 0xc0000010;
      }
    }
    if (plVar5 != (longlong *)0x0) {
      ExFreePoolWithTag(plVar5,0);
    }
  }
  else {
    uVar4 = 0xc0000010;
  }
  return uVar4;
}



===== RequestHandleGetPerformance @ 140025ef0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int RequestHandleGetPerformance
              (longlong param_1,undefined8 param_2,longlong param_3,size_t *param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  byte bVar4;
  ulonglong _Size;
  ushort uVar5;
  ushort uVar6;
  undefined1 auStackY_b8 [32];
  int *local_78;
  void *local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  ulonglong local_50;
  
  local_50 = __security_cookie ^ (ulonglong)auStackY_b8;
  uVar6 = 0;
  *param_4 = 0;
  local_78 = (int *)0x0;
  local_70 = (void *)0x0;
  local_68 = param_2;
  iVar3 = (**(code **)(WdfFunctions_01015 + 0x868))
                    (WdfDriverGlobals,param_2,*(undefined8 *)(param_3 + 0x10),&local_78);
  if (iVar3 < 0) {
    return iVar3;
  }
  _Size = *(ulonglong *)(param_3 + 8);
  iVar3 = (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,param_2,_Size,&local_70);
  if (iVar3 < 0) {
    return iVar3;
  }
  uVar5 = 0;
  ScratchBuffer_BeginUseX(param_1);
  local_60 = 0;
  uStack_58 = 0;
  if (*local_78 != 1) {
    if (*local_78 == 2) {
      uStack_58 = 0x30000;
      uVar5 = 0x10;
    }
    goto LAB_140026039;
  }
  iVar1 = local_78[2];
  bVar4 = 0x10;
  local_60._0_2_ = 0x1000;
  if (iVar1 == 1) {
    bVar4 = 0x10;
LAB_140025ff0:
    uVar5 = 0x10;
LAB_140025ff4:
    local_60._0_2_ = (ushort)bVar4 << 8;
  }
  else {
    if (iVar1 == 2) {
      bVar4 = 0x11;
      goto LAB_140025ff0;
    }
    uVar5 = 0;
    if (iVar1 == 3) {
      uVar5 = 6;
      bVar4 = 0x12;
      goto LAB_140025ff4;
    }
  }
  if (local_78[1] == 1) {
LAB_14002600f:
    local_60._0_2_ = (ushort)bVar4 << 8;
  }
  else if (local_78[1] == 2) {
    bVar4 = bVar4 | 4;
    goto LAB_14002600f;
  }
  local_60._0_3_ = CONCAT12(*(undefined1 *)((longlong)local_78 + 0x13),(short)local_60);
  local_60 = (ulonglong)
             CONCAT33(CONCAT21(CONCAT11((char)local_78[4],*(undefined1 *)((longlong)local_78 + 0x11)
                                       ),*(undefined1 *)((longlong)local_78 + 0x12)),
                      (undefined3)local_60);
LAB_140026039:
  local_60 = CONCAT71(local_60._1_7_,0xac);
  if ((_Size - 8 < 0xfff8) && (uVar5 != 0)) {
    uVar6 = (ushort)(*(short *)(param_3 + 8) - 8U) / uVar5;
  }
  else {
    iVar3 = -0x3ffffff3;
  }
  uStack_58 = CONCAT71(CONCAT61(uStack_58._2_6_,(char)uVar6),(char)(uVar6 >> 8));
  uVar2 = *(uint *)(*(longlong *)(param_1 + 0xd0) + 0x10);
  if ((-1 < iVar3) &&
     (iVar3 = ScratchBuffer_ExecuteCdbEx
                        (param_1,local_68,uVar2 + (int)_Size & ~uVar2,'\x01',&local_60,0xc,0x14),
     -1 < iVar3)) {
    uVar2 = *(uint *)(*(longlong *)(param_1 + 0x408) + 0x10);
    if (uVar2 < 8) {
      *param_4 = 0;
      iVar3 = -0x3ffffff0;
    }
    else {
      if (uVar2 <= _Size) {
        _Size = (ulonglong)uVar2;
      }
      *param_4 = _Size;
      memmove(local_70,*(void **)(param_1 + 0x3f0),_Size);
    }
  }
  ScratchBuffer_EndUse(param_1);
  return iVar3;
}



===== RequestHandleLoadEjectMedia @ 14002612c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int RequestHandleLoadEjectMedia
              (longlong param_1,undefined8 param_2,longlong param_3,undefined8 *param_4)

{
  char *pcVar1;
  int iVar2;
  undefined1 auStackY_b8 [32];
  undefined2 local_88 [5];
  undefined1 local_7e;
  undefined1 local_40;
  byte local_3c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_b8;
  pcVar1 = *(char **)(param_1 + 0x120);
  *param_4 = 0;
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x110),0);
  if (*(int *)(param_1 + 0xf0) == 0) {
    memset(local_88,0,0x58);
    local_7e = 6;
    local_40 = 0x1b;
    if (*(int *)(param_3 + 0x18) == 0x2d4808) {
      local_3c = local_3c & 0xfe | 2;
      if (((pcVar1 != (char *)0x0) && (*pcVar1 == '\x01')) && (pcVar1[1] == '\0')) {
        pcVar1[0x53] = '\x01';
      }
    }
    else {
      local_3c = local_3c | 3;
    }
    iVar2 = DeviceSendSrbSynchronously(*(undefined8 *)(param_1 + 0x10),local_88,0,0,'\0',param_2);
    if (pcVar1 != (char *)0x0) {
      pcVar1[0x53] = '\0';
    }
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,5,0x40,
                       &WPP_7cea3eca420c34d4f6f4315c54c616a1_Traceguids);
    }
    iVar2 = -0x7fffffef;
  }
  (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x110));
  return iVar2;
}



===== RequestHandlePersistentReserve @ 140026290 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int RequestHandlePersistentReserve
              (longlong param_1,undefined8 param_2,longlong param_3,undefined8 *param_4)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  undefined8 uVar4;
  code *pcVar5;
  undefined8 uVar6;
  int iVar7;
  undefined2 *puVar8;
  undefined4 uVar9;
  bool bVar10;
  void *local_res18 [2];
  
  uVar6 = WdfDriverGlobals;
  iVar3 = *(int *)(param_3 + 0x18);
  uVar4 = *(undefined8 *)(param_3 + 0x10);
  local_res18[0] = (void *)0x0;
  pcVar5 = *(code **)(WdfFunctions_01015 + 0x868);
  *param_4 = 0;
  iVar7 = (*pcVar5)(uVar6,param_2,uVar4,local_res18,0);
  if (-1 < iVar7) {
    puVar8 = (undefined2 *)ExAllocatePool2(0x40,0x68,0x53436353);
    if (puVar8 == (undefined2 *)0x0) {
      iVar7 = -0x3fffff66;
    }
    else {
      bVar1 = *(byte *)((longlong)puVar8 + 0x49);
      bVar10 = iVar3 != 0x2d5018;
      if (bVar10) {
        *(undefined1 *)(puVar8 + 0x24) = 0x5f;
        uVar9 = 0x18;
        *(byte *)((longlong)puVar8 + 0x49) =
             (bVar1 ^ *(byte *)((longlong)local_res18[0] + 8)) & 0x1f ^ bVar1;
        bVar1 = *(byte *)((longlong)local_res18[0] + 9);
        *(byte *)(puVar8 + 0x25) = (bVar1 ^ *(byte *)(puVar8 + 0x25)) & 0xf ^ bVar1;
        bVar2 = *(byte *)((longlong)local_res18[0] + 9);
        *(undefined1 *)(puVar8 + 0x28) = 0x18;
        *(byte *)(puVar8 + 0x25) = (bVar1 ^ bVar2) & 0xf ^ bVar1;
        memmove(local_res18[0],(void *)((longlong)local_res18[0] + 10),0x18);
      }
      else {
        uVar9 = (undefined4)*(undefined8 *)(param_3 + 8);
        *(undefined1 *)(puVar8 + 0x24) = 0x5e;
        *(byte *)((longlong)puVar8 + 0x49) =
             (bVar1 ^ *(byte *)((longlong)local_res18[0] + 8)) & 0x1f ^ bVar1;
        *(undefined1 *)(puVar8 + 0x28) = *(undefined1 *)((longlong)local_res18[0] + 10);
        *(undefined1 *)((longlong)puVar8 + 0x4f) = *(undefined1 *)((longlong)local_res18[0] + 0xb);
      }
      *(undefined2 *)((longlong)puVar8 + 9) = 0xa20;
      iVar7 = DeviceSendSrbSynchronously
                        (*(undefined8 *)(param_1 + 0x10),puVar8,(longlong)local_res18[0],uVar9,
                         bVar10,param_2);
      ExFreePoolWithTag(puVar8,0);
    }
  }
  return iVar7;
}



===== RequestHandleReserveRelease @ 140026400 =====

int RequestHandleReserveRelease
              (longlong param_1,undefined8 param_2,longlong param_3,undefined8 *param_4)

{
  ulonglong uVar1;
  int iVar2;
  undefined2 *puVar3;
  char cVar4;
  
  *param_4 = 0;
  puVar3 = (undefined2 *)ExAllocatePool2(0x40,0x68,0x53436353);
  if (puVar3 == (undefined2 *)0x0) {
    iVar2 = -0x3fffff66;
  }
  else {
    iVar2 = *(int *)(param_3 + 0x18);
    uVar1 = *(ulonglong *)(*(longlong *)(param_1 + 0x478) + 0x10);
    if ((uVar1 & 8) == 0) {
      cVar4 = (iVar2 != 0x2d4810) + '\x16';
    }
    else {
      cVar4 = (iVar2 != 0x2d4810) + 'V';
    }
    *(byte *)(puVar3 + 5) = (-((uVar1 & 8) != 0) & 4U) + 6;
    *(char *)(puVar3 + 0x24) = cVar4;
    *(undefined4 *)(puVar3 + 10) = *(undefined4 *)(param_1 + 0x78);
    if (iVar2 == 0x2d4810) {
      *(uint *)(puVar3 + 6) = *(uint *)(puVar3 + 6) | 2;
      *(undefined1 *)((longlong)puVar3 + 9) = 0x20;
    }
    iVar2 = DeviceSendSrbSynchronously(*(undefined8 *)(param_1 + 0x10),puVar3,0,0,'\0',param_2);
    *param_4 = 0;
    ExFreePoolWithTag(puVar3,0);
  }
  return iVar2;
}



===== RequestHandleSendOpcInformation @ 1400264fc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int RequestHandleSendOpcInformation(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong lVar1;
  int iVar2;
  undefined8 local_18;
  undefined8 uStack_10;
  
  lVar1 = WdfFunctions_01015;
  *param_3 = 0;
  iVar2 = (**(code **)(lVar1 + 0x868))(WdfDriverGlobals);
  if (-1 < iVar2) {
    ScratchBuffer_BeginUseX(param_1);
    uStack_10 = 0;
    local_18 = (ulonglong)
               CONCAT12(cRam0000000000000004 != '\0' | -(cRam0000000000000005 != '\0') & 2U,0x154);
    iVar2 = ScratchBuffer_ExecuteCdbEx(param_1,param_2,0,'\0',&local_18,10,0);
    ScratchBuffer_EndUse(param_1);
  }
  return iVar2;
}



===== DeviceDisableGesn @ 1400265e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void DeviceDisableGesn(undefined8 param_1)

{
  undefined8 uVar1;
  longlong lVar2;
  
  uVar1 = (**(code **)(WdfFunctions_01015 + 0xbe8))(WdfDriverGlobals,param_1);
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,uVar1,DAT_14001a0f0);
  DeviceSetParameter(lVar2,0x140015260,L"MMCDetectionState",1);
  (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,param_1);
  return;
}



===== DeviceDisableMediaChangeDetection @ 140026674 =====

void DeviceDisableMediaChangeDetection(longlong param_1,longlong param_2)

{
  longlong lVar1;
  int iVar2;
  
  lVar1 = *(longlong *)(param_1 + 0x118);
  if (param_2 != 0) {
    LOCK();
    *(int *)(param_2 + 0x14) = *(int *)(param_2 + 0x14) + 1;
    UNLOCK();
  }
  if (lVar1 != 0) {
    KeWaitForSingleObject(lVar1 + 8,6,0,0,0);
    iVar2 = *(int *)(lVar1 + 0x50) + 1;
    *(int *)(lVar1 + 0x50) = iVar2;
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,0xd,0x51,
                        &WPP_bfcef3ce16aa3c5196ed71474c974d5c_Traceguids,(char)iVar2);
    }
    KeReleaseMutex(lVar1 + 8,0);
  }
  return;
}



===== DeviceEnableMediaChangeDetection @ 14002672c =====

void DeviceEnableMediaChangeDetection(longlong param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  byte bVar3;
  short sVar4;
  int iVar5;
  
  lVar2 = *(longlong *)(param_1 + 0x118);
  if (param_2 != 0) {
    LOCK();
    *(int *)(param_2 + 0x14) = *(int *)(param_2 + 0x14) + -1;
    UNLOCK();
  }
  if (lVar2 == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return;
    }
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,0xd,0x4d,
                     &WPP_bfcef3ce16aa3c5196ed71474c974d5c_Traceguids);
    return;
  }
  KeWaitForSingleObject(lVar2 + 8,6,0,0,0);
  iVar1 = *(int *)(lVar2 + 0x50);
  iVar5 = iVar1 + -1;
  *(int *)(lVar2 + 0x50) = iVar5;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,0xd,0x4e,
                      &WPP_bfcef3ce16aa3c5196ed71474c974d5c_Traceguids,(char)iVar5);
  }
  if (iVar5 == 0) {
    *(undefined4 *)(lVar2 + 0x4c) = *(undefined4 *)(lVar2 + 0x48);
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140026860;
    sVar4 = (short)iVar1 + 0x4e;
    bVar3 = 4;
  }
  else {
    if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
       (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) goto LAB_140026860;
    sVar4 = 0x50;
    bVar3 = 5;
  }
  WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),bVar3,0xd,sVar4,
                   &WPP_bfcef3ce16aa3c5196ed71474c974d5c_Traceguids);
LAB_140026860:
  KeReleaseMutex(lVar2 + 8,0);
  return;
}



===== DeviceIsMediaChangeDisabledForClass @ 140026894 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

bool DeviceIsMediaChangeDisabledForClass(longlong param_1)

{
  int iVar1;
  char *pcVar2;
  undefined8 uVar3;
  int local_res10 [2];
  longlong local_res18;
  undefined8 local_res20;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  
  local_res10[0] = 1;
  local_res20 = 0;
  local_res18 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_48 = 0;
  uStack_40 = 0;
  uVar3 = *WdfDriverGlobals;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x3b8))(WdfDriverGlobals,uVar3,0xf003f,0,&local_res20);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      pcVar2 = "Enabled";
      if (local_res10[0] == 0) {
        pcVar2 = "Disabled";
      }
      WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar3,0xd,0x49,
                        &WPP_bfcef3ce16aa3c5196ed71474c974d5c_Traceguids,pcVar2);
    }
  }
  else {
    RtlInitUnicodeString(&local_38,L"Parameters");
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x728))
                      (WdfDriverGlobals,local_res20,&local_38,0x20019,0,&local_res18);
    if (iVar1 < 0) {
      local_res18 = 0;
    }
    RtlInitUnicodeString(&local_48,L"Autorun");
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x780))
                      (WdfDriverGlobals,local_res20,&local_48,local_res10);
    if (((-1 < iVar1) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,0xd,0x4a,
                        &WPP_bfcef3ce16aa3c5196ed71474c974d5c_Traceguids,(char)local_res10[0]);
    }
    if (local_res18 != 0) {
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x780))
                        (WdfDriverGlobals,local_res18,&local_48,local_res10);
      if (((-1 < iVar1) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) &&
         (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
        WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,0xd,0x4b,
                          &WPP_bfcef3ce16aa3c5196ed71474c974d5c_Traceguids,(char)local_res10[0]);
      }
      (**(code **)(WdfFunctions_01015 + 0x738))(WdfDriverGlobals,local_res18);
    }
    uVar3 = local_res20;
    (**(code **)(WdfFunctions_01015 + 0x738))(WdfDriverGlobals);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      pcVar2 = "on";
      if (local_res10[0] == 0) {
        pcVar2 = "off";
      }
      WPP_RECORDER_SF_qs(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar3,0xd,0x4c,
                         &WPP_bfcef3ce16aa3c5196ed71474c974d5c_Traceguids,
                         (char)*(undefined8 *)(param_1 + 0x40),pcVar2);
    }
  }
  return local_res10[0] == 0;
}



===== DeviceMediaChangeRegistryCallBack @ 140026b40 =====

undefined8
DeviceMediaChangeRegistryCallBack
          (undefined8 param_1,int param_2,longlong param_3,int param_4,ushort *param_5,int *param_6)

{
  uint uVar1;
  ulonglong uVar2;
  byte bVar3;
  undefined2 uVar4;
  
  if ((param_5 == (ushort *)0x0) || (param_6 == (int *)0x0)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0;
    }
    uVar4 = 0x40;
  }
  else {
    if (*param_6 != 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return 0;
      }
      uVar4 = 0x41;
      bVar3 = 4;
      goto LAB_140026cd8;
    }
    if (param_4 != 2) {
      if (param_2 != 1) {
        return 0;
      }
      if (param_3 == 0) {
        return 0;
      }
      uVar1 = (uint)*param_5;
      if (param_4 - 2U <= (uint)*param_5) {
        uVar1 = param_4 - 2U;
      }
      uVar2 = RtlCompareMemory(*(undefined8 *)(param_5 + 4),param_3,uVar1);
      if (uVar2 != uVar1) {
        return 0;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,0xd,0x43,
                           &WPP_bfcef3ce16aa3c5196ed71474c974d5c_Traceguids);
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
            WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,0xd,0x44,
                              &WPP_bfcef3ce16aa3c5196ed71474c974d5c_Traceguids,
                              (char)*(undefined8 *)(param_5 + 4));
          }
          if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
             (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
            WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,0xd,0x45,
                              &WPP_bfcef3ce16aa3c5196ed71474c974d5c_Traceguids,(char)param_3);
          }
        }
      }
      *param_6 = 1;
      return 0;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0;
    }
    uVar4 = 0x42;
  }
  bVar3 = 3;
LAB_140026cd8:
  WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),bVar3,0xd,uVar4,
                   &WPP_bfcef3ce16aa3c5196ed71474c974d5c_Traceguids);
  return 0;
}



===== DeviceReleaseMcnResources @ 140026d1c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void DeviceReleaseMcnResources(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar1 = *(longlong *)(param_1 + 0x118);
  if (lVar1 != 0) {
    if (*(longlong *)(lVar1 + 0x68) != 0) {
      lVar2 = (**(code **)(WdfFunctions_01015 + 0x8e8))
                        (WdfDriverGlobals,*(undefined8 *)(lVar1 + 0x80));
      IoFreeMdl(*(undefined8 *)(lVar1 + 0x68));
      *(undefined8 *)(lVar2 + 8) = 0;
    }
    IoFreeIrp(*(undefined8 *)(lVar1 + 0x40));
    if (*(longlong *)(lVar1 + 0x60) != 0) {
      ExFreePoolWithTag(*(longlong *)(lVar1 + 0x60),0);
      *(undefined8 *)(lVar1 + 0x60) = 0;
    }
    if (*(longlong *)(lVar1 + 0xe0) != 0) {
      ExFreePoolWithTag(*(longlong *)(lVar1 + 0xe0),0);
      *(undefined8 *)(lVar1 + 0xe0) = 0;
    }
    if (*(longlong *)(lVar1 + 0xf0) != 0) {
      PoUnregisterPowerSettingCallback();
      *(undefined8 *)(lVar1 + 0xf0) = 0;
    }
    ExFreePoolWithTag(lVar1,0);
    *(undefined8 *)(param_1 + 0x118) = 0;
  }
  return;
}



===== RequestHandleMcnControl @ 140026e1c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int RequestHandleMcnControl(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  char cVar1;
  int iVar2;
  longlong lVar3;
  char *local_res18 [2];
  
  lVar3 = WdfFunctions_01015;
  local_res18[0] = (char *)0x0;
  *param_3 = 0;
  iVar2 = (**(code **)(lVar3 + 0x868))(WdfDriverGlobals,param_2,1,local_res18,0);
  if (iVar2 < 0) {
    return iVar2;
  }
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x8a8))(WdfDriverGlobals,param_2);
  if (((lVar3 == 0) ||
      (lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                         (WdfDriverGlobals,lVar3,PTR__WDF_FILE_OBJECT_CONTEXT_TYPE_INFO_14001a090),
      lVar3 == 0)) &&
     ((cVar1 = (**(code **)(WdfFunctions_01015 + 0x8c0))(WdfDriverGlobals,param_2), cVar1 != '\0' ||
      (lVar3 = param_1 + 0x128, lVar3 == 0)))) {
    return -0x3ffffff3;
  }
  if (*local_res18[0] == '\0') {
    if (*(int *)(lVar3 + 0x14) == 0) {
      iVar2 = -0x3ffffe7c;
    }
    else {
      DeviceEnableMediaChangeDetection(param_1,lVar3);
    }
  }
  else {
    DeviceDisableMediaChangeDetection(param_1,lVar3);
  }
  return iVar2;
}



===== DeviceAllocateMmcResources @ 140026f34 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong DeviceAllocateMmcResources(undefined8 param_1)

{
  uint *puVar1;
  undefined8 *puVar2;
  uint uVar3;
  longlong lVar4;
  ulonglong uVar5;
  longlong lVar6;
  uint uVar7;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined *local_18;
  
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1,DAT_14001a0f0);
  puVar1 = (uint *)(lVar4 + 0x328);
  puVar2 = (undefined8 *)(lVar4 + 800);
  uVar5 = DeviceGetConfigurationWithAlloc(param_1,puVar2,puVar1);
  if (-1 < (int)uVar5) {
    lVar6 = IoAllocateMdl(*puVar2,*puVar1,0,0,0);
    *(longlong *)(lVar4 + 0x330) = lVar6;
    if (lVar6 != 0) {
      lVar6 = IoAllocateIrp(*(char *)(*(longlong *)(lVar4 + 0x40) + 0x4c) + '\x01',0);
      *(longlong *)(lVar4 + 0x2f8) = lVar6;
      if (lVar6 != 0) {
        local_38 = 0;
        uStack_40 = 0;
        local_48 = 0x38;
        local_28 = 0;
        uStack_20 = 0;
        uStack_30 = 0x100000001;
        local_18 = PTR__WDF_CDROM_REQUEST_CONTEXT_TYPE_INFO_14001a018;
        uVar3 = (**(code **)(WdfFunctions_01015 + 0x7c0))
                          (WdfDriverGlobals,&local_48,*(undefined8 *)(lVar4 + 0x2f8),0,lVar4 + 0x300
                          );
        uVar7 = 0;
        if ((int)uVar3 < 0) {
          uVar7 = uVar3;
        }
        return (ulonglong)uVar7;
      }
      IoFreeMdl(*(undefined8 *)(lVar4 + 0x330));
      *(undefined8 *)(lVar4 + 0x330) = 0;
    }
    ExFreePoolWithTag(*puVar2,0);
    uVar5 = 0xc000009a;
    *puVar2 = 0;
    *puVar1 = 0;
  }
  return uVar5;
}



===== DeviceGetConfigurationWithAlloc @ 1400270b4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong DeviceGetConfigurationWithAlloc(undefined8 param_1,undefined8 *param_2,uint *param_3)

{
  ulonglong uVar1;
  undefined1 *puVar2;
  uint uVar3;
  uint uVar4;
  ulonglong uVar5;
  uint uVar6;
  undefined1 auStackY_88 [32];
  uint local_58 [2];
  undefined8 local_50;
  undefined1 local_48;
  undefined4 local_47;
  undefined2 local_43;
  undefined1 local_41;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_88;
  *param_2 = 0;
  *param_3 = 0;
  local_58[0] = 0;
  local_48 = 0;
  local_47 = 0;
  uVar6 = 0;
  local_43 = 0;
  local_41 = 0;
  local_50 = param_1;
  uVar1 = DeviceGetConfiguration(param_1,&local_48,8,local_58,0,0);
  uVar5 = uVar1 & 0xffffffff;
  if (-1 < (int)uVar1) {
    uVar3 = CONCAT31(CONCAT21(CONCAT11(local_48,(undefined1)local_47),local_47._1_1_),local_47._2_1_
                    );
    for (; uVar6 < 4; uVar6 = uVar6 + 1) {
      if ((int)uVar5 < 0) goto LAB_14002728c;
      uVar4 = uVar3 + 4;
      uVar3 = uVar4;
      if (uVar4 < 5) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,10,
                            &WPP_d8e52d07227d39443b0054e092747dea_Traceguids,(char)uVar4);
        }
        uVar5 = 0xc0000001;
      }
      else {
        puVar2 = (undefined1 *)ExAllocatePool2(0x48,uVar4,0x46436353);
        if (puVar2 == (undefined1 *)0x0) {
          uVar5 = 0xc000009a;
        }
        else {
          uVar1 = DeviceGetConfiguration(param_1,puVar2,uVar4,local_58,0,0);
          uVar5 = uVar1 & 0xffffffff;
          if ((int)uVar1 < 0) {
            ExFreePoolWithTag(puVar2,0);
          }
          else if (uVar4 < local_58[0]) {
            ExFreePoolWithTag(puVar2,0);
            uVar5 = 0xc00000e5;
          }
          else {
            uVar3 = CONCAT31(CONCAT21(CONCAT11(*puVar2,puVar2[1]),puVar2[2]),puVar2[3]) + 4;
            if (uVar3 <= uVar4) {
              *param_2 = puVar2;
              *param_3 = uVar3;
              return 0;
            }
            local_58[0] = uVar3;
            ExFreePoolWithTag(puVar2,0);
            param_1 = local_50;
          }
        }
      }
    }
    if (-1 < (int)uVar5) {
      return uVar5;
    }
  }
LAB_14002728c:
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0xb,
                      &WPP_d8e52d07227d39443b0054e092747dea_Traceguids,(char)uVar6);
  }
  return uVar5;
}



===== ScratchBuffer_Deallocate @ 1400272e8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ScratchBuffer_Deallocate(longlong param_1)

{
  longlong lVar1;
  
  if (*(longlong *)(param_1 + 0x418) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x418),0);
    *(undefined8 *)(param_1 + 0x418) = 0;
  }
  if (*(longlong *)(param_1 + 0x410) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x410),0);
    *(undefined8 *)(param_1 + 0x410) = 0;
  }
  if (*(longlong *)(param_1 + 0x408) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x408),0);
    *(undefined8 *)(param_1 + 0x408) = 0;
  }
  if (*(int *)(param_1 + 1000) != 0) {
    *(undefined4 *)(param_1 + 1000) = 0;
  }
  if (*(longlong *)(param_1 + 0x3f8) != 0) {
    IoFreeMdl();
    *(undefined8 *)(param_1 + 0x3f8) = 0;
  }
  if (*(longlong *)(param_1 + 0x3f0) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x3f0),0);
    *(undefined8 *)(param_1 + 0x3f0) = 0;
  }
  if (*(longlong *)(param_1 + 0x420) != 0) {
    IoFreeMdl();
    *(undefined8 *)(param_1 + 0x420) = 0;
  }
  if (*(longlong *)(param_1 + 0x400) != 0) {
    lVar1 = (**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals);
    if (*(longlong *)(lVar1 + 8) != 0) {
      *(undefined8 *)(lVar1 + 8) = 0;
    }
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x400));
    *(undefined8 *)(param_1 + 0x400) = 0;
  }
  return;
}



===== DeviceHandleAacsEndSession @ 140027434 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int DeviceHandleAacsEndSession
              (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 *param_4)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined8 local_28;
  longlong lStack_20;
  
  lVar1 = WdfFunctions_01015;
  *param_4 = 0;
  iVar2 = (**(code **)(lVar1 + 0x868))(WdfDriverGlobals);
  if (-1 < iVar2) {
    uVar3 = uRam0000000000000000;
    if (uRam0000000000000000 == 0xffffffff) {
      uVar3 = 3;
    }
    ScratchBuffer_BeginUseX(param_1);
    uVar4 = 0;
    if (uRam0000000000000000 != 0xffffffff) {
      uVar4 = uRam0000000000000000;
    }
    do {
      lStack_20 = (ulonglong)(byte)((char)uVar4 << 6 | 0x3f) << 0x10;
      local_28 = 0x2000000000000a3;
      iVar2 = ScratchBuffer_ExecuteCdbEx(param_1,param_2,0,'\0',&local_28,0xc,0);
      uVar4 = uVar4 + 1;
      if (uVar3 < uVar4) break;
    } while (-1 < iVar2);
    ScratchBuffer_EndUse(param_1);
  }
  return iVar2;
}



===== DeviceHandleAacsGenerateBindingNonce @ 140027520 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int DeviceHandleAacsGenerateBindingNonce
              (longlong param_1,undefined8 param_2,longlong param_3,undefined8 *param_4)

{
  ushort *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  longlong lVar4;
  ushort uVar5;
  int iVar6;
  undefined8 *local_res18;
  undefined8 local_res20;
  undefined8 local_28;
  undefined8 uStack_20;
  
  lVar4 = WdfFunctions_01015;
  local_res20 = 0;
  local_res18 = (undefined8 *)0x0;
  *param_4 = 0;
  iVar6 = (**(code **)(lVar4 + 0x868))
                    (WdfDriverGlobals,param_2,*(undefined8 *)(param_3 + 0x10),&local_res20,0);
  if (-1 < iVar6) {
    iVar6 = (**(code **)(WdfFunctions_01015 + 0x870))
                      (WdfDriverGlobals,param_2,*(undefined8 *)(param_3 + 8),&local_res18,0);
    if (-1 < iVar6) {
      ScratchBuffer_BeginUseX(param_1);
      local_28 = 0;
      uStack_20 = 0;
      iVar6 = ScratchBuffer_ExecuteCdbEx(param_1,param_2,0x24,'\x01',&local_28,0xc,0);
      if (-1 < iVar6) {
        puVar1 = *(ushort **)(param_1 + 0x3f0);
        uVar5 = *puVar1;
        *(undefined1 *)puVar1 = *(undefined1 *)((longlong)puVar1 + 1);
        *(char *)((longlong)puVar1 + 1) = (char)uVar5;
        if ((*puVar1 < 2) || (uVar5 = *puVar1 - 2, *puVar1 = uVar5, uVar5 != 0x20)) {
          *param_4 = 0;
          iVar6 = -0x3ffffe7b;
        }
        else {
          uVar2 = *(undefined8 *)(puVar1 + 2);
          uVar3 = *(undefined8 *)(puVar1 + 6);
          *param_4 = 0x20;
          *local_res18 = uVar2;
          local_res18[1] = uVar3;
          uVar2 = *(undefined8 *)(puVar1 + 0xe);
          local_res18[2] = *(undefined8 *)(puVar1 + 10);
          local_res18[3] = uVar2;
        }
      }
      ScratchBuffer_EndUse(param_1);
    }
  }
  return iVar6;
}



===== DeviceHandleAacsGetCertificate @ 14002766c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int DeviceHandleAacsGetCertificate
              (longlong param_1,undefined8 param_2,longlong param_3,undefined8 *param_4)

{
  ushort *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  longlong lVar4;
  ushort uVar5;
  int iVar6;
  char *local_res18;
  undefined8 *local_res20;
  undefined1 local_38;
  undefined6 uStack_37;
  undefined1 uStack_31;
  undefined1 uStack_30;
  undefined1 uStack_2f;
  byte bStack_2e;
  undefined5 uStack_2d;
  
  lVar4 = WdfFunctions_01015;
  local_res18 = (char *)0x0;
  local_res20 = (undefined8 *)0x0;
  *param_4 = 0;
  iVar6 = (**(code **)(lVar4 + 0x868))
                    (WdfDriverGlobals,param_2,*(undefined8 *)(param_3 + 0x10),&local_res18,0);
  if (-1 < iVar6) {
    iVar6 = (**(code **)(WdfFunctions_01015 + 0x870))
                      (WdfDriverGlobals,param_2,*(undefined8 *)(param_3 + 8),&local_res20,0);
    if (-1 < iVar6) {
      ScratchBuffer_BeginUseX(param_1);
      uStack_37 = 0;
      uStack_2d = 0;
      bStack_2e = *local_res18 << 6 | 1;
      local_38 = 0xa4;
      uStack_31 = 2;
      uStack_30 = 0;
      uStack_2f = 0x74;
      iVar6 = ScratchBuffer_ExecuteCdbEx(param_1,param_2,0x74,'\x01',(undefined8 *)&local_38,0xc,0);
      if (-1 < iVar6) {
        puVar1 = *(ushort **)(param_1 + 0x3f0);
        uVar5 = *puVar1;
        *(undefined1 *)puVar1 = *(undefined1 *)((longlong)puVar1 + 1);
        *(char *)((longlong)puVar1 + 1) = (char)uVar5;
        if ((*puVar1 < 2) || (uVar5 = *puVar1 - 2, *puVar1 = uVar5, uVar5 != 0x70)) {
          *param_4 = 0;
          iVar6 = -0x3ffffe7b;
        }
        else {
          uVar2 = *(undefined8 *)(puVar1 + 2);
          uVar3 = *(undefined8 *)(puVar1 + 6);
          *param_4 = 0x70;
          *local_res20 = uVar2;
          local_res20[1] = uVar3;
          uVar2 = *(undefined8 *)(puVar1 + 0xe);
          local_res20[2] = *(undefined8 *)(puVar1 + 10);
          local_res20[3] = uVar2;
          uVar2 = *(undefined8 *)(puVar1 + 0x16);
          local_res20[4] = *(undefined8 *)(puVar1 + 0x12);
          local_res20[5] = uVar2;
          uVar2 = *(undefined8 *)(puVar1 + 0x1e);
          local_res20[6] = *(undefined8 *)(puVar1 + 0x1a);
          local_res20[7] = uVar2;
          uVar2 = *(undefined8 *)(puVar1 + 0x26);
          local_res20[8] = *(undefined8 *)(puVar1 + 0x22);
          local_res20[9] = uVar2;
          uVar2 = *(undefined8 *)(puVar1 + 0x2e);
          local_res20[10] = *(undefined8 *)(puVar1 + 0x2a);
          local_res20[0xb] = uVar2;
          uVar2 = *(undefined8 *)(puVar1 + 0x36);
          local_res20[0xc] = *(undefined8 *)(puVar1 + 0x32);
          local_res20[0xd] = uVar2;
        }
      }
      ScratchBuffer_EndUse(param_1);
    }
  }
  return iVar6;
}



===== DeviceHandleAacsGetChallengeKey @ 1400277f4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int DeviceHandleAacsGetChallengeKey
              (longlong param_1,undefined8 param_2,longlong param_3,undefined8 *param_4)

{
  ushort *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  longlong lVar4;
  ushort uVar5;
  int iVar6;
  char *local_res18;
  undefined8 *local_res20;
  undefined1 local_38;
  undefined6 uStack_37;
  undefined1 uStack_31;
  undefined1 uStack_30;
  undefined1 uStack_2f;
  byte bStack_2e;
  undefined5 uStack_2d;
  
  lVar4 = WdfFunctions_01015;
  local_res18 = (char *)0x0;
  local_res20 = (undefined8 *)0x0;
  *param_4 = 0;
  iVar6 = (**(code **)(lVar4 + 0x868))
                    (WdfDriverGlobals,param_2,*(undefined8 *)(param_3 + 0x10),&local_res18,0);
  if (-1 < iVar6) {
    iVar6 = (**(code **)(WdfFunctions_01015 + 0x870))
                      (WdfDriverGlobals,param_2,*(undefined8 *)(param_3 + 8),&local_res20,0);
    if (-1 < iVar6) {
      ScratchBuffer_BeginUseX(param_1);
      uStack_37 = 0;
      uStack_2d = 0;
      bStack_2e = *local_res18 << 6 | 2;
      local_38 = 0xa4;
      uStack_31 = 2;
      uStack_30 = 0;
      uStack_2f = 0x54;
      iVar6 = ScratchBuffer_ExecuteCdbEx(param_1,param_2,0x54,'\x01',(undefined8 *)&local_38,0xc,0);
      if (-1 < iVar6) {
        puVar1 = *(ushort **)(param_1 + 0x3f0);
        uVar5 = *puVar1;
        *(undefined1 *)puVar1 = *(undefined1 *)((longlong)puVar1 + 1);
        *(char *)((longlong)puVar1 + 1) = (char)uVar5;
        if ((*puVar1 < 2) || (uVar5 = *puVar1 - 2, *puVar1 = uVar5, uVar5 != 0x50)) {
          *param_4 = 0;
          iVar6 = -0x3ffffe7b;
        }
        else {
          uVar2 = *(undefined8 *)(puVar1 + 2);
          uVar3 = *(undefined8 *)(puVar1 + 6);
          *param_4 = 0x50;
          *local_res20 = uVar2;
          local_res20[1] = uVar3;
          uVar2 = *(undefined8 *)(puVar1 + 0xe);
          local_res20[2] = *(undefined8 *)(puVar1 + 10);
          local_res20[3] = uVar2;
          uVar2 = *(undefined8 *)(puVar1 + 0x16);
          local_res20[4] = *(undefined8 *)(puVar1 + 0x12);
          local_res20[5] = uVar2;
          uVar2 = *(undefined8 *)(puVar1 + 0x1e);
          local_res20[6] = *(undefined8 *)(puVar1 + 0x1a);
          local_res20[7] = uVar2;
          uVar2 = *(undefined8 *)(puVar1 + 0x26);
          local_res20[8] = *(undefined8 *)(puVar1 + 0x22);
          local_res20[9] = uVar2;
        }
      }
      ScratchBuffer_EndUse(param_1);
    }
  }
  return iVar6;
}



===== DeviceHandleAacsReadBindingNonce @ 14002796c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int DeviceHandleAacsReadBindingNonce
              (longlong param_1,undefined8 param_2,longlong param_3,undefined8 *param_4)

{
  undefined8 uVar1;
  ushort *puVar2;
  undefined8 uVar3;
  longlong lVar4;
  ushort uVar5;
  int iVar6;
  char *local_res18;
  undefined8 *local_res20;
  undefined1 local_38;
  undefined1 uStack_37;
  undefined1 uStack_36;
  undefined1 uStack_35;
  undefined1 uStack_34;
  char cStack_33;
  char cStack_32;
  undefined1 uStack_31;
  undefined1 uStack_30;
  undefined1 uStack_2f;
  byte bStack_2e;
  undefined5 uStack_2d;
  
  lVar4 = WdfFunctions_01015;
  local_res18 = (char *)0x0;
  local_res20 = (undefined8 *)0x0;
  *param_4 = 0;
  iVar6 = (**(code **)(lVar4 + 0x868))
                    (WdfDriverGlobals,param_2,*(undefined8 *)(param_3 + 0x10),&local_res18,0);
  if (-1 < iVar6) {
    iVar6 = (**(code **)(WdfFunctions_01015 + 0x870))
                      (WdfDriverGlobals,param_2,*(undefined8 *)(param_3 + 8),&local_res20,0);
    if (-1 < iVar6) {
      ScratchBuffer_BeginUseX(param_1);
      uStack_37 = 0;
      uStack_2d = 0;
      uVar1 = *(undefined8 *)(local_res18 + 8);
      local_38 = 0xa4;
      uStack_36 = (undefined1)((ulonglong)uVar1 >> 0x18);
      uStack_35 = (undefined1)((ulonglong)uVar1 >> 0x10);
      cStack_33 = local_res18[8];
      cStack_32 = local_res18[4];
      bStack_2e = *local_res18 << 6 | 0x21;
      uStack_34 = (undefined1)((ulonglong)uVar1 >> 8);
      uStack_31 = 2;
      uStack_30 = 0;
      uStack_2f = 0x24;
      iVar6 = ScratchBuffer_ExecuteCdbEx(param_1,param_2,0x24,'\x01',(undefined8 *)&local_38,0xc,0);
      if (-1 < iVar6) {
        puVar2 = *(ushort **)(param_1 + 0x3f0);
        uVar5 = *puVar2;
        *(undefined1 *)puVar2 = *(undefined1 *)((longlong)puVar2 + 1);
        *(char *)((longlong)puVar2 + 1) = (char)uVar5;
        if ((*puVar2 < 2) || (uVar5 = *puVar2 - 2, *puVar2 = uVar5, uVar5 != 0x20)) {
          *param_4 = 0;
          iVar6 = -0x3ffffe7b;
        }
        else {
          uVar1 = *(undefined8 *)(puVar2 + 2);
          uVar3 = *(undefined8 *)(puVar2 + 6);
          *param_4 = 0x20;
          *local_res20 = uVar1;
          local_res20[1] = uVar3;
          uVar1 = *(undefined8 *)(puVar2 + 0xe);
          local_res20[2] = *(undefined8 *)(puVar2 + 10);
          local_res20[3] = uVar1;
        }
      }
      ScratchBuffer_EndUse(param_1);
    }
  }
  return iVar6;
}



===== DeviceHandleAacsReadMediaId @ 140027af4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int DeviceHandleAacsReadMediaId
              (longlong param_1,undefined8 param_2,longlong param_3,undefined8 *param_4)

{
  ushort *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  longlong lVar4;
  ushort uVar5;
  int iVar6;
  char *local_res18;
  undefined8 *local_res20;
  undefined1 local_38;
  undefined6 uStack_37;
  undefined1 uStack_31;
  undefined1 uStack_30;
  undefined1 uStack_2f;
  char cStack_2e;
  undefined5 uStack_2d;
  
  lVar4 = WdfFunctions_01015;
  local_res18 = (char *)0x0;
  local_res20 = (undefined8 *)0x0;
  *param_4 = 0;
  iVar6 = (**(code **)(lVar4 + 0x868))
                    (WdfDriverGlobals,param_2,*(undefined8 *)(param_3 + 0x10),&local_res18,0);
  if (-1 < iVar6) {
    iVar6 = (**(code **)(WdfFunctions_01015 + 0x870))
                      (WdfDriverGlobals,param_2,*(undefined8 *)(param_3 + 8),&local_res20,0);
    if (-1 < iVar6) {
      ScratchBuffer_BeginUseX(param_1);
      uStack_37 = 0;
      uStack_2d = 0;
      cStack_2e = *local_res18 << 6;
      local_38 = 0xad;
      uStack_31 = 0x82;
      uStack_30 = 0;
      uStack_2f = 0x24;
      iVar6 = ScratchBuffer_ExecuteCdbEx(param_1,param_2,0x24,'\x01',(undefined8 *)&local_38,0xc,0);
      if (-1 < iVar6) {
        puVar1 = *(ushort **)(param_1 + 0x3f0);
        uVar5 = *puVar1;
        *(undefined1 *)puVar1 = *(undefined1 *)((longlong)puVar1 + 1);
        *(char *)((longlong)puVar1 + 1) = (char)uVar5;
        if ((*puVar1 < 2) || (uVar5 = *puVar1 - 2, *puVar1 = uVar5, uVar5 != 0x20)) {
          *param_4 = 0;
          iVar6 = -0x3ffffe7b;
        }
        else {
          uVar2 = *(undefined8 *)(puVar1 + 2);
          uVar3 = *(undefined8 *)(puVar1 + 6);
          *param_4 = 0x20;
          *local_res20 = uVar2;
          local_res20[1] = uVar3;
          uVar2 = *(undefined8 *)(puVar1 + 0xe);
          local_res20[2] = *(undefined8 *)(puVar1 + 10);
          local_res20[3] = uVar2;
        }
      }
      ScratchBuffer_EndUse(param_1);
    }
  }
  return iVar6;
}



===== DeviceHandleAacsReadMediaKeyBlock @ 140027c58 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int DeviceHandleAacsReadMediaKeyBlock
              (longlong param_1,undefined8 param_2,longlong param_3,ulonglong *param_4)

{
  undefined1 uVar1;
  undefined8 uVar2;
  code *pcVar3;
  ushort *puVar4;
  bool bVar5;
  bool bVar6;
  undefined8 uVar7;
  int iVar8;
  ulonglong uVar9;
  bool bVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  byte bVar14;
  undefined2 uVar15;
  bool bVar16;
  byte bVar17;
  byte local_res20;
  int *local_60;
  undefined1 *local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  
  uVar7 = WdfDriverGlobals;
  local_58 = (undefined1 *)0x0;
  local_60 = (int *)0x0;
  uVar2 = *(undefined8 *)(param_3 + 0x10);
  pcVar3 = *(code **)(WdfFunctions_01015 + 0x868);
  *param_4 = 0;
  iVar8 = (*pcVar3)(uVar7,param_2,uVar2,&local_58,0);
  if ((-1 < iVar8) &&
     (iVar8 = (**(code **)(WdfFunctions_01015 + 0x870))
                        (WdfDriverGlobals,param_2,*(undefined8 *)(param_3 + 8),&local_60,0),
     -1 < iVar8)) {
    uVar12 = 0x8004;
    if (*(int *)(param_3 + 0x18) != 0x3350c4) {
      uVar12 = 4;
    }
    if (uVar12 <= *(uint *)(param_1 + 1000)) {
      local_res20 = 0;
      bVar5 = true;
      bVar6 = true;
      ScratchBuffer_BeginUseX(param_1);
      local_50 = CONCAT17(0x83,CONCAT16(*local_58,0xad));
      uStack_48 = (ulonglong)CONCAT11((char)uVar12,(char)(uVar12 >> 8));
      bVar14 = 0;
      bVar16 = true;
LAB_140027d5f:
      local_50._0_6_ = CONCAT15(bVar14,(undefined5)local_50);
      if (bVar5) {
        iVar8 = ScratchBuffer_ExecuteCdbEx(param_1,param_2,uVar12,'\x01',&local_50,0xc,0);
      }
      iVar13 = iVar8;
      if (iVar8 < 0) {
LAB_140027f6f:
        bVar10 = false;
        if (-1 < iVar13) {
          bVar10 = bVar16;
        }
        iVar8 = iVar13;
        bVar16 = bVar10;
        if (!bVar10) {
LAB_14002803c:
          ScratchBuffer_EndUse(param_1);
          return iVar13;
        }
        goto LAB_140027d5f;
      }
      uVar9 = Feature_1596350777__private_IsEnabledDeviceUsageNoInline();
      if (((int)uVar9 == 0) || (3 < *(uint *)(*(longlong *)(param_1 + 0x408) + 0x10))) {
        puVar4 = *(ushort **)(param_1 + 0x3f0);
        if (*(char *)((longlong)puVar4 + 3) == '\0') {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar15 = 0xb;
            goto LAB_14002800f;
          }
        }
        else {
          bVar17 = *(char *)((longlong)puVar4 + 3) - 1;
          if (*(int *)(param_3 + 0x18) == 0x3350c0) {
            if (bVar17 == local_res20) {
              uVar1 = *(undefined1 *)((longlong)puVar4 + 1);
              *(char *)((longlong)puVar4 + 1) = (char)*puVar4;
              *(undefined1 *)puVar4 = uVar1;
              if (*puVar4 < 2) {
                iVar8 = -0x3ffffe7b;
                uVar9 = 0;
              }
              else {
                uVar11 = *puVar4 - 2;
                uVar9 = Feature_1596350777__private_IsEnabledDeviceUsageNoInline();
                if (((int)uVar9 != 0) && (0x8000 < uVar11)) {
                  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                    WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,9,0xc,
                                      &WPP_9bb309afef393e3146adaf4bb6d607a2_Traceguids,(char)uVar11)
                    ;
                  }
                  goto LAB_140028033;
                }
                iVar8 = 0;
                *local_60 = (uint)bVar17 * 0x8000 + uVar11;
                uVar9 = 4;
              }
              bVar6 = false;
              *param_4 = uVar9;
            }
            else {
              puVar4[0] = 0;
              puVar4[1] = 0;
              uVar12 = 4;
              ScratchBuffer_ResetItems(param_1,'\x01');
              bVar6 = true;
              local_res20 = bVar17;
            }
            bVar14 = local_res20;
            iVar13 = iVar8;
            bVar5 = bVar6;
            bVar16 = bVar6;
            goto LAB_140027f6f;
          }
          bVar14 = local_res20;
          if (*(int *)(param_3 + 0x18) != 0x3350c4) {
            bVar5 = bVar6;
            goto LAB_140027f6f;
          }
          uVar1 = *(undefined1 *)((longlong)puVar4 + 1);
          *(char *)((longlong)puVar4 + 1) = (char)*puVar4;
          *(undefined1 *)puVar4 = uVar1;
          if (*puVar4 < 2) goto LAB_140028033;
          uVar12 = *puVar4 - 2;
          uVar9 = Feature_1596350777__private_IsEnabledDeviceUsageNoInline();
          if (((int)uVar9 == 0) ||
             ((((ulonglong)uVar12 <= (ulonglong)*(uint *)(*(longlong *)(param_1 + 0x408) + 0x10) - 4
               && (uVar12 < 0x8001)) && ((local_res20 == bVar17 || (uVar12 == 0x8000)))))) {
            uVar9 = (ulonglong)((uint)local_res20 * 0x8000 + uVar12);
            if (*(ulonglong *)(param_3 + 8) < uVar9) {
              iVar13 = -0x3fffffdd;
              *param_4 = ((ulonglong)bVar17 + 1) * 0x8000;
              goto LAB_14002803c;
            }
            memmove(local_60 + (ulonglong)local_res20 * 0x2000,puVar4 + 2,(ulonglong)uVar12);
            iVar8 = 0;
            iVar13 = 0;
            *param_4 = uVar9;
            if (local_res20 == bVar17) goto LAB_14002803c;
            uVar12 = 0x8004;
            **(undefined4 **)(param_1 + 0x3f0) = 0;
            local_50._0_6_ = CONCAT15(local_res20 + 1,(undefined5)local_50);
            ScratchBuffer_ResetItems(param_1,'\0');
            bVar5 = true;
            bVar6 = true;
            bVar16 = true;
            goto LAB_140027d5f;
          }
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_Ldd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
          }
        }
      }
      else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar15 = 10;
LAB_14002800f:
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,9,uVar15,
                         &WPP_9bb309afef393e3146adaf4bb6d607a2_Traceguids);
      }
LAB_140028033:
      *param_4 = 0;
      iVar13 = -0x3ffffe7b;
      goto LAB_14002803c;
    }
    iVar8 = -0x3fffff1b;
  }
  return iVar8;
}



===== DeviceHandleAacsReadSerialNumber @ 140028068 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int DeviceHandleAacsReadSerialNumber
              (longlong param_1,undefined8 param_2,longlong param_3,undefined8 *param_4)

{
  ushort *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  longlong lVar4;
  ushort uVar5;
  int iVar6;
  char *local_res18;
  undefined8 *local_res20;
  undefined1 local_38;
  undefined6 uStack_37;
  undefined1 uStack_31;
  undefined1 uStack_30;
  undefined1 uStack_2f;
  char cStack_2e;
  undefined5 uStack_2d;
  
  lVar4 = WdfFunctions_01015;
  local_res18 = (char *)0x0;
  local_res20 = (undefined8 *)0x0;
  *param_4 = 0;
  iVar6 = (**(code **)(lVar4 + 0x868))
                    (WdfDriverGlobals,param_2,*(undefined8 *)(param_3 + 0x10),&local_res18,0);
  if (-1 < iVar6) {
    iVar6 = (**(code **)(WdfFunctions_01015 + 0x870))
                      (WdfDriverGlobals,param_2,*(undefined8 *)(param_3 + 8),&local_res20,0);
    if (-1 < iVar6) {
      ScratchBuffer_BeginUseX(param_1);
      uStack_37 = 0;
      uStack_2d = 0;
      cStack_2e = *local_res18 << 6;
      local_38 = 0xad;
      uStack_31 = 0x81;
      uStack_30 = 0;
      uStack_2f = 0x24;
      iVar6 = ScratchBuffer_ExecuteCdbEx(param_1,param_2,0x24,'\x01',(undefined8 *)&local_38,0xc,0);
      if (-1 < iVar6) {
        puVar1 = *(ushort **)(param_1 + 0x3f0);
        uVar5 = *puVar1;
        *(undefined1 *)puVar1 = *(undefined1 *)((longlong)puVar1 + 1);
        *(char *)((longlong)puVar1 + 1) = (char)uVar5;
        if ((*puVar1 < 2) || (uVar5 = *puVar1 - 2, *puVar1 = uVar5, uVar5 != 0x20)) {
          *param_4 = 0;
          iVar6 = -0x3ffffe7b;
        }
        else {
          uVar2 = *(undefined8 *)(puVar1 + 2);
          uVar3 = *(undefined8 *)(puVar1 + 6);
          *param_4 = 0x20;
          *local_res20 = uVar2;
          local_res20[1] = uVar3;
          uVar2 = *(undefined8 *)(puVar1 + 0xe);
          local_res20[2] = *(undefined8 *)(puVar1 + 10);
          local_res20[3] = uVar2;
        }
      }
      ScratchBuffer_EndUse(param_1);
    }
  }
  return iVar6;
}



===== DeviceHandleAacsSendCertificate @ 1400281cc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int DeviceHandleAacsSendCertificate
              (longlong param_1,undefined8 param_2,longlong param_3,undefined8 *param_4)

{
  undefined2 *puVar1;
  undefined8 uVar2;
  longlong lVar3;
  int iVar4;
  char *local_res18;
  undefined1 local_18;
  undefined6 uStack_17;
  undefined1 uStack_11;
  undefined1 uStack_10;
  undefined1 uStack_f;
  byte bStack_e;
  undefined5 uStack_d;
  
  lVar3 = WdfFunctions_01015;
  local_res18 = (char *)0x0;
  *param_4 = 0;
  iVar4 = (**(code **)(lVar3 + 0x868))
                    (WdfDriverGlobals,param_2,*(undefined8 *)(param_3 + 0x10),&local_res18,0);
  if (-1 < iVar4) {
    ScratchBuffer_BeginUseX(param_1);
    puVar1 = *(undefined2 **)(param_1 + 0x3f0);
    *puVar1 = 0x7200;
    uVar2 = *(undefined8 *)(local_res18 + 0xc);
    *(undefined8 *)(puVar1 + 2) = *(undefined8 *)(local_res18 + 4);
    *(undefined8 *)(puVar1 + 6) = uVar2;
    uVar2 = *(undefined8 *)(local_res18 + 0x1c);
    *(undefined8 *)(puVar1 + 10) = *(undefined8 *)(local_res18 + 0x14);
    *(undefined8 *)(puVar1 + 0xe) = uVar2;
    uVar2 = *(undefined8 *)(local_res18 + 0x2c);
    *(undefined8 *)(puVar1 + 0x12) = *(undefined8 *)(local_res18 + 0x24);
    *(undefined8 *)(puVar1 + 0x16) = uVar2;
    uVar2 = *(undefined8 *)(local_res18 + 0x3c);
    *(undefined8 *)(puVar1 + 0x1a) = *(undefined8 *)(local_res18 + 0x34);
    *(undefined8 *)(puVar1 + 0x1e) = uVar2;
    uVar2 = *(undefined8 *)(local_res18 + 0x4c);
    *(undefined8 *)(puVar1 + 0x22) = *(undefined8 *)(local_res18 + 0x44);
    *(undefined8 *)(puVar1 + 0x26) = uVar2;
    uVar2 = *(undefined8 *)(local_res18 + 0x5c);
    *(undefined8 *)(puVar1 + 0x2a) = *(undefined8 *)(local_res18 + 0x54);
    *(undefined8 *)(puVar1 + 0x2e) = uVar2;
    uVar2 = *(undefined8 *)(local_res18 + 0x6c);
    *(undefined8 *)(puVar1 + 0x32) = *(undefined8 *)(local_res18 + 100);
    *(undefined8 *)(puVar1 + 0x36) = uVar2;
    uStack_17 = 0;
    uStack_d = 0;
    local_18 = 0xa3;
    uStack_11 = 2;
    uStack_10 = 0;
    bStack_e = *local_res18 << 6 | 1;
    uStack_f = 0x74;
    iVar4 = ScratchBuffer_ExecuteCdbEx(param_1,param_2,0x74,'\0',(undefined8 *)&local_18,0xc,0);
    if (-1 < iVar4) {
      *param_4 = 0;
    }
    ScratchBuffer_EndUse(param_1);
  }
  return iVar4;
}



===== DeviceHandleAacsStartSession @ 1400282f4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int DeviceHandleAacsStartSession
              (longlong param_1,undefined8 param_2,longlong param_3,undefined8 *param_4)

{
  longlong lVar1;
  int iVar2;
  uint *local_res18;
  undefined1 local_18;
  undefined6 uStack_17;
  undefined1 uStack_11;
  undefined1 uStack_10;
  undefined1 uStack_f;
  undefined1 uStack_e;
  undefined5 uStack_d;
  
  lVar1 = WdfFunctions_01015;
  local_res18 = (uint *)0x0;
  *param_4 = 0;
  iVar2 = (**(code **)(lVar1 + 0x870))
                    (WdfDriverGlobals,param_2,*(undefined8 *)(param_3 + 8),&local_res18,0);
  if (-1 < iVar2) {
    ScratchBuffer_BeginUseX(param_1);
    uStack_17 = 0;
    uStack_d = 0;
    uStack_e = 0;
    local_18 = 0xa4;
    uStack_11 = 2;
    uStack_10 = 0;
    uStack_f = 8;
    iVar2 = ScratchBuffer_ExecuteCdbEx(param_1,param_2,8,'\x01',(undefined8 *)&local_18,0xc,0);
    if (-1 < iVar2) {
      lVar1 = *(longlong *)(param_1 + 0x3f0);
      *param_4 = 4;
      *local_res18 = (uint)(*(byte *)(lVar1 + 7) >> 6);
    }
    ScratchBuffer_EndUse(param_1);
  }
  return iVar2;
}



===== DeviceHandleReadVolumeId @ 1400283e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int DeviceHandleReadVolumeId
              (longlong param_1,undefined8 param_2,longlong param_3,undefined8 *param_4)

{
  ushort *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  longlong lVar4;
  ushort uVar5;
  int iVar6;
  char *local_res18;
  undefined8 *local_res20;
  undefined1 local_38;
  undefined6 uStack_37;
  undefined1 uStack_31;
  undefined1 uStack_30;
  undefined1 uStack_2f;
  char cStack_2e;
  undefined5 uStack_2d;
  
  lVar4 = WdfFunctions_01015;
  local_res18 = (char *)0x0;
  local_res20 = (undefined8 *)0x0;
  *param_4 = 0;
  iVar6 = (**(code **)(lVar4 + 0x868))
                    (WdfDriverGlobals,param_2,*(undefined8 *)(param_3 + 0x10),&local_res18,0);
  if (-1 < iVar6) {
    iVar6 = (**(code **)(WdfFunctions_01015 + 0x870))
                      (WdfDriverGlobals,param_2,*(undefined8 *)(param_3 + 8),&local_res20,0);
    if (-1 < iVar6) {
      ScratchBuffer_BeginUseX(param_1);
      uStack_37 = 0;
      uStack_2d = 0;
      cStack_2e = *local_res18 << 6;
      local_38 = 0xad;
      uStack_31 = 0x80;
      uStack_30 = 0;
      uStack_2f = 0x24;
      iVar6 = ScratchBuffer_ExecuteCdbEx(param_1,param_2,0x24,'\x01',(undefined8 *)&local_38,0xc,0);
      if (-1 < iVar6) {
        puVar1 = *(ushort **)(param_1 + 0x3f0);
        uVar5 = *puVar1;
        *(undefined1 *)puVar1 = *(undefined1 *)((longlong)puVar1 + 1);
        *(char *)((longlong)puVar1 + 1) = (char)uVar5;
        if ((*puVar1 < 2) || (uVar5 = *puVar1 - 2, *puVar1 = uVar5, uVar5 != 0x20)) {
          *param_4 = 0;
          iVar6 = -0x3ffffe7b;
        }
        else {
          uVar2 = *(undefined8 *)(puVar1 + 2);
          uVar3 = *(undefined8 *)(puVar1 + 6);
          *param_4 = 0x20;
          *local_res20 = uVar2;
          local_res20[1] = uVar3;
          uVar2 = *(undefined8 *)(puVar1 + 0xe);
          local_res20[2] = *(undefined8 *)(puVar1 + 10);
          local_res20[3] = uVar2;
        }
      }
      ScratchBuffer_EndUse(param_1);
    }
  }
  return iVar6;
}



===== DeviceHandleSendChallengeKey @ 140028544 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int DeviceHandleSendChallengeKey
              (longlong param_1,undefined8 param_2,longlong param_3,undefined8 *param_4)

{
  undefined2 *puVar1;
  undefined8 uVar2;
  longlong lVar3;
  int iVar4;
  char *local_res18;
  undefined1 local_18;
  undefined6 uStack_17;
  undefined1 uStack_11;
  undefined1 uStack_10;
  undefined1 uStack_f;
  byte bStack_e;
  undefined5 uStack_d;
  
  lVar3 = WdfFunctions_01015;
  local_res18 = (char *)0x0;
  *param_4 = 0;
  iVar4 = (**(code **)(lVar3 + 0x868))
                    (WdfDriverGlobals,param_2,*(undefined8 *)(param_3 + 0x10),&local_res18,0);
  if (-1 < iVar4) {
    ScratchBuffer_BeginUseX(param_1);
    puVar1 = *(undefined2 **)(param_1 + 0x3f0);
    *puVar1 = 0x5200;
    uVar2 = *(undefined8 *)(local_res18 + 0xc);
    *(undefined8 *)(puVar1 + 2) = *(undefined8 *)(local_res18 + 4);
    *(undefined8 *)(puVar1 + 6) = uVar2;
    uVar2 = *(undefined8 *)(local_res18 + 0x1c);
    *(undefined8 *)(puVar1 + 10) = *(undefined8 *)(local_res18 + 0x14);
    *(undefined8 *)(puVar1 + 0xe) = uVar2;
    uVar2 = *(undefined8 *)(local_res18 + 0x2c);
    *(undefined8 *)(puVar1 + 0x12) = *(undefined8 *)(local_res18 + 0x24);
    *(undefined8 *)(puVar1 + 0x16) = uVar2;
    uVar2 = *(undefined8 *)(local_res18 + 0x3c);
    *(undefined8 *)(puVar1 + 0x1a) = *(undefined8 *)(local_res18 + 0x34);
    *(undefined8 *)(puVar1 + 0x1e) = uVar2;
    uVar2 = *(undefined8 *)(local_res18 + 0x4c);
    *(undefined8 *)(puVar1 + 0x22) = *(undefined8 *)(local_res18 + 0x44);
    *(undefined8 *)(puVar1 + 0x26) = uVar2;
    uStack_17 = 0;
    uStack_d = 0;
    local_18 = 0xa3;
    uStack_11 = 2;
    uStack_10 = 0;
    bStack_e = *local_res18 << 6 | 2;
    uStack_f = 0x54;
    iVar4 = ScratchBuffer_ExecuteCdbEx(param_1,param_2,0x54,'\0',(undefined8 *)&local_18,0xc,0);
    if (-1 < iVar4) {
      *param_4 = 0;
    }
    ScratchBuffer_EndUse(param_1);
  }
  return iVar4;
}



===== DeviceGetZPODDEnabledFromRegistry @ 14002865c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 DeviceGetZPODDEnabledFromRegistry(void)

{
  int iVar1;
  undefined1 auStack_88 [32];
  undefined8 *local_68;
  undefined4 local_58 [2];
  undefined8 local_50;
  undefined8 local_48;
  wchar_t *local_40;
  wchar_t local_38 [20];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_88;
  local_50 = 0;
  local_68 = &local_50;
  local_58[0] = 0;
  local_40 = local_38;
  builtin_wcsncpy(local_38,L"ZeroPowerODDEnab",0x10);
  local_48 = 0x280026;
  builtin_wcsncpy(local_38 + 0x10,L"led",4);
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x3b8))(WdfDriverGlobals,*WdfDriverGlobals,0x20019,0);
  if (-1 < iVar1) {
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x780))(WdfDriverGlobals,local_50,&local_48,local_58);
    (**(code **)(WdfFunctions_01015 + 0x738))(WdfDriverGlobals,local_50);
    if (-1 < iVar1) {
      return local_58[0];
    }
  }
  return 1;
}



===== DeviceInitializeZPODD @ 140028760 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 DeviceInitializeZPODD(longlong param_1)

{
  byte bVar1;
  longlong lVar2;
  int iVar3;
  byte *pbVar4;
  undefined1 *puVar5;
  undefined8 uVar6;
  byte bVar7;
  undefined8 uVar8;
  int *piVar9;
  undefined2 uVar10;
  int local_res8 [2];
  
  pbVar4 = (byte *)0x0;
  local_res8[0] = 0;
  if (*(longlong *)(param_1 + 0x120) != 0) {
    return 0;
  }
  iVar3 = DeviceGetZPODDEnabledFromRegistry();
  if (iVar3 == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140028a24;
    uVar10 = 10;
  }
  else {
    pbVar4 = (byte *)ExAllocatePool2(0x40);
    if (pbVar4 == (byte *)0x0) goto LAB_140028a24;
    lVar2 = *(longlong *)(param_1 + 0xd8);
    if (((lVar2 == 0) || (*(char *)(lVar2 + 8) == '\0')) || (*(char *)(lVar2 + 9) == '\0')) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140028a24;
      uVar10 = 0xb;
    }
    else {
      puVar5 = DeviceFindFeaturePage(*(undefined1 **)(param_1 + 800),*(uint *)(param_1 + 0x328),3);
      if (puVar5 != (undefined1 *)0x0) {
        bVar1 = puVar5[4];
        bVar7 = bVar1 >> 5;
        if (((bVar7 == 1) && ((bVar1 & 0x12) == 2)) ||
           ((bVar7 == 0 &&
            (((bVar1 & 0x10) == 0 && (*(char *)(*(longlong *)(param_1 + 0x118) + 0x58) != '\0'))))))
        {
          *pbVar4 = bVar7;
          pbVar4[1] = (byte)puVar5[4] >> 4 & 1;
          iVar3 = DeviceQueryD3ColdInterface(param_1,pbVar4 + 8);
          if (iVar3 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
            goto LAB_140028a24;
            uVar10 = 0xd;
          }
          else {
            piVar9 = local_res8;
            uVar8 = 0;
            iVar3 = (**(code **)(pbVar4 + 0x30))(*(undefined8 *)(pbVar4 + 0x10));
            if (iVar3 < 0) goto LAB_140028a24;
            if ((local_res8[0] == 5) && (*(char *)(*(longlong *)(param_1 + 0xd8) + 0xc) != '\0')) {
              pbVar4[0x6c] = 5;
              pbVar4[0x6d] = 0;
              pbVar4[0x6e] = 0;
              pbVar4[0x6f] = 0;
              uVar8 = CONCAT71((int7)((ulonglong)uVar8 >> 8),1);
              iVar3 = DeviceSendEnableIdlePowerIoctl
                                (param_1,(uint)uVar8,
                                 (uint)CONCAT71((int7)((ulonglong)piVar9 >> 8),1),60000);
              if (-1 < iVar3) {
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  uVar8 = CONCAT71((int7)((ulonglong)uVar8 >> 8),4);
                  WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,3,0x10,
                                   &WPP_af14ec63502f3054fdb449d0dcf290f5_Traceguids);
                }
                *(byte **)(param_1 + 0x120) = pbVar4;
                uVar6 = DeviceZPODDIsInHomePosition(param_1);
                if ((char)uVar6 != '\0') {
                  if (*(longlong *)(pbVar4 + 0x60) == 0) {
                    DeviceGetConfigurationWithAlloc
                              (*(undefined8 *)(param_1 + 0x10),(undefined8 *)(pbVar4 + 0x60),
                               (uint *)(pbVar4 + 0x68));
                    return 0;
                  }
                  return 0;
                }
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  uVar8 = CONCAT71((int7)((ulonglong)uVar8 >> 8),4);
                  WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,3,0x11,
                                   &WPP_af14ec63502f3054fdb449d0dcf290f5_Traceguids);
                }
                DeviceMarkActive(param_1,(longlong *)CONCAT71((int7)((ulonglong)uVar8 >> 8),1),
                                 (uint *)0x0);
                return 0;
              }
              if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
              goto LAB_140028a24;
              uVar10 = 0xf;
            }
            else {
              if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
              goto LAB_140028a24;
              uVar10 = 0xe;
            }
          }
          goto LAB_140028a06;
        }
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140028a24;
      uVar10 = 0xc;
    }
  }
LAB_140028a06:
  WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,3,uVar10,
                   &WPP_af14ec63502f3054fdb449d0dcf290f5_Traceguids);
LAB_140028a24:
  uVar8 = 0;
  iVar3 = DeviceSendEnableIdlePowerIoctl(param_1,0,0,60000);
  if (-1 < iVar3) {
    DeviceMarkActive(param_1,(longlong *)CONCAT71((int7)((ulonglong)uVar8 >> 8),1),(uint *)0x0);
  }
  if (pbVar4 != (byte *)0x0) {
    ExFreePoolWithTag(pbVar4,0);
  }
  return 0;
}



===== DeviceMarkActive @ 140028a7c =====

void DeviceMarkActive(longlong param_1,longlong *param_2,uint *param_3)

{
  longlong lVar1;
  char cVar2;
  int iVar3;
  char cVar4;
  uint uVar5;
  
  cVar2 = (char)param_3;
  lVar1 = *(longlong *)(param_1 + 0x120);
  cVar4 = (char)param_2;
  if (*(char *)(param_1 + 9) == cVar4) {
    return;
  }
  if (((cVar4 == '\0') && (lVar1 != 0)) && (param_2 = (longlong *)(lVar1 + 0x60), *param_2 == 0)) {
    param_3 = (uint *)(lVar1 + 0x68);
    DeviceGetConfigurationWithAlloc(*(undefined8 *)(param_1 + 0x10),param_2,param_3);
  }
  if (cVar2 != '\0') {
    if ((lVar1 == 0) || (*(int *)(lVar1 + 0x6c) == 0)) {
      uVar5 = (int)((ulonglong)param_2 >> 8) << 8;
    }
    else {
      uVar5 = (uint)CONCAT71((int7)((ulonglong)param_2 >> 8),1);
    }
    iVar3 = DeviceSendEnableIdlePowerIoctl
                      (param_1,uVar5,(uint)CONCAT71((int7)((ulonglong)param_3 >> 8),lVar1 != 0),
                       (-(uint)(cVar4 != '\0') & 50000) + 10000);
    if (iVar3 < 0) goto LAB_140028b20;
  }
  DeviceSendIoctlAsynchronously
            (param_1,(-(uint)(cVar4 != '\0') & 0xfffffffc) + 0x2d1c8c,
             *(undefined8 *)(param_1 + 0x48));
LAB_140028b20:
  *(char *)(param_1 + 9) = cVar4;
  return;
}



===== DeviceQueryD3ColdInterface @ 140028b40 =====

int DeviceQueryD3ColdInterface(longlong param_1,void *param_2)

{
  longlong lVar1;
  int iVar2;
  undefined8 uVar3;
  longlong lVar4;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  local_38 = 0;
  uStack_30 = 0;
  memset(param_2,0,0x48);
  KeInitializeEvent(&local_28,0,0);
  uVar3 = IoGetAttachedDeviceReference(*(undefined8 *)(param_1 + 0x40));
  lVar4 = IoBuildSynchronousFsdRequest(0x1b,uVar3,0,0,0,&local_28,&local_38);
  if (lVar4 == 0) {
    iVar2 = -0x3fffff66;
  }
  else {
    *(undefined8 *)(lVar4 + 0x38) = 0;
    *(undefined4 *)(lVar4 + 0x30) = 0xc00000bb;
    lVar1 = *(longlong *)(lVar4 + 0xb8);
    *(undefined8 *)(lVar1 + -0x28) = 0;
    *(undefined **)(lVar1 + -0x40) = &GUID_D3COLD_SUPPORT_INTERFACE;
    *(undefined1 *)(lVar1 + -0x47) = 8;
    *(undefined4 *)(lVar1 + -0x38) = 0x10048;
    *(void **)(lVar1 + -0x30) = param_2;
    iVar2 = IofCallDriver(uVar3,lVar4);
    if (iVar2 == 0x103) {
      KeWaitForSingleObject(&local_28,0,0,0,0);
      iVar2 = (int)local_38;
    }
  }
  ObfDereferenceObject(uVar3);
  return iVar2;
}



===== DeviceZPODDIsInHomePosition @ 140028c84 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 DeviceZPODDIsInHomePosition(longlong param_1)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  undefined4 extraout_var;
  undefined1 uVar4;
  undefined1 auStackY_a8 [32];
  undefined2 local_78 [5];
  undefined1 local_6e;
  undefined4 local_64;
  undefined1 local_30;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  pcVar2 = *(char **)(param_1 + 0x120);
  uVar4 = 0;
  if (pcVar2 != (char *)0x0) {
    pcVar2[0x58] = '\0';
    pcVar2[0x59] = '\0';
    pcVar2[0x5a] = '\0';
    memset(local_78,0,0x58);
    local_6e = 6;
    local_30 = 0;
    local_64 = 0x14;
    iVar3 = DeviceSendSrbSynchronously(*(undefined8 *)(param_1 + 0x10),local_78,0,0,'\0',0);
    cVar1 = *pcVar2;
    local_18 = CONCAT71((int7)(CONCAT44(extraout_var,iVar3) >> 8),cVar1);
    if (cVar1 == '\x01') {
      if (((pcVar2[1] != '\0') || (pcVar2[0x58] != '\x02')) ||
         ((pcVar2[0x59] != ':' || (pcVar2[0x5a] != '\x01')))) goto LAB_140028d3d;
    }
    else if ((((cVar1 != '\0') || (pcVar2[1] != '\0')) || (pcVar2[0x58] != '\x02')) ||
            (pcVar2[0x59] != ':')) goto LAB_140028d3d;
    uVar4 = 1;
  }
LAB_140028d3d:
  return CONCAT71((int7)(local_18 >> 8),uVar4);
}



===== ScratchBuffer_SetupSrb @ 140028d70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ScratchBuffer_SetupSrb(longlong param_1,undefined8 param_2,uint param_3,char param_4)

{
  undefined8 uVar1;
  undefined4 *puVar2;
  longlong lVar3;
  longlong lVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  
  uVar1 = *(undefined8 *)(param_1 + 0x400);
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals,uVar1);
  puVar2 = *(undefined4 **)(param_1 + 0x408);
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar1,PTR__WDF_CDROM_REQUEST_CONTEXT_TYPE_INFO_14001a018);
  *(undefined8 *)(lVar4 + 8) = param_2;
  lVar4 = *(longlong *)(lVar3 + 0xb8);
  *(undefined1 *)(lVar4 + -0x48) = 0xf;
  if (param_3 == 0) {
    *(undefined4 *)(lVar4 + -0x30) = 0x1b0013;
    *(undefined4 **)(lVar4 + -0x40) = puVar2;
  }
  else {
    uVar7 = 0x1b0011;
    if (param_4 == '\0') {
      uVar7 = 0x1b0012;
    }
    *(undefined4 *)(lVar4 + -0x30) = uVar7;
    *(undefined4 **)(lVar4 + -0x40) = puVar2;
    *(undefined8 *)(lVar3 + 8) = *(undefined8 *)(param_1 + 0x3f8);
    *(undefined8 *)(puVar2 + 6) = *(undefined8 *)(param_1 + 0x3f0);
  }
  *puVar2 = 0x58;
  *(undefined1 *)((longlong)puVar2 + 9) = 0x20;
  *(undefined1 *)(puVar2 + 1) = 0;
  *(undefined8 *)(puVar2 + 10) = 0;
  *(longlong *)(puVar2 + 0xc) = lVar3;
  *(undefined1 *)((longlong)puVar2 + 0xb) = 0x12;
  *(undefined8 *)(puVar2 + 8) = *(undefined8 *)(param_1 + 0x410);
  *(undefined1 *)((longlong)puVar2 + 10) = 0x10;
  uVar5 = param_3;
  if (*(uint *)(param_1 + 1000) < param_3) {
    uVar5 = *(uint *)(param_1 + 1000);
  }
  puVar2[4] = uVar5;
  puVar2[5] = *(undefined4 *)(param_1 + 0x78);
  uVar5 = *(uint *)(param_1 + 0x74);
  if (param_3 == 0) {
    puVar2[3] = uVar5 | 0x108;
  }
  else {
    uVar6 = uVar5 | 0x188;
    if (param_4 != '\0') {
      uVar6 = uVar5 | 0x148;
    }
    puVar2[3] = uVar6;
  }
  return;
}



===== DeviceHandleRawRead @ 140028ee0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int DeviceHandleRawRead(longlong param_1,undefined8 param_2,longlong param_3,ulonglong *param_4)

{
  longlong lVar1;
  undefined4 *puVar2;
  int iVar3;
  byte bVar4;
  char cVar5;
  longlong lVar6;
  longlong lVar7;
  undefined2 uVar8;
  ulonglong uVar9;
  uint uVar10;
  ulonglong uVar11;
  int local_res8 [2];
  undefined8 local_res10;
  uint local_res20;
  longlong local_68 [3];
  undefined4 local_50;
  undefined4 uStack_4c;
  int iStack_48;
  int iStack_44;
  
  local_res8[0] = 0;
  uVar9 = 0;
  local_res10 = param_2;
  lVar6 = (**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals);
  lVar1 = *(longlong *)(param_1 + 0x40);
  *param_4 = 0;
  lVar7 = *(longlong *)(lVar6 + 0xb8);
  local_68[1] = 0;
  if ((((*(uint *)(lVar1 + 0x30) & 2) != 0) && (*(char *)(lVar7 + 1) != '4')) &&
     ((*(byte *)(lVar7 + 2) & 2) == 0)) {
    MediaReadCapacity(*(undefined8 *)(param_1 + 0x10));
    *param_4 = 0;
    local_res8[0] = -0x7fffffea;
  }
  if (local_res8[0] < 0) {
    return local_res8[0];
  }
  puVar2 = *(undefined4 **)(lVar7 + 0x20);
  local_50 = *puVar2;
  uStack_4c = puVar2[1];
  iStack_48 = puVar2[2];
  iStack_44 = puVar2[3];
  if ((*(int *)(lVar7 + 8) == 0) ||
     (uVar9 = (ulonglong)*(uint *)(*(longlong *)(lVar6 + 8) + 0x2c) +
              *(longlong *)(*(longlong *)(lVar6 + 8) + 0x20),
     (uVar9 & *(uint *)(*(longlong *)(param_1 + 0xd0) + 0x10)) != 0)) {
    local_res8[0] = -0x3ffffff3;
  }
  if (local_res8[0] < 0) {
    return local_res8[0];
  }
  local_res8[0] =
       (**(code **)(WdfFunctions_01015 + 0x870))
                 (WdfDriverGlobals,param_2,*(undefined8 *)(param_3 + 8),local_68 + 1,0);
  if (local_res8[0] < 0) {
    return local_res8[0];
  }
  if (((iStack_44 == 0) || (iStack_44 == 1)) || (iStack_44 == 2)) goto LAB_140029097;
  if (iStack_44 == 3) {
    if ((*(char *)(param_1 + 0x338) != '\0') && (*(char *)(param_1 + 0x339) != '\0'))
    goto LAB_140029097;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x41,
                         &WPP_7cea3eca420c34d4f6f4315c54c616a1_Traceguids,*(char *)(param_1 + 0x338)
                         ,*(char *)(param_1 + 0x339));
    }
LAB_140029172:
    *param_4 = 0;
    local_res8[0] = -0x3ffffff0;
  }
  else {
    if (iStack_44 == 4) {
      if (*(char *)(param_1 + 0x338) == '\0') {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar8 = 0x42;
LAB_14002905e:
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,uVar8,
                           &WPP_7cea3eca420c34d4f6f4315c54c616a1_Traceguids);
        }
LAB_140029082:
        *param_4 = 0;
        local_res8[0] = -0x3ffffff0;
      }
    }
    else {
      if (iStack_44 != 5) goto LAB_140029172;
      if (*(char *)(param_1 + 0x339) == '\0') {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar8 = 0x43;
          goto LAB_14002905e;
        }
        goto LAB_140029082;
      }
    }
    if (-1 < local_res8[0]) {
LAB_140029097:
      lVar1 = *(longlong *)(param_1 + 0x408);
      local_res20 = 0;
      local_68[0] = 0;
      uVar11 = *(ulonglong *)(param_3 + 8);
      ScratchBuffer_BeginUseX(param_1);
      iVar3 = iStack_48;
      do {
        if (iStack_44 == 0) {
          uVar10 = iVar3 * 0x930;
          *(byte *)(lVar1 + 0x49) = *(byte *)(lVar1 + 0x49) & 0xef | 0xc;
          bVar4 = *(byte *)(lVar1 + 0x51) & 0xf | 0xb0;
LAB_1400291f3:
          uVar11 = (ulonglong)uVar10;
          *(byte *)(lVar1 + 0x51) = bVar4;
        }
        else {
          if (iStack_44 == 1) {
            bVar4 = *(byte *)(lVar1 + 0x49) & 0xf7 | 0x14;
          }
          else {
            if (iStack_44 != 2) {
              if (iStack_44 == 3) {
                *(byte *)(lVar1 + 0x49) = *(byte *)(lVar1 + 0x49) & 0xe3;
                uVar10 = iVar3 * 0xab8;
                *(byte *)(lVar1 + 0x51) = *(byte *)(lVar1 + 0x51) & 0xfd | 0xf4;
              }
              else {
                if (iStack_44 == 4) {
                  *(byte *)(lVar1 + 0x49) = *(byte *)(lVar1 + 0x49) & 0xe3;
                  uVar10 = iVar3 * 0xa58;
                  bVar4 = *(byte *)(lVar1 + 0x51) & 0xfd | 0xf4;
                  goto LAB_1400291f3;
                }
                if (iStack_44 != 5) goto LAB_1400291f6;
                *(byte *)(lVar1 + 0x49) = *(byte *)(lVar1 + 0x49) & 0xe3;
                uVar10 = iVar3 * 0x990;
                *(byte *)(lVar1 + 0x51) = *(byte *)(lVar1 + 0x51) | 0xf0;
              }
              uVar11 = (ulonglong)uVar10;
              *(byte *)(lVar1 + 0x52) = *(byte *)(lVar1 + 0x52) & 0xf9 | 1;
              goto LAB_1400291f6;
            }
            bVar4 = *(byte *)(lVar1 + 0x49) & 0xe7 | 4;
          }
          uVar11 = (ulonglong)(uint)(iVar3 * 0x930);
          *(byte *)(lVar1 + 0x51) = *(byte *)(lVar1 + 0x51) | 0xf0;
          *(byte *)(lVar1 + 0x49) = bVar4;
        }
LAB_1400291f6:
        ScratchBuffer_SetupSrb(param_1,local_res10,(uint)uVar11,'\x01');
        lVar7 = (**(code **)(WdfFunctions_01015 + 0x8e8))
                          (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x400));
        *(undefined8 *)(lVar7 + 8) = *(undefined8 *)(lVar6 + 8);
        *(ulonglong *)(lVar1 + 0x18) = uVar9;
        *(uint *)(lVar1 + 0x10) = (uint)uVar11;
        bVar4 = *(byte *)(param_1 + 0xa0);
        *(undefined1 *)(lVar1 + 10) = 0xc;
        lVar7 = CONCAT44(uStack_4c,local_50) >> (bVar4 & 0x3f);
        *(char *)(lVar1 + 0x4f) = (char)((uint)iVar3 >> 8);
        *(char *)(lVar1 + 0x4e) = (char)((uint)iVar3 >> 0x10);
        *(char *)(lVar1 + 0x4c) = (char)((ulonglong)lVar7 >> 8);
        *(char *)(lVar1 + 0x4d) = (char)lVar7;
        *(char *)(lVar1 + 0x4a) = (char)((ulonglong)lVar7 >> 0x18);
        *(undefined1 *)(lVar1 + 0x48) = 0xbe;
        *(char *)(lVar1 + 0x50) = (char)iVar3;
        *(char *)(lVar1 + 0x4b) = (char)((ulonglong)lVar7 >> 0x10);
        ScratchBuffer_SendSrb(param_1,'\x01',(undefined8 *)0x0);
        if ((*(char *)(*(longlong *)(param_1 + 0x408) + 3) == '\x02') &&
           (*(int *)(*(longlong *)(param_1 + 0x408) + 0x40) == -0x3ffffee0)) {
          local_res8[0] = -0x3ffffee0;
          goto LAB_1400292fb;
        }
        cVar5 = RequestSenseInfoInterpretForScratchBuffer
                          (param_1,local_res20,(undefined **)local_res8,local_68);
        if (cVar5 == '\0') {
          if (-1 < local_res8[0]) {
            *param_4 = (ulonglong)*(uint *)(lVar1 + 0x10);
          }
LAB_1400292fb:
          ScratchBuffer_EndUse(param_1);
          return local_res8[0];
        }
        local_res20 = local_res20 + 1;
        local_68[2] = -local_68[0];
        KeDelayExecutionThread(0,0,local_68 + 2);
        ScratchBuffer_ResetItems(param_1,'\0');
      } while( true );
    }
  }
  return local_res8[0];
}



===== DeviceUpdateMmcWriteCapability @ 140029324 =====

void DeviceUpdateMmcWriteCapability
               (undefined1 *param_1,uint param_2,char param_3,undefined1 *param_4,
               undefined4 *param_5,uint *param_6)

{
  byte bVar1;
  bool bVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  char *pcVar6;
  ulonglong uVar7;
  undefined1 uVar8;
  ulonglong uVar9;
  undefined2 uVar10;
  undefined1 uVar11;
  
  *param_4 = 0;
  *param_5 = 0;
  *param_6 = 1;
  puVar4 = MmcDataFindFeaturePage(param_1,param_2,0x24);
  puVar5 = MmcDataFindFeaturePage(param_1,param_2,0x20);
  if ((puVar4 != (undefined1 *)0x0) && (puVar5 != (undefined1 *)0x0)) {
    if (param_3 == '\0') {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,9,0xe,
                         &WPP_d8e52d07227d39443b0054e092747dea_Traceguids);
      }
      goto LAB_1400295fa;
    }
    if (((puVar4[2] & 1) != 0) && ((puVar5[2] & 1) != 0)) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,9,0xf,
                         &WPP_d8e52d07227d39443b0054e092747dea_Traceguids);
      }
      *param_4 = 1;
      *param_5 = 0x24;
      return;
    }
  }
  puVar4 = MmcDataFindFeaturePage(param_1,param_2,0x10);
  if (((puVar4 != (undefined1 *)0x0) && ((puVar4[2] & 1) != 0)) && (5 < (byte)puVar4[3])) {
    *param_6 = (uint)CONCAT11(puVar4[8],puVar4[9]);
  }
  for (uVar7 = 0; (uint)uVar7 < 4; uVar7 = (ulonglong)((uint)uVar7 + 1)) {
    puVar4 = MmcDataFindFeaturePage(param_1,param_2,(&DAT_140016c50)[uVar7 * 2]);
    if (puVar4 != (undefined1 *)0x0) {
      if (param_3 == '\0') {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400295fa;
        uVar10 = 0x10;
        uVar11 = (undefined1)(&DAT_140016c50)[uVar7 * 2];
        goto LAB_1400295d6;
      }
      if ((puVar4[2] & 1) != 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,9,0x11,
                            &WPP_d8e52d07227d39443b0054e092747dea_Traceguids,
                            (char)(&DAT_140016c50)[uVar7 * 2]);
        }
        *param_4 = 1;
        uVar3 = (&DAT_140016c54)[uVar7 * 2];
        goto LAB_140029797;
      }
    }
  }
  uVar11 = 0x2b;
  uVar8 = 0x2b;
  puVar4 = MmcDataFindFeaturePage(param_1,param_2,0x2b);
  if (((puVar4 == (undefined1 *)0x0) || (puVar4[3] == '\0')) || ((puVar4[4] & 1) == 0)) {
LAB_14002958a:
    uVar11 = 0x3b;
    uVar8 = 0x3b;
    puVar4 = MmcDataFindFeaturePage(param_1,param_2,0x3b);
    if (((puVar4 == (undefined1 *)0x0) || (puVar4[3] == '\0')) || ((puVar4[4] & 1) == 0)) {
LAB_140029658:
      puVar4 = MmcDataFindFeaturePage(param_1,param_2,0);
      if (puVar4 == (undefined1 *)0x0) {
        return;
      }
      if ((puVar4[2] & 1) == 0) {
        return;
      }
      if (param_1 + param_2 < puVar4 + (ulonglong)(byte)puVar4[3] + 4) {
        return;
      }
      uVar7 = 0;
      do {
        if (3 < (uint)uVar7) {
          return;
        }
        bVar2 = false;
        bVar1 = puVar4[3];
        if ((bVar1 & 1) == 0) {
          if (bVar1 >> 2 != 0) {
            uVar9 = (ulonglong)(bVar1 >> 2);
            puVar5 = puVar4;
            do {
              if (((uint)CONCAT11(puVar5[4],puVar5[5]) == (&DAT_140016c70)[uVar7 * 2]) &&
                 (((puVar5[6] & 1) != 0 || (param_3 == '\0')))) {
                bVar2 = true;
              }
              uVar9 = uVar9 - 1;
              puVar5 = puVar5 + 4;
            } while (uVar9 != 0);
            if (bVar2) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                pcVar6 = "*allowed*";
                if (param_3 == '\0') {
                  pcVar6 = "supported";
                }
                WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,9,0x16,
                                   &WPP_d8e52d07227d39443b0054e092747dea_Traceguids,pcVar6,0x2b);
              }
              *param_4 = 1;
              uVar3 = *(undefined4 *)(&UNK_140016c74 + uVar7 * 8);
LAB_140029797:
              *param_5 = uVar3;
              return;
            }
          }
        }
        else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,1,0x18,
                            &WPP_d8e52d07227d39443b0054e092747dea_Traceguids,bVar1);
        }
        uVar7 = (ulonglong)((uint)uVar7 + 1);
      } while( true );
    }
    if (param_3 != '\0') {
      if ((puVar4[2] & 1) == 0) goto LAB_140029658;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140029647;
      uVar10 = 0x15;
      goto LAB_14002961f;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400295fa;
    uVar10 = 0x14;
  }
  else {
    if (param_3 != '\0') {
      if ((puVar4[2] & 1) == 0) goto LAB_14002958a;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140029647;
      uVar10 = 0x13;
LAB_14002961f:
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,9,uVar10,
                        &WPP_d8e52d07227d39443b0054e092747dea_Traceguids,uVar8);
LAB_140029647:
      *param_4 = 1;
      *param_5 = 0x21;
      return;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400295fa;
    uVar10 = 0x12;
  }
LAB_1400295d6:
  WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,9,uVar10,
                    &WPP_d8e52d07227d39443b0054e092747dea_Traceguids,uVar11);
LAB_1400295fa:
  *param_4 = 1;
  return;
}



===== DeviceRetryTimeGuessBasedOnProfile @ 1400297c0 =====

undefined8 DeviceRetryTimeGuessBasedOnProfile(int param_1)

{
  if (param_1 < 0x41) {
    if (param_1 != 0x40) {
      if (param_1 < 0x16) {
        if (param_1 != 0x15) {
          if (((param_1 == 8) || (param_1 == 9)) || (param_1 == 10)) {
            return 0x1046ab;
          }
          if (((param_1 != 0x10) && (param_1 != 0x11)) &&
             ((param_1 != 0x12 && ((param_1 != 0x13 && (param_1 != 0x14)))))) {
            return 0xffffffffffffffff;
          }
        }
      }
      else if (((param_1 != 0x16) && (param_1 != 0x1a)) && (param_1 != 0x1b)) {
        if (param_1 == 0x20) {
          return 0x1046ab;
        }
        if (param_1 == 0x21) {
          return 0x1046ab;
        }
        if (param_1 == 0x22) {
          return 0x1046ab;
        }
        if ((param_1 != 0x2a) && (param_1 != 0x2b)) {
          return 0xffffffffffffffff;
        }
      }
      return 0x7391d;
    }
  }
  else if (((((param_1 != 0x41) && (param_1 != 0x42)) && (param_1 != 0x43)) &&
           ((param_1 != 0x50 && (param_1 != 0x51)))) && (param_1 != 0x52)) {
    return 0xffffffffffffffff;
  }
  return 0x2308a;
}



===== DeviceRetryTimeDetectionBasedOnGetPerformance @ 140029864 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong DeviceRetryTimeDetectionBasedOnGetPerformance(longlong param_1,char param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined4 *puVar3;
  longlong lVar4;
  char cVar5;
  int iVar6;
  longlong lVar7;
  longlong lVar8;
  uint uVar9;
  ulonglong uVar10;
  undefined1 *puVar11;
  uint uVar12;
  uint uVar13;
  ulonglong uVar14;
  bool bVar15;
  int local_res8 [2];
  char local_res10;
  uint local_res18;
  longlong local_res20;
  longlong local_70;
  undefined8 uStack_68;
  
  uVar10 = (ulonglong)*(uint *)(param_1 + 1000) - 8 >> 4;
  uVar14 = 0xffffffffffffffff;
  iVar6 = (int)uVar10;
  if (200 < uVar10) {
    iVar6 = 200;
  }
  uVar13 = 0;
  local_res18 = iVar6 * 0x10 + 8;
  local_res10 = param_2;
  ScratchBuffer_BeginUseX(param_1);
  local_70 = 0xac;
  if (param_2 == '\0') {
    uStack_68._0_3_ = CONCAT12(3,(ushort)(byte)iVar6 << 8);
  }
  else {
    uStack_68._0_3_ = (uint3)(byte)iVar6 << 8;
    local_70 = 0x14ac;
  }
  lVar4 = local_70;
  uStack_68 = (ulonglong)(uint3)uStack_68;
  uVar10 = uStack_68;
  lVar1 = *(longlong *)(param_1 + 0x408);
  uVar12 = 0;
  local_res8[0] = 0;
  local_res20 = 0;
  while( true ) {
    uVar2 = *(undefined8 *)(param_1 + 0x400);
    lVar7 = (**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals,uVar2);
    puVar3 = *(undefined4 **)(param_1 + 0x408);
    lVar8 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,uVar2);
    *(undefined8 *)(lVar8 + 8) = 0;
    lVar8 = *(longlong *)(lVar7 + 0xb8);
    *(undefined1 *)(lVar8 + -0x48) = 0xf;
    *(undefined4 *)(lVar8 + -0x30) = 0x1b0011;
    *(undefined4 **)(lVar8 + -0x40) = puVar3;
    *(undefined8 *)(lVar7 + 8) = *(undefined8 *)(param_1 + 0x3f8);
    *(undefined8 *)(puVar3 + 6) = *(undefined8 *)(param_1 + 0x3f0);
    *puVar3 = 0x58;
    *(undefined1 *)((longlong)puVar3 + 9) = 0x20;
    *(undefined1 *)(puVar3 + 1) = 0;
    *(undefined8 *)(puVar3 + 10) = 0;
    *(longlong *)(puVar3 + 0xc) = lVar7;
    *(undefined1 *)((longlong)puVar3 + 0xb) = 0x12;
    *(undefined8 *)(puVar3 + 8) = *(undefined8 *)(param_1 + 0x410);
    *(undefined1 *)((longlong)puVar3 + 10) = 0x10;
    uVar9 = *(uint *)(param_1 + 1000);
    if (local_res18 <= *(uint *)(param_1 + 1000)) {
      uVar9 = local_res18;
    }
    puVar3[4] = uVar9;
    puVar3[5] = *(undefined4 *)(param_1 + 0x78);
    puVar3[3] = *(uint *)(param_1 + 0x74) | 0x148;
    *(longlong *)(lVar1 + 0x48) = lVar4;
    *(ulonglong *)(lVar1 + 0x50) = uVar10;
    *(undefined1 *)(lVar1 + 10) = 0xc;
    *(undefined4 *)(lVar1 + 0x14) = 0x14;
    ScratchBuffer_SendSrb(param_1,'\x01',(undefined8 *)0x0);
    if ((*(char *)(*(longlong *)(param_1 + 0x408) + 3) == '\x02') &&
       (*(int *)(*(longlong *)(param_1 + 0x408) + 0x40) == -0x3ffffee0)) {
      iVar6 = -0x3ffffee0;
      goto LAB_140029a16;
    }
    cVar5 = RequestSenseInfoInterpretForScratchBuffer
                      (param_1,uVar12,(undefined **)local_res8,&local_res20);
    if (cVar5 == '\0') break;
    local_70 = -local_res20;
    uVar12 = uVar12 + 1;
    KeDelayExecutionThread(0,0,&local_70);
    ScratchBuffer_ResetItems(param_1,'\0');
  }
  iVar6 = local_res8[0];
LAB_140029a16:
  if (-1 < iVar6) {
    puVar11 = *(undefined1 **)(param_1 + 0x3f0);
    uVar9 = CONCAT31(CONCAT21(CONCAT11(*puVar11,puVar11[1]),puVar11[2]),puVar11[3]);
    uVar12 = uVar9 + 4;
    if (((uVar9 <= uVar12) && (uVar9 != 0)) && (8 < uVar12)) {
      if (local_res10 == '\0') {
        bVar15 = (puVar11[4] & 3) == 0;
      }
      else {
        bVar15 = (puVar11[4] & 3) == 2;
      }
      if ((bVar15) && ((uVar9 + 0xfc & 0xf) == 0)) {
        uVar13 = *(uint *)(*(longlong *)(param_1 + 0x408) + 0x10);
        if (uVar12 < uVar13) {
          uVar13 = uVar12;
        }
        uVar13 = (uint)((ulonglong)uVar13 - 8 >> 4);
      }
    }
    uVar12 = 0;
    puVar11 = puVar11 + 0x15;
    while (uVar12 < uVar13) {
      uVar9 = CONCAT31(CONCAT21(CONCAT11(puVar11[-1],*puVar11),puVar11[1]),puVar11[2]);
      if (uVar9 < 0x418938) {
        uVar9 = uVar9 * 1000 >> 0xb;
      }
      else {
        uVar9 = (uint)(uint3)(CONCAT21(CONCAT11(puVar11[-1],*puVar11),puVar11[1]) >> 3) * 1000;
      }
      if (uVar9 == 0) break;
      uVar10 = uVar14;
      if (uVar14 == 0xffffffffffffffff) {
        uVar10 = 1000000000;
      }
      puVar11 = puVar11 + 0x10;
      uVar12 = uVar12 + 1;
      uVar14 = 320000000 / (ulonglong)uVar9;
      if ((longlong)uVar10 < (longlong)(320000000 / (ulonglong)uVar9)) {
        uVar14 = uVar10;
      }
    }
  }
  ScratchBuffer_EndUse(param_1);
  return uVar14;
}



===== MmcDataFindFeaturePage @ 140029bb0 =====

undefined1 * MmcDataFindFeaturePage(undefined1 *param_1,uint param_2,uint param_3)

{
  byte bVar1;
  uint uVar2;
  undefined1 *puVar3;
  int local_res10;
  
  if (0xb < param_2) {
    local_res10 = CONCAT31(CONCAT21(CONCAT11(*param_1,param_1[1]),param_1[2]),param_1[3]);
    uVar2 = local_res10 + 4U;
    if (param_2 < local_res10 + 4U) {
      uVar2 = param_2;
    }
    for (puVar3 = param_1 + 8; puVar3 + 4 <= param_1 + uVar2; puVar3 = puVar3 + (ulonglong)bVar1 + 4
        ) {
      bVar1 = puVar3[3];
      if (CONCAT11(*puVar3,puVar3[1]) == param_3) {
        if (puVar3 + (ulonglong)bVar1 + 4 <= param_1 + uVar2) {
          return puVar3;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return (undefined1 *)0x0;
        }
        WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,1,0x17,
                          &WPP_d8e52d07227d39443b0054e092747dea_Traceguids,(char)param_3);
        return (undefined1 *)0x0;
      }
      if (((bVar1 & 3) != 0) && (0xff < param_3 - 0xff00)) {
        return (undefined1 *)0x0;
      }
    }
  }
  return (undefined1 *)0x0;
}



===== DeviceFindFeaturePage @ 140029c8c =====

undefined1 * DeviceFindFeaturePage(undefined1 *param_1,uint param_2,uint param_3)

{
  byte bVar1;
  uint uVar2;
  undefined1 *puVar3;
  int local_res10;
  
  if (0xb < param_2) {
    local_res10 = CONCAT31(CONCAT21(CONCAT11(*param_1,param_1[1]),param_1[2]),param_1[3]);
    uVar2 = local_res10 + 4U;
    if (param_2 < local_res10 + 4U) {
      uVar2 = param_2;
    }
    for (puVar3 = param_1 + 8; puVar3 + 4 <= param_1 + uVar2; puVar3 = puVar3 + (ulonglong)bVar1 + 4
        ) {
      bVar1 = puVar3[3];
      if (CONCAT11(*puVar3,puVar3[1]) == param_3) {
        if (puVar3 + (ulonglong)bVar1 + 4 <= param_1 + uVar2) {
          return puVar3;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return (undefined1 *)0x0;
        }
        WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,1,0x16,
                          &WPP_8ec010589a13368bcaefd70a9b2ee310_Traceguids,(char)param_3);
        return (undefined1 *)0x0;
      }
      if ((bVar1 & 3) != 0) {
        return (undefined1 *)0x0;
      }
    }
  }
  return (undefined1 *)0x0;
}



===== DeviceGetConfiguration @ 140029d58 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong DeviceGetConfiguration
                    (undefined8 param_1,undefined1 *param_2,uint param_3,uint *param_4,
                    undefined4 param_5,byte param_6)

{
  uint uVar1;
  uint uVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined1 auStackY_d8 [32];
  undefined2 local_a8 [5];
  undefined1 local_9e;
  uint local_98;
  undefined4 local_94;
  undefined1 local_60;
  byte local_5f;
  undefined1 local_5e;
  undefined1 local_5d;
  undefined1 local_59;
  undefined1 local_58;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_d8;
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1,DAT_14001a0f0);
  if ((param_2 == (undefined1 *)0x0) || (param_3 < 8)) {
    uVar4 = 0xc0000023;
  }
  else {
    *param_4 = 0;
    memset(local_a8,0,0x58);
    memset(param_2,0,(ulonglong)param_3);
    if ((*(uint *)(lVar3 + 0x340) >> 8 & 1) == 0) {
      if (param_3 < 0xfffd) {
        local_94 = 4;
        local_5f = local_5f ^ (param_6 ^ local_5f) & 3;
        local_9e = 10;
        local_5e = (undefined1)((uint)param_5 >> 8);
        local_59 = (undefined1)(param_3 >> 8);
        local_5d = (undefined1)param_5;
        local_60 = 0x46;
        local_58 = (char)param_3;
        uVar1 = DeviceSendSrbSynchronously(param_1,local_a8,(longlong)param_2,param_3,'\0',0);
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0xc,
                            &WPP_d8e52d07227d39443b0054e092747dea_Traceguids,(char)uVar1);
        }
        if ((((int)uVar1 < 0) && (uVar1 != 0x80000005)) && (uVar1 != 0xc000003c)) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0xd,
                              &WPP_d8e52d07227d39443b0054e092747dea_Traceguids,(char)uVar1);
          }
        }
        else {
          uVar2 = CONCAT31(CONCAT21(CONCAT11(*param_2,param_2[1]),param_2[2]),param_2[3]) + 4;
          if (local_98 <= uVar2) {
            uVar2 = local_98;
          }
          uVar1 = 0;
          *param_4 = uVar2;
        }
        uVar4 = (ulonglong)uVar1;
      }
      else {
        uVar4 = DeviceGetConfiguration(param_1,param_2,0xfffc,param_4,param_5,param_6);
      }
    }
    else {
      uVar4 = 0xc0000010;
    }
  }
  return uVar4;
}



===== DeviceUpdateMmcCapabilities @ 140029f58 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong DeviceUpdateMmcCapabilities(undefined8 param_1)

{
  undefined1 uVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined1 *puVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  bool bVar10;
  undefined1 local_res10 [8];
  uint local_res18 [2];
  undefined4 local_res20 [2];
  uint local_48 [4];
  
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1,DAT_14001a0f0);
  local_res18[0] = 0;
  LOCK();
  bVar10 = *(int *)(lVar2 + 0x290) == 1;
  if (bVar10) {
    *(int *)(lVar2 + 0x290) = 2;
  }
  UNLOCK();
  if (bVar10) {
    *(undefined1 *)(lVar2 + 0x28b) = 0;
    *(undefined2 *)(lVar2 + 0x28d) = 0;
    uVar3 = DeviceGetConfiguration
                      (param_1,*(undefined1 **)(lVar2 + 800),*(uint *)(lVar2 + 0x328),local_res18,0,
                       1);
    uVar9 = uVar3 & 0xffffffff;
    if (((int)uVar3 < 0) || (*(uint *)(lVar2 + 0x328) < local_res18[0])) {
      *(undefined4 *)(lVar2 + 0x290) = 1;
    }
    else {
      local_res10[0] = 0;
      local_res20[0] = 0;
      local_48[0] = 1;
      DeviceUpdateMmcWriteCapability
                (*(undefined1 **)(lVar2 + 800),local_res18[0],'\x01',local_res10,local_res20,
                 local_48);
      *(undefined1 *)(lVar2 + 0x28b) = local_res10[0];
      *(undefined4 *)(lVar2 + 0x294) = local_res20[0];
      *(uint *)(lVar2 + 0x298) = local_48[0];
      puVar4 = MmcDataFindFeaturePage(*(undefined1 **)(lVar2 + 800),local_res18[0],0x107);
      if (((puVar4 != (undefined1 *)0x0) && ((puVar4[2] & 1) != 0)) && (puVar4[3] != '\0')) {
        *(undefined1 *)(lVar2 + 0x28d) = 1;
        *(byte *)(lVar2 + 0x28e) = puVar4[4] & 1;
      }
      puVar4 = DeviceFindFeaturePage(*(undefined1 **)(lVar2 + 800),local_res18[0],0x106);
      if ((puVar4 == (undefined1 *)0x0) || (uVar1 = 1, (puVar4[2] & 1) == 0)) {
        uVar1 = 0;
      }
      *(undefined1 *)(lVar2 + 0x28c) = uVar1;
      uVar5 = DeviceRetryTimeGuessBasedOnProfile
                        ((uint)CONCAT11(*(undefined1 *)(*(longlong *)(lVar2 + 800) + 6),
                                        *(undefined1 *)(*(longlong *)(lVar2 + 800) + 7)));
      uVar6 = DeviceRetryTimeDetectionBasedOnModePage2A(lVar2);
      uVar7 = DeviceRetryTimeDetectionBasedOnGetPerformance(lVar2,'\x01');
      uVar8 = DeviceRetryTimeDetectionBasedOnGetPerformance(lVar2,'\0');
      uVar3 = 0x7fffffffffffffff;
      if (uVar8 != 0xffffffffffffffff) {
        uVar3 = uVar8;
      }
      if ((uVar7 != 0xffffffffffffffff) && ((longlong)uVar7 <= (longlong)uVar3)) {
        uVar3 = uVar7;
      }
      if ((uVar6 != 0xffffffffffffffff) && ((longlong)uVar6 <= (longlong)uVar3)) {
        uVar3 = uVar6;
      }
      if ((uVar5 != 0xffffffffffffffff) && ((longlong)uVar5 <= (longlong)uVar3)) {
        uVar3 = uVar5;
      }
      if (uVar3 == 0x7fffffffffffffff) {
        uVar3 = 0x1046ab;
      }
      *(ulonglong *)(lVar2 + 0x3c8) = uVar3;
    }
    LOCK();
    if (*(int *)(lVar2 + 0x290) == 2) {
      *(int *)(lVar2 + 0x290) = 0;
    }
    UNLOCK();
  }
  else {
    uVar9 = 0;
  }
  return uVar9;
}



===== IoctlWorkItemRoutine @ 14002a1b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void IoctlWorkItemRoutine
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  bool bVar1;
  undefined8 uVar2;
  longlong lVar3;
  undefined8 uVar4;
  
  uVar2 = (**(code **)(WdfFunctions_01015 + 0xbe8))(WdfDriverGlobals,param_1);
  uVar4 = DAT_14001a0f0;
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,uVar2);
  bVar1 = DeviceIsMmcUpdateRequired(*(undefined8 *)(lVar3 + 0x10));
  if (bVar1) {
    DeviceUpdateMmcCapabilities(*(undefined8 *)(lVar3 + 0x10));
  }
  RequestProcessSerializedIoctl(lVar3,*(undefined8 *)(lVar3 + 0x498),uVar4,param_4);
  return;
}



===== RequestProcessSerializedIoctl @ 14002a230 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint RequestProcessSerializedIoctl
               (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  undefined4 *puVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  byte *pbVar6;
  ulonglong uVar7;
  longlong lVar8;
  longlong lVar9;
  undefined8 uVar10;
  size_t _Size;
  undefined8 *puVar11;
  undefined1 auStackY_118 [32];
  ulonglong local_d8 [2];
  undefined8 local_c8;
  ulonglong uStack_c0;
  longlong local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  char local_98 [8];
  byte *local_90;
  undefined8 *local_88;
  undefined8 local_80;
  ulonglong uStack_78;
  longlong local_70;
  undefined8 local_68;
  ulonglong uStack_60;
  longlong local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_118;
  puVar11 = &local_68;
  local_48 = 0;
  uStack_60 = 0;
  lVar9 = 0;
  uVar5 = 0;
  local_68 = 0x28;
  local_58 = 0;
  uStack_50 = 0;
  local_d8[0] = 0;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals);
  NormalizeIoctl((longlong)&local_68);
  if ((uint)uStack_50 == 0x24038) {
switchD_14002a804_caseD_24000:
    local_90 = (byte *)0x0;
    local_c8 = local_68;
    uStack_c0 = uStack_60;
    local_b8 = local_58;
    uStack_b0 = uStack_50;
    lVar9 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x10),DAT_14001a0f0);
    local_80 = 0;
    if ((*(char *)(lVar9 + 0x350) != '\0') &&
       (pbVar6 = (byte *)ExAllocatePool2(0x48,0x10,0x70436353), pbVar6 != (byte *)0x0)) {
      pbVar6[0] = 1;
      pbVar6[1] = 0;
      iVar4 = ReadQChannel(lVar9,0,pbVar6,param_4,pbVar6,0x10,&local_80);
      if (iVar4 < 0) {
        ExFreePoolWithTag(pbVar6,0);
      }
      else {
        *(bool *)(lVar9 + 0x350) = pbVar6[1] == 0x11;
        ExFreePoolWithTag(pbVar6,0);
        if (*(char *)(lVar9 + 0x350) != '\0') {
          uVar5 = 0x80000011;
          goto LAB_14002a4d8;
        }
      }
    }
    uVar7 = uStack_c0;
    uVar5 = (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,param_2,uStack_c0,&local_90);
    if ((int)uVar5 < 0) goto LAB_14002a4d8;
    _Size = 0x324;
    if (uVar7 < 0x324) {
      _Size = uVar7;
    }
    memset(local_90,0,_Size);
    ScratchBuffer_BeginUseX(param_1);
    if ((int)uStack_b0 == 0x24038) {
      local_80 = 0x10000;
    }
    else {
      local_80 = 0x200;
    }
    local_80 = CONCAT17((char)(_Size >> 8),(undefined7)local_80);
    local_80 = CONCAT71(local_80._1_7_,0x43);
    uStack_78 = _Size & 0xff;
    uVar5 = ScratchBuffer_ExecuteCdbEx(param_1,param_2,(uint)_Size,'\x01',&local_80,10,0);
    if (-1 < (int)uVar5) {
      local_d8[0] = (ulonglong)*(uint *)(*(longlong *)(param_1 + 0x408) + 0x10);
      memmove(local_90,*(void **)(param_1 + 0x3f0),local_d8[0]);
    }
LAB_14002a4ce:
    ScratchBuffer_EndUse(param_1);
    goto LAB_14002a4d8;
  }
  if ((uint)uStack_50 == 0x7c0c8) {
    lVar9 = *(longlong *)(param_1 + 0x118);
    while (uVar7 = RequestSetupMcnRequest(param_1,*(char *)(lVar9 + 0x58)), -1 < (int)uVar7) {
      local_98[0] = '\0';
      RequestSend(param_1,*(undefined8 *)(*(longlong *)(param_1 + 0x118) + 0x80),
                  *(undefined8 *)(param_1 + 0x18),2,local_98);
      if ((local_98[0] == '\0') || (uVar7 = RequestPostWorkMcnRequest(param_1), (char)uVar7 == '\0')
         ) break;
    }
    lVar9 = *(longlong *)(param_1 + 0x118);
    local_80 = 0;
    if ((lVar9 != 0) && (iVar4 = KeWaitForSingleObject(lVar9 + 8,0,0,0), iVar4 != 0x102)) {
      if ((*(uint *)(lVar9 + 0x48) != *(uint *)(lVar9 + 0x4c)) && (*(int *)(lVar9 + 0x50) == 0)) {
        DeviceInternalSetMediaChangeState(param_1,*(uint *)(lVar9 + 0x48),(int *)0x0);
      }
      KeReleaseMutex(lVar9 + 8,0);
    }
    goto LAB_14002a4d8;
  }
  if ((uint)uStack_50 < 0x2c06d) {
    if ((uint)uStack_50 == 0x2c06c) {
      uVar5 = RequestHandleSendOpcInformation(param_1,param_2,local_d8);
      goto LAB_14002a4d8;
    }
    switch((uint)uStack_50) {
    case 0x24000:
      goto switchD_14002a804_caseD_24000;
    default:
      goto switchD_14002ae51_caseD_335001;
    case 0x24004:
      local_c8 = local_68;
      uStack_c0 = uStack_60;
      local_a8 = local_48;
      local_b8 = local_58;
      uStack_b0 = uStack_50;
      uVar5 = DeviceHandleSeekAudioMsf(param_1,param_2,&local_c8,local_d8);
      break;
    case 0x24008:
      uVar5 = DeviceHandleStopAudio(param_1,param_2,local_d8);
      break;
    case 0x2400c:
      uVar5 = DeviceHandlePauseAudio(param_1,param_2,local_d8);
      break;
    case 0x24010:
      uVar5 = DeviceHandleResumeAudio(param_1,param_2,local_d8);
      break;
    case 0x24014:
    case 0x24028:
      local_c8 = local_68;
      uStack_c0 = uStack_60;
      local_a8 = local_48;
      local_b8 = local_58;
      uStack_b0 = uStack_50;
      uVar5 = DeviceHandleGetSetVolume(param_1,param_2,(longlong)&local_c8,local_d8);
      break;
    case 0x24018:
      local_c8 = local_68;
      uStack_c0 = uStack_60;
      local_a8 = local_48;
      local_b8 = local_58;
      uStack_b0 = uStack_50;
      uVar5 = DeviceHandlePlayAudioMsf(param_1,param_2,&local_c8,local_d8);
      break;
    case 0x2402c:
      local_c8 = local_68;
      uStack_c0 = uStack_60;
      local_a8 = local_48;
      local_b8 = local_58;
      uStack_b0 = uStack_50;
      uVar5 = DeviceHandleReadQChannel(param_1,param_2,(longlong)&local_c8,local_d8);
      break;
    case 0x2403e:
      local_c8 = local_68;
      uStack_c0 = uStack_60;
      local_a8 = local_48;
      local_b8 = local_58;
      uStack_b0 = uStack_50;
      uVar5 = DeviceHandleRawRead(param_1,param_2,(longlong)&local_c8,local_d8);
      break;
    case 0x2404c:
    case 0x24050:
      goto switchD_14002a804_caseD_2404c;
    case 0x24054:
      local_c8 = local_68;
      uStack_c0 = uStack_60;
      local_a8 = local_48;
      local_b8 = local_58;
      uStack_b0 = uStack_50;
      uVar5 = RequestHandleReadTocEx(param_1,param_2,(longlong)&local_c8,local_d8);
      break;
    case 0x24058:
      local_c8 = local_68;
      uStack_c0 = uStack_60;
      local_a8 = local_48;
      local_b8 = local_58;
      uStack_b0 = uStack_50;
      uVar7 = RequestHandleGetConfiguration(param_1,param_2,(longlong)&local_c8,local_d8);
      uVar5 = (uint)uVar7;
      break;
    case 0x24060:
      local_c8 = local_68;
      uStack_c0 = uStack_60;
      local_a8 = local_48;
      local_b8 = local_58;
      uStack_b0 = uStack_50;
      uVar5 = DeviceHandleSetSpeed(param_1,param_2,(longlong)&local_c8,local_d8);
      break;
    case 0x24068:
      uVar5 = RequestHandleEnableStreaming(param_1,param_2,local_d8);
      break;
    case 0x24070:
      local_c8 = local_68;
      uStack_c0 = uStack_60;
      local_a8 = local_48;
      local_b8 = local_58;
      uStack_b0 = uStack_50;
      uVar5 = RequestHandleGetPerformance(param_1,param_2,(longlong)&local_c8,local_d8);
    }
    goto LAB_14002a4d8;
  }
  if ((uint)uStack_50 < 0x2dd01d) {
    if ((uint)uStack_50 == 0x2dd01c) {
LAB_14002ade3:
      local_c8 = local_68;
      uStack_c0 = uStack_60;
      local_a8 = local_48;
      local_b8 = local_58;
      uStack_b0 = uStack_50;
      uVar5 = RequestHandlePersistentReserve(param_1,param_2,(longlong)&local_c8,local_d8);
      goto LAB_14002a4d8;
    }
    if ((uint)uStack_50 < 0x2d080d) {
      if ((uint)uStack_50 != 0x2d080c) {
        if ((uint)uStack_50 < 0x700a1) {
          if (((uint)uStack_50 != 0x700a0) && ((uint)uStack_50 != 0x70000)) {
            if ((uint)uStack_50 == 0x70014) {
              local_c8 = local_68;
              uStack_c0 = uStack_60;
              local_a8 = local_48;
              local_b8 = local_58;
              uStack_b0 = uStack_50;
              uVar5 = RequestHandleDiskVerify(param_1,param_2,&local_c8,local_d8);
              goto LAB_14002a4d8;
            }
            if ((uint)uStack_50 == 0x70024) {
              if ((*(char *)(param_1 + 0x28b) == '\0') || (*(int *)(param_1 + 0x294) != 0x24)) {
                uVar5 = 0xc00000a2;
              }
              goto LAB_14002a4d8;
            }
            if (((uint)uStack_50 != 0x70048) && ((uint)uStack_50 != 0x70050))
            goto switchD_14002ae51_caseD_335001;
            goto LAB_14002abf9;
          }
        }
        else {
          if (((uint)uStack_50 == 0x74004) || ((uint)uStack_50 == 0x7400c)) {
LAB_14002abf9:
            local_c8 = local_68;
            uStack_c0 = uStack_60;
            local_a8 = local_48;
            local_b8 = local_58;
            uStack_b0 = uStack_50;
            uVar5 = RequestHandleFakePartitionInfo(param_1,param_2,(longlong)&local_c8,local_d8);
            goto LAB_14002a4d8;
          }
          if ((uint)uStack_50 != 0x7405c) {
            if ((uint)uStack_50 == 0x7421c) {
              uVar5 = RequestHandleAreVolumesReady(param_1,param_2,puVar11,local_d8);
              return uVar5;
            }
            if ((uint)uStack_50 != 0x2d0800) goto switchD_14002ae51_caseD_335001;
LAB_14002a574:
            local_c8 = local_68;
            uStack_c0 = uStack_60;
            local_b8 = local_58;
            uStack_b0 = uStack_50;
            ScratchBuffer_BeginUseX(param_1);
            local_70 = *(longlong *)(param_1 + 0x408);
            uVar5 = 0;
            local_88 = (undefined8 *)((ulonglong)local_88 & 0xffffffff00000000);
            local_90 = (byte *)0x0;
            while( true ) {
              uVar10 = *(undefined8 *)(param_1 + 0x400);
              lVar8 = (**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals,uVar10);
              puVar2 = *(undefined4 **)(param_1 + 0x408);
              lVar9 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,uVar10);
              *(undefined8 *)(lVar9 + 8) = param_2;
              lVar9 = *(longlong *)(lVar8 + 0xb8);
              *(undefined1 *)(lVar9 + -0x48) = 0xf;
              *(undefined4 *)(lVar9 + -0x30) = 0x1b0013;
              *(undefined4 **)(lVar9 + -0x40) = puVar2;
              *puVar2 = 0x58;
              *(undefined1 *)((longlong)puVar2 + 9) = 0x20;
              *(undefined1 *)(puVar2 + 1) = 0;
              *(undefined8 *)(puVar2 + 10) = 0;
              *(longlong *)(puVar2 + 0xc) = lVar8;
              *(undefined1 *)((longlong)puVar2 + 0xb) = 0x12;
              *(undefined8 *)(puVar2 + 8) = *(undefined8 *)(param_1 + 0x410);
              *(undefined1 *)((longlong)puVar2 + 10) = 0x10;
              puVar2[4] = 0;
              puVar2[5] = *(undefined4 *)(param_1 + 0x78);
              puVar2[3] = *(uint *)(param_1 + 0x74) | 0x108;
              *(undefined8 *)(local_70 + 0x48) = 0;
              *(undefined8 *)(local_70 + 0x50) = 0;
              *(undefined1 *)(local_70 + 10) = 6;
              *(undefined4 *)(local_70 + 0x14) = 0x14;
              ScratchBuffer_SendSrb(param_1,'\x01',(undefined8 *)0x0);
              if ((*(char *)(*(longlong *)(param_1 + 0x408) + 3) == '\x02') &&
                 (*(int *)(*(longlong *)(param_1 + 0x408) + 0x40) == -0x3ffffee0)) {
                uVar5 = 0xc0000120;
                local_88 = (undefined8 *)CONCAT44(local_88._4_4_,0xc0000120);
                goto LAB_14002a6b5;
              }
              cVar3 = RequestSenseInfoInterpretForScratchBuffer
                                (param_1,uVar5,(undefined **)&local_88,&local_90);
              if (cVar3 == '\0') break;
              local_80 = -(longlong)local_90;
              uVar5 = uVar5 + 1;
              KeDelayExecutionThread(0,0,&local_80);
              ScratchBuffer_ResetItems(param_1,'\0');
            }
            uVar5 = (uint)local_88;
LAB_14002a6b5:
            if (((-1 < (int)uVar5) && ((int)uStack_b0 == 0x2d4800)) && (uStack_c0 != 0)) {
              local_90 = (byte *)0x0;
              uVar5 = (**(code **)(WdfFunctions_01015 + 0x870))
                                (WdfDriverGlobals,param_2,uStack_c0,&local_90);
              if (local_90 != (byte *)0x0) {
                *(undefined4 *)local_90 = *(undefined4 *)(param_1 + 0x148);
                local_d8[0] = 4;
              }
            }
            goto LAB_14002a4ce;
          }
        }
switchD_14002a804_caseD_2404c:
        local_88 = (undefined8 *)0x0;
        local_b8 = local_58;
        uStack_b0 = uStack_50;
        uVar5 = (**(code **)(WdfFunctions_01015 + 0x870))
                          (WdfDriverGlobals,param_2,uStack_60,&local_88);
        if (((int)uVar5 < 0) ||
           (uVar5 = MediaReadCapacity(*(undefined8 *)(param_1 + 0x10)), (int)uVar5 < 0))
        goto LAB_14002a4d8;
        if ((int)uStack_b0 == 0x7405c) {
          local_d8[0] = 8;
          *local_88 = *(undefined8 *)(param_1 + 0xa8);
          goto LAB_14002a4d8;
        }
        if ((int)uStack_b0 == 0x2404c) {
LAB_14002a9e4:
          uVar10 = *(undefined8 *)(param_1 + 0x90);
          local_d8[0] = 0x18;
          *local_88 = *(undefined8 *)(param_1 + 0x88);
          local_88[1] = uVar10;
          local_88[2] = *(undefined8 *)(param_1 + 0x98);
        }
        else {
          if ((int)uStack_b0 != 0x24050) {
            if ((int)uStack_b0 == 0x70000) goto LAB_14002a9e4;
            if ((int)uStack_b0 != 0x700a0) {
              if ((int)uStack_b0 == 0x2d5140) {
                *(undefined4 *)local_88 = 0x20;
                *(undefined4 *)((longlong)local_88 + 4) = 0x20;
                uVar1 = *(uint *)(param_1 + 0x9c);
                *(uint *)(local_88 + 1) = uVar1;
                if (uVar1 != 0) {
                  lVar9 = *(longlong *)(param_1 + 0xa8) / (longlong)(ulonglong)uVar1;
                }
                local_88[2] = lVar9;
                local_88[3] = *(undefined8 *)(param_1 + 0xa8);
                local_d8[0] = 0x20;
              }
              goto LAB_14002a4d8;
            }
          }
          local_d8[0] = 0x20;
          local_88[3] = *(undefined8 *)(param_1 + 0xa8);
          uVar10 = *(undefined8 *)(param_1 + 0x90);
          *local_88 = *(undefined8 *)(param_1 + 0x88);
          local_88[1] = uVar10;
          local_88[2] = *(undefined8 *)(param_1 + 0x98);
        }
        goto LAB_14002a4d8;
      }
    }
    else if ((uint)uStack_50 < 0x2d4809) {
      if ((uint)uStack_50 != 0x2d4808) {
        if ((uint)uStack_50 != 0x2d0940) {
          if ((uint)uStack_50 == 0x2d0944) {
            uVar5 = RequestHandleMcnControl(param_1,param_2,local_d8);
            goto LAB_14002a4d8;
          }
          if ((uint)uStack_50 == 0x2d4400) {
            local_c8 = local_68;
            uStack_c0 = uStack_60;
            local_a8 = local_48;
            local_b8 = local_58;
            uStack_b0 = uStack_50;
            uVar5 = DeviceHandleSetReadAhead(param_1,param_2,(longlong)&local_c8,local_d8);
            goto LAB_14002a4d8;
          }
          if ((uint)uStack_50 == 0x2d4800) goto LAB_14002a574;
          if ((uint)uStack_50 != 0x2d4804) goto switchD_14002ae51_caseD_335001;
        }
        local_90 = (byte *)0x0;
        local_b8 = local_58;
        uStack_b0 = uStack_50;
        if (local_58 == 0) {
          uVar5 = 0xc0000004;
        }
        else {
          uVar5 = (**(code **)(WdfFunctions_01015 + 0x868))
                            (WdfDriverGlobals,param_2,local_58,&local_90);
          if (-1 < (int)uVar5) {
            uVar5 = PerformEjectionControl
                              (param_1,param_2,(uint)((int)uStack_b0 == 0x2d0940),*local_90);
          }
        }
        goto LAB_14002a4d8;
      }
    }
    else if ((uint)uStack_50 != 0x2d480c) {
      if (((uint)uStack_50 == 0x2d4810) || ((uint)uStack_50 == 0x2d4814)) {
        local_c8 = local_68;
        uStack_c0 = uStack_60;
        local_a8 = local_48;
        local_b8 = local_58;
        uStack_b0 = uStack_50;
        uVar5 = RequestHandleReserveRelease(param_1,param_2,(longlong)&local_c8,local_d8);
        goto LAB_14002a4d8;
      }
      if ((uint)uStack_50 != 0x2d5018) {
        if ((uint)uStack_50 != 0x2d5140) goto switchD_14002ae51_caseD_335001;
        goto switchD_14002a804_caseD_2404c;
      }
      goto LAB_14002ade3;
    }
    local_c8 = local_68;
    uStack_c0 = uStack_60;
    local_a8 = local_48;
    local_b8 = local_58;
    uStack_b0 = uStack_50;
    uVar5 = RequestHandleLoadEjectMedia(param_1,param_2,(longlong)&local_c8,local_d8);
    goto LAB_14002a4d8;
  }
  if ((uint)uStack_50 < 0x335141) {
    if ((uint)uStack_50 == 0x335140) {
      local_c8 = local_68;
      uStack_c0 = uStack_60;
      local_a8 = local_48;
      local_b8 = local_58;
      uStack_b0 = uStack_50;
      uVar5 = DeviceHandleReadDvdStructure(param_1,param_2,(longlong)&local_c8,local_d8);
      goto LAB_14002a4d8;
    }
    switch((uint)uStack_50) {
    case 0x335000:
    case 0x335004:
      local_c8 = local_68;
      uStack_c0 = uStack_60;
      local_a8 = local_48;
      local_b8 = local_58;
      uStack_b0 = uStack_50;
      uVar5 = DeviceHandleDvdStartSessionReadKey(param_1,param_2,(longlong)&local_c8,local_d8);
      break;
    default:
      goto switchD_14002ae51_caseD_335001;
    case 0x335008:
      goto switchD_14002ae51_caseD_335008;
    case 0x33500c:
      local_c8 = local_68;
      uStack_c0 = uStack_60;
      local_a8 = local_48;
      local_b8 = local_58;
      uStack_b0 = uStack_50;
      uVar5 = DeviceHandleDvdEndSession(param_1,param_2,&local_c8,local_d8);
      break;
    case 0x335014:
      uVar5 = RequestHandleGetDvdRegion(param_1,param_2,local_d8);
      break;
    case 0x3350c0:
    case 0x3350c4:
      local_c8 = local_68;
      uStack_c0 = uStack_60;
      local_a8 = local_48;
      local_b8 = local_58;
      uStack_b0 = uStack_50;
      uVar5 = DeviceHandleAacsReadMediaKeyBlock(param_1,param_2,(longlong)&local_c8,local_d8);
      break;
    case 0x3350c8:
      local_c8 = local_68;
      uStack_c0 = uStack_60;
      local_a8 = local_48;
      local_b8 = local_58;
      uStack_b0 = uStack_50;
      uVar5 = DeviceHandleAacsStartSession(param_1,param_2,(longlong)&local_c8,local_d8);
      break;
    case 0x3350cc:
      local_c8 = local_68;
      uStack_c0 = uStack_60;
      local_a8 = local_48;
      local_b8 = local_58;
      uStack_b0 = uStack_50;
      uVar5 = DeviceHandleAacsEndSession(param_1,param_2,&local_c8,local_d8);
      break;
    case 0x3350d0:
      local_c8 = local_68;
      uStack_c0 = uStack_60;
      local_a8 = local_48;
      local_b8 = local_58;
      uStack_b0 = uStack_50;
      uVar5 = DeviceHandleAacsSendCertificate(param_1,param_2,(longlong)&local_c8,local_d8);
      break;
    case 0x3350d4:
      local_c8 = local_68;
      uStack_c0 = uStack_60;
      local_a8 = local_48;
      local_b8 = local_58;
      uStack_b0 = uStack_50;
      uVar5 = DeviceHandleAacsGetCertificate(param_1,param_2,(longlong)&local_c8,local_d8);
      break;
    case 0x3350d8:
      local_c8 = local_68;
      uStack_c0 = uStack_60;
      local_a8 = local_48;
      local_b8 = local_58;
      uStack_b0 = uStack_50;
      uVar5 = DeviceHandleAacsGetChallengeKey(param_1,param_2,(longlong)&local_c8,local_d8);
      break;
    case 0x3350dc:
      local_c8 = local_68;
      uStack_c0 = uStack_60;
      local_a8 = local_48;
      local_b8 = local_58;
      uStack_b0 = uStack_50;
      uVar5 = DeviceHandleSendChallengeKey(param_1,param_2,(longlong)&local_c8,local_d8);
      break;
    case 0x3350e0:
      local_c8 = local_68;
      uStack_c0 = uStack_60;
      local_a8 = local_48;
      local_b8 = local_58;
      uStack_b0 = uStack_50;
      uVar5 = DeviceHandleReadVolumeId(param_1,param_2,(longlong)&local_c8,local_d8);
      break;
    case 0x3350e4:
      local_c8 = local_68;
      uStack_c0 = uStack_60;
      local_a8 = local_48;
      local_b8 = local_58;
      uStack_b0 = uStack_50;
      uVar5 = DeviceHandleAacsReadSerialNumber(param_1,param_2,(longlong)&local_c8,local_d8);
      break;
    case 0x3350e8:
      local_c8 = local_68;
      uStack_c0 = uStack_60;
      local_a8 = local_48;
      local_b8 = local_58;
      uStack_b0 = uStack_50;
      uVar5 = DeviceHandleAacsReadMediaId(param_1,param_2,(longlong)&local_c8,local_d8);
      break;
    case 0x3350ec:
      local_c8 = local_68;
      uStack_c0 = uStack_60;
      local_a8 = local_48;
      local_b8 = local_58;
      uStack_b0 = uStack_50;
      uVar5 = DeviceHandleAacsReadBindingNonce(param_1,param_2,(longlong)&local_c8,local_d8);
    }
  }
  else {
    if ((uint)uStack_50 == 0x33d018) {
switchD_14002ae51_caseD_335008:
      local_c8 = local_68;
      uStack_c0 = uStack_60;
      local_a8 = local_48;
      local_b8 = local_58;
      uStack_b0 = uStack_50;
      uVar5 = DeviceHandleDvdSendKey(param_1,param_2,(longlong)&local_c8,local_d8);
      goto LAB_14002a4d8;
    }
    if ((uint)uStack_50 == 0x33d0f0) {
      local_c8 = local_68;
      uStack_c0 = uStack_60;
      local_a8 = local_48;
      local_b8 = local_58;
      uStack_b0 = uStack_50;
      uVar5 = DeviceHandleAacsGenerateBindingNonce(param_1,param_2,(longlong)&local_c8,local_d8);
      goto LAB_14002a4d8;
    }
    if (((uint)uStack_50 == 0x56c008) || ((uint)uStack_50 == 0x56c064)) {
      uVar10 = RequestHandleVolumeOnline(param_1,param_2,puVar11,local_d8);
      uVar5 = (uint)uVar10;
      goto LAB_14002a4d8;
    }
switchD_14002ae51_caseD_335001:
    uVar5 = 0xc0000022;
  }
LAB_14002a4d8:
  RequestCompletion(param_1,param_2,uVar5,local_d8[0]);
  return uVar5;
}



===== RequestSetupMcnRequest @ 14002b260 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong RequestSetupMcnRequest(longlong param_1,char param_2)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 *puVar3;
  uint uVar4;
  longlong lVar5;
  ulonglong uVar6;
  undefined8 local_38;
  undefined4 local_30;
  undefined8 local_2c;
  undefined4 local_24;
  
  lVar1 = *(longlong *)(param_1 + 0x118);
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals,*(undefined8 *)(lVar1 + 0x80));
  if (*(longlong *)(lVar5 + 8) != 0) {
    *(undefined8 *)(lVar5 + 8) = 0;
  }
  local_2c = 0;
  local_24 = 0;
  local_38 = 0x18;
  local_30 = 0xc00000bb;
  uVar6 = (**(code **)(WdfFunctions_01015 + 0x7c8))
                    (WdfDriverGlobals,*(undefined8 *)(lVar1 + 0x80),&local_38);
  if (-1 < (int)uVar6) {
    uVar4 = (**(code **)(WdfFunctions_01015 + 0x5f8))
                      (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x18),
                       *(undefined8 *)(lVar1 + 0x80),0x1b0011,0,0,0,0,0,0);
    uVar6 = (ulonglong)uVar4;
    if ((int)uVar4 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x1d,
                          &WPP_bfcef3ce16aa3c5196ed71474c974d5c_Traceguids,(char)uVar4);
      }
    }
    else {
      RequestClearSendTime(*(undefined8 *)(lVar1 + 0x80));
      lVar2 = *(longlong *)(lVar5 + 0xb8);
      *(undefined1 *)(lVar2 + -0x46) = 2;
      *(undefined1 *)(lVar2 + -0x48) = 0xf;
      *(undefined4 **)(lVar2 + -0x40) = (undefined4 *)(lVar1 + 0x88);
      puVar3 = *(undefined8 **)(lVar1 + 0xe0);
      *(undefined8 *)(lVar1 + 0x8a) = 0;
      *(undefined8 *)(lVar1 + 0x92) = 0;
      *(undefined8 *)(lVar1 + 0x9a) = 0;
      *(undefined8 *)(lVar1 + 0xa2) = 0;
      *(undefined8 *)(lVar1 + 0xaa) = 0;
      *(undefined8 *)(lVar1 + 0xb2) = 0;
      *(undefined8 *)(lVar1 + 0xba) = 0;
      *(undefined8 *)(lVar1 + 0xc2) = 0;
      *(undefined8 *)(lVar1 + 0xca) = 0;
      *(undefined8 *)(lVar1 + 0xd2) = 0;
      *(undefined4 *)(lVar1 + 0xda) = 0;
      *(undefined2 *)(lVar1 + 0xde) = 0;
      *puVar3 = 0;
      puVar3[1] = 0;
      *(undefined2 *)(puVar3 + 2) = 0;
      *(undefined2 *)(lVar1 + 0x90) = 0x20ff;
      *(undefined4 *)(lVar1 + 0x88) = 0x58;
      *(undefined8 **)(lVar1 + 0xa8) = puVar3;
      *(undefined1 *)(lVar1 + 0x8c) = 0;
      *(longlong *)(lVar1 + 0xb8) = lVar5;
      *(undefined1 *)(lVar1 + 0x93) = 0x12;
      uVar4 = *(uint *)(param_1 + 0x74);
      *(uint *)(lVar1 + 0x94) = uVar4;
      uVar4 = uVar4 | *(uint *)(lVar1 + 0xe8);
      if (param_2 == '\0') {
        *(uint *)(lVar1 + 0x94) = uVar4;
        *(undefined4 *)(lVar1 + 0x9c) = 0x14;
        *(undefined1 *)(lVar1 + 0x92) = 6;
        *(undefined4 *)(lVar2 + -0x30) = 0x1b0013;
        *(undefined8 *)(lVar1 + 0xa0) = 0;
        *(undefined4 *)(lVar1 + 0x98) = 0;
        *(undefined8 *)(lVar5 + 8) = 0;
        *(undefined1 *)(lVar1 + 0xd0) = 0;
        return uVar6;
      }
      *(undefined4 *)(lVar1 + 0x9c) = 4;
      *(uint *)(lVar1 + 0x94) = uVar4 | 0x40;
      *(undefined1 *)(lVar1 + 0x92) = 10;
      *(undefined4 *)(lVar2 + -0x30) = 0x1b0011;
      *(undefined8 *)(lVar1 + 0xa0) = *(undefined8 *)(lVar1 + 0x60);
      *(undefined4 *)(lVar1 + 0x98) = *(undefined4 *)(lVar1 + 0x70);
      *(undefined8 *)(lVar5 + 8) = *(undefined8 *)(lVar1 + 0x68);
      *(byte *)(lVar1 + 0xd1) = *(byte *)(lVar1 + 0xd1) | 1;
      *(undefined1 *)(lVar1 + 0xd0) = 0x4a;
      *(char *)(lVar1 + 0xd7) = (char)((uint)*(undefined4 *)(lVar1 + 0x70) >> 8);
      *(undefined1 *)(lVar1 + 0xd8) = *(undefined1 *)(lVar1 + 0x70);
      *(undefined1 *)(lVar1 + 0xd4) = *(undefined1 *)(lVar1 + 0x5a);
    }
  }
  return uVar6;
}



===== RequestPostWorkMcnRequest @ 14002b4f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong RequestPostWorkMcnRequest(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  longlong lVar4;
  ulonglong uVar5;
  byte local_res8 [8];
  uint local_res10 [2];
  undefined8 local_res18;
  undefined8 local_88;
  code *pcStack_80;
  undefined8 local_78;
  undefined4 local_70;
  undefined8 local_6c;
  undefined8 uStack_64;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  
  lVar1 = *(longlong *)(param_1 + 0x118);
  local_res10[0] = 0;
  local_res8[0] = 0;
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals,*(undefined8 *)(lVar1 + 0x80));
  if ((*(byte *)(lVar1 + 0x8b) & 0x3f) == 1) {
    *(undefined1 *)(*(longlong *)(param_1 + 0x478) + 0x21) = 0;
    if (*(char *)(lVar1 + 0x58) == '\0') {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,0xd,0x1f,
                         &WPP_bfcef3ce16aa3c5196ed71474c974d5c_Traceguids);
      }
      DeviceSetMediaChangeStateEx(param_1,1,(int *)0x0);
    }
    else if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
            (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,0xd,0x20,
                       &WPP_bfcef3ce16aa3c5196ed71474c974d5c_Traceguids);
    }
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      lVar2 = *(longlong *)(lVar1 + 0xa8);
      WPP_RECORDER_SF_DDDD
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,0xd,0x1e,
                 &WPP_bfcef3ce16aa3c5196ed71474c974d5c_Traceguids,*(byte *)(lVar1 + 0x8b),
                 *(byte *)(lVar2 + 2) & 0xf,*(undefined1 *)(lVar2 + 0xc),
                 *(undefined1 *)(lVar2 + 0xd));
    }
    if ((*(byte *)(lVar1 + 0x8b) & 0x3f) != 0x24) {
      if ((*(byte *)(lVar1 + 0x8b) & 0x40) != 0) {
        DeviceReleaseQueue(*(undefined8 *)(param_1 + 0x10));
      }
      RequestSenseInfoInterpret
                (param_1,*(undefined8 *)(lVar1 + 0x80),(undefined8 *)(lVar1 + 0x88),0,
                 (undefined **)local_res10,(undefined8 *)0x0);
    }
  }
  if (*(char *)(lVar1 + 0x58) != '\0') {
    if (local_res10[0] == -0x3fffffc4) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,0xd,0x21,
                         &WPP_bfcef3ce16aa3c5196ed71474c974d5c_Traceguids);
      }
      local_res10[0] = 0;
    }
    else if ((int)local_res10[0] < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,0xd,0x22,
                          &WPP_bfcef3ce16aa3c5196ed71474c974d5c_Traceguids,(char)local_res10[0]);
      }
      goto LAB_14002b5da;
    }
    if (*(longlong *)(lVar4 + 0x38) == 8) {
      GesnDataInterpret(param_1,*(undefined **)(lVar1 + 0x60),local_res8);
    }
  }
LAB_14002b5da:
  if ((*(uint *)(lVar1 + 0x94) & 0x200400) == 0x200400) {
    ExFreePoolWithTag(*(undefined8 *)(lVar1 + 0xa8),0);
    *(uint *)(lVar1 + 0x94) = *(uint *)(lVar1 + 0x94) & 0xfffffbff;
    *(undefined8 *)(lVar1 + 0xa8) = 0;
    *(undefined1 *)(lVar1 + 0x93) = 0;
  }
  *(longlong *)(*(longlong *)(lVar4 + 0xb8) + -0x40) = lVar1 + 0x88;
  if (local_res8[0] == 0) {
    *(undefined4 *)(lVar1 + 0x54) = 0;
  }
  else {
    iVar3 = *(int *)(lVar1 + 0x54) + 1;
    *(int *)(lVar1 + 0x54) = iVar3;
    if (0x20 < iVar3) {
      local_50 = *(undefined8 *)(param_1 + 0x10);
      local_res18 = 0;
      local_5c = 0;
      pcStack_80 = DeviceDisableGesn;
      local_6c = 0;
      uStack_64 = 0;
      local_70 = 0x38;
      local_48 = 0;
      uStack_40 = 0;
      local_58 = 1;
      local_54 = 1;
      local_88 = 0x18;
      local_78 = 0;
      uVar5 = (**(code **)(WdfFunctions_01015 + 0xbd8))
                        (WdfDriverGlobals,&local_88,&local_70,&local_res18);
      local_res10[0] = (uint)uVar5;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,0xd,0x23,
                          &WPP_bfcef3ce16aa3c5196ed71474c974d5c_Traceguids,
                          (char)*(undefined8 *)(param_1 + 0x10));
        uVar5 = (ulonglong)local_res10[0];
      }
      if (-1 < (int)uVar5) {
        uVar5 = (**(code **)(WdfFunctions_01015 + 0xbe0))(WdfDriverGlobals,local_res18);
      }
      *(char *)(lVar1 + 0x58) = '\0';
      *(undefined1 *)(lVar1 + 0x5a) = 0;
      *(undefined4 *)(lVar1 + 0x70) = 0;
      *(undefined4 *)(lVar1 + 0x54) = 0;
      return uVar5 & 0xffffffffffffff00;
    }
  }
  return (ulonglong)local_res8[0];
}



===== GesnDataInterpret @ 14002b910 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 GesnDataInterpret(longlong param_1,undefined *param_2,undefined1 *param_3)

{
  byte *pbVar1;
  char *pcVar2;
  byte bVar3;
  undefined8 uVar4;
  byte bVar5;
  int iVar6;
  byte bVar7;
  undefined *puVar8;
  longlong lVar9;
  uint uVar10;
  undefined1 auStackY_108 [32];
  undefined1 local_c8 [4];
  undefined4 local_c4 [3];
  undefined2 local_b8;
  undefined1 local_b5;
  undefined2 local_ae;
  undefined8 *local_98;
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_108;
  lVar9 = *(longlong *)(param_1 + 0x118);
  *param_3 = 0;
  bVar5 = param_2[2];
  if (((char)bVar5 < '\0') || ((bVar5 & 7) == 0)) {
LAB_14002b9a8:
    uVar4 = 0;
  }
  else {
    puVar8 = param_2;
    if (*(char *)(lVar9 + 0x59) == '\0') {
LAB_14002b9d7:
      iVar6 = CONCAT11(*param_2,param_2[1]) - 2;
      if (3 < iVar6) {
        if ((4 < iVar6) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          puVar8 = (undefined *)CONCAT71((int7)((ulonglong)puVar8 >> 8),3);
          WPP_RECORDER_SF_Dq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,0xd,0xc,
                             &WPP_bfcef3ce16aa3c5196ed71474c974d5c_Traceguids,(char)iVar6,
                             (char)*(undefined8 *)(param_1 + 0x40));
        }
        if ((param_2[4] & 0xf) != 0) {
          *param_3 = 1;
          bVar5 = param_2[2] & 7;
          if (bVar5 == 1) {
            if ((param_2[4] & 0xf) != 1) {
              if (*(int *)(lVar9 + 0x54) < 4) {
                if (CONCAT11(param_2[6],param_2[7]) == 2 || CONCAT11(param_2[6],param_2[7]) == 1) {
                  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,0xd,0xe,
                                      &WPP_bfcef3ce16aa3c5196ed71474c974d5c_Traceguids,
                                      (char)*(undefined8 *)(param_1 + 0x10));
                  }
                  lVar9 = *(longlong *)(param_1 + 0x40);
                  uVar4 = IsVolumeMounted(lVar9);
                  if ((char)uVar4 != '\0') {
                    *(uint *)(lVar9 + 0x30) = *(uint *)(lVar9 + 0x30) | 2;
                  }
                  memset(&local_b8,0,0x58);
                  local_c4[0] = 0x8000001c;
                  local_48 = local_48 & 0xffffffffffff0000;
                  local_c8[0] = 0;
                  local_98 = &local_58;
                  local_ae = 0x1206;
                  local_b8 = 0x58;
                  local_b5 = 0x84;
                  local_58 = 0xa00000000060000;
                  uStack_50 = 0x2800000000;
                  if (*(code **)(param_1 + 0x348) != (code *)0x0) {
                    (**(code **)(param_1 + 0x348))(param_1,&local_b8,local_c4,local_c8);
                  }
                }
              }
              else {
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0xd,0xd,
                                    &WPP_bfcef3ce16aa3c5196ed71474c974d5c_Traceguids,
                                    (char)*(undefined8 *)(param_1 + 0x10));
                }
                bVar7 = *(byte *)(lVar9 + 0x5b) | 2;
                *(undefined1 *)(lVar9 + 0x59) = 1;
                pbVar1 = (byte *)(lVar9 + 0x5a);
                *pbVar1 = *pbVar1 & 0xfd;
                bVar5 = *pbVar1;
                *(byte *)(lVar9 + 0x5b) = bVar7;
                if (bVar5 == 0) {
                  *(byte *)(lVar9 + 0x5a) = bVar7;
                  *(undefined1 *)(lVar9 + 0x5b) = 0;
                }
                *param_3 = bVar5 != 0;
              }
            }
          }
          else if (bVar5 == 3) {
            uStack_50 = uStack_50 & 0xffffffff;
            if ((param_2[4] & 0xf) == 1) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_DDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,0xd,0xf,
                                    &WPP_bfcef3ce16aa3c5196ed71474c974d5c_Traceguids,
                                    param_2[4] & 0xf,param_2[5] & 0xf,param_2[7]);
              }
              lVar9 = _DAT_fffff78000000014;
              local_58 = 1;
              uStack_50._0_4_ = CONCAT22(CONCAT11(param_2[6],param_2[7]),(ushort)(param_2[4] & 0xf))
              ;
              uVar10 = KeQueryTimeIncrement();
              local_48 = (ulonglong)uVar10 * lVar9;
              DeviceSendNotification
                        (param_1,(undefined4 *)&GUID_IO_DEVICE_EXTERNAL_REQUEST,0x18,&local_58);
            }
          }
          else if (bVar5 == 4) {
            bVar5 = param_2[4] & 0xf;
            if ((bVar5 - 2 & 0xfd) == 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,0xd,0x10,
                                  &WPP_bfcef3ce16aa3c5196ed71474c974d5c_Traceguids,param_2[5]);
              }
              lVar9 = *(longlong *)(param_1 + 0x40);
              uVar4 = IsVolumeMounted(lVar9);
              if ((char)uVar4 != '\0') {
                *(uint *)(lVar9 + 0x30) = *(uint *)(lVar9 + 0x30) | 2;
              }
              uVar4 = 0;
              DeviceSetMediaChangeStateEx(param_1,1,(int *)0x0);
              pcVar2 = *(char **)(param_1 + 0x120);
              if (((pcVar2 != (char *)0x0) && (*pcVar2 == '\0')) && (pcVar2[1] == '\0')) {
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  uVar4 = CONCAT71((int7)((ulonglong)uVar4 >> 8),4);
                  WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,3,0x11,
                                   &WPP_bfcef3ce16aa3c5196ed71474c974d5c_Traceguids);
                }
                DeviceMarkActive(param_1,(longlong *)CONCAT71((int7)((ulonglong)uVar4 >> 8),1),
                                 (uint *)0x0);
              }
            }
            else if (bVar5 == 3) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,0xd,0x12,
                                  &WPP_bfcef3ce16aa3c5196ed71474c974d5c_Traceguids,param_2[5]);
              }
              DeviceSetMediaChangeStateEx(param_1,2,(int *)0x0);
              pcVar2 = *(char **)(param_1 + 0x120);
              if (((pcVar2 != (char *)0x0) && (*pcVar2 == '\0')) && (pcVar2[1] == '\0')) {
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,3,0x13,
                                   &WPP_bfcef3ce16aa3c5196ed71474c974d5c_Traceguids);
                }
                DeviceMarkActive(param_1,(longlong *)0x0,(uint *)0x0);
              }
            }
            else if (bVar5 == 1) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,0xd,0x14,
                                  &WPP_bfcef3ce16aa3c5196ed71474c974d5c_Traceguids,param_2[5]);
              }
              DeviceSendNotification
                        (param_1,(undefined4 *)&GUID_IO_MEDIA_EJECT_REQUEST,0,(void *)0x0);
            }
          }
          else if (bVar5 == 6) {
            uVar10 = (uint)CONCAT11(param_2[6],param_2[7]);
            uStack_50 = CONCAT44(uStack_50._4_4_,uVar10);
            local_58 = CONCAT44((uint)(byte)param_2[5],1);
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              puVar8 = (undefined *)CONCAT71((int7)((ulonglong)puVar8 >> 8),4);
              WPP_RECORDER_SF_DDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,0xd,0x15,
                                  &WPP_bfcef3ce16aa3c5196ed71474c974d5c_Traceguids,param_2[4] & 0xf,
                                  param_2[5],param_2[7]);
            }
            if (1 < uVar10) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,0xd,0x16,
                                 &WPP_bfcef3ce16aa3c5196ed71474c974d5c_Traceguids);
              }
              puVar8 = &GUID_IO_DEVICE_BECOMING_READY;
              DeviceSendNotification
                        (param_1,(undefined4 *)&GUID_IO_DEVICE_BECOMING_READY,0xc,&local_58);
            }
            pcVar2 = *(char **)(param_1 + 0x120);
            if (((pcVar2 != (char *)0x0) && (*pcVar2 == '\x01')) &&
               ((pcVar2[1] == '\0' && (((param_2[4] & 0xf) == 2 && (param_2[5] == '\0')))))) {
              uVar4 = DeviceZPODDIsInHomePosition(param_1);
              if ((char)uVar4 == '\0') {
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  puVar8 = (undefined *)CONCAT71((int7)((ulonglong)puVar8 >> 8),4);
                  WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,3,0x17,
                                   &WPP_bfcef3ce16aa3c5196ed71474c974d5c_Traceguids);
                }
                DeviceMarkActive(param_1,(longlong *)CONCAT71((int7)((ulonglong)puVar8 >> 8),1),
                                 (uint *)0x0);
              }
              else {
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,3,0x18,
                                   &WPP_bfcef3ce16aa3c5196ed71474c974d5c_Traceguids);
                }
                DeviceMarkActive(param_1,(longlong *)0x0,(uint *)0x0);
              }
            }
          }
        }
        goto LAB_14002b9a8;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_Dq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,0xd,0xb,
                           &WPP_bfcef3ce16aa3c5196ed71474c974d5c_Traceguids,(char)iVar6,
                           (char)*(undefined8 *)(param_1 + 0x40));
      }
    }
    else {
      bVar7 = '\x01' << (bVar5 & 7);
      puVar8 = (undefined *)0x0;
      bVar5 = *(byte *)(lVar9 + 0x5a);
      if ((bVar7 & bVar5) != 0) {
        if (bVar7 == (-bVar5 & bVar5)) {
          if ((param_2[4] & 0xf) == 0) {
            bVar3 = bVar7 | *(byte *)(lVar9 + 0x5b);
            *(byte *)(lVar9 + 0x5b) = bVar3;
            *(byte *)(lVar9 + 0x5a) = ~bVar7 & bVar5;
            if ((~bVar7 & bVar5) == 0) {
              *(byte *)(lVar9 + 0x5a) = bVar3;
              *(undefined1 *)(lVar9 + 0x5b) = 0;
            }
            else {
              *param_3 = 1;
            }
            goto LAB_14002b9a8;
          }
        }
        else {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            puVar8 = (undefined *)0x0;
            WPP_RECORDER_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,0xd,10,
                               &WPP_bfcef3ce16aa3c5196ed71474c974d5c_Traceguids,bVar7,bVar5);
          }
          *(undefined1 *)(lVar9 + 0x59) = 0;
        }
        goto LAB_14002b9d7;
      }
    }
    uVar4 = 0xc0000186;
  }
  return uVar4;
}



===== ScratchBuffer_ExecuteCdbEx @ 14002c050 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4
ScratchBuffer_ExecuteCdbEx
          (longlong param_1,undefined8 param_2,uint param_3,char param_4,undefined8 *param_5,
          undefined1 param_6,int param_7)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined4 *puVar3;
  char cVar4;
  longlong lVar5;
  longlong lVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined4 uVar10;
  undefined4 local_res8 [2];
  undefined8 local_res10;
  longlong local_48;
  longlong local_40;
  
  lVar1 = *(longlong *)(param_1 + 0x408);
  uVar9 = 0;
  local_res8[0] = 0;
  local_48 = 0;
  local_res10 = param_2;
  while( true ) {
    uVar2 = *(undefined8 *)(param_1 + 0x400);
    lVar5 = (**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals,uVar2);
    puVar3 = *(undefined4 **)(param_1 + 0x408);
    lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,uVar2);
    *(undefined8 *)(lVar6 + 8) = local_res10;
    lVar6 = *(longlong *)(lVar5 + 0xb8);
    *(undefined1 *)(lVar6 + -0x48) = 0xf;
    if (param_3 == 0) {
      *(undefined4 *)(lVar6 + -0x30) = 0x1b0013;
      *(undefined4 **)(lVar6 + -0x40) = puVar3;
    }
    else {
      uVar10 = 0x1b0011;
      if (param_4 == '\0') {
        uVar10 = 0x1b0012;
      }
      *(undefined4 *)(lVar6 + -0x30) = uVar10;
      *(undefined4 **)(lVar6 + -0x40) = puVar3;
      *(undefined8 *)(lVar5 + 8) = *(undefined8 *)(param_1 + 0x3f8);
      *(undefined8 *)(puVar3 + 6) = *(undefined8 *)(param_1 + 0x3f0);
    }
    *puVar3 = 0x58;
    *(undefined1 *)((longlong)puVar3 + 9) = 0x20;
    *(undefined1 *)(puVar3 + 1) = 0;
    *(undefined8 *)(puVar3 + 10) = 0;
    *(longlong *)(puVar3 + 0xc) = lVar5;
    *(undefined1 *)((longlong)puVar3 + 0xb) = 0x12;
    *(undefined8 *)(puVar3 + 8) = *(undefined8 *)(param_1 + 0x410);
    *(undefined1 *)((longlong)puVar3 + 10) = 0x10;
    uVar7 = param_3;
    if (*(uint *)(param_1 + 1000) < param_3) {
      uVar7 = *(uint *)(param_1 + 1000);
    }
    puVar3[4] = uVar7;
    puVar3[5] = *(undefined4 *)(param_1 + 0x78);
    uVar7 = *(uint *)(param_1 + 0x74);
    uVar8 = uVar7 | 0x108;
    if (param_3 != 0) {
      uVar8 = uVar7 | 0x188;
      if (param_4 != '\0') {
        uVar8 = uVar7 | 0x148;
      }
    }
    puVar3[3] = uVar8;
    uVar2 = param_5[1];
    *(undefined8 *)(lVar1 + 0x48) = *param_5;
    *(undefined8 *)(lVar1 + 0x50) = uVar2;
    *(undefined1 *)(lVar1 + 10) = param_6;
    if (param_7 != 0) {
      *(int *)(lVar1 + 0x14) = param_7;
    }
    ScratchBuffer_SendSrb(param_1,'\x01',(undefined8 *)0x0);
    if ((*(char *)(*(longlong *)(param_1 + 0x408) + 3) == '\x02') &&
       (*(int *)(*(longlong *)(param_1 + 0x408) + 0x40) == -0x3ffffee0)) break;
    cVar4 = RequestSenseInfoInterpretForScratchBuffer
                      (param_1,uVar9,(undefined **)local_res8,&local_48);
    if (cVar4 == '\0') {
      return local_res8[0];
    }
    local_40 = -local_48;
    uVar9 = uVar9 + 1;
    KeDelayExecutionThread(0,0,&local_40);
    ScratchBuffer_ResetItems(param_1,'\0');
  }
  return 0xc0000120;
}



===== RequestHandleGetConfiguration @ 14002c290 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong RequestHandleGetConfiguration
                    (longlong param_1,undefined8 param_2,longlong param_3,ulonglong *param_4)

{
  longlong lVar1;
  uint uVar2;
  ulonglong uVar3;
  uint *local_res20;
  undefined1 *local_58;
  undefined8 local_50;
  ulonglong uStack_48;
  
  lVar1 = *(longlong *)(param_1 + 0x120);
  local_res20 = (uint *)0x0;
  local_58 = (undefined1 *)0x0;
  *param_4 = 0;
  if (*(char *)(param_1 + 0x288) == '\0') {
    return 0xc0000010;
  }
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x868))
                    (WdfDriverGlobals,param_2,*(undefined8 *)(param_3 + 0x10),&local_res20,0);
  if ((int)uVar3 < 0) {
    return uVar3;
  }
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x870))
                    (WdfDriverGlobals,param_2,*(undefined8 *)(param_3 + 8),&local_58,0);
  if ((int)uVar3 < 0) {
    return uVar3;
  }
  if (((lVar1 != 0) && (*(char *)(lVar1 + 0x51) != '\0')) &&
     (*(undefined1 **)(lVar1 + 0x60) != (undefined1 *)0x0)) {
    GetConfigurationDataSynthesize
              (*(undefined1 **)(lVar1 + 0x60),*(uint *)(lVar1 + 0x68),local_58,
               *(ulonglong *)(param_3 + 8),*local_res20,local_res20[1],param_4);
    return uVar3 & 0xffffffff;
  }
  uVar3 = 0xfffe;
  if (*(ulonglong *)(param_3 + 8) < 0xfffe) {
    uVar3 = *(ulonglong *)(param_3 + 8);
  }
  if (((local_res20[1] == 2) && ((*(uint *)(param_1 + 0x340) >> 0xb & 1) != 0)) && (uVar3 < 0xd)) {
    uVar3 = 0xc;
  }
  ScratchBuffer_BeginUseX(param_1);
  local_50 = (uVar3 >> 8) << 0x38;
  uStack_48 = uVar3 & 0xff;
  local_50._0_2_ = CONCAT11((byte)local_res20[1] & 3,0x46);
  local_50 = CONCAT62(CONCAT51(CONCAT41(local_50._4_4_,(char)*local_res20),(char)(*local_res20 >> 8)
                              ),(ushort)local_50);
  if ((local_res20[1] == 2) && ((*(uint *)(param_1 + 0x340) >> 0xb & 1) != 0)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,5,0x32,
                       &WPP_7cea3eca420c34d4f6f4315c54c616a1_Traceguids);
    }
    local_50._0_2_ = (ushort)(byte)local_50;
  }
  uVar2 = ScratchBuffer_ExecuteCdbEx(param_1,param_2,(uint)uVar3,'\x01',&local_50,0xc,0);
  if (-1 < (int)uVar2) {
    if ((local_res20[1] == 2) && ((*(uint *)(param_1 + 0x340) >> 0xb & 1) != 0)) {
      if (*(uint *)(*(longlong *)(param_1 + 0x408) + 0x10) < 8) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x33,
                           &WPP_7cea3eca420c34d4f6f4315c54c616a1_Traceguids);
        }
        uVar2 = 0xc0000010;
        uVar3 = 0;
      }
      else {
        GetConfigurationDataConversionTypeAllToTypeOne
                  (*local_res20,*(longlong *)(param_1 + 0x408),param_4);
        uVar3 = *param_4;
        if (*(ulonglong *)(param_3 + 8) <= *param_4) {
          uVar3 = *(ulonglong *)(param_3 + 8);
        }
      }
      *param_4 = uVar3;
      if ((int)uVar2 < 0) goto LAB_14002c431;
    }
    else {
      uVar3 = (ulonglong)*(uint *)(*(longlong *)(param_1 + 0x408) + 0x10);
      *param_4 = uVar3;
    }
    memmove(local_58,*(void **)(param_1 + 0x3f0),uVar3);
  }
LAB_14002c431:
  ScratchBuffer_EndUse(param_1);
  return (ulonglong)uVar2;
}



===== MediaReadCapacity @ 14002c5b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int MediaReadCapacity(undefined8 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStackY_b8 [32];
  undefined8 local_88;
  undefined2 local_78 [5];
  undefined1 local_6e;
  undefined4 local_64;
  undefined1 local_30;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_b8;
  memset(local_78,0,0x58);
  local_6e = 10;
  local_88 = 0;
  local_64 = 0x14;
  local_30 = 0x25;
  iVar1 = DeviceSendSrbSynchronously(param_1,local_78,(longlong)&local_88,8,'\0',0);
  uVar2 = local_88._4_4_;
  if (iVar1 < 0) {
    uVar2 = 0;
  }
  local_88 = CONCAT44(uVar2,(undefined4)local_88);
  MediaReadCapacityDataInterpret(param_1,(undefined4 *)&local_88);
  return iVar1;
}



===== MediaReadCapacityDataInterpret @ 14002c670 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void MediaReadCapacityDataInterpret(undefined8 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  bool bVar3;
  char cVar4;
  longlong lVar5;
  longlong lVar6;
  byte bVar7;
  uint uVar8;
  undefined4 local_res10;
  
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1,DAT_14001a0f0);
  bVar3 = false;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x43,
                     &WPP_8ec010589a13368bcaefd70a9b2ee310_Traceguids);
  }
  uVar1 = param_2[1];
  local_res10._0_2_ = CONCAT11((char)((uint)uVar1 >> 0x10),(char)((uint)uVar1 >> 0x18));
  local_res10._0_3_ = CONCAT12((char)((uint)uVar1 >> 8),(undefined2)local_res10);
  local_res10 = CONCAT13((char)uVar1,(undefined3)local_res10);
  if (local_res10 == 0) {
    uVar8 = 0x800;
    bVar3 = true;
  }
  else {
    bVar7 = 0xff;
    do {
      bVar7 = bVar7 + 1;
      local_res10 = local_res10 >> 1;
    } while (local_res10 != 0);
    uVar8 = 1 << (bVar7 & 0x1f);
  }
  *(uint *)(lVar5 + 0x9c) = uVar8;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x44,
                      &WPP_8ec010589a13368bcaefd70a9b2ee310_Traceguids,(char)uVar8);
  }
  uVar1 = *param_2;
  cVar4 = (char)((uint)uVar1 >> 0x18);
  local_res10._0_2_ = CONCAT11((char)((uint)uVar1 >> 0x10),cVar4);
  local_res10._0_3_ = CONCAT12((char)((uint)uVar1 >> 8),(undefined2)local_res10);
  iVar2 = 0x1f;
  if (uVar8 != 0) {
    for (; uVar8 >> iVar2 == 0; iVar2 = iVar2 + -1) {
    }
  }
  local_res10 = CONCAT13((char)uVar1,(undefined3)local_res10);
  *(char *)(lVar5 + 0xa0) = (char)iVar2;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x45,
                        &WPP_8ec010589a13368bcaefd70a9b2ee310_Traceguids,
                        (char)*(undefined4 *)(lVar5 + 0x9c));
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x46,
                        &WPP_8ec010589a13368bcaefd70a9b2ee310_Traceguids,cVar4 + '\x01');
    }
  }
  if (bVar3) {
    lVar6 = 0x7fffffff;
  }
  else {
    lVar6 = (ulonglong)(local_res10 + 1) << (*(byte *)(lVar5 + 0xa0) & 0x3f);
  }
  *(longlong *)(lVar5 + 0xa8) = lVar6;
  *(ulonglong *)(lVar5 + 0x88) = (ulonglong)(local_res10 + 1 >> 0xb);
  *(undefined4 *)(lVar5 + 0x94) = 0x40;
  *(undefined4 *)(lVar5 + 0x98) = 0x20;
  *(undefined4 *)(lVar5 + 0x90) = 0xb;
  return;
}



===== DeviceSendSrbSynchronously @ 14002c890 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int DeviceSendSrbSynchronously
              (undefined8 param_1,undefined2 *param_2,longlong param_3,undefined4 param_4,
              char param_5,undefined8 param_6)

{
  undefined1 *puVar1;
  bool bVar2;
  char cVar3;
  uint uVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  longlong lVar8;
  longlong lVar9;
  ulonglong uVar10;
  uint uVar11;
  word *pwVar12;
  undefined2 uVar13;
  char local_res10;
  int local_d4 [3];
  longlong local_c8;
  int local_c0;
  uint local_bc;
  longlong local_b8;
  undefined1 *local_b0;
  longlong local_a8;
  longlong local_a0;
  longlong local_98;
  longlong local_90;
  undefined8 local_88;
  undefined4 local_80;
  undefined8 local_7c;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 local_60;
  undefined4 uStack_5c;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1,DAT_14001a0f0);
  local_98 = *(longlong *)(lVar5 + 0x478);
  local_bc = 0;
  local_c0 = 0;
  local_c8 = 0;
  lVar7 = 0;
  lVar8 = 0;
  bVar2 = false;
  local_70 = 0;
  uStack_6c = 0;
  uStack_68 = 0;
  uStack_64 = 0;
  local_60 = 0;
  uStack_5c = 0;
  uStack_58 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = (undefined *)((ulonglong)local_40._4_4_ << 0x20);
  local_90 = *(longlong *)(lVar5 + 0x120);
  *param_2 = 0x58;
  *(undefined1 *)(param_2 + 1) = 0;
  puVar1 = (undefined1 *)((longlong)param_2 + 0xb);
  *puVar1 = 0x12;
  local_b0 = puVar1;
  lVar6 = ExAllocatePool2(0x48,0x12,0x49436353);
  local_b8 = lVar6;
  if (lVar6 == 0) {
    local_d4[0] = -0x3fffff66;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar13 = 10;
LAB_14002cf7c:
      local_d4[0] = -0x3fffff66;
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,uVar13,
                       &WPP_8ec010589a13368bcaefd70a9b2ee310_Traceguids);
    }
  }
  else {
    *(longlong *)(param_2 + 0x10) = lVar6;
    *(longlong *)(param_2 + 0xc) = param_3;
    if (*(int *)(param_2 + 10) == 0) {
      *(undefined4 *)(param_2 + 10) = *(undefined4 *)(lVar5 + 0x78);
    }
    uStack_6c = 0;
    uStack_68 = 0;
    uStack_64 = 0;
    local_60 = 0;
    uStack_5c = 0;
    local_50 = 0;
    uStack_48 = 0;
    local_70 = 0x38;
    uStack_58 = 0x100000001;
    local_40 = PTR__WDF_CDROM_REQUEST_CONTEXT_TYPE_INFO_14001a018;
    local_d4[0] = (**(code **)(WdfFunctions_01015 + 0x7b8))
                            (WdfDriverGlobals,&local_70,*(undefined8 *)(lVar5 + 0x18),&local_c8);
    if (-1 < local_d4[0]) {
      lVar7 = (**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals,local_c8);
      local_a8 = lVar7;
      if (param_3 != 0) {
        lVar8 = IoAllocateMdl(param_3,param_4,0,0,lVar7);
        local_a0 = lVar8;
        if (lVar8 == 0) {
          local_d4[0] = -0x3fffff66;
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar13 = 0xc;
            goto LAB_14002cf7c;
          }
          goto LAB_14002c99c;
        }
        MmProbeAndLockPages(lVar8,0,param_5 == '\0');
        bVar2 = true;
      }
      do {
        local_res10 = '\0';
        if (*(longlong *)(lVar7 + 8) != 0) {
          *(undefined8 *)(lVar7 + 8) = 0;
        }
        local_7c = 0;
        local_74 = 0;
        local_88 = 0x18;
        local_80 = 0;
        local_d4[0] = (**(code **)(WdfFunctions_01015 + 0x7c8))(WdfDriverGlobals,local_c8);
        if (local_d4[0] < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar13 = 0xe;
LAB_14002cf0a:
            WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,uVar13,
                              &WPP_8ec010589a13368bcaefd70a9b2ee310_Traceguids,(char)local_d4[0]);
          }
          break;
        }
        local_d4[0] = (**(code **)(WdfFunctions_01015 + 0x5f8))
                                (WdfDriverGlobals,*(undefined8 *)(lVar5 + 0x18),local_c8,local_c0,0,
                                 0,0,0,0,0);
        if (local_d4[0] < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar13 = 0xf;
            goto LAB_14002cf0a;
          }
          break;
        }
        lVar9 = (**(code **)(WdfFunctions_01015 + 0x650))
                          (WdfDriverGlobals,local_c8,
                           PTR__WDF_CDROM_REQUEST_CONTEXT_TYPE_INFO_14001a018);
        *(undefined8 *)(lVar9 + 8) = param_6;
        *(longlong *)(param_2 + 0x18) = lVar7;
        *(undefined1 *)((longlong)param_2 + 9) = 0x20;
        *(undefined4 *)(param_2 + 8) = param_4;
        uVar11 = *(uint *)(lVar5 + 0x74) | 0x108;
        *(uint *)(param_2 + 6) = uVar11;
        if (param_3 == 0) {
          local_c0 = 0x1b0013;
        }
        else {
          uVar4 = 0x80;
          if (param_5 == '\0') {
            uVar4 = 0x40;
          }
          *(uint *)(param_2 + 6) = uVar4 | uVar11;
          local_c0 = (param_5 != '\0') + 0x1b0011;
        }
        *(undefined2 *)((longlong)param_2 + 3) = 0;
        *(undefined8 *)(param_2 + 0x14) = 0;
        *(longlong *)(lVar7 + 8) = lVar8;
        lVar9 = *(longlong *)(lVar7 + 0xb8);
        *(undefined1 *)(lVar9 + -0x48) = 0xf;
        *(int *)(lVar9 + -0x30) = local_c0;
        *(undefined2 **)(lVar9 + -0x40) = param_2;
        local_b8 = local_c8;
        local_b0 = (undefined1 *)
                   (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1,DAT_14001a0f0)
        ;
        lVar9 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,local_b8);
        if (*(longlong *)(lVar9 + 8) == 0) {
          cVar3 = '\0';
        }
        else {
          cVar3 = (**(code **)(WdfFunctions_01015 + 0x808))(WdfDriverGlobals);
        }
        if (cVar3 == '\0') {
          local_d4[0] = RequestSend((longlong)local_b0,local_b8,*(undefined8 *)(local_b0 + 0x18),2,
                                    (char *)0x0);
        }
        else {
          local_d4[0] = -0x3ffffee0;
        }
        if (local_d4[0] != -0x3ffffee0) {
          if ((*(byte *)((longlong)param_2 + 3) & 0x3f) == 1) {
            *(undefined1 *)(local_98 + 0x21) = 0;
            local_d4[0] = 0;
            break;
          }
          local_b8 = 0;
          uVar10 = RequestSenseInfoInterpret
                             (lVar5,local_c8,(undefined8 *)param_2,local_bc,(undefined **)local_d4,
                              &local_b8);
          local_res10 = (char)uVar10;
          if (local_res10 == '\0') break;
          local_b0 = (undefined1 *)-local_b8;
          local_bc = local_bc + 1;
          KeDelayExecutionThread(0,0);
        }
      } while (local_res10 != '\0');
      pwVar12 = (word *)&WPP_8ec010589a13368bcaefd70a9b2ee310_Traceguids;
      if (((local_90 != 0) && (*(char *)(local_90 + 0x53) != '\0')) &&
         ((*(byte *)((longlong)param_2 + 3) & 0x3f) == 1)) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          pwVar12 = &_load_config_used.DynamicValueRelocTableSection;
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,3,0x10,
                           &WPP_8ec010589a13368bcaefd70a9b2ee310_Traceguids);
        }
        DeviceMarkActive(lVar5,(longlong *)CONCAT71((int7)((ulonglong)pwVar12 >> 8),1),(uint *)0x0);
      }
      if ((*(uint *)(param_2 + 6) & 0x200400) == 0x200400) {
        ExFreePoolWithTag(*(undefined8 *)(param_2 + 0x10),0);
        *(undefined8 *)(param_2 + 0x10) = 0;
        *puVar1 = 0;
        *(uint *)(param_2 + 6) = *(uint *)(param_2 + 6) & 0xfffffbff;
      }
      goto LAB_14002c99f;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0xb,
                        &WPP_8ec010589a13368bcaefd70a9b2ee310_Traceguids,(char)local_d4[0]);
    }
  }
LAB_14002c99c:
  bVar2 = false;
LAB_14002c99f:
  if (lVar6 != 0) {
    ExFreePoolWithTag(lVar6,0);
  }
  *(undefined8 *)(param_2 + 0x10) = 0;
  *puVar1 = 0;
  if (lVar8 != 0) {
    if (bVar2) {
      MmUnlockPages(lVar8);
    }
    IoFreeMdl(lVar8);
    *(undefined8 *)(lVar7 + 8) = 0;
  }
  if (local_c8 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
  return local_d4[0];
}



===== DeviceRetryTimeDetectionBasedOnModePage2A @ 14002d0a0 =====

ulonglong DeviceRetryTimeDetectionBasedOnModePage2A(longlong param_1)

{
  undefined1 *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  byte *pbVar5;
  ulonglong uVar6;
  undefined8 local_18;
  ulonglong uStack_10;
  
  uVar4 = *(uint *)(param_1 + 1000);
  if (0xfff0 < uVar4) {
    uVar4 = 0xfff0;
  }
  uVar6 = 0xffffffffffffffff;
  ScratchBuffer_BeginUseX(param_1);
  uStack_10 = (ulonglong)(byte)uVar4;
  local_18 = CONCAT17((char)(uVar4 >> 8),0x2a085a);
  iVar2 = ScratchBuffer_ExecuteCdbEx(param_1,0,uVar4,'\x01',&local_18,10,0);
  if (-1 < iVar2) {
    puVar1 = *(undefined1 **)(param_1 + 0x3f0);
    uVar4 = CONCAT11(*puVar1,puVar1[1]) + 2;
    if (CONCAT11(*puVar1,puVar1[1]) == 0) {
      uVar4 = 0;
    }
    if (((7 < uVar4) && (uVar4 <= *(uint *)(param_1 + 1000))) && (puVar1[7] == '\0')) {
      if (puVar1[6] == '\0') {
        uVar4 = uVar4 - 8;
        pbVar5 = puVar1 + 8;
      }
      else {
        if (puVar1[6] != '\b') goto LAB_14002d1b7;
        uVar4 = uVar4 - 8;
        uVar3 = uVar4;
        if (7 < uVar4) {
          uVar3 = 8;
        }
        uVar4 = uVar4 - uVar3;
        pbVar5 = puVar1 + 0x10;
      }
      if (pbVar5 != (byte *)0x0) {
        if ((1 < uVar4) && (pbVar5[1] + 2 <= uVar4)) {
          uVar4 = pbVar5[1] + 2;
        }
        if (uVar4 < 0x14) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,9,0x19,
                               &WPP_d8e52d07227d39443b0054e092747dea_Traceguids,(char)uVar4,0x14);
          }
        }
        else if ((*pbVar5 & 0x3f) == 0x2a) {
          uVar4 = (uint)CONCAT11(pbVar5[0x12],pbVar5[0x13]) * 1000 >> 0xb;
          if (uVar4 != 0) {
            uVar6 = 320000000 / (ulonglong)uVar4;
          }
        }
        else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,9,0x1a,
                            &WPP_d8e52d07227d39443b0054e092747dea_Traceguids,*pbVar5 & 0x3f);
        }
      }
    }
  }
LAB_14002d1b7:
  ScratchBuffer_EndUse(param_1);
  return uVar6;
}



===== PerformEjectionControl @ 14002d290 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int PerformEjectionControl(longlong param_1,undefined8 param_2,int param_3,byte param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  longlong lVar5;
  int iVar6;
  int iVar7;
  char cVar8;
  bool bVar9;
  undefined1 auStackY_138 [32];
  int local_d4;
  int local_d0;
  int local_cc;
  longlong local_c0;
  undefined2 local_a8 [5];
  undefined1 local_9e;
  undefined4 local_94;
  undefined1 local_60;
  byte local_5c;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_138;
  local_c0 = 0;
  memset(local_a8,0,0x58);
  bVar9 = false;
  local_d0 = 0;
  local_d4 = (**(code **)(WdfFunctions_01015 + 0x9c8))
                       (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x110),0);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                      &WPP_8ec010589a13368bcaefd70a9b2ee310_Traceguids,5,0x5d,
                      &WPP_8ec010589a13368bcaefd70a9b2ee310_Traceguids,(&LockTypeStrings)[param_3]);
  }
  if (param_3 == 1) {
    lVar5 = (**(code **)(WdfFunctions_01015 + 0x8a8))(WdfDriverGlobals,param_2);
    if (lVar5 == 0) {
      local_d4 = -0x3ffffff8;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x5e,
                         &WPP_8ec010589a13368bcaefd70a9b2ee310_Traceguids);
      }
      goto LAB_14002d5e8;
    }
    local_c0 = (**(code **)(WdfFunctions_01015 + 0x650))
                         (WdfDriverGlobals,lVar5,PTR__WDF_FILE_OBJECT_CONTEXT_TYPE_INFO_14001a090);
  }
  iVar1 = *(int *)(param_1 + 0xf4);
  iVar2 = *(int *)(param_1 + 0xec);
  iVar3 = *(int *)(param_1 + 0xf0);
  if (local_c0 != 0) {
    local_d0 = *(int *)(local_c0 + 0x10);
  }
  iVar7 = iVar2;
  iVar6 = iVar3;
  local_cc = iVar1;
  if (param_4 == 0) {
    if (param_3 == 0) {
      bVar9 = iVar2 != 0;
      iVar7 = iVar2 + -1;
      if (iVar2 == 0) {
        iVar7 = iVar2;
      }
    }
    else {
      if (param_3 == 1) {
        if ((local_d0 == 0) || (iVar3 == 0)) {
          local_d4 = -0x3ffffe7c;
          goto LAB_14002d5e8;
        }
        local_d0 = local_d0 + -1;
        iVar6 = iVar3 + -1;
        goto LAB_14002d4d5;
      }
      if (param_3 == 2) {
        local_cc = iVar1 + -1;
        goto LAB_14002d4d1;
      }
    }
  }
  else {
    if (param_3 == 0) {
      iVar7 = iVar2 + 1;
    }
    else if (param_3 == 1) {
      local_d0 = local_d0 + 1;
      iVar6 = iVar3 + 1;
    }
    else {
      if (param_3 != 2) goto LAB_14002d4d8;
      local_cc = iVar1 + 1;
LAB_14002d4d1:
    }
LAB_14002d4d5:
    bVar9 = true;
  }
LAB_14002d4d8:
  if (((iVar2 == 0) && (iVar3 == 0)) && (iVar1 == 0)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if (((iVar7 == 0) && (iVar6 == 0)) && (local_cc == 0)) {
    cVar8 = '\0';
  }
  else {
    cVar8 = '\x01';
  }
  if (cVar4 != cVar8) {
    memset(local_a8,0,0x58);
    local_94 = *(undefined4 *)(param_1 + 0x78);
    local_9e = 6;
    local_60 = 0x1e;
    local_5c = local_5c ^ (local_5c ^ param_4) & 1;
    local_d4 = DeviceSendSrbSynchronously(*(undefined8 *)(param_1 + 0x10),local_a8,0,0,'\0',param_2)
    ;
  }
  if ((bVar9) && (-1 < local_d4)) {
    *(int *)(param_1 + 0xec) = iVar7;
    *(int *)(param_1 + 0xf0) = iVar6;
    *(int *)(param_1 + 0xf4) = local_cc;
    if (local_c0 != 0) {
      *(int *)(local_c0 + 0x10) = local_d0;
    }
  }
LAB_14002d5e8:
  (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x110));
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_dddDDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  return local_d4;
}



===== DeviceIsPlayActive @ 14002d68c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined1
DeviceIsPlayActive(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  longlong lVar2;
  byte *pbVar3;
  ulonglong local_res10 [3];
  
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1,DAT_14001a0f0);
  local_res10[0] = 0;
  if ((*(char *)(lVar2 + 0x350) != '\0') &&
     (pbVar3 = (byte *)ExAllocatePool2(0x48,0x10,0x70436353), pbVar3 != (byte *)0x0)) {
    pbVar3[0] = 1;
    pbVar3[1] = 0;
    iVar1 = ReadQChannel(lVar2,0,pbVar3,param_4,pbVar3,0x10,local_res10);
    if (-1 < iVar1) {
      *(bool *)(lVar2 + 0x350) = pbVar3[1] == 0x11;
      ExFreePoolWithTag(pbVar3,0);
      return *(undefined1 *)(lVar2 + 0x350);
    }
    ExFreePoolWithTag(pbVar3,0);
  }
  return 0;
}



===== RequestHandleReadTocEx @ 14002d764 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int RequestHandleReadTocEx(longlong param_1,undefined8 param_2,longlong param_3,ulonglong *param_4)

{
  uint uVar1;
  undefined8 uVar2;
  void *_Src;
  undefined2 uVar3;
  char cVar4;
  int iVar5;
  ulonglong uVar6;
  byte *local_res8;
  void *local_res20;
  undefined8 local_38;
  ulonglong uStack_30;
  
  local_res8 = (byte *)0x0;
  uVar2 = *(undefined8 *)(param_1 + 0x10);
  local_res20 = (void *)0x0;
  *param_4 = 0;
  cVar4 = DeviceIsPlayActive(uVar2,param_2,param_3,param_4);
  if (cVar4 == '\0') {
    iVar5 = (**(code **)(WdfFunctions_01015 + 0x868))
                      (WdfDriverGlobals,param_2,*(undefined8 *)(param_3 + 0x10),&local_res8,0);
    if (-1 < iVar5) {
      iVar5 = (**(code **)(WdfFunctions_01015 + 0x870))
                        (WdfDriverGlobals,param_2,*(undefined8 *)(param_3 + 8),&local_res20,0);
      if (-1 < iVar5) {
        uVar6 = 0xffff;
        if (*(ulonglong *)(param_3 + 8) < 0xffff) {
          uVar6 = *(ulonglong *)(param_3 + 8);
        }
        ScratchBuffer_BeginUseX(param_1);
        uStack_30 = uVar6 & 0xff;
        local_38._0_2_ = CONCAT11(*local_res8 >> 6 & 2,0x43);
        uVar3 = (undefined2)local_38;
        local_38 = (ulonglong)CONCAT11((char)(uVar6 >> 8),local_res8[1]) << 0x30;
        local_38 = CONCAT53(local_38._3_5_,CONCAT12(*local_res8,uVar3)) & 0xffffffffff0fffff;
        iVar5 = ScratchBuffer_ExecuteCdbEx(param_1,param_2,(uint)uVar6,'\x01',&local_38,10,0);
        if (-1 < iVar5) {
          uVar1 = *(uint *)(*(longlong *)(param_1 + 0x408) + 0x10);
          if (uVar1 < 2) {
            *param_4 = 0;
            iVar5 = -0x3ffffff0;
          }
          else {
            _Src = *(void **)(param_1 + 0x3f0);
            *param_4 = (ulonglong)uVar1;
            memmove(local_res20,_Src,(ulonglong)uVar1);
          }
        }
        ScratchBuffer_EndUse(param_1);
      }
    }
  }
  else {
    iVar5 = -0x7fffffef;
  }
  return iVar5;
}



===== DeviceEvtSelfManagedIoInit @ 14002d8f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong DeviceEvtSelfManagedIoInit(undefined8 param_1)

{
  uint *puVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  longlong lVar5;
  ulonglong uVar6;
  longlong lVar7;
  undefined **ppuVar8;
  ulonglong uVar9;
  uint local_res10 [2];
  undefined1 local_res18 [8];
  char local_res20 [8];
  undefined8 in_stack_ffffffffffffffa8;
  undefined4 uVar10;
  undefined8 in_stack_ffffffffffffffb0;
  undefined8 uVar11;
  undefined4 uVar12;
  char local_38 [16];
  
  uVar10 = (undefined4)((ulonglong)in_stack_ffffffffffffffa8 >> 0x20);
  uVar12 = (undefined4)((ulonglong)in_stack_ffffffffffffffb0 >> 0x20);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    uVar10 = 1;
    uVar11 = param_1;
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0xc,
                      &WPP_c6cef56efab5359de7c6f40b77738682_Traceguids,(char)param_1);
    uVar12 = (undefined4)((ulonglong)uVar11 >> 0x20);
  }
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1,DAT_14001a0f0);
  DeviceRetrieveScsiAddress(lVar5,lVar5 + 0x7c);
  uVar6 = DeviceRetrieveDescriptorsAndTransferLength(lVar5);
  uVar9 = uVar6 & 0xffffffff;
  if (-1 < (int)uVar6) {
    uVar3 = DeviceInitAllocateBuffers(lVar5);
    uVar9 = (ulonglong)uVar3;
    if (-1 < (int)uVar3) {
      local_res10[0] = 0x10;
      DeviceGetParameter(lVar5,0x140015260,L"RestorePerfAtCount",local_res10);
      if (0xf < local_res10[0]) {
        *(uint *)(*(longlong *)(lVar5 + 0x478) + 8) = local_res10[0];
      }
      DeviceRetrieveHackFlagsFromRegistry(lVar5);
      ppuVar8 = &CdRomBadItems;
      DeviceScanForSpecial(lVar5,&CdRomBadItems,DeviceHackFlagsScan);
      DeviceScanSpecialDevices(lVar5);
      uVar3 = DeviceInitializeHotplugInfo(lVar5);
      uVar9 = (ulonglong)uVar3;
      if (-1 < (int)uVar3) {
        uVar3 = DeviceCacheDeviceInquiryData(lVar5);
        uVar9 = (ulonglong)uVar3;
        if ((int)uVar3 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,9,0xd,
                              &WPP_c6cef56efab5359de7c6f40b77738682_Traceguids,(char)uVar3);
          }
        }
        else {
          uVar6 = DeviceInitializeMediaChangeDetection(lVar5,ppuVar8);
          uVar9 = uVar6 & 0xffffffff;
          if (-1 < (int)uVar6) {
            uVar3 = DeviceInitMmcContext(lVar5);
            uVar9 = (ulonglong)uVar3;
            if (-1 < (int)uVar3) {
              uVar6 = DeviceInitializeZPODD(lVar5);
              uVar9 = uVar6 & 0xffffffff;
              if (-1 < (int)uVar6) {
                iVar4 = MediaReadCapacity(param_1);
                if (-1 < iVar4) {
                  DeviceSetMediaChangeStateEx(lVar5,1,(int *)0x0);
                }
                uVar6 = DeviceInitializeDvd(param_1);
                uVar9 = uVar6 & 0xffffffff;
                if (-1 < (int)uVar6) {
                  if (*(undefined4 **)(lVar5 + 0x478) != (undefined4 *)0x0) {
                    **(undefined4 **)(lVar5 + 0x478) = *(undefined4 *)(lVar5 + 0x74);
                  }
                  if (*(char *)(lVar5 + 0x28a) != '\0') {
                    uVar3 = 0x104;
                    if (0x104 < *(uint *)(lVar5 + 0x78)) {
                      uVar3 = *(uint *)(lVar5 + 0x78);
                    }
                    *(uint *)(lVar5 + 0x78) = uVar3;
                  }
                  lVar7 = IoGetConfigurationInformation();
                  *(int *)(lVar7 + 8) = *(int *)(lVar7 + 8) + 1;
                  *(undefined1 *)(lVar5 + 8) = 1;
                  DeviceEnableMainTimer(lVar5);
                  if ((*(uint *)(*(longlong *)(lVar5 + 0x38) + 0x10) & 1) != 0) {
                    IoCreateArcName(*(undefined8 *)(lVar5 + 0x40));
                  }
                  local_res10[0] = local_res10[0] & 0xffffff00;
                  bVar2 = *(byte *)(*(longlong *)(lVar5 + 0x40) + 0x34);
                  uVar3 = DeviceIsPortable(lVar5,(undefined1 *)local_res10);
                  uVar9 = (ulonglong)uVar3;
                  if (-1 < (int)uVar3) {
                    if ((char)local_res10[0] == '\0') {
                      local_res18[0] = 0;
                    }
                    else {
                      puVar1 = (uint *)(*(longlong *)(lVar5 + 0x40) + 0x34);
                      *puVar1 = *puVar1 | 0x40000;
                      local_res18[0] = 0xff;
                    }
                    lVar7 = lVar5 + 0xb8;
                    uVar3 = IoSetDeviceInterfacePropertyData
                                      (lVar7,&DEVPKEY_Storage_Portable,0,0,CONCAT44(uVar10,0x11),
                                       CONCAT44(uVar12,1),local_res18);
                    uVar9 = (ulonglong)uVar3;
                    if (-1 < (int)uVar3) {
                      local_res20[0] = (bVar2 & 1 ^ 1) - 1;
                      uVar3 = IoSetDeviceInterfacePropertyData
                                        (lVar7,&DEVPKEY_Storage_Removable_Media,0,0,0x11,1,
                                         local_res20);
                      uVar9 = (ulonglong)uVar3;
                      if (-1 < (int)uVar3) {
                        local_38[0] = -((*(uint *)(*(longlong *)(lVar5 + 0x40) + 0x30) & 0x600100)
                                       != 0);
                        uVar3 = IoSetDeviceInterfacePropertyData
                                          (lVar7,&DEVPKEY_Storage_System_Critical,0,0,0x11,1,
                                           local_38);
                        uVar9 = (ulonglong)uVar3;
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
  }
  return uVar9;
}



===== DeviceEvtFileClose @ 14002dc40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void DeviceEvtFileClose(longlong param_1)

{
  int iVar1;
  undefined8 uVar2;
  longlong lVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined1 auStackY_d8 [32];
  undefined *in_stack_ffffffffffffff48;
  undefined2 local_98 [5];
  undefined1 local_8e;
  undefined4 local_84;
  undefined1 local_50;
  byte local_4c;
  ulonglong local_38;
  
  if (param_1 == 0) {
    return;
  }
  local_38 = __security_cookie ^ (ulonglong)auStackY_d8;
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x458))(WdfDriverGlobals,param_1);
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,uVar2,DAT_14001a0f0);
  puVar4 = (undefined8 *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  iVar1 = 0;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,9,0x24,
                        in_stack_ffffffffffffff48,(char)*(undefined8 *)(lVar3 + 0x10),(char)*puVar4,
                        (char)*(undefined4 *)(puVar4 + 2));
  }
  uVar5 = 0;
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals);
  if (*(int *)(puVar4 + 2) != 0) {
    *(int *)(lVar3 + 0xf0) = *(int *)(lVar3 + 0xf0) - *(int *)(puVar4 + 2);
    *(undefined4 *)(puVar4 + 2) = 0;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar5 = 9;
      in_stack_ffffffffffffff48 = &WPP_d2ddb5c132d1335dbff1b624de01ec23_Traceguids;
      WPP_RECORDER_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,9,0x25,
                         &WPP_d2ddb5c132d1335dbff1b624de01ec23_Traceguids,
                         (char)*(undefined4 *)(lVar3 + 0xf0),(char)*(undefined4 *)(lVar3 + 0xec));
    }
    if ((*(int *)(lVar3 + 0xf0) == 0) && (*(int *)(lVar3 + 0xec) == 0)) {
      memset(local_98,0,0x58);
      local_84 = *(undefined4 *)(lVar3 + 0x78);
      local_4c = local_4c & 0xfe;
      uVar5 = 0;
      local_8e = 6;
      local_50 = 0x1e;
      in_stack_ffffffffffffff48 =
           (undefined *)((ulonglong)in_stack_ffffffffffffff48 & 0xffffffffffffff00);
      iVar1 = DeviceSendSrbSynchronously(*(undefined8 *)(lVar3 + 0x10),local_98,0,0,'\0',0);
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        in_stack_ffffffffffffff48 = &WPP_d2ddb5c132d1335dbff1b624de01ec23_Traceguids;
        uVar5 = 9;
        WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,9,0x26,
                          &WPP_d2ddb5c132d1335dbff1b624de01ec23_Traceguids,(char)iVar1);
      }
    }
  }
  uVar6 = *(undefined8 *)(lVar3 + 0x110);
  (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14002dd81;
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar6,uVar5,0x21,
                       in_stack_ffffffffffffff48,(char)uVar2,(char)iVar1);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,9,0x27,
                        in_stack_ffffffffffffff48,(char)*(undefined8 *)(lVar3 + 0x10),(char)*puVar4,
                        (char)*(undefined4 *)((longlong)puVar4 + 0x14));
  }
LAB_14002dd81:
  iVar1 = *(int *)((longlong)puVar4 + 0x14);
  while (iVar1 != 0) {
    DeviceEnableMediaChangeDetection(lVar3,(longlong)puVar4);
    iVar1 = *(int *)((longlong)puVar4 + 0x14);
  }
  if ((*(longlong *)(lVar3 + 0x378) != 0) && (*(longlong *)(lVar3 + 0x378) == param_1)) {
    uVar6 = 0;
    uVar5 = DeviceUnlockExclusive(lVar3,param_1,'\0');
    if (((int)uVar5 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_1,uVar6,0x23,
                         in_stack_ffffffffffffff48,(char)uVar2,(char)uVar5);
    }
  }
  return;
}



===== CreateQueueEvtIoDefault @ 14002dfe0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void CreateQueueEvtIoDefault(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  longlong *plVar6;
  undefined8 uVar7;
  
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x8a8))(WdfDriverGlobals);
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,lVar4,DAT_14001a0f0);
  if (lVar3 == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,0x20,
                       &WPP_d2ddb5c132d1335dbff1b624de01ec23_Traceguids);
    }
    iVar2 = -0x3fffff1b;
    uVar7 = 0;
    goto LAB_14002e157;
  }
  plVar6 = (longlong *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,lVar3,PTR__WDF_FILE_OBJECT_CONTEXT_TYPE_INFO_14001a090);
  *plVar6 = lVar3;
  plVar6[2] = 0;
  *(undefined2 *)(plVar6 + 3) = 0;
  plVar6[1] = lVar4;
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,lVar4,DAT_14001a0f0);
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_CDROM_REQUEST_CONTEXT_TYPE_INFO_14001a018);
  (**(code **)(WdfFunctions_01015 + 0x7d8))(WdfDriverGlobals,param_2);
  if (*(longlong *)(lVar4 + 8) == 0) {
LAB_14002e116:
    iVar2 = RequestSend(lVar3,param_2,*(undefined8 *)(lVar3 + 0x18),2,(char *)0x0);
  }
  else {
    cVar1 = (**(code **)(WdfFunctions_01015 + 0x808))(WdfDriverGlobals);
    if (cVar1 == '\0') goto LAB_14002e116;
    iVar2 = -0x3ffffee0;
  }
  uVar7 = (**(code **)(WdfFunctions_01015 + 0x8a0))(WdfDriverGlobals,param_2);
LAB_14002e157:
  RequestCompletion(lVar5,param_2,iVar2,uVar7);
  return;
}



===== DeviceSendRequestSynchronously @ 14002e200 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 DeviceSendRequestSynchronously(undefined8 param_1,undefined8 param_2,char param_3)

{
  char cVar1;
  undefined4 uVar2;
  longlong lVar3;
  longlong lVar4;
  
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1,DAT_14001a0f0);
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_CDROM_REQUEST_CONTEXT_TYPE_INFO_14001a018);
  if (param_3 == '\0') {
    (**(code **)(WdfFunctions_01015 + 0x7d8))(WdfDriverGlobals,param_2);
  }
  if ((*(longlong *)(lVar4 + 8) == 0) ||
     (cVar1 = (**(code **)(WdfFunctions_01015 + 0x808))(WdfDriverGlobals), cVar1 == '\0')) {
    uVar2 = RequestSend(lVar3,param_2,*(undefined8 *)(lVar3 + 0x18),2,(char *)0x0);
    return uVar2;
  }
  return 0xc0000120;
}



===== RequestHandleScsiPassThrough @ 14002e300 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int RequestHandleScsiPassThrough(undefined8 param_1,ulonglong param_2)

{
  code *pcVar1;
  code *pcVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 uVar6;
  char *pcVar7;
  longlong lVar8;
  longlong lVar9;
  ulonglong uVar10;
  bool bVar11;
  
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1,DAT_14001a0f0);
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals,param_2);
  pcVar7 = *(char **)(lVar4 + 0x120);
  bVar11 = false;
  lVar8 = *(longlong *)(*(longlong *)(lVar4 + 0x38) + 0x18);
  if ((((pcVar7 != (char *)0x0) && (*pcVar7 == '\x01')) && (pcVar7[1] == '\0')) &&
     ((pcVar7 = (char *)RequestGetScsiPassThroughCdb(lVar5), pcVar7 != (char *)0x0 &&
      (*pcVar7 == '\x1b')))) {
    bVar11 = (pcVar7[4] & 3U) == 2;
  }
  (**(code **)(WdfFunctions_01015 + 0x7d8))(WdfDriverGlobals,param_2);
  *(undefined1 *)(*(longlong *)(lVar5 + 0xb8) + -0x47) = 1;
  pcVar1 = *(code **)(lVar8 + 0x18);
  pcVar2 = *(code **)(lVar8 + 0x10);
  if (pcVar1 != (code *)0x0) {
    (*pcVar1)(lVar5);
  }
  if (pcVar2 == (code *)0x0) {
    uVar10 = param_2;
    iVar3 = RequestSend(lVar4,param_2,*(undefined8 *)(lVar4 + 0x18),2,(char *)0x0);
  }
  else {
    lVar8 = KeQueryPerformanceCounter(0);
    iVar3 = RequestSend(lVar4,param_2,*(undefined8 *)(lVar4 + 0x18),2,(char *)0x0);
    lVar9 = KeQueryPerformanceCounter(0);
    uVar10 = (ulonglong)*(uint *)(lVar4 + 0x68);
    (*pcVar2)(0,uVar10,lVar5,lVar9 - lVar8);
  }
  if ((iVar3 < 0) && (bVar11)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar10 = CONCAT71((int7)(uVar10 >> 8),4);
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,3,0x31,
                       &WPP_7cea3eca420c34d4f6f4315c54c616a1_Traceguids);
    }
    DeviceMarkActive(lVar4,(longlong *)CONCAT71((int7)(uVar10 >> 8),1),(uint *)0x0);
  }
  uVar6 = (**(code **)(WdfFunctions_01015 + 0x8a0))(WdfDriverGlobals,param_2);
  RequestCompletion(lVar4,param_2,iVar3,uVar6);
  return iVar3;
}



===== SenseInfoInterpretRefineByIoControl @ 14002e540 =====

void SenseInfoInterpretRefineByIoControl
               (longlong param_1,int param_2,char param_3,undefined1 *param_4,int *param_5)

{
  if (((param_2 == 0x24054) ||
      (((param_2 - 0x24000U < 0x39 &&
        ((0x100000000100001U >> ((ulonglong)(param_2 - 0x24000U) & 0x3f) & 1) != 0)) ||
       (param_2 == 0x24058)))) && (*param_5 == -0x3fffffc4)) {
    *param_5 = 0;
    *param_4 = 0;
  }
  if (param_2 == 0x2402c) {
    *(undefined1 *)(param_1 + 0x350) = 0;
  }
  if ((param_3 != '\0') && (*param_5 == -0x7fffffea)) {
    *param_5 = -0x3ffffe7b;
    *param_4 = 1;
    if (((param_2 == 0x24800) || ((param_2 == 0x2d4800 || (param_2 == 0x2d0800)))) ||
       (param_2 == 0x74800)) {
      MediaReadCapacity(*(undefined8 *)(param_1 + 0x10));
    }
  }
  if (((param_2 == 0x24060) && (*param_5 < 0)) &&
     (*(undefined1 *)(param_1 + 0x3c0) = 0,
     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x3a,
                     &WPP_14ceea506f553d1aa69114b6e3475b08_Traceguids);
  }
  return;
}



===== DeviceScanForSpecial @ 14002e670 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void DeviceScanForSpecial(longlong param_1,undefined8 *param_2,undefined *param_3)

{
  longlong lVar1;
  bool bVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  char local_res10 [8];
  
  if ((param_2 != (undefined8 *)0x0) && (local_res10[0] = '\0', param_3 != (undefined *)0x0)) {
    lVar1 = *(longlong *)(param_1 + 200);
    pcVar5 = (char *)(lVar1 + (ulonglong)*(uint *)(lVar1 + 0xc));
    if (0xfffffffd < *(uint *)(lVar1 + 0xc) - 1) {
      pcVar5 = local_res10;
    }
    pcVar3 = (char *)(lVar1 + (ulonglong)*(uint *)(lVar1 + 0x10));
    if (0xfffffffd < *(uint *)(lVar1 + 0x10) - 1) {
      pcVar3 = local_res10;
    }
    pcVar4 = (char *)(lVar1 + (ulonglong)*(uint *)(lVar1 + 0x14));
    if (0xfffffffd < *(uint *)(lVar1 + 0x14) - 1) {
      pcVar4 = local_res10;
    }
    while( true ) {
      if ((((char *)*param_2 == (char *)0x0) && (param_2[1] == 0)) && (param_2[2] == 0)) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return;
        }
        WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,9,0x22,
                          &WPP_c6cef56efab5359de7c6f40b77738682_Traceguids,
                          (char)*(undefined8 *)(param_1 + 0x40));
        return;
      }
      bVar2 = StringsAreMatched((char *)*param_2,pcVar5);
      if (((bVar2) && (bVar2 = StringsAreMatched((char *)param_2[1],pcVar3), bVar2)) &&
         (bVar2 = StringsAreMatched((char *)param_2[2],pcVar4), bVar2)) break;
      param_2 = param_2 + 4;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sss(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
    (*(code *)param_3)(param_1,param_2[3]);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,9,0x21,
                       &WPP_c6cef56efab5359de7c6f40b77738682_Traceguids);
    }
  }
  return;
}



===== StringsAreMatched @ 14002e810 =====

bool StringsAreMatched(char *param_1,char *param_2)

{
  int iVar1;
  longlong lVar2;
  size_t _MaxCount;
  bool bVar3;
  
  if (param_1 == (char *)0x0) {
    bVar3 = true;
  }
  else {
    lVar2 = -1;
    _MaxCount = 0xffffffffffffffff;
    do {
      _MaxCount = _MaxCount + 1;
    } while (param_1[_MaxCount] != '\0');
    if (_MaxCount == 0) {
      do {
        lVar2 = lVar2 + 1;
      } while (param_2[lVar2] != '\0');
      bVar3 = lVar2 == 0;
    }
    else {
      iVar1 = strncmp(param_1,param_2,_MaxCount);
      bVar3 = iVar1 == 0;
    }
  }
  return bVar3;
}



===== DeviceRetrieveDescriptor @ 14002e860 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x00014002e9c2) */
/* WARNING: Removing unreachable block (ram,0x00014002e9d0) */
/* WARNING: Removing unreachable block (ram,0x00014002e9d4) */
/* WARNING: Removing unreachable block (ram,0x00014002ea2e) */
/* WARNING: Removing unreachable block (ram,0x00014002eaf4) */
/* WARNING: Removing unreachable block (ram,0x00014002eaa3) */
/* WARNING: Removing unreachable block (ram,0x00014002eab3) */
/* WARNING: Removing unreachable block (ram,0x00014002eadf) */
/* WARNING: Removing unreachable block (ram,0x00014002e9ea) */
/* WARNING: Removing unreachable block (ram,0x00014002e9fa) */
/* WARNING: Removing unreachable block (ram,0x00014002ea24) */

ulonglong DeviceRetrieveDescriptor(undefined8 param_1,uint *param_2,undefined8 *param_3)

{
  uint uVar1;
  longlong lVar2;
  ulonglong uVar3;
  
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1,DAT_14001a0f0);
  *param_3 = 0;
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x5d0))
                    (WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x18),0,0x2d1400);
  uVar3 = (ulonglong)uVar1;
  if ((int)uVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,9,0x1c,
                        &WPP_c6cef56efab5359de7c6f40b77738682_Traceguids,(char)uVar1);
    }
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,9,0x1d,
                        &WPP_c6cef56efab5359de7c6f40b77738682_Traceguids,(char)uVar1);
    }
    uVar3 = 0xc0000001;
  }
  return uVar3;
}



===== DeviceInitializeGesn @ 14002eb28 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint DeviceInitializeGesn(longlong param_1)

{
  byte *pbVar1;
  longlong lVar2;
  undefined *puVar3;
  int iVar4;
  longlong lVar5;
  ulonglong uVar6;
  longlong lVar7;
  byte bVar8;
  int iVar9;
  uint uVar10;
  undefined2 uVar11;
  uint uVar12;
  uint uVar13;
  char local_res8 [8];
  uint local_res10 [2];
  int local_res18 [2];
  undefined1 uVar14;
  
  lVar7 = *(longlong *)(param_1 + 200);
  lVar2 = *(longlong *)(param_1 + 0x118);
  local_res8[0] = '\x01';
  local_res10[0] = 0;
  local_res18[0] = 0;
  uVar12 = 0;
  DeviceGetParameter(param_1,0x140015260,L"MMCDetectionState",local_res18);
  if (local_res18[0] == 1) {
    local_res10[0] = 0xc00000bb;
  }
  uVar10 = local_res10[0];
  if (-1 < (int)local_res10[0]) {
    if ((*(byte *)(*(longlong *)(param_1 + 0x478) + 0x10) & 2) != 0) {
      DeviceSetParameter(param_1,0x140015260,L"MMCDetectionState",1);
      local_res10[0] = 0xc00000bb;
    }
    uVar10 = local_res10[0];
    if (-1 < (int)local_res10[0]) {
      lVar5 = *(longlong *)(lVar2 + 0x60);
      if (lVar5 == 0) {
        lVar5 = ExAllocatePool2(0x48,8,0x47436353);
        *(longlong *)(lVar2 + 0x60) = lVar5;
      }
      if (lVar5 == 0) {
        local_res10[0] = 0xc000009a;
      }
      if (-1 < (int)local_res10[0]) {
        if (*(longlong *)(lVar2 + 0x68) != 0) {
          IoFreeMdl();
        }
        lVar5 = IoAllocateMdl(*(undefined8 *)(lVar2 + 0x60),8,0,0,0);
        *(longlong *)(lVar2 + 0x68) = lVar5;
        if (lVar5 == 0) {
          local_res10[0] = 0xc000009a;
        }
        if (-1 < (int)local_res10[0]) {
          MmBuildMdlForNonPagedPool(*(undefined8 *)(lVar2 + 0x68));
          *(undefined4 *)(lVar2 + 0x70) = 8;
          uVar13 = 0;
          *(undefined1 *)(lVar2 + 0x5a) = 0;
          uVar6 = (ulonglong)local_res10[0];
          do {
            uVar10 = (uint)uVar6;
            if ((0xf < uVar13) || (local_res8[0] == '\0')) goto LAB_14002f0c2;
            uVar6 = RequestSetupMcnRequest(param_1,'\x01');
            local_res10[0] = (uint)uVar6;
            if ((int)local_res10[0] < 0) {
              uVar10 = local_res10[0];
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                uVar11 = 0x27;
LAB_14002f157:
                uVar14 = (undefined1)*(undefined8 *)(param_1 + 0x10);
LAB_14002f164:
                bVar8 = 3;
                uVar12 = local_res10[0];
LAB_14002f166:
                WPP_RECORDER_SF_Dq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),bVar8,0xd,uVar11,
                                   &WPP_bfcef3ce16aa3c5196ed71474c974d5c_Traceguids,(char)uVar12,
                                   uVar14);
                uVar10 = local_res10[0];
              }
              goto LAB_14002f0c9;
            }
            local_res10[0] =
                 DeviceSendRequestSynchronously
                           (*(undefined8 *)(param_1 + 0x10),*(undefined8 *)(lVar2 + 0x80),'\x01');
            if ((*(byte *)(lVar2 + 0x8b) & 0x3f) != 1) {
              if ((*(byte *)(lVar2 + 0x8b) & 0x40) != 0) {
                DeviceReleaseQueue(*(undefined8 *)(param_1 + 0x10));
              }
              RequestSenseInfoInterpret
                        (param_1,*(undefined8 *)(lVar2 + 0x80),(undefined8 *)(lVar2 + 0x88),0,
                         (undefined **)local_res10,(undefined8 *)0x0);
            }
            if (((*(int *)(lVar7 + 0x1c) == 2) && (*(char *)(lVar2 + 0x8b) == '\x0e')) &&
               (uVar12 = uVar12 + 1, 3 < uVar12)) {
              local_res10[0] = 0xc0000185;
              break;
            }
            if (local_res10[0] == 0xc000003c) {
              local_res10[0] = 0;
            }
            if (((local_res10[0] == 0xc0000010) || (local_res10[0] == 0x102)) ||
               ((local_res10[0] == 0xc0000185 || (local_res10[0] == 0xc00000b5)))) {
              DeviceSetParameter(param_1,0x140015260,L"MMCDetectionState",1);
              if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
              goto LAB_14002f0bf;
              uVar14 = (undefined1)*(undefined8 *)(param_1 + 0x10);
              uVar11 = 0x28;
              goto LAB_14002f164;
            }
            if ((int)local_res10[0] < 0) {
              uVar10 = local_res10[0];
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                uVar11 = 0x29;
                goto LAB_14002f157;
              }
              goto LAB_14002f0c9;
            }
            puVar3 = *(undefined **)(lVar2 + 0x60);
            if (uVar13 == 0) {
              pbVar1 = puVar3 + 3;
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,0xd,0x2a,
                                   &WPP_bfcef3ce16aa3c5196ed71474c974d5c_Traceguids,
                                   (char)*(undefined8 *)(param_1 + 0x10),*pbVar1);
              }
              if (((*pbVar1 & 0x10) != 0) &&
                 ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,0xd,0x2b,
                                 &WPP_bfcef3ce16aa3c5196ed71474c974d5c_Traceguids);
              }
              if (((*pbVar1 & 0x40) != 0) &&
                 ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,0xd,0x2c,
                                 &WPP_bfcef3ce16aa3c5196ed71474c974d5c_Traceguids);
              }
              if ((*pbVar1 & 2) != 0) {
                if ((*(byte *)(*(longlong *)(param_1 + 0x478) + 0x10) & 0x10) == 0) {
                  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,0xd,0x2e,
                                     &WPP_bfcef3ce16aa3c5196ed71474c974d5c_Traceguids);
                  }
                }
                else {
                  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,0xd,0x2d,
                                     &WPP_bfcef3ce16aa3c5196ed71474c974d5c_Traceguids);
                  }
                  puVar3[3] = puVar3[3] & 0xfd;
                }
              }
              bVar8 = puVar3[3] & 0x5a;
              *(byte *)(lVar2 + 0x5a) = bVar8;
              if (bVar8 != 0) {
                iVar4 = 0;
                do {
                  iVar9 = iVar4;
                  bVar8 = bVar8 & bVar8 - 1;
                  iVar4 = iVar9 + 1;
                } while (bVar8 != 0);
                if (iVar9 + 1 == 1) {
                  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,iVar9 + 0xd,
                                      (short)iVar9 + 0x30,
                                      &WPP_bfcef3ce16aa3c5196ed71474c974d5c_Traceguids,
                                      (char)*(undefined8 *)(param_1 + 0x40));
                  }
                }
                else {
                  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,0xd,0x31,
                                      &WPP_bfcef3ce16aa3c5196ed71474c974d5c_Traceguids,
                                      (char)*(undefined8 *)(param_1 + 0x40));
                  }
                  *(undefined1 *)(lVar2 + 0x59) = 1;
                }
                uVar6 = (ulonglong)local_res10[0];
                goto LAB_14002ef99;
              }
              if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
              goto LAB_14002f0bf;
              uVar14 = (undefined1)*(undefined8 *)(param_1 + 0x40);
              uVar11 = 0x2f;
              bVar8 = 4;
              uVar12 = (uint)(byte)puVar3[3];
              goto LAB_14002f166;
            }
            uVar6 = GesnDataInterpret(param_1,puVar3,local_res8);
            local_res10[0] = (uint)uVar6;
            uVar6 = uVar6 & 0xffffffff;
            if ((int)local_res10[0] < 0) goto LAB_14002f0a3;
LAB_14002ef99:
            uVar13 = uVar13 + 1;
          } while( true );
        }
      }
      uVar10 = local_res10[0];
    }
  }
LAB_14002efb0:
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,0xd,0x34,
                       &WPP_bfcef3ce16aa3c5196ed71474c974d5c_Traceguids,
                       (char)*(undefined8 *)(param_1 + 0x10),(char)uVar10);
  }
  if (*(longlong *)(lVar2 + 0x68) != 0) {
    lVar7 = (**(code **)(WdfFunctions_01015 + 0x8e8))
                      (WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x80));
    IoFreeMdl(*(undefined8 *)(lVar2 + 0x68));
    *(undefined8 *)(lVar2 + 0x68) = 0;
    *(undefined8 *)(lVar7 + 8) = 0;
  }
  if (*(longlong *)(lVar2 + 0x60) != 0) {
    ExFreePoolWithTag(*(longlong *)(lVar2 + 0x60),0);
    *(undefined8 *)(lVar2 + 0x60) = 0;
  }
  *(undefined1 *)(lVar2 + 0x58) = 0;
  *(undefined1 *)(lVar2 + 0x5a) = 0;
  *(undefined4 *)(lVar2 + 0x70) = 0;
  return local_res10[0];
LAB_14002f0a3:
  DeviceSetParameter(param_1,0x140015260,L"MMCDetectionState",1);
LAB_14002f0bf:
  uVar10 = local_res10[0];
LAB_14002f0c2:
LAB_14002f0c9:
  if (-1 < (int)uVar10) {
    if ((*(byte *)(lVar2 + 0x5a) & 0x10) == 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,0xd,0x33,
                          &WPP_bfcef3ce16aa3c5196ed71474c974d5c_Traceguids,
                          (char)*(undefined8 *)(param_1 + 0x10));
      }
      local_res10[0] = 0xc00000bb;
    }
    else {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,0xd,0x32,
                          &WPP_bfcef3ce16aa3c5196ed71474c974d5c_Traceguids,
                          (char)*(undefined8 *)(param_1 + 0x10));
      }
      *(undefined1 *)(lVar2 + 0x58) = 1;
      DeviceSetParameter(param_1,0x140015260,L"MMCDetectionState",2);
    }
    uVar10 = local_res10[0];
    if (-1 < (int)local_res10[0]) {
      return local_res10[0];
    }
  }
  goto LAB_14002efb0;
}



===== DeviceGetParameter @ 14002f254 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void DeviceGetParameter(longlong param_1,longlong param_2,undefined8 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  int iVar2;
  longlong lVar3;
  longlong local_res8;
  longlong local_res10;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  
  local_res8 = 0;
  local_res10 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  RtlInitUnicodeString(&local_38,param_3);
  if (param_2 != 0) {
    RtlInitUnicodeString(&local_48,param_2);
  }
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x180))
                    (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x10),1,0x20019,0,&local_res8);
  if (-1 < iVar2) {
    if ((param_2 == 0) ||
       (iVar2 = (**(code **)(WdfFunctions_01015 + 0x728))
                          (WdfDriverGlobals,local_res8,&local_48,0x20019,0,&local_res10), -1 < iVar2
       )) {
      if (local_res8 != 0) {
        uVar1 = *param_4;
        lVar3 = local_res8;
        if (local_res10 != 0) {
          lVar3 = local_res10;
        }
        iVar2 = (**(code **)(WdfFunctions_01015 + 0x780))(WdfDriverGlobals,lVar3,&local_38,param_4);
        if (iVar2 < 0) {
          *param_4 = uVar1;
        }
      }
    }
    else {
      (**(code **)(WdfFunctions_01015 + 0x738))(WdfDriverGlobals);
      local_res8 = 0;
    }
  }
  if (local_res10 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x738))(WdfDriverGlobals,local_res10);
    local_res10 = 0;
  }
  if (local_res8 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x738))(WdfDriverGlobals);
    local_res8 = 0;
  }
  if (-1 < iVar2) {
    return;
  }
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x180))
                    (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x10),2,0x20019,0,&local_res8);
  if (-1 < iVar2) {
    if ((param_2 == 0) ||
       (iVar2 = (**(code **)(WdfFunctions_01015 + 0x728))
                          (WdfDriverGlobals,local_res8,&local_48,0x20019,0,&local_res10), -1 < iVar2
       )) {
      if (local_res8 != 0) {
        uVar1 = *param_4;
        lVar3 = local_res8;
        if (local_res10 != 0) {
          lVar3 = local_res10;
        }
        iVar2 = (**(code **)(WdfFunctions_01015 + 0x780))(WdfDriverGlobals,lVar3,&local_38,param_4);
        if (iVar2 < 0) {
          *param_4 = uVar1;
        }
        else {
          DeviceSetParameter(param_1,param_2,param_3,*param_4);
        }
      }
    }
    else {
      (**(code **)(WdfFunctions_01015 + 0x738))(WdfDriverGlobals,local_res8);
      local_res8 = 0;
    }
  }
  if (local_res10 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x738))(WdfDriverGlobals);
    local_res10 = 0;
  }
  if (local_res8 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x738))(WdfDriverGlobals);
  }
  return;
}



===== DeviceMediaChangeDeviceInstanceOverride @ 14002f568 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 DeviceMediaChangeDeviceInstanceOverride(longlong param_1,undefined1 *param_2)

{
  int iVar1;
  char *pcVar2;
  longlong lVar3;
  undefined2 uVar4;
  int local_res8 [2];
  int local_res18 [2];
  longlong local_res20;
  longlong local_68 [8];
  
  local_68[0] = 0;
  local_res20 = 0;
  local_res18[0] = 0;
  local_res8[0] = 0;
  local_68[1] = 0;
  local_68[2] = 0;
  local_68[3] = 0;
  local_68[4] = 0;
  local_68[5] = 0;
  local_68[6] = 0;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x180))
                    (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x10),1,0xf003f,0,local_68);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,0xd,0x3a,
                        &WPP_bfcef3ce16aa3c5196ed71474c974d5c_Traceguids,(char)iVar1);
LAB_14002f67e:
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,0xd,0x3b,
                          &WPP_bfcef3ce16aa3c5196ed71474c974d5c_Traceguids,(char)iVar1);
      }
    }
  }
  else {
    RtlInitUnicodeString(local_68 + 1,L"MediaChangeNotification");
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x728))
                      (WdfDriverGlobals,local_68[0],local_68 + 1,0x20019,0,&local_res20);
    if (iVar1 < 0) goto LAB_14002f67e;
    RtlInitUnicodeString(local_68 + 3,L"AlwaysEnableMCN");
    RtlInitUnicodeString(local_68 + 5,L"AlwaysDisableMCN");
    (**(code **)(WdfFunctions_01015 + 0x780))(WdfDriverGlobals,local_res20,local_68 + 3,local_res18)
    ;
    (**(code **)(WdfFunctions_01015 + 0x780))(WdfDriverGlobals,local_res20,local_68 + 5,local_res8);
  }
  if (local_res20 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x738))(WdfDriverGlobals);
  }
  lVar3 = local_68[0];
  if (local_68[0] != 0) {
    (**(code **)(WdfFunctions_01015 + 0x738))(WdfDriverGlobals);
  }
  if (local_res18[0] == 0) {
    if (local_res8[0] == 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar3,0xd,0x3f,
                          &WPP_bfcef3ce16aa3c5196ed71474c974d5c_Traceguids,"DEFAULT");
      }
      return 0xc0000001;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14002f80c;
    uVar4 = 0x3d;
    pcVar2 = "DISABLE";
  }
  else {
    if (local_res8[0] == 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar3,0xd,0x3e,
                          &WPP_bfcef3ce16aa3c5196ed71474c974d5c_Traceguids,"ENABLE");
      }
      *param_2 = 1;
      return 0;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14002f80c;
    uVar4 = 0x3c;
    pcVar2 = "Both Enable and Disable set -- DISABLE";
  }
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar3,0xd,uVar4,
                    &WPP_bfcef3ce16aa3c5196ed71474c974d5c_Traceguids,pcVar2);
LAB_14002f80c:
  *param_2 = 0;
  return 0;
}



===== WppLoadTracingSupport @ 14002f86c =====

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



===== DeviceEvtD0Exit @ 14002f9b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 DeviceEvtD0Exit(undefined8 param_1,int param_2)

{
  uint *puVar1;
  longlong lVar2;
  int iVar3;
  longlong lVar4;
  
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  lVar2 = *(longlong *)(lVar4 + 0x120);
  if (param_2 - 4U < 2) {
    DeviceDisableMainTimer(lVar4);
    if ((*(char *)(lVar4 + 8) != '\0') && (*(char *)(lVar4 + 10) == '\0')) {
      *(undefined1 *)(lVar4 + 0x270) = 1;
      iVar3 = PowerContextBeginUse(lVar4);
      *(uint *)(lVar4 + 0x1ec) = *(uint *)(lVar4 + 0x1ec) | 1;
      if ((-1 < iVar3) && (param_2 != 5)) {
        iVar3 = DeviceSendPowerDownProcessRequest(lVar4,0,0);
        if (-1 < iVar3) {
          *(uint *)(lVar4 + 0x1ec) = *(uint *)(lVar4 + 0x1ec) | 2;
        }
        iVar3 = 0;
      }
      *(int *)(lVar4 + 0x1e8) = *(int *)(lVar4 + 0x1e8) + 1;
      if ((-1 < iVar3) && (param_2 != 5)) {
        DeviceSendPowerDownProcessRequest(lVar4,0,0);
        iVar3 = 0;
      }
      *(int *)(lVar4 + 0x1e8) = *(int *)(lVar4 + 0x1e8) + 1;
      if ((-1 < iVar3) && (*(char *)(lVar4 + 0x28b) != '\0')) {
        DeviceSendPowerDownProcessRequest(lVar4,0,0);
        iVar3 = 0;
      }
      *(int *)(lVar4 + 0x1e8) = *(int *)(lVar4 + 0x1e8) + 1;
      if ((-1 < iVar3) && ((*(uint *)(lVar4 + 0x70) & 1) == 0)) {
        DeviceSendPowerDownProcessRequest(lVar4,0,0);
      }
      if (param_2 == 5) {
        PowerContextEndUse(lVar4);
      }
      puVar1 = (uint *)(*(longlong *)(lVar4 + 0x40) + 0x30);
      *puVar1 = *puVar1 | 2;
      LOCK();
      *(int *)(lVar4 + 0x148) = *(int *)(lVar4 + 0x148) + 1;
      UNLOCK();
      if ((lVar2 != 0) &&
         (*(undefined1 *)(lVar2 + 0x51) = 1,
         (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,3,0x1e,
                         &WPP_d2ddb5c132d1335dbff1b624de01ec23_Traceguids);
      }
      *(undefined1 *)(lVar4 + 0x270) = 0;
    }
  }
  return 0;
}



===== DeviceDisableMainTimer @ 14002fb30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void DeviceDisableMainTimer(longlong param_1)

{
  if ((*(char **)(param_1 + 0x118) != (char *)0x0) && (**(char **)(param_1 + 0x118) == '\0')) {
    if (*(longlong *)(param_1 + 0x30) == 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,0xd,0x55,
                         &WPP_bfcef3ce16aa3c5196ed71474c974d5c_Traceguids);
      }
    }
    else {
      (**(code **)(WdfFunctions_01015 + 0xa00))(WdfDriverGlobals,*(longlong *)(param_1 + 0x30),1);
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,0xd,0x54,
                          &WPP_bfcef3ce16aa3c5196ed71474c974d5c_Traceguids,
                          (char)*(undefined8 *)(param_1 + 0x10));
      }
    }
  }
  return;
}



===== WppCleanupKm @ 14002fc00 =====

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



===== DriverEvtDeviceAdd @ 14002fcb0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong DriverEvtDeviceAdd(undefined8 param_1,undefined8 param_2)

{
  undefined8 *puVar1;
  bool bVar2;
  undefined1 uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined8 uVar7;
  wchar_t *pwVar8;
  ulonglong uVar9;
  undefined4 *puVar10;
  undefined8 uVar11;
  ulonglong uVar12;
  uint uVar13;
  undefined2 uVar14;
  undefined8 local_res10;
  undefined8 local_res18;
  int local_res20 [2];
  undefined8 in_stack_fffffffffffffd50;
  undefined4 uVar15;
  ulonglong local_298;
  code *pcStack_290;
  undefined8 local_288;
  undefined8 uStack_280;
  undefined8 local_278;
  undefined8 uStack_270;
  undefined *local_268;
  undefined8 local_260;
  undefined4 local_258;
  undefined4 local_254;
  undefined8 local_250;
  code *pcStack_248;
  undefined8 local_240;
  undefined4 local_238;
  undefined4 local_234;
  undefined8 local_230;
  undefined8 uStack_228;
  undefined8 local_220;
  undefined8 uStack_218;
  undefined8 local_210;
  undefined8 uStack_208;
  undefined8 local_200;
  undefined8 local_1f8;
  undefined8 uStack_1f0;
  undefined4 local_1e8;
  undefined4 local_1e4;
  undefined4 local_1e0;
  undefined1 local_1dc;
  undefined1 local_1db;
  code *local_1d8;
  code *local_1d0;
  code *local_1c8;
  code *local_1c0;
  code *local_1a0;
  undefined4 local_198;
  undefined4 local_188;
  undefined4 local_184;
  undefined8 local_180;
  code *local_178;
  undefined8 local_170;
  undefined4 local_168;
  undefined4 local_164;
  undefined4 local_158;
  undefined4 local_154;
  code *local_150;
  code *local_140;
  code *local_120;
  code *local_110;
  code *local_f8;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined8 local_a8;
  
  uVar15 = (undefined4)((ulonglong)in_stack_fffffffffffffd50 >> 0x20);
  local_260 = 0;
  local_298 = (ulonglong)(uint)local_298;
  local_288 = 0;
  local_184 = 0;
  puVar10 = (undefined4 *)0x0;
  bVar2 = false;
  local_278 = 0;
  uStack_270 = 0;
  local_res10 = param_2;
  memset(&local_c8,0,0x88);
  memset(&local_1e8,0,0x60);
  local_res20[0] = -1;
  local_154 = 0;
  local_1f8 = 0;
  uStack_1f0 = 0;
  local_254 = 0;
  local_258 = 0;
  uVar7 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_CDROM_DRIVER_EXTENSION_TYPE_INFO_14001a0b8);
  RtlInitUnicodeString(&local_1f8);
  memset(&local_158,0,0x90);
  local_110 = DeviceEvtSelfManagedIoInit;
  local_150 = DeviceEvtD0Entry;
  local_140 = DeviceEvtD0Exit;
  local_120 = DeviceEvtSelfManagedIoCleanup;
  local_f8 = DeviceEvtSurpriseRemoval;
  local_158 = 0x90;
  (**(code **)(WdfFunctions_01015 + 0x1b8))(WdfDriverGlobals,local_res10,&local_158);
  (**(code **)(WdfFunctions_01015 + 0x250))(WdfDriverGlobals,local_res10,DeviceEvtIoInCallerContext)
  ;
  local_res18 = CONCAT71(local_res18._1_7_,2);
  uVar12 = CONCAT44(uVar15,1);
  uVar5 = (**(code **)(WdfFunctions_01015 + 0x248))
                    (WdfDriverGlobals,local_res10,RequestProcessSetPower,0x16,&local_res18,uVar12);
  uVar9 = (ulonglong)uVar5;
  if ((int)uVar5 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return uVar9;
    }
    uVar14 = 0xe;
LAB_14002ff41:
    WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,2,uVar14,
                      &WPP_d2ddb5c132d1335dbff1b624de01ec23_Traceguids,(char)uVar5);
    return uVar9;
  }
  uVar12 = uVar12 & 0xffffffff00000000;
  uVar5 = (**(code **)(WdfFunctions_01015 + 0x248))
                    (WdfDriverGlobals,local_res10,RequestProcessShutdownFlush,9,0,uVar12);
  uVar9 = (ulonglong)uVar5;
  if ((int)uVar5 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return uVar9;
    }
    uVar14 = 0xf;
    goto LAB_14002ff41;
  }
  uVar5 = (**(code **)(WdfFunctions_01015 + 0x248))
                    (WdfDriverGlobals,local_res10,RequestProcessShutdownFlush,0x10,0,
                     uVar12 & 0xffffffff00000000);
  uVar9 = (ulonglong)uVar5;
  if ((int)uVar5 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return uVar9;
    }
    uVar14 = 0x10;
    goto LAB_14002ff41;
  }
  local_268 = PTR__WDF_CDROM_REQUEST_CONTEXT_TYPE_INFO_14001a018;
  pcStack_290 = RequestEvtCleanup;
  local_298 = 0x38;
  local_288 = 0;
  local_278 = 0;
  uStack_270 = 0;
  uStack_280 = 0x100000001;
  (**(code **)(WdfFunctions_01015 + 0x240))(WdfDriverGlobals,local_res10,&local_298);
  local_268 = PTR__WDF_FILE_OBJECT_CONTEXT_TYPE_INFO_14001a090;
  local_288 = 0;
  local_178 = DeviceEvtFileClose;
  pcStack_290 = (code *)0x0;
  local_298 = 0x38;
  local_278 = 0;
  uStack_270 = 0;
  local_188 = 0x28;
  local_180 = 0;
  local_170 = 0;
  local_168 = 1;
  uStack_280 = 0x400000002;
  local_164 = 0x80000004;
  (**(code **)(WdfFunctions_01015 + 0x238))(WdfDriverGlobals,local_res10,&local_188,&local_298);
  (**(code **)(WdfFunctions_01015 + 0x1c8))(WdfDriverGlobals,local_res10,0);
  (**(code **)(WdfFunctions_01015 + 0x1f0))(WdfDriverGlobals,local_res10,0);
  (**(code **)(WdfFunctions_01015 + 0x210))(WdfDriverGlobals,local_res10,2);
  (**(code **)(WdfFunctions_01015 + 0x230))(WdfDriverGlobals,local_res10,1,0);
  (**(code **)(WdfFunctions_01015 + 0x1e8))(WdfDriverGlobals,local_res10,3);
  (**(code **)(WdfFunctions_01015 + 0x200))(WdfDriverGlobals,local_res10);
  local_238 = 8;
  local_234 = 1;
  (**(code **)(WdfFunctions_01015 + 0xc98))(WdfDriverGlobals,local_res10,&local_238);
  local_res18 = (**(code **)(WdfFunctions_01015 + 0x3e0))(WdfDriverGlobals,local_res10);
  local_268 = DAT_14001a0f0;
  local_298 = 0x38;
  pcStack_290 = DeviceEvtCleanup;
  local_288 = 0;
  local_278 = 0;
  uStack_270 = 0;
  uStack_280 = 0x400000003;
  pwVar8 = (wchar_t *)ExAllocatePool2(0x40,0x80,0x73436353);
  uVar5 = 0;
  if (pwVar8 == (wchar_t *)0x0) {
    return 0xc000009a;
  }
  do {
    uVar13 = uVar5;
    uVar9 = RtlStringCchPrintfW(pwVar8,0x40,L"\\Device\\CdRom%d",(ulonglong)uVar13);
    uVar4 = (uint)uVar9;
    uVar9 = uVar9 & 0xffffffff;
    if ((int)uVar4 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140030a34;
      uVar14 = 0x11;
      goto LAB_140030a0c;
    }
    RtlInitUnicodeString(&local_1f8,pwVar8);
    uVar4 = (**(code **)(WdfFunctions_01015 + 0x218))(WdfDriverGlobals,local_res10,&local_1f8);
    uVar9 = (ulonglong)uVar4;
    if ((int)uVar4 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140030a34;
      uVar14 = 0x12;
      goto LAB_140030a0c;
    }
    uVar4 = (**(code **)(WdfFunctions_01015 + 600))
                      (WdfDriverGlobals,&local_res10,&local_298,&local_260);
    uVar9 = (ulonglong)uVar4;
    uVar5 = uVar13 + 1;
  } while (uVar4 == 0xc0000035);
  if ((int)uVar4 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140030a34;
    uVar14 = 0x13;
LAB_140030a0c:
    uVar3 = (undefined1)uVar4;
    uVar4 = 2;
  }
  else {
    puVar10 = (undefined4 *)
              (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,local_260,DAT_14001a0f0);
    *puVar10 = 1;
    puVar10[1] = 0x4a0;
    uVar11 = (**(code **)(WdfFunctions_01015 + 0xf8))(WdfDriverGlobals,local_260);
    *(undefined8 *)(puVar10 + 0x10) = uVar11;
    *(undefined8 *)(puVar10 + 4) = local_260;
    *(undefined8 *)(puVar10 + 0x12) = local_res18;
    *(undefined8 *)(puVar10 + 0xe) = uVar7;
    puVar1 = (undefined8 *)(puVar10 + 6);
    puVar10[0x14] = 2;
    puVar10[0x1a] = uVar13;
    puVar10[0x16] = (undefined4)local_1f8;
    puVar10[0x17] = local_1f8._4_4_;
    puVar10[0x18] = (undefined4)uStack_1f0;
    puVar10[0x19] = uStack_1f0._4_4_;
    local_288 = 0;
    local_268 = (undefined *)0x0;
    pcStack_290 = (code *)0x0;
    local_298 = 0x38;
    uStack_270 = 0;
    uStack_280 = 0x100000001;
    local_278 = *(undefined8 *)(puVar10 + 4);
    uVar4 = (**(code **)(WdfFunctions_01015 + 0x538))
                      (WdfDriverGlobals,*(undefined8 *)(puVar10 + 4),&local_298,puVar1);
    uVar9 = (ulonglong)uVar4;
    if ((int)uVar4 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140030a34;
      uVar14 = 0x14;
      goto LAB_140030a0c;
    }
    local_a8 = (**(code **)(WdfFunctions_01015 + 0x100))
                         (WdfDriverGlobals,*(undefined8 *)(puVar10 + 4));
    local_c8 = 0x88;
    local_c4 = 1;
    uVar5 = (**(code **)(WdfFunctions_01015 + 0x540))(WdfDriverGlobals,*puVar1,&local_c8);
    uVar9 = (ulonglong)uVar5;
    if ((int)uVar5 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,2,0x15,
                          &WPP_d2ddb5c132d1335dbff1b624de01ec23_Traceguids,(char)uVar5);
      }
      (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,*puVar1);
      *puVar1 = 0;
      goto LAB_140030a34;
    }
    uVar5 = DeviceClaimRelease((longlong)puVar10,'\0');
    uVar9 = (ulonglong)uVar5;
    if ((int)uVar5 < 0) goto LAB_140030a34;
    local_1e0 = 0;
    local_1d0 = SequentialQueueEvtIoReadWrite;
    local_1c8 = SequentialQueueEvtIoReadWrite;
    bVar2 = true;
    local_1db = 1;
    local_1c0 = SequentialQueueEvtIoDeviceControl;
    local_1e8 = 0x60;
    local_1a0 = SequentialQueueEvtCanceledOnQueue;
    local_1e4 = 1;
    uVar5 = (**(code **)(WdfFunctions_01015 + 0x4c0))
                      (WdfDriverGlobals,local_260,&local_1e8,0,puVar10 + 8);
    uVar9 = (ulonglong)uVar5;
    if ((int)uVar5 < 0) goto LAB_140030a34;
    memset(&local_1e8,0,0x60);
    local_198 = 0xffffffff;
    local_1e0 = 0;
    local_1d8 = CreateQueueEvtIoDefault;
    local_288 = 0;
    local_268 = PTR__WDF_CDROM_REQUEST_CONTEXT_TYPE_INFO_14001a018;
    local_1e8 = 0x60;
    pcStack_290 = (code *)0x0;
    local_1e4 = 2;
    local_278 = 0;
    uStack_270 = 0;
    local_298 = 0x38;
    uStack_280 = 0x400000002;
    uVar5 = (**(code **)(WdfFunctions_01015 + 0x4c0))
                      (WdfDriverGlobals,local_260,&local_1e8,&local_298,puVar10 + 10);
    uVar9 = (ulonglong)uVar5;
    if ((int)uVar5 < 0) goto LAB_140030a34;
    uVar5 = (**(code **)(WdfFunctions_01015 + 0x2e8))
                      (WdfDriverGlobals,local_260,*(undefined8 *)(puVar10 + 10),0);
    uVar9 = (ulonglong)uVar5;
    if ((int)uVar5 < 0) goto LAB_140030a34;
    if (*(uint *)(*(longlong *)(puVar10 + 0x10) + 0x98) <
        *(uint *)(*(longlong *)(puVar10 + 0x12) + 0x98)) {
      (**(code **)(WdfFunctions_01015 + 0x1a8))(WdfDriverGlobals);
    }
    puVar10[0x2c] = 0;
    puVar10[0x2d] = 0;
    puVar10[0x24] = 0xb;
    puVar10[0x25] = 0x40;
    puVar10[0x26] = 0x20;
    *(undefined8 *)(puVar10 + 0xf2) = 0x7391d;
    puVar10[0x1d] = 8;
    uVar5 = DeviceGetTimeOutValueFromRegistry();
    puVar10[0x1e] = uVar5;
    if ((0x708 < uVar5) || (uVar5 == 0)) {
      uVar5 = 10;
      puVar10[0x1e] = 10;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,9,0x16,
                        &WPP_d2ddb5c132d1335dbff1b624de01ec23_Traceguids,(char)uVar5);
    }
    *(undefined1 *)((longlong)puVar10 + 0x271) = 1;
    memset(&local_1dc,0,0x54);
    local_1e0 = 0;
    local_1e8 = 0x60;
    local_1e4 = 3;
    uVar5 = (**(code **)(WdfFunctions_01015 + 0x4c0))
                      (WdfDriverGlobals,local_260,&local_1e8,0,puVar10 + 0x9e);
    uVar9 = (ulonglong)uVar5;
    if ((int)uVar5 < 0) goto LAB_140030a34;
    local_268 = (undefined *)0x0;
    local_288 = 0;
    pcStack_290 = (code *)0x0;
    local_298 = 0x38;
    uStack_270 = 0;
    uStack_280 = 0x100000001;
    local_278 = *(undefined8 *)(puVar10 + 4);
    uVar5 = (**(code **)(WdfFunctions_01015 + 0x9c0))(WdfDriverGlobals,&local_298,puVar10 + 0x44);
    puVar10[0x3b] = 0;
    uVar9 = (ulonglong)uVar5;
    if ((int)uVar5 < 0) goto LAB_140030a34;
    uVar12 = DeviceInitReleaseQueueContext((longlong)puVar10);
    uVar9 = uVar12 & 0xffffffff;
    if ((int)uVar12 < 0) goto LAB_140030a34;
    uVar12 = DeviceInitPowerContext((longlong)puVar10);
    uVar9 = uVar12 & 0xffffffff;
    if ((int)uVar12 < 0) goto LAB_140030a34;
    uVar12 = DeviceCreateWellKnownName((longlong)puVar10);
    uVar9 = uVar12 & 0xffffffff;
    if ((int)uVar12 < 0) goto LAB_140030a34;
    iVar6 = IoGetDevicePropertyData
                      (*(undefined8 *)(puVar10 + 0x12),&DEVPKEY_Device_SessionId,0,0,4,local_res20,
                       &local_254,&local_258);
    if (iVar6 < 0) {
      local_res20[0] = -1;
    }
    uVar5 = DeviceRegisterInterface((longlong)puVar10,0);
    uVar9 = (ulonglong)uVar5;
    if ((int)uVar5 < 0) goto LAB_140030a34;
    iVar6 = 1;
    if (local_res20[0] != -1) {
      iVar6 = 2;
    }
    uVar5 = DeviceRegisterInterface((longlong)puVar10,iVar6);
    uVar9 = (ulonglong)uVar5;
    if ((int)uVar5 < 0) goto LAB_140030a34;
    local_268 = (undefined *)0x0;
    local_288 = 0;
    pcStack_290 = (code *)0x0;
    local_298 = 0x38;
    uStack_270 = 0;
    uStack_280 = 0x100000001;
    local_278 = *(undefined8 *)(puVar10 + 4);
    uVar5 = (**(code **)(WdfFunctions_01015 + 0x9c0))(WdfDriverGlobals,&local_298,puVar10 + 0xa0);
    uVar9 = (ulonglong)uVar5;
    if ((int)uVar5 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140030a34;
      uVar14 = 0x17;
      uVar4 = 2;
    }
    else {
      local_240 = 1;
      local_250 = 0x18;
      pcStack_248 = ReadWriteWorkItemRoutine;
      local_200 = 0;
      local_220 = 0;
      uStack_218 = 0x100000001;
      local_210 = *(undefined8 *)(puVar10 + 4);
      uStack_208 = 0;
      uStack_228 = 0;
      local_230 = 0x38;
      uVar5 = (**(code **)(WdfFunctions_01015 + 0xbd8))
                        (WdfDriverGlobals,&local_250,&local_230,puVar10 + 0x120);
      uVar9 = (ulonglong)uVar5;
      if ((int)uVar5 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140030a34;
        uVar14 = 0x18;
      }
      else {
        local_240 = 1;
        local_250 = 0x18;
        pcStack_248 = IoctlWorkItemRoutine;
        local_200 = 0;
        local_210 = *(undefined8 *)(puVar10 + 4);
        local_220 = 0;
        uStack_208 = 0;
        uStack_228 = 0;
        local_230 = 0x38;
        uStack_218 = 0x100000001;
        uVar5 = (**(code **)(WdfFunctions_01015 + 0xbd8))
                          (WdfDriverGlobals,&local_250,&local_230,puVar10 + 0x124);
        uVar9 = (ulonglong)uVar5;
        if (-1 < (int)uVar5) {
          return uVar9;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140030a34;
        uVar14 = 0x19;
      }
      uVar4 = 9;
    }
    uVar3 = (undefined1)uVar5;
  }
  WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,uVar4,uVar14,
                    &WPP_d2ddb5c132d1335dbff1b624de01ec23_Traceguids,uVar3);
LAB_140030a34:
  ExFreePoolWithTag(pwVar8,0);
  if (puVar10 == (undefined4 *)0x0) {
    return uVar9;
  }
  RtlInitUnicodeString(puVar10 + 0x16,0);
  if (bVar2) {
    DeviceClaimRelease((longlong)puVar10,'\x01');
    return uVar9;
  }
  return uVar9;
}



===== DeviceInitializeMcn @ 140030a90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x000140030c5b) */

int DeviceInitializeMcn(longlong param_1,char param_2)

{
  uint uVar1;
  int iVar2;
  undefined1 *puVar3;
  longlong lVar4;
  longlong lVar5;
  char local_res10 [8];
  undefined4 local_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 local_58;
  undefined4 uStack_54;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined *local_38;
  
  local_38 = (undefined *)((ulonglong)local_38 & 0xffffffff00000000);
  local_68 = 0;
  uStack_64 = 0;
  uStack_60 = 0;
  uStack_5c = 0;
  local_58 = 0;
  uStack_54 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  if (*(longlong *)(param_1 + 0x118) != 0) {
    return 0;
  }
  *(undefined8 *)(param_1 + 0x138) = 0;
  *(undefined8 *)(param_1 + 0x128) = 0xffffffffffffffff;
  *(undefined8 *)(param_1 + 0x130) = 0xffffffffffffffff;
  local_res10[0] = param_2;
  puVar3 = (undefined1 *)ExAllocatePool2(0x40,0xf8,0x61436353);
  if (puVar3 == (undefined1 *)0x0) {
    iVar2 = -0x3fffff66;
  }
  else {
    if (((*(longlong *)(param_1 + 0xd8) != 0) &&
        (*(char *)(*(longlong *)(param_1 + 0xd8) + 9) != '\0')) &&
       ((*(byte *)(*(longlong *)(param_1 + 0x478) + 0x10) & 0x40) == 0)) {
      *puVar3 = 1;
    }
    lVar4 = IoAllocateIrp(CONCAT71((int7)((ulonglong)*(longlong *)(param_1 + 0x40) >> 8),
                                   *(undefined1 *)(*(longlong *)(param_1 + 0x40) + 0x4c)),0);
    if (lVar4 == 0) {
      iVar2 = -0x3fffff66;
    }
    else {
      local_38 = PTR__WDF_CDROM_REQUEST_CONTEXT_TYPE_INFO_14001a018;
      local_48 = *(undefined8 *)(param_1 + 0x10);
      uStack_64 = 0;
      uStack_60 = 0;
      uStack_5c = 0;
      local_58 = 0;
      uStack_54 = 0;
      uStack_40 = 0;
      local_68 = 0x38;
      uStack_50 = 0x100000001;
      iVar2 = (**(code **)(WdfFunctions_01015 + 0x7b8))
                        (WdfDriverGlobals,&local_68,*(undefined8 *)(param_1 + 0x18),puVar3 + 0x80);
      if ((-1 < iVar2) &&
         (iVar2 = (**(code **)(WdfFunctions_01015 + 0x5f8))
                            (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x18),
                             *(undefined8 *)(puVar3 + 0x80),0x1b0011,0,0,0,0,0,0), -1 < iVar2)) {
        lVar5 = ExAllocatePool2(0x48,0x12,0x61436353);
        if (lVar5 != 0) {
          *(longlong *)(puVar3 + 0x40) = lVar4;
          *(longlong *)(puVar3 + 0xe0) = lVar5;
          *(undefined8 *)(puVar3 + 0x4c) = 0;
          *(undefined4 *)(puVar3 + 0x48) = 0;
          *(undefined4 *)(puVar3 + 0xe8) = 0x10000108;
          KeInitializeMutex(puVar3 + 8,0x100);
          *(undefined1 **)(param_1 + 0x118) = puVar3;
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,0xd,0x24,
                             &WPP_bfcef3ce16aa3c5196ed71474c974d5c_Traceguids);
          }
          uVar1 = DeviceInitializeGesn(param_1);
          if ((int)uVar1 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,0xd,0x26,
                                &WPP_bfcef3ce16aa3c5196ed71474c974d5c_Traceguids,
                                (char)*(undefined8 *)(param_1 + 0x40));
            }
            puVar3[0x58] = 0;
          }
          else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,0xd,0x25,
                              &WPP_bfcef3ce16aa3c5196ed71474c974d5c_Traceguids,
                              (char)*(undefined8 *)(param_1 + 0x40));
          }
          if (*(longlong *)(puVar3 + 0xf0) != 0) {
            return iVar2;
          }
          local_res10[0] = '\0';
          iVar2 = ZwPowerInformation(0x42,0,0,local_res10,1);
          if ((-1 < iVar2) && (local_res10[0] != '\0')) {
            PoRegisterPowerSettingCallback
                      (*(undefined8 *)(param_1 + 0x40),&GUID_LOW_POWER_EPOCH,
                       DevicePowerSettingCallback,param_1,puVar3 + 0xf0);
          }
          return 0;
        }
        iVar2 = -0x3fffff66;
      }
      IoFreeIrp(lVar4);
    }
    ExFreePoolWithTag(puVar3,0);
  }
  return iVar2;
}



===== ScratchBuffer_Allocate @ 140030e00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

byte ScratchBuffer_Allocate(longlong param_1)

{
  uint uVar1;
  int iVar2;
  longlong lVar3;
  byte bVar4;
  undefined2 uVar5;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined *local_18;
  
  if (((((*(longlong *)(param_1 + 0x3f0) != 0) && (*(longlong *)(param_1 + 0x3f8) != 0)) &&
       (*(int *)(param_1 + 1000) != 0)) &&
      ((*(longlong *)(param_1 + 0x400) != 0 && (*(longlong *)(param_1 + 0x408) != 0)))) &&
     ((*(longlong *)(param_1 + 0x418) != 0 && (*(longlong *)(param_1 + 0x420) != 0)))) {
    return 1;
  }
  uVar1 = 0x10000;
  if (*(uint *)(param_1 + 0x368) < 0x10000) {
    uVar1 = *(uint *)(param_1 + 0x368);
  }
  *(uint *)(param_1 + 1000) = uVar1;
  lVar3 = ExAllocatePool2(0x40,uVar1,0x42436353);
  *(longlong *)(param_1 + 0x3f0) = lVar3;
  if (lVar3 == 0) {
    iVar2 = -0x3fffff66;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar5 = 10;
LAB_140030ebe:
      iVar2 = -0x3fffff66;
      bVar4 = 3;
LAB_140030ec0:
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),bVar4,9,uVar5,
                        &WPP_7774703dbdbe384c966e4c3ee8bb8942_Traceguids,
                        (char)*(undefined4 *)(param_1 + 1000));
    }
  }
  else if ((*(uint *)(param_1 + 0x3f0) & 0xfff) == 0) {
    lVar3 = IoAllocateMdl(lVar3,*(undefined4 *)(param_1 + 1000),0,0,0);
    *(longlong *)(param_1 + 0x3f8) = lVar3;
    if (lVar3 == 0) {
      iVar2 = -0x3fffff66;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar5 = 0xc;
        goto LAB_140030ebe;
      }
    }
    else {
      MmBuildMdlForNonPagedPool(lVar3);
      local_38 = 0;
      local_18 = PTR__WDF_CDROM_REQUEST_CONTEXT_TYPE_INFO_14001a018;
      uStack_40 = 0;
      local_48 = 0x38;
      local_28 = 0;
      uStack_20 = 0;
      uStack_30 = 0x100000001;
      iVar2 = (**(code **)(WdfFunctions_01015 + 0x7b8))
                        (WdfDriverGlobals,&local_48,*(undefined8 *)(param_1 + 0x18),
                         (longlong *)(param_1 + 0x400));
      if ((iVar2 < 0) || (*(longlong *)(param_1 + 0x400) == 0)) {
        iVar2 = -0x3fffff66;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar5 = 0xd;
LAB_140031183:
          iVar2 = -0x3fffff66;
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,9,uVar5,
                           &WPP_7774703dbdbe384c966e4c3ee8bb8942_Traceguids);
        }
      }
      else {
        lVar3 = ExAllocatePool2(0x40,0x58,0x42436353);
        *(longlong *)(param_1 + 0x408) = lVar3;
        if (lVar3 == 0) {
          iVar2 = -0x3fffff66;
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar5 = 0xe;
            goto LAB_140031183;
          }
        }
        else {
          lVar3 = ExAllocatePool2(0x40,0x12,0x42436353);
          *(longlong *)(param_1 + 0x410) = lVar3;
          if (lVar3 == 0) {
            iVar2 = -0x3fffff66;
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar5 = 0xf;
              goto LAB_140031183;
            }
          }
          else {
            lVar3 = ExAllocatePool2(0x40,0x348,0x42436353);
            *(longlong *)(param_1 + 0x418) = lVar3;
            if (lVar3 == 0) {
              iVar2 = -0x3fffff66;
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                uVar5 = 0x10;
                goto LAB_140031183;
              }
            }
            else {
              *(undefined4 *)(lVar3 + 0x20) = 0x14;
              uVar1 = *(uint *)(param_1 + 0x368) + 0x1000;
              if (uVar1 < *(uint *)(param_1 + 0x368)) {
                iVar2 = -0x3fffff6b;
              }
              else {
                iVar2 = 0;
                *(undefined1 *)(param_1 + 0x428) = 0;
                lVar3 = IoAllocateMdl(0,uVar1,0,0,0);
                *(longlong *)(param_1 + 0x420) = lVar3;
                if ((lVar3 == 0) &&
                   (iVar2 = -0x3fffff66,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                  WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,9,0x11,
                                    &WPP_7774703dbdbe384c966e4c3ee8bb8942_Traceguids,
                                    (char)*(undefined4 *)(param_1 + 1000));
                }
                if (-1 < iVar2) goto LAB_1400311af;
              }
            }
          }
        }
      }
    }
  }
  else {
    iVar2 = -0x3fffff1b;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar5 = 0xb;
      bVar4 = 1;
      goto LAB_140030ec0;
    }
  }
  ScratchBuffer_Deallocate(param_1);
LAB_1400311af:
  return (byte)((uint)iVar2 >> 0x1f) ^ 1;
}



===== DeviceInitializeMediaChangeDetection @ 1400311d4 =====

ulonglong DeviceInitializeMediaChangeDetection(longlong param_1,undefined8 param_2)

{
  char cVar1;
  bool bVar2;
  uint uVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  char *pcVar6;
  char *pcVar7;
  ulonglong uVar8;
  char *pcVar9;
  char local_res10 [8];
  
  local_res10[0] = '\0';
  uVar4 = DeviceIsMediaChangeDisabledDueToHardwareLimitation(param_1);
  if ((char)uVar4 != '\0') {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0;
    }
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,0xd,0x35,
                     &WPP_bfcef3ce16aa3c5196ed71474c974d5c_Traceguids);
    return 0;
  }
  bVar2 = DeviceIsMediaChangeDisabledForClass(param_1);
  pcVar9 = "disabled";
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    pcVar7 = "disabled";
    if (!bVar2) {
      pcVar7 = "enabled";
    }
    WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,0xd,0x36,
                      &WPP_bfcef3ce16aa3c5196ed71474c974d5c_Traceguids,pcVar7);
  }
  pcVar7 = local_res10;
  uVar5 = DeviceMediaChangeDeviceInstanceOverride(param_1,pcVar7);
  cVar1 = local_res10[0];
  uVar8 = uVar5 & 0xffffffff;
  if ((int)uVar5 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14003135f;
    pcVar7 = (char *)CONCAT71((int7)((ulonglong)pcVar7 >> 8),4);
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,0xd,0x37,
                     &WPP_bfcef3ce16aa3c5196ed71474c974d5c_Traceguids);
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      pcVar6 = "Enabling";
      if (local_res10[0] == '\0') {
        pcVar6 = "Disabling";
      }
      WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar7,0xd,0x38,
                        &WPP_bfcef3ce16aa3c5196ed71474c974d5c_Traceguids,pcVar6);
    }
    bVar2 = cVar1 == '\0';
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (bVar2 == false) {
      pcVar9 = "enabled";
    }
    WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar7,0xd,0x39,
                      &WPP_bfcef3ce16aa3c5196ed71474c974d5c_Traceguids,pcVar9);
  }
LAB_14003135f:
  if (bVar2 == false) {
    uVar3 = DeviceInitializeMcn(param_1,(char)pcVar7);
    uVar8 = (ulonglong)uVar3;
  }
  return uVar8;
}



===== BootEnvironmentIsWinPE @ 140034008 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool BootEnvironmentIsWinPE(void)

{
  int iVar1;
  undefined1 auStack_f8 [32];
  undefined8 local_d8;
  undefined8 *local_d0;
  undefined8 local_b8;
  undefined8 local_b0;
  wchar_t *local_a8;
  wchar_t local_98 [64];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_f8;
  local_d0 = &local_b8;
  local_b8 = 0;
  builtin_wcsncpy(local_98,L"\\Registry\\Machine\\System\\CurrentControlSet\\Contr",0x30);
  builtin_wcsncpy(local_98 + 0x30,L"ol\\MiniNT",10);
  local_a8 = local_98;
  local_d8 = 0;
  local_b0 = 0x740072;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x728))(WdfDriverGlobals,0,&local_b0,0x20019);
  if (-1 < iVar1) {
    (**(code **)(WdfFunctions_01015 + 0x738))(WdfDriverGlobals,local_b8);
  }
  return -1 < iVar1;
}



===== __security_init_cookie @ 140034108 =====

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



===== DriverEntry @ 14003413c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(undefined8 param_1,undefined8 param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined8 local_res18;
  ulonglong local_78;
  code *local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  ulonglong local_58;
  code *local_50;
  undefined8 local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined *local_28;
  
  _DAT_14001a4e8 = 1;
  local_res18 = 0;
  local_78 = (ulonglong)(uint)local_78;
  local_58 = (ulonglong)(uint)local_58;
  _WPP_MAIN_CB = 0;
  DAT_14001a4c8 = &WPP_ThisDir_CTLGUID_wppCtlGuid;
  DAT_14001a4d0 = 0;
  _DAT_14001a4e0 = 0;
  _DAT_14001a500 = 0;
  _DAT_14001a508 = 0;
  WppLoadTracingSupport();
  _DAT_14001a4e0 = 0;
  WppInitKm(param_1,param_2);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,9,10,
                      &WPP_d2ddb5c132d1335dbff1b624de01ec23_Traceguids,(char)param_1);
  }
  McGenEventRegister_EtwRegister();
  wil_InitializeFeatureStaging();
  local_28 = PTR__WDF_CDROM_DRIVER_EXTENSION_TYPE_INFO_14001a0b8;
  local_50 = DriverEvtCleanup;
  local_58 = 0x38;
  local_48 = 0;
  local_70 = DriverEvtDeviceAdd;
  local_38 = 0;
  uStack_30 = 0;
  local_40 = 1;
  local_3c = 1;
  local_78 = 0x20;
  local_68 = 0;
  uStack_60 = 0;
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x3a0))
                    (WdfDriverGlobals,param_1,param_2,&local_58,&local_78,&local_res18);
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,9,0xb,
                        &WPP_d2ddb5c132d1335dbff1b624de01ec23_Traceguids,(char)iVar2);
    }
    WppCleanupKm(param_1);
    McGenEventUnregister_EtwUnregister();
    wil_UninitializeFeatureStaging();
  }
  else {
    puVar4 = (undefined4 *)
             (**(code **)(WdfFunctions_01015 + 0x650))
                       (WdfDriverGlobals,local_res18,
                        PTR__WDF_CDROM_DRIVER_EXTENSION_TYPE_INFO_14001a0b8);
    *puVar4 = 1;
    *(undefined8 *)(puVar4 + 2) = param_1;
    bVar1 = BootEnvironmentIsWinPE();
    if (bVar1) {
      puVar4[4] = puVar4[4] | 1;
    }
    iVar3 = WmiQueryTraceInformation(0xb,puVar4 + 6,8,0,0);
    if (iVar3 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,9,0xc,
                          &WPP_d2ddb5c132d1335dbff1b624de01ec23_Traceguids,(char)iVar3);
      }
      *(undefined4 **)(puVar4 + 6) = puVar4 + 8;
    }
  }
  return iVar2;
}



===== wil_InitializeFeatureStaging @ 1400343a8 =====

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



===== wil_details_PopulateInitialConfiguredFeatureStates @ 140034498 =====

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


