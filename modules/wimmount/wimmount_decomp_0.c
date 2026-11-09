
===== __report_gsfailure @ 140001010 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
                    /* WARNING: Subroutine does not return */
  KeBugCheckEx(0xf7,_StackCookie,__security_cookie,__security_cookie_complement,0);
}



===== __C_specific_handler @ 140001043 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000140001043. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== PFOpenById @ 140001058 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int PFOpenById(undefined8 param_1,undefined8 param_2,undefined8 param_3,short *param_4,char param_5,
              undefined8 *param_6,longlong *param_7,char param_8)

{
  longlong lVar1;
  short sVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  undefined1 auStack_128 [32];
  undefined8 *local_108;
  undefined8 *local_100;
  undefined8 local_f8;
  undefined4 local_f0;
  undefined4 local_e8;
  undefined4 local_e0;
  undefined4 local_d8;
  undefined8 local_d0;
  undefined4 local_c8;
  undefined4 local_c0;
  longlong local_b8;
  undefined8 local_b0;
  short *local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 *local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  ulonglong local_50;
  
  local_50 = __security_cookie ^ (ulonglong)auStack_128;
  local_c0 = 0x800;
  local_c8 = 0;
  piVar4 = (int *)0x0;
  local_d0 = 0;
  local_d8 = 0x206020;
  uVar5 = -(uint)(param_8 != '\0') & 0xfefefeea;
  local_e0 = 1;
  local_90 = &local_b0;
  local_e8 = 7;
  local_100 = &local_68;
  local_f0 = 0x80;
  local_f8 = 0;
  local_108 = &local_a0;
  local_b8 = 0;
  local_b0 = 0x80008;
  local_a0 = 0x30;
  local_88 = 0x200;
  local_68 = 0;
  uStack_60 = 0;
  local_80 = 0;
  uStack_78 = 0;
  local_a8 = param_4;
  local_98 = param_3;
  local_70 = param_3;
  iVar3 = FltCreateFile(param_1,param_2,&local_b8,uVar5 + 0x113019f);
  if (-1 < iVar3) {
    local_100 = (undefined8 *)0x0;
    local_108 = param_6;
    iVar3 = ObReferenceObjectByHandle(local_b8,0xf0000,*(undefined8 *)IoFileObjectType_exref,0);
    if (-1 < iVar3) {
      if (param_5 != '\0') {
        local_58 = 0;
        FltClose(local_b8);
        local_100 = (undefined8 *)0x0;
        local_b8 = 0;
        local_108 = (undefined8 *)CONCAT44(local_108._4_4_,9);
        iVar3 = FltQueryInformationFile(param_2,*param_6,&local_58,8);
        if (((iVar3 + 0x80000000U & 0x80000000) == 0) && (iVar3 != -0x7ffffffb)) goto LAB_140001310;
        iVar3 = (int)local_58 + 8;
        piVar4 = (int *)ExAllocatePoolWithTag(1,iVar3,0x50466e69);
        if (piVar4 == (int *)0x0) {
          iVar3 = -0x3fffff66;
          goto LAB_140001310;
        }
        local_100 = (undefined8 *)0x0;
        local_108 = (undefined8 *)CONCAT44(local_108._4_4_,9);
        iVar3 = FltQueryInformationFile(param_2,*param_6,piVar4,iVar3);
        if (iVar3 < 0) goto LAB_140001310;
        if (*piVar4 == 0) {
          iVar3 = -0x3fffffff;
          goto LAB_140001310;
        }
        local_c0 = 0x800;
        local_a8 = (short *)((longlong)piVar4 + 6);
        local_c8 = 0;
        local_d0 = 0;
        sVar2 = (short)*piVar4 + -2;
        local_d8 = 0x204020;
        local_b0 = CONCAT62(CONCAT42(local_b0._4_4_,sVar2),sVar2);
        local_e0 = 1;
        local_98 = local_70;
        local_90 = &local_b0;
        local_e8 = 7;
        local_100 = &local_68;
        local_f0 = 0x80;
        local_f8 = 0;
        local_108 = &local_a0;
        local_a0 = CONCAT44(local_a0._4_4_,0x30);
        local_88 = CONCAT44(local_88._4_4_,0x200);
        local_80 = 0;
        uStack_78 = 0;
        iVar3 = FltCreateFile(param_1,param_2,&local_b8,uVar5 + 0x113019f);
        if (iVar3 < 0) goto LAB_140001310;
      }
      lVar1 = local_b8;
      if (param_7 != (longlong *)0x0) {
        local_b8 = 0;
        *param_7 = lVar1;
      }
    }
  }
LAB_140001310:
  if (local_b8 != 0) {
    FltClose();
  }
  if (piVar4 != (int *)0x0) {
    ExFreePoolWithTag(piVar4,0x50466e69);
  }
  return iVar3;
}



===== PFPathIsUnderTempDir @ 140001368 =====

undefined1 PFPathIsUnderTempDir(uint *param_1)

{
  undefined1 extraout_AL;
  undefined1 extraout_AL_00;
  undefined1 extraout_AH;
  undefined1 extraout_AH_00;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  uint local_48 [8];
  short local_28 [16];
  
  local_28[0] = 0;
  local_28[1] = 0;
  local_28[2] = 0;
  local_28[3] = 0;
  local_28[4] = 0;
  local_28[5] = 0;
  local_28[6] = 0;
  local_28[7] = 0;
  local_48[0] = 0;
  local_48[1] = 0;
  local_48[2] = 0;
  local_48[3] = 0;
  local_48[4] = 0;
  local_48[5] = 0;
  local_48[6] = 0;
  local_48[7] = 0;
  local_28[8] = 0;
  local_28[9] = 0;
  local_28[10] = 0;
  local_28[0xb] = 0;
  local_28[0xc] = 0;
  local_28[0xd] = 0;
  local_28[0xe] = 0;
  local_28[0xf] = 0;
  ParsePathElement(param_1,local_28,(short *)local_48);
  ParsePathElement(local_48,local_28,(short *)local_48);
  ParsePathElement(local_48,(short *)local_48,(short *)(local_48 + 4));
  ParsePathElement(local_48 + 4,(short *)(local_48 + 4),local_28 + 8);
  RtlCompareUnicodeString(local_48,&DAT_140006000,1);
  if (((CONCAT22(extraout_var,CONCAT11(extraout_AH,extraout_AL)) &
       CONCAT22(extraout_var,CONCAT11(extraout_AH,extraout_AL))) == 0) &&
     (RtlCompareUnicodeString(local_48 + 4,&DAT_140006010,1),
     (CONCAT22(extraout_var_00,CONCAT11(extraout_AH_00,extraout_AL_00)) &
     CONCAT22(extraout_var_00,CONCAT11(extraout_AH_00,extraout_AL_00))) == 0)) {
    return 1;
  }
  return 0;
}



===== PFSetSubsumedStatus @ 140001420 =====

void PFSetSubsumedStatus(undefined8 param_1,longlong param_2,undefined4 param_3)

{
  longlong lVar1;
  longlong lVar2;
  
  FltAcquireResourceExclusive(&DAT_1400060f0);
  lVar1 = *(longlong *)(param_2 + 0x28);
  *(undefined8 *)(param_2 + 0x28) = 0;
  FltReleaseResource(&DAT_1400060f0);
  while (lVar1 != 0) {
    lVar2 = *(longlong *)(lVar1 + 0x28);
    *(undefined4 *)(lVar1 + 0x18) = param_3;
    KeSetEvent(lVar1,0,0);
    FltDeleteStreamContext(param_1,*(undefined8 *)(lVar1 + 0x30),0);
    FltUntagFile(param_1,*(undefined8 *)(lVar1 + 0x30),0x80000008,0);
    ObfDereferenceObject(*(undefined8 *)(lVar1 + 0x30));
    FltReleaseContext(lVar1);
    lVar1 = lVar2;
  }
  return;
}



===== PFSubsumeContext @ 140001504 =====

int PFSubsumeContext(undefined8 param_1,undefined8 param_2,undefined8 param_3,short *param_4,
                    short *param_5,undefined8 param_6)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  char *pcVar4;
  ulonglong uVar5;
  longlong *plVar6;
  undefined4 uVar7;
  char local_48 [8];
  longlong local_40;
  longlong local_38;
  longlong local_30;
  longlong local_28;
  longlong local_20;
  
  local_38 = 0;
  local_40 = 0;
  local_30 = 0;
  local_20 = 0;
  local_28 = 0;
  local_48[0] = '\0';
  iVar1 = PFOpenById(param_1,param_2,param_3,param_5,'\x01',&local_40,&local_38,'\0');
  if (-1 < iVar1) {
    pcVar4 = local_48;
    iVar1 = PFGetContextByFileObject(param_1,param_2,local_40,&local_20,pcVar4);
    lVar2 = local_20;
    if (iVar1 < 0) goto LAB_14000170d;
    if (local_20 != 0) {
      if (local_48[0] == '\0') {
        if (local_40 != 0) {
          ObfDereferenceObject();
          local_40 = 0;
        }
        if (local_38 != 0) {
          FltClose(local_38);
        }
        lVar3 = 0;
        iVar1 = KeWaitForSingleObject(lVar2,6,0,1,0);
        if ((iVar1 == 0x101) || ((-1 < iVar1 && (*(int *)(lVar2 + 0x18) < 0)))) {
          iVar1 = *(int *)(lVar2 + 0x18);
        }
      }
      else {
        plVar6 = &local_30;
        uVar7 = 0;
        uVar5 = (ulonglong)pcVar4 & 0xffffffffffffff00;
        iVar1 = PFOpenById(param_1,param_2,param_3,param_4,'\0',plVar6,(longlong *)0x0,'\x01');
        if (-1 < iVar1) {
          iVar1 = FltGetStreamContext(param_2,local_30,&local_28);
          if (-1 < iVar1) {
            ObfDereferenceObject(local_30);
            lVar3 = local_38;
            local_30 = 0;
            iVar1 = ZwDuplicateObject(0xffffffffffffffff,local_38,0xffffffffffffffff,param_6,
                                      uVar5 & 0xffffffff00000000,
                                      (ulonglong)plVar6 & 0xffffffff00000000,CONCAT44(uVar7,6));
            if (-1 < iVar1) {
              FltAcquireResourceExclusive(&DAT_1400060f0);
              *(undefined8 *)(lVar2 + 0x28) = *(undefined8 *)(local_28 + 0x28);
              *(longlong *)(local_28 + 0x28) = lVar2;
              *(longlong *)(lVar2 + 0x30) = local_40;
              lVar2 = 0;
              local_40 = 0;
              FltReleaseResource(&DAT_1400060f0);
            }
            goto LAB_140001711;
          }
        }
LAB_14000170d:
        lVar3 = local_38;
      }
LAB_140001711:
      if (lVar2 != 0) {
        if (local_48[0] != '\0') {
          *(int *)(lVar2 + 0x18) = iVar1;
          KeSetEvent(lVar2,0,0);
          FltDeleteStreamContext(param_2,local_40,0);
        }
        FltReleaseContext(lVar2);
      }
      goto LAB_14000175e;
    }
  }
  lVar3 = local_38;
LAB_14000175e:
  if (local_28 != 0) {
    FltReleaseContext();
  }
  if (local_40 != 0) {
    ObfDereferenceObject();
  }
  if (local_30 != 0) {
    ObfDereferenceObject();
  }
  if (lVar3 != 0) {
    FltClose(lVar3);
  }
  return iVar1;
}



===== ParsePathElement @ 1400017d8 =====

short ParsePathElement(uint *param_1,short *param_2,short *param_3)

{
  short sVar1;
  uint uVar2;
  ulonglong uVar3;
  short *psVar4;
  short *psVar5;
  short sVar6;
  uint uVar7;
  ushort uVar8;
  short sVar9;
  uint uVar10;
  short *psVar11;
  
  uVar10 = *param_1;
  psVar11 = (short *)0x0;
  uVar8 = (ushort)uVar10;
  for (psVar5 = *(short **)(param_1 + 2); (uVar8 != 0 && (*psVar5 == 0x5c)); psVar5 = psVar5 + 1) {
    uVar8 = (short)uVar10 - 2;
    uVar10 = (uint)uVar8;
  }
  uVar7 = (uVar10 & 0xffff) >> 1;
  uVar3 = 0;
  if (uVar7 != 0) {
    psVar4 = psVar5;
    do {
      if (*psVar4 == 0x5c) break;
      uVar2 = (int)uVar3 + 1;
      uVar3 = (ulonglong)uVar2;
      psVar4 = psVar4 + 1;
    } while (uVar2 < uVar7);
  }
  sVar1 = (short)uVar3;
  sVar6 = sVar1 * 2;
  param_2[1] = sVar6;
  *param_2 = sVar6;
  sVar9 = (short)uVar10 + sVar1 * -2;
  *(ulonglong *)(param_2 + 4) = -(ulonglong)(sVar6 != 0) & (ulonglong)psVar5;
  param_3[1] = sVar9;
  *param_3 = sVar9;
  if (sVar9 != 0) {
    psVar11 = psVar5 + uVar3;
  }
  *(short **)(param_3 + 4) = psVar11;
  return sVar1 * -2;
}



===== wil_details_FeatureReporting_RecordUsageInCache @ 140001878 =====

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
LAB_140001a81:
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
LAB_140001953:
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
      if (param_3 == 4) goto LAB_140001a81;
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
        goto LAB_140001953;
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



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 140001b6c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool wil_details_FeatureReporting_ReportUsageToServiceDirect
               (undefined8 param_1,undefined8 param_2,uint param_3)

{
  uint6 uVar1;
  uint *puVar2;
  undefined1 auStack_98 [32];
  uint *local_78;
  undefined8 local_68;
  undefined8 local_60;
  wchar_t *local_58;
  uint local_50 [6];
  uint local_38;
  uint uStack_34;
  uint uStack_30;
  uint uStack_2c;
  undefined8 local_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_98;
  puVar2 = wil_details_FeatureReporting_RecordUsageInCache
                     (local_50,&Feature_ReFS_WIM_Mount_Support__private_reporting,param_3,
                      (uint)((ulonglong)param_2 >> 0x20));
  local_38 = *puVar2;
  uStack_34 = puVar2[1];
  uStack_30 = puVar2[2];
  uStack_2c = puVar2[3];
  local_28 = *(undefined8 *)(puVar2 + 4);
  if (g_wil_details_recordFeatureUsage != (code *)0x0) {
    local_78 = &local_38;
    (*g_wil_details_recordFeatureUsage)
              (0x26b38e7,param_3,1,&Feature_ReFS_WIM_Mount_Support__private_reporting);
  }
  if ((((uint)param_2 >> 10 & 1) != 0) && (param_3 != 0xfe)) {
    local_68._0_6_ = CONCAT24((short)param_3,0x26b38e7);
    uVar1 = (uint6)local_68;
    local_68 = (ulonglong)(uint6)local_68;
    if (((uint)param_2 >> 0xb & 1) != 0) {
      local_68 = CONCAT26(1,uVar1);
    }
    if (g_wil_details_pfnRtlNotifyFeatureUsage == (code *)0x0) {
      local_60 = 0x2c002a;
      local_58 = L"RtlNotifyFeatureUsage";
      g_wil_details_pfnRtlNotifyFeatureUsage = (code *)MmGetSystemRoutineAddress(&local_60);
      if (g_wil_details_pfnRtlNotifyFeatureUsage == (code *)0x0) goto LAB_140001c5f;
    }
    (*g_wil_details_pfnRtlNotifyFeatureUsage)(&local_68);
  }
LAB_140001c5f:
  return (int)local_28 == 0;
}



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 140001c94 =====

void wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath(undefined8 param_1,int param_2)

{
  uint uVar1;
  
  if (param_2 == 3) {
    uVar1 = 0x10;
  }
  else {
    if (param_2 != 4) {
      return;
    }
    uVar1 = 0x20;
  }
  LOCK();
  UNLOCK();
  Feature_ReFS_WIM_Mount_Support__private_featureState =
       Feature_ReFS_WIM_Mount_Support__private_featureState | uVar1;
  return;
}



===== wil_details_RecordCachedUsage @ 140001cbc =====

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
    wil_details_RtlRecordFeatureUsage(&local_48,lVar6);
  }
  return;
}



===== wil_details_RecordFeatureUsageReporting @ 140001e10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void wil_details_RecordFeatureUsageReporting(undefined4 param_1)

{
  int *piVar1;
  longlong lVar2;
  int iVar3;
  undefined4 uStack0000000000000028;
  undefined2 in_stack_0000002c;
  undefined2 in_stack_0000002e;
  undefined8 local_28;
  wchar_t *local_20;
  undefined8 local_18;
  wchar_t *local_10;
  
  iVar3 = g_wil_details_featureUsageCached;
  lVar2 = g_wil_details_featureUsageProvider;
  piVar1 = (int *)CONCAT26(in_stack_0000002e,CONCAT24(in_stack_0000002c,uStack0000000000000028));
  if (*piVar1 != 0) {
    LOCK();
    g_wil_details_featureUsageCached = 1;
    UNLOCK();
    if ((iVar3 == 0) && (g_wil_details_featureUsageProvider != 0)) {
      if (g_wil_details_pfnRtlArmFeatureUsageProviderFlushNotification == (code *)0x0) {
        local_28 = 0x580056;
        local_20 = L"RtlArmFeatureUsageProviderFlushNotification";
        g_wil_details_pfnRtlArmFeatureUsageProviderFlushNotification =
             (code *)MmGetSystemRoutineAddress(&local_28);
        if (g_wil_details_pfnRtlArmFeatureUsageProviderFlushNotification == (code *)0x0)
        goto LAB_140001e95;
      }
      (*g_wil_details_pfnRtlArmFeatureUsageProviderFlushNotification)(lVar2,1);
    }
  }
LAB_140001e95:
  if (piVar1[1] != 0) {
    in_stack_0000002c = (undefined2)piVar1[2];
    in_stack_0000002e = (undefined2)piVar1[1];
    uStack0000000000000028 = param_1;
    if (g_wil_details_pfnRtlRecordFeatureUsage == (code *)0x0) {
      local_18 = 0x2c002a;
      local_10 = L"RtlRecordFeatureUsage";
      g_wil_details_pfnRtlRecordFeatureUsage = (code *)MmGetSystemRoutineAddress(&local_18);
      if (g_wil_details_pfnRtlRecordFeatureUsage == (code *)0x0) {
        return;
      }
    }
    (*g_wil_details_pfnRtlRecordFeatureUsage)(&uStack0000000000000028,1);
  }
  return;
}



===== wil_details_RtlQueryFeatureConfiguration @ 140001f14 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
wil_details_RtlQueryFeatureConfiguration
          (undefined4 param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  undefined8 local_18;
  wchar_t *local_10;
  
  if (g_wil_details_pfnRtlQueryFeatureConfiguration == (code *)0x0) {
    local_18 = 0x3a0038;
    local_10 = L"RtlQueryFeatureConfiguration";
    g_wil_details_pfnRtlQueryFeatureConfiguration = (code *)MmGetSystemRoutineAddress(&local_18);
    if (g_wil_details_pfnRtlQueryFeatureConfiguration == (code *)0x0) {
      return 0xc0000139;
    }
  }
  uVar1 = (*g_wil_details_pfnRtlQueryFeatureConfiguration)(param_1,param_2,param_3,param_4);
  return uVar1;
}



===== wil_details_RtlRecordFeatureUsage @ 140001fa0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void wil_details_RtlRecordFeatureUsage(undefined8 param_1,undefined8 param_2)

{
  undefined8 local_18;
  wchar_t *local_10;
  
  if (g_wil_details_pfnRtlRecordFeatureUsage == (code *)0x0) {
    local_18 = 0x2c002a;
    local_10 = L"RtlRecordFeatureUsage";
    g_wil_details_pfnRtlRecordFeatureUsage = (code *)MmGetSystemRoutineAddress(&local_18);
    if (g_wil_details_pfnRtlRecordFeatureUsage == (code *)0x0) {
      return;
    }
  }
  (*g_wil_details_pfnRtlRecordFeatureUsage)(param_1,param_2);
  return;
}



===== DuplicateEventIntoProcess @ 14000200c =====

int DuplicateEventIntoProcess(undefined8 param_1,undefined8 *param_2,longlong *param_3)

{
  int iVar1;
  longlong local_res10;
  ulonglong in_stack_ffffffffffffff98;
  longlong *plVar2;
  ulonglong uVar3;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 uStack_20;
  
  local_48 = 0x30;
  *param_2 = 0;
  *param_3 = 0;
  local_res10 = 0;
  local_30 = 0x200;
  local_40 = 0;
  local_38 = 0;
  local_28 = 0;
  uStack_20 = 0;
  iVar1 = ZwCreateEvent(&local_res10,0x1f0003,&local_48,0,
                        in_stack_ffffffffffffff98 & 0xffffffffffffff00);
  if (-1 < iVar1) {
    uVar3 = 0;
    plVar2 = param_3;
    iVar1 = ObReferenceObjectByHandle
                      (local_res10,0x1f0003,*(undefined8 *)ExEventObjectType_exref,0,param_3,0);
    if (-1 < iVar1) {
      iVar1 = ZwDuplicateObject(0xffffffffffffffff,local_res10,param_1,param_2,
                                (ulonglong)plVar2 & 0xffffffff00000000,uVar3 & 0xffffffff00000000,6)
      ;
      if (-1 < iVar1) goto LAB_1400020fe;
    }
  }
  if (*param_3 != 0) {
    ObfDereferenceObject();
    *param_3 = 0;
  }
LAB_1400020fe:
  if (local_res10 != 0) {
    ZwClose();
  }
  return iVar1;
}



===== PriCreateTransactional @ 140002138 =====

void PriCreateTransactional
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8)

{
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_28 = param_5;
  local_30 = 0;
  uStack_50 = 0;
  local_38 = 0x30;
  local_58 = 0x20;
  local_48 = 0;
  local_20 = 0x240;
  local_68 = 0;
  uStack_60 = 0;
  local_18 = 0;
  uStack_10 = 0;
  uStack_40 = param_3;
  FltCreateFileEx2(0,0,param_7,param_8,0x10000,&local_38,&local_68,0,0x80,7,1,0x204001,0,0,0,
                   &local_58);
  return;
}



===== PriExchangeDirs @ 140002204 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong PriExchangeDirs(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4,
                         undefined1 *param_5)

{
  ushort uVar1;
  ushort *puVar2;
  uint uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined1 *puVar6;
  ulonglong uVar7;
  undefined1 **ppuVar8;
  longlong *plVar9;
  ushort **ppuVar10;
  longlong lVar11;
  longlong lVar12;
  longlong lVar13;
  longlong lVar14;
  undefined1 auStackY_1e8 [32];
  undefined1 local_1a8 [8];
  longlong local_1a0;
  longlong local_198;
  longlong local_190;
  longlong local_188;
  undefined1 *local_180;
  longlong local_178;
  ushort local_170 [4];
  void *pvStack_168;
  ushort local_160 [4];
  void *pvStack_158;
  ulonglong local_150 [4];
  ushort local_130 [8];
  undefined8 local_120;
  longlong local_118;
  undefined8 local_110;
  undefined8 local_108;
  longlong lStack_100;
  longlong local_f8 [2];
  undefined1 *local_e8;
  longlong local_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  longlong local_b0 [7];
  ushort *local_78;
  ulonglong *local_70;
  ushort *local_68;
  ushort *local_60;
  ulonglong local_58;
  
  ppuVar8 = &local_e8;
  local_58 = __security_cookie ^ (ulonglong)auStackY_1e8;
  local_e8 = param_5;
  local_b8 = 0;
  local_150[3] = 0;
  lVar11 = 0;
  local_190 = 0;
  puVar6 = (undefined1 *)0x0;
  local_188 = 0;
  local_b0[0] = 0;
  local_198 = 0;
  local_1a0 = 0;
  local_180 = (undefined1 *)0x0;
  local_178 = 0;
  local_118 = 0;
  local_110 = 0;
  local_108 = 0;
  lStack_100 = 0;
  local_1a8[0] = 0;
  local_130[0] = 0;
  local_130[1] = 0;
  local_130[2] = 0;
  local_130[3] = 0;
  local_130[4] = 0;
  local_130[5] = 0;
  local_130[6] = 0;
  local_130[7] = 0;
  local_150[2] = 0;
  local_150[0] = 0;
  local_150[1] = 0;
  local_170[0] = 0;
  local_170[1] = 0;
  local_170[2] = 0;
  local_170[3] = 0;
  pvStack_168 = (void *)0x0;
  local_160[0] = 0;
  local_160[1] = 0;
  local_160[2] = 0;
  local_160[3] = 0;
  pvStack_158 = (void *)0x0;
  local_d8 = 0;
  uStack_d0 = 0;
  local_c8 = 0;
  uStack_c0 = 0;
  local_120 = param_2;
  local_f8[0] = param_4;
  uVar3 = ObReferenceObjectByHandle(0,0,*(undefined8 *)TmTransactionObjectType_exref,1);
  lVar12 = 4;
  uVar7 = (ulonglong)uVar3;
  lVar13 = 0;
  lVar14 = 0;
  if (-1 < (int)uVar3) {
    uVar3 = PriGetObjectsFromUserHandle
                      (local_120,0x10000,(longlong *)(local_150 + 3),&local_190,&local_188,
                       (longlong *)&local_180,&local_198);
    uVar7 = (ulonglong)uVar3;
    if (-1 < (int)uVar3) {
      plVar9 = &local_178;
      uVar3 = PriGetObjectsFromUserHandle
                        (param_3,0x10000,(longlong *)0x0,(longlong *)0x0,local_b0,plVar9,&local_1a0)
      ;
      lVar11 = local_b0[0];
      lVar14 = local_188;
      uVar7 = (ulonglong)uVar3;
      if (-1 < (int)uVar3) {
        if (local_188 == local_b0[0]) {
          uVar3 = PriGetString(local_188,FltGetVolumeName_exref,local_130);
          lVar13 = local_190;
          uVar7 = (ulonglong)uVar3;
          if (-1 < (int)uVar3) {
            local_b0[1] = local_198;
            local_b0[0] = local_190;
            uVar3 = PriGetString(local_b0,PriGetFileNameCallback,(ushort *)local_150);
            uVar7 = (ulonglong)uVar3;
            if (-1 < (int)uVar3) {
              uVar4 = PriStringEnsureCapacity
                                (local_170,
                                 (uint)DAT_140006020 + (uint)(ushort)local_150[0] +
                                 (uint)local_130[0]);
              uVar7 = uVar4 & 0xffffffff;
              if (-1 < (int)uVar4) {
                uVar3 = RtlAppendUnicodeStringToString(local_170,local_130);
                uVar7 = (ulonglong)uVar3;
                if (-1 < (int)uVar3) {
                  uVar3 = RtlAppendUnicodeStringToString(local_170);
                  uVar7 = (ulonglong)uVar3;
                  if (-1 < (int)uVar3) {
                    local_150[0] = local_150[0] & 0xffffffffffff0000;
                    local_b0[1] = local_1a0;
                    local_b0[0] = lVar13;
                    uVar3 = PriGetString(local_b0,PriGetFileNameCallback,(ushort *)local_150);
                    uVar7 = (ulonglong)uVar3;
                    if (-1 < (int)uVar3) {
                      uVar4 = PriStringEnsureCapacity
                                        (local_160,(uint)(ushort)local_150[0] + (uint)local_130[0]);
                      uVar7 = uVar4 & 0xffffffff;
                      if (-1 < (int)uVar4) {
                        uVar3 = RtlAppendUnicodeStringToString(local_160,local_130);
                        uVar7 = (ulonglong)uVar3;
                        if (-1 < (int)uVar3) {
                          uVar3 = RtlAppendUnicodeStringToString(local_160,local_150);
                          uVar7 = (ulonglong)uVar3;
                          if (-1 < (int)uVar3) {
                            ObfDereferenceObject(local_198,0);
                            ObfDereferenceObject(local_1a0);
                            local_1a0 = 0;
                            local_198 = 0;
                            ZwClose(local_180);
                            ZwClose(local_178);
                            uVar4 = local_150[3];
                            local_178 = 0;
                            local_180 = (undefined1 *)0x0;
                            uVar5 = PFSendExchangeCloseHandlesMessage
                                              (local_150[3],local_f8[0],local_120,param_3);
                            uVar7 = uVar5 & 0xffffffff;
                            if (-1 < (int)uVar5) {
                              local_108 = CONCAT44(local_108._4_4_,0xfffe0010);
                              *local_e8 = 1;
                              lStack_100 = local_150[2];
                              uVar3 = PriCreateTransactional
                                                (uVar4,lVar13,&local_108,param_3,local_170,plVar9,
                                                 &local_118,&local_198);
                              uVar7 = (ulonglong)uVar3;
                              if (-1 < (int)uVar3) {
                                uVar3 = PriCreateTransactional
                                                  (uVar4,lVar13,&local_108,param_3,local_160,plVar9,
                                                   &local_110,&local_1a0);
                                uVar7 = (ulonglong)uVar3;
                                if (-1 < (int)uVar3) {
                                  uVar3 = RtlAppendUnicodeStringToString(local_170,&DAT_140006020);
                                  uVar7 = (ulonglong)uVar3;
                                  if (-1 < (int)uVar3) {
                                    uVar1 = local_170[0];
                                    if (local_170[0] < local_160[0]) {
                                      uVar1 = local_160[0];
                                    }
                                    puVar6 = (undefined1 *)
                                             ExAllocatePoolWithTag(1,uVar1 + 0x14,0x574d6365);
                                    if (puVar6 == (undefined1 *)0x0) {
                                      uVar7 = 0xc0000017;
                                    }
                                    else {
                                      *puVar6 = 0;
                                      *(undefined8 *)(puVar6 + 8) = 0;
                                      *(uint *)(puVar6 + 0x10) = (uint)local_170[0];
                                      memmove(puVar6 + 0x14,pvStack_168,
                                              (ulonglong)(uint)local_170[0]);
                                      uVar3 = FltSetInformationFile
                                                        (lVar13,local_1a0,puVar6,
                                                         *(int *)(puVar6 + 0x10) + 0x14);
                                      uVar7 = (ulonglong)uVar3;
                                      if (-1 < (int)uVar3) {
                                        *(uint *)(puVar6 + 0x10) = (uint)local_160[0];
                                        memmove(puVar6 + 0x14,pvStack_158,
                                                (ulonglong)(uint)local_160[0]);
                                        uVar3 = FltSetInformationFile
                                                          (lVar13,local_198,puVar6,
                                                           *(int *)(puVar6 + 0x10) + 0x14);
                                        uVar7 = (ulonglong)uVar3;
                                        if (-1 < (int)uVar3) {
                                          local_b8 = CONCAT44(local_b8._4_4_,0x80);
                                          local_1a8[0] = 1;
                                          uVar3 = FltSetInformationFile
                                                            (lVar13,local_1a0,&local_d8,0x28);
                                          uVar7 = (ulonglong)uVar3;
                                          if (-1 < (int)uVar3) {
                                            uVar3 = FltSetInformationFile
                                                              (lVar13,local_1a0,local_1a8,1);
                                            uVar7 = (ulonglong)uVar3;
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
                    }
                  }
                }
              }
            }
          }
          goto LAB_14000272d;
        }
        uVar7 = 0xc000000d;
      }
    }
    lVar13 = local_190;
    lVar14 = local_188;
  }
LAB_14000272d:
  local_b0[0] = local_150[2];
  local_b0[1] = local_198;
  local_b0[2] = local_1a0;
  local_b0[3] = local_150[3];
  local_e8 = local_180;
  local_e0 = local_178;
  local_f8[0] = local_118;
  local_f8[1] = local_110;
  local_78 = local_130;
  local_70 = local_150;
  local_68 = local_170;
  local_b0[4] = lVar13;
  plVar9 = local_b0;
  local_b0[5] = lVar14;
  lVar13 = 3;
  local_60 = local_160;
  local_b0[6] = lVar11;
  do {
    if (*plVar9 != 0) {
      ObfDereferenceObject(*plVar9,0);
    }
    plVar9 = plVar9 + 1;
    lVar13 = lVar13 + -1;
  } while (lVar13 != 0);
  plVar9 = local_b0 + 3;
  lVar13 = 4;
  do {
    if (*plVar9 != 0) {
      FltObjectDereference(*plVar9,0);
    }
    plVar9 = plVar9 + 1;
    lVar13 = lVar13 + -1;
  } while (lVar13 != 0);
  lVar13 = 2;
  lVar14 = 2;
  do {
    if (*ppuVar8 != (undefined1 *)0x0) {
      ZwClose(*ppuVar8,0);
    }
    ppuVar8 = ppuVar8 + 1;
    lVar14 = lVar14 + -1;
  } while (lVar14 != 0);
  plVar9 = local_f8;
  do {
    if (*plVar9 != 0) {
      FltClose(*plVar9,0);
    }
    plVar9 = plVar9 + 1;
    lVar13 = lVar13 + -1;
  } while (lVar13 != 0);
  ppuVar10 = &local_78;
  do {
    puVar2 = *ppuVar10;
    if (puVar2 != (ushort *)0x0) {
      if (*(longlong *)(puVar2 + 4) != 0) {
        ExFreePoolWithTag(*(longlong *)(puVar2 + 4),0x574d6365);
      }
      puVar2[0] = 0;
      puVar2[1] = 0;
      puVar2[2] = 0;
      puVar2[3] = 0;
      puVar2[4] = 0;
      puVar2[5] = 0;
      puVar2[6] = 0;
      puVar2[7] = 0;
    }
    ppuVar10 = ppuVar10 + 1;
    lVar12 = lVar12 + -1;
  } while (lVar12 != 0);
  if (puVar6 != (undefined1 *)0x0) {
    ExFreePoolWithTag(puVar6,0x574d6365);
  }
  return uVar7;
}



===== PriGetFileNameCallback @ 1400028d0 =====

int PriGetFileNameCallback(undefined8 *param_1,ushort *param_2,uint *param_3)

{
  ushort uVar1;
  ushort *puVar2;
  int iVar3;
  
  uVar1 = param_2[1];
  puVar2 = *(ushort **)(param_2 + 4);
  if (uVar1 < 8) {
    *param_3 = 0x208;
    iVar3 = -0x3fffffdd;
  }
  else {
    iVar3 = FltQueryInformationFile(*param_1,param_1[1],puVar2,uVar1,9,param_3);
    if (-1 < iVar3) {
      if ((uint)uVar1 < *param_3) {
        iVar3 = -0x3fffffdd;
      }
      else {
        uVar1 = *puVar2;
        *param_2 = uVar1;
        memmove(*(void **)(param_2 + 4),puVar2 + 2,(ulonglong)uVar1);
      }
    }
  }
  return iVar3;
}



===== PriGetString @ 14000297c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int PriGetString(undefined8 param_1,undefined *param_2,ushort *param_3)

{
  int iVar1;
  undefined8 uVar2;
  uint local_res10 [2];
  
  local_res10[0] = 0;
  while( true ) {
    iVar1 = (*(code *)param_2)(param_1,param_3,local_res10);
    if (iVar1 != -0x3fffffdd) break;
    if ((local_res10[0] <= param_3[1]) || (0xffff < local_res10[0])) goto LAB_1400029e3;
    *param_3 = 0;
    uVar2 = PriStringEnsureCapacity(param_3,local_res10[0]);
    if ((int)uVar2 < 0) break;
  }
  if (iVar1 < 0) {
LAB_1400029e3:
    if (param_3 != (ushort *)0x0) {
      if (*(longlong *)(param_3 + 4) != 0) {
        ExFreePoolWithTag(*(longlong *)(param_3 + 4),0x574d6365);
      }
      param_3[0] = 0;
      param_3[1] = 0;
      param_3[2] = 0;
      param_3[3] = 0;
      param_3[4] = 0;
      param_3[5] = 0;
      param_3[6] = 0;
      param_3[7] = 0;
    }
  }
  return iVar1;
}



===== PriStringEnsureCapacity @ 140002a24 =====

undefined8 PriStringEnsureCapacity(ushort *param_1,uint param_2)

{
  void *_Dst;
  undefined8 uVar1;
  
  uVar1 = 0;
  if ((param_1[1] <= param_2) && (param_2 < 0x10000)) {
    _Dst = (void *)ExAllocatePoolWithTag(1,param_2,0x574d6365);
    if (_Dst == (void *)0x0) {
      uVar1 = 0xc0000023;
    }
    else {
      if (*(void **)(param_1 + 4) != (void *)0x0) {
        memmove(_Dst,*(void **)(param_1 + 4),(ulonglong)*param_1);
        if (*(longlong *)(param_1 + 4) != 0) {
          ExFreePoolWithTag(*(longlong *)(param_1 + 4),0x574d6365);
        }
      }
      *(void **)(param_1 + 4) = _Dst;
      param_1[1] = (ushort)param_2;
    }
  }
  return uVar1;
}



===== WMCommListEntryAddRef @ 140002acc =====

undefined4 WMCommListEntryAddRef(longlong param_1)

{
  int *piVar1;
  int iVar2;
  
  LOCK();
  piVar1 = (int *)(param_1 + 0x10);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + 1;
  UNLOCK();
  return CONCAT31((int3)((uint)(iVar2 + 1) >> 8),iVar2 + 1 != -1);
}



===== WMCommListEntryRelease @ 140002ae8 =====

void WMCommListEntryRelease(longlong param_1)

{
  int *piVar1;
  int iVar2;
  
  LOCK();
  piVar1 = (int *)(param_1 + 0x10);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if ((iVar2 == 1) && (param_1 != 0)) {
    if (*(longlong *)(param_1 + 0x30) != 0) {
      ZwClose();
    }
    if (*(longlong *)(param_1 + 0x28) != 0) {
      FltCloseClientPort(gFilterHandle);
    }
    ExFreePoolWithTag(param_1,0x574d6365);
  }
  return;
}



===== _guard_check_icall @ 140002b60 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 140002b78 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 140002b9c =====

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



===== __cpu_features_init @ 140002c10 =====

/* WARNING: Removing unreachable block (ram,0x000140002c7a) */
/* WARNING: Removing unreachable block (ram,0x000140002c29) */
/* WARNING: Removing unreachable block (ram,0x000140002c1a) */

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



===== __security_check_cookie @ 140002ce0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140002d20 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 140002d50 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140002d50. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140002d80 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memmove @ 140002e00 =====

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



===== memset @ 140003100 =====

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



===== __memset_repmovs @ 140003240 =====

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



===== __memset_query @ 1400032c0 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140003340 =====

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



===== __memset_spec_ermsb_repmovsb @ 140003480 =====

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



===== __memset_spec_plain @ 140003500 =====

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



===== InstanceSetup @ 140009010 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int InstanceSetup(longlong param_1,undefined8 param_2,int param_3,int param_4)

{
  bool bVar1;
  int iVar2;
  undefined7 extraout_var;
  ulonglong uVar3;
  int unaff_EBX;
  ulonglong local_res8;
  longlong local_18;
  ulonglong local_10;
  
  local_18 = 0;
  if ((param_1 != 0) && (((param_3 == 7 || (param_3 == 8)) || (param_3 == 9)))) {
    iVar2 = FltGetDiskDeviceObject(*(undefined8 *)(param_1 + 0x10),&local_18);
    if (((((-1 < iVar2) && (local_18 != 0)) && ((*(uint *)(local_18 + 0x34) & 1) == 0)) &&
        ((param_4 != 2 && (param_4 == 0x1c)))) &&
       (local_res8 = (ulonglong)Feature_ReFS_WIM_Mount_Support__private_featureState,
       (Feature_ReFS_WIM_Mount_Support__private_featureState & 0x10) == 0)) {
      uVar3 = (ulonglong)(Feature_ReFS_WIM_Mount_Support__private_featureState | 1);
      local_10 = (ulonglong)(Feature_ReFS_WIM_Mount_Support__private_featureState | 1);
      local_res8 = 3;
      bVar1 = wil_details_FeatureReporting_ReportUsageToServiceDirect(uVar3,local_10,2);
      if (((int)CONCAT71(extraout_var,bVar1) != 0) &&
         (g_wil_details_pfnFeatureLoggingHook != (code *)0x0)) {
        uVar3 = 0x26b38e7;
        (*g_wil_details_pfnFeatureLoggingHook)
                  (0x26b38e7,&Feature_ReFS_WIM_Mount_Support_logged_traits,0,1,&local_res8,0,0,1);
      }
      wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath(uVar3,3);
    }
    if (local_18 != 0) {
      ObfDereferenceObject(local_18);
    }
  }
  return unaff_EBX;
}



===== PFFileSystemControl @ 140009160 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 PFFileSystemControl(longlong param_1,longlong param_2)

{
  longlong lVar1;
  int iVar2;
  undefined1 auStack_78 [32];
  undefined4 local_58;
  undefined8 *local_50;
  undefined4 local_48;
  undefined8 local_40;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  undefined4 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_78;
  local_20 = 0;
  lVar1 = *(longlong *)(param_1 + 0x10);
  local_18 = 0;
  local_30 = 0;
  uStack_28 = 0;
  iVar2 = *(int *)(lVar1 + 0x28);
  if ((((iVar2 != 0x90000) && (iVar2 != 0x90004)) && (iVar2 != 0x90008)) && (iVar2 != 0x9005c)) {
    if (iVar2 != 0x90240) {
      if (iVar2 == 0x94264) {
        iVar2 = -0x3fff5d5d;
      }
      else {
        if (iVar2 != 0x98268) {
          return 1;
        }
        iVar2 = -0x3fff5d5c;
      }
      goto LAB_140009267;
    }
    if (*(uint *)(lVar1 + 0x20) < 0xc) {
      iVar2 = -0x3fffffdd;
      goto LAB_140009267;
    }
    if ((*(uint *)(*(longlong *)(lVar1 + 0x30) + 8) & 1) == 0) {
      return 1;
    }
  }
  local_40 = 0;
  local_50 = &local_30;
  local_48 = 0x1c;
  local_58 = 0;
  iVar2 = FltFsControlFile(*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(lVar1 + 8),0x900a8,0);
  if ((iVar2 == -0x7ffffffb) || (iVar2 == 0)) {
    if ((int)local_30 != -0x7ffffff8) {
      return 1;
    }
    iVar2 = -0x3fffff1e;
  }
  else {
    if (iVar2 == -0x3ffffd8b) {
      return 1;
    }
    if (-1 < iVar2) {
      return 4;
    }
  }
LAB_140009267:
  *(int *)(param_1 + 0x18) = iVar2;
  return 4;
}



===== PFGetContextByFileObject @ 140009294 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int PFGetContextByFileObject
              (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 *param_4,
              undefined1 *param_5)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_c8 [32];
  undefined8 **local_a8;
  undefined8 *local_a0;
  undefined4 local_98;
  undefined8 local_90;
  undefined8 *local_88;
  undefined8 *local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined4 local_58;
  ulonglong local_50;
  
  local_50 = __security_cookie ^ (ulonglong)auStack_c8;
  *param_4 = 0;
  local_88 = (undefined8 *)0x0;
  *param_5 = 0;
  local_80 = (undefined8 *)0x0;
  bVar1 = false;
  local_78 = 0;
  local_60 = 0;
  local_58 = 0;
  local_70 = 0;
  uStack_68 = 0;
  iVar3 = FltGetStreamContext(param_2,param_3,&local_80);
  if (-1 < iVar3) {
    *param_4 = local_80;
    *param_5 = 0;
    goto LAB_14000947c;
  }
  if (iVar3 != -0x3ffffddb) goto LAB_14000947c;
  local_a8 = &local_88;
  iVar3 = FltAllocateContext(param_1,8,0x38,0x200);
  if (iVar3 < 0) goto LAB_14000947c;
  *local_88 = 0;
  local_88[1] = 0;
  local_88[2] = 0;
  local_88[3] = 0;
  local_88[4] = 0;
  local_88[5] = 0;
  local_88[6] = 0;
  *(undefined4 *)(local_88 + 3) = 0;
  KeInitializeEvent(local_88,0,0);
  local_a0 = (undefined8 *)0x0;
  local_a8 = (undefined8 **)CONCAT44(local_a8._4_4_,6);
  iVar3 = FltQueryInformationFile(param_2,param_3,&local_78,8);
  if (iVar3 < 0) goto LAB_14000947c;
  local_88[4] = local_78;
  local_a8 = &local_80;
  iVar3 = FltSetStreamContext(param_2,param_3,1,local_88);
  if (iVar3 == -0x3fe3fffe) {
    *param_4 = local_80;
    *param_5 = 0;
    bVar1 = false;
LAB_140009406:
    iVar3 = 0;
  }
  else {
    if (iVar3 < 0) goto LAB_14000947c;
    local_90 = 0;
    local_a0 = &local_70;
    local_98 = 0x1c;
    local_a8 = (undefined8 **)((ulonglong)local_a8 & 0xffffffff00000000);
    bVar1 = true;
    iVar3 = FltFsControlFile(param_2,param_3,0x900a8,0);
    if ((iVar3 == -0x7ffffffb) || (iVar3 == 0)) {
      iVar3 = 0;
      iVar2 = 0;
      if ((int)local_70 != -0x7ffffff8) goto LAB_14000947c;
    }
    else {
      if (iVar3 == -0x3ffffd8b) goto LAB_140009406;
      iVar2 = iVar3;
      if (iVar3 < 0) goto LAB_14000947c;
    }
    iVar3 = iVar2;
    *param_4 = local_88;
    *param_5 = 1;
    local_88 = (undefined8 *)0x0;
  }
LAB_14000947c:
  if (local_88 != (undefined8 *)0x0) {
    if (bVar1) {
      KeSetEvent(local_88,0,0);
      FltDeleteStreamContext(param_2,param_3,0);
    }
    FltReleaseContext(local_88);
  }
  return iVar3;
}



===== PFGetWritableHandle @ 1400094ec =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int PFGetWritableHandle(longlong param_1,longlong param_2,longlong param_3,undefined8 param_4,
                       longlong *param_5)

{
  bool bVar1;
  undefined4 uVar2;
  ulonglong uVar3;
  int iVar4;
  undefined1 auStack_138 [32];
  undefined8 *local_118;
  undefined8 *local_110;
  undefined8 local_108;
  undefined4 local_100;
  undefined4 local_f8;
  undefined4 local_f0;
  undefined4 local_e8;
  undefined8 local_e0;
  undefined4 local_d8;
  undefined4 local_d0;
  longlong local_c8;
  short local_c0;
  undefined2 uStack_be;
  undefined4 uStack_bc;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined8 local_b0;
  undefined8 uStack_a8;
  short *local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  ulonglong local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_138;
  local_110 = (undefined8 *)0x0;
  local_c8 = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_50 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_80 = 0;
  uStack_78 = 0;
  bVar1 = false;
  local_118 = (undefined8 *)CONCAT44(local_118._4_4_,4);
  uStack_bc = *(undefined4 *)(param_3 + 0xc);
  uStack_b8 = *(undefined4 *)(param_3 + 0x10);
  uStack_b4 = *(undefined4 *)(param_3 + 0x14);
  local_b0 = 0;
  uStack_a8 = 0;
  local_a0 = (short *)0x0;
  uStack_98 = 0;
  local_90 = 0;
  uStack_88 = 0;
  _local_c0 = CONCAT22((short)((uint)*(undefined4 *)(param_3 + 8) >> 0x10),
                       (short)*(undefined4 *)(param_3 + 8) -
                       *(short *)(*(longlong *)(param_1 + 0x28) + 6));
  iVar4 = FltQueryInformationFile(*(undefined8 *)(param_2 + 0x18),param_4,&local_70,0x28);
  uVar3 = local_50;
  if (-1 < iVar4) {
    uVar2 = (undefined4)local_50;
    if ((local_50 & 1) != 0) {
      local_118 = (undefined8 *)CONCAT44(local_118._4_4_,4);
      local_50 = local_50 & 0xfffffffffffffffe;
      iVar4 = FltSetInformationFile(*(undefined8 *)(param_2 + 0x18),param_4,&local_70,0x28);
      if (iVar4 < 0) goto LAB_1400096c1;
      bVar1 = true;
    }
    uStack_a8 = 0;
    local_a0 = &local_c0;
    local_d0 = 0x800;
    local_b0 = CONCAT44(local_b0._4_4_,0x30);
    uStack_98 = CONCAT44(uStack_98._4_4_,0x240);
    local_110 = &local_80;
    local_d8 = 0;
    local_e0 = 0;
    local_e8 = 0x204020;
    local_f0 = 3;
    local_f8 = 7;
    local_100 = 0x80;
    local_108 = 0;
    local_118 = &local_b0;
    local_90 = 0;
    uStack_88 = 0;
    iVar4 = FltCreateFile(*(undefined8 *)(param_2 + 8),*(undefined8 *)(param_2 + 0x18),&local_c8,
                          (-(uint)((uVar3 & 0x10) != 0) & 0x1030000) + 0xc0100000);
    if (-1 < iVar4) {
      if (bVar1) {
        local_50 = CONCAT44(local_50._4_4_,uVar2);
        local_118 = (undefined8 *)CONCAT44(local_118._4_4_,4);
        iVar4 = FltSetInformationFile(*(undefined8 *)(param_2 + 0x18),param_4,&local_70,0x28);
        if (iVar4 < 0) goto LAB_1400096c1;
      }
      *param_5 = local_c8;
      local_c8 = 0;
    }
  }
LAB_1400096c1:
  if (local_c8 != 0) {
    FltClose();
  }
  return iVar4;
}



===== PFOnlyConsiderDirectories @ 140009700 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int PFOnlyConsiderDirectories
              (longlong param_1,longlong param_2,undefined8 param_3,longlong *param_4,
              undefined1 *param_5)

{
  uint *puVar1;
  longlong *plVar2;
  longlong lVar3;
  int iVar4;
  char local_res10 [8];
  
  local_res10[0] = '\0';
  iVar4 = FltIsDirectory(param_3,*(undefined8 *)(param_2 + 0x18),local_res10);
  if (((-1 < iVar4) && (param_4 != (longlong *)0x0)) && (local_res10[0] == '\0')) {
    plVar2 = (longlong *)*param_4;
    if (plVar2 == (longlong *)0x0) {
      puVar1 = (uint *)(*(longlong *)(param_1 + 0x10) + 0x20);
      *puVar1 = *puVar1 | *(uint *)(param_4 + 7);
      FltSetCallbackDataDirty(param_1);
    }
    else if ((longlong *)*plVar2 != plVar2) {
      (*DAT_140006160)(*(undefined8 *)(param_2 + 8),param_1);
      lVar3 = *param_4;
      *(longlong *)(lVar3 + 8) = lVar3;
      *(longlong *)lVar3 = lVar3;
    }
    FltReissueSynchronousIo(*(undefined8 *)(param_2 + 0x18),param_1);
    *param_5 = 1;
  }
  return iVar4;
}



===== PFOpenReparseTarget @ 1400097cc =====

int PFOpenReparseTarget(longlong param_1,longlong param_2,longlong *param_3,longlong *param_4)

{
  longlong lVar1;
  longlong lVar2;
  char cVar3;
  int iVar4;
  longlong local_88;
  longlong local_80;
  longlong local_78;
  short local_70;
  undefined6 uStack_6e;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 *local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  
  local_78 = 0;
  local_88 = 0;
  local_80 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = (undefined8 *)0x0;
  uStack_38 = 0;
  local_30 = 0;
  uStack_28 = 0;
  local_60 = 0;
  uStack_58 = 0;
  _local_70 = 0;
  uStack_68 = 0;
  iVar4 = FltGetFileNameInformation(0,0x4000102,&local_88);
  if (-1 < iVar4) {
    uStack_68 = *(undefined8 *)(local_88 + 0x10);
    _local_70 = CONCAT62(*(undefined6 *)(local_88 + 10),
                         *(short *)(local_88 + 8) - *(short *)(*(longlong *)(param_1 + 0x28) + 6));
    cVar3 = PFPathIsUnderTempDir((uint *)&local_70);
    if (cVar3 == '\0') {
      local_40 = (undefined8 *)&local_70;
      uStack_48 = 0;
      local_50 = CONCAT44(local_50._4_4_,0x30);
      uStack_38 = CONCAT44(uStack_38._4_4_,0x240);
      local_30 = 0;
      uStack_28 = 0;
      iVar4 = FltCreateFile(*(undefined8 *)(param_2 + 8),*(undefined8 *)(param_2 + 0x18),&local_78,
                            0x80100110,&local_50,&local_60,0,0x80,7,3,0x204020,0,0,0x800);
      if (-1 < iVar4) {
        iVar4 = ObReferenceObjectByHandle
                          (local_78,0xf0000,*(undefined8 *)IoFileObjectType_exref,0,&local_80,0);
        lVar2 = local_80;
        lVar1 = local_88;
        if (-1 < iVar4) {
          local_80 = 0;
          *param_4 = lVar2;
          if (param_3 != (longlong *)0x0) {
            local_88 = 0;
            *param_3 = lVar1;
          }
        }
      }
    }
    else {
      iVar4 = -0x3fffffde;
    }
  }
  if (local_78 != 0) {
    FltClose();
  }
  if (local_80 != 0) {
    ObfDereferenceObject();
  }
  if (local_88 != 0) {
    FltReleaseFileNameInformation();
  }
  return iVar4;
}



===== PFPostCreate @ 1400099c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 PFPostCreate(longlong param_1,longlong param_2,longlong *param_3)

{
  uint *puVar1;
  uint *puVar2;
  void *pvVar3;
  ushort uVar4;
  uint uVar5;
  longlong lVar6;
  undefined8 uVar7;
  longlong *plVar8;
  longlong lVar9;
  longlong lVar10;
  char local_res8;
  char local_res18 [16];
  char local_78;
  char local_77;
  longlong local_70;
  longlong local_68;
  longlong local_60;
  longlong local_58;
  longlong local_50;
  code *local_48;
  longlong *local_40;
  
  local_70 = 0;
  local_48 = (code *)0x0;
  local_40 = (longlong *)0x0;
  uVar5 = 0;
  local_58 = 0;
  lVar9 = 0;
  local_res8 = '\0';
  lVar10 = 0;
  if (param_3 == (longlong *)0x0) goto LAB_140009abd;
  puVar1 = (uint *)(param_3 + 7);
  if (((*(int *)(param_1 + 0x18) + 0x3ffffd8aU & 0xfffffffd) != 0) || (*puVar1 == 0)) {
    if (*(int *)(param_1 + 0x18) != 0x104) goto LAB_140009abd;
    if (*(longlong *)(param_1 + 0x20) == 0x80000008) {
      if (*(longlong *)(param_2 + 0x28) != 0) goto LAB_140009abd;
      if (*(short *)(*(longlong *)(param_1 + 0x28) + 6) != 0) {
        local_48 = PFOnlyConsiderDirectories;
        local_40 = param_3;
        goto LAB_140009abd;
      }
    }
    else if (*puVar1 == 0) goto LAB_140009abd;
  }
  plVar8 = (longlong *)*param_3;
  if (plVar8 == (longlong *)0x0) {
    puVar2 = (uint *)(*(longlong *)(param_1 + 0x10) + 0x20);
    *puVar2 = *puVar2 | *puVar1;
    FltSetCallbackDataDirty(param_1);
  }
  else if ((longlong *)*plVar8 != plVar8) {
    (*DAT_140006160)(*(undefined8 *)(param_2 + 8),param_1);
    lVar6 = *param_3;
    *(longlong *)(lVar6 + 8) = lVar6;
    *(longlong *)lVar6 = lVar6;
  }
  FltReissueSynchronousIo(*(undefined8 *)(param_2 + 0x18),param_1);
LAB_140009abd:
  if (*(int *)(param_1 + 0x18) == 0x104) {
    do {
      lVar9 = 0;
      local_res8 = '\0';
      if ((*(int **)(param_1 + 0x28) == (int *)0x0) || (**(int **)(param_1 + 0x28) != -0x7ffffff8))
      break;
      lVar6 = IoGetTopLevelIrp();
      if (lVar6 != 0) break;
      local_50 = 0;
      local_60 = 0;
      local_77 = '\0';
      lVar9 = 0;
      local_68 = 0;
      local_res8 = '\0';
      local_78 = '\0';
      uVar5 = PFOpenReparseTarget(param_1,param_2,&local_60,&local_50);
      lVar6 = local_50;
      if ((uVar5 + 0x80000000 & 0x80000000) == 0) {
        if (uVar5 == 0xc0000275) goto LAB_140009b44;
LAB_140009bec:
      }
      else {
LAB_140009b44:
        if (uVar5 == 0xc0000275) {
          uVar5 = 0;
        }
        else if (local_48 == (code *)0x0) {
LAB_140009b97:
          uVar5 = PFGetContextByFileObject
                            (*(undefined8 *)(param_2 + 8),*(undefined8 *)(param_2 + 0x18),lVar6,
                             &local_68,&local_78);
          local_res8 = local_78;
          if (local_78 != '\0') {
            uVar5 = PFGetWritableHandle(param_1,param_2,local_60,lVar6,&local_70);
            lVar9 = local_68;
            lVar10 = local_70;
            goto LAB_140009bec;
          }
          lVar9 = local_68;
        }
        else {
          local_res18[0] = '\0';
          uVar5 = (*local_48)(param_1,param_2,local_50,local_40,local_res18);
          if (-1 < (int)uVar5) {
            if (local_res18[0] == '\0') goto LAB_140009b97;
            uVar5 = 0;
            local_77 = '\x01';
          }
        }
      }
      if (lVar6 != 0) {
        ObfDereferenceObject(lVar6);
      }
      if (local_60 != 0) {
        FltReleaseFileNameInformation(local_60);
      }
      if ((int)uVar5 < 0) {
        if (local_res8 != '\0') {
          *(uint *)(lVar9 + 0x18) = uVar5;
          KeSetEvent(lVar9,0,0);
          FltDeleteStreamContext(*(undefined8 *)(param_2 + 0x18),0,0);
          local_res8 = '\0';
        }
        if (lVar9 != 0) {
          FltReleaseContext(lVar9);
          lVar9 = 0;
          break;
        }
        if ((int)uVar5 < 0) break;
      }
      if (local_77 != '\0') break;
      if (local_res8 == '\0') {
        if (lVar9 != 0) {
          uVar5 = KeWaitForSingleObject(lVar9,6,0,1,0);
          if (uVar5 != 0x101) {
            if ((int)uVar5 < 0) break;
            if (-1 < *(int *)(lVar9 + 0x18)) goto LAB_140009d60;
          }
          uVar5 = *(uint *)(lVar9 + 0x18);
          break;
        }
      }
      else {
        pvVar3 = (void *)(*(longlong *)(param_1 + 0x28) + 8);
        uVar5 = (uint)*(ushort *)(*(longlong *)(param_1 + 0x28) + 4);
        local_68 = CONCAT44(local_68._4_4_,uVar5);
        if (uVar5 < 0x10) {
          uVar5 = 0xc000000d;
          break;
        }
        plVar8 = &local_58;
        uVar7 = WMCommListGet(pvVar3,plVar8);
        uVar5 = (uint)uVar7;
        if (uVar5 == 0xc0000225) {
          uVar5 = 0x104;
          break;
        }
        if ((int)uVar5 < 0) break;
        PsGetCurrentProcessId();
        uVar5 = PFSendExtractMessage(&local_70,plVar8,local_58,pvVar3,(uint)local_68);
        *(uint *)(lVar9 + 0x18) = uVar5;
        PFSetSubsumedStatus(*(undefined8 *)(param_2 + 0x18),lVar9,uVar5);
        lVar10 = local_70;
        if ((int)uVar5 < 0) break;
      }
LAB_140009d60:
      uVar5 = PFReleaseContextAndUntagFile(param_1,param_2,lVar9,local_res8,lVar10,'\x01');
      lVar9 = 0;
      if ((int)uVar5 < 0) break;
      local_res8 = '\0';
      if (lVar10 != 0) {
        FltClose(lVar10);
        lVar10 = 0;
        local_70 = 0;
      }
      FltReissueSynchronousIo(*(undefined8 *)(param_2 + 0x18),param_1);
    } while (*(int *)(param_1 + 0x18) == 0x104);
    if (local_58 != 0) {
      WMCommListEntryRelease(local_58);
    }
  }
  if (param_3 != (longlong *)0x0) {
    plVar8 = (longlong *)*param_3;
    if ((plVar8 != (longlong *)0x0) && ((longlong *)*plVar8 != plVar8)) {
      (*DAT_140006160)(*(undefined8 *)(param_2 + 8),param_1);
    }
    _DAT_14000629c = _DAT_14000629c + 1;
    uVar4 = ExQueryDepthSList(&DAT_140006280);
    if (uVar4 < DAT_140006290) {
      ExpInterlockedPushEntrySList(&DAT_140006280,param_3);
    }
    else {
      _DAT_1400062a0 = _DAT_1400062a0 + 1;
      (*DAT_1400062b8)(param_3);
    }
  }
  if (lVar9 != 0) {
    PFReleaseContextAndUntagFile(param_1,param_2,lVar9,local_res8,lVar10,'\0');
  }
  if (lVar10 != 0) {
    FltClose(lVar10);
  }
  if ((int)uVar5 < 0) {
    *(uint *)(param_1 + 0x18) = uVar5;
  }
  return 0;
}



===== PFPreCreate @ 140009ee0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 PFPreCreate(longlong param_1,longlong param_2,undefined8 *param_3)

{
  uint *puVar1;
  longlong *plVar2;
  code *pcVar3;
  ushort uVar4;
  int iVar5;
  undefined8 *puVar6;
  longlong *_Dst;
  undefined8 uVar7;
  undefined4 local_res8 [2];
  
  uVar7 = 0;
  if ((*(uint *)(*(longlong *)(param_1 + 0x10) + 0x20) & 0x200000) == 0) {
    return 0;
  }
  local_res8[0] = FltGetRequestorProcessId();
  FltAcquireResourceShared(&DAT_1400061e0);
  puVar6 = PriGetEntry(MatchByProcessId,local_res8);
  FltReleaseResource(&DAT_1400061e0);
  if (puVar6 != (undefined8 *)0x0) {
    return 0;
  }
  _DAT_140006294 = _DAT_140006294 + 1;
  _Dst = (longlong *)ExpInterlockedPopEntrySList(&DAT_140006280);
  if (_Dst == (longlong *)0x0) {
    _DAT_140006298 = _DAT_140006298 + 1;
    _Dst = (longlong *)(*DAT_1400062b0)(DAT_1400062a4,DAT_1400062ac,DAT_1400062a8);
  }
  if (_Dst == (longlong *)0x0) {
    iVar5 = -0x3fffff66;
LAB_14000a08f:
    *(int *)(param_1 + 0x18) = iVar5;
    uVar7 = 4;
  }
  else {
    memset(_Dst,0,0x40);
    pcVar3 = DAT_1400061b0;
    if (DAT_1400061a8 == '\0') {
      *(undefined4 *)(_Dst + 7) = 0x200000;
      puVar1 = (uint *)(*(longlong *)(param_1 + 0x10) + 0x20);
      *puVar1 = *puVar1 & 0xffdfffff;
    }
    else {
      plVar2 = _Dst + 1;
      _Dst[2] = (longlong)plVar2;
      *plVar2 = (longlong)plVar2;
      *(undefined4 *)(_Dst + 3) = 0x80000008;
      *(undefined4 *)((longlong)_Dst + 0x1c) = 0x8000007e;
      *(undefined4 *)(_Dst + 6) = 0x30;
      iVar5 = (*pcVar3)(*(undefined8 *)(param_2 + 8),param_1,plVar2);
      if (iVar5 < 0) {
        plVar2 = (longlong *)*_Dst;
        if ((plVar2 != (longlong *)0x0) && ((longlong *)*plVar2 != plVar2)) {
          (*DAT_140006160)(*(undefined8 *)(param_2 + 8),param_1);
        }
        _DAT_14000629c = _DAT_14000629c + 1;
        uVar4 = ExQueryDepthSList(&DAT_140006280);
        if (uVar4 < DAT_140006290) {
          ExpInterlockedPushEntrySList(&DAT_140006280,_Dst);
        }
        else {
          _DAT_1400062a0 = _DAT_1400062a0 + 1;
          (*DAT_1400062b8)(_Dst);
        }
        goto LAB_14000a08f;
      }
      *_Dst = (longlong)plVar2;
    }
    FltSetCallbackDataDirty(param_1);
    *param_3 = _Dst;
  }
  return uVar7;
}



===== PFReleaseContextAndUntagFile @ 14000a0d8 =====

int PFReleaseContextAndUntagFile
              (longlong param_1,longlong param_2,longlong param_3,char param_4,longlong param_5,
              char param_6)

{
  int iVar1;
  longlong local_18 [2];
  
  local_18[0] = 0;
  if (param_4 == '\0') {
LAB_14000a1e3:
    if (param_3 != 0) {
      FltReleaseContext(param_3);
    }
    iVar1 = 0;
  }
  else {
    if (param_5 == 0) {
      iVar1 = PFOpenReparseTarget(param_1,param_2,(longlong *)0x0,local_18);
    }
    else {
      iVar1 = ObReferenceObjectByHandle
                        (param_5,0xf0000,*(undefined8 *)IoFileObjectType_exref,0,local_18,0);
    }
    if (-1 < iVar1) {
      if (param_6 != '\0') {
        iVar1 = FltUntagFile(*(undefined8 *)(param_2 + 0x18),local_18[0],0x80000008,0);
        if (iVar1 == -0x3ffffd8b) {
          iVar1 = 0;
        }
      }
      KeSetEvent(param_3,0,0);
      FltDeleteStreamContext(*(undefined8 *)(param_2 + 0x18),local_18[0],0);
      if ((param_6 == '\0') || (-1 < iVar1)) goto LAB_14000a1e3;
    }
    *(int *)(param_3 + 0x18) = iVar1;
    KeSetEvent(param_3,0,0);
    FltReleaseContext(param_3);
  }
  if (local_18[0] != 0) {
    ObfDereferenceObject();
  }
  return iVar1;
}



===== Unload @ 14000a230 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 Unload(void)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  longlong *plVar4;
  undefined8 uVar5;
  undefined8 local_28;
  wchar_t *local_20;
  undefined8 local_18;
  wchar_t *local_10;
  
  if (gFilterHandle != 0) {
    if (DAT_1400061b8 != 0) {
      FltCloseCommunicationPort();
      DAT_1400061b8 = 0;
    }
    FltUnregisterFilter(gFilterHandle);
    FltAcquireResourceExclusive(&DAT_1400061e0);
    while ((plVar4 = g_CommList, (longlong **)g_CommList != &g_CommList &&
           (g_CommList != (longlong *)0x0))) {
      lVar1 = *g_CommList;
      if ((*(longlong **)(lVar1 + 8) != g_CommList) ||
         (plVar2 = (longlong *)g_CommList[1], (longlong *)*plVar2 != g_CommList)) {
        pcVar3 = (code *)swi(0x29);
        (*pcVar3)(3);
        pcVar3 = (code *)swi(3);
        uVar5 = (*pcVar3)();
        return uVar5;
      }
      *plVar2 = lVar1;
      *(longlong **)(lVar1 + 8) = plVar2;
      WMCommListEntryRelease((longlong)plVar4);
    }
    FltReleaseResource(&DAT_1400061e0);
    ExDeleteResourceLite(&DAT_1400061e0);
    gFilterHandle = 0;
  }
  ExDeletePagedLookasideList(&DAT_140006280);
  if (DAT_140006189 != '\0') {
    ExDeleteResourceLite(&DAT_1400060f0);
  }
  lVar1 = g_wil_details_featureChangeNotification;
  if (DAT_140006188 == '\0') {
    return 0;
  }
  if (g_wil_details_featureChangeNotification == 0) goto LAB_14000a390;
  if (g_wil_details_pfnRtlUnregisterFeatureConfigurationChangeNotification == (code *)0x0) {
    local_28 = 0x680066;
    local_20 = L"RtlUnregisterFeatureConfigurationChangeNotification";
    g_wil_details_pfnRtlUnregisterFeatureConfigurationChangeNotification =
         (code *)MmGetSystemRoutineAddress(&local_28);
    if (g_wil_details_pfnRtlUnregisterFeatureConfigurationChangeNotification != (code *)0x0)
    goto LAB_14000a380;
  }
  else {
LAB_14000a380:
    (*g_wil_details_pfnRtlUnregisterFeatureConfigurationChangeNotification)(lVar1);
  }
  g_wil_details_featureChangeNotification = 0;
LAB_14000a390:
  lVar1 = g_wil_details_featureUsageProvider;
  if (g_wil_details_featureUsageProvider == 0) {
    g_wil_details_isFeatureStagingInitialized = 0;
    return 0;
  }
  if (g_wil_details_pfnRtlUnregisterFeatureUsageProvider == (code *)0x0) {
    local_18 = 0x440042;
    local_10 = L"RtlUnregisterFeatureUsageProvider";
    g_wil_details_pfnRtlUnregisterFeatureUsageProvider =
         (code *)MmGetSystemRoutineAddress(&local_18);
    if (g_wil_details_pfnRtlUnregisterFeatureUsageProvider == (code *)0x0) {
      g_wil_details_featureUsageProvider = 0;
      g_wil_details_isFeatureStagingInitialized = 0;
      return 0;
    }
  }
  (*g_wil_details_pfnRtlUnregisterFeatureUsageProvider)(lVar1);
  g_wil_details_isFeatureStagingInitialized = 0;
  g_wil_details_featureUsageProvider = 0;
  return 0;
}



===== wil_details_EvaluateFeatureDependencies @ 14000a40c =====

void wil_details_EvaluateFeatureDependencies(void)

{
  uint uVar1;
  undefined **ppuVar2;
  undefined **ppuVar3;
  undefined *puVar4;
  bool bVar5;
  
  puVar4 = (undefined *)0x0;
  ppuVar3 = &Feature_ReFS_WIM_Mount_Support__private_descriptor;
  ppuVar2 = &Feature_ReFS_WIM_Mount_Support__private_descriptor;
  do {
    if (*ppuVar2 != (undefined *)0x0) goto joined_r0x00014000a447;
    ppuVar2 = ppuVar2 + 1;
  } while (ppuVar2 < &wil_details_featureDescriptors_z);
LAB_14000a4c1:
  while( true ) {
    if (&UNK_140005f5f < ppuVar3) {
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
      if (&UNK_140005f5f < ppuVar3) {
        return;
      }
      if (*ppuVar3 != puVar4) break;
      ppuVar3 = ppuVar3 + 1;
    }
  } while( true );
joined_r0x00014000a447:
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
      if (&UNK_140005f5f < ppuVar2) goto LAB_14000a4c1;
      if (*ppuVar2 != (undefined *)0x0) break;
      ppuVar2 = ppuVar2 + 1;
    }
  }
  goto LAB_14000a4c1;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 14000a4fc =====

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
          if (puVar1 == (undefined8 *)0x0) goto LAB_14000a594;
          if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
             (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
          if ((uVar4 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
            uVar4 = 0;
            goto LAB_14000a594;
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
LAB_14000a594:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 14000a5e0 =====

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
      for (ppuVar2 = &Feature_ReFS_WIM_Mount_Support__private_descriptor;
          ppuVar2 < &wil_details_featureDescriptors_z; ppuVar2 = ppuVar2 + 1) {
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
              if (&UNK_140005f5f < ppuVar2) {
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



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 14000a660 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_ReevaluateOnFeatureConfigurationChange(void)

{
  int iVar1;
  undefined8 uVar2;
  uint uVar3;
  undefined **ppuVar4;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined8 local_20;
  undefined4 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  for (ppuVar4 = &Feature_ReFS_WIM_Mount_Support__private_descriptor;
      ppuVar4 < &wil_details_featureDescriptors_z; ppuVar4 = ppuVar4 + 1) {
    if (*ppuVar4 != (undefined *)0x0) goto LAB_14000a756;
  }
LAB_14000a75f:
  wil_details_EvaluateFeatureDependencies();
  return;
LAB_14000a756:
  if (ppuVar4 == (undefined **)0x0) goto LAB_14000a75f;
  if (((*(char *)((longlong)ppuVar4 + 0x1d) == '\0') &&
      (*(char *)((longlong)ppuVar4 + 0x1e) == '\0')) &&
     (*(char *)((longlong)ppuVar4 + 0x1c) == '\0')) {
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    uVar2 = wil_details_RtlQueryFeatureConfiguration
                      (*(undefined4 *)(ppuVar4 + 3),1,&local_28,&local_20);
    iVar1 = (int)uVar2;
    if ((iVar1 == -0x7fffffde) || (iVar1 == -0x3ffffddb)) {
LAB_14000a727:
      uVar3 = 0x206;
    }
    else {
      if (iVar1 == 0) {
        uVar3 = (local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0;
      }
      else {
        if (iVar1 != 0x117) goto LAB_14000a727;
        uVar3 = local_20._4_4_ & 0x80;
      }
      uVar3 = uVar3 << 3 | 0x206;
    }
    LOCK();
    *(uint *)*ppuVar4 = *(uint *)*ppuVar4 ^ (*(uint *)*ppuVar4 ^ uVar3) & 0xf80;
    UNLOCK();
  }
  ppuVar4 = ppuVar4 + 7;
  while( true ) {
    if (&UNK_140005f5f < ppuVar4) goto LAB_14000a75f;
    if (*ppuVar4 != (undefined *)0x0) break;
    ppuVar4 = ppuVar4 + 1;
  }
  goto LAB_14000a756;
}



===== PFPortConnect @ 14000a790 =====

int PFPortConnect(longlong param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined8 *in_stack_00000028;
  
  iVar2 = 0;
  puVar1 = (undefined4 *)0x0;
  if ((param_1 == 0) || (in_stack_00000028 == (undefined8 *)0x0)) {
    iVar2 = -0x3ffffff3;
  }
  else {
    puVar1 = (undefined4 *)ExAllocatePoolWithTag(1,0x30,0x574d6363);
    if (puVar1 == (undefined4 *)0x0) {
      iVar2 = -0x3fffff66;
      goto LAB_14000a818;
    }
    *puVar1 = 3;
    *(undefined8 *)(puVar1 + 4) = gFilterHandle;
    *(longlong *)(puVar1 + 2) = param_1;
    puVar1[10] = 0;
    *in_stack_00000028 = puVar1;
  }
  if (-1 < iVar2) {
    return iVar2;
  }
LAB_14000a818:
  if (puVar1 != (undefined4 *)0x0) {
    ExFreePoolWithTag(puVar1,0x574d6363);
  }
  return iVar2;
}



===== PFPortDisconnect @ 14000a850 =====

void PFPortDisconnect(longlong param_1)

{
  longlong lVar1;
  longlong *plVar2;
  undefined8 uVar3;
  code *pcVar4;
  longlong *plVar5;
  undefined1 *puVar6;
  int iVar7;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [40];
  
  puVar6 = auStack_38;
  if (param_1 == 0) {
    return;
  }
  if (*(int *)(param_1 + 0x28) != 0) {
    iVar7 = 0;
    FltAcquireResourceExclusive(&DAT_1400061e0);
    plVar5 = PriGetEntry(MatchByGuid,param_1 + 0x18);
    if (plVar5 == (longlong *)0x0) {
      iVar7 = -0x3ffffddb;
    }
    else {
      lVar1 = *plVar5;
      plVar2 = (longlong *)plVar5[1];
      if ((*(longlong **)(lVar1 + 8) != plVar5) || ((longlong *)*plVar2 != plVar5)) {
        pcVar4 = (code *)swi(0x29);
        (*pcVar4)(3);
        puVar6 = auStack_30;
        goto LAB_14000a8df;
      }
      *plVar2 = lVar1;
      *(longlong **)(lVar1 + 8) = plVar2;
      WMCommListEntryRelease((longlong)plVar5);
    }
    FltReleaseResource(&DAT_1400061e0);
    puVar6 = auStack_38;
    if (iVar7 < 0) {
      return;
    }
  }
LAB_14000a8df:
  if (*(longlong *)(param_1 + 8) != 0) {
    uVar3 = *(undefined8 *)(param_1 + 0x10);
    *(undefined8 *)(puVar6 + -8) = 0x14000a8f4;
    FltCloseClientPort(uVar3);
  }
  *(undefined8 *)(puVar6 + -8) = 0x14000a908;
  ExFreePoolWithTag(param_1,0x574d6363);
  return;
}



===== PFReceiveMessage @ 14000a930 =====

ulonglong PFReceiveMessage(int *param_1,void *param_2,uint param_3,undefined8 *param_4,uint param_5,
                          undefined4 *param_6)

{
  ulonglong uVar1;
  
  if (param_1 == (int *)0x0) {
    uVar1 = 0xc00000ef;
  }
  else {
    uVar1 = PriProcessMessage(param_1,param_2,param_3,param_4,param_5,param_6);
  }
  return uVar1;
}



===== PFSendExchangeCloseHandlesMessage @ 14000a964 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong PFSendExchangeCloseHandlesMessage
                    (undefined8 param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  uint uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  undefined1 auStack_c8 [32];
  longlong *local_a8;
  undefined4 *local_a0;
  undefined8 local_98;
  undefined4 local_88 [2];
  longlong local_80 [7];
  undefined4 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_c8;
  local_80[0] = 0;
  local_88[0] = 0x14;
  local_48 = 0;
  local_80[1] = 0;
  local_80[2] = 0;
  local_80[3] = 0;
  local_80[4] = 0;
  local_80[5] = 0;
  local_80[6] = 0;
  uVar3 = WMCommListGet(param_2 + 0x18,local_80);
  lVar1 = local_80[0];
  uVar4 = uVar3 & 0xffffffff;
  if (-1 < (int)uVar3) {
    local_98 = 0;
    local_a0 = local_88;
    local_a8 = local_80 + 5;
    local_80[1] = 0x1000342424242;
    local_80[2] = 0x900000020;
    local_80[3] = param_3;
    local_80[4] = param_4;
    uVar2 = FltSendMessage(param_1,local_80[0] + 0x28,local_80 + 1);
    uVar4 = (ulonglong)uVar2;
    if (-1 < (int)uVar2) {
      uVar4 = (ulonglong)local_80[6] >> 0x20;
    }
  }
  if (lVar1 != 0) {
    WMCommListEntryRelease(lVar1);
  }
  return uVar4;
}



===== PFSendExtractMessage @ 14000aa58 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint PFSendExtractMessage
               (undefined8 *param_1,undefined8 param_2,longlong param_3,void *param_4,uint param_5)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  ulonglong _Size;
  undefined1 auStack_e8 [32];
  void **local_c8;
  undefined4 *local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  void *local_a8;
  undefined4 local_a0 [2];
  undefined8 local_98;
  longlong local_90;
  longlong local_88;
  undefined8 local_80;
  undefined8 local_78;
  void *local_70;
  undefined8 uStack_68;
  undefined4 local_60;
  longlong local_58;
  longlong local_50;
  void *local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_e8;
  _Size = (ulonglong)param_5;
  local_60 = 0;
  local_a0[0] = 0x14;
  local_98 = 0;
  local_80 = 0;
  local_78 = 0;
  local_90 = 0;
  local_70 = (void *)0x0;
  uStack_68 = 0;
  local_88 = 0;
  bVar1 = false;
  local_a8 = param_4;
  puVar4 = (undefined4 *)ExAllocatePoolWithTag(1,_Size + 0x38,0x574d6d67);
  if (puVar4 == (undefined4 *)0x0) {
    uVar2 = 0xc000009a;
    goto LAB_14000ad0e;
  }
  local_b8 = CONCAT44(local_b8._4_4_,6);
  local_c0 = (undefined4 *)((ulonglong)local_c0 & 0xffffffff00000000);
  local_c8 = (void **)((ulonglong)local_c8 & 0xffffffff00000000);
  uVar2 = ZwDuplicateObject(0xffffffffffffffff,*param_1,*(undefined8 *)(param_3 + 0x30),&local_98);
  if (-1 < (int)uVar2) {
    FltClose(*param_1);
    *param_1 = 0;
    *puVar4 = 0x42424242;
    if ((*(ushort *)(param_3 + 0x3c) < 4) &&
       ((*(ushort *)(param_3 + 0x3c) != 3 || (*(short *)(param_3 + 0x3e) == 0)))) {
      puVar4[1] = 3;
      puVar4[3] = 0;
      puVar4[2] = param_5 + 0x20;
      puVar4[6] = param_5;
      memmove(puVar4 + 7,local_a8,_Size);
      *(undefined8 *)(puVar4 + 4) = local_98;
LAB_14000ac02:
      local_c0 = local_a0;
      local_b8 = 0;
      local_c8 = &local_70;
      uVar2 = FltSendMessage(gFilterHandle,param_3 + 0x28,puVar4,puVar4[2]);
      if (((-1 < (int)uVar2) && (uVar2 = uStack_68._4_4_, -1 < uStack_68)) && (bVar1)) {
        local_c8 = &local_a8;
        local_c0 = (undefined4 *)0x0;
        local_a8 = (void *)0x0;
        uVar2 = ObReferenceObjectByHandle
                          (*(undefined8 *)(param_3 + 0x30),0xf0000,
                           *(undefined8 *)PsProcessType_exref,0);
        if (-1 < (int)uVar2) {
          local_58 = local_88;
          local_b0 = 0;
          local_50 = local_90;
          local_b8 = 0;
          local_c0 = (undefined4 *)CONCAT71(local_c0._1_7_,1);
          local_48 = local_a8;
          local_c8 = (void **)((ulonglong)local_c8 & 0xffffffffffffff00);
          iVar3 = KeWaitForMultipleObjects(3,&local_58,1);
          uVar2 = -(uint)(iVar3 != 1) & 0xc0000267;
        }
        if (local_a8 != (void *)0x0) {
          ObfDereferenceObject();
        }
      }
    }
    else {
      puVar4[2] = param_5 + 0x30;
      puVar4[1] = 0x10003;
      puVar4[3] = 4;
      puVar4[10] = param_5;
      memmove(puVar4 + 0xb,local_a8,_Size);
      *(undefined8 *)(puVar4 + 4) = local_98;
      uVar2 = DuplicateEventIntoProcess(*(undefined8 *)(param_3 + 0x30),&local_80,&local_90);
      if (-1 < (int)uVar2) {
        uVar2 = DuplicateEventIntoProcess(*(undefined8 *)(param_3 + 0x30),&local_78,&local_88);
        if (-1 < (int)uVar2) {
          *(undefined8 *)(puVar4 + 6) = local_80;
          bVar1 = true;
          *(undefined8 *)(puVar4 + 8) = local_78;
          goto LAB_14000ac02;
        }
      }
    }
  }
  ExFreePoolWithTag(puVar4,0x574d6d67);
LAB_14000ad0e:
  if (local_90 != 0) {
    ObfDereferenceObject();
  }
  if (local_88 != 0) {
    ObfDereferenceObject();
  }
  return uVar2;
}



===== PriDuplicateUserBuffer @ 14000ad68 =====

undefined8 PriDuplicateUserBuffer(void *param_1,uint param_2,undefined8 *param_3)

{
  void *_Dst;
  undefined8 uVar1;
  
  uVar1 = 0;
  _Dst = (void *)ExAllocatePoolWithTag(1,param_2,0x574d6365);
  if (_Dst == (void *)0x0) {
    uVar1 = 0xc000009a;
  }
  else {
    memmove(_Dst,param_1,(ulonglong)param_2);
    *param_3 = _Dst;
  }
  return uVar1;
}



===== PriGetObjectsFromUserHandle @ 14000adf4 =====

int PriGetObjectsFromUserHandle
              (undefined8 param_1,undefined4 param_2,longlong *param_3,longlong *param_4,
              longlong *param_5,longlong *param_6,longlong *param_7)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  int iVar5;
  longlong lVar6;
  ulonglong uVar7;
  undefined4 local_48 [2];
  longlong local_40;
  longlong local_38;
  longlong local_30;
  longlong local_28 [2];
  
  local_28[0] = 0;
  local_40 = 0;
  local_38 = 0;
  local_30 = 0;
  local_48[0] = 0;
  iVar5 = FltObjectReference(gFilterHandle);
  lVar6 = gFilterHandle;
  if (iVar5 < 0) goto LAB_14000afa6;
  uVar7 = 0;
  iVar5 = ObReferenceObjectByHandle
                    (param_1,param_2,*(undefined8 *)IoFileObjectType_exref,1,&local_40,0);
  if (-1 < iVar5) {
    if ((param_5 != (longlong *)0x0) || (param_4 != (longlong *)0x0)) {
      iVar5 = FltGetVolumeFromFileObject(lVar6,local_40,&local_38);
      if (iVar5 < 0) goto LAB_14000af92;
      if (param_4 != (longlong *)0x0) {
        iVar5 = FltEnumerateInstances(local_38,lVar6,&local_30,1,local_48);
        if (iVar5 < 0) goto LAB_14000af92;
      }
    }
    if (param_6 != (longlong *)0x0) {
      iVar5 = ObOpenObjectByPointer
                        (local_40,0x200,0,0xf0000,*(undefined8 *)IoFileObjectType_exref,
                         uVar7 & 0xffffffffffffff00,local_28);
      if (iVar5 < 0) goto LAB_14000af92;
    }
    lVar4 = local_28[0];
    lVar3 = local_30;
    lVar2 = local_38;
    lVar1 = local_40;
    if (param_3 != (longlong *)0x0) {
      *param_3 = lVar6;
      lVar6 = 0;
    }
    if (param_4 != (longlong *)0x0) {
      local_30 = 0;
      *param_4 = lVar3;
    }
    if (param_5 != (longlong *)0x0) {
      local_38 = 0;
      *param_5 = lVar2;
    }
    if (param_6 != (longlong *)0x0) {
      local_28[0] = 0;
      *param_6 = lVar4;
    }
    if (param_7 != (longlong *)0x0) {
      local_40 = 0;
      *param_7 = lVar1;
    }
  }
LAB_14000af92:
  if (lVar6 != 0) {
    FltObjectDereference(lVar6);
  }
LAB_14000afa6:
  if (local_40 != 0) {
    ObfDereferenceObject();
  }
  if (local_38 != 0) {
    FltObjectDereference();
  }
  if (local_30 != 0) {
    FltObjectDereference();
  }
  if (local_28[0] != 0) {
    ZwClose();
  }
  return iVar5;
}



===== PriProcessMessage @ 14000b024 =====

ulonglong PriProcessMessage(int *param_1,void *param_2,uint param_3,undefined8 *param_4,uint param_5
                           ,undefined4 *param_6)

{
  ushort uVar1;
  int iVar2;
  ulonglong uVar3;
  int *piVar4;
  uint uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  bool bVar9;
  undefined1 local_res10 [8];
  int *local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  ulonglong local_38;
  longlong lStack_30;
  
  uVar3 = (ulonglong)param_3;
  local_60 = (int *)0x0;
  if (((param_2 == (void *)0x0) || (param_3 < 0x10)) || (param_6 == (undefined4 *)0x0)) {
    return 0xc000000d;
  }
  ProbeForRead(param_2,uVar3,1);
  if (param_4 != (undefined8 *)0x0) {
    ProbeForWrite(param_4,param_5,1);
  }
  uVar6 = PriDuplicateUserBuffer(param_2,param_3,&local_60);
  piVar4 = local_60;
  uVar7 = uVar6 & 0xffffffff;
  if ((int)uVar6 < 0) goto LAB_14000b335;
  if ((((uint)local_60[2] <= param_3) && (*local_60 == 0x42424242)) &&
     (((short)local_60[1] == 3 && (*(ushort *)((longlong)local_60 + 6) < 2)))) {
    iVar2 = local_60[3];
    if (iVar2 == 2) {
      if ((param_1 != (int *)0x0) && (0x23 < param_3)) {
        LOCK();
        bVar9 = param_1[10] == 0;
        if (bVar9) {
          param_1[10] = 1;
        }
        UNLOCK();
        if (bVar9) {
          uVar8 = *(undefined8 *)(local_60 + 6);
          *(undefined8 *)(param_1 + 6) = *(undefined8 *)(local_60 + 4);
          *(undefined8 *)(param_1 + 8) = uVar8;
          uVar5 = WMCommListInsert(local_60 + 4,(undefined8 *)(param_1 + 2),local_60[8],param_1);
          uVar7 = (ulonglong)uVar5;
        }
        else {
          uVar7 = 0xc0000082;
        }
        goto LAB_14000b335;
      }
    }
    else {
      if (iVar2 == 3) {
        if (0x13 < param_3) {
          *param_1 = local_60[4];
        }
        if ((param_4 != (undefined8 *)0x0) && (3 < param_5)) {
          *(undefined4 *)param_4 = 0x10003;
        }
        goto LAB_14000b335;
      }
      if (iVar2 == 5) {
        if (((0x2f < param_3) &&
            (uVar1 = *(ushort *)(local_60 + 10), (ulonglong)uVar1 + 0x30 <= uVar3)) &&
           (param_4 != (undefined8 *)0x0)) {
          if (param_5 < 8) {
            uVar7 = 0x80000005;
            goto LAB_14000b335;
          }
          local_50 = 0;
          lStack_30 = (longlong)local_60 + 0x2a;
          local_38 = (ulonglong)CONCAT22(uVar1,uVar1);
          uVar5 = PriStubCreateChild(*(undefined8 *)(local_60 + 4),local_60[6],local_60[7],
                                     local_60[8],local_60[9],&local_38,&local_50);
          uVar8 = local_50;
LAB_14000b1e8:
          uVar7 = (ulonglong)uVar5;
          *param_4 = uVar8;
          *param_6 = 8;
          goto LAB_14000b335;
        }
      }
      else if (iVar2 == 6) {
        if ((0x37 < param_3) && ((ulonglong)(uint)local_60[0xc] + 0x38 <= uVar3)) {
          uVar7 = PriStubRename(*(undefined8 *)(local_60 + 4),local_60 + 8,param_3 - 0x20,
                                local_60[6]);
          uVar7 = uVar7 & 0xffffffff;
          goto LAB_14000b335;
        }
      }
      else if (iVar2 == 7) {
        if (((0x27 < param_3) && (7 < param_5)) && (param_4 != (undefined8 *)0x0)) {
          local_40 = *(undefined8 *)(local_60 + 6);
          local_48 = *(undefined8 *)(local_60 + 8);
          local_58 = 0;
          uVar5 = PriSubsumeContext(*(undefined8 *)(local_60 + 4),(short *)&local_40,
                                    (short *)&local_48,&local_58);
          uVar8 = local_58;
          goto LAB_14000b1e8;
        }
      }
      else if (((iVar2 == 8) && (0x27 < param_3)) && (param_5 != 0)) {
        local_res10[0] = 0;
        uVar7 = PriExchangeDirs(*(undefined8 *)(local_60 + 4),*(undefined8 *)(local_60 + 6),
                                *(undefined8 *)(local_60 + 8),(longlong)param_1,local_res10);
        uVar7 = uVar7 & 0xffffffff;
        *(undefined1 *)param_4 = local_res10[0];
        *param_6 = 1;
        goto LAB_14000b335;
      }
    }
  }
  uVar7 = 0xc000000d;
LAB_14000b335:
  if (piVar4 != (int *)0x0) {
    ExFreePoolWithTag(piVar4,0x574d6365);
  }
  return uVar7;
}



===== PriStubCreateChild @ 14000b388 =====

int PriStubCreateChild(undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                      undefined4 param_5,undefined8 *param_6,undefined8 param_7)

{
  longlong lVar1;
  int iVar2;
  undefined8 uVar3;
  longlong lVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  undefined4 uVar7;
  longlong local_98;
  longlong local_90;
  longlong local_88;
  longlong local_80;
  longlong local_78;
  undefined8 local_70;
  longlong lStack_68;
  undefined8 local_60;
  longlong lStack_58;
  undefined8 *local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  ulonglong uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  
  local_40 = 0;
  uStack_38 = uStack_38 & 0xffffffff00000000;
  local_98 = 0;
  local_90 = 0;
  lVar4 = 0;
  local_78 = 0;
  local_80 = 0;
  local_88 = 0;
  local_70 = 0;
  lStack_68 = 0;
  local_60 = 0;
  lStack_58 = 0;
  local_50 = (undefined8 *)0x0;
  uStack_48 = 0;
  local_30 = 0;
  uStack_28 = 0;
  iVar2 = PriGetObjectsFromUserHandle
                    (param_1,0x100131,&local_98,&local_90,(longlong *)0x0,&local_78,(longlong *)0x0)
  ;
  lVar1 = local_78;
  if (-1 < iVar2) {
    uVar3 = PriDuplicateUserBuffer
                      ((void *)param_6[1],(uint)*(ushort *)((longlong)param_6 + 2),&local_88);
    lVar4 = local_88;
    iVar2 = (int)uVar3;
    if (-1 < iVar2) {
      local_70 = *param_6;
      local_50 = &local_70;
      puVar6 = &local_30;
      uVar7 = 0;
      puVar5 = &local_60;
      lStack_68 = local_88;
      local_60 = CONCAT44(local_60._4_4_,0x30);
      lStack_58 = lVar1;
      uStack_48 = CONCAT44(uStack_48._4_4_,0x200);
      local_40 = 0;
      uStack_38 = 0;
      iVar2 = FltCreateFile(local_98,local_90,&local_80,param_2,puVar5,puVar6,0,param_5,7,param_3,
                            param_4,0,0,0);
      if (-1 < iVar2) {
        iVar2 = ZwDuplicateObject(0xffffffffffffffff,local_80,0xffffffffffffffff,param_7,
                                  (ulonglong)puVar5 & 0xffffffff00000000,
                                  (ulonglong)puVar6 & 0xffffffff00000000,CONCAT44(uVar7,6));
      }
    }
  }
  if (local_98 != 0) {
    FltObjectDereference(local_98);
  }
  if (local_90 != 0) {
    FltObjectDereference(local_90);
  }
  if (lVar1 != 0) {
    ZwClose(lVar1);
  }
  if (local_80 != 0) {
    FltClose();
  }
  if (lVar4 != 0) {
    ExFreePoolWithTag(lVar4,0x574d6365);
  }
  return iVar2;
}



===== PriStubRename @ 14000b594 =====

ulonglong PriStubRename(undefined8 param_1,void *param_2,uint param_3,int param_4)

{
  longlong lVar1;
  uint uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  longlong local_res10;
  longlong local_38;
  longlong local_30;
  longlong local_28 [2];
  
  local_38 = 0;
  local_28[0] = 0;
  local_res10 = 0;
  local_30 = 0;
  if ((ulonglong)param_3 + (longlong)param_2 <
      (longlong)param_2 + (ulonglong)*(uint *)((longlong)param_2 + 0x10) + 0x14) {
    uVar4 = 0x80000005;
  }
  else if ((((param_4 == 10) || (param_4 == 0xb)) || (param_4 == 0x41)) &&
          (*(longlong *)((longlong)param_2 + 8) == 0)) {
    uVar3 = PriDuplicateUserBuffer(param_2,param_3,&local_38);
    uVar4 = uVar3 & 0xffffffff;
    if (-1 < (int)uVar3) {
      uVar2 = PriGetObjectsFromUserHandle
                        (param_1,0x10000,local_28,&local_res10,(longlong *)0x0,(longlong *)0x0,
                         &local_30);
      lVar1 = local_30;
      if (-1 < (int)uVar2) {
        uVar2 = FltSetInformationFile(local_res10,local_30,local_38,param_3,param_4);
      }
      uVar4 = (ulonglong)uVar2;
      if (local_28[0] != 0) {
        FltObjectDereference();
      }
      if (local_res10 != 0) {
        FltObjectDereference(local_res10);
      }
      if (lVar1 != 0) {
        ObfDereferenceObject(lVar1);
      }
    }
    if (local_38 != 0) {
      ExFreePoolWithTag(local_38,0x574d6365);
    }
  }
  else {
    uVar4 = 0xc000000d;
  }
  return uVar4;
}



===== PriSubsumeContext @ 14000b6f8 =====

int PriSubsumeContext(undefined8 param_1,short *param_2,short *param_3,undefined8 param_4)

{
  int iVar1;
  longlong local_28;
  longlong local_20;
  longlong local_18 [2];
  
  local_20 = 0;
  local_18[0] = 0;
  local_28 = 0;
  iVar1 = PriGetObjectsFromUserHandle
                    (param_1,0x120196,&local_20,local_18,(longlong *)0x0,&local_28,(longlong *)0x0);
  if (-1 < iVar1) {
    iVar1 = PFSubsumeContext(local_20,local_18[0],local_28,param_2,param_3,param_4);
  }
  if (local_28 != 0) {
    ZwClose(local_28);
  }
  if (local_20 != 0) {
    FltObjectDereference(local_20);
  }
  if (local_18[0] != 0) {
    FltObjectDereference(local_18[0]);
  }
  return iVar1;
}



===== MatchByGuid @ 14000b7e0 =====

bool MatchByGuid(longlong param_1,undefined8 param_2)

{
  longlong lVar1;
  
  lVar1 = RtlCompareMemory(param_1 + 0x14,param_2,0x10);
  return lVar1 == 0x10;
}



===== MatchByProcessId @ 14000b810 =====

undefined4 MatchByProcessId(longlong param_1,int *param_2)

{
  return CONCAT31((int3)((uint)*param_2 >> 8),*(int *)(param_1 + 0x38) == *param_2);
}



===== PriGetEntry @ 14000b820 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 * PriGetEntry(undefined *param_1,undefined8 param_2)

{
  char cVar1;
  undefined8 *puVar2;
  
  puVar2 = g_CommList;
  while( true ) {
    if ((undefined8 **)puVar2 == &g_CommList) {
      return (undefined8 *)0x0;
    }
    cVar1 = (*(code *)param_1)(puVar2,param_2);
    if (cVar1 != '\0') break;
    puVar2 = (undefined8 *)*puVar2;
  }
  return puVar2;
}



===== WMCommListCreate @ 14000b888 =====

void WMCommListCreate(void)

{
  DAT_1400061d8 = &g_CommList;
  g_CommList = &g_CommList;
  ExInitializeResourceLite(&DAT_1400061e0);
  return;
}



===== WMCommListGet @ 14000b8c0 =====

undefined8 WMCommListGet(undefined8 param_1,undefined8 *param_2)

{
  undefined4 uVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  
  uVar3 = 0;
  FltAcquireResourceShared(&DAT_1400061e0);
  puVar2 = PriGetEntry(MatchByGuid,param_1);
  if (puVar2 == (undefined8 *)0x0) {
    uVar3 = 0xc0000225;
  }
  else {
    uVar1 = WMCommListEntryAddRef((longlong)puVar2);
    if ((char)uVar1 == '\0') {
      WMCommListEntryRelease((longlong)puVar2);
      uVar3 = 0xc0000095;
    }
    else {
      *param_2 = puVar2;
    }
  }
  FltReleaseResource(&DAT_1400061e0);
  return uVar3;
}



===== WMCommListInsert @ 14000b94c =====

int WMCommListInsert(undefined4 *param_1,undefined8 *param_2,uint param_3,undefined4 *param_4)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  undefined1 *puVar9;
  undefined1 auStack_88 [8];
  undefined1 auStack_80 [24];
  longlong local_68;
  ulonglong local_60 [2];
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  ulonglong uStack_28;
  
  local_68 = 0;
  local_30 = 0;
  uStack_28 = uStack_28 & 0xffffffff00000000;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  uStack_38 = 0;
  local_60[0] = 0;
  local_60[1] = 0;
  puVar6 = (undefined8 *)ExAllocatePoolWithTag(1,0x40,0x574d6365);
  puVar9 = auStack_88;
  puVar8 = puVar6;
  if (puVar6 == (undefined8 *)0x0) {
    iVar5 = -0x3fffff66;
  }
  else {
    puVar6[6] = 0;
    *(undefined4 *)(puVar6 + 7) = 0;
    *(undefined4 *)(puVar6 + 2) = 1;
    uStack_48 = 0;
    local_40 = 0;
    local_30 = 0;
    uStack_28 = 0;
    local_50 = CONCAT44(local_50._4_4_,0x30);
    uStack_38 = CONCAT44(uStack_38._4_4_,0x200);
    local_60[0] = (ulonglong)param_3;
    iVar5 = ZwOpenProcess(&local_68,0x40,&local_50,local_60);
    puVar9 = auStack_88;
    if (-1 < iVar5) {
      uVar2 = param_1[1];
      uVar3 = param_1[2];
      uVar4 = param_1[3];
      *(undefined4 *)((longlong)puVar6 + 0x14) = *param_1;
      *(undefined4 *)(puVar6 + 3) = uVar2;
      *(undefined4 *)((longlong)puVar6 + 0x1c) = uVar3;
      *(undefined4 *)(puVar6 + 4) = uVar4;
      puVar6[5] = *param_2;
      puVar6[6] = local_68;
      *(uint *)(puVar6 + 7) = param_3;
      *(undefined4 *)((longlong)puVar6 + 0x3c) = *param_4;
      local_68 = 0;
      *param_2 = 0;
      FltAcquireResourceExclusive(&DAT_1400061e0);
      puVar7 = PriGetEntry(MatchByGuid,param_1);
      puVar9 = auStack_88;
      if (puVar7 == (undefined8 *)0x0) {
        puVar8 = &g_CommList;
        if ((undefined8 *)*DAT_1400061d8 != &g_CommList) {
          puVar8 = (undefined8 *)0x3;
          pcVar1 = (code *)swi(0x29);
          DAT_1400061d8 = (undefined8 *)(*pcVar1)();
          puVar9 = auStack_80;
        }
        *puVar6 = puVar8;
        puVar6[1] = DAT_1400061d8;
        *DAT_1400061d8 = puVar6;
        puVar8 = (undefined8 *)0x0;
        DAT_1400061d8 = puVar6;
      }
      else {
        iVar5 = -0x3ffff8f8;
        puVar9 = auStack_88;
      }
      *(undefined8 *)(puVar9 + -8) = 0x14000baab;
      FltReleaseResource(&DAT_1400061e0);
    }
  }
  if (local_68 != 0) {
    *(undefined8 *)(puVar9 + -8) = 0x14000bac0;
    ZwClose();
  }
  if (puVar8 != (undefined8 *)0x0) {
    if (puVar8[6] != 0) {
      *(undefined8 *)(puVar9 + -8) = 0x14000bada;
      ZwClose();
    }
    *(undefined8 *)(puVar9 + -8) = 0x14000baee;
    ExFreePoolWithTag(puVar8,0x574d6365);
  }
  return iVar5;
}



===== entry @ 14000c010 =====

void entry(undefined8 param_1)

{
  __security_init_cookie();
  DriverEntry(param_1);
  return;
}



===== __security_init_cookie @ 14000c044 =====

void __cdecl __security_init_cookie(void)

{
  ulonglong uVar1;
  
  if ((__security_cookie == 0) || (__security_cookie == 0x2b992ddfa232)) {
    uVar1 = rdtsc();
    __security_cookie =
         ((CONCAT44((int)(__security_cookie >> 0x20),(int)uVar1) | uVar1 & 0xffffffff00000000) ^
         0x140006040) & 0xffffffffffff;
    if (__security_cookie == 0) {
      __security_cookie = 0x2b992ddfa232;
    }
  }
  __security_cookie_complement = ~__security_cookie;
  return;
}



===== DriverEntry @ 14000c0ac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int DriverEntry(undefined8 param_1)

{
  int iVar1;
  code *pcVar2;
  undefined1 auStack_1e8 [32];
  code *local_1c8;
  code *local_1c0;
  code *local_1b8;
  undefined4 local_1b0;
  char local_1a8 [8];
  longlong local_1a0 [2];
  wchar_t *local_190;
  undefined8 local_188;
  undefined8 uStack_180;
  undefined8 *local_178;
  undefined8 uStack_170;
  longlong local_168;
  undefined8 uStack_160;
  undefined8 local_158;
  undefined8 uStack_150;
  undefined4 local_148;
  undefined1 local_144 [284];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_1e8;
  local_1a0[1] = 0x320030;
  local_1a0[0] = 0;
  local_1a8[0] = '\0';
  local_190 = L"NtQuerySystemInformation";
  local_158 = 0;
  uStack_150 = 0;
  local_188 = 0;
  uStack_180 = 0;
  local_178 = (undefined8 *)0x0;
  uStack_170 = 0;
  local_168 = 0;
  uStack_160 = 0;
  memset(local_144,0,0x110);
  local_148 = 0x114;
  RtlGetVersion(&local_148);
  pcVar2 = (code *)MmGetSystemRoutineAddress(local_1a0 + 1);
  if (pcVar2 != (code *)0x0) {
    iVar1 = (*pcVar2)(0xe3,local_1a8,1,0);
    if ((-1 < iVar1) && (local_1a8[0] != '\0')) {
      ExPoolZeroingNativelySupported = 1;
    }
  }
  iVar1 = wil_InitializeFeatureStaging();
  DAT_140006188 = (byte)((uint)iVar1 >> 0x1f) ^ 1;
  if ((iVar1 == -0x3ffffec7) || (-1 < iVar1)) {
    DAT_1400061b0 = FltGetRoutineAddress("FltAddOpenReparseEntry");
    DAT_140006160 = FltGetRoutineAddress("FltRemoveOpenReparseEntry");
    if ((DAT_1400061b0 == 0) || (DAT_1400061a8 = 1, DAT_140006160 == 0)) {
      DAT_1400061a8 = 0;
    }
    iVar1 = ExInitializeResourceLite(&DAT_1400060f0);
    if (-1 < iVar1) {
      local_1b8 = (code *)((ulonglong)local_1b8 & 0xffffffffffff0000);
      local_1c0 = (code *)CONCAT44(local_1c0._4_4_,0x50466372);
      local_1c8 = (code *)0x40;
      DAT_140006189 = 1;
      ExInitializePagedLookasideList(&DAT_140006280,0,0,0);
      iVar1 = FltRegisterFilter(param_1,&FilterRegistration,&gFilterHandle);
      if (-1 < iVar1) {
        WMCommListCreate();
        iVar1 = FltBuildDefaultSecurityDescriptor(local_1a0,0x1f0001);
        if (-1 < iVar1) {
          RtlInitUnicodeString(&local_158,L"\\PFPort");
          local_178 = &local_158;
          local_168 = local_1a0[0];
          local_1b0 = 0x100;
          local_1b8 = PFReceiveMessage;
          local_1c0 = PFPortDisconnect;
          local_1c8 = PFPortConnect;
          local_188 = CONCAT44(local_188._4_4_,0x30);
          uStack_180 = 0;
          uStack_170 = CONCAT44(uStack_170._4_4_,0x240);
          uStack_160 = 0;
          iVar1 = FltCreateCommunicationPort(gFilterHandle,&DAT_1400061b8,&local_188,0);
          if (-1 < iVar1) {
            iVar1 = FltStartFiltering(gFilterHandle);
          }
        }
      }
    }
  }
  if (local_1a0[0] != 0) {
    FltFreeSecurityDescriptor();
  }
  if (iVar1 < 0) {
    Unload();
  }
  return iVar1;
}



===== wil_InitializeFeatureStaging @ 14000c38c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int wil_InitializeFeatureStaging(void)

{
  bool bVar1;
  int iVar2;
  undefined **ppuVar3;
  undefined8 local_res8;
  undefined8 local_28;
  wchar_t *local_20;
  undefined8 local_18;
  wchar_t *local_10;
  
  bVar1 = false;
  if (g_wil_details_isFeatureStagingInitialized == 0) {
    g_wil_details_isFeatureStagingInitialized = 1;
    if (g_wil_details_pfnRtlQueryFeatureConfigurationChangeStamp == (code *)0x0) {
      local_28 = 0x50004e;
      local_20 = L"RtlQueryFeatureConfigurationChangeStamp";
      g_wil_details_pfnRtlQueryFeatureConfigurationChangeStamp =
           (code *)MmGetSystemRoutineAddress(&local_28);
      if (g_wil_details_pfnRtlQueryFeatureConfigurationChangeStamp != (code *)0x0)
      goto LAB_14000c3f7;
      local_res8 = 0;
    }
    else {
LAB_14000c3f7:
      local_res8 = (*g_wil_details_pfnRtlQueryFeatureConfigurationChangeStamp)();
    }
    wil_details_PopulateInitialConfiguredFeatureStates();
    wil_details_EvaluateFeatureDependencies();
    for (ppuVar3 = &Feature_ReFS_WIM_Mount_Support__private_descriptor;
        ppuVar3 < &wil_details_featureDescriptors_z; ppuVar3 = ppuVar3 + 1) {
      if (*ppuVar3 != (undefined *)0x0) goto LAB_14000c455;
    }
LAB_14000c4c2:
    g_wil_details_recordFeatureUsage = wil_details_RecordFeatureUsageReporting;
    if (g_wil_details_pfnRtlRegisterFeatureUsageProvider == (code *)0x0) {
      local_28 = 0x40003e;
      local_20 = L"RtlRegisterFeatureUsageProvider";
      g_wil_details_pfnRtlRegisterFeatureUsageProvider =
           (code *)MmGetSystemRoutineAddress(&local_28);
      if (g_wil_details_pfnRtlRegisterFeatureUsageProvider != (code *)0x0) goto LAB_14000c512;
      iVar2 = -0x3ffffec7;
    }
    else {
LAB_14000c512:
      iVar2 = (*g_wil_details_pfnRtlRegisterFeatureUsageProvider)
                        (wil_details_OnFeatureUsageProviderFlushNotification,0,
                         &g_wil_details_featureUsageProvider);
      if (iVar2 == 0) goto LAB_14000c539;
    }
    g_wil_details_featureUsageProvider = 0;
    if (bVar1) {
      iVar2 = 0;
    }
  }
  else {
LAB_14000c539:
    iVar2 = 0;
  }
  return iVar2;
LAB_14000c455:
  if (ppuVar3 == (undefined **)0x0) goto LAB_14000c4c2;
  if (((*(char *)((longlong)ppuVar3 + 0x1d) == '\0') &&
      (*(char *)((longlong)ppuVar3 + 0x1e) == '\0')) &&
     (*(char *)((longlong)ppuVar3 + 0x1c) == '\0')) {
    if (g_wil_details_pfnRtlRegisterFeatureConfigurationChangeNotification == (code *)0x0) {
      local_18 = 0x640062;
      local_10 = L"RtlRegisterFeatureConfigurationChangeNotification";
      g_wil_details_pfnRtlRegisterFeatureConfigurationChangeNotification =
           (code *)MmGetSystemRoutineAddress(&local_18);
      if (g_wil_details_pfnRtlRegisterFeatureConfigurationChangeNotification != (code *)0x0)
      goto LAB_14000c497;
    }
    else {
LAB_14000c497:
      iVar2 = (*g_wil_details_pfnRtlRegisterFeatureConfigurationChangeNotification)
                        (wil_details_ReevaluateOnFeatureConfigurationChange,0,&local_res8,
                         &g_wil_details_featureChangeNotification);
      if (iVar2 == 0) {
        bVar1 = true;
        goto LAB_14000c4c2;
      }
    }
    g_wil_details_featureChangeNotification = 0;
    goto LAB_14000c4c2;
  }
  ppuVar3 = ppuVar3 + 7;
  while( true ) {
    if (&UNK_140005f5f < ppuVar3) goto LAB_14000c4c2;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_14000c455;
}



===== wil_details_PopulateInitialConfiguredFeatureStates @ 14000c554 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_PopulateInitialConfiguredFeatureStates(void)

{
  ulonglong *puVar1;
  undefined8 *puVar2;
  int iVar3;
  undefined8 uVar4;
  undefined **ppuVar5;
  undefined1 auStack_48 [32];
  ulonglong local_28;
  undefined8 local_20;
  undefined4 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  ppuVar5 = &Feature_ReFS_WIM_Mount_Support__private_descriptor;
  while( true ) {
    if (&wil_details_featureDescriptors_z <= ppuVar5) {
      return;
    }
    if (*ppuVar5 != (undefined *)0x0) break;
    ppuVar5 = ppuVar5 + 1;
  }
  do {
    if (ppuVar5 == (undefined **)0x0) {
      return;
    }
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    if ((*(char *)((longlong)ppuVar5 + 0x1d) == '\0') &&
       (*(char *)((longlong)ppuVar5 + 0x1e) == '\0')) {
      uVar4 = wil_details_RtlQueryFeatureConfiguration
                        (*(undefined4 *)(ppuVar5 + 3),
                         (uint)(1 < (byte)(*(char *)((longlong)ppuVar5 + 0x1c) - 2U)),&local_28,
                         &local_20);
      iVar3 = (int)uVar4;
      if (iVar3 == -0x7fffffde) {
        do {
          puVar2 = (undefined8 *)*ppuVar5;
          ppuVar5 = ppuVar5 + 7;
          *puVar2 = 0x206;
          while( true ) {
            if (&UNK_140005f5f < ppuVar5) {
              return;
            }
            if (*ppuVar5 != (undefined *)0x0) break;
            ppuVar5 = ppuVar5 + 1;
          }
        } while (ppuVar5 != (undefined **)0x0);
        return;
      }
      if (iVar3 == -0x3ffffddb) goto LAB_14000c637;
      if (iVar3 == 0) {
        local_28 = (ulonglong)(((local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0) << 3 | 0x206);
      }
      else {
        if (iVar3 != 0x117) goto LAB_14000c637;
        local_28 = (ulonglong)((local_20._4_4_ & 0x80) << 3 | 0x206);
      }
    }
    else {
LAB_14000c637:
      local_28 = 0x206;
    }
    puVar1 = (ulonglong *)*ppuVar5;
    ppuVar5 = ppuVar5 + 7;
    *puVar1 = local_28;
    while( true ) {
      if (&UNK_140005f5f < ppuVar5) {
        return;
      }
      if (*ppuVar5 != (undefined *)0x0) break;
      ppuVar5 = ppuVar5 + 1;
    }
  } while( true );
}


