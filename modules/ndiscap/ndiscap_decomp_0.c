
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



===== memcpy_s @ 140001020 =====

errno_t __cdecl memcpy_s(void *_Dst,rsize_t _DstSize,void *_Src,rsize_t _MaxCount)

{
  errno_t eVar1;
  
  if (_MaxCount == 0) {
LAB_14000103d:
    eVar1 = 0;
  }
  else {
    if (_Dst == (void *)0x0) {
LAB_14000107f:
      eVar1 = 0x16;
    }
    else {
      if ((_Src != (void *)0x0) && (_MaxCount <= _DstSize)) {
        memmove(_Dst,_Src,_MaxCount);
        goto LAB_14000103d;
      }
      memset(_Dst,0,_DstSize);
      if (_Src == (void *)0x0) goto LAB_14000107f;
      if (_MaxCount <= _DstSize) {
        return 0x16;
      }
      eVar1 = 0x22;
    }
    _guard_check_icall();
  }
  return eVar1;
}



===== _guard_check_icall @ 1400010c0 =====

void _guard_check_icall(void)

{
  return;
}



===== __cpu_features_init @ 1400010e0 =====

/* WARNING: Removing unreachable block (ram,0x00014000114a) */
/* WARNING: Removing unreachable block (ram,0x0001400010f9) */
/* WARNING: Removing unreachable block (ram,0x0001400010ea) */

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



===== AddPort @ 1400011a8 =====

void AddPort(longlong param_1,longlong param_2,undefined8 *param_3)

{
  short sVar1;
  int iVar2;
  uint *puVar3;
  short *psVar4;
  short *psVar5;
  longlong lVar6;
  longlong lVar7;
  longlong lVar8;
  
  if (param_2 == 0) {
    return;
  }
  if (param_1 == 0) {
    return;
  }
  if (param_3 == (undefined8 *)0x0) {
    return;
  }
  if (0xffff < *(uint *)(param_2 + 0x410)) {
    return;
  }
  if (3 < *(uint *)(param_2 + 0x418)) {
    return;
  }
  puVar3 = (uint *)NdisAllocateMemoryWithTagPriority
                             (*(undefined8 *)(param_1 + 0x18),0x20,0x746c6946,0);
  if (puVar3 == (uint *)0x0) {
    return;
  }
  puVar3[0] = 0;
  puVar3[1] = 0;
  puVar3[2] = 0;
  puVar3[3] = 0;
  puVar3[4] = 0;
  puVar3[5] = 0;
  puVar3[6] = 0;
  puVar3[7] = 0;
  iVar2 = *(int *)(param_2 + 0x418);
  if (iVar2 - 1U < 2) {
    psVar4 = (short *)NdisAllocateMemoryWithTagPriority
                                (*(undefined8 *)(param_1 + 0x18),
                                 (uint)*(ushort *)(param_2 + 0x624) * 2 + 2,0x746c6946,0);
    *(short **)(puVar3 + 2) = psVar4;
    if (psVar4 == (short *)0x0) goto LAB_1400013da;
    lVar6 = (ulonglong)*(ushort *)(param_2 + 0x624) + 1;
    lVar7 = 0x7ffffffe - lVar6;
    lVar8 = param_2 - (longlong)psVar4;
    do {
      if ((lVar7 + lVar6 == 0) || (sVar1 = *(short *)(lVar8 + 0x626 + (longlong)psVar4), sVar1 == 0)
         ) break;
      *psVar4 = sVar1;
      psVar4 = psVar4 + 1;
      lVar6 = lVar6 + -1;
    } while (lVar6 != 0);
LAB_140001346:
    psVar5 = psVar4 + -1;
    if (lVar6 != 0) {
      psVar5 = psVar4;
    }
    *psVar5 = 0;
  }
  else if ((iVar2 == 0) || (iVar2 == 3)) {
    psVar4 = (short *)NdisAllocateMemoryWithTagPriority
                                (*(undefined8 *)(param_1 + 0x18),
                                 (uint)*(ushort *)(param_1 + 0xf8) * 2 + 2,0x746c6946,0);
    *(short **)(puVar3 + 2) = psVar4;
    if (psVar4 == (short *)0x0) goto LAB_1400013da;
    lVar6 = (ulonglong)*(ushort *)(param_1 + 0xf8) + 1;
    lVar8 = 0x7ffffffe - lVar6;
    lVar7 = *(longlong *)(param_1 + 0x100) - (longlong)psVar4;
    do {
      if ((lVar8 + lVar6 == 0) || (sVar1 = *(short *)(lVar7 + (longlong)psVar4), sVar1 == 0)) break;
      *psVar4 = sVar1;
      psVar4 = psVar4 + 1;
      lVar6 = lVar6 + -1;
    } while (lVar6 != 0);
    goto LAB_140001346;
  }
  psVar4 = (short *)NdisAllocateMemoryWithTagPriority
                              (*(undefined8 *)(param_1 + 0x18),
                               (uint)*(ushort *)(param_2 + 8) * 2 + 2,0x746c6946,0);
  *(short **)(puVar3 + 4) = psVar4;
  if (psVar4 != (short *)0x0) {
    lVar6 = (ulonglong)*(ushort *)(param_2 + 8) + 1;
    lVar8 = 0x7ffffffe - lVar6;
    lVar7 = param_2 - (longlong)psVar4;
    do {
      if ((lVar8 + lVar6 == 0) || (sVar1 = *(short *)(lVar7 + 10 + (longlong)psVar4), sVar1 == 0))
      break;
      *psVar4 = sVar1;
      psVar4 = psVar4 + 1;
      lVar6 = lVar6 + -1;
    } while (lVar6 != 0);
    *param_3 = puVar3;
    psVar5 = psVar4 + -1;
    if (lVar6 != 0) {
      psVar5 = psVar4;
    }
    *psVar5 = 0;
    puVar3[1] = *(uint *)(param_2 + 0x418);
    *puVar3 = (uint)*(ushort *)(param_2 + 0x414);
    return;
  }
LAB_1400013da:
  DeleteSwitchNicIndexInfo((longlong)puVar3,'\x01');
  return;
}



===== CheckFilterPosition @ 140001404 =====

int CheckFilterPosition(longlong param_1)

{
  undefined4 uVar1;
  int iVar2;
  longlong lVar3;
  ulonglong uVar4;
  longlong lVar5;
  longlong lVar6;
  ushort uVar7;
  ulonglong uVar8;
  undefined4 local_res8 [2];
  undefined4 local_res10 [2];
  
  local_res8[0] = 0;
  local_res10[0] = 0;
  NdisEnumerateFilterModules(*(undefined8 *)(param_1 + 0x18),0,0,local_res8,local_res10);
  uVar1 = local_res8[0];
  lVar3 = ExAllocatePoolWithTag(0x200,local_res8[0],0x746c6946);
  if (lVar3 == 0) {
    iVar2 = -0x3fffff66;
  }
  else {
    iVar2 = NdisEnumerateFilterModules
                      (*(undefined8 *)(param_1 + 0x18),lVar3,uVar1,local_res8,local_res10);
    if (iVar2 == 0) {
      uVar7 = 0;
      lVar5 = (ulonglong)*(uint *)(lVar3 + 0xc) + lVar3;
      uVar8 = (ulonglong)*(ushort *)(param_1 + 0x20) - 8;
      *(undefined1 *)(param_1 + 0x124) = 0;
      if (*(int *)(lVar3 + 8) != 0) {
        do {
          lVar6 = (ulonglong)uVar7 * 0x40;
          if ((uVar8 <= *(ushort *)(lVar6 + 0x30 + lVar5)) &&
             (uVar4 = RtlCompareMemory(*(undefined8 *)(lVar6 + 0x38 + lVar5),
                                       *(undefined8 *)(param_1 + 0x28),uVar8), uVar4 == uVar8)) {
            if (*(int *)(lVar6 + 0x10 + lVar5) == *(int *)(param_1 + 0x58)) {
              *(undefined1 *)(param_1 + 0x124) = 1;
            }
            break;
          }
          uVar7 = uVar7 + 1;
        } while ((uint)uVar7 < *(uint *)(lVar3 + 8));
      }
      iVar2 = 0;
    }
    ExFreePoolWithTag(lVar3,0);
  }
  return iVar2;
}



===== CheckForSwitchDestinations @ 140001548 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

bool CheckForSwitchDestinations(longlong param_1,longlong param_2,longlong *param_3)

{
  bool bVar1;
  longlong local_res8 [4];
  
  local_res8[0] = 0;
  bVar1 = false;
  if ((param_1 != 0) && (param_2 != 0)) {
    (**(code **)(*(longlong *)(param_1 + 0xe8) + 0x30))
              (**(undefined8 **)(param_1 + 0xe0),param_2,local_res8);
    bVar1 = *(int *)(local_res8[0] + 0xc) != 0;
    if (param_3 != (longlong *)0x0) {
      *param_3 = local_res8[0];
    }
  }
  return bVar1;
}



===== DeleteSwitchNicIndexInfo @ 1400015a4 =====

void DeleteSwitchNicIndexInfo(longlong param_1,char param_2)

{
  longlong lVar1;
  
  if (param_1 != 0) {
    lVar1 = 0;
    do {
      if (param_2 != '\0') {
        lVar1 = *(longlong *)(param_1 + 0x18);
      }
      if (*(longlong *)(param_1 + 8) != 0) {
        NdisFreeMemory(*(longlong *)(param_1 + 8),0,0);
      }
      if (*(longlong *)(param_1 + 0x10) != 0) {
        NdisFreeMemory();
      }
      *(undefined8 *)(param_1 + 0x18) = 0;
      NdisFreeMemory(param_1);
      param_1 = lVar1;
    } while (lVar1 != 0);
  }
  return;
}



===== EtwEx_tidPacketFragmentNetBuffer @ 14000163c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void EtwEx_tidPacketFragmentNetBuffer
               (undefined8 param_1,undefined8 *param_2,ulonglong param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6,uint param_7,longlong param_8,
               undefined1 param_9,undefined1 param_10)

{
  longlong lVar1;
  ulonglong uVar2;
  undefined1 auStackY_2d8 [32];
  uint local_2a8;
  uint local_2a4;
  undefined8 local_2a0;
  ulonglong uStack_298;
  undefined1 *local_288;
  undefined8 local_280;
  undefined1 *local_278;
  undefined4 local_270;
  undefined4 local_26c;
  uint *local_268;
  undefined4 local_260;
  undefined4 local_25c;
  undefined1 local_258 [560];
  ulonglong local_28;
  
  lVar1 = param_8;
  local_28 = __security_cookie ^ (ulonglong)auStackY_2d8;
  local_2a0 = *param_2;
  uStack_298 = param_2[1] | param_3;
  local_2a8 = 0;
  local_280._4_4_ = 0;
  local_26c = 0;
  local_288 = &param_5;
  local_278 = &param_6;
  local_280._0_4_ = 4;
  local_270 = 4;
  local_2a4 = 0x20;
  NetBufferFragmentCombine(param_8,param_7,&local_2a8,(longlong)local_258,&local_2a4);
  local_268 = &local_2a8;
  local_25c = 0;
  local_260 = 4;
  if (local_2a8 < *(uint *)(lVar1 + 0x18)) {
    uStack_298 = uStack_298 | 0x2000000;
  }
  uVar2 = (ulonglong)(local_2a4 + 3);
  *(undefined4 *)((longlong)&local_280 + (uVar2 * 4 + 1) * 4) = 0;
  (&local_280)[uVar2 * 2 + -1] = &param_9;
  *(undefined4 *)(&local_280 + uVar2 * 2) = 8;
  uVar2 = (ulonglong)(local_2a4 + 4);
  *(undefined4 *)((longlong)&local_280 + (uVar2 * 4 + 1) * 4) = 0;
  (&local_280)[uVar2 * 2 + -1] = &param_10;
  *(undefined4 *)(&local_280 + uVar2 * 2) = 8;
  EtwWrite(param_1,&local_2a0,param_4,local_2a4 + 5);
  return;
}



===== EtwEx_tidPacketMetadata @ 1400017a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void EtwEx_tidPacketMetadata
               (undefined8 param_1,undefined4 *param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6,uint param_7,undefined8 param_8,
               undefined8 param_9)

{
  undefined1 auStack_a8 [32];
  undefined1 **local_88;
  undefined4 local_78 [2];
  undefined4 local_70;
  undefined4 uStack_6c;
  ulonglong uStack_68;
  undefined1 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined4 *local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_a8;
  local_70 = *param_2;
  uStack_6c = param_2[1];
  local_78[0] = 0x30;
  local_20 = 0x30;
  uStack_68 = *(ulonglong *)(param_2 + 2) | 0x200000000 | 1L << ((ulonglong)param_7 & 0x3f);
  local_50 = 4;
  local_58 = &param_5;
  local_40 = 4;
  local_48 = &param_6;
  local_30 = 4;
  local_38 = local_78;
  local_28 = param_9;
  local_88 = &local_58;
  EtwWrite(param_1,&local_70,param_4);
  return;
}



===== EtwEx_tidVMSwitchNetBuffer @ 140001860 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void EtwEx_tidVMSwitchNetBuffer
               (undefined8 param_1,undefined4 *param_2,ulonglong param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6,undefined8 *param_7,uint param_8,
               longlong param_9,undefined8 param_10,undefined1 *param_11)

{
  undefined8 *puVar1;
  longlong lVar2;
  size_t sVar3;
  ulonglong uVar4;
  undefined1 auStackY_358 [32];
  uint local_328;
  uint local_324;
  undefined8 local_320;
  undefined4 local_318;
  undefined4 uStack_314;
  ulonglong uStack_310;
  undefined1 *local_308;
  undefined8 local_300;
  undefined4 uStack_2fc;
  undefined1 *local_2f8;
  undefined8 local_2f0;
  undefined8 *local_2e8;
  undefined8 local_2e0;
  wchar_t *local_2d8;
  ulonglong local_2d0;
  wchar_t *local_2c8;
  ulonglong local_2c0;
  wchar_t *local_2b8;
  ulonglong local_2b0;
  undefined8 *local_2a8;
  undefined8 local_2a0;
  undefined8 local_298;
  undefined4 local_290;
  undefined4 local_28c;
  uint *local_288;
  undefined8 local_280;
  undefined1 local_278 [560];
  ulonglong local_48;
  
  lVar2 = param_9;
  puVar1 = param_7;
  local_48 = __security_cookie ^ (ulonglong)auStackY_358;
  local_318 = *param_2;
  uStack_314 = param_2[1];
  uStack_310 = *(ulonglong *)(param_2 + 2) | param_3;
  local_308 = &param_5;
  local_2f8 = &param_6;
  local_2e8 = param_7 + 1;
  local_320._0_4_ = 0xd8;
  local_328 = 0;
  local_300 = 4;
  local_2f0 = 4;
  local_2e0 = 4;
  if ((wchar_t *)*param_7 == (wchar_t *)0x0) {
    local_2d8 = L"NULL";
    local_2d0 = 10;
  }
  else {
    sVar3 = wcsnlen((wchar_t *)*param_7,0x104);
    local_2d8 = (wchar_t *)*puVar1;
    local_2d0 = (ulonglong)((int)sVar3 * 2 + 2);
  }
  if ((wchar_t *)puVar1[2] == (wchar_t *)0x0) {
    local_2c8 = L"NULL";
    local_2c0 = 10;
  }
  else {
    sVar3 = wcsnlen((wchar_t *)puVar1[2],0x104);
    local_2c8 = (wchar_t *)puVar1[2];
    local_2c0 = (ulonglong)((int)sVar3 * 2 + 2);
  }
  if ((wchar_t *)puVar1[3] == (wchar_t *)0x0) {
    local_2b8 = L"NULL";
    local_2b0 = 10;
  }
  else {
    sVar3 = wcsnlen((wchar_t *)puVar1[3],0x104);
    local_2b8 = (wchar_t *)puVar1[3];
    local_2b0 = (ulonglong)((int)sVar3 * 2 + 2);
  }
  local_2a8 = puVar1 + 4;
  local_298 = puVar1[6];
  local_290 = *(undefined4 *)(puVar1 + 5);
  local_2a0 = 4;
  local_28c = 0;
  local_324 = 0x20;
  NetBufferFragmentCombine(lVar2,param_8,&local_328,(longlong)local_278,&local_324);
  local_288 = &local_328;
  local_280 = 4;
  if (local_328 < *(uint *)(lVar2 + 0x18)) {
    uStack_310 = uStack_310 | 0x2000000;
  }
  uVar4 = (ulonglong)(local_324 + 10);
  (&local_308)[(ulonglong)(local_324 + 9) * 2] = (undefined1 *)&local_320;
  (&local_320)[(ulonglong)(local_324 + 9) * 2 + 4] = 4;
  (&local_308)[uVar4 * 2] = param_11;
  *(undefined4 *)(&local_320 + uVar4 * 2 + 4) = (undefined4)local_320;
  (&uStack_2fc)[uVar4 * 4] = 0;
  EtwWrite(param_1,&local_318,param_4,local_324 + 0xb);
  return;
}



===== Feature_969905467__private_IsEnabledDeviceUsageNoInline @ 140001abc =====

ulonglong Feature_969905467__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  undefined4 *local_res8;
  
  local_res8 = (undefined4 *)(ulonglong)Feature_969905467__private_featureState;
  if ((Feature_969905467__private_featureState & 0x10) == 0) {
    uVar1 = Feature_969905467__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_969905467__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_969905467__private_IsEnabledFallback @ 140001af4 =====

void Feature_969905467__private_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2);
  return;
}



===== FilterAttach @ 140001b10 =====

int FilterAttach(undefined8 *param_1,longlong param_2,undefined8 *param_3)

{
  ushort uVar1;
  undefined4 uVar2;
  longlong lVar3;
  undefined8 uVar4;
  code *pcVar5;
  ulonglong uVar6;
  bool bVar7;
  undefined4 uVar8;
  bool bVar9;
  int iVar10;
  undefined8 *_Dst;
  undefined8 *puVar11;
  ulonglong uVar12;
  undefined8 *puVar13;
  undefined4 uVar14;
  undefined8 *puVar15;
  undefined1 *puVar16;
  uint uVar17;
  undefined8 *puVar18;
  ulonglong uVar19;
  ulonglong uVar20;
  ulonglong uVar21;
  char local_res10 [8];
  char local_res18;
  undefined4 local_res20 [2];
  undefined8 uStackY_90;
  undefined1 auStackY_88 [8];
  undefined1 auStackY_80 [24];
  undefined8 local_40;
  
  uVar2 = *(undefined4 *)(param_3 + 0x12);
  local_40 = 0;
  local_res10[0] = '\0';
  _Dst = (undefined8 *)0x0;
  uVar14 = 0;
  puVar15 = param_1;
  puVar18 = param_3;
  if ((Microsoft_Windows_NDIS_PacketCaptureEnableBits & 0x40) != 0) {
    McTemplateK0uuqq_EtwWriteTransfer(param_1,&StartLayerLoad,param_3,1,0x15,0x78,(char)uVar2);
  }
  if ((Microsoft_Windows_NDIS_PacketCaptureEnableBits & 0x10) != 0) {
    McTemplateK0qqqq_EtwWriteTransfer
              (puVar15,&LayerLoad,puVar18,*(undefined4 *)(param_3 + 3),
               (char)*(undefined4 *)(param_3 + 0x12),(char)*(undefined4 *)(param_3 + 9),(char)uVar2)
    ;
  }
  puVar16 = auStackY_88;
  if (param_2 == FilterDriverObject) {
    local_res18 = g_CaptureType != 0;
    puVar18 = (undefined8 *)0x746c6946;
    uVar14 = 2;
    if (g_CaptureType != 1) {
      uVar14 = 0;
    }
    puVar15 = param_1;
    _Dst = (undefined8 *)NdisAllocateMemoryWithTagPriority();
    puVar16 = auStackY_88;
    if (_Dst == (undefined8 *)0x0) {
      iVar10 = -0x3fffff66;
      uVar14 = 0x6a1;
    }
    else {
      memset(_Dst,0,0x128);
      uVar1 = *(ushort *)param_3[2];
      *(ushort *)((longlong)_Dst + 0x22) = uVar1;
      *(ushort *)(_Dst + 4) = uVar1;
      _Dst[5] = _Dst + 0x25;
      memmove(_Dst + 0x25,*(void **)(param_3[2] + 8),(ulonglong)uVar1);
      uVar1 = *(ushort *)param_3[4];
      *(ushort *)((longlong)_Dst + 0x32) = uVar1;
      *(ushort *)(_Dst + 6) = uVar1;
      _Dst[7] = (void *)((ulonglong)*(ushort *)(_Dst + 4) + _Dst[5]);
      memmove((void *)((ulonglong)*(ushort *)(_Dst + 4) + _Dst[5]),*(void **)(param_3[4] + 8),
              (ulonglong)uVar1);
      uVar1 = *(ushort *)param_3[5];
      *(ushort *)((longlong)_Dst + 0x42) = uVar1;
      *(ushort *)(_Dst + 8) = uVar1;
      _Dst[9] = (void *)((ulonglong)*(ushort *)(_Dst + 6) + _Dst[7]);
      memmove((void *)((ulonglong)*(ushort *)(_Dst + 6) + _Dst[7]),*(void **)(param_3[5] + 8),
              (ulonglong)uVar1);
      *(undefined4 *)((longlong)_Dst + 0x5c) = *(undefined4 *)(param_3 + 9);
      *(undefined4 *)(_Dst + 10) = *(undefined4 *)(param_3 + 3);
      *(undefined4 *)((longlong)_Dst + 0x54) = *(undefined4 *)(param_3 + 0x12);
      *(undefined4 *)(_Dst + 0xb) = *(undefined4 *)((longlong)param_3 + 4);
      if (((*(int *)(param_3 + 9) == 0x10) && (lVar3 = param_3[10], lVar3 != 0)) &&
         (*(uint *)(lVar3 + 0x14) < 0x41)) {
        puVar18 = (undefined8 *)0x746c6946;
        puVar15 = param_1;
        puVar11 = (undefined8 *)
                  NdisAllocateMemoryWithTagPriority
                            (param_1,*(uint *)(lVar3 + 0x14) * 4 + 8,0x746c6946,0);
        puVar16 = auStackY_88;
        _Dst[0x1a] = puVar11;
        if (puVar11 == (undefined8 *)0x0) {
          iVar10 = -0x3fffff66;
          uVar14 = 0x6df;
          goto LAB_140001f2b;
        }
        uVar12 = 0;
        *puVar11 = 0;
        *(undefined4 *)(puVar11 + 1) = 0;
        *(undefined4 *)_Dst[0x1a] = *(undefined4 *)(lVar3 + 0x14);
        *(undefined4 *)(_Dst[0x1a] + 4) = *(undefined4 *)(lVar3 + 0x14);
        if (*(int *)(lVar3 + 0x14) != 0) {
          do {
            *(undefined4 *)(_Dst[0x1a] + 8 + uVar12 * 4) =
                 *(undefined4 *)(uVar12 * 0x444 + 4 + *(longlong *)(lVar3 + 0x18));
            if (*(int *)(_Dst[0x1a] + 8 + uVar12 * 4) == 2) {
              *(undefined4 *)(_Dst[0x1a] + 8 + uVar12 * 4) = 5;
            }
            uVar17 = (int)uVar12 + 1;
            uVar12 = (ulonglong)uVar17;
          } while (uVar17 < *(uint *)(lVar3 + 0x14));
        }
      }
      _Dst[3] = param_1;
      local_res20[0] = 0;
      iVar10 = NdisEnumerateFilterModules(param_1,0,0,local_res20);
      uVar8 = local_res20[0];
      puVar16 = auStackY_88;
      if (iVar10 == -0x3ffeffea) {
        uVar12 = ExAllocatePoolWithTag(0x200,local_res20[0],0x746c6946);
        puVar16 = auStackY_88;
        if (uVar12 != 0) {
          iVar10 = NdisEnumerateFilterModules(_Dst[3],uVar12,uVar8,local_res20);
          puVar16 = auStackY_88;
          if (iVar10 == 0) {
            uVar20 = *(uint *)(uVar12 + 0xc) + uVar12;
            if (uVar20 < uVar12) {
              pcVar5 = (code *)swi(0x2c);
              (*pcVar5)();
              puVar16 = auStackY_80;
            }
            uVar21 = (ulonglong)*(uint *)(uVar12 + 8);
            bVar7 = false;
            uVar19 = 0;
            if (uVar21 != 0) {
              do {
                if (*(int *)(_Dst + 0xb) == *(int *)(uVar19 * 0x40 + 0x10 + uVar20)) {
                  uVar6 = uVar19;
                  bVar9 = true;
                  while (bVar7 = bVar9, uVar19 = uVar6 + 1, uVar19 < uVar21) {
                    uVar6 = uVar21;
                    bVar9 = false;
                    if (*(int *)(uVar19 * 0x40 + 8 + uVar20) != 2) {
                      uVar6 = uVar19;
                      bVar9 = bVar7;
                    }
                  }
                }
                uVar19 = uVar19 + 1;
              } while (uVar19 < uVar21);
            }
            *(undefined8 *)(puVar16 + -8) = 0x140001e9c;
            ExFreePoolWithTag(uVar12,0x746c6946);
            if (bVar7) {
              *(undefined4 *)((longlong)_Dst + 0x54) = *(undefined4 *)(_Dst + 10);
            }
          }
          else {
            ExFreePoolWithTag(uVar12,0x746c6946);
            puVar16 = auStackY_88;
          }
        }
      }
      local_40 = 0x8018d;
      puVar18 = &local_40;
      *(undefined8 *)(puVar16 + -8) = 0x140001ecb;
      puVar15 = param_1;
      iVar10 = NdisFSetAttributes(param_1,_Dst);
      if (iVar10 == 0) {
        *(undefined4 *)(_Dst + 0x13) = 3;
        *(undefined4 *)((longlong)_Dst + 0xdc) = 0;
        puVar18 = (undefined8 *)0x746c6946;
        _Dst[0x1c] = 0;
        _Dst[0x1d] = 0;
        *(undefined8 *)(puVar16 + -8) = 0x140001f0f;
        puVar15 = param_1;
        puVar11 = (undefined8 *)NdisAllocateMemoryWithTagPriority(param_1,8,0x746c6946,0);
        if (puVar11 != (undefined8 *)0x0) {
          *(undefined8 *)(puVar16 + -8) = 0x140001fe7;
          puVar13 = (undefined8 *)NdisAllocateMemoryWithTagPriority(param_1,0xf0,0x746c6946,0);
          if (puVar13 == (undefined8 *)0x0) {
            iVar10 = -0x3fffff66;
LAB_140001ffa:
            puVar18 = (undefined8 *)0x0;
            *(undefined8 *)(puVar16 + -8) = 0x140002009;
            NdisFreeMemory(puVar11,0);
            puVar15 = puVar11;
            if (puVar13 != (undefined8 *)0x0) {
              puVar18 = (undefined8 *)0x0;
              *(undefined8 *)(puVar16 + -8) = 0x140002022;
              NdisFreeMemory(puVar13,0);
              puVar15 = puVar13;
            }
            if (iVar10 == 0) goto LAB_140002033;
            if (iVar10 != -0x3fffff45) goto LAB_140001f25;
            *(undefined1 *)(_Dst + 0x1b) = 0;
            iVar10 = 0;
          }
          else {
            *(undefined4 *)puVar13 = 0x7001b8;
            *(undefined8 *)(puVar16 + -8) = 0x14000205f;
            puVar18 = puVar13;
            iVar10 = NdisFGetOptionalSwitchHandlers(param_1,puVar11);
            if (iVar10 != 0) goto LAB_140001ffa;
            _Dst[0x1c] = puVar11;
            _Dst[0x1d] = puVar13;
LAB_140002033:
            *(undefined1 *)(_Dst + 0x1b) = 1;
            if (local_res18 == '\0') {
              uVar14 = 2;
            }
            else {
              uVar4 = _Dst[3];
              *(undefined8 *)(puVar16 + -8) = 0x14000208d;
              FilterGetHostName(uVar4,(ushort *)(_Dst + 0x1f));
              *(undefined8 *)(puVar16 + -8) = 0x140002099;
              puVar15 = _Dst;
              iVar10 = FilterIsSwitchActive((longlong)_Dst,local_res10);
              if (iVar10 != 0) {
                uVar14 = 0x749;
                goto LAB_140001f2b;
              }
              if (local_res10[0] == '\0') {
                uVar14 = 1;
              }
              else {
                *(undefined8 *)(puVar16 + -8) = 0x1400020be;
                puVar15 = _Dst;
                iVar10 = FilterIssueSwitchNicArrayOidRequest((longlong)_Dst,_Dst + 0x1e);
                uVar14 = 0;
                if (iVar10 != 0) {
                  uVar14 = 0x753;
                  goto LAB_140001f2b;
                }
              }
            }
          }
          *(undefined4 *)((longlong)_Dst + 0xdc) = uVar14;
          *(undefined8 *)(puVar16 + -8) = 0x140002102;
          DAT_14000c728 = KeAcquireSpinLockRaiseToDpc(&FilterListLock);
          puVar11 = &FilterModuleList;
          if ((undefined8 **)FilterModuleList[1] != &FilterModuleList) {
            pcVar5 = (code *)swi(0x29);
            FilterModuleList = (undefined8 *)(*pcVar5)(3);
            puVar16 = puVar16 + 8;
          }
          *_Dst = FilterModuleList;
          puVar15 = (undefined8 *)&FilterListLock;
          _Dst[1] = puVar11;
          FilterModuleList[1] = _Dst;
          *(undefined8 *)(puVar16 + -8) = 0x14000214e;
          FilterModuleList = _Dst;
          KeReleaseSpinLock(&FilterListLock,DAT_14000c728);
          goto LAB_140001f8a;
        }
        iVar10 = -0x3fffff66;
LAB_140001f25:
        uVar14 = 0x776;
      }
      else {
        uVar14 = 0x71c;
      }
    }
  }
  else {
    iVar10 = -0x3ffffff3;
  }
LAB_140001f2b:
  if ((Microsoft_Windows_NDIS_PacketCaptureEnableBits & 0x20) != 0) {
    *(undefined4 *)(puVar16 + 0x28) = uVar2;
    *(undefined4 *)(puVar16 + 0x20) = uVar14;
    *(undefined8 *)(puVar16 + -8) = 0x140001f4d;
    McTemplateK0qqq_EtwWriteTransfer
              (puVar15,&LayerLoadError,puVar18,iVar10,puVar16[0x20],puVar16[0x28]);
  }
  if (_Dst != (undefined8 *)0x0) {
    lVar3 = _Dst[0x1a];
    if (lVar3 != 0) {
      *(undefined8 *)(puVar16 + -8) = 0x140001f6a;
      NdisFreeMemory(lVar3,0);
      _Dst[0x1a] = 0;
    }
    puVar18 = (undefined8 *)0x0;
    *(undefined8 *)(puVar16 + -8) = 0x140001f85;
    NdisFreeMemory(_Dst,0);
    puVar15 = _Dst;
  }
LAB_140001f8a:
  if ((Microsoft_Windows_NDIS_PacketCaptureEnableBits & 0x40) != 0) {
    *(undefined4 *)(puVar16 + 0x30) = uVar2;
    *(undefined4 *)(puVar16 + 0x28) = 0x795;
    puVar16[0x20] = 2;
    *(undefined8 *)(puVar16 + -8) = 0x140001fb4;
    McTemplateK0uuqq_EtwWriteTransfer
              (puVar15,&EndLayerLoad,puVar18,0x15,puVar16[0x20],puVar16[0x28],puVar16[0x30]);
  }
  return iVar10;
}



===== FilterDetach @ 140002160 =====

void FilterDetach(longlong *param_1,undefined8 param_2,undefined8 param_3)

{
  longlong *plVar1;
  longlong lVar2;
  code *pcVar3;
  longlong lVar4;
  longlong lVar5;
  undefined1 uVar6;
  
  if ((Microsoft_Windows_NDIS_PacketCaptureEnableBits & 0x10) != 0) {
    uVar6 = (undefined1)*(undefined4 *)((longlong)param_1 + 0x54);
    McTemplateK0qqqq_EtwWriteTransfer
              (param_1,&LayerUnload,param_3,(int)param_1[10],uVar6,
               (char)*(undefined4 *)((longlong)param_1 + 0x5c),uVar6);
  }
  if (param_1[0x19] != 0) {
    NdisFreeMemory(param_1[0x19],0,0);
  }
  DAT_14000c728 = KeAcquireSpinLockRaiseToDpc(&FilterListLock);
  lVar4 = *param_1;
  if ((*(longlong **)(lVar4 + 8) != param_1) ||
     (plVar1 = (longlong *)param_1[1], (longlong *)*plVar1 != param_1)) {
    pcVar3 = (code *)swi(0x29);
    (*pcVar3)(3);
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  *plVar1 = lVar4;
  *(longlong **)(lVar4 + 8) = plVar1;
  KeReleaseSpinLock(&FilterListLock,CONCAT71((int7)((ulonglong)lVar4 >> 8),DAT_14000c728));
  if (param_1[0x1a] != 0) {
    NdisFreeMemory(param_1[0x1a],0,0);
    param_1[0x1a] = 0;
  }
  if (param_1[0x1c] != 0) {
    NdisFreeMemory(param_1[0x1c],0,0);
    param_1[0x1c] = 0;
  }
  if (param_1[0x1d] != 0) {
    NdisFreeMemory(param_1[0x1d],0,0);
    param_1[0x1d] = 0;
  }
  if (param_1[0x20] != 0) {
    NdisFreeMemory(param_1[0x20],0,0);
    param_1[0x20] = 0;
    *(undefined2 *)(param_1 + 0x1f) = 0;
  }
  if (param_1[0x1e] != 0) {
    lVar5 = 0;
    lVar4 = 0x10000;
    do {
      lVar2 = *(longlong *)(lVar5 + 8 + param_1[0x1e]);
      if (lVar2 != 0) {
        DeleteSwitchNicIndexInfo(lVar2,'\x01');
      }
      lVar5 = lVar5 + 8;
      lVar4 = lVar4 + -1;
    } while (lVar4 != 0);
    NdisFreeMemory(param_1[0x1e],0,0);
    param_1[0x1e] = 0;
  }
  NdisFreeMemory(param_1,0,0);
  return;
}



===== FilterGetHostName @ 140002334 =====

int FilterGetHostName(undefined8 param_1,ushort *param_2)

{
  int iVar1;
  longlong lVar2;
  ulonglong uVar3;
  longlong lVar4;
  longlong local_res10;
  wchar_t *local_68 [4];
  undefined4 local_48;
  undefined4 local_44;
  undefined8 local_40;
  wchar_t **local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 local_28;
  undefined8 uStack_20;
  
  local_68[0] = 
  L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\ComputerName\\ActiveComputerName";
  local_68[1] = 
  L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\ComputerName\\ComputerName";
  local_res10 = 0;
  if (param_2 == (ushort *)0x0) {
    iVar1 = -0x3fffff10;
  }
  else {
    lVar4 = 0;
    do {
      local_44 = 0;
      local_68[2] = (wchar_t *)0x0;
      local_68[3] = (wchar_t *)0x0;
      local_2c = 0;
      RtlInitUnicodeString(local_68 + 2,local_68[lVar4]);
      local_38 = local_68 + 2;
      local_48 = 0x30;
      local_40 = 0;
      local_30 = 0x240;
      local_28 = 0;
      uStack_20 = 0;
      iVar1 = ZwOpenKey(&local_res10,0x20019,&local_48);
      if (iVar1 == 0) {
        uVar3 = 0x42;
        param_2[0] = 0;
        param_2[1] = 0;
        param_2[2] = 0;
        param_2[3] = 0;
        param_2[4] = 0;
        param_2[5] = 0;
        param_2[6] = 0;
        param_2[7] = 0;
        lVar2 = NdisAllocateMemoryWithTagPriority(param_1,0x42,0x746c6946,0);
        *(longlong *)(param_2 + 4) = lVar2;
        if (lVar2 == 0) {
LAB_1400024db:
          iVar1 = -0x3fffffe9;
          break;
        }
        *param_2 = 0x20;
        iVar1 = RegUtilQuerySTRINGValue(local_res10,uVar3,param_2);
        if (iVar1 == 0) break;
        if ((iVar1 == -0x3fffffdd) || (iVar1 == -0x7ffffffb)) {
          NdisFreeMemory(*(undefined8 *)(param_2 + 4),0,0);
          uVar3 = (ulonglong)((uint)*param_2 * 2 + 2);
          lVar2 = NdisAllocateMemoryWithTagPriority(param_1,uVar3,0x746c6946);
          *(longlong *)(param_2 + 4) = lVar2;
          if (lVar2 == 0) goto LAB_1400024db;
          iVar1 = RegUtilQuerySTRINGValue(local_res10,uVar3,param_2);
          if (iVar1 == 0) break;
        }
        if (local_res10 != 0) {
          ZwClose();
          local_res10 = 0;
        }
        NdisFreeMemory(*(undefined8 *)(param_2 + 4),0,0);
        param_2[4] = 0;
        param_2[5] = 0;
        param_2[6] = 0;
        param_2[7] = 0;
        *param_2 = 0;
      }
      lVar4 = lVar4 + 1;
    } while (lVar4 < 2);
    if (local_res10 != 0) {
      ZwClose();
      local_res10 = 0;
    }
    if ((iVar1 != 0) && (*(longlong *)(param_2 + 4) != 0)) {
      NdisFreeMemory(*(longlong *)(param_2 + 4),0,0);
      param_2[4] = 0;
      param_2[5] = 0;
      param_2[6] = 0;
      param_2[7] = 0;
      *param_2 = 0;
    }
  }
  return iVar1;
}



===== FilterGetSwitchEventInfo @ 140002544 =====

void FilterGetSwitchEventInfo
               (longlong param_1,longlong param_2,undefined8 *param_3,undefined1 *param_4,
               undefined1 *param_5)

{
  int iVar1;
  uint uVar2;
  undefined8 uVar3;
  longlong lVar4;
  bool bVar5;
  bool bVar6;
  longlong *plVar7;
  void *_Dst;
  uint *puVar8;
  longlong lVar9;
  undefined *puVar10;
  longlong lVar11;
  longlong lVar12;
  uint *puVar13;
  bool local_res8;
  uint local_44;
  longlong local_40;
  
  local_res8 = true;
  local_44 = 0;
  local_40 = 0;
  lVar12 = 0;
  lVar11 = 0;
  puVar10 = (undefined *)0x0;
  _Dst = (void *)0x0;
  if (param_3 == (undefined8 *)0x0) {
    return;
  }
  if (param_1 == 0) {
    return;
  }
  if (param_2 == 0) {
    return;
  }
  uVar3 = *(undefined8 *)(param_1 + 0x18);
  *param_3 = 0;
  *param_4 = 1;
  *param_5 = 1;
  plVar7 = (longlong *)NdisAllocateMemoryWithTagPriority(uVar3,0x38,0x746c6946,0);
  if (plVar7 == (longlong *)0x0) {
    return;
  }
  *plVar7 = 0;
  plVar7[1] = 0;
  plVar7[2] = 0;
  plVar7[3] = 0;
  plVar7[4] = 0;
  plVar7[5] = 0;
  plVar7[6] = 0;
  if (param_2 == -0x128) {
LAB_140002802:
    if (plVar7[6] != 0) {
      NdisFreeMemory(plVar7[6],0,0);
      plVar7[6] = 0;
    }
    NdisFreeMemory(plVar7,0,0);
  }
  else {
    *(uint *)(plVar7 + 1) = (uint)*(ushort *)(param_2 + 0x12a);
    if (*(longlong *)(param_1 + 0xf0) != 0) {
      for (puVar13 = *(uint **)(*(longlong *)(param_1 + 0xf0) + 8 +
                               (ulonglong)*(ushort *)(param_2 + 0x12a) * 8); puVar13 != (uint *)0x0;
          puVar13 = *(uint **)(puVar13 + 6)) {
        if (*puVar13 == (*(uint *)(param_2 + 300) & 0xff)) {
          lVar12 = *(longlong *)(puVar13 + 2);
          lVar11 = *(longlong *)(puVar13 + 4);
          puVar10 = (&g_NicTypes)[puVar13[1]];
          if (((lVar12 != 0) || (lVar11 != 0)) || (puVar10 != (undefined *)0x0)) {
            *plVar7 = lVar12;
            plVar7[2] = lVar11;
            plVar7[3] = (longlong)puVar10;
          }
          break;
        }
      }
    }
    bVar5 = AllowedByRuleEx2(0x1a,(uint *)(plVar7 + 1),4,(byte *)0x0);
    bVar6 = CheckForSwitchDestinations(param_1,param_2,&local_40);
    lVar4 = local_40;
    if (bVar6) {
      _Dst = (void *)NdisAllocateMemoryWithTagPriority
                               (*(undefined8 *)(param_1 + 0x18),*(int *)(local_40 + 0xc) << 5,
                                0x746c6946);
      if (_Dst == (void *)0x0) goto LAB_140002802;
      memset(_Dst,0,(ulonglong)*(uint *)(lVar4 + 0xc) << 5);
      iVar1 = *(int *)(lVar4 + 0xc);
      *(int *)(plVar7 + 4) = iVar1;
      puVar13 = *(uint **)(lVar4 + 0x10);
      uVar2 = 0;
      if (iVar1 != 0) {
        do {
          lVar9 = (ulonglong)local_44 * 0x20;
          *(uint *)(lVar9 + (longlong)_Dst) = *puVar13;
          if ((*(longlong *)(param_1 + 0xf0) == 0) ||
             (puVar8 = *(uint **)(*(longlong *)(param_1 + 0xf0) + 8 + (ulonglong)*puVar13 * 8),
             puVar8 == (uint *)0x0)) {
LAB_14000274d:
            if (((lVar12 != 0) || (lVar11 != 0)) || (puVar10 != (undefined *)0x0)) {
              *(longlong *)(lVar9 + 8 + (longlong)_Dst) = lVar12;
              *(longlong *)(lVar9 + 0x10 + (longlong)_Dst) = lVar11;
              *(undefined **)(lVar9 + 0x18 + (longlong)_Dst) = puVar10;
            }
          }
          else {
            do {
              if (*puVar8 == (uint)(ushort)puVar13[1]) {
                lVar12 = *(longlong *)(puVar8 + 2);
                lVar11 = *(longlong *)(puVar8 + 4);
                puVar10 = (&g_NicTypes)[puVar8[1]];
                goto LAB_14000274d;
              }
              puVar8 = *(uint **)(puVar8 + 6);
            } while (puVar8 != (uint *)0x0);
            lVar12 = 0;
            lVar11 = 0;
            puVar10 = (undefined *)0x0;
          }
          if (local_res8 != false) {
            local_res8 = AllowedByRuleEx2(0x1a,puVar13,4,(byte *)0x0);
          }
          local_44 = local_44 + 1;
          uVar2 = *(uint *)(plVar7 + 4);
          puVar13 = (uint *)((longlong)puVar13 + (ulonglong)*(uint *)(lVar4 + 4));
        } while (local_44 < uVar2);
      }
      GetSwitchDestinationsBuffer
                (*(undefined8 *)(param_1 + 0x18),_Dst,uVar2,(ulonglong *)(plVar7 + 5),plVar7 + 6);
    }
    else {
      plVar7[6] = 0;
      plVar7[5] = 0;
      *(undefined4 *)(plVar7 + 4) = 0;
    }
    *param_3 = plVar7;
    *param_4 = bVar5;
    *param_5 = local_res8;
  }
  if (_Dst != (void *)0x0) {
    NdisFreeMemory(_Dst,0,0);
  }
  return;
}



===== FilterIsSwitchActive @ 14000286c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FilterIsSwitchActive(longlong param_1,undefined1 *param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 auStackY_498 [32];
  undefined4 local_438;
  undefined1 local_434 [1040];
  undefined1 local_24;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_498;
  uVar2 = 0;
  memset(local_434,0,0x414);
  if ((param_1 == 0) || (param_2 == (undefined1 *)0x0)) {
    iVar1 = -0x3ffffff3;
  }
  else {
    local_438 = 0x4180180;
    iVar1 = filterDoInternalRequest(param_1,uVar2,0x10275,&local_438,0x418);
    if (iVar1 == 0) {
      *param_2 = local_24;
    }
  }
  return iVar1;
}



===== FilterIssueSwitchNicArrayOidRequest @ 14000291c =====

int FilterIssueSwitchNicArrayOidRequest(longlong param_1,undefined8 *param_2)

{
  int iVar1;
  undefined2 *_Dst;
  undefined8 uVar2;
  
  if (param_2 == (undefined8 *)0x0) {
    iVar1 = -0x3ffffff3;
  }
  else {
    *param_2 = 0;
    iVar1 = filterDoInternalRequest(param_1,param_2,0x10277,0,0);
    if (iVar1 == -0x3ffeffec) {
      _Dst = (undefined2 *)
             NdisAllocateMemoryWithTagPriority(*(undefined8 *)(param_1 + 0x18),0,0x746c6946,0);
      if (_Dst == (undefined2 *)0x0) {
        iVar1 = -0x3fffff66;
      }
      else {
        uVar2 = 0;
        memset(_Dst,0,0);
        *_Dst = 0x180;
        _Dst[1] = 0;
        iVar1 = filterDoInternalRequest(param_1,uVar2,0x10277,_Dst,0);
        if (iVar1 == 0) {
          GetSwitchNics(param_1,(longlong)_Dst,param_2);
        }
        NdisFreeMemory(_Dst,0,0);
      }
    }
  }
  return iVar1;
}



===== FilterNetPnPEvent @ 140002a30 =====

void FilterNetPnPEvent(longlong param_1,longlong param_2)

{
  int iVar1;
  
  if ((*(int *)(param_2 + 8) == 0x11) && (*(int *)(param_1 + 0xdc) == 1)) {
    iVar1 = FilterIssueSwitchNicArrayOidRequest(param_1,(undefined8 *)(param_1 + 0xf0));
    *(uint *)(param_1 + 0xdc) = -(uint)(iVar1 != 0) & 2;
  }
  NdisFNetPnPEvent(*(undefined8 *)(param_1 + 0x18),param_2);
  return;
}



===== FilterOidRequest @ 140002a90 =====

int FilterOidRequest(longlong param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  int iVar3;
  void *_Dst;
  int *piVar4;
  uint *puVar5;
  uint *puVar6;
  uint *local_res8;
  longlong local_res10;
  
  local_res10 = 0;
  iVar3 = *(int *)(param_2 + 0x20);
  if (((((iVar3 == 0x1027a) || (iVar3 == 0x1027d)) && (*(int *)(param_1 + 0xdc) == 0)) &&
      ((*(char *)(param_1 + 0xd8) != '\0' && (lVar2 = *(longlong *)(param_2 + 0x28), lVar2 != 0))))
     && ((iVar3 == 0x1027a || (iVar3 == 0x1027d)))) {
    if (*(longlong *)(param_1 + 0xf0) == 0) {
      _Dst = (void *)NdisAllocateMemoryWithTagPriority
                               (*(undefined8 *)(param_1 + 0x18),0x80008,0x746c6946,0);
      *(void **)(param_1 + 0xf0) = _Dst;
      if (_Dst == (void *)0x0) goto LAB_140002c4b;
      memset(_Dst,0,0x80008);
    }
    if (iVar3 == 0x1027a) {
      local_res8 = *(uint **)(*(longlong *)(param_1 + 0xf0) + 8 +
                             (ulonglong)*(uint *)(lVar2 + 0x410) * 8);
      puVar6 = (uint *)0x0;
      if (local_res8 != (uint *)0x0) {
        do {
          if (*local_res8 == (uint)*(ushort *)(lVar2 + 0x414)) goto LAB_140002c4b;
          puVar5 = *(uint **)(local_res8 + 6);
          puVar6 = local_res8;
          local_res8 = puVar5;
        } while (puVar5 != (uint *)0x0);
      }
      AddPort(param_1,lVar2,&local_res8);
      if (puVar6 == (uint *)0x0) {
        *(uint **)(*(longlong *)(param_1 + 0xf0) + 8 + (ulonglong)*(uint *)(lVar2 + 0x410) * 8) =
             local_res8;
      }
      else {
        *(uint **)(puVar6 + 6) = local_res8;
      }
    }
    else if (iVar3 == 0x1027d) {
      local_res8 = *(uint **)(*(longlong *)(param_1 + 0xf0) + 8 +
                             (ulonglong)*(uint *)(lVar2 + 0x410) * 8);
      if (local_res8 != (uint *)0x0) {
        puVar6 = local_res8;
        do {
          puVar5 = puVar6;
          puVar6 = puVar5;
          if (*puVar5 == (uint)*(ushort *)(lVar2 + 0x414)) break;
          puVar6 = *(uint **)(puVar5 + 6);
          local_res8 = puVar5;
        } while (puVar6 != (uint *)0x0);
        if (puVar6 != (uint *)0x0) {
          if (puVar6 == local_res8) {
            *(undefined8 *)
             (*(longlong *)(param_1 + 0xf0) + 8 + (ulonglong)*(uint *)(lVar2 + 0x410) * 8) =
                 *(undefined8 *)(puVar6 + 6);
          }
          else {
            *(undefined8 *)(local_res8 + 6) = *(undefined8 *)(puVar6 + 6);
          }
          DeleteSwitchNicIndexInfo((longlong)puVar6,'\0');
        }
      }
    }
  }
LAB_140002c4b:
  iVar3 = NdisAllocateCloneOidRequest
                    (*(undefined8 *)(param_1 + 0x18),param_2,0x646e5446,&local_res10);
  if (iVar3 == 0) {
    *(longlong *)(local_res10 + 0xd8) = param_2;
    *(undefined8 *)(local_res10 + 0x10) = *(undefined8 *)(param_2 + 0x10);
    *(longlong *)(param_1 + 0x118) = local_res10;
    *(longlong *)(param_1 + 0x110) = local_res10;
    iVar3 = NdisFOidRequest(*(undefined8 *)(param_1 + 0x18));
    if (iVar3 != 0x103) {
      piVar4 = &ExternalRequestFailedCount;
      if (iVar3 == 0) {
        piVar4 = &ExternalRequestSuccessCount;
      }
      LOCK();
      *piVar4 = *piVar4 + 1;
      UNLOCK();
      FilterOidRequestComplete(param_1,local_res10,iVar3);
      iVar3 = 0x103;
    }
  }
  else {
    iVar1 = *(int *)(param_2 + 4);
    if (((iVar1 == 0) || (iVar1 == 1)) || ((iVar1 == 2 || (iVar1 != 0xc)))) {
      *(undefined4 *)(param_2 + 0x34) = 0;
      *(undefined4 *)(param_2 + 0x38) = 0;
    }
    else {
      *(undefined4 *)(param_2 + 0x40) = 0;
      *(undefined4 *)(param_2 + 0x44) = 0;
      *(undefined4 *)(param_2 + 0x3c) = 0;
    }
  }
  return iVar3;
}



===== FilterOidRequestComplete @ 140002d30 =====

void FilterOidRequestComplete(longlong param_1,longlong param_2,int param_3)

{
  int iVar1;
  longlong lVar2;
  undefined1 uVar3;
  int *piVar4;
  
  lVar2 = *(longlong *)(param_2 + 0xd8);
  if (lVar2 == 0) {
    filterInternalRequestComplete(param_1,param_2,param_3);
  }
  else {
    *(undefined8 *)(param_1 + 0x110) = 0;
    uVar3 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x88);
    *(undefined8 *)(param_1 + 0x118) = 0;
    *(undefined1 *)(param_1 + 0x90) = uVar3;
    KeReleaseSpinLock(param_1 + 0x88,uVar3);
    *(longlong *)(param_1 + 0x108) = lVar2;
    piVar4 = &ExternalRequestFailedCount;
    if (param_3 == 0) {
      piVar4 = &ExternalRequestSuccessCount;
    }
    LOCK();
    *piVar4 = *piVar4 + 1;
    UNLOCK();
    iVar1 = *(int *)(param_2 + 4);
    if ((((iVar1 == 0) || (iVar1 == 1)) || (iVar1 == 2)) || (iVar1 != 0xc)) {
      *(undefined4 *)(lVar2 + 0x34) = *(undefined4 *)(param_2 + 0x34);
      *(undefined4 *)(lVar2 + 0x38) = *(undefined4 *)(param_2 + 0x38);
    }
    else {
      *(undefined4 *)(lVar2 + 0x34) = *(undefined4 *)(param_2 + 0x34);
      *(undefined4 *)(lVar2 + 0x40) = *(undefined4 *)(param_2 + 0x40);
      *(undefined4 *)(lVar2 + 0x44) = *(undefined4 *)(param_2 + 0x44);
      *(undefined4 *)(lVar2 + 0x3c) = *(undefined4 *)(param_2 + 0x3c);
    }
    *(undefined8 *)(param_2 + 0xd8) = 0;
    NdisFreeCloneOidRequest(*(undefined8 *)(param_1 + 0x18),param_2);
    NdisFOidRequestComplete(*(undefined8 *)(param_1 + 0x18),lVar2,param_3);
  }
  return;
}



===== FilterPause @ 140002e60 =====

undefined8 FilterPause(longlong param_1)

{
  undefined1 uVar1;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x88);
  *(undefined4 *)(param_1 + 0x98) = 2;
  *(undefined1 *)(param_1 + 0x90) = uVar1;
  KeReleaseSpinLock(param_1 + 0x88,uVar1);
  *(undefined4 *)(param_1 + 0x98) = 3;
  return 0;
}



===== FilterReceiveNetBufferLists @ 140002ed0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FilterReceiveNetBufferLists
               (longlong param_1,undefined8 *param_2,undefined4 param_3,undefined4 param_4,
               uint param_5)

{
  uint uVar1;
  uint *puVar2;
  char cVar3;
  bool bVar4;
  char cVar5;
  undefined1 uVar6;
  undefined8 *puVar7;
  ulonglong uVar8;
  uint uVar9;
  undefined8 *puVar10;
  undefined8 *puVar11;
  longlong *plVar12;
  undefined8 *puVar13;
  undefined1 auStackY_148 [32];
  undefined4 in_stack_fffffffffffffef0;
  undefined4 in_stack_fffffffffffffef4;
  char local_f8;
  char local_f7;
  char local_f6;
  uint local_f0 [2];
  undefined8 *local_e8;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined8 *local_d8;
  undefined8 *local_d0;
  undefined8 *local_c8;
  undefined8 *local_c0;
  undefined8 *local_b8;
  ulonglong local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  ulonglong local_68 [5];
  
  local_68[2] = __security_cookie ^ (ulonglong)auStackY_148;
  cVar5 = '\x01';
  puVar11 = (undefined8 *)0x0;
  local_d8 = (undefined8 *)0x0;
  local_d0 = (undefined8 *)0x0;
  local_68[0] = 0;
  local_68[1] = 0;
  local_e8 = (undefined8 *)0x0;
  local_f6 = '\x01';
  local_f8 = '\x01';
  local_f7 = '\x01';
  local_e0 = param_4;
  local_dc = param_3;
  local_b8 = param_2;
  if ((*(int *)(param_1 + 0xdc) != 0) ||
     (cVar3 = EtwProviderEnabled(MICROSOFT_PACKETCAPTURE_PROVIDER_Context,0,
                                 (-(ulonglong)(*(char *)(param_1 + 0xd8) != '\0') &
                                 0xfffffe0001000000) + 0x8000060200000000 |
                                 1L << ((longlong)*(int *)(param_1 + 0x5c) & 0x3fU)), cVar3 == '\0')
     ) goto LAB_140003393;
  local_f0[0] = *(uint *)(param_1 + 0x50);
  bVar4 = AllowedByRuleEx2(4,local_f0,4,(byte *)0x0);
  if (!bVar4) goto LAB_140003393;
  if (*(char *)(param_1 + 0xd8) == '\0') {
    if (*(int *)(param_1 + 0x50) != *(int *)(param_1 + 0x54)) {
      local_f0[0] = 0;
      bVar4 = AllowedByRuleEx2(3,local_f0,4,(byte *)0x0);
      if (bVar4) goto LAB_140003393;
    }
    if (*(char *)(param_1 + 0xd8) != '\0') goto LAB_140002fed;
  }
  else {
LAB_140002fed:
    if (*(char *)(param_1 + 0x124) == '\0') {
      local_f0[0] = 0;
      bVar4 = AllowedByRuleEx2(3,local_f0,4,(byte *)0x0);
      if (bVar4) goto LAB_140003393;
    }
  }
  if (param_2 == (undefined8 *)0x0) goto LAB_140003393;
  puVar7 = (undefined8 *)0x0;
  if ((*(char *)(param_1 + 0xd8) == '\0') || ((param_5 & 0xc000) != 0xc000)) {
LAB_14000307f:
    local_f0[0] = param_5 & 2;
    do {
      uStack_a0 = 0;
      local_a8 = param_2[0x1f] & 0x7fffffffffffffff;
      puVar10 = (undefined8 *)*param_2;
      local_68[1] = 0;
      puVar13 = (undefined8 *)param_2[1];
      local_c0 = puVar10;
      local_68[0] = local_a8;
      if ((cVar5 == '\0') || (*(char *)(param_1 + 0xd8) == '\0')) {
LAB_140003103:
        if (puVar13 != (undefined8 *)0x0) {
          do {
            local_c8 = (undefined8 *)*puVar13;
            uVar1 = *(uint *)(puVar13 + 3);
            uVar9 = *(uint *)(puVar13 + 5);
            for (plVar12 = (longlong *)puVar13[4];
                (plVar12 != (longlong *)0x0 && (*(uint *)(plVar12 + 5) <= uVar9));
                plVar12 = (longlong *)*plVar12) {
              uVar9 = uVar9 - *(uint *)(plVar12 + 5);
            }
            puVar13[1] = plVar12;
            *(uint *)(puVar13 + 2) = uVar9;
            cVar5 = EtwProviderEnabled(MICROSOFT_PACKETCAPTURE_PROVIDER_Context,0,0x200000000);
            if ((cVar5 != '\0') &&
               ((g_PacketInspectionRequired == '\0' ||
                (cVar5 = InspectPacketMdl(*(int *)(param_1 + 0x5c),plVar12,(ulonglong)uVar9,
                                          (ulonglong)uVar1), cVar5 != '\0')))) {
              if (*(int *)(param_1 + 0x5c) == 0x10) {
                puVar11 = (undefined8 *)param_2[0x18];
                local_98 = 0;
                uStack_90 = 0;
                local_88 = 0;
                uStack_80 = 0;
                local_78 = 0;
                uStack_70 = 0;
                if ((puVar11 != (undefined8 *)0x0) &&
                   (cVar5 = MmIsAddressValid(puVar11), cVar5 != '\0')) {
                  local_98 = *puVar11;
                  uStack_90 = puVar11[1];
                  uVar9 = 0;
                  local_88 = puVar11[2];
                  uStack_80 = puVar11[3];
                  local_78 = puVar11[4];
                  uStack_70 = puVar11[5];
                  uVar1 = *(uint *)(puVar11 + 1);
                  uVar6 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x88);
                  puVar2 = *(uint **)(param_1 + 0xd0);
                  *(undefined1 *)(param_1 + 0x90) = uVar6;
                  if ((puVar2 != (uint *)0x0) && (uVar1 < *puVar2)) {
                    uVar9 = puVar2[(ulonglong)uVar1 + 2];
                  }
                  KeReleaseSpinLock(param_1 + 0x88,CONCAT71((int7)((ulonglong)puVar2 >> 8),uVar6));
                  uVar8 = 1L << ((longlong)*(int *)(param_1 + 0x5c) & 0x3fU) | 0x8000040200000000;
                  uStack_90 = CONCAT44(uStack_90._4_4_,uVar9);
                  cVar5 = EtwProviderEnabled(MICROSOFT_PACKETCAPTURE_PROVIDER_Context,0);
                  if (cVar5 != '\0') {
                    EtwEx_tidPacketMetadata
                              (MICROSOFT_PACKETCAPTURE_PROVIDER_Context,
                               (undefined4 *)&PacketMetadata,uVar8,local_68,
                               (char)*(undefined4 *)(param_1 + 0x50),
                               (char)*(undefined4 *)(param_1 + 0x54),*(uint *)(param_1 + 0x5c),
                               CONCAT44(in_stack_fffffffffffffef4,in_stack_fffffffffffffef0),
                               &local_98);
                  }
                }
              }
              TraceNetBuffer((longlong)puVar13,local_68,(char)*(undefined4 *)(param_1 + 0x50),
                             (char)*(undefined4 *)(param_1 + 0x54),*(int *)(param_1 + 0x5c),puVar7,
                             (undefined1 *)(param_2 + 0x12),in_stack_fffffffffffffef0,1);
            }
            puVar13 = local_c8;
          } while (local_c8 != (undefined8 *)0x0);
          puVar10 = local_c0;
          puVar11 = local_d0;
          cVar5 = local_f6;
        }
      }
      else {
        FilterGetSwitchEventInfo(param_1,(longlong)param_2,&local_e8,&local_f8,&local_f7);
        puVar7 = local_e8;
        if ((local_f8 != '\0') || (local_f7 != '\0')) goto LAB_140003103;
      }
      if (local_f0[0] == 0) {
        if (local_d8 == (undefined8 *)0x0) {
          local_d8 = param_2;
        }
        else {
          *puVar11 = param_2;
        }
        *param_2 = 0;
        puVar11 = param_2;
        local_d0 = param_2;
      }
      if ((cVar5 != '\0') && (puVar7 != (undefined8 *)0x0)) {
        if (puVar7[6] != 0) {
          NdisFreeMemory(puVar7[6],0,0);
          puVar7[6] = 0;
        }
        NdisFreeMemory(puVar7);
        puVar7 = (undefined8 *)0x0;
        local_e8 = (undefined8 *)0x0;
      }
      param_2 = puVar10;
    } while (puVar10 != (undefined8 *)0x0);
    if (cVar5 != '\0') goto LAB_140003393;
  }
  else {
    cVar5 = '\0';
    local_f6 = '\0';
    FilterGetSwitchEventInfo(param_1,(longlong)param_2,&local_e8,&local_f8,&local_f7);
    puVar7 = local_e8;
    if ((local_f8 != '\0') || (local_f7 != '\0')) goto LAB_14000307f;
  }
  if (puVar7 != (undefined8 *)0x0) {
    if (puVar7[6] != 0) {
      NdisFreeMemory(puVar7[6],0,0);
      puVar7[6] = 0;
    }
    NdisFreeMemory(puVar7,0,0);
  }
LAB_140003393:
  NdisFIndicateReceiveNetBufferLists(*(undefined8 *)(param_1 + 0x18),local_b8,local_dc,local_e0);
  return;
}



===== FilterRegisterOptions @ 1400033e0 =====

uint FilterRegisterOptions(longlong param_1,longlong param_2)

{
  if (param_1 == FilterDriverHandle) {
    return -(uint)(param_2 != FilterDriverObject) & 0xc000000d;
  }
  return 0xc000000d;
}



===== FilterRestart @ 140003410 =====

undefined8 FilterRestart(longlong param_1,longlong param_2)

{
  int iVar1;
  undefined8 local_res8;
  undefined8 local_28;
  undefined8 local_20;
  undefined4 local_18;
  
  local_res8 = 0;
  local_28 = 0x1801a9;
  local_20 = FilterDriverHandle;
  local_18 = 0;
  iVar1 = NdisOpenConfigurationEx(&local_28,&local_res8);
  if (iVar1 == 0) {
    NdisCloseConfiguration(local_res8);
  }
  if (*(longlong *)(param_2 + 0x10) != 0) {
    *(undefined4 *)(*(longlong *)(param_2 + 0x10) + 0x28) = 0x80;
  }
  if (*(char *)(param_1 + 0xd8) != '\0') {
    CheckFilterPosition(param_1);
  }
  *(undefined4 *)(param_1 + 0x98) = 4;
  return 0;
}



===== FilterSendNetBufferLists @ 1400034b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FilterSendNetBufferLists(longlong param_1,undefined8 *param_2,undefined4 param_3,uint param_4)

{
  longlong *plVar1;
  char cVar2;
  bool bVar3;
  char cVar4;
  undefined8 *puVar5;
  longlong *plVar6;
  longlong *plVar7;
  uint uVar8;
  undefined8 *puVar9;
  undefined1 auStackY_f8 [32];
  undefined4 in_stack_ffffffffffffff40;
  char local_a8;
  char local_a7;
  char local_a6;
  ulonglong local_a0;
  undefined8 *local_98;
  uint local_90;
  undefined4 local_8c;
  undefined8 *local_88;
  undefined8 *local_80;
  ulonglong local_78;
  undefined8 uStack_70;
  ulonglong local_68;
  undefined8 uStack_60;
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStackY_f8;
  cVar4 = '\x01';
  puVar5 = (undefined8 *)0x0;
  local_98 = (undefined8 *)0x0;
  local_a6 = '\x01';
  local_68 = 0;
  uStack_60 = 0;
  local_a8 = '\x01';
  local_a7 = '\x01';
  local_90 = param_4;
  local_8c = param_3;
  local_80 = param_2;
  if ((*(int *)(param_1 + 0xdc) != 0) ||
     (cVar2 = EtwProviderEnabled(MICROSOFT_PACKETCAPTURE_PROVIDER_Context,0,
                                 (-(ulonglong)(*(char *)(param_1 + 0xd8) != '\0') &
                                 0xfffffe0001000000) + 0x8000060100000000 |
                                 1L << ((longlong)*(int *)(param_1 + 0x5c) & 0x3fU)), cVar2 == '\0')
     ) goto LAB_140003834;
  local_a0 = CONCAT44(local_a0._4_4_,*(undefined4 *)(param_1 + 0x50));
  bVar3 = AllowedByRuleEx2(4,(uint *)&local_a0,4,(byte *)0x0);
  if (!bVar3) goto LAB_140003834;
  if (*(char *)(param_1 + 0xd8) == '\0') {
    if (*(int *)(param_1 + 0x50) != *(int *)(param_1 + 0x54)) {
      local_a0 = local_a0 & 0xffffffff00000000;
      bVar3 = AllowedByRuleEx2(3,(uint *)&local_a0,4,(byte *)0x0);
      if (bVar3) goto LAB_140003834;
    }
    if (*(char *)(param_1 + 0xd8) != '\0') goto LAB_1400035be;
  }
  else {
LAB_1400035be:
    if (*(char *)(param_1 + 0x124) == '\0') {
      local_a0 = local_a0 & 0xffffffff00000000;
      bVar3 = AllowedByRuleEx2(3,(uint *)&local_a0,4,(byte *)0x0);
      if (bVar3) goto LAB_140003834;
    }
  }
  if (param_2 == (undefined8 *)0x0) goto LAB_140003834;
  if ((*(char *)(param_1 + 0xd8) == '\0') || ((param_4 & 0x20) == 0)) {
LAB_140003670:
    do {
      uStack_70 = 0;
      puVar9 = (undefined8 *)*param_2;
      local_78 = param_2[0x1f] & 0x7fffffffffffffff;
      plVar6 = (longlong *)param_2[1];
      local_88 = puVar9;
      local_68 = local_78;
      uStack_60 = uStack_70;
      if ((cVar4 == '\0') || (*(char *)(param_1 + 0xd8) == '\0')) {
LAB_1400036e9:
        if (plVar6 != (longlong *)0x0) {
          do {
            plVar7 = (longlong *)plVar6[4];
            plVar1 = (longlong *)*plVar6;
            uVar8 = *(uint *)(plVar6 + 5);
            local_a0 = CONCAT44(local_a0._4_4_,(int)plVar6[3]);
            if (plVar7 != (longlong *)0x0) {
              for (; *(uint *)(plVar7 + 5) <= uVar8; plVar7 = (longlong *)*plVar7) {
                uVar8 = uVar8 - *(uint *)(plVar7 + 5);
              }
            }
            plVar6[1] = (longlong)plVar7;
            *(uint *)(plVar6 + 2) = uVar8;
            cVar4 = EtwProviderEnabled(MICROSOFT_PACKETCAPTURE_PROVIDER_Context,0,0x100000000);
            if ((cVar4 != '\0') &&
               ((g_PacketInspectionRequired == '\0' ||
                (cVar4 = InspectPacketMdl(*(int *)(param_1 + 0x5c),plVar7,(ulonglong)uVar8,
                                          local_a0 & 0xffffffff), cVar4 != '\0')))) {
              TraceNetBuffer((longlong)plVar6,&local_68,(char)*(undefined4 *)(param_1 + 0x50),
                             (char)*(undefined4 *)(param_1 + 0x54),*(int *)(param_1 + 0x5c),puVar5,
                             (undefined1 *)(param_2 + 0x12),in_stack_ffffffffffffff40,0);
            }
            plVar6 = plVar1;
          } while (plVar1 != (longlong *)0x0);
          puVar9 = local_88;
          cVar4 = local_a6;
        }
        param_2 = puVar9;
        if (cVar4 != '\0') goto LAB_1400037b1;
      }
      else {
        FilterGetSwitchEventInfo(param_1,(longlong)param_2,&local_98,&local_a8,&local_a7);
        puVar5 = local_98;
        if ((local_a8 != '\0') || (local_a7 != '\0')) goto LAB_1400036e9;
LAB_1400037b1:
        param_2 = puVar9;
        if (puVar5 != (undefined8 *)0x0) {
          if (puVar5[6] != 0) {
            NdisFreeMemory(puVar5[6],0,0);
            puVar5[6] = 0;
          }
          NdisFreeMemory(puVar5);
          puVar5 = (undefined8 *)0x0;
          local_98 = (undefined8 *)0x0;
        }
      }
    } while (param_2 != (undefined8 *)0x0);
    if (cVar4 != '\0') goto LAB_140003834;
  }
  else {
    if ((param_4 & 0x10) == 0) {
      local_a0 = 0;
      (**(code **)(*(longlong *)(param_1 + 0xe8) + 0x30))
                (**(undefined8 **)(param_1 + 0xe0),param_2,&local_a0);
      if (*(int *)(local_a0 + 0xc) != 0) goto LAB_140003670;
    }
    local_a6 = '\0';
    cVar4 = '\0';
    FilterGetSwitchEventInfo(param_1,(longlong)param_2,&local_98,&local_a8,&local_a7);
    puVar5 = local_98;
    if ((local_a8 != '\0') || (local_a7 != '\0')) goto LAB_140003670;
  }
  if (puVar5 != (undefined8 *)0x0) {
    if (puVar5[6] != 0) {
      NdisFreeMemory(puVar5[6],0,0);
      puVar5[6] = 0;
    }
    NdisFreeMemory(puVar5,0,0);
  }
LAB_140003834:
  NdisFSendNetBufferLists(*(undefined8 *)(param_1 + 0x18),local_80,local_8c,local_90);
  return;
}



===== FilterSetModuleOptions @ 140003880 =====

undefined8 FilterSetModuleOptions(void)

{
  return 0;
}



===== FilterStatus @ 140003890 =====

void FilterStatus(longlong param_1)

{
  NdisFIndicateStatus(*(undefined8 *)(param_1 + 0x18));
  return;
}



===== FilterUnload @ 1400038b0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FilterUnload(undefined8 param_1)

{
  int iVar1;
  
  if ((Microsoft_Windows_NDIS_PacketCaptureEnableBits & 0x10) != 0) {
    McTemplateK0zzzz_EtwWriteTransfer(param_1,&DriverUnload);
  }
  McGenEventUnregister_EtwUnregister();
  iVar1 = 1;
  LOCK();
  if (fFilterRegistered == 1) {
    fFilterRegistered = 0;
  }
  else {
    iVar1 = fFilterRegistered;
  }
  UNLOCK();
  if (iVar1 != 0) {
    NdisFDeregisterFilterDriver(FilterDriverHandle);
  }
  PktCapProviderUninitialize();
  if (g_CoalescedBuffer != 0) {
    ExFreePoolWithTag(g_CoalescedBuffer,0);
    g_CoalescedBuffer = 0;
  }
  if (DAT_14000c748 != 0) {
    ExFreePoolWithTag(DAT_14000c748,0);
    DAT_14000c748 = 0;
  }
  _DriverRegistryPath = 0;
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



===== GetSwitchDestinationsBuffer @ 140003994 =====

void GetSwitchDestinationsBuffer
               (undefined8 param_1,void *param_2,uint param_3,ulonglong *param_4,undefined8 *param_5
               )

{
  short sVar1;
  short *psVar2;
  short *psVar3;
  short *psVar4;
  short *psVar5;
  longlong lVar6;
  ulonglong uVar7;
  short *psVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  undefined8 *puVar12;
  longlong lVar13;
  ulonglong uVar14;
  undefined8 *puVar15;
  ulonglong _Size;
  
  *param_4 = 0;
  uVar9 = (ulonglong)param_3;
  _Size = 0;
  *param_5 = 0;
  if (param_2 != (void *)0x0) {
    puVar15 = (undefined8 *)((longlong)param_2 + 0x10);
    if (param_3 != 0) {
      uVar7 = uVar9;
      puVar12 = puVar15;
      do {
        psVar2 = (short *)puVar12[-1];
        if (psVar2 == (short *)0x0) {
LAB_140003a1e:
          uVar14 = 0;
        }
        else {
          lVar6 = 0x7fffffff;
          do {
            if (*psVar2 == 0) break;
            psVar2 = psVar2 + 1;
            lVar6 = lVar6 + -1;
          } while (lVar6 != 0);
          uVar14 = -(ulonglong)(lVar6 != 0) & 0x7fffffffU - lVar6;
          if (lVar6 == 0) goto LAB_140003a1e;
        }
        psVar2 = (short *)*puVar12;
        if (psVar2 == (short *)0x0) {
LAB_140003a52:
          uVar11 = 0;
        }
        else {
          lVar6 = 0x7fffffff;
          do {
            if (*psVar2 == 0) break;
            psVar2 = psVar2 + 1;
            lVar6 = lVar6 + -1;
          } while (lVar6 != 0);
          uVar11 = -(ulonglong)(lVar6 != 0) & 0x7fffffffU - lVar6;
          if (lVar6 == 0) goto LAB_140003a52;
        }
        psVar2 = (short *)puVar12[1];
        if (psVar2 == (short *)0x0) {
LAB_140003a87:
          uVar10 = 0;
        }
        else {
          lVar6 = 0x7fffffff;
          do {
            if (*psVar2 == 0) break;
            psVar2 = psVar2 + 1;
            lVar6 = lVar6 + -1;
          } while (lVar6 != 0);
          uVar10 = -(ulonglong)(lVar6 != 0) & 0x7fffffffU - lVar6;
          if (lVar6 == 0) goto LAB_140003a87;
        }
        puVar12 = puVar12 + 4;
        _Size = _Size + (uVar10 + uVar11 + uVar14) * 2 + 10;
        uVar7 = uVar7 - 1;
      } while (uVar7 != 0);
    }
    psVar2 = (short *)NdisAllocateMemoryWithTagPriority(param_1,_Size & 0xffffffff,0x746c6946,0);
    if (psVar2 != (short *)0x0) {
      memset(psVar2,0,_Size);
      psVar8 = psVar2;
      uVar7 = _Size;
      if (param_3 != 0) {
        do {
          memcpy_s(psVar8,uVar7,param_2,4);
          psVar5 = (short *)puVar15[-1];
          psVar4 = psVar8 + 2;
          if (psVar5 == (short *)0x0) {
LAB_140003b4a:
            uVar14 = 0;
          }
          else {
            lVar6 = 0x7fffffff;
            psVar3 = psVar5;
            do {
              if (*psVar3 == 0) break;
              psVar3 = psVar3 + 1;
              lVar6 = lVar6 + -1;
            } while (lVar6 != 0);
            uVar14 = -(ulonglong)(lVar6 != 0) & 0x7fffffffU - lVar6;
            if (lVar6 == 0) goto LAB_140003b4a;
          }
          uVar11 = uVar7 - 4 >> 1;
          if (uVar11 != 0) {
            if (uVar11 < 0x80000000) {
              lVar13 = 0x7ffffffe - uVar11;
              lVar6 = (longlong)psVar5 - (longlong)psVar4;
              do {
                if ((lVar13 + uVar11 == 0) ||
                   (sVar1 = *(short *)(lVar6 + (longlong)psVar4), sVar1 == 0)) break;
                *psVar4 = sVar1;
                psVar4 = psVar4 + 1;
                uVar11 = uVar11 - 1;
              } while (uVar11 != 0);
              psVar5 = psVar4 + -1;
              if (uVar11 != 0) {
                psVar5 = psVar4;
              }
              *psVar5 = 0;
            }
            else {
              *psVar4 = 0;
            }
          }
          psVar5 = (short *)*puVar15;
          psVar8 = psVar8 + uVar14 + 3;
          uVar7 = (uVar7 - 4) + uVar14 * -2 + -2;
          if (psVar5 == (short *)0x0) {
LAB_140003bf2:
            uVar14 = 0;
          }
          else {
            lVar6 = 0x7fffffff;
            psVar4 = psVar5;
            do {
              if (*psVar4 == 0) break;
              psVar4 = psVar4 + 1;
              lVar6 = lVar6 + -1;
            } while (lVar6 != 0);
            uVar14 = -(ulonglong)(lVar6 != 0) & 0x7fffffffU - lVar6;
            if (lVar6 == 0) goto LAB_140003bf2;
          }
          uVar11 = uVar7 >> 1;
          if (uVar11 != 0) {
            if (uVar11 < 0x80000000) {
              lVar6 = 0x7ffffffe - uVar11;
              psVar4 = psVar8;
              do {
                if ((lVar6 + uVar11 == 0) ||
                   (sVar1 = *(short *)(((longlong)psVar5 - (longlong)psVar8) + (longlong)psVar4),
                   sVar1 == 0)) break;
                *psVar4 = sVar1;
                psVar4 = psVar4 + 1;
                uVar11 = uVar11 - 1;
              } while (uVar11 != 0);
              psVar5 = psVar4 + -1;
              if (uVar11 != 0) {
                psVar5 = psVar4;
              }
              *psVar5 = 0;
            }
            else {
              *psVar8 = 0;
            }
          }
          psVar5 = (short *)puVar15[1];
          psVar8 = psVar8 + uVar14 + 1;
          uVar7 = uVar7 + uVar14 * -2 + -2;
          if (psVar5 == (short *)0x0) {
LAB_140003c98:
            uVar14 = 0;
          }
          else {
            lVar6 = 0x7fffffff;
            psVar4 = psVar5;
            do {
              if (*psVar4 == 0) break;
              psVar4 = psVar4 + 1;
              lVar6 = lVar6 + -1;
            } while (lVar6 != 0);
            uVar14 = -(ulonglong)(lVar6 != 0) & 0x7fffffffU - lVar6;
            if (lVar6 == 0) goto LAB_140003c98;
          }
          uVar11 = uVar7 >> 1;
          if (uVar11 != 0) {
            if (uVar11 < 0x80000000) {
              lVar6 = 0x7ffffffe - uVar11;
              psVar4 = psVar8;
              do {
                if ((lVar6 + uVar11 == 0) ||
                   (sVar1 = *(short *)(((longlong)psVar5 - (longlong)psVar8) + (longlong)psVar4),
                   sVar1 == 0)) break;
                *psVar4 = sVar1;
                psVar4 = psVar4 + 1;
                uVar11 = uVar11 - 1;
              } while (uVar11 != 0);
              psVar5 = psVar4 + -1;
              if (uVar11 != 0) {
                psVar5 = psVar4;
              }
              *psVar5 = 0;
            }
            else {
              *psVar8 = 0;
            }
          }
          psVar8 = psVar8 + uVar14 + 1;
          uVar7 = uVar7 + uVar14 * -2 + -2;
          param_2 = (void *)((longlong)param_2 + 0x20);
          puVar15 = puVar15 + 4;
          uVar9 = uVar9 - 1;
        } while (uVar9 != 0);
      }
      *param_4 = _Size;
      *param_5 = psVar2;
    }
  }
  return;
}



===== GetSwitchNics @ 140003d48 =====

void GetSwitchNics(longlong param_1,longlong param_2,undefined8 *param_3)

{
  undefined4 *_Dst;
  uint uVar1;
  uint *puVar2;
  longlong lVar3;
  uint *local_res10;
  
  if ((((param_2 != 0) && (param_3 != (undefined8 *)0x0)) && (param_1 != 0)) &&
     (_Dst = (undefined4 *)
             NdisAllocateMemoryWithTagPriority(*(undefined8 *)(param_1 + 0x18),0x80008,0x746c6946,0)
     , _Dst != (undefined4 *)0x0)) {
    memset(_Dst,0,0x80008);
    uVar1 = 0;
    *_Dst = *(undefined4 *)(param_2 + 0xc);
    if (*(int *)(param_2 + 0xc) != 0) {
      do {
        lVar3 = (ulonglong)*(ushort *)(param_2 + 8) +
                (ulonglong)(uVar1 * *(int *)(param_2 + 0x10)) + param_2;
        puVar2 = *(uint **)(_Dst + (ulonglong)*(uint *)(lVar3 + 0x410) * 2 + 2);
        local_res10 = puVar2;
        if (puVar2 != (uint *)0x0) {
          do {
            puVar2 = local_res10;
            if (*puVar2 == (uint)*(ushort *)(lVar3 + 0x414)) goto LAB_140003e50;
            local_res10 = *(uint **)(puVar2 + 6);
          } while (local_res10 != (uint *)0x0);
        }
        if (local_res10 == (uint *)0x0) {
          AddPort(param_1,lVar3,&local_res10);
          if (puVar2 == (uint *)0x0) {
            *(uint **)(_Dst + (ulonglong)*(uint *)(lVar3 + 0x410) * 2 + 2) = local_res10;
          }
          else {
            *(uint **)(puVar2 + 6) = local_res10;
          }
        }
LAB_140003e50:
        uVar1 = uVar1 + 1;
      } while (uVar1 < *(uint *)(param_2 + 0xc));
    }
    *param_3 = _Dst;
  }
  return;
}



===== McGenControlCallbackV2 @ 140003e80 =====

void McGenControlCallbackV2
               (void *param_1,uint param_2,uint *param_3,undefined8 param_4,undefined8 param_5,
               longlong *param_6,longlong param_7)

{
  uint *puVar1;
  ulonglong uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  char cVar6;
  undefined7 uVar7;
  undefined8 in_stack_ffffffffffffffd8;
  
  cVar6 = (char)param_4;
  uVar7 = (undefined7)((ulonglong)param_4 >> 8);
  if (param_7 != 0) {
    if (param_2 == 0) {
      *(undefined4 *)(param_7 + 0x24) = 0;
      *(undefined1 *)(param_7 + 0x28) = 0;
      *(undefined8 *)(param_7 + 0x10) = 0;
      *(undefined8 *)(param_7 + 0x18) = 0;
      if (*(ushort *)(param_7 + 0x2a) != 0) {
        param_1 = *(void **)(param_7 + 0x30);
        iVar3 = *(ushort *)(param_7 + 0x2a) - 1;
        param_3 = (uint *)((longlong)(((int)(iVar3 + (iVar3 >> 0x1f & 0x1fU)) >> 5) + 1) << 2);
        memset(param_1,0,(size_t)param_3);
      }
    }
    else if (param_2 == 1) {
      *(char *)(param_7 + 0x28) = (char)param_3;
      param_3 = (uint *)0x0;
      *(undefined8 *)(param_7 + 0x18) = param_5;
      *(undefined8 *)(param_7 + 0x10) = param_4;
      *(undefined4 *)(param_7 + 0x24) = 1;
      if (*(short *)(param_7 + 0x2a) != 0) {
        do {
          uVar2 = *(ulonglong *)(*(longlong *)(param_7 + 0x38) + (longlong)param_3 * 8);
          if (((*(byte *)(param_7 + 0x28) <
                *(byte *)((longlong)param_3 + *(longlong *)(param_7 + 0x40))) &&
              (*(byte *)(param_7 + 0x28) != 0)) ||
             ((uVar2 != 0 &&
              (((*(ulonglong *)(param_7 + 0x10) & uVar2) == 0 ||
               ((*(ulonglong *)(param_7 + 0x18) & uVar2) != *(ulonglong *)(param_7 + 0x18))))))) {
            cVar6 = '\0';
          }
          else {
            cVar6 = '\x01';
          }
          uVar4 = 1 << ((byte)param_3 & 0x1f);
          param_1 = (void *)((ulonglong)param_3 >> 5);
          puVar1 = (uint *)(*(longlong *)(param_7 + 0x30) + (longlong)param_1 * 4);
          uVar5 = *puVar1;
          if (cVar6 == '\0') {
            uVar4 = ~uVar4 & uVar5;
          }
          else {
            uVar4 = uVar4 | uVar5;
          }
          *puVar1 = uVar4;
          uVar5 = (int)param_3 + 1;
          param_3 = (uint *)(ulonglong)uVar5;
        } while (uVar5 < *(ushort *)(param_7 + 0x2a));
      }
    }
    NdisCapEtwEnableCallback
              (param_1,(uint *)(ulonglong)param_2,param_3,CONCAT71(uVar7,cVar6),
               in_stack_ffffffffffffffd8,param_6);
  }
  return;
}



===== McGenEventRegister_EtwRegister @ 140003fb0 =====

void McGenEventRegister_EtwRegister(void)

{
  if (MICROSOFT_PACKETCAPTURE_PROVIDER_Context == 0) {
    EtwRegister(&MICROSOFT_PACKETCAPTURE_PROVIDER,McGenControlCallbackV2,
                &MICROSOFT_PACKETCAPTURE_PROVIDER_Context,&MICROSOFT_PACKETCAPTURE_PROVIDER_Context)
    ;
  }
  return;
}



===== McGenEventUnregister_EtwUnregister @ 140003ff0 =====

undefined8 McGenEventUnregister_EtwUnregister(void)

{
  undefined8 uVar1;
  
  if (MICROSOFT_PACKETCAPTURE_PROVIDER_Context == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = EtwUnregister();
    MICROSOFT_PACKETCAPTURE_PROVIDER_Context = 0;
  }
  return uVar1;
}



===== McGenEventWrite_EtwWriteTransfer @ 140004024 =====

void McGenEventWrite_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined8 *param_5)

{
  ushort *puVar1;
  undefined4 uVar2;
  uint uVar3;
  
  puVar1 = DAT_14000c008;
  uVar2 = 0;
  if (DAT_14000c008 == (ushort *)0x0) {
    *param_5 = 0;
    uVar3 = 0;
  }
  else {
    *param_5 = DAT_14000c008;
    uVar2 = 2;
    uVar3 = (uint)*puVar1;
  }
  *(uint *)(param_5 + 1) = uVar3;
  *(undefined4 *)((longlong)param_5 + 0xc) = uVar2;
  EtwWriteTransfer(MICROSOFT_PACKETCAPTURE_PROVIDER_Context,param_2,0,0,param_4,param_5);
  return;
}



===== McTemplateK0qqq_EtwWriteTransfer @ 140004088 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0qqq_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  undefined1 auStackY_88 [32];
  undefined8 local_58 [2];
  undefined4 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  local_48 = local_res20;
  local_38 = &param_5;
  local_28 = &param_6;
  local_40 = 4;
  local_30 = 4;
  local_20 = 4;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,param_3,4,local_58);
  return;
}



===== McTemplateK0qqqq_EtwWriteTransfer @ 1400040fc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0qqqq_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined4 local_res20 [2];
  undefined1 auStackY_98 [32];
  undefined8 local_68 [2];
  undefined4 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  local_58 = local_res20;
  local_50 = 4;
  local_48 = &param_5;
  local_40 = 4;
  local_38 = &param_6;
  local_28 = &param_7;
  local_30 = 4;
  local_20 = 4;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,param_3,5,local_68);
  return;
}



===== McTemplateK0uuqq_EtwWriteTransfer @ 14000418c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0uuqq_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined1 param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined1 local_res20 [8];
  undefined1 auStackY_98 [32];
  undefined8 local_68 [2];
  undefined1 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  local_58 = local_res20;
  local_50 = 1;
  local_48 = &param_5;
  local_40 = 1;
  local_38 = &param_6;
  local_28 = &param_7;
  local_30 = 4;
  local_20 = 4;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,param_3,5,local_68);
  return;
}



===== McTemplateK0zzzz_EtwWriteTransfer @ 14000421c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0zzzz_EtwWriteTransfer(undefined8 param_1,undefined8 param_2)

{
  longlong lVar1;
  undefined1 auStackY_98 [32];
  undefined8 local_68 [2];
  wchar_t *local_58;
  int local_50;
  undefined4 local_4c;
  wchar_t *local_48;
  undefined8 local_40;
  wchar_t *local_38;
  undefined8 local_30;
  wchar_t *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  lVar1 = -1;
  do {
    lVar1 = lVar1 + 1;
  } while (L"Microsoft NDIS Capture"[lVar1] != L'\0');
  local_50 = (int)lVar1 * 2 + 2;
  local_58 = L"Microsoft NDIS Capture";
  local_4c = 0;
  local_48 = L"{430BDADD-BAB0-41AB-A369-94B67FA5BE0A}";
  local_38 = L"NDISCAP";
  local_28 = L"6.1.0000";
  local_40 = 0x4e;
  local_30 = 0x10;
  local_20 = 0x12;
  McGenEventWrite_EtwWriteTransfer(0,param_2,L"Microsoft NDIS Capture",5,local_68);
  return;
}



===== NetBufferFragmentCombine @ 1400042cc =====

void NetBufferFragmentCombine
               (longlong param_1,uint param_2,uint *param_3,longlong param_4,uint *param_5)

{
  uint uVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  *param_3 = 0;
  plVar4 = *(longlong **)(param_1 + 8);
  uVar7 = *(uint *)(param_1 + 0x10);
  uVar8 = *(uint *)(param_1 + 0x18);
  if (param_2 < *(uint *)(param_1 + 0x18)) {
    uVar8 = param_2;
  }
  uVar5 = 0;
  if (plVar4 != (longlong *)0x0) {
    uVar1 = 0;
    do {
      if ((uVar8 <= uVar1) || (*param_5 <= uVar5)) break;
      uVar6 = *(uint *)(plVar4 + 5);
      if (uVar6 < uVar7) {
        uVar7 = uVar7 - uVar6;
      }
      else {
        if ((*(byte *)((longlong)plVar4 + 10) & 5) == 0) {
          lVar3 = MmMapLockedPagesSpecifyCache(plVar4,0,1,0,0,0x40000000);
        }
        else {
          lVar3 = plVar4[3];
        }
        if (lVar3 == 0) break;
        if (uVar7 != 0) {
          uVar6 = uVar6 - uVar7;
          lVar3 = lVar3 + (ulonglong)uVar7;
          uVar7 = 0;
        }
        uVar1 = uVar8;
        if (uVar6 <= uVar8) {
          uVar1 = uVar6;
        }
        plVar2 = (longlong *)((ulonglong)uVar5 * 0x10 + param_4);
        uVar5 = uVar5 + 1;
        *(undefined4 *)((longlong)plVar2 + 0xc) = 0;
        *plVar2 = lVar3;
        *(uint *)(plVar2 + 1) = uVar1;
        *param_3 = *param_3 + uVar1;
        uVar1 = *param_3;
      }
      plVar4 = (longlong *)*plVar4;
    } while (plVar4 != (longlong *)0x0);
  }
  *param_5 = uVar5;
  return;
}



===== RegisterFilterDriver @ 1400043d8 =====

int RegisterFilterDriver(void)

{
  int iVar1;
  undefined8 uVar2;
  undefined4 *puVar3;
  undefined8 local_128;
  undefined8 uStack_120;
  undefined8 local_118;
  undefined8 uStack_110;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined4 local_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined4 local_c8;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  code *local_b8;
  code *local_b0;
  code *local_a8;
  code *local_a0;
  code *local_98;
  code *local_90;
  code *local_88;
  code *local_70;
  code *local_60;
  code *local_58;
  code *local_40;
  code *local_38;
  
  local_108 = 0;
  uStack_100 = 0;
  local_118 = 0;
  uStack_110 = 0;
  local_128 = 0;
  uStack_120 = 0;
  RtlInitUnicodeString(&local_108,L"NDISCAP");
  RtlInitUnicodeString(&local_128,L"Microsoft NDIS Capture");
  RtlInitUnicodeString(&local_118);
  memset(&local_f8,0,0xf0);
  local_f0 = 0;
  local_b8 = FilterRegisterOptions;
  puVar3 = &local_f8;
  local_f8 = 0xe0028b;
  local_a8 = FilterAttach;
  local_f4 = 0x12806;
  local_a0 = FilterDetach;
  local_98 = FilterRestart;
  local_90 = FilterPause;
  local_60 = FilterOidRequest;
  local_58 = FilterOidRequestComplete;
  local_40 = FilterNetPnPEvent;
  local_b0 = FilterSetModuleOptions;
  local_88 = FilterSendNetBufferLists;
  local_e8 = local_128;
  uStack_e0 = uStack_120;
  local_70 = FilterReceiveNetBufferLists;
  local_38 = FilterStatus;
  local_d8 = (undefined4)local_118;
  uStack_d4 = local_118._4_4_;
  uStack_d0 = (undefined4)uStack_110;
  uStack_cc = uStack_110._4_4_;
  local_c8 = (undefined4)local_108;
  uStack_c4 = local_108._4_4_;
  uStack_c0 = (undefined4)uStack_100;
  uStack_bc = uStack_100._4_4_;
  uVar2 = FilterDriverObject;
  iVar1 = NdisFRegisterFilterDriver
                    (FilterDriverObject,FilterDriverObject,puVar3,&FilterDriverHandle);
  if ((iVar1 != 0) && ((Microsoft_Windows_NDIS_PacketCaptureEnableBits & 0x20) != 0)) {
    McTemplateK0qqq_EtwWriteTransfer(uVar2,&DriverLoadError,puVar3,iVar1,0x7f,0);
  }
  return iVar1;
}



===== TraceNetBuffer @ 140004578 =====

void TraceNetBuffer(longlong param_1,undefined8 param_2,undefined1 param_3,undefined1 param_4,
                   int param_5,undefined8 *param_6,undefined1 *param_7,uint param_8,int param_9)

{
  undefined8 uVar1;
  undefined8 uVar2;
  char cVar3;
  uint uVar4;
  ulonglong uVar5;
  bool bVar6;
  undefined8 in_stack_ffffffffffffffc0;
  
  param_8 = 0;
  GetRuleValue(0x11,&param_8);
  if (param_8 == 0) {
    uVar4 = 0xf000;
  }
  else {
    uVar4 = 0xe;
    if ((0xd < param_8) && (uVar4 = param_8, 0xf000 < param_8)) {
      uVar4 = 0xf000;
    }
  }
  bVar6 = param_9 != 0;
  param_9 = -param_9;
  uVar5 = 1L << ((longlong)param_5 & 0x3fU) | 0xc0000000U |
          (-(ulonglong)bVar6 & 0x100000000) + 0x100000000;
  if (param_6 == (undefined8 *)0x0) {
    uVar1 = *(undefined8 *)(param_7 + 200);
    uVar2 = *(undefined8 *)(param_7 + 0xc0);
    cVar3 = EtwProviderEnabled(MICROSOFT_PACKETCAPTURE_PROVIDER_Context,0,uVar5 | 0x8000060000000000
                              );
    if (cVar3 != '\0') {
      EtwEx_tidPacketFragmentNetBuffer
                (MICROSOFT_PACKETCAPTURE_PROVIDER_Context,(undefined8 *)&PacketFragment,uVar5,
                 param_2,param_3,param_4,uVar4,param_1,(char)uVar1,(char)uVar2);
    }
  }
  else {
    cVar3 = EtwProviderEnabled(MICROSOFT_PACKETCAPTURE_PROVIDER_Context,0,uVar5 | 0x8000040001000000
                              );
    if (cVar3 != '\0') {
      EtwEx_tidVMSwitchNetBuffer
                (MICROSOFT_PACKETCAPTURE_PROVIDER_Context,(undefined4 *)&VMSwitchPacketFragment,
                 uVar5,param_2,param_3,param_4,param_6,uVar4,param_1,in_stack_ffffffffffffffc0,
                 param_7);
    }
  }
  return;
}



===== filterDoInternalRequest @ 14000470c =====

int filterDoInternalRequest
              (longlong param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4,
              uint param_5)

{
  longlong lVar1;
  uint uVar2;
  undefined1 uVar3;
  int iVar4;
  undefined4 *_Dst;
  uint *in_stack_00000048;
  
  lVar1 = param_1 + 0x88;
  iVar4 = 0;
  uVar3 = KeAcquireSpinLockRaiseToDpc(lVar1);
  *(int *)(param_1 + 0x120) = *(int *)(param_1 + 0x120) + 1;
  *(undefined1 *)(param_1 + 0x90) = uVar3;
  KeReleaseSpinLock(lVar1,uVar3);
  _Dst = (undefined4 *)
         NdisAllocateMemoryWithTagPriority(*(undefined8 *)(param_1 + 0x18),0x120,0x746c6946,0);
  if (_Dst != (undefined4 *)0x0) {
    memset(_Dst,0,0xf8);
    NdisInitializeEvent(_Dst + 0x3e);
    *(undefined8 *)(_Dst + 0x46) = 0;
    _Dst[1] = 0;
    *(undefined8 *)(_Dst + 10) = param_4;
    _Dst[0xc] = param_5;
    *_Dst = 0xf80196;
    _Dst[3] = 10;
    _Dst[8] = param_3;
    *(undefined8 *)(_Dst + 4) = 0x52544c46;
    iVar4 = NdisFOidRequest(*(undefined8 *)(param_1 + 0x18),_Dst);
    if (iVar4 == 0x103) {
      NdisWaitEvent(_Dst + 0x3e,0);
      iVar4 = _Dst[0x44];
    }
    uVar3 = KeAcquireSpinLockRaiseToDpc(lVar1);
    *(int *)(param_1 + 0x120) = *(int *)(param_1 + 0x120) + -1;
    *(undefined1 *)(param_1 + 0x90) = uVar3;
    KeReleaseSpinLock(lVar1,uVar3);
    if (iVar4 == 0) {
      uVar2 = _Dst[0xd];
      *in_stack_00000048 = uVar2;
      if (param_5 < uVar2) {
        *in_stack_00000048 = param_5;
      }
    }
    else if (iVar4 == -0x3ffeffec) {
      *in_stack_00000048 = _Dst[0xe];
    }
    else if (iVar4 == 0x103) {
      return 0x103;
    }
    NdisFreeMemory(_Dst,0,0);
  }
  return iVar4;
}



===== filterInternalRequestComplete @ 1400048bc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void filterInternalRequestComplete(longlong param_1,longlong param_2,undefined4 param_3)

{
  undefined1 uVar1;
  
  if (*(longlong *)(param_2 + 0x118) == 0) {
    *(undefined4 *)(param_2 + 0x110) = param_3;
    NdisSetEvent(param_2 + 0xf8);
  }
  else {
    uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x88);
    *(int *)(param_1 + 0x120) = *(int *)(param_1 + 0x120) + -1;
    *(undefined1 *)(param_1 + 0x90) = uVar1;
    KeReleaseSpinLock(param_1 + 0x88,uVar1);
    (**(code **)(param_2 + 0x118))(param_1,param_2,param_3);
    NdisFreeMemory(param_2,0,0);
  }
  return;
}



===== wil_details_FeatureReporting_RecordUsageInCache @ 140004978 =====

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
LAB_140004b81:
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
LAB_140004a53:
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
      if (param_3 == 4) goto LAB_140004b81;
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
        goto LAB_140004a53;
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



===== wil_details_FeatureReporting_ReportUsageToService @ 140004c6c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void wil_details_FeatureReporting_ReportUsageToService
               (undefined8 param_1,ulonglong param_2,uint param_3)

{
  bool bVar1;
  undefined7 extraout_var;
  uint uVar2;
  ulonglong uVar3;
  uint uVar4;
  byte bVar5;
  uint local_res18 [4];
  
  uVar4 = (uint)param_2 & 1;
  uVar3 = (ulonglong)param_3;
  if (param_3 != 0) {
    if (param_3 == 1) {
      uVar2 = (uVar4 ^ 1) << 2;
      uVar3 = 0;
      goto LAB_140004d2f;
    }
    if (param_3 == 2) {
      uVar2 = (uVar4 ^ 1) * 4 + 1;
      uVar3 = 0;
      goto LAB_140004d2f;
    }
    if (param_3 == 3) {
      uVar2 = (uVar4 ^ 1) * 4 + 2;
      uVar3 = 0;
      goto LAB_140004d2f;
    }
    if (param_3 == 4) {
      uVar2 = (uVar4 ^ 1) * 4 + 3;
      uVar3 = 0;
      goto LAB_140004d2f;
    }
    uVar2 = param_3 - 5;
    uVar3 = (ulonglong)uVar2;
    if (uVar2 == 0) {
      uVar2 = (uVar4 ^ 1) * 2 + 8;
      goto LAB_140004d2f;
    }
    if (uVar2 == 1) {
      uVar2 = (uVar4 ^ 1) * 2 + 9;
      goto LAB_140004d2f;
    }
    bVar5 = (char)param_3 + 0x9c;
    if (bVar5 < 0x32) {
      uVar2 = (-(uint)((param_2 & 1) != 0) & 0xffffffce) + 0x96 + (uint)bVar5;
      goto LAB_140004d2f;
    }
  }
  uVar2 = 0xff;
LAB_140004d2f:
  local_res18[0] = param_3;
  bVar1 = wil_details_FeatureReporting_ReportUsageToServiceDirect(uVar3,param_2,uVar2);
  if (((int)CONCAT71(extraout_var,bVar1) != 0) &&
     (g_wil_details_pfnFeatureLoggingHook != (code *)0x0)) {
    (*g_wil_details_pfnFeatureLoggingHook)
              (0x3b92d90,&Feature_969905467_logged_traits,0,uVar4,local_res18,0,0,1);
  }
  return;
}



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 140004d88 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool wil_details_FeatureReporting_ReportUsageToServiceDirect
               (undefined8 param_1,undefined8 param_2,uint param_3)

{
  uint6 uVar1;
  uint *puVar2;
  undefined1 auStack_88 [32];
  uint *local_68;
  undefined8 local_58;
  uint local_50 [6];
  uint local_38;
  uint uStack_34;
  uint uStack_30;
  uint uStack_2c;
  undefined8 local_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_88;
  puVar2 = wil_details_FeatureReporting_RecordUsageInCache
                     (local_50,&Feature_969905467__private_reporting,param_3,
                      (uint)((ulonglong)param_2 >> 0x20));
  local_38 = *puVar2;
  uStack_34 = puVar2[1];
  uStack_30 = puVar2[2];
  uStack_2c = puVar2[3];
  local_28 = *(undefined8 *)(puVar2 + 4);
  if (g_wil_details_recordFeatureUsage != (code *)0x0) {
    local_68 = &local_38;
    (*g_wil_details_recordFeatureUsage)(0x3b92d90,param_3,1,&Feature_969905467__private_reporting);
  }
  if ((((uint)param_2 >> 10 & 1) != 0) && (param_3 != 0xfe)) {
    local_58._0_6_ = CONCAT24((short)param_3,0x3b92d90);
    uVar1 = (uint6)local_58;
    local_58 = (ulonglong)(uint6)local_58;
    if (((uint)param_2 >> 0xb & 1) != 0) {
      local_58 = CONCAT26(1,uVar1);
    }
    RtlNotifyFeatureUsage(&local_58);
  }
  return (int)local_28 == 0;
}



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 140004e74 =====

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
LAB_140004f27:
    uVar8 = uVar8 << 10;
    if (uVar5 != 0) {
      uVar5 = 0x800;
      goto LAB_140004f55;
    }
  }
  else {
    uVar8 = 0;
    uVar5 = 0;
    uVar11 = (uint)local_70;
    if (iVar4 != 0x117) goto LAB_140004f27;
    bVar2 = 1;
    uVar8 = (local_58._4_4_ >> 7 & 1) << 10;
  }
  uVar5 = 0;
LAB_140004f55:
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



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 1400050e0 =====

void wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath(uint param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  
  if (param_2 == 3) {
    uVar2 = 0x10;
  }
  else {
    if (param_2 != 4) {
      return;
    }
    uVar2 = 0x20;
  }
  if ((Feature_969905467__private_featureState & 2) != 0) {
    uVar1 = Feature_969905467__private_featureState;
    while ((uVar1 & 1) == (param_1 & 1)) {
      LOCK();
      bVar3 = uVar1 == Feature_969905467__private_featureState;
      if (bVar3) {
        Feature_969905467__private_featureState = uVar2 | uVar1;
      }
      else {
        uVar1 = Feature_969905467__private_featureState;
      }
      UNLOCK();
      if (bVar3) {
        return;
      }
      if ((uVar1 & 2) == 0) {
        return;
      }
    }
  }
  return;
}



===== wil_details_IsEnabledFallback @ 140005134 =====

uint wil_details_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  undefined4 *puVar1;
  ulonglong local_res18;
  
  local_res18 = (ulonglong)param_1 & 0xffffffff;
  if (((ulonglong)param_1 & 2) == 0) {
    puVar1 = &Feature_969905467__private_featureState;
    local_res18 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                            (&Feature_969905467__private_featureState,(ulonglong)param_1,0x14000b0c0
                            );
    param_1 = puVar1;
    puVar1 = (undefined4 *)(local_res18 & 0xffffffff);
  }
  else {
    puVar1 = param_1;
  }
  if (param_2 != 0) {
    wil_details_FeatureReporting_ReportUsageToService(param_1,local_res18,param_2);
    if (param_2 - 3 < 2) {
      wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath((uint)local_res18,param_2);
    }
  }
  return (uint)puVar1 & 1;
}



===== wil_details_RecordCachedUsage @ 1400051c4 =====

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



===== wil_details_RecordFeatureUsageReporting @ 140005320 =====

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



===== InspectDot11Header @ 1400053a4 =====

undefined1 InspectDot11Header(uint *param_1,uint param_2,int *param_3,ushort *param_4)

{
  ushort uVar1;
  bool bVar2;
  bool bVar3;
  uint *puVar4;
  uint *puVar5;
  byte local_res10 [8];
  
  *param_4 = 0;
  *param_3 = 0;
  if (param_2 < 10) {
    return 1;
  }
  bVar2 = AllowedByRuleEx2(2,param_1,2,(byte *)0x0);
  if (!bVar2) {
    return 0;
  }
  uVar1 = (ushort)*param_1;
  if ((uVar1 & 0xc) != 8) {
    if ((uVar1 & 0xc) == 0) {
      *param_3 = 0x18;
      return 1;
    }
    return 1;
  }
  if ((uVar1 & 0x300) == 0x300) {
    if (0x17 < param_2) {
      *param_3 = 0x1e;
      return 1;
    }
LAB_140005438:
    *param_3 = 0;
    return 1;
  }
  if (param_2 < 0x18) goto LAB_140005438;
  local_res10[0] = 0;
  puVar4 = (uint *)0x0;
  puVar5 = (uint *)0x0;
  if ((uVar1 & 0x300) == 0) {
    puVar5 = param_1 + 1;
LAB_14000547e:
    puVar4 = (uint *)((longlong)param_1 + 10);
  }
  else if ((uVar1 >> 8 & 1) == 0) {
    if ((uVar1 >> 9 & 1) != 0) {
      puVar5 = param_1 + 1;
      puVar4 = param_1 + 4;
    }
  }
  else if ((uVar1 >> 9 & 1) == 0) {
    puVar5 = param_1 + 4;
    goto LAB_14000547e;
  }
  bVar2 = AllowedByRuleEx2(8,puVar5,6,(byte *)0x0);
  if (!bVar2) {
    return 0;
  }
  bVar2 = AllowedByRuleEx2(7,puVar4,6,(byte *)0x0);
  if (!bVar2) {
    return 0;
  }
  bVar2 = AllowedByRuleEx2(9,puVar5,6,local_res10);
  bVar3 = AllowedByRuleEx2(9,puVar4,6,(byte *)0x0);
  if (local_res10[0] == 0) {
    if (bVar2) goto LAB_1400054fd;
  }
  else if (!bVar2) {
    return 0;
  }
  if (!bVar3) {
    return 0;
  }
LAB_1400054fd:
  *param_3 = 0x18;
  if (param_2 < 0x19) {
    return 1;
  }
  if (param_2 - 0x18 < 8) {
    return 1;
  }
  uVar1 = *(ushort *)((longlong)param_1 + 0x1e);
  *param_4 = uVar1 >> 8 | uVar1 << 8;
  bVar2 = AllowedByRuleEx2(6,(uint *)((longlong)param_1 + 0x1e),2,(byte *)0x0);
  if (bVar2) {
    *param_3 = *param_3 + 8;
    return 1;
  }
  return 0;
}



===== InspectPacket @ 14000556c =====

char InspectPacket(int param_1,uint *param_2,uint param_3)

{
  bool bVar1;
  bool bVar2;
  char cVar3;
  byte bVar4;
  uint *puVar5;
  uint uVar6;
  ushort uVar7;
  longlong lVar8;
  ushort local_res20 [4];
  uint local_48 [2];
  uint local_40 [2];
  uint local_38 [4];
  
  local_48[0] = 0;
  uVar6 = 0;
  local_res20[0] = 0;
  uVar7 = 0;
  bVar1 = AllowedByCustomRule(0x12,(longlong)param_2,param_3);
  if (!bVar1) {
    return '\0';
  }
  if (param_1 != 0) {
    if (param_1 != 0x10) {
      return '\x01';
    }
    cVar3 = InspectDot11Header(param_2,param_3,(int *)local_48,local_res20);
    if (cVar3 == '\0') {
      return '\0';
    }
    uVar6 = local_48[0];
    uVar7 = local_res20[0];
    goto LAB_140005690;
  }
  if (0xd < param_3) {
    local_res20[0] = local_res20[0] & 0xff00;
    bVar1 = AllowedByRuleEx2(8,param_2,6,(byte *)0x0);
    if (!bVar1) {
      return '\0';
    }
    bVar1 = AllowedByRuleEx2(7,(uint *)((longlong)param_2 + 6),6,(byte *)0x0);
    if (!bVar1) {
      return '\0';
    }
    bVar1 = AllowedByRuleEx2(9,param_2,6,(byte *)local_res20);
    bVar2 = AllowedByRuleEx2(9,(uint *)((longlong)param_2 + 6),6,(byte *)0x0);
    if ((char)local_res20[0] == '\0') {
      if (!bVar1) goto LAB_140005632;
    }
    else {
      if (!bVar1) {
        return '\0';
      }
LAB_140005632:
      if (!bVar2) {
        return '\0';
      }
    }
    uVar7 = (ushort)param_2[3];
    uVar7 = uVar7 >> 8 | uVar7 << 8;
    bVar1 = AllowedByRuleEx2(6,param_2 + 3,2,(byte *)0x0);
    if (!bVar1) {
      return '\0';
    }
    uVar6 = 0xe;
  }
  cVar3 = '\x01';
LAB_140005690:
  if (uVar7 == 0x800) {
    lVar8 = (ulonglong)uVar6 + (longlong)param_2;
    bVar1 = AllowedByCustomRule(0x13,lVar8,param_3 - uVar6);
    if (!bVar1) {
      return '\0';
    }
    if (param_3 - uVar6 < 0x14) {
      return '\x01';
    }
    local_res20[0] = local_res20[0] & 0xff00;
    bVar1 = AllowedByRuleEx2(0x10,(uint *)(lVar8 + 9),1,(byte *)0x0);
    if (!bVar1) {
      return '\0';
    }
    local_48[0] = *(uint *)(lVar8 + 0xc);
    bVar1 = AllowedByRuleEx2(10,local_48,4,(byte *)0x0);
    if (!bVar1) {
      return '\0';
    }
    local_40[0] = *(uint *)(lVar8 + 0x10);
    bVar1 = AllowedByRuleEx2(0xb,local_40,4,(byte *)0x0);
    if (!bVar1) {
      return '\0';
    }
    bVar1 = AllowedByRuleEx2(0xc,(uint *)(lVar8 + 0xc),4,(byte *)local_res20);
    local_38[0] = *(uint *)(lVar8 + 0x10);
    uVar6 = 4;
    bVar4 = 0xc;
    puVar5 = local_38;
  }
  else {
    if (uVar7 != 0x86dd) {
      return cVar3;
    }
    lVar8 = (ulonglong)uVar6 + (longlong)param_2;
    bVar1 = AllowedByCustomRule(0x13,lVar8,param_3 - uVar6);
    if (!bVar1) {
      return '\0';
    }
    if (param_3 - uVar6 < 0x28) {
      return '\x01';
    }
    local_res20[0] = local_res20[0] & 0xff00;
    bVar1 = AllowedByRuleEx2(0x10,(uint *)(lVar8 + 6),1,(byte *)0x0);
    if (!bVar1) {
      return '\0';
    }
    bVar1 = AllowedByRuleEx2(0xd,(uint *)(lVar8 + 8),0x10,(byte *)0x0);
    if (!bVar1) {
      return '\0';
    }
    bVar1 = AllowedByRuleEx2(0xe,(uint *)(lVar8 + 0x18),0x10,(byte *)0x0);
    if (!bVar1) {
      return '\0';
    }
    bVar1 = AllowedByRuleEx2(0xf,(uint *)(lVar8 + 8),0x10,(byte *)local_res20);
    uVar6 = 0x10;
    puVar5 = (uint *)(lVar8 + 0x18);
    bVar4 = 0xf;
  }
  bVar2 = AllowedByRuleEx2(bVar4,puVar5,uVar6,(byte *)0x0);
  if ((char)local_res20[0] == '\0') {
    if (bVar2) {
      return '\x01';
    }
  }
  else if (!bVar2) {
    return '\0';
  }
  if (bVar1 == false) {
    return '\0';
  }
  return '\x01';
}



===== InspectPacketMdl @ 140005838 =====

/* WARNING: Removing unreachable block (ram,0x000140005a8c) */

char InspectPacketMdl(int param_1,longlong *param_2,ulonglong param_3,ulonglong param_4)

{
  uint *puVar1;
  uint uVar2;
  char cVar3;
  uint *puVar4;
  longlong lVar5;
  void *_Src;
  int iVar6;
  ulonglong _Size;
  ulonglong uVar7;
  uint uVar8;
  size_t local_38;
  
  if (param_1 == 0) {
    iVar6 = 0x36;
  }
  else {
    iVar6 = 0;
    if (param_1 == 0x10) {
      iVar6 = 0x52;
    }
  }
  uVar8 = g_MaxRuleInspectionOffset + iVar6;
  if (uVar8 == 0) {
    return '\x01';
  }
  if (param_2 == (longlong *)0x0) {
    return '\x01';
  }
  if ((*(byte *)((longlong)param_2 + 10) & 5) == 0) {
    lVar5 = MmMapLockedPagesSpecifyCache(param_2,0,1,0,0,0x40000010);
  }
  else {
    lVar5 = param_2[3];
  }
  if (lVar5 == 0) {
    return '\x01';
  }
  if ((ulonglong)*(uint *)(param_2 + 5) == 0) {
    return '\x01';
  }
  uVar7 = *(uint *)(param_2 + 5) - param_3;
  puVar4 = (uint *)(lVar5 + param_3);
  if ((uVar8 <= uVar7) || (uVar7 == param_4)) goto LAB_140005ace;
  if (g_CoalescedBuffer == (uint *)0x0) {
LAB_14000592f:
    g_CoalescedBuffer = (uint *)ExAllocatePoolWithTag(0x200,(ulonglong)uVar8,0x746c6946);
    g_CoalescedBufferLength = uVar8;
  }
  else if (g_CoalescedBufferLength < uVar8) {
    ExFreePoolWithTag(g_CoalescedBuffer,0);
    g_CoalescedBuffer = (uint *)0x0;
    g_CoalescedBufferLength = 0;
    goto LAB_14000592f;
  }
  puVar4 = g_CoalescedBuffer;
  if (g_CoalescedBuffer == (uint *)0x0) {
    return '\x01';
  }
  do {
    puVar1 = (uint *)(param_2 + 5);
    if (param_3 < *puVar1) break;
    param_2 = (longlong *)*param_2;
    param_3 = param_3 - *puVar1;
  } while (param_2 != (longlong *)0x0);
  uVar7 = (ulonglong)g_CoalescedBufferLength;
  if (param_4 < g_CoalescedBufferLength) {
    uVar7 = param_4;
  }
  if ((uVar7 != 0) && (param_2 != (longlong *)0x0)) {
    _Size = uVar7;
    if (*(uint *)(param_2 + 5) - param_3 <= uVar7) {
      _Size = *(uint *)(param_2 + 5) - param_3;
    }
    if ((*(byte *)((longlong)param_2 + 10) & 5) == 0) {
      lVar5 = MmMapLockedPagesSpecifyCache(param_2,0,1,0,0,0x40000000);
    }
    else {
      lVar5 = param_2[3];
    }
    if (lVar5 == 0) {
      return '\x01';
    }
    memmove(puVar4,(void *)(lVar5 + param_3),_Size);
    if (uVar7 != _Size) {
      local_38 = _Size;
      do {
        uVar7 = uVar7 - _Size;
        do {
          param_2 = (longlong *)*param_2;
          if (param_2 == (longlong *)0x0) goto LAB_140005ab9;
          uVar2 = *(uint *)(param_2 + 5);
        } while (uVar2 == 0);
        _Size = uVar7;
        if (uVar2 <= uVar7) {
          _Size = (ulonglong)uVar2;
        }
        if ((*(byte *)((longlong)param_2 + 10) & 5) == 0) {
          _Src = (void *)MmMapLockedPagesSpecifyCache(param_2,0,1,0,0,0x40000000);
        }
        else {
          _Src = (void *)param_2[3];
        }
        if (_Src == (void *)0x0) {
          return '\x01';
        }
        memmove((void *)(local_38 + (longlong)puVar4),_Src,_Size);
        local_38 = local_38 + _Size;
      } while (uVar7 != _Size);
    }
  }
LAB_140005ab9:
  uVar7 = param_4 & 0xffffffff;
  if (uVar8 <= (uint)param_4) {
    uVar7 = (ulonglong)uVar8;
  }
  puVar4 = g_CoalescedBuffer;
LAB_140005ace:
  cVar3 = InspectPacket(param_1,puVar4,(uint)uVar7);
  return cVar3;
}



===== EtwEx_tidPacketFragmentArray @ 140005ae0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void EtwEx_tidPacketFragmentArray
               (undefined8 param_1,undefined8 *param_2,ulonglong param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6,uint param_7,uint param_8,longlong *param_9)

{
  undefined1 auStack_2b8 [32];
  undefined1 **local_298;
  uint local_288 [2];
  undefined8 local_280;
  ulonglong uStack_278;
  undefined1 *local_268;
  undefined4 local_260;
  undefined4 local_25c;
  undefined1 *local_258;
  undefined4 local_250;
  undefined4 local_24c;
  uint *local_248;
  undefined4 local_240;
  undefined4 local_23c;
  undefined1 local_238 [528];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_2b8;
  local_280 = *param_2;
  local_25c = 0;
  local_24c = 0;
  uStack_278 = param_2[1] | param_3 | 1L << ((ulonglong)param_7 & 0x3f);
  local_260 = 4;
  local_268 = &param_5;
  local_250 = 4;
  local_258 = &param_6;
  local_288[0] = 0x20;
  PacketFragmentCombine(param_9,&param_8,(longlong)local_238,local_288);
  local_248 = &param_8;
  local_23c = 0;
  local_298 = &local_268;
  local_240 = 4;
  EtwWrite(param_1,&local_280,param_4,local_288[0] + 3);
  return;
}



===== EtwEx_tidVMSwitchPacketFragmentArray @ 140005be8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void EtwEx_tidVMSwitchPacketFragmentArray
               (undefined8 param_1,undefined8 *param_2,ulonglong param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6,uint param_7,undefined1 param_8)

{
  ulonglong uVar1;
  undefined1 uStack0000000000000060;
  uint uStack0000000000000078;
  longlong *in_stack_00000080;
  undefined8 in_stack_00000090;
  undefined1 auStack_328 [32];
  undefined1 **local_308;
  uint local_2f8 [2];
  undefined4 local_2f0 [2];
  undefined8 local_2e8;
  ulonglong uStack_2e0;
  undefined1 *local_2d8;
  undefined8 local_2d0;
  undefined1 *local_2c8;
  undefined4 local_2c0;
  undefined4 local_2bc;
  undefined1 *local_2b8;
  undefined4 local_2b0;
  undefined4 local_2ac;
  wchar_t *local_2a8;
  undefined4 local_2a0;
  undefined4 local_29c;
  wchar_t *local_298;
  undefined4 local_290;
  undefined4 local_28c;
  wchar_t *local_288;
  undefined4 local_280;
  undefined4 local_27c;
  undefined1 *local_278;
  undefined4 local_270;
  undefined4 local_26c;
  undefined4 local_25c;
  undefined1 *local_258;
  undefined4 local_250;
  undefined4 local_24c;
  undefined1 local_248 [560];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_328;
  local_2e8 = *param_2;
  local_2d0._4_4_ = 0;
  local_2bc = 0;
  local_2ac = 0;
  uStack_2e0 = param_2[1] | param_3 | 1L << ((ulonglong)param_7 & 0x3f);
  local_29c = 0;
  local_2d8 = &param_5;
  local_28c = 0;
  local_27c = 0;
  local_26c = 0;
  local_25c = 0;
  local_2c8 = &param_6;
  local_2b8 = &param_8;
  local_2a0 = 10;
  local_290 = 10;
  local_280 = 10;
  local_278 = &uStack0000000000000060;
  local_2a8 = L"NULL";
  local_298 = L"NULL";
  local_288 = L"NULL";
  local_2f0[0] = 0xd8;
  local_2d0._0_4_ = 4;
  local_2c0 = 4;
  local_2b0 = 4;
  local_270 = 4;
  local_2f8[0] = 0x20;
  PacketFragmentCombine(in_stack_00000080,&uStack0000000000000078,(longlong)local_248,local_2f8);
  local_24c = 0;
  local_258 = (undefined1 *)&uStack0000000000000078;
  local_250 = 4;
  uVar1 = (ulonglong)(local_2f8[0] + 9);
  *(undefined4 *)((longlong)&local_2d0 + (uVar1 * 4 + 1) * 4) = 0;
  (&local_2d0)[uVar1 * 2 + -1] = local_2f0;
  *(undefined4 *)(&local_2d0 + uVar1 * 2) = 4;
  uVar1 = (ulonglong)(local_2f8[0] + 10);
  *(undefined4 *)((longlong)&local_2d0 + (uVar1 * 4 + 1) * 4) = 0;
  (&local_2d0)[uVar1 * 2 + -1] = in_stack_00000090;
  *(undefined4 *)(&local_2d0 + uVar1 * 2) = local_2f0[0];
  local_308 = &local_2d8;
  EtwWrite(param_1,&local_2e8,&DAT_14000c158,local_2f8[0] + 0xb);
  return;
}



===== McTemplateK0uqxxzz_EtwWriteTransfer @ 140005da8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0uqxxzz_EtwWriteTransfer(void)

{
  longlong lVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined1 local_res20 [8];
  undefined1 uStack0000000000000028;
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  wchar_t *in_stack_00000040;
  wchar_t *in_stack_00000048;
  undefined1 auStackY_b8 [32];
  undefined8 local_88 [2];
  undefined1 *local_78;
  undefined8 local_70;
  undefined1 *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  wchar_t *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  wchar_t *local_28;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_b8;
  local_78 = local_res20;
  local_68 = &uStack0000000000000028;
  local_58 = &uStack0000000000000030;
  local_48 = &uStack0000000000000038;
  local_20 = 10;
  lVar1 = -1;
  local_70 = 1;
  local_60 = 4;
  local_50 = 8;
  local_40 = 8;
  if (in_stack_00000040 == (wchar_t *)0x0) {
    uVar3 = 10;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (in_stack_00000040[lVar2] != L'\0');
    uVar3 = (ulonglong)((int)lVar2 * 2 + 2);
  }
  local_30 = (undefined4)uVar3;
  local_2c = 0;
  if (in_stack_00000040 == (wchar_t *)0x0) {
    in_stack_00000040 = L"NULL";
  }
  if (in_stack_00000048 != (wchar_t *)0x0) {
    do {
      lVar1 = lVar1 + 1;
    } while (in_stack_00000048[lVar1] != L'\0');
    local_20 = (int)lVar1 * 2 + 2;
  }
  if (in_stack_00000048 == (wchar_t *)0x0) {
    in_stack_00000048 = L"NULL";
  }
  local_1c = 0;
  local_38 = in_stack_00000040;
  local_28 = in_stack_00000048;
  McGenEventWrite_EtwWriteTransfer(uVar3,&StateRundown,in_stack_00000048,7,local_88);
  return;
}



===== McTemplateK0uzqhNR3_EtwWriteTransfer @ 140005eb4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0uzqhNR3_EtwWriteTransfer(void)

{
  longlong lVar1;
  undefined1 local_res20 [8];
  wchar_t *in_stack_00000028;
  undefined1 uStack0000000000000030;
  undefined2 uStack0000000000000038;
  undefined1 auStackY_a8 [32];
  undefined8 local_78 [2];
  undefined1 *local_68;
  undefined8 local_60;
  wchar_t *local_58;
  int local_50;
  undefined4 local_4c;
  undefined1 *local_48;
  undefined8 local_40;
  undefined2 *local_38;
  undefined8 local_30;
  uint local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_68 = local_res20;
  local_60 = 1;
  if (in_stack_00000028 == (wchar_t *)0x0) {
    local_50 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (in_stack_00000028[lVar1] != L'\0');
    local_50 = (int)lVar1 * 2 + 2;
  }
  local_4c = 0;
  local_48 = &uStack0000000000000030;
  local_40 = 4;
  if (in_stack_00000028 == (wchar_t *)0x0) {
    in_stack_00000028 = L"NULL";
  }
  local_38 = &uStack0000000000000038;
  local_20 = (uint)uStack0000000000000038 * 0x210;
  local_30 = 2;
  local_1c = 0;
  local_58 = in_stack_00000028;
  McGenEventWrite_EtwWriteTransfer((ulonglong)local_20,&PktSourceInfo,0,6,local_78);
  return;
}



===== PacketFragmentCombine @ 140005f98 =====

void PacketFragmentCombine(longlong *param_1,uint *param_2,longlong param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  ulonglong uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar4 = *param_2;
  uVar5 = 0;
  if ((short)param_1[1] != 0) {
    uVar1 = *param_4;
    do {
      if ((uVar1 <= uVar5) || (uVar4 == 0)) break;
      uVar3 = (ulonglong)uVar5;
      uVar2 = *(uint *)(*param_1 + 8 + uVar3 * 0x10);
      if (uVar4 <= uVar2) {
        uVar2 = uVar4;
      }
      *(undefined8 *)(param_3 + uVar3 * 0x10) = *(undefined8 *)(*param_1 + uVar3 * 0x10);
      *(uint *)(param_3 + 8 + uVar3 * 0x10) = uVar2;
      uVar4 = uVar4 - uVar2;
      *(undefined4 *)(param_3 + 0xc + uVar3 * 0x10) = 0;
      uVar5 = uVar5 + 1;
    } while (uVar5 < *(ushort *)(param_1 + 1));
  }
  *param_2 = *param_2 - uVar4;
  *param_4 = uVar5;
  return;
}



===== PktCapAttachClient @ 140006030 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 PktCapAttachClient(void)

{
  code *pcVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  undefined1 *puVar5;
  undefined8 in_R9;
  undefined8 in_stack_00000028;
  undefined8 *in_stack_00000030;
  undefined8 *in_stack_00000038;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  *in_stack_00000038 = 0;
  *in_stack_00000030 = 0;
  puVar2 = (undefined8 *)ExAllocatePoolWithTag(0x200,0x20,0x63634350);
  if (puVar2 == (undefined8 *)0x0) {
    uVar3 = 0xc000009a;
  }
  else {
    *puVar2 = 0;
    puVar2[1] = 0;
    puVar2[3] = in_stack_00000028;
    puVar2[2] = in_R9;
    *in_stack_00000038 = &PktCapProviderDispatch;
    *in_stack_00000030 = puVar2;
    KeAcquireGuardedMutex(&DAT_14000c198);
    puVar5 = auStack_28;
    puVar4 = &DAT_14000c180;
    if ((undefined8 **)DAT_14000c180[1] != &DAT_14000c180) {
      puVar4 = (undefined8 *)0x3;
      pcVar1 = (code *)swi(0x29);
      DAT_14000c180 = (undefined8 *)(*pcVar1)();
      puVar5 = auStack_20;
    }
    puVar2[1] = puVar4;
    *puVar2 = DAT_14000c180;
    DAT_14000c180[1] = puVar2;
    _DAT_14000c190 = _DAT_14000c190 + 1;
    *(undefined8 *)(puVar5 + -8) = 0x1400060f8;
    DAT_14000c180 = puVar2;
    PktCapUpdateClientConfig((longlong)puVar2);
    *(undefined8 *)(puVar5 + -8) = 0x140006106;
    KeReleaseGuardedMutex(&DAT_14000c198);
    uVar3 = 0;
  }
  return uVar3;
}



===== PktCapCleanupClientContext @ 140006130 =====

void PktCapCleanupClientContext(undefined8 param_1)

{
  ExFreePoolWithTag(param_1,0);
  return;
}



===== PktCapDetachClient @ 140006150 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 PktCapDetachClient(longlong *param_1)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  undefined8 uVar4;
  
  KeAcquireGuardedMutex(&DAT_14000c198);
  lVar1 = *param_1;
  if ((*(longlong **)(lVar1 + 8) == param_1) &&
     (plVar2 = (longlong *)param_1[1], (longlong *)*plVar2 == param_1)) {
    *plVar2 = lVar1;
    *(longlong **)(lVar1 + 8) = plVar2;
    _DAT_14000c190 = _DAT_14000c190 + -1;
    KeReleaseGuardedMutex(&DAT_14000c198);
    return 0;
  }
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  pcVar3 = (code *)swi(3);
  uVar4 = (*pcVar3)();
  return uVar4;
}



===== PktCapInspectPacket @ 1400061b4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

char PktCapInspectPacket(longlong *param_1,int param_2)

{
  ushort uVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint *puVar7;
  uint uVar8;
  ulonglong uVar9;
  undefined1 auStack_d8 [32];
  uint local_b8 [32];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_d8;
  if (param_2 == 1) {
    iVar6 = 0;
    iVar4 = 0x36;
  }
  else if (param_2 == 2) {
    iVar6 = 0x10;
    iVar4 = 0x52;
  }
  else {
    iVar6 = 0x14;
    iVar4 = 0;
  }
  if ((g_MaxRuleInspectionOffset + iVar4 == 0) || (uVar1 = *(ushort *)(param_1 + 1), uVar1 == 0)) {
LAB_1400062a4:
    cVar2 = '\x01';
  }
  else {
    uVar5 = *(uint *)((undefined8 *)*param_1 + 1);
    if ((uVar5 < (uint)(g_MaxRuleInspectionOffset + iVar4)) && (uVar1 != 1)) {
      if (uVar1 < 2) goto LAB_1400062a4;
      uVar9 = 0;
      uVar5 = 0x80;
      puVar7 = local_b8;
      do {
        if (uVar5 == 0) break;
        uVar8 = *(uint *)(*param_1 + 8 + uVar9 * 0x10);
        uVar3 = uVar5;
        if (uVar8 <= uVar5) {
          uVar3 = uVar8;
        }
        memmove(puVar7,*(void **)(*param_1 + uVar9 * 0x10),(ulonglong)uVar3);
        puVar7 = (uint *)((longlong)puVar7 + (ulonglong)uVar3);
        uVar5 = uVar5 - uVar3;
        uVar8 = (int)uVar9 + 1;
        uVar9 = (ulonglong)uVar8;
      } while (uVar8 < *(ushort *)(param_1 + 1));
      uVar5 = 0x80 - uVar5;
      puVar7 = local_b8;
    }
    else {
      puVar7 = *(uint **)*param_1;
    }
    cVar2 = InspectPacket(iVar6,puVar7,uVar5);
  }
  return cVar2;
}



===== PktCapLogNetEvent @ 1400062e0 =====

void PktCapLogNetEvent(void)

{
  if ((DAT_14000c751 & 1) != 0) {
    McTemplateK0uqxxzz_EtwWriteTransfer();
  }
  return;
}



===== PktCapLogPacket @ 140006330 =====

void PktCapLogPacket(longlong *param_1,int *param_2)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  int *piVar5;
  ulonglong uVar6;
  uint uVar7;
  uint uVar8;
  uint local_res10 [2];
  uint local_res18 [4];
  
  local_res10[0] = 0;
  if (((param_2[4] != 2) ||
      (cVar1 = EtwProviderEnabled(MICROSOFT_PACKETCAPTURE_PROVIDER_Context,0,0x100000000),
      cVar1 != '\0')) &&
     ((param_2[4] != 1 ||
      (cVar1 = EtwProviderEnabled(MICROSOFT_PACKETCAPTURE_PROVIDER_Context,0,0x200000000),
      cVar1 != '\0')))) {
    if ((char)param_2[0xb] == '\0') {
      local_res18[0] = 0;
      bVar2 = AllowedByRuleEx2(3,local_res18,4,(byte *)0x0);
      if (bVar2) {
        return;
      }
    }
    local_res18[0] = param_2[2];
    bVar2 = AllowedByRuleEx2(4,local_res18,4,(byte *)0x0);
    if (bVar2) {
      if (*param_2 == 1) {
        bVar3 = AllowedByRuleEx2(0x1a,(uint *)(param_2 + 0x16),4,(byte *)0x0);
        bVar2 = false;
        uVar7 = 0;
        if (param_2[0x1a] != 0) {
          do {
            bVar4 = AllowedByRuleEx2(0x1a,(uint *)(*(longlong *)(param_2 + 0x18) +
                                                  (ulonglong)uVar7 * 4),4,(byte *)0x0);
            if (bVar4) {
              bVar2 = true;
              break;
            }
            uVar7 = uVar7 + 1;
          } while (uVar7 < (uint)param_2[0x1a]);
        }
        if ((!bVar3) && (!bVar2)) {
          return;
        }
      }
      if ((g_PacketInspectionRequired == '\0') ||
         (cVar1 = PktCapInspectPacket(param_1,param_2[3]), cVar1 != '\0')) {
        uVar7 = 0;
        if (*(ushort *)(param_1 + 1) != 0) {
          uVar6 = (ulonglong)*(ushort *)(param_1 + 1);
          piVar5 = (int *)(*param_1 + 8);
          do {
            uVar7 = uVar7 + *piVar5;
            piVar5 = piVar5 + 4;
            uVar6 = uVar6 - 1;
          } while (uVar6 != 0);
        }
        GetRuleValue(0x11,local_res10);
        if ((local_res10[0] == 0) || (uVar8 = local_res10[0], uVar7 < local_res10[0])) {
          uVar8 = uVar7;
        }
        if (0xf000 < uVar8) {
          uVar8 = 0xf000;
        }
        PktCapTracePacket(param_1,param_2,(ulonglong)uVar7,uVar8);
      }
    }
  }
  return;
}



===== PktCapProviderUninitialize @ 1400064d4 =====

void PktCapProviderUninitialize(void)

{
  int iVar1;
  
  if (DAT_14000c178 != '\0') {
    DAT_14000c178 = '\0';
    PktCapUpdateCaptureConfig();
  }
  if (PktCap != 0) {
    iVar1 = NmrDeregisterProvider();
    if (iVar1 == 0x103) {
      NmrWaitForProviderDeregisterComplete(PktCap);
    }
    PktCap = 0;
  }
  return;
}



===== PktCapTracePacket @ 140006534 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PktCapTracePacket(longlong *param_1,int *param_2,ulonglong param_3,uint param_4)

{
  char cVar1;
  ulonglong uVar2;
  uint uVar3;
  undefined1 auStackY_88 [32];
  undefined8 local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_88;
  local_38 = 0;
  uStack_30 = 0;
  if (param_2[3] == 1) {
    uVar3 = 0;
  }
  else if (param_2[3] == 2) {
    uVar3 = 0x10;
  }
  else {
    uVar3 = 0x14;
  }
  uVar2 = 0x100000000;
  if (param_2[4] != 2) {
    uVar2 = 0x200000000;
  }
  uVar2 = (ulonglong)(-(uint)(param_4 < (uint)param_3) & 0x2000000) + 0xc0000000 | uVar2;
  if (*param_2 == 0) {
    param_3 = uVar2 | 0x8000060000000000 | 1L << uVar3;
    cVar1 = EtwProviderEnabled(MICROSOFT_PACKETCAPTURE_PROVIDER_Context,0);
    if (cVar1 != '\0') {
      param_3 = uVar2;
      EtwEx_tidPacketFragmentArray
                (MICROSOFT_PACKETCAPTURE_PROVIDER_Context,(undefined8 *)&PacketFragment,uVar2,
                 &local_38,(char)param_2[2],(char)param_2[10],uVar3,param_4,param_1);
    }
  }
  if (*param_2 == 1) {
    TraceLegacyVMSwitchPacket(param_1,(longlong)param_2,param_3,(ulonglong)param_4,uVar2,uVar3);
  }
  return;
}



===== PktCapTraceRundown @ 140006668 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PktCapTraceRundown(void)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 local_res8;
  
  local_res8 = 0;
  KeAcquireGuardedMutex(&DAT_14000c198);
  for (puVar2 = DAT_14000c180; (undefined8 **)puVar2 != &DAT_14000c180;
      puVar2 = (undefined8 *)*puVar2) {
    iVar1 = (**(code **)(puVar2[3] + 8))(puVar2[2],&local_res8);
    if (iVar1 == 0) {
      if ((DAT_14000c751 & 1) != 0) {
        McTemplateK0uzqhNR3_EtwWriteTransfer();
      }
      ExFreePoolWithTag(local_res8,0);
      local_res8 = 0;
    }
    (**(code **)(puVar2[3] + 0x18))(puVar2[2]);
  }
  KeReleaseGuardedMutex(&DAT_14000c198);
  return;
}



===== PktCapUpdateCaptureConfig @ 140006758 =====

void PktCapUpdateCaptureConfig(void)

{
  undefined8 *puVar1;
  
  KeAcquireGuardedMutex(&DAT_14000c198);
  for (puVar1 = DAT_14000c180; (undefined8 **)puVar1 != &DAT_14000c180;
      puVar1 = (undefined8 *)*puVar1) {
    PktCapUpdateClientConfig((longlong)puVar1);
  }
  KeReleaseGuardedMutex(&DAT_14000c198);
  return;
}



===== PktCapUpdateClientConfig @ 1400067bc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PktCapUpdateClientConfig(longlong param_1)

{
  bool bVar1;
  char cVar2;
  uint local_res8 [8];
  
  cVar2 = '\0';
  if (DAT_14000c178 != '\0') {
    local_res8[0] = 0;
    bVar1 = AllowedByRuleEx2(3,local_res8,4,(byte *)0x0);
    cVar2 = bVar1 + '\x01';
  }
  (**(code **)(*(longlong *)(param_1 + 0x18) + 0x10))(*(undefined8 *)(param_1 + 0x10),cVar2,0,0);
  return;
}



===== TraceLegacyVMSwitchPacket @ 140006814 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void TraceLegacyVMSwitchPacket
               (undefined8 param_1,longlong param_2,undefined8 param_3,undefined8 param_4,
               ulonglong param_5,uint param_6)

{
  char cVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined1 auStackY_5a8 [32];
  undefined8 local_518 [2];
  undefined8 local_508;
  undefined8 local_4f8;
  undefined8 local_478;
  undefined8 local_468;
  undefined8 local_460;
  undefined1 local_438 [1024];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_5a8;
  memset(local_518,0,0xd8);
  local_518[0] = *(undefined8 *)(param_2 + 0x30);
  local_508 = *(undefined8 *)(param_2 + 0x38);
  local_468 = *(undefined8 *)(param_2 + 0x40);
  local_4f8 = *(undefined8 *)(param_2 + 0x48);
  local_478 = *(undefined8 *)(param_2 + 0x78);
  local_460 = *(undefined8 *)(param_2 + 0x70);
  if (*(uint *)(param_2 + 0x68) < 0x40) {
    puVar2 = local_438;
    puVar3 = (undefined1 *)0x0;
  }
  else {
    puVar2 = (undefined1 *)ExAllocatePoolWithTag(0x200,(ulonglong)*(uint *)(param_2 + 0x68) << 4);
    if (puVar2 == (undefined1 *)0x0) {
      return;
    }
    puVar3 = puVar2;
  }
  if (*(int *)(param_2 + 0x68) != 0) {
    param_4 = 0x30;
    uVar5 = 0;
    do {
      uVar4 = (int)uVar5 + 1;
      *(undefined4 *)(puVar2 + uVar5 * 0x10) =
           *(undefined4 *)(*(longlong *)(param_2 + 0x60) + uVar5 * 4);
      *(undefined4 *)(puVar2 + uVar5 * 0x10 + 8) = 0x30;
      *(undefined4 *)(puVar2 + uVar5 * 0x10 + 0xc) = 0x30;
      *(undefined4 *)(puVar2 + uVar5 * 0x10 + 4) = 0x30;
      uVar5 = (ulonglong)uVar4;
    } while (uVar4 < *(uint *)(param_2 + 0x68));
  }
  cVar1 = EtwProviderEnabled(MICROSOFT_PACKETCAPTURE_PROVIDER_Context,0,
                             param_5 | 0x8000040001000000 | 1L << ((longlong)(int)param_6 & 0x3fU));
  if (cVar1 != '\0') {
    EtwEx_tidVMSwitchPacketFragmentArray
              (MICROSOFT_PACKETCAPTURE_PROVIDER_Context,(undefined8 *)&VMSwitchPacketFragment,
               param_5,param_4,(char)*(undefined4 *)(param_2 + 8),
               (char)*(undefined4 *)(param_2 + 0x28),param_6,(char)*(undefined4 *)(param_2 + 0x58));
  }
  if (puVar3 != (undefined1 *)0x0) {
    ExFreePoolWithTag(puVar3,0);
  }
  return;
}



===== AllowedByCustomRule @ 1400069f8 =====

bool AllowedByCustomRule(byte param_1,longlong param_2,uint param_3)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  ulonglong uVar4;
  bool bVar5;
  undefined4 local_res8 [2];
  
  local_res8[0] = 0;
  bVar5 = true;
  uVar4 = Feature_969905467__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar4 != 0) {
    NdisAcquireReadWriteLock(&g_RulesLock,0,local_res8);
  }
  lVar2 = (&g_Rules)[param_1];
  if ((lVar2 != 0) && (*(char *)(lVar2 + 1) != '\0')) {
    bVar5 = false;
    uVar1 = *(uint *)(lVar2 + 4);
    uVar3 = *(ushort *)(lVar2 + 2) - 4;
    if ((uVar1 <= param_3) && (uVar3 <= param_3 - uVar1)) {
      uVar4 = RtlCompareMemory((ulonglong)uVar1 + param_2,lVar2 + 8,uVar3);
      bVar5 = uVar4 == uVar3;
    }
  }
  uVar4 = Feature_969905467__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar4 != 0) {
    NdisReleaseReadWriteLock(&g_RulesLock,local_res8);
  }
  return bVar5;
}



===== AllowedByRuleEx2 @ 140006ad0 =====

bool AllowedByRuleEx2(byte param_1,uint *param_2,uint param_3,byte *param_4)

{
  longlong lVar1;
  bool bVar2;
  ulonglong uVar3;
  undefined4 local_18 [4];
  
  uVar3 = Feature_969905467__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar3 == 0) {
    bVar2 = true;
    if (param_4 != (byte *)0x0) {
      *param_4 = 0;
    }
    if (((param_1 < 0x22) && (lVar1 = (&g_Rules)[param_1], lVar1 != 0)) &&
       (*(char *)(lVar1 + 1) != '\0')) {
      bVar2 = TraceFilterEnginepEvaluateBinaryRuleEx(lVar1,param_2,param_3);
      if (param_4 != (byte *)0x0) {
        *param_4 = *(byte *)(lVar1 + 1) >> 7;
      }
    }
  }
  else {
    local_18[0] = 0;
    NdisAcquireReadWriteLock(&g_RulesLock,0,local_18);
    bVar2 = true;
    if (param_4 != (byte *)0x0) {
      *param_4 = 0;
    }
    if (((param_1 < 0x22) && (lVar1 = (&g_Rules)[param_1], lVar1 != 0)) &&
       (*(char *)(lVar1 + 1) != '\0')) {
      bVar2 = TraceFilterEnginepEvaluateBinaryRuleEx(lVar1,param_2,param_3);
      if (param_4 != (byte *)0x0) {
        *param_4 = *(byte *)(lVar1 + 1) >> 7;
      }
    }
    NdisReleaseReadWriteLock(&g_RulesLock,local_18);
  }
  return bVar2;
}



===== GetRuleValue @ 140006bf8 =====

undefined8 GetRuleValue(byte param_1,undefined4 *param_2)

{
  uint *puVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined1 uVar5;
  undefined1 uVar4;
  undefined4 local_res18 [4];
  
  uVar3 = Feature_969905467__private_IsEnabledDeviceUsageNoInline();
  uVar5 = 0;
  uVar4 = 0;
  if ((int)uVar3 == 0) {
    if ((((param_1 < 0x22) && (uVar3 = (&g_Rules)[param_1], uVar3 != 0)) &&
        (*(char *)(uVar3 + 1) != '\0')) && (*(short *)(uVar3 + 2) == 4)) {
      puVar1 = (uint *)(uVar3 + 4);
      uVar3 = (ulonglong)*puVar1;
      uVar4 = 1;
      *param_2 = *puVar1;
    }
  }
  else {
    local_res18[0] = 0;
    NdisAcquireReadWriteLock(&g_RulesLock,0,local_res18);
    uVar4 = uVar5;
    if (((param_1 < 0x22) && (lVar2 = (&g_Rules)[param_1], lVar2 != 0)) &&
       ((*(char *)(lVar2 + 1) != '\0' && (*(short *)(lVar2 + 2) == 4)))) {
      uVar4 = 1;
      *param_2 = *(undefined4 *)(lVar2 + 4);
    }
    uVar3 = NdisReleaseReadWriteLock(&g_RulesLock,local_res18);
  }
  return CONCAT71((int7)(uVar3 >> 8),uVar4);
}



===== McTemplateK0q_EtwWriteTransfer @ 140006cc4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0q_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  undefined1 auStackY_68 [32];
  undefined8 local_38 [2];
  undefined4 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  local_28 = local_res20;
  local_1c = 0;
  local_20 = 4;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&CaptureRules,param_3,2,local_38);
  return;
}



===== McTemplateK0uuhbr2_EtwWriteTransfer @ 140006d28 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0uuhbr2_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined1 param_4,
               undefined1 param_5,ushort param_6,undefined8 param_7)

{
  undefined1 local_res20 [8];
  undefined1 auStackY_98 [32];
  undefined8 local_68 [2];
  undefined1 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  ushort *local_38;
  undefined8 local_30;
  undefined8 local_28;
  uint local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  local_50 = 1;
  local_58 = local_res20;
  local_40 = 1;
  local_48 = &param_5;
  local_38 = &param_6;
  local_28 = param_7;
  local_20 = (uint)param_6;
  local_30 = 2;
  local_1c = 0;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,0,5,local_68);
  return;
}



===== NdisCapEtwEnableCallback @ 140006dbc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void NdisCapEtwEnableCallback
               (undefined8 param_1,uint *param_2,uint *param_3,undefined8 param_4,undefined8 param_5
               ,longlong *param_6)

{
  byte bVar1;
  ushort uVar2;
  undefined1 *puVar3;
  ulonglong uVar4;
  void *_Dst;
  undefined8 uVar5;
  uint uVar6;
  char *_Dst_00;
  uint *puVar7;
  uint uVar8;
  int iVar9;
  longlong lVar10;
  uint *puVar11;
  undefined8 *puVar12;
  longlong lVar13;
  longlong *plVar14;
  uint uVar15;
  longlong lVar16;
  bool bVar17;
  undefined1 auStackY_1a8 [32];
  uint local_168;
  uint local_164;
  int local_160;
  uint *local_158;
  longlong local_148 [34];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_1a8;
  _Dst_00 = "*** NdisCapEtwEnableCallback called (IsEnabled=%d)\n";
  iVar9 = (int)param_2;
  uVar15 = 0;
  local_164 = 0;
  local_160 = iVar9;
  DbgPrint();
  local_168 = 0;
  if ((param_6 != (longlong *)0x0) && (*(int *)((longlong)param_6 + 0xc) == 0x30ad)) {
    uVar6 = *(uint *)(param_6 + 1);
    puVar7 = (uint *)(ulonglong)uVar6;
    puVar11 = (uint *)0x0;
    local_158 = (uint *)0x0;
    uVar4 = Feature_969905467__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar4 == 0) {
      puVar11 = (uint *)*param_6;
    }
    else if ((uVar6 != 0) && (*param_6 != 0)) {
      param_3 = (uint *)0x746c6946;
      _Dst_00 = (char *)0x200;
      param_2 = puVar7;
      puVar11 = (uint *)ExAllocatePoolWithTag();
      local_158 = puVar11;
      if (puVar11 == (uint *)0x0) {
        puVar7 = (uint *)0x0;
      }
      else {
        param_2 = (uint *)*param_6;
        _Dst_00 = (char *)puVar11;
        param_3 = puVar7;
        memmove(puVar11,param_2,(size_t)puVar7);
      }
    }
    while (uVar6 = (uint)puVar7, 3 < uVar6) {
      uVar8 = uVar6 - 4;
      if (((byte)*puVar11 < 0x22) && (*(ushort *)((longlong)puVar11 + 2) <= uVar8)) {
        uVar4 = Feature_969905467__private_IsEnabledDeviceUsageNoInline();
        if (((int)uVar4 == 0) && ((&g_Rules)[(byte)*puVar11] != 0)) {
          ExFreePoolWithTag((&g_Rules)[(byte)*puVar11],0);
          (&g_Rules)[(byte)*puVar11] = 0;
        }
        _Dst_00 = (char *)puVar11;
        uVar5 = TraceFilterEngineValidateRule((byte *)puVar11,uVar6);
        if ((char)uVar5 == '\0') {
          param_2 = puVar7;
          if ((Microsoft_Windows_NDIS_PacketCaptureEnableBits & 0x20) != 0) {
            param_2 = (uint *)&RuleLoadError;
            McTemplateK0uuhbr2_EtwWriteTransfer
                      (_Dst_00,&RuleLoadError,param_3,(char)*puVar11,
                       *(undefined1 *)((longlong)puVar11 + 1),*(ushort *)((longlong)puVar11 + 2),
                       puVar11 + 1);
          }
          break;
        }
        uVar4 = Feature_969905467__private_IsEnabledDeviceUsageNoInline();
        param_2 = (uint *)((ulonglong)*(ushort *)((longlong)puVar11 + 2) + 4);
        _Dst_00 = (char *)0x200;
        param_3 = (uint *)0x746c6946;
        if ((int)uVar4 == 0) {
          uVar5 = ExAllocatePoolWithTag();
          param_2 = (uint *)&g_Rules;
          (&g_Rules)[(byte)*puVar11] = uVar5;
          _Dst_00 = (char *)(&g_Rules)[(byte)*puVar11];
          if ((uint *)_Dst_00 != (uint *)0x0) {
            param_3 = (uint *)((ulonglong)*(ushort *)((longlong)puVar11 + 2) + 4);
            param_2 = puVar11;
            memmove(_Dst_00,puVar11,(size_t)param_3);
            if ((byte)((char)*puVar11 - 0x12U) < 2) {
              if (4 < *(ushort *)((longlong)puVar11 + 2)) {
                uVar6 = (*(ushort *)((longlong)puVar11 + 2) - 4) + puVar11[1];
                param_2 = (uint *)(ulonglong)uVar6;
                if (g_MaxRuleInspectionOffset < uVar6) {
                  g_MaxRuleInspectionOffset = uVar6;
                }
              }
            }
          }
        }
        else {
          _Dst = (void *)ExAllocatePoolWithTag();
          if (_Dst == (void *)0x0) break;
          memmove(_Dst,puVar11,(ulonglong)*(ushort *)((longlong)puVar11 + 2) + 4);
          param_3 = &local_168;
          NdisAcquireReadWriteLock(&g_RulesLock,1);
          puVar7 = (uint *)(&g_Rules)[(byte)*puVar11];
          (&g_Rules)[(byte)*puVar11] = _Dst;
          if ((byte)((char)*puVar11 - 0x12U) < 2) {
            if (4 < *(ushort *)((longlong)puVar11 + 2)) {
              uVar6 = (*(ushort *)((longlong)puVar11 + 2) - 4) + puVar11[1];
              if (g_MaxRuleInspectionOffset < uVar6) {
                g_MaxRuleInspectionOffset = uVar6;
              }
            }
          }
          param_2 = &local_168;
          _Dst_00 = &g_RulesLock;
          NdisReleaseReadWriteLock();
          if (puVar7 != (uint *)0x0) {
            param_2 = (uint *)0x0;
            ExFreePoolWithTag();
            _Dst_00 = (char *)puVar7;
          }
        }
      }
      uVar2 = *(ushort *)((longlong)puVar11 + 2);
      if (uVar8 < uVar2) break;
      _Dst_00 = (char *)(ulonglong)(uVar2 + 4);
      puVar11 = (uint *)((longlong)puVar11 + (longlong)_Dst_00);
      puVar7 = (uint *)(ulonglong)(uVar8 - uVar2);
    }
    uVar4 = Feature_969905467__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar4 != 0) {
      param_3 = &local_168;
      param_2 = (uint *)CONCAT71((int7)((ulonglong)param_2 >> 8),1);
      _Dst_00 = &g_RulesLock;
      NdisAcquireReadWriteLock();
    }
    g_PacketInspectionRequired = 0;
    puVar12 = &g_Rules;
    iVar9 = 0;
    lVar16 = 0x22;
    do {
      puVar3 = (undefined1 *)*puVar12;
      if (puVar3 != (undefined1 *)0x0) {
        if ((Microsoft_Windows_NDIS_PacketCaptureEnableBits & 8) != 0) {
          param_2 = (uint *)&CaptureRule;
          McTemplateK0uuhbr2_EtwWriteTransfer
                    (_Dst_00,&CaptureRule,param_3,*puVar3,puVar3[1],*(ushort *)(puVar3 + 2),
                     puVar3 + 4);
        }
        uVar6 = (uint)*(byte *)*puVar12;
        _Dst_00 = (char *)(ulonglong)(uVar6 - 3);
        if (uVar6 - 3 != 0) {
          _Dst_00 = (char *)(ulonglong)(uVar6 - 4);
          if (uVar6 - 4 != 0) {
            _Dst_00 = (char *)(ulonglong)(uVar6 - 5);
            if (uVar6 - 5 != 0) {
              _Dst_00 = (char *)(ulonglong)(uVar6 - 0x11);
              if (uVar6 - 0x11 != 0) {
                uVar6 = uVar6 - 0x1a;
                _Dst_00 = (char *)(ulonglong)uVar6;
                if (uVar6 != 0) {
                  if (uVar6 == 6) {
                    uVar4 = Feature_969905467__private_IsEnabledDeviceUsageNoInline();
                    if ((int)uVar4 == 0) {
                      param_2 = &local_164;
                      bVar1 = *(byte *)*puVar12;
                      _Dst_00 = (char *)CONCAT71((int7)((ulonglong)*puVar12 >> 8),bVar1);
                      uVar5 = GetRuleValue(bVar1,param_2);
                      if ((char)uVar5 != '\0') goto LAB_1400071a8;
                    }
                    else {
                      _Dst_00 = (char *)(ulonglong)*(byte *)*puVar12;
                      if ((((*(byte *)*puVar12 < 0x22) &&
                           (lVar10 = (&g_Rules)[(longlong)_Dst_00], lVar10 != 0)) &&
                          (*(char *)(lVar10 + 1) != '\0')) && (*(short *)(lVar10 + 2) == 4)) {
                        local_164 = *(uint *)(lVar10 + 4);
LAB_1400071a8:
                        uVar15 = local_164;
                        if (local_164 < 3) goto LAB_1400071b5;
                      }
                    }
                    local_164 = 0;
                    uVar15 = 0;
                  }
                  else {
                    g_PacketInspectionRequired = 1;
                  }
                }
              }
            }
          }
        }
LAB_1400071b5:
        iVar9 = iVar9 + 1;
      }
      puVar12 = puVar12 + 1;
      lVar16 = lVar16 + -1;
    } while (lVar16 != 0);
    uVar4 = Feature_969905467__private_IsEnabledDeviceUsageNoInline();
    puVar11 = local_158;
    if ((int)uVar4 != 0) {
      param_2 = &local_168;
      _Dst_00 = &g_RulesLock;
      NdisReleaseReadWriteLock();
      if (puVar11 != (uint *)0x0) {
        param_2 = (uint *)0x0;
        ExFreePoolWithTag();
        _Dst_00 = (char *)puVar11;
      }
    }
    if ((Microsoft_Windows_NDIS_PacketCaptureEnableBits & 8) != 0) {
      McTemplateK0q_EtwWriteTransfer(_Dst_00,param_2,param_3,iVar9);
    }
    iVar9 = local_160;
  }
  lVar16 = 0x22;
  if ((uVar15 != g_CaptureType) && (g_CaptureType = uVar15, fFilterRegistered != 0)) {
    NdisFRetryAttach(FilterDriverHandle);
  }
  if (iVar9 == 0) {
    DAT_14000c178 = 0;
    PktCapUpdateCaptureConfig();
  }
  else {
    if (iVar9 == 1) {
      LOCK();
      bVar17 = fFilterRegistered == 0;
      if (bVar17) {
        fFilterRegistered = 1;
      }
      UNLOCK();
      if ((bVar17) && (iVar9 = RegisterFilterDriver(), iVar9 != 0)) {
        LOCK();
        fFilterRegistered = 0;
        UNLOCK();
      }
      DAT_14000c178 = 1;
      PktCapTraceRundown();
      PktCapUpdateCaptureConfig();
      return;
    }
    if (iVar9 == 2) {
      PktCapTraceRundown();
      return;
    }
  }
  if (iVar9 == 0) {
    memset(local_148,0,0x110);
    uVar4 = Feature_969905467__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar4 != 0) {
      NdisAcquireReadWriteLock(&g_RulesLock,1,&local_168);
    }
    lVar13 = 0;
    lVar10 = 0x22;
    do {
      if (*(longlong *)((longlong)&g_Rules + lVar13) != 0) {
        uVar4 = Feature_969905467__private_IsEnabledDeviceUsageNoInline();
        if ((int)uVar4 == 0) {
          ExFreePoolWithTag(*(undefined8 *)((longlong)&g_Rules + lVar13),0);
        }
        else {
          *(undefined8 *)((longlong)local_148 + lVar13) =
               *(undefined8 *)((longlong)&g_Rules + lVar13);
        }
        *(undefined8 *)((longlong)&g_Rules + lVar13) = 0;
      }
      lVar13 = lVar13 + 8;
      lVar10 = lVar10 + -1;
    } while (lVar10 != 0);
    g_MaxRuleInspectionOffset = 0;
    g_PacketInspectionRequired = 0;
    uVar4 = Feature_969905467__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar4 != 0) {
      NdisReleaseReadWriteLock(&g_RulesLock,&local_168);
      plVar14 = local_148;
      do {
        if (*plVar14 != 0) {
          ExFreePoolWithTag(*plVar14,0);
        }
        plVar14 = plVar14 + 1;
        lVar16 = lVar16 + -1;
      } while (lVar16 != 0);
    }
  }
  return;
}



===== TraceFilterEngineValidateRule @ 1400073ac =====

undefined8 TraceFilterEngineValidateRule(byte *param_1,uint param_2)

{
  byte bVar1;
  int iVar2;
  ulonglong in_RAX;
  ushort uVar3;
  undefined1 uVar4;
  ushort uVar5;
  ulonglong uVar6;
  uint uVar7;
  ulonglong uVar8;
  
  if (3 < param_2) {
    uVar5 = *(ushort *)(param_1 + 2);
    uVar6 = (ulonglong)uVar5;
    in_RAX = (ulonglong)param_2 - 4;
    if ((uVar6 <= in_RAX) && (*param_1 < 0x22)) {
      bVar1 = param_1[1];
      iVar2 = (int)CONCAT71((int7)((ulonglong)param_1 >> 8),bVar1);
      in_RAX = (ulonglong)(iVar2 - 8U);
      if ((0x7a < (byte)(iVar2 - 8U)) && (bVar1 < 0x88)) {
        in_RAX = (ulonglong)(iVar2 - 6U);
        if (((iVar2 - 6U & 0x7f) != 0) || (uVar5 == 8)) {
          uVar4 = 0;
          in_RAX = (ulonglong)(iVar2 - 5U);
          if (((iVar2 - 5U & 0x7f) == 0) &&
             ((uVar5 < 2 || ((uVar5 == 2 && (*(short *)(param_1 + 4) != 0)))))) goto LAB_140007490;
          if ((bVar1 - 7 & 0x7f) == 0) {
            if (uVar5 < 3) goto LAB_140007490;
            uVar8 = 0;
            uVar7 = 0;
            if (2 < uVar6) {
              do {
                uVar7 = (uint)uVar8;
                in_RAX = (ulonglong)param_1[uVar8 + 4] << 8;
                uVar3 = (ushort)param_1[(ulonglong)(uVar7 + 1) + 4] | (ushort)in_RAX;
                if (uVar3 == 0) break;
                uVar7 = uVar7 + uVar3 + 2;
                uVar8 = (ulonglong)uVar7;
                in_RAX = uVar8 + 2;
              } while (in_RAX < uVar6);
            }
            if (uVar7 != uVar5) goto LAB_140007490;
          }
          else {
            uVar5 = *(ushort *)(param_1 + 2);
          }
          if ((1 < (byte)(*param_1 - 0x12)) || (4 < uVar5)) {
            uVar4 = 1;
          }
          goto LAB_140007490;
        }
      }
    }
  }
  uVar4 = 0;
LAB_140007490:
  return CONCAT71((int7)(in_RAX >> 8),uVar4);
}



===== TraceFilterEnginepEvaluateBinaryRuleEx @ 1400074a0 =====

bool TraceFilterEnginepEvaluateBinaryRuleEx(longlong param_1,uint *param_2,uint param_3)

{
  byte bVar1;
  ushort uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  longlong lVar8;
  ushort uVar9;
  bool bVar10;
  bool bVar11;
  
  uVar3 = (ulonglong)param_3;
  bVar1 = *(byte *)(param_1 + 1);
  uVar6 = (uint)bVar1;
  if (bVar1 < 0x84) {
    if ((bVar1 == 0x83) || (uVar6 == 3)) {
      if (*(ushort *)(param_1 + 2) != param_3) {
        return false;
      }
      uVar3 = RtlCompareMemory(param_1 + 4,param_2,(uint)*(ushort *)(param_1 + 2));
      if (*(char *)(param_1 + 1) == '\x03') {
        return uVar3 == *(ushort *)(param_1 + 2);
      }
      return uVar3 != *(ushort *)(param_1 + 2);
    }
    iVar5 = uVar6 - 4;
  }
  else {
    iVar5 = uVar6 - 0x84;
  }
  if (iVar5 == 0) {
    if (*(ushort *)(param_1 + 2) != param_3) {
      return false;
    }
    bVar10 = false;
    if ((param_3 < 5) && (*(ushort *)(param_1 + 2) < 5)) {
      if (param_3 == 4) {
        uVar6 = *(uint *)(param_1 + 4);
        uVar7 = *param_2;
      }
      else if (param_3 == 2) {
        uVar6 = (uint)*(ushort *)(param_1 + 4);
        uVar7 = (uint)(ushort)*param_2;
      }
      else {
        if (param_3 != 1) goto LAB_1400076ef;
        uVar6 = (uint)*(byte *)(param_1 + 4);
        uVar7 = (uint)(byte)*param_2;
      }
      if ((uVar7 & uVar6) == uVar6) {
        bVar10 = true;
      }
    }
LAB_1400076ef:
    bVar11 = bVar1 == 4;
    goto LAB_1400076f3;
  }
  if (iVar5 == 1) {
    if ((ulonglong)*(ushort *)(param_1 + 2) < uVar3 + 2) {
      return false;
    }
    uVar2 = *(ushort *)(param_1 + 4);
    bVar10 = false;
    if ((*(ushort *)(param_1 + 2) - 2) / (uint)uVar2 == param_3) {
      lVar8 = param_1 + 6;
      uVar9 = 0;
      if (uVar2 != 0) {
        do {
          if (bVar10 != false) break;
          uVar4 = RtlCompareMemory(lVar8,param_2,uVar3);
          bVar10 = uVar4 == uVar3;
          lVar8 = lVar8 + uVar3;
          uVar9 = uVar9 + 1;
        } while (uVar9 < uVar2);
      }
    }
    if (*(char *)(param_1 + 1) == '\x05') {
      return bVar10;
    }
    return bVar10 == false;
  }
  if (iVar5 != 2) {
    if (iVar5 != 3) {
      return true;
    }
    uVar2 = *(ushort *)(param_1 + 2);
    bVar10 = false;
    lVar8 = param_1 + 4;
    uVar4 = 0;
    do {
      iVar5 = (int)uVar4;
      if ((((ulonglong)uVar2 <= uVar4 + 2) ||
          (uVar9 = CONCAT11(*(undefined1 *)(uVar4 + lVar8),
                            *(undefined1 *)((ulonglong)(iVar5 + 1) + lVar8)), uVar9 == 0)) ||
         ((ulonglong)uVar2 < (ulonglong)uVar9 + 2 + uVar4)) break;
      if (uVar9 == param_3) {
        uVar4 = RtlCompareMemory((ulonglong)(iVar5 + 2) + lVar8,param_2,uVar3);
        bVar10 = uVar4 == uVar3;
      }
      uVar4 = (ulonglong)(iVar5 + 2 + (uint)uVar9);
    } while (bVar10 == false);
    if (*(char *)(param_1 + 1) == '\a') {
      return bVar10;
    }
    return bVar10 == false;
  }
  if (*(short *)(param_1 + 2) != 8) {
    return false;
  }
  bVar10 = false;
  if (param_3 < 5) {
    if (param_3 == 4) {
      uVar6 = *param_2;
    }
    else if (param_3 == 2) {
      uVar6 = (uint)(ushort)*param_2;
    }
    else {
      if (param_3 != 1) goto LAB_140007623;
      uVar6 = (uint)(byte)*param_2;
    }
    if ((*(uint *)(param_1 + 4) <= uVar6) && (uVar6 <= *(uint *)(param_1 + 8))) {
      bVar10 = true;
    }
  }
LAB_140007623:
  bVar11 = bVar1 == 6;
LAB_1400076f3:
  if (bVar11) {
    return bVar10;
  }
  return bVar10 == false;
}



===== RegUtilQuerySTRINGValue @ 140007720 =====

int RegUtilQuerySTRINGValue(undefined8 param_1,ulonglong param_2,ushort *param_3)

{
  int iVar1;
  void *_Dst;
  uint uVar2;
  ulonglong local_res10;
  undefined8 local_28;
  undefined8 uStack_20;
  
  local_res10 = param_2 & 0xffffffff00000000;
  local_28 = 0;
  uStack_20 = 0;
  if (param_3 == (ushort *)0x0) {
    iVar1 = -0x3fffff0f;
  }
  else {
    RtlInitUnicodeString(&local_28,L"ComputerName");
    uVar2 = (uint)*param_3 * 2 + 0x12;
    _Dst = (void *)ExAllocatePoolWithTag(0x200,uVar2,0x746c6946);
    if (_Dst == (void *)0x0) {
      iVar1 = -0x3fffffe9;
    }
    else {
      memset(_Dst,0,(ulonglong)uVar2);
      iVar1 = ZwQueryValueKey(param_1,&local_28,2,_Dst,uVar2,&local_res10);
      if (((iVar1 == -0x7ffffffb) || (iVar1 == -0x3fffffdd)) ||
         (*(void **)(param_3 + 4) == (void *)0x0)) {
        *param_3 = (ushort)((uint)local_res10 >> 1);
      }
      else if (iVar1 == 0) {
        if (*(int *)((longlong)_Dst + 4) == 1) {
          memmove(*(void **)(param_3 + 4),(void *)((longlong)_Dst + 0xc),(ulonglong)*param_3 * 2);
          *(undefined2 *)(*(longlong *)(param_3 + 4) + (ulonglong)*param_3 * 2) = 0;
        }
        else {
          iVar1 = -0x3fffffc2;
        }
      }
      ExFreePoolWithTag(_Dst,0);
    }
  }
  return iVar1;
}



===== __GSHandlerCheck @ 140007878 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 14000789c =====

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



===== __security_check_cookie @ 140007910 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140007950 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 140007980 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140007980. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1400079b0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memmove @ 140007a00 =====

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



===== memset @ 140007d00 =====

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



===== __memset_repmovs @ 140007e40 =====

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



===== __memset_query @ 140007ec0 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140007f40 =====

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



===== __memset_spec_ermsb_repmovsb @ 140008080 =====

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



===== __memset_spec_plain @ 140008100 =====

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



===== wil_details_EvaluateFeatureDependencies @ 14000f008 =====

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
    if (*ppuVar2 != (undefined *)0x0) goto joined_r0x00014000f043;
    ppuVar2 = ppuVar2 + 1;
  } while (ppuVar2 < &wil_details_featureDescriptors_z);
LAB_14000f0bd:
  while( true ) {
    if (&UNK_14000b0f7 < ppuVar3) {
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
      if (&UNK_14000b0f7 < ppuVar3) {
        return;
      }
      if (*ppuVar3 != puVar4) break;
      ppuVar3 = ppuVar3 + 1;
    }
  } while( true );
joined_r0x00014000f043:
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
      if (&UNK_14000b0f7 < ppuVar2) goto LAB_14000f0bd;
      if (*ppuVar2 != (undefined *)0x0) break;
      ppuVar2 = ppuVar2 + 1;
    }
  }
  goto LAB_14000f0bd;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 14000f0f8 =====

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
          if (puVar1 == (undefined8 *)0x0) goto LAB_14000f190;
          if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
             (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
          if ((uVar4 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
            uVar4 = 0;
            goto LAB_14000f190;
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
LAB_14000f190:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 14000f1e0 =====

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
              if (&UNK_14000b0f7 < ppuVar2) {
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



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 14000f260 =====

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
    if (*ppuVar3 != (undefined *)0x0) goto LAB_14000f35d;
  }
LAB_14000f366:
  wil_details_EvaluateFeatureDependencies();
  return;
LAB_14000f35d:
  if (ppuVar3 == (undefined **)0x0) goto LAB_14000f366;
  if (((*(char *)((longlong)ppuVar3 + 0x1d) == '\0') &&
      (*(char *)((longlong)ppuVar3 + 0x1e) == '\0')) &&
     (*(char *)((longlong)ppuVar3 + 0x1c) == '\0')) {
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    iVar1 = RtlQueryFeatureConfiguration(*(undefined4 *)(ppuVar3 + 3),1,&local_28,&local_20);
    if ((iVar1 == -0x7fffffde) || (iVar1 == -0x3ffffddb)) {
LAB_14000f32e:
      uVar2 = 0x206;
    }
    else {
      if (iVar1 == 0) {
        uVar2 = (local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0;
      }
      else {
        if (iVar1 != 0x117) goto LAB_14000f32e;
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
    if (&UNK_14000b0f7 < ppuVar3) goto LAB_14000f366;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_14000f35d;
}



===== entry @ 140010010 =====

void entry(longlong param_1,ushort *param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(longlong param_1,ushort *param_2)

{
  int iVar1;
  ulonglong uVar2;
  undefined *puVar3;
  undefined1 uVar4;
  undefined8 *puVar5;
  
  uVar4 = 0;
  wil_InitializeFeatureStaging();
  _DriverRegistryPath = 0;
  puVar3 = (undefined *)0x1;
  _DAT_14000c742 = *param_2;
  puVar5 = (undefined8 *)0x746c6946;
  FilterDriverObject = param_1;
  DAT_14000c748 = ExAllocatePoolWithTag(1,(ulonglong)*param_2 + 2);
  if (DAT_14000c748 == 0) {
    uVar4 = 0xb5;
    iVar1 = -0x3fffff66;
  }
  else {
    RtlCopyUnicodeString(&DriverRegistryPath,param_2);
    *(code **)(param_1 + 0x68) = FilterUnload;
    FilterDriverHandle = 0;
    KeInitializeSpinLock(&FilterListLock);
    _DAT_14000c738 = &FilterModuleList;
    FilterModuleList = &FilterModuleList;
    uVar2 = Feature_969905467__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar2 != 0) {
      NdisInitializeReadWriteLock(&g_RulesLock);
    }
    KeInitializeGuardedMutex(&DAT_14000c198);
    puVar5 = &PktCap;
    _DAT_14000c188 = &DAT_14000c180;
    puVar3 = &PktCapProviderNotify;
    DAT_14000c180 = &DAT_14000c180;
    NmrRegisterProvider(&PktCapProviderNotify,0);
    iVar1 = McGenEventRegister_EtwRegister();
    if ((Microsoft_Windows_NDIS_PacketCaptureEnableBits & 0x10) != 0) {
      McTemplateK0zzzz_EtwWriteTransfer(puVar3,&DriverLoad);
    }
    if (iVar1 == 0) {
      return 0;
    }
  }
  if ((Microsoft_Windows_NDIS_PacketCaptureEnableBits & 0x20) != 0) {
    McTemplateK0qqq_EtwWriteTransfer(puVar3,&DriverLoadError,puVar5,iVar1,uVar4,0);
  }
  McGenEventUnregister_EtwUnregister();
  PktCapProviderUninitialize();
  if (g_wil_details_featureChangeNotification != 0) {
    RtlUnregisterFeatureConfigurationChangeNotification();
    g_wil_details_featureChangeNotification = 0;
  }
  if (g_wil_details_featureUsageProvider != 0) {
    RtlUnregisterFeatureUsageProvider();
    g_wil_details_featureUsageProvider = 0;
  }
  g_wil_details_isFeatureStagingInitialized = 0;
  return iVar1;
}



===== wil_InitializeFeatureStaging @ 140010248 =====

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
      if (*ppuVar3 != (undefined *)0x0) goto LAB_1400102cf;
    }
LAB_140010309:
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
LAB_1400102cf:
  if (ppuVar3 == (undefined **)0x0) goto LAB_140010309;
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
    goto LAB_140010309;
  }
  ppuVar3 = ppuVar3 + 7;
  while( true ) {
    if (&UNK_14000b0f7 < ppuVar3) goto LAB_140010309;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_1400102cf;
}



===== wil_details_PopulateInitialConfiguredFeatureStates @ 14001035c =====

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
            if (&UNK_14000b0f7 < ppuVar4) {
              return;
            }
            if (*ppuVar4 != (undefined *)0x0) break;
            ppuVar4 = ppuVar4 + 1;
          }
        } while (ppuVar4 != (undefined **)0x0);
        return;
      }
      if (iVar3 == -0x3ffffddb) goto LAB_140010446;
      if (iVar3 == 0) {
        local_28 = (ulonglong)(((local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0) << 3 | 0x206);
      }
      else {
        if (iVar3 != 0x117) goto LAB_140010446;
        local_28 = (ulonglong)((local_20._4_4_ & 0x80) << 3 | 0x206);
      }
    }
    else {
LAB_140010446:
      local_28 = 0x206;
    }
    puVar1 = (ulonglong *)*ppuVar4;
    ppuVar4 = ppuVar4 + 7;
    *puVar1 = local_28;
    while( true ) {
      if (&UNK_14000b0f7 < ppuVar4) {
        return;
      }
      if (*ppuVar4 != (undefined *)0x0) break;
      ppuVar4 = ppuVar4 + 1;
    }
  } while( true );
}


