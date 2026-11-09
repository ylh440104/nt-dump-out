
===== GdiGetEntry @ 180001010 =====

undefined8 GdiGetEntry(uint param_1,undefined8 *param_2)

{
  undefined8 *puVar1;
  longlong lVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  
                    /* 0x1010  1574  GdiGetEntry */
  lVar2 = pGdiSharedHandleTable;
  uVar4 = (ulonglong)(param_1 & 0xffff);
  if ((param_1 < 0x10000) ||
     ((uint)*(byte *)(pGdiSharedHandleTable + 0xd + uVar4 * 0x18) == param_1 >> 0x10)) {
    puVar1 = (undefined8 *)(pGdiSharedHandleTable + uVar4 * 0x18);
    uVar3 = puVar1[1];
    *param_2 = *puVar1;
    param_2[1] = uVar3;
    param_2[2] = *(undefined8 *)(lVar2 + 0x10 + uVar4 * 0x18);
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x000180001039. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar3 = NtGdiGetEntry();
  return uVar3;
}



===== DeleteObject @ 180001070 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

BOOL __stdcall DeleteObject(HGDIOBJ ho)

{
  char cVar1;
  BOOL BVar2;
  ulonglong uVar3;
  
                    /* 0x1070  1418  DeleteObject */
  InitOnceExecuteOnce((PINIT_ONCE)&DAT_1800256e8,CheckIsEdgeGdiProcessOnce,(PVOID)0x0,(LPVOID *)0x0)
  ;
  if (g_pEdgeGdi != 0) {
    BVar2 = (**(code **)(g_pEdgeGdi + 0x58))();
    return BVar2;
  }
  uVar3 = InternalDeleteObject(ho);
  if ((int)uVar3 == 0) {
    BVar2 = 0;
  }
  else {
    cVar1 = IsGdiTrackHCreatePresent();
    if (cVar1 != '\0') {
      GdiTrackHDelete(ho);
    }
    BVar2 = 1;
  }
  return BVar2;
}



===== InternalDeleteObject @ 1800010f0 =====

ulonglong InternalDeleteObject(HCOLORSPACE param_1)

{
  byte bVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  BOOL BVar7;
  undefined8 uVar8;
  ulonglong uVar9;
  undefined4 extraout_var;
  uint uVar10;
  HCOLORSPACE pHVar11;
  uint uVar12;
  uint *puVar13;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
                    /* 0x10f0  1774  InternalDeleteObject */
  uVar12 = (uint)((ulonglong)param_1 >> 0x10);
  uVar10 = uVar12 & 0x1f;
  uVar5 = HANDLE_TO_INDEX((uint)param_1);
  if (gMaxGdiHandleCount <= uVar5) {
    return 0;
  }
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  uVar8 = GdiGetEntry(uVar5,&local_28);
  if ((int)uVar8 < 0) {
    return 0;
  }
  if (uStack_20._6_1_ != uVar10) {
    return 0;
  }
  if (((uVar12 & 0xffff ^ (uint)uStack_20._4_2_) & 0xffffff7f) != 0) {
    return 0;
  }
  if ((((uint)uStack_20 & 0xfffffffe) != gW32PID) && ((uStack_20 & 0xfffffffe) != 0)) {
    return 0;
  }
  uVar9 = uStack_20 & 0x8000000000;
  uVar2 = uStack_20 & 0x8000000000;
  uVar3 = uStack_20 & 0x8000000000;
  if (uVar10 == 1) {
    uVar9 = InternalDeleteDC(param_1);
    return uVar9;
  }
  uVar5 = (uint)param_1 & 0x7f0000;
  if ((uVar5 - 0x260000 & 0xffdfffff) == 0) {
    return 0;
  }
  if (uVar5 == 0x40000) {
    uVar9 = DeleteRegion(param_1);
    return uVar9;
  }
  if (uVar5 == 0x90000) {
    BVar7 = DeleteColorSpace(param_1);
    return CONCAT44(extraout_var,BVar7);
  }
  if (((ulonglong)param_1 >> 0x17 & 1) != 0) {
    return 1;
  }
  cVar4 = IsExtEscapeImplPresent();
  if ((cVar4 != '\0') && (iVar6 = MF_DeleteObjectHelper(param_1), iVar6 == 0)) {
    return 0;
  }
  if (uVar5 == 0xa0000) {
    cVar4 = IsDeleteFontPresent();
    if (cVar4 == '\0') {
      return 0;
    }
    uVar9 = DeleteFont(param_1);
    return uVar9;
  }
  pHVar11 = (HCOLORSPACE)((ulonglong)param_1 | 0x800000);
  if (uVar9 == 0) {
    pHVar11 = param_1;
  }
  uVar5 = (uint)pHVar11 & 0x7f0000;
  if ((uVar5 - 0x100000 & 0xffdfffff) == 0) {
    uVar10 = HANDLE_TO_INDEX((uint)pHVar11);
    puVar13 = (uint *)0x0;
    if (uVar10 < gMaxGdiHandleCount) {
      local_18 = 0;
      local_28 = 0;
      uStack_20 = 0;
      uVar8 = GdiGetEntry(uVar10,&local_28);
      if ((((-1 < (int)uVar8) && (uStack_20._6_1_ == '\x10')) &&
          (uStack_20._4_2_ == (short)((ulonglong)pHVar11 >> 0x10))) &&
         ((((uint)uStack_20 & 0xfffffffe) == gW32PID && (local_18 != 0)))) {
        bVar1 = 0x40 - ((byte)gCookie & 0x3f) & 0x3f;
        puVar13 = (uint *)((local_18 >> bVar1 | local_18 << 0x40 - bVar1) ^ gCookie);
      }
    }
    if ((uVar2 != 0) || ((puVar13 != (uint *)0x0 && ((*puVar13 & 0xb) == 0)))) {
      iVar6 = GdiHandleBeingTracked(pHVar11);
      if ((iVar6 == 0) &&
         ((Win32ThreadInfo != (void *)0x0 && (((uint)GdiTebBatch & 0x3fffffff) + 0x10 < 0x4d9)))) {
        if ((((uint)GdiTebBatch >> 0x1e & 1) != 0) &&
           (cVar4 = IsTraceLoggingGdiBatchInProcessingPresent(), cVar4 != '\0')) {
          TraceLoggingGdiBatchInProcessing(7);
        }
        uVar5 = (uint)GdiTebBatch & 0x3fffffff;
        *(undefined4 *)(&DAT_ff00000300 + uVar5) = 0x70010;
        if (uVar3 == 0) {
          *puVar13 = *puVar13 | 8;
        }
        *(undefined4 *)(&DAT_ff00000300 + uVar5) = 0x70010;
        *(HCOLORSPACE *)(&DAT_ff00000308 + uVar5) = pHVar11;
        GdiBatchCount = GdiBatchCount + 1;
        GdiTebBatch._0_4_ =
             ((uint)GdiTebBatch + 0x10 ^ (uint)GdiTebBatch) & 0x3fffffff ^ (uint)GdiTebBatch;
        if (GdiBatchCount < GdiBatchLimit) {
          return 1;
        }
        NtGdiFlush();
        return 1;
      }
      goto LAB_180001216;
    }
  }
  if (uVar5 == 0x50000) {
    IcmReleaseCachedColorSpace(pHVar11);
  }
LAB_180001216:
  uVar9 = NtGdiDeleteObjectApp(pHVar11);
  return uVar9;
}



===== DeleteRegion @ 180001470 =====

undefined8 DeleteRegion(undefined8 param_1)

{
  byte bVar1;
  char cVar2;
  uint uVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  uVar3 = HANDLE_TO_INDEX((uint)param_1);
  uVar5 = 0;
  if (uVar3 < gMaxGdiHandleCount) {
    local_18 = 0;
    local_28 = 0;
    uStack_20 = 0;
    uVar4 = GdiGetEntry(uVar3,&local_28);
    if ((((-1 < (int)uVar4) && (uStack_20._6_1_ == '\x04')) &&
        (uStack_20._4_2_ == (short)((ulonglong)param_1 >> 0x10))) &&
       ((((uint)uStack_20 & 0xfffffffe) == gW32PID && (local_18 != 0)))) {
      bVar1 = 0x40 - ((byte)gCookie & 0x3f) & 0x3f;
      uVar5 = (local_18 >> bVar1 | local_18 << 0x40 - bVar1) ^ gCookie;
    }
  }
  if ((Win32ThreadInfo != (void *)0x0) && (((uint)GdiTebBatch & 0x3fffffff) + 0x10 < 0x4d9)) {
    if (((uint)GdiTebBatch >> 0x1e & 1) != 0) {
      cVar2 = IsTraceLoggingGdiBatchInProcessingPresent();
      if (cVar2 != '\0') {
        TraceLoggingGdiBatchInProcessing(8);
      }
    }
    uVar3 = (uint)GdiTebBatch & 0x3fffffff;
    *(undefined4 *)(&DAT_ff00000300 + uVar3) = 0x80010;
    if (uVar5 != 0) {
      *(undefined8 *)(&DAT_ff00000308 + uVar3) = param_1;
      GdiBatchCount = GdiBatchCount + 1;
      GdiTebBatch._0_4_ =
           ((uint)GdiTebBatch + 0x10 ^ (uint)GdiTebBatch) & 0x3fffffff ^ (uint)GdiTebBatch;
      if (GdiBatchLimit <= GdiBatchCount) {
        NtGdiFlush();
      }
      return 1;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x000180001559. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar4 = NtGdiDeleteObjectApp(param_1);
  return uVar4;
}



===== IsPseudoDesktopDcForFilteredProcess @ 180001620 =====

undefined8 IsPseudoDesktopDcForFilteredProcess(longlong param_1)

{
  if ((g_systemCallFilterId == 5) && (param_1 == -0x2321b000)) {
    return 1;
  }
  return 0;
}



===== GdiReleaseDC @ 180001650 =====

ulonglong GdiReleaseDC(ulonglong param_1)

{
  byte bVar1;
  uint uVar2;
  undefined8 uVar3;
  HLOCAL pvVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
                    /* 0x1650  1604  GdiReleaseDC */
  uVar6 = 1;
  uVar5 = param_1;
  uVar3 = IsPseudoDesktopDcForFilteredProcess(param_1);
  if ((int)uVar3 == 0) {
    pvVar4 = (HLOCAL)pldcGet(uVar5);
    uVar2 = HANDLE_TO_INDEX((uint)param_1);
    if (uVar2 < gMaxGdiHandleCount) {
      local_18 = 0;
      local_28 = 0;
      uStack_20 = 0;
      uVar3 = GdiGetEntry(uVar2,&local_28);
      if (((((-1 < (int)uVar3) && (uStack_20._6_1_ == '\x01')) &&
           (uStack_20._4_2_ == (short)(param_1 >> 0x10))) &&
          ((((uint)uStack_20 & 0xfffffffe) == gW32PID && (local_18 != 0)))) &&
         ((bVar1 = 0x40 - ((byte)gCookie & 0x3f) & 0x3f,
          uVar5 = (local_18 >> bVar1 | local_18 << 0x40 - bVar1) ^ gCookie, uVar5 != 0 &&
          ((ghICM != 0 || (*(longlong *)(uVar5 + 0x108) != 0)))))) {
        IcmDeleteLocalDC(param_1,uVar5,0);
      }
    }
    if (pvVar4 != (HLOCAL)0x0) {
      if (*(longlong *)((longlong)pvVar4 + 0x38) != 0) {
        MicrosoftTelemetryAssertTriggeredNoArgs();
        return 0;
      }
      vSetPldc(param_1,(ulonglong *)0x0);
      uVar6 = bDeleteLDC(pvVar4);
      uVar6 = uVar6 & 0xffffffff;
    }
  }
  else {
    uVar6 = 1;
  }
  return uVar6;
}



===== CloseEnhMetaFile @ 180001780 =====

HENHMETAFILE __stdcall CloseEnhMetaFile(HDC hdc)

{
  char cVar1;
  longlong lVar2;
  HENHMETAFILE pHVar3;
  
                    /* 0x1780  1044  CloseEnhMetaFile */
  lVar2 = pldcGet(hdc);
  if ((lVar2 == 0) || (((uint)hdc & 0x7f0000) == 0x660000)) {
    LastErrorValue = 6;
  }
  else {
    cVar1 = IsPlayMetaFilePresent();
    if (cVar1 != '\0') {
                    /* WARNING: Could not recover jumptable at 0x0001800017ba. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      pHVar3 = (HENHMETAFILE)CloseEnhMetaFile(hdc);
      return pHVar3;
    }
  }
  return (HENHMETAFILE)0x0;
}



===== GetDeviceCaps @ 1800017f0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

int __stdcall GetDeviceCaps(HDC hdc,int index)

{
  undefined8 *puVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  ulonglong uVar5;
  longlong lVar6;
  uint uVar7;
  ulonglong uVar8;
  int *piVar9;
  byte *pbVar10;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
                    /* 0x17f0  1670  GetDeviceCaps */
  InitOnceExecuteOnce((PINIT_ONCE)&DAT_1800256e8,CheckIsEdgeGdiProcessOnce,(PVOID)0x0,(LPVOID *)0x0)
  ;
  if ((g_pEdgeGdi == 0) || (iVar4 = (**(code **)(g_pEdgeGdi + 0xc0))(), iVar4 != 0)) {
    if ((g_systemCallFilterId == 5) && (hdc == (HDC)0xffffffffdcde5000)) {
LAB_1800019d8:
      piVar9 = pGdiDevCaps;
    }
    else {
      uVar3 = (uint)hdc & 0x7f0000;
      if (uVar3 == 0x10000) {
        uVar3 = (uint)((ulonglong)hdc >> 8) & 0xff0000;
        uVar5 = (ulonglong)hdc & 0xffff;
        uVar7 = uVar3 | (uint)uVar5;
        if ((uVar7 < 0x10000) ||
           (uVar8 = (ulonglong)uVar7,
           (uint)*(byte *)(pGdiSharedHandleTable + 0xd + uVar5 * 0x18) == uVar3 >> 0x10)) {
          uVar8 = uVar5;
        }
        uVar3 = (uint)uVar8;
        if (uVar3 < gMaxGdiHandleCount) {
          local_18 = 0;
          uVar8 = uVar8 & 0xffff;
          local_28 = 0;
          uStack_20 = 0;
          if ((uVar3 < 0x10000) ||
             ((uint)*(byte *)(pGdiSharedHandleTable + 0xd + uVar8 * 0x18) == uVar3 >> 0x10)) {
            puVar1 = (undefined8 *)(pGdiSharedHandleTable + uVar8 * 0x18);
            local_28 = *puVar1;
            uStack_20 = puVar1[1];
            local_18 = *(ulonglong *)(pGdiSharedHandleTable + 0x10 + uVar8 * 0x18);
          }
          else {
            iVar4 = NtGdiGetEntry(0,&local_28);
            if (iVar4 < 0) goto LAB_1800018a3;
          }
          if ((((uStack_20._6_1_ == '\x01') && (uStack_20._4_2_ == (short)((ulonglong)hdc >> 0x10)))
              && (((uint)uStack_20 & 0xfffffffe) == gW32PID)) &&
             ((local_18 != 0 &&
              (bVar2 = 0x40 - ((byte)gCookie & 0x3f) & 0x3f,
              pbVar10 = (byte *)((local_18 >> bVar2 | local_18 << 0x40 - bVar2) ^ gCookie),
              pbVar10 != (byte *)0x0)))) {
            if ((*pbVar10 & 2) == 0) goto switchD_180001a33_caseD_4;
            goto LAB_1800019d8;
          }
        }
LAB_1800018a3:
        LastErrorValue = 0x57;
        goto switchD_180001a33_caseD_1;
      }
      if (uVar3 == 0x660000) {
        iVar4 = 5;
        if (index != 2) {
          iVar4 = 0;
        }
        return iVar4;
      }
      lVar6 = pldcGet(hdc);
      if ((lVar6 == 0) || (((uint)hdc & 0x7f0000) == 0x660000)) {
        LastErrorValue = 6;
        return 0;
      }
      piVar9 = (int *)(lVar6 + 0xa0);
      if ((*(uint *)(lVar6 + 8) & 0x2000000) == 0) {
        iVar4 = NtGdiGetDeviceCapsAll(hdc,piVar9);
        if (iVar4 == 0) goto LAB_1800018a3;
        *(uint *)(lVar6 + 8) = *(uint *)(lVar6 + 8) | 0x2000000;
      }
    }
    if (index == 2) {
      return piVar9[1];
    }
    if (index == 0xc) {
      return piVar9[8];
    }
    switch(index) {
    case 0:
      iVar4 = *piVar9;
      break;
    default:
      goto switchD_180001a33_caseD_1;
    case 4:
    case 6:
    case 8:
    case 10:
    case 0x28:
    case 0x2a:
    case 0x2c:
    case 0x58:
    case 0x5a:
switchD_180001a33_caseD_4:
      iVar4 = NtGdiGetDeviceCaps(hdc,index);
      return iVar4;
    case 0xe:
      return piVar9[9];
    case 0x10:
      iVar4 = -1;
      break;
    case 0x12:
      iVar4 = piVar9[10];
      break;
    case 0x16:
      iVar4 = piVar9[0xb];
      break;
    case 0x18:
      return piVar9[0xc];
    case 0x1c:
      iVar4 = 0x1ff;
      break;
    case 0x1e:
      return 0xfe;
    case 0x20:
      iVar4 = 0xff;
      break;
    case 0x22:
      return piVar9[0x19];
    case 0x24:
      return 1;
    case 0x26:
      return piVar9[0xd];
    case 0x68:
      return piVar9[0x13];
    case 0x6a:
      iVar4 = 0x14;
      break;
    case 0x6c:
      iVar4 = piVar9[0x14];
      break;
    case 0x6e:
      return piVar9[0x15];
    case 0x6f:
      return piVar9[0x16];
    case 0x70:
      return piVar9[0x17];
    case 0x71:
      iVar4 = piVar9[0x18];
      break;
    case 0x74:
      return piVar9[0x1a];
    case 0x75:
      return piVar9[0x1c];
    case 0x76:
      return piVar9[0x1b];
    case 0x77:
      iVar4 = piVar9[0x1d];
      break;
    case 0x78:
      return piVar9[0x22];
    case 0x79:
      iVar4 = piVar9[0x23];
    }
  }
  else {
switchD_180001a33_caseD_1:
    iVar4 = 0;
  }
  return iVar4;
}



===== pldcGet @ 180001d70 =====

undefined8 pldcGet(undefined8 param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  ulonglong uVar6;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
                    /* 0x1d70  2005  pldcGet */
  uVar4 = (uint)((ulonglong)param_1 >> 8) & 0xff0000;
  uVar2 = (uint)param_1 & 0xffff;
  uVar5 = uVar4 | uVar2;
  if ((uVar5 < 0x10000) ||
     ((uint)*(byte *)(pGdiSharedHandleTable + 0xd + (ulonglong)uVar2 * 0x18) == uVar4 >> 0x10)) {
    uVar5 = uVar2;
  }
  if (uVar5 < gMaxGdiHandleCount) {
    local_18 = 0;
    uVar6 = (ulonglong)uVar5 & 0xffff;
    local_28 = 0;
    uStack_20 = 0;
    if ((uVar5 < 0x10000) ||
       ((uint)*(byte *)(pGdiSharedHandleTable + 0xd + uVar6 * 0x18) == uVar5 >> 0x10)) {
      uStack_20 = *(undefined8 *)(pGdiSharedHandleTable + uVar6 * 0x18 + 8);
      local_18 = *(ulonglong *)(pGdiSharedHandleTable + 0x10 + uVar6 * 0x18);
    }
    else {
      iVar3 = NtGdiGetEntry(0,&local_28);
      if (iVar3 < 0) {
        return 0;
      }
    }
    if ((((uStack_20._6_1_ == '\x01') && (uStack_20._4_2_ == (short)((ulonglong)param_1 >> 0x10)))
        && (((uint)uStack_20 & 0xfffffffe) == gW32PID)) &&
       ((local_18 != 0 &&
        (bVar1 = 0x40 - ((byte)gCookie & 0x3f) & 0x3f,
        uVar6 = (local_18 >> bVar1 | local_18 << 0x40 - bVar1) ^ gCookie, uVar6 != 0)))) {
      return *(undefined8 *)(uVar6 + 0x90);
    }
  }
  return 0;
}



===== CreatePolygonRgn @ 180001e90 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

HRGN __stdcall CreatePolygonRgn(POINT *pptl,int cPoint,int iMode)

{
  char cVar1;
  bool bVar2;
  undefined8 uVar3;
  HRGN pHVar4;
  undefined7 extraout_var;
  int local_res10 [6];
  
                    /* 0x1e90  1096  CreatePolygonRgn */
  local_res10[0] = cPoint;
  cVar1 = IsGdiTrackHCreatePresent();
  if (cVar1 == '\0') {
    pHVar4 = (HRGN)NtGdiPolyPolyDraw((longlong)iMode,pptl,local_res10,1,6);
  }
  else {
    uVar3 = NtGdiPolyPolyDraw();
    pHVar4 = (HRGN)GdiTrackHCreate(uVar3);
  }
  bVar2 = IsEdgeGdiProcess();
  if ((int)CONCAT71(extraout_var,bVar2) != 0) {
    pHVar4 = (HRGN)(**(code **)(g_pEdgeGdi + 0xd0))(pHVar4);
  }
  return pHVar4;
}



===== CreateICW @ 180001f30 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

HDC __stdcall CreateICW(LPCWSTR pszDriver,LPCWSTR pszDevice,LPCWSTR pszPort,DEVMODEW *pdm)

{
  bool bVar1;
  char cVar2;
  undefined7 extraout_var;
  undefined8 uVar3;
  HDC pHVar4;
  
                    /* 0x1f30  1086  CreateICW */
  bVar1 = IsEdgeGdiProcess();
  if ((int)CONCAT71(extraout_var,bVar1) == 0) {
    cVar2 = IsGdiTrackHCreatePresent();
    if (cVar2 == '\0') {
      pHVar4 = (HDC)bCreateDCW(pszDriver,pszDevice,(longlong)pszPort,pdm,1,0);
    }
    else {
      uVar3 = bCreateDCW(pszDriver,pszDevice,(longlong)pszPort,pdm,1,0);
      pHVar4 = (HDC)GdiTrackHCreate(uVar3);
    }
  }
  else {
    pHVar4 = (HDC)(**(code **)(g_pEdgeGdi + 0x30))(pszDriver,pszDevice,pszPort,pdm);
  }
  return pHVar4;
}



===== CreateFontW @ 180001fe0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

HFONT __stdcall
CreateFontW(int cHeight,int cWidth,int cEscapement,int cOrientation,int cWeight,DWORD bItalic,
           DWORD bUnderline,DWORD bStrikeOut,DWORD iCharSet,DWORD iOutPrecision,DWORD iClipPrecision
           ,DWORD iQuality,DWORD iPitchAndFamily,LPCWSTR pszFaceName)

{
  bool bVar1;
  undefined7 extraout_var;
  HFONT pHVar2;
  
                    /* 0x1fe0  1082  CreateFontW */
  bVar1 = IsEdgeGdiProcess();
  if ((int)CONCAT71(extraout_var,bVar1) == 0) {
    pHVar2 = CreateFontW(cHeight,cWidth,cEscapement,cOrientation,cWeight,bItalic,bUnderline,
                         bStrikeOut,iCharSet,iOutPrecision,iClipPrecision,iQuality,iPitchAndFamily,
                         pszFaceName);
  }
  else {
    pHVar2 = (HFONT)(**(code **)(g_pEdgeGdi + 0x10))
                              (cHeight,cWidth,cEscapement,cOrientation,cWeight,bItalic,bUnderline,
                               bStrikeOut,iCharSet,iOutPrecision,iClipPrecision,iQuality,
                               iPitchAndFamily,pszFaceName);
  }
  return pHVar2;
}



===== D3DKMTOpenAdapterFromGdiDisplayName @ 180002140 =====

ulonglong D3DKMTOpenAdapterFromGdiDisplayName(LPCWSTR param_1)

{
  ulonglong uVar1;
  HDC local_28;
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
                    /* 0x2140  1230  D3DKMTOpenAdapterFromGdiDisplayName */
  if (g_systemCallFilterId == 5) {
    uVar1 = 0xc000001c;
  }
  else {
    local_20 = 0;
    uStack_1c = 0;
    uStack_18 = 0;
    uStack_14 = 0;
    local_28 = CreateDCW(param_1,param_1,(LPCWSTR)0x0,(DEVMODEW *)0x0);
    if (local_28 != (HDC)0x0) {
      uVar1 = D3DKMTOpenAdapterFromHdc(&local_28);
      if (-1 < (int)uVar1) {
        *(undefined4 *)(param_1 + 0x20) = local_20;
        *(ulonglong *)(param_1 + 0x22) = CONCAT44(uStack_18,uStack_1c);
        *(undefined4 *)(param_1 + 0x26) = uStack_14;
      }
      DeleteDC(local_28);
      return uVar1 & 0xffffffff;
    }
    uVar1 = 0xc0000001;
  }
  return uVar1;
}



===== ExtCreateRegion @ 1800021d0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

HRGN __stdcall ExtCreateRegion(XFORM *lpx,DWORD nCount,RGNDATA *lpData)

{
  char cVar1;
  bool bVar2;
  HRGN pHVar3;
  undefined8 uVar4;
  undefined7 extraout_var;
  
                    /* 0x21d0  1495  ExtCreateRegion */
  if ((lpData == (RGNDATA *)0x0) || (nCount < 0x20)) {
    LastErrorValue = 0x57;
    return (HRGN)0x0;
  }
  if ((lpx == (XFORM *)0x0) && ((lpData->rdh).nCount == 1)) {
    if (nCount < 0x30) {
      LastErrorValue = 0x57;
      return (HRGN)0x0;
    }
    pHVar3 = CreateRectRgn(*(int *)lpData->Buffer,lpData[1].rdh.dwSize,lpData[1].rdh.iType,
                           lpData[1].rdh.nCount);
  }
  else {
    cVar1 = IsGdiTrackHCreatePresent();
    if (cVar1 == '\0') {
      pHVar3 = (HRGN)NtGdiExtCreateRegion(lpx,nCount,lpData);
    }
    else {
      uVar4 = NtGdiExtCreateRegion();
      pHVar3 = (HRGN)GdiTrackHCreate(uVar4);
    }
    bVar2 = IsEdgeGdiProcess();
    if ((int)CONCAT71(extraout_var,bVar2) != 0) {
      pHVar3 = (HRGN)(**(code **)(g_pEdgeGdi + 0xd0))(pHVar3);
      return pHVar3;
    }
  }
  return pHVar3;
}



===== SetDIBitsToDevice @ 1800022c0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

int __stdcall
SetDIBitsToDevice(HDC hdc,int xDest,int yDest,DWORD w,DWORD h,int xSrc,int ySrc,UINT StartScan,
                 UINT cLines,void *lpvBits,BITMAPINFO *lpbmi,UINT ColorUse)

{
  bool bVar1;
  int iVar2;
  undefined7 extraout_var;
  
                    /* 0x22c0  1922  SetDIBitsToDevice */
  bVar1 = IsEdgeGdiProcess();
  if ((int)CONCAT71(extraout_var,bVar1) == 0) {
    iVar2 = SetDIBitsToDevice(hdc,xDest,yDest,w,h,xSrc,ySrc,StartScan,cLines,lpvBits,lpbmi,ColorUse)
    ;
  }
  else {
    iVar2 = (**(code **)(g_pEdgeGdi + 0xa0))
                      (hdc,xDest,yDest,w,h,xSrc,ySrc,StartScan,cLines,lpvBits,lpbmi,ColorUse);
  }
  return iVar2;
}



===== CreateDCW @ 180002400 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

HDC __stdcall CreateDCW(LPCWSTR pwszDriver,LPCWSTR pwszDevice,LPCWSTR pszPort,DEVMODEW *pdm)

{
  bool bVar1;
  char cVar2;
  undefined7 extraout_var;
  undefined8 uVar3;
  HDC pHVar4;
  
                    /* 0x2400  1066  CreateDCW */
  bVar1 = IsEdgeGdiProcess();
  if ((int)CONCAT71(extraout_var,bVar1) == 0) {
    cVar2 = IsGdiTrackHCreatePresent();
    if (cVar2 == '\0') {
      pHVar4 = (HDC)bCreateDCW(pwszDriver,pwszDevice,(longlong)pszPort,pdm,0,0);
    }
    else {
      uVar3 = bCreateDCW(pwszDriver,pwszDevice,(longlong)pszPort,pdm,0,0);
      pHVar4 = (HDC)GdiTrackHCreate(uVar3);
    }
  }
  else {
    pHVar4 = (HDC)(**(code **)(g_pEdgeGdi + 0x28))(pwszDriver,pwszDevice,pszPort,pdm);
  }
  return pHVar4;
}



===== SetMapMode @ 1800024b0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

int __stdcall SetMapMode(HDC hdc,int iMode)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  undefined7 extraout_var;
  
                    /* 0x24b0  1933  SetMapMode */
  bVar1 = IsEdgeGdiProcess();
  if ((int)CONCAT71(extraout_var,bVar1) != 0) {
    iVar3 = (**(code **)(g_pEdgeGdi + 0xa8))(hdc,iMode);
    return iVar3;
  }
  cVar2 = IsSetMapModePresent();
  if (cVar2 == '\0') {
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x0001800024e8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar3 = SetMapMode(hdc,iMode);
  return iVar3;
}



===== D3DKMTOpenAdapterFromHdc @ 180002530 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

undefined8 D3DKMTOpenAdapterFromHdc(undefined8 *param_1)

{
  undefined8 uVar1;
  bool bVar2;
  int iVar3;
  undefined7 extraout_var;
  undefined8 uVar4;
  
                    /* 0x2530  1231  D3DKMTOpenAdapterFromHdc */
  uVar1 = *param_1;
  bVar2 = IsEdgeGdiProcess();
  if ((int)CONCAT71(extraout_var,bVar2) != 0) {
    iVar3 = (**(code **)(g_pEdgeGdi + 0xc0))(param_1);
    if (iVar3 == 0) {
      uVar4 = 0xc0000001;
      goto LAB_180002558;
    }
  }
  uVar4 = NtGdiDdDDIOpenAdapterFromHdc(param_1);
LAB_180002558:
  *param_1 = uVar1;
  return uVar4;
}



===== SetDIBits @ 180002590 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

int __stdcall
SetDIBits(HDC hdc,HBITMAP hbm,UINT start,UINT cLines,void *lpBits,BITMAPINFO *lpbmi,UINT ColorUse)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  undefined7 extraout_var;
  
                    /* 0x2590  1921  SetDIBits */
  bVar1 = IsEdgeGdiProcess();
  if ((int)CONCAT71(extraout_var,bVar1) == 0) {
    cVar2 = IsBitBltPresent();
    if (cVar2 == '\0') {
      iVar3 = 0;
    }
    else {
      iVar3 = SetDIBits(hdc,hbm,start,cLines,lpBits,lpbmi,ColorUse);
    }
  }
  else {
    iVar3 = (**(code **)(g_pEdgeGdi + 0x98))(hdc,hbm,start,cLines,lpBits,lpbmi,ColorUse);
  }
  return iVar3;
}



===== CreateRectRgnIndirect @ 180002680 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

HRGN __stdcall CreateRectRgnIndirect(RECT *lprect)

{
  undefined8 *puVar1;
  byte bVar2;
  char cVar3;
  bool bVar4;
  uint uVar5;
  int iVar6;
  HRGN pHVar7;
  undefined8 uVar8;
  undefined7 extraout_var;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined4 *puVar12;
  ulonglong uVar13;
  int iVar14;
  undefined4 uVar15;
  undefined8 local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  
                    /* 0x2680  1098  CreateRectRgnIndirect */
  iVar10 = lprect->right;
  iVar9 = lprect->left;
  iVar14 = lprect->bottom;
  iVar6 = lprect->top;
  iVar11 = iVar9;
  if (iVar9 <= iVar10) {
    iVar11 = iVar10;
    iVar10 = iVar9;
  }
  iVar9 = iVar6;
  if (iVar6 <= iVar14) {
    iVar9 = iVar14;
    iVar14 = iVar6;
  }
  if ((((iVar10 < -0x8000000) || (iVar14 < -0x8000000)) || (0x7ffffff < iVar11)) ||
     (0x7ffffff < iVar9)) {
    LastErrorValue = 0x57;
    return (HRGN)0x0;
  }
  uVar15 = 2;
  pHVar7 = (HRGN)hGetPEBHandle(2,0);
  if (pHVar7 == (HRGN)0x0) {
    pHVar7 = (HRGN)NtGdiCreateRectRgn(0,0,1);
  }
  uVar5 = HANDLE_TO_INDEX((uint)pHVar7);
  uVar13 = (ulonglong)uVar5;
  if (uVar5 < gMaxGdiHandleCount) {
    local_38 = 0;
    local_48 = 0;
    uStack_40 = 0;
    uVar8 = IS_INDEX_IN_USER_SHARED_ARRAY(uVar5);
    if ((int)uVar8 == 0) {
      iVar6 = NtGdiGetEntry(uVar13 & 0xffffffff,&local_48);
      if (iVar6 < 0) goto LAB_1800028a7;
    }
    else {
      puVar1 = (undefined8 *)(pGdiSharedHandleTable + (uVar13 & 0xffff) * 0x18);
      local_48 = *puVar1;
      uStack_40 = puVar1[1];
      local_38 = *(ulonglong *)(pGdiSharedHandleTable + 0x10 + (uVar13 & 0xffff) * 0x18);
    }
    if (((uStack_40._6_1_ == '\x04') && (uStack_40._4_2_ == (short)((ulonglong)pHVar7 >> 0x10))) &&
       ((((uint)uStack_40 & 0xfffffffe) == gW32PID &&
        ((local_38 != 0 &&
         (bVar2 = 0x40 - ((byte)gCookie & 0x3f) & 0x3f,
         puVar12 = (undefined4 *)((local_38 >> bVar2 | local_38 << 0x40 - bVar2) ^ gCookie),
         puVar12 != (undefined4 *)0x0)))))) {
      if ((iVar10 == iVar11) || (iVar14 == iVar9)) {
        iVar10 = 0;
        uVar15 = 1;
        iVar11 = iVar10;
        iVar14 = iVar10;
        iVar9 = iVar10;
      }
      puVar12[1] = uVar15;
      puVar12[2] = iVar10;
      puVar12[3] = iVar14;
      puVar12[4] = iVar11;
      puVar12[5] = iVar9;
      *puVar12 = 0x30;
      goto LAB_18000281d;
    }
  }
LAB_1800028a7:
  if (pHVar7 != (HRGN)0x0) {
    DeleteRegion(pHVar7);
    pHVar7 = (HRGN)0x0;
  }
LAB_18000281d:
  cVar3 = IsGdiTrackHCreatePresent();
  if (cVar3 != '\0') {
    pHVar7 = (HRGN)GdiTrackHCreate(pHVar7);
  }
  bVar4 = IsEdgeGdiProcess();
  if ((int)CONCAT71(extraout_var,bVar4) == 0) {
    return pHVar7;
  }
  pHVar7 = (HRGN)(**(code **)(g_pEdgeGdi + 0xd0))(pHVar7);
  return pHVar7;
}



===== IsEdgeGdiProcess @ 180002910 =====

bool IsEdgeGdiProcess(void)

{
  InitOnceExecuteOnce((PINIT_ONCE)&DAT_1800256e8,CheckIsEdgeGdiProcessOnce,(PVOID)0x0,(LPVOID *)0x0)
  ;
  return g_pEdgeGdi != 0;
}



===== CreateRectRgn @ 180002950 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

HRGN __stdcall CreateRectRgn(int x1,int y1,int x2,int y2)

{
  undefined8 *puVar1;
  byte bVar2;
  char cVar3;
  int iVar4;
  HRGN pHVar5;
  ulonglong uVar6;
  uint uVar7;
  uint uVar8;
  ulonglong uVar9;
  int iVar10;
  int iVar11;
  undefined4 *puVar12;
  undefined4 uVar13;
  undefined8 local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  
                    /* 0x2950  1097  CreateRectRgn */
  iVar10 = x1;
  if (x1 <= x2) {
    iVar10 = x2;
    x2 = x1;
  }
  iVar11 = y1;
  if (y1 <= y2) {
    iVar11 = y2;
    y2 = y1;
  }
  if ((((x2 < -0x8000000) || (y2 < -0x8000000)) || (0x7ffffff < iVar10)) || (0x7ffffff < iVar11)) {
    LastErrorValue = 0x57;
    return (HRGN)0x0;
  }
  uVar13 = 2;
  pHVar5 = (HRGN)hGetPEBHandle(2,0);
  if (pHVar5 == (HRGN)0x0) {
    pHVar5 = (HRGN)NtGdiCreateRectRgn(0,0,1);
  }
  uVar7 = (uint)((ulonglong)pHVar5 >> 8) & 0xff0000;
  uVar6 = (ulonglong)pHVar5 & 0xffff;
  uVar8 = uVar7 | (uint)uVar6;
  if ((uVar8 < 0x10000) ||
     (uVar9 = (ulonglong)uVar8,
     (uint)*(byte *)(pGdiSharedHandleTable + 0xd + uVar6 * 0x18) == uVar7 >> 0x10)) {
    uVar9 = uVar6;
  }
  uVar7 = (uint)uVar9;
  if (uVar7 < gMaxGdiHandleCount) {
    local_38 = 0;
    uVar9 = uVar9 & 0xffff;
    local_48 = 0;
    uStack_40 = 0;
    if ((uVar7 < 0x10000) ||
       ((uint)*(byte *)(pGdiSharedHandleTable + 0xd + uVar9 * 0x18) == uVar7 >> 0x10)) {
      puVar1 = (undefined8 *)(pGdiSharedHandleTable + uVar9 * 0x18);
      local_48 = *puVar1;
      uStack_40 = puVar1[1];
      local_38 = *(ulonglong *)(pGdiSharedHandleTable + 0x10 + uVar9 * 0x18);
    }
    else {
      iVar4 = NtGdiGetEntry(0,&local_48);
      if (iVar4 < 0) goto LAB_180002a66;
    }
    if ((((uStack_40._6_1_ == '\x04') && (uStack_40._4_2_ == (short)((ulonglong)pHVar5 >> 0x10))) &&
        (((uint)uStack_40 & 0xfffffffe) == gW32PID)) &&
       ((local_38 != 0 &&
        (bVar2 = 0x40 - ((byte)gCookie & 0x3f) & 0x3f,
        puVar12 = (undefined4 *)((local_38 >> bVar2 | local_38 << 0x40 - bVar2) ^ gCookie),
        puVar12 != (undefined4 *)0x0)))) {
      if ((x2 == iVar10) || (y2 == iVar11)) {
        x2 = 0;
        uVar13 = 1;
        iVar10 = x2;
        y2 = x2;
        iVar11 = x2;
      }
      puVar12[1] = uVar13;
      puVar12[2] = x2;
      puVar12[3] = y2;
      puVar12[4] = iVar10;
      puVar12[5] = iVar11;
      *puVar12 = 0x30;
      goto LAB_180002bad;
    }
  }
LAB_180002a66:
  if (pHVar5 != (HRGN)0x0) {
    DeleteRegion(pHVar5);
    pHVar5 = (HRGN)0x0;
  }
LAB_180002bad:
  cVar3 = IsGdiTrackHCreatePresent();
  if (cVar3 != '\0') {
    pHVar5 = (HRGN)GdiTrackHCreate(pHVar5);
  }
  InitOnceExecuteOnce((PINIT_ONCE)&DAT_1800256e8,CheckIsEdgeGdiProcessOnce,(PVOID)0x0,(LPVOID *)0x0)
  ;
  if (g_pEdgeGdi == 0) {
    return pHVar5;
  }
  pHVar5 = (HRGN)(**(code **)(g_pEdgeGdi + 0xd0))(pHVar5);
  return pHVar5;
}



===== hGetPEBHandle @ 180002c40 =====

ulonglong hGetPEBHandle(int param_1,uint param_2)

{
  int *piVar1;
  longlong lVar2;
  byte bVar3;
  void *pvVar4;
  int iVar5;
  ulonglong uVar6;
  ulonglong *puVar7;
  ulonglong uVar8;
  longlong lVar9;
  char cVar10;
  longlong *plVar11;
  uint uVar12;
  uint uVar13;
  ulonglong uVar14;
  uint *puVar15;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
                    /* 0x2c40  2001  hGetPEBHandle */
  pvVar4 = ProcessEnvironmentBlock;
  uVar6 = 0;
  plVar11 = (longlong *)((longlong)ProcessEnvironmentBlock + 0x140);
  lVar9 = (longlong)param_1;
  cVar10 = '\x04';
  if (param_1 != 2) {
    cVar10 = '\x10';
  }
  uVar8 = uVar6;
  if (*plVar11 == 0) {
    LOCK();
    lVar2 = *plVar11;
    if (lVar2 == 0) {
      *plVar11 = (longlong)&ExceptionList;
    }
    UNLOCK();
    if (lVar2 == 0) {
      if (*(int *)((longlong)pvVar4 + lVar9 * 4 + 0x148) != 0) {
        for (puVar7 = (ulonglong *)
                      (plVar11 + (ulonglong)*(uint *)(&gCacheHandleOffsets + lVar9 * 4) + 3);
            uVar8 = uVar6,
            puVar7 != (ulonglong *)
                      (plVar11 +
                      (ulonglong)*(uint *)(&gHandleCacheSize + lVar9 * 4) +
                      (ulonglong)*(uint *)(&gCacheHandleOffsets + lVar9 * 4) + 3);
            puVar7 = puVar7 + 1) {
          uVar8 = *puVar7;
          if (uVar8 != 0) {
            *puVar7 = 0;
            piVar1 = (int *)((longlong)pvVar4 + lVar9 * 4 + 0x148);
            *piVar1 = *piVar1 + -1;
            uVar12 = (uint)(uVar8 >> 8) & 0xff0000;
            uVar6 = uVar8 & 0xffff;
            uVar13 = uVar12 | (uint)uVar6;
            if ((uVar13 < 0x10000) ||
               (uVar14 = (ulonglong)uVar13,
               (uint)*(byte *)(pGdiSharedHandleTable + 0xd + uVar6 * 0x18) == uVar12 >> 0x10)) {
              uVar14 = uVar6;
            }
            if ((uint)uVar14 < gMaxGdiHandleCount) {
              local_18 = 0;
              uVar6 = uVar14 & 0xffff;
              local_28 = 0;
              uStack_20 = 0;
              if (((uint)uVar14 < 0x10000) ||
                 ((uint)*(byte *)(pGdiSharedHandleTable + 0xd + uVar6 * 0x18) ==
                  (uint)(uVar14 >> 0x10))) {
                uStack_20 = *(undefined8 *)(pGdiSharedHandleTable + uVar6 * 0x18 + 8);
                local_18 = *(ulonglong *)(pGdiSharedHandleTable + 0x10 + uVar6 * 0x18);
              }
              else {
                iVar5 = NtGdiGetEntry(uVar14,&local_28);
                if (iVar5 < 0) goto LAB_180002d97;
              }
              if (((((uStack_20._6_1_ == cVar10) && (uStack_20._4_2_ == (short)(uVar8 >> 0x10))) &&
                   (((uint)uStack_20 & 0xfffffffe) == gW32PID)) &&
                  ((local_18 != 0 &&
                   (bVar3 = 0x40 - ((byte)gCookie & 0x3f) & 0x3f,
                   puVar15 = (uint *)((local_18 >> bVar3 | local_18 << 0x40 - bVar3) ^ gCookie),
                   puVar15 != (uint *)0x0)))) && (((byte)*puVar15 & 0xb) == 1)) {
                uVar12 = *puVar15 & 0xfffffffe;
                *puVar15 = uVar12;
                if ((param_1 == 0) && (puVar15[1] != param_2)) {
                  *puVar15 = uVar12 | 4;
                  puVar15[1] = param_2;
                }
                break;
              }
            }
LAB_180002d97:
            uVar8 = 0;
            break;
          }
        }
      }
      *plVar11 = 0;
    }
  }
  return uVar8;
}



===== HANDLE_TO_INDEX @ 180002e70 =====

uint HANDLE_TO_INDEX(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1 & 0xffff;
  uVar1 = param_1 >> 8 & 0xff0000 | uVar2;
  if ((uVar1 < 0x10000) ||
     ((uint)*(byte *)(pGdiSharedHandleTable + 0xd + (ulonglong)uVar2 * 0x18) == param_1 >> 0x18)) {
    return uVar2;
  }
  return uVar1;
}



===== CombineRgn @ 180002eb0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

int __stdcall CombineRgn(HRGN hrgnDst,HRGN hrgnSrc1,HRGN hrgnSrc2,int iMode)

{
  undefined8 *puVar1;
  uint uVar2;
  uint uVar3;
  byte bVar4;
  HRGN pHVar5;
  int iVar6;
  int iVar7;
  undefined8 uVar8;
  uint uVar9;
  uint uVar10;
  ulonglong uVar11;
  uint *puVar12;
  ulonglong uVar13;
  uint *puVar14;
  ulonglong uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint *puVar19;
  longlong lVar20;
  HRGN local_res8;
  HRGN local_res10;
  HRGN local_res18;
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  
                    /* 0x2eb0  1049  CombineRgn */
  uVar16 = 0;
  local_res8 = hrgnDst;
  local_res10 = hrgnSrc1;
  local_res18 = hrgnSrc2;
  InitOnceExecuteOnce((PINIT_ONCE)&DAT_1800256e8,CheckIsEdgeGdiProcessOnce,(PVOID)0x0,(LPVOID *)0x0)
  ;
  if ((g_pEdgeGdi != 0) &&
     (((iVar6 = (**(code **)(g_pEdgeGdi + 200))(&local_res8), iVar6 == 0 ||
       (iVar6 = (**(code **)(g_pEdgeGdi + 200))(&local_res10), iVar6 == 0)) ||
      (iVar6 = (**(code **)(g_pEdgeGdi + 200))(&local_res18), iVar6 == 0)))) {
    return 0;
  }
  uVar9 = (uint)((ulonglong)local_res8 >> 8) & 0xff0000;
  uVar13 = (ulonglong)local_res8 & 0xffff;
  uVar10 = uVar9 | (uint)uVar13;
  if ((uVar10 < 0x10000) ||
     (uVar15 = (ulonglong)uVar10,
     (uint)*(byte *)(pGdiSharedHandleTable + 0xd + uVar13 * 0x18) == uVar9 >> 0x10)) {
    uVar15 = uVar13;
  }
  uVar9 = (uint)uVar15;
  puVar12 = (uint *)0x0;
  if (uVar9 < gMaxGdiHandleCount) {
    local_48 = 0;
    uVar15 = uVar15 & 0xffff;
    local_58 = 0;
    uStack_50 = 0;
    if ((uVar9 < 0x10000) ||
       ((uint)*(byte *)(pGdiSharedHandleTable + 0xd + uVar15 * 0x18) == uVar9 >> 0x10)) {
      puVar1 = (undefined8 *)(pGdiSharedHandleTable + uVar15 * 0x18);
      local_58 = *puVar1;
      uStack_50 = puVar1[1];
      local_48 = *(ulonglong *)(pGdiSharedHandleTable + 0x10 + uVar15 * 0x18);
    }
    else {
      iVar6 = NtGdiGetEntry(0,&local_58);
      if (iVar6 < 0) goto LAB_180003062;
    }
    if ((((uStack_50._6_1_ == '\x04') && (uStack_50._4_2_ == (short)((ulonglong)local_res8 >> 0x10))
         ) && (((uint)uStack_50 & 0xfffffffe) == gW32PID)) && (local_48 != 0)) {
      bVar4 = -((byte)gCookie & 0x3f) & 0x3f;
      puVar12 = (uint *)((local_48 >> bVar4 | local_48 << 0x40 - bVar4) ^ gCookie);
    }
  }
LAB_180003062:
  uVar13 = (ulonglong)local_res10 & 0xffff;
  uVar9 = (uint)((ulonglong)local_res10 >> 8) & 0xff0000;
  uVar10 = uVar9 | (uint)uVar13;
  if ((uVar10 < 0x10000) ||
     (uVar15 = (ulonglong)uVar10,
     (uint)*(byte *)(pGdiSharedHandleTable + 0xd + uVar13 * 0x18) == uVar9 >> 0x10)) {
    uVar15 = uVar13;
  }
  uVar13 = 0;
  if ((uint)uVar15 < gMaxGdiHandleCount) {
    local_48 = 0;
    uVar11 = uVar15 & 0xffff;
    local_58 = 0;
    uStack_50 = 0;
    if (((uint)uVar15 < 0x10000) ||
       ((uint)*(byte *)(pGdiSharedHandleTable + 0xd + uVar11 * 0x18) == (uint)(uVar15 >> 0x10))) {
      puVar1 = (undefined8 *)(pGdiSharedHandleTable + uVar11 * 0x18);
      local_58 = *puVar1;
      uStack_50 = puVar1[1];
      local_48 = *(ulonglong *)(pGdiSharedHandleTable + 0x10 + uVar11 * 0x18);
    }
    else {
      iVar6 = NtGdiGetEntry(uVar15,&local_58);
      if (iVar6 < 0) goto LAB_180003161;
    }
    if ((((uStack_50._6_1_ == '\x04') &&
         (uStack_50._4_2_ == (short)((ulonglong)local_res10 >> 0x10))) &&
        (((uint)uStack_50 & 0xfffffffe) == gW32PID)) && (local_48 != 0)) {
      bVar4 = -((byte)gCookie & 0x3f) & 0x3f;
      uVar13 = (local_48 >> bVar4 | local_48 << 0x40 - bVar4) ^ gCookie;
    }
  }
LAB_180003161:
  if ((puVar12 == (uint *)0x0) || (uVar13 == 0)) goto LAB_180003170;
  iVar6 = *(int *)(uVar13 + 4);
  puVar14 = (uint *)(uVar13 + 8);
  if (2 < iVar6) goto LAB_180003170;
  if (iMode == 5) {
LAB_18000329d:
    lVar20 = pGdiSharedHandleTable;
    if (iVar6 != 2) {
      if (iVar6 != 1) {
        if (iVar6 == 3) goto LAB_180003170;
        goto LAB_1800033f0;
      }
      goto LAB_1800032b1;
    }
    goto LAB_18000335f;
  }
  uVar15 = (ulonglong)local_res18 & 0xffff;
  uVar9 = (uint)((ulonglong)local_res18 >> 8) & 0xff0000;
  uVar10 = uVar9 | (uint)uVar15;
  if ((uVar10 < 0x10000) ||
     (uVar11 = (ulonglong)uVar10,
     (uint)*(byte *)(pGdiSharedHandleTable + 0xd + uVar15 * 0x18) == uVar9 >> 0x10)) {
    uVar11 = uVar15;
  }
  if (gMaxGdiHandleCount <= (uint)uVar11) goto LAB_180003170;
  local_48 = 0;
  uVar15 = uVar11 & 0xffff;
  local_58 = 0;
  uStack_50 = 0;
  if (((uint)uVar11 < 0x10000) ||
     ((uint)*(byte *)(pGdiSharedHandleTable + 0xd + uVar15 * 0x18) == (uint)(uVar11 >> 0x10))) {
    puVar1 = (undefined8 *)(pGdiSharedHandleTable + uVar15 * 0x18);
    local_58 = *puVar1;
    uStack_50 = puVar1[1];
    local_48 = *(ulonglong *)(pGdiSharedHandleTable + 0x10 + uVar15 * 0x18);
  }
  else {
    iVar7 = NtGdiGetEntry(uVar11,&local_58);
    if (iVar7 < 0) goto LAB_180003170;
  }
  if ((((uStack_50._6_1_ != '\x04') || (uStack_50._4_2_ != (short)((ulonglong)local_res18 >> 0x10)))
      || (((uint)uStack_50 & 0xfffffffe) != gW32PID)) ||
     (((local_48 == 0 ||
       (bVar4 = -((byte)gCookie & 0x3f) & 0x3f,
       uVar15 = (local_48 >> bVar4 | local_48 << 0x40 - bVar4) ^ gCookie, uVar15 == 0)) ||
      (uVar9 = *(uint *)(uVar15 + 4), 2 < uVar9)))) goto LAB_180003170;
  puVar19 = (uint *)(uVar15 + 8);
  lVar20 = pGdiSharedHandleTable;
  if (iMode == 1) {
    if ((uVar9 != 1) && (iVar6 != 1)) {
      uVar9 = *puVar14;
      uVar10 = *puVar19;
      if ((int)uVar10 < (int)uVar9) {
LAB_1800036f9:
        if (((*(int *)(uVar13 + 0x10) <= *(int *)(uVar15 + 0x10)) &&
            (*(int *)(uVar15 + 0xc) <= *(int *)(uVar13 + 0xc))) &&
           (*(int *)(uVar13 + 0x14) <= *(int *)(uVar15 + 0x14))) goto LAB_18000335f;
      }
      else {
        if (((*(int *)(uVar15 + 0x10) <= *(int *)(uVar13 + 0x10)) &&
            (*(int *)(uVar13 + 0xc) <= *(int *)(uVar15 + 0xc))) &&
           (*(int *)(uVar15 + 0x14) <= *(int *)(uVar13 + 0x14))) {
          puVar14 = puVar19;
          goto LAB_18000335f;
        }
        if ((int)uVar10 <= (int)uVar9) goto LAB_1800036f9;
      }
      if ((((int)uVar9 < *(int *)(uVar15 + 0x10)) && ((int)uVar10 < *(int *)(uVar13 + 0x10))) &&
         ((*(int *)(uVar13 + 0xc) < *(int *)(uVar15 + 0x14) &&
          (*(int *)(uVar15 + 0xc) < *(int *)(uVar13 + 0x14))))) {
LAB_180003170:
        iVar6 = NtGdiCombineRgn(local_res8,local_res10,local_res18,iMode);
        return iVar6;
      }
    }
LAB_1800032b1:
    pHVar5 = local_res8;
    uVar13 = (ulonglong)local_res8 & 0xffff;
    uVar16 = (uint)((ulonglong)local_res8 >> 8) & 0xff0000;
    uVar9 = uVar16 | (uint)uVar13;
    if ((uVar9 < 0x10000) ||
       (uVar15 = (ulonglong)uVar9,
       (uint)*(byte *)(pGdiSharedHandleTable + 0xd + uVar13 * 0x18) == uVar16 >> 0x10)) {
      uVar15 = uVar13;
    }
    if ((uint)uVar15 < gMaxGdiHandleCount) {
      local_48 = 0;
      local_58 = 0;
      uStack_50 = 0;
      lVar20 = pGdiSharedHandleTable;
      uVar8 = IS_INDEX_IN_USER_SHARED_ARRAY((uint)uVar15);
      if ((int)uVar8 == 0) {
        iVar6 = NtGdiGetEntry(uVar15 & 0xffffffff,&local_58);
        if (iVar6 < 0) goto LAB_1800032ff;
      }
      else {
        puVar1 = (undefined8 *)(lVar20 + (uVar15 & 0xffff) * 0x18);
        local_58 = *puVar1;
        uStack_50 = puVar1[1];
        local_48 = *(ulonglong *)(lVar20 + 0x10 + (uVar15 & 0xffff) * 0x18);
      }
      if ((((uStack_50._6_1_ == '\x04') && (uStack_50._4_2_ == (short)((ulonglong)pHVar5 >> 0x10)))
          && (((uint)uStack_50 & 0xfffffffe) == gW32PID)) &&
         ((local_48 != 0 &&
          (bVar4 = 0x40 - ((byte)gCookie & 0x3f) & 0x3f,
          puVar14 = (uint *)((local_48 >> bVar4 | local_48 << 0x40 - bVar4) ^ gCookie),
          puVar14 != (uint *)0x0)))) {
        puVar14[1] = 1;
        puVar14[2] = 0;
        puVar14[3] = 0;
        puVar14[4] = 0;
        puVar14[5] = 0;
        *puVar14 = *puVar14 | 0x20;
        uVar16 = 1;
        goto LAB_1800033f0;
      }
    }
LAB_1800032ff:
    iVar6 = NtGdiSetRectRgn(pHVar5,0,0,0,0);
    uVar16 = (uint)(iVar6 != 0);
    goto LAB_1800033f0;
  }
  if ((iMode == 2) || (iMode == 3)) {
    if (iVar6 == 1) {
      puVar14 = (uint *)0x0;
      if (uVar9 != 1) {
        puVar14 = puVar19;
      }
      iVar6 = (uVar9 != 1) + 1;
      goto LAB_18000329d;
    }
    if (uVar9 != 1) {
      if (iMode != 2) goto LAB_180003170;
      uVar8 = iRectRelation((int *)puVar14,(int *)puVar19);
      if ((int)uVar8 == 1) {
        puVar14 = puVar19;
      }
      else if ((int)uVar8 != 2) goto LAB_180003170;
    }
  }
  else {
    if (iMode != 4) goto LAB_180003170;
    if (iVar6 == 1) goto LAB_1800032b1;
    if (uVar9 == 1) goto LAB_18000335f;
    uVar9 = *puVar14;
    uVar10 = *puVar19;
    if ((int)uVar10 < (int)uVar9) {
LAB_180003328:
      if (((*(int *)(uVar13 + 0x10) <= *(int *)(uVar15 + 0x10)) &&
          (*(int *)(uVar15 + 0xc) <= *(int *)(uVar13 + 0xc))) &&
         (*(int *)(uVar13 + 0x14) <= *(int *)(uVar15 + 0x14))) goto LAB_1800032b1;
    }
    else {
      if (((*(int *)(uVar15 + 0x10) <= *(int *)(uVar13 + 0x10)) &&
          (*(int *)(uVar13 + 0xc) <= *(int *)(uVar15 + 0xc))) &&
         (*(int *)(uVar15 + 0x14) <= *(int *)(uVar13 + 0x14))) goto LAB_180003170;
      if ((int)uVar10 <= (int)uVar9) goto LAB_180003328;
    }
    if ((((int)uVar9 < *(int *)(uVar15 + 0x10)) && ((int)uVar10 < *(int *)(uVar13 + 0x10))) &&
       ((*(int *)(uVar13 + 0xc) < *(int *)(uVar15 + 0x14) &&
        (*(int *)(uVar15 + 0xc) < *(int *)(uVar13 + 0x14))))) goto LAB_180003170;
  }
LAB_18000335f:
  pHVar5 = local_res8;
  uVar9 = puVar14[3];
  uVar10 = puVar14[2];
  uVar2 = puVar14[1];
  uVar3 = *puVar14;
  uVar17 = (uint)((ulonglong)local_res8 >> 8) & 0xff0000;
  uVar13 = (ulonglong)local_res8 & 0xffff;
  uVar18 = uVar17 | (uint)uVar13;
  if ((uVar18 < 0x10000) ||
     (uVar15 = (ulonglong)uVar18, (uint)*(byte *)(lVar20 + 0xd + uVar13 * 0x18) == uVar17 >> 0x10))
  {
    uVar15 = uVar13;
  }
  if ((uint)uVar15 < gMaxGdiHandleCount) {
    local_48 = 0;
    local_58 = 0;
    uStack_50 = 0;
    uVar8 = IS_INDEX_IN_USER_SHARED_ARRAY((uint)uVar15);
    if ((int)uVar8 == 0) {
      iVar6 = NtGdiGetEntry(uVar15 & 0xffffffff,&local_58);
      if (iVar6 < 0) goto LAB_1800033b8;
    }
    else {
      puVar1 = (undefined8 *)(lVar20 + (uVar15 & 0xffff) * 0x18);
      local_58 = *puVar1;
      uStack_50 = puVar1[1];
      local_48 = *(ulonglong *)(lVar20 + 0x10 + (uVar15 & 0xffff) * 0x18);
    }
    if ((((uStack_50._6_1_ == '\x04') && (uStack_50._4_2_ == (short)((ulonglong)pHVar5 >> 0x10))) &&
        (((uint)uStack_50 & 0xfffffffe) == gW32PID)) &&
       ((local_48 != 0 &&
        (bVar4 = 0x40 - ((byte)gCookie & 0x3f) & 0x3f,
        puVar14 = (uint *)((local_48 >> bVar4 | local_48 << 0x40 - bVar4) ^ gCookie),
        puVar14 != (uint *)0x0)))) {
      if ((uVar3 == uVar10) || (uVar2 == uVar9)) {
        puVar14[1] = 1;
        puVar14[2] = 0;
        puVar14[3] = 0;
        puVar14[4] = 0;
        puVar14[5] = 0;
        *puVar14 = *puVar14 | 0x20;
        *puVar12 = *puVar12 | 0x20;
        return 2;
      }
      puVar14[2] = uVar3;
      puVar14[3] = uVar2;
      puVar14[4] = uVar10;
      puVar14[5] = uVar9;
      if ((int)uVar10 < (int)uVar3) {
        puVar14[2] = uVar10;
        puVar14[4] = uVar3;
      }
      if ((int)uVar9 < (int)uVar2) {
        puVar14[3] = uVar9;
        puVar14[5] = uVar2;
      }
      puVar14[1] = 2;
      *puVar14 = *puVar14 | 0x20;
      *puVar12 = *puVar12 | 0x20;
      return 2;
    }
  }
LAB_1800033b8:
  iVar6 = NtGdiSetRectRgn(pHVar5,uVar3,uVar2,uVar10,uVar9);
  if (iVar6 != 0) {
    *puVar12 = *puVar12 | 0x20;
    return 2;
  }
LAB_1800033f0:
  *puVar12 = *puVar12 | 0x20;
  return uVar16;
}



===== IS_INDEX_IN_USER_SHARED_ARRAY @ 180003810 =====

undefined8 IS_INDEX_IN_USER_SHARED_ARRAY(uint param_1)

{
  if ((param_1 < 0x10000) ||
     ((uint)*(byte *)(pGdiSharedHandleTable + 0xd + (ulonglong)(ushort)param_1 * 0x18) ==
      param_1 >> 0x10)) {
    return 1;
  }
  return 0;
}



===== iRectRelation @ 180003850 =====

undefined8 iRectRelation(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_1;
  iVar2 = *param_2;
  if (iVar1 <= iVar2) {
    if (((param_2[2] <= param_1[2]) && (param_1[1] <= param_2[1])) && (param_2[3] <= param_1[3])) {
      return 2;
    }
    if (iVar1 < iVar2) goto LAB_18000389f;
  }
  if (((param_1[2] <= param_2[2]) && (param_2[1] <= param_1[1])) && (param_1[3] <= param_2[3])) {
    return 1;
  }
LAB_18000389f:
  if (((iVar1 < param_2[2]) && (iVar2 < param_1[2])) &&
     ((param_1[1] < param_2[3] && (param_2[1] < param_1[3])))) {
    return 0;
  }
  return 3;
}



===== bCreateDCW @ 1800038e0 =====

void bCreateDCW(wchar_t *param_1,wchar_t *param_2,longlong param_3,undefined8 param_4,
               undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  undefined8 *puVar2;
  undefined4 uVar3;
  undefined8 *puVar4;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  
                    /* 0x38e0  1987  bCreateDCW */
  puVar2 = (undefined8 *)0x0;
  puVar4 = (undefined8 *)0x0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  if (param_2 == (wchar_t *)0x0) {
LAB_180003928:
    uVar3 = 0;
    if (param_1 != (wchar_t *)0x0) {
      iVar1 = _wcsicmp(param_1,L"DISPLAY");
      if (iVar1 == 0) {
        uVar3 = 1;
        goto LAB_180003970;
      }
      iVar1 = _wcsnicmp(param_1,L"\\\\.\\DISPLAY",0xb);
      if (iVar1 == 0) {
        uVar3 = 1;
        goto LAB_180003957;
      }
    }
    param_1 = param_2;
    if (param_2 == (wchar_t *)0x0) goto LAB_180003970;
  }
  else {
    iVar1 = _wcsnicmp(param_2,L"\\\\.\\DISPLAY",0xb);
    if (iVar1 != 0) goto LAB_180003928;
    uVar3 = 1;
    param_1 = param_2;
  }
LAB_180003957:
  RtlInitUnicodeString(&local_38,param_1);
  puVar2 = &local_38;
LAB_180003970:
  if (param_3 != 0) {
    RtlInitUnicodeString(&local_28,param_3);
    puVar4 = &local_28;
  }
  hdcCreateDCW(puVar2,puVar4,param_4,uVar3,param_5,param_6);
  return;
}



===== DeleteDC @ 180003a50 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

BOOL __stdcall DeleteDC(HDC hdc)

{
  char cVar1;
  int iVar2;
  BOOL BVar3;
  
                    /* 0x3a50  1415  DeleteDC */
  InitOnceExecuteOnce((PINIT_ONCE)&DAT_1800256e8,CheckIsEdgeGdiProcessOnce,(PVOID)0x0,(LPVOID *)0x0)
  ;
  if (g_pEdgeGdi != 0) {
    BVar3 = (**(code **)(g_pEdgeGdi + 0x48))(hdc);
    return BVar3;
  }
  iVar2 = InternalDeleteDC();
  if (iVar2 == 0) {
    BVar3 = 0;
  }
  else {
    cVar1 = IsGdiTrackHCreatePresent();
    if (cVar1 != '\0') {
      GdiTrackHDelete(hdc);
    }
    BVar3 = 1;
  }
  return BVar3;
}



===== SetRectRgn @ 180003ae0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

BOOL __stdcall SetRectRgn(HRGN hrgn,int left,int top,int right,int bottom)

{
  undefined8 *puVar1;
  byte bVar2;
  HRGN pHVar3;
  BOOL BVar4;
  int iVar5;
  ulonglong uVar6;
  uint uVar7;
  uint uVar8;
  ulonglong uVar9;
  uint *puVar10;
  HRGN local_res8;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_res8 = hrgn;
                    /* 0x3ae0  1945  SetRectRgn */
  InitOnceExecuteOnce((PINIT_ONCE)&DAT_1800256e8,CheckIsEdgeGdiProcessOnce,(PVOID)0x0,(LPVOID *)0x0)
  ;
  if ((g_pEdgeGdi != 0) && (iVar5 = (**(code **)(g_pEdgeGdi + 200))(&local_res8), iVar5 == 0)) {
    return 0;
  }
  pHVar3 = local_res8;
  uVar6 = (ulonglong)local_res8 & 0xffff;
  uVar7 = (uint)((ulonglong)local_res8 >> 8) & 0xff0000;
  uVar8 = uVar7 | (uint)uVar6;
  if ((uVar8 < 0x10000) ||
     (uVar9 = (ulonglong)uVar8,
     (uint)*(byte *)(pGdiSharedHandleTable + 0xd + uVar6 * 0x18) == uVar7 >> 0x10)) {
    uVar9 = uVar6;
  }
  uVar7 = (uint)uVar9;
  if (uVar7 < gMaxGdiHandleCount) {
    local_18 = 0;
    uVar9 = uVar9 & 0xffff;
    local_28 = 0;
    uStack_20 = 0;
    if ((uVar7 < 0x10000) ||
       ((uint)*(byte *)(pGdiSharedHandleTable + 0xd + uVar9 * 0x18) == uVar7 >> 0x10)) {
      puVar1 = (undefined8 *)(pGdiSharedHandleTable + uVar9 * 0x18);
      local_28 = *puVar1;
      uStack_20 = puVar1[1];
      local_18 = *(ulonglong *)(pGdiSharedHandleTable + 0x10 + uVar9 * 0x18);
    }
    else {
      iVar5 = NtGdiGetEntry(0,&local_28);
      if (iVar5 < 0) goto LAB_180003b7b;
    }
    if ((((uStack_20._6_1_ == '\x04') && (uStack_20._4_2_ == (short)((ulonglong)pHVar3 >> 0x10))) &&
        (((uint)uStack_20 & 0xfffffffe) == gW32PID)) &&
       ((local_18 != 0 &&
        (bVar2 = 0x40 - ((byte)gCookie & 0x3f) & 0x3f,
        puVar10 = (uint *)((local_18 >> bVar2 | local_18 << 0x40 - bVar2) ^ gCookie),
        puVar10 != (uint *)0x0)))) {
      if ((left == right) || (top == bottom)) {
        puVar10[1] = 1;
        puVar10[2] = 0;
        puVar10[3] = 0;
        puVar10[4] = 0;
        puVar10[5] = 0;
        *puVar10 = *puVar10 | 0x20;
        return 1;
      }
      puVar10[2] = left;
      puVar10[3] = top;
      puVar10[4] = right;
      puVar10[5] = bottom;
      if (right < left) {
        puVar10[2] = right;
        puVar10[4] = left;
      }
      if (bottom < top) {
        puVar10[3] = bottom;
        puVar10[5] = top;
      }
      puVar10[1] = 2;
      *puVar10 = *puVar10 | 0x20;
      return 1;
    }
  }
LAB_180003b7b:
  BVar4 = NtGdiSetRectRgn(pHVar3,left,top,right,bottom);
  return BVar4;
}



===== GetRgnBox @ 180003d10 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

int __stdcall GetRgnBox(HRGN hrgn,LPRECT lprc)

{
  undefined8 *puVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  HRGN local_res8 [4];
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_res8[0] = hrgn;
                    /* 0x3d10  1737  GetRgnBox */
  InitOnceExecuteOnce((PINIT_ONCE)&DAT_1800256e8,CheckIsEdgeGdiProcessOnce,(PVOID)0x0,(LPVOID *)0x0)
  ;
  if ((g_pEdgeGdi != 0) && (iVar3 = (**(code **)(g_pEdgeGdi + 200))(local_res8), iVar3 == 0)) {
    return 0;
  }
  uVar4 = (uint)((ulonglong)local_res8[0] >> 8) & 0xff0000;
  uVar7 = (ulonglong)local_res8[0] & 0xffff;
  uVar5 = uVar4 | (uint)uVar7;
  if ((uVar5 < 0x10000) ||
     (uVar6 = (ulonglong)uVar5,
     (uint)*(byte *)(pGdiSharedHandleTable + 0xd + uVar7 * 0x18) == uVar4 >> 0x10)) {
    uVar6 = uVar7;
  }
  uVar4 = (uint)uVar6;
  if (uVar4 < gMaxGdiHandleCount) {
    local_18 = 0;
    uVar6 = uVar6 & 0xffff;
    local_28 = 0;
    uStack_20 = 0;
    if ((uVar4 < 0x10000) ||
       ((uint)*(byte *)(pGdiSharedHandleTable + 0xd + uVar6 * 0x18) == uVar4 >> 0x10)) {
      puVar1 = (undefined8 *)(pGdiSharedHandleTable + uVar6 * 0x18);
      local_28 = *puVar1;
      uStack_20 = puVar1[1];
      local_18 = *(ulonglong *)(pGdiSharedHandleTable + 0x10 + uVar6 * 0x18);
    }
    else {
      iVar3 = NtGdiGetEntry(0,&local_28);
      if (iVar3 < 0) goto LAB_180003dfb;
    }
    if ((((uStack_20._6_1_ == '\x04') &&
         (uStack_20._4_2_ == (short)((ulonglong)local_res8[0] >> 0x10))) &&
        (((uint)uStack_20 & 0xfffffffe) == gW32PID)) &&
       ((local_18 != 0 &&
        (bVar2 = 0x40 - ((byte)gCookie & 0x3f) & 0x3f,
        uVar7 = (local_18 >> bVar2 | local_18 << 0x40 - bVar2) ^ gCookie, uVar7 != 0)))) {
      if (*(int *)(uVar7 + 4) == 1) {
        lprc->left = 0;
        lprc->top = 0;
        lprc->right = 0;
        lprc->bottom = 0;
        return 1;
      }
      if (*(int *)(uVar7 + 4) == 2) {
        lprc->left = *(LONG *)(uVar7 + 8);
        lprc->top = *(LONG *)(uVar7 + 0xc);
        lprc->right = *(LONG *)(uVar7 + 0x10);
        lprc->bottom = *(LONG *)(uVar7 + 0x14);
        return 2;
      }
    }
  }
LAB_180003dfb:
  iVar3 = NtGdiGetRgnBox(local_res8[0],lprc);
  return iVar3;
}



===== RectInRegion @ 180003ed0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

BOOL __stdcall RectInRegion(HRGN hrgn,RECT *lprect)

{
  undefined8 *puVar1;
  int iVar2;
  byte bVar3;
  BOOL BVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  HRGN local_res8 [4];
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_res8[0] = hrgn;
                    /* 0x3ed0  1836  RectInRegion */
  InitOnceExecuteOnce((PINIT_ONCE)&DAT_1800256e8,CheckIsEdgeGdiProcessOnce,(PVOID)0x0,(LPVOID *)0x0)
  ;
  if ((g_pEdgeGdi != 0) && (iVar5 = (**(code **)(g_pEdgeGdi + 200))(local_res8), iVar5 == 0)) {
    return 0;
  }
  uVar7 = (uint)((ulonglong)local_res8[0] >> 8) & 0xff0000;
  uVar10 = (ulonglong)local_res8[0] & 0xffff;
  uVar8 = uVar7 | (uint)uVar10;
  if ((uVar8 < 0x10000) ||
     (uVar9 = (ulonglong)uVar8,
     (uint)*(byte *)(pGdiSharedHandleTable + 0xd + uVar10 * 0x18) == uVar7 >> 0x10)) {
    uVar9 = uVar10;
  }
  if (gMaxGdiHandleCount <= (uint)uVar9) {
LAB_180003f5c:
    BVar4 = NtGdiRectInRegion(local_res8[0],lprect);
    return BVar4;
  }
  local_18 = 0;
  uVar10 = uVar9 & 0xffff;
  local_28 = 0;
  uStack_20 = 0;
  if (((uint)uVar9 < 0x10000) ||
     ((uint)*(byte *)(pGdiSharedHandleTable + 0xd + uVar10 * 0x18) == (uint)(uVar9 >> 0x10))) {
    puVar1 = (undefined8 *)(pGdiSharedHandleTable + uVar10 * 0x18);
    local_28 = *puVar1;
    uStack_20 = puVar1[1];
    local_18 = *(ulonglong *)(pGdiSharedHandleTable + 0x10 + uVar10 * 0x18);
  }
  else {
    iVar5 = NtGdiGetEntry(uVar9,&local_28);
    if (iVar5 < 0) goto LAB_180003f5c;
  }
  if ((((uStack_20._6_1_ != '\x04') ||
       (uStack_20._4_2_ != (short)((ulonglong)local_res8[0] >> 0x10))) ||
      (((uint)uStack_20 & 0xfffffffe) != gW32PID)) ||
     ((local_18 == 0 ||
      (bVar3 = 0x40 - ((byte)gCookie & 0x3f) & 0x3f,
      uVar10 = (local_18 >> bVar3 | local_18 << 0x40 - bVar3) ^ gCookie, uVar10 == 0))))
  goto LAB_180003f5c;
  if (*(int *)(uVar10 + 4) == 1) {
    return 0;
  }
  if (*(int *)(uVar10 + 4) != 2) goto LAB_180003f5c;
  iVar12 = lprect->left;
  iVar2 = lprect->top;
  iVar6 = lprect->bottom;
  iVar5 = lprect->right;
  iVar13 = iVar5;
  if (iVar5 < iVar12) {
    iVar13 = iVar12;
    iVar12 = iVar5;
  }
  iVar5 = iVar2;
  if (iVar6 < iVar2) {
    iVar5 = iVar6;
    iVar6 = iVar2;
  }
  iVar2 = *(int *)(uVar10 + 8);
  iVar11 = 0;
  if (iVar12 < iVar2) {
LAB_1800040c2:
    if (((*(int *)(uVar10 + 0x10) <= iVar13) && (iVar5 <= *(int *)(uVar10 + 0xc))) &&
       (*(int *)(uVar10 + 0x14) <= iVar6)) {
      return 1;
    }
  }
  else {
    if (((iVar13 <= *(int *)(uVar10 + 0x10)) && (*(int *)(uVar10 + 0xc) <= iVar5)) &&
       (iVar6 <= *(int *)(uVar10 + 0x14))) {
      iVar11 = 2;
      goto LAB_1800040a6;
    }
    if (iVar12 <= iVar2) goto LAB_1800040c2;
  }
  if (((iVar13 <= iVar2) || (*(int *)(uVar10 + 0x10) <= iVar12)) ||
     ((iVar6 <= *(int *)(uVar10 + 0xc) || (*(int *)(uVar10 + 0x14) <= iVar5)))) {
    iVar11 = 3;
  }
LAB_1800040a6:
  return (BOOL)(iVar11 != 3);
}



===== SelectObject @ 180004150 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

HGDIOBJ __stdcall SelectObject(HDC hdc,HGDIOBJ h)

{
  HGDIOBJ pvVar1;
  
                    /* 0x4150  1904  SelectObject */
  InitOnceExecuteOnce((PINIT_ONCE)&DAT_1800256e8,CheckIsEdgeGdiProcessOnce,(PVOID)0x0,(LPVOID *)0x0)
  ;
  if (g_pEdgeGdi == 0) {
    pvVar1 = (HGDIOBJ)SelectObjectImpl(hdc,h);
  }
  else {
    pvVar1 = (HGDIOBJ)(**(code **)(g_pEdgeGdi + 0x90))();
  }
  return pvVar1;
}



===== OffsetRgn @ 1800041d0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

int __stdcall OffsetRgn(HRGN hrgn,int x,int y)

{
  undefined8 *puVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  ulonglong uVar5;
  uint uVar6;
  uint uVar7;
  ulonglong uVar8;
  uint *puVar9;
  uint uVar10;
  uint uVar11;
  HRGN local_res8;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_res8 = hrgn;
                    /* 0x41d0  1804  OffsetRgn */
  InitOnceExecuteOnce((PINIT_ONCE)&DAT_1800256e8,CheckIsEdgeGdiProcessOnce,(PVOID)0x0,(LPVOID *)0x0)
  ;
  if ((g_pEdgeGdi != 0) && (iVar3 = (**(code **)(g_pEdgeGdi + 200))(&local_res8), iVar3 == 0)) {
    return 0;
  }
  uVar6 = (uint)((ulonglong)local_res8 >> 8) & 0xff0000;
  uVar5 = (ulonglong)local_res8 & 0xffff;
  uVar7 = uVar6 | (uint)uVar5;
  if ((uVar7 < 0x10000) ||
     (uVar8 = (ulonglong)uVar7,
     (uint)*(byte *)(pGdiSharedHandleTable + 0xd + uVar5 * 0x18) == uVar6 >> 0x10)) {
    uVar8 = uVar5;
  }
  uVar6 = (uint)uVar8;
  if (uVar6 < gMaxGdiHandleCount) {
    local_18 = 0;
    uVar5 = uVar8 & 0xffff;
    local_28 = 0;
    uStack_20 = 0;
    if ((uVar6 < 0x10000) ||
       ((uint)*(byte *)(pGdiSharedHandleTable + 0xd + uVar5 * 0x18) == uVar6 >> 0x10)) {
      puVar1 = (undefined8 *)(pGdiSharedHandleTable + uVar5 * 0x18);
      local_28 = *puVar1;
      uStack_20 = puVar1[1];
      local_18 = *(ulonglong *)(pGdiSharedHandleTable + 0x10 + uVar5 * 0x18);
    }
    else {
      iVar3 = NtGdiGetEntry(uVar8,&local_28);
      if (iVar3 < 0) goto LAB_1800042af;
    }
    if ((((uStack_20._6_1_ == '\x04') && (uStack_20._4_2_ == (short)((ulonglong)local_res8 >> 0x10))
         ) && (((uint)uStack_20 & 0xfffffffe) == gW32PID)) &&
       ((local_18 != 0 &&
        (bVar2 = 0x40 - ((byte)gCookie & 0x3f) & 0x3f,
        puVar9 = (uint *)((local_18 >> bVar2 | local_18 << 0x40 - bVar2) ^ gCookie),
        puVar9 != (uint *)0x0)))) {
      if (puVar9[1] == 1) {
        return 1;
      }
      if (puVar9[1] == 2) {
        if ((int)puVar9[4] <= (int)puVar9[2]) {
          return 2;
        }
        if ((int)puVar9[5] <= (int)puVar9[3]) {
          return 2;
        }
        uVar6 = puVar9[2] + x;
        uVar10 = puVar9[3] + y;
        uVar7 = puVar9[4] + x;
        uVar11 = puVar9[5] + y;
        uVar4 = uVar6 & 0xf8000000;
        if ((((uVar4 == 0xf8000000 || uVar4 == 0) &&
             (((uVar11 & 0xf8000000) == 0 || ((uVar11 & 0xf8000000) == 0xf8000000)))) &&
            (((uVar7 & 0xf8000000) == 0 || ((uVar7 & 0xf8000000) == 0xf8000000)))) &&
           (((uVar10 & 0xf8000000) == 0 || ((uVar10 & 0xf8000000) == 0xf8000000)))) {
          puVar9[2] = uVar6;
          puVar9[3] = uVar10;
          puVar9[4] = uVar7;
          puVar9[5] = uVar11;
          *puVar9 = *puVar9 | 0x20;
          return 2;
        }
        return 0;
      }
    }
  }
LAB_1800042af:
  iVar3 = NtGdiOffsetRgn(local_res8,x,y);
  return iVar3;
}



===== ExtTextOutW @ 180004490 =====

BOOL __stdcall
ExtTextOutW(HDC hdc,int x,int y,UINT options,RECT *lprect,LPCWSTR lpString,UINT c,INT *lpDx)

{
  char cVar1;
  int iVar2;
  BOOL BVar3;
  undefined8 unaff_retaddr;
  undefined4 uVar4;
  
                    /* 0x4490  1500  ExtTextOutW */
  uVar4 = 0x49414e;
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    BVar3 = 0;
  }
  else {
    iVar2 = GditPushCallerInfo(unaff_retaddr);
    BVar3 = ExtTextOutWImpl(hdc,x,y,options,lprect,lpString,c,lpDx,uVar4);
    if (iVar2 != 0) {
      GditPopCallerInfo();
    }
  }
  return BVar3;
}



===== GetRegionData @ 180004560 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

DWORD __stdcall GetRegionData(HRGN hrgn,DWORD nCount,LPRGNDATA lpRgnData)

{
  DWORD DVar1;
  int iVar2;
  HRGN local_res8;
  
  local_res8 = hrgn;
                    /* 0x4560  1735  GetRegionData */
  InitOnceExecuteOnce((PINIT_ONCE)&DAT_1800256e8,CheckIsEdgeGdiProcessOnce,(PVOID)0x0,(LPVOID *)0x0)
  ;
  if ((g_pEdgeGdi != 0) && (iVar2 = (**(code **)(g_pEdgeGdi + 200))(&local_res8), iVar2 == 0)) {
    return 0;
  }
  DVar1 = 0;
  if (lpRgnData != (LPRGNDATA)0x0) {
    DVar1 = nCount;
  }
  DVar1 = NtGdiGetRegionData(local_res8,DVar1,lpRgnData);
  return DVar1;
}



===== GdiEntry13 @ 1800045f0 =====

undefined4 GdiEntry13(void)

{
                    /* 0x45f0  1553  GdiEntry13 */
  return *(undefined4 *)(pGdiSharedMemory + 0x180090);
}



===== vSetPldc @ 180004610 =====

void vSetPldc(ulonglong param_1,ulonglong *param_2)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
                    /* 0x4610  2006  vSetPldc */
  uVar3 = (uint)(param_1 >> 8) & 0xff0000;
  uVar6 = param_1 & 0xffff;
  uVar4 = uVar3 | (uint)uVar6;
  if ((uVar4 < 0x10000) ||
     (uVar5 = (ulonglong)uVar4,
     (uint)*(byte *)(pGdiSharedHandleTable + 0xd + uVar6 * 0x18) == uVar3 >> 0x10)) {
    uVar5 = uVar6;
  }
  uVar3 = (uint)uVar5;
  if (uVar3 < gMaxGdiHandleCount) {
    local_18 = 0;
    uVar5 = uVar5 & 0xffff;
    local_28 = 0;
    uStack_20 = 0;
    if ((uVar3 < 0x10000) ||
       ((uint)*(byte *)(pGdiSharedHandleTable + 0xd + uVar5 * 0x18) == uVar3 >> 0x10)) {
      uStack_20 = *(undefined8 *)(pGdiSharedHandleTable + uVar5 * 0x18 + 8);
      local_18 = *(ulonglong *)(pGdiSharedHandleTable + 0x10 + uVar5 * 0x18);
    }
    else {
      iVar2 = NtGdiGetEntry(0,&local_28);
      if (iVar2 < 0) goto LAB_180004719;
    }
    if ((((uStack_20._6_1_ == '\x01') && (uStack_20._4_2_ == (short)(param_1 >> 0x10))) &&
        (((uint)uStack_20 & 0xfffffffe) == gW32PID)) &&
       ((local_18 != 0 &&
        (bVar1 = 0x40 - ((byte)gCookie & 0x3f) & 0x3f,
        uVar6 = (local_18 >> bVar1 | local_18 << 0x40 - bVar1) ^ gCookie, uVar6 != 0)))) {
      *(ulonglong **)(uVar6 + 0x90) = param_2;
    }
  }
LAB_180004719:
  if (param_2 != (ulonglong *)0x0) {
    *param_2 = param_1;
  }
  return;
}



===== GetObjectType @ 180004740 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

DWORD __stdcall GetObjectType(HGDIOBJ h)

{
  char cVar1;
  DWORD DVar2;
  
                    /* 0x4740  1719  GetObjectType */
  InitOnceExecuteOnce((PINIT_ONCE)&DAT_1800256e8,CheckIsEdgeGdiProcessOnce,(PVOID)0x0,(LPVOID *)0x0)
  ;
  if (g_pEdgeGdi != 0) {
    DVar2 = (**(code **)(g_pEdgeGdi + 0x60))(h);
    return DVar2;
  }
  cVar1 = IsGetObjectAPresent();
  if (cVar1 == '\0') {
    DVar2 = 0;
  }
  else {
    DVar2 = GetObjectType(h);
  }
  return DVar2;
}



===== MoveToEx @ 1800047c0 =====

BOOL __stdcall MoveToEx(HDC hdc,int x,int y,LPPOINT lppt)

{
  char cVar1;
  BOOL BVar2;
  undefined4 uVar3;
  
                    /* 0x47c0  1801  MoveToEx */
  uVar3 = 0x49414e;
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    BVar2 = 0;
  }
  else {
    BVar2 = MoveToExImpl(hdc,x,y,lppt,uVar3);
  }
  return BVar2;
}



===== ExtSelectClipRgn @ 180004830 =====

int __stdcall ExtSelectClipRgn(HDC hdc,HRGN hrgn,int mode)

{
  char cVar1;
  int iVar2;
  
                    /* 0x4830  1498  ExtSelectClipRgn */
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    iVar2 = 0;
  }
  else {
    iVar2 = ExtSelectClipRgnImpl(hdc,hrgn,mode);
  }
  return iVar2;
}



===== SetTextColor @ 180004890 =====

COLORREF __stdcall SetTextColor(HDC hdc,COLORREF color)

{
  char cVar1;
  COLORREF CVar2;
  
                    /* 0x4890  1951  SetTextColor */
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    CVar2 = 0xffffffff;
  }
  else {
    CVar2 = SetTextColorImpl(hdc,color);
  }
  return CVar2;
}



===== SetBkColor @ 1800048e0 =====

COLORREF __stdcall SetBkColor(HDC hdc,COLORREF color)

{
  char cVar1;
  COLORREF CVar2;
  
                    /* 0x48e0  1911  SetBkColor */
  cVar1 = IsCreatePatternBrushPresent();
  if (cVar1 == '\0') {
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x00018000490f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CVar2 = SetBkColor(hdc,color);
  return CVar2;
}



===== SetBkMode @ 180004930 =====

int __stdcall SetBkMode(HDC hdc,int mode)

{
  char cVar1;
  int iVar2;
  
                    /* 0x4930  1912  SetBkMode */
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    iVar2 = 0;
  }
  else {
    iVar2 = SetBkModeImpl(hdc,mode);
  }
  return iVar2;
}



===== GetStockObject @ 180004980 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

HGDIOBJ __stdcall GetStockObject(int i)

{
  char cVar1;
  HGDIOBJ pvVar2;
  
                    /* 0x4980  1738  GetStockObject */
  InitOnceExecuteOnce((PINIT_ONCE)&DAT_1800256e8,CheckIsEdgeGdiProcessOnce,(PVOID)0x0,(LPVOID *)0x0)
  ;
  if (g_pEdgeGdi != 0) {
    pvVar2 = (HGDIOBJ)(**(code **)(g_pEdgeGdi + 0x70))(i);
    return pvVar2;
  }
  cVar1 = IsGetObjectAPresent();
  if (cVar1 == '\0') {
    pvVar2 = (HGDIOBJ)0x0;
  }
  else {
    pvVar2 = GetStockObject(i);
  }
  return pvVar2;
}



===== SetTextAlign @ 180004a00 =====

UINT __stdcall SetTextAlign(HDC hdc,UINT align)

{
  char cVar1;
  UINT UVar2;
  
                    /* 0x4a00  1949  SetTextAlign */
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    UVar2 = 0xffffffff;
  }
  else {
    UVar2 = SetTextAlignImpl(hdc,align);
  }
  return UVar2;
}



===== BitBlt @ 180004a50 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

BOOL __stdcall BitBlt(HDC hdc,int x,int y,int cx,int cy,HDC hdcSrc,int x1,int y1,DWORD rop)

{
  char cVar1;
  BOOL BVar2;
  
                    /* 0x4a50  1034  BitBlt */
  InitOnceExecuteOnce((PINIT_ONCE)&DAT_1800256e8,CheckIsEdgeGdiProcessOnce,(PVOID)0x0,(LPVOID *)0x0)
  ;
  if (g_pEdgeGdi == (undefined8 *)0x0) {
    cVar1 = IsBitBltPresent();
    if (cVar1 == '\0') {
      BVar2 = 0;
    }
    else {
      BVar2 = BitBlt(hdc,x,y,cx,cy,hdcSrc,x1,y1,rop);
    }
  }
  else {
    BVar2 = (*(code *)*g_pEdgeGdi)(hdc,x,y,cx,cy,hdcSrc,x1,y1,rop);
  }
  return BVar2;
}



===== GetObjectW @ 180004b80 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

int __stdcall GetObjectW(HANDLE h,int c,LPVOID pv)

{
  int iVar1;
  
                    /* 0x4b80  1720  GetObjectW */
  InitOnceExecuteOnce((PINIT_ONCE)&DAT_1800256e8,CheckIsEdgeGdiProcessOnce,(PVOID)0x0,(LPVOID *)0x0)
  ;
  if (g_pEdgeGdi == 0) {
    iVar1 = GetObjectW(h,c,pv);
  }
  else {
    iVar1 = (**(code **)(g_pEdgeGdi + 0x68))();
  }
  return iVar1;
}



===== SelectClipRgn @ 180004c00 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

int __stdcall SelectClipRgn(HDC hdc,HRGN hrgn)

{
  int iVar1;
  
                    /* 0x4c00  1902  SelectClipRgn */
  InitOnceExecuteOnce((PINIT_ONCE)&DAT_1800256e8,CheckIsEdgeGdiProcessOnce,(PVOID)0x0,(LPVOID *)0x0)
  ;
  if (g_pEdgeGdi == 0) {
    iVar1 = SelectClipRgnImpl(hdc,hrgn);
  }
  else {
    iVar1 = (**(code **)(g_pEdgeGdi + 0x88))();
  }
  return iVar1;
}



===== CreateDIBSection @ 180004c80 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

HBITMAP __stdcall
CreateDIBSection(HDC hdc,BITMAPINFO *lpbmi,UINT usage,void **ppvBits,HANDLE hSection,DWORD offset)

{
  char cVar1;
  HBITMAP pHVar2;
  
                    /* 0x4c80  1069  CreateDIBSection */
  InitOnceExecuteOnce((PINIT_ONCE)&DAT_1800256e8,CheckIsEdgeGdiProcessOnce,(PVOID)0x0,(LPVOID *)0x0)
  ;
  if (g_pEdgeGdi == 0) {
    cVar1 = IsBitBltPresent();
    if (cVar1 == '\0') {
      pHVar2 = (HBITMAP)0x0;
    }
    else {
      pHVar2 = CreateDIBSection(hdc,lpbmi,usage,ppvBits,hSection,offset);
    }
  }
  else {
    pHVar2 = (HBITMAP)(**(code **)(g_pEdgeGdi + 8))(hdc,lpbmi,usage,ppvBits,hSection,offset);
  }
  return pHVar2;
}



===== CreateCompatibleDC @ 180004d60 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

HDC __stdcall CreateCompatibleDC(HDC hdc)

{
  char cVar1;
  HDC pHVar2;
  
                    /* 0x4d60  1064  CreateCompatibleDC */
  InitOnceExecuteOnce((PINIT_ONCE)&DAT_1800256e8,CheckIsEdgeGdiProcessOnce,(PVOID)0x0,(LPVOID *)0x0)
  ;
  if (g_pEdgeGdi != 0) {
    pHVar2 = (HDC)(**(code **)(g_pEdgeGdi + 0x20))(hdc);
    return pHVar2;
  }
  cVar1 = IsCreateCompatibleDCPresent();
  if (cVar1 == '\0') {
    pHVar2 = (HDC)0x0;
  }
  else {
    pHVar2 = CreateCompatibleDC(hdc);
  }
  return pHVar2;
}



===== SetStretchBltMode @ 180004de0 =====

int __stdcall SetStretchBltMode(HDC hdc,int mode)

{
  char cVar1;
  int iVar2;
  
                    /* 0x4de0  1947  SetStretchBltMode */
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x000180004e0f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar2 = SetStretchBltModeImpl(hdc,mode);
  return iVar2;
}



===== GetDIBits @ 180004e30 =====

int __stdcall
GetDIBits(HDC hdc,HBITMAP hbm,UINT start,UINT cLines,LPVOID lpvBits,LPBITMAPINFO lpbmi,UINT usage)

{
  char cVar1;
  int iVar2;
  
                    /* 0x4e30  1669  GetDIBits */
  cVar1 = IsBitBltPresent();
  if (cVar1 == '\0') {
    iVar2 = 0;
  }
  else {
    iVar2 = GetDIBits(hdc,hbm,start,cLines,lpvBits,lpbmi,usage);
  }
  return iVar2;
}



===== GetTextExtentPoint32W @ 180004ec0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

BOOL __stdcall GetTextExtentPoint32W(HDC hdc,LPCWSTR lpString,int c,LPSIZE psizl)

{
  char cVar1;
  BOOL BVar2;
  
                    /* 0x4ec0  1755  GetTextExtentPoint32W */
  InitOnceExecuteOnce((PINIT_ONCE)&DAT_1800256e8,CheckIsEdgeGdiProcessOnce,(PVOID)0x0,(LPVOID *)0x0)
  ;
  if (g_pEdgeGdi == 0) {
    cVar1 = IsGetTextExtentPointWPresent();
    if (cVar1 == '\0') {
      BVar2 = 0;
    }
    else {
      BVar2 = GetTextExtentPoint32W(hdc,lpString,c,psizl);
    }
  }
  else {
    BVar2 = (**(code **)(g_pEdgeGdi + 0x80))(hdc,lpString,c,psizl);
  }
  return BVar2;
}



===== GetTextMetricsW @ 180004f70 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

BOOL __stdcall GetTextMetricsW(HDC hdc,LPTEXTMETRICW lptm)

{
  BOOL BVar1;
  
                    /* 0x4f70  1763  GetTextMetricsW */
  InitOnceExecuteOnce((PINIT_ONCE)&DAT_1800256e8,CheckIsEdgeGdiProcessOnce,(PVOID)0x0,(LPVOID *)0x0)
  ;
  if (g_pEdgeGdi == 0) {
    BVar1 = GetTextMetricsW(hdc,lptm);
  }
  else {
    BVar1 = (**(code **)(g_pEdgeGdi + 0x78))();
  }
  return BVar1;
}



===== GetClipRgn @ 180004fe0 =====

int __stdcall GetClipRgn(HDC hdc,HRGN hrgn)

{
  char cVar1;
  int iVar2;
  
                    /* 0x4fe0  1658  GetClipRgn */
  cVar1 = IsRectVisiblePresent();
  if (cVar1 == '\0') {
    iVar2 = 0;
  }
  else {
    iVar2 = GetClipRgn(hdc,hrgn);
  }
  return iVar2;
}



===== SetViewportOrgEx @ 180005030 =====

BOOL __stdcall SetViewportOrgEx(HDC hdc,int x,int y,LPPOINT lppt)

{
  char cVar1;
  BOOL BVar2;
  
                    /* 0x5030  1954  SetViewportOrgEx */
  cVar1 = IsSetMapModePresent();
  if (cVar1 == '\0') {
    BVar2 = 0;
  }
  else {
    BVar2 = SetViewportOrgEx(hdc,x,y,lppt);
  }
  return BVar2;
}



===== StretchBlt @ 1800050a0 =====

BOOL __stdcall
StretchBlt(HDC hdcDest,int xDest,int yDest,int wDest,int hDest,HDC hdcSrc,int xSrc,int ySrc,int wSrc
          ,int hSrc,DWORD rop)

{
  char cVar1;
  BOOL BVar2;
  
                    /* 0x50a0  1964  StretchBlt */
  cVar1 = IsBitBltPresent();
  if (cVar1 == '\0') {
    BVar2 = 0;
  }
  else {
    BVar2 = StretchBlt(hdcDest,xDest,yDest,wDest,hDest,hdcSrc,xSrc,ySrc,wSrc,hSrc,rop);
  }
  return BVar2;
}



===== GetTextAlign @ 180005160 =====

UINT __stdcall GetTextAlign(HDC hdc)

{
  char cVar1;
  UINT UVar2;
  
                    /* 0x5160  1745  GetTextAlign */
  cVar1 = IsGetTextExtentPointWPresent();
  if (cVar1 == '\0') {
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x000180005182. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  UVar2 = GetTextAlign(hdc);
  return UVar2;
}



===== CreateFontIndirectW @ 1800051a0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

HFONT __stdcall CreateFontIndirectW(LOGFONTW *lplf)

{
  char cVar1;
  HFONT pHVar2;
  
                    /* 0x51a0  1081  CreateFontIndirectW */
  InitOnceExecuteOnce((PINIT_ONCE)&DAT_1800256e8,CheckIsEdgeGdiProcessOnce,(PVOID)0x0,(LPVOID *)0x0)
  ;
  if (g_pEdgeGdi != 0) {
    pHVar2 = (HFONT)(**(code **)(g_pEdgeGdi + 0x18))(lplf);
    return pHVar2;
  }
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    pHVar2 = (HFONT)0x0;
  }
  else {
    pHVar2 = (HFONT)CreateFontIndirectWImpl(lplf);
  }
  return pHVar2;
}



===== GetCurrentObject @ 180005220 =====

HGDIOBJ __stdcall GetCurrentObject(HDC hdc,UINT type)

{
  char cVar1;
  HGDIOBJ pvVar2;
  
                    /* 0x5220  1662  GetCurrentObject */
  cVar1 = IsGetObjectAPresent();
  if (cVar1 == '\0') {
    pvVar2 = (HGDIOBJ)0x0;
  }
  else {
    pvVar2 = GetCurrentObject(hdc,type);
  }
  return pvVar2;
}



===== SetWindowOrgEx @ 180005270 =====

BOOL __stdcall SetWindowOrgEx(HDC hdc,int x,int y,LPPOINT lppt)

{
  char cVar1;
  BOOL BVar2;
  
                    /* 0x5270  1958  SetWindowOrgEx */
  cVar1 = IsCreatePatternBrushPresent();
  if (cVar1 == '\0') {
    BVar2 = 0;
  }
  else {
    BVar2 = SetWindowOrgEx(hdc,x,y,lppt);
  }
  return BVar2;
}



===== PatBlt @ 1800052e0 =====

BOOL __stdcall PatBlt(HDC hdc,int x,int y,int w,int h,DWORD rop)

{
  char cVar1;
  BOOL BVar2;
  
                    /* 0x52e0  1813  PatBlt */
  cVar1 = IsCreatePatternBrushPresent();
  if (cVar1 == '\0') {
    BVar2 = 0;
  }
  else {
    BVar2 = PatBlt(hdc,x,y,w,h,rop);
  }
  return BVar2;
}



===== CreateBitmap @ 180005360 =====

HBITMAP __stdcall CreateBitmap(int nWidth,int nHeight,UINT nPlanes,UINT nBitCount,void *lpBits)

{
  char cVar1;
  HBITMAP pHVar2;
  
                    /* 0x5360  1056  CreateBitmap */
  cVar1 = IsBitBltPresent();
  if (cVar1 == '\0') {
    pHVar2 = (HBITMAP)0x0;
  }
  else {
    pHVar2 = CreateBitmap(nWidth,nHeight,nPlanes,nBitCount,lpBits);
  }
  return pHVar2;
}



===== EqualRgn @ 1800053d0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

BOOL __stdcall EqualRgn(HRGN hrgn1,HRGN hrgn2)

{
  BOOL BVar1;
  int iVar2;
  HRGN local_res8;
  HRGN local_res10 [3];
  
  local_res8 = hrgn1;
  local_res10[0] = hrgn2;
                    /* 0x53d0  1489  EqualRgn */
  InitOnceExecuteOnce((PINIT_ONCE)&DAT_1800256e8,CheckIsEdgeGdiProcessOnce,(PVOID)0x0,(LPVOID *)0x0)
  ;
  if (g_pEdgeGdi == 0) {
LAB_18000540a:
    BVar1 = NtGdiEqualRgn(local_res8,local_res10[0]);
  }
  else {
    iVar2 = (**(code **)(g_pEdgeGdi + 200))(&local_res8);
    if (iVar2 != 0) {
      iVar2 = (**(code **)(g_pEdgeGdi + 200))(local_res10);
      if (iVar2 != 0) goto LAB_18000540a;
    }
    BVar1 = 0;
  }
  return BVar1;
}



===== CreateDIBitmap @ 180005470 =====

HBITMAP __stdcall
CreateDIBitmap(HDC hdc,BITMAPINFOHEADER *pbmih,DWORD flInit,void *pjBits,BITMAPINFO *pbmi,
              UINT iUsage)

{
  char cVar1;
  HBITMAP pHVar2;
  
                    /* 0x5470  1070  CreateDIBitmap */
  cVar1 = IsSetMapModePresent();
  if (cVar1 == '\0') {
    pHVar2 = (HBITMAP)0x0;
  }
  else {
    pHVar2 = CreateDIBitmap(hdc,pbmih,flInit,pjBits,pbmi,iUsage);
  }
  return pHVar2;
}



===== GetTextExtentPointW @ 1800054f0 =====

BOOL __stdcall GetTextExtentPointW(HDC hdc,LPCWSTR lpString,int c,LPSIZE lpsz)

{
  char cVar1;
  BOOL BVar2;
  
                    /* 0x54f0  1758  GetTextExtentPointW */
  cVar1 = IsGetTextExtentPointWPresent();
  if (cVar1 == '\0') {
    BVar2 = 0;
  }
  else {
    BVar2 = GetTextExtentPointW(hdc,lpString,c,lpsz);
  }
  return BVar2;
}



===== CreateCompatibleBitmap @ 180005560 =====

HBITMAP __stdcall CreateCompatibleBitmap(HDC hdc,int cx,int cy)

{
  char cVar1;
  HBITMAP pHVar2;
  
                    /* 0x5560  1063  CreateCompatibleBitmap */
  cVar1 = IsBitBltPresent();
  if (cVar1 == '\0') {
    return (HBITMAP)0x0;
  }
                    /* WARNING: Could not recover jumptable at 0x00018000559f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pHVar2 = (HBITMAP)CreateCompatibleBitmap(hdc,cx,cy);
  return pHVar2;
}



===== StretchDIBits @ 1800055d0 =====

int __stdcall
StretchDIBits(HDC hdc,int xDest,int yDest,int DestWidth,int DestHeight,int xSrc,int ySrc,
             int SrcWidth,int SrcHeight,void *lpBits,BITMAPINFO *lpbmi,UINT iUsage,DWORD rop)

{
  char cVar1;
  int iVar2;
  
                    /* 0x55d0  1965  StretchDIBits */
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    iVar2 = 0;
  }
  else {
    iVar2 = StretchDIBitsImpl(hdc,xDest,yDest,DestWidth,DestHeight,xSrc,ySrc,SrcWidth,SrcHeight,
                              lpBits,lpbmi,iUsage,rop);
  }
  return iVar2;
}



===== LineTo @ 1800056b0 =====

BOOL __stdcall LineTo(HDC hdc,int x,int y)

{
  char cVar1;
  BOOL BVar2;
  
                    /* 0x56b0  1781  LineTo */
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    BVar2 = 0;
  }
  else {
    BVar2 = LineToImpl(hdc,x,y);
  }
  return BVar2;
}



===== GetViewportOrgEx @ 180005710 =====

BOOL __stdcall GetViewportOrgEx(HDC hdc,LPPOINT lppoint)

{
  char cVar1;
  BOOL BVar2;
  
                    /* 0x5710  1766  GetViewportOrgEx */
  cVar1 = IsCreatePatternBrushPresent();
  if (cVar1 == '\0') {
    BVar2 = 0;
  }
  else {
    BVar2 = GetViewportOrgEx(hdc,lppoint);
  }
  return BVar2;
}



===== LPtoDP @ 180005760 =====

BOOL __stdcall LPtoDP(HDC hdc,LPPOINT lppt,int c)

{
  char cVar1;
  BOOL BVar2;
  
                    /* 0x5760  1779  LPtoDP */
  cVar1 = IsSetMapModePresent();
  if (cVar1 == '\0') {
    BVar2 = 0;
  }
  else {
    BVar2 = LPtoDP(hdc,lppt,c);
  }
  return BVar2;
}



===== GetFontData @ 1800057c0 =====

DWORD __stdcall GetFontData(HDC hdc,DWORD dwTable,DWORD dwOffset,PVOID pvBuffer,DWORD cjBuffer)

{
  char cVar1;
  DWORD DVar2;
  
                    /* 0x57c0  1684  GetFontData */
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    DVar2 = 0xffffffff;
  }
  else {
    DVar2 = GetFontDataImpl(hdc,dwTable,dwOffset,pvBuffer,cjBuffer);
  }
  return DVar2;
}



===== GetObjectA @ 180005840 =====

int __stdcall GetObjectA(HANDLE h,int c,LPVOID pv)

{
  char cVar1;
  int iVar2;
  
                    /* 0x5840  1718  GetObjectA */
  cVar1 = IsGetObjectAPresent();
  if (cVar1 == '\0') {
    iVar2 = 0;
  }
  else {
    iVar2 = GetObjectA(h,c,pv);
  }
  return iVar2;
}



===== SaveDC @ 1800058a0 =====

int __stdcall SaveDC(HDC hdc)

{
  char cVar1;
  int iVar2;
  
                    /* 0x58a0  1855  SaveDC */
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    return -1;
  }
                    /* WARNING: Could not recover jumptable at 0x0001800058c2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar2 = SaveDCImpl(hdc);
  return iVar2;
}



===== RestoreDC @ 1800058f0 =====

BOOL __stdcall RestoreDC(HDC hdc,int nSavedDC)

{
  char cVar1;
  BOOL BVar2;
  
                    /* 0x58f0  1848  RestoreDC */
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    BVar2 = 0;
  }
  else {
    BVar2 = RestoreDCImpl(hdc,nSavedDC);
  }
  return BVar2;
}



===== IntersectClipRect @ 180005940 =====

int __stdcall IntersectClipRect(HDC hdc,int left,int top,int right,int bottom)

{
  int iVar1;
  
                    /* 0x5940  1775  IntersectClipRect */
                    /* WARNING: Could not recover jumptable at 0x000180005950. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = IntersectClipRectImpl();
  return iVar1;
}



===== CreateSolidBrush @ 180005970 =====

HBRUSH __stdcall CreateSolidBrush(COLORREF color)

{
  char cVar1;
  HBRUSH pHVar2;
  
                    /* 0x5970  1104  CreateSolidBrush */
  cVar1 = IsBitBltPresent();
  if (cVar1 == '\0') {
    return (HBRUSH)0x0;
  }
                    /* WARNING: Could not recover jumptable at 0x000180005990. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pHVar2 = (HBRUSH)CreateSolidBrush(color);
  return pHVar2;
}



===== GetClipBox @ 1800059b0 =====

int __stdcall GetClipBox(HDC hdc,LPRECT lprect)

{
  char cVar1;
  int iVar2;
  
                    /* 0x59b0  1657  GetClipBox */
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    iVar2 = 0;
  }
  else {
    iVar2 = GetClipBoxImpl(hdc,lprect);
  }
  return iVar2;
}



===== SetWorldTransform @ 180005a00 =====

BOOL __stdcall SetWorldTransform(HDC hdc,XFORM *lpxf)

{
  char cVar1;
  BOOL BVar2;
  
                    /* 0x5a00  1959  SetWorldTransform */
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    BVar2 = 0;
  }
  else {
    BVar2 = SetWorldTransformImpl(hdc,lpxf);
  }
  return BVar2;
}



===== PolyBezierTo @ 180005a50 =====

BOOL __stdcall PolyBezierTo(HDC hdc,POINT *apt,DWORD cpt)

{
  char cVar1;
  BOOL BVar2;
  
                    /* 0x5a50  1822  PolyBezierTo */
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    BVar2 = 0;
  }
  else {
    BVar2 = PolyBezierToImpl(hdc,apt,cpt);
  }
  return BVar2;
}



===== ExtTextOutA @ 180005ab0 =====

BOOL __stdcall
ExtTextOutA(HDC hdc,int x,int y,UINT options,RECT *lprect,LPCSTR lpString,UINT c,INT *lpDx)

{
  char cVar1;
  int iVar2;
  BOOL BVar3;
  undefined8 unaff_retaddr;
  undefined4 uVar4;
  
                    /* 0x5ab0  1499  ExtTextOutA */
  uVar4 = 0x49414e;
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    BVar3 = 0;
  }
  else {
    iVar2 = GditPushCallerInfo(unaff_retaddr);
    BVar3 = ExtTextOutAImpl(hdc,x,y,options,lprect,lpString,c,lpDx,uVar4);
    if (iVar2 != 0) {
      GditPopCallerInfo();
    }
  }
  return BVar3;
}



===== GetGlyphOutlineW @ 180005b90 =====

DWORD __stdcall
GetGlyphOutlineW(HDC hdc,UINT uChar,UINT fuFormat,LPGLYPHMETRICS lpgm,DWORD cjBuffer,LPVOID pvBuffer
                ,MAT2 *lpmat2)

{
  char cVar1;
  DWORD DVar2;
  
                    /* 0x5b90  1695  GetGlyphOutlineW */
  cVar1 = IsGetKerningPairsAPresent();
  if (cVar1 == '\0') {
    DVar2 = 0;
  }
  else {
    DVar2 = GetGlyphOutlineW(hdc,uChar,fuFormat,lpgm,cjBuffer,pvBuffer,lpmat2);
  }
  return DVar2;
}



===== DrvQueryAdapterPopulationUniqueness @ 180005c20 =====

undefined4 DrvQueryAdapterPopulationUniqueness(void)

{
                    /* 0x5c20  1004   */
  return *(undefined4 *)(pGdiSharedMemory + 0x1800a0);
}



===== SetROP2 @ 180005c40 =====

int __stdcall SetROP2(HDC hdc,int rop2)

{
  char cVar1;
  int iVar2;
  
                    /* 0x5c40  1944  SetROP2 */
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    iVar2 = 0;
  }
  else {
    iVar2 = SetROP2(hdc,rop2);
  }
  return iVar2;
}



===== SetPixel @ 180005c90 =====

COLORREF __stdcall SetPixel(HDC hdc,int x,int y,COLORREF color)

{
  char cVar1;
  COLORREF CVar2;
  
                    /* 0x5c90  1940  SetPixel */
  cVar1 = IsSetMapModePresent();
  if (cVar1 == '\0') {
    CVar2 = 0;
  }
  else {
    CVar2 = SetPixel(hdc,x,y,color);
  }
  return CVar2;
}



===== CreatePen @ 180005d00 =====

HPEN __stdcall CreatePen(int iStyle,int cWidth,COLORREF color)

{
  char cVar1;
  HPEN pHVar2;
  
                    /* 0x5d00  1093  CreatePen */
  cVar1 = IsCreatePatternBrushPresent();
  if (cVar1 == '\0') {
    pHVar2 = (HPEN)0x0;
  }
  else {
    pHVar2 = CreatePen(iStyle,cWidth,color);
  }
  return pHVar2;
}



===== SetBitmapBits @ 180005d60 =====

LONG __stdcall SetBitmapBits(HBITMAP hbm,DWORD cb,void *pvBits)

{
  char cVar1;
  LONG LVar2;
  
                    /* 0x5d60  1909  SetBitmapBits */
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    LVar2 = 0;
  }
  else {
    LVar2 = SetBitmapBits(hbm,cb,pvBits);
  }
  return LVar2;
}



===== GetBkColor @ 180005dc0 =====

COLORREF __stdcall GetBkColor(HDC hdc)

{
  char cVar1;
  COLORREF CVar2;
  
                    /* 0x5dc0  1631  GetBkColor */
  cVar1 = IsCreatePatternBrushPresent();
  if (cVar1 == '\0') {
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x000180005de2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CVar2 = GetBkColor(hdc);
  return CVar2;
}



===== GetPixel @ 180005e00 =====

COLORREF __stdcall GetPixel(HDC hdc,int x,int y)

{
  char cVar1;
  COLORREF CVar2;
  
                    /* 0x5e00  1728  GetPixel */
  cVar1 = IsCreatePatternBrushPresent();
  if (cVar1 == '\0') {
    CVar2 = 0;
  }
  else {
    CVar2 = GetPixel(hdc,x,y);
  }
  return CVar2;
}



===== CreateDCA @ 180005e60 =====

HDC __stdcall CreateDCA(LPCSTR pwszDriver,LPCSTR pwszDevice,LPCSTR pszPort,DEVMODEA *pdm)

{
  char cVar1;
  HDC pHVar2;
  undefined4 uVar3;
  
                    /* 0x5e60  1065  CreateDCA */
  uVar3 = 0x49414e;
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    pHVar2 = (HDC)0x0;
  }
  else {
    pHVar2 = (HDC)CreateDCAImpl(pwszDriver,pwszDevice,pszPort,pdm,uVar3);
  }
  return pHVar2;
}



===== Gdi32DllInitialize @ 180005ed0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

undefined8 Gdi32DllInitialize(HMODULE param_1,int param_2)

{
  int iVar1;
  HANDLE pvVar2;
  HMODULE hModule;
  FARPROC pFVar3;
  uint local_res10 [6];
  
                    /* 0x5ed0  1516  Gdi32DllInitialize */
  if (param_2 != 1) {
    return 1;
  }
  DisableThreadLibraryCalls(param_1);
  __security_init_cookie();
  local_res10[0] = 0;
  pvVar2 = GetCurrentProcess();
  iVar1 = GetProcessMitigationPolicy(pvVar2,0xb,local_res10);
  if (iVar1 != 0) {
    g_systemCallFilterId = local_res10[0] & 0xf;
  }
  hModule = GetModuleHandleA("gdi32full.dll");
  if (((hModule == (HMODULE)0x0) &&
      (hModule = GetModuleHandleA("gdi32min.dll"), hModule == (HMODULE)0x0)) ||
     (pFVar3 = GetProcAddress(hModule,"GdiDllInitializeWrapper"), pFVar3 == (FARPROC)0x0)) {
    return 0;
  }
  (*pFVar3)();
  return 1;
}



===== RectVisible @ 180005fa0 =====

BOOL __stdcall RectVisible(HDC hdc,RECT *lprect)

{
  char cVar1;
  BOOL BVar2;
  
                    /* 0x5fa0  1837  RectVisible */
  cVar1 = IsRectVisiblePresent();
  if (cVar1 == '\0') {
    BVar2 = 0;
  }
  else {
    BVar2 = RectVisible(hdc,lprect);
  }
  return BVar2;
}



===== __delayLoadHelper2 @ 180005ff0 =====

void __delayLoadHelper2(undefined8 param_1,undefined8 param_2)

{
  ResolveDelayLoadedAPI(0x180000000,param_1,0,DelayLoadFailureHook_exref,param_2,0);
  return;
}



===== TranslateCharsetInfo @ 180006040 =====

BOOL __stdcall TranslateCharsetInfo(DWORD *lpSrc,LPCHARSETINFO lpCs,DWORD dwFlags)

{
  char cVar1;
  BOOL BVar2;
  
                    /* 0x6040  1971  TranslateCharsetInfo */
  cVar1 = IsEnumFontFamiliesAPresent();
  if (cVar1 == '\0') {
    BVar2 = 0;
  }
  else {
    BVar2 = TranslateCharsetInfo(lpSrc,lpCs,dwFlags);
  }
  return BVar2;
}



===== GetCurrentDpiInfo @ 1800060a0 =====

undefined8 GetCurrentDpiInfo(void)

{
  int iVar1;
  undefined8 uVar2;
  
                    /* 0x60a0  1661  GetCurrentDpiInfo */
  iVar1 = NtGdiGetCurrentDpiInfo();
  if (iVar1 < 0) {
    if (iVar1 == -0x3fffffff) {
      LastErrorValue = 0x57;
    }
    else if (iVar1 == -0x3ffffff3) {
      LastErrorValue = 6;
      return 0;
    }
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}



===== CreateBrushIndirect @ 180006100 =====

HBRUSH __stdcall CreateBrushIndirect(LOGBRUSH *plbrush)

{
  char cVar1;
  HBRUSH pHVar2;
  
                    /* 0x6100  1060  CreateBrushIndirect */
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    return (HBRUSH)0x0;
  }
                    /* WARNING: Could not recover jumptable at 0x000180006122. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pHVar2 = (HBRUSH)CreateBrushIndirect(plbrush);
  return pHVar2;
}



===== LpkpInitializeEditControl @ 180006140 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 LpkpInitializeEditControl(undefined8 *param_1,int param_2)

{
                    /* 0x6140  1794  LpkpInitializeEditControl */
  if (param_2 == 0xe) {
    _LpkEditControl = *param_1;
    uRam0000000180025708 = param_1[1];
    _DAT_180025710 = param_1[2];
    uRam0000000180025718 = param_1[3];
    _DAT_180025720 = param_1[4];
    uRam0000000180025728 = param_1[5];
    _DAT_180025730 = param_1[6];
    uRam0000000180025738 = param_1[7];
    _DAT_180025740 = param_1[8];
    uRam0000000180025748 = param_1[9];
    _DAT_180025750 = param_1[10];
    uRam0000000180025758 = param_1[0xb];
    _DAT_180025760 = param_1[0xc];
    uRam0000000180025768 = param_1[0xd];
    return 1;
  }
  return 0;
}



===== GetTextColor @ 1800061b0 =====

COLORREF __stdcall GetTextColor(HDC hdc)

{
  char cVar1;
  COLORREF CVar2;
  
                    /* 0x61b0  1749  GetTextColor */
  cVar1 = IsGetTextExtentPointWPresent();
  if (cVar1 == '\0') {
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x0001800061d2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CVar2 = GetTextColor(hdc);
  return CVar2;
}



===== Rectangle @ 1800061f0 =====

BOOL __stdcall Rectangle(HDC hdc,int left,int top,int right,int bottom)

{
  char cVar1;
  BOOL BVar2;
  
                    /* 0x61f0  1838  Rectangle */
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    BVar2 = 0;
  }
  else {
    BVar2 = RectangleImpl(hdc,left,top,right,bottom);
  }
  return BVar2;
}



===== DPtoLP @ 180006260 =====

BOOL __stdcall DPtoLP(HDC hdc,LPPOINT lppt,int c)

{
  char cVar1;
  BOOL BVar2;
  
                    /* 0x6260  1352  DPtoLP */
  cVar1 = IsCreatePatternBrushPresent();
  if (cVar1 == '\0') {
    BVar2 = 0;
  }
  else {
    BVar2 = DPtoLP(hdc,lppt,c);
  }
  return BVar2;
}



===== SetViewportExtEx @ 1800062c0 =====

BOOL __stdcall SetViewportExtEx(HDC hdc,int x,int y,LPSIZE lpsz)

{
  char cVar1;
  BOOL BVar2;
  
                    /* 0x62c0  1953  SetViewportExtEx */
  cVar1 = IsSetMapModePresent();
  if (cVar1 == '\0') {
    BVar2 = 0;
  }
  else {
    BVar2 = SetViewportExtEx(hdc,x,y,lpsz);
  }
  return BVar2;
}



===== SelectPalette @ 180006330 =====

HPALETTE __stdcall SelectPalette(HDC hdc,HPALETTE hPal,BOOL bForceBkgd)

{
  char cVar1;
  HPALETTE pHVar2;
  
                    /* 0x6330  1905  SelectPalette */
  cVar1 = IsGetObjectAPresent();
  if (cVar1 == '\0') {
    pHVar2 = (HPALETTE)0x0;
  }
  else {
    pHVar2 = SelectPalette(hdc,hPal,bForceBkgd);
  }
  return pHVar2;
}



===== SetICMMode @ 180006390 =====

int __stdcall SetICMMode(HDC hdc,int mode)

{
  char cVar1;
  int iVar2;
  
                    /* 0x6390  1927  SetICMMode */
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    iVar2 = 0;
  }
  else {
    iVar2 = SetICMModeImpl(hdc,mode);
  }
  return iVar2;
}



===== GetTextMetricsA @ 1800063e0 =====

BOOL __stdcall GetTextMetricsA(HDC hdc,LPTEXTMETRICA lptm)

{
  char cVar1;
  BOOL BVar2;
  
                    /* 0x63e0  1762  GetTextMetricsA */
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x000180006411. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar2 = GetTextMetricsAImpl(hdc,lptm);
  return BVar2;
}



===== SetWindowExtEx @ 180006440 =====

BOOL __stdcall SetWindowExtEx(HDC hdc,int x,int y,LPSIZE lpsz)

{
  char cVar1;
  BOOL BVar2;
  
                    /* 0x6440  1957  SetWindowExtEx */
  cVar1 = IsCreatePatternBrushPresent();
  if (cVar1 == '\0') {
    BVar2 = 0;
  }
  else {
    BVar2 = SetWindowExtEx(hdc,x,y,lpsz);
  }
  return BVar2;
}



===== GdiSetLastError @ 1800064b0 =====

void GdiSetLastError(dword param_1)

{
                    /* 0x64b0  1609  GdiSetLastError */
  LastErrorValue = param_1;
  return;
}



===== GetTextExtentExPointW @ 1800064d0 =====

BOOL __stdcall
GetTextExtentExPointW
          (HDC hdc,LPCWSTR lpszString,int cchString,int nMaxExtent,LPINT lpnFit,LPINT lpnDx,
          LPSIZE lpSize)

{
  char cVar1;
  BOOL BVar2;
  
                    /* 0x64d0  1752  GetTextExtentExPointW */
  cVar1 = IsGetKerningPairsAPresent();
  if (cVar1 == '\0') {
    BVar2 = 0;
  }
  else {
    BVar2 = GetTextExtentExPointW(hdc,lpszString,cchString,nMaxExtent,lpnFit,lpnDx,lpSize);
  }
  return BVar2;
}



===== CreateFontIndirectA @ 180006560 =====

HFONT __stdcall CreateFontIndirectA(LOGFONTA *lplf)

{
  char cVar1;
  HFONT pHVar2;
  
                    /* 0x6560  1078  CreateFontIndirectA */
  cVar1 = IsEnumFontFamiliesAPresent();
  if (cVar1 == '\0') {
    return (HFONT)0x0;
  }
                    /* WARNING: Could not recover jumptable at 0x000180006582. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pHVar2 = (HFONT)CreateFontIndirectA(lplf);
  return pHVar2;
}



===== CloseFigure @ 1800065a0 =====

BOOL __stdcall CloseFigure(HDC hdc)

{
  char cVar1;
  BOOL BVar2;
  
                    /* 0x65a0  1045  CloseFigure */
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x0001800065c2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar2 = CloseFigureImpl(hdc);
  return BVar2;
}



===== GetCurrentPositionEx @ 1800065e0 =====

BOOL __stdcall GetCurrentPositionEx(HDC hdc,LPPOINT lppt)

{
  char cVar1;
  BOOL BVar2;
  
                    /* 0x65e0  1663  GetCurrentPositionEx */
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    BVar2 = 0;
  }
  else {
    BVar2 = GetCurrentPositionEx(hdc,lppt);
  }
  return BVar2;
}



===== BeginPath @ 180006630 =====

BOOL __stdcall BeginPath(HDC hdc)

{
  char cVar1;
  BOOL BVar2;
  
                    /* 0x6630  1033  BeginPath */
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x000180006652. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar2 = BeginPathImpl(hdc);
  return BVar2;
}



===== EndPath @ 180006670 =====

BOOL __stdcall EndPath(HDC hdc)

{
  char cVar1;
  BOOL BVar2;
  
                    /* 0x6670  1431  EndPath */
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x000180006692. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar2 = EndPathImpl(hdc);
  return BVar2;
}



===== Polygon @ 1800066b0 =====

BOOL __stdcall Polygon(HDC hdc,POINT *apt,int cpt)

{
  char cVar1;
  BOOL BVar2;
  
                    /* 0x66b0  1829  Polygon */
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x0001800066f1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar2 = Polygon(hdc,apt,cpt);
  return BVar2;
}



===== TextOutA @ 180006720 =====

BOOL __stdcall TextOutA(HDC hdc,int x,int y,LPCSTR lpString,int c)

{
  char cVar1;
  BOOL BVar2;
  
                    /* 0x6720  1969  TextOutA */
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    BVar2 = 0;
  }
  else {
    BVar2 = TextOutA(hdc,x,y,lpString,c);
  }
  return BVar2;
}



===== UnrealizeObject @ 180006790 =====

BOOL __stdcall UnrealizeObject(HGDIOBJ h)

{
  char cVar1;
  BOOL BVar2;
  
                    /* 0x6790  1973  UnrealizeObject */
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x0001800067b2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar2 = UnrealizeObject(h);
  return BVar2;
}



===== FillPath @ 1800067d0 =====

BOOL __stdcall FillPath(HDC hdc)

{
  char cVar1;
  BOOL BVar2;
  
                    /* 0x67d0  1509  FillPath */
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x0001800067f2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar2 = FillPathImpl(hdc);
  return BVar2;
}



===== GetBitmapBits @ 180006810 =====

LONG __stdcall GetBitmapBits(HBITMAP hbit,LONG cb,LPVOID lpvBits)

{
  char cVar1;
  LONG LVar2;
  
                    /* 0x6810  1628  GetBitmapBits */
  cVar1 = IsBitBltPresent();
  if (cVar1 == '\0') {
    LVar2 = 0;
  }
  else {
    LVar2 = GetBitmapBits(hbit,cb,lpvBits);
  }
  return LVar2;
}



===== GetROP2 @ 180006870 =====

int __stdcall GetROP2(HDC hdc)

{
  char cVar1;
  int iVar2;
  
                    /* 0x6870  1732  GetROP2 */
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x000180006892. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar2 = GetROP2(hdc);
  return iVar2;
}



===== Polyline @ 1800068b0 =====

BOOL __stdcall Polyline(HDC hdc,POINT *apt,int cpt)

{
  char cVar1;
  BOOL BVar2;
  
                    /* 0x68b0  1830  Polyline */
  cVar1 = IsCreatePatternBrushPresent();
  if (cVar1 == '\0') {
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x0001800068f1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar2 = Polyline(hdc,apt,cpt);
  return BVar2;
}



===== GetTextExtentExPointA @ 180006920 =====

BOOL __stdcall
GetTextExtentExPointA
          (HDC hdc,LPCSTR lpszString,int cchString,int nMaxExtent,LPINT lpnFit,LPINT lpnDx,
          LPSIZE lpSize)

{
  char cVar1;
  BOOL BVar2;
  
                    /* 0x6920  1750  GetTextExtentExPointA */
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    BVar2 = 0;
  }
  else {
    BVar2 = GetTextExtentExPointA(hdc,lpszString,cchString,nMaxExtent,lpnFit,lpnDx,lpSize);
  }
  return BVar2;
}



===== GetTextExtentPoint32A @ 1800069b0 =====

BOOL __stdcall GetTextExtentPoint32A(HDC hdc,LPCSTR lpString,int c,LPSIZE psizl)

{
  char cVar1;
  BOOL BVar2;
  
                    /* 0x69b0  1754  GetTextExtentPoint32A */
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    BVar2 = 0;
  }
  else {
    BVar2 = GetTextExtentPoint32A(hdc,lpString,c,psizl);
  }
  return BVar2;
}



===== GdiComment @ 180006a20 =====

BOOL __stdcall GdiComment(HDC hdc,UINT nSize,BYTE *lpData)

{
  char cVar1;
  BOOL BVar2;
  
                    /* 0x6a20  1525  GdiComment */
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    BVar2 = 0;
  }
  else {
    BVar2 = GdiComment(hdc,nSize,lpData);
  }
  return BVar2;
}



===== CreateHalftonePalette @ 180006a80 =====

HPALETTE __stdcall CreateHalftonePalette(HDC hdc)

{
  undefined8 uVar1;
  HPALETTE pHVar2;
  char cVar3;
  
                    /* 0x6a80  1083  CreateHalftonePalette */
  cVar3 = IsGdiTrackHCreatePresent();
  if (cVar3 == '\0') {
    pHVar2 = (HPALETTE)NtGdiCreateHalftonePalette(hdc);
    return pHVar2;
  }
  uVar1 = NtGdiCreateHalftonePalette();
                    /* WARNING: Could not recover jumptable at 0x000180006aa9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pHVar2 = (HPALETTE)GdiTrackHCreate(uVar1);
  return pHVar2;
}



===== DrvQueryMonitorUniqueness @ 180006ad0 =====

undefined4 DrvQueryMonitorUniqueness(void)

{
                    /* 0x6ad0  1016   */
  return *(undefined4 *)(pGdiSharedMemory + 0x1800a8);
}



===== CreatePenIndirect @ 180006af0 =====

HPEN __stdcall CreatePenIndirect(LOGPEN *plpen)

{
  char cVar1;
  HPEN pHVar2;
  
                    /* 0x6af0  1094  CreatePenIndirect */
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    return (HPEN)0x0;
  }
                    /* WARNING: Could not recover jumptable at 0x000180006b12. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pHVar2 = (HPEN)CreatePenIndirect(plpen);
  return pHVar2;
}



===== RoundRect @ 180006b30 =====

BOOL __stdcall RoundRect(HDC hdc,int left,int top,int right,int bottom,int width,int height)

{
  char cVar1;
  BOOL BVar2;
  
                    /* 0x6b30  1849  RoundRect */
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    BVar2 = 0;
  }
  else {
    BVar2 = RoundRect(hdc,left,top,right,bottom,width,height);
  }
  return BVar2;
}



===== LpkGetEditControl @ 180006bc0 =====

undefined * LpkGetEditControl(void)

{
                    /* 0x6bc0  1786  LpkGetEditControl */
  return &LpkEditControl;
}



===== ExtEscape @ 180006bd0 =====

int __stdcall
ExtEscape(HDC hdc,int iEscape,int cjInput,LPCSTR lpInData,int cjOutput,LPSTR lpOutData)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
                    /* 0x6bd0  1496  ExtEscape */
  uVar3 = 0x49414e;
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    iVar2 = -1;
  }
  else {
    iVar2 = ExtEscapeImpl(hdc,iEscape,cjInput,lpInData,cjOutput,lpOutData,uVar3);
  }
  return iVar2;
}



===== SetMiterLimit @ 180006c50 =====

BOOL __stdcall SetMiterLimit(HDC hdc,FLOAT limit,PFLOAT old)

{
  char cVar1;
  BOOL BVar2;
  
                    /* 0x6c50  1937  SetMiterLimit */
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x000180006c91. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar2 = SetMiterLimitImpl(hdc,limit,old);
  return BVar2;
}



===== Ellipse @ 180006cc0 =====

BOOL __stdcall Ellipse(HDC hdc,int left,int top,int right,int bottom)

{
  char cVar1;
  BOOL BVar2;
  
                    /* 0x6cc0  1425  Ellipse */
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    BVar2 = 0;
  }
  else {
    BVar2 = Ellipse(hdc,left,top,right,bottom);
  }
  return BVar2;
}



===== CheckIsEdgeGdiProcessOnce @ 180006d30 =====

undefined8 CheckIsEdgeGdiProcessOnce(void)

{
  char cVar1;
  
  cVar1 = IsEdgeGdiInitializePresent();
  if (cVar1 != '\0') {
    g_pEdgeGdi = EdgeGdiInitialize();
  }
  return 1;
}



===== IsEdgeGdiInitializePresent @ 180006d70 =====

undefined1 IsEdgeGdiInitializePresent(void)

{
  int iVar1;
  
  if (DAT_1800256f0 == 1) {
    return 1;
  }
  if (DAT_1800256f0 != 2) {
    iVar1 = ApiSetQueryApiSetPresence(&DAT_1800101a0);
    if (-1 < iVar1) {
      DAT_1800256f0 = 2;
      return 0;
    }
  }
  return 0;
}



===== RealizePalette @ 180006de0 =====

UINT __stdcall RealizePalette(HDC hdc)

{
  char cVar1;
  UINT UVar2;
  
                    /* 0x6de0  1835  RealizePalette */
  cVar1 = IsGetObjectAPresent();
  if (cVar1 == '\0') {
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x000180006e02. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  UVar2 = RealizePalette(hdc);
  return UVar2;
}



===== PolyDraw @ 180006e20 =====

BOOL __stdcall PolyDraw(HDC hdc,POINT *apt,BYTE *aj,int cpt)

{
  char cVar1;
  BOOL BVar2;
  undefined4 uVar3;
  
                    /* 0x6e20  1823  PolyDraw */
  uVar3 = 0x49414e;
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    BVar2 = 0;
  }
  else {
    BVar2 = PolyDrawImpl(hdc,apt,aj,cpt,uVar3);
  }
  return BVar2;
}



===== CreatePatternBrush @ 180006e90 =====

HBRUSH __stdcall CreatePatternBrush(HBITMAP hbm)

{
  char cVar1;
  HBRUSH pHVar2;
  
                    /* 0x6e90  1092  CreatePatternBrush */
  cVar1 = IsCreatePatternBrushPresent();
  if (cVar1 == '\0') {
    return (HBRUSH)0x0;
  }
                    /* WARNING: Could not recover jumptable at 0x000180006eb2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pHVar2 = (HBRUSH)CreatePatternBrush(hbm);
  return pHVar2;
}



===== GetPaletteEntries @ 180006ed0 =====

UINT __stdcall GetPaletteEntries(HPALETTE hpal,UINT iStart,UINT cEntries,LPPALETTEENTRY pPalEntries)

{
  char cVar1;
  UINT UVar2;
  
                    /* 0x6ed0  1723  GetPaletteEntries */
  cVar1 = IsGetObjectAPresent();
  if (cVar1 == '\0') {
    UVar2 = 0;
  }
  else {
    UVar2 = GetPaletteEntries(hpal,iStart,cEntries,pPalEntries);
  }
  return UVar2;
}



===== GetTextCharacterExtra @ 180006f40 =====

int __stdcall GetTextCharacterExtra(HDC hdc)

{
  char cVar1;
  int iVar2;
  
                    /* 0x6f40  1746  GetTextCharacterExtra */
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x000180006f62. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar2 = GetTextCharacterExtra(hdc);
  return iVar2;
}



===== bDeleteLDC @ 180006f80 =====

undefined8 bDeleteLDC(HLOCAL param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  
                    /* 0x6f80  1988  bDeleteLDC */
  if (*(longlong *)((longlong)param_1 + 0x70) != 0) {
    RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0);
  }
  if (*(longlong *)((longlong)param_1 + 0x80) != 0) {
    DeleteEMFSpoolData(param_1);
  }
  if (*(int *)((longlong)param_1 + 0x88) != 0) {
    puVar2 = *(undefined8 **)((longlong)param_1 + 0x90);
    while (puVar2 != (undefined8 *)((longlong)param_1 + 0x90)) {
      puVar1 = (undefined8 *)*puVar2;
      RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,puVar2);
      puVar2 = puVar1;
    }
  }
  LocalFree(param_1);
  return 1;
}



===== GetTextExtentExPointI @ 180007040 =====

BOOL __stdcall
GetTextExtentExPointI
          (HDC hdc,LPWORD lpwszString,int cwchString,int nMaxExtent,LPINT lpnFit,LPINT lpnDx,
          LPSIZE lpSize)

{
  char cVar1;
  BOOL BVar2;
  
                    /* 0x7040  1751  GetTextExtentExPointI */
  cVar1 = IsGetTextExtentExPointIPresent();
  if (cVar1 == '\0') {
    BVar2 = 0;
  }
  else {
    BVar2 = GetTextExtentExPointI(hdc,lpwszString,cwchString,nMaxExtent,lpnFit,lpnDx,lpSize);
  }
  return BVar2;
}



===== EnumEnhMetaFile @ 1800070d0 =====

BOOL __stdcall
EnumEnhMetaFile(HDC hdc,HENHMETAFILE hmf,ENHMFENUMPROC proc,LPVOID param,RECT *lpRect)

{
  char cVar1;
  BOOL BVar2;
  
                    /* 0x70d0  1478  EnumEnhMetaFile */
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    BVar2 = 0;
  }
  else {
    BVar2 = EnumEnhMetaFile(hdc,hmf,proc,param,lpRect);
  }
  return BVar2;
}



===== DeleteEnhMetaFile @ 180007150 =====

BOOL __stdcall DeleteEnhMetaFile(HENHMETAFILE hmf)

{
  char cVar1;
  BOOL BVar2;
  
                    /* 0x7150  1416  DeleteEnhMetaFile */
  cVar1 = IsSetMetaFileBitsExPresent();
  if (cVar1 == '\0') {
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x000180007172. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar2 = DeleteEnhMetaFile(hmf);
  return BVar2;
}



===== StrokePath @ 180007190 =====

BOOL __stdcall StrokePath(HDC hdc)

{
  char cVar1;
  BOOL BVar2;
  
                    /* 0x7190  1967  StrokePath */
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x0001800071b2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar2 = StrokePathImpl(hdc);
  return BVar2;
}



===== Escape @ 1800071d0 =====

int __stdcall Escape(HDC hdc,int iEscape,int cjIn,LPCSTR pvIn,LPVOID pvOut)

{
  char cVar1;
  int iVar2;
  
                    /* 0x71d0  1490  Escape */
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    iVar2 = -1;
  }
  else {
    iVar2 = EscapeImpl(hdc,iEscape,cjIn,pvIn,pvOut);
  }
  return iVar2;
}



===== GetMetaFileBitsEx @ 180007250 =====

UINT __stdcall GetMetaFileBitsEx(HMETAFILE hMF,UINT cbBuffer,LPVOID lpData)

{
  char cVar1;
  UINT UVar2;
  
                    /* 0x7250  1709  GetMetaFileBitsEx */
  cVar1 = IsSetMetaFileBitsExPresent();
  if (cVar1 == '\0') {
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x00018000728f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  UVar2 = GetMetaFileBitsEx(hMF,cbBuffer,lpData);
  return UVar2;
}



===== CreateFontA @ 1800072c0 =====

HFONT __stdcall
CreateFontA(int cHeight,int cWidth,int cEscapement,int cOrientation,int cWeight,DWORD bItalic,
           DWORD bUnderline,DWORD bStrikeOut,DWORD iCharSet,DWORD iOutPrecision,DWORD iClipPrecision
           ,DWORD iQuality,DWORD iPitchAndFamily,LPCSTR pszFaceName)

{
  char cVar1;
  HFONT pHVar2;
  
                    /* 0x72c0  1077  CreateFontA */
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    pHVar2 = (HFONT)0x0;
  }
  else {
    pHVar2 = CreateFontA(cHeight,cWidth,cEscapement,cOrientation,cWeight,bItalic,bUnderline,
                         bStrikeOut,iCharSet,iOutPrecision,iClipPrecision,iQuality,iPitchAndFamily,
                         pszFaceName);
  }
  return pHVar2;
}



===== CreatePalette @ 1800073a0 =====

HPALETTE __stdcall CreatePalette(LOGPALETTE *plpal)

{
  char cVar1;
  HPALETTE pHVar2;
  
                    /* 0x73a0  1091  CreatePalette */
  cVar1 = IsGetObjectAPresent();
  if (cVar1 == '\0') {
    return (HPALETTE)0x0;
  }
                    /* WARNING: Could not recover jumptable at 0x0001800073c2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pHVar2 = (HPALETTE)CreatePalette(plpal);
  return pHVar2;
}



===== PolylineTo @ 1800073e0 =====

BOOL __stdcall PolylineTo(HDC hdc,POINT *apt,DWORD cpt)

{
  char cVar1;
  BOOL BVar2;
  
                    /* 0x73e0  1831  PolylineTo */
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x000180007421. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar2 = PolylineToImpl(hdc,apt,cpt);
  return BVar2;
}



===== CreateRoundRectRgn @ 180007450 =====

HRGN __stdcall CreateRoundRectRgn(int x1,int y1,int x2,int y2,int w,int h)

{
  HRGN pHVar1;
  
                    /* 0x7450  1099  CreateRoundRectRgn */
                    /* WARNING: Could not recover jumptable at 0x000180007460. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pHVar1 = (HRGN)CreateRoundRectRgn();
  return pHVar1;
}



===== SetPolyFillMode @ 180007480 =====

int __stdcall SetPolyFillMode(HDC hdc,int mode)

{
  int iVar1;
  
                    /* 0x7480  1943  SetPolyFillMode */
                    /* WARNING: Could not recover jumptable at 0x000180007488. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = SetPolyFillModeImpl();
  return iVar1;
}



===== GetCharWidthA @ 1800074a0 =====

BOOL __stdcall GetCharWidthA(HDC hdc,UINT iFirst,UINT iLast,LPINT lpBuffer)

{
  char cVar1;
  BOOL BVar2;
  
                    /* 0x74a0  1649  GetCharWidthA */
  cVar1 = IsGetKerningPairsAPresent();
  if (cVar1 == '\0') {
    BVar2 = 0;
  }
  else {
    BVar2 = GetCharWidthA(hdc,iFirst,iLast,lpBuffer);
  }
  return BVar2;
}



===== GetTextExtentPointA @ 180007510 =====

BOOL __stdcall GetTextExtentPointA(HDC hdc,LPCSTR lpString,int c,LPSIZE lpsz)

{
  char cVar1;
  BOOL BVar2;
  
                    /* 0x7510  1756  GetTextExtentPointA */
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    BVar2 = 0;
  }
  else {
    BVar2 = GetTextExtentPointA(hdc,lpString,c,lpsz);
  }
  return BVar2;
}



===== EnumMetaFile @ 180007580 =====

BOOL __stdcall EnumMetaFile(HDC hdc,HMETAFILE hmf,MFENUMPROC proc,LPARAM param)

{
  char cVar1;
  BOOL BVar2;
  
                    /* 0x7580  1487  EnumMetaFile */
  cVar1 = IsCloseMetaFilePresent();
  if (cVar1 == '\0') {
    BVar2 = 0;
  }
  else {
    BVar2 = EnumMetaFile(hdc,hmf,proc,param);
  }
  return BVar2;
}



===== PolyPolygon @ 1800075f0 =====

BOOL __stdcall PolyPolygon(HDC hdc,POINT *apt,INT *asz,int csz)

{
  char cVar1;
  BOOL BVar2;
  
                    /* 0x75f0  1825  PolyPolygon */
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    BVar2 = 0;
  }
  else {
    BVar2 = PolyPolygon(hdc,apt,asz,csz);
  }
  return BVar2;
}



===== DeleteMetaFile @ 180007660 =====

BOOL __stdcall DeleteMetaFile(HMETAFILE hmf)

{
  char cVar1;
  BOOL BVar2;
  
                    /* 0x7660  1417  DeleteMetaFile */
  cVar1 = IsSetMetaFileBitsExPresent();
  if (cVar1 == '\0') {
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x000180007682. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar2 = DeleteMetaFile(hmf);
  return BVar2;
}



===== SelectClipPath @ 1800076a0 =====

BOOL __stdcall SelectClipPath(HDC hdc,int mode)

{
  char cVar1;
  BOOL BVar2;
  
                    /* 0x76a0  1901  SelectClipPath */
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    BVar2 = 0;
  }
  else {
    BVar2 = SelectClipPathImpl(hdc,mode);
  }
  return BVar2;
}



===== SetMetaFileBitsEx @ 1800076f0 =====

HMETAFILE __stdcall SetMetaFileBitsEx(UINT cbBuffer,BYTE *lpData)

{
  char cVar1;
  HMETAFILE pHVar2;
  
                    /* 0x76f0  1935  SetMetaFileBitsEx */
  cVar1 = IsSetMetaFileBitsExPresent();
  if (cVar1 == '\0') {
    return (HMETAFILE)0x0;
  }
                    /* WARNING: Could not recover jumptable at 0x00018000771f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pHVar2 = (HMETAFILE)SetMetaFileBitsEx(cbBuffer,lpData);
  return pHVar2;
}



===== GetGlyphOutlineA @ 180007740 =====

DWORD __stdcall
GetGlyphOutlineA(HDC hdc,UINT uChar,UINT fuFormat,LPGLYPHMETRICS lpgm,DWORD cjBuffer,LPVOID pvBuffer
                ,MAT2 *lpmat2)

{
  char cVar1;
  DWORD DVar2;
  
                    /* 0x7740  1694  GetGlyphOutlineA */
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    DVar2 = 0;
  }
  else {
    DVar2 = GetGlyphOutlineA(hdc,uChar,fuFormat,lpgm,cjBuffer,pvBuffer,lpmat2);
  }
  return DVar2;
}



===== PlayMetaFile @ 1800077d0 =====

BOOL __stdcall PlayMetaFile(HDC hdc,HMETAFILE hmf)

{
  char cVar1;
  BOOL BVar2;
  
                    /* 0x77d0  1818  PlayMetaFile */
  cVar1 = IsPlayMetaFilePresent();
  if (cVar1 == '\0') {
    BVar2 = 0;
  }
  else {
    BVar2 = PlayMetaFile(hdc,hmf);
  }
  return BVar2;
}



===== GetTextFaceA @ 180007820 =====

int __stdcall GetTextFaceA(HDC hdc,int c,LPSTR lpName)

{
  char cVar1;
  int iVar2;
  
                    /* 0x7820  1759  GetTextFaceA */
  cVar1 = IsEnumFontFamiliesAPresent();
  if (cVar1 == '\0') {
    iVar2 = 0;
  }
  else {
    iVar2 = GetTextFaceA(hdc,c,lpName);
  }
  return iVar2;
}



===== GetOutlineTextMetricsA @ 180007880 =====

UINT __stdcall GetOutlineTextMetricsA(HDC hdc,UINT cjCopy,LPOUTLINETEXTMETRICA potm)

{
  char cVar1;
  UINT UVar2;
  
                    /* 0x7880  1721  GetOutlineTextMetricsA */
  cVar1 = IsGetKerningPairsAPresent();
  if (cVar1 == '\0') {
    UVar2 = 0;
  }
  else {
    UVar2 = GetOutlineTextMetricsA(hdc,cjCopy,potm);
  }
  return UVar2;
}



===== GetSystemPaletteEntries @ 1800078e0 =====

UINT __stdcall GetSystemPaletteEntries(HDC hdc,UINT iStart,UINT cEntries,LPPALETTEENTRY pPalEntries)

{
  char cVar1;
  UINT UVar2;
  
                    /* 0x78e0  1743  GetSystemPaletteEntries */
  cVar1 = IsGetObjectAPresent();
  if (cVar1 == '\0') {
    UVar2 = 0;
  }
  else {
    UVar2 = GetSystemPaletteEntries(hdc,iStart,cEntries,pPalEntries);
  }
  return UVar2;
}



===== CreateEnhMetaFileA @ 180007950 =====

HDC __stdcall CreateEnhMetaFileA(HDC hdc,LPCSTR lpFilename,RECT *lprc,LPCSTR lpDesc)

{
  char cVar1;
  HDC pHVar2;
  
                    /* 0x7950  1075  CreateEnhMetaFileA */
  cVar1 = IsPlayMetaFilePresent();
  if (cVar1 == '\0') {
    pHVar2 = (HDC)0x0;
  }
  else {
    pHVar2 = CreateEnhMetaFileA(hdc,lpFilename,lprc,lpDesc);
  }
  return pHVar2;
}



===== EnumFontFamiliesA @ 1800079c0 =====

int __stdcall EnumFontFamiliesA(HDC hdc,LPCSTR lpLogfont,FONTENUMPROCA lpProc,LPARAM lParam)

{
  char cVar1;
  int iVar2;
  
                    /* 0x79c0  1479  EnumFontFamiliesA */
  cVar1 = IsEnumFontFamiliesAPresent();
  if (cVar1 == '\0') {
    iVar2 = 0;
  }
  else {
    iVar2 = EnumFontFamiliesA(hdc,lpLogfont,lpProc,lParam);
  }
  return iVar2;
}



===== EnumFontFamiliesExA @ 180007a30 =====

int __stdcall
EnumFontFamiliesExA(HDC hdc,LPLOGFONTA lpLogfont,FONTENUMPROCA lpProc,LPARAM lParam,DWORD dwFlags)

{
  char cVar1;
  int iVar2;
  
                    /* 0x7a30  1480  EnumFontFamiliesExA */
  cVar1 = IsEnumFontFamiliesAPresent();
  if (cVar1 == '\0') {
    iVar2 = 0;
  }
  else {
    iVar2 = EnumFontFamiliesExA(hdc,lpLogfont,lpProc,lParam,dwFlags);
  }
  return iVar2;
}



===== GetNearestPaletteIndex @ 180007ab0 =====

UINT __stdcall GetNearestPaletteIndex(HPALETTE h,COLORREF color)

{
  char cVar1;
  UINT UVar2;
  
                    /* 0x7ab0  1714  GetNearestPaletteIndex */
  cVar1 = IsGetNearestPaletteIndexPresent();
  if (cVar1 == '\0') {
    UVar2 = 0;
  }
  else {
    UVar2 = GetNearestPaletteIndex(h,color);
  }
  return UVar2;
}



===== FillRgn @ 180007b00 =====

BOOL __stdcall FillRgn(HDC hdc,HRGN hrgn,HBRUSH hbr)

{
  BOOL BVar1;
  
                    /* 0x7b00  1510  FillRgn */
                    /* WARNING: Could not recover jumptable at 0x000180007b08. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = FillRgn();
  return BVar1;
}



===== CreateMetaFileA @ 180007b20 =====

HDC __stdcall CreateMetaFileA(LPCSTR pszFile)

{
  char cVar1;
  HDC pHVar2;
  
                    /* 0x7b20  1087  CreateMetaFileA */
  cVar1 = IsCloseMetaFilePresent();
  if (cVar1 == '\0') {
    return (HDC)0x0;
  }
                    /* WARNING: Could not recover jumptable at 0x000180007b42. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pHVar2 = (HDC)CreateMetaFileA(pszFile);
  return pHVar2;
}



===== FrameRgn @ 180007b60 =====

BOOL __stdcall FrameRgn(HDC hdc,HRGN hrgn,HBRUSH hbr,int w,int h)

{
  char cVar1;
  BOOL BVar2;
  
                    /* 0x7b60  1515  FrameRgn */
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    BVar2 = 0;
  }
  else {
    BVar2 = FrameRgn(hdc,hrgn,hbr,w,h);
  }
  return BVar2;
}



===== Arc @ 180007be0 =====

BOOL __stdcall Arc(HDC hdc,int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4)

{
  char cVar1;
  BOOL BVar2;
  
                    /* 0x7be0  1026  Arc */
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    BVar2 = 0;
  }
  else {
    BVar2 = Arc(hdc,x1,y1,x2,y2,x3,y3,x4,y4);
  }
  return BVar2;
}



===== GetEnhMetaFileBits @ 180007c90 =====

UINT __stdcall GetEnhMetaFileBits(HENHMETAFILE hEMF,UINT nSize,LPBYTE lpData)

{
  char cVar1;
  UINT UVar2;
  
                    /* 0x7c90  1676  GetEnhMetaFileBits */
  cVar1 = IsSetMetaFileBitsExPresent();
  if (cVar1 == '\0') {
    UVar2 = 0;
  }
  else {
    UVar2 = GetEnhMetaFileBits(hEMF,nSize,lpData);
  }
  return UVar2;
}



===== CreateBitmapIndirect @ 180007cf0 =====

HBITMAP __stdcall CreateBitmapIndirect(BITMAP *pbm)

{
  char cVar1;
  HBITMAP pHVar2;
  
                    /* 0x7cf0  1059  CreateBitmapIndirect */
  cVar1 = IsCreatePatternBrushPresent();
  if (cVar1 == '\0') {
    pHVar2 = (HBITMAP)0x0;
  }
  else {
    pHVar2 = CreateBitmapIndirect(pbm);
  }
  return pHVar2;
}



===== GetKerningPairs @ 180007d30 =====

DWORD __stdcall GetKerningPairs(HDC hdc,DWORD nPairs,LPKERNINGPAIR lpKernPair)

{
  char cVar1;
  DWORD DVar2;
  
                    /* 0x7d30  1701  GetKerningPairs
                       0x7d30  1702  GetKerningPairsA */
  cVar1 = IsGetKerningPairsAPresent();
  if (cVar1 == '\0') {
    DVar2 = 0;
  }
  else {
    DVar2 = GetKerningPairsA(hdc,nPairs,lpKernPair);
  }
  return DVar2;
}



===== CreatePolyPolygonRgn @ 180007d90 =====

HRGN __stdcall CreatePolyPolygonRgn(POINT *pptl,INT *pc,int cPoly,int iMode)

{
  char cVar1;
  HRGN pHVar2;
  
                    /* 0x7d90  1095  CreatePolyPolygonRgn */
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    pHVar2 = (HRGN)0x0;
  }
  else {
    pHVar2 = CreatePolyPolygonRgn(pptl,pc,cPoly,iMode);
  }
  return pHVar2;
}



===== PolyBezier @ 180007e00 =====

BOOL __stdcall PolyBezier(HDC hdc,POINT *apt,DWORD cpt)

{
  char cVar1;
  BOOL BVar2;
  
                    /* 0x7e00  1821  PolyBezier */
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    BVar2 = 0;
  }
  else {
    BVar2 = PolyBezier(hdc,apt,cpt);
  }
  return BVar2;
}



===== CloseMetaFile @ 180007e60 =====

HMETAFILE __stdcall CloseMetaFile(HDC hdc)

{
  char cVar1;
  HMETAFILE pHVar2;
  
                    /* 0x7e60  1046  CloseMetaFile */
  cVar1 = IsCloseMetaFilePresent();
  if (cVar1 == '\0') {
    pHVar2 = (HMETAFILE)0x0;
  }
  else {
    pHVar2 = CloseMetaFile(hdc);
  }
  return pHVar2;
}



===== ResetDCW @ 180007ea0 =====

HDC __stdcall ResetDCW(HDC hdc,DEVMODEW *lpdm)

{
  char cVar1;
  HDC pHVar2;
  
                    /* 0x7ea0  1846  ResetDCW */
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    pHVar2 = (HDC)0x0;
  }
  else {
    pHVar2 = (HDC)ResetDCWImpl(hdc,lpdm);
  }
  return pHVar2;
}



===== StartDocW @ 180007ef0 =====

int __stdcall StartDocW(HDC hdc,DOCINFOW *lpdi)

{
  char cVar1;
  int iVar2;
  
                    /* 0x7ef0  1961  StartDocW */
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    iVar2 = 0;
  }
  else {
    iVar2 = StartDocWImpl(hdc,lpdi);
  }
  return iVar2;
}



===== ResizePalette @ 180007f40 =====

BOOL __stdcall ResizePalette(HPALETTE hpal,UINT n)

{
  char cVar1;
  BOOL BVar2;
  
                    /* 0x7f40  1847  ResizePalette */
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    BVar2 = 0;
  }
  else {
    BVar2 = ResizePalette(hpal,n);
  }
  return BVar2;
}



===== InvertRgn @ 180007f90 =====

BOOL __stdcall InvertRgn(HDC hdc,HRGN hrgn)

{
  char cVar1;
  BOOL BVar2;
  
                    /* 0x7f90  1776  InvertRgn */
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x000180007fc1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar2 = InvertRgn(hdc,hrgn);
  return BVar2;
}



===== EndPage @ 180007ff0 =====

int __stdcall EndPage(HDC hdc)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined8 unaff_retaddr;
  
                    /* 0x7ff0  1430  EndPage */
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    return 0;
  }
  iVar2 = GditPushCallerInfo(unaff_retaddr);
  iVar3 = EndPageImpl(hdc);
  if (iVar2 != 0) {
    GditPopCallerInfo();
  }
  return iVar3;
}



===== PlayEnhMetaFile @ 180008070 =====

BOOL __stdcall PlayEnhMetaFile(HDC hdc,HENHMETAFILE hmf,RECT *lprect)

{
  char cVar1;
  BOOL BVar2;
  
                    /* 0x8070  1816  PlayEnhMetaFile */
  cVar1 = IsPlayMetaFilePresent();
  if (cVar1 == '\0') {
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x0001800080b1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar2 = PlayEnhMetaFile(hdc,hmf,lprect);
  return BVar2;
}



===== RemoveFontResourceW @ 1800080e0 =====

BOOL __stdcall RemoveFontResourceW(LPCWSTR lpFileName)

{
  char cVar1;
  BOOL BVar2;
  
                    /* 0x80e0  1844  RemoveFontResourceW */
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    BVar2 = 0;
  }
  else {
    BVar2 = RemoveFontResourceWImpl(lpFileName);
  }
  return BVar2;
}



===== GetTextExtentPointI @ 180008120 =====

BOOL __stdcall GetTextExtentPointI(HDC hdc,LPWORD pgiIn,int cgi,LPSIZE psize)

{
  char cVar1;
  BOOL BVar2;
  
                    /* 0x8120  1757  GetTextExtentPointI */
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    BVar2 = 0;
  }
  else {
    BVar2 = GetTextExtentPointI(hdc,pgiIn,cgi,psize);
  }
  return BVar2;
}



===== EndDoc @ 180008190 =====

int __stdcall EndDoc(HDC hdc)

{
  char cVar1;
  int iVar2;
  
                    /* 0x8190  1427  EndDoc */
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    iVar2 = 0;
  }
  else {
    iVar2 = EndDocImpl(hdc);
  }
  return iVar2;
}



===== StartPage @ 1800081d0 =====

int __stdcall StartPage(HDC hdc)

{
  char cVar1;
  int iVar2;
  
                    /* 0x81d0  1963  StartPage */
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    iVar2 = 0;
  }
  else {
    iVar2 = StartPageImpl(hdc);
  }
  return iVar2;
}



===== Pie @ 180008210 =====

BOOL __stdcall Pie(HDC hdc,int left,int top,int right,int bottom,int xr1,int yr1,int xr2,int yr2)

{
  char cVar1;
  BOOL BVar2;
  
                    /* 0x8210  1815  Pie */
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    BVar2 = 0;
  }
  else {
    BVar2 = Pie(hdc,left,top,right,bottom,xr1,yr1,xr2,yr2);
  }
  return BVar2;
}



===== __security_init_cookie @ 1800082b8 =====

void __cdecl __security_init_cookie(void)

{
  DWORD DVar1;
  ulonglong uVar2;
  _FILETIME local_res8;
  LARGE_INTEGER local_res10;
  _FILETIME local_res18;
  
  local_res18.dwLowDateTime = 0;
  local_res18.dwHighDateTime = 0;
  local_res10.QuadPart = 0;
  if ((__security_cookie == 0) || (__security_cookie == 0x2b992ddfa232)) {
    GetSystemTimeAsFileTime(&local_res18);
    local_res8 = local_res18;
    DVar1 = GetCurrentProcessId();
    local_res8 = (_FILETIME)((ulonglong)local_res8 ^ (ulonglong)DVar1);
    DVar1 = GetCurrentThreadId();
    local_res8 = (_FILETIME)((ulonglong)local_res8 ^ (ulonglong)DVar1);
    DVar1 = GetTickCount();
    local_res8 = (_FILETIME)((ulonglong)local_res8 ^ (ulonglong)DVar1 << 0x18);
    DVar1 = GetTickCount();
    local_res8 = (_FILETIME)((ulonglong)DVar1 ^ (ulonglong)local_res8 ^ (ulonglong)&local_res8);
    QueryPerformanceCounter(&local_res10);
    uVar2 = (local_res10.QuadPart << 0x20 ^ local_res10.QuadPart ^ (ulonglong)local_res8) &
            0xffffffffffff;
    __security_cookie = 0x2b992ddfa232;
    if (uVar2 != 0) {
      __security_cookie = uVar2;
    }
  }
  __security_cookie_complement = ~__security_cookie;
  return;
}



===== __report_gsfailure @ 180008390 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  DWORD64 ControlPc;
  PRUNTIME_FUNCTION FunctionEntry;
  HANDLE hProcess;
  DWORD64 unaff_retaddr;
  uintptr_t local_res8 [4];
  ulonglong local_38 [2];
  PVOID local_28;
  undefined8 local_20;
  undefined8 local_18;
  
  local_38[1] = 0;
  local_28 = (PVOID)0x0;
  local_38[0] = 0;
  local_res8[0] = _StackCookie;
  RtlCaptureContext(&DAT_1800250c0);
  ControlPc = DAT_1800251b8;
  FunctionEntry = RtlLookupFunctionEntry(DAT_1800251b8,local_38,(PUNWIND_HISTORY_TABLE)0x0);
  if (FunctionEntry == (PRUNTIME_FUNCTION)0x0) {
    _DAT_180025158 = local_res8;
    DAT_1800251b8 = unaff_retaddr;
  }
  else {
    RtlVirtualUnwind(0,local_38[0],ControlPc,FunctionEntry,(PCONTEXT)&DAT_1800250c0,&local_28,
                     local_38 + 1,(PKNONVOLATILE_CONTEXT_POINTERS)0x0);
  }
  _DAT_180025030 = DAT_1800251b8;
  _DAT_180025140 = local_res8[0];
  _DAT_180025020 = 0xc0000409;
  _DAT_180025024 = 1;
  _DAT_180025038 = 1;
  DAT_180025040 = 2;
  local_20 = __security_cookie;
  local_18 = __security_cookie_complement;
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  UnhandledExceptionFilter((_EXCEPTION_POINTERS *)&PTR_DAT_180010000);
  hProcess = GetCurrentProcess();
  TerminateProcess(hProcess,0xc0000409);
  return;
}



===== BRUSHOBJ_hGetColorTransform @ 180008510 =====

void BRUSHOBJ_hGetColorTransform(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180008510. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8510  1028  BRUSHOBJ_hGetColorTransform */
  NtGdiBRUSHOBJ_hGetColorTransform();
  return;
}



===== BRUSHOBJ_pvAllocRbrush @ 180008520 =====

void BRUSHOBJ_pvAllocRbrush(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180008520. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8520  1029  BRUSHOBJ_pvAllocRbrush */
  NtGdiBRUSHOBJ_pvAllocRbrush();
  return;
}



===== BRUSHOBJ_pvGetRbrush @ 180008530 =====

void BRUSHOBJ_pvGetRbrush(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180008530. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8530  1030  BRUSHOBJ_pvGetRbrush */
  NtGdiBRUSHOBJ_pvGetRbrush();
  return;
}



===== BRUSHOBJ_ulGetBrushColor @ 180008540 =====

void BRUSHOBJ_ulGetBrushColor(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180008540. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8540  1031  BRUSHOBJ_ulGetBrushColor */
  NtGdiBRUSHOBJ_ulGetBrushColor();
  return;
}



===== BeginGdiRendering @ 180008550 =====

void BeginGdiRendering(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180008550. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8550  1032  BeginGdiRendering */
  NtGdiBeginGdiRendering();
  return;
}



===== CLIPOBJ_bEnum @ 180008560 =====

void CLIPOBJ_bEnum(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180008560. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8560  1035  CLIPOBJ_bEnum */
  NtGdiCLIPOBJ_bEnum();
  return;
}



===== CLIPOBJ_cEnumStart @ 180008570 =====

void CLIPOBJ_cEnumStart(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180008570. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8570  1036  CLIPOBJ_cEnumStart */
  NtGdiCLIPOBJ_cEnumStart();
  return;
}



===== CLIPOBJ_ppoGetPath @ 180008580 =====

void CLIPOBJ_ppoGetPath(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180008580. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8580  1037  CLIPOBJ_ppoGetPath */
  NtGdiCLIPOBJ_ppoGetPath();
  return;
}



===== ConfigureOPMProtectedOutput @ 180008590 =====

void ConfigureOPMProtectedOutput(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180008590. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8590  1051  ConfigureOPMProtectedOutput */
  NtGdiConfigureOPMProtectedOutput();
  return;
}



===== CreateBitmapFromDxSurface @ 1800085a0 =====

void CreateBitmapFromDxSurface(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800085a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x85a0  1057  CreateBitmapFromDxSurface */
  NtGdiCreateBitmapFromDxSurface();
  return;
}



===== CreateBitmapFromDxSurface2 @ 1800085b0 =====

void CreateBitmapFromDxSurface2(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800085b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x85b0  1058  CreateBitmapFromDxSurface2 */
  NtGdiCreateBitmapFromDxSurface2();
  return;
}



===== CreateOPMProtectedOutput @ 1800085c0 =====

void CreateOPMProtectedOutput(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800085c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x85c0  1089  CreateOPMProtectedOutput */
  NtGdiCreateOPMProtectedOutput();
  return;
}



===== CreateOPMProtectedOutputs @ 1800085d0 =====

void CreateOPMProtectedOutputs(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800085d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x85d0  1090  CreateOPMProtectedOutputs */
  NtGdiCreateOPMProtectedOutputs();
  return;
}



===== DDCCIGetCapabilitiesString @ 1800085e0 =====

void DDCCIGetCapabilitiesString(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800085e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x85e0  1346  DDCCIGetCapabilitiesString */
  NtGdiDDCCIGetCapabilitiesString();
  return;
}



===== DDCCIGetCapabilitiesStringLength @ 1800085f0 =====

void DDCCIGetCapabilitiesStringLength(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800085f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x85f0  1347  DDCCIGetCapabilitiesStringLength */
  NtGdiDDCCIGetCapabilitiesStringLength();
  return;
}



===== DDCCIGetTimingReport @ 180008600 =====

void DDCCIGetTimingReport(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180008600. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8600  1348  DDCCIGetTimingReport */
  NtGdiDDCCIGetTimingReport();
  return;
}



===== DDCCIGetVCPFeature @ 180008610 =====

void DDCCIGetVCPFeature(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180008610. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8610  1349  DDCCIGetVCPFeature */
  NtGdiDDCCIGetVCPFeature();
  return;
}



===== DDCCISaveCurrentSettings @ 180008620 =====

void DDCCISaveCurrentSettings(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180008620. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8620  1350  DDCCISaveCurrentSettings */
  NtGdiDDCCISaveCurrentSettings();
  return;
}



===== DDCCISetVCPFeature @ 180008630 =====

void DDCCISetVCPFeature(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180008630. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8630  1351  DDCCISetVCPFeature */
  NtGdiDDCCISetVCPFeature();
  return;
}



===== DdCreateFullscreenSprite @ 180008640 =====

void DdCreateFullscreenSprite(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180008640. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8640  1353  DdCreateFullscreenSprite */
  NtGdiDdCreateFullscreenSprite();
  return;
}



===== DdDestroyFullscreenSprite @ 180008650 =====

void DdDestroyFullscreenSprite(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180008650. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8650  1354  DdDestroyFullscreenSprite */
  NtGdiDdDestroyFullscreenSprite();
  return;
}



===== DdNotifyFullscreenSpriteUpdate @ 180008660 =====

void DdNotifyFullscreenSpriteUpdate(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180008660. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8660  1412  DdNotifyFullscreenSpriteUpdate */
  NtGdiDdNotifyFullscreenSpriteUpdate();
  return;
}



===== DdQueryVisRgnUniqueness @ 180008670 =====

void DdQueryVisRgnUniqueness(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180008670. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8670  1413  DdQueryVisRgnUniqueness */
  NtGdiDdQueryVisRgnUniqueness();
  return;
}



===== DestroyOPMProtectedOutput @ 180008680 =====

void DestroyOPMProtectedOutput(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180008680. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8680  1420  DestroyOPMProtectedOutput */
  NtGdiDestroyOPMProtectedOutput();
  return;
}



===== DestroyPhysicalMonitorInternal @ 180008690 =====

void DestroyPhysicalMonitorInternal(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180008690. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8690  1421  DestroyPhysicalMonitorInternal */
  NtGdiDestroyPhysicalMonitor();
  return;
}



===== EnableEUDC @ 1800086a0 =====

void EnableEUDC(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800086a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x86a0  1426  EnableEUDC */
  NtGdiEnableEudc();
  return;
}



===== EndGdiRendering @ 1800086b0 =====

void EndGdiRendering(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800086b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x86b0  1429  EndGdiRendering */
  NtGdiEndGdiRendering();
  return;
}



===== EngAlphaBlend @ 1800086c0 =====

void EngAlphaBlend(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800086c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x86c0  1433  EngAlphaBlend */
  NtGdiEngAlphaBlend();
  return;
}



===== EngAssociateSurface @ 1800086d0 =====

void EngAssociateSurface(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800086d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x86d0  1434  EngAssociateSurface */
  NtGdiEngAssociateSurface();
  return;
}



===== EngBitBlt @ 1800086e0 =====

void EngBitBlt(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800086e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x86e0  1435  EngBitBlt */
  NtGdiEngBitBlt();
  return;
}



===== EngCheckAbort @ 1800086f0 =====

void EngCheckAbort(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800086f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x86f0  1436  EngCheckAbort */
  NtGdiEngCheckAbort();
  return;
}



===== EngCopyBits @ 180008700 =====

void EngCopyBits(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180008700. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8700  1438  EngCopyBits */
  NtGdiEngCopyBits();
  return;
}



===== EngCreateClip @ 180008710 =====

void EngCreateClip(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180008710. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8710  1440  EngCreateClip */
  NtGdiEngCreateClip();
  return;
}



===== EngDeleteClip @ 180008720 =====

void EngDeleteClip(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180008720. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8720  1445  EngDeleteClip */
  NtGdiEngDeleteClip();
  return;
}



===== EngDeletePath @ 180008730 =====

void EngDeletePath(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180008730. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8730  1447  EngDeletePath */
  NtGdiEngDeletePath();
  return;
}



===== EngEraseSurface @ 180008740 =====

void EngEraseSurface(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180008740. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8740  1450  EngEraseSurface */
  NtGdiEngEraseSurface();
  return;
}



===== EngFillPath @ 180008750 =====

void EngFillPath(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180008750. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8750  1451  EngFillPath */
  NtGdiEngFillPath();
  return;
}



===== EngGradientFill @ 180008760 =====

void EngGradientFill(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180008760. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8760  1457  EngGradientFill */
  NtGdiEngGradientFill();
  return;
}



===== EngLineTo @ 180008770 =====

void EngLineTo(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180008770. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8770  1458  EngLineTo */
  NtGdiEngLineTo();
  return;
}



===== EngLockSurface @ 180008780 =====

void EngLockSurface(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180008780. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8780  1460  EngLockSurface */
  NtGdiEngLockSurface();
  return;
}



===== EngMarkBandingSurface @ 180008790 =====

void EngMarkBandingSurface(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180008790. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8790  1461  EngMarkBandingSurface */
  NtGdiEngMarkBandingSurface();
  return;
}



===== EngPaint @ 1800087a0 =====

void EngPaint(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800087a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x87a0  1464  EngPaint */
  NtGdiEngPaint();
  return;
}



===== EngPlgBlt @ 1800087b0 =====

void EngPlgBlt(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800087b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x87b0  1465  EngPlgBlt */
  NtGdiEngPlgBlt();
  return;
}



===== EngStretchBlt @ 1800087c0 =====

void EngStretchBlt(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800087c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x87c0  1469  EngStretchBlt */
  NtGdiEngStretchBlt();
  return;
}



===== EngStretchBltROP @ 1800087d0 =====

void EngStretchBltROP(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800087d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x87d0  1470  EngStretchBltROP */
  NtGdiEngStretchBltROP();
  return;
}



===== EngStrokeAndFillPath @ 1800087e0 =====

void EngStrokeAndFillPath(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800087e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x87e0  1471  EngStrokeAndFillPath */
  NtGdiEngStrokeAndFillPath();
  return;
}



===== EngStrokePath @ 1800087f0 =====

void EngStrokePath(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800087f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x87f0  1472  EngStrokePath */
  NtGdiEngStrokePath();
  return;
}



===== EngTextOut @ 180008800 =====

void EngTextOut(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180008800. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8800  1473  EngTextOut */
  NtGdiEngTextOut();
  return;
}



===== EngTransparentBlt @ 180008810 =====

void EngTransparentBlt(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180008810. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8810  1474  EngTransparentBlt */
  NtGdiEngTransparentBlt();
  return;
}



===== EngUnlockSurface @ 180008820 =====

void EngUnlockSurface(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180008820. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8820  1476  EngUnlockSurface */
  NtGdiEngUnlockSurface();
  return;
}



===== FONTOBJ_cGetAllGlyphHandles @ 180008830 =====

void FONTOBJ_cGetAllGlyphHandles(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180008830. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8830  1501  FONTOBJ_cGetAllGlyphHandles */
  NtGdiFONTOBJ_cGetAllGlyphHandles();
  return;
}



===== FONTOBJ_cGetGlyphs @ 180008840 =====

void FONTOBJ_cGetGlyphs(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180008840. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8840  1502  FONTOBJ_cGetGlyphs */
  NtGdiFONTOBJ_cGetGlyphs();
  return;
}



===== FONTOBJ_pQueryGlyphAttrs @ 180008850 =====

void FONTOBJ_pQueryGlyphAttrs(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180008850. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8850  1503  FONTOBJ_pQueryGlyphAttrs */
  NtGdiFONTOBJ_pQueryGlyphAttrs();
  return;
}



===== FONTOBJ_pfdg @ 180008860 =====

void FONTOBJ_pfdg(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180008860. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8860  1504  FONTOBJ_pfdg */
  NtGdiFONTOBJ_pfdg();
  return;
}



===== FONTOBJ_pifi @ 180008870 =====

void FONTOBJ_pifi(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180008870. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8870  1505  FONTOBJ_pifi */
  NtGdiFONTOBJ_pifi();
  return;
}



===== FONTOBJ_pvTrueTypeFontFile @ 180008880 =====

void FONTOBJ_pvTrueTypeFontFile(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180008880. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8880  1506  FONTOBJ_pvTrueTypeFontFile */
  NtGdiFONTOBJ_pvTrueTypeFontFile();
  return;
}



===== FONTOBJ_pxoGetXform @ 180008890 =====

void FONTOBJ_pxoGetXform(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180008890. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8890  1507  FONTOBJ_pxoGetXform */
  NtGdiFONTOBJ_pxoGetXform();
  return;
}



===== FONTOBJ_vGetInfo @ 1800088a0 =====

void FONTOBJ_vGetInfo(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800088a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x88a0  1508  FONTOBJ_vGetInfo */
  NtGdiFONTOBJ_vGetInfo();
  return;
}



===== GdiFullscreenControl @ 1800088b0 =====

void GdiFullscreenControl(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800088b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x88b0  1567  GdiFullscreenControl */
  NtGdiFullscreenControl();
  return;
}



===== GdiGetSpoolMessage @ 1800088c0 =====

void GdiGetSpoolMessage(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800088c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x88c0  1581  GdiGetSpoolMessage */
  NtGdiGetSpoolMessage();
  return;
}



===== GdiInitSpool @ 1800088d0 =====

void GdiInitSpool(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800088d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x88d0  1585  GdiInitSpool */
  NtGdiInitSpool();
  return;
}



===== GdiQueryFonts @ 1800088e0 =====

void GdiQueryFonts(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800088e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x88e0  1601  GdiQueryFonts */
  NtGdiQueryFonts();
  return;
}



===== GetBitmapDpiScaleValue @ 1800088f0 =====

void GetBitmapDpiScaleValue(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800088f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x88f0  1630  GetBitmapDpiScaleValue */
  NtGdiGetBitmapDpiScaleValue();
  return;
}



===== GetCOPPCompatibleOPMInformation @ 180008900 =====

void GetCOPPCompatibleOPMInformation(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180008900. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8900  1636  GetCOPPCompatibleOPMInformation */
  NtGdiGetCOPPCompatibleOPMInformation();
  return;
}



===== GetCertificate @ 180008910 =====

void GetCertificate(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180008910. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8910  1637  GetCertificate */
  NtGdiGetCertificate();
  return;
}



===== GetCertificateByHandle @ 180008920 =====

void GetCertificateByHandle(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180008920. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8920  1638  GetCertificateByHandle */
  NtGdiGetCertificateByHandle();
  return;
}



===== GetCertificateSize @ 180008930 =====

void GetCertificateSize(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180008930. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8930  1639  GetCertificateSize */
  NtGdiGetCertificateSize();
  return;
}



===== GetCertificateSizeByHandle @ 180008940 =====

void GetCertificateSizeByHandle(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180008940. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8940  1640  GetCertificateSizeByHandle */
  NtGdiGetCertificateSizeByHandle();
  return;
}



===== GetCharWidthInfo @ 180008950 =====

void GetCharWidthInfo(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180008950. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8950  1653  GetCharWidthInfo */
  NtGdiGetCharWidthInfo();
  return;
}



===== GetFontUnicodeRanges @ 180008960 =====

void GetFontUnicodeRanges(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180008960. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8960  1690  GetFontUnicodeRanges */
  NtGdiGetFontUnicodeRanges();
  return;
}



===== GetNumberOfPhysicalMonitors @ 180008970 =====

void GetNumberOfPhysicalMonitors(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180008970. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8970  1715  GetNumberOfPhysicalMonitors */
  NtGdiGetNumberOfPhysicalMonitors();
  return;
}



===== GetOPMInformation @ 180008980 =====

void GetOPMInformation(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180008980. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8980  1716  GetOPMInformation */
  NtGdiGetOPMInformation();
  return;
}



===== GetOPMRandomNumber @ 180008990 =====

void GetOPMRandomNumber(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180008990. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8990  1717  GetOPMRandomNumber */
  NtGdiGetOPMRandomNumber();
  return;
}



===== GetPhysicalMonitorDescription @ 1800089a0 =====

void GetPhysicalMonitorDescription(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800089a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x89a0  1725  GetPhysicalMonitorDescription */
  NtGdiGetPhysicalMonitorDescription();
  return;
}



===== GetPhysicalMonitorFromTargetInternal @ 1800089b0 =====

void GetPhysicalMonitorFromTargetInternal(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800089b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x89b0  1726  GetPhysicalMonitorFromTargetInternal */
  NtGdiGetPhysicalMonitorFromTarget();
  return;
}



===== GetPhysicalMonitors @ 1800089c0 =====

void GetPhysicalMonitors(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800089c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x89c0  1727  GetPhysicalMonitors */
  NtGdiGetPhysicalMonitors();
  return;
}



===== GetStringBitmapW @ 1800089d0 =====

void GetStringBitmapW(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800089d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x89d0  1741  GetStringBitmapW */
  NtGdiGetStringBitmapW();
  return;
}



===== GetSuggestedOPMProtectedOutputArraySize @ 1800089e0 =====

void GetSuggestedOPMProtectedOutputArraySize(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800089e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x89e0  1742  GetSuggestedOPMProtectedOutputArraySize */
  NtGdiGetSuggestedOPMProtectedOutputArraySize();
  return;
}



===== GetTextCharsetInfo @ 1800089f0 =====

void GetTextCharsetInfo(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800089f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x89f0  1748  GetTextCharsetInfo */
  NtGdiGetTextCharsetInfo();
  return;
}



===== HT_Get8BPPFormatPalette @ 180008a00 =====

void HT_Get8BPPFormatPalette(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180008a00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8a00  1771  HT_Get8BPPFormatPalette */
  NtGdiHT_Get8BPPFormatPalette();
  return;
}



===== HT_Get8BPPMaskPalette @ 180008a10 =====

void HT_Get8BPPMaskPalette(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180008a10. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8a10  1772  HT_Get8BPPMaskPalette */
  NtGdiHT_Get8BPPMaskPalette();
  return;
}



===== PATHOBJ_bEnum @ 180008a20 =====

void PATHOBJ_bEnum(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180008a20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8a20  1807  PATHOBJ_bEnum */
  NtGdiPATHOBJ_bEnum();
  return;
}



===== PATHOBJ_bEnumClipLines @ 180008a30 =====

void PATHOBJ_bEnumClipLines(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180008a30. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8a30  1808  PATHOBJ_bEnumClipLines */
  NtGdiPATHOBJ_bEnumClipLines();
  return;
}



===== PATHOBJ_vEnumStart @ 180008a40 =====

void PATHOBJ_vEnumStart(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180008a40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8a40  1809  PATHOBJ_vEnumStart */
  NtGdiPATHOBJ_vEnumStart();
  return;
}



===== PATHOBJ_vEnumStartClipLines @ 180008a50 =====

void PATHOBJ_vEnumStartClipLines(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180008a50. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8a50  1810  PATHOBJ_vEnumStartClipLines */
  NtGdiPATHOBJ_vEnumStartClipLines();
  return;
}



===== PATHOBJ_vGetBounds @ 180008a60 =====

void PATHOBJ_vGetBounds(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180008a60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8a60  1811  PATHOBJ_vGetBounds */
  NtGdiPATHOBJ_vGetBounds();
  return;
}



===== STROBJ_bEnum @ 180008a70 =====

void STROBJ_bEnum(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180008a70. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8a70  1850  STROBJ_bEnum */
  NtGdiSTROBJ_bEnum();
  return;
}



===== STROBJ_bEnumPositionsOnly @ 180008a80 =====

void STROBJ_bEnumPositionsOnly(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180008a80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8a80  1851  STROBJ_bEnumPositionsOnly */
  NtGdiSTROBJ_bEnumPositionsOnly();
  return;
}



===== STROBJ_bGetAdvanceWidths @ 180008a90 =====

void STROBJ_bGetAdvanceWidths(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180008a90. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8a90  1852  STROBJ_bGetAdvanceWidths */
  NtGdiSTROBJ_bGetAdvanceWidths();
  return;
}



===== STROBJ_dwGetCodePage @ 180008aa0 =====

void STROBJ_dwGetCodePage(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180008aa0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8aa0  1853  STROBJ_dwGetCodePage */
  NtGdiSTROBJ_dwGetCodePage();
  return;
}



===== STROBJ_vEnumStart @ 180008ab0 =====

void STROBJ_vEnumStart(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180008ab0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8ab0  1854  STROBJ_vEnumStart */
  NtGdiSTROBJ_vEnumStart();
  return;
}



===== ScaleRgn @ 180008ac0 =====

void ScaleRgn(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180008ac0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8ac0  1856  ScaleRgn */
  NtGdiScaleRgn();
  return;
}



===== ScaleValues @ 180008ad0 =====

void ScaleValues(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180008ad0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8ad0  1857  ScaleValues */
  NtGdiScaleValues();
  return;
}



===== SetMagicColors @ 180008ae0 =====

void SetMagicColors(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180008ae0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8ae0  1932  SetMagicColors */
  NtGdiSetMagicColors();
  return;
}



===== SetOPMSigningKeyAndSequenceNumbers @ 180008af0 =====

void SetOPMSigningKeyAndSequenceNumbers(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180008af0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8af0  1938  SetOPMSigningKeyAndSequenceNumbers */
  NtGdiSetOPMSigningKeyAndSequenceNumbers();
  return;
}



===== XFORMOBJ_bApplyXform @ 180008b00 =====

void XFORMOBJ_bApplyXform(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180008b00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8b00  1981  XFORMOBJ_bApplyXform */
  NtGdiXFORMOBJ_bApplyXform();
  return;
}



===== XFORMOBJ_iGetXform @ 180008b10 =====

void XFORMOBJ_iGetXform(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180008b10. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8b10  1982  XFORMOBJ_iGetXform */
  NtGdiXFORMOBJ_iGetXform();
  return;
}



===== XLATEOBJ_cGetPalette @ 180008b20 =====

void XLATEOBJ_cGetPalette(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180008b20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8b20  1983  XLATEOBJ_cGetPalette */
  NtGdiXLATEOBJ_cGetPalette();
  return;
}



===== XLATEOBJ_hGetColorTransform @ 180008b30 =====

void XLATEOBJ_hGetColorTransform(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180008b30. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8b30  1984  XLATEOBJ_hGetColorTransform */
  NtGdiXLATEOBJ_hGetColorTransform();
  return;
}



===== XLATEOBJ_iXlate @ 180008b40 =====

void XLATEOBJ_iXlate(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180008b40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8b40  1985  XLATEOBJ_iXlate */
  NtGdiXLATEOBJ_iXlate();
  return;
}



===== EnumObjects @ 180008b50 =====

int __stdcall EnumObjects(HDC hdc,int nType,GOBJENUMPROC lpFunc,LPARAM lParam)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180008b50. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8b50  1488  EnumObjects */
  iVar1 = EnumObjects(hdc,nType,lpFunc,lParam);
  return iVar1;
}



===== __tailMerge_ext_ms_win_gdi_dc_l1_2_1_dll @ 180008b56 =====

void __tailMerge_ext_ms_win_gdi_dc_l1_2_1_dll
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 in_RAX;
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = (code *)__delayLoadHelper2(&ImgDelayDescr_180013100,in_RAX);
                    /* WARNING: Could not recover jumptable at 0x000180008bcd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_EnumObjects @ 180008bd5 =====

void DelayLoad_EnumObjects
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_dc_l1_2_1_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetDCBrushColor @ 180008bf0 =====

COLORREF __stdcall GetDCBrushColor(HDC hdc)

{
  COLORREF CVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180008bf0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8bf0  1664  GetDCBrushColor */
  CVar1 = GetDCBrushColor(hdc);
  return CVar1;
}



===== DelayLoad_GetDCBrushColor @ 180008bfc =====

void DelayLoad_GetDCBrushColor
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_dc_l1_2_1_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetDCOrgEx @ 180008c10 =====

BOOL __stdcall GetDCOrgEx(HDC hdc,LPPOINT lppt)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180008c10. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8c10  1666  GetDCOrgEx */
  BVar1 = GetDCOrgEx(hdc,lppt);
  return BVar1;
}



===== __tailMerge_ext_ms_win_gdi_dc_l1_2_0_dll @ 180008c16 =====

void __tailMerge_ext_ms_win_gdi_dc_l1_2_0_dll
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 in_RAX;
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = (code *)__delayLoadHelper2(&ImgDelayDescr_180013120,in_RAX);
                    /* WARNING: Could not recover jumptable at 0x000180008c8d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_GetDCOrgEx @ 180008c95 =====

void DelayLoad_GetDCOrgEx
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_dc_l1_2_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetLayout @ 180008cb0 =====

DWORD __stdcall GetLayout(HDC hdc)

{
  DWORD DVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180008cb0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8cb0  1704  GetLayout */
  DVar1 = GetLayout(hdc);
  return DVar1;
}



===== DelayLoad_GetLayout @ 180008cbc =====

void DelayLoad_GetLayout(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4
                        )

{
  __tailMerge_ext_ms_win_gdi_dc_l1_2_1_dll(param_1,param_2,param_3,param_4);
  return;
}



===== SetDCBrushColor @ 180008cd0 =====

COLORREF __stdcall SetDCBrushColor(HDC hdc,COLORREF color)

{
  COLORREF CVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180008cd0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8cd0  1918  SetDCBrushColor */
  CVar1 = SetDCBrushColor(hdc,color);
  return CVar1;
}



===== DelayLoad_SetDCBrushColor @ 180008cdc =====

void DelayLoad_SetDCBrushColor
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_dc_l1_2_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== IsGetObjectAPresent @ 180008cf0 =====

undefined1 IsGetObjectAPresent(void)

{
  undefined1 uVar1;
  int iVar2;
  
  if (DAT_1800255a0 == 1) {
    uVar1 = 1;
  }
  else {
    if ((DAT_1800255a0 != 2) && (iVar2 = ApiSetQueryApiSetPresence(&DAT_180010010), -1 < iVar2)) {
      DAT_1800255a0 = 2;
      return 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}



===== IsGetNearestPaletteIndexPresent @ 180008d44 =====

undefined1 IsGetNearestPaletteIndexPresent(void)

{
  undefined1 uVar1;
  int iVar2;
  
  if (DAT_1800255a4 == 1) {
    uVar1 = 1;
  }
  else {
    if ((DAT_1800255a4 != 2) && (iVar2 = ApiSetQueryApiSetPresence(&DAT_180010020), -1 < iVar2)) {
      DAT_1800255a4 = 2;
      return 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}



===== DelayLoad_GetObjectType @ 180008d98 =====

void DelayLoad_GetObjectType
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_dc_l1_2_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_GetStockObject @ 180008daa =====

void DelayLoad_GetStockObject
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_dc_l1_2_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_GetCurrentObject @ 180008dbc =====

void DelayLoad_GetCurrentObject
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_dc_l1_2_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_GetObjectA @ 180008dce =====

void DelayLoad_GetObjectA
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_dc_l1_2_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_GetPaletteEntries @ 180008de0 =====

void DelayLoad_GetPaletteEntries
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_dc_l1_2_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_GetSystemPaletteEntries @ 180008df2 =====

void DelayLoad_GetSystemPaletteEntries
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_dc_l1_2_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_CreatePalette @ 180008e04 =====

void DelayLoad_CreatePalette
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_dc_l1_2_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_RealizePalette @ 180008e16 =====

void DelayLoad_RealizePalette
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_dc_l1_2_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_SelectPalette @ 180008e28 =====

void DelayLoad_SelectPalette
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_dc_l1_2_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_GetNearestPaletteIndex @ 180008e3a =====

void DelayLoad_GetNearestPaletteIndex
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_dc_l1_2_1_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_GetObjectW @ 180008e4c =====

void DelayLoad_GetObjectW
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_dc_l1_2_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== IsCreateCompatibleDCPresent @ 180008e60 =====

undefined1 IsCreateCompatibleDCPresent(void)

{
  undefined1 uVar1;
  int iVar2;
  
  if (DAT_1800255a8 == 1) {
    uVar1 = 1;
  }
  else {
    if ((DAT_1800255a8 != 2) && (iVar2 = ApiSetQueryApiSetPresence(&DAT_180010030), -1 < iVar2)) {
      DAT_1800255a8 = 2;
      return 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}



===== __tailMerge_ext_ms_win_gdi_dc_create_l1_1_0_dll @ 180008eae =====

void __tailMerge_ext_ms_win_gdi_dc_create_l1_1_0_dll
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 in_RAX;
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = (code *)__delayLoadHelper2(&ImgDelayDescr_180013140,in_RAX);
                    /* WARNING: Could not recover jumptable at 0x000180008f25. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_CreateCompatibleDC @ 180008f2d =====

void DelayLoad_CreateCompatibleDC
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_dc_create_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== ChoosePixelFormat @ 180008f40 =====

int __stdcall ChoosePixelFormat(HDC hdc,PIXELFORMATDESCRIPTOR *ppfd)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180008f40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8f40  1040  ChoosePixelFormat */
  iVar1 = ChoosePixelFormat(hdc,ppfd);
  return iVar1;
}



===== __tailMerge_ext_ms_win_gdi_draw_l1_1_3_dll @ 180008f46 =====

void __tailMerge_ext_ms_win_gdi_draw_l1_1_3_dll
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 in_RAX;
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = (code *)__delayLoadHelper2(&ImgDelayDescr_180013160,in_RAX);
                    /* WARNING: Could not recover jumptable at 0x000180008fbd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_ChoosePixelFormat @ 180008fc5 =====

void DelayLoad_ChoosePixelFormat
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_draw_l1_1_3_dll(param_1,param_2,param_3,param_4);
  return;
}



===== CreateDIBPatternBrushPt @ 180008fe0 =====

HBRUSH __stdcall CreateDIBPatternBrushPt(void *lpPackedDIB,UINT iUsage)

{
  HBRUSH pHVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180008fe0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8fe0  1068  CreateDIBPatternBrushPt */
  pHVar1 = CreateDIBPatternBrushPt(lpPackedDIB,iUsage);
  return pHVar1;
}



===== __tailMerge_ext_ms_win_gdi_draw_l1_1_2_dll @ 180008fe6 =====

void __tailMerge_ext_ms_win_gdi_draw_l1_1_2_dll
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 in_RAX;
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = (code *)__delayLoadHelper2(&ImgDelayDescr_180013180,in_RAX);
                    /* WARNING: Could not recover jumptable at 0x00018000905d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_CreateDIBPatternBrushPt @ 180009065 =====

void DelayLoad_CreateDIBPatternBrushPt
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_draw_l1_1_2_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiAlphaBlend @ 180009080 =====

BOOL __stdcall
GdiAlphaBlend(HDC hdcDest,int xoriginDest,int yoriginDest,int wDest,int hDest,HDC hdcSrc,
             int xoriginSrc,int yoriginSrc,int wSrc,int hSrc,BLENDFUNCTION ftn)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180009080. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x9080  1521  GdiAlphaBlend */
  BVar1 = GdiAlphaBlend(hdcDest,xoriginDest,yoriginDest,wDest,hDest,hdcSrc,xoriginSrc,yoriginSrc,
                        wSrc,hSrc,ftn);
  return BVar1;
}



===== __tailMerge_ext_ms_win_gdi_draw_l1_1_1_dll @ 180009086 =====

void __tailMerge_ext_ms_win_gdi_draw_l1_1_1_dll
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 in_RAX;
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = (code *)__delayLoadHelper2(&ImgDelayDescr_1800131a0,in_RAX);
                    /* WARNING: Could not recover jumptable at 0x0001800090fd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_GdiAlphaBlend @ 180009105 =====

void DelayLoad_GdiAlphaBlend
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_draw_l1_1_1_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiFlush @ 180009120 =====

BOOL __stdcall GdiFlush(void)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180009120. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x9120  1566  GdiFlush */
  BVar1 = GdiFlush();
  return BVar1;
}



===== __tailMerge_ext_ms_win_gdi_draw_l1_1_0_dll @ 180009126 =====

void __tailMerge_ext_ms_win_gdi_draw_l1_1_0_dll
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 in_RAX;
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = (code *)__delayLoadHelper2(&ImgDelayDescr_1800131c0,in_RAX);
                    /* WARNING: Could not recover jumptable at 0x00018000919d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_GdiFlush @ 1800091a5 =====

void DelayLoad_GdiFlush(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_draw_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiGradientFill @ 1800091c0 =====

BOOL __stdcall
GdiGradientFill(HDC hdc,PTRIVERTEX pVertex,ULONG nVertex,PVOID pMesh,ULONG nCount,ULONG ulMode)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800091c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x91c0  1583  GdiGradientFill */
  BVar1 = GdiGradientFill(hdc,pVertex,nVertex,pMesh,nCount,ulMode);
  return BVar1;
}



===== DelayLoad_GdiGradientFill @ 1800091cc =====

void DelayLoad_GdiGradientFill
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_draw_l1_1_2_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiTransparentBlt @ 1800091e0 =====

BOOL __stdcall
GdiTransparentBlt(HDC hdcDest,int xoriginDest,int yoriginDest,int wDest,int hDest,HDC hdcSrc,
                 int xoriginSrc,int yoriginSrc,int wSrc,int hSrc,UINT crTransparent)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800091e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x91e0  1618  GdiTransparentBlt */
  BVar1 = GdiTransparentBlt(hdcDest,xoriginDest,yoriginDest,wDest,hDest,hdcSrc,xoriginSrc,yoriginSrc
                            ,wSrc,hSrc,crTransparent);
  return BVar1;
}



===== DelayLoad_GdiTransparentBlt @ 1800091ec =====

void DelayLoad_GdiTransparentBlt
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_draw_l1_1_2_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetBkMode @ 180009200 =====

int __stdcall GetBkMode(HDC hdc)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180009200. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x9200  1632  GetBkMode */
  iVar1 = GetBkMode(hdc);
  return iVar1;
}



===== DelayLoad_GetBkMode @ 18000920c =====

void DelayLoad_GetBkMode(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4
                        )

{
  __tailMerge_ext_ms_win_gdi_draw_l1_1_1_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetBrushOrgEx @ 180009220 =====

BOOL __stdcall GetBrushOrgEx(HDC hdc,LPPOINT lppt)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180009220. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x9220  1635  GetBrushOrgEx */
  BVar1 = GetBrushOrgEx(hdc,lppt);
  return BVar1;
}



===== DelayLoad_GetBrushOrgEx @ 18000922c =====

void DelayLoad_GetBrushOrgEx
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_draw_l1_1_2_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetDIBColorTable @ 180009240 =====

UINT __stdcall GetDIBColorTable(HDC hdc,UINT iStart,UINT cEntries,RGBQUAD *prgbq)

{
  UINT UVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180009240. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x9240  1668  GetDIBColorTable */
  UVar1 = GetDIBColorTable(hdc,iStart,cEntries,prgbq);
  return UVar1;
}



===== DelayLoad_GetDIBColorTable @ 18000924c =====

void DelayLoad_GetDIBColorTable
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_draw_l1_1_2_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetMapMode @ 180009260 =====

int __stdcall GetMapMode(HDC hdc)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180009260. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x9260  1707  GetMapMode */
  iVar1 = GetMapMode(hdc);
  return iVar1;
}



===== DelayLoad_GetMapMode @ 18000926c =====

void DelayLoad_GetMapMode
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_draw_l1_1_2_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetWindowExtEx @ 180009280 =====

BOOL __stdcall GetWindowExtEx(HDC hdc,LPSIZE lpsize)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180009280. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x9280  1768  GetWindowExtEx */
  BVar1 = GetWindowExtEx(hdc,lpsize);
  return BVar1;
}



===== DelayLoad_GetWindowExtEx @ 18000928c =====

void DelayLoad_GetWindowExtEx
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_draw_l1_1_2_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetWindowOrgEx @ 1800092a0 =====

BOOL __stdcall GetWindowOrgEx(HDC hdc,LPPOINT lppoint)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800092a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x92a0  1769  GetWindowOrgEx */
  BVar1 = GetWindowOrgEx(hdc,lppoint);
  return BVar1;
}



===== DelayLoad_GetWindowOrgEx @ 1800092ac =====

void DelayLoad_GetWindowOrgEx
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_draw_l1_1_2_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetWorldTransform @ 1800092c0 =====

BOOL __stdcall GetWorldTransform(HDC hdc,LPXFORM lpxf)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800092c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x92c0  1770  GetWorldTransform */
  BVar1 = GetWorldTransform(hdc,lpxf);
  return BVar1;
}



===== DelayLoad_GetWorldTransform @ 1800092cc =====

void DelayLoad_GetWorldTransform
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_draw_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== OffsetViewportOrgEx @ 1800092e0 =====

BOOL __stdcall OffsetViewportOrgEx(HDC hdc,int x,int y,LPPOINT lppt)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800092e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x92e0  1805  OffsetViewportOrgEx */
  BVar1 = OffsetViewportOrgEx(hdc,x,y,lppt);
  return BVar1;
}



===== DelayLoad_OffsetViewportOrgEx @ 1800092ec =====

void DelayLoad_OffsetViewportOrgEx
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_draw_l1_1_1_dll(param_1,param_2,param_3,param_4);
  return;
}



===== OffsetWindowOrgEx @ 180009300 =====

BOOL __stdcall OffsetWindowOrgEx(HDC hdc,int x,int y,LPPOINT lppt)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180009300. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x9300  1806  OffsetWindowOrgEx */
  BVar1 = OffsetWindowOrgEx(hdc,x,y,lppt);
  return BVar1;
}



===== DelayLoad_OffsetWindowOrgEx @ 18000930c =====

void DelayLoad_OffsetWindowOrgEx
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_draw_l1_1_2_dll(param_1,param_2,param_3,param_4);
  return;
}



===== PlgBlt @ 180009320 =====

BOOL __stdcall
PlgBlt(HDC hdcDest,POINT *lpPoint,HDC hdcSrc,int xSrc,int ySrc,int width,int height,HBITMAP hbmMask,
      int xMask,int yMask)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180009320. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x9320  1820  PlgBlt */
  BVar1 = PlgBlt(hdcDest,lpPoint,hdcSrc,xSrc,ySrc,width,height,hbmMask,xMask,yMask);
  return BVar1;
}



===== DelayLoad_PlgBlt @ 18000932c =====

void DelayLoad_PlgBlt(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_draw_l1_1_3_dll(param_1,param_2,param_3,param_4);
  return;
}



===== SetBrushOrgEx @ 180009340 =====

BOOL __stdcall SetBrushOrgEx(HDC hdc,int x,int y,LPPOINT lppt)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180009340. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x9340  1915  SetBrushOrgEx */
  BVar1 = SetBrushOrgEx(hdc,x,y,lppt);
  return BVar1;
}



===== DelayLoad_SetBrushOrgEx @ 18000934c =====

void DelayLoad_SetBrushOrgEx
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_draw_l1_1_2_dll(param_1,param_2,param_3,param_4);
  return;
}



===== SetDIBColorTable @ 180009360 =====

UINT __stdcall SetDIBColorTable(HDC hdc,UINT iStart,UINT cEntries,RGBQUAD *prgbq)

{
  UINT UVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180009360. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x9360  1920  SetDIBColorTable */
  UVar1 = SetDIBColorTable(hdc,iStart,cEntries,prgbq);
  return UVar1;
}



===== DelayLoad_SetDIBColorTable @ 18000936c =====

void DelayLoad_SetDIBColorTable
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_draw_l1_1_2_dll(param_1,param_2,param_3,param_4);
  return;
}



===== SetGraphicsMode @ 180009380 =====

int __stdcall SetGraphicsMode(HDC hdc,int iMode)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180009380. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x9380  1926  SetGraphicsMode */
  iVar1 = SetGraphicsMode(hdc,iMode);
  return iVar1;
}



===== DelayLoad_SetGraphicsMode @ 18000938c =====

void DelayLoad_SetGraphicsMode
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_draw_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== SetLayout @ 1800093a0 =====

DWORD __stdcall SetLayout(HDC hdc,DWORD l)

{
  DWORD DVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800093a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x93a0  1930  SetLayout */
  DVar1 = SetLayout(hdc,l);
  return DVar1;
}



===== DelayLoad_SetLayout @ 1800093ac =====

void DelayLoad_SetLayout(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4
                        )

{
  __tailMerge_ext_ms_win_gdi_draw_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== SetPixelFormat @ 1800093c0 =====

BOOL __stdcall SetPixelFormat(HDC hdc,int format,PIXELFORMATDESCRIPTOR *ppfd)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800093c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x93c0  1941  SetPixelFormat */
  BVar1 = SetPixelFormat(hdc,format,ppfd);
  return BVar1;
}



===== DelayLoad_SetPixelFormat @ 1800093cc =====

void DelayLoad_SetPixelFormat
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_draw_l1_1_3_dll(param_1,param_2,param_3,param_4);
  return;
}



===== SwapBuffers @ 1800093e0 =====

BOOL __stdcall SwapBuffers(HDC param_1)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800093e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x93e0  1968  SwapBuffers */
  BVar1 = SwapBuffers(param_1);
  return BVar1;
}



===== DelayLoad_SwapBuffers @ 1800093ec =====

void DelayLoad_SwapBuffers
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_draw_l1_1_3_dll(param_1,param_2,param_3,param_4);
  return;
}



===== IsBitBltPresent @ 180009400 =====

undefined1 IsBitBltPresent(void)

{
  undefined1 uVar1;
  int iVar2;
  
  if (DAT_1800255e0 == 1) {
    uVar1 = 1;
  }
  else {
    if ((DAT_1800255e0 != 2) && (iVar2 = ApiSetQueryApiSetPresence(&DAT_180010060), -1 < iVar2)) {
      DAT_1800255e0 = 2;
      return 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}



===== IsCreatePatternBrushPresent @ 180009454 =====

undefined1 IsCreatePatternBrushPresent(void)

{
  undefined1 uVar1;
  int iVar2;
  
  if (DAT_1800255e4 == 1) {
    uVar1 = 1;
  }
  else {
    if ((DAT_1800255e4 != 2) && (iVar2 = ApiSetQueryApiSetPresence(&DAT_180010070), -1 < iVar2)) {
      DAT_1800255e4 = 2;
      return 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}



===== IsSetMapModePresent @ 1800094a8 =====

undefined1 IsSetMapModePresent(void)

{
  undefined1 uVar1;
  int iVar2;
  
  if (DAT_1800255e8 == 1) {
    uVar1 = 1;
  }
  else {
    if ((DAT_1800255e8 != 2) && (iVar2 = ApiSetQueryApiSetPresence(&DAT_180010080), -1 < iVar2)) {
      DAT_1800255e8 = 2;
      return 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}



===== DelayLoad_BitBlt @ 1800094fc =====

void DelayLoad_BitBlt(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_draw_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_CreateDIBSection @ 18000950e =====

void DelayLoad_CreateDIBSection
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_draw_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_SetDIBits @ 180009520 =====

void DelayLoad_SetDIBits(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4
                        )

{
  __tailMerge_ext_ms_win_gdi_draw_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_SetMapMode @ 180009532 =====

void DelayLoad_SetMapMode
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_draw_l1_1_2_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_StretchBlt @ 180009544 =====

void DelayLoad_StretchBlt
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_draw_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_CreateBitmap @ 180009556 =====

void DelayLoad_CreateBitmap
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_draw_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_CreateBitmapIndirect @ 180009568 =====

void DelayLoad_CreateBitmapIndirect
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_draw_l1_1_1_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_CreateCompatibleBitmap @ 18000957a =====

void DelayLoad_CreateCompatibleBitmap
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_draw_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_CreatePen @ 18000958c =====

void DelayLoad_CreatePen(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4
                        )

{
  __tailMerge_ext_ms_win_gdi_draw_l1_1_1_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_CreatePatternBrush @ 18000959e =====

void DelayLoad_CreatePatternBrush
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_draw_l1_1_1_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_CreateSolidBrush @ 1800095b0 =====

void DelayLoad_CreateSolidBrush
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_draw_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_GetBkColor @ 1800095c2 =====

void DelayLoad_GetBkColor
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_draw_l1_1_1_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_GetBitmapBits @ 1800095d4 =====

void DelayLoad_GetBitmapBits
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_draw_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_GetDIBits @ 1800095e6 =====

void DelayLoad_GetDIBits(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4
                        )

{
  __tailMerge_ext_ms_win_gdi_draw_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_GetPixel @ 1800095f8 =====

void DelayLoad_GetPixel(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_draw_l1_1_1_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_GetViewportOrgEx @ 18000960a =====

void DelayLoad_GetViewportOrgEx
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_draw_l1_1_1_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_PatBlt @ 18000961c =====

void DelayLoad_PatBlt(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_draw_l1_1_1_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_SetBkColor @ 18000962e =====

void DelayLoad_SetBkColor
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_draw_l1_1_1_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_SetPixel @ 180009640 =====

void DelayLoad_SetPixel(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_draw_l1_1_2_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_DPtoLP @ 180009652 =====

void DelayLoad_DPtoLP(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_draw_l1_1_1_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_Polyline @ 180009664 =====

void DelayLoad_Polyline(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_draw_l1_1_1_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_SetWindowExtEx @ 180009676 =====

void DelayLoad_SetWindowExtEx
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_draw_l1_1_1_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_SetWindowOrgEx @ 180009688 =====

void DelayLoad_SetWindowOrgEx
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_draw_l1_1_1_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_CreateDIBitmap @ 18000969a =====

void DelayLoad_CreateDIBitmap
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_draw_l1_1_2_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_LPtoDP @ 1800096ac =====

void DelayLoad_LPtoDP(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_draw_l1_1_2_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_SetViewportExtEx @ 1800096be =====

void DelayLoad_SetViewportExtEx
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_draw_l1_1_2_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_SetViewportOrgEx @ 1800096d0 =====

void DelayLoad_SetViewportOrgEx
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_draw_l1_1_2_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_SetDIBitsToDevice @ 1800096e2 =====

void DelayLoad_SetDIBitsToDevice
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_draw_l1_1_2_dll(param_1,param_2,param_3,param_4);
  return;
}



===== AddFontMemResourceEx @ 180009700 =====

HANDLE __stdcall AddFontMemResourceEx(PVOID pFileView,DWORD cjSize,PVOID pvResrved,DWORD *pNumFonts)

{
  HANDLE pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180009700. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x9700  1017  AddFontMemResourceEx */
  pvVar1 = AddFontMemResourceEx(pFileView,cjSize,pvResrved,pNumFonts);
  return pvVar1;
}



===== __tailMerge_ext_ms_win_gdi_font_l1_1_2_dll @ 180009706 =====

void __tailMerge_ext_ms_win_gdi_font_l1_1_2_dll
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 in_RAX;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 in_RCX;
  undefined8 in_RDX;
  undefined8 in_XMM2_Qa;
  
  UNRECOVERED_JUMPTABLE = (code *)__delayLoadHelper2(&ImgDelayDescr_1800131e0,in_RAX);
                    /* WARNING: Could not recover jumptable at 0x00018000977d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(in_RCX,in_RDX,in_XMM2_Qa,param_4);
  return;
}



===== DelayLoad_AddFontMemResourceEx @ 180009785 =====

void DelayLoad_AddFontMemResourceEx
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_font_l1_1_2_dll(param_1,param_2,param_3,param_4);
  return;
}



===== EnumFontFamiliesExW @ 1800097a0 =====

int __stdcall
EnumFontFamiliesExW(HDC hdc,LPLOGFONTW lpLogfont,FONTENUMPROCW lpProc,LPARAM lParam,DWORD dwFlags)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800097a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x97a0  1481  EnumFontFamiliesExW */
  iVar1 = EnumFontFamiliesExW(hdc,lpLogfont,lpProc,lParam,dwFlags);
  return iVar1;
}



===== __tailMerge_ext_ms_win_gdi_font_l1_1_0_dll @ 1800097a6 =====

void __tailMerge_ext_ms_win_gdi_font_l1_1_0_dll
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 in_RAX;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 in_RCX;
  
  UNRECOVERED_JUMPTABLE = (code *)__delayLoadHelper2(&ImgDelayDescr_180013200,in_RAX);
                    /* WARNING: Could not recover jumptable at 0x00018000981d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(in_RCX,param_2,param_3,param_4);
  return;
}



===== DelayLoad_EnumFontFamiliesExW @ 180009825 =====

void DelayLoad_EnumFontFamiliesExW
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_font_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== EnumFontsW @ 180009840 =====

int __stdcall EnumFontsW(HDC hdc,LPCWSTR lpLogfont,FONTENUMPROCW lpProc,LPARAM lParam)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180009840. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x9840  1484  EnumFontsW */
  iVar1 = EnumFontsW(hdc,lpLogfont,lpProc,lParam);
  return iVar1;
}



===== DelayLoad_EnumFontsW @ 18000984c =====

void DelayLoad_EnumFontsW
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_font_l1_1_2_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetCharABCWidthsW @ 180009860 =====

BOOL __stdcall GetCharABCWidthsW(HDC hdc,UINT wFirst,UINT wLast,LPABC lpABC)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180009860. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x9860  1646  GetCharABCWidthsW */
  BVar1 = GetCharABCWidthsW(hdc,wFirst,wLast,lpABC);
  return BVar1;
}



===== __tailMerge_ext_ms_win_gdi_font_l1_1_1_dll @ 180009866 =====

void __tailMerge_ext_ms_win_gdi_font_l1_1_1_dll
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 in_RAX;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 in_RCX;
  undefined8 in_RDX;
  undefined8 in_XMM2_Qa;
  
  UNRECOVERED_JUMPTABLE = (code *)__delayLoadHelper2(&ImgDelayDescr_180013220,in_RAX);
                    /* WARNING: Could not recover jumptable at 0x0001800098dd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(in_RCX,in_RDX,in_XMM2_Qa,param_4);
  return;
}



===== DelayLoad_GetCharABCWidthsW @ 1800098e5 =====

void DelayLoad_GetCharABCWidthsW
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_font_l1_1_1_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetCharWidth32A @ 180009900 =====

BOOL __stdcall GetCharWidth32A(HDC hdc,UINT iFirst,UINT iLast,LPINT lpBuffer)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180009900. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x9900  1647  GetCharWidth32A */
  BVar1 = GetCharWidth32A(hdc,iFirst,iLast,lpBuffer);
  return BVar1;
}



===== DelayLoad_GetCharWidth32A @ 18000990c =====

void DelayLoad_GetCharWidth32A
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_font_l1_1_1_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetCharWidthW @ 180009920 =====

BOOL __stdcall GetCharWidthW(HDC hdc,UINT iFirst,UINT iLast,LPINT lpBuffer)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180009920. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x9920  1654  GetCharWidthW */
  BVar1 = GetCharWidthW(hdc,iFirst,iLast,lpBuffer);
  return BVar1;
}



===== DelayLoad_GetCharWidthW @ 18000992c =====

void DelayLoad_GetCharWidthW
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_font_l1_1_1_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetFontFileData @ 180009940 =====

void GetFontFileData(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180009940. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x9940  1685  GetFontFileData */
  GetFontFileData();
  return;
}



===== DelayLoad_GetFontFileData @ 18000994c =====

void DelayLoad_GetFontFileData
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_font_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetFontFileInfo @ 180009960 =====

void GetFontFileInfo(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180009960. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x9960  1686  GetFontFileInfo */
  GetFontFileInfo();
  return;
}



===== DelayLoad_GetFontFileInfo @ 18000996c =====

void DelayLoad_GetFontFileInfo
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_font_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetFontRealizationInfo @ 180009980 =====

void GetFontRealizationInfo(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180009980. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x9980  1688  GetFontRealizationInfo */
  GetFontRealizationInfo();
  return;
}



===== DelayLoad_GetFontRealizationInfo @ 18000998c =====

void DelayLoad_GetFontRealizationInfo
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_font_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetGlyphIndicesW @ 1800099a0 =====

DWORD __stdcall GetGlyphIndicesW(HDC hdc,LPCWSTR lpstr,int c,LPWORD pgi,DWORD fl)

{
  DWORD DVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800099a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x99a0  1692  GetGlyphIndicesW */
  DVar1 = GetGlyphIndicesW(hdc,lpstr,c,pgi,fl);
  return DVar1;
}



===== DelayLoad_GetGlyphIndicesW @ 1800099ac =====

void DelayLoad_GetGlyphIndicesW
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_font_l1_1_1_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetKerningPairsW @ 1800099c0 =====

DWORD __stdcall GetKerningPairsW(HDC hdc,DWORD nPairs,LPKERNINGPAIR lpKernPair)

{
  DWORD DVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800099c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x99c0  1703  GetKerningPairsW */
  DVar1 = GetKerningPairsW(hdc,nPairs,lpKernPair);
  return DVar1;
}



===== DelayLoad_GetKerningPairsW @ 1800099cc =====

void DelayLoad_GetKerningPairsW
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_font_l1_1_1_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetOutlineTextMetricsW @ 1800099e0 =====

UINT __stdcall GetOutlineTextMetricsW(HDC hdc,UINT cjCopy,LPOUTLINETEXTMETRICW potm)

{
  UINT UVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800099e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x99e0  1722  GetOutlineTextMetricsW */
  UVar1 = GetOutlineTextMetricsW(hdc,cjCopy,potm);
  return UVar1;
}



===== DelayLoad_GetOutlineTextMetricsW @ 1800099ec =====

void DelayLoad_GetOutlineTextMetricsW
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_font_l1_1_1_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetProcessSessionFonts @ 180009a00 =====

void GetProcessSessionFonts(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180009a00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x9a00  1731  GetProcessSessionFonts */
  GetProcessSessionFonts();
  return;
}



===== DelayLoad_GetProcessSessionFonts @ 180009a0c =====

void DelayLoad_GetProcessSessionFonts
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_font_l1_1_2_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetTextCharset @ 180009a20 =====

int __stdcall GetTextCharset(HDC hdc)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180009a20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x9a20  1747  GetTextCharset */
  iVar1 = GetTextCharset(hdc);
  return iVar1;
}



===== DelayLoad_GetTextCharset @ 180009a2c =====

void DelayLoad_GetTextCharset
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_font_l1_1_2_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetTextFaceW @ 180009a40 =====

int __stdcall GetTextFaceW(HDC hdc,int c,LPWSTR lpName)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180009a40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x9a40  1761  GetTextFaceW */
  iVar1 = GetTextFaceW(hdc,c,lpName);
  return iVar1;
}



===== DelayLoad_GetTextFaceW @ 180009a4c =====

void DelayLoad_GetTextFaceW
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_font_l1_1_1_dll(param_1,param_2,param_3,param_4);
  return;
}



===== RemoveFontMemResourceEx @ 180009a60 =====

BOOL __stdcall RemoveFontMemResourceEx(HANDLE h)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180009a60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x9a60  1839  RemoveFontMemResourceEx */
  BVar1 = RemoveFontMemResourceEx(h);
  return BVar1;
}



===== DelayLoad_RemoveFontMemResourceEx @ 180009a6c =====

void DelayLoad_RemoveFontMemResourceEx
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_font_l1_1_2_dll(param_1,param_2,param_3,param_4);
  return;
}



===== SetTextCharacterExtra @ 180009a80 =====

int __stdcall SetTextCharacterExtra(HDC hdc,int extra)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180009a80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x9a80  1950  SetTextCharacterExtra */
  iVar1 = SetTextCharacterExtra(hdc,extra);
  return iVar1;
}



===== DelayLoad_SetTextCharacterExtra @ 180009a8c =====

void DelayLoad_SetTextCharacterExtra
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_font_l1_1_2_dll(param_1,param_2,param_3,param_4);
  return;
}



===== TextOutW @ 180009aa0 =====

BOOL __stdcall TextOutW(HDC hdc,int x,int y,LPCWSTR lpString,int c)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180009aa0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x9aa0  1970  TextOutW */
  BVar1 = TextOutW(hdc,x,y,lpString,c);
  return BVar1;
}



===== DelayLoad_TextOutW @ 180009aac =====

void DelayLoad_TextOutW(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_font_l1_1_1_dll(param_1,param_2,param_3,param_4);
  return;
}



===== IsEnumFontFamiliesAPresent @ 180009ac0 =====

undefined1 IsEnumFontFamiliesAPresent(void)

{
  undefined1 uVar1;
  int iVar2;
  
  if (DAT_180025608 == 1) {
    uVar1 = 1;
  }
  else {
    if ((DAT_180025608 != 2) && (iVar2 = ApiSetQueryApiSetPresence(&DAT_1800100a0), -1 < iVar2)) {
      DAT_180025608 = 2;
      return 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}



===== IsGetKerningPairsAPresent @ 180009b14 =====

undefined1 IsGetKerningPairsAPresent(void)

{
  undefined1 uVar1;
  int iVar2;
  
  if (DAT_18002560c == 1) {
    uVar1 = 1;
  }
  else {
    if ((DAT_18002560c != 2) && (iVar2 = ApiSetQueryApiSetPresence(&DAT_1800100b0), -1 < iVar2)) {
      DAT_18002560c = 2;
      return 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}



===== IsGetTextExtentPointWPresent @ 180009b68 =====

undefined1 IsGetTextExtentPointWPresent(void)

{
  undefined1 uVar1;
  int iVar2;
  
  if (DAT_180025610 == 1) {
    uVar1 = 1;
  }
  else {
    if ((DAT_180025610 != 2) && (iVar2 = ApiSetQueryApiSetPresence(&DAT_1800100c0), -1 < iVar2)) {
      DAT_180025610 = 2;
      return 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}



===== IsGetTextExtentExPointIPresent @ 180009bbc =====

undefined1 IsGetTextExtentExPointIPresent(void)

{
  undefined1 uVar1;
  int iVar2;
  
  if (DAT_180025614 == 1) {
    uVar1 = 1;
  }
  else {
    if ((DAT_180025614 != 2) && (iVar2 = ApiSetQueryApiSetPresence(&DAT_1800100d0), -1 < iVar2)) {
      DAT_180025614 = 2;
      return 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}



===== DelayLoad_GetTextExtentPoint32W @ 180009c10 =====

void DelayLoad_GetTextExtentPoint32W
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_font_l1_1_2_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_CreateFontIndirectA @ 180009c22 =====

void DelayLoad_CreateFontIndirectA
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_font_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_EnumFontFamiliesExA @ 180009c34 =====

void DelayLoad_EnumFontFamiliesExA
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_font_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_EnumFontFamiliesA @ 180009c46 =====

void DelayLoad_EnumFontFamiliesA
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_font_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_GetCharWidthA @ 180009c58 =====

void DelayLoad_GetCharWidthA
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_font_l1_1_1_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_GetGlyphOutlineW @ 180009c6a =====

void DelayLoad_GetGlyphOutlineW
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_font_l1_1_1_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_GetOutlineTextMetricsA @ 180009c7c =====

void DelayLoad_GetOutlineTextMetricsA
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_font_l1_1_1_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_TranslateCharsetInfo @ 180009c8e =====

void DelayLoad_TranslateCharsetInfo
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_font_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_GetTextFaceA @ 180009ca0 =====

void DelayLoad_GetTextFaceA
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_font_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_GetKerningPairsA @ 180009cb2 =====

void DelayLoad_GetKerningPairsA
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_font_l1_1_1_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_GetTextAlign @ 180009cc4 =====

void DelayLoad_GetTextAlign
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_font_l1_1_2_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_GetTextColor @ 180009cd6 =====

void DelayLoad_GetTextColor
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_font_l1_1_2_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_GetTextExtentExPointW @ 180009ce8 =====

void DelayLoad_GetTextExtentExPointW
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_font_l1_1_1_dll(param_1,param_2,param_3,param_4);
  return;
}



===== __tailMerge_ext_ms_win_gdi_font_l1_1_3_dll @ 180009cf4 =====

void __tailMerge_ext_ms_win_gdi_font_l1_1_3_dll
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 in_RAX;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 in_RCX;
  
  UNRECOVERED_JUMPTABLE = (code *)__delayLoadHelper2(&ImgDelayDescr_180013240,in_RAX);
                    /* WARNING: Could not recover jumptable at 0x000180009d6b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(in_RCX,param_2,param_3,param_4);
  return;
}



===== DelayLoad_GetTextExtentExPointI @ 180009d73 =====

void DelayLoad_GetTextExtentExPointI
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_font_l1_1_3_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_GetTextExtentPointW @ 180009d85 =====

void DelayLoad_GetTextExtentPointW
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_font_l1_1_2_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_CreateFontW @ 180009d97 =====

void DelayLoad_CreateFontW
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_font_l1_1_2_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_GetTextMetricsW @ 180009da9 =====

void DelayLoad_GetTextMetricsW
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_font_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== CreateEnhMetaFileW @ 180009dc0 =====

HDC __stdcall CreateEnhMetaFileW(HDC hdc,LPCWSTR lpFilename,RECT *lprc,LPCWSTR lpDesc)

{
  HDC pHVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180009dc0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x9dc0  1076  CreateEnhMetaFileW */
  pHVar1 = CreateEnhMetaFileW(hdc,lpFilename,lprc,lpDesc);
  return pHVar1;
}



===== __tailMerge_ext_ms_win_gdi_metafile_l1_1_2_dll @ 180009dc6 =====

void __tailMerge_ext_ms_win_gdi_metafile_l1_1_2_dll
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 in_RAX;
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = (code *)__delayLoadHelper2(&ImgDelayDescr_180013260,in_RAX);
                    /* WARNING: Could not recover jumptable at 0x000180009e3d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_CreateEnhMetaFileW @ 180009e45 =====

void DelayLoad_CreateEnhMetaFileW
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_metafile_l1_1_2_dll(param_1,param_2,param_3,param_4);
  return;
}



===== CreateMetaFileW @ 180009e60 =====

HDC __stdcall CreateMetaFileW(LPCWSTR pszFile)

{
  HDC pHVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180009e60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x9e60  1088  CreateMetaFileW */
  pHVar1 = CreateMetaFileW(pszFile);
  return pHVar1;
}



===== DelayLoad_CreateMetaFileW @ 180009e6c =====

void DelayLoad_CreateMetaFileW
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_metafile_l1_1_2_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetEnhMetaFileHeader @ 180009e80 =====

UINT __stdcall GetEnhMetaFileHeader(HENHMETAFILE hemf,UINT nSize,LPENHMETAHEADER lpEnhMetaHeader)

{
  UINT UVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180009e80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x9e80  1679  GetEnhMetaFileHeader */
  UVar1 = GetEnhMetaFileHeader(hemf,nSize,lpEnhMetaHeader);
  return UVar1;
}



===== __tailMerge_ext_ms_win_gdi_metafile_l1_1_1_dll @ 180009e86 =====

void __tailMerge_ext_ms_win_gdi_metafile_l1_1_1_dll
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 in_RAX;
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = (code *)__delayLoadHelper2(&ImgDelayDescr_180013280,in_RAX);
                    /* WARNING: Could not recover jumptable at 0x000180009efd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_GetEnhMetaFileHeader @ 180009f05 =====

void DelayLoad_GetEnhMetaFileHeader
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_metafile_l1_1_1_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetEnhMetaFilePaletteEntries @ 180009f20 =====

UINT __stdcall
GetEnhMetaFilePaletteEntries(HENHMETAFILE hemf,UINT nNumEntries,LPPALETTEENTRY lpPaletteEntries)

{
  UINT UVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180009f20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x9f20  1680  GetEnhMetaFilePaletteEntries */
  UVar1 = GetEnhMetaFilePaletteEntries(hemf,nNumEntries,lpPaletteEntries);
  return UVar1;
}



===== DelayLoad_GetEnhMetaFilePaletteEntries @ 180009f2c =====

void DelayLoad_GetEnhMetaFilePaletteEntries
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_metafile_l1_1_2_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetEnhMetaFileW @ 180009f40 =====

HENHMETAFILE __stdcall GetEnhMetaFileW(LPCWSTR lpName)

{
  HENHMETAFILE pHVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180009f40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x9f40  1682  GetEnhMetaFileW */
  pHVar1 = GetEnhMetaFileW(lpName);
  return pHVar1;
}



===== DelayLoad_GetEnhMetaFileW @ 180009f4c =====

void DelayLoad_GetEnhMetaFileW
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_metafile_l1_1_2_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetWinMetaFileBits @ 180009f60 =====

UINT __stdcall
GetWinMetaFileBits(HENHMETAFILE hemf,UINT cbData16,LPBYTE pData16,INT iMapMode,HDC hdcRef)

{
  UINT UVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180009f60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x9f60  1767  GetWinMetaFileBits */
  UVar1 = GetWinMetaFileBits(hemf,cbData16,pData16,iMapMode,hdcRef);
  return UVar1;
}



===== DelayLoad_GetWinMetaFileBits @ 180009f6c =====

void DelayLoad_GetWinMetaFileBits
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_metafile_l1_1_1_dll(param_1,param_2,param_3,param_4);
  return;
}



===== SetEnhMetaFileBits @ 180009f80 =====

HENHMETAFILE __stdcall SetEnhMetaFileBits(UINT nSize,BYTE *pb)

{
  HENHMETAFILE pHVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180009f80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x9f80  1924  SetEnhMetaFileBits */
  pHVar1 = SetEnhMetaFileBits(nSize,pb);
  return pHVar1;
}



===== __tailMerge_ext_ms_win_gdi_metafile_l1_1_0_dll @ 180009f86 =====

void __tailMerge_ext_ms_win_gdi_metafile_l1_1_0_dll
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 in_RAX;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 in_RCX;
  undefined8 in_RDX;
  undefined8 in_XMM2_Qa;
  
  UNRECOVERED_JUMPTABLE = (code *)__delayLoadHelper2(&ImgDelayDescr_1800132a0,in_RAX);
                    /* WARNING: Could not recover jumptable at 0x000180009ffd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(in_RCX,in_RDX,in_XMM2_Qa,param_4);
  return;
}



===== DelayLoad_SetEnhMetaFileBits @ 18000a005 =====

void DelayLoad_SetEnhMetaFileBits
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_metafile_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== IsPlayMetaFilePresent @ 18000a018 =====

undefined1 IsPlayMetaFilePresent(void)

{
  undefined1 uVar1;
  int iVar2;
  
  if (DAT_180025640 == 1) {
    uVar1 = 1;
  }
  else {
    if ((DAT_180025640 != 2) && (iVar2 = ApiSetQueryApiSetPresence(&DAT_180010100), -1 < iVar2)) {
      DAT_180025640 = 2;
      return 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}



===== IsCloseMetaFilePresent @ 18000a06c =====

undefined1 IsCloseMetaFilePresent(void)

{
  undefined1 uVar1;
  int iVar2;
  
  if (DAT_18002563c == 1) {
    uVar1 = 1;
  }
  else {
    if ((DAT_18002563c != 2) && (iVar2 = ApiSetQueryApiSetPresence(&DAT_1800100f0), -1 < iVar2)) {
      DAT_18002563c = 2;
      return 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}



===== IsSetMetaFileBitsExPresent @ 18000a0c0 =====

undefined1 IsSetMetaFileBitsExPresent(void)

{
  undefined1 uVar1;
  int iVar2;
  
  if (DAT_180025638 == 1) {
    uVar1 = 1;
  }
  else {
    if ((DAT_180025638 != 2) && (iVar2 = ApiSetQueryApiSetPresence(&DAT_1800100e0), -1 < iVar2)) {
      DAT_180025638 = 2;
      return 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}



===== DelayLoad_CloseEnhMetaFile @ 18000a114 =====

void DelayLoad_CloseEnhMetaFile
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_metafile_l1_1_2_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_CloseMetaFile @ 18000a126 =====

void DelayLoad_CloseMetaFile
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_metafile_l1_1_1_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_CreateMetaFileA @ 18000a138 =====

void DelayLoad_CreateMetaFileA
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_metafile_l1_1_1_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_DeleteEnhMetaFile @ 18000a14a =====

void DelayLoad_DeleteEnhMetaFile
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_metafile_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_DeleteMetaFile @ 18000a15c =====

void DelayLoad_DeleteMetaFile
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_metafile_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_EnumMetaFile @ 18000a16e =====

void DelayLoad_EnumMetaFile
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_metafile_l1_1_1_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_GetMetaFileBitsEx @ 18000a180 =====

void DelayLoad_GetMetaFileBitsEx
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_metafile_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_GetEnhMetaFileBits @ 18000a192 =====

void DelayLoad_GetEnhMetaFileBits
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_metafile_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_SetMetaFileBitsEx @ 18000a1a4 =====

void DelayLoad_SetMetaFileBitsEx
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_metafile_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_CreateEnhMetaFileA @ 18000a1b6 =====

void DelayLoad_CreateEnhMetaFileA
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_metafile_l1_1_2_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_PlayEnhMetaFile @ 18000a1c8 =====

void DelayLoad_PlayEnhMetaFile
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_metafile_l1_1_2_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_PlayMetaFile @ 18000a1da =====

void DelayLoad_PlayMetaFile
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_metafile_l1_1_2_dll(param_1,param_2,param_3,param_4);
  return;
}



===== PathToRegion @ 18000a1f0 =====

HRGN __stdcall PathToRegion(HDC hdc)

{
  HRGN pHVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000a1f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xa1f0  1814  PathToRegion */
  pHVar1 = PathToRegion(hdc);
  return pHVar1;
}



===== __tailMerge_ext_ms_win_gdi_path_l1_1_0_dll @ 18000a1f6 =====

void __tailMerge_ext_ms_win_gdi_path_l1_1_0_dll
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 in_RAX;
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = (code *)__delayLoadHelper2(&ImgDelayDescr_1800132c0,in_RAX);
                    /* WARNING: Could not recover jumptable at 0x00018000a26d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_PathToRegion @ 18000a275 =====

void DelayLoad_PathToRegion
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_path_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== IsStartDocAPresent @ 18000a288 =====

undefined1 IsStartDocAPresent(void)

{
  undefined1 uVar1;
  int iVar2;
  
  if (DAT_180025650 == 1) {
    uVar1 = 1;
  }
  else {
    if ((DAT_180025650 != 2) && (iVar2 = ApiSetQueryApiSetPresence(&DAT_180010110), -1 < iVar2)) {
      DAT_180025650 = 2;
      return 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}



===== __tailMerge_ext_ms_win_gdi_print_l1_1_0_dll @ 18000a2d6 =====

void __tailMerge_ext_ms_win_gdi_print_l1_1_0_dll
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 in_RAX;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 in_RCX;
  undefined8 in_RDX;
  undefined8 in_XMM2_Qa;
  
  UNRECOVERED_JUMPTABLE = (code *)__delayLoadHelper2(&ImgDelayDescr_1800132e0,in_RAX);
                    /* WARNING: Could not recover jumptable at 0x00018000a34d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(in_RCX,in_RDX,in_XMM2_Qa,param_4);
  return;
}



===== DelayLoad_StartDocA @ 18000a355 =====

void DelayLoad_StartDocA(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4
                        )

{
  __tailMerge_ext_ms_win_gdi_print_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DwmGenerateMoveData @ 18000a370 =====

void DwmGenerateMoveData(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000a370. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xa370  1013   */
  Ordinal_1013();
  return;
}



===== __tailMerge_ext_ms_win_gdi_private_l1_1_0_dll @ 18000a376 =====

void __tailMerge_ext_ms_win_gdi_private_l1_1_0_dll
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 in_RAX;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 in_RCX;
  
  UNRECOVERED_JUMPTABLE = (code *)__delayLoadHelper2(&ImgDelayDescr_180013300,in_RAX);
                    /* WARNING: Could not recover jumptable at 0x00018000a3ed. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(in_RCX,param_2,param_3,param_4);
  return;
}



===== DelayLoad_Ordinal_1013 @ 18000a3f5 =====

void DelayLoad_Ordinal_1013
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_private_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DwmGetRedirectionStyle @ 18000a410 =====

void DwmGetRedirectionStyle(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000a410. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xa410  1006   */
  Ordinal_1006();
  return;
}



===== DelayLoad_Ordinal_1006 @ 18000a41c =====

void DelayLoad_Ordinal_1006
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_private_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DwmGetSurfaceData @ 18000a430 =====

void DwmGetSurfaceData(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000a430. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xa430  1003   */
  Ordinal_1003();
  return;
}



===== DelayLoad_Ordinal_1003 @ 18000a43c =====

void DelayLoad_Ordinal_1003
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_private_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DwmHLSurfCloseCompositorRef @ 18000a450 =====

void DwmHLSurfCloseCompositorRef(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000a450. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xa450  1010   */
  Ordinal_1010();
  return;
}



===== DelayLoad_Ordinal_1010 @ 18000a45c =====

void DelayLoad_Ordinal_1010
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_private_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DwmHLSurfGetDirtyRgn @ 18000a470 =====

void DwmHLSurfGetDirtyRgn(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000a470. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xa470  1007   */
  Ordinal_1007();
  return;
}



===== DelayLoad_Ordinal_1007 @ 18000a47c =====

void DelayLoad_Ordinal_1007
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_private_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DwmHLSurfOpenCompositorRef @ 18000a490 =====

void DwmHLSurfOpenCompositorRef(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000a490. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xa490  1009   */
  Ordinal_1009();
  return;
}



===== DelayLoad_Ordinal_1009 @ 18000a49c =====

void DelayLoad_Ordinal_1009
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_private_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DwmHLSurfSetSignalOnDirty @ 18000a4b0 =====

void DwmHLSurfSetSignalOnDirty(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000a4b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xa4b0  1000   */
  Ordinal_1000();
  return;
}



===== DelayLoad_Ordinal_1000 @ 18000a4bc =====

void DelayLoad_Ordinal_1000
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_private_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DwmHLsurfSetPresentFlags @ 18000a4d0 =====

void DwmHLsurfSetPresentFlags(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000a4d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xa4d0  1001   */
  Ordinal_1001();
  return;
}



===== DelayLoad_Ordinal_1001 @ 18000a4dc =====

void DelayLoad_Ordinal_1001
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_private_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DwmHLsurfSetUpdatedId @ 18000a4f0 =====

void DwmHLsurfSetUpdatedId(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000a4f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xa4f0  1002   */
  Ordinal_1002();
  return;
}



===== DelayLoad_Ordinal_1002 @ 18000a4fc =====

void DelayLoad_Ordinal_1002
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_private_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DwmQueryCompositionId @ 18000a510 =====

void DwmQueryCompositionId(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000a510. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xa510  1005   */
  Ordinal_1005();
  return;
}



===== DelayLoad_Ordinal_1005 @ 18000a51c =====

void DelayLoad_Ordinal_1005
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_private_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== SetDeviceGammaRamp @ 18000a530 =====

BOOL __stdcall SetDeviceGammaRamp(HDC hdc,LPVOID lpRamp)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000a530. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xa530  1923  SetDeviceGammaRamp */
  BVar1 = SetDeviceGammaRamp(hdc,lpRamp);
  return BVar1;
}



===== __tailMerge_ext_ms_win_gdi_wcs_l1_1_0_dll @ 18000a536 =====

void __tailMerge_ext_ms_win_gdi_wcs_l1_1_0_dll
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 in_RAX;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 in_RCX;
  undefined8 in_RDX;
  undefined8 in_XMM2_Qa;
  
  UNRECOVERED_JUMPTABLE = (code *)__delayLoadHelper2(&ImgDelayDescr_180013320,in_RAX);
                    /* WARNING: Could not recover jumptable at 0x00018000a5ad. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(in_RCX,in_RDX,in_XMM2_Qa,param_4);
  return;
}



===== DelayLoad_SetDeviceGammaRamp @ 18000a5b5 =====

void DelayLoad_SetDeviceGammaRamp
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_wcs_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== ExcludeClipRect @ 18000a5d0 =====

int __stdcall ExcludeClipRect(HDC hdc,int left,int top,int right,int bottom)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000a5d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xa5d0  1493  ExcludeClipRect */
  iVar1 = ExcludeClipRect(hdc,left,top,right,bottom);
  return iVar1;
}



===== __tailMerge_ext_ms_win_gdi_clipping_l1_1_0_dll @ 18000a5d6 =====

void __tailMerge_ext_ms_win_gdi_clipping_l1_1_0_dll
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 in_RAX;
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = (code *)__delayLoadHelper2(&ImgDelayDescr_180013340,in_RAX);
                    /* WARNING: Could not recover jumptable at 0x00018000a64d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_ExcludeClipRect @ 18000a655 =====

void DelayLoad_ExcludeClipRect
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_clipping_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== IsRectVisiblePresent @ 18000a668 =====

undefined1 IsRectVisiblePresent(void)

{
  undefined1 uVar1;
  int iVar2;
  
  if (DAT_180025678 == 1) {
    uVar1 = 1;
  }
  else {
    if ((DAT_180025678 != 2) && (iVar2 = ApiSetQueryApiSetPresence(&DAT_180010120), -1 < iVar2)) {
      DAT_180025678 = 2;
      return 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}



===== DelayLoad_GetClipRgn @ 18000a6bc =====

void DelayLoad_GetClipRgn
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_clipping_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_RectVisible @ 18000a6ce =====

void DelayLoad_RectVisible
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_clipping_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiDllInitialize @ 18000a6e0 =====

void GdiDllInitialize(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000a6e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xa6e0  1545  GdiDllInitialize */
  GdiDllInitialize();
  return;
}



===== __tailMerge_ext_ms_win_gdi_internal_uap_init_l1_1_0_dll @ 18000a6e6 =====

void __tailMerge_ext_ms_win_gdi_internal_uap_init_l1_1_0_dll
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 in_RAX;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 in_RCX;
  undefined8 in_RDX;
  undefined8 in_XMM2_Qa;
  
  UNRECOVERED_JUMPTABLE = (code *)__delayLoadHelper2(&ImgDelayDescr_180013360,in_RAX);
                    /* WARNING: Could not recover jumptable at 0x00018000a75d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(in_RCX,in_RDX,in_XMM2_Qa,param_4);
  return;
}



===== DelayLoad_GdiDllInitialize @ 18000a765 =====

void DelayLoad_GdiDllInitialize
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_uap_init_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== ModerncoreCreateICW @ 18000a780 =====

void ModerncoreCreateICW(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000a780. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xa780  1797  ModerncoreCreateICW */
  ModerncoreCreateICW();
  return;
}



===== DelayLoad_ModerncoreCreateICW @ 18000a78c =====

void DelayLoad_ModerncoreCreateICW
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_uap_init_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== ModerncoreDeleteDC @ 18000a7a0 =====

void ModerncoreDeleteDC(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000a7a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xa7a0  1798  ModerncoreDeleteDC */
  ModerncoreDeleteDC();
  return;
}



===== DelayLoad_ModerncoreDeleteDC @ 18000a7ac =====

void DelayLoad_ModerncoreDeleteDC
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_uap_init_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== ModerncoreGdiInit @ 18000a7c0 =====

void ModerncoreGdiInit(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000a7c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xa7c0  1799  ModerncoreGdiInit */
  ModerncoreGdiInit();
  return;
}



===== DelayLoad_ModerncoreGdiInit @ 18000a7cc =====

void DelayLoad_ModerncoreGdiInit
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_uap_init_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DeleteColorSpace @ 18000a7e0 =====

BOOL __stdcall DeleteColorSpace(HCOLORSPACE hcs)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000a7e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xa7e0  1414  DeleteColorSpace */
  BVar1 = DeleteColorSpace(hcs);
  return BVar1;
}



===== GdiSupportsFontChangeEvent @ 18000a7f0 =====

void GdiSupportsFontChangeEvent(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000a7f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xa7f0  1614  GdiSupportsFontChangeEvent */
  GdiSupportsFontChangeEvent();
  return;
}



===== GetRandomRgn @ 18000a800 =====

int __stdcall GetRandomRgn(HDC hdc,HRGN hrgn,INT i)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000a800. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xa800  1733  GetRandomRgn */
  iVar1 = GetRandomRgn(hdc,hrgn,i);
  return iVar1;
}



===== InternalDeleteDC @ 18000a810 =====

void InternalDeleteDC(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000a810. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xa810  1773  InternalDeleteDC */
  InternalDeleteDC();
  return;
}



===== PtInRegion @ 18000a820 =====

BOOL __stdcall PtInRegion(HRGN hrgn,int x,int y)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000a820. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xa820  1832  PtInRegion */
  BVar1 = PtInRegion(hrgn,x,y);
  return BVar1;
}



===== SetMetaRgn @ 18000a830 =====

int __stdcall SetMetaRgn(HDC hdc)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000a830. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xa830  1936  SetMetaRgn */
  iVar1 = SetMetaRgn(hdc);
  return iVar1;
}



===== AbortPath @ 18000a840 =====

BOOL __stdcall AbortPath(HDC hdc)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000a840. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xa840  1012  AbortPath */
  BVar1 = AbortPath(hdc);
  return BVar1;
}



===== __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll @ 18000a846 =====

void __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 in_RAX;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 in_RCX;
  undefined8 in_RDX;
  undefined8 in_XMM2_Qa;
  
  UNRECOVERED_JUMPTABLE = (code *)__delayLoadHelper2(&ImgDelayDescr_180013380,in_RAX);
                    /* WARNING: Could not recover jumptable at 0x00018000a8bd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(in_RCX,in_RDX,in_XMM2_Qa,param_4);
  return;
}



===== DelayLoad_AbortPath @ 18000a8c5 =====

void DelayLoad_AbortPath(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4
                        )

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== AddFontResourceExA @ 18000a8e0 =====

int __stdcall AddFontResourceExA(LPCSTR name,DWORD fl,PVOID res)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000a8e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xa8e0  1019  AddFontResourceExA */
  iVar1 = AddFontResourceExA(name,fl,res);
  return iVar1;
}



===== DelayLoad_AddFontResourceExA @ 18000a8ec =====

void DelayLoad_AddFontResourceExA
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== AddFontResourceExW @ 18000a900 =====

int __stdcall AddFontResourceExW(LPCWSTR name,DWORD fl,PVOID res)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000a900. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xa900  1020  AddFontResourceExW */
  iVar1 = AddFontResourceExW(name,fl,res);
  return iVar1;
}



===== DelayLoad_AddFontResourceExW @ 18000a90c =====

void DelayLoad_AddFontResourceExW
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== AddFontResourceTracking @ 18000a920 =====

void AddFontResourceTracking(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000a920. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xa920  1021  AddFontResourceTracking */
  AddFontResourceTracking();
  return;
}



===== DelayLoad_AddFontResourceTracking @ 18000a92c =====

void DelayLoad_AddFontResourceTracking
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== AngleArc @ 18000a940 =====

BOOL __stdcall AngleArc(HDC hdc,int x,int y,DWORD r,FLOAT StartAngle,FLOAT SweepAngle)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000a940. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xa940  1023  AngleArc */
  BVar1 = AngleArc(hdc,x,y,r,StartAngle,SweepAngle);
  return BVar1;
}



===== DelayLoad_AngleArc @ 18000a94c =====

void DelayLoad_AngleArc(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== AnyLinkedFonts @ 18000a960 =====

void AnyLinkedFonts(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000a960. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xa960  1025  AnyLinkedFonts */
  AnyLinkedFonts();
  return;
}



===== DelayLoad_AnyLinkedFonts @ 18000a96c =====

void DelayLoad_AnyLinkedFonts
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== ArcTo @ 18000a980 =====

BOOL __stdcall ArcTo(HDC hdc,int left,int top,int right,int bottom,int xr1,int yr1,int xr2,int yr2)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000a980. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xa980  1027  ArcTo */
  BVar1 = ArcTo(hdc,left,top,right,bottom,xr1,yr1,xr2,yr2);
  return BVar1;
}



===== DelayLoad_ArcTo @ 18000a98c =====

void DelayLoad_ArcTo(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== CancelDC @ 18000a9a0 =====

BOOL __stdcall CancelDC(HDC hdc)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000a9a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xa9a0  1038  CancelDC */
  BVar1 = CancelDC(hdc);
  return BVar1;
}



===== DelayLoad_CancelDC @ 18000a9ac =====

void DelayLoad_CancelDC(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== CheckColorsInGamut @ 18000a9c0 =====

BOOL __stdcall CheckColorsInGamut(HDC hdc,LPRGBTRIPLE lpRGBTriple,LPVOID dlpBuffer,DWORD nCount)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000a9c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xa9c0  1039  CheckColorsInGamut */
  BVar1 = CheckColorsInGamut(hdc,lpRGBTriple,dlpBuffer,nCount);
  return BVar1;
}



===== DelayLoad_CheckColorsInGamut @ 18000a9cc =====

void DelayLoad_CheckColorsInGamut
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== Chord @ 18000a9e0 =====

BOOL __stdcall Chord(HDC hdc,int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000a9e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xa9e0  1041  Chord */
  BVar1 = Chord(hdc,x1,y1,x2,y2,x3,y3,x4,y4);
  return BVar1;
}



===== DelayLoad_Chord @ 18000a9ec =====

void DelayLoad_Chord(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== ClearBitmapAttributes @ 18000aa00 =====

void ClearBitmapAttributes(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000aa00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xaa00  1042  ClearBitmapAttributes */
  ClearBitmapAttributes();
  return;
}



===== DelayLoad_ClearBitmapAttributes @ 18000aa0c =====

void DelayLoad_ClearBitmapAttributes
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== ClearBrushAttributes @ 18000aa20 =====

void ClearBrushAttributes(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000aa20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xaa20  1043  ClearBrushAttributes */
  ClearBrushAttributes();
  return;
}



===== DelayLoad_ClearBrushAttributes @ 18000aa2c =====

void DelayLoad_ClearBrushAttributes
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== ColorCorrectPalette @ 18000aa40 =====

BOOL __stdcall ColorCorrectPalette(HDC hdc,HPALETTE hPal,DWORD deFirst,DWORD num)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000aa40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xaa40  1047  ColorCorrectPalette */
  BVar1 = ColorCorrectPalette(hdc,hPal,deFirst,num);
  return BVar1;
}



===== DelayLoad_ColorCorrectPalette @ 18000aa4c =====

void DelayLoad_ColorCorrectPalette
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== ColorMatchToTarget @ 18000aa60 =====

BOOL __stdcall ColorMatchToTarget(HDC hdc,HDC hdcTarget,DWORD action)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000aa60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xaa60  1048  ColorMatchToTarget */
  BVar1 = ColorMatchToTarget(hdc,hdcTarget,action);
  return BVar1;
}



===== DelayLoad_ColorMatchToTarget @ 18000aa6c =====

void DelayLoad_ColorMatchToTarget
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== CombineTransform @ 18000aa80 =====

BOOL __stdcall CombineTransform(LPXFORM lpxfOut,XFORM *lpxf1,XFORM *lpxf2)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000aa80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xaa80  1050  CombineTransform */
  BVar1 = CombineTransform(lpxfOut,lpxf1,lpxf2);
  return BVar1;
}



===== DelayLoad_CombineTransform @ 18000aa8c =====

void DelayLoad_CombineTransform
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== CopyEnhMetaFileA @ 18000aaa0 =====

HENHMETAFILE __stdcall CopyEnhMetaFileA(HENHMETAFILE hEnh,LPCSTR lpFileName)

{
  HENHMETAFILE pHVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000aaa0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xaaa0  1052  CopyEnhMetaFileA */
  pHVar1 = CopyEnhMetaFileA(hEnh,lpFileName);
  return pHVar1;
}



===== DelayLoad_CopyEnhMetaFileA @ 18000aaac =====

void DelayLoad_CopyEnhMetaFileA
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== CopyEnhMetaFileW @ 18000aac0 =====

HENHMETAFILE __stdcall CopyEnhMetaFileW(HENHMETAFILE hEnh,LPCWSTR lpFileName)

{
  HENHMETAFILE pHVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000aac0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xaac0  1053  CopyEnhMetaFileW */
  pHVar1 = CopyEnhMetaFileW(hEnh,lpFileName);
  return pHVar1;
}



===== DelayLoad_CopyEnhMetaFileW @ 18000aacc =====

void DelayLoad_CopyEnhMetaFileW
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== CopyMetaFileA @ 18000aae0 =====

HMETAFILE __stdcall CopyMetaFileA(HMETAFILE param_1,LPCSTR param_2)

{
  HMETAFILE pHVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000aae0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xaae0  1054  CopyMetaFileA */
  pHVar1 = CopyMetaFileA(param_1,param_2);
  return pHVar1;
}



===== DelayLoad_CopyMetaFileA @ 18000aaec =====

void DelayLoad_CopyMetaFileA
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== CopyMetaFileW @ 18000ab00 =====

HMETAFILE __stdcall CopyMetaFileW(HMETAFILE param_1,LPCWSTR param_2)

{
  HMETAFILE pHVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000ab00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xab00  1055  CopyMetaFileW */
  pHVar1 = CopyMetaFileW(param_1,param_2);
  return pHVar1;
}



===== DelayLoad_CopyMetaFileW @ 18000ab0c =====

void DelayLoad_CopyMetaFileW
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== CreateColorSpaceA @ 18000ab20 =====

HCOLORSPACE __stdcall CreateColorSpaceA(LPLOGCOLORSPACEA lplcs)

{
  HCOLORSPACE pHVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000ab20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xab20  1061  CreateColorSpaceA */
  pHVar1 = CreateColorSpaceA(lplcs);
  return pHVar1;
}



===== DelayLoad_CreateColorSpaceA @ 18000ab2c =====

void DelayLoad_CreateColorSpaceA
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== CreateColorSpaceW @ 18000ab40 =====

HCOLORSPACE __stdcall CreateColorSpaceW(LPLOGCOLORSPACEW lplcs)

{
  HCOLORSPACE pHVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000ab40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xab40  1062  CreateColorSpaceW */
  pHVar1 = CreateColorSpaceW(lplcs);
  return pHVar1;
}



===== DelayLoad_CreateColorSpaceW @ 18000ab4c =====

void DelayLoad_CreateColorSpaceW
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== CreateDCExW @ 18000ab60 =====

void CreateDCExW(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000ab60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xab60  2000  CreateDCExW */
  CreateDCExW();
  return;
}



===== DelayLoad_CreateDCExW @ 18000ab6c =====

void DelayLoad_CreateDCExW
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== CreateDIBPatternBrush @ 18000ab80 =====

HBRUSH __stdcall CreateDIBPatternBrush(HGLOBAL h,UINT iUsage)

{
  HBRUSH pHVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000ab80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xab80  1067  CreateDIBPatternBrush */
  pHVar1 = CreateDIBPatternBrush(h,iUsage);
  return pHVar1;
}



===== DelayLoad_CreateDIBPatternBrush @ 18000ab8c =====

void DelayLoad_CreateDIBPatternBrush
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== CreateDPIScaledDIBSection @ 18000aba0 =====

void CreateDPIScaledDIBSection(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000aba0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xaba0  1071  CreateDPIScaledDIBSection */
  CreateDPIScaledDIBSection();
  return;
}



===== __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_1_dll @ 18000aba6 =====

void __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_1_dll
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 in_RAX;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 in_RCX;
  
  UNRECOVERED_JUMPTABLE = (code *)__delayLoadHelper2(&ImgDelayDescr_1800133a0,in_RAX);
                    /* WARNING: Could not recover jumptable at 0x00018000ac1d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(in_RCX,param_2,param_3,param_4);
  return;
}



===== DelayLoad_CreateDPIScaledDIBSection @ 18000ac25 =====

void DelayLoad_CreateDPIScaledDIBSection
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_1_dll(param_1,param_2,param_3,param_4);
  return;
}



===== CreateDiscardableBitmap @ 18000ac40 =====

HBITMAP __stdcall CreateDiscardableBitmap(HDC hdc,int cx,int cy)

{
  HBITMAP pHVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000ac40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xac40  1072  CreateDiscardableBitmap */
  pHVar1 = CreateDiscardableBitmap(hdc,cx,cy);
  return pHVar1;
}



===== DelayLoad_CreateDiscardableBitmap @ 18000ac4c =====

void DelayLoad_CreateDiscardableBitmap
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== CreateEllipticRgn @ 18000ac60 =====

HRGN __stdcall CreateEllipticRgn(int x1,int y1,int x2,int y2)

{
  HRGN pHVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000ac60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xac60  1073  CreateEllipticRgn */
  pHVar1 = CreateEllipticRgn(x1,y1,x2,y2);
  return pHVar1;
}



===== DelayLoad_CreateEllipticRgn @ 18000ac6c =====

void DelayLoad_CreateEllipticRgn
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== CreateFontIndirectExA @ 18000ac80 =====

HFONT __stdcall CreateFontIndirectExA(ENUMLOGFONTEXDVA *param_1)

{
  HFONT pHVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000ac80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xac80  1079  CreateFontIndirectExA */
  pHVar1 = CreateFontIndirectExA(param_1);
  return pHVar1;
}



===== DelayLoad_CreateFontIndirectExA @ 18000ac8c =====

void DelayLoad_CreateFontIndirectExA
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== CreateFontIndirectExW @ 18000aca0 =====

HFONT __stdcall CreateFontIndirectExW(ENUMLOGFONTEXDVW *param_1)

{
  HFONT pHVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000aca0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xaca0  1080  CreateFontIndirectExW */
  pHVar1 = CreateFontIndirectExW(param_1);
  return pHVar1;
}



===== DelayLoad_CreateFontIndirectExW @ 18000acac =====

void DelayLoad_CreateFontIndirectExW
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== CreateHatchBrush @ 18000acc0 =====

HBRUSH __stdcall CreateHatchBrush(int iHatch,COLORREF color)

{
  HBRUSH pHVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000acc0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xacc0  1084  CreateHatchBrush */
  pHVar1 = CreateHatchBrush(iHatch,color);
  return pHVar1;
}



===== DelayLoad_CreateHatchBrush @ 18000accc =====

void DelayLoad_CreateHatchBrush
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== CreateICA @ 18000ace0 =====

HDC __stdcall CreateICA(LPCSTR pszDriver,LPCSTR pszDevice,LPCSTR pszPort,DEVMODEA *pdm)

{
  HDC pHVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000ace0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xace0  1085  CreateICA */
  pHVar1 = CreateICA(pszDriver,pszDevice,pszPort,pdm);
  return pHVar1;
}



===== DelayLoad_CreateICA @ 18000acec =====

void DelayLoad_CreateICA(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4
                        )

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== CreateScalableFontResourceA @ 18000ad00 =====

BOOL __stdcall
CreateScalableFontResourceA(DWORD fdwHidden,LPCSTR lpszFont,LPCSTR lpszFile,LPCSTR lpszPath)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000ad00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xad00  1100  CreateScalableFontResourceA */
  BVar1 = CreateScalableFontResourceA(fdwHidden,lpszFont,lpszFile,lpszPath);
  return BVar1;
}



===== DelayLoad_CreateScalableFontResourceA @ 18000ad0c =====

void DelayLoad_CreateScalableFontResourceA
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== CreateScaledCompatibleBitmap @ 18000ad20 =====

void CreateScaledCompatibleBitmap(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000ad20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xad20  1102  CreateScaledCompatibleBitmap */
  CreateScaledCompatibleBitmap();
  return;
}



===== __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_3_dll @ 18000ad26 =====

void __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_3_dll
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 in_RAX;
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = (code *)__delayLoadHelper2(&ImgDelayDescr_1800133c0,in_RAX);
                    /* WARNING: Could not recover jumptable at 0x00018000ad9d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_CreateScaledCompatibleBitmap @ 18000ada5 =====

void DelayLoad_CreateScaledCompatibleBitmap
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_3_dll(param_1,param_2,param_3,param_4);
  return;
}



===== CreateSessionMappedDIBSection @ 18000adc0 =====

void CreateSessionMappedDIBSection(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000adc0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xadc0  1103  CreateSessionMappedDIBSection */
  CreateSessionMappedDIBSection();
  return;
}



===== DelayLoad_CreateSessionMappedDIBSection @ 18000adcc =====

void DelayLoad_CreateSessionMappedDIBSection
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DdEntry0 @ 18000ade0 =====

void DdEntry0(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000ade0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xade0  1355  DdEntry0 */
  NtGdiDxgGenericThunk();
  return;
}



===== DelayLoad_NtGdiDxgGenericThunk @ 18000adec =====

void DelayLoad_NtGdiDxgGenericThunk
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DdEntry1 @ 18000ae00 =====

void DdEntry1(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000ae00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xae00  1356  DdEntry1 */
  NtGdiD3dContextCreate();
  return;
}



===== DelayLoad_NtGdiD3dContextCreate @ 18000ae0c =====

void DelayLoad_NtGdiD3dContextCreate
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DdEntry10 @ 18000ae20 =====

void DdEntry10(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000ae20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xae20  1357  DdEntry10 */
  NtGdiDdBeginMoCompFrame();
  return;
}



===== DelayLoad_NtGdiDdBeginMoCompFrame @ 18000ae2c =====

void DelayLoad_NtGdiDdBeginMoCompFrame
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DdEntry11 @ 18000ae40 =====

void DdEntry11(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000ae40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xae40  1358  DdEntry11 */
  NtGdiDdBlt();
  return;
}



===== DelayLoad_NtGdiDdBlt @ 18000ae4c =====

void DelayLoad_NtGdiDdBlt
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DdEntry12 @ 18000ae60 =====

void DdEntry12(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000ae60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xae60  1359  DdEntry12 */
  NtGdiDdCanCreateSurface();
  return;
}



===== DelayLoad_NtGdiDdCanCreateSurface @ 18000ae6c =====

void DelayLoad_NtGdiDdCanCreateSurface
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DdEntry13 @ 18000ae80 =====

void DdEntry13(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000ae80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xae80  1360  DdEntry13 */
  NtGdiDdCanCreateD3DBuffer();
  return;
}



===== DelayLoad_NtGdiDdCanCreateD3DBuffer @ 18000ae8c =====

void DelayLoad_NtGdiDdCanCreateD3DBuffer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DdEntry14 @ 18000aea0 =====

void DdEntry14(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000aea0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xaea0  1361  DdEntry14 */
  NtGdiDdColorControl();
  return;
}



===== DelayLoad_NtGdiDdColorControl @ 18000aeac =====

void DelayLoad_NtGdiDdColorControl
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DdEntry15 @ 18000aec0 =====

void DdEntry15(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000aec0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xaec0  1362  DdEntry15 */
  NtGdiDdCreateDirectDrawObject();
  return;
}



===== DelayLoad_NtGdiDdCreateDirectDrawObject @ 18000aecc =====

void DelayLoad_NtGdiDdCreateDirectDrawObject
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DdEntry16 @ 18000aee0 =====

void DdEntry16(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000aee0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xaee0  1363  DdEntry16 */
  NtGdiDdCreateSurface();
  return;
}



===== DelayLoad_NtGdiDdCreateSurface @ 18000aeec =====

void DelayLoad_NtGdiDdCreateSurface
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DdEntry17 @ 18000af00 =====

void DdEntry17(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000af00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xaf00  1364  DdEntry17 */
  NtGdiDdCreateD3DBuffer();
  return;
}



===== DelayLoad_NtGdiDdCreateD3DBuffer @ 18000af0c =====

void DelayLoad_NtGdiDdCreateD3DBuffer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DdEntry18 @ 18000af20 =====

void DdEntry18(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000af20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xaf20  1365  DdEntry18 */
  NtGdiDdCreateMoComp();
  return;
}



===== DelayLoad_NtGdiDdCreateMoComp @ 18000af2c =====

void DelayLoad_NtGdiDdCreateMoComp
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DdEntry19 @ 18000af40 =====

void DdEntry19(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000af40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xaf40  1366  DdEntry19 */
  NtGdiDdCreateSurfaceObject();
  return;
}



===== DelayLoad_NtGdiDdCreateSurfaceObject @ 18000af4c =====

void DelayLoad_NtGdiDdCreateSurfaceObject
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DdEntry2 @ 18000af60 =====

void DdEntry2(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000af60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xaf60  1367  DdEntry2 */
  NtGdiD3dContextDestroy();
  return;
}



===== DelayLoad_NtGdiD3dContextDestroy @ 18000af6c =====

void DelayLoad_NtGdiD3dContextDestroy
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DdEntry20 @ 18000af80 =====

void DdEntry20(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000af80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xaf80  1368  DdEntry20 */
  NtGdiDdDeleteDirectDrawObject();
  return;
}



===== DelayLoad_NtGdiDdDeleteDirectDrawObject @ 18000af8c =====

void DelayLoad_NtGdiDdDeleteDirectDrawObject
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DdEntry21 @ 18000afa0 =====

void DdEntry21(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000afa0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xafa0  1369  DdEntry21 */
  NtGdiDdDeleteSurfaceObject();
  return;
}



===== DelayLoad_NtGdiDdDeleteSurfaceObject @ 18000afac =====

void DelayLoad_NtGdiDdDeleteSurfaceObject
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DdEntry22 @ 18000afc0 =====

void DdEntry22(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000afc0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xafc0  1370  DdEntry22 */
  NtGdiDdDestroyMoComp();
  return;
}



===== DelayLoad_NtGdiDdDestroyMoComp @ 18000afcc =====

void DelayLoad_NtGdiDdDestroyMoComp
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DdEntry23 @ 18000afe0 =====

void DdEntry23(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000afe0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xafe0  1371  DdEntry23 */
  NtGdiDdDestroySurface();
  return;
}



===== DelayLoad_NtGdiDdDestroySurface @ 18000afec =====

void DelayLoad_NtGdiDdDestroySurface
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DdEntry24 @ 18000b000 =====

void DdEntry24(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000b000. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb000  1372  DdEntry24 */
  NtGdiDdDestroyD3DBuffer();
  return;
}



===== DelayLoad_NtGdiDdDestroyD3DBuffer @ 18000b00c =====

void DelayLoad_NtGdiDdDestroyD3DBuffer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DdEntry25 @ 18000b020 =====

void DdEntry25(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000b020. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb020  1373  DdEntry25 */
  NtGdiDdEndMoCompFrame();
  return;
}



===== DelayLoad_NtGdiDdEndMoCompFrame @ 18000b02c =====

void DelayLoad_NtGdiDdEndMoCompFrame
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DdEntry26 @ 18000b040 =====

void DdEntry26(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000b040. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb040  1374  DdEntry26 */
  NtGdiDdFlip();
  return;
}



===== DelayLoad_NtGdiDdFlip @ 18000b04c =====

void DelayLoad_NtGdiDdFlip
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DdEntry27 @ 18000b060 =====

void DdEntry27(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000b060. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb060  1375  DdEntry27 */
  NtGdiDdFlipToGDISurface();
  return;
}



===== DelayLoad_NtGdiDdFlipToGDISurface @ 18000b06c =====

void DelayLoad_NtGdiDdFlipToGDISurface
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DdEntry28 @ 18000b080 =====

void DdEntry28(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000b080. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb080  1376  DdEntry28 */
  NtGdiDdGetAvailDriverMemory();
  return;
}



===== DelayLoad_NtGdiDdGetAvailDriverMemory @ 18000b08c =====

void DelayLoad_NtGdiDdGetAvailDriverMemory
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DdEntry29 @ 18000b0a0 =====

void DdEntry29(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000b0a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb0a0  1377  DdEntry29 */
  NtGdiDdGetBltStatus();
  return;
}



===== DelayLoad_NtGdiDdGetBltStatus @ 18000b0ac =====

void DelayLoad_NtGdiDdGetBltStatus
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DdEntry3 @ 18000b0c0 =====

void DdEntry3(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000b0c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb0c0  1378  DdEntry3 */
  NtGdiD3dContextDestroyAll();
  return;
}



===== DelayLoad_NtGdiD3dContextDestroyAll @ 18000b0cc =====

void DelayLoad_NtGdiD3dContextDestroyAll
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DdEntry30 @ 18000b0e0 =====

void DdEntry30(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000b0e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb0e0  1379  DdEntry30 */
  NtGdiDdGetDC();
  return;
}



===== DelayLoad_NtGdiDdGetDC @ 18000b0ec =====

void DelayLoad_NtGdiDdGetDC
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DdEntry31 @ 18000b100 =====

void DdEntry31(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000b100. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb100  1380  DdEntry31 */
  NtGdiDdGetDriverInfo();
  return;
}



===== DelayLoad_NtGdiDdGetDriverInfo @ 18000b10c =====

void DelayLoad_NtGdiDdGetDriverInfo
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DdEntry32 @ 18000b120 =====

void DdEntry32(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000b120. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb120  1381  DdEntry32 */
  NtGdiDdGetDxHandle();
  return;
}



===== DelayLoad_NtGdiDdGetDxHandle @ 18000b12c =====

void DelayLoad_NtGdiDdGetDxHandle
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DdEntry33 @ 18000b140 =====

void DdEntry33(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000b140. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb140  1382  DdEntry33 */
  NtGdiDdGetFlipStatus();
  return;
}



===== DelayLoad_NtGdiDdGetFlipStatus @ 18000b14c =====

void DelayLoad_NtGdiDdGetFlipStatus
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DdEntry34 @ 18000b160 =====

void DdEntry34(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000b160. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb160  1383  DdEntry34 */
  NtGdiDdGetInternalMoCompInfo();
  return;
}



===== DelayLoad_NtGdiDdGetInternalMoCompInfo @ 18000b16c =====

void DelayLoad_NtGdiDdGetInternalMoCompInfo
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DdEntry35 @ 18000b180 =====

void DdEntry35(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000b180. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb180  1384  DdEntry35 */
  NtGdiDdGetMoCompBuffInfo();
  return;
}



===== DelayLoad_NtGdiDdGetMoCompBuffInfo @ 18000b18c =====

void DelayLoad_NtGdiDdGetMoCompBuffInfo
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DdEntry36 @ 18000b1a0 =====

void DdEntry36(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000b1a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb1a0  1385  DdEntry36 */
  NtGdiDdGetMoCompGuids();
  return;
}



===== DelayLoad_NtGdiDdGetMoCompGuids @ 18000b1ac =====

void DelayLoad_NtGdiDdGetMoCompGuids
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DdEntry37 @ 18000b1c0 =====

void DdEntry37(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000b1c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb1c0  1386  DdEntry37 */
  NtGdiDdGetMoCompFormats();
  return;
}



===== DelayLoad_NtGdiDdGetMoCompFormats @ 18000b1cc =====

void DelayLoad_NtGdiDdGetMoCompFormats
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DdEntry38 @ 18000b1e0 =====

void DdEntry38(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000b1e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb1e0  1387  DdEntry38 */
  NtGdiDdGetScanLine();
  return;
}



===== DelayLoad_NtGdiDdGetScanLine @ 18000b1ec =====

void DelayLoad_NtGdiDdGetScanLine
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DdEntry39 @ 18000b200 =====

void DdEntry39(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000b200. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb200  1388  DdEntry39 */
  NtGdiDdLock();
  return;
}



===== DelayLoad_NtGdiDdLock @ 18000b20c =====

void DelayLoad_NtGdiDdLock
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DdEntry4 @ 18000b220 =====

void DdEntry4(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000b220. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb220  1389  DdEntry4 */
  NtGdiD3dValidateTextureStageState();
  return;
}



===== DelayLoad_NtGdiD3dValidateTextureStageState @ 18000b22c =====

void DelayLoad_NtGdiD3dValidateTextureStageState
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DdEntry40 @ 18000b240 =====

void DdEntry40(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000b240. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb240  1390  DdEntry40 */
  NtGdiDdLockD3D();
  return;
}



===== DelayLoad_NtGdiDdLockD3D @ 18000b24c =====

void DelayLoad_NtGdiDdLockD3D
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DdEntry41 @ 18000b260 =====

void DdEntry41(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000b260. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb260  1391  DdEntry41 */
  NtGdiDdQueryDirectDrawObject();
  return;
}



===== DelayLoad_NtGdiDdQueryDirectDrawObject @ 18000b26c =====

void DelayLoad_NtGdiDdQueryDirectDrawObject
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DdEntry42 @ 18000b280 =====

void DdEntry42(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000b280. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb280  1392  DdEntry42 */
  NtGdiDdQueryMoCompStatus();
  return;
}



===== DelayLoad_NtGdiDdQueryMoCompStatus @ 18000b28c =====

void DelayLoad_NtGdiDdQueryMoCompStatus
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DdEntry43 @ 18000b2a0 =====

void DdEntry43(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000b2a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb2a0  1393  DdEntry43 */
  NtGdiDdReenableDirectDrawObject();
  return;
}



===== DelayLoad_NtGdiDdReenableDirectDrawObject @ 18000b2ac =====

void DelayLoad_NtGdiDdReenableDirectDrawObject
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DdEntry44 @ 18000b2c0 =====

void DdEntry44(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000b2c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb2c0  1394  DdEntry44 */
  NtGdiDdReleaseDC();
  return;
}



===== DelayLoad_NtGdiDdReleaseDC @ 18000b2cc =====

void DelayLoad_NtGdiDdReleaseDC
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DdEntry45 @ 18000b2e0 =====

void DdEntry45(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000b2e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb2e0  1395  DdEntry45 */
  NtGdiDdRenderMoComp();
  return;
}



===== DelayLoad_NtGdiDdRenderMoComp @ 18000b2ec =====

void DelayLoad_NtGdiDdRenderMoComp
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DdEntry46 @ 18000b300 =====

void DdEntry46(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000b300. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb300  1396  DdEntry46 */
  NtGdiDdResetVisrgn();
  return;
}



===== DelayLoad_NtGdiDdResetVisrgn @ 18000b30c =====

void DelayLoad_NtGdiDdResetVisrgn
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DdEntry47 @ 18000b320 =====

void DdEntry47(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000b320. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb320  1397  DdEntry47 */
  NtGdiDdSetColorKey();
  return;
}



===== DelayLoad_NtGdiDdSetColorKey @ 18000b32c =====

void DelayLoad_NtGdiDdSetColorKey
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DdEntry48 @ 18000b340 =====

void DdEntry48(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000b340. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb340  1398  DdEntry48 */
  NtGdiDdSetExclusiveMode();
  return;
}



===== DelayLoad_NtGdiDdSetExclusiveMode @ 18000b34c =====

void DelayLoad_NtGdiDdSetExclusiveMode
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DdEntry49 @ 18000b360 =====

void DdEntry49(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000b360. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb360  1399  DdEntry49 */
  NtGdiDdSetGammaRamp();
  return;
}



===== DelayLoad_NtGdiDdSetGammaRamp @ 18000b36c =====

void DelayLoad_NtGdiDdSetGammaRamp
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DdEntry5 @ 18000b380 =====

void DdEntry5(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000b380. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb380  1400  DdEntry5 */
  NtGdiD3dDrawPrimitives2();
  return;
}



===== DelayLoad_NtGdiD3dDrawPrimitives2 @ 18000b38c =====

void DelayLoad_NtGdiD3dDrawPrimitives2
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DdEntry50 @ 18000b3a0 =====

void DdEntry50(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000b3a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb3a0  1401  DdEntry50 */
  NtGdiDdCreateSurfaceEx();
  return;
}



===== DelayLoad_NtGdiDdCreateSurfaceEx @ 18000b3ac =====

void DelayLoad_NtGdiDdCreateSurfaceEx
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DdEntry51 @ 18000b3c0 =====

void DdEntry51(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000b3c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb3c0  1402  DdEntry51 */
  NtGdiDdSetOverlayPosition();
  return;
}



===== DelayLoad_NtGdiDdSetOverlayPosition @ 18000b3cc =====

void DelayLoad_NtGdiDdSetOverlayPosition
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DdEntry52 @ 18000b3e0 =====

void DdEntry52(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000b3e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb3e0  1403  DdEntry52 */
  NtGdiDdUnattachSurface();
  return;
}



===== DelayLoad_NtGdiDdUnattachSurface @ 18000b3ec =====

void DelayLoad_NtGdiDdUnattachSurface
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DdEntry53 @ 18000b400 =====

void DdEntry53(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000b400. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb400  1404  DdEntry53 */
  NtGdiDdUnlock();
  return;
}



===== DelayLoad_NtGdiDdUnlock @ 18000b40c =====

void DelayLoad_NtGdiDdUnlock
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DdEntry54 @ 18000b420 =====

void DdEntry54(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000b420. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb420  1405  DdEntry54 */
  NtGdiDdUnlockD3D();
  return;
}



===== DelayLoad_NtGdiDdUnlockD3D @ 18000b42c =====

void DelayLoad_NtGdiDdUnlockD3D
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DdEntry55 @ 18000b440 =====

void DdEntry55(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000b440. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb440  1406  DdEntry55 */
  NtGdiDdUpdateOverlay();
  return;
}



===== DelayLoad_NtGdiDdUpdateOverlay @ 18000b44c =====

void DelayLoad_NtGdiDdUpdateOverlay
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DdEntry56 @ 18000b460 =====

void DdEntry56(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000b460. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb460  1407  DdEntry56 */
  NtGdiDdWaitForVerticalBlank();
  return;
}



===== DelayLoad_NtGdiDdWaitForVerticalBlank @ 18000b46c =====

void DelayLoad_NtGdiDdWaitForVerticalBlank
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DdEntry6 @ 18000b480 =====

void DdEntry6(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000b480. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb480  1408  DdEntry6 */
  NtGdiDdGetDriverState();
  return;
}



===== DelayLoad_NtGdiDdGetDriverState @ 18000b48c =====

void DelayLoad_NtGdiDdGetDriverState
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DdEntry7 @ 18000b4a0 =====

void DdEntry7(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000b4a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb4a0  1409  DdEntry7 */
  NtGdiDdAddAttachedSurface();
  return;
}



===== DelayLoad_NtGdiDdAddAttachedSurface @ 18000b4ac =====

void DelayLoad_NtGdiDdAddAttachedSurface
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DdEntry8 @ 18000b4c0 =====

void DdEntry8(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000b4c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb4c0  1410  DdEntry8 */
  NtGdiDdAlphaBlt();
  return;
}



===== DelayLoad_NtGdiDdAlphaBlt @ 18000b4cc =====

void DelayLoad_NtGdiDdAlphaBlt
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DdEntry9 @ 18000b4e0 =====

void DdEntry9(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000b4e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb4e0  1411  DdEntry9 */
  NtGdiDdAttachSurface();
  return;
}



===== DelayLoad_NtGdiDdAttachSurface @ 18000b4ec =====

void DelayLoad_NtGdiDdAttachSurface
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DescribePixelFormat @ 18000b500 =====

int __stdcall DescribePixelFormat(HDC hdc,int iPixelFormat,UINT nBytes,LPPIXELFORMATDESCRIPTOR ppfd)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000b500. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb500  1419  DescribePixelFormat */
  iVar1 = DescribePixelFormat(hdc,iPixelFormat,nBytes,ppfd);
  return iVar1;
}



===== DelayLoad_DescribePixelFormat @ 18000b50c =====

void DelayLoad_DescribePixelFormat
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DeviceCapabilitiesExA @ 18000b520 =====

void DeviceCapabilitiesExA(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000b520. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb520  1422  DeviceCapabilitiesExA */
  DeviceCapabilitiesExA();
  return;
}



===== DelayLoad_DeviceCapabilitiesExA @ 18000b52c =====

void DelayLoad_DeviceCapabilitiesExA
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DrawEscape @ 18000b540 =====

int __stdcall DrawEscape(HDC hdc,int iEscape,int cjIn,LPCSTR lpIn)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000b540. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb540  1424  DrawEscape */
  iVar1 = DrawEscape(hdc,iEscape,cjIn,lpIn);
  return iVar1;
}



===== DelayLoad_DrawEscape @ 18000b54c =====

void DelayLoad_DrawEscape
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DwmCreatedBitmapRemotingOutput @ 18000b560 =====

void DwmCreatedBitmapRemotingOutput(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000b560. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb560  1014  DwmCreatedBitmapRemotingOutput */
  DwmCreatedBitmapRemotingOutput();
  return;
}



===== DelayLoad_DwmCreatedBitmapRemotingOutput @ 18000b56c =====

void DelayLoad_DwmCreatedBitmapRemotingOutput
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== EndFormPage @ 18000b580 =====

void EndFormPage(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000b580. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb580  1428  EndFormPage */
  EndFormPage();
  return;
}



===== DelayLoad_EndFormPage @ 18000b58c =====

void DelayLoad_EndFormPage
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== EngAcquireSemaphore @ 18000b5a0 =====

void EngAcquireSemaphore(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000b5a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb5a0  1432  EngAcquireSemaphore */
  EngAcquireSemaphore();
  return;
}



===== DelayLoad_EngAcquireSemaphore @ 18000b5ac =====

void DelayLoad_EngAcquireSemaphore
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== EngComputeGlyphSet @ 18000b5c0 =====

void EngComputeGlyphSet(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000b5c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb5c0  1437  EngComputeGlyphSet */
  EngComputeGlyphSet();
  return;
}



===== DelayLoad_EngComputeGlyphSet @ 18000b5cc =====

void DelayLoad_EngComputeGlyphSet
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== EngCreateBitmap @ 18000b5e0 =====

void EngCreateBitmap(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000b5e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb5e0  1439  EngCreateBitmap */
  EngCreateBitmap();
  return;
}



===== DelayLoad_EngCreateBitmap @ 18000b5ec =====

void DelayLoad_EngCreateBitmap
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== EngCreateDeviceBitmap @ 18000b600 =====

void EngCreateDeviceBitmap(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000b600. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb600  1441  EngCreateDeviceBitmap */
  EngCreateDeviceBitmap();
  return;
}



===== DelayLoad_EngCreateDeviceBitmap @ 18000b60c =====

void DelayLoad_EngCreateDeviceBitmap
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== EngCreateDeviceSurface @ 18000b620 =====

void EngCreateDeviceSurface(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000b620. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb620  1442  EngCreateDeviceSurface */
  EngCreateDeviceSurface();
  return;
}



===== DelayLoad_EngCreateDeviceSurface @ 18000b62c =====

void DelayLoad_EngCreateDeviceSurface
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== EngCreatePalette @ 18000b640 =====

void EngCreatePalette(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000b640. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb640  1443  EngCreatePalette */
  EngCreatePalette();
  return;
}



===== DelayLoad_EngCreatePalette @ 18000b64c =====

void DelayLoad_EngCreatePalette
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== EngCreateSemaphore @ 18000b660 =====

void EngCreateSemaphore(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000b660. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb660  1444  EngCreateSemaphore */
  EngCreateSemaphore();
  return;
}



===== DelayLoad_EngCreateSemaphore @ 18000b66c =====

void DelayLoad_EngCreateSemaphore
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== EngDeletePalette @ 18000b680 =====

void EngDeletePalette(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000b680. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb680  1446  EngDeletePalette */
  EngDeletePalette();
  return;
}



===== DelayLoad_EngDeletePalette @ 18000b68c =====

void DelayLoad_EngDeletePalette
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== EngDeleteSemaphore @ 18000b6a0 =====

void EngDeleteSemaphore(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000b6a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb6a0  1448  EngDeleteSemaphore */
  EngDeleteSemaphore();
  return;
}



===== DelayLoad_EngDeleteSemaphore @ 18000b6ac =====

void DelayLoad_EngDeleteSemaphore
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== EngDeleteSurface @ 18000b6c0 =====

void EngDeleteSurface(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000b6c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb6c0  1449  EngDeleteSurface */
  EngDeleteSurface();
  return;
}



===== DelayLoad_EngDeleteSurface @ 18000b6cc =====

void DelayLoad_EngDeleteSurface
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== EngFindResource @ 18000b6e0 =====

void EngFindResource(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000b6e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb6e0  1452  EngFindResource */
  EngFindResource();
  return;
}



===== DelayLoad_EngFindResource @ 18000b6ec =====

void DelayLoad_EngFindResource
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== EngFreeModule @ 18000b700 =====

void EngFreeModule(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000b700. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb700  1453  EngFreeModule */
  EngFreeModule();
  return;
}



===== DelayLoad_EngFreeModule @ 18000b70c =====

void DelayLoad_EngFreeModule
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== EngGetCurrentCodePage @ 18000b720 =====

void EngGetCurrentCodePage(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000b720. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb720  1454  EngGetCurrentCodePage */
  EngGetCurrentCodePage();
  return;
}



===== DelayLoad_EngGetCurrentCodePage @ 18000b72c =====

void DelayLoad_EngGetCurrentCodePage
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== EngGetDriverName @ 18000b740 =====

void EngGetDriverName(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000b740. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb740  1455  EngGetDriverName */
  EngGetDriverName();
  return;
}



===== DelayLoad_EngGetDriverName @ 18000b74c =====

void DelayLoad_EngGetDriverName
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== EngGetPrinterDataFileName @ 18000b760 =====

void EngGetPrinterDataFileName(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000b760. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb760  1456  EngGetPrinterDataFileName */
  EngGetPrinterDataFileName();
  return;
}



===== DelayLoad_EngGetPrinterDataFileName @ 18000b76c =====

void DelayLoad_EngGetPrinterDataFileName
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== EngLoadModule @ 18000b780 =====

void EngLoadModule(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000b780. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb780  1459  EngLoadModule */
  EngLoadModule();
  return;
}



===== DelayLoad_EngLoadModule @ 18000b78c =====

void DelayLoad_EngLoadModule
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== EngMultiByteToUnicodeN @ 18000b7a0 =====

void EngMultiByteToUnicodeN(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000b7a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb7a0  1462  EngMultiByteToUnicodeN */
  EngMultiByteToUnicodeN();
  return;
}



===== DelayLoad_EngMultiByteToUnicodeN @ 18000b7ac =====

void DelayLoad_EngMultiByteToUnicodeN
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== EngMultiByteToWideChar @ 18000b7c0 =====

void EngMultiByteToWideChar(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000b7c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb7c0  1463  EngMultiByteToWideChar */
  EngMultiByteToWideChar();
  return;
}



===== DelayLoad_EngMultiByteToWideChar @ 18000b7cc =====

void DelayLoad_EngMultiByteToWideChar
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== EngQueryEMFInfo @ 18000b7e0 =====

void EngQueryEMFInfo(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000b7e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb7e0  1466  EngQueryEMFInfo */
  EngQueryEMFInfo();
  return;
}



===== DelayLoad_EngQueryEMFInfo @ 18000b7ec =====

void DelayLoad_EngQueryEMFInfo
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== EngQueryLocalTime @ 18000b800 =====

void EngQueryLocalTime(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000b800. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb800  1467  EngQueryLocalTime */
  EngQueryLocalTime();
  return;
}



===== DelayLoad_EngQueryLocalTime @ 18000b80c =====

void DelayLoad_EngQueryLocalTime
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== EngReleaseSemaphore @ 18000b820 =====

void EngReleaseSemaphore(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000b820. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb820  1468  EngReleaseSemaphore */
  EngReleaseSemaphore();
  return;
}



===== DelayLoad_EngReleaseSemaphore @ 18000b82c =====

void DelayLoad_EngReleaseSemaphore
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== EngUnicodeToMultiByteN @ 18000b840 =====

void EngUnicodeToMultiByteN(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000b840. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb840  1475  EngUnicodeToMultiByteN */
  EngUnicodeToMultiByteN();
  return;
}



===== DelayLoad_EngUnicodeToMultiByteN @ 18000b84c =====

void DelayLoad_EngUnicodeToMultiByteN
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== EngWideCharToMultiByte @ 18000b860 =====

void EngWideCharToMultiByte(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000b860. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb860  1477  EngWideCharToMultiByte */
  EngWideCharToMultiByte();
  return;
}



===== DelayLoad_EngWideCharToMultiByte @ 18000b86c =====

void DelayLoad_EngWideCharToMultiByte
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== EnumFontFamiliesW @ 18000b880 =====

int __stdcall EnumFontFamiliesW(HDC hdc,LPCWSTR lpLogfont,FONTENUMPROCW lpProc,LPARAM lParam)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000b880. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb880  1482  EnumFontFamiliesW */
  iVar1 = EnumFontFamiliesW(hdc,lpLogfont,lpProc,lParam);
  return iVar1;
}



===== DelayLoad_EnumFontFamiliesW @ 18000b88c =====

void DelayLoad_EnumFontFamiliesW
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== EnumFontsA @ 18000b8a0 =====

int __stdcall EnumFontsA(HDC hdc,LPCSTR lpLogfont,FONTENUMPROCA lpProc,LPARAM lParam)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000b8a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb8a0  1483  EnumFontsA */
  iVar1 = EnumFontsA(hdc,lpLogfont,lpProc,lParam);
  return iVar1;
}



===== DelayLoad_EnumFontsA @ 18000b8ac =====

void DelayLoad_EnumFontsA
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== EnumICMProfilesA @ 18000b8c0 =====

int __stdcall EnumICMProfilesA(HDC hdc,ICMENUMPROCA proc,LPARAM param)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000b8c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb8c0  1485  EnumICMProfilesA */
  iVar1 = EnumICMProfilesA(hdc,proc,param);
  return iVar1;
}



===== DelayLoad_EnumICMProfilesA @ 18000b8cc =====

void DelayLoad_EnumICMProfilesA
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== EnumICMProfilesW @ 18000b8e0 =====

int __stdcall EnumICMProfilesW(HDC hdc,ICMENUMPROCW proc,LPARAM param)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000b8e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb8e0  1486  EnumICMProfilesW */
  iVar1 = EnumICMProfilesW(hdc,proc,param);
  return iVar1;
}



===== DelayLoad_EnumICMProfilesW @ 18000b8ec =====

void DelayLoad_EnumICMProfilesW
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== EudcLoadLinkW @ 18000b900 =====

void EudcLoadLinkW(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000b900. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb900  1491  EudcLoadLinkW */
  EudcLoadLinkW();
  return;
}



===== DelayLoad_EudcLoadLinkW @ 18000b90c =====

void DelayLoad_EudcLoadLinkW
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== EudcUnloadLinkW @ 18000b920 =====

void EudcUnloadLinkW(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000b920. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb920  1492  EudcUnloadLinkW */
  EudcUnloadLinkW();
  return;
}



===== DelayLoad_EudcUnloadLinkW @ 18000b92c =====

void DelayLoad_EudcUnloadLinkW
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== ExtCreatePen @ 18000b940 =====

HPEN __stdcall
ExtCreatePen(DWORD iPenStyle,DWORD cWidth,LOGBRUSH *plbrush,DWORD cStyle,DWORD *pstyle)

{
  HPEN pHVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000b940. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb940  1494  ExtCreatePen */
  pHVar1 = ExtCreatePen(iPenStyle,cWidth,plbrush,cStyle,pstyle);
  return pHVar1;
}



===== DelayLoad_ExtCreatePen @ 18000b94c =====

void DelayLoad_ExtCreatePen
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== ExtFloodFill @ 18000b960 =====

BOOL __stdcall ExtFloodFill(HDC hdc,int x,int y,COLORREF color,UINT type)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000b960. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb960  1497  ExtFloodFill */
  BVar1 = ExtFloodFill(hdc,x,y,color,type);
  return BVar1;
}



===== DelayLoad_ExtFloodFill @ 18000b96c =====

void DelayLoad_ExtFloodFill
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== FixBrushOrgEx @ 18000b980 =====

BOOL __stdcall FixBrushOrgEx(HDC hdc,int x,int y,LPPOINT ptl)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000b980. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb980  1511  FixBrushOrgEx */
  BVar1 = FixBrushOrgEx(hdc,x,y,ptl);
  return BVar1;
}



===== DelayLoad_FixBrushOrgEx @ 18000b98c =====

void DelayLoad_FixBrushOrgEx
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== FlattenPath @ 18000b9a0 =====

BOOL __stdcall FlattenPath(HDC hdc)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000b9a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb9a0  1512  FlattenPath */
  BVar1 = FlattenPath(hdc);
  return BVar1;
}



===== DelayLoad_FlattenPath @ 18000b9ac =====

void DelayLoad_FlattenPath
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== FloodFill @ 18000b9c0 =====

BOOL __stdcall FloodFill(HDC hdc,int x,int y,COLORREF color)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000b9c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb9c0  1513  FloodFill */
  BVar1 = FloodFill(hdc,x,y,color);
  return BVar1;
}



===== DelayLoad_FloodFill @ 18000b9cc =====

void DelayLoad_FloodFill(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4
                        )

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== FontIsLinked @ 18000b9e0 =====

void FontIsLinked(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000b9e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xb9e0  1514  FontIsLinked */
  FontIsLinked();
  return;
}



===== DelayLoad_FontIsLinked @ 18000b9ec =====

void DelayLoad_FontIsLinked
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiAddFontResourceW @ 18000ba00 =====

void GdiAddFontResourceW(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000ba00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xba00  1517  GdiAddFontResourceW */
  GdiAddFontResourceW();
  return;
}



===== DelayLoad_GdiAddFontResourceW @ 18000ba0c =====

void DelayLoad_GdiAddFontResourceW
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiAddGlsBounds @ 18000ba20 =====

void GdiAddGlsBounds(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000ba20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xba20  1518  GdiAddGlsBounds */
  GdiAddGlsBounds();
  return;
}



===== DelayLoad_GdiAddGlsBounds @ 18000ba2c =====

void DelayLoad_GdiAddGlsBounds
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiAddGlsRecord @ 18000ba40 =====

void GdiAddGlsRecord(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000ba40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xba40  1519  GdiAddGlsRecord */
  GdiAddGlsRecord();
  return;
}



===== DelayLoad_GdiAddGlsRecord @ 18000ba4c =====

void DelayLoad_GdiAddGlsRecord
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiAddInitialFonts @ 18000ba60 =====

void GdiAddInitialFonts(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000ba60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xba60  1520  GdiAddInitialFonts */
  GdiAddInitialFonts();
  return;
}



===== DelayLoad_GdiAddInitialFonts @ 18000ba6c =====

void DelayLoad_GdiAddInitialFonts
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_1_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiArtificialDecrementDriver @ 18000ba80 =====

void GdiArtificialDecrementDriver(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000ba80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xba80  1522  GdiArtificialDecrementDriver */
  GdiArtificialDecrementDriver();
  return;
}



===== DelayLoad_GdiArtificialDecrementDriver @ 18000ba8c =====

void DelayLoad_GdiArtificialDecrementDriver
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiCleanCacheDC @ 18000baa0 =====

void GdiCleanCacheDC(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000baa0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xbaa0  1524  GdiCleanCacheDC */
  GdiCleanCacheDC();
  return;
}



===== DelayLoad_GdiCleanCacheDC @ 18000baac =====

void DelayLoad_GdiCleanCacheDC
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiConsoleTextOut @ 18000bac0 =====

void GdiConsoleTextOut(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000bac0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xbac0  1526  GdiConsoleTextOut */
  GdiConsoleTextOut();
  return;
}



===== DelayLoad_GdiConsoleTextOut @ 18000bacc =====

void DelayLoad_GdiConsoleTextOut
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiConvertAndCheckDC @ 18000bae0 =====

void GdiConvertAndCheckDC(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000bae0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xbae0  1527  GdiConvertAndCheckDC */
  GdiConvertAndCheckDC();
  return;
}



===== DelayLoad_GdiConvertAndCheckDC @ 18000baec =====

void DelayLoad_GdiConvertAndCheckDC
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiConvertBitmap @ 18000bb00 =====

void GdiConvertBitmap(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000bb00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xbb00  1528  GdiConvertBitmap */
  GdiConvertBitmap();
  return;
}



===== DelayLoad_GdiConvertBitmap @ 18000bb0c =====

void DelayLoad_GdiConvertBitmap
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiConvertBitmapV5 @ 18000bb20 =====

void GdiConvertBitmapV5(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000bb20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xbb20  1529  GdiConvertBitmapV5 */
  GdiConvertBitmapV5();
  return;
}



===== DelayLoad_GdiConvertBitmapV5 @ 18000bb2c =====

void DelayLoad_GdiConvertBitmapV5
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiConvertBrush @ 18000bb40 =====

void GdiConvertBrush(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000bb40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xbb40  1530  GdiConvertBrush */
  GdiConvertBrush();
  return;
}



===== DelayLoad_GdiConvertBrush @ 18000bb4c =====

void DelayLoad_GdiConvertBrush
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiConvertDC @ 18000bb60 =====

void GdiConvertDC(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000bb60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xbb60  1531  GdiConvertDC */
  GdiConvertDC();
  return;
}



===== DelayLoad_GdiConvertDC @ 18000bb6c =====

void DelayLoad_GdiConvertDC
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiConvertEnhMetaFile @ 18000bb80 =====

void GdiConvertEnhMetaFile(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000bb80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xbb80  1532  GdiConvertEnhMetaFile */
  GdiConvertEnhMetaFile();
  return;
}



===== DelayLoad_GdiConvertEnhMetaFile @ 18000bb8c =====

void DelayLoad_GdiConvertEnhMetaFile
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiConvertFont @ 18000bba0 =====

void GdiConvertFont(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000bba0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xbba0  1533  GdiConvertFont */
  GdiConvertFont();
  return;
}



===== DelayLoad_GdiConvertFont @ 18000bbac =====

void DelayLoad_GdiConvertFont
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiConvertMetaFilePict @ 18000bbc0 =====

void GdiConvertMetaFilePict(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000bbc0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xbbc0  1534  GdiConvertMetaFilePict */
  GdiConvertMetaFilePict();
  return;
}



===== DelayLoad_GdiConvertMetaFilePict @ 18000bbcc =====

void DelayLoad_GdiConvertMetaFilePict
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiConvertPalette @ 18000bbe0 =====

void GdiConvertPalette(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000bbe0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xbbe0  1535  GdiConvertPalette */
  GdiConvertPalette();
  return;
}



===== DelayLoad_GdiConvertPalette @ 18000bbec =====

void DelayLoad_GdiConvertPalette
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiConvertRegion @ 18000bc00 =====

void GdiConvertRegion(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000bc00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xbc00  1536  GdiConvertRegion */
  GdiConvertRegion();
  return;
}



===== DelayLoad_GdiConvertRegion @ 18000bc0c =====

void DelayLoad_GdiConvertRegion
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiConvertToDevmodeW @ 18000bc20 =====

void GdiConvertToDevmodeW(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000bc20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xbc20  1537  GdiConvertToDevmodeW */
  GdiConvertToDevmodeW();
  return;
}



===== DelayLoad_GdiConvertToDevmodeW @ 18000bc2c =====

void DelayLoad_GdiConvertToDevmodeW
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiCreateLocalEnhMetaFile @ 18000bc40 =====

void GdiCreateLocalEnhMetaFile(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000bc40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xbc40  1538  GdiCreateLocalEnhMetaFile */
  GdiCreateLocalEnhMetaFile();
  return;
}



===== DelayLoad_GdiCreateLocalEnhMetaFile @ 18000bc4c =====

void DelayLoad_GdiCreateLocalEnhMetaFile
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiCreateLocalMetaFilePict @ 18000bc60 =====

void GdiCreateLocalMetaFilePict(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000bc60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xbc60  1539  GdiCreateLocalMetaFilePict */
  GdiCreateLocalMetaFilePict();
  return;
}



===== DelayLoad_GdiCreateLocalMetaFilePict @ 18000bc6c =====

void DelayLoad_GdiCreateLocalMetaFilePict
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiCurrentProcessSplWow64 @ 18000bc80 =====

void GdiCurrentProcessSplWow64(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000bc80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xbc80  1540  GdiCurrentProcessSplWow64 */
  GdiCurrentProcessSplWow64();
  return;
}



===== __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_2_dll @ 18000bc86 =====

void __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_2_dll
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 in_RAX;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 in_RCX;
  
  UNRECOVERED_JUMPTABLE = (code *)__delayLoadHelper2(&ImgDelayDescr_1800133e0,in_RAX);
                    /* WARNING: Could not recover jumptable at 0x00018000bcfd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(in_RCX,param_2,param_3,param_4);
  return;
}



===== DelayLoad_GdiCurrentProcessSplWow64 @ 18000bd05 =====

void DelayLoad_GdiCurrentProcessSplWow64
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_2_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiDeleteLocalDC @ 18000bd20 =====

void GdiDeleteLocalDC(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000bd20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xbd20  1541  GdiDeleteLocalDC */
  GdiDeleteLocalDC();
  return;
}



===== DelayLoad_GdiDeleteLocalDC @ 18000bd2c =====

void DelayLoad_GdiDeleteLocalDC
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiDeleteSpoolFileHandle @ 18000bd40 =====

void GdiDeleteSpoolFileHandle(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000bd40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xbd40  1542  GdiDeleteSpoolFileHandle */
  GdiDeleteSpoolFileHandle();
  return;
}



===== DelayLoad_GdiDeleteSpoolFileHandle @ 18000bd4c =====

void DelayLoad_GdiDeleteSpoolFileHandle
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiDescribePixelFormat @ 18000bd60 =====

void GdiDescribePixelFormat(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000bd60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xbd60  1543  GdiDescribePixelFormat */
  GdiDescribePixelFormat();
  return;
}



===== DelayLoad_GdiDescribePixelFormat @ 18000bd6c =====

void DelayLoad_GdiDescribePixelFormat
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiDisableUMPDSandboxing @ 18000bd80 =====

void GdiDisableUMPDSandboxing(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000bd80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xbd80  1544  GdiDisableUMPDSandboxing */
  GdiDisableUMPDSandboxing();
  return;
}



===== __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_4_dll @ 18000bd86 =====

void __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_4_dll
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 in_RAX;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 in_RCX;
  
  UNRECOVERED_JUMPTABLE = (code *)__delayLoadHelper2(&ImgDelayDescr_180013400,in_RAX);
                    /* WARNING: Could not recover jumptable at 0x00018000bdfd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(in_RCX,param_2,param_3,param_4);
  return;
}



===== DelayLoad_GdiDisableUMPDSandboxing @ 18000be05 =====

void DelayLoad_GdiDisableUMPDSandboxing
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_4_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiDrawStream @ 18000be20 =====

void GdiDrawStream(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000be20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xbe20  1546  GdiDrawStream */
  GdiDrawStream();
  return;
}



===== DelayLoad_GdiDrawStream @ 18000be2c =====

void DelayLoad_GdiDrawStream
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiEndDocEMF @ 18000be40 =====

void GdiEndDocEMF(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000be40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xbe40  1547  GdiEndDocEMF */
  GdiEndDocEMF();
  return;
}



===== DelayLoad_GdiEndDocEMF @ 18000be4c =====

void DelayLoad_GdiEndDocEMF
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiEndPageEMF @ 18000be60 =====

void GdiEndPageEMF(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000be60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xbe60  1548  GdiEndPageEMF */
  GdiEndPageEMF();
  return;
}



===== DelayLoad_GdiEndPageEMF @ 18000be6c =====

void DelayLoad_GdiEndPageEMF
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiEntry1 @ 18000be80 =====

void GdiEntry1(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000be80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xbe80  1549  GdiEntry1 */
  GdiEntry1();
  return;
}



===== DelayLoad_GdiEntry1 @ 18000be8c =====

void DelayLoad_GdiEntry1(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4
                        )

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiEntry10 @ 18000bea0 =====

void GdiEntry10(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000bea0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xbea0  1550  GdiEntry10 */
  GdiEntry10();
  return;
}



===== DelayLoad_GdiEntry10 @ 18000beac =====

void DelayLoad_GdiEntry10
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiEntry11 @ 18000bec0 =====

void GdiEntry11(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000bec0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xbec0  1551  GdiEntry11 */
  GdiEntry11();
  return;
}



===== DelayLoad_GdiEntry11 @ 18000becc =====

void DelayLoad_GdiEntry11
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiEntry12 @ 18000bee0 =====

void GdiEntry12(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000bee0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xbee0  1552  GdiEntry12 */
  GdiEntry12();
  return;
}



===== DelayLoad_GdiEntry12 @ 18000beec =====

void DelayLoad_GdiEntry12
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiEntry14 @ 18000bf00 =====

void GdiEntry14(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000bf00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xbf00  1554  GdiEntry14 */
  GdiEntry14();
  return;
}



===== DelayLoad_GdiEntry14 @ 18000bf0c =====

void DelayLoad_GdiEntry14
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiEntry15 @ 18000bf20 =====

void GdiEntry15(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000bf20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xbf20  1555  GdiEntry15 */
  GdiEntry15();
  return;
}



===== DelayLoad_GdiEntry15 @ 18000bf2c =====

void DelayLoad_GdiEntry15
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiEntry16 @ 18000bf40 =====

void GdiEntry16(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000bf40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xbf40  1556  GdiEntry16 */
  GdiEntry16();
  return;
}



===== DelayLoad_GdiEntry16 @ 18000bf4c =====

void DelayLoad_GdiEntry16
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiEntry2 @ 18000bf60 =====

void GdiEntry2(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000bf60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xbf60  1557  GdiEntry2 */
  GdiEntry2();
  return;
}



===== DelayLoad_GdiEntry2 @ 18000bf6c =====

void DelayLoad_GdiEntry2(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4
                        )

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiEntry3 @ 18000bf80 =====

void GdiEntry3(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000bf80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xbf80  1558  GdiEntry3 */
  GdiEntry3();
  return;
}



===== DelayLoad_GdiEntry3 @ 18000bf8c =====

void DelayLoad_GdiEntry3(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4
                        )

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiEntry4 @ 18000bfa0 =====

void GdiEntry4(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000bfa0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xbfa0  1559  GdiEntry4 */
  GdiEntry4();
  return;
}



===== DelayLoad_GdiEntry4 @ 18000bfac =====

void DelayLoad_GdiEntry4(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4
                        )

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiEntry5 @ 18000bfc0 =====

void GdiEntry5(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000bfc0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xbfc0  1560  GdiEntry5 */
  GdiEntry5();
  return;
}



===== DelayLoad_GdiEntry5 @ 18000bfcc =====

void DelayLoad_GdiEntry5(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4
                        )

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiEntry6 @ 18000bfe0 =====

void GdiEntry6(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000bfe0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xbfe0  1561  GdiEntry6 */
  GdiEntry6();
  return;
}



===== DelayLoad_GdiEntry6 @ 18000bfec =====

void DelayLoad_GdiEntry6(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4
                        )

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiEntry7 @ 18000c000 =====

void GdiEntry7(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000c000. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc000  1562  GdiEntry7 */
  GdiEntry7();
  return;
}



===== DelayLoad_GdiEntry7 @ 18000c00c =====

void DelayLoad_GdiEntry7(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4
                        )

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiEntry8 @ 18000c020 =====

void GdiEntry8(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000c020. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc020  1563  GdiEntry8 */
  GdiEntry8();
  return;
}



===== DelayLoad_GdiEntry8 @ 18000c02c =====

void DelayLoad_GdiEntry8(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4
                        )

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiEntry9 @ 18000c040 =====

void GdiEntry9(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000c040. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc040  1564  GdiEntry9 */
  GdiEntry9();
  return;
}



===== DelayLoad_GdiEntry9 @ 18000c04c =====

void DelayLoad_GdiEntry9(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4
                        )

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiFixUpHandle @ 18000c060 =====

void GdiFixUpHandle(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000c060. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc060  1565  GdiFixUpHandle */
  GdiFixUpHandle();
  return;
}



===== DelayLoad_GdiFixUpHandle @ 18000c06c =====

void DelayLoad_GdiFixUpHandle
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiGetBatchLimit @ 18000c080 =====

DWORD __stdcall GdiGetBatchLimit(void)

{
  DWORD DVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000c080. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc080  1568  GdiGetBatchLimit */
  DVar1 = GdiGetBatchLimit();
  return DVar1;
}



===== DelayLoad_GdiGetBatchLimit @ 18000c08c =====

void DelayLoad_GdiGetBatchLimit
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiGetBitmapBitsSize @ 18000c0a0 =====

void GdiGetBitmapBitsSize(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000c0a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc0a0  1569  GdiGetBitmapBitsSize */
  GdiGetBitmapBitsSize();
  return;
}



===== DelayLoad_GdiGetBitmapBitsSize @ 18000c0ac =====

void DelayLoad_GdiGetBitmapBitsSize
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiGetCharDimensions @ 18000c0c0 =====

void GdiGetCharDimensions(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000c0c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc0c0  1570  GdiGetCharDimensions */
  GdiGetCharDimensions();
  return;
}



===== DelayLoad_GdiGetCharDimensions @ 18000c0cc =====

void DelayLoad_GdiGetCharDimensions
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiGetCodePage @ 18000c0e0 =====

void GdiGetCodePage(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000c0e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc0e0  1571  GdiGetCodePage */
  GetCodePage();
  return;
}



===== DelayLoad_GetCodePage @ 18000c0ec =====

void DelayLoad_GetCodePage
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiGetDC @ 18000c100 =====

void GdiGetDC(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000c100. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc100  1572  GdiGetDC */
  GdiGetDC();
  return;
}



===== DelayLoad_GdiGetDC @ 18000c10c =====

void DelayLoad_GdiGetDC(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiGetDevmodeForPage @ 18000c120 =====

void GdiGetDevmodeForPage(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000c120. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc120  1573  GdiGetDevmodeForPage */
  GdiGetDevmodeForPage();
  return;
}



===== DelayLoad_GdiGetDevmodeForPage @ 18000c12c =====

void DelayLoad_GdiGetDevmodeForPage
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiGetLocalBrush @ 18000c140 =====

void GdiGetLocalBrush(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000c140. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc140  1575  GdiGetLocalBrush */
  GdiGetLocalBrush();
  return;
}



===== DelayLoad_GdiGetLocalBrush @ 18000c14c =====

void DelayLoad_GdiGetLocalBrush
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiGetLocalDC @ 18000c160 =====

void GdiGetLocalDC(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000c160. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc160  1576  GdiGetLocalDC */
  GdiGetLocalDC();
  return;
}



===== DelayLoad_GdiGetLocalDC @ 18000c16c =====

void DelayLoad_GdiGetLocalDC
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiGetLocalFont @ 18000c180 =====

void GdiGetLocalFont(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000c180. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc180  1577  GdiGetLocalFont */
  GdiGetLocalFont();
  return;
}



===== DelayLoad_GdiGetLocalFont @ 18000c18c =====

void DelayLoad_GdiGetLocalFont
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiGetPageCount @ 18000c1a0 =====

void GdiGetPageCount(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000c1a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc1a0  1578  GdiGetPageCount */
  GdiGetPageCount();
  return;
}



===== DelayLoad_GdiGetPageCount @ 18000c1ac =====

void DelayLoad_GdiGetPageCount
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiGetPageHandle @ 18000c1c0 =====

void GdiGetPageHandle(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000c1c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc1c0  1579  GdiGetPageHandle */
  GdiGetPageHandle();
  return;
}



===== DelayLoad_GdiGetPageHandle @ 18000c1cc =====

void DelayLoad_GdiGetPageHandle
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiGetSpoolFileHandle @ 18000c1e0 =====

void GdiGetSpoolFileHandle(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000c1e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc1e0  1580  GdiGetSpoolFileHandle */
  GdiGetSpoolFileHandle();
  return;
}



===== DelayLoad_GdiGetSpoolFileHandle @ 18000c1ec =====

void DelayLoad_GdiGetSpoolFileHandle
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiGetVariationStoreDelta @ 18000c200 =====

void GdiGetVariationStoreDelta(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000c200. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc200  1582  GdiGetVariationStoreDelta */
  GdiGetVariationStoreDelta();
  return;
}



===== DelayLoad_GdiGetVariationStoreDelta @ 18000c20c =====

void DelayLoad_GdiGetVariationStoreDelta
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_1_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiHandleBeingTracked @ 18000c220 =====

void GdiHandleBeingTracked(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000c220. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc220  1584  GdiHandleBeingTracked */
  GdiHandleBeingTracked();
  return;
}



===== DelayLoad_GdiHandleBeingTracked @ 18000c22c =====

void DelayLoad_GdiHandleBeingTracked
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_1_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiInitializeLanguagePack @ 18000c240 =====

void GdiInitializeLanguagePack(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000c240. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc240  1586  GdiInitializeLanguagePack */
  GdiInitializeLanguagePack();
  return;
}



===== DelayLoad_GdiInitializeLanguagePack @ 18000c24c =====

void DelayLoad_GdiInitializeLanguagePack
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiIsMetaFileDC @ 18000c260 =====

void GdiIsMetaFileDC(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000c260. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc260  1587  GdiIsMetaFileDC */
  GdiIsMetaFileDC();
  return;
}



===== DelayLoad_GdiIsMetaFileDC @ 18000c26c =====

void DelayLoad_GdiIsMetaFileDC
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiIsMetaPrintDC @ 18000c280 =====

void GdiIsMetaPrintDC(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000c280. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc280  1588  GdiIsMetaPrintDC */
  GdiIsMetaPrintDC();
  return;
}



===== DelayLoad_GdiIsMetaPrintDC @ 18000c28c =====

void DelayLoad_GdiIsMetaPrintDC
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiIsPlayMetafileDC @ 18000c2a0 =====

void GdiIsPlayMetafileDC(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000c2a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc2a0  1589  GdiIsPlayMetafileDC */
  GdiIsPlayMetafileDC();
  return;
}



===== DelayLoad_GdiIsPlayMetafileDC @ 18000c2ac =====

void DelayLoad_GdiIsPlayMetafileDC
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiIsScreenDC @ 18000c2c0 =====

void GdiIsScreenDC(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000c2c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc2c0  1590  GdiIsScreenDC */
  GdiIsScreenDC();
  return;
}



===== DelayLoad_GdiIsScreenDC @ 18000c2cc =====

void DelayLoad_GdiIsScreenDC
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiIsUMPDSandboxingEnabled @ 18000c2e0 =====

void GdiIsUMPDSandboxingEnabled(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000c2e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc2e0  1591  GdiIsUMPDSandboxingEnabled */
  GdiIsUMPDSandboxingEnabled();
  return;
}



===== DelayLoad_GdiIsUMPDSandboxingEnabled @ 18000c2ec =====

void DelayLoad_GdiIsUMPDSandboxingEnabled
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiLoadType1Fonts @ 18000c300 =====

void GdiLoadType1Fonts(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000c300. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc300  1592  GdiLoadType1Fonts */
  GdiLoadType1Fonts();
  return;
}



===== DelayLoad_GdiLoadType1Fonts @ 18000c30c =====

void DelayLoad_GdiLoadType1Fonts
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiPlayDCScript @ 18000c320 =====

void GdiPlayDCScript(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000c320. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc320  1593  GdiPlayDCScript */
  GdiPlayDCScript();
  return;
}



===== DelayLoad_GdiPlayDCScript @ 18000c32c =====

void DelayLoad_GdiPlayDCScript
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiPlayEMF @ 18000c340 =====

void GdiPlayEMF(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000c340. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc340  1594  GdiPlayEMF */
  GdiPlayEMF();
  return;
}



===== DelayLoad_GdiPlayEMF @ 18000c34c =====

void DelayLoad_GdiPlayEMF
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiPlayJournal @ 18000c360 =====

void GdiPlayJournal(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000c360. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc360  1595  GdiPlayJournal */
  GdiPlayJournal();
  return;
}



===== DelayLoad_GdiPlayJournal @ 18000c36c =====

void DelayLoad_GdiPlayJournal
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiPlayPageEMF @ 18000c380 =====

void GdiPlayPageEMF(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000c380. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc380  1596  GdiPlayPageEMF */
  GdiPlayPageEMF();
  return;
}



===== DelayLoad_GdiPlayPageEMF @ 18000c38c =====

void DelayLoad_GdiPlayPageEMF
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiPlayPrivatePageEMF @ 18000c3a0 =====

void GdiPlayPrivatePageEMF(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000c3a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc3a0  1597  GdiPlayPrivatePageEMF */
  GdiPlayPrivatePageEMF();
  return;
}



===== DelayLoad_GdiPlayPrivatePageEMF @ 18000c3ac =====

void DelayLoad_GdiPlayPrivatePageEMF
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiPlayScript @ 18000c3c0 =====

void GdiPlayScript(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000c3c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc3c0  1598  GdiPlayScript */
  GdiPlayScript();
  return;
}



===== DelayLoad_GdiPlayScript @ 18000c3cc =====

void DelayLoad_GdiPlayScript
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiPrinterThunk @ 18000c3e0 =====

void GdiPrinterThunk(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000c3e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc3e0  1599  GdiPrinterThunk */
  GdiPrinterThunk();
  return;
}



===== DelayLoad_GdiPrinterThunk @ 18000c3ec =====

void DelayLoad_GdiPrinterThunk
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiProcessSetup @ 18000c400 =====

void GdiProcessSetup(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000c400. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc400  1600  GdiProcessSetup */
  GdiProcessSetup();
  return;
}



===== DelayLoad_GdiProcessSetup @ 18000c40c =====

void DelayLoad_GdiProcessSetup
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiQueryTable @ 18000c420 =====

void GdiQueryTable(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000c420. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc420  1602  GdiQueryTable */
  GdiQueryTable();
  return;
}



===== DelayLoad_GdiQueryTable @ 18000c42c =====

void DelayLoad_GdiQueryTable
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiRealizationInfo @ 18000c440 =====

void GdiRealizationInfo(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000c440. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc440  1603  GdiRealizationInfo */
  GdiRealizationInfo();
  return;
}



===== DelayLoad_GdiRealizationInfo @ 18000c44c =====

void DelayLoad_GdiRealizationInfo
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiReleaseLocalDC @ 18000c460 =====

void GdiReleaseLocalDC(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000c460. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc460  1605  GdiReleaseLocalDC */
  GdiReleaseLocalDC();
  return;
}



===== DelayLoad_GdiReleaseLocalDC @ 18000c46c =====

void DelayLoad_GdiReleaseLocalDC
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiResetDCEMF @ 18000c480 =====

void GdiResetDCEMF(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000c480. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc480  1606  GdiResetDCEMF */
  GdiResetDCEMF();
  return;
}



===== DelayLoad_GdiResetDCEMF @ 18000c48c =====

void DelayLoad_GdiResetDCEMF
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiSetAttrs @ 18000c4a0 =====

void GdiSetAttrs(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000c4a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc4a0  1607  GdiSetAttrs */
  GdiSetAttrs();
  return;
}



===== DelayLoad_GdiSetAttrs @ 18000c4ac =====

void DelayLoad_GdiSetAttrs
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiSetBatchLimit @ 18000c4c0 =====

DWORD __stdcall GdiSetBatchLimit(DWORD dw)

{
  DWORD DVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000c4c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc4c0  1608  GdiSetBatchLimit */
  DVar1 = GdiSetBatchLimit(dw);
  return DVar1;
}



===== DelayLoad_GdiSetBatchLimit @ 18000c4cc =====

void DelayLoad_GdiSetBatchLimit
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiSetPixelFormat @ 18000c4e0 =====

void GdiSetPixelFormat(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000c4e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc4e0  1610  GdiSetPixelFormat */
  GdiSetPixelFormat();
  return;
}



===== DelayLoad_GdiSetPixelFormat @ 18000c4ec =====

void DelayLoad_GdiSetPixelFormat
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiSetServerAttr @ 18000c500 =====

void GdiSetServerAttr(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000c500. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc500  1611  GdiSetServerAttr */
  GdiSetServerAttr();
  return;
}



===== DelayLoad_GdiSetServerAttr @ 18000c50c =====

void DelayLoad_GdiSetServerAttr
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiStartDocEMF @ 18000c520 =====

void GdiStartDocEMF(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000c520. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc520  1612  GdiStartDocEMF */
  GdiStartDocEMF();
  return;
}



===== DelayLoad_GdiStartDocEMF @ 18000c52c =====

void DelayLoad_GdiStartDocEMF
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiStartPageEMF @ 18000c540 =====

void GdiStartPageEMF(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000c540. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc540  1613  GdiStartPageEMF */
  GdiStartPageEMF();
  return;
}



===== DelayLoad_GdiStartPageEMF @ 18000c54c =====

void DelayLoad_GdiStartPageEMF
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiSwapBuffers @ 18000c560 =====

void GdiSwapBuffers(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000c560. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc560  1615  GdiSwapBuffers */
  GdiSwapBuffers();
  return;
}



===== DelayLoad_GdiSwapBuffers @ 18000c56c =====

void DelayLoad_GdiSwapBuffers
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiTrackHCreate @ 18000c580 =====

void GdiTrackHCreate(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000c580. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc580  1616  GdiTrackHCreate */
  GdiTrackHCreate();
  return;
}



===== DelayLoad_GdiTrackHCreate @ 18000c58c =====

void DelayLoad_GdiTrackHCreate
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_1_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiTrackHDelete @ 18000c5a0 =====

void GdiTrackHDelete(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000c5a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc5a0  1617  GdiTrackHDelete */
  GdiTrackHDelete();
  return;
}



===== DelayLoad_GdiTrackHDelete @ 18000c5ac =====

void DelayLoad_GdiTrackHDelete
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_1_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiValidateHandle @ 18000c5c0 =====

void GdiValidateHandle(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000c5c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc5c0  1619  GdiValidateHandle */
  GdiValidateHandle();
  return;
}



===== DelayLoad_GdiValidateHandle @ 18000c5cc =====

void DelayLoad_GdiValidateHandle
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GdiWaitForTextReady @ 18000c5e0 =====

void GdiWaitForTextReady(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000c5e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc5e0  1620  GdiWaitForTextReady */
  GdiWaitForTextReady();
  return;
}



===== DelayLoad_GdiWaitForTextReady @ 18000c5ec =====

void DelayLoad_GdiWaitForTextReady
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_4_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GditGetCallerTLStorage @ 18000c600 =====

void GditGetCallerTLStorage(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000c600. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc600  1622  GditGetCallerTLStorage */
  GditGetCallerTLStorage();
  return;
}



===== DelayLoad_GditGetCallerTLStorage @ 18000c60c =====

void DelayLoad_GditGetCallerTLStorage
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_4_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GditPopCallerInfo @ 18000c620 =====

void GditPopCallerInfo(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000c620. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc620  1623  GditPopCallerInfo */
  GditPopCallerInfo();
  return;
}



===== DelayLoad_GditPopCallerInfo @ 18000c62c =====

void DelayLoad_GditPopCallerInfo
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_4_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GditPushCallerInfo @ 18000c640 =====

void GditPushCallerInfo(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000c640. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc640  1624  GditPushCallerInfo */
  GditPushCallerInfo();
  return;
}



===== DelayLoad_GditPushCallerInfo @ 18000c64c =====

void DelayLoad_GditPushCallerInfo
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_4_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetArcDirection @ 18000c660 =====

int __stdcall GetArcDirection(HDC hdc)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000c660. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc660  1625  GetArcDirection */
  iVar1 = GetArcDirection(hdc);
  return iVar1;
}



===== DelayLoad_GetArcDirection @ 18000c66c =====

void DelayLoad_GetArcDirection
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetAspectRatioFilterEx @ 18000c680 =====

BOOL __stdcall GetAspectRatioFilterEx(HDC hdc,LPSIZE lpsize)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000c680. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc680  1626  GetAspectRatioFilterEx */
  BVar1 = GetAspectRatioFilterEx(hdc,lpsize);
  return BVar1;
}



===== DelayLoad_GetAspectRatioFilterEx @ 18000c68c =====

void DelayLoad_GetAspectRatioFilterEx
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetBitmapAttributes @ 18000c6a0 =====

void GetBitmapAttributes(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000c6a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc6a0  1627  GetBitmapAttributes */
  GetBitmapAttributes();
  return;
}



===== DelayLoad_GetBitmapAttributes @ 18000c6ac =====

void DelayLoad_GetBitmapAttributes
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetBitmapDimensionEx @ 18000c6c0 =====

BOOL __stdcall GetBitmapDimensionEx(HBITMAP hbit,LPSIZE lpsize)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000c6c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc6c0  1629  GetBitmapDimensionEx */
  BVar1 = GetBitmapDimensionEx(hbit,lpsize);
  return BVar1;
}



===== DelayLoad_GetBitmapDimensionEx @ 18000c6cc =====

void DelayLoad_GetBitmapDimensionEx
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetBoundsRect @ 18000c6e0 =====

UINT __stdcall GetBoundsRect(HDC hdc,LPRECT lprect,UINT flags)

{
  UINT UVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000c6e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc6e0  1633  GetBoundsRect */
  UVar1 = GetBoundsRect(hdc,lprect,flags);
  return UVar1;
}



===== DelayLoad_GetBoundsRect @ 18000c6ec =====

void DelayLoad_GetBoundsRect
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetBrushAttributes @ 18000c700 =====

void GetBrushAttributes(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000c700. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc700  1634  GetBrushAttributes */
  GetBrushAttributes();
  return;
}



===== DelayLoad_GetBrushAttributes @ 18000c70c =====

void DelayLoad_GetBrushAttributes
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetCharABCWidthsA @ 18000c720 =====

BOOL __stdcall GetCharABCWidthsA(HDC hdc,UINT wFirst,UINT wLast,LPABC lpABC)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000c720. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc720  1641  GetCharABCWidthsA */
  BVar1 = GetCharABCWidthsA(hdc,wFirst,wLast,lpABC);
  return BVar1;
}



===== DelayLoad_GetCharABCWidthsA @ 18000c72c =====

void DelayLoad_GetCharABCWidthsA
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetCharABCWidthsFloatA @ 18000c740 =====

BOOL __stdcall GetCharABCWidthsFloatA(HDC hdc,UINT iFirst,UINT iLast,LPABCFLOAT lpABC)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000c740. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc740  1642  GetCharABCWidthsFloatA */
  BVar1 = GetCharABCWidthsFloatA(hdc,iFirst,iLast,lpABC);
  return BVar1;
}



===== DelayLoad_GetCharABCWidthsFloatA @ 18000c74c =====

void DelayLoad_GetCharABCWidthsFloatA
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetCharABCWidthsFloatI @ 18000c760 =====

void GetCharABCWidthsFloatI(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000c760. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc760  1643  GetCharABCWidthsFloatI */
  GetCharABCWidthsFloatI();
  return;
}



===== DelayLoad_GetCharABCWidthsFloatI @ 18000c76c =====

void DelayLoad_GetCharABCWidthsFloatI
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetCharABCWidthsFloatW @ 18000c780 =====

BOOL __stdcall GetCharABCWidthsFloatW(HDC hdc,UINT iFirst,UINT iLast,LPABCFLOAT lpABC)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000c780. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc780  1644  GetCharABCWidthsFloatW */
  BVar1 = GetCharABCWidthsFloatW(hdc,iFirst,iLast,lpABC);
  return BVar1;
}



===== DelayLoad_GetCharABCWidthsFloatW @ 18000c78c =====

void DelayLoad_GetCharABCWidthsFloatW
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetCharABCWidthsI @ 18000c7a0 =====

BOOL __stdcall GetCharABCWidthsI(HDC hdc,UINT giFirst,UINT cgi,LPWORD pgi,LPABC pabc)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000c7a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc7a0  1645  GetCharABCWidthsI */
  BVar1 = GetCharABCWidthsI(hdc,giFirst,cgi,pgi,pabc);
  return BVar1;
}



===== DelayLoad_GetCharABCWidthsI @ 18000c7ac =====

void DelayLoad_GetCharABCWidthsI
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetCharWidth32W @ 18000c7c0 =====

BOOL __stdcall GetCharWidth32W(HDC hdc,UINT iFirst,UINT iLast,LPINT lpBuffer)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000c7c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc7c0  1648  GetCharWidth32W */
  BVar1 = GetCharWidth32W(hdc,iFirst,iLast,lpBuffer);
  return BVar1;
}



===== DelayLoad_GetCharWidth32W @ 18000c7cc =====

void DelayLoad_GetCharWidth32W
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetCharWidthFloatA @ 18000c7e0 =====

BOOL __stdcall GetCharWidthFloatA(HDC hdc,UINT iFirst,UINT iLast,PFLOAT lpBuffer)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000c7e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc7e0  1650  GetCharWidthFloatA */
  BVar1 = GetCharWidthFloatA(hdc,iFirst,iLast,lpBuffer);
  return BVar1;
}



===== DelayLoad_GetCharWidthFloatA @ 18000c7ec =====

void DelayLoad_GetCharWidthFloatA
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetCharWidthFloatW @ 18000c800 =====

BOOL __stdcall GetCharWidthFloatW(HDC hdc,UINT iFirst,UINT iLast,PFLOAT lpBuffer)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000c800. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc800  1651  GetCharWidthFloatW */
  BVar1 = GetCharWidthFloatW(hdc,iFirst,iLast,lpBuffer);
  return BVar1;
}



===== DelayLoad_GetCharWidthFloatW @ 18000c80c =====

void DelayLoad_GetCharWidthFloatW
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetCharWidthI @ 18000c820 =====

BOOL __stdcall GetCharWidthI(HDC hdc,UINT giFirst,UINT cgi,LPWORD pgi,LPINT piWidths)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000c820. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc820  1652  GetCharWidthI */
  BVar1 = GetCharWidthI(hdc,giFirst,cgi,pgi,piWidths);
  return BVar1;
}



===== DelayLoad_GetCharWidthI @ 18000c82c =====

void DelayLoad_GetCharWidthI
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetCharacterPlacementA @ 18000c840 =====

DWORD __stdcall
GetCharacterPlacementA
          (HDC hdc,LPCSTR lpString,int nCount,int nMexExtent,LPGCP_RESULTSA lpResults,DWORD dwFlags)

{
  DWORD DVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000c840. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc840  1655  GetCharacterPlacementA */
  DVar1 = GetCharacterPlacementA(hdc,lpString,nCount,nMexExtent,lpResults,dwFlags);
  return DVar1;
}



===== DelayLoad_GetCharacterPlacementA @ 18000c84c =====

void DelayLoad_GetCharacterPlacementA
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetCharacterPlacementW @ 18000c860 =====

DWORD __stdcall
GetCharacterPlacementW
          (HDC hdc,LPCWSTR lpString,int nCount,int nMexExtent,LPGCP_RESULTSW lpResults,DWORD dwFlags
          )

{
  DWORD DVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000c860. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc860  1656  GetCharacterPlacementW */
  DVar1 = GetCharacterPlacementW(hdc,lpString,nCount,nMexExtent,lpResults,dwFlags);
  return DVar1;
}



===== DelayLoad_GetCharacterPlacementW @ 18000c86c =====

void DelayLoad_GetCharacterPlacementW
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetColorAdjustment @ 18000c880 =====

BOOL __stdcall GetColorAdjustment(HDC hdc,LPCOLORADJUSTMENT lpca)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000c880. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc880  1659  GetColorAdjustment */
  BVar1 = GetColorAdjustment(hdc,lpca);
  return BVar1;
}



===== DelayLoad_GetColorAdjustment @ 18000c88c =====

void DelayLoad_GetColorAdjustment
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetColorSpace @ 18000c8a0 =====

HCOLORSPACE __stdcall GetColorSpace(HDC hdc)

{
  HCOLORSPACE pHVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000c8a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc8a0  1660  GetColorSpace */
  pHVar1 = GetColorSpace(hdc);
  return pHVar1;
}



===== DelayLoad_GetColorSpace @ 18000c8ac =====

void DelayLoad_GetColorSpace
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetDCDpiScaleValue @ 18000c8c0 =====

void GetDCDpiScaleValue(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000c8c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc8c0  1665  GetDCDpiScaleValue */
  GetDCDpiScaleValue();
  return;
}



===== DelayLoad_GetDCDpiScaleValue @ 18000c8cc =====

void DelayLoad_GetDCDpiScaleValue
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetDCPenColor @ 18000c8e0 =====

COLORREF __stdcall GetDCPenColor(HDC hdc)

{
  COLORREF CVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000c8e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc8e0  1667  GetDCPenColor */
  CVar1 = GetDCPenColor(hdc);
  return CVar1;
}



===== DelayLoad_GetDCPenColor @ 18000c8ec =====

void DelayLoad_GetDCPenColor
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetDeviceGammaRamp @ 18000c900 =====

BOOL __stdcall GetDeviceGammaRamp(HDC hdc,LPVOID lpRamp)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000c900. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc900  1671  GetDeviceGammaRamp */
  BVar1 = GetDeviceGammaRamp(hdc,lpRamp);
  return BVar1;
}



===== DelayLoad_GetDeviceGammaRamp @ 18000c90c =====

void DelayLoad_GetDeviceGammaRamp
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetETM @ 18000c920 =====

void GetETM(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000c920. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc920  1672  GetETM */
  GetETM();
  return;
}



===== DelayLoad_GetETM @ 18000c92c =====

void DelayLoad_GetETM(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetEUDCTimeStamp @ 18000c940 =====

void GetEUDCTimeStamp(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000c940. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc940  1673  GetEUDCTimeStamp */
  GetEUDCTimeStamp();
  return;
}



===== DelayLoad_GetEUDCTimeStamp @ 18000c94c =====

void DelayLoad_GetEUDCTimeStamp
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetEUDCTimeStampExW @ 18000c960 =====

void GetEUDCTimeStampExW(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000c960. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc960  1674  GetEUDCTimeStampExW */
  GetEUDCTimeStampExW();
  return;
}



===== DelayLoad_GetEUDCTimeStampExW @ 18000c96c =====

void DelayLoad_GetEUDCTimeStampExW
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetEnhMetaFileDescriptionW @ 18000c980 =====

UINT __stdcall GetEnhMetaFileDescriptionW(HENHMETAFILE hemf,UINT cchBuffer,LPWSTR lpDescription)

{
  UINT UVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000c980. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc980  1678  GetEnhMetaFileDescriptionW */
  UVar1 = GetEnhMetaFileDescriptionW(hemf,cchBuffer,lpDescription);
  return UVar1;
}



===== DelayLoad_GetEnhMetaFileDescriptionW @ 18000c98c =====

void DelayLoad_GetEnhMetaFileDescriptionW
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetEnhMetaFilePixelFormat @ 18000c9a0 =====

UINT __stdcall
GetEnhMetaFilePixelFormat(HENHMETAFILE hemf,UINT cbBuffer,PIXELFORMATDESCRIPTOR *ppfd)

{
  UINT UVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000c9a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc9a0  1681  GetEnhMetaFilePixelFormat */
  UVar1 = GetEnhMetaFilePixelFormat(hemf,cbBuffer,ppfd);
  return UVar1;
}



===== DelayLoad_GetEnhMetaFilePixelFormat @ 18000c9ac =====

void DelayLoad_GetEnhMetaFilePixelFormat
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetFontAssocStatus @ 18000c9c0 =====

void GetFontAssocStatus(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000c9c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc9c0  1683  GetFontAssocStatus */
  GetFontAssocStatus();
  return;
}



===== DelayLoad_GetFontAssocStatus @ 18000c9cc =====

void DelayLoad_GetFontAssocStatus
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetFontLanguageInfo @ 18000c9e0 =====

DWORD __stdcall GetFontLanguageInfo(HDC hdc)

{
  DWORD DVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000c9e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xc9e0  1687  GetFontLanguageInfo */
  DVar1 = GetFontLanguageInfo(hdc);
  return DVar1;
}



===== DelayLoad_GetFontLanguageInfo @ 18000c9ec =====

void DelayLoad_GetFontLanguageInfo
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetFontResourceInfoW @ 18000ca00 =====

void GetFontResourceInfoW(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000ca00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xca00  1689  GetFontResourceInfoW */
  GetFontResourceInfoW();
  return;
}



===== DelayLoad_GetFontResourceInfoW @ 18000ca0c =====

void DelayLoad_GetFontResourceInfoW
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetGlyphIndicesA @ 18000ca20 =====

DWORD __stdcall GetGlyphIndicesA(HDC hdc,LPCSTR lpstr,int c,LPWORD pgi,DWORD fl)

{
  DWORD DVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000ca20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xca20  1691  GetGlyphIndicesA */
  DVar1 = GetGlyphIndicesA(hdc,lpstr,c,pgi,fl);
  return DVar1;
}



===== DelayLoad_GetGlyphIndicesA @ 18000ca2c =====

void DelayLoad_GetGlyphIndicesA
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetGlyphOutlineWow @ 18000ca40 =====

void GetGlyphOutlineWow(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000ca40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xca40  1696  GetGlyphOutlineWow */
  GetGlyphOutlineWow();
  return;
}



===== DelayLoad_GetGlyphOutlineWow @ 18000ca4c =====

void DelayLoad_GetGlyphOutlineWow
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetGraphicsMode @ 18000ca60 =====

int __stdcall GetGraphicsMode(HDC hdc)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000ca60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xca60  1697  GetGraphicsMode */
  iVar1 = GetGraphicsMode(hdc);
  return iVar1;
}



===== DelayLoad_GetGraphicsMode @ 18000ca6c =====

void DelayLoad_GetGraphicsMode
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetHFONT @ 18000ca80 =====

void GetHFONT(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000ca80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xca80  1698  GetHFONT */
  GetHFONT();
  return;
}



===== DelayLoad_GetHFONT @ 18000ca8c =====

void DelayLoad_GetHFONT(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetICMProfileA @ 18000caa0 =====

BOOL __stdcall GetICMProfileA(HDC hdc,LPDWORD pBufSize,LPSTR pszFilename)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000caa0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xcaa0  1699  GetICMProfileA */
  BVar1 = GetICMProfileA(hdc,pBufSize,pszFilename);
  return BVar1;
}



===== DelayLoad_GetICMProfileA @ 18000caac =====

void DelayLoad_GetICMProfileA
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetICMProfileW @ 18000cac0 =====

BOOL __stdcall GetICMProfileW(HDC hdc,LPDWORD pBufSize,LPWSTR pszFilename)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000cac0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xcac0  1700  GetICMProfileW */
  BVar1 = GetICMProfileW(hdc,pBufSize,pszFilename);
  return BVar1;
}



===== DelayLoad_GetICMProfileW @ 18000cacc =====

void DelayLoad_GetICMProfileW
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetLogColorSpaceA @ 18000cae0 =====

BOOL __stdcall GetLogColorSpaceA(HCOLORSPACE hColorSpace,LPLOGCOLORSPACEA lpBuffer,DWORD nSize)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000cae0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xcae0  1705  GetLogColorSpaceA */
  BVar1 = GetLogColorSpaceA(hColorSpace,lpBuffer,nSize);
  return BVar1;
}



===== DelayLoad_GetLogColorSpaceA @ 18000caec =====

void DelayLoad_GetLogColorSpaceA
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetLogColorSpaceW @ 18000cb00 =====

BOOL __stdcall GetLogColorSpaceW(HCOLORSPACE hColorSpace,LPLOGCOLORSPACEW lpBuffer,DWORD nSize)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000cb00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xcb00  1706  GetLogColorSpaceW */
  BVar1 = GetLogColorSpaceW(hColorSpace,lpBuffer,nSize);
  return BVar1;
}



===== DelayLoad_GetLogColorSpaceW @ 18000cb0c =====

void DelayLoad_GetLogColorSpaceW
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetMetaFileA @ 18000cb20 =====

HMETAFILE __stdcall GetMetaFileA(LPCSTR lpName)

{
  HMETAFILE pHVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000cb20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xcb20  1708  GetMetaFileA */
  pHVar1 = GetMetaFileA(lpName);
  return pHVar1;
}



===== DelayLoad_GetMetaFileA @ 18000cb2c =====

void DelayLoad_GetMetaFileA
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetMetaFileW @ 18000cb40 =====

HMETAFILE __stdcall GetMetaFileW(LPCWSTR lpName)

{
  HMETAFILE pHVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000cb40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xcb40  1710  GetMetaFileW */
  pHVar1 = GetMetaFileW(lpName);
  return pHVar1;
}



===== DelayLoad_GetMetaFileW @ 18000cb4c =====

void DelayLoad_GetMetaFileW
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetMetaRgn @ 18000cb60 =====

int __stdcall GetMetaRgn(HDC hdc,HRGN hrgn)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000cb60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xcb60  1711  GetMetaRgn */
  iVar1 = GetMetaRgn(hdc,hrgn);
  return iVar1;
}



===== DelayLoad_GetMetaRgn @ 18000cb6c =====

void DelayLoad_GetMetaRgn
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetMiterLimit @ 18000cb80 =====

BOOL __stdcall GetMiterLimit(HDC hdc,PFLOAT plimit)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000cb80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xcb80  1712  GetMiterLimit */
  BVar1 = GetMiterLimit(hdc,plimit);
  return BVar1;
}



===== DelayLoad_GetMiterLimit @ 18000cb8c =====

void DelayLoad_GetMiterLimit
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetNearestColor @ 18000cba0 =====

COLORREF __stdcall GetNearestColor(HDC hdc,COLORREF color)

{
  COLORREF CVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000cba0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xcba0  1713  GetNearestColor */
  CVar1 = GetNearestColor(hdc,color);
  return CVar1;
}



===== DelayLoad_GetNearestColor @ 18000cbac =====

void DelayLoad_GetNearestColor
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetPath @ 18000cbc0 =====

int __stdcall GetPath(HDC hdc,LPPOINT apt,LPBYTE aj,int cpt)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000cbc0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xcbc0  1724  GetPath */
  iVar1 = GetPath(hdc,apt,aj,cpt);
  return iVar1;
}



===== DelayLoad_GetPath @ 18000cbcc =====

void DelayLoad_GetPath(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetPixelFormat @ 18000cbe0 =====

int __stdcall GetPixelFormat(HDC hdc)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000cbe0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xcbe0  1729  GetPixelFormat */
  iVar1 = GetPixelFormat(hdc);
  return iVar1;
}



===== DelayLoad_GetPixelFormat @ 18000cbec =====

void DelayLoad_GetPixelFormat
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetPolyFillMode @ 18000cc00 =====

int __stdcall GetPolyFillMode(HDC hdc)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000cc00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xcc00  1730  GetPolyFillMode */
  iVar1 = GetPolyFillMode(hdc);
  return iVar1;
}



===== DelayLoad_GetPolyFillMode @ 18000cc0c =====

void DelayLoad_GetPolyFillMode
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetRelAbs @ 18000cc20 =====

void GetRelAbs(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000cc20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xcc20  1736  GetRelAbs */
  GetRelAbs();
  return;
}



===== DelayLoad_GetRelAbs @ 18000cc2c =====

void DelayLoad_GetRelAbs(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4
                        )

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetStretchBltMode @ 18000cc40 =====

int __stdcall GetStretchBltMode(HDC hdc)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000cc40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xcc40  1739  GetStretchBltMode */
  iVar1 = GetStretchBltMode(hdc);
  return iVar1;
}



===== DelayLoad_GetStretchBltMode @ 18000cc4c =====

void DelayLoad_GetStretchBltMode
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetStringBitmapA @ 18000cc60 =====

void GetStringBitmapA(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000cc60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xcc60  1740  GetStringBitmapA */
  GetStringBitmapA();
  return;
}



===== DelayLoad_GetStringBitmapA @ 18000cc6c =====

void DelayLoad_GetStringBitmapA
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetSystemPaletteUse @ 18000cc80 =====

UINT __stdcall GetSystemPaletteUse(HDC hdc)

{
  UINT UVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000cc80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xcc80  1744  GetSystemPaletteUse */
  UVar1 = GetSystemPaletteUse(hdc);
  return UVar1;
}



===== DelayLoad_GetSystemPaletteUse @ 18000cc8c =====

void DelayLoad_GetSystemPaletteUse
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetTextExtentExPointWPri @ 18000cca0 =====

void GetTextExtentExPointWPri(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000cca0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xcca0  1753  GetTextExtentExPointWPri */
  GetTextExtentExPointWPri();
  return;
}



===== DelayLoad_GetTextExtentExPointWPri @ 18000ccac =====

void DelayLoad_GetTextExtentExPointWPri
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetTextFaceAliasW @ 18000ccc0 =====

void GetTextFaceAliasW(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000ccc0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xccc0  1760  GetTextFaceAliasW */
  GetTextFaceAliasW();
  return;
}



===== DelayLoad_GetTextFaceAliasW @ 18000cccc =====

void DelayLoad_GetTextFaceAliasW
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetTransform @ 18000cce0 =====

void GetTransform(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000cce0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xcce0  1764  GetTransform */
  GetTransform();
  return;
}



===== DelayLoad_GetTransform @ 18000ccec =====

void DelayLoad_GetTransform
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== GetViewportExtEx @ 18000cd00 =====

BOOL __stdcall GetViewportExtEx(HDC hdc,LPSIZE lpsize)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000cd00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xcd00  1765  GetViewportExtEx */
  BVar1 = GetViewportExtEx(hdc,lpsize);
  return BVar1;
}



===== DelayLoad_GetViewportExtEx @ 18000cd0c =====

void DelayLoad_GetViewportExtEx
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== IsValidEnhMetaRecord @ 18000cd20 =====

void IsValidEnhMetaRecord(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000cd20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xcd20  1777  IsValidEnhMetaRecord */
  IsValidEnhMetaRecord();
  return;
}



===== DelayLoad_IsValidEnhMetaRecord @ 18000cd2c =====

void DelayLoad_IsValidEnhMetaRecord
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== IsValidEnhMetaRecordOffExt @ 18000cd40 =====

void IsValidEnhMetaRecordOffExt(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000cd40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xcd40  1778  IsValidEnhMetaRecordOffExt */
  IsValidEnhMetaRecordOffExt();
  return;
}



===== DelayLoad_IsValidEnhMetaRecordOffExt @ 18000cd4c =====

void DelayLoad_IsValidEnhMetaRecordOffExt
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== LineDDA @ 18000cd60 =====

BOOL __stdcall LineDDA(int xStart,int yStart,int xEnd,int yEnd,LINEDDAPROC lpProc,LPARAM data)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000cd60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xcd60  1780  LineDDA */
  BVar1 = LineDDA(xStart,yStart,xEnd,yEnd,lpProc,data);
  return BVar1;
}



===== DelayLoad_LineDDA @ 18000cd6c =====

void DelayLoad_LineDDA(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== MaskBlt @ 18000cd80 =====

BOOL __stdcall
MaskBlt(HDC hdcDest,int xDest,int yDest,int width,int height,HDC hdcSrc,int xSrc,int ySrc,
       HBITMAP hbmMask,int xMask,int yMask,DWORD rop)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000cd80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xcd80  1795  MaskBlt */
  BVar1 = MaskBlt(hdcDest,xDest,yDest,width,height,hdcSrc,xSrc,ySrc,hbmMask,xMask,yMask,rop);
  return BVar1;
}



===== DelayLoad_MaskBlt @ 18000cd8c =====

void DelayLoad_MaskBlt(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== MirrorRgn @ 18000cda0 =====

void MirrorRgn(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000cda0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xcda0  1796  MirrorRgn */
  MirrorRgn();
  return;
}



===== DelayLoad_MirrorRgn @ 18000cdac =====

void DelayLoad_MirrorRgn(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4
                        )

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== ModifyWorldTransform @ 18000cdc0 =====

BOOL __stdcall ModifyWorldTransform(HDC hdc,XFORM *lpxf,DWORD mode)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000cdc0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xcdc0  1800  ModifyWorldTransform */
  BVar1 = ModifyWorldTransform(hdc,lpxf,mode);
  return BVar1;
}



===== DelayLoad_ModifyWorldTransform @ 18000cdcc =====

void DelayLoad_ModifyWorldTransform
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== NamedEscape @ 18000cde0 =====

void NamedEscape(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000cde0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xcde0  1802  NamedEscape */
  NamedEscape();
  return;
}



===== DelayLoad_NamedEscape @ 18000cdec =====

void DelayLoad_NamedEscape
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== OffsetClipRgn @ 18000ce00 =====

int __stdcall OffsetClipRgn(HDC hdc,int x,int y)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000ce00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xce00  1803  OffsetClipRgn */
  iVar1 = OffsetClipRgn(hdc,x,y);
  return iVar1;
}



===== DelayLoad_OffsetClipRgn @ 18000ce0c =====

void DelayLoad_OffsetClipRgn
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== PaintRgn @ 18000ce20 =====

BOOL __stdcall PaintRgn(HDC hdc,HRGN hrgn)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000ce20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xce20  1812  PaintRgn */
  BVar1 = PaintRgn(hdc,hrgn);
  return BVar1;
}



===== DelayLoad_PaintRgn @ 18000ce2c =====

void DelayLoad_PaintRgn(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== PlayEnhMetaFileRecord @ 18000ce40 =====

BOOL __stdcall PlayEnhMetaFileRecord(HDC hdc,LPHANDLETABLE pht,ENHMETARECORD *pmr,UINT cht)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000ce40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xce40  1817  PlayEnhMetaFileRecord */
  BVar1 = PlayEnhMetaFileRecord(hdc,pht,pmr,cht);
  return BVar1;
}



===== DelayLoad_PlayEnhMetaFileRecord @ 18000ce4c =====

void DelayLoad_PlayEnhMetaFileRecord
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== PlayMetaFileRecord @ 18000ce60 =====

BOOL __stdcall PlayMetaFileRecord(HDC hdc,LPHANDLETABLE lpHandleTable,LPMETARECORD lpMR,UINT noObjs)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000ce60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xce60  1819  PlayMetaFileRecord */
  BVar1 = PlayMetaFileRecord(hdc,lpHandleTable,lpMR,noObjs);
  return BVar1;
}



===== DelayLoad_PlayMetaFileRecord @ 18000ce6c =====

void DelayLoad_PlayMetaFileRecord
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== PolyPatBlt @ 18000ce80 =====

void PolyPatBlt(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000ce80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xce80  1824  PolyPatBlt */
  PolyPatBlt();
  return;
}



===== DelayLoad_PolyPatBlt @ 18000ce8c =====

void DelayLoad_PolyPatBlt
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== PolyPolyline @ 18000cea0 =====

BOOL __stdcall PolyPolyline(HDC hdc,POINT *apt,DWORD *asz,DWORD csz)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000cea0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xcea0  1826  PolyPolyline */
  BVar1 = PolyPolyline(hdc,apt,asz,csz);
  return BVar1;
}



===== DelayLoad_PolyPolyline @ 18000ceac =====

void DelayLoad_PolyPolyline
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== PolyTextOutA @ 18000cec0 =====

BOOL __stdcall PolyTextOutA(HDC hdc,POLYTEXTA *ppt,int nstrings)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000cec0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xcec0  1827  PolyTextOutA */
  BVar1 = PolyTextOutA(hdc,ppt,nstrings);
  return BVar1;
}



===== DelayLoad_PolyTextOutA @ 18000cecc =====

void DelayLoad_PolyTextOutA
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== PolyTextOutW @ 18000cee0 =====

BOOL __stdcall PolyTextOutW(HDC hdc,POLYTEXTW *ppt,int nstrings)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000cee0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xcee0  1828  PolyTextOutW */
  BVar1 = PolyTextOutW(hdc,ppt,nstrings);
  return BVar1;
}



===== DelayLoad_PolyTextOutW @ 18000ceec =====

void DelayLoad_PolyTextOutW
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== PtVisible @ 18000cf00 =====

BOOL __stdcall PtVisible(HDC hdc,int x,int y)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000cf00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xcf00  1833  PtVisible */
  BVar1 = PtVisible(hdc,x,y);
  return BVar1;
}



===== DelayLoad_PtVisible @ 18000cf0c =====

void DelayLoad_PtVisible(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4
                        )

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== QueryFontAssocStatus @ 18000cf20 =====

void QueryFontAssocStatus(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000cf20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xcf20  1834  QueryFontAssocStatus */
  QueryFontAssocStatus();
  return;
}



===== DelayLoad_QueryFontAssocStatus @ 18000cf2c =====

void DelayLoad_QueryFontAssocStatus
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== RemoveFontResourceExA @ 18000cf40 =====

BOOL __stdcall RemoveFontResourceExA(LPCSTR name,DWORD fl,PVOID pdv)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000cf40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xcf40  1841  RemoveFontResourceExA */
  BVar1 = RemoveFontResourceExA(name,fl,pdv);
  return BVar1;
}



===== DelayLoad_RemoveFontResourceExA @ 18000cf4c =====

void DelayLoad_RemoveFontResourceExA
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== RemoveFontResourceExW @ 18000cf60 =====

BOOL __stdcall RemoveFontResourceExW(LPCWSTR name,DWORD fl,PVOID pdv)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000cf60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xcf60  1842  RemoveFontResourceExW */
  BVar1 = RemoveFontResourceExW(name,fl,pdv);
  return BVar1;
}



===== DelayLoad_RemoveFontResourceExW @ 18000cf6c =====

void DelayLoad_RemoveFontResourceExW
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== RemoveFontResourceTracking @ 18000cf80 =====

void RemoveFontResourceTracking(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000cf80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xcf80  1843  RemoveFontResourceTracking */
  RemoveFontResourceTracking();
  return;
}



===== DelayLoad_RemoveFontResourceTracking @ 18000cf8c =====

void DelayLoad_RemoveFontResourceTracking
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== ResetDCA @ 18000cfa0 =====

HDC __stdcall ResetDCA(HDC hdc,DEVMODEA *lpdm)

{
  HDC pHVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000cfa0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xcfa0  1845  ResetDCA */
  pHVar1 = ResetDCA(hdc,lpdm);
  return pHVar1;
}



===== DelayLoad_ResetDCA @ 18000cfac =====

void DelayLoad_ResetDCA(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== ScaleViewportExtEx @ 18000cfc0 =====

BOOL __stdcall ScaleViewportExtEx(HDC hdc,int xn,int dx,int yn,int yd,LPSIZE lpsz)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000cfc0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xcfc0  1858  ScaleViewportExtEx */
  BVar1 = ScaleViewportExtEx(hdc,xn,dx,yn,yd,lpsz);
  return BVar1;
}



===== DelayLoad_ScaleViewportExtEx @ 18000cfcc =====

void DelayLoad_ScaleViewportExtEx
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== ScaleWindowExtEx @ 18000cfe0 =====

BOOL __stdcall ScaleWindowExtEx(HDC hdc,int xn,int xd,int yn,int yd,LPSIZE lpsz)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000cfe0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xcfe0  1859  ScaleWindowExtEx */
  BVar1 = ScaleWindowExtEx(hdc,xn,xd,yn,yd,lpsz);
  return BVar1;
}



===== DelayLoad_ScaleWindowExtEx @ 18000cfec =====

void DelayLoad_ScaleWindowExtEx
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== SelectBrushLocal @ 18000d000 =====

void SelectBrushLocal(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000d000. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xd000  1900  SelectBrushLocal */
  SelectBrushLocal();
  return;
}



===== DelayLoad_SelectBrushLocal @ 18000d00c =====

void DelayLoad_SelectBrushLocal
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== SelectFontLocal @ 18000d020 =====

void SelectFontLocal(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000d020. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xd020  1903  SelectFontLocal */
  SelectFontLocal();
  return;
}



===== DelayLoad_SelectFontLocal @ 18000d02c =====

void DelayLoad_SelectFontLocal
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== SetAbortProc @ 18000d040 =====

int __stdcall SetAbortProc(HDC hdc,ABORTPROC proc)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000d040. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xd040  1906  SetAbortProc */
  iVar1 = SetAbortProc(hdc,proc);
  return iVar1;
}



===== DelayLoad_SetAbortProc @ 18000d04c =====

void DelayLoad_SetAbortProc
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== SetArcDirection @ 18000d060 =====

int __stdcall SetArcDirection(HDC hdc,int dir)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000d060. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xd060  1907  SetArcDirection */
  iVar1 = SetArcDirection(hdc,dir);
  return iVar1;
}



===== DelayLoad_SetArcDirection @ 18000d06c =====

void DelayLoad_SetArcDirection
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== SetBitmapAttributes @ 18000d080 =====

void SetBitmapAttributes(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000d080. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xd080  1908  SetBitmapAttributes */
  SetBitmapAttributes();
  return;
}



===== DelayLoad_SetBitmapAttributes @ 18000d08c =====

void DelayLoad_SetBitmapAttributes
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== SetBitmapDimensionEx @ 18000d0a0 =====

BOOL __stdcall SetBitmapDimensionEx(HBITMAP hbm,int w,int h,LPSIZE lpsz)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000d0a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xd0a0  1910  SetBitmapDimensionEx */
  BVar1 = SetBitmapDimensionEx(hbm,w,h,lpsz);
  return BVar1;
}



===== DelayLoad_SetBitmapDimensionEx @ 18000d0ac =====

void DelayLoad_SetBitmapDimensionEx
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== SetBoundsRect @ 18000d0c0 =====

UINT __stdcall SetBoundsRect(HDC hdc,RECT *lprect,UINT flags)

{
  UINT UVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000d0c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xd0c0  1913  SetBoundsRect */
  UVar1 = SetBoundsRect(hdc,lprect,flags);
  return UVar1;
}



===== DelayLoad_SetBoundsRect @ 18000d0cc =====

void DelayLoad_SetBoundsRect
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== SetBrushAttributes @ 18000d0e0 =====

void SetBrushAttributes(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000d0e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xd0e0  1914  SetBrushAttributes */
  SetBrushAttributes();
  return;
}



===== DelayLoad_SetBrushAttributes @ 18000d0ec =====

void DelayLoad_SetBrushAttributes
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== SetColorAdjustment @ 18000d100 =====

BOOL __stdcall SetColorAdjustment(HDC hdc,COLORADJUSTMENT *lpca)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000d100. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xd100  1916  SetColorAdjustment */
  BVar1 = SetColorAdjustment(hdc,lpca);
  return BVar1;
}



===== DelayLoad_SetColorAdjustment @ 18000d10c =====

void DelayLoad_SetColorAdjustment
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== SetColorSpace @ 18000d120 =====

HCOLORSPACE __stdcall SetColorSpace(HDC hdc,HCOLORSPACE hcs)

{
  HCOLORSPACE pHVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000d120. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xd120  1917  SetColorSpace */
  pHVar1 = SetColorSpace(hdc,hcs);
  return pHVar1;
}



===== DelayLoad_SetColorSpace @ 18000d12c =====

void DelayLoad_SetColorSpace
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== SetDCPenColor @ 18000d140 =====

COLORREF __stdcall SetDCPenColor(HDC hdc,COLORREF color)

{
  COLORREF CVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000d140. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xd140  1919  SetDCPenColor */
  CVar1 = SetDCPenColor(hdc,color);
  return CVar1;
}



===== DelayLoad_SetDCPenColor @ 18000d14c =====

void DelayLoad_SetDCPenColor
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== SetFontEnumeration @ 18000d160 =====

void SetFontEnumeration(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000d160. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xd160  1925  SetFontEnumeration */
  SetFontEnumeration();
  return;
}



===== DelayLoad_SetFontEnumeration @ 18000d16c =====

void DelayLoad_SetFontEnumeration
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== SetICMProfileA @ 18000d180 =====

BOOL __stdcall SetICMProfileA(HDC hdc,LPSTR lpFileName)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000d180. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xd180  1928  SetICMProfileA */
  BVar1 = SetICMProfileA(hdc,lpFileName);
  return BVar1;
}



===== DelayLoad_SetICMProfileA @ 18000d18c =====

void DelayLoad_SetICMProfileA
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== SetICMProfileW @ 18000d1a0 =====

BOOL __stdcall SetICMProfileW(HDC hdc,LPWSTR lpFileName)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000d1a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xd1a0  1929  SetICMProfileW */
  BVar1 = SetICMProfileW(hdc,lpFileName);
  return BVar1;
}



===== DelayLoad_SetICMProfileW @ 18000d1ac =====

void DelayLoad_SetICMProfileW
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== SetLayoutWidth @ 18000d1c0 =====

void SetLayoutWidth(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000d1c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xd1c0  1931  SetLayoutWidth */
  SetLayoutWidth();
  return;
}



===== DelayLoad_SetLayoutWidth @ 18000d1cc =====

void DelayLoad_SetLayoutWidth
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== SetMapperFlags @ 18000d1e0 =====

DWORD __stdcall SetMapperFlags(HDC hdc,DWORD flags)

{
  DWORD DVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000d1e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xd1e0  1934  SetMapperFlags */
  DVar1 = SetMapperFlags(hdc,flags);
  return DVar1;
}



===== DelayLoad_SetMapperFlags @ 18000d1ec =====

void DelayLoad_SetMapperFlags
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== SetPixelV @ 18000d200 =====

BOOL __stdcall SetPixelV(HDC hdc,int x,int y,COLORREF color)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000d200. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xd200  1942  SetPixelV */
  BVar1 = SetPixelV(hdc,x,y,color);
  return BVar1;
}



===== DelayLoad_SetPixelV @ 18000d20c =====

void DelayLoad_SetPixelV(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4
                        )

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== SetRelAbs @ 18000d220 =====

void SetRelAbs(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000d220. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xd220  1946  SetRelAbs */
  SetRelAbs();
  return;
}



===== DelayLoad_SetRelAbs @ 18000d22c =====

void DelayLoad_SetRelAbs(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4
                        )

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== SetSystemPaletteUse @ 18000d240 =====

UINT __stdcall SetSystemPaletteUse(HDC hdc,UINT use)

{
  UINT UVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000d240. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xd240  1948  SetSystemPaletteUse */
  UVar1 = SetSystemPaletteUse(hdc,use);
  return UVar1;
}



===== DelayLoad_SetSystemPaletteUse @ 18000d24c =====

void DelayLoad_SetSystemPaletteUse
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== SetTextJustification @ 18000d260 =====

BOOL __stdcall SetTextJustification(HDC hdc,int extra,int count)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000d260. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xd260  1952  SetTextJustification */
  BVar1 = SetTextJustification(hdc,extra,count);
  return BVar1;
}



===== DelayLoad_SetTextJustification @ 18000d26c =====

void DelayLoad_SetTextJustification
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== SetVirtualResolution @ 18000d280 =====

void SetVirtualResolution(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000d280. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xd280  1955  SetVirtualResolution */
  SetVirtualResolution();
  return;
}



===== DelayLoad_SetVirtualResolution @ 18000d28c =====

void DelayLoad_SetVirtualResolution
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== SetWinMetaFileBits @ 18000d2a0 =====

HENHMETAFILE __stdcall
SetWinMetaFileBits(UINT nSize,BYTE *lpMeta16Data,HDC hdcRef,METAFILEPICT *lpMFP)

{
  HENHMETAFILE pHVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000d2a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xd2a0  1956  SetWinMetaFileBits */
  pHVar1 = SetWinMetaFileBits(nSize,lpMeta16Data,hdcRef,lpMFP);
  return pHVar1;
}



===== DelayLoad_SetWinMetaFileBits @ 18000d2ac =====

void DelayLoad_SetWinMetaFileBits
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== StartFormPage @ 18000d2c0 =====

void StartFormPage(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000d2c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xd2c0  1962  StartFormPage */
  StartFormPage();
  return;
}



===== DelayLoad_StartFormPage @ 18000d2cc =====

void DelayLoad_StartFormPage
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== StrokeAndFillPath @ 18000d2e0 =====

BOOL __stdcall StrokeAndFillPath(HDC hdc)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000d2e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xd2e0  1966  StrokeAndFillPath */
  BVar1 = StrokeAndFillPath(hdc);
  return BVar1;
}



===== DelayLoad_StrokeAndFillPath @ 18000d2ec =====

void DelayLoad_StrokeAndFillPath
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== UnloadNetworkFonts @ 18000d300 =====

void UnloadNetworkFonts(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000d300. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xd300  1972  UnloadNetworkFonts */
  UnloadNetworkFonts();
  return;
}



===== DelayLoad_UnloadNetworkFonts @ 18000d30c =====

void DelayLoad_UnloadNetworkFonts
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== UpdateICMRegKeyA @ 18000d320 =====

BOOL __stdcall UpdateICMRegKeyA(DWORD reserved,LPSTR lpszCMID,LPSTR lpszFileName,UINT command)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000d320. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xd320  1975  UpdateICMRegKeyA */
  BVar1 = UpdateICMRegKeyA(reserved,lpszCMID,lpszFileName,command);
  return BVar1;
}



===== DelayLoad_UpdateICMRegKeyA @ 18000d32c =====

void DelayLoad_UpdateICMRegKeyA
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== UpdateICMRegKeyW @ 18000d340 =====

BOOL __stdcall UpdateICMRegKeyW(DWORD reserved,LPWSTR lpszCMID,LPWSTR lpszFileName,UINT command)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000d340. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xd340  1976  UpdateICMRegKeyW */
  BVar1 = UpdateICMRegKeyW(reserved,lpszCMID,lpszFileName,command);
  return BVar1;
}



===== DelayLoad_UpdateICMRegKeyW @ 18000d34c =====

void DelayLoad_UpdateICMRegKeyW
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== WidenPath @ 18000d360 =====

BOOL __stdcall WidenPath(HDC hdc)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000d360. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xd360  1980  WidenPath */
  BVar1 = WidenPath(hdc);
  return BVar1;
}



===== DelayLoad_WidenPath @ 18000d36c =====

void DelayLoad_WidenPath(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4
                        )

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== XLATEOBJ_piVector @ 18000d380 =====

void XLATEOBJ_piVector(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000d380. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xd380  1986  XLATEOBJ_piVector */
  XLATEOBJ_piVector();
  return;
}



===== DelayLoad_XLATEOBJ_piVector @ 18000d38c =====

void DelayLoad_XLATEOBJ_piVector
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== bInitSystemAndFontsDirectoriesW @ 18000d3a0 =====

void bInitSystemAndFontsDirectoriesW(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000d3a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xd3a0  1989  bInitSystemAndFontsDirectoriesW */
  bInitSystemAndFontsDirectoriesW();
  return;
}



===== DelayLoad_bInitSystemAndFontsDirectoriesW @ 18000d3ac =====

void DelayLoad_bInitSystemAndFontsDirectoriesW
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== bMakePathNameW @ 18000d3c0 =====

void bMakePathNameW(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000d3c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xd3c0  1990  bMakePathNameW */
  bMakePathNameW();
  return;
}



===== DelayLoad_bMakePathNameW @ 18000d3cc =====

void DelayLoad_bMakePathNameW
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== cGetTTFFromFOT @ 18000d3e0 =====

void cGetTTFFromFOT(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000d3e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xd3e0  1991  cGetTTFFromFOT */
  cGetTTFFromFOT();
  return;
}



===== DelayLoad_cGetTTFFromFOT @ 18000d3ec =====

void DelayLoad_cGetTTFFromFOT
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== gdiPlaySpoolStream @ 18000d400 =====

void gdiPlaySpoolStream(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000d400. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xd400  1998  gdiPlaySpoolStream */
  gdiPlaySpoolStream();
  return;
}



===== DelayLoad_gdiPlaySpoolStream @ 18000d40c =====

void DelayLoad_gdiPlaySpoolStream
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== IsExtEscapeImplPresent @ 18000d420 =====

undefined1 IsExtEscapeImplPresent(void)

{
  undefined1 uVar1;
  int iVar2;
  
  if (DAT_1800256b0 == 1) {
    uVar1 = 1;
  }
  else {
    if ((DAT_1800256b0 != 2) && (iVar2 = ApiSetQueryApiSetPresence(&DAT_180010130), -1 < iVar2)) {
      DAT_1800256b0 = 2;
      return 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}



===== IsDeleteFontPresent @ 18000d474 =====

undefined1 IsDeleteFontPresent(void)

{
  undefined1 uVar1;
  int iVar2;
  
  if (DAT_1800256c0 == 1) {
    uVar1 = 1;
  }
  else {
    if ((DAT_1800256c0 != 2) && (iVar2 = ApiSetQueryApiSetPresence(&DAT_180010170), -1 < iVar2)) {
      DAT_1800256c0 = 2;
      return 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}



===== IsGdiTrackHCreatePresent @ 18000d4c8 =====

undefined1 IsGdiTrackHCreatePresent(void)

{
  undefined1 uVar1;
  int iVar2;
  
  if (DAT_1800256b4 == 1) {
    uVar1 = 1;
  }
  else {
    if ((DAT_1800256b4 != 2) && (iVar2 = ApiSetQueryApiSetPresence(&DAT_180010140), -1 < iVar2)) {
      DAT_1800256b4 = 2;
      return 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}



===== IsTraceLoggingGdiBatchInProcessingPresent @ 18000d51c =====

undefined1 IsTraceLoggingGdiBatchInProcessingPresent(void)

{
  undefined1 uVar1;
  int iVar2;
  
  if (DAT_1800256c8 == 1) {
    uVar1 = 1;
  }
  else {
    if ((DAT_1800256c8 != 2) && (iVar2 = ApiSetQueryApiSetPresence(&DAT_180010190), -1 < iVar2)) {
      DAT_1800256c8 = 2;
      return 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}



===== DelayLoad_MF_DeleteObjectHelper @ 18000d570 =====

void DelayLoad_MF_DeleteObjectHelper
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_DeleteFont @ 18000d582 =====

void DelayLoad_DeleteFont
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_4_dll(param_1,param_2,param_3,param_4);
  return;
}



===== __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_6_dll @ 18000d58e =====

void __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_6_dll
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 in_RAX;
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = (code *)__delayLoadHelper2(&ImgDelayDescr_180013420,in_RAX);
                    /* WARNING: Could not recover jumptable at 0x00018000d605. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_TraceLoggingGdiBatchInProcessing @ 18000d60d =====

void DelayLoad_TraceLoggingGdiBatchInProcessing
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_6_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_DwmGetDirtyRgnImpl @ 18000d61f =====

void DelayLoad_DwmGetDirtyRgnImpl
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_AddFontResourceWImpl @ 18000d631 =====

void DelayLoad_AddFontResourceWImpl
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_BeginPathImpl @ 18000d643 =====

void DelayLoad_BeginPathImpl
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_CloseFigureImpl @ 18000d655 =====

void DelayLoad_CloseFigureImpl
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_CreateDCAImpl @ 18000d667 =====

void DelayLoad_CreateDCAImpl
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_CreateScalableFontResourceWImpl @ 18000d679 =====

void DelayLoad_CreateScalableFontResourceWImpl
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_EndDocImpl @ 18000d68b =====

void DelayLoad_EndDocImpl
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_EndPageImpl @ 18000d69d =====

void DelayLoad_EndPageImpl
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_EndPathImpl @ 18000d6af =====

void DelayLoad_EndPathImpl
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_EscapeImpl @ 18000d6c1 =====

void DelayLoad_EscapeImpl
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_ExtEscapeImpl @ 18000d6d3 =====

void DelayLoad_ExtEscapeImpl
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_ExtSelectClipRgnImpl @ 18000d6e5 =====

void DelayLoad_ExtSelectClipRgnImpl
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_ExtTextOutAImpl @ 18000d6f7 =====

void DelayLoad_ExtTextOutAImpl
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_ExtTextOutWImpl @ 18000d709 =====

void DelayLoad_ExtTextOutWImpl
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_FillPathImpl @ 18000d71b =====

void DelayLoad_FillPathImpl
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_GetClipBoxImpl @ 18000d72d =====

void DelayLoad_GetClipBoxImpl
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_GetTextMetricsAImpl @ 18000d73f =====

void DelayLoad_GetTextMetricsAImpl
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_GetFontDataImpl @ 18000d751 =====

void DelayLoad_GetFontDataImpl
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_LineToImpl @ 18000d763 =====

void DelayLoad_LineToImpl
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_MoveToExImpl @ 18000d775 =====

void DelayLoad_MoveToExImpl
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_PolyBezierToImpl @ 18000d787 =====

void DelayLoad_PolyBezierToImpl
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_PolyDrawImpl @ 18000d799 =====

void DelayLoad_PolyDrawImpl
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_PolylineToImpl @ 18000d7ab =====

void DelayLoad_PolylineToImpl
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_RectangleImpl @ 18000d7bd =====

void DelayLoad_RectangleImpl
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_RemoveFontResourceWImpl @ 18000d7cf =====

void DelayLoad_RemoveFontResourceWImpl
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_RestoreDCImpl @ 18000d7e1 =====

void DelayLoad_RestoreDCImpl
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_ResetDCWImpl @ 18000d7f3 =====

void DelayLoad_ResetDCWImpl
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_SaveDCImpl @ 18000d805 =====

void DelayLoad_SaveDCImpl
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_SelectClipPathImpl @ 18000d817 =====

void DelayLoad_SelectClipPathImpl
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_SetBkModeImpl @ 18000d829 =====

void DelayLoad_SetBkModeImpl
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_SetTextAlignImpl @ 18000d83b =====

void DelayLoad_SetTextAlignImpl
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_SetTextColorImpl @ 18000d84d =====

void DelayLoad_SetTextColorImpl
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_SetICMModeImpl @ 18000d85f =====

void DelayLoad_SetICMModeImpl
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_SetMiterLimitImpl @ 18000d871 =====

void DelayLoad_SetMiterLimitImpl
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_SetStretchBltModeImpl @ 18000d883 =====

void DelayLoad_SetStretchBltModeImpl
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_SetWorldTransformImpl @ 18000d895 =====

void DelayLoad_SetWorldTransformImpl
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_StartDocWImpl @ 18000d8a7 =====

void DelayLoad_StartDocWImpl
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_StartPageImpl @ 18000d8b9 =====

void DelayLoad_StartPageImpl
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_StretchDIBitsImpl @ 18000d8cb =====

void DelayLoad_StretchDIBitsImpl
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_StrokePathImpl @ 18000d8dd =====

void DelayLoad_StrokePathImpl
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_GetGlyphOutlineA @ 18000d8ef =====

void DelayLoad_GetGlyphOutlineA
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_CreateFontIndirectWImpl @ 18000d901 =====

void DelayLoad_CreateFontIndirectWImpl
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_AddFontResourceA @ 18000d913 =====

void DelayLoad_AddFontResourceA
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_AnimatePalette @ 18000d925 =====

void DelayLoad_AnimatePalette
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_Arc @ 18000d937 =====

void DelayLoad_Arc(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_CreateBrushIndirect @ 18000d949 =====

void DelayLoad_CreateBrushIndirect
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_CreateEllipticRgnIndirect @ 18000d95b =====

void DelayLoad_CreateEllipticRgnIndirect
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_CreateFontA @ 18000d96d =====

void DelayLoad_CreateFontA
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_CreatePenIndirect @ 18000d97f =====

void DelayLoad_CreatePenIndirect
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_CreatePolyPolygonRgn @ 18000d991 =====

void DelayLoad_CreatePolyPolygonRgn
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_Ellipse @ 18000d9a3 =====

void DelayLoad_Ellipse(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_EnumEnhMetaFile @ 18000d9b5 =====

void DelayLoad_EnumEnhMetaFile
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_FrameRgn @ 18000d9c7 =====

void DelayLoad_FrameRgn(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_GdiComment @ 18000d9d9 =====

void DelayLoad_GdiComment
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_GetCurrentPositionEx @ 18000d9eb =====

void DelayLoad_GetCurrentPositionEx
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_GetEnhMetaFileA @ 18000d9fd =====

void DelayLoad_GetEnhMetaFileA
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_GetEnhMetaFileDescriptionA @ 18000da0f =====

void DelayLoad_GetEnhMetaFileDescriptionA
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_GetROP2 @ 18000da21 =====

void DelayLoad_GetROP2(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_GetRasterizerCaps @ 18000da33 =====

void DelayLoad_GetRasterizerCaps
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_GetTextCharacterExtra @ 18000da45 =====

void DelayLoad_GetTextCharacterExtra
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_GetTextExtentExPointA @ 18000da57 =====

void DelayLoad_GetTextExtentExPointA
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_GetTextExtentPoint32A @ 18000da69 =====

void DelayLoad_GetTextExtentPoint32A
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_GetTextExtentPointA @ 18000da7b =====

void DelayLoad_GetTextExtentPointA
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_GetTextExtentPointI @ 18000da8d =====

void DelayLoad_GetTextExtentPointI
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_InvertRgn @ 18000da9f =====

void DelayLoad_InvertRgn(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4
                        )

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_Pie @ 18000dab1 =====

void DelayLoad_Pie(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_PolyBezier @ 18000dac3 =====

void DelayLoad_PolyBezier
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_PolyPolygon @ 18000dad5 =====

void DelayLoad_PolyPolygon
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_Polygon @ 18000dae7 =====

void DelayLoad_Polygon(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_RemoveFontResourceA @ 18000daf9 =====

void DelayLoad_RemoveFontResourceA
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_ResizePalette @ 18000db0b =====

void DelayLoad_ResizePalette
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_RoundRect @ 18000db1d =====

void DelayLoad_RoundRect(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4
                        )

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_SetBitmapBits @ 18000db2f =====

void DelayLoad_SetBitmapBits
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_SetPaletteEntries @ 18000db41 =====

void DelayLoad_SetPaletteEntries
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_SetROP2 @ 18000db53 =====

void DelayLoad_SetROP2(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_TextOutA @ 18000db65 =====

void DelayLoad_TextOutA(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_UnrealizeObject @ 18000db77 =====

void DelayLoad_UnrealizeObject
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_UpdateColors @ 18000db89 =====

void DelayLoad_UpdateColors
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_internal_desktop_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== __tailMerge_ext_ms_win_gdi_edgegdi_l1_1_0_dll @ 18000db95 =====

void __tailMerge_ext_ms_win_gdi_edgegdi_l1_1_0_dll
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 in_RAX;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 in_RCX;
  
  UNRECOVERED_JUMPTABLE = (code *)__delayLoadHelper2(&ImgDelayDescr_180013440,in_RAX);
                    /* WARNING: Could not recover jumptable at 0x00018000dc0c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(in_RCX,param_2,param_3,param_4);
  return;
}



===== DelayLoad_EdgeGdiInitialize @ 18000dc14 =====

void DelayLoad_EdgeGdiInitialize
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_gdi_edgegdi_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== ApiSetQueryApiSetPresence @ 18000dc26 =====

void ApiSetQueryApiSetPresence(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000dc26. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ApiSetQueryApiSetPresence();
  return;
}



===== DrvQueryPrivateDisplayChangeUniqueness @ 18000dc40 =====

undefined4 DrvQueryPrivateDisplayChangeUniqueness(void)

{
                    /* 0xdc40  1015   */
  return *(undefined4 *)(pGdiSharedMemory + 0x180290);
}



===== GdipIsAssertEnabled @ 18000dc60 =====

undefined4 GdipIsAssertEnabled(uint param_1)

{
  undefined4 uVar1;
  undefined4 local_res8 [8];
  undefined4 local_e8 [2];
  undefined4 local_e0;
  uint local_dc;
  
                    /* 0xdc60  1621  GdipIsAssertEnabled */
  memset(local_e8,0,0xd8);
  local_e8[0] = 8;
  local_e0 = 0;
  local_res8[0] = 0;
  uVar1 = 0;
  if (param_1 < 0x1d) {
    local_dc = param_1;
    NamedEscape(0,L"ASU",0,0xd8,local_e8,4,local_res8);
    uVar1 = local_res8[0];
  }
  return uVar1;
}



===== AbortDoc @ 18000dcf0 =====

int __stdcall AbortDoc(HDC hdc)

{
  int iVar1;
  
                    /* 0xdcf0  1011  AbortDoc */
                    /* WARNING: Could not recover jumptable at 0x00018000dcf8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = AbortDocImpl();
  return iVar1;
}



===== AddFontResourceA @ 18000dd10 =====

int __stdcall AddFontResourceA(LPCSTR param_1)

{
  char cVar1;
  int iVar2;
  
                    /* 0xdd10  1018  AddFontResourceA */
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x00018000dd3b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar2 = AddFontResourceA(param_1);
  return iVar2;
}



===== AddFontResourceW @ 18000dd50 =====

int __stdcall AddFontResourceW(LPCWSTR param_1)

{
  char cVar1;
  int iVar2;
  
                    /* 0xdd50  1022  AddFontResourceW */
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x00018000dd7b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar2 = AddFontResourceWImpl(param_1);
  return iVar2;
}



===== AnimatePalette @ 18000dd90 =====

BOOL __stdcall AnimatePalette(HPALETTE hPal,UINT iStartIndex,UINT cEntries,PALETTEENTRY *ppe)

{
  char cVar1;
  BOOL BVar2;
  
                    /* 0xdd90  1024  AnimatePalette */
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    BVar2 = 0;
  }
  else {
    BVar2 = AnimatePalette(hPal,iStartIndex,cEntries,ppe);
  }
  return BVar2;
}



===== CreateEllipticRgnIndirect @ 18000de00 =====

HRGN __stdcall CreateEllipticRgnIndirect(RECT *lprect)

{
  char cVar1;
  HRGN pHVar2;
  
                    /* 0xde00  1074  CreateEllipticRgnIndirect */
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    return (HRGN)0x0;
  }
                    /* WARNING: Could not recover jumptable at 0x00018000de2b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pHVar2 = (HRGN)CreateEllipticRgnIndirect(lprect);
  return pHVar2;
}



===== CreateScalableFontResourceW @ 18000de40 =====

BOOL __stdcall
CreateScalableFontResourceW(DWORD fdwHidden,LPCWSTR lpszFont,LPCWSTR lpszFile,LPCWSTR lpszPath)

{
  char cVar1;
  BOOL BVar2;
  undefined4 uVar3;
  
                    /* 0xde40  1101  CreateScalableFontResourceW */
  uVar3 = 0x49414e;
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    BVar2 = 0;
  }
  else {
    BVar2 = CreateScalableFontResourceWImpl(fdwHidden,lpszFont,lpszFile,lpszPath,uVar3);
  }
  return BVar2;
}



===== DwmGetDirtyRgn @ 18000deb0 =====

undefined8
DwmGetDirtyRgn(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
              undefined8 param_5)

{
  char cVar1;
  undefined8 uVar2;
  
                    /* 0xdeb0  1008   */
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    uVar2 = 0;
  }
  else {
    uVar2 = DwmGetDirtyRgnImpl(param_1,param_2,param_3,param_4,param_5);
  }
  return uVar2;
}



===== GetEnhMetaFileA @ 18000df20 =====

HENHMETAFILE __stdcall GetEnhMetaFileA(LPCSTR lpName)

{
  char cVar1;
  HENHMETAFILE pHVar2;
  
                    /* 0xdf20  1675  GetEnhMetaFileA */
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    return (HENHMETAFILE)0x0;
  }
                    /* WARNING: Could not recover jumptable at 0x00018000df4b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pHVar2 = (HENHMETAFILE)GetEnhMetaFileA(lpName);
  return pHVar2;
}



===== GetEnhMetaFileDescriptionA @ 18000df60 =====

UINT __stdcall GetEnhMetaFileDescriptionA(HENHMETAFILE hemf,UINT cchBuffer,LPSTR lpDescription)

{
  char cVar1;
  UINT UVar2;
  
                    /* 0xdf60  1677  GetEnhMetaFileDescriptionA */
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    UVar2 = 0;
  }
  else {
    UVar2 = GetEnhMetaFileDescriptionA(hemf,cchBuffer,lpDescription);
  }
  return UVar2;
}



===== GetGlyphOutline @ 18000dfc0 =====

DWORD __stdcall
GetGlyphOutline(HDC hdc,UINT uChar,UINT fuFormat,LPGLYPHMETRICS lpgm,DWORD cjBuffer,LPVOID pvBuffer,
               MAT2 *lpmat2)

{
  DWORD DVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000dfc0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0xdfc0  1693  GetGlyphOutline */
  DVar1 = GetGlyphOutlineA(hdc,uChar,fuFormat,lpgm,cjBuffer,pvBuffer,lpmat2);
  return DVar1;
}



===== GetRasterizerCaps @ 18000dfe0 =====

BOOL __stdcall GetRasterizerCaps(LPRASTERIZER_STATUS lpraststat,UINT cjBytes)

{
  char cVar1;
  BOOL BVar2;
  
                    /* 0xdfe0  1734  GetRasterizerCaps */
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    BVar2 = 0;
  }
  else {
    BVar2 = GetRasterizerCaps(lpraststat,cjBytes);
  }
  return BVar2;
}



===== RemoveFontResourceA @ 18000e030 =====

BOOL __stdcall RemoveFontResourceA(LPCSTR lpFileName)

{
  char cVar1;
  BOOL BVar2;
  
                    /* 0xe030  1840  RemoveFontResourceA */
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x00018000e05b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar2 = RemoveFontResourceA(lpFileName);
  return BVar2;
}



===== SetPaletteEntries @ 18000e070 =====

UINT __stdcall SetPaletteEntries(HPALETTE hpal,UINT iStart,UINT cEntries,PALETTEENTRY *pPalEntries)

{
  char cVar1;
  UINT UVar2;
  
                    /* 0xe070  1939  SetPaletteEntries */
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    UVar2 = 0;
  }
  else {
    UVar2 = SetPaletteEntries(hpal,iStart,cEntries,pPalEntries);
  }
  return UVar2;
}



===== StartDocA @ 18000e0e0 =====

int __stdcall StartDocA(HDC hdc,DOCINFOA *lpdi)

{
  char cVar1;
  int iVar2;
  
                    /* 0xe0e0  1960  StartDocA */
  cVar1 = IsStartDocAPresent();
  if (cVar1 == '\0') {
    iVar2 = 0;
  }
  else {
    iVar2 = StartDocA(hdc,lpdi);
  }
  return iVar2;
}



===== UpdateColors @ 18000e130 =====

BOOL __stdcall UpdateColors(HDC hdc)

{
  char cVar1;
  BOOL BVar2;
  
                    /* 0xe130  1974  UpdateColors */
  cVar1 = IsExtEscapeImplPresent();
  if (cVar1 == '\0') {
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x00018000e15b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar2 = UpdateColors(hdc);
  return BVar2;
}



===== MicrosoftTelemetryAssertTriggeredNoArgs @ 18000e170 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void MicrosoftTelemetryAssertTriggeredNoArgs(void)

{
  BOOL BVar1;
  FARPROC pFVar2;
  HMODULE local_res8 [4];
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined4 local_18;
  
  local_res8[0] = (HMODULE)0x0;
  BVar1 = GetModuleHandleExA(2,"ntdll.dll",local_res8);
  if ((BVar1 != 0) && (local_res8[0] != (HMODULE)0x0)) {
    pFVar2 = GetProcAddress(local_res8[0],"MicrosoftTelemetryAssertTriggeredUM");
    if (pFVar2 != (FARPROC)0x0) {
      uStack_40 = 0x180000000;
      local_28 = 0;
      uStack_20 = 0xffffffffffffffff;
      local_48 = 0xb;
      local_18 = 1;
      uStack_30 = 0;
      (*pFVar2)(&local_48);
    }
  }
  return;
}



===== _guard_check_icall @ 18000e230 =====

void _guard_check_icall(void)

{
  return;
}



===== memset @ 18000e246 =====

void * __cdecl memset(void *_Dst,int _Val,size_t _Size)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000e246. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = memset(_Dst,_Val,_Size);
  return pvVar1;
}



===== __security_check_cookie @ 18000e260 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 18000e2a0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 18000e2d0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x00018000e2d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 18000e300 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall$thunk$10345483385596137414 @ 18000f010 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall_thunk_10345483385596137414(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== D3DKMTAbandonSwapChain @ 18002b000 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1b326  1105  D3DKMTAbandonSwapChain  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#154) */

void D3DKMTAbandonSwapChain(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTAcquireKeyedMutex @ 18002b008 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1b366  1106  D3DKMTAcquireKeyedMutex  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#73) */

void D3DKMTAcquireKeyedMutex(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTAcquireKeyedMutex2 @ 18002b010 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1b3a6  1107  D3DKMTAcquireKeyedMutex2  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#74) */

void D3DKMTAcquireKeyedMutex2(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTAcquireSwapChain @ 18002b018 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1b3e4  1108  D3DKMTAcquireSwapChain  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#151) */

void D3DKMTAcquireSwapChain(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTAddSurfaceToSwapChain @ 18002b020 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1b428  1109  D3DKMTAddSurfaceToSwapChain  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#194) */

void D3DKMTAddSurfaceToSwapChain(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTAdjustFullscreenGamma @ 18002b028 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1b46c  1110  D3DKMTAdjustFullscreenGamma  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#123) */

void D3DKMTAdjustFullscreenGamma(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTCacheHybridQueryValue @ 18002b030 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1b4b0  1111  D3DKMTCacheHybridQueryValue  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#92)
    */

void D3DKMTCacheHybridQueryValue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTCancelPresents @ 18002b038 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1b4ec  1112  D3DKMTCancelPresents  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#227) */

void D3DKMTCancelPresents(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTChangeVideoMemoryReservation @ 18002b040 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1b537  1113  D3DKMTChangeVideoMemoryReservation  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#132) */

void D3DKMTChangeVideoMemoryReservation(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTCheckExclusiveOwnership @ 18002b048 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1b57d  1114  D3DKMTCheckExclusiveOwnership  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#63) */

void D3DKMTCheckExclusiveOwnership(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTCheckMonitorPowerState @ 18002b050 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1b5c1  1115  D3DKMTCheckMonitorPowerState  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#62) */

void D3DKMTCheckMonitorPowerState(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTCheckMultiPlaneOverlaySupport @ 18002b058 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1b60c  1116  D3DKMTCheckMultiPlaneOverlaySupport  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#137) */

void D3DKMTCheckMultiPlaneOverlaySupport(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTCheckMultiPlaneOverlaySupport2 @ 18002b060 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1b659  1117  D3DKMTCheckMultiPlaneOverlaySupport2  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#139) */

void D3DKMTCheckMultiPlaneOverlaySupport2(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTCheckMultiPlaneOverlaySupport3 @ 18002b068 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1b6a6  1118  D3DKMTCheckMultiPlaneOverlaySupport3  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#147) */

void D3DKMTCheckMultiPlaneOverlaySupport3(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTCheckOcclusion @ 18002b070 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1b6e3  1119  D3DKMTCheckOcclusion  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#60) */

void D3DKMTCheckOcclusion(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTCheckSharedResourceAccess @ 18002b078 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1b72a  1120  D3DKMTCheckSharedResourceAccess  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#79) */

void D3DKMTCheckSharedResourceAccess(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTCheckSinglePlaneForMultiPlaneOverlaySupport @ 18002b080 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1b783  1121  D3DKMTCheckSinglePlaneForMultiPlaneOverlaySupport  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#226) */

void D3DKMTCheckSinglePlaneForMultiPlaneOverlaySupport(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTCheckVidPnExclusiveOwnership @ 18002b088 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1b7ce  1122  D3DKMTCheckVidPnExclusiveOwnership  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#64) */

void D3DKMTCheckVidPnExclusiveOwnership(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTCloseAdapter @ 18002b090 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1b808  1123  D3DKMTCloseAdapter  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#36) */

void D3DKMTCloseAdapter(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTConfigureSharedResource @ 18002b098 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1b84d  1124  D3DKMTConfigureSharedResource  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#77) */

void D3DKMTConfigureSharedResource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTConnectDoorbell @ 18002b0a0 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1b88a  1125  D3DKMTConnectDoorbell  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#232) */

void D3DKMTConnectDoorbell(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTCreateAllocation @ 18002b0a8 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1b8c9  1126  D3DKMTCreateAllocation  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#1) */

void D3DKMTCreateAllocation(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTCreateAllocation2 @ 18002b0b0 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1b907  1127  D3DKMTCreateAllocation2  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#2) */

void D3DKMTCreateAllocation2(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTCreateBundleObject @ 18002b0b8 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1b946  1128  D3DKMTCreateBundleObject  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#189)
    */

void D3DKMTCreateBundleObject(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTCreateContext @ 18002b0c0 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1b982  1129  D3DKMTCreateContext  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#16) */

void D3DKMTCreateContext(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTCreateContextVirtual @ 18002b0c8 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1b9c4  1130  D3DKMTCreateContextVirtual  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#119)
    */

void D3DKMTCreateContextVirtual(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTCreateDCFromMemory @ 18002b0d0 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1ba05  1131  D3DKMTCreateDCFromMemory  (forwarder -> WIN32U.NtGdiDdDDICreateDCFromMemory) */

void D3DKMTCreateDCFromMemory(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTCreateDevice @ 18002b0d8 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1ba3c  1132  D3DKMTCreateDevice  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#14) */

void D3DKMTCreateDevice(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTCreateDoorbell @ 18002b0e0 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1ba78  1133  D3DKMTCreateDoorbell  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#231) */

void D3DKMTCreateDoorbell(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTCreateHwContext @ 18002b0e8 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1bab6  1134  D3DKMTCreateHwContext  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#158) */

void D3DKMTCreateHwContext(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTCreateHwQueue @ 18002b0f0 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1baf2  1135  D3DKMTCreateHwQueue  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#160) */

void D3DKMTCreateHwQueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTCreateKeyedMutex @ 18002b0f8 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1bb31  1136  D3DKMTCreateKeyedMutex  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#68) */

void D3DKMTCreateKeyedMutex(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTCreateKeyedMutex2 @ 18002b100 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1bb70  1137  D3DKMTCreateKeyedMutex2  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#69) */

void D3DKMTCreateKeyedMutex2(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTCreateNativeFence @ 18002b108 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1bbaf  1138  D3DKMTCreateNativeFence  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#229) */

void D3DKMTCreateNativeFence(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTCreateOutputDupl @ 18002b110 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1bbee  1139  D3DKMTCreateOutputDupl  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#82) */

void D3DKMTCreateOutputDupl(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTCreateOverlay @ 18002b118 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1bc29  1140  D3DKMTCreateOverlay  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#43) */

void D3DKMTCreateOverlay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTCreatePagingQueue @ 18002b120 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1bc68  1141  D3DKMTCreatePagingQueue  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#109) */

void D3DKMTCreatePagingQueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTCreateProtectedSession @ 18002b128 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1bcad  1142  D3DKMTCreateProtectedSession  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#184) */

void D3DKMTCreateProtectedSession(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTCreateSwapChain @ 18002b130 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1bceb  1143  D3DKMTCreateSwapChain  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#149) */

void D3DKMTCreateSwapChain(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTCreateSynchronizationObject @ 18002b138 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1bd35  1144  D3DKMTCreateSynchronizationObject  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#18) */

void D3DKMTCreateSynchronizationObject(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTCreateSynchronizationObject2 @ 18002b140 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1bd7f  1145  D3DKMTCreateSynchronizationObject2  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#19) */

void D3DKMTCreateSynchronizationObject2(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTCreateTrackedWorkload @ 18002b148 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1bdc2  1146  D3DKMTCreateTrackedWorkload  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#207) */

void D3DKMTCreateTrackedWorkload(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTDDisplayEnum @ 18002b150 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1bdfd  1147  D3DKMTDDisplayEnum  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#178) */

void D3DKMTDDisplayEnum(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTDestroyAllocation @ 18002b158 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1be3d  1148  D3DKMTDestroyAllocation  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#11) */

void D3DKMTDestroyAllocation(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTDestroyAllocation2 @ 18002b160 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1be7d  1149  D3DKMTDestroyAllocation2  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#100)
    */

void D3DKMTDestroyAllocation2(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTDestroyContext @ 18002b168 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1beba  1150  D3DKMTDestroyContext  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#17) */

void D3DKMTDestroyContext(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTDestroyDCFromMemory @ 18002b170 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1befb  1151  D3DKMTDestroyDCFromMemory  (forwarder -> WIN32U.NtGdiDdDDIDestroyDCFromMemory) */

void D3DKMTDestroyDCFromMemory(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTDestroyDevice @ 18002b178 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1bf34  1152  D3DKMTDestroyDevice  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#15) */

void D3DKMTDestroyDevice(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTDestroyDoorbell @ 18002b180 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1bf71  1153  D3DKMTDestroyDoorbell  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#233) */

void D3DKMTDestroyDoorbell(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTDestroyHwContext @ 18002b188 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1bfb0  1154  D3DKMTDestroyHwContext  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#159) */

void D3DKMTDestroyHwContext(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTDestroyHwQueue @ 18002b190 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1bfed  1155  D3DKMTDestroyHwQueue  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#161) */

void D3DKMTDestroyHwQueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTDestroyKeyedMutex @ 18002b198 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1c02d  1156  D3DKMTDestroyKeyedMutex  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#72) */

void D3DKMTDestroyKeyedMutex(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTDestroyOutputDupl @ 18002b1a0 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1c06c  1157  D3DKMTDestroyOutputDupl  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#83) */

void D3DKMTDestroyOutputDupl(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTDestroyOverlay @ 18002b1a8 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1c0a8  1158  D3DKMTDestroyOverlay  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#46) */

void D3DKMTDestroyOverlay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTDestroyPagingQueue @ 18002b1b0 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1c0e8  1159  D3DKMTDestroyPagingQueue  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#110)
    */

void D3DKMTDestroyPagingQueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTDestroyProtectedSession @ 18002b1b8 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1c12e  1160  D3DKMTDestroyProtectedSession  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#185) */

void D3DKMTDestroyProtectedSession(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTDestroySynchronizationObject @ 18002b1c0 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1c179  1161  D3DKMTDestroySynchronizationObject  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#21) */

void D3DKMTDestroySynchronizationObject(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTDestroyTrackedWorkload @ 18002b1c8 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1c1bd  1162  D3DKMTDestroyTrackedWorkload  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#208) */

void D3DKMTDestroyTrackedWorkload(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTDispMgrCreate @ 18002b1d0 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1c1f9  1163  D3DKMTDispMgrCreate  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#179) */

void D3DKMTDispMgrCreate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTDispMgrOperation @ 18002b1d8 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1c238  1164  D3DKMTDispMgrOperation  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#215) */

void D3DKMTDispMgrOperation(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTDispMgrSourceOperation @ 18002b1e0 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1c27d  1165  D3DKMTDispMgrSourceOperation  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#181) */

void D3DKMTDispMgrSourceOperation(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTDispMgrTargetOperation @ 18002b1e8 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1c2c2  1166  D3DKMTDispMgrTargetOperation  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#180) */

void D3DKMTDispMgrTargetOperation(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTDisplayMuxSwitchExecute @ 18002b1f0 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1c308  1167  D3DKMTDisplayMuxSwitchExecute  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#237) */

void D3DKMTDisplayMuxSwitchExecute(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTDisplayMuxSwitchFinish @ 18002b1f8 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1c34d  1168  D3DKMTDisplayMuxSwitchFinish  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#238) */

void D3DKMTDisplayMuxSwitchFinish(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTDisplayMuxSwitchPrepare @ 18002b200 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1c393  1169  D3DKMTDisplayMuxSwitchPrepare  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#236) */

void D3DKMTDisplayMuxSwitchPrepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTDisplayPortOperation @ 18002b208 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1c3d6  1170  D3DKMTDisplayPortOperation  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#222)
    */

void D3DKMTDisplayPortOperation(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTDuplicateHandle @ 18002b210 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1c414  1171  D3DKMTDuplicateHandle  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#216) */

void D3DKMTDuplicateHandle(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTEnumAdapters @ 18002b218 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1c44f  1172  D3DKMTEnumAdapters  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#143) */

void D3DKMTEnumAdapters(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTEnumAdapters2 @ 18002b220 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1c48b  1173  D3DKMTEnumAdapters2  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#144) */

void D3DKMTEnumAdapters2(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTEnumAdapters3 @ 18002b228 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1c4c7  1174  D3DKMTEnumAdapters3  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#217) */

void D3DKMTEnumAdapters3(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTEnumProcesses @ 18002b230 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1c503  1175  D3DKMTEnumProcesses  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#228) */

void D3DKMTEnumProcesses(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTEscape @ 18002b238 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1c538  1176  D3DKMTEscape  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#38) */

void D3DKMTEscape(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTEvict @ 18002b240 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1c56b  1177  D3DKMTEvict  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#102) */

void D3DKMTEvict(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTExtractBundleObject @ 18002b248 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1c5ad  1178  D3DKMTExtractBundleObject  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#190)
    */

void D3DKMTExtractBundleObject(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTFlipOverlay @ 18002b250 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1c5e7  1179  D3DKMTFlipOverlay  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#45) */

void D3DKMTFlipOverlay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTFlushHeapTransitions @ 18002b258 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1c629  1180  D3DKMTFlushHeapTransitions  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#127)
    */

void D3DKMTFlushHeapTransitions(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTFreeGpuVirtualAddress @ 18002b260 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1c66d  1181  D3DKMTFreeGpuVirtualAddress  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#116) */

void D3DKMTFreeGpuVirtualAddress(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTGetAllocationPriority @ 18002b268 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1c6b1  1182  D3DKMTGetAllocationPriority  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#169) */

void D3DKMTGetAllocationPriority(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTGetAvailableTrackedWorkloadIndex @ 18002b270 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1c700  1183  D3DKMTGetAvailableTrackedWorkloadIndex  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#209) */

void D3DKMTGetAvailableTrackedWorkloadIndex(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTGetCachedHybridQueryValue @ 18002b278 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1c748  1184  D3DKMTGetCachedHybridQueryValue  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#91) */

void D3DKMTGetCachedHybridQueryValue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTGetContextInProcessSchedulingPriority @ 18002b280 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1c79b  1185  D3DKMTGetContextInProcessSchedulingPriority  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#50) */

void D3DKMTGetContextInProcessSchedulingPriority(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTGetContextSchedulingPriority @ 18002b288 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1c7e5  1186  D3DKMTGetContextSchedulingPriority  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#52) */

void D3DKMTGetContextSchedulingPriority(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTGetDWMVerticalBlankEvent @ 18002b290 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1c82b  1187  D3DKMTGetDWMVerticalBlankEvent  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#168) */

void D3DKMTGetDWMVerticalBlankEvent(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTGetDeviceState @ 18002b298 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1c868  1188  D3DKMTGetDeviceState  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#49) */

void D3DKMTGetDeviceState(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTGetDisplayModeList @ 18002b2a0 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1c8a8  1189  D3DKMTGetDisplayModeList  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#28) */

void D3DKMTGetDisplayModeList(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTGetMemoryBudgetTarget @ 18002b2a8 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1c8eb  1190  D3DKMTGetMemoryBudgetTarget  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#177) */

void D3DKMTGetMemoryBudgetTarget(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTGetMultiPlaneOverlayCaps @ 18002b2b0 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1c932  1191  D3DKMTGetMultiPlaneOverlayCaps  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#170) */

void D3DKMTGetMultiPlaneOverlayCaps(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTGetMultisampleMethodList @ 18002b2b8 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1c979  1192  D3DKMTGetMultisampleMethodList  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#30) */

void D3DKMTGetMultisampleMethodList(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTGetNativeFenceLogDetail @ 18002b2c0 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1c9be  1193  D3DKMTGetNativeFenceLogDetail  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#239) */

void D3DKMTGetNativeFenceLogDetail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTGetOverlayState @ 18002b2c8 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1c9fc  1194  D3DKMTGetOverlayState  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#78) */

void D3DKMTGetOverlayState(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTGetPostCompositionCaps @ 18002b2d0 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1ca40  1195  D3DKMTGetPostCompositionCaps  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#171) */

void D3DKMTGetPostCompositionCaps(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTGetPresentHistory @ 18002b2d8 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1ca80  1196  D3DKMTGetPresentHistory  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#41) */

void D3DKMTGetPresentHistory(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTGetPresentQueueEvent @ 18002b2e0 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1cac2  1197  D3DKMTGetPresentQueueEvent  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#42)
    */

void D3DKMTGetPresentQueueEvent(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTGetProcessDeviceRemovalSupport @ 18002b2e8 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1cb0e  1198  D3DKMTGetProcessDeviceRemovalSupport  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#192) */

void D3DKMTGetProcessDeviceRemovalSupport(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTGetProcessList @ 18002b2f0 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1cb4b  1199  D3DKMTGetProcessList  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#203) */

void D3DKMTGetProcessList(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTGetProcessSchedulingPriorityBand @ 18002b2f8 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1cb9a  1200  D3DKMTGetProcessSchedulingPriorityBand  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#176) */

void D3DKMTGetProcessSchedulingPriorityBand(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTGetProcessSchedulingPriorityClass @ 18002b300 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1cbea  1201  D3DKMTGetProcessSchedulingPriorityClass  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#54) */

void D3DKMTGetProcessSchedulingPriorityClass(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTGetProperties @ 18002b308 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1cc25  1202  D3DKMTGetProperties  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#224) */

void D3DKMTGetProperties(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTGetResourcePresentPrivateDriverData @ 18002b310 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1cc77  1203  D3DKMTGetResourcePresentPrivateDriverData  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#118) */

void D3DKMTGetResourcePresentPrivateDriverData(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTGetRuntimeData @ 18002b318 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1ccb4  1204  D3DKMTGetRuntimeData  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#33) */

void D3DKMTGetRuntimeData(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTGetScanLine @ 18002b320 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1cced  1205  D3DKMTGetScanLine  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#56) */

void D3DKMTGetScanLine(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTGetSetSwapChainMetadata @ 18002b328 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1cd32  1206  D3DKMTGetSetSwapChainMetadata  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#153) */

void D3DKMTGetSetSwapChainMetadata(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTGetSharedPrimaryHandle @ 18002b330 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1cd77  1207  D3DKMTGetSharedPrimaryHandle  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#37) */

void D3DKMTGetSharedPrimaryHandle(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTGetSharedResourceAdapterLuid @ 18002b338 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1cdc1  1208  D3DKMTGetSharedResourceAdapterLuid  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#89) */

void D3DKMTGetSharedResourceAdapterLuid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTGetSwapChainSurfacePhysicalAddress @ 18002b340 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1ce11  1209  D3DKMTGetSwapChainSurfacePhysicalAddress  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#225) */

void D3DKMTGetSwapChainSurfacePhysicalAddress(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTGetTrackedWorkloadStatistics @ 18002b348 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1ce5c  1210  D3DKMTGetTrackedWorkloadStatistics  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#212) */

void D3DKMTGetTrackedWorkloadStatistics(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTGetYieldPercentage @ 18002b350 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1ce9d  1211  D3DKMTGetYieldPercentage  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#175)
    */

void D3DKMTGetYieldPercentage(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTInvalidateActiveVidPn @ 18002b358 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1cee1  1212  D3DKMTInvalidateActiveVidPn  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#59)
    */

void D3DKMTInvalidateActiveVidPn(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTInvalidateCache @ 18002b360 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1cf1e  1213  D3DKMTInvalidateCache  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#113) */

void D3DKMTInvalidateCache(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTIsFeatureEnabled @ 18002b368 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1cf5d  1214  D3DKMTIsFeatureEnabled  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#235) */

void D3DKMTIsFeatureEnabled(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTLock @ 18002b370 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1cf90  1215  D3DKMTLock  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#26) */

void D3DKMTLock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTLock2 @ 18002b378 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1cfc3  1216  D3DKMTLock2  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#111) */

void D3DKMTLock2(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTMakeResident @ 18002b380 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1cffe  1217  D3DKMTMakeResident  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#101) */

void D3DKMTMakeResident(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTMapGpuVirtualAddress @ 18002b388 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1d041  1218  D3DKMTMapGpuVirtualAddress  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#114)
    */

void D3DKMTMapGpuVirtualAddress(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTMarkDeviceAsError @ 18002b390 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1d081  1219  D3DKMTMarkDeviceAsError  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#126) */

void D3DKMTMarkDeviceAsError(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTNetDispGetNextChunkInfo @ 18002b398 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1d0c7  1220  D3DKMTNetDispGetNextChunkInfo  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#93) */

void D3DKMTNetDispGetNextChunkInfo(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTNetDispQueryMiracastDisplayDeviceStatus @ 18002b3a0 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1d11c  1221  D3DKMTNetDispQueryMiracastDisplayDeviceStatus  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#99) */

void D3DKMTNetDispQueryMiracastDisplayDeviceStatus(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTNetDispQueryMiracastDisplayDeviceSupport @ 18002b3a8 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1d172  1222  D3DKMTNetDispQueryMiracastDisplayDeviceSupport  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#94) */

void D3DKMTNetDispQueryMiracastDisplayDeviceSupport(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTNetDispStartMiracastDisplayDevice @ 18002b3b0 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1d1c1  1223  D3DKMTNetDispStartMiracastDisplayDevice  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#95) */

void D3DKMTNetDispStartMiracastDisplayDevice(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTNetDispStartMiracastDisplayDevice2 @ 18002b3b8 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1d211  1224  D3DKMTNetDispStartMiracastDisplayDevice2  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#96) */

void D3DKMTNetDispStartMiracastDisplayDevice2(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTNetDispStartMiracastDisplayDeviceEx @ 18002b3c0 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1d262  1225  D3DKMTNetDispStartMiracastDisplayDeviceEx  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#97) */

void D3DKMTNetDispStartMiracastDisplayDeviceEx(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTNetDispStopMiracastDisplayDevice @ 18002b3c8 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1d2b0  1226  D3DKMTNetDispStopMiracastDisplayDevice  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#98) */

void D3DKMTNetDispStopMiracastDisplayDevice(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTNotifyWorkSubmission @ 18002b3d0 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1d2f2  1227  D3DKMTNotifyWorkSubmission  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#234)
    */

void D3DKMTNotifyWorkSubmission(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTOfferAllocations @ 18002b3d8 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1d331  1228  D3DKMTOfferAllocations  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#80) */

void D3DKMTOfferAllocations(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTOpenAdapterFromDeviceName @ 18002b3e0 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1d378  1229  D3DKMTOpenAdapterFromDeviceName  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#35) */

void D3DKMTOpenAdapterFromDeviceName(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTOpenAdapterFromLuid @ 18002b3e8 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1d3f6  1232  D3DKMTOpenAdapterFromLuid  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#124)
    */

void D3DKMTOpenAdapterFromLuid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTOpenBundleObjectNtHandleFromName @ 18002b3f0 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1d445  1233  D3DKMTOpenBundleObjectNtHandleFromName  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#204) */

void D3DKMTOpenBundleObjectNtHandleFromName(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTOpenKeyedMutex @ 18002b3f8 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1d482  1234  D3DKMTOpenKeyedMutex  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#70) */

void D3DKMTOpenKeyedMutex(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTOpenKeyedMutex2 @ 18002b400 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1d4bf  1235  D3DKMTOpenKeyedMutex2  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#71) */

void D3DKMTOpenKeyedMutex2(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTOpenKeyedMutexFromNtHandle @ 18002b408 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1d507  1236  D3DKMTOpenKeyedMutexFromNtHandle  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#197) */

void D3DKMTOpenKeyedMutexFromNtHandle(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTOpenNativeFenceFromNtHandle @ 18002b410 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1d551  1237  D3DKMTOpenNativeFenceFromNtHandle  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#230) */

void D3DKMTOpenNativeFenceFromNtHandle(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTOpenNtHandleFromName @ 18002b418 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1d594  1238  D3DKMTOpenNtHandleFromName  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#6)
    */

void D3DKMTOpenNtHandleFromName(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTOpenProtectedSessionFromNtHandle @ 18002b420 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1d5e1  1239  D3DKMTOpenProtectedSessionFromNtHandle  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#188) */

void D3DKMTOpenProtectedSessionFromNtHandle(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTOpenResource @ 18002b428 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1d61c  1240  D3DKMTOpenResource  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#9) */

void D3DKMTOpenResource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTOpenResource2 @ 18002b430 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1d656  1241  D3DKMTOpenResource2  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#10) */

void D3DKMTOpenResource2(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTOpenResourceFromNtHandle @ 18002b438 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1d69c  1242  D3DKMTOpenResourceFromNtHandle  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#7) */

void D3DKMTOpenResourceFromNtHandle(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTOpenSwapChain @ 18002b440 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1d6d6  1243  D3DKMTOpenSwapChain  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#150) */

void D3DKMTOpenSwapChain(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTOpenSyncObjectFromNtHandle @ 18002b448 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1d71f  1244  D3DKMTOpenSyncObjectFromNtHandle  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#8) */

void D3DKMTOpenSyncObjectFromNtHandle(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTOpenSyncObjectFromNtHandle2 @ 18002b450 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1d767  1245  D3DKMTOpenSyncObjectFromNtHandle2  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#129) */

void D3DKMTOpenSyncObjectFromNtHandle2(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTOpenSyncObjectNtHandleFromName @ 18002b458 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1d7b4  1246  D3DKMTOpenSyncObjectNtHandleFromName  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#130) */

void D3DKMTOpenSyncObjectNtHandleFromName(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTOpenSynchronizationObject @ 18002b460 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1d7fc  1247  D3DKMTOpenSynchronizationObject  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#20) */

void D3DKMTOpenSynchronizationObject(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTOutputDuplGetFrameInfo @ 18002b468 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1d840  1248  D3DKMTOutputDuplGetFrameInfo  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#84) */

void D3DKMTOutputDuplGetFrameInfo(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTOutputDuplGetMetaData @ 18002b470 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1d883  1249  D3DKMTOutputDuplGetMetaData  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#85)
    */

void D3DKMTOutputDuplGetMetaData(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTOutputDuplGetPointerShapeData @ 18002b478 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1d8ce  1250  D3DKMTOutputDuplGetPointerShapeData  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#86) */

void D3DKMTOutputDuplGetPointerShapeData(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTOutputDuplPresent @ 18002b480 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1d90d  1251  D3DKMTOutputDuplPresent  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#88) */

void D3DKMTOutputDuplPresent(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTOutputDuplPresentToHwQueue @ 18002b488 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1d955  1252  D3DKMTOutputDuplPresentToHwQueue  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#214) */

void D3DKMTOutputDuplPresentToHwQueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTOutputDuplReleaseFrame @ 18002b490 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1d99a  1253  D3DKMTOutputDuplReleaseFrame  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#87) */

void D3DKMTOutputDuplReleaseFrame(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTPinDirectFlipResources @ 18002b498 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1d9de  1254  D3DKMTPinDirectFlipResources  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#135) */

void D3DKMTPinDirectFlipResources(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTPinResources @ 18002b4a0 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1da19  1255  D3DKMTPinResources  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#220) */

void D3DKMTPinResources(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTPollDisplayChildren @ 18002b4a8 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1da5b  1256  D3DKMTPollDisplayChildren  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#58)
    */

void D3DKMTPollDisplayChildren(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTPresent @ 18002b4b0 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1da90  1257  D3DKMTPresent  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#31) */

void D3DKMTPresent(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTPresentMultiPlaneOverlay @ 18002b4b8 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1dad6  1258  D3DKMTPresentMultiPlaneOverlay  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#138) */

void D3DKMTPresentMultiPlaneOverlay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTPresentMultiPlaneOverlay2 @ 18002b4c0 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1db1e  1259  D3DKMTPresentMultiPlaneOverlay2  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#140) */

void D3DKMTPresentMultiPlaneOverlay2(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTPresentMultiPlaneOverlay3 @ 18002b4c8 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1db66  1260  D3DKMTPresentMultiPlaneOverlay3  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#148) */

void D3DKMTPresentMultiPlaneOverlay3(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTPresentRedirected @ 18002b4d0 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1dba6  1261  D3DKMTPresentRedirected  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#193) */

void D3DKMTPresentRedirected(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTQueryAdapterInfo @ 18002b4d8 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1dbe5  1262  D3DKMTQueryAdapterInfo  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#34) */

void D3DKMTQueryAdapterInfo(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTQueryAllocationResidency @ 18002b4e0 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1dc2b  1263  D3DKMTQueryAllocationResidency  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#13) */

void D3DKMTQueryAllocationResidency(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTQueryClockCalibration @ 18002b4e8 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1dc6e  1264  D3DKMTQueryClockCalibration  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#142) */

void D3DKMTQueryClockCalibration(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTQueryFSEBlock @ 18002b4f0 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1dcaa  1265  D3DKMTQueryFSEBlock  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#157) */

void D3DKMTQueryFSEBlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTQueryProcessOfferInfo @ 18002b4f8 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1dcee  1266  D3DKMTQueryProcessOfferInfo  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#145) */

void D3DKMTQueryProcessOfferInfo(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTQueryProtectedSessionInfoFromNtHandle @ 18002b500 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1dd42  1267  D3DKMTQueryProtectedSessionInfoFromNtHandle  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#187) */

void D3DKMTQueryProtectedSessionInfoFromNtHandle(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTQueryProtectedSessionStatus @ 18002b508 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1dd8c  1268  D3DKMTQueryProtectedSessionStatus  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#186) */

void D3DKMTQueryProtectedSessionStatus(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTQueryRemoteVidPnSourceFromGdiDisplayName @ 18002b510 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1dde3  1269  D3DKMTQueryRemoteVidPnSourceFromGdiDisplayName  (forwarder ->
   WIN32U.NtGdiDdDDIQueryRemoteVidPnSourceFromGdiDisplayName) */

void D3DKMTQueryRemoteVidPnSourceFromGdiDisplayName(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTQueryResourceInfo @ 18002b518 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1de35  1270  D3DKMTQueryResourceInfo  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#3) */

void D3DKMTQueryResourceInfo(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTQueryResourceInfoFromNtHandle @ 18002b520 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1de7f  1271  D3DKMTQueryResourceInfoFromNtHandle  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#4) */

void D3DKMTQueryResourceInfoFromNtHandle(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTQueryStatistics @ 18002b528 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1debb  1272  D3DKMTQueryStatistics  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#39) */

void D3DKMTQueryStatistics(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTQueryVidPnExclusiveOwnership @ 18002b530 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1df05  1273  D3DKMTQueryVidPnExclusiveOwnership  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#122) */

void D3DKMTQueryVidPnExclusiveOwnership(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTQueryVideoMemoryInfo @ 18002b538 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1df48  1274  D3DKMTQueryVideoMemoryInfo  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#131)
    */

void D3DKMTQueryVideoMemoryInfo(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTReclaimAllocations @ 18002b540 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1df89  1275  D3DKMTReclaimAllocations  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#81) */

void D3DKMTReclaimAllocations(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTReclaimAllocations2 @ 18002b548 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1dfca  1276  D3DKMTReclaimAllocations2  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#121)
    */

void D3DKMTReclaimAllocations2(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTRegisterTrimNotification @ 18002b550 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1e011  1277  D3DKMTRegisterTrimNotification  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#133) */

void D3DKMTRegisterTrimNotification(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTRegisterVailProcess @ 18002b558 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1e053  1278  D3DKMTRegisterVailProcess  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#198)
    */

void D3DKMTRegisterVailProcess(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTReleaseKeyedMutex @ 18002b560 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1e093  1279  D3DKMTReleaseKeyedMutex  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#75) */

void D3DKMTReleaseKeyedMutex(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTReleaseKeyedMutex2 @ 18002b568 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1e0d3  1280  D3DKMTReleaseKeyedMutex2  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#76) */

void D3DKMTReleaseKeyedMutex2(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTReleaseProcessVidPnSourceOwners @ 18002b570 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1e120  1281  D3DKMTReleaseProcessVidPnSourceOwners  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#55) */

void D3DKMTReleaseProcessVidPnSourceOwners(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTReleaseSwapChain @ 18002b578 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1e15e  1282  D3DKMTReleaseSwapChain  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#152) */

void D3DKMTReleaseSwapChain(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTRemoveSurfaceFromSwapChain @ 18002b580 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1e1a7  1283  D3DKMTRemoveSurfaceFromSwapChain  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#195) */

void D3DKMTRemoveSurfaceFromSwapChain(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTRender @ 18002b588 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1e1dc  1284  D3DKMTRender  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#32) */

void D3DKMTRender(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTReserveGpuVirtualAddress @ 18002b590 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1e222  1285  D3DKMTReserveGpuVirtualAddress  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#115) */

void D3DKMTReserveGpuVirtualAddress(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTResetTrackedWorkloadStatistics @ 18002b598 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1e26f  1286  D3DKMTResetTrackedWorkloadStatistics  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#213) */

void D3DKMTResetTrackedWorkloadStatistics(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTSetAllocationPriority @ 18002b5a0 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1e2b3  1287  D3DKMTSetAllocationPriority  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#12)
    */

void D3DKMTSetAllocationPriority(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTSetContextInProcessSchedulingPriority @ 18002b5a8 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1e306  1288  D3DKMTSetContextInProcessSchedulingPriority  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#205) */

void D3DKMTSetContextInProcessSchedulingPriority(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTSetContextSchedulingPriority @ 18002b5b0 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1e351  1289  D3DKMTSetContextSchedulingPriority  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#51) */

void D3DKMTSetContextSchedulingPriority(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTSetDisplayMode @ 18002b5b8 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1e38d  1290  D3DKMTSetDisplayMode  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#29) */

void D3DKMTSetDisplayMode(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTSetDisplayPrivateDriverFormat @ 18002b5c0 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1e3d8  1291  D3DKMTSetDisplayPrivateDriverFormat  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#65) */

void D3DKMTSetDisplayPrivateDriverFormat(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTSetDodIndirectSwapchain @ 18002b5c8 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1e41d  1292  D3DKMTSetDodIndirectSwapchain  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#155) */

void D3DKMTSetDodIndirectSwapchain(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTSetFSEBlock @ 18002b5d0 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1e457  1293  D3DKMTSetFSEBlock  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#156) */

void D3DKMTSetFSEBlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTSetGammaRamp @ 18002b5d8 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1e492  1294  D3DKMTSetGammaRamp  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#48) */

void D3DKMTSetGammaRamp(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTSetHwProtectionTeardownRecovery @ 18002b5e0 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1e4df  1295  D3DKMTSetHwProtectionTeardownRecovery  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#128) */

void D3DKMTSetHwProtectionTeardownRecovery(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTSetMemoryBudgetTarget @ 18002b5e8 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1e523  1296  D3DKMTSetMemoryBudgetTarget  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#174) */

void D3DKMTSetMemoryBudgetTarget(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTSetMonitorColorSpaceTransform @ 18002b5f0 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1e56f  1297  D3DKMTSetMonitorColorSpaceTransform  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#183) */

void D3DKMTSetMonitorColorSpaceTransform(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTSetProcessDeviceRemovalSupport @ 18002b5f8 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1e5bc  1298  D3DKMTSetProcessDeviceRemovalSupport  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#191) */

void D3DKMTSetProcessDeviceRemovalSupport(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTSetProcessSchedulingPriorityBand @ 18002b600 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1e60b  1299  D3DKMTSetProcessSchedulingPriorityBand  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#173) */

void D3DKMTSetProcessSchedulingPriorityBand(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTSetProcessSchedulingPriorityClass @ 18002b608 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1e65b  1300  D3DKMTSetProcessSchedulingPriorityClass  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#53) */

void D3DKMTSetProcessSchedulingPriorityClass(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTSetProperties @ 18002b610 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1e696  1301  D3DKMTSetProperties  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#223) */

void D3DKMTSetProperties(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTSetQueuedLimit @ 18002b618 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1e6d3  1302  D3DKMTSetQueuedLimit  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#57) */

void D3DKMTSetQueuedLimit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTSetStablePowerState @ 18002b620 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1e714  1303  D3DKMTSetStablePowerState  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#141)
    */

void D3DKMTSetStablePowerState(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTSetStereoEnabled @ 18002b628 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1e753  1304  D3DKMTSetStereoEnabled  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#90) */

void D3DKMTSetStereoEnabled(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTSetSyncRefreshCountWaitTarget @ 18002b630 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1e79e  1305  D3DKMTSetSyncRefreshCountWaitTarget  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#167) */

void D3DKMTSetSyncRefreshCountWaitTarget(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTSetVidPnSourceHwProtection @ 18002b638 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1e7e7  1306  D3DKMTSetVidPnSourceHwProtection  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#125) */

void D3DKMTSetVidPnSourceHwProtection(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTSetVidPnSourceOwner @ 18002b640 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1e829  1307  D3DKMTSetVidPnSourceOwner  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#40)
    */

void D3DKMTSetVidPnSourceOwner(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTSetVidPnSourceOwner1 @ 18002b648 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1e86b  1308  D3DKMTSetVidPnSourceOwner1  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#165)
    */

void D3DKMTSetVidPnSourceOwner1(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTSetVidPnSourceOwner2 @ 18002b650 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1e8ae  1309  D3DKMTSetVidPnSourceOwner2  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#182)
    */

void D3DKMTSetVidPnSourceOwner2(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTSetYieldPercentage @ 18002b658 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1e8ef  1310  D3DKMTSetYieldPercentage  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#172)
    */

void D3DKMTSetYieldPercentage(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTShareObjects @ 18002b660 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1e92a  1311  D3DKMTShareObjects  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#5) */

void D3DKMTShareObjects(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTSharedPrimaryLockNotification @ 18002b668 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1e974  1312  D3DKMTSharedPrimaryLockNotification  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#66) */

void D3DKMTSharedPrimaryLockNotification(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTSharedPrimaryUnLockNotification @ 18002b670 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1e9c1  1313  D3DKMTSharedPrimaryUnLockNotification  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#67) */

void D3DKMTSharedPrimaryUnLockNotification(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTSignalSynchronizationObject @ 18002b678 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1ea0a  1314  D3DKMTSignalSynchronizationObject  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#24) */

void D3DKMTSignalSynchronizationObject(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTSignalSynchronizationObject2 @ 18002b680 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1ea54  1315  D3DKMTSignalSynchronizationObject2  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#25) */

void D3DKMTSignalSynchronizationObject2(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTSignalSynchronizationObjectFromCpu @ 18002b688 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1eaa4  1316  D3DKMTSignalSynchronizationObjectFromCpu  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#105) */

void D3DKMTSignalSynchronizationObjectFromCpu(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTSignalSynchronizationObjectFromGpu @ 18002b690 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1eaf5  1317  D3DKMTSignalSynchronizationObjectFromGpu  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#107) */

void D3DKMTSignalSynchronizationObjectFromGpu(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTSignalSynchronizationObjectFromGpu2 @ 18002b698 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1eb47  1318  D3DKMTSignalSynchronizationObjectFromGpu2  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#108) */

void D3DKMTSignalSynchronizationObjectFromGpu2(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTSubmitCommand @ 18002b6a0 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1eb83  1319  D3DKMTSubmitCommand  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#120) */

void D3DKMTSubmitCommand(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTSubmitCommandToHwQueue @ 18002b6a8 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1ebc8  1320  D3DKMTSubmitCommandToHwQueue  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#162) */

void D3DKMTSubmitCommandToHwQueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTSubmitPresentBltToHwQueue @ 18002b6b0 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1ec10  1321  D3DKMTSubmitPresentBltToHwQueue  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#202) */

void D3DKMTSubmitPresentBltToHwQueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTSubmitPresentToHwQueue @ 18002b6b8 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1ec55  1322  D3DKMTSubmitPresentToHwQueue  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#206) */

void D3DKMTSubmitPresentToHwQueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTSubmitSignalSyncObjectsToHwQueue @ 18002b6c0 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1eca4  1323  D3DKMTSubmitSignalSyncObjectsToHwQueue  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#164) */

void D3DKMTSubmitSignalSyncObjectsToHwQueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTSubmitWaitForSyncObjectsToHwQueue @ 18002b6c8 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1ecf4  1324  D3DKMTSubmitWaitForSyncObjectsToHwQueue  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#163) */

void D3DKMTSubmitWaitForSyncObjectsToHwQueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTTrimProcessCommitment @ 18002b6d0 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1ed38  1325  D3DKMTTrimProcessCommitment  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#146) */

void D3DKMTTrimProcessCommitment(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTUnOrderedPresentSwapChain @ 18002b6d8 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1ed80  1326  D3DKMTUnOrderedPresentSwapChain  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#196) */

void D3DKMTUnOrderedPresentSwapChain(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTUnlock @ 18002b6e0 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1edb5  1327  D3DKMTUnlock  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#27) */

void D3DKMTUnlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTUnlock2 @ 18002b6e8 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1edea  1328  D3DKMTUnlock2  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#112) */

void D3DKMTUnlock2(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTUnpinDirectFlipResources @ 18002b6f0 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1ee31  1329  D3DKMTUnpinDirectFlipResources  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#136) */

void D3DKMTUnpinDirectFlipResources(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTUnpinResources @ 18002b6f8 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1ee6e  1330  D3DKMTUnpinResources  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#221) */

void D3DKMTUnpinResources(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTUnregisterTrimNotification @ 18002b700 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1eeb7  1331  D3DKMTUnregisterTrimNotification  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#134) */

void D3DKMTUnregisterTrimNotification(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTUpdateAllocationProperty @ 18002b708 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1eefe  1332  D3DKMTUpdateAllocationProperty  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#103) */

void D3DKMTUpdateAllocationProperty(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTUpdateGpuVirtualAddress @ 18002b710 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1ef44  1333  D3DKMTUpdateGpuVirtualAddress  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#117) */

void D3DKMTUpdateGpuVirtualAddress(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTUpdateOverlay @ 18002b718 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1ef80  1334  D3DKMTUpdateOverlay  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#44) */

void D3DKMTUpdateOverlay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTUpdateTrackedWorkload @ 18002b720 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1efc3  1335  D3DKMTUpdateTrackedWorkload  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#210) */

void D3DKMTUpdateTrackedWorkload(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTVailConnect @ 18002b728 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1effd  1336  D3DKMTVailConnect  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#199) */

void D3DKMTVailConnect(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTVailDisconnect @ 18002b730 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1f03a  1337  D3DKMTVailDisconnect  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#200) */

void D3DKMTVailDisconnect(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTVailPromoteCompositionSurface @ 18002b738 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1f086  1338  D3DKMTVailPromoteCompositionSurface  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#201) */

void D3DKMTVailPromoteCompositionSurface(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTWaitForIdle @ 18002b740 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1f0c0  1339  D3DKMTWaitForIdle  (forwarder -> ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#61) */

void D3DKMTWaitForIdle(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTWaitForSynchronizationObject @ 18002b748 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1f10a  1340  D3DKMTWaitForSynchronizationObject  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#22) */

void D3DKMTWaitForSynchronizationObject(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTWaitForSynchronizationObject2 @ 18002b750 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1f155  1341  D3DKMTWaitForSynchronizationObject2  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#23) */

void D3DKMTWaitForSynchronizationObject2(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTWaitForSynchronizationObjectFromCpu @ 18002b758 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1f1a6  1342  D3DKMTWaitForSynchronizationObjectFromCpu  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#104) */

void D3DKMTWaitForSynchronizationObjectFromCpu(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTWaitForSynchronizationObjectFromGpu @ 18002b760 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1f1f8  1343  D3DKMTWaitForSynchronizationObjectFromGpu  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#106) */

void D3DKMTWaitForSynchronizationObjectFromGpu(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTWaitForVerticalBlankEvent @ 18002b768 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1f240  1344  D3DKMTWaitForVerticalBlankEvent  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#47) */

void D3DKMTWaitForVerticalBlankEvent(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== D3DKMTWaitForVerticalBlankEvent2 @ 18002b770 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1f288  1345  D3DKMTWaitForVerticalBlankEvent2  (forwarder ->
   ext-ms-win-dx-d3dkmt-dxcore-l1-1-5.#166) */

void D3DKMTWaitForVerticalBlankEvent2(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== DeviceCapabilitiesExW @ 18002b778 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x1f6a2  1423  DeviceCapabilitiesExW  (forwarder ->
   ext-ms-win-gdi-desktop-l1-1-0.DeviceCapabilitiesExA) */

void DeviceCapabilitiesExW(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== LpkDrawTextEx @ 18002b780 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x20e86  1782  LpkDrawTextEx  (forwarder -> ext-ms-win-gdi-internal-desktop-l1-1-0.LpkDrawTextEx)
    */

void LpkDrawTextEx(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== LpkExtTextOut @ 18002b788 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x20ed8  1784  LpkExtTextOut  (forwarder -> ext-ms-win-gdi-internal-desktop-l1-1-0.LpkExtTextOut)
    */

void LpkExtTextOut(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== LpkGetCharacterPlacement @ 18002b790 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x20f26  1785  LpkGetCharacterPlacement  (forwarder ->
   ext-ms-win-gdi-internal-desktop-l1-1-0.LpkGetCharacterPlacement) */

void LpkGetCharacterPlacement(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== LpkGetTextExtentExPoint @ 18002b798 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x20f90  1787  LpkGetTextExtentExPoint  (forwarder ->
   ext-ms-win-gdi-internal-desktop-l1-1-0.LpkGetTextExtentExPoint) */

void LpkGetTextExtentExPoint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== LpkInitialize @ 18002b7a0 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x20fdd  1788  LpkInitialize  (forwarder -> ext-ms-win-gdi-internal-desktop-l1-1-0.LpkInitialize)
    */

void LpkInitialize(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== LpkPSMTextOut @ 18002b7a8 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x21020  1789  LpkPSMTextOut  (forwarder -> ext-ms-win-gdi-internal-desktop-l1-1-0.LpkPSMTextOut)
    */

void LpkPSMTextOut(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== LpkPresent @ 18002b7b0 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x21060  1790  LpkPresent  (forwarder -> ext-ms-win-gdi-internal-desktop-l1-1-0.LpkPresent) */

void LpkPresent(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== LpkTabbedTextOut @ 18002b7b8 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x210a3  1791  LpkTabbedTextOut  (forwarder ->
   ext-ms-win-gdi-internal-desktop-l1-1-0.LpkTabbedTextOut) */

void LpkTabbedTextOut(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== LpkUseGDIWidthCache @ 18002b7c0 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x210ef  1792  LpkUseGDIWidthCache  (forwarder ->
   ext-ms-win-gdi-internal-desktop-l1-1-0.LpkUseGDIWidthCache) */

void LpkUseGDIWidthCache(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== ScriptApplyDigitSubstitution @ 18002b7c8 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x21536  1860  ScriptApplyDigitSubstitution  (forwarder ->
   ext-ms-win-gdi-internal-desktop-l1-1-0.ScriptApplyDigitSubstitution) */

void ScriptApplyDigitSubstitution(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== ScriptApplyLogicalWidth @ 18002b7d0 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x21592  1861  ScriptApplyLogicalWidth  (forwarder ->
   ext-ms-win-gdi-internal-desktop-l1-1-0.ScriptApplyLogicalWidth) */

void ScriptApplyLogicalWidth(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== ScriptBreak @ 18002b7d8 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x215dd  1862  ScriptBreak  (forwarder -> ext-ms-win-usp10-l1-1-0.ScriptBreak) */

void ScriptBreak(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== ScriptCPtoX @ 18002b7e0 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x2160d  1863  ScriptCPtoX  (forwarder -> ext-ms-win-gdi-internal-desktop-l1-1-0.ScriptCPtoX) */

void ScriptCPtoX(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== ScriptCacheGetHeight @ 18002b7e8 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x21655  1864  ScriptCacheGetHeight  (forwarder ->
   ext-ms-win-gdi-internal-desktop-l1-1-0.ScriptCacheGetHeight) */

void ScriptCacheGetHeight(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== ScriptFreeCache @ 18002b7f0 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x216a1  1865  ScriptFreeCache  (forwarder -> ext-ms-win-usp10-l1-1-0.ScriptFreeCache) */

void ScriptFreeCache(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== ScriptGetCMap @ 18002b7f8 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x216d7  1866  ScriptGetCMap  (forwarder -> ext-ms-win-usp10-l1-1-0.ScriptGetCMap) */

void ScriptGetCMap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== ScriptGetFontAlternateGlyphs @ 18002b800 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x2171a  1867  ScriptGetFontAlternateGlyphs  (forwarder ->
   ext-ms-win-gdi-internal-desktop-l1-1-0.ScriptGetFontAlternateGlyphs) */

void ScriptGetFontAlternateGlyphs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== ScriptGetFontFeatureTags @ 18002b808 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x21777  1868  ScriptGetFontFeatureTags  (forwarder ->
   ext-ms-win-gdi-internal-desktop-l1-1-0.ScriptGetFontFeatureTags) */

void ScriptGetFontFeatureTags(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== ScriptGetFontLanguageTags @ 18002b810 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x217d1  1869  ScriptGetFontLanguageTags  (forwarder ->
   ext-ms-win-gdi-internal-desktop-l1-1-0.ScriptGetFontLanguageTags) */

void ScriptGetFontLanguageTags(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== ScriptGetFontProperties @ 18002b818 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x2182a  1870  ScriptGetFontProperties  (forwarder ->
   ext-ms-win-gdi-internal-desktop-l1-1-0.ScriptGetFontProperties) */

void ScriptGetFontProperties(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== ScriptGetFontScriptTags @ 18002b820 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x21881  1871  ScriptGetFontScriptTags  (forwarder ->
   ext-ms-win-gdi-internal-desktop-l1-1-0.ScriptGetFontScriptTags) */

void ScriptGetFontScriptTags(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== ScriptGetGlyphABCWidth @ 18002b828 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x218d7  1872  ScriptGetGlyphABCWidth  (forwarder ->
   ext-ms-win-gdi-internal-desktop-l1-1-0.ScriptGetGlyphABCWidth) */

void ScriptGetGlyphABCWidth(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== ScriptGetLogicalWidths @ 18002b830 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x2192c  1873  ScriptGetLogicalWidths  (forwarder ->
   ext-ms-win-usp10-l1-1-0.ScriptGetLogicalWidths) */

void ScriptGetLogicalWidths(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== ScriptGetProperties @ 18002b838 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x2196f  1874  ScriptGetProperties  (forwarder -> ext-ms-win-usp10-l1-1-0.ScriptGetProperties) */

void ScriptGetProperties(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== ScriptIsComplex @ 18002b840 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x219ab  1875  ScriptIsComplex  (forwarder ->
   ext-ms-win-gdi-internal-desktop-l1-1-0.ScriptIsComplex) */

void ScriptIsComplex(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== ScriptItemize @ 18002b848 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x219f0  1876  ScriptItemize  (forwarder -> ext-ms-win-usp10-l1-1-0.ScriptItemize) */

void ScriptItemize(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== ScriptItemizeOpenType @ 18002b850 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x21a2c  1877  ScriptItemizeOpenType  (forwarder ->
   ext-ms-win-gdi-internal-desktop-l1-1-0.ScriptItemizeOpenType) */

void ScriptItemizeOpenType(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== ScriptJustify @ 18002b858 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x21a77  1878  ScriptJustify  (forwarder -> ext-ms-win-gdi-internal-desktop-l1-1-0.ScriptJustify)
    */

void ScriptJustify(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== ScriptLayout @ 18002b860 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x21ab9  1879  ScriptLayout  (forwarder -> ext-ms-win-gdi-internal-desktop-l1-1-0.ScriptLayout)
    */

void ScriptLayout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== ScriptPlace @ 18002b868 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x21af9  1880  ScriptPlace  (forwarder -> ext-ms-win-usp10-l1-1-0.ScriptPlace) */

void ScriptPlace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== ScriptPlaceOpenType @ 18002b870 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x21b31  1881  ScriptPlaceOpenType  (forwarder ->
   ext-ms-win-gdi-internal-desktop-l1-1-0.ScriptPlaceOpenType) */

void ScriptPlaceOpenType(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== ScriptPositionSingleGlyph @ 18002b878 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x21b86  1882  ScriptPositionSingleGlyph  (forwarder ->
   ext-ms-win-gdi-internal-desktop-l1-1-0.ScriptPositionSingleGlyph) */

void ScriptPositionSingleGlyph(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== ScriptRecordDigitSubstitution @ 18002b880 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x21be5  1883  ScriptRecordDigitSubstitution  (forwarder ->
   ext-ms-win-gdi-internal-desktop-l1-1-0.ScriptRecordDigitSubstitution) */

void ScriptRecordDigitSubstitution(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== ScriptShape @ 18002b888 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x21c36  1884  ScriptShape  (forwarder -> ext-ms-win-usp10-l1-1-0.ScriptShape) */

void ScriptShape(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== ScriptShapeOpenType @ 18002b890 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x21c6e  1885  ScriptShapeOpenType  (forwarder ->
   ext-ms-win-gdi-internal-desktop-l1-1-0.ScriptShapeOpenType) */

void ScriptShapeOpenType(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== ScriptStringAnalyse @ 18002b898 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x21cbd  1886  ScriptStringAnalyse  (forwarder -> ext-ms-win-usp10-l1-1-0.ScriptStringAnalyse) */

void ScriptStringAnalyse(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== ScriptStringCPtoX @ 18002b8a0 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x21cfb  1887  ScriptStringCPtoX  (forwarder ->
   ext-ms-win-gdi-internal-desktop-l1-1-0.ScriptStringCPtoX) */

void ScriptStringCPtoX(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== ScriptStringFree @ 18002b8a8 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x21d45  1888  ScriptStringFree  (forwarder -> ext-ms-win-usp10-l1-1-0.ScriptStringFree) */

void ScriptStringFree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== ScriptStringGetLogicalWidths @ 18002b8b0 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x21d8b  1889  ScriptStringGetLogicalWidths  (forwarder ->
   ext-ms-win-gdi-internal-desktop-l1-1-0.ScriptStringGetLogicalWidths) */

void ScriptStringGetLogicalWidths(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== ScriptStringGetOrder @ 18002b8b8 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x21de4  1890  ScriptStringGetOrder  (forwarder ->
   ext-ms-win-gdi-internal-desktop-l1-1-0.ScriptStringGetOrder) */

void ScriptStringGetOrder(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== ScriptStringOut @ 18002b8c0 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x21e30  1891  ScriptStringOut  (forwarder ->
   ext-ms-win-gdi-internal-desktop-l1-1-0.ScriptStringOut) */

void ScriptStringOut(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== ScriptStringValidate @ 18002b8c8 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x21e7c  1892  ScriptStringValidate  (forwarder -> ext-ms-win-usp10-l1-1-0.ScriptStringValidate)
    */

void ScriptStringValidate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== ScriptStringXtoCP @ 18002b8d0 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x21ebb  1893  ScriptStringXtoCP  (forwarder ->
   ext-ms-win-gdi-internal-desktop-l1-1-0.ScriptStringXtoCP) */

void ScriptStringXtoCP(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== ScriptString_pLogAttr @ 18002b8d8 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x21f0a  1894  ScriptString_pLogAttr  (forwarder ->
   ext-ms-win-usp10-l1-1-0.ScriptString_pLogAttr) */

void ScriptString_pLogAttr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== ScriptString_pSize @ 18002b8e0 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x21f4b  1895  ScriptString_pSize  (forwarder ->
   ext-ms-win-gdi-internal-desktop-l1-1-0.ScriptString_pSize) */

void ScriptString_pSize(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== ScriptString_pcOutChars @ 18002b8e8 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x21f9d  1896  ScriptString_pcOutChars  (forwarder ->
   ext-ms-win-gdi-internal-desktop-l1-1-0.ScriptString_pcOutChars) */

void ScriptString_pcOutChars(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== ScriptSubstituteSingleGlyph @ 18002b8f0 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x21ff8  1897  ScriptSubstituteSingleGlyph  (forwarder ->
   ext-ms-win-usp10-l1-1-0.ScriptSubstituteSingleGlyph) */

void ScriptSubstituteSingleGlyph(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== ScriptTextOut @ 18002b8f8 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x2203a  1898  ScriptTextOut  (forwarder -> ext-ms-win-usp10-l1-1-0.ScriptTextOut) */

void ScriptTextOut(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== ScriptXtoCP @ 18002b900 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x2206c  1899  ScriptXtoCP  (forwarder -> ext-ms-win-gdi-internal-desktop-l1-1-0.ScriptXtoCP) */

void ScriptXtoCP(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== UspAllocCache @ 18002b908 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x22539  1977  UspAllocCache  (forwarder -> ext-ms-win-gdi-internal-desktop-l1-1-0.UspAllocCache)
    */

void UspAllocCache(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== UspAllocTemp @ 18002b910 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x2257b  1978  UspAllocTemp  (forwarder -> ext-ms-win-gdi-internal-desktop-l1-1-0.UspAllocTemp)
    */

void UspAllocTemp(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== UspFreeMem @ 18002b918 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x225ba  1979  UspFreeMem  (forwarder -> ext-ms-win-gdi-internal-desktop-l1-1-0.UspFreeMem) */

void UspFreeMem(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== ftsWordBreak @ 18002b920 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x226e1  1993  ftsWordBreak  (forwarder -> ext-ms-win-gdi-internal-desktop-l1-1-0.ftsWordBreak)
    */

void ftsWordBreak(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


