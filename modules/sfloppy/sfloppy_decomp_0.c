
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



===== RtlStringCbPrintfA @ 140001020 =====

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



===== RtlStringCbPrintfW @ 140001094 =====

undefined8
RtlStringCbPrintfW(wchar_t *param_1,ulonglong param_2,wchar_t *param_3,undefined8 param_4)

{
  int iVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 local_res20;
  
  uVar2 = param_2 >> 1;
  if (uVar2 - 1 < 0x7fffffff) {
    uVar2 = uVar2 - 1;
    uVar3 = 0;
    local_res20 = param_4;
    iVar1 = _vsnwprintf(param_1,uVar2,param_3,(va_list)&local_res20);
    if ((iVar1 < 0) || (uVar2 < (ulonglong)(longlong)iVar1)) {
      uVar3 = 0x80000005;
    }
    else if ((longlong)iVar1 != uVar2) {
      return 0;
    }
    param_1[uVar2] = L'\0';
  }
  else {
    uVar3 = 0xc000000d;
    if (uVar2 != 0) {
      *param_1 = L'\0';
    }
  }
  return uVar3;
}



===== ScsiFlopDeviceControl @ 140001110 =====

ulonglong ScsiFlopDeviceControl(char *param_1,longlong param_2)

{
  char cVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  longlong *plVar6;
  uint uVar7;
  longlong lVar8;
  ulonglong uVar9;
  longlong lVar10;
  longlong lVar11;
  ulonglong uVar12;
  uint uVar13;
  int *piVar14;
  
  lVar10 = *(longlong *)(param_1 + 0x40);
  *(undefined8 *)(param_2 + 0x38) = 0;
  lVar11 = *(longlong *)(param_2 + 0xb8);
  lVar8 = ExAllocatePool2(0x40,0x58,0x706f4653);
  if (lVar8 == 0) {
    *(undefined4 *)(param_2 + 0x30) = 0xc000009a;
    ClassReleaseRemoveLock(param_1,param_2);
    ClassCompleteRequest(param_1,param_2,0);
    return 0xc000009a;
  }
  iVar3 = *(int *)(lVar11 + 0x18);
  if (iVar3 == 0x70000) {
    if (*(char *)(*(longlong *)(lVar10 + 0x210) + 0x18) == '\a') {
LAB_14000154d:
      uVar9 = USBFlopGetMediaTypes(param_1,param_2);
      uVar7 = (uint)uVar9;
      goto LAB_140001555;
    }
    if (*(uint *)(lVar11 + 8) < 0x18) goto LAB_140001200;
    uVar9 = DetermineMediaType((longlong)param_1);
    uVar12 = uVar9 & 0xffffffff;
    if (-1 < (int)uVar9) {
      memcpy(*(void **)(param_2 + 0x18),(void *)(lVar10 + 0x228),0x18);
      *(undefined8 *)(param_2 + 0x38) = 0x18;
LAB_1400015b3:
      uVar12 = 0;
      goto LAB_1400015b5;
    }
    *(undefined8 *)(param_2 + 0x38) = 0;
    *(int *)(param_2 + 0x30) = (int)uVar9;
  }
  else {
    if (iVar3 == 0x70014) {
      plVar6 = *(longlong **)(param_2 + 0x18);
      if (*(uint *)(lVar11 + 0x10) < 0x10) {
        uVar12 = 0xc0000004;
      }
      else {
        lVar11 = *plVar6;
        if (((lVar11 <= *(longlong *)(lVar10 + 0x90)) && (-1 < lVar11)) &&
           ((ulonglong)*(uint *)(plVar6 + 1) <= (ulonglong)(*(longlong *)(lVar10 + 0x90) - lVar11)))
        {
          *(undefined1 *)(lVar8 + 10) = 10;
          *(undefined1 *)(lVar8 + 0x48) = 0x2f;
          lVar11 = *(longlong *)(lVar10 + 0x98) + *plVar6 >> (*(byte *)(lVar10 + 0x282) & 0x3f);
          uVar7 = *(uint *)(plVar6 + 1) >> (*(byte *)(lVar10 + 0x282) & 0x1f);
          *(char *)(lVar8 + 0x4a) = (char)((ulonglong)lVar11 >> 0x18);
          uVar13 = uVar7 & 0xffff;
          *(char *)(lVar8 + 0x50) = (char)uVar13;
          *(char *)(lVar8 + 0x4b) = (char)((ulonglong)lVar11 >> 0x10);
          *(char *)(lVar8 + 0x4d) = (char)lVar11;
          *(char *)(lVar8 + 0x4c) = (char)((ulonglong)lVar11 >> 8);
          *(char *)(lVar8 + 0x4f) = (char)(uVar7 >> 8);
          *(uint *)(lVar8 + 0x14) = (uVar13 + 0x7f >> 7) * *(int *)(lVar10 + 0x248);
          uVar9 = ClassSendSrbAsynchronous(param_1,lVar8,param_2,0,0,0);
          return uVar9;
        }
        uVar12 = 0xc0000015;
      }
      goto LAB_1400015b5;
    }
    if (iVar3 == 0x70024) {
      if (*(int *)(lVar10 + 0x230) == 0x19) {
        uVar12 = 0xc00000a2;
        goto LAB_1400015b5;
      }
      lVar10 = ExAllocatePool2(0x48,0xc0,0x706f4653);
      if (lVar10 == 0) {
        uVar12 = 0xc000009a;
        goto LAB_1400015b5;
      }
      uVar7 = ClassModeSense(param_1,lVar10,0xc0,0x3f);
      if ((uVar7 < 4) && (uVar7 = ClassModeSense(param_1,lVar10,0xc0,0x3f), uVar7 < 4)) {
        uVar12 = 0xc0000185;
        ExFreePoolWithTag(lVar10,0);
        goto LAB_1400015b5;
      }
      cVar1 = *(char *)(lVar10 + 2);
      ExFreePoolWithTag(lVar10,0);
      uVar12 = (ulonglong)((int)cVar1 >> 7 & 0xc00000a2);
    }
    else if (iVar3 == 0x70c00) {
      if (*(char *)(*(longlong *)(lVar10 + 0x210) + 0x18) == '\a') goto LAB_14000154d;
      uVar7 = DetermineDriveType((longlong)param_1);
      if (uVar7 == 7) {
        uVar12 = 0xc0000014;
        goto LAB_1400015b5;
      }
      uVar13 = *(uint *)(&DAT_14000508c + (ulonglong)uVar7 * 8);
      uVar7 = (&DriveMediaLimits)[(ulonglong)uVar7 * 2];
      uVar4 = *(uint *)(lVar11 + 8);
      if (uVar4 < 0x18) {
        uVar12 = 0xc0000023;
        goto LAB_1400015b5;
      }
      uVar12 = 0;
      if ((ulonglong)uVar4 < (ulonglong)((longlong)(int)((uVar7 - uVar13) + 1) * 0x18)) {
        uVar12 = 0x80000005;
        uVar7 = (uVar4 / 0x18 - 1) + uVar13;
      }
      piVar14 = *(int **)(param_2 + 0x18);
      for (uVar9 = (ulonglong)uVar13 & 0xff; (uint)uVar9 <= (uVar7 & 0xff);
          uVar9 = (ulonglong)((uint)uVar9 + 1)) {
        piVar14[2] = (&DriveMediaConstants)[uVar9 * 3];
        uVar2 = (&DAT_1400050c8)[uVar9 * 6];
        piVar14[1] = 0;
        *piVar14 = uVar2 + 1;
        piVar14[3] = (uint)(byte)(&DAT_1400050ca)[uVar9 * 0xc];
        piVar14[4] = (uint)(byte)(&DAT_1400050c6)[uVar9 * 0xc];
        piVar14[5] = (uint)*(ushort *)(&DAT_1400050c4 + uVar9 * 0xc);
        *(longlong *)(param_2 + 0x38) = *(longlong *)(param_2 + 0x38) + 0x18;
        piVar14 = piVar14 + 6;
      }
    }
    else if (iVar3 == 0x74004) {
      if (*(char *)(*(longlong *)(lVar10 + 0x210) + 0x18) == '\a') {
        USBFlopGetMediaTypes(param_1,0);
      }
      else {
        uVar9 = DetermineMediaType((longlong)param_1);
        uVar12 = uVar9 & 0xffffffff;
        if ((int)uVar9 < 0) goto LAB_14000157a;
      }
      if (*(int *)(lVar10 + 0x230) != 0xd) {
LAB_140001290:
        ExFreePoolWithTag(lVar8,0);
        uVar9 = ClassDeviceControl(param_1,param_2);
        return uVar9;
      }
      uVar12 = 0xc0000010;
    }
    else {
      if (iVar3 != 0x7c018) goto LAB_140001290;
      if (*(char *)(*(longlong *)(lVar10 + 0x210) + 0x18) != '\a') {
        if (0x13 < *(uint *)(lVar11 + 0x10)) {
          puVar5 = *(uint **)(param_2 + 0x18);
          uVar7 = FlCheckFormatParameters((longlong)param_1,puVar5);
          if ((char)uVar7 != '\0') {
            if (*puVar5 == 4) {
              uVar7 = FlopticalFormatMedia(param_1,(longlong)puVar5);
            }
            else {
              if ((puVar5[1] != 0) || (puVar5[3] != 0)) goto LAB_1400015b3;
              uVar7 = FormatMedia(param_1,*puVar5);
            }
            goto LAB_140001555;
          }
        }
LAB_140001200:
        uVar12 = 0xc000000d;
        goto LAB_1400015b5;
      }
      uVar7 = USBFlopFormatTracks((longlong)param_1,param_2);
LAB_140001555:
      uVar12 = (ulonglong)uVar7;
    }
  }
LAB_14000157a:
  if ((int)uVar12 == -0x7fffffea) {
    uVar7 = 0x80000016;
    if ((*(byte *)(lVar11 + 2) & 2) != 0) {
      uVar7 = 0xc0000185;
    }
    uVar12 = (ulonglong)uVar7;
  }
LAB_1400015b5:
  iVar3 = (int)uVar12;
  *(int *)(param_2 + 0x30) = iVar3;
  if ((((iVar3 + 0x3fffff5eU < 2) || (iVar3 == -0x3fffff4b)) || (iVar3 + 0x3fffffeeU < 3)) ||
     (iVar3 == -0x7fffffea)) {
    IoSetHardErrorOrVerifyDevice(param_2,param_1);
  }
  ClassReleaseRemoveLock(param_1,param_2);
  ClassCompleteRequest(param_1,param_2,0);
  ExFreePoolWithTag(lVar8,0);
  return uVar12;
}



===== ScsiFlopInitDevice @ 140001650 =====

undefined8 ScsiFlopInitDevice(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  undefined8 uVar6;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  lVar2 = *(longlong *)(lVar1 + 0x60);
  lVar5 = ExAllocatePool2(0x48,0x12,0x706f4653);
  if (lVar5 == 0) {
    uVar6 = 0xc000009a;
  }
  else {
    *(longlong *)(lVar1 + 0x240) = lVar5;
    ClassInitializeSrbLookasideList(lVar1,4);
    ClassInitializeMediaChangeDetection(lVar1,"SFloppy");
    iVar3 = ClassQueryTimeOutRegistryValue(param_1);
    lVar2 = lVar2 + 8;
    iVar4 = 0x14;
    if (iVar3 != 0) {
      iVar4 = iVar3;
    }
    *(int *)(lVar1 + 0x248) = iVar4;
    *(undefined8 *)(lVar1 + 0x98) = 0;
    *(undefined8 *)(lVar1 + 0x228) = 0;
    *(undefined8 *)(lVar1 + 0x230) = 0;
    *(undefined8 *)(lVar1 + 0x238) = 0;
    RtlInitUnicodeString(lVar2,0);
    iVar4 = IoRegisterDeviceInterface
                      (*(undefined8 *)(lVar1 + 0x200),&GUID_DEVINTERFACE_FLOPPY,0,lVar2);
    if (iVar4 < 0) {
      RtlFreeUnicodeString(lVar2);
      RtlInitUnicodeString(lVar2,0);
    }
    uVar6 = 0;
  }
  return uVar6;
}



===== ScsiFlopProcessError @ 140001770 =====

void ScsiFlopProcessError(longlong param_1,longlong param_2,undefined4 *param_3)

{
  longlong lVar1;
  undefined4 *puVar2;
  longlong lVar3;
  byte bVar4;
  uint uVar5;
  longlong *plVar6;
  longlong lVar7;
  undefined8 uVar8;
  longlong *_Dst;
  ulonglong uVar9;
  ulonglong uVar10;
  undefined8 local_res8;
  
  uVar9 = 1;
  lVar1 = *(longlong *)(param_1 + 0x40);
  lVar7 = *(longlong *)(param_2 + 0x20);
  puVar2 = *(undefined4 **)(lVar1 + 0x60);
  local_res8 = 1;
  if (-1 < *(char *)(param_2 + 3)) {
    return;
  }
  *puVar2 = 7;
  *(undefined1 *)(puVar2 + 1) = 0;
  *(undefined4 *)(lVar1 + 0x230) = 0;
  if (*(char *)(*(longlong *)(lVar1 + 0x210) + 0x18) == '\a') {
    *(undefined4 *)(lVar1 + 0x2b8) = 0;
    bVar4 = *(byte *)(lVar7 + 2) & 0xf;
    if (bVar4 != 6) {
      if (bVar4 == 3) {
        *param_3 = 0xc0000014;
        return;
      }
      return;
    }
    if (*(char *)(lVar7 + 0xc) != '(') {
      return;
    }
    plVar6 = (longlong *)ExAllocatePool2(0x40,0xc0,0x706f4653);
    if (plVar6 == (longlong *)0x0) {
      return;
    }
    _Dst = plVar6 + 1;
    memset(_Dst,0,0x58);
    *(byte *)((longlong)plVar6 + 0x54) = *(byte *)((longlong)plVar6 + 0x54) | 1;
    uVar8 = 9;
    *(undefined4 *)((longlong)plVar6 + 0x14) = 0x20;
    *(undefined1 *)(plVar6 + 10) = 0x1b;
  }
  else {
    bVar4 = *(byte *)(lVar7 + 2) & 0xf;
    if (((bVar4 != 2) || (*(char *)(lVar7 + 0xd) != '\x02')) && (bVar4 != 6)) {
      return;
    }
    uVar5 = *(uint *)(param_1 + 0x98);
    if (uVar5 == 0) {
      uVar10 = 1;
      uVar5 = 0xeb;
    }
    else {
      uVar9 = (ulonglong)uVar5;
      uVar10 = (ulonglong)uVar5;
      uVar5 = uVar5 + 0xea;
      if (uVar5 < 0xea) {
        return;
      }
    }
    plVar6 = (longlong *)ExAllocatePool2(0x40,uVar5,0x706f4653);
    if (plVar6 == (longlong *)0x0) {
      return;
    }
    _Dst = plVar6 + 1;
    memset(_Dst,0,0x58);
    *(undefined4 *)(plVar6 + 3) = 0x2a;
    *(undefined4 *)((longlong)plVar6 + 0x14) = 0x68;
    *(undefined1 *)(plVar6 + 10) = 0x1a;
    *(undefined1 *)((longlong)plVar6 + 0x54) = 0x2a;
    plVar6[4] = (longlong)plVar6 + uVar10 + 0xbf & -uVar9;
    uVar8 = 3;
    *(byte *)((longlong)plVar6 + 0x52) = *(byte *)((longlong)plVar6 + 0x52) & 0xee | 0x2e;
  }
  *(undefined1 *)((longlong)_Dst + 10) = 6;
  *plVar6 = param_1;
  *(undefined2 *)_Dst = 0x58;
  *(undefined1 *)((longlong)_Dst + 2) = 0;
  *(undefined4 *)((longlong)_Dst + 0x14) = *(undefined4 *)(lVar1 + 0x248);
  lVar7 = IoBuildAsynchronousFsdRequest(uVar8,param_1,_Dst[3],(int)_Dst[2],&local_res8,0);
  if (lVar7 == 0) {
    ExFreePoolWithTag(plVar6,0);
  }
  else {
    lVar3 = *(longlong *)(lVar7 + 0xb8);
    *(code **)(lVar3 + -0x10) = ClassAsynchronousCompletion_exref;
    *(longlong **)(lVar3 + -8) = plVar6;
    *(undefined1 *)(lVar3 + -0x45) = 0xe0;
    ClassAcquireRemoveLockEx(param_1,lVar7,"onecore\\drivers\\storage\\sfloppy\\floppy.c",0xa0b);
    lVar3 = *(longlong *)(lVar7 + 0xb8);
    *(undefined1 *)(lVar3 + -0x48) = 0xf;
    _Dst[6] = lVar7;
    *(longlong **)(lVar3 + -0x40) = _Dst;
    IofCallDriver(*(undefined8 *)(lVar1 + 0x10),lVar7);
  }
  return;
}



===== ScsiFlopReadWriteVerification @ 1400019e0 =====

void ScsiFlopReadWriteVerification(longlong param_1,longlong param_2)

{
  *(uint *)(param_2 + 0x30) =
       -(uint)((*(int *)(*(longlong *)(param_1 + 0x40) + 0x23c) - 1U &
               *(uint *)(*(longlong *)(param_2 + 0xb8) + 8)) != 0) & 0xc000000d;
  return;
}



===== ScsiFlopStopDevice @ 140001a10 =====

undefined8 ScsiFlopStopDevice(void)

{
  return 0;
}



===== __GSHandlerCheck @ 140001a1c =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 140001a40 =====

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



===== __cpu_features_init @ 140001ab0 =====

/* WARNING: Removing unreachable block (ram,0x000140001b1a) */
/* WARNING: Removing unreachable block (ram,0x000140001ac9) */
/* WARNING: Removing unreachable block (ram,0x000140001aba) */

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



===== _guard_check_icall @ 140001b80 =====

void _guard_check_icall(void)

{
  return;
}



===== __security_check_cookie @ 140001ba0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140001be0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140001be0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140001c10 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcpy @ 140001c80 =====

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



===== memset @ 140001f80 =====

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



===== __memset_repmovs @ 1400020c0 =====

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



===== __memset_query @ 140002140 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1400021c0 =====

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



===== __memset_spec_ermsb_repmovsb @ 140002300 =====

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



===== __memset_spec_plain @ 140002380 =====

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



===== DetermineDriveType @ 140008008 =====

uint DetermineDriveType(longlong param_1)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  short *psVar4;
  uint *puVar5;
  uint uVar6;
  
  uVar6 = **(uint **)(*(longlong *)(param_1 + 0x40) + 0x60);
  if (uVar6 != 7) {
    return uVar6;
  }
  lVar2 = ExAllocatePool2(0x48,0xc0,0x706f4653);
  uVar6 = 0;
  if (lVar2 != 0) {
    uVar1 = ClassModeSense(param_1,lVar2,0xc0,5);
    if ((((3 < uVar1) || (uVar1 = ClassModeSense(param_1,lVar2,0xc0,5), 3 < uVar1)) &&
        (lVar3 = ClassFindModePage(lVar2,uVar1,5,1), lVar3 != 0)) && (9 < *(byte *)(lVar3 + 1) + 2))
    {
      uVar1 = 0;
      psVar4 = &DAT_1400050c8;
      do {
        if ((((char)psVar4[1] == *(char *)(lVar3 + 4)) &&
            (*psVar4 ==
             (short)(CONCAT11(*(undefined1 *)(lVar3 + 8),*(undefined1 *)(lVar3 + 9)) + -1))) &&
           ((char)psVar4[-1] == *(char *)(lVar3 + 5))) {
          ExFreePoolWithTag(lVar2,0);
          puVar5 = &DriveMediaLimits;
          do {
            if (*puVar5 == uVar1) {
              return uVar6;
            }
            uVar6 = uVar6 + 1;
            puVar5 = puVar5 + 2;
          } while (uVar6 < 7);
          return 7;
        }
        uVar1 = uVar1 + 1;
        psVar4 = psVar4 + 6;
      } while (uVar1 < 0x1b);
    }
    ExFreePoolWithTag(lVar2,0);
  }
  return 7;
}



===== DetermineMediaType @ 140008168 =====

ulonglong DetermineMediaType(longlong param_1)

{
  longlong lVar1;
  ulonglong uVar2;
  longlong lVar3;
  ulonglong uVar4;
  longlong lVar5;
  longlong lVar6;
  ushort *puVar7;
  uint uVar8;
  
  lVar6 = *(longlong *)(param_1 + 0x40);
  uVar2 = ClassReadDriveCapacity();
  uVar4 = uVar2 & 0xffffffff;
  if ((int)uVar2 < 0) {
    *(undefined4 *)(lVar6 + 0x230) = 0;
    return uVar2;
  }
  puVar7 = &DAT_1400051fc;
  uVar8 = 0x1a;
  do {
    if (((puVar7[2] + 1) * (uint)(byte)puVar7[3] * (uint)(byte)puVar7[1] * (uint)*puVar7 <=
         *(uint *)(lVar6 + 0x90)) && ((uint)*puVar7 == *(uint *)(lVar6 + 0x23c))) {
      uVar2 = (ulonglong)uVar8;
      *(undefined4 *)(lVar6 + 0x230) = (&DriveMediaConstants)[uVar2 * 3];
      *(uint *)(lVar6 + 0x234) = (uint)(byte)(&DAT_1400050ca)[uVar2 * 0xc];
      *(uint *)(lVar6 + 0x238) = (uint)(byte)(&DAT_1400050c6)[uVar2 * 0xc];
      *(uint *)(lVar6 + 0x228) = (ushort)(&DAT_1400050c8)[uVar2 * 6] + 1;
      break;
    }
    puVar7 = puVar7 + -6;
    uVar8 = uVar8 - 1;
  } while (-1 < (int)uVar8);
  if (uVar8 == 0xffffffff) {
    *(undefined4 *)(lVar6 + 0x230) = 0;
  }
  else {
    lVar1 = *(longlong *)(lVar6 + 0x60);
    lVar3 = ExAllocatePool2(0x40,*(undefined4 *)(lVar6 + 0x23c),0x706f4653);
    if (lVar3 != 0) {
      lVar5 = ExAllocatePool2(0x40,0x58,0x706f4653);
      if (lVar5 != 0) {
        *(undefined1 *)(lVar5 + 10) = 10;
        *(undefined1 *)(lVar5 + 0x48) = 0x28;
        *(undefined1 *)(lVar5 + 0x4d) = 0;
        *(undefined1 *)(lVar5 + 0x50) = 1;
        *(undefined4 *)(lVar5 + 0x14) = *(undefined4 *)(lVar6 + 0x248);
        uVar8 = ClassSendSrbSynchronous(param_1,lVar5,lVar3,*(undefined4 *)(lVar6 + 0x23c),0);
        uVar4 = (ulonglong)uVar8;
        if ((-1 < (int)uVar8) && (lVar6 = RtlCompareMemory(lVar3 + 3,"MSDMF3.",7), lVar6 == 7)) {
          *(undefined1 *)(lVar1 + 4) = 1;
        }
        ExFreePoolWithTag(lVar3,0);
        ExFreePoolWithTag(lVar5,0);
        goto LAB_140008330;
      }
      ExFreePoolWithTag(lVar3,0);
    }
    uVar4 = 0xc0000017;
  }
LAB_140008330:
  return uVar4;
}



===== FlCheckFormatParameters @ 140008350 =====

uint FlCheckFormatParameters(longlong param_1,uint *param_2)

{
  uint uVar1;
  uint *puVar2;
  longlong lVar3;
  uint uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  
  uVar1 = DetermineDriveType(param_1);
  if (uVar1 == 7) {
    uVar4 = 0;
    if (DriveMediaConstants != *param_2) {
      puVar2 = &DriveMediaConstants;
      uVar4 = 0;
      do {
        if (0x14000517f < (longlong)puVar2) break;
        puVar2 = puVar2 + 3;
        uVar4 = uVar4 + 1;
      } while (*puVar2 != *param_2);
    }
  }
  else {
    uVar4 = (&DriveMediaLimits)[(ulonglong)uVar1 * 2];
    uVar5 = (ulonglong)(int)uVar4;
    puVar2 = &DriveMediaConstants + uVar5 * 3;
    if (*puVar2 != *param_2) {
      uVar6 = uVar5;
      do {
        uVar4 = (uint)uVar5;
        if ((longlong)uVar6 <= (longlong)*(int *)(&DAT_14000508c + (ulonglong)uVar1 * 8)) break;
        puVar2 = puVar2 + -3;
        uVar4 = uVar4 - 1;
        uVar5 = (ulonglong)uVar4;
        uVar6 = uVar6 - 1;
      } while (*puVar2 != *param_2);
    }
  }
  lVar3 = (longlong)(int)uVar4;
  uVar1 = *param_2;
  if ((((&DriveMediaConstants)[lVar3 * 3] == uVar1) &&
      (uVar1 = (byte)(&DAT_1400050ca)[lVar3 * 0xc] - 1, param_2[3] <= uVar1)) &&
     (param_2[4] <= uVar1)) {
    if ((param_2[1] <= (uint)(ushort)(&DAT_1400050c8)[lVar3 * 6]) &&
       (uVar1 = param_2[2], uVar1 <= (ushort)(&DAT_1400050c8)[lVar3 * 6])) {
      return CONCAT31((int3)(uVar1 >> 8),param_2[1] <= uVar1);
    }
  }
  return uVar1 & 0xffffff00;
}



===== FlopticalFormatMedia @ 140008420 =====

int FlopticalFormatMedia(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  ulonglong local_res10;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_38 = 0;
  uStack_30 = 0;
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  iVar3 = ((((*(int *)(param_2 + 8) - *(int *)(param_2 + 4)) * (uint)DAT_1400051ae +
            *(int *)(param_2 + 0x10)) - *(int *)(param_2 + 0xc)) + 1) * (uint)DAT_1400051a8 *
          (uint)DAT_1400051aa;
  lVar1 = ExAllocatePool2(0x48,iVar3,0x706f4653);
  if (lVar1 == 0) {
    return -0x3fffff66;
  }
  local_res10 = (ulonglong)
                ((uint)DAT_1400051aa *
                ((uint)DAT_1400051ae * *(int *)(param_2 + 4) + *(int *)(param_2 + 0xc)) *
                (uint)DAT_1400051a8);
  KeInitializeEvent(&local_28,0,0);
  lVar2 = IoBuildSynchronousFsdRequest(4,param_1,lVar1,iVar3,&local_res10,&local_28,&local_38);
  if (lVar2 == 0) {
    iVar3 = -0x3fffff66;
  }
  else {
    iVar3 = IofCallDriver(param_1,lVar2);
    if (iVar3 == 0x103) {
      KeWaitForSingleObject(&local_28,0,0,0,0);
    }
    else if (iVar3 < 0) goto LAB_140008572;
    iVar3 = (int)local_38;
  }
LAB_140008572:
  ExFreePoolWithTag(lVar1,0);
  return iVar3;
}



===== FormatMedia @ 1400085a4 =====

int FormatMedia(undefined8 param_1,int param_2)

{
  byte bVar1;
  uint uVar2;
  undefined4 *puVar3;
  void *pvVar4;
  int *piVar5;
  longlong lVar6;
  int iVar7;
  
  puVar3 = (undefined4 *)ExAllocatePool2(0x48,0xc0,0x706f4653);
  if (puVar3 == (undefined4 *)0x0) {
    return -0x3fffff66;
  }
  uVar2 = ClassModeSense(param_1,puVar3,0xc0,5);
  if (((uVar2 < 4) || (pvVar4 = (void *)ClassFindModePage(puVar3,uVar2,5,1), pvVar4 == (void *)0x0))
     || (*(byte *)((longlong)pvVar4 + 1) + 2 < 10)) {
    ExFreePoolWithTag(puVar3,0);
    return -0x3ffffff0;
  }
  iVar7 = 0x17;
  if (DAT_1400051d4 != param_2) {
    piVar5 = &DAT_1400051d4;
    do {
      if (piVar5 == &DriveMediaConstants) {
        iVar7 = -0x3ffffff3;
        goto LAB_14000877e;
      }
      piVar5 = piVar5 + -3;
      iVar7 = iVar7 + -1;
    } while (*piVar5 != param_2);
  }
  lVar6 = (longlong)iVar7;
  if ((((*(char *)((longlong)pvVar4 + 4) == (&DAT_1400050ca)[lVar6 * 0xc]) &&
       (*(char *)((longlong)pvVar4 + 5) == (&DAT_1400050c6)[lVar6 * 0xc])) &&
      ((*(char *)((longlong)pvVar4 + 8) == (char)((ushort)(&DAT_1400050c8)[lVar6 * 6] + 1 >> 8) ||
       ((uint)*(byte *)((longlong)pvVar4 + 9) == *(byte *)(&DAT_1400050c8 + lVar6 * 6) + 1)))) &&
     (*(char *)((longlong)pvVar4 + 6) == *(char *)(lVar6 * 0xc + 0x1400050c5))) {
    ExFreePoolWithTag(puVar3,0);
    pvVar4 = (void *)ExAllocatePool2(0x40,0x58,0x706f4653);
    if (pvVar4 == (void *)0x0) {
      return -0x3fffff66;
    }
  }
  else {
    *(undefined1 *)((longlong)pvVar4 + 4) = (&DAT_1400050ca)[lVar6 * 0xc];
    *(undefined1 *)((longlong)pvVar4 + 5) = (&DAT_1400050c6)[lVar6 * 0xc];
    *(char *)((longlong)pvVar4 + 8) = (char)((ushort)(&DAT_1400050c8)[lVar6 * 6] + 1 >> 8);
    *(char *)((longlong)pvVar4 + 9) = *(char *)(&DAT_1400050c8 + lVar6 * 6) + '\x01';
    *(undefined1 *)((longlong)pvVar4 + 6) = *(undefined1 *)(lVar6 * 0xc + 0x1400050c5);
    *puVar3 = 0;
    bVar1 = *(byte *)((longlong)pvVar4 + 1);
    memcpy(puVar3 + 1,pvVar4,(ulonglong)(bVar1 + 2));
    iVar7 = bVar1 + 6;
    pvVar4 = (void *)ExAllocatePool2(0x40,0x58,0x706f4653);
    if (pvVar4 == (void *)0x0) {
      iVar7 = -0x3fffff66;
LAB_14000877e:
      ExFreePoolWithTag(puVar3,0);
      return iVar7;
    }
    *(byte *)((longlong)pvVar4 + 0x49) = *(byte *)((longlong)pvVar4 + 0x49) | 0x10;
    *(undefined1 *)((longlong)pvVar4 + 10) = 6;
    *(undefined1 *)((longlong)pvVar4 + 0x48) = 0x15;
    *(char *)((longlong)pvVar4 + 0x4c) = (char)iVar7;
    *(undefined4 *)((longlong)pvVar4 + 0x14) = 2;
    iVar7 = ClassSendSrbSynchronous(param_1,pvVar4,puVar3,iVar7,1);
    ExFreePoolWithTag(puVar3);
    if (iVar7 < 0) {
      ExFreePoolWithTag(pvVar4,0);
      return iVar7;
    }
  }
  memset(pvVar4,0,0x58);
  *(undefined1 *)((longlong)pvVar4 + 10) = 6;
  *(undefined1 *)((longlong)pvVar4 + 0x48) = 4;
  *(undefined4 *)((longlong)pvVar4 + 0x14) = 600;
  iVar7 = ClassSendSrbSynchronous(param_1,pvVar4,0,0,0);
  ExFreePoolWithTag(pvVar4,0);
  return iVar7;
}



===== ScsiFlopAddDevice @ 140008870 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong ScsiFlopAddDevice(undefined8 param_1,longlong param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  longlong lVar4;
  ulonglong uVar5;
  longlong lVar6;
  int iVar7;
  ulonglong uVar8;
  undefined1 auStack_168 [32];
  longlong *local_148;
  longlong local_138 [2];
  char local_128 [256];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_168;
  lVar4 = IoGetConfigurationInformation();
  local_138[0] = 0;
  iVar7 = *(int *)(lVar4 + 4);
  uVar2 = ClassClaimDevice(param_2,0);
  if ((int)uVar2 < 0) {
    return (ulonglong)uVar2;
  }
  uVar2 = iVar7 - 1;
  do {
    uVar2 = uVar2 + 1;
    uVar5 = RtlStringCbPrintfA(local_128,0x100,"\\Device\\Floppy%u",(ulonglong)uVar2);
    uVar8 = uVar5 & 0xffffffff;
    if (-1 < (int)uVar5) {
      local_148 = local_138;
      uVar3 = ClassCreateDeviceObject(param_1,local_128,param_2,1);
      uVar8 = (ulonglong)uVar3;
    }
    iVar7 = (int)uVar8;
  } while ((iVar7 == -0x3fffffcb) || (iVar7 == 0x40000000));
  if (-1 < iVar7) {
    *(uint *)(local_138[0] + 0x30) = *(uint *)(local_138[0] + 0x30) | 0x10;
    lVar4 = *(longlong *)(local_138[0] + 0x40);
    *(longlong *)(lVar4 + 8) = local_138[0];
    puVar1 = *(undefined4 **)(lVar4 + 0x60);
    *(longlong *)(lVar4 + 0x18) = lVar4;
    *puVar1 = 7;
    *(undefined1 *)(puVar1 + 1) = 0;
    *(undefined4 *)(lVar4 + 600) = 0;
    *(uint *)(lVar4 + 0x24c) = uVar2;
    if (*(uint *)(local_138[0] + 0x98) < *(uint *)(param_2 + 0x98)) {
      *(uint *)(local_138[0] + 0x98) = *(uint *)(param_2 + 0x98);
    }
    *(undefined4 *)(lVar4 + 0x250) = 8;
    *(longlong *)(lVar4 + 0x200) = param_2;
    lVar6 = IoAttachDeviceToDeviceStack(local_138[0],param_2);
    *(longlong *)(lVar4 + 0x10) = lVar6;
    if (lVar6 != 0) {
      *(char *)(local_138[0] + 0x4c) = *(char *)(local_138[0] + 0x4c) + '\x01';
      *(uint *)(local_138[0] + 0x30) = *(uint *)(local_138[0] + 0x30) & 0xffffff7f;
      uVar8 = 0;
      goto LAB_1400089c3;
    }
    uVar8 = 0xc0000001;
  }
  if (local_138[0] != 0) {
    IoDeleteDevice();
  }
  if ((int)uVar8 < 0) {
    return uVar8;
  }
LAB_1400089c3:
  lVar4 = IoGetConfigurationInformation();
  *(int *)(lVar4 + 4) = *(int *)(lVar4 + 4) + 1;
  return uVar8;
}



===== ScsiFlopRemoveDevice @ 140008a20 =====

undefined8 ScsiFlopRemoveDevice(longlong param_1,char param_2)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  lVar2 = *(longlong *)(lVar1 + 0x60);
  if ((param_2 - 1U & 0xfd) != 0) {
    if (param_2 == '\x02') {
      if (*(longlong *)(lVar1 + 0x208) != 0) {
        ExFreePoolWithTag(*(longlong *)(lVar1 + 0x208),0);
        *(undefined8 *)(lVar1 + 0x208) = 0;
      }
      if (*(longlong *)(lVar1 + 0x210) != 0) {
        ExFreePoolWithTag(*(longlong *)(lVar1 + 0x210),0);
        *(undefined8 *)(lVar1 + 0x210) = 0;
      }
      if (*(longlong *)(lVar1 + 0x240) != 0) {
        ExFreePoolWithTag(*(longlong *)(lVar1 + 0x240),0);
        *(undefined8 *)(lVar1 + 0x240) = 0;
      }
      ClassDeleteSrbLookasideList(lVar1);
    }
    if (*(longlong *)(lVar2 + 0x10) != 0) {
      lVar2 = lVar2 + 8;
      IoSetDeviceInterfaceState(lVar2,0);
      RtlFreeUnicodeString(lVar2);
      RtlInitUnicodeString(lVar2,0);
    }
    if (param_2 == '\x02') {
      lVar2 = IoGetConfigurationInformation();
      *(int *)(lVar2 + 4) = *(int *)(lVar2 + 4) + -1;
    }
  }
  return 0;
}



===== ScsiFlopStartDevice @ 140008b30 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 ScsiFlopStartDevice(longlong param_1)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined1 auStack_4b8 [32];
  undefined8 *local_498;
  uint local_490;
  undefined1 local_488;
  undefined8 *local_480;
  undefined8 *local_478;
  undefined8 local_468;
  undefined8 local_460;
  undefined8 uStack_458;
  undefined8 local_450;
  undefined8 uStack_448;
  undefined8 local_440;
  undefined8 uStack_438;
  undefined8 local_430;
  undefined8 local_428;
  undefined8 uStack_420;
  wchar_t local_418 [256];
  wchar_t local_218 [256];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_4b8;
  lVar1 = *(longlong *)(param_1 + 0x40);
  local_468 = 0;
  local_430 = 0;
  local_428 = 0;
  uStack_420 = 0;
  local_450 = 0;
  uStack_448 = 0;
  local_460 = 0;
  uStack_458 = 0;
  local_440 = 0;
  uStack_438 = 0;
  KeInitializeEvent(&local_440,1,0);
  DetermineMediaType(param_1);
  RtlStringCbPrintfW(local_218,0x100,L"\\Device\\Floppy%u",(ulonglong)*(uint *)(lVar1 + 0x24c));
  RtlInitUnicodeString(&local_450,local_218);
  local_478 = &local_428;
  local_480 = &local_440;
  local_488 = 0;
  local_498 = &local_468;
  local_490 = 8;
  lVar3 = IoBuildDeviceIoControlRequest(0x41018,param_1,0);
  if (lVar3 == 0) {
    uVar4 = 0xc000009a;
  }
  else {
    iVar2 = IofCallDriver(*(undefined8 *)(lVar1 + 0x10),lVar3);
    if (iVar2 == 0x103) {
      local_498 = (undefined8 *)0x0;
      KeWaitForSingleObject(&local_440,0,0);
      iVar2 = (int)local_428;
    }
    if (-1 < iVar2) {
      local_490 = (uint)local_468._7_1_;
      local_498 = (undefined8 *)CONCAT44(local_498._4_4_,(uint)local_468._6_1_);
      RtlStringCbPrintfW(local_418,0x100,L"\\ArcName\\scsi(%u)disk(%u)fdisk(%u)",
                         local_468 >> 0x20 & 0xff);
      RtlInitUnicodeString(&local_460,local_418);
      IoCreateSymbolicLink(&local_460,&local_450);
    }
    local_490 = *(undefined4 *)(lVar1 + 0x24c);
    local_498 = (undefined8 *)0x0;
    RtlStringCbPrintfW(local_418,0x100,L"\\ArcName\\multi(%u)disk(%u)fdisk(%u)",0);
    RtlInitUnicodeString(&local_460,local_418);
    IoCreateSymbolicLink(&local_460,&local_450);
    if (*(longlong *)(*(longlong *)(lVar1 + 0x60) + 0x10) != 0) {
      IoSetDeviceInterfaceState(*(longlong *)(lVar1 + 0x60) + 8,1);
    }
    uVar4 = 0;
  }
  return uVar4;
}



===== ScsiFlopUnload @ 140008d70 =====

void ScsiFlopUnload(void)

{
  return;
}



===== USBFlopFormatTracks @ 140008d7c =====

int USBFlopFormatTracks(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined4 uVar2;
  longlong lVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  ulonglong uVar10;
  void *_Dst;
  longlong lVar11;
  int *piVar12;
  uint uVar13;
  int local_res10;
  
  lVar3 = *(longlong *)(param_1 + 0x40);
  local_res10 = 0;
  if (0x13 < *(uint *)(*(longlong *)(param_2 + 0xb8) + 0x10)) {
    piVar4 = *(int **)(param_2 + 0x18);
    uVar10 = 0;
    piVar12 = &DAT_140005218;
    iVar9 = *piVar4;
    do {
      if (*piVar12 == iVar9) {
        lVar1 = uVar10 * 0x18;
        piVar12 = (int *)(&FloppyGeometries + lVar1);
        if (piVar12 == (int *)0x0) {
          return -0x3ffffff3;
        }
        if (*piVar12 - 1U < (uint)piVar4[1]) {
          return -0x3ffffff3;
        }
        if (*piVar12 - 1U < (uint)piVar4[2]) {
          return -0x3ffffff3;
        }
        uVar8 = *(int *)(lVar1 + 0x14000521c) - 1;
        if (uVar8 < (uint)piVar4[3]) {
          return -0x3ffffff3;
        }
        if (uVar8 < (uint)piVar4[4]) {
          return -0x3ffffff3;
        }
        if ((uint)piVar4[2] < (uint)piVar4[1]) {
          return -0x3ffffff3;
        }
        if ((uint)piVar4[4] < (uint)piVar4[3]) {
          return -0x3ffffff3;
        }
        if ((iVar9 == 0xd) || (iVar9 - 0x18U < 2)) {
          return 0;
        }
        _Dst = (void *)ExAllocatePool2(0x40,0x58,0x706f4653);
        if (_Dst != (void *)0x0) {
          lVar11 = ExAllocatePool2(0x40,0xc,0x706f4653);
          if (lVar11 != 0) {
            *(byte *)(lVar11 + 1) = *(byte *)(lVar11 + 1) | 0xb0;
            *(undefined1 *)(lVar11 + 3) = 8;
            *(undefined1 *)(lVar11 + 4) =
                 *(undefined1 *)((longlong)&FloppyCapacities + uVar10 * 0xc + 3);
            *(undefined1 *)(lVar11 + 5) =
                 *(undefined1 *)((longlong)&FloppyCapacities + uVar10 * 0xc + 2);
            *(undefined1 *)(lVar11 + 6) =
                 *(undefined1 *)((longlong)&FloppyCapacities + uVar10 * 0xc + 1);
            *(undefined1 *)(lVar11 + 7) = *(undefined1 *)(&FloppyCapacities + uVar10 * 3);
            *(undefined1 *)(lVar11 + 9) =
                 *(undefined1 *)((longlong)&DAT_140005014 + uVar10 * 0xc + 2);
            *(undefined1 *)(lVar11 + 10) =
                 *(undefined1 *)((longlong)&DAT_140005014 + uVar10 * 0xc + 1);
            *(undefined1 *)(lVar11 + 0xb) = *(undefined1 *)(&DAT_140005014 + uVar10 * 3);
            uVar8 = piVar4[1];
            iVar9 = 0;
            if (uVar8 <= (uint)piVar4[2]) {
              do {
                uVar13 = piVar4[3];
                if (uVar13 <= (uint)piVar4[4]) {
                  do {
                    memset(_Dst,0,0x58);
                    *(undefined1 *)((longlong)_Dst + 10) = 0xc;
                    uVar2 = *(undefined4 *)(lVar3 + 0x248);
                    *(byte *)((longlong)_Dst + 0x49) = *(byte *)((longlong)_Dst + 0x49) | 0x17;
                    *(undefined4 *)((longlong)_Dst + 0x14) = uVar2;
                    *(undefined1 *)((longlong)_Dst + 0x48) = 4;
                    *(char *)((longlong)_Dst + 0x4a) = (char)uVar8;
                    *(undefined1 *)((longlong)_Dst + 0x50) = 0xc;
                    *(byte *)(lVar11 + 1) =
                         (*(byte *)(lVar11 + 1) ^ (byte)uVar13) & 1 ^ *(byte *)(lVar11 + 1);
                    iVar9 = ClassSendSrbSynchronous(param_1,_Dst,lVar11,0xc,1);
                    if (iVar9 < 0) goto LAB_140009001;
                    uVar13 = uVar13 + 1;
                  } while (uVar13 <= (uint)piVar4[4]);
                  local_res10 = iVar9;
                }
                uVar8 = uVar8 + 1;
              } while (uVar8 <= (uint)piVar4[2]);
              iVar9 = local_res10;
            }
            if (piVar4[1] == 0) {
              uVar2 = *(undefined4 *)(lVar1 + 0x140005214);
              uVar6 = (&DAT_140005218)[uVar10 * 6];
              uVar7 = *(undefined4 *)(lVar1 + 0x14000521c);
              *(int *)(lVar3 + 0x228) = *piVar12;
              *(undefined4 *)(lVar3 + 0x22c) = uVar2;
              *(undefined4 *)(lVar3 + 0x230) = uVar6;
              *(undefined4 *)(lVar3 + 0x234) = uVar7;
              *(undefined8 *)(lVar3 + 0x238) = (&DAT_140005220)[uVar10 * 3];
              iVar5 = 0x1f;
              if (*(uint *)(lVar3 + 0x23c) != 0) {
                for (; *(uint *)(lVar3 + 0x23c) >> iVar5 == 0; iVar5 = iVar5 + -1) {
                }
              }
              *(char *)(lVar3 + 0x282) = (char)iVar5;
              *(ulonglong *)(lVar3 + 0x90) =
                   (ulonglong)(uint)(&DAT_140005014)[uVar10 * 3] *
                   (ulonglong)(uint)(&FloppyCapacities)[uVar10 * 3];
            }
LAB_140009001:
            ExFreePoolWithTag(lVar11,0);
            ExFreePoolWithTag(_Dst,0);
            return iVar9;
          }
          ExFreePoolWithTag(_Dst,0);
        }
        return -0x3fffff66;
      }
      uVar8 = (int)uVar10 + 1;
      uVar10 = (ulonglong)uVar8;
      piVar12 = piVar12 + 6;
    } while (uVar8 < 10);
  }
  return -0x3ffffff3;
}



===== USBFlopGetMediaTypes @ 140009038 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong USBFlopGetMediaTypes(char *param_1,longlong param_2)

{
  undefined8 uVar1;
  uint uVar2;
  uint uVar3;
  ulonglong uVar4;
  longlong lVar5;
  longlong lVar6;
  char *pcVar7;
  uint uVar8;
  char *pcVar9;
  longlong lVar10;
  undefined8 *puVar11;
  uint uVar12;
  undefined8 *puVar13;
  int iVar14;
  int iVar15;
  int *piVar16;
  byte *pbVar17;
  longlong lVar18;
  undefined1 auStack_c8 [32];
  undefined1 local_a8;
  int local_98;
  uint local_94;
  uint local_90;
  int local_8c;
  int local_88;
  char *local_80;
  longlong local_78;
  undefined8 *local_70;
  longlong local_68;
  longlong local_60;
  char local_58 [16];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_c8;
  lVar18 = *(longlong *)(param_1 + 0x40);
  local_80 = param_1;
  local_68 = param_2;
  local_60 = lVar18;
  if (param_2 == 0) {
    local_8c = 0x70000;
    puVar11 = (undefined8 *)0x0;
    local_70 = (undefined8 *)0x0;
  }
  else {
    puVar11 = *(undefined8 **)(param_2 + 0x18);
    local_8c = *(int *)(*(longlong *)(param_2 + 0xb8) + 0x18);
    *(undefined8 *)(param_2 + 0x38) = 0;
    uVar2 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 8);
    if (uVar2 < 0x18) {
      return 0xc0000023;
    }
    local_70 = puVar11 + ((ulonglong)uVar2 / 0x18) * 3;
    if (local_8c != 0x70000) goto LAB_14000910f;
  }
  *(undefined4 *)(lVar18 + 0x230) = 0;
  uVar4 = ClassReadDriveCapacity(param_1);
  if ((((int)uVar4 + 0x80000000U & 0x80000000) == 0) && ((int)uVar4 != -0x3fffffec)) {
    return uVar4;
  }
LAB_14000910f:
  lVar5 = ExAllocatePool2(0x40,0x58,0x706f4653);
  if (lVar5 == 0) {
    uVar4 = 0xc000009a;
  }
  else {
    local_78 = lVar5;
    lVar6 = ExAllocatePool2(0x40,0xfc,0x706f4653);
    if (lVar6 == 0) {
      uVar4 = 0xc000009a;
    }
    else {
      local_a8 = 0;
      *(undefined1 *)(lVar5 + 10) = 10;
      *(undefined4 *)(lVar5 + 0x14) = *(undefined4 *)(lVar18 + 0x248);
      *(undefined1 *)(lVar5 + 0x48) = 0x23;
      *(undefined1 *)(lVar5 + 0x50) = 0xfc;
      uVar2 = ClassSendSrbSynchronous(param_1,lVar5,lVar6,0xfc);
      pcVar7 = local_80;
      uVar4 = 0;
      if ((*(byte *)(lVar5 + 3) & 0x3f) != 0x12) {
        uVar4 = (ulonglong)uVar2;
      }
      if (((((int)uVar4 < 0) || (*(uint *)(lVar5 + 0x10) < 4)) || (*(byte *)(lVar6 + 3) == 0)) ||
         ((*(byte *)(lVar6 + 3) & 7) != 0)) {
        if (-1 < (int)uVar4) {
          uVar4 = 0xc0000001;
        }
      }
      else {
        uVar2 = *(uint *)(lVar5 + 0x10) - 4;
        *(uint *)(lVar5 + 0x10) = uVar2;
        uVar12 = uVar2 >> 3;
        if (*(byte *)(lVar6 + 3) <= uVar2) {
          uVar12 = (uint)(*(byte *)(lVar6 + 3) >> 3);
        }
        local_58[0] = '\0';
        local_58[1] = '\0';
        local_58[2] = '\0';
        local_58[3] = '\0';
        local_58[4] = '\0';
        local_58[5] = '\0';
        local_58[6] = '\0';
        local_58[7] = '\0';
        uVar2 = 0xffffffff;
        local_58[8] = '\0';
        local_58[9] = '\0';
        local_90 = 0;
        if (uVar12 != 0) {
          pbVar17 = (byte *)(lVar6 + 4);
          uVar2 = 0xffffffff;
          do {
            local_80 = local_58;
            piVar16 = &DAT_140005014;
            iVar15 = (uint)pbVar17[1] * 0x10000 + (uint)pbVar17[2] * 0x100 +
                     (uint)*pbVar17 * 0x1000000 + (uint)pbVar17[3];
            iVar14 = (uint)pbVar17[5] * 0x10000 + (uint)pbVar17[6] * 0x100 + (uint)pbVar17[7];
            local_94 = 0;
            uVar8 = local_90;
            local_98 = iVar15;
            local_88 = iVar14;
            do {
              if ((iVar15 == piVar16[-1]) && (iVar14 == *piVar16)) {
                *local_80 = '\x01';
                if (uVar8 == 0) {
                  uVar2 = local_94;
                }
              }
              else if (((pbVar17[4] & 2) != 0) && (iVar14 == *piVar16)) {
                uVar3 = DetermineDriveType((longlong)pcVar7);
                iVar15 = local_98;
                iVar14 = local_88;
                uVar8 = local_90;
                if (uVar3 == 7) {
                }
                else if (((&DriveMediaConstants)
                          [(ulonglong)(uint)(&DriveMediaLimits)[(ulonglong)uVar3 * 2] * 3] == 0x19)
                        && (*local_80 = '\x01', local_90 == 0)) {
                  uVar2 = local_94;
                }
              }
              local_94 = local_94 + 1;
              local_80 = local_80 + 1;
              piVar16 = piVar16 + 3;
            } while (local_94 < 10);
            local_90 = uVar8 + 1;
            pbVar17 = pbVar17 + 8;
          } while (local_90 < uVar12);
          lVar5 = local_78;
          param_2 = local_68;
          lVar18 = local_60;
        }
        lVar10 = 10;
        uVar4 = 0xc0000014;
        if (local_8c == 0x70000) {
          if (uVar2 != 0xffffffff) {
            lVar10 = (longlong)(int)uVar2;
            uVar1 = *(undefined8 *)(&DAT_140005218 + lVar10 * 6);
            *(undefined8 *)(lVar18 + 0x228) = *(undefined8 *)(&FloppyGeometries + lVar10 * 0x18);
            *(undefined8 *)(lVar18 + 0x230) = uVar1;
            *(undefined8 *)(lVar18 + 0x238) = (&DAT_140005220)[lVar10 * 3];
            local_8c = 0x1f;
            if (*(uint *)(lVar18 + 0x23c) != 0) {
              for (; *(uint *)(lVar18 + 0x23c) >> local_8c == 0; local_8c = local_8c + -1) {
              }
            }
            *(char *)(lVar18 + 0x282) = (char)local_8c;
            *(ulonglong *)(lVar18 + 0x90) =
                 (ulonglong)(uint)(&DAT_140005014)[lVar10 * 3] *
                 (ulonglong)(uint)(&FloppyCapacities)[lVar10 * 3];
            if (param_2 != 0) {
              uVar1 = *(undefined8 *)(&DAT_140005218 + lVar10 * 6);
              *puVar11 = *(undefined8 *)(&FloppyGeometries + lVar10 * 0x18);
              puVar11[1] = uVar1;
              puVar11[2] = (&DAT_140005220)[lVar10 * 3];
              *(undefined8 *)(param_2 + 0x38) = 0x18;
            }
            uVar4 = 0;
          }
        }
        else {
          pcVar7 = local_58;
          puVar13 = (undefined8 *)&FloppyGeometries;
          pcVar9 = &DAT_140005018;
          do {
            if ((*pcVar7 != '\0') && (*pcVar9 != '\0')) {
              if (puVar11 < local_70) {
                uVar1 = puVar13[1];
                *puVar11 = *puVar13;
                puVar11[1] = uVar1;
                puVar11[2] = puVar13[2];
                puVar11 = puVar11 + 3;
                *(longlong *)(param_2 + 0x38) = *(longlong *)(param_2 + 0x38) + 0x18;
                uVar4 = 0;
              }
              else {
                uVar4 = 0x80000005;
              }
            }
            pcVar7 = pcVar7 + 1;
            pcVar9 = pcVar9 + 0xc;
            puVar13 = puVar13 + 3;
            lVar10 = lVar10 + -1;
          } while (lVar10 != 0);
        }
      }
      ExFreePoolWithTag(lVar6,0);
    }
    ExFreePoolWithTag(lVar5,0);
  }
  return uVar4;
}



===== entry @ 14000a010 =====

void entry(undefined8 param_1,undefined8 param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 14000a044 =====

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



===== DriverEntry @ 14000a078 =====

void DriverEntry(undefined8 param_1,undefined8 param_2)

{
  undefined4 local_198 [2];
  undefined4 local_190;
  undefined4 local_18c;
  undefined4 local_184;
  code *local_180;
  code *local_178;
  code *local_170;
  undefined8 local_168;
  undefined8 local_160;
  code *local_158;
  code *local_150;
  code *local_140;
  code *local_138;
  code *local_40;
  undefined8 local_28;
  code *local_20;
  
  memset(local_198,0,0x188);
  local_198[0] = 0x188;
  local_168 = 0;
  local_158 = ScsiFlopInitDevice;
  local_160 = 0;
  local_150 = ScsiFlopStartDevice;
  local_28 = 0;
  local_140 = ScsiFlopStopDevice;
  local_190 = 0x4d8;
  local_138 = ScsiFlopRemoveDevice;
  local_178 = ScsiFlopReadWriteVerification;
  local_170 = ScsiFlopDeviceControl;
  local_180 = ScsiFlopProcessError;
  local_40 = ScsiFlopAddDevice;
  local_20 = ScsiFlopUnload;
  local_18c = 7;
  local_184 = 5;
  ClassInitialize(param_1,param_2,local_198);
  return;
}


