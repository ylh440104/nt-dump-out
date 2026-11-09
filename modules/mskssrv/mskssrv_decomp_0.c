
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



===== __C_specific_handler @ 14000101d =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00014000101d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== _purecall @ 140001030 =====

void _purecall(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140001030. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _purecall();
  return;
}



===== BuildFilterData @ 140001044 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong BuildFilterData(undefined8 param_1,undefined4 param_2,undefined8 *param_3,int *param_4)

{
  int iVar1;
  ulonglong uVar2;
  undefined4 *puVar3;
  ulonglong uVar4;
  int iVar5;
  int *piVar6;
  longlong lVar7;
  uint uVar8;
  int *piVar9;
  ulonglong uVar10;
  uint uVar11;
  uint uVar12;
  undefined1 auStackY_118 [32];
  uint local_d8 [5];
  uint local_c4;
  longlong local_c0;
  int *local_b8;
  int *local_b0;
  undefined8 local_a8;
  int *local_a0;
  undefined4 local_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 local_88;
  undefined4 local_84;
  uint local_80;
  undefined4 local_7c;
  undefined8 local_78;
  undefined8 uStack_70;
  longlong local_68 [6];
  
  local_68[4] = __security_cookie ^ (ulonglong)auStackY_118;
  local_d8[2] = 0;
  local_d8[3] = param_2;
  local_b8 = (int *)param_3;
  local_a8 = param_1;
  local_a0 = param_4;
  uVar2 = GetFilterPinCount(param_1,local_d8 + 2);
  if (-1 < (int)uVar2) {
    uVar4 = 0;
    local_c4 = 0;
    uVar8 = local_d8[2];
    if (local_d8[2] != 0) {
      do {
        uVar11 = local_c4;
        local_d8[0] = 0;
        uVar8 = uVar8 - 1;
        uVar2 = GetPinTypes(param_1,uVar8,3,local_d8);
        if ((int)uVar2 < 0) {
          return uVar2;
        }
        uVar4 = (ulonglong)((int)uVar4 + local_d8[0]);
        uVar2 = GetPinTypes(param_1,uVar8,6,local_d8);
        if ((int)uVar2 < 0) {
          return uVar2;
        }
        local_c4 = uVar11 + local_d8[0];
      } while (uVar8 != 0);
    }
    uVar8 = local_c4;
    uVar2 = uVar2 & 0xffffffff;
    if (((local_d8[2] < 0x2711) && (uVar11 = (uint)uVar4, uVar11 < 0x2711)) && (local_c4 < 0x2711))
    {
      uVar12 = local_d8[2] * 3 + uVar11 * 2;
      iVar5 = (local_c4 * 2 + 1 + uVar12 + uVar11) * 0x10 + local_d8[2] * 0x18;
      *param_4 = iVar5;
      local_d8[4] = uVar12;
      puVar3 = (undefined4 *)ExAllocatePoolWithTag(0x401,iVar5,0x6466534b);
      *(undefined4 **)local_b8 = puVar3;
      if (puVar3 != (undefined4 *)0x0) {
        piVar9 = puVar3 + 4;
        puVar3[1] = local_d8[3];
        *puVar3 = 2;
        puVar3[3] = 0;
        puVar3[2] = local_d8[2];
        uVar10 = (ulonglong)local_d8[2];
        uVar11 = 0;
        local_d8[3] = 0;
        local_d8[0] = 0;
        local_b0 = piVar9 + (uVar10 * 3 + uVar4 * 2 + (ulonglong)uVar8) * 2;
        local_b8 = local_b0 + (ulonglong)uVar12 * 4;
        if (local_d8[2] != 0) {
          do {
            local_68[0] = 0;
            local_c0 = 0;
            *piVar9 = 0x33697030;
            *(char *)piVar9 = (char)uVar11 + '0';
            local_68[2] = 0;
            local_68[3] = 0;
            uVar8 = GetPinFlags(param_1,uVar11,(uint *)(piVar9 + 1));
            uVar2 = (ulonglong)uVar8;
            if ((int)uVar8 < 0) goto LAB_14000153e;
            local_78 = 0;
            local_d8[1] = 0;
            local_88 = 0;
            local_7c = 0;
            local_84 = 1;
            local_98 = 0x8c134960;
            uStack_94 = 0x11cf51ad;
            uStack_90 = 0xf8948a87;
            uStack_8c = 0xc101;
            local_80 = uVar11;
            uVar8 = KsSynchronousIoControlDevice(param_1,0,0x2f0003,&local_98);
            uVar2 = (ulonglong)uVar8;
            if ((int)uVar8 < 0) goto LAB_14000153e;
            piVar9[2] = (uint)local_78;
            if (1 < (uint)local_78) {
              piVar9[1] = piVar9[1] | 4;
            }
            uVar4 = GetPinTypeList(param_1,uVar11,3,local_68);
            lVar7 = local_68[0];
            uVar2 = uVar4 & 0xffffffff;
            if ((int)uVar4 < 0) goto LAB_14000153e;
            piVar9[3] = *(int *)(local_68[0] + 4);
            uVar4 = GetPinTypeList(param_1,uVar11,6,&local_c0);
            uVar2 = uVar4 & 0xffffffff;
            if ((int)uVar4 < 0) {
LAB_140001532:
              ExFreePool(lVar7);
LAB_14000153e:
              ExFreePool(puVar3);
              return uVar2;
            }
            local_d8[1] = 0;
            local_7c = 0;
            piVar9[4] = *(int *)(local_c0 + 4);
            local_98 = 0x8c134960;
            uStack_94 = 0x11cf51ad;
            uStack_90 = 0xf8948a87;
            uStack_8c = 0xc101;
            local_88 = 0xb;
            local_84 = 1;
            local_80 = uVar11;
            uVar8 = KsSynchronousIoControlDevice(param_1,0,0x2f0003);
            uVar2 = (ulonglong)uVar8;
            iVar5 = (int)puVar3;
            if ((int)uVar8 < 0) {
              if (uVar8 != 0xc0000225) {
                ExFreePool(lVar7);
                lVar7 = local_c0;
                goto LAB_140001532;
              }
              piVar9[5] = 0;
              uVar2 = 0;
            }
            else {
              InsertCacheItem(local_68 + 2,0x10,iVar5,(longlong)local_b0,local_d8,piVar9 + 5);
            }
            piVar6 = local_b0;
            local_d8[1] = 0;
            piVar9 = piVar9 + 6;
            if (*(int *)(lVar7 + 4) != 0) {
              uVar8 = 0;
              do {
                piVar9[1] = 0;
                *piVar9 = 0x33797430;
                *(char *)piVar9 = (char)uVar8 + '0';
                local_68[0] = 0;
                local_68[1] = 0;
                local_78 = 0;
                uStack_70 = 0;
                ExtractMediaTypes(lVar7,uVar8,local_68,&local_78);
                InsertCacheItem(local_68,0x10,iVar5,(longlong)piVar6,local_d8,piVar9 + 2);
                InsertCacheItem(&local_78,0x10,iVar5,(longlong)piVar6,local_d8,piVar9 + 3);
                piVar9 = piVar9 + 4;
                uVar8 = uVar8 + 1;
              } while (uVar8 < *(uint *)(lVar7 + 4));
              param_1 = local_a8;
              uVar12 = local_d8[4];
            }
            ExFreePool(lVar7);
            piVar6 = local_b8;
            lVar7 = local_c0;
            local_d8[1] = 0;
            if (*(int *)(local_c0 + 4) != 0) {
              uVar8 = 0;
              do {
                InsertCacheItem((void *)(lVar7 + ((ulonglong)uVar8 * 3 + 1) * 8),0x18,iVar5,
                                (longlong)piVar6,local_d8 + 3,piVar9);
                piVar9 = piVar9 + 1;
                uVar8 = uVar8 + 1;
              } while (uVar8 < *(uint *)(lVar7 + 4));
              param_1 = local_a8;
              uVar12 = local_d8[4];
            }
            ExFreePool(lVar7);
            uVar10 = (ulonglong)local_d8[2];
            uVar11 = uVar11 + 1;
          } while (uVar11 < local_d8[2]);
        }
        uVar8 = local_d8[3];
        iVar5 = uVar12 - local_d8[0];
        if (iVar5 * 0x10 != 0) {
          uVar11 = (uint)uVar10;
          piVar9 = puVar3 + 4;
          while (uVar11 != 0) {
            piVar6 = piVar9 + (ulonglong)(uint)piVar9[3] * 4 + 6;
            for (iVar1 = piVar9[4]; iVar1 != 0; iVar1 = iVar1 + -1) {
              *piVar6 = *piVar6 + iVar5 * -0x10;
              piVar6 = piVar6 + 1;
            }
            uVar11 = (int)uVar10 - 1;
            uVar10 = (ulonglong)uVar11;
            piVar9 = piVar6;
          }
          memmove((void *)((longlong)local_b8 - (ulonglong)(uint)(iVar5 * 0x10)),local_b8,
                  (ulonglong)local_d8[3] * 0x18);
          *local_a0 = *local_a0 + iVar5 * -0x10;
        }
        *local_a0 = *local_a0 + (uVar8 - local_c4) * 0x18;
        return uVar2;
      }
    }
    uVar2 = 0xc000009a;
  }
  return uVar2;
}



===== Feature_220357944__private_IsEnabledDeviceUsageNoInline @ 140001598 =====

ulonglong Feature_220357944__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_220357944__private_featureState;
  if ((Feature_220357944__private_featureState & 0x10) == 0) {
    uVar1 = Feature_220357944__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_220357944__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_220357944__private_IsEnabledFallback @ 1400015d0 =====

void Feature_220357944__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&wil_details_featureDescriptors_a);
  return;
}



===== Feature_3602159931__private_IsEnabledDeviceUsageNoInline @ 1400015ec =====

ulonglong Feature_3602159931__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_3602159931__private_featureState;
  if ((Feature_3602159931__private_featureState & 0x10) == 0) {
    uVar1 = Feature_3602159931__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_3602159931__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_3602159931__private_IsEnabledFallback @ 140001624 =====

void Feature_3602159931__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_3602159931__private_descriptor);
  return;
}



===== FsAllocAndLockMdl @ 140001640 =====

/* WARNING: Removing unreachable block (ram,0x0001400016c6) */

undefined8 FsAllocAndLockMdl(longlong param_1,int param_2,longlong *param_3)

{
  longlong lVar1;
  undefined8 uVar2;
  
  uVar2 = 0;
  if (((param_1 == 0) || (param_2 == 0)) || (param_3 == (longlong *)0x0)) {
    uVar2 = 0xc000000d;
  }
  else {
    lVar1 = IoAllocateMdl(param_1,param_2,0,0,0);
    if (lVar1 == 0) {
      uVar2 = 0xc000009a;
    }
    else {
      MmProbeAndLockPages(lVar1,1);
      *param_3 = lVar1;
    }
  }
  return uVar2;
}



===== FsDispatchCleanUp @ 1400016f0 =====

undefined8 FsDispatchCleanUp(undefined8 param_1,_IRP *param_2)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_2 + 0xb8);
  if (*(longlong *)(*(longlong *)(lVar1 + 0x30) + 0x20) == -1) {
    FSRendezvousClearWnf();
    *(undefined8 *)(*(longlong *)(lVar1 + 0x30) + 0x20) = 0;
  }
  if (*(longlong *)(*(longlong *)(lVar1 + 0x30) + 0x20) != 0) {
    FSRendezvousClose(param_2);
  }
  *(undefined4 *)(param_2 + 0x30) = 0;
  IofCompleteRequest(param_2,0);
  return 0;
}



===== FsMapLockedPages @ 14000175c =====

undefined8 FsMapLockedPages(longlong param_1,undefined4 param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar2 = 0;
  if ((param_1 == 0) || (param_3 == (undefined8 *)0x0)) {
    uVar2 = 0xc000000d;
  }
  else {
    *param_3 = 0;
    uVar1 = MmMapLockedPagesSpecifyCache(param_1,1,1,0,0,param_2);
    *param_3 = uVar1;
  }
  return uVar2;
}



===== GetFilterPinCount @ 1400017b8 =====

void GetFilterPinCount(undefined8 param_1,undefined8 param_2)

{
  undefined4 local_res18 [4];
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  local_res18[0] = 0;
  local_18 = 1;
  local_14 = 1;
  local_28 = 0x8c134960;
  uStack_24 = 0x11cf51ad;
  uStack_20 = 0xf8948a87;
  uStack_1c = 0xc101;
  KsSynchronousIoControlDevice(0x8c134960,0,0x2f0003,&local_28,0x18,param_2,4,local_res18);
  return;
}



===== GetPinFlags @ 140001820 =====

void GetPinFlags(undefined8 param_1,undefined4 param_2,uint *param_3)

{
  int iVar1;
  int local_res10 [2];
  undefined4 local_res18 [2];
  int local_res20 [2];
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  *param_3 = 0;
  local_res10[0] = 0;
  local_res20[0] = 0;
  local_res18[0] = 0;
  local_1c = 0;
  local_38 = 0x8c134960;
  uStack_34 = 0x11cf51ad;
  uStack_30 = 0xf8948a87;
  uStack_2c = 0xc101;
  local_28 = 9;
  local_24 = 1;
  local_20 = param_2;
  iVar1 = KsSynchronousIoControlDevice
                    (0x8c134960,0,0x2f0003,&local_38,0x20,local_res10,4,local_res18);
  if ((-1 < iVar1) && (local_res10[0] == 0)) {
    *param_3 = *param_3 | 1;
  }
  local_28 = 2;
  iVar1 = KsSynchronousIoControlDevice(param_1,0,0x2f0003,&local_38,0x20,local_res20,4,local_res18);
  if ((-1 < iVar1) && (local_res20[0] == 2)) {
    *param_3 = *param_3 | 8;
  }
  return;
}



===== GetPinTypeList @ 14000190c =====

ulonglong GetPinTypeList(undefined8 param_1,undefined4 param_2,undefined4 param_3,longlong *param_4)

{
  uint uVar1;
  ulonglong uVar2;
  longlong lVar3;
  undefined4 local_res10 [2];
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  local_res10[0] = 0;
  local_c = 0;
  local_28 = 0x8c134960;
  uStack_24 = 0x11cf51ad;
  uStack_20 = 0xf8948a87;
  uStack_1c = 0xc101;
  local_14 = 1;
  local_18 = param_3;
  local_10 = param_2;
  uVar2 = KsSynchronousIoControlDevice(0x8c134960,0,0x2f0003,&local_28,0x20,0,0,local_res10);
  if ((int)uVar2 < 0) {
    if ((int)uVar2 == -0x7ffffffb) {
      lVar3 = ExAllocatePoolWithTag(0x401,local_res10[0],0x7470534b);
      *param_4 = lVar3;
      if (lVar3 == 0) {
        uVar2 = 0xc000009a;
      }
      else {
        uVar1 = KsSynchronousIoControlDevice
                          (param_1,0,0x2f0003,&local_28,0x20,lVar3,local_res10[0],local_res10);
        uVar2 = (ulonglong)uVar1;
        if ((int)uVar1 < 0) {
          ExFreePool(*param_4);
        }
      }
    }
  }
  else {
    uVar2 = 0xc00000e5;
  }
  return uVar2;
}



===== GetPinTypes @ 140001a24 =====

void GetPinTypes(undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 local_res10 [6];
  undefined8 local_38;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  local_38 = 0;
  local_res10[0] = 0;
  local_14 = 0;
  local_1c = 1;
  local_30 = 0x8c134960;
  uStack_2c = 0x11cf51ad;
  uStack_28 = 0xf8948a87;
  uStack_24 = 0xc101;
  local_20 = param_3;
  local_18 = param_2;
  iVar1 = KsSynchronousIoControlDevice(0x8c134960,0,0x2f0003,&local_30,0x20,&local_38,8,local_res10)
  ;
  if (-1 < iVar1) {
    *param_4 = local_38._4_4_;
  }
  return;
}



===== PropertySrv @ 140001ab0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong PropertySrv(longlong param_1,longlong param_2,undefined4 *param_3)

{
  undefined8 *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  wchar_t *_Dst;
  ulonglong uVar5;
  ulonglong uVar6;
  longlong lVar7;
  undefined1 auStack_178 [32];
  undefined8 *local_158;
  int *local_150;
  longlong *local_148;
  undefined4 local_140;
  undefined4 local_138;
  undefined8 local_130;
  undefined4 local_128;
  undefined4 local_120;
  undefined8 local_118;
  undefined4 local_110;
  int local_108;
  undefined4 local_104;
  undefined8 local_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  undefined8 local_e0;
  undefined4 local_d8 [2];
  undefined8 local_d0;
  longlong local_c8 [3];
  undefined4 local_b0;
  undefined4 local_ac;
  undefined8 local_a8;
  longlong *local_a0;
  undefined4 local_98;
  undefined4 local_94;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  uint local_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined1 local_60 [4];
  int local_5c;
  int local_58;
  undefined4 local_54;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_178;
  local_100 = 0;
  local_c8[1] = 0;
  local_c8[2] = 0;
  local_c8[0] = 0;
  local_e0 = 0;
  uVar3 = *(uint *)(*(longlong *)(param_1 + 0xb8) + 8);
  if (*(short *)((longlong)param_3 + (ulonglong)(uVar3 >> 1) * 2 + -2) != 0) {
    return 0xc000000d;
  }
  if (*(int *)(param_2 + 0x10) == 0) {
    local_104 = 0x200000;
  }
  else {
    local_104 = *param_3;
    param_3 = param_3 + 1;
    uVar3 = uVar3 - 4;
  }
  uVar2 = uVar3 + 0x18;
  if ((uVar2 < uVar3) ||
     (_Dst = (wchar_t *)ExAllocatePoolWithTag(0x401,uVar2,0x6c73534b), _Dst == (wchar_t *)0x0)) {
    return 0xc000009a;
  }
  memmove(_Dst,param_3,(ulonglong)uVar3);
  if ((*_Dst == L'\\') && ((_Dst[1] == L'\\' && (_Dst[3] == L'\\')))) {
    if (_Dst[2] == L'?') {
      _Dst[1] = L'?';
    }
    else if (_Dst[2] == L'.') {
      builtin_wcsncpy(_Dst,L"\\DosDevices",0xc);
      memmove(_Dst + 0xb,(void *)((longlong)param_3 + 6),(ulonglong)uVar3 - 6);
    }
  }
  _Dst[(ulonglong)(uVar2 >> 1) - 1] = L'\0';
  RtlInitUnicodeString(local_c8 + 1,_Dst);
  uVar3 = IoOpenDeviceInterfaceRegistryKey(local_c8 + 1,0x20006,&local_100);
  uVar6 = (ulonglong)uVar3;
  if ((int)uVar3 < 0) goto LAB_140002096;
  local_f8 = 0;
  uStack_f0 = 0;
  RtlInitUnicodeString(&local_f8,L"Merit");
  if (*(int *)(param_2 + 0x10) == 0) {
    local_150 = local_d8;
    local_158 = (undefined8 *)CONCAT44(local_158._4_4_,0x13);
    local_d8[0] = 0;
    local_d0 = 0;
    local_ac = 0;
    local_94 = 0;
    local_70 = 0;
    uStack_68 = 0;
    iVar4 = ZwQueryValueKey(local_100,&local_f8,2,local_60);
    if (((-1 < iVar4) && (local_58 == 4)) && (local_5c - 3U < 2)) {
      local_104 = local_54;
    }
    local_110 = 0x101;
    local_a0 = local_c8 + 1;
    local_118 = 0;
    local_120 = 0;
    local_128 = 0;
    local_130 = 0;
    local_138 = 0;
    local_140 = 1;
    local_148 = (longlong *)((ulonglong)local_148 & 0xffffffff00000000);
    local_150 = (int *)((ulonglong)local_150 & 0xffffffff00000000);
    local_158 = (undefined8 *)0x0;
    local_b0 = 0x30;
    local_a8 = 0;
    local_98 = 0x640;
    local_90 = 0;
    uStack_88 = 0;
    uVar3 = IoCreateFile(&local_d0,0x80100000,&local_b0,&local_70);
    uVar6 = (ulonglong)uVar3;
    if (-1 < (int)uVar3) {
      local_158 = &local_e8;
      local_150 = (int *)0x0;
      local_e8 = 0;
      uVar3 = ObReferenceObjectByHandle(local_d0,0x120089,*(undefined8 *)IoFileObjectType_exref,0);
      uVar6 = (ulonglong)uVar3;
      ZwClose(local_d0);
      if (-1 < (int)uVar3) {
        local_108 = 0;
        local_80 = (undefined8 *)0x0;
        uVar5 = BuildFilterData(local_e8,local_104,&local_80,&local_108);
        uVar6 = uVar5 & 0xffffffff;
        if (-1 < (int)uVar5) {
          RtlInitUnicodeString(&local_f8,L"FilterData");
          puVar1 = local_80;
          local_150 = (int *)CONCAT44(local_150._4_4_,local_108);
          local_158 = local_80;
          uVar3 = ZwSetValueKey(local_100,&local_f8,0,3);
          uVar6 = (ulonglong)uVar3;
          ExFreePool(puVar1);
          if (-1 < (int)uVar3) {
            uVar6 = UpdateMediumCache(local_e8,(longlong)(local_c8 + 1));
            uVar6 = uVar6 & 0xffffffff;
          }
        }
        ObfDereferenceObject(local_e8);
      }
    }
  }
  else {
    uVar6 = Feature_220357944__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar6 == 0) {
      local_158 = (undefined8 *)&local_104;
      local_150 = (int *)CONCAT44(local_150._4_4_,4);
      uVar3 = ZwSetValueKey(local_100,&local_f8,0,4);
      uVar6 = (ulonglong)uVar3;
      if (-1 < (int)uVar3) {
LAB_140001f43:
        local_108 = 0;
        local_70 = 0;
        uStack_68 = 0;
        RtlInitUnicodeString(&local_f8,L"FilterData");
        local_150 = &local_108;
        local_158 = (undefined8 *)CONCAT44(local_158._4_4_,0x10);
        uVar3 = ZwQueryValueKey(local_100,&local_f8,2,&local_70);
        uVar6 = (ulonglong)uVar3;
        if (((uVar3 + 0x80000000 & 0x80000000) == 0) && (uVar3 != 0x80000005)) {
          uVar6 = 0;
        }
        else {
          lVar7 = ExAllocatePoolWithTag(0x401,local_108,0x6466534b);
          if (lVar7 != 0) {
            local_150 = &local_108;
            local_158 = (undefined8 *)CONCAT44(local_158._4_4_,local_108);
            uVar3 = ZwQueryValueKey(local_100,&local_f8,2,lVar7);
            uVar6 = (ulonglong)uVar3;
            if ((int)uVar3 < 0) {
              uVar6 = 0;
            }
            else if ((0xf < *(uint *)(lVar7 + 8)) && (*(int *)(lVar7 + 4) == 3)) {
              *(undefined4 *)(lVar7 + 0x10) = local_104;
              local_150 = (int *)CONCAT44(local_150._4_4_,*(uint *)(lVar7 + 8));
              local_158 = (undefined8 *)(lVar7 + 0xc);
              uVar3 = ZwSetValueKey(local_100,&local_f8,0,3);
              uVar6 = (ulonglong)uVar3;
            }
            ExFreePool(lVar7);
          }
        }
      }
    }
    else {
      local_158 = &local_e0;
      local_150 = (int *)0x0;
      uVar3 = ObReferenceObjectByHandle(local_100,0,*(undefined8 *)CmKeyObjectType_exref,0);
      if ((int)uVar3 < 0) {
LAB_140001ee8:
        local_80._4_4_ = 2;
        local_78 = uVar3;
      }
      else {
        local_148 = local_c8;
        local_150 = (int *)CONCAT71(local_150._1_7_,*(undefined1 *)(param_1 + 0x40));
        local_158 = *(undefined8 **)CmKeyObjectType_exref;
        uVar3 = ObOpenObjectByPointer(local_e0,0x600,0,0x20006);
        ObfDereferenceObject(local_e0);
        local_e0 = 0;
        if ((int)uVar3 < 0) goto LAB_140001ee8;
        local_158 = (undefined8 *)&local_104;
        local_150 = (int *)CONCAT44(local_150._4_4_,4);
        uVar3 = ZwSetValueKey(local_c8[0],&local_f8,0,4);
        if (-1 < (int)uVar3) goto LAB_140001f43;
        local_80._4_4_ = 1;
        local_78 = uVar3;
      }
      uVar6 = (ulonglong)local_78;
      local_80 = (undefined8 *)CONCAT44(local_80._4_4_,0x3c5165d);
      RtlLogUnexpectedCodepath(&local_80);
    }
  }
  ZwClose(local_100);
  uVar5 = Feature_220357944__private_IsEnabledDeviceUsageNoInline();
  if (((int)uVar5 != 0) && (local_c8[0] != 0)) {
    ZwClose();
  }
LAB_140002096:
  ExFreePool(_Dst);
  return uVar6;
}



===== UpdateMediumCache @ 1400020dc =====

ulonglong UpdateMediumCache(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  uint uVar7;
  longlong *plVar8;
  int local_res18 [2];
  uint local_res20 [2];
  undefined4 local_68 [2];
  longlong local_60;
  undefined4 local_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 local_48;
  undefined4 local_44;
  uint local_40;
  undefined4 local_3c;
  
  local_res20[0] = 0;
  uVar4 = GetFilterPinCount(param_1,local_res20);
  uVar6 = uVar4 & 0xffffffff;
  if (-1 < (int)uVar4) {
    uVar7 = 0;
    uVar4 = uVar6;
    if (local_res20[0] != 0) {
      do {
        uVar4 = uVar6;
        if ((int)uVar6 < 0) break;
        local_60 = 0;
        local_res18[0] = 0;
        local_68[0] = 0;
        local_3c = 0;
        local_58 = 0x8c134960;
        uStack_54 = 0x11cf51ad;
        uStack_50 = 0xf8948a87;
        uStack_4c = 0xc101;
        local_48 = 2;
        local_44 = 1;
        local_40 = uVar7;
        uVar2 = KsSynchronousIoControlDevice
                          (param_1,0,0x2f0003,&local_58,0x20,local_res18,4,local_68);
        uVar4 = (ulonglong)uVar2;
        if ((int)uVar2 < 0) break;
        uVar5 = GetPinTypeList(param_1,uVar7,6,&local_60);
        uVar6 = uVar5 & 0xffffffff;
        uVar4 = uVar6;
        if ((int)uVar5 < 0) break;
        uVar4 = Feature_3602159931__private_IsEnabledDeviceUsageNoInline();
        lVar1 = local_60;
        if ((int)uVar4 == 0) {
          uVar2 = 0;
          plVar8 = (longlong *)(local_60 + 8);
          if (*(int *)(local_60 + 4) != 0) {
            do {
              if ((*plVar8 != 0x11cf62ce4747b320) || (plVar8[1] != 0xc104db28d6a5)) {
                uVar3 = KsCacheMedium(param_2,plVar8,local_res18[0] == 2);
                uVar6 = (ulonglong)uVar3;
                if ((int)uVar3 < 0) break;
              }
              plVar8 = plVar8 + 3;
              uVar2 = uVar2 + 1;
            } while (uVar2 < *(uint *)(lVar1 + 4));
          }
        }
        else {
          uVar2 = UpdateMediumCachePassive(param_1,param_2,local_60,local_res18[0]);
          uVar6 = (ulonglong)uVar2;
        }
        ExFreePool(lVar1);
        uVar7 = uVar7 + 1;
        uVar4 = uVar6;
      } while (uVar7 < local_res20[0]);
    }
  }
  return uVar4;
}



===== UpdateMediumCachePassive @ 14000226c =====

int UpdateMediumCachePassive
              (undefined8 param_1,longlong param_2,longlong param_3,undefined4 param_4)

{
  int iVar1;
  longlong lVar2;
  longlong *plVar3;
  
  lVar2 = IoGetRelatedDeviceObject();
  if ((((lVar2 == 0) || (param_3 == 0)) || (*(int *)(param_3 + 4) == 0)) || (param_2 == 0)) {
    iVar1 = -0x3fffffff;
  }
  else {
    lVar2 = IoAllocateWorkItem(lVar2);
    if (lVar2 == 0) {
      iVar1 = -0x3fffff66;
    }
    else {
      plVar3 = (longlong *)ExAllocatePoolWithTag(0x600,0x38,0x70636d55);
      if (plVar3 == (longlong *)0x0) {
        iVar1 = -0x3fffff66;
      }
      else {
        KeInitializeEvent(plVar3 + 3,0,0);
        *(undefined4 *)(plVar3 + 6) = 0;
        *plVar3 = param_2;
        plVar3[1] = param_3;
        *(undefined4 *)(plVar3 + 2) = param_4;
        IoQueueWorkItemEx(lVar2,UpdateMediumCachePassive_Do,1,plVar3);
        iVar1 = KeWaitForSingleObject(plVar3 + 3,0,0,0,0);
        if (-1 < iVar1) {
          iVar1 = (int)plVar3[6];
        }
        ExFreePool(plVar3);
      }
      IoFreeWorkItem(lVar2);
    }
  }
  return iVar1;
}



===== UpdateMediumCachePassive_Do @ 1400023c0 =====

void UpdateMediumCachePassive_Do(undefined8 param_1,undefined8 *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  longlong *plVar4;
  
  uVar3 = 0;
  iVar2 = 0;
  plVar4 = (longlong *)(param_2[1] + 8);
  iVar1 = 0;
  if (*(int *)(param_2[1] + 4) != 0) {
    do {
      iVar2 = iVar1;
      if ((*plVar4 != 0x11cf62ce4747b320) || (plVar4[1] != 0xc104db28d6a5)) {
        iVar2 = KsCacheMedium(*param_2,plVar4,*(int *)(param_2 + 2) == 2);
        if (iVar2 < 0) break;
      }
      plVar4 = plVar4 + 3;
      uVar3 = uVar3 + 1;
      iVar1 = iVar2;
    } while (uVar3 < *(uint *)(param_2[1] + 4));
  }
  *(int *)(param_2 + 6) = iVar2;
  KeSetEvent(param_2 + 3,0,0);
  return;
}



===== wil_details_FeatureReporting_RecordUsageInCache @ 140002460 =====

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
LAB_140002669:
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
LAB_14000253b:
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
      if (param_3 == 4) goto LAB_140002669;
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
        goto LAB_14000253b;
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



===== wil_details_FeatureReporting_ReportUsageToService @ 140002754 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void wil_details_FeatureReporting_ReportUsageToService
               (longlong param_1,ulonglong param_2,int param_3)

{
  bool bVar1;
  undefined7 extraout_var;
  uint uVar2;
  uint uVar3;
  byte bVar4;
  int local_res18 [4];
  
  uVar2 = (uint)param_2 & 1;
  if (param_3 != 0) {
    if (param_3 == 1) {
      uVar3 = (uVar2 ^ 1) << 2;
      goto LAB_140002825;
    }
    if (param_3 == 2) {
      uVar3 = (uVar2 ^ 1) * 4 + 1;
      goto LAB_140002825;
    }
    if (param_3 == 3) {
      uVar3 = (uVar2 ^ 1) * 4 + 2;
      goto LAB_140002825;
    }
    if (param_3 == 4) {
      uVar3 = (uVar2 ^ 1) * 4 + 3;
      goto LAB_140002825;
    }
    if (param_3 == 5) {
      uVar3 = (uVar2 ^ 1) * 2 + 8;
      goto LAB_140002825;
    }
    if (param_3 == 6) {
      uVar3 = (uVar2 ^ 1) * 2 + 9;
      goto LAB_140002825;
    }
    bVar4 = (char)param_3 + 0x9c;
    if (bVar4 < 0x32) {
      uVar3 = (-(uint)((param_2 & 1) != 0) & 0xffffffce) + 0x96 + (uint)bVar4;
      goto LAB_140002825;
    }
  }
  uVar3 = 0xff;
LAB_140002825:
  local_res18[0] = param_3;
  bVar1 = wil_details_FeatureReporting_ReportUsageToServiceDirect(param_1,param_2,uVar3);
  if (((int)CONCAT71(extraout_var,bVar1) != 0) &&
     (g_wil_details_pfnFeatureLoggingHook != (code *)0x0)) {
    (*g_wil_details_pfnFeatureLoggingHook)
              (*(undefined4 *)(param_1 + 0x18),*(undefined8 *)(param_1 + 0x10),0,uVar2,local_res18,0
               ,0,1);
  }
  return;
}



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 14000287c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool wil_details_FeatureReporting_ReportUsageToServiceDirect
               (longlong param_1,undefined8 param_2,uint param_3)

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
              (*(undefined4 *)(param_1 + 0x18),param_3,1,*(undefined8 *)(param_1 + 8));
  }
  if ((((uint)param_2 >> 10 & 1) != 0) && (param_3 != 0xfe)) {
    local_68._0_6_ = CONCAT24((short)param_3,*(undefined4 *)(param_1 + 0x18));
    uVar1 = (uint6)local_68;
    local_68 = (ulonglong)(uint6)local_68;
    if (((uint)param_2 >> 0xb & 1) != 0) {
      local_68 = CONCAT26(1,uVar1);
    }
    RtlNotifyFeatureUsage(&local_68);
  }
  return (int)local_38 == 0;
}



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 14000296c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                    (uint *param_1,ulonglong param_2,longlong param_3)

{
  undefined8 *puVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  ulonglong uVar7;
  uint uVar8;
  uint uVar9;
  longlong *plVar10;
  uint uVar11;
  bool bVar12;
  bool bVar13;
  undefined1 auStack_a8 [32];
  undefined8 local_88;
  ulonglong local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined4 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_a8;
  iVar3 = 0;
  local_88 = param_2;
  if (g_wil_details_ensureSubscribedToFeatureConfigurationChanges != (code *)0x0) {
    iVar3 = (*g_wil_details_ensureSubscribedToFeatureConfigurationChanges)();
  }
  local_70 = 0;
  uStack_68 = 0;
  local_78 = 0;
  bVar2 = 0;
  local_60 = 0;
  local_58 = 0;
  local_50 = 0;
  iVar4 = RtlQueryFeatureConfiguration
                    (*(undefined4 *)(param_3 + 0x18),1 < (byte)(*(char *)(param_3 + 0x1c) - 2U),
                     &local_78,&local_58);
  if (iVar4 == 0) {
    bVar2 = 1;
    uVar8 = local_58._4_4_ >> 7 & 1;
    local_70 = CONCAT44(local_70._4_4_,local_58._4_4_ >> 4) & 0xffffffff00000003;
    uVar5 = local_58._4_4_ >> 6 & 1;
    uVar11 = local_58._4_4_ >> 4 & 3;
LAB_140002a1f:
    uVar8 = uVar8 << 10;
    if (uVar5 != 0) {
      uVar5 = 0x800;
      goto LAB_140002a4d;
    }
  }
  else {
    uVar8 = 0;
    uVar5 = 0;
    uVar11 = (uint)local_70;
    if (iVar4 != 0x117) goto LAB_140002a1f;
    bVar2 = 1;
    uVar8 = (local_58._4_4_ >> 7 & 1) << 10;
  }
  uVar5 = 0;
LAB_140002a4d:
  uVar6 = -(uint)bVar2 & uVar11 & 3;
  if (uVar6 == 0) {
    uVar9 = -(uint)(*(char *)(param_3 + 0x1f) != '\0') & 0x40;
  }
  else {
    uVar9 = 0;
    if (uVar11 == 2) {
      uVar9 = 0x40;
    }
  }
  uVar11 = uVar9 >> 6 ^ (uVar9 | uVar6 << 7 | uVar8 | uVar5);
  if ((uVar9 != 0) && (plVar10 = *(longlong **)(param_3 + 0x20), plVar10 != (longlong *)0x0)) {
    do {
      puVar1 = (undefined8 *)*plVar10;
      if (puVar1 == (undefined8 *)0x0) break;
      if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
         (*(char *)((longlong)puVar1 + 0x1d) == '\0')) {
        uVar8 = *(uint *)*puVar1;
        local_80 = (ulonglong)uVar8;
        if ((uVar8 & 2) == 0) {
          uVar7 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                            ((uint *)*puVar1,local_80,(longlong)puVar1);
          uVar8 = (uint)uVar7;
        }
        uVar5 = uVar11 & 0xfffffffe;
        uVar11 = (uint)((uVar8 & uVar11 & 1) != 0);
      }
      else {
        if (((uVar11 & 1) == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
          uVar5 = 0;
        }
        else {
          uVar5 = 1;
        }
        uVar11 = uVar11 & 0xfffffffe;
      }
      uVar11 = uVar11 | uVar5;
      plVar10 = plVar10 + 1;
    } while ((uVar11 & 1) != 0);
  }
  bVar12 = *(char *)(param_3 + 0x1c) == '\0';
  uVar7 = param_2 & 0xffffffff;
  while( true ) {
    uVar5 = (uint)uVar7;
    local_88 = CONCAT44(local_88._4_4_,uVar5);
    if ((!bVar12 || iVar3 != 0) && (local_88 = CONCAT44(local_88._4_4_,uVar5), (uVar7 & 2) == 0)) {
      uVar8 = (uVar11 ^ uVar5) & 0x9c1 ^ uVar5;
      uVar5 = uVar8 | 2;
      local_88 = CONCAT44(local_88._4_4_,uVar8) | 2;
    }
    if ((param_2 & 4) == 0) {
      uVar8 = (uVar5 ^ uVar11) & 0x400 ^ uVar5;
      uVar5 = uVar8 | 4;
      local_88 = CONCAT44(local_88._4_4_,uVar8) | 4;
    }
    uVar7 = param_2 & 0xffffffff;
    LOCK();
    uVar8 = *param_1;
    bVar13 = (uint)param_2 == uVar8;
    if (bVar13) {
      *param_1 = uVar5;
    }
    else {
      uVar7 = (ulonglong)uVar8;
    }
    UNLOCK();
    if (bVar13) break;
    param_2 = uVar7;
  }
  if (((param_2 & 4) == 0) &&
     (g_wil_details_subscribeFeatureStateCacheToConfigurationChanges != (code *)0x0)) {
    (*g_wil_details_subscribeFeatureStateCacheToConfigurationChanges)
              (param_1,*(undefined1 *)(param_3 + 0x1c),iVar3);
  }
  if (bVar12 && iVar3 == 0) {
    local_88 = CONCAT44(local_88._4_4_,(uVar11 ^ uVar5) & 0x9c1 ^ uVar5);
  }
  return local_88;
}



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 140002bd8 =====

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



===== wil_details_IsEnabledFallback @ 140002c3c =====

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



===== wil_details_RecordCachedUsage @ 140002cd0 =====

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



===== wil_details_RecordFeatureUsageReporting @ 140002e30 =====

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



===== Feature_1640916283__private_IsEnabledDeviceUsageNoInline @ 140002eb4 =====

ulonglong Feature_1640916283__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_1640916283__private_featureState;
  if ((Feature_1640916283__private_featureState & 0x10) == 0) {
    uVar1 = Feature_1640916283__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_1640916283__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_1640916283__private_IsEnabledFallback @ 140002eec =====

void Feature_1640916283__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_1640916283__private_descriptor);
  return;
}



===== `vector_deleting_destructor' @ 140002f10 =====

/* public: virtual void * __ptr64 __cdecl FSList::`vector deleting destructor'(unsigned int) __ptr64
    */

void * __thiscall FSList::_vector_deleting_destructor_(FSList *this,uint param_1)

{
  ~FSList(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



===== `vector_deleting_destructor' @ 140002f50 =====

/* public: virtual void * __ptr64 __cdecl FSRegObject::`vector deleting destructor'(unsigned int)
   __ptr64 */

void * __thiscall FSRegObject::_vector_deleting_destructor_(FSRegObject *this,uint param_1)

{
  ~FSRegObject(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



===== `scalar_deleting_destructor' @ 140002f90 =====

/* public: virtual void * __ptr64 __cdecl FSRegObjectList::`scalar deleting destructor'(unsigned
   int) __ptr64 */

void * __thiscall FSRegObjectList::_scalar_deleting_destructor_(FSRegObjectList *this,uint param_1)

{
  ~FSRegObjectList(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



===== `vector_deleting_destructor' @ 140002fd0 =====

/* public: virtual void * __ptr64 __cdecl FSFrameMdlList::`vector deleting destructor'(unsigned int)
   __ptr64 */

void * __thiscall FSFrameMdlList::_vector_deleting_destructor_(FSFrameMdlList *this,uint param_1)

{
  ~FSFrameMdlList(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



===== `scalar_deleting_destructor' @ 140003010 =====

/* public: virtual void * __ptr64 __cdecl FSStreamReg::`scalar deleting destructor'(unsigned int)
   __ptr64 */

void * __thiscall FSStreamReg::_scalar_deleting_destructor_(FSStreamReg *this,uint param_1)

{
  ~FSStreamReg(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



===== MsKsSrvFSStreamRegCleanupWorkItem @ 140003050 =====

/* void __cdecl MsKsSrvFSStreamRegCleanupWorkItem(struct _EX_TIMER * __ptr64,void * __ptr64) */

void __cdecl MsKsSrvFSStreamRegCleanupWorkItem(_EX_TIMER *param_1,void *param_2)

{
  if (param_2 != (void *)0x0) {
    if (s_fsTraceEnable != 0) {
      DbgPrintEx(0x1d,3,"MsKsSrvFSStreamRegCleanupWorkItem , Close.. some references exist (%p)\n",
                 param_2);
    }
    IoQueueWorkItem(*(undefined8 *)((longlong)param_2 + 0x50),
                    MsKsSrvFSStreamRegCleanupWorkitemRoutine,1,param_2);
  }
  return;
}



===== `scalar_deleting_destructor' @ 1400030c0 =====

/* public: virtual void * __ptr64 __cdecl FSContextReg::`scalar deleting destructor'(unsigned int)
   __ptr64 */

void * __thiscall FSContextReg::_scalar_deleting_destructor_(FSContextReg *this,uint param_1)

{
  ~FSContextReg(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



===== _guard_check_icall @ 140003100 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 140003118 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 14000313c =====

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



===== __cpu_features_init @ 1400031b0 =====

/* WARNING: Removing unreachable block (ram,0x00014000321a) */
/* WARNING: Removing unreachable block (ram,0x0001400031c9) */
/* WARNING: Removing unreachable block (ram,0x0001400031ba) */

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



===== __security_check_cookie @ 140003280 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1400032c0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1400032f0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001400032f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140003320 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memmove @ 140003380 =====

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



===== memset @ 140003680 =====

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



===== __memset_repmovs @ 1400037c0 =====

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



===== __memset_query @ 140003840 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1400038c0 =====

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



===== __memset_spec_ermsb_repmovsb @ 140003a00 =====

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



===== __memset_spec_plain @ 140003a80 =====

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



===== ExtractMediaTypes @ 14000b008 =====

void ExtractMediaTypes(longlong param_1,uint param_2,undefined8 *param_3,undefined8 *param_4)

{
  undefined8 uVar1;
  int *piVar2;
  ulonglong uVar3;
  
  piVar2 = (int *)(param_1 + 8);
  if (param_2 != 0) {
    uVar3 = (ulonglong)param_2;
    do {
      piVar2 = (int *)((longlong)piVar2 + ((ulonglong)(*piVar2 + 7) & 0xfffffff8));
      uVar3 = uVar3 - 1;
    } while (uVar3 != 0);
  }
  uVar1 = *(undefined8 *)(piVar2 + 6);
  *param_3 = *(undefined8 *)(piVar2 + 4);
  param_3[1] = uVar1;
  uVar1 = *(undefined8 *)(piVar2 + 10);
  *param_4 = *(undefined8 *)(piVar2 + 8);
  param_4[1] = uVar1;
  return;
}



===== FsDriverUnload @ 14000b050 =====

void FsDriverUnload(void)

{
  KeWaitForSingleObject(&DAT_1400070d8,0,0,0,0);
  if (DAT_1400070c0 != (FSRendezvousServer *)0x0) {
    if (s_fsTraceEnable != 0) {
      DbgPrintEx(0x1d,3,"FSDisposeRendezvousServer++ (%p)\n",DAT_1400070c0);
    }
    FSRendezvousServer::Release(DAT_1400070c0);
    DAT_1400070c0 = (FSRendezvousServer *)0x0;
  }
  KeReleaseMutex(&DAT_1400070d8,0);
  FSRendezvousClearWnf();
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



===== InsertCacheItem @ 14000b12c =====

void InsertCacheItem(void *param_1,uint param_2,int param_3,longlong param_4,uint *param_5,
                    int *param_6)

{
  ulonglong uVar1;
  ulonglong _Size;
  uint uVar2;
  
  uVar2 = 0;
  _Size = (ulonglong)param_2;
  if (*param_5 != 0) {
    do {
      uVar1 = RtlCompareMemory(param_1,(ulonglong)(uVar2 * param_2) + param_4,_Size);
      if (uVar1 == _Size) break;
      uVar2 = uVar2 + 1;
    } while (uVar2 < *param_5);
  }
  if (uVar2 == *param_5) {
    *param_5 = *param_5 + 1;
    memmove((void *)((ulonglong)(param_2 * uVar2) + param_4),param_1,_Size);
  }
  *param_6 = (param_2 * uVar2 - param_3) + (int)param_4;
  return;
}



===== PnpAddDevice @ 14000b1e0 =====

ulonglong PnpAddDevice(undefined8 param_1,undefined8 param_2)

{
  undefined8 *puVar1;
  uint uVar2;
  ulonglong uVar3;
  longlong lVar4;
  longlong local_res18 [2];
  
  local_res18[0] = 0;
  uVar3 = IoCreateDevice(param_1,8,0,0x2f,0,0,local_res18);
  if (-1 < (int)uVar3) {
    puVar1 = *(undefined8 **)(local_res18[0] + 0x40);
    uVar2 = KsAllocateDeviceHeader(puVar1,1,&PTR_SrvDispatchCreate_140005000);
    uVar3 = (ulonglong)uVar2;
    if (-1 < (int)uVar2) {
      lVar4 = IoAttachDeviceToDeviceStack(local_res18[0],param_2);
      if (lVar4 != 0) {
        KsSetDevicePnpAndBaseObject(*puVar1,lVar4,local_res18[0]);
        lVar4 = KsQueryDevicePnpObject(*puVar1);
        *(uint *)(local_res18[0] + 0x30) =
             *(uint *)(local_res18[0] + 0x30) | *(uint *)(lVar4 + 0x30) & 0x2000;
        *(uint *)(local_res18[0] + 0x30) = *(uint *)(local_res18[0] + 0x30) & 0xffffff7f;
        return 0;
      }
      KsFreeDeviceHeader(*puVar1);
    }
    *(uint *)(local_res18[0] + 0x30) = *(uint *)(local_res18[0] + 0x30) & 0xffffff7f;
    IoDeleteDevice(local_res18[0]);
  }
  return uVar3;
}



===== SrvDispatchClose @ 14000b300 =====

undefined8 SrvDispatchClose(longlong param_1,_IRP *param_2)

{
  longlong lVar1;
  undefined8 *puVar2;
  
  lVar1 = *(longlong *)(param_2 + 0xb8);
  if (*(longlong *)(*(longlong *)(lVar1 + 0x30) + 0x20) != 0) {
    FSRendezvousClose(param_2);
  }
  puVar2 = *(undefined8 **)(*(longlong *)(lVar1 + 0x30) + 0x18);
  KsFreeObjectHeader(*puVar2);
  ExFreePool(puVar2);
  KsDereferenceSoftwareBusObject(**(undefined8 **)(param_1 + 0x40));
  *(undefined4 *)(param_2 + 0x30) = 0;
  IofCompleteRequest(param_2,0);
  return 0;
}



===== SrvDispatchCreate @ 14000b3a0 =====

int SrvDispatchCreate(longlong param_1,longlong param_2)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  
  iVar2 = KsReferenceSoftwareBusObject(**(undefined8 **)(param_1 + 0x40));
  if (-1 < iVar2) {
    lVar1 = *(longlong *)(param_2 + 0xb8);
    if ((ulonglong)*(ushort *)(*(longlong *)(lVar1 + 0x30) + 0x58) ==
        (ulonglong)*(ushort *)(*(longlong *)(param_2 + 0x78) + 0x10) + 2) {
      lVar3 = ExAllocatePoolWithTag(0x600,0x10,0x4946734b);
      if (lVar3 == 0) {
        iVar2 = -0x3fffff66;
      }
      else {
        iVar2 = KsAllocateObjectHeader(lVar3,0,0,param_2,&PTR_SrvDispatchIoControl_140005030);
        if (-1 < iVar2) {
          *(longlong *)(*(longlong *)(lVar1 + 0x30) + 0x18) = lVar3;
          goto LAB_14000b483;
        }
        ExFreePool(lVar3);
      }
    }
    else {
      iVar2 = -0x3ffffff3;
    }
    KsDereferenceSoftwareBusObject(**(undefined8 **)(param_1 + 0x40));
  }
LAB_14000b483:
  *(int *)(param_2 + 0x30) = iVar2;
  IofCompleteRequest(param_2,0);
  return iVar2;
}



===== SrvDispatchIoControl @ 14000b4c0 =====

long SrvDispatchIoControl(undefined8 param_1,_IRP *param_2)

{
  uint uVar1;
  longlong lVar2;
  char cVar3;
  long lVar4;
  undefined4 uVar5;
  undefined8 *puVar6;
  int iVar7;
  undefined8 local_res10;
  
  uVar1 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 0x18);
  if (uVar1 < 0x2f0415) {
    if (uVar1 == 0x2f0414) {
      local_res10 = (FSRendezvousServer *)0x0;
      lVar4 = FSGetRendezvousServer((FSRendezvousServer **)&local_res10);
      if (lVar4 < 0) goto LAB_14000b769;
      lVar4 = FSRendezvousServer::ConsumeRx(local_res10,param_2);
    }
    else {
      if (uVar1 == 0x2f0003) {
        lVar4 = KsPropertyHandler(param_2,1,&PTR_KSPROPSETID_Service_1400051d0);
        goto LAB_14000b769;
      }
      if (uVar1 == 0x2f0400) {
        lVar4 = FSInitializeContextRendezvous(param_2);
        goto LAB_14000b769;
      }
      if (uVar1 == 0x2f0404) {
        local_res10 = (FSRendezvousServer *)0x0;
        lVar4 = FSGetRendezvousServer((FSRendezvousServer **)&local_res10);
        if (lVar4 < 0) goto LAB_14000b769;
        lVar4 = FSRendezvousServer::InitializeStream(local_res10,param_2);
      }
      else if (uVar1 == 0x2f0408) {
        local_res10 = (FSRendezvousServer *)0x0;
        lVar4 = FSGetRendezvousServer((FSRendezvousServer **)&local_res10);
        if (lVar4 < 0) goto LAB_14000b769;
        lVar4 = FSRendezvousServer::PublishTx(local_res10,param_2);
      }
      else if (uVar1 == 0x2f040c) {
        local_res10 = (FSRendezvousServer *)0x0;
        lVar4 = FSGetRendezvousServer((FSRendezvousServer **)&local_res10);
        if (lVar4 < 0) goto LAB_14000b769;
        lVar4 = FSRendezvousServer::PublishRx(local_res10,param_2);
      }
      else {
        if (uVar1 != 0x2f0410) goto LAB_14000b64b;
        local_res10 = (FSRendezvousServer *)0x0;
        lVar4 = FSGetRendezvousServer((FSRendezvousServer **)&local_res10);
        if (lVar4 < 0) goto LAB_14000b769;
        lVar4 = FSRendezvousServer::ConsumeTx(local_res10,param_2);
      }
    }
  }
  else if (uVar1 == 0x2f0418) {
    local_res10 = (FSRendezvousServer *)0x0;
    lVar4 = FSGetRendezvousServer((FSRendezvousServer **)&local_res10);
    if (lVar4 < 0) goto LAB_14000b769;
    lVar4 = FSRendezvousServer::NotifyContext(local_res10,param_2);
  }
  else if (uVar1 == 0x2f041c) {
    local_res10 = (FSRendezvousServer *)0x0;
    lVar4 = FSGetRendezvousServer((FSRendezvousServer **)&local_res10);
    if (lVar4 < 0) goto LAB_14000b769;
    lVar4 = FSRendezvousServer::RegisterContext(local_res10,param_2);
  }
  else if (uVar1 == 0x2f0420) {
    local_res10 = (FSRendezvousServer *)0x0;
    lVar4 = FSGetRendezvousServer((FSRendezvousServer **)&local_res10);
    if (lVar4 < 0) goto LAB_14000b769;
    lVar4 = FSRendezvousServer::RegisterStream(local_res10,param_2);
  }
  else {
    if (uVar1 != 0x2f0424) {
      if (uVar1 == 0x2f0428) {
        cVar3 = KsIsCurrentProcessFrameServer();
        if (cVar3 == '\0') {
          lVar4 = -0x3fffffde;
        }
        else {
          lVar2 = *(longlong *)(param_2 + 0xb8);
          iVar7 = *(int *)(lVar2 + 0x10);
          if (iVar7 == 0) {
            uVar5 = PsGetCurrentProcessId();
            puVar6 = &local_res10;
            local_res10 = (FSRendezvousServer *)CONCAT44(0xffffffff,uVar5);
            iVar7 = 8;
          }
          else {
            puVar6 = *(undefined8 **)(param_2 + 0x18);
          }
          ZwUpdateWnfStateData(&WNF_KSV_FSSTREAMACTIVITY,puVar6,iVar7,0,0,0,0);
          *(undefined8 *)(*(longlong *)(lVar2 + 0x30) + 0x20) = 0xffffffffffffffff;
          lVar4 = 0;
        }
        goto LAB_14000b769;
      }
LAB_14000b64b:
      lVar4 = -0x3ffffff0;
      goto LAB_14000b769;
    }
    local_res10 = (FSRendezvousServer *)0x0;
    lVar4 = FSGetRendezvousServer((FSRendezvousServer **)&local_res10);
    if (lVar4 < 0) goto LAB_14000b769;
    lVar4 = FSRendezvousServer::DrainTx(local_res10,param_2);
  }
  FSRendezvousServer::Release(local_res10);
LAB_14000b769:
  *(long *)(param_2 + 0x30) = lVar4;
  IofCompleteRequest(param_2,0);
  return lVar4;
}



===== wil_details_EvaluateFeatureDependencies @ 14000b798 =====

void wil_details_EvaluateFeatureDependencies(void)

{
  uint uVar1;
  undefined **ppuVar2;
  undefined **ppuVar3;
  undefined *puVar4;
  bool bVar5;
  
  puVar4 = (undefined *)0x0;
  ppuVar3 = &wil_details_featureDescriptors_a;
  ppuVar2 = &wil_details_featureDescriptors_a;
  do {
    if (*ppuVar2 != (undefined *)0x0) goto joined_r0x00014000b7d3;
    ppuVar2 = ppuVar2 + 1;
  } while (ppuVar2 < &wil_details_featureDescriptors_z);
LAB_14000b84d:
  while( true ) {
    if (&UNK_140006037 < ppuVar3) {
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
      if (&UNK_140006037 < ppuVar3) {
        return;
      }
      if (*ppuVar3 != puVar4) break;
      ppuVar3 = ppuVar3 + 1;
    }
  } while( true );
joined_r0x00014000b7d3:
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
      if (&UNK_140006037 < ppuVar2) goto LAB_14000b84d;
      if (*ppuVar2 != (undefined *)0x0) break;
      ppuVar2 = ppuVar2 + 1;
    }
  }
  goto LAB_14000b84d;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 14000b888 =====

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
          if (puVar1 == (undefined8 *)0x0) goto LAB_14000b920;
          if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
             (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
          if ((uVar4 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
            uVar4 = 0;
            goto LAB_14000b920;
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
LAB_14000b920:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 14000b970 =====

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
      for (ppuVar2 = &wil_details_featureDescriptors_a; ppuVar2 < &wil_details_featureDescriptors_z;
          ppuVar2 = ppuVar2 + 1) {
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
              if (&UNK_140006037 < ppuVar2) {
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



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 14000b9f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_ReevaluateOnFeatureConfigurationChange(void)

{
  int iVar1;
  uint uVar2;
  undefined **ppuVar3;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined8 local_20;
  undefined4 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  for (ppuVar3 = &wil_details_featureDescriptors_a; ppuVar3 < &wil_details_featureDescriptors_z;
      ppuVar3 = ppuVar3 + 1) {
    if (*ppuVar3 != (undefined *)0x0) goto LAB_14000baed;
  }
LAB_14000baf6:
  wil_details_EvaluateFeatureDependencies();
  return;
LAB_14000baed:
  if (ppuVar3 == (undefined **)0x0) goto LAB_14000baf6;
  if (((*(char *)((longlong)ppuVar3 + 0x1d) == '\0') &&
      (*(char *)((longlong)ppuVar3 + 0x1e) == '\0')) &&
     (*(char *)((longlong)ppuVar3 + 0x1c) == '\0')) {
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    iVar1 = RtlQueryFeatureConfiguration(*(undefined4 *)(ppuVar3 + 3),1,&local_28,&local_20);
    if ((iVar1 == -0x7fffffde) || (iVar1 == -0x3ffffddb)) {
LAB_14000babe:
      uVar2 = 0x206;
    }
    else {
      if (iVar1 == 0) {
        uVar2 = (local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0;
      }
      else {
        if (iVar1 != 0x117) goto LAB_14000babe;
        uVar2 = local_20._4_4_ & 0x80;
      }
      uVar2 = uVar2 << 3 | 0x206;
    }
    LOCK();
    *(uint *)*ppuVar3 = *(uint *)*ppuVar3 ^ (*(uint *)*ppuVar3 ^ uVar2) & 0xf80;
    UNLOCK();
  }
  ppuVar3 = ppuVar3 + 7;
  while( true ) {
    if (&UNK_140006037 < ppuVar3) goto LAB_14000baf6;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_14000baed;
}



===== ~FSRendezvousServer @ 14000bb1c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* protected: __cdecl FSRendezvousServer::~FSRendezvousServer(void) __ptr64 */

void __thiscall FSRendezvousServer::~FSRendezvousServer(FSRendezvousServer *this)

{
  _LIST_ENTRY *p_Var1;
  longlong *plVar2;
  
  Lock(this);
  while (*(FSRendezvousServer **)(this + 0x50) != this + 0x50) {
    p_Var1 = FSList::RemoveHead((FSList *)(this + 0x48));
    plVar2 = (longlong *)(-(ulonglong)(p_Var1 != (_LIST_ENTRY *)0x0) & (ulonglong)(p_Var1 + -8));
    plVar2[9] = 0;
    (**(code **)(*plVar2 + 0x20))(plVar2);
    (**(code **)*plVar2)(plVar2);
  }
  while (*(FSRendezvousServer **)(this + 0x80) != this + 0x80) {
    p_Var1 = FSList::RemoveHead((FSList *)(this + 0x78));
    plVar2 = (longlong *)(-(ulonglong)(p_Var1 != (_LIST_ENTRY *)0x0) & (ulonglong)(p_Var1 + -8));
    plVar2[9] = 0;
    (**(code **)(*plVar2 + 0x20))(plVar2);
    (**(code **)*plVar2)(plVar2);
  }
  KeReleaseMutex(this + 8,0);
  FSRegObjectList::~FSRegObjectList((FSRegObjectList *)(this + 0x70));
  FSRegObjectList::~FSRegObjectList((FSRegObjectList *)(this + 0x40));
  return;
}



===== Close @ 14000bc04 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: long __cdecl FSRendezvousServer::Close(struct _IRP * __ptr64) __ptr64 */

long __thiscall FSRendezvousServer::Close(FSRendezvousServer *this,_IRP *param_1)

{
  FSRegObject *this_00;
  FSRendezvousServer *pFVar1;
  bool bVar2;
  char cVar3;
  longlong lVar4;
  longlong lVar5;
  ulonglong uVar6;
  FSRendezvousServer *pFVar7;
  FSRendezvousServer *pFVar8;
  
  lVar4 = *(longlong *)(param_1 + 0xb8);
  Lock(this);
  this_00 = *(FSRegObject **)(*(longlong *)(lVar4 + 0x30) + 0x20);
  if (this_00 != (FSRegObject *)0x0) {
    if (*(int *)(this_00 + 0x30) == 1) {
      pFVar7 = this + 0x80;
      pFVar8 = this + 0x90;
      if (*(FSRendezvousServer **)pFVar7 != pFVar7) {
        *(FSRendezvousServer **)pFVar8 = *(FSRendezvousServer **)pFVar7;
      }
      while (((pFVar1 = *(FSRendezvousServer **)pFVar8, pFVar1 != (FSRendezvousServer *)0x0 &&
              (*(FSRendezvousServer **)pFVar7 != pFVar7)) && (pFVar1 != pFVar7))) {
        uVar6 = -(ulonglong)(pFVar1 != (FSRendezvousServer *)0x0) & (ulonglong)(pFVar1 + -8);
        if ((uVar6 != 0) && (*(FSRegObject **)(uVar6 + 0x20) == this_00)) goto LAB_14000bcc9;
        FSRegObjectList::MoveNext((FSRegObjectList *)(this + 0x70));
      }
    }
    bVar2 = FindStreamObject(this,this_00);
    if (bVar2) {
LAB_14000bcc9:
      (**(code **)(*(longlong *)this_00 + 0x28))(this_00);
      if (*(longlong *)(this_00 + 0x38) != 0) {
        lVar4 = PsGetProcessId();
        lVar5 = PsGetCurrentProcessId();
        if (lVar4 == lVar5) {
          if (s_fsTraceEnable != 0) {
            DbgPrintEx(0x1d,3,"FSRendezvousServer::Close, init close (%p)\n",this_00);
          }
          (**(code **)(*(longlong *)this_00 + 0x18))(this_00,param_1);
        }
      }
      bVar2 = FSRegObject::IsRegProcess(this_00);
      if (bVar2) {
        if (s_fsTraceEnable != 0) {
          DbgPrintEx(0x1d,3,"FSRendezvousServer::Close, reg close (%p)\n",this_00);
        }
        (**(code **)(*(longlong *)this_00 + 0x10))(this_00,param_1);
      }
      cVar3 = (**(code **)(*(longlong *)this_00 + 8))(this_00);
      if (cVar3 != '\0') {
        if (s_fsTraceEnable != 0) {
          DbgPrintEx(0x1d,3,"FSRendezvousServer::Close, obj close (%p)\n",this_00);
        }
        (**(code **)(*(longlong *)this_00 + 0x20))(this_00);
        FSRegObject::Release(this_00);
      }
      (**(code **)(*(longlong *)this_00 + 0x30))(this_00);
      FSRegObject::Release(this_00);
    }
    else if (s_fsTraceEnable != 0) {
      DbgPrintEx(0x1d,3,"!!!FSRendezvousServer::Close, failed to find object!!!\n");
    }
  }
  KeReleaseMutex(this + 8,0);
  return 0;
}



===== ConsumeRx @ 14000be18 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: long __cdecl FSRendezvousServer::ConsumeRx(struct _IRP * __ptr64) __ptr64 */

long __thiscall FSRendezvousServer::ConsumeRx(FSRendezvousServer *this,_IRP *param_1)

{
  uint uVar1;
  uint uVar2;
  longlong lVar3;
  FSFrameInfo *pFVar4;
  char cVar5;
  bool bVar6;
  long lVar7;
  ulonglong uVar8;
  FSRegObject *this_00;
  
  this_00 = (FSRegObject *)0x0;
  bVar6 = false;
  cVar5 = KsIsCurrentProcessFrameServer();
  if (cVar5 == '\0') {
    lVar7 = -0x3fffffde;
    goto LAB_14000bf7c;
  }
  lVar3 = *(longlong *)(param_1 + 0xb8);
  if (*(longlong *)(*(longlong *)(lVar3 + 0x30) + 0x20) == 0) {
LAB_14000be6b:
    lVar7 = -0x3ffffff0;
  }
  else {
    pFVar4 = *(FSFrameInfo **)(param_1 + 0x18);
    if (pFVar4 != (FSFrameInfo *)0x0) {
      uVar1 = *(uint *)(lVar3 + 8);
      if ((((0xaf < uVar1) && (uVar1 == *(uint *)(lVar3 + 0x10))) &&
          (uVar2 = *(uint *)(pFVar4 + 0x20), uVar2 - 1 < 300)) &&
         ((*(uint *)(pFVar4 + 0x24) <= uVar2 &&
          ((ulonglong)(uVar2 - 1) * 0x88 + 0xb0 <= (ulonglong)uVar1)))) {
        *(undefined4 *)(pFVar4 + 0x24) = 0;
        Lock(this);
        this_00 = *(FSRegObject **)(*(longlong *)(lVar3 + 0x30) + 0x20);
        bVar6 = FindStreamObject(this,this_00);
        uVar8 = Feature_1640916283__private_IsEnabledDeviceUsageNoInline();
        if (((int)uVar8 != 0) && (bVar6)) {
          LOCK();
          *(int *)(this_00 + 0x18) = *(int *)(this_00 + 0x18) + 1;
          UNLOCK();
        }
        KeReleaseMutex(this + 8,0);
        if (bVar6) {
          (**(code **)(*(longlong *)this_00 + 0x28))(this_00);
          lVar7 = FSStreamReg::ConsumeRx((FSStreamReg *)this_00,pFVar4);
          if (-1 < lVar7) {
            FSStreamReg::GetStats((FSStreamReg *)this_00,(FSQueueStats *)(pFVar4 + 8));
          }
          (**(code **)(*(longlong *)this_00 + 0x30))(this_00);
          if (*(int *)(pFVar4 + 0x24) == 0) {
            *(undefined8 *)(param_1 + 0x38) = 0xb0;
          }
          else {
            *(ulonglong *)(param_1 + 0x38) = (ulonglong)(*(int *)(pFVar4 + 0x24) - 1) * 0x88 + 0xb0;
          }
          goto LAB_14000bf7c;
        }
        goto LAB_14000be6b;
      }
    }
    lVar7 = -0x3ffffff3;
  }
LAB_14000bf7c:
  uVar8 = Feature_1640916283__private_IsEnabledDeviceUsageNoInline();
  if (((int)uVar8 != 0) && (bVar6 != false)) {
    FSRegObject::Release(this_00);
  }
  return lVar7;
}



===== ConsumeTx @ 14000bfbc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: long __cdecl FSRendezvousServer::ConsumeTx(struct _IRP * __ptr64) __ptr64 */

long __thiscall FSRendezvousServer::ConsumeTx(FSRendezvousServer *this,_IRP *param_1)

{
  uint uVar1;
  longlong lVar2;
  FSFrameInfo *pFVar3;
  bool bVar4;
  ulonglong uVar5;
  uint uVar6;
  FSRegObject *this_00;
  
  lVar2 = *(longlong *)(param_1 + 0xb8);
  this_00 = (FSRegObject *)0x0;
  bVar4 = false;
  if (*(longlong *)(*(longlong *)(lVar2 + 0x30) + 0x20) == 0) {
LAB_14000bff5:
    uVar6 = 0xc0000010;
  }
  else {
    pFVar3 = *(FSFrameInfo **)(param_1 + 0x18);
    if (pFVar3 != (FSFrameInfo *)0x0) {
      uVar6 = *(uint *)(lVar2 + 8);
      if ((((0xaf < uVar6) && (uVar6 == *(uint *)(lVar2 + 0x10))) &&
          (uVar1 = *(uint *)(pFVar3 + 0x20), uVar1 - 1 < 300)) &&
         ((*(uint *)(pFVar3 + 0x24) <= uVar1 &&
          ((ulonglong)(uVar1 - 1) * 0x88 + 0xb0 <= (ulonglong)uVar6)))) {
        *(undefined4 *)(pFVar3 + 0x24) = 0;
        Lock(this);
        this_00 = *(FSRegObject **)(*(longlong *)(lVar2 + 0x30) + 0x20);
        bVar4 = FindStreamObject(this,this_00);
        uVar5 = Feature_1640916283__private_IsEnabledDeviceUsageNoInline();
        if (((int)uVar5 != 0) && (bVar4)) {
          LOCK();
          *(int *)(this_00 + 0x18) = *(int *)(this_00 + 0x18) + 1;
          UNLOCK();
        }
        KeReleaseMutex(this + 8,0);
        if (bVar4) {
          (**(code **)(*(longlong *)this_00 + 0x28))(this_00);
          FSStreamReg::ConsumeTx((FSStreamReg *)this_00,pFVar3);
          FSStreamReg::GetStats((FSStreamReg *)this_00,(FSQueueStats *)(pFVar3 + 8));
          uVar6 = ~-(uint)(*(int *)(pFVar3 + 0x24) != 0) & 0x8000001a;
          (**(code **)(*(longlong *)this_00 + 0x30))(this_00);
          if (*(int *)(pFVar3 + 0x24) == 0) {
            *(undefined8 *)(param_1 + 0x38) = 0xb0;
          }
          else {
            *(ulonglong *)(param_1 + 0x38) = (ulonglong)(*(int *)(pFVar3 + 0x24) - 1) * 0x88 + 0xb0;
          }
          goto LAB_14000c10f;
        }
        goto LAB_14000bff5;
      }
    }
    uVar6 = 0xc000000d;
  }
LAB_14000c10f:
  uVar5 = Feature_1640916283__private_IsEnabledDeviceUsageNoInline();
  if (((int)uVar5 != 0) && (bVar4 != false)) {
    FSRegObject::Release(this_00);
  }
  return uVar6;
}



===== DrainTx @ 14000c150 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: long __cdecl FSRendezvousServer::DrainTx(struct _IRP * __ptr64) __ptr64 */

long __thiscall FSRendezvousServer::DrainTx(FSRendezvousServer *this,_IRP *param_1)

{
  uint uVar1;
  uint uVar2;
  longlong lVar3;
  FSFrameInfo *pFVar4;
  char cVar5;
  bool bVar6;
  long lVar7;
  ulonglong uVar8;
  FSRegObject *this_00;
  
  this_00 = (FSRegObject *)0x0;
  bVar6 = false;
  cVar5 = KsIsCurrentProcessFrameServer();
  if (cVar5 == '\0') {
    lVar7 = -0x3fffffde;
    goto LAB_14000c2b4;
  }
  lVar3 = *(longlong *)(param_1 + 0xb8);
  if (*(longlong *)(*(longlong *)(lVar3 + 0x30) + 0x20) == 0) {
LAB_14000c1a3:
    lVar7 = -0x3ffffff0;
  }
  else {
    pFVar4 = *(FSFrameInfo **)(param_1 + 0x18);
    if (pFVar4 != (FSFrameInfo *)0x0) {
      uVar1 = *(uint *)(lVar3 + 8);
      if ((((0xaf < uVar1) && (*(uint *)(lVar3 + 0x10) == uVar1)) &&
          (uVar2 = *(uint *)(pFVar4 + 0x20), uVar2 - 1 < 300)) &&
         ((*(uint *)(pFVar4 + 0x24) <= uVar2 &&
          ((ulonglong)(uVar2 - 1) * 0x88 + 0xb0 <= (ulonglong)uVar1)))) {
        *(undefined4 *)(pFVar4 + 0x24) = 0;
        Lock(this);
        this_00 = *(FSRegObject **)(*(longlong *)(lVar3 + 0x30) + 0x20);
        bVar6 = FindStreamObject(this,this_00);
        uVar8 = Feature_1640916283__private_IsEnabledDeviceUsageNoInline();
        if (((int)uVar8 != 0) && (bVar6)) {
          LOCK();
          *(int *)(this_00 + 0x18) = *(int *)(this_00 + 0x18) + 1;
          UNLOCK();
        }
        KeReleaseMutex(this + 8,0);
        if (bVar6) {
          (**(code **)(*(longlong *)this_00 + 0x28))(this_00);
          lVar7 = FSStreamReg::DrainTx((FSStreamReg *)this_00,pFVar4);
          if (-1 < lVar7) {
            FSStreamReg::GetStats((FSStreamReg *)this_00,(FSQueueStats *)(pFVar4 + 8));
          }
          (**(code **)(*(longlong *)this_00 + 0x30))(this_00);
          if (*(int *)(pFVar4 + 0x24) == 0) {
            *(undefined8 *)(param_1 + 0x38) = 0xb0;
          }
          else {
            *(ulonglong *)(param_1 + 0x38) = (ulonglong)(*(int *)(pFVar4 + 0x24) - 1) * 0x88 + 0xb0;
          }
          goto LAB_14000c2b4;
        }
        goto LAB_14000c1a3;
      }
    }
    lVar7 = -0x3ffffff3;
  }
LAB_14000c2b4:
  uVar8 = Feature_1640916283__private_IsEnabledDeviceUsageNoInline();
  if (((int)uVar8 != 0) && (bVar6 != false)) {
    FSRegObject::Release(this_00);
  }
  return lVar7;
}



===== FSGetRendezvousServer @ 14000c2f4 =====

/* long __cdecl FSGetRendezvousServer(class FSRendezvousServer * __ptr64 * __ptr64) */

long __cdecl FSGetRendezvousServer(FSRendezvousServer **param_1)

{
  FSRendezvousServer *pFVar1;
  long lVar2;
  
  lVar2 = 0;
  KeWaitForSingleObject(&DAT_1400070d8,0,0,0,0);
  pFVar1 = DAT_1400070c0;
  if (param_1 == (FSRendezvousServer **)0x0) {
    lVar2 = -0x3ffffff3;
  }
  else if (DAT_1400070c0 == (FSRendezvousServer *)0x0) {
    lVar2 = -0x3ffffff0;
  }
  else {
    *param_1 = DAT_1400070c0;
    LOCK();
    *(int *)pFVar1 = *(int *)pFVar1 + 1;
    UNLOCK();
  }
  KeReleaseMutex(&DAT_1400070d8,0);
  return lVar2;
}



===== FindStreamObject @ 14000c374 =====

/* protected: bool __cdecl FSRendezvousServer::FindStreamObject(class FSRegObject const * __ptr64)
   __ptr64 */

bool __thiscall FSRendezvousServer::FindStreamObject(FSRendezvousServer *this,FSRegObject *param_1)

{
  FSRendezvousServer *pFVar1;
  FSRendezvousServer *pFVar2;
  ulonglong uVar3;
  FSRendezvousServer *pFVar4;
  
  if ((param_1 != (FSRegObject *)0x0) && (*(int *)(param_1 + 0x30) == 2)) {
    pFVar4 = this + 0x50;
    pFVar1 = this + 0x60;
    if (*(FSRendezvousServer **)pFVar4 != pFVar4) {
      *(FSRendezvousServer **)pFVar1 = *(FSRendezvousServer **)pFVar4;
    }
    while (((pFVar2 = *(FSRendezvousServer **)pFVar1, pFVar2 != (FSRendezvousServer *)0x0 &&
            (*(FSRendezvousServer **)pFVar4 != pFVar4)) && (pFVar2 != pFVar4))) {
      uVar3 = -(ulonglong)(pFVar2 != (FSRendezvousServer *)0x0) & (ulonglong)(pFVar2 + -8);
      if ((uVar3 != 0) && (*(FSRegObject **)(uVar3 + 0x20) == param_1)) {
        return true;
      }
      FSRegObjectList::MoveNext((FSRegObjectList *)(this + 0x40));
    }
  }
  return false;
}



===== InitializeContext @ 14000c3e4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: long __cdecl FSRendezvousServer::InitializeContext(struct _IRP * __ptr64) __ptr64 */

long __thiscall FSRendezvousServer::InitializeContext(FSRendezvousServer *this,_IRP *param_1)

{
  FSRendezvousServer *pFVar1;
  longlong lVar2;
  uint *puVar3;
  FSRendezvousServer *pFVar4;
  byte bVar5;
  char cVar6;
  uint uVar7;
  FSRegObject *this_00;
  _EPROCESS *p_Var8;
  longlong lVar9;
  ulonglong uVar10;
  
  cVar6 = KsIsCurrentProcessFrameServer();
  if (cVar6 == '\0') {
    uVar7 = 0xc0000022;
  }
  else {
    lVar2 = *(longlong *)(param_1 + 0xb8);
    if ((*(int *)(lVar2 + 0x18) == 0x2f0400) &&
       (*(longlong *)(*(longlong *)(lVar2 + 0x30) + 0x20) == 0)) {
      puVar3 = *(uint **)(param_1 + 0x18);
      if ((puVar3 == (uint *)0x0) || (*(uint *)(lVar2 + 0x10) < 0x20)) {
        uVar7 = 0xc000000d;
      }
      else {
        this_00 = (FSRegObject *)ExAllocatePoolWithTag(0x600,0x78,0x67657243);
        if (this_00 == (FSRegObject *)0x0) {
          uVar7 = 0xc000009a;
        }
        else {
          *(undefined4 *)(this_00 + 0x28) = 0;
          *(undefined4 *)(this_00 + 0x2c) = 0;
          *(undefined8 *)(this_00 + 0x38) = 0;
          *(undefined8 *)(this_00 + 0x40) = 0;
          *(undefined8 *)(this_00 + 0x48) = 0;
          *(undefined8 *)(this_00 + 0x70) = 0;
          *(undefined4 *)(this_00 + 0x18) = 1;
          *(FSRegObject **)(this_00 + 0x20) = this_00;
          *(undefined4 *)(this_00 + 0x30) = 1;
          *(undefined4 *)(this_00 + 0x34) = 0x78;
          *(undefined ***)this_00 = &FSContextReg::_vftable_;
          *(undefined8 *)(this_00 + 0x50) = 0;
          *(undefined8 *)(this_00 + 0x58) = 0;
          *(undefined8 *)(this_00 + 0x60) = 0;
          *(undefined8 *)(this_00 + 0x68) = 0;
          if ((((*(longlong *)(puVar3 + 2) == 0) || ((*puVar3 & 1) == 0)) ||
              (*(longlong *)(puVar3 + 4) == 0)) || (*(longlong *)(puVar3 + 6) != 0)) {
            uVar7 = 0xc000000d;
          }
          else {
            p_Var8 = (_EPROCESS *)IoGetCurrentProcess();
            uVar7 = FSRegObject::SetInitProcess(this_00,p_Var8);
            if (-1 < (int)uVar7) {
              *(uint *)(this_00 + 0x50) = *puVar3;
              *(undefined8 *)(this_00 + 0x58) = *(undefined8 *)(puVar3 + 2);
              *(undefined8 *)(this_00 + 0x60) = *(undefined8 *)(puVar3 + 4);
              *(undefined4 *)(this_00 + 0x28) = 1;
              Lock(this);
              pFVar1 = this + 0x80;
              if (*(FSRendezvousServer **)pFVar1 != pFVar1) {
                *(FSRendezvousServer **)(this + 0x90) = *(FSRendezvousServer **)pFVar1;
              }
              while (((pFVar4 = *(FSRendezvousServer **)(this + 0x90),
                      pFVar4 != (FSRendezvousServer *)0x0 &&
                      (*(FSRendezvousServer **)pFVar1 != pFVar1)) && (pFVar4 != pFVar1))) {
                uVar10 = -(ulonglong)(pFVar4 != (FSRendezvousServer *)0x0) &
                         (ulonglong)(pFVar4 + -8);
                if (((uVar10 != 0) && (*(longlong *)(puVar3 + 4) == *(longlong *)(uVar10 + 0x60)))
                   && (lVar9 = PsGetCurrentProcessId(-(longlong)pFVar4),
                      *(longlong *)(puVar3 + 2) == lVar9)) {
                  bVar5 = 1;
                  goto LAB_14000c5bb;
                }
                FSRegObjectList::MoveNext((FSRegObjectList *)(this + 0x70));
              }
              FSRegObjectList::InsertTail((FSRegObjectList *)(this + 0x70),this_00);
              *(FSRegObject **)(*(longlong *)(lVar2 + 0x30) + 0x20) = this_00;
              LOCK();
              *(int *)(this_00 + 0x18) = *(int *)(this_00 + 0x18) + 1;
              UNLOCK();
              this_00 = (FSRegObject *)0x0;
              bVar5 = 0;
LAB_14000c5bb:
              KeReleaseMutex(this + 8,0);
              uVar7 = -(uint)bVar5 & 0xc0000010;
              if (this_00 == (FSRegObject *)0x0) {
                return uVar7;
              }
            }
          }
          (*(code *)**(undefined8 **)this_00)(this_00,1);
        }
      }
    }
    else {
      uVar7 = 0xc0000010;
    }
  }
  return uVar7;
}



===== InitializeStream @ 14000c630 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: long __cdecl FSRendezvousServer::InitializeStream(struct _IRP * __ptr64) __ptr64 */

long __thiscall FSRendezvousServer::InitializeStream(FSRendezvousServer *this,_IRP *param_1)

{
  longlong lVar1;
  _FSStreamRegInfo *p_Var2;
  FSRendezvousServer *pFVar3;
  byte bVar4;
  char cVar5;
  uint uVar6;
  FSStreamReg *pFVar7;
  ulonglong uVar8;
  long lVar9;
  FSRegObjectList *pFVar10;
  FSRendezvousServer *pFVar11;
  FSRendezvousServer *pFVar12;
  
  cVar5 = KsIsCurrentProcessFrameServer();
  if (cVar5 == '\0') {
    lVar9 = -0x3fffffde;
  }
  else {
    lVar1 = *(longlong *)(param_1 + 0xb8);
    if ((*(int *)(lVar1 + 0x18) == 0x2f0404) &&
       (*(longlong *)(*(longlong *)(lVar1 + 0x30) + 0x20) == 0)) {
      p_Var2 = *(_FSStreamRegInfo **)(param_1 + 0x18);
      if ((((p_Var2 == (_FSStreamRegInfo *)0x0) || (*(uint *)(lVar1 + 0x10) < 0x30)) ||
          (*(longlong *)(p_Var2 + 8) == 0)) ||
         ((((*(uint *)p_Var2 & 1) == 0 || (0x74 < *(int *)(p_Var2 + 0x1c) - 4U)) ||
          ((0x7c000 < *(int *)(p_Var2 + 0x20) - 0x4000U ||
           ((*(longlong *)(p_Var2 + 0x10) == 0 || (*(longlong *)(p_Var2 + 0x28) == 0)))))))) {
        lVar9 = -0x3ffffff3;
      }
      else {
        pFVar10 = (FSRegObjectList *)0x67657253;
        pFVar7 = (FSStreamReg *)ExAllocatePoolWithTag(0x600,0x1d8);
        if ((pFVar7 != (FSStreamReg *)0x0) &&
           (pFVar7 = (FSStreamReg *)FSStreamReg::FSStreamReg(pFVar7), pFVar7 != (FSStreamReg *)0x0))
        {
          uVar6 = FSStreamReg::Initialize(pFVar7,param_1,pFVar10,p_Var2,(char)param_1[0x40]);
          if (-1 < (int)uVar6) {
            Lock(this);
            pFVar11 = this + 0x50;
            pFVar12 = this + 0x60;
            if (*(FSRendezvousServer **)pFVar11 != pFVar11) {
              *(FSRendezvousServer **)pFVar12 = *(FSRendezvousServer **)pFVar11;
            }
            while (((pFVar3 = *(FSRendezvousServer **)pFVar12, pFVar3 != (FSRendezvousServer *)0x0
                    && (*(FSRendezvousServer **)pFVar11 != pFVar11)) && (pFVar3 != pFVar11))) {
              uVar8 = -(ulonglong)(pFVar3 != (FSRendezvousServer *)0x0) & (ulonglong)(pFVar3 + -8);
              if (((uVar8 != 0) && (*(longlong *)(uVar8 + 0xa0) == *(longlong *)(p_Var2 + 8))) &&
                 ((*(longlong *)(uVar8 + 0xa8) == *(longlong *)(p_Var2 + 0x10) &&
                  (*(int *)(uVar8 + 0xb0) == *(int *)(p_Var2 + 0x18))))) {
                bVar4 = 1;
                goto LAB_14000c7cf;
              }
              FSRegObjectList::MoveNext((FSRegObjectList *)(this + 0x40));
            }
            FSRegObjectList::InsertTail((FSRegObjectList *)(this + 0x40),(FSRegObject *)pFVar7);
            *(FSStreamReg **)(*(longlong *)(lVar1 + 0x30) + 0x20) = pFVar7;
            LOCK();
            *(int *)(pFVar7 + 0x18) = *(int *)(pFVar7 + 0x18) + 1;
            UNLOCK();
            pFVar7 = (FSStreamReg *)0x0;
            bVar4 = 0;
LAB_14000c7cf:
            KeReleaseMutex(this + 8,0);
            uVar6 = -(uint)bVar4 & 0xc0000010;
            if (pFVar7 == (FSStreamReg *)0x0) {
              return uVar6;
            }
          }
          (*(code *)**(undefined8 **)pFVar7)(pFVar7,1);
          return uVar6;
        }
        lVar9 = -0x3fffff66;
      }
    }
    else {
      lVar9 = -0x3ffffff0;
    }
  }
  return lVar9;
}



===== Lock @ 14000c834 =====

/* protected: void __cdecl FSRendezvousServer::Lock(void) __ptr64 */

void __thiscall FSRendezvousServer::Lock(FSRendezvousServer *this)

{
  KeWaitForSingleObject(this + 8,0,0,0,0);
  return;
}



===== NotifyContext @ 14000c864 =====

/* public: long __cdecl FSRendezvousServer::NotifyContext(struct _IRP * __ptr64) __ptr64 */

long __thiscall FSRendezvousServer::NotifyContext(FSRendezvousServer *this,_IRP *param_1)

{
  longlong lVar1;
  uint *puVar2;
  FSRendezvousServer *pFVar3;
  char cVar4;
  ulonglong uVar5;
  long lVar6;
  FSRendezvousServer *pFVar7;
  FSRendezvousServer *pFVar8;
  
  lVar6 = 0;
  cVar4 = KsIsCurrentProcessFrameServer();
  if (cVar4 == '\0') {
    lVar6 = -0x3fffffde;
  }
  else {
    lVar1 = *(longlong *)(param_1 + 0xb8);
    if ((*(int *)(lVar1 + 0x18) == 0x2f0418) &&
       (*(longlong *)(*(longlong *)(lVar1 + 0x30) + 0x20) != 0)) {
      puVar2 = *(uint **)(param_1 + 0x18);
      if ((((puVar2 == (uint *)0x0) || (*(uint *)(lVar1 + 0x10) < 0x20)) ||
          (*(longlong *)(puVar2 + 2) == 0)) ||
         ((((*puVar2 & 1) == 0 || (*(longlong *)(puVar2 + 4) == 0)) ||
          (*(longlong *)(puVar2 + 6) != 0)))) {
        lVar6 = -0x3ffffff3;
      }
      else {
        Lock(this);
        pFVar7 = this + 0x80;
        pFVar8 = this + 0x90;
        if (*(FSRendezvousServer **)pFVar7 != pFVar7) {
          *(FSRendezvousServer **)pFVar8 = *(FSRendezvousServer **)pFVar7;
        }
        while (((pFVar3 = *(FSRendezvousServer **)pFVar8, pFVar3 != (FSRendezvousServer *)0x0 &&
                (*(FSRendezvousServer **)pFVar7 != pFVar7)) && (pFVar3 != pFVar7))) {
          uVar5 = -(ulonglong)(pFVar3 != (FSRendezvousServer *)0x0) & (ulonglong)(pFVar3 + -8);
          if (((uVar5 != 0) && (*(longlong *)(puVar2 + 4) == *(longlong *)(uVar5 + 0x60))) &&
             (*(longlong *)(puVar2 + 2) == *(longlong *)(uVar5 + 0x58))) {
            if (*(longlong *)(uVar5 + 0x70) != 0) {
              KeSetEvent(*(longlong *)(uVar5 + 0x70),0,0);
            }
            goto LAB_14000c978;
          }
          FSRegObjectList::MoveNext((FSRegObjectList *)(this + 0x70));
        }
        lVar6 = -0x3ffffff0;
LAB_14000c978:
        KeReleaseMutex(this + 8,0);
      }
    }
    else {
      lVar6 = -0x3ffffff0;
    }
  }
  return lVar6;
}



===== PublishRx @ 14000c9b4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: long __cdecl FSRendezvousServer::PublishRx(struct _IRP * __ptr64) __ptr64 */

long __thiscall FSRendezvousServer::PublishRx(FSRendezvousServer *this,_IRP *param_1)

{
  uint uVar1;
  longlong lVar2;
  FSFrameInfo *pFVar3;
  bool bVar4;
  long lVar5;
  ulonglong uVar6;
  FSRegObject *this_00;
  
  lVar2 = *(longlong *)(param_1 + 0xb8);
  this_00 = (FSRegObject *)0x0;
  bVar4 = false;
  if (*(longlong *)(*(longlong *)(lVar2 + 0x30) + 0x20) != 0) {
    pFVar3 = *(FSFrameInfo **)(param_1 + 0x18);
    if ((((pFVar3 == (FSFrameInfo *)0x0) || (*(uint *)(lVar2 + 0x10) < 0xb0)) ||
        (uVar1 = *(uint *)(pFVar3 + 0x20), 299 < uVar1 - 1)) ||
       ((uVar1 < *(uint *)(pFVar3 + 0x24) ||
        ((ulonglong)*(uint *)(lVar2 + 0x10) < (ulonglong)(uVar1 - 1) * 0x88 + 0xb0)))) {
      lVar5 = -0x3ffffff3;
      goto LAB_14000cadd;
    }
    Lock(this);
    this_00 = *(FSRegObject **)(*(longlong *)(lVar2 + 0x30) + 0x20);
    bVar4 = FindStreamObject(this,this_00);
    uVar6 = Feature_1640916283__private_IsEnabledDeviceUsageNoInline();
    if (((int)uVar6 != 0) && (bVar4)) {
      LOCK();
      *(int *)(this_00 + 0x18) = *(int *)(this_00 + 0x18) + 1;
      UNLOCK();
    }
    KeReleaseMutex(this + 8,0);
    if (bVar4) {
      (**(code **)(*(longlong *)this_00 + 0x28))(this_00);
      lVar5 = FSStreamReg::PublishRx((FSStreamReg *)this_00,pFVar3);
      if ((-1 < lVar5) && (0x17 < *(uint *)(lVar2 + 8))) {
        FSStreamReg::GetStats((FSStreamReg *)this_00,*(FSQueueStats **)(param_1 + 0x18));
        *(undefined8 *)(param_1 + 0x38) = 0x18;
      }
      (**(code **)(*(longlong *)this_00 + 0x30))(this_00);
      goto LAB_14000cadd;
    }
  }
  lVar5 = -0x3ffffff0;
LAB_14000cadd:
  uVar6 = Feature_1640916283__private_IsEnabledDeviceUsageNoInline();
  if (((int)uVar6 != 0) && (bVar4 != false)) {
    FSRegObject::Release(this_00);
  }
  return lVar5;
}



===== PublishTx @ 14000cb18 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: long __cdecl FSRendezvousServer::PublishTx(struct _IRP * __ptr64) __ptr64 */

long __thiscall FSRendezvousServer::PublishTx(FSRendezvousServer *this,_IRP *param_1)

{
  uint uVar1;
  longlong lVar2;
  FSFrameInfo *pFVar3;
  char cVar4;
  bool bVar5;
  long lVar6;
  ulonglong uVar7;
  FSRegObject *this_00;
  
  this_00 = (FSRegObject *)0x0;
  bVar5 = false;
  cVar4 = KsIsCurrentProcessFrameServer();
  if (cVar4 == '\0') {
    lVar6 = -0x3fffffde;
    goto LAB_14000cc5a;
  }
  lVar2 = *(longlong *)(param_1 + 0xb8);
  if (*(longlong *)(*(longlong *)(lVar2 + 0x30) + 0x20) != 0) {
    pFVar3 = *(FSFrameInfo **)(param_1 + 0x18);
    if ((((pFVar3 == (FSFrameInfo *)0x0) || (*(uint *)(lVar2 + 0x10) < 0xb0)) ||
        (uVar1 = *(uint *)(pFVar3 + 0x20), 299 < uVar1 - 1)) ||
       ((uVar1 < *(uint *)(pFVar3 + 0x24) ||
        ((ulonglong)*(uint *)(lVar2 + 0x10) < (ulonglong)(uVar1 - 1) * 0x88 + 0xb0)))) {
      lVar6 = -0x3ffffff3;
      goto LAB_14000cc5a;
    }
    Lock(this);
    this_00 = *(FSRegObject **)(*(longlong *)(lVar2 + 0x30) + 0x20);
    bVar5 = FindStreamObject(this,this_00);
    uVar7 = Feature_1640916283__private_IsEnabledDeviceUsageNoInline();
    if (((int)uVar7 != 0) && (bVar5)) {
      LOCK();
      *(int *)(this_00 + 0x18) = *(int *)(this_00 + 0x18) + 1;
      UNLOCK();
    }
    KeReleaseMutex(this + 8,0);
    if (bVar5) {
      (**(code **)(*(longlong *)this_00 + 0x28))(this_00);
      lVar6 = FSStreamReg::PublishTx((FSStreamReg *)this_00,pFVar3);
      if ((-1 < lVar6) && (0x17 < *(uint *)(lVar2 + 8))) {
        FSStreamReg::GetStats((FSStreamReg *)this_00,*(FSQueueStats **)(param_1 + 0x18));
        *(undefined8 *)(param_1 + 0x38) = 0x18;
      }
      (**(code **)(*(longlong *)this_00 + 0x30))(this_00);
      goto LAB_14000cc5a;
    }
  }
  lVar6 = -0x3ffffff0;
LAB_14000cc5a:
  uVar7 = Feature_1640916283__private_IsEnabledDeviceUsageNoInline();
  if (((int)uVar7 != 0) && (bVar5 != false)) {
    FSRegObject::Release(this_00);
  }
  return lVar6;
}



===== RegisterContext @ 14000cc94 =====

/* public: long __cdecl FSRendezvousServer::RegisterContext(struct _IRP * __ptr64) __ptr64 */

long __thiscall FSRendezvousServer::RegisterContext(FSRendezvousServer *this,_IRP *param_1)

{
  FSRendezvousServer *pFVar1;
  longlong lVar2;
  _FSContextRegInfo *p_Var3;
  FSRendezvousServer *pFVar4;
  long lVar5;
  longlong lVar6;
  long lVar7;
  FSContextReg *this_00;
  
  lVar2 = *(longlong *)(param_1 + 0xb8);
  lVar7 = 0;
  if ((*(int *)(lVar2 + 0x18) == 0x2f041c) &&
     (*(longlong *)(*(longlong *)(lVar2 + 0x30) + 0x20) == 0)) {
    p_Var3 = *(_FSContextRegInfo **)(param_1 + 0x18);
    if ((p_Var3 == (_FSContextRegInfo *)0x0) || (*(uint *)(lVar2 + 0x10) < 0x20)) {
      lVar7 = -0x3ffffff3;
    }
    else {
      Lock(this);
      pFVar1 = this + 0x80;
      if (*(FSRendezvousServer **)pFVar1 != pFVar1) {
        *(FSRendezvousServer **)(this + 0x90) = *(FSRendezvousServer **)pFVar1;
      }
      while (((pFVar4 = *(FSRendezvousServer **)(this + 0x90), pFVar4 != (FSRendezvousServer *)0x0
              && (*(FSRendezvousServer **)pFVar1 != pFVar1)) && (pFVar4 != pFVar1))) {
        this_00 = (FSContextReg *)
                  (-(ulonglong)(pFVar4 != (FSRendezvousServer *)0x0) & (ulonglong)(pFVar4 + -8));
        if ((this_00 != (FSContextReg *)0x0) &&
           (*(longlong *)(p_Var3 + 0x10) == *(longlong *)(this_00 + 0x60))) {
          lVar6 = PsGetCurrentProcessId(-(longlong)pFVar4);
          if (*(longlong *)(p_Var3 + 8) == lVar6) {
            lVar5 = FSContextReg::Register(this_00,p_Var3,(char)param_1[0x40]);
            if (lVar5 < 0) {
              lVar7 = lVar5;
            }
            else {
              *(FSContextReg **)(*(longlong *)(lVar2 + 0x30) + 0x20) = this_00;
              LOCK();
              *(int *)(this_00 + 0x18) = *(int *)(this_00 + 0x18) + 1;
              UNLOCK();
            }
            goto LAB_14000cd83;
          }
        }
        FSRegObjectList::MoveNext((FSRegObjectList *)(this + 0x70));
      }
      lVar7 = -0x3ffffff0;
LAB_14000cd83:
      KeReleaseMutex(this + 8,0);
    }
  }
  else {
    lVar7 = -0x3ffffff0;
  }
  return lVar7;
}



===== RegisterStream @ 14000cdcc =====

/* public: long __cdecl FSRendezvousServer::RegisterStream(struct _IRP * __ptr64) __ptr64 */

long __thiscall FSRendezvousServer::RegisterStream(FSRendezvousServer *this,_IRP *param_1)

{
  longlong lVar1;
  _FSStreamRegInfo *p_Var2;
  FSRendezvousServer *pFVar3;
  long lVar4;
  longlong lVar5;
  long lVar6;
  FSStreamReg *this_00;
  FSRendezvousServer *pFVar7;
  FSRendezvousServer *pFVar8;
  
  lVar1 = *(longlong *)(param_1 + 0xb8);
  lVar6 = 0;
  if ((*(int *)(lVar1 + 0x18) == 0x2f0420) &&
     (*(longlong *)(*(longlong *)(lVar1 + 0x30) + 0x20) == 0)) {
    p_Var2 = *(_FSStreamRegInfo **)(param_1 + 0x18);
    if ((((p_Var2 != (_FSStreamRegInfo *)0x0) && (0x2f < *(uint *)(lVar1 + 0x10))) &&
        (lVar5 = PsGetCurrentProcessId(), *(longlong *)(p_Var2 + 8) == lVar5)) &&
       ((((*(uint *)p_Var2 & 2) != 0 && (*(longlong *)(p_Var2 + 0x10) != 0)) &&
        (*(longlong *)(p_Var2 + 0x28) != 0)))) {
      Lock(this);
      pFVar7 = this + 0x50;
      pFVar8 = this + 0x60;
      if (*(FSRendezvousServer **)pFVar7 != pFVar7) {
        *(FSRendezvousServer **)pFVar8 = *(FSRendezvousServer **)pFVar7;
      }
      while (((pFVar3 = *(FSRendezvousServer **)pFVar8, pFVar3 != (FSRendezvousServer *)0x0 &&
              (*(FSRendezvousServer **)pFVar7 != pFVar7)) && (pFVar3 != pFVar7))) {
        this_00 = (FSStreamReg *)
                  (-(ulonglong)(pFVar3 != (FSRendezvousServer *)0x0) & (ulonglong)(pFVar3 + -8));
        if ((((this_00 != (FSStreamReg *)0x0) &&
             (*(longlong *)(this_00 + 0xa0) == *(longlong *)(p_Var2 + 8))) &&
            (*(longlong *)(this_00 + 0xa8) == *(longlong *)(p_Var2 + 0x10))) &&
           (*(int *)(this_00 + 0xb0) == *(int *)(p_Var2 + 0x18))) {
          lVar4 = FSStreamReg::Register(this_00,param_1,p_Var2,(char)param_1[0x40]);
          if (lVar4 < 0) {
            lVar6 = lVar4;
          }
          else {
            *(FSStreamReg **)(*(longlong *)(lVar1 + 0x30) + 0x20) = this_00;
            LOCK();
            *(int *)(this_00 + 0x18) = *(int *)(this_00 + 0x18) + 1;
            UNLOCK();
          }
          goto LAB_14000cef4;
        }
        FSRegObjectList::MoveNext((FSRegObjectList *)(this + 0x40));
      }
      lVar6 = -0x3ffffff0;
LAB_14000cef4:
      KeReleaseMutex(this + 8,0);
      return lVar6;
    }
    lVar6 = -0x3ffffff3;
  }
  else {
    lVar6 = -0x3ffffff0;
  }
  return lVar6;
}



===== Release @ 14000cf38 =====

/* public: long __cdecl FSRendezvousServer::Release(void) __ptr64 */

long __thiscall FSRendezvousServer::Release(FSRendezvousServer *this)

{
  int iVar1;
  
  LOCK();
  iVar1 = *(int *)this;
  *(int *)this = *(int *)this + -1;
  UNLOCK();
  if ((iVar1 + -1 == 0) && (this != (FSRendezvousServer *)0x0)) {
    ~FSRendezvousServer(this);
    ExFreePool(this);
  }
  return iVar1 + -1;
}



===== FSInitializeContextRendezvous @ 14000cf80 =====

long FSInitializeContextRendezvous(_IRP *param_1)

{
  long lVar1;
  FSRendezvousServer *pFVar2;
  FSRendezvousServer *pFVar3;
  FSRendezvousServer *this;
  
  this = (FSRendezvousServer *)0x0;
  KeWaitForSingleObject(&DAT_1400070d8,0,0,0,0);
  if (DAT_1400070c0 == (FSRendezvousServer *)0x0) {
    pFVar2 = (FSRendezvousServer *)ExAllocatePoolWithTag(0x600,0xa0,0x73767a52);
    if (pFVar2 == (FSRendezvousServer *)0x0) {
      pFVar2 = (FSRendezvousServer *)0x0;
    }
    else {
      *(undefined8 *)(pFVar2 + 0x60) = 0;
      *(int *)(pFVar2 + 0x68) = 0;
      *(undefined8 *)(pFVar2 + 0x90) = 0;
      *(int *)(pFVar2 + 0x98) = 0;
      *(undefined ***)(pFVar2 + 0x40) = &FSRegObjectList::_vftable_;
      *(undefined ***)(pFVar2 + 0x48) = &FSList::_vftable_;
      *(int *)pFVar2 = 1;
      pFVar3 = pFVar2 + 0x50;
      *(undefined ***)(pFVar2 + 0x70) = &FSRegObjectList::_vftable_;
      *(undefined ***)(pFVar2 + 0x78) = &FSList::_vftable_;
      *(FSRendezvousServer **)(pFVar2 + 0x58) = pFVar3;
      *(FSRendezvousServer **)pFVar3 = pFVar3;
      pFVar3 = pFVar2 + 0x80;
      *(FSRendezvousServer **)(pFVar2 + 0x88) = pFVar3;
      *(FSRendezvousServer **)pFVar3 = pFVar3;
      KeInitializeMutex(pFVar2 + 8,0);
    }
    DAT_1400070c0 = pFVar2;
    if (s_fsTraceEnable != 0) {
      DbgPrintEx(0x1d,3,"FSGetRendezvoudServer++ (new server=%p)\n",pFVar2);
    }
    if (DAT_1400070c0 == (FSRendezvousServer *)0x0) goto LAB_14000d08e;
  }
  this = DAT_1400070c0;
  LOCK();
  *(int *)DAT_1400070c0 = *(int *)DAT_1400070c0 + 1;
  UNLOCK();
LAB_14000d08e:
  KeReleaseMutex(&DAT_1400070d8,0);
  if (this == (FSRendezvousServer *)0x0) {
    lVar1 = -0x3fffff66;
  }
  else {
    lVar1 = FSRendezvousServer::InitializeContext(this,param_1);
    FSRendezvousServer::Release(this);
  }
  return lVar1;
}



===== FSRendezvousClearWnf @ 14000d0e0 =====

undefined8 FSRendezvousClearWnf(void)

{
  undefined4 local_res8;
  undefined4 local_resc;
  
  local_res8 = PsGetCurrentProcessId();
  local_resc = 0xffffffff;
  ZwUpdateWnfStateData(&WNF_KSV_FSSTREAMACTIVITY,&local_res8,8,0,0,0,0);
  return 0;
}



===== FSRendezvousClose @ 14000d138 =====

long FSRendezvousClose(_IRP *param_1)

{
  FSRendezvousServer *pFVar1;
  long lVar2;
  FSRendezvousServer *this;
  
  KeWaitForSingleObject(&DAT_1400070d8,0,0,0,0);
  pFVar1 = DAT_1400070c0;
  this = (FSRendezvousServer *)0x0;
  if (DAT_1400070c0 != (FSRendezvousServer *)0x0) {
    LOCK();
    *(int *)DAT_1400070c0 = *(int *)DAT_1400070c0 + 1;
    UNLOCK();
    this = pFVar1;
  }
  KeReleaseMutex(&DAT_1400070d8,0);
  if (this == (FSRendezvousServer *)0x0) {
    lVar2 = -0x3ffffff0;
  }
  else {
    lVar2 = FSRendezvousServer::Close(this,param_1);
    FSRendezvousServer::Release(this);
    if (s_fsTraceEnable != 0) {
      DbgPrintEx(0x1d,3,"FSRendezvousClose++\n");
    }
  }
  return lVar2;
}



===== ~FSList @ 14000d1e8 =====

/* public: virtual __cdecl FSList::~FSList(void) __ptr64 */

void __thiscall FSList::~FSList(FSList *this)

{
  *(undefined ***)this = &_vftable_;
  return;
}



===== RemoveCurrent @ 14000d1fc =====

/* public: struct _LIST_ENTRY * __ptr64 __cdecl FSList::RemoveCurrent(void) __ptr64 */

_LIST_ENTRY * __thiscall FSList::RemoveCurrent(FSList *this)

{
  FSList *pFVar1;
  _LIST_ENTRY *p_Var2;
  FSList *pFVar3;
  FSList *pFVar4;
  code *pcVar5;
  _LIST_ENTRY *p_Var6;
  
  pFVar1 = this + 8;
  p_Var6 = (_LIST_ENTRY *)0x0;
  if (*(FSList **)pFVar1 == pFVar1) {
    *(undefined8 *)(this + 0x18) = 0;
  }
  else {
    p_Var2 = *(_LIST_ENTRY **)(this + 0x18);
    if (p_Var2 != (_LIST_ENTRY *)0x0) {
      pFVar3 = *(FSList **)p_Var2;
      if ((*(_LIST_ENTRY **)(pFVar3 + 8) != p_Var2) ||
         (pFVar4 = *(FSList **)(p_Var2 + 8), *(_LIST_ENTRY **)pFVar4 != p_Var2)) {
        pcVar5 = (code *)swi(0x29);
        (*pcVar5)(3);
        pcVar5 = (code *)swi(3);
        p_Var6 = (_LIST_ENTRY *)(*pcVar5)();
        return p_Var6;
      }
      *(FSList **)pFVar4 = pFVar3;
      *(FSList **)(pFVar3 + 8) = pFVar4;
      if (pFVar4 == pFVar3) {
        *(int *)(this + 0x20) = *(int *)(this + 0x20) + -1;
      }
      p_Var6 = p_Var2;
      if ((*(FSList **)pFVar1 == pFVar1) || (pFVar3 == pFVar1)) {
        *(undefined8 *)(this + 0x18) = 0;
      }
      else {
        *(FSList **)(this + 0x18) = pFVar3;
      }
    }
  }
  return p_Var6;
}



===== RemoveHead @ 14000d264 =====

/* public: struct _LIST_ENTRY * __ptr64 __cdecl FSList::RemoveHead(void) __ptr64 */

_LIST_ENTRY * __thiscall FSList::RemoveHead(FSList *this)

{
  _LIST_ENTRY *p_Var1;
  longlong lVar2;
  code *pcVar3;
  _LIST_ENTRY *p_Var4;
  _LIST_ENTRY *p_Var5;
  
  p_Var5 = (_LIST_ENTRY *)(this + 8);
  p_Var1 = *(_LIST_ENTRY **)p_Var5;
  p_Var4 = (_LIST_ENTRY *)0x0;
  if (p_Var1 != p_Var5) {
    if ((*(_LIST_ENTRY **)(p_Var1 + 8) != p_Var5) ||
       (lVar2 = *(longlong *)p_Var1, *(_LIST_ENTRY **)(lVar2 + 8) != p_Var1)) {
      pcVar3 = (code *)swi(0x29);
      (*pcVar3)(3);
      pcVar3 = (code *)swi(3);
      p_Var5 = (_LIST_ENTRY *)(*pcVar3)();
      return p_Var5;
    }
    *(longlong *)p_Var5 = lVar2;
    *(_LIST_ENTRY **)(lVar2 + 8) = p_Var5;
    *(int *)(this + 0x20) = *(int *)(this + 0x20) + -1;
    p_Var4 = p_Var1;
    if (*(_LIST_ENTRY **)p_Var5 == p_Var5) {
      *(undefined8 *)(this + 0x18) = 0;
    }
    else if (*(_LIST_ENTRY **)(this + 0x18) == p_Var1) {
      *(_LIST_ENTRY **)(this + 0x18) = *(_LIST_ENTRY **)p_Var5;
      return p_Var1;
    }
  }
  return p_Var4;
}



===== ~FSRegObject @ 14000d2b8 =====

/* public: virtual __cdecl FSRegObject::~FSRegObject(void) __ptr64 */

void __thiscall FSRegObject::~FSRegObject(FSRegObject *this)

{
  *(undefined ***)this = &_vftable_;
  RemoveFromList(this);
  if (*(longlong *)(this + 0x38) != 0) {
    ObfDereferenceObject();
    *(undefined8 *)(this + 0x38) = 0;
  }
  if (*(longlong *)(this + 0x40) != 0) {
    ObfDereferenceObject();
    *(undefined8 *)(this + 0x40) = 0;
  }
  return;
}



===== ~FSRegObjectList @ 14000d314 =====

/* public: virtual __cdecl FSRegObjectList::~FSRegObjectList(void) __ptr64 */

void __thiscall FSRegObjectList::~FSRegObjectList(FSRegObjectList *this)

{
  _LIST_ENTRY *p_Var1;
  FSRegObject *this_00;
  
  *(undefined ***)this = &_vftable_;
  while (*(FSRegObjectList **)(this + 0x10) != this + 0x10) {
    p_Var1 = FSList::RemoveHead((FSList *)(this + 8));
    this_00 = (FSRegObject *)(-(ulonglong)(p_Var1 != (_LIST_ENTRY *)0x0) & (ulonglong)(p_Var1 + -8))
    ;
    *(undefined8 *)(this_00 + 0x48) = 0;
    FSRegObject::Release(this_00);
  }
  *(undefined ***)(this + 8) = &FSList::_vftable_;
  return;
}



===== operator_delete @ 14000d374 =====

/* void __cdecl operator delete(void * __ptr64) */

void __cdecl operator_delete(void *param_1)

{
  if (param_1 != (void *)0x0) {
    ExFreePool();
  }
  return;
}



===== CloseInitProcess @ 14000d3a0 =====

/* public: virtual void __cdecl FSRegObject::CloseInitProcess(struct _IRP * __ptr64) __ptr64 */

void __thiscall FSRegObject::CloseInitProcess(FSRegObject *this,_IRP *param_1)

{
  longlong lVar1;
  
  *(undefined4 *)(this + 0x28) = 0;
  if (((param_1 != (_IRP *)0x0) && (*(longlong *)(param_1 + 0xb8) != 0)) &&
     (lVar1 = *(longlong *)(*(longlong *)(param_1 + 0xb8) + 0x30), lVar1 != 0)) {
    *(undefined8 *)(lVar1 + 0x20) = 0;
  }
  return;
}



===== CloseRegProcess @ 14000d3d0 =====

/* public: virtual void __cdecl FSRegObject::CloseRegProcess(struct _IRP * __ptr64) __ptr64 */

void __thiscall FSRegObject::CloseRegProcess(FSRegObject *this,_IRP *param_1)

{
  longlong lVar1;
  
  *(undefined4 *)(this + 0x2c) = 0;
  if (((param_1 != (_IRP *)0x0) && (*(longlong *)(param_1 + 0xb8) != 0)) &&
     (lVar1 = *(longlong *)(*(longlong *)(param_1 + 0xb8) + 0x30), lVar1 != 0)) {
    *(undefined8 *)(lVar1 + 0x20) = 0;
  }
  return;
}



===== InsertTail @ 14000d3fc =====

/* public: void __cdecl FSRegObjectList::InsertTail(class FSRegObject * __ptr64) __ptr64 */

void __thiscall FSRegObjectList::InsertTail(FSRegObjectList *this,FSRegObject *param_1)

{
  code *pcVar1;
  longlong *plVar2;
  FSRegObjectList *pFVar3;
  FSRegObjectList *pFVar4;
  undefined8 *puVar5;
  
  puVar5 = (undefined8 *)(-(ulonglong)(param_1 != (FSRegObject *)0x0) & (ulonglong)(param_1 + 8));
  pFVar4 = this + 0x10;
  plVar2 = *(longlong **)(this + 0x18);
  if ((FSRegObjectList *)*plVar2 != pFVar4) {
    this = (FSRegObjectList *)0x3;
    pcVar1 = (code *)swi(0x29);
    plVar2 = (longlong *)(*pcVar1)();
  }
  *puVar5 = pFVar4;
  puVar5[1] = plVar2;
  *plVar2 = (longlong)puVar5;
  *(undefined8 **)(pFVar4 + 8) = puVar5;
  *(int *)(this + 0x28) = *(int *)(this + 0x28) + 1;
  if (*(longlong *)(this + 0x20) == 0) {
    pFVar3 = (FSRegObjectList *)0x0;
    if (*(FSRegObjectList **)pFVar4 != pFVar4) {
      pFVar3 = *(FSRegObjectList **)pFVar4;
    }
    *(FSRegObjectList **)(this + 0x20) = pFVar3;
  }
  *(FSRegObjectList **)(param_1 + 0x48) = this;
  return;
}



===== IsEmpty @ 14000d460 =====

/* public: virtual bool __cdecl FSRegObject::IsEmpty(void) __ptr64 */

bool __thiscall FSRegObject::IsEmpty(FSRegObject *this)

{
  bool bVar1;
  
  bVar1 = false;
  if ((*(int *)(this + 0x28) == 0) && (*(int *)(this + 0x2c) == 0)) {
    bVar1 = true;
  }
  return bVar1;
}



===== IsRegProcess @ 14000d478 =====

/* public: bool __cdecl FSRegObject::IsRegProcess(void)const __ptr64 */

bool __thiscall FSRegObject::IsRegProcess(FSRegObject *this)

{
  longlong lVar1;
  longlong lVar2;
  bool bVar3;
  
  if (*(longlong *)(this + 0x40) == 0) {
    bVar3 = false;
  }
  else {
    lVar1 = PsGetProcessId();
    lVar2 = PsGetCurrentProcessId();
    bVar3 = lVar1 == lVar2;
  }
  return bVar3;
}



===== Lock @ 14000d4c0 =====

/* public: virtual void __cdecl FSRegObject::Lock(void) __ptr64 */

void __thiscall FSRegObject::Lock(FSRegObject *this)

{
  return;
}



===== MoveNext @ 14000d4cc =====

/* public: int __cdecl FSRegObjectList::MoveNext(void) __ptr64 */

int __thiscall FSRegObjectList::MoveNext(FSRegObjectList *this)

{
  FSRegObjectList *pFVar1;
  FSRegObjectList *pFVar2;
  bool bVar3;
  
  pFVar2 = *(FSRegObjectList **)(this + 0x20);
  bVar3 = pFVar2 == (FSRegObjectList *)0x0;
  if (!bVar3) {
    pFVar1 = this + 0x10;
    if (*(FSRegObjectList **)pFVar1 != pFVar1) {
      pFVar2 = *(FSRegObjectList **)pFVar2;
      if (pFVar2 == pFVar1) {
        *(undefined8 *)(this + 0x20) = 0;
        pFVar2 = (FSRegObjectList *)0x0;
      }
      else {
        *(FSRegObjectList **)(this + 0x20) = pFVar2;
      }
    }
    bVar3 = pFVar2 == (FSRegObjectList *)0x0;
  }
  return (uint)!bVar3;
}



===== Release @ 14000d504 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: long __cdecl FSRegObject::Release(void) __ptr64 */

long __thiscall FSRegObject::Release(FSRegObject *this)

{
  FSRegObject *pFVar1;
  int iVar2;
  int iVar3;
  
  LOCK();
  pFVar1 = this + 0x18;
  iVar2 = *(int *)pFVar1;
  *(int *)pFVar1 = *(int *)pFVar1 + -1;
  UNLOCK();
  iVar3 = iVar2 + -1;
  if ((iVar3 == 0) && (this != (FSRegObject *)0x0)) {
    (*(code *)**(undefined8 **)this)(this,iVar2);
  }
  return iVar3;
}



===== RemoveFromList @ 14000d53c =====

/* public: void __cdecl FSRegObject::RemoveFromList(void) __ptr64 */

void __thiscall FSRegObject::RemoveFromList(FSRegObject *this)

{
  longlong lVar1;
  longlong *plVar2;
  longlong *plVar3;
  code *pcVar4;
  undefined8 *puVar5;
  FSRegObject *pFVar6;
  
  pFVar6 = this + 0x48;
  lVar1 = *(longlong *)pFVar6;
  if (lVar1 != 0) {
    puVar5 = (undefined8 *)(-(ulonglong)(this != (FSRegObject *)0x0) & (ulonglong)(this + 8));
    if (puVar5 != (undefined8 *)0x0) {
      if (puVar5 == *(undefined8 **)(lVar1 + 0x20)) {
        FSList::RemoveCurrent((FSList *)(lVar1 + 8));
      }
      else {
        plVar2 = (longlong *)*puVar5;
        if (((undefined8 *)plVar2[1] != puVar5) ||
           (plVar3 = (longlong *)puVar5[1], (undefined8 *)*plVar3 != puVar5)) {
          pcVar4 = (code *)swi(0x29);
          (*pcVar4)(3);
          pcVar4 = (code *)swi(3);
          (*pcVar4)();
          return;
        }
        *plVar3 = (longlong)plVar2;
        plVar2[1] = (longlong)plVar3;
        if (plVar3 == plVar2) {
          *(int *)(lVar1 + 0x28) = *(int *)(lVar1 + 0x28) + -1;
        }
      }
    }
    *(longlong *)pFVar6 = 0;
  }
  return;
}



===== SetInitProcess @ 14000d5a8 =====

/* public: long __cdecl FSRegObject::SetInitProcess(struct _EPROCESS * __ptr64) __ptr64 */

long __thiscall FSRegObject::SetInitProcess(FSRegObject *this,_EPROCESS *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (param_1 == (_EPROCESS *)0x0) {
    if (*(longlong *)(this + 0x38) != 0) {
      ObfDereferenceObject();
      *(undefined8 *)(this + 0x38) = 0;
    }
  }
  else if (*(longlong *)(this + 0x38) == 0) {
    iVar1 = ObReferenceObjectByPointer(param_1,0,0,0);
    if (iVar1 < 0) {
      iVar2 = iVar1;
    }
    else {
      *(_EPROCESS **)(this + 0x38) = param_1;
    }
  }
  else {
    iVar2 = -0x3ffffff0;
  }
  return iVar2;
}



===== SetRegProcess @ 14000d628 =====

/* public: long __cdecl FSRegObject::SetRegProcess(struct _EPROCESS * __ptr64) __ptr64 */

long __thiscall FSRegObject::SetRegProcess(FSRegObject *this,_EPROCESS *param_1)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  long lVar4;
  
  lVar4 = 0;
  if (param_1 == (_EPROCESS *)0x0) {
    if (*(longlong *)(this + 0x40) != 0) {
      ObfDereferenceObject();
      *(undefined8 *)(this + 0x40) = 0;
    }
  }
  else {
    if (*(longlong *)(this + 0x38) != 0) {
      lVar2 = PsGetProcessId();
      lVar3 = PsGetProcessId(param_1);
      if (lVar2 != lVar3) {
        if (*(longlong *)(this + 0x40) != 0) {
          return -0x3ffffff0;
        }
        iVar1 = ObReferenceObjectByPointer(param_1,0,0,0);
        if (iVar1 < 0) {
          return iVar1;
        }
        *(_EPROCESS **)(this + 0x40) = param_1;
        return 0;
      }
    }
    lVar4 = -0x3fffffff;
  }
  return lVar4;
}



===== FSFrameMdlList @ 14000d6e8 =====

/* public: __cdecl FSFrameMdlList::FSFrameMdlList(void) __ptr64 */

FSFrameMdlList * __thiscall FSFrameMdlList::FSFrameMdlList(FSFrameMdlList *this)

{
  FSFrameMdlList *pFVar1;
  
  *(undefined ***)this = &_vftable_;
  *(undefined ***)(this + 0x40) = &FSList::_vftable_;
  pFVar1 = this + 0x48;
  *(undefined8 *)(this + 0x58) = 0;
  *(undefined4 *)(this + 0x60) = 0;
  *(undefined8 *)(this + 0x68) = 0;
  *(undefined8 *)(this + 0x70) = 0;
  *(FSFrameMdlList **)(this + 0x50) = pFVar1;
  *(FSFrameMdlList **)pFVar1 = pFVar1;
  KeInitializeMutex(this + 8,0);
  return this;
}



===== ~FSFrameMdl @ 14000d744 =====

/* public: __cdecl FSFrameMdl::~FSFrameMdl(void) __ptr64 */

void __thiscall FSFrameMdl::~FSFrameMdl(FSFrameMdl *this)

{
  UnmapPages(this);
  FreeMdl(this);
  return;
}



===== ~FSFrameMdlList @ 14000d768 =====

/* public: virtual __cdecl FSFrameMdlList::~FSFrameMdlList(void) __ptr64 */

void __thiscall FSFrameMdlList::~FSFrameMdlList(FSFrameMdlList *this)

{
  *(undefined ***)this = &_vftable_;
  RemoveAll(this);
  if (*(longlong *)(this + 0x68) != 0) {
    ObfDereferenceObject();
    *(undefined8 *)(this + 0x68) = 0;
  }
  *(undefined ***)(this + 0x40) = &FSList::_vftable_;
  return;
}



===== AllocateMdl @ 14000d7b4 =====

/* public: long __cdecl FSFrameMdl::AllocateMdl(struct FSMemoryStream const & __ptr64) __ptr64 */

long __thiscall FSFrameMdl::AllocateMdl(FSFrameMdl *this,FSMemoryStream *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined8 uVar5;
  uint uVar6;
  int iVar7;
  longlong local_res8 [2];
  longlong *plVar8;
  
  uVar5 = *(undefined8 *)(param_1 + 8);
  iVar7 = 0;
  local_res8[1] = 0;
  local_res8[0] = 0;
  *(undefined8 *)(this + 0x18) = *(undefined8 *)param_1;
  *(undefined8 *)(this + 0x20) = uVar5;
  uVar5 = *(undefined8 *)(param_1 + 0x18);
  *(undefined8 *)(this + 0x28) = *(undefined8 *)(param_1 + 0x10);
  *(undefined8 *)(this + 0x30) = uVar5;
  uVar5 = *(undefined8 *)(param_1 + 0x28);
  *(undefined8 *)(this + 0x38) = *(undefined8 *)(param_1 + 0x20);
  *(undefined8 *)(this + 0x40) = uVar5;
  uVar5 = *(undefined8 *)(param_1 + 0x38);
  *(undefined8 *)(this + 0x48) = *(undefined8 *)(param_1 + 0x30);
  *(undefined8 *)(this + 0x50) = uVar5;
  uVar5 = *(undefined8 *)(param_1 + 0x48);
  *(undefined8 *)(this + 0x58) = *(undefined8 *)(param_1 + 0x40);
  *(undefined8 *)(this + 0x60) = uVar5;
  uVar1 = *(undefined4 *)(param_1 + 0x54);
  uVar2 = *(undefined4 *)(param_1 + 0x58);
  uVar3 = *(undefined4 *)(param_1 + 0x5c);
  *(undefined4 *)(this + 0x68) = *(undefined4 *)(param_1 + 0x50);
  *(undefined4 *)(this + 0x6c) = uVar1;
  *(undefined4 *)(this + 0x70) = uVar2;
  *(undefined4 *)(this + 0x74) = uVar3;
  uVar5 = *(undefined8 *)(param_1 + 0x68);
  *(undefined8 *)(this + 0x78) = *(undefined8 *)(param_1 + 0x60);
  *(undefined8 *)(this + 0x80) = uVar5;
  uVar1 = *(undefined4 *)(param_1 + 0x74);
  uVar2 = *(undefined4 *)(param_1 + 0x78);
  uVar3 = *(undefined4 *)(param_1 + 0x7c);
  *(undefined4 *)(this + 0x88) = *(undefined4 *)(param_1 + 0x70);
  *(undefined4 *)(this + 0x8c) = uVar1;
  *(undefined4 *)(this + 0x90) = uVar2;
  *(undefined4 *)(this + 0x94) = uVar3;
  *(undefined8 *)(this + 0x98) = *(undefined8 *)(param_1 + 0x80);
  uVar6 = *(uint *)(param_1 + 0x48) & 0xff;
  if ((char)*(uint *)(param_1 + 0x48) == '\0') {
    if ((*(longlong *)(param_1 + 0x20) != 0) || (*(int *)(param_1 + 0x30) != 0)) {
      iVar7 = -0x3ffffff3;
    }
  }
  else if (uVar6 != 1) {
    if (uVar6 == 2) {
      return -0x3ffffff3;
    }
    if ((uVar6 == 4) || (uVar6 == 8)) {
      uVar5 = FsAllocAndLockMdl(*(longlong *)(param_1 + 0x20),*(int *)(param_1 + 0x34),
                                (longlong *)(this + 0xa0));
      iVar4 = (int)uVar5;
    }
    else {
      if (uVar6 != 0x10) {
        if ((uVar6 != 0x20) && (uVar6 != 0x40)) {
          return -0x3ffffff3;
        }
        goto LAB_14000d91b;
      }
      plVar8 = local_res8 + 1;
      uVar6 = (uint)((ulonglong)*(undefined8 *)(this + 0x60) >> 0x3c) & 1 | 0x20000;
      iVar4 = ObReferenceObjectByHandle(*(undefined8 *)(param_1 + 0x20),uVar6,0,1,local_res8,plVar8)
      ;
      if (iVar4 < 0) goto LAB_14000d935;
      iVar4 = ObOpenObjectByPointer
                        (local_res8[0],2,0,uVar6,0,(ulonglong)plVar8 & 0xffffffffffffff00,
                         this + 0xc0);
    }
    if (iVar4 < 0) goto LAB_14000d935;
  }
LAB_14000d91b:
  uVar5 = FsAllocAndLockMdl(*(longlong *)(param_1 + 0x38),*(int *)(param_1 + 0x44),
                            (longlong *)(this + 0xb0));
  iVar4 = iVar7;
  if ((int)uVar5 < 0) {
    iVar4 = (int)uVar5;
  }
LAB_14000d935:
  if (local_res8[0] != 0) {
    ObfDereferenceObject();
  }
  return iVar4;
}



===== FreeAllMdls @ 14000d968 =====

/* public: void __cdecl FSFrameMdlList::FreeAllMdls(void) __ptr64 */

void __thiscall FSFrameMdlList::FreeAllMdls(FSFrameMdlList *this)

{
  FSFrameMdl *pFVar1;
  FSFrameMdl *this_00;
  
  pFVar1 = (FSFrameMdl *)(this + 0x48);
  if (*(FSFrameMdl **)pFVar1 != pFVar1) {
    *(FSFrameMdl **)(this + 0x58) = *(FSFrameMdl **)pFVar1;
  }
  while (((this_00 = *(FSFrameMdl **)(this + 0x58), this_00 != (FSFrameMdl *)0x0 &&
          (*(FSFrameMdl **)pFVar1 != pFVar1)) && (this_00 != pFVar1))) {
    FSFrameMdl::FreeMdl(this_00);
    MoveNext(this);
  }
  return;
}



===== FreeMdl @ 14000d9c8 =====

/* public: void __cdecl FSFrameMdl::FreeMdl(void) __ptr64 */

void __thiscall FSFrameMdl::FreeMdl(FSFrameMdl *this)

{
  if (*(longlong *)(this + 0xa0) != 0) {
    MmUnlockPages();
    IoFreeMdl(*(undefined8 *)(this + 0xa0));
    *(undefined8 *)(this + 0xa0) = 0;
  }
  if (*(longlong *)(this + 0xb0) != 0) {
    MmUnlockPages();
    IoFreeMdl(*(undefined8 *)(this + 0xb0));
    *(undefined8 *)(this + 0xb0) = 0;
  }
  if (*(longlong *)(this + 0xc0) != 0) {
    NtClose();
    *(undefined8 *)(this + 0xc0) = 0;
  }
  if ((*(ulonglong *)(this + 0x60) & 1) != 0) {
    *(undefined8 *)(this + 0x38) = 0;
  }
  if ((*(ulonglong *)(this + 0x60) & 0x20) != 0) {
    *(GUID *)(this + 0x38) = _GUID_00000000_0000_0000_0000_000000000000;
  }
  return;
}



===== InitializeMdlList @ 14000da84 =====

/* public: long __cdecl FSFrameMdlList::InitializeMdlList(void * __ptr64,char) __ptr64 */

long __thiscall FSFrameMdlList::InitializeMdlList(FSFrameMdlList *this,void *param_1,char param_2)

{
  int iVar1;
  int iVar2;
  longlong local_res20;
  
  iVar2 = 0;
  local_res20 = 0;
  iVar1 = ObReferenceObjectByHandle
                    (param_1,2,*(undefined8 *)ExEventObjectType_exref,param_2,&local_res20,0);
  if (iVar1 < 0) {
    iVar2 = iVar1;
  }
  else {
    if (*(longlong *)(this + 0x68) != 0) {
      ObfDereferenceObject();
    }
    *(longlong *)(this + 0x68) = local_res20;
    local_res20 = 0;
  }
  if (local_res20 != 0) {
    ObfDereferenceObject();
  }
  return iVar2;
}



===== InsertTail @ 14000db20 =====

/* public: void __cdecl FSFrameMdlList::InsertTail(class FSFrameMdl * __ptr64) __ptr64 */

void __thiscall FSFrameMdlList::InsertTail(FSFrameMdlList *this,FSFrameMdl *param_1)

{
  code *pcVar1;
  longlong *plVar2;
  FSFrameMdlList *pFVar3;
  FSFrameMdlList *pFVar4;
  
  pFVar3 = this + 0x48;
  plVar2 = *(longlong **)(this + 0x50);
  if ((FSFrameMdlList *)*plVar2 != pFVar3) {
    this = (FSFrameMdlList *)0x3;
    pcVar1 = (code *)swi(0x29);
    plVar2 = (longlong *)(*pcVar1)();
  }
  *(FSFrameMdlList **)param_1 = pFVar3;
  *(longlong **)(param_1 + 8) = plVar2;
  *plVar2 = (longlong)param_1;
  *(FSFrameMdl **)(pFVar3 + 8) = param_1;
  *(int *)(this + 0x60) = *(int *)(this + 0x60) + 1;
  if (*(longlong *)(this + 0x58) == 0) {
    pFVar4 = (FSFrameMdlList *)0x0;
    if (*(FSFrameMdlList **)pFVar3 != pFVar3) {
      pFVar4 = *(FSFrameMdlList **)pFVar3;
    }
    *(FSFrameMdlList **)(this + 0x58) = pFVar4;
  }
  *(ulonglong *)(this + 0x70) = *(longlong *)(this + 0x70) + (ulonglong)*(uint *)(param_1 + 0x4c);
  return;
}



===== MapPages @ 14000db6c =====

/* public: long __cdecl FSFrameMdl::MapPages(struct _EPROCESS * __ptr64,struct _EPROCESS *
   __ptr64,struct FSMemoryStream & __ptr64) __ptr64 */

long __thiscall
FSFrameMdl::MapPages(FSFrameMdl *this,_EPROCESS *param_1,_EPROCESS *param_2,FSMemoryStream *param_3)

{
  ulonglong uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  
  *(undefined4 *)(this + 0xd0) = 0;
  if ((param_1 == (_EPROCESS *)0x0) || (param_2 == (_EPROCESS *)0x0)) {
    return -0x3ffffff3;
  }
  uVar7 = *(undefined8 *)(this + 0x20);
  *(undefined8 *)param_3 = *(undefined8 *)(this + 0x18);
  *(undefined8 *)(param_3 + 8) = uVar7;
  uVar7 = *(undefined8 *)(this + 0x30);
  *(undefined8 *)(param_3 + 0x10) = *(undefined8 *)(this + 0x28);
  *(undefined8 *)(param_3 + 0x18) = uVar7;
  uVar7 = *(undefined8 *)(this + 0x40);
  *(undefined8 *)(param_3 + 0x20) = *(undefined8 *)(this + 0x38);
  *(undefined8 *)(param_3 + 0x28) = uVar7;
  uVar7 = *(undefined8 *)(this + 0x50);
  *(undefined8 *)(param_3 + 0x30) = *(undefined8 *)(this + 0x48);
  *(undefined8 *)(param_3 + 0x38) = uVar7;
  uVar7 = *(undefined8 *)(this + 0x60);
  *(undefined8 *)(param_3 + 0x40) = *(undefined8 *)(this + 0x58);
  *(undefined8 *)(param_3 + 0x48) = uVar7;
  uVar2 = *(undefined4 *)(this + 0x6c);
  uVar3 = *(undefined4 *)(this + 0x70);
  uVar4 = *(undefined4 *)(this + 0x74);
  *(undefined4 *)(param_3 + 0x50) = *(undefined4 *)(this + 0x68);
  *(undefined4 *)(param_3 + 0x54) = uVar2;
  *(undefined4 *)(param_3 + 0x58) = uVar3;
  *(undefined4 *)(param_3 + 0x5c) = uVar4;
  uVar7 = *(undefined8 *)(this + 0x80);
  *(undefined8 *)(param_3 + 0x60) = *(undefined8 *)(this + 0x78);
  *(undefined8 *)(param_3 + 0x68) = uVar7;
  uVar2 = *(undefined4 *)(this + 0x8c);
  uVar3 = *(undefined4 *)(this + 0x90);
  uVar4 = *(undefined4 *)(this + 0x94);
  *(undefined4 *)(param_3 + 0x70) = *(undefined4 *)(this + 0x88);
  *(undefined4 *)(param_3 + 0x74) = uVar2;
  *(undefined4 *)(param_3 + 0x78) = uVar3;
  *(undefined4 *)(param_3 + 0x7c) = uVar4;
  *(undefined8 *)(param_3 + 0x80) = *(undefined8 *)(this + 0x98);
  uVar1 = *(ulonglong *)(this + 0x60);
  uVar6 = uVar1 & 0xff;
  if (uVar6 != 1) {
    if (uVar6 == 2) {
      return -0x3ffffff3;
    }
    if ((uVar6 == 4) || (uVar6 == 8)) {
      if (*(int *)(this + 0x4c) == 0) {
        return 0;
      }
      uVar7 = FsMapLockedPages(*(longlong *)(this + 0xa0),
                               ~(uint)(uVar1 >> 0x1d) & 0xc0000010 | 0x40000010,
                               (undefined8 *)(this + 0xa8));
      if ((int)uVar7 < 0) {
        return (int)uVar7;
      }
      *(undefined8 *)(param_3 + 0x20) = *(undefined8 *)(this + 0xa8);
      *(undefined4 *)(this + 0xd0) = 1;
    }
    else if (uVar6 == 0x10) {
      iVar5 = ObDuplicateObject(param_1,*(undefined8 *)(this + 0xc0),param_2,param_3 + 0x20,
                                (uint)(uVar1 >> 0x3c) & 1 | 0x20000,0,4,1);
      if (iVar5 < 0) {
        return iVar5;
      }
      *(undefined8 *)(this + 200) = *(undefined8 *)(param_3 + 0x20);
    }
    else if ((uVar6 != 0x20) && (uVar6 != 0x40)) {
      return -0x3ffffff3;
    }
  }
  if (*(longlong *)(this + 0xb0) != 0) {
    uVar7 = FsMapLockedPages(*(longlong *)(this + 0xb0),0xc0000010,(undefined8 *)(this + 0xb8));
    if ((int)uVar7 < 0) {
      return (int)uVar7;
    }
    *(undefined8 *)(param_3 + 0x38) = *(undefined8 *)(this + 0xb8);
    *(undefined4 *)(this + 0xd0) = 1;
  }
  *(undefined4 *)(this + 0x10) = 1;
  return 0;
}



===== MoveNext @ 14000dd3c =====

/* public: int __cdecl FSFrameMdlList::MoveNext(void) __ptr64 */

int __thiscall FSFrameMdlList::MoveNext(FSFrameMdlList *this)

{
  FSFrameMdlList *pFVar1;
  FSFrameMdlList *pFVar2;
  bool bVar3;
  
  pFVar2 = *(FSFrameMdlList **)(this + 0x58);
  bVar3 = pFVar2 == (FSFrameMdlList *)0x0;
  if (!bVar3) {
    pFVar1 = this + 0x48;
    if (*(FSFrameMdlList **)pFVar1 != pFVar1) {
      pFVar2 = *(FSFrameMdlList **)pFVar2;
      if (pFVar2 == pFVar1) {
        *(undefined8 *)(this + 0x58) = 0;
        pFVar2 = (FSFrameMdlList *)0x0;
      }
      else {
        *(FSFrameMdlList **)(this + 0x58) = pFVar2;
      }
    }
    bVar3 = pFVar2 == (FSFrameMdlList *)0x0;
  }
  return (uint)!bVar3;
}



===== RemoveAll @ 14000dd74 =====

/* public: void __cdecl FSFrameMdlList::RemoveAll(void) __ptr64 */

void __thiscall FSFrameMdlList::RemoveAll(FSFrameMdlList *this)

{
  _LIST_ENTRY *this_00;
  
  while (*(FSFrameMdlList **)(this + 0x48) != this + 0x48) {
    this_00 = FSList::RemoveHead((FSList *)(this + 0x40));
    if (this_00 != (_LIST_ENTRY *)0x0) {
      FSFrameMdl::~FSFrameMdl((FSFrameMdl *)this_00);
      operator_delete(this_00);
    }
  }
  *(undefined8 *)(this + 0x70) = 0;
  return;
}



===== UnmapAllViews @ 14000ddd0 =====

/* public: void __cdecl FSFrameMdlList::UnmapAllViews(struct _EPROCESS * __ptr64,struct _FILE_OBJECT
   * __ptr64) __ptr64 */

void __thiscall
FSFrameMdlList::UnmapAllViews(FSFrameMdlList *this,_EPROCESS *param_1,_FILE_OBJECT *param_2)

{
  FSFrameMdl *pFVar1;
  int iVar2;
  FSFrameMdl *this_00;
  
  pFVar1 = (FSFrameMdl *)(this + 0x48);
  if (*(FSFrameMdl **)pFVar1 != pFVar1) {
    *(FSFrameMdl **)(this + 0x58) = *(FSFrameMdl **)pFVar1;
  }
  while (((this_00 = *(FSFrameMdl **)(this + 0x58), this_00 != (FSFrameMdl *)0x0 &&
          (*(FSFrameMdl **)pFVar1 != pFVar1)) && (this_00 != pFVar1))) {
    iVar2 = *(int *)(this_00 + 0xd0);
    FSFrameMdl::UnmapPages(this_00);
    if (iVar2 != 0) {
      if (param_1 != (_EPROCESS *)0x0) {
        ObfDereferenceObject(param_1);
      }
      if (param_2 != (_FILE_OBJECT *)0x0) {
        ObfDereferenceObject(param_2);
      }
    }
    MoveNext(this);
  }
  return;
}



===== UnmapPages @ 14000de78 =====

/* public: void __cdecl FSFrameMdl::UnmapPages(void) __ptr64 */

void __thiscall FSFrameMdl::UnmapPages(FSFrameMdl *this)

{
  if ((*(longlong *)(this + 0xa8) != 0) && (*(longlong *)(this + 0xa0) != 0)) {
    MmUnmapLockedPages();
    *(undefined8 *)(this + 0xa8) = 0;
  }
  if ((*(longlong *)(this + 0xb8) != 0) && (*(longlong *)(this + 0xb0) != 0)) {
    MmUnmapLockedPages();
    *(undefined8 *)(this + 0xb8) = 0;
  }
  if (*(longlong *)(this + 200) != 0) {
    *(undefined8 *)(this + 200) = 0;
  }
  if ((*(ulonglong *)(this + 0x60) & 1) != 0) {
    *(undefined8 *)(this + 0x38) = 0;
  }
  if ((*(ulonglong *)(this + 0x60) & 0x20) != 0) {
    *(GUID *)(this + 0x38) = _GUID_00000000_0000_0000_0000_000000000000;
  }
  *(undefined4 *)(this + 0xd0) = 0;
  *(undefined4 *)(this + 0x10) = 2;
  return;
}



===== FSStreamReg @ 14000df24 =====

/* public: __cdecl FSStreamReg::FSStreamReg(void) __ptr64 */

FSStreamReg * __thiscall FSStreamReg::FSStreamReg(FSStreamReg *this)

{
  *(undefined4 *)(this + 0x18) = 1;
  *(undefined8 *)(this + 0x28) = 0;
  *(undefined8 *)(this + 0x38) = 0;
  *(undefined8 *)(this + 0x40) = 0;
  *(undefined8 *)(this + 0x48) = 0;
  *(undefined ***)this = &_vftable_;
  *(FSStreamReg **)(this + 0x20) = this;
  *(undefined4 *)(this + 0x30) = 2;
  *(undefined4 *)(this + 0x34) = 0x1d8;
  FSFrameMdlList::FSFrameMdlList((FSFrameMdlList *)(this + 200));
  FSFrameMdlList::FSFrameMdlList((FSFrameMdlList *)(this + 0x140));
  *(undefined8 *)(this + 0x1b8) = 0;
  *(undefined4 *)(this + 0x1c0) = 0;
  *(undefined8 *)(this + 0x1c8) = 0;
  *(undefined8 *)(this + 0x1d0) = 0;
  *(undefined8 *)(this + 0x98) = 0;
  *(undefined8 *)(this + 0xa0) = 0;
  *(undefined8 *)(this + 0xa8) = 0;
  *(undefined8 *)(this + 0xb0) = 0;
  *(undefined8 *)(this + 0xb8) = 0;
  *(undefined8 *)(this + 0xc0) = 0;
  *(undefined8 *)(this + 0x58) = 0;
  *(undefined8 *)(this + 0x50) = 0;
  KeInitializeMutex(this + 0x60,0);
  return this;
}



===== ~FSStreamReg @ 14000dfe0 =====

/* public: virtual __cdecl FSStreamReg::~FSStreamReg(void) __ptr64 */

void __thiscall FSStreamReg::~FSStreamReg(FSStreamReg *this)

{
  *(undefined ***)this = &_vftable_;
  if (*(longlong *)(this + 0x38) != 0) {
    ObfDereferenceObject();
    *(undefined8 *)(this + 0x38) = 0;
  }
  if (*(longlong *)(this + 0x40) != 0) {
    ObfDereferenceObject();
    *(undefined8 *)(this + 0x40) = 0;
  }
  if (*(longlong *)(this + 0x58) != 0) {
    ExDeleteTimer(*(longlong *)(this + 0x58),1,1,0);
  }
  if (*(longlong *)(this + 0x50) != 0) {
    IoFreeWorkItem();
  }
  FSFrameMdlList::~FSFrameMdlList((FSFrameMdlList *)(this + 0x140));
  FSFrameMdlList::~FSFrameMdlList((FSFrameMdlList *)(this + 200));
  FSRegObject::~FSRegObject((FSRegObject *)this);
  return;
}



===== CheckRecycle @ 14000e088 =====

/* protected: long __cdecl FSStreamReg::CheckRecycle(struct FSFrameInfo * __ptr64) __ptr64 */

long __thiscall FSStreamReg::CheckRecycle(FSStreamReg *this,FSFrameInfo *param_1)

{
  FSStreamReg *pFVar1;
  int iVar2;
  bool bVar3;
  _LIST_ENTRY *p_Var4;
  FSFrameInfo *pFVar5;
  ulonglong uVar6;
  long lVar7;
  int iVar8;
  longlong lVar9;
  longlong lVar10;
  longlong lVar11;
  int iVar12;
  byte bVar13;
  FSStreamReg *pFVar14;
  byte bVar15;
  longlong lVar16;
  
  lVar7 = 0;
  lVar11 = 0;
  iVar12 = 0;
  bVar3 = false;
  bVar15 = 0;
  if (param_1 == (FSFrameInfo *)0x0) {
    return -0x3ffffff3;
  }
  if (*(uint *)(param_1 + 0x24) == 0) {
    return 0;
  }
  pFVar5 = param_1 + 0x5c;
  uVar6 = (ulonglong)*(uint *)(param_1 + 0x24);
  do {
    if (*(longlong *)(pFVar5 + 0x14) != 0) {
      lVar11 = lVar11 + (ulonglong)*(uint *)pFVar5;
      if ((*(uint *)(pFVar5 + 0x20) == 0) ||
         ((*(uint *)(pFVar5 + 0x20) == 3 && ((int)*(uint *)(pFVar5 + 0x24) < 0)))) {
        iVar12 = iVar12 + 1;
      }
    }
    pFVar5 = pFVar5 + 0x88;
    uVar6 = uVar6 - 1;
  } while (uVar6 != 0);
  iVar2 = *(int *)(this + 0x1bc);
  if ((longlong)*(int *)(this + 0x1b8) <=
      *(longlong *)(this + 0x138) + *(longlong *)(this + 0x1b0) + lVar11) {
    if ((*(int *)(this + 0x98) < 0) ||
       ((longlong)*(int *)(this + 0x1b8) <= *(longlong *)(this + 0x1b0))) {
      return -0x3fffff5f;
    }
    lVar9 = lVar11;
    if (lVar11 < 1) {
LAB_14000e214:
      bVar3 = false;
    }
    else {
      do {
        lVar16 = -0x8000000000000000;
        if (lVar7 < 0) break;
        pFVar1 = this + 0x110;
        lVar7 = 0;
        lVar10 = 0;
        if (*(FSStreamReg **)pFVar1 == pFVar1) {
          lVar7 = -0x3fffff5f;
        }
        else {
          *(FSStreamReg **)(this + 0x120) = *(FSStreamReg **)pFVar1;
          while (((pFVar14 = *(FSStreamReg **)(this + 0x120), pFVar14 != (FSStreamReg *)0x0 &&
                  (*(FSStreamReg **)pFVar1 != pFVar1)) && (pFVar14 != pFVar1))) {
            if (lVar16 == -0x8000000000000000) {
              lVar16 = *(longlong *)(pFVar14 + 0x18);
            }
            else if (lVar16 != *(longlong *)(pFVar14 + 0x18)) break;
            p_Var4 = FSList::RemoveCurrent((FSList *)(this + 0x108));
            if (p_Var4 != (_LIST_ENTRY *)0x0) {
              *(ulonglong *)(this + 0x138) =
                   *(longlong *)(this + 0x138) - (ulonglong)*(uint *)(p_Var4 + 0x4c);
            }
            *(undefined4 *)(pFVar14 + 0x10) = 2;
            FSFrameMdlList::InsertTail((FSFrameMdlList *)(this + 0x140),(FSFrameMdl *)pFVar14);
            lVar10 = lVar10 + (ulonglong)*(uint *)(pFVar14 + 0x4c);
          }
          lVar9 = lVar9 - lVar10;
        }
      } while (0 < lVar9);
      if (lVar11 <= lVar9) goto LAB_14000e214;
      bVar3 = true;
    }
    if (lVar7 < 0) goto LAB_14000e25e;
  }
  if (*(int *)(this + 0x1c0) <= iVar2 + iVar12) {
    iVar8 = 0;
    iVar12 = ((iVar2 + iVar12) - *(int *)(this + 0x1c0)) + 1;
    if (0 < iVar12) {
      pFVar1 = this + 0x110;
      do {
        lVar7 = 0;
        bVar13 = 0;
        lVar11 = -0x8000000000000000;
        if (*(FSStreamReg **)pFVar1 == pFVar1) {
          lVar7 = -0x3fffff5f;
        }
        else {
          *(FSStreamReg **)(this + 0x120) = *(FSStreamReg **)pFVar1;
          while (((pFVar14 = *(FSStreamReg **)(this + 0x120), pFVar14 != (FSStreamReg *)0x0 &&
                  (*(FSStreamReg **)pFVar1 != pFVar1)) && (pFVar14 != pFVar1))) {
            if (((*(int *)(pFVar14 + 0x6c) == 0) ||
                ((*(int *)(pFVar14 + 0x6c) == 3 && (*(int *)(pFVar14 + 0x70) < 0)))) &&
               (lVar11 == -0x8000000000000000)) {
              lVar11 = *(longlong *)(pFVar14 + 0x18);
LAB_14000e2e6:
              p_Var4 = FSList::RemoveCurrent((FSList *)(this + 0x108));
              if (p_Var4 != (_LIST_ENTRY *)0x0) {
                *(ulonglong *)(this + 0x138) =
                     *(longlong *)(this + 0x138) - (ulonglong)*(uint *)(p_Var4 + 0x4c);
              }
              *(undefined4 *)(pFVar14 + 0x10) = 2;
              FSFrameMdlList::InsertTail((FSFrameMdlList *)(this + 0x140),(FSFrameMdl *)pFVar14);
              bVar13 = 1;
            }
            else {
              if (lVar11 == *(longlong *)(pFVar14 + 0x18)) goto LAB_14000e2e6;
              if (lVar11 != -0x8000000000000000) break;
              FSFrameMdlList::MoveNext((FSFrameMdlList *)(this + 200));
            }
          }
        }
        bVar15 = bVar15 | bVar13;
      } while ((-1 < lVar7) && (iVar8 = iVar8 + 1, iVar8 < iVar12));
    }
  }
LAB_14000e25e:
  if (((bVar3) || (bVar15 != 0)) && (*(longlong *)(this + 0x1a8) != 0)) {
    KeSetEvent(*(longlong *)(this + 0x1a8),0,0);
  }
  return lVar7;
}



===== CloseInitProcess @ 14000e340 =====

/* public: virtual void __cdecl FSStreamReg::CloseInitProcess(struct _IRP * __ptr64) __ptr64 */

void __thiscall FSStreamReg::CloseInitProcess(FSStreamReg *this,_IRP *param_1)

{
  char cVar1;
  
  if (**(char **)(param_1 + 0xb8) == '\x12') {
    LOCK();
    *(int *)(this + 0x18) = *(int *)(this + 0x18) + 1;
    UNLOCK();
    LOCK();
    *(int *)(this + 0x18) = *(int *)(this + 0x18) + 1;
    UNLOCK();
    ExSetTimer(*(undefined8 *)(this + 0x58),0xfffffffffe363c80,0,0);
  }
  else {
    cVar1 = ExCancelTimer(*(undefined8 *)(this + 0x58),0);
    if (cVar1 != '\0') {
      FSRegObject::Release((FSRegObject *)this);
      CloseInitProcessInternal(this,param_1);
    }
  }
  return;
}



===== CloseInitProcessInternal @ 14000e3c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: void __cdecl FSStreamReg::CloseInitProcessInternal(struct _IRP * __ptr64) __ptr64 */

void __thiscall FSStreamReg::CloseInitProcessInternal(FSStreamReg *this,_IRP *param_1)

{
  longlong lVar1;
  undefined1 auStack_68 [32];
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  *(undefined4 *)(this + 0x28) = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  if (((param_1 != (_IRP *)0x0) && (*(longlong *)(param_1 + 0xb8) != 0)) &&
     (lVar1 = *(longlong *)(*(longlong *)(param_1 + 0xb8) + 0x30), lVar1 != 0)) {
    *(undefined8 *)(lVar1 + 0x20) = 0;
  }
  if (*(longlong *)(this + 0x40) != 0) {
    KeStackAttachProcess();
  }
  FSFrameMdlList::UnmapAllViews((FSFrameMdlList *)(this + 200),(_EPROCESS *)0x0,(_FILE_OBJECT *)0x0)
  ;
  FSFrameMdlList::UnmapAllViews
            ((FSFrameMdlList *)(this + 0x140),*(_EPROCESS **)(this + 0x38),
             *(_FILE_OBJECT **)(this + 0x1c8));
  if (*(longlong *)(this + 0x40) != 0) {
    KeUnstackDetachProcess(&local_48);
  }
  FSFrameMdlList::FreeAllMdls((FSFrameMdlList *)(this + 200));
  FSFrameMdlList::FreeAllMdls((FSFrameMdlList *)(this + 0x140));
  return;
}



===== CloseRegObject @ 14000e4b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: virtual void __cdecl FSStreamReg::CloseRegObject(void) __ptr64 */

void __thiscall FSStreamReg::CloseRegObject(FSStreamReg *this)

{
  bool bVar1;
  undefined1 auStack_68 [32];
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  bVar1 = FSRegObject::IsRegProcess((FSRegObject *)this);
  if ((!bVar1) && (*(longlong *)(this + 0x40) != 0)) {
    KeStackAttachProcess(*(longlong *)(this + 0x40),&local_48);
  }
  FSRegObject::RemoveFromList((FSRegObject *)this);
  FSFrameMdlList::RemoveAll((FSFrameMdlList *)(this + 200));
  FSFrameMdlList::RemoveAll((FSFrameMdlList *)(this + 0x140));
  *(undefined4 *)(this + 0x1b8) = 0;
  *(undefined4 *)(this + 0x1bc) = 0;
  *(undefined4 *)(this + 0x1c0) = 0;
  if ((!bVar1) && (*(longlong *)(this + 0x40) != 0)) {
    KeUnstackDetachProcess(&local_48);
  }
  if (*(longlong *)(this + 0x38) != 0) {
    ObfDereferenceObject();
    *(undefined8 *)(this + 0x38) = 0;
  }
  if (*(longlong *)(this + 0x40) != 0) {
    ObfDereferenceObject();
    *(undefined8 *)(this + 0x40) = 0;
  }
  return;
}



===== CloseRegProcess @ 14000e5b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: virtual void __cdecl FSStreamReg::CloseRegProcess(struct _IRP * __ptr64) __ptr64 */

void __thiscall FSStreamReg::CloseRegProcess(FSStreamReg *this,_IRP *param_1)

{
  longlong lVar1;
  bool bVar2;
  undefined1 auStack_68 [32];
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  bVar2 = FSRegObject::IsRegProcess((FSRegObject *)this);
  *(undefined4 *)(this + 0x2c) = 0;
  if (((param_1 != (_IRP *)0x0) && (*(longlong *)(param_1 + 0xb8) != 0)) &&
     (lVar1 = *(longlong *)(*(longlong *)(param_1 + 0xb8) + 0x30), lVar1 != 0)) {
    *(undefined8 *)(lVar1 + 0x20) = 0;
  }
  if ((!bVar2) && (*(longlong *)(this + 0x40) != 0)) {
    KeStackAttachProcess();
  }
  FSFrameMdlList::UnmapAllViews((FSFrameMdlList *)(this + 200),(_EPROCESS *)0x0,(_FILE_OBJECT *)0x0)
  ;
  FSFrameMdlList::UnmapAllViews
            ((FSFrameMdlList *)(this + 0x140),*(_EPROCESS **)(this + 0x38),
             *(_FILE_OBJECT **)(this + 0x1c8));
  if ((!bVar2) && (*(longlong *)(this + 0x40) != 0)) {
    KeUnstackDetachProcess(&local_48);
  }
  return;
}



===== ConsumeRx @ 14000e69c =====

/* public: long __cdecl FSStreamReg::ConsumeRx(struct FSFrameInfo * __ptr64) __ptr64 */

long __thiscall FSStreamReg::ConsumeRx(FSStreamReg *this,FSFrameInfo *param_1)

{
  FSFrameMdl *pFVar1;
  uint uVar2;
  FSFrameMdl *this_00;
  undefined8 uVar3;
  _LIST_ENTRY *p_Var4;
  char cVar5;
  longlong lVar6;
  
  cVar5 = '\0';
  lVar6 = 0;
  if ((param_1 == (FSFrameInfo *)0x0) || (*(int *)(param_1 + 0x20) == 0)) {
    return -0x3ffffff3;
  }
  pFVar1 = (FSFrameMdl *)(this + 0x188);
  *(undefined4 *)(param_1 + 0x24) = 0;
  if (*(FSFrameMdl **)pFVar1 != pFVar1) {
    *(FSFrameMdl **)(this + 0x198) = *(FSFrameMdl **)pFVar1;
  }
  do {
    while( true ) {
      this_00 = *(FSFrameMdl **)(this + 0x198);
      if (((this_00 == (FSFrameMdl *)0x0) || (*(FSFrameMdl **)pFVar1 == pFVar1)) ||
         (this_00 == pFVar1)) {
        if (lVar6 != 0) {
          *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 0x10000;
        }
        if (s_fsTraceEnable != 0) {
          DbgPrintEx(0x1d,3,"ConsumeRx(%d) stats[txsize:%I64d,rxsize:%I64d,txcount:%d,rxcount:%d]\n"
                     ,cVar5,*(undefined8 *)(this + 0x138),*(undefined8 *)(this + 0x1b0),
                     *(undefined4 *)(this + 0x128),*(undefined4 *)(this + 0x1a0));
        }
        if (cVar5 != '\0') {
          return 0;
        }
        if (lVar6 == 0) {
          return -0x7fffffe6;
        }
        return 0;
      }
      if (*(int *)(this_00 + 0x10) == 2) break;
LAB_14000e7ee:
      FSFrameMdlList::MoveNext((FSFrameMdlList *)(this + 0x140));
    }
    if (*(uint *)(param_1 + 0x20) <= *(uint *)(param_1 + 0x24)) {
      lVar6 = lVar6 + 1;
      goto LAB_14000e7ee;
    }
    p_Var4 = FSList::RemoveCurrent((FSList *)(this + 0x180));
    if (p_Var4 != (_LIST_ENTRY *)0x0) {
      *(ulonglong *)(this + 0x1b0) =
           *(longlong *)(this + 0x1b0) - (ulonglong)*(uint *)(p_Var4 + 0x4c);
    }
    FSFrameMdl::FreeMdl(this_00);
    uVar2 = *(uint *)(param_1 + 0x24);
    uVar3 = *(undefined8 *)(this_00 + 0x20);
    *(undefined8 *)(param_1 + (ulonglong)uVar2 * 0x88 + 0x28) = *(undefined8 *)(this_00 + 0x18);
    *(undefined8 *)(param_1 + (ulonglong)uVar2 * 0x88 + 0x30) = uVar3;
    uVar3 = *(undefined8 *)(this_00 + 0x30);
    *(undefined8 *)(param_1 + (ulonglong)uVar2 * 0x88 + 0x38) = *(undefined8 *)(this_00 + 0x28);
    *(undefined8 *)(param_1 + (ulonglong)uVar2 * 0x88 + 0x40) = uVar3;
    uVar3 = *(undefined8 *)(this_00 + 0x40);
    *(undefined8 *)(param_1 + (ulonglong)uVar2 * 0x88 + 0x48) = *(undefined8 *)(this_00 + 0x38);
    *(undefined8 *)(param_1 + (ulonglong)uVar2 * 0x88 + 0x50) = uVar3;
    uVar3 = *(undefined8 *)(this_00 + 0x50);
    *(undefined8 *)(param_1 + (ulonglong)uVar2 * 0x88 + 0x58) = *(undefined8 *)(this_00 + 0x48);
    *(undefined8 *)(param_1 + (ulonglong)uVar2 * 0x88 + 0x60) = uVar3;
    uVar3 = *(undefined8 *)(this_00 + 0x60);
    *(undefined8 *)(param_1 + (ulonglong)uVar2 * 0x88 + 0x68) = *(undefined8 *)(this_00 + 0x58);
    *(undefined8 *)(param_1 + (ulonglong)uVar2 * 0x88 + 0x70) = uVar3;
    uVar3 = *(undefined8 *)(this_00 + 0x70);
    *(undefined8 *)(param_1 + (ulonglong)uVar2 * 0x88 + 0x78) = *(undefined8 *)(this_00 + 0x68);
    *(undefined8 *)(param_1 + (ulonglong)uVar2 * 0x88 + 0x80) = uVar3;
    uVar3 = *(undefined8 *)(this_00 + 0x80);
    *(undefined8 *)(param_1 + (ulonglong)uVar2 * 0x88 + 0x88) = *(undefined8 *)(this_00 + 0x78);
    *(undefined8 *)(param_1 + (ulonglong)uVar2 * 0x88 + 0x90) = uVar3;
    uVar3 = *(undefined8 *)(this_00 + 0x90);
    *(undefined8 *)(param_1 + (ulonglong)uVar2 * 0x88 + 0x98) = *(undefined8 *)(this_00 + 0x88);
    *(undefined8 *)(param_1 + (ulonglong)uVar2 * 0x88 + 0xa0) = uVar3;
    *(undefined8 *)(param_1 + (ulonglong)uVar2 * 0x88 + 0xa8) = *(undefined8 *)(this_00 + 0x98);
    if ((*(int *)(this_00 + 0x6c) == 0) ||
       ((*(int *)(this_00 + 0x6c) == 3 && (*(int *)(this_00 + 0x70) < 0)))) {
      *(int *)(this + 0x1bc) = *(int *)(this + 0x1bc) + -1;
    }
    *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
    FSFrameMdl::~FSFrameMdl(this_00);
    operator_delete(this_00);
    cVar5 = '\x01';
  } while( true );
}



===== ConsumeTx @ 14000e890 =====

/* public: long __cdecl FSStreamReg::ConsumeTx(struct FSFrameInfo * __ptr64) __ptr64 */

long __thiscall FSStreamReg::ConsumeTx(FSStreamReg *this,FSFrameInfo *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  code *pcVar5;
  bool bVar6;
  long lVar7;
  _LIST_ENTRY *this_00;
  _LIST_ENTRY *p_Var8;
  FSList *pFVar9;
  FSList *pFVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  long lVar13;
  FSList *this_01;
  longlong lVar14;
  longlong lVar15;
  undefined1 auStack_58 [8];
  undefined1 auStack_50 [56];
  
  puVar11 = auStack_58;
  lVar13 = 0;
  bVar6 = false;
  lVar15 = -0x8000000000000000;
  if ((param_1 == (FSFrameInfo *)0x0) || (*(int *)(param_1 + 0x20) == 0)) {
    lVar13 = -0x3ffffff3;
  }
  else if ((*(int *)(this + 0x28) == 0) || (*(int *)(this + 0x2c) == 0)) {
    lVar13 = -0x3ffffb9a;
  }
  else {
    *(undefined4 *)(param_1 + 0x24) = 0;
    while (lVar14 = -0x8000000000000000, puVar12 = auStack_58,
          *(FSStreamReg **)(this + 0x110) != this + 0x110) {
      this_01 = (FSList *)(this + 0x108);
      this_00 = FSList::RemoveHead(this_01);
      if (this_00 != (_LIST_ENTRY *)0x0) {
        *(ulonglong *)(this + 0x138) =
             *(longlong *)(this + 0x138) - (ulonglong)*(uint *)(this_00 + 0x4c);
      }
      if (lVar15 != lVar14) {
        pFVar9 = this_01;
        if (lVar15 == *(longlong *)(this_00 + 0x18)) goto LAB_14000e93e;
        pFVar10 = this_01 + 8;
        lVar15 = *(longlong *)pFVar10;
        if (*(FSList **)(lVar15 + 8) != pFVar10) goto LAB_14000ea33;
LAB_14000ea3a:
        *(longlong *)this_00 = lVar15;
        *(FSList **)(this_00 + 8) = pFVar10;
        *(_LIST_ENTRY **)(lVar15 + 8) = this_00;
        *(_LIST_ENTRY **)pFVar10 = this_00;
        *(int *)(this_01 + 0x20) = *(int *)(this_01 + 0x20) + 1;
        bVar6 = false;
        if (*(longlong *)(this_01 + 0x18) == 0) {
          p_Var8 = (_LIST_ENTRY *)0x0;
          if (this_00 != (_LIST_ENTRY *)pFVar10) {
            p_Var8 = this_00;
          }
          *(_LIST_ENTRY **)(this_01 + 0x18) = p_Var8;
        }
LAB_14000ea5f:
        *(ulonglong *)(this + 0x138) =
             *(longlong *)(this + 0x138) + (ulonglong)*(uint *)(this_00 + 0x4c);
        puVar12 = puVar11;
        break;
      }
      lVar15 = *(longlong *)(this_00 + 0x18);
      pFVar9 = (FSList *)(this + 0x108);
LAB_14000e93e:
      if (*(uint *)(param_1 + 0x20) <= *(uint *)(param_1 + 0x24)) {
        pFVar10 = pFVar9 + 8;
        lVar15 = *(longlong *)pFVar10;
        if (*(FSList **)(lVar15 + 8) != pFVar10) {
LAB_14000ea33:
          pcVar5 = (code *)swi(0x29);
          lVar15 = (*pcVar5)(3);
          puVar11 = auStack_50;
          goto LAB_14000ea3a;
        }
        *(longlong *)this_00 = lVar15;
        *(FSList **)(this_00 + 8) = pFVar10;
        *(_LIST_ENTRY **)(lVar15 + 8) = this_00;
        *(_LIST_ENTRY **)pFVar10 = this_00;
        *(int *)(pFVar9 + 0x20) = *(int *)(pFVar9 + 0x20) + 1;
        if (*(longlong *)(pFVar9 + 0x18) == 0) {
          p_Var8 = (_LIST_ENTRY *)0x0;
          if (this_00 != (_LIST_ENTRY *)pFVar10) {
            p_Var8 = this_00;
          }
          *(_LIST_ENTRY **)(pFVar9 + 0x18) = p_Var8;
        }
        puVar11 = auStack_58;
        bVar6 = true;
        goto LAB_14000ea5f;
      }
      lVar7 = FSFrameMdl::MapPages
                        ((FSFrameMdl *)this_00,*(_EPROCESS **)(this + 0x38),
                         *(_EPROCESS **)(this + 0x40),
                         (FSMemoryStream *)
                         (param_1 + (ulonglong)*(uint *)(param_1 + 0x24) * 0x88 + 0x28));
      if ((lVar7 < 0) ||
         ((*(int *)(this_00 + 0xd0) != 0 &&
          ((lVar7 = ObReferenceObjectByPointer(*(undefined8 *)(this + 0x38),0,0,0), lVar7 < 0 ||
           (lVar7 = ObReferenceObjectByPointer(*(undefined8 *)(this + 0x1c8),0,0,0), lVar7 < 0))))))
      {
        if (this_00 == (_LIST_ENTRY *)0x0) {
          return lVar7;
        }
        FSFrameMdl::~FSFrameMdl((FSFrameMdl *)this_00);
        operator_delete(this_00);
        return lVar7;
      }
      FSFrameMdlList::InsertTail((FSFrameMdlList *)(this + 0x140),(FSFrameMdl *)this_00);
      *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
    }
    if (*(FSStreamReg **)(this + 0x110) != this + 0x110) {
      uVar1 = *(uint *)(param_1 + 4);
      *(uint *)(param_1 + 4) = uVar1 | 0x10000;
      if (bVar6) {
        *(uint *)(param_1 + 4) = uVar1 | 0x30000;
      }
    }
    uVar3 = *(undefined8 *)(this + 0x138);
    uVar4 = *(undefined8 *)(this + 0x1b0);
    uVar2 = *(undefined4 *)(this + 0x128);
    if (s_fsTraceEnable != 0) {
      *(undefined4 *)(puVar12 + 0x30) = *(undefined4 *)(this + 0x1a0);
      *(undefined4 *)(puVar12 + 0x28) = uVar2;
      *(undefined8 *)(puVar12 + 0x20) = uVar4;
      *(undefined8 *)(puVar12 + -8) = 0x14000ead0;
      DbgPrintEx(0x1d,3,"ConsumeTx() stats[txsize:%I64d,rxsize:%I64d,txcount:%d,rxcount:%d]\n",uVar3
                );
    }
  }
  return lVar13;
}



===== DrainTx @ 14000eb04 =====

/* public: long __cdecl FSStreamReg::DrainTx(struct FSFrameInfo * __ptr64) __ptr64 */

long __thiscall FSStreamReg::DrainTx(FSStreamReg *this,FSFrameInfo *param_1)

{
  undefined8 uVar1;
  uint uVar2;
  _LIST_ENTRY *this_00;
  long lVar3;
  
  lVar3 = 0;
  if ((param_1 == (FSFrameInfo *)0x0) || (*(int *)(param_1 + 0x20) == 0)) {
    lVar3 = -0x3ffffff3;
  }
  else {
    *(undefined4 *)(param_1 + 0x24) = 0;
    uVar2 = 0;
    while (*(FSStreamReg **)(this + 0x110) != this + 0x110) {
      if (*(uint *)(param_1 + 0x20) <= uVar2) {
        *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 0x10000;
        break;
      }
      this_00 = FSList::RemoveHead((FSList *)(this + 0x108));
      if (this_00 != (_LIST_ENTRY *)0x0) {
        *(ulonglong *)(this + 0x138) =
             *(longlong *)(this + 0x138) - (ulonglong)*(uint *)(this_00 + 0x4c);
      }
      uVar2 = *(uint *)(param_1 + 0x24);
      uVar1 = *(undefined8 *)(this_00 + 0x20);
      *(undefined8 *)(param_1 + (ulonglong)uVar2 * 0x88 + 0x28) = *(undefined8 *)(this_00 + 0x18);
      *(undefined8 *)(param_1 + (ulonglong)uVar2 * 0x88 + 0x30) = uVar1;
      uVar1 = *(undefined8 *)(this_00 + 0x30);
      *(undefined8 *)(param_1 + (ulonglong)uVar2 * 0x88 + 0x38) = *(undefined8 *)(this_00 + 0x28);
      *(undefined8 *)(param_1 + (ulonglong)uVar2 * 0x88 + 0x40) = uVar1;
      uVar1 = *(undefined8 *)(this_00 + 0x40);
      *(undefined8 *)(param_1 + (ulonglong)uVar2 * 0x88 + 0x48) = *(undefined8 *)(this_00 + 0x38);
      *(undefined8 *)(param_1 + (ulonglong)uVar2 * 0x88 + 0x50) = uVar1;
      uVar1 = *(undefined8 *)(this_00 + 0x50);
      *(undefined8 *)(param_1 + (ulonglong)uVar2 * 0x88 + 0x58) = *(undefined8 *)(this_00 + 0x48);
      *(undefined8 *)(param_1 + (ulonglong)uVar2 * 0x88 + 0x60) = uVar1;
      uVar1 = *(undefined8 *)(this_00 + 0x60);
      *(undefined8 *)(param_1 + (ulonglong)uVar2 * 0x88 + 0x68) = *(undefined8 *)(this_00 + 0x58);
      *(undefined8 *)(param_1 + (ulonglong)uVar2 * 0x88 + 0x70) = uVar1;
      uVar1 = *(undefined8 *)(this_00 + 0x70);
      *(undefined8 *)(param_1 + (ulonglong)uVar2 * 0x88 + 0x78) = *(undefined8 *)(this_00 + 0x68);
      *(undefined8 *)(param_1 + (ulonglong)uVar2 * 0x88 + 0x80) = uVar1;
      uVar1 = *(undefined8 *)(this_00 + 0x80);
      *(undefined8 *)(param_1 + (ulonglong)uVar2 * 0x88 + 0x88) = *(undefined8 *)(this_00 + 0x78);
      *(undefined8 *)(param_1 + (ulonglong)uVar2 * 0x88 + 0x90) = uVar1;
      uVar1 = *(undefined8 *)(this_00 + 0x90);
      *(undefined8 *)(param_1 + (ulonglong)uVar2 * 0x88 + 0x98) = *(undefined8 *)(this_00 + 0x88);
      *(undefined8 *)(param_1 + (ulonglong)uVar2 * 0x88 + 0xa0) = uVar1;
      *(undefined8 *)(param_1 + (ulonglong)uVar2 * 0x88 + 0xa8) = *(undefined8 *)(this_00 + 0x98);
      FSFrameMdl::~FSFrameMdl((FSFrameMdl *)this_00);
      operator_delete(this_00);
      *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
      uVar2 = *(uint *)(param_1 + 0x24);
    }
    GetStats(this,(FSQueueStats *)(param_1 + 8));
  }
  return lVar3;
}



===== GetStats @ 14000ec2c =====

/* public: void __cdecl FSStreamReg::GetStats(struct FSQueueStats * __ptr64) __ptr64 */

void __thiscall FSStreamReg::GetStats(FSStreamReg *this,FSQueueStats *param_1)

{
  if (param_1 != (FSQueueStats *)0x0) {
    *(undefined8 *)param_1 = *(undefined8 *)(this + 0x138);
    *(undefined8 *)(param_1 + 8) = *(undefined8 *)(this + 0x1b0);
    *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(this + 0x128);
    *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(this + 0x1a0);
  }
  return;
}



===== Initialize @ 14000ec60 =====

/* public: long __cdecl FSStreamReg::Initialize(struct _IRP * __ptr64,class FSRegObjectList *
   __ptr64,struct _FSStreamRegInfo const * __ptr64,char) __ptr64 */

long __thiscall
FSStreamReg::Initialize
          (FSStreamReg *this,_IRP *param_1,FSRegObjectList *param_2,_FSStreamRegInfo *param_3,
          char param_4)

{
  long lVar1;
  _EPROCESS *p_Var2;
  longlong lVar3;
  
  if ((((param_3 == (_FSStreamRegInfo *)0x0) || (*(longlong *)(param_3 + 8) == 0)) ||
      ((*(uint *)param_3 & 1) == 0)) ||
     (((0x74 < *(int *)(param_3 + 0x1c) - 4U || (0x7c000 < *(int *)(param_3 + 0x20) - 0x4000U)) ||
      ((*(longlong *)(param_3 + 0x10) == 0 || (*(void **)(param_3 + 0x28) == (void *)0x0)))))) {
    lVar1 = -0x3ffffff3;
  }
  else {
    lVar1 = FSFrameMdlList::InitializeMdlList
                      ((FSFrameMdlList *)(this + 0x140),*(void **)(param_3 + 0x28),param_4);
    if (-1 < lVar1) {
      p_Var2 = (_EPROCESS *)IoGetCurrentProcess();
      lVar1 = FSRegObject::SetInitProcess((FSRegObject *)this,p_Var2);
      if (-1 < lVar1) {
        lVar3 = ExAllocateTimer(MsKsSrvFSStreamRegCleanupWorkItem,this,0x80000004);
        *(longlong *)(this + 0x58) = lVar3;
        if (lVar3 != 0) {
          lVar3 = IoAllocateWorkItem(*(undefined8 *)(*(longlong *)(param_1 + 0xb8) + 0x28));
          *(longlong *)(this + 0x50) = lVar3;
          if (lVar3 != 0) {
            *(int *)(this + 0x1b8) = *(int *)(param_3 + 0x20) << 10;
            *(undefined4 *)(this + 0x1c0) = *(undefined4 *)(param_3 + 0x1c);
            *(undefined4 *)(this + 0x98) = 1;
            *(undefined8 *)(this + 0xa0) = *(undefined8 *)(param_3 + 8);
            *(undefined8 *)(this + 0xa8) = *(undefined8 *)(param_3 + 0x10);
            *(undefined4 *)(this + 0xb0) = *(undefined4 *)(param_3 + 0x18);
            *(undefined4 *)(this + 0xb4) = *(undefined4 *)(param_3 + 0x1c);
            *(undefined8 *)(this + 0xc0) = 0;
            *(undefined4 *)(this + 0x28) = 1;
            *(undefined8 *)(this + 0x1c8) = *(undefined8 *)(*(longlong *)(param_1 + 0xb8) + 0x30);
            return 0;
          }
        }
        return -0x3fffff66;
      }
    }
  }
  return lVar1;
}



===== Lock @ 14000edf0 =====

/* public: virtual void __cdecl FSStreamReg::Lock(void) __ptr64 */

void __thiscall FSStreamReg::Lock(FSStreamReg *this)

{
  KeWaitForSingleObject(this + 0x60,0,0,0,0);
  return;
}



===== MsKsSrvFSStreamRegCleanupWorkitemRoutine @ 14000ee20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl MsKsSrvFSStreamRegCleanupWorkitemRoutine(struct _DEVICE_OBJECT * __ptr64,void *
   __ptr64) */

void __cdecl MsKsSrvFSStreamRegCleanupWorkitemRoutine(_DEVICE_OBJECT *param_1,void *param_2)

{
  if (param_2 != (void *)0x0) {
    (**(code **)(*(longlong *)param_2 + 0x28))(param_2);
    FSStreamReg::CloseInitProcessInternal(param_2,(_IRP *)0x0);
    (**(code **)(*(longlong *)param_2 + 0x30))(param_2);
    FSRegObject::Release(param_2);
  }
  return;
}



===== PublishRx @ 14000ee6c =====

/* public: long __cdecl FSStreamReg::PublishRx(struct FSFrameInfo const * __ptr64) __ptr64 */

long __thiscall FSStreamReg::PublishRx(FSStreamReg *this,FSFrameInfo *param_1)

{
  FSFrameMdl *pFVar1;
  int iVar2;
  FSFrameMdl *this_00;
  char cVar3;
  long lVar4;
  uint uVar5;
  ulonglong uVar6;
  
  lVar4 = 0;
  cVar3 = '\0';
  if ((param_1 == (FSFrameInfo *)0x0) || (*(int *)(param_1 + 0x20) == 0)) {
    lVar4 = -0x3ffffff3;
  }
  else {
    pFVar1 = (FSFrameMdl *)(this + 0x188);
    if (*(FSFrameMdl **)pFVar1 == pFVar1) {
      lVar4 = -0x3ffffff0;
    }
    else {
      uVar6 = 0;
      if (*(int *)(param_1 + 0x24) != 0) {
        do {
          if (*(FSFrameMdl **)pFVar1 != pFVar1) {
            *(FSFrameMdl **)(this + 0x198) = *(FSFrameMdl **)pFVar1;
          }
          while( true ) {
            this_00 = *(FSFrameMdl **)(this + 0x198);
            if (((this_00 == (FSFrameMdl *)0x0) || (*(FSFrameMdl **)pFVar1 == pFVar1)) ||
               (this_00 == pFVar1)) break;
            if (*(longlong *)(this_00 + 0x20) == *(longlong *)(param_1 + uVar6 * 0x88 + 0x30)) {
              iVar2 = *(int *)(this_00 + 0xd0);
              FSFrameMdl::UnmapPages(this_00);
              if (iVar2 != 0) {
                ObfDereferenceObject(*(undefined8 *)(this + 0x38));
                ObfDereferenceObject(*(undefined8 *)(this + 0x1c8));
              }
              cVar3 = '\x01';
            }
            FSFrameMdlList::MoveNext((FSFrameMdlList *)(this + 0x140));
          }
          uVar5 = (int)uVar6 + 1;
          uVar6 = (ulonglong)uVar5;
        } while (uVar5 < *(uint *)(param_1 + 0x24));
      }
      if (s_fsTraceEnable != 0) {
        DbgPrintEx(0x1d,3,"PublishRx(%d) stats[txsize:%I64d,rxsize:%I64d,txcount:%d,rxcount:%d]\n",
                   cVar3,*(undefined8 *)(this + 0x138),*(undefined8 *)(this + 0x1b0),
                   *(undefined4 *)(this + 0x128),*(undefined4 *)(this + 0x1a0));
      }
      if ((cVar3 != '\0') && (*(longlong *)(this + 0x1a8) != 0)) {
        KeSetEvent(*(longlong *)(this + 0x1a8),0,0);
      }
    }
  }
  return lVar4;
}



===== PublishTx @ 14000efe8 =====

/* public: long __cdecl FSStreamReg::PublishTx(struct FSFrameInfo * __ptr64) __ptr64 */

long __thiscall FSStreamReg::PublishTx(FSStreamReg *this,FSFrameInfo *param_1)

{
  long lVar1;
  FSFrameMdl *this_00;
  long lVar2;
  char cVar3;
  uint uVar4;
  ulonglong uVar5;
  
  lVar2 = 0;
  cVar3 = '\0';
  lVar1 = CheckRecycle(this,param_1);
  if (lVar1 < 0) {
    lVar2 = lVar1;
  }
  else {
    uVar5 = 0;
    if (*(int *)(param_1 + 0x24) != 0) {
      do {
        if (*(longlong *)(param_1 + uVar5 * 0x88 + 0x70) != 0) {
          this_00 = (FSFrameMdl *)ExAllocatePoolWithTag(0x600,0xd8,0x736c644d);
          if (this_00 == (FSFrameMdl *)0x0) {
            return -0x3fffff66;
          }
          *(undefined4 *)(this_00 + 0x10) = 0;
          *(undefined4 *)(this_00 + 0xd0) = 0;
          memset(this_00 + 0x18,0,0x88);
          *(undefined8 *)(this_00 + 0xa0) = 0;
          *(undefined8 *)(this_00 + 0xa8) = 0;
          *(undefined8 *)(this_00 + 0xb0) = 0;
          *(undefined8 *)(this_00 + 0xb8) = 0;
          *(undefined8 *)(this_00 + 0xc0) = 0;
          *(undefined8 *)(this_00 + 200) = 0;
          lVar1 = FSFrameMdl::AllocateMdl(this_00,(FSMemoryStream *)(param_1 + uVar5 * 0x88 + 0x28))
          ;
          if (lVar1 < 0) {
            FSFrameMdl::~FSFrameMdl(this_00);
            operator_delete(this_00);
            return lVar1;
          }
          FSFrameMdlList::InsertTail((FSFrameMdlList *)(this + 200),this_00);
          if ((*(int *)(this_00 + 0x6c) == 0) ||
             ((*(int *)(this_00 + 0x6c) == 3 && (*(int *)(this_00 + 0x70) < 0)))) {
            *(int *)(this + 0x1bc) = *(int *)(this + 0x1bc) + 1;
          }
          cVar3 = '\x01';
        }
        uVar4 = (int)uVar5 + 1;
        uVar5 = (ulonglong)uVar4;
      } while (uVar4 < *(uint *)(param_1 + 0x24));
    }
    if (s_fsTraceEnable != 0) {
      DbgPrintEx(0x1d,3,"PublishTx(%d) stats[txsize:%I64d,rxsize:%I64d,txcount:%d,rxcount:%d]\n",
                 cVar3,*(undefined8 *)(this + 0x138),*(undefined8 *)(this + 0x1b0),
                 *(undefined4 *)(this + 0x128),*(undefined4 *)(this + 0x1a0));
    }
    if ((cVar3 != '\0') && (*(longlong *)(this + 0x130) != 0)) {
      KeSetEvent(*(longlong *)(this + 0x130),0,0);
    }
  }
  return lVar2;
}



===== Register @ 14000f19c =====

/* public: long __cdecl FSStreamReg::Register(struct _IRP * __ptr64,struct _FSStreamRegInfo const *
   __ptr64,char) __ptr64 */

long __thiscall
FSStreamReg::Register(FSStreamReg *this,_IRP *param_1,_FSStreamRegInfo *param_2,char param_3)

{
  long lVar1;
  longlong lVar2;
  _EPROCESS *p_Var3;
  
  if ((((param_2 == (_FSStreamRegInfo *)0x0) || (param_1 == (_IRP *)0x0)) ||
      (lVar2 = PsGetCurrentProcessId(), *(longlong *)(param_2 + 8) != lVar2)) ||
     ((((*(uint *)param_2 & 2) == 0 || (*(longlong *)(param_2 + 0x10) == 0)) ||
      (*(void **)(param_2 + 0x28) == (void *)0x0)))) {
    return -0x3ffffff3;
  }
  lVar1 = FSFrameMdlList::InitializeMdlList
                    ((FSFrameMdlList *)(this + 200),*(void **)(param_2 + 0x28),param_3);
  if (-1 < lVar1) {
    p_Var3 = (_EPROCESS *)IoGetCurrentProcess();
    lVar1 = FSRegObject::SetRegProcess((FSRegObject *)this,p_Var3);
    if (-1 < lVar1) {
      *(uint *)(this + 0x98) = *(uint *)(this + 0x98) | 2;
      *(undefined8 *)(this + 0x1d0) = *(undefined8 *)(*(longlong *)(param_1 + 0xb8) + 0x30);
      *(undefined4 *)(this + 0x2c) = 1;
      return 0;
    }
  }
  return lVar1;
}



===== Unlock @ 14000f280 =====

/* public: virtual void __cdecl FSStreamReg::Unlock(void) __ptr64 */

void __thiscall FSStreamReg::Unlock(FSStreamReg *this)

{
  KeReleaseMutex(this + 0x60,0);
  return;
}



===== ~FSContextReg @ 14000f2a4 =====

/* public: virtual __cdecl FSContextReg::~FSContextReg(void) __ptr64 */

void __thiscall FSContextReg::~FSContextReg(FSContextReg *this)

{
  *(undefined ***)this = &_vftable_;
  if (*(longlong *)(this + 0x70) != 0) {
    ObfDereferenceObject();
    *(undefined8 *)(this + 0x70) = 0;
  }
  FSRegObject::~FSRegObject((FSRegObject *)this);
  return;
}



===== CloseRegObject @ 14000f2f0 =====

/* public: virtual void __cdecl FSContextReg::CloseRegObject(void) __ptr64 */

void __thiscall FSContextReg::CloseRegObject(FSContextReg *this)

{
  if (*(longlong *)(this + 0x38) != 0) {
    ObfDereferenceObject();
    *(undefined8 *)(this + 0x38) = 0;
  }
  if (*(longlong *)(this + 0x40) != 0) {
    ObfDereferenceObject();
    *(undefined8 *)(this + 0x40) = 0;
  }
  FSRegObject::RemoveFromList((FSRegObject *)this);
  if (*(longlong *)(this + 0x70) != 0) {
    ObfDereferenceObject();
    *(undefined8 *)(this + 0x70) = 0;
  }
  return;
}



===== Register @ 14000f35c =====

/* public: long __cdecl FSContextReg::Register(struct _FSContextRegInfo const * __ptr64,char)
   __ptr64 */

long __thiscall FSContextReg::Register(FSContextReg *this,_FSContextRegInfo *param_1,char param_2)

{
  int iVar1;
  longlong lVar2;
  _EPROCESS *p_Var3;
  int iVar4;
  longlong local_res10;
  
  iVar4 = 0;
  local_res10 = 0;
  lVar2 = PsGetCurrentProcessId();
  if ((((*(longlong *)(param_1 + 8) == lVar2) && ((*(uint *)param_1 & 2) != 0)) &&
      (*(longlong *)(param_1 + 0x10) != 0)) && (*(longlong *)(param_1 + 0x18) != 0)) {
    iVar1 = ObReferenceObjectByHandle
                      (*(longlong *)(param_1 + 0x18),2,*(undefined8 *)ExEventObjectType_exref,
                       param_2,&local_res10,0);
    if (-1 < iVar1) {
      p_Var3 = (_EPROCESS *)IoGetCurrentProcess();
      iVar1 = FSRegObject::SetRegProcess((FSRegObject *)this,p_Var3);
      lVar2 = local_res10;
      if (-1 < iVar1) {
        *(uint *)(this + 0x50) = *(uint *)(this + 0x50) | 2;
        local_res10 = 0;
        *(longlong *)(this + 0x70) = lVar2;
        *(undefined4 *)(this + 0x2c) = 1;
        goto LAB_14000f414;
      }
    }
    iVar4 = iVar1;
  }
  else {
    iVar4 = -0x3ffffff3;
  }
LAB_14000f414:
  if (local_res10 != 0) {
    ObfDereferenceObject();
  }
  return iVar4;
}



===== entry @ 140010010 =====

void entry(longlong param_1)

{
  __security_init_cookie();
  DriverEntry(param_1);
  return;
}



===== __security_init_cookie @ 140010044 =====

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



===== DriverEntry @ 140010078 =====

undefined8 DriverEntry(longlong param_1)

{
  wil_InitializeFeatureStaging();
  if (DAT_1400070d0 == '\0') {
    if (s_fsTraceEnable != 0) {
      DbgPrintEx(0x1d,3,"FSInitializeRendezvous++ ()\n");
    }
    KeInitializeMutex(&DAT_1400070d8,0);
    DAT_1400070d0 = '\x01';
  }
  *(code **)(param_1 + 0x148) = KsDefaultDispatchPnp_exref;
  *(code **)(param_1 + 0x120) = KsDefaultDispatchPower_exref;
  *(code **)(param_1 + 0x128) = KsDefaultForwardIrp_exref;
  *(code **)(param_1 + 0x100) = FsDispatchCleanUp;
  *(code **)(*(longlong *)(param_1 + 0x30) + 8) = PnpAddDevice;
  *(code **)(param_1 + 0x68) = FsDriverUnload;
  KsSetMajorFunctionHandler(param_1,0);
  KsSetMajorFunctionHandler(param_1,2);
  KsSetMajorFunctionHandler(param_1,0xe);
  return 0;
}



===== wil_InitializeFeatureStaging @ 14001016c =====

int wil_InitializeFeatureStaging(void)

{
  bool bVar1;
  int iVar2;
  undefined **ppuVar3;
  undefined8 local_res8;
  
  bVar1 = false;
  if (g_wil_details_isFeatureStagingInitialized == 0) {
    g_wil_details_isFeatureStagingInitialized = 1;
    local_res8 = RtlQueryFeatureConfigurationChangeStamp();
    wil_details_PopulateInitialConfiguredFeatureStates();
    wil_details_EvaluateFeatureDependencies();
    for (ppuVar3 = &wil_details_featureDescriptors_a; ppuVar3 < &wil_details_featureDescriptors_z;
        ppuVar3 = ppuVar3 + 1) {
      if (*ppuVar3 != (undefined *)0x0) goto LAB_1400101f3;
    }
LAB_14001022d:
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
LAB_1400101f3:
  if (ppuVar3 == (undefined **)0x0) goto LAB_14001022d;
  if (((*(char *)((longlong)ppuVar3 + 0x1d) == '\0') &&
      (*(char *)((longlong)ppuVar3 + 0x1e) == '\0')) &&
     (*(char *)((longlong)ppuVar3 + 0x1c) == '\0')) {
    iVar2 = RtlRegisterFeatureConfigurationChangeNotification
                      (wil_details_ReevaluateOnFeatureConfigurationChange,0,&local_res8,
                       &g_wil_details_featureChangeNotification);
    if (iVar2 == 0) {
      bVar1 = true;
    }
    else {
      g_wil_details_featureChangeNotification = 0;
    }
    goto LAB_14001022d;
  }
  ppuVar3 = ppuVar3 + 7;
  while( true ) {
    if (&UNK_140006037 < ppuVar3) goto LAB_14001022d;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_1400101f3;
}



===== wil_details_PopulateInitialConfiguredFeatureStates @ 140010280 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_PopulateInitialConfiguredFeatureStates(void)

{
  ulonglong *puVar1;
  undefined8 *puVar2;
  int iVar3;
  undefined **ppuVar4;
  undefined1 auStack_48 [32];
  ulonglong local_28;
  undefined8 local_20;
  undefined4 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  ppuVar4 = &wil_details_featureDescriptors_a;
  while( true ) {
    if (&wil_details_featureDescriptors_z <= ppuVar4) {
      return;
    }
    if (*ppuVar4 != (undefined *)0x0) break;
    ppuVar4 = ppuVar4 + 1;
  }
  do {
    if (ppuVar4 == (undefined **)0x0) {
      return;
    }
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    if ((*(char *)((longlong)ppuVar4 + 0x1d) == '\0') &&
       (*(char *)((longlong)ppuVar4 + 0x1e) == '\0')) {
      iVar3 = RtlQueryFeatureConfiguration
                        (*(undefined4 *)(ppuVar4 + 3),
                         1 < (byte)(*(char *)((longlong)ppuVar4 + 0x1c) - 2U),&local_28,&local_20);
      if (iVar3 == -0x7fffffde) {
        do {
          puVar2 = (undefined8 *)*ppuVar4;
          ppuVar4 = ppuVar4 + 7;
          *puVar2 = 0x206;
          while( true ) {
            if (&UNK_140006037 < ppuVar4) {
              return;
            }
            if (*ppuVar4 != (undefined *)0x0) break;
            ppuVar4 = ppuVar4 + 1;
          }
        } while (ppuVar4 != (undefined **)0x0);
        return;
      }
      if (iVar3 == -0x3ffffddb) goto LAB_14001036a;
      if (iVar3 == 0) {
        local_28 = (ulonglong)(((local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0) << 3 | 0x206);
      }
      else {
        if (iVar3 != 0x117) goto LAB_14001036a;
        local_28 = (ulonglong)((local_20._4_4_ & 0x80) << 3 | 0x206);
      }
    }
    else {
LAB_14001036a:
      local_28 = 0x206;
    }
    puVar1 = (ulonglong *)*ppuVar4;
    ppuVar4 = ppuVar4 + 7;
    *puVar1 = local_28;
    while( true ) {
      if (&UNK_140006037 < ppuVar4) {
        return;
      }
      if (*ppuVar4 != (undefined *)0x0) break;
      ppuVar4 = ppuVar4 + 1;
    }
  } while( true );
}


