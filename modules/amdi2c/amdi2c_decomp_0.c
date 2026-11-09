
===== ControllerCompleteTransfer @ 140001000 =====

/* void __cdecl ControllerCompleteTransfer(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST * __ptr64)
    */

void __cdecl ControllerCompleteTransfer(PBC_DEVICE *param_1,PBC_REQUEST *param_2)

{
  int iVar1;
  
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0x28,
                     &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids);
  }
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x29,
                    &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids,"ControllerCompleteTransfer");
  if (*(int *)(param_2 + 0x18) != -0x3ffffee0) {
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x800))(WdfDriverGlobals,*(undefined8 *)param_2);
    if (iVar1 < 0) {
      *(undefined4 *)(param_1 + 0xa0) = 0;
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x2a,
                         &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids,
                         (char)*(undefined8 *)param_2,(char)iVar1);
      WPP_RECORDER_SF_sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x2b,
                         &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids,
                         "ControllerCompleteTransfer",0x6d);
      goto LAB_1400011f4;
    }
  }
  if (*(int *)(param_2 + 0x18) == 0) {
    if (*(int *)(param_1 + 0xa0) != 0) {
      param_1[0xed] = (PBC_DEVICE)0x0;
    }
    if (*(int *)(param_2 + 0x18) == 0) {
      ControllerDisableController(param_1);
      *(undefined4 *)(*(longlong *)(param_1 + 0x20) + 8) = 0;
      LOCK();
      UNLOCK();
      ControllerEnableController(param_1,1);
    }
  }
  if ((param_2[0x3b] != (PBC_REQUEST)0x0) && (*(int *)(param_2 + 0x18) == -0x3ffffee0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,4,0x2c,
                     &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids);
  }
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0xa0) = 0;
  param_2[0x3b] = (PBC_REQUEST)0x0;
  if (*(longlong *)(param_1 + 0x28) == 0) {
    param_2[0x1c] = (PBC_REQUEST)0x0;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,4,0x2d,
                     &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids);
  }
  else {
    WPP_RECORDER_SF_sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x2e,
                       &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids,"ControllerCompleteTransfer"
                       ,0xa8);
    *(undefined8 *)(*(longlong *)(param_1 + 0x28) + 0xf) = 0;
    if ((*(int *)(param_2 + 8) == 3) || (*(int *)(param_2 + 0x29) == 1)) {
      *(undefined8 *)(param_1 + 0x28) = 0;
    }
    param_2[0x1c] = (PBC_REQUEST)0x1;
  }
LAB_1400011f4:
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x2f,
                    &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids,"ControllerCompleteTransfer");
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0x30,
                     &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids);
  }
  return;
}



===== ControllerConfigureForTransfer @ 140001260 =====

/* void __cdecl ControllerConfigureForTransfer(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST *
   __ptr64) */

void __cdecl ControllerConfigureForTransfer(PBC_DEVICE *param_1,PBC_REQUEST *param_2)

{
  PBC_TARGET *pPVar1;
  
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0x13,
                     &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids);
  }
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x14,
                    &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids,
                    "ControllerConfigureForTransfer");
  pPVar1 = *(PBC_TARGET **)(param_1 + 0x28);
  *(undefined4 *)(param_2 + 0x18) = 0;
  if (*(int *)(param_2 + 8) - 1U < 3) {
    I2CXfer(param_2,param_1,pPVar1);
  }
  else {
    *(undefined4 *)(param_2 + 0x18) = 0xc000000d;
  }
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x15,
                    &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids,
                    "ControllerConfigureForTransfer");
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0x16,
                     &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids);
  }
  return;
}



===== ControllerDisableController @ 14000136c =====

/* void __cdecl ControllerDisableController(struct PBC_DEVICE * __ptr64) */

void __cdecl ControllerDisableController(PBC_DEVICE *param_1)

{
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0x3b,
                     &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids);
  }
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x3c,
                    &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids,"ControllerDisableController");
  (**(code **)(WdfFunctions_01015 + 0x480))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x30));
  *(undefined4 *)(*(longlong *)(param_1 + 0x20) + 0x6c) = 0;
  LOCK();
  UNLOCK();
  (**(code **)(WdfFunctions_01015 + 0x488))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x30));
  WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x3d,
                   &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids);
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x3e,
                    &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids,"ControllerDisableController");
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0x3f,
                     &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids);
  }
  return;
}



===== ControllerDisableInterrupts @ 1400014a4 =====

/* void __cdecl ControllerDisableInterrupts(struct PBC_DEVICE * __ptr64) */

void __cdecl ControllerDisableInterrupts(PBC_DEVICE *param_1)

{
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0x40,
                     &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids);
  }
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x41,
                    &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids,"ControllerDisableInterrupts");
  (**(code **)(WdfFunctions_01015 + 0x480))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x30));
  *(undefined4 *)(*(longlong *)(param_1 + 0x20) + 0x30) = 0;
  LOCK();
  UNLOCK();
  (**(code **)(WdfFunctions_01015 + 0x488))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x30));
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x42,
                    &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids,"ControllerDisableInterrupts");
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0x43,
                     &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids);
  }
  return;
}



===== ControllerEnableController @ 1400015bc =====

/* void __cdecl ControllerEnableController(struct PBC_DEVICE * __ptr64,unsigned long) */

void __cdecl ControllerEnableController(PBC_DEVICE *param_1,ulong param_2)

{
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0x36,
                     &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids);
  }
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x37,
                    &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids,"ControllerEnableController");
  (**(code **)(WdfFunctions_01015 + 0x480))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x30));
  *(ulong *)(*(longlong *)(param_1 + 0x20) + 0x6c) = param_2;
  LOCK();
  UNLOCK();
  (**(code **)(WdfFunctions_01015 + 0x488))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x30));
  WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x38,
                    &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids,(char)param_2);
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x39,
                    &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids,"ControllerEnableController");
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0x3a,
                     &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids);
  }
  return;
}



===== ControllerEnableInterrupts @ 140001704 =====

/* void __cdecl ControllerEnableInterrupts(struct PBC_DEVICE * __ptr64,unsigned long) */

void __cdecl ControllerEnableInterrupts(PBC_DEVICE *param_1,ulong param_2)

{
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0x31,
                     &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids);
  }
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x32,
                    &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids,"ControllerEnableInterrupts");
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0x33,
                      &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids,(char)param_2);
  }
  (**(code **)(WdfFunctions_01015 + 0x480))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x30));
  *(ulong *)(param_1 + 0x38) = param_2;
  *(ulong *)(*(longlong *)(param_1 + 0x20) + 0x30) = param_2;
  LOCK();
  UNLOCK();
  (**(code **)(WdfFunctions_01015 + 0x488))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x30));
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x34,
                    &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids,"ControllerEnableInterrupts");
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0x35,
                     &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids);
  }
  return;
}



===== ControllerInitialize @ 140001854 =====

/* void __cdecl ControllerInitialize(struct PBC_DEVICE * __ptr64) */

void __cdecl ControllerInitialize(PBC_DEVICE *param_1)

{
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,10,
                     &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids);
  }
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0xb,
                    &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids,"ControllerInitialize");
  *(undefined4 *)(param_1 + 0x58) = 99;
  ControllerDisableController(param_1);
  *(undefined4 *)(*(longlong *)(param_1 + 0x20) + 0x94) = 0x20;
  LOCK();
  UNLOCK();
  *(undefined4 *)(*(longlong *)(param_1 + 0x20) + 0xa0) = 6;
  LOCK();
  UNLOCK();
  *(undefined4 *)(*(longlong *)(param_1 + 0x20) + 0xa4) = 2;
  LOCK();
  UNLOCK();
  *(undefined4 *)(*(longlong *)(param_1 + 0x20) + 0x30) = 0;
  LOCK();
  UNLOCK();
  *(undefined4 *)(param_1 + 0xb0) = 0x48;
  *(undefined4 *)(param_1 + 0xbc) = 0x48;
  *(undefined4 *)(param_1 + 0x5c) = 0x100;
  *(undefined4 *)(param_1 + 0x60) = 0x100;
  *(undefined4 *)(param_1 + 0xd0) = 0x1b;
  *(undefined4 *)(param_1 + 0xdc) = 0x1b;
  *(undefined4 *)(param_1 + 200) = 0x30;
  *(undefined4 *)(param_1 + 0xd4) = 0x2a;
  *(undefined4 *)(param_1 + 0xe0) = 7;
  *(undefined4 *)(param_1 + 0xa8) = 0x23c;
  *(undefined4 *)(param_1 + 0xac) = 0x2f7;
  *(undefined4 *)(param_1 + 0xb4) = 0x78;
  *(undefined4 *)(param_1 + 0xb8) = 0xd5;
  *(undefined4 *)(param_1 + 0xc0) = 0x33;
  *(undefined4 *)(param_1 + 0xc4) = 0x53;
  *(undefined4 *)(param_1 + 0xcc) = 0xe;
  *(undefined4 *)(param_1 + 0xd8) = 0xe;
  if (*(int *)(param_1 + 0xe4) == 3) {
    *(undefined4 *)(param_1 + 0xa8) = 0x285;
    *(undefined4 *)(param_1 + 0xac) = 0x357;
    *(undefined4 *)(param_1 + 0xb4) = 0x87;
    *(undefined4 *)(param_1 + 0xb8) = 0xf0;
    *(undefined4 *)(param_1 + 0xc0) = 0x39;
    *(undefined4 *)(param_1 + 0xc4) = 0x5d;
  }
  *(undefined4 *)(*(longlong *)(param_1 + 0x20) + 0x14) = *(undefined4 *)(param_1 + 0xa8);
  LOCK();
  UNLOCK();
  *(undefined4 *)(*(longlong *)(param_1 + 0x20) + 0x18) = *(undefined4 *)(param_1 + 0xac);
  LOCK();
  UNLOCK();
  *(undefined4 *)(*(longlong *)(param_1 + 0x20) + 0x3c) = 0x7f;
  LOCK();
  UNLOCK();
  *(undefined4 *)(*(longlong *)(param_1 + 0x20) + 0x38) = 0x1f;
  LOCK();
  UNLOCK();
  **(undefined4 **)(param_1 + 0x20) = *(undefined4 *)(param_1 + 0x58);
  LOCK();
  UNLOCK();
  ControllerEnableController(param_1,1);
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0xc,
                    &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids,"ControllerInitialize");
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0xd,
                     &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids);
  }
  return;
}



===== ControllerProcessInterrupts @ 140001ab8 =====

/* unsigned char __cdecl ControllerProcessInterrupts(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST
   * __ptr64,unsigned long) */

uchar __cdecl ControllerProcessInterrupts(PBC_DEVICE *param_1,PBC_REQUEST *param_2,ulong param_3)

{
  uchar uVar1;
  
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0x17,
                     &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids);
  }
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x18,
                    &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids,"ControllerProcessInterrupts");
  uVar1 = '\x01';
  WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,6,0x19,
                    &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids,(char)param_3);
  if ((param_3 & 0x40) == 0) {
    if ((param_3 & 4) != 0) {
      if (*(int *)(param_2 + 0x2d) != 1) {
        WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,4,0x1b,
                          &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids,(char)param_3);
      }
      WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x1c,
                        &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids,
                        "ControllerProcessInterrupts");
      I2CReadData(param_2,param_1);
      if (*(int *)(param_2 + 0x18) < 0) {
        WPP_RECORDER_SF_sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x1d,
                           &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids,
                           "ControllerProcessInterrupts",0xaf);
        uVar1 = '\0';
      }
    }
    if ((param_3 & 0x10) != 0) {
      WPP_RECORDER_SF_sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x1e,
                         &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids,
                         "ControllerProcessInterrupts",0xbc);
      I2CXferData(param_2,param_1);
      if (*(int *)(param_2 + 0x18) < 0) {
        WPP_RECORDER_SF_sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x1f,
                           &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids,
                           "ControllerProcessInterrupts",199);
        uVar1 = '\0';
      }
    }
  }
  else {
    WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x1a,
                      &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids,"ControllerProcessInterrupts"
                     );
  }
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0x20,
                     &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids);
  }
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x21,
                    &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids,"ControllerProcessInterrupts");
  return uVar1;
}



===== ControllerUninitialize @ 140001d34 =====

/* void __cdecl ControllerUninitialize(struct PBC_DEVICE * __ptr64) */

void __cdecl ControllerUninitialize(PBC_DEVICE *param_1)

{
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0xe,
                     &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids);
  }
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0xf,
                    &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids,"ControllerUninitialize");
  *(undefined4 *)(*(longlong *)(param_1 + 0x20) + 0x30) = 0;
  LOCK();
  UNLOCK();
  if (param_1[0xeb] != (PBC_DEVICE)0x0) {
    ControllerEnableController(param_1,3);
    I2CWaitForNoActivity(param_1,100);
  }
  if (*(int *)(*(longlong *)(param_1 + 0x20) + 0x9c) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,1,0x10,
                     &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids);
  }
  ControllerDisableController(param_1);
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x11,
                    &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids,"ControllerUninitialize");
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x12,
                     &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids);
  }
  return;
}



===== I2CHandleTxAbort @ 140001e78 =====

/* long __cdecl I2CHandleTxAbort(struct PBC_REQUEST * __ptr64,struct PBC_DEVICE * __ptr64,unsigned
   long) */

long __cdecl I2CHandleTxAbort(PBC_REQUEST *param_1,PBC_DEVICE *param_2,ulong param_3)

{
  uint uVar1;
  
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x57,
                    &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids,"I2CHandleTxAbort");
  WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,4,0x58,
                    &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids,
                    (char)*(undefined4 *)(param_2 + 0x9c));
  uVar1 = *(uint *)(param_2 + 0x9c);
  if ((uVar1 & 7) == 0) {
    if ((uVar1 & 8) == 0) {
      if ((uVar1 >> 0xc & 1) == 0) {
        WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,4,0x5b,
                          &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids,(char)uVar1);
      }
      else {
        WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,4,0x5a,
                          &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids,(char)uVar1);
        param_2[0xec] = (PBC_DEVICE)0x1;
      }
      *(undefined4 *)(param_1 + 0x18) = 0xc0000001;
    }
    else {
      *(undefined4 *)(param_1 + 0x35) = 0;
      *(undefined4 *)(param_1 + 0x18) = 0;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x35) = 0;
    *(undefined4 *)(param_1 + 0x18) = 0xc000000e;
    WPP_RECORDER_SF_sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x59,
                       &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids,"I2CHandleTxAbort",0xf4);
  }
  if (*(int *)(param_2 + 0xa0) != 0) {
    *(undefined4 *)(param_2 + 0x9c) = 0;
    *(undefined4 *)(param_2 + 0x7c) = 0;
  }
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x5c,
                    &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids,"I2CHandleTxAbort");
  return 0;
}



===== I2CPostXfer @ 140001ff8 =====

/* unsigned char __cdecl I2CPostXfer(struct PBC_REQUEST * __ptr64,struct PBC_DEVICE * __ptr64) */

uchar __cdecl I2CPostXfer(PBC_REQUEST *param_1,PBC_DEVICE *param_2)

{
  char *pcVar1;
  uchar uVar2;
  
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x65,
                    &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids,"I2CPostXfer");
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0x66,
                     &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids);
  }
  if (*(int *)(param_2 + 0xa0) == 0) {
    *(undefined4 *)(param_1 + 0x35) = *(undefined4 *)(param_1 + 0x1d);
  }
  if (*(int *)(param_1 + 0x18) < 0) {
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + *(int *)(param_1 + 0x35);
  pcVar1 = "error";
  if (-1 < *(int *)(param_1 + 0x18)) {
    pcVar1 = "complete";
  }
  WPP_RECORDER_SF_LsLd
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x67,
             &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids,(char)*(undefined4 *)(param_1 + 0x10),
             pcVar1,(char)*(int *)(param_1 + 0x35),(char)*(int *)(param_1 + 0x18));
  uVar2 = '\0';
  if ((-1 < *(int *)(param_1 + 0x18)) && (*(int *)(param_2 + 0xa0) == 0)) {
    *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
    uVar2 = '\0';
    if (*(uint *)(param_1 + 0x10) < *(uint *)(param_1 + 0xc)) {
      uVar2 = '\x01';
    }
  }
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0x68,
                     &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids);
  }
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x69,
                    &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids,"I2CPostXfer");
  return uVar2;
}



===== I2CReadData @ 140002170 =====

/* long __cdecl I2CReadData(struct PBC_REQUEST * __ptr64,struct PBC_DEVICE * __ptr64) */

long __cdecl I2CReadData(PBC_REQUEST *param_1,PBC_DEVICE *param_2)

{
  uint *puVar1;
  undefined4 uVar2;
  longlong lVar3;
  undefined8 *puVar4;
  long lVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  undefined *puVar10;
  
  uVar9 = 0;
  lVar5 = 0;
  puVar10 = &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids;
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x5d,
                    &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids,"I2CReadData");
  iVar8 = *(int *)(*(longlong *)(param_2 + 0x20) + 0x78);
  uVar6 = *(uint *)(param_2 + 0x7c);
  if ((uVar6 & 8) == 0) {
    if ((uVar6 & 2) == 0) {
      uVar7 = 0;
    }
    else {
      uVar7 = *(uint *)(param_2 + 0x8c);
      uVar9 = *(uint *)(param_2 + 0x84);
    }
  }
  else {
    uVar7 = *(uint *)(param_1 + 0x1d);
    *(uint *)(param_2 + 0x7c) = uVar6 & 0xfffffff7;
    *(uint *)(param_2 + 0x8c) = uVar7;
  }
  if (uVar7 == 0) {
    lVar5 = -0x3ffffff3;
  }
  else {
    do {
      if (iVar8 == 0) break;
      uVar2 = *(undefined4 *)(*(longlong *)(param_2 + 0x20) + 0x10);
      lVar5 = -0x3ffffffc;
      puVar4 = *(undefined8 **)(param_1 + 0x21);
      uVar6 = uVar9;
      if (uVar9 < *(uint *)(param_1 + 0x1d)) {
        for (; puVar4 != (undefined8 *)0x0; puVar4 = (undefined8 *)*puVar4) {
          puVar1 = (uint *)(puVar4 + 5);
          if (uVar6 < *puVar1) {
            if ((*(byte *)((longlong)puVar4 + 10) & 5) == 0) {
              puVar10 = (undefined *)((ulonglong)puVar10 & 0xffffffff00000000);
              lVar3 = MmMapLockedPagesSpecifyCache(puVar4,0,1,0,puVar10,0x40000020);
            }
            else {
              lVar3 = puVar4[3];
            }
            if (lVar3 != 0) {
              lVar5 = 0;
              *(char *)((ulonglong)uVar6 + lVar3) = (char)uVar2;
            }
            break;
          }
          uVar6 = uVar6 - *puVar1;
        }
      }
      if (lVar5 < 0) {
        *(long *)(param_1 + 0x18) = lVar5;
        WPP_RECORDER_SF_sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x5e,
                           &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids,"I2CReadData",0x8c);
        break;
      }
      *(int *)(param_2 + 0x94) = *(int *)(param_2 + 0x94) + -1;
      uVar9 = uVar9 + 1;
      iVar8 = iVar8 + -1;
      uVar7 = uVar7 - 1;
    } while (uVar7 != 0);
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      WPP_RECORDER_SF_DDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0x5f,
                          &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids,
                          (char)*(undefined4 *)(param_2 + 0x8c) - (char)uVar7,(char)uVar7,
                          (char)*(undefined4 *)(param_2 + 0x94));
    }
    *(uint *)(param_2 + 0x8c) = uVar7;
    if (uVar7 == 0) {
      *(uint *)(param_2 + 0x7c) = *(uint *)(param_2 + 0x7c) & 0xfffffffd;
    }
    else {
      *(uint *)(param_2 + 0x7c) = *(uint *)(param_2 + 0x7c) | 2;
      *(uint *)(param_2 + 0x84) = uVar9;
      if (uVar7 < 0x21) {
        *(uint *)(*(longlong *)(param_2 + 0x20) + 0x38) = uVar7 - 1;
      }
      else {
        *(undefined4 *)(*(longlong *)(param_2 + 0x20) + 0x38) = 0x1f;
      }
      LOCK();
      UNLOCK();
    }
    *(int *)(param_1 + 0x35) = *(int *)(param_1 + 0x1d) - *(int *)(param_2 + 0x8c);
  }
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x60,
                    &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids,"I2CReadData");
  return lVar5;
}



===== I2CWaitForNoActivity @ 1400023d0 =====

/* void __cdecl I2CWaitForNoActivity(struct PBC_DEVICE * __ptr64,unsigned long) */

void __cdecl I2CWaitForNoActivity(PBC_DEVICE *param_1,ulong param_2)

{
  longlong lVar1;
  
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x61,
                    &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids,"I2CWaitForNoActivity");
  lVar1 = *(longlong *)(param_1 + 0x20);
  for (; ((*(uint *)(lVar1 + 0x70) & 0x20) != 0 && (param_2 != 0)); param_2 = param_2 - 1) {
    KeStallExecutionProcessor(100);
    lVar1 = *(longlong *)(param_1 + 0x20);
  }
  if ((*(uint *)(lVar1 + 0x70) & 0x20) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,1,0x62,
                     &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids);
  }
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,100,
                    &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids,"I2CWaitForNoActivity");
  return;
}



===== I2CXfer @ 1400024a4 =====

/* void __cdecl I2CXfer(struct PBC_REQUEST * __ptr64,struct PBC_DEVICE * __ptr64,struct PBC_TARGET *
   __ptr64) */

void __cdecl I2CXfer(PBC_REQUEST *param_1,PBC_DEVICE *param_2,PBC_TARGET *param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  ushort uVar4;
  
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0x48,
                     &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids);
  }
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x49,
                    &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids,"I2CXfer");
  *(undefined4 *)(param_2 + 0x7c) = 0xc;
  if (1 < *(int *)(param_1 + 0x29) - 1U) goto LAB_1400026e6;
  ControllerDisableController(param_2);
  *(undefined4 *)(param_2 + 0x3c) = 0;
  *(undefined4 *)(param_2 + 0x9c) = 0;
  *(uint *)(*(longlong *)(param_2 + 0x20) + 4) = (uint)*(ushort *)(param_3 + 9);
  LOCK();
  UNLOCK();
  if (param_3[8] == (PBC_TARGET)0x0) {
    uVar4 = (ushort)**(undefined4 **)(param_2 + 0x20) & 0xffe9;
  }
  else {
    uVar4 = (ushort)**(undefined4 **)(param_2 + 0x20) & 0xfff9 | 0x10;
  }
  iVar1 = *(int *)(param_3 + 0xb);
  if (iVar1 == 100000) {
    *(undefined4 *)(*(longlong *)(param_2 + 0x20) + 0x7c) = *(undefined4 *)(param_2 + 0xb0);
    LOCK();
    UNLOCK();
    uVar4 = uVar4 | 2;
  }
  else {
    if (iVar1 == 400000) {
      *(undefined4 *)(*(longlong *)(param_2 + 0x20) + 0x7c) = *(undefined4 *)(param_2 + 0xbc);
      LOCK();
      UNLOCK();
      *(undefined4 *)(*(longlong *)(param_2 + 0x20) + 0x1c) = *(undefined4 *)(param_2 + 0xb4);
      LOCK();
      UNLOCK();
      uVar3 = *(undefined4 *)(param_2 + 0xb8);
    }
    else {
      if (iVar1 != 1000000) {
        if (iVar1 == 1400000) {
          *(undefined4 *)(*(longlong *)(param_2 + 0x20) + 0x7c) = *(undefined4 *)(param_2 + 0xd4);
          LOCK();
          UNLOCK();
          *(undefined4 *)(*(longlong *)(param_2 + 0x20) + 0x24) = *(undefined4 *)(param_2 + 0xcc);
          LOCK();
          UNLOCK();
          uVar3 = *(undefined4 *)(param_2 + 0xd0);
        }
        else {
          if (iVar1 != 3400000) goto LAB_14000269c;
          *(undefined4 *)(*(longlong *)(param_2 + 0x20) + 0x7c) = *(undefined4 *)(param_2 + 0xe0);
          LOCK();
          UNLOCK();
          *(undefined4 *)(*(longlong *)(param_2 + 0x20) + 0x24) = *(undefined4 *)(param_2 + 0xd8);
          LOCK();
          UNLOCK();
          uVar3 = *(undefined4 *)(param_2 + 0xdc);
        }
        *(undefined4 *)(*(longlong *)(param_2 + 0x20) + 0x28) = uVar3;
        LOCK();
        UNLOCK();
        uVar4 = uVar4 | 6;
        goto LAB_14000269c;
      }
      *(undefined4 *)(*(longlong *)(param_2 + 0x20) + 0x7c) = *(undefined4 *)(param_2 + 200);
      LOCK();
      UNLOCK();
      *(undefined4 *)(*(longlong *)(param_2 + 0x20) + 0x1c) = *(undefined4 *)(param_2 + 0xc0);
      LOCK();
      UNLOCK();
      uVar3 = *(undefined4 *)(param_2 + 0xc4);
    }
    *(undefined4 *)(*(longlong *)(param_2 + 0x20) + 0x20) = uVar3;
    LOCK();
    UNLOCK();
    uVar4 = uVar4 | 4;
  }
LAB_14000269c:
  WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x4a,
                    &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids,
                    (char)*(undefined4 *)(param_3 + 0xb));
  **(uint **)(param_2 + 0x20) = (uint)uVar4;
  LOCK();
  UNLOCK();
  ControllerEnableController(param_2,1);
LAB_1400026e6:
  if (*(int *)(param_1 + 0x2d) == 1) {
    uVar2 = *(uint *)(param_1 + 0x1d);
    *(uint *)(param_2 + 0x8c) = uVar2;
    if (uVar2 < 0x21) {
      *(uint *)(*(longlong *)(param_2 + 0x20) + 0x38) = uVar2 - 1;
    }
    else {
      *(undefined4 *)(*(longlong *)(param_2 + 0x20) + 0x38) = 0x1f;
    }
    LOCK();
    UNLOCK();
  }
  *(undefined4 *)(param_2 + 0x94) = 0;
  ControllerEnableInterrupts(param_2,0x254);
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x4b,
                    &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids,"I2CXfer");
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0x4c,
                     &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids);
  }
  return;
}



===== I2CXferData @ 140002794 =====

/* long __cdecl I2CXferData(struct PBC_REQUEST * __ptr64,struct PBC_DEVICE * __ptr64) */

long __cdecl I2CXferData(PBC_REQUEST *param_1,PBC_DEVICE *param_2)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  ushort uVar5;
  longlong lVar6;
  ushort uVar7;
  undefined8 *puVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  byte bVar14;
  int local_res10;
  undefined *puVar15;
  
  iVar12 = 0;
  puVar15 = &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids;
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x4d,
                    &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids,"I2CXferData");
  iVar2 = *(int *)(*(longlong *)(param_2 + 0x20) + 0x74);
  local_res10 = *(int *)(param_2 + 0x5c) - iVar2;
  uVar9 = *(uint *)(*(longlong *)(param_2 + 0x20) + 0x78);
  uVar11 = *(uint *)(param_2 + 0x94);
  if (uVar11 < uVar9) {
    puVar15 = &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids;
    WPP_RECORDER_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0x4e,
                       &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids,(char)uVar9,(char)uVar11);
    uVar11 = uVar9;
  }
  uVar11 = *(int *)(param_2 + 0x60) - uVar11;
  uVar13 = 0;
  uVar3 = *(uint *)(param_2 + 0x7c);
  if ((uVar3 & 4) == 0) {
    if ((uVar3 & 1) == 0) {
      iVar10 = 0;
    }
    else {
      iVar10 = *(int *)(param_2 + 0x88);
      uVar13 = *(uint *)(param_2 + 0x80);
    }
  }
  else {
    iVar10 = *(int *)(param_1 + 0x1d);
    *(int *)(param_2 + 0x88) = iVar10;
    *(uint *)(param_2 + 0x7c) = uVar3 & 0xfffffffb | 1;
  }
  if (iVar10 == 0) {
    *(uint *)(param_2 + 0x7c) = *(uint *)(param_2 + 0x7c) & 0xfffffffe;
    *(uint *)(param_2 + 0x38) = *(uint *)(param_2 + 0x38) & 0xffffffef;
  }
  else {
    if ((*(int *)(param_1 + 0x2d) == 1) && (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      puVar15 = &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids;
      WPP_RECORDER_SF_dddd
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0x4f,
                 &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids,(char)iVar10,(char)iVar2,
                 (char)uVar9,(char)uVar11);
    }
    if (iVar10 != 0) {
      bVar14 = (byte)local_res10;
      do {
        if ((local_res10 == 0) || (uVar11 == 0)) break;
        if (*(int *)(param_1 + 0x2d) == 1) {
          if (uVar11 <= *(uint *)(param_2 + 0x94)) break;
          uVar11 = uVar11 - 1;
          uVar7 = 0x100;
          *(uint *)(param_2 + 0x94) = *(uint *)(param_2 + 0x94) + 1;
        }
        else {
          puVar8 = *(undefined8 **)(param_1 + 0x21);
          iVar12 = -0x3ffffffc;
          uVar9 = uVar13;
          if (uVar13 < *(uint *)(param_1 + 0x1d)) {
            for (; puVar8 != (undefined8 *)0x0; puVar8 = (undefined8 *)*puVar8) {
              puVar1 = (uint *)(puVar8 + 5);
              if (uVar9 < *puVar1) {
                if ((*(byte *)((longlong)puVar8 + 10) & 5) == 0) {
                  puVar15 = (undefined *)((ulonglong)puVar15 & 0xffffffff00000000);
                  lVar6 = MmMapLockedPagesSpecifyCache(puVar8,0,1,0,puVar15,0xc0000020);
                }
                else {
                  lVar6 = puVar8[3];
                }
                if (lVar6 != 0) {
                  iVar12 = 0;
                  bVar14 = *(byte *)((ulonglong)uVar9 + lVar6);
                }
                break;
              }
              uVar9 = uVar9 - *puVar1;
            }
          }
          if (iVar12 < 0) {
            *(int *)(param_1 + 0x18) = iVar12;
            WPP_RECORDER_SF_sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x50,
                               &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids,"I2CXferData",4);
            uVar13 = uVar13 + 1;
            break;
          }
          uVar7 = (ushort)bVar14;
        }
        uVar13 = uVar13 + 1;
        iVar2 = *(int *)(param_1 + 0xc);
        if (iVar2 == 1) {
          iVar4 = *(int *)(param_1 + 0x29);
          if ((iVar4 == 1) || (*(int *)(param_1 + 8) == 3)) {
            if (iVar10 == 1) {
              uVar7 = uVar7 | 0x200;
            }
          }
          else if (iVar4 != 2) {
            uVar5 = uVar7 | 0x400;
            if (iVar10 != *(int *)(param_1 + 0x1d)) {
              uVar5 = uVar7;
            }
            uVar7 = uVar5;
            if ((iVar4 == 4) && (iVar10 == 1)) {
              uVar7 = uVar7 | 0x200;
            }
          }
        }
        else {
          uVar9 = *(uint *)(param_1 + 0x10);
          if ((uVar9 != 0) && (uVar9 <= iVar2 - 1U)) {
            uVar5 = uVar7 | 0x400;
            if (iVar10 != *(int *)(param_1 + 0x1d)) {
              uVar5 = uVar7;
            }
            uVar7 = uVar5;
            if ((uVar9 == iVar2 - 1U) && (iVar10 == 1)) {
              uVar7 = uVar7 | 0x200;
            }
          }
        }
        if (((uVar7 & 0x200) != 0) &&
           (param_1[0x39] = (PBC_REQUEST)0x1, *(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
          puVar15 = &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids;
          WPP_RECORDER_SF_dddd
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0x51,
                     &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids,(char)iVar2,
                     (char)*(undefined4 *)(param_1 + 0x10),(char)*(undefined4 *)(param_1 + 0x29),
                     (char)*(undefined4 *)(param_1 + 8));
        }
        *(uint *)(*(longlong *)(param_2 + 0x20) + 0x10) = (uint)uVar7;
        LOCK();
        UNLOCK();
        local_res10 = local_res10 + -1;
        iVar10 = iVar10 + -1;
      } while (iVar10 != 0);
    }
    if (uVar13 < *(uint *)(param_1 + 0x1d)) {
      *(uint *)(param_2 + 0x80) = uVar13;
    }
    *(int *)(param_2 + 0x88) = iVar10;
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      WPP_RECORDER_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0x52,
                         &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids,(char)iVar10,
                         (char)*(undefined4 *)(param_2 + 0x94));
    }
    if (iVar10 == 0) {
      *(undefined4 *)(*(longlong *)(param_2 + 0x20) + 0x3c) = 0;
      LOCK();
      UNLOCK();
    }
  }
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x53,
                    &WPP_a919b1bcd7333ff56d299e546ed83146_Traceguids,"I2CXferData");
  return iVar12;
}



===== WPP_RECORDER_SF_ @ 140002bcc =====

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



===== WPP_RECORDER_SF_L @ 140002c8c =====

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



===== WPP_RECORDER_SF_LsLd @ 140002d7c =====

void WPP_RECORDER_SF_LsLd
               (undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,undefined8 param_5,
               undefined1 param_6,char *param_7,undefined1 param_8,undefined1 param_9)

{
  char *pcVar1;
  char *pcVar2;
  longlong lVar3;
  longlong lVar4;
  ulonglong uVar5;
  
  pcVar1 = param_7;
  uVar5 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar5 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar5 * 0x50 + 0x29])) {
    if (param_7 == (char *)0x0) {
      lVar4 = 5;
    }
    else {
      lVar3 = -1;
      do {
        lVar4 = lVar3;
        lVar3 = lVar4 + 1;
      } while (param_7[lVar3] != '\0');
      lVar4 = lVar4 + 2;
    }
    pcVar2 = "NULL";
    if (param_7 != (char *)0x0) {
      pcVar2 = param_7;
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar5 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,4,pcVar2,lVar4,&param_8,4,&param_9,4,0);
  }
  lVar4 = -1;
  if (pcVar1 == (char *)0x0) {
    lVar3 = 5;
  }
  else {
    do {
      lVar3 = lVar4;
      lVar4 = lVar3 + 1;
    } while (pcVar1[lVar4] != '\0');
    lVar3 = lVar3 + 2;
  }
  pcVar2 = "NULL";
  if (pcVar1 != (char *)0x0) {
    pcVar2 = pcVar1;
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,&param_6,4,pcVar2,lVar3,&param_8,4,
                  &param_9,4,0);
  return;
}



===== WPP_RECORDER_SF_dd @ 140002f3c =====

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



===== WPP_RECORDER_SF_dddd @ 140003050 =====

void WPP_RECORDER_SF_dddd
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



===== WPP_RECORDER_SF_qd @ 1400031ac =====

void WPP_RECORDER_SF_qd(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
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



===== WPP_RECORDER_SF_s @ 1400032c8 =====

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
    pcVar1 = "NULL";
    if (param_6 != (char *)0x0) {
      pcVar1 = param_6;
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
  pcVar1 = "NULL";
  if (param_6 != (char *)0x0) {
    pcVar1 = param_6;
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,pcVar1,lVar2,0);
  return;
}



===== WPP_RECORDER_SF_sd @ 140003408 =====

void WPP_RECORDER_SF_sd(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
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
    pcVar1 = "NULL";
    if (param_6 != (char *)0x0) {
      pcVar1 = param_6;
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
  pcVar1 = "NULL";
  if (param_6 != (char *)0x0) {
    pcVar1 = param_6;
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,pcVar1,lVar2,&param_7,4,0);
  return;
}



===== AllocResetIrp @ 140003578 =====

/* long __cdecl AllocResetIrp(struct PBC_DEVICE * __ptr64) */

long __cdecl AllocResetIrp(PBC_DEVICE *param_1)

{
  undefined4 *puVar1;
  longlong lVar2;
  
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,10,
                    &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,"AllocResetIrp");
  lVar2 = ExAllocatePoolWithQuotaTag(0x200,8,0x43324953);
  *(longlong *)(param_1 + 0x6c) = lVar2;
  if (lVar2 != 0) {
    lVar2 = ExAllocatePoolWithQuotaTag(0x200,0x14,0x43324953);
    *(longlong *)(param_1 + 100) = lVar2;
    if (lVar2 != 0) {
      lVar2 = ExAllocatePoolWithQuotaTag(0x200,0x10,0x43324953);
      *(longlong *)(param_1 + 0x74) = lVar2;
      if (lVar2 != 0) {
        puVar1 = *(undefined4 **)(param_1 + 0x6c);
        *puVar1 = 0x42696541;
        puVar1[1] = 0x54455352;
        WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0xb,
                          &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,"AllocResetIrp");
        return 0;
      }
    }
  }
  return -0x3fffff66;
}



===== FreeResetIrp @ 14000366c =====

/* long __cdecl FreeResetIrp(struct PBC_DEVICE * __ptr64) */

long __cdecl FreeResetIrp(PBC_DEVICE *param_1)

{
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0xc,
                    &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,"FreeResetIrp");
  if (*(longlong *)(param_1 + 0x6c) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x6c),0x43324953);
    *(undefined8 *)(param_1 + 0x6c) = 0;
  }
  if (*(longlong *)(param_1 + 100) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 100),0x43324953);
    *(undefined8 *)(param_1 + 100) = 0;
  }
  if (*(longlong *)(param_1 + 0x74) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x74),0x43324953);
    *(undefined8 *)(param_1 + 0x74) = 0;
  }
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0xd,
                    &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,"FreeResetIrp");
  return 0;
}



===== GetGeneration @ 140003738 =====

/* long __cdecl GetGeneration(struct WDFDEVICE__ * __ptr64,enum SBGeneration * __ptr64) */

long __cdecl GetGeneration(WDFDEVICE__ *param_1,SBGeneration *param_2)

{
  int iVar1;
  long lVar2;
  wchar_t *_Str2;
  longlong lVar3;
  undefined8 local_res8;
  undefined4 local_48 [6];
  undefined4 local_30;
  undefined4 local_2c;
  WDFDEVICE__ *local_28;
  
  memset(local_48,0,0x38);
  local_48[0] = 0x38;
  local_30 = 1;
  *param_2 = 0;
  local_2c = 1;
  local_28 = param_1;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x290))
                    (WdfDriverGlobals,param_1,1,0x200,local_48,&local_res8);
  if (iVar1 < 0) {
    lVar2 = -0x3fffffff;
  }
  else {
    _Str2 = (wchar_t *)(**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,local_res8,0);
    lVar3 = -1;
    do {
      lVar3 = lVar3 + 1;
    } while (_Str2[lVar3] != L'\0');
    while (lVar3 != 0) {
      iVar1 = wcsncmp(L"*AMD0010",_Str2,8);
      if (iVar1 == 0) {
        *param_2 = 1;
        break;
      }
      iVar1 = wcsncmp(L"*AMDI0010",_Str2,9);
      if (iVar1 == 0) {
        *param_2 = 3;
      }
      _Str2 = _Str2 + lVar3 + 1;
      lVar3 = -1;
      do {
        lVar3 = lVar3 + 1;
      } while (_Str2[lVar3] != L'\0');
    }
    lVar2 = 0;
  }
  return lVar2;
}



===== OnCancel @ 14000386c =====

/* void __cdecl OnCancel(struct WDFREQUEST__ * __ptr64) */

void __cdecl OnCancel(WDFREQUEST__ *param_1)

{
  bool bVar1;
  bool bVar2;
  char cVar3;
  undefined8 uVar4;
  PBC_DEVICE *pPVar5;
  longlong lVar6;
  PBC_REQUEST *pPVar7;
  undefined2 uVar8;
  
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x6e,
                     &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
  }
  bVar2 = false;
  bVar1 = false;
  uVar4 = (*DAT_14000b480)(SpbDriverGlobals,param_1);
  pPVar5 = (PBC_DEVICE *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,uVar4,PTR__WDF_PBC_DEVICE_TYPE_INFO_14000b018);
  uVar4 = (*DAT_14000b478)(SpbDriverGlobals,param_1);
  lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar4,PTR__WDF_PBC_TARGET_TYPE_INFO_14000b040);
  pPVar7 = (PBC_REQUEST *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_PBC_REQUEST_TYPE_INFO_14000b068);
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x6f,
                    &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,"OnCancel");
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(pPVar5 + 0x40));
  if (lVar6 == *(longlong *)(pPVar5 + 0x28)) {
    if (pPVar7 == *(PBC_REQUEST **)(lVar6 + 0xf)) {
      WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,4,0x72,
                        &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,"OnCancel");
      cVar3 = (**(code **)(WdfFunctions_01015 + 0xa00))
                        (WdfDriverGlobals,*(undefined8 *)(pPVar5 + 0x48),0);
      if (cVar3 != '\0') {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,4,0x73,
                         &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
      }
      ControllerDisableInterrupts(pPVar5);
      if (*(int *)(pPVar7 + 0x2d) == 1) {
        I2CReadData(pPVar7,pPVar5);
      }
      bVar2 = true;
      *(undefined4 *)(pPVar7 + 0x18) = 0xc0000120;
      if (((pPVar7[0x39] == (PBC_REQUEST)0x0) || (pPVar7[0x3a] != (PBC_REQUEST)0x0)) ||
         (*(int *)(pPVar7 + 0x35) != *(int *)(pPVar7 + 0x1d))) {
        if ((*(int *)(pPVar5 + 0xa0) != 0) && (pPVar7[0x3a] == (PBC_REQUEST)0x0)) {
          uVar8 = 0x75;
          goto LAB_140003aa5;
        }
        if (pPVar7[0x39] != (PBC_REQUEST)0x0) goto LAB_140003b28;
        if (pPVar5[0xeb] == (PBC_DEVICE)0x0) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,4,0x76,
                           &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
          *(uint *)(pPVar5 + 0x38) = *(uint *)(pPVar5 + 0x38) | 0x40;
          ControllerEnableInterrupts(pPVar5,*(ulong *)(pPVar5 + 0x38));
          ControllerEnableController(pPVar5,3);
          I2CWaitForNoActivity(pPVar5,100);
          ControllerDisableInterrupts(pPVar5);
          goto LAB_140003b28;
        }
      }
      else {
        if ((*(uint *)(*(longlong *)(pPVar5 + 0x20) + 0x70) & 0x20) != 0) goto LAB_140003b28;
        uVar8 = 0x74;
LAB_140003aa5:
        bVar1 = true;
        WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,uVar8,
                          &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,"OnCancel");
LAB_140003b28:
        if (pPVar5[0xeb] == (PBC_DEVICE)0x0) {
          ControllerDisableController(pPVar5);
        }
      }
      if ((pPVar5[0xed] != (PBC_DEVICE)0x0) || (bVar1)) {
        pPVar5[0xec] = (PBC_DEVICE)0x1;
      }
      ControllerCompleteTransfer(pPVar5,pPVar7);
      goto LAB_140003b59;
    }
    uVar8 = 0x71;
  }
  else {
    uVar8 = 0x70;
  }
  WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,4,uVar8,
                   &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
LAB_140003b59:
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(pPVar5 + 0x40));
  if (bVar2) {
    PbcRequestComplete(pPVar7);
  }
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x77,
                    &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,"OnCancel");
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x78,
                     &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
  }
  return;
}



===== OnControllerLock @ 140003bec =====

/* void __cdecl OnControllerLock(struct WDFDEVICE__ * __ptr64,struct SPBTARGET__ * __ptr64,struct
   SPBREQUEST__ * __ptr64) */

void __cdecl OnControllerLock(WDFDEVICE__ *param_1,SPBTARGET__ *param_2,SPBREQUEST__ *param_3)

{
  longlong lVar1;
  longlong lVar2;
  
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x34,
                     &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
  }
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x35,
                    &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,"OnControllerLock");
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_14000b018);
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_PBC_TARGET_TYPE_INFO_14000b040);
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(lVar1 + 0x40));
  *(longlong *)(lVar1 + 0x28) = lVar2;
  *(undefined1 *)(lVar1 + 0xeb) = 1;
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(lVar1 + 0x40));
  WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x36,
                    &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,
                    (char)*(undefined2 *)(lVar2 + 9));
  (*DAT_14000b498)(SpbDriverGlobals,param_3,0);
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x37,
                    &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,"OnControllerLock");
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x38,
                     &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
  }
  return;
}



===== OnControllerUnlock @ 140003d90 =====

/* void __cdecl OnControllerUnlock(struct WDFDEVICE__ * __ptr64,struct SPBTARGET__ * __ptr64,struct
   SPBREQUEST__ * __ptr64) */

void __cdecl OnControllerUnlock(WDFDEVICE__ *param_1,SPBTARGET__ *param_2,SPBREQUEST__ *param_3)

{
  PBC_DEVICE *pPVar1;
  longlong lVar2;
  
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x39,
                     &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
  }
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x3a,
                    &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,"OnControllerUnlock");
  pPVar1 = (PBC_DEVICE *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_14000b018);
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_PBC_TARGET_TYPE_INFO_14000b040);
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(pPVar1 + 0x40));
  if (*(longlong *)(lVar2 + 0xf) == 0) {
    if (*(int *)(*(longlong *)(pPVar1 + 0x20) + 0x6c) == 0) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,2,0x3c,
                       &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
    }
    *(uint *)(pPVar1 + 0x38) = *(uint *)(pPVar1 + 0x38) | 0x40;
    ControllerEnableInterrupts(pPVar1,*(ulong *)(pPVar1 + 0x38));
  }
  else {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x3b,
                     &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
  }
  ControllerEnableController(pPVar1,3);
  I2CWaitForNoActivity(pPVar1,100);
  ControllerDisableController(pPVar1);
  *(undefined8 *)(pPVar1 + 0x28) = 0;
  pPVar1[0xeb] = (PBC_DEVICE)0x0;
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(pPVar1 + 0x40));
  WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x3d,
                    &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,
                    (char)*(undefined2 *)(lVar2 + 9));
  (*DAT_14000b498)(SpbDriverGlobals,param_3,0);
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x3e,
                    &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,"OnControllerUnlock");
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x3f,
                     &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
  }
  return;
}



===== OnD0Entry @ 140003fc0 =====

/* long __cdecl OnD0Entry(struct WDFDEVICE__ * __ptr64,enum _WDF_POWER_DEVICE_STATE) */

long __cdecl OnD0Entry(WDFDEVICE__ *param_1,_WDF_POWER_DEVICE_STATE param_2)

{
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x18,
                     &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
  }
  WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x19,
                   &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x1a,
                     &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
  }
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x1b,
                    &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,"OnD0Entry");
  return 0;
}



===== OnD0Exit @ 140004074 =====

/* long __cdecl OnD0Exit(struct WDFDEVICE__ * __ptr64,enum _WDF_POWER_DEVICE_STATE) */

long __cdecl OnD0Exit(WDFDEVICE__ *param_1,_WDF_POWER_DEVICE_STATE param_2)

{
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x1c,
                     &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
  }
  WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x1d,
                   &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x1e,
                     &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
  }
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x1f,
                    &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,"OnD0Exit");
  return 0;
}



===== OnDelayTimerExpired @ 140004128 =====

/* void __cdecl OnDelayTimerExpired(struct WDFTIMER__ * __ptr64) */

void __cdecl OnDelayTimerExpired(WDFTIMER__ *param_1)

{
  PBC_REQUEST *pPVar1;
  undefined8 uVar2;
  PBC_DEVICE *pPVar3;
  undefined2 uVar4;
  
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0xbe,
                     &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
  }
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0xbf,
                    &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,"OnDelayTimerExpired");
  uVar2 = (**(code **)(WdfFunctions_01015 + 0xa08))(WdfDriverGlobals,param_1);
  pPVar3 = (PBC_DEVICE *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,uVar2,PTR__WDF_PBC_DEVICE_TYPE_INFO_14000b018);
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(pPVar3 + 0x40));
  if (*(longlong *)(pPVar3 + 0x28) == 0) {
    uVar4 = 0xc0;
  }
  else {
    pPVar1 = *(PBC_REQUEST **)(*(longlong *)(pPVar3 + 0x28) + 0xf);
    if (pPVar1 != (PBC_REQUEST *)0x0) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0xc2,
                       &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
      (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(pPVar3 + 0x40));
      ControllerConfigureForTransfer(pPVar3,pPVar1);
      goto LAB_140004291;
    }
    uVar4 = 0xc1;
  }
  WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,4,uVar4,
                   &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(pPVar3 + 0x40));
LAB_140004291:
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0xc3,
                    &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,"OnDelayTimerExpired");
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0xc4,
                     &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
  }
  return;
}



===== OnDeviceD0EntryPostInterruptsEnabled @ 1400042fc =====

/* long __cdecl OnDeviceD0EntryPostInterruptsEnabled(struct WDFDEVICE__ * __ptr64,enum
   _WDF_POWER_DEVICE_STATE) */

long __cdecl
OnDeviceD0EntryPostInterruptsEnabled(WDFDEVICE__ *param_1,_WDF_POWER_DEVICE_STATE param_2)

{
  PBC_DEVICE *pPVar1;
  
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0x7b,
                     &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
  }
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x7c,
                    &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,
                    "OnDeviceD0EntryPostInterruptsEnabled");
  pPVar1 = (PBC_DEVICE *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_14000b018);
  *(undefined8 *)(pPVar1 + 0x28) = 0;
  ControllerInitialize(pPVar1);
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0x7d,
                     &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
  }
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x7e,
                    &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,
                    "OnDeviceD0EntryPostInterruptsEnabled");
  return 0;
}



===== OnDeviceD0ExitPreInterruptsDisabled @ 140004400 =====

/* long __cdecl OnDeviceD0ExitPreInterruptsDisabled(struct WDFDEVICE__ * __ptr64,enum
   _WDF_POWER_DEVICE_STATE) */

long __cdecl
OnDeviceD0ExitPreInterruptsDisabled(WDFDEVICE__ *param_1,_WDF_POWER_DEVICE_STATE param_2)

{
  PBC_DEVICE *pPVar1;
  
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0x7f,
                     &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
  }
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x80,
                    &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,
                    "OnDeviceD0ExitPreInterruptsDisabled");
  pPVar1 = (PBC_DEVICE *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_14000b018);
  *(undefined8 *)(pPVar1 + 0x28) = 0;
  ControllerUninitialize(pPVar1);
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0x81,
                     &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
  }
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x82,
                    &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,
                    "OnDeviceD0ExitPreInterruptsDisabled");
  return 0;
}



===== OnInterruptDisable @ 140004504 =====

/* long __cdecl OnInterruptDisable(struct WDFINTERRUPT__ * __ptr64,struct WDFDEVICE__ * __ptr64) */

long __cdecl OnInterruptDisable(WDFINTERRUPT__ *param_1,WDFDEVICE__ *param_2)

{
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0x87,
                     &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
  }
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x88,
                    &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,"OnInterruptDisable");
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0x89,
                     &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
  }
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x8a,
                    &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,"OnInterruptDisable");
  return 0;
}



===== OnInterruptDpc @ 1400045d0 =====

/* void __cdecl OnInterruptDpc(struct WDFINTERRUPT__ * __ptr64,void * __ptr64) */

void __cdecl OnInterruptDpc(WDFINTERRUPT__ *param_1,void *param_2)

{
  ulong uVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  uchar uVar7;
  uchar uVar8;
  long lVar9;
  PBC_DEVICE *pPVar10;
  ulong uVar11;
  PBC_REQUEST *pPVar12;
  undefined2 uVar13;
  
  bVar4 = false;
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0x95,
                     &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
  }
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x96,
                    &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,"OnInterruptDpc");
  pPVar12 = (PBC_REQUEST *)0x0;
  bVar6 = false;
  bVar5 = false;
  bVar3 = false;
  bVar2 = false;
  uVar8 = '\0';
  pPVar10 = (PBC_DEVICE *)
            (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,param_2,PTR__WDF_PBC_DEVICE_TYPE_INFO_14000b018);
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(pPVar10 + 0x40));
  if (*(longlong *)(pPVar10 + 0x28) == 0) {
    uVar13 = 0x97;
  }
  else {
    pPVar12 = *(PBC_REQUEST **)(*(longlong *)(pPVar10 + 0x28) + 0xf);
    if (pPVar12 != (PBC_REQUEST *)0x0) {
      (**(code **)(WdfFunctions_01015 + 0x480))(WdfDriverGlobals,param_1);
      uVar1 = *(ulong *)(pPVar10 + 0x3c);
      *(undefined4 *)(pPVar10 + 0x3c) = 0;
      (**(code **)(WdfFunctions_01015 + 0x488))(WdfDriverGlobals,param_1);
      uVar7 = ControllerProcessInterrupts(pPVar10,pPVar12,uVar1);
      if (uVar7 == '\0') {
        ControllerCompleteTransfer(pPVar10,pPVar12);
        bVar5 = pPVar12[0x1c] != (PBC_REQUEST)0x0;
      }
      else {
        if (((*(uint *)(pPVar10 + 0x3c) | uVar1) & 0x40) == 0) {
          if ((uVar1 & 0x14) != 0) {
            if (*(int *)(pPVar12 + 0x2d) == 1) {
              if ((((byte)pPVar10[0x7c] & 10) == 0) && ((uVar1 & 4) != 0)) {
LAB_140004797:
                bVar3 = true;
                bVar2 = true;
                uVar8 = I2CPostXfer(pPVar12,pPVar10);
                if (uVar8 != '\0') {
                  lVar9 = PbcRequestConfigureForIndex(pPVar12,*(ulong *)(pPVar12 + 0x10));
                  *(long *)(pPVar12 + 0x18) = lVar9;
                  if (-1 < lVar9) {
                    PbcRequestDoTransfer(pPVar10,pPVar12);
                  }
                  goto LAB_14000482a;
                }
              }
            }
            else if (((byte)pPVar10[0x7c] & 5) == 0) goto LAB_140004797;
            uVar11 = *(uint *)(pPVar10 + 0x38) & 0x254;
            bVar2 = bVar3;
LAB_140004822:
            ControllerEnableInterrupts(pPVar10,uVar11);
          }
LAB_14000482a:
          if ((uVar1 >> 9 & 1) != 0) goto LAB_140004834;
          if ((((pPVar10[0xeb] != (PBC_DEVICE)0x0) && (bVar2)) && (uVar8 == '\0')) && (!bVar4)) {
            ControllerCompleteTransfer(pPVar10,pPVar12);
          }
        }
        else {
          *(undefined4 *)(pPVar10 + 0xa0) = 1;
          bVar4 = true;
          if ((uVar1 & 0x40) != 0) {
            I2CHandleTxAbort(pPVar12,pPVar10,uVar1);
          }
          if ((uVar1 >> 9 & 1) == 0) {
            WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,4,0x99,
                             &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
            uVar11 = 0x200;
            bVar2 = bVar3;
            goto LAB_140004822;
          }
LAB_140004834:
          pPVar12[0x3a] = (PBC_REQUEST)0x1;
          if (-1 < *(int *)(pPVar12 + 0x18)) {
            if ((*(int *)(pPVar12 + 0x14) == 0) && (((byte)pPVar10[0x7c] & 2) != 0)) {
              WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,4,0x9a,
                               &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
            }
            if ((((byte)pPVar10[0x7c] & 2) != 0) && (*(int *)(pPVar12 + 8) == 1)) {
              WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,4,0x9b,
                                &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,
                                (char)*(undefined4 *)(*(longlong *)(pPVar10 + 0x20) + 0x78));
              *(int *)(pPVar12 + 0x14) = *(int *)(pPVar12 + 0x14) + *(int *)(pPVar12 + 0x35);
            }
          }
          ControllerCompleteTransfer(pPVar10,pPVar12);
          ControllerDisableController(pPVar10);
        }
        bVar5 = false;
        if (pPVar12[0x1c] != (PBC_REQUEST)0x0) {
          bVar5 = true;
        }
      }
      bVar6 = true;
      goto LAB_14000491b;
    }
    uVar13 = 0x98;
  }
  WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,4,uVar13,
                   &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
LAB_14000491b:
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(pPVar10 + 0x40));
  if ((bVar6) && (bVar5)) {
    PbcRequestComplete(pPVar12);
  }
  if (pPVar12 == (PBC_REQUEST *)0x0) {
    *(undefined4 *)(pPVar10 + 0x3c) = 0;
  }
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x9c,
                    &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,"OnInterruptDpc");
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0x9d,
                     &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
  }
  return;
}



===== OnInterruptEnable @ 1400049c4 =====

/* long __cdecl OnInterruptEnable(struct WDFINTERRUPT__ * __ptr64,struct WDFDEVICE__ * __ptr64) */

long __cdecl OnInterruptEnable(WDFINTERRUPT__ *param_1,WDFDEVICE__ *param_2)

{
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0x83,
                     &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
  }
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x84,
                    &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,"OnInterruptEnable");
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0x85,
                     &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
  }
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x86,
                    &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,"OnInterruptEnable");
  return 0;
}



===== OnInterruptIsr @ 140004a8c =====

/* unsigned char __cdecl OnInterruptIsr(struct WDFINTERRUPT__ * __ptr64,unsigned long) */

uchar __cdecl OnInterruptIsr(WDFINTERRUPT__ *param_1,ulong param_2)

{
  uint uVar1;
  char cVar2;
  undefined8 uVar3;
  longlong lVar4;
  uchar uVar5;
  undefined2 uVar6;
  undefined1 uVar7;
  
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0x8b,
                     &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
  }
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x8c,
                    &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,"OnInterruptIsr");
  uVar5 = '\0';
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x4b8))(WdfDriverGlobals,param_1);
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar3,PTR__WDF_PBC_DEVICE_TYPE_INFO_14000b018);
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x79,
                    &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,"I2CReadClearIntrbits");
  uVar1 = *(uint *)(*(longlong *)(lVar4 + 0x20) + 0x2c);
  if ((uVar1 & 0x40) != 0) {
    *(uint *)(lVar4 + 0x98) = *(uint *)(*(longlong *)(lVar4 + 0x20) + 0x74) & 0xff;
    *(undefined4 *)(lVar4 + 0x9c) = *(undefined4 *)(*(longlong *)(lVar4 + 0x20) + 0x80);
  }
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x7a,
                    &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,"I2CReadClearIntrbits");
  *(uint *)(lVar4 + 0x3c) = *(uint *)(lVar4 + 0x3c) | uVar1;
  if ((*(short *)(WPP_GLOBAL_Control + 0x48) != 0) &&
     (WPP_RECORDER_SF_DDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x8d,
                          &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,
                          (char)*(undefined4 *)(lVar4 + 0x3c),(char)*(undefined4 *)(lVar4 + 0x38),
                          (char)*(undefined4 *)(lVar4 + 0x9c)),
     *(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x8e,
                      &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,0);
  }
  *(undefined4 *)(*(longlong *)(lVar4 + 0x20) + 0x30) = 0;
  LOCK();
  UNLOCK();
  if (*(longlong *)(lVar4 + 0x28) == 0) {
    uVar6 = 0x8f;
  }
  else {
    if (*(longlong *)(*(longlong *)(lVar4 + 0x28) + 0xf) != 0) {
      uVar1 = *(uint *)(*(longlong *)(lVar4 + 0x20) + 0x34);
      uVar7 = (undefined1)uVar1;
      if ((*(int *)(*(longlong *)(lVar4 + 0x20) + 0x6c) == 0) || ((uVar1 & 0xfffffeff) == 0)) {
        WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x91,
                          &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,uVar7);
        uVar5 = '\0';
      }
      else {
        uVar5 = '\x01';
        cVar2 = (**(code **)(WdfFunctions_01015 + 0x470))(WdfDriverGlobals,param_1);
        if (cVar2 == '\0') {
          WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x92,
                            &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,uVar7);
        }
      }
      goto LAB_140004da9;
    }
    uVar6 = 0x90;
  }
  WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,4,uVar6,
                   &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
LAB_140004da9:
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0x93,
                     &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
  }
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x94,
                    &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,"OnInterruptIsr");
  return uVar5;
}



===== OnMonitorPowerSettingCallback @ 140004e24 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl OnMonitorPowerSettingCallback(struct _GUID const * __ptr64,void * __ptr64,unsigned
   long,void * __ptr64) */

long __cdecl OnMonitorPowerSettingCallback(_GUID *param_1,void *param_2,ulong param_3,void *param_4)

{
  int iVar1;
  undefined2 uVar2;
  undefined1 auStackY_88 [32];
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  int local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_88;
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x29,
                     &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
  }
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x2a,
                    &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,"OnMonitorPowerSettingCallback"
                   );
  iVar1 = 0;
  if (param_4 == (void *)0x0) {
    uVar2 = 0x2b;
    iVar1 = -0x3ffffff3;
  }
  else {
    if ((*(longlong *)param_1 != 0x4526451002731015) ||
       (*(longlong *)(param_1 + 8) != -0x15e542815e1a1967)) goto LAB_140004f8d;
    memset(&local_58,0,0x24);
    local_58 = 0x24;
    local_48 = 2;
    local_44 = 2;
    local_4c = (-(uint)(*(int *)param_2 != 0) & 0xed8) + 200;
    local_40 = 2;
    local_38 = 2;
    local_54 = 1;
    local_50 = 4;
    local_3c = 2;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x170))(WdfDriverGlobals,param_4,&local_58);
    if (-1 < iVar1) goto LAB_140004f8d;
    uVar2 = 0x2c;
  }
  WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,uVar2,
                    &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,(char)iVar1);
LAB_140004f8d:
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x2d,
                     &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
  }
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x2e,
                    &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,"OnMonitorPowerSettingCallback"
                   );
  return iVar1;
}



===== OnOther @ 140005008 =====

/* void __cdecl OnOther(struct WDFDEVICE__ * __ptr64,struct SPBTARGET__ * __ptr64,struct
   SPBREQUEST__ * __ptr64,unsigned __int64,unsigned __int64,unsigned long) */

void __cdecl
OnOther(WDFDEVICE__ *param_1,SPBTARGET__ *param_2,SPBREQUEST__ *param_3,__uint64 param_4,
       __uint64 param_5,ulong param_6)

{
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x6a,
                     &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
  }
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x6b,
                    &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,"OnOther");
  (*DAT_14000b498)(SpbDriverGlobals,param_3,0);
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x6c,
                    &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,"OnOther");
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x6d,
                     &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
  }
  return;
}



===== OnOtherInCallerContext @ 1400050e8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl OnOtherInCallerContext(struct WDFDEVICE__ * __ptr64,struct WDFREQUEST__ * __ptr64)
    */

void __cdecl OnOtherInCallerContext(WDFDEVICE__ *param_1,WDFREQUEST__ *param_2)

{
  undefined1 auStackY_78 [32];
  undefined2 local_38 [2];
  int local_34;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_78;
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x55,
                     &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
  }
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x56,
                    &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,"OnOtherInCallerContext");
  memset(local_38,0,0x28);
  local_38[0] = 0x28;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,local_38);
  if (1 < local_34 - 0xeU) {
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x57,
                       &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,(char)param_2,0xbb);
  }
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,0xc00000bb);
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x59,
                    &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,"OnOtherInCallerContext");
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x5a,
                     &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
  }
  return;
}



===== OnPrepareHardware @ 140005268 =====

/* long __cdecl OnPrepareHardware(struct WDFDEVICE__ * __ptr64,struct WDFCMRESLIST__ *
   __ptr64,struct WDFCMRESLIST__ * __ptr64) */

long __cdecl OnPrepareHardware(WDFDEVICE__ *param_1,WDFCMRESLIST__ *param_2,WDFCMRESLIST__ *param_3)

{
  uint uVar1;
  long lVar2;
  PBC_DEVICE *pPVar3;
  char *pcVar4;
  longlong lVar5;
  longlong lVar6;
  uint uVar7;
  
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0xe,
                     &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
  }
  pPVar3 = (PBC_DEVICE *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_14000b018);
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0xf,
                    &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,"OnPrepareHardware");
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x980))(WdfDriverGlobals,param_3);
  uVar7 = 0;
  if (uVar1 != 0) {
    do {
      pcVar4 = (char *)(**(code **)(WdfFunctions_01015 + 0x988))(WdfDriverGlobals,param_3,uVar7);
      if (*pcVar4 == '\x03') {
        lVar5 = (**(code **)(WdfFunctions_01015 + 0x988))(WdfDriverGlobals,param_2,uVar7);
        lVar6 = MmMapIoSpaceEx(*(undefined8 *)(pcVar4 + 4),*(undefined4 *)(pcVar4 + 0xc),0x204);
        *(longlong *)(pPVar3 + 0x10) = lVar6;
        *(undefined4 *)(pPVar3 + 0x18) = *(undefined4 *)(pcVar4 + 0xc);
        if (lVar6 == 0) {
          lVar2 = -0x3fffff66;
          WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x10,
                            &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,0x9a);
          goto LAB_14000546a;
        }
        *(longlong *)(pPVar3 + 0x20) = lVar6;
        WPP_RECORDER_SF_xq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x11,
                           &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,
                           (char)*(undefined8 *)(lVar5 + 4),(char)lVar6);
      }
      if (*pcVar4 == '\x01') {
        *(short *)(pPVar3 + 0xe8) = (short)*(undefined8 *)(pcVar4 + 4);
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < uVar1);
  }
  if (*(int *)(*(longlong *)(pPVar3 + 0x20) + 0xfc) == 0x44570140) {
    lVar2 = GetGeneration(param_1,(SBGeneration *)(pPVar3 + 0xe4));
    if ((-1 < lVar2) && (lVar2 = AllocResetIrp(pPVar3), lVar2 < 0)) {
      FreeResetIrp(pPVar3);
    }
  }
  else {
    lVar2 = -0x3fffffff;
  }
LAB_14000546a:
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x12,
                     &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
  }
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x13,
                    &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,"OnPrepareHardware");
  return lVar2;
}



===== OnRead @ 1400054dc =====

/* void __cdecl OnRead(struct WDFDEVICE__ * __ptr64,struct SPBTARGET__ * __ptr64,struct SPBREQUEST__
   * __ptr64,unsigned __int64) */

void __cdecl
OnRead(WDFDEVICE__ *param_1,SPBTARGET__ *param_2,SPBREQUEST__ *param_3,__uint64 param_4)

{
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x40,
                     &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
  }
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x41,
                    &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,"OnRead");
  PbcRequestConfigureForNonSequence(param_1,param_2,param_3,param_4);
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x42,
                    &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,"OnRead");
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x43,
                     &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
  }
  return;
}



===== OnReleaseHardware @ 1400055d4 =====

/* long __cdecl OnReleaseHardware(struct WDFDEVICE__ * __ptr64,struct WDFCMRESLIST__ * __ptr64) */

long __cdecl OnReleaseHardware(WDFDEVICE__ *param_1,WDFCMRESLIST__ *param_2)

{
  PBC_DEVICE *pPVar1;
  
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x14,
                     &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
  }
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x15,
                    &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,"OnReleaseHardware");
  pPVar1 = (PBC_DEVICE *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_14000b018);
  if (*(longlong *)(pPVar1 + 0x10) != 0) {
    MmUnmapIoSpace(*(longlong *)(pPVar1 + 0x10),*(undefined4 *)(pPVar1 + 0x18));
    *(undefined8 *)(pPVar1 + 0x10) = 0;
    *(undefined4 *)(pPVar1 + 0x18) = 0;
  }
  FreeResetIrp(pPVar1);
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x16,
                     &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
  }
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x17,
                    &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,"OnReleaseHardware");
  return 0;
}



===== OnSelfManagedIoCleanup @ 1400056f0 =====

/* void __cdecl OnSelfManagedIoCleanup(struct WDFDEVICE__ * __ptr64) */

void __cdecl OnSelfManagedIoCleanup(WDFDEVICE__ *param_1)

{
  longlong lVar1;
  
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x25,
                     &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
  }
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x26,
                    &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,"OnSelfManagedIoCleanup");
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_14000b018);
  if (*(longlong *)(lVar1 + 0x50) != 0) {
    PoUnregisterPowerSettingCallback();
    *(undefined8 *)(lVar1 + 0x50) = 0;
  }
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x27,
                    &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,"OnSelfManagedIoCleanup");
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x28,
                     &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
  }
  return;
}



===== OnSelfManagedIoInit @ 1400057fc =====

/* long __cdecl OnSelfManagedIoInit(struct WDFDEVICE__ * __ptr64) */

long __cdecl OnSelfManagedIoInit(WDFDEVICE__ *param_1)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x20,
                     &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
  }
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x21,
                    &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,"OnSelfManagedIoInit");
  puVar2 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_14000b018);
  uVar3 = (**(code **)(WdfFunctions_01015 + 0xf8))(WdfDriverGlobals,*puVar2);
  iVar1 = PoRegisterPowerSettingCallback
                    (uVar3,&GUID_MONITOR_POWER_ON,OnMonitorPowerSettingCallback,*puVar2,puVar2 + 10)
  ;
  if (iVar1 < 0) {
    WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x22,
                      &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,(char)iVar1);
  }
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x23,
                     &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
  }
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x24,
                    &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,"OnSelfManagedIoInit");
  return iVar1;
}



===== OnSequence @ 140005964 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl OnSequence(struct WDFDEVICE__ * __ptr64,struct SPBTARGET__ * __ptr64,struct
   SPBREQUEST__ * __ptr64,unsigned long) */

void __cdecl
OnSequence(WDFDEVICE__ *param_1,SPBTARGET__ *param_2,SPBREQUEST__ *param_3,ulong param_4)

{
  long lVar1;
  PBC_DEVICE *pPVar2;
  longlong lVar3;
  PBC_REQUEST *pPVar4;
  undefined2 uVar5;
  undefined1 auStackY_a8 [32];
  undefined2 local_68 [2];
  int local_64;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_a8;
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x4a,
                     &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
  }
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x4b,
                    &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,"OnSequence");
  pPVar2 = (PBC_DEVICE *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_14000b018);
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_PBC_TARGET_TYPE_INFO_14000b040);
  pPVar4 = (PBC_REQUEST *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_3,PTR__WDF_PBC_REQUEST_TYPE_INFO_14000b068);
  memset(local_68,0,0x20);
  local_68[0] = 0x20;
  (*DAT_14000b488)(SpbDriverGlobals,param_3,local_68);
  if (local_64 == 3) {
    WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x4c,
                      &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,(char)param_4);
    *(SPBREQUEST__ **)pPVar4 = param_3;
    *(int *)(pPVar4 + 8) = local_64;
    *(undefined8 *)(pPVar4 + 0x10) = 0;
    *(ulong *)(pPVar4 + 0xc) = param_4;
    pPVar4[0x1c] = (PBC_REQUEST)0x0;
    *(undefined2 *)(pPVar4 + 0x39) = 0;
    *(undefined4 *)(pPVar4 + 0x18) = 0;
    pPVar4[0x3b] = (PBC_REQUEST)0x0;
    lVar1 = PbcRequestValidate(pPVar4);
    if (-1 < lVar1) {
      if (param_4 == 1) {
        lVar1 = PbcRequestConfigureForIndex(pPVar4,0);
        if (lVar1 < 0) {
          uVar5 = 0x4d;
LAB_140005be5:
          WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,uVar5,
                            &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,(char)lVar1);
          goto LAB_140005c12;
        }
      }
      else if (param_4 < 2) {
        lVar1 = -0x3ffffff0;
LAB_140005c12:
        if (lVar1 < 0) goto LAB_140005a9f;
      }
      else {
        lVar1 = PbcRequestConfigureForIndex(pPVar4,0);
        if (lVar1 < 0) {
          uVar5 = 0x4e;
          goto LAB_140005be5;
        }
      }
      (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(pPVar2 + 0x40));
      *(longlong *)(pPVar2 + 0x28) = lVar3;
      *(PBC_REQUEST **)(lVar3 + 0xf) = pPVar4;
      if (pPVar2[0xec] == (PBC_DEVICE)0x0) {
        lVar1 = (**(code **)(WdfFunctions_01015 + 0xc48))
                          (WdfDriverGlobals,*(undefined8 *)pPVar4,OnCancel);
        if (-1 < lVar1) {
          PbcRequestDoTransfer(pPVar2,pPVar4);
          goto LAB_140005d41;
        }
        WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x51,
                           &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,
                           (char)*(undefined8 *)pPVar4,(char)lVar1);
LAB_140005c84:
        *(undefined8 *)(pPVar2 + 0x28) = 0;
        *(undefined8 *)(lVar3 + 0xf) = 0;
        (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(pPVar2 + 0x40));
      }
      else {
        lVar1 = ResetI2CController(pPVar2,pPVar4);
        if (lVar1 < 0) {
          WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x4f,
                            &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,(char)lVar1);
          goto LAB_140005c84;
        }
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0x50,
                         &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
        pPVar4[0x3b] = (PBC_REQUEST)0x1;
LAB_140005d41:
        (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(pPVar2 + 0x40));
      }
      if (-1 < lVar1) goto LAB_140005ad7;
    }
  }
  else {
    lVar1 = -0x3ffffff3;
  }
LAB_140005a9f:
  WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x52,
                    &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,(char)lVar1);
  (*DAT_14000b498)(SpbDriverGlobals,param_3,lVar1);
LAB_140005ad7:
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x53,
                    &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,"OnSequence");
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x54,
                     &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
  }
  return;
}



===== OnTargetConnect @ 140005d70 =====

/* long __cdecl OnTargetConnect(struct WDFDEVICE__ * __ptr64,struct SPBTARGET__ * __ptr64) */

long __cdecl OnTargetConnect(WDFDEVICE__ *param_1,SPBTARGET__ *param_2)

{
  long lVar1;
  PBC_DEVICE *pPVar2;
  undefined8 *puVar3;
  undefined8 local_38;
  undefined8 local_30;
  void *local_28;
  
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x2f,
                     &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
  }
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x30,
                    &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,"OnTargetConnect");
  pPVar2 = (PBC_DEVICE *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_14000b018);
  puVar3 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_2,PTR__WDF_PBC_TARGET_TYPE_INFO_14000b040);
  local_30 = 0;
  local_28 = (void *)0x0;
  local_38 = 0x18;
  (*DAT_14000b468)(SpbDriverGlobals,param_2,&local_38);
  lVar1 = PbcTargetGetSettings(pPVar2,local_28,(PBC_TARGET_SETTINGS *)(puVar3 + 1));
  if (-1 < lVar1) {
    *puVar3 = param_2;
    *(undefined8 *)((longlong)puVar3 + 0xf) = 0;
    WPP_RECORDER_SF_qLq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x31,
                        &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,(char)param_2,
                        (char)*(undefined2 *)((longlong)puVar3 + 9),(char)*(undefined8 *)pPVar2);
  }
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x32,
                     &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
  }
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x33,
                    &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,"OnTargetConnect");
  return lVar1;
}



===== OnWrite @ 140005f24 =====

/* void __cdecl OnWrite(struct WDFDEVICE__ * __ptr64,struct SPBTARGET__ * __ptr64,struct
   SPBREQUEST__ * __ptr64,unsigned __int64) */

void __cdecl
OnWrite(WDFDEVICE__ *param_1,SPBTARGET__ *param_2,SPBREQUEST__ *param_3,__uint64 param_4)

{
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x44,
                     &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
  }
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x45,
                    &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,"OnWrite");
  PbcRequestConfigureForNonSequence(param_1,param_2,param_3,param_4);
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x46,
                    &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,"OnWrite");
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x47,
                     &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
  }
  return;
}



===== PbcRequestComplete @ 14000601c =====

/* void __cdecl PbcRequestComplete(struct PBC_REQUEST * __ptr64) */

void __cdecl PbcRequestComplete(PBC_REQUEST *param_1)

{
  char *pcVar1;
  
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0xc5,
                     &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
  }
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0xc6,
                    &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,"PbcRequestComplete");
  pcVar1 = "error";
  if (-1 < *(int *)(param_1 + 0x18)) {
    pcVar1 = "complete";
  }
  WPP_RECORDER_SF_sLd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,199,
                      &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,pcVar1,
                      (char)*(undefined4 *)(param_1 + 0x14),(char)*(int *)(param_1 + 0x18));
  (**(code **)(WdfFunctions_01015 + 0x898))
            (WdfDriverGlobals,*(undefined8 *)param_1,*(undefined4 *)(param_1 + 0x14));
  (*DAT_14000b498)(SpbDriverGlobals,*(undefined8 *)param_1,*(undefined4 *)(param_1 + 0x18));
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,200,
                    &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,"PbcRequestComplete");
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0xc9,
                     &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
  }
  return;
}



===== PbcRequestConfigureForIndex @ 140006178 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl PbcRequestConfigureForIndex(struct PBC_REQUEST * __ptr64,unsigned long) */

long __cdecl PbcRequestConfigureForIndex(PBC_REQUEST *param_1,ulong param_2)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  char *pcVar3;
  undefined1 auStackY_98 [32];
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_98;
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0xb3,
                     &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
  }
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0xb4,
                    &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,"PbcRequestConfigureForIndex");
  local_38 = 0;
  local_30 = 0;
  local_40 = 0x18;
  (*DAT_14000b490)(SpbDriverGlobals,*(undefined8 *)param_1,param_2,&local_40);
  *(undefined8 *)(param_1 + 0x21) = local_48;
  *(undefined4 *)(param_1 + 0x1d) = (undefined4)local_38;
  *(undefined4 *)(param_1 + 0x2d) = local_40._4_4_;
  *(undefined4 *)(param_1 + 0x31) = (undefined4)local_30;
  *(undefined4 *)(param_1 + 0x35) = 0;
  if (*(int *)(param_1 + 8) == 3) {
    if (*(int *)(param_1 + 0xc) == 1) {
      *(undefined4 *)(param_1 + 0x29) = 1;
    }
    else if (param_2 == 0) {
      *(undefined4 *)(param_1 + 0x29) = 2;
    }
    else {
      *(uint *)(param_1 + 0x29) = 4 - (uint)(param_2 != *(int *)(param_1 + 0xc) - 1U);
    }
  }
  uVar1 = (*DAT_14000b478)(SpbDriverGlobals,*(undefined8 *)param_1);
  puVar2 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,uVar1,PTR__WDF_PBC_TARGET_TYPE_INFO_14000b040);
  pcVar3 = "write";
  if (*(int *)(param_1 + 0x2d) == 1) {
    pcVar3 = "read";
  }
  WPP_RECORDER_SF_sLLLq
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0xb5,
             &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,pcVar3,(char)param_2,
             (char)*(undefined4 *)(param_1 + 0x1d),(char)*(undefined2 *)((longlong)puVar2 + 9),
             (char)*puVar2);
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0xb6,
                     &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
  }
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0xb7,
                    &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,"PbcRequestConfigureForIndex");
  return 0;
}



===== PbcRequestConfigureForNonSequence @ 140006394 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl PbcRequestConfigureForNonSequence(struct WDFDEVICE__ * __ptr64,struct SPBTARGET__ *
   __ptr64,struct SPBREQUEST__ * __ptr64,unsigned __int64) */

void __cdecl
PbcRequestConfigureForNonSequence
          (WDFDEVICE__ *param_1,SPBTARGET__ *param_2,SPBREQUEST__ *param_3,__uint64 param_4)

{
  long lVar1;
  PBC_DEVICE *pPVar2;
  longlong lVar3;
  PBC_REQUEST *pPVar4;
  char *pcVar5;
  undefined1 auStackY_a8 [32];
  undefined2 local_68 [2];
  undefined4 local_64;
  undefined4 local_60;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_a8;
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0xaa,
                     &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
  }
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0xab,
                    &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,
                    "PbcRequestConfigureForNonSequence");
  pPVar2 = (PBC_DEVICE *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_14000b018);
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_PBC_TARGET_TYPE_INFO_14000b040);
  pPVar4 = (PBC_REQUEST *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_3,PTR__WDF_PBC_REQUEST_TYPE_INFO_14000b068);
  memset(local_68,0,0x20);
  local_68[0] = 0x20;
  (*DAT_14000b488)(SpbDriverGlobals,param_3,local_68);
  *(SPBREQUEST__ **)pPVar4 = param_3;
  *(undefined4 *)(pPVar4 + 8) = local_64;
  *(undefined4 *)(pPVar4 + 0x29) = local_60;
  *(undefined8 *)(pPVar4 + 0x10) = 0;
  *(undefined4 *)(pPVar4 + 0xc) = 1;
  pPVar4[0x1c] = (PBC_REQUEST)0x0;
  *(undefined2 *)(pPVar4 + 0x39) = 0;
  *(undefined4 *)(pPVar4 + 0x18) = 0;
  pPVar4[0x3b] = (PBC_REQUEST)0x0;
  lVar1 = PbcRequestValidate(pPVar4);
  if (-1 < lVar1) {
    lVar1 = PbcRequestConfigureForIndex(pPVar4,*(ulong *)(pPVar4 + 0x10));
    if (lVar1 < 0) {
      WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0xac,
                        &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,(char)lVar1);
    }
    else {
      (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(pPVar2 + 0x40));
      if (*(int *)(pPVar4 + 0x29) == 1) {
        *(longlong *)(pPVar2 + 0x28) = lVar3;
      }
      *(PBC_REQUEST **)(lVar3 + 0xf) = pPVar4;
      *(undefined4 *)(pPVar2 + 0xa0) = 0;
      if (pPVar2[0xec] == (PBC_DEVICE)0x0) {
        lVar1 = (**(code **)(WdfFunctions_01015 + 0xc48))
                          (WdfDriverGlobals,*(undefined8 *)pPVar4,OnCancel);
        if (lVar1 < 0) {
          WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0xaf,
                             &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,
                             (char)*(undefined8 *)pPVar4,(char)lVar1);
          goto LAB_1400065a4;
        }
        pcVar5 = "write";
        if (*(int *)(pPVar4 + 8) == 1) {
          pcVar5 = "read";
        }
        WPP_RECORDER_SF_sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0xb0,
                           &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,pcVar5,
                           (char)*(undefined2 *)(lVar3 + 9));
        PbcRequestDoTransfer(pPVar2,pPVar4);
      }
      else {
        lVar1 = ResetI2CController(pPVar2,pPVar4);
        if (lVar1 < 0) {
          WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0xad,
                            &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,(char)lVar1);
LAB_1400065a4:
          *(undefined8 *)(pPVar2 + 0x28) = 0;
          *(undefined8 *)(lVar3 + 0xf) = 0;
        }
        else {
          pPVar4[0x3b] = (PBC_REQUEST)0x1;
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0xae,
                           &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
        }
      }
      (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(pPVar2 + 0x40));
    }
    if (-1 < lVar1) goto LAB_1400066af;
  }
  (*DAT_14000b498)(SpbDriverGlobals,param_3,*(undefined4 *)(pPVar4 + 0x18));
LAB_1400066af:
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0xb1,
                    &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,
                    "PbcRequestConfigureForNonSequence");
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0xb2,
                     &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
  }
  return;
}



===== PbcRequestDoTransfer @ 14000672c =====

/* void __cdecl PbcRequestDoTransfer(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST * __ptr64) */

void __cdecl PbcRequestDoTransfer(PBC_DEVICE *param_1,PBC_REQUEST *param_2)

{
  char cVar1;
  
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0xb8,
                     &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
  }
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0xb9,
                    &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,"PbcRequestDoTransfer");
  if (*(int *)(param_2 + 0x31) == 0) {
    ControllerConfigureForTransfer(param_1,param_2);
  }
  else {
    WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0xba,
                      &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,
                      (char)*(int *)(param_2 + 0x31));
    cVar1 = (**(code **)(WdfFunctions_01015 + 0x9f8))
                      (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x48),
                       (ulonglong)*(uint *)(param_2 + 0x31) * -10);
    if (cVar1 == '\x01') {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0xbb,
                       &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
    }
  }
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0xbc,
                    &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,"PbcRequestDoTransfer");
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0xbd,
                     &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
  }
  return;
}



===== PbcRequestValidate @ 14000689c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl PbcRequestValidate(struct PBC_REQUEST * __ptr64) */

long __cdecl PbcRequestValidate(PBC_REQUEST *param_1)

{
  uint uVar1;
  long lVar2;
  undefined1 auStackY_88 [32];
  undefined8 local_38;
  ulonglong local_30;
  undefined8 local_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStackY_88;
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0xa5,
                     &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
  }
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0xa6,
                    &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,"PbcRequestValidate");
  lVar2 = 0;
  uVar1 = 0;
  if (*(int *)(param_1 + 0xc) != 0) {
    do {
      local_30 = 0;
      local_28 = 0;
      local_38 = 0x18;
      (*DAT_14000b490)(SpbDriverGlobals,*(undefined8 *)param_1,uVar1,&local_38);
      if (0x2000 < local_30) {
        lVar2 = -0x3ffffff3;
        WPP_RECORDER_SF_PdqLd
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0xa7,
                   &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,(char)local_30,0,
                   (char)*(undefined8 *)param_1,(char)uVar1,0xd);
        break;
      }
      uVar1 = uVar1 + 1;
    } while (uVar1 < *(uint *)(param_1 + 0xc));
  }
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0xa8,
                     &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
  }
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0xa9,
                    &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,"PbcRequestValidate");
  return lVar2;
}



===== PbcTargetGetSettings @ 140006a48 =====

/* long __cdecl PbcTargetGetSettings(struct PBC_DEVICE * __ptr64,void * __ptr64,struct
   PBC_TARGET_SETTINGS * __ptr64) */

long __cdecl PbcTargetGetSettings(PBC_DEVICE *param_1,void *param_2,PBC_TARGET_SETTINGS *param_3)

{
  int iVar1;
  uint uVar2;
  
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x9e,
                     &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
  }
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x9f,
                    &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,"PbcTargetGetSettings");
  if (*(uint *)((longlong)param_2 + 4) < 0xc) {
    uVar2 = 0xc000000d;
    WPP_RECORDER_SF_DDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,3,0xa0,
                        &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,
                        (char)*(uint *)((longlong)param_2 + 4),0xc,0xd);
  }
  else if (*(char *)((longlong)param_2 + 0xd) == '\x01') {
    WPP_RECORDER_SF_qLH(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,3,0xa2,
                        &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,(char)param_2 + '\b',
                        (char)*(undefined4 *)((longlong)param_2 + 0x14),
                        (char)*(undefined2 *)((longlong)param_2 + 0x18));
    *(undefined2 *)(param_3 + 1) = *(undefined2 *)((longlong)param_2 + 0x18);
    *param_3 = (PBC_TARGET_SETTINGS)(*(byte *)((longlong)param_2 + 0xf) & 1);
    iVar1 = *(int *)((longlong)param_2 + 0x14);
    *(int *)(param_3 + 3) = iVar1;
    if (((iVar1 == 100000) || (iVar1 == 400000)) || (iVar1 == 1000000)) {
      uVar2 = 0;
    }
    else if ((iVar1 == 1400000) || (iVar1 == 3400000)) {
      uVar2 = ~-(uint)((*(int *)(param_1 + 0xe4) - 1U & 0xfffffffd) != 0) & 0xc000000d;
    }
    else {
      uVar2 = 0xc000000d;
    }
  }
  else {
    uVar2 = 0xc000000d;
    WPP_RECORDER_SF_cd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,3,0xa1,
                       &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,
                       *(char *)((longlong)param_2 + 0xd),0xd);
  }
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0xa3,
                     &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
  }
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0xa4,
                    &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,"PbcTargetGetSettings");
  return uVar2;
}



===== ResetI2CController @ 140006c68 =====

/* long __cdecl ResetI2CController(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST * __ptr64) */

long __cdecl ResetI2CController(PBC_DEVICE *param_1,PBC_REQUEST *param_2)

{
  long lVar1;
  
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,100,
                    &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,"ResetI2CController");
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0x65,
                     &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
  }
  lVar1 = SendDownResetIrp(param_1,'\0','\x01');
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0x68,
                     &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids);
  }
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x69,
                    &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,"ResetI2CController");
  return lVar1;
}



===== ResetIrpIoCompletion @ 140006d48 =====

/* long __cdecl ResetIrpIoCompletion(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64,void *
   __ptr64) */

long __cdecl ResetIrpIoCompletion(_DEVICE_OBJECT *param_1,_IRP *param_2,void *param_3)

{
  longlong lVar1;
  bool bVar2;
  int iVar3;
  PBC_REQUEST *pPVar4;
  
  pPVar4 = (PBC_REQUEST *)0x0;
  bVar2 = false;
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x5b,
                    &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,"ResetIrpIoCompletion");
  if (param_3 != (void *)0x0) {
    *(undefined2 *)((longlong)param_3 + 0xec) = 0;
    iVar3 = 0x32;
    do {
      KeStallExecutionProcessor(100);
      iVar3 = iVar3 + -1;
      if (*(int *)(*(longlong *)((longlong)param_3 + 0x20) + 0x14) !=
          *(int *)((longlong)param_3 + 0xa8)) break;
    } while (iVar3 != 0);
    (**(code **)(WdfFunctions_01015 + 0x9e0))
              (WdfDriverGlobals,*(undefined8 *)((longlong)param_3 + 0x40));
    ControllerInitialize(param_3);
    ControllerDisableController(param_3);
    *(undefined4 *)(*(longlong *)((longlong)param_3 + 0x20) + 8) = 1;
    LOCK();
    UNLOCK();
    ControllerEnableController(param_3,1);
    lVar1 = *(longlong *)((longlong)param_3 + 0x28);
    if ((lVar1 != 0) && (pPVar4 = *(PBC_REQUEST **)(lVar1 + 0xf), pPVar4 != (PBC_REQUEST *)0x0)) {
      iVar3 = (**(code **)(WdfFunctions_01015 + 0xc48))
                        (WdfDriverGlobals,*(undefined8 *)pPVar4,OnCancel);
      if (iVar3 < 0) {
        WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x5c,
                           &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,
                           (char)*(undefined8 *)pPVar4,(char)iVar3);
        *(undefined8 *)(lVar1 + 0xf) = 0;
        bVar2 = true;
        *(undefined8 *)((longlong)param_3 + 0x28) = 0;
      }
      else {
        WPP_RECORDER_SF_sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x5d,
                           &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,"ResetIrpIoCompletion",1
                          );
        PbcRequestDoTransfer(param_3,pPVar4);
      }
    }
    (**(code **)(WdfFunctions_01015 + 0x9e8))
              (WdfDriverGlobals,*(undefined8 *)((longlong)param_3 + 0x40));
    if (bVar2) {
      (*DAT_14000b498)(SpbDriverGlobals,*(undefined8 *)pPVar4,*(undefined4 *)(pPVar4 + 0x18));
    }
  }
  IoFreeIrp(param_2);
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x5e,
                    &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,"ResetIrpIoCompletion");
  return -0x3fffffea;
}



===== SendDownResetIrp @ 140006f58 =====

/* long __cdecl SendDownResetIrp(struct PBC_DEVICE * __ptr64,unsigned char,unsigned char) */

long __cdecl SendDownResetIrp(PBC_DEVICE *param_1,uchar param_2,uchar param_3)

{
  undefined8 *puVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  undefined2 uVar5;
  char in_CR8;
  undefined4 uVar6;
  uint uVar7;
  undefined1 local_38 [32];
  
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x5f,
                    &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,"SendDownResetIrp");
  if ((param_2 == '\0') && (in_CR8 != '\0')) {
    puVar1 = *(undefined8 **)(param_1 + 100);
    *puVar1 = 0;
    puVar1[1] = 0;
    *(undefined4 *)(puVar1 + 2) = 0;
    *(undefined4 *)puVar1 = 0x42696541;
    *(undefined4 *)((longlong)puVar1 + 4) = 0x54455352;
    lVar3 = IoAllocateIrp(*(undefined1 *)(*(longlong *)(param_1 + 8) + 0x4c),0);
    *(undefined1 *)(lVar3 + 0x40) = 0;
    *(undefined4 *)(lVar3 + 0x30) = 0xc00000bb;
    *(undefined8 *)(lVar3 + 0x38) = 0;
    *(undefined8 *)(lVar3 + 0x18) = *(undefined8 *)(param_1 + 100);
    lVar4 = *(longlong *)(lVar3 + 0xb8);
    *(undefined1 *)(lVar4 + -0x48) = 0xe;
    *(undefined4 *)(lVar4 + -0x30) = 0x32c000;
    *(undefined4 *)(lVar4 + -0x38) = 8;
    *(undefined4 *)(lVar4 + -0x40) = 0x14;
    lVar4 = *(longlong *)(lVar3 + 0xb8);
    *(code **)(lVar4 + -0x10) = ResetIrpIoCompletion;
    *(PBC_DEVICE **)(lVar4 + -8) = param_1;
    *(undefined1 *)(lVar4 + -0x45) = 0xe0;
    iVar2 = IofCallDriver(*(undefined8 *)(param_1 + 8),lVar3);
    if (iVar2 == 0x103) {
      iVar2 = 0;
    }
    uVar5 = 99;
  }
  else {
    uVar7 = 0x6cc;
    uVar6 = 1;
    WPP_RECORDER_SF_sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x60,
                       &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,"SendDownResetIrp",0xcc);
    KeInitializeEvent(local_38,1,0);
    lVar4 = IoBuildDeviceIoControlRequest
                      (0x32c004,*(undefined8 *)(param_1 + 8),*(undefined8 *)(param_1 + 0x6c),8,
                       *(undefined8 *)(param_1 + 100),CONCAT44(uVar6,0x14),uVar7 & 0xffffff00,
                       local_38,*(undefined8 *)(param_1 + 0x74));
    if (lVar4 == 0) {
      WPP_RECORDER_SF_sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x61,
                         &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,"SendDownResetIrp",0xe4);
      return -0x3fffff66;
    }
    iVar2 = IofCallDriver(*(undefined8 *)(param_1 + 8),lVar4);
    if (iVar2 == 0x103) {
      KeWaitForSingleObject(local_38,0,0,0,0);
      iVar2 = **(int **)(param_1 + 0x74);
    }
    if (param_3 != '\0') {
      ControllerInitialize(param_1);
    }
    uVar5 = 0x62;
  }
  WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,uVar5,
                    &WPP_92e1792a37953faf1ee134440f5d84fc_Traceguids,"SendDownResetIrp");
  return iVar2;
}



===== WPP_RECORDER_SF_DDD @ 1400071a4 =====

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



===== WPP_RECORDER_SF_PdqLd @ 1400072dc =====

void WPP_RECORDER_SF_PdqLd
               (undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,undefined8 param_5,
               undefined1 param_6,undefined1 param_7,undefined1 param_8,undefined1 param_9,
               undefined1 param_10)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,8,&param_7,4,&param_8,8,&param_9,4,&param_10,4,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,&param_6,8,&param_7,4,&param_8,8,&param_9,
                  4,&param_10,4,0);
  return;
}



===== WPP_RECORDER_SF_cd @ 140007474 =====

void WPP_RECORDER_SF_cd(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
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
               &param_6,1,&param_7,4,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,&param_6,1,&param_7,4,0);
  return;
}



===== WPP_RECORDER_SF_qLH @ 140007590 =====

void WPP_RECORDER_SF_qLH(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
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
               &param_6,8,&param_7,4,&param_8,2,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,&param_6,8,&param_7,4,&param_8,2,0);
  return;
}



===== WPP_RECORDER_SF_qLq @ 1400076d8 =====

void WPP_RECORDER_SF_qLq(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
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
               &param_6,8,&param_7,4,&param_8,8,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,&param_6,8,&param_7,4,&param_8,8,0);
  return;
}



===== WPP_RECORDER_SF_sLLLq @ 140007818 =====

void WPP_RECORDER_SF_sLLLq
               (undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,undefined8 param_5,
               char *param_6,undefined1 param_7,undefined1 param_8,undefined1 param_9,
               undefined1 param_10)

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
    pcVar1 = "NULL";
    if (param_6 != (char *)0x0) {
      pcVar1 = param_6;
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar4 * 0x50 + 0x18),0x2b,param_5,param_4,pcVar1
               ,lVar3,&param_7,4,&param_8,4,&param_9,4,&param_10,8,0);
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
  pcVar1 = "NULL";
  if (param_6 != (char *)0x0) {
    pcVar1 = param_6;
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,pcVar1,lVar2,&param_7,4,&param_8,4,
                  &param_9,4,&param_10,8,0);
  return;
}



===== WPP_RECORDER_SF_sLd @ 140007a0c =====

void WPP_RECORDER_SF_sLd(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
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
    pcVar1 = "NULL";
    if (param_6 != (char *)0x0) {
      pcVar1 = param_6;
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar4 * 0x50 + 0x18),0x2b,param_5,param_4,pcVar1
               ,lVar3,&param_7,4,&param_8,4,0);
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
  pcVar1 = "NULL";
  if (param_6 != (char *)0x0) {
    pcVar1 = param_6;
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,pcVar1,lVar2,&param_7,4,&param_8,4,0);
  return;
}



===== WPP_RECORDER_SF_xq @ 140007ba8 =====

void WPP_RECORDER_SF_xq(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
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



===== OnDeviceAdd @ 140007cbc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl OnDeviceAdd(struct WDFDRIVER__ * __ptr64,struct WDFDEVICE_INIT * __ptr64) */

long __cdecl OnDeviceAdd(WDFDRIVER__ *param_1,WDFDEVICE_INIT *param_2)

{
  int iVar1;
  longlong lVar2;
  undefined8 *puVar3;
  undefined2 uVar4;
  undefined1 auStackY_1c8 [32];
  code *local_188;
  WDFDEVICE_INIT *local_180;
  undefined4 local_178;
  undefined4 local_174;
  code *local_170;
  code *local_168;
  code *local_160;
  code *local_158;
  code *local_150;
  code *local_148;
  code *local_140;
  code *local_138;
  code *local_130;
  undefined4 local_11c;
  code *local_e8;
  undefined4 local_e0 [6];
  undefined4 local_c8;
  undefined4 local_c4;
  undefined *local_b0;
  undefined4 local_a8 [6];
  undefined4 local_90;
  undefined4 local_8c;
  code *local_88;
  undefined8 local_70;
  undefined4 local_68;
  undefined4 uStack_64;
  undefined4 local_60;
  undefined4 uStack_5c;
  undefined4 local_58;
  undefined4 local_54;
  code *local_50;
  undefined *local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_1c8;
  local_180 = param_2;
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0xe,
                     &WPP_809d1502360037038a691e569ce09a3d_Traceguids);
  }
  iVar1 = (*SpbFunctions)(SpbDriverGlobals);
  if (iVar1 < 0) {
    uVar4 = 0xf;
  }
  else {
    memset(&local_178,0,0x90);
    local_150 = OnPrepareHardware;
    local_148 = OnReleaseHardware;
    local_170 = OnD0Entry;
    local_160 = OnD0Exit;
    local_130 = OnSelfManagedIoInit;
    local_140 = OnSelfManagedIoCleanup;
    local_168 = OnDeviceD0EntryPostInterruptsEnabled;
    local_158 = OnDeviceD0ExitPreInterruptsDisabled;
    local_178 = 0x90;
    (**(code **)(WdfFunctions_01015 + 0x1b8))(WdfDriverGlobals,local_180,&local_178);
    (**(code **)(WdfFunctions_01015 + 0x230))(WdfDriverGlobals,local_180,0x80,1);
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x220))
                      (WdfDriverGlobals,local_180,&g_SddlLocalService);
    if (iVar1 < 0) {
      uVar4 = 0x10;
    }
    else {
      lVar2 = (**(code **)(WdfFunctions_01015 + 0x3e0))(WdfDriverGlobals);
      if (lVar2 == 0) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x11,
                         &WPP_809d1502360037038a691e569ce09a3d_Traceguids);
        goto LAB_1400082e3;
      }
      memset(local_e0,0,0x38);
      local_b0 = PTR__WDF_PBC_DEVICE_TYPE_INFO_14000b018;
      local_e0[0] = 0x38;
      local_c8 = 1;
      local_c4 = 1;
      iVar1 = (**(code **)(WdfFunctions_01015 + 600))
                        (WdfDriverGlobals,&local_180,local_e0,&local_188);
      if (iVar1 < 0) {
        uVar4 = 0x12;
      }
      else {
        puVar3 = (undefined8 *)
                 (**(code **)(WdfFunctions_01015 + 0x650))
                           (WdfDriverGlobals,local_188,PTR__WDF_PBC_DEVICE_TYPE_INFO_14000b018);
        puVar3[1] = lVar2;
        *puVar3 = local_188;
        *(undefined1 *)((longlong)puVar3 + 0xea) = 1;
        uStack_5c = 2;
        local_70 = 0x20000001c;
        local_68 = 2;
        uStack_64 = 2;
        local_60 = 0;
        local_58 = 2;
        (**(code **)(WdfFunctions_01015 + 0xe8))(WdfDriverGlobals,local_188,&local_70);
        memset(&local_178,0,0x48);
        local_168 = OnTargetConnect;
        local_148 = OnRead;
        local_140 = OnWrite;
        local_138 = OnSequence;
        local_158 = OnControllerLock;
        local_150 = OnControllerUnlock;
        local_178 = 0x48;
        local_174 = 1;
        local_170 = (code *)CONCAT44(local_170._4_4_,1);
        iVar1 = (*DAT_14000b448)(SpbDriverGlobals,local_188,&local_178);
        if (iVar1 < 0) {
          uVar4 = 0x13;
        }
        else {
          (*DAT_14000b450)(SpbDriverGlobals,*puVar3,OnOther,OnOtherInCallerContext);
          memset(&local_70,0,0x38);
          local_40 = PTR__WDF_PBC_TARGET_TYPE_INFO_14000b040;
          local_70._0_4_ = 0x38;
          local_58 = 1;
          local_54 = 1;
          (*DAT_14000b460)(SpbDriverGlobals,local_188,&local_70);
          memset(&local_70,0,0x38);
          local_40 = PTR__WDF_PBC_REQUEST_TYPE_INFO_14000b068;
          local_70._0_4_ = 0x38;
          local_58 = 1;
          local_54 = 1;
          (*DAT_14000b458)(SpbDriverGlobals,local_188,&local_70);
          memset(&local_70,0,0x38);
          local_50 = local_188;
          local_70 = CONCAT44(local_70._4_4_,0x38);
          local_58 = 1;
          local_54 = 1;
          iVar1 = (**(code **)(WdfFunctions_01015 + 0x9d8))(WdfDriverGlobals,&local_70,&local_e8);
          if (iVar1 < 0) {
            uVar4 = 0x14;
          }
          else {
            memset(&local_178,0,0x68);
            local_178 = 0x68;
            local_160 = OnInterruptIsr;
            local_158 = OnInterruptDpc;
            local_170 = local_e8;
            local_150 = OnInterruptEnable;
            local_148 = OnInterruptDisable;
            local_168 = (code *)CONCAT44(local_168._4_4_,2);
            local_11c = 2;
            if ((*(char *)((longlong)puVar3 + 0xea) == '\0') ||
               (iVar1 = (**(code **)(WdfFunctions_01015 + 0x468))
                                  (WdfDriverGlobals,*puVar3,&local_178,0), -1 < iVar1)) {
              memset(&local_70,0,0x28);
              local_70 = CONCAT44(local_70._4_4_,0x28);
              local_68 = 0x40004128;
              uStack_64 = 1;
              local_60 = 0;
              uStack_5c = CONCAT31(uStack_5c._1_3_,1);
              local_58 = 0;
              memset(&local_178,0,0x38);
              local_158 = local_188;
              local_178 = 0x38;
              local_160 = (code *)0x100000001;
              iVar1 = (**(code **)(WdfFunctions_01015 + 0x9f0))
                                (WdfDriverGlobals,&local_70,&local_178,puVar3 + 9);
              if (iVar1 < 0) {
                uVar4 = 0x16;
              }
              else {
                memset(local_a8,0,0x38);
                local_88 = local_188;
                local_a8[0] = 0x38;
                local_90 = 1;
                local_8c = 1;
                iVar1 = (**(code **)(WdfFunctions_01015 + 0x9d8))
                                  (WdfDriverGlobals,local_a8,puVar3 + 8);
                if (-1 < iVar1) {
                  memset(&local_70,0,0x24);
                  local_60 = 2;
                  uStack_5c = 2;
                  local_58 = 2;
                  local_50 = (code *)CONCAT44(local_50._4_4_,2);
                  local_70 = 0x100000024;
                  local_54 = 2;
                  uStack_64 = 4000;
                  local_68 = 4;
                  iVar1 = (**(code **)(WdfFunctions_01015 + 0x170))
                                    (WdfDriverGlobals,*puVar3,&local_70);
                  if (iVar1 < 0) {
                    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x18,
                                       &WPP_809d1502360037038a691e569ce09a3d_Traceguids,
                                       (char)*puVar3,(char)iVar1);
                  }
                  goto LAB_1400082e3;
                }
                uVar4 = 0x17;
              }
            }
            else {
              uVar4 = 0x15;
            }
          }
        }
      }
    }
  }
  WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,uVar4,
                    &WPP_809d1502360037038a691e569ce09a3d_Traceguids,(char)iVar1);
LAB_1400082e3:
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x19,
                     &WPP_809d1502360037038a691e569ce09a3d_Traceguids);
  }
  return iVar1;
}



===== OnDriverUnload @ 14000833c =====

/* void __cdecl OnDriverUnload(struct WDFDRIVER__ * __ptr64) */

void __cdecl OnDriverUnload(WDFDRIVER__ *param_1)

{
  WppCleanupKm(param_1);
  return;
}



===== DriverEntry @ 140008344 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined1 local_res18 [8];
  undefined4 local_78 [2];
  code *local_70;
  code *local_68;
  undefined4 local_5c;
  undefined4 local_58 [6];
  undefined4 local_40;
  undefined4 local_3c;
  
  _WPP_MAIN_CB = 0;
  DAT_14000b198 = &WPP_ThisDir_CTLGUID_PbcTraceGuid;
  DAT_14000b1a0 = 0;
  _DAT_14000b1b0 = 0;
  _DAT_14000b1b8 = 1;
  _DAT_14000b1d0 = 0;
  _DAT_14000b1d8 = 0;
  WppLoadTracingSupport();
  _DAT_14000b1b0 = 0;
  WppInitKm(param_1,param_2);
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,10,
                     &WPP_809d1502360037038a691e569ce09a3d_Traceguids);
  }
  memset(local_78,0,0x20);
  local_78[0] = 0x20;
  local_5c = 0x43324953;
  local_70 = OnDeviceAdd;
  local_68 = OnDriverUnload;
  memset(local_58,0,0x38);
  local_58[0] = 0x38;
  local_40 = 1;
  local_3c = 1;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x3a0))
                    (WdfDriverGlobals,param_1,param_2,local_58,local_78,local_res18);
  if (iVar1 < 0) {
    WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0xb,
                      &WPP_809d1502360037038a691e569ce09a3d_Traceguids,(char)iVar1);
  }
  else {
    if (*(short *)(WPP_GLOBAL_Control + 0x48) == 0) goto LAB_1400084e6;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0xc,
                     &WPP_809d1502360037038a691e569ce09a3d_Traceguids);
  }
  if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0xd,
                     &WPP_809d1502360037038a691e569ce09a3d_Traceguids);
  }
LAB_1400084e6:
  if (iVar1 < 0) {
    WppCleanupKm(0);
  }
  return iVar1;
}



===== __security_check_cookie @ 140008570 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  if ((_StackCookie == __security_cookie) && ((short)(_StackCookie >> 0x30) == 0)) {
    return;
  }
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== wcsncmp @ 140008598 =====

int __cdecl wcsncmp(wchar_t *_Str1,wchar_t *_Str2,size_t _MaxCount)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000140008598. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = wcsncmp(_Str1,_Str2,_MaxCount);
  return iVar1;
}



===== __GSHandlerCheck @ 1400085a0 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1400085c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

longlong __GSHandlerCheckCommon(undefined8 param_1,longlong param_2)

{
  byte bVar1;
  longlong lVar2;
  
  bVar1 = *(byte *)((ulonglong)*(uint *)(*(longlong *)(param_2 + 0x10) + 8) +
                    *(longlong *)(param_2 + 8) + 3);
  lVar2 = CONCAT71((int7)((ulonglong)*(longlong *)(param_2 + 0x10) >> 8),bVar1);
  if ((bVar1 & 0xf) != 0) {
    lVar2 = (longlong)(int)(bVar1 & 0xfffffff0);
  }
  return lVar2;
}



===== FxStubDriverUnloadCommon @ 140008620 =====

/* void __cdecl FxStubDriverUnloadCommon(void) */

void __cdecl FxStubDriverUnloadCommon(void)

{
  FxStubUnbindClasses((_WDF_BIND_INFO *)&DAT_14000b0a0);
  WdfVersionUnbind(&DAT_14000b1e8,&DAT_14000b0a0,WdfDriverGlobals);
  return;
}



===== entry @ 140008650 =====

void entry(longlong param_1,undefined8 param_2)

{
  __security_init_cookie();
  FxDriverEntryWorker(param_1,param_2);
  return;
}



===== FxDriverEntryWorker @ 14000867c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FxDriverEntryWorker(longlong param_1,undefined8 param_2)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = DriverEntry(0,param_2);
  }
  else {
    _DAT_14000b1f0 = &DAT_14000b220;
    _DAT_14000b1e8 = 0x2080000;
    _DAT_14000b210 = param_1;
    RtlCopyUnicodeString(&DAT_14000b1e8);
    iVar1 = WdfVersionBind(param_1,&DAT_14000b1e8,&DAT_14000b0a0,&WdfDriverGlobals);
    if (-1 < iVar1) {
      _WdfDriverMiniportUnloadOverride = *(undefined1 **)(WdfFunctions_01015 + 0x648);
      iVar1 = FxStubBindClasses((_WDF_BIND_INFO *)&DAT_14000b0a0);
      if (((-1 < iVar1) && (iVar1 = FxStubInitTypes(), -1 < iVar1)) &&
         (iVar1 = DriverEntry(param_1,param_2), -1 < iVar1)) {
        if (*(char *)(WdfDriverGlobals + 0x30) == '\0') {
          if ((*(uint *)(WdfDriverGlobals + 8) & 2) != 0) {
            _WdfDriverMiniportUnloadOverride = &FxStubDriverMiniportUnload;
          }
        }
        else {
          if (*(longlong *)(param_1 + 0x68) != 0) {
            DAT_14000b1f8 = *(longlong *)(param_1 + 0x68);
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



===== FxStubDriverUnload @ 1400087ac =====

void FxStubDriverUnload(void)

{
  if ((DAT_14000b1f8 != (code *)0x0) && (DAT_14000b1f8 != FxStubDriverUnload)) {
    (*DAT_14000b1f8)();
  }
  FxStubDriverUnloadCommon();
  return;
}



===== FxStubInitTypes @ 1400087d4 =====

/* WARNING: Removing unreachable block (ram,0x000140008804) */
/* WARNING: Removing unreachable block (ram,0x00014000880b) */
/* WARNING: Removing unreachable block (ram,0x000140008839) */
/* WARNING: Removing unreachable block (ram,0x000140008811) */
/* WARNING: Removing unreachable block (ram,0x000140008819) */
/* WARNING: Removing unreachable block (ram,0x00014000881f) */
/* WARNING: Removing unreachable block (ram,0x0001400087f1) */
/* long __cdecl FxStubInitTypes(void) */

long __cdecl FxStubInitTypes(void)

{
  return 0;
}



===== FxStubBindClasses @ 140008840 =====

/* WARNING: Removing unreachable block (ram,0x000140008867) */
/* long __cdecl FxStubBindClasses(struct _WDF_BIND_INFO * __ptr64) */

long __cdecl FxStubBindClasses(_WDF_BIND_INFO *param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = &_SPBCx_BIND_INFO;
  while( true ) {
    if ((int *)0x14000b12f < piVar2) {
      return iVar1;
    }
    if (*piVar2 != 0x50) break;
    PTR___KMDF_CLASS_BIND_START_14000b138 = (undefined *)piVar2;
    if (*(code **)(piVar2 + 0xe) == (code *)0x0) {
      iVar1 = WdfVersionBindClass(param_1,WdfDriverGlobals,piVar2);
    }
    else {
      iVar1 = (**(code **)(piVar2 + 0xe))(WdfVersionBindClass,param_1,WdfDriverGlobals,piVar2);
    }
    if (iVar1 < 0) {
      return iVar1;
    }
    piVar2 = piVar2 + 0x14;
  }
  return -0x3ffffffc;
}



===== FxStubUnbindClasses @ 1400088d8 =====

/* void __cdecl FxStubUnbindClasses(struct _WDF_BIND_INFO * __ptr64) */

void __cdecl FxStubUnbindClasses(_WDF_BIND_INFO *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = &_SPBCx_BIND_INFO;
  if (((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_14000b138 != &__KMDF_CLASS_BIND_START) &&
     ((undefined *)0x14000b0df < PTR___KMDF_CLASS_BIND_START_14000b138)) {
    do {
      if (*(code **)(puVar1 + 0x10) == (code *)0x0) {
        WdfVersionUnbindClass(param_1,WdfDriverGlobals,puVar1);
      }
      else {
        (**(code **)(puVar1 + 0x10))(WdfVersionUnbindClass,param_1,WdfDriverGlobals,puVar1);
      }
      puVar1 = puVar1 + 0x14;
    } while (puVar1 <= PTR___KMDF_CLASS_BIND_START_14000b138);
  }
  return;
}



===== WppAutoLogTrace @ 140008950 =====

void WppAutoLogTrace(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140008950. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WppAutoLogTrace();
  return;
}



===== WppAutoLogStart @ 140008956 =====

void WppAutoLogStart(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140008956. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WppAutoLogStart();
  return;
}



===== WppAutoLogStop @ 14000895c =====

void WppAutoLogStop(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000895c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WppAutoLogStop();
  return;
}



===== WdfVersionBind @ 140008968 =====

void WdfVersionBind(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140008968. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WdfVersionBind();
  return;
}



===== WdfVersionUnbind @ 14000896e =====

void WdfVersionUnbind(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000896e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WdfVersionUnbind();
  return;
}



===== WdfVersionBindClass @ 140008974 =====

void WdfVersionBindClass(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140008974. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WdfVersionBindClass();
  return;
}



===== WdfVersionUnbindClass @ 14000897a =====

void WdfVersionUnbindClass(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000897a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WdfVersionUnbindClass();
  return;
}



===== _guard_check_icall @ 140008980 =====

void _guard_check_icall(void)

{
  return;
}



===== _guard_dispatch_icall @ 1400089a0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001400089a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== memset @ 1400089c0 =====

void * __cdecl memset(void *_Dst,int _Val,size_t _Size)

{
  uint uVar1;
  void *pvVar2;
  ulonglong *puVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  
  uVar4 = (ulonglong)(uint)_Val;
  pvVar2 = _Dst;
  if (7 < _Size) {
    uVar4 = (ulonglong)(byte)_Val * 0x101010101010101;
    if (0x46 < _Size) {
      uVar1 = -(int)_Dst & 7;
      if (uVar1 != 0) {
        _Size = _Size - uVar1;
        *(ulonglong *)_Dst = uVar4;
      }
      puVar3 = (ulonglong *)((ulonglong)uVar1 + (longlong)_Dst);
      uVar6 = _Size >> 6;
      uVar5 = _Size >> 3 & 7;
      if (uVar5 == 0) goto LAB_140008a80;
      puVar3 = puVar3 + (uVar5 - 8);
      uVar6 = uVar6 + 1;
      switch(uVar5) {
      case 2:
        goto switchD_140008a7d_caseD_2;
      case 3:
        goto switchD_140008a7d_caseD_3;
      case 4:
        goto switchD_140008a7d_caseD_4;
      case 5:
        goto switchD_140008a7d_caseD_5;
      case 6:
        goto switchD_140008a7d_caseD_6;
      case 7:
        goto switchD_140008a7d_caseD_7;
      }
      while( true ) {
        puVar3[7] = uVar4;
        puVar3 = puVar3 + 8;
        uVar6 = uVar6 - 1;
        if (uVar6 == 0) break;
LAB_140008a80:
        *puVar3 = uVar4;
switchD_140008a7d_caseD_7:
        puVar3[1] = uVar4;
switchD_140008a7d_caseD_6:
        puVar3[2] = uVar4;
switchD_140008a7d_caseD_5:
        puVar3[3] = uVar4;
switchD_140008a7d_caseD_4:
        puVar3[4] = uVar4;
switchD_140008a7d_caseD_3:
        puVar3[5] = uVar4;
switchD_140008a7d_caseD_2:
        puVar3[6] = uVar4;
      }
      for (uVar5 = _Size & 7; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(char *)((uVar5 - 1) + (longlong)puVar3) = (char)uVar4;
      }
      return _Dst;
    }
    uVar5 = _Size & 0xfffffffffffffff8;
    pvVar2 = (void *)((longlong)_Dst + uVar5);
    do {
      *(ulonglong *)((uVar5 - 8) + (longlong)_Dst) = uVar4;
      uVar5 = uVar5 - 8;
    } while (uVar5 != 0);
  }
  for (uVar5 = _Size & 7; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(char *)((uVar5 - 1) + (longlong)pvVar2) = (char)uVar4;
  }
  return _Dst;
}



===== memmove @ 140008ac0 =====

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
          puVar10 = (undefined8 *)((uVar11 - 0x10) + (longlong)puVar9);
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
          *(undefined1 *)puVar9 = *(undefined1 *)(uVar11 + (longlong)puVar9);
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
            puVar9 = (undefined8 *)((uVar11 - 0x10) + (longlong)puVar10);
            uVar4 = puVar9[1];
            puVar1 = (undefined8 *)((uVar11 - 0x20) + (longlong)puVar10);
            uVar5 = *puVar1;
            uVar6 = puVar1[1];
            puVar10[-2] = *puVar9;
            puVar10[-1] = uVar4;
            puVar10[-4] = uVar5;
            puVar10[-3] = uVar6;
            puVar9 = puVar10 + -8;
            puVar1 = (undefined8 *)(uVar11 + 0x10 + (longlong)puVar9);
            uVar4 = puVar1[1];
            uVar5 = *(undefined8 *)(uVar11 + (longlong)puVar9);
            uVar6 = ((undefined8 *)(uVar11 + (longlong)puVar9))[1];
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
        if (uVar12 == 0) goto LAB_140008c77;
      }
      _Size = _Size & 0x1f;
      puVar10 = puVar9;
      do {
        puVar1 = (undefined8 *)((uVar11 - 0x10) + (longlong)puVar10);
        uVar4 = puVar1[1];
        puVar9 = (undefined8 *)((uVar11 - 0x20) + (longlong)puVar10);
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
LAB_140008c77:
    for (uVar12 = _Size >> 3; uVar12 != 0; uVar12 = uVar12 - 1) {
      puVar10 = (undefined8 *)((uVar11 - 8) + (longlong)puVar9);
      puVar9 = puVar9 + -1;
      *puVar9 = *puVar10;
    }
    for (uVar12 = _Size & 7; uVar12 != 0; uVar12 = uVar12 - 1) {
      puVar3 = (undefined1 *)((uVar11 - 1) + (longlong)puVar9);
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
        *(undefined1 *)puVar9 = *(undefined1 *)(uVar11 + (longlong)puVar9);
      }
    }
    else {
      uVar8 = -(int)_Dst & 0xf;
      if (uVar8 != 0) {
        _Size = _Size - uVar8;
        uVar4 = ((undefined8 *)(uVar11 + (longlong)_Dst))[1];
        *(undefined8 *)_Dst = *(undefined8 *)(uVar11 + (longlong)_Dst);
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
          uVar4 = ((undefined8 *)(uVar11 + (longlong)puVar10))[1];
          puVar9 = (undefined8 *)(uVar11 + 0x10 + (longlong)puVar10);
          uVar5 = *puVar9;
          uVar6 = puVar9[1];
          *puVar10 = *(undefined8 *)(uVar11 + (longlong)puVar10);
          puVar10[1] = uVar4;
          puVar10[2] = uVar5;
          puVar10[3] = uVar6;
          puVar9 = puVar10 + 8;
          puVar1 = (undefined8 *)((uVar11 - 0x20) + (longlong)puVar9);
          uVar4 = puVar1[1];
          puVar2 = (undefined8 *)((uVar11 - 0x10) + (longlong)puVar9);
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
      if (uVar12 == 0) goto LAB_140008ad2;
    }
    _Size = _Size & 0x1f;
    puVar10 = puVar9;
    do {
      uVar4 = ((undefined8 *)(uVar11 + (longlong)puVar10))[1];
      puVar9 = (undefined8 *)(uVar11 + 0x10 + (longlong)puVar10);
      uVar5 = *puVar9;
      uVar6 = puVar9[1];
      puVar9 = puVar10 + 4;
      *puVar10 = *(undefined8 *)(uVar11 + (longlong)puVar10);
      puVar10[1] = uVar4;
      puVar10[2] = uVar5;
      puVar10[3] = uVar6;
      uVar12 = uVar12 - 1;
      puVar10 = puVar9;
    } while (uVar12 != 0);
  }
LAB_140008ad2:
  for (uVar12 = _Size >> 3; uVar12 != 0; uVar12 = uVar12 - 1) {
    *puVar9 = *(undefined8 *)(uVar11 + (longlong)puVar9);
    puVar9 = puVar9 + 1;
  }
  for (uVar12 = _Size & 7; uVar12 != 0; uVar12 = uVar12 - 1) {
    *(undefined1 *)puVar9 = *(undefined1 *)(uVar11 + (longlong)puVar9);
    puVar9 = (undefined8 *)((longlong)puVar9 + 1);
  }
  return _Dst;
}



===== WppCleanupKm @ 14000e000 =====

void WppCleanupKm(undefined8 param_1)

{
  undefined *puVar1;
  
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    puVar1 = WPP_GLOBAL_Control;
    if (WPPTraceSuite == 4) {
      for (; puVar1 != (undefined *)0x0; puVar1 = *(undefined **)(puVar1 + 0x10)) {
        if (*(longlong *)(puVar1 + 0x38) != 0) {
          (*pfnEtwUnregister)();
        }
      }
    }
    else if (WPPTraceSuite == 2) {
      IoWMIRegistrationControl(WPP_GLOBAL_Control,0x80000002);
    }
    WppAutoLogStop(WPP_GLOBAL_Control,param_1);
    WPP_GLOBAL_Control = (undefined *)&WPP_GLOBAL_Control;
  }
  return;
}



===== WppInitKm @ 14000e08c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void WppInitKm(undefined8 param_1,undefined8 param_2)

{
  undefined *puVar1;
  
  puVar1 = &WPP_MAIN_CB;
  if (WPP_GLOBAL_Control != &WPP_MAIN_CB) {
    WPP_GLOBAL_Control = &WPP_MAIN_CB;
    if (WPPTraceSuite == 4) {
      do {
        *(undefined8 *)(puVar1 + 0x38) = 0;
        (*_pfnEtwRegisterClassicProvider)
                  (*(undefined8 *)(puVar1 + 8),0,&WppClassicProviderCallback,puVar1,puVar1 + 0x38);
        puVar1 = *(undefined **)(puVar1 + 0x10);
      } while (puVar1 != (undefined *)0x0);
    }
    else if (WPPTraceSuite == 2) {
      _WPP_MAIN_CB = WppTraceCallback;
      IoWMIRegistrationControl(&WPP_MAIN_CB,0x80010001);
    }
    WppAutoLogStart(WPP_GLOBAL_Control,param_1,param_2);
  }
  return;
}



===== WppLoadTracingSupport @ 14000e134 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void WppLoadTracingSupport(void)

{
  uint local_res8 [8];
  undefined1 local_18 [16];
  
  local_res8[0] = 0;
  RtlInitUnicodeString(local_18,L"PsGetVersion");
  pfnWppGetVersion = (code *)MmGetSystemRoutineAddress(local_18);
  RtlInitUnicodeString(local_18,L"WmiTraceMessage");
  pfnWppTraceMessage = MmGetSystemRoutineAddress(local_18);
  RtlInitUnicodeString(local_18,L"WmiQueryTraceInformation");
  pfnWppQueryTraceInformation = MmGetSystemRoutineAddress(local_18);
  WPPTraceSuite = 2;
  if (pfnWppGetVersion != (code *)0x0) {
    (*pfnWppGetVersion)(local_res8,0,0,0);
  }
  if (5 < local_res8[0]) {
    RtlInitUnicodeString(local_18,L"EtwRegisterClassicProvider");
    _pfnEtwRegisterClassicProvider = MmGetSystemRoutineAddress(local_18);
    if (_pfnEtwRegisterClassicProvider != 0) {
      RtlInitUnicodeString(local_18,L"EtwUnregister");
      pfnEtwUnregister = MmGetSystemRoutineAddress(local_18);
      WPPTraceSuite = 4;
    }
  }
  return;
}



===== WppTraceCallback @ 14000e22c =====

undefined4
WppTraceCallback(byte param_1,undefined8 param_2,uint param_3,uint *param_4,longlong param_5,
                uint *param_6)

{
  ushort *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  uint *puVar4;
  int iVar5;
  undefined4 uVar6;
  longlong lVar7;
  ulonglong uVar8;
  uint uVar9;
  uint uVar10;
  uint *puVar11;
  uint uVar12;
  undefined1 local_res8 [8];
  undefined1 uStack_36;
  undefined4 uStack_34;
  
  puVar4 = param_6;
  *param_6 = 0;
  if (3 < param_1) {
    if (param_1 < 6) {
      if (param_5 != 0) {
        if (param_3 < 0x30) {
          return 0xc000000d;
        }
        do {
          lVar7 = RtlCompareMemory(*(undefined8 *)(param_5 + 8),param_4 + 6,0x10);
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
          if (WPPTraceSuite != 2) {
            uStack_34 = (undefined4)((ulonglong)uVar2 >> 0x20);
            *(undefined4 *)(param_5 + 0x2c) = uStack_34;
            uStack_36 = (undefined1)((ulonglong)uVar2 >> 0x10);
            *(undefined1 *)(param_5 + 0x29) = uStack_36;
            return 0;
          }
          iVar5 = (*pfnWppQueryTraceInformation)(3,local_res8,4,&param_6,param_4);
          if (iVar5 == 0) {
            *(undefined1 *)(param_5 + 0x29) = local_res8[0];
          }
          uVar6 = (*pfnWppQueryTraceInformation)(2,param_5 + 0x2c,4,&param_6,param_4);
          return uVar6;
        }
      }
      return 0xc0000295;
    }
    if (param_1 < 8) {
      return 0;
    }
    if (param_1 == 8) {
      uVar10 = 0;
      puVar1 = *(ushort **)(param_5 + 0x20);
      lVar7 = param_5;
      do {
        lVar7 = *(longlong *)(lVar7 + 0x10);
        uVar10 = uVar10 + 1;
      } while (lVar7 != 0);
      if (0x3f < uVar10) {
        return 0xc000000d;
      }
      if (puVar1 == (ushort *)0x0) {
        uVar12 = 0;
        uVar9 = uVar10 * 0x20 + 0x18;
      }
      else {
        uVar12 = uVar10 * 0x20 + 0x18;
        uVar9 = *puVar1 + 2 + uVar12;
      }
      if (param_3 < uVar9) {
        if (param_3 < 4) {
          return 0xc0000023;
        }
        *param_4 = uVar9;
        *param_6 = 4;
        return 0xc0000023;
      }
      memset(param_4,0,(ulonglong)param_3);
      *param_4 = uVar9;
      param_4[2] = uVar12;
      param_4[4] = uVar10;
      if (puVar1 != (ushort *)0x0) {
        *(ushort *)((ulonglong)uVar12 + (longlong)param_4) = *puVar1;
        memmove((ushort *)((ulonglong)uVar12 + (longlong)param_4) + 1,*(void **)(puVar1 + 4),
                (ulonglong)*puVar1);
      }
      if (uVar10 != 0) {
        uVar8 = (ulonglong)uVar10;
        puVar11 = param_4 + 10;
        do {
          uVar2 = **(undefined8 **)(param_5 + 8);
          uVar3 = (*(undefined8 **)(param_5 + 8))[1];
          *puVar11 = 0x81000;
          *(undefined8 *)(puVar11 + -4) = uVar2;
          *(undefined8 *)(puVar11 + -2) = uVar3;
          *(undefined1 *)(param_5 + 0x29) = 0;
          *(undefined4 *)(param_5 + 0x2c) = 0;
          param_5 = *(longlong *)(param_5 + 0x10);
          uVar8 = uVar8 - 1;
          puVar11 = puVar11 + 8;
        } while (uVar8 != 0);
      }
      *puVar4 = uVar9;
      return 0;
    }
  }
  return 0xc0000010;
}



===== __security_init_cookie @ 14000f000 =====

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


