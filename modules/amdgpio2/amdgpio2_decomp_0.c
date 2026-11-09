
===== AMDGpioClearActiveInterrupts @ 140001000 =====

undefined8 AMDGpioClearActiveInterrupts(undefined4 *param_1,short *param_2)

{
  short sVar1;
  uint uVar2;
  ulonglong uVar3;
  ushort uVar4;
  ushort uVar5;
  uint *puVar6;
  undefined4 uVar9;
  undefined8 uVar7;
  ulonglong uVar8;
  
  sVar1 = *param_2;
  uVar3 = *(ulonglong *)(param_2 + 4);
  uVar5 = 0;
  uVar8 = uVar3;
  DbgPrintEx(0x94,2,"AMDGPIO: In %s, BankID %d ClearActiveMask 0x%I64X\n",
             "AMDGpioClearActiveInterrupts",sVar1,uVar3);
  uVar9 = (undefined4)(uVar8 >> 0x20);
  if (sVar1 == 0) {
    uVar5 = 0x3f;
  }
  else if (sVar1 == 1) {
    uVar5 = 0x40;
  }
  else if (sVar1 == 2) {
    uVar5 = 0x38;
  }
  else if (sVar1 == 3) {
    uVar5 = 0x20;
  }
  uVar4 = 0;
  puVar6 = (uint *)(*(longlong *)(param_1 + 2) + (ulonglong)(ushort)(sVar1 << 6) * 4);
  if (uVar5 != 0) {
    do {
      if ((uVar3 >> ((ulonglong)(byte)uVar4 & 0x3f) & 1) != 0) {
        uVar2 = *puVar6;
        uVar7 = CONCAT44((int)(uVar8 >> 0x20),uVar2);
        DbgPrintEx(0x94,3,"AMDGPIO: AMDGPIO READ_REGISTER_LONG(0x%lx + 0x%lx) = 0x%x\n",*param_1,
                   (longlong)puVar6 - *(longlong *)(param_1 + 2),uVar7);
        uVar8 = CONCAT44((int)((ulonglong)uVar7 >> 0x20),uVar2) | 0x10000000;
        DbgPrintEx(0x94,3,"AMDGPIO: AMDGPIO WRITE_REGISTER_LONG(0x%lx + 0x%lx) = 0x%x\n",*param_1,
                   (longlong)puVar6 - *(longlong *)(param_1 + 2),uVar8);
        *puVar6 = uVar2 | 0x10000000;
        LOCK();
        UNLOCK();
        param_1[((longlong)puVar6 - *(longlong *)(param_1 + 2) >> 2) + 4] = uVar2 | 0x10000000;
      }
      uVar9 = (undefined4)(uVar8 >> 0x20);
      uVar4 = uVar4 + 1;
      puVar6 = puVar6 + 1;
    } while (uVar4 < uVar5);
  }
  uVar2 = *(uint *)(*(longlong *)(param_1 + 2) + 0xfc);
  uVar7 = CONCAT44(uVar9,uVar2);
  DbgPrintEx(0x94,3,"AMDGPIO: AMDGPIO READ_REGISTER_LONG(0x%lx + 0x%lx) = 0x%x\n",*param_1,
             (*(longlong *)(param_1 + 2) + 0xfc) - *(longlong *)(param_1 + 2),uVar7);
  puVar6 = (uint *)(*(longlong *)(param_1 + 2) + 0xfc);
  DbgPrintEx(0x94,3,"AMDGPIO: AMDGPIO WRITE_REGISTER_LONG(0x%lx + 0x%lx) = 0x%x\n",*param_1,
             (longlong)puVar6 - *(longlong *)(param_1 + 2),
             CONCAT44((int)((ulonglong)uVar7 >> 0x20),uVar2) | 0x20000000);
  *puVar6 = uVar2 | 0x20000000;
  LOCK();
  UNLOCK();
  param_1[((longlong)puVar6 - *(longlong *)(param_1 + 2) >> 2) + 4] = uVar2 | 0x20000000;
  param_2[8] = 0;
  param_2[9] = 0;
  param_2[10] = 0;
  param_2[0xb] = 0;
  return 0;
}



===== AMDGpioConnectIoPins @ 1400011d8 =====

undefined8 AMDGpioConnectIoPins(undefined4 *param_1,ushort *param_2)

{
  uint *puVar1;
  ushort uVar2;
  ushort uVar3;
  longlong lVar4;
  uint uVar5;
  ulonglong uVar6;
  uint local_res8 [2];
  longlong local_res10;
  
  uVar2 = *param_2;
  local_res10 = *(longlong *)(param_2 + 4);
  lVar4 = *(longlong *)(param_1 + 2);
  uVar6 = 0;
  if (param_2[8] != 0) {
    do {
      uVar3 = *(ushort *)(local_res10 + uVar6 * 2);
      puVar1 = (uint *)((ulonglong)uVar2 * 0x100 + lVar4 + (ulonglong)uVar3 * 4);
      uVar5 = *puVar1;
      DbgPrintEx(0x94,3,"AMDGPIO: AMDGPIO READ_REGISTER_LONG(0x%lx + 0x%lx) = 0x%x\n",*param_1,
                 (longlong)puVar1 - *(longlong *)(param_1 + 2),uVar5);
      local_res8[0] = uVar5;
      if (*(int *)(param_2 + 10) == 1) {
        DbgPrintEx(0x94,2,"AMDGPIO: In %s, configure BankID %d PinNumber %d as input\n",
                   "AMDGpioConnectIoPins",uVar2,uVar3);
        local_res8[0] = uVar5 & 0xff7fffff;
LAB_140001352:
      }
      else if (*(int *)(param_2 + 10) == 2) {
        DbgPrintEx(0x94,2,"AMDGPIO: In %s, configure BankID %d PinNumber %d as output\n",
                   "AMDGpioConnectIoPins",uVar2,uVar3);
        local_res8[0] = uVar5 | 0x800000;
        AMDGpioSetDebounceTimeout(param_2[0xd],local_res8,(longlong)param_1);
        uVar3 = param_2[0xe];
        if (uVar3 != 0) {
          if (uVar3 < 0x191) {
            local_res8[0] = local_res8[0] & 0xfff9ffff;
          }
          else if (uVar3 < 0x321) {
            local_res8[0] = local_res8[0] & 0xfffbffff | 0x20000;
          }
          else if (uVar3 < 0x4b1) {
            local_res8[0] = local_res8[0] & 0xfffdffff | 0x40000;
          }
          else {
            local_res8[0] = local_res8[0] | 0x60000;
          }
        }
        if ((char)param_2[0xc] == '\x01') {
          local_res8[0] = local_res8[0] & 0xffdfffff | 0x100000;
        }
        else if ((char)param_2[0xc] == '\x02') {
          local_res8[0] = local_res8[0] & 0xffefffff | 0x200000;
        }
        else {
          local_res8[0] = local_res8[0] & 0xffcfffff;
        }
        local_res8[0] = local_res8[0] | 0x80000;
        goto LAB_140001352;
      }
      uVar5 = local_res8[0];
      DbgPrintEx(0x94,3,"AMDGPIO: AMDGPIO WRITE_REGISTER_LONG(0x%lx + 0x%lx) = 0x%x\n",*param_1,
                 (longlong)puVar1 - *(longlong *)(param_1 + 2),local_res8[0]);
      *puVar1 = uVar5;
      LOCK();
      UNLOCK();
      uVar5 = (int)uVar6 + 1;
      uVar6 = (ulonglong)uVar5;
      param_1[((longlong)puVar1 - *(longlong *)(param_1 + 2) >> 2) + 4] = local_res8[0];
    } while (uVar5 < param_2[8]);
  }
  return 0;
}



===== AMDGpioDisableInterrupt @ 1400013cc =====

undefined8 AMDGpioDisableInterrupt(undefined4 *param_1,ushort *param_2)

{
  uint *puVar1;
  ushort uVar2;
  ushort uVar3;
  uint uVar4;
  longlong lVar5;
  
  uVar2 = param_2[1];
  uVar3 = *param_2;
  DbgPrintEx(0x94,2,"AMDGPIO: In %s, BankId %d PinNumber %d\n","AMDGpioDisableInterrupt",(uint)uVar3
             ,uVar2);
  (*DAT_140005360)(param_1,uVar3);
  lVar5 = (ulonglong)(uint)uVar3 * 0x40 + (ulonglong)uVar2;
  puVar1 = (uint *)(*(longlong *)(param_1 + 2) + lVar5 * 4);
  uVar4 = *puVar1;
  DbgPrintEx(0x94,3,"AMDGPIO: AMDGPIO READ_REGISTER_LONG(0x%lx + 0x%lx) = 0x%x\n",*param_1,
             (longlong)puVar1 - *(longlong *)(param_1 + 2),uVar4);
  uVar4 = uVar4 & 0xffffe7ff;
  puVar1 = (uint *)(*(longlong *)(param_1 + 2) + lVar5 * 4);
  DbgPrintEx(0x94,3,"AMDGPIO: AMDGPIO WRITE_REGISTER_LONG(0x%lx + 0x%lx) = 0x%x\n",*param_1,
             (longlong)puVar1 - *(longlong *)(param_1 + 2),uVar4);
  *puVar1 = uVar4;
  LOCK();
  UNLOCK();
  param_1[((longlong)puVar1 - *(longlong *)(param_1 + 2) >> 2) + 4] = uVar4;
  (*DAT_140005368)(param_1,uVar3);
  return 0;
}



===== AMDGpioDisconnectIoPins @ 1400014cc =====

undefined8 AMDGpioDisconnectIoPins(undefined4 *param_1,ushort *param_2)

{
  uint *puVar1;
  ushort uVar2;
  ushort uVar3;
  longlong lVar4;
  uint uVar5;
  ulonglong uVar6;
  ushort *puVar7;
  
  uVar2 = *param_2;
  puVar7 = *(ushort **)(param_2 + 4);
  lVar4 = *(longlong *)(param_1 + 2);
  if (*(uint *)(param_2 + 8) != 0) {
    uVar6 = (ulonglong)*(uint *)(param_2 + 8);
    do {
      uVar3 = *puVar7;
      DbgPrintEx(0x94,2,"AMDGPIO: In %s, configure BankID %d PinNumber %d as default\n",
                 "AMDGpioDisconnectIoPins",uVar2,uVar3);
      puVar1 = (uint *)((ulonglong)uVar2 * 0x100 + lVar4 + (ulonglong)uVar3 * 4);
      uVar5 = *puVar1;
      DbgPrintEx(0x94,3,"AMDGPIO: AMDGPIO READ_REGISTER_LONG(0x%lx + 0x%lx) = 0x%x\n",*param_1,
                 (longlong)puVar1 - *(longlong *)(param_1 + 2),uVar5);
      uVar5 = uVar5 & 0xff47ff90;
      DbgPrintEx(0x94,3,"AMDGPIO: AMDGPIO WRITE_REGISTER_LONG(0x%lx + 0x%lx) = 0x%x\n",*param_1,
                 (longlong)puVar1 - *(longlong *)(param_1 + 2),uVar5);
      *puVar1 = uVar5;
      LOCK();
      UNLOCK();
      puVar7 = puVar7 + 1;
      param_1[((longlong)puVar1 - *(longlong *)(param_1 + 2) >> 2) + 4] = uVar5;
      uVar6 = uVar6 - 1;
    } while (uVar6 != 0);
  }
  return 0;
}



===== AMDGpioEnableInterrupt @ 1400015d8 =====

undefined8 AMDGpioEnableInterrupt(undefined4 *param_1,ushort *param_2)

{
  uint *puVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  char *pcVar5;
  uint uVar6;
  uint uVar7;
  undefined8 uVar8;
  uint local_res8 [2];
  
  uVar2 = *param_2;
  uVar3 = param_2[1];
  uVar8 = 0;
  pcVar5 = "Latched";
  uVar6 = (uint)uVar2 * 0x40 + (uint)uVar3;
  if (*(int *)(param_2 + 4) == 0) {
    pcVar5 = "LevelSensitive";
  }
  DbgPrintEx(0x94,2,"AMDGPIO: In %s, Enable Interrupt with IntMode(%s), BankID %d PinNumber %d\n",
             "AMDGpioEnableInterrupt",pcVar5,uVar2,(uint)uVar3);
  (*DAT_140005360)(param_1,uVar2);
  puVar1 = (uint *)(*(longlong *)(param_1 + 2) + (ulonglong)uVar6 * 4);
  uVar7 = *puVar1;
  DbgPrintEx(0x94,3,"AMDGPIO: AMDGPIO READ_REGISTER_LONG(0x%lx + 0x%lx) = 0x%x\n",*param_1,
             (longlong)puVar1 - *(longlong *)(param_1 + 2),uVar7);
  if (*(int *)(param_2 + 4) == 0) {
    uVar7 = uVar7 | 0x100;
  }
  else {
    uVar7 = uVar7 & 0xfffffeff;
  }
  iVar4 = *(int *)(param_2 + 6);
  if (iVar4 == 1) {
    local_res8[0] = uVar7 & 0xfffff9df | 0x40;
  }
  else if (iVar4 == 2) {
    local_res8[0] = uVar7 & 0xfffffbbf | 0x220;
  }
  else {
    if (iVar4 != 3) {
      uVar8 = 0xc00000bb;
      goto LAB_140001785;
    }
    local_res8[0] = uVar7 & 0xfffffdff | 0x460;
  }
  if ((uVar2 == 0) && (uVar3 == 0)) {
    AMDGpioSetDebounceTimeoutForGpio0(param_2[9],local_res8,param_1);
  }
  else {
    AMDGpioSetDebounceTimeout(param_2[9],local_res8,(longlong)param_1);
  }
  if ((char)param_2[8] == '\x01') {
    uVar7 = local_res8[0] & 0xffdfffff | 0x100000;
  }
  else if ((char)param_2[8] == '\x02') {
    uVar7 = local_res8[0] & 0xffefffff | 0x200000;
  }
  else {
    uVar7 = local_res8[0] & 0xffcfffff;
  }
  uVar7 = uVar7 | 0x10001800;
  puVar1 = (uint *)(*(longlong *)(param_1 + 2) + (ulonglong)uVar6 * 4);
  local_res8[0] = uVar7;
  DbgPrintEx(0x94,3,"AMDGPIO: AMDGPIO WRITE_REGISTER_LONG(0x%lx + 0x%lx) = 0x%x\n",*param_1,
             (longlong)puVar1 - *(longlong *)(param_1 + 2),uVar7);
  *puVar1 = uVar7;
  LOCK();
  UNLOCK();
  param_1[((longlong)puVar1 - *(longlong *)(param_1 + 2) >> 2) + 4] = local_res8[0];
LAB_140001785:
  (*DAT_140005368)(param_1,uVar2);
  return uVar8;
}



===== AMDGpioGetGeneration @ 1400017b0 =====

undefined8 AMDGpioGetGeneration(undefined8 param_1,int *param_2)

{
  int iVar1;
  wchar_t *_Str2;
  longlong lVar2;
  undefined8 local_res8;
  undefined4 local_48 [6];
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 local_28;
  
  memset(local_48,0,0x38);
  local_48[0] = 0x38;
  local_30 = 1;
  *param_2 = 0;
  local_2c = 1;
  local_28 = param_1;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x290))
                    (WdfDriverGlobals,param_1,1,0x200,local_48,&local_res8);
  if (-1 < iVar1) {
    _Str2 = (wchar_t *)(**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,local_res8,0);
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (_Str2[lVar2] != L'\0');
    while (lVar2 != 0) {
      iVar1 = wcsncmp(L"*GPIO0010",_Str2,9);
      if (iVar1 == 0) {
        DbgPrintEx(0x94,2,"AMDGPIO: In %s, HWID GPIO0010 is found\n","AMDGpioGetGeneration");
        *param_2 = 1;
        return 0;
      }
      iVar1 = wcsncmp(L"*AMD0030",_Str2,8);
      if (iVar1 == 0) {
        DbgPrintEx(0x94,2,"AMDGPIO: In %s, HWID AMD0030 is found\n","AMDGpioGetGeneration");
        *param_2 = 2;
        return 0;
      }
      iVar1 = wcsncmp(L"*AMDI0030",_Str2,9);
      if (iVar1 == 0) {
        DbgPrintEx(0x94,2,"AMDGPIO: In %s, HWID AMDI0030 is found\n","AMDGpioGetGeneration");
        *param_2 = 3;
        break;
      }
      _Str2 = _Str2 + lVar2 + 1;
      lVar2 = -1;
      do {
        lVar2 = lVar2 + 1;
      } while (_Str2[lVar2] != L'\0');
    }
    if (*param_2 != 0) {
      return 0;
    }
  }
  return 0xc0000001;
}



===== AMDGpioMaskInterrupts @ 140001970 =====

undefined8 AMDGpioMaskInterrupts(undefined4 *param_1,short *param_2)

{
  short sVar1;
  uint uVar2;
  ulonglong uVar3;
  uint uVar4;
  ushort uVar5;
  ushort uVar6;
  uint *puVar7;
  undefined8 uVar8;
  ulonglong uVar9;
  
  sVar1 = *param_2;
  uVar3 = *(ulonglong *)(param_2 + 4);
  uVar6 = 0;
  uVar9 = uVar3;
  DbgPrintEx(0x94,2,"AMDGPIO: In %s, BankID %d PinMask 0x%I64X\n","AMDGpioMaskInterrupts",sVar1,
             uVar3);
  if (sVar1 == 0) {
    uVar6 = 0x3f;
  }
  else if (sVar1 == 1) {
    uVar6 = 0x40;
  }
  else if (sVar1 == 2) {
    uVar6 = 0x38;
  }
  else if (sVar1 == 3) {
    uVar6 = 0x20;
  }
  uVar5 = 0;
  puVar7 = (uint *)(*(longlong *)(param_1 + 2) + (ulonglong)(ushort)(sVar1 << 6) * 4);
  if (uVar6 != 0) {
    do {
      if ((uVar3 >> ((ulonglong)(byte)uVar5 & 0x3f) & 1) != 0) {
        uVar2 = *puVar7;
        uVar8 = CONCAT44((int)(uVar9 >> 0x20),uVar2);
        DbgPrintEx(0x94,3,"AMDGPIO: AMDGPIO READ_REGISTER_LONG(0x%lx + 0x%lx) = 0x%x\n",*param_1,
                   (longlong)puVar7 - *(longlong *)(param_1 + 2),uVar8);
        uVar4 = uVar2 & 0xffffefff | 0x800;
        uVar9 = CONCAT44((int)((ulonglong)uVar8 >> 0x20),uVar2) & 0xffffffffffffefff | 0x800;
        DbgPrintEx(0x94,3,"AMDGPIO: AMDGPIO WRITE_REGISTER_LONG(0x%lx + 0x%lx) = 0x%x\n",*param_1,
                   (longlong)puVar7 - *(longlong *)(param_1 + 2),uVar9);
        *puVar7 = uVar4;
        LOCK();
        UNLOCK();
        param_1[((longlong)puVar7 - *(longlong *)(param_1 + 2) >> 2) + 4] = uVar4;
      }
      uVar5 = uVar5 + 1;
      puVar7 = puVar7 + 1;
    } while (uVar5 < uVar6);
  }
  return 0;
}



===== AMDGpioPrepareController @ 140001abc =====

ulonglong AMDGpioPrepareController
                    (undefined8 param_1,undefined8 *param_2,undefined8 param_3,undefined8 param_4)

{
  char cVar1;
  uint uVar2;
  ulonglong uVar3;
  char *pcVar4;
  longlong lVar5;
  undefined8 *puVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  
  memset(param_2,0,0x420);
  uVar3 = AMDGpioGetGeneration(param_1,(int *)(param_2 + 0x82));
  uVar7 = 0;
  if ((int)uVar3 < 0) {
    return uVar3;
  }
  *(undefined2 *)((longlong)param_2 + 0x41a) = 3;
  if (*(int *)(param_2 + 0x82) == 3) {
    *(undefined2 *)((longlong)param_2 + 0x41a) = 4;
  }
  iVar11 = 0;
  *(short *)(param_2 + 0x83) = *(short *)((longlong)param_2 + 0x41a) << 6;
  iVar10 = 0;
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x980))(WdfDriverGlobals);
  uVar9 = 0;
  uVar8 = 0;
  if (uVar2 == 0) {
LAB_140001c34:
    pcVar4 = "AMDGPIO: No proper memory resource found\n";
  }
  else {
    do {
      pcVar4 = (char *)(**(code **)(WdfFunctions_01015 + 0x988))(WdfDriverGlobals,param_4,uVar8);
      cVar1 = *pcVar4;
      if (cVar1 == '\x01') {
        uVar9 = 0xc0000001;
      }
      else if (cVar1 == '\x02') {
        iVar11 = iVar11 + 1;
      }
      else if ((cVar1 == '\x03') && ((*(int *)(pcVar4 + 0xc) - 0x300U & 0xfffffeff) == 0)) {
        *param_2 = *(undefined8 *)(pcVar4 + 4);
        lVar5 = MmMapIoSpace(*(undefined8 *)(pcVar4 + 4),*(undefined4 *)(pcVar4 + 0xc),0);
        param_2[1] = lVar5;
        if (lVar5 == 0) {
          uVar9 = 0xc0000001;
        }
        *(undefined4 *)((longlong)param_2 + 0x414) = *(undefined4 *)(pcVar4 + 0xc);
        iVar10 = iVar10 + 1;
      }
      if ((int)uVar9 < 0) goto LAB_140001c4d;
      uVar8 = uVar8 + 1;
    } while (uVar8 < uVar2);
    if (iVar10 == 0) goto LAB_140001c34;
    if (iVar11 != 0) {
      puVar6 = param_2 + 2;
      if (*(short *)(param_2 + 0x83) != 0) {
        do {
          *(undefined4 *)puVar6 = 0xffffffff;
          uVar7 = uVar7 + 1;
          puVar6 = (undefined8 *)((longlong)puVar6 + 4);
        } while (uVar7 < *(ushort *)(param_2 + 0x83));
      }
      goto LAB_140001c76;
    }
    pcVar4 = "AMDGPIO: No proper irq resource found\n";
  }
  DbgPrintEx(0x94,0,pcVar4);
  uVar9 = 0xc0000001;
LAB_140001c4d:
  if (param_2[1] != 0) {
    MmUnmapIoSpace();
    param_2[1] = 0;
  }
  memset(param_2,0,0x420);
LAB_140001c76:
  return (ulonglong)uVar9;
}



===== AMDGpioQueryActiveInterrupts @ 140001c98 =====

undefined8 AMDGpioQueryActiveInterrupts(undefined4 *param_1,ushort *param_2)

{
  ulonglong *puVar1;
  ushort uVar2;
  uint uVar3;
  ulonglong uVar4;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint local_res10;
  uint local_res18;
  
  uVar2 = *param_2;
  uVar8 = 0;
  uVar4 = *(ulonglong *)(param_2 + 4);
  param_2[8] = 0;
  param_2[9] = 0;
  param_2[10] = 0;
  param_2[0xb] = 0;
  uVar7 = (uint)uVar2;
  local_res10 = 0;
  local_res18 = 0;
  if (uVar7 == 0) {
    local_res18 = 0xe;
  }
  else if (uVar7 == 1) {
    uVar8 = 0x10;
    local_res18 = 0x1f;
  }
  else {
    if (uVar7 != 2) goto LAB_140001d11;
    local_res18 = 0xd;
  }
  local_res10 = uVar8;
LAB_140001d11:
  if (uVar2 == 2) {
    puVar6 = (uint *)(*(longlong *)(param_1 + 2) + 0x2fc);
  }
  else {
    puVar6 = (uint *)(*(longlong *)(param_1 + 2) + 0x2f8);
  }
  uVar8 = *puVar6;
  DbgPrintEx(0x94,3,"AMDGPIO: AMDGPIO READ_REGISTER_LONG(0x%lx + 0x%lx) = 0x%x\n",*param_1,
             (longlong)puVar6 - *(longlong *)(param_1 + 2),uVar8);
  for (; local_res10 <= local_res18; local_res10 = local_res10 + 1) {
    if ((uVar8 >> (local_res10 & 0x1f) & 1) != 0) {
      uVar5 = local_res10 + 0x20;
      if (uVar2 != 2) {
        uVar5 = local_res10;
      }
      uVar9 = 0;
      puVar6 = (uint *)(*(longlong *)(param_1 + 2) + (ulonglong)(uVar5 << 2) * 4);
      do {
        uVar3 = *puVar6;
        DbgPrintEx(0x94,3,"AMDGPIO: AMDGPIO READ_REGISTER_LONG(0x%lx + 0x%lx) = 0x%x\n",*param_1,
                   (longlong)puVar6 - *(longlong *)(param_1 + 2),uVar3);
        if (((uVar3 & 0x1800) == 0x1800) && ((uVar3 >> 0x1c & 1) != 0)) {
          uVar3 = uVar9 + (uVar5 + uVar7 * -0x10) * 4;
          DbgPrintEx(0x94,2,
                     "AMDGPIO: In %s, BankID %d PinNumber #%d is active while EnabledMask is 0x%I64X.\n"
                     ,"AMDGpioQueryActiveInterrupts",uVar7,uVar3,uVar4);
          *(ulonglong *)(param_2 + 8) =
               *(ulonglong *)(param_2 + 8) | 1L << ((ulonglong)uVar3 & 0x3f);
        }
        uVar9 = uVar9 + 1;
        puVar6 = puVar6 + 1;
      } while (uVar9 < 4);
    }
  }
  puVar1 = (ulonglong *)(param_2 + 8);
  *puVar1 = *puVar1 & uVar4;
  if (*puVar1 == 0) {
    uVar7 = *(uint *)(*(longlong *)(param_1 + 2) + 0xfc);
    DbgPrintEx(0x94,3,"AMDGPIO: AMDGPIO READ_REGISTER_LONG(0x%lx + 0x%lx) = 0x%x\n",*param_1,
               (*(longlong *)(param_1 + 2) + 0xfc) - *(longlong *)(param_1 + 2),uVar7);
    uVar7 = uVar7 | 0x20000000;
    puVar6 = (uint *)(*(longlong *)(param_1 + 2) + 0xfc);
    DbgPrintEx(0x94,3,"AMDGPIO: AMDGPIO WRITE_REGISTER_LONG(0x%lx + 0x%lx) = 0x%x\n",*param_1,
               (longlong)puVar6 - *(longlong *)(param_1 + 2),uVar7);
    *puVar6 = uVar7;
    LOCK();
    UNLOCK();
    param_1[((longlong)puVar6 - *(longlong *)(param_1 + 2) >> 2) + 4] = uVar7;
  }
  return 0;
}



===== AMDGpioQueryEnabledInterrupts @ 140001f2c =====

undefined8 AMDGpioQueryEnabledInterrupts(undefined4 *param_1,ushort *param_2)

{
  ushort uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  uint *puVar4;
  uint uVar5;
  
  uVar3 = 0;
  uVar1 = *param_2;
  uVar5 = 0;
  param_2[4] = 0;
  param_2[5] = 0;
  param_2[6] = 0;
  param_2[7] = 0;
  if (uVar1 == 0) {
    uVar5 = 0x3f;
  }
  else if (uVar1 == 1) {
    uVar5 = 0x40;
  }
  else if (uVar1 == 2) {
    uVar5 = 0x38;
  }
  else if (uVar1 == 3) {
    uVar5 = 0x20;
  }
  puVar4 = (uint *)((ulonglong)uVar1 * 0x100 + *(longlong *)(param_1 + 2));
  if (uVar5 != 0) {
    uVar2 = (ulonglong)uVar5;
    do {
      uVar5 = *puVar4;
      DbgPrintEx(0x94,3,"AMDGPIO: AMDGPIO READ_REGISTER_LONG(0x%lx + 0x%lx) = 0x%x\n",*param_1,
                 (longlong)puVar4 - *(longlong *)(param_1 + 2),uVar5);
      if ((uVar5 & 0x1800) == 0x1800) {
        *(ulonglong *)(param_2 + 4) = *(ulonglong *)(param_2 + 4) | 1L << (uVar3 & 0x3f);
      }
      puVar4 = puVar4 + 1;
      uVar3 = uVar3 + 1;
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  DbgPrintEx(0x94,2,"AMDGPIO: In %s, BankID %d EnabledMask is 0x%I64X.\n",
             "AMDGpioQueryEnabledInterrupts",uVar1,*(undefined8 *)(param_2 + 4));
  return 0;
}



===== AMDGpioReadGpioPins @ 140002084 =====

undefined8 AMDGpioReadGpioPins(undefined4 *param_1,ushort *param_2)

{
  ushort uVar1;
  uint uVar2;
  ulonglong *puVar3;
  longlong lVar4;
  ushort uVar5;
  uint uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  uint *puVar9;
  undefined8 in_stack_ffffffffffffffd8;
  undefined8 uVar10;
  undefined4 uVar11;
  
  uVar1 = *param_2;
  uVar8 = 0;
  puVar3 = *(ulonglong **)(param_2 + 4);
  uVar5 = 0;
  uVar6 = (uint)uVar1;
  if (uVar1 == 0) {
    uVar5 = 0x3f;
  }
  else if (uVar6 == 1) {
    uVar5 = 0x40;
  }
  else if (uVar6 == 2) {
    uVar5 = 0x38;
  }
  else if (uVar6 == 3) {
    uVar5 = 0x20;
  }
  *puVar3 = 0;
  uVar10 = CONCAT44((int)((ulonglong)in_stack_ffffffffffffffd8 >> 0x20),uVar6);
  DbgPrintEx(0x94,3,"AMDGPIO: In %s, Read Bank %d\n","AMDGpioReadGpioPins",uVar10);
  uVar11 = (undefined4)((ulonglong)uVar10 >> 0x20);
  puVar9 = (uint *)(*(longlong *)(param_1 + 2) + (ulonglong)(ushort)(uVar1 << 6) * 4);
  if (uVar5 != 0) {
    uVar7 = (ulonglong)uVar5;
    do {
      uVar2 = *puVar9;
      lVar4 = (longlong)puVar9 - *(longlong *)(param_1 + 2);
      DbgPrintEx(0x94,3,"AMDGPIO: AMDGPIO READ_REGISTER_LONG(0x%lx + 0x%lx) = 0x%x\n",*param_1,lVar4
                 ,uVar2);
      uVar11 = (undefined4)((ulonglong)lVar4 >> 0x20);
      if ((uVar2 >> 0x10 & 1) != 0) {
        *puVar3 = *puVar3 | 1L << (uVar8 & 0x3f);
      }
      uVar8 = uVar8 + 1;
      puVar9 = puVar9 + 1;
      uVar7 = uVar7 - 1;
    } while (uVar7 != 0);
  }
  DbgPrintEx(0x94,2,"AMDGPIO: In %s, Read out Bank %d, PinValues: 0x%I64X\n","AMDGpioReadGpioPins",
             CONCAT44(uVar11,uVar6),*puVar3);
  return 0;
}



===== AMDGpioReconfigureInterrupt @ 1400021b4 =====

undefined8 AMDGpioReconfigureInterrupt(undefined4 *param_1,ushort *param_2)

{
  uint *puVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  uint uVar5;
  ulonglong uVar6;
  
  uVar2 = param_2[1];
  uVar3 = *param_2;
  DbgPrintEx(0x94,2,"AMDGPIO: In %s, BankID %d PinNumber %d\n","AMDGpioReconfigureInterrupt",uVar3,
             (uint)uVar2);
  uVar6 = (ulonglong)((uint)uVar3 * 0x40 + (uint)uVar2);
  puVar1 = (uint *)(*(longlong *)(param_1 + 2) + uVar6 * 4);
  uVar5 = *puVar1;
  DbgPrintEx(0x94,3,"AMDGPIO: AMDGPIO READ_REGISTER_LONG(0x%lx + 0x%lx) = 0x%x\n",*param_1,
             (longlong)puVar1 - *(longlong *)(param_1 + 2),uVar5);
  if (*(int *)(param_2 + 2) == 0) {
    uVar5 = uVar5 | 0x100;
  }
  else {
    uVar5 = uVar5 & 0xfffffeff;
  }
  iVar4 = *(int *)(param_2 + 4);
  if (iVar4 == 1) {
    uVar5 = uVar5 & 0xfffff9df | 0x40;
  }
  else if (iVar4 == 2) {
    uVar5 = uVar5 & 0xfffffbbf | 0x220;
  }
  else {
    if (iVar4 != 3) {
      return 0xc00000bb;
    }
    uVar5 = uVar5 & 0xfffffdff | 0x460;
  }
  uVar5 = uVar5 | 0x10000000;
  puVar1 = (uint *)(*(longlong *)(param_1 + 2) + uVar6 * 4);
  DbgPrintEx(0x94,3,"AMDGPIO: AMDGPIO WRITE_REGISTER_LONG(0x%lx + 0x%lx) = 0x%x\n",*param_1,
             (longlong)puVar1 - *(longlong *)(param_1 + 2),uVar5);
  *puVar1 = uVar5;
  LOCK();
  UNLOCK();
  param_1[((longlong)puVar1 - *(longlong *)(param_1 + 2) >> 2) + 4] = uVar5;
  return 0;
}



===== AMDGpioReleaseController @ 1400022e8 =====

undefined8 AMDGpioReleaseController(undefined8 param_1,void *param_2)

{
  if (*(longlong *)((longlong)param_2 + 8) != 0) {
    MmUnmapIoSpace();
    *(undefined8 *)((longlong)param_2 + 8) = 0;
  }
  memset(param_2,0,0x420);
  return 0;
}



===== AMDGpioRestoreBankHardwareContext @ 140002324 =====

void AMDGpioRestoreBankHardwareContext(undefined4 *param_1,ushort *param_2)

{
  int iVar1;
  int *piVar2;
  longlong lVar3;
  int *piVar4;
  
  DbgPrintEx(0x94,3,"AMDGPIO: In %s, Restore GPIO register context of BankID %d and enter F%d\n",
             "AMDGpioRestoreBankHardwareContext",*param_2,*(undefined4 *)(param_2 + 2));
  lVar3 = 0x40;
  piVar4 = param_1 + (ulonglong)*param_2 * 0x40 + 4;
  piVar2 = (int *)(*(longlong *)(param_1 + 2) + (ulonglong)*param_2 * 0x100);
  do {
    iVar1 = *piVar4;
    if (iVar1 != -1) {
      DbgPrintEx(0x94,3,"AMDGPIO: AMDGPIO WRITE_REGISTER_LONG(0x%lx + 0x%lx) = 0x%x\n",*param_1,
                 (longlong)piVar2 - *(longlong *)(param_1 + 2),iVar1);
      *piVar2 = iVar1;
      LOCK();
      UNLOCK();
      param_1[((longlong)piVar2 - *(longlong *)(param_1 + 2) >> 2) + 4] = iVar1;
    }
    piVar2 = piVar2 + 1;
    piVar4 = piVar4 + 1;
    lVar3 = lVar3 + -1;
  } while (lVar3 != 0);
  return;
}



===== AMDGpioSaveBankHardwareContext @ 1400023fc =====

void AMDGpioSaveBankHardwareContext(undefined8 param_1,undefined2 *param_2)

{
  DbgPrintEx(0x94,3,"AMDGPIO: In %s, Save GPIO register context of BankID %d and enter F%d\n",
             "AMDGpioSaveBankHardwareContext",*param_2,*(undefined4 *)(param_2 + 2));
  return;
}



===== AMDGpioSetDebounceTimeout @ 140002434 =====

void AMDGpioSetDebounceTimeout(ushort param_1,uint *param_2,longlong param_3)

{
  uint uVar1;
  uint uVar2;
  
  if (param_1 == 0) {
    *param_2 = *param_2 & 0xffffff00;
    return;
  }
  if (param_1 < 0x61) {
    uVar2 = ((uint)param_1 * 10) / 0x3d & 0xf;
    uVar1 = *param_2 & 0xffffff60;
  }
  else if (param_1 < 0x186) {
    uVar2 = ((uint)param_1 * 10) / 0xf4 & 0xf | 0x10;
    uVar1 = *param_2 & 0xffffff70;
  }
  else {
    if (*(int *)(param_3 + 0x410) == 1) {
      *param_2 = *param_2 & 0xffffff7f | 0x1f;
      return;
    }
    if (param_1 < 25000) {
      uVar2 = ((uint)param_1 * 10) / 0x3d00 & 0xf | 0x80;
      uVar1 = *param_2 & 0xffffffe0;
    }
    else {
      if (99999 < param_1) {
        *param_2 = *param_2 | 0x9f;
        return;
      }
      uVar2 = ((uint)param_1 * 10) / 0xf400 & 0xf | 0x90;
      uVar1 = *param_2 & 0xfffffff0;
    }
  }
  *param_2 = uVar2 | uVar1;
  return;
}



===== AMDGpioSetDebounceTimeoutForGpio0 @ 14000252c =====

void AMDGpioSetDebounceTimeoutForGpio0(ushort param_1,uint *param_2,undefined4 *param_3)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  
  if (param_1 == 0) {
    *param_2 = *param_2 & 0xffffff00;
    return;
  }
  if (param_1 < 0x61) {
    uVar3 = ((uint)param_1 * 10) / 0x3d & 0xf;
    uVar2 = *param_2 & 0xffffff60;
  }
  else if (param_1 < 0x186) {
    uVar3 = ((uint)param_1 * 10) / 0xf4 & 0xf | 0x10;
    uVar2 = *param_2 & 0xffffff70;
  }
  else {
    if (param_3[0x104] == 1) {
      if (param_1 < 25000) {
        *param_2 = ((uint)param_1 * 10) / 0x3d00 & 0xf | 0x90 | *param_2 & 0xfffffff0;
      }
      else {
        *param_2 = *param_2 | 0x9f;
      }
      uVar2 = *(uint *)(*(longlong *)(param_3 + 2) + 0xfc);
      DbgPrintEx(0x94,3,"AMDGPIO: AMDGPIO READ_REGISTER_LONG(0x%lx + 0x%lx) = 0x%x\n",*param_3,
                 (*(longlong *)(param_3 + 2) + 0xfc) - *(longlong *)(param_3 + 2),uVar2);
      if ((char)*param_2 < '\0') {
        uVar2 = uVar2 | 0x800000;
      }
      else {
        uVar2 = uVar2 & 0xff7fffff;
      }
      puVar1 = (uint *)(*(longlong *)(param_3 + 2) + 0xfc);
      DbgPrintEx(0x94,3,"AMDGPIO: AMDGPIO WRITE_REGISTER_LONG(0x%lx + 0x%lx) = 0x%x\n",*param_3,
                 (longlong)puVar1 - *(longlong *)(param_3 + 2),uVar2);
      *puVar1 = uVar2;
      LOCK();
      UNLOCK();
      param_3[((longlong)puVar1 - *(longlong *)(param_3 + 2) >> 2) + 4] = uVar2;
      return;
    }
    if (param_1 < 25000) {
      uVar3 = ((uint)param_1 * 10) / 0x3d00 & 0xf | 0x80;
      uVar2 = *param_2 & 0xffffffe0;
    }
    else {
      if (99999 < param_1) {
        *param_2 = *param_2 | 0x9f;
        return;
      }
      uVar3 = ((uint)param_1 * 10) / 0xf400 & 0xf | 0x90;
      uVar2 = *param_2 & 0xfffffff0;
    }
  }
  *param_2 = uVar3 | uVar2;
  return;
}



===== AMDGpioStartController @ 14000270c =====

undefined8 AMDGpioStartController(undefined4 *param_1,char param_2,undefined4 param_3)

{
  char *pcVar1;
  ushort uVar2;
  ushort local_18 [2];
  undefined4 local_14;
  
  pcVar1 = "not";
  uVar2 = 0;
  if (param_2 != '\0') {
    pcVar1 = "";
  }
  DbgPrintEx(0x94,3,"AMDGPIO: In %s, It will %s restore GPIO register context\n",
             "AMDGpioStartController",pcVar1);
  if (param_2 == '\x01') {
    for (; uVar2 < *(ushort *)((longlong)param_1 + 0x41a); uVar2 = uVar2 + 1) {
      local_18[0] = uVar2;
      local_14 = param_3;
      AMDGpioRestoreBankHardwareContext(param_1,local_18);
    }
  }
  return 0;
}



===== AMDGpioStopController @ 1400027a0 =====

undefined8 AMDGpioStopController(longlong param_1,char param_2,undefined4 param_3)

{
  ushort uVar1;
  ushort local_18 [2];
  undefined4 local_14;
  
  if ((param_2 == '\x01') && (uVar1 = 0, *(short *)(param_1 + 0x41a) != 0)) {
    do {
      local_18[0] = uVar1;
      local_14 = param_3;
      AMDGpioSaveBankHardwareContext(param_1,local_18);
      uVar1 = uVar1 + 1;
    } while (uVar1 < *(ushort *)(param_1 + 0x41a));
  }
  return 0;
}



===== AMDGpioUnmaskInterrupt @ 1400027fc =====

undefined8 AMDGpioUnmaskInterrupt(undefined4 *param_1,ushort *param_2)

{
  uint *puVar1;
  ushort uVar2;
  ushort uVar3;
  uint uVar4;
  
  uVar2 = param_2[1];
  uVar3 = *param_2;
  DbgPrintEx(0x94,2,"AMDGPIO: In %s, BankID %d PinNumber %d\n","AMDGpioUnmaskInterrupt",(uint)uVar3,
             uVar2);
  puVar1 = (uint *)(*(longlong *)(param_1 + 2) +
                   ((ulonglong)(uint)uVar3 * 0x40 + (ulonglong)uVar2) * 4);
  uVar4 = *puVar1;
  DbgPrintEx(0x94,3,"AMDGPIO: AMDGPIO READ_REGISTER_LONG(0x%lx + 0x%lx) = 0x%x\n",*param_1,
             (longlong)puVar1 - *(longlong *)(param_1 + 2),uVar4);
  uVar4 = uVar4 | 0x1800;
  DbgPrintEx(0x94,3,"AMDGPIO: AMDGPIO WRITE_REGISTER_LONG(0x%lx + 0x%lx) = 0x%x\n",*param_1,
             (longlong)puVar1 - *(longlong *)(param_1 + 2),uVar4);
  *puVar1 = uVar4;
  LOCK();
  UNLOCK();
  param_1[((longlong)puVar1 - *(longlong *)(param_1 + 2) >> 2) + 4] = uVar4;
  return 0;
}



===== AMDGpioWriteGpioPins @ 1400028d4 =====

undefined8 AMDGpioWriteGpioPins(undefined4 *param_1,ushort *param_2)

{
  ushort uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  longlong lVar4;
  ulonglong uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint *puVar9;
  uint local_res8;
  undefined4 uVar11;
  undefined8 uVar10;
  
  uVar1 = *param_2;
  uVar7 = 0;
  uVar2 = *(ulonglong *)(param_2 + 4);
  uVar3 = *(ulonglong *)(param_2 + 8);
  uVar8 = (uint)uVar1;
  if (uVar1 == 0) {
    uVar7 = 0x3f;
  }
  else if (uVar8 == 1) {
    uVar7 = 0x40;
  }
  else if (uVar8 == 2) {
    uVar7 = 0x38;
  }
  else if (uVar8 == 3) {
    uVar7 = 0x20;
  }
  uVar6 = 0;
  puVar9 = (uint *)(*(longlong *)(param_1 + 2) + (ulonglong)(ushort)(uVar1 << 6) * 4);
  if (uVar7 != 0) {
    do {
      uVar5 = 1L << ((byte)uVar6 & 0x3f);
      if (((uVar3 | uVar2) & uVar5) != 0) {
        local_res8 = *puVar9;
        lVar4 = (longlong)puVar9 - *(longlong *)(param_1 + 2);
        DbgPrintEx(0x94,3,"AMDGPIO: AMDGPIO READ_REGISTER_LONG(0x%lx + 0x%lx) = 0x%x\n",*param_1,
                   lVar4,local_res8);
        uVar11 = (undefined4)((ulonglong)lVar4 >> 0x20);
        if ((uVar2 & uVar5) != 0) {
          uVar10 = CONCAT44(uVar11,uVar8);
          DbgPrintEx(0x94,3,"AMDGPIO: In %s, BankID %d GEvent (%d) set to high\n",
                     "AMDGpioWriteGpioPins",uVar10,uVar6);
          uVar11 = (undefined4)((ulonglong)uVar10 >> 0x20);
          local_res8 = local_res8 & 0xffffffdf | 0x400040;
        }
        if ((uVar3 & uVar5) != 0) {
          DbgPrintEx(0x94,3,"AMDGPIO: In %s, BankID %d GEvent (%d) set to low\n",
                     "AMDGpioWriteGpioPins",CONCAT44(uVar11,uVar8),uVar6);
          local_res8 = local_res8 & 0xffbfffbf | 0x20;
        }
        DbgPrintEx(0x94,3,"AMDGPIO: AMDGPIO WRITE_REGISTER_LONG(0x%lx + 0x%lx) = 0x%x\n",*param_1,
                   (longlong)puVar9 - *(longlong *)(param_1 + 2),local_res8);
        *puVar9 = local_res8;
        LOCK();
        UNLOCK();
        param_1[((longlong)puVar9 - *(longlong *)(param_1 + 2) >> 2) + 4] = local_res8;
      }
      uVar6 = uVar6 + 1;
      puVar9 = puVar9 + 1;
    } while (uVar6 < uVar7);
  }
  return 0;
}



===== __security_check_cookie @ 140002aa0 =====

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



===== wcsncmp @ 140002ac8 =====

int __cdecl wcsncmp(wchar_t *_Str1,wchar_t *_Str2,size_t _MaxCount)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000140002ac8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = wcsncmp(_Str1,_Str2,_MaxCount);
  return iVar1;
}



===== FxStubDriverUnloadCommon @ 140002ad0 =====

/* void __cdecl FxStubDriverUnloadCommon(void) */

void __cdecl FxStubDriverUnloadCommon(void)

{
  FxStubUnbindClasses((_WDF_BIND_INFO *)&DAT_140005010);
  WdfVersionUnbind(&DAT_1400050e8,&DAT_140005010,WdfDriverGlobals);
  return;
}



===== entry @ 140002b00 =====

void entry(longlong param_1,undefined8 param_2)

{
  __security_init_cookie();
  FxDriverEntryWorker(param_1,param_2);
  return;
}



===== FxDriverEntryWorker @ 140002b2c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FxDriverEntryWorker(longlong param_1,undefined8 param_2)

{
  uint uVar1;
  ulonglong uVar2;
  
  if (param_1 == 0) {
    uVar2 = DriverEntry(0,param_2);
  }
  else {
    _DAT_1400050f0 = &DAT_140005120;
    DAT_1400050e8 = 0x2080000;
    _DAT_140005110 = param_1;
    RtlCopyUnicodeString(&DAT_1400050e8);
    uVar2 = WdfVersionBind(param_1,&DAT_1400050e8,&DAT_140005010,&WdfDriverGlobals);
    if (-1 < (int)uVar2) {
      _WdfDriverMiniportUnloadOverride = *(undefined1 **)(WdfFunctions_01015 + 0x648);
      uVar1 = FxStubBindClasses((_WDF_BIND_INFO *)&DAT_140005010);
      if (((-1 < (int)uVar1) && (uVar1 = FxStubInitTypes(), -1 < (int)uVar1)) &&
         (uVar1 = DriverEntry(param_1,param_2), -1 < (int)uVar1)) {
        if (*(char *)(WdfDriverGlobals + 0x30) == '\0') {
          if ((*(uint *)(WdfDriverGlobals + 8) & 2) != 0) {
            _WdfDriverMiniportUnloadOverride = &FxStubDriverMiniportUnload;
          }
        }
        else {
          if (*(longlong *)(param_1 + 0x68) != 0) {
            DAT_1400050f8 = *(longlong *)(param_1 + 0x68);
          }
          *(code **)(param_1 + 0x68) = FxStubDriverUnload;
        }
        return 0;
      }
      FxStubDriverUnloadCommon();
      uVar2 = (ulonglong)uVar1;
    }
  }
  return uVar2;
}



===== FxStubDriverUnload @ 140002c5c =====

void FxStubDriverUnload(void)

{
  if ((DAT_1400050f8 != (code *)0x0) && (DAT_1400050f8 != FxStubDriverUnload)) {
    (*DAT_1400050f8)();
  }
  FxStubDriverUnloadCommon();
  return;
}



===== FxStubInitTypes @ 140002c84 =====

/* WARNING: Removing unreachable block (ram,0x000140002cb4) */
/* WARNING: Removing unreachable block (ram,0x000140002cbb) */
/* WARNING: Removing unreachable block (ram,0x000140002ce9) */
/* WARNING: Removing unreachable block (ram,0x000140002cc1) */
/* WARNING: Removing unreachable block (ram,0x000140002cc9) */
/* WARNING: Removing unreachable block (ram,0x000140002ccf) */
/* WARNING: Removing unreachable block (ram,0x000140002ca1) */
/* long __cdecl FxStubInitTypes(void) */

long __cdecl FxStubInitTypes(void)

{
  return 0;
}



===== FxStubBindClasses @ 140002cf0 =====

/* WARNING: Removing unreachable block (ram,0x000140002d17) */
/* long __cdecl FxStubBindClasses(struct _WDF_BIND_INFO * __ptr64) */

long __cdecl FxStubBindClasses(_WDF_BIND_INFO *param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = &_GPIOClx_BIND_INFO;
  while( true ) {
    if ((int *)0x14000509f < piVar2) {
      return iVar1;
    }
    if (*piVar2 != 0x50) break;
    PTR___KMDF_CLASS_BIND_START_1400050a8 = (undefined *)piVar2;
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



===== FxStubUnbindClasses @ 140002d88 =====

/* void __cdecl FxStubUnbindClasses(struct _WDF_BIND_INFO * __ptr64) */

void __cdecl FxStubUnbindClasses(_WDF_BIND_INFO *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = &_GPIOClx_BIND_INFO;
  if (((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_1400050a8 != &__KMDF_CLASS_BIND_START) &&
     ((undefined *)0x14000504f < PTR___KMDF_CLASS_BIND_START_1400050a8)) {
    do {
      if (*(code **)(puVar1 + 0x10) == (code *)0x0) {
        WdfVersionUnbindClass(param_1,WdfDriverGlobals,puVar1);
      }
      else {
        (**(code **)(puVar1 + 0x10))(WdfVersionUnbindClass,param_1,WdfDriverGlobals,puVar1);
      }
      puVar1 = puVar1 + 0x14;
    } while (puVar1 <= PTR___KMDF_CLASS_BIND_START_1400050a8);
  }
  return;
}



===== WdfVersionBind @ 140002e00 =====

void WdfVersionBind(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140002e00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WdfVersionBind();
  return;
}



===== WdfVersionUnbind @ 140002e06 =====

void WdfVersionUnbind(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140002e06. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WdfVersionUnbind();
  return;
}



===== WdfVersionBindClass @ 140002e0c =====

void WdfVersionBindClass(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140002e0c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WdfVersionBindClass();
  return;
}



===== WdfVersionUnbindClass @ 140002e12 =====

void WdfVersionUnbindClass(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140002e12. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WdfVersionUnbindClass();
  return;
}



===== _guard_check_icall @ 140002e18 =====

void _guard_check_icall(void)

{
  return;
}



===== _guard_dispatch_icall @ 140002e30 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140002e30. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== memset @ 140002e40 =====

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
      if (uVar5 == 0) goto LAB_140002f00;
      puVar3 = puVar3 + (uVar5 - 8);
      uVar6 = uVar6 + 1;
      switch(uVar5) {
      case 2:
        goto switchD_140002efd_caseD_2;
      case 3:
        goto switchD_140002efd_caseD_3;
      case 4:
        goto switchD_140002efd_caseD_4;
      case 5:
        goto switchD_140002efd_caseD_5;
      case 6:
        goto switchD_140002efd_caseD_6;
      case 7:
        goto switchD_140002efd_caseD_7;
      }
      while( true ) {
        puVar3[7] = uVar4;
        puVar3 = puVar3 + 8;
        uVar6 = uVar6 - 1;
        if (uVar6 == 0) break;
LAB_140002f00:
        *puVar3 = uVar4;
switchD_140002efd_caseD_7:
        puVar3[1] = uVar4;
switchD_140002efd_caseD_6:
        puVar3[2] = uVar4;
switchD_140002efd_caseD_5:
        puVar3[3] = uVar4;
switchD_140002efd_caseD_4:
        puVar3[4] = uVar4;
switchD_140002efd_caseD_3:
        puVar3[5] = uVar4;
switchD_140002efd_caseD_2:
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



===== AMDGpioEvtDeviceAdd @ 140008000 =====

void AMDGpioEvtDeviceAdd(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 local_res10;
  undefined8 local_res18 [2];
  undefined1 local_48 [64];
  
  local_res10 = param_2;
  iVar1 = (*DAT_140005350)(param_1,param_2,local_48);
  if (-1 < iVar1) {
    iVar1 = (**(code **)(WdfFunctions_01015 + 600))
                      (WdfDriverGlobals,&local_res10,local_48,local_res18);
    if (-1 < iVar1) {
      (*DAT_140005358)(param_1,local_res18[0]);
    }
  }
  return;
}



===== DriverEntry @ 140009000 =====

void DriverEntry(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 local_res18 [2];
  undefined4 local_108 [2];
  code *local_100;
  undefined1 *local_f8;
  undefined4 local_e8 [2];
  undefined4 local_e0;
  code *local_d0;
  code *local_c8;
  code *local_c0;
  code *local_b8;
  undefined1 *local_b0;
  undefined1 *local_a8;
  code *local_a0;
  code *local_98;
  code *local_90;
  code *local_88;
  code *local_80;
  code *local_78;
  code *local_70;
  code *local_68;
  code *local_60;
  code *local_58;
  code *local_50;
  code *local_48;
  code *local_30;
  code *local_28;
  
  memset(local_108,0,0x20);
  local_100 = AMDGpioEvtDeviceAdd;
  local_108[0] = 0x20;
  local_f8 = &AMDGpioEvtDriverUnload;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x3a0))
                    (WdfDriverGlobals,param_1,param_2,0,local_108,local_res18);
  if (-1 < iVar1) {
    memset(local_e8,0,0xd8);
    local_d0 = AMDGpioPrepareController;
    local_e8[0] = 0xd80003;
    local_c0 = AMDGpioStartController;
    local_e0 = 0x420;
    local_b8 = AMDGpioStopController;
    local_c8 = AMDGpioReleaseController;
    local_a8 = &AMDGpioQuerySetControllerInformation;
    local_b0 = &AMDGpioQueryControllerBasicInformation;
    local_98 = AMDGpioDisableInterrupt;
    local_a0 = AMDGpioEnableInterrupt;
    local_88 = AMDGpioMaskInterrupts;
    local_90 = AMDGpioUnmaskInterrupt;
    local_30 = AMDGpioReconfigureInterrupt;
    local_78 = AMDGpioClearActiveInterrupts;
    local_80 = AMDGpioQueryActiveInterrupts;
    local_28 = AMDGpioQueryEnabledInterrupts;
    local_70 = AMDGpioConnectIoPins;
    local_68 = AMDGpioDisconnectIoPins;
    local_60 = AMDGpioReadGpioPins;
    local_58 = AMDGpioWriteGpioPins;
    local_50 = AMDGpioSaveBankHardwareContext;
    local_48 = AMDGpioRestoreBankHardwareContext;
    (*GpioClxExportedInterfaces)(local_res18[0],local_e8,param_2);
  }
  return;
}



===== __security_init_cookie @ 1400091b0 =====

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


