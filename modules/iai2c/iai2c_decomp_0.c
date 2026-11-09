
===== ControllerAcknowledgeInterrupts @ 140001000 =====

/* void __cdecl ControllerAcknowledgeInterrupts(struct PBC_DEVICE * __ptr64,unsigned long) */

void __cdecl ControllerAcknowledgeInterrupts(PBC_DEVICE *param_1,ulong param_2)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
            &WPP_b3564bc0e82137d896779365436e6d83_Traceguids);
  }
  LpssApi_AcknowledgeInterrupts(param_1,param_2);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2c,
            &WPP_b3564bc0e82137d896779365436e6d83_Traceguids);
  }
  return;
}



===== ControllerCompleteTransfer @ 140001094 =====

/* void __cdecl ControllerCompleteTransfer(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST * __ptr64)
    */

void __cdecl ControllerCompleteTransfer(PBC_DEVICE *param_1,PBC_REQUEST *param_2)

{
  undefined8 uVar1;
  PBC_DEVICE *pPVar2;
  PBC_DEVICE PVar3;
  int iVar4;
  ulong uVar5;
  PBC_REQUEST *pPVar6;
  char *pcVar7;
  
  pPVar6 = param_2;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    pPVar6 = (PBC_REQUEST *)0x1e;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
            &WPP_b3564bc0e82137d896779365436e6d83_Traceguids);
  }
  uVar5 = (ulong)pPVar6;
  if (param_2[0x24] == (PBC_REQUEST)0x0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      pcVar7 = "error";
      if (-1 < *(int *)(param_2 + 0x20)) {
        pcVar7 = "complete";
      }
      uVar5 = 0x20;
      WPP_SF_LsPLq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,
                   &WPP_b3564bc0e82137d896779365436e6d83_Traceguids,*(undefined4 *)(param_2 + 0x10),
                   pcVar7,(char)*(undefined8 *)(param_2 + 0x58),
                   (char)*(undefined2 *)(*(longlong *)(param_1 + 0x20) + 0xc),
                   (char)*(undefined8 *)param_2);
    }
    if (param_2[0x88] == (PBC_REQUEST)0x0) {
      *(longlong *)(param_2 + 0x18) = *(longlong *)(param_2 + 0x18) + *(longlong *)(param_2 + 0x58);
      *(undefined8 *)(param_2 + 0x58) = 0;
      if (((-1 < *(int *)(param_2 + 0x20)) && (*(int *)(param_2 + 0x20) != 0x10b)) &&
         (*(int *)(param_2 + 0x10) = *(int *)(param_2 + 0x10) + 1,
         *(uint *)(param_2 + 0x10) < *(uint *)(param_2 + 0xc))) goto LAB_1400012bf;
    }
    param_2[0x88] = (PBC_REQUEST)0x0;
    if (*(int *)(param_2 + 0x20) != -0x3ffffee0) {
      uVar1 = *(undefined8 *)param_2;
      pPVar2 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x800);
      ChvP1I2c_ControllerIoGenerateStart(pPVar2,uVar5);
      iVar4 = (*(code *)pPVar2)(WdfDriverGlobals,uVar1);
      if (iVar4 < 0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_xd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,
                    &WPP_b3564bc0e82137d896779365436e6d83_Traceguids,*(undefined8 *)param_2,
                    (char)iVar4);
        }
        if (iVar4 == -0x3ffffee0) {
          param_2[0x88] = (PBC_REQUEST)0x1;
          goto LAB_1400012bf;
        }
      }
    }
    if (((param_2[0x41] != (PBC_REQUEST)0x0) && (param_1[0x310] == (PBC_DEVICE)0x0)) ||
       ((*(int *)(param_2 + 0x20) < 0 || (*(int *)(param_2 + 0x20) == 0x10b)))) {
      if ((param_1[0x41] == (PBC_DEVICE)0x0) ||
         (PVar3 = (PBC_DEVICE)0x1, *(int *)(param_2 + 0x20) != -0x3ffffee0)) {
        PVar3 = (PBC_DEVICE)0x0;
      }
      param_1[0x3b1] = PVar3;
      LpssApi_ControllerIoGenerateStop(param_1,*(ulong *)(*(longlong *)(param_1 + 0x20) + 0x20));
      param_1[0x3b1] = (PBC_DEVICE)0x0;
      if (param_1[0x41] == (PBC_DEVICE)0x0) {
        param_1[0x70] = (PBC_DEVICE)0x0;
      }
    }
    *(undefined8 *)(*(longlong *)(param_1 + 0x20) + 0x18) = 0;
    if ((*(int *)(param_2 + 8) == 3) || (*(int *)(param_2 + 0x38) == 1)) {
      *(undefined8 *)(param_1 + 0x20) = 0;
    }
    param_2[0x24] = (PBC_REQUEST)0x1;
  }
  else if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) &&
          (2 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,
            &WPP_b3564bc0e82137d896779365436e6d83_Traceguids);
  }
LAB_1400012bf:
  ControllerDisableEventsAndInterrupts(param_1);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,
            &WPP_b3564bc0e82137d896779365436e6d83_Traceguids);
  }
  return;
}



===== ControllerConfigureForTransfer @ 140001310 =====

/* void __cdecl ControllerConfigureForTransfer(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST *
   __ptr64) */

void __cdecl ControllerConfigureForTransfer(PBC_DEVICE *param_1,PBC_REQUEST *param_2)

{
  char *pcVar1;
  char *pcVar2;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
            &WPP_b3564bc0e82137d896779365436e6d83_Traceguids);
  }
  if (*(uint *)(param_2 + 0x38) < 5) {
    *(undefined4 *)(param_2 + 0x20) = 0;
    *(undefined8 *)(param_2 + 0x3c) = (&DAT_140014380)[(int)*(uint *)(param_2 + 0x38)];
    LpssApi_ConfigureForTransferPreSettings(param_1,param_2);
    if (param_2[0x40] == (PBC_REQUEST)0x0) {
      if (param_2[0x41] != (PBC_REQUEST)0x0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
                  &WPP_b3564bc0e82137d896779365436e6d83_Traceguids);
        }
        LpssApi_ConfigureForTransferEnd(param_1,param_2);
      }
    }
    else {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
                &WPP_b3564bc0e82137d896779365436e6d83_Traceguids);
      }
      LpssApi_ConfigureForTransferStart(param_1,param_2);
    }
    if (*(int *)(param_2 + 0x44) == 2) {
      LpssApi_ConfigureForTransferToDevice(param_1,param_2);
    }
    else if (*(int *)(param_2 + 0x44) == 1) {
      LpssApi_ConfigureForTransferFromDevice(param_1,param_2);
    }
    LpssApi_ConfigureForTransferPostSettings(param_1,param_2);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      pcVar2 = "Write";
      pcVar1 = "PIO";
      if (*(int *)(param_2 + 0x44) == 1) {
        pcVar2 = "Read";
      }
      if (param_1[800] != (PBC_DEVICE)0x0) {
        pcVar1 = "DMA";
      }
      WPP_SF_ssPLLqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
                     &WPP_b3564bc0e82137d896779365436e6d83_Traceguids,pcVar1,pcVar2,
                     (char)*(undefined8 *)(param_2 + 0x28),
                     (char)*(undefined2 *)(*(longlong *)(param_1 + 0x20) + 0xc),
                     (char)*(undefined4 *)(param_2 + 0x10),(char)*(undefined8 *)param_2,
                     (char)*(undefined8 *)param_1);
    }
    if (param_1[800] == (PBC_DEVICE)0x0) {
      LpssApi_ConfigureForTransferPio(param_1,param_2);
    }
    else {
      LpssApi_ConfigureForTransferDma(param_1,param_2);
    }
  }
  else {
    *(undefined8 *)(param_2 + 0x3c) = 2;
    *(undefined4 *)(param_2 + 0x20) = 0xc0000001;
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
              &WPP_b3564bc0e82137d896779365436e6d83_Traceguids);
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
            &WPP_b3564bc0e82137d896779365436e6d83_Traceguids);
  }
  return;
}



===== ControllerDisableEventsAndInterrupts @ 140001560 =====

/* void __cdecl ControllerDisableEventsAndInterrupts(struct PBC_DEVICE * __ptr64) */

void __cdecl ControllerDisableEventsAndInterrupts(PBC_DEVICE *param_1)

{
  PBC_DEVICE *UNRECOVERED_JUMPTABLE;
  ulong in_EDX;
  ulong uVar1;
  
  UNRECOVERED_JUMPTABLE = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x480);
  ChvP1I2c_ControllerIoGenerateStart(UNRECOVERED_JUMPTABLE,in_EDX);
  uVar1 = (ulong)*(undefined8 *)(param_1 + 0x28);
  (*(code *)UNRECOVERED_JUMPTABLE)(WdfDriverGlobals);
  ControllerDisableInterrupts(param_1);
  LOCK();
  *(undefined4 *)(param_1 + 0x30) = 0;
  UNLOCK();
  *(undefined4 *)(param_1 + 0x34) = 0;
  UNRECOVERED_JUMPTABLE = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x488);
  ChvP1I2c_ControllerIoGenerateStart(UNRECOVERED_JUMPTABLE,uVar1);
                    /* WARNING: Could not recover jumptable at 0x0001400015d1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)UNRECOVERED_JUMPTABLE)(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x28));
  return;
}



===== ControllerDisableInterrupts @ 1400015d4 =====

/* void __cdecl ControllerDisableInterrupts(struct PBC_DEVICE * __ptr64) */

void __cdecl ControllerDisableInterrupts(PBC_DEVICE *param_1)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x26,
            &WPP_b3564bc0e82137d896779365436e6d83_Traceguids);
  }
  LpssApi_DisableInterrupts(param_1);
  param_1[0x250] = (PBC_DEVICE)0x0;
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x27,
              &WPP_b3564bc0e82137d896779365436e6d83_Traceguids);
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x28,
              &WPP_b3564bc0e82137d896779365436e6d83_Traceguids);
    }
  }
  return;
}



===== ControllerEnableInterrupts @ 14000168c =====

/* void __cdecl ControllerEnableInterrupts(struct PBC_DEVICE * __ptr64,unsigned long) */

void __cdecl ControllerEnableInterrupts(PBC_DEVICE *param_1,ulong param_2)

{
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,
              &WPP_b3564bc0e82137d896779365436e6d83_Traceguids);
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_Lq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x24,
                &WPP_b3564bc0e82137d896779365436e6d83_Traceguids,param_2,
                (char)*(undefined8 *)param_1);
    }
  }
  param_1[0x250] = (PBC_DEVICE)0x1;
  LpssApi_EnableInterrupts(param_1,param_2);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x25,
            &WPP_b3564bc0e82137d896779365436e6d83_Traceguids);
  }
  return;
}



===== ControllerGetInterruptStatus @ 140001760 =====

/* unsigned long __cdecl ControllerGetInterruptStatus(struct PBC_DEVICE * __ptr64,unsigned long) */

ulong __cdecl ControllerGetInterruptStatus(PBC_DEVICE *param_1,ulong param_2)

{
  ulong uVar1;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x29,
            &WPP_b3564bc0e82137d896779365436e6d83_Traceguids);
  }
  uVar1 = LpssApi_GetInterruptStatus(param_1,param_2);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2a,
            &WPP_b3564bc0e82137d896779365436e6d83_Traceguids);
  }
  return uVar1;
}



===== ControllerInitialize @ 1400017f8 =====

/* void __cdecl ControllerInitialize(struct PBC_DEVICE * __ptr64) */

void __cdecl ControllerInitialize(PBC_DEVICE *param_1)

{
  long lVar1;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_b3564bc0e82137d896779365436e6d83_Traceguids);
  }
  param_1[0x250] = (PBC_DEVICE)0x0;
  ControllerDisableInterrupts(param_1);
  LOCK();
  *(undefined4 *)(param_1 + 0x30) = 0;
  UNLOCK();
  *(undefined4 *)(param_1 + 0x34) = 0;
  lVar1 = LpssApi_ControllerInitialize(param_1);
  if (-1 < lVar1) {
    param_1[0x70] = (PBC_DEVICE)0x1;
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
            &WPP_b3564bc0e82137d896779365436e6d83_Traceguids);
  }
  return;
}



===== ControllerProcessInterrupts @ 14000189c =====

/* void __cdecl ControllerProcessInterrupts(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST *
   __ptr64,unsigned long) */

void __cdecl ControllerProcessInterrupts(PBC_DEVICE *param_1,PBC_REQUEST *param_2,ulong param_3)

{
  PBC_DEVICE *pPVar1;
  PBC_DEVICE *pPVar2;
  uint uVar3;
  int iVar4;
  ulong uVar5;
  uint uVar6;
  int iVar7;
  bool bVar8;
  
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
              &WPP_b3564bc0e82137d896779365436e6d83_Traceguids);
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_Lq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
                &WPP_b3564bc0e82137d896779365436e6d83_Traceguids,param_3,
                (char)*(undefined8 *)param_1);
    }
  }
  uVar5 = LpssApi_CheckControllerAbort(param_1,param_3);
  if (uVar5 != 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
              &WPP_b3564bc0e82137d896779365436e6d83_Traceguids);
    }
    LOCK();
    *(undefined4 *)(param_1 + 0x30) = 0;
    UNLOCK();
    LOCK();
    *(uint *)(param_1 + 0x234) = *(uint *)(param_1 + 0x234) | 1;
    UNLOCK();
    goto LAB_140001a8f;
  }
  uVar5 = LpssApi_CheckControllerError(param_1,param_3);
  if (uVar5 != 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
              &WPP_b3564bc0e82137d896779365436e6d83_Traceguids);
    }
    LOCK();
    *(undefined4 *)(param_1 + 0x30) = 0;
    UNLOCK();
    LOCK();
    *(uint *)(param_1 + 0x238) = *(uint *)(param_1 + 0x238) | 1;
    UNLOCK();
    goto LAB_140001a8f;
  }
  uVar5 = LpssApi_CheckControllerTransferOngoing(param_1,param_3);
  pPVar1 = param_1 + 0x30;
  pPVar2 = param_1 + 0x23c;
  if (uVar5 != 0) {
    LOCK();
    *(uint *)pPVar1 = *(uint *)pPVar1 & ~uVar5;
    UNLOCK();
    LOCK();
    *(uint *)pPVar2 = *(uint *)pPVar2 | 1;
    UNLOCK();
  }
  uVar5 = LpssApi_CheckControllerTransferDone(param_1,param_3);
  if (uVar5 != 0) {
    LOCK();
    *(uint *)pPVar1 = *(uint *)pPVar1 & ~uVar5;
    UNLOCK();
    LOCK();
    *(uint *)(param_1 + 0x248) = *(uint *)(param_1 + 0x248) | 1;
    UNLOCK();
  }
  uVar5 = LpssApi_CheckControllerReadyForTransfer(param_1,param_3);
  if (uVar5 == 0) goto LAB_140001a8f;
  LOCK();
  *(uint *)pPVar1 = *(uint *)pPVar1 & ~uVar5;
  UNLOCK();
  uVar6 = *(uint *)pPVar2;
  do {
    LOCK();
    uVar3 = *(uint *)pPVar2;
    bVar8 = uVar6 == uVar3;
    if (bVar8) {
      *(uint *)pPVar2 = uVar6;
    }
    else {
      uVar6 = uVar3;
    }
    UNLOCK();
  } while (!bVar8);
  if (uVar6 == 0) {
    iVar7 = *(int *)(param_1 + 0x248);
    do {
      LOCK();
      iVar4 = *(int *)(param_1 + 0x248);
      bVar8 = iVar7 == iVar4;
      if (bVar8) {
        *(int *)(param_1 + 0x248) = iVar7;
      }
      else {
        iVar7 = iVar4;
      }
      UNLOCK();
    } while (!bVar8);
    if (iVar7 != 0) goto LAB_140001a4a;
    LOCK();
    *(uint *)(param_1 + 0x244) = *(uint *)(param_1 + 0x244) | 1;
    UNLOCK();
  }
  else {
LAB_140001a4a:
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
              &WPP_b3564bc0e82137d896779365436e6d83_Traceguids);
    }
  }
  uVar5 = LpssApi_CheckControllerFinishData(param_1,param_3);
  if (uVar5 != 0) {
    LOCK();
    *(uint *)pPVar1 = *(uint *)pPVar1 & ~uVar5;
    UNLOCK();
    LOCK();
    *(uint *)(param_1 + 0x248) = *(uint *)(param_1 + 0x248) | 1;
    UNLOCK();
  }
LAB_140001a8f:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
            &WPP_b3564bc0e82137d896779365436e6d83_Traceguids);
  }
  return;
}



===== ControllerTransferData @ 140001ad4 =====

/* void __cdecl ControllerTransferData(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST * __ptr64) */

void __cdecl ControllerTransferData(PBC_DEVICE *param_1,PBC_REQUEST *param_2)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
            &WPP_b3564bc0e82137d896779365436e6d83_Traceguids);
  }
  if (*(int *)(param_2 + 0x44) == 2) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_P(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
               &WPP_b3564bc0e82137d896779365436e6d83_Traceguids,*(undefined8 *)(param_2 + 0x28));
    }
    LpssApi_TransferDataWrite(param_1,param_2);
  }
  else if (*(int *)(param_2 + 0x44) == 1) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_P(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
               &WPP_b3564bc0e82137d896779365436e6d83_Traceguids,*(undefined8 *)(param_2 + 0x28));
    }
    LpssApi_TransferDataRead(param_1,param_2);
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
            &WPP_b3564bc0e82137d896779365436e6d83_Traceguids);
  }
  return;
}



===== ControllerTransferStateNavigation @ 140001be8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl ControllerTransferStateNavigation(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST *
   __ptr64) */

void __cdecl ControllerTransferStateNavigation(PBC_DEVICE *param_1,PBC_REQUEST *param_2)

{
  PBC_DEVICE *pPVar1;
  int iVar2;
  uint uVar3;
  undefined8 uVar4;
  bool bVar5;
  bool bVar6;
  uchar uVar7;
  char cVar8;
  ulong uVar9;
  int iVar10;
  ulong uVar11;
  int iVar12;
  __uint64 _Var13;
  PBC_DEVICE *pPVar14;
  ulong uVar15;
  PBC_DEVICE **ppPVar16;
  undefined **ppuVar17;
  char *pcVar18;
  char *pcVar19;
  uint uVar20;
  bool bVar21;
  bool bVar22;
  undefined1 auStackY_178 [32];
  PBC_DEVICE *local_128;
  PBC_DEVICE *local_120;
  PBC_DEVICE *local_118;
  PBC_DEVICE *local_110;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_178;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x30,
            &WPP_b3564bc0e82137d896779365436e6d83_Traceguids);
  }
  LOCK();
  *(undefined4 *)(param_1 + 0x24c) = 0;
  UNLOCK();
  pPVar1 = param_1 + 600;
  KeClearEvent(pPVar1);
  KeClearEvent(param_1 + 0x270);
  KeClearEvent(param_1 + 0x2a0);
  LOCK();
  *(undefined4 *)(param_1 + 0x230) = 0;
  UNLOCK();
  LOCK();
  *(undefined4 *)(param_1 + 0x234) = 0;
  UNLOCK();
  LOCK();
  *(undefined4 *)(param_1 + 0x238) = 0;
  UNLOCK();
  LOCK();
  *(undefined4 *)(param_1 + 0x23c) = 0;
  UNLOCK();
  LOCK();
  *(undefined4 *)(param_1 + 0x240) = 0;
  UNLOCK();
  LOCK();
  *(undefined4 *)(param_1 + 0x244) = 0;
  UNLOCK();
  LOCK();
  *(undefined4 *)(param_1 + 0x248) = 0;
  UNLOCK();
  LOCK();
  *(undefined4 *)(param_1 + 0x3a4) = 0;
  UNLOCK();
  LOCK();
  *(undefined4 *)(param_1 + 0x3a0) = 0;
  UNLOCK();
  local_118 = param_1 + 0x288;
  bVar22 = true;
  bVar5 = false;
  bVar6 = true;
  uVar20 = 0;
  LOCK();
  *(uint *)(param_1 + 0x244) = *(uint *)(param_1 + 0x244) | 1;
  UNLOCK();
  ppuVar17 = (undefined **)0x0;
  local_128 = pPVar1;
  local_120 = param_1 + 0x270;
  local_110 = param_1 + 0x2a0;
  KeSetEvent(pPVar1,0,0);
  do {
    uVar11 = (ulong)ppuVar17;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      iVar10 = *(int *)(param_1 + 0x30);
      do {
        LOCK();
        iVar12 = *(int *)(param_1 + 0x30);
        bVar21 = iVar10 == iVar12;
        if (bVar21) {
          *(int *)(param_1 + 0x30) = iVar10;
        }
        else {
          iVar10 = iVar12;
        }
        UNLOCK();
      } while (!bVar21);
      uVar11 = 0x31;
      WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x31,
                &WPP_b3564bc0e82137d896779365436e6d83_Traceguids,(uint)(byte)param_1[0x250],
                (char)iVar10);
    }
    pPVar14 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x480);
    ChvP1I2c_ControllerIoGenerateStart(pPVar14,uVar11);
    uVar11 = (ulong)*(undefined8 *)(param_1 + 0x28);
    (*(code *)pPVar14)(WdfDriverGlobals);
    if (*(int *)(param_1 + 0x230) == 0) {
      uVar9 = *(ulong *)(param_1 + 0x30);
      do {
        LOCK();
        uVar15 = *(ulong *)(param_1 + 0x30);
        bVar21 = uVar9 == uVar15;
        if (bVar21) {
          *(ulong *)(param_1 + 0x30) = uVar9;
        }
        else {
          uVar9 = uVar15;
        }
        UNLOCK();
      } while (!bVar21);
      if ((uVar9 != 0) && (param_1[0x250] == (PBC_DEVICE)0x0)) {
        uVar11 = uVar9;
        ControllerEnableInterrupts(param_1,uVar9);
      }
    }
    else if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) &&
            (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      uVar11 = 0x32;
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x32,
              &WPP_b3564bc0e82137d896779365436e6d83_Traceguids);
    }
    pPVar14 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x488);
    ChvP1I2c_ControllerIoGenerateStart(pPVar14,uVar11);
    uVar11 = (ulong)*(undefined8 *)(param_1 + 0x28);
    (*(code *)pPVar14)(WdfDriverGlobals);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      uVar11 = 0x33;
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x33,
              &WPP_b3564bc0e82137d896779365436e6d83_Traceguids);
    }
    pPVar14 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x9e8);
    ChvP1I2c_ControllerIoGenerateStart(pPVar14,uVar11);
    (*(code *)pPVar14)(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x38));
    ppPVar16 = &local_128;
    iVar10 = KeWaitForMultipleObjects(4,ppPVar16,1);
    pPVar14 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x9e0);
    ChvP1I2c_ControllerIoGenerateStart(pPVar14,(ulong)ppPVar16);
    (*(code *)pPVar14)(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x38));
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x34,
               &WPP_b3564bc0e82137d896779365436e6d83_Traceguids,iVar10);
    }
    ppuVar17 = &WPP_GLOBAL_Control;
    uVar11 = 0x40016000;
    _Var13 = 0;
    if (iVar10 == 0) {
      KeClearEvent(pPVar1);
      if ((((param_1[800] != (PBC_DEVICE)0x0) &&
           ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        ppuVar17 = (undefined **)0x35;
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x35,
                &WPP_b3564bc0e82137d896779365436e6d83_Traceguids);
      }
      uVar11 = (ulong)ppuVar17;
      iVar12 = *(int *)(param_1 + 0x234);
      do {
        LOCK();
        iVar2 = *(int *)(param_1 + 0x234);
        bVar21 = iVar12 == iVar2;
        if (bVar21) {
          *(int *)(param_1 + 0x234) = iVar12;
        }
        else {
          iVar12 = iVar2;
        }
        UNLOCK();
      } while (!bVar21);
      if (iVar12 != 0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          ppuVar17 = (undefined **)0x36;
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x36,
                   &WPP_b3564bc0e82137d896779365436e6d83_Traceguids,*(undefined4 *)(param_1 + 0xe0))
          ;
        }
        iVar10 = *(int *)(param_2 + 0x20);
        if (iVar10 != -0x3ffffee0) {
          uVar7 = LpssApi_IsAbortByAddressPhase(param_1);
          if (uVar7 == '\0') {
            *(undefined4 *)(param_2 + 0x20) = 0x10b;
            _Var13 = LpssApi_UpdateTransferDataSize(param_1);
            iVar10 = *(int *)(param_2 + 0x20);
          }
          else {
            *(undefined4 *)(param_2 + 0x20) = 0xc000000e;
            iVar10 = -0x3ffffff2;
          }
        }
        *(__uint64 *)(param_2 + 0x58) = _Var13;
        goto LAB_14000275b;
      }
      iVar12 = *(int *)(param_1 + 0x238);
      do {
        LOCK();
        iVar2 = *(int *)(param_1 + 0x238);
        bVar21 = iVar12 == iVar2;
        if (bVar21) {
          *(int *)(param_1 + 0x238) = iVar12;
        }
        else {
          iVar12 = iVar2;
        }
        UNLOCK();
      } while (!bVar21);
      if (iVar12 == 0) {
        iVar12 = *(int *)(param_1 + 0x23c);
        do {
          LOCK();
          iVar2 = *(int *)(param_1 + 0x23c);
          bVar21 = iVar12 == iVar2;
          if (bVar21) {
            *(int *)(param_1 + 0x23c) = iVar12;
          }
          else {
            iVar12 = iVar2;
          }
          UNLOCK();
        } while (!bVar21);
        if (iVar12 == 0) {
          iVar12 = *(int *)(param_1 + 0x240);
          do {
            LOCK();
            iVar2 = *(int *)(param_1 + 0x240);
            bVar21 = iVar12 == iVar2;
            if (bVar21) {
              *(int *)(param_1 + 0x240) = iVar12;
            }
            else {
              iVar12 = iVar2;
            }
            UNLOCK();
          } while (!bVar21);
          if (iVar12 != 0) {
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) &&
               (3 < (byte)WPP_GLOBAL_Control[0x29])) {
              WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3b,
                      &WPP_b3564bc0e82137d896779365436e6d83_Traceguids);
            }
            LOCK();
            *(undefined4 *)(param_1 + 0x240) = 0;
            UNLOCK();
            _Var13 = LpssApi_UpdateTransferDataSize(param_1);
            if ((((_Var13 != *(__uint64 *)(param_2 + 0x28)) &&
                 ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) &&
               (2 < (byte)WPP_GLOBAL_Control[0x29])) {
              WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3c,
                      &WPP_b3564bc0e82137d896779365436e6d83_Traceguids);
            }
            LOCK();
            *(uint *)(param_1 + 0x248) = *(uint *)(param_1 + 0x248) | 1;
            UNLOCK();
            pPVar14 = pPVar1;
LAB_1400025e3:
            ppuVar17 = (undefined **)0x0;
            KeSetEvent(pPVar14,0,0);
            goto LAB_14000294a;
          }
          iVar12 = *(int *)(param_1 + 0x244);
          do {
            LOCK();
            iVar2 = *(int *)(param_1 + 0x244);
            bVar21 = iVar12 == iVar2;
            if (bVar21) {
              *(int *)(param_1 + 0x244) = iVar12;
            }
            else {
              iVar12 = iVar2;
            }
            UNLOCK();
          } while (!bVar21);
          if (iVar12 == 0) {
            iVar10 = *(int *)(param_1 + 0x248);
            do {
              LOCK();
              iVar12 = *(int *)(param_1 + 0x248);
              bVar21 = iVar10 == iVar12;
              if (bVar21) {
                *(int *)(param_1 + 0x248) = iVar10;
              }
              else {
                iVar10 = iVar12;
              }
              UNLOCK();
            } while (!bVar21);
            if (iVar10 != 0) {
              LOCK();
              *(undefined4 *)(param_1 + 0x248) = 0;
              UNLOCK();
              if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) &&
                 (3 < (byte)WPP_GLOBAL_Control[0x29])) {
                uVar11 = 0x42;
                WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x42,
                        &WPP_b3564bc0e82137d896779365436e6d83_Traceguids);
              }
              if (param_1[800] == (PBC_DEVICE)0x0) goto LAB_14000215c;
              LOCK();
              *(uint *)(param_1 + 0x3a4) = *(uint *)(param_1 + 0x3a4) | 1;
              UNLOCK();
              *(undefined4 *)(param_1 + 0x35c) = 1;
              pPVar14 = param_1 + 0x270;
              goto LAB_1400025e3;
            }
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) &&
               (2 < (byte)WPP_GLOBAL_Control[0x29])) {
              ppuVar17 = (undefined **)0x43;
              WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x43,
                       &WPP_b3564bc0e82137d896779365436e6d83_Traceguids,uVar20);
              uVar20 = uVar20 + 1;
            }
            if (uVar20 < 3) goto LAB_14000294a;
            iVar10 = 0x10b;
          }
          else {
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) &&
               (3 < (byte)WPP_GLOBAL_Control[0x29])) {
              ppuVar17 = (undefined **)0x3d;
              WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3d,
                      &WPP_b3564bc0e82137d896779365436e6d83_Traceguids);
            }
            LOCK();
            *(undefined4 *)(param_1 + 0x244) = 0;
            UNLOCK();
            uVar3 = *(uint *)(param_2 + 0x10);
            bVar5 = false;
            if (uVar3 < *(uint *)(param_2 + 0xc)) {
              ppuVar17 = (undefined **)(ulonglong)uVar3;
              if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) &&
                 (4 < (byte)WPP_GLOBAL_Control[0x29])) {
                WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3e,
                         &WPP_b3564bc0e82137d896779365436e6d83_Traceguids,uVar3);
                ppuVar17 = (undefined **)(ulonglong)*(uint *)(param_2 + 0x10);
              }
              iVar10 = PbcRequestConfigureForIndex(param_2,(ulong)ppuVar17);
              if ((-1 < iVar10) &&
                 (ppuVar17 = (undefined **)param_2, iVar10 = PbcRequestDoTransfer(param_1,param_2),
                 -1 < iVar10)) {
                uVar4 = *(undefined8 *)(param_1 + 0x48);
                pPVar14 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x9f8);
                ChvP1I2c_ControllerIoGenerateStart(pPVar14,(ulong)ppuVar17);
                cVar8 = (*(code *)pPVar14)(WdfDriverGlobals,uVar4,0xfffffffffd050f80);
                if ((cVar8 != '\0') &&
                   ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control &&
                     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) &&
                    (2 < (byte)WPP_GLOBAL_Control[0x29])))) {
                  WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3f,
                          &WPP_b3564bc0e82137d896779365436e6d83_Traceguids);
                }
                if (param_1[800] == (PBC_DEVICE)0x0) {
                  LOCK();
                  *(uint *)(param_1 + 0x23c) = *(uint *)(param_1 + 0x23c) | 1;
                  UNLOCK();
                  ppuVar17 = (undefined **)0x0;
                  KeSetEvent(pPVar1,0,0);
                  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) &&
                     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
                    ppuVar17 = (undefined **)0x40;
                    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x40,
                            &WPP_b3564bc0e82137d896779365436e6d83_Traceguids);
                  }
                }
                else {
                  LOCK();
                  *(undefined4 *)(param_1 + 0x3a4) = 0;
                  UNLOCK();
                  LOCK();
                  *(undefined4 *)(param_1 + 0x3a0) = 0;
                  UNLOCK();
                  ppuVar17 = (undefined **)param_2;
                  iVar10 = ControllerExecuteDmaTransaction(param_1,param_2);
                }
                bVar22 = bVar6;
              }
            }
            else {
              if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) &&
                 (2 < (byte)WPP_GLOBAL_Control[0x29])) {
                ppuVar17 = (undefined **)0x41;
                WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x41,
                        &WPP_b3564bc0e82137d896779365436e6d83_Traceguids);
              }
              param_2[0x24] = (PBC_REQUEST)0x1;
            }
          }
        }
        else {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) &&
             (3 < (byte)WPP_GLOBAL_Control[0x29])) {
            ppuVar17 = (undefined **)0x38;
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x38,
                    &WPP_b3564bc0e82137d896779365436e6d83_Traceguids);
          }
          uVar11 = (ulong)ppuVar17;
          LOCK();
          *(undefined4 *)(param_1 + 0x23c) = 0;
          UNLOCK();
          if (*(longlong *)(param_2 + 0x28) == *(longlong *)(param_2 + 0x58)) {
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) &&
               (2 < (byte)WPP_GLOBAL_Control[0x29])) {
              uVar11 = 0x39;
              WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x39,
                      &WPP_b3564bc0e82137d896779365436e6d83_Traceguids);
            }
            goto LAB_14000215c;
          }
          if (param_1[800] != (PBC_DEVICE)0x0) goto LAB_14000294a;
          iVar10 = *(int *)(param_2 + 0x20);
          if ((iVar10 == 0) || (iVar10 == -0x3ffffee0)) {
            if ((bVar22) && (*(int *)(param_2 + 0x44) == 1)) {
              ppuVar17 = (undefined **)param_2;
              iVar10 = LpssApi_PrepareForTransfer(param_1,param_2);
              if (-1 < iVar10) {
                bVar6 = false;
                LOCK();
                *(uint *)(param_1 + 0x23c) = *(uint *)(param_1 + 0x23c) | 1;
                UNLOCK();
                bVar22 = false;
              }
            }
            else {
              ppuVar17 = (undefined **)param_2;
              ControllerTransferData(param_1,param_2);
              iVar10 = *(int *)(param_2 + 0x20);
              if (-1 < iVar10) {
                if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                    ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) &&
                   (3 < (byte)WPP_GLOBAL_Control[0x29])) {
                  ppuVar17 = (undefined **)0x3a;
                  WPP_SF_ddPP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3a,
                              &WPP_b3564bc0e82137d896779365436e6d83_Traceguids,
                              *(int *)(param_2 + 0x10) + 1,(char)*(undefined4 *)(param_2 + 0xc),
                              (char)*(undefined8 *)(param_2 + 0x58),
                              (char)*(undefined8 *)(param_2 + 0x28));
                }
                if (*(longlong *)(param_2 + 0x28) == *(longlong *)(param_2 + 0x58)) {
                  if (*(int *)(param_2 + 0x44) == 2) {
                    if (param_2[0x41] == (PBC_REQUEST)0x1) {
                      LOCK();
                      *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) & 0xffffffef;
                      UNLOCK();
                    }
                    LOCK();
                    *(uint *)(param_1 + 0x248) = *(uint *)(param_1 + 0x248) | 1;
                    UNLOCK();
                  }
                  else {
                    bVar5 = true;
                  }
                }
                else {
                  LOCK();
                  *(uint *)(param_1 + 0x23c) = *(uint *)(param_1 + 0x23c) | 1;
                  UNLOCK();
                  if (*(int *)(param_2 + 0x44) == 1) {
                    ppuVar17 = (undefined **)0x0;
                    KeSetEvent(pPVar1,0,0);
                  }
                }
                bVar22 = true;
                bVar6 = true;
                goto LAB_14000294a;
              }
            }
          }
        }
LAB_14000275b:
        uVar11 = (ulong)ppuVar17;
        if (iVar10 == 0x10b) goto LAB_140002767;
        if (-1 < iVar10) goto LAB_14000294a;
      }
      else {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          ppuVar17 = (undefined **)0x37;
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x37,
                  &WPP_b3564bc0e82137d896779365436e6d83_Traceguids);
        }
        iVar10 = -0x3fffffc4;
      }
LAB_14000290e:
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        ppuVar17 = (undefined **)0x4c;
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4c,
                &WPP_b3564bc0e82137d896779365436e6d83_Traceguids);
      }
      *(int *)(param_2 + 0x20) = iVar10;
      bVar5 = true;
LAB_14000294a:
      uVar11 = (ulong)ppuVar17;
      if (bVar5) goto LAB_140002953;
    }
    else {
      if (iVar10 == 1) {
        KeClearEvent(param_1 + 0x270);
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          pcVar18 = "Read";
          pcVar19 = "Rx";
          if (*(int *)(param_2 + 0x44) == 2) {
            pcVar18 = "Write";
          }
          if (*(int *)(param_1 + 0x370) != 0) {
            pcVar19 = "Tx";
          }
          WPP_SF_ssD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x44,
                     &WPP_b3564bc0e82137d896779365436e6d83_Traceguids,pcVar19,pcVar18,
                     (char)*(undefined4 *)(param_1 + 0x35c));
        }
        ppuVar17 = &WPP_GLOBAL_Control;
        uVar11 = 0x40016000;
        uVar9 = 0x40016000;
        uVar15 = 0x40016000;
        iVar10 = *(int *)(param_1 + 0x35c);
        if (iVar10 != 1) {
          if ((iVar10 == 2) || (iVar10 == 4)) {
            *(undefined4 *)(param_1 + 0x318) = 0;
            *(undefined4 *)(param_2 + 0x20) = 0xc0000001;
          }
          else if (iVar10 != 8) {
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) &&
               (3 < (byte)WPP_GLOBAL_Control[0x29])) {
              ppuVar17 = (undefined **)0x46;
              WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x46,
                      &WPP_b3564bc0e82137d896779365436e6d83_Traceguids);
            }
            goto LAB_14000294a;
          }
          goto LAB_14000215c;
        }
        if (*(int *)(param_2 + 0x44) != 2) {
          if (*(int *)(param_2 + 0x44) == 1) {
            *(undefined8 *)(param_2 + 0x58) = *(undefined8 *)(param_1 + 0x368);
            iVar10 = *(int *)(param_1 + 0x3a4);
            do {
              LOCK();
              iVar12 = *(int *)(param_1 + 0x3a4);
              bVar21 = iVar10 == iVar12;
              if (bVar21) {
                *(int *)(param_1 + 0x3a4) = iVar10;
              }
              else {
                iVar10 = iVar12;
              }
              UNLOCK();
            } while (!bVar21);
            if (iVar10 != 0) {
              iVar10 = *(int *)(param_1 + 0x3a0);
              do {
                LOCK();
                iVar12 = *(int *)(param_1 + 0x3a0);
                bVar21 = iVar10 == iVar12;
                if (bVar21) {
                  *(int *)(param_1 + 0x3a0) = iVar10;
                }
                else {
                  iVar10 = iVar12;
                }
                UNLOCK();
              } while (!bVar21);
              if (iVar10 != 0) goto LAB_14000215c;
            }
          }
          goto LAB_14000294a;
        }
        bVar5 = true;
        *(undefined8 *)(param_2 + 0x58) = *(undefined8 *)(param_1 + 0x360);
        iVar10 = *(int *)(param_1 + 0x3a4);
        do {
          LOCK();
          iVar12 = *(int *)(param_1 + 0x3a4);
          bVar22 = iVar10 == iVar12;
          if (bVar22) {
            *(int *)(param_1 + 0x3a4) = iVar10;
          }
          else {
            iVar10 = iVar12;
          }
          UNLOCK();
        } while (!bVar22);
        uVar11 = uVar9;
        if (iVar10 != 0) goto LAB_140002953;
        if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
          if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0) &&
             (3 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar11 = 0x45;
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x45,
                    &WPP_b3564bc0e82137d896779365436e6d83_Traceguids);
          }
          goto LAB_140002953;
        }
      }
      else {
        if (iVar10 == 2) {
          KeClearEvent(param_1 + 0x288);
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            ppuVar17 = (undefined **)0x48;
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x48,
                    &WPP_b3564bc0e82137d896779365436e6d83_Traceguids);
          }
          if ((*(int *)(param_1 + 100) != 1) ||
             ((uVar11 = HWREG<unsigned_long>::Read
                                  ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x78)),
              uVar11 == 0 && (*(longlong *)(param_2 + 0x28) == *(longlong *)(param_2 + 0x58))))) {
            iVar10 = -0x3ffffee0;
            goto LAB_14000290e;
          }
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0 &&
              (3 < (byte)WPP_GLOBAL_Control[0x29])))) {
            ppuVar17 = (undefined **)0x49;
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x49,
                    &WPP_b3564bc0e82137d896779365436e6d83_Traceguids);
          }
          *(undefined4 *)(param_2 + 0x20) = 0xc0000120;
          goto LAB_14000294a;
        }
        if (iVar10 == 3) {
          KeClearEvent(param_1 + 0x2a0);
          if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
            if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0) &&
               (3 < (byte)WPP_GLOBAL_Control[0x29])) {
              uVar11 = 0x47;
              WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x47,
                      &WPP_b3564bc0e82137d896779365436e6d83_Traceguids);
            }
            goto LAB_140002767;
          }
        }
        else {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) &&
             (2 < (byte)WPP_GLOBAL_Control[0x29])) {
            ppuVar17 = (undefined **)0x4a;
            WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4a,
                      &WPP_b3564bc0e82137d896779365436e6d83_Traceguids,iVar10,(char)uVar20);
            uVar20 = uVar20 + 1;
          }
          uVar11 = (ulong)ppuVar17;
          if (uVar20 < 3) goto LAB_14000275b;
LAB_140002767:
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar11 = 0x4b;
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4b,
                    &WPP_b3564bc0e82137d896779365436e6d83_Traceguids);
          }
        }
        *(undefined8 *)(param_2 + 0x18) = 0;
        if (*(int *)(param_2 + 0x20) != -0x3ffffee0) {
          *(undefined4 *)(param_2 + 0x20) = 0x10b;
        }
LAB_14000215c:
        bVar5 = true;
LAB_140002953:
        uVar15 = uVar11;
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar15 = 0x4d;
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4d,
                  &WPP_b3564bc0e82137d896779365436e6d83_Traceguids);
        }
      }
      uVar4 = *(undefined8 *)(param_1 + 0x48);
      pPVar14 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0xa00);
      ChvP1I2c_ControllerIoGenerateStart(pPVar14,uVar15);
      cVar8 = (*(code *)pPVar14)(WdfDriverGlobals,uVar4,0);
      if (((cVar8 != '\0') && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
         (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0 && (4 < (byte)WPP_GLOBAL_Control[0x29])))
         ) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4e,
                &WPP_b3564bc0e82137d896779365436e6d83_Traceguids);
      }
      if (param_1[800] != (PBC_DEVICE)0x0) {
        ControllerDmaCompleteTransaction(param_1,param_2,3);
      }
      ppuVar17 = (undefined **)param_2;
      ControllerCompleteTransfer(param_1,param_2);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        ppuVar17 = (undefined **)0x4f;
        WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4f,
                  &WPP_b3564bc0e82137d896779365436e6d83_Traceguids,*(undefined4 *)(param_2 + 0x10),
                  (char)*(undefined4 *)(param_2 + 0xc));
      }
      if (param_2[0x24] != (PBC_REQUEST)0x0) break;
      bVar22 = bVar6;
      if (param_2[0x88] == (PBC_REQUEST)0x0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x50,
                  &WPP_b3564bc0e82137d896779365436e6d83_Traceguids);
        }
        bVar5 = false;
        uVar20 = 0;
        LOCK();
        *(uint *)(param_1 + 0x244) = *(uint *)(param_1 + 0x244) | 1;
        UNLOCK();
        ppuVar17 = (undefined **)0x0;
        KeSetEvent(pPVar1,0,0);
      }
    }
  } while (param_2[0x24] == (PBC_REQUEST)0x0);
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x51,
              &WPP_b3564bc0e82137d896779365436e6d83_Traceguids);
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x52,
              &WPP_b3564bc0e82137d896779365436e6d83_Traceguids);
    }
  }
  return;
}



===== ControllerUninitialize @ 140002b48 =====

/* void __cdecl ControllerUninitialize(struct PBC_DEVICE * __ptr64) */

void __cdecl ControllerUninitialize(PBC_DEVICE *param_1)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
            &WPP_b3564bc0e82137d896779365436e6d83_Traceguids);
  }
  ControllerDisableInterrupts(param_1);
  LpssApi_ControllerUnitialize(param_1);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
            &WPP_b3564bc0e82137d896779365436e6d83_Traceguids);
  }
  return;
}



===== ControllerWatchdogTimerExpired @ 140002be0 =====

/* void __cdecl ControllerWatchdogTimerExpired(struct WDFTIMER__ * __ptr64) */

void __cdecl ControllerWatchdogTimerExpired(WDFTIMER__ *param_1)

{
  PBC_DEVICE *pPVar1;
  undefined8 uVar2;
  longlong lVar3;
  ulong uVar4;
  ulong in_EDX;
  
  uVar4 = (ulong)param_1;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    in_EDX = 0x2d;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2d,
            &WPP_b3564bc0e82137d896779365436e6d83_Traceguids);
  }
  pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0xa08);
  ChvP1I2c_ControllerIoGenerateStart(pPVar1,in_EDX);
  uVar2 = (*(code *)pPVar1)(WdfDriverGlobals);
  pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x650);
  ChvP1I2c_ControllerIoGenerateStart(pPVar1,uVar4);
  lVar3 = (*(code *)pPVar1)(WdfDriverGlobals,uVar2,PTR__WDF_PBC_DEVICE_TYPE_INFO_140016020);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (2 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2e,
            &WPP_b3564bc0e82137d896779365436e6d83_Traceguids);
  }
  KeSetEvent(lVar3 + 0x2a0,0,0);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2f,
            &WPP_b3564bc0e82137d896779365436e6d83_Traceguids);
  }
  return;
}



===== WPP_SF_ @ 140002d08 =====

void WPP_SF_(undefined8 param_1,uint param_2,undefined8 param_3)

{
  PBC_DEVICE *pPVar1;
  
  pPVar1 = pfnWppTraceMessage;
  ChvP1I2c_ControllerIoGenerateStart(pfnWppTraceMessage,param_2);
  (*(code *)pPVar1)(param_1,0x2b,param_3,param_2 & 0xffff,0);
  return;
}



===== WPP_SF_D @ 140002d60 =====

void WPP_SF_D(undefined8 param_1,uint param_2,undefined8 param_3,undefined4 param_4)

{
  PBC_DEVICE *pPVar1;
  undefined4 local_res20 [2];
  
  pPVar1 = pfnWppTraceMessage;
  local_res20[0] = param_4;
  ChvP1I2c_ControllerIoGenerateStart(pfnWppTraceMessage,param_2);
  (*(code *)pPVar1)(param_1,0x2b,param_3,param_2 & 0xffff,local_res20,4,0);
  return;
}



===== WPP_SF_Lq @ 140002dd0 =====

void WPP_SF_Lq(undefined8 param_1,uint param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  PBC_DEVICE *pPVar1;
  undefined4 local_res20 [2];
  
  pPVar1 = pfnWppTraceMessage;
  local_res20[0] = param_4;
  ChvP1I2c_ControllerIoGenerateStart(pfnWppTraceMessage,param_2);
  (*(code *)pPVar1)(param_1,0x2b,param_3,param_2 & 0xffff,local_res20,4,&param_5,8,0);
  return;
}



===== WPP_SF_LsPLq @ 140002e58 =====

void WPP_SF_LsPLq(undefined8 param_1,uint param_2,undefined8 param_3,undefined4 param_4,
                 char *param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  PBC_DEVICE *pPVar1;
  char *pcVar2;
  longlong lVar3;
  longlong lVar4;
  undefined4 local_res20 [2];
  
  pPVar1 = pfnWppTraceMessage;
  if (param_5 == (char *)0x0) {
    lVar4 = 5;
  }
  else {
    lVar3 = -1;
    do {
      lVar4 = lVar3;
      lVar3 = lVar4 + 1;
    } while (param_5[lVar3] != '\0');
    lVar4 = lVar4 + 2;
  }
  pcVar2 = "NULL";
  if (param_5 != (char *)0x0) {
    pcVar2 = param_5;
  }
  local_res20[0] = param_4;
  ChvP1I2c_ControllerIoGenerateStart(pfnWppTraceMessage,param_2);
  (*(code *)pPVar1)(param_1,0x2b,param_3,(short)param_2,local_res20,4,pcVar2,lVar4,&param_6,8,
                    &param_7,4,&param_8,8,0);
  return;
}



===== WPP_SF_P @ 140002f50 =====

void WPP_SF_P(undefined8 param_1,uint param_2,undefined8 param_3,undefined8 param_4)

{
  PBC_DEVICE *pPVar1;
  undefined8 local_res20;
  
  pPVar1 = pfnWppTraceMessage;
  local_res20 = param_4;
  ChvP1I2c_ControllerIoGenerateStart(pfnWppTraceMessage,param_2);
  (*(code *)pPVar1)(param_1,0x2b,param_3,param_2 & 0xffff,&local_res20,8,0);
  return;
}



===== WPP_SF_dD @ 140002fc0 =====

void WPP_SF_dD(undefined8 param_1,uint param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  PBC_DEVICE *pPVar1;
  undefined4 local_res20 [2];
  
  pPVar1 = pfnWppTraceMessage;
  local_res20[0] = param_4;
  ChvP1I2c_ControllerIoGenerateStart(pfnWppTraceMessage,param_2);
  (*(code *)pPVar1)(param_1,0x2b,param_3,param_2 & 0xffff,local_res20,4,&param_5,4,0);
  return;
}



===== WPP_SF_ddPP @ 140003040 =====

void WPP_SF_ddPP(undefined8 param_1,uint param_2,undefined8 param_3,undefined4 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  PBC_DEVICE *pPVar1;
  undefined4 local_res20 [2];
  
  pPVar1 = pfnWppTraceMessage;
  local_res20[0] = param_4;
  ChvP1I2c_ControllerIoGenerateStart(pfnWppTraceMessage,param_2);
  (*(code *)pPVar1)(param_1,0x2b,param_3,param_2 & 0xffff,local_res20,4,&param_5,4,&param_6,8,
                    &param_7,8,0);
  return;
}



===== WPP_SF_xd @ 1400030f0 =====

void WPP_SF_xd(undefined8 param_1,uint param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  PBC_DEVICE *pPVar1;
  undefined8 local_res20;
  
  pPVar1 = pfnWppTraceMessage;
  local_res20 = param_4;
  ChvP1I2c_ControllerIoGenerateStart(pfnWppTraceMessage,param_2);
  (*(code *)pPVar1)(param_1,0x2b,param_3,param_2 & 0xffff,&local_res20,8,&param_5,4,0);
  return;
}



===== WPP_SF_ssD @ 140003178 =====

void WPP_SF_ssD(undefined8 param_1,uint param_2,undefined8 param_3,char *param_4,char *param_5,
               undefined1 param_6)

{
  PBC_DEVICE *pPVar1;
  longlong lVar2;
  char *pcVar3;
  char *pcVar4;
  longlong lVar5;
  longlong lVar6;
  
  pPVar1 = pfnWppTraceMessage;
  if (param_5 == (char *)0x0) {
    lVar6 = 5;
  }
  else {
    lVar5 = -1;
    do {
      lVar6 = lVar5;
      lVar5 = lVar6 + 1;
    } while (param_5[lVar5] != '\0');
    lVar6 = lVar6 + 2;
  }
  lVar5 = -1;
  if (param_4 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    do {
      lVar2 = lVar5;
      lVar5 = lVar2 + 1;
    } while (param_4[lVar5] != '\0');
    lVar2 = lVar2 + 2;
  }
  pcVar4 = "NULL";
  if (param_5 != (char *)0x0) {
    pcVar4 = param_5;
  }
  pcVar3 = "NULL";
  if (param_4 != (char *)0x0) {
    pcVar3 = param_4;
  }
  ChvP1I2c_ControllerIoGenerateStart(pfnWppTraceMessage,param_2);
  (*(code *)pPVar1)(param_1,0x2b,param_3,(short)param_2,pcVar3,lVar2,pcVar4,lVar6,&param_6,4,0);
  return;
}



===== WPP_SF_ssPLLqq @ 140003268 =====

void WPP_SF_ssPLLqq(undefined8 param_1,uint param_2,undefined8 param_3,char *param_4,char *param_5,
                   undefined1 param_6,undefined1 param_7,undefined1 param_8,undefined1 param_9,
                   undefined1 param_10)

{
  PBC_DEVICE *pPVar1;
  longlong lVar2;
  char *pcVar3;
  char *pcVar4;
  longlong lVar5;
  longlong lVar6;
  
  pPVar1 = pfnWppTraceMessage;
  if (param_5 == (char *)0x0) {
    lVar6 = 5;
  }
  else {
    lVar5 = -1;
    do {
      lVar6 = lVar5;
      lVar5 = lVar6 + 1;
    } while (param_5[lVar5] != '\0');
    lVar6 = lVar6 + 2;
  }
  lVar5 = -1;
  if (param_4 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    do {
      lVar2 = lVar5;
      lVar5 = lVar2 + 1;
    } while (param_4[lVar5] != '\0');
    lVar2 = lVar2 + 2;
  }
  pcVar4 = "NULL";
  if (param_5 != (char *)0x0) {
    pcVar4 = param_5;
  }
  pcVar3 = "NULL";
  if (param_4 != (char *)0x0) {
    pcVar3 = param_4;
  }
  ChvP1I2c_ControllerIoGenerateStart(pfnWppTraceMessage,param_2);
  (*(code *)pPVar1)(param_1,0x2b,param_3,(short)param_2,pcVar3,lVar2,pcVar4,lVar6,&param_6,8,
                    &param_7,4,&param_8,4,&param_9,8,&param_10,8,0);
  return;
}



===== ControllerDestroyMdlForDma @ 1400033b0 =====

/* void __cdecl ControllerDestroyMdlForDma(struct _MDL * __ptr64) */

void __cdecl ControllerDestroyMdlForDma(_MDL *param_1)

{
  _MDL *p_Var1;
  
  if (param_1 != (_MDL *)0x0) {
    do {
      p_Var1 = *(_MDL **)param_1;
      IoFreeMdl(param_1);
      param_1 = p_Var1;
    } while (p_Var1 != (_MDL *)0x0);
  }
  return;
}



===== ControllerDmaCompleteTransaction @ 1400033d4 =====

/* long __cdecl ControllerDmaCompleteTransaction(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST *
   __ptr64,unsigned long) */

long __cdecl
ControllerDmaCompleteTransaction(PBC_DEVICE *param_1,PBC_REQUEST *param_2,ulong param_3)

{
  int iVar1;
  uint uVar2;
  PBC_DEVICE *pPVar3;
  longlong lVar4;
  undefined8 uVar5;
  char cVar6;
  ulong uVar7;
  int iVar8;
  uint uVar9;
  PBC_REQUEST *pPVar10;
  bool bVar11;
  
  pPVar10 = param_2;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    pPVar10 = (PBC_REQUEST *)0x1b;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
            &WPP_c579c2b1b5af3efbd9446f4704323067_Traceguids);
  }
  if (param_1[800] == (PBC_DEVICE)0x0) goto LAB_140003663;
  pPVar3 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x9e0);
  ChvP1I2c_ControllerIoGenerateStart(pPVar3,(ulong)pPVar10);
  uVar7 = (ulong)*(undefined8 *)(param_1 + 0x328);
  (*(code *)pPVar3)(WdfDriverGlobals);
  if ((param_3 & 1) != 0) {
    lVar4 = *(longlong *)(param_1 + 8);
    uVar7 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(lVar4 + 0x88));
    uVar7 = uVar7 & 0xfffffffd;
    HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(lVar4 + 0x88),uVar7);
    if (param_1[0x358] != (PBC_DEVICE)0x0) {
      iVar8 = *(int *)(param_1 + 0x3a4);
      do {
        LOCK();
        iVar1 = *(int *)(param_1 + 0x3a4);
        bVar11 = iVar8 == iVar1;
        if (bVar11) {
          *(int *)(param_1 + 0x3a4) = iVar8;
        }
        else {
          iVar8 = iVar1;
        }
        UNLOCK();
      } while (!bVar11);
      if (iVar8 == 0) {
        uVar9 = *(uint *)(param_1 + 0x3ac);
        do {
          LOCK();
          uVar2 = *(uint *)(param_1 + 0x3ac);
          bVar11 = uVar9 == uVar2;
          if (bVar11) {
            *(uint *)(param_1 + 0x3ac) = uVar9 | 1;
          }
          else {
            uVar9 = uVar2;
          }
          UNLOCK();
        } while (!bVar11);
        if (uVar9 == 0) {
          iVar8 = *(int *)(param_2 + 0x70);
          do {
            LOCK();
            iVar1 = *(int *)(param_2 + 0x70);
            bVar11 = iVar8 == iVar1;
            if (bVar11) {
              *(int *)(param_2 + 0x70) = iVar8;
            }
            else {
              iVar8 = iVar1;
            }
            UNLOCK();
          } while (!bVar11);
          if (iVar8 != 0) {
            uVar5 = *(undefined8 *)(param_1 + 0x380);
            pPVar3 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0xcf0);
            ChvP1I2c_ControllerIoGenerateStart(pPVar3,uVar7);
            uVar7 = (ulong)uVar5;
            cVar6 = (*(code *)pPVar3)(WdfDriverGlobals);
            if (cVar6 != '\0') goto LAB_140003540;
          }
          pPVar3 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0xd50);
          ChvP1I2c_ControllerIoGenerateStart(pPVar3,uVar7);
          uVar7 = (ulong)*(undefined8 *)(param_1 + 0x380);
          (*(code *)pPVar3)(WdfDriverGlobals);
        }
      }
    }
LAB_140003540:
    LOCK();
    *(undefined4 *)(param_1 + 0x3a4) = 0;
    UNLOCK();
  }
  if (((param_3 & 2) != 0) && (*(int *)(param_2 + 0x44) == 1)) {
    lVar4 = *(longlong *)(param_1 + 8);
    uVar7 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(lVar4 + 0x88));
    uVar7 = uVar7 & 0xfffffffe;
    HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(lVar4 + 0x88),uVar7);
    if (param_1[0x359] != (PBC_DEVICE)0x0) {
      iVar8 = *(int *)(param_1 + 0x3a0);
      do {
        LOCK();
        iVar1 = *(int *)(param_1 + 0x3a0);
        bVar11 = iVar8 == iVar1;
        if (bVar11) {
          *(int *)(param_1 + 0x3a0) = iVar8;
        }
        else {
          iVar8 = iVar1;
        }
        UNLOCK();
      } while (!bVar11);
      if (iVar8 == 0) {
        uVar9 = *(uint *)(param_1 + 0x3a8);
        do {
          LOCK();
          uVar2 = *(uint *)(param_1 + 0x3a8);
          bVar11 = uVar9 == uVar2;
          if (bVar11) {
            *(uint *)(param_1 + 0x3a8) = uVar9 | 1;
          }
          else {
            uVar9 = uVar2;
          }
          UNLOCK();
        } while (!bVar11);
        if (uVar9 == 0) {
          iVar8 = *(int *)(param_2 + 0x74);
          do {
            LOCK();
            iVar1 = *(int *)(param_2 + 0x74);
            bVar11 = iVar8 == iVar1;
            if (bVar11) {
              *(int *)(param_2 + 0x74) = iVar8;
            }
            else {
              iVar8 = iVar1;
            }
            UNLOCK();
          } while (!bVar11);
          if (iVar8 != 0) {
            uVar5 = *(undefined8 *)(param_1 + 0x388);
            pPVar3 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0xcf0);
            ChvP1I2c_ControllerIoGenerateStart(pPVar3,uVar7);
            uVar7 = (ulong)uVar5;
            cVar6 = (*(code *)pPVar3)(WdfDriverGlobals);
            if (cVar6 != '\0') goto LAB_140003634;
          }
          pPVar3 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0xd50);
          ChvP1I2c_ControllerIoGenerateStart(pPVar3,uVar7);
          uVar7 = (ulong)*(undefined8 *)(param_1 + 0x388);
          (*(code *)pPVar3)(WdfDriverGlobals);
        }
      }
    }
LAB_140003634:
    LOCK();
    *(undefined4 *)(param_1 + 0x3a0) = 0;
    UNLOCK();
  }
  pPVar3 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x9e8);
  ChvP1I2c_ControllerIoGenerateStart(pPVar3,uVar7);
  (*(code *)pPVar3)(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x328));
LAB_140003663:
  ControllerDisableEventsAndInterrupts(param_1);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
            &WPP_c579c2b1b5af3efbd9446f4704323067_Traceguids);
  }
  return 0;
}



===== ControllerExecuteDmaTransaction @ 1400036b4 =====

/* long __cdecl ControllerExecuteDmaTransaction(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST *
   __ptr64) */

long __cdecl ControllerExecuteDmaTransaction(PBC_DEVICE *param_1,PBC_REQUEST *param_2)

{
  PBC_DEVICE *pPVar1;
  undefined8 uVar2;
  longlong lVar3;
  longlong lVar4;
  __uint64 _Var5;
  undefined8 *puVar6;
  long lVar7;
  undefined8 *puVar8;
  ulong uVar9;
  uint uVar10;
  PBC_REQUEST *pPVar11;
  undefined8 uVar12;
  ulong local_res8 [2];
  __uint64 local_res10;
  _MDL *local_res18;
  undefined8 *local_res20;
  
  pPVar11 = param_2;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    pPVar11 = (PBC_REQUEST *)0xa;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_c579c2b1b5af3efbd9446f4704323067_Traceguids);
  }
  uVar12 = *(undefined8 *)(param_1 + 0x380);
  *(undefined8 *)(param_1 + 0x390) = 0;
  lVar7 = 0;
  *(undefined8 *)(param_1 + 0x398) = 0;
  *(undefined8 *)(param_1 + 0x374) = 0;
  *(undefined4 *)(param_1 + 0x35c) = 0;
  *(undefined8 *)(param_1 + 0x360) = 0;
  *(undefined8 *)(param_1 + 0x368) = 0;
  local_res18 = (_MDL *)0x0;
  local_res8[0] = 0;
  local_res10 = 0;
  pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x650);
  ChvP1I2c_ControllerIoGenerateStart(pPVar1,(ulong)pPVar11);
  local_res20 = (undefined8 *)
                (*(code *)pPVar1)(WdfDriverGlobals,uVar12,
                                  PTR__WDF_DMA_TRANSACTION_CONTEXT_TYPE_INFO_140016098);
  uVar2 = *(undefined8 *)(param_1 + 0x388);
  pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x650);
  ChvP1I2c_ControllerIoGenerateStart(pPVar1,(ulong)uVar12);
  puVar8 = (undefined8 *)
           (*(code *)pPVar1)(WdfDriverGlobals,uVar2,
                             PTR__WDF_DMA_TRANSACTION_CONTEXT_TYPE_INFO_140016098);
  LOCK();
  *(undefined4 *)(param_1 + 0x3ac) = 0;
  UNLOCK();
  LOCK();
  *(undefined4 *)(param_1 + 0x3a8) = 0;
  UNLOCK();
  if (*(int *)(param_2 + 0x44) == 2) {
    pPVar11 = param_2;
    lVar7 = ControllerPrepareMdlForDmaTx(param_1,param_2,&local_res18,local_res8,&local_res10);
    _Var5 = local_res10;
    uVar10 = (uint)pPVar11;
    if (lVar7 < 0) {
      uVar10 = 0x40016000;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (uVar10 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar10 & 0x20) != 0)) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar10 = 0xb;
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                &WPP_c579c2b1b5af3efbd9446f4704323067_Traceguids);
      }
      goto LAB_140004086;
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      uVar10 = 0xc;
      WPP_SF_Lq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                &WPP_c579c2b1b5af3efbd9446f4704323067_Traceguids,local_res8[0],(char)local_res10);
    }
    *(_MDL **)(param_1 + 0x390) = local_res18;
    if (local_res18 != (_MDL *)0x0) {
      param_1[0x358] = (PBC_DEVICE)0x0;
      pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x330);
      ChvP1I2c_ControllerIoGenerateStart(pPVar1,uVar10);
      uVar9 = (ulong)*(undefined8 *)(param_1 + 0x380);
      (*(code *)pPVar1)(WdfDriverGlobals);
      lVar3 = *(longlong *)(param_1 + 0x390);
      uVar12 = *(undefined8 *)(param_1 + 0x380);
      uVar10 = *(uint *)(lVar3 + 0x2c);
      pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x318);
      lVar4 = *(longlong *)(lVar3 + 0x20);
      ChvP1I2c_ControllerIoGenerateStart(pPVar1,uVar9);
      lVar7 = (*(code *)pPVar1)(WdfDriverGlobals,uVar12,ProgramDmaCallback,1,lVar3,
                                (ulonglong)uVar10 + lVar4,_Var5);
      puVar8 = local_res20;
      uVar10 = (uint)uVar12;
      if (lVar7 < 0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar10 = 0xe;
LAB_140003980:
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar10,
                   &WPP_c579c2b1b5af3efbd9446f4704323067_Traceguids,lVar7);
        }
      }
      else {
        param_1[0x358] = (PBC_DEVICE)0x1;
        local_res20[5] = *(undefined8 *)(param_1 + 0x390);
        *(ulong *)(local_res20 + 6) = local_res8[0];
        local_res20[7] = _Var5;
        *local_res20 = param_1;
        local_res20[1] = param_2;
        pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0xce0);
        ChvP1I2c_ControllerIoGenerateStart(pPVar1,uVar10);
        uVar12 = *(undefined8 *)(param_1 + 0x380);
        (*(code *)pPVar1)(WdfDriverGlobals,uVar12,0x10);
        pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0xcc0);
        ChvP1I2c_ControllerIoGenerateStart(pPVar1,(ulong)uVar12);
        uVar12 = *(undefined8 *)(param_1 + 0x380);
        (*(code *)pPVar1)(WdfDriverGlobals,uVar12,SysDmaConfigureChannel,0);
        pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0xcc8);
        ChvP1I2c_ControllerIoGenerateStart(pPVar1,(ulong)uVar12);
        uVar12 = *(undefined8 *)(param_1 + 0x380);
        (*(code *)pPVar1)(WdfDriverGlobals,uVar12,SysDmaTransferCompleteTx,0);
        uVar9 = (ulong)uVar12;
        LpssApi_DmaPreExecute(param_1);
        uVar12 = *(undefined8 *)(param_1 + 0x380);
        pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x328);
        ChvP1I2c_ControllerIoGenerateStart(pPVar1,uVar9);
        lVar7 = (*(code *)pPVar1)(WdfDriverGlobals,uVar12,puVar8);
        uVar10 = (uint)uVar12;
        if (-1 < lVar7) goto LAB_140004103;
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar10 = 0xf;
          goto LAB_140003980;
        }
      }
      goto LAB_140004086;
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      uVar10 = 0xd;
LAB_1400038a2:
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar10,
              &WPP_c579c2b1b5af3efbd9446f4704323067_Traceguids);
    }
LAB_1400038b2:
    lVar7 = -0x3ffffff3;
  }
  else {
    if (*(int *)(param_2 + 0x44) != 1) goto LAB_140004103;
    pPVar11 = param_2;
    lVar7 = ControllerPrepareMdlForDmaRx(param_1,param_2,&local_res18,local_res8,&local_res10);
    _Var5 = local_res10;
    uVar10 = (uint)pPVar11;
    if (lVar7 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar10 = 0x10;
LAB_140003b23:
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar10,
                &WPP_c579c2b1b5af3efbd9446f4704323067_Traceguids);
      }
    }
    else {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
         (4 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_Lq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
                  &WPP_c579c2b1b5af3efbd9446f4704323067_Traceguids,local_res8[0],(char)local_res10);
      }
      uVar10 = 0x40016000;
      *(_MDL **)(param_1 + 0x398) = local_res18;
      if ((local_res18 == (_MDL *)0x0) || (_Var5 == 0)) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0 &&
            (1 < (byte)WPP_GLOBAL_Control[0x29])))) {
          uVar10 = 0x12;
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
                  &WPP_c579c2b1b5af3efbd9446f4704323067_Traceguids);
        }
        lVar7 = -0x3ffffff3;
      }
      else {
        param_1[0x359] = (PBC_DEVICE)0x0;
        pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x330);
        ChvP1I2c_ControllerIoGenerateStart(pPVar1,0x40016000);
        uVar9 = (ulong)*(undefined8 *)(param_1 + 0x388);
        (*(code *)pPVar1)(WdfDriverGlobals);
        lVar3 = *(longlong *)(param_1 + 0x398);
        uVar12 = *(undefined8 *)(param_1 + 0x388);
        uVar10 = *(uint *)(lVar3 + 0x2c);
        pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x318);
        lVar4 = *(longlong *)(lVar3 + 0x20);
        ChvP1I2c_ControllerIoGenerateStart(pPVar1,uVar9);
        lVar7 = (*(code *)pPVar1)(WdfDriverGlobals,uVar12,ProgramDmaCallback,0,lVar3,
                                  (ulonglong)uVar10 + lVar4,_Var5);
        uVar10 = (uint)uVar12;
        if (lVar7 < 0) {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar10 = 0x13;
            goto LAB_140003980;
          }
        }
        else {
          param_1[0x359] = (PBC_DEVICE)0x1;
          puVar8[5] = *(undefined8 *)(param_1 + 0x398);
          *(ulong *)(puVar8 + 6) = local_res8[0];
          puVar8[7] = _Var5;
          *puVar8 = param_1;
          puVar8[1] = param_2;
          pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0xce0);
          ChvP1I2c_ControllerIoGenerateStart(pPVar1,uVar10);
          uVar12 = *(undefined8 *)(param_1 + 0x388);
          (*(code *)pPVar1)(WdfDriverGlobals,uVar12,0x10);
          pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0xcc0);
          ChvP1I2c_ControllerIoGenerateStart(pPVar1,(ulong)uVar12);
          uVar12 = *(undefined8 *)(param_1 + 0x388);
          (*(code *)pPVar1)(WdfDriverGlobals,uVar12,SysDmaConfigureChannel,0);
          pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0xcc8);
          ChvP1I2c_ControllerIoGenerateStart(pPVar1,(ulong)uVar12);
          (*(code *)pPVar1)(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x388),
                            SysDmaTransferCompleteRx,0);
          pPVar11 = param_2;
          lVar7 = ControllerPrepareMdlForDmaTxForRx
                            (param_1,param_2,&local_res18,local_res8,&local_res10);
          _Var5 = local_res10;
          uVar10 = (uint)pPVar11;
          if (lVar7 < 0) {
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
               (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              uVar10 = 0x14;
              goto LAB_140003b23;
            }
          }
          else {
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
               (4 < (byte)WPP_GLOBAL_Control[0x29])) {
              uVar10 = 0x15;
              WPP_SF_Lq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
                        &WPP_c579c2b1b5af3efbd9446f4704323067_Traceguids,local_res8[0],
                        (char)local_res10);
            }
            param_1[0x358] = (PBC_DEVICE)0x0;
            *(_MDL **)(param_1 + 0x390) = local_res18;
            if ((local_res18 == (_MDL *)0x0) || (_Var5 == 0)) {
              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0 &&
                  (1 < (byte)WPP_GLOBAL_Control[0x29])))) {
                uVar10 = 0x16;
                goto LAB_1400038a2;
              }
              goto LAB_1400038b2;
            }
            pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x330);
            ChvP1I2c_ControllerIoGenerateStart(pPVar1,uVar10);
            uVar9 = (ulong)*(undefined8 *)(param_1 + 0x380);
            (*(code *)pPVar1)(WdfDriverGlobals);
            lVar3 = *(longlong *)(param_1 + 0x390);
            uVar12 = *(undefined8 *)(param_1 + 0x380);
            uVar10 = *(uint *)(lVar3 + 0x2c);
            pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x318);
            lVar4 = *(longlong *)(lVar3 + 0x20);
            ChvP1I2c_ControllerIoGenerateStart(pPVar1,uVar9);
            lVar7 = (*(code *)pPVar1)(WdfDriverGlobals,uVar12,ProgramDmaCallback,1,lVar3,
                                      (ulonglong)uVar10 + lVar4,_Var5);
            puVar6 = local_res20;
            uVar10 = (uint)uVar12;
            if (lVar7 < 0) {
              if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
                 (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                uVar10 = 0x17;
                goto LAB_140003980;
              }
            }
            else {
              param_1[0x358] = (PBC_DEVICE)0x1;
              local_res20[5] = *(undefined8 *)(param_1 + 0x390);
              *(ulong *)(local_res20 + 6) = local_res8[0];
              local_res20[7] = _Var5;
              *local_res20 = param_1;
              local_res20[1] = param_2;
              pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0xce0);
              ChvP1I2c_ControllerIoGenerateStart(pPVar1,uVar10);
              uVar12 = *(undefined8 *)(param_1 + 0x380);
              (*(code *)pPVar1)(WdfDriverGlobals,uVar12,0x10);
              pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0xcc0);
              ChvP1I2c_ControllerIoGenerateStart(pPVar1,(ulong)uVar12);
              uVar12 = *(undefined8 *)(param_1 + 0x380);
              (*(code *)pPVar1)(WdfDriverGlobals,uVar12,SysDmaConfigureChannel,0);
              pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0xcc8);
              ChvP1I2c_ControllerIoGenerateStart(pPVar1,(ulong)uVar12);
              uVar12 = *(undefined8 *)(param_1 + 0x380);
              (*(code *)pPVar1)(WdfDriverGlobals,uVar12,SysDmaTransferCompleteTx,0);
              uVar9 = (ulong)uVar12;
              LpssApi_DmaPreExecute(param_1);
              uVar12 = *(undefined8 *)(param_1 + 0x388);
              pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x328);
              ChvP1I2c_ControllerIoGenerateStart(pPVar1,uVar9);
              lVar7 = (*(code *)pPVar1)(WdfDriverGlobals,uVar12,puVar8);
              uVar10 = (uint)uVar12;
              if (lVar7 < 0) {
                if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                    ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
                   (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                  uVar10 = 0x18;
                  goto LAB_140003980;
                }
              }
              else {
                uVar12 = *(undefined8 *)(param_1 + 0x380);
                pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x328);
                ChvP1I2c_ControllerIoGenerateStart(pPVar1,uVar10);
                lVar7 = (*(code *)pPVar1)(WdfDriverGlobals,uVar12,puVar6);
                uVar10 = (uint)uVar12;
                if (-1 < lVar7) goto LAB_140004103;
                if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                    ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
                   (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                  uVar10 = 0x19;
                  goto LAB_140003980;
                }
              }
            }
          }
        }
      }
    }
LAB_140004086:
    if (-1 < lVar7) goto LAB_140004103;
  }
  pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x330);
  ChvP1I2c_ControllerIoGenerateStart(pPVar1,uVar10);
  uVar9 = (ulong)*(undefined8 *)(param_1 + 0x380);
  (*(code *)pPVar1)(WdfDriverGlobals);
  pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x330);
  ChvP1I2c_ControllerIoGenerateStart(pPVar1,uVar9);
  (*(code *)pPVar1)(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x388));
  *(undefined2 *)(param_1 + 0x358) = 0;
  ControllerDestroyMdlForDma(*(_MDL **)(param_1 + 0x390));
  ControllerDestroyMdlForDma(*(_MDL **)(param_1 + 0x398));
LAB_140004103:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
            &WPP_c579c2b1b5af3efbd9446f4704323067_Traceguids);
  }
  return lVar7;
}



===== ControllerPrepareMdlForDmaRx @ 140004148 =====

/* long __cdecl ControllerPrepareMdlForDmaRx(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST *
   __ptr64,struct _MDL * __ptr64 * __ptr64,unsigned long * __ptr64,unsigned __int64 * __ptr64) */

long __cdecl
ControllerPrepareMdlForDmaRx
          (PBC_DEVICE *param_1,PBC_REQUEST *param_2,_MDL **param_3,ulong *param_4,__uint64 *param_5)

{
  undefined8 *puVar1;
  longlong lVar2;
  _MDL *p_Var3;
  _MDL *p_Var4;
  _MDL *p_Var5;
  int iVar6;
  ulonglong in_stack_ffffffffffffffc8;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2d,
            &WPP_c579c2b1b5af3efbd9446f4704323067_Traceguids);
  }
  puVar1 = *(undefined8 **)(param_2 + 0x30);
  iVar6 = 0;
  p_Var5 = (_MDL *)0x0;
  p_Var4 = (_MDL *)0x0;
  do {
    if (puVar1 == (undefined8 *)0x0) {
      *param_5 = 0;
      *param_4 = 0;
      for (p_Var4 = p_Var5; p_Var4 != (_MDL *)0x0; p_Var4 = *(_MDL **)p_Var4) {
        *param_5 = *param_5 + (ulonglong)*(uint *)(p_Var4 + 0x28);
        *param_4 = *param_4 + 1;
      }
LAB_14000425c:
      p_Var4 = (_MDL *)0x0;
      if (-1 < iVar6) {
        p_Var4 = p_Var5;
      }
      *param_3 = p_Var4;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
         (4 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x30,
                &WPP_c579c2b1b5af3efbd9446f4704323067_Traceguids);
      }
      return iVar6;
    }
    if ((*(byte *)((longlong)puVar1 + 10) & 5) == 0) {
      lVar2 = MmMapLockedPagesSpecifyCache
                        (puVar1,0,1,0,in_stack_ffffffffffffffc8 & 0xffffffff00000000,0x40000010);
    }
    else {
      lVar2 = puVar1[3];
    }
    if (lVar2 == 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2e,
                &WPP_c579c2b1b5af3efbd9446f4704323067_Traceguids);
      }
      iVar6 = -0x3fffff66;
LAB_14000432e:
      ControllerDestroyMdlForDma(p_Var5);
      goto LAB_14000425c;
    }
    in_stack_ffffffffffffffc8 = 0;
    p_Var3 = (_MDL *)IoAllocateMdl(lVar2,*(undefined4 *)(puVar1 + 5),0,0,0);
    if (p_Var3 == (_MDL *)0x0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2f,
                &WPP_c579c2b1b5af3efbd9446f4704323067_Traceguids);
      }
      iVar6 = -0x3fffffff;
      goto LAB_14000432e;
    }
    MmBuildMdlForNonPagedPool(p_Var3);
    if (p_Var5 == (_MDL *)0x0) {
      p_Var5 = p_Var3;
    }
    else {
      *(_MDL **)p_Var4 = p_Var3;
    }
    puVar1 = (undefined8 *)*puVar1;
    p_Var4 = p_Var3;
  } while( true );
}



===== ControllerPrepareMdlForDmaTx @ 14000433c =====

/* long __cdecl ControllerPrepareMdlForDmaTx(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST *
   __ptr64,struct _MDL * __ptr64 * __ptr64,unsigned long * __ptr64,unsigned __int64 * __ptr64) */

long __cdecl
ControllerPrepareMdlForDmaTx
          (PBC_DEVICE *param_1,PBC_REQUEST *param_2,_MDL **param_3,ulong *param_4,__uint64 *param_5)

{
  longlong *plVar1;
  int iVar2;
  _MDL *p_Var3;
  longlong lVar4;
  _MDL *p_Var5;
  longlong *plVar6;
  undefined8 *puVar7;
  uint uVar8;
  ulonglong uVar9;
  long lVar10;
  _MDL *p_Var11;
  bool bVar12;
  ulonglong in_stack_ffffffffffffffc8;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,
            &WPP_c579c2b1b5af3efbd9446f4704323067_Traceguids);
  }
  plVar1 = *(longlong **)(param_2 + 0x30);
  p_Var11 = (_MDL *)0x0;
  uVar9 = 0;
  lVar10 = -0x3ffffffc;
  plVar6 = plVar1;
  if (*(longlong *)(param_2 + 0x28) != 0) {
    for (; plVar6 != (longlong *)0x0; plVar6 = (longlong *)*plVar6) {
      if (uVar9 < *(uint *)(plVar6 + 5)) {
        if ((*(byte *)((longlong)plVar6 + 10) & 5) == 0) {
          in_stack_ffffffffffffffc8 = in_stack_ffffffffffffffc8 & 0xffffffff00000000;
          lVar4 = MmMapLockedPagesSpecifyCache(plVar6,0,1,0,in_stack_ffffffffffffffc8,0x40000010);
        }
        else {
          lVar4 = plVar6[3];
        }
        if (lVar4 != 0) {
          lVar10 = 0;
          param_1[0x374] = *(PBC_DEVICE *)(lVar4 + uVar9);
        }
        break;
      }
      uVar9 = uVar9 - *(uint *)(plVar6 + 5);
    }
  }
  if (lVar10 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      uVar8 = 0x23;
LAB_140004436:
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar8,
               &WPP_c579c2b1b5af3efbd9446f4704323067_Traceguids,lVar10);
    }
LAB_1400046b5:
    bVar12 = lVar10 < 0;
    if (!bVar12) goto LAB_1400046c3;
  }
  else {
    *(uint *)(param_1 + 0x374) = *(uint *)(param_1 + 0x374) | 0x400;
    lVar10 = -0x3ffffffc;
    uVar9 = *(ulonglong *)(param_2 + 0x28) - 1;
    if (uVar9 < *(ulonglong *)(param_2 + 0x28)) {
      for (puVar7 = *(undefined8 **)(param_2 + 0x30); puVar7 != (undefined8 *)0x0;
          puVar7 = (undefined8 *)*puVar7) {
        if (uVar9 < *(uint *)(puVar7 + 5)) {
          if ((*(byte *)((longlong)puVar7 + 10) & 5) == 0) {
            in_stack_ffffffffffffffc8 = in_stack_ffffffffffffffc8 & 0xffffffff00000000;
            lVar4 = MmMapLockedPagesSpecifyCache(puVar7,0,1,0,in_stack_ffffffffffffffc8,0x40000010);
          }
          else {
            lVar4 = puVar7[3];
          }
          if (lVar4 != 0) {
            lVar10 = 0;
            param_1[0x378] = *(PBC_DEVICE *)(lVar4 + uVar9);
          }
          break;
        }
        uVar9 = uVar9 - *(uint *)(puVar7 + 5);
      }
    }
    if (lVar10 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar8 = 0x24;
        goto LAB_140004436;
      }
      goto LAB_1400046b5;
    }
    if (param_2[0x41] != (PBC_REQUEST)0x0) {
      *(uint *)(param_1 + 0x378) = *(uint *)(param_1 + 0x378) | 0x200;
    }
    p_Var3 = p_Var11;
    if (*(uint *)(plVar1 + 5) < 2) {
LAB_1400045df:
      plVar1 = (longlong *)*plVar1;
      p_Var11 = p_Var3;
joined_r0x0001400045e8:
      plVar6 = plVar1;
      if (plVar6 != (longlong *)0x0) {
        if (*plVar6 == 0) goto code_r0x0001400045f3;
        goto LAB_1400045fc;
      }
      *param_5 = 0;
      *param_4 = 0;
      for (p_Var3 = p_Var11; p_Var3 != (_MDL *)0x0; p_Var3 = *(_MDL **)p_Var3) {
        *param_5 = *param_5 + (ulonglong)*(uint *)(p_Var3 + 0x28);
        *param_4 = *param_4 + 1;
      }
      goto LAB_1400046b5;
    }
    if ((*(byte *)((longlong)plVar1 + 10) & 5) == 0) {
      lVar4 = MmMapLockedPagesSpecifyCache
                        (plVar1,0,1,0,in_stack_ffffffffffffffc8 & 0xffffffff00000000,0x40000010);
    }
    else {
      lVar4 = plVar1[3];
    }
    if (lVar4 == 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar8 = 0x25;
LAB_140004564:
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar8,
                &WPP_c579c2b1b5af3efbd9446f4704323067_Traceguids);
      }
    }
    else {
      in_stack_ffffffffffffffc8 = 0;
      p_Var3 = (_MDL *)IoAllocateMdl(lVar4 + 1,(int)plVar1[5] - (2 - (uint)(*plVar1 != 0)),0,0,0);
      if (p_Var3 != (_MDL *)0x0) {
        MmBuildMdlForNonPagedPool(p_Var3);
        goto LAB_1400045df;
      }
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar8 = 0x26;
        goto LAB_140004564;
      }
    }
LAB_140004574:
    lVar10 = -0x3fffffff;
  }
  ControllerDestroyMdlForDma(p_Var11);
  bVar12 = lVar10 < 0;
LAB_1400046c3:
  p_Var3 = (_MDL *)0x0;
  if (!bVar12) {
    p_Var3 = p_Var11;
  }
  *param_3 = p_Var3;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x29,
            &WPP_c579c2b1b5af3efbd9446f4704323067_Traceguids);
  }
  return lVar10;
code_r0x0001400045f3:
  plVar1 = (longlong *)0x0;
  if (1 < *(uint *)(plVar6 + 5)) {
LAB_1400045fc:
    if ((*(byte *)((longlong)plVar6 + 10) & 5) == 0) {
      lVar4 = MmMapLockedPagesSpecifyCache
                        (plVar6,0,1,0,in_stack_ffffffffffffffc8 & 0xffffffff00000000,0x40000010);
    }
    else {
      lVar4 = plVar6[3];
    }
    if (lVar4 == 0) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) == 0)) ||
         ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_140004574;
      uVar8 = 0x27;
      goto LAB_140004564;
    }
    in_stack_ffffffffffffffc8 = 0;
    iVar2 = (int)plVar6[5];
    if (*plVar6 == 0) {
      iVar2 = (int)plVar6[5] + -1;
    }
    p_Var5 = (_MDL *)IoAllocateMdl(lVar4,iVar2,0,0,0);
    if (p_Var5 == (_MDL *)0x0) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) == 0)) ||
         ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_140004574;
      uVar8 = 0x28;
      goto LAB_140004564;
    }
    MmBuildMdlForNonPagedPool(p_Var5);
    if (p_Var3 == (_MDL *)0x0) {
      p_Var11 = p_Var5;
    }
    else {
      *(_MDL **)p_Var3 = p_Var5;
    }
    plVar1 = (longlong *)*plVar6;
    p_Var3 = p_Var5;
  }
  goto joined_r0x0001400045e8;
}



===== ControllerPrepareMdlForDmaTxForRx @ 14000478c =====

/* long __cdecl ControllerPrepareMdlForDmaTxForRx(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST *
   __ptr64,struct _MDL * __ptr64 * __ptr64,unsigned long * __ptr64,unsigned __int64 * __ptr64) */

long __cdecl
ControllerPrepareMdlForDmaTxForRx
          (PBC_DEVICE *param_1,PBC_REQUEST *param_2,_MDL **param_3,ulong *param_4,__uint64 *param_5)

{
  longlong lVar1;
  _MDL *p_Var2;
  _MDL *p_Var3;
  undefined4 uVar4;
  _MDL *p_Var5;
  ulonglong uVar6;
  _MDL *p_Var7;
  ulonglong uVar8;
  int iVar9;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2a,
            &WPP_c579c2b1b5af3efbd9446f4704323067_Traceguids);
  }
  lVar1 = *(longlong *)(param_2 + 0x28);
  *(undefined4 *)(param_1 + 0x378) = 0x100;
  uVar4 = *(undefined4 *)(param_1 + 0x378);
  iVar9 = 0;
  *(undefined4 *)(param_1 + 0x374) = 0x500;
  if (param_2[0x41] != (PBC_REQUEST)0x0) {
    uVar4 = 0x300;
  }
  *(undefined4 *)(param_1 + 0x378) = uVar4;
  uVar8 = lVar1 - 2;
  p_Var7 = (_MDL *)0x0;
  p_Var5 = (_MDL *)0x0;
  do {
    p_Var3 = p_Var5;
    p_Var2 = p_Var7;
    if (uVar8 == 0) {
      *param_5 = 0;
      *param_4 = 0;
      for (p_Var7 = p_Var2; p_Var7 != (_MDL *)0x0; p_Var7 = *(_MDL **)p_Var7) {
        *param_5 = *param_5 + (ulonglong)*(uint *)(p_Var7 + 0x28);
        *param_4 = *param_4 + 1;
      }
LAB_1400048bd:
      p_Var7 = (_MDL *)0x0;
      if (-1 < iVar9) {
        p_Var7 = p_Var2;
      }
      *param_3 = p_Var7;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
         (4 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2c,
                &WPP_c579c2b1b5af3efbd9446f4704323067_Traceguids);
      }
      return iVar9;
    }
    uVar6 = (ulonglong)(uint)((int)uVar8 * 2);
    if (0x7fd < uVar8) {
      uVar6 = 0xffa;
    }
    uVar8 = uVar8 - (uVar6 >> 1);
    p_Var5 = (_MDL *)IoAllocateMdl(*(undefined8 *)(param_1 + 0x350),uVar6,0,0,0);
    if (p_Var5 == (_MDL *)0x0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
                &WPP_c579c2b1b5af3efbd9446f4704323067_Traceguids);
      }
      iVar9 = -0x3fffffff;
      ControllerDestroyMdlForDma(p_Var2);
      goto LAB_1400048bd;
    }
    MmBuildMdlForNonPagedPool(p_Var5);
    p_Var7 = p_Var5;
    if (p_Var3 != (_MDL *)0x0) {
      *(_MDL **)p_Var3 = p_Var5;
      p_Var7 = p_Var2;
    }
  } while( true );
}



===== ProgramDmaCallback @ 140004970 =====

/* unsigned char __cdecl ProgramDmaCallback(struct WDFDMATRANSACTION__ * __ptr64,struct WDFDEVICE__
   * __ptr64,void * __ptr64,enum _WDF_DMA_DIRECTION,struct _SCATTER_GATHER_LIST * __ptr64) */

uchar __cdecl
ProgramDmaCallback(WDFDMATRANSACTION__ *param_1,WDFDEVICE__ *param_2,void *param_3,
                  _WDF_DMA_DIRECTION param_4,_SCATTER_GATHER_LIST *param_5)

{
  ulonglong uVar1;
  uchar uVar2;
  uint uVar3;
  ulonglong uVar4;
  longlong lVar5;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
            &WPP_c579c2b1b5af3efbd9446f4704323067_Traceguids);
  }
  uVar1 = 0;
  *(undefined8 *)((longlong)param_3 + 0x18) = 0;
  uVar2 = '\x01';
  lVar5 = 0;
  uVar4 = 0;
  if (*(int *)param_5 != 0) {
    do {
      uVar3 = (int)uVar4 + 1;
      lVar5 = lVar5 + (ulonglong)*(uint *)(param_5 + (uVar4 + 1) * 0x18);
      *(longlong *)((longlong)param_3 + 0x18) = lVar5;
      uVar4 = (ulonglong)uVar3;
    } while (uVar3 < *(uint *)param_5);
  }
  if (*(int *)((longlong)param_3 + 0x10) == 1) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_Xq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
                &WPP_c579c2b1b5af3efbd9446f4704323067_Traceguids,lVar5,
                (char)*(undefined4 *)((longlong)param_3 + 0x20));
    }
    LOCK();
    *(undefined4 *)(*(longlong *)((longlong)param_3 + 8) + 0x70) = 0;
    UNLOCK();
  }
  else if (*(int *)((longlong)param_3 + 0x10) == 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_Xq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,
                &WPP_c579c2b1b5af3efbd9446f4704323067_Traceguids,lVar5,
                (char)*(undefined4 *)((longlong)param_3 + 0x20));
    }
    LOCK();
    *(undefined4 *)(*(longlong *)((longlong)param_3 + 8) + 0x74) = 0;
    UNLOCK();
  }
  if ((*(uint *)((longlong)param_3 + 0x20) == 0) || (*(ulonglong *)((longlong)param_3 + 0x18) == 0))
  {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0 && (1 < (byte)WPP_GLOBAL_Control[0x29]))
       )) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,
              &WPP_c579c2b1b5af3efbd9446f4704323067_Traceguids);
    }
    uVar2 = '\0';
  }
  else {
    uVar1 = *(ulonglong *)((longlong)param_3 + 0x18) /
            (ulonglong)*(uint *)((longlong)param_3 + 0x20);
  }
  *(ulonglong *)((longlong)param_3 + 0x18) = uVar1;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,
            &WPP_c579c2b1b5af3efbd9446f4704323067_Traceguids);
  }
  return uVar2;
}



===== WPP_SF_Xq @ 140004b10 =====

void WPP_SF_Xq(undefined8 param_1,uint param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  PBC_DEVICE *pPVar1;
  undefined8 local_res20;
  
  pPVar1 = pfnWppTraceMessage;
  local_res20 = param_4;
  ChvP1I2c_ControllerIoGenerateStart(pfnWppTraceMessage,param_2);
  (*(code *)pPVar1)(param_1,0x2b,param_3,param_2 & 0xffff,&local_res20,8,&param_5,8,0);
  return;
}



===== AcquireMbiSemaphoreLock @ 140004b90 =====

/* long __cdecl AcquireMbiSemaphoreLock(struct PBC_DEVICE * __ptr64) */

long __cdecl AcquireMbiSemaphoreLock(PBC_DEVICE *param_1)

{
  uint uVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  
  if (DAT_1400161d0 != (CMBI *)0x0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
              &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
    }
    AcquireSema_SEMAREG_V1 = CMBI::Read(DAT_1400161d0,'\x04',0x10e);
    LOCK();
    UNLOCK();
    AcquireSema_SEMAREG_V2_Count = 0;
    AcquireSema_MST_BIT =
         HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x70));
    uVar2 = 0;
    do {
      CMBI::Write(DAT_1400161d0,'\x04',0x10e,2);
      LOCK();
      UNLOCK();
      AcquireSema_SEMAREG_V2 = CMBI::Read(DAT_1400161d0,'\x04',0x10e);
      LOCK();
      UNLOCK();
      if (AcquireSema_SEMAREG_V2 - 1 < 2) break;
      AcquireSema_SEMAREG_V2_Count = AcquireSema_SEMAREG_V2_Count + 1;
      KeStallExecutionProcessor(0x32);
      uVar2 = uVar2 + 1;
    } while (uVar2 < 10);
    uVar2 = 0;
    lVar3 = 4;
    do {
      KeStallExecutionProcessor(0x32);
      lVar3 = lVar3 + -1;
    } while (lVar3 != 0);
    uVar1 = CMBI::Read(DAT_1400161d0,'\x04',0x10e);
    if ((uVar1 & 1) == 0) {
      do {
        LOCK();
        UNLOCK();
        lVar3 = 6;
        do {
          lVar4 = lVar3;
          KeStallExecutionProcessor(0x32);
          lVar3 = lVar4 + -1;
        } while (lVar3 != 0);
        if (10000 < uVar2) {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                    &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
          }
          AcquireSema_SEMAREG_V3 = CMBI::Read(DAT_1400161d0,'\x04',0x10e);
          AcquireSema_TimeOut_Count = AcquireSema_TimeOut_Count + 1;
          return -0x3fffffff;
        }
        uVar2 = uVar2 + 1;
        uVar1 = CMBI::Read(DAT_1400161d0,'\x04',0x10e);
      } while ((uVar1 & 1) == 0);
      if (((uVar2 != 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
         (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0 && (1 < (byte)WPP_GLOBAL_Control[0x29])))
         ) {
        WPP_SF_g(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(int)lVar4 + 0xe,
                 &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids,(double)(uVar2 * 300));
      }
    }
  }
  return 0;
}



===== DeInitMbiSemaphoreLock @ 140004d98 =====

/* void __cdecl DeInitMbiSemaphoreLock(void) */

void __cdecl DeInitMbiSemaphoreLock(void)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
            &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
  }
  if (DAT_1400161d0 != (CMBI *)0x0) {
    MbiInterface_Destroy(DAT_1400161d0);
  }
  return;
}



===== InitMbiSemaphoreLock @ 140004de8 =====

/* void __cdecl InitMbiSemaphoreLock(void) */

void __cdecl InitMbiSemaphoreLock(void)

{
  long lVar1;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
  }
  lVar1 = MbiInterface_Create((CMBI **)&DAT_1400161d0);
  if (((lVar1 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
     (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0 && (1 < (byte)WPP_GLOBAL_Control[0x29])))) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
             &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids,lVar1);
  }
  return;
}



===== NonSequenceIoctlWorker @ 140004e70 =====

/* void __cdecl NonSequenceIoctlWorker(struct WDFWORKITEM__ * __ptr64) */

void __cdecl NonSequenceIoctlWorker(WDFWORKITEM__ *param_1)

{
  PBC_DEVICE *pPVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  longlong lVar4;
  ulong in_EDX;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    in_EDX = 0x43;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x43,
            &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
  }
  pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x650);
  ChvP1I2c_ControllerIoGenerateStart(pPVar1,in_EDX);
  puVar3 = (undefined8 *)
           (*(code *)pPVar1)(WdfDriverGlobals,param_1,
                             PTR__WDF_LPSS_WORK_ITEM_CONTEXT_TYPE_INFO_1400160c0);
  uVar2 = *puVar3;
  pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x650);
  ChvP1I2c_ControllerIoGenerateStart(pPVar1,(ulong)param_1);
  lVar4 = (*(code *)pPVar1)(WdfDriverGlobals,uVar2,PTR__WDF_PBC_DEVICE_TYPE_INFO_140016020);
  if (*(char *)(lVar4 + 0x41) == '\0') {
    PbcRequestConfigureForNonSequence
              ((WDFDEVICE__ *)*puVar3,(SPBTARGET__ *)puVar3[1],(SPBREQUEST__ *)puVar3[2],puVar3[3]);
  }
  else {
    PollingIoctlWorker((WDFDEVICE__ *)*puVar3,(SPBTARGET__ *)puVar3[1],(SPBREQUEST__ *)puVar3[2],1);
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x44,
            &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
  }
  return;
}



===== OnCancel @ 140004f90 =====

/* void __cdecl OnCancel(struct WDFREQUEST__ * __ptr64) */

void __cdecl OnCancel(WDFREQUEST__ *param_1)

{
  int iVar1;
  PBC_DEVICE *pPVar2;
  code *pcVar3;
  int iVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  PBC_REQUEST *pPVar8;
  ulong in_EDX;
  ulong uVar9;
  WDFREQUEST__ *pWVar10;
  bool bVar11;
  bool bVar12;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    in_EDX = 0x61;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x61,
            &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
  }
  pcVar3 = DAT_140016500;
  bVar12 = false;
  ChvP1I2c_ControllerIoGenerateStart((PBC_DEVICE *)DAT_140016500,in_EDX);
  pWVar10 = param_1;
  uVar5 = (*pcVar3)(SpbDriverGlobals);
  pPVar2 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x650);
  ChvP1I2c_ControllerIoGenerateStart(pPVar2,(ulong)pWVar10);
  puVar6 = (undefined8 *)
           (*(code *)pPVar2)(WdfDriverGlobals,uVar5,PTR__WDF_PBC_DEVICE_TYPE_INFO_140016020);
  pcVar3 = DAT_1400164f8;
  ChvP1I2c_ControllerIoGenerateStart((PBC_DEVICE *)DAT_1400164f8,(ulong)uVar5);
  pWVar10 = param_1;
  uVar5 = (*pcVar3)(SpbDriverGlobals);
  pPVar2 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x650);
  ChvP1I2c_ControllerIoGenerateStart(pPVar2,(ulong)pWVar10);
  puVar7 = (undefined8 *)
           (*(code *)pPVar2)(WdfDriverGlobals,uVar5,PTR__WDF_PBC_TARGET_TYPE_INFO_140016048);
  pPVar2 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x650);
  ChvP1I2c_ControllerIoGenerateStart(pPVar2,(ulong)uVar5);
  pWVar10 = param_1;
  pPVar8 = (PBC_REQUEST *)
           (*(code *)pPVar2)(WdfDriverGlobals,param_1,PTR__WDF_PBC_REQUEST_TYPE_INFO_140016070);
  pPVar2 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x9e0);
  ChvP1I2c_ControllerIoGenerateStart(pPVar2,(ulong)pWVar10);
  uVar9 = (ulong)puVar6[7];
  (*(code *)pPVar2)(WdfDriverGlobals);
  if (puVar7 == (undefined8 *)puVar6[4]) {
    if (pPVar8 == (PBC_REQUEST *)puVar7[3]) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        uVar9 = 100;
        WPP_SF_qqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),100,
                   &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids,param_1,(char)puVar7,
                   (char)puVar6);
      }
      *(undefined4 *)(pPVar8 + 0x20) = 0xc0000120;
      KeClearEvent(puVar6 + 0x57);
      iVar4 = *(int *)((longlong)puVar6 + 0x24c);
      do {
        LOCK();
        iVar1 = *(int *)((longlong)puVar6 + 0x24c);
        bVar11 = iVar4 == iVar1;
        if (bVar11) {
          *(int *)((longlong)puVar6 + 0x24c) = iVar4;
        }
        else {
          iVar4 = iVar1;
        }
        UNLOCK();
      } while (!bVar11);
      if (iVar4 == 0) {
        uVar9 = 0;
        KeSetEvent(puVar6 + 0x51,0,0);
      }
      else {
        bVar12 = true;
      }
      goto LAB_1400051d3;
    }
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 3))
    goto LAB_1400051d3;
    uVar5 = *puVar7;
    uVar9 = 99;
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 3))
    goto LAB_1400051d3;
    uVar5 = *puVar6;
    uVar9 = 0x62;
  }
  WPP_SF_Xq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar9,
            &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids,uVar5,(char)param_1);
LAB_1400051d3:
  pPVar2 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x9e8);
  ChvP1I2c_ControllerIoGenerateStart(pPVar2,uVar9);
  (*(code *)pPVar2)(WdfDriverGlobals,puVar6[7]);
  if (bVar12) {
    iVar4 = *(int *)((longlong)puVar6 + 0x24c);
    do {
      LOCK();
      iVar1 = *(int *)((longlong)puVar6 + 0x24c);
      bVar12 = iVar4 == iVar1;
      if (bVar12) {
        *(int *)((longlong)puVar6 + 0x24c) = iVar4;
      }
      else {
        iVar4 = iVar1;
      }
      UNLOCK();
    } while (!bVar12);
    if (iVar4 != 0) {
      PbcRequestComplete(pPVar8);
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x65,
            &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
  }
  return;
}



===== OnControllerLock @ 140005270 =====

/* void __cdecl OnControllerLock(struct WDFDEVICE__ * __ptr64,struct SPBTARGET__ * __ptr64,struct
   SPBREQUEST__ * __ptr64) */

void __cdecl OnControllerLock(WDFDEVICE__ *param_1,SPBTARGET__ *param_2,SPBREQUEST__ *param_3)

{
  PBC_DEVICE *pPVar1;
  code *pcVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  ulong uVar5;
  SPBTARGET__ *pSVar6;
  
  pSVar6 = param_2;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    pSVar6 = (SPBTARGET__ *)0x37;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x37,
            &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
  }
  pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x650);
  ChvP1I2c_ControllerIoGenerateStart(pPVar1,(ulong)pSVar6);
  puVar3 = (undefined8 *)
           (*(code *)pPVar1)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140016020);
  pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x650);
  ChvP1I2c_ControllerIoGenerateStart(pPVar1,(ulong)param_1);
  puVar4 = (undefined8 *)
           (*(code *)pPVar1)(WdfDriverGlobals,param_2,PTR__WDF_PBC_TARGET_TYPE_INFO_140016048);
  pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x9e0);
  ChvP1I2c_ControllerIoGenerateStart(pPVar1,(ulong)param_2);
  uVar5 = (ulong)puVar3[7];
  (*(code *)pPVar1)(WdfDriverGlobals);
  puVar3[4] = puVar4;
  *(undefined1 *)(puVar3 + 0x62) = 1;
  pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x9e8);
  ChvP1I2c_ControllerIoGenerateStart(pPVar1,uVar5);
  uVar5 = (ulong)puVar3[7];
  (*(code *)pPVar1)(WdfDriverGlobals);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    uVar5 = 0x38;
    WPP_SF_qLq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x38,
               &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids,*puVar4,
               (char)*(undefined2 *)((longlong)puVar4 + 0xc),(char)*puVar3);
  }
  pcVar2 = DAT_140016518;
  ChvP1I2c_ControllerIoGenerateStart((PBC_DEVICE *)DAT_140016518,uVar5);
  (*pcVar2)(SpbDriverGlobals,param_3,0);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x39,
            &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
  }
  return;
}



===== OnControllerUnlock @ 140005420 =====

/* void __cdecl OnControllerUnlock(struct WDFDEVICE__ * __ptr64,struct SPBTARGET__ * __ptr64,struct
   SPBREQUEST__ * __ptr64) */

void __cdecl OnControllerUnlock(WDFDEVICE__ *param_1,SPBTARGET__ *param_2,SPBREQUEST__ *param_3)

{
  PBC_DEVICE *pPVar1;
  longlong lVar2;
  code *pcVar3;
  PBC_DEVICE *pPVar4;
  undefined8 *puVar5;
  ulong uVar6;
  SPBTARGET__ *pSVar7;
  PBC_REQUEST *pPVar8;
  
  pSVar7 = param_2;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    pSVar7 = (SPBTARGET__ *)0x3a;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3a,
            &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
  }
  pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x650);
  ChvP1I2c_ControllerIoGenerateStart(pPVar1,(ulong)pSVar7);
  pPVar4 = (PBC_DEVICE *)
           (*(code *)pPVar1)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140016020);
  pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x650);
  ChvP1I2c_ControllerIoGenerateStart(pPVar1,(ulong)param_1);
  puVar5 = (undefined8 *)
           (*(code *)pPVar1)(WdfDriverGlobals,param_2,PTR__WDF_PBC_TARGET_TYPE_INFO_140016048);
  pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x9e0);
  ChvP1I2c_ControllerIoGenerateStart(pPVar1,(ulong)param_2);
  uVar6 = (ulong)*(undefined8 *)(pPVar4 + 0x38);
  (*(code *)pPVar1)(WdfDriverGlobals);
  lVar2 = puVar5[3];
  if (lVar2 == 0) {
    ControllerDisableEventsAndInterrupts(pPVar4);
    uVar6 = *(ulong *)(puVar5 + 4);
    LpssApi_ControllerIoGenerateStop(pPVar4,uVar6);
    if (pPVar4[0x41] == (PBC_DEVICE)0x0) {
      pPVar4[0x70] = (PBC_DEVICE)0x0;
    }
  }
  else {
    if (*(char *)(lVar2 + 0x24) == '\0') {
      *(undefined4 *)(lVar2 + 0x20) = 0x10b;
      if (pPVar4[800] != (PBC_DEVICE)0x0) {
        ControllerDmaCompleteTransaction(pPVar4,(PBC_REQUEST *)puVar5[3],3);
      }
      pPVar8 = (PBC_REQUEST *)puVar5[3];
      ControllerCompleteTransfer(pPVar4,pPVar8);
      uVar6 = (ulong)pPVar8;
    }
    puVar5[3] = 0;
  }
  *(undefined8 *)(pPVar4 + 0x20) = 0;
  pPVar4[0x310] = (PBC_DEVICE)0x0;
  pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x9e8);
  ChvP1I2c_ControllerIoGenerateStart(pPVar1,uVar6);
  uVar6 = (ulong)*(undefined8 *)(pPVar4 + 0x38);
  (*(code *)pPVar1)(WdfDriverGlobals);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    uVar6 = 0x3b;
    WPP_SF_qLq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3b,
               &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids,*puVar5,
               (char)*(undefined2 *)((longlong)puVar5 + 0xc),(char)*(undefined8 *)pPVar4);
  }
  pcVar3 = DAT_140016518;
  ChvP1I2c_ControllerIoGenerateStart((PBC_DEVICE *)DAT_140016518,uVar6);
  (*pcVar3)(SpbDriverGlobals,param_3,0);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3c,
            &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
  }
  return;
}



===== OnD0Entry @ 140005630 =====

/* long __cdecl OnD0Entry(struct WDFDEVICE__ * __ptr64,enum _WDF_POWER_DEVICE_STATE) */

long __cdecl OnD0Entry(WDFDEVICE__ *param_1,_WDF_POWER_DEVICE_STATE param_2)

{
  long lVar1;
  PBC_DEVICE *pPVar2;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_2 = 0x1e;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
            &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
  }
  lVar1 = 0;
  pPVar2 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x650);
  ChvP1I2c_ControllerIoGenerateStart(pPVar2,param_2);
  pPVar2 = (PBC_DEVICE *)
           (*(code *)pPVar2)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140016020);
  if (pPVar2[0x41] != (PBC_DEVICE)0x0) {
    D0Entry_HWInitializeDone = 0;
    if (pPVar2[0x70] != (PBC_DEVICE)0x0) goto LAB_1400057da;
    D0Entry_HWInitializeDone = 1;
    lVar1 = AcquireMbiSemaphoreLock(pPVar2);
    if (lVar1 < 0) {
      pPVar2[0x40] = (PBC_DEVICE)0x0;
      D0Entry_HWInitializeDone = D0Entry_HWInitializeDone | 2;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,
                &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
      }
      lVar1 = -0x7fffffef;
      goto LAB_1400057da;
    }
    pPVar2[0x40] = (PBC_DEVICE)0x1;
    D0Entry_HWInitializeDone = D0Entry_HWInitializeDone | 4;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,
              &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
    }
  }
  lVar1 = LpssApi_RestoreContext(pPVar2);
  if (-1 < lVar1) {
    *(undefined8 *)(pPVar2 + 0x20) = 0;
    pPVar2[0x310] = (PBC_DEVICE)0x0;
    pPVar2[0x70] = (PBC_DEVICE)0x0;
    if (pPVar2[0x41] != (PBC_DEVICE)0x0) {
      D0Entry_HWInitializeDone = D0Entry_HWInitializeDone | 8;
      D0Entry_HWInitializeCount = D0Entry_HWInitializeCount + 1;
    }
    ControllerInitialize(pPVar2);
    if (pPVar2[0x70] == (PBC_DEVICE)0x0) {
      lVar1 = -0x3ffffe7e;
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_Lqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,
               &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids,*(undefined4 *)(pPVar2 + 0x6c),
               (char)param_1,(char)lVar1);
  }
LAB_1400057da:
  if ((pPVar2[0x41] != (PBC_DEVICE)0x0) && (pPVar2[0x40] != (PBC_DEVICE)0x0)) {
    lVar1 = ReleaseMbiSemaphoreLock(pPVar2);
    pPVar2[0x40] = (PBC_DEVICE)0x0;
    D0Entry_HWInitializeDone = D0Entry_HWInitializeDone | 0x10;
    if (lVar1 < 0) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return lVar1;
      }
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200) != 0) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x24,
                 &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids,lVar1);
      }
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x25,
            &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
  }
  return lVar1;
}



===== OnD0Exit @ 140005880 =====

/* long __cdecl OnD0Exit(struct WDFDEVICE__ * __ptr64,enum _WDF_POWER_DEVICE_STATE) */

long __cdecl OnD0Exit(WDFDEVICE__ *param_1,_WDF_POWER_DEVICE_STATE param_2)

{
  PBC_DEVICE *pPVar1;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_2 = 0x26;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x26,
            &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
  }
  pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x650);
  ChvP1I2c_ControllerIoGenerateStart(pPVar1,param_2);
  pPVar1 = (PBC_DEVICE *)
           (*(code *)pPVar1)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140016020);
  if (pPVar1[0x41] == (PBC_DEVICE)0x0) {
    ControllerUninitialize(pPVar1);
    pPVar1[0x70] = (PBC_DEVICE)0x0;
  }
  *(undefined8 *)(pPVar1 + 0x20) = 0;
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_Lq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x27,
                &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids,*(undefined4 *)(pPVar1 + 0x6c),
                (char)param_1);
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x28,
              &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
    }
  }
  return 0;
}



===== OnDeviceQueryStop @ 140005990 =====

/* long __cdecl OnDeviceQueryStop(struct WDFDEVICE__ * __ptr64) */

long __cdecl OnDeviceQueryStop(WDFDEVICE__ *param_1)

{
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x29,
              &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2a,
              &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
    }
  }
  return -0x3fffffff;
}



===== OnInterruptDpc @ 140005a10 =====

/* void __cdecl OnInterruptDpc(struct WDFINTERRUPT__ * __ptr64,void * __ptr64) */

void __cdecl OnInterruptDpc(WDFINTERRUPT__ *param_1,void *param_2)

{
  PBC_DEVICE *pPVar1;
  undefined8 *puVar2;
  PBC_REQUEST *pPVar3;
  PBC_DEVICE *pPVar4;
  ulong uVar5;
  uint uVar6;
  ulong uVar7;
  void *pvVar8;
  undefined8 uVar9;
  
  uVar7 = (ulong)param_1;
  pvVar8 = param_2;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    pvVar8 = (void *)0x6a;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6a,
            &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
  }
  pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x650);
  ChvP1I2c_ControllerIoGenerateStart(pPVar1,(ulong)pvVar8);
  pPVar4 = (PBC_DEVICE *)
           (*(code *)pPVar1)(WdfDriverGlobals,param_2,PTR__WDF_PBC_DEVICE_TYPE_INFO_140016020);
  pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x9e0);
  ChvP1I2c_ControllerIoGenerateStart(pPVar1,(ulong)param_2);
  uVar5 = (ulong)*(undefined8 *)(pPVar4 + 0x38);
  (*(code *)pPVar1)(WdfDriverGlobals);
  puVar2 = *(undefined8 **)(pPVar4 + 0x20);
  if (puVar2 == (undefined8 *)0x0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 3))
    goto LAB_140005bd6;
    uVar6 = 0x6b;
    uVar9 = *(undefined8 *)pPVar4;
  }
  else {
    pPVar3 = (PBC_REQUEST *)puVar2[3];
    if (pPVar3 != (PBC_REQUEST *)0x0) {
      pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x480);
      ChvP1I2c_ControllerIoGenerateStart(pPVar1,uVar5);
      (*(code *)pPVar1)(WdfDriverGlobals);
      uVar5 = *(ulong *)(pPVar4 + 0x34);
      *(undefined4 *)(pPVar4 + 0x34) = 0;
      pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x488);
      ChvP1I2c_ControllerIoGenerateStart(pPVar1,uVar7);
      (*(code *)pPVar1)(WdfDriverGlobals);
      if (uVar5 != 0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_Lq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6d,
                    &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids,uVar5,
                    (char)*(undefined8 *)pPVar4);
        }
        ControllerAcknowledgeInterrupts(pPVar4,uVar5);
        ControllerProcessInterrupts(pPVar4,pPVar3,uVar5);
      }
      goto LAB_140005bd6;
    }
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 3))
    goto LAB_140005bd6;
    uVar9 = *puVar2;
    uVar6 = 0x6c;
  }
  WPP_SF_P(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,
           &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids,uVar9);
LAB_140005bd6:
  LOCK();
  *(undefined4 *)(pPVar4 + 0x230) = 0;
  UNLOCK();
  uVar7 = 0;
  KeSetEvent(pPVar4 + 600,0,0);
  pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x9e8);
  ChvP1I2c_ControllerIoGenerateStart(pPVar1,uVar7);
  (*(code *)pPVar1)(WdfDriverGlobals,*(undefined8 *)(pPVar4 + 0x38));
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6e,
            &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
  }
  return;
}



===== OnInterruptIsr @ 140005c60 =====

/* unsigned char __cdecl OnInterruptIsr(struct WDFINTERRUPT__ * __ptr64,unsigned long) */

uchar __cdecl OnInterruptIsr(WDFINTERRUPT__ *param_1,ulong param_2)

{
  PBC_DEVICE *pPVar1;
  char cVar2;
  uint uVar3;
  ulong uVar4;
  undefined8 uVar5;
  PBC_DEVICE *pPVar6;
  WDFINTERRUPT__ *pWVar7;
  uchar uVar8;
  bool bVar9;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_2 = 0x66;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x66,
            &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
  }
  uVar8 = '\0';
  pPVar6 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x4b8);
  ChvP1I2c_ControllerIoGenerateStart(pPVar6,param_2);
  pWVar7 = param_1;
  uVar5 = (*(code *)pPVar6)(WdfDriverGlobals);
  pPVar6 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x650);
  ChvP1I2c_ControllerIoGenerateStart(pPVar6,(ulong)pWVar7);
  pPVar6 = (PBC_DEVICE *)
           (*(code *)pPVar6)(WdfDriverGlobals,uVar5,PTR__WDF_PBC_DEVICE_TYPE_INFO_140016020);
  uVar3 = *(uint *)(pPVar6 + 0x30);
  do {
    LOCK();
    uVar4 = *(ulong *)(pPVar6 + 0x30);
    bVar9 = uVar3 == uVar4;
    if (bVar9) {
      *(uint *)(pPVar6 + 0x30) = uVar3;
    }
    else {
      uVar3 = uVar4;
    }
    UNLOCK();
  } while (!bVar9);
  uVar4 = ControllerGetInterruptStatus(pPVar6,uVar3);
  if (uVar4 != 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (uVar3 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar3 & 8) != 0)) &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      uVar3 = 0x67;
      WPP_SF_Lq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x67,
                &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids,uVar4,(char)*(undefined8 *)pPVar6);
    }
    *(uint *)(pPVar6 + 0x34) = *(uint *)(pPVar6 + 0x34) | uVar4;
    uVar8 = '\x01';
    ControllerDisableInterrupts(pPVar6);
    pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x470);
    ChvP1I2c_ControllerIoGenerateStart(pPVar1,uVar3);
    cVar2 = (*(code *)pPVar1)(WdfDriverGlobals,param_1);
    if (cVar2 == '\0') {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return '\x01';
      }
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
      {
        WPP_SF_Lq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x68,
                  &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids,uVar4,(char)*(undefined8 *)pPVar6
                 );
      }
    }
    else {
      LOCK();
      *(uint *)(pPVar6 + 0x230) = *(uint *)(pPVar6 + 0x230) | 1;
      UNLOCK();
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x69,
            &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
  }
  return uVar8;
}



===== OnMonitorPowerSettingCallback @ 140005e30 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl OnMonitorPowerSettingCallback(struct _GUID const * __ptr64,void * __ptr64,unsigned
   long,void * __ptr64) */

long __cdecl OnMonitorPowerSettingCallback(_GUID *param_1,void *param_2,ulong param_3,void *param_4)

{
  PBC_DEVICE *pPVar1;
  int iVar2;
  ulong uVar3;
  undefined1 auStack_68 [32];
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  int local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_68;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x30,
            &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
  }
  iVar2 = 0;
  if (param_4 == (void *)0x0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x31,
              &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
    }
    iVar2 = -0x3ffffff3;
  }
  else if ((*(longlong *)param_1 == 0x4526451002731015) &&
          (*(longlong *)(param_1 + 8) == -0x15e542815e1a1967)) {
    uVar3 = 0;
    memset(&local_48,0,0x24);
    local_48 = 0x24;
    local_30 = 2;
    local_28 = 2;
    local_3c = (-(uint)(*(int *)param_2 != 0) & 0x79e) + 0x32;
    local_44 = 1;
    local_2c = 2;
    local_40 = 4;
    local_38 = 1;
    local_34 = 1;
    pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x170);
    ChvP1I2c_ControllerIoGenerateStart(pPVar1,uVar3);
    iVar2 = (*(code *)pPVar1)(WdfDriverGlobals,param_4,&local_48);
    if (iVar2 < 0) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return iVar2;
      }
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
      {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x32,
                 &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids,iVar2);
      }
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x33,
            &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
  }
  return iVar2;
}



===== OnPrepareHardware @ 140006000 =====

/* long __cdecl OnPrepareHardware(struct WDFDEVICE__ * __ptr64,struct WDFCMRESLIST__ *
   __ptr64,struct WDFCMRESLIST__ * __ptr64) */

long __cdecl OnPrepareHardware(WDFDEVICE__ *param_1,WDFCMRESLIST__ *param_2,WDFCMRESLIST__ *param_3)

{
  _CM_PARTIAL_RESOURCE_DESCRIPTOR _Var1;
  PBC_DEVICE *pPVar2;
  bool bVar3;
  uint uVar4;
  long lVar5;
  PBC_DEVICE *pPVar6;
  _CM_PARTIAL_RESOURCE_DESCRIPTOR *p_Var7;
  _CM_PARTIAL_RESOURCE_DESCRIPTOR *p_Var8;
  longlong lVar9;
  ulong uVar10;
  WDFCMRESLIST__ *pWVar11;
  WDFDEVICE__ *pWVar12;
  _CM_PARTIAL_RESOURCE_DESCRIPTOR *p_Var13;
  undefined8 uVar14;
  uint uVar15;
  ulong uVar16;
  
  pWVar11 = param_2;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    pWVar11 = (WDFCMRESLIST__ *)0x13;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
            &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
  }
  pPVar6 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x650);
  ChvP1I2c_ControllerIoGenerateStart(pPVar6,(ulong)pWVar11);
  pWVar12 = param_1;
  pPVar6 = (PBC_DEVICE *)
           (*(code *)pPVar6)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140016020);
  uVar16 = 0;
  bVar3 = false;
  if ((param_2 == (WDFCMRESLIST__ *)0x0) || (param_3 == (WDFCMRESLIST__ *)0x0)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0 && (1 < (byte)WPP_GLOBAL_Control[0x29]))))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
              &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
    }
    lVar5 = -0x3ffffe7e;
LAB_14000646e:
    if (-1 < lVar5) goto LAB_14000648d;
  }
  else {
    pPVar2 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x980);
    ChvP1I2c_ControllerIoGenerateStart(pPVar2,(ulong)pWVar12);
    pWVar11 = param_3;
    uVar4 = (*(code *)pPVar2)(WdfDriverGlobals);
    uVar10 = (ulong)pWVar11;
    if (uVar4 == 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        uVar10 = 0x15;
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
                &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
      }
      pPVar2 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x2b8);
      ChvP1I2c_ControllerIoGenerateStart(pPVar2,uVar10);
      (*(code *)pPVar2)(WdfDriverGlobals,param_1,2);
LAB_14000612b:
      lVar5 = -0x3ffffe7e;
    }
    else {
      *(undefined8 *)(pPVar6 + 8) = 0;
      *(undefined4 *)(pPVar6 + 0x10) = 0;
      pPVar6[0x70] = (PBC_DEVICE)0x0;
      KeInitializeEvent(pPVar6 + 600,0,0);
      KeInitializeEvent(pPVar6 + 0x270,0,0);
      KeInitializeEvent(pPVar6 + 0x288,0,0);
      KeInitializeEvent(pPVar6 + 0x2a0,0,0);
      uVar14 = 0;
      KeInitializeEvent(pPVar6 + 0x2b8,0,0);
      DmaInitializeSettings(pPVar6);
      LpssApi_InitializeSettings(pPVar6);
      uVar15 = 0;
      if (uVar4 != 0) {
        do {
          pPVar2 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x988);
          ChvP1I2c_ControllerIoGenerateStart(pPVar2,(ulong)uVar14);
          p_Var13 = (_CM_PARTIAL_RESOURCE_DESCRIPTOR *)param_3;
          p_Var7 = (_CM_PARTIAL_RESOURCE_DESCRIPTOR *)
                   (*(code *)pPVar2)(WdfDriverGlobals,param_3,uVar15);
          _Var1 = *p_Var7;
          if (_Var1 == (_CM_PARTIAL_RESOURCE_DESCRIPTOR)0x3) {
            pPVar2 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x988);
            ChvP1I2c_ControllerIoGenerateStart(pPVar2,(ulong)p_Var13);
            p_Var8 = (_CM_PARTIAL_RESOURCE_DESCRIPTOR *)
                     (*(code *)pPVar2)(WdfDriverGlobals,param_2,uVar15);
            p_Var13 = p_Var7;
            lVar5 = LpssApi_AssignMemoryResource(pPVar6,p_Var7,p_Var8,uVar16);
            if (lVar5 < 0) goto LAB_140006472;
            if (uVar16 == 0) {
              p_Var13 = (_CM_PARTIAL_RESOURCE_DESCRIPTOR *)(ulonglong)*(uint *)(p_Var7 + 0xc);
              lVar9 = MmMapIoSpaceEx(*(undefined8 *)(p_Var7 + 4),p_Var13,0x204);
              *(longlong *)(pPVar6 + 8) = lVar9;
              *(undefined4 *)(pPVar6 + 0x10) = *(undefined4 *)(p_Var7 + 0xc);
              if (lVar9 == 0) {
                if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                    ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                   (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                  WPP_SF_xd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
                            &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids,
                            *(undefined8 *)(p_Var7 + 4),(char)*(undefined4 *)(p_Var7 + 0xc));
                }
                *(undefined4 *)(pPVar6 + 0x10) = 0;
                lVar5 = -0x3fffff66;
                goto LAB_140006472;
              }
              *(undefined8 *)(pPVar6 + 0x18) = *(undefined8 *)(p_Var7 + 4);
              if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                 (3 < (byte)WPP_GLOBAL_Control[0x29])) {
                p_Var13 = (_CM_PARTIAL_RESOURCE_DESCRIPTOR *)0x0;
                WPP_SF_Xq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
                          &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids,
                          *(undefined8 *)(p_Var7 + 4),(char)lVar9);
              }
            }
            uVar16 = uVar16 + 1;
          }
          else if (_Var1 == (_CM_PARTIAL_RESOURCE_DESCRIPTOR)0x2) {
            if (bVar3) {
              if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                 (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
                        &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
              }
              goto LAB_14000612b;
            }
            bVar3 = true;
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
               (3 < (byte)WPP_GLOBAL_Control[0x29])) {
              p_Var13 = (_CM_PARTIAL_RESOURCE_DESCRIPTOR *)0x0;
              WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
                        &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids,*(undefined4 *)(p_Var7 + 8)
                        ,(char)*(undefined4 *)(p_Var7 + 8));
            }
          }
          else if (_Var1 == (_CM_PARTIAL_RESOURCE_DESCRIPTOR)0x4) {
            *(int *)(pPVar6 + 0x318) = *(int *)(pPVar6 + 0x318) + 1;
            if (*(int *)(pPVar6 + 0x318) == 1) {
              *(_CM_PARTIAL_RESOURCE_DESCRIPTOR **)(pPVar6 + 0x340) = p_Var7;
            }
            else {
              if (*(int *)(pPVar6 + 0x318) != 2) {
                if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                    ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                   (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                  WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
                          &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
                }
                *(undefined4 *)(pPVar6 + 0x318) = 0;
                goto LAB_14000612b;
              }
              *(_CM_PARTIAL_RESOURCE_DESCRIPTOR **)(pPVar6 + 0x348) = p_Var7;
            }
          }
          uVar14 = CONCAT71((int7)((ulonglong)p_Var13 >> 8),*p_Var7);
          lVar5 = LpssApi_ValidateResource(pPVar6,(uchar)*p_Var7);
          if (lVar5 < 0) goto LAB_140006472;
          uVar15 = uVar15 + 1;
        } while (uVar15 < uVar4);
      }
      lVar5 = LpssApi_ValidateAllResources(pPVar6);
      if (-1 < lVar5) {
        lVar5 = DmaInitialize(pPVar6);
        goto LAB_14000646e;
      }
    }
  }
LAB_140006472:
  if (*(longlong *)(pPVar6 + 8) != 0) {
    MmUnmapIoSpace(*(longlong *)(pPVar6 + 8),*(undefined4 *)(pPVar6 + 0x10));
    *(undefined8 *)(pPVar6 + 8) = 0;
    *(undefined4 *)(pPVar6 + 0x10) = 0;
  }
LAB_14000648d:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
            &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
  }
  return lVar5;
}



===== OnRead @ 1400064f0 =====

/* void __cdecl OnRead(struct WDFDEVICE__ * __ptr64,struct SPBTARGET__ * __ptr64,struct SPBREQUEST__
   * __ptr64,unsigned __int64) */

void __cdecl
OnRead(WDFDEVICE__ *param_1,SPBTARGET__ *param_2,SPBREQUEST__ *param_3,__uint64 param_4)

{
  uint uVar1;
  longlong lVar2;
  undefined8 *puVar3;
  PBC_DEVICE *pPVar4;
  ulong uVar5;
  SPBTARGET__ *pSVar6;
  WDFDEVICE__ *pWVar7;
  undefined8 uVar8;
  
  pPVar4 = (PBC_DEVICE *)WPP_GLOBAL_Control;
  pSVar6 = param_2;
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      pSVar6 = (SPBTARGET__ *)0x3d;
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3d,
              &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
    }
    pPVar4 = (PBC_DEVICE *)WPP_GLOBAL_Control;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      pPVar4 = *(PBC_DEVICE **)(WPP_GLOBAL_Control + 0x18);
      pSVar6 = (SPBTARGET__ *)0x3e;
      WPP_SF_qPqq(pPVar4,0x3e,&WPP_2ad8463ac409321276b270cb100b84a9_Traceguids,param_3,(char)param_4
                  ,(char)param_2,(char)param_1);
    }
  }
  uVar5 = (ulong)pSVar6;
  ChvP1I2c_ControllerIoGenerateStart(pPVar4,uVar5);
  pPVar4 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x650);
  ChvP1I2c_ControllerIoGenerateStart(pPVar4,uVar5);
  pWVar7 = param_1;
  lVar2 = (*(code *)pPVar4)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140016020);
  pPVar4 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x9e0);
  ChvP1I2c_ControllerIoGenerateStart(pPVar4,(ulong)pWVar7);
  (*(code *)pPVar4)(WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x38));
  uVar1 = *(uint *)(lVar2 + 0x304);
  *(uint *)(lVar2 + 0x304) = (uVar1 + 1) % 3;
  uVar8 = *(undefined8 *)(lVar2 + 0x2e8 + (ulonglong)uVar1 * 8);
  pPVar4 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x650);
  ChvP1I2c_ControllerIoGenerateStart(pPVar4,(uVar1 + 1) / 3);
  puVar3 = (undefined8 *)
           (*(code *)pPVar4)(WdfDriverGlobals,uVar8,
                             PTR__WDF_LPSS_WORK_ITEM_CONTEXT_TYPE_INFO_1400160c0);
  puVar3[1] = param_2;
  puVar3[2] = param_3;
  *puVar3 = param_1;
  puVar3[3] = param_4;
  *(uint *)((longlong)puVar3 + 0x24) = uVar1;
  pPVar4 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0xbe0);
  ChvP1I2c_ControllerIoGenerateStart(pPVar4,(ulong)uVar8);
  uVar5 = (ulong)*(undefined8 *)(lVar2 + 0x2e8 + (ulonglong)uVar1 * 8);
  (*(code *)pPVar4)(WdfDriverGlobals);
  pPVar4 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x9e8);
  ChvP1I2c_ControllerIoGenerateStart(pPVar4,uVar5);
  (*(code *)pPVar4)(WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x38));
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3f,
            &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
  }
  return;
}



===== OnReleaseHardware @ 140006700 =====

/* long __cdecl OnReleaseHardware(struct WDFDEVICE__ * __ptr64,struct WDFCMRESLIST__ * __ptr64) */

long __cdecl OnReleaseHardware(WDFDEVICE__ *param_1,WDFCMRESLIST__ *param_2)

{
  long lVar1;
  PBC_DEVICE *pPVar2;
  ulong uVar3;
  
  uVar3 = (ulong)param_2;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    uVar3 = 0x1c;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
            &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
  }
  pPVar2 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x650);
  ChvP1I2c_ControllerIoGenerateStart(pPVar2,uVar3);
  pPVar2 = (PBC_DEVICE *)
           (*(code *)pPVar2)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140016020);
  lVar1 = 0;
  if (*(int *)(pPVar2 + 0x318) != 0) {
    lVar1 = DmaUninitialize(pPVar2);
  }
  LpssApi_ReleaseResources(pPVar2);
  if (*(longlong *)(pPVar2 + 8) != 0) {
    ControllerDisableInterrupts(pPVar2);
    MmUnmapIoSpace(*(undefined8 *)(pPVar2 + 8),*(undefined4 *)(pPVar2 + 0x10));
    *(undefined8 *)(pPVar2 + 8) = 0;
    *(undefined4 *)(pPVar2 + 0x10) = 0;
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
            &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
  }
  return lVar1;
}



===== OnSelfManagedIoCleanup @ 140006800 =====

/* void __cdecl OnSelfManagedIoCleanup(struct WDFDEVICE__ * __ptr64) */

void __cdecl OnSelfManagedIoCleanup(WDFDEVICE__ *param_1)

{
  PBC_DEVICE *pPVar1;
  longlong lVar2;
  ulong in_EDX;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    in_EDX = 0x2e;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2e,
            &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
  }
  pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x650);
  ChvP1I2c_ControllerIoGenerateStart(pPVar1,in_EDX);
  lVar2 = (*(code *)pPVar1)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140016020);
  if (*(longlong *)(lVar2 + 0x50) != 0) {
    PoUnregisterPowerSettingCallback();
    *(undefined8 *)(lVar2 + 0x50) = 0;
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2f,
            &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
  }
  return;
}



===== OnSelfManagedIoInit @ 1400068d0 =====

/* long __cdecl OnSelfManagedIoInit(struct WDFDEVICE__ * __ptr64) */

long __cdecl OnSelfManagedIoInit(WDFDEVICE__ *param_1)

{
  PBC_DEVICE *pPVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  ulong in_EDX;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    in_EDX = 0x2b;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
            &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
  }
  pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x650);
  ChvP1I2c_ControllerIoGenerateStart(pPVar1,in_EDX);
  puVar3 = (undefined8 *)
           (*(code *)pPVar1)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140016020);
  uVar4 = *puVar3;
  pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0xf8);
  ChvP1I2c_ControllerIoGenerateStart(pPVar1,(ulong)param_1);
  uVar4 = (*(code *)pPVar1)(WdfDriverGlobals,uVar4);
  iVar2 = PoRegisterPowerSettingCallback
                    (uVar4,&GUID_MONITOR_POWER_ON,OnMonitorPowerSettingCallback,*puVar3,puVar3 + 10)
  ;
  if (iVar2 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar2;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2c,
               &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids,iVar2);
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2d,
            &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
  }
  return iVar2;
}



===== OnSequence @ 140006a20 =====

/* void __cdecl OnSequence(struct WDFDEVICE__ * __ptr64,struct SPBTARGET__ * __ptr64,struct
   SPBREQUEST__ * __ptr64,unsigned long) */

void __cdecl
OnSequence(WDFDEVICE__ *param_1,SPBTARGET__ *param_2,SPBREQUEST__ *param_3,ulong param_4)

{
  uint uVar1;
  longlong lVar2;
  undefined8 *puVar3;
  PBC_DEVICE *pPVar4;
  ulong uVar5;
  SPBTARGET__ *pSVar6;
  WDFDEVICE__ *pWVar7;
  undefined8 uVar8;
  
  pPVar4 = (PBC_DEVICE *)WPP_GLOBAL_Control;
  pSVar6 = param_2;
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      pSVar6 = (SPBTARGET__ *)0x47;
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x47,
              &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
    }
    pPVar4 = (PBC_DEVICE *)WPP_GLOBAL_Control;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      pPVar4 = *(PBC_DEVICE **)(WPP_GLOBAL_Control + 0x18);
      pSVar6 = (SPBTARGET__ *)0x48;
      WPP_SF_Xq(pPVar4,0x48,&WPP_2ad8463ac409321276b270cb100b84a9_Traceguids,param_3,(char)param_1);
    }
  }
  uVar5 = (ulong)pSVar6;
  ChvP1I2c_ControllerIoGenerateStart(pPVar4,uVar5);
  pPVar4 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x650);
  ChvP1I2c_ControllerIoGenerateStart(pPVar4,uVar5);
  pWVar7 = param_1;
  lVar2 = (*(code *)pPVar4)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140016020);
  pPVar4 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x9e0);
  ChvP1I2c_ControllerIoGenerateStart(pPVar4,(ulong)pWVar7);
  (*(code *)pPVar4)(WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x38));
  uVar1 = *(uint *)(lVar2 + 0x300);
  *(uint *)(lVar2 + 0x300) = (uVar1 + 1) % 3;
  uVar8 = *(undefined8 *)(lVar2 + 0x2d0 + (ulonglong)uVar1 * 8);
  pPVar4 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x650);
  ChvP1I2c_ControllerIoGenerateStart(pPVar4,(uVar1 + 1) / 3);
  puVar3 = (undefined8 *)
           (*(code *)pPVar4)(WdfDriverGlobals,uVar8,
                             PTR__WDF_LPSS_WORK_ITEM_CONTEXT_TYPE_INFO_1400160c0);
  puVar3[1] = param_2;
  *(ulong *)(puVar3 + 4) = param_4;
  *puVar3 = param_1;
  puVar3[2] = param_3;
  *(uint *)((longlong)puVar3 + 0x24) = uVar1;
  pPVar4 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x9e8);
  ChvP1I2c_ControllerIoGenerateStart(pPVar4,(ulong)uVar8);
  uVar5 = (ulong)*(undefined8 *)(lVar2 + 0x38);
  (*(code *)pPVar4)(WdfDriverGlobals);
  pPVar4 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0xbe0);
  ChvP1I2c_ControllerIoGenerateStart(pPVar4,uVar5);
  (*(code *)pPVar4)(WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x2d0 + (ulonglong)uVar1 * 8));
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x49,
            &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
  }
  return;
}



===== OnTargetConnect @ 140006c10 =====

/* long __cdecl OnTargetConnect(struct WDFDEVICE__ * __ptr64,struct SPBTARGET__ * __ptr64) */

long __cdecl OnTargetConnect(WDFDEVICE__ *param_1,SPBTARGET__ *param_2)

{
  PBC_DEVICE *pPVar1;
  code *pcVar2;
  long lVar3;
  PBC_DEVICE *pPVar4;
  undefined8 *puVar5;
  SPBTARGET__ *pSVar6;
  undefined8 local_38;
  undefined8 local_30;
  void *local_28;
  
  pSVar6 = param_2;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    pSVar6 = (SPBTARGET__ *)0x34;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x34,
            &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
  }
  pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x650);
  ChvP1I2c_ControllerIoGenerateStart(pPVar1,(ulong)pSVar6);
  pPVar4 = (PBC_DEVICE *)
           (*(code *)pPVar1)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140016020);
  pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x650);
  ChvP1I2c_ControllerIoGenerateStart(pPVar1,(ulong)param_1);
  pSVar6 = param_2;
  puVar5 = (undefined8 *)
           (*(code *)pPVar1)(WdfDriverGlobals,param_2,PTR__WDF_PBC_TARGET_TYPE_INFO_140016048);
  pcVar2 = DAT_1400164e8;
  local_30 = 0;
  local_28 = (void *)0x0;
  local_38 = 0x18;
  ChvP1I2c_ControllerIoGenerateStart((PBC_DEVICE *)DAT_1400164e8,(ulong)pSVar6);
  (*pcVar2)(SpbDriverGlobals,param_2,&local_38);
  lVar3 = PbcTargetGetSettings(pPVar4,local_28,(PBC_TARGET_SETTINGS *)(puVar5 + 1));
  if (-1 < lVar3) {
    puVar5[3] = 0;
    *puVar5 = param_2;
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return lVar3;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_qLq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x35,
                 &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids,param_2,
                 (char)*(undefined2 *)((longlong)puVar5 + 0xc),(char)*(undefined8 *)pPVar4);
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x36,
            &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
  }
  return lVar3;
}



===== OnWrite @ 140006db0 =====

/* void __cdecl OnWrite(struct WDFDEVICE__ * __ptr64,struct SPBTARGET__ * __ptr64,struct
   SPBREQUEST__ * __ptr64,unsigned __int64) */

void __cdecl
OnWrite(WDFDEVICE__ *param_1,SPBTARGET__ *param_2,SPBREQUEST__ *param_3,__uint64 param_4)

{
  uint uVar1;
  longlong lVar2;
  undefined8 *puVar3;
  PBC_DEVICE *pPVar4;
  ulong uVar5;
  SPBTARGET__ *pSVar6;
  WDFDEVICE__ *pWVar7;
  undefined8 uVar8;
  
  pPVar4 = (PBC_DEVICE *)WPP_GLOBAL_Control;
  pSVar6 = param_2;
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      pSVar6 = (SPBTARGET__ *)0x40;
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x40,
              &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
    }
    pPVar4 = (PBC_DEVICE *)WPP_GLOBAL_Control;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      pPVar4 = *(PBC_DEVICE **)(WPP_GLOBAL_Control + 0x18);
      pSVar6 = (SPBTARGET__ *)0x41;
      WPP_SF_qPqq(pPVar4,0x41,&WPP_2ad8463ac409321276b270cb100b84a9_Traceguids,param_3,(char)param_4
                  ,(char)param_2,(char)param_1);
    }
  }
  uVar5 = (ulong)pSVar6;
  ChvP1I2c_ControllerIoGenerateStart(pPVar4,uVar5);
  pPVar4 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x650);
  ChvP1I2c_ControllerIoGenerateStart(pPVar4,uVar5);
  pWVar7 = param_1;
  lVar2 = (*(code *)pPVar4)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140016020);
  pPVar4 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x9e0);
  ChvP1I2c_ControllerIoGenerateStart(pPVar4,(ulong)pWVar7);
  (*(code *)pPVar4)(WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x38));
  uVar1 = *(uint *)(lVar2 + 0x304);
  *(uint *)(lVar2 + 0x304) = (uVar1 + 1) % 3;
  uVar8 = *(undefined8 *)(lVar2 + 0x2e8 + (ulonglong)uVar1 * 8);
  pPVar4 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x650);
  ChvP1I2c_ControllerIoGenerateStart(pPVar4,(uVar1 + 1) / 3);
  puVar3 = (undefined8 *)
           (*(code *)pPVar4)(WdfDriverGlobals,uVar8,
                             PTR__WDF_LPSS_WORK_ITEM_CONTEXT_TYPE_INFO_1400160c0);
  puVar3[1] = param_2;
  puVar3[2] = param_3;
  *puVar3 = param_1;
  puVar3[3] = param_4;
  *(uint *)((longlong)puVar3 + 0x24) = uVar1;
  pPVar4 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0xbe0);
  ChvP1I2c_ControllerIoGenerateStart(pPVar4,(ulong)uVar8);
  uVar5 = (ulong)*(undefined8 *)(lVar2 + 0x2e8 + (ulonglong)uVar1 * 8);
  (*(code *)pPVar4)(WdfDriverGlobals);
  pPVar4 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x9e8);
  ChvP1I2c_ControllerIoGenerateStart(pPVar4,uVar5);
  (*(code *)pPVar4)(WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x38));
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x42,
            &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
  }
  return;
}



===== PbcRequestComplete @ 140006fc0 =====

/* void __cdecl PbcRequestComplete(struct PBC_REQUEST * __ptr64) */

void __cdecl PbcRequestComplete(PBC_REQUEST *param_1)

{
  PBC_DEVICE *pPVar1;
  code *pcVar2;
  ulong in_EDX;
  undefined8 uVar3;
  
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      in_EDX = 0x8f;
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x8f,
              &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      in_EDX = 0x90;
      WPP_SF_qLq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x90,
                 &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids,*(undefined8 *)param_1,
                 (char)*(undefined4 *)(param_1 + 0x20),(char)*(undefined8 *)(param_1 + 0x18));
    }
  }
  pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x898);
  ChvP1I2c_ControllerIoGenerateStart(pPVar1,in_EDX);
  uVar3 = *(undefined8 *)param_1;
  (*(code *)pPVar1)(WdfDriverGlobals,uVar3,*(undefined8 *)(param_1 + 0x18));
  pcVar2 = DAT_140016518;
  ChvP1I2c_ControllerIoGenerateStart((PBC_DEVICE *)DAT_140016518,(ulong)uVar3);
  (*pcVar2)(SpbDriverGlobals,*(undefined8 *)param_1,*(undefined4 *)(param_1 + 0x20));
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x95,
            &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
  }
  return;
}



===== PbcRequestConfigureArrayInitialize @ 1400070d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl PbcRequestConfigureArrayInitialize(struct PBC_REQUEST * __ptr64) */

long __cdecl PbcRequestConfigureArrayInitialize(PBC_REQUEST *param_1)

{
  code *pcVar1;
  undefined8 uVar2;
  undefined8 in_RDX;
  uint uVar3;
  ulonglong uVar4;
  longlong lVar5;
  undefined1 auStackY_88 [32];
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    in_RDX = 0x81;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x81,
            &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
  }
  uVar4 = 0;
  if (*(int *)(param_1 + 0xc) != 0) {
    do {
      pcVar1 = DAT_140016510;
      local_28 = 0;
      local_20 = 0;
      local_30 = 0x18;
      ChvP1I2c_ControllerIoGenerateStart((PBC_DEVICE *)DAT_140016510,(ulong)in_RDX);
      in_RDX = *(undefined8 *)param_1;
      (*pcVar1)(SpbDriverGlobals,in_RDX,uVar4,&local_30);
      if ((bRam000000000000000a & 5) == 0) {
        in_RDX = 0;
        uVar2 = MmMapLockedPagesSpecifyCache(0,0,1);
      }
      else {
        uVar2 = uRam0000000000000018;
      }
      lVar5 = uVar4 * 0x20;
      *(undefined8 *)(param_1 + (uVar4 + 5) * 0x20) = uVar2;
      *(undefined8 *)(param_1 + lVar5 + 0x90) = local_28;
      *(undefined8 *)(param_1 + lVar5 + 0x98) = 0;
      *(undefined4 *)(param_1 + lVar5 + 0xa8) = local_30._4_4_;
      *(undefined4 *)(param_1 + lVar5 + 0xac) = (undefined4)local_20;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        in_RDX = 0x82;
        WPP_SF_DqqDDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x82,
                      &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids,(int)uVar4,(char)uVar2,0,
                      (char)*(undefined4 *)(param_1 + lVar5 + 0x90),
                      (char)((ulonglong)local_30 >> 0x20),(char)local_20);
      }
      uVar3 = (int)uVar4 + 1;
      uVar4 = (ulonglong)uVar3;
    } while (uVar3 < *(uint *)(param_1 + 0xc));
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x83,
            &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
  }
  return 0;
}



===== PbcRequestConfigureForIndex @ 1400072b8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl PbcRequestConfigureForIndex(struct PBC_REQUEST * __ptr64,unsigned long) */

long __cdecl PbcRequestConfigureForIndex(PBC_REQUEST *param_1,ulong param_2)

{
  PBC_DEVICE *pPVar1;
  code *pcVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  ulong uVar6;
  ulong uVar7;
  char *pcVar8;
  long lVar9;
  undefined1 auStackY_98 [32];
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_98;
  uVar6 = param_2;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    uVar6 = 0x7d;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x7d,
            &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
  }
  pcVar2 = DAT_140016510;
  lVar9 = 0;
  local_48 = 0;
  local_40 = 0;
  local_50 = 0x18;
  ChvP1I2c_ControllerIoGenerateStart((PBC_DEVICE *)DAT_140016510,uVar6);
  uVar4 = *(undefined8 *)param_1;
  (*pcVar2)(SpbDriverGlobals,uVar4,param_2,&local_50);
  uVar6 = (ulong)uVar4;
  if ((bRam000000000000000a & 5) == 0) {
    uVar6 = 0;
    lVar3 = MmMapLockedPagesSpecifyCache(0,0,1);
  }
  else {
    lVar3 = lRam0000000000000018;
  }
  *(longlong *)(param_1 + 0x68) = lVar3;
  if (lVar3 == 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x7e,
              &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
    }
    lVar9 = -0x3fffffff;
  }
  else {
    *(undefined8 *)(param_1 + 0x28) = local_48;
    *(undefined4 *)(param_1 + 0x44) = local_50._4_4_;
    *(undefined4 *)(param_1 + 0x48) = (undefined4)local_40;
    *(undefined8 *)(param_1 + 0x30) = 0;
    *(undefined8 *)(param_1 + 0x58) = 0;
    if (*(int *)(param_1 + 8) == 3) {
      if (*(int *)(param_1 + 0xc) == 1) {
        *(undefined4 *)(param_1 + 0x38) = 1;
      }
      else if (param_2 == 0) {
        *(undefined4 *)(param_1 + 0x38) = 2;
      }
      else {
        *(uint *)(param_1 + 0x38) = 4 - (uint)(param_2 != *(int *)(param_1 + 0xc) - 1U);
      }
    }
    pcVar2 = DAT_1400164f8;
    uVar7 = (ulong)*(undefined8 *)param_1;
    ChvP1I2c_ControllerIoGenerateStart((PBC_DEVICE *)DAT_1400164f8,uVar6);
    uVar4 = (*pcVar2)(SpbDriverGlobals);
    pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x650);
    ChvP1I2c_ControllerIoGenerateStart(pPVar1,uVar7);
    puVar5 = (undefined8 *)
             (*(code *)pPVar1)(WdfDriverGlobals,uVar4,PTR__WDF_PBC_TARGET_TYPE_INFO_140016048);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      pcVar8 = "write";
      if (*(int *)(param_1 + 0x44) == 1) {
        pcVar8 = "read";
      }
      WPP_SF_sLLq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x7f,
                  &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids,pcVar8,(char)param_2,
                  (char)*(undefined2 *)((longlong)puVar5 + 0xc),(char)*puVar5);
    }
    DmaCheckOp(*(PBC_DEVICE **)(param_1 + 0x60),param_1);
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x80,
            &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
  }
  return lVar9;
}



===== PbcRequestConfigureForIndex_DIRQL @ 140007540 =====

/* long __cdecl PbcRequestConfigureForIndex_DIRQL(struct PBC_REQUEST * __ptr64,unsigned long) */

long __cdecl PbcRequestConfigureForIndex_DIRQL(PBC_REQUEST *param_1,ulong param_2)

{
  longlong lVar1;
  long lVar2;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x84,
            &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
  }
  lVar2 = 0;
  lVar1 = *(longlong *)(param_1 + ((ulonglong)param_2 + 5) * 0x20);
  *(longlong *)(param_1 + 0x68) = lVar1;
  if (lVar1 == 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x85,
              &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
    }
    lVar2 = -0x3fffffff;
  }
  else {
    lVar1 = (ulonglong)param_2 * 0x20;
    *(undefined8 *)(param_1 + 0x30) = *(undefined8 *)(param_1 + lVar1 + 0x98);
    *(undefined8 *)(param_1 + 0x28) = *(undefined8 *)(param_1 + lVar1 + 0x90);
    *(undefined8 *)(param_1 + 0x58) = 0;
    *(undefined4 *)(param_1 + 0x44) = *(undefined4 *)(param_1 + lVar1 + 0xa8);
    *(undefined4 *)(param_1 + 0x48) = *(undefined4 *)(param_1 + lVar1 + 0xac);
    if (*(int *)(param_1 + 8) == 3) {
      if (*(int *)(param_1 + 0xc) == 1) {
        *(undefined4 *)(param_1 + 0x38) = 1;
      }
      else if (param_2 == 0) {
        *(undefined4 *)(param_1 + 0x38) = 2;
      }
      else {
        *(uint *)(param_1 + 0x38) = 4 - (uint)(param_2 != *(int *)(param_1 + 0xc) - 1U);
      }
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x87,
            &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
  }
  return lVar2;
}



===== PbcRequestConfigureForNonSequence @ 140007688 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl PbcRequestConfigureForNonSequence(struct WDFDEVICE__ * __ptr64,struct SPBTARGET__ *
   __ptr64,struct SPBREQUEST__ * __ptr64,unsigned __int64) */

void __cdecl
PbcRequestConfigureForNonSequence
          (WDFDEVICE__ *param_1,SPBTARGET__ *param_2,SPBREQUEST__ *param_3,__uint64 param_4)

{
  PBC_REQUEST PVar1;
  PBC_DEVICE *pPVar2;
  code *pcVar3;
  long lVar4;
  PBC_DEVICE *pPVar5;
  longlong lVar6;
  PBC_REQUEST *pPVar7;
  int iVar8;
  ulong uVar9;
  SPBTARGET__ *pSVar10;
  SPBREQUEST__ *pSVar11;
  undefined8 uVar12;
  PBC_REQUEST *pPVar13;
  undefined1 auStack_98 [32];
  undefined2 local_68 [2];
  undefined4 local_64;
  undefined4 local_60;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_98;
  pSVar10 = param_2;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    pSVar10 = (SPBTARGET__ *)0x77;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x77,
            &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
  }
  pPVar2 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x650);
  ChvP1I2c_ControllerIoGenerateStart(pPVar2,(ulong)pSVar10);
  pPVar5 = (PBC_DEVICE *)
           (*(code *)pPVar2)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140016020);
  pPVar2 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x650);
  ChvP1I2c_ControllerIoGenerateStart(pPVar2,(ulong)param_1);
  lVar6 = (*(code *)pPVar2)(WdfDriverGlobals,param_2,PTR__WDF_PBC_TARGET_TYPE_INFO_140016048);
  pPVar2 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x650);
  ChvP1I2c_ControllerIoGenerateStart(pPVar2,(ulong)param_2);
  pPVar7 = (PBC_REQUEST *)
           (*(code *)pPVar2)(WdfDriverGlobals,param_3,PTR__WDF_PBC_REQUEST_TYPE_INFO_140016070);
  uVar9 = 0;
  memset(local_68,0,0x20);
  pcVar3 = DAT_140016508;
  local_68[0] = 0x20;
  ChvP1I2c_ControllerIoGenerateStart((PBC_DEVICE *)DAT_140016508,uVar9);
  pSVar11 = param_3;
  (*pcVar3)(SpbDriverGlobals,param_3,local_68);
  uVar9 = (ulong)pSVar11;
  *(SPBREQUEST__ **)pPVar7 = param_3;
  *(undefined4 *)(pPVar7 + 8) = local_64;
  *(undefined4 *)(pPVar7 + 0x38) = local_60;
  *(undefined8 *)(pPVar7 + 0x18) = 0;
  *(undefined8 *)(pPVar7 + 0xc) = 1;
  pPVar7[0x24] = (PBC_REQUEST)0x0;
  *(PBC_DEVICE **)(pPVar7 + 0x60) = pPVar5;
  LOCK();
  *(uint *)(pPVar5 + 0x24c) = *(uint *)(pPVar5 + 0x24c) | 1;
  UNLOCK();
  lVar4 = PbcRequestValidate(pPVar7);
  if (-1 < lVar4) {
    pPVar2 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x9e0);
    ChvP1I2c_ControllerIoGenerateStart(pPVar2,uVar9);
    uVar9 = (ulong)*(undefined8 *)(pPVar5 + 0x38);
    (*(code *)pPVar2)(WdfDriverGlobals);
    KeClearEvent(pPVar5 + 0x288);
    uVar12 = *(undefined8 *)pPVar7;
    pPVar7[0x88] = (PBC_REQUEST)0x0;
    pPVar2 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0xc48);
    ChvP1I2c_ControllerIoGenerateStart(pPVar2,uVar9);
    lVar4 = (*(code *)pPVar2)(WdfDriverGlobals,uVar12,OnCancel);
    uVar9 = (ulong)uVar12;
    if (lVar4 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        uVar9 = 0x78;
        WPP_SF_xd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x78,
                  &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids,*(undefined8 *)pPVar7,(char)lVar4
                 );
      }
      pPVar2 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x9e8);
      ChvP1I2c_ControllerIoGenerateStart(pPVar2,uVar9);
      uVar9 = (ulong)*(undefined8 *)(pPVar5 + 0x38);
      (*(code *)pPVar2)(WdfDriverGlobals);
    }
    else {
      if (((pPVar5[0x310] != (PBC_DEVICE)0x0) &&
          ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
         (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0 && (3 < (byte)WPP_GLOBAL_Control[0x29])))
         ) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x79,
                &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
      }
      iVar8 = *(int *)(pPVar7 + 0x38);
      if (((iVar8 != 1) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
         (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0 && (2 < (byte)WPP_GLOBAL_Control[0x29])))
         ) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x7a,
                &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
        iVar8 = *(int *)(pPVar7 + 0x38);
      }
      if (iVar8 == 1) {
        *(longlong *)(pPVar5 + 0x20) = lVar6;
      }
      *(PBC_REQUEST **)(lVar6 + 0x18) = pPVar7;
      *(undefined4 *)(pPVar7 + 0x20) = 0;
      pPVar13 = pPVar7;
      ControllerTransferStateNavigation(pPVar5,pPVar7);
      PVar1 = pPVar7[0x24];
      pPVar2 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x9e8);
      ChvP1I2c_ControllerIoGenerateStart(pPVar2,(ulong)pPVar13);
      uVar9 = (ulong)*(undefined8 *)(pPVar5 + 0x38);
      (*(code *)pPVar2)(WdfDriverGlobals);
      if (PVar1 != (PBC_REQUEST)0x0) {
        PbcRequestComplete(pPVar7);
        if (PVar1 != (PBC_REQUEST)0x0) goto LAB_1400079c4;
      }
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    uVar9 = 0x7b;
    WPP_SF_xd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x7b,
              &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids,*(undefined8 *)pPVar7,(char)lVar4);
  }
  pcVar3 = DAT_140016518;
  ChvP1I2c_ControllerIoGenerateStart((PBC_DEVICE *)DAT_140016518,uVar9);
  (*pcVar3)(SpbDriverGlobals,param_3,lVar4);
LAB_1400079c4:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x7c,
            &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
  }
  return;
}



===== PbcRequestDoTransfer @ 140007a14 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* long __cdecl PbcRequestDoTransfer(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST * __ptr64) */

long __cdecl PbcRequestDoTransfer(PBC_DEVICE *param_1,PBC_REQUEST *param_2)

{
  PBC_DEVICE *pPVar1;
  uint uVar2;
  ulong uVar3;
  ulonglong uVar4;
  uint uVar5;
  long lVar6;
  longlong local_res10;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x88,
            &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
  }
  uVar2 = *(uint *)(param_2 + 0x48);
  uVar5 = 0;
  if (uVar2 != 0) {
    uVar4 = (ulonglong)uVar2;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_Lq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x89,
                &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids,uVar2,(char)*(undefined8 *)param_1)
      ;
      uVar2 = *(uint *)(param_2 + 0x48);
      uVar4 = (ulonglong)uVar2;
    }
    uVar3 = (ulong)uVar4;
    if (uVar2 < 15000) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_P(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x8a,
                 &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids,_DAT_fffff78000000014);
      }
      if (*(uint *)(param_2 + 0x48) / 0x32 != 0) {
        do {
          KeStallExecutionProcessor(0x32);
          uVar5 = uVar5 + 1;
        } while (uVar5 < *(uint *)(param_2 + 0x48) / 0x32);
      }
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x8b,
                  &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids,
                  (int)((ulonglong)_DAT_fffff78000000014 >> 0x20),(char)_DAT_fffff78000000014);
      }
    }
    else {
      if (1000000 < uVar2) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x8c,
                   &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids,uVar2);
        }
        lVar6 = -0x3ffffff3;
        *(undefined4 *)(param_2 + 0x20) = 0xc000000d;
        goto LAB_140007b77;
      }
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        uVar3 = 0x8d;
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x8d,
                &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
        uVar4 = (ulonglong)*(uint *)(param_2 + 0x48);
      }
      if (param_1[0x41] == (PBC_DEVICE)0x0) {
        local_res10 = uVar4 * -10;
        KeClearEvent(param_1 + 0x2b8);
        pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x9e8);
        ChvP1I2c_ControllerIoGenerateStart(pPVar1,uVar3);
        (*(code *)pPVar1)(WdfDriverGlobals);
        uVar3 = 0;
        uVar2 = KeWaitForSingleObject(param_1 + 0x2b8,0,0,0,&local_res10);
        pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x9e0);
        ChvP1I2c_ControllerIoGenerateStart(pPVar1,uVar3);
        (*(code *)pPVar1)(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x38));
        if ((uVar2 & 0xffffff7f) == 0) {
          lVar6 = 0x10b;
          goto LAB_140007b77;
        }
      }
      else if ((int)(uVar4 / 0x32) != 0) {
        do {
          KeStallExecutionProcessor(0x32);
          uVar5 = uVar5 + 1;
        } while (uVar5 < *(uint *)(param_2 + 0x48) / 0x32);
      }
    }
  }
  ControllerConfigureForTransfer(param_1,param_2);
  lVar6 = *(long *)(param_2 + 0x20);
LAB_140007b77:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x8e,
            &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
  }
  return lVar6;
}



===== PbcRequestValidate @ 140007d04 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl PbcRequestValidate(struct PBC_REQUEST * __ptr64) */

long __cdecl PbcRequestValidate(PBC_REQUEST *param_1)

{
  code *pcVar1;
  undefined8 in_RDX;
  uint uVar2;
  long lVar3;
  undefined1 auStackY_78 [32];
  undefined8 local_38;
  ulonglong local_30;
  undefined8 local_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStackY_78;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    in_RDX = 0x72;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x72,
            &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
  }
  lVar3 = 0;
  if ((*(char *)(*(longlong *)(param_1 + 0x60) + 0x41) == '\0') || (*(uint *)(param_1 + 0xc) < 10))
  {
    uVar2 = 0;
    if (*(int *)(param_1 + 0xc) != 0) {
      do {
        pcVar1 = DAT_140016510;
        local_30 = 0;
        local_28 = 0;
        local_38 = 0x18;
        ChvP1I2c_ControllerIoGenerateStart((PBC_DEVICE *)DAT_140016510,(ulong)in_RDX);
        in_RDX = *(undefined8 *)param_1;
        (*pcVar1)(SpbDriverGlobals,in_RDX,uVar2,&local_38);
        if ((*(uint *)(*(longlong *)(param_1 + 0x60) + 0x78) < local_30) || (local_30 == 0)) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0 &&
              (1 < (byte)WPP_GLOBAL_Control[0x29])))) {
            WPP_SF_PdqL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x74,
                        &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids,local_30,
                        (char)*(uint *)(*(longlong *)(param_1 + 0x60) + 0x78),
                        (char)*(undefined8 *)param_1,(char)uVar2);
          }
          goto LAB_140007e9e;
        }
        if (1 < local_38._4_4_ - 1U) {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x75,
                      &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids,
                      *(undefined4 *)(param_1 + 0x44),(char)uVar2);
          }
          goto LAB_140007e9e;
        }
        uVar2 = uVar2 + 1;
      } while (uVar2 < *(uint *)(param_1 + 0xc));
    }
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x73,
               &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids,*(uint *)(param_1 + 0xc));
    }
LAB_140007e9e:
    lVar3 = -0x3ffffff3;
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x76,
            &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
  }
  return lVar3;
}



===== PbcTargetGetSettings @ 140007ef8 =====

/* long __cdecl PbcTargetGetSettings(struct PBC_DEVICE * __ptr64,void * __ptr64,struct
   PBC_TARGET_SETTINGS * __ptr64) */

long __cdecl PbcTargetGetSettings(PBC_DEVICE *param_1,void *param_2,PBC_TARGET_SETTINGS *param_3)

{
  long lVar1;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6f,
            &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
  }
  if (*(uint *)((longlong)param_2 + 4) < 8) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x70,
                &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids,*(uint *)((longlong)param_2 + 4),8)
      ;
    }
    lVar1 = -0x3ffffff3;
  }
  else {
    lVar1 = LpssApi_TargetGetSettings(param_1,(void *)((longlong)param_2 + 8),param_3);
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x71,
            &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
  }
  return lVar1;
}



===== PollingIoctlWorker @ 140007fec =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl PollingIoctlWorker(struct WDFDEVICE__ * __ptr64,struct SPBTARGET__ * __ptr64,struct
   SPBREQUEST__ * __ptr64,unsigned int) */

void __cdecl
PollingIoctlWorker(WDFDEVICE__ *param_1,SPBTARGET__ *param_2,SPBREQUEST__ *param_3,uint param_4)

{
  PBC_DEVICE *pPVar1;
  code *pcVar2;
  undefined1 uVar3;
  uchar uVar4;
  long lVar5;
  ulong uVar6;
  ulong uVar7;
  PBC_DEVICE *pPVar8;
  longlong lVar9;
  PBC_REQUEST *pPVar10;
  SPBTARGET__ *pSVar11;
  SPBREQUEST__ *pSVar12;
  undefined8 uVar13;
  PBC_REQUEST *pPVar14;
  __uint64 _Var15;
  uint uVar16;
  int iVar17;
  bool bVar18;
  bool bVar19;
  undefined1 auStack_b8 [32];
  undefined1 local_78 [24];
  undefined2 local_60 [2];
  undefined4 local_5c;
  undefined4 local_58;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_b8;
  pSVar11 = param_2;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    pSVar11 = (SPBTARGET__ *)0x51;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x51,
            &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
  }
  pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x650);
  ChvP1I2c_ControllerIoGenerateStart(pPVar1,(ulong)pSVar11);
  pPVar8 = (PBC_DEVICE *)
           (*(code *)pPVar1)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140016020);
  pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x650);
  ChvP1I2c_ControllerIoGenerateStart(pPVar1,(ulong)param_1);
  lVar9 = (*(code *)pPVar1)(WdfDriverGlobals,param_2,PTR__WDF_PBC_TARGET_TYPE_INFO_140016048);
  pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x650);
  ChvP1I2c_ControllerIoGenerateStart(pPVar1,(ulong)param_2);
  pPVar10 = (PBC_REQUEST *)
            (*(code *)pPVar1)(WdfDriverGlobals,param_3,PTR__WDF_PBC_REQUEST_TYPE_INFO_140016070);
  uVar16 = 0;
  uVar6 = 0;
  bVar19 = false;
  memset(local_60,0,0x20);
  pcVar2 = DAT_140016508;
  local_60[0] = 0x20;
  ChvP1I2c_ControllerIoGenerateStart((PBC_DEVICE *)DAT_140016508,uVar6);
  pSVar12 = param_3;
  (*pcVar2)(SpbDriverGlobals,param_3,local_60);
  uVar6 = (ulong)pSVar12;
  *(SPBREQUEST__ **)pPVar10 = param_3;
  *(undefined4 *)(pPVar10 + 8) = local_5c;
  *(undefined4 *)(pPVar10 + 0x38) = local_58;
  *(undefined8 *)(pPVar10 + 0x18) = 0;
  *(uint *)(pPVar10 + 0xc) = param_4;
  *(undefined4 *)(pPVar10 + 0x10) = 0;
  pPVar10[0x24] = (PBC_REQUEST)0x0;
  *(PBC_DEVICE **)(pPVar10 + 0x60) = pPVar8;
  lVar5 = PbcRequestValidate(pPVar10);
  if (lVar5 < 0) goto LAB_140008839;
  PbcRequestConfigureArrayInitialize(pPVar10);
  pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x9e0);
  ChvP1I2c_ControllerIoGenerateStart(pPVar1,uVar6);
  uVar6 = (ulong)*(undefined8 *)(pPVar8 + 0x38);
  (*(code *)pPVar1)(WdfDriverGlobals);
  if (param_4 == 1) {
    if (((pPVar8[0x310] != (PBC_DEVICE)0x0) &&
        ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
       (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0 && (3 < (byte)WPP_GLOBAL_Control[0x29]))))
    {
      uVar6 = 0x52;
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x52,
              &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
    }
    if (*(int *)(pPVar10 + 0x38) == 1) goto LAB_1400081d8;
LAB_1400081e6:
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (2 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      uVar6 = 0x54;
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x54,
              &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
    }
  }
  else {
    if (pPVar8[0x310] == (PBC_DEVICE)0x0) {
LAB_1400081d8:
      *(longlong *)(pPVar8 + 0x20) = lVar9;
    }
    else if (lVar9 != *(longlong *)(pPVar8 + 0x20)) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        uVar6 = 0x53;
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x53,
                &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
      }
      *(undefined4 *)(pPVar10 + 0x20) = 0xc000000d;
      bVar19 = false;
      pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x9e8);
      ChvP1I2c_ControllerIoGenerateStart(pPVar1,uVar6);
      uVar6 = (ulong)*(undefined8 *)(pPVar8 + 0x38);
      (*(code *)pPVar1)(WdfDriverGlobals);
      goto LAB_140008839;
    }
    if (*(int *)(pPVar10 + 0x38) != 1) goto LAB_1400081e6;
  }
  *(PBC_REQUEST **)(lVar9 + 0x18) = pPVar10;
  uVar3 = KfRaiseIrql(0xc);
  if ((pPVar8[0x41] != (PBC_DEVICE)0x0) && (pPVar8[0x310] == (PBC_DEVICE)0x0)) {
    uVar13 = 0;
    KeInitializeEvent(local_78,0,0);
    lVar5 = AcquireMbiSemaphoreLock(pPVar8);
    uVar6 = (ulong)uVar13;
    if (lVar5 < 0) {
      pPVar8[0x40] = (PBC_DEVICE)0x0;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        uVar6 = 0x55;
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x55,
                &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
      }
LAB_140008316:
      KeLowerIrql(uVar3);
      pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x9e8);
      ChvP1I2c_ControllerIoGenerateStart(pPVar1,uVar6);
      uVar6 = (ulong)*(undefined8 *)(pPVar8 + 0x38);
      (*(code *)pPVar1)(WdfDriverGlobals);
      goto LAB_140008839;
    }
    pPVar8[0x40] = (PBC_DEVICE)0x1;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      uVar13 = 0x56;
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x56,
              &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
    }
    while( true ) {
      uVar6 = (ulong)uVar13;
      uVar7 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(pPVar8 + 8) + 0x70))
      ;
      if ((uVar7 & 0x20) == 0) break;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        uVar6 = HWREG<unsigned_long>::Read
                          ((HWREG<unsigned_long> *)(*(longlong *)(pPVar8 + 8) + 0x70));
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x57,
                 &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids,uVar6);
      }
      uVar13 = 0;
      KeWaitForSingleObject(local_78,0,0,0);
      uVar6 = (ulong)uVar13;
      if (100 < uVar16) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar7 = HWREG<unsigned_long>::Read
                            ((HWREG<unsigned_long> *)(*(longlong *)(pPVar8 + 8) + 0x70));
          uVar6 = 0x58;
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x58,
                   &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids,uVar7);
        }
        lVar5 = ReleaseMbiSemaphoreLock(pPVar8);
        pPVar8[0x40] = (PBC_DEVICE)0x0;
        if (((lVar5 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
           (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200) != 0 &&
            (1 < (byte)WPP_GLOBAL_Control[0x29])))) {
          uVar6 = 0x59;
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x59,
                   &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids,lVar5);
        }
        goto LAB_140008316;
      }
      uVar16 = uVar16 + 1;
    }
  }
  bVar19 = true;
  pPVar10[0x24] = (PBC_REQUEST)0x0;
  *(undefined4 *)(pPVar10 + 0x20) = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
     ) {
    uVar6 = 0x5a;
    WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5a,
              &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids,*(undefined4 *)(pPVar10 + 0x10),
              (char)*(undefined4 *)(pPVar10 + 0xc));
  }
  *(undefined4 *)(pPVar10 + 0x10) = 0;
  if (*(int *)(pPVar10 + 0xc) != 0) {
    uVar7 = 0;
    do {
      uVar6 = uVar7;
      lVar5 = PbcRequestConfigureForIndex_DIRQL(pPVar10,uVar7);
      if (lVar5 < 0) {
LAB_140008750:
        *(undefined4 *)(pPVar10 + 0x20) = 0xc0000001;
        pPVar10[0x24] = (PBC_REQUEST)0x0;
        break;
      }
      pPVar14 = pPVar10;
      lVar5 = PbcRequestDoTransfer(pPVar8,pPVar10);
      uVar6 = (ulong)pPVar14;
      if (lVar5 < 0) goto LAB_140008750;
      iVar17 = 20000;
      while( true ) {
        iVar17 = iVar17 + -1;
        uVar7 = HWREG<unsigned_long>::Read
                          ((HWREG<unsigned_long> *)(*(longlong *)(pPVar8 + 8) + 0x34));
        if ((uVar7 & 0x40) != 0) break;
        if (((pPVar10[0x41] != (PBC_REQUEST)0x1) && (*(int *)(pPVar10 + 0x44) == 2)) &&
           ((pPVar14 = *(PBC_REQUEST **)(pPVar10 + 0x58),
            *(PBC_REQUEST **)(pPVar10 + 0x28) == pPVar14 && ((uVar7 & 0x10) != 0)))) {
LAB_14000860c:
          uVar6 = (ulong)pPVar14;
          *(undefined4 *)(pPVar10 + 0x20) = 0;
          goto LAB_1400086e0;
        }
        if ((!bVar19) || (*(int *)(pPVar10 + 0x44) != 1)) {
          pPVar14 = pPVar10;
          ControllerTransferData(pPVar8,pPVar10);
          if ((((!bVar19) && (*(int *)(pPVar10 + 0x44) == 1)) &&
              (*(longlong *)(pPVar10 + 0x80) == 0)) &&
             (bVar19 = true, *(longlong *)(pPVar10 + 0x28) == *(longlong *)(pPVar10 + 0x58)))
          goto LAB_14000860c;
          uVar13 = 0x200;
          uVar6 = 0x200;
          if ((uVar7 & 0x200) != 0) {
            pPVar10[0x24] = (PBC_REQUEST)0x1;
            *(undefined4 *)(pPVar10 + 0x20) = 0;
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200) != 0)) &&
               (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              uVar6 = 0x5c;
              WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5c,
                      &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
            }
            goto LAB_1400086e4;
          }
          lVar9 = 0x14;
          do {
            KeStallExecutionProcessor(0x32);
            uVar6 = (ulong)uVar13;
            lVar9 = lVar9 + -1;
          } while (lVar9 != 0);
        }
        else {
          pPVar14 = pPVar10;
          lVar5 = LpssApi_PrepareForTransfer(pPVar8,pPVar10);
          bVar19 = false;
          lVar9 = 0x14;
          do {
            KeStallExecutionProcessor(0x32);
            uVar6 = (ulong)pPVar14;
            lVar9 = lVar9 + -1;
          } while (lVar9 != 0);
        }
        if (iVar17 < 1) goto LAB_1400086e4;
      }
      uVar7 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(pPVar8 + 8) + 0x80))
      ;
      *(ulong *)(pPVar8 + 0xe0) = uVar7;
      uVar6 = 0x40016000;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200) != 0)) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar6 = 0x5b;
        WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5b,
                  &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids,lVar5,(char)uVar7);
      }
      _Var15 = 0;
      uVar4 = LpssApi_IsAbortByAddressPhase(pPVar8);
      if (uVar4 == '\0') {
        *(undefined4 *)(pPVar10 + 0x20) = 0x10b;
        _Var15 = LpssApi_UpdateTransferDataSize(pPVar8);
      }
      else {
        *(undefined4 *)(pPVar10 + 0x20) = 0xc000000e;
      }
      *(__uint64 *)(pPVar10 + 0x58) = _Var15;
LAB_1400086e0:
      pPVar10[0x24] = (PBC_REQUEST)0x0;
LAB_1400086e4:
      *(longlong *)(pPVar10 + 0x18) = *(longlong *)(pPVar10 + 0x18) + *(longlong *)(pPVar10 + 0x58);
      *(undefined8 *)(pPVar10 + 0x58) = 0;
      if ((pPVar10[0x24] == (PBC_REQUEST)0x0) && (iVar17 == 0)) {
        *(undefined4 *)(pPVar10 + 0x20) = 0xc0000001;
      }
      if ((pPVar10[0x41] == (PBC_REQUEST)0x1) && (pPVar8[0x310] == (PBC_DEVICE)0x0)) {
        bVar18 = *(int *)(pPVar10 + 0x20) == 0;
LAB_140008732:
        pPVar8[0x3b1] = (PBC_DEVICE)!bVar18;
        uVar6 = *(ulong *)(*(longlong *)(pPVar8 + 0x20) + 0x20);
        LpssApi_ControllerIoGenerateStop(pPVar8,uVar6);
        pPVar10[0x24] = (PBC_REQUEST)0x1;
        break;
      }
      if ((pPVar10[0x24] == (PBC_REQUEST)0x0) && (bVar18 = *(int *)(pPVar10 + 0x20) == 0, !bVar18))
      goto LAB_140008732;
      uVar7 = *(int *)(pPVar10 + 0x10) + 1;
      *(ulong *)(pPVar10 + 0x10) = uVar7;
    } while (uVar7 < *(uint *)(pPVar10 + 0xc));
  }
  if (*(int *)(pPVar10 + 0x10) == *(int *)(pPVar10 + 0xc)) {
    pPVar10[0x24] = (PBC_REQUEST)0x1;
  }
  *(undefined8 *)(*(longlong *)(pPVar8 + 0x20) + 0x18) = 0;
  if ((*(int *)(pPVar10 + 8) == 3) || (*(int *)(pPVar10 + 0x38) == 1)) {
    *(undefined8 *)(pPVar8 + 0x20) = 0;
  }
  if (((pPVar8[0x41] != (PBC_DEVICE)0x0) && (pPVar8[0x310] == (PBC_DEVICE)0x0)) &&
     (pPVar8[0x40] != (PBC_DEVICE)0x0)) {
    lVar5 = ReleaseMbiSemaphoreLock(pPVar8);
    pPVar8[0x40] = (PBC_DEVICE)0x0;
    if (((lVar5 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
       (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200) != 0 && (1 < (byte)WPP_GLOBAL_Control[0x29])
        ))) {
      uVar6 = 0x5d;
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5d,
               &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids,lVar5);
    }
  }
  KeLowerIrql(uVar3);
  pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x9e8);
  ChvP1I2c_ControllerIoGenerateStart(pPVar1,uVar6);
  uVar6 = (ulong)*(undefined8 *)(pPVar8 + 0x38);
  (*(code *)pPVar1)(WdfDriverGlobals);
  bVar19 = pPVar10[0x24] != (PBC_REQUEST)0x0;
  if (pPVar10[0x24] != (PBC_REQUEST)0x0) {
    PbcRequestComplete(pPVar10);
  }
LAB_140008839:
  if ((pPVar8[0x41] != (PBC_DEVICE)0x0) && (pPVar8[0x40] != (PBC_DEVICE)0x0)) {
    lVar5 = ReleaseMbiSemaphoreLock(pPVar8);
    pPVar8[0x40] = (PBC_DEVICE)0x0;
    if ((lVar5 < 0) &&
       ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200) != 0)) &&
        (1 < (byte)WPP_GLOBAL_Control[0x29])))) {
      uVar6 = 0x5e;
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5e,
               &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids,lVar5);
    }
  }
  if (!bVar19) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      uVar6 = 0x5f;
      WPP_SF_xd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5f,
                &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids,*(undefined8 *)pPVar10,
                (char)*(undefined4 *)(pPVar10 + 0x20));
    }
    pcVar2 = DAT_140016518;
    ChvP1I2c_ControllerIoGenerateStart((PBC_DEVICE *)DAT_140016518,uVar6);
    (*pcVar2)(SpbDriverGlobals,param_3,*(undefined4 *)(pPVar10 + 0x20));
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x60,
            &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
  }
  return;
}



===== ReleaseMbiSemaphoreLock @ 14000893c =====

/* long __cdecl ReleaseMbiSemaphoreLock(struct PBC_DEVICE * __ptr64) */

long __cdecl ReleaseMbiSemaphoreLock(PBC_DEVICE *param_1)

{
  ulong uVar1;
  longlong lVar2;
  uint uVar3;
  undefined8 local_res8;
  undefined1 local_28 [32];
  
  lVar2 = 4;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
            &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
  }
  uVar3 = 0;
  KeInitializeEvent(local_28,0,0);
  ReleaseSema_MST_BIT = 0;
  ReleaseSema_MST_TIMEOUT = 0;
  local_res8 = 1000000000;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    uVar1 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x70));
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
             &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids,uVar1);
  }
  while (uVar1 = HWREG<unsigned_long>::Read
                           ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x70)),
        (uVar1 & 0x20) != 0) {
    KeWaitForSingleObject(local_28,0,0,0,&local_res8);
    if (10000 < uVar3) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        uVar1 = HWREG<unsigned_long>::Read
                          ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x70));
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
                 &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids,uVar1);
      }
      ReleaseSema_MST_TIMEOUT = 1;
      break;
    }
    uVar3 = uVar3 + 1;
  }
  if (DAT_1400161d0 != (CMBI *)0x0) {
    ReleaseSema_MST_BIT =
         HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x70));
    ReleaseSema_SEMAREG_V2_Count = 0;
    ReleaseSema_SEMAREG_V1 = CMBI::Read(DAT_1400161d0,'\x04',0x10e);
    LOCK();
    UNLOCK();
    uVar3 = 0;
    do {
      CMBI::Write(DAT_1400161d0,'\x04',0x10e,0);
      LOCK();
      UNLOCK();
      ReleaseSema_SEMAREG_V2 = CMBI::Read(DAT_1400161d0,'\x04',0x10e);
      LOCK();
      UNLOCK();
      if (ReleaseSema_SEMAREG_V2 == 0) break;
      ReleaseSema_SEMAREG_V2_Count = ReleaseSema_SEMAREG_V2_Count + 1;
      KeStallExecutionProcessor(0x32);
      uVar3 = uVar3 + 1;
    } while (uVar3 < 10);
    do {
      KeStallExecutionProcessor(0x32);
      lVar2 = lVar2 + -1;
    } while (lVar2 != 0);
  }
  return 0;
}



===== SequenceIoctlWorker @ 140008b50 =====

/* void __cdecl SequenceIoctlWorker(struct WDFWORKITEM__ * __ptr64) */

void __cdecl SequenceIoctlWorker(WDFWORKITEM__ *param_1)

{
  PBC_DEVICE *pPVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  longlong lVar4;
  ulong in_EDX;
  WDFWORKITEM__ *pWVar5;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    in_EDX = 0x45;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x45,
            &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
  }
  pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x650);
  ChvP1I2c_ControllerIoGenerateStart(pPVar1,in_EDX);
  pWVar5 = param_1;
  puVar3 = (undefined8 *)
           (*(code *)pPVar1)(WdfDriverGlobals,param_1,
                             PTR__WDF_LPSS_WORK_ITEM_CONTEXT_TYPE_INFO_1400160c0);
  uVar2 = *puVar3;
  pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x650);
  ChvP1I2c_ControllerIoGenerateStart(pPVar1,(ulong)pWVar5);
  lVar4 = (*(code *)pPVar1)(WdfDriverGlobals,uVar2,PTR__WDF_PBC_DEVICE_TYPE_INFO_140016020);
  if (*(char *)(lVar4 + 0x41) == '\0') {
    SequenceIoctlWorker_PIO(param_1);
  }
  else {
    PollingIoctlWorker((WDFDEVICE__ *)*puVar3,(SPBTARGET__ *)puVar3[1],(SPBREQUEST__ *)puVar3[2],
                       *(uint *)(puVar3 + 4));
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x46,
            &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
  }
  return;
}



===== SequenceIoctlWorker_PIO @ 140008c68 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl SequenceIoctlWorker_PIO(struct WDFWORKITEM__ * __ptr64) */

void __cdecl SequenceIoctlWorker_PIO(WDFWORKITEM__ *param_1)

{
  PBC_REQUEST PVar1;
  undefined4 uVar2;
  PBC_DEVICE *pPVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  code *pcVar6;
  long lVar7;
  int iVar8;
  undefined8 *puVar9;
  PBC_DEVICE *pPVar10;
  longlong lVar11;
  PBC_REQUEST *pPVar12;
  ulong in_EDX;
  ulong uVar13;
  uint uVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  PBC_REQUEST *pPVar17;
  bool bVar18;
  undefined1 auStackY_98 [32];
  undefined2 local_50 [2];
  undefined4 local_4c;
  undefined4 local_48;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_98;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    in_EDX = 0x4a;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4a,
            &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
  }
  pPVar3 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x650);
  ChvP1I2c_ControllerIoGenerateStart(pPVar3,in_EDX);
  puVar9 = (undefined8 *)
           (*(code *)pPVar3)(WdfDriverGlobals,param_1,
                             PTR__WDF_LPSS_WORK_ITEM_CONTEXT_TYPE_INFO_1400160c0);
  uVar4 = puVar9[2];
  uVar16 = *puVar9;
  uVar5 = puVar9[1];
  uVar2 = *(undefined4 *)(puVar9 + 4);
  pPVar3 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x650);
  ChvP1I2c_ControllerIoGenerateStart(pPVar3,(ulong)param_1);
  uVar15 = uVar16;
  pPVar10 = (PBC_DEVICE *)
            (*(code *)pPVar3)(WdfDriverGlobals,uVar16,PTR__WDF_PBC_DEVICE_TYPE_INFO_140016020);
  pPVar3 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x650);
  ChvP1I2c_ControllerIoGenerateStart(pPVar3,(ulong)uVar15);
  uVar15 = uVar5;
  lVar11 = (*(code *)pPVar3)(WdfDriverGlobals,uVar5,PTR__WDF_PBC_TARGET_TYPE_INFO_140016048);
  pPVar3 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x650);
  ChvP1I2c_ControllerIoGenerateStart(pPVar3,(ulong)uVar15);
  pPVar12 = (PBC_REQUEST *)
            (*(code *)pPVar3)(WdfDriverGlobals,uVar4,PTR__WDF_PBC_REQUEST_TYPE_INFO_140016070);
  uVar13 = 0;
  memset(local_50,0,0x20);
  pcVar6 = DAT_140016508;
  local_50[0] = 0x20;
  ChvP1I2c_ControllerIoGenerateStart((PBC_DEVICE *)DAT_140016508,uVar13);
  uVar15 = uVar4;
  (*pcVar6)(SpbDriverGlobals,uVar4,local_50);
  uVar13 = (ulong)uVar15;
  *(undefined8 *)pPVar12 = uVar4;
  *(undefined4 *)(pPVar12 + 8) = local_4c;
  *(undefined4 *)(pPVar12 + 0x38) = local_48;
  *(undefined8 *)(pPVar12 + 0x18) = 0;
  *(undefined4 *)(pPVar12 + 0x10) = 0;
  pPVar12[0x24] = (PBC_REQUEST)0x0;
  *(undefined4 *)(pPVar12 + 0xc) = uVar2;
  *(PBC_DEVICE **)(pPVar12 + 0x60) = pPVar10;
  LOCK();
  *(uint *)(pPVar10 + 0x24c) = *(uint *)(pPVar10 + 0x24c) | 1;
  UNLOCK();
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    uVar13 = 0x4b;
    WPP_SF_qdqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4b,
                &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids,*(undefined8 *)pPVar12,
                (char)*(undefined4 *)(pPVar12 + 0xc),(char)uVar5,(char)uVar16);
  }
  lVar7 = PbcRequestValidate(pPVar12);
  if (-1 < lVar7) {
    pPVar3 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x9e0);
    ChvP1I2c_ControllerIoGenerateStart(pPVar3,uVar13);
    uVar13 = (ulong)*(undefined8 *)(pPVar10 + 0x38);
    (*(code *)pPVar3)(WdfDriverGlobals);
    KeClearEvent(pPVar10 + 0x288);
    uVar16 = *(undefined8 *)pPVar12;
    pPVar12[0x88] = (PBC_REQUEST)0x0;
    pPVar3 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0xc48);
    ChvP1I2c_ControllerIoGenerateStart(pPVar3,uVar13);
    lVar7 = (*(code *)pPVar3)(WdfDriverGlobals,uVar16,OnCancel);
    uVar13 = (ulong)uVar16;
    if (lVar7 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        uVar13 = 0x4c;
        WPP_SF_xd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4c,
                  &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids,*(undefined8 *)pPVar12,
                  (char)lVar7);
      }
      pPVar3 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x9e8);
      ChvP1I2c_ControllerIoGenerateStart(pPVar3,uVar13);
      uVar13 = (ulong)*(undefined8 *)(pPVar10 + 0x38);
      (*(code *)pPVar3)(WdfDriverGlobals);
    }
    else {
      if (pPVar10[0x310] == (PBC_DEVICE)0x0) {
        *(longlong *)(pPVar10 + 0x20) = lVar11;
LAB_140009021:
        *(PBC_REQUEST **)(lVar11 + 0x18) = pPVar12;
        *(undefined4 *)(pPVar12 + 0x20) = 0;
        pPVar17 = pPVar12;
        ControllerTransferStateNavigation(pPVar10,pPVar12);
        PVar1 = pPVar12[0x24];
        bVar18 = PVar1 != (PBC_REQUEST)0x0;
        pPVar3 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x9e8);
        ChvP1I2c_ControllerIoGenerateStart(pPVar3,(ulong)pPVar17);
        uVar13 = (ulong)*(undefined8 *)(pPVar10 + 0x38);
        (*(code *)pPVar3)(WdfDriverGlobals);
        if (PVar1 != (PBC_REQUEST)0x0) {
          PbcRequestComplete(pPVar12);
        }
      }
      else {
        if (lVar11 == *(longlong *)(pPVar10 + 0x20)) goto LAB_140009021;
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar13 = 0x4d;
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4d,
                  &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
        }
        uVar14 = (uint)*(undefined8 *)pPVar12;
        pPVar3 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x800);
        ChvP1I2c_ControllerIoGenerateStart(pPVar3,uVar13);
        iVar8 = (*(code *)pPVar3)(WdfDriverGlobals);
        if (((iVar8 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
           ((uVar14 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar14 & 8) != 0 &&
            (1 < (byte)WPP_GLOBAL_Control[0x29])))) {
          uVar14 = 0x4e;
          WPP_SF_xd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4e,
                    &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids,*(undefined8 *)pPVar12,
                    (char)iVar8);
        }
        bVar18 = iVar8 == -0x3ffffee0;
        lVar7 = -0x3ffffff3;
        pPVar3 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x9e8);
        ChvP1I2c_ControllerIoGenerateStart(pPVar3,uVar14);
        uVar13 = (ulong)*(undefined8 *)(pPVar10 + 0x38);
        (*(code *)pPVar3)(WdfDriverGlobals);
      }
      if (bVar18) goto LAB_1400090d8;
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    uVar13 = 0x4f;
    WPP_SF_xd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4f,
              &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids,*(undefined8 *)pPVar12,(char)lVar7);
  }
  pcVar6 = DAT_140016518;
  ChvP1I2c_ControllerIoGenerateStart((PBC_DEVICE *)DAT_140016518,uVar13);
  (*pcVar6)(SpbDriverGlobals,uVar4,lVar7);
LAB_1400090d8:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x50,
            &WPP_2ad8463ac409321276b270cb100b84a9_Traceguids);
  }
  return;
}



===== WPP_SF_DqqDDD @ 140009138 =====

void WPP_SF_DqqDDD(undefined8 param_1,uint param_2,undefined8 param_3,undefined4 param_4,
                  undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
                  undefined1 param_9)

{
  PBC_DEVICE *pPVar1;
  undefined4 local_res20 [2];
  
  pPVar1 = pfnWppTraceMessage;
  local_res20[0] = param_4;
  ChvP1I2c_ControllerIoGenerateStart(pfnWppTraceMessage,param_2);
  (*(code *)pPVar1)(param_1,0x2b,param_3,param_2 & 0xffff,local_res20,4,&param_5,8,&param_6,8,
                    &param_7,4,&param_8,4,&param_9,4,0);
  return;
}



===== WPP_SF_Lqd @ 140009210 =====

void WPP_SF_Lqd(undefined8 param_1,uint param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  PBC_DEVICE *pPVar1;
  undefined4 local_res20 [2];
  
  pPVar1 = pfnWppTraceMessage;
  local_res20[0] = param_4;
  ChvP1I2c_ControllerIoGenerateStart(pfnWppTraceMessage,param_2);
  (*(code *)pPVar1)(param_1,0x2b,param_3,param_2 & 0xffff,local_res20,4,&param_5,8,&param_6,4,0);
  return;
}



===== WPP_SF_PdqL @ 1400092ac =====

void WPP_SF_PdqL(undefined8 param_1,uint param_2,undefined8 param_3,undefined8 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  PBC_DEVICE *pPVar1;
  undefined8 local_res20;
  
  pPVar1 = pfnWppTraceMessage;
  local_res20 = param_4;
  ChvP1I2c_ControllerIoGenerateStart(pfnWppTraceMessage,param_2);
  (*(code *)pPVar1)(param_1,0x2b,param_3,param_2 & 0xffff,&local_res20,8,&param_5,4,&param_6,8,
                    &param_7,4,0);
  return;
}



===== WPP_SF_g @ 140009358 =====

void WPP_SF_g(undefined8 param_1,uint param_2,undefined8 param_3,undefined8 param_4)

{
  PBC_DEVICE *pPVar1;
  undefined8 local_res20;
  
  pPVar1 = pfnWppTraceMessage;
  local_res20 = param_4;
  ChvP1I2c_ControllerIoGenerateStart(pfnWppTraceMessage,param_2);
  (*(code *)pPVar1)(param_1,0x2b,param_3,param_2 & 0xffff,&local_res20,8,0);
  return;
}



===== WPP_SF_qLq @ 1400093c8 =====

void WPP_SF_qLq(undefined8 param_1,uint param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  PBC_DEVICE *pPVar1;
  undefined8 local_res20;
  
  pPVar1 = pfnWppTraceMessage;
  local_res20 = param_4;
  ChvP1I2c_ControllerIoGenerateStart(pfnWppTraceMessage,param_2);
  (*(code *)pPVar1)(param_1,0x2b,param_3,param_2 & 0xffff,&local_res20,8,&param_5,4,&param_6,8,0);
  return;
}



===== WPP_SF_qPqq @ 140009464 =====

void WPP_SF_qPqq(undefined8 param_1,uint param_2,undefined8 param_3,undefined8 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  PBC_DEVICE *pPVar1;
  undefined8 local_res20;
  
  pPVar1 = pfnWppTraceMessage;
  local_res20 = param_4;
  ChvP1I2c_ControllerIoGenerateStart(pfnWppTraceMessage,param_2);
  (*(code *)pPVar1)(param_1,0x2b,param_3,param_2 & 0xffff,&local_res20,8,&param_5,8,&param_6,8,
                    &param_7,8,0);
  return;
}



===== WPP_SF_qdqq @ 14000950c =====

void WPP_SF_qdqq(undefined8 param_1,uint param_2,undefined8 param_3,undefined8 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  PBC_DEVICE *pPVar1;
  undefined8 local_res20;
  
  pPVar1 = pfnWppTraceMessage;
  local_res20 = param_4;
  ChvP1I2c_ControllerIoGenerateStart(pfnWppTraceMessage,param_2);
  (*(code *)pPVar1)(param_1,0x2b,param_3,param_2 & 0xffff,&local_res20,8,&param_5,4,&param_6,8,
                    &param_7,8,0);
  return;
}



===== WPP_SF_qqq @ 1400095b8 =====

void WPP_SF_qqq(undefined8 param_1,uint param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  PBC_DEVICE *pPVar1;
  undefined8 local_res20;
  
  pPVar1 = pfnWppTraceMessage;
  local_res20 = param_4;
  ChvP1I2c_ControllerIoGenerateStart(pfnWppTraceMessage,param_2);
  (*(code *)pPVar1)(param_1,0x2b,param_3,param_2 & 0xffff,&local_res20,8,&param_5,8,&param_6,8,0);
  return;
}



===== WPP_SF_sLLq @ 140009650 =====

void WPP_SF_sLLq(undefined8 param_1,uint param_2,undefined8 param_3,char *param_4,undefined1 param_5
                ,undefined1 param_6,undefined1 param_7)

{
  PBC_DEVICE *pPVar1;
  char *pcVar2;
  longlong lVar3;
  longlong lVar4;
  
  pPVar1 = pfnWppTraceMessage;
  if (param_4 == (char *)0x0) {
    lVar4 = 5;
  }
  else {
    lVar3 = -1;
    do {
      lVar4 = lVar3;
      lVar3 = lVar4 + 1;
    } while (param_4[lVar3] != '\0');
    lVar4 = lVar4 + 2;
  }
  pcVar2 = "NULL";
  if (param_4 != (char *)0x0) {
    pcVar2 = param_4;
  }
  ChvP1I2c_ControllerIoGenerateStart(pfnWppTraceMessage,param_2);
  (*(code *)pPVar1)(param_1,0x2b,param_3,(short)param_2,pcVar2,lVar4,&param_5,4,&param_6,4,&param_7,
                    8,0);
  return;
}



===== OnDeviceAdd @ 140009730 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl OnDeviceAdd(struct WDFDRIVER__ * __ptr64,struct WDFDEVICE_INIT * __ptr64) */

long __cdecl OnDeviceAdd(WDFDRIVER__ *param_1,WDFDEVICE_INIT *param_2)

{
  PBC_DEVICE *pPVar1;
  code *pcVar2;
  uchar uVar3;
  int iVar4;
  undefined8 *puVar5;
  ulong uVar6;
  WDFDEVICE_INIT *pWVar7;
  WDFDEVICE_INIT **ppWVar8;
  WDFDEVICE__ *pWVar9;
  undefined8 uVar10;
  undefined8 *puVar11;
  uint uVar12;
  ulonglong uVar13;
  char *pcVar14;
  undefined8 *puVar15;
  undefined1 auStackY_208 [32];
  undefined1 uVar16;
  WDFDEVICE_INIT *local_1c8 [2];
  undefined4 local_1b8;
  undefined4 local_1b4;
  undefined4 local_1b0;
  code *local_1a8;
  undefined4 local_1a0;
  undefined4 local_19c;
  code *local_198;
  code *local_190;
  code *local_188;
  code *local_180;
  code *local_178;
  WDFDEVICE__ *local_168;
  code *local_160;
  undefined4 local_158 [2];
  code *local_150;
  undefined4 local_148;
  code *local_140;
  code *local_138;
  code *local_130;
  code *local_128;
  code *local_120;
  code *local_110;
  undefined4 local_fc;
  code *local_e8;
  undefined4 local_c8 [6];
  undefined4 local_b0;
  undefined4 local_ac;
  undefined *local_98;
  undefined4 local_90 [6];
  undefined4 local_78;
  undefined4 local_74;
  undefined8 local_70;
  undefined8 local_58;
  code *local_50;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_208;
  pWVar7 = param_2;
  local_1c8[0] = param_2;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    pWVar7 = (WDFDEVICE_INIT *)0x10;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
            &WPP_04e4e9a7170d36ab7d7da83381215d59_Traceguids);
  }
  pcVar2 = SpbFunctions;
  local_168 = (WDFDEVICE__ *)0x0;
  ChvP1I2c_ControllerIoGenerateStart((PBC_DEVICE *)SpbFunctions,(ulong)pWVar7);
  iVar4 = (*pcVar2)(SpbDriverGlobals);
  if (iVar4 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar4;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_14000a1a4;
    uVar12 = 0x11;
LAB_14000980a:
    pWVar7 = local_1c8[0];
  }
  else {
    uVar6 = 0;
    memset(local_158,0,0x90);
    local_158[0] = 0x90;
    local_130 = OnPrepareHardware;
    local_128 = OnReleaseHardware;
    local_150 = OnD0Entry;
    local_140 = OnD0Exit;
    local_e8 = OnDeviceQueryStop;
    local_110 = OnSelfManagedIoInit;
    local_120 = OnSelfManagedIoCleanup;
    pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x1b8);
    ChvP1I2c_ControllerIoGenerateStart(pPVar1,uVar6);
    (*(code *)pPVar1)(WdfDriverGlobals,local_1c8[0],local_158);
    uVar6 = 0;
    memset(local_c8,0,0x38);
    local_98 = PTR__WDF_PBC_DEVICE_TYPE_INFO_140016020;
    local_c8[0] = 0x38;
    local_b0 = 1;
    local_ac = 1;
    pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 600);
    ChvP1I2c_ControllerIoGenerateStart(pPVar1,uVar6);
    ppWVar8 = local_1c8;
    iVar4 = (*(code *)pPVar1)(WdfDriverGlobals,ppWVar8,local_c8,&local_168);
    if (iVar4 < 0) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return iVar4;
      }
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
      goto LAB_14000a1a4;
      uVar12 = 0x12;
      goto LAB_14000980a;
    }
    pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x650);
    ChvP1I2c_ControllerIoGenerateStart(pPVar1,(ulong)ppWVar8);
    pWVar9 = local_168;
    puVar5 = (undefined8 *)
             (*(code *)pPVar1)(WdfDriverGlobals,local_168,PTR__WDF_PBC_DEVICE_TYPE_INFO_140016020);
    uVar6 = (ulong)pWVar9;
    if (puVar5 == (undefined8 *)0x0) {
      iVar4 = -0x3fffffff;
      goto LAB_14000a1a4;
    }
    *puVar5 = local_168;
    iVar4 = LpssApi_VerifyHardware(local_168);
    if (iVar4 < 0) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return iVar4;
      }
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
      {
        uVar12 = 0x13;
LAB_14000a194:
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar12,
                &WPP_04e4e9a7170d36ab7d7da83381215d59_Traceguids);
      }
      goto LAB_14000a1a4;
    }
    pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x260);
    ChvP1I2c_ControllerIoGenerateStart(pPVar1,uVar6);
    uVar10 = *puVar5;
    (*(code *)pPVar1)(WdfDriverGlobals,uVar10,0);
    uStack_44 = 2;
    local_58 = 0x20000001c;
    local_50 = (code *)0x200000002;
    local_40 = 2;
    local_48 = 1;
    pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0xe8);
    ChvP1I2c_ControllerIoGenerateStart(pPVar1,(ulong)uVar10);
    (*(code *)pPVar1)(WdfDriverGlobals,*puVar5,&local_58);
    if (*(char *)((longlong)puVar5 + 0x41) != '\0') {
      InitMbiSemaphoreLock();
      *(undefined1 *)(puVar5 + 8) = 0;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
                &WPP_04e4e9a7170d36ab7d7da83381215d59_Traceguids);
      }
    }
    uVar6 = 0;
    memset(&local_1b8,0,0x48);
    local_1a8 = OnTargetConnect;
    local_188 = OnRead;
    local_180 = OnWrite;
    local_178 = OnSequence;
    local_1b8 = 0x48;
    local_1b4 = 1;
    local_1b0 = 1;
    uVar3 = LpssApi_VerifySpbLockSupport((WDFDEVICE__ *)*puVar5);
    pcVar2 = DAT_1400164c8;
    if (uVar3 != '\0') {
      local_198 = OnControllerLock;
      local_190 = OnControllerUnlock;
    }
    uVar10 = *puVar5;
    ChvP1I2c_ControllerIoGenerateStart((PBC_DEVICE *)DAT_1400164c8,uVar6);
    iVar4 = (*pcVar2)(SpbDriverGlobals,uVar10,&local_1b8);
    if (iVar4 < 0) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return iVar4;
      }
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
      goto LAB_14000a1a4;
      uVar12 = 0x15;
    }
    else {
      uVar6 = 0;
      memset(&local_1b8,0,0x38);
      pcVar2 = DAT_1400164e0;
      local_188 = (code *)PTR__WDF_PBC_TARGET_TYPE_INFO_140016048;
      local_1b8 = 0x38;
      local_1a0 = 1;
      local_19c = 1;
      ChvP1I2c_ControllerIoGenerateStart((PBC_DEVICE *)DAT_1400164e0,uVar6);
      (*pcVar2)(SpbDriverGlobals,*puVar5,&local_1b8);
      uVar6 = 0;
      memset(&local_1b8,0,0x38);
      pcVar2 = DAT_1400164d8;
      local_188 = (code *)PTR__WDF_PBC_REQUEST_TYPE_INFO_140016070;
      local_1b8 = 0x38;
      local_1a0 = 1;
      local_19c = 1;
      ChvP1I2c_ControllerIoGenerateStart((PBC_DEVICE *)DAT_1400164d8,uVar6);
      (*pcVar2)(SpbDriverGlobals,*puVar5,&local_1b8);
      uVar6 = 0;
      memset(&local_1b8,0,0x38);
      local_198 = (code *)*puVar5;
      local_1b8 = 0x38;
      local_1a0 = 1;
      local_19c = 1;
      pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x9d8);
      ChvP1I2c_ControllerIoGenerateStart(pPVar1,uVar6);
      iVar4 = (*(code *)pPVar1)(WdfDriverGlobals,&local_1b8,&local_160);
      if (iVar4 < 0) {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return iVar4;
        }
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14000a1a4;
        uVar12 = 0x16;
      }
      else {
        uVar6 = 0;
        memset(local_158,0,0x68);
        uVar10 = *puVar5;
        local_140 = OnInterruptIsr;
        local_138 = OnInterruptDpc;
        local_150 = local_160;
        local_158[0] = 0x68;
        local_148 = 2;
        local_fc = 1;
        pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x468);
        ChvP1I2c_ControllerIoGenerateStart(pPVar1,uVar6);
        iVar4 = (*(code *)pPVar1)(WdfDriverGlobals,uVar10,local_158,0);
        if (iVar4 < 0) {
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return iVar4;
          }
          if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14000a1a4;
          uVar12 = 0x17;
        }
        else {
          memset(&local_58,0,0x28);
          local_48 = 0;
          local_40 = 0;
          local_50 = ControllerWatchdogTimerExpired;
          uVar6 = 0;
          local_58 = CONCAT44(local_58._4_4_,0x28);
          uStack_44 = CONCAT31(uStack_44._1_3_,1);
          memset(&local_1b8,0,0x38);
          local_198 = (code *)*puVar5;
          local_1b8 = 0x38;
          local_1a0 = 1;
          local_19c = 1;
          pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x9f0);
          ChvP1I2c_ControllerIoGenerateStart(pPVar1,uVar6);
          iVar4 = (*(code *)pPVar1)(WdfDriverGlobals,&local_58,&local_1b8,puVar5 + 9);
          if (iVar4 < 0) {
            if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
              return iVar4;
            }
            if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) ||
               ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14000a1a4;
            uVar12 = 0x18;
          }
          else {
            uVar6 = 0;
            memset(local_90,0,0x38);
            local_90[0] = 0x38;
            local_78 = 1;
            local_74 = 1;
            local_70 = *puVar5;
            pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x9d8);
            ChvP1I2c_ControllerIoGenerateStart(pPVar1,uVar6);
            iVar4 = (*(code *)pPVar1)(WdfDriverGlobals,local_90,puVar5 + 7);
            if (iVar4 < 0) {
              if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
                return iVar4;
              }
              if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) ||
                 ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14000a1a4;
              uVar12 = 0x19;
            }
            else {
              uVar6 = 0;
              memset(&local_58,0,0x24);
              uVar10 = *puVar5;
              local_40 = 2;
              local_38 = 2;
              local_58 = 0x100000024;
              local_3c = 2;
              local_48 = 1;
              local_50 = (code *)0x7d000000004;
              uStack_44 = 1;
              pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x170);
              ChvP1I2c_ControllerIoGenerateStart(pPVar1,uVar6);
              iVar4 = (*(code *)pPVar1)(WdfDriverGlobals,uVar10,&local_58);
              if (-1 < iVar4) {
                *(undefined4 *)(puVar5 + 0x60) = 0;
                puVar15 = puVar5 + 0x5d;
                *(undefined4 *)((longlong)puVar5 + 0x304) = 0;
                *(undefined4 *)(puVar5 + 0x61) = 0;
                *(undefined4 *)((longlong)puVar5 + 0x30c) = 0;
                uVar13 = 0;
                do {
                  uVar6 = 0;
                  memset(&local_1b8,0,0x38);
                  local_188 = (code *)PTR__WDF_LPSS_WORK_ITEM_CONTEXT_TYPE_INFO_1400160c0;
                  local_198 = (code *)*puVar5;
                  uStack_44 = 0;
                  local_50 = SequenceIoctlWorker;
                  local_1b8 = 0x38;
                  local_1a0 = 1;
                  local_19c = 1;
                  local_58 = 0x18;
                  local_48 = 1;
                  pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0xbd8);
                  ChvP1I2c_ControllerIoGenerateStart(pPVar1,uVar6);
                  puVar11 = &local_58;
                  iVar4 = (*(code *)pPVar1)(WdfDriverGlobals,puVar11,&local_1b8,
                                            puVar5 + uVar13 + 0x5a);
                  if (iVar4 < 0) {
                    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
                      return iVar4;
                    }
                    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
                       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                      uVar12 = 0x1b;
                      goto LAB_14000a194;
                    }
                    break;
                  }
                  pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x650);
                  ChvP1I2c_ControllerIoGenerateStart(pPVar1,(ulong)puVar11);
                  (*(code *)pPVar1)(WdfDriverGlobals,puVar15[-3],
                                    PTR__WDF_LPSS_WORK_ITEM_CONTEXT_TYPE_INFO_1400160c0);
                  uVar6 = 0;
                  memset(&local_1b8,0,0x38);
                  local_188 = (code *)PTR__WDF_LPSS_WORK_ITEM_CONTEXT_TYPE_INFO_1400160c0;
                  local_198 = (code *)*puVar5;
                  uStack_44 = 0;
                  local_50 = NonSequenceIoctlWorker;
                  local_1b8 = 0x38;
                  local_1a0 = 1;
                  local_19c = 1;
                  local_48 = 1;
                  local_58 = 0x18;
                  pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0xbd8);
                  ChvP1I2c_ControllerIoGenerateStart(pPVar1,uVar6);
                  puVar11 = &local_58;
                  iVar4 = (*(code *)pPVar1)(WdfDriverGlobals,puVar11,&local_1b8,
                                            puVar5 + uVar13 + 0x5d);
                  if (iVar4 < 0) {
                    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
                      return iVar4;
                    }
                    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
                       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                      uVar12 = 0x1c;
                      goto LAB_14000a194;
                    }
                    break;
                  }
                  pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x650);
                  ChvP1I2c_ControllerIoGenerateStart(pPVar1,(ulong)puVar11);
                  (*(code *)pPVar1)(WdfDriverGlobals,*puVar15,
                                    PTR__WDF_LPSS_WORK_ITEM_CONTEXT_TYPE_INFO_1400160c0);
                  puVar15 = puVar15 + 1;
                  uVar12 = (int)uVar13 + 1;
                  uVar13 = (ulonglong)uVar12;
                } while (uVar12 < 3);
                goto LAB_14000a1a4;
              }
              if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
                return iVar4;
              }
              if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) ||
                 ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14000a1a4;
              uVar12 = 0x1a;
            }
          }
        }
      }
    }
    pWVar7 = (WDFDEVICE_INIT *)*puVar5;
  }
  WPP_SF_xd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar12,
            &WPP_04e4e9a7170d36ab7d7da83381215d59_Traceguids,pWVar7,(char)iVar4);
LAB_14000a1a4:
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      pcVar14 = "Failed";
      if (-1 < iVar4) {
        pcVar14 = "Success";
      }
      uVar16 = (undefined1)g_DriverInstance;
      g_DriverInstance = g_DriverInstance + 1;
      WPP_SF_sLqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
                  &WPP_04e4e9a7170d36ab7d7da83381215d59_Traceguids,pcVar14,uVar16,(char)local_168,
                  (char)iVar4);
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
              &WPP_04e4e9a7170d36ab7d7da83381215d59_Traceguids);
    }
  }
  return iVar4;
}



===== OnDriverCleanup @ 14000a270 =====

/* void __cdecl OnDriverCleanup(void * __ptr64) */

void __cdecl OnDriverCleanup(void *param_1)

{
  undefined8 in_RDX;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    in_RDX = 0xe;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
            &WPP_04e4e9a7170d36ab7d7da83381215d59_Traceguids);
  }
  DeInitMbiSemaphoreLock();
  WppCleanupKm(0,in_RDX);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
            &WPP_04e4e9a7170d36ab7d7da83381215d59_Traceguids);
  }
  return;
}



===== DriverEntry @ 14000a2ec =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(ulonglong param_1,undefined8 param_2)

{
  PBC_DEVICE *pPVar1;
  int iVar2;
  ulong uVar3;
  undefined8 local_res18;
  undefined4 local_78 [2];
  code *local_70;
  undefined4 local_5c;
  undefined4 local_58 [2];
  code *local_50;
  undefined4 local_40;
  undefined4 local_3c;
  
  _DAT_140016238 = 1;
  _WPP_MAIN_CB = 0;
  DAT_140016218 = &WPP_ThisDir_CTLGUID_LpssTraceGuid;
  DAT_140016220 = 0;
  _DAT_140016230 = 0;
  WppLoadTracingSupport();
  _DAT_140016230 = 0;
  WppInitKm(param_1,param_2);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_04e4e9a7170d36ab7d7da83381215d59_Traceguids);
  }
  memset(local_78,0,0x20);
  local_78[0] = 0x20;
  local_70 = OnDeviceAdd;
  local_5c = 0x53504c69;
  uVar3 = 0;
  memset(local_58,0,0x38);
  local_58[0] = 0x38;
  local_50 = OnDriverCleanup;
  local_40 = 1;
  local_3c = 1;
  pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x3a0);
  ChvP1I2c_ControllerIoGenerateStart(pPVar1,uVar3);
  iVar2 = (*(code *)pPVar1)(WdfDriverGlobals,param_1,param_2,local_58,local_78,&local_res18);
  if (iVar2 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (param_1 = (ulonglong)*(uint *)(WPP_GLOBAL_Control + 0x2c),
        (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      param_1 = 0xb;
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
               &WPP_04e4e9a7170d36ab7d7da83381215d59_Traceguids,iVar2);
    }
    WppCleanupKm(0,param_1);
  }
  else {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar2;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_P(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
               &WPP_04e4e9a7170d36ab7d7da83381215d59_Traceguids,local_res18);
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
            &WPP_04e4e9a7170d36ab7d7da83381215d59_Traceguids);
  }
  return iVar2;
}



===== WPP_SF_sLqd @ 14000a4e0 =====

void WPP_SF_sLqd(undefined8 param_1,uint param_2,undefined8 param_3,char *param_4,undefined1 param_5
                ,undefined1 param_6,undefined1 param_7)

{
  PBC_DEVICE *pPVar1;
  char *pcVar2;
  longlong lVar3;
  longlong lVar4;
  
  pPVar1 = pfnWppTraceMessage;
  if (param_4 == (char *)0x0) {
    lVar4 = 5;
  }
  else {
    lVar3 = -1;
    do {
      lVar4 = lVar3;
      lVar3 = lVar4 + 1;
    } while (param_4[lVar3] != '\0');
    lVar4 = lVar4 + 2;
  }
  pcVar2 = "NULL";
  if (param_4 != (char *)0x0) {
    pcVar2 = param_4;
  }
  ChvP1I2c_ControllerIoGenerateStart(pfnWppTraceMessage,param_2);
  (*(code *)pPVar1)(param_1,0x2b,param_3,(short)param_2,pcVar2,lVar4,&param_5,4,&param_6,8,&param_7,
                    4,0);
  return;
}



===== WppClassicProviderCallback @ 14000a5c0 =====

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



===== Read @ 14000a5f0 =====

/* public: unsigned long __cdecl HWREG<unsigned long>::Read(void) __ptr64 */

ulong __thiscall HWREG<unsigned_long>::Read(HWREG<unsigned_long> *this)

{
  return *(ulong *)this;
}



===== Write @ 14000a5f4 =====

/* public: unsigned long __cdecl HWREG<unsigned long>::Write(unsigned long) __ptr64 */

ulong __thiscall HWREG<unsigned_long>::Write(HWREG<unsigned_long> *this,ulong param_1)

{
  *(ulong *)this = param_1;
  LOCK();
  UNLOCK();
  return param_1;
}



===== DmaCheckOp @ 14000a600 =====

/* void __cdecl DmaCheckOp(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST * __ptr64) */

void __cdecl DmaCheckOp(PBC_DEVICE *param_1,PBC_REQUEST *param_2)

{
  PBC_DEVICE PVar1;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
            &WPP_ac8c47c7753634169521ea773b2de5d0_Traceguids);
  }
  param_1[800] = (PBC_DEVICE)0x0;
  if ((*(int *)(param_1 + 0x318) == 2) && (3 < *(uint *)(param_1 + 0x31c))) {
    PVar1 = param_1[800];
    if ((ulonglong)*(uint *)(param_1 + 0x31c) <= *(ulonglong *)(param_2 + 0x28)) {
      PVar1 = (PBC_DEVICE)0x1;
    }
    param_1[800] = PVar1;
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
            &WPP_ac8c47c7753634169521ea773b2de5d0_Traceguids);
  }
  return;
}



===== DmaInitialize @ 14000a6bc =====

/* long __cdecl DmaInitialize(struct PBC_DEVICE * __ptr64) */

long __cdecl DmaInitialize(PBC_DEVICE *param_1)

{
  PBC_DEVICE *pPVar1;
  long lVar2;
  int iVar3;
  longlong lVar4;
  uint uVar5;
  ulong uVar6;
  undefined4 *puVar7;
  undefined8 uVar8;
  longlong lVar9;
  undefined4 local_58 [6];
  undefined4 local_40;
  undefined4 local_3c;
  undefined8 local_38;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
            &WPP_ac8c47c7753634169521ea773b2de5d0_Traceguids);
  }
  if (*(int *)(param_1 + 0x318) == 2) {
    lVar2 = SysDmaCreateEnablerObjects(param_1);
    if (-1 < lVar2) {
      lVar2 = SysDmaConfigureSystemProfile
                        (param_1,*(_CM_PARTIAL_RESOURCE_DESCRIPTOR **)(param_1 + 0x340),1);
      if (-1 < lVar2) {
        lVar2 = SysDmaConfigureSystemProfile
                          (param_1,*(_CM_PARTIAL_RESOURCE_DESCRIPTOR **)(param_1 + 0x348),0);
        if (-1 < lVar2) {
          lVar2 = SysDmaCreateTransactionObjects(param_1);
          if (-1 < lVar2) {
            uVar6 = 0;
            memset(local_58,0,0x38);
            local_38 = *(undefined8 *)param_1;
            local_58[0] = 0x38;
            local_40 = 1;
            local_3c = 1;
            pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x9d8);
            ChvP1I2c_ControllerIoGenerateStart(pPVar1,uVar6);
            puVar7 = local_58;
            iVar3 = (*(code *)pPVar1)(WdfDriverGlobals,puVar7,param_1 + 0x328);
            if (iVar3 < 0) {
              if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                 (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
                         &WPP_ac8c47c7753634169521ea773b2de5d0_Traceguids,iVar3);
              }
            }
            else {
              pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x308);
              ChvP1I2c_ControllerIoGenerateStart(pPVar1,(ulong)puVar7);
              uVar8 = *(undefined8 *)(param_1 + 0x330);
              (*(code *)pPVar1)(WdfDriverGlobals,uVar8,1);
              pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x308);
              ChvP1I2c_ControllerIoGenerateStart(pPVar1,(ulong)uVar8);
              (*(code *)pPVar1)(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x338),1);
              lVar4 = MmAllocateContiguousMemorySpecifyCache(0xffa,0,0xffffffffffffffff,0,0);
              *(longlong *)(param_1 + 0x350) = lVar4;
              if (lVar4 == 0) {
                if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_14000a937;
                if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0) &&
                   (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                  uVar5 = 0x15;
                  goto LAB_14000a748;
                }
                goto LAB_14000a90d;
              }
              lVar4 = 1;
              lVar9 = 0x7fd;
              do {
                *(undefined1 *)(lVar4 + *(longlong *)(param_1 + 0x350)) = 1;
                lVar4 = lVar4 + 2;
                lVar9 = lVar9 + -1;
              } while (lVar9 != 0);
              iVar3 = LpssApi_DmaInitialize(param_1);
            }
            if (-1 < iVar3) goto LAB_14000a95a;
          }
        }
      }
    }
LAB_14000a90d:
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
       (2 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
              &WPP_ac8c47c7753634169521ea773b2de5d0_Traceguids);
    }
  }
  else if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      uVar5 = 0x13;
LAB_14000a748:
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,
              &WPP_ac8c47c7753634169521ea773b2de5d0_Traceguids);
    }
    goto LAB_14000a90d;
  }
LAB_14000a937:
  *(undefined4 *)(param_1 + 0x318) = 0;
  iVar3 = 0;
  if (*(longlong *)(param_1 + 0x350) != 0) {
    MmFreeContiguousMemory();
    *(undefined8 *)(param_1 + 0x350) = 0;
  }
LAB_14000a95a:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
            &WPP_ac8c47c7753634169521ea773b2de5d0_Traceguids);
  }
  return iVar3;
}



===== DmaInitializeSettings @ 14000a9a4 =====

/* void __cdecl DmaInitializeSettings(struct PBC_DEVICE * __ptr64) */

void __cdecl DmaInitializeSettings(PBC_DEVICE *param_1)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_ac8c47c7753634169521ea773b2de5d0_Traceguids);
  }
  *(undefined8 *)(param_1 + 0x318) = 0;
  *(undefined8 *)(param_1 + 0x350) = 0;
  *(undefined8 *)(param_1 + 0x330) = 0;
  *(undefined8 *)(param_1 + 0x338) = 0;
  param_1[800] = (PBC_DEVICE)0x0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
            &WPP_ac8c47c7753634169521ea773b2de5d0_Traceguids);
  }
  return;
}



===== DmaUninitialize @ 14000aa44 =====

/* long __cdecl DmaUninitialize(struct PBC_DEVICE * __ptr64) */

long __cdecl DmaUninitialize(PBC_DEVICE *param_1)

{
  PBC_DEVICE *pPVar1;
  undefined1 uVar2;
  long lVar3;
  int iVar4;
  longlong lVar5;
  longlong lVar6;
  uint in_EDX;
  ulong in_CR8;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    in_EDX = 0xe;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
            &WPP_ac8c47c7753634169521ea773b2de5d0_Traceguids);
  }
  lVar3 = LpssApi_DmaUninitialize(param_1);
  lVar6 = *(longlong *)(param_1 + 0x380);
  if ((lVar6 != 0) && (param_1[0x358] != (PBC_DEVICE)0x0)) {
    pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x330);
    ChvP1I2c_ControllerIoGenerateStart(pPVar1,in_EDX);
    iVar4 = (*(code *)pPVar1)(WdfDriverGlobals);
    in_EDX = (uint)lVar6;
    if (((iVar4 < 0) &&
        (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control &&
         (in_EDX = *(uint *)(WPP_GLOBAL_Control + 0x2c), (in_EDX & 0x20) != 0)))) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      in_EDX = 0xf;
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
               &WPP_ac8c47c7753634169521ea773b2de5d0_Traceguids,iVar4);
    }
    param_1[0x358] = (PBC_DEVICE)0x0;
  }
  lVar6 = *(longlong *)(param_1 + 0x330);
  if (lVar6 != 0) {
    pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0xc08);
    ChvP1I2c_ControllerIoGenerateStart(pPVar1,in_EDX);
    lVar5 = (*(code *)pPVar1)(WdfDriverGlobals,lVar6,1);
    in_EDX = (uint)lVar6;
    if (lVar5 != 0) {
      if ((byte)in_CR8 < 2) {
        uVar2 = KfRaiseIrql(2);
        pPVar1 = *(PBC_DEVICE **)(*(longlong *)(lVar5 + 8) + 0x30);
        ChvP1I2c_ControllerIoGenerateStart(pPVar1,in_EDX);
        (*(code *)pPVar1)(lVar5);
        KeLowerIrql(uVar2);
      }
      else {
        pPVar1 = *(PBC_DEVICE **)(*(longlong *)(lVar5 + 8) + 0x30);
        ChvP1I2c_ControllerIoGenerateStart(pPVar1,in_EDX);
        (*(code *)pPVar1)(lVar5);
      }
      pPVar1 = *(PBC_DEVICE **)(*(longlong *)(lVar5 + 8) + 8);
      ChvP1I2c_ControllerIoGenerateStart(pPVar1,in_EDX);
      (*(code *)pPVar1)(lVar5);
    }
  }
  if (*(longlong *)(param_1 + 0x350) != 0) {
    MmFreeContiguousMemory();
    *(undefined8 *)(param_1 + 0x350) = 0;
  }
  lVar6 = *(longlong *)(param_1 + 0x388);
  if ((lVar6 != 0) && (param_1[0x359] != (PBC_DEVICE)0x0)) {
    pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x330);
    ChvP1I2c_ControllerIoGenerateStart(pPVar1,in_EDX);
    iVar4 = (*(code *)pPVar1)(WdfDriverGlobals);
    in_EDX = (uint)lVar6;
    if ((iVar4 < 0) &&
       ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control &&
         (in_EDX = *(uint *)(WPP_GLOBAL_Control + 0x2c), (in_EDX & 0x20) != 0)) &&
        (1 < (byte)WPP_GLOBAL_Control[0x29])))) {
      in_EDX = 0x10;
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
               &WPP_ac8c47c7753634169521ea773b2de5d0_Traceguids,iVar4);
    }
    param_1[0x359] = (PBC_DEVICE)0x0;
  }
  lVar6 = *(longlong *)(param_1 + 0x338);
  if (lVar6 != 0) {
    pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0xc08);
    ChvP1I2c_ControllerIoGenerateStart(pPVar1,in_EDX);
    lVar6 = (*(code *)pPVar1)(WdfDriverGlobals,lVar6,0);
    if (lVar6 != 0) {
      if ((byte)in_CR8 < 2) {
        uVar2 = KfRaiseIrql(2);
        pPVar1 = *(PBC_DEVICE **)(*(longlong *)(lVar6 + 8) + 0x30);
        ChvP1I2c_ControllerIoGenerateStart(pPVar1,in_CR8);
        (*(code *)pPVar1)(lVar6);
        KeLowerIrql(uVar2);
      }
      else {
        pPVar1 = *(PBC_DEVICE **)(*(longlong *)(lVar6 + 8) + 0x30);
        ChvP1I2c_ControllerIoGenerateStart(pPVar1,in_CR8);
        (*(code *)pPVar1)(lVar6);
      }
      pPVar1 = *(PBC_DEVICE **)(*(longlong *)(lVar6 + 8) + 8);
      ChvP1I2c_ControllerIoGenerateStart(pPVar1,in_CR8);
      (*(code *)pPVar1)(lVar6);
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
            &WPP_ac8c47c7753634169521ea773b2de5d0_Traceguids);
  }
  return lVar3;
}



===== SysDmaConfigureChannel @ 14000ad40 =====

/* unsigned char __cdecl SysDmaConfigureChannel(struct WDFDMATRANSACTION__ * __ptr64,struct
   WDFDEVICE__ * __ptr64,void * __ptr64,struct _MDL * __ptr64,unsigned __int64,unsigned __int64) */

uchar __cdecl
SysDmaConfigureChannel
          (WDFDMATRANSACTION__ *param_1,WDFDEVICE__ *param_2,void *param_3,_MDL *param_4,
          __uint64 param_5,__uint64 param_6)

{
  PBC_DEVICE *pPVar1;
  int iVar2;
  longlong *plVar3;
  longlong lVar4;
  undefined8 *puVar5;
  longlong lVar6;
  ulonglong uVar7;
  ulong uVar8;
  uint uVar9;
  WDFDEVICE__ *pWVar10;
  ulonglong uVar11;
  undefined8 uVar12;
  int local_28 [4];
  
  pWVar10 = param_2;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    pWVar10 = (WDFDEVICE__ *)0x23;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,
            &WPP_ac8c47c7753634169521ea773b2de5d0_Traceguids);
  }
  local_28[0] = 1;
  pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x650);
  ChvP1I2c_ControllerIoGenerateStart(pPVar1,(ulong)pWVar10);
  plVar3 = (longlong *)
           (*(code *)pPVar1)(WdfDriverGlobals,param_1,
                             PTR__WDF_DMA_TRANSACTION_CONTEXT_TYPE_INFO_140016098);
  uVar8 = (ulong)param_1;
  *(undefined4 *)(plVar3 + 4) = 0;
  if ((int)plVar3[2] == 1) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      uVar8 = 0x24;
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x24,
              &WPP_ac8c47c7753634169521ea773b2de5d0_Traceguids);
    }
    uVar11 = *(ulonglong *)(*plVar3 + 0x330);
    pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0xc08);
    ChvP1I2c_ControllerIoGenerateStart(pPVar1,uVar8);
    lVar4 = (*(code *)pPVar1)(WdfDriverGlobals,uVar11,1);
    uVar7 = param_5 & 0xffffffff;
    iVar2 = 0;
    for (puVar5 = (undefined8 *)plVar3[5]; uVar9 = (uint)uVar11, puVar5 != (undefined8 *)0x0;
        puVar5 = (undefined8 *)*puVar5) {
      uVar9 = *(uint *)(puVar5 + 5);
      uVar11 = (ulonglong)uVar9;
      if (uVar7 < uVar11) break;
      iVar2 = iVar2 + 1;
      uVar7 = uVar7 - uVar11;
    }
    pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x650);
    ChvP1I2c_ControllerIoGenerateStart(pPVar1,uVar9);
    lVar6 = (*(code *)pPVar1)(WdfDriverGlobals,param_2,PTR__WDF_PBC_DEVICE_TYPE_INFO_140016020);
    uVar8 = (ulong)param_2;
    if ((iVar2 == 0) && (param_5 == 0)) {
      uVar8 = *(ulong *)(lVar6 + 0x374);
      HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(lVar6 + 8) + 0x10),uVar8);
      *(longlong *)(lVar6 + 0x360) = *(longlong *)(lVar6 + 0x360) + 1;
    }
    local_28[0] = (*(int *)(plVar3[1] + 0x44) != 2) + 1;
  }
  else {
    if ((int)plVar3[2] != 0) goto LAB_14000aff9;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      uVar8 = 0x25;
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x25,
              &WPP_ac8c47c7753634169521ea773b2de5d0_Traceguids);
    }
    uVar12 = *(undefined8 *)(*plVar3 + 0x338);
    pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0xc08);
    ChvP1I2c_ControllerIoGenerateStart(pPVar1,uVar8);
    lVar4 = (*(code *)pPVar1)(WdfDriverGlobals,uVar12,0);
    uVar8 = (ulong)uVar12;
    local_28[0] = 1;
  }
  if (lVar4 == 0) goto LAB_14000aff9;
  pPVar1 = *(PBC_DEVICE **)(*(longlong *)(lVar4 + 8) + 0xa8);
  ChvP1I2c_ControllerIoGenerateStart(pPVar1,uVar8);
  uVar8 = 3;
  iVar2 = (*(code *)pPVar1)(lVar4,3,param_3);
  if (iVar2 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return '\x01';
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)
       ) goto LAB_14000aff9;
    uVar9 = 0x26;
  }
  else {
    pPVar1 = *(PBC_DEVICE **)(*(longlong *)(lVar4 + 8) + 0xa8);
    ChvP1I2c_ControllerIoGenerateStart(pPVar1,uVar8);
    iVar2 = (*(code *)pPVar1)(lVar4,1,local_28);
    if (-1 < iVar2) {
      *(int *)(plVar3 + 4) = local_28[0];
      goto LAB_14000aff9;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return '\x01';
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)
       ) goto LAB_14000aff9;
    uVar9 = 0x27;
  }
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar9,
           &WPP_ac8c47c7753634169521ea773b2de5d0_Traceguids,iVar2);
LAB_14000aff9:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x28,
            &WPP_ac8c47c7753634169521ea773b2de5d0_Traceguids);
  }
  return '\x01';
}



===== SysDmaConfigureSystemProfile @ 14000b04c =====

/* long __cdecl SysDmaConfigureSystemProfile(struct PBC_DEVICE * __ptr64,struct
   _CM_PARTIAL_RESOURCE_DESCRIPTOR * __ptr64,enum _WDF_DMA_DIRECTION) */

long __cdecl
SysDmaConfigureSystemProfile
          (PBC_DEVICE *param_1,_CM_PARTIAL_RESOURCE_DESCRIPTOR *param_2,_WDF_DMA_DIRECTION param_3)

{
  int iVar1;
  ulong uVar2;
  undefined8 uVar3;
  PBC_DEVICE *pPVar4;
  undefined8 uVar5;
  undefined4 local_28;
  undefined1 local_24;
  undefined4 local_20;
  undefined8 local_18;
  _CM_PARTIAL_RESOURCE_DESCRIPTOR *local_10;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
            &WPP_ac8c47c7753634169521ea773b2de5d0_Traceguids);
  }
  iVar1 = 0;
  uVar2 = 0;
  memset(&local_28,0,0x20);
  local_18 = *(undefined8 *)(param_1 + 0x18);
  local_28 = 0x20;
  local_20 = 2;
  local_24 = 1;
  local_10 = param_2;
  if (param_3 == 1) {
    uVar3 = *(undefined8 *)(param_1 + 0x330);
    pPVar4 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0xca8);
    ChvP1I2c_ControllerIoGenerateStart(pPVar4,uVar2);
    uVar5 = 1;
  }
  else {
    if (param_3 != 0) goto LAB_14000b170;
    uVar3 = *(undefined8 *)(param_1 + 0x338);
    pPVar4 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0xca8);
    ChvP1I2c_ControllerIoGenerateStart(pPVar4,uVar2);
    uVar5 = 0;
  }
  iVar1 = (*(code *)pPVar4)(WdfDriverGlobals,uVar3,&local_28,uVar5);
  if (iVar1 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar1;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])
       ) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
               &WPP_ac8c47c7753634169521ea773b2de5d0_Traceguids,iVar1);
    }
  }
LAB_14000b170:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
            &WPP_ac8c47c7753634169521ea773b2de5d0_Traceguids);
  }
  return iVar1;
}



===== SysDmaCreateEnablerObjects @ 14000b1bc =====

/* long __cdecl SysDmaCreateEnablerObjects(struct PBC_DEVICE * __ptr64) */

long __cdecl SysDmaCreateEnablerObjects(PBC_DEVICE *param_1)

{
  undefined8 uVar1;
  PBC_DEVICE *pPVar2;
  int iVar3;
  ulong uVar4;
  uint uVar5;
  undefined4 local_68;
  undefined4 local_64;
  undefined8 local_60;
  undefined4 local_24;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
            &WPP_ac8c47c7753634169521ea773b2de5d0_Traceguids);
  }
  uVar4 = 0;
  *(undefined2 *)(param_1 + 0x358) = 0;
  *(undefined8 *)(param_1 + 0x3a0) = 0;
  memset(&local_68,0,0x50);
  uVar1 = *(undefined8 *)param_1;
  local_68 = 0x50;
  local_64 = 7;
  local_60 = 0xffa;
  local_24 = 3;
  pPVar2 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x2f0);
  ChvP1I2c_ControllerIoGenerateStart(pPVar2,uVar4);
  iVar3 = (*(code *)pPVar2)(WdfDriverGlobals,uVar1,&local_68,0,param_1 + 0x330);
  if (iVar3 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar3;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)
       ) goto LAB_14000b35b;
    uVar5 = 0x19;
  }
  else {
    uVar4 = 0;
    memset(&local_68,0,0x50);
    uVar1 = *(undefined8 *)param_1;
    local_68 = 0x50;
    local_64 = 7;
    local_60 = 0xffa;
    local_24 = 3;
    pPVar2 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x2f0);
    ChvP1I2c_ControllerIoGenerateStart(pPVar2,uVar4);
    iVar3 = (*(code *)pPVar2)(WdfDriverGlobals,uVar1,&local_68,0,param_1 + 0x338);
    if (-1 < iVar3) goto LAB_14000b35b;
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar3;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)
       ) goto LAB_14000b35b;
    uVar5 = 0x1a;
  }
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,
           &WPP_ac8c47c7753634169521ea773b2de5d0_Traceguids,iVar3);
LAB_14000b35b:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
            &WPP_ac8c47c7753634169521ea773b2de5d0_Traceguids);
  }
  return iVar3;
}



===== SysDmaCreateTransactionObjects @ 14000b3a8 =====

/* long __cdecl SysDmaCreateTransactionObjects(struct PBC_DEVICE * __ptr64) */

long __cdecl SysDmaCreateTransactionObjects(PBC_DEVICE *param_1)

{
  PBC_DEVICE *pPVar1;
  undefined8 uVar2;
  int iVar3;
  longlong lVar4;
  ulong uVar5;
  uint uVar6;
  undefined8 uVar7;
  undefined4 local_58 [6];
  undefined4 local_40;
  undefined4 local_3c;
  undefined *local_28;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,
            &WPP_ac8c47c7753634169521ea773b2de5d0_Traceguids);
  }
  uVar5 = 0;
  memset(local_58,0,0x38);
  uVar7 = *(undefined8 *)(param_1 + 0x330);
  local_40 = 1;
  local_3c = 1;
  local_28 = PTR__WDF_DMA_TRANSACTION_CONTEXT_TYPE_INFO_140016098;
  local_58[0] = 0x38;
  pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x310);
  ChvP1I2c_ControllerIoGenerateStart(pPVar1,uVar5);
  iVar3 = (*(code *)pPVar1)(WdfDriverGlobals,uVar7,local_58,param_1 + 0x380);
  if (iVar3 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar3;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)
       ) goto LAB_14000b59b;
    uVar6 = 0x20;
  }
  else {
    uVar2 = *(undefined8 *)(param_1 + 0x380);
    pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x650);
    ChvP1I2c_ControllerIoGenerateStart(pPVar1,(ulong)uVar7);
    lVar4 = (*(code *)pPVar1)(WdfDriverGlobals,uVar2,
                              PTR__WDF_DMA_TRANSACTION_CONTEXT_TYPE_INFO_140016098);
    uVar5 = 0;
    *(undefined4 *)(lVar4 + 0x10) = 1;
    memset(local_58,0,0x38);
    local_28 = PTR__WDF_DMA_TRANSACTION_CONTEXT_TYPE_INFO_140016098;
    local_58[0] = 0x38;
    uVar7 = *(undefined8 *)(param_1 + 0x338);
    local_40 = 1;
    local_3c = 1;
    pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x310);
    ChvP1I2c_ControllerIoGenerateStart(pPVar1,uVar5);
    iVar3 = (*(code *)pPVar1)(WdfDriverGlobals,uVar7,local_58,param_1 + 0x388);
    if (-1 < iVar3) {
      uVar2 = *(undefined8 *)(param_1 + 0x388);
      pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x650);
      ChvP1I2c_ControllerIoGenerateStart(pPVar1,(ulong)uVar7);
      lVar4 = (*(code *)pPVar1)(WdfDriverGlobals,uVar2,
                                PTR__WDF_DMA_TRANSACTION_CONTEXT_TYPE_INFO_140016098);
      *(undefined4 *)(lVar4 + 0x10) = 0;
      goto LAB_14000b59b;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar3;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)
       ) goto LAB_14000b59b;
    uVar6 = 0x21;
  }
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,
           &WPP_ac8c47c7753634169521ea773b2de5d0_Traceguids,iVar3);
LAB_14000b59b:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,
            &WPP_ac8c47c7753634169521ea773b2de5d0_Traceguids);
  }
  return iVar3;
}



===== SysDmaTransferCompleteRx @ 14000b5f0 =====

/* void __cdecl SysDmaTransferCompleteRx(struct WDFDMATRANSACTION__ * __ptr64,struct WDFDEVICE__ *
   __ptr64,void * __ptr64,enum _WDF_DMA_DIRECTION,enum DMA_COMPLETION_STATUS) */

void __cdecl
SysDmaTransferCompleteRx
          (WDFDMATRANSACTION__ *param_1,WDFDEVICE__ *param_2,void *param_3,
          _WDF_DMA_DIRECTION param_4,DMA_COMPLETION_STATUS param_5)

{
  PBC_DEVICE *pPVar1;
  longlong lVar2;
  char cVar3;
  uint uVar4;
  longlong lVar5;
  longlong *plVar6;
  longlong lVar7;
  undefined8 uVar8;
  ulong uVar9;
  WDFDEVICE__ *pWVar10;
  WDFDMATRANSACTION__ *pWVar11;
  longlong lVar12;
  undefined4 uVar13;
  int local_res20 [2];
  
  pWVar10 = param_2;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    pWVar10 = (WDFDEVICE__ *)0x33;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x33,
            &WPP_ac8c47c7753634169521ea773b2de5d0_Traceguids);
  }
  local_res20[0] = 0;
  pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x650);
  ChvP1I2c_ControllerIoGenerateStart(pPVar1,(ulong)pWVar10);
  lVar5 = (*(code *)pPVar1)(WdfDriverGlobals,param_2,PTR__WDF_PBC_DEVICE_TYPE_INFO_140016020);
  pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x650);
  ChvP1I2c_ControllerIoGenerateStart(pPVar1,(ulong)param_2);
  pWVar11 = param_1;
  plVar6 = (longlong *)
           (*(code *)pPVar1)(WdfDriverGlobals,param_1,
                             PTR__WDF_DMA_TRANSACTION_CONTEXT_TYPE_INFO_140016098);
  uVar13 = 4;
  if (param_4 == 0) {
    *(undefined4 *)(lVar5 + 0x370) = 0;
    uVar8 = *(undefined8 *)(*plVar6 + 0x338);
    pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0xc08);
    ChvP1I2c_ControllerIoGenerateStart(pPVar1,(ulong)pWVar11);
    lVar7 = (*(code *)pPVar1)(WdfDriverGlobals,uVar8,0);
    lVar2 = plVar6[3];
    pPVar1 = *(PBC_DEVICE **)(*(longlong *)(lVar7 + 8) + 0x50);
    ChvP1I2c_ControllerIoGenerateStart(pPVar1,(ulong)uVar8);
    uVar4 = (*(code *)pPVar1)(lVar7);
    lVar12 = lVar2 - (ulonglong)uVar4;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_Xq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x35,
                &WPP_ac8c47c7753634169521ea773b2de5d0_Traceguids,lVar2,(char)uVar4);
    }
    uVar9 = 0x40016000;
    uVar8 = 0;
    if (param_5 == 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
         (4 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar9 = 0x36;
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x36,
                &WPP_ac8c47c7753634169521ea773b2de5d0_Traceguids);
      }
      lVar2 = *plVar6;
      pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x9e0);
      ChvP1I2c_ControllerIoGenerateStart(pPVar1,uVar9);
      uVar9 = (ulong)*(undefined8 *)(lVar2 + 0x328);
      (*(code *)pPVar1)(WdfDriverGlobals);
      pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x338);
      ChvP1I2c_ControllerIoGenerateStart(pPVar1,uVar9);
      pWVar11 = param_1;
      cVar3 = (*(code *)pPVar1)(WdfDriverGlobals,param_1,local_res20);
      uVar13 = 1;
      LOCK();
      *(uint *)(plVar6[1] + 0x74) = *(uint *)(plVar6[1] + 0x74) | 1;
      UNLOCK();
      if (cVar3 == '\0') {
        lVar5 = *plVar6;
        pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x9e8);
        ChvP1I2c_ControllerIoGenerateStart(pPVar1,(ulong)pWVar11);
        (*(code *)pPVar1)(WdfDriverGlobals,*(undefined8 *)(lVar5 + 0x328));
        goto LAB_14000bb6a;
      }
      LOCK();
      *(uint *)(*plVar6 + 0x3a8) = *(uint *)(*plVar6 + 0x3a8) | 1;
      UNLOCK();
      lVar2 = *plVar6;
      pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x9e8);
      ChvP1I2c_ControllerIoGenerateStart(pPVar1,(ulong)pWVar11);
      uVar9 = (ulong)*(undefined8 *)(lVar2 + 0x328);
      (*(code *)pPVar1)(WdfDriverGlobals);
      if (local_res20[0] < 0) goto LAB_14000b961;
      pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x350);
      ChvP1I2c_ControllerIoGenerateStart(pPVar1,uVar9);
      pWVar11 = param_1;
      uVar8 = (*(code *)pPVar1)(WdfDriverGlobals);
      pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x330);
      ChvP1I2c_ControllerIoGenerateStart(pPVar1,(ulong)pWVar11);
      local_res20[0] = (*(code *)pPVar1)(WdfDriverGlobals);
      uVar4 = (uint)param_1;
      if ((((local_res20[0] < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
          (uVar4 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar4 & 0x20) != 0)) &&
         (2 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar4 = 0x37;
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x37,
                 &WPP_ac8c47c7753634169521ea773b2de5d0_Traceguids,local_res20[0]);
      }
      *(undefined1 *)(lVar5 + 0x359) = 0;
      pPVar1 = *(PBC_DEVICE **)(*(longlong *)(lVar7 + 8) + 0x30);
      ChvP1I2c_ControllerIoGenerateStart(pPVar1,uVar4);
      (*(code *)pPVar1)(lVar7);
      ControllerDestroyMdlForDma(*(_MDL **)(lVar5 + 0x398));
      if (local_res20[0] < 0) {
        uVar13 = 4;
      }
      else {
        LOCK();
        *(uint *)(lVar5 + 0x3a0) = *(uint *)(lVar5 + 0x3a0) | 1;
        UNLOCK();
      }
      *(undefined4 *)(lVar5 + 0x35c) = uVar13;
    }
    else {
      if (param_5 != 1) {
        if (param_5 == 2) goto LAB_14000b7da;
        if (param_5 != 3) goto LAB_14000bb6a;
LAB_14000b961:
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar9 = 0x3a;
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3a,
                  &WPP_ac8c47c7753634169521ea773b2de5d0_Traceguids);
        }
        if (param_5 != 0) {
          *(longlong *)(lVar5 + 0x368) = lVar12;
          pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x348);
          ChvP1I2c_ControllerIoGenerateStart(pPVar1,uVar9);
          pWVar11 = param_1;
          (*(code *)pPVar1)(WdfDriverGlobals,param_1,lVar12,local_res20);
          uVar9 = (ulong)pWVar11;
        }
        pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x330);
        ChvP1I2c_ControllerIoGenerateStart(pPVar1,uVar9);
        local_res20[0] = (*(code *)pPVar1)(WdfDriverGlobals);
        uVar4 = (uint)param_1;
        if (((local_res20[0] < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
           ((uVar4 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar4 & 0x20) != 0 &&
            (2 < (byte)WPP_GLOBAL_Control[0x29])))) {
          uVar4 = 0x3b;
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3b,
                   &WPP_ac8c47c7753634169521ea773b2de5d0_Traceguids,local_res20[0]);
        }
        *(undefined1 *)(lVar5 + 0x359) = 0;
        pPVar1 = *(PBC_DEVICE **)(*(longlong *)(lVar7 + 8) + 0x30);
        ChvP1I2c_ControllerIoGenerateStart(pPVar1,uVar4);
        (*(code *)pPVar1)(lVar7);
        ControllerDestroyMdlForDma(*(_MDL **)(lVar5 + 0x398));
        uVar13 = 4;
        if (-1 < local_res20[0]) {
          uVar13 = 8;
        }
        goto LAB_14000b808;
      }
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x38,
                &WPP_ac8c47c7753634169521ea773b2de5d0_Traceguids);
      }
      *(undefined4 *)(lVar5 + 0x35c) = 2;
    }
  }
  else {
    if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x34,
                &WPP_ac8c47c7753634169521ea773b2de5d0_Traceguids);
      }
LAB_14000b7da:
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x39,
                &WPP_ac8c47c7753634169521ea773b2de5d0_Traceguids);
      }
    }
LAB_14000b808:
    uVar8 = 0;
    *(undefined4 *)(lVar5 + 0x35c) = uVar13;
  }
  *(undefined8 *)(lVar5 + 0x368) = uVar8;
  KeSetEvent(*plVar6 + 0x270,0,0);
LAB_14000bb6a:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3c,
            &WPP_ac8c47c7753634169521ea773b2de5d0_Traceguids);
  }
  return;
}



===== SysDmaTransferCompleteTx @ 14000bbc0 =====

/* void __cdecl SysDmaTransferCompleteTx(struct WDFDMATRANSACTION__ * __ptr64,struct WDFDEVICE__ *
   __ptr64,void * __ptr64,enum _WDF_DMA_DIRECTION,enum DMA_COMPLETION_STATUS) */

void __cdecl
SysDmaTransferCompleteTx
          (WDFDMATRANSACTION__ *param_1,WDFDEVICE__ *param_2,void *param_3,
          _WDF_DMA_DIRECTION param_4,DMA_COMPLETION_STATUS param_5)

{
  PBC_DEVICE *pPVar1;
  undefined1 uVar2;
  char cVar3;
  PBC_DEVICE *pPVar4;
  longlong *plVar5;
  longlong lVar6;
  longlong lVar7;
  ulong uVar8;
  uint uVar9;
  WDFDEVICE__ *pWVar10;
  WDFDMATRANSACTION__ *pWVar11;
  undefined8 uVar12;
  undefined4 uVar13;
  int local_res20 [2];
  
  pWVar10 = param_2;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    pWVar10 = (WDFDEVICE__ *)0x29;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x29,
            &WPP_ac8c47c7753634169521ea773b2de5d0_Traceguids);
  }
  local_res20[0] = 0;
  pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x650);
  ChvP1I2c_ControllerIoGenerateStart(pPVar1,(ulong)pWVar10);
  pPVar4 = (PBC_DEVICE *)
           (*(code *)pPVar1)(WdfDriverGlobals,param_2,PTR__WDF_PBC_DEVICE_TYPE_INFO_140016020);
  pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x650);
  ChvP1I2c_ControllerIoGenerateStart(pPVar1,(ulong)param_2);
  pWVar11 = param_1;
  plVar5 = (longlong *)
           (*(code *)pPVar1)(WdfDriverGlobals,param_1,
                             PTR__WDF_DMA_TRANSACTION_CONTEXT_TYPE_INFO_140016098);
  if (param_4 == 1) {
    *(undefined4 *)(pPVar4 + 0x370) = 1;
    uVar12 = *(undefined8 *)(*plVar5 + 0x330);
    pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0xc08);
    ChvP1I2c_ControllerIoGenerateStart(pPVar1,(ulong)pWVar11);
    lVar6 = (*(code *)pPVar1)(WdfDriverGlobals,uVar12,1);
    lVar7 = plVar5[3];
    pPVar1 = *(PBC_DEVICE **)(*(longlong *)(lVar6 + 8) + 0x50);
    ChvP1I2c_ControllerIoGenerateStart(pPVar1,(ulong)uVar12);
    uVar2 = (*(code *)pPVar1)(lVar6);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_Xq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
                &WPP_ac8c47c7753634169521ea773b2de5d0_Traceguids,lVar7,uVar2);
    }
    uVar8 = 0x40016000;
    if (param_5 == 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
         (4 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar8 = 0x2c;
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2c,
                &WPP_ac8c47c7753634169521ea773b2de5d0_Traceguids);
      }
      lVar7 = *plVar5;
      pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x9e0);
      ChvP1I2c_ControllerIoGenerateStart(pPVar1,uVar8);
      uVar8 = (ulong)*(undefined8 *)(lVar7 + 0x328);
      (*(code *)pPVar1)(WdfDriverGlobals);
      pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x338);
      ChvP1I2c_ControllerIoGenerateStart(pPVar1,uVar8);
      pWVar11 = param_1;
      cVar3 = (*(code *)pPVar1)(WdfDriverGlobals,param_1,local_res20);
      LOCK();
      *(uint *)(plVar5[1] + 0x70) = *(uint *)(plVar5[1] + 0x70) | 1;
      UNLOCK();
      if (cVar3 == '\0') {
        lVar7 = *plVar5;
        pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x9e8);
        ChvP1I2c_ControllerIoGenerateStart(pPVar1,(ulong)pWVar11);
        (*(code *)pPVar1)(WdfDriverGlobals,*(undefined8 *)(lVar7 + 0x328));
        goto LAB_14000bdee;
      }
      LOCK();
      *(uint *)(*plVar5 + 0x3ac) = *(uint *)(*plVar5 + 0x3ac) | 1;
      UNLOCK();
      lVar7 = *plVar5;
      pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x9e8);
      ChvP1I2c_ControllerIoGenerateStart(pPVar1,(ulong)pWVar11);
      uVar8 = (ulong)*(undefined8 *)(lVar7 + 0x328);
      (*(code *)pPVar1)(WdfDriverGlobals);
      if (local_res20[0] < 0) goto LAB_14000bf81;
      pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x350);
      ChvP1I2c_ControllerIoGenerateStart(pPVar1,uVar8);
      pWVar11 = param_1;
      lVar7 = (*(code *)pPVar1)(WdfDriverGlobals);
      pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x330);
      ChvP1I2c_ControllerIoGenerateStart(pPVar1,(ulong)pWVar11);
      local_res20[0] = (*(code *)pPVar1)(WdfDriverGlobals);
      uVar9 = (uint)param_1;
      if ((((local_res20[0] < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
          (uVar9 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar9 & 0x20) != 0)) &&
         (2 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar9 = 0x2d;
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2d,
                 &WPP_ac8c47c7753634169521ea773b2de5d0_Traceguids,local_res20[0]);
      }
      pPVar4[0x358] = (PBC_DEVICE)0x0;
      pPVar1 = *(PBC_DEVICE **)(*(longlong *)(lVar6 + 8) + 0x30);
      ChvP1I2c_ControllerIoGenerateStart(pPVar1,uVar9);
      (*(code *)pPVar1)(lVar6);
      ControllerDestroyMdlForDma(*(_MDL **)(pPVar4 + 0x390));
      *(longlong *)(pPVar4 + 0x360) = *(longlong *)(pPVar4 + 0x360) + lVar7;
      if (-1 < local_res20[0]) {
        LpssApi_DmaPostCompletion(pPVar4);
        goto LAB_14000bdd9;
      }
      goto LAB_14000bdd2;
    }
    if (param_5 == 1) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2e,
                &WPP_ac8c47c7753634169521ea773b2de5d0_Traceguids);
      }
      *(undefined8 *)(pPVar4 + 0x360) = 0;
      *(undefined4 *)(pPVar4 + 0x35c) = 2;
    }
    else {
      if (param_5 == 2) goto LAB_14000bd9c;
      if (param_5 != 3) goto LAB_14000bdee;
LAB_14000bf81:
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar8 = 0x30;
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x30,
                &WPP_ac8c47c7753634169521ea773b2de5d0_Traceguids);
      }
      if (param_5 != 0) {
        pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x348);
        ChvP1I2c_ControllerIoGenerateStart(pPVar1,uVar8);
        pWVar11 = param_1;
        (*(code *)pPVar1)(WdfDriverGlobals,param_1,0,local_res20);
        uVar8 = (ulong)pWVar11;
      }
      pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x330);
      ChvP1I2c_ControllerIoGenerateStart(pPVar1,uVar8);
      local_res20[0] = (*(code *)pPVar1)(WdfDriverGlobals);
      uVar9 = (uint)param_1;
      if ((((local_res20[0] < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
          (uVar9 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar9 & 0x20) != 0)) &&
         (2 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar9 = 0x31;
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x31,
                 &WPP_ac8c47c7753634169521ea773b2de5d0_Traceguids,local_res20[0]);
      }
      pPVar4[0x358] = (PBC_DEVICE)0x0;
      pPVar1 = *(PBC_DEVICE **)(*(longlong *)(lVar6 + 8) + 0x30);
      ChvP1I2c_ControllerIoGenerateStart(pPVar1,uVar9);
      (*(code *)pPVar1)(lVar6);
      ControllerDestroyMdlForDma(*(_MDL **)(pPVar4 + 0x390));
      uVar13 = 4;
      if (-1 < local_res20[0]) {
        uVar13 = 8;
      }
      *(undefined4 *)(pPVar4 + 0x35c) = uVar13;
      *(undefined8 *)(pPVar4 + 0x360) = 0;
    }
  }
  else {
    if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2a,
                &WPP_ac8c47c7753634169521ea773b2de5d0_Traceguids);
      }
LAB_14000bd9c:
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2f,
                &WPP_ac8c47c7753634169521ea773b2de5d0_Traceguids);
      }
    }
    *(undefined8 *)(pPVar4 + 0x360) = 0;
LAB_14000bdd2:
    *(undefined4 *)(pPVar4 + 0x35c) = 4;
  }
LAB_14000bdd9:
  KeSetEvent(*plVar5 + 0x270,0,0);
LAB_14000bdee:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x32,
            &WPP_ac8c47c7753634169521ea773b2de5d0_Traceguids);
  }
  return;
}



===== ChvOverride_clk_settings @ 14000c160 =====

/* void __cdecl ChvOverride_clk_settings(struct PBC_DEVICE * __ptr64,unsigned long,struct WDFKEY__ *
   __ptr64) */

void __cdecl ChvOverride_clk_settings(PBC_DEVICE *param_1,ulong param_2,WDFKEY__ *param_3)

{
  long lVar1;
  ulong local_res8 [2];
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4a,
            &WPP_d3ace4e3478434d6f80f54d6eccc5db4_Traceguids);
  }
  local_res8[0] = 0;
  LpssRegistry_GetRegistryKeyUlong
            (param_2,param_3,1,(ushort *)&u_BUS_SS_HCNT,(ulong *)(param_1 + 0x7c));
  LpssRegistry_GetRegistryKeyUlong
            (param_2,param_3,1,(ushort *)&u_BUS_SS_LCNT,(ulong *)(param_1 + 0x80));
  LpssRegistry_GetRegistryKeyUlong
            (param_2,param_3,1,(ushort *)&u_BUS_SS_SDA,(ulong *)(param_1 + 0x84));
  LpssRegistry_GetRegistryKeyUlong
            (param_2,param_3,1,(ushort *)&u_BUS_SS_SDA_SETUP,(ulong *)(param_1 + 0x88));
  LpssRegistry_GetRegistryKeyUlong
            (param_2,param_3,1,(ushort *)&u_BUS_FS_HCNT,(ulong *)(param_1 + 0x8c));
  LpssRegistry_GetRegistryKeyUlong
            (param_2,param_3,1,(ushort *)&u_BUS_FS_LCNT,(ulong *)(param_1 + 0x90));
  LpssRegistry_GetRegistryKeyUlong
            (param_2,param_3,1,(ushort *)&u_BUS_FS_SDA,(ulong *)(param_1 + 0x94));
  LpssRegistry_GetRegistryKeyUlong
            (param_2,param_3,1,(ushort *)&u_BUS_FS_SDA_SETUP,(ulong *)(param_1 + 0x98));
  LpssRegistry_GetRegistryKeyUlong
            (param_2,param_3,1,(ushort *)&u_BUS_FP_HCNT,(ulong *)(param_1 + 0x9c));
  LpssRegistry_GetRegistryKeyUlong
            (param_2,param_3,1,(ushort *)&u_BUS_FP_LCNT,(ulong *)(param_1 + 0xa0));
  LpssRegistry_GetRegistryKeyUlong
            (param_2,param_3,1,(ushort *)&u_BUS_FP_SDA,(ulong *)(param_1 + 0xa4));
  LpssRegistry_GetRegistryKeyUlong
            (param_2,param_3,1,(ushort *)&u_BUS_FP_SDA_SETUP,(ulong *)(param_1 + 0xa8));
  LpssRegistry_GetRegistryKeyUlong
            (param_2,param_3,1,(ushort *)&u_BUS_HS_HCNT,(ulong *)(param_1 + 0xac));
  LpssRegistry_GetRegistryKeyUlong
            (param_2,param_3,1,(ushort *)&u_BUS_HS_LCNT,(ulong *)(param_1 + 0xb0));
  LpssRegistry_GetRegistryKeyUlong
            (param_2,param_3,1,(ushort *)&u_BUS_HS_SDA,(ulong *)(param_1 + 0xb4));
  LpssRegistry_GetRegistryKeyUlong
            (param_2,param_3,1,(ushort *)&u_BUS_HS_SDA_SETUP,(ulong *)(param_1 + 0xb8));
  LpssRegistry_GetRegistryKeyUlong
            (param_2,param_3,1,(ushort *)&u_BUS_HP_HCNT,(ulong *)(param_1 + 0xbc));
  LpssRegistry_GetRegistryKeyUlong
            (param_2,param_3,1,(ushort *)&u_BUS_HP_LCNT,(ulong *)(param_1 + 0xc0));
  LpssRegistry_GetRegistryKeyUlong
            (param_2,param_3,1,(ushort *)&u_BUS_HP_SDA,(ulong *)(param_1 + 0xc4));
  LpssRegistry_GetRegistryKeyUlong
            (param_2,param_3,1,(ushort *)&u_BUS_HP_SDA_SETUP,(ulong *)(param_1 + 200));
  lVar1 = LpssAcpi_GetAcpiMethodData(param_1,"_SHT",local_res8);
  if (lVar1 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4c,
               &WPP_d3ace4e3478434d6f80f54d6eccc5db4_Traceguids,lVar1);
    }
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4b,
               &WPP_d3ace4e3478434d6f80f54d6eccc5db4_Traceguids,local_res8[0]);
    }
    *(ulong *)(param_1 + 0x84) = local_res8[0];
    *(ulong *)(param_1 + 0x94) = local_res8[0];
    *(ulong *)(param_1 + 0xa4) = local_res8[0];
    *(ulong *)(param_1 + 0xb4) = local_res8[0];
    *(ulong *)(param_1 + 0xc4) = local_res8[0];
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4d,
            &WPP_d3ace4e3478434d6f80f54d6eccc5db4_Traceguids);
  }
  return;
}



===== ChvP1I2c_AcknowledgeInterrupts @ 14000c540 =====

/* void __cdecl ChvP1I2c_AcknowledgeInterrupts(struct PBC_DEVICE * __ptr64,unsigned long) */

void __cdecl ChvP1I2c_AcknowledgeInterrupts(PBC_DEVICE *param_1,ulong param_2)

{
  longlong lVar1;
  ulong uVar2;
  ulong uVar3;
  uint uVar4;
  
  uVar2 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x820));
  uVar3 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x34));
  uVar4 = uVar3 & param_2;
  if ((uVar4 & 1) != 0) {
    HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x44));
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x25,
              &WPP_d3ace4e3478434d6f80f54d6eccc5db4_Traceguids);
    }
  }
  if ((uVar4 & 2) != 0) {
    HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x48));
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x26,
              &WPP_d3ace4e3478434d6f80f54d6eccc5db4_Traceguids);
    }
  }
  if ((((uVar4 & 4) != 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
     (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0 && (3 < (byte)WPP_GLOBAL_Control[0x29])))) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x27,
            &WPP_d3ace4e3478434d6f80f54d6eccc5db4_Traceguids);
  }
  if ((uVar4 & 8) != 0) {
    HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x4c));
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x28,
              &WPP_d3ace4e3478434d6f80f54d6eccc5db4_Traceguids);
    }
  }
  if ((((uVar4 & 0x10) != 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
     (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0 && (3 < (byte)WPP_GLOBAL_Control[0x29])))) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x29,
            &WPP_d3ace4e3478434d6f80f54d6eccc5db4_Traceguids);
  }
  if ((uVar4 & 0x20) != 0) {
    HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x50));
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2a,
              &WPP_d3ace4e3478434d6f80f54d6eccc5db4_Traceguids);
    }
  }
  if ((uVar4 & 0x40) != 0) {
    uVar3 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x80));
    *(ulong *)(param_1 + 0xe0) = uVar3;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_d3ace4e3478434d6f80f54d6eccc5db4_Traceguids,uVar3);
    }
  }
  if ((char)uVar4 < '\0') {
    HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x58));
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2c,
              &WPP_d3ace4e3478434d6f80f54d6eccc5db4_Traceguids);
    }
  }
  if ((uVar4 & 0x100) != 0) {
    HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x5c));
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2d,
              &WPP_d3ace4e3478434d6f80f54d6eccc5db4_Traceguids);
    }
  }
  if ((uVar4 & 0x200) != 0) {
    HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x60));
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2e,
              &WPP_d3ace4e3478434d6f80f54d6eccc5db4_Traceguids);
    }
  }
  if ((uVar4 & 0x400) != 0) {
    HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 100));
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2f,
              &WPP_d3ace4e3478434d6f80f54d6eccc5db4_Traceguids);
    }
  }
  if ((uVar4 & 0x800) != 0) {
    HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x68));
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x30,
              &WPP_d3ace4e3478434d6f80f54d6eccc5db4_Traceguids);
    }
  }
  if ((uVar4 & 0x100000) != 0 || (uVar2 & 1) != 0) {
    lVar1 = *(longlong *)(param_1 + 8);
    uVar2 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(lVar1 + 0x808));
    HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(lVar1 + 0x808),uVar2 & 0xffffffef);
    HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x824));
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x31,
              &WPP_d3ace4e3478434d6f80f54d6eccc5db4_Traceguids);
    }
  }
  return;
}



===== ChvP1I2c_CheckControllerAbort @ 14000c900 =====

/* unsigned long __cdecl ChvP1I2c_CheckControllerAbort(struct PBC_DEVICE * __ptr64,unsigned long) */

ulong __cdecl ChvP1I2c_CheckControllerAbort(PBC_DEVICE *param_1,ulong param_2)

{
  return (param_2 >> 6 & 1) << 6;
}



===== ChvP1I2c_CheckControllerError @ 14000c910 =====

/* unsigned long __cdecl ChvP1I2c_CheckControllerError(struct PBC_DEVICE * __ptr64,unsigned long) */

ulong __cdecl ChvP1I2c_CheckControllerError(PBC_DEVICE *param_1,ulong param_2)

{
  ulong uVar1;
  
  uVar1 = 0;
  if ((param_2 >> 1 & 1) != 0) {
    uVar1 = 2;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,
              &WPP_d3ace4e3478434d6f80f54d6eccc5db4_Traceguids);
    }
  }
  return uVar1;
}



===== VlvI2c_CheckControllerFinishData @ 14000c960 =====

/* unsigned long __cdecl VlvI2c_CheckControllerFinishData(struct PBC_DEVICE * __ptr64,unsigned long)
    */

ulong __cdecl VlvI2c_CheckControllerFinishData(PBC_DEVICE *param_1,ulong param_2)

{
  return (param_2 >> 0x14 & 1) << 0x14;
}



===== VlvI2c_CheckControllerReadyForTransfer @ 14000c970 =====

/* unsigned long __cdecl VlvI2c_CheckControllerReadyForTransfer(struct PBC_DEVICE * __ptr64,unsigned
   long) */

ulong __cdecl VlvI2c_CheckControllerReadyForTransfer(PBC_DEVICE *param_1,ulong param_2)

{
  return (param_2 >> 4 & 1) << 4;
}



===== ChvP1I2c_CheckControllerTransferDone @ 14000c980 =====

/* unsigned long __cdecl ChvP1I2c_CheckControllerTransferDone(struct PBC_DEVICE * __ptr64,unsigned
   long) */

ulong __cdecl ChvP1I2c_CheckControllerTransferDone(PBC_DEVICE *param_1,ulong param_2)

{
  return (param_2 >> 9 & 1) << 9;
}



===== VlvI2c_CheckControllerTransferOngoing @ 14000c990 =====

/* unsigned long __cdecl VlvI2c_CheckControllerTransferOngoing(struct PBC_DEVICE * __ptr64,unsigned
   long) */

ulong __cdecl VlvI2c_CheckControllerTransferOngoing(PBC_DEVICE *param_1,ulong param_2)

{
  return (param_2 >> 2 & 1) << 2;
}



===== ChvP1I2c_ConfigureForTransferEnd @ 14000c9a0 =====

/* long __cdecl ChvP1I2c_ConfigureForTransferEnd(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST *
   __ptr64) */

long __cdecl ChvP1I2c_ConfigureForTransferEnd(PBC_DEVICE *param_1,PBC_REQUEST *param_2)

{
  return 0;
}



===== VlvI2c_ConfigureForTransferFromDevice @ 14000c9b0 =====

/* long __cdecl VlvI2c_ConfigureForTransferFromDevice(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST
   * __ptr64) */

long __cdecl VlvI2c_ConfigureForTransferFromDevice(PBC_DEVICE *param_1,PBC_REQUEST *param_2)

{
  *(undefined8 *)(param_2 + 0x50) = 0;
  return 0;
}



===== ChvP1I2c_ConfigureForTransferPostSettings @ 14000c9c0 =====

/* long __cdecl ChvP1I2c_ConfigureForTransferPostSettings(struct PBC_DEVICE * __ptr64,struct
   PBC_REQUEST * __ptr64) */

long __cdecl ChvP1I2c_ConfigureForTransferPostSettings(PBC_DEVICE *param_1,PBC_REQUEST *param_2)

{
  longlong lVar1;
  PBC_DEVICE *pPVar2;
  ulong uVar3;
  
  lVar1 = *(longlong *)(param_1 + 8);
  uVar3 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(lVar1 + 0x808));
  HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(lVar1 + 0x808),uVar3 & 0xffffffef);
  lVar1 = *(longlong *)(param_1 + 8);
  uVar3 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(lVar1 + 0x818));
  HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(lVar1 + 0x818),uVar3 | 0x80000);
  lVar1 = *(longlong *)(param_1 + 8);
  uVar3 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(lVar1 + 0x818));
  uVar3 = uVar3 & 0xfff7ffff;
  HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(lVar1 + 0x818),uVar3);
  if (param_1[0x41] == (PBC_DEVICE)0x0) {
    pPVar2 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x480);
    ChvP1I2c_ControllerIoGenerateStart(pPVar2,uVar3);
    uVar3 = (ulong)*(undefined8 *)(param_1 + 0x28);
    (*(code *)pPVar2)(WdfDriverGlobals);
  }
  ControllerDisableInterrupts(param_1);
  LOCK();
  *(undefined4 *)(param_1 + 0x30) = 0;
  UNLOCK();
  *(undefined4 *)(param_1 + 0x34) = 0;
  if (param_1[0x41] == (PBC_DEVICE)0x0) {
    pPVar2 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x488);
    ChvP1I2c_ControllerIoGenerateStart(pPVar2,uVar3);
    (*(code *)pPVar2)(WdfDriverGlobals);
  }
  HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x88),0);
  *(undefined8 *)(param_2 + 0x80) = 0;
  return 0;
}



===== VlvI2c_ConfigureForTransferPreSettings @ 14000cad0 =====

/* long __cdecl VlvI2c_ConfigureForTransferPreSettings(struct PBC_DEVICE * __ptr64,struct
   PBC_REQUEST * __ptr64) */

long __cdecl VlvI2c_ConfigureForTransferPreSettings(PBC_DEVICE *param_1,PBC_REQUEST *param_2)

{
  HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x3c),0);
  return 0;
}



===== ChvP1I2c_ConfigureForTransferStart @ 14000caf0 =====

/* long __cdecl ChvP1I2c_ConfigureForTransferStart(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST *
   __ptr64) */

long __cdecl ChvP1I2c_ConfigureForTransferStart(PBC_DEVICE *param_1,PBC_REQUEST *param_2)

{
  ushort uVar1;
  uchar uVar2;
  ulong uVar3;
  uint uVar4;
  long lVar5;
  
  lVar5 = 0;
  uVar2 = ChvP1I2c_DisableController(param_1);
  if (uVar2 != '\0') {
    uVar3 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x54));
    if ((uVar3 != 0) || (*(int *)(param_1 + 0xe0) != 0)) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0 && (2 < (byte)WPP_GLOBAL_Control[0x29])))
         ) {
        WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,
                  &WPP_d3ace4e3478434d6f80f54d6eccc5db4_Traceguids,uVar3,
                  (char)*(undefined4 *)(param_1 + 0xe0));
      }
      *(undefined4 *)(param_1 + 0xe0) = 0;
    }
    uVar1 = *(ushort *)(*(longlong *)(param_1 + 0x20) + 0xc);
    uVar4 = uVar1 | 0x1000;
    if (*(int *)(*(longlong *)(param_1 + 0x20) + 8) != 1) {
      uVar4 = (uint)uVar1;
    }
    HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 4),uVar4);
    uVar4 = (*(uint *)(*(longlong *)(param_1 + 0x20) + 0x10) & 3) * 2;
    if (param_1[0xdc] == (PBC_DEVICE)0x0) {
      uVar3 = uVar4 | 0x61;
    }
    else {
      uVar3 = uVar4 | 0x41;
    }
    HWREG<unsigned_long>::Write(*(HWREG<unsigned_long> **)(param_1 + 8),uVar3);
    ChvP1I2c_SetRuntimeClock(param_1);
    uVar2 = ChvP1I2c_EnableController(param_1);
    if (uVar2 != '\0') {
      param_1[0x70] = (PBC_DEVICE)0x1;
      goto LAB_14000cbe2;
    }
  }
  lVar5 = -0x3ffffe7e;
LAB_14000cbe2:
  *(long *)(param_2 + 0x20) = lVar5;
  return lVar5;
}



===== ChvP1I2c_ControllerInitialize @ 14000cc00 =====

/* long __cdecl ChvP1I2c_ControllerInitialize(struct PBC_DEVICE * __ptr64) */

long __cdecl ChvP1I2c_ControllerInitialize(PBC_DEVICE *param_1)

{
  longlong lVar1;
  ulong uVar2;
  
  lVar1 = *(longlong *)(param_1 + 0x58);
  if (lVar1 != 0) {
    uVar2 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(lVar1 + 0x84));
    HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(lVar1 + 0x84),uVar2 & 0xfffffffc);
    HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x58) + 0x84));
  }
  KeStallExecutionProcessor(0x32);
  HWREG<unsigned_long>::Write
            ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x804),0xfffffffc);
  HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x804),3);
  if (param_1[0x41] != (PBC_DEVICE)0x0) {
    HWREG<unsigned_long>::Write(*(HWREG<unsigned_long> **)(param_1 + 8),0x65);
    HWREG<unsigned_long>::Write
              ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x1c),
               *(ulong *)(param_1 + 0x8c));
    HWREG<unsigned_long>::Write
              ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x20),
               *(ulong *)(param_1 + 0x90));
    HWREG<unsigned_long>::Write
              ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x7c),
               *(ulong *)(param_1 + 0x94));
    HWREG<unsigned_long>::Write
              ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x94),
               *(ulong *)(param_1 + 0x98));
  }
  HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x800),1);
  HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x88),0);
  return 0;
}



===== ChvP1I2c_ControllerIoGenerateStart @ 14000cd10 =====

/* void __cdecl ChvP1I2c_ControllerIoGenerateStart(struct PBC_DEVICE * __ptr64,unsigned long) */

void __cdecl ChvP1I2c_ControllerIoGenerateStart(PBC_DEVICE *param_1,ulong param_2)

{
  return;
}



===== ChvP1I2c_ControllerIoGenerateStop @ 14000cd20 =====

/* void __cdecl ChvP1I2c_ControllerIoGenerateStop(struct PBC_DEVICE * __ptr64,unsigned long) */

void __cdecl ChvP1I2c_ControllerIoGenerateStop(PBC_DEVICE *param_1,ulong param_2)

{
  longlong lVar1;
  int iVar2;
  ulong uVar3;
  int iVar4;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x46,
            &WPP_d3ace4e3478434d6f80f54d6eccc5db4_Traceguids);
  }
  HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x88),0);
  uVar3 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x808));
  if (((uVar3 >> 0x18 & 1) == 0) || (param_1[0x3b1] != (PBC_DEVICE)0x0)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0 && (3 < (byte)WPP_GLOBAL_Control[0x29]))))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x47,
              &WPP_d3ace4e3478434d6f80f54d6eccc5db4_Traceguids);
    }
    lVar1 = *(longlong *)(param_1 + 8);
    uVar3 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(lVar1 + 0x6c));
    HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(lVar1 + 0x6c),uVar3 | 2);
    uVar3 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x70));
    iVar2 = 100;
    if ((uVar3 & 0x20) != 0) {
      do {
        iVar4 = iVar2;
        if (iVar4 == 0) break;
        KeStallExecutionProcessor((ulonglong)param_2 / 10);
        uVar3 = HWREG<unsigned_long>::Read
                          ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x70));
        iVar2 = iVar4 + -1;
      } while ((uVar3 & 0x20) != 0);
      if ((((iVar4 + -1 == 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),iVar4 + 0x47,
                &WPP_d3ace4e3478434d6f80f54d6eccc5db4_Traceguids);
      }
    }
    HWREG<unsigned_long>::Write
              ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x804),0xfffffffc);
    KeStallExecutionProcessor(param_2);
    HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x804),3);
    KeStallExecutionProcessor(param_2);
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x49,
            &WPP_d3ace4e3478434d6f80f54d6eccc5db4_Traceguids);
  }
  return;
}



===== ChvP1I2c_ControllerUnitialize @ 14000cee0 =====

/* long __cdecl ChvP1I2c_ControllerUnitialize(struct PBC_DEVICE * __ptr64) */

long __cdecl ChvP1I2c_ControllerUnitialize(PBC_DEVICE *param_1)

{
  longlong lVar1;
  ulong uVar2;
  
  lVar1 = *(longlong *)(param_1 + 0x58);
  if (lVar1 != 0) {
    uVar2 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(lVar1 + 0x84));
    HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(lVar1 + 0x84),uVar2 | 3);
    HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x58) + 0x84));
  }
  return 0;
}



===== ChvP1I2c_DisableController @ 14000cf30 =====

/* unsigned char __cdecl ChvP1I2c_DisableController(struct PBC_DEVICE * __ptr64) */

uchar __cdecl ChvP1I2c_DisableController(PBC_DEVICE *param_1)

{
  ulong uVar1;
  byte bVar2;
  uint uVar3;
  
  HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x6c),0);
  LOCK();
  UNLOCK();
  uVar1 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x9c));
  uVar3 = 0;
  bVar2 = (byte)uVar1 & 1;
  if ((uVar1 & 1) != 0) {
    do {
      if (9 < uVar3) break;
      KeStallExecutionProcessor(0x19);
      uVar1 = HWREG<unsigned_long>::Read
                        ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x9c));
      bVar2 = (byte)uVar1 & 1;
      uVar3 = uVar3 + 1;
    } while ((uVar1 & 1) != 0);
    if (bVar2 != 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x44,
                &WPP_d3ace4e3478434d6f80f54d6eccc5db4_Traceguids);
      }
      *(undefined4 *)(param_1 + 0x30) = 0;
    }
  }
  return bVar2 ^ 1;
}



===== VlvI2c_DisableInterrupts @ 14000cff0 =====

/* void __cdecl VlvI2c_DisableInterrupts(struct PBC_DEVICE * __ptr64) */

void __cdecl VlvI2c_DisableInterrupts(PBC_DEVICE *param_1)

{
  longlong lVar1;
  ulong uVar2;
  
  HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x30),0);
  lVar1 = *(longlong *)(param_1 + 8);
  uVar2 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(lVar1 + 0x820));
  HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(lVar1 + 0x820),uVar2 | 2);
  return;
}



===== ChvP1I2c_DmaPostCompletion @ 14000d030 =====

/* void __cdecl ChvP1I2c_DmaPostCompletion(struct PBC_DEVICE * __ptr64) */

void __cdecl ChvP1I2c_DmaPostCompletion(PBC_DEVICE *param_1)

{
  longlong lVar1;
  uint uVar2;
  ulong uVar3;
  char *pcVar4;
  
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])
       ) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3e,
              &WPP_d3ace4e3478434d6f80f54d6eccc5db4_Traceguids);
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      uVar2 = *(uint *)(param_1 + 0x378) & 0x600;
      if (uVar2 == 0x600) {
        pcVar4 = "RESTART/STOP";
      }
      else if (uVar2 == 0x400) {
        pcVar4 = "RESTART";
      }
      else {
        pcVar4 = " ";
        if (uVar2 == 0x200) {
          pcVar4 = "STOP";
        }
      }
      WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3f,
               &WPP_d3ace4e3478434d6f80f54d6eccc5db4_Traceguids,pcVar4);
    }
  }
  HWREG<unsigned_long>::Write
            ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x10),*(ulong *)(param_1 + 0x378)
            );
  *(longlong *)(param_1 + 0x360) = *(longlong *)(param_1 + 0x360) + 1;
  if ((*(uint *)(param_1 + 0x378) & 0x600) == 0x200) {
    lVar1 = *(longlong *)(param_1 + 8);
    uVar3 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(lVar1 + 0x808));
    HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(lVar1 + 0x808),uVar3 | 0x10);
  }
  else {
    LOCK();
    *(uint *)(param_1 + 0x3a4) = *(uint *)(param_1 + 0x3a4) | 1;
    UNLOCK();
    *(undefined4 *)(param_1 + 0x35c) = 1;
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x41,
            &WPP_d3ace4e3478434d6f80f54d6eccc5db4_Traceguids);
  }
  return;
}



===== ChvP1I2c_DmaPreExecute @ 14000d180 =====

/* void __cdecl ChvP1I2c_DmaPreExecute(struct PBC_DEVICE * __ptr64) */

void __cdecl ChvP1I2c_DmaPreExecute(PBC_DEVICE *param_1)

{
  int iVar1;
  ulong uVar2;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x42,
            &WPP_d3ace4e3478434d6f80f54d6eccc5db4_Traceguids);
  }
  HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x8c),0);
  HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x90),0);
  uVar2 = 2;
  iVar1 = *(int *)(*(longlong *)(*(longlong *)(param_1 + 0x20) + 0x18) + 0x44);
  if (iVar1 != 2) {
    if (iVar1 != 1) goto LAB_14000d212;
    uVar2 = 3;
  }
  HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x88),uVar2);
LAB_14000d212:
  LOCK();
  *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 0x100242;
  UNLOCK();
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x43,
            &WPP_d3ace4e3478434d6f80f54d6eccc5db4_Traceguids);
  }
  return;
}



===== ChvP1I2c_EnableController @ 14000d254 =====

/* unsigned char __cdecl ChvP1I2c_EnableController(struct PBC_DEVICE * __ptr64) */

uchar __cdecl ChvP1I2c_EnableController(PBC_DEVICE *param_1)

{
  ulong uVar1;
  byte bVar2;
  uint uVar3;
  
  LOCK();
  UNLOCK();
  HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x6c),1);
  LOCK();
  UNLOCK();
  uVar1 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x9c));
  uVar3 = 0;
  bVar2 = (byte)uVar1 & 1;
  if ((uVar1 & 1) == 0) {
    do {
      if (9 < uVar3) break;
      KeStallExecutionProcessor(0x19);
      uVar1 = HWREG<unsigned_long>::Read
                        ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x9c));
      bVar2 = (byte)uVar1 & 1;
      uVar3 = uVar3 + 1;
    } while ((uVar1 & 1) == 0);
    if (bVar2 == 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x45,
                &WPP_d3ace4e3478434d6f80f54d6eccc5db4_Traceguids);
      }
      *(undefined4 *)(param_1 + 0x30) = 0;
    }
  }
  return bVar2;
}



===== ChvP1I2c_EnableInterrupts @ 14000d320 =====

/* void __cdecl ChvP1I2c_EnableInterrupts(struct PBC_DEVICE * __ptr64,unsigned long) */

void __cdecl ChvP1I2c_EnableInterrupts(PBC_DEVICE *param_1,ulong param_2)

{
  HWREG<unsigned_long>::Write
            ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x30),param_2 & 0x2ff);
  return;
}



===== ChvP1I2c_GetInterruptStatus @ 14000d340 =====

/* unsigned long __cdecl ChvP1I2c_GetInterruptStatus(struct PBC_DEVICE * __ptr64,unsigned long) */

ulong __cdecl ChvP1I2c_GetInterruptStatus(PBC_DEVICE *param_1,ulong param_2)

{
  ulong uVar1;
  ulong uVar2;
  ulong uVar3;
  
  uVar1 = 0;
  if (param_1[0x250] != (PBC_DEVICE)0x0) {
    uVar1 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x820))
    ;
    uVar2 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x34));
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      uVar3 = HWREG<unsigned_long>::Read
                        ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x34));
      WPP_SF_DDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x24,
                 &WPP_d3ace4e3478434d6f80f54d6eccc5db4_Traceguids,uVar3,0,(char)param_2);
    }
    uVar1 = (uVar2 | (uVar1 & 1) << 0x14) & param_2;
  }
  return uVar1;
}



===== ChvP1I2c_InitializeSettings @ 14000d400 =====

/* long __cdecl ChvP1I2c_InitializeSettings(struct PBC_DEVICE * __ptr64) */

long __cdecl ChvP1I2c_InitializeSettings(PBC_DEVICE *param_1)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
            &WPP_d3ace4e3478434d6f80f54d6eccc5db4_Traceguids);
  }
  *(undefined4 *)(param_1 + 0x74) = 0xff;
  *(undefined4 *)(param_1 + 0x78) = 0xffff;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
            &WPP_d3ace4e3478434d6f80f54d6eccc5db4_Traceguids);
  }
  *(undefined4 *)(param_1 + 0x7c) = 0x28f;
  *(undefined4 *)(param_1 + 0x84) = 6;
  *(undefined4 *)(param_1 + 0x94) = 6;
  *(undefined4 *)(param_1 + 0xa4) = 6;
  *(undefined4 *)(param_1 + 0xac) = 6;
  *(undefined4 *)(param_1 + 0xb4) = 6;
  *(undefined4 *)(param_1 + 0x80) = 0x2ba;
  *(undefined4 *)(param_1 + 0x8c) = 0x71;
  *(undefined4 *)(param_1 + 0x90) = 0xce;
  *(undefined4 *)(param_1 + 0x9c) = 0x24;
  *(undefined4 *)(param_1 + 0xa0) = 0x53;
  *(undefined4 *)(param_1 + 0xb0) = 0x30;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
            &WPP_d3ace4e3478434d6f80f54d6eccc5db4_Traceguids);
  }
  return 0;
}



===== ChvP1I2c_IsAbortByAddressPhase @ 14000d520 =====

/* unsigned char __cdecl ChvP1I2c_IsAbortByAddressPhase(struct PBC_DEVICE * __ptr64) */

uchar __cdecl ChvP1I2c_IsAbortByAddressPhase(PBC_DEVICE *param_1)

{
  return (*(uint *)(param_1 + 0xe0) & 7) != 0;
}



===== ChvP1I2c_IsAbortByDataPhase @ 14000d530 =====

/* unsigned char __cdecl ChvP1I2c_IsAbortByDataPhase(struct PBC_DEVICE * __ptr64) */

uchar __cdecl ChvP1I2c_IsAbortByDataPhase(PBC_DEVICE *param_1)

{
  return (byte)(*(uint *)(param_1 + 0xe0) >> 3) & 1;
}



===== ChvP1I2c_OverrideRegistrySettings @ 14000d53c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl ChvP1I2c_OverrideRegistrySettings(struct PBC_DEVICE * __ptr64) */

long __cdecl ChvP1I2c_OverrideRegistrySettings(PBC_DEVICE *param_1)

{
  PBC_DEVICE *pPVar1;
  int iVar2;
  long lVar3;
  char *pcVar4;
  size_t sVar5;
  ulong uVar6;
  ulong uVar7;
  uint uVar8;
  undefined1 auStackY_318 [32];
  ulong local_288 [2];
  WDFKEY__ *local_280;
  char *local_278;
  undefined4 local_270 [2];
  undefined1 *local_268;
  undefined1 local_260 [8];
  char *local_258;
  undefined1 local_250 [24];
  undefined1 local_238 [512];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_318;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
            &WPP_d3ace4e3478434d6f80f54d6eccc5db4_Traceguids);
  }
  uVar7 = *(ulong *)(param_1 + 0x6c);
  local_268 = local_238;
  uVar6 = 0x40013550;
  local_270[0] = 0x2000000;
  RtlInitUnicodeString(local_250);
  pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x728);
  ChvP1I2c_ControllerIoGenerateStart(pPVar1,uVar6);
  iVar2 = (*(code *)pPVar1)(WdfDriverGlobals,0,local_250,0x20019);
  if (iVar2 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar2;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0) && (2 < (byte)WPP_GLOBAL_Control[0x29])
       ) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
               &WPP_d3ace4e3478434d6f80f54d6eccc5db4_Traceguids,iVar2);
    }
  }
  else {
    LpssRegistry_GetRegistryKeyString
              (uVar7,local_280,0,(ushort *)L"ForceDma",(_UNICODE_STRING *)local_270);
    RtlInitAnsiString(local_260,0);
    iVar2 = RtlUnicodeStringToAnsiString(local_260,local_270);
    if (-1 < iVar2) {
      local_278 = (char *)0x0;
      pcVar4 = strtok_s(local_258,",",&local_278);
      uVar8 = 1;
      if (1 < uVar7) {
        do {
          pcVar4 = strtok_s((char *)0x0,",",&local_278);
          if (pcVar4 == (char *)0x0) goto LAB_14000d70a;
          uVar8 = uVar8 + 1;
        } while (uVar8 < uVar7);
      }
      if ((pcVar4 != (char *)0x0) && (sVar5 = strnlen(pcVar4,10), sVar5 < 10)) {
        lVar3 = atol(pcVar4);
        *(long *)(param_1 + 0x31c) = lVar3;
      }
LAB_14000d70a:
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
                  &WPP_d3ace4e3478434d6f80f54d6eccc5db4_Traceguids,uVar7,
                  (char)*(undefined4 *)(param_1 + 0x31c));
      }
    }
    RtlFreeAnsiString(local_260);
    local_288[0] = 0;
    LpssRegistry_GetRegistryKeyUlong(uVar7,local_280,0,(ushort *)L"NoRestartCondition",local_288);
    local_288[0] = local_288[0] >> ((char)uVar7 - 1U & 0x1f);
    param_1[0xdc] = (PBC_DEVICE)((byte)local_288[0] & 1);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      pcVar4 = "supports";
      if ((local_288[0] & 1) != 0) {
        pcVar4 = "does not support";
      }
      WPP_SF_Ls(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
                &WPP_d3ace4e3478434d6f80f54d6eccc5db4_Traceguids,uVar7,pcVar4);
    }
    ChvOverride_clk_settings(param_1,uVar7,local_280);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      uVar7 = 0x14;
      WPP_SF_LLLLLLLLLLLLLLL
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
                 &WPP_d3ace4e3478434d6f80f54d6eccc5db4_Traceguids,*(undefined4 *)(param_1 + 0x74),
                 (char)*(undefined4 *)(param_1 + 0x78),(char)*(undefined4 *)(param_1 + 0x31c),
                 (char)*(undefined4 *)(param_1 + 0x7c),(char)*(undefined4 *)(param_1 + 0x80),
                 (char)*(undefined4 *)(param_1 + 0x84),(char)*(undefined4 *)(param_1 + 0x8c),
                 (char)*(undefined4 *)(param_1 + 0x90),(char)*(undefined4 *)(param_1 + 0x94),
                 (char)*(undefined4 *)(param_1 + 0x9c),(char)*(undefined4 *)(param_1 + 0xa0),
                 (char)*(undefined4 *)(param_1 + 0xa4),(char)*(undefined4 *)(param_1 + 0xac),
                 (char)*(undefined4 *)(param_1 + 0xb0),(char)*(undefined4 *)(param_1 + 0xb4));
    }
    pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x738);
    ChvP1I2c_ControllerIoGenerateStart(pPVar1,uVar7);
    (*(code *)pPVar1)(WdfDriverGlobals,local_280);
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
            &WPP_d3ace4e3478434d6f80f54d6eccc5db4_Traceguids);
  }
  return iVar2;
}



===== ChvP1I2c_PrepareForRead @ 14000d930 =====

/* long __cdecl ChvP1I2c_PrepareForRead(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST * __ptr64) */

long __cdecl ChvP1I2c_PrepareForRead(PBC_DEVICE *param_1,PBC_REQUEST *param_2)

{
  ulonglong uVar1;
  longlong lVar2;
  ulong uVar3;
  uint uVar4;
  uint uVar5;
  ulonglong uVar6;
  char cVar7;
  uint uVar8;
  uint uVar9;
  int local_res8;
  int local_res10;
  
  uVar6 = *(ulonglong *)(param_2 + 0x50);
  uVar1 = *(ulonglong *)(param_2 + 0x28);
  uVar8 = 0x246;
  uVar9 = 0;
  uVar3 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x78));
  local_res8 = 0xff - uVar3;
  uVar3 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x74));
  local_res10 = 0x100 - uVar3;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_PPPLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x32,
                 &WPP_d3ace4e3478434d6f80f54d6eccc5db4_Traceguids,uVar1 - uVar6,(char)uVar6,
                 (char)uVar1,(char)local_res10,(char)local_res8);
  }
  lVar2 = *(longlong *)(param_1 + 8);
  uVar3 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(lVar2 + 0x800));
  HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(lVar2 + 0x800),uVar3 & 0xfffffffe);
  *(undefined2 *)(param_2 + 0x78) = 0;
  if (uVar6 < uVar1) {
    cVar7 = '\x01';
    do {
      if ((local_res10 == 0) || (local_res8 == 0)) break;
      uVar4 = (-(uint)(uVar6 != 0) & 0xfffffc00) + 0x500;
      uVar5 = uVar8 | 0x10;
      if (uVar6 != 0) {
        uVar5 = uVar8;
      }
      uVar8 = uVar5;
      if ((param_2[0x41] == (PBC_REQUEST)0x0) || (uVar1 - uVar6 != 1)) {
LAB_14000da8e:
        uVar5 = uVar4;
        if (*(short *)(param_2 + 0x78) != 0) goto LAB_14000da94;
      }
      else {
        *(undefined2 *)(param_2 + 0x78) = 1;
        uVar8 = uVar8 & 0xffffffef;
        uVar5 = uVar4 | 0x200;
        if (uVar1 == 1) {
          uVar4 = uVar4 | 0x600;
          goto LAB_14000da8e;
        }
LAB_14000da94:
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_Xq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x33,
                    &WPP_d3ace4e3478434d6f80f54d6eccc5db4_Traceguids,uVar6 + 1,cVar7);
        }
      }
      HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x10),uVar5)
      ;
      cVar7 = cVar7 + '\x01';
      *(longlong *)(param_2 + 0x50) = *(longlong *)(param_2 + 0x50) + 1;
      local_res8 = local_res8 + -1;
      local_res10 = local_res10 + -1;
      uVar9 = uVar9 + 1;
      uVar6 = uVar6 + 1;
    } while (uVar6 < uVar1);
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x35,
             &WPP_d3ace4e3478434d6f80f54d6eccc5db4_Traceguids,uVar9);
  }
  lVar2 = *(longlong *)(param_1 + 8);
  uVar3 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(lVar2 + 0x800));
  HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(lVar2 + 0x800),uVar3 | 1);
  if (*(short *)(param_2 + 0x78) == 0) {
    uVar3 = 0;
    if (2 < uVar9) {
      uVar3 = uVar9 - 2;
    }
    HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x38),uVar3);
  }
  ChvP1I2c_SetTransferInterrupts(param_1,uVar8,0);
  *(ulonglong *)(param_2 + 0x80) = *(longlong *)(param_2 + 0x80) + (ulonglong)uVar9;
  return 0;
}



===== ChvP1I2c_PrepareForWrite @ 14000dbe0 =====

/* long __cdecl ChvP1I2c_PrepareForWrite(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST * __ptr64)
    */

long __cdecl ChvP1I2c_PrepareForWrite(PBC_DEVICE *param_1,PBC_REQUEST *param_2)

{
  ChvP1I2c_SetTransferInterrupts(param_1,0x242,0);
  return 0;
}



===== ChvP1I2c_ReleaseResources @ 14000dc00 =====

/* long __cdecl ChvP1I2c_ReleaseResources(struct PBC_DEVICE * __ptr64) */

long __cdecl ChvP1I2c_ReleaseResources(PBC_DEVICE *param_1)

{
  longlong lVar1;
  ulong uVar2;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
            &WPP_d3ace4e3478434d6f80f54d6eccc5db4_Traceguids);
  }
  ChvP1I2c_ControllerUnitialize(param_1);
  if (*(longlong *)(param_1 + 8) != 0) {
    HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x800),0);
    lVar1 = *(longlong *)(param_1 + 8);
    uVar2 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(lVar1 + 0x804));
    HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(lVar1 + 0x804),uVar2 & 0xfffffffc);
  }
  lVar1 = *(longlong *)(param_1 + 0x58);
  if (lVar1 != 0) {
    uVar2 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(lVar1 + 0x84));
    HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(lVar1 + 0x84),uVar2 | 3);
    HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x58) + 0x84));
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
            &WPP_d3ace4e3478434d6f80f54d6eccc5db4_Traceguids);
  }
  return 0;
}



===== ChvP1I2c_RestoreContext @ 14000dd00 =====

/* long __cdecl ChvP1I2c_RestoreContext(struct PBC_DEVICE * __ptr64) */

long __cdecl ChvP1I2c_RestoreContext(PBC_DEVICE *param_1)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
            &WPP_d3ace4e3478434d6f80f54d6eccc5db4_Traceguids);
  }
  ChvP1I2c_InitializeSettings(param_1);
  ChvP1I2c_OverrideRegistrySettings(param_1);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
            &WPP_d3ace4e3478434d6f80f54d6eccc5db4_Traceguids);
  }
  return 0;
}



===== ChvP1I2c_SetRuntimeClock @ 14000dd90 =====

/* void __cdecl ChvP1I2c_SetRuntimeClock(struct PBC_DEVICE * __ptr64) */

void __cdecl ChvP1I2c_SetRuntimeClock(PBC_DEVICE *param_1)

{
  longlong lVar1;
  longlong lVar2;
  ulong uVar3;
  undefined4 uVar4;
  
  lVar1 = *(longlong *)(param_1 + 0x20);
  lVar2 = *(longlong *)(param_1 + 8);
  if (*(int *)(lVar1 + 0x10) == 2) {
    if (*(int *)(lVar1 + 0x14) == 4) {
      HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(lVar2 + 0x1c),*(ulong *)(param_1 + 0x9c))
      ;
      HWREG<unsigned_long>::Write
                ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x20),
                 *(ulong *)(param_1 + 0xa0));
      HWREG<unsigned_long>::Write
                ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x7c),
                 *(ulong *)(param_1 + 0xa4));
      uVar3 = *(ulong *)(param_1 + 0xa8);
      uVar4 = 10;
    }
    else {
      HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(lVar2 + 0x1c),*(ulong *)(param_1 + 0x8c))
      ;
      HWREG<unsigned_long>::Write
                ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x20),
                 *(ulong *)(param_1 + 0x90));
      HWREG<unsigned_long>::Write
                ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x7c),
                 *(ulong *)(param_1 + 0x94));
      uVar3 = *(ulong *)(param_1 + 0x98);
      uVar4 = 0x19;
    }
    HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x94),uVar3);
    *(undefined4 *)(lVar1 + 0x20) = uVar4;
  }
  else if (*(int *)(lVar1 + 0x10) == 3) {
    uVar4 = 5;
    if (*(int *)(lVar1 + 0x14) == 5) {
      HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(lVar2 + 0x24),0xf);
      uVar3 = 0x33;
    }
    else {
      HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(lVar2 + 0x24),*(ulong *)(param_1 + 0xac))
      ;
      uVar3 = *(ulong *)(param_1 + 0xb0);
      uVar4 = 2;
    }
    HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x28),uVar3);
    *(undefined4 *)(lVar1 + 0x20) = uVar4;
    HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x1c),0x71);
    HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x20),0xce);
    HWREG<unsigned_long>::Write
              ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x7c),
               *(ulong *)(param_1 + 0xb4));
    HWREG<unsigned_long>::Write
              ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x94),
               *(ulong *)(param_1 + 0xb8));
  }
  else {
    HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(lVar2 + 0x14),*(ulong *)(param_1 + 0x7c));
    HWREG<unsigned_long>::Write
              ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x18),
               *(ulong *)(param_1 + 0x80));
    HWREG<unsigned_long>::Write
              ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x7c),
               *(ulong *)(param_1 + 0x84));
    HWREG<unsigned_long>::Write
              ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x94),
               *(ulong *)(param_1 + 0x88));
    *(undefined4 *)(lVar1 + 0x20) = 100;
  }
  return;
}



===== ChvP1I2c_SetTransferInterrupts @ 14000df50 =====

/* void __cdecl ChvP1I2c_SetTransferInterrupts(struct PBC_DEVICE * __ptr64,unsigned long,unsigned
   long) */

void __cdecl ChvP1I2c_SetTransferInterrupts(PBC_DEVICE *param_1,ulong param_2,ulong param_3)

{
  PBC_DEVICE *pPVar1;
  ulong uVar2;
  
  uVar2 = param_2;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    uVar2 = 0x22;
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,
             &WPP_d3ace4e3478434d6f80f54d6eccc5db4_Traceguids,param_2);
  }
  if (param_1[0x41] == (PBC_DEVICE)0x0) {
    pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x480);
    ChvP1I2c_ControllerIoGenerateStart(pPVar1,uVar2);
    uVar2 = (ulong)*(undefined8 *)(param_1 + 0x28);
    (*(code *)pPVar1)(WdfDriverGlobals);
  }
  ControllerDisableInterrupts(param_1);
  if (param_3 != 0) {
    LOCK();
    *(undefined4 *)(param_1 + 0x30) = 0;
    UNLOCK();
  }
  LOCK();
  *(ulong *)(param_1 + 0x30) = param_2;
  UNLOCK();
  *(undefined4 *)(param_1 + 0x34) = 0;
  if (param_1[0x41] == (PBC_DEVICE)0x0) {
    pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x488);
    ChvP1I2c_ControllerIoGenerateStart(pPVar1,uVar2);
    (*(code *)pPVar1)(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x28));
  }
  return;
}



===== ChvP1I2c_SetupDispatchers @ 14000e030 =====

/* void __cdecl ChvP1I2c_SetupDispatchers(struct PBC_DEVICE * __ptr64) */

void __cdecl ChvP1I2c_SetupDispatchers(PBC_DEVICE *param_1)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_d3ace4e3478434d6f80f54d6eccc5db4_Traceguids);
  }
  *(code **)(param_1 + 0xe8) = ChvP1I2c_InitializeSettings;
  *(code **)(param_1 + 0xf0) = ChvP1I2c_ConfigureForTransferEnd;
  *(code **)(param_1 + 0xf8) = ChvP1I2c_ValidateAllResources;
  *(code **)(param_1 + 0x100) = ChvP1I2c_ReleaseResources;
  *(code **)(param_1 + 0x108) = ChvP1I2c_ConfigureForTransferEnd;
  *(code **)(param_1 + 0x110) = ChvP1I2c_ConfigureForTransferEnd;
  *(code **)(param_1 + 0x118) = ChvP1I2c_ControllerInitialize;
  *(code **)(param_1 + 0x120) = ChvP1I2c_ControllerUnitialize;
  *(code **)(param_1 + 0x128) = ChvP1I2c_ConfigureForTransferEnd;
  *(code **)(param_1 + 0x130) = ChvP1I2c_RestoreContext;
  *(code **)(param_1 + 0x138) = ChvP1I2c_TargetGetSettings;
  *(code **)(param_1 + 0x140) = VlvI2c_ConfigureForTransferPreSettings;
  *(code **)(param_1 + 0x148) = ChvP1I2c_ConfigureForTransferStart;
  *(code **)(param_1 + 0x150) = ChvP1I2c_ConfigureForTransferEnd;
  *(code **)(param_1 + 0x158) = ChvP1I2c_ConfigureForTransferEnd;
  *(code **)(param_1 + 0x160) = VlvI2c_ConfigureForTransferFromDevice;
  *(code **)(param_1 + 0x168) = ChvP1I2c_ConfigureForTransferPostSettings;
  *(code **)(param_1 + 0x170) = ChvP1I2c_ConfigureForTransferEnd;
  *(code **)(param_1 + 0x178) = ChvP1I2c_ConfigureForTransferEnd;
  *(code **)(param_1 + 0x180) = ChvP1I2c_SetTransferInterrupts;
  *(code **)(param_1 + 0x188) = ChvP1I2c_CheckControllerAbort;
  *(code **)(param_1 + 400) = ChvP1I2c_CheckControllerError;
  *(code **)(param_1 + 0x198) = VlvI2c_CheckControllerReadyForTransfer;
  *(code **)(param_1 + 0x1a0) = VlvI2c_CheckControllerTransferOngoing;
  *(code **)(param_1 + 0x1a8) = ChvP1I2c_CheckControllerTransferDone;
  *(code **)(param_1 + 0x1b0) = VlvI2c_CheckControllerFinishData;
  *(code **)(param_1 + 0x1b8) = ChvP1I2c_EnableInterrupts;
  *(code **)(param_1 + 0x1c0) = VlvI2c_DisableInterrupts;
  *(code **)(param_1 + 0x1c8) = ChvP1I2c_GetInterruptStatus;
  *(code **)(param_1 + 0x1d0) = ChvP1I2c_AcknowledgeInterrupts;
  *(code **)(param_1 + 0x1d8) = ChvP1I2c_PrepareForWrite;
  *(code **)(param_1 + 0x1e0) = ChvP1I2c_PrepareForRead;
  *(code **)(param_1 + 0x1e8) = ChvP1I2c_TransferDataWrite;
  *(code **)(param_1 + 0x1f0) = ChvP1I2c_TransferDataRead;
  *(code **)(param_1 + 0x1f8) = ChvP1I2c_UpdateTransferDataSize;
  *(code **)(param_1 + 0x200) = ChvP1I2c_DmaPostCompletion;
  *(code **)(param_1 + 0x208) = ChvP1I2c_DmaPreExecute;
  *(code **)(param_1 + 0x210) = ChvP1I2c_ControllerIoGenerateStart;
  *(code **)(param_1 + 0x218) = ChvP1I2c_ControllerIoGenerateStop;
  *(code **)(param_1 + 0x220) = ChvP1I2c_IsAbortByAddressPhase;
  *(code **)(param_1 + 0x228) = ChvP1I2c_IsAbortByDataPhase;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
            &WPP_d3ace4e3478434d6f80f54d6eccc5db4_Traceguids);
  }
  return;
}



===== ChvP1I2c_TargetGetSettings @ 14000e2f0 =====

/* long __cdecl ChvP1I2c_TargetGetSettings(struct PBC_DEVICE * __ptr64,void * __ptr64,struct
   PBC_TARGET_SETTINGS * __ptr64) */

long __cdecl
ChvP1I2c_TargetGetSettings(PBC_DEVICE *param_1,void *param_2,PBC_TARGET_SETTINGS *param_3)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  uVar6 = 1;
  uVar5 = 2;
  if (*(char *)((longlong)param_2 + 5) != '\x01') {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3ffffff3;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) {
      return -0x3ffffff3;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return -0x3ffffff3;
    }
    WPP_SF_c(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
             &WPP_d3ace4e3478434d6f80f54d6eccc5db4_Traceguids,*(char *)((longlong)param_2 + 5));
    return -0x3ffffff3;
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
             &WPP_d3ace4e3478434d6f80f54d6eccc5db4_Traceguids,
             *(uint *)((longlong)param_2 + 0xc) / 1000);
  }
  uVar1 = *(ushort *)((longlong)param_2 + 0x10);
  *(ushort *)(param_3 + 4) = uVar1;
  uVar2 = *(ushort *)((longlong)param_2 + 7);
  *(uint *)param_3 = uVar2 & 1;
  if ((uVar2 & 1) == 0) {
    if (uVar1 < 0x80) {
LAB_14000e426:
      iVar3 = *(int *)((longlong)param_2 + 0xc);
      if (iVar3 == 400000) {
        uVar6 = 2;
      }
      else if (iVar3 == 1000000) {
        uVar6 = 2;
        uVar5 = 4;
      }
      else if (iVar3 == 1700000) {
        uVar6 = 3;
        uVar5 = 5;
      }
      else if (iVar3 == 3400000) {
        uVar6 = 3;
      }
      *(undefined4 *)(param_3 + 8) = uVar6;
      *(undefined4 *)(param_3 + 0xc) = uVar5;
      return 0;
    }
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_14000e3ee;
    uVar4 = 0x1c;
  }
  else {
    if (uVar1 < 0x400) goto LAB_14000e426;
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_14000e3ee;
    uVar4 = 0x1d;
  }
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,
           &WPP_d3ace4e3478434d6f80f54d6eccc5db4_Traceguids,(uint)uVar1);
LAB_14000e3ee:
  *(undefined2 *)(param_3 + 4) = 0;
  return -0x3ffffff3;
}



===== ChvP1I2c_TransferDataRead @ 14000e490 =====

/* long __cdecl ChvP1I2c_TransferDataRead(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST * __ptr64)
    */

long __cdecl ChvP1I2c_TransferDataRead(PBC_DEVICE *param_1,PBC_REQUEST *param_2)

{
  ulonglong uVar1;
  ulong uVar2;
  ulong uVar3;
  longlong lVar4;
  undefined8 *puVar5;
  long lVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  ulonglong in_stack_ffffffffffffffc8;
  
  uVar8 = *(ulonglong *)(param_2 + 0x58);
  lVar6 = 0;
  uVar1 = *(ulonglong *)(param_2 + 0x28);
  uVar2 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x78));
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    in_stack_ffffffffffffffc8 = uVar8;
    WPP_SF_Xq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x39,
              &WPP_d3ace4e3478434d6f80f54d6eccc5db4_Traceguids,(ulonglong)uVar2,(char)uVar8);
  }
  do {
    if ((uVar1 <= uVar8) || (uVar2 == 0)) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_Lq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3b,
                  &WPP_d3ace4e3478434d6f80f54d6eccc5db4_Traceguids,(int)uVar8,
                  (char)*(undefined8 *)(param_2 + 0x80));
      }
      ChvP1I2c_SetTransferInterrupts(param_1,0x246,0);
      return lVar6;
    }
    HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x70));
    uVar3 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x10));
    lVar6 = -0x3ffffffc;
    if (uVar8 < *(ulonglong *)(param_2 + 0x28)) {
      uVar7 = uVar8;
      for (puVar5 = *(undefined8 **)(param_2 + 0x30); puVar5 != (undefined8 *)0x0;
          puVar5 = (undefined8 *)*puVar5) {
        if (uVar7 < *(uint *)(puVar5 + 5)) {
          if ((*(byte *)((longlong)puVar5 + 10) & 5) == 0) {
            in_stack_ffffffffffffffc8 = in_stack_ffffffffffffffc8 & 0xffffffff00000000;
            lVar4 = MmMapLockedPagesSpecifyCache(puVar5,0,1,0,in_stack_ffffffffffffffc8,0x40000010);
          }
          else {
            lVar4 = puVar5[3];
          }
          if (lVar4 != 0) {
            *(char *)(lVar4 + uVar7) = (char)uVar3;
            lVar6 = 0;
          }
          break;
        }
        uVar7 = uVar7 - *(uint *)(puVar5 + 5);
      }
    }
    if (lVar6 < 0) {
      return lVar6;
    }
    *(longlong *)(param_2 + 0x58) = *(longlong *)(param_2 + 0x58) + 1;
    uVar8 = uVar8 + 1;
    uVar2 = uVar2 - 1;
    *(longlong *)(param_2 + 0x80) = *(longlong *)(param_2 + 0x80) + -1;
  } while( true );
}



===== ChvP1I2c_TransferDataWrite @ 14000e630 =====

/* long __cdecl ChvP1I2c_TransferDataWrite(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST * __ptr64)
    */

long __cdecl ChvP1I2c_TransferDataWrite(PBC_DEVICE *param_1,PBC_REQUEST *param_2)

{
  ulonglong uVar1;
  ulong uVar2;
  longlong lVar3;
  uint uVar4;
  undefined8 *puVar5;
  uint uVar6;
  ulonglong uVar7;
  long lVar8;
  ulonglong uVar9;
  uint uVar10;
  
  uVar9 = *(ulonglong *)(param_2 + 0x58);
  uVar1 = *(ulonglong *)(param_2 + 0x28);
  lVar8 = 0;
  uVar2 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x74));
  uVar10 = 0x100 - uVar2;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_P(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x36,
             &WPP_d3ace4e3478434d6f80f54d6eccc5db4_Traceguids,(ulonglong)uVar10);
  }
  lVar3 = *(longlong *)(param_1 + 8);
  uVar2 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(lVar3 + 0x800));
  HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(lVar3 + 0x800),uVar2 & 0xfffffffe);
  do {
    if ((uVar1 <= uVar9) || (uVar10 == 0)) {
      lVar3 = *(longlong *)(param_1 + 8);
      uVar2 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(lVar3 + 0x800));
      HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(lVar3 + 0x800),uVar2 | 1);
      ChvP1I2c_SetTransferInterrupts(param_1,0x100252,0);
      return lVar8;
    }
    uVar6 = 0;
    lVar8 = -0x3ffffffc;
    if (uVar9 < *(ulonglong *)(param_2 + 0x28)) {
      uVar7 = uVar9;
      for (puVar5 = *(undefined8 **)(param_2 + 0x30); puVar5 != (undefined8 *)0x0;
          puVar5 = (undefined8 *)*puVar5) {
        if (uVar7 < *(uint *)(puVar5 + 5)) {
          if ((*(byte *)((longlong)puVar5 + 10) & 5) == 0) {
            lVar3 = MmMapLockedPagesSpecifyCache(puVar5,0,1,0,0,0x40000010);
          }
          else {
            lVar3 = puVar5[3];
          }
          if (lVar3 != 0) {
            uVar6 = (uint)*(byte *)(lVar3 + uVar7);
            lVar8 = 0;
          }
          break;
        }
        uVar7 = uVar7 - *(uint *)(puVar5 + 5);
      }
    }
    if (lVar8 < 0) {
      return lVar8;
    }
    uVar4 = uVar6 | 0x400;
    if (uVar9 != 0) {
      uVar4 = uVar6;
    }
    uVar6 = uVar4;
    if ((param_2[0x41] != (PBC_REQUEST)0x0) && (uVar1 - uVar9 == 1)) {
      uVar6 = uVar4 | 0x200;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0 && (3 < (byte)WPP_GLOBAL_Control[0x29])))
         ) {
        WPP_SF_P(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x37,
                 &WPP_d3ace4e3478434d6f80f54d6eccc5db4_Traceguids,uVar9 + 1);
      }
      if (uVar1 == 1) {
        uVar6 = uVar4 | 0x600;
      }
    }
    HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x10),uVar6);
    *(longlong *)(param_2 + 0x58) = *(longlong *)(param_2 + 0x58) + 1;
    uVar9 = uVar9 + 1;
    uVar10 = uVar10 - 1;
  } while( true );
}



===== ChvP1I2c_UpdateTransferDataSize @ 14000e820 =====

/* unsigned __int64 __cdecl ChvP1I2c_UpdateTransferDataSize(struct PBC_DEVICE * __ptr64) */

__uint64 __cdecl ChvP1I2c_UpdateTransferDataSize(PBC_DEVICE *param_1)

{
  ulong uVar1;
  ulong uVar2;
  
  uVar1 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x818));
  uVar2 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x818));
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3d,
              &WPP_d3ace4e3478434d6f80f54d6eccc5db4_Traceguids,uVar1 & 0xffff,0);
  }
  return (ulonglong)((uVar2 & 0x10000) + (uVar1 & 0xffff));
}



===== ChvP1I2c_ValidateAllResources @ 14000e8b0 =====

/* long __cdecl ChvP1I2c_ValidateAllResources(struct PBC_DEVICE * __ptr64) */

long __cdecl ChvP1I2c_ValidateAllResources(PBC_DEVICE *param_1)

{
  ChvP1I2c_OverrideRegistrySettings(param_1);
  return 0;
}



===== WPP_SF_DDD @ 14000e8c0 =====

void WPP_SF_DDD(undefined8 param_1,uint param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  PBC_DEVICE *pPVar1;
  undefined4 local_res20 [2];
  
  pPVar1 = pfnWppTraceMessage;
  local_res20[0] = param_4;
  ChvP1I2c_ControllerIoGenerateStart(pfnWppTraceMessage,param_2);
  (*(code *)pPVar1)(param_1,0x2b,param_3,param_2 & 0xffff,local_res20,4,&param_5,4,&param_6,4,0);
  return;
}



===== WPP_SF_LLLLLLLLLLLLLLL @ 14000e958 =====

void WPP_SF_LLLLLLLLLLLLLLL
               (undefined8 param_1,uint param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9,undefined1 param_10,undefined1 param_11,undefined1 param_12,
               undefined1 param_13,undefined1 param_14,undefined1 param_15,undefined1 param_16,
               undefined1 param_17,undefined1 param_18)

{
  PBC_DEVICE *pPVar1;
  undefined4 local_res20 [2];
  
  pPVar1 = pfnWppTraceMessage;
  local_res20[0] = param_4;
  ChvP1I2c_ControllerIoGenerateStart(pfnWppTraceMessage,param_2);
  (*(code *)pPVar1)(param_1,0x2b,param_3,param_2 & 0xffff,local_res20,4,&param_5,4,&param_6,4,
                    &param_7,4,&param_8,4,&param_9,4,&param_10,4,&param_11,4,&param_12,4,&param_13,4
                    ,&param_14,4,&param_15,4,&param_16,4,&param_17,4,&param_18,4,0);
  return;
}



===== WPP_SF_Ls @ 14000eacc =====

void WPP_SF_Ls(undefined8 param_1,uint param_2,undefined8 param_3,undefined4 param_4,char *param_5)

{
  PBC_DEVICE *pPVar1;
  char *pcVar2;
  longlong lVar3;
  longlong lVar4;
  undefined4 local_res20 [2];
  
  pPVar1 = pfnWppTraceMessage;
  if (param_5 == (char *)0x0) {
    lVar4 = 5;
  }
  else {
    lVar3 = -1;
    do {
      lVar4 = lVar3;
      lVar3 = lVar4 + 1;
    } while (param_5[lVar3] != '\0');
    lVar4 = lVar4 + 2;
  }
  pcVar2 = "NULL";
  if (param_5 != (char *)0x0) {
    pcVar2 = param_5;
  }
  local_res20[0] = param_4;
  ChvP1I2c_ControllerIoGenerateStart(pfnWppTraceMessage,param_2);
  (*(code *)pPVar1)(param_1,0x2b,param_3,(short)param_2,local_res20,4,pcVar2,lVar4,0);
  return;
}



===== WPP_SF_PPPLL @ 14000eb88 =====

void WPP_SF_PPPLL(undefined8 param_1,uint param_2,undefined8 param_3,undefined8 param_4,
                 undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  PBC_DEVICE *pPVar1;
  undefined8 local_res20;
  
  pPVar1 = pfnWppTraceMessage;
  local_res20 = param_4;
  ChvP1I2c_ControllerIoGenerateStart(pfnWppTraceMessage,param_2);
  (*(code *)pPVar1)(param_1,0x2b,param_3,param_2 & 0xffff,&local_res20,8,&param_5,8,&param_6,8,
                    &param_7,4,&param_8,4,0);
  return;
}



===== WPP_SF_c @ 14000ec50 =====

void WPP_SF_c(undefined8 param_1,uint param_2,undefined8 param_3,undefined1 param_4)

{
  PBC_DEVICE *pPVar1;
  undefined1 local_res20 [8];
  
  pPVar1 = pfnWppTraceMessage;
  local_res20[0] = param_4;
  ChvP1I2c_ControllerIoGenerateStart(pfnWppTraceMessage,param_2);
  (*(code *)pPVar1)(param_1,0x2b,param_3,param_2 & 0xffff,local_res20,1,0);
  return;
}



===== WPP_SF_s @ 14000ecc0 =====

void WPP_SF_s(undefined8 param_1,uint param_2,undefined8 param_3,char *param_4)

{
  PBC_DEVICE *pPVar1;
  char *pcVar2;
  longlong lVar3;
  longlong lVar4;
  
  pPVar1 = pfnWppTraceMessage;
  if (param_4 == (char *)0x0) {
    lVar4 = 5;
  }
  else {
    lVar3 = -1;
    do {
      lVar4 = lVar3;
      lVar3 = lVar4 + 1;
    } while (param_4[lVar3] != '\0');
    lVar4 = lVar4 + 2;
  }
  pcVar2 = "NULL";
  if (param_4 != (char *)0x0) {
    pcVar2 = param_4;
  }
  ChvP1I2c_ControllerIoGenerateStart(pfnWppTraceMessage,param_2);
  (*(code *)pPVar1)(param_1,0x2b,param_3,(short)param_2,pcVar2,lVar4,0);
  return;
}



===== LpssRegistry_GetRegistryKeyString @ 14000ed58 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl LpssRegistry_GetRegistryKeyString(unsigned long,struct WDFKEY__ * __ptr64,enum
   REGKEY_SCOPE,unsigned short * __ptr64,struct _UNICODE_STRING * __ptr64) */

void __cdecl
LpssRegistry_GetRegistryKeyString
          (ulong param_1,WDFKEY__ *param_2,REGKEY_SCOPE param_3,ushort *param_4,
          _UNICODE_STRING *param_5)

{
  PBC_DEVICE *pPVar1;
  int iVar2;
  wchar_t *pwVar3;
  undefined1 auStackY_278 [32];
  undefined4 local_248 [2];
  undefined1 *local_240;
  undefined1 local_238 [512];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_278;
  local_240 = local_238;
  local_248[0] = 0x2000000;
  if (param_3 == 0) {
    pwVar3 = (wchar_t *)&u__ws;
    RtlUnicodeStringPrintf((_UNICODE_STRING *)local_248,(ushort *)&u__ws,param_4);
  }
  else {
    pwVar3 = (wchar_t *)param_2;
    if (param_3 == 1) {
      pwVar3 = L"%ws_%lu";
      RtlUnicodeStringPrintf
                ((_UNICODE_STRING *)local_248,(ushort *)L"%ws_%lu",param_4,(ulonglong)param_1);
    }
  }
  pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x770);
  ChvP1I2c_ControllerIoGenerateStart(pPVar1,(ulong)pwVar3);
  iVar2 = (*(code *)pPVar1)(WdfDriverGlobals,param_2,local_248,0);
  if ((((-1 < iVar2) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_SZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
              &WPP_194e9404c1a83ed12ea69d5135e99dff_Traceguids,(undefined1 *)param_4,
              (short *)param_5);
  }
  return;
}



===== LpssRegistry_GetRegistryKeyUlong @ 14000ee60 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl LpssRegistry_GetRegistryKeyUlong(unsigned long,struct WDFKEY__ * __ptr64,enum
   REGKEY_SCOPE,unsigned short * __ptr64,unsigned long * __ptr64) */

void __cdecl
LpssRegistry_GetRegistryKeyUlong
          (ulong param_1,WDFKEY__ *param_2,REGKEY_SCOPE param_3,ushort *param_4,ulong *param_5)

{
  PBC_DEVICE *pPVar1;
  int iVar2;
  ulong uVar3;
  undefined1 auStackY_288 [32];
  ulong local_258 [2];
  undefined4 local_250 [2];
  undefined1 *local_248;
  undefined1 local_238 [512];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_288;
  local_248 = local_238;
  local_250[0] = 0x2000000;
  local_258[0] = 0;
  if (param_3 == 0) {
    uVar3 = 0x400139a0;
    iVar2 = RtlUnicodeStringPrintf((_UNICODE_STRING *)local_250,(ushort *)&u__ws,param_4);
  }
  else {
    if (param_3 != 1) {
      return;
    }
    uVar3 = 0x400139b0;
    iVar2 = RtlUnicodeStringPrintf
                      ((_UNICODE_STRING *)local_250,(ushort *)L"%ws_%lu",param_4,(ulonglong)param_1)
    ;
  }
  if (-1 < iVar2) {
    pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x780);
    ChvP1I2c_ControllerIoGenerateStart(pPVar1,uVar3);
    iVar2 = (*(code *)pPVar1)(WdfDriverGlobals,param_2,local_250,local_258);
    if ((((-1 < iVar2) &&
         (*param_5 = local_258[0], (undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_SdD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
                 &WPP_194e9404c1a83ed12ea69d5135e99dff_Traceguids,(undefined1 *)param_4,
                 (char)local_258[0],(char)local_258[0]);
    }
  }
  return;
}



===== RtlUnicodeStringPrintf @ 14000ef84 =====

/* long __cdecl RtlUnicodeStringPrintf(struct _UNICODE_STRING * __ptr64,unsigned short const *
   __ptr64,...) */

long __cdecl RtlUnicodeStringPrintf(_UNICODE_STRING *param_1,ushort *param_2,...)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  ulonglong uVar4;
  long lVar5;
  size_t _Count;
  undefined8 in_R8;
  undefined8 in_R9;
  wchar_t *_Dest;
  undefined8 local_res18;
  undefined8 local_res20;
  
  uVar1 = *(ushort *)param_1;
  _Count = 0;
  lVar5 = 0;
  if (((((uVar1 & 1) == 0) && (uVar2 = *(ushort *)(param_1 + 2), (uVar2 & 1) == 0)) &&
      (uVar1 <= uVar2)) && (uVar2 != 0xffff)) {
    _Dest = *(wchar_t **)(param_1 + 8);
    if ((_Dest == (wchar_t *)0x0) && ((uVar1 != 0 || (uVar2 != 0)))) {
      lVar5 = -0x3ffffff3;
      _Dest = (wchar_t *)0x0;
    }
    else {
      _Count = (size_t)(uVar2 >> 1);
    }
    if (-1 < lVar5) {
      lVar5 = 0;
      local_res18 = in_R8;
      local_res20 = in_R9;
      iVar3 = _vsnwprintf(_Dest,_Count,(wchar_t *)param_2,(va_list)&local_res18);
      if ((iVar3 < 0) || (uVar4 = (longlong)iVar3, _Count < (ulonglong)(longlong)iVar3)) {
        lVar5 = -0x7ffffffb;
        uVar4 = _Count;
      }
      *(short *)param_1 = (short)uVar4 * 2;
    }
  }
  else {
    lVar5 = -0x3ffffff3;
  }
  return lVar5;
}



===== WPP_SF_SZ @ 14000f030 =====

void WPP_SF_SZ(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined1 *param_4,
              short *param_5)

{
  PBC_DEVICE *pPVar1;
  longlong lVar2;
  undefined1 *puVar3;
  short *psVar4;
  undefined1 *puVar5;
  short sVar6;
  
  pPVar1 = pfnWppTraceMessage;
  if (param_5 == (short *)0x0) {
    sVar6 = 8;
  }
  else {
    sVar6 = *param_5;
  }
  if ((param_5 == (short *)0x0) || (*param_5 == 0)) {
    puVar5 = &u_NULL;
  }
  else {
    puVar5 = *(undefined1 **)(param_5 + 4);
  }
  if (param_4 == (undefined1 *)0x0) {
    lVar2 = 10;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (*(short *)(param_4 + lVar2 * 2) != 0);
    lVar2 = lVar2 * 2 + 2;
  }
  psVar4 = (short *)&u__;
  if (param_5 != (short *)0x0) {
    psVar4 = param_5;
  }
  puVar3 = &u_NULL;
  if (param_4 != (undefined1 *)0x0) {
    puVar3 = param_4;
  }
  ChvP1I2c_ControllerIoGenerateStart(pfnWppTraceMessage,0);
  (*(code *)pPVar1)(param_1,0x2b,param_3,param_2,puVar3,lVar2,psVar4,2,puVar5,sVar6,0);
  return;
}



===== WPP_SF_SdD @ 14000f130 =====

void WPP_SF_SdD(undefined8 param_1,uint param_2,undefined8 param_3,undefined1 *param_4,
               undefined1 param_5,undefined1 param_6)

{
  PBC_DEVICE *pPVar1;
  longlong lVar2;
  undefined1 *puVar3;
  
  pPVar1 = pfnWppTraceMessage;
  if (param_4 == (undefined1 *)0x0) {
    lVar2 = 10;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (*(short *)(param_4 + lVar2 * 2) != 0);
    lVar2 = lVar2 * 2 + 2;
  }
  puVar3 = &u_NULL;
  if (param_4 != (undefined1 *)0x0) {
    puVar3 = param_4;
  }
  ChvP1I2c_ControllerIoGenerateStart(pfnWppTraceMessage,param_2);
  (*(code *)pPVar1)(param_1,0x2b,param_3,(short)param_2,puVar3,lVar2,&param_5,4,&param_6,4,0);
  return;
}



===== LpssAcpi_GetAcpiMethodData @ 14000f200 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl LpssAcpi_GetAcpiMethodData(struct PBC_DEVICE * __ptr64,char * __ptr64,unsigned long
   * __ptr64) */

long __cdecl LpssAcpi_GetAcpiMethodData(PBC_DEVICE *param_1,char *param_2,ulong *param_3)

{
  PBC_DEVICE *pPVar1;
  int iVar2;
  undefined8 uVar3;
  ulong uVar4;
  ulong uVar5;
  uint uVar6;
  long lVar7;
  undefined1 auStack_2c8 [32];
  undefined4 local_288;
  char local_284;
  char local_283;
  char local_282;
  char local_281;
  undefined8 local_280;
  int *local_278;
  undefined8 local_270;
  undefined8 local_268;
  undefined4 *local_260;
  undefined8 local_258;
  longlong local_250;
  int local_248 [2];
  int local_240;
  short local_23c;
  ulong local_238;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_2c8;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_ab56a4963786347204ad4dbff0cc769c_Traceguids);
  }
  *param_3 = 0xbaad;
  local_284 = *param_2;
  local_283 = param_2[1];
  uVar4 = 0;
  local_282 = param_2[2];
  local_281 = param_2[3];
  local_260 = &local_288;
  local_288 = 0x42696541;
  local_268 = 1;
  local_258 = 8;
  memset(local_248,0,0x200);
  uVar5 = (ulong)*(undefined8 *)param_1;
  local_278 = local_248;
  local_280 = 1;
  local_270 = 0x200;
  pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x150);
  ChvP1I2c_ControllerIoGenerateStart(pPVar1,uVar4);
  uVar3 = (*(code *)pPVar1)(WdfDriverGlobals);
  pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x5d0);
  ChvP1I2c_ControllerIoGenerateStart(pPVar1,uVar5);
  lVar7 = 0;
  iVar2 = (*(code *)pPVar1)(WdfDriverGlobals,uVar3,0,0x32c004);
  if ((iVar2 < 0) || (local_250 == 0)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0 && (2 < (byte)WPP_GLOBAL_Control[0x29]))))
    {
      WPP_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                &WPP_ab56a4963786347204ad4dbff0cc769c_Traceguids,param_2,(char)iVar2);
    }
    lVar7 = -0x3ffffffe;
    goto LAB_14000f48d;
  }
  if (local_248[0] == 0x426f6541) {
    if (local_240 == 1) {
      if (local_23c == 0) {
        *param_3 = local_238;
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return 0;
        }
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                    &WPP_ab56a4963786347204ad4dbff0cc769c_Traceguids,param_2,(char)local_238);
        }
        goto LAB_14000f48d;
      }
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        uVar6 = 0xe;
        goto LAB_14000f3a6;
      }
    }
    else if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
            (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      uVar6 = 0xd;
      goto LAB_14000f3a6;
    }
  }
  else if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    uVar6 = 0xc;
LAB_14000f3a6:
    WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,
             &WPP_ab56a4963786347204ad4dbff0cc769c_Traceguids,param_2);
  }
  lVar7 = -0x3febfff1;
LAB_14000f48d:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
            &WPP_ab56a4963786347204ad4dbff0cc769c_Traceguids);
  }
  return lVar7;
}



===== WPP_SF_sD @ 14000f4e0 =====

void WPP_SF_sD(undefined8 param_1,uint param_2,undefined8 param_3,char *param_4,undefined1 param_5)

{
  PBC_DEVICE *pPVar1;
  char *pcVar2;
  longlong lVar3;
  longlong lVar4;
  
  pPVar1 = pfnWppTraceMessage;
  if (param_4 == (char *)0x0) {
    lVar4 = 5;
  }
  else {
    lVar3 = -1;
    do {
      lVar4 = lVar3;
      lVar3 = lVar4 + 1;
    } while (param_4[lVar3] != '\0');
    lVar4 = lVar4 + 2;
  }
  pcVar2 = "NULL";
  if (param_4 != (char *)0x0) {
    pcVar2 = param_4;
  }
  ChvP1I2c_ControllerIoGenerateStart(pfnWppTraceMessage,param_2);
  (*(code *)pPVar1)(param_1,0x2b,param_3,(short)param_2,pcVar2,lVar4,&param_5,4,0);
  return;
}



===== LpssApi_AcknowledgeInterrupts @ 14000f590 =====

/* void __cdecl LpssApi_AcknowledgeInterrupts(struct PBC_DEVICE * __ptr64,unsigned long) */

void __cdecl LpssApi_AcknowledgeInterrupts(PBC_DEVICE *param_1,ulong param_2)

{
  PBC_DEVICE *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(PBC_DEVICE **)(param_1 + 0x1d0);
  ChvP1I2c_ControllerIoGenerateStart(UNRECOVERED_JUMPTABLE,param_2);
                    /* WARNING: Could not recover jumptable at 0x00014000f5cb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)UNRECOVERED_JUMPTABLE)(param_1,param_2);
  return;
}



===== LpssApi_AssignMemoryResource @ 14000f5d0 =====

/* long __cdecl LpssApi_AssignMemoryResource(struct PBC_DEVICE * __ptr64,struct
   _CM_PARTIAL_RESOURCE_DESCRIPTOR * __ptr64,struct _CM_PARTIAL_RESOURCE_DESCRIPTOR *
   __ptr64,unsigned long) */

long __cdecl
LpssApi_AssignMemoryResource
          (PBC_DEVICE *param_1,_CM_PARTIAL_RESOURCE_DESCRIPTOR *param_2,
          _CM_PARTIAL_RESOURCE_DESCRIPTOR *param_3,ulong param_4)

{
  longlong lVar1;
  long lVar2;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
            &WPP_cade0c8bec5232dc457469c5f08fa6b4_Traceguids);
  }
  lVar2 = 0;
  if ((*(int *)(param_3 + 8) == 0) &&
     (*(uint *)(param_3 + 4) <= *(int *)(param_3 + 0xc) + *(uint *)(param_3 + 4))) {
    if (param_4 == 0) goto LAB_14000f72a;
    if (param_4 != 1) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
                &WPP_cade0c8bec5232dc457469c5f08fa6b4_Traceguids);
      }
      lVar2 = -0x3ffffe7e;
      goto LAB_14000f72a;
    }
    lVar1 = MmMapIoSpaceEx(*(undefined8 *)(param_2 + 4),*(undefined4 *)(param_2 + 0xc),0x204);
    *(longlong *)(param_1 + 0x58) = lVar1;
    *(undefined4 *)(param_1 + 0x60) = *(undefined4 *)(param_2 + 0xc);
    if (lVar1 != 0) goto LAB_14000f72a;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_xd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
                &WPP_cade0c8bec5232dc457469c5f08fa6b4_Traceguids,*(undefined8 *)(param_2 + 4),
                (char)*(undefined4 *)(param_2 + 0xc));
    }
    *(undefined4 *)(param_1 + 0x60) = 0;
  }
  else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0 && (1 < (byte)WPP_GLOBAL_Control[0x29]))
          )) {
    WPP_SF_Lq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
              &WPP_cade0c8bec5232dc457469c5f08fa6b4_Traceguids,param_4,
              (char)*(undefined8 *)(param_3 + 4));
  }
  lVar2 = -0x3fffff66;
LAB_14000f72a:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
            &WPP_cade0c8bec5232dc457469c5f08fa6b4_Traceguids);
  }
  return lVar2;
}



===== LpssApi_CheckControllerAbort @ 14000f778 =====

/* unsigned long __cdecl LpssApi_CheckControllerAbort(struct PBC_DEVICE * __ptr64,unsigned long) */

ulong __cdecl LpssApi_CheckControllerAbort(PBC_DEVICE *param_1,ulong param_2)

{
  PBC_DEVICE *UNRECOVERED_JUMPTABLE;
  ulong uVar1;
  
  UNRECOVERED_JUMPTABLE = *(PBC_DEVICE **)(param_1 + 0x188);
  ChvP1I2c_ControllerIoGenerateStart(UNRECOVERED_JUMPTABLE,param_2);
                    /* WARNING: Could not recover jumptable at 0x00014000f7b3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(code *)UNRECOVERED_JUMPTABLE)(param_1,param_2);
  return uVar1;
}



===== LpssApi_CheckControllerError @ 14000f7b8 =====

/* unsigned long __cdecl LpssApi_CheckControllerError(struct PBC_DEVICE * __ptr64,unsigned long) */

ulong __cdecl LpssApi_CheckControllerError(PBC_DEVICE *param_1,ulong param_2)

{
  PBC_DEVICE *UNRECOVERED_JUMPTABLE;
  ulong uVar1;
  
  UNRECOVERED_JUMPTABLE = *(PBC_DEVICE **)(param_1 + 400);
  ChvP1I2c_ControllerIoGenerateStart(UNRECOVERED_JUMPTABLE,param_2);
                    /* WARNING: Could not recover jumptable at 0x00014000f7f3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(code *)UNRECOVERED_JUMPTABLE)(param_1,param_2);
  return uVar1;
}



===== LpssApi_CheckControllerFinishData @ 14000f7f8 =====

/* unsigned long __cdecl LpssApi_CheckControllerFinishData(struct PBC_DEVICE * __ptr64,unsigned
   long) */

ulong __cdecl LpssApi_CheckControllerFinishData(PBC_DEVICE *param_1,ulong param_2)

{
  PBC_DEVICE *UNRECOVERED_JUMPTABLE;
  ulong uVar1;
  
  UNRECOVERED_JUMPTABLE = *(PBC_DEVICE **)(param_1 + 0x1b0);
  ChvP1I2c_ControllerIoGenerateStart(UNRECOVERED_JUMPTABLE,param_2);
                    /* WARNING: Could not recover jumptable at 0x00014000f833. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(code *)UNRECOVERED_JUMPTABLE)(param_1,param_2);
  return uVar1;
}



===== LpssApi_CheckControllerReadyForTransfer @ 14000f838 =====

/* unsigned long __cdecl LpssApi_CheckControllerReadyForTransfer(struct PBC_DEVICE *
   __ptr64,unsigned long) */

ulong __cdecl LpssApi_CheckControllerReadyForTransfer(PBC_DEVICE *param_1,ulong param_2)

{
  PBC_DEVICE *UNRECOVERED_JUMPTABLE;
  ulong uVar1;
  
  UNRECOVERED_JUMPTABLE = *(PBC_DEVICE **)(param_1 + 0x198);
  ChvP1I2c_ControllerIoGenerateStart(UNRECOVERED_JUMPTABLE,param_2);
                    /* WARNING: Could not recover jumptable at 0x00014000f873. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(code *)UNRECOVERED_JUMPTABLE)(param_1,param_2);
  return uVar1;
}



===== LpssApi_CheckControllerTransferDone @ 14000f878 =====

/* unsigned long __cdecl LpssApi_CheckControllerTransferDone(struct PBC_DEVICE * __ptr64,unsigned
   long) */

ulong __cdecl LpssApi_CheckControllerTransferDone(PBC_DEVICE *param_1,ulong param_2)

{
  PBC_DEVICE *UNRECOVERED_JUMPTABLE;
  ulong uVar1;
  
  UNRECOVERED_JUMPTABLE = *(PBC_DEVICE **)(param_1 + 0x1a8);
  ChvP1I2c_ControllerIoGenerateStart(UNRECOVERED_JUMPTABLE,param_2);
                    /* WARNING: Could not recover jumptable at 0x00014000f8b3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(code *)UNRECOVERED_JUMPTABLE)(param_1,param_2);
  return uVar1;
}



===== LpssApi_CheckControllerTransferOngoing @ 14000f8b8 =====

/* unsigned long __cdecl LpssApi_CheckControllerTransferOngoing(struct PBC_DEVICE * __ptr64,unsigned
   long) */

ulong __cdecl LpssApi_CheckControllerTransferOngoing(PBC_DEVICE *param_1,ulong param_2)

{
  PBC_DEVICE *UNRECOVERED_JUMPTABLE;
  ulong uVar1;
  
  UNRECOVERED_JUMPTABLE = *(PBC_DEVICE **)(param_1 + 0x1a0);
  ChvP1I2c_ControllerIoGenerateStart(UNRECOVERED_JUMPTABLE,param_2);
                    /* WARNING: Could not recover jumptable at 0x00014000f8f3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(code *)UNRECOVERED_JUMPTABLE)(param_1,param_2);
  return uVar1;
}



===== LpssApi_ConfigureForTransferDma @ 14000f8f8 =====

/* long __cdecl LpssApi_ConfigureForTransferDma(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST *
   __ptr64) */

long __cdecl LpssApi_ConfigureForTransferDma(PBC_DEVICE *param_1,PBC_REQUEST *param_2)

{
  PBC_DEVICE *UNRECOVERED_JUMPTABLE;
  long lVar1;
  
  UNRECOVERED_JUMPTABLE = *(PBC_DEVICE **)(param_1 + 0x170);
  ChvP1I2c_ControllerIoGenerateStart(UNRECOVERED_JUMPTABLE,(ulong)param_2);
                    /* WARNING: Could not recover jumptable at 0x00014000f935. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = (*(code *)UNRECOVERED_JUMPTABLE)(param_1,param_2);
  return lVar1;
}



===== LpssApi_ConfigureForTransferEnd @ 14000f938 =====

/* long __cdecl LpssApi_ConfigureForTransferEnd(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST *
   __ptr64) */

long __cdecl LpssApi_ConfigureForTransferEnd(PBC_DEVICE *param_1,PBC_REQUEST *param_2)

{
  PBC_DEVICE *UNRECOVERED_JUMPTABLE;
  long lVar1;
  
  UNRECOVERED_JUMPTABLE = *(PBC_DEVICE **)(param_1 + 0x150);
  ChvP1I2c_ControllerIoGenerateStart(UNRECOVERED_JUMPTABLE,(ulong)param_2);
                    /* WARNING: Could not recover jumptable at 0x00014000f975. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = (*(code *)UNRECOVERED_JUMPTABLE)(param_1,param_2);
  return lVar1;
}



===== LpssApi_ConfigureForTransferFromDevice @ 14000f978 =====

/* long __cdecl LpssApi_ConfigureForTransferFromDevice(struct PBC_DEVICE * __ptr64,struct
   PBC_REQUEST * __ptr64) */

long __cdecl LpssApi_ConfigureForTransferFromDevice(PBC_DEVICE *param_1,PBC_REQUEST *param_2)

{
  PBC_DEVICE *UNRECOVERED_JUMPTABLE;
  long lVar1;
  
  UNRECOVERED_JUMPTABLE = *(PBC_DEVICE **)(param_1 + 0x160);
  ChvP1I2c_ControllerIoGenerateStart(UNRECOVERED_JUMPTABLE,(ulong)param_2);
                    /* WARNING: Could not recover jumptable at 0x00014000f9b5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = (*(code *)UNRECOVERED_JUMPTABLE)(param_1,param_2);
  return lVar1;
}



===== LpssApi_ConfigureForTransferPio @ 14000f9b8 =====

/* long __cdecl LpssApi_ConfigureForTransferPio(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST *
   __ptr64) */

long __cdecl LpssApi_ConfigureForTransferPio(PBC_DEVICE *param_1,PBC_REQUEST *param_2)

{
  PBC_DEVICE *UNRECOVERED_JUMPTABLE;
  long lVar1;
  
  UNRECOVERED_JUMPTABLE = *(PBC_DEVICE **)(param_1 + 0x178);
  ChvP1I2c_ControllerIoGenerateStart(UNRECOVERED_JUMPTABLE,(ulong)param_2);
                    /* WARNING: Could not recover jumptable at 0x00014000f9f5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = (*(code *)UNRECOVERED_JUMPTABLE)(param_1,param_2);
  return lVar1;
}



===== LpssApi_ConfigureForTransferPostSettings @ 14000f9f8 =====

/* long __cdecl LpssApi_ConfigureForTransferPostSettings(struct PBC_DEVICE * __ptr64,struct
   PBC_REQUEST * __ptr64) */

long __cdecl LpssApi_ConfigureForTransferPostSettings(PBC_DEVICE *param_1,PBC_REQUEST *param_2)

{
  PBC_DEVICE *UNRECOVERED_JUMPTABLE;
  long lVar1;
  
  UNRECOVERED_JUMPTABLE = *(PBC_DEVICE **)(param_1 + 0x168);
  ChvP1I2c_ControllerIoGenerateStart(UNRECOVERED_JUMPTABLE,(ulong)param_2);
                    /* WARNING: Could not recover jumptable at 0x00014000fa35. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = (*(code *)UNRECOVERED_JUMPTABLE)(param_1,param_2);
  return lVar1;
}



===== LpssApi_ConfigureForTransferPreSettings @ 14000fa38 =====

/* long __cdecl LpssApi_ConfigureForTransferPreSettings(struct PBC_DEVICE * __ptr64,struct
   PBC_REQUEST * __ptr64) */

long __cdecl LpssApi_ConfigureForTransferPreSettings(PBC_DEVICE *param_1,PBC_REQUEST *param_2)

{
  PBC_DEVICE *UNRECOVERED_JUMPTABLE;
  long lVar1;
  
  UNRECOVERED_JUMPTABLE = *(PBC_DEVICE **)(param_1 + 0x140);
  ChvP1I2c_ControllerIoGenerateStart(UNRECOVERED_JUMPTABLE,(ulong)param_2);
                    /* WARNING: Could not recover jumptable at 0x00014000fa75. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = (*(code *)UNRECOVERED_JUMPTABLE)(param_1,param_2);
  return lVar1;
}



===== LpssApi_ConfigureForTransferStart @ 14000fa78 =====

/* long __cdecl LpssApi_ConfigureForTransferStart(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST *
   __ptr64) */

long __cdecl LpssApi_ConfigureForTransferStart(PBC_DEVICE *param_1,PBC_REQUEST *param_2)

{
  PBC_DEVICE *UNRECOVERED_JUMPTABLE;
  long lVar1;
  
  UNRECOVERED_JUMPTABLE = *(PBC_DEVICE **)(param_1 + 0x148);
  ChvP1I2c_ControllerIoGenerateStart(UNRECOVERED_JUMPTABLE,(ulong)param_2);
                    /* WARNING: Could not recover jumptable at 0x00014000fab5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = (*(code *)UNRECOVERED_JUMPTABLE)(param_1,param_2);
  return lVar1;
}



===== LpssApi_ConfigureForTransferToDevice @ 14000fab8 =====

/* long __cdecl LpssApi_ConfigureForTransferToDevice(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST
   * __ptr64) */

long __cdecl LpssApi_ConfigureForTransferToDevice(PBC_DEVICE *param_1,PBC_REQUEST *param_2)

{
  PBC_DEVICE *UNRECOVERED_JUMPTABLE;
  long lVar1;
  
  UNRECOVERED_JUMPTABLE = *(PBC_DEVICE **)(param_1 + 0x158);
  ChvP1I2c_ControllerIoGenerateStart(UNRECOVERED_JUMPTABLE,(ulong)param_2);
                    /* WARNING: Could not recover jumptable at 0x00014000faf5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = (*(code *)UNRECOVERED_JUMPTABLE)(param_1,param_2);
  return lVar1;
}



===== LpssApi_ControllerInitialize @ 14000faf8 =====

/* long __cdecl LpssApi_ControllerInitialize(struct PBC_DEVICE * __ptr64) */

long __cdecl LpssApi_ControllerInitialize(PBC_DEVICE *param_1)

{
  PBC_DEVICE *UNRECOVERED_JUMPTABLE;
  long lVar1;
  ulong in_EDX;
  
  UNRECOVERED_JUMPTABLE = *(PBC_DEVICE **)(param_1 + 0x118);
  ChvP1I2c_ControllerIoGenerateStart(UNRECOVERED_JUMPTABLE,in_EDX);
                    /* WARNING: Could not recover jumptable at 0x00014000fb25. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = (*(code *)UNRECOVERED_JUMPTABLE)(param_1);
  return lVar1;
}



===== LpssApi_ControllerIoGenerateStop @ 14000fb28 =====

/* void __cdecl LpssApi_ControllerIoGenerateStop(struct PBC_DEVICE * __ptr64,unsigned long) */

void __cdecl LpssApi_ControllerIoGenerateStop(PBC_DEVICE *param_1,ulong param_2)

{
  PBC_DEVICE *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(PBC_DEVICE **)(param_1 + 0x218);
  ChvP1I2c_ControllerIoGenerateStart(UNRECOVERED_JUMPTABLE,param_2);
                    /* WARNING: Could not recover jumptable at 0x00014000fb63. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)UNRECOVERED_JUMPTABLE)(param_1,param_2);
  return;
}



===== LpssApi_ControllerUnitialize @ 14000fb68 =====

/* long __cdecl LpssApi_ControllerUnitialize(struct PBC_DEVICE * __ptr64) */

long __cdecl LpssApi_ControllerUnitialize(PBC_DEVICE *param_1)

{
  PBC_DEVICE *UNRECOVERED_JUMPTABLE;
  long lVar1;
  ulong in_EDX;
  
  UNRECOVERED_JUMPTABLE = *(PBC_DEVICE **)(param_1 + 0x120);
  ChvP1I2c_ControllerIoGenerateStart(UNRECOVERED_JUMPTABLE,in_EDX);
                    /* WARNING: Could not recover jumptable at 0x00014000fb95. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = (*(code *)UNRECOVERED_JUMPTABLE)(param_1);
  return lVar1;
}



===== LpssApi_DisableInterrupts @ 14000fb98 =====

/* void __cdecl LpssApi_DisableInterrupts(struct PBC_DEVICE * __ptr64) */

void __cdecl LpssApi_DisableInterrupts(PBC_DEVICE *param_1)

{
  PBC_DEVICE *UNRECOVERED_JUMPTABLE;
  ulong in_EDX;
  
  UNRECOVERED_JUMPTABLE = *(PBC_DEVICE **)(param_1 + 0x1c0);
  ChvP1I2c_ControllerIoGenerateStart(UNRECOVERED_JUMPTABLE,in_EDX);
                    /* WARNING: Could not recover jumptable at 0x00014000fbc5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)UNRECOVERED_JUMPTABLE)(param_1);
  return;
}



===== LpssApi_DmaInitialize @ 14000fbc8 =====

/* long __cdecl LpssApi_DmaInitialize(struct PBC_DEVICE * __ptr64) */

long __cdecl LpssApi_DmaInitialize(PBC_DEVICE *param_1)

{
  PBC_DEVICE *UNRECOVERED_JUMPTABLE;
  long lVar1;
  ulong in_EDX;
  
  UNRECOVERED_JUMPTABLE = *(PBC_DEVICE **)(param_1 + 0x108);
  ChvP1I2c_ControllerIoGenerateStart(UNRECOVERED_JUMPTABLE,in_EDX);
                    /* WARNING: Could not recover jumptable at 0x00014000fbf5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = (*(code *)UNRECOVERED_JUMPTABLE)(param_1);
  return lVar1;
}



===== LpssApi_DmaPostCompletion @ 14000fbf8 =====

/* void __cdecl LpssApi_DmaPostCompletion(struct PBC_DEVICE * __ptr64) */

void __cdecl LpssApi_DmaPostCompletion(PBC_DEVICE *param_1)

{
  PBC_DEVICE *UNRECOVERED_JUMPTABLE;
  ulong in_EDX;
  
  UNRECOVERED_JUMPTABLE = *(PBC_DEVICE **)(param_1 + 0x200);
  ChvP1I2c_ControllerIoGenerateStart(UNRECOVERED_JUMPTABLE,in_EDX);
                    /* WARNING: Could not recover jumptable at 0x00014000fc25. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)UNRECOVERED_JUMPTABLE)(param_1);
  return;
}



===== LpssApi_DmaPreExecute @ 14000fc28 =====

/* void __cdecl LpssApi_DmaPreExecute(struct PBC_DEVICE * __ptr64) */

void __cdecl LpssApi_DmaPreExecute(PBC_DEVICE *param_1)

{
  PBC_DEVICE *UNRECOVERED_JUMPTABLE;
  ulong in_EDX;
  
  UNRECOVERED_JUMPTABLE = *(PBC_DEVICE **)(param_1 + 0x208);
  ChvP1I2c_ControllerIoGenerateStart(UNRECOVERED_JUMPTABLE,in_EDX);
                    /* WARNING: Could not recover jumptable at 0x00014000fc55. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)UNRECOVERED_JUMPTABLE)(param_1);
  return;
}



===== LpssApi_DmaUninitialize @ 14000fc58 =====

/* long __cdecl LpssApi_DmaUninitialize(struct PBC_DEVICE * __ptr64) */

long __cdecl LpssApi_DmaUninitialize(PBC_DEVICE *param_1)

{
  PBC_DEVICE *UNRECOVERED_JUMPTABLE;
  long lVar1;
  ulong in_EDX;
  
  UNRECOVERED_JUMPTABLE = *(PBC_DEVICE **)(param_1 + 0x110);
  ChvP1I2c_ControllerIoGenerateStart(UNRECOVERED_JUMPTABLE,in_EDX);
                    /* WARNING: Could not recover jumptable at 0x00014000fc85. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = (*(code *)UNRECOVERED_JUMPTABLE)(param_1);
  return lVar1;
}



===== LpssApi_EnableInterrupts @ 14000fc88 =====

/* void __cdecl LpssApi_EnableInterrupts(struct PBC_DEVICE * __ptr64,unsigned long) */

void __cdecl LpssApi_EnableInterrupts(PBC_DEVICE *param_1,ulong param_2)

{
  PBC_DEVICE *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(PBC_DEVICE **)(param_1 + 0x1b8);
  ChvP1I2c_ControllerIoGenerateStart(UNRECOVERED_JUMPTABLE,param_2);
                    /* WARNING: Could not recover jumptable at 0x00014000fcc3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)UNRECOVERED_JUMPTABLE)(param_1,param_2);
  return;
}



===== LpssApi_GetInterruptStatus @ 14000fcc8 =====

/* unsigned long __cdecl LpssApi_GetInterruptStatus(struct PBC_DEVICE * __ptr64,unsigned long) */

ulong __cdecl LpssApi_GetInterruptStatus(PBC_DEVICE *param_1,ulong param_2)

{
  PBC_DEVICE *UNRECOVERED_JUMPTABLE;
  ulong uVar1;
  
  UNRECOVERED_JUMPTABLE = *(PBC_DEVICE **)(param_1 + 0x1c8);
  ChvP1I2c_ControllerIoGenerateStart(UNRECOVERED_JUMPTABLE,param_2);
                    /* WARNING: Could not recover jumptable at 0x00014000fd03. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(code *)UNRECOVERED_JUMPTABLE)(param_1,param_2);
  return uVar1;
}



===== LpssApi_InitializeSettings @ 14000fd08 =====

/* long __cdecl LpssApi_InitializeSettings(struct PBC_DEVICE * __ptr64) */

long __cdecl LpssApi_InitializeSettings(PBC_DEVICE *param_1)

{
  PBC_DEVICE *UNRECOVERED_JUMPTABLE;
  long lVar1;
  ulong in_EDX;
  
  UNRECOVERED_JUMPTABLE = *(PBC_DEVICE **)(param_1 + 0xe8);
  ChvP1I2c_ControllerIoGenerateStart(UNRECOVERED_JUMPTABLE,in_EDX);
                    /* WARNING: Could not recover jumptable at 0x00014000fd35. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = (*(code *)UNRECOVERED_JUMPTABLE)(param_1);
  return lVar1;
}



===== LpssApi_IsAbortByAddressPhase @ 14000fd38 =====

/* unsigned char __cdecl LpssApi_IsAbortByAddressPhase(struct PBC_DEVICE * __ptr64) */

uchar __cdecl LpssApi_IsAbortByAddressPhase(PBC_DEVICE *param_1)

{
  PBC_DEVICE *UNRECOVERED_JUMPTABLE;
  uchar uVar1;
  ulong in_EDX;
  
  UNRECOVERED_JUMPTABLE = *(PBC_DEVICE **)(param_1 + 0x220);
  ChvP1I2c_ControllerIoGenerateStart(UNRECOVERED_JUMPTABLE,in_EDX);
                    /* WARNING: Could not recover jumptable at 0x00014000fd65. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(code *)UNRECOVERED_JUMPTABLE)(param_1);
  return uVar1;
}



===== LpssApi_PrepareForTransfer @ 14000fd68 =====

/* long __cdecl LpssApi_PrepareForTransfer(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST * __ptr64)
    */

long __cdecl LpssApi_PrepareForTransfer(PBC_DEVICE *param_1,PBC_REQUEST *param_2)

{
  long lVar1;
  PBC_DEVICE *pPVar2;
  
  if (*(int *)(param_2 + 0x44) == 2) {
    pPVar2 = *(PBC_DEVICE **)(param_1 + 0x1d8);
  }
  else {
    if (*(int *)(param_2 + 0x44) != 1) {
      return 0;
    }
    pPVar2 = *(PBC_DEVICE **)(param_1 + 0x1e0);
  }
  ChvP1I2c_ControllerIoGenerateStart(pPVar2,(ulong)param_2);
  lVar1 = (*(code *)pPVar2)(param_1,param_2);
  return lVar1;
}



===== LpssApi_ReleaseResources @ 14000fdc0 =====

/* long __cdecl LpssApi_ReleaseResources(struct PBC_DEVICE * __ptr64) */

long __cdecl LpssApi_ReleaseResources(PBC_DEVICE *param_1)

{
  PBC_DEVICE *pPVar1;
  longlong lVar2;
  long lVar3;
  ulong uVar4;
  ulong in_EDX;
  
  pPVar1 = *(PBC_DEVICE **)(param_1 + 0x100);
  ChvP1I2c_ControllerIoGenerateStart(pPVar1,in_EDX);
  lVar3 = (*(code *)pPVar1)(param_1);
  lVar2 = *(longlong *)(param_1 + 0x58);
  if (lVar2 != 0) {
    uVar4 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(lVar2 + 0x84));
    HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(lVar2 + 0x84),uVar4 | 3);
    HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x58) + 0x84));
    MmUnmapIoSpace(*(undefined8 *)(param_1 + 0x58),*(undefined4 *)(param_1 + 0x60));
    *(undefined8 *)(param_1 + 0x58) = 0;
    *(undefined4 *)(param_1 + 0x60) = 0;
  }
  return lVar3;
}



===== LpssApi_RestoreContext @ 14000fe48 =====

/* long __cdecl LpssApi_RestoreContext(struct PBC_DEVICE * __ptr64) */

long __cdecl LpssApi_RestoreContext(PBC_DEVICE *param_1)

{
  PBC_DEVICE *UNRECOVERED_JUMPTABLE;
  long lVar1;
  ulong in_EDX;
  
  UNRECOVERED_JUMPTABLE = *(PBC_DEVICE **)(param_1 + 0x130);
  ChvP1I2c_ControllerIoGenerateStart(UNRECOVERED_JUMPTABLE,in_EDX);
                    /* WARNING: Could not recover jumptable at 0x00014000fe75. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = (*(code *)UNRECOVERED_JUMPTABLE)(param_1);
  return lVar1;
}



===== LpssApi_TargetGetSettings @ 14000fe78 =====

/* long __cdecl LpssApi_TargetGetSettings(struct PBC_DEVICE * __ptr64,void * __ptr64,struct
   PBC_TARGET_SETTINGS * __ptr64) */

long __cdecl
LpssApi_TargetGetSettings(PBC_DEVICE *param_1,void *param_2,PBC_TARGET_SETTINGS *param_3)

{
  PBC_DEVICE *UNRECOVERED_JUMPTABLE;
  long lVar1;
  
  UNRECOVERED_JUMPTABLE = *(PBC_DEVICE **)(param_1 + 0x138);
  ChvP1I2c_ControllerIoGenerateStart(UNRECOVERED_JUMPTABLE,(ulong)param_2);
                    /* WARNING: Could not recover jumptable at 0x00014000fec5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = (*(code *)UNRECOVERED_JUMPTABLE)(param_1,param_2,param_3);
  return lVar1;
}



===== LpssApi_TransferDataRead @ 14000fec8 =====

/* long __cdecl LpssApi_TransferDataRead(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST * __ptr64)
    */

long __cdecl LpssApi_TransferDataRead(PBC_DEVICE *param_1,PBC_REQUEST *param_2)

{
  PBC_DEVICE *UNRECOVERED_JUMPTABLE;
  long lVar1;
  
  UNRECOVERED_JUMPTABLE = *(PBC_DEVICE **)(param_1 + 0x1f0);
  ChvP1I2c_ControllerIoGenerateStart(UNRECOVERED_JUMPTABLE,(ulong)param_2);
                    /* WARNING: Could not recover jumptable at 0x00014000ff05. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = (*(code *)UNRECOVERED_JUMPTABLE)(param_1,param_2);
  return lVar1;
}



===== LpssApi_TransferDataWrite @ 14000ff08 =====

/* long __cdecl LpssApi_TransferDataWrite(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST * __ptr64)
    */

long __cdecl LpssApi_TransferDataWrite(PBC_DEVICE *param_1,PBC_REQUEST *param_2)

{
  PBC_DEVICE *UNRECOVERED_JUMPTABLE;
  long lVar1;
  
  UNRECOVERED_JUMPTABLE = *(PBC_DEVICE **)(param_1 + 0x1e8);
  ChvP1I2c_ControllerIoGenerateStart(UNRECOVERED_JUMPTABLE,(ulong)param_2);
                    /* WARNING: Could not recover jumptable at 0x00014000ff45. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = (*(code *)UNRECOVERED_JUMPTABLE)(param_1,param_2);
  return lVar1;
}



===== LpssApi_UpdateTransferDataSize @ 14000ff48 =====

/* unsigned __int64 __cdecl LpssApi_UpdateTransferDataSize(struct PBC_DEVICE * __ptr64) */

__uint64 __cdecl LpssApi_UpdateTransferDataSize(PBC_DEVICE *param_1)

{
  PBC_DEVICE *UNRECOVERED_JUMPTABLE;
  __uint64 _Var1;
  ulong in_EDX;
  
  UNRECOVERED_JUMPTABLE = *(PBC_DEVICE **)(param_1 + 0x1f8);
  ChvP1I2c_ControllerIoGenerateStart(UNRECOVERED_JUMPTABLE,in_EDX);
                    /* WARNING: Could not recover jumptable at 0x00014000ff75. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _Var1 = (*(code *)UNRECOVERED_JUMPTABLE)(param_1);
  return _Var1;
}



===== LpssApi_ValidateAllResources @ 14000ff78 =====

/* long __cdecl LpssApi_ValidateAllResources(struct PBC_DEVICE * __ptr64) */

long __cdecl LpssApi_ValidateAllResources(PBC_DEVICE *param_1)

{
  PBC_DEVICE *UNRECOVERED_JUMPTABLE;
  long lVar1;
  ulong in_EDX;
  
  UNRECOVERED_JUMPTABLE = *(PBC_DEVICE **)(param_1 + 0xf8);
  ChvP1I2c_ControllerIoGenerateStart(UNRECOVERED_JUMPTABLE,in_EDX);
                    /* WARNING: Could not recover jumptable at 0x00014000ffa5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = (*(code *)UNRECOVERED_JUMPTABLE)(param_1);
  return lVar1;
}



===== LpssApi_ValidateResource @ 14000ffa8 =====

/* long __cdecl LpssApi_ValidateResource(struct PBC_DEVICE * __ptr64,unsigned char) */

long __cdecl LpssApi_ValidateResource(PBC_DEVICE *param_1,uchar param_2)

{
  PBC_DEVICE *UNRECOVERED_JUMPTABLE;
  long lVar1;
  undefined3 in_register_00000011;
  
  UNRECOVERED_JUMPTABLE = *(PBC_DEVICE **)(param_1 + 0xf0);
  ChvP1I2c_ControllerIoGenerateStart(UNRECOVERED_JUMPTABLE,CONCAT31(in_register_00000011,param_2));
                    /* WARNING: Could not recover jumptable at 0x00014000ffe5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = (*(code *)UNRECOVERED_JUMPTABLE)(param_1,param_2);
  return lVar1;
}



===== LpssApi_VerifyHardware @ 14000ffe8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl LpssApi_VerifyHardware(struct WDFDEVICE__ * __ptr64) */

long __cdecl LpssApi_VerifyHardware(WDFDEVICE__ *param_1)

{
  PBC_DEVICE *pPVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  PBC_DEVICE *pPVar5;
  undefined1 *_Dst;
  longlong lVar6;
  ulong in_EDX;
  ulong uVar7;
  WDFDEVICE__ *pWVar8;
  undefined1 *puVar9;
  ulonglong uVar10;
  undefined1 auStack_2e8 [32];
  ulong local_2b8;
  uint local_2b4;
  undefined1 local_2b0 [16];
  undefined1 local_2a0 [24];
  wchar_t *local_288;
  int local_280 [2];
  code *local_278 [2];
  undefined4 local_268;
  code *local_260;
  undefined8 local_258;
  undefined4 local_250;
  undefined8 local_248;
  undefined1 local_238 [512];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_2e8;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    in_EDX = 10;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_cade0c8bec5232dc457469c5f08fa6b4_Traceguids);
  }
  pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x650);
  ChvP1I2c_ControllerIoGenerateStart(pPVar1,in_EDX);
  pPVar5 = (PBC_DEVICE *)
           (*(code *)pPVar1)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140016020);
  memset(local_238,0,0x200);
  *(undefined4 *)(pPVar5 + 0x6c) = 0xff;
  pPVar5[0x3b0] = (PBC_DEVICE)0x0;
  local_288 = L"ACPI\\VEN_8086&DEV_0F41&REV_0002";
  local_258 = 0;
  local_278[0] = VlvI2c_SetupDispatchers;
  *(undefined8 *)(pPVar5 + 100) = 2;
  local_278[1] = (code *)&u_ACPI_VEN_8086_DEV_22C1;
  _Dst = (undefined1 *)0x0;
  local_248 = 0;
  local_260 = ChvP1I2c_SetupDispatchers;
  uVar10 = 0;
  local_280[0] = 1;
  local_268 = 1;
  local_250 = 2;
  pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x288);
  ChvP1I2c_ControllerIoGenerateStart(pPVar1,2);
  pWVar8 = param_1;
  iVar2 = (*(code *)pPVar1)(WdfDriverGlobals,param_1,1,0x200);
  uVar7 = (ulong)pWVar8;
  puVar9 = local_238;
  if (iVar2 == -0x3fffffdd) {
    _Dst = (undefined1 *)ExAllocatePoolWithTag(0x200,local_2b4,0x53504c69);
    if (_Dst != (undefined1 *)0x0) {
      uVar7 = 0;
      memset(_Dst,0,(ulonglong)local_2b4);
      pPVar1 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x288);
      ChvP1I2c_ControllerIoGenerateStart(pPVar1,uVar7);
      iVar2 = (*(code *)pPVar1)(WdfDriverGlobals,param_1,1,local_2b4);
      uVar7 = (ulong)param_1;
      if (-1 < iVar2) {
        puVar9 = _Dst;
        RtlInitUnicodeString(local_2b0);
        uVar7 = (ulong)puVar9;
        puVar9 = _Dst;
        goto LAB_1400101cf;
      }
      goto LAB_14001023a;
    }
  }
  else {
LAB_1400101cf:
    if (-1 < iVar2) {
      RtlInitUnicodeString(local_2b0,puVar9);
      lVar6 = 0;
      do {
        RtlInitUnicodeString(local_2a0,*(undefined8 *)(local_2a0 + lVar6 + 0x18));
        puVar9 = local_2a0;
        iVar3 = RtlCompareUnicodeString(local_2b0,puVar9,1);
        uVar7 = (ulong)puVar9;
        if (iVar3 == 0) {
          iVar3 = local_280[uVar10 * 6];
          *(int *)(pPVar5 + 100) = iVar3;
          if (iVar3 == 1) {
            pPVar5[0x3b0] = (PBC_DEVICE)0x1;
          }
          break;
        }
        uVar10 = (ulonglong)((int)uVar10 + 1);
        lVar6 = uVar10 * 0x18;
      } while (local_280[uVar10 * 6] != 2);
    }
LAB_14001023a:
    if (_Dst != (undefined1 *)0x0) {
      uVar7 = 0x53504c69;
      ExFreePoolWithTag(_Dst);
    }
    if ((-1 < iVar2) && (*(int *)(pPVar5 + 100) < 2)) {
      pPVar1 = (PBC_DEVICE *)local_278[uVar10 * 3];
      ChvP1I2c_ControllerIoGenerateStart(pPVar1,uVar7);
      (*(code *)pPVar1)(pPVar5);
      local_2b8 = 0;
      LpssAcpi_GetAcpiMethodData(pPVar5,"_UID",&local_2b8);
      *(ulong *)(pPVar5 + 0x6c) = local_2b8;
      local_2b8 = 0;
      lVar4 = LpssAcpi_GetAcpiMethodData(pPVar5,"_SEM",&local_2b8);
      if (lVar4 == -0x3ffffffe) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                    &WPP_cade0c8bec5232dc457469c5f08fa6b4_Traceguids,*(undefined4 *)(pPVar5 + 0x6c),
                    (char)local_2b8);
        }
        lVar4 = 0;
      }
      if (lVar4 < 0) {
        if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
          if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                     &WPP_cade0c8bec5232dc457469c5f08fa6b4_Traceguids,lVar4);
          }
          goto LAB_14001033d;
        }
      }
      else {
LAB_14001033d:
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                   &WPP_cade0c8bec5232dc457469c5f08fa6b4_Traceguids,local_2b8);
        }
      }
      if ((lVar4 == 0) && (local_2b8 == 1)) {
        pPVar5[0x41] = (PBC_DEVICE)0x1;
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return 0;
        }
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                   &WPP_cade0c8bec5232dc457469c5f08fa6b4_Traceguids,*(undefined4 *)(pPVar5 + 0x6c));
        }
      }
      else {
        pPVar5[0x41] = (PBC_DEVICE)0x0;
      }
      goto LAB_140010406;
    }
  }
  *(code **)(pPVar5 + 0x100) = ChvP1I2c_ConfigureForTransferEnd;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
             &WPP_cade0c8bec5232dc457469c5f08fa6b4_Traceguids,iVar2);
  }
  lVar4 = -0x3ffffe7e;
LAB_140010406:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
            &WPP_cade0c8bec5232dc457469c5f08fa6b4_Traceguids);
  }
  return lVar4;
}



===== LpssApi_VerifySpbLockSupport @ 140010468 =====

/* unsigned char __cdecl LpssApi_VerifySpbLockSupport(struct WDFDEVICE__ * __ptr64) */

uchar __cdecl LpssApi_VerifySpbLockSupport(WDFDEVICE__ *param_1)

{
  char cVar1;
  PBC_DEVICE *pPVar2;
  undefined *puVar3;
  longlong lVar4;
  ulong in_EDX;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    in_EDX = 0x11;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
            &WPP_cade0c8bec5232dc457469c5f08fa6b4_Traceguids);
  }
  puVar3 = PTR__WDF_PBC_DEVICE_TYPE_INFO_140016020;
  pPVar2 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x650);
  ChvP1I2c_ControllerIoGenerateStart(pPVar2,in_EDX);
  lVar4 = (*(code *)pPVar2)(WdfDriverGlobals,param_1,puVar3);
  cVar1 = *(char *)(lVar4 + 0x41);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
            &WPP_cade0c8bec5232dc457469c5f08fa6b4_Traceguids);
  }
  return cVar1 == '\0';
}



===== VlvI2c_AcknowledgeInterrupts @ 140010530 =====

/* void __cdecl VlvI2c_AcknowledgeInterrupts(struct PBC_DEVICE * __ptr64,unsigned long) */

void __cdecl VlvI2c_AcknowledgeInterrupts(PBC_DEVICE *param_1,ulong param_2)

{
  longlong lVar1;
  ulong uVar2;
  ulong uVar3;
  uint uVar4;
  
  uVar2 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x820));
  uVar3 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x34));
  uVar4 = uVar3 & param_2;
  if ((uVar4 & 1) != 0) {
    HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x44));
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,
              &WPP_5000268d7bd03bbcd2cafa4a21cbf4fa_Traceguids);
    }
  }
  if ((uVar4 & 2) != 0) {
    HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x48));
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,
              &WPP_5000268d7bd03bbcd2cafa4a21cbf4fa_Traceguids);
    }
  }
  if ((((uVar4 & 4) != 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
     (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0 && (3 < (byte)WPP_GLOBAL_Control[0x29])))) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,
            &WPP_5000268d7bd03bbcd2cafa4a21cbf4fa_Traceguids);
  }
  if ((uVar4 & 8) != 0) {
    HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x4c));
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,
              &WPP_5000268d7bd03bbcd2cafa4a21cbf4fa_Traceguids);
    }
  }
  if ((((uVar4 & 0x10) != 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
     (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0 && (3 < (byte)WPP_GLOBAL_Control[0x29])))) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,
            &WPP_5000268d7bd03bbcd2cafa4a21cbf4fa_Traceguids);
  }
  if ((uVar4 & 0x20) != 0) {
    HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x50));
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x24,
              &WPP_5000268d7bd03bbcd2cafa4a21cbf4fa_Traceguids);
    }
  }
  if ((uVar4 & 0x40) != 0) {
    uVar3 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x80));
    *(ulong *)(param_1 + 0xe0) = uVar3;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x25,
               &WPP_5000268d7bd03bbcd2cafa4a21cbf4fa_Traceguids,uVar3);
    }
  }
  if ((char)uVar4 < '\0') {
    HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x58));
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x26,
              &WPP_5000268d7bd03bbcd2cafa4a21cbf4fa_Traceguids);
    }
  }
  if ((uVar4 & 0x100) != 0) {
    HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x5c));
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x27,
              &WPP_5000268d7bd03bbcd2cafa4a21cbf4fa_Traceguids);
    }
  }
  if ((uVar4 & 0x200) != 0) {
    HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x60));
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x28,
              &WPP_5000268d7bd03bbcd2cafa4a21cbf4fa_Traceguids);
    }
  }
  if ((uVar4 & 0x400) != 0) {
    HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 100));
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x29,
              &WPP_5000268d7bd03bbcd2cafa4a21cbf4fa_Traceguids);
    }
  }
  if ((uVar4 & 0x800) != 0) {
    HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x68));
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2a,
              &WPP_5000268d7bd03bbcd2cafa4a21cbf4fa_Traceguids);
    }
  }
  if ((uVar4 & 0x100000) != 0 || (uVar2 & 1) != 0) {
    lVar1 = *(longlong *)(param_1 + 8);
    uVar2 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(lVar1 + 0x808));
    HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(lVar1 + 0x808),uVar2 & 0xffffffef);
    HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x824));
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
              &WPP_5000268d7bd03bbcd2cafa4a21cbf4fa_Traceguids);
    }
  }
  return;
}



===== VlvI2c_CheckControllerError @ 1400108f0 =====

/* unsigned long __cdecl VlvI2c_CheckControllerError(struct PBC_DEVICE * __ptr64,unsigned long) */

ulong __cdecl VlvI2c_CheckControllerError(PBC_DEVICE *param_1,ulong param_2)

{
  ulong uVar1;
  
  uVar1 = 0;
  if ((param_2 >> 1 & 1) != 0) {
    uVar1 = 2;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
              &WPP_5000268d7bd03bbcd2cafa4a21cbf4fa_Traceguids);
    }
  }
  return uVar1;
}



===== VlvI2c_ConfigureForTransferPostSettings @ 140010940 =====

/* long __cdecl VlvI2c_ConfigureForTransferPostSettings(struct PBC_DEVICE * __ptr64,struct
   PBC_REQUEST * __ptr64) */

long __cdecl VlvI2c_ConfigureForTransferPostSettings(PBC_DEVICE *param_1,PBC_REQUEST *param_2)

{
  longlong lVar1;
  PBC_DEVICE *pPVar2;
  ulong uVar3;
  uint uVar4;
  
  lVar1 = *(longlong *)(param_1 + 8);
  uVar3 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(lVar1 + 0x808));
  HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(lVar1 + 0x808),uVar3 & 0xffffffef);
  lVar1 = *(longlong *)(param_1 + 8);
  uVar3 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(lVar1 + 0x818));
  HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(lVar1 + 0x818),uVar3 | 0x80000);
  lVar1 = *(longlong *)(param_1 + 8);
  uVar3 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(lVar1 + 0x818));
  uVar4 = uVar3 & 0xfff7ffff;
  HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(lVar1 + 0x818),uVar4);
  pPVar2 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x480);
  ChvP1I2c_ControllerIoGenerateStart(pPVar2,uVar4);
  uVar3 = (ulong)*(undefined8 *)(param_1 + 0x28);
  (*(code *)pPVar2)(WdfDriverGlobals);
  ControllerDisableInterrupts(param_1);
  LOCK();
  *(undefined4 *)(param_1 + 0x30) = 0;
  UNLOCK();
  *(undefined4 *)(param_1 + 0x34) = 0;
  pPVar2 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x488);
  ChvP1I2c_ControllerIoGenerateStart(pPVar2,uVar3);
  (*(code *)pPVar2)(WdfDriverGlobals);
  HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x88),0);
  *(undefined8 *)(param_2 + 0x80) = 0;
  return 0;
}



===== VlvI2c_ConfigureForTransferStart @ 140010a40 =====

/* long __cdecl VlvI2c_ConfigureForTransferStart(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST *
   __ptr64) */

long __cdecl VlvI2c_ConfigureForTransferStart(PBC_DEVICE *param_1,PBC_REQUEST *param_2)

{
  ushort uVar1;
  uchar uVar2;
  ulong uVar3;
  uint uVar4;
  long lVar5;
  
  lVar5 = 0;
  uVar2 = VlvI2c_DisableController(param_1);
  if (uVar2 != '\0') {
    uVar3 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x54));
    if ((uVar3 != 0) || (*(int *)(param_1 + 0xe0) != 0)) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0 && (2 < (byte)WPP_GLOBAL_Control[0x29])))
         ) {
        WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
                  &WPP_5000268d7bd03bbcd2cafa4a21cbf4fa_Traceguids,uVar3,
                  (char)*(undefined4 *)(param_1 + 0xe0));
      }
      *(undefined4 *)(param_1 + 0xe0) = 0;
    }
    uVar1 = *(ushort *)(*(longlong *)(param_1 + 0x20) + 0xc);
    uVar4 = uVar1 | 0x1000;
    if (*(int *)(*(longlong *)(param_1 + 0x20) + 8) != 1) {
      uVar4 = (uint)uVar1;
    }
    HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 4),uVar4);
    uVar4 = (*(uint *)(*(longlong *)(param_1 + 0x20) + 0x10) & 3) * 2;
    if (param_1[0xdc] == (PBC_DEVICE)0x0) {
      uVar3 = uVar4 | 0x61;
    }
    else {
      uVar3 = uVar4 | 0x41;
    }
    HWREG<unsigned_long>::Write(*(HWREG<unsigned_long> **)(param_1 + 8),uVar3);
    VlvI2c_SetRuntimeClock(param_1);
    uVar2 = VlvI2c_EnableController(param_1);
    if (uVar2 != '\0') {
      param_1[0x70] = (PBC_DEVICE)0x1;
      goto LAB_140010b32;
    }
  }
  lVar5 = -0x3ffffe7e;
LAB_140010b32:
  *(long *)(param_2 + 0x20) = lVar5;
  return lVar5;
}



===== VlvI2c_ControllerInitialize @ 140010b50 =====

/* long __cdecl VlvI2c_ControllerInitialize(struct PBC_DEVICE * __ptr64) */

long __cdecl VlvI2c_ControllerInitialize(PBC_DEVICE *param_1)

{
  longlong lVar1;
  ulong uVar2;
  
  lVar1 = *(longlong *)(param_1 + 0x58);
  if (lVar1 != 0) {
    uVar2 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(lVar1 + 0x84));
    HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(lVar1 + 0x84),uVar2 & 0xfffffffc);
    HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x58) + 0x84));
  }
  HWREG<unsigned_long>::Write
            ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x804),0xfffffffc);
  HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x804),3);
  HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x800),1);
  HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x88),0);
  return 0;
}



===== VlvI2c_ControllerIoGenerateStop @ 140010bf0 =====

/* void __cdecl VlvI2c_ControllerIoGenerateStop(struct PBC_DEVICE * __ptr64,unsigned long) */

void __cdecl VlvI2c_ControllerIoGenerateStop(PBC_DEVICE *param_1,ulong param_2)

{
  longlong lVar1;
  int iVar2;
  ulong uVar3;
  int iVar4;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x38,
            &WPP_5000268d7bd03bbcd2cafa4a21cbf4fa_Traceguids);
  }
  HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x88),0);
  uVar3 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x808));
  if ((uVar3 >> 0x18 & 1) == 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x39,
              &WPP_5000268d7bd03bbcd2cafa4a21cbf4fa_Traceguids);
    }
    lVar1 = *(longlong *)(param_1 + 8);
    uVar3 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(lVar1 + 0x6c));
    HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(lVar1 + 0x6c),uVar3 | 2);
    uVar3 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x70));
    iVar2 = 100;
    if ((uVar3 & 0x20) != 0) {
      do {
        iVar4 = iVar2;
        if (iVar4 == 0) break;
        KeStallExecutionProcessor((ulonglong)param_2 / 10);
        uVar3 = HWREG<unsigned_long>::Read
                          ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x70));
        iVar2 = iVar4 + -1;
      } while ((uVar3 & 0x20) != 0);
      if (((iVar4 + -1 == 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
         (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0 && (1 < (byte)WPP_GLOBAL_Control[0x29])))
         ) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),iVar4 + 0x39,
                &WPP_5000268d7bd03bbcd2cafa4a21cbf4fa_Traceguids);
      }
    }
    HWREG<unsigned_long>::Write
              ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x804),0xfffffffc);
    KeStallExecutionProcessor(param_2);
    HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x804),3);
    KeStallExecutionProcessor(param_2);
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3b,
            &WPP_5000268d7bd03bbcd2cafa4a21cbf4fa_Traceguids);
  }
  return;
}



===== VlvI2c_DisableController @ 140010da0 =====

/* unsigned char __cdecl VlvI2c_DisableController(struct PBC_DEVICE * __ptr64) */

uchar __cdecl VlvI2c_DisableController(PBC_DEVICE *param_1)

{
  ulong uVar1;
  byte bVar2;
  uint uVar3;
  
  HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x6c),0);
  LOCK();
  UNLOCK();
  uVar1 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x9c));
  uVar3 = 0;
  bVar2 = (byte)uVar1 & 1;
  if ((uVar1 & 1) != 0) {
    do {
      if (9 < uVar3) break;
      KeStallExecutionProcessor(0x19);
      uVar1 = HWREG<unsigned_long>::Read
                        ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x9c));
      bVar2 = (byte)uVar1 & 1;
      uVar3 = uVar3 + 1;
    } while ((uVar1 & 1) != 0);
    if (bVar2 != 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3c,
                &WPP_5000268d7bd03bbcd2cafa4a21cbf4fa_Traceguids);
      }
      *(undefined4 *)(param_1 + 0x30) = 0;
    }
  }
  return bVar2 ^ 1;
}



===== VlvI2c_DmaPostCompletion @ 140010e60 =====

/* void __cdecl VlvI2c_DmaPostCompletion(struct PBC_DEVICE * __ptr64) */

void __cdecl VlvI2c_DmaPostCompletion(PBC_DEVICE *param_1)

{
  longlong lVar1;
  uint uVar2;
  ulong uVar3;
  char *pcVar4;
  
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])
       ) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x33,
              &WPP_5000268d7bd03bbcd2cafa4a21cbf4fa_Traceguids);
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      uVar2 = *(uint *)(param_1 + 0x378) & 0x600;
      if (uVar2 == 0x600) {
        pcVar4 = "RESTART/STOP";
      }
      else if (uVar2 == 0x400) {
        pcVar4 = "RESTART";
      }
      else {
        pcVar4 = " ";
        if (uVar2 == 0x200) {
          pcVar4 = "STOP";
        }
      }
      WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x34,
               &WPP_5000268d7bd03bbcd2cafa4a21cbf4fa_Traceguids,pcVar4);
    }
  }
  HWREG<unsigned_long>::Write
            ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x10),*(ulong *)(param_1 + 0x378)
            );
  *(longlong *)(param_1 + 0x360) = *(longlong *)(param_1 + 0x360) + 1;
  if ((*(uint *)(param_1 + 0x378) & 0x600) == 0x200) {
    lVar1 = *(longlong *)(param_1 + 8);
    uVar3 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(lVar1 + 0x808));
    HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(lVar1 + 0x808),uVar3 | 0x10);
  }
  else {
    LOCK();
    *(uint *)(param_1 + 0x3a4) = *(uint *)(param_1 + 0x3a4) | 1;
    UNLOCK();
    *(undefined4 *)(param_1 + 0x35c) = 1;
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x35,
            &WPP_5000268d7bd03bbcd2cafa4a21cbf4fa_Traceguids);
  }
  return;
}



===== VlvI2c_DmaPreExecute @ 140010fb0 =====

/* void __cdecl VlvI2c_DmaPreExecute(struct PBC_DEVICE * __ptr64) */

void __cdecl VlvI2c_DmaPreExecute(PBC_DEVICE *param_1)

{
  int iVar1;
  ulong uVar2;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x36,
            &WPP_5000268d7bd03bbcd2cafa4a21cbf4fa_Traceguids);
  }
  HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x8c),0);
  HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x90),0);
  uVar2 = 2;
  iVar1 = *(int *)(*(longlong *)(*(longlong *)(param_1 + 0x20) + 0x18) + 0x44);
  if (iVar1 != 2) {
    if (iVar1 != 1) goto LAB_140011042;
    uVar2 = 3;
  }
  HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x88),uVar2);
LAB_140011042:
  LOCK();
  *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 0x100242;
  UNLOCK();
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x37,
            &WPP_5000268d7bd03bbcd2cafa4a21cbf4fa_Traceguids);
  }
  return;
}



===== VlvI2c_EnableController @ 140011084 =====

/* unsigned char __cdecl VlvI2c_EnableController(struct PBC_DEVICE * __ptr64) */

uchar __cdecl VlvI2c_EnableController(PBC_DEVICE *param_1)

{
  ulong uVar1;
  byte bVar2;
  uint uVar3;
  
  LOCK();
  UNLOCK();
  HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x6c),1);
  LOCK();
  UNLOCK();
  uVar1 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x9c));
  uVar3 = 0;
  bVar2 = (byte)uVar1 & 1;
  if ((uVar1 & 1) == 0) {
    do {
      if (9 < uVar3) break;
      KeStallExecutionProcessor(0x19);
      uVar1 = HWREG<unsigned_long>::Read
                        ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x9c));
      bVar2 = (byte)uVar1 & 1;
      uVar3 = uVar3 + 1;
    } while ((uVar1 & 1) == 0);
    if (bVar2 == 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3d,
                &WPP_5000268d7bd03bbcd2cafa4a21cbf4fa_Traceguids);
      }
      *(undefined4 *)(param_1 + 0x30) = 0;
    }
  }
  return bVar2;
}



===== VlvI2c_GetInterruptStatus @ 140011150 =====

/* unsigned long __cdecl VlvI2c_GetInterruptStatus(struct PBC_DEVICE * __ptr64,unsigned long) */

ulong __cdecl VlvI2c_GetInterruptStatus(PBC_DEVICE *param_1,ulong param_2)

{
  ulong uVar1;
  ulong uVar2;
  ulong uVar3;
  
  uVar1 = 0;
  if (param_1[0x250] != (PBC_DEVICE)0x0) {
    uVar1 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x820))
    ;
    uVar2 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x34));
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      uVar3 = HWREG<unsigned_long>::Read
                        ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x34));
      WPP_SF_DDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
                 &WPP_5000268d7bd03bbcd2cafa4a21cbf4fa_Traceguids,uVar3,0,(char)param_2);
    }
    uVar1 = (uVar2 | (uVar1 & 1) << 0x14) & param_2;
  }
  return uVar1;
}



===== VlvI2c_InitializeSettings @ 140011210 =====

/* long __cdecl VlvI2c_InitializeSettings(struct PBC_DEVICE * __ptr64) */

long __cdecl VlvI2c_InitializeSettings(PBC_DEVICE *param_1)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
            &WPP_5000268d7bd03bbcd2cafa4a21cbf4fa_Traceguids);
  }
  *(undefined4 *)(param_1 + 0x74) = 0xff;
  *(undefined4 *)(param_1 + 0x78) = 0xffff;
  param_1[0xdc] = (PBC_DEVICE)0x0;
  *(undefined4 *)(param_1 + 0x7c) = 0x200;
  *(undefined4 *)(param_1 + 0x80) = 0x200;
  *(undefined4 *)(param_1 + 0x84) = 6;
  *(undefined4 *)(param_1 + 0x88) = 6;
  *(undefined4 *)(param_1 + 0x94) = 6;
  *(undefined4 *)(param_1 + 0x98) = 6;
  *(undefined4 *)(param_1 + 0xa4) = 6;
  *(undefined4 *)(param_1 + 0xa8) = 6;
  *(undefined4 *)(param_1 + 0xb4) = 6;
  *(undefined4 *)(param_1 + 0xb8) = 6;
  *(undefined4 *)(param_1 + 0x8c) = 0x55;
  *(undefined4 *)(param_1 + 0x90) = 0x96;
  *(undefined4 *)(param_1 + 0x9c) = 0x1b;
  *(undefined4 *)(param_1 + 0xa0) = 0x3a;
  *(undefined4 *)(param_1 + 0xac) = 10;
  *(undefined4 *)(param_1 + 0xb0) = 0x25;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
            &WPP_5000268d7bd03bbcd2cafa4a21cbf4fa_Traceguids);
  }
  return 0;
}



===== VlvI2c_OverrideRegistrySettings @ 140011324 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl VlvI2c_OverrideRegistrySettings(struct PBC_DEVICE * __ptr64) */

long __cdecl VlvI2c_OverrideRegistrySettings(PBC_DEVICE *param_1)

{
  ulong uVar1;
  PBC_DEVICE *pPVar2;
  int iVar3;
  long lVar4;
  char *pcVar5;
  size_t sVar6;
  ulong uVar7;
  WDFKEY__ *pWVar8;
  uint uVar9;
  undefined1 auStackY_2b8 [32];
  WDFKEY__ *local_288;
  ulong local_280 [2];
  char *local_278;
  undefined4 local_270 [2];
  undefined1 *local_268;
  undefined1 local_260 [8];
  char *local_258;
  undefined1 local_250 [24];
  undefined1 local_238 [512];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_2b8;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
            &WPP_5000268d7bd03bbcd2cafa4a21cbf4fa_Traceguids);
  }
  uVar1 = *(ulong *)(param_1 + 0x6c);
  local_268 = local_238;
  uVar7 = 0x40013a50;
  local_270[0] = 0x2000000;
  RtlInitUnicodeString(local_250);
  pPVar2 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x728);
  ChvP1I2c_ControllerIoGenerateStart(pPVar2,uVar7);
  iVar3 = (*(code *)pPVar2)(WdfDriverGlobals,0,local_250,0x20019);
  if (iVar3 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar3;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0) && (2 < (byte)WPP_GLOBAL_Control[0x29])
       ) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
               &WPP_5000268d7bd03bbcd2cafa4a21cbf4fa_Traceguids,iVar3);
    }
  }
  else {
    LpssRegistry_GetRegistryKeyString
              (uVar1,local_288,0,(ushort *)L"ForceDma",(_UNICODE_STRING *)local_270);
    RtlInitAnsiString(local_260,0);
    iVar3 = RtlUnicodeStringToAnsiString(local_260,local_270);
    if (-1 < iVar3) {
      local_278 = (char *)0x0;
      pcVar5 = strtok_s(local_258,",",&local_278);
      uVar9 = 1;
      if (uVar1 != 0) {
        do {
          pcVar5 = strtok_s((char *)0x0,",",&local_278);
          if (pcVar5 == (char *)0x0) goto LAB_140011501;
          uVar9 = uVar9 + 1;
        } while (uVar9 <= uVar1);
      }
      if ((pcVar5 != (char *)0x0) && (sVar6 = strnlen(pcVar5,10), sVar6 < 10)) {
        lVar4 = atol(pcVar5);
        *(long *)(param_1 + 0x31c) = lVar4;
      }
LAB_140011501:
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
                  &WPP_5000268d7bd03bbcd2cafa4a21cbf4fa_Traceguids,uVar1,
                  (char)*(undefined4 *)(param_1 + 0x31c));
      }
    }
    RtlFreeAnsiString(local_260);
    local_280[0] = 0;
    LpssRegistry_GetRegistryKeyUlong(uVar1,local_288,0,(ushort *)L"NoRestartCondition",local_280);
    local_280[0] = local_280[0] >> ((char)uVar1 - 1U & 0x1f);
    param_1[0xdc] = (PBC_DEVICE)((byte)local_280[0] & 1);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      pcVar5 = "supports";
      if ((local_280[0] & 1) != 0) {
        pcVar5 = "does not support";
      }
      WPP_SF_Ls(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
                &WPP_5000268d7bd03bbcd2cafa4a21cbf4fa_Traceguids,uVar1,pcVar5);
    }
    LpssRegistry_GetRegistryKeyUlong
              (uVar1,local_288,0,(ushort *)L"FifoSize",(ulong *)(param_1 + 0x74));
    LpssRegistry_GetRegistryKeyUlong
              (uVar1,local_288,0,(ushort *)L"BufferSize",(ulong *)(param_1 + 0x78));
    LpssRegistry_GetRegistryKeyUlong
              (uVar1,local_288,0,(ushort *)&u_BUS_SS_HCNT,(ulong *)(param_1 + 0x7c));
    LpssRegistry_GetRegistryKeyUlong
              (uVar1,local_288,0,(ushort *)&u_BUS_SS_LCNT,(ulong *)(param_1 + 0x80));
    LpssRegistry_GetRegistryKeyUlong
              (uVar1,local_288,0,(ushort *)&u_BUS_SS_SDA,(ulong *)(param_1 + 0x84));
    LpssRegistry_GetRegistryKeyUlong
              (uVar1,local_288,0,(ushort *)&u_BUS_SS_SDA_SETUP,(ulong *)(param_1 + 0x88));
    LpssRegistry_GetRegistryKeyUlong
              (uVar1,local_288,0,(ushort *)&u_BUS_FS_HCNT,(ulong *)(param_1 + 0x8c));
    LpssRegistry_GetRegistryKeyUlong
              (uVar1,local_288,0,(ushort *)&u_BUS_FS_LCNT,(ulong *)(param_1 + 0x90));
    LpssRegistry_GetRegistryKeyUlong
              (uVar1,local_288,0,(ushort *)&u_BUS_FS_SDA,(ulong *)(param_1 + 0x94));
    LpssRegistry_GetRegistryKeyUlong
              (uVar1,local_288,0,(ushort *)&u_BUS_FS_SDA_SETUP,(ulong *)(param_1 + 0x98));
    LpssRegistry_GetRegistryKeyUlong
              (uVar1,local_288,0,(ushort *)&u_BUS_FP_HCNT,(ulong *)(param_1 + 0x9c));
    LpssRegistry_GetRegistryKeyUlong
              (uVar1,local_288,0,(ushort *)&u_BUS_FP_LCNT,(ulong *)(param_1 + 0xa0));
    LpssRegistry_GetRegistryKeyUlong
              (uVar1,local_288,0,(ushort *)&u_BUS_FP_SDA,(ulong *)(param_1 + 0xa4));
    LpssRegistry_GetRegistryKeyUlong
              (uVar1,local_288,0,(ushort *)&u_BUS_FP_SDA_SETUP,(ulong *)(param_1 + 0xa8));
    LpssRegistry_GetRegistryKeyUlong
              (uVar1,local_288,0,(ushort *)&u_BUS_HS_HCNT,(ulong *)(param_1 + 0xac));
    LpssRegistry_GetRegistryKeyUlong
              (uVar1,local_288,0,(ushort *)&u_BUS_HS_LCNT,(ulong *)(param_1 + 0xb0));
    LpssRegistry_GetRegistryKeyUlong
              (uVar1,local_288,0,(ushort *)&u_BUS_HS_SDA,(ulong *)(param_1 + 0xb4));
    pWVar8 = local_288;
    LpssRegistry_GetRegistryKeyUlong
              (uVar1,local_288,0,(ushort *)&u_BUS_HS_SDA_SETUP,(ulong *)(param_1 + 0xb8));
    pPVar2 = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x738);
    ChvP1I2c_ControllerIoGenerateStart(pPVar2,(ulong)pWVar8);
    (*(code *)pPVar2)(WdfDriverGlobals,local_288);
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
            &WPP_5000268d7bd03bbcd2cafa4a21cbf4fa_Traceguids);
  }
  return iVar3;
}



===== VlvI2c_PrepareForRead @ 1400118c0 =====

/* long __cdecl VlvI2c_PrepareForRead(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST * __ptr64) */

long __cdecl VlvI2c_PrepareForRead(PBC_DEVICE *param_1,PBC_REQUEST *param_2)

{
  ulonglong uVar1;
  longlong lVar2;
  ulong uVar3;
  uint uVar4;
  char cVar5;
  uint uVar6;
  ulonglong uVar7;
  ulong uVar8;
  uint uVar9;
  int local_res8;
  int local_res10;
  
  uVar7 = *(ulonglong *)(param_2 + 0x50);
  uVar1 = *(ulonglong *)(param_2 + 0x28);
  uVar8 = 0x242;
  uVar9 = 0;
  uVar3 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x78));
  local_res8 = 0xff - uVar3;
  uVar3 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x74));
  local_res10 = 0x100 - uVar3;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_PPPLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2c,
                 &WPP_5000268d7bd03bbcd2cafa4a21cbf4fa_Traceguids,uVar1 - uVar7,(char)uVar7,
                 (char)uVar1,(char)local_res10,(char)local_res8);
  }
  lVar2 = *(longlong *)(param_1 + 8);
  uVar3 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(lVar2 + 0x800));
  HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(lVar2 + 0x800),uVar3 & 0xfffffffe);
  *(undefined2 *)(param_2 + 0x78) = 0;
  if (uVar7 < uVar1) {
    cVar5 = '\x01';
    do {
      if ((local_res10 == 0) || (local_res8 == 0)) break;
      uVar4 = (-(uint)(uVar7 != 0) & 0xfffffc00) + 0x500;
      if ((param_2[0x41] == (PBC_REQUEST)0x0) || (uVar1 - uVar7 != 1)) {
LAB_140011a0b:
        uVar6 = uVar4;
        if (*(short *)(param_2 + 0x78) != 0) goto LAB_140011a11;
      }
      else {
        *(undefined2 *)(param_2 + 0x78) = 1;
        uVar6 = uVar4 | 0x200;
        if (uVar1 == 1) {
          uVar4 = uVar4 | 0x600;
          goto LAB_140011a0b;
        }
LAB_140011a11:
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_Xq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2d,
                    &WPP_5000268d7bd03bbcd2cafa4a21cbf4fa_Traceguids,uVar7 + 1,cVar5);
        }
      }
      HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x10),uVar6)
      ;
      cVar5 = cVar5 + '\x01';
      *(longlong *)(param_2 + 0x50) = *(longlong *)(param_2 + 0x50) + 1;
      local_res8 = local_res8 + -1;
      local_res10 = local_res10 + -1;
      uVar9 = uVar9 + 1;
      uVar7 = uVar7 + 1;
    } while (uVar7 < uVar1);
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2e,
             &WPP_5000268d7bd03bbcd2cafa4a21cbf4fa_Traceguids,uVar9);
  }
  lVar2 = *(longlong *)(param_1 + 8);
  uVar3 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(lVar2 + 0x800));
  HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(lVar2 + 0x800),uVar3 | 1);
  if (*(short *)(param_2 + 0x78) == 0) {
    uVar3 = 0;
    if (1 < uVar9) {
      uVar3 = uVar9 - 1;
    }
    HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x38),uVar3);
    uVar8 = 0x246;
  }
  VlvI2c_SetTransferInterrupts(param_1,uVar8,0);
  *(ulonglong *)(param_2 + 0x80) = *(longlong *)(param_2 + 0x80) + (ulonglong)uVar9;
  return 0;
}



===== VlvI2c_PrepareForWrite @ 140011b60 =====

/* long __cdecl VlvI2c_PrepareForWrite(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST * __ptr64) */

long __cdecl VlvI2c_PrepareForWrite(PBC_DEVICE *param_1,PBC_REQUEST *param_2)

{
  VlvI2c_SetTransferInterrupts(param_1,0x242,0);
  return 0;
}



===== VlvI2c_ReleaseResources @ 140011b80 =====

/* long __cdecl VlvI2c_ReleaseResources(struct PBC_DEVICE * __ptr64) */

long __cdecl VlvI2c_ReleaseResources(PBC_DEVICE *param_1)

{
  longlong lVar1;
  ulong uVar2;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
            &WPP_5000268d7bd03bbcd2cafa4a21cbf4fa_Traceguids);
  }
  ChvP1I2c_ControllerUnitialize(param_1);
  if (*(longlong *)(param_1 + 8) != 0) {
    HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x800),0);
    lVar1 = *(longlong *)(param_1 + 8);
    uVar2 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(lVar1 + 0x804));
    HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(lVar1 + 0x804),uVar2 & 0xfffffffc);
  }
  lVar1 = *(longlong *)(param_1 + 0x58);
  if (lVar1 != 0) {
    uVar2 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(lVar1 + 0x84));
    HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(lVar1 + 0x84),uVar2 | 3);
    HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x58) + 0x84));
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
            &WPP_5000268d7bd03bbcd2cafa4a21cbf4fa_Traceguids);
  }
  return 0;
}



===== VlvI2c_RestoreContext @ 140011c80 =====

/* long __cdecl VlvI2c_RestoreContext(struct PBC_DEVICE * __ptr64) */

long __cdecl VlvI2c_RestoreContext(PBC_DEVICE *param_1)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
            &WPP_5000268d7bd03bbcd2cafa4a21cbf4fa_Traceguids);
  }
  VlvI2c_InitializeSettings(param_1);
  VlvI2c_OverrideRegistrySettings(param_1);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
            &WPP_5000268d7bd03bbcd2cafa4a21cbf4fa_Traceguids);
  }
  return 0;
}



===== VlvI2c_SetRuntimeClock @ 140011d10 =====

/* void __cdecl VlvI2c_SetRuntimeClock(struct PBC_DEVICE * __ptr64) */

void __cdecl VlvI2c_SetRuntimeClock(PBC_DEVICE *param_1)

{
  longlong lVar1;
  longlong lVar2;
  ulong uVar3;
  undefined4 uVar4;
  
  lVar1 = *(longlong *)(param_1 + 0x20);
  uVar4 = 2;
  lVar2 = *(longlong *)(param_1 + 8);
  if (*(int *)(lVar1 + 0x10) == 2) {
    if (*(int *)(lVar1 + 0x14) == 4) {
      HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(lVar2 + 0x1c),*(ulong *)(param_1 + 0x9c))
      ;
      HWREG<unsigned_long>::Write
                ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x20),
                 *(ulong *)(param_1 + 0xa0));
      HWREG<unsigned_long>::Write
                ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x7c),
                 *(ulong *)(param_1 + 0xa4));
      uVar3 = *(ulong *)(param_1 + 0xa8);
      uVar4 = 10;
    }
    else {
      HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(lVar2 + 0x1c),*(ulong *)(param_1 + 0x8c))
      ;
      HWREG<unsigned_long>::Write
                ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x20),
                 *(ulong *)(param_1 + 0x90));
      HWREG<unsigned_long>::Write
                ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x7c),
                 *(ulong *)(param_1 + 0x94));
      uVar3 = *(ulong *)(param_1 + 0x98);
      uVar4 = 0x19;
    }
  }
  else if (*(int *)(lVar1 + 0x10) == 3) {
    HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(lVar2 + 0x24),*(ulong *)(param_1 + 0xac));
    HWREG<unsigned_long>::Write
              ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x28),
               *(ulong *)(param_1 + 0xb0));
    HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x1c),0x55);
    HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x20),0x96);
    HWREG<unsigned_long>::Write
              ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x7c),
               *(ulong *)(param_1 + 0xb4));
    uVar3 = *(ulong *)(param_1 + 0xb8);
  }
  else {
    HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(lVar2 + 0x14),*(ulong *)(param_1 + 0x7c));
    HWREG<unsigned_long>::Write
              ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x18),
               *(ulong *)(param_1 + 0x80));
    HWREG<unsigned_long>::Write
              ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x7c),
               *(ulong *)(param_1 + 0x84));
    uVar3 = *(ulong *)(param_1 + 0x88);
    uVar4 = 100;
  }
  HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x94),uVar3);
  *(undefined4 *)(lVar1 + 0x20) = uVar4;
  return;
}



===== VlvI2c_SetTransferInterrupts @ 140011e90 =====

/* void __cdecl VlvI2c_SetTransferInterrupts(struct PBC_DEVICE * __ptr64,unsigned long,unsigned
   long) */

void __cdecl VlvI2c_SetTransferInterrupts(PBC_DEVICE *param_1,ulong param_2,ulong param_3)

{
  PBC_DEVICE *UNRECOVERED_JUMPTABLE;
  ulong uVar1;
  
  uVar1 = param_2;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    uVar1 = 0x1c;
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
             &WPP_5000268d7bd03bbcd2cafa4a21cbf4fa_Traceguids,param_2);
  }
  UNRECOVERED_JUMPTABLE = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x480);
  ChvP1I2c_ControllerIoGenerateStart(UNRECOVERED_JUMPTABLE,uVar1);
  uVar1 = (ulong)*(undefined8 *)(param_1 + 0x28);
  (*(code *)UNRECOVERED_JUMPTABLE)(WdfDriverGlobals);
  ControllerDisableInterrupts(param_1);
  if (param_3 != 0) {
    LOCK();
    *(undefined4 *)(param_1 + 0x30) = 0;
    UNLOCK();
  }
  LOCK();
  *(ulong *)(param_1 + 0x30) = param_2;
  UNLOCK();
  *(undefined4 *)(param_1 + 0x34) = 0;
  UNRECOVERED_JUMPTABLE = *(PBC_DEVICE **)(WdfFunctions_01015 + 0x488);
  ChvP1I2c_ControllerIoGenerateStart(UNRECOVERED_JUMPTABLE,uVar1);
                    /* WARNING: Could not recover jumptable at 0x000140011f59. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)UNRECOVERED_JUMPTABLE)(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x28));
  return;
}



===== VlvI2c_SetupDispatchers @ 140011f60 =====

/* void __cdecl VlvI2c_SetupDispatchers(struct PBC_DEVICE * __ptr64) */

void __cdecl VlvI2c_SetupDispatchers(PBC_DEVICE *param_1)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_5000268d7bd03bbcd2cafa4a21cbf4fa_Traceguids);
  }
  *(code **)(param_1 + 0xe8) = VlvI2c_InitializeSettings;
  *(code **)(param_1 + 0xf0) = ChvP1I2c_ConfigureForTransferEnd;
  *(code **)(param_1 + 0xf8) = VlvI2c_ValidateAllResources;
  *(code **)(param_1 + 0x100) = VlvI2c_ReleaseResources;
  *(code **)(param_1 + 0x108) = ChvP1I2c_ConfigureForTransferEnd;
  *(code **)(param_1 + 0x110) = ChvP1I2c_ConfigureForTransferEnd;
  *(code **)(param_1 + 0x118) = VlvI2c_ControllerInitialize;
  *(code **)(param_1 + 0x120) = ChvP1I2c_ControllerUnitialize;
  *(code **)(param_1 + 0x128) = ChvP1I2c_ConfigureForTransferEnd;
  *(code **)(param_1 + 0x130) = VlvI2c_RestoreContext;
  *(code **)(param_1 + 0x138) = VlvI2c_TargetGetSettings;
  *(code **)(param_1 + 0x140) = VlvI2c_ConfigureForTransferPreSettings;
  *(code **)(param_1 + 0x148) = VlvI2c_ConfigureForTransferStart;
  *(code **)(param_1 + 0x150) = ChvP1I2c_ConfigureForTransferEnd;
  *(code **)(param_1 + 0x158) = ChvP1I2c_ConfigureForTransferEnd;
  *(code **)(param_1 + 0x160) = VlvI2c_ConfigureForTransferFromDevice;
  *(code **)(param_1 + 0x168) = VlvI2c_ConfigureForTransferPostSettings;
  *(code **)(param_1 + 0x170) = ChvP1I2c_ConfigureForTransferEnd;
  *(code **)(param_1 + 0x178) = ChvP1I2c_ConfigureForTransferEnd;
  *(code **)(param_1 + 0x180) = VlvI2c_SetTransferInterrupts;
  *(code **)(param_1 + 0x188) = ChvP1I2c_CheckControllerAbort;
  *(code **)(param_1 + 400) = VlvI2c_CheckControllerError;
  *(code **)(param_1 + 0x198) = VlvI2c_CheckControllerReadyForTransfer;
  *(code **)(param_1 + 0x1a0) = VlvI2c_CheckControllerTransferOngoing;
  *(code **)(param_1 + 0x1a8) = ChvP1I2c_CheckControllerTransferDone;
  *(code **)(param_1 + 0x1b0) = VlvI2c_CheckControllerFinishData;
  *(code **)(param_1 + 0x1b8) = ChvP1I2c_EnableInterrupts;
  *(code **)(param_1 + 0x1c0) = VlvI2c_DisableInterrupts;
  *(code **)(param_1 + 0x1c8) = VlvI2c_GetInterruptStatus;
  *(code **)(param_1 + 0x1d0) = VlvI2c_AcknowledgeInterrupts;
  *(code **)(param_1 + 0x1d8) = VlvI2c_PrepareForWrite;
  *(code **)(param_1 + 0x1e0) = VlvI2c_PrepareForRead;
  *(code **)(param_1 + 0x1e8) = VlvI2c_TransferDataWrite;
  *(code **)(param_1 + 0x1f0) = VlvI2c_TransferDataRead;
  *(code **)(param_1 + 0x1f8) = VlvI2c_UpdateTransferDataSize;
  *(code **)(param_1 + 0x200) = VlvI2c_DmaPostCompletion;
  *(code **)(param_1 + 0x208) = VlvI2c_DmaPreExecute;
  *(code **)(param_1 + 0x210) = ChvP1I2c_ControllerIoGenerateStart;
  *(code **)(param_1 + 0x218) = VlvI2c_ControllerIoGenerateStop;
  *(code **)(param_1 + 0x220) = ChvP1I2c_IsAbortByAddressPhase;
  *(code **)(param_1 + 0x228) = ChvP1I2c_IsAbortByDataPhase;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
            &WPP_5000268d7bd03bbcd2cafa4a21cbf4fa_Traceguids);
  }
  return;
}



===== VlvI2c_TargetGetSettings @ 140012220 =====

/* long __cdecl VlvI2c_TargetGetSettings(struct PBC_DEVICE * __ptr64,void * __ptr64,struct
   PBC_TARGET_SETTINGS * __ptr64) */

long __cdecl
VlvI2c_TargetGetSettings(PBC_DEVICE *param_1,void *param_2,PBC_TARGET_SETTINGS *param_3)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  uVar5 = 1;
  uVar6 = 2;
  if (*(char *)((longlong)param_2 + 5) != '\x01') {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3ffffff3;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) {
      return -0x3ffffff3;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return -0x3ffffff3;
    }
    WPP_SF_c(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
             &WPP_5000268d7bd03bbcd2cafa4a21cbf4fa_Traceguids,*(char *)((longlong)param_2 + 5));
    return -0x3ffffff3;
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
             &WPP_5000268d7bd03bbcd2cafa4a21cbf4fa_Traceguids,
             *(uint *)((longlong)param_2 + 0xc) / 1000);
  }
  uVar1 = *(ushort *)((longlong)param_2 + 0x10);
  *(ushort *)(param_3 + 4) = uVar1;
  uVar2 = *(ushort *)((longlong)param_2 + 7);
  *(uint *)param_3 = uVar2 & 1;
  if ((uVar2 & 1) == 0) {
    if (uVar1 < 0x80) {
LAB_140012356:
      iVar3 = *(int *)((longlong)param_2 + 0xc);
      if (iVar3 == 400000) {
        uVar5 = 2;
      }
      else if (iVar3 == 1000000) {
        uVar5 = 2;
        uVar6 = 4;
      }
      else if (iVar3 == 3400000) {
        uVar5 = 3;
      }
      *(undefined4 *)(param_3 + 8) = uVar5;
      *(undefined4 *)(param_3 + 0xc) = uVar6;
      return 0;
    }
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_14001231e;
    uVar4 = 0x19;
  }
  else {
    if (uVar1 < 0x400) goto LAB_140012356;
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_14001231e;
    uVar4 = 0x1a;
  }
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,
           &WPP_5000268d7bd03bbcd2cafa4a21cbf4fa_Traceguids,(uint)uVar1);
LAB_14001231e:
  *(undefined2 *)(param_3 + 4) = 0;
  return -0x3ffffff3;
}



===== VlvI2c_TransferDataRead @ 1400123b0 =====

/* long __cdecl VlvI2c_TransferDataRead(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST * __ptr64) */

long __cdecl VlvI2c_TransferDataRead(PBC_DEVICE *param_1,PBC_REQUEST *param_2)

{
  ulonglong uVar1;
  ulong uVar2;
  ulong uVar3;
  longlong lVar4;
  undefined8 *puVar5;
  long lVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  ulonglong in_stack_ffffffffffffffc8;
  
  uVar8 = *(ulonglong *)(param_2 + 0x58);
  lVar6 = 0;
  uVar1 = *(ulonglong *)(param_2 + 0x28);
  uVar2 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x78));
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    in_stack_ffffffffffffffc8 = uVar8;
    WPP_SF_Xq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x30,
              &WPP_5000268d7bd03bbcd2cafa4a21cbf4fa_Traceguids,(ulonglong)uVar2,(char)uVar8);
  }
  do {
    if ((uVar1 <= uVar8) || (uVar2 == 0)) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_Xq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x31,
                  &WPP_5000268d7bd03bbcd2cafa4a21cbf4fa_Traceguids,uVar8,
                  (char)*(undefined8 *)(param_2 + 0x80));
      }
      VlvI2c_SetTransferInterrupts(param_1,0x246,0);
      return lVar6;
    }
    HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x70));
    uVar3 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x10));
    lVar6 = -0x3ffffffc;
    if (uVar8 < *(ulonglong *)(param_2 + 0x28)) {
      uVar7 = uVar8;
      for (puVar5 = *(undefined8 **)(param_2 + 0x30); puVar5 != (undefined8 *)0x0;
          puVar5 = (undefined8 *)*puVar5) {
        if (uVar7 < *(uint *)(puVar5 + 5)) {
          if ((*(byte *)((longlong)puVar5 + 10) & 5) == 0) {
            in_stack_ffffffffffffffc8 = in_stack_ffffffffffffffc8 & 0xffffffff00000000;
            lVar4 = MmMapLockedPagesSpecifyCache(puVar5,0,1,0,in_stack_ffffffffffffffc8,0x40000010);
          }
          else {
            lVar4 = puVar5[3];
          }
          if (lVar4 != 0) {
            *(char *)(lVar4 + uVar7) = (char)uVar3;
            lVar6 = 0;
          }
          break;
        }
        uVar7 = uVar7 - *(uint *)(puVar5 + 5);
      }
    }
    if (lVar6 < 0) {
      return lVar6;
    }
    *(longlong *)(param_2 + 0x58) = *(longlong *)(param_2 + 0x58) + 1;
    uVar8 = uVar8 + 1;
    uVar2 = uVar2 - 1;
    *(longlong *)(param_2 + 0x80) = *(longlong *)(param_2 + 0x80) + -1;
  } while( true );
}



===== VlvI2c_TransferDataWrite @ 140012550 =====

/* long __cdecl VlvI2c_TransferDataWrite(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST * __ptr64)
    */

long __cdecl VlvI2c_TransferDataWrite(PBC_DEVICE *param_1,PBC_REQUEST *param_2)

{
  ulonglong uVar1;
  ulong uVar2;
  longlong lVar3;
  uint uVar4;
  undefined8 *puVar5;
  uint uVar6;
  ulonglong uVar7;
  long lVar8;
  ulonglong uVar9;
  uint uVar10;
  
  uVar9 = *(ulonglong *)(param_2 + 0x58);
  uVar1 = *(ulonglong *)(param_2 + 0x28);
  lVar8 = 0;
  uVar2 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x74));
  uVar10 = 0x100 - uVar2;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_P(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2f,
             &WPP_5000268d7bd03bbcd2cafa4a21cbf4fa_Traceguids,(ulonglong)uVar10);
  }
  lVar3 = *(longlong *)(param_1 + 8);
  uVar2 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(lVar3 + 0x800));
  HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(lVar3 + 0x800),uVar2 & 0xfffffffe);
  do {
    if ((uVar1 <= uVar9) || (uVar10 == 0)) {
      lVar3 = *(longlong *)(param_1 + 8);
      uVar2 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(lVar3 + 0x800));
      HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(lVar3 + 0x800),uVar2 | 1);
      VlvI2c_SetTransferInterrupts(param_1,0x100252,0);
      return lVar8;
    }
    uVar6 = 0;
    lVar8 = -0x3ffffffc;
    if (uVar9 < *(ulonglong *)(param_2 + 0x28)) {
      uVar7 = uVar9;
      for (puVar5 = *(undefined8 **)(param_2 + 0x30); puVar5 != (undefined8 *)0x0;
          puVar5 = (undefined8 *)*puVar5) {
        if (uVar7 < *(uint *)(puVar5 + 5)) {
          if ((*(byte *)((longlong)puVar5 + 10) & 5) == 0) {
            lVar3 = MmMapLockedPagesSpecifyCache(puVar5,0,1,0,0,0x40000010);
          }
          else {
            lVar3 = puVar5[3];
          }
          if (lVar3 != 0) {
            uVar6 = (uint)*(byte *)(lVar3 + uVar7);
            lVar8 = 0;
          }
          break;
        }
        uVar7 = uVar7 - *(uint *)(puVar5 + 5);
      }
    }
    if (lVar8 < 0) {
      return lVar8;
    }
    uVar4 = uVar6 | 0x400;
    if (uVar9 != 0) {
      uVar4 = uVar6;
    }
    uVar6 = uVar4;
    if (((param_2[0x41] != (PBC_REQUEST)0x0) && (uVar1 - uVar9 == 1)) &&
       (uVar6 = uVar4 | 0x200, uVar1 == 1)) {
      uVar6 = uVar4 | 0x600;
    }
    HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x10),uVar6);
    *(longlong *)(param_2 + 0x58) = *(longlong *)(param_2 + 0x58) + 1;
    uVar9 = uVar9 + 1;
    uVar10 = uVar10 - 1;
  } while( true );
}



===== VlvI2c_UpdateTransferDataSize @ 140012700 =====

/* unsigned __int64 __cdecl VlvI2c_UpdateTransferDataSize(struct PBC_DEVICE * __ptr64) */

__uint64 __cdecl VlvI2c_UpdateTransferDataSize(PBC_DEVICE *param_1)

{
  ulong uVar1;
  ulong uVar2;
  
  uVar1 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x818));
  uVar2 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x818));
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_Xq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x32,
              &WPP_5000268d7bd03bbcd2cafa4a21cbf4fa_Traceguids,(ulonglong)(uVar1 & 0xffff),0);
  }
  return (ulonglong)(uVar2 & 0x10000) + (ulonglong)(uVar1 & 0xffff);
}



===== VlvI2c_ValidateAllResources @ 140012790 =====

/* long __cdecl VlvI2c_ValidateAllResources(struct PBC_DEVICE * __ptr64) */

long __cdecl VlvI2c_ValidateAllResources(PBC_DEVICE *param_1)

{
  VlvI2c_OverrideRegistrySettings(param_1);
  return 0;
}



===== GetMBIDeviceObject @ 1400127a0 =====

/* long __cdecl GetMBIDeviceObject(struct _UNICODE_STRING * __ptr64,struct _DEVICE_OBJECT * __ptr64
   * __ptr64) */

long __cdecl GetMBIDeviceObject(_UNICODE_STRING *param_1,_DEVICE_OBJECT **param_2)

{
  int iVar1;
  undefined8 local_res8;
  
  local_res8 = 0;
  if (param_1 == (_UNICODE_STRING *)0x0) {
    iVar1 = -0x3fffffff;
  }
  else {
    iVar1 = IoGetDeviceObjectPointer(param_1,0x1f01ff,&local_res8,param_2);
    if (iVar1 < 0) {
      return iVar1;
    }
    ObfReferenceObject(*param_2);
    ObfDereferenceObject(local_res8);
  }
  return iVar1;
}



===== Init @ 1400127fc =====

/* public: long __cdecl CMBI::Init(void) __ptr64 */

long __thiscall CMBI::Init(CMBI *this)

{
  long lVar1;
  void *pvVar2;
  _DEVICE_OBJECT *local_res8;
  _UNICODE_STRING local_18 [16];
  
  local_res8 = (_DEVICE_OBJECT *)0x0;
  lVar1 = 0;
  *(undefined8 *)this = 0;
  pvVar2 = (void *)ExAllocatePoolWithTag(0x200,0x38,0x69626d64);
  if (pvVar2 != (void *)0x0) {
    RtlInitUnicodeString(local_18,L"\\Device\\MBI");
    lVar1 = GetMBIDeviceObject(local_18,&local_res8);
    if ((-1 < lVar1) &&
       (lVar1 = QueryMBIDeviceInterface(local_res8,pvVar2,(_GUID *)&DAT_140014438,0x38,3),
       -1 < lVar1)) {
      *(void **)this = pvVar2;
      return lVar1;
    }
    ExFreePoolWithTag(pvVar2,0x69626d64);
  }
  return lVar1;
}



===== MbiInterface_Create @ 1400128ac =====

/* long __cdecl MbiInterface_Create(class CMBI * __ptr64 * __ptr64) */

long __cdecl MbiInterface_Create(CMBI **param_1)

{
  long lVar1;
  CMBI *this;
  
  *param_1 = (CMBI *)0x0;
  this = (CMBI *)ExAllocatePoolWithTag(0x200,8,0x6962696d);
  if (this == (CMBI *)0x0) {
    lVar1 = -0x3fffff66;
  }
  else {
    *(undefined8 *)this = 0;
    lVar1 = CMBI::Init(this);
    if (lVar1 < 0) {
      ExFreePool(this);
    }
    else {
      *param_1 = this;
    }
  }
  return lVar1;
}



===== MbiInterface_Destroy @ 14001291c =====

/* void __cdecl MbiInterface_Destroy(class CMBI * __ptr64) */

void __cdecl MbiInterface_Destroy(CMBI *param_1)

{
  CMBI::destroy(param_1);
                    /* WARNING: Could not recover jumptable at 0x000140012932. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ExFreePool(param_1);
  return;
}



===== QueryMBIDeviceInterface @ 14001293c =====

/* long __cdecl QueryMBIDeviceInterface(struct _DEVICE_OBJECT * __ptr64,void * __ptr64,struct _GUID
   const * __ptr64,unsigned short,unsigned short) */

long __cdecl
QueryMBIDeviceInterface
          (_DEVICE_OBJECT *param_1,void *param_2,_GUID *param_3,ushort param_4,ushort param_5)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  int local_48 [4];
  undefined1 local_38 [32];
  
  if (param_1 == (_DEVICE_OBJECT *)0x0) {
    iVar2 = -0x3fffffff;
  }
  else {
    KeInitializeEvent(local_38,0,0);
    lVar3 = IoBuildSynchronousFsdRequest(0x1b,param_1,0,0,0,local_38,local_48);
    if (lVar3 == 0) {
      iVar2 = -0x3fffff66;
    }
    else {
      lVar1 = *(longlong *)(lVar3 + 0xb8);
      *(undefined4 *)(lVar3 + 0x30) = 0xc00000bb;
      memset((undefined2 *)(lVar1 + -0x48),0,0x48);
      *(ushort *)(lVar1 + -0x36) = param_5;
      *(undefined2 *)(lVar1 + -0x48) = 0x81b;
      *(_GUID **)(lVar1 + -0x40) = param_3;
      *(void **)(lVar1 + -0x30) = param_2;
      *(ushort *)(lVar1 + -0x38) = param_4;
      iVar2 = IofCallDriver(param_1,lVar3);
      if (iVar2 == 0x103) {
        KeWaitForSingleObject(local_38,0,0,0,0);
        iVar2 = local_48[0];
      }
    }
  }
  return iVar2;
}



===== Read @ 140012a44 =====

/* public: unsigned int __cdecl CMBI::Read(unsigned char,unsigned long) __ptr64 */

uint __thiscall CMBI::Read(CMBI *this,uchar param_1,ulong param_2)

{
  PBC_DEVICE *UNRECOVERED_JUMPTABLE;
  uint uVar1;
  undefined7 in_register_00000011;
  
  UNRECOVERED_JUMPTABLE = *(PBC_DEVICE **)(*(longlong *)this + 0x20);
  ChvP1I2c_ControllerIoGenerateStart
            (UNRECOVERED_JUMPTABLE,(ulong)CONCAT71(in_register_00000011,param_1));
                    /* WARNING: Could not recover jumptable at 0x000140012a97. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(code *)UNRECOVERED_JUMPTABLE)
                    (param_2 & 0xffffff00,(uint)param_1 << 0x10 | 0x100000f0 | (param_2 & 0xff) << 8
                    );
  return uVar1;
}



===== Write @ 140012a9c =====

/* public: void __cdecl CMBI::Write(unsigned char,unsigned long,unsigned int) __ptr64 */

void __thiscall CMBI::Write(CMBI *this,uchar param_1,ulong param_2,uint param_3)

{
  PBC_DEVICE *UNRECOVERED_JUMPTABLE;
  undefined7 in_register_00000011;
  
  UNRECOVERED_JUMPTABLE = *(PBC_DEVICE **)(*(longlong *)this + 0x28);
  ChvP1I2c_ControllerIoGenerateStart
            (UNRECOVERED_JUMPTABLE,(ulong)CONCAT71(in_register_00000011,param_1));
                    /* WARNING: Could not recover jumptable at 0x000140012aff. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)UNRECOVERED_JUMPTABLE)
            (param_2 & 0xffffff00,(uint)param_1 << 0x10 | 0x110000f0 | (param_2 & 0xff) << 8,param_3
            );
  return;
}



===== destroy @ 140012b04 =====

/* public: void __cdecl CMBI::destroy(void) __ptr64 */

void __thiscall CMBI::destroy(CMBI *this)

{
  longlong lVar1;
  PBC_DEVICE *pPVar2;
  ulong in_EDX;
  
  lVar1 = *(longlong *)this;
  if (lVar1 != 0) {
    pPVar2 = *(PBC_DEVICE **)(lVar1 + 0x18);
    ChvP1I2c_ControllerIoGenerateStart(pPVar2,in_EDX);
    (*(code *)pPVar2)(*(undefined8 *)(lVar1 + 8));
    ExFreePoolWithTag(*(undefined8 *)this,0x69626d64);
    *(undefined8 *)this = 0;
  }
  return;
}



===== __security_check_cookie @ 140012b70 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== __report_gsfailure @ 140012b90 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== __GSHandlerCheck @ 140012ba0 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 140012bc0 =====

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



===== strnlen @ 140012c20 =====

size_t __cdecl strnlen(char *_Str,size_t _MaxCount)

{
  size_t sVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000140012c20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  sVar1 = strnlen(_Str,_MaxCount);
  return sVar1;
}



===== strtok_s @ 140012c26 =====

char * __cdecl strtok_s(char *_Str,char *_Delim,char **_Context)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000140012c26. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = strtok_s(_Str,_Delim,_Context);
  return pcVar1;
}



===== atol @ 140012c2c =====

long __cdecl atol(char *_Str)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000140012c2c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = atol(_Str);
  return lVar1;
}



===== _vsnwprintf @ 140012c32 =====

int __cdecl _vsnwprintf(wchar_t *_Dest,size_t _Count,wchar_t *_Format,va_list _Args)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000140012c32. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = _vsnwprintf(_Dest,_Count,_Format,_Args);
  return iVar1;
}



===== FxStubDriverUnloadCommon @ 140012c38 =====

/* void __cdecl FxStubDriverUnloadCommon(void) */

void __cdecl FxStubDriverUnloadCommon(void)

{
  FxStubUnbindClasses((_WDF_BIND_INFO *)&DAT_1400160e0);
  WdfVersionUnbind(&DAT_140016268,&DAT_1400160e0,WdfDriverGlobals);
  return;
}



===== entry @ 140012c70 =====

void entry(ulonglong param_1,undefined8 param_2)

{
  __security_init_cookie();
  FxDriverEntryWorker(param_1,param_2);
  return;
}



===== FxDriverEntryWorker @ 140012c9c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FxDriverEntryWorker(ulonglong param_1,undefined8 param_2)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = DriverEntry(0,param_2);
  }
  else {
    _DAT_140016270 = &DAT_1400162a0;
    _DAT_140016268 = 0x2080000;
    _DAT_140016290 = param_1;
    RtlCopyUnicodeString(&DAT_140016268);
    iVar1 = WdfVersionBind(param_1,&DAT_140016268,&DAT_1400160e0,&WdfDriverGlobals);
    if (-1 < iVar1) {
      _WdfDriverMiniportUnloadOverride = *(code **)(WdfFunctions_01015 + 0x648);
      iVar1 = FxStubBindClasses((_WDF_BIND_INFO *)&DAT_1400160e0);
      if (((-1 < iVar1) && (iVar1 = FxStubInitTypes(), -1 < iVar1)) &&
         (iVar1 = DriverEntry(param_1,param_2), -1 < iVar1)) {
        if (*(char *)(WdfDriverGlobals + 0x30) == '\0') {
          if ((*(uint *)(WdfDriverGlobals + 8) & 2) != 0) {
            _WdfDriverMiniportUnloadOverride = FxStubDriverMiniportUnload;
          }
        }
        else {
          if (*(longlong *)(param_1 + 0x68) != 0) {
            DAT_140016278 = *(longlong *)(param_1 + 0x68);
          }
          *(code **)(param_1 + 0x68) = FxStubDriverUnload;
        }
        return 0;
      }
      FxStubDriverUnloadCommon();
    }
  }
  return iVar1;
}



===== FxStubDriverMiniportUnload @ 140012dd0 =====

void __cdecl FxStubDriverMiniportUnload(void)

{
  FxStubUnbindClasses((_WDF_BIND_INFO *)&DAT_1400160e0);
  WdfVersionUnbind(&DAT_140016268,&DAT_1400160e0,WdfDriverGlobals);
  return;
}



===== FxStubDriverUnload @ 140012de0 =====

void FxStubDriverUnload(undefined8 param_1,ulong param_2)

{
  PBC_DEVICE *pPVar1;
  
  pPVar1 = DAT_140016278;
  if ((DAT_140016278 != (PBC_DEVICE *)0x0) && (DAT_140016278 != (PBC_DEVICE *)FxStubDriverUnload)) {
    ChvP1I2c_ControllerIoGenerateStart(DAT_140016278,param_2);
    (*(code *)pPVar1)(param_1);
  }
  FxStubDriverUnloadCommon();
  return;
}



===== FxStubInitTypes @ 140012e24 =====

/* WARNING: Removing unreachable block (ram,0x000140012e59) */
/* WARNING: Removing unreachable block (ram,0x000140012e60) */
/* WARNING: Removing unreachable block (ram,0x000140012e9c) */
/* WARNING: Removing unreachable block (ram,0x000140012e66) */
/* WARNING: Removing unreachable block (ram,0x000140012e6e) */
/* WARNING: Removing unreachable block (ram,0x000140012e7d) */
/* WARNING: Removing unreachable block (ram,0x000140012e46) */
/* long __cdecl FxStubInitTypes(void) */

long __cdecl FxStubInitTypes(void)

{
  return 0;
}



===== FxStubBindClasses @ 140012ea4 =====

/* WARNING: Removing unreachable block (ram,0x000140012ed0) */
/* long __cdecl FxStubBindClasses(struct _WDF_BIND_INFO * __ptr64) */

long __cdecl FxStubBindClasses(_WDF_BIND_INFO *param_1)

{
  PBC_DEVICE *pPVar1;
  int iVar2;
  _WDF_BIND_INFO *in_RDX;
  int *piVar3;
  
  iVar2 = 0;
  piVar3 = &_SPBCx_BIND_INFO;
  while( true ) {
    if ((int *)0x14001616f < piVar3) {
      return iVar2;
    }
    if (*piVar3 != 0x50) break;
    pPVar1 = *(PBC_DEVICE **)(piVar3 + 0xe);
    PTR___KMDF_CLASS_BIND_START_140016178 = (undefined *)piVar3;
    if (pPVar1 == (PBC_DEVICE *)0x0) {
      in_RDX = WdfDriverGlobals;
      iVar2 = WdfVersionBindClass(param_1,WdfDriverGlobals,piVar3);
    }
    else {
      ChvP1I2c_ControllerIoGenerateStart(pPVar1,(ulong)in_RDX);
      in_RDX = param_1;
      iVar2 = (*(code *)pPVar1)(WdfVersionBindClass,param_1,WdfDriverGlobals,piVar3);
    }
    if (iVar2 < 0) {
      return iVar2;
    }
    piVar3 = piVar3 + 0x14;
  }
  return -0x3ffffffc;
}



===== FxStubUnbindClasses @ 140012f50 =====

/* void __cdecl FxStubUnbindClasses(struct _WDF_BIND_INFO * __ptr64) */

void __cdecl FxStubUnbindClasses(_WDF_BIND_INFO *param_1)

{
  PBC_DEVICE *pPVar1;
  _WDF_BIND_INFO *in_RDX;
  undefined4 *puVar2;
  
  puVar2 = &_SPBCx_BIND_INFO;
  if (((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_140016178 != &__KMDF_CLASS_BIND_START) &&
     ((undefined *)0x14001611f < PTR___KMDF_CLASS_BIND_START_140016178)) {
    do {
      pPVar1 = *(PBC_DEVICE **)(puVar2 + 0x10);
      if (pPVar1 == (PBC_DEVICE *)0x0) {
        in_RDX = WdfDriverGlobals;
        WdfVersionUnbindClass(param_1,WdfDriverGlobals,puVar2);
      }
      else {
        ChvP1I2c_ControllerIoGenerateStart(pPVar1,(ulong)in_RDX);
        in_RDX = param_1;
        (*(code *)pPVar1)(WdfVersionUnbindClass,param_1,WdfDriverGlobals,puVar2);
      }
      puVar2 = puVar2 + 0x14;
    } while (puVar2 <= PTR___KMDF_CLASS_BIND_START_140016178);
  }
  return;
}



===== WdfVersionBind @ 140012fda =====

void WdfVersionBind(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140012fda. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WdfVersionBind();
  return;
}



===== WdfVersionUnbind @ 140012fe0 =====

void WdfVersionUnbind(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140012fe0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WdfVersionUnbind();
  return;
}



===== WdfVersionBindClass @ 140012ff0 =====

void WdfVersionBindClass(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140012ff0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WdfVersionBindClass();
  return;
}



===== WdfVersionUnbindClass @ 140013000 =====

void WdfVersionUnbindClass(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140013000. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WdfVersionUnbindClass();
  return;
}



===== _guard_dispatch_icall @ 140013020 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140013020. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== memset @ 140013040 =====

void * __cdecl memset(void *_Dst,int _Val,size_t _Size)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  
  if (_Size < 8) {
    for (uVar4 = _Size & 7; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(char *)((longlong)_Dst + (uVar4 - 1)) = (char)_Val;
    }
    return _Dst;
  }
  lVar3 = ((ulonglong)(uint)_Val & 0xff) * 0x101010101010101;
  if (_Size < 0x4f) {
    uVar4 = _Size & 0xfffffffffffffff8;
    do {
      *(longlong *)((longlong)_Dst + (uVar4 - 8)) = lVar3;
      uVar4 = uVar4 - 8;
    } while (uVar4 != 0);
    if ((_Size & 7) != 0) {
      *(longlong *)((longlong)_Dst + (_Size & 7) + ((_Size & 0xfffffffffffffff8) - 8)) = lVar3;
    }
    return _Dst;
  }
  *(longlong *)_Dst = lVar3;
  *(longlong *)((longlong)_Dst + 8) = lVar3;
  plVar1 = (longlong *)((longlong)_Dst + 0x10U & 0xfffffffffffffff0);
  uVar4 = (longlong)_Dst + (_Size - (longlong)plVar1);
  uVar5 = uVar4 >> 7;
  plVar2 = plVar1;
  if (uVar5 != 0) {
    do {
      *plVar2 = lVar3;
      plVar2[1] = lVar3;
      plVar2[2] = lVar3;
      plVar2[3] = lVar3;
      plVar1 = plVar2 + 0x10;
      plVar2[4] = lVar3;
      plVar2[5] = lVar3;
      plVar2[6] = lVar3;
      plVar2[7] = lVar3;
      uVar5 = uVar5 - 1;
      plVar2[8] = lVar3;
      plVar2[9] = lVar3;
      plVar2[10] = lVar3;
      plVar2[0xb] = lVar3;
      plVar2[0xc] = lVar3;
      plVar2[0xd] = lVar3;
      plVar2[0xe] = lVar3;
      plVar2[0xf] = lVar3;
      plVar2 = plVar1;
    } while (uVar5 != 0);
    uVar4 = uVar4 & 0x7f;
  }
  for (uVar5 = uVar4 >> 4; uVar5 != 0; uVar5 = uVar5 - 1) {
    *plVar1 = lVar3;
    plVar1[1] = lVar3;
    plVar1 = plVar1 + 2;
  }
  if ((uVar4 & 0xf) != 0) {
    plVar1 = (longlong *)((longlong)plVar1 + ((uVar4 & 0xf) - 0x10));
    *plVar1 = lVar3;
    plVar1[1] = lVar3;
  }
  return _Dst;
}



===== memmove @ 140013140 =====

void * __cdecl memmove(void *_Dst,void *_Src,size_t _Size)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined1 *puVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  int iVar7;
  uint uVar8;
  undefined8 *puVar9;
  undefined8 *puVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  
  uVar11 = (longlong)_Src - (longlong)_Dst;
  if (_Src < _Dst) {
    puVar9 = (undefined8 *)((longlong)_Dst + _Size);
    if (0x4e < _Size) {
      if (uVar11 < 0xfffffffffffffff1) {
        uVar12 = (ulonglong)((uint)puVar9 & 0xf);
        if (((ulonglong)puVar9 & 0xf) != 0) {
          _Size = _Size - uVar12;
          uVar12 = -uVar12;
          puVar10 = (undefined8 *)((longlong)puVar9 + (uVar11 - 0x10));
          uVar4 = puVar10[1];
          puVar9[-2] = *puVar10;
          puVar9[-1] = uVar4;
        }
        puVar9 = (undefined8 *)(uVar12 + (longlong)puVar9);
      }
      else {
        while (((ulonglong)puVar9 & 0xf) != 0) {
          puVar9 = (undefined8 *)((longlong)puVar9 + -1);
          _Size = _Size - 1;
          *(undefined1 *)puVar9 = *(undefined1 *)((longlong)puVar9 + uVar11);
        }
      }
      uVar12 = _Size >> 5;
      if ((0x2000 < uVar12) && (uVar11 < 0xfffffffffffffe01)) {
        do {
          iVar7 = 4;
          do {
            puVar10 = puVar9;
            iVar7 = iVar7 + -1;
            puVar9 = puVar10 + -0x10;
          } while (iVar7 != 0);
          iVar7 = 8;
          puVar10 = puVar10 + 0x30;
          do {
            puVar9 = (undefined8 *)((longlong)puVar10 + (uVar11 - 0x10));
            uVar4 = puVar9[1];
            puVar1 = (undefined8 *)((longlong)puVar10 + (uVar11 - 0x20));
            uVar5 = *puVar1;
            uVar6 = puVar1[1];
            puVar10[-2] = *puVar9;
            puVar10[-1] = uVar4;
            puVar10[-4] = uVar5;
            puVar10[-3] = uVar6;
            puVar9 = puVar10 + -8;
            puVar1 = (undefined8 *)((longlong)puVar10 + (uVar11 - 0x30));
            uVar4 = puVar1[1];
            uVar5 = *(undefined8 *)((longlong)puVar9 + uVar11);
            uVar6 = ((undefined8 *)((longlong)puVar9 + uVar11))[1];
            puVar10[-6] = *puVar1;
            puVar10[-5] = uVar4;
            *puVar9 = uVar5;
            puVar10[-7] = uVar6;
            iVar7 = iVar7 + -1;
            puVar10 = puVar9;
          } while (iVar7 != 0);
          _Size = _Size - 0x200;
        } while (0x1ff < _Size);
        LOCK();
        UNLOCK();
        uVar12 = _Size >> 5;
        if (uVar12 == 0) goto LAB_1400132f7;
      }
      _Size = _Size & 0x1f;
      puVar10 = puVar9;
      do {
        puVar1 = (undefined8 *)((longlong)puVar10 + (uVar11 - 0x10));
        uVar4 = puVar1[1];
        puVar9 = (undefined8 *)((longlong)puVar10 + (uVar11 - 0x20));
        uVar5 = *puVar9;
        uVar6 = puVar9[1];
        puVar9 = puVar10 + -4;
        puVar10[-2] = *puVar1;
        puVar10[-1] = uVar4;
        *puVar9 = uVar5;
        puVar10[-3] = uVar6;
        uVar12 = uVar12 - 1;
        puVar10 = puVar9;
      } while (uVar12 != 0);
    }
LAB_1400132f7:
    for (uVar12 = _Size >> 3; uVar12 != 0; uVar12 = uVar12 - 1) {
      puVar10 = (undefined8 *)((longlong)puVar9 + (uVar11 - 8));
      puVar9 = puVar9 + -1;
      *puVar9 = *puVar10;
    }
    for (uVar12 = _Size & 7; uVar12 != 0; uVar12 = uVar12 - 1) {
      puVar3 = (undefined1 *)((longlong)puVar9 + (uVar11 - 1));
      puVar9 = (undefined8 *)((longlong)puVar9 + -1);
      *(undefined1 *)puVar9 = *puVar3;
    }
    return _Dst;
  }
  puVar9 = _Dst;
  if (0x4e < _Size) {
    if (uVar11 < 0x10) {
      for (; ((ulonglong)puVar9 & 0xf) != 0; puVar9 = (undefined8 *)((longlong)puVar9 + 1)) {
        _Size = _Size - 1;
        *(undefined1 *)puVar9 = *(undefined1 *)((longlong)puVar9 + uVar11);
      }
    }
    else {
      uVar8 = -(int)_Dst & 0xf;
      if (uVar8 != 0) {
        _Size = _Size - uVar8;
        uVar4 = ((undefined8 *)((longlong)_Dst + uVar11))[1];
        *(undefined8 *)_Dst = *(undefined8 *)((longlong)_Dst + uVar11);
        *(undefined8 *)((longlong)_Dst + 8) = uVar4;
      }
      puVar9 = (undefined8 *)((ulonglong)uVar8 + (longlong)_Dst);
    }
    uVar12 = _Size >> 5;
    if ((0x2000 < uVar12) && (0x1ff < uVar11)) {
      do {
        iVar7 = 4;
        do {
          puVar10 = puVar9;
          iVar7 = iVar7 + -1;
          puVar9 = puVar10 + 0x10;
        } while (iVar7 != 0);
        iVar7 = 8;
        puVar10 = puVar10 + -0x30;
        do {
          uVar4 = ((undefined8 *)((longlong)puVar10 + uVar11))[1];
          puVar9 = (undefined8 *)((longlong)puVar10 + uVar11 + 0x10);
          uVar5 = *puVar9;
          uVar6 = puVar9[1];
          *puVar10 = *(undefined8 *)((longlong)puVar10 + uVar11);
          puVar10[1] = uVar4;
          puVar10[2] = uVar5;
          puVar10[3] = uVar6;
          puVar9 = puVar10 + 8;
          puVar1 = (undefined8 *)((longlong)puVar10 + uVar11 + 0x20);
          uVar4 = puVar1[1];
          puVar2 = (undefined8 *)((longlong)puVar10 + uVar11 + 0x30);
          uVar5 = *puVar2;
          uVar6 = puVar2[1];
          puVar10[4] = *puVar1;
          puVar10[5] = uVar4;
          puVar10[6] = uVar5;
          puVar10[7] = uVar6;
          iVar7 = iVar7 + -1;
          puVar10 = puVar9;
        } while (iVar7 != 0);
        _Size = _Size - 0x200;
      } while (0x1ff < _Size);
      LOCK();
      UNLOCK();
      uVar12 = _Size >> 5;
      if (uVar12 == 0) goto LAB_140013152;
    }
    _Size = _Size & 0x1f;
    puVar10 = puVar9;
    do {
      uVar4 = ((undefined8 *)((longlong)puVar10 + uVar11))[1];
      puVar9 = (undefined8 *)((longlong)puVar10 + uVar11 + 0x10);
      uVar5 = *puVar9;
      uVar6 = puVar9[1];
      puVar9 = puVar10 + 4;
      *puVar10 = *(undefined8 *)((longlong)puVar10 + uVar11);
      puVar10[1] = uVar4;
      puVar10[2] = uVar5;
      puVar10[3] = uVar6;
      uVar12 = uVar12 - 1;
      puVar10 = puVar9;
    } while (uVar12 != 0);
  }
LAB_140013152:
  for (uVar12 = _Size >> 3; uVar12 != 0; uVar12 = uVar12 - 1) {
    *puVar9 = *(undefined8 *)((longlong)puVar9 + uVar11);
    puVar9 = puVar9 + 1;
  }
  for (uVar12 = _Size & 7; uVar12 != 0; uVar12 = uVar12 - 1) {
    *(undefined1 *)puVar9 = *(undefined1 *)((longlong)puVar9 + uVar11);
    puVar9 = (undefined8 *)((longlong)puVar9 + 1);
  }
  return _Dst;
}



===== WppCleanupKm @ 140018000 =====

void WppCleanupKm(undefined8 param_1,undefined8 param_2)

{
  longlong lVar1;
  code *pcVar2;
  undefined *puVar3;
  
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    puVar3 = WPP_GLOBAL_Control;
    if (WPPTraceSuite == 4) {
      for (; pcVar2 = pfnEtwUnregister, puVar3 != (undefined *)0x0;
          puVar3 = *(undefined **)(puVar3 + 0x10)) {
        lVar1 = *(longlong *)(puVar3 + 0x38);
        if (lVar1 != 0) {
          ChvP1I2c_ControllerIoGenerateStart((PBC_DEVICE *)pfnEtwUnregister,(ulong)param_2);
          (*pcVar2)(lVar1);
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



===== WppInitKm @ 14001808c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void WppInitKm(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  undefined *puVar2;
  
  puVar2 = &WPP_MAIN_CB;
  if (WPP_GLOBAL_Control != &WPP_MAIN_CB) {
    WPP_GLOBAL_Control = &WPP_MAIN_CB;
    if (WPPTraceSuite == 4) {
      do {
        *(undefined8 *)(puVar2 + 0x38) = 0;
        pcVar1 = pfnEtwRegisterClassicProvider;
        ChvP1I2c_ControllerIoGenerateStart
                  ((PBC_DEVICE *)pfnEtwRegisterClassicProvider,(ulong)param_2);
        param_2 = 0;
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



===== WppLoadTracingSupport @ 140018128 =====

void WppLoadTracingSupport(void)

{
  code *pcVar1;
  ulong uVar2;
  uint local_res8 [2];
  undefined1 local_18 [16];
  
  local_res8[0] = 0;
  RtlInitUnicodeString(local_18,L"PsGetVersion");
  pfnWppGetVersion = (code *)MmGetSystemRoutineAddress(local_18);
  RtlInitUnicodeString(local_18,L"WmiTraceMessage");
  pfnWppTraceMessage = MmGetSystemRoutineAddress(local_18);
  uVar2 = 0x400184c0;
  RtlInitUnicodeString(local_18);
  pfnWppQueryTraceInformation = MmGetSystemRoutineAddress(local_18);
  pcVar1 = pfnWppGetVersion;
  WPPTraceSuite = 2;
  if (pfnWppGetVersion != (code *)0x0) {
    ChvP1I2c_ControllerIoGenerateStart((PBC_DEVICE *)pfnWppGetVersion,uVar2);
    (*pcVar1)(local_res8,0,0,0);
  }
  if (5 < local_res8[0]) {
    RtlInitUnicodeString(local_18,L"EtwRegisterClassicProvider");
    pfnEtwRegisterClassicProvider = MmGetSystemRoutineAddress(local_18);
    if (pfnEtwRegisterClassicProvider != 0) {
      RtlInitUnicodeString(local_18,L"EtwUnregister");
      pfnEtwUnregister = MmGetSystemRoutineAddress(local_18);
      WPPTraceSuite = 4;
    }
  }
  return;
}



===== WppTraceCallback @ 140018230 =====

undefined4
WppTraceCallback(byte param_1,undefined8 param_2,uint param_3,uint *param_4,longlong param_5,
                uint *param_6)

{
  ushort *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  code *pcVar4;
  int iVar5;
  undefined4 uVar6;
  longlong lVar7;
  ulonglong uVar8;
  uint *puVar9;
  undefined1 *puVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint *puVar14;
  undefined1 local_res8 [8];
  undefined1 uStack_36;
  undefined4 uStack_34;
  
  puVar9 = param_6;
  *param_6 = 0;
  if (3 < param_1) {
    if (param_1 < 6) {
      if (param_5 != 0) {
        if (param_3 < 0x30) {
          return 0xc000000d;
        }
        do {
          puVar9 = param_4 + 6;
          lVar7 = RtlCompareMemory(*(undefined8 *)(param_5 + 8),puVar9,0x10);
          if (lVar7 == 0x10) break;
          param_5 = *(longlong *)(param_5 + 0x10);
        } while (param_5 != 0);
        if (param_5 != 0) {
          if (param_1 == 5) {
            *(undefined1 *)(param_5 + 0x29) = 0;
            *(undefined4 *)(param_5 + 0x2c) = 0;
            *(undefined8 *)(param_5 + 0x18) = 0;
            return 0;
          }
          uVar2 = *(undefined8 *)(param_4 + 2);
          *(undefined8 *)(param_5 + 0x18) = uVar2;
          pcVar4 = pfnWppQueryTraceInformation;
          if (WPPTraceSuite != 2) {
            uStack_34 = (undefined4)((ulonglong)uVar2 >> 0x20);
            *(undefined4 *)(param_5 + 0x2c) = uStack_34;
            uStack_36 = (undefined1)((ulonglong)uVar2 >> 0x10);
            *(undefined1 *)(param_5 + 0x29) = uStack_36;
            return 0;
          }
          ChvP1I2c_ControllerIoGenerateStart
                    ((PBC_DEVICE *)pfnWppQueryTraceInformation,(ulong)puVar9);
          puVar10 = local_res8;
          iVar5 = (*pcVar4)(3,puVar10,4,&param_6,param_4);
          if (iVar5 == 0) {
            *(undefined1 *)(param_5 + 0x29) = local_res8[0];
          }
          pcVar4 = pfnWppQueryTraceInformation;
          ChvP1I2c_ControllerIoGenerateStart
                    ((PBC_DEVICE *)pfnWppQueryTraceInformation,(ulong)puVar10);
          uVar6 = (*pcVar4)(2,param_5 + 0x2c,4,&param_6,param_4);
          return uVar6;
        }
      }
      return 0xc0000295;
    }
    if (param_1 < 8) {
      return 0;
    }
    if (param_1 == 8) {
      uVar11 = 0;
      puVar1 = *(ushort **)(param_5 + 0x20);
      lVar7 = param_5;
      do {
        lVar7 = *(longlong *)(lVar7 + 0x10);
        uVar11 = uVar11 + 1;
      } while (lVar7 != 0);
      if (0x3f < uVar11) {
        return 0xc000000d;
      }
      uVar12 = uVar11 * 0x20 + 0x18;
      if (puVar1 == (ushort *)0x0) {
        uVar13 = uVar12;
        uVar12 = 0;
      }
      else {
        uVar13 = *puVar1 + 2 + uVar12;
      }
      if (param_3 < uVar13) {
        if (param_3 < 4) {
          return 0xc0000023;
        }
        *param_4 = uVar13;
        *param_6 = 4;
        return 0xc0000023;
      }
      memset(param_4,0,(ulonglong)param_3);
      *param_4 = uVar13;
      param_4[2] = uVar12;
      param_4[4] = uVar11;
      if (puVar1 != (ushort *)0x0) {
        *(ushort *)((ulonglong)uVar12 + (longlong)param_4) = *puVar1;
        memmove((ushort *)((ulonglong)uVar12 + (longlong)param_4) + 1,*(void **)(puVar1 + 4),
                (ulonglong)*puVar1);
      }
      if (uVar11 != 0) {
        uVar8 = (ulonglong)uVar11;
        puVar14 = param_4 + 10;
        do {
          uVar2 = **(undefined8 **)(param_5 + 8);
          uVar3 = (*(undefined8 **)(param_5 + 8))[1];
          *puVar14 = 0x81000;
          *(undefined8 *)(puVar14 + -4) = uVar2;
          *(undefined8 *)(puVar14 + -2) = uVar3;
          *(undefined1 *)(param_5 + 0x29) = 0;
          *(undefined4 *)(param_5 + 0x2c) = 0;
          param_5 = *(longlong *)(param_5 + 0x10);
          uVar8 = uVar8 - 1;
          puVar14 = puVar14 + 8;
        } while (uVar8 != 0);
      }
      *puVar9 = uVar13;
      return 0;
    }
  }
  return 0xc0000010;
}



===== __security_init_cookie @ 140019000 =====

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


