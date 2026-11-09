
===== SMBiosWmiQueryDataBlock @ 1c0001010 =====

void SMBiosWmiQueryDataBlock
               (undefined8 param_1,undefined8 param_2,int param_3,int param_4,int param_5,
               uint *param_6,uint param_7,ushort *param_8)

{
  ushort *puVar1;
  ushort *puVar2;
  ushort uVar3;
  ushort uVar4;
  char cVar5;
  undefined1 uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  undefined4 uVar18;
  
  uVar18 = 0;
  uVar7 = 0;
  if (param_3 == 0) {
    if ((param_4 == 0) && (param_5 == 1)) {
      uVar6 = KeAcquireSpinLockRaiseToDpc(&SMBiosStringLock);
      cVar5 = SMBiosEnableTargetedContentDistribution;
      if (SMBiosEnableTargetedContentDistribution == '\0') {
        uVar7 = 0x30;
      }
      else {
        uVar7 = (uint)DAT_1c00082c2;
        if (DAT_1c00082c2 == 0) {
          uVar7 = 2;
        }
        uVar8 = (uint)DAT_1c00082e2;
        if (DAT_1c00082e2 == 0) {
          uVar8 = 2;
        }
        uVar9 = (uint)DAT_1c0008302;
        if (DAT_1c0008302 == 0) {
          uVar9 = 2;
        }
        uVar10 = (uint)DAT_1c0008322;
        if (DAT_1c0008322 == 0) {
          uVar10 = 2;
        }
        uVar11 = (uint)DAT_1c0008342;
        if (DAT_1c0008342 == 0) {
          uVar11 = 2;
        }
        uVar12 = (uint)DAT_1c0008362;
        if (DAT_1c0008362 == 0) {
          uVar12 = 2;
        }
        uVar13 = (uint)DAT_1c0008382;
        if (DAT_1c0008382 == 0) {
          uVar13 = 2;
        }
        uVar14 = (uint)DAT_1c00083a2;
        if (DAT_1c00083a2 == 0) {
          uVar14 = 2;
        }
        uVar15 = (uint)DAT_1c00083c2;
        if (DAT_1c00083c2 == 0) {
          uVar15 = 2;
        }
        uVar16 = (uint)DAT_1c00083e2;
        if (DAT_1c00083e2 == 0) {
          uVar16 = 2;
        }
        uVar17 = (uint)DAT_1c0008402;
        if (DAT_1c0008402 == 0) {
          uVar17 = 2;
        }
        uVar7 = uVar17 + 0x1a +
                uVar15 + uVar14 + uVar13 + uVar12 + uVar11 + uVar8 + uVar7 + uVar9 + uVar10 + uVar16
        ;
      }
      if ((param_6 == (uint *)0x0) || (param_7 < uVar7)) {
        uVar18 = 0xc0000023;
        KeReleaseSpinLock(&SMBiosStringLock,uVar6);
      }
      else {
        memset(param_8,0,(ulonglong)uVar7);
        uVar3 = DAT_1c00082c2;
        if (cVar5 == '\0') {
          KeReleaseSpinLock(&SMBiosStringLock,uVar6);
          param_8[0] = 2;
          param_8[1] = 0;
          param_8[2] = 2;
          param_8[3] = 0;
          param_8[4] = 2;
          param_8[5] = 0;
          param_8[6] = 2;
          param_8[7] = 0;
          param_8[8] = 2;
          param_8[9] = 0;
          param_8[10] = 2;
          param_8[0xb] = 0;
          param_8[0xc] = 2;
          param_8[0xd] = 0;
          param_8[0xe] = 2;
          param_8[0xf] = 0;
          param_8[0x10] = 2;
          param_8[0x11] = 0;
          param_8[0x12] = 2;
          param_8[0x13] = 0;
          param_8[0x14] = 2;
          param_8[0x15] = 0;
          param_8[0x16] = 0xffff;
          param_8[0x17] = 0xffff;
          *param_6 = uVar7;
        }
        else {
          if (DAT_1c00082c2 == 0) {
            param_8[1] = 0;
            *param_8 = 2;
          }
          else {
            *param_8 = DAT_1c00082c2;
            memmove(param_8 + 1,DAT_1c00082c8,(ulonglong)uVar3);
          }
          uVar4 = DAT_1c00082e2;
          uVar3 = *param_8;
          puVar1 = param_8 + (ulonglong)(uVar3 >> 1) + 1;
          if (DAT_1c00082e2 == 0) {
            *puVar1 = 2;
            param_8[(ulonglong)(uVar3 >> 1) + 2] = 0;
          }
          else {
            *puVar1 = DAT_1c00082e2;
            memmove(param_8 + (ulonglong)(uVar3 >> 1) + 2,DAT_1c00082e8,(ulonglong)uVar4);
          }
          uVar4 = DAT_1c0008302;
          uVar3 = *puVar1;
          puVar2 = puVar1 + (ulonglong)(uVar3 >> 1) + 1;
          if (DAT_1c0008302 == 0) {
            *puVar2 = 2;
            puVar1[(ulonglong)(uVar3 >> 1) + 2] = 0;
          }
          else {
            *puVar2 = DAT_1c0008302;
            memmove(puVar1 + (ulonglong)(uVar3 >> 1) + 2,DAT_1c0008308,(ulonglong)uVar4);
          }
          uVar4 = DAT_1c0008322;
          uVar3 = *puVar2;
          puVar1 = puVar2 + (ulonglong)(uVar3 >> 1) + 1;
          if (DAT_1c0008322 == 0) {
            *puVar1 = 2;
            puVar2[(ulonglong)(uVar3 >> 1) + 2] = 0;
          }
          else {
            *puVar1 = DAT_1c0008322;
            memmove(puVar2 + (ulonglong)(uVar3 >> 1) + 2,DAT_1c0008328,(ulonglong)uVar4);
          }
          uVar4 = DAT_1c0008342;
          uVar3 = *puVar1;
          puVar2 = puVar1 + (ulonglong)(uVar3 >> 1) + 1;
          if (DAT_1c0008342 == 0) {
            *puVar2 = 2;
            puVar1[(ulonglong)(uVar3 >> 1) + 2] = 0;
          }
          else {
            *puVar2 = DAT_1c0008342;
            memmove(puVar1 + (ulonglong)(uVar3 >> 1) + 2,DAT_1c0008348,(ulonglong)uVar4);
          }
          uVar4 = DAT_1c0008362;
          uVar3 = *puVar2;
          puVar1 = puVar2 + (ulonglong)(uVar3 >> 1) + 1;
          if (DAT_1c0008362 == 0) {
            *puVar1 = 2;
            puVar2[(ulonglong)(uVar3 >> 1) + 2] = 0;
          }
          else {
            *puVar1 = DAT_1c0008362;
            memmove(puVar2 + (ulonglong)(uVar3 >> 1) + 2,DAT_1c0008368,(ulonglong)uVar4);
          }
          uVar4 = DAT_1c0008382;
          uVar3 = *puVar1;
          puVar2 = puVar1 + (ulonglong)(uVar3 >> 1) + 1;
          if (DAT_1c0008382 == 0) {
            *puVar2 = 2;
            puVar1[(ulonglong)(uVar3 >> 1) + 2] = 0;
          }
          else {
            *puVar2 = DAT_1c0008382;
            memmove(puVar1 + (ulonglong)(uVar3 >> 1) + 2,DAT_1c0008388,(ulonglong)uVar4);
          }
          uVar4 = DAT_1c00083a2;
          uVar3 = *puVar2;
          puVar1 = puVar2 + (ulonglong)(uVar3 >> 1) + 1;
          if (DAT_1c00083a2 == 0) {
            *puVar1 = 2;
            puVar2[(ulonglong)(uVar3 >> 1) + 2] = 0;
          }
          else {
            *puVar1 = DAT_1c00083a2;
            memmove(puVar2 + (ulonglong)(uVar3 >> 1) + 2,DAT_1c00083a8,(ulonglong)uVar4);
          }
          uVar4 = DAT_1c00083c2;
          uVar3 = *puVar1;
          puVar2 = puVar1 + (ulonglong)(uVar3 >> 1) + 1;
          if (DAT_1c00083c2 == 0) {
            *puVar2 = 2;
            puVar1[(ulonglong)(uVar3 >> 1) + 2] = 0;
          }
          else {
            *puVar2 = DAT_1c00083c2;
            memmove(puVar1 + (ulonglong)(uVar3 >> 1) + 2,DAT_1c00083c8,(ulonglong)uVar4);
          }
          uVar4 = DAT_1c00083e2;
          uVar3 = *puVar2;
          puVar1 = puVar2 + (ulonglong)(uVar3 >> 1) + 1;
          if (DAT_1c00083e2 == 0) {
            *puVar1 = 2;
            puVar2[(ulonglong)(uVar3 >> 1) + 2] = 0;
          }
          else {
            *puVar1 = DAT_1c00083e2;
            memmove(puVar2 + (ulonglong)(uVar3 >> 1) + 2,DAT_1c00083e8,(ulonglong)uVar4);
          }
          uVar4 = DAT_1c0008402;
          uVar3 = *puVar1;
          puVar2 = puVar1 + (ulonglong)(uVar3 >> 1) + 1;
          if (DAT_1c0008402 == 0) {
            *puVar2 = 2;
            puVar1[(ulonglong)(uVar3 >> 1) + 2] = 0;
          }
          else {
            *puVar2 = DAT_1c0008402;
            memmove(puVar1 + (ulonglong)(uVar3 >> 1) + 2,DAT_1c0008408,(ulonglong)uVar4);
          }
          uVar3 = *puVar2 >> 1;
          *(undefined1 *)(puVar2 + (ulonglong)uVar3 + 1) = SMBiosSystemBiosMajorRelease;
          *(undefined1 *)((longlong)puVar2 + (ulonglong)uVar3 * 2 + 3) =
               SMBiosSystemBiosMinorRelease;
          *(undefined1 *)(puVar2 + (ulonglong)uVar3 + 2) = SMBiosSystemECFirmwareMajorRelease;
          *(undefined1 *)((longlong)puVar2 + (ulonglong)uVar3 * 2 + 5) =
               SMBiosSystemECFirmwareMinorRelease;
          KeReleaseSpinLock(&SMBiosStringLock,uVar6);
          *param_6 = uVar7;
        }
      }
    }
    else {
      uVar18 = 0xc0000296;
    }
  }
  else {
    uVar18 = 0xc0000295;
  }
  WmiCompleteRequest(param_1,param_2,uVar18,uVar7,0);
  return;
}



===== SMBiosDriverPower @ 1c00015f0 =====

int SMBiosDriverPower(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  lVar2 = *(longlong *)(param_2 + 0xb8);
  iVar3 = IoAcquireRemoveLockEx(lVar1 + 0x18,param_2,"",1,0x20);
  if (iVar3 < 0) {
    *(int *)(param_2 + 0x30) = iVar3;
    PoStartNextPowerIrp(param_2);
    IofCompleteRequest(param_2,0);
  }
  else {
    if ((*(char *)(lVar2 + 1) == '\x02') && (*(int *)(lVar2 + 0x10) == 1)) {
      PoSetPowerState(param_1,1,*(undefined4 *)(lVar2 + 0x18));
    }
    PoStartNextPowerIrp(param_2);
    *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
    *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
    iVar3 = PoCallDriver(*(undefined8 *)(lVar1 + 8),param_2);
    IoReleaseRemoveLockEx(lVar1 + 0x18,param_2,0x20);
  }
  return iVar3;
}



===== SMBiosDriverWmi @ 1c0001700 =====

ulonglong SMBiosDriverWmi(longlong param_1,longlong param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  int local_res8 [2];
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  local_res8[0] = 0;
  uVar2 = WmiSystemControl(&SMBiosLibInfo,param_1,param_2,local_res8);
  if (local_res8[0] != 0) {
    if (local_res8[0] == 1) {
      IofCompleteRequest(param_2,0);
      uVar2 = uVar2 & 0xffffffff;
    }
    else {
      *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
      *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
      uVar2 = IofCallDriver(*(undefined8 *)(lVar1 + 8),param_2);
    }
  }
  return uVar2;
}



===== SMBiosWriteSystemInformationRegistry @ 1c00017a0 =====

void SMBiosWriteSystemInformationRegistry(void)

{
  uint uVar1;
  int iVar2;
  undefined2 *puVar3;
  char cVar4;
  uint local_res8 [2];
  longlong local_res10;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  longlong lStack_60;
  undefined8 local_58;
  longlong lStack_50;
  undefined8 local_48;
  longlong lStack_40;
  undefined8 local_38;
  longlong lStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  
  local_res8[0] = 0;
  local_38 = 0;
  lStack_30 = 0;
  local_48 = 0;
  lStack_40 = 0;
  local_58 = 0;
  lStack_50 = 0;
  local_68 = 0;
  lStack_60 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_78 = 0;
  uStack_70 = 0;
  RtlInitUnicodeString(&local_38,0);
  RtlInitUnicodeString(&local_48,0);
  RtlInitUnicodeString(&local_58,0);
  RtlInitUnicodeString(&local_68,0);
  RtlInitUnicodeString
            (&local_28,L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\SystemInformation"
            );
  local_res10 = 0;
  KeAcquireSpinLockRaiseToDpc(&SMBiosStringLock);
  if ((DAT_1c0008328 == (void *)0x0) || (uVar1 = (uint)DAT_1c0008322, DAT_1c0008322 == 0)) {
LAB_1c00018a6:
    puVar3 = (undefined2 *)ExAllocatePool2(0x42,2,0x69424d53);
    if (puVar3 != (undefined2 *)0x0) {
      *puVar3 = 0;
    }
  }
  else {
    puVar3 = (undefined2 *)ExAllocatePool2(0x42,uVar1,0x69424d53);
    if (puVar3 == (undefined2 *)0x0) goto LAB_1c00018a6;
    memmove(puVar3,DAT_1c0008328,(ulonglong)uVar1);
  }
  RtlInitUnicodeString(&local_38,puVar3);
  if ((DAT_1c0008368 == (void *)0x0) || (uVar1 = (uint)DAT_1c0008362, DAT_1c0008362 == 0)) {
LAB_1c000192b:
    puVar3 = (undefined2 *)ExAllocatePool2(0x42,2,0x69424d53);
    if (puVar3 != (undefined2 *)0x0) {
      *puVar3 = 0;
    }
  }
  else {
    puVar3 = (undefined2 *)ExAllocatePool2(0x42,uVar1,0x69424d53);
    if (puVar3 == (undefined2 *)0x0) goto LAB_1c000192b;
    memmove(puVar3,DAT_1c0008368,(ulonglong)uVar1);
  }
  RtlInitUnicodeString(&local_48,puVar3);
  if ((DAT_1c00083a8 == (void *)0x0) || (uVar1 = (uint)DAT_1c00083a2, DAT_1c00083a2 == 0)) {
LAB_1c00019b0:
    puVar3 = (undefined2 *)ExAllocatePool2(0x42,2,0x69424d53);
    if (puVar3 != (undefined2 *)0x0) {
      *puVar3 = 0;
    }
  }
  else {
    puVar3 = (undefined2 *)ExAllocatePool2(0x42,uVar1,0x69424d53);
    if (puVar3 == (undefined2 *)0x0) goto LAB_1c00019b0;
    memmove(puVar3,DAT_1c00083a8,(ulonglong)uVar1);
  }
  RtlInitUnicodeString(&local_58,puVar3);
  if ((DAT_1c00083c8 != (void *)0x0) && (uVar1 = (uint)DAT_1c00083c2, DAT_1c00083c2 != 0)) {
    puVar3 = (undefined2 *)ExAllocatePool2(0x42,uVar1,0x69424d53);
    if (puVar3 != (undefined2 *)0x0) {
      memmove(puVar3,DAT_1c00083c8,(ulonglong)uVar1);
      goto LAB_1c0001a5a;
    }
  }
  puVar3 = (undefined2 *)ExAllocatePool2(0x42,2,0x69424d53);
  if (puVar3 != (undefined2 *)0x0) {
    *puVar3 = 0;
  }
LAB_1c0001a5a:
  RtlInitUnicodeString(&local_68,puVar3);
  KeReleaseSpinLock(&SMBiosStringLock);
  iVar2 = SMBiosRegistryCreateHandleW(&local_28,0,&local_res10);
  if (iVar2 < 0) {
    local_res10 = 0;
  }
  else {
    cVar4 = (short)local_48 != 0;
    if ((bool)cVar4) {
      RtlInitUnicodeString(&local_78,L"BIOSVersion");
      ZwSetValueKey(local_res10,&local_78,0,1,lStack_40,local_48._2_2_);
    }
    if ((short)local_38 != 0) {
      cVar4 = cVar4 + '\x01';
      RtlInitUnicodeString(&local_78,L"BIOSReleaseDate");
      ZwSetValueKey(local_res10,&local_78,0,1,lStack_30,local_38._2_2_);
    }
    if ((short)local_58 != 0) {
      cVar4 = cVar4 + '\x01';
      RtlInitUnicodeString(&local_78,L"SystemManufacturer");
      ZwSetValueKey(local_res10,&local_78,0,1,lStack_50,local_58._2_2_);
    }
    if ((short)local_68 != 0) {
      cVar4 = cVar4 + '\x01';
      RtlInitUnicodeString(&local_78,L"SystemProductName");
      ZwSetValueKey(local_res10,&local_78,0,1,lStack_60,local_68._2_2_);
    }
    if (cVar4 != '\0') {
      local_res8[0] = (uint)(SMBiosEnableTargetedContentDistribution != '\0');
      RtlInitUnicodeString(&local_78,L"InformationSource");
      ZwSetValueKey(local_res10,&local_78,0,4,local_res8,4);
    }
    SMBiosHardwareIdsSaveToRegistry(local_res10);
    if (local_res10 != 0) {
      ZwClose();
    }
  }
  if (lStack_60 != 0) {
    ExFreePoolWithTag(lStack_60,0x69424d53);
  }
  if (lStack_50 != 0) {
    ExFreePoolWithTag(lStack_50,0x69424d53);
  }
  if (lStack_40 != 0) {
    ExFreePoolWithTag(lStack_40,0x69424d53);
  }
  if (lStack_30 != 0) {
    ExFreePoolWithTag(lStack_30,0x69424d53);
  }
  return;
}



===== SMBiosSMBiosSaveBiosString @ 1c0001cf0 =====

undefined8
SMBiosSMBiosSaveBiosString(longlong param_1,int param_2,ulonglong param_3,longlong param_4)

{
  undefined1 uVar1;
  short *psVar2;
  undefined8 uVar3;
  ushort *_Dst;
  ushort *puVar4;
  uint uVar5;
  char *_Str;
  undefined8 local_38;
  void *pvStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  
  _Dst = (ushort *)0x0;
  local_28 = 0;
  uStack_20 = 0;
  local_38 = 0;
  pvStack_30 = (void *)0x0;
  if (param_2 == 0) {
    uVar3 = 0;
  }
  else {
    _Str = (char *)((ulonglong)*(byte *)(param_1 + 1) + param_1);
    for (uVar5 = 0; uVar5 < param_2 - 1U; uVar5 = uVar5 + 1) {
      psVar2 = (short *)strchr(_Str,0);
      _Str = (char *)((longlong)psVar2 + 1);
      if (((char *)((param_3 & 0xffffffff) + param_1) <= _Str) || (*psVar2 == 0)) {
        return 0xc0000034;
      }
    }
    RtlInitUnicodeString(&local_38,0);
    RtlInitAnsiString(&local_28,_Str);
    uVar3 = RtlAnsiStringToUnicodeString(&local_38,&local_28,1);
    if (-1 < (int)uVar3) {
      if (1 < local_38._2_2_) {
        _Dst = (ushort *)ExAllocatePool2(0x42,local_38._2_2_,0x69424d53);
        if (_Dst == (ushort *)0x0) {
          RtlFreeUnicodeString(&local_38);
          return 0xc000009a;
        }
        memmove(_Dst,pvStack_30,local_38 >> 0x10 & 0xffff);
        for (puVar4 = _Dst + ((local_38 >> 0x11 & 0x7fff) - 1);
            (_Dst <= puVar4 && ((*puVar4 & 0xffdf) == 0)); puVar4 = puVar4 + -1) {
          *puVar4 = 0;
        }
      }
      RtlFreeUnicodeString(&local_38);
      uVar1 = KeAcquireSpinLockRaiseToDpc(&SMBiosStringLock);
      if (*(longlong *)(param_4 + 8) != 0) {
        ExFreePoolWithTag(*(longlong *)(param_4 + 8),0);
      }
      if (_Dst != (ushort *)0x0) {
        RtlInitUnicodeString(param_4,_Dst);
      }
      KeReleaseSpinLock(&SMBiosStringLock,uVar1);
      uVar3 = 0;
    }
  }
  return uVar3;
}



===== SMBiosCPUCaptureRegistersForDumpArch @ 1c0001ee0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SMBiosCPUCaptureRegistersForDumpArch(int *param_1,char param_2)

{
  undefined8 uVar1;
  longlong lVar2;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  lVar2 = 0x18;
  if (param_2 == '\0') {
    lVar2 = 8;
  }
  if (*param_1 == 0) {
    SMBiosCPUID(param_1[1],(undefined4 *)(lVar2 + (longlong)param_1));
  }
  else if (*param_1 == 1) {
    if (param_1[1] == 0x8b) {
      local_28 = 0;
      uStack_20 = 0;
      wrmsr(0x8b,0);
      SMBiosCPUID(1,(undefined4 *)&local_28);
    }
    uVar1 = rdmsr(param_1[1]);
    *(undefined8 *)(lVar2 + (longlong)param_1) = uVar1;
  }
  return;
}



===== SMBiosStringsSaveToRegistry @ 1c0001f80 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 SMBiosStringsSaveToRegistry(undefined8 param_1)

{
  ushort uVar1;
  undefined1 uVar2;
  void *_Dst;
  undefined2 *puVar3;
  undefined1 *puVar4;
  uint *puVar5;
  longlong lVar6;
  longlong *plVar7;
  undefined **ppuVar8;
  uint uVar9;
  ulonglong uVar10;
  undefined1 auStack_128 [32];
  undefined8 local_108;
  undefined8 uStack_100;
  uint local_f8 [4];
  undefined1 local_e8 [2];
  ushort local_e6 [3];
  longlong local_e0 [21];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_128;
  local_f8[0] = 0xff;
  local_f8[1] = 0xff;
  local_f8[2] = 0xff;
  local_108 = 0;
  uStack_100 = 0;
  local_f8[3] = 0xff;
  uVar2 = KeAcquireSpinLockRaiseToDpc(&SMBiosStringLock);
  if (SMBiosEnableTargetedContentDistribution == '\0') {
    KeReleaseSpinLock(&SMBiosStringLock,uVar2);
  }
  else {
    local_f8[0] = (uint)SMBiosSystemBiosMajorRelease;
    puVar4 = local_e8;
    lVar6 = 0xb;
    local_f8[1] = (uint)SMBiosSystemBiosMinorRelease;
    plVar7 = &DAT_1c00082c8;
    local_f8[2] = (uint)SMBiosSystemECFirmwareMajorRelease;
    uVar10 = 0;
    local_f8[3] = (uint)SMBiosSystemECFirmwareMinorRelease;
    do {
      RtlInitUnicodeString(puVar4,0);
      if (((plVar7 == (longlong *)0x8) || (*plVar7 == 0)) ||
         (uVar1 = *(ushort *)((longlong)plVar7 + -6), uVar1 == 0)) {
LAB_1c00020bc:
        puVar3 = (undefined2 *)ExAllocatePool2(0x42,2,0x69424d53);
        if (puVar3 != (undefined2 *)0x0) {
          *puVar3 = 0;
        }
      }
      else {
        _Dst = (void *)ExAllocatePool2(0x42,(uint)uVar1,0x69424d53);
        if (_Dst == (void *)0x0) goto LAB_1c00020bc;
        memmove(_Dst,(void *)*plVar7,(ulonglong)(uint)uVar1);
      }
      RtlInitUnicodeString(puVar4);
      puVar4 = puVar4 + 0x10;
      plVar7 = plVar7 + 4;
      lVar6 = lVar6 + -1;
    } while (lVar6 != 0);
    KeReleaseSpinLock(&SMBiosStringLock,uVar2);
    puVar5 = local_f8;
    lVar6 = 4;
    ppuVar8 = &SMBiosIntegerTableNames;
    do {
      RtlInitUnicodeString(&local_108,*ppuVar8);
      SMBiosRegistryWriteIntegerW(&local_108,param_1,*puVar5);
      ppuVar8 = ppuVar8 + 1;
      puVar5 = puVar5 + 1;
      lVar6 = lVar6 + -1;
    } while (lVar6 != 0);
    if ((SMBiosSystemChassisType & 0x7f) != 0) {
      RtlInitUnicodeString(&local_108,L"EnclosureType");
      SMBiosRegistryWriteIntegerW(&local_108,param_1,SMBiosSystemChassisType & 0x7f);
    }
    plVar7 = local_e0;
    do {
      if (*plVar7 != 0) {
        SMBiosRegistryWriteStringW
                  (&DAT_1c00082d0 + uVar10 * 0x20,param_1,*plVar7,
                   (uint)*(ushort *)((longlong)plVar7 + -6));
        ExFreePoolWithTag(*plVar7,0);
      }
      uVar9 = (int)uVar10 + 1;
      uVar10 = (ulonglong)uVar9;
      plVar7 = plVar7 + 2;
    } while (uVar9 < 0xb);
  }
  return 0;
}



===== SMBiosDataAddPageableObject @ 1c0002260 =====

ulonglong SMBiosDataAddPageableObject(undefined8 param_1,void *param_2,uint param_3)

{
  void *_Dst;
  ulonglong uVar1;
  
  _Dst = (void *)ExAllocatePool2(0x42,(ulonglong)param_3,0x69424d53);
  if (_Dst == (void *)0x0) {
    uVar1 = 0xc000009a;
  }
  else {
    memmove(_Dst,param_2,(ulonglong)param_3);
    uVar1 = SMBiosDataAddObject(0x1c0008440,_Dst,param_3);
    uVar1 = uVar1 & 0xffffffff;
    ExFreePoolWithTag(_Dst,0);
  }
  return uVar1;
}



===== SMBiosCPUProbeRegisterForDump @ 1c0002300 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SMBiosCPUProbeRegisterForDump(int param_1,int param_2)

{
  undefined1 auStack_78 [40];
  int local_50;
  int local_4c;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_78;
  local_48 = 0;
  local_40 = 0;
  uStack_38 = 0;
  local_30 = 0;
  local_50 = param_1;
  local_4c = param_2;
  if (param_1 == 0) {
    SMBiosCPUID(param_2,(undefined4 *)&local_48);
  }
  else if (param_1 == 1) {
    if (param_2 == 0x8b) {
      local_28 = 0;
      uStack_20 = 0;
      wrmsr(0x8b,0);
      SMBiosCPUID(1,(undefined4 *)&local_28);
    }
    local_48 = rdmsr(local_4c);
  }
  SMBiosDataAddObject(0x1c0008540,&local_50,0x28);
  return;
}



===== SMBiosDataAddObject @ 1c00023c0 =====

undefined8 SMBiosDataAddObject(longlong param_1,void *param_2,uint param_3)

{
  uint uVar1;
  undefined1 uVar2;
  void *_Dst;
  undefined8 uVar3;
  uint uVar4;
  
  uVar3 = 0;
  uVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x30);
  if ((*(uint *)(param_1 + 4) & 1) != 0) {
    uVar3 = 0xc0000033;
    goto LAB_1c00024ae;
  }
  uVar1 = *(uint *)(param_1 + 0x2c);
  if (uVar1 - *(int *)(param_1 + 0x28) < param_3) {
    uVar4 = (param_3 & 0xfffff000) + 0x1000 + uVar1;
    if (uVar4 < uVar1) {
      uVar3 = 0xc0000095;
      goto LAB_1c00024ae;
    }
    _Dst = (void *)ExAllocatePool2(0x40,uVar4,0x69424d53);
    if (_Dst == (void *)0x0) {
      uVar3 = 0xc000009a;
      goto LAB_1c00024ae;
    }
    if (*(void **)(param_1 + 0x38) != (void *)0x0) {
      memmove(_Dst,*(void **)(param_1 + 0x38),(ulonglong)*(uint *)(param_1 + 0x28));
      ExFreePoolWithTag(*(undefined8 *)(param_1 + 0x38),0);
    }
    *(void **)(param_1 + 0x38) = _Dst;
    *(uint *)(param_1 + 0x2c) = uVar4;
  }
  memmove((void *)((ulonglong)*(uint *)(param_1 + 0x28) + *(longlong *)(param_1 + 0x38)),param_2,
          (ulonglong)param_3);
  *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + param_3;
LAB_1c00024ae:
  KeReleaseSpinLock(param_1 + 0x30,uVar2);
  return uVar3;
}



===== SMBiosDataSaveObjects @ 1c00024e0 =====

int SMBiosDataSaveObjects(undefined8 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = SMBiosDataSaveObject(0x1c0008500,param_1);
  iVar2 = 0;
  if (iVar1 < 0) {
    iVar2 = iVar1;
  }
  iVar1 = SMBiosDataSaveObject(0x1c0008480,param_1);
  if (iVar1 < 0) {
    iVar2 = iVar1;
  }
  iVar1 = SMBiosDataSaveObject(0x1c0008540,param_1);
  if (iVar1 < 0) {
    iVar2 = iVar1;
  }
  iVar1 = SMBiosDataSaveObject(0x1c0008440,param_1);
  if (iVar1 < 0) {
    iVar2 = iVar1;
  }
  return iVar2;
}



===== SMBiosDataSaveObject @ 1c0002560 =====

undefined4 SMBiosDataSaveObject(longlong param_1,undefined8 param_2)

{
  uint uVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  void *_Dst;
  
  uVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x30);
  if ((*(uint *)(param_1 + 4) & 3) == 0) {
    uVar1 = *(uint *)(param_1 + 0x28);
    if (uVar1 != 0) {
      _Dst = (void *)ExAllocatePool2(0x42,(ulonglong)uVar1,0x69424d53);
      if (_Dst == (void *)0x0) {
        KeReleaseSpinLock(param_1 + 0x30,uVar2);
        return 0xc000009a;
      }
      memmove(_Dst,*(void **)(param_1 + 0x38),(ulonglong)uVar1);
      KeReleaseSpinLock(param_1 + 0x30,uVar2);
      uVar3 = SMBiosRegistryWriteValueW(param_1 + 8,param_2,_Dst,uVar1);
      ExFreePoolWithTag(_Dst,0);
      return uVar3;
    }
  }
  KeReleaseSpinLock(param_1 + 0x30,uVar2);
  return 0;
}



===== SMBiosCPUGatherDataQueryRoutine @ 1c0002680 =====

undefined8
SMBiosCPUGatherDataQueryRoutine(void *param_1,undefined4 param_2,void *param_3,uint param_4)

{
  longlong lVar1;
  undefined1 uVar2;
  longlong lVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  undefined *puVar6;
  uint local_res8 [2];
  undefined4 local_res10 [2];
  uint local_res20 [2];
  
  if (param_1 != (void *)0x0) {
    lVar3 = -1;
    do {
      lVar1 = lVar3 * 2;
      lVar3 = lVar3 + 1;
    } while (*(short *)((longlong)param_1 + lVar1 + 2) != 0);
    local_res8[0] = (int)lVar3 * 2 + 2;
    if (2 < local_res8[0]) {
      puVar6 = &SMBiosDriverRegistryObject;
      local_res10[0] = param_2;
      local_res20[0] = param_4;
      uVar4 = SMBiosDataAddObject(0x1c0008440,local_res8,4);
      if (((-1 < (int)uVar4) &&
          (uVar5 = SMBiosDataAddPageableObject(puVar6,param_1,local_res8[0]), -1 < (int)uVar5)) &&
         (uVar4 = SMBiosDataAddObject(0x1c0008440,local_res10,4), -1 < (int)uVar4)) {
        puVar6 = &SMBiosDriverRegistryObject;
        uVar4 = SMBiosDataAddObject(0x1c0008440,local_res20,4);
        if ((-1 < (int)uVar4) &&
           (uVar5 = SMBiosDataAddPageableObject(puVar6,param_3,local_res20[0]), -1 < (int)uVar5)) {
          return 0;
        }
      }
      uVar2 = KeAcquireSpinLockRaiseToDpc(&DAT_1c0008470);
      DAT_1c0008444 = DAT_1c0008444 | 2;
      KeReleaseSpinLock(&DAT_1c0008470,uVar2);
    }
  }
  return 0;
}



===== SMBiosACPIProcessACPIData @ 1c0002790 =====

int SMBiosACPIProcessACPIData(void)

{
  int iVar1;
  uint uVar2;
  undefined8 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined4 local_res8 [2];
  
  puVar3 = (undefined8 *)0x0;
  local_res8[0] = 0;
  puVar4 = (undefined4 *)0x0;
  uVar6 = 0;
  do {
    if (puVar3 != (undefined8 *)0x0) {
      ExFreePoolWithTag(puVar3,0);
    }
    puVar3 = (undefined8 *)ExAllocatePool2(0x42,uVar6 + 0x14,0x69424d53);
    if (puVar3 == (undefined8 *)0x0) {
      return -0x3fffff66;
    }
    *puVar3 = 0x41435049;
    *(undefined4 *)(puVar3 + 1) = 0;
    *(uint *)((longlong)puVar3 + 0xc) = uVar6;
    iVar1 = ZwQuerySystemInformation(0x4c,puVar3,uVar6 + 0x14,local_res8);
    if (((iVar1 + 0x80000000U & 0x80000000) == 0) && (iVar1 != -0x3fffffdd)) {
      ExFreePoolWithTag(puVar3,0);
      return iVar1;
    }
    uVar6 = *(uint *)((longlong)puVar3 + 0xc);
  } while (iVar1 == -0x3fffffdd);
  if (uVar6 == 0) {
    ExFreePoolWithTag(puVar3,0);
    iVar1 = 0;
  }
  else {
    for (uVar8 = 0; uVar8 < uVar6 >> 2; uVar8 = uVar8 + 1) {
      iVar5 = 0;
      do {
        if (puVar4 != (undefined4 *)0x0) {
          ExFreePoolWithTag(puVar4,0);
        }
        puVar4 = (undefined4 *)ExAllocatePool2(0x42,iVar5 + 0x14,0x69424d53);
        if (puVar4 == (undefined4 *)0x0) {
          ExFreePoolWithTag(puVar3,0);
          return -0x3fffff66;
        }
        *puVar4 = 0x41435049;
        puVar4[1] = 1;
        puVar4[2] = *(undefined4 *)((longlong)puVar3 + (ulonglong)uVar8 * 4 + 0x10);
        puVar4[3] = iVar5;
        iVar1 = ZwQuerySystemInformation(0x4c,puVar4,iVar5 + 0x14,local_res8);
        if (((iVar1 + 0x80000000U & 0x80000000) == 0) && (iVar1 != -0x3fffffdd)) goto LAB_1c00029ad;
        iVar5 = puVar4[3];
      } while (iVar1 == -0x3fffffdd);
      if (iVar5 != 0) {
        if ((0xf < puVar4[4] + 0xabbbacbc) ||
           (uVar2 = 0x24, (0x9001U >> (puVar4[4] + 0xabbbacbc & 0x1f) & 1) == 0)) {
          uVar2 = puVar4[5];
        }
        uVar7 = uVar6;
        if (uVar2 <= uVar6) {
          uVar7 = uVar2;
        }
        if (uVar7 != 0) {
          SMBiosDataAddObject(0x1c0008500,puVar4 + 4,uVar7);
        }
      }
    }
LAB_1c00029ad:
    ExFreePoolWithTag(puVar3,0);
    if (puVar4 != (undefined4 *)0x0) {
      ExFreePoolWithTag(puVar4,0);
    }
  }
  return iVar1;
}



===== SMBiosStringsResetStrings @ 1c0002a00 =====

void SMBiosStringsResetStrings(void)

{
  undefined1 uVar1;
  uint uVar2;
  longlong *plVar3;
  ulonglong uVar4;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(&SMBiosStringLock);
  uVar4 = 0;
  plVar3 = &DAT_1c00082c8;
  uVar2 = 0;
  do {
    if (*plVar3 != 0) {
      ExFreePoolWithTag(*plVar3,0);
      RtlInitUnicodeString(&SMBiosStrings + (ulonglong)uVar2 * 0x20);
    }
    uVar2 = uVar2 + 1;
    plVar3 = plVar3 + 4;
  } while (uVar2 < 0xb);
  plVar3 = &DAT_1c0008208;
  do {
    if (*plVar3 != 0) {
      ExFreePoolWithTag(*plVar3,0);
      RtlInitUnicodeString(&SMBiosHardwareIds + uVar4 * 0x10);
    }
    uVar2 = (int)uVar4 + 1;
    uVar4 = (ulonglong)uVar2;
    plVar3 = plVar3 + 2;
  } while (uVar2 < 10);
  if (DAT_1c00082a8 != 0) {
    ExFreePoolWithTag(DAT_1c00082a8,0);
    RtlInitUnicodeString(&SMBiosComputerId,0);
  }
  SMBiosSystemBiosMajorRelease = 0xff;
  SMBiosSystemBiosMinorRelease = 0xff;
  SMBiosSystemECFirmwareMajorRelease = 0xff;
  SMBiosSystemECFirmwareMinorRelease = 0xff;
  SMBiosEnableTargetedContentDistribution = 0;
  KeReleaseSpinLock(&SMBiosStringLock,uVar1);
  SMBiosStringsDeleteFromRegistry();
  return;
}



===== SMBiosCPUGatherRegisters @ 1c0002b50 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int SMBiosCPUGatherRegisters(void)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char cVar4;
  int iVar5;
  char *pcVar6;
  ulonglong uVar7;
  longlong lVar8;
  undefined1 auStack_68 [32];
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  iVar5 = 0;
  cVar4 = SMBiosCPUIDIsPresent();
  if (cVar4 == '\0') {
    return 0;
  }
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  SMBiosCPUID(0,(undefined4 *)&local_38);
  SMBiosCPUID(-0x80000000,(undefined4 *)&local_28);
  uVar2 = (uint)local_38;
  uVar3 = (uint)local_28;
  local_48 = local_38._4_4_;
  local_44 = uStack_30._4_4_;
  local_40 = (undefined4)uStack_30;
  local_3c = 0;
  if ((uint)local_38 != 0) {
    iVar5 = SMBiosCPUGatherCPUID(0,(uint)local_38);
    if (iVar5 < 0) {
      return iVar5;
    }
    pcVar6 = (char *)&local_48;
    lVar8 = (longlong)"GenuineIntel" - (longlong)pcVar6;
    do {
      cVar4 = *pcVar6;
      cVar1 = pcVar6[lVar8];
      if (cVar4 != cVar1) break;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    if (cVar4 == cVar1) {
      uVar7 = SMBiosCPUGatherIntelMSRs(uVar2,uVar3);
      iVar5 = (int)uVar7;
    }
    else {
      pcVar6 = (char *)&local_48;
      lVar8 = (longlong)"AuthenticAMD" - (longlong)pcVar6;
      do {
        cVar4 = *pcVar6;
        cVar1 = pcVar6[lVar8];
        if (cVar4 != cVar1) break;
        pcVar6 = pcVar6 + 1;
      } while (cVar1 != '\0');
      if (cVar4 == cVar1) {
        iVar5 = SMBiosCPUGatherAmdMSRs(uVar2,uVar3);
      }
      else {
        pcVar6 = (char *)&local_48;
        lVar8 = (longlong)"TransmetaCPU" - (longlong)pcVar6;
        do {
          cVar4 = *pcVar6;
          cVar1 = pcVar6[lVar8];
          if (cVar4 != cVar1) break;
          pcVar6 = pcVar6 + 1;
        } while (cVar1 != '\0');
        if (cVar4 != cVar1) {
          pcVar6 = (char *)&local_48;
          lVar8 = (longlong)"GenuineTMx86" - (longlong)pcVar6;
          do {
            cVar4 = *pcVar6;
            cVar1 = pcVar6[lVar8];
            if (cVar4 != cVar1) break;
            pcVar6 = pcVar6 + 1;
          } while (cVar1 != '\0');
          if (cVar4 != cVar1) goto LAB_1c0002ce7;
        }
        local_38 = 0;
        uStack_30 = 0;
        SMBiosCPUID(-0x7f7a0000,(undefined4 *)&local_38);
        if ((uint)local_38 < 0x80860000) goto LAB_1c0002ce7;
        iVar5 = SMBiosCPUGatherCPUID(0x80860000,(uint)local_38);
      }
    }
    if (iVar5 < 0) {
      return iVar5;
    }
  }
LAB_1c0002ce7:
  if (0x7fffffff < uVar3) {
    iVar5 = SMBiosCPUGatherCPUID(0x80000000,uVar3);
  }
  return iVar5;
}



===== SMBiosCPUGatherCPUID @ 1c0002d30 =====

int SMBiosCPUGatherCPUID(uint param_1,uint param_2)

{
  int iVar1;
  
  while( true ) {
    if (param_2 < param_1) {
      return 0;
    }
    if (((param_1 != 3) &&
        (iVar1 = SMBiosCPUProbeRegisterForDump(0,param_1), (iVar1 + 0x80000000U & 0x80000000) == 0))
       && (iVar1 != -0x3fffffe3)) break;
    param_1 = param_1 + 1;
  }
  return iVar1;
}



===== RtlStringCchPrintfW @ 1c0002d90 =====

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
      param_1[_Count] = L'\0';
      uVar2 = 0x80000005;
    }
    else if ((longlong)iVar1 == _Count) {
      param_1[_Count] = L'\0';
    }
  }
  else {
    uVar2 = 0xc000000d;
    if (param_2 != 0) {
      *param_1 = L'\0';
    }
  }
  return uVar2;
}



===== SMBiosDriverPnpComplete @ 1c0002e20 =====

undefined8 SMBiosDriverPnpComplete(longlong param_1,longlong param_2,longlong param_3)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  if (-1 < *(int *)(param_2 + 0x30)) {
    if (param_3 != 0) {
      IoQueueWorkItemEx(param_3,SMBiosDriverStartDeviceWorker,1,param_2);
      return 0xc0000016;
    }
    *(undefined4 *)(param_2 + 0x30) = 0xc000009a;
  }
  IoReleaseRemoveLockEx(lVar1 + 0x18,param_2,0x20);
  return 0;
}



===== SMBiosDataInitializeObject @ 1c0002e90 =====

undefined8
SMBiosDataInitializeObject
          (undefined8 *param_1,undefined8 param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  longlong lVar4;
  undefined8 uVar5;
  
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  KeInitializeSpinLock(param_1 + 6);
  RtlInitUnicodeString(param_1 + 1,param_2);
  *(undefined4 *)param_1 = param_3;
  uVar1 = param_4[1];
  uVar2 = param_4[2];
  uVar3 = param_4[3];
  *(undefined4 *)(param_1 + 3) = *param_4;
  *(undefined4 *)((longlong)param_1 + 0x1c) = uVar1;
  *(undefined4 *)(param_1 + 4) = uVar2;
  *(undefined4 *)((longlong)param_1 + 0x24) = uVar3;
  lVar4 = ExAllocatePool2(0x40,0x1000,0x69424d53);
  param_1[7] = lVar4;
  if (lVar4 == 0) {
    uVar5 = 0xc000009a;
  }
  else {
    *(undefined4 *)((longlong)param_1 + 0x2c) = 0x1000;
    uVar5 = 0;
  }
  return uVar5;
}



===== SMBiosStringsDeleteFromRegistry @ 1c0002f40 =====

int SMBiosStringsDeleteFromRegistry(void)

{
  int iVar1;
  longlong local_res8;
  longlong local_res10 [3];
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res8 = 0;
  local_res10[0] = 0;
  local_18 = 0;
  uStack_10 = 0;
  local_28 = 0;
  uStack_20 = 0;
  RtlInitUnicodeString(&local_28);
  iVar1 = SMBiosRegistryOpenHandleW(&local_28,0,local_res10);
  if (-1 < iVar1) {
    RtlInitUnicodeString(&local_18,L"BIOS");
    iVar1 = SMBiosRegistryOpenHandleW(&local_18,local_res10[0],&local_res8);
    if (-1 < iVar1) {
      iVar1 = ZwDeleteKey(local_res8);
    }
  }
  if (local_res8 != 0) {
    ZwClose();
  }
  if (local_res10[0] != 0) {
    ZwClose();
  }
  return iVar1;
}



===== SMBiosHardwareIdsSaveToRegistry @ 1c0003020 =====

int SMBiosHardwareIdsSaveToRegistry(undefined8 param_1)

{
  undefined1 uVar1;
  int iVar2;
  undefined2 *_Dst;
  void *_Dst_00;
  undefined *puVar3;
  uint uVar4;
  uint uVar5;
  undefined2 *_Dst_01;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(&SMBiosStringLock);
  if (DAT_1c00082a2 == 0) {
    KeReleaseSpinLock(&SMBiosStringLock,uVar1);
    return -0x3ffffff3;
  }
  uVar4 = (uint)DAT_1c0008202;
  if (DAT_1c0008202 == 0) {
    uVar4 = 0;
  }
  if (DAT_1c0008212 != 0) {
    uVar4 = uVar4 + DAT_1c0008212;
  }
  if (DAT_1c0008222 != 0) {
    uVar4 = uVar4 + DAT_1c0008222;
  }
  if (DAT_1c0008232 != 0) {
    uVar4 = uVar4 + DAT_1c0008232;
  }
  if (DAT_1c0008242 != 0) {
    uVar4 = uVar4 + DAT_1c0008242;
  }
  if (DAT_1c0008252 != 0) {
    uVar4 = uVar4 + DAT_1c0008252;
  }
  if (DAT_1c0008262 != 0) {
    uVar4 = uVar4 + DAT_1c0008262;
  }
  if (DAT_1c0008272 != 0) {
    uVar4 = uVar4 + DAT_1c0008272;
  }
  if (DAT_1c0008282 != 0) {
    uVar4 = uVar4 + DAT_1c0008282;
  }
  if (DAT_1c0008292 != 0) {
    uVar4 = uVar4 + DAT_1c0008292;
  }
  _Dst = (undefined2 *)ExAllocatePool2(0x42,uVar4 + 2,0x69424d53);
  if (_Dst == (undefined2 *)0x0) {
    KeReleaseSpinLock(&SMBiosStringLock,uVar1);
    iVar2 = -0x3fffffe9;
  }
  else {
    _Dst_01 = _Dst;
    if (DAT_1c0008202 != 0) {
      memmove(_Dst,DAT_1c0008208,(ulonglong)DAT_1c0008202);
      _Dst_01 = _Dst + (DAT_1c0008202 >> 1);
    }
    if (DAT_1c0008212 != 0) {
      memmove(_Dst_01,DAT_1c0008218,(ulonglong)DAT_1c0008212);
      _Dst_01 = _Dst_01 + (DAT_1c0008212 >> 1);
    }
    if (DAT_1c0008222 != 0) {
      memmove(_Dst_01,DAT_1c0008228,(ulonglong)DAT_1c0008222);
      _Dst_01 = _Dst_01 + (DAT_1c0008222 >> 1);
    }
    if (DAT_1c0008232 != 0) {
      memmove(_Dst_01,DAT_1c0008238,(ulonglong)DAT_1c0008232);
      _Dst_01 = _Dst_01 + (DAT_1c0008232 >> 1);
    }
    if (DAT_1c0008242 != 0) {
      memmove(_Dst_01,DAT_1c0008248,(ulonglong)DAT_1c0008242);
      _Dst_01 = _Dst_01 + (DAT_1c0008242 >> 1);
    }
    if (DAT_1c0008252 != 0) {
      memmove(_Dst_01,DAT_1c0008258,(ulonglong)DAT_1c0008252);
      _Dst_01 = _Dst_01 + (DAT_1c0008252 >> 1);
    }
    if (DAT_1c0008262 != 0) {
      memmove(_Dst_01,DAT_1c0008268,(ulonglong)DAT_1c0008262);
      _Dst_01 = _Dst_01 + (DAT_1c0008262 >> 1);
    }
    if (DAT_1c0008272 != 0) {
      memmove(_Dst_01,DAT_1c0008278,(ulonglong)DAT_1c0008272);
      _Dst_01 = _Dst_01 + (DAT_1c0008272 >> 1);
    }
    if (DAT_1c0008282 != 0) {
      memmove(_Dst_01,DAT_1c0008288,(ulonglong)DAT_1c0008282);
      _Dst_01 = _Dst_01 + (DAT_1c0008282 >> 1);
    }
    if (DAT_1c0008292 != 0) {
      memmove(_Dst_01,DAT_1c0008298,(ulonglong)DAT_1c0008292);
      _Dst_01 = _Dst_01 + (DAT_1c0008292 >> 1);
    }
    *_Dst_01 = 0;
    _Dst_00 = (void *)ExAllocatePool2(0x42,DAT_1c00082a2,0x69424d53);
    if (_Dst_00 == (void *)0x0) {
      KeReleaseSpinLock(&SMBiosStringLock,uVar1);
      iVar2 = -0x3fffffe9;
    }
    else {
      memmove(_Dst_00,DAT_1c00082a8,(ulonglong)DAT_1c00082a2);
      uVar5 = (uint)DAT_1c00082a2;
      puVar3 = &SMBiosStringLock;
      KeReleaseSpinLock(&SMBiosStringLock,uVar1);
      iVar2 = SMBiosRegistryWriteMultiStringW(puVar3,param_1,_Dst,uVar4 + 2);
      if (-1 < iVar2) {
        iVar2 = SMBiosRegistryWriteStringW(&SMBiosComputerHardwareIdValue,param_1,_Dst_00,uVar5);
      }
      ExFreePoolWithTag(_Dst_00,0);
    }
    ExFreePoolWithTag(_Dst,0);
  }
  return iVar2;
}



===== __report_gsfailure @ 1c0003410 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== __C_specific_handler @ 1c000341d =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001c000341d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== SMBiosCPUGatherAmdMSRs @ 1c0003430 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int SMBiosCPUGatherAmdMSRs(int param_1,uint param_2)

{
  int iVar1;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  ulonglong uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  local_28 = 0;
  uStack_20 = 0;
  if (param_1 == 0) {
    return 0;
  }
  SMBiosCPUID(1,(undefined4 *)&local_28);
  if ((uStack_20 & 0x2000000000) == 0) {
    return 0;
  }
  if ((((param_2 < 0x80000001) ||
       (SMBiosCPUID(-0x7fffffff,(undefined4 *)&local_28), (uStack_20 & 0x2008080000000000) == 0)) ||
      (iVar1 = SMBiosCPUProbeRegisterForDump(1,-0x3fffff80), (iVar1 + 0x80000000U & 0x80000000) != 0
      )) || (iVar1 == -0x3fffffe3)) {
    if (param_2 < 0x80000007) {
      return 0;
    }
    SMBiosCPUID(-0x7ffffff9,(undefined4 *)&local_28);
    if ((uStack_20 & 0x600000000) == 0) {
      return 0;
    }
    iVar1 = SMBiosCPUProbeRegisterForDump(1,-0x3ffeffbf);
    if (((iVar1 + 0x80000000U & 0x80000000) != 0) || (iVar1 == -0x3fffffe3)) {
      iVar1 = SMBiosCPUProbeRegisterForDump(1,-0x3ffeffbe);
      if ((iVar1 + 0x80000000U & 0x80000000) != 0) {
        return 0;
      }
      if (iVar1 == -0x3fffffe3) {
        return 0;
      }
      return iVar1;
    }
  }
  return iVar1;
}



===== SMBiosCPUGatherIntelMSRs @ 1c000353c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong SMBiosCPUGatherIntelMSRs(uint param_1,uint param_2)

{
  ulonglong uVar1;
  ulonglong uVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  bool bVar6;
  undefined1 auStack_c8 [32];
  undefined8 local_a8;
  undefined8 local_a0;
  int local_98;
  undefined8 local_90;
  undefined4 local_88;
  undefined8 local_80;
  ulonglong uStack_78;
  undefined8 local_70;
  ulonglong uStack_68;
  int local_60 [2];
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_c8;
  uVar2 = 0;
  local_98 = 0;
  local_60[0] = 0;
  local_60[1] = 0;
  uStack_58 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  local_80 = 0;
  uStack_78 = 0;
  local_70 = 0;
  uStack_68 = 0;
  if (param_1 == 0) {
    return 0;
  }
  SMBiosCPUID(1,(undefined4 *)&local_80);
  if ((uStack_78 & 0x2000000000) == 0) {
    return 0;
  }
  uVar4 = (uint)local_80 >> 8 & 0xf;
  uVar3 = (uint)local_80 >> 4 & 0xf;
  if (uVar4 == 0xf) {
    uVar4 = ((uint)local_80 >> 0x14 & 0xff) + 0xf;
  }
  if ((uVar4 == 6) || (uVar4 == 0xf)) {
    uVar3 = uVar3 + ((uint)local_80 >> 0xc & 0xf0);
  }
  bVar5 = uVar4 < 6;
  bVar6 = uVar4 == 6;
  if (bVar6) {
    if (uVar3 < 6) {
      bVar5 = false;
      bVar6 = true;
      goto LAB_1c0003602;
    }
LAB_1c0003604:
    uVar3 = SMBiosCPUProbeRegisterForDump(1,0x17);
    if (((uVar3 + 0x80000000 & 0x80000000) == 0) && (uVar3 != 0xc000001d)) {
      return (ulonglong)uVar3;
    }
  }
  else {
LAB_1c0003602:
    if (!bVar5 && !bVar6) goto LAB_1c0003604;
  }
  if (5 < uVar4) {
    local_90 = 0x3800520053004d;
    local_88 = 0x42;
    uStack_58 = 0;
    local_50 = 0;
    uStack_48 = 0;
    local_40 = 0;
    local_60[0] = 1;
    local_60[1] = 0x8b;
    SMBiosCPUCaptureRegistersForDumpArch(local_60,'\0');
    uVar2 = SMBiosDataAddObject(0x1c0008540,local_60,0x28);
    if ((int)uVar2 < 0) {
      return uVar2 & 0xffffffff;
    }
    local_a0 = 0;
    local_a8 = 0;
    uVar2 = SMBiosCPUGatherDataQueryRoutine(&local_90,0xb,&uStack_58,8);
    local_98 = (int)uVar2;
    uVar2 = uVar2 & 0xffffffff;
    if (local_98 < 0) {
      return uVar2;
    }
  }
  if ((uStack_78 & 0x40000000000000) != 0) {
    for (uVar3 = 0x19a; uVar3 < 0x19d; uVar3 = uVar3 + 1) {
      uVar4 = SMBiosCPUProbeRegisterForDump(1,uVar3);
      if (((uVar4 + 0x80000000 & 0x80000000) == 0) && (uVar4 != 0xc000001d)) goto LAB_1c0003710;
    }
  }
  if ((((((uStack_78 & 0x100) == 0) ||
        (uVar4 = SMBiosCPUProbeRegisterForDump(1,0x19d), (uVar4 + 0x80000000 & 0x80000000) != 0)) ||
       (uVar4 == 0xc000001d)) &&
      ((((uStack_78 & 0x20000000000000) == 0 && ((uStack_78 & 0x188) == 0)) ||
       ((uVar4 = SMBiosCPUProbeRegisterForDump(1,0x1a0), (uVar4 + 0x80000000 & 0x80000000) != 0 ||
        (uVar4 == 0xc000001d)))))) &&
     (((param_1 < 6 || (SMBiosCPUID(6,(undefined4 *)&local_70), (uStack_68 & 8) == 0)) ||
      ((uVar4 = SMBiosCPUProbeRegisterForDump(1,0x1fc), (uVar4 + 0x80000000 & 0x80000000) != 0 ||
       (uVar4 == 0xc000001d)))))) {
    if ((6 < param_1) &&
       (SMBiosCPUIDSubleaf(7,0,(undefined4 *)&local_70), (uStack_68 & 0x2000000000000000) != 0)) {
      uVar4 = SMBiosCPUProbeRegisterForDump(1,0x10a);
      if (((uVar4 + 0x80000000 & 0x80000000) == 0) && (uVar4 != 0xc000001d)) goto LAB_1c0003710;
      uVar1 = rdmsr(0x10a);
      if ((((uVar1 >> 0x17 & 1) != 0) &&
          (uVar3 = SMBiosCPUProbeRegisterForDump(1,0x195), (uVar3 + 0x80000000 & 0x80000000) == 0))
         && (uVar3 != 0xc000001d)) {
        return (ulonglong)uVar3;
      }
    }
    if (((0x80000000 < param_2) &&
        (SMBiosCPUID(-0x7fffffff,(undefined4 *)&local_70), (uStack_68 & 0x2010080000000000) != 0))
       && ((uVar3 = SMBiosCPUProbeRegisterForDump(1,-0x3fffff80),
           (uVar3 + 0x80000000 & 0x80000000) == 0 && (uVar3 != 0xc000001d)))) {
      uVar2 = (ulonglong)uVar3;
    }
  }
  else {
LAB_1c0003710:
    uVar2 = (ulonglong)uVar4;
  }
  return uVar2;
}



===== SMBiosSMBiosProcessTable @ 1c00038a4 =====

undefined8 SMBiosSMBiosProcessTable(short *param_1,uint param_2)

{
  byte bVar1;
  bool bVar2;
  void *pvVar3;
  uint uVar4;
  undefined1 uVar5;
  undefined8 uVar6;
  uint uVar7;
  byte local_res8;
  void *local_res18;
  uint local_res20 [2];
  void *local_78;
  void *local_70;
  void *local_68;
  void *local_60;
  void *local_58;
  void *local_50;
  void *local_48 [2];
  
  local_res8 = 0;
  local_70 = (void *)0x0;
  bVar2 = false;
  local_res18 = (void *)0x0;
  local_58 = (void *)0x0;
  local_60 = (void *)0x0;
  local_68 = (void *)0x0;
  local_78 = (void *)0x0;
  local_50 = (void *)0x0;
  local_48[0] = (void *)0x0;
  local_res20[0] = 0;
  if ((param_1 == (short *)0x0) || (param_2 == 0)) {
    return 0xc0000034;
  }
  uVar7 = 0;
  while (uVar6 = SMBiosSMBiosFindStructure
                           ('\0',uVar7,&local_res18,(int *)local_res20,param_1,param_2),
        uVar4 = local_res20[0], pvVar3 = local_res18, -1 < (int)uVar6) {
    if (uVar7 != 0) {
      return 0xc0000001;
    }
    uVar7 = 1;
    bVar1 = *(byte *)((longlong)local_res18 + 1);
    if ((4 < bVar1) &&
       (uVar6 = SMBiosSMBiosSaveBiosString
                          ((longlong)local_res18,(uint)*(byte *)((longlong)local_res18 + 4),
                           (ulonglong)local_res20[0],0x1c0008340), (int)uVar6 < 0)) {
      return uVar6;
    }
    if ((5 < bVar1) &&
       (uVar6 = SMBiosSMBiosSaveBiosString
                          ((longlong)pvVar3,(uint)*(byte *)((longlong)pvVar3 + 5),(ulonglong)uVar4,
                           0x1c0008360), (int)uVar6 < 0)) {
      return uVar6;
    }
    if ((8 < bVar1) &&
       (uVar6 = SMBiosSMBiosSaveBiosString
                          ((longlong)pvVar3,(uint)*(byte *)((longlong)pvVar3 + 8),(ulonglong)uVar4,
                           0x1c0008320), (int)uVar6 < 0)) {
      return uVar6;
    }
    if (0x17 < bVar1) {
      uVar5 = KeAcquireSpinLockRaiseToDpc(&SMBiosStringLock);
      SMBiosSystemBiosMajorRelease = *(undefined1 *)((longlong)pvVar3 + 0x14);
      bVar1 = *(byte *)((longlong)pvVar3 + 0x13);
      SMBiosSystemBiosMinorRelease = *(undefined1 *)((longlong)pvVar3 + 0x15);
      SMBiosSystemECFirmwareMajorRelease = *(undefined1 *)((longlong)pvVar3 + 0x16);
      SMBiosSystemECFirmwareMinorRelease = *(undefined1 *)((longlong)pvVar3 + 0x17);
      KeReleaseSpinLock(&SMBiosStringLock,uVar5);
      local_res8 = bVar1 >> 2 & 1;
    }
    uVar6 = SMBiosDataAddObject(0x1c00084c0,pvVar3,uVar4);
    if ((int)uVar6 < 0) {
      return uVar6;
    }
  }
  uVar7 = 0;
  do {
    uVar6 = SMBiosSMBiosFindStructure('\x01',uVar7,&local_78,(int *)local_res20,param_1,param_2);
    pvVar3 = local_78;
    uVar4 = local_res20[0];
    if ((int)uVar6 < 0) {
      uVar7 = 0;
      while (uVar6 = SMBiosSMBiosFindStructure
                               ('\x02',uVar7,&local_70,(int *)local_res20,param_1,param_2),
            pvVar3 = local_70, uVar4 = local_res20[0], -1 < (int)uVar6) {
        uVar7 = uVar7 + 1;
        bVar1 = *(byte *)((longlong)local_70 + 1);
        if ((4 < bVar1) &&
           (uVar6 = SMBiosSMBiosSaveBiosString
                              ((longlong)local_70,(uint)*(byte *)((longlong)local_70 + 4),
                               (ulonglong)local_res20[0],0x1c00082c0), (int)uVar6 < 0)) {
          return uVar6;
        }
        if ((5 < bVar1) &&
           (uVar6 = SMBiosSMBiosSaveBiosString
                              ((longlong)pvVar3,(uint)*(byte *)((longlong)pvVar3 + 5),
                               (ulonglong)uVar4,0x1c00082e0), (int)uVar6 < 0)) {
          return uVar6;
        }
        if ((6 < bVar1) &&
           (uVar6 = SMBiosSMBiosSaveBiosString
                              ((longlong)pvVar3,(uint)*(byte *)((longlong)pvVar3 + 6),
                               (ulonglong)uVar4,0x1c0008300), (int)uVar6 < 0)) {
          return uVar6;
        }
        if (8 < bVar1) {
          SMBiosSMBiosFindStringAndZero
                    ((longlong)pvVar3,(uint)*(byte *)((longlong)pvVar3 + 8),uVar4);
        }
        uVar6 = SMBiosDataAddObject(0x1c00084c0,pvVar3,uVar4);
        if ((int)uVar6 < 0) {
          return uVar6;
        }
      }
      uVar7 = 0;
      do {
        uVar6 = SMBiosSMBiosFindStructure('\x03',uVar7,&local_68,(int *)local_res20,param_1,param_2)
        ;
        pvVar3 = local_68;
        uVar4 = local_res20[0];
        if ((int)uVar6 < 0) {
          uVar7 = 0;
          do {
            uVar6 = SMBiosSMBiosFindStructure
                              ('\x04',uVar7,&local_60,(int *)local_res20,param_1,param_2);
            pvVar3 = local_60;
            uVar4 = local_res20[0];
            if ((int)uVar6 < 0) {
              uVar7 = 0;
              do {
                uVar6 = SMBiosSMBiosFindStructure
                                  ('\x11',uVar7,&local_58,(int *)local_res20,param_1,param_2);
                pvVar3 = local_58;
                uVar4 = local_res20[0];
                if ((int)uVar6 < 0) {
                  uVar7 = 0;
                  do {
                    uVar6 = SMBiosSMBiosFindStructure
                                      ('\x16',uVar7,&local_50,(int *)local_res20,param_1,param_2);
                    pvVar3 = local_50;
                    if ((int)uVar6 < 0) {
                      uVar7 = 0;
                      do {
                        uVar6 = SMBiosSMBiosFindStructure
                                          ('\'',uVar7,local_48,(int *)local_res20,param_1,param_2);
                        pvVar3 = local_48[0];
                        uVar4 = local_res20[0];
                        if ((int)uVar6 < 0) {
                          if ((local_res8 != 0) && (bVar2)) {
                            uVar5 = KeAcquireSpinLockRaiseToDpc(&SMBiosStringLock);
                            SMBiosEnableTargetedContentDistribution = 1;
                            KeReleaseSpinLock(&SMBiosStringLock,uVar5);
                          }
                          uVar6 = SMBiosDataAddObject(0x1c0008480,param_1,param_2);
                          return uVar6;
                        }
                        uVar7 = uVar7 + 1;
                        bVar1 = *(byte *)((longlong)local_48[0] + 1);
                        if (8 < bVar1) {
                          SMBiosSMBiosFindStringAndZero
                                    ((longlong)local_48[0],
                                     (uint)*(byte *)((longlong)local_48[0] + 8),local_res20[0]);
                        }
                        if (9 < bVar1) {
                          SMBiosSMBiosFindStringAndZero
                                    ((longlong)pvVar3,(uint)*(byte *)((longlong)pvVar3 + 9),uVar4);
                        }
                        uVar6 = SMBiosDataAddObject(0x1c00084c0,pvVar3,uVar4);
                      } while (-1 < (int)uVar6);
                      return uVar6;
                    }
                    uVar7 = uVar7 + 1;
                    bVar1 = *(byte *)((longlong)local_50 + 1);
                    if (7 < bVar1) {
                      SMBiosSMBiosFindStringAndZero
                                ((longlong)local_50,(uint)*(byte *)((longlong)local_50 + 7),
                                 local_res20[0]);
                    }
                    if (0x11 < bVar1) {
                      *(undefined2 *)((longlong)pvVar3 + 0x10) = 0;
                    }
                    uVar6 = SMBiosDataAddObject(0x1c00084c0,pvVar3,local_res20[0]);
                  } while (-1 < (int)uVar6);
                  return uVar6;
                }
                uVar7 = uVar7 + 1;
                bVar1 = *(byte *)((longlong)local_58 + 1);
                if (0x18 < bVar1) {
                  SMBiosSMBiosFindStringAndZero
                            ((longlong)local_58,(uint)*(byte *)((longlong)local_58 + 0x18),
                             local_res20[0]);
                }
                if (0x19 < bVar1) {
                  SMBiosSMBiosFindStringAndZero
                            ((longlong)pvVar3,(uint)*(byte *)((longlong)pvVar3 + 0x19),uVar4);
                }
                uVar6 = SMBiosDataAddObject(0x1c00084c0,pvVar3,uVar4);
              } while (-1 < (int)uVar6);
              return uVar6;
            }
            uVar7 = uVar7 + 1;
            bVar1 = *(byte *)((longlong)local_60 + 1);
            if (0x20 < bVar1) {
              SMBiosSMBiosFindStringAndZero
                        ((longlong)local_60,(uint)*(byte *)((longlong)local_60 + 0x20),
                         local_res20[0]);
            }
            if (0x21 < bVar1) {
              SMBiosSMBiosFindStringAndZero
                        ((longlong)pvVar3,(uint)*(byte *)((longlong)pvVar3 + 0x21),uVar4);
            }
            uVar6 = SMBiosDataAddObject(0x1c00084c0,pvVar3,uVar4);
          } while (-1 < (int)uVar6);
          return uVar6;
        }
        uVar7 = uVar7 + 1;
        bVar1 = *(byte *)((longlong)local_68 + 1);
        if (7 < bVar1) {
          SMBiosSMBiosFindStringAndZero
                    ((longlong)local_68,(uint)*(byte *)((longlong)local_68 + 7),local_res20[0]);
        }
        if (bVar1 < 9) {
          if (5 < bVar1) goto LAB_1c0003c8e;
        }
        else {
          SMBiosSMBiosFindStringAndZero
                    ((longlong)pvVar3,(uint)*(byte *)((longlong)pvVar3 + 8),uVar4);
LAB_1c0003c8e:
          SMBiosSystemChassisType = *(undefined1 *)((longlong)pvVar3 + 5);
        }
        uVar6 = SMBiosDataAddObject(0x1c00084c0,pvVar3,uVar4);
        if ((int)uVar6 < 0) {
          return uVar6;
        }
      } while( true );
    }
    if (uVar7 != 0) {
      return 0xc0000001;
    }
    uVar7 = 1;
    bVar1 = *(byte *)((longlong)local_78 + 1);
    if ((4 < bVar1) &&
       (uVar6 = SMBiosSMBiosSaveBiosString
                          ((longlong)local_78,(uint)*(byte *)((longlong)local_78 + 4),
                           (ulonglong)local_res20[0],0x1c00083a0), (int)uVar6 < 0)) {
      return uVar6;
    }
    if ((5 < bVar1) &&
       (uVar6 = SMBiosSMBiosSaveBiosString
                          ((longlong)pvVar3,(uint)*(byte *)((longlong)pvVar3 + 5),(ulonglong)uVar4,
                           0x1c00083c0), (int)uVar6 < 0)) {
      return uVar6;
    }
    if ((6 < bVar1) &&
       (uVar6 = SMBiosSMBiosSaveBiosString
                          ((longlong)pvVar3,(uint)*(byte *)((longlong)pvVar3 + 6),(ulonglong)uVar4,
                           0x1c0008400), (int)uVar6 < 0)) {
      return uVar6;
    }
    if ((0x19 < bVar1) &&
       (uVar6 = SMBiosSMBiosSaveBiosString
                          ((longlong)pvVar3,(uint)*(byte *)((longlong)pvVar3 + 0x19),
                           (ulonglong)uVar4,0x1c00083e0), (int)uVar6 < 0)) {
      return uVar6;
    }
    if (bVar1 < 0x1b) {
      if (0x17 < bVar1) goto LAB_1c0003b2c;
    }
    else {
      uVar6 = SMBiosSMBiosSaveBiosString
                        ((longlong)pvVar3,(uint)*(byte *)((longlong)pvVar3 + 0x1a),(ulonglong)uVar4,
                         0x1c0008380);
      if ((int)uVar6 < 0) {
        return uVar6;
      }
      bVar2 = true;
LAB_1c0003b2c:
      *(undefined8 *)((longlong)pvVar3 + 8) = 0;
      *(undefined8 *)((longlong)pvVar3 + 0x10) = 0;
    }
    uVar6 = SMBiosDataAddObject(0x1c00084c0,pvVar3,uVar4);
    if ((int)uVar6 < 0) {
      return uVar6;
    }
  } while( true );
}



===== SMBiosBugCheckCallbackRoutineACPI @ 1c0003ef0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SMBiosBugCheckCallbackRoutineACPI(undefined8 param_1,undefined8 param_2,longlong param_3)

{
  undefined8 uVar1;
  
  uVar1 = uRam00000001c0008520;
  if (((DAT_1c0008528 != 0) && (DAT_1c0008528 <= *(uint *)(param_3 + 0xc))) &&
     ((DAT_1c0008504 & 1) == 0)) {
    *(undefined8 *)(param_3 + 0x10) = _DAT_1c0008518;
    *(undefined8 *)(param_3 + 0x18) = uVar1;
    *(undefined8 *)(param_3 + 0x20) = DAT_1c0008538;
    *(uint *)(param_3 + 0x28) = DAT_1c0008528;
  }
  return;
}



===== SMBiosBugCheckCallbackRoutineRegisters @ 1c0003f40 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SMBiosBugCheckCallbackRoutineRegisters(undefined8 param_1,undefined8 param_2,longlong param_3)

{
  undefined8 uVar1;
  ulonglong uVar2;
  int *piVar3;
  
  if ((((DAT_1c0008568 != 0) && (DAT_1c0008568 <= *(uint *)(param_3 + 0xc))) &&
      ((DAT_1c0008544 & 1) == 0)) && ((DAT_1c0008544 & 2) == 0)) {
    uVar2 = (ulonglong)DAT_1c0008568 / 0x28;
    if ((int)uVar2 != 0) {
      piVar3 = DAT_1c0008578;
      do {
        SMBiosCPUCaptureRegistersForDumpArch(piVar3,'\x01');
        piVar3 = piVar3 + 10;
        uVar2 = uVar2 - 1;
      } while (uVar2 != 0);
    }
    uVar1 = uRam00000001c0008560;
    *(undefined8 *)(param_3 + 0x10) = _DAT_1c0008558;
    *(undefined8 *)(param_3 + 0x18) = uVar1;
    *(int **)(param_3 + 0x20) = DAT_1c0008578;
    *(uint *)(param_3 + 0x28) = DAT_1c0008568;
  }
  return;
}



===== SMBiosBugCheckCallbackRoutineRegistry @ 1c0003fe0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SMBiosBugCheckCallbackRoutineRegistry(undefined8 param_1,undefined8 param_2,longlong param_3)

{
  undefined8 uVar1;
  
  uVar1 = uRam00000001c0008460;
  if ((((DAT_1c0008468 != 0) && (DAT_1c0008468 <= *(uint *)(param_3 + 0xc))) &&
      ((DAT_1c0008444 & 1) == 0)) && ((DAT_1c0008444 & 2) == 0)) {
    *(undefined8 *)(param_3 + 0x10) = _DAT_1c0008458;
    *(undefined8 *)(param_3 + 0x18) = uVar1;
    *(undefined8 *)(param_3 + 0x20) = DAT_1c0008478;
    *(uint *)(param_3 + 0x28) = DAT_1c0008468;
  }
  return;
}



===== SMBiosBugCheckCallbackRoutineSMBios @ 1c0004030 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SMBiosBugCheckCallbackRoutineSMBios(undefined8 param_1,undefined8 param_2,longlong param_3)

{
  undefined8 uVar1;
  
  uVar1 = uRam00000001c00084a0;
  if (((DAT_1c00084a8 != 0) && (DAT_1c00084a8 <= *(uint *)(param_3 + 0xc))) &&
     ((DAT_1c0008484 & 1) == 0)) {
    *(undefined8 *)(param_3 + 0x10) = _DAT_1c0008498;
    *(undefined8 *)(param_3 + 0x18) = uVar1;
    *(undefined8 *)(param_3 + 0x20) = DAT_1c00084b8;
    *(uint *)(param_3 + 0x28) = DAT_1c00084a8;
  }
  return;
}



===== SMBiosBugCheckRegisterCallbacks @ 1c0004074 =====

void SMBiosBugCheckRegisterCallbacks(void)

{
  DAT_1c00085ac = 0;
  KeRegisterBugCheckReasonCallback
            (&SMBiosBugCheckCallbackRecordACPI,SMBiosBugCheckCallbackRoutineACPI,5,"SMBiosDataACPI")
  ;
  DAT_1c000862c = 0;
  KeRegisterBugCheckReasonCallback
            (&SMBiosBugCheckCallbackRecordRegisters,SMBiosBugCheckCallbackRoutineRegisters,5,
             "SMBiosRegisters");
  DAT_1c000866c = 0;
  KeRegisterBugCheckReasonCallback
            (&SMBiosBugCheckCallbackRecordRegistry,SMBiosBugCheckCallbackRoutineRegistry,5,
             "SMBiosRegistry");
  DAT_1c00085ec = 0;
  KeRegisterBugCheckReasonCallback
            (&SMBiosBugCheckCallbackRecordSMBios,SMBiosBugCheckCallbackRoutineSMBios,5,"SMBiosData")
  ;
  return;
}



===== SMBiosDataDeleteObject @ 1c000413c =====

undefined8 SMBiosDataDeleteObject(longlong param_1)

{
  undefined1 uVar1;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x30);
  if (*(longlong *)(param_1 + 0x38) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x38),0);
    *(undefined8 *)(param_1 + 0x38) = 0;
  }
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 1;
  KeReleaseSpinLock(param_1 + 0x30,uVar1);
  return 0;
}



===== SMBiosDataResetObject @ 1c00041b8 =====

undefined8 SMBiosDataResetObject(longlong param_1)

{
  undefined1 uVar1;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x30);
  if (*(void **)(param_1 + 0x38) != (void *)0x0) {
    memset(*(void **)(param_1 + 0x38),0,(ulonglong)*(uint *)(param_1 + 0x2c));
    *(undefined4 *)(param_1 + 0x28) = 0;
  }
  KeReleaseSpinLock(param_1 + 0x30,uVar1);
  return 0;
}



===== SMBiosDataResetObjects @ 1c0004224 =====

int SMBiosDataResetObjects(void)

{
  undefined8 uVar1;
  int iVar2;
  
  uVar1 = SMBiosDataResetObject(0x1c0008500);
  iVar2 = 0;
  if ((int)uVar1 < 0) {
    iVar2 = (int)uVar1;
  }
  uVar1 = SMBiosDataResetObject(0x1c0008480);
  if ((int)uVar1 < 0) {
    iVar2 = (int)uVar1;
  }
  uVar1 = SMBiosDataResetObject(0x1c00084c0);
  if ((int)uVar1 < 0) {
    iVar2 = (int)uVar1;
  }
  uVar1 = SMBiosDataResetObject(0x1c0008540);
  if ((int)uVar1 < 0) {
    iVar2 = (int)uVar1;
  }
  uVar1 = SMBiosDataResetObject(0x1c0008440);
  if ((int)uVar1 < 0) {
    iVar2 = (int)uVar1;
  }
  return iVar2;
}



===== SMBiosDriverUnload @ 1c0004290 =====

void SMBiosDriverUnload(void)

{
  KeDeregisterBugCheckReasonCallback(&SMBiosBugCheckCallbackRecordACPI);
  KeDeregisterBugCheckReasonCallback(&SMBiosBugCheckCallbackRecordRegisters);
  KeDeregisterBugCheckReasonCallback(&SMBiosBugCheckCallbackRecordRegistry);
  KeDeregisterBugCheckReasonCallback(&SMBiosBugCheckCallbackRecordSMBios);
  SMBiosDataDeleteObject(0x1c0008500);
  SMBiosDataDeleteObject(0x1c0008480);
  SMBiosDataDeleteObject(0x1c00084c0);
  SMBiosDataDeleteObject(0x1c0008540);
  SMBiosDataDeleteObject(0x1c0008440);
  SMBiosStringsResetStrings();
  if (DAT_1c00082b2 != 0) {
    ExFreePoolWithTag(DAT_1c00082b8,0);
  }
  return;
}



===== SMBiosWmiQueryRegInfo @ 1c0004350 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
SMBiosWmiQueryRegInfo
          (longlong param_1,undefined4 *param_2,undefined8 param_3,undefined8 *param_4,
          undefined8 param_5,undefined8 *param_6)

{
  undefined8 *puVar1;
  undefined1 uVar2;
  
  puVar1 = *(undefined8 **)(param_1 + 0x40);
  *param_2 = 0x20;
  *param_4 = &SMBiosRegistryPath;
  RtlInitUnicodeString(param_5);
  *param_6 = *puVar1;
  SMBiosDataResetObject(0x1c0008480);
  SMBiosDataResetObject(0x1c00084c0);
  SMBiosSMbiosProcessSMBiosData();
  SMBiosRegistrySaveData();
  SMBiosComputeHardwareIds();
  SMBiosRegistrySaveData();
  uVar2 = KeAcquireSpinLockRaiseToDpc(&SMBiosStringLock);
  _DAT_1c0008048 = (uint)(SMBiosEnableTargetedContentDistribution != '\0');
  KeReleaseSpinLock(&SMBiosStringLock,uVar2);
  return 0;
}



===== SMBiosBigEndian @ 1c0004404 =====

undefined1 SMBiosBigEndian(void)

{
  return 0;
}



===== SMBiosNetworkToHostLong @ 1c0004410 =====

uint SMBiosNetworkToHostLong(uint param_1)

{
  return param_1 >> 0x18 | (param_1 & 0xff0000) >> 8 | (param_1 & 0xff00) << 8 | param_1 << 0x18;
}



===== SMBiosNetworkToHostShort @ 1c000441c =====

ushort SMBiosNetworkToHostShort(ushort param_1)

{
  return param_1 >> 8 | param_1 << 8;
}



===== __GSHandlerCheck @ 1c000442c =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c0004450 =====

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



===== __GSHandlerCheck_SEH @ 1c00044b8 =====

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



===== __cpu_features_init @ 1c0004550 =====

/* WARNING: Removing unreachable block (ram,0x0001c00045ba) */
/* WARNING: Removing unreachable block (ram,0x0001c0004569) */
/* WARNING: Removing unreachable block (ram,0x0001c000455a) */

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



===== _guard_check_icall @ 1c0004620 =====

void _guard_check_icall(void)

{
  return;
}



===== SMBiosCPUIDIsPresent @ 1c0004640 =====

undefined1 SMBiosCPUIDIsPresent(void)

{
  return 1;
}



===== SMBiosCPUID @ 1c0004650 =====

void SMBiosCPUID(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  if (param_1 == 0) {
    puVar1 = (undefined4 *)cpuid_basic_info(0);
  }
  else if (param_1 == 1) {
    puVar1 = (undefined4 *)cpuid_Version_info(1);
  }
  else if (param_1 == 2) {
    puVar1 = (undefined4 *)cpuid_cache_tlb_info(2);
  }
  else if (param_1 == 3) {
    puVar1 = (undefined4 *)cpuid_serial_info(3);
  }
  else if (param_1 == 4) {
    puVar1 = (undefined4 *)cpuid_Deterministic_Cache_Parameters_info(4);
  }
  else if (param_1 == 5) {
    puVar1 = (undefined4 *)cpuid_MONITOR_MWAIT_Features_info(5);
  }
  else if (param_1 == 6) {
    puVar1 = (undefined4 *)cpuid_Thermal_Power_Management_info(6);
  }
  else if (param_1 == 7) {
    puVar1 = (undefined4 *)cpuid_Extended_Feature_Enumeration_info(7);
  }
  else if (param_1 == 9) {
    puVar1 = (undefined4 *)cpuid_Direct_Cache_Access_info(9);
  }
  else if (param_1 == 10) {
    puVar1 = (undefined4 *)cpuid_Architectural_Performance_Monitoring_info(10);
  }
  else if (param_1 == 0xb) {
    puVar1 = (undefined4 *)cpuid_Extended_Topology_info(0xb);
  }
  else if (param_1 == 0xd) {
    puVar1 = (undefined4 *)cpuid_Processor_Extended_States_info(0xd);
  }
  else if (param_1 == 0xf) {
    puVar1 = (undefined4 *)cpuid_Quality_of_Service_info(0xf);
  }
  else if (param_1 == -0x7ffffffe) {
    puVar1 = (undefined4 *)cpuid_brand_part1_info(0x80000002);
  }
  else if (param_1 == -0x7ffffffd) {
    puVar1 = (undefined4 *)cpuid_brand_part2_info(0x80000003);
  }
  else if (param_1 == -0x7ffffffc) {
    puVar1 = (undefined4 *)cpuid_brand_part3_info(0x80000004);
  }
  else {
    puVar1 = (undefined4 *)cpuid(param_1);
  }
  uVar2 = puVar1[1];
  uVar3 = puVar1[2];
  uVar4 = puVar1[3];
  *param_2 = *puVar1;
  param_2[1] = uVar2;
  param_2[2] = uVar4;
  param_2[3] = uVar3;
  return;
}



===== SMBiosCPUIDSubleaf @ 1c0004670 =====

void SMBiosCPUIDSubleaf(int param_1,undefined8 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  if (param_1 == 0) {
    puVar1 = (undefined4 *)cpuid_basic_info(0);
  }
  else if (param_1 == 1) {
    puVar1 = (undefined4 *)cpuid_Version_info(1);
  }
  else if (param_1 == 2) {
    puVar1 = (undefined4 *)cpuid_cache_tlb_info(2);
  }
  else if (param_1 == 3) {
    puVar1 = (undefined4 *)cpuid_serial_info(3);
  }
  else if (param_1 == 4) {
    puVar1 = (undefined4 *)cpuid_Deterministic_Cache_Parameters_info(4);
  }
  else if (param_1 == 5) {
    puVar1 = (undefined4 *)cpuid_MONITOR_MWAIT_Features_info(5);
  }
  else if (param_1 == 6) {
    puVar1 = (undefined4 *)cpuid_Thermal_Power_Management_info(6);
  }
  else if (param_1 == 7) {
    puVar1 = (undefined4 *)cpuid_Extended_Feature_Enumeration_info(7);
  }
  else if (param_1 == 9) {
    puVar1 = (undefined4 *)cpuid_Direct_Cache_Access_info(9);
  }
  else if (param_1 == 10) {
    puVar1 = (undefined4 *)cpuid_Architectural_Performance_Monitoring_info(10);
  }
  else if (param_1 == 0xb) {
    puVar1 = (undefined4 *)cpuid_Extended_Topology_info(0xb);
  }
  else if (param_1 == 0xd) {
    puVar1 = (undefined4 *)cpuid_Processor_Extended_States_info(0xd);
  }
  else if (param_1 == 0xf) {
    puVar1 = (undefined4 *)cpuid_Quality_of_Service_info(0xf);
  }
  else if (param_1 == -0x7ffffffe) {
    puVar1 = (undefined4 *)cpuid_brand_part1_info(0x80000002);
  }
  else if (param_1 == -0x7ffffffd) {
    puVar1 = (undefined4 *)cpuid_brand_part2_info(0x80000003);
  }
  else if (param_1 == -0x7ffffffc) {
    puVar1 = (undefined4 *)cpuid_brand_part3_info(0x80000004);
  }
  else {
    puVar1 = (undefined4 *)cpuid(param_1);
  }
  uVar2 = puVar1[1];
  uVar3 = puVar1[2];
  uVar4 = puVar1[3];
  *param_3 = *puVar1;
  param_3[1] = uVar2;
  param_3[2] = uVar4;
  param_3[3] = uVar3;
  return;
}



===== __security_check_cookie @ 1c00046a0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c00046e0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c00046e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c0004710 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memmove @ 1c0004780 =====

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



===== memset @ 1c0004a80 =====

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



===== __memset_repmovs @ 1c0004bc0 =====

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



===== __memset_query @ 1c0004c40 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c0004cc0 =====

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



===== __memset_spec_ermsb_repmovsb @ 1c0004e00 =====

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



===== __memset_spec_plain @ 1c0004e80 =====

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



===== SMBiosRegistrySaveData @ 1c000b010 =====

ulonglong SMBiosRegistrySaveData(void)

{
  uint uVar1;
  ulonglong uVar2;
  undefined8 local_res8;
  undefined8 local_res10;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined *local_28;
  undefined8 local_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res8 = 0;
  local_res10 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  SMBiosWriteSystemInformationRegistry();
  local_38 = 0x30;
  local_28 = &SMBiosRegistryPath;
  local_20 = 0x240;
  local_30 = 0;
  local_18 = 0;
  uStack_10 = 0;
  uVar2 = ZwOpenKey(&local_res8,0x20019,&local_38);
  if ((int)uVar2 < 0) {
    return uVar2;
  }
  RtlInitUnicodeString(&local_58,L"Data");
  uVar1 = SMBiosRegistryCreateHandleW(&local_58,local_res8,&local_res10);
  if (-1 < (int)uVar1) {
    SMBiosDataSaveObjects(local_res10);
    ZwClose(local_res8);
    ZwClose(local_res10);
    RtlInitUnicodeString(&local_48,rgzGlobalIdentifier);
    RtlInitUnicodeString(&local_58);
    uVar2 = SMBiosRegistryOpenHandleW(&local_48,0,&local_res8);
    if ((int)uVar2 < 0) {
      return uVar2;
    }
    uVar1 = SMBiosRegistryCreateHandleW(&local_58,local_res8,&local_res10);
    if (-1 < (int)uVar1) {
      SMBiosStringsSaveToRegistry(local_res10);
      ZwClose(local_res8);
      ZwClose(local_res10);
      return 0;
    }
  }
  ZwClose(local_res8);
  return (ulonglong)uVar1;
}



===== SMBiosRegistryWriteIntegerW @ 1c000b190 =====

void SMBiosRegistryWriteIntegerW(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  undefined4 local_res18 [4];
  
  local_res18[0] = param_3;
  ZwSetValueKey(param_2,param_1,0,4,local_res18,4);
  return;
}



===== SMBiosRegistryWriteStringW @ 1c000b1e0 =====

void SMBiosRegistryWriteStringW
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  ZwSetValueKey(param_2,param_1,0,1,param_3,param_4);
  return;
}



===== SMBiosSMbiosProcessSMBiosData @ 1c000b218 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 SMBiosSMbiosProcessSMBiosData(void)

{
  short *psVar1;
  short *psVar2;
  uint uVar3;
  short sVar4;
  int iVar5;
  longlong lVar6;
  undefined8 uVar7;
  short *psVar8;
  short *psVar9;
  void *pvVar10;
  undefined1 auStack_68 [32];
  undefined4 local_48 [2];
  longlong local_40;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_68;
  local_38 = 0x8f680850;
  local_40 = 0;
  lVar6 = 0;
  local_48[0] = 0;
  local_34 = 0x11d1a584;
  local_30 = 0xa00038bf;
  local_2c = 0x102906c9;
  SMBiosDataResetObject(0x1c0008480);
  SMBiosDataResetObject(0x1c00084c0);
  SMBiosStringsResetStrings();
  iVar5 = IoWMIOpenBlock(&local_38,1,&local_40);
  if (-1 < iVar5) {
    iVar5 = IoWMIQueryAllData(local_40,local_48,0);
    if (iVar5 == -0x3fffffdd) {
      lVar6 = ExAllocatePool2(0x42,local_48[0],0x69424d53);
      if (lVar6 != 0) {
        iVar5 = IoWMIQueryAllData(local_40,local_48,lVar6);
        if ((((-1 < iVar5) && ((*(uint *)(lVar6 + 0x2c) & 0x10) == 0)) &&
            (*(int *)(lVar6 + 0x34) == 1)) && (8 < *(uint *)(lVar6 + 0x40))) {
          pvVar10 = (void *)((ulonglong)*(uint *)(lVar6 + 0x3c) + lVar6);
          uVar3 = *(uint *)((longlong)pvVar10 + 4);
          psVar1 = (short *)((longlong)pvVar10 + 8);
          psVar2 = (short *)((longlong)psVar1 + (ulonglong)uVar3);
          psVar8 = psVar1;
          do {
            psVar9 = psVar8;
            if (psVar2 <= psVar8) goto LAB_1c000b370;
            for (psVar9 = (short *)((longlong)psVar8 + (ulonglong)*(byte *)((longlong)psVar8 + 1));
                (psVar9 < psVar2 && (*psVar9 != 0)); psVar9 = (short *)((longlong)psVar9 + 1)) {
            }
            psVar9 = psVar9 + 1;
            sVar4 = *psVar8;
            psVar8 = psVar9;
          } while ((char)sVar4 != '\x7f');
          if (psVar2 <= psVar9) {
LAB_1c000b370:
            if (psVar9 != psVar2) goto LAB_1c000b3b3;
          }
          uVar7 = SMBiosDataAddObject(0x1c0008480,pvVar10,8);
          if (-1 < (int)uVar7) {
            uVar7 = SMBiosDataAddObject(0x1c00084c0,pvVar10,8);
            if (-1 < (int)uVar7) {
              uVar7 = SMBiosSMBiosProcessTable(psVar1,uVar3);
              iVar5 = (int)uVar7;
              goto LAB_1c000b3af;
            }
          }
        }
      }
    }
    else {
LAB_1c000b3af:
      if (-1 < iVar5) goto LAB_1c000b3d0;
    }
  }
LAB_1c000b3b3:
  SMBiosDataResetObject(0x1c0008480);
  SMBiosDataResetObject(0x1c00084c0);
  SMBiosStringsResetStrings();
LAB_1c000b3d0:
  if (lVar6 != 0) {
    ExFreePoolWithTag(lVar6,0);
  }
  if (local_40 != 0) {
    ObfDereferenceObject();
  }
  return 0;
}



===== SMBiosRegistryWriteMultiStringW @ 1c000b42c =====

void SMBiosRegistryWriteMultiStringW
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  ZwSetValueKey(param_2,&SMBiosComputerHardwareIdsValue,0,7,param_3,param_4);
  return;
}



===== SMBiosDriverAddDevice @ 1c000b470 =====

ulonglong SMBiosDriverAddDevice(undefined8 param_1,undefined8 param_2)

{
  undefined8 *puVar1;
  ulonglong uVar2;
  longlong lVar3;
  longlong local_res18 [2];
  
  local_res18[0] = 0;
  uVar2 = IoCreateDevice(param_1,0x150,0,0x22,0,0,local_res18);
  if (-1 < (int)uVar2) {
    puVar1 = *(undefined8 **)(local_res18[0] + 0x40);
    puVar1[2] = local_res18[0];
    *puVar1 = param_2;
    lVar3 = IoAttachDeviceToDeviceStack(local_res18[0],param_2);
    puVar1[1] = lVar3;
    if (lVar3 == 0) {
      IoDeleteDevice(local_res18[0]);
      uVar2 = 0xc000000e;
    }
    else {
      IoInitializeRemoveLockEx(puVar1 + 3,0x69424d53,1,0x14,0x20);
      IoWMIRegistrationControl(local_res18[0],1);
      *(uint *)(local_res18[0] + 0x30) = *(uint *)(local_res18[0] + 0x30) & 0xffffff7f;
      uVar2 = uVar2 & 0xffffffff;
    }
  }
  return uVar2;
}



===== SMBiosDriverStartDeviceWorker @ 1c000b570 =====

void SMBiosDriverStartDeviceWorker(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  SMBiosDataResetObjects();
  SMBiosACPIProcessACPIData();
  SMBiosCPUGatherData();
  SMBiosSMbiosProcessSMBiosData();
  SMBiosComputeHardwareIds();
  SMBiosRegistrySaveData();
  *(undefined4 *)(lVar1 + 0x38) = 1;
  IofCompleteRequest(param_2,0);
  IoFreeWorkItem(param_3);
  IoReleaseRemoveLockEx(lVar1 + 0x18,param_2,0x20);
  return;
}



===== SMBiosComputeHardwareIds @ 1c000b600 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SMBiosComputeHardwareIds(void)

{
  NTSTATUS NVar1;
  undefined8 uVar2;
  undefined8 **ppuVar3;
  undefined8 *puVar4;
  longlong lVar5;
  longlong lVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  undefined1 auStack_138 [32];
  uint local_118;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined8 *local_e8 [16];
  wchar_t local_68 [8];
  wchar_t local_58 [24];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_138;
  local_108 = 0;
  uStack_100 = 0;
  memset(local_e8 + 3,0,0x68);
  local_118 = (uint)SMBiosSystemBiosMinorRelease;
  uVar2 = RtlStringCchPrintfW(local_58,0x18,L"%02x&%02x",(ulonglong)SMBiosSystemBiosMajorRelease);
  if ((int)uVar2 < 0) {
    return;
  }
  RtlInitUnicodeString(&local_108,local_58);
  puVar7 = (undefined8 *)&DAT_1c0008340;
  puVar8 = (undefined8 *)&SMBiosHardwareIds;
  if (DAT_1c00083e0 != 0) {
    local_e8[1] = (undefined8 *)&DAT_1c0008380;
    lVar6 = 2;
    local_e8[3] = (undefined8 *)&DAT_1c00083e0;
    ppuVar3 = local_e8 + 4;
    puVar4 = (undefined8 *)&DAT_1c0008340;
    local_e8[0] = (undefined8 *)&DAT_1c00083a0;
    local_e8[2] = (undefined8 *)&DAT_1c00083c0;
    do {
      *ppuVar3 = puVar4;
      puVar4 = puVar4 + 4;
      ppuVar3 = ppuVar3 + 1;
      lVar6 = lVar6 + -1;
    } while (lVar6 != 0);
    local_e8[6] = &local_108;
    NVar1 = SMBiosCalculateComputerHardwareId(local_e8,7,&SMBiosHardwareIds);
    if (NVar1 < 0) {
      return;
    }
  }
  local_e8[1] = (undefined8 *)&DAT_1c0008380;
  puVar4 = (undefined8 *)&DAT_1c0008340;
  ppuVar3 = local_e8 + 3;
  local_e8[0] = (undefined8 *)&DAT_1c00083a0;
  local_e8[2] = (undefined8 *)&DAT_1c00083c0;
  lVar6 = 2;
  do {
    *ppuVar3 = puVar4;
    puVar4 = puVar4 + 4;
    ppuVar3 = ppuVar3 + 1;
    lVar6 = lVar6 + -1;
  } while (lVar6 != 0);
  local_e8[5] = &local_108;
  NVar1 = SMBiosCalculateComputerHardwareId(local_e8,6,&DAT_1c0008210);
  if (NVar1 < 0) {
    return;
  }
  ppuVar3 = local_e8;
  puVar4 = (undefined8 *)&DAT_1c00083a0;
  lVar6 = 2;
  do {
    *ppuVar3 = puVar4;
    puVar4 = puVar4 + 4;
    ppuVar3 = ppuVar3 + 1;
    lVar6 = lVar6 + -1;
  } while (lVar6 != 0);
  ppuVar3 = local_e8 + 2;
  lVar6 = 2;
  do {
    lVar5 = lVar6;
    *ppuVar3 = puVar7;
    puVar7 = puVar7 + 4;
    ppuVar3 = ppuVar3 + 1;
    lVar6 = lVar5 + -1;
  } while (lVar6 != 0);
  local_e8[4] = &local_108;
  NVar1 = SMBiosCalculateComputerHardwareId(local_e8,(int)lVar5 + 4,&DAT_1c0008220);
  if (NVar1 < 0) {
    return;
  }
  if (DAT_1c00083a0 != 0) {
    if (DAT_1c00083c0 != 0) {
      if (DAT_1c00083e0 != 0) {
        local_e8[0] = (undefined8 *)&DAT_1c00083a0;
        local_e8[3] = (undefined8 *)&DAT_1c00083e0;
        local_e8[1] = (undefined8 *)&DAT_1c0008380;
        local_e8[2] = (undefined8 *)&DAT_1c00083c0;
        NVar1 = SMBiosCalculateComputerHardwareId(local_e8,4,&DAT_1c0008230);
        if (NVar1 < 0) {
          return;
        }
      }
      local_e8[0] = (undefined8 *)&DAT_1c00083a0;
      local_e8[1] = (undefined8 *)&DAT_1c0008380;
      local_e8[2] = (undefined8 *)&DAT_1c00083c0;
      NVar1 = SMBiosCalculateComputerHardwareId(local_e8,3,&DAT_1c0008240);
      if (NVar1 < 0) {
        return;
      }
    }
    if (DAT_1c00083a0 != 0) {
      if (DAT_1c00083e0 != 0) {
        local_e8[0] = (undefined8 *)&DAT_1c00083a0;
        local_e8[1] = (undefined8 *)&DAT_1c00083e0;
        NVar1 = SMBiosCalculateComputerHardwareId(local_e8,2,&DAT_1c0008250);
        if (NVar1 < 0) {
          return;
        }
      }
      if (DAT_1c00083a0 != 0) {
        if (DAT_1c00083c0 != 0) {
          ppuVar3 = local_e8;
          puVar7 = (undefined8 *)&DAT_1c00083a0;
          lVar6 = 2;
          do {
            *ppuVar3 = puVar7;
            puVar7 = puVar7 + 4;
            ppuVar3 = ppuVar3 + 1;
            lVar6 = lVar6 + -1;
          } while (lVar6 != 0);
          NVar1 = SMBiosCalculateComputerHardwareId(local_e8,2,&DAT_1c0008260);
          if (NVar1 < 0) {
            return;
          }
        }
        if ((DAT_1c00083a0 != 0) && (DAT_1c0008380 != 0)) {
          local_e8[0] = (undefined8 *)&DAT_1c00083a0;
          local_e8[1] = (undefined8 *)&DAT_1c0008380;
          NVar1 = SMBiosCalculateComputerHardwareId(local_e8,2,&DAT_1c0008270);
          if (NVar1 < 0) {
            return;
          }
        }
      }
    }
  }
  if (SMBiosSystemChassisType != 0) {
    if (DAT_1c00083a0 == 0) goto LAB_1c000b9c4;
    local_f8 = 0;
    uStack_f0 = 0;
    uVar2 = RtlStringCchPrintfW(local_68,8,L"%x",(ulonglong)SMBiosSystemChassisType);
    if ((int)uVar2 < 0) {
      return;
    }
    RtlInitUnicodeString(&local_f8,local_68);
    local_e8[1] = &local_f8;
    local_e8[0] = (undefined8 *)&DAT_1c00083a0;
    NVar1 = SMBiosCalculateComputerHardwareId(local_e8,2,&DAT_1c0008280);
    if (NVar1 < 0) {
      return;
    }
  }
  if (DAT_1c00083a0 != 0) {
    local_e8[0] = (undefined8 *)&DAT_1c00083a0;
    NVar1 = SMBiosCalculateComputerHardwareId(local_e8,1,&DAT_1c0008290);
    if (NVar1 < 0) {
      return;
    }
  }
LAB_1c000b9c4:
  ppuVar3 = local_e8;
  lVar6 = 10;
  do {
    *ppuVar3 = puVar8;
    puVar8 = puVar8 + 2;
    ppuVar3 = ppuVar3 + 1;
    lVar6 = lVar6 + -1;
  } while (lVar6 != 0);
  SMBiosCalculateComputerHardwareId(local_e8,10,&SMBiosComputerId);
  return;
}



===== SMBiosSMBiosFindStructure @ 1c000ba30 =====

undefined8
SMBiosSMBiosFindStructure
          (char param_1,uint param_2,undefined8 *param_3,int *param_4,short *param_5,uint param_6)

{
  byte bVar1;
  short *psVar2;
  uint uVar3;
  short *psVar4;
  
  psVar4 = (short *)((ulonglong)param_6 + (longlong)param_5);
  uVar3 = 0;
  while( true ) {
    if (psVar4 <= param_5) {
      return 0xc0000034;
    }
    if (((char)*param_5 == param_1) && (uVar3 = uVar3 + 1, param_2 < uVar3)) break;
    for (psVar2 = (short *)((longlong)param_5 + (ulonglong)*(byte *)((longlong)param_5 + 1));
        (psVar2 < psVar4 && (*psVar2 != 0)); psVar2 = (short *)((longlong)psVar2 + 1)) {
    }
    param_5 = psVar2 + 1;
  }
  bVar1 = *(byte *)((longlong)param_5 + 1);
  *param_3 = param_5;
  for (psVar2 = (short *)((ulonglong)bVar1 + (longlong)param_5); (psVar2 < psVar4 && (*psVar2 != 0))
      ; psVar2 = (short *)((longlong)psVar2 + 1)) {
  }
  *param_4 = ((int)psVar2 - (int)param_5) + 2;
  return 0;
}



===== SMBiosCalculateComputerHardwareId @ 1c000bac0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

NTSTATUS SMBiosCalculateComputerHardwareId(undefined8 *param_1,uint param_2,undefined8 param_3)

{
  ushort *puVar1;
  uint uVar2;
  NTSTATUS NVar3;
  wchar_t *pwVar4;
  wchar_t *pwVar5;
  undefined8 uVar6;
  uint uVar7;
  undefined8 *puVar8;
  ulonglong uVar9;
  uint uVar10;
  undefined1 auStack_c8 [32];
  uint local_a8;
  uint local_a0;
  uint local_98;
  uint local_90;
  uint local_88;
  uint local_80;
  uint local_78;
  uint local_70;
  uint local_68;
  uint local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_c8;
  pwVar5 = (wchar_t *)0x0;
  uVar10 = 0;
  uVar7 = 0;
  local_58 = 0;
  uStack_50 = 0;
  if (param_2 == 0) {
    return -0x3ffffff3;
  }
  puVar8 = param_1;
  do {
    uVar2 = uVar10 + 2;
    if (uVar7 == 0) {
      uVar2 = uVar10;
    }
    uVar10 = uVar2;
    if (*(ushort *)*puVar8 != 0) {
      uVar10 = uVar10 + *(ushort *)*puVar8;
    }
    uVar7 = uVar7 + 1;
    puVar8 = puVar8 + 1;
  } while (uVar7 < param_2);
  if (uVar10 < 3) {
    return -0x3ffffff3;
  }
  pwVar4 = (wchar_t *)ExAllocatePool2(0x102,uVar10 + 2,0x69424d53);
  if (pwVar4 == (wchar_t *)0x0) {
    return -0x3fffff66;
  }
  uVar9 = 0;
  uVar10 = 0;
  do {
    puVar1 = (ushort *)*param_1;
    if (uVar10 != 0) {
      pwVar4[uVar9] = L'&';
      uVar9 = (ulonglong)((int)uVar9 + 1);
    }
    if (*puVar1 != 0) {
      memmove(pwVar4 + uVar9,*(void **)(puVar1 + 4),(ulonglong)*puVar1);
      uVar9 = (ulonglong)((int)uVar9 + (uint)(*puVar1 >> 1));
    }
    uVar10 = uVar10 + 1;
    param_1 = param_1 + 1;
  } while (uVar10 < param_2);
  pwVar4[uVar9] = L'\0';
  NVar3 = SMBiosClass5GuidFromBlob(0x26,(PUCHAR)pwVar4,(int)uVar9 * 2,(uint *)&local_58);
  if (-1 < NVar3) {
    pwVar5 = (wchar_t *)ExAllocatePool2(0x42,0x60,0x69424d53);
    if (pwVar5 == (wchar_t *)0x0) {
      NVar3 = -0x3fffff66;
      pwVar5 = pwVar4;
      goto LAB_1c000bcdc;
    }
    local_60 = (uint)uStack_50._7_1_;
    local_68 = (uint)uStack_50._6_1_;
    local_70 = (uint)uStack_50._5_1_;
    local_78 = (uint)uStack_50._4_1_;
    local_80 = (uint)uStack_50._3_1_;
    local_88 = (uint)uStack_50._2_1_;
    local_90 = (uint)uStack_50._1_1_;
    local_98 = (uint)(byte)uStack_50;
    local_a0 = (uint)local_58._6_2_;
    local_a8 = (uint)local_58._4_2_;
    uVar6 = RtlStringCchPrintfW(pwVar5,0x30,L"{%08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x}",
                                local_58 & 0xffffffff);
    NVar3 = (NTSTATUS)uVar6;
    if (-1 < NVar3) {
      RtlInitUnicodeString(param_3,pwVar5);
      pwVar5 = pwVar4;
      goto LAB_1c000bcdc;
    }
  }
  ExFreePoolWithTag(pwVar4,0);
  if (pwVar5 == (wchar_t *)0x0) {
    return NVar3;
  }
LAB_1c000bcdc:
  ExFreePoolWithTag(pwVar5,0);
  return NVar3;
}



===== SMBiosClass5GuidFromBlob @ 1c000bd30 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

NTSTATUS SMBiosClass5GuidFromBlob(undefined8 param_1,PUCHAR param_2,ULONG param_3,uint *param_4)

{
  char cVar1;
  ushort uVar2;
  NTSTATUS NVar3;
  uint uVar4;
  PUCHAR pbHashObject;
  PUCHAR pbOutput;
  size_t _Size;
  undefined1 auStackY_b8 [32];
  ULONG local_74 [3];
  BCRYPT_HASH_HANDLE local_68;
  BCRYPT_ALG_HANDLE local_60;
  uint local_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_b8;
  pbOutput = (PUCHAR)0x0;
  local_60 = (BCRYPT_HANDLE)0x0;
  local_68 = (BCRYPT_HASH_HANDLE)0x0;
  local_74[0] = 0;
  local_74[1] = 0;
  pbHashObject = (PUCHAR)0x0;
  local_58 = SMBiosHardwareIdNameSpace;
  uStack_54 = _DAT_1c0008184;
  uStack_50 = uRam00000001c0008188;
  uStack_4c = uRam00000001c000818c;
  NVar3 = BCryptOpenAlgorithmProvider(&local_60,L"SHA1",L"Microsoft Primitive Provider",0);
  if ((-1 < NVar3) &&
     (NVar3 = BCryptGetProperty(local_60,L"ObjectLength",(PUCHAR)local_74,4,local_74 + 1,0),
     -1 < NVar3)) {
    pbHashObject = (PUCHAR)ExAllocatePool2(0x102,local_74[0],0x69424d53);
    if (pbHashObject == (PUCHAR)0x0) {
      NVar3 = -0x3fffffe9;
    }
    else {
      NVar3 = BCryptCreateHash(local_60,&local_68,pbHashObject,local_74[0],(PUCHAR)0x0,0,0);
      if (-1 < NVar3) {
        cVar1 = SMBiosBigEndian();
        if (cVar1 == '\0') {
          local_58 = SMBiosNetworkToHostLong(SMBiosHardwareIdNameSpace);
          uVar2 = SMBiosNetworkToHostShort((ushort)_DAT_1c0008184);
          uStack_54 = CONCAT22(uStack_54._2_2_,uVar2);
          uVar2 = SMBiosNetworkToHostShort((ushort)((uint)_DAT_1c0008184 >> 0x10));
          uStack_54 = CONCAT22(uVar2,(undefined2)uStack_54);
        }
        _Size = 0x10;
        NVar3 = BCryptHashData(local_68,(PUCHAR)&local_58,0x10,0);
        if (((-1 < NVar3) && (NVar3 = BCryptHashData(local_68,param_2,param_3,0), -1 < NVar3)) &&
           (NVar3 = BCryptGetProperty(local_60,L"HashDigestLength",(PUCHAR)local_74,4,local_74 + 1,0
                                     ), -1 < NVar3)) {
          pbOutput = (PUCHAR)ExAllocatePool2(0x102,local_74[0],0x69424d53);
          if (pbOutput == (PUCHAR)0x0) {
            NVar3 = -0x3fffffe9;
          }
          else {
            NVar3 = BCryptFinishHash(local_68,pbOutput,local_74[0],0);
            if (-1 < NVar3) {
              if (local_74[0] < 0x10) {
                _Size = (size_t)local_74[0];
              }
              memmove(param_4,pbOutput,_Size);
              if (cVar1 == '\0') {
                uVar4 = SMBiosNetworkToHostLong(*param_4);
                *param_4 = uVar4;
                uVar2 = SMBiosNetworkToHostShort((ushort)param_4[1]);
                *(ushort *)(param_4 + 1) = uVar2;
                uVar2 = SMBiosNetworkToHostShort(*(ushort *)((longlong)param_4 + 6));
                *(ushort *)((longlong)param_4 + 6) = uVar2;
              }
              *(ushort *)((longlong)param_4 + 6) =
                   *(ushort *)((longlong)param_4 + 6) & 0xfff | 0x5000;
              *(byte *)(param_4 + 2) = (byte)param_4[2] & 0x3f | 0x80;
            }
          }
        }
      }
    }
  }
  if (local_68 != (BCRYPT_HASH_HANDLE)0x0) {
    BCryptDestroyHash(local_68);
  }
  if (local_60 != (BCRYPT_ALG_HANDLE)0x0) {
    BCryptCloseAlgorithmProvider(local_60,0);
  }
  if (pbOutput != (PUCHAR)0x0) {
    ExFreePoolWithTag(pbOutput,0);
  }
  if (pbHashObject != (PUCHAR)0x0) {
    ExFreePoolWithTag(pbHashObject,0);
  }
  return NVar3;
}



===== SMBiosStringsInitialize @ 1c000c070 =====

undefined8 SMBiosStringsInitialize(void)

{
  undefined *puVar1;
  longlong lVar2;
  
  KeInitializeSpinLock(&SMBiosStringLock);
  RtlInitUnicodeString(&SMBiosStrings,0);
  RtlInitUnicodeString(&DAT_1c00082d0,L"BaseBoardManufacturer");
  RtlInitUnicodeString(&DAT_1c00082e0,0);
  RtlInitUnicodeString(&DAT_1c00082f0,L"BaseBoardProduct");
  RtlInitUnicodeString(&DAT_1c0008300,0);
  RtlInitUnicodeString(&DAT_1c0008310,L"BaseBoardVersion");
  RtlInitUnicodeString(&DAT_1c0008320,0);
  RtlInitUnicodeString(&DAT_1c0008330,L"BIOSReleaseDate");
  RtlInitUnicodeString(&DAT_1c0008340,0);
  RtlInitUnicodeString(&DAT_1c0008350,L"BIOSVendor");
  RtlInitUnicodeString(&DAT_1c0008360,0);
  RtlInitUnicodeString(&DAT_1c0008370,L"BIOSVersion");
  RtlInitUnicodeString(&DAT_1c0008380,0);
  RtlInitUnicodeString(&DAT_1c0008390,L"SystemFamily");
  RtlInitUnicodeString(&DAT_1c00083a0,0);
  RtlInitUnicodeString(&DAT_1c00083b0,L"SystemManufacturer");
  RtlInitUnicodeString(&DAT_1c00083c0,0);
  RtlInitUnicodeString(&DAT_1c00083d0,L"SystemProductName");
  RtlInitUnicodeString(&DAT_1c00083e0,0);
  RtlInitUnicodeString(&DAT_1c00083f0,L"SystemSKU");
  RtlInitUnicodeString(&DAT_1c0008400,0);
  RtlInitUnicodeString(&DAT_1c0008410,L"SystemVersion");
  SMBiosSystemBiosMajorRelease = 0xff;
  puVar1 = &SMBiosHardwareIds;
  SMBiosSystemBiosMinorRelease = 0xff;
  lVar2 = 10;
  SMBiosSystemECFirmwareMajorRelease = 0xff;
  SMBiosSystemECFirmwareMinorRelease = 0xff;
  SMBiosEnableTargetedContentDistribution = 0;
  do {
    RtlInitUnicodeString(puVar1,0);
    puVar1 = puVar1 + 0x10;
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  RtlInitUnicodeString(&SMBiosComputerId,0);
  return 0;
}



===== SMBiosDriverPnp @ 1c000c310 =====

int SMBiosDriverPnp(longlong param_1,longlong param_2)

{
  byte *pbVar1;
  byte bVar2;
  char cVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 *puVar6;
  int iVar7;
  undefined8 uVar8;
  
  lVar4 = *(longlong *)(param_1 + 0x40);
  lVar5 = *(longlong *)(param_2 + 0xb8);
  iVar7 = IoAcquireRemoveLockEx(lVar4 + 0x18,param_2,"",1,0x20);
  if (iVar7 < 0) {
    *(int *)(param_2 + 0x30) = iVar7;
    IofCompleteRequest(param_2,0);
  }
  else {
    bVar2 = *(byte *)(lVar5 + 1);
    if (bVar2 == 2) {
      IoWMIRegistrationControl(param_1,2);
      *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
      *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
      *(undefined4 *)(param_2 + 0x30) = 0;
      iVar7 = IofCallDriver(*(undefined8 *)(lVar4 + 8),param_2);
      IoReleaseRemoveLockAndWaitEx(lVar4 + 0x18,param_2,0x20);
      IoDetachDevice(*(undefined8 *)(lVar4 + 8));
      IoDeleteDevice(param_1);
    }
    else {
      if ((bVar2 < 0x18) && ((0x800062U >> (bVar2 & 0x1f) & 1) != 0)) {
        *(undefined4 *)(param_2 + 0x30) = 0;
      }
      cVar3 = *(char *)(lVar5 + 1);
      if (cVar3 == '\0') {
        puVar6 = *(undefined8 **)(param_2 + 0xb8);
        puVar6[-9] = *puVar6;
        puVar6[-8] = puVar6[1];
        puVar6[-7] = puVar6[2];
        puVar6[-6] = puVar6[3];
        *(undefined4 *)(puVar6 + -5) = *(undefined4 *)(puVar6 + 4);
        *(undefined4 *)((longlong)puVar6 + -0x24) = *(undefined4 *)((longlong)puVar6 + 0x24);
        *(undefined4 *)(puVar6 + -4) = *(undefined4 *)(puVar6 + 5);
        *(undefined4 *)((longlong)puVar6 + -0x1c) = *(undefined4 *)((longlong)puVar6 + 0x2c);
        puVar6[-3] = puVar6[6];
        *(undefined1 *)((longlong)puVar6 + -0x45) = 0;
        if (*(int *)(lVar4 + 0x38) == 0) {
          pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
          *pbVar1 = *pbVar1 | 1;
          uVar8 = IoAllocateWorkItem(param_1);
          lVar5 = *(longlong *)(param_2 + 0xb8);
          *(code **)(lVar5 + -0x10) = SMBiosDriverPnpComplete;
          *(undefined8 *)(lVar5 + -8) = uVar8;
          *(undefined1 *)(lVar5 + -0x45) = 0xe0;
          IofCallDriver(*(undefined8 *)(lVar4 + 8),param_2);
          return 0x103;
        }
      }
      else {
        if ((cVar3 == '\x04') && (*(int *)(lVar4 + 0x38) == 1)) {
          SMBiosDataResetObjects();
          *(undefined4 *)(lVar4 + 0x38) = 0;
        }
        *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
        *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
      }
      iVar7 = IofCallDriver(*(undefined8 *)(lVar4 + 8),param_2);
      IoReleaseRemoveLockEx(lVar4 + 0x18,param_2,0x20);
    }
  }
  return iVar7;
}



===== SMBiosCPUGatherData @ 1c000c510 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SMBiosCPUGatherData(void)

{
  int iVar1;
  undefined1 auStack_278 [32];
  undefined8 local_258;
  code *local_248 [2];
  wchar_t *local_238;
  undefined4 local_228;
  code *local_210;
  wchar_t *local_200;
  undefined4 local_1f0;
  code *local_1d8;
  wchar_t *local_1c8;
  undefined4 local_1b8;
  code *local_1a0;
  wchar_t *local_190;
  undefined4 local_180;
  code *local_168;
  wchar_t *local_158;
  undefined4 local_148;
  code *local_130;
  wchar_t *local_120;
  undefined4 local_110;
  code *local_f8;
  wchar_t *local_e8;
  undefined4 local_d8;
  code *local_c0;
  wchar_t *local_b0;
  undefined4 local_a0;
  code *local_88;
  wchar_t *local_78;
  undefined4 local_68;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_278;
  memset(local_248,0,0x230);
  local_238 = L"~MHz";
  local_200 = L"Component Information";
  local_1c8 = L"Configuration Data";
  local_190 = L"Feature Set";
  local_158 = L"Identifier";
  local_120 = L"ProcessorNameString";
  local_e8 = L"Update Signature";
  local_b0 = L"Update Status";
  local_228 = 0;
  local_248[0] = SMBiosCPUGatherDataQueryRoutine;
  local_1f0 = 0;
  local_210 = SMBiosCPUGatherDataQueryRoutine;
  local_1b8 = 0;
  local_1d8 = SMBiosCPUGatherDataQueryRoutine;
  local_180 = 0;
  local_1a0 = SMBiosCPUGatherDataQueryRoutine;
  local_148 = 0;
  local_168 = SMBiosCPUGatherDataQueryRoutine;
  local_110 = 0;
  local_130 = SMBiosCPUGatherDataQueryRoutine;
  local_d8 = 0;
  local_f8 = SMBiosCPUGatherDataQueryRoutine;
  local_a0 = 0;
  local_c0 = SMBiosCPUGatherDataQueryRoutine;
  local_68 = 0;
  local_88 = SMBiosCPUGatherDataQueryRoutine;
  local_258 = 0;
  local_78 = L"VendorIdentifier";
  iVar1 = RtlQueryRegistryValuesEx(0,rgzCPUIdentifier,local_248,0);
  if (-1 < iVar1) {
    SMBiosCPUGatherRegisters();
  }
  return;
}



===== SMBiosRegistryWriteValueW @ 1c000c660 =====

void SMBiosRegistryWriteValueW
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  ZwSetValueKey(param_2,param_1,0,3,param_3,param_4);
  return;
}



===== SMBiosSMBiosFindStringAndZero @ 1c000c6a0 =====

undefined8 SMBiosSMBiosFindStringAndZero(longlong param_1,int param_2,uint param_3)

{
  char *_Str;
  short *psVar1;
  uint uVar2;
  
  if (param_2 != 0) {
    _Str = (char *)((ulonglong)*(byte *)(param_1 + 1) + param_1);
    for (uVar2 = 0; uVar2 < param_2 - 1U; uVar2 = uVar2 + 1) {
      psVar1 = (short *)strchr(_Str,0);
      _Str = (char *)((longlong)psVar1 + 1);
      if (((char *)((ulonglong)param_3 + param_1) <= _Str) || (*psVar1 == 0)) {
        return 0xc0000034;
      }
    }
    for (; (_Str < (char *)((ulonglong)param_3 + param_1) && (*_Str != '\0')); _Str = _Str + 1) {
      *_Str = ' ';
    }
  }
  return 0;
}



===== SMBiosRegistryOpenHandleW @ 1c000c730 =====

void SMBiosRegistryOpenHandleW(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_38 = 0x30;
  local_20 = 0x240;
  local_18 = 0;
  uStack_10 = 0;
  local_30 = param_2;
  local_28 = param_1;
  ZwOpenKey(param_3,0x20019,&local_38);
  return;
}



===== SMBiosRegistryCreateHandleW @ 1c000c790 =====

void SMBiosRegistryCreateHandleW(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_38 = 0x30;
  *param_3 = 0;
  local_20 = 0x240;
  local_18 = 0;
  uStack_10 = 0;
  local_30 = param_2;
  local_28 = param_1;
  ZwCreateKey(param_3,0x20006,&local_38,0,0,1,0);
  return;
}



===== entry @ 1c000d010 =====

void entry(longlong param_1,short *param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 1c000d044 =====

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



===== DriverEntry @ 1c000d078 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(longlong param_1,short *param_2)

{
  int iVar1;
  int iVar2;
  
  _SMBiosRegistryPath = 0;
  DAT_1c00082b2 = *param_2 + 2;
  DAT_1c00082b8 = ExAllocatePool2(0x102,DAT_1c00082b2,0x69424d53);
  if (DAT_1c00082b8 == 0) {
    DAT_1c00082b2 = 0;
  }
  else {
    RtlCopyUnicodeString(&SMBiosRegistryPath,param_2);
  }
  SMBiosDataInitializeObject
            ((undefined8 *)&SMBiosDriverAcpiObject,L"AcpiData",0x69706341,
             (undefined4 *)&SMBiosGuidAcpi);
  SMBiosDataInitializeObject
            ((undefined8 *)&SMBiosDriverSMBiosObject,L"SMBiosData",0x69424d53,
             (undefined4 *)&SMBiosGuidSMBios);
  SMBiosDataInitializeObject
            ((undefined8 *)&SMBiosDriverSMBiosLightObject,L"SMbiosLightData",0x69424d53,
             (undefined4 *)&SMBiosGuidSMBiosLight);
  SMBiosDataInitializeObject
            ((undefined8 *)&SMBiosDriverRegistersObject,L"RegistersData",0x67655248,
             (undefined4 *)&SMBiosGuidRegisters);
  SMBiosDataInitializeObject
            ((undefined8 *)&SMBiosDriverRegistryObject,L"BiosData",0x736f6942,
             (undefined4 *)&SMBiosGuidBios);
  SMBiosStringsInitialize();
  *(code **)(*(longlong *)(param_1 + 0x30) + 8) = SMBiosDriverAddDevice;
  *(code **)(param_1 + 0x148) = SMBiosDriverPnp;
  *(code **)(param_1 + 0x120) = SMBiosDriverPower;
  *(code **)(param_1 + 0x128) = SMBiosDriverWmi;
  *(code **)(param_1 + 0x68) = SMBiosDriverUnload;
  SMBiosACPIProcessACPIData();
  SMBiosCPUGatherData();
  SMBiosBugCheckRegisterCallbacks();
  SMBiosRegistrySaveData();
  iVar1 = IoReportRootDevice(param_1);
  iVar2 = 0;
  if (iVar1 < 0) {
    iVar2 = iVar1;
  }
  return iVar2;
}


