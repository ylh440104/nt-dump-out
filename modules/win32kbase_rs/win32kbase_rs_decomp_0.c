
===== call_once<gdi_rust::xform::xformobj_cxx::impl$1::bXformRound_umptr_pointl_pointfx::closure_env$0,tuple$<onecore_windows::windef::_POINTL>_> @ 140001010 =====

int core::ops::function::FnOnce::
    call_once<gdi_rust::xform::xformobj_cxx::impl_1::bXformRound_umptr_pointl_pointfx::closure_env_0,tuple_<onecore_windows::windef::_POINTL>_>
              (int param_1)

{
  return param_1 << 4;
}



===== EXFORMOBJ_vInit @ 140001020 =====

void EXFORMOBJ_vInit(undefined8 *param_1,float *param_2,float param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
                    /* 0x1020  32  EXFORMOBJ_vInit */
  *param_1 = param_2;
  fVar4 = (float)((uint)param_3 & 0x38);
  if (((uint)param_3 & 1) == 0) {
    if (fVar4 != 0.0) {
      param_2[8] = param_3;
      return;
    }
  }
  else {
    param_2[8] = fVar4;
    fVar3 = fVar4;
    if (param_2[7] == 0.0 && param_2[6] == 0.0) {
      fVar3 = (float)((int)fVar4 + 0x40);
      param_2[8] = fVar3;
    }
    if (param_2[1] != 0.0) {
      return;
    }
    if (NAN(param_2[1])) {
      return;
    }
    if (param_2[2] != 0.0) {
      return;
    }
    if (NAN(param_2[2])) {
      return;
    }
    param_2[8] = (float)((uint)fVar3 | 1);
    fVar1 = *param_2;
    fVar2 = param_2[3];
    if (fVar4 == 1.12104e-44) {
      if (fVar1 != 16.0) {
        return;
      }
      if (NAN(fVar1)) {
        return;
      }
      if (fVar2 != 16.0) {
        return;
      }
    }
    else {
      if (fVar4 == 4.48416e-44) {
        if (fVar1 != 1.0) {
          return;
        }
        if (NAN(fVar1)) {
          return;
        }
        if (fVar2 != 1.0) {
          return;
        }
        if (NAN(fVar2)) {
          return;
        }
        goto LAB_1400010c9;
      }
      if (fVar1 != 0.0625) {
        return;
      }
      if (NAN(fVar1)) {
        return;
      }
      if (fVar2 != 0.0625) {
        return;
      }
    }
    if (!NAN(fVar2)) {
LAB_1400010c9:
      param_2[8] = (float)((uint)fVar3 | 3);
      return;
    }
  }
  return;
}



===== EXFORMOBJ_vComputeWtoDAccelFlags @ 1400010e0 =====

void EXFORMOBJ_vComputeWtoDAccelFlags(undefined8 *param_1)

{
  float *pfVar1;
  float fVar2;
  
                    /* 0x10e0  29  EXFORMOBJ_vComputeWtoDAccelFlags */
  pfVar1 = (float *)*param_1;
  if (pfVar1 == (float *)0x0) {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core6option13unwrap_failed();
  }
  fVar2 = (float)((uint)(pfVar1[7] == 0.0 && pfVar1[6] == 0.0) << 6 | 8);
  if ((((pfVar1[1] == 0.0) && (!NAN(pfVar1[1]))) && (pfVar1[2] == 0.0)) && (!NAN(pfVar1[2]))) {
    fVar2 = (float)((-(uint)(*pfVar1 == 16.0 && pfVar1[3] == 16.0) & 1) * 2 | (uint)fVar2 | 1);
  }
  pfVar1[8] = fVar2;
  return;
}



===== EXFORMOBJ_bValid @ 140001160 =====

bool EXFORMOBJ_bValid(longlong *param_1)

{
                    /* 0x1160  16  EXFORMOBJ_bValid */
  return *param_1 != 0;
}



===== EXFORMOBJ_vSetElementsLToL @ 140001170 =====

void EXFORMOBJ_vSetElementsLToL
               (undefined8 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
               undefined4 *param_5)

{
  undefined4 *puVar1;
  
                    /* 0x1170  37  EXFORMOBJ_vSetElementsLToL */
  puVar1 = (undefined4 *)*param_1;
  if (puVar1 == (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core6option13unwrap_failed();
  }
  *puVar1 = *param_2;
  puVar1[1] = *param_3;
  puVar1[2] = *param_4;
  puVar1[3] = *param_5;
  return;
}



===== EXFORMOBJ_vSetElementsLToFx @ 1400011c0 =====

void EXFORMOBJ_vSetElementsLToFx
               (longlong *param_1,float param_2,float param_3,float param_4,float param_5)

{
  float *pfVar1;
  
                    /* 0x11c0  36  EXFORMOBJ_vSetElementsLToFx */
  pfVar1 = (float *)*param_1;
  if (pfVar1 == (float *)0x0) {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core6option13unwrap_failed();
  }
  *pfVar1 = param_2 * 16.0;
  pfVar1[1] = param_3 * 16.0;
  pfVar1[2] = param_4 * 16.0;
  pfVar1[3] = param_5 * 16.0;
  return;
}



===== EXFORMOBJ_bScale @ 140001200 =====

byte EXFORMOBJ_bScale(longlong *param_1)

{
                    /* 0x1200  14  EXFORMOBJ_bScale */
  if (*param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core6option13unwrap_failed();
  }
  return *(byte *)(*param_1 + 0x20) & 1;
}



===== EXFORMOBJ_bRotation @ 140001230 =====

undefined8 EXFORMOBJ_bRotation(longlong *param_1)

{
  longlong lVar1;
  
                    /* 0x1230  13  EXFORMOBJ_bRotation */
  lVar1 = *param_1;
  if (lVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core6option13unwrap_failed();
  }
  return CONCAT71((int7)((ulonglong)lVar1 >> 8),(*(byte *)(lVar1 + 0x20) & 1) == 0);
}



===== EXFORMOBJ_bMirroring @ 140001260 =====

ulonglong EXFORMOBJ_bMirroring(undefined8 *param_1)

{
  int *piVar1;
  
                    /* 0x1260  10  EXFORMOBJ_bMirroring */
  piVar1 = (int *)*param_1;
  if (piVar1 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core6option13unwrap_failed();
  }
  if (*piVar1 < 0) {
    return CONCAT71((int7)((ulonglong)piVar1 >> 8),1);
  }
  return (ulonglong)((uint)piVar1[3] >> 0x1f);
}



===== EXFORMOBJ_bNoTranslation @ 1400012a0 =====

byte EXFORMOBJ_bNoTranslation(longlong *param_1)

{
                    /* 0x12a0  12  EXFORMOBJ_bNoTranslation */
  if (*param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core6option13unwrap_failed();
  }
  return (*(byte *)(*param_1 + 0x20) & 0x40) >> 6;
}



===== EXFORMOBJ_bIdentity @ 1400012d0 =====

undefined4 EXFORMOBJ_bIdentity(longlong *param_1)

{
  uint uVar1;
  
                    /* 0x12d0  8  EXFORMOBJ_bIdentity */
  if (*param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core6option13unwrap_failed();
  }
  uVar1 = ~*(uint *)(*param_1 + 0x20);
  return CONCAT31((int3)(uVar1 >> 8),(uVar1 & 0x43) == 0);
}



===== EXFORMOBJ_bTranslationsOnly @ 140001300 =====

byte EXFORMOBJ_bTranslationsOnly(longlong *param_1)

{
                    /* 0x1300  15  EXFORMOBJ_bTranslationsOnly */
  if (*param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core6option13unwrap_failed();
  }
  return (*(byte *)(*param_1 + 0x20) & 2) >> 1;
}



===== EXFORMOBJ_bConformal @ 140001330 =====

byte EXFORMOBJ_bConformal(undefined8 *param_1)

{
  float *pfVar1;
  
                    /* 0x1330  5  EXFORMOBJ_bConformal */
  pfVar1 = (float *)*param_1;
  if (pfVar1 == (float *)0x0) {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core6option13unwrap_failed();
  }
  if ((*pfVar1 == pfVar1[3]) && (!NAN(*pfVar1) && !NAN(pfVar1[3]))) {
    return -(-pfVar1[2] == pfVar1[1]) & 1;
  }
  return 0;
}



===== EXFORMOBJ_bXform_pointl @ 140001380 =====

undefined8 EXFORMOBJ_bXform_pointl(undefined8 *param_1,int *param_2,longlong param_3)

{
  float *pfVar1;
  undefined8 uVar2;
  
                    /* 0x1380  18  EXFORMOBJ_bXform_pointl */
  pfVar1 = (float *)*param_1;
  if (pfVar1 == (float *)0x0) {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core6option13unwrap_failed();
  }
  if ((~(uint)pfVar1[8] & 0x43) == 0) {
    return CONCAT71((uint7)(uint3)(~(uint)pfVar1[8] >> 8),1);
  }
  uVar2 = _RNvNtNtCsdyToaWEq7tk_8gdi_rust5xform7xformer8bCvtPts1(pfVar1,param_2,param_3);
  return uVar2;
}



===== EXFORMOBJ_bXform_vectorfl @ 1400013c0 =====

void EXFORMOBJ_bXform_vectorfl(undefined8 *param_1,void *param_2,ulonglong param_3)

{
                    /* 0x13c0  21  EXFORMOBJ_bXform_vectorfl */
  _RNvMNtNtCsdyToaWEq7tk_8gdi_rust5xform12xformobj_cxxNtNtB4_10xformobj_h9EXFORMOBJ24bXform_vectorfl_vectorfl
            (param_1,param_2,param_3,param_2,param_3);
  return;
}



===== EXFORMOBJ_vSetScaling @ 1400013e0 =====

void EXFORMOBJ_vSetScaling(undefined8 *param_1,float *param_2,float *param_3,uint param_4)

{
  float fVar1;
  float fVar2;
  float *pfVar3;
  float fVar4;
  float fVar5;
  bool bVar6;
  
                    /* 0x13e0  38  EXFORMOBJ_vSetScaling */
  pfVar3 = (float *)*param_1;
  if (pfVar3 == (float *)0x0) {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core6option13unwrap_failed();
  }
  fVar1 = *param_2;
  *pfVar3 = fVar1;
  fVar2 = *param_3;
  pfVar3[3] = fVar2;
  if ((param_4 & 1) != 0) {
    fVar5 = (float)(param_4 & 0x38);
    pfVar3[8] = fVar5;
    fVar4 = fVar5;
    if ((pfVar3[6] == 0.0) && (pfVar3[7] == 0.0)) {
      fVar4 = (float)((int)fVar5 + 0x40);
      pfVar3[8] = fVar4;
    }
    if ((((pfVar3[1] == 0.0) && (!NAN(pfVar3[1]))) && (pfVar3[2] == 0.0)) && (!NAN(pfVar3[2]))) {
      pfVar3[8] = (float)((uint)fVar4 | 1);
      if (fVar5 == 1.12104e-44) {
        if (fVar1 != 16.0) {
          return;
        }
        if (NAN(fVar1)) {
          return;
        }
        bVar6 = fVar2 == 16.0;
      }
      else if (fVar5 == 4.48416e-44) {
        if (fVar1 != 1.0) {
          return;
        }
        if (NAN(fVar1)) {
          return;
        }
        bVar6 = fVar2 == 1.0;
      }
      else {
        if (fVar1 != 0.0625) {
          return;
        }
        if (NAN(fVar1)) {
          return;
        }
        bVar6 = fVar2 == 0.0625;
      }
      if ((bVar6) && (!NAN(fVar2))) {
        pfVar3[8] = (float)((uint)fVar4 | 3);
      }
    }
  }
  return;
}



===== EXFORMOBJ_vSetTranslations @ 1400014c0 =====

void EXFORMOBJ_vSetTranslations(longlong *param_1,uint *param_2,uint *param_3)

{
  longlong lVar1;
  int iVar2;
  
                    /* 0x14c0  39  EXFORMOBJ_vSetTranslations */
  iVar2 = _RNvNtCslMg0IV26qJh_12gdi_bindings6efloat14bEfToL_or_zero(*param_2);
  lVar1 = *param_1;
  if (lVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core6option13unwrap_failed();
  }
  *(int *)(lVar1 + 0x18) = iVar2;
  iVar2 = _RNvNtCslMg0IV26qJh_12gdi_bindings6efloat14bEfToL_or_zero(*param_3);
  *(int *)(lVar1 + 0x1c) = iVar2;
  *(uint *)(lVar1 + 0x20) =
       (uint)(iVar2 == 0 && *(int *)(lVar1 + 0x18) == 0) << 6 | *(uint *)(lVar1 + 0x20) & 0xffffffbf
  ;
  return;
}



===== EXFORMOBJ_vSet @ 140001520 =====

void EXFORMOBJ_vSet(undefined8 *param_1,float *param_2,uint param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
                    /* 0x1520  35  EXFORMOBJ_vSet */
  *param_1 = param_2;
  if ((param_3 & 1) != 0) {
    fVar4 = (float)(param_3 & 0x38);
    param_2[8] = fVar4;
    fVar3 = fVar4;
    if (param_2[7] == 0.0 && param_2[6] == 0.0) {
      fVar3 = (float)((int)fVar4 + 0x40);
      param_2[8] = fVar3;
    }
    if (param_2[1] != 0.0) {
      return;
    }
    if (NAN(param_2[1])) {
      return;
    }
    if (param_2[2] != 0.0) {
      return;
    }
    if (NAN(param_2[2])) {
      return;
    }
    param_2[8] = (float)((uint)fVar3 | 1);
    fVar1 = *param_2;
    fVar2 = param_2[3];
    if (fVar4 == 1.12104e-44) {
      if (fVar1 != 16.0) {
        return;
      }
      if (NAN(fVar1)) {
        return;
      }
      if (fVar2 != 16.0) {
        return;
      }
    }
    else {
      if (fVar4 != 4.48416e-44) {
        if (fVar1 != 0.0625) {
          return;
        }
        if (NAN(fVar1)) {
          return;
        }
        if (fVar2 != 0.0625) {
          return;
        }
        if (NAN(fVar2)) {
          return;
        }
        goto LAB_1400015d5;
      }
      if (fVar1 != 1.0) {
        return;
      }
      if (NAN(fVar1)) {
        return;
      }
      if (fVar2 != 1.0) {
        return;
      }
    }
    if (!NAN(fVar2)) {
LAB_1400015d5:
      param_2[8] = (float)((uint)fVar3 | 3);
      return;
    }
  }
  return;
}



===== EXFORMOBJ_fxFastX @ 1400015f0 =====

int EXFORMOBJ_fxFastX(undefined8 *param_1,int param_2)

{
  float *pfVar1;
  int iVar2;
  
                    /* 0x15f0  26  EXFORMOBJ_fxFastX */
  pfVar1 = (float *)*param_1;
  if (pfVar1 == (float *)0x0) {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core6option13unwrap_failed();
  }
  iVar2 = _RNvNtCslMg0IV26qJh_12gdi_bindings4math13lCvtWithRound(*pfVar1,param_2);
  return iVar2 + (int)pfVar1[6];
}



===== EXFORMOBJ_fxFastY @ 140001630 =====

int EXFORMOBJ_fxFastY(longlong *param_1,int param_2)

{
  longlong lVar1;
  int iVar2;
  
                    /* 0x1630  27  EXFORMOBJ_fxFastY */
  lVar1 = *param_1;
  if (lVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core6option13unwrap_failed();
  }
  iVar2 = _RNvNtCslMg0IV26qJh_12gdi_bindings4math13lCvtWithRound(*(float *)(lVar1 + 0xc),param_2);
  return iVar2 + *(int *)(lVar1 + 0x1c);
}



===== EXFORMOBJ_bEqual @ 140001670 =====

byte EXFORMOBJ_bEqual(undefined8 *param_1,undefined8 *param_2)

{
  float *pfVar1;
  float *pfVar2;
  
                    /* 0x1670  6  EXFORMOBJ_bEqual */
  pfVar1 = (float *)*param_1;
  if ((pfVar1 == (float *)0x0) || (pfVar2 = (float *)*param_2, pfVar2 == (float *)0x0)) {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core6option13unwrap_failed();
  }
  if ((((((*pfVar1 == *pfVar2) && (!NAN(*pfVar1) && !NAN(*pfVar2))) && (pfVar1[1] == pfVar2[1])) &&
       ((!NAN(pfVar1[1]) && !NAN(pfVar2[1]) && (pfVar1[2] == pfVar2[2])))) &&
      ((!NAN(pfVar1[2]) && !NAN(pfVar2[2]) &&
       ((pfVar1[3] == pfVar2[3] && (!NAN(pfVar1[3]) && !NAN(pfVar2[3]))))))) &&
     ((pfVar1[4] == pfVar2[4] && (!NAN(pfVar1[4]) && !NAN(pfVar2[4]))))) {
    return -(pfVar2[5] == pfVar1[5]) & 1;
  }
  return 0;
}



===== EXFORMOBJ_bEqualExceptTranslations @ 140001700 =====

byte EXFORMOBJ_bEqualExceptTranslations(undefined8 *param_1,float *param_2)

{
  float *pfVar1;
  
                    /* 0x1700  7  EXFORMOBJ_bEqualExceptTranslations */
  pfVar1 = (float *)*param_1;
  if (pfVar1 == (float *)0x0) {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core6option13unwrap_failed();
  }
  if ((((*pfVar1 == *param_2) && (!NAN(*pfVar1) && !NAN(*param_2))) && (pfVar1[1] == param_2[1])) &&
     (((!NAN(pfVar1[1]) && !NAN(param_2[1]) && (pfVar1[2] == param_2[2])) &&
      (!NAN(pfVar1[2]) && !NAN(param_2[2]))))) {
    return -(param_2[3] == pfVar1[3]) & 1;
  }
  return 0;
}



===== EXFORMOBJ_bXform_pointl_pointl @ 140001770 =====

ulonglong EXFORMOBJ_bXform_pointl_pointl
                    (undefined8 *param_1,void *param_2,int *param_3,longlong param_4)

{
  float *pfVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  
                    /* 0x1770  20  EXFORMOBJ_bXform_pointl_pointl */
  _weak_memcpy_default___llvm_retpoline_r11(param_3,param_2,param_4 * 8);
  pfVar1 = (float *)*param_1;
  if (pfVar1 == (float *)0x0) {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core6option13unwrap_failed();
  }
  uVar3 = CONCAT71((int7)((ulonglong)param_1 >> 8),1);
  if ((~(uint)pfVar1[8] & 0x43) != 0) {
    uVar2 = _RNvNtNtCsdyToaWEq7tk_8gdi_rust5xform7xformer8bCvtPts1(pfVar1,param_3,param_4);
    if ((char)uVar2 == '\0') {
      EngSetLastError(0x216);
      uVar3 = 0;
    }
  }
  return uVar3 & 0xffffffff;
}



===== EXFORMOBJ_bXform_pointl_pointfx @ 1400017e0 =====

void EXFORMOBJ_bXform_pointl_pointfx
               (undefined8 *param_1,longlong param_2,longlong param_3,ulonglong param_4)

{
                    /* 0x17e0  19  EXFORMOBJ_bXform_pointl_pointfx */
  _RNvMNtNtCsdyToaWEq7tk_8gdi_rust5xform12xformobj_cxxNtNtB4_10xformobj_h9EXFORMOBJ21bXform_pointl_pointfx
            (param_1,param_2,param_4,param_3,param_4);
  return;
}



===== EXFORMOBJ_bXform_pointfx_pointl @ 140001810 =====

void EXFORMOBJ_bXform_pointfx_pointl
               (undefined8 *param_1,longlong param_2,longlong param_3,ulonglong param_4)

{
                    /* 0x1810  17  EXFORMOBJ_bXform_pointfx_pointl */
  _RNvMNtNtCsdyToaWEq7tk_8gdi_rust5xform12xformobj_cxxNtNtB4_10xformobj_h9EXFORMOBJ21bXform_pointfx_pointl
            (param_1,param_2,param_4,param_3,param_4);
  return;
}



===== EXFORMOBJ_bXform_vectorfl_vectorfl @ 140001840 =====

void EXFORMOBJ_bXform_vectorfl_vectorfl
               (undefined8 *param_1,void *param_2,void *param_3,ulonglong param_4)

{
                    /* 0x1840  22  EXFORMOBJ_bXform_vectorfl_vectorfl */
  _RNvMNtNtCsdyToaWEq7tk_8gdi_rust5xform12xformobj_cxxNtNtB4_10xformobj_h9EXFORMOBJ24bXform_vectorfl_vectorfl
            (param_1,param_2,param_4,param_3,param_4);
  return;
}



===== EXFORMOBJ_bXform_vectorl_vectorl @ 140001870 =====

void EXFORMOBJ_bXform_vectorl_vectorl
               (longlong *param_1,void *param_2,void *param_3,longlong param_4)

{
                    /* 0x1870  25  EXFORMOBJ_bXform_vectorl_vectorl */
  _RNvMNtNtCsdyToaWEq7tk_8gdi_rust5xform12xformobj_cxxNtNtB4_10xformobj_h9EXFORMOBJ22bXform_vectorl_vectorl
            (param_1,param_2,param_4,param_3,param_4);
  return;
}



===== EXFORMOBJ_bXform_vectorl_vectorfx @ 1400018a0 =====

void EXFORMOBJ_bXform_vectorl_vectorfx
               (undefined8 *param_1,longlong param_2,longlong param_3,longlong param_4)

{
                    /* 0x18a0  24  EXFORMOBJ_bXform_vectorl_vectorfx */
  _RNvMNtNtCsdyToaWEq7tk_8gdi_rust5xform12xformobj_cxxNtNtB4_10xformobj_h9EXFORMOBJ23bXform_vectorl_vectorfx
            (param_1,param_2,param_4,param_3,param_4);
  return;
}



===== EXFORMOBJ_bXform_vectorfx_vectorl @ 1400018d0 =====

void EXFORMOBJ_bXform_vectorfx_vectorl
               (undefined8 *param_1,longlong param_2,longlong param_3,ulonglong param_4)

{
                    /* 0x18d0  23  EXFORMOBJ_bXform_vectorfx_vectorl */
  _RNvMNtNtCsdyToaWEq7tk_8gdi_rust5xform12xformobj_cxxNtNtB4_10xformobj_h9EXFORMOBJ23bXform_vectorfx_vectorl
            (param_1,param_2,param_4,param_3,param_4);
  return;
}



===== EXFORMOBJ_vComputeAccelFlags @ 140001900 =====

void EXFORMOBJ_vComputeAccelFlags(undefined8 *param_1,float param_2)

{
  float fVar1;
  float *pfVar2;
  float fVar3;
  
                    /* 0x1900  28  EXFORMOBJ_vComputeAccelFlags */
  pfVar2 = (float *)*param_1;
  if (pfVar2 == (float *)0x0) {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core6option13unwrap_failed();
  }
  pfVar2[8] = param_2;
  fVar3 = param_2;
  if ((pfVar2[6] == 0.0) && (pfVar2[7] == 0.0)) {
    fVar3 = (float)((uint)param_2 | 0x40);
    pfVar2[8] = fVar3;
  }
  if ((((pfVar2[1] == 0.0) && (!NAN(pfVar2[1]))) && (pfVar2[2] == 0.0)) && (!NAN(pfVar2[2]))) {
    pfVar2[8] = (float)((uint)fVar3 | 1);
    fVar1 = *pfVar2;
    if (param_2 == 1.12104e-44) {
      if (fVar1 != 16.0) {
        return;
      }
      if (NAN(fVar1)) {
        return;
      }
      fVar1 = pfVar2[3];
      if (fVar1 != 16.0) {
        return;
      }
    }
    else if (param_2 == 4.48416e-44) {
      if (fVar1 != 1.0) {
        return;
      }
      if (NAN(fVar1)) {
        return;
      }
      fVar1 = pfVar2[3];
      if (fVar1 != 1.0) {
        return;
      }
    }
    else {
      if (fVar1 != 0.0625) {
        return;
      }
      if (NAN(fVar1)) {
        return;
      }
      fVar1 = pfVar2[3];
      if (fVar1 != 0.0625) {
        return;
      }
    }
    if (!NAN(fVar1)) {
      pfVar2[8] = (float)((uint)fVar3 | 3);
      return;
    }
  }
  return;
}



===== EXFORMOBJ_vRemoveTranslation @ 1400019e0 =====

void EXFORMOBJ_vRemoveTranslation(longlong *param_1)

{
  longlong lVar1;
  
                    /* 0x19e0  34  EXFORMOBJ_vRemoveTranslation */
  lVar1 = *param_1;
  if (lVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core6option13unwrap_failed();
  }
  *(undefined8 *)(lVar1 + 0x10) = 0;
  *(undefined8 *)(lVar1 + 0x18) = 0;
  *(byte *)(lVar1 + 0x20) = *(byte *)(lVar1 + 0x20) | 0x40;
  return;
}



===== EXFORMOBJ_vGetCoefficient @ 140001a10 =====

void EXFORMOBJ_vGetCoefficient(undefined8 *param_1,float *param_2)

{
  float fVar1;
  undefined8 uVar2;
  float *pfVar3;
  float fVar4;
  float fVar5;
  
                    /* 0x1a10  30  EXFORMOBJ_vGetCoefficient */
  pfVar3 = (float *)*param_1;
  if (pfVar3 == (float *)0x0) {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core6option13unwrap_failed();
  }
  if (((uint)pfVar3[8] & 8) != 0) {
    fVar1 = pfVar3[1];
    fVar4 = pfVar3[2];
    fVar5 = pfVar3[3];
    *param_2 = *pfVar3 * 0.0625;
    param_2[1] = fVar1 * 0.0625;
    param_2[2] = fVar4 * 0.0625;
    param_2[3] = fVar5 * 0.0625;
    *(ulonglong *)(param_2 + 4) =
         CONCAT44((float)((ulonglong)*(undefined8 *)(pfVar3 + 4) >> 0x20) * 0.0625,
                  (float)*(undefined8 *)(pfVar3 + 4) * 0.0625);
    return;
  }
  if (((uint)pfVar3[8] & 0x10) == 0) {
    *param_2 = *pfVar3;
    uVar2 = *(undefined8 *)(pfVar3 + 3);
    *(undefined8 *)(param_2 + 1) = *(undefined8 *)(pfVar3 + 1);
    *(undefined8 *)(param_2 + 3) = uVar2;
    param_2[5] = pfVar3[5];
    return;
  }
  fVar1 = pfVar3[1];
  uVar2 = *(undefined8 *)(pfVar3 + 2);
  *param_2 = *pfVar3 * 16.0;
  param_2[1] = fVar1 * 16.0;
  param_2[2] = (float)uVar2 * 16.0;
  param_2[3] = (float)((ulonglong)uVar2 >> 0x20) * 16.0;
  *(undefined8 *)(param_2 + 4) = *(undefined8 *)(pfVar3 + 4);
  return;
}



===== EXFORMOBJ_vGetCoefficient_fd_xform @ 140001a20 =====

void EXFORMOBJ_vGetCoefficient_fd_xform(undefined8 *param_1,undefined8 *param_2)

{
  float fVar1;
  float *pfVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  
                    /* 0x1a20  31  EXFORMOBJ_vGetCoefficient_fd_xform */
  pfVar2 = (float *)*param_1;
  if (pfVar2 == (float *)0x0) {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core6option13unwrap_failed();
  }
  if (((uint)pfVar2[8] & 8) == 0) {
    fVar1 = *pfVar2;
    if (((uint)pfVar2[8] & 0x10) == 0) {
      iVar3 = _RNvNtCslMg0IV26qJh_12gdi_bindings6efloat14bEfToL_or_zero((uint)fVar1);
      iVar4 = _RNvNtCslMg0IV26qJh_12gdi_bindings6efloat14bEfToL_or_zero((uint)pfVar2[1]);
      *param_2 = CONCAT44((float)iVar4,(float)iVar3);
      iVar3 = _RNvNtCslMg0IV26qJh_12gdi_bindings6efloat14bEfToL_or_zero((uint)pfVar2[2]);
      *(float *)(param_2 + 1) = (float)iVar3;
      fVar5 = pfVar2[3];
      goto LAB_1400027da;
    }
    fVar5 = 16.0;
  }
  else {
    fVar5 = 0.0625;
    fVar1 = *pfVar2;
  }
  iVar3 = _RNvNtCslMg0IV26qJh_12gdi_bindings6efloat14bEfToL_or_zero((uint)(fVar1 * fVar5));
  iVar4 = _RNvNtCslMg0IV26qJh_12gdi_bindings6efloat14bEfToL_or_zero((uint)(pfVar2[1] * fVar5));
  *param_2 = CONCAT44((float)iVar4,(float)iVar3);
  iVar3 = _RNvNtCslMg0IV26qJh_12gdi_bindings6efloat14bEfToL_or_zero((uint)(pfVar2[2] * fVar5));
  *(float *)(param_2 + 1) = (float)iVar3;
  fVar5 = fVar5 * pfVar2[3];
LAB_1400027da:
  iVar3 = _RNvNtCslMg0IV26qJh_12gdi_bindings6efloat14bEfToL_or_zero((uint)fVar5);
  *(float *)((longlong)param_2 + 0xc) = (float)iVar3;
  return;
}



===== EXFORMOBJ_vOrder @ 140001a30 =====

void EXFORMOBJ_vOrder(undefined8 *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
                    /* 0x1a30  33  EXFORMOBJ_vOrder */
  piVar3 = (int *)*param_1;
  if (piVar3 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core6option13unwrap_failed();
  }
  iVar1 = *param_2;
  iVar2 = param_2[2];
  if (*piVar3 < 0) {
    if (iVar2 <= iVar1) goto LAB_140001a52;
  }
  else if (iVar1 <= iVar2) goto LAB_140001a52;
  *param_2 = iVar2;
  param_2[2] = iVar1;
LAB_140001a52:
  iVar1 = param_2[1];
  iVar2 = param_2[3];
  if (piVar3[3] < 0) {
    if (iVar2 <= iVar1) {
      return;
    }
  }
  else if (iVar1 <= iVar2) {
    return;
  }
  param_2[1] = iVar2;
  param_2[3] = iVar1;
  return;
}



===== EXFORMOBJ_bMultiply @ 140001a90 =====

undefined8
EXFORMOBJ_bMultiply(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,uint param_4)

{
  float fVar1;
  undefined8 in_RAX;
  undefined8 uVar2;
  float fVar3;
  float fVar4;
  float *pfVar5;
  bool bVar6;
  bool bVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  
                    /* 0x1a90  11  EXFORMOBJ_bMultiply */
  fVar3 = *(float *)(param_2 + 1);
  fVar9 = *(float *)(param_3 + 1);
  fVar4 = (float)*param_3;
  fVar11 = (float)((ulonglong)*param_3 >> 0x20);
  fVar8 = (float)*param_2;
  if (((((*(float *)((longlong)param_2 + 4) != 0.0) || (NAN(*(float *)((longlong)param_2 + 4)))) ||
       (fVar3 != 0.0)) || ((NAN(fVar3) || (fVar11 != 0.0)))) ||
     ((NAN(fVar11) || ((fVar9 != 0.0 || (NAN(fVar9))))))) {
    pfVar5 = (float *)*param_1;
    if (pfVar5 == (float *)0x0) goto LAB_140002a47;
    fVar12 = *(float *)((longlong)param_3 + 0xc);
    fVar10 = (float)((ulonglong)*param_2 >> 0x20);
    fVar1 = *(float *)((longlong)param_2 + 0xc);
    *pfVar5 = fVar9 * fVar10 + fVar8 * fVar4;
    pfVar5[1] = fVar12 * fVar10 + fVar8 * fVar11;
    pfVar5[2] = fVar1 * fVar9 + fVar3 * fVar4;
    pfVar5[3] = fVar1 * fVar12 + fVar3 * fVar11;
  }
  else {
    pfVar5 = (float *)*param_1;
    if (pfVar5 == (float *)0x0) {
LAB_140002a47:
                    /* WARNING: Subroutine does not return */
      _RNvNtCsloaxXL3qbEI_4core6option13unwrap_failed();
    }
    *pfVar5 = fVar8 * fVar4;
    fVar12 = *(float *)((longlong)param_3 + 0xc);
    pfVar5[3] = *(float *)((longlong)param_2 + 0xc) * fVar12;
    pfVar5[1] = 0.0;
    pfVar5[2] = 0.0;
  }
  fVar3 = *(float *)(param_2 + 2);
  fVar8 = *(float *)((longlong)param_2 + 0x14);
  if ((((fVar3 != 0.0) || (NAN(fVar3))) || (fVar8 != 0.0)) || (NAN(fVar8))) {
    fVar9 = *(float *)(param_3 + 2) + fVar8 * fVar9 + fVar4 * fVar3;
    *(ulonglong *)(pfVar5 + 4) =
         CONCAT44(*(float *)((longlong)param_3 + 0x14) + fVar8 * fVar12 + fVar11 * fVar3,fVar9);
    uVar2 = _RNvNtCslMg0IV26qJh_12gdi_bindings6efloat6bEfToL((uint)fVar9);
    fVar3 = SUB84(param_2,0);
    fVar9 = fVar3;
    in_RAX = _RNvNtCslMg0IV26qJh_12gdi_bindings6efloat6bEfToL((uint)pfVar5[5]);
    if (((int)uVar2 != 1) || (pfVar5[6] = fVar3, (int)in_RAX != 1)) {
      return 0;
    }
  }
  else {
    pfVar5[4] = *(float *)(param_3 + 2);
    pfVar5[5] = *(float *)((longlong)param_3 + 0x14);
    fVar3 = *(float *)(param_3 + 3);
    pfVar5[6] = fVar3;
    fVar9 = *(float *)((longlong)param_3 + 0x1c);
  }
  pfVar5[7] = fVar9;
  uVar2 = CONCAT71((int7)((ulonglong)in_RAX >> 8),1);
  if ((param_4 & 1) != 0) {
    fVar4 = (float)(param_4 & 0x38);
    fVar8 = (float)((int)fVar4 + 0x40);
    if (fVar3 != 0.0 || fVar9 != 0.0) {
      fVar8 = fVar4;
    }
    pfVar5[8] = fVar8;
    if (((pfVar5[1] == 0.0) && (!NAN(pfVar5[1]))) && ((pfVar5[2] == 0.0 && (!NAN(pfVar5[2]))))) {
      pfVar5[8] = (float)((uint)fVar8 | 1);
      fVar3 = *pfVar5;
      if (fVar4 == 1.12104e-44) {
        if (fVar3 != 16.0) {
          return uVar2;
        }
        if (NAN(fVar3)) {
          return uVar2;
        }
        bVar6 = NAN(pfVar5[3]);
        bVar7 = pfVar5[3] == 16.0;
      }
      else if (fVar4 == 4.48416e-44) {
        if (fVar3 != 1.0) {
          return uVar2;
        }
        if (NAN(fVar3)) {
          return uVar2;
        }
        bVar6 = NAN(pfVar5[3]);
        bVar7 = pfVar5[3] == 1.0;
      }
      else {
        if (fVar3 != 0.0625) {
          return uVar2;
        }
        if (NAN(fVar3)) {
          return uVar2;
        }
        bVar6 = NAN(pfVar5[3]);
        bVar7 = pfVar5[3] == 0.0625;
      }
      if ((bVar7) && (!bVar6)) {
        pfVar5[8] = (float)((uint)fVar8 | 3);
      }
    }
  }
  return uVar2;
}



===== EXFORMOBJ_bInverse @ 140001aa0 =====

undefined8 EXFORMOBJ_bInverse(undefined8 *param_1,float *param_2)

{
  ulonglong uVar1;
  float *pfVar2;
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined8 uVar5;
  ulonglong uVar6;
  float fVar7;
  float fVar8;
  float fVar11;
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  undefined1 auVar12 [16];
  undefined1 auVar13 [16];
  float fVar14;
  float fVar15;
  
                    /* 0x1aa0  9  EXFORMOBJ_bInverse */
  fVar7 = SUB84(param_2,0);
  pfVar2 = (float *)*param_1;
  if (pfVar2 == (float *)0x0) {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core6option13unwrap_failed();
  }
  fVar8 = param_2[8];
  uVar6 = (ulonglong)(uint)fVar8;
  pfVar2[8] = (float)((uint)fVar8 & 0xffffffe7 | 0x10);
  if (((uint)fVar8 & 2) == 0) {
    fVar11 = *param_2;
    fVar14 = param_2[3];
    uVar1 = *(ulonglong *)(param_2 + 1);
    fVar15 = fVar11 * fVar14 - (float)(uVar1 >> 0x20) * (float)uVar1;
    if ((fVar15 != 0.0) || (NAN(fVar15))) {
      if (((uint)fVar8 & 1) == 0) {
        auVar12._0_8_ = uVar1 ^ 0x8000000080000000;
        auVar12._8_4_ = 0x80000000;
        auVar12._12_4_ = 0x80000000;
        auVar3._4_4_ = fVar15;
        auVar3._0_4_ = fVar15;
        auVar3._8_8_ = 0;
        auVar13 = divps(auVar12,auVar3);
        auVar9._4_4_ = fVar11;
        auVar9._0_4_ = fVar14;
        auVar9._8_8_ = 0;
        auVar4._4_4_ = fVar15;
        auVar4._0_4_ = fVar15;
        auVar4._8_8_ = 0;
        auVar10 = divps(auVar9,auVar4);
        *pfVar2 = auVar10._0_4_;
        pfVar2[1] = auVar13._0_4_;
        pfVar2[2] = auVar13._4_4_;
        pfVar2[3] = auVar10._4_4_;
        if (((uint)fVar8 & 0x40) != 0) {
LAB_140002b92:
          pfVar2[4] = 0.0;
          pfVar2[5] = 0.0;
          pfVar2[6] = 0.0;
          pfVar2[7] = 0.0;
          goto LAB_140002ae5;
        }
        fVar11 = (float)*(undefined8 *)(param_2 + 4);
        fVar14 = (float)((ulonglong)*(undefined8 *)(param_2 + 4) >> 0x20);
        fVar8 = auVar10._0_4_ * fVar11 + auVar13._4_4_ * fVar14;
        fVar11 = auVar10._4_4_ * fVar14 + auVar13._0_4_ * fVar11;
      }
      else {
        pfVar2[1] = 0.0;
        pfVar2[2] = 0.0;
        auVar10._4_4_ = fVar11;
        auVar10._0_4_ = fVar14;
        auVar10._8_8_ = 0;
        auVar13._4_4_ = fVar15;
        auVar13._0_4_ = fVar15;
        auVar13._8_8_ = 0;
        auVar10 = divps(auVar10,auVar13);
        *pfVar2 = auVar10._0_4_;
        pfVar2[3] = auVar10._4_4_;
        if (((uint)fVar8 & 0x40) != 0) goto LAB_140002b92;
        fVar8 = auVar10._0_4_ * (float)*(undefined8 *)(param_2 + 4);
        fVar11 = auVar10._4_4_ * (float)((ulonglong)*(undefined8 *)(param_2 + 4) >> 0x20);
      }
      *(ulonglong *)(pfVar2 + 4) = CONCAT44(fVar11,fVar8) ^ 0x8000000080000000;
      uVar5 = _RNvNtCslMg0IV26qJh_12gdi_bindings6efloat6bEfToL((uint)-fVar8);
      fVar8 = fVar7;
      uVar6 = _RNvNtCslMg0IV26qJh_12gdi_bindings6efloat6bEfToL((uint)pfVar2[5]);
      if (((int)uVar5 == 1) && (pfVar2[6] = fVar7, (int)uVar6 == 1)) {
        pfVar2[7] = fVar8;
        goto LAB_140002ae5;
      }
    }
    uVar5 = 0;
  }
  else {
    pfVar2[0] = 0.0625;
    pfVar2[1] = 0.0;
    pfVar2[2] = 0.0;
    pfVar2[3] = 0.0625;
    *(ulonglong *)(pfVar2 + 4) =
         CONCAT44((float)((ulonglong)*(undefined8 *)(param_2 + 4) >> 0x20) * -0.0625,
                  (float)*(undefined8 *)(param_2 + 4) * -0.0625);
    *(ulonglong *)(pfVar2 + 6) =
         CONCAT44(-(int)((longlong)*(undefined8 *)(param_2 + 6) >> 0x24),
                  -((int)*(undefined8 *)(param_2 + 6) >> 4));
LAB_140002ae5:
    uVar5 = CONCAT71((int7)(uVar6 >> 8),1);
  }
  return uVar5;
}



===== EXFORMOBJ_bComputeUnits @ 140001ab0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
EXFORMOBJ_bComputeUnits(undefined8 *param_1,int param_2,uint *param_3,float *param_4,float *param_5)

{
  float *pfVar1;
  code *pcVar2;
  undefined1 auVar3 [16];
  uint uVar4;
  undefined8 uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  float *pfVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  bool bVar16;
  undefined8 uVar17;
  undefined1 auVar18 [16];
  float fVar19;
  undefined1 auVar21 [12];
  uint uVar20;
  undefined1 auVar22 [16];
  undefined1 auVar23 [16];
  undefined1 auStackY_98 [32];
  float fStack_70;
  float fStack_6c;
  float fStack_68;
  float fStack_64;
  ulonglong uStack_60;
  
                    /* 0x1ab0  4  EXFORMOBJ_bComputeUnits */
  uStack_60 = __security_cookie ^ (ulonglong)auStackY_98;
  iVar14 = -param_2;
  if (-param_2 < 0) {
    iVar14 = param_2;
  }
  pfVar1 = (float *)*param_1;
  if (pfVar1 == (float *)0x0) {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core6option13unwrap_failed();
  }
  if (((iVar14 * -0x789abcdf + 0x91a2b0U >> 2 | iVar14 * 0x40000000) < 0x48d159) &&
     (((uint)pfVar1[8] & 1) != 0)) {
    bVar16 = (iVar14 / 900 & 1U) == 0;
    pfVar10 = pfVar1 + 3;
    if (bVar16) {
      pfVar10 = pfVar1;
    }
    fVar19 = *pfVar10;
    if ((fVar19 == 0.0) && (!NAN(fVar19))) {
      if ((uStack_60 ^ (ulonglong)auStackY_98) == __security_cookie) {
        return 0;
      }
      goto LAB_1400031bf;
    }
    uVar20 = (uint)bVar16;
    auVar21._0_4_ = (int)(uVar20 << 0x1f) >> 0x1f;
    auVar21._4_4_ = (int)(uVar20 << 0x1f) >> 0x1f;
    auVar21._8_4_ = 0;
    auVar23._12_4_ = 0;
    auVar23._0_12_ = auVar21;
    auVar3._12_4_ = 0;
    auVar3._0_12_ = auVar21;
    if ((iVar14 / 900 & 2U) != 0) {
      fVar19 = -fVar19;
    }
    if (0.0 <= fVar19) {
      auVar18 = ZEXT416(0x3f800000) & auVar3 | ~auVar23 & ___xmm_00000000000000003f80000000000000;
      uVar20 = auVar18._4_4_;
      goto joined_r0x000140003130;
    }
    auVar18 = ZEXT416(0x3f800000) & auVar3 | ~auVar23 & ___xmm_00000000000000003f80000000000000;
    uVar20 = auVar18._4_4_ ^ 0x80000000;
    uVar9 = auVar18._0_4_ ^ 0x80000000;
    fVar19 = -fVar19;
  }
  else {
    uVar5 = _RNvNtCslMg0IV26qJh_12gdi_bindings7draweng5efCos
                      ((ulonglong)(uint)((float)iVar14 / 10.0));
    fStack_70 = (float)uVar5;
    uVar17 = _RNvNtCslMg0IV26qJh_12gdi_bindings7draweng5efSin
                       ((ulonglong)(uint)((float)iVar14 / 10.0));
    fStack_6c = (float)uVar17;
    fStack_68 = (float)uVar5;
    fStack_64 = fStack_6c;
    _RNvMNtNtCsdyToaWEq7tk_8gdi_rust5xform12xformobj_cxxNtNtB4_10xformobj_h9EXFORMOBJ24bXform_vectorfl_vectorfl
              (param_1,&fStack_68,1,&fStack_70,1);
    auVar18._4_4_ = fStack_6c;
    auVar18._0_4_ = fStack_70;
    auVar18._8_8_ = 0;
    fVar19 = fStack_6c * fStack_6c + fStack_70 * fStack_70;
    uVar7 = (uint)fVar19 >> 0x17 & 0xff;
    uVar20 = uVar7 + 0x7f;
    uVar11 = uVar20 & 1;
    uVar12 = ((uint)fVar19 & 0x7fffff | 0x800000) << (char)uVar11 + 7;
    uVar4 = ((uVar12 >> 0x1e) - 1) * 4 | (uVar12 & 0x3fffffff) >> 0x1c;
    iVar14 = 3 - (uint)(uVar4 < 5);
    uVar9 = uVar4 + 0x3ffffffb;
    if (uVar4 < 5) {
      uVar9 = uVar4;
    }
    uVar8 = (uVar12 & 0xfffffff) >> 0x1a | uVar9 << 2;
    uVar6 = iVar14 * 4;
    uVar4 = 0;
    uVar9 = ~uVar6;
    if (uVar6 >= uVar8) {
      uVar9 = uVar4;
    }
    iVar14 = (uint)(uVar6 < uVar8) + iVar14 * 2;
    uVar6 = (uVar9 + uVar8) * 4 | (uVar12 & 0x3ffffff) >> 0x18;
    uVar8 = iVar14 * 4;
    uVar9 = ~uVar8;
    if (uVar8 >= uVar6) {
      uVar9 = uVar4;
    }
    uVar15 = (uVar9 + uVar6) * 4 | (uVar12 & 0xffffff) >> 0x16;
    iVar14 = (uint)(uVar8 < uVar6) + iVar14 * 2;
    uVar6 = iVar14 * 4;
    iVar14 = (uint)(uVar6 < uVar15) + iVar14 * 2;
    uVar9 = ~uVar6;
    if (uVar6 >= uVar15) {
      uVar9 = uVar4;
    }
    uVar6 = (uVar9 + uVar15) * 4 | (uVar12 & 0x3fffff) >> 0x14;
    uVar8 = iVar14 * 4;
    iVar14 = (uint)(uVar8 < uVar6) + iVar14 * 2;
    uVar9 = ~uVar8;
    if (uVar8 >= uVar6) {
      uVar9 = uVar4;
    }
    uVar8 = (uVar9 + uVar6) * 4 | (uVar12 & 0xfffff) >> 0x12;
    uVar6 = iVar14 * 4;
    uVar9 = ~uVar6;
    if (uVar6 >= uVar8) {
      uVar9 = uVar4;
    }
    iVar14 = (uint)(uVar6 < uVar8) + iVar14 * 2;
    uVar6 = (uVar9 + uVar8) * 4 | (uVar12 & 0x3ffff) >> 0x10;
    uVar8 = iVar14 * 4;
    uVar9 = ~uVar8;
    if (uVar8 >= uVar6) {
      uVar9 = uVar4;
    }
    uVar15 = (uVar9 + uVar6) * 4 | (uVar12 & 0xffff) >> 0xe;
    iVar14 = (uint)(uVar8 < uVar6) + iVar14 * 2;
    uVar6 = iVar14 * 4;
    iVar14 = (uint)(uVar6 < uVar15) + iVar14 * 2;
    uVar9 = ~uVar6;
    if (uVar6 >= uVar15) {
      uVar9 = uVar4;
    }
    uVar6 = (uVar9 + uVar15) * 4 | (uVar12 & 0x3fff) >> 0xc;
    uVar8 = iVar14 * 4;
    iVar14 = (uint)(uVar8 < uVar6) + iVar14 * 2;
    uVar9 = ~uVar8;
    if (uVar8 >= uVar6) {
      uVar9 = uVar4;
    }
    uVar8 = (uVar9 + uVar6) * 4 | (uVar12 & 0xfff) >> 10;
    uVar6 = iVar14 * 4;
    uVar9 = ~uVar6;
    if (uVar6 >= uVar8) {
      uVar9 = uVar4;
    }
    iVar14 = (uint)(uVar6 < uVar8) + iVar14 * 2;
    uVar6 = (uVar9 + uVar8) * 4 | (uVar12 & 0x3ff) >> 8;
    uVar8 = iVar14 * 4;
    uVar9 = ~uVar8;
    if (uVar8 >= uVar6) {
      uVar9 = uVar4;
    }
    uVar15 = (uVar9 + uVar6) * 4 | (uVar12 & 0xff) >> 6;
    iVar14 = (uint)(uVar8 < uVar6) + iVar14 * 2;
    uVar6 = iVar14 * 4;
    iVar14 = (uint)(uVar6 < uVar15) + iVar14 * 2;
    uVar9 = ~uVar6;
    if (uVar6 >= uVar15) {
      uVar9 = uVar4;
    }
    uVar6 = (uVar9 + uVar15) * 4 | (uVar12 & 0x3f) >> 4;
    uVar8 = iVar14 * 4;
    iVar14 = (uint)(uVar8 < uVar6) + iVar14 * 2;
    uVar9 = ~uVar8;
    if (uVar8 >= uVar6) {
      uVar9 = uVar4;
    }
    uVar8 = (uVar9 + uVar6) * 4 | (uVar12 & 0xf) >> 2;
    uVar6 = iVar14 * 4;
    iVar14 = (uint)(uVar6 < uVar8) + iVar14 * 2;
    uVar9 = ~uVar6;
    if (uVar6 >= uVar8) {
      uVar9 = uVar4;
    }
    uVar6 = (uVar9 + uVar8) * 4 | uVar12 & 3;
    uVar12 = iVar14 * 4;
    iVar14 = (uint)(uVar12 < uVar6) + iVar14 * 2;
    uVar9 = ~uVar12;
    if (uVar12 >= uVar6) {
      uVar9 = uVar4;
    }
    uVar12 = iVar14 * 4;
    bVar16 = uVar12 < (uVar9 + uVar6) * 4;
    uVar12 = ~uVar12;
    if (!bVar16) {
      uVar12 = uVar4;
    }
    iVar13 = (uint)bVar16 + iVar14 * 2;
    iVar14 = uVar12 + (uVar9 + uVar6) * 4;
    uVar9 = iVar13 * 4;
    bVar16 = uVar9 < (uint)(iVar14 * 4);
    iVar13 = (uint)bVar16 + iVar13 * 2;
    uVar9 = ~uVar9;
    if (!bVar16) {
      uVar9 = uVar4;
    }
    iVar14 = uVar9 + iVar14 * 4;
    uVar9 = iVar13 * 4;
    bVar16 = uVar9 < (uint)(iVar14 * 4);
    uVar9 = ~uVar9;
    if (!bVar16) {
      uVar9 = uVar4;
    }
    iVar13 = (uint)bVar16 + iVar13 * 2;
    iVar14 = uVar9 + iVar14 * 4;
    uVar9 = iVar13 * 4;
    bVar16 = uVar9 < (uint)(iVar14 * 4);
    iVar13 = (uint)bVar16 + iVar13 * 2;
    uVar9 = ~uVar9;
    if (!bVar16) {
      uVar9 = uVar4;
    }
    iVar14 = uVar9 + iVar14 * 4;
    uVar9 = iVar13 * 4;
    bVar16 = uVar9 < (uint)(iVar14 * 4);
    uVar9 = ~uVar9;
    if (!bVar16) {
      uVar9 = uVar4;
    }
    iVar13 = (uint)bVar16 + iVar13 * 2;
    iVar14 = uVar9 + iVar14 * 4;
    uVar9 = iVar13 * 4;
    bVar16 = uVar9 < (uint)(iVar14 * 4);
    iVar13 = (uint)bVar16 + iVar13 * 2;
    uVar9 = ~uVar9;
    if (!bVar16) {
      uVar9 = uVar4;
    }
    iVar14 = uVar9 + iVar14 * 4;
    uVar9 = iVar13 * 4;
    bVar16 = uVar9 < (uint)(iVar14 * 4);
    uVar9 = ~uVar9;
    if (!bVar16) {
      uVar9 = uVar4;
    }
    uVar12 = (uint)bVar16 + iVar13 * 2;
    uVar4 = uVar7 + 0x7e;
    if (uVar11 == 0) {
      uVar4 = uVar20;
    }
    fVar19 = (float)((uVar4 & 0x1fe) * 0x400000 + (uVar12 & 0x3fffff) * 2 |
                    (uint)(uVar12 * 4 < (uVar9 + iVar14 * 4) * 4));
    if ((fVar19 == 0.0) && (!NAN(fVar19))) {
      if ((uStack_60 ^ (ulonglong)auStackY_98) == __security_cookie) {
        return 0;
      }
      goto LAB_1400031bf;
    }
    auVar22._4_4_ = fVar19;
    auVar22._0_4_ = fVar19;
    auVar22._8_8_ = 0;
    auVar18 = divps(auVar18,auVar22);
    fVar19 = fVar19 * 16.0;
    uVar20 = auVar18._4_4_;
joined_r0x000140003130:
    uVar9 = auVar18._0_4_;
  }
  if (param_2 < 0) {
    uVar20 = uVar20 ^ 0x80000000;
  }
  *param_3 = uVar9;
  param_3[1] = uVar20;
  *param_4 = fVar19;
  *param_5 = 1.0 / fVar19;
  if ((uStack_60 ^ (ulonglong)auStackY_98) == __security_cookie) {
                    /* WARNING: Read-only address (ram,0x00014001a580) is written */
    return CONCAT71((int7)((ulonglong)param_5 >> 8),1);
  }
LAB_1400031bf:
  pcVar2 = (code *)swi(3);
  uVar5 = (*pcVar2)();
  return uVar5;
}



===== EXFORMOBJR_bXformRound_vectorl_vectorfx @ 140001ac0 =====

bool EXFORMOBJR_bXformRound_vectorl_vectorfx
               (undefined8 *param_1,longlong param_2,ulonglong *param_3,longlong param_4)

{
  undefined8 uVar1;
  
                    /* 0x1ac0  3  EXFORMOBJR_bXformRound_vectorl_vectorfx */
  uVar1 = _RNvMs_NtNtCsdyToaWEq7tk_8gdi_rust5xform12xformobj_cxxNtNtB6_10xformobj_h10EXFORMOBJR28bXformRound_vectorl_vectorfx
                    (param_1,param_2,param_4,param_3,param_4);
  return (int)uVar1 == 0;
}



===== EXFORMOBJR_bXformRound_umptr_pointl_pointfx @ 140001af0 =====

bool EXFORMOBJR_bXformRound_umptr_pointl_pointfx
               (longlong *******param_1,longlong *******param_2,undefined **param_3,
               longlong *******param_4)

{
  undefined8 uVar1;
  
                    /* 0x1af0  2  EXFORMOBJR_bXformRound_umptr_pointl_pointfx */
  uVar1 = _RNvMs_NtNtCsdyToaWEq7tk_8gdi_rust5xform12xformobj_cxxNtNtB6_10xformobj_h10EXFORMOBJR32bXformRound_umptr_pointl_pointfx
                    (param_1,param_2,param_3,param_4);
  return (int)uVar1 == 0;
}



===== EXFORMOBJR_bXformRound_pointl_pointfx @ 140001b10 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool EXFORMOBJR_bXformRound_pointl_pointfx
               (longlong *******param_1,longlong ******param_2,undefined **param_3,
               longlong *******param_4)

{
  code *pcVar1;
  undefined1 uVar2;
  undefined8 uVar3;
  undefined1 auStack_48 [32];
  longlong ******local_28;
  longlong *******local_20;
  undefined8 local_18;
  undefined2 local_10;
  ulonglong local_8;
  
                    /* 0x1b10  1  EXFORMOBJR_bXformRound_pointl_pointfx */
  local_8 = __security_cookie ^ (ulonglong)auStack_48;
  local_18 = 0;
  local_10 = 0;
  local_28 = param_2;
  local_20 = param_4;
  uVar3 = _RNvMs_NtNtCsdyToaWEq7tk_8gdi_rust5xform12xformobj_cxxNtNtB6_10xformobj_h10EXFORMOBJR32bXformRound_umptr_pointl_pointfx
                    (param_1,&local_28,param_3,param_4);
  if ((local_8 ^ (ulonglong)auStack_48) == __security_cookie) {
    return (int)uVar3 == 0;
  }
  pcVar1 = (code *)swi(3);
  uVar2 = (*pcVar1)();
  return (bool)uVar2;
}



===== _RNvMNtNtCsdyToaWEq7tk_8gdi_rust5xform12xformobj_cxxNtNtB4_10xformobj_h9EXFORMOBJ21bXform_pointl_pointfx @ 140001b70 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
_RNvMNtNtCsdyToaWEq7tk_8gdi_rust5xform12xformobj_cxxNtNtB4_10xformobj_h9EXFORMOBJ21bXform_pointl_pointfx
          (undefined8 *param_1,longlong param_2,ulonglong param_3,longlong param_4,ulonglong param_5
          )

{
  int *piVar1;
  int *piVar2;
  float *pfVar3;
  code *pcVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  ulonglong uVar14;
  ulonglong uVar15;
  undefined1 auStackY_68 [32];
  ulonglong local_40;
  undefined **local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined8 uStack_18;
  ulonglong local_8;
  
  local_8 = __security_cookie ^ (ulonglong)auStackY_68;
  local_40 = param_3;
  if (param_3 == param_5) {
    pfVar3 = (float *)*param_1;
    if (pfVar3 != (float *)0x0) {
      if ((~(uint)pfVar3[8] & 0x43) == 0) {
        uVar12 = CONCAT71((uint7)(uint3)(~(uint)pfVar3[8] >> 8),1);
        if (param_3 != 0) {
          if (param_3 < 4) {
            uVar14 = 0;
          }
          else {
            uVar14 = param_3 & 0xfffffffffffffffc;
            uVar15 = 0;
            do {
              piVar1 = (int *)(param_2 + uVar15 * 8);
              iVar5 = piVar1[1];
              iVar6 = piVar1[2];
              iVar7 = piVar1[3];
              piVar2 = (int *)(param_2 + 0x10 + uVar15 * 8);
              iVar8 = *piVar2;
              iVar9 = piVar2[1];
              iVar10 = piVar2[2];
              iVar11 = piVar2[3];
              piVar2 = (int *)(param_4 + uVar15 * 8);
              *piVar2 = *piVar1 << 4;
              piVar2[1] = iVar5 << 4;
              piVar2[2] = iVar6 << 4;
              piVar2[3] = iVar7 << 4;
              piVar1 = (int *)(param_4 + 0x10 + uVar15 * 8);
              *piVar1 = iVar8 << 4;
              piVar1[1] = iVar9 << 4;
              piVar1[2] = iVar10 << 4;
              piVar1[3] = iVar11 << 4;
              uVar15 = uVar15 + 4;
            } while (uVar14 != uVar15);
            if (param_3 == uVar14) goto LAB_140001c4c;
          }
          do {
            uVar13 = *(undefined8 *)(param_2 + uVar14 * 8);
            *(ulonglong *)(param_4 + uVar14 * 8) =
                 CONCAT44((int)((ulonglong)uVar13 >> 0x20) << 4,(int)uVar13 << 4);
            uVar14 = uVar14 + 1;
          } while (param_3 != uVar14);
        }
      }
      else {
        uVar13 = _RNvNtNtCsdyToaWEq7tk_8gdi_rust5xform7xformer7bCvtPts
                           (pfVar3,param_2,param_3,param_4,param_3);
        uVar12 = CONCAT71((int7)((ulonglong)uVar13 >> 8),1);
        if ((char)uVar13 == '\0') {
          EngSetLastError(0x216);
          uVar12 = 0;
        }
      }
LAB_140001c4c:
      if ((local_8 ^ (ulonglong)auStackY_68) == __security_cookie) {
        return uVar12;
      }
      pcVar4 = (code *)swi(3);
      uVar13 = (*pcVar4)();
      return uVar13;
    }
  }
  else {
    local_38 = &PTR_s_Src_and_Dst_are_of_different_siz_140019030;
    local_30 = 1;
    local_28 = 8;
    local_20 = 0;
    uStack_18 = 0;
    _RINvNtCsloaxXL3qbEI_4core9panicking13assert_failedjjEB4_
              (0,&local_40,&param_5,(longlong *)&local_38);
  }
                    /* WARNING: Subroutine does not return */
  _RNvNtCsloaxXL3qbEI_4core6option13unwrap_failed();
}



===== _RNvMNtNtCsdyToaWEq7tk_8gdi_rust5xform12xformobj_cxxNtNtB4_10xformobj_h9EXFORMOBJ21bXform_pointfx_pointl @ 140001cd0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
_RNvMNtNtCsdyToaWEq7tk_8gdi_rust5xform12xformobj_cxxNtNtB4_10xformobj_h9EXFORMOBJ21bXform_pointfx_pointl
          (undefined8 *param_1,longlong param_2,ulonglong param_3,longlong param_4,ulonglong param_5
          )

{
  int *piVar1;
  int *piVar2;
  float *pfVar3;
  code *pcVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  uint uVar13;
  undefined1 auStackY_68 [32];
  ulonglong local_40;
  undefined **local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined8 uStack_18;
  ulonglong local_8;
  
  local_8 = __security_cookie ^ (ulonglong)auStackY_68;
  local_40 = param_3;
  if (param_3 == param_5) {
    pfVar3 = (float *)*param_1;
    if (pfVar3 != (float *)0x0) {
      if ((~(uint)pfVar3[8] & 0x43) == 0) {
        uVar9 = CONCAT71((uint7)(uint3)(~(uint)pfVar3[8] >> 8),1);
        if (param_3 != 0) {
          if (param_3 == 1) {
            uVar11 = 0;
          }
          else {
            uVar11 = param_3 & 0xfffffffffffffffe;
            uVar12 = 0;
            do {
              piVar1 = (int *)(param_2 + uVar12 * 8);
              iVar6 = piVar1[1];
              iVar7 = piVar1[2];
              iVar8 = piVar1[3];
              piVar2 = (int *)(param_4 + uVar12 * 8);
              *piVar2 = (*piVar1 >> 3) + 1 >> 1;
              piVar2[1] = (iVar6 >> 3) + 1 >> 1;
              piVar2[2] = (iVar7 >> 3) + 1 >> 1;
              piVar2[3] = (iVar8 >> 3) + 1 >> 1;
              uVar12 = uVar12 + 2;
            } while (uVar11 != uVar12);
            if (param_3 == uVar11) goto LAB_140001dbd;
          }
          do {
            uVar10 = *(undefined8 *)(param_2 + uVar11 * 8);
            uVar13 = (uint)uVar10;
            uVar5 = (uint)((ulonglong)uVar10 >> 0x20);
            *(ulonglong *)(param_4 + uVar11 * 8) =
                 CONCAT44(((int)uVar5 >> 4) + (uVar5 >> 3 & 1),
                          ((int)uVar13 >> 4) + (uVar13 >> 3 & 1));
            uVar11 = uVar11 + 1;
          } while (param_3 != uVar11);
        }
      }
      else {
        uVar10 = _RNvNtNtCsdyToaWEq7tk_8gdi_rust5xform7xformer7bCvtPts
                           (pfVar3,param_2,param_3,param_4,param_3);
        uVar9 = CONCAT71((int7)((ulonglong)uVar10 >> 8),1);
        if ((char)uVar10 == '\0') {
          EngSetLastError(0x216);
          uVar9 = 0;
        }
      }
LAB_140001dbd:
      if ((local_8 ^ (ulonglong)auStackY_68) == __security_cookie) {
        return uVar9;
      }
      pcVar4 = (code *)swi(3);
      uVar10 = (*pcVar4)();
      return uVar10;
    }
  }
  else {
    local_38 = &PTR_s_Src_and_Dst_are_of_different_siz_140019030;
    local_30 = 1;
    local_28 = 8;
    local_20 = 0;
    uStack_18 = 0;
    _RINvNtCsloaxXL3qbEI_4core9panicking13assert_failedjjEB4_
              (0,&local_40,&param_5,(longlong *)&local_38);
  }
                    /* WARNING: Subroutine does not return */
  _RNvNtCsloaxXL3qbEI_4core6option13unwrap_failed();
}



===== _RNvMNtNtCsdyToaWEq7tk_8gdi_rust5xform12xformobj_cxxNtNtB4_10xformobj_h9EXFORMOBJ24bXform_vectorfl_vectorfl @ 140001e40 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
_RNvMNtNtCsdyToaWEq7tk_8gdi_rust5xform12xformobj_cxxNtNtB4_10xformobj_h9EXFORMOBJ24bXform_vectorfl_vectorfl
          (undefined8 *param_1,void *param_2,ulonglong param_3,void *param_4,ulonglong param_5)

{
  float *pfVar1;
  code *pcVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  void *pvVar9;
  undefined8 uVar10;
  void *pvVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  undefined1 auStack_c8 [32];
  undefined **local_a8;
  ulonglong local_98;
  undefined **local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  ulonglong local_60;
  
  local_60 = __security_cookie ^ (ulonglong)auStack_c8;
  local_98 = param_3;
  if (param_3 == param_5) {
    pfVar1 = (float *)*param_1;
    if (pfVar1 != (float *)0x0) {
      fVar16 = pfVar1[8];
      pvVar9 = (void *)(ulonglong)(uint)fVar16;
      if (((uint)fVar16 & 2) == 0) {
        fVar12 = *pfVar1;
        fVar13 = pfVar1[3];
        fVar14 = (float)*(undefined8 *)(pfVar1 + 1);
        fVar15 = (float)((ulonglong)*(undefined8 *)(pfVar1 + 1) >> 0x20);
        if (((uint)fVar16 & 0x20) == 0) {
          if (((uint)fVar16 & 8) == 0) {
            if (param_3 != 0) {
              fVar14 = fVar14 * 16.0;
              fVar15 = fVar15 * 16.0;
              fVar12 = fVar12 * 16.0;
              fVar13 = fVar13 * 16.0;
              if (param_3 < 4) {
                pvVar9 = (void *)0x0;
              }
              else {
                pvVar9 = (void *)(param_3 & 0xfffffffffffffffc);
                pvVar11 = (void *)0x0;
                do {
                  pfVar1 = (float *)((longlong)param_2 + (longlong)pvVar11 * 8);
                  fVar16 = *pfVar1;
                  fVar17 = pfVar1[1];
                  fVar3 = pfVar1[2];
                  fVar4 = pfVar1[3];
                  pfVar1 = (float *)((longlong)param_2 + (longlong)pvVar11 * 8 + 0x10);
                  fVar5 = *pfVar1;
                  fVar6 = pfVar1[1];
                  fVar7 = pfVar1[2];
                  fVar8 = pfVar1[3];
                  pfVar1 = (float *)((longlong)param_4 + (longlong)pvVar11 * 8 + 0x10);
                  *pfVar1 = fVar15 * fVar6 + fVar12 * fVar5;
                  pfVar1[1] = fVar6 * fVar13 + fVar5 * fVar14;
                  pfVar1[2] = fVar15 * fVar8 + fVar12 * fVar7;
                  pfVar1[3] = fVar8 * fVar13 + fVar7 * fVar14;
                  pfVar1 = (float *)((longlong)param_4 + (longlong)pvVar11 * 8);
                  *pfVar1 = fVar15 * fVar17 + fVar12 * fVar16;
                  pfVar1[1] = fVar17 * fVar13 + fVar16 * fVar14;
                  pfVar1[2] = fVar15 * fVar4 + fVar12 * fVar3;
                  pfVar1[3] = fVar4 * fVar13 + fVar3 * fVar14;
                  pvVar11 = (void *)((longlong)pvVar11 + 4);
                } while (pvVar9 != pvVar11);
                if ((void *)param_3 == pvVar9) goto LAB_1400021a6;
              }
              do {
                uVar10 = *(undefined8 *)((longlong)param_2 + (longlong)pvVar9 * 8);
                fVar16 = (float)uVar10;
                fVar17 = (float)((ulonglong)uVar10 >> 0x20);
                *(ulonglong *)((longlong)param_4 + (longlong)pvVar9 * 8) =
                     CONCAT44(fVar17 * fVar13 + fVar14 * fVar16,fVar16 * fVar12 + fVar15 * fVar17);
                pvVar9 = (void *)((longlong)pvVar9 + 1);
              } while ((void *)param_3 != pvVar9);
            }
          }
          else if (param_3 != 0) {
            fVar14 = fVar14 * 0.0625;
            fVar15 = fVar15 * 0.0625;
            fVar12 = fVar12 * 0.0625;
            fVar13 = fVar13 * 0.0625;
            if (param_3 < 4) {
              pvVar9 = (void *)0x0;
            }
            else {
              pvVar9 = (void *)(param_3 & 0xfffffffffffffffc);
              pvVar11 = (void *)0x0;
              do {
                pfVar1 = (float *)((longlong)param_2 + (longlong)pvVar11 * 8);
                fVar16 = *pfVar1;
                fVar17 = pfVar1[1];
                fVar3 = pfVar1[2];
                fVar4 = pfVar1[3];
                pfVar1 = (float *)((longlong)param_2 + (longlong)pvVar11 * 8 + 0x10);
                fVar5 = *pfVar1;
                fVar6 = pfVar1[1];
                fVar7 = pfVar1[2];
                fVar8 = pfVar1[3];
                pfVar1 = (float *)((longlong)param_4 + (longlong)pvVar11 * 8 + 0x10);
                *pfVar1 = fVar15 * fVar6 + fVar12 * fVar5;
                pfVar1[1] = fVar6 * fVar13 + fVar5 * fVar14;
                pfVar1[2] = fVar15 * fVar8 + fVar12 * fVar7;
                pfVar1[3] = fVar8 * fVar13 + fVar7 * fVar14;
                pfVar1 = (float *)((longlong)param_4 + (longlong)pvVar11 * 8);
                *pfVar1 = fVar15 * fVar17 + fVar12 * fVar16;
                pfVar1[1] = fVar17 * fVar13 + fVar16 * fVar14;
                pfVar1[2] = fVar15 * fVar4 + fVar12 * fVar3;
                pfVar1[3] = fVar4 * fVar13 + fVar3 * fVar14;
                pvVar11 = (void *)((longlong)pvVar11 + 4);
              } while (pvVar9 != pvVar11);
              if ((void *)param_3 == pvVar9) goto LAB_1400021a6;
            }
            do {
              uVar10 = *(undefined8 *)((longlong)param_2 + (longlong)pvVar9 * 8);
              fVar16 = (float)uVar10;
              fVar17 = (float)((ulonglong)uVar10 >> 0x20);
              *(ulonglong *)((longlong)param_4 + (longlong)pvVar9 * 8) =
                   CONCAT44(fVar17 * fVar13 + fVar14 * fVar16,fVar16 * fVar12 + fVar15 * fVar17);
              pvVar9 = (void *)((longlong)pvVar9 + 1);
            } while ((void *)param_3 != pvVar9);
          }
        }
        else if (param_3 != 0) {
          if (param_3 < 4) {
            pvVar9 = (void *)0x0;
          }
          else {
            pvVar9 = (void *)(param_3 & 0xfffffffffffffffc);
            pvVar11 = (void *)0x0;
            do {
              pfVar1 = (float *)((longlong)param_2 + (longlong)pvVar11 * 8);
              fVar16 = *pfVar1;
              fVar17 = pfVar1[1];
              fVar3 = pfVar1[2];
              fVar4 = pfVar1[3];
              pfVar1 = (float *)((longlong)param_2 + (longlong)pvVar11 * 8 + 0x10);
              fVar5 = *pfVar1;
              fVar6 = pfVar1[1];
              fVar7 = pfVar1[2];
              fVar8 = pfVar1[3];
              pfVar1 = (float *)((longlong)param_4 + (longlong)pvVar11 * 8 + 0x10);
              *pfVar1 = fVar15 * fVar6 + fVar12 * fVar5;
              pfVar1[1] = fVar6 * fVar13 + fVar5 * fVar14;
              pfVar1[2] = fVar15 * fVar8 + fVar12 * fVar7;
              pfVar1[3] = fVar8 * fVar13 + fVar7 * fVar14;
              pfVar1 = (float *)((longlong)param_4 + (longlong)pvVar11 * 8);
              *pfVar1 = fVar15 * fVar17 + fVar12 * fVar16;
              pfVar1[1] = fVar17 * fVar13 + fVar16 * fVar14;
              pfVar1[2] = fVar15 * fVar4 + fVar12 * fVar3;
              pfVar1[3] = fVar4 * fVar13 + fVar3 * fVar14;
              pvVar11 = (void *)((longlong)pvVar11 + 4);
            } while (pvVar9 != pvVar11);
            if ((void *)param_3 == pvVar9) goto LAB_1400021a6;
          }
          do {
            uVar10 = *(undefined8 *)((longlong)param_2 + (longlong)pvVar9 * 8);
            fVar16 = (float)uVar10;
            fVar17 = (float)((ulonglong)uVar10 >> 0x20);
            *(ulonglong *)((longlong)param_4 + (longlong)pvVar9 * 8) =
                 CONCAT44(fVar17 * fVar13 + fVar14 * fVar16,fVar16 * fVar12 + fVar15 * fVar17);
            pvVar9 = (void *)((longlong)pvVar9 + 1);
          } while ((void *)param_3 != pvVar9);
        }
      }
      else if (param_3 != 0) {
        pvVar9 = (void *)0x0;
        do {
          fVar16 = *(float *)((longlong)param_2 + (longlong)pvVar9 * 8);
          pfVar1 = (float *)((longlong)param_4 + (longlong)pvVar9 * 8);
          if ((((fVar16 != *pfVar1) || (NAN(fVar16) || NAN(*pfVar1))) ||
              (fVar16 = *(float *)((longlong)param_2 + (longlong)pvVar9 * 8 + 4),
              pfVar1 = (float *)((longlong)param_4 + (longlong)pvVar9 * 8 + 4), fVar16 != *pfVar1))
             || (NAN(fVar16) || NAN(*pfVar1))) {
            pvVar9 = _weak_memcpy_default___llvm_retpoline_r11(param_4,param_2,param_3 << 3);
            break;
          }
          pvVar9 = (void *)((longlong)pvVar9 + 1);
        } while ((void *)param_3 != pvVar9);
      }
LAB_1400021a6:
      if ((local_60 ^ (ulonglong)auStack_c8) == __security_cookie) {
        return CONCAT71((int7)((ulonglong)pvVar9 >> 8),1);
      }
      pcVar2 = (code *)swi(3);
      uVar10 = (*pcVar2)();
      return uVar10;
    }
  }
  else {
    local_90 = &PTR_s_Src_and_Dst_are_of_different_siz_140019030;
    local_88 = 1;
    local_80 = 8;
    local_78 = 0;
    uStack_70 = 0;
    local_a8 = &PTR_s_gdi_rust_src_xform_xformobj_cxx__14001a60b_0x22_140019070;
    _RINvNtCsloaxXL3qbEI_4core9panicking13assert_failedjjEB4_
              (0,&local_98,&param_5,(longlong *)&local_90);
  }
                    /* WARNING: Subroutine does not return */
  _RNvNtCsloaxXL3qbEI_4core6option13unwrap_failed();
}



===== _RNvMNtNtCsdyToaWEq7tk_8gdi_rust5xform12xformobj_cxxNtNtB4_10xformobj_h9EXFORMOBJ22bXform_vectorl_vectorl @ 140002250 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong _RNvMNtNtCsdyToaWEq7tk_8gdi_rust5xform12xformobj_cxxNtNtB4_10xformobj_h9EXFORMOBJ22bXform_vectorl_vectorl
                    (longlong *param_1,void *param_2,longlong param_3,void *param_4,longlong param_5
                    )

{
  undefined8 uVar1;
  longlong *plVar2;
  code *pcVar3;
  undefined8 uVar4;
  longlong lVar5;
  ulonglong uVar6;
  undefined4 uVar7;
  undefined8 unaff_RSI;
  undefined7 uVar8;
  undefined1 auVar9 [16];
  int iVar10;
  int iVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  undefined1 auStackY_88 [32];
  longlong local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  longlong local_48;
  longlong lStack_40;
  undefined8 local_38;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStackY_88;
  local_60 = param_3;
  if (param_3 != param_5) {
    local_58 = &PTR_s_Src_and_Dst_are_of_different_siz_140019030;
    uStack_50 = 1;
    local_48 = 8;
    lStack_40 = 0;
    local_38 = 0;
    _RINvNtCsloaxXL3qbEI_4core9panicking13assert_failedjjEB4_(0,&local_60,&param_5,&local_58);
LAB_1400023c4:
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core6option13unwrap_failed();
  }
  plVar2 = (longlong *)*param_1;
  if (plVar2 == (longlong *)0x0) goto LAB_1400023c4;
  uVar7 = (undefined4)plVar2[4];
  local_38 = CONCAT44(local_38._4_4_,uVar7);
  local_58 = (undefined **)*plVar2;
  uStack_50 = plVar2[1];
  local_48 = plVar2[2];
  lStack_40 = plVar2[3];
  uVar8 = (undefined7)((ulonglong)unaff_RSI >> 8);
  if ((*(byte *)(plVar2 + 4) & 2) == 0) {
    local_58._4_4_ = (float)((ulonglong)local_58 >> 0x20);
    uStack_50._4_4_ = (float)((ulonglong)uStack_50 >> 0x20);
    fVar12 = (float)local_58 * 0.0625;
    fVar13 = local_58._4_4_ * 0.0625;
    fVar14 = (float)uStack_50 * 0.0625;
    fVar15 = uStack_50._4_4_ * 0.0625;
    local_58 = (undefined **)CONCAT44(fVar13,fVar12);
    uStack_50 = CONCAT44(fVar15,fVar14);
    uVar4 = _RNvNtNtCsdyToaWEq7tk_8gdi_rust5xform7xformer7bCvtVts
                      ((float *)&local_58,(longlong)param_2,param_3,(longlong)param_4,param_3);
    local_58 = (undefined **)CONCAT44(fVar13 * 16.0,fVar12 * 16.0);
    uStack_50 = CONCAT44(fVar15 * 16.0,fVar14 * 16.0);
    if ((char)uVar4 == '\0') {
      EngSetLastError(0x216);
      uVar6 = 0;
      if ((local_20 ^ (ulonglong)auStackY_88) == __security_cookie) goto LAB_140002346;
      goto LAB_140002373;
    }
  }
  else {
    uVar6 = CONCAT71(uVar8,1);
    if (param_3 != 0) {
      lVar5 = 0;
      do {
        uVar4 = *(undefined8 *)((longlong)param_2 + lVar5 * 8);
        uVar1 = *(undefined8 *)((longlong)param_4 + lVar5 * 8);
        iVar10 = -(uint)((int)uVar1 == (int)uVar4);
        iVar11 = -(uint)((int)((ulonglong)uVar1 >> 0x20) == (int)((ulonglong)uVar4 >> 0x20));
        auVar9._4_4_ = iVar10;
        auVar9._0_4_ = iVar10;
        auVar9._8_4_ = iVar11;
        auVar9._12_4_ = iVar11;
        iVar10 = movmskpd(uVar7,auVar9);
        if (iVar10 != 3) {
          _weak_memcpy_default___llvm_retpoline_r11(param_4,param_2,param_3 << 3);
          if ((local_20 ^ (ulonglong)auStackY_88) == __security_cookie) goto LAB_140002346;
          goto LAB_140002373;
        }
        lVar5 = lVar5 + 1;
        uVar7 = 3;
      } while (param_3 != lVar5);
    }
  }
  uVar6 = CONCAT71(uVar8,1);
  if ((local_20 ^ (ulonglong)auStackY_88) == __security_cookie) {
LAB_140002346:
    return uVar6 & 0xffffffff;
  }
LAB_140002373:
  pcVar3 = (code *)swi(3);
  uVar6 = (*pcVar3)();
  return uVar6;
}



===== _RNvMNtNtCsdyToaWEq7tk_8gdi_rust5xform12xformobj_cxxNtNtB4_10xformobj_h9EXFORMOBJ23bXform_vectorl_vectorfx @ 1400023e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
_RNvMNtNtCsdyToaWEq7tk_8gdi_rust5xform12xformobj_cxxNtNtB4_10xformobj_h9EXFORMOBJ23bXform_vectorl_vectorfx
          (undefined8 *param_1,longlong param_2,longlong param_3,longlong param_4,longlong param_5)

{
  int iVar1;
  int iVar2;
  float *pfVar3;
  code *pcVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  longlong lVar7;
  undefined1 auStackY_78 [32];
  longlong local_48;
  undefined **local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_78;
  local_48 = param_3;
  if (param_3 == param_5) {
    pfVar3 = (float *)*param_1;
    if (pfVar3 != (float *)0x0) {
      if (((uint)pfVar3[8] & 2) == 0) {
        uVar5 = _RNvNtNtCsdyToaWEq7tk_8gdi_rust5xform7xformer7bCvtVts
                          (pfVar3,param_2,param_3,param_4,param_3);
        uVar6 = CONCAT71((int7)((ulonglong)uVar5 >> 8),1);
        if ((char)uVar5 == '\0') {
LAB_14000242b:
          EngSetLastError(0x216);
          uVar6 = 0;
        }
      }
      else {
        uVar6 = CONCAT71((int7)(local_10 >> 8),1);
        if (param_3 != 0) {
          lVar7 = 0;
          do {
            iVar1 = *(int *)(param_2 + lVar7 * 8);
            if ((0xffffffc < iVar1 + 0x7fffffeU) ||
               (iVar2 = *(int *)(param_2 + 4 + lVar7 * 8), 0xffffffc < iVar2 + 0x7fffffeU))
            goto LAB_14000242b;
            *(int *)(param_4 + lVar7 * 8) = iVar1 << 4;
            *(int *)(param_4 + 4 + lVar7 * 8) = iVar2 << 4;
            lVar7 = lVar7 + 1;
          } while (param_3 != lVar7);
        }
      }
      if ((local_10 ^ (ulonglong)auStackY_78) == __security_cookie) {
        return uVar6;
      }
      pcVar4 = (code *)swi(3);
      uVar6 = (*pcVar4)();
      return uVar6;
    }
  }
  else {
    local_40 = &PTR_s_Src_and_Dst_are_of_different_siz_140019030;
    local_38 = 1;
    local_30 = 8;
    local_28 = 0;
    uStack_20 = 0;
    _RINvNtCsloaxXL3qbEI_4core9panicking13assert_failedjjEB4_
              (0,&local_48,&param_5,(longlong *)&local_40);
  }
                    /* WARNING: Subroutine does not return */
  _RNvNtCsloaxXL3qbEI_4core6option13unwrap_failed();
}



===== _RNvMNtNtCsdyToaWEq7tk_8gdi_rust5xform12xformobj_cxxNtNtB4_10xformobj_h9EXFORMOBJ23bXform_vectorfx_vectorl @ 140002510 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
_RNvMNtNtCsdyToaWEq7tk_8gdi_rust5xform12xformobj_cxxNtNtB4_10xformobj_h9EXFORMOBJ23bXform_vectorfx_vectorl
          (undefined8 *param_1,longlong param_2,ulonglong param_3,longlong param_4,ulonglong param_5
          )

{
  int *piVar1;
  int *piVar2;
  float *pfVar3;
  code *pcVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  ulonglong uVar14;
  ulonglong uVar15;
  undefined1 auStackY_68 [32];
  ulonglong local_40;
  undefined **local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined8 uStack_18;
  ulonglong local_8;
  
  local_8 = __security_cookie ^ (ulonglong)auStackY_68;
  local_40 = param_3;
  if (param_3 == param_5) {
    pfVar3 = (float *)*param_1;
    if (pfVar3 != (float *)0x0) {
      if (((uint)pfVar3[8] & 2) == 0) {
        uVar12 = _RNvNtNtCsdyToaWEq7tk_8gdi_rust5xform7xformer7bCvtVts
                           (pfVar3,param_2,param_3,param_4,param_3);
        uVar13 = CONCAT71((int7)((ulonglong)uVar12 >> 8),1);
        if ((char)uVar12 == '\0') {
          EngSetLastError(0x216);
          uVar13 = 0;
        }
      }
      else {
        uVar13 = CONCAT71((int7)(local_8 >> 8),1);
        if (param_3 != 0) {
          if (param_3 < 4) {
            uVar14 = 0;
          }
          else {
            uVar14 = param_3 & 0xfffffffffffffffc;
            uVar15 = 0;
            do {
              piVar1 = (int *)(param_2 + uVar15 * 8);
              iVar5 = piVar1[1];
              iVar6 = piVar1[2];
              iVar7 = piVar1[3];
              piVar2 = (int *)(param_2 + 0x10 + uVar15 * 8);
              iVar8 = *piVar2;
              iVar9 = piVar2[1];
              iVar10 = piVar2[2];
              iVar11 = piVar2[3];
              piVar2 = (int *)(param_4 + uVar15 * 8);
              *piVar2 = *piVar1 >> 4;
              piVar2[1] = iVar5 >> 4;
              piVar2[2] = iVar6 >> 4;
              piVar2[3] = iVar7 >> 4;
              piVar1 = (int *)(param_4 + 0x10 + uVar15 * 8);
              *piVar1 = iVar8 >> 4;
              piVar1[1] = iVar9 >> 4;
              piVar1[2] = iVar10 >> 4;
              piVar1[3] = iVar11 >> 4;
              uVar15 = uVar15 + 4;
            } while (uVar14 != uVar15);
            if (param_3 == uVar14) goto LAB_1400025ec;
          }
          do {
            uVar12 = *(undefined8 *)(param_2 + uVar14 * 8);
            *(ulonglong *)(param_4 + uVar14 * 8) =
                 CONCAT44((int)((longlong)uVar12 >> 0x24),(int)uVar12 >> 4);
            uVar14 = uVar14 + 1;
          } while (param_3 != uVar14);
        }
      }
LAB_1400025ec:
      if ((local_8 ^ (ulonglong)auStackY_68) == __security_cookie) {
        return uVar13;
      }
      pcVar4 = (code *)swi(3);
      uVar13 = (*pcVar4)();
      return uVar13;
    }
  }
  else {
    local_38 = &PTR_s_Src_and_Dst_are_of_different_siz_140019030;
    local_30 = 1;
    local_28 = 8;
    local_20 = 0;
    uStack_18 = 0;
    _RINvNtCsloaxXL3qbEI_4core9panicking13assert_failedjjEB4_
              (0,&local_40,&param_5,(longlong *)&local_38);
  }
                    /* WARNING: Subroutine does not return */
  _RNvNtCsloaxXL3qbEI_4core6option13unwrap_failed();
}



===== _RNvMNtNtCsdyToaWEq7tk_8gdi_rust5xform12xformobj_cxxNtNtB4_10xformobj_h9EXFORMOBJ15vGetCoefficient @ 140002670 =====

void _RNvMNtNtCsdyToaWEq7tk_8gdi_rust5xform12xformobj_cxxNtNtB4_10xformobj_h9EXFORMOBJ15vGetCoefficient
               (undefined8 *param_1,float *param_2)

{
  float fVar1;
  undefined8 uVar2;
  float *pfVar3;
  float fVar4;
  float fVar5;
  
  pfVar3 = (float *)*param_1;
  if (pfVar3 == (float *)0x0) {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core6option13unwrap_failed();
  }
  if (((uint)pfVar3[8] & 8) != 0) {
    fVar1 = pfVar3[1];
    fVar4 = pfVar3[2];
    fVar5 = pfVar3[3];
    *param_2 = *pfVar3 * 0.0625;
    param_2[1] = fVar1 * 0.0625;
    param_2[2] = fVar4 * 0.0625;
    param_2[3] = fVar5 * 0.0625;
    *(ulonglong *)(param_2 + 4) =
         CONCAT44((float)((ulonglong)*(undefined8 *)(pfVar3 + 4) >> 0x20) * 0.0625,
                  (float)*(undefined8 *)(pfVar3 + 4) * 0.0625);
    return;
  }
  if (((uint)pfVar3[8] & 0x10) == 0) {
    *param_2 = *pfVar3;
    uVar2 = *(undefined8 *)(pfVar3 + 3);
    *(undefined8 *)(param_2 + 1) = *(undefined8 *)(pfVar3 + 1);
    *(undefined8 *)(param_2 + 3) = uVar2;
    param_2[5] = pfVar3[5];
    return;
  }
  fVar1 = pfVar3[1];
  uVar2 = *(undefined8 *)(pfVar3 + 2);
  *param_2 = *pfVar3 * 16.0;
  param_2[1] = fVar1 * 16.0;
  param_2[2] = (float)uVar2 * 16.0;
  param_2[3] = (float)((ulonglong)uVar2 >> 0x20) * 16.0;
  *(undefined8 *)(param_2 + 4) = *(undefined8 *)(pfVar3 + 4);
  return;
}



===== _RNvMNtNtCsdyToaWEq7tk_8gdi_rust5xform12xformobj_cxxNtNtB4_10xformobj_h9EXFORMOBJ24vGetCoefficient_fd_xform @ 140002710 =====

void _RNvMNtNtCsdyToaWEq7tk_8gdi_rust5xform12xformobj_cxxNtNtB4_10xformobj_h9EXFORMOBJ24vGetCoefficient_fd_xform
               (undefined8 *param_1,undefined8 *param_2)

{
  float fVar1;
  float *pfVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  
  pfVar2 = (float *)*param_1;
  if (pfVar2 == (float *)0x0) {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core6option13unwrap_failed();
  }
  if (((uint)pfVar2[8] & 8) == 0) {
    fVar1 = *pfVar2;
    if (((uint)pfVar2[8] & 0x10) == 0) {
      iVar3 = _RNvNtCslMg0IV26qJh_12gdi_bindings6efloat14bEfToL_or_zero((uint)fVar1);
      iVar4 = _RNvNtCslMg0IV26qJh_12gdi_bindings6efloat14bEfToL_or_zero((uint)pfVar2[1]);
      *param_2 = CONCAT44((float)iVar4,(float)iVar3);
      iVar3 = _RNvNtCslMg0IV26qJh_12gdi_bindings6efloat14bEfToL_or_zero((uint)pfVar2[2]);
      *(float *)(param_2 + 1) = (float)iVar3;
      fVar5 = pfVar2[3];
      goto LAB_1400027da;
    }
    fVar5 = 16.0;
  }
  else {
    fVar5 = 0.0625;
    fVar1 = *pfVar2;
  }
  iVar3 = _RNvNtCslMg0IV26qJh_12gdi_bindings6efloat14bEfToL_or_zero((uint)(fVar1 * fVar5));
  iVar4 = _RNvNtCslMg0IV26qJh_12gdi_bindings6efloat14bEfToL_or_zero((uint)(pfVar2[1] * fVar5));
  *param_2 = CONCAT44((float)iVar4,(float)iVar3);
  iVar3 = _RNvNtCslMg0IV26qJh_12gdi_bindings6efloat14bEfToL_or_zero((uint)(pfVar2[2] * fVar5));
  *(float *)(param_2 + 1) = (float)iVar3;
  fVar5 = fVar5 * pfVar2[3];
LAB_1400027da:
  iVar3 = _RNvNtCslMg0IV26qJh_12gdi_bindings6efloat14bEfToL_or_zero((uint)fVar5);
  *(float *)((longlong)param_2 + 0xc) = (float)iVar3;
  return;
}



===== _RNvMNtNtCsdyToaWEq7tk_8gdi_rust5xform12xformobj_cxxNtNtB4_10xformobj_h9EXFORMOBJ9bMultiply @ 140002810 =====

undefined8
_RNvMNtNtCsdyToaWEq7tk_8gdi_rust5xform12xformobj_cxxNtNtB4_10xformobj_h9EXFORMOBJ9bMultiply
          (undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,uint param_4)

{
  float fVar1;
  undefined8 in_RAX;
  undefined8 uVar2;
  float fVar3;
  float fVar4;
  float *pfVar5;
  bool bVar6;
  bool bVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  
  fVar3 = *(float *)(param_2 + 1);
  fVar9 = *(float *)(param_3 + 1);
  fVar4 = (float)*param_3;
  fVar11 = (float)((ulonglong)*param_3 >> 0x20);
  fVar8 = (float)*param_2;
  if (((((*(float *)((longlong)param_2 + 4) != 0.0) || (NAN(*(float *)((longlong)param_2 + 4)))) ||
       (fVar3 != 0.0)) || ((NAN(fVar3) || (fVar11 != 0.0)))) ||
     ((NAN(fVar11) || ((fVar9 != 0.0 || (NAN(fVar9))))))) {
    pfVar5 = (float *)*param_1;
    if (pfVar5 == (float *)0x0) goto LAB_140002a47;
    fVar12 = *(float *)((longlong)param_3 + 0xc);
    fVar10 = (float)((ulonglong)*param_2 >> 0x20);
    fVar1 = *(float *)((longlong)param_2 + 0xc);
    *pfVar5 = fVar9 * fVar10 + fVar8 * fVar4;
    pfVar5[1] = fVar12 * fVar10 + fVar8 * fVar11;
    pfVar5[2] = fVar1 * fVar9 + fVar3 * fVar4;
    pfVar5[3] = fVar1 * fVar12 + fVar3 * fVar11;
  }
  else {
    pfVar5 = (float *)*param_1;
    if (pfVar5 == (float *)0x0) {
LAB_140002a47:
                    /* WARNING: Subroutine does not return */
      _RNvNtCsloaxXL3qbEI_4core6option13unwrap_failed();
    }
    *pfVar5 = fVar8 * fVar4;
    fVar12 = *(float *)((longlong)param_3 + 0xc);
    pfVar5[3] = *(float *)((longlong)param_2 + 0xc) * fVar12;
    pfVar5[1] = 0.0;
    pfVar5[2] = 0.0;
  }
  fVar3 = *(float *)(param_2 + 2);
  fVar8 = *(float *)((longlong)param_2 + 0x14);
  if ((((fVar3 != 0.0) || (NAN(fVar3))) || (fVar8 != 0.0)) || (NAN(fVar8))) {
    fVar9 = *(float *)(param_3 + 2) + fVar8 * fVar9 + fVar4 * fVar3;
    *(ulonglong *)(pfVar5 + 4) =
         CONCAT44(*(float *)((longlong)param_3 + 0x14) + fVar8 * fVar12 + fVar11 * fVar3,fVar9);
    uVar2 = _RNvNtCslMg0IV26qJh_12gdi_bindings6efloat6bEfToL((uint)fVar9);
    fVar3 = SUB84(param_2,0);
    fVar9 = fVar3;
    in_RAX = _RNvNtCslMg0IV26qJh_12gdi_bindings6efloat6bEfToL((uint)pfVar5[5]);
    if (((int)uVar2 != 1) || (pfVar5[6] = fVar3, (int)in_RAX != 1)) {
      return 0;
    }
  }
  else {
    pfVar5[4] = *(float *)(param_3 + 2);
    pfVar5[5] = *(float *)((longlong)param_3 + 0x14);
    fVar3 = *(float *)(param_3 + 3);
    pfVar5[6] = fVar3;
    fVar9 = *(float *)((longlong)param_3 + 0x1c);
  }
  pfVar5[7] = fVar9;
  uVar2 = CONCAT71((int7)((ulonglong)in_RAX >> 8),1);
  if ((param_4 & 1) != 0) {
    fVar4 = (float)(param_4 & 0x38);
    fVar8 = (float)((int)fVar4 + 0x40);
    if (fVar3 != 0.0 || fVar9 != 0.0) {
      fVar8 = fVar4;
    }
    pfVar5[8] = fVar8;
    if (((pfVar5[1] == 0.0) && (!NAN(pfVar5[1]))) && ((pfVar5[2] == 0.0 && (!NAN(pfVar5[2]))))) {
      pfVar5[8] = (float)((uint)fVar8 | 1);
      fVar3 = *pfVar5;
      if (fVar4 == 1.12104e-44) {
        if (fVar3 != 16.0) {
          return uVar2;
        }
        if (NAN(fVar3)) {
          return uVar2;
        }
        bVar6 = NAN(pfVar5[3]);
        bVar7 = pfVar5[3] == 16.0;
      }
      else if (fVar4 == 4.48416e-44) {
        if (fVar3 != 1.0) {
          return uVar2;
        }
        if (NAN(fVar3)) {
          return uVar2;
        }
        bVar6 = NAN(pfVar5[3]);
        bVar7 = pfVar5[3] == 1.0;
      }
      else {
        if (fVar3 != 0.0625) {
          return uVar2;
        }
        if (NAN(fVar3)) {
          return uVar2;
        }
        bVar6 = NAN(pfVar5[3]);
        bVar7 = pfVar5[3] == 0.0625;
      }
      if ((bVar7) && (!bVar6)) {
        pfVar5[8] = (float)((uint)fVar8 | 3);
      }
    }
  }
  return uVar2;
}



===== _RNvMNtNtCsdyToaWEq7tk_8gdi_rust5xform12xformobj_cxxNtNtB4_10xformobj_h9EXFORMOBJ8bInverse @ 140002a60 =====

undefined8
_RNvMNtNtCsdyToaWEq7tk_8gdi_rust5xform12xformobj_cxxNtNtB4_10xformobj_h9EXFORMOBJ8bInverse
          (undefined8 *param_1,float *param_2)

{
  ulonglong uVar1;
  float *pfVar2;
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined8 uVar5;
  ulonglong uVar6;
  float fVar7;
  float fVar8;
  float fVar11;
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  undefined1 auVar12 [16];
  undefined1 auVar13 [16];
  float fVar14;
  float fVar15;
  
  fVar7 = SUB84(param_2,0);
  pfVar2 = (float *)*param_1;
  if (pfVar2 == (float *)0x0) {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core6option13unwrap_failed();
  }
  fVar8 = param_2[8];
  uVar6 = (ulonglong)(uint)fVar8;
  pfVar2[8] = (float)((uint)fVar8 & 0xffffffe7 | 0x10);
  if (((uint)fVar8 & 2) == 0) {
    fVar11 = *param_2;
    fVar14 = param_2[3];
    uVar1 = *(ulonglong *)(param_2 + 1);
    fVar15 = fVar11 * fVar14 - (float)(uVar1 >> 0x20) * (float)uVar1;
    if ((fVar15 != 0.0) || (NAN(fVar15))) {
      if (((uint)fVar8 & 1) == 0) {
        auVar12._0_8_ = uVar1 ^ 0x8000000080000000;
        auVar12._8_4_ = 0x80000000;
        auVar12._12_4_ = 0x80000000;
        auVar3._4_4_ = fVar15;
        auVar3._0_4_ = fVar15;
        auVar3._8_8_ = 0;
        auVar13 = divps(auVar12,auVar3);
        auVar9._4_4_ = fVar11;
        auVar9._0_4_ = fVar14;
        auVar9._8_8_ = 0;
        auVar4._4_4_ = fVar15;
        auVar4._0_4_ = fVar15;
        auVar4._8_8_ = 0;
        auVar10 = divps(auVar9,auVar4);
        *pfVar2 = auVar10._0_4_;
        pfVar2[1] = auVar13._0_4_;
        pfVar2[2] = auVar13._4_4_;
        pfVar2[3] = auVar10._4_4_;
        if (((uint)fVar8 & 0x40) != 0) {
LAB_140002b92:
          pfVar2[4] = 0.0;
          pfVar2[5] = 0.0;
          pfVar2[6] = 0.0;
          pfVar2[7] = 0.0;
          goto LAB_140002ae5;
        }
        fVar11 = (float)*(undefined8 *)(param_2 + 4);
        fVar14 = (float)((ulonglong)*(undefined8 *)(param_2 + 4) >> 0x20);
        fVar8 = auVar10._0_4_ * fVar11 + auVar13._4_4_ * fVar14;
        fVar11 = auVar10._4_4_ * fVar14 + auVar13._0_4_ * fVar11;
      }
      else {
        pfVar2[1] = 0.0;
        pfVar2[2] = 0.0;
        auVar10._4_4_ = fVar11;
        auVar10._0_4_ = fVar14;
        auVar10._8_8_ = 0;
        auVar13._4_4_ = fVar15;
        auVar13._0_4_ = fVar15;
        auVar13._8_8_ = 0;
        auVar10 = divps(auVar10,auVar13);
        *pfVar2 = auVar10._0_4_;
        pfVar2[3] = auVar10._4_4_;
        if (((uint)fVar8 & 0x40) != 0) goto LAB_140002b92;
        fVar8 = auVar10._0_4_ * (float)*(undefined8 *)(param_2 + 4);
        fVar11 = auVar10._4_4_ * (float)((ulonglong)*(undefined8 *)(param_2 + 4) >> 0x20);
      }
      *(ulonglong *)(pfVar2 + 4) = CONCAT44(fVar11,fVar8) ^ 0x8000000080000000;
      uVar5 = _RNvNtCslMg0IV26qJh_12gdi_bindings6efloat6bEfToL((uint)-fVar8);
      fVar8 = fVar7;
      uVar6 = _RNvNtCslMg0IV26qJh_12gdi_bindings6efloat6bEfToL((uint)pfVar2[5]);
      if (((int)uVar5 == 1) && (pfVar2[6] = fVar7, (int)uVar6 == 1)) {
        pfVar2[7] = fVar8;
        goto LAB_140002ae5;
      }
    }
    uVar5 = 0;
  }
  else {
    pfVar2[0] = 0.0625;
    pfVar2[1] = 0.0;
    pfVar2[2] = 0.0;
    pfVar2[3] = 0.0625;
    *(ulonglong *)(pfVar2 + 4) =
         CONCAT44((float)((ulonglong)*(undefined8 *)(param_2 + 4) >> 0x20) * -0.0625,
                  (float)*(undefined8 *)(param_2 + 4) * -0.0625);
    *(ulonglong *)(pfVar2 + 6) =
         CONCAT44(-(int)((longlong)*(undefined8 *)(param_2 + 6) >> 0x24),
                  -((int)*(undefined8 *)(param_2 + 6) >> 4));
LAB_140002ae5:
    uVar5 = CONCAT71((int7)(uVar6 >> 8),1);
  }
  return uVar5;
}



===== _RNvMNtNtCsdyToaWEq7tk_8gdi_rust5xform12xformobj_cxxNtNtB4_10xformobj_h9EXFORMOBJ13bComputeUnits @ 140002bc0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
_RNvMNtNtCsdyToaWEq7tk_8gdi_rust5xform12xformobj_cxxNtNtB4_10xformobj_h9EXFORMOBJ13bComputeUnits
          (undefined8 *param_1,int param_2,uint *param_3,float *param_4,float *param_5)

{
  float *pfVar1;
  code *pcVar2;
  undefined1 auVar3 [16];
  uint uVar4;
  undefined8 uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  float *pfVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  bool bVar16;
  undefined8 uVar17;
  undefined1 auVar18 [16];
  float fVar19;
  undefined1 auVar21 [12];
  uint uVar20;
  undefined1 auVar22 [16];
  undefined1 auVar23 [16];
  undefined1 auStackY_98 [32];
  float local_70;
  float fStack_6c;
  float local_68;
  float local_64;
  ulonglong local_60;
  
  local_60 = __security_cookie ^ (ulonglong)auStackY_98;
  iVar14 = -param_2;
  if (-param_2 < 0) {
    iVar14 = param_2;
  }
  pfVar1 = (float *)*param_1;
  if (pfVar1 == (float *)0x0) {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core6option13unwrap_failed();
  }
  if (((iVar14 * -0x789abcdf + 0x91a2b0U >> 2 | iVar14 * 0x40000000) < 0x48d159) &&
     (((uint)pfVar1[8] & 1) != 0)) {
    bVar16 = (iVar14 / 900 & 1U) == 0;
    pfVar10 = pfVar1 + 3;
    if (bVar16) {
      pfVar10 = pfVar1;
    }
    fVar19 = *pfVar10;
    if ((fVar19 == 0.0) && (!NAN(fVar19))) {
      if ((local_60 ^ (ulonglong)auStackY_98) == __security_cookie) {
        return 0;
      }
      goto LAB_1400031bf;
    }
    uVar20 = (uint)bVar16;
    auVar21._0_4_ = (int)(uVar20 << 0x1f) >> 0x1f;
    auVar21._4_4_ = (int)(uVar20 << 0x1f) >> 0x1f;
    auVar21._8_4_ = 0;
    auVar23._12_4_ = 0;
    auVar23._0_12_ = auVar21;
    auVar3._12_4_ = 0;
    auVar3._0_12_ = auVar21;
    if ((iVar14 / 900 & 2U) != 0) {
      fVar19 = -fVar19;
    }
    if (0.0 <= fVar19) {
      auVar18 = ZEXT416(0x3f800000) & auVar3 | ~auVar23 & ___xmm_00000000000000003f80000000000000;
      uVar20 = auVar18._4_4_;
      goto joined_r0x000140003130;
    }
    auVar18 = ZEXT416(0x3f800000) & auVar3 | ~auVar23 & ___xmm_00000000000000003f80000000000000;
    uVar20 = auVar18._4_4_ ^ 0x80000000;
    uVar9 = auVar18._0_4_ ^ 0x80000000;
    fVar19 = -fVar19;
  }
  else {
    uVar5 = _RNvNtCslMg0IV26qJh_12gdi_bindings7draweng5efCos
                      ((ulonglong)(uint)((float)iVar14 / 10.0));
    local_70 = (float)uVar5;
    uVar17 = _RNvNtCslMg0IV26qJh_12gdi_bindings7draweng5efSin
                       ((ulonglong)(uint)((float)iVar14 / 10.0));
    fStack_6c = (float)uVar17;
    local_68 = (float)uVar5;
    local_64 = fStack_6c;
    _RNvMNtNtCsdyToaWEq7tk_8gdi_rust5xform12xformobj_cxxNtNtB4_10xformobj_h9EXFORMOBJ24bXform_vectorfl_vectorfl
              (param_1,&local_68,1,&local_70,1);
    auVar18._4_4_ = fStack_6c;
    auVar18._0_4_ = local_70;
    auVar18._8_8_ = 0;
    fVar19 = fStack_6c * fStack_6c + local_70 * local_70;
    uVar7 = (uint)fVar19 >> 0x17 & 0xff;
    uVar20 = uVar7 + 0x7f;
    uVar11 = uVar20 & 1;
    uVar12 = ((uint)fVar19 & 0x7fffff | 0x800000) << (char)uVar11 + 7;
    uVar4 = ((uVar12 >> 0x1e) - 1) * 4 | (uVar12 & 0x3fffffff) >> 0x1c;
    iVar14 = 3 - (uint)(uVar4 < 5);
    uVar9 = uVar4 + 0x3ffffffb;
    if (uVar4 < 5) {
      uVar9 = uVar4;
    }
    uVar8 = (uVar12 & 0xfffffff) >> 0x1a | uVar9 << 2;
    uVar6 = iVar14 * 4;
    uVar4 = 0;
    uVar9 = ~uVar6;
    if (uVar6 >= uVar8) {
      uVar9 = uVar4;
    }
    iVar14 = (uint)(uVar6 < uVar8) + iVar14 * 2;
    uVar6 = (uVar9 + uVar8) * 4 | (uVar12 & 0x3ffffff) >> 0x18;
    uVar8 = iVar14 * 4;
    uVar9 = ~uVar8;
    if (uVar8 >= uVar6) {
      uVar9 = uVar4;
    }
    uVar15 = (uVar9 + uVar6) * 4 | (uVar12 & 0xffffff) >> 0x16;
    iVar14 = (uint)(uVar8 < uVar6) + iVar14 * 2;
    uVar6 = iVar14 * 4;
    iVar14 = (uint)(uVar6 < uVar15) + iVar14 * 2;
    uVar9 = ~uVar6;
    if (uVar6 >= uVar15) {
      uVar9 = uVar4;
    }
    uVar6 = (uVar9 + uVar15) * 4 | (uVar12 & 0x3fffff) >> 0x14;
    uVar8 = iVar14 * 4;
    iVar14 = (uint)(uVar8 < uVar6) + iVar14 * 2;
    uVar9 = ~uVar8;
    if (uVar8 >= uVar6) {
      uVar9 = uVar4;
    }
    uVar8 = (uVar9 + uVar6) * 4 | (uVar12 & 0xfffff) >> 0x12;
    uVar6 = iVar14 * 4;
    uVar9 = ~uVar6;
    if (uVar6 >= uVar8) {
      uVar9 = uVar4;
    }
    iVar14 = (uint)(uVar6 < uVar8) + iVar14 * 2;
    uVar6 = (uVar9 + uVar8) * 4 | (uVar12 & 0x3ffff) >> 0x10;
    uVar8 = iVar14 * 4;
    uVar9 = ~uVar8;
    if (uVar8 >= uVar6) {
      uVar9 = uVar4;
    }
    uVar15 = (uVar9 + uVar6) * 4 | (uVar12 & 0xffff) >> 0xe;
    iVar14 = (uint)(uVar8 < uVar6) + iVar14 * 2;
    uVar6 = iVar14 * 4;
    iVar14 = (uint)(uVar6 < uVar15) + iVar14 * 2;
    uVar9 = ~uVar6;
    if (uVar6 >= uVar15) {
      uVar9 = uVar4;
    }
    uVar6 = (uVar9 + uVar15) * 4 | (uVar12 & 0x3fff) >> 0xc;
    uVar8 = iVar14 * 4;
    iVar14 = (uint)(uVar8 < uVar6) + iVar14 * 2;
    uVar9 = ~uVar8;
    if (uVar8 >= uVar6) {
      uVar9 = uVar4;
    }
    uVar8 = (uVar9 + uVar6) * 4 | (uVar12 & 0xfff) >> 10;
    uVar6 = iVar14 * 4;
    uVar9 = ~uVar6;
    if (uVar6 >= uVar8) {
      uVar9 = uVar4;
    }
    iVar14 = (uint)(uVar6 < uVar8) + iVar14 * 2;
    uVar6 = (uVar9 + uVar8) * 4 | (uVar12 & 0x3ff) >> 8;
    uVar8 = iVar14 * 4;
    uVar9 = ~uVar8;
    if (uVar8 >= uVar6) {
      uVar9 = uVar4;
    }
    uVar15 = (uVar9 + uVar6) * 4 | (uVar12 & 0xff) >> 6;
    iVar14 = (uint)(uVar8 < uVar6) + iVar14 * 2;
    uVar6 = iVar14 * 4;
    iVar14 = (uint)(uVar6 < uVar15) + iVar14 * 2;
    uVar9 = ~uVar6;
    if (uVar6 >= uVar15) {
      uVar9 = uVar4;
    }
    uVar6 = (uVar9 + uVar15) * 4 | (uVar12 & 0x3f) >> 4;
    uVar8 = iVar14 * 4;
    iVar14 = (uint)(uVar8 < uVar6) + iVar14 * 2;
    uVar9 = ~uVar8;
    if (uVar8 >= uVar6) {
      uVar9 = uVar4;
    }
    uVar8 = (uVar9 + uVar6) * 4 | (uVar12 & 0xf) >> 2;
    uVar6 = iVar14 * 4;
    iVar14 = (uint)(uVar6 < uVar8) + iVar14 * 2;
    uVar9 = ~uVar6;
    if (uVar6 >= uVar8) {
      uVar9 = uVar4;
    }
    uVar6 = (uVar9 + uVar8) * 4 | uVar12 & 3;
    uVar12 = iVar14 * 4;
    iVar14 = (uint)(uVar12 < uVar6) + iVar14 * 2;
    uVar9 = ~uVar12;
    if (uVar12 >= uVar6) {
      uVar9 = uVar4;
    }
    uVar12 = iVar14 * 4;
    bVar16 = uVar12 < (uVar9 + uVar6) * 4;
    uVar12 = ~uVar12;
    if (!bVar16) {
      uVar12 = uVar4;
    }
    iVar13 = (uint)bVar16 + iVar14 * 2;
    iVar14 = uVar12 + (uVar9 + uVar6) * 4;
    uVar9 = iVar13 * 4;
    bVar16 = uVar9 < (uint)(iVar14 * 4);
    iVar13 = (uint)bVar16 + iVar13 * 2;
    uVar9 = ~uVar9;
    if (!bVar16) {
      uVar9 = uVar4;
    }
    iVar14 = uVar9 + iVar14 * 4;
    uVar9 = iVar13 * 4;
    bVar16 = uVar9 < (uint)(iVar14 * 4);
    uVar9 = ~uVar9;
    if (!bVar16) {
      uVar9 = uVar4;
    }
    iVar13 = (uint)bVar16 + iVar13 * 2;
    iVar14 = uVar9 + iVar14 * 4;
    uVar9 = iVar13 * 4;
    bVar16 = uVar9 < (uint)(iVar14 * 4);
    iVar13 = (uint)bVar16 + iVar13 * 2;
    uVar9 = ~uVar9;
    if (!bVar16) {
      uVar9 = uVar4;
    }
    iVar14 = uVar9 + iVar14 * 4;
    uVar9 = iVar13 * 4;
    bVar16 = uVar9 < (uint)(iVar14 * 4);
    uVar9 = ~uVar9;
    if (!bVar16) {
      uVar9 = uVar4;
    }
    iVar13 = (uint)bVar16 + iVar13 * 2;
    iVar14 = uVar9 + iVar14 * 4;
    uVar9 = iVar13 * 4;
    bVar16 = uVar9 < (uint)(iVar14 * 4);
    iVar13 = (uint)bVar16 + iVar13 * 2;
    uVar9 = ~uVar9;
    if (!bVar16) {
      uVar9 = uVar4;
    }
    iVar14 = uVar9 + iVar14 * 4;
    uVar9 = iVar13 * 4;
    bVar16 = uVar9 < (uint)(iVar14 * 4);
    uVar9 = ~uVar9;
    if (!bVar16) {
      uVar9 = uVar4;
    }
    uVar12 = (uint)bVar16 + iVar13 * 2;
    uVar4 = uVar7 + 0x7e;
    if (uVar11 == 0) {
      uVar4 = uVar20;
    }
    fVar19 = (float)((uVar4 & 0x1fe) * 0x400000 + (uVar12 & 0x3fffff) * 2 |
                    (uint)(uVar12 * 4 < (uVar9 + iVar14 * 4) * 4));
    if ((fVar19 == 0.0) && (!NAN(fVar19))) {
      if ((local_60 ^ (ulonglong)auStackY_98) == __security_cookie) {
        return 0;
      }
      goto LAB_1400031bf;
    }
    auVar22._4_4_ = fVar19;
    auVar22._0_4_ = fVar19;
    auVar22._8_8_ = 0;
    auVar18 = divps(auVar18,auVar22);
    fVar19 = fVar19 * 16.0;
    uVar20 = auVar18._4_4_;
joined_r0x000140003130:
    uVar9 = auVar18._0_4_;
  }
  if (param_2 < 0) {
    uVar20 = uVar20 ^ 0x80000000;
  }
  *param_3 = uVar9;
  param_3[1] = uVar20;
  *param_4 = fVar19;
  *param_5 = 1.0 / fVar19;
  if ((local_60 ^ (ulonglong)auStackY_98) == __security_cookie) {
                    /* WARNING: Read-only address (ram,0x00014001a580) is written */
    return CONCAT71((int7)((ulonglong)param_5 >> 8),1);
  }
LAB_1400031bf:
  pcVar2 = (code *)swi(3);
  uVar5 = (*pcVar2)();
  return uVar5;
}



===== _RNvMs_NtNtCsdyToaWEq7tk_8gdi_rust5xform12xformobj_cxxNtNtB6_10xformobj_h10EXFORMOBJR32bXformRound_umptr_pointl_pointfx @ 140003210 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
_RNvMs_NtNtCsdyToaWEq7tk_8gdi_rust5xform12xformobj_cxxNtNtB6_10xformobj_h10EXFORMOBJR32bXformRound_umptr_pointl_pointfx
          (longlong *******param_1,longlong *******param_2,undefined **param_3,
          longlong *******param_4)

{
  undefined **ppuVar1;
  undefined **ppuVar2;
  code *pcVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined8 uVar11;
  undefined **ppuVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  longlong *******ppppppplVar15;
  ulonglong uVar16;
  undefined1 auStack_b8 [44];
  undefined4 local_8c;
  code *local_88;
  longlong *******local_80;
  code **local_78;
  longlong *******local_70;
  longlong ********local_68;
  code **local_60;
  longlong *******local_58;
  longlong *******local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_b8;
  if (*param_1 == (longlong ******)0x0) {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core6option13unwrap_failed();
  }
  if ((~*(uint *)(*param_1 + 4) & 0x43) == 0) {
    local_88 = core::ops::function::FnOnce::
               call_once<gdi_rust::xform::xformobj_cxx::impl_1::bXformRound_umptr_pointl_pointfx::closure_env_0,tuple_<onecore_windows::windef::_POINTL>_>
    ;
    if (((ulonglong)param_4 >> 0x3d != 0) ||
       ((longlong *******)((longlong)param_2[1] - (longlong)param_2[2]) < param_4)) {
      *(undefined1 *)(param_2 + 3) = 1;
LAB_140003471:
      if ((local_48 ^ (ulonglong)auStack_b8) == __security_cookie) {
        return 0x57;
      }
      goto LAB_140003487;
    }
    uVar11 = 0x57;
    if ((*(char *)((longlong)param_2 + 0x19) == '\0') && (*(char *)(param_2 + 3) == '\0')) {
      if (param_4 != (longlong *******)0x0) {
        ppppppplVar15 = (longlong *******)0x0;
        do {
          local_68 = &local_80;
          local_60 = &local_88;
          local_8c = 0;
          local_80 = ppppppplVar15;
          local_78 = (code **)param_3;
          local_70 = param_4;
          local_58 = param_2;
          local_50 = param_2 + 2;
          uVar11 = CallInTryExcept(_RINvNvNtCs4xf65G0cUDK_10seh_unwind14implementation12catch_unwind7do_callNCINvMs_NtCsdyToaWEq7tk_8gdi_rust5umptrINtB1g_5umptrNtNtCs2JCLxFJL4Mh_15onecore_windows6windef7__POINTLE9enumerateNtNtB22_7winddip9__POINTFIXE0uEB1i__llvm_7047519757781241447
                                   ,&local_78);
          if ((char)uVar11 == '\0') {
            umptr_inpage_warning();
            *(undefined1 *)((longlong)param_2 + 0x19) = 1;
            goto LAB_140003471;
          }
          ppppppplVar15 = (longlong *******)((longlong)ppppppplVar15 + 1);
        } while (param_4 != ppppppplVar15);
      }
      if ((local_48 ^ (ulonglong)auStack_b8) == __security_cookie) {
        return 0;
      }
      goto LAB_140003487;
    }
  }
  else {
    local_88 = (code *)((ulonglong)local_88 & 0xffffffffffffff00);
    local_78 = &local_88;
    local_80 = (longlong *******)((ulonglong)local_80 & 0xffffffff00000000);
    local_70 = param_1;
    local_68 = (longlong ********)param_2;
    local_60 = (code **)param_3;
    local_58 = param_4;
    uVar11 = CallInTryExcept(_RINvNvNtCs4xf65G0cUDK_10seh_unwind14implementation12catch_unwind7do_callNCNvMs_NtNtCsdyToaWEq7tk_8gdi_rust5xform12xformobj_cxxNtNtB1h_10xformobj_h10EXFORMOBJR32bXformRound_umptr_pointl_pointfxs_0uEB1j__llvm_7047519757781241447
                             ,&local_78);
    if ((char)uVar11 == '\0') {
      umptr_inpage_warning();
      *(undefined1 *)((longlong)param_2 + 0x19) = 1;
      local_88 = (code *)((ulonglong)local_88 & 0xffffffffffffff00);
    }
    if ((*(char *)(param_1 + 1) != '\0') && (param_4 != (longlong *******)0x0)) {
      uVar13 = (longlong)param_4 - 1U & 0x1fffffffffffffff;
      ppuVar12 = param_3;
      if (2 < uVar13) {
        uVar13 = uVar13 + 1;
        uVar14 = uVar13 & 0xfffffffffffffffc;
        ppuVar12 = param_3 + uVar14;
        uVar16 = 0;
        do {
          ppuVar1 = param_3 + uVar16;
          iVar4 = *(int *)((longlong)ppuVar1 + 4);
          iVar5 = *(int *)(ppuVar1 + 1);
          iVar6 = *(int *)((longlong)ppuVar1 + 0xc);
          ppuVar2 = param_3 + uVar16 + 2;
          iVar7 = *(int *)ppuVar2;
          iVar8 = *(int *)((longlong)ppuVar2 + 4);
          iVar9 = *(int *)(ppuVar2 + 1);
          iVar10 = *(int *)((longlong)ppuVar2 + 0xc);
          ppuVar2 = param_3 + uVar16;
          *(uint *)ppuVar2 = *(int *)ppuVar1 + 8U & 0xfffffff0;
          *(uint *)((longlong)ppuVar2 + 4) = iVar4 + 8U & 0xfffffff0;
          *(uint *)(ppuVar2 + 1) = iVar5 + 8U & 0xfffffff0;
          *(uint *)((longlong)ppuVar2 + 0xc) = iVar6 + 8U & 0xfffffff0;
          ppuVar1 = param_3 + uVar16 + 2;
          *(uint *)ppuVar1 = iVar7 + 8U & 0xfffffff0;
          *(uint *)((longlong)ppuVar1 + 4) = iVar8 + 8U & 0xfffffff0;
          *(uint *)(ppuVar1 + 1) = iVar9 + 8U & 0xfffffff0;
          *(uint *)((longlong)ppuVar1 + 0xc) = iVar10 + 8U & 0xfffffff0;
          uVar16 = uVar16 + 4;
        } while (uVar14 != uVar16);
        if (uVar13 == uVar14) goto LAB_14000343c;
      }
      do {
        *ppuVar12 = (undefined *)
                    (CONCAT44((int)((ulonglong)*ppuVar12 >> 0x20) + 8,(int)*ppuVar12 + 8) &
                    0xfffffff0fffffff0);
        ppuVar12 = ppuVar12 + 1;
      } while (ppuVar12 != param_3 + (longlong)param_4);
    }
LAB_14000343c:
    uVar11 = 0x57;
    if ((char)local_88 != '\0') {
      uVar11 = 0;
    }
  }
  if ((local_48 ^ (ulonglong)auStack_b8) == __security_cookie) {
    return uVar11;
  }
LAB_140003487:
  pcVar3 = (code *)swi(3);
  uVar11 = (*pcVar3)();
  return uVar11;
}



===== _RNvMs_NtNtCsdyToaWEq7tk_8gdi_rust5xform12xformobj_cxxNtNtB6_10xformobj_h10EXFORMOBJR28bXformRound_vectorl_vectorfx @ 1400034b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
_RNvMs_NtNtCsdyToaWEq7tk_8gdi_rust5xform12xformobj_cxxNtNtB6_10xformobj_h10EXFORMOBJR28bXformRound_vectorl_vectorfx
          (undefined8 *param_1,longlong param_2,longlong param_3,ulonglong *param_4,longlong param_5
          )

{
  ulonglong *puVar1;
  ulonglong *puVar2;
  int iVar3;
  int iVar4;
  float *pfVar5;
  code *pcVar6;
  int iVar7;
  int iVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  undefined8 uVar12;
  longlong lVar13;
  ulonglong *puVar14;
  ulonglong uVar15;
  ulonglong uVar16;
  ulonglong uVar17;
  undefined1 auStackY_88 [32];
  longlong local_58;
  undefined **local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStackY_88;
  local_58 = param_3;
  if (param_3 == param_5) {
    pfVar5 = (float *)*param_1;
    if (pfVar5 != (float *)0x0) {
      if (((uint)pfVar5[8] & 2) == 0) {
        uVar12 = _RNvNtNtCsdyToaWEq7tk_8gdi_rust5xform7xformer7bCvtVts
                           (pfVar5,param_2,param_3,(longlong)param_4,param_3);
        if ((char)uVar12 == '\0') {
          EngSetLastError(0x216);
        }
        if ((*(char *)(param_1 + 1) == '\x01') && (param_3 != 0)) {
          uVar15 = param_3 - 1U & 0x1fffffffffffffff;
          puVar14 = param_4;
          if (2 < uVar15) {
            uVar15 = uVar15 + 1;
            uVar16 = uVar15 & 0xfffffffffffffffc;
            puVar14 = param_4 + uVar16;
            uVar17 = 0;
            do {
              puVar1 = param_4 + uVar17;
              iVar3 = *(int *)((longlong)puVar1 + 4);
              uVar9 = puVar1[1];
              iVar4 = *(int *)((longlong)puVar1 + 0xc);
              puVar2 = param_4 + uVar17 + 2;
              uVar10 = *puVar2;
              iVar7 = *(int *)((longlong)puVar2 + 4);
              uVar11 = puVar2[1];
              iVar8 = *(int *)((longlong)puVar2 + 0xc);
              puVar2 = param_4 + uVar17;
              *(uint *)puVar2 = (int)*puVar1 + 8U & 0xfffffff0;
              *(uint *)((longlong)puVar2 + 4) = iVar3 + 8U & 0xfffffff0;
              *(uint *)(puVar2 + 1) = (int)uVar9 + 8U & 0xfffffff0;
              *(uint *)((longlong)puVar2 + 0xc) = iVar4 + 8U & 0xfffffff0;
              puVar1 = param_4 + uVar17 + 2;
              *(uint *)puVar1 = (int)uVar10 + 8U & 0xfffffff0;
              *(uint *)((longlong)puVar1 + 4) = iVar7 + 8U & 0xfffffff0;
              *(uint *)(puVar1 + 1) = (int)uVar11 + 8U & 0xfffffff0;
              *(uint *)((longlong)puVar1 + 0xc) = iVar8 + 8U & 0xfffffff0;
              uVar17 = uVar17 + 4;
            } while (uVar16 != uVar17);
            if (uVar15 == uVar16) goto LAB_140003636;
          }
          do {
            *puVar14 = CONCAT44((int)(*puVar14 >> 0x20) + 8,(int)*puVar14 + 8) & 0xfffffff0fffffff0;
            puVar14 = puVar14 + 1;
          } while (puVar14 != param_4 + param_3);
        }
      }
      else if (param_3 != 0) {
        lVar13 = 0;
        do {
          iVar3 = *(int *)(param_2 + lVar13 * 8);
          if ((0xffffffc < iVar3 + 0x7fffffeU) ||
             (iVar4 = *(int *)(param_2 + 4 + lVar13 * 8), 0xffffffc < iVar4 + 0x7fffffeU)) {
            EngSetLastError(0x216);
            if ((local_20 ^ (ulonglong)auStackY_88) == __security_cookie) {
              return 0x216;
            }
            goto LAB_14000366f;
          }
          *(int *)(param_4 + lVar13) = iVar3 << 4;
          *(int *)((longlong)param_4 + lVar13 * 8 + 4) = iVar4 << 4;
          lVar13 = lVar13 + 1;
        } while (param_3 != lVar13);
      }
LAB_140003636:
      if ((local_20 ^ (ulonglong)auStackY_88) == __security_cookie) {
        return 0;
      }
LAB_14000366f:
      pcVar6 = (code *)swi(3);
      uVar12 = (*pcVar6)();
      return uVar12;
    }
  }
  else {
    local_50 = &PTR_s_Src_and_Dst_are_of_different_siz_140019030;
    local_48 = 1;
    local_40 = 8;
    local_38 = 0;
    uStack_30 = 0;
    _RINvNtCsloaxXL3qbEI_4core9panicking13assert_failedjjEB4_
              (0,&local_58,&param_5,(longlong *)&local_50);
  }
                    /* WARNING: Subroutine does not return */
  _RNvNtCsloaxXL3qbEI_4core6option13unwrap_failed();
}



===== __llvm_retpoline_r11 @ 1400036e0 =====

void __llvm_retpoline_r11(void)

{
  FUN_1400036f0();
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



===== FUN_1400036f0 @ 1400036f0 =====

void FUN_1400036f0(void)

{
  return;
}



===== _RINvCsgf1RBdmyjwT_12fallible_vec20try_with_capacity_inNtNtNtCsdyToaWEq7tk_8gdi_rust6region9from_path4EdgeINtCsiNQa5DCRmUC_9gdi_alloc15TaggedAllocatorKm67646547_EEBW_ @ 140003700 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong *
_RINvCsgf1RBdmyjwT_12fallible_vec20try_with_capacity_inNtNtNtCsdyToaWEq7tk_8gdi_rust6region9from_path4EdgeINtCsiNQa5DCRmUC_9gdi_alloc15TaggedAllocatorKm67646547_EEBW_
          (ulonglong *param_1,ulonglong param_2)

{
  code *pcVar1;
  undefined1 auVar2 [16];
  ulonglong uVar3;
  ulonglong *puVar4;
  ulonglong uVar5;
  undefined1 auStack_98 [32];
  ulonglong *local_78;
  ulonglong local_68;
  ulonglong local_60;
  ulonglong local_58;
  byte local_50 [8];
  ulonglong local_48;
  ulonglong uStack_40;
  undefined8 local_38;
  undefined8 local_30;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_98;
  local_68 = 0;
  local_60 = 8;
  local_58 = 0;
  if (param_2 != 0) {
    uVar5 = 4;
    if (4 < param_2) {
      uVar5 = param_2;
    }
    auVar2._8_8_ = 0;
    auVar2._0_8_ = uVar5;
    uVar3 = SUB168(auVar2 * ZEXT816(0x30),0);
    if (!(bool)(~(SUB168(auVar2 * ZEXT816(0x30),8) != 0) & uVar3 < 0x7ffffffffffffff9)) {
      param_1[1] = 0;
      *param_1 = 0x8000000000000000;
      if ((local_20 ^ (ulonglong)auStack_98) == __security_cookie) {
        return param_1;
      }
      goto LAB_14000383e;
    }
    local_30 = 0;
    local_78 = &local_58;
    _RINvNtCsip5f2bf5HGI_5alloc7raw_vec11finish_growINtCsiNQa5DCRmUC_9gdi_alloc15TaggedAllocatorKm67646547_EECsdyToaWEq7tk_8gdi_rust_llvm_17353492243722970462
              ((ulonglong *)local_50,&DAT_00000008,uVar3,&local_38);
    if ((local_50[0] & 1) != 0) {
      param_1[1] = local_48;
      param_1[2] = uStack_40;
      *param_1 = 0x8000000000000000;
      if (local_68 != 0) {
        _RNvNtCsiNQa5DCRmUC_9gdi_alloc3ffi13Win32FreePool();
      }
      if ((local_20 ^ (ulonglong)auStack_98) == __security_cookie) {
        return param_1;
      }
      goto LAB_14000383e;
    }
    local_60 = local_48;
    local_68 = uVar5;
  }
  param_1[2] = local_58;
  *param_1 = local_68;
  param_1[1] = local_60;
  if ((local_20 ^ (ulonglong)auStack_98) == __security_cookie) {
    return param_1;
  }
LAB_14000383e:
  pcVar1 = (code *)swi(3);
  puVar4 = (ulonglong *)(*pcVar1)();
  return puVar4;
}



===== _RINvMNtCscIyU0BP6seX_7rgncore9fill_pathNtB5_10RegionCore30fill_path_with_outline_genericNtNtCsdyToaWEq7tk_8gdi_rust6region12EPATHOBJSinkEB1s_ @ 140003850 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong _RINvMNtCscIyU0BP6seX_7rgncore9fill_pathNtB5_10RegionCore30fill_path_with_outline_genericNtNtCsdyToaWEq7tk_8gdi_rust6region12EPATHOBJSinkEB1s_
                    (longlong param_1,longlong *param_2)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  code *pcVar6;
  char cVar7;
  int iVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  longlong *plVar11;
  undefined8 uVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  ulonglong uVar15;
  ulonglong uVar16;
  ulonglong uVar17;
  longlong lVar18;
  ulonglong uVar19;
  ulonglong uVar20;
  ulonglong uVar21;
  ulonglong uVar22;
  longlong *plVar23;
  longlong *plVar24;
  longlong *plVar25;
  ulonglong uVar26;
  longlong *plVar27;
  ulonglong uVar28;
  uint uVar29;
  ulonglong uVar30;
  bool bVar31;
  undefined1 auStackY_138 [32];
  longlong *local_110;
  uint local_104;
  ulonglong local_100;
  longlong local_d8;
  ulonglong local_88;
  longlong *local_80;
  ulonglong local_78;
  longlong *local_70;
  int local_60;
  undefined4 local_5c;
  undefined8 local_58;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_138;
  uVar14 = *(ulonglong *)(param_1 + 0x10);
  if (uVar14 == 0) {
    local_110 = (longlong *)0x1;
    local_100 = 0;
    plVar27 = param_2;
  }
  else {
    local_100 = 8;
    if (8 < uVar14) {
      local_100 = uVar14;
    }
    local_58 = 0;
    _RINvNtCsip5f2bf5HGI_5alloc7raw_vec11finish_growNtNtB4_5alloc6GlobalECscIyU0BP6seX_7rgncore_llvm_13477870103536380358
              (&local_78,(void *)0x1,local_100,(undefined8 *)&local_60);
    if ((int)local_78 == 1) {
      local_104 = 0xe;
LAB_1400045da:
      if ((local_48 ^ (ulonglong)auStackY_138) == __security_cookie) {
        return (ulonglong)local_104;
      }
      pcVar6 = (code *)swi(3);
      uVar14 = (*pcVar6)();
      return uVar14;
    }
    local_110 = local_70;
    plVar27 = (longlong *)0x0;
    _weak_memset_default___llvm_retpoline_r11(local_70,0,uVar14);
  }
  local_88 = _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore10first_scan(param_1);
  local_80 = plVar27;
  if (plVar27 < *(longlong **)(local_88 + 0x10)) {
    lVar2 = *param_2;
    lVar3 = param_2[1];
    do {
      uVar9 = (ulonglong)*(int *)(*(longlong *)(local_88 + 8) + (longlong)local_80 * 4);
      if (uVar9 != 0) {
        uVar28 = 1;
        uVar15 = 0;
        do {
          uVar10 = uVar28;
          cVar7 = _RNvNvMNtCscIyU0BP6seX_7rgncore9fill_pathNtB6_10RegionCore30fill_path_with_outline_generic9is_framed
                            ((longlong)&local_88,uVar15,(longlong)local_110,uVar14);
          if (cVar7 == '\0') {
            local_78 = local_88;
            local_70 = local_80;
            plVar27 = *(longlong **)(local_88 + 0x10);
            if (plVar27 <= local_80) {
LAB_1400046b9:
                    /* WARNING: Subroutine does not return */
              _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
            }
            lVar18 = *(longlong *)(local_88 + 8);
            if ((ulonglong)(longlong)*(int *)(lVar18 + (longlong)local_80 * 4) <= uVar15) {
LAB_140004537:
                    /* WARNING: Subroutine does not return */
              _RNvNtCsloaxXL3qbEI_4core9panicking5panic();
            }
            plVar11 = (longlong *)((longlong)local_80 + uVar15 + 3);
            if (plVar27 <= plVar11) {
LAB_1400046d1:
                    /* WARNING: Subroutine does not return */
              _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
            }
            if (plVar27 <= (longlong *)((longlong)local_80 + 1U)) {
LAB_140004773:
                    /* WARNING: Subroutine does not return */
              _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
            }
            local_60 = *(int *)(lVar18 + (longlong)plVar11 * 4);
            local_5c = *(undefined4 *)(lVar18 + 4 + (longlong)local_80 * 4);
            iVar8 = EPATHOBJ_bMoveTo(lVar2,lVar3,&local_60);
            uVar28 = local_78;
            local_104 = 0x1f;
            if (iVar8 == 0) goto joined_r0x000140004617;
            if (*(longlong **)(local_78 + 0x10) <= local_70) goto LAB_1400046b9;
            plVar27 = (longlong *)
                      ((longlong)local_70 +
                      (longlong)*(int *)(*(longlong *)(local_78 + 8) + (longlong)local_70 * 4) + 4);
            uVar12 = _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalRINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E13is_valid_scanCsdyToaWEq7tk_8gdi_rust_llvm_12588874305795175024
                               (local_78,(ulonglong)plVar27);
            uVar29 = (uint)uVar15 & 1;
            uVar30 = (ulonglong)uVar29;
            _RNvNvMNtCscIyU0BP6seX_7rgncore9fill_pathNtB6_10RegionCore30fill_path_with_outline_generic11mark_framed
                      ((longlong)&local_78,uVar15,param_1,(longlong)local_110,uVar14);
            uVar13 = ~uVar30;
            uVar19 = uVar15;
            if ((char)uVar12 == '\0') {
              uVar28 = 0;
            }
joined_r0x000140003a8d:
            lVar18 = 1;
            if (uVar28 != 0) {
              do {
                lVar18 = 1;
                plVar11 = *(longlong **)(uVar28 + 0x10);
                if (plVar11 <= plVar27) {
LAB_140004656:
                    /* WARNING: Subroutine does not return */
                  _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
                }
                lVar4 = *(longlong *)(uVar28 + 8);
                uVar22 = (ulonglong)*(int *)(lVar4 + (longlong)plVar27 * 4);
                if (uVar22 == 0) break;
                plVar24 = *(longlong **)(local_78 + 0x10);
                if (plVar24 <= local_70) {
                    /* WARNING: Subroutine does not return */
                  _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
                }
                lVar5 = *(longlong *)(local_78 + 8);
                uVar17 = (ulonglong)*(int *)(lVar5 + (longlong)local_70 * 4);
                if (uVar17 <= uVar19) goto LAB_140004537;
                plVar25 = (longlong *)((longlong)local_70 + uVar19 + 3);
                if (plVar24 <= plVar25) {
                    /* WARNING: Subroutine does not return */
                  _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
                }
                if (uVar22 <= uVar30) goto LAB_140004537;
                plVar23 = (longlong *)(uVar30 + 3 + (longlong)plVar27);
                if (plVar11 <= plVar23) goto LAB_140004647;
                iVar8 = *(int *)(lVar5 + (longlong)plVar25 * 4);
                uVar16 = uVar30;
                if (*(int *)(lVar4 + (longlong)plVar23 * 4) <= iVar8) {
                  uVar16 = uVar22 + uVar13;
                  if (!CARRY8(uVar22,uVar13)) goto LAB_140004537;
                  plVar25 = (longlong *)((longlong)plVar27 + uVar16 + 3);
                  if (plVar11 <= plVar25) goto LAB_140004647;
                  if (*(int *)(lVar4 + (longlong)plVar25 * 4) <= iVar8) {
                    lVar18 = 1;
                    break;
                  }
                  uVar20 = uVar22 - 1 >> 1;
                  uVar26 = uVar30;
                  if (uVar20 != uVar30) {
                    do {
                      while( true ) {
                        uVar21 = uVar20;
                        if (uVar22 <= uVar21) goto LAB_140004537;
                        plVar25 = (longlong *)((longlong)plVar27 + uVar21 + 3);
                        if (plVar11 <= plVar25) goto LAB_140004647;
                        if (*(int *)(lVar4 + (longlong)plVar25 * 4) <= iVar8) break;
                        uVar20 = uVar26 + uVar21 >> 1;
                        uVar16 = uVar21;
                        if (uVar20 == uVar26) goto LAB_140003bc0;
                      }
                      uVar20 = uVar21 + uVar16 >> 1;
                      uVar26 = uVar21;
                    } while (uVar20 != uVar21);
                  }
                }
LAB_140003bc0:
                if (((uint)uVar16 & 1) == uVar29) {
                  if (uVar22 <= uVar16) goto LAB_140004537;
                  plVar25 = (longlong *)((longlong)plVar27 + uVar16 + 3);
                  if (plVar11 <= plVar25) {
LAB_140004686:
                    /* WARNING: Subroutine does not return */
                    _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
                  }
                  if (uVar17 <= uVar19 + 1) goto LAB_140004537;
                  plVar23 = (longlong *)((longlong)local_70 + uVar19 + 4);
                  if (plVar24 <= plVar23) {
LAB_140004695:
                    /* WARNING: Subroutine does not return */
                    _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
                  }
                  lVar18 = 1;
                  uVar20 = uVar16;
                  if (*(int *)(lVar5 + (longlong)plVar23 * 4) <=
                      *(int *)(lVar4 + (longlong)plVar25 * 4)) break;
                }
                else {
                  uVar20 = uVar16 - 1;
                  if (uVar19 != 0) {
                    if (uVar22 <= uVar20) goto LAB_140004537;
                    plVar25 = (longlong *)((longlong)plVar27 + uVar16 + 2);
                    if (plVar11 <= plVar25) goto LAB_140004686;
                    if (uVar17 <= uVar19 - 1) goto LAB_140004537;
                    plVar23 = (longlong *)((longlong)local_70 + uVar19 + 2);
                    if (plVar24 <= plVar23) goto LAB_140004695;
                    if (*(int *)(lVar4 + (longlong)plVar25 * 4) <
                        *(int *)(lVar5 + (longlong)plVar23 * 4)) {
                      lVar18 = -1;
                      break;
                    }
                  }
                }
                uVar19 = uVar20;
                if (uVar22 <= uVar19) goto LAB_140004537;
                lVar18 = 1;
                plVar25 = (longlong *)((longlong)plVar27 + uVar19 + 3);
                if (plVar11 <= plVar25) goto LAB_140004647;
                iVar1 = *(int *)(lVar4 + (longlong)plVar25 * 4);
                if (iVar8 != iVar1) {
                  if (plVar24 <= (longlong *)((longlong)local_70 + 2U)) {
                    /* WARNING: Subroutine does not return */
                    _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
                  }
                  local_5c = *(undefined4 *)(lVar5 + 8 + (longlong)local_70 * 4);
                  local_58 = CONCAT44(local_5c,iVar1);
                  local_60 = iVar8;
                  iVar8 = EPATHOBJ_bPolyLineTo(lVar2,lVar3,&local_60,2);
                  if (iVar8 == 0) goto joined_r0x000140004617;
                  plVar11 = *(longlong **)(uVar28 + 0x10);
                }
                local_78 = uVar28;
                local_70 = plVar27;
                if (plVar11 <= plVar27) goto LAB_140004656;
                plVar27 = (longlong *)
                          ((longlong)plVar27 +
                          (longlong)*(int *)(*(longlong *)(uVar28 + 8) + (longlong)plVar27 * 4) + 4)
                ;
                uVar12 = _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalRINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E13is_valid_scanCsdyToaWEq7tk_8gdi_rust_llvm_12588874305795175024
                                   (uVar28,(ulonglong)plVar27);
                _RNvNvMNtCscIyU0BP6seX_7rgncore9fill_pathNtB6_10RegionCore30fill_path_with_outline_generic11mark_framed
                          ((longlong)&local_78,uVar19,param_1,(longlong)local_110,uVar14);
              } while ((char)uVar12 != '\0');
            }
            plVar27 = *(longlong **)(local_78 + 0x10);
            if (plVar27 <= local_70) goto LAB_1400046b9;
            lVar4 = *(longlong *)(local_78 + 8);
            uVar28 = (ulonglong)*(int *)(lVar4 + (longlong)local_70 * 4);
            if (uVar28 <= uVar19) goto LAB_140004537;
            plVar11 = (longlong *)((longlong)local_70 + uVar19 + 3);
            if (plVar27 <= plVar11) goto LAB_1400046d1;
            if (plVar27 <= (longlong *)((longlong)local_70 + 2U)) {
                    /* WARNING: Subroutine does not return */
              _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
            }
            uVar19 = lVar18 + uVar19;
            if (uVar28 <= uVar19) goto LAB_140004537;
            plVar24 = (longlong *)((longlong)local_70 + uVar19 + 3);
            if (plVar27 <= plVar24) {
LAB_140004647:
                    /* WARNING: Subroutine does not return */
              _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
            }
            local_60 = *(int *)(lVar4 + (longlong)plVar11 * 4);
            local_5c = *(undefined4 *)(lVar4 + 8 + (longlong)local_70 * 4);
            local_58 = CONCAT44(local_5c,*(undefined4 *)(lVar4 + (longlong)plVar24 * 4));
            iVar8 = EPATHOBJ_bPolyLineTo(lVar2,lVar3,&local_60,2);
            uVar28 = local_78;
            if (iVar8 == 0) goto joined_r0x000140004617;
            if (local_70 == (longlong *)0x0) goto LAB_140004250;
            if (*(ulonglong *)(local_78 + 0x10) <= (longlong)local_70 - 1U) {
LAB_1400046c5:
              local_78 = uVar28;
                    /* WARNING: Subroutine does not return */
              _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
            }
            lVar18 = (longlong)*(int *)(*(longlong *)(local_78 + 8) + -4 + (longlong)local_70 * 4);
            if (lVar18 < 0) {
LAB_14000461b:
              local_78 = uVar28;
              _RNvNtCsloaxXL3qbEI_4core6result13unwrap_failed();
              goto LAB_140004647;
            }
            if (local_70 < (longlong *)(lVar18 + 4U)) {
LAB_140004250:
              _RNvNvMNtCscIyU0BP6seX_7rgncore9fill_pathNtB6_10RegionCore30fill_path_with_outline_generic11mark_framed
                        ((longlong)&local_78,uVar19,param_1,(longlong)local_110,uVar14);
              local_d8 = -1;
            }
            else {
              plVar27 = (longlong *)((longlong)local_70 + (-4 - lVar18));
              uVar12 = _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalRINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E13is_valid_scanCsdyToaWEq7tk_8gdi_rust_llvm_12588874305795175024
                                 (local_78,(ulonglong)plVar27);
              if ((char)uVar12 == '\0') goto LAB_140004250;
              _RNvNvMNtCscIyU0BP6seX_7rgncore9fill_pathNtB6_10RegionCore30fill_path_with_outline_generic11mark_framed
                        ((longlong)&local_78,uVar19,param_1,(longlong)local_110,uVar14);
              plVar11 = *(longlong **)(uVar28 + 0x10);
              if (plVar11 <= plVar27) {
LAB_140004734:
                    /* WARNING: Subroutine does not return */
                _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
              }
              while( true ) {
                lVar18 = *(longlong *)(uVar28 + 8);
                uVar22 = (ulonglong)*(int *)(lVar18 + (longlong)plVar27 * 4);
                local_d8 = -1;
                if (uVar22 == 0) break;
                plVar24 = *(longlong **)(local_78 + 0x10);
                if (plVar24 <= local_70) {
                    /* WARNING: Subroutine does not return */
                  _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
                }
                lVar4 = *(longlong *)(local_78 + 8);
                uVar17 = (ulonglong)*(int *)(lVar4 + (longlong)local_70 * 4);
                if (uVar17 <= uVar19) goto LAB_140004537;
                plVar25 = (longlong *)((longlong)local_70 + uVar19 + 3);
                if (plVar24 <= plVar25) {
                    /* WARNING: Subroutine does not return */
                  _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
                }
                uVar16 = uVar22 + uVar13;
                if (!CARRY8(uVar22,uVar13)) goto LAB_140004537;
                plVar23 = (longlong *)(uVar16 + 3 + (longlong)plVar27);
                if (plVar11 <= plVar23) goto LAB_140004647;
                iVar8 = *(int *)(lVar4 + (longlong)plVar25 * 4);
                if (*(int *)(lVar18 + (longlong)plVar23 * 4) < iVar8) {
                  uVar20 = uVar16;
                }
                else {
                  if (uVar22 <= uVar30) goto LAB_140004537;
                  plVar25 = (longlong *)(uVar30 + 3 + (longlong)plVar27);
                  if (plVar11 <= plVar25) goto LAB_140004647;
                  if (iVar8 <= *(int *)(lVar18 + (longlong)plVar25 * 4)) break;
                  uVar26 = uVar22 - 1 >> 1;
                  uVar20 = uVar30;
                  if (uVar26 != uVar30) {
                    uVar21 = uVar30;
                    do {
                      while( true ) {
                        uVar20 = uVar26;
                        if (uVar22 <= uVar20) goto LAB_140004537;
                        plVar25 = (longlong *)((longlong)plVar27 + uVar20 + 3);
                        if (plVar11 <= plVar25) goto LAB_140004647;
                        if (iVar8 <= *(int *)(lVar18 + (longlong)plVar25 * 4)) break;
                        uVar26 = uVar20 + uVar16 >> 1;
                        uVar21 = uVar20;
                        if (uVar26 == uVar20) goto LAB_140004030;
                      }
                      uVar26 = uVar21 + uVar20 >> 1;
                      uVar16 = uVar20;
                      uVar20 = uVar21;
                    } while (uVar26 != uVar21);
                  }
                }
LAB_140004030:
                if (((uint)uVar20 & 1) == uVar29) {
                  uVar16 = uVar20 + 1;
                  if (uVar19 < uVar17 - 1) {
                    if (uVar22 <= uVar16) goto LAB_140004537;
                    plVar25 = (longlong *)((longlong)plVar27 + uVar20 + 4);
                    if (plVar11 <= plVar25) goto LAB_140004647;
                    if (uVar17 <= uVar19 + 1) goto LAB_140004537;
                    plVar23 = (longlong *)((longlong)local_70 + uVar19 + 4);
                    if (plVar24 <= plVar23) goto LAB_140004782;
                    if (*(int *)(lVar4 + (longlong)plVar23 * 4) <
                        *(int *)(lVar18 + (longlong)plVar25 * 4)) {
                      local_d8 = 1;
                      break;
                    }
                  }
                }
                else {
                  if (uVar22 <= uVar20) goto LAB_140004537;
                  plVar25 = (longlong *)((longlong)plVar27 + uVar20 + 3);
                  if (plVar11 <= plVar25) goto LAB_140004647;
                  if (uVar17 <= uVar19 - 1) goto LAB_140004537;
                  plVar23 = (longlong *)((longlong)local_70 + uVar19 + 2);
                  if (plVar24 <= plVar23) {
LAB_140004782:
                    /* WARNING: Subroutine does not return */
                    _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
                  }
                  uVar16 = uVar20;
                  if (*(int *)(lVar18 + (longlong)plVar25 * 4) <=
                      *(int *)(lVar4 + (longlong)plVar23 * 4)) break;
                }
                uVar19 = uVar16;
                if (uVar22 <= uVar19) goto LAB_140004537;
                plVar25 = (longlong *)((longlong)plVar27 + uVar19 + 3);
                if (plVar11 <= plVar25) {
                    /* WARNING: Subroutine does not return */
                  _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
                }
                iVar1 = *(int *)(lVar18 + (longlong)plVar25 * 4);
                if (iVar8 != iVar1) {
                  if (plVar24 <= (longlong *)((longlong)local_70 + 1U)) goto LAB_140004773;
                  local_5c = *(undefined4 *)(lVar4 + 4 + (longlong)local_70 * 4);
                  local_58 = CONCAT44(local_5c,iVar1);
                  local_60 = iVar8;
                  iVar8 = EPATHOBJ_bPolyLineTo(lVar2,lVar3,&local_60,2);
                  if (iVar8 == 0) goto joined_r0x000140004617;
                }
                local_78 = uVar28;
                local_70 = plVar27;
                if (plVar27 == (longlong *)0x0) goto LAB_140004250;
                if (*(ulonglong *)(uVar28 + 0x10) <= (longlong)plVar27 - 1U) goto LAB_1400046c5;
                lVar18 = (longlong)*(int *)(*(longlong *)(uVar28 + 8) + -4 + (longlong)plVar27 * 4);
                if (lVar18 < 0) goto LAB_14000461b;
                if (plVar27 < (longlong *)(lVar18 + 4U)) goto LAB_140004250;
                plVar27 = (longlong *)((longlong)plVar27 + (-4 - lVar18));
                uVar12 = _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalRINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E13is_valid_scanCsdyToaWEq7tk_8gdi_rust_llvm_12588874305795175024
                                   (uVar28,(ulonglong)plVar27);
                if ((char)uVar12 == '\0') goto LAB_140004250;
                _RNvNvMNtCscIyU0BP6seX_7rgncore9fill_pathNtB6_10RegionCore30fill_path_with_outline_generic11mark_framed
                          ((longlong)&local_78,uVar19,param_1,(longlong)local_110,uVar14);
                plVar11 = *(longlong **)(uVar28 + 0x10);
                if (plVar11 <= plVar27) goto LAB_140004734;
              }
            }
            uVar28 = local_78;
            plVar27 = *(longlong **)(local_78 + 0x10);
            if (*(longlong **)(local_88 + 0x10) == plVar27) {
              iVar8 = memcmp(*(void **)(local_88 + 8),*(void **)(local_78 + 8),
                             (longlong)*(longlong **)(local_88 + 0x10) << 2);
              bVar31 = iVar8 == 0;
            }
            else {
              bVar31 = false;
            }
            if (((uVar15 != uVar19 - 1) || (!bVar31)) || (local_80 != local_70)) {
              if (plVar27 <= local_70) {
                    /* WARNING: Subroutine does not return */
                _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
              }
              lVar18 = *(longlong *)(uVar28 + 8);
              uVar28 = (ulonglong)*(int *)(lVar18 + (longlong)local_70 * 4);
              if (uVar28 <= uVar19) goto LAB_140004537;
              plVar11 = (longlong *)((longlong)local_70 + uVar19 + 3);
              if (plVar27 <= plVar11) {
                    /* WARNING: Subroutine does not return */
                _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
              }
              if (plVar27 <= (longlong *)((longlong)local_70 + 1U)) goto LAB_1400046ef;
              uVar19 = local_d8 + uVar19;
              if (uVar28 <= uVar19) goto LAB_140004537;
              plVar24 = (longlong *)((longlong)local_70 + uVar19 + 3);
              if (plVar27 <= plVar24) {
                    /* WARNING: Subroutine does not return */
                _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
              }
              local_60 = *(int *)(lVar18 + (longlong)plVar11 * 4);
              local_5c = *(undefined4 *)(lVar18 + 4 + (longlong)local_70 * 4);
              local_58 = CONCAT44(local_5c,*(undefined4 *)(lVar18 + (longlong)plVar24 * 4));
              iVar8 = EPATHOBJ_bPolyLineTo(lVar2,lVar3,&local_60,2);
              uVar28 = local_78;
              if (iVar8 == 0) goto joined_r0x000140004617;
              if (*(longlong **)(local_78 + 0x10) <= local_70) goto LAB_1400046b9;
              plVar27 = (longlong *)
                        ((longlong)local_70 +
                        (longlong)*(int *)(*(longlong *)(local_78 + 8) + (longlong)local_70 * 4) + 4
                        );
              uVar12 = _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalRINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E13is_valid_scanCsdyToaWEq7tk_8gdi_rust_llvm_12588874305795175024
                                 (local_78,(ulonglong)plVar27);
              _RNvNvMNtCscIyU0BP6seX_7rgncore9fill_pathNtB6_10RegionCore30fill_path_with_outline_generic11mark_framed
                        ((longlong)&local_78,uVar19,param_1,(longlong)local_110,uVar14);
              if ((char)uVar12 == '\0') {
                uVar28 = 0;
              }
              goto joined_r0x000140003a8d;
            }
            if (plVar27 <= local_80) {
                    /* WARNING: Subroutine does not return */
              _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
            }
            lVar18 = *(longlong *)(uVar28 + 8);
            if ((ulonglong)(longlong)*(int *)(lVar18 + (longlong)local_80 * 4) <= uVar19)
            goto LAB_140004537;
            plVar11 = (longlong *)((longlong)local_80 + uVar19 + 3);
            if (plVar27 <= plVar11) {
                    /* WARNING: Subroutine does not return */
              _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
            }
            if (plVar27 <= (longlong *)((longlong)local_80 + 1U)) {
LAB_1400046ef:
                    /* WARNING: Subroutine does not return */
              _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
            }
            local_60 = *(int *)(lVar18 + (longlong)plVar11 * 4);
            local_5c = *(undefined4 *)(lVar18 + 4 + (longlong)local_80 * 4);
            iVar8 = EPATHOBJ_bPolyLineTo(lVar2,lVar3,&local_60,1);
            if (iVar8 == 0) goto joined_r0x000140004617;
            lVar18 = *(longlong *)(lVar2 + 8);
            if (lVar18 == 0) {
              local_104 = 0x57;
              goto joined_r0x000140004617;
            }
            *(byte *)(lVar18 + 0x48) = *(byte *)(lVar18 + 0x48) | 1;
            lVar18 = *(longlong *)(lVar18 + 0x28);
            if ((lVar18 != 0) && ((*(uint *)(lVar18 + 0x10) & 8) == 0)) {
              *(uint *)(lVar18 + 0x10) = *(uint *)(lVar18 + 0x10) | 8;
              *(int *)(lVar2 + 4) = *(int *)(lVar2 + 4) + 1;
            }
          }
          uVar28 = uVar10 + (uVar10 < uVar9);
          uVar15 = uVar10;
        } while (uVar10 < uVar9);
      }
      uVar9 = local_88;
      local_88 = uVar9;
      if (*(longlong **)(local_88 + 0x10) <= local_80) break;
      plVar27 = (longlong *)
                ((longlong)local_80 +
                (longlong)*(int *)(*(longlong *)(local_88 + 8) + (longlong)local_80 * 4) + 4);
      uVar12 = _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalRINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E13is_valid_scanCsdyToaWEq7tk_8gdi_rust_llvm_12588874305795175024
                         (local_88,(ulonglong)plVar27);
      if ((char)uVar12 == '\0') {
        local_104 = 0;
joined_r0x000140004617:
        if (local_100 != 0) {
          _RNvCs8cVqplN8eB1_7___rustc14___rust_dealloc();
        }
        goto LAB_1400045da;
      }
      local_88 = uVar9;
      local_80 = plVar27;
    } while (plVar27 < *(longlong **)(uVar9 + 0x10));
  }
                    /* WARNING: Subroutine does not return */
  _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
}



===== _RINvNvNtCs4xf65G0cUDK_10seh_unwind14implementation12catch_unwind7do_callNCINvMs_NtCsdyToaWEq7tk_8gdi_rust5umptrINtB1g_5umptrNtNtCs2JCLxFJL4Mh_15onecore_windows6windef7__POINTLE9enumerateNtNtB22_7winddip9__POINTFIXE0uEB1i_.llvm.7047519757781241447 @ 1400047c0 =====

void _RINvNvNtCs4xf65G0cUDK_10seh_unwind14implementation12catch_unwind7do_callNCINvMs_NtCsdyToaWEq7tk_8gdi_rust5umptrINtB1g_5umptrNtNtCs2JCLxFJL4Mh_15onecore_windows6windef7__POINTLE9enumerateNtNtB22_7winddip9__POINTFIXE0uEB1i__llvm_7047519757781241447
               (longlong *param_1)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong *puVar3;
  ulonglong uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  lVar1 = *param_1;
  uVar2 = param_1[1];
  puVar3 = (ulonglong *)param_1[2];
  uVar6 = *(undefined4 *)(*(longlong *)param_1[5] * 8 + *(longlong *)param_1[4] + 4 + *puVar3 * 8);
  uVar5 = __llvm_retpoline_r11();
  uVar4 = *puVar3;
  if (uVar2 <= uVar4) {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
  }
  *(undefined4 *)(lVar1 + uVar4 * 8) = uVar5;
  *(undefined4 *)(lVar1 + 4 + uVar4 * 8) = uVar6;
  return;
}



===== _RINvNvNtCs4xf65G0cUDK_10seh_unwind14implementation12catch_unwind7do_callNCNvMs_NtNtCsdyToaWEq7tk_8gdi_rust5xform12xformobj_cxxNtNtB1h_10xformobj_h10EXFORMOBJR32bXformRound_umptr_pointl_pointfxs_0uEB1j_.llvm.7047519757781241447 @ 140004830 =====

void _RINvNvNtCs4xf65G0cUDK_10seh_unwind14implementation12catch_unwind7do_callNCNvMs_NtNtCsdyToaWEq7tk_8gdi_rust5xform12xformobj_cxxNtNtB1h_10xformobj_h10EXFORMOBJR32bXformRound_umptr_pointl_pointfxs_0uEB1j__llvm_7047519757781241447
               (undefined8 *param_1)

{
  longlong lVar1;
  char *pcVar2;
  undefined8 uVar3;
  
  if (*(float **)param_1[1] == (float *)0x0) {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core6option13unwrap_failed();
  }
  lVar1 = *(longlong *)param_1[2];
  if (lVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core6option13unwrap_failed();
  }
  pcVar2 = (char *)*param_1;
  uVar3 = _RNvNtNtCsdyToaWEq7tk_8gdi_rust5xform7xformer7bCvtPts
                    (*(float **)param_1[1],lVar1,((longlong *)param_1[2])[1],param_1[3],param_1[4]);
  *pcVar2 = (char)uVar3;
  if ((char)uVar3 == '\0') {
    EngSetLastError(0x216);
    return;
  }
  return;
}



===== GdiHandleManager_Create @ 1400048b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 GdiHandleManager_Create(uint param_1,undefined8 param_2,uint param_3)

{
  code *pcVar1;
  undefined8 uVar2;
  undefined1 auStack_38 [32];
  byte local_18 [8];
  undefined8 local_10;
  ulonglong local_8;
  
                    /* 0x48b0  40  GdiHandleManager_Create */
  local_8 = __security_cookie ^ (ulonglong)auStack_38;
  _RNvMNtCsfOHk4HCp6w5_14handle_manager16GdiHandleManagerNtB2_16GdiHandleManager6Create
            ((undefined8 *)local_18,param_1,param_2,param_3);
  if ((local_18[0] & 1) != 0) {
    local_10 = 0;
  }
  if ((local_8 ^ (ulonglong)auStack_38) == __security_cookie) {
    return local_10;
  }
  pcVar1 = (code *)swi(3);
  uVar2 = (*pcVar1)();
  return uVar2;
}



===== GdiHandleManager_Destroy @ 140004920 =====

void GdiHandleManager_Destroy(longlong *param_1)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  
                    /* 0x4920  41  GdiHandleManager_Destroy */
  if (*(char *)((longlong)param_1 + 0x81e) != '\x02') {
    lVar2 = 0;
    do {
      plVar1 = (longlong *)param_1[lVar2 + 3];
      if (plVar1 != (longlong *)0x0) {
        if (((*(byte *)(plVar1 + 7) != 2) && ((*(byte *)(plVar1 + 7) & 1) != 0)) && (plVar1[6] != 0)
           ) {
          _RNvNtCsiNQa5DCRmUC_9gdi_alloc3ffi13Win32FreePool();
        }
        lVar4 = *plVar1;
        if (!SBORROW8(0,lVar4)) {
          lVar3 = plVar1[2];
          if (lVar3 != 0) {
            lVar4 = plVar1[1] + 8;
            do {
              if (*(longlong *)(lVar4 + -8) != 0) {
                _RNvNtCsiNQa5DCRmUC_9gdi_alloc3ffi13Win32FreePool();
              }
              lVar4 = lVar4 + 0x18;
              lVar3 = lVar3 + -1;
            } while (lVar3 != 0);
            lVar4 = *plVar1;
          }
          if (lVar4 != 0) {
            _RNvNtCsiNQa5DCRmUC_9gdi_alloc3ffi13Win32FreePool();
          }
        }
        _RNvNtCsiNQa5DCRmUC_9gdi_alloc3ffi13Win32FreePool();
      }
      lVar2 = lVar2 + 1;
    } while (lVar2 != 0x100);
  }
  if (*param_1 != 0) {
    _RNvNtCsiNQa5DCRmUC_9gdi_alloc3ffi13Win32FreePool();
  }
  _RNvNtCsiNQa5DCRmUC_9gdi_alloc3ffi13Win32FreePool();
  return;
}



===== RegionCore_set_to_rect @ 140004a00 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void RegionCore_set_to_rect(ulonglong *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  ulonglong uVar4;
  code *pcVar5;
  int iVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  longlong lVar9;
  undefined1 auStackY_98 [32];
  int aiStack_70 [2];
  ulonglong uStack_68;
  undefined8 uStack_58;
  undefined8 uStack_50;
  longlong lStack_48;
  ulonglong uStack_40;
  
                    /* 0x4a00  69  RegionCore_set_to_rect */
  uStack_40 = __security_cookie ^ (ulonglong)auStackY_98;
  iVar6 = *param_2;
  iVar1 = param_2[2];
  if (iVar6 == iVar1) {
LAB_14000a195:
    if ((uStack_40 ^ (ulonglong)auStackY_98) == __security_cookie) {
      _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore16set_to_null_scan(param_1);
      return;
    }
    pcVar5 = (code *)swi(3);
    (*pcVar5)();
    return;
  }
  iVar2 = param_2[1];
  iVar3 = param_2[3];
  if (iVar2 == iVar3) goto LAB_14000a195;
  uVar7 = *(undefined8 *)(param_2 + 2);
  *(undefined8 *)((longlong)param_1 + 0x1c) = *(undefined8 *)param_2;
  *(undefined8 *)((longlong)param_1 + 0x24) = uVar7;
  uVar8 = param_1[2];
  if (uVar8 == 0xe) {
    uVar7 = _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalQINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E13is_valid_scanB4__llvm_3083486868190693220
                      ((longlong)param_1,0);
    if ((char)uVar7 == '\0') {
                    /* WARNING: Subroutine does not return */
      _RNvNtCsloaxXL3qbEI_4core9panicking5panic();
    }
    if (param_1[2] < 3) {
                    /* WARNING: Subroutine does not return */
      _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
    }
    *(int *)(param_1[1] + 8) = iVar2;
    if (param_1[2] == 0) {
                    /* WARNING: Subroutine does not return */
      _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
    }
    lVar9 = (longlong)*(int *)param_1[1];
    uVar8 = lVar9 + 4;
    uVar7 = _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalQINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E13is_valid_scanB4__llvm_3083486868190693220
                      ((longlong)param_1,uVar8);
    if ((char)uVar7 == '\0') {
                    /* WARNING: Subroutine does not return */
      _RNvNtCsloaxXL3qbEI_4core6option13unwrap_failed();
    }
    if (param_1[2] <= lVar9 + 5U) {
LAB_14000a52d:
                    /* WARNING: Subroutine does not return */
      _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
    }
    *(int *)(param_1[1] + 0x14 + lVar9 * 4) = iVar2;
    if (param_1[2] <= lVar9 + 6U) {
                    /* WARNING: Subroutine does not return */
      _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
    }
    *(int *)(param_1[1] + 0x18 + lVar9 * 4) = iVar3;
    if (param_1[2] <= uVar8) {
LAB_14000a51e:
                    /* WARNING: Subroutine does not return */
      _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
    }
    if (*(int *)(param_1[1] + 0x10 + lVar9 * 4) == 0) {
LAB_14000a45e:
                    /* WARNING: Subroutine does not return */
      _RNvNtCsloaxXL3qbEI_4core9panicking5panic();
    }
    if (param_1[2] <= lVar9 + 7U) {
                    /* WARNING: Subroutine does not return */
      _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
    }
    *(int *)(param_1[1] + 0x1c + lVar9 * 4) = iVar6;
    if (param_1[2] <= uVar8) goto LAB_14000a51e;
    if (*(uint *)(param_1[1] + 0x10 + lVar9 * 4) < 2) goto LAB_14000a45e;
    if (param_1[2] <= lVar9 + 8U) {
                    /* WARNING: Subroutine does not return */
      _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
    }
    *(int *)(param_1[1] + 0x20 + lVar9 * 4) = iVar1;
    if (param_1[2] <= uVar8) goto LAB_14000a51e;
    uVar8 = lVar9 + 8U + (longlong)*(int *)(param_1[1] + 0x10 + lVar9 * 4);
    uVar7 = _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalQINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E13is_valid_scanB4__llvm_3083486868190693220
                      ((longlong)param_1,uVar8);
    if ((char)uVar7 != '\0') {
      if (uVar8 + 1 < param_1[2]) {
        *(int *)(param_1[1] + 4 + uVar8 * 4) = iVar3;
        return;
      }
      goto LAB_14000a52d;
    }
    goto LAB_14000a501;
  }
  uVar4 = *param_1;
  if ((uVar4 < 0xe) && (uVar4 - uVar8 < 0xe - uVar8)) {
    if (!CARRY8(uVar8,0xe - uVar8)) {
      uVar8 = 0xe;
      if (0xe < uVar4 * 2) {
        uVar8 = uVar4 * 2;
      }
      if (uVar4 == 0) {
        uStack_50 = 0;
      }
      else {
        uStack_58 = param_1[1];
        lStack_48 = uVar4 << 2;
        uStack_50 = 4;
      }
      _RINvNtCsip5f2bf5HGI_5alloc7raw_vec11finish_growINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EECscIyU0BP6seX_7rgncore_llvm_13477870103536380358
                ((ulonglong *)aiStack_70,&DAT_00000004,uVar8 * 4,&uStack_58);
      if (aiStack_70[0] != 1) {
        param_1[1] = uStack_68;
        *param_1 = uVar8;
        goto LAB_14000a328;
      }
    }
    uStack_58 = CONCAT44(uStack_58._4_4_,0xe);
  }
  else {
LAB_14000a328:
    param_1[2] = 0;
    *(undefined4 *)(param_1 + 3) = 0;
    uVar7 = _RNvMs5_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE11append_scan
                      (param_1,0x80000000,iVar2,(undefined4 *)&DAT_00000004,0);
    if ((int)uVar7 == 0) {
      uStack_58 = CONCAT44(iVar1,iVar6);
      uVar7 = _RNvMs5_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE11append_scan
                        (param_1,iVar2,iVar3,(undefined4 *)&uStack_58,2);
      if ((int)uVar7 == 0) {
        uVar7 = _RNvMs5_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE11append_scan
                          (param_1,iVar3,0x7fffffff,(undefined4 *)&DAT_00000004,0);
        iVar6 = (int)uVar7;
        if (iVar6 == 0) {
          if (param_1[2] == 0) {
            _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore16set_to_null_scan(param_1);
          }
          return;
        }
      }
      else {
        aiStack_70[0] = (int)uVar7;
        iVar6 = _RNvNtCsloaxXL3qbEI_4core6result13unwrap_failed();
      }
      uStack_58 = CONCAT44(uStack_58._4_4_,iVar6);
    }
    else {
      uStack_58 = CONCAT44(uStack_58._4_4_,(int)uVar7);
    }
  }
  _RNvNtCsloaxXL3qbEI_4core6result13unwrap_failed();
LAB_14000a501:
                    /* WARNING: Subroutine does not return */
  _RNvNtCsloaxXL3qbEI_4core6option13unwrap_failed();
}



===== RegionCore_iComplexity @ 140004a10 =====

int RegionCore_iComplexity(longlong param_1)

{
  int iVar1;
  
                    /* 0x4a10  61  RegionCore_iComplexity */
  iVar1 = 1;
  if (*(int *)(param_1 + 0x18) != 1) {
    iVar1 = 3 - (uint)(*(ulonglong *)(param_1 + 0x10) < 0xf);
  }
  return iVar1;
}



===== RegionCore_bMerge @ 140004a30 =====

bool RegionCore_bMerge(ulonglong *param_1,longlong param_2,longlong param_3,byte param_4)

{
  ulonglong uVar1;
  
                    /* 0x4a30  49  RegionCore_bMerge */
  uVar1 = _RNvMs_NtCscIyU0BP6seX_7rgncore5mergeNtB6_10RegionCore5merge
                    (param_1,param_2,param_3,param_4);
  return (int)uVar1 == 0;
}



===== RegionCore_vCopy @ 140004a50 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void RegionCore_vCopy(ulonglong *param_1,ulonglong *param_2)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  ulonglong uVar4;
  code *pcVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  ulonglong uVar9;
  char *pcVar10;
  ulonglong uVar11;
  undefined4 *puVar12;
  ulonglong *puVar13;
  ulonglong uVar14;
  ulonglong uVar15;
  longlong lVar16;
  undefined1 auStack_88 [32];
  undefined **ppuStack_68;
  int aiStack_58 [2];
  ulonglong uStack_50;
  ulonglong *puStack_48;
  ulonglong uStack_40;
  ulonglong *puStack_38;
  longlong lStack_30;
  ulonglong uStack_28;
  
                    /* 0x4a50  76  RegionCore_vCopy */
  uStack_28 = __security_cookie ^ (ulonglong)auStack_88;
  if (param_1 == param_2) goto LAB_14000b547;
  *(int *)(param_1 + 3) = (int)param_2[3];
  uVar6 = *(undefined8 *)((longlong)param_2 + 0x24);
  *(undefined8 *)((longlong)param_1 + 0x1c) = *(undefined8 *)((longlong)param_2 + 0x1c);
  *(undefined8 *)((longlong)param_1 + 0x24) = uVar6;
  param_1[2] = 0;
  puVar3 = (undefined4 *)param_2[1];
  uVar4 = param_2[2];
  uVar9 = *param_1;
  if (uVar9 < uVar4) {
    uVar14 = uVar9 * 2;
    if (uVar9 * 2 < uVar4) {
      uVar14 = uVar4;
    }
    uVar11 = 4;
    if (4 < uVar14) {
      uVar11 = uVar14;
    }
    puVar13 = (ulonglong *)(uVar11 * 4);
    if (puVar13 < (ulonglong *)0x7ffffffffffffffd && uVar14 >> 0x3e == 0) goto LAB_14000b62d;
    uStack_40 = 0;
    while( true ) {
      ppuStack_68 = &PTR_s_rgncore_src_lib_rs_140019628;
      pcVar10 = s_called__Result__unwrap____on_an___14001abf3;
      puVar13 = &uStack_40;
      puStack_38 = param_1;
      uVar9 = _RNvNtCsloaxXL3qbEI_4core6result13unwrap_failed();
      param_1 = (ulonglong *)pcVar10;
LAB_14000b62d:
      if (uVar9 == 0) {
        puStack_38 = (ulonglong *)0x0;
      }
      else {
        uStack_40 = param_1[1];
        lStack_30 = uVar9 << 2;
        puStack_38 = (ulonglong *)0x4;
      }
      ppuStack_68 = (undefined **)(param_1 + 2);
      _RINvNtCsip5f2bf5HGI_5alloc7raw_vec11finish_growINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EECscIyU0BP6seX_7rgncore_llvm_13477870103536380358
                ((ulonglong *)aiStack_58,&DAT_00000004,(ulonglong)puVar13,&uStack_40);
      if (aiStack_58[0] != 1) break;
      uStack_40 = uStack_50;
      param_1 = puStack_48;
    }
    param_1[1] = uStack_50;
    *param_1 = uVar11;
    uVar9 = param_1[2];
LAB_14000b502:
    uVar14 = uVar4 - 1 & 0x3fffffffffffffff;
    if ((uVar14 < 0xb) || ((uStack_50 + uVar9 * 4) - (longlong)puVar3 < 0x20)) {
      puVar12 = puVar3;
    }
    else {
      uVar14 = uVar14 + 1;
      lVar16 = uVar9 * 4;
      uVar15 = uVar14 & 0xfffffffffffffff8;
      puVar12 = puVar3 + uVar15;
      uVar9 = uVar9 + uVar15;
      lVar16 = lVar16 + uStack_50;
      uVar11 = 0;
      do {
        uVar6 = *(undefined8 *)((longlong)(puVar3 + uVar11) + 8);
        uVar7 = *(undefined8 *)(puVar3 + uVar11 + 4);
        uVar8 = *(undefined8 *)((longlong)(puVar3 + uVar11 + 4) + 8);
        puVar1 = (undefined8 *)(lVar16 + uVar11 * 4);
        *puVar1 = *(undefined8 *)(puVar3 + uVar11);
        puVar1[1] = uVar6;
        puVar1 = (undefined8 *)(lVar16 + 0x10 + uVar11 * 4);
        *puVar1 = uVar7;
        puVar1[1] = uVar8;
        uVar11 = uVar11 + 8;
      } while (uVar15 != uVar11);
      if (uVar14 == uVar15) goto LAB_14000b543;
    }
    do {
      uVar2 = *puVar12;
      puVar12 = puVar12 + 1;
      *(undefined4 *)(uStack_50 + uVar9 * 4) = uVar2;
      uVar9 = uVar9 + 1;
    } while (puVar12 != puVar3 + uVar4);
  }
  else {
    uVar9 = 0;
    if (uVar4 != 0) {
      uStack_50 = param_1[1];
      goto LAB_14000b502;
    }
  }
LAB_14000b543:
  param_1[2] = uVar9;
LAB_14000b547:
  if ((uStack_28 ^ (ulonglong)auStack_88) == __security_cookie) {
    return;
  }
  pcVar5 = (code *)swi(3);
  (*pcVar5)();
  return;
}



===== RegionCore_bCopy @ 140004a60 =====

bool RegionCore_bCopy(ulonglong *param_1,ulonglong *param_2)

{
  undefined8 uVar1;
  
                    /* 0x4a60  44  RegionCore_bCopy */
  uVar1 = _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore17set_to_scans_from(param_1,param_2);
  return (int)uVar1 == 0;
}



===== RegionCore_bExpand @ 140004a80 =====

bool RegionCore_bExpand(ulonglong *param_1,uint param_2)

{
  undefined8 uVar1;
  
                    /* 0x4a80  46  RegionCore_bExpand */
  uVar1 = _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore21try_reserve_scan_data
                    (param_1,(ulonglong)(param_2 >> 2));
  return (int)uVar1 == 0;
}



===== RegionCore_bInside_rcl @ 140004aa0 =====

int RegionCore_bInside_rcl(longlong param_1,int *param_2)

{
  undefined8 uVar1;
  
                    /* 0x4aa0  48  RegionCore_bInside_rcl */
  uVar1 = _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore10intersects(param_1,param_2);
  return ((uint)uVar1 & 0xff) + 1;
}



===== RegionCore_bInside_point @ 140004ac0 =====

int RegionCore_bInside_point(longlong param_1,int *param_2)

{
  ulonglong uVar1;
  
                    /* 0x4ac0  47  RegionCore_bInside_point */
  uVar1 = _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore14contains_point(param_1,param_2);
  return ((uint)uVar1 & 0xff) + 1;
}



===== RegionCore_bEqual @ 140004ae0 =====

ulonglong RegionCore_bEqual(longlong param_1,longlong param_2)

{
  ulonglong uVar1;
  
                    /* 0x4ae0  45  RegionCore_bEqual */
  uVar1 = _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore15scans_are_equal(param_1,param_2);
  return uVar1 & 0xff;
}



===== RegionCore_new_with_scan_capacity @ 140004b00 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong RegionCore_new_with_scan_capacity(undefined4 *param_1,uint param_2)

{
  code *pcVar1;
  ulonglong uVar2;
  bool bVar3;
  undefined1 auStack_68 [40];
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  undefined8 uStack_18;
  ulonglong local_10;
  
                    /* 0x4b00  64  RegionCore_new_with_scan_capacity */
  local_10 = __security_cookie ^ (ulonglong)auStack_68;
  _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore22new_with_scan_capacity
            ((undefined8 *)&local_40,(ulonglong)(param_2 >> 2));
  bVar3 = SBORROW8(0,CONCAT44(uStack_3c,local_40));
  if (!bVar3) {
    *(undefined8 *)(param_1 + 8) = local_20;
    *(undefined8 *)(param_1 + 10) = uStack_18;
    *(undefined8 *)(param_1 + 4) = local_30;
    *(undefined8 *)(param_1 + 6) = uStack_28;
    *param_1 = local_40;
    param_1[1] = uStack_3c;
    param_1[2] = uStack_38;
    param_1[3] = uStack_34;
  }
  if ((local_10 ^ (ulonglong)auStack_68) == __security_cookie) {
    return (ulonglong)!bVar3;
  }
  pcVar1 = (code *)swi(3);
  uVar2 = (*pcVar1)();
  return uVar2;
}



===== RegionCore_drop @ 140004b70 =====

void RegionCore_drop(longlong *param_1)

{
                    /* 0x4b70  52  RegionCore_drop */
  if (*param_1 == 0) {
    return;
  }
  if (*param_1 == 0x1c) {
    _RNvNtCsjsHfHFRyfyy_10gdi_region3ffi22ScanLookAsideList_Free();
    return;
  }
  Win32FreePool(param_1[1]);
  return;
}



===== RegionCore_set_to_null_scan @ 140004ba0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void RegionCore_set_to_null_scan(ulonglong *param_1)

{
  code *pcVar1;
  ulonglong uVar2;
  char *pcVar3;
  ulonglong uVar4;
  ulonglong *puVar5;
  undefined1 auStack_78 [32];
  undefined **ppuStack_58;
  int aiStack_48 [2];
  ulonglong uStack_40;
  ulonglong *puStack_38;
  ulonglong uStack_30;
  ulonglong *puStack_28;
  longlong lStack_20;
  ulonglong uStack_18;
  
                    /* 0x4ba0  68  RegionCore_set_to_null_scan */
  uStack_18 = __security_cookie ^ (ulonglong)auStack_78;
  *(undefined8 *)((longlong)param_1 + 0x1c) = 0;
  *(undefined8 *)((longlong)param_1 + 0x24) = 0;
  uVar2 = param_1[2];
  if (uVar2 < 5) {
    if (uVar2 == 4) goto LAB_140009d92;
    uVar4 = *param_1;
    if (uVar4 - uVar2 < 4 - uVar2) {
      uVar2 = 4;
      if (4 < uVar4 * 2) {
        uVar2 = uVar4 * 2;
      }
      puVar5 = (ulonglong *)(uVar2 * 4);
      if (puVar5 < (ulonglong *)0x7ffffffffffffffd && uVar4 < 0x2000000000000000)
      goto LAB_140009e7e;
      uStack_30 = 0;
      while( true ) {
        ppuStack_58 = &PTR_s_rgncore_src_lib_rs_140019520;
        pcVar3 = s_called__Result__unwrap____on_an___14001abf3;
        puVar5 = &uStack_30;
        uVar4 = 0x2b;
        puStack_28 = param_1;
        _RNvNtCsloaxXL3qbEI_4core6result13unwrap_failed();
        param_1 = (ulonglong *)pcVar3;
LAB_140009e7e:
        if (uVar4 == 0) {
          puStack_28 = (ulonglong *)0x0;
        }
        else {
          uStack_30 = param_1[1];
          lStack_20 = uVar4 << 2;
          puStack_28 = (ulonglong *)0x4;
        }
        ppuStack_58 = (undefined **)(param_1 + 2);
        _RINvNtCsip5f2bf5HGI_5alloc7raw_vec11finish_growINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EECscIyU0BP6seX_7rgncore_llvm_13477870103536380358
                  ((ulonglong *)aiStack_48,&DAT_00000004,(ulonglong)puVar5,&uStack_30);
        if (aiStack_48[0] != 1) break;
        uStack_30 = uStack_40;
        param_1 = puStack_38;
      }
      param_1[1] = uStack_40;
      *param_1 = uVar2;
      uVar2 = param_1[2];
    }
    else {
      uStack_40 = param_1[1];
    }
    _weak_memset_default___llvm_retpoline_r11((void *)(uStack_40 + uVar2 * 4),0,uVar2 * -4 + 0x10);
  }
  param_1[2] = 4;
LAB_140009d92:
  *(undefined4 *)param_1[1] = 0;
  if (param_1[2] < 2) {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
  }
  *(undefined4 *)(param_1[1] + 4) = 0x80000000;
  if (param_1[2] < 3) {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
  }
  *(undefined4 *)(param_1[1] + 8) = 0x7fffffff;
  if (param_1[2] < 4) {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
  }
  *(undefined4 *)(param_1[1] + 0xc) = 0;
  *(undefined4 *)(param_1 + 3) = 1;
  if ((uStack_18 ^ (ulonglong)auStack_78) == __security_cookie) {
    return;
  }
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== RegionCore_bOffset @ 140004bb0 =====

undefined8 RegionCore_bOffset(longlong param_1,int *param_2)

{
  ulonglong uVar1;
  
                    /* 0x4bb0  50  RegionCore_bOffset */
  uVar1 = _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore9offset_by(param_1,*param_2,param_2[1]);
  if ((int)uVar1 == 0) {
    return 1;
  }
  EngSetLastError(uVar1 & 0xffffffff);
  return 0;
}



===== RegionCore_set_from_path @ 140004bf0 =====

bool RegionCore_set_from_path(ulonglong *param_1,longlong param_2,uint param_3,longlong param_4)

{
  ulonglong uVar1;
  
                    /* 0x4bf0  66  RegionCore_set_from_path */
  if (*(longlong *)(param_2 + 8) == 0) {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core9panicking5panic();
  }
  uVar1 = _RNvNtNtCsdyToaWEq7tk_8gdi_rust6region9from_path20region_from_path_mut
                    (param_1,*(longlong *)(param_2 + 8) + 0x18,(char)((param_3 & 2) >> 1),param_4,1,
                     *(uint *)(param_2 + 4));
  return (int)uVar1 == 0;
}



===== RegionCore_bContain_rcl @ 140004c50 =====

bool RegionCore_bContain_rcl(longlong param_1,int *param_2)

{
  bool bVar1;
  
                    /* 0x4c50  42  RegionCore_bContain_rcl */
  bVar1 = false;
  if (((*(int *)(param_1 + 0x1c) <= *param_2) && (param_2[2] <= *(int *)(param_1 + 0x24))) &&
     (*(int *)(param_1 + 0x20) <= param_2[1])) {
    bVar1 = param_2[3] <= *(int *)(param_1 + 0x28);
  }
  return bVar1;
}



===== RegionCore_bContain_region @ 140004c90 =====

bool RegionCore_bContain_region(longlong param_1,longlong param_2)

{
  bool bVar1;
  
                    /* 0x4c90  43  RegionCore_bContain_region */
  bVar1 = false;
  if (((*(int *)(param_1 + 0x1c) <= *(int *)(param_2 + 0x1c)) &&
      (*(int *)(param_2 + 0x24) <= *(int *)(param_1 + 0x24))) &&
     (*(int *)(param_1 + 0x20) <= *(int *)(param_2 + 0x20))) {
    bVar1 = *(int *)(param_2 + 0x28) <= *(int *)(param_1 + 0x28);
  }
  return bVar1;
}



===== _RNvNtCsdyToaWEq7tk_8gdi_rust6region26try_repair_zero_sized_scan @ 140004cd0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong _RNvNtCsdyToaWEq7tk_8gdi_rust6region26try_repair_zero_sized_scan
                    (ulonglong *param_1,ulonglong *param_2)

{
  ulonglong uVar1;
  uint uVar2;
  int iVar3;
  code *pcVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  longlong lVar8;
  ulonglong uVar9;
  int iVar10;
  uint *puVar11;
  uint *_Dst;
  ulonglong uVar12;
  uint uVar13;
  bool bVar14;
  undefined1 auStackY_88 [32];
  ulonglong *local_58;
  ulonglong *local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_88;
  uVar7 = *param_1;
  _Dst = (uint *)param_1[1];
  _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore23clear_scans_and_reserve
            ((undefined4 *)&local_58,param_2,uVar7);
  if (((ulonglong)local_58 & 1) == 0) {
    local_58 = local_50;
    uVar6 = param_1[3];
    uVar13 = 0x80000000;
    puVar11 = _Dst;
    uVar12 = 0;
    do {
      if ((uint)uVar6 <= uVar12) {
        uVar7 = local_50[2];
        uVar6 = param_1[2];
        if (uVar7 < uVar6) {
          param_1[2] = uVar7;
        }
        else {
          if (!(uVar7 < uVar6 || uVar7 - uVar6 == 0)) {
            uVar6 = _RNvMs2_NtCsip5f2bf5HGI_5alloc7raw_vecINtB5_11RawVecInnerINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE11try_reserveCscIyU0BP6seX_7rgncore
                              (param_1,uVar6,uVar7 - uVar6,&DAT_00000004,4);
            uVar9 = 0xe;
            if (uVar6 != 0x8000000000000001) goto LAB_140004ecb;
            _weak_memset_default___llvm_retpoline_r11
                      ((void *)(param_1[2] * 4 + param_1[1]),0,(uVar7 - param_1[2]) * 4);
            param_1[2] = uVar7;
            _Dst = (uint *)param_1[1];
            uVar6 = uVar7;
            uVar7 = local_50[2];
          }
          if (uVar6 != uVar7) {
            _RNvNvMNtCsloaxXL3qbEI_4core5sliceSp15copy_from_slice17len_mismatch_fail
                      (uVar6,uVar7,&PTR_s_gdi_rust_src_region_rs_140019118);
            pcVar4 = (code *)swi(3);
            uVar7 = (*pcVar4)();
            return uVar7;
          }
        }
        _weak_memcpy_default___llvm_retpoline_r11(_Dst,(void *)local_50[1],uVar7 << 2);
        _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore20tighten_bounding_box((longlong)param_1);
        uVar9 = 0;
        goto LAB_140004ecb;
      }
      uVar9 = 0x57;
      if (uVar7 < 4) goto LAB_140004ecb;
      uVar2 = *puVar11;
      uVar5 = (ulonglong)uVar2;
      if ((int)uVar2 < 0) goto LAB_140004ecb;
      uVar1 = uVar5 + 4;
      bVar14 = uVar7 < uVar1;
      uVar7 = uVar7 - uVar1;
      if ((((bVar14) || ((uVar2 & 1) != 0)) || (uVar2 = puVar11[1], (int)uVar2 < (int)uVar13)) ||
         (uVar13 = puVar11[2], (int)uVar13 <= (int)uVar2)) goto LAB_140004ecb;
      lVar8 = 0;
      iVar10 = -0x80000000;
      while (uVar5 * 4 != lVar8) {
        iVar3 = *(int *)((longlong)(puVar11 + 3) + lVar8);
        lVar8 = lVar8 + 4;
        bVar14 = iVar3 < iVar10;
        iVar10 = iVar3;
        if (bVar14) goto LAB_140004ecb;
      }
      uVar9 = _RNvMs5_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE11append_scan
                        (local_50,uVar2,uVar13,puVar11 + 3,uVar5);
      puVar11 = puVar11 + uVar1;
      uVar12 = uVar12 + (uVar12 < (uint)uVar6);
    } while ((int)uVar9 == 0);
    uVar9 = uVar9 & 0xffffffff;
LAB_140004ecb:
    _RNvXCscIyU0BP6seX_7rgncoreNtB2_11RegionGuardNtNtNtCsloaxXL3qbEI_4core3ops4drop4Drop4drop
              (&local_58);
    if ((local_48 ^ (ulonglong)auStackY_88) != __security_cookie) goto LAB_140004eea;
  }
  else {
    uVar9 = (ulonglong)local_58 >> 0x20;
    if ((local_48 ^ (ulonglong)auStackY_88) != __security_cookie) {
LAB_140004eea:
      pcVar4 = (code *)swi(3);
      uVar7 = (*pcVar4)();
      return uVar7;
    }
  }
  return uVar9;
}



===== RegionCore_iCombine @ 140004f10 =====

ulonglong RegionCore_iCombine(ulonglong *param_1,ulonglong *param_2,ulonglong *param_3,int param_4)

{
  ulonglong uVar1;
  ulonglong uVar2;
  
                    /* 0x4f10  60  RegionCore_iCombine */
  if (param_2[2] == 0) {
    _RNvNtCsjsHfHFRyfyy_10gdi_region3ffi27RustOnZeroSizedScanCallback();
    uVar2 = _RNvNtCsdyToaWEq7tk_8gdi_rust6region26try_repair_zero_sized_scan(param_2,param_1);
    if ((int)uVar2 == 0) goto LAB_140004f2c;
LAB_140004f7a:
    uVar2 = 0;
  }
  else {
LAB_140004f2c:
    if (param_3[2] == 0) {
      _RNvNtCsjsHfHFRyfyy_10gdi_region3ffi27RustOnZeroSizedScanCallback();
      uVar2 = _RNvNtCsdyToaWEq7tk_8gdi_rust6region26try_repair_zero_sized_scan(param_3,param_1);
      if ((int)uVar2 != 0) goto LAB_140004f7a;
    }
    uVar1 = _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore7combine(param_1,param_2,param_3,param_4);
    uVar2 = 0;
    if ((uVar1 & 1) == 0) {
      uVar2 = (ulonglong)param_2 & 0xffffffff;
    }
  }
  return uVar2;
}



===== RegionCore_vScale @ 140004f90 =====

void RegionCore_vScale(longlong param_1,undefined8 param_2)

{
                    /* 0x4f90  78  RegionCore_vScale */
  _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore5scale
            (param_1,(float)param_2,(float)((ulonglong)param_2 >> 0x20));
  return;
}



===== RegionCore_vGetSubRect @ 140004fb0 =====

void RegionCore_vGetSubRect(longlong param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  
                    /* 0x4fb0  77  RegionCore_vGetSubRect */
  if (*(ulonglong *)(param_1 + 0x10) < 0xf) {
    uVar1 = *(undefined8 *)(param_1 + 0x24);
    *param_2 = *(undefined8 *)(param_1 + 0x1c);
    param_2[1] = uVar1;
    return;
  }
  *param_2 = 0;
  param_2[1] = 0;
  return;
}



===== RegionCore_is_rect @ 140004fd0 =====

bool RegionCore_is_rect(longlong param_1)

{
                    /* 0x4fd0  63  RegionCore_is_rect */
  return *(longlong *)(param_1 + 0x10) == 0xe;
}



===== RegionCore_tighten @ 140004ff0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void RegionCore_tighten(longlong param_1)

{
  ulonglong uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  code *pcVar4;
  int iVar5;
  undefined8 uVar6;
  longlong lVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  undefined1 auStack_68 [32];
  undefined **ppuStack_48;
  ulonglong uStack_38;
  
                    /* 0x4ff0  73  RegionCore_tighten */
  uStack_38 = __security_cookie ^ (ulonglong)auStack_68;
  if (*(int *)(param_1 + 0x18) == 1) {
    *(undefined8 *)(param_1 + 0x1c) = 0;
    *(undefined8 *)(param_1 + 0x24) = 0;
    return;
  }
  uVar6 = _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalQINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E13is_valid_scanB4__llvm_3083486868190693220
                    (param_1,0);
  if ((char)uVar6 == '\0') {
LAB_14000d2d1:
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core9panicking5panic();
  }
  uVar9 = *(ulonglong *)(param_1 + 0x10);
  if (uVar9 < 3) {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
  }
  lVar7 = (longlong)*(int *)(*(longlong *)(param_1 + 8) + -4 + uVar9 * 4);
  if (lVar7 < 0) {
    ppuStack_48 = &anon_67cd83108cc9ed848dbde57549fb323c_12_llvm_3083486868190693220;
    _RNvNtCsloaxXL3qbEI_4core6result13unwrap_failed();
LAB_14000d312:
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
  }
  if (lVar7 + 4U <= uVar9) {
    uVar2 = *(undefined4 *)(*(longlong *)(param_1 + 8) + 8);
    uVar8 = (uVar9 - lVar7) - 4;
    uVar6 = _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalQINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E13is_valid_scanB4__llvm_3083486868190693220
                      (param_1,uVar8);
    if ((char)uVar6 != '\0') {
      if (*(ulonglong *)(param_1 + 0x10) <= (uVar9 - lVar7) - 3) {
                    /* WARNING: Subroutine does not return */
        _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
      }
      uVar3 = *(undefined4 *)(*(longlong *)(param_1 + 8) + 4 + uVar8 * 4);
      uVar6 = _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalQINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E13is_valid_scanB4__llvm_3083486868190693220
                        (param_1,0);
      if ((char)uVar6 != '\0') {
        iVar13 = 0x7fffffff;
        iVar11 = -0x80000000;
        uVar9 = 0;
        do {
          uVar8 = *(ulonglong *)(param_1 + 0x10);
          if (uVar8 <= uVar9) goto LAB_14000d312;
          lVar7 = *(longlong *)(param_1 + 8);
          uVar10 = (ulonglong)*(int *)(lVar7 + uVar9 * 4);
          if (uVar10 != 0) {
            uVar1 = uVar9 + 3;
            if (uVar8 <= uVar1) {
                    /* WARNING: Subroutine does not return */
              _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
            }
            if (CARRY8(uVar1,uVar10)) {
              _RNvNtNtCsloaxXL3qbEI_4core5slice5index22slice_index_order_fail();
              break;
            }
            if (uVar8 < uVar1 + uVar10) {
              _RNvNtNtCsloaxXL3qbEI_4core5slice5index24slice_end_index_len_fail
                        (uVar1 + uVar10,uVar8,
                         &anon_67cd83108cc9ed848dbde57549fb323c_20_llvm_3083486868190693220);
              goto LAB_14000d284;
            }
            iVar12 = *(int *)(lVar7 + uVar1 * 4);
            if (iVar12 <= iVar13) {
              iVar13 = iVar12;
            }
            iVar12 = *(int *)(lVar7 + uVar1 * 4 + -4 + uVar10 * 4);
            if (iVar11 <= iVar12) {
              iVar11 = iVar12;
            }
          }
          uVar9 = uVar9 + uVar10 + 4;
          uVar6 = _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalQINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E13is_valid_scanB4__llvm_3083486868190693220
                            (param_1,uVar9);
          if ((char)uVar6 == '\0') {
LAB_14000d284:
            iVar12 = iVar11;
            if (iVar11 <= iVar13) {
              iVar12 = 0;
            }
            iVar5 = 0;
            if (iVar13 < iVar11) {
              iVar5 = iVar13;
            }
            *(int *)(param_1 + 0x1c) = iVar5;
            *(undefined4 *)(param_1 + 0x20) = uVar2;
            *(int *)(param_1 + 0x24) = iVar12;
            *(undefined4 *)(param_1 + 0x28) = uVar3;
            if ((uStack_38 ^ (ulonglong)auStack_68) == __security_cookie) {
              return;
            }
            pcVar4 = (code *)swi(3);
            (*pcVar4)();
            return;
          }
        } while( true );
      }
      goto LAB_14000d2d1;
    }
  }
                    /* WARNING: Subroutine does not return */
  _RNvNtCsloaxXL3qbEI_4core6option13unwrap_failed();
}



===== RegionCore_subtract @ 140005000 =====

bool RegionCore_subtract(ulonglong **param_1,uint *param_2,uint *param_3,ulonglong param_4)

{
  ulonglong uVar1;
  
                    /* 0x5000  72  RegionCore_subtract */
  uVar1 = _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore8subtract(param_1,param_2,param_3,param_4);
  return (int)uVar1 == 0;
}



===== RegionCore_get_sizeScan @ 140005020 =====

int RegionCore_get_sizeScan(longlong param_1)

{
                    /* 0x5020  58  RegionCore_get_sizeScan */
  return *(int *)(param_1 + 0x10) << 2;
}



===== RegionCore_get_sizeScanAlloc @ 140005030 =====

int RegionCore_get_sizeScanAlloc(int *param_1)

{
                    /* 0x5030  59  RegionCore_get_sizeScanAlloc */
  return *param_1 << 2;
}



===== RegionCore_set_sizeScan @ 140005040 =====

void RegionCore_set_sizeScan(longlong param_1,uint param_2)

{
                    /* 0x5040  67  RegionCore_set_sizeScan */
  *(ulonglong *)(param_1 + 0x10) = (ulonglong)(param_2 >> 2);
  return;
}



===== RegionCore_get_pScan_const @ 140005050 =====

undefined8 RegionCore_get_pScan_const(longlong param_1)

{
                    /* 0x5050  54  RegionCore_get_pScan_const
                       0x5050  55  RegionCore_get_pScan_mut */
  return *(undefined8 *)(param_1 + 8);
}



===== RegionCore_get_pscnTail_const @ 140005060 =====

longlong RegionCore_get_pscnTail_const(longlong param_1)

{
                    /* 0x5060  56  RegionCore_get_pscnTail_const
                       0x5060  57  RegionCore_get_pscnTail_mut */
  return *(longlong *)(param_1 + 0x10) * 4 + *(longlong *)(param_1 + 8);
}



===== RegionCore_numRect @ 140005080 =====

longlong RegionCore_numRect(longlong param_1)

{
  longlong lVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  longlong lVar6;
  
                    /* 0x5080  65  RegionCore_numRect */
  uVar3 = _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalQINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E13is_valid_scanB4__llvm_3083486868190693220
                    (param_1,0);
  if ((char)uVar3 == '\0') {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core9panicking5panic();
  }
  lVar1 = *(longlong *)(param_1 + 8);
  uVar2 = *(ulonglong *)(param_1 + 0x10);
  uVar5 = 0;
  lVar6 = 0;
  do {
    if (uVar2 <= uVar5) {
                    /* WARNING: Subroutine does not return */
      _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
    }
    uVar4 = (ulonglong)*(int *)(lVar1 + uVar5 * 4);
    uVar5 = uVar5 + uVar4 + 4;
    lVar6 = lVar6 + (uVar4 >> 1);
    uVar3 = _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalQINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E13is_valid_scanB4__llvm_3083486868190693220
                      (param_1,uVar5);
  } while ((char)uVar3 != '\0');
  return lVar6;
}



===== RegionCore_sizeSave @ 140005090 =====

int RegionCore_sizeSave(longlong param_1)

{
  longlong lVar1;
  
                    /* 0x5090  71  RegionCore_sizeSave */
  lVar1 = _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore10rect_count(param_1);
  return (int)lVar1 << 4;
}



===== RegionCore_download @ 1400050b0 =====

ulonglong RegionCore_download(longlong param_1,ulonglong param_2,ulonglong param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  longlong lVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  longlong lVar10;
  ulonglong uVar11;
  longlong lVar12;
  ulonglong uVar13;
  
  uVar8 = param_2;
                    /* 0x50b0  51  RegionCore_download */
  lVar4 = _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore10first_scan(param_1);
  uVar13 = 0;
  while( true ) {
    uVar11 = *(ulonglong *)(lVar4 + 0x10);
    if (uVar11 <= uVar8 + 1) {
                    /* WARNING: Subroutine does not return */
      _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
    }
    if (uVar11 <= uVar8 + 2) {
                    /* WARNING: Subroutine does not return */
      _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
    }
    if (uVar11 <= uVar8) break;
    lVar10 = *(longlong *)(lVar4 + 8);
    uVar9 = (ulonglong)(longlong)*(int *)(lVar10 + uVar8 * 4) >> 1;
    uVar5 = param_3 - uVar13;
    if (uVar9 <= param_3 - uVar13) {
      uVar5 = uVar9;
    }
    if (uVar5 != 0) {
      uVar1 = *(undefined4 *)(lVar10 + 4 + uVar8 * 4);
      uVar2 = *(undefined4 *)(lVar10 + 8 + uVar8 * 4);
      lVar10 = uVar13 * 0x10 + param_2 + 0xc;
      uVar11 = 0;
      do {
        uVar9 = *(ulonglong *)(lVar4 + 0x10);
        if (uVar9 <= uVar8) goto LAB_14000523b;
        uVar7 = (ulonglong)*(int *)(*(longlong *)(lVar4 + 8) + uVar8 * 4);
        if (uVar7 <= uVar11) {
LAB_140005217:
                    /* WARNING: Subroutine does not return */
          _RNvNtCsloaxXL3qbEI_4core9panicking5panic();
        }
        if (uVar9 <= uVar8 + uVar11 + 3) {
LAB_14000522f:
                    /* WARNING: Subroutine does not return */
          _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
        }
        if (uVar7 <= uVar11 + 1) goto LAB_140005217;
        if (uVar9 <= uVar8 + uVar11 + 4) goto LAB_14000522f;
        if (param_3 <= uVar13) {
                    /* WARNING: Subroutine does not return */
          _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
        }
        lVar12 = *(longlong *)(lVar4 + 8) + uVar8 * 4 + 0x10;
        uVar3 = *(undefined4 *)(lVar12 + uVar11 * 4);
        *(undefined4 *)(lVar10 + -0xc + uVar11 * 8) = *(undefined4 *)(lVar12 + -4 + uVar11 * 4);
        *(undefined4 *)(lVar10 + -8 + uVar11 * 8) = uVar1;
        *(undefined4 *)(lVar10 + -4 + uVar11 * 8) = uVar3;
        *(undefined4 *)(lVar10 + uVar11 * 8) = uVar2;
        uVar13 = uVar13 + 1;
        uVar11 = uVar11 + 2;
        uVar5 = uVar5 - 1;
      } while (uVar5 != 0);
      uVar11 = *(ulonglong *)(lVar4 + 0x10);
    }
    if (uVar11 <= uVar8) break;
    uVar8 = uVar8 + (longlong)*(int *)(*(longlong *)(lVar4 + 8) + uVar8 * 4) + 4;
    uVar6 = _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalRINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E13is_valid_scanCsdyToaWEq7tk_8gdi_rust_llvm_12588874305795175024
                      (lVar4,uVar8);
    if ((char)uVar6 == '\0') {
      return uVar13;
    }
  }
LAB_14000523b:
                    /* WARNING: Subroutine does not return */
  _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
}



===== RegionCore_set_to_rectls @ 140005280 =====

bool RegionCore_set_to_rectls(ulonglong *param_1,ulonglong param_2,longlong param_3)

{
  ulonglong uVar1;
  
                    /* 0x5280  70  RegionCore_set_to_rectls */
  uVar1 = _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore13set_to_rectls(param_1,param_3,param_2);
  return (int)uVar1 == 0;
}



===== RegionCore_iReduce @ 1400052b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong RegionCore_iReduce(ulonglong *param_1,longlong param_2)

{
  code *pcVar1;
  ulonglong uVar2;
  undefined1 auStack_b8 [32];
  longlong local_98;
  undefined4 local_90;
  undefined8 uStack_8c;
  undefined8 uStack_84;
  undefined8 local_7c;
  undefined8 uStack_74;
  undefined4 local_6c;
  longlong local_68;
  undefined4 local_60;
  undefined8 local_5c;
  undefined8 uStack_54;
  undefined8 local_4c;
  undefined8 uStack_44;
  undefined4 local_3c;
  int local_38 [6];
  ulonglong local_20;
  
                    /* 0x52b0  62  RegionCore_iReduce */
  local_20 = __security_cookie ^ (ulonglong)auStack_b8;
  local_38[0] = -0x8000000;
  local_38[1] = -0x8000000;
  local_38[2] = 0x7ffffff;
  local_38[3] = 0x7ffffff;
  _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore9from_rect(&local_68,local_38);
  if (!SBORROW8(0,local_68)) {
    uStack_8c = local_5c;
    uStack_84 = uStack_54;
    local_7c = local_4c;
    uStack_74 = uStack_44;
    local_6c = local_3c;
    local_98 = local_68;
    local_90 = local_60;
    _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore16set_to_rectangle(param_1,(int *)&DAT_14001a698);
    uVar2 = _RNvMs_NtCscIyU0BP6seX_7rgncore5mergeNtB6_10RegionCore5merge
                      (param_1,(longlong)&local_98,param_2,8);
    if ((int)uVar2 == 0) {
      uVar2 = 1;
      if ((int)param_1[3] != 1) {
        uVar2 = (ulonglong)(3 - (param_1[2] < 0xf));
      }
      if (local_68 != 0) {
        if (local_68 == 0x1c) {
          _RNvNtCsjsHfHFRyfyy_10gdi_region3ffi22ScanLookAsideList_Free();
        }
        else {
          _RNvNtCsiNQa5DCRmUC_9gdi_alloc3ffi13Win32FreePool();
        }
      }
      goto LAB_14000530a;
    }
    if (local_68 != 0) {
      if (local_68 == 0x1c) {
        _RNvNtCsjsHfHFRyfyy_10gdi_region3ffi22ScanLookAsideList_Free();
      }
      else {
        _RNvNtCsiNQa5DCRmUC_9gdi_alloc3ffi13Win32FreePool();
      }
    }
  }
  _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore16set_to_null_scan(param_1);
  uVar2 = 0;
LAB_14000530a:
  if ((local_20 ^ (ulonglong)auStack_b8) == __security_cookie) {
    return uVar2;
  }
  pcVar1 = (code *)swi(3);
  uVar2 = (*pcVar1)();
  return uVar2;
}



===== RegionCore_fill_path_with_outline @ 1400053f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong RegionCore_fill_path_with_outline(longlong param_1,longlong param_2,undefined8 param_3)

{
  code *pcVar1;
  ulonglong uVar2;
  undefined1 auStack_38 [32];
  longlong local_18;
  undefined8 local_10;
  ulonglong local_8;
  
                    /* 0x53f0  53  RegionCore_fill_path_with_outline */
  local_8 = __security_cookie ^ (ulonglong)auStack_38;
  local_18 = param_2;
  local_10 = param_3;
  uVar2 = _RINvMNtCscIyU0BP6seX_7rgncore9fill_pathNtB5_10RegionCore30fill_path_with_outline_genericNtNtCsdyToaWEq7tk_8gdi_rust6region12EPATHOBJSinkEB1s_
                    (param_1,&local_18);
  if ((local_8 ^ (ulonglong)auStack_38) == __security_cookie) {
    return (ulonglong)((int)uVar2 == 0);
  }
  pcVar1 = (code *)swi(3);
  uVar2 = (*pcVar1)();
  return uVar2;
}



===== RegionCore_upload @ 140005450 =====

bool RegionCore_upload(ulonglong *param_1,undefined **param_2,uint param_3)

{
  ulonglong uVar1;
  
                    /* 0x5450  74  RegionCore_upload */
  uVar1 = _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore6upload(param_1,param_2,(ulonglong)param_3);
  return (int)uVar1 == 0;
}



===== RegionCore_upload_for_floodfill @ 140005470 =====

ulonglong RegionCore_upload_for_floodfill
                    (ulonglong *param_1,int *param_2,uint param_3,undefined **param_4,uint param_5)

{
  int iVar1;
  ulonglong uVar2;
  
                    /* 0x5470  75  RegionCore_upload_for_floodfill */
  uVar2 = _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore20upload_for_floodfill
                    (param_1,param_2,(ulonglong)param_3,param_4,(ulonglong)param_5);
  iVar1 = (int)uVar2;
  if (iVar1 < 0xe) {
    if (iVar1 == 0) {
      return uVar2;
    }
    if (iVar1 == 8) {
      return 0xc0000023;
    }
  }
  else {
    if (iVar1 == 0xe) {
      return 0xc0000017;
    }
    if (iVar1 == 0x57) {
      return 0xc000000d;
    }
  }
  return 0xc0000001;
}



===== _RNvNtNtCsdyToaWEq7tk_8gdi_rust5xform7xformer7bCvtPts @ 1400054d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
_RNvNtNtCsdyToaWEq7tk_8gdi_rust5xform7xformer7bCvtPts
          (float *param_1,longlong param_2,ulonglong param_3,longlong param_4,ulonglong param_5)

{
  int *piVar1;
  int *piVar2;
  ulonglong uVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  code *pcVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  ulonglong uVar17;
  undefined8 uVar18;
  ulonglong uVar19;
  uint uVar20;
  float fVar21;
  float fVar22;
  undefined1 auStack_108 [32];
  undefined **local_e8;
  ulonglong local_d8;
  undefined **local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  ulonglong local_a0;
  
  local_a0 = __security_cookie ^ (ulonglong)auStack_108;
  local_d8 = param_3;
  if (param_3 != param_5) {
    local_d0 = &anon_74be573667ea39222c9b5e724367a855_5_llvm_13016933376561125598;
    local_c8 = 1;
    local_c0 = 8;
    local_b8 = 0;
    uStack_b0 = 0;
    local_e8 = &PTR_anon_74be573667ea39222c9b5e724367a855_6_llvm_13016933376561125598_140019158;
    _RINvNtCsloaxXL3qbEI_4core9panicking13assert_failedjjEB4_
              (0,&local_d8,&param_5,(longlong *)&local_d0);
    pcVar10 = (code *)swi(3);
    uVar18 = (*pcVar10)();
    return uVar18;
  }
  uVar14 = (uint)param_1[8] & 0xb;
  uVar17 = 0;
  if (uVar14 == 0xb) {
    if (param_3 != 0) {
      iVar16 = (int)*(undefined8 *)(param_1 + 6);
      iVar15 = (int)((ulonglong)*(undefined8 *)(param_1 + 6) >> 0x20);
      if (param_3 == 1) {
        uVar17 = 0;
      }
      else {
        uVar17 = param_3 & 0xfffffffffffffffe;
        uVar19 = 0;
        do {
          piVar1 = (int *)(param_2 + uVar19 * 8);
          iVar11 = piVar1[1];
          iVar12 = piVar1[2];
          iVar13 = piVar1[3];
          piVar2 = (int *)(param_4 + uVar19 * 8);
          *piVar2 = *piVar1 * 0x10 + iVar16;
          piVar2[1] = iVar11 * 0x10 + iVar15;
          piVar2[2] = iVar12 * 0x10 + iVar16;
          piVar2[3] = iVar13 * 0x10 + iVar15;
          uVar19 = uVar19 + 2;
        } while (uVar17 != uVar19);
        if (param_3 == uVar17) goto LAB_140005790;
      }
      do {
        uVar18 = *(undefined8 *)(param_2 + uVar17 * 8);
        *(ulonglong *)(param_4 + uVar17 * 8) =
             CONCAT44((int)((ulonglong)uVar18 >> 0x20) * 0x10 + iVar15,(int)uVar18 * 0x10 + iVar16);
        uVar17 = uVar17 + 1;
      } while (param_3 != uVar17);
    }
  }
  else {
    uVar20 = (uint)param_1[8] & 3;
    if (uVar20 == 0) {
      if (param_3 != 0) {
        fVar4 = *param_1;
        fVar5 = param_1[1];
        fVar6 = param_1[2];
        fVar7 = param_1[3];
        fVar8 = param_1[6];
        fVar9 = param_1[7];
        uVar19 = 0;
        do {
          fVar21 = (float)*(int *)(param_2 + uVar19 * 8);
          uVar3 = uVar19 + 1;
          fVar22 = (float)*(int *)(param_2 + 4 + uVar19 * 8);
          iVar16 = _RNvNtCslMg0IV26qJh_12gdi_bindings6efloat14bEfToL_or_zero
                             ((uint)(fVar6 * fVar22 + fVar4 * fVar21));
          iVar15 = _RNvNtCslMg0IV26qJh_12gdi_bindings6efloat14bEfToL_or_zero
                             ((uint)(fVar22 * fVar7 + fVar21 * fVar5));
          *(int *)(param_4 + uVar19 * 8) = iVar16 + (int)fVar8;
          uVar17 = (ulonglong)(uint)(iVar15 + (int)fVar9);
          *(int *)(param_4 + 4 + uVar19 * 8) = iVar15 + (int)fVar9;
          uVar19 = uVar3;
        } while (param_3 != uVar3);
      }
    }
    else if (uVar20 == 1) {
      if (param_3 != 0) {
        fVar4 = *param_1;
        fVar5 = param_1[3];
        fVar6 = param_1[6];
        fVar7 = param_1[7];
        uVar19 = 0;
        do {
          uVar3 = uVar19 + 1;
          iVar16 = *(int *)(param_2 + 4 + uVar19 * 8);
          iVar15 = _RNvNtCslMg0IV26qJh_12gdi_bindings6efloat14bEfToL_or_zero
                             ((uint)((float)*(int *)(param_2 + uVar19 * 8) * fVar4));
          iVar16 = _RNvNtCslMg0IV26qJh_12gdi_bindings6efloat14bEfToL_or_zero
                             ((uint)((float)iVar16 * fVar5));
          *(int *)(param_4 + uVar19 * 8) = iVar15 + (int)fVar6;
          uVar17 = (ulonglong)(uint)(iVar16 + (int)fVar7);
          *(int *)(param_4 + 4 + uVar19 * 8) = iVar16 + (int)fVar7;
          uVar19 = uVar3;
        } while (param_3 != uVar3);
      }
    }
    else {
      uVar17 = 0;
      if (param_3 != 0 && uVar14 == 3) {
        iVar16 = (int)*(undefined8 *)(param_1 + 6);
        iVar15 = (int)((ulonglong)*(undefined8 *)(param_1 + 6) >> 0x20);
        if (param_3 < 2) {
          uVar17 = 0;
        }
        else {
          uVar17 = param_3 & 0xfffffffffffffffe;
          uVar19 = 0;
          do {
            piVar1 = (int *)(param_2 + uVar19 * 8);
            iVar11 = piVar1[1];
            iVar12 = piVar1[2];
            iVar13 = piVar1[3];
            piVar2 = (int *)(param_4 + uVar19 * 8);
            *piVar2 = ((*piVar1 >> 3) + 1 >> 1) + iVar16;
            piVar2[1] = ((iVar11 >> 3) + 1 >> 1) + iVar15;
            piVar2[2] = ((iVar12 >> 3) + 1 >> 1) + iVar16;
            piVar2[3] = ((iVar13 >> 3) + 1 >> 1) + iVar15;
            uVar19 = uVar19 + 2;
          } while (uVar17 != uVar19);
          if (param_3 == uVar17) goto LAB_140005790;
        }
        do {
          uVar18 = *(undefined8 *)(param_2 + uVar17 * 8);
          uVar20 = (uint)uVar18;
          uVar14 = (uint)((ulonglong)uVar18 >> 0x20);
          *(ulonglong *)(param_4 + uVar17 * 8) =
               CONCAT44(((int)uVar14 >> 4) + iVar15 + (uVar14 >> 3 & 1),
                        ((int)uVar20 >> 4) + iVar16 + (uVar20 >> 3 & 1));
          uVar17 = uVar17 + 1;
        } while (param_3 != uVar17);
      }
    }
  }
LAB_140005790:
  if ((local_a0 ^ (ulonglong)auStack_108) == __security_cookie) {
    return CONCAT71((int7)(uVar17 >> 8),1);
  }
  pcVar10 = (code *)swi(3);
  uVar18 = (*pcVar10)();
  return uVar18;
}



===== _RNvNtNtCsdyToaWEq7tk_8gdi_rust5xform7xformer8bCvtPts1 @ 140005840 =====

undefined8
_RNvNtNtCsdyToaWEq7tk_8gdi_rust5xform7xformer8bCvtPts1(float *param_1,int *param_2,longlong param_3)

{
  int *piVar1;
  int *piVar2;
  float fVar3;
  float fVar4;
  undefined8 uVar5;
  float fVar6;
  float fVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  undefined4 extraout_var;
  int *piVar18;
  undefined4 extraout_var_00;
  ulonglong uVar19;
  ulonglong uVar20;
  ulonglong uVar21;
  longlong lVar22;
  uint uVar23;
  float fVar24;
  float fVar25;
  
  uVar14 = (uint)param_1[8] & 0xb;
  piVar18 = (int *)0x0;
  if (uVar14 < 8) {
    if (uVar14 == 0) {
      if (param_3 != 0) {
        piVar1 = param_2 + param_3 * 2;
        fVar3 = *param_1;
        fVar4 = param_1[1];
        fVar6 = param_1[2];
        fVar7 = param_1[3];
        fVar24 = param_1[6];
        fVar25 = param_1[7];
        do {
          iVar17 = *param_2;
          iVar16 = param_2[1];
          iVar15 = _RNvNtCslMg0IV26qJh_12gdi_bindings6efloat14bEfToL_or_zero
                             ((uint)(fVar6 * (float)(iVar16 << 4) + fVar3 * (float)(iVar17 << 4)));
          *param_2 = iVar15;
          iVar17 = _RNvNtCslMg0IV26qJh_12gdi_bindings6efloat14bEfToL_or_zero
                             ((uint)((float)(iVar16 << 4) * fVar7 + (float)(iVar17 << 4) * fVar4));
          *param_2 = *param_2 + (int)fVar24;
          piVar18 = (int *)(ulonglong)(uint)(iVar17 + (int)fVar25);
          param_2[1] = iVar17 + (int)fVar25;
          param_2 = param_2 + 2;
        } while (param_2 != piVar1);
      }
    }
    else if (uVar14 == 1) {
      if (param_3 != 0) {
        piVar1 = param_2 + param_3 * 2;
        fVar3 = *param_1;
        fVar4 = param_1[3];
        fVar6 = param_1[6];
        fVar7 = param_1[7];
        do {
          iVar17 = param_2[1];
          iVar16 = _RNvNtCslMg0IV26qJh_12gdi_bindings6efloat14bEfToL_or_zero
                             ((uint)((float)(*param_2 << 4) * fVar3));
          *param_2 = iVar16;
          iVar17 = _RNvNtCslMg0IV26qJh_12gdi_bindings6efloat14bEfToL_or_zero
                             ((uint)((float)(iVar17 << 4) * fVar4));
          *param_2 = *param_2 + (int)fVar6;
          piVar18 = (int *)(ulonglong)(uint)(iVar17 + (int)fVar7);
          param_2[1] = iVar17 + (int)fVar7;
          param_2 = param_2 + 2;
        } while (param_2 != piVar1);
      }
    }
    else if ((uVar14 == 3) && (param_3 != 0)) {
      uVar19 = param_3 - 1U & 0x1fffffffffffffff;
      iVar16 = (int)((ulonglong)*(undefined8 *)(param_1 + 6) >> 0x20);
      iVar17 = (int)*(undefined8 *)(param_1 + 6);
      piVar18 = param_2;
      if (2 < uVar19) {
        uVar19 = uVar19 + 1;
        uVar20 = uVar19 & 0xfffffffffffffffc;
        piVar18 = param_2 + uVar20 * 2;
        uVar21 = 0;
        do {
          piVar1 = param_2 + uVar21 * 2;
          iVar15 = piVar1[1];
          iVar8 = piVar1[2];
          iVar9 = piVar1[3];
          piVar2 = param_2 + uVar21 * 2 + 4;
          iVar10 = *piVar2;
          iVar11 = piVar2[1];
          iVar12 = piVar2[2];
          iVar13 = piVar2[3];
          piVar2 = param_2 + uVar21 * 2;
          *piVar2 = *piVar1 + iVar17;
          piVar2[1] = iVar15 + iVar16;
          piVar2[2] = iVar8 + iVar17;
          piVar2[3] = iVar9 + iVar16;
          piVar1 = param_2 + uVar21 * 2 + 4;
          *piVar1 = iVar10 + iVar17;
          piVar1[1] = iVar11 + iVar16;
          piVar1[2] = iVar12 + iVar17;
          piVar1[3] = iVar13 + iVar16;
          uVar21 = uVar21 + 4;
        } while (uVar20 != uVar21);
        if (uVar19 == uVar20) goto LAB_140005c58;
      }
      do {
        *(ulonglong *)piVar18 =
             CONCAT44((int)((ulonglong)*(undefined8 *)piVar18 >> 0x20) + iVar16,
                      (int)*(undefined8 *)piVar18 + iVar17);
        piVar18 = piVar18 + 2;
      } while (piVar18 != param_2 + param_3 * 2);
    }
  }
  else if (uVar14 == 8) {
    if (param_3 != 0) {
      fVar6 = *param_1;
      fVar7 = param_1[1];
      uVar5 = *(undefined8 *)(param_1 + 6);
      fVar3 = param_1[3];
      fVar4 = param_1[2];
      lVar22 = 0;
      do {
        fVar24 = (float)(int)*(undefined8 *)((longlong)param_2 + lVar22);
        fVar25 = (float)(int)((ulonglong)*(undefined8 *)((longlong)param_2 + lVar22) >> 0x20);
        iVar17 = _RNvNtCslMg0IV26qJh_12gdi_bindings6efloat14bEfToL_or_zero
                           ((uint)(fVar4 * fVar25 + fVar6 * fVar24));
        iVar16 = _RNvNtCslMg0IV26qJh_12gdi_bindings6efloat14bEfToL_or_zero
                           ((uint)(fVar25 * fVar3 + fVar24 * fVar7));
        piVar18 = (int *)CONCAT44(extraout_var_00,iVar16);
        uVar14 = iVar17 + (int)uVar5;
        uVar23 = iVar16 + (int)((ulonglong)uVar5 >> 0x20);
        *(ulonglong *)((longlong)param_2 + lVar22) =
             CONCAT44(((int)uVar23 >> 4) + (uVar23 >> 3 & 1),((int)uVar14 >> 4) + (uVar14 >> 3 & 1))
        ;
        lVar22 = lVar22 + 8;
      } while (param_3 * 8 != lVar22);
    }
  }
  else if (uVar14 == 0xb) {
    if (param_3 != 0) {
      uVar23 = (uint)*(undefined8 *)(param_1 + 6);
      uVar14 = (uint)((ulonglong)*(undefined8 *)(param_1 + 6) >> 0x20);
      iVar17 = (uVar23 >> 3 & 1) + ((int)uVar23 >> 4);
      iVar16 = (uVar14 >> 3 & 1) + ((int)uVar14 >> 4);
      uVar19 = param_3 - 1U & 0x1fffffffffffffff;
      piVar18 = param_2;
      if (2 < uVar19) {
        uVar19 = uVar19 + 1;
        uVar20 = uVar19 & 0xfffffffffffffffc;
        piVar18 = param_2 + uVar20 * 2;
        uVar21 = 0;
        do {
          piVar1 = param_2 + uVar21 * 2;
          iVar15 = piVar1[1];
          iVar8 = piVar1[2];
          iVar9 = piVar1[3];
          piVar2 = param_2 + uVar21 * 2 + 4;
          iVar10 = *piVar2;
          iVar11 = piVar2[1];
          iVar12 = piVar2[2];
          iVar13 = piVar2[3];
          piVar2 = param_2 + uVar21 * 2;
          *piVar2 = *piVar1 + iVar17;
          piVar2[1] = iVar15 + iVar16;
          piVar2[2] = iVar8 + iVar17;
          piVar2[3] = iVar9 + iVar16;
          piVar1 = param_2 + uVar21 * 2 + 4;
          *piVar1 = iVar10 + iVar17;
          piVar1[1] = iVar11 + iVar16;
          piVar1[2] = iVar12 + iVar17;
          piVar1[3] = iVar13 + iVar16;
          uVar21 = uVar21 + 4;
        } while (uVar20 != uVar21);
        if (uVar19 == uVar20) goto LAB_140005c58;
      }
      do {
        *(ulonglong *)piVar18 =
             CONCAT44((int)((ulonglong)*(undefined8 *)piVar18 >> 0x20) + iVar16,
                      (int)*(undefined8 *)piVar18 + iVar17);
        piVar18 = piVar18 + 2;
      } while (piVar18 != param_2 + param_3 * 2);
    }
  }
  else if ((uVar14 == 9) && (param_3 != 0)) {
    piVar1 = param_2 + param_3 * 2;
    fVar3 = *param_1;
    fVar4 = param_1[3];
    uVar5 = *(undefined8 *)(param_1 + 6);
    do {
      iVar17 = param_2[1];
      iVar16 = _RNvNtCslMg0IV26qJh_12gdi_bindings6efloat14bEfToL_or_zero
                         ((uint)((float)*param_2 * fVar3));
      iVar17 = _RNvNtCslMg0IV26qJh_12gdi_bindings6efloat14bEfToL_or_zero
                         ((uint)((float)iVar17 * fVar4));
      piVar18 = (int *)CONCAT44(extraout_var,iVar17);
      uVar14 = iVar16 + (int)uVar5;
      uVar23 = iVar17 + (int)((ulonglong)uVar5 >> 0x20);
      *(ulonglong *)param_2 =
           CONCAT44(((int)uVar23 >> 4) + (uVar23 >> 3 & 1),((int)uVar14 >> 4) + (uVar14 >> 3 & 1));
      param_2 = param_2 + 2;
    } while (param_2 != piVar1);
  }
LAB_140005c58:
  return CONCAT71((int7)((ulonglong)piVar18 >> 8),1);
}



===== _RNvNtNtCsdyToaWEq7tk_8gdi_rust5xform7xformer7bCvtVts @ 140005c90 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
_RNvNtNtCsdyToaWEq7tk_8gdi_rust5xform7xformer7bCvtVts
          (float *param_1,longlong param_2,longlong param_3,longlong param_4,longlong param_5)

{
  longlong lVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  code *pcVar6;
  int iVar7;
  int iVar8;
  undefined4 extraout_var;
  undefined4 extraout_var_00;
  undefined8 uVar9;
  longlong lVar10;
  float fVar11;
  float fVar12;
  undefined1 auStack_e8 [32];
  undefined **local_c8;
  longlong local_b8;
  undefined **local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  ulonglong local_80;
  
  local_80 = __security_cookie ^ (ulonglong)auStack_e8;
  local_b8 = param_3;
  if (param_3 != param_5) {
    local_b0 = &anon_74be573667ea39222c9b5e724367a855_5_llvm_13016933376561125598;
    local_a8 = 1;
    local_a0 = 8;
    local_98 = 0;
    uStack_90 = 0;
    local_c8 = &PTR_anon_74be573667ea39222c9b5e724367a855_6_llvm_13016933376561125598_140019170;
    _RINvNtCsloaxXL3qbEI_4core9panicking13assert_failedjjEB4_
              (0,&local_b8,&param_5,(longlong *)&local_b0);
    pcVar6 = (code *)swi(3);
    uVar9 = (*pcVar6)();
    return uVar9;
  }
  uVar9 = 0;
  if (((uint)param_1[8] & 3) == 0) {
    if (param_3 != 0) {
      fVar2 = *param_1;
      fVar3 = param_1[1];
      fVar4 = param_1[2];
      fVar5 = param_1[3];
      lVar10 = 0;
      do {
        fVar11 = (float)*(int *)(param_2 + lVar10 * 8);
        lVar1 = lVar10 + 1;
        fVar12 = (float)*(int *)(param_2 + 4 + lVar10 * 8);
        iVar8 = _RNvNtCslMg0IV26qJh_12gdi_bindings6efloat14bEfToL_or_zero
                          ((uint)(fVar4 * fVar12 + fVar2 * fVar11));
        *(int *)(param_4 + lVar10 * 8) = iVar8;
        iVar8 = _RNvNtCslMg0IV26qJh_12gdi_bindings6efloat14bEfToL_or_zero
                          ((uint)(fVar12 * fVar5 + fVar11 * fVar3));
        uVar9 = CONCAT44(extraout_var_00,iVar8);
        *(int *)(param_4 + 4 + lVar10 * 8) = iVar8;
        lVar10 = lVar1;
      } while (param_3 != lVar1);
    }
  }
  else if ((((uint)param_1[8] & 3) == 1) && (param_3 != 0)) {
    fVar2 = *param_1;
    fVar3 = param_1[3];
    lVar10 = 0;
    do {
      lVar1 = lVar10 + 1;
      iVar8 = *(int *)(param_2 + 4 + lVar10 * 8);
      iVar7 = _RNvNtCslMg0IV26qJh_12gdi_bindings6efloat14bEfToL_or_zero
                        ((uint)((float)*(int *)(param_2 + lVar10 * 8) * fVar2));
      *(int *)(param_4 + lVar10 * 8) = iVar7;
      iVar8 = _RNvNtCslMg0IV26qJh_12gdi_bindings6efloat14bEfToL_or_zero
                        ((uint)((float)iVar8 * fVar3));
      uVar9 = CONCAT44(extraout_var,iVar8);
      *(int *)(param_4 + 4 + lVar10 * 8) = iVar8;
      lVar10 = lVar1;
    } while (param_3 != lVar1);
  }
  if ((local_80 ^ (ulonglong)auStack_e8) == __security_cookie) {
    return CONCAT71((int7)((ulonglong)uVar9 >> 8),1);
  }
  pcVar6 = (code *)swi(3);
  uVar9 = (*pcVar6)();
  return uVar9;
}



===== _RNvXs_NtNtCsloaxXL3qbEI_4core3ptr9alignmentNtB4_9AlignmentNtNtB8_3fmt5Debug3fmt @ 140005e80 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void _RNvXs_NtNtCsloaxXL3qbEI_4core3ptr9alignmentNtB4_9AlignmentNtNtB8_3fmt5Debug3fmt
               (ulonglong *param_1,undefined8 *param_2)

{
  code *pcVar1;
  ulonglong uVar2;
  int local_6c;
  undefined *local_68;
  undefined8 local_60;
  ulonglong **local_58;
  undefined8 local_50;
  undefined8 local_48;
  ulonglong local_38;
  ulonglong *local_30;
  code *local_28;
  int *local_20;
  code *local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)&local_18;
  local_6c = 0;
  local_38 = *param_1;
  for (uVar2 = local_38; (uVar2 & 1) == 0; uVar2 = uVar2 >> 1 | 0x8000000000000000) {
    local_6c = local_6c + 1;
  }
  local_30 = &local_38;
  local_28 = core::num::nonzero::impl$42::fmt<usize>;
  local_20 = &local_6c;
  local_18 = core::fmt::num::impl$88::fmt;
  local_68 = &DAT_140019198;
  local_60 = 3;
  local_48 = 0;
  local_58 = &local_30;
  local_50 = 2;
  _RNvNtCsloaxXL3qbEI_4core3fmt5write(*param_2,param_2[1],(longlong *)&local_68);
  if ((local_10 ^ (ulonglong)&local_18) == __security_cookie) {
    return;
  }
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== _RNvXs0_NtNtCsloaxXL3qbEI_4core3fmt8buildersNtB5_10PadAdapterNtB7_5Write9write_str @ 140005f40 =====

undefined8
_RNvXs0_NtNtCsloaxXL3qbEI_4core3fmt8buildersNtB5_10PadAdapterNtB7_5Write9write_str
          (longlong param_1,longlong param_2,ulonglong param_3)

{
  longlong lVar1;
  char *pcVar2;
  bool bVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  ulonglong *puVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  bool bVar12;
  
  pcVar2 = *(char **)(param_1 + 0x10);
  uVar5 = 0;
  bVar3 = false;
  uVar11 = 0;
  do {
    if (bVar3) {
      return 0;
    }
    if (param_3 < uVar5) {
    }
    else {
      uVar9 = uVar5;
      do {
        uVar5 = param_3 - uVar9;
        lVar1 = param_2 + uVar9;
        if (0xf < uVar5) {
          uVar7 = lVar1 + 7U & 0xfffffffffffffff8;
          uVar6 = uVar7 - lVar1;
          if (uVar6 != 0) {
            uVar10 = 0;
            do {
              if (*(char *)(lVar1 + uVar10) == '\n') goto LAB_140006140;
              uVar10 = uVar10 + 1;
            } while (uVar6 != uVar10);
            uVar10 = uVar6;
            if (uVar5 - 0x10 < uVar6) goto joined_r0x000140006118;
          }
          puVar8 = (ulonglong *)(uVar7 + 8);
          do {
            uVar10 = uVar6;
            if (((0x101010101010100 - (puVar8[-1] ^ 0xa0a0a0a0a0a0a0a) | puVar8[-1]) &
                 0x8080808080808080 &
                (0x101010101010100 - (*puVar8 ^ 0xa0a0a0a0a0a0a0a) | *puVar8 ^ 0xa0a0a0a0a0a0a0a))
                != 0x8080808080808080) break;
            uVar6 = uVar6 + 0x10;
            puVar8 = puVar8 + 2;
            uVar10 = uVar6;
          } while (uVar6 <= uVar5 - 0x10);
joined_r0x000140006118:
          do {
            if (uVar5 == uVar10) goto LAB_140006170;
            if (*(char *)(lVar1 + uVar10) == '\n') goto LAB_140006140;
            uVar10 = uVar10 + 1;
          } while( true );
        }
        if (param_3 == uVar9) {
LAB_140006170:
          uVar5 = param_3;
          break;
        }
        uVar10 = 0;
        while (*(char *)(lVar1 + uVar10) != '\n') {
          uVar10 = uVar10 + 1;
          if (uVar5 == uVar10) goto LAB_140006170;
        }
LAB_140006140:
        uVar5 = uVar9 + uVar10 + 1;
        if ((uVar9 + uVar10 < param_3) && (*(char *)(uVar10 + lVar1) == '\n')) {
          uVar9 = uVar5;
          uVar6 = uVar5;
          goto LAB_140006190;
        }
        uVar9 = uVar5;
      } while (uVar5 <= param_3);
    }
    bVar3 = true;
    uVar9 = param_3;
    uVar6 = uVar11;
    if (param_3 == uVar11) {
      return 0;
    }
LAB_140006190:
    if ((*pcVar2 != '\0') && (uVar4 = __llvm_retpoline_r11(), (char)uVar4 != '\0')) break;
    if (uVar9 == uVar11) {
      bVar12 = false;
    }
    else {
      bVar12 = *(char *)(param_2 + -1 + uVar9) == '\n';
    }
    *pcVar2 = bVar12;
    uVar4 = __llvm_retpoline_r11();
    uVar11 = uVar6;
  } while ((char)uVar4 == '\0');
  return CONCAT71((int7)((ulonglong)uVar4 >> 8),1);
}



===== _RNvXs0_NtNtCsloaxXL3qbEI_4core3fmt8buildersNtB5_10PadAdapterNtB7_5Write10write_char @ 140006200 =====

undefined8
_RNvXs0_NtNtCsloaxXL3qbEI_4core3fmt8buildersNtB5_10PadAdapterNtB7_5Write10write_char
          (longlong param_1,int param_2)

{
  char *pcVar1;
  undefined8 uVar2;
  
  pcVar1 = *(char **)(param_1 + 0x10);
  if (*pcVar1 != '\0') {
    uVar2 = __llvm_retpoline_r11();
    if ((char)uVar2 != '\0') {
      return CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
    }
  }
  *pcVar1 = param_2 == 10;
  uVar2 = __llvm_retpoline_r11();
  return uVar2;
}



===== _RNvMs1_NtNtCsloaxXL3qbEI_4core3fmt8buildersNtB5_11DebugStruct5field @ 140006290 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

longlong *
_RNvMs1_NtNtCsloaxXL3qbEI_4core3fmt8buildersNtB5_11DebugStruct5field
          (longlong *param_1,longlong param_2,ulonglong param_3)

{
  undefined8 *puVar1;
  code *pcVar2;
  char cVar3;
  undefined1 uVar4;
  longlong *plVar5;
  undefined8 uVar6;
  undefined1 local_79;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined1 *local_68;
  undefined8 *local_60;
  undefined *local_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)&local_48;
  uVar4 = 1;
  if ((char)param_1[1] == '\0') {
    puVar1 = (undefined8 *)*param_1;
    if ((*(byte *)((longlong)puVar1 + 0x12) & 0x80) == 0) {
      cVar3 = __llvm_retpoline_r11();
      if (((cVar3 == '\0') && (cVar3 = __llvm_retpoline_r11(), cVar3 == '\0')) &&
         (cVar3 = __llvm_retpoline_r11(), cVar3 == '\0')) {
        uVar4 = __llvm_retpoline_r11();
      }
    }
    else {
      if (*(char *)((longlong)param_1 + 9) == '\0') {
        cVar3 = __llvm_retpoline_r11();
        uVar4 = 1;
        if (cVar3 != '\0') goto LAB_1400062bf;
      }
      uVar4 = 1;
      local_79 = 1;
      local_78 = *puVar1;
      uStack_70 = puVar1[1];
      local_68 = &local_79;
      local_50 = puVar1[2];
      local_60 = &local_78;
      local_58 = &DAT_140019298;
      uVar6 = _RNvXs0_NtNtCsloaxXL3qbEI_4core3fmt8buildersNtB5_10PadAdapterNtB7_5Write9write_str
                        ((longlong)local_60,param_2,param_3);
      if ((((char)uVar6 == '\0') &&
          (uVar6 = _RNvXs0_NtNtCsloaxXL3qbEI_4core3fmt8buildersNtB5_10PadAdapterNtB7_5Write9write_str
                             ((longlong)&local_78,0x14001a818,2), (char)uVar6 == '\0')) &&
         (cVar3 = __llvm_retpoline_r11(), cVar3 == '\0')) {
        uVar4 = __llvm_retpoline_r11();
      }
    }
  }
LAB_1400062bf:
  *(undefined1 *)(param_1 + 1) = uVar4;
  *(undefined1 *)((longlong)param_1 + 9) = 1;
  if ((local_48 ^ (ulonglong)&local_48) == __security_cookie) {
    return param_1;
  }
  pcVar2 = (code *)swi(3);
  plVar5 = (longlong *)(*pcVar2)();
  return plVar5;
}



===== write_fmt<core::fmt::builders::PadAdapter> @ 1400064b0 =====

void core::fmt::Write::write_fmt<core::fmt::builders::PadAdapter>
               (undefined8 param_1,longlong *param_2)

{
  _RNvNtCsloaxXL3qbEI_4core3fmt5write(param_1,&DAT_140019298,param_2);
  return;
}



===== _RNvXs7_NtCsloaxXL3qbEI_4core3fmtNtB5_9ArgumentsNtB5_7Display3fmt @ 1400064d0 =====

void _RNvXs7_NtCsloaxXL3qbEI_4core3fmtNtB5_9ArgumentsNtB5_7Display3fmt
               (longlong *param_1,undefined8 *param_2)

{
  _RNvNtCsloaxXL3qbEI_4core3fmt5write(*param_2,param_2[1],param_1);
  return;
}



===== _RNvNtCsloaxXL3qbEI_4core3fmt5write @ 1400064f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
_RNvNtCsloaxXL3qbEI_4core3fmt5write(undefined8 param_1,undefined8 param_2,longlong *param_3)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  code *pcVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  longlong lVar8;
  longlong lVar9;
  longlong *plVar10;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)&local_48;
  if (param_3[4] == 0) {
    lVar2 = param_3[3];
    if (lVar2 != 0) {
      lVar8 = param_3[2];
      lVar3 = *param_3;
      lVar9 = 0;
      uVar7 = 0;
      do {
        if ((*(longlong *)(lVar3 + 8 + lVar9) != 0) &&
           (uVar5 = __llvm_retpoline_r11(), (char)uVar5 != '\0')) goto LAB_1400066e1;
        lVar1 = lVar8 + lVar9;
        uVar5 = __llvm_retpoline_r11();
        if ((char)uVar5 != '\0') goto LAB_1400066e1;
        lVar9 = lVar9 + 0x10;
        uVar7 = uVar7 + 1;
      } while (lVar1 + 0x10 != lVar2 * 0x10 + lVar8);
      goto LAB_1400066d9;
    }
    if (param_3[1] != 0) goto LAB_1400066f7;
  }
  else {
    lVar2 = param_3[5];
    if (lVar2 == 0) {
      if (param_3[1] == 0) goto LAB_140006727;
    }
    else {
      plVar10 = (longlong *)(*param_3 + 8);
      lVar8 = 0;
      uVar7 = 0;
      do {
        if (((*plVar10 != 0) && (uVar5 = __llvm_retpoline_r11(), (char)uVar5 != '\0')) ||
           (uVar5 = __llvm_retpoline_r11(), (char)uVar5 != '\0')) goto LAB_1400066e1;
        plVar10 = plVar10 + 2;
        lVar8 = lVar8 + 0x30;
        uVar7 = uVar7 + 1;
      } while (lVar2 * 0x30 != lVar8);
LAB_1400066d9:
      if ((ulonglong)param_3[1] <= uVar7) goto LAB_140006727;
    }
LAB_1400066f7:
    uVar6 = __llvm_retpoline_r11();
    uVar5 = CONCAT71((int7)((ulonglong)uVar6 >> 8),1);
    if ((char)uVar6 != '\0') goto LAB_140006729;
  }
LAB_140006727:
  uVar5 = 0;
LAB_140006729:
  if ((local_48 ^ (ulonglong)&local_48) == __security_cookie) {
    return uVar5;
  }
  pcVar4 = (code *)swi(3);
  uVar5 = (*pcVar4)();
  return uVar5;
LAB_1400066e1:
  uVar5 = CONCAT71((int7)((ulonglong)uVar5 >> 8),1);
  goto LAB_140006729;
}



===== _RNvMs9_NtCsloaxXL3qbEI_4core3fmtNtB5_9Formatter12pad_integral @ 140006760 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong _RNvMs9_NtCsloaxXL3qbEI_4core3fmtNtB5_9Formatter12pad_integral
                    (undefined8 *param_1,char param_2,undefined2 *param_3,ulonglong param_4,
                    undefined8 param_5,longlong param_6)

{
  char cVar1;
  uint uVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  uint uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  ushort uVar9;
  int iVar10;
  ushort uVar11;
  uint uVar12;
  int iVar13;
  undefined7 uVar14;
  char cVar18;
  undefined1 auVar15 [16];
  undefined1 auVar16 [16];
  undefined1 auVar17 [16];
  undefined1 auVar19 [16];
  undefined1 auVar20 [16];
  undefined1 auVar21 [16];
  char cVar22;
  char cVar24;
  char cVar25;
  char cVar26;
  char cVar27;
  char cVar28;
  char cVar29;
  char cVar30;
  undefined1 auVar23 [16];
  undefined1 auVar31 [16];
  undefined1 auVar32 [16];
  undefined1 auVar33 [16];
  undefined1 auVar34 [16];
  undefined1 auVar35 [16];
  undefined1 auVar36 [16];
  undefined1 auVar37 [16];
  undefined1 auVar38 [16];
  undefined1 auVar39 [16];
  undefined1 auVar40 [16];
  undefined1 auVar41 [16];
  undefined1 auVar42 [16];
  undefined1 auVar43 [16];
  undefined1 auVar44 [16];
  undefined1 auVar45 [16];
  undefined1 auVar46 [16];
  undefined1 auVar47 [16];
  undefined1 auVar48 [16];
  undefined1 auVar49 [16];
  undefined1 auVar50 [16];
  undefined1 auVar51 [16];
  undefined1 auVar52 [16];
  undefined1 auVar53 [16];
  int local_44;
  
  if (param_2 == '\0') {
    uVar8 = param_6 + 1;
    uVar12 = *(uint *)(param_1 + 2);
    local_44 = 0x2d;
    if ((uVar12 & 0x800000) == 0) goto LAB_1400067fd;
LAB_1400067b8:
    if (param_4 < 0x20) {
      if (param_4 == 0) {
        lVar3 = 0;
      }
      else {
        if (3 < param_4) {
          uVar2 = (uint)param_4 & 0x1c;
          uVar7 = (ulonglong)uVar2;
          cVar22 = __xmm_0000000000000000000000000000bfbf;
          auVar15[0] = -(cVar22 < (char)*param_3);
          cVar24 = __xmm_0000000000000000000000000000bfbf._1_1_;
          cVar1 = -(cVar24 < (char)((ushort)*param_3 >> 8));
          cVar25 = __xmm_0000000000000000000000000000bfbf._2_1_;
          cVar26 = __xmm_0000000000000000000000000000bfbf._3_1_;
          cVar27 = __xmm_0000000000000000000000000000bfbf._4_1_;
          cVar28 = __xmm_0000000000000000000000000000bfbf._5_1_;
          cVar29 = __xmm_0000000000000000000000000000bfbf._6_1_;
          cVar30 = __xmm_0000000000000000000000000000bfbf._7_1_;
          cVar18 = -(cVar30 < '\0');
          auVar15._8_8_ =
               (undefined8)
               (CONCAT72(CONCAT61(CONCAT51(CONCAT41(CONCAT31(CONCAT21(CONCAT11(cVar18,cVar18),
                                                                      -(cVar29 < '\0')),
                                                             -(cVar29 < '\0')),-(cVar28 < '\0')),
                                           -(cVar28 < '\0')),-(cVar27 < '\0')),
                         CONCAT11(-(cVar27 < '\0'),cVar18)) >> 8);
          auVar15[7] = -(cVar26 < '\0');
          auVar15[6] = -(cVar26 < '\0');
          auVar15[5] = -(cVar25 < '\0');
          auVar15[4] = -(cVar25 < '\0');
          auVar15[3] = cVar1;
          auVar15[2] = cVar1;
          auVar15[1] = auVar15[0];
          auVar15 = pshuflw(auVar15,auVar15,0xd4);
          auVar16._12_4_ = auVar15._12_4_;
          auVar16._0_8_ = auVar15._0_8_;
          auVar16._8_4_ = auVar15._4_4_;
          auVar17 = auVar16 & ___xmm_00000000000000010000000000000001;
          auVar19[0] = -(cVar22 < (char)param_3[1]);
          cVar1 = -(cVar24 < (char)((ushort)param_3[1] >> 8));
          cVar18 = -(cVar30 < '\0');
          auVar19._8_8_ =
               (undefined8)
               (CONCAT72(CONCAT61(CONCAT51(CONCAT41(CONCAT31(CONCAT21(CONCAT11(cVar18,cVar18),
                                                                      -(cVar29 < '\0')),
                                                             -(cVar29 < '\0')),-(cVar28 < '\0')),
                                           -(cVar28 < '\0')),-(cVar27 < '\0')),
                         CONCAT11(-(cVar27 < '\0'),cVar18)) >> 8);
          auVar19[7] = -(cVar26 < '\0');
          auVar19[6] = -(cVar26 < '\0');
          auVar19[5] = -(cVar25 < '\0');
          auVar19[4] = -(cVar25 < '\0');
          auVar19[3] = cVar1;
          auVar19[2] = cVar1;
          auVar19[1] = auVar19[0];
          auVar15 = pshuflw(auVar19,auVar19,0xd4);
          auVar20._12_4_ = auVar15._12_4_;
          auVar20._0_8_ = auVar15._0_8_;
          auVar20._8_4_ = auVar15._4_4_;
          auVar21 = auVar20 & ___xmm_00000000000000010000000000000001;
          if (uVar7 != 4) {
            auVar31[0] = -(cVar22 < (char)param_3[2]);
            cVar1 = -(cVar24 < (char)((ushort)param_3[2] >> 8));
            cVar18 = -(cVar30 < '\0');
            auVar31._8_8_ =
                 (undefined8)
                 (CONCAT72(CONCAT61(CONCAT51(CONCAT41(CONCAT31(CONCAT21(CONCAT11(cVar18,cVar18),
                                                                        -(cVar29 < '\0')),
                                                               -(cVar29 < '\0')),-(cVar28 < '\0')),
                                             -(cVar28 < '\0')),-(cVar27 < '\0')),
                           CONCAT11(-(cVar27 < '\0'),cVar18)) >> 8);
            auVar31[7] = -(cVar26 < '\0');
            auVar31[6] = -(cVar26 < '\0');
            auVar31[5] = -(cVar25 < '\0');
            auVar31[4] = -(cVar25 < '\0');
            auVar31[3] = cVar1;
            auVar31[2] = cVar1;
            auVar31[1] = auVar31[0];
            auVar15 = pshuflw(auVar31,auVar31,0xd4);
            auVar32._12_4_ = auVar15._12_4_;
            auVar32._0_8_ = auVar15._0_8_;
            auVar32._8_4_ = auVar15._4_4_;
            auVar43[0] = -(cVar22 < (char)param_3[3]);
            cVar1 = -(cVar24 < (char)((ushort)param_3[3] >> 8));
            cVar18 = -(cVar30 < '\0');
            auVar43._8_8_ =
                 (undefined8)
                 (CONCAT72(CONCAT61(CONCAT51(CONCAT41(CONCAT31(CONCAT21(CONCAT11(cVar18,cVar18),
                                                                        -(cVar29 < '\0')),
                                                               -(cVar29 < '\0')),-(cVar28 < '\0')),
                                             -(cVar28 < '\0')),-(cVar27 < '\0')),
                           CONCAT11(-(cVar27 < '\0'),cVar18)) >> 8);
            auVar43[7] = -(cVar26 < '\0');
            auVar43[6] = -(cVar26 < '\0');
            auVar43[5] = -(cVar25 < '\0');
            auVar43[4] = -(cVar25 < '\0');
            auVar43[3] = cVar1;
            auVar43[2] = cVar1;
            auVar43[1] = auVar43[0];
            auVar15 = pshuflw(auVar43,auVar43,0xd4);
            auVar44._12_4_ = auVar15._12_4_;
            auVar44._0_8_ = auVar15._0_8_;
            auVar44._8_4_ = auVar15._4_4_;
            lVar3 = auVar17._8_8_;
            auVar17._0_8_ =
                 auVar17._0_8_ + SUB168(auVar32 & ___xmm_00000000000000010000000000000001,0);
            auVar17._8_8_ = lVar3 + SUB168(auVar32 & ___xmm_00000000000000010000000000000001,8);
            lVar3 = auVar21._8_8_;
            auVar21._0_8_ =
                 auVar21._0_8_ + SUB168(auVar44 & ___xmm_00000000000000010000000000000001,0);
            auVar21._8_8_ = lVar3 + SUB168(auVar44 & ___xmm_00000000000000010000000000000001,8);
            if (uVar2 != 8) {
              auVar33[0] = -(cVar22 < (char)param_3[4]);
              cVar1 = -(cVar24 < (char)((ushort)param_3[4] >> 8));
              cVar18 = -(cVar30 < '\0');
              auVar33._8_8_ =
                   (undefined8)
                   (CONCAT72(CONCAT61(CONCAT51(CONCAT41(CONCAT31(CONCAT21(CONCAT11(cVar18,cVar18),
                                                                          -(cVar29 < '\0')),
                                                                 -(cVar29 < '\0')),-(cVar28 < '\0'))
                                               ,-(cVar28 < '\0')),-(cVar27 < '\0')),
                             CONCAT11(-(cVar27 < '\0'),cVar18)) >> 8);
              auVar33[7] = -(cVar26 < '\0');
              auVar33[6] = -(cVar26 < '\0');
              auVar33[5] = -(cVar25 < '\0');
              auVar33[4] = -(cVar25 < '\0');
              auVar33[3] = cVar1;
              auVar33[2] = cVar1;
              auVar33[1] = auVar33[0];
              auVar15 = pshuflw(auVar33,auVar33,0xd4);
              auVar34._12_4_ = auVar15._12_4_;
              auVar34._0_8_ = auVar15._0_8_;
              auVar34._8_4_ = auVar15._4_4_;
              auVar45[0] = -(cVar22 < (char)param_3[5]);
              cVar1 = -(cVar24 < (char)((ushort)param_3[5] >> 8));
              cVar18 = -(cVar30 < '\0');
              auVar45._8_8_ =
                   (undefined8)
                   (CONCAT72(CONCAT61(CONCAT51(CONCAT41(CONCAT31(CONCAT21(CONCAT11(cVar18,cVar18),
                                                                          -(cVar29 < '\0')),
                                                                 -(cVar29 < '\0')),-(cVar28 < '\0'))
                                               ,-(cVar28 < '\0')),-(cVar27 < '\0')),
                             CONCAT11(-(cVar27 < '\0'),cVar18)) >> 8);
              auVar45[7] = -(cVar26 < '\0');
              auVar45[6] = -(cVar26 < '\0');
              auVar45[5] = -(cVar25 < '\0');
              auVar45[4] = -(cVar25 < '\0');
              auVar45[3] = cVar1;
              auVar45[2] = cVar1;
              auVar45[1] = auVar45[0];
              auVar15 = pshuflw(auVar45,auVar45,0xd4);
              auVar46._12_4_ = auVar15._12_4_;
              auVar46._0_8_ = auVar15._0_8_;
              auVar46._8_4_ = auVar15._4_4_;
              auVar17._0_8_ =
                   auVar17._0_8_ + SUB168(auVar34 & ___xmm_00000000000000010000000000000001,0);
              auVar17._8_8_ =
                   auVar17._8_8_ + SUB168(auVar34 & ___xmm_00000000000000010000000000000001,8);
              auVar21._0_8_ =
                   auVar21._0_8_ + SUB168(auVar46 & ___xmm_00000000000000010000000000000001,0);
              auVar21._8_8_ =
                   auVar21._8_8_ + SUB168(auVar46 & ___xmm_00000000000000010000000000000001,8);
              if (uVar2 != 0xc) {
                auVar35[0] = -(cVar22 < (char)param_3[6]);
                cVar1 = -(cVar24 < (char)((ushort)param_3[6] >> 8));
                cVar18 = -(cVar30 < '\0');
                auVar35._8_8_ =
                     (undefined8)
                     (CONCAT72(CONCAT61(CONCAT51(CONCAT41(CONCAT31(CONCAT21(CONCAT11(cVar18,cVar18),
                                                                            -(cVar29 < '\0')),
                                                                   -(cVar29 < '\0')),
                                                          -(cVar28 < '\0')),-(cVar28 < '\0')),
                                        -(cVar27 < '\0')),CONCAT11(-(cVar27 < '\0'),cVar18)) >> 8);
                auVar35[7] = -(cVar26 < '\0');
                auVar35[6] = -(cVar26 < '\0');
                auVar35[5] = -(cVar25 < '\0');
                auVar35[4] = -(cVar25 < '\0');
                auVar35[3] = cVar1;
                auVar35[2] = cVar1;
                auVar35[1] = auVar35[0];
                auVar15 = pshuflw(auVar35,auVar35,0xd4);
                auVar36._12_4_ = auVar15._12_4_;
                auVar36._0_8_ = auVar15._0_8_;
                auVar36._8_4_ = auVar15._4_4_;
                auVar47[0] = -(cVar22 < (char)param_3[7]);
                cVar1 = -(cVar24 < (char)((ushort)param_3[7] >> 8));
                cVar18 = -(cVar30 < '\0');
                auVar47._8_8_ =
                     (undefined8)
                     (CONCAT72(CONCAT61(CONCAT51(CONCAT41(CONCAT31(CONCAT21(CONCAT11(cVar18,cVar18),
                                                                            -(cVar29 < '\0')),
                                                                   -(cVar29 < '\0')),
                                                          -(cVar28 < '\0')),-(cVar28 < '\0')),
                                        -(cVar27 < '\0')),CONCAT11(-(cVar27 < '\0'),cVar18)) >> 8);
                auVar47[7] = -(cVar26 < '\0');
                auVar47[6] = -(cVar26 < '\0');
                auVar47[5] = -(cVar25 < '\0');
                auVar47[4] = -(cVar25 < '\0');
                auVar47[3] = cVar1;
                auVar47[2] = cVar1;
                auVar47[1] = auVar47[0];
                auVar15 = pshuflw(auVar47,auVar47,0xd4);
                auVar48._12_4_ = auVar15._12_4_;
                auVar48._0_8_ = auVar15._0_8_;
                auVar48._8_4_ = auVar15._4_4_;
                auVar17._0_8_ =
                     auVar17._0_8_ + SUB168(auVar36 & ___xmm_00000000000000010000000000000001,0);
                auVar17._8_8_ =
                     auVar17._8_8_ + SUB168(auVar36 & ___xmm_00000000000000010000000000000001,8);
                auVar21._0_8_ =
                     auVar21._0_8_ + SUB168(auVar48 & ___xmm_00000000000000010000000000000001,0);
                auVar21._8_8_ =
                     auVar21._8_8_ + SUB168(auVar48 & ___xmm_00000000000000010000000000000001,8);
                if (uVar2 != 0x10) {
                  auVar37[0] = -(cVar22 < (char)param_3[8]);
                  cVar1 = -(cVar24 < (char)((ushort)param_3[8] >> 8));
                  cVar18 = -(cVar30 < '\0');
                  auVar37._8_8_ =
                       (undefined8)
                       (CONCAT72(CONCAT61(CONCAT51(CONCAT41(CONCAT31(CONCAT21(CONCAT11(cVar18,cVar18
                                                                                      ),
                                                                              -(cVar29 < '\0')),
                                                                     -(cVar29 < '\0')),
                                                            -(cVar28 < '\0')),-(cVar28 < '\0')),
                                          -(cVar27 < '\0')),CONCAT11(-(cVar27 < '\0'),cVar18)) >> 8)
                  ;
                  auVar37[7] = -(cVar26 < '\0');
                  auVar37[6] = -(cVar26 < '\0');
                  auVar37[5] = -(cVar25 < '\0');
                  auVar37[4] = -(cVar25 < '\0');
                  auVar37[3] = cVar1;
                  auVar37[2] = cVar1;
                  auVar37[1] = auVar37[0];
                  auVar15 = pshuflw(auVar37,auVar37,0xd4);
                  auVar38._12_4_ = auVar15._12_4_;
                  auVar38._0_8_ = auVar15._0_8_;
                  auVar38._8_4_ = auVar15._4_4_;
                  auVar49[0] = -(cVar22 < (char)param_3[9]);
                  cVar1 = -(cVar24 < (char)((ushort)param_3[9] >> 8));
                  cVar18 = -(cVar30 < '\0');
                  auVar49._8_8_ =
                       (undefined8)
                       (CONCAT72(CONCAT61(CONCAT51(CONCAT41(CONCAT31(CONCAT21(CONCAT11(cVar18,cVar18
                                                                                      ),
                                                                              -(cVar29 < '\0')),
                                                                     -(cVar29 < '\0')),
                                                            -(cVar28 < '\0')),-(cVar28 < '\0')),
                                          -(cVar27 < '\0')),CONCAT11(-(cVar27 < '\0'),cVar18)) >> 8)
                  ;
                  auVar49[7] = -(cVar26 < '\0');
                  auVar49[6] = -(cVar26 < '\0');
                  auVar49[5] = -(cVar25 < '\0');
                  auVar49[4] = -(cVar25 < '\0');
                  auVar49[3] = cVar1;
                  auVar49[2] = cVar1;
                  auVar49[1] = auVar49[0];
                  auVar15 = pshuflw(auVar49,auVar49,0xd4);
                  auVar50._12_4_ = auVar15._12_4_;
                  auVar50._0_8_ = auVar15._0_8_;
                  auVar50._8_4_ = auVar15._4_4_;
                  auVar17._0_8_ =
                       auVar17._0_8_ + SUB168(auVar38 & ___xmm_00000000000000010000000000000001,0);
                  auVar17._8_8_ =
                       auVar17._8_8_ + SUB168(auVar38 & ___xmm_00000000000000010000000000000001,8);
                  auVar21._0_8_ =
                       auVar21._0_8_ + SUB168(auVar50 & ___xmm_00000000000000010000000000000001,0);
                  auVar21._8_8_ =
                       auVar21._8_8_ + SUB168(auVar50 & ___xmm_00000000000000010000000000000001,8);
                  if (uVar2 != 0x14) {
                    auVar39[0] = -(cVar22 < (char)param_3[10]);
                    cVar1 = -(cVar24 < (char)((ushort)param_3[10] >> 8));
                    cVar18 = -(cVar30 < '\0');
                    auVar39._8_8_ =
                         (undefined8)
                         (CONCAT72(CONCAT61(CONCAT51(CONCAT41(CONCAT31(CONCAT21(CONCAT11(cVar18,
                                                  cVar18),-(cVar29 < '\0')),-(cVar29 < '\0')),
                                                  -(cVar28 < '\0')),-(cVar28 < '\0')),
                                            -(cVar27 < '\0')),CONCAT11(-(cVar27 < '\0'),cVar18)) >>
                         8);
                    auVar39[7] = -(cVar26 < '\0');
                    auVar39[6] = -(cVar26 < '\0');
                    auVar39[5] = -(cVar25 < '\0');
                    auVar39[4] = -(cVar25 < '\0');
                    auVar39[3] = cVar1;
                    auVar39[2] = cVar1;
                    auVar39[1] = auVar39[0];
                    auVar15 = pshuflw(auVar39,auVar39,0xd4);
                    auVar40._12_4_ = auVar15._12_4_;
                    auVar40._0_8_ = auVar15._0_8_;
                    auVar40._8_4_ = auVar15._4_4_;
                    auVar51[0] = -(cVar22 < (char)param_3[0xb]);
                    cVar1 = -(cVar24 < (char)((ushort)param_3[0xb] >> 8));
                    cVar18 = -(cVar30 < '\0');
                    auVar51._8_8_ =
                         (undefined8)
                         (CONCAT72(CONCAT61(CONCAT51(CONCAT41(CONCAT31(CONCAT21(CONCAT11(cVar18,
                                                  cVar18),-(cVar29 < '\0')),-(cVar29 < '\0')),
                                                  -(cVar28 < '\0')),-(cVar28 < '\0')),
                                            -(cVar27 < '\0')),CONCAT11(-(cVar27 < '\0'),cVar18)) >>
                         8);
                    auVar51[7] = -(cVar26 < '\0');
                    auVar51[6] = -(cVar26 < '\0');
                    auVar51[5] = -(cVar25 < '\0');
                    auVar51[4] = -(cVar25 < '\0');
                    auVar51[3] = cVar1;
                    auVar51[2] = cVar1;
                    auVar51[1] = auVar51[0];
                    auVar15 = pshuflw(auVar51,auVar51,0xd4);
                    auVar52._12_4_ = auVar15._12_4_;
                    auVar52._0_8_ = auVar15._0_8_;
                    auVar52._8_4_ = auVar15._4_4_;
                    auVar17._0_8_ =
                         auVar17._0_8_ + SUB168(auVar40 & ___xmm_00000000000000010000000000000001,0)
                    ;
                    auVar17._8_8_ =
                         auVar17._8_8_ + SUB168(auVar40 & ___xmm_00000000000000010000000000000001,8)
                    ;
                    auVar21._0_8_ =
                         auVar21._0_8_ + SUB168(auVar52 & ___xmm_00000000000000010000000000000001,0)
                    ;
                    auVar21._8_8_ =
                         auVar21._8_8_ + SUB168(auVar52 & ___xmm_00000000000000010000000000000001,8)
                    ;
                    if (uVar2 != 0x18) {
                      auVar41[0] = -(cVar22 < (char)param_3[0xc]);
                      cVar1 = -(cVar24 < (char)((ushort)param_3[0xc] >> 8));
                      cVar18 = -(cVar30 < '\0');
                      auVar41._8_8_ =
                           (undefined8)
                           (CONCAT72(CONCAT61(CONCAT51(CONCAT41(CONCAT31(CONCAT21(CONCAT11(cVar18,
                                                  cVar18),-(cVar29 < '\0')),-(cVar29 < '\0')),
                                                  -(cVar28 < '\0')),-(cVar28 < '\0')),
                                              -(cVar27 < '\0')),CONCAT11(-(cVar27 < '\0'),cVar18))
                           >> 8);
                      auVar41[7] = -(cVar26 < '\0');
                      auVar41[6] = -(cVar26 < '\0');
                      auVar41[5] = -(cVar25 < '\0');
                      auVar41[4] = -(cVar25 < '\0');
                      auVar41[3] = cVar1;
                      auVar41[2] = cVar1;
                      auVar41[1] = auVar41[0];
                      auVar15 = pshuflw(auVar41,auVar41,0xd4);
                      auVar42._12_4_ = auVar15._12_4_;
                      auVar42._0_8_ = auVar15._0_8_;
                      auVar42._8_4_ = auVar15._4_4_;
                      auVar53[0] = -(cVar22 < (char)param_3[0xd]);
                      cVar1 = -(cVar24 < (char)((ushort)param_3[0xd] >> 8));
                      cVar18 = -(cVar30 < '\0');
                      auVar53._8_8_ =
                           (undefined8)
                           (CONCAT72(CONCAT61(CONCAT51(CONCAT41(CONCAT31(CONCAT21(CONCAT11(cVar18,
                                                  cVar18),-(cVar29 < '\0')),-(cVar29 < '\0')),
                                                  -(cVar28 < '\0')),-(cVar28 < '\0')),
                                              -(cVar27 < '\0')),CONCAT11(-(cVar27 < '\0'),cVar18))
                           >> 8);
                      auVar53[7] = -(cVar26 < '\0');
                      auVar53[6] = -(cVar26 < '\0');
                      auVar53[5] = -(cVar25 < '\0');
                      auVar53[4] = -(cVar25 < '\0');
                      auVar53[3] = cVar1;
                      auVar53[2] = cVar1;
                      auVar53[1] = auVar53[0];
                      auVar15 = pshuflw(___xmm_0000000000000000000000000000bfbf,auVar53,0xd4);
                      auVar23._12_4_ = auVar15._12_4_;
                      auVar23._0_8_ = auVar15._0_8_;
                      auVar23._8_4_ = auVar15._4_4_;
                      auVar17._0_8_ =
                           auVar17._0_8_ +
                           SUB168(auVar42 & ___xmm_00000000000000010000000000000001,0);
                      auVar17._8_8_ =
                           auVar17._8_8_ +
                           SUB168(auVar42 & ___xmm_00000000000000010000000000000001,8);
                      auVar21._0_8_ =
                           auVar21._0_8_ +
                           SUB168(auVar23 & ___xmm_00000000000000010000000000000001,0);
                      auVar21._8_8_ =
                           auVar21._8_8_ +
                           SUB168(auVar23 & ___xmm_00000000000000010000000000000001,8);
                    }
                  }
                }
              }
            }
          }
          lVar3 = auVar17._8_8_ + auVar21._8_8_ + auVar17._0_8_ + auVar21._0_8_;
          goto LAB_140006ac6;
        }
        lVar3 = 0;
        uVar7 = 0;
        do {
          lVar3 = lVar3 + (ulonglong)(-0x41 < *(char *)((longlong)param_3 + uVar7));
          uVar7 = uVar7 + 1;
LAB_140006ac6:
        } while (param_4 != uVar7);
      }
    }
    else {
      lVar3 = _RNvNtNtCsloaxXL3qbEI_4core3str5count14do_count_chars((ulonglong)param_3,param_4);
    }
    uVar8 = uVar8 + lVar3;
    uVar11 = *(ushort *)((longlong)param_1 + 0x14);
    if (uVar11 <= uVar8) {
LAB_14000680e:
      uVar5 = core::fmt::impl$11::pad_integral::write_prefix
                        (*param_1,param_1[1],local_44,(longlong)param_3);
      uVar7 = CONCAT71((int7)((ulonglong)param_3 >> 8),1);
      if ((char)uVar5 == '\0') {
        uVar8 = __llvm_retpoline_r11();
        return uVar8;
      }
      goto LAB_140006c92;
    }
  }
  else {
    uVar12 = *(uint *)(param_1 + 2);
    local_44 = 0x2b;
    if ((uVar12 & 0x200000) == 0) {
      local_44 = 0x110000;
    }
    uVar8 = (ulonglong)((uVar12 & 0x200000) >> 0x15) + param_6;
    if ((uVar12 & 0x800000) != 0) goto LAB_1400067b8;
LAB_1400067fd:
    param_3 = (undefined2 *)0x0;
    uVar11 = *(ushort *)((longlong)param_1 + 0x14);
    if (uVar11 <= uVar8) goto LAB_14000680e;
  }
  uVar14 = (undefined7)((ulonglong)param_3 >> 8);
  if ((uVar12 & 0x1000000) == 0) {
    uVar6 = (uint)uVar11 - (int)uVar8;
    uVar2 = uVar12 >> 0x1d & 3;
    uVar12 = uVar6;
    if (uVar2 < 2) {
      if (uVar2 == 0) {
        uVar12 = 0;
      }
    }
    else if (uVar2 == 2) {
      uVar12 = uVar6 >> 1 & 0x7fff;
    }
    uVar5 = *param_1;
    uVar4 = param_1[1];
    uVar2 = uVar12 + 1;
    do {
      uVar9 = (short)uVar2 - 1;
      uVar2 = (uint)uVar9;
      if (uVar9 == 0) {
        uVar5 = core::fmt::impl$11::pad_integral::write_prefix
                          (uVar5,uVar4,local_44,(longlong)param_3);
        uVar7 = CONCAT71(uVar14,1);
        if (((char)uVar5 != '\0') || (cVar1 = __llvm_retpoline_r11(), cVar1 != '\0'))
        goto LAB_140006c92;
        iVar13 = uVar6 - uVar12;
        iVar10 = 0xffff;
        goto LAB_140006c60;
      }
      cVar1 = __llvm_retpoline_r11();
    } while (cVar1 == '\0');
    uVar7 = CONCAT71(uVar14,1);
  }
  else {
    uVar5 = param_1[2];
    *(uint *)(param_1 + 2) = (uint)uVar5 & 0x9fe00000 | 0x20000030;
    uVar4 = core::fmt::impl$11::pad_integral::write_prefix
                      (*param_1,param_1[1],local_44,(longlong)param_3);
    uVar7 = CONCAT71(uVar14,1);
    if ((char)uVar4 == '\0') {
      uVar12 = ((uint)uVar11 - (int)uVar8) + 1;
      do {
        uVar11 = (short)uVar12 - 1;
        uVar12 = (uint)uVar11;
        if (uVar11 == 0) {
          cVar1 = __llvm_retpoline_r11();
          if (cVar1 == '\0') {
            param_1[2] = uVar5;
            uVar7 = 0;
          }
          break;
        }
        cVar1 = __llvm_retpoline_r11();
      } while (cVar1 == '\0');
    }
  }
LAB_140006c92:
  return uVar7 & 0xffffffff;
  while( true ) {
    cVar1 = __llvm_retpoline_r11();
    iVar10 = iVar10 + 1;
    if (cVar1 != '\0') break;
LAB_140006c60:
    if ((ushort)((((short)uVar12 + (short)uVar8) - uVar11) + (short)iVar10) == -1) {
      iVar10 = iVar13;
      break;
    }
  }
  uVar7 = (ulonglong)CONCAT31((int3)((uint)iVar13 >> 8),(ushort)iVar10 < (ushort)iVar13);
  goto LAB_140006c92;
}



===== write_prefix @ 140006cb0 =====

undefined8
core::fmt::impl$11::pad_integral::write_prefix
          (undefined8 param_1,undefined8 param_2,int param_3,longlong param_4)

{
  undefined8 uVar1;
  
  if (param_3 != 0x110000) {
    uVar1 = __llvm_retpoline_r11();
    if ((char)uVar1 != '\0') {
      return CONCAT71((int7)((ulonglong)uVar1 >> 8),1);
    }
  }
  if (param_4 == 0) {
    return 0;
  }
  uVar1 = __llvm_retpoline_r11();
  return uVar1;
}



===== _RNvMs9_NtCsloaxXL3qbEI_4core3fmtNtB5_9Formatter3pad @ 140006d30 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool _RNvMs9_NtCsloaxXL3qbEI_4core3fmtNtB5_9Formatter3pad
               (longlong param_1,byte *param_2,ulonglong param_3)

{
  byte bVar1;
  ushort uVar2;
  undefined1 uVar3;
  char cVar4;
  uint uVar5;
  ulonglong uVar6;
  uint uVar7;
  ushort uVar8;
  byte *pbVar9;
  ushort uVar10;
  ushort uVar11;
  uint uVar12;
  ulonglong uVar13;
  char cVar17;
  undefined1 auVar14 [16];
  undefined1 auVar15 [16];
  undefined1 auVar16 [16];
  longlong lVar18;
  undefined1 auVar19 [16];
  undefined1 auVar20 [16];
  undefined1 auVar21 [16];
  char cVar22;
  char cVar24;
  char cVar25;
  char cVar26;
  char cVar27;
  char cVar28;
  char cVar29;
  char cVar30;
  undefined1 auVar23 [16];
  undefined1 auVar31 [16];
  undefined1 auVar32 [16];
  undefined1 auVar33 [16];
  undefined1 auVar34 [16];
  undefined1 auVar35 [16];
  undefined1 auVar36 [16];
  undefined1 auVar37 [16];
  undefined1 auVar38 [16];
  undefined1 auVar39 [16];
  undefined1 auVar40 [16];
  undefined1 auVar41 [16];
  undefined1 auVar42 [16];
  undefined1 auVar43 [16];
  undefined1 auVar44 [16];
  undefined1 auVar45 [16];
  undefined1 auVar46 [16];
  undefined1 auVar47 [16];
  undefined1 auVar48 [16];
  undefined1 auVar49 [16];
  undefined1 auVar50 [16];
  undefined1 auVar51 [16];
  undefined1 auVar52 [16];
  undefined1 auVar53 [16];
  
  uVar12 = *(uint *)(param_1 + 0x10);
  if ((uVar12 & 0x18000000) != 0) {
    if ((uVar12 & 0x10000000) == 0) {
      if (param_3 < 0x20) {
        if (param_3 == 0) {
          uVar13 = 0;
        }
        else {
          if (3 < param_3) {
            uVar5 = (uint)param_3 & 0x1c;
            uVar6 = (ulonglong)uVar5;
            cVar22 = __xmm_0000000000000000000000000000bfbf;
            auVar14[0] = -(cVar22 < (char)*(undefined2 *)param_2);
            cVar24 = __xmm_0000000000000000000000000000bfbf._1_1_;
            cVar4 = -(cVar24 < (char)((ushort)*(undefined2 *)param_2 >> 8));
            cVar25 = __xmm_0000000000000000000000000000bfbf._2_1_;
            cVar26 = __xmm_0000000000000000000000000000bfbf._3_1_;
            cVar27 = __xmm_0000000000000000000000000000bfbf._4_1_;
            cVar28 = __xmm_0000000000000000000000000000bfbf._5_1_;
            cVar29 = __xmm_0000000000000000000000000000bfbf._6_1_;
            cVar30 = __xmm_0000000000000000000000000000bfbf._7_1_;
            cVar17 = -(cVar30 < '\0');
            auVar14._8_8_ =
                 (undefined8)
                 (CONCAT72(CONCAT61(CONCAT51(CONCAT41(CONCAT31(CONCAT21(CONCAT11(cVar17,cVar17),
                                                                        -(cVar29 < '\0')),
                                                               -(cVar29 < '\0')),-(cVar28 < '\0')),
                                             -(cVar28 < '\0')),-(cVar27 < '\0')),
                           CONCAT11(-(cVar27 < '\0'),cVar17)) >> 8);
            auVar14[7] = -(cVar26 < '\0');
            auVar14[6] = -(cVar26 < '\0');
            auVar14[5] = -(cVar25 < '\0');
            auVar14[4] = -(cVar25 < '\0');
            auVar14[3] = cVar4;
            auVar14[2] = cVar4;
            auVar14[1] = auVar14[0];
            auVar14 = pshuflw(auVar14,auVar14,0xd4);
            auVar15._12_4_ = auVar14._12_4_;
            auVar15._0_8_ = auVar14._0_8_;
            auVar15._8_4_ = auVar14._4_4_;
            auVar16 = auVar15 & ___xmm_00000000000000010000000000000001;
            auVar19[0] = -(cVar22 < (char)*(undefined2 *)(param_2 + 2));
            cVar4 = -(cVar24 < (char)((ushort)*(undefined2 *)(param_2 + 2) >> 8));
            cVar17 = -(cVar30 < '\0');
            auVar19._8_8_ =
                 (undefined8)
                 (CONCAT72(CONCAT61(CONCAT51(CONCAT41(CONCAT31(CONCAT21(CONCAT11(cVar17,cVar17),
                                                                        -(cVar29 < '\0')),
                                                               -(cVar29 < '\0')),-(cVar28 < '\0')),
                                             -(cVar28 < '\0')),-(cVar27 < '\0')),
                           CONCAT11(-(cVar27 < '\0'),cVar17)) >> 8);
            auVar19[7] = -(cVar26 < '\0');
            auVar19[6] = -(cVar26 < '\0');
            auVar19[5] = -(cVar25 < '\0');
            auVar19[4] = -(cVar25 < '\0');
            auVar19[3] = cVar4;
            auVar19[2] = cVar4;
            auVar19[1] = auVar19[0];
            auVar14 = pshuflw(auVar19,auVar19,0xd4);
            auVar20._12_4_ = auVar14._12_4_;
            auVar20._0_8_ = auVar14._0_8_;
            auVar20._8_4_ = auVar14._4_4_;
            auVar21 = auVar20 & ___xmm_00000000000000010000000000000001;
            if (uVar6 != 4) {
              auVar31[0] = -(cVar22 < (char)*(undefined2 *)(param_2 + 4));
              cVar4 = -(cVar24 < (char)((ushort)*(undefined2 *)(param_2 + 4) >> 8));
              cVar17 = -(cVar30 < '\0');
              auVar31._8_8_ =
                   (undefined8)
                   (CONCAT72(CONCAT61(CONCAT51(CONCAT41(CONCAT31(CONCAT21(CONCAT11(cVar17,cVar17),
                                                                          -(cVar29 < '\0')),
                                                                 -(cVar29 < '\0')),-(cVar28 < '\0'))
                                               ,-(cVar28 < '\0')),-(cVar27 < '\0')),
                             CONCAT11(-(cVar27 < '\0'),cVar17)) >> 8);
              auVar31[7] = -(cVar26 < '\0');
              auVar31[6] = -(cVar26 < '\0');
              auVar31[5] = -(cVar25 < '\0');
              auVar31[4] = -(cVar25 < '\0');
              auVar31[3] = cVar4;
              auVar31[2] = cVar4;
              auVar31[1] = auVar31[0];
              auVar14 = pshuflw(auVar31,auVar31,0xd4);
              auVar32._12_4_ = auVar14._12_4_;
              auVar32._0_8_ = auVar14._0_8_;
              auVar32._8_4_ = auVar14._4_4_;
              auVar43[0] = -(cVar22 < (char)*(undefined2 *)(param_2 + 6));
              cVar4 = -(cVar24 < (char)((ushort)*(undefined2 *)(param_2 + 6) >> 8));
              cVar17 = -(cVar30 < '\0');
              auVar43._8_8_ =
                   (undefined8)
                   (CONCAT72(CONCAT61(CONCAT51(CONCAT41(CONCAT31(CONCAT21(CONCAT11(cVar17,cVar17),
                                                                          -(cVar29 < '\0')),
                                                                 -(cVar29 < '\0')),-(cVar28 < '\0'))
                                               ,-(cVar28 < '\0')),-(cVar27 < '\0')),
                             CONCAT11(-(cVar27 < '\0'),cVar17)) >> 8);
              auVar43[7] = -(cVar26 < '\0');
              auVar43[6] = -(cVar26 < '\0');
              auVar43[5] = -(cVar25 < '\0');
              auVar43[4] = -(cVar25 < '\0');
              auVar43[3] = cVar4;
              auVar43[2] = cVar4;
              auVar43[1] = auVar43[0];
              auVar14 = pshuflw(auVar43,auVar43,0xd4);
              auVar44._12_4_ = auVar14._12_4_;
              auVar44._0_8_ = auVar14._0_8_;
              auVar44._8_4_ = auVar14._4_4_;
              lVar18 = auVar16._8_8_;
              auVar16._0_8_ =
                   auVar16._0_8_ + SUB168(auVar32 & ___xmm_00000000000000010000000000000001,0);
              auVar16._8_8_ = lVar18 + SUB168(auVar32 & ___xmm_00000000000000010000000000000001,8);
              lVar18 = auVar21._8_8_;
              auVar21._0_8_ =
                   auVar21._0_8_ + SUB168(auVar44 & ___xmm_00000000000000010000000000000001,0);
              auVar21._8_8_ = lVar18 + SUB168(auVar44 & ___xmm_00000000000000010000000000000001,8);
              if (uVar5 != 8) {
                auVar33[0] = -(cVar22 < (char)*(undefined2 *)(param_2 + 8));
                cVar4 = -(cVar24 < (char)((ushort)*(undefined2 *)(param_2 + 8) >> 8));
                cVar17 = -(cVar30 < '\0');
                auVar33._8_8_ =
                     (undefined8)
                     (CONCAT72(CONCAT61(CONCAT51(CONCAT41(CONCAT31(CONCAT21(CONCAT11(cVar17,cVar17),
                                                                            -(cVar29 < '\0')),
                                                                   -(cVar29 < '\0')),
                                                          -(cVar28 < '\0')),-(cVar28 < '\0')),
                                        -(cVar27 < '\0')),CONCAT11(-(cVar27 < '\0'),cVar17)) >> 8);
                auVar33[7] = -(cVar26 < '\0');
                auVar33[6] = -(cVar26 < '\0');
                auVar33[5] = -(cVar25 < '\0');
                auVar33[4] = -(cVar25 < '\0');
                auVar33[3] = cVar4;
                auVar33[2] = cVar4;
                auVar33[1] = auVar33[0];
                auVar14 = pshuflw(auVar33,auVar33,0xd4);
                auVar34._12_4_ = auVar14._12_4_;
                auVar34._0_8_ = auVar14._0_8_;
                auVar34._8_4_ = auVar14._4_4_;
                auVar45[0] = -(cVar22 < (char)*(undefined2 *)(param_2 + 10));
                cVar4 = -(cVar24 < (char)((ushort)*(undefined2 *)(param_2 + 10) >> 8));
                cVar17 = -(cVar30 < '\0');
                auVar45._8_8_ =
                     (undefined8)
                     (CONCAT72(CONCAT61(CONCAT51(CONCAT41(CONCAT31(CONCAT21(CONCAT11(cVar17,cVar17),
                                                                            -(cVar29 < '\0')),
                                                                   -(cVar29 < '\0')),
                                                          -(cVar28 < '\0')),-(cVar28 < '\0')),
                                        -(cVar27 < '\0')),CONCAT11(-(cVar27 < '\0'),cVar17)) >> 8);
                auVar45[7] = -(cVar26 < '\0');
                auVar45[6] = -(cVar26 < '\0');
                auVar45[5] = -(cVar25 < '\0');
                auVar45[4] = -(cVar25 < '\0');
                auVar45[3] = cVar4;
                auVar45[2] = cVar4;
                auVar45[1] = auVar45[0];
                auVar14 = pshuflw(auVar45,auVar45,0xd4);
                auVar46._12_4_ = auVar14._12_4_;
                auVar46._0_8_ = auVar14._0_8_;
                auVar46._8_4_ = auVar14._4_4_;
                auVar16._0_8_ =
                     auVar16._0_8_ + SUB168(auVar34 & ___xmm_00000000000000010000000000000001,0);
                auVar16._8_8_ =
                     auVar16._8_8_ + SUB168(auVar34 & ___xmm_00000000000000010000000000000001,8);
                auVar21._0_8_ =
                     auVar21._0_8_ + SUB168(auVar46 & ___xmm_00000000000000010000000000000001,0);
                auVar21._8_8_ =
                     auVar21._8_8_ + SUB168(auVar46 & ___xmm_00000000000000010000000000000001,8);
                if (uVar5 != 0xc) {
                  auVar35[0] = -(cVar22 < (char)*(undefined2 *)(param_2 + 0xc));
                  cVar4 = -(cVar24 < (char)((ushort)*(undefined2 *)(param_2 + 0xc) >> 8));
                  cVar17 = -(cVar30 < '\0');
                  auVar35._8_8_ =
                       (undefined8)
                       (CONCAT72(CONCAT61(CONCAT51(CONCAT41(CONCAT31(CONCAT21(CONCAT11(cVar17,cVar17
                                                                                      ),
                                                                              -(cVar29 < '\0')),
                                                                     -(cVar29 < '\0')),
                                                            -(cVar28 < '\0')),-(cVar28 < '\0')),
                                          -(cVar27 < '\0')),CONCAT11(-(cVar27 < '\0'),cVar17)) >> 8)
                  ;
                  auVar35[7] = -(cVar26 < '\0');
                  auVar35[6] = -(cVar26 < '\0');
                  auVar35[5] = -(cVar25 < '\0');
                  auVar35[4] = -(cVar25 < '\0');
                  auVar35[3] = cVar4;
                  auVar35[2] = cVar4;
                  auVar35[1] = auVar35[0];
                  auVar14 = pshuflw(auVar35,auVar35,0xd4);
                  auVar36._12_4_ = auVar14._12_4_;
                  auVar36._0_8_ = auVar14._0_8_;
                  auVar36._8_4_ = auVar14._4_4_;
                  auVar47[0] = -(cVar22 < (char)*(undefined2 *)(param_2 + 0xe));
                  cVar4 = -(cVar24 < (char)((ushort)*(undefined2 *)(param_2 + 0xe) >> 8));
                  cVar17 = -(cVar30 < '\0');
                  auVar47._8_8_ =
                       (undefined8)
                       (CONCAT72(CONCAT61(CONCAT51(CONCAT41(CONCAT31(CONCAT21(CONCAT11(cVar17,cVar17
                                                                                      ),
                                                                              -(cVar29 < '\0')),
                                                                     -(cVar29 < '\0')),
                                                            -(cVar28 < '\0')),-(cVar28 < '\0')),
                                          -(cVar27 < '\0')),CONCAT11(-(cVar27 < '\0'),cVar17)) >> 8)
                  ;
                  auVar47[7] = -(cVar26 < '\0');
                  auVar47[6] = -(cVar26 < '\0');
                  auVar47[5] = -(cVar25 < '\0');
                  auVar47[4] = -(cVar25 < '\0');
                  auVar47[3] = cVar4;
                  auVar47[2] = cVar4;
                  auVar47[1] = auVar47[0];
                  auVar14 = pshuflw(auVar47,auVar47,0xd4);
                  auVar48._12_4_ = auVar14._12_4_;
                  auVar48._0_8_ = auVar14._0_8_;
                  auVar48._8_4_ = auVar14._4_4_;
                  auVar16._0_8_ =
                       auVar16._0_8_ + SUB168(auVar36 & ___xmm_00000000000000010000000000000001,0);
                  auVar16._8_8_ =
                       auVar16._8_8_ + SUB168(auVar36 & ___xmm_00000000000000010000000000000001,8);
                  auVar21._0_8_ =
                       auVar21._0_8_ + SUB168(auVar48 & ___xmm_00000000000000010000000000000001,0);
                  auVar21._8_8_ =
                       auVar21._8_8_ + SUB168(auVar48 & ___xmm_00000000000000010000000000000001,8);
                  if (uVar5 != 0x10) {
                    auVar37[0] = -(cVar22 < (char)*(undefined2 *)(param_2 + 0x10));
                    cVar4 = -(cVar24 < (char)((ushort)*(undefined2 *)(param_2 + 0x10) >> 8));
                    cVar17 = -(cVar30 < '\0');
                    auVar37._8_8_ =
                         (undefined8)
                         (CONCAT72(CONCAT61(CONCAT51(CONCAT41(CONCAT31(CONCAT21(CONCAT11(cVar17,
                                                  cVar17),-(cVar29 < '\0')),-(cVar29 < '\0')),
                                                  -(cVar28 < '\0')),-(cVar28 < '\0')),
                                            -(cVar27 < '\0')),CONCAT11(-(cVar27 < '\0'),cVar17)) >>
                         8);
                    auVar37[7] = -(cVar26 < '\0');
                    auVar37[6] = -(cVar26 < '\0');
                    auVar37[5] = -(cVar25 < '\0');
                    auVar37[4] = -(cVar25 < '\0');
                    auVar37[3] = cVar4;
                    auVar37[2] = cVar4;
                    auVar37[1] = auVar37[0];
                    auVar14 = pshuflw(auVar37,auVar37,0xd4);
                    auVar38._12_4_ = auVar14._12_4_;
                    auVar38._0_8_ = auVar14._0_8_;
                    auVar38._8_4_ = auVar14._4_4_;
                    auVar49[0] = -(cVar22 < (char)*(undefined2 *)(param_2 + 0x12));
                    cVar4 = -(cVar24 < (char)((ushort)*(undefined2 *)(param_2 + 0x12) >> 8));
                    cVar17 = -(cVar30 < '\0');
                    auVar49._8_8_ =
                         (undefined8)
                         (CONCAT72(CONCAT61(CONCAT51(CONCAT41(CONCAT31(CONCAT21(CONCAT11(cVar17,
                                                  cVar17),-(cVar29 < '\0')),-(cVar29 < '\0')),
                                                  -(cVar28 < '\0')),-(cVar28 < '\0')),
                                            -(cVar27 < '\0')),CONCAT11(-(cVar27 < '\0'),cVar17)) >>
                         8);
                    auVar49[7] = -(cVar26 < '\0');
                    auVar49[6] = -(cVar26 < '\0');
                    auVar49[5] = -(cVar25 < '\0');
                    auVar49[4] = -(cVar25 < '\0');
                    auVar49[3] = cVar4;
                    auVar49[2] = cVar4;
                    auVar49[1] = auVar49[0];
                    auVar14 = pshuflw(auVar49,auVar49,0xd4);
                    auVar50._12_4_ = auVar14._12_4_;
                    auVar50._0_8_ = auVar14._0_8_;
                    auVar50._8_4_ = auVar14._4_4_;
                    auVar16._0_8_ =
                         auVar16._0_8_ + SUB168(auVar38 & ___xmm_00000000000000010000000000000001,0)
                    ;
                    auVar16._8_8_ =
                         auVar16._8_8_ + SUB168(auVar38 & ___xmm_00000000000000010000000000000001,8)
                    ;
                    auVar21._0_8_ =
                         auVar21._0_8_ + SUB168(auVar50 & ___xmm_00000000000000010000000000000001,0)
                    ;
                    auVar21._8_8_ =
                         auVar21._8_8_ + SUB168(auVar50 & ___xmm_00000000000000010000000000000001,8)
                    ;
                    if (uVar5 != 0x14) {
                      auVar39[0] = -(cVar22 < (char)*(undefined2 *)(param_2 + 0x14));
                      cVar4 = -(cVar24 < (char)((ushort)*(undefined2 *)(param_2 + 0x14) >> 8));
                      cVar17 = -(cVar30 < '\0');
                      auVar39._8_8_ =
                           (undefined8)
                           (CONCAT72(CONCAT61(CONCAT51(CONCAT41(CONCAT31(CONCAT21(CONCAT11(cVar17,
                                                  cVar17),-(cVar29 < '\0')),-(cVar29 < '\0')),
                                                  -(cVar28 < '\0')),-(cVar28 < '\0')),
                                              -(cVar27 < '\0')),CONCAT11(-(cVar27 < '\0'),cVar17))
                           >> 8);
                      auVar39[7] = -(cVar26 < '\0');
                      auVar39[6] = -(cVar26 < '\0');
                      auVar39[5] = -(cVar25 < '\0');
                      auVar39[4] = -(cVar25 < '\0');
                      auVar39[3] = cVar4;
                      auVar39[2] = cVar4;
                      auVar39[1] = auVar39[0];
                      auVar14 = pshuflw(auVar39,auVar39,0xd4);
                      auVar40._12_4_ = auVar14._12_4_;
                      auVar40._0_8_ = auVar14._0_8_;
                      auVar40._8_4_ = auVar14._4_4_;
                      auVar51[0] = -(cVar22 < (char)*(undefined2 *)(param_2 + 0x16));
                      cVar4 = -(cVar24 < (char)((ushort)*(undefined2 *)(param_2 + 0x16) >> 8));
                      cVar17 = -(cVar30 < '\0');
                      auVar51._8_8_ =
                           (undefined8)
                           (CONCAT72(CONCAT61(CONCAT51(CONCAT41(CONCAT31(CONCAT21(CONCAT11(cVar17,
                                                  cVar17),-(cVar29 < '\0')),-(cVar29 < '\0')),
                                                  -(cVar28 < '\0')),-(cVar28 < '\0')),
                                              -(cVar27 < '\0')),CONCAT11(-(cVar27 < '\0'),cVar17))
                           >> 8);
                      auVar51[7] = -(cVar26 < '\0');
                      auVar51[6] = -(cVar26 < '\0');
                      auVar51[5] = -(cVar25 < '\0');
                      auVar51[4] = -(cVar25 < '\0');
                      auVar51[3] = cVar4;
                      auVar51[2] = cVar4;
                      auVar51[1] = auVar51[0];
                      auVar14 = pshuflw(auVar51,auVar51,0xd4);
                      auVar52._12_4_ = auVar14._12_4_;
                      auVar52._0_8_ = auVar14._0_8_;
                      auVar52._8_4_ = auVar14._4_4_;
                      auVar16._0_8_ =
                           auVar16._0_8_ +
                           SUB168(auVar40 & ___xmm_00000000000000010000000000000001,0);
                      auVar16._8_8_ =
                           auVar16._8_8_ +
                           SUB168(auVar40 & ___xmm_00000000000000010000000000000001,8);
                      auVar21._0_8_ =
                           auVar21._0_8_ +
                           SUB168(auVar52 & ___xmm_00000000000000010000000000000001,0);
                      auVar21._8_8_ =
                           auVar21._8_8_ +
                           SUB168(auVar52 & ___xmm_00000000000000010000000000000001,8);
                      if (uVar5 != 0x18) {
                        auVar41[0] = -(cVar22 < (char)*(undefined2 *)(param_2 + 0x18));
                        cVar4 = -(cVar24 < (char)((ushort)*(undefined2 *)(param_2 + 0x18) >> 8));
                        cVar17 = -(cVar30 < '\0');
                        auVar41._8_8_ =
                             (undefined8)
                             (CONCAT72(CONCAT61(CONCAT51(CONCAT41(CONCAT31(CONCAT21(CONCAT11(cVar17,
                                                  cVar17),-(cVar29 < '\0')),-(cVar29 < '\0')),
                                                  -(cVar28 < '\0')),-(cVar28 < '\0')),
                                                -(cVar27 < '\0')),CONCAT11(-(cVar27 < '\0'),cVar17))
                             >> 8);
                        auVar41[7] = -(cVar26 < '\0');
                        auVar41[6] = -(cVar26 < '\0');
                        auVar41[5] = -(cVar25 < '\0');
                        auVar41[4] = -(cVar25 < '\0');
                        auVar41[3] = cVar4;
                        auVar41[2] = cVar4;
                        auVar41[1] = auVar41[0];
                        auVar14 = pshuflw(auVar41,auVar41,0xd4);
                        auVar42._12_4_ = auVar14._12_4_;
                        auVar42._0_8_ = auVar14._0_8_;
                        auVar42._8_4_ = auVar14._4_4_;
                        auVar53[0] = -(cVar22 < (char)*(undefined2 *)(param_2 + 0x1a));
                        cVar4 = -(cVar24 < (char)((ushort)*(undefined2 *)(param_2 + 0x1a) >> 8));
                        cVar17 = -(cVar30 < '\0');
                        auVar53._8_8_ =
                             (undefined8)
                             (CONCAT72(CONCAT61(CONCAT51(CONCAT41(CONCAT31(CONCAT21(CONCAT11(cVar17,
                                                  cVar17),-(cVar29 < '\0')),-(cVar29 < '\0')),
                                                  -(cVar28 < '\0')),-(cVar28 < '\0')),
                                                -(cVar27 < '\0')),CONCAT11(-(cVar27 < '\0'),cVar17))
                             >> 8);
                        auVar53[7] = -(cVar26 < '\0');
                        auVar53[6] = -(cVar26 < '\0');
                        auVar53[5] = -(cVar25 < '\0');
                        auVar53[4] = -(cVar25 < '\0');
                        auVar53[3] = cVar4;
                        auVar53[2] = cVar4;
                        auVar53[1] = auVar53[0];
                        auVar14 = pshuflw(___xmm_0000000000000000000000000000bfbf,auVar53,0xd4);
                        auVar23._12_4_ = auVar14._12_4_;
                        auVar23._0_8_ = auVar14._0_8_;
                        auVar23._8_4_ = auVar14._4_4_;
                        auVar16._0_8_ =
                             auVar16._0_8_ +
                             SUB168(auVar42 & ___xmm_00000000000000010000000000000001,0);
                        auVar16._8_8_ =
                             auVar16._8_8_ +
                             SUB168(auVar42 & ___xmm_00000000000000010000000000000001,8);
                        auVar21._0_8_ =
                             auVar21._0_8_ +
                             SUB168(auVar23 & ___xmm_00000000000000010000000000000001,0);
                        auVar21._8_8_ =
                             auVar21._8_8_ +
                             SUB168(auVar23 & ___xmm_00000000000000010000000000000001,8);
                      }
                    }
                  }
                }
              }
            }
            uVar13 = auVar16._8_8_ + auVar21._8_8_ + auVar16._0_8_ + auVar21._0_8_;
            goto LAB_140007057;
          }
          uVar13 = 0;
          uVar6 = 0;
          do {
            uVar13 = uVar13 + (-0x41 < (char)param_2[uVar6]);
            uVar6 = uVar6 + 1;
LAB_140007057:
          } while (param_3 != uVar6);
        }
      }
      else {
        uVar13 = _RNvNtNtCsloaxXL3qbEI_4core3str5count14do_count_chars((ulonglong)param_2,param_3);
      }
    }
    else {
      uVar13 = (ulonglong)*(ushort *)(param_1 + 0x16);
      if (uVar13 != 0) {
        pbVar9 = param_2 + param_3;
        uVar6 = uVar13;
        do {
          if (param_2 == pbVar9) goto LAB_140006e07;
          bVar1 = *param_2;
          if ((char)bVar1 < '\0') {
            if (bVar1 < 0xe0) {
              param_2 = param_2 + 2;
            }
            else if (bVar1 < 0xf0) {
              param_2 = param_2 + 3;
            }
            else {
              param_2 = param_2 + 4;
            }
          }
          else {
            param_2 = param_2 + 1;
          }
          uVar6 = uVar6 - 1;
        } while (uVar6 != 0);
      }
      uVar6 = 0;
LAB_140006e07:
      uVar13 = uVar13 - uVar6;
    }
    uVar2 = *(ushort *)(param_1 + 0x14);
    if (uVar13 < uVar2) {
      uVar7 = (uint)uVar2 - (int)uVar13;
      uVar5 = uVar12 >> 0x1d & 3;
      uVar12 = 0;
      if (uVar5 < 2) {
        if (uVar5 != 0) {
          uVar12 = uVar7;
        }
      }
      else if (uVar5 == 2) {
        uVar12 = (uVar7 & 0xffff) >> 1;
      }
      uVar5 = uVar12 + 1;
      while (uVar10 = (short)uVar5 - 1, uVar5 = (uint)uVar10, uVar10 != 0) {
        cVar4 = __llvm_retpoline_r11();
        if (cVar4 != '\0') {
          return true;
        }
      }
      cVar4 = __llvm_retpoline_r11();
      if (cVar4 != '\0') {
        return true;
      }
      uVar11 = (short)uVar7 - (short)uVar12;
      uVar10 = 0xffff;
      do {
        uVar8 = uVar11;
        if ((ushort)(uVar10 + (((short)uVar12 + (short)uVar13) - uVar2)) == -1) break;
        cVar4 = __llvm_retpoline_r11();
        uVar8 = uVar10 + 1;
        uVar10 = uVar8;
      } while (cVar4 == '\0');
                    /* WARNING: Read-only address (ram,0x00014001a6f0) is written */
                    /* WARNING: Read-only address (ram,0x00014001a700) is written */
      return uVar8 < uVar11;
    }
  }
  uVar3 = __llvm_retpoline_r11();
  return (bool)uVar3;
}



===== _RNvXsa_NtCsloaxXL3qbEI_4core3fmtNtB5_9FormatterNtB5_5Write9write_str @ 1400071a0 =====

void _RNvXsa_NtCsloaxXL3qbEI_4core3fmtNtB5_9FormatterNtB5_5Write9write_str(void)

{
  __llvm_retpoline_r11();
  return;
}



===== _RNvMs9_NtCsloaxXL3qbEI_4core3fmtNtB5_9Formatter26debug_struct_field1_finish @ 1400071c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong _RNvMs9_NtCsloaxXL3qbEI_4core3fmtNtB5_9Formatter26debug_struct_field1_finish
                    (longlong param_1,undefined8 param_2,undefined8 param_3,longlong param_4,
                    ulonglong param_5)

{
  code *pcVar1;
  ulonglong uVar2;
  longlong local_48;
  byte local_40;
  byte local_3f;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)&local_38;
  local_40 = __llvm_retpoline_r11();
  local_3f = 0;
  local_48 = param_1;
  _RNvMs1_NtNtCsloaxXL3qbEI_4core3fmt8buildersNtB5_11DebugStruct5field(&local_48,param_4,param_5);
  if (((~local_3f | local_40) & 1) == 0) {
    uVar2 = __llvm_retpoline_r11();
  }
  else {
    uVar2 = (ulonglong)(local_3f | local_40);
  }
  if ((local_38 ^ (ulonglong)&local_38) == __security_cookie) {
    return uVar2 & 0xffffffffffffff01;
  }
  pcVar1 = (code *)swi(3);
  uVar2 = (*pcVar1)();
  return uVar2;
}



===== _RNvMs9_NtCsloaxXL3qbEI_4core3fmtNtB5_9Formatter26debug_struct_field2_finish @ 1400072c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong _RNvMs9_NtCsloaxXL3qbEI_4core3fmtNtB5_9Formatter26debug_struct_field2_finish
                    (longlong param_1,undefined8 param_2,undefined8 param_3,longlong param_4,
                    ulonglong param_5,undefined8 param_6,undefined8 param_7,longlong param_8,
                    ulonglong param_9)

{
  code *pcVar1;
  ulonglong uVar2;
  longlong local_58;
  byte local_50;
  byte local_4f;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)&local_48;
  local_50 = __llvm_retpoline_r11();
  local_4f = 0;
  local_58 = param_1;
  _RNvMs1_NtNtCsloaxXL3qbEI_4core3fmt8buildersNtB5_11DebugStruct5field(&local_58,param_4,param_5);
  _RNvMs1_NtNtCsloaxXL3qbEI_4core3fmt8buildersNtB5_11DebugStruct5field(&local_58,param_8,param_9);
  if (((~local_4f | local_50) & 1) == 0) {
    uVar2 = __llvm_retpoline_r11();
  }
  else {
    uVar2 = (ulonglong)(local_4f | local_50);
  }
  if ((local_48 ^ (ulonglong)&local_48) == __security_cookie) {
    return uVar2 & 0xffffffffffffff01;
  }
  pcVar1 = (code *)swi(3);
  uVar2 = (*pcVar1)();
  return uVar2;
}



===== _RNvMs9_NtCsloaxXL3qbEI_4core3fmtNtB5_9Formatter25debug_tuple_field1_finish @ 140007400 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong _RNvMs9_NtCsloaxXL3qbEI_4core3fmtNtB5_9Formatter25debug_tuple_field1_finish
                    (undefined8 *param_1,undefined8 param_2,longlong param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  code *pcVar3;
  char cVar4;
  uint uVar5;
  ulonglong uVar6;
  undefined8 unaff_RBX;
  undefined1 local_79;
  undefined8 local_78;
  undefined8 local_70;
  undefined1 *local_68;
  undefined8 *local_60;
  undefined *local_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)&local_48;
  uVar1 = *param_1;
  uVar2 = param_1[1];
  cVar4 = __llvm_retpoline_r11();
  uVar6 = CONCAT71((int7)((ulonglong)unaff_RBX >> 8),1);
  if (cVar4 != '\0') goto LAB_14000744f;
  if ((*(byte *)((longlong)param_1 + 0x12) & 0x80) == 0) {
    cVar4 = __llvm_retpoline_r11();
    if (cVar4 != '\0') goto LAB_14000744f;
    cVar4 = __llvm_retpoline_r11();
  }
  else {
    cVar4 = __llvm_retpoline_r11();
    if (cVar4 != '\0') goto LAB_14000744f;
    local_79 = 1;
    local_68 = &local_79;
    local_50 = param_1[2];
    local_60 = &local_78;
    local_58 = &DAT_140019298;
    local_78 = uVar1;
    local_70 = uVar2;
    cVar4 = __llvm_retpoline_r11();
    if (cVar4 != '\0') goto LAB_14000744f;
    cVar4 = __llvm_retpoline_r11();
  }
  if ((cVar4 == '\0') &&
     (((param_3 != 0 || ((*(byte *)((longlong)param_1 + 0x12) & 0x80) != 0)) ||
      (cVar4 = __llvm_retpoline_r11(), cVar4 == '\0')))) {
    uVar5 = __llvm_retpoline_r11();
    uVar6 = (ulonglong)uVar5;
  }
LAB_14000744f:
  if ((local_48 ^ (ulonglong)&local_48) == __security_cookie) {
    return uVar6 & 0xffffffff;
  }
  pcVar3 = (code *)swi(3);
  uVar6 = (*pcVar3)();
  return uVar6;
}



===== _RNvNtNtCsloaxXL3qbEI_4core3str5count14do_count_chars @ 1400075e0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong _RNvNtNtCsloaxXL3qbEI_4core3str5count14do_count_chars(ulonglong param_1,ulonglong param_2)

{
  undefined2 uVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  uint uVar8;
  longlong lVar9;
  undefined1 (*pauVar10) [16];
  undefined1 (*pauVar11) [16];
  undefined1 (*pauVar12) [16];
  ulonglong uVar13;
  ulonglong uVar14;
  ulonglong uVar15;
  ulonglong uVar16;
  ulonglong uVar17;
  ulonglong uVar18;
  longlong lVar20;
  undefined1 auVar19 [16];
  longlong lVar21;
  longlong lVar22;
  undefined1 auVar23 [16];
  undefined1 auVar24 [16];
  undefined1 auVar25 [16];
  undefined1 auVar26 [16];
  undefined1 auVar27 [16];
  undefined1 auVar28 [16];
  undefined1 auVar29 [16];
  undefined1 auVar30 [16];
  undefined1 auVar31 [16];
  char cVar42;
  undefined1 auVar32 [16];
  undefined1 auVar33 [16];
  undefined1 auVar34 [16];
  undefined1 auVar35 [16];
  undefined1 auVar36 [16];
  undefined1 auVar37 [16];
  undefined1 auVar38 [16];
  undefined1 auVar39 [16];
  undefined1 auVar40 [16];
  undefined1 auVar41 [16];
  undefined1 auVar43 [16];
  undefined1 auVar44 [16];
  undefined1 auVar45 [16];
  undefined1 auVar46 [16];
  undefined1 auVar47 [16];
  undefined1 auVar48 [16];
  undefined1 auVar49 [16];
  undefined1 auVar50 [16];
  longlong lVar51;
  undefined1 auVar52 [16];
  undefined1 auVar53 [16];
  undefined1 auVar54 [16];
  undefined1 auVar55 [16];
  undefined1 auVar56 [16];
  undefined1 auVar57 [16];
  undefined1 auVar58 [16];
  undefined1 auVar59 [16];
  undefined1 auVar60 [16];
  undefined1 auVar61 [16];
  undefined1 auVar62 [16];
  undefined1 auVar63 [16];
  undefined1 auVar64 [16];
  undefined1 auVar65 [16];
  undefined1 auVar66 [16];
  
  uVar15 = param_1 + 7 & 0xfffffffffffffff8;
  uVar14 = uVar15 - param_1;
  uVar13 = param_2 - uVar14;
  if ((param_2 < uVar14) || (uVar13 < 8)) {
    if (param_2 == 0) {
      lVar9 = 0;
    }
    else {
      if (3 < param_2) {
        uVar14 = param_2 & 0xfffffffffffffffc;
        lVar9 = 0;
        lVar20 = 0;
        uVar13 = 0;
        lVar21 = 0;
        lVar22 = 0;
        do {
          uVar1 = *(undefined2 *)(param_1 + 2 + uVar13);
          auVar61[0] = -(-0x41 < (char)*(undefined2 *)(param_1 + uVar13));
          cVar42 = -(-0x41 < (char)((ushort)*(undefined2 *)(param_1 + uVar13) >> 8));
          auVar40._9_7_ = 0;
          auVar40._0_9_ = SUB169(ZEXT816(0),7);
          auVar31._10_6_ = 0;
          auVar31._0_10_ = SUB1610(auVar40 << 0x38,6);
          auVar32._11_5_ = 0;
          auVar32._0_11_ = SUB1611(auVar31 << 0x30,5);
          auVar61._4_12_ = SUB1612(auVar32 << 0x28,4);
          auVar61[3] = cVar42;
          auVar61[2] = cVar42;
          auVar61[1] = auVar61[0];
          auVar32 = pshuflw(auVar61,auVar61,0xd4);
          auVar33._12_4_ = auVar32._12_4_;
          auVar33._0_8_ = auVar32._0_8_;
          auVar33._8_4_ = auVar32._4_4_;
          auVar33 = auVar33 & ___xmm_00000000000000010000000000000001;
          lVar9 = lVar9 + auVar33._0_8_;
          lVar20 = lVar20 + auVar33._8_8_;
          auVar43[0] = -(-0x41 < (char)uVar1);
          cVar42 = -(-0x41 < (char)((ushort)uVar1 >> 8));
          auVar58._9_7_ = 0;
          auVar58._0_9_ = SUB169(ZEXT816(0),7);
          auVar55._10_6_ = 0;
          auVar55._0_10_ = SUB1610(auVar58 << 0x38,6);
          auVar47._11_5_ = 0;
          auVar47._0_11_ = SUB1611(auVar55 << 0x30,5);
          auVar43._4_12_ = SUB1612(auVar47 << 0x28,4);
          auVar43[3] = cVar42;
          auVar43[2] = cVar42;
          auVar43[1] = auVar43[0];
          auVar32 = pshuflw(auVar33,auVar43,0xd4);
          auVar34._12_4_ = auVar32._12_4_;
          auVar34._0_8_ = auVar32._0_8_;
          auVar34._8_4_ = auVar32._4_4_;
          lVar21 = lVar21 + SUB168(auVar34 & ___xmm_00000000000000010000000000000001,0);
          lVar22 = lVar22 + SUB168(auVar34 & ___xmm_00000000000000010000000000000001,8);
          uVar13 = uVar13 + 4;
        } while (uVar14 != uVar13);
        lVar9 = lVar22 + lVar20 + lVar21 + lVar9;
        goto LAB_140007bbb;
      }
      lVar9 = 0;
      uVar14 = 0;
      do {
        lVar9 = lVar9 + (ulonglong)(-0x41 < *(char *)(param_1 + uVar14));
        uVar14 = uVar14 + 1;
LAB_140007bbb:
      } while (param_2 != uVar14);
    }
  }
  else {
    uVar8 = (uint)uVar13 & 7;
    if (uVar15 == param_1) {
      lVar9 = 0;
    }
    else {
      if (3 < uVar14) {
        uVar16 = (ulonglong)((uint)uVar14 & 4);
        lVar9 = 0;
        lVar20 = 0;
        uVar15 = 0;
        lVar21 = 0;
        lVar22 = 0;
        do {
          uVar1 = *(undefined2 *)(param_1 + 2 + uVar15);
          auVar35[0] = -(-0x41 < (char)*(undefined2 *)(param_1 + uVar15));
          cVar42 = -(-0x41 < (char)((ushort)*(undefined2 *)(param_1 + uVar15) >> 8));
          auVar4._9_7_ = 0;
          auVar4._0_9_ = SUB169(ZEXT816(0),7);
          auVar3._10_6_ = 0;
          auVar3._0_10_ = SUB1610(auVar4 << 0x38,6);
          auVar2._11_5_ = 0;
          auVar2._0_11_ = SUB1611(auVar3 << 0x30,5);
          auVar35._4_12_ = SUB1612(auVar2 << 0x28,4);
          auVar35[3] = cVar42;
          auVar35[2] = cVar42;
          auVar35[1] = auVar35[0];
          auVar32 = pshuflw(auVar35,auVar35,0xd4);
          auVar36._12_4_ = auVar32._12_4_;
          auVar36._0_8_ = auVar32._0_8_;
          auVar36._8_4_ = auVar32._4_4_;
          auVar36 = auVar36 & ___xmm_00000000000000010000000000000001;
          lVar9 = lVar9 + auVar36._0_8_;
          lVar20 = lVar20 + auVar36._8_8_;
          auVar44[0] = -(-0x41 < (char)uVar1);
          cVar42 = -(-0x41 < (char)((ushort)uVar1 >> 8));
          auVar7._9_7_ = 0;
          auVar7._0_9_ = SUB169(ZEXT816(0),7);
          auVar6._10_6_ = 0;
          auVar6._0_10_ = SUB1610(auVar7 << 0x38,6);
          auVar5._11_5_ = 0;
          auVar5._0_11_ = SUB1611(auVar6 << 0x30,5);
          auVar44._4_12_ = SUB1612(auVar5 << 0x28,4);
          auVar44[3] = cVar42;
          auVar44[2] = cVar42;
          auVar44[1] = auVar44[0];
          auVar32 = pshuflw(auVar36,auVar44,0xd4);
          auVar37._12_4_ = auVar32._12_4_;
          auVar37._0_8_ = auVar32._0_8_;
          auVar37._8_4_ = auVar32._4_4_;
          lVar21 = lVar21 + SUB168(auVar37 & ___xmm_00000000000000010000000000000001,0);
          lVar22 = lVar22 + SUB168(auVar37 & ___xmm_00000000000000010000000000000001,8);
          uVar15 = uVar15 + 4;
        } while (uVar16 != uVar15);
        lVar9 = lVar22 + lVar20 + lVar21 + lVar9;
        goto LAB_1400077a8;
      }
      lVar9 = 0;
      uVar16 = 0;
      do {
        lVar9 = lVar9 + (ulonglong)(-0x41 < *(char *)(param_1 + uVar16));
        uVar16 = uVar16 + 1;
LAB_1400077a8:
      } while (uVar14 != uVar16);
    }
    pauVar10 = (undefined1 (*) [16])(param_1 + uVar14);
    if ((uVar13 & 7) == 0) {
      uVar14 = 0;
    }
    else {
      uVar15 = uVar13 & 0xfffffffffffffff8;
      uVar14 = (ulonglong)(-0x41 < (char)(*pauVar10)[uVar15]);
      if (((((uVar8 != 1) && (uVar14 = uVar14 + (-0x41 < (char)(*pauVar10)[uVar15 + 1]), uVar8 != 2)
            ) && (uVar14 = uVar14 + (-0x41 < (char)(*pauVar10)[uVar15 + 2]), uVar8 != 3)) &&
          ((uVar14 = uVar14 + (-0x41 < (char)(*pauVar10)[uVar15 + 3]), uVar8 != 4 &&
           (uVar14 = uVar14 + (-0x41 < (char)(*pauVar10)[uVar15 + 4]), uVar8 != 5)))) &&
         (uVar14 = uVar14 + (-0x41 < (char)(*pauVar10)[uVar15 + 5]), uVar8 != 6)) {
        uVar14 = uVar14 + (-0x41 < (char)(*pauVar10)[uVar15 + 6]);
      }
    }
    lVar9 = uVar14 + lVar9;
    uVar13 = uVar13 >> 3;
    auVar19._8_4_ = 0xffffffff;
    auVar19._0_8_ = 0xffffffffffffffff;
    auVar19._12_4_ = 0xffffffff;
    do {
      pauVar11 = pauVar10;
      if (uVar13 == 0) {
        return lVar9;
      }
      uVar14 = 0xc0;
      if (uVar13 < 0xc0) {
        uVar14 = uVar13;
      }
      if (uVar13 < 4) {
        uVar15 = 0;
      }
      else {
        uVar16 = uVar14 >> 2 & 0x3fffffff;
        uVar17 = uVar16 + 0x7ffffffffffffff & 0x7ffffffffffffff;
        if (uVar17 < 3) {
          uVar15 = 0;
          pauVar12 = pauVar11;
        }
        else {
          uVar17 = uVar17 + 1;
          uVar18 = uVar17 & 0xfffffffffffffffc;
          pauVar12 = pauVar11 + uVar18 * 2;
          pauVar10 = pauVar11 + 4;
          lVar20 = 0;
          lVar21 = 0;
          lVar22 = 0;
          lVar51 = 0;
          uVar15 = uVar18;
          do {
            auVar27._8_8_ = *(ulonglong *)pauVar10[-2];
            auVar27._0_8_ = *(ulonglong *)pauVar10[-4];
            auVar52._0_8_ = SUB168(auVar27 ^ auVar19,0) >> 7;
            auVar52._8_8_ = SUB168(auVar27 ^ auVar19,8) >> 7;
            auVar28._0_8_ = *(ulonglong *)pauVar10[-4] >> 6;
            auVar28._8_8_ = *(ulonglong *)pauVar10[-2] >> 6;
            auVar31 = (auVar28 | auVar52) & ___xmm_01010101010101010101010101010101;
            auVar23._8_8_ = *(ulonglong *)(pauVar10[-2] + 8);
            auVar23._0_8_ = *(ulonglong *)(pauVar10[-4] + 8);
            auVar45._8_8_ = *(ulonglong *)pauVar10[-1];
            auVar45._0_8_ = *(ulonglong *)pauVar10[-3];
            auVar38._8_8_ = *(ulonglong *)(pauVar10[-1] + 8);
            auVar38._0_8_ = *(ulonglong *)(pauVar10[-3] + 8);
            auVar56._8_8_ = *(ulonglong *)pauVar10[2];
            auVar56._0_8_ = *(ulonglong *)*pauVar10;
            auVar64._0_8_ = SUB168(auVar56 ^ auVar19,0) >> 7;
            auVar64._8_8_ = SUB168(auVar56 ^ auVar19,8) >> 7;
            auVar57._0_8_ = *(ulonglong *)*pauVar10 >> 6;
            auVar57._8_8_ = *(ulonglong *)pauVar10[2] >> 6;
            auVar58 = (auVar57 | auVar64) & ___xmm_01010101010101010101010101010101;
            auVar59._8_8_ = *(ulonglong *)(pauVar10[2] + 8);
            auVar59._0_8_ = *(ulonglong *)(*pauVar10 + 8);
            auVar53._8_8_ = *(ulonglong *)pauVar10[3];
            auVar53._0_8_ = *(ulonglong *)pauVar10[1];
            auVar49._8_8_ = *(ulonglong *)(pauVar10[3] + 8);
            auVar49._0_8_ = *(ulonglong *)(pauVar10[1] + 8);
            auVar62._0_8_ = SUB168(auVar23 ^ auVar19,0) >> 7;
            auVar62._8_8_ = SUB168(auVar23 ^ auVar19,8) >> 7;
            auVar65._0_8_ = SUB168(auVar59 ^ auVar19,0) >> 7;
            auVar65._8_8_ = SUB168(auVar59 ^ auVar19,8) >> 7;
            auVar24._0_8_ = *(ulonglong *)(pauVar10[-4] + 8) >> 6;
            auVar24._8_8_ = *(ulonglong *)(pauVar10[-2] + 8) >> 6;
            auVar60._0_8_ = *(ulonglong *)(*pauVar10 + 8) >> 6;
            auVar60._8_8_ = *(ulonglong *)(pauVar10[2] + 8) >> 6;
            auVar32 = (auVar24 | auVar62) & ___xmm_01010101010101010101010101010101;
            auVar61 = (auVar60 | auVar65) & ___xmm_01010101010101010101010101010101;
            auVar63._0_8_ = SUB168(auVar45 ^ auVar19,0) >> 7;
            auVar63._8_8_ = SUB168(auVar45 ^ auVar19,8) >> 7;
            auVar66._0_8_ = SUB168(auVar53 ^ auVar19,0) >> 7;
            auVar66._8_8_ = SUB168(auVar53 ^ auVar19,8) >> 7;
            auVar46._0_8_ = *(ulonglong *)pauVar10[-3] >> 6;
            auVar46._8_8_ = *(ulonglong *)pauVar10[-1] >> 6;
            auVar54._0_8_ = *(ulonglong *)pauVar10[1] >> 6;
            auVar54._8_8_ = *(ulonglong *)pauVar10[3] >> 6;
            auVar47 = (auVar46 | auVar63) & ___xmm_01010101010101010101010101010101;
            auVar55 = (auVar54 | auVar66) & ___xmm_01010101010101010101010101010101;
            auVar25._0_8_ = SUB168(auVar38 ^ auVar19,0) >> 7;
            auVar25._8_8_ = SUB168(auVar38 ^ auVar19,8) >> 7;
            auVar29._0_8_ = SUB168(auVar49 ^ auVar19,0) >> 7;
            auVar29._8_8_ = SUB168(auVar49 ^ auVar19,8) >> 7;
            auVar39._0_8_ = *(ulonglong *)(pauVar10[-3] + 8) >> 6;
            auVar39._8_8_ = *(ulonglong *)(pauVar10[-1] + 8) >> 6;
            auVar50._0_8_ = *(ulonglong *)(pauVar10[1] + 8) >> 6;
            auVar50._8_8_ = *(ulonglong *)(pauVar10[3] + 8) >> 6;
            auVar40 = (auVar39 | auVar25) & ___xmm_01010101010101010101010101010101;
            lVar20 = auVar40._0_8_ + auVar47._0_8_ + auVar32._0_8_ + auVar31._0_8_ + lVar20;
            lVar21 = auVar40._8_8_ + auVar47._8_8_ + auVar32._8_8_ + auVar31._8_8_ + lVar21;
            auVar32 = (auVar50 | auVar29) & ___xmm_01010101010101010101010101010101;
            lVar22 = auVar32._0_8_ + auVar55._0_8_ + auVar61._0_8_ + auVar58._0_8_ + lVar22;
            lVar51 = auVar32._8_8_ + auVar55._8_8_ + auVar61._8_8_ + auVar58._8_8_ + lVar51;
            pauVar10 = pauVar10 + 8;
            uVar15 = uVar15 - 4;
          } while (uVar15 != 0);
          uVar15 = lVar51 + lVar21 + lVar22 + lVar20;
          if (uVar17 == uVar18) goto LAB_140007882;
        }
        do {
          auVar32 = *pauVar12;
          auVar31 = pauVar12[1];
          auVar48._0_8_ = SUB168(auVar31 ^ auVar19,0) >> 7;
          auVar48._8_8_ = SUB168(auVar31 ^ auVar19,8) >> 7;
          auVar41._0_8_ = SUB168(auVar32 ^ auVar19,0) >> 7;
          auVar41._8_8_ = SUB168(auVar32 ^ auVar19,8) >> 7;
          auVar30._0_8_ = auVar31._0_8_ >> 6;
          auVar30._8_8_ = auVar31._8_8_ >> 6;
          auVar26._0_8_ = auVar32._0_8_ >> 6;
          auVar26._8_8_ = auVar32._8_8_ >> 6;
          auVar31 = (auVar30 | auVar48) & ___xmm_01010101010101010101010101010101;
          auVar32 = (auVar26 | auVar41) & ___xmm_01010101010101010101010101010101;
          uVar15 = uVar15 + auVar32._8_8_ + auVar31._8_8_ + auVar32._0_8_ + auVar31._0_8_;
          pauVar12 = pauVar12 + 2;
        } while (pauVar12 != (undefined1 (*) [16])(*pauVar11 + (uint)((int)uVar16 << 5)));
      }
LAB_140007882:
      uVar13 = uVar13 - uVar14;
      uVar8 = (uint)uVar14 & 3;
      lVar9 = (((uVar15 >> 8 & 0xff00ff00ff00ff) + (uVar15 & 0xff00ff00ff00ff)) * 0x1000100010001 >>
              0x30) + lVar9;
      pauVar10 = (undefined1 (*) [16])(*pauVar11 + (uVar14 & 0xffffffff) * 8);
    } while ((uVar14 & 3) == 0);
    uVar14 = (ulonglong)((uint)uVar14 & 0xfc);
    uVar13 = (*(ulonglong *)(*pauVar11 + uVar14 * 8) >> 6 |
             ~*(ulonglong *)(*pauVar11 + uVar14 * 8) >> 7) & 0x101010101010101;
    if ((uVar8 != 1) &&
       (uVar13 = uVar13 + ((*(ulonglong *)(*pauVar11 + uVar14 * 8 + 8) >> 6 |
                           ~*(ulonglong *)(*pauVar11 + uVar14 * 8 + 8) >> 7) & 0x101010101010101),
       uVar8 != 2)) {
      uVar13 = uVar13 + ((*(ulonglong *)(pauVar11[1] + uVar14 * 8) >> 6 |
                         ~*(ulonglong *)(pauVar11[1] + uVar14 * 8) >> 7) & 0x101010101010101);
    }
    lVar9 = (((uVar13 >> 8 & 0xff00ff00ff00ff) + (uVar13 & 0xff00ff00ff00ff)) * 0x1000100010001 >>
            0x30) + lVar9;
  }
  return lVar9;
}



===== fmt<usize> @ 140007c10 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void core::num::nonzero::impl$42::fmt<usize>(ulonglong *param_1,undefined8 *param_2)

{
  bool bVar1;
  code *pcVar2;
  longlong lVar3;
  ulonglong uVar4;
  byte bVar5;
  char cVar6;
  ulonglong local_98 [10];
  undefined1 local_48 [55];
  char cStack_11;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)local_48;
  local_98[0] = *param_1;
  if ((*(uint *)(param_2 + 2) & 0x2000000) == 0) {
    if ((*(uint *)(param_2 + 2) & 0x4000000) == 0) {
      _RNvXsi_NtNtNtCsloaxXL3qbEI_4core3fmt3num3impjNtB9_7Display3fmt(local_98,param_2);
      if ((local_10 ^ (ulonglong)local_48) == __security_cookie) {
        return;
      }
      goto LAB_140007c65;
    }
    lVar3 = 0;
    uVar4 = local_98[0];
    do {
      bVar5 = (byte)uVar4 & 0xf;
      cVar6 = bVar5 + 0x37;
      if (bVar5 < 10) {
        cVar6 = bVar5 + 0x30;
      }
      local_48[lVar3 + 0x37] = cVar6;
      lVar3 = lVar3 + -1;
      bVar1 = 0xf < uVar4;
      uVar4 = uVar4 >> 4;
    } while (bVar1);
  }
  else {
    lVar3 = 0;
    uVar4 = local_98[0];
    do {
      bVar5 = (byte)uVar4 & 0xf;
      cVar6 = bVar5 + 0x57;
      if (bVar5 < 10) {
        cVar6 = bVar5 + 0x30;
      }
      local_48[lVar3 + 0x37] = cVar6;
      lVar3 = lVar3 + -1;
      bVar1 = 0xf < uVar4;
      uVar4 = uVar4 >> 4;
    } while (bVar1);
  }
  _RNvMs9_NtCsloaxXL3qbEI_4core3fmtNtB5_9Formatter12pad_integral
            (param_2,'\x01',
             (undefined2 *)
             "0x00010203040506070809101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899user-provided comparison function does not correctly implement a total orderlibrary\\core\\src\\slice\\sort\\shared\\smallsort.rs"
             ,2,local_48 + lVar3 + 0x38,-lVar3);
  if ((local_10 ^ (ulonglong)local_48) == __security_cookie) {
    return;
  }
LAB_140007c65:
  pcVar2 = (code *)swi(3);
  (*pcVar2)();
  return;
}



===== _RNvXsU_NtNtCsloaxXL3qbEI_4core3fmt3numlNtB7_8LowerHex3fmt @ 140007d40 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void _RNvXsU_NtNtCsloaxXL3qbEI_4core3fmt3numlNtB7_8LowerHex3fmt(uint *param_1,undefined8 *param_2)

{
  bool bVar1;
  code *pcVar2;
  longlong lVar3;
  longlong lVar4;
  uint uVar5;
  byte bVar6;
  char cVar7;
  undefined1 local_48 [55];
  char cStack_11;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)local_48;
  lVar3 = 0;
  uVar5 = *param_1;
  do {
    lVar4 = lVar3;
    bVar6 = (byte)uVar5 & 0xf;
    cVar7 = bVar6 + 0x57;
    if (bVar6 < 10) {
      cVar7 = bVar6 + 0x30;
    }
    local_48[lVar4 + 0x37] = cVar7;
    bVar1 = 0xf < uVar5;
    lVar3 = lVar4 + -1;
    uVar5 = uVar5 >> 4;
  } while (bVar1);
  _RNvMs9_NtCsloaxXL3qbEI_4core3fmtNtB5_9Formatter12pad_integral
            (param_2,'\x01',
             (undefined2 *)
             "0x00010203040506070809101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899user-provided comparison function does not correctly implement a total orderlibrary\\core\\src\\slice\\sort\\shared\\smallsort.rs"
             ,2,local_48 + lVar4 + 0x37,-(lVar4 + -1));
  if ((local_10 ^ (ulonglong)local_48) == __security_cookie) {
    return;
  }
  pcVar2 = (code *)swi(3);
  (*pcVar2)();
  return;
}



===== _RNvXsV_NtNtCsloaxXL3qbEI_4core3fmt3numlNtB7_8UpperHex3fmt @ 140007e00 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void _RNvXsV_NtNtCsloaxXL3qbEI_4core3fmt3numlNtB7_8UpperHex3fmt(uint *param_1,undefined8 *param_2)

{
  bool bVar1;
  code *pcVar2;
  longlong lVar3;
  longlong lVar4;
  uint uVar5;
  byte bVar6;
  char cVar7;
  undefined1 local_48 [55];
  char cStack_11;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)local_48;
  lVar3 = 0;
  uVar5 = *param_1;
  do {
    lVar4 = lVar3;
    bVar6 = (byte)uVar5 & 0xf;
    cVar7 = bVar6 + 0x37;
    if (bVar6 < 10) {
      cVar7 = bVar6 + 0x30;
    }
    local_48[lVar4 + 0x37] = cVar7;
    bVar1 = 0xf < uVar5;
    lVar3 = lVar4 + -1;
    uVar5 = uVar5 >> 4;
  } while (bVar1);
  _RNvMs9_NtCsloaxXL3qbEI_4core3fmtNtB5_9Formatter12pad_integral
            (param_2,'\x01',
             (undefined2 *)
             "0x00010203040506070809101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899user-provided comparison function does not correctly implement a total orderlibrary\\core\\src\\slice\\sort\\shared\\smallsort.rs"
             ,2,local_48 + lVar4 + 0x37,-(lVar4 + -1));
  if ((local_10 ^ (ulonglong)local_48) == __security_cookie) {
    return;
  }
  pcVar2 = (code *)swi(3);
  (*pcVar2)();
  return;
}



===== _RNvXsw_NtNtCsloaxXL3qbEI_4core3fmt3numiNtB7_8LowerHex3fmt @ 140007ec0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void _RNvXsw_NtNtCsloaxXL3qbEI_4core3fmt3numiNtB7_8LowerHex3fmt
               (ulonglong *param_1,undefined8 *param_2)

{
  bool bVar1;
  code *pcVar2;
  longlong lVar3;
  longlong lVar4;
  ulonglong uVar5;
  byte bVar6;
  char cVar7;
  undefined1 local_48 [55];
  char cStack_11;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)local_48;
  lVar3 = 0;
  uVar5 = *param_1;
  do {
    lVar4 = lVar3;
    bVar6 = (byte)uVar5 & 0xf;
    cVar7 = bVar6 + 0x57;
    if (bVar6 < 10) {
      cVar7 = bVar6 + 0x30;
    }
    local_48[lVar4 + 0x37] = cVar7;
    bVar1 = 0xf < uVar5;
    lVar3 = lVar4 + -1;
    uVar5 = uVar5 >> 4;
  } while (bVar1);
  _RNvMs9_NtCsloaxXL3qbEI_4core3fmtNtB5_9Formatter12pad_integral
            (param_2,'\x01',
             (undefined2 *)
             "0x00010203040506070809101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899user-provided comparison function does not correctly implement a total orderlibrary\\core\\src\\slice\\sort\\shared\\smallsort.rs"
             ,2,local_48 + lVar4 + 0x37,-(lVar4 + -1));
  if ((local_10 ^ (ulonglong)local_48) == __security_cookie) {
    return;
  }
  pcVar2 = (code *)swi(3);
  (*pcVar2)();
  return;
}



===== _RNvXsB_NtNtCsloaxXL3qbEI_4core3fmt3numjNtB7_8UpperHex3fmt @ 140007f80 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void _RNvXsB_NtNtCsloaxXL3qbEI_4core3fmt3numjNtB7_8UpperHex3fmt
               (ulonglong *param_1,undefined8 *param_2)

{
  bool bVar1;
  code *pcVar2;
  longlong lVar3;
  longlong lVar4;
  ulonglong uVar5;
  byte bVar6;
  char cVar7;
  undefined1 local_48 [55];
  char cStack_11;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)local_48;
  lVar3 = 0;
  uVar5 = *param_1;
  do {
    lVar4 = lVar3;
    bVar6 = (byte)uVar5 & 0xf;
    cVar7 = bVar6 + 0x37;
    if (bVar6 < 10) {
      cVar7 = bVar6 + 0x30;
    }
    local_48[lVar4 + 0x37] = cVar7;
    bVar1 = 0xf < uVar5;
    lVar3 = lVar4 + -1;
    uVar5 = uVar5 >> 4;
  } while (bVar1);
  _RNvMs9_NtCsloaxXL3qbEI_4core3fmtNtB5_9Formatter12pad_integral
            (param_2,'\x01',
             (undefined2 *)
             "0x00010203040506070809101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899user-provided comparison function does not correctly implement a total orderlibrary\\core\\src\\slice\\sort\\shared\\smallsort.rs"
             ,2,local_48 + lVar4 + 0x37,-(lVar4 + -1));
  if ((local_10 ^ (ulonglong)local_48) == __security_cookie) {
    return;
  }
  pcVar2 = (code *)swi(3);
  (*pcVar2)();
  return;
}



===== fmt @ 140008040 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void core::fmt::num::impl$88::fmt(uint *param_1,undefined8 *param_2)

{
  bool bVar1;
  code *pcVar2;
  longlong lVar3;
  uint uVar4;
  byte bVar5;
  char cVar6;
  undefined1 local_58 [55];
  char cStack_21;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)local_58;
  if ((*(uint *)(param_2 + 2) & 0x2000000) == 0) {
    if ((*(uint *)(param_2 + 2) & 0x4000000) == 0) {
      _RNvXs8_NtNtNtCsloaxXL3qbEI_4core3fmt3num3impmNtB9_7Display3fmt(param_1,param_2);
      return;
    }
    lVar3 = 0;
    uVar4 = *param_1;
    do {
      bVar5 = (byte)uVar4 & 0xf;
      cVar6 = bVar5 + 0x37;
      if (bVar5 < 10) {
        cVar6 = bVar5 + 0x30;
      }
      local_58[lVar3 + 0x37] = cVar6;
      lVar3 = lVar3 + -1;
      bVar1 = 0xf < uVar4;
      uVar4 = uVar4 >> 4;
    } while (bVar1);
  }
  else {
    lVar3 = 0;
    uVar4 = *param_1;
    do {
      bVar5 = (byte)uVar4 & 0xf;
      cVar6 = bVar5 + 0x57;
      if (bVar5 < 10) {
        cVar6 = bVar5 + 0x30;
      }
      local_58[lVar3 + 0x37] = cVar6;
      lVar3 = lVar3 + -1;
      bVar1 = 0xf < uVar4;
      uVar4 = uVar4 >> 4;
    } while (bVar1);
  }
  _RNvMs9_NtCsloaxXL3qbEI_4core3fmtNtB5_9Formatter12pad_integral
            (param_2,'\x01',
             (undefined2 *)
             "0x00010203040506070809101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899user-provided comparison function does not correctly implement a total orderlibrary\\core\\src\\slice\\sort\\shared\\smallsort.rs"
             ,2,local_58 + lVar3 + 0x38,-lVar3);
  if ((local_20 ^ (ulonglong)local_58) == __security_cookie) {
    return;
  }
  pcVar2 = (code *)swi(3);
  (*pcVar2)();
  return;
}



===== _RNvXs8_NtNtNtCsloaxXL3qbEI_4core3fmt3num3impmNtB9_7Display3fmt @ 140008180 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void _RNvXs8_NtNtNtCsloaxXL3qbEI_4core3fmt3num3impmNtB9_7Display3fmt
               (uint *param_1,undefined8 *param_2)

{
  uint uVar1;
  bool bVar2;
  code *pcVar3;
  longlong lVar4;
  uint uVar5;
  ulonglong uVar6;
  uint uVar7;
  longlong lVar8;
  char cStack_3f;
  undefined2 uStack_3e;
  char acStack_3c [12];
  undefined8 local_30;
  
  local_30 = __security_cookie ^ (ulonglong)(acStack_3c + 0x14);
  uVar1 = *param_1;
  lVar4 = 10;
  uVar6 = (ulonglong)uVar1;
  if (999 < uVar1) {
    lVar8 = 10;
    uVar7 = uVar1;
    do {
      lVar4 = lVar8 + -4;
      uVar6 = (ulonglong)uVar7 / 10000;
      *(undefined2 *)(acStack_3c + lVar8 + -2) =
           *(undefined2 *)
            (
            "attempt to divide with overflow (1 << )called `Option::unwrap()` on a `None` valueindex out of bounds: the len is  but the index is assertion `left  right` failed: \n  left: \n right:  right` failed\n  left: ==!=matches:      { ,  {\n,\n} }((\n,0x00010203040506070809101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899user-provided comparison function does not correctly implement a total orderlibrary\\core\\src\\slice\\sort\\shared\\smallsort.rs"
            + (ulonglong)((uVar7 % 10000) / 100) * 2 + 0xf1);
      *(undefined2 *)(acStack_3c + lVar8) =
           *(undefined2 *)
            (
            "attempt to divide with overflow (1 << )called `Option::unwrap()` on a `None` valueindex out of bounds: the len is  but the index is assertion `left  right` failed: \n  left: \n right:  right` failed\n  left: ==!=matches:      { ,  {\n,\n} }((\n,0x00010203040506070809101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899user-provided comparison function does not correctly implement a total orderlibrary\\core\\src\\slice\\sort\\shared\\smallsort.rs"
            + (ulonglong)((uVar7 % 10000) % 100) * 2 + 0xf1);
      bVar2 = 9999999 < uVar7;
      lVar8 = lVar4;
      uVar7 = uVar7 / 10000;
    } while (bVar2);
  }
  uVar5 = (uint)uVar6;
  uVar7 = uVar5;
  if (9 < uVar5) {
    uVar7 = (uint)((uVar6 & 0xffff) >> 2) / 0x19;
    *(undefined2 *)(acStack_3c + lVar4) =
         *(undefined2 *)
          (
          "attempt to divide with overflow (1 << )called `Option::unwrap()` on a `None` valueindex out of bounds: the len is  but the index is assertion `left  right` failed: \n  left: \n right:  right` failed\n  left: ==!=matches:      { ,  {\n,\n} }((\n,0x00010203040506070809101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899user-provided comparison function does not correctly implement a total orderlibrary\\core\\src\\slice\\sort\\shared\\smallsort.rs"
          + (ulonglong)(uVar5 + uVar7 * -100 & 0xffff) * 2 + 0xf1);
    lVar4 = lVar4 + -2;
  }
  if ((uVar1 == 0) || (uVar7 != 0)) {
    acStack_3c[lVar4 + 1] =
         "attempt to divide with overflow (1 << )called `Option::unwrap()` on a `None` valueindex out of bounds: the len is  but the index is assertion `left  right` failed: \n  left: \n right:  right` failed\n  left: ==!=matches:      { ,  {\n,\n} }((\n,0x00010203040506070809101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899user-provided comparison function does not correctly implement a total orderlibrary\\core\\src\\slice\\sort\\shared\\smallsort.rs"
         [(ulonglong)(uVar7 & 0xf) * 2 + 0xf2];
    lVar4 = lVar4 + -1;
  }
  _RNvMs9_NtCsloaxXL3qbEI_4core3fmtNtB5_9Formatter12pad_integral
            (param_2,'\x01',(undefined2 *)0x1,0,acStack_3c + lVar4 + 2,10 - lVar4);
  if ((local_30 ^ (ulonglong)(acStack_3c + 0x14)) == __security_cookie) {
    return;
  }
  pcVar3 = (code *)swi(3);
  (*pcVar3)();
  return;
}



===== _RNvXsi_NtNtNtCsloaxXL3qbEI_4core3fmt3num3impjNtB9_7Display3fmt @ 1400082d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void _RNvXsi_NtNtNtCsloaxXL3qbEI_4core3fmt3num3impjNtB9_7Display3fmt
               (ulonglong *param_1,undefined8 *param_2)

{
  ulonglong uVar1;
  bool bVar2;
  code *pcVar3;
  uint uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  int iVar7;
  longlong lVar8;
  longlong lVar9;
  undefined2 uStack_48;
  undefined2 uStack_46;
  undefined1 auStack_44 [20];
  undefined8 local_30;
  
  local_30 = __security_cookie ^ (ulonglong)(auStack_44 + 0x1c);
  uVar1 = *param_1;
  lVar9 = 0x14;
  uVar6 = uVar1;
  if (999 < uVar1) {
    uVar5 = uVar1;
    lVar8 = 0x14;
    do {
      lVar9 = lVar8 + -4;
      uVar6 = uVar5 / 10000;
      iVar7 = (int)uVar5 + (int)uVar6 * -10000;
      uVar4 = (uint)(iVar7 * 0x147b) >> 0x13;
      *(undefined2 *)(auStack_44 + lVar8 + -4) =
           *(undefined2 *)
            (
            "attempt to divide with overflow (1 << )called `Option::unwrap()` on a `None` valueindex out of bounds: the len is  but the index is assertion `left  right` failed: \n  left: \n right:  right` failed\n  left: ==!=matches:      { ,  {\n,\n} }((\n,0x00010203040506070809101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899user-provided comparison function does not correctly implement a total orderlibrary\\core\\src\\slice\\sort\\shared\\smallsort.rs"
            + (ulonglong)uVar4 * 2 + 0xf1);
      *(undefined2 *)(auStack_44 + lVar8 + -2) =
           *(undefined2 *)
            (
            "attempt to divide with overflow (1 << )called `Option::unwrap()` on a `None` valueindex out of bounds: the len is  but the index is assertion `left  right` failed: \n  left: \n right:  right` failed\n  left: ==!=matches:      { ,  {\n,\n} }((\n,0x00010203040506070809101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899user-provided comparison function does not correctly implement a total orderlibrary\\core\\src\\slice\\sort\\shared\\smallsort.rs"
            + (ulonglong)(iVar7 + uVar4 * -100 & 0xffff) * 2 + 0xf1);
      bVar2 = 9999999 < uVar5;
      uVar5 = uVar6;
      lVar8 = lVar9;
    } while (bVar2);
  }
  if (9 < uVar6) {
    iVar7 = (int)uVar6;
    uVar4 = ((uint)(uVar6 >> 2) & 0xffff) * 0x147b >> 0x11;
    uVar6 = (ulonglong)uVar4;
    *(undefined2 *)(auStack_44 + lVar9 + -2) =
         *(undefined2 *)
          (
          "attempt to divide with overflow (1 << )called `Option::unwrap()` on a `None` valueindex out of bounds: the len is  but the index is assertion `left  right` failed: \n  left: \n right:  right` failed\n  left: ==!=matches:      { ,  {\n,\n} }((\n,0x00010203040506070809101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899user-provided comparison function does not correctly implement a total orderlibrary\\core\\src\\slice\\sort\\shared\\smallsort.rs"
          + (ulonglong)(iVar7 + uVar4 * -100 & 0xffff) * 2 + 0xf1);
    lVar9 = lVar9 + -2;
  }
  if ((uVar1 == 0) || (uVar6 != 0)) {
    auStack_44[lVar9 + -1] =
         "attempt to divide with overflow (1 << )called `Option::unwrap()` on a `None` valueindex out of bounds: the len is  but the index is assertion `left  right` failed: \n  left: \n right:  right` failed\n  left: ==!=matches:      { ,  {\n,\n} }((\n,0x00010203040506070809101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899user-provided comparison function does not correctly implement a total orderlibrary\\core\\src\\slice\\sort\\shared\\smallsort.rs"
         [(ulonglong)((uint)uVar6 & 0xf) * 2 + 0xf2];
    lVar9 = lVar9 + -1;
  }
  _RNvMs9_NtCsloaxXL3qbEI_4core3fmtNtB5_9Formatter12pad_integral
            (param_2,'\x01',(undefined2 *)0x1,0,auStack_44 + lVar9,0x14 - lVar9);
  if ((local_30 ^ (ulonglong)(auStack_44 + 0x1c)) == __security_cookie) {
    return;
  }
  pcVar3 = (code *)swi(3);
  (*pcVar3)();
  return;
}



===== fmt<dyn$<core::fmt::Debug>_> @ 140008410 =====

void core::fmt::impl$73::fmt<dyn_<core::fmt::Debug>_>(void)

{
  __llvm_retpoline_r11();
  return;
}



===== fmt<usize> @ 140008430 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void core::fmt::impl$73::fmt<usize>(undefined8 *param_1,undefined8 *param_2)

{
  ulonglong *puVar1;
  bool bVar2;
  code *pcVar3;
  longlong lVar4;
  ulonglong uVar5;
  byte bVar6;
  char cVar7;
  undefined1 local_58 [55];
  char cStack_21;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)local_58;
  puVar1 = (ulonglong *)*param_1;
  if ((*(uint *)(param_2 + 2) & 0x2000000) == 0) {
    if ((*(uint *)(param_2 + 2) & 0x4000000) == 0) {
      _RNvXsi_NtNtNtCsloaxXL3qbEI_4core3fmt3num3impjNtB9_7Display3fmt(puVar1,param_2);
      return;
    }
    lVar4 = 0;
    uVar5 = *puVar1;
    do {
      bVar6 = (byte)uVar5 & 0xf;
      cVar7 = bVar6 + 0x37;
      if (bVar6 < 10) {
        cVar7 = bVar6 + 0x30;
      }
      local_58[lVar4 + 0x37] = cVar7;
      lVar4 = lVar4 + -1;
      bVar2 = 0xf < uVar5;
      uVar5 = uVar5 >> 4;
    } while (bVar2);
  }
  else {
    lVar4 = 0;
    uVar5 = *puVar1;
    do {
      bVar6 = (byte)uVar5 & 0xf;
      cVar7 = bVar6 + 0x57;
      if (bVar6 < 10) {
        cVar7 = bVar6 + 0x30;
      }
      local_58[lVar4 + 0x37] = cVar7;
      lVar4 = lVar4 + -1;
      bVar2 = 0xf < uVar5;
      uVar5 = uVar5 >> 4;
    } while (bVar2);
  }
  _RNvMs9_NtCsloaxXL3qbEI_4core3fmtNtB5_9Formatter12pad_integral
            (param_2,'\x01',
             (undefined2 *)
             "0x00010203040506070809101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899user-provided comparison function does not correctly implement a total orderlibrary\\core\\src\\slice\\sort\\shared\\smallsort.rs"
             ,2,local_58 + lVar4 + 0x38,-lVar4);
  if ((local_20 ^ (ulonglong)local_58) == __security_cookie) {
    return;
  }
  pcVar3 = (code *)swi(3);
  (*pcVar3)();
  return;
}



===== fmt<str$> @ 140008560 =====

void core::fmt::impl$75::fmt<str_>(undefined8 *param_1,longlong param_2)

{
  _RNvMs9_NtCsloaxXL3qbEI_4core3fmtNtB5_9Formatter3pad(param_2,(byte *)*param_1,param_1[1]);
  return;
}



===== _RNvNtCslMg0IV26qJh_12gdi_bindings7draweng5efCos @ 140008580 =====

undefined8 _RNvNtCslMg0IV26qJh_12gdi_bindings7draweng5efCos(undefined8 param_1)

{
  undefined1 auVar1 [16];
  char cVar2;
  undefined4 in_EAX;
  uint uVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  float fVar9;
  float fVar10;
  undefined4 uVar11;
  undefined4 in_XMM0_Dc;
  undefined4 in_XMM0_Dd;
  
  fVar9 = (float)param_1 + 90.0;
  auVar1._4_4_ = (int)((ulonglong)param_1 >> 0x20);
  auVar1._0_4_ = fVar9;
  auVar1._8_4_ = in_XMM0_Dc;
  auVar1._12_4_ = in_XMM0_Dd;
  uVar3 = movmskps(in_EAX,auVar1);
  fVar10 = ABS(fVar9) * 0.35555556;
  uVar3 = uVar3 & 1;
  uVar8 = (uint)fVar10 >> 0x17 & 0xff;
  uVar5 = 0;
  fVar9 = 0.0;
  if (uVar8 < 0x9f) {
    if (uVar8 < 0x76) {
      fVar9 = fVar10;
      goto LAB_140008624;
    }
    cVar2 = (char)((uint)fVar10 >> 0x17);
    uVar7 = (uint)fVar10 & 0x7fffff | 0x800000;
    uVar6 = (uint)(((ulonglong)uVar7 << (cVar2 + 0x8aU & 0x3f)) >> 0x20);
    uVar5 = -uVar6;
    if (-1 < (int)fVar10) {
      uVar5 = uVar6;
    }
    if (uVar8 < 0x7f) {
LAB_14000860e:
      fVar9 = fVar10;
    }
    else if (uVar8 < 0x96) {
      fVar10 = fVar10 - (float)(int)(uVar7 >> (0x16U - cVar2 & 0x1f));
      goto LAB_14000860e;
    }
    bVar4 = (byte)uVar5 >> 6 ^ (byte)uVar3;
    if ((uVar5 & 0x20) == 0) {
      uVar3 = (uint)bVar4;
      goto LAB_140008624;
    }
    uVar11 = 0;
    fVar9 = (float)(&DAT_14001aa78)[0x20 - (uVar5 & 0x1f)] -
            fVar9 * ((float)(&DAT_14001aa78)[0x20 - (uVar5 & 0x1f)] -
                    (float)(&DAT_14001aa78)[uVar5 & 0x1f ^ 0x1f]);
    if ((bVar4 & 1) == 0) goto LAB_140008653;
  }
  else {
LAB_140008624:
    uVar11 = 0;
    fVar9 = ((float)(&DAT_14001aa7c)[uVar5 & 0x1f] - (float)(&DAT_14001aa78)[uVar5 & 0x1f]) * fVar9
            + (float)(&DAT_14001aa78)[uVar5 & 0x1f];
    if ((uVar3 & 1) == 0) goto LAB_140008653;
  }
  uVar11 = 0x80000000;
  fVar9 = -fVar9;
LAB_140008653:
  return CONCAT44(uVar11,fVar9);
}



===== _RNvNtCslMg0IV26qJh_12gdi_bindings7draweng5efSin @ 140008690 =====

undefined8 _RNvNtCslMg0IV26qJh_12gdi_bindings7draweng5efSin(undefined8 param_1)

{
  undefined1 auVar1 [16];
  char cVar2;
  undefined4 in_EAX;
  uint uVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  float fVar9;
  float fVar10;
  undefined4 uVar11;
  undefined4 in_XMM0_Dc;
  undefined4 in_XMM0_Dd;
  
  auVar1._8_4_ = in_XMM0_Dc;
  auVar1._0_8_ = param_1;
  auVar1._12_4_ = in_XMM0_Dd;
  uVar3 = movmskps(in_EAX,auVar1);
  fVar9 = ABS((float)param_1) * 0.35555556;
  uVar3 = uVar3 & 1;
  uVar8 = (uint)fVar9 >> 0x17 & 0xff;
  uVar5 = 0;
  fVar10 = 0.0;
  if (uVar8 < 0x9f) {
    if (uVar8 < 0x76) {
      fVar10 = fVar9;
      goto LAB_14000872c;
    }
    cVar2 = (char)((uint)fVar9 >> 0x17);
    uVar7 = (uint)fVar9 & 0x7fffff | 0x800000;
    uVar6 = (uint)(((ulonglong)uVar7 << (cVar2 + 0x8aU & 0x3f)) >> 0x20);
    uVar5 = -uVar6;
    if (-1 < (int)fVar9) {
      uVar5 = uVar6;
    }
    if (uVar8 < 0x7f) {
LAB_140008716:
      fVar10 = fVar9;
    }
    else if (uVar8 < 0x96) {
      fVar9 = fVar9 - (float)(int)(uVar7 >> (0x16U - cVar2 & 0x1f));
      goto LAB_140008716;
    }
    bVar4 = (byte)uVar5 >> 6 ^ (byte)uVar3;
    if ((uVar5 & 0x20) == 0) {
      uVar3 = (uint)bVar4;
      goto LAB_14000872c;
    }
    uVar11 = 0;
    fVar10 = (float)(&DAT_14001aa78)[0x20 - (uVar5 & 0x1f)] -
             fVar10 * ((float)(&DAT_14001aa78)[0x20 - (uVar5 & 0x1f)] -
                      (float)(&DAT_14001aa78)[uVar5 & 0x1f ^ 0x1f]);
    if ((bVar4 & 1) == 0) goto LAB_14000875b;
  }
  else {
LAB_14000872c:
    uVar11 = 0;
    fVar10 = ((float)(&DAT_14001aa7c)[uVar5 & 0x1f] - (float)(&DAT_14001aa78)[uVar5 & 0x1f]) *
             fVar10 + (float)(&DAT_14001aa78)[uVar5 & 0x1f];
    if ((uVar3 & 1) == 0) goto LAB_14000875b;
  }
  uVar11 = 0x80000000;
  fVar10 = -fVar10;
LAB_14000875b:
  return CONCAT44(uVar11,fVar10);
}



===== _RNvNtCslMg0IV26qJh_12gdi_bindings6efloat6bEfToL @ 1400087a0 =====

undefined8 _RNvNtCslMg0IV26qJh_12gdi_bindings6efloat6bEfToL(uint param_1)

{
  if ((param_1 >> 0x17 & 0xff) < 0x9f) {
    return 1;
  }
  return 0;
}



===== _RNvNtCslMg0IV26qJh_12gdi_bindings6efloat14bEfToL_or_zero @ 140008810 =====

int _RNvNtCslMg0IV26qJh_12gdi_bindings6efloat14bEfToL_or_zero(uint param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  ulonglong uVar4;
  uint uVar5;
  
  uVar5 = param_1 >> 0x17 & 0xff;
  iVar1 = 0;
  if (uVar5 < 0x9f) {
    uVar2 = param_1 & 0x7fffff | 0x800000;
    if (uVar5 < 0x76) {
      if (uVar5 - 0x76 < 0xffffffc1) {
        uVar4 = 0;
      }
      else {
        uVar4 = (ulonglong)(uVar2 >> (0x76U - (char)(param_1 >> 0x17) & 0x3f));
      }
    }
    else {
      uVar4 = (ulonglong)uVar2 << ((byte)(uVar5 - 0x76) & 0x3f);
    }
    iVar3 = (int)(uVar4 + 0x80000000 >> 0x20);
    iVar1 = -iVar3;
    if (-1 < (int)param_1) {
      iVar1 = iVar3;
    }
  }
  return iVar1;
}



===== _RNvNtCslMg0IV26qJh_12gdi_bindings4math13lCvtWithRound @ 140008880 =====

int _RNvNtCslMg0IV26qJh_12gdi_bindings4math13lCvtWithRound(float param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  ulonglong uVar4;
  uint uVar5;
  float fVar6;
  
  fVar6 = (float)param_2 * param_1;
  uVar5 = (uint)fVar6 >> 0x17 & 0xff;
  iVar1 = 0;
  if (uVar5 < 0x9f) {
    uVar2 = (uint)fVar6 & 0x7fffff | 0x800000;
    if (uVar5 < 0x76) {
      if (uVar5 - 0x76 < 0xffffffc1) {
        uVar4 = 0;
      }
      else {
        uVar4 = (ulonglong)(uVar2 >> (0x76U - (char)((uint)fVar6 >> 0x17) & 0x3f));
      }
    }
    else {
      uVar4 = (ulonglong)uVar2 << ((byte)(uVar5 - 0x76) & 0x3f);
    }
    iVar3 = (int)(uVar4 + 0x80000000 >> 0x20);
    iVar1 = -iVar3;
    if (-1 < (int)fVar6) {
      iVar1 = iVar3;
    }
  }
  return iVar1;
}



===== _RNvMNtCslMg0IV26qJh_12gdi_bindings5pointNtB2_7POINTFL10scale_rect @ 140008900 =====

void _RNvMNtCslMg0IV26qJh_12gdi_bindings5pointNtB2_7POINTFL10scale_rect
               (undefined4 *param_1,float *param_2,int *param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  ulonglong uVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  float fVar10;
  
  fVar10 = (float)*param_3 * *param_2;
  uVar5 = (uint)fVar10 >> 0x17 & 0xff;
  uVar7 = 0;
  if (uVar5 < 0x9f) {
    uVar1 = (uint)fVar10 & 0x7fffff | 0x800000;
    if (uVar5 < 0x76) {
      if (uVar5 - 0x76 < 0xffffffc1) {
        uVar4 = 0;
      }
      else {
        uVar4 = (ulonglong)(uVar1 >> (0x76U - (char)((uint)fVar10 >> 0x17) & 0x3f));
      }
    }
    else {
      uVar4 = (ulonglong)uVar1 << ((byte)(uVar5 - 0x76) & 0x3f);
    }
    iVar2 = (int)(uVar4 + 0x80000000 >> 0x20);
    iVar9 = -iVar2;
    if (-1 < (int)fVar10) {
      iVar9 = iVar2;
    }
    fVar10 = (float)param_3[1] * param_2[1];
    uVar5 = (uint)fVar10 >> 0x17 & 0xff;
    if (uVar5 < 0x9f) {
      uVar1 = (uint)fVar10 & 0x7fffff | 0x800000;
      if (uVar5 < 0x76) {
        if (uVar5 - 0x76 < 0xffffffc1) {
          uVar4 = 0;
        }
        else {
          uVar4 = (ulonglong)(uVar1 >> (0x76U - (char)((uint)fVar10 >> 0x17) & 0x3f));
        }
      }
      else {
        uVar4 = (ulonglong)uVar1 << ((byte)(uVar5 - 0x76) & 0x3f);
      }
      iVar3 = (int)(uVar4 + 0x80000000 >> 0x20);
      iVar2 = -iVar3;
      if (-1 < (int)fVar10) {
        iVar2 = iVar3;
      }
      fVar10 = *param_2 * (float)param_3[2];
      uVar5 = (uint)fVar10 >> 0x17 & 0xff;
      if (uVar5 < 0x9f) {
        uVar1 = (uint)fVar10 & 0x7fffff | 0x800000;
        if (uVar5 < 0x76) {
          if (uVar5 - 0x76 < 0xffffffc1) {
            uVar4 = 0;
          }
          else {
            uVar4 = (ulonglong)(uVar1 >> (0x76U - (char)((uint)fVar10 >> 0x17) & 0x3f));
          }
        }
        else {
          uVar4 = (ulonglong)uVar1 << ((byte)(uVar5 - 0x76) & 0x3f);
        }
        iVar6 = (int)(uVar4 + 0x80000000 >> 0x20);
        iVar3 = -iVar6;
        if (-1 < (int)fVar10) {
          iVar3 = iVar6;
        }
        fVar10 = param_2[1] * (float)param_3[3];
        uVar5 = (uint)fVar10 >> 0x17 & 0xff;
        if (uVar5 < 0x9f) {
          uVar1 = (uint)fVar10 & 0x7fffff | 0x800000;
          if (uVar5 < 0x76) {
            if (uVar5 - 0x76 < 0xffffffc1) {
              uVar4 = 0;
            }
            else {
              uVar4 = (ulonglong)(uVar1 >> (0x76U - (char)((uint)fVar10 >> 0x17) & 0x3f));
            }
          }
          else {
            uVar4 = (ulonglong)uVar1 << ((byte)(uVar5 - 0x76) & 0x3f);
          }
          iVar8 = (int)(uVar4 + 0x80000000 >> 0x20);
          iVar6 = -iVar8;
          if (-1 < (int)fVar10) {
            iVar6 = iVar8;
          }
          param_1[1] = iVar9;
          param_1[2] = iVar2;
          param_1[3] = iVar3;
          param_1[4] = iVar6;
          uVar7 = 1;
        }
      }
    }
  }
  *param_1 = uVar7;
  return;
}



===== _RNvMNtCslMg0IV26qJh_12gdi_bindings5pointNtB2_7POINTFL14scale_rect_mut @ 140008ae0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void _RNvMNtCslMg0IV26qJh_12gdi_bindings5pointNtB2_7POINTFL14scale_rect_mut
               (float *param_1,int *param_2)

{
  code *pcVar1;
  undefined1 auStack_48 [36];
  char local_24 [4];
  int local_20;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  _RNvMNtCslMg0IV26qJh_12gdi_bindings5pointNtB2_7POINTFL10scale_rect
            ((undefined4 *)local_24,param_1,param_2);
  if (local_24[0] == '\0') {
    local_20 = 0;
    iStack_1c = 0;
    iStack_18 = 0;
    iStack_14 = 0;
  }
  *param_2 = local_20;
  param_2[1] = iStack_1c;
  param_2[2] = iStack_18;
  param_2[3] = iStack_14;
  if ((local_10 ^ (ulonglong)auStack_48) == __security_cookie) {
    return;
  }
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== .weak.memcpy.default.__llvm_retpoline_r11 @ 140008b40 =====

void * __cdecl _weak_memcpy_default___llvm_retpoline_r11(void *_Dst,void *_Src,size_t _Size)

{
  ulonglong uVar1;
  ulonglong uVar2;
  undefined8 *puVar3;
  ulonglong uVar4;
  
  uVar1 = (ulonglong)(-(int)_Dst & 7);
  if (_Size < uVar1) {
    uVar1 = _Size;
  }
  uVar4 = _Size - uVar1 >> 3;
  uVar2 = (ulonglong)((uint)(_Size - uVar1) & 7);
  puVar3 = _Dst;
  for (; uVar1 != 0; uVar1 = uVar1 - 1) {
    *(undefined1 *)puVar3 = *(undefined1 *)_Src;
    _Src = (undefined8 *)((longlong)_Src + 1);
    puVar3 = (undefined8 *)((longlong)puVar3 + 1);
  }
  for (; uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar3 = *(undefined8 *)_Src;
    _Src = (undefined8 *)((longlong)_Src + 8);
    puVar3 = puVar3 + 1;
  }
  for (; uVar2 != 0; uVar2 = uVar2 - 1) {
    *(undefined1 *)puVar3 = *(undefined1 *)_Src;
    _Src = (undefined8 *)((longlong)_Src + 1);
    puVar3 = (undefined8 *)((longlong)puVar3 + 1);
  }
  return _Dst;
}



===== _RNvMs2_NtCsip5f2bf5HGI_5alloc7raw_vecINtB5_11RawVecInnerINtCsiNQa5DCRmUC_9gdi_alloc15TaggedAllocatorKm67646547_EE11try_reserveCsdyToaWEq7tk_8gdi_rust @ 140008b80 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong _RNvMs2_NtCsip5f2bf5HGI_5alloc7raw_vecINtB5_11RawVecInnerINtCsiNQa5DCRmUC_9gdi_alloc15TaggedAllocatorKm67646547_EE11try_reserveCsdyToaWEq7tk_8gdi_rust
                    (ulonglong *param_1,ulonglong param_2,ulonglong param_3,void *param_4,
                    ulonglong param_5)

{
  code *pcVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  ulonglong uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  undefined1 auStack_78 [48];
  int local_48 [2];
  ulonglong local_40;
  ulonglong local_30;
  void *local_28;
  longlong local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_78;
  uVar5 = *param_1;
  if ((-(ulonglong)(param_5 == 0) | uVar5) - param_2 < param_3) {
    if ((param_5 != 0) && (!CARRY8(param_2,param_3))) {
      uVar4 = uVar5 * 2;
      if (uVar5 * 2 < param_2 + param_3) {
        uVar4 = param_2 + param_3;
      }
      uVar6 = 8;
      if (param_5 != 1) {
        uVar6 = (ulonglong)(param_5 < 0x401) * 3 + 1;
      }
      if (uVar6 < uVar4) {
        uVar6 = uVar4;
      }
      auVar2._8_8_ = 0;
      auVar2._0_8_ = -(longlong)param_4 & (longlong)param_4 + (param_5 - 1);
      auVar3._8_8_ = 0;
      auVar3._0_8_ = uVar6;
      uVar4 = SUB168(auVar2 * auVar3,0);
      if (uVar4 <= 0x8000000000000000U - (longlong)param_4 && SUB168(auVar2 * auVar3,8) == 0) {
        if (uVar5 == 0) {
          local_28 = (void *)0x0;
        }
        else {
          local_30 = param_1[1];
          local_20 = uVar5 * param_5;
          local_28 = param_4;
        }
        _RINvNtCsip5f2bf5HGI_5alloc7raw_vec11finish_growINtCsiNQa5DCRmUC_9gdi_alloc15TaggedAllocatorKm67646547_EECsdyToaWEq7tk_8gdi_rust_llvm_17353492243722970462
                  ((ulonglong *)local_48,param_4,uVar4,&local_30);
        if (local_48[0] == 1) {
          if ((local_18 ^ (ulonglong)auStack_78) == __security_cookie) {
            return local_40;
          }
          goto LAB_140008c8b;
        }
        param_1[1] = local_40;
        *param_1 = uVar6;
        goto LAB_140008c9d;
      }
    }
    uVar5 = 0;
  }
  else {
LAB_140008c9d:
    uVar5 = 0x8000000000000001;
  }
  if ((local_18 ^ (ulonglong)auStack_78) == __security_cookie) {
    return uVar5;
  }
LAB_140008c8b:
  pcVar1 = (code *)swi(3);
  uVar5 = (*pcVar1)();
  return uVar5;
}



===== _RNvMs2_NtCsip5f2bf5HGI_5alloc7raw_vecINtB5_11RawVecInnerINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE11try_reserveCscIyU0BP6seX_7rgncore @ 140008cd0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong _RNvMs2_NtCsip5f2bf5HGI_5alloc7raw_vecINtB5_11RawVecInnerINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE11try_reserveCscIyU0BP6seX_7rgncore
                    (ulonglong *param_1,ulonglong param_2,ulonglong param_3,undefined1 *param_4,
                    ulonglong param_5)

{
  code *pcVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  ulonglong uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  undefined1 auStack_78 [48];
  int local_48 [2];
  ulonglong local_40;
  ulonglong local_30;
  undefined1 *local_28;
  longlong local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_78;
  uVar5 = *param_1;
  if ((-(ulonglong)(param_5 == 0) | uVar5) - param_2 < param_3) {
    if ((param_5 != 0) && (!CARRY8(param_2,param_3))) {
      uVar4 = uVar5 * 2;
      if (uVar5 * 2 < param_2 + param_3) {
        uVar4 = param_2 + param_3;
      }
      uVar6 = 8;
      if (param_5 != 1) {
        uVar6 = (ulonglong)(param_5 < 0x401) * 3 + 1;
      }
      if (uVar6 < uVar4) {
        uVar6 = uVar4;
      }
      auVar2._8_8_ = 0;
      auVar2._0_8_ = -(longlong)param_4 & (ulonglong)(param_4 + (param_5 - 1));
      auVar3._8_8_ = 0;
      auVar3._0_8_ = uVar6;
      uVar4 = SUB168(auVar2 * auVar3,0);
      if (uVar4 <= 0x8000000000000000U - (longlong)param_4 && SUB168(auVar2 * auVar3,8) == 0) {
        if (uVar5 == 0) {
          local_28 = (undefined1 *)0x0;
        }
        else {
          local_30 = param_1[1];
          local_20 = uVar5 * param_5;
          local_28 = param_4;
        }
        _RINvNtCsip5f2bf5HGI_5alloc7raw_vec11finish_growINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EECscIyU0BP6seX_7rgncore_llvm_13477870103536380358
                  ((ulonglong *)local_48,param_4,uVar4,&local_30);
        if (local_48[0] == 1) {
          if ((local_18 ^ (ulonglong)auStack_78) == __security_cookie) {
            return local_40;
          }
          goto LAB_140008ddb;
        }
        param_1[1] = local_40;
        *param_1 = uVar6;
        goto LAB_140008ded;
      }
    }
    uVar5 = 0;
  }
  else {
LAB_140008ded:
    uVar5 = 0x8000000000000001;
  }
  if ((local_18 ^ (ulonglong)auStack_78) == __security_cookie) {
    return uVar5;
  }
LAB_140008ddb:
  pcVar1 = (code *)swi(3);
  uVar5 = (*pcVar1)();
  return uVar5;
}



===== _RNvXCsiNQa5DCRmUC_9gdi_allocNtB2_14Win32AllocatorNtNtNtCsloaxXL3qbEI_4core5alloc6global11GlobalAlloc5alloc @ 140008e20 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void _RNvXCsiNQa5DCRmUC_9gdi_allocNtB2_14Win32AllocatorNtNtNtCsloaxXL3qbEI_4core5alloc6global11GlobalAlloc5alloc
               (undefined8 param_1,ulonglong param_2,undefined8 param_3)

{
  code *pcVar1;
  undefined1 auStack_38 [36];
  undefined4 local_14;
  undefined8 local_10;
  ulonglong local_8;
  
  local_8 = __security_cookie ^ (ulonglong)auStack_38;
  if (0x10 < param_2) {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core9panicking5panic();
  }
  local_14 = 0x74737552;
  local_10 = param_3;
  cxxbridge1_Win32AllocPool(&local_10,&local_14);
  if ((local_8 ^ (ulonglong)auStack_38) == __security_cookie) {
    return;
  }
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== _RNvXCsiNQa5DCRmUC_9gdi_allocNtB2_14Win32AllocatorNtNtNtCsloaxXL3qbEI_4core5alloc6global11GlobalAlloc7dealloc @ 140008e90 =====

void _RNvXCsiNQa5DCRmUC_9gdi_allocNtB2_14Win32AllocatorNtNtNtCsloaxXL3qbEI_4core5alloc6global11GlobalAlloc7dealloc
               (void)

{
  cxxbridge1_Win32FreePool();
  return;
}



===== _RNvNtCsiNQa5DCRmUC_9gdi_alloc3ffi14Win32AllocPool @ 140008ea0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void _RNvNtCsiNQa5DCRmUC_9gdi_alloc3ffi14Win32AllocPool(undefined8 param_1,undefined4 param_2)

{
  code *pcVar1;
  undefined1 auStack_38 [36];
  undefined4 local_14;
  undefined8 local_10;
  ulonglong local_8;
  
  local_8 = __security_cookie ^ (ulonglong)auStack_38;
  local_14 = param_2;
  local_10 = param_1;
  cxxbridge1_Win32AllocPool(&local_10,&local_14);
  if ((local_8 ^ (ulonglong)auStack_38) == __security_cookie) {
    return;
  }
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== _RNvNtCsiNQa5DCRmUC_9gdi_alloc3ffi13Win32FreePool @ 140008ef0 =====

void _RNvNtCsiNQa5DCRmUC_9gdi_alloc3ffi13Win32FreePool(void)

{
  Win32FreePool();
  return;
}



===== memmove @ 140008f00 =====

void * __cdecl memmove(void *_Dst,void *_Src,size_t _Size)

{
  ulonglong uVar1;
  ulonglong uVar2;
  undefined8 *puVar3;
  undefined1 *puVar4;
  undefined8 *puVar5;
  ulonglong uVar6;
  
  uVar2 = (ulonglong)(-(int)_Dst & 7);
  if (_Size < uVar2) {
    uVar2 = _Size;
  }
  uVar6 = _Size - uVar2 >> 3;
  uVar1 = (ulonglong)((uint)(_Size - uVar2) & 7);
  if ((ulonglong)((longlong)_Dst - (longlong)_Src) < _Size) {
    puVar4 = (undefined1 *)((longlong)_Src + (_Size - 1));
    puVar5 = (undefined8 *)((longlong)_Dst + _Size);
    for (; uVar1 != 0; uVar1 = uVar1 - 1) {
      *(undefined1 *)((longlong)puVar5 + -1) = *puVar4;
      puVar4 = puVar4 + -1;
      puVar5 = (undefined8 *)((longlong)puVar5 + -1);
    }
    puVar3 = (undefined8 *)(puVar4 + -7);
    for (; uVar6 != 0; uVar6 = uVar6 - 1) {
      puVar5[-1] = *puVar3;
      puVar3 = puVar3 + -1;
      puVar5 = puVar5 + -1;
    }
    puVar4 = (undefined1 *)((longlong)puVar3 + 7);
    for (uVar2 = uVar2 & 0xffffffff; puVar5 = (undefined8 *)((longlong)puVar5 + -1), uVar2 != 0;
        uVar2 = uVar2 - 1) {
      *(undefined1 *)puVar5 = *puVar4;
      puVar4 = puVar4 + -1;
    }
    return _Dst;
  }
  puVar5 = _Dst;
  for (; uVar2 != 0; uVar2 = uVar2 - 1) {
    *(undefined1 *)puVar5 = *(undefined1 *)_Src;
    _Src = (undefined8 *)((longlong)_Src + 1);
    puVar5 = (undefined8 *)((longlong)puVar5 + 1);
  }
  for (; uVar6 != 0; uVar6 = uVar6 - 1) {
    *puVar5 = *(undefined8 *)_Src;
    _Src = (undefined8 *)((longlong)_Src + 8);
    puVar5 = puVar5 + 1;
  }
  for (; uVar1 != 0; uVar1 = uVar1 - 1) {
    *(undefined1 *)puVar5 = *(undefined1 *)_Src;
    _Src = (undefined8 *)((longlong)_Src + 1);
    puVar5 = (undefined8 *)((longlong)puVar5 + 1);
  }
  return _Dst;
}



===== fmt @ 140008f90 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void alloc::collections::impl$9::fmt(undefined8 param_1,longlong param_2)

{
  code *pcVar1;
  ulonglong uVar2;
  undefined1 auStackY_48 [32];
  
  uVar2 = __security_cookie ^ (ulonglong)auStackY_48;
  _RNvMs9_NtCsloaxXL3qbEI_4core3fmtNtB5_9Formatter26debug_struct_field1_finish
            (param_2,"TryReserveErrorkindWindowsErrortrying to read past pscnTail",0xf,0x14001ab6f,4
            );
  if ((uVar2 ^ (ulonglong)auStackY_48) == __security_cookie) {
    return;
  }
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== fmt @ 140009010 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void minkernel_base::winerror::impl$13::fmt(undefined8 param_1,undefined8 *param_2)

{
  code *pcVar1;
  undefined1 auStack_38 [32];
  undefined *local_18;
  undefined8 local_10;
  ulonglong local_8;
  
  local_8 = __security_cookie ^ (ulonglong)auStack_38;
  local_18 = &DAT_1400193c8;
  local_10 = param_1;
  _RNvMs9_NtCsloaxXL3qbEI_4core3fmtNtB5_9Formatter25debug_tuple_field1_finish
            (param_2,"WindowsErrortrying to read past pscnTail",0xc);
  if ((local_8 ^ (ulonglong)auStack_38) == __security_cookie) {
    return;
  }
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== _RNvMs_NtCscIyU0BP6seX_7rgncore5mergeNtB6_10RegionCore5merge @ 140009080 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong _RNvMs_NtCscIyU0BP6seX_7rgncore5mergeNtB6_10RegionCore5merge
                    (ulonglong *param_1,longlong param_2,longlong param_3,byte param_4)

{
  int iVar1;
  int *piVar2;
  longlong lVar3;
  int *piVar4;
  code *pcVar5;
  undefined *puVar6;
  undefined **ppuVar7;
  longlong lVar8;
  undefined8 uVar9;
  longlong lVar10;
  int *piVar11;
  ulonglong uVar12;
  ulonglong uVar13;
  int *piVar14;
  byte *pbVar15;
  int *piVar16;
  int *piVar17;
  int *piVar18;
  int *piVar19;
  int *piVar20;
  int *piVar21;
  int iVar22;
  ulonglong uVar23;
  ulonglong uVar24;
  ulonglong uVar25;
  int *piVar26;
  ulonglong uVar27;
  int *unaff_R12;
  int *piVar28;
  byte bVar29;
  int iVar30;
  int *piVar31;
  int *piVar32;
  byte bVar33;
  undefined1 auStackY_128 [32];
  undefined **local_98;
  uint uStack_90;
  undefined4 uStack_8c;
  undefined4 local_88;
  undefined4 uStack_84;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined **local_60;
  uint uStack_58;
  undefined4 uStack_54;
  undefined4 local_50;
  undefined4 uStack_4c;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_128;
  piVar2 = *(int **)(param_2 + 0x10);
  if (piVar2 != (int *)0x0) {
    lVar3 = *(longlong *)(param_2 + 8);
    lVar8 = (longlong)*(int *)(lVar3 + -4 + (longlong)piVar2 * 4);
    piVar14 = piVar2;
    if (lVar8 < 0) {
LAB_140009859:
      piVar16 = (int *)0x2b;
      _RNvNtCsloaxXL3qbEI_4core6result13unwrap_failed();
LAB_140009885:
      _RNvNtNtCsloaxXL3qbEI_4core5slice5index22slice_index_order_fail();
LAB_140009891:
      _RNvNtNtCsloaxXL3qbEI_4core5slice5index24slice_end_index_len_fail
                (piVar16,piVar14,&anon_67cd83108cc9ed848dbde57549fb323c_20_llvm_3083486868190693220)
      ;
LAB_1400098a3:
      _RNvNtNtCsloaxXL3qbEI_4core5slice5index22slice_index_order_fail();
LAB_1400098b2:
      uVar12 = _RNvNtNtCsloaxXL3qbEI_4core5slice5index24slice_end_index_len_fail
                         (piVar14,unaff_R12,
                          &anon_67cd83108cc9ed848dbde57549fb323c_20_llvm_3083486868190693220);
LAB_1400098c4:
      uVar24 = uVar12;
      uVar12 = _RNvNtNtCsloaxXL3qbEI_4core5slice5index22slice_index_order_fail();
LAB_1400098d3:
      _RNvNtNtCsloaxXL3qbEI_4core5slice5index24slice_end_index_len_fail
                (uVar12,uVar24,&anon_67cd83108cc9ed848dbde57549fb323c_20_llvm_3083486868190693220);
LAB_1400098e2:
                    /* WARNING: Subroutine does not return */
      _RNvNtCsloaxXL3qbEI_4core6option13unwrap_failed();
    }
    if ((((int *)(lVar8 + 4U) <= piVar2) &&
        (uVar9 = _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalQINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E13is_valid_scanB4__llvm_3083486868190693220
                           (param_2,(longlong)piVar2 + (-4 - lVar8)), (char)uVar9 != '\0')) &&
       (piVar4 = *(int **)(param_3 + 0x10), piVar4 != (int *)0x0)) {
      lVar8 = *(longlong *)(param_3 + 8);
      lVar10 = (longlong)*(int *)(lVar8 + -4 + (longlong)piVar4 * 4);
      unaff_R12 = piVar4;
      if (lVar10 < 0) goto LAB_140009859;
      if (((int *)(lVar10 + 4U) <= piVar4) &&
         (uVar9 = _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalQINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E13is_valid_scanB4__llvm_3083486868190693220
                            (param_3,(longlong)piVar4 + (-4 - lVar10)), (char)uVar9 != '\0')) {
        uVar13 = *param_1;
        if (uVar13 < 0x1c) {
          uVar24 = param_1[2];
          if (uVar13 - uVar24 < 0x1c - uVar24) {
            uVar23 = 0xe;
            if (CARRY8(uVar24,0x1c - uVar24)) {
LAB_1400097fc:
              if ((local_48 ^ (ulonglong)auStackY_128) == __security_cookie) {
                return uVar23;
              }
            }
            else {
              uVar24 = 0x1c;
              if (0x1c < uVar13 * 2) {
                uVar24 = uVar13 * 2;
              }
              if (uVar13 == 0) {
                uStack_90 = 0;
              }
              else {
                local_98 = (undefined **)param_1[1];
                local_88 = (undefined4)(uVar13 << 2);
                uStack_84 = (undefined4)((uVar13 << 2) >> 0x20);
                uStack_90 = 4;
              }
              uStack_8c = 0;
              _RINvNtCsip5f2bf5HGI_5alloc7raw_vec11finish_growINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EECscIyU0BP6seX_7rgncore_llvm_13477870103536380358
                        ((ulonglong *)&local_60,&DAT_00000004,uVar24 * 4,&local_98);
              if ((int)local_60 != 1) {
                param_1[1] = CONCAT44(uStack_54,uStack_58);
                *param_1 = uVar24;
                goto LAB_140009225;
              }
              if ((local_48 ^ (ulonglong)auStackY_128) == __security_cookie) {
                return 0xe;
              }
            }
LAB_140009853:
            pcVar5 = (code *)swi(3);
            uVar13 = (*pcVar5)();
            return uVar13;
          }
        }
LAB_140009225:
        param_1[2] = 0;
        param_1[3] = 0x7fffffff00000000;
        param_1[4] = 0x800000007fffffff;
        *(undefined4 *)(param_1 + 5) = 0x80000000;
        uVar9 = _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalQINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E13is_valid_scanB4__llvm_3083486868190693220
                          (param_2,0);
        if (((char)uVar9 == '\0') ||
           (uVar9 = _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalQINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E13is_valid_scanB4__llvm_3083486868190693220
                              (param_3,0), (char)uVar9 == '\0')) {
                    /* WARNING: Subroutine does not return */
          _RNvNtCsloaxXL3qbEI_4core9panicking5panic();
        }
        piVar14 = (int *)0x1;
        piVar19 = (int *)0x0;
        piVar17 = (int *)0x0;
LAB_1400092ad:
        if (piVar4 <= (int *)((longlong)piVar17 + 1U)) {
                    /* WARNING: Subroutine does not return */
          _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
        }
        iVar22 = *(int *)(lVar3 + (longlong)piVar14 * 4);
        iVar30 = *(int *)(lVar8 + 4 + (longlong)piVar17 * 4);
        if (iVar22 < iVar30) {
          iVar22 = iVar30;
        }
        if (piVar2 <= (int *)((longlong)piVar19 + 2U)) {
                    /* WARNING: Subroutine does not return */
          _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
        }
        if (piVar4 <= (int *)((longlong)piVar17 + 2U)) {
                    /* WARNING: Subroutine does not return */
          _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
        }
        iVar30 = *(int *)(lVar3 + 8 + (longlong)piVar19 * 4);
        iVar1 = *(int *)(lVar8 + 8 + (longlong)piVar17 * 4);
        if (iVar1 < iVar30) {
          iVar30 = iVar1;
        }
        if (piVar2 <= piVar19) {
                    /* WARNING: Subroutine does not return */
          _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
        }
        if (piVar4 <= piVar17) {
                    /* WARNING: Subroutine does not return */
          _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
        }
        _RNvMs5_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE3new
                  (&local_98,param_1,iVar22,iVar30,
                   (longlong)*(int *)(lVar8 + (longlong)piVar17 * 4) +
                   (longlong)*(int *)(lVar3 + (longlong)piVar19 * 4));
        ppuVar7 = local_98;
        uVar23 = (ulonglong)uStack_90;
        if (local_98 == (undefined **)0x0) goto LAB_1400097f5;
        uStack_4c = uStack_84;
        uStack_54 = uStack_8c;
        local_50 = local_88;
        local_60 = local_98;
        uStack_58 = uStack_90;
        uVar13 = (longlong)piVar19 + 3;
        iVar22 = *(int *)(lVar3 + (longlong)piVar19 * 4);
        uVar24 = (ulonglong)iVar22;
        piVar16 = (int *)(uVar13 + uVar24);
        piVar14 = piVar2;
        unaff_R12 = piVar4;
        if (!CARRY8(uVar13,uVar24)) {
          if (piVar16 <= piVar2) {
            uVar23 = (longlong)piVar17 + 3;
            iVar1 = *(int *)(lVar8 + (longlong)piVar17 * 4);
            uVar25 = (ulonglong)iVar1;
            piVar14 = (int *)(uVar23 + uVar25);
            if (!CARRY8(uVar23,uVar25)) {
              if (piVar14 <= piVar4) goto code_r0x0001400093b0;
              goto LAB_1400098b2;
            }
            goto LAB_1400098a3;
          }
          goto LAB_140009891;
        }
        goto LAB_140009885;
      }
    }
  }
LAB_1400099b9:
                    /* WARNING: Subroutine does not return */
  _RNvNtCsloaxXL3qbEI_4core6option13unwrap_failed();
code_r0x0001400093b0:
  piVar16 = (int *)(lVar3 + uVar13 * 4);
  piVar20 = piVar16 + uVar24;
  piVar31 = (int *)(lVar8 + uVar23 * 4);
  piVar14 = piVar31 + uVar25;
  piVar28 = piVar31 + (iVar1 != 0);
  if (iVar1 == 0) {
    piVar31 = (int *)0x0;
  }
  piVar21 = piVar16 + (iVar22 != 0);
  if (iVar22 == 0) {
    piVar16 = (int *)0x0;
  }
  bVar29 = 1;
  bVar33 = param_4;
  while( true ) {
    piVar26 = (int *)0x0;
    piVar18 = piVar16;
    unaff_R12 = piVar28;
    piVar32 = piVar31;
    do {
      piVar31 = unaff_R12;
      if (piVar18 == (int *)0x0) {
        if (piVar32 == (int *)0x0) {
          local_88 = local_50;
          uStack_84 = uStack_4c;
          local_98 = local_60;
          uStack_90 = uStack_58;
          uStack_8c = uStack_54;
          uVar23 = _RNvMs4_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE18commit_or_coalesceB7_
                             ((longlong *)&local_98);
          if ((uVar23 & 1) != 0) {
            uVar23 = uVar23 >> 0x20;
            goto LAB_1400097f5;
          }
          uVar13 = param_1[2];
          if (uVar13 == 0) goto LAB_1400099b9;
          lVar10 = (longlong)*(int *)((param_1[1] - 4) + uVar13 * 4);
          if (lVar10 < 0) goto LAB_140009859;
          if (uVar13 < lVar10 + 4U) goto LAB_1400099b9;
          lVar10 = uVar13 - lVar10;
          uVar13 = lVar10 - 4;
          uVar9 = _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalQINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E13is_valid_scanB4__llvm_3083486868190693220
                            ((longlong)param_1,uVar13);
          if ((char)uVar9 == '\0') goto LAB_1400099b9;
          if (iVar30 == 0x7fffffff) {
            uVar23 = 0;
            uVar13 = param_1[2];
            goto joined_r0x00014000982f;
          }
          uVar24 = param_1[2];
          if (uVar24 <= uVar13) {
                    /* WARNING: Subroutine does not return */
            _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
          }
          uVar23 = param_1[1];
          if (*(int *)(uVar23 + uVar13 * 4) != 0) {
            uVar25 = lVar10 - 1;
            if (uVar24 <= uVar25) {
                    /* WARNING: Subroutine does not return */
              _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
            }
            iVar22 = *(int *)(uVar23 + uVar25 * 4);
            if (iVar22 < *(int *)((longlong)param_1 + 0x1c)) {
              *(int *)((longlong)param_1 + 0x1c) = iVar22;
            }
            if (uVar24 <= lVar10 - 3U) {
                    /* WARNING: Subroutine does not return */
              _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
            }
            iVar22 = *(int *)(uVar23 + 4 + uVar13 * 4);
            if (iVar22 < (int)param_1[4]) {
              *(int *)(param_1 + 4) = iVar22;
            }
            iVar22 = *(int *)(uVar23 + uVar13 * 4);
            uVar27 = (ulonglong)iVar22;
            uVar12 = uVar25 + uVar27;
            if (CARRY8(uVar25,uVar27)) goto LAB_1400098c4;
            if (uVar24 < uVar12) goto LAB_1400098d3;
            if ((iVar22 == 0) ||
               (piVar14 = (int *)(uVar23 + uVar25 * 4 + uVar27 * 4 + -4), piVar14 == (int *)0x0))
            goto LAB_1400098e2;
            iVar22 = *piVar14;
            if (*(int *)((longlong)param_1 + 0x24) < iVar22) {
              *(int *)((longlong)param_1 + 0x24) = iVar22;
            }
            if (uVar24 <= lVar10 - 2U) {
                    /* WARNING: Subroutine does not return */
              _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
            }
            iVar22 = *(int *)(uVar23 + 8 + uVar13 * 4);
            if ((int)param_1[5] < iVar22) {
              *(int *)(param_1 + 5) = iVar22;
            }
          }
          if (iVar30 == *(int *)(lVar3 + 8 + (longlong)piVar19 * 4)) {
            piVar19 = (int *)((longlong)piVar19 +
                             (longlong)*(int *)(lVar3 + (longlong)piVar19 * 4) + 4);
            uVar9 = _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalQINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E13is_valid_scanB4__llvm_3083486868190693220
                              (param_2,(ulonglong)piVar19);
            if ((char)uVar9 == '\0') {
              local_98 = &PTR_s_trying_to_read_past_pscnTail_14001ab60_0x1f_1400193e8;
              uStack_90 = 1;
              uStack_8c = 0;
              local_88 = 8;
              uStack_84 = 0;
              local_80 = 0;
              uStack_78 = 0;
                    /* WARNING: Subroutine does not return */
              _RNvNtCsloaxXL3qbEI_4core9panicking9panic_fmt();
            }
            iVar22 = *(int *)(lVar8 + 8 + (longlong)piVar17 * 4);
          }
          else {
            iVar22 = *(int *)(lVar8 + 8 + (longlong)piVar17 * 4);
          }
          if (iVar30 == iVar22) {
            piVar17 = (int *)((longlong)piVar17 +
                             (longlong)*(int *)(lVar8 + (longlong)piVar17 * 4) + 4);
            uVar9 = _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalQINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E13is_valid_scanB4__llvm_3083486868190693220
                              (param_3,(ulonglong)piVar17);
            if ((char)uVar9 == '\0') {
              local_98 = &PTR_s_trying_to_read_past_pscnTail_14001ab60_0x1f_1400193e8;
              uStack_90 = 1;
              uStack_8c = 0;
              local_88 = 8;
              uStack_84 = 0;
              local_80 = 0;
              uStack_78 = 0;
                    /* WARNING: Subroutine does not return */
              _RNvNtCsloaxXL3qbEI_4core9panicking9panic_fmt();
            }
          }
          piVar14 = (int *)((longlong)piVar19 + 1);
          if (piVar2 <= piVar14) {
                    /* WARNING: Subroutine does not return */
            _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
          }
          goto LAB_1400092ad;
        }
        if (0xf < bVar29) {
                    /* WARNING: Subroutine does not return */
          _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
        }
        pbVar15 = &DAT_14001abc0 + bVar29;
        piVar28 = unaff_R12 + (unaff_R12 != piVar14);
        if (unaff_R12 == piVar14) {
          piVar31 = piVar26;
        }
        piVar16 = (int *)0x0;
        piVar11 = piVar32;
      }
      else {
        piVar11 = piVar18;
        piVar16 = piVar21;
        piVar28 = unaff_R12;
        if (piVar32 == (int *)0x0) {
          if (0xf < bVar29) {
                    /* WARNING: Subroutine does not return */
            _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
          }
          pbVar15 = &DAT_14001abd0 + bVar29;
          if (piVar21 == piVar20) {
            piVar16 = piVar26;
          }
          piVar31 = (int *)0x0;
          piVar21 = piVar21 + (piVar21 != piVar20);
        }
        else if (*piVar18 < *piVar32) {
          if (0xf < bVar29) {
                    /* WARNING: Subroutine does not return */
            _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
          }
          pbVar15 = &DAT_14001abd0 + bVar29;
          piVar16 = (int *)0x0;
          if (piVar21 != piVar20) {
            piVar16 = piVar21;
          }
          piVar21 = piVar21 + (piVar21 != piVar20);
          piVar31 = piVar32;
        }
        else if (*piVar32 < *piVar18) {
          if (0xf < bVar29) {
                    /* WARNING: Subroutine does not return */
            _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
          }
          pbVar15 = &DAT_14001abc0 + bVar29;
          piVar31 = (int *)0x0;
          if (unaff_R12 != piVar14) {
            piVar31 = unaff_R12;
          }
          piVar11 = piVar32;
          piVar16 = piVar18;
          piVar28 = unaff_R12 + (unaff_R12 != piVar14);
        }
        else {
          if (0xf < bVar29) {
                    /* WARNING: Subroutine does not return */
            _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
          }
          pbVar15 = (byte *)("TryReserveErrorkindWindowsErrortrying to read past pscnTail" +
                            (ulonglong)bVar29 + 0x3b);
          if (piVar21 == piVar20) {
            piVar16 = piVar26;
          }
          if (unaff_R12 == piVar14) {
            piVar31 = piVar26;
          }
          piVar21 = piVar21 + (piVar21 != piVar20);
          piVar28 = unaff_R12 + (unaff_R12 != piVar14);
        }
      }
      bVar29 = *pbVar15;
      piVar18 = piVar16;
      unaff_R12 = piVar28;
      piVar32 = piVar31;
    } while ((bVar29 & bVar33) == 0);
    uVar23 = _RNvMs4_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE11append_wallB7_
                       ((longlong *)&local_60,*piVar11);
    if ((int)uVar23 != 0) break;
    bVar33 = bVar33 ^ 0xf;
  }
  uVar23 = uVar23 & 0xffffffff;
  puVar6 = (undefined *)CONCAT44(uStack_4c,local_50);
  if (ppuVar7[2] < puVar6) {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core9panicking5panic();
  }
  ppuVar7[2] = puVar6;
  if (puVar6 == (undefined *)0x0) {
    _RNvNtCsjsHfHFRyfyy_10gdi_region3ffi27RustOnZeroSizedScanCallback();
  }
LAB_1400097f5:
  uVar13 = param_1[2];
joined_r0x00014000982f:
  if (uVar13 != 0) goto LAB_1400097fc;
  _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore16set_to_null_scan(param_1);
  if ((local_48 ^ (ulonglong)auStackY_128) == __security_cookie) {
    return uVar23;
  }
  goto LAB_140009853;
}



===== _RNvXCscIyU0BP6seX_7rgncoreNtB2_11RegionGuardNtNtNtCsloaxXL3qbEI_4core3ops4drop4Drop4drop @ 140009a70 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void _RNvXCscIyU0BP6seX_7rgncoreNtB2_11RegionGuardNtNtNtCsloaxXL3qbEI_4core3ops4drop4Drop4drop
               (undefined8 *param_1)

{
  code *pcVar1;
  ulonglong uVar2;
  char *pcVar3;
  ulonglong uVar4;
  ulonglong *puVar5;
  undefined1 auStack_78 [32];
  undefined **ppuStack_58;
  int aiStack_48 [2];
  ulonglong uStack_40;
  ulonglong *puStack_38;
  ulonglong uStack_30;
  ulonglong *puStack_28;
  longlong lStack_20;
  ulonglong uStack_18;
  
  pcVar3 = (char *)*param_1;
  if (*(ulonglong *)((longlong)pcVar3 + 0x10) != 0) {
    return;
  }
  uStack_18 = __security_cookie ^ (ulonglong)auStack_78;
  *(undefined8 *)((longlong)pcVar3 + 0x1c) = 0;
  *(undefined8 *)((longlong)pcVar3 + 0x24) = 0;
  uVar2 = *(ulonglong *)((longlong)pcVar3 + 0x10);
  if (uVar2 < 5) {
    if (uVar2 == 4) goto LAB_140009d92;
    uVar4 = *(ulonglong *)pcVar3;
    if (uVar4 - uVar2 < 4 - uVar2) {
      uVar2 = 4;
      if (4 < uVar4 * 2) {
        uVar2 = uVar4 * 2;
      }
      puVar5 = (ulonglong *)(uVar2 * 4);
      if (puVar5 < (ulonglong *)0x7ffffffffffffffd && uVar4 < 0x2000000000000000)
      goto LAB_140009e7e;
      uStack_30 = 0;
      puStack_28 = (ulonglong *)pcVar3;
      while( true ) {
        ppuStack_58 = &PTR_s_rgncore_src_lib_rs_140019520;
        pcVar3 = s_called__Result__unwrap____on_an___14001abf3;
        puVar5 = &uStack_30;
        uVar4 = 0x2b;
        _RNvNtCsloaxXL3qbEI_4core6result13unwrap_failed();
LAB_140009e7e:
        if (uVar4 == 0) {
          puStack_28 = (ulonglong *)0x0;
        }
        else {
          uStack_30 = *(ulonglong *)((longlong)pcVar3 + 8);
          lStack_20 = uVar4 << 2;
          puStack_28 = (ulonglong *)0x4;
        }
        ppuStack_58 = (undefined **)((longlong)pcVar3 + 0x10);
        _RINvNtCsip5f2bf5HGI_5alloc7raw_vec11finish_growINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EECscIyU0BP6seX_7rgncore_llvm_13477870103536380358
                  ((ulonglong *)aiStack_48,&DAT_00000004,(ulonglong)puVar5,&uStack_30);
        if (aiStack_48[0] != 1) break;
        uStack_30 = uStack_40;
        puStack_28 = puStack_38;
      }
      *(ulonglong *)((longlong)pcVar3 + 8) = uStack_40;
      *(ulonglong *)pcVar3 = uVar2;
      uVar2 = *(ulonglong *)((longlong)pcVar3 + 0x10);
    }
    else {
      uStack_40 = *(ulonglong *)((longlong)pcVar3 + 8);
    }
    _weak_memset_default___llvm_retpoline_r11((void *)(uStack_40 + uVar2 * 4),0,uVar2 * -4 + 0x10);
  }
  *(ulonglong *)((longlong)pcVar3 + 0x10) = 4;
LAB_140009d92:
  **(undefined4 **)((longlong)pcVar3 + 8) = 0;
  if (*(ulonglong *)((longlong)pcVar3 + 0x10) < 2) {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
  }
  *(undefined4 *)(*(ulonglong *)((longlong)pcVar3 + 8) + 4) = 0x80000000;
  if (*(ulonglong *)((longlong)pcVar3 + 0x10) < 3) {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
  }
  *(undefined4 *)(*(ulonglong *)((longlong)pcVar3 + 8) + 8) = 0x7fffffff;
  if (*(ulonglong *)((longlong)pcVar3 + 0x10) < 4) {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
  }
  *(undefined4 *)(*(ulonglong *)((longlong)pcVar3 + 8) + 0xc) = 0;
  *(undefined4 *)((longlong)pcVar3 + 0x18) = 1;
  if ((uStack_18 ^ (ulonglong)auStack_78) == __security_cookie) {
    return;
  }
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore22new_with_scan_capacity @ 140009a90 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 *
_RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore22new_with_scan_capacity
          (undefined8 *param_1,ulonglong param_2)

{
  code *pcVar1;
  undefined8 *puVar2;
  ulonglong uVar3;
  undefined1 auStack_a8 [32];
  undefined8 *local_88;
  ulonglong local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 uStack_60;
  undefined4 uStack_58;
  undefined4 uStack_54;
  longlong local_50;
  undefined8 local_48;
  undefined8 local_40;
  byte local_38 [8];
  undefined8 local_30;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_a8;
  local_50 = 0;
  local_48 = 4;
  local_40 = 0;
  if (param_2 == 0) {
    local_30 = 4;
    uVar3 = 0;
LAB_140009b8d:
    uStack_68 = 0;
    uStack_60 = 0;
    uStack_58 = 0;
    local_80 = uVar3;
    uStack_78 = local_30;
    local_70 = local_40;
    _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore16set_to_null_scan(&local_80);
    param_1[4] = uStack_60;
    param_1[5] = CONCAT44(uStack_54,uStack_58);
    param_1[2] = local_70;
    param_1[3] = uStack_68;
    *param_1 = local_80;
    param_1[1] = uStack_78;
    if ((local_20 ^ (ulonglong)auStack_a8) == __security_cookie) {
      return param_1;
    }
  }
  else {
    uVar3 = 4;
    if (4 < param_2) {
      uVar3 = param_2;
    }
    if (uVar3 * 4 < 0x7ffffffffffffffd && param_2 >> 0x3e == 0) {
      uStack_78 = 0;
      local_88 = &local_40;
      _RINvNtCsip5f2bf5HGI_5alloc7raw_vec11finish_growINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EECscIyU0BP6seX_7rgncore_llvm_13477870103536380358
                ((ulonglong *)local_38,&DAT_00000004,uVar3 * 4,&local_80);
      if ((local_38[0] & 1) == 0) goto LAB_140009b8d;
      if (local_50 != 0) {
        if (local_50 == 0x1c) {
          _RNvNtCsjsHfHFRyfyy_10gdi_region3ffi22ScanLookAsideList_Free();
        }
        else {
          _RNvNtCsiNQa5DCRmUC_9gdi_alloc3ffi13Win32FreePool();
        }
      }
    }
    *(undefined4 *)(param_1 + 1) = 0xe;
    *param_1 = 0x8000000000000000;
    if ((local_20 ^ (ulonglong)auStack_a8) == __security_cookie) {
      return param_1;
    }
  }
  pcVar1 = (code *)swi(3);
  puVar2 = (undefined8 *)(*pcVar1)();
  return puVar2;
}



===== _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore21try_reserve_scan_data @ 140009c10 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
_RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore21try_reserve_scan_data
          (ulonglong *param_1,ulonglong param_2)

{
  ulonglong uVar1;
  code *pcVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined1 auStack_78 [32];
  ulonglong *local_58;
  int local_48 [2];
  ulonglong local_40;
  ulonglong local_30;
  undefined8 local_28;
  longlong local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_78;
  uVar1 = *param_1;
  uVar5 = param_1[2];
  uVar3 = 0;
  if (uVar1 - uVar5 < param_2) {
    uVar3 = 0xe;
    if (!CARRY8(uVar5,param_2)) {
      uVar4 = uVar1 * 2;
      if (uVar1 * 2 < uVar5 + param_2) {
        uVar4 = uVar5 + param_2;
      }
      uVar5 = 4;
      if (4 < uVar4) {
        uVar5 = uVar4;
      }
      if (uVar5 * 4 < 0x7ffffffffffffffd && uVar4 >> 0x3e == 0) {
        if (uVar1 == 0) {
          local_28 = 0;
        }
        else {
          local_30 = param_1[1];
          local_20 = uVar1 << 2;
          local_28 = 4;
        }
        local_58 = param_1 + 2;
        _RINvNtCsip5f2bf5HGI_5alloc7raw_vec11finish_growINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EECscIyU0BP6seX_7rgncore_llvm_13477870103536380358
                  ((ulonglong *)local_48,&DAT_00000004,uVar5 * 4,&local_30);
        if (local_48[0] != 1) {
          param_1[1] = local_40;
          *param_1 = uVar5;
          if ((local_18 ^ (ulonglong)auStack_78) == __security_cookie) {
            return 0;
          }
          goto LAB_140009d10;
        }
        uVar3 = 0xe;
      }
    }
  }
  if ((local_18 ^ (ulonglong)auStack_78) == __security_cookie) {
    return uVar3;
  }
LAB_140009d10:
  pcVar2 = (code *)swi(3);
  uVar3 = (*pcVar2)();
  return uVar3;
}



===== _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore16set_to_null_scan @ 140009d20 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore16set_to_null_scan(ulonglong *param_1)

{
  code *pcVar1;
  ulonglong uVar2;
  char *pcVar3;
  ulonglong uVar4;
  ulonglong *puVar5;
  undefined1 auStack_78 [32];
  undefined **local_58;
  int local_48 [2];
  ulonglong local_40;
  ulonglong *local_38;
  ulonglong local_30;
  ulonglong *local_28;
  longlong local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_78;
  *(undefined8 *)((longlong)param_1 + 0x1c) = 0;
  *(undefined8 *)((longlong)param_1 + 0x24) = 0;
  uVar2 = param_1[2];
  if (uVar2 < 5) {
    if (uVar2 == 4) goto LAB_140009d92;
    uVar4 = *param_1;
    if (uVar4 - uVar2 < 4 - uVar2) {
      uVar2 = 4;
      if (4 < uVar4 * 2) {
        uVar2 = uVar4 * 2;
      }
      puVar5 = (ulonglong *)(uVar2 * 4);
      if (puVar5 < (ulonglong *)0x7ffffffffffffffd && uVar4 < 0x2000000000000000)
      goto LAB_140009e7e;
      local_30 = 0;
      while( true ) {
        local_58 = &PTR_s_rgncore_src_lib_rs_140019520;
        pcVar3 = s_called__Result__unwrap____on_an___14001abf3;
        puVar5 = &local_30;
        uVar4 = 0x2b;
        local_28 = param_1;
        _RNvNtCsloaxXL3qbEI_4core6result13unwrap_failed();
        param_1 = (ulonglong *)pcVar3;
LAB_140009e7e:
        if (uVar4 == 0) {
          local_28 = (ulonglong *)0x0;
        }
        else {
          local_30 = param_1[1];
          local_20 = uVar4 << 2;
          local_28 = (ulonglong *)0x4;
        }
        local_58 = (undefined **)(param_1 + 2);
        _RINvNtCsip5f2bf5HGI_5alloc7raw_vec11finish_growINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EECscIyU0BP6seX_7rgncore_llvm_13477870103536380358
                  ((ulonglong *)local_48,&DAT_00000004,(ulonglong)puVar5,&local_30);
        if (local_48[0] != 1) break;
        local_30 = local_40;
        param_1 = local_38;
      }
      param_1[1] = local_40;
      *param_1 = uVar2;
      uVar2 = param_1[2];
    }
    else {
      local_40 = param_1[1];
    }
    _weak_memset_default___llvm_retpoline_r11((void *)(local_40 + uVar2 * 4),0,uVar2 * -4 + 0x10);
  }
  param_1[2] = 4;
LAB_140009d92:
  *(undefined4 *)param_1[1] = 0;
  if (param_1[2] < 2) {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
  }
  *(undefined4 *)(param_1[1] + 4) = 0x80000000;
  if (param_1[2] < 3) {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
  }
  *(undefined4 *)(param_1[1] + 8) = 0x7fffffff;
  if (param_1[2] < 4) {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
  }
  *(undefined4 *)(param_1[1] + 0xc) = 0;
  *(undefined4 *)(param_1 + 3) = 1;
  if ((local_18 ^ (ulonglong)auStack_78) == __security_cookie) {
    return;
  }
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore10first_scan @ 140009f30 =====

longlong _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore10first_scan(longlong param_1)

{
  undefined8 uVar1;
  
  uVar1 = _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalQINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E13is_valid_scanB4__llvm_3083486868190693220
                    (param_1,0);
  if ((char)uVar1 == '\0') {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core9panicking5panic();
  }
  return param_1;
}



===== _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore13last_scan_mut @ 140009f70 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

longlong _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore13last_scan_mut(longlong param_1)

{
  ulonglong uVar1;
  code *pcVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined1 auStack_48 [32];
  undefined **local_28;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  uVar1 = *(ulonglong *)(param_1 + 0x10);
  if (uVar1 != 0) {
    lVar3 = (longlong)*(int *)(*(longlong *)(param_1 + 8) + -4 + uVar1 * 4);
    if (lVar3 < 0) {
      local_28 = &anon_67cd83108cc9ed848dbde57549fb323c_12_llvm_3083486868190693220;
      _RNvNtCsloaxXL3qbEI_4core6result13unwrap_failed();
    }
    else if (lVar3 + 4U <= uVar1) {
      uVar4 = _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalQINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E13is_valid_scanB4__llvm_3083486868190693220
                        (param_1,(uVar1 - lVar3) - 4);
      if ((char)uVar4 != '\0') {
        if ((local_18 ^ (ulonglong)auStack_48) == __security_cookie) {
          return param_1;
        }
        pcVar2 = (code *)swi(3);
        lVar3 = (*pcVar2)();
        return lVar3;
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  _RNvNtCsloaxXL3qbEI_4core6option13unwrap_failed();
}



===== _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore23clear_scans_and_reserve @ 14000a020 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 *
_RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore23clear_scans_and_reserve
          (undefined4 *param_1,ulonglong *param_2,ulonglong param_3)

{
  ulonglong uVar1;
  code *pcVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  undefined1 auStack_78 [32];
  ulonglong *local_58;
  int local_50 [2];
  ulonglong local_48;
  ulonglong local_38;
  undefined8 local_30;
  longlong local_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_78;
  uVar1 = *param_2;
  if (uVar1 < param_3) {
    uVar6 = param_2[2];
    if (uVar1 - uVar6 < param_3 - uVar6) {
      if (!CARRY8(uVar6,param_3 - uVar6)) {
        uVar6 = uVar1 * 2;
        if (uVar1 * 2 < param_3) {
          uVar6 = param_3;
        }
        uVar5 = 4;
        if (4 < uVar6) {
          uVar5 = uVar6;
        }
        if (uVar5 * 4 < 0x7ffffffffffffffd && uVar6 >> 0x3e == 0) {
          if (uVar1 == 0) {
            local_30 = 0;
          }
          else {
            local_38 = param_2[1];
            local_28 = uVar1 << 2;
            local_30 = 4;
          }
          local_58 = param_2 + 2;
          _RINvNtCsip5f2bf5HGI_5alloc7raw_vec11finish_growINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EECscIyU0BP6seX_7rgncore_llvm_13477870103536380358
                    ((ulonglong *)local_50,&DAT_00000004,uVar5 * 4,&local_38);
          if (local_50[0] != 1) {
            param_2[1] = local_48;
            *param_2 = uVar5;
            goto LAB_14000a114;
          }
        }
      }
      param_1[1] = 0xe;
      uVar3 = 1;
      goto LAB_14000a129;
    }
  }
LAB_14000a114:
  param_2[2] = 0;
  *(undefined4 *)(param_2 + 3) = 0;
  *(ulonglong **)(param_1 + 2) = param_2;
  uVar3 = 0;
LAB_14000a129:
  *param_1 = uVar3;
  if ((local_20 ^ (ulonglong)auStack_78) == __security_cookie) {
    return param_1;
  }
  pcVar2 = (code *)swi(3);
  puVar4 = (undefined4 *)(*pcVar2)(local_20 ^ (ulonglong)auStack_78);
  return puVar4;
}



===== _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore16set_to_rectangle @ 14000a160 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore16set_to_rectangle
               (ulonglong *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  ulonglong uVar4;
  code *pcVar5;
  int iVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  longlong lVar9;
  undefined1 auStackY_98 [32];
  int local_70 [2];
  ulonglong local_68;
  undefined8 local_58;
  undefined8 local_50;
  longlong local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_98;
  iVar6 = *param_2;
  iVar1 = param_2[2];
  if (iVar6 == iVar1) {
LAB_14000a195:
    if ((local_40 ^ (ulonglong)auStackY_98) == __security_cookie) {
      _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore16set_to_null_scan(param_1);
      return;
    }
    pcVar5 = (code *)swi(3);
    (*pcVar5)();
    return;
  }
  iVar2 = param_2[1];
  iVar3 = param_2[3];
  if (iVar2 == iVar3) goto LAB_14000a195;
  uVar7 = *(undefined8 *)(param_2 + 2);
  *(undefined8 *)((longlong)param_1 + 0x1c) = *(undefined8 *)param_2;
  *(undefined8 *)((longlong)param_1 + 0x24) = uVar7;
  uVar8 = param_1[2];
  if (uVar8 == 0xe) {
    uVar7 = _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalQINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E13is_valid_scanB4__llvm_3083486868190693220
                      ((longlong)param_1,0);
    if ((char)uVar7 == '\0') {
                    /* WARNING: Subroutine does not return */
      _RNvNtCsloaxXL3qbEI_4core9panicking5panic();
    }
    if (param_1[2] < 3) {
                    /* WARNING: Subroutine does not return */
      _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
    }
    *(int *)(param_1[1] + 8) = iVar2;
    if (param_1[2] == 0) {
                    /* WARNING: Subroutine does not return */
      _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
    }
    lVar9 = (longlong)*(int *)param_1[1];
    uVar8 = lVar9 + 4;
    uVar7 = _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalQINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E13is_valid_scanB4__llvm_3083486868190693220
                      ((longlong)param_1,uVar8);
    if ((char)uVar7 == '\0') {
                    /* WARNING: Subroutine does not return */
      _RNvNtCsloaxXL3qbEI_4core6option13unwrap_failed();
    }
    if (param_1[2] <= lVar9 + 5U) {
LAB_14000a52d:
                    /* WARNING: Subroutine does not return */
      _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
    }
    *(int *)(param_1[1] + 0x14 + lVar9 * 4) = iVar2;
    if (param_1[2] <= lVar9 + 6U) {
                    /* WARNING: Subroutine does not return */
      _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
    }
    *(int *)(param_1[1] + 0x18 + lVar9 * 4) = iVar3;
    if (param_1[2] <= uVar8) {
LAB_14000a51e:
                    /* WARNING: Subroutine does not return */
      _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
    }
    if (*(int *)(param_1[1] + 0x10 + lVar9 * 4) == 0) {
LAB_14000a45e:
                    /* WARNING: Subroutine does not return */
      _RNvNtCsloaxXL3qbEI_4core9panicking5panic();
    }
    if (param_1[2] <= lVar9 + 7U) {
                    /* WARNING: Subroutine does not return */
      _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
    }
    *(int *)(param_1[1] + 0x1c + lVar9 * 4) = iVar6;
    if (param_1[2] <= uVar8) goto LAB_14000a51e;
    if (*(uint *)(param_1[1] + 0x10 + lVar9 * 4) < 2) goto LAB_14000a45e;
    if (param_1[2] <= lVar9 + 8U) {
                    /* WARNING: Subroutine does not return */
      _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
    }
    *(int *)(param_1[1] + 0x20 + lVar9 * 4) = iVar1;
    if (param_1[2] <= uVar8) goto LAB_14000a51e;
    uVar8 = lVar9 + 8U + (longlong)*(int *)(param_1[1] + 0x10 + lVar9 * 4);
    uVar7 = _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalQINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E13is_valid_scanB4__llvm_3083486868190693220
                      ((longlong)param_1,uVar8);
    if ((char)uVar7 != '\0') {
      if (uVar8 + 1 < param_1[2]) {
        *(int *)(param_1[1] + 4 + uVar8 * 4) = iVar3;
        return;
      }
      goto LAB_14000a52d;
    }
    goto LAB_14000a501;
  }
  uVar4 = *param_1;
  if ((uVar4 < 0xe) && (uVar4 - uVar8 < 0xe - uVar8)) {
    if (!CARRY8(uVar8,0xe - uVar8)) {
      uVar8 = 0xe;
      if (0xe < uVar4 * 2) {
        uVar8 = uVar4 * 2;
      }
      if (uVar4 == 0) {
        local_50 = 0;
      }
      else {
        local_58 = param_1[1];
        local_48 = uVar4 << 2;
        local_50 = 4;
      }
      _RINvNtCsip5f2bf5HGI_5alloc7raw_vec11finish_growINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EECscIyU0BP6seX_7rgncore_llvm_13477870103536380358
                ((ulonglong *)local_70,&DAT_00000004,uVar8 * 4,&local_58);
      if (local_70[0] != 1) {
        param_1[1] = local_68;
        *param_1 = uVar8;
        goto LAB_14000a328;
      }
    }
    local_58 = CONCAT44(local_58._4_4_,0xe);
  }
  else {
LAB_14000a328:
    param_1[2] = 0;
    *(undefined4 *)(param_1 + 3) = 0;
    uVar7 = _RNvMs5_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE11append_scan
                      (param_1,0x80000000,iVar2,(undefined4 *)&DAT_00000004,0);
    if ((int)uVar7 == 0) {
      local_58 = CONCAT44(iVar1,iVar6);
      uVar7 = _RNvMs5_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE11append_scan
                        (param_1,iVar2,iVar3,(undefined4 *)&local_58,2);
      if ((int)uVar7 == 0) {
        uVar7 = _RNvMs5_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE11append_scan
                          (param_1,iVar3,0x7fffffff,(undefined4 *)&DAT_00000004,0);
        iVar6 = (int)uVar7;
        if (iVar6 == 0) {
          if (param_1[2] == 0) {
            _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore16set_to_null_scan(param_1);
          }
          return;
        }
      }
      else {
        local_70[0] = (int)uVar7;
        iVar6 = _RNvNtCsloaxXL3qbEI_4core6result13unwrap_failed();
      }
      local_58 = CONCAT44(local_58._4_4_,iVar6);
    }
    else {
      local_58 = CONCAT44(local_58._4_4_,(int)uVar7);
    }
  }
  _RNvNtCsloaxXL3qbEI_4core6result13unwrap_failed();
LAB_14000a501:
                    /* WARNING: Subroutine does not return */
  _RNvNtCsloaxXL3qbEI_4core6option13unwrap_failed();
}



===== _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore13set_to_rectls @ 14000a590 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore13set_to_rectls
                    (ulonglong *param_1,longlong param_2,ulonglong param_3)

{
  code *pcVar1;
  ulonglong uVar2;
  int *piVar3;
  uint uVar4;
  ulonglong uVar5;
  longlong lVar6;
  int *piVar7;
  int *piVar8;
  ulonglong *puVar9;
  longlong lVar10;
  ulonglong uVar11;
  undefined1 auStack_188 [32];
  ulonglong *local_168;
  ulonglong local_158;
  uint local_150;
  ulonglong uStack_14c;
  undefined8 uStack_144;
  undefined8 local_13c;
  undefined8 uStack_134;
  uint local_12c;
  ulonglong local_128;
  uint uStack_120;
  undefined4 uStack_11c;
  undefined4 uStack_118;
  uint uStack_114;
  undefined4 uStack_110;
  undefined4 uStack_10c;
  uint uStack_108;
  undefined4 uStack_104;
  undefined4 uStack_100;
  uint local_fc;
  ulonglong local_f8;
  uint uStack_f0;
  undefined4 uStack_ec;
  undefined4 local_e8;
  uint uStack_e4;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  uint local_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  uint uStack_cc;
  ulonglong local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  uint local_a8;
  ulonglong local_98;
  uint local_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  uint uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  uint uStack_78;
  undefined4 uStack_74;
  undefined4 local_70;
  uint local_6c;
  longlong local_68;
  undefined8 local_60;
  ulonglong local_58;
  ulonglong local_50;
  undefined8 local_48;
  ulonglong uStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_188;
  if (param_3 == 0) {
    _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore16set_to_null_scan(param_1);
LAB_14000a5bc:
    uVar5 = 0;
    goto LAB_14000a5be;
  }
  local_50 = 0;
  local_48 = 4;
  local_168 = &uStack_40;
  uStack_40 = 0;
  uStack_120 = 0;
  uStack_11c = 0;
  _RINvNtCsip5f2bf5HGI_5alloc7raw_vec11finish_growINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EECscIyU0BP6seX_7rgncore_llvm_13477870103536380358
            (&local_c8,&DAT_00000004,0x70,&local_128);
  if ((int)local_c8 == 1) {
    if (local_50 != 0) {
      if (local_50 != 0x1c) {
        _RNvNtCsiNQa5DCRmUC_9gdi_alloc3ffi13Win32FreePool();
        uVar5 = 0xe;
        goto LAB_14000a5be;
      }
      _RNvNtCsjsHfHFRyfyy_10gdi_region3ffi22ScanLookAsideList_Free();
    }
    uVar5 = 0xe;
    goto LAB_14000a5be;
  }
  local_98 = 0x1c;
  local_90 = (uint)uStack_c0;
  uStack_8c = (undefined4)((ulonglong)uStack_c0 >> 0x20);
  uStack_88 = (undefined4)uStack_40;
  uStack_84 = (uint)(uStack_40 >> 0x20);
  uStack_80 = 0;
  uStack_7c = 0;
  uStack_78 = 0;
  uStack_74 = 0;
  local_70 = 0;
  _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore16set_to_null_scan(&local_98);
  uVar5 = (ulonglong)local_90;
  local_f8 = CONCAT44(uStack_88,uStack_8c);
  uStack_f0 = uStack_84;
  uStack_ec = uStack_80;
  local_e8 = uStack_7c;
  uStack_e4 = uStack_78;
  uStack_e0 = uStack_74;
  uStack_dc = local_70;
  local_d8 = local_6c;
  if (SBORROW8(0,local_98)) goto LAB_14000a5be;
  local_12c = local_6c;
  uStack_144 = CONCAT44(uStack_80,uStack_84);
  local_13c = CONCAT44(uStack_78,uStack_7c);
  uStack_134 = CONCAT44(local_70,uStack_74);
  local_158 = local_98;
  local_150 = local_90;
  local_68 = 0;
  local_60 = 4;
  local_168 = &local_58;
  local_58 = 0;
  uStack_c0 = 0;
  uStack_14c = local_f8;
  _RINvNtCsip5f2bf5HGI_5alloc7raw_vec11finish_growINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EECscIyU0BP6seX_7rgncore_llvm_13477870103536380358
            (&local_50,&DAT_00000004,0x70,&local_c8);
  if ((int)local_50 == 1) {
    if (local_68 != 0) {
      if (local_68 != 0x1c) {
        _RNvNtCsiNQa5DCRmUC_9gdi_alloc3ffi13Win32FreePool();
        uVar5 = 0xe;
        goto LAB_14000ab1d;
      }
      _RNvNtCsjsHfHFRyfyy_10gdi_region3ffi22ScanLookAsideList_Free();
    }
    uVar5 = 0xe;
  }
  else {
    local_98 = 0x1c;
    local_90 = (uint)local_48;
    uStack_8c = (undefined4)((ulonglong)local_48 >> 0x20);
    uStack_88 = (undefined4)local_58;
    uStack_84 = (uint)(local_58 >> 0x20);
    uStack_80 = 0;
    uStack_7c = 0;
    uStack_78 = 0;
    uStack_74 = 0;
    local_70 = 0;
    _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore16set_to_null_scan(&local_98);
    uVar5 = (ulonglong)local_90;
    local_f8 = CONCAT44(uStack_88,uStack_8c);
    uStack_f0 = uStack_84;
    uStack_ec = uStack_80;
    local_e8 = uStack_7c;
    uStack_e4 = uStack_78;
    uStack_e0 = uStack_74;
    uStack_dc = local_70;
    local_d8 = local_6c;
    if (local_98 != 0x8000000000000000) {
      local_fc = local_6c;
      uStack_10c = uStack_7c;
      uStack_108 = uStack_78;
      uStack_104 = uStack_74;
      uStack_100 = local_70;
      uStack_11c = uStack_8c;
      uStack_118 = uStack_88;
      uStack_114 = uStack_84;
      uStack_110 = uStack_80;
      local_128 = local_98;
      uStack_120 = local_90;
      if (param_3 < 0x14) {
        lVar6 = param_3 * 0x10;
        lVar10 = 0;
        do {
          if ((*(int *)(param_2 + lVar10) < *(int *)(param_2 + 8 + lVar10)) &&
             (*(int *)(param_2 + 4 + lVar10) < *(int *)(param_2 + 0xc + lVar10))) {
            _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore16set_to_rectangle
                      (param_1,(int *)(param_2 + lVar10));
            if (lVar6 + -0x10 != lVar10) {
              piVar3 = (int *)(param_2 + lVar10 + 0x20);
              piVar8 = (int *)(param_2 + lVar10 + 0x10);
              goto LAB_14000a94b;
            }
            break;
          }
          lVar10 = lVar10 + 0x10;
        } while (lVar6 != lVar10);
LAB_14000abcc:
        RegionCore_drop((longlong *)&local_128);
        RegionCore_drop((longlong *)&local_158);
        goto LAB_14000a5bc;
      }
      _RINvCsgf1RBdmyjwT_12fallible_vec20try_with_capacity_inlINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EECscIyU0BP6seX_7rgncore
                (&local_50,0x1c);
      if (local_50 == 0x8000000000000000) {
        uVar4 = 0xe;
      }
      else {
        local_98 = local_50;
        local_90 = (uint)local_48;
        uStack_8c = (undefined4)((ulonglong)local_48 >> 0x20);
        uStack_88 = (undefined4)uStack_40;
        uStack_84 = (uint)(uStack_40 >> 0x20);
        uStack_80 = 0;
        uStack_7c = 0;
        uStack_78 = 0;
        uStack_74 = 0;
        local_70 = 0;
        _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore16set_to_null_scan(&local_98);
        local_c8 = CONCAT44(uStack_88,uStack_8c);
        uStack_c0 = CONCAT44(uStack_80,uStack_84);
        local_b8 = CONCAT44(uStack_78,uStack_7c);
        uStack_b0 = CONCAT44(local_70,uStack_74);
        local_a8 = local_6c;
        if (local_98 == 0x8000000000000000) {
          uVar4 = local_90;
        }
        else {
          uStack_cc = local_6c;
          uStack_dc = uStack_7c;
          local_d8 = uStack_78;
          uStack_d4 = uStack_74;
          uStack_d0 = local_70;
          uStack_ec = uStack_8c;
          local_e8 = uStack_88;
          uStack_e4 = uStack_84;
          uStack_e0 = uStack_80;
          local_f8 = local_98;
          uStack_f0 = local_90;
          uVar11 = param_3 >> 1;
          uVar5 = _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore13set_to_rectls
                            (&local_158,param_2,uVar11);
          uVar4 = (uint)uVar5;
          if (uVar4 == 0) {
            uVar5 = _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore13set_to_rectls
                              (&local_128,param_2 + uVar11 * 0x10,param_3 - uVar11);
            uVar4 = (uint)uVar5;
            if (uVar4 == 0) {
              puVar9 = &local_128;
              uVar5 = _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore7combine
                                (&local_f8,puVar9,&local_158,2);
              if ((uVar5 & 1) == 0) {
                uVar5 = *param_1;
                uVar11 = param_1[1];
                *param_1 = local_f8;
                param_1[1] = CONCAT44(uStack_ec,uStack_f0);
                uStack_f0 = (uint)uVar11;
                uStack_ec = (undefined4)(uVar11 >> 0x20);
                uVar11 = param_1[2];
                uVar2 = param_1[3];
                param_1[2] = CONCAT44(uStack_e4,local_e8);
                param_1[3] = CONCAT44(uStack_dc,uStack_e0);
                local_e8 = (undefined4)uVar11;
                uStack_e4 = (uint)(uVar11 >> 0x20);
                uStack_e0 = (undefined4)uVar2;
                uStack_dc = (undefined4)(uVar2 >> 0x20);
                uVar11 = param_1[4];
                uVar2 = param_1[5];
                param_1[4] = CONCAT44(uStack_d4,local_d8);
                param_1[5] = CONCAT44(uStack_cc,uStack_d0);
                local_d8 = (uint)uVar11;
                uStack_d4 = (undefined4)(uVar11 >> 0x20);
                uStack_d0 = (undefined4)uVar2;
                uStack_cc = (uint)(uVar2 >> 0x20);
                local_f8 = uVar5;
                RegionCore_drop((longlong *)&local_f8);
                goto LAB_14000abcc;
              }
              uVar4 = (uint)puVar9;
            }
          }
          RegionCore_drop((longlong *)&local_f8);
        }
      }
LAB_14000ab11:
      RegionCore_drop((longlong *)&local_128);
      uVar5 = (ulonglong)uVar4;
    }
  }
LAB_14000ab1d:
  if (local_158 != 0) {
    if (local_158 == 0x1c) {
      _RNvNtCsjsHfHFRyfyy_10gdi_region3ffi22ScanLookAsideList_Free();
    }
    else {
      _RNvNtCsiNQa5DCRmUC_9gdi_alloc3ffi13Win32FreePool();
    }
  }
LAB_14000a5be:
  if ((local_38 ^ (ulonglong)auStack_188) == __security_cookie) {
    return uVar5;
  }
  pcVar1 = (code *)swi(3);
  uVar5 = (*pcVar1)();
  return uVar5;
LAB_14000a94b:
  piVar7 = piVar3;
  if ((*piVar8 < piVar8[2]) && (piVar8[1] < piVar8[3])) {
    _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore16set_to_rectangle(&local_158,piVar8);
    puVar9 = param_1;
    uVar5 = _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore7combine(&local_128,param_1,&local_158,2);
    if ((uVar5 & 1) != 0) {
      uVar4 = (uint)puVar9;
      goto LAB_14000ab11;
    }
    uVar5 = *param_1;
    uVar11 = param_1[1];
    *param_1 = local_128;
    param_1[1] = CONCAT44(uStack_11c,uStack_120);
    uStack_120 = (uint)uVar11;
    uStack_11c = (undefined4)(uVar11 >> 0x20);
    uVar11 = param_1[2];
    uVar2 = param_1[3];
    param_1[2] = CONCAT44(uStack_114,uStack_118);
    param_1[3] = CONCAT44(uStack_10c,uStack_110);
    uStack_118 = (undefined4)uVar11;
    uStack_114 = (uint)(uVar11 >> 0x20);
    uStack_110 = (undefined4)uVar2;
    uStack_10c = (undefined4)(uVar2 >> 0x20);
    uVar11 = param_1[4];
    uVar2 = param_1[5];
    param_1[4] = CONCAT44(uStack_104,uStack_108);
    param_1[5] = CONCAT44(local_fc,uStack_100);
    uStack_108 = (uint)uVar11;
    uStack_104 = (undefined4)(uVar11 >> 0x20);
    uStack_100 = (undefined4)uVar2;
    local_fc = (uint)(uVar2 >> 0x20);
    local_128 = uVar5;
  }
  if (piVar7 == (int *)(param_2 + lVar6)) goto LAB_14000abcc;
  piVar3 = piVar7 + (ulonglong)(piVar7 != (int *)(param_2 + lVar6)) * 4;
  piVar8 = piVar7;
  goto LAB_14000a94b;
}



===== _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore10intersects @ 14000abf0 =====

undefined8 _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore10intersects(longlong param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  int *piVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  
  iVar1 = *param_2;
  if ((((iVar1 < *(int *)(param_1 + 0x24)) && (iVar2 = param_2[2], *(int *)(param_1 + 0x1c) < iVar2)
       ) && (iVar3 = param_2[1], iVar3 < *(int *)(param_1 + 0x28))) &&
     (iVar4 = param_2[3], *(int *)(param_1 + 0x20) < iVar4)) {
    uVar7 = _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalQINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E13is_valid_scanB4__llvm_3083486868190693220
                      (param_1,0);
    if ((char)uVar7 == '\0') {
LAB_14000ad51:
                    /* WARNING: Subroutine does not return */
      _RNvNtCsloaxXL3qbEI_4core9panicking5panic();
    }
    lVar5 = *(longlong *)(param_1 + 8);
    uVar6 = *(ulonglong *)(param_1 + 0x10);
    uVar11 = 0;
    do {
      if (uVar6 <= uVar11 + 2) {
                    /* WARNING: Subroutine does not return */
        _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
      }
      if (iVar3 < *(int *)(lVar5 + 8 + uVar11 * 4)) {
        goto LAB_14000acc5;
      }
      if (uVar6 <= uVar11) goto LAB_14000ad7f;
      uVar11 = uVar11 + (longlong)*(int *)(lVar5 + uVar11 * 4) + 4;
      uVar7 = _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalQINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E13is_valid_scanB4__llvm_3083486868190693220
                        (param_1,uVar11);
    } while ((char)uVar7 != '\0');
  }
  return 0;
LAB_14000acc5:
  if (uVar6 <= uVar11 + 1) {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
  }
  if (iVar4 <= *(int *)(lVar5 + 4 + uVar11 * 4)) {
    return 0;
  }
  if (uVar6 <= uVar11) {
LAB_14000ad7f:
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
  }
  iVar3 = *(int *)(lVar5 + uVar11 * 4);
  uVar8 = (ulonglong)iVar3;
  uVar10 = uVar11 + 3 + uVar8;
  if (CARRY8(uVar11 + 3,uVar8)) {
    _RNvNtNtCsloaxXL3qbEI_4core5slice5index22slice_index_order_fail();
LAB_14000ad3f:
    _RNvNtNtCsloaxXL3qbEI_4core5slice5index24slice_end_index_len_fail
              (uVar10,uVar6,&anon_67cd83108cc9ed848dbde57549fb323c_20_llvm_3083486868190693220);
    goto LAB_14000ad51;
  }
  if (uVar6 < uVar10) goto LAB_14000ad3f;
  piVar9 = (int *)(uVar11 * 4 + lVar5 + 0x10);
  for (uVar10 = uVar8; uVar10 != 0; uVar10 = uVar10 - 2) {
    if (uVar10 == 1) {
                    /* WARNING: Subroutine does not return */
      _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
    }
    if (iVar1 < *piVar9) {
      if (piVar9[-1] < iVar2) {
        return CONCAT71((int7)(int3)((uint)iVar3 >> 8),1);
      }
      break;
    }
    piVar9 = piVar9 + 2;
  }
  uVar11 = uVar11 + uVar8 + 4;
  uVar7 = _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalQINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E13is_valid_scanB4__llvm_3083486868190693220
                    (param_1,uVar11);
  if ((char)uVar7 == '\0') {
    return 0;
  }
  goto LAB_14000acc5;
}



===== _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore15scans_are_equal @ 14000adc0 =====

undefined8
_RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore15scans_are_equal(longlong param_1,longlong param_2)

{
  int iVar1;
  undefined4 extraout_var;
  
  if ((*(int *)(param_1 + 0x18) == *(int *)(param_2 + 0x18)) &&
     (*(longlong *)(param_1 + 0x10) == *(longlong *)(param_2 + 0x10))) {
    iVar1 = memcmp(*(void **)(param_1 + 8),*(void **)(param_2 + 8),
                   *(longlong *)(param_1 + 0x10) << 2);
    return CONCAT71((int7)(CONCAT44(extraout_var,iVar1) >> 8),iVar1 == 0);
  }
  return 0;
}



===== _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore9offset_by @ 14000ae00 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore9offset_by
                    (longlong param_1,int param_2,int param_3)

{
  int *piVar1;
  code *pcVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  undefined1 auStack_68 [36];
  int local_44;
  uint local_40;
  int local_3c;
  uint local_38;
  uint local_34;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_68;
  uVar6 = 0;
  if (((*(int *)(param_1 + 0x18) != 1) && (*(int *)(param_1 + 0x1c) < *(int *)(param_1 + 0x24))) &&
     (*(int *)(param_1 + 0x20) < *(int *)(param_1 + 0x28))) {
    _RNvMNtNtCs2JCLxFJL4Mh_15onecore_windows6windef4rectNtB4_6__RECTL16offset_add_point
              (&local_44,(int *)(param_1 + 0x1c),param_2,param_3);
    if (local_44 == 1) {
      uVar6 = (ulonglong)local_40;
    }
    else {
      uVar8 = (ulonglong)local_38;
      uVar6 = 0x216;
      if ((((((local_40 & 0xf8000000) == 0) || ((local_40 & 0xf8000000) == 0xf8000000)) &&
           (((local_34 & 0xf8000000) == 0 || ((local_34 & 0xf8000000) == 0xf8000000)))) &&
          (((local_38 & 0xf8000000) == 0 || ((local_38 & 0xf8000000) == 0xf8000000)))) &&
         (local_3c + 0x8000000U < 0x10000000)) {
        *(uint *)(param_1 + 0x1c) = local_40;
        *(int *)(param_1 + 0x20) = local_3c;
        *(uint *)(param_1 + 0x24) = local_38;
        *(uint *)(param_1 + 0x28) = local_34;
        lVar3 = _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalRINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E8first_ofB4_
                          (param_1);
        do {
          if (*(ulonglong *)(lVar3 + 0x10) <= uVar8 + 1) {
                    /* WARNING: Subroutine does not return */
            _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
          }
          piVar1 = (int *)(*(longlong *)(lVar3 + 8) + 4 + uVar8 * 4);
          *piVar1 = *piVar1 + param_3;
          if (*(ulonglong *)(lVar3 + 0x10) <= uVar8 + 2) {
                    /* WARNING: Subroutine does not return */
            _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
          }
          piVar1 = (int *)(*(longlong *)(lVar3 + 8) + 8 + uVar8 * 4);
          *piVar1 = *piVar1 + param_3;
          uVar6 = *(ulonglong *)(lVar3 + 0x10);
          if (uVar6 <= uVar8) {
LAB_14000b04c:
                    /* WARNING: Subroutine does not return */
            _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
          }
          uVar4 = (ulonglong)*(int *)(*(longlong *)(lVar3 + 8) + uVar8 * 4);
          if (uVar4 != 0) {
            uVar6 = uVar8 + 3;
            uVar7 = 0;
            do {
              if (*(ulonglong *)(lVar3 + 0x10) <= uVar8) goto LAB_14000b04c;
              if ((ulonglong)(longlong)*(int *)(*(longlong *)(lVar3 + 8) + uVar8 * 4) <= uVar7) {
                    /* WARNING: Subroutine does not return */
                _RNvNtCsloaxXL3qbEI_4core9panicking5panic();
              }
              if (*(ulonglong *)(lVar3 + 0x10) <= uVar6) {
                    /* WARNING: Subroutine does not return */
                _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
              }
              piVar1 = (int *)(*(longlong *)(lVar3 + 8) + uVar6 * 4);
              *piVar1 = *piVar1 + param_2;
              uVar7 = uVar7 + 1;
              uVar6 = uVar6 + 1;
            } while (uVar4 != uVar7);
            uVar6 = *(ulonglong *)(lVar3 + 0x10);
          }
          if (uVar6 <= uVar8) goto LAB_14000b04c;
          uVar8 = uVar8 + (longlong)*(int *)(*(longlong *)(lVar3 + 8) + uVar8 * 4) + 4;
          uVar6 = uVar8;
          uVar5 = _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalQINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E13is_valid_scanB4__llvm_3083486868190693220
                            (lVar3,uVar8);
        } while ((char)uVar5 != '\0');
        lVar3 = _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalRINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E8first_ofB4_
                          (param_1);
        if (*(ulonglong *)(lVar3 + 0x10) <= uVar6 + 1) {
                    /* WARNING: Subroutine does not return */
          _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
        }
        *(undefined4 *)(*(longlong *)(lVar3 + 8) + 4 + uVar6 * 4) = 0x80000000;
        lVar3 = _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalQINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E7last_ofB4_
                          (param_1);
        if (*(ulonglong *)(lVar3 + 0x10) <= uVar6 + 2) {
                    /* WARNING: Subroutine does not return */
          _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
        }
        *(undefined4 *)(*(longlong *)(lVar3 + 8) + 8 + uVar6 * 4) = 0x7fffffff;
        uVar6 = 0;
      }
    }
  }
  if ((local_30 ^ (ulonglong)auStack_68) == __security_cookie) {
    return uVar6;
  }
  pcVar2 = (code *)swi(3);
  uVar6 = (*pcVar2)();
  return uVar6;
}



===== _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore17set_to_scans_from @ 14000b0b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
_RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore17set_to_scans_from
          (ulonglong *param_1,ulonglong *param_2)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  ulonglong uVar3;
  undefined4 *puVar4;
  code *pcVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  char *pcVar9;
  ulonglong uVar10;
  longlong lVar11;
  undefined4 *puVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  ulonglong uVar15;
  undefined1 auStack_98 [32];
  undefined **local_78;
  longlong local_70;
  undefined8 local_68;
  ulonglong local_60;
  int local_58 [2];
  ulonglong local_50;
  ulonglong *local_48;
  ulonglong local_40;
  ulonglong *local_38;
  longlong local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_98;
  if (param_1 != param_2) {
    uVar10 = *param_1;
    uVar3 = param_2[2];
    if (uVar10 < uVar3 && 0x1c < uVar3) {
      uVar13 = param_1[2];
      if (uVar10 - uVar13 < uVar3) {
        if (!CARRY8(uVar13,uVar3)) {
          uVar14 = uVar10 * 2;
          if (uVar10 * 2 < uVar13 + uVar3) {
            uVar14 = uVar13 + uVar3;
          }
          if (uVar14 * 4 < 0x7ffffffffffffffd && uVar14 >> 0x3e == 0) {
            if (uVar10 == 0) {
              local_38 = (ulonglong *)0x0;
            }
            else {
              local_40 = param_1[1];
              local_30 = uVar10 << 2;
              local_38 = (ulonglong *)0x4;
            }
            local_78 = (undefined **)(param_1 + 2);
            _RINvNtCsip5f2bf5HGI_5alloc7raw_vec11finish_growINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EECscIyU0BP6seX_7rgncore_llvm_13477870103536380358
                      ((ulonglong *)local_58,&DAT_00000004,uVar14 * 4,&local_40);
            if (local_58[0] != 1) {
              param_1[1] = local_50;
              *param_1 = uVar14;
              uVar10 = uVar14;
              goto LAB_14000b16d;
            }
          }
        }
        if ((local_28 ^ (ulonglong)auStack_98) == __security_cookie) {
          return 0xe;
        }
        goto LAB_14000b2b6;
      }
    }
    else if (0x1c < uVar10 && uVar3 < 0x1d) goto LAB_14000b332;
LAB_14000b16d:
    while( true ) {
      *(int *)(param_1 + 3) = (int)param_2[3];
      uVar8 = *(undefined8 *)((longlong)param_2 + 0x24);
      *(undefined8 *)((longlong)param_1 + 0x1c) = *(undefined8 *)((longlong)param_2 + 0x1c);
      *(undefined8 *)((longlong)param_1 + 0x24) = uVar8;
      param_1[2] = 0;
      puVar4 = (undefined4 *)param_2[1];
      if (uVar3 <= uVar10) break;
      uVar13 = uVar10 * 2;
      if (uVar10 * 2 < uVar3) {
        uVar13 = uVar3;
      }
      uVar14 = 4;
      if (4 < uVar13) {
        uVar14 = uVar13;
      }
      if (uVar10 >> 0x3c == 0) {
        if (uVar10 == 0) {
          local_38 = (ulonglong *)0x0;
        }
        else {
          local_40 = param_1[1];
          local_30 = uVar10 << 2;
          local_38 = (ulonglong *)0x4;
        }
        local_78 = (undefined **)(param_1 + 2);
        _RINvNtCsip5f2bf5HGI_5alloc7raw_vec11finish_growINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EECscIyU0BP6seX_7rgncore_llvm_13477870103536380358
                  ((ulonglong *)local_58,&DAT_00000004,uVar14 * 4,&local_40);
        if (local_58[0] != 1) {
          param_1[1] = local_50;
          *param_1 = uVar14;
          uVar10 = param_1[2];
          goto LAB_14000b19d;
        }
        local_40 = local_50;
        local_38 = local_48;
      }
      else {
        local_40 = 0;
        local_38 = param_1;
      }
      local_78 = &PTR_s_rgncore_src_lib_rs_140019610;
      pcVar9 = s_called__Result__unwrap____on_an___14001abf3;
      param_2 = (ulonglong *)0x2b;
      _RNvNtCsloaxXL3qbEI_4core6result13unwrap_failed();
      param_1 = (ulonglong *)pcVar9;
LAB_14000b332:
      local_70 = 0;
      local_68 = 4;
      local_78 = (undefined **)&local_60;
      local_60 = 0;
      local_38 = (ulonglong *)0x0;
      _RINvNtCsip5f2bf5HGI_5alloc7raw_vec11finish_growINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EECscIyU0BP6seX_7rgncore_llvm_13477870103536380358
                ((ulonglong *)local_58,&DAT_00000004,0x70,&local_40);
      uVar10 = local_50;
      if (local_58[0] == 1) {
        if (local_70 != 0) {
          if (local_70 == 0x1c) {
            _RNvNtCsjsHfHFRyfyy_10gdi_region3ffi22ScanLookAsideList_Free();
          }
          else {
            _RNvNtCsiNQa5DCRmUC_9gdi_alloc3ffi13Win32FreePool();
          }
        }
        uVar10 = *param_1;
      }
      else {
        if (*param_1 != 0) {
          if (*param_1 == 0x1c) {
            _RNvNtCsjsHfHFRyfyy_10gdi_region3ffi22ScanLookAsideList_Free();
          }
          else {
            _RNvNtCsiNQa5DCRmUC_9gdi_alloc3ffi13Win32FreePool();
          }
        }
        *param_1 = 0x1c;
        param_1[1] = uVar10;
        uVar10 = 0x1c;
      }
    }
    uVar10 = 0;
    if (uVar3 != 0) {
      local_50 = param_1[1];
LAB_14000b19d:
      uVar13 = uVar3 - 1 & 0x3fffffffffffffff;
      if ((uVar13 < 0xb) || ((local_50 + uVar10 * 4) - (longlong)puVar4 < 0x20)) {
        puVar12 = puVar4;
      }
      else {
        uVar13 = uVar13 + 1;
        lVar11 = uVar10 * 4;
        uVar14 = uVar13 & 0xfffffffffffffff8;
        puVar12 = puVar4 + uVar14;
        uVar10 = uVar10 + uVar14;
        lVar11 = lVar11 + local_50;
        uVar15 = 0;
        do {
          uVar8 = *(undefined8 *)((longlong)(puVar4 + uVar15) + 8);
          uVar6 = *(undefined8 *)(puVar4 + uVar15 + 4);
          uVar7 = *(undefined8 *)((longlong)(puVar4 + uVar15 + 4) + 8);
          puVar1 = (undefined8 *)(lVar11 + uVar15 * 4);
          *puVar1 = *(undefined8 *)(puVar4 + uVar15);
          puVar1[1] = uVar8;
          puVar1 = (undefined8 *)(lVar11 + 0x10 + uVar15 * 4);
          *puVar1 = uVar6;
          puVar1[1] = uVar7;
          uVar15 = uVar15 + 8;
        } while (uVar14 != uVar15);
        if (uVar13 == uVar14) goto LAB_14000b1e3;
      }
      do {
        uVar2 = *puVar12;
        puVar12 = puVar12 + 1;
        *(undefined4 *)(local_50 + uVar10 * 4) = uVar2;
        uVar10 = uVar10 + 1;
      } while (puVar12 != puVar4 + uVar3);
    }
LAB_14000b1e3:
    param_1[2] = uVar10;
  }
  if ((local_28 ^ (ulonglong)auStack_98) == __security_cookie) {
    return 0;
  }
LAB_14000b2b6:
  pcVar5 = (code *)swi(3);
  uVar8 = (*pcVar5)();
  return uVar8;
}



===== _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore27set_to_scans_from_no_resize @ 14000b4b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore27set_to_scans_from_no_resize
               (ulonglong *param_1,ulonglong *param_2)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  ulonglong uVar4;
  code *pcVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  ulonglong uVar9;
  char *pcVar10;
  ulonglong uVar11;
  undefined4 *puVar12;
  ulonglong *puVar13;
  ulonglong uVar14;
  ulonglong uVar15;
  longlong lVar16;
  undefined1 auStack_88 [32];
  undefined **local_68;
  int local_58 [2];
  ulonglong local_50;
  ulonglong *local_48;
  ulonglong local_40;
  ulonglong *local_38;
  longlong local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_88;
  if (param_1 == param_2) goto LAB_14000b547;
  *(int *)(param_1 + 3) = (int)param_2[3];
  uVar6 = *(undefined8 *)((longlong)param_2 + 0x24);
  *(undefined8 *)((longlong)param_1 + 0x1c) = *(undefined8 *)((longlong)param_2 + 0x1c);
  *(undefined8 *)((longlong)param_1 + 0x24) = uVar6;
  param_1[2] = 0;
  puVar3 = (undefined4 *)param_2[1];
  uVar4 = param_2[2];
  uVar9 = *param_1;
  if (uVar9 < uVar4) {
    uVar14 = uVar9 * 2;
    if (uVar9 * 2 < uVar4) {
      uVar14 = uVar4;
    }
    uVar11 = 4;
    if (4 < uVar14) {
      uVar11 = uVar14;
    }
    puVar13 = (ulonglong *)(uVar11 * 4);
    if (puVar13 < (ulonglong *)0x7ffffffffffffffd && uVar14 >> 0x3e == 0) goto LAB_14000b62d;
    local_40 = 0;
    while( true ) {
      local_68 = &PTR_s_rgncore_src_lib_rs_140019628;
      pcVar10 = s_called__Result__unwrap____on_an___14001abf3;
      puVar13 = &local_40;
      local_38 = param_1;
      uVar9 = _RNvNtCsloaxXL3qbEI_4core6result13unwrap_failed();
      param_1 = (ulonglong *)pcVar10;
LAB_14000b62d:
      if (uVar9 == 0) {
        local_38 = (ulonglong *)0x0;
      }
      else {
        local_40 = param_1[1];
        local_30 = uVar9 << 2;
        local_38 = (ulonglong *)0x4;
      }
      local_68 = (undefined **)(param_1 + 2);
      _RINvNtCsip5f2bf5HGI_5alloc7raw_vec11finish_growINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EECscIyU0BP6seX_7rgncore_llvm_13477870103536380358
                ((ulonglong *)local_58,&DAT_00000004,(ulonglong)puVar13,&local_40);
      if (local_58[0] != 1) break;
      local_40 = local_50;
      param_1 = local_48;
    }
    param_1[1] = local_50;
    *param_1 = uVar11;
    uVar9 = param_1[2];
LAB_14000b502:
    uVar14 = uVar4 - 1 & 0x3fffffffffffffff;
    if ((uVar14 < 0xb) || ((local_50 + uVar9 * 4) - (longlong)puVar3 < 0x20)) {
      puVar12 = puVar3;
    }
    else {
      uVar14 = uVar14 + 1;
      lVar16 = uVar9 * 4;
      uVar15 = uVar14 & 0xfffffffffffffff8;
      puVar12 = puVar3 + uVar15;
      uVar9 = uVar9 + uVar15;
      lVar16 = lVar16 + local_50;
      uVar11 = 0;
      do {
        uVar6 = *(undefined8 *)((longlong)(puVar3 + uVar11) + 8);
        uVar7 = *(undefined8 *)(puVar3 + uVar11 + 4);
        uVar8 = *(undefined8 *)((longlong)(puVar3 + uVar11 + 4) + 8);
        puVar1 = (undefined8 *)(lVar16 + uVar11 * 4);
        *puVar1 = *(undefined8 *)(puVar3 + uVar11);
        puVar1[1] = uVar6;
        puVar1 = (undefined8 *)(lVar16 + 0x10 + uVar11 * 4);
        *puVar1 = uVar7;
        puVar1[1] = uVar8;
        uVar11 = uVar11 + 8;
      } while (uVar15 != uVar11);
      if (uVar14 == uVar15) goto LAB_14000b543;
    }
    do {
      uVar2 = *puVar12;
      puVar12 = puVar12 + 1;
      *(undefined4 *)(local_50 + uVar9 * 4) = uVar2;
      uVar9 = uVar9 + 1;
    } while (puVar12 != puVar3 + uVar4);
  }
  else {
    uVar9 = 0;
    if (uVar4 != 0) {
      local_50 = param_1[1];
      goto LAB_14000b502;
    }
  }
LAB_14000b543:
  param_1[2] = uVar9;
LAB_14000b547:
  if ((local_28 ^ (ulonglong)auStack_88) == __security_cookie) {
    return;
  }
  pcVar5 = (code *)swi(3);
  (*pcVar5)();
  return;
}



===== _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore8subtract @ 14000b6b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Type propagation algorithm not settling */

ulonglong _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore8subtract
                    (ulonglong **param_1,uint *param_2,uint *param_3,ulonglong param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  longlong *plVar3;
  longlong lVar4;
  undefined **ppuVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  code *pcVar15;
  ulonglong *puVar16;
  ulonglong *puVar17;
  ulonglong *puVar18;
  byte bVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  int iVar24;
  int iVar25;
  undefined8 uVar26;
  ulonglong uVar27;
  undefined4 *puVar28;
  int *piVar29;
  ulonglong *puVar30;
  ulonglong uVar31;
  ulonglong uVar32;
  uint uVar33;
  byte bVar34;
  longlong *plVar35;
  ulonglong uVar36;
  ulonglong uVar37;
  ulonglong uVar38;
  longlong lVar39;
  ulonglong uVar40;
  undefined1 auStackY_1a8 [32];
  ulonglong *local_178;
  ulonglong *local_128;
  uint uStack_120;
  uint uStack_11c;
  undefined4 uStack_118;
  uint uStack_114;
  uint uStack_110;
  int iStack_10c;
  undefined4 uStack_108;
  int iStack_104;
  undefined4 uStack_100;
  undefined4 local_fc;
  ulonglong *local_f8;
  uint uStack_f0;
  uint uStack_ec;
  undefined8 uStack_e8;
  undefined8 uStack_e0;
  undefined4 local_d8;
  undefined8 local_c8;
  uint uStack_c0;
  uint uStack_bc;
  undefined8 uStack_b8;
  uint uStack_b0;
  int iStack_ac;
  undefined4 uStack_a8;
  int iStack_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  ulonglong local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  ulonglong *local_60;
  longlong *local_58;
  ulonglong local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_1a8;
  uVar6 = *param_2;
  uVar7 = param_2[2];
  if (uVar6 != uVar7) {
    uVar33 = param_2[1];
    uVar8 = param_2[3];
    if (uVar33 != uVar8) {
      if (param_4 != 1) {
        puVar30 = (ulonglong *)0x1c;
        if ((ulonglong *)0x1c < param_1[2]) {
          puVar30 = param_1[2];
        }
        local_90 = 0;
        local_88 = 4;
        local_80 = 0;
        local_58 = (longlong *)0x0;
        _RINvNtCsip5f2bf5HGI_5alloc7raw_vec11finish_growINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EECscIyU0BP6seX_7rgncore_llvm_13477870103536380358
                  (&local_78,&DAT_00000004,(longlong)puVar30 * 4,&local_60);
        if ((int)local_78 == 1) {
          if (local_90 != 0) {
            if (local_90 != 0x1c) {
              _RNvNtCsiNQa5DCRmUC_9gdi_alloc3ffi13Win32FreePool();
              uVar38 = 0xe;
              uVar27 = CONCAT44(uStack_b8._4_4_,(undefined4)uStack_b8);
              uVar40 = CONCAT44(uStack_e8._4_4_,(int)uStack_e8);
              goto LAB_14000c4d1;
            }
            _RNvNtCsjsHfHFRyfyy_10gdi_region3ffi22ScanLookAsideList_Free();
          }
          uVar38 = 0xe;
          uVar27 = CONCAT44(uStack_b8._4_4_,(undefined4)uStack_b8);
          uVar40 = CONCAT44(uStack_e8._4_4_,(int)uStack_e8);
          goto LAB_14000c4d1;
        }
        uStack_c0 = (uint)local_70;
        uStack_bc = (uint)((ulonglong)local_70 >> 0x20);
        uStack_b8._0_4_ = (undefined4)local_80;
        uStack_b8._4_4_ = (uint)((ulonglong)local_80 >> 0x20);
        uStack_b0 = 0;
        iStack_ac = 0;
        uStack_a8 = 0;
        iStack_a4 = 0;
        local_a0 = 0;
        local_c8 = puVar30;
        _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore16set_to_null_scan(&local_c8);
        uVar38 = (ulonglong)uStack_c0;
        local_f8 = (ulonglong *)CONCAT44((undefined4)uStack_b8,uStack_bc);
        uStack_f0 = uStack_b8._4_4_;
        uStack_ec = uStack_b0;
        uStack_e0 = CONCAT44(local_a0,iStack_a4);
        uStack_e8._0_4_ = iStack_ac;
        uStack_e8._4_4_ = uStack_a8;
        local_d8 = local_9c;
        uVar27 = CONCAT44(uStack_b8._4_4_,(undefined4)uStack_b8);
        uVar40 = CONCAT44(uStack_a8,iStack_ac);
        if (local_c8 == (ulonglong *)0x8000000000000000) goto LAB_14000c4d1;
        local_fc = local_9c;
        iStack_10c = iStack_ac;
        uStack_108 = uStack_a8;
        iStack_104 = iStack_a4;
        uStack_100 = local_a0;
        uStack_11c = uStack_bc;
        uStack_118 = (undefined4)uStack_b8;
        uStack_114 = uStack_b8._4_4_;
        uStack_110 = uStack_b0;
        local_128 = local_c8;
        uStack_120 = uStack_c0;
        if (&local_128 != param_1) {
          uStack_110 = *(uint *)(param_1 + 3);
          iStack_10c = (int)*(undefined8 *)((longlong)param_1 + 0x1c);
          uStack_108 = (undefined4)((ulonglong)*(undefined8 *)((longlong)param_1 + 0x1c) >> 0x20);
          iStack_104 = (int)*(undefined8 *)((longlong)param_1 + 0x24);
          uStack_100 = (undefined4)((ulonglong)*(undefined8 *)((longlong)param_1 + 0x24) >> 0x20);
          uStack_118 = 0;
          uStack_114 = 0;
          puVar30 = param_1[1];
          local_c8 = (ulonglong *)
                     _RNvXCsgf1RBdmyjwT_12fallible_vecINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEINtB2_11FallibleVeclB12_E21try_extend_from_sliceCscIyU0BP6seX_7rgncore
                               ((ulonglong *)&local_128,(undefined4 *)puVar30,(ulonglong)param_1[2])
          ;
          if (local_c8 != (ulonglong *)0x8000000000000001) {
            uStack_c0 = (uint)puVar30;
            uStack_bc = (uint)((ulonglong)puVar30 >> 0x20);
            _RNvNtCsloaxXL3qbEI_4core6result13unwrap_failed();
LAB_14000cfaa:
                    /* WARNING: Subroutine does not return */
            _RNvNtCsloaxXL3qbEI_4core9panicking5panic();
          }
        }
        local_c8 = (ulonglong *)0x0;
        uStack_c0 = 8;
        uStack_bc = 0;
        uStack_b8._0_4_ = 0;
        uStack_b8._4_4_ = 0;
        uVar27 = _RNvMs2_NtCsip5f2bf5HGI_5alloc7raw_vecNtB5_11RawVecInner11try_reserveCscIyU0BP6seX_7rgncore
                           (&local_c8,0,param_4,&DAT_00000008,8);
        if (uVar27 == 0x8000000000000001) {
          if (param_4 != 0) {
            lVar39 = param_4 << 4;
            do {
              uVar27 = _RNvMs2_NtCsip5f2bf5HGI_5alloc7raw_vecNtB5_11RawVecInner11try_reserveCscIyU0BP6seX_7rgncore
                                 (&local_c8,uStack_b8,1,&DAT_00000008,8);
              if (uVar27 != 0x8000000000000001) goto LAB_14000bd6b;
              *(uint **)(CONCAT44(uStack_bc,uStack_c0) + uStack_b8 * 8) = param_3;
              param_3 = param_3 + 4;
              uStack_b8 = uStack_b8 + 1;
              lVar39 = lVar39 + -0x10;
            } while (lVar39 != 0);
          }
          uVar38 = 0xe;
          if (local_c8 != (ulonglong *)0x8000000000000000) {
            local_58 = (longlong *)CONCAT44(uStack_bc,uStack_c0);
            local_60 = local_c8;
            local_c8 = &local_90;
            local_50 = uStack_b8;
            if (1 < uStack_b8) {
              if (uStack_b8 < 0x15) {
                _RINvNtNtNtNtCsloaxXL3qbEI_4core5slice4sort6shared9smallsort25insertion_sort_shift_leftRNtNtCs2JCLxFJL4Mh_15onecore_windows6windef6__RECTLNCINvMB8_SB1m_20sort_unstable_by_keylNCNvMs_CscIyU0BP6seX_7rgncoreNtB2T_10RegionCore16subtract_complex0E0EB2T_
                          (local_58,uStack_b8,1);
              }
              else {
                _RINvNtNtNtCsloaxXL3qbEI_4core5slice4sort8unstable7ipnsortRNtNtCs2JCLxFJL4Mh_15onecore_windows6windef6__RECTLNCINvMB6_SBT_20sort_unstable_by_keylNCNvMs_CscIyU0BP6seX_7rgncoreNtB2p_10RegionCore16subtract_complex0E0EB2p_
                          (local_58,uStack_b8,&local_c8);
              }
            }
            local_78._0_4_ = 0;
            local_70 = 0x7fffffff00000000;
            local_78._4_4_ = uVar8;
            uVar27 = _RNvXCsgf1RBdmyjwT_12fallible_vecINtNtCsip5f2bf5HGI_5alloc3vec3VecRNtNtCs2JCLxFJL4Mh_15onecore_windows6windef6__RECTLEINtB2_11FallibleVecB11_NtNtBz_5alloc6GlobalE8try_pushCscIyU0BP6seX_7rgncore
                               ((ulonglong *)&local_60,&local_78);
            uVar38 = 0xe;
            if (uVar27 == 0x8000000000000001) {
              _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore16set_to_null_scan
                        ((ulonglong *)&local_128);
              iStack_10c = 0x7fffffff;
              iStack_104 = -0x80000000;
              if (local_50 != 0) {
                uVar27 = 0;
                do {
                  if ((int)uVar33 < *(int *)(local_58[uVar27] + 0xc)) {
                    uVar40 = uVar27;
                    goto LAB_14000c61d;
                  }
                  uVar27 = uVar27 + 1;
                } while (local_50 != uVar27);
              }
                    /* WARNING: Subroutine does not return */
              _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
            }
            goto LAB_14000cc9a;
          }
        }
        else {
LAB_14000bd6b:
          if (local_c8 != (ulonglong *)0x0) {
            _RNvCs8cVqplN8eB1_7___rustc14___rust_dealloc();
          }
          uVar38 = 0xe;
        }
LAB_14000bd95:
        if (CONCAT44(uStack_114,uStack_118) == 0) goto LAB_14000bda5;
        goto LAB_14000bdb7;
      }
      uVar20 = param_3[1];
      if (((((int)uVar8 <= (int)uVar20) || (uVar23 = *param_3, (int)uVar7 <= (int)uVar23)) ||
          (uVar22 = param_3[3], (int)uVar22 <= (int)uVar33)) ||
         (uVar9 = param_3[2], (int)uVar9 <= (int)uVar6)) {
LAB_14000c4c9:
        _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore16set_to_rectangle
                  ((ulonglong *)param_1,(int *)param_2);
        goto LAB_14000c4ce;
      }
      bVar34 = ((int)uVar8 <= (int)uVar22) + 2;
      if ((int)uVar20 <= (int)uVar33) {
        bVar34 = (int)uVar8 <= (int)uVar22;
      }
      bVar19 = (int)uVar7 <= (int)uVar9;
      if ((int)uVar6 < (int)uVar23) {
        bVar19 = (int)uVar9 < (int)uVar7 ^ 3;
      }
      if (bVar34 < 2) {
        if (bVar34 != 0) {
          if (bVar19 < 2) {
            if (bVar19 != 0) goto LAB_14000b6e8;
            local_c8 = (ulonglong *)CONCAT44(uVar33,uVar9);
LAB_14000c12b:
            uStack_c0 = uVar7;
          }
          else {
            if (bVar19 == 2) {
              _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore23clear_scans_and_reserve
                        ((undefined4 *)&local_c8,(ulonglong *)param_1,0x10);
              if (((ulonglong)local_c8 & 1) != 0) goto LAB_14000c51f;
              local_178 = (ulonglong *)CONCAT44(uStack_bc,uStack_c0);
              uVar26 = *(undefined8 *)(param_2 + 2);
              *(undefined8 *)((longlong)local_178 + 0x1c) = *(undefined8 *)param_2;
              *(undefined8 *)((longlong)local_178 + 0x24) = uVar26;
              uVar26 = _RNvMs5_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE11append_scan
                                 (local_178,0x80000000,uVar33,(undefined4 *)&DAT_00000004,0);
              uVar22 = (uint)uVar26;
              if (uVar22 == 0) {
                local_c8 = (ulonglong *)CONCAT44(uVar23,uVar6);
                uStack_c0 = uVar9;
                uStack_bc = uVar7;
                uVar26 = _RNvMs5_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE11append_scan
                                   (local_178,uVar33,uVar8,(undefined4 *)&local_c8,4);
                uVar22 = (uint)uVar26;
                if (uVar22 != 0) goto LAB_14000c5ea;
LAB_14000c5c3:
                uVar26 = _RNvMs5_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE11append_scan
                                   (local_178,uVar8,0x7fffffff,(undefined4 *)&DAT_00000004,0);
                uVar40 = CONCAT44(uStack_e8._4_4_,(int)uStack_e8);
                uVar27 = CONCAT44(uStack_b8._4_4_,(undefined4)uStack_b8);
                uVar22 = (uint)uVar26;
                if (uVar22 != 0) goto LAB_14000c5ea;
                uVar38 = 0;
                uVar13 = local_178[2];
              }
              else {
LAB_14000c5ea:
                uVar40 = CONCAT44(uStack_e8._4_4_,(int)uStack_e8);
                uVar27 = CONCAT44(uStack_b8._4_4_,(undefined4)uStack_b8);
                uVar38 = (ulonglong)uVar22;
                uVar13 = local_178[2];
              }
              if (uVar13 != 0) goto LAB_14000c4d1;
              goto LAB_14000c5fb;
            }
            local_c8 = (ulonglong *)CONCAT44(uVar33,uVar6);
            uStack_c0 = uVar23;
          }
          uStack_bc = uVar8;
          goto LAB_14000c4c1;
        }
        if (1 < bVar19) {
          if (bVar19 == 2) {
            _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore23clear_scans_and_reserve
                      ((undefined4 *)&local_c8,(ulonglong *)param_1,0x16);
            if (((ulonglong)local_c8 & 1) == 0) {
              local_178 = (ulonglong *)CONCAT44(uStack_bc,uStack_c0);
              uVar26 = *(undefined8 *)(param_2 + 2);
              *(undefined8 *)((longlong)local_178 + 0x1c) = *(undefined8 *)param_2;
              *(undefined8 *)((longlong)local_178 + 0x24) = uVar26;
              uVar26 = _RNvMs5_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE11append_scan
                                 (local_178,0x80000000,uVar33,(undefined4 *)&DAT_00000004,0);
              uVar20 = (uint)uVar26;
              if (uVar20 == 0) {
                local_c8 = (ulonglong *)CONCAT44(uVar23,uVar6);
                uVar27 = 4;
                uStack_c0 = uVar9;
                uStack_bc = uVar7;
                goto LAB_14000c2e3;
              }
              goto LAB_14000c354;
            }
          }
          else {
            _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore23clear_scans_and_reserve
                      ((undefined4 *)&local_c8,(ulonglong *)param_1,0x14);
            if (((ulonglong)local_c8 & 1) == 0) {
              local_178 = (ulonglong *)CONCAT44(uStack_bc,uStack_c0);
              uVar26 = *(undefined8 *)(param_2 + 2);
              *(undefined8 *)((longlong)local_178 + 0x1c) = *(undefined8 *)param_2;
              *(undefined8 *)((longlong)local_178 + 0x24) = uVar26;
              uVar26 = _RNvMs5_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE11append_scan
                                 (local_178,0x80000000,uVar33,(undefined4 *)&DAT_00000004,0);
              uVar20 = (uint)uVar26;
              if (uVar20 == 0) {
                local_c8 = (ulonglong *)CONCAT44(uVar23,uVar6);
                goto LAB_14000c2da;
              }
              goto LAB_14000c354;
            }
          }
          goto LAB_14000c51f;
        }
        if (bVar19 != 0) {
          local_c8 = (ulonglong *)CONCAT44(uVar22,uVar6);
          goto LAB_14000c12b;
        }
        _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore23clear_scans_and_reserve
                  ((undefined4 *)&local_c8,(ulonglong *)param_1,0x14);
        if (((ulonglong)local_c8 & 1) != 0) goto LAB_14000c51f;
        local_178 = (ulonglong *)CONCAT44(uStack_bc,uStack_c0);
        uVar26 = *(undefined8 *)(param_2 + 2);
        *(undefined8 *)((longlong)local_178 + 0x1c) = *(undefined8 *)param_2;
        *(undefined8 *)((longlong)local_178 + 0x24) = uVar26;
        uVar26 = _RNvMs5_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE11append_scan
                           (local_178,0x80000000,uVar33,(undefined4 *)&DAT_00000004,0);
        uVar20 = (uint)uVar26;
        if (uVar20 == 0) {
          local_c8 = (ulonglong *)CONCAT44(uVar7,uVar9);
LAB_14000c2da:
          uVar27 = 2;
LAB_14000c2e3:
          uVar26 = _RNvMs5_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE11append_scan
                             (local_178,uVar33,uVar22,(undefined4 *)&local_c8,uVar27);
          uVar20 = (uint)uVar26;
          if (uVar20 != 0) goto LAB_14000c354;
          local_c8 = (ulonglong *)CONCAT44(uVar7,uVar6);
          uVar26 = _RNvMs5_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE11append_scan
                             (local_178,uVar22,uVar8,(undefined4 *)&local_c8,2);
          uVar20 = (uint)uVar26;
          if (uVar20 != 0) goto LAB_14000c354;
          uVar26 = _RNvMs5_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE11append_scan
                             (local_178,uVar8,0x7fffffff,(undefined4 *)&DAT_00000004,0);
          uVar40 = CONCAT44(uStack_e8._4_4_,(int)uStack_e8);
          uVar27 = CONCAT44(uStack_b8._4_4_,(undefined4)uStack_b8);
          uVar20 = (uint)uVar26;
          if (uVar20 != 0) goto LAB_14000c354;
          uVar38 = 0;
          uVar13 = local_178[2];
        }
        else {
LAB_14000c354:
          uVar40 = CONCAT44(uStack_e8._4_4_,(int)uStack_e8);
          uVar27 = CONCAT44(uStack_b8._4_4_,(undefined4)uStack_b8);
          uVar38 = (ulonglong)uVar20;
          uVar13 = local_178[2];
        }
        if (uVar13 != 0) goto LAB_14000c4d1;
      }
      else {
        if (bVar34 != 2) {
          if (1 < bVar19) {
            if (bVar19 == 2) {
              _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore23clear_scans_and_reserve
                        ((undefined4 *)&local_c8,(ulonglong *)param_1,0x16);
              if (((ulonglong)local_c8 & 1) == 0) {
                local_178 = (ulonglong *)CONCAT44(uStack_bc,uStack_c0);
                uVar26 = *(undefined8 *)(param_2 + 2);
                *(undefined8 *)((longlong)local_178 + 0x1c) = *(undefined8 *)param_2;
                *(undefined8 *)((longlong)local_178 + 0x24) = uVar26;
                uVar26 = _RNvMs5_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE11append_scan
                                   (local_178,0x80000000,uVar33,(undefined4 *)&DAT_00000004,0);
                uVar22 = (uint)uVar26;
                if (uVar22 == 0) {
                  local_c8 = (ulonglong *)CONCAT44(uVar7,uVar6);
                  uVar26 = _RNvMs5_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE11append_scan
                                     (local_178,uVar33,uVar20,(undefined4 *)&local_c8,2);
                  uVar22 = (uint)uVar26;
                  if (uVar22 == 0) {
                    local_c8 = (ulonglong *)CONCAT44(uVar23,uVar6);
                    uVar27 = 4;
                    uStack_c0 = uVar9;
                    uStack_bc = uVar7;
                    goto LAB_14000c5a9;
                  }
                }
                goto LAB_14000c5ea;
              }
            }
            else {
              _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore23clear_scans_and_reserve
                        ((undefined4 *)&local_c8,(ulonglong *)param_1,0x14);
              if (((ulonglong)local_c8 & 1) == 0) {
                local_178 = (ulonglong *)CONCAT44(uStack_bc,uStack_c0);
                uVar26 = *(undefined8 *)(param_2 + 2);
                *(undefined8 *)((longlong)local_178 + 0x1c) = *(undefined8 *)param_2;
                *(undefined8 *)((longlong)local_178 + 0x24) = uVar26;
                uVar26 = _RNvMs5_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE11append_scan
                                   (local_178,0x80000000,uVar33,(undefined4 *)&DAT_00000004,0);
                uVar22 = (uint)uVar26;
                if (uVar22 == 0) {
                  local_c8 = (ulonglong *)CONCAT44(uVar7,uVar6);
                  uVar26 = _RNvMs5_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE11append_scan
                                     (local_178,uVar33,uVar20,(undefined4 *)&local_c8,2);
                  uVar22 = (uint)uVar26;
                  if (uVar22 == 0) {
                    local_c8 = (ulonglong *)CONCAT44(uVar23,uVar6);
                    goto LAB_14000c5a0;
                  }
                }
                goto LAB_14000c5ea;
              }
            }
            goto LAB_14000c51f;
          }
          if (bVar19 == 0) {
            _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore23clear_scans_and_reserve
                      ((undefined4 *)&local_c8,(ulonglong *)param_1,0x14);
            if (((ulonglong)local_c8 & 1) == 0) {
              local_178 = (ulonglong *)CONCAT44(uStack_bc,uStack_c0);
              uVar26 = *(undefined8 *)(param_2 + 2);
              *(undefined8 *)((longlong)local_178 + 0x1c) = *(undefined8 *)param_2;
              *(undefined8 *)((longlong)local_178 + 0x24) = uVar26;
              uVar26 = _RNvMs5_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE11append_scan
                                 (local_178,0x80000000,uVar33,(undefined4 *)&DAT_00000004,0);
              uVar22 = (uint)uVar26;
              if (uVar22 == 0) {
                local_c8 = (ulonglong *)CONCAT44(uVar7,uVar6);
                uVar26 = _RNvMs5_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE11append_scan
                                   (local_178,uVar33,uVar20,(undefined4 *)&local_c8,2);
                uVar22 = (uint)uVar26;
                if (uVar22 == 0) {
                  local_c8 = (ulonglong *)CONCAT44(uVar7,uVar9);
LAB_14000c5a0:
                  uVar27 = 2;
LAB_14000c5a9:
                  uVar26 = _RNvMs5_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE11append_scan
                                     (local_178,uVar20,uVar8,(undefined4 *)&local_c8,uVar27);
                  uVar22 = (uint)uVar26;
                  if (uVar22 == 0) goto LAB_14000c5c3;
                }
              }
              goto LAB_14000c5ea;
            }
            goto LAB_14000c51f;
          }
          local_c8 = (ulonglong *)CONCAT44(uVar33,uVar6);
          uStack_c0 = uVar7;
          uStack_bc = uVar20;
LAB_14000c4c1:
          param_2 = (uint *)&local_c8;
          goto LAB_14000c4c9;
        }
        if (1 < bVar19) {
          if (bVar19 == 2) {
            _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore23clear_scans_and_reserve
                      ((undefined4 *)&local_c8,(ulonglong *)param_1,0x1c);
            if (((ulonglong)local_c8 & 1) == 0) {
              local_178 = (ulonglong *)CONCAT44(uStack_bc,uStack_c0);
              uVar26 = *(undefined8 *)(param_2 + 2);
              *(undefined8 *)((longlong)local_178 + 0x1c) = *(undefined8 *)param_2;
              *(undefined8 *)((longlong)local_178 + 0x24) = uVar26;
              uVar26 = _RNvMs5_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE11append_scan
                                 (local_178,0x80000000,uVar33,(undefined4 *)&DAT_00000004,0);
              uVar21 = (uint)uVar26;
              if (uVar21 == 0) {
                local_c8 = (ulonglong *)CONCAT44(uVar7,uVar6);
                uVar26 = _RNvMs5_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE11append_scan
                                   (local_178,uVar33,uVar20,(undefined4 *)&local_c8,2);
                uVar21 = (uint)uVar26;
                if (uVar21 == 0) {
                  local_c8 = (ulonglong *)CONCAT44(uVar23,uVar6);
                  uStack_c0 = uVar9;
                  uStack_bc = uVar7;
                  uVar26 = _RNvMs5_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE11append_scan
                                     (local_178,uVar20,uVar22,(undefined4 *)&local_c8,4);
                  uVar21 = (uint)uVar26;
                  if (uVar21 != 0) goto LAB_14000cc49;
                  local_c8 = (ulonglong *)CONCAT44(uVar7,uVar6);
                  uVar26 = _RNvMs5_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE11append_scan
                                     (local_178,uVar22,uVar8,(undefined4 *)&local_c8,2);
                  uVar21 = (uint)uVar26;
                  if (uVar21 == 0) {
                    uVar26 = _RNvMs5_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE11append_scan
                                       (local_178,uVar8,0x7fffffff,(undefined4 *)&DAT_00000004,0);
                    uVar21 = (uint)uVar26;
                    if (uVar21 == 0) {
                      uVar38 = 0;
                      uVar27 = CONCAT44(uStack_b8._4_4_,(undefined4)uStack_b8);
                      uVar40 = CONCAT44(uStack_e8._4_4_,(int)uStack_e8);
                      if (local_178[2] != 0) goto LAB_14000c4d1;
                      goto LAB_14000c5fb;
                    }
                  }
                }
              }
              uVar40 = CONCAT44(uStack_e8._4_4_,(int)uStack_e8);
              uVar27 = CONCAT44(uStack_b8._4_4_,(undefined4)uStack_b8);
              uVar13 = local_178[2];
              goto joined_r0x00014000bf26;
            }
          }
          else {
            _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore23clear_scans_and_reserve
                      ((undefined4 *)&local_c8,(ulonglong *)param_1,0x1a);
            if (((ulonglong)local_c8 & 1) == 0) {
              local_178 = (ulonglong *)CONCAT44(uStack_bc,uStack_c0);
              uVar26 = *(undefined8 *)(param_2 + 2);
              *(undefined8 *)((longlong)local_178 + 0x1c) = *(undefined8 *)param_2;
              *(undefined8 *)((longlong)local_178 + 0x24) = uVar26;
              uVar26 = _RNvMs5_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE11append_scan
                                 (local_178,0x80000000,uVar33,(undefined4 *)&DAT_00000004,0);
              uVar21 = (uint)uVar26;
              if (uVar21 == 0) {
                local_c8 = (ulonglong *)CONCAT44(uVar7,uVar6);
                uVar26 = _RNvMs5_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE11append_scan
                                   (local_178,uVar33,uVar20,(undefined4 *)&local_c8,2);
                uVar21 = (uint)uVar26;
                if (uVar21 == 0) {
                  local_c8 = (ulonglong *)CONCAT44(uVar23,uVar6);
                  goto LAB_14000c40a;
                }
              }
              goto LAB_14000c490;
            }
          }
LAB_14000c51f:
          uVar38 = (ulonglong)local_c8 >> 0x20;
          uVar27 = CONCAT44(uStack_b8._4_4_,(undefined4)uStack_b8);
          uVar40 = CONCAT44(uStack_e8._4_4_,(int)uStack_e8);
          goto LAB_14000c4d1;
        }
        if (bVar19 == 0) {
          _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore23clear_scans_and_reserve
                    ((undefined4 *)&local_c8,(ulonglong *)param_1,0x1a);
          if (((ulonglong)local_c8 & 1) != 0) goto LAB_14000c51f;
          local_178 = (ulonglong *)CONCAT44(uStack_bc,uStack_c0);
          uVar26 = *(undefined8 *)(param_2 + 2);
          *(undefined8 *)((longlong)local_178 + 0x1c) = *(undefined8 *)param_2;
          *(undefined8 *)((longlong)local_178 + 0x24) = uVar26;
          uVar26 = _RNvMs5_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE11append_scan
                             (local_178,0x80000000,uVar33,(undefined4 *)&DAT_00000004,0);
          uVar21 = (uint)uVar26;
          if (uVar21 == 0) {
            local_c8 = (ulonglong *)CONCAT44(uVar7,uVar6);
            uVar26 = _RNvMs5_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE11append_scan
                               (local_178,uVar33,uVar20,(undefined4 *)&local_c8,2);
            uVar21 = (uint)uVar26;
            if (uVar21 == 0) {
              local_c8 = (ulonglong *)CONCAT44(uVar7,uVar9);
LAB_14000c40a:
              uVar26 = _RNvMs5_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE11append_scan
                                 (local_178,uVar20,uVar22,(undefined4 *)&local_c8,2);
              uVar21 = (uint)uVar26;
              if (uVar21 != 0) {
LAB_14000cc49:
                uVar40 = CONCAT44(uStack_e8._4_4_,(int)uStack_e8);
                uVar27 = CONCAT44(uStack_b8._4_4_,(undefined4)uStack_b8);
                uVar13 = local_178[2];
                goto joined_r0x00014000bf26;
              }
              local_c8 = (ulonglong *)CONCAT44(uVar7,uVar6);
              uVar26 = _RNvMs5_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE11append_scan
                                 (local_178,uVar22,uVar8,(undefined4 *)&local_c8,2);
              uVar21 = (uint)uVar26;
              if (uVar21 != 0) goto LAB_14000c490;
              uVar26 = _RNvMs5_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE11append_scan
                                 (local_178,uVar8,0x7fffffff,(undefined4 *)&DAT_00000004,0);
              uVar21 = (uint)uVar26;
              if (uVar21 != 0) goto LAB_14000c490;
              uVar38 = 0;
              uVar27 = CONCAT44(uStack_b8._4_4_,(undefined4)uStack_b8);
              uVar40 = CONCAT44(uStack_e8._4_4_,(int)uStack_e8);
              if (local_178[2] != 0) goto LAB_14000c4d1;
              goto LAB_14000c5fb;
            }
          }
LAB_14000c490:
          uVar40 = CONCAT44(uStack_e8._4_4_,(int)uStack_e8);
          uVar27 = CONCAT44(uStack_b8._4_4_,(undefined4)uStack_b8);
          uVar13 = local_178[2];
joined_r0x00014000bf26:
          uVar38 = (ulonglong)uVar21;
          if (uVar13 != 0) goto LAB_14000c4d1;
          goto LAB_14000c5fb;
        }
        _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore23clear_scans_and_reserve
                  ((undefined4 *)&local_c8,(ulonglong *)param_1,0x18);
        if (((ulonglong)local_c8 & 1) != 0) goto LAB_14000c51f;
        local_178 = (ulonglong *)CONCAT44(uStack_bc,uStack_c0);
        uVar26 = *(undefined8 *)(param_2 + 2);
        *(undefined8 *)((longlong)local_178 + 0x1c) = *(undefined8 *)param_2;
        *(undefined8 *)((longlong)local_178 + 0x24) = uVar26;
        uVar26 = _RNvMs5_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE11append_scan
                           (local_178,0x80000000,uVar33,(undefined4 *)&DAT_00000004,0);
        uVar23 = (uint)uVar26;
        if (uVar23 == 0) {
          local_c8 = (ulonglong *)CONCAT44(uVar7,uVar6);
          uVar26 = _RNvMs5_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE11append_scan
                             (local_178,uVar33,uVar20,(undefined4 *)&local_c8,2);
          uVar23 = (uint)uVar26;
          if (uVar23 != 0) goto LAB_14000c239;
          uVar26 = _RNvMs5_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE11append_scan
                             (local_178,uVar20,uVar22,(undefined4 *)&DAT_00000004,0);
          uVar23 = (uint)uVar26;
          if (uVar23 != 0) goto LAB_14000c239;
          local_c8 = (ulonglong *)CONCAT44(uVar7,uVar6);
          uVar26 = _RNvMs5_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE11append_scan
                             (local_178,uVar22,uVar8,(undefined4 *)&local_c8,2);
          uVar23 = (uint)uVar26;
          if (uVar23 != 0) goto LAB_14000c239;
          uVar26 = _RNvMs5_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE11append_scan
                             (local_178,uVar8,0x7fffffff,(undefined4 *)&DAT_00000004,0);
          uVar40 = CONCAT44(uStack_e8._4_4_,(int)uStack_e8);
          uVar27 = CONCAT44(uStack_b8._4_4_,(undefined4)uStack_b8);
          uVar23 = (uint)uVar26;
          if (uVar23 != 0) goto LAB_14000c239;
          uVar38 = 0;
          uVar13 = local_178[2];
        }
        else {
LAB_14000c239:
          uVar40 = CONCAT44(uStack_e8._4_4_,(int)uStack_e8);
          uVar27 = CONCAT44(uStack_b8._4_4_,(undefined4)uStack_b8);
          uVar38 = (ulonglong)uVar23;
          uVar13 = local_178[2];
        }
        if (uVar13 != 0) goto LAB_14000c4d1;
      }
LAB_14000c5fb:
      _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore16set_to_null_scan(local_178);
      uVar27 = CONCAT44(uStack_b8._4_4_,(undefined4)uStack_b8);
      uVar40 = CONCAT44(uStack_e8._4_4_,(int)uStack_e8);
      goto LAB_14000c4d1;
    }
  }
LAB_14000b6e8:
  _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore16set_to_null_scan((ulonglong *)param_1);
  goto LAB_14000c4ce;
LAB_14000c9fb:
  if (uVar31 <= uVar13) {
LAB_14000d093:
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
  }
  uVar37 = uVar38 + uVar32;
  if (uVar31 <= uVar37) {
LAB_14000d087:
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
  }
  iVar24 = iVar10;
LAB_14000ca47:
  *(int *)(uVar14 + uVar37 * 4) = iVar24;
LAB_14000ca4b:
  uVar38 = uVar38 + 2;
  uVar31 = puVar30[2];
  if (uVar31 <= uVar13) goto LAB_14000d00b;
  goto LAB_14000c906;
LAB_14000c61d:
  do {
    _RNvMs5_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE3new
              (&local_c8,(ulonglong *)&local_128,uVar33,uVar33,2);
    puVar30 = local_c8;
    uVar38 = (ulonglong)uStack_c0;
    if (local_c8 == (ulonglong *)0x0) goto LAB_14000cc9a;
    uStack_ec = uStack_bc;
    local_f8 = local_c8;
    uStack_f0 = uStack_c0;
    uStack_e8 = uStack_b8;
    uVar26 = _RNvMs4_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE11append_wallB7_
                       ((longlong *)&local_f8,uVar6);
    uVar20 = (uint)uVar26;
    if (uVar20 != 0) {
LAB_14000cbf4:
      uVar38 = (ulonglong)uVar20;
LAB_14000cc8d:
      _RNvXs6_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EENtNtNtCsloaxXL3qbEI_4core3ops4drop4Drop4dropB7_
                ((longlong *)&local_f8);
      goto LAB_14000cc9a;
    }
    uVar26 = _RNvMs4_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE11append_wallB7_
                       ((longlong *)&local_f8,uVar7);
    uVar13 = uStack_e8;
    uVar20 = (uint)uVar26;
    if (uVar20 != 0) goto LAB_14000cbf4;
    if (local_50 <= uVar27) {
                    /* WARNING: Subroutine does not return */
      _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
    }
    iVar25 = *(int *)(local_58[uVar27] + 4);
    uVar1 = uStack_e8 + 2;
    if ((int)uVar33 < iVar25) {
      if (puVar30[2] <= uVar1) goto LAB_14000d0ae;
      *(int *)(puVar30[1] + 8 + uStack_e8 * 4) = iVar25;
    }
    else {
      if (puVar30[2] <= uVar1) {
LAB_14000d0ae:
                    /* WARNING: Subroutine does not return */
        _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
      }
      *(undefined4 *)(puVar30[1] + 8 + uStack_e8 * 4) = *(undefined4 *)(local_58[uVar27] + 0xc);
      while( true ) {
        if (local_50 <= uVar40) {
                    /* WARNING: Subroutine does not return */
          _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
        }
        iVar25 = *(int *)(local_58[uVar40] + 4);
        if ((int)uVar33 < iVar25) break;
        if (puVar30[2] <= uVar1) goto LAB_14000d029;
        iVar25 = *(int *)(local_58[uVar40] + 0xc);
        if (iVar25 < *(int *)(puVar30[1] + 8 + uStack_e8 * 4)) {
          *(int *)(puVar30[1] + 8 + uStack_e8 * 4) = iVar25;
        }
        if (local_50 <= uVar40) {
                    /* WARNING: Subroutine does not return */
          _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
        }
        lVar39 = local_58[uVar40];
        uVar38 = uVar40;
        if (uVar27 < uVar40) {
          do {
            uVar32 = uVar38 - 1;
            if (local_50 <= uVar32) {
                    /* WARNING: Subroutine does not return */
              _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
            }
            if (*(int *)(local_58[uVar32] + 0xc) <= *(int *)(lVar39 + 0xc)) goto LAB_14000c7f3;
            if (local_50 <= uVar38) {
                    /* WARNING: Subroutine does not return */
              _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
            }
            local_58[uVar38] = local_58[uVar32];
            uVar38 = uVar32;
          } while (uVar27 < uVar32);
          uVar38 = uVar27;
        }
LAB_14000c7f3:
        if (local_50 <= uVar38) {
                    /* WARNING: Subroutine does not return */
          _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
        }
        if ((int)uVar33 < *(int *)(local_58[uVar38] + 0xc)) {
          local_58[uVar38] = lVar39;
          uVar40 = uVar40 + 1;
        }
        else {
          uVar27 = uVar27 + 1;
          uVar40 = uVar40 + 1;
        }
      }
      if (puVar30[2] <= uVar1) {
LAB_14000d029:
                    /* WARNING: Subroutine does not return */
        _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
      }
      if (iVar25 < *(int *)(puVar30[1] + 8 + uStack_e8 * 4)) {
        *(int *)(puVar30[1] + 8 + uStack_e8 * 4) = iVar25;
      }
      lVar39 = uVar40 - uVar27;
      if (lVar39 != 0) {
        plVar3 = local_58 + local_50;
        uVar32 = uStack_e8 + 3;
        lVar2 = uStack_e8 + 4;
        uVar38 = uVar27;
        plVar35 = local_58;
LAB_14000c8c7:
        if (uVar38 == 0) {
          if (plVar35 == plVar3) goto LAB_14000caae;
          uVar31 = puVar30[2];
        }
        else {
          if ((ulonglong)((longlong)plVar3 - (longlong)plVar35) >> 3 <= uVar38) goto LAB_14000caae;
          plVar35 = plVar35 + uVar38;
          uVar31 = puVar30[2];
        }
        if (uVar31 <= uVar13) {
LAB_14000d00b:
                    /* WARNING: Subroutine does not return */
          _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
        }
        lVar39 = lVar39 + -1;
        piVar29 = (int *)*plVar35;
        plVar35 = plVar35 + 1;
        iVar25 = *piVar29;
        iVar10 = piVar29[2];
        uVar38 = 0;
LAB_14000c906:
        uVar37 = uVar38 | 1;
        do {
          uVar14 = puVar30[1];
          uVar36 = (ulonglong)*(int *)(uVar14 + uVar13 * 4);
          if (uVar36 <= uVar38) {
LAB_14000c893:
            uVar38 = 0;
            if (lVar39 == 0) break;
            goto LAB_14000c8c7;
          }
          if (uVar31 < uVar32) {
            _RNvNtNtCsloaxXL3qbEI_4core5slice5index26slice_start_index_len_fail();
            goto LAB_14000cc81;
          }
          if (uVar31 - uVar32 <= uVar37) {
                    /* WARNING: Subroutine does not return */
            _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
          }
          lVar4 = uVar14 + uVar32 * 4;
          iVar24 = *(int *)(lVar4 + uVar37 * 4);
          if (iVar24 <= iVar25) goto LAB_14000ca4b;
          iVar11 = *(int *)(lVar4 + uVar38 * 4);
          if (iVar10 <= iVar11) goto LAB_14000c893;
          if (iVar11 < iVar25) {
            if (iVar10 < iVar24) {
              local_c8 = (ulonglong *)CONCAT44(iVar10,iVar25);
              if (uVar31 <= uVar13) {
                    /* WARNING: Subroutine does not return */
                _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
              }
              piVar29 = (int *)(uVar14 + uVar13 * 4);
              *piVar29 = *piVar29 + 2;
              ppuVar5 = (undefined **)(lVar2 + uVar38);
              puVar28 = _RINvXCsgf1RBdmyjwT_12fallible_vecINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEINtB3_11FallibleVeclB13_E13try_splice_inINtNtNtNtCsloaxXL3qbEI_4core4iter8adapters6cloned6ClonedINtNtNtB2O_5slice4iter4IterlEEINtNtNtB2O_3ops5range5RangejEECscIyU0BP6seX_7rgncore
                                  (puVar30,ppuVar5,ppuVar5,(undefined **)&local_c8,
                                   (undefined **)&uStack_c0);
              if (puVar28 == (undefined4 *)0x8000000000000001) goto LAB_14000ca4b;
              uVar38 = 0xe;
              goto LAB_14000cc8d;
            }
            if (uVar31 <= uVar13) goto LAB_14000d093;
            if (uVar36 <= uVar37) goto LAB_14000cfaa;
            uVar37 = lVar2 + uVar38;
            if (uVar31 <= uVar37) goto LAB_14000d087;
            iVar24 = iVar25;
            goto LAB_14000ca47;
          }
          if (iVar10 < iVar24) goto LAB_14000c9fb;
          _RNvMs4_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE12remove_wallsB7_
                    ((longlong *)&local_f8,uVar38,2);
          uVar31 = puVar30[2];
          if (uVar31 <= uVar13) goto LAB_14000d00b;
        } while( true );
      }
    }
LAB_14000caae:
    uVar32 = puVar30[2];
    if (uVar32 <= uVar1) {
LAB_14000d09f:
                    /* WARNING: Subroutine does not return */
      _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
    }
    if ((int)uVar8 < *(int *)(puVar30[1] + 8 + uVar13 * 4)) {
      *(uint *)(puVar30[1] + 8 + uVar13 * 4) = uVar8;
      uVar32 = puVar30[2];
    }
    if (uVar32 <= uVar1) goto LAB_14000d09f;
    uVar33 = *(uint *)(puVar30[1] + 8 + uVar13 * 4);
    local_c8 = local_f8;
    uStack_c0 = uStack_f0;
    uStack_bc = uStack_ec;
    uStack_b8 = uStack_e8;
    uVar38 = _RNvMs4_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE18commit_or_coalesceB7_
                       (&local_c8);
    if ((uVar38 & 1) != 0) {
LAB_14000cc81:
      uVar38 = uVar38 >> 0x20;
      goto LAB_14000cc9a;
    }
    if ((uVar38 & 0x100) != 0) {
      local_c8 = (ulonglong *)
                 _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalQINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E7last_ofB4_
                           ((longlong)&local_128);
      uStack_c0 = (uint)uVar32;
      uStack_bc = (uint)(uVar32 >> 0x20);
      if (local_c8[2] <= uVar32) goto LAB_14000d0d8;
      if (*(int *)(local_c8[1] + uVar32 * 4) != 0) {
        uVar32 = 0;
        iVar25 = _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalQINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E6x_wallB4_
                           (&local_c8,0);
        if (iVar25 < iStack_10c) {
          iStack_10c = iVar25;
        }
        lVar39 = _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalQINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E7x_wallsB4_
                           (&local_c8);
        if ((uVar32 == 0) || (piVar29 = (int *)(lVar39 + uVar32 * 4 + -4), piVar29 == (int *)0x0)) {
                    /* WARNING: Subroutine does not return */
          _RNvNtCsloaxXL3qbEI_4core6option13unwrap_failed();
        }
        iVar25 = *piVar29;
        if (iStack_104 < iVar25) {
          iStack_104 = iVar25;
        }
      }
    }
    if (uVar27 < uVar40) {
      do {
        if (local_50 <= uVar27) {
                    /* WARNING: Subroutine does not return */
          _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
        }
        uVar32 = local_50;
        if ((int)uVar33 < *(int *)(local_58[uVar27] + 0xc)) goto LAB_14000c615;
        uVar27 = uVar27 + 1;
      } while (uVar40 != uVar27);
      uVar27 = uVar40;
    }
LAB_14000c615:
  } while ((int)uVar33 < (int)uVar8);
  if (uStack_110 == 1) {
    iStack_10c = 0;
    uStack_108 = 0;
    iStack_104 = 0;
    uStack_100 = 0;
    lVar39 = _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalQINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E7last_ofB4_
                       ((longlong)&local_128);
    if (*(ulonglong *)(lVar39 + 0x10) <= uVar32 + 2) goto LAB_14000d0fc;
    *(undefined4 *)(*(longlong *)(lVar39 + 8) + 8 + uVar32 * 4) = 0x7fffffff;
  }
  else {
    lVar39 = _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalQINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E7last_ofB4_
                       ((longlong)&local_128);
    if (*(ulonglong *)(lVar39 + 0x10) <= uVar32) {
LAB_14000d0d8:
                    /* WARNING: Subroutine does not return */
      _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
    }
    if (*(int *)(*(longlong *)(lVar39 + 8) + uVar32 * 4) == 0) {
      lVar39 = _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalQINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E7last_ofB4_
                         ((longlong)&local_128);
      if (*(ulonglong *)(lVar39 + 0x10) <= uVar32 + 2) goto LAB_14000d0fc;
      *(undefined4 *)(*(longlong *)(lVar39 + 8) + 8 + uVar32 * 4) = 0x7fffffff;
    }
    else {
      lVar39 = _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalQINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E7last_ofB4_
                         ((longlong)&local_128);
      if (*(ulonglong *)(lVar39 + 0x10) <= uVar32 + 2) goto LAB_14000d10b;
      uVar6 = *(uint *)(*(longlong *)(lVar39 + 8) + 8 + uVar32 * 4);
      uVar32 = (ulonglong)uVar6;
      uVar27 = _RNvMs5_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE11append_scan
                         ((ulonglong *)&local_128,uVar6,0x7fffffff,(undefined4 *)&DAT_00000004,0);
      uVar38 = uVar27 & 0xffffffff;
      if ((int)uVar27 != 0) {
LAB_14000cc9a:
        if (local_60 != (ulonglong *)0x0) {
          _RNvCs8cVqplN8eB1_7___rustc14___rust_dealloc();
        }
        goto LAB_14000bd95;
      }
    }
    lVar39 = _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalRINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E8first_ofB4_
                       ((longlong)&local_128);
    lVar39 = _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalRINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E4nextB4_
                       (lVar39,uVar32);
    if (lVar39 == 0) {
                    /* WARNING: Subroutine does not return */
      _RNvNtCsloaxXL3qbEI_4core6option13unwrap_failed();
    }
    if (*(ulonglong *)(lVar39 + 0x10) <= uVar32 + 1) {
LAB_14000d11a:
                    /* WARNING: Subroutine does not return */
      _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
    }
    uVar12 = *(undefined4 *)(*(longlong *)(lVar39 + 8) + 4 + uVar32 * 4);
    lVar39 = _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalRINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E8first_ofB4_
                       ((longlong)&local_128);
    if (*(ulonglong *)(lVar39 + 0x10) <= uVar32 + 2) {
LAB_14000d0fc:
                    /* WARNING: Subroutine does not return */
      _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
    }
    *(undefined4 *)(*(longlong *)(lVar39 + 8) + 8 + uVar32 * 4) = uVar12;
    lVar39 = _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalRINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E8first_ofB4_
                       ((longlong)&local_128);
    if (*(ulonglong *)(lVar39 + 0x10) <= uVar32 + 2) {
LAB_14000d10b:
                    /* WARNING: Subroutine does not return */
      _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
    }
    uStack_108 = *(undefined4 *)(*(longlong *)(lVar39 + 8) + 8 + uVar32 * 4);
    lVar39 = _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalQINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E7last_ofB4_
                       ((longlong)&local_128);
    if (*(ulonglong *)(lVar39 + 0x10) <= uVar32 + 1) goto LAB_14000d11a;
    uStack_100 = *(undefined4 *)(*(longlong *)(lVar39 + 8) + 4 + uVar32 * 4);
  }
  if (local_60 != (ulonglong *)0x0) {
    _RNvCs8cVqplN8eB1_7___rustc14___rust_dealloc();
  }
  puVar30 = (ulonglong *)CONCAT44(uStack_114,uStack_118);
  if (puVar30 == (ulonglong *)0x0) {
    uVar38 = 0;
LAB_14000bda5:
    _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore16set_to_null_scan((ulonglong *)&local_128);
LAB_14000bdb7:
    if ((int)uVar38 != 0) {
      RegionCore_drop((longlong *)&local_128);
      uVar27 = uStack_b8;
      uVar40 = uStack_e8;
      goto LAB_14000c4d1;
    }
    puVar30 = (ulonglong *)CONCAT44(uStack_114,uStack_118);
  }
  puVar16 = *param_1;
  puVar17 = param_1[1];
  *param_1 = local_128;
  param_1[1] = (ulonglong *)CONCAT44(uStack_11c,uStack_120);
  uStack_120 = (uint)puVar17;
  uStack_11c = (uint)((ulonglong)puVar17 >> 0x20);
  puVar18 = (ulonglong *)CONCAT44(iStack_10c,uStack_110);
  puVar17 = param_1[2];
  param_1[2] = puVar30;
  uStack_118 = SUB84(puVar17,0);
  uStack_114 = (uint)((ulonglong)puVar17 >> 0x20);
  uStack_110 = (uint)param_1[3];
  iStack_10c = (int)((ulonglong)param_1[3] >> 0x20);
  puVar30 = param_1[4];
  puVar17 = param_1[5];
  param_1[3] = puVar18;
  param_1[4] = (ulonglong *)CONCAT44(iStack_104,uStack_108);
  param_1[5] = (ulonglong *)CONCAT44(local_fc,uStack_100);
  uStack_108 = SUB84(puVar30,0);
  iStack_104 = (int)((ulonglong)puVar30 >> 0x20);
  uStack_100 = SUB84(puVar17,0);
  local_fc = (undefined4)((ulonglong)puVar17 >> 0x20);
  local_128 = puVar16;
  RegionCore_drop((longlong *)&local_128);
LAB_14000c4ce:
  uVar38 = 0;
  uVar27 = uStack_b8;
  uVar40 = uStack_e8;
LAB_14000c4d1:
  if ((local_48 ^ (ulonglong)auStackY_1a8) == __security_cookie) {
    return uVar38;
  }
  pcVar15 = (code *)swi(3);
  uStack_b8 = uVar27;
  uStack_e8 = uVar40;
  uVar27 = (*pcVar15)();
  return uVar27;
}



===== _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore20tighten_bounding_box @ 14000d130 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore20tighten_bounding_box(longlong param_1)

{
  ulonglong uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  code *pcVar4;
  int iVar5;
  undefined8 uVar6;
  longlong lVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  undefined1 auStack_68 [32];
  undefined **local_48;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_68;
  if (*(int *)(param_1 + 0x18) == 1) {
    *(undefined8 *)(param_1 + 0x1c) = 0;
    *(undefined8 *)(param_1 + 0x24) = 0;
    return;
  }
  uVar6 = _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalQINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E13is_valid_scanB4__llvm_3083486868190693220
                    (param_1,0);
  if ((char)uVar6 == '\0') {
LAB_14000d2d1:
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core9panicking5panic();
  }
  uVar9 = *(ulonglong *)(param_1 + 0x10);
  if (uVar9 < 3) {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
  }
  lVar7 = (longlong)*(int *)(*(longlong *)(param_1 + 8) + -4 + uVar9 * 4);
  if (lVar7 < 0) {
    local_48 = &anon_67cd83108cc9ed848dbde57549fb323c_12_llvm_3083486868190693220;
    _RNvNtCsloaxXL3qbEI_4core6result13unwrap_failed();
LAB_14000d312:
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
  }
  if (lVar7 + 4U <= uVar9) {
    uVar2 = *(undefined4 *)(*(longlong *)(param_1 + 8) + 8);
    uVar8 = (uVar9 - lVar7) - 4;
    uVar6 = _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalQINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E13is_valid_scanB4__llvm_3083486868190693220
                      (param_1,uVar8);
    if ((char)uVar6 != '\0') {
      if (*(ulonglong *)(param_1 + 0x10) <= (uVar9 - lVar7) - 3) {
                    /* WARNING: Subroutine does not return */
        _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
      }
      uVar3 = *(undefined4 *)(*(longlong *)(param_1 + 8) + 4 + uVar8 * 4);
      uVar6 = _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalQINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E13is_valid_scanB4__llvm_3083486868190693220
                        (param_1,0);
      if ((char)uVar6 != '\0') {
        iVar13 = 0x7fffffff;
        iVar11 = -0x80000000;
        uVar9 = 0;
        do {
          uVar8 = *(ulonglong *)(param_1 + 0x10);
          if (uVar8 <= uVar9) goto LAB_14000d312;
          lVar7 = *(longlong *)(param_1 + 8);
          uVar10 = (ulonglong)*(int *)(lVar7 + uVar9 * 4);
          if (uVar10 != 0) {
            uVar1 = uVar9 + 3;
            if (uVar8 <= uVar1) {
                    /* WARNING: Subroutine does not return */
              _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
            }
            if (CARRY8(uVar1,uVar10)) {
              _RNvNtNtCsloaxXL3qbEI_4core5slice5index22slice_index_order_fail();
              break;
            }
            if (uVar8 < uVar1 + uVar10) {
              _RNvNtNtCsloaxXL3qbEI_4core5slice5index24slice_end_index_len_fail
                        (uVar1 + uVar10,uVar8,
                         &anon_67cd83108cc9ed848dbde57549fb323c_20_llvm_3083486868190693220);
              goto LAB_14000d284;
            }
            iVar12 = *(int *)(lVar7 + uVar1 * 4);
            if (iVar12 <= iVar13) {
              iVar13 = iVar12;
            }
            iVar12 = *(int *)(lVar7 + uVar1 * 4 + -4 + uVar10 * 4);
            if (iVar11 <= iVar12) {
              iVar11 = iVar12;
            }
          }
          uVar9 = uVar9 + uVar10 + 4;
          uVar6 = _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalQINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E13is_valid_scanB4__llvm_3083486868190693220
                            (param_1,uVar9);
          if ((char)uVar6 == '\0') {
LAB_14000d284:
            iVar12 = iVar11;
            if (iVar11 <= iVar13) {
              iVar12 = 0;
            }
            iVar5 = 0;
            if (iVar13 < iVar11) {
              iVar5 = iVar13;
            }
            *(int *)(param_1 + 0x1c) = iVar5;
            *(undefined4 *)(param_1 + 0x20) = uVar2;
            *(int *)(param_1 + 0x24) = iVar12;
            *(undefined4 *)(param_1 + 0x28) = uVar3;
            if ((local_38 ^ (ulonglong)auStack_68) == __security_cookie) {
              return;
            }
            pcVar4 = (code *)swi(3);
            (*pcVar4)();
            return;
          }
        } while( true );
      }
      goto LAB_14000d2d1;
    }
  }
                    /* WARNING: Subroutine does not return */
  _RNvNtCsloaxXL3qbEI_4core6option13unwrap_failed();
}



===== _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore14contains_point @ 14000d360 =====

ulonglong _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore14contains_point
                    (longlong param_1,int *param_2)

{
  ulonglong uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  longlong lVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  
  iVar2 = *param_2;
  if ((((*(int *)(param_1 + 0x1c) <= iVar2) &&
       (iVar3 = param_2[1], iVar3 < *(int *)(param_1 + 0x28))) && (iVar2 < *(int *)(param_1 + 0x24))
      ) && (*(int *)(param_1 + 0x20) <= iVar3)) {
    uVar7 = _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalQINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E13is_valid_scanB4__llvm_3083486868190693220
                      (param_1,0);
    if ((char)uVar7 == '\0') {
LAB_14000d478:
                    /* WARNING: Subroutine does not return */
      _RNvNtCsloaxXL3qbEI_4core9panicking5panic();
    }
    lVar5 = *(longlong *)(param_1 + 8);
    uVar6 = *(ulonglong *)(param_1 + 0x10);
    uVar10 = 0;
    do {
      if (uVar6 <= uVar10 + 1) {
                    /* WARNING: Subroutine does not return */
        _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
      }
      if (iVar3 < *(int *)(lVar5 + 4 + uVar10 * 4)) {
        return 0;
      }
      if (uVar6 <= uVar10 + 2) {
                    /* WARNING: Subroutine does not return */
        _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
      }
      if (iVar3 < *(int *)(lVar5 + 8 + uVar10 * 4)) {
        if (uVar6 <= uVar10) goto LAB_14000d490;
        uVar1 = uVar10 + 3;
        iVar4 = *(int *)(lVar5 + uVar10 * 4);
        uVar11 = (ulonglong)iVar4;
        uVar8 = uVar1 + uVar11;
        if (CARRY8(uVar1,uVar11)) {
          _RNvNtNtCsloaxXL3qbEI_4core5slice5index22slice_index_order_fail();
        }
        else if (uVar8 <= uVar6) {
          if (iVar4 != 0) {
            lVar9 = 0;
            uVar8 = 0;
            do {
              if (iVar2 < *(int *)(lVar5 + uVar1 * 4 + lVar9)) {
                return uVar8;
              }
              uVar8 = uVar8 ^ 1;
              lVar9 = lVar9 + 4;
            } while (uVar11 * 4 != lVar9);
          }
          goto LAB_14000d420;
        }
        _RNvNtNtCsloaxXL3qbEI_4core5slice5index24slice_end_index_len_fail
                  (uVar8,uVar6,&anon_67cd83108cc9ed848dbde57549fb323c_20_llvm_3083486868190693220);
        goto LAB_14000d478;
      }
LAB_14000d420:
      if (uVar6 <= uVar10) {
LAB_14000d490:
                    /* WARNING: Subroutine does not return */
        _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
      }
      uVar10 = uVar10 + (longlong)*(int *)(lVar5 + uVar10 * 4) + 4;
      uVar7 = _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalQINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E13is_valid_scanB4__llvm_3083486868190693220
                        (param_1,uVar10);
    } while ((char)uVar7 != '\0');
  }
  return 0;
}



===== _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore7combine @ 14000d4d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
_RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore7combine
          (ulonglong *param_1,ulonglong *param_2,ulonglong *param_3,int param_4)

{
  code *pcVar1;
  ulonglong *puVar2;
  int iVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  uint uVar6;
  int iVar7;
  ulonglong uVar8;
  int iVar9;
  int iVar10;
  undefined1 auStackY_78 [32];
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 uStack_28;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  uVar6 = param_4 - 1;
  if (uVar6 < 2) {
    if ((((param_2[2] != 0xe) ||
         (*(int *)((longlong)param_3 + 0x1c) < *(int *)((longlong)param_2 + 0x1c))) ||
        (*(int *)((longlong)param_2 + 0x24) < *(int *)((longlong)param_3 + 0x24))) ||
       (((int)param_3[4] < (int)param_2[4] || ((int)param_2[5] < (int)param_3[5])))) {
      if (param_3[2] == 0xe) {
        iVar10 = *(int *)((longlong)param_3 + 0x1c);
        iVar3 = *(int *)((longlong)param_2 + 0x1c);
        if (((iVar10 <= iVar3) &&
            (*(int *)((longlong)param_2 + 0x24) <= *(int *)((longlong)param_3 + 0x24))) &&
           (((int)param_3[4] <= (int)param_2[4] && ((int)param_2[5] <= (int)param_3[5])))) {
          if (param_4 != 1) {
            param_2 = param_3;
          }
          uVar4 = param_2[2];
          goto LAB_14000d654;
        }
        if (param_4 == 1 && param_2[2] == 0xe) {
          if (iVar3 < iVar10) {
            iVar3 = iVar10;
          }
          iVar10 = *(int *)((longlong)param_2 + 0x24);
          if (*(int *)((longlong)param_3 + 0x24) < *(int *)((longlong)param_2 + 0x24)) {
            iVar10 = *(int *)((longlong)param_3 + 0x24);
          }
          iVar7 = (int)param_2[4];
          if ((int)param_2[4] < (int)param_3[4]) {
            iVar7 = (int)param_3[4];
          }
          iVar9 = (int)param_2[5];
          if ((int)param_3[5] < (int)param_2[5]) {
            iVar9 = (int)param_3[5];
          }
          local_48 = (undefined **)CONCAT44(iVar7,iVar3);
          local_40 = CONCAT44(iVar9,iVar10);
          if ((iVar3 < iVar10) && (iVar7 < iVar9)) {
            _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore16set_to_rectangle
                      (param_1,(int *)&local_48);
          }
          else {
            _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore16set_to_null_scan(param_1);
          }
          uVar4 = 2;
          uVar8 = local_18 ^ (ulonglong)auStackY_78;
          if (uVar8 == __security_cookie) {
            return 0;
          }
          goto LAB_14000d6d6;
        }
      }
      goto LAB_14000d56a;
    }
    puVar2 = param_3;
    if (param_4 != 1) {
      puVar2 = param_2;
    }
    param_2 = puVar2;
    uVar4 = param_2[2];
LAB_14000d654:
    uVar4 = _RNvMs2_NtCsip5f2bf5HGI_5alloc7raw_vecINtB5_11RawVecInnerINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE11try_reserveCscIyU0BP6seX_7rgncore
                      (param_1,param_1[2],uVar4,&DAT_00000004,4);
    if (uVar4 != 0x8000000000000001) {
      uVar4 = 0xe;
      uVar8 = local_18 ^ (ulonglong)auStackY_78;
      if (uVar8 == __security_cookie) {
        return 1;
      }
      goto LAB_14000d6d6;
    }
    _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore27set_to_scans_from_no_resize(param_1,param_2);
  }
  else {
LAB_14000d56a:
    if (3 < uVar6) {
      local_48 = &anon_b48ea28664ba4942b42991ee697635cb_4_llvm_8928174079759062801;
      local_40 = 1;
      local_38 = 8;
      local_30 = 0;
      uStack_28 = 0;
                    /* WARNING: Subroutine does not return */
      _RNvNtCsloaxXL3qbEI_4core9panicking9panic_fmt();
    }
    uVar4 = _RNvMs_NtCscIyU0BP6seX_7rgncore5mergeNtB6_10RegionCore5merge
                      (param_1,(longlong)param_2,(longlong)param_3,
                       (byte)(0x4060e08 >> ((char)uVar6 * '\b' & 0x1fU)));
    if ((int)uVar4 != 0) {
      uVar4 = uVar4 & 0xffffffff;
      uVar8 = local_18 ^ (ulonglong)auStackY_78;
      if (uVar8 == __security_cookie) {
        return 1;
      }
      goto LAB_14000d6d6;
    }
  }
  uVar4 = 1;
  if ((int)param_1[3] != 1) {
    uVar4 = (ulonglong)(3 - (param_1[2] < 0xf));
  }
  uVar8 = local_18 ^ (ulonglong)auStackY_78;
  if (uVar8 == __security_cookie) {
    return 0;
  }
LAB_14000d6d6:
  pcVar1 = (code *)swi(3);
  uVar5 = (*pcVar1)(uVar8,uVar4);
  return uVar5;
}



===== _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore5scale @ 14000d720 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore5scale
               (longlong param_1,float param_2,float param_3)

{
  ulonglong uVar1;
  longlong lVar2;
  code *pcVar3;
  int iVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  longlong lVar10;
  undefined1 auStack_78 [32];
  float local_58;
  float local_54;
  ulonglong local_50;
  
  local_50 = __security_cookie ^ (ulonglong)auStack_78;
  local_58 = param_2;
  local_54 = param_3;
  if (*(int *)(param_1 + 0x18) != 0) {
    uVar5 = _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalQINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E13is_valid_scanB4__llvm_3083486868190693220
                      (param_1,0);
    if ((char)uVar5 == '\0') {
LAB_14000d8f3:
                    /* WARNING: Subroutine does not return */
      _RNvNtCsloaxXL3qbEI_4core9panicking5panic();
    }
    uVar9 = 0;
    do {
      uVar7 = *(ulonglong *)(param_1 + 0x10);
      if (uVar7 <= uVar9) {
LAB_14000d90b:
                    /* WARNING: Subroutine does not return */
        _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
      }
      uVar1 = uVar9 + 3;
      iVar4 = *(int *)(*(longlong *)(param_1 + 8) + uVar9 * 4);
      uVar8 = (ulonglong)iVar4;
      uVar6 = uVar1 + uVar8;
      if (CARRY8(uVar1,uVar8)) {
        uVar7 = uVar6;
        uVar6 = _RNvNtNtCsloaxXL3qbEI_4core5slice5index22slice_index_order_fail();
LAB_14000d8e4:
        _RNvNtNtCsloaxXL3qbEI_4core5slice5index24slice_end_index_len_fail
                  (uVar6,uVar7,&anon_67cd83108cc9ed848dbde57549fb323c_25_llvm_3083486868190693220);
        goto LAB_14000d8f3;
      }
      if (uVar7 < uVar6) goto LAB_14000d8e4;
      if (iVar4 != 0) {
        lVar2 = *(longlong *)(param_1 + 8) + uVar1 * 4;
        lVar10 = 0;
        do {
          iVar4 = _RNvNtCslMg0IV26qJh_12gdi_bindings6efloat14bEfToL_or_zero
                            ((uint)((float)*(int *)(lVar2 + lVar10) * param_2));
          *(int *)(lVar2 + lVar10) = iVar4;
          lVar10 = lVar10 + 4;
        } while (uVar8 * 4 != lVar10);
        uVar7 = *(ulonglong *)(param_1 + 0x10);
      }
      if (uVar7 <= uVar9 + 1) {
                    /* WARNING: Subroutine does not return */
        _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
      }
      iVar4 = *(int *)(*(longlong *)(param_1 + 8) + 4 + uVar9 * 4);
      if (!SBORROW4(0,iVar4)) {
        iVar4 = _RNvNtCslMg0IV26qJh_12gdi_bindings6efloat14bEfToL_or_zero
                          ((uint)((float)iVar4 * param_3));
        if (*(ulonglong *)(param_1 + 0x10) <= uVar9 + 1) {
                    /* WARNING: Subroutine does not return */
          _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
        }
        *(int *)(*(longlong *)(param_1 + 8) + 4 + uVar9 * 4) = iVar4;
        uVar7 = *(ulonglong *)(param_1 + 0x10);
      }
      if (uVar7 <= uVar9 + 2) {
                    /* WARNING: Subroutine does not return */
        _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
      }
      iVar4 = *(int *)(*(longlong *)(param_1 + 8) + 8 + uVar9 * 4);
      if (iVar4 != 0x7fffffff) {
        iVar4 = _RNvNtCslMg0IV26qJh_12gdi_bindings6efloat14bEfToL_or_zero
                          ((uint)((float)iVar4 * param_3));
        if (*(ulonglong *)(param_1 + 0x10) <= uVar9 + 2) {
                    /* WARNING: Subroutine does not return */
          _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
        }
        *(int *)(*(longlong *)(param_1 + 8) + 8 + uVar9 * 4) = iVar4;
        uVar7 = *(ulonglong *)(param_1 + 0x10);
      }
      if (uVar7 <= uVar9) goto LAB_14000d90b;
      uVar9 = uVar9 + (longlong)*(int *)(*(longlong *)(param_1 + 8) + uVar9 * 4) + 4;
      uVar5 = _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalQINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E13is_valid_scanB4__llvm_3083486868190693220
                        (param_1,uVar9);
    } while ((char)uVar5 != '\0');
    _RNvMNtCslMg0IV26qJh_12gdi_bindings5pointNtB2_7POINTFL14scale_rect_mut
              (&local_58,(int *)(param_1 + 0x1c));
  }
  if ((local_50 ^ (ulonglong)auStack_78) == __security_cookie) {
    return;
  }
  pcVar3 = (code *)swi(3);
  (*pcVar3)();
  return;
}



===== _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore15insert_scanline @ 14000d960 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore15insert_scanline
                    (ulonglong *param_1,int param_2,int *param_3,ulonglong param_4,
                    undefined **param_5,ulonglong param_6)

{
  ulonglong uVar1;
  code *pcVar2;
  undefined **ppuVar3;
  byte bVar4;
  char cVar5;
  int iVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  longlong lVar9;
  undefined4 *puVar10;
  ulonglong uVar11;
  int iVar12;
  undefined **ppuVar13;
  undefined **ppuVar14;
  ulonglong uVar15;
  ulonglong uVar16;
  undefined **ppuVar17;
  undefined1 auStackY_e8 [32];
  int local_b4;
  ulonglong local_b0;
  undefined8 *local_a8;
  undefined4 *local_a0;
  int *local_98;
  int *local_90;
  int *local_88;
  ulonglong *local_80;
  int local_78;
  int local_74;
  int local_70;
  undefined4 auStack_6c [3];
  ulonglong *local_60;
  undefined **local_58;
  longlong local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_e8;
  uVar11 = param_1[2];
  if (uVar11 == 4) {
    uVar11 = param_4 + 0xe;
    uVar1 = *param_1;
    if ((uVar1 < uVar11) && (uVar1 - 4 < param_4 + 10)) {
      uVar7 = 0xe;
      if (0xfffffffffffffffb < param_4 + 10) goto LAB_14000de65;
      uVar15 = uVar1 * 2;
      if (uVar1 * 2 < uVar11) {
        uVar15 = uVar11;
      }
      if (0x7ffffffffffffffc < uVar15 * 4 || uVar15 >> 0x3e != 0) goto LAB_14000de65;
      if (uVar1 == 0) {
        local_58 = (undefined **)0x0;
      }
      else {
        local_60 = (ulonglong *)param_1[1];
        local_50 = uVar1 << 2;
        local_58 = (undefined **)&DAT_00000004;
      }
      _RINvNtCsip5f2bf5HGI_5alloc7raw_vec11finish_growINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EECscIyU0BP6seX_7rgncore_llvm_13477870103536380358
                ((ulonglong *)&local_78,&DAT_00000004,uVar15 * 4,&local_60);
      if (local_78 == 1) goto LAB_14000dd5f;
      param_1[1] = CONCAT44(auStack_6c[0],local_70);
      *param_1 = uVar15;
    }
    param_1[2] = 0;
    *(undefined4 *)(param_1 + 3) = 0;
    uVar7 = _RNvMs5_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE11append_scan
                      (param_1,0x80000000,param_2,(undefined4 *)&DAT_00000004,0);
    if ((int)uVar7 == 0) {
      iVar6 = param_2 + 1;
      uVar7 = _RNvMs5_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE11append_scan
                        (param_1,param_2,iVar6,param_3,param_4);
      if (((int)uVar7 == 0) &&
         (uVar7 = _RNvMs5_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE11append_scan
                            (param_1,iVar6,0x7fffffff,(undefined4 *)&DAT_00000004,0),
         (int)uVar7 == 0)) {
        *(int *)(param_1 + 4) = param_2;
        *(int *)(param_1 + 5) = iVar6;
        bVar4 = _RNvNtCsjsHfHFRyfyy_10gdi_region3ffi60Feature_Servicing_Win32kRSFloodFillBoundingBox_ffi_IsEnabled
                          ();
        if ((param_4 != 0 & bVar4) != 0) {
          *(int *)((longlong)param_1 + 0x1c) = *param_3;
          *(int *)((longlong)param_1 + 0x24) = param_3[param_4 - 1];
        }
        if (param_1[2] == 0) {
          _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore16set_to_null_scan(param_1);
        }
        goto LAB_14000de2e;
      }
    }
    if (param_1[2] == 0) {
      uVar7 = uVar7 & 0xffffffff;
      _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore16set_to_null_scan(param_1);
    }
  }
  else {
    uVar15 = param_4 + uVar11 + 4;
    uVar1 = *param_1;
    if (uVar1 - uVar11 < uVar15) {
      uVar7 = 0xe;
      if (CARRY8(uVar11,uVar15)) goto LAB_14000de65;
      uVar16 = uVar1 * 2;
      if (uVar1 * 2 < uVar11 + uVar15) {
        uVar16 = uVar11 + uVar15;
      }
      uVar11 = 4;
      if (4 < uVar16) {
        uVar11 = uVar16;
      }
      if (0x7ffffffffffffffc < uVar11 * 4 || uVar16 >> 0x3e != 0) goto LAB_14000de65;
      if (uVar1 == 0) {
        local_58 = (undefined **)0x0;
      }
      else {
        local_60 = (ulonglong *)param_1[1];
        local_50 = uVar1 << 2;
        local_58 = (undefined **)&DAT_00000004;
      }
      _RINvNtCsip5f2bf5HGI_5alloc7raw_vec11finish_growINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EECscIyU0BP6seX_7rgncore_llvm_13477870103536380358
                ((ulonglong *)&local_78,&DAT_00000004,uVar11 * 4,&local_60);
      if (local_78 == 1) goto LAB_14000dd5f;
      param_1[1] = CONCAT44(auStack_6c[0],local_70);
      *param_1 = uVar11;
    }
    uVar8 = _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalQINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E13is_valid_scanB4__llvm_3083486868190693220
                      ((longlong)param_1,0);
    if ((char)uVar8 == '\0') {
                    /* WARNING: Subroutine does not return */
      _RNvNtCsloaxXL3qbEI_4core9panicking5panic();
    }
    local_58 = (undefined **)0x0;
    ppuVar14 = (undefined **)param_1[2];
    if (ppuVar14 < (undefined **)0x2) {
      local_60 = param_1;
                    /* WARNING: Subroutine does not return */
      _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
    }
    ppuVar13 = (undefined **)0x1;
    while( true ) {
      ppuVar3 = local_58;
      uVar11 = param_1[1];
      iVar6 = *(int *)(uVar11 + (longlong)ppuVar13 * 4);
      if (param_2 <= iVar6) break;
      if (ppuVar14 <= local_58) {
        local_60 = param_1;
                    /* WARNING: Subroutine does not return */
        _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
      }
      iVar6 = *(int *)(uVar11 + (longlong)local_58 * 4);
      ppuVar17 = (undefined **)((longlong)local_58 + (longlong)iVar6 + 4);
      local_60 = param_1;
      uVar8 = _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalQINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E13is_valid_scanB4__llvm_3083486868190693220
                        ((longlong)param_1,(ulonglong)ppuVar17);
      if ((char)uVar8 == '\0') {
        uVar7 = 0;
        goto LAB_14000de65;
      }
      ppuVar13 = (undefined **)((longlong)ppuVar3 + (longlong)iVar6 + 5);
      ppuVar14 = (undefined **)param_1[2];
      local_58 = ppuVar17;
      if (ppuVar14 <= ppuVar13) {
        local_60 = param_1;
                    /* WARNING: Subroutine does not return */
        _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
      }
    }
    if (param_2 == iVar6) {
      if (ppuVar14 <= (undefined **)((longlong)local_58 + 2U)) {
        local_60 = param_1;
                    /* WARNING: Subroutine does not return */
        _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
      }
      iVar6 = param_2 + 1;
      if (iVar6 != *(int *)(uVar11 + 8 + (longlong)local_58 * 4)) {
        *(int *)(uVar11 + (longlong)ppuVar13 * 4) = iVar6;
        *(int *)(param_1 + 5) = iVar6;
        local_60 = param_1;
        goto LAB_14000dc56;
      }
      local_60 = param_1;
      uVar7 = _RNvMs1_NtCscIyU0BP6seX_7rgncore4scanINtB5_12ScanInternalQINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1r_E16merge_in_x_wallsB7_
                        (&local_60,param_3,param_4,param_5,param_6);
      if ((int)uVar7 != 0) goto LAB_14000de65;
    }
    else {
      local_60 = param_1;
      if (local_58 == (undefined **)0x0) goto LAB_14000df0c;
      if (ppuVar14 <= (undefined **)((longlong)local_58 - 1U)) {
                    /* WARNING: Subroutine does not return */
        _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
      }
      lVar9 = (longlong)*(int *)((uVar11 - 4) + (longlong)local_58 * 4);
      if (lVar9 < 0) {
        _RNvNtCsloaxXL3qbEI_4core6result13unwrap_failed();
        goto LAB_14000ded4;
      }
      if (local_58 < (undefined **)(lVar9 + 4U)) {
LAB_14000df0c:
                    /* WARNING: Subroutine does not return */
        _RNvNtCsloaxXL3qbEI_4core6option13unwrap_failed();
      }
      uVar11 = (longlong)local_58 + (-4 - lVar9);
      uVar8 = _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalQINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E13is_valid_scanB4__llvm_3083486868190693220
                        ((longlong)param_1,uVar11);
      if ((char)uVar8 == '\0') goto LAB_14000df0c;
      if (param_1[2] <= (ulonglong)((longlong)ppuVar3 + (-2 - lVar9))) {
                    /* WARNING: Subroutine does not return */
        _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
      }
      *(int *)(param_1[1] + 8 + uVar11 * 4) = param_2;
      iVar6 = (int)param_1[4];
      if (param_2 < (int)param_1[4]) {
        iVar6 = param_2;
      }
      *(int *)(param_1 + 4) = iVar6;
LAB_14000dc56:
      local_70 = param_2 + 1;
      local_b4 = (int)param_4;
      local_a0 = auStack_6c;
      local_90 = param_3 + param_4;
      local_80 = &local_b0;
      local_b0 = 1;
      local_a8 = (undefined8 *)&local_78;
      local_88 = &local_b4;
      local_98 = param_3;
      local_78 = local_b4;
      local_74 = param_2;
      puVar10 = _RINvXCsgf1RBdmyjwT_12fallible_vecINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEINtB3_11FallibleVeclB13_E13try_splice_inINtNtNtNtCsloaxXL3qbEI_4core4iter8adapters6cloned6ClonedINtNtB2K_5chain5ChainIB3A_INtNtNtB2O_5slice4iter4IterlEB3Z_EB3Z_EEINtNtNtB2O_3ops5range5RangejEECscIyU0BP6seX_7rgncore
                          (param_1,ppuVar3,ppuVar3,&local_b0);
      if (puVar10 != (undefined4 *)0x8000000000000001) {
LAB_14000dd5f:
        uVar7 = 0xe;
        goto LAB_14000de65;
      }
      *(int *)(param_1 + 3) = (int)param_1[3] + 1;
    }
    bVar4 = _RNvNtCsjsHfHFRyfyy_10gdi_region3ffi60Feature_Servicing_Win32kRSFloodFillBoundingBox_ffi_IsEnabled
                      ();
    if ((param_4 != 0 & bVar4) != 0) {
      iVar6 = *(int *)((longlong)param_1 + 0x1c);
      if (*param_3 < *(int *)((longlong)param_1 + 0x1c)) {
        iVar6 = *param_3;
      }
      *(int *)((longlong)param_1 + 0x1c) = iVar6;
      if (param_3 + (param_4 - 1) == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        _RNvNtCsloaxXL3qbEI_4core6option13unwrap_failed();
      }
      iVar6 = param_3[param_4 - 1];
      iVar12 = *(int *)((longlong)param_1 + 0x24);
      if (*(int *)((longlong)param_1 + 0x24) < iVar6) {
        iVar12 = iVar6;
      }
      *(int *)((longlong)param_1 + 0x24) = iVar12;
    }
LAB_14000de2e:
    cVar5 = _RNvNtCsjsHfHFRyfyy_10gdi_region3ffi60Feature_Servicing_Win32kRSFloodFillBoundingBox_ffi_IsEnabled
                      ();
    uVar7 = 0;
    if (param_4 != 0 && cVar5 == '\0') {
      iVar6 = *(int *)((longlong)param_1 + 0x1c);
      if (*param_3 < *(int *)((longlong)param_1 + 0x1c)) {
        iVar6 = *param_3;
      }
      *(int *)((longlong)param_1 + 0x1c) = iVar6;
      if (param_3 + (param_4 - 1) == (int *)0x0) {
LAB_14000ded4:
                    /* WARNING: Subroutine does not return */
        _RNvNtCsloaxXL3qbEI_4core6option13unwrap_failed();
      }
      iVar6 = param_3[param_4 - 1];
      iVar12 = *(int *)((longlong)param_1 + 0x24);
      if (*(int *)((longlong)param_1 + 0x24) < iVar6) {
        iVar12 = iVar6;
      }
      *(int *)((longlong)param_1 + 0x24) = iVar12;
    }
  }
LAB_14000de65:
  if ((local_48 ^ (ulonglong)auStackY_e8) == __security_cookie) {
    return uVar7;
  }
  pcVar2 = (code *)swi(3);
  uVar11 = (*pcVar2)();
  return uVar11;
}



===== _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore10rect_count @ 14000df50 =====

longlong _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore10rect_count(longlong param_1)

{
  longlong lVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  longlong lVar6;
  
  uVar3 = _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalQINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E13is_valid_scanB4__llvm_3083486868190693220
                    (param_1,0);
  if ((char)uVar3 == '\0') {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core9panicking5panic();
  }
  lVar1 = *(longlong *)(param_1 + 8);
  uVar2 = *(ulonglong *)(param_1 + 0x10);
  uVar5 = 0;
  lVar6 = 0;
  do {
    if (uVar2 <= uVar5) {
                    /* WARNING: Subroutine does not return */
      _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
    }
    uVar4 = (ulonglong)*(int *)(lVar1 + uVar5 * 4);
    uVar5 = uVar5 + uVar4 + 4;
    lVar6 = lVar6 + (uVar4 >> 1);
    uVar3 = _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalQINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E13is_valid_scanB4__llvm_3083486868190693220
                      (param_1,uVar5);
  } while ((char)uVar3 != '\0');
  return lVar6;
}



===== _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore6upload @ 14000dff0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Type propagation algorithm not settling */

ulonglong _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore6upload
                    (ulonglong *param_1,undefined **param_2,ulonglong param_3)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  code *pcVar4;
  ulonglong *puVar5;
  char cVar6;
  longlong lVar7;
  undefined4 *puVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  int iVar11;
  ulonglong uVar12;
  ulonglong uVar13;
  int iVar14;
  undefined **ppuVar15;
  undefined1 auStackY_e8 [32];
  int local_b8;
  int local_b4;
  ulonglong *local_90;
  ulonglong local_88;
  ulonglong local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  int local_60 [2];
  ulonglong local_58;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_e8;
  if (param_3 < 2) {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
  }
  uVar2 = *(undefined4 *)((longlong)param_2 + 4);
  uVar10 = param_3 + ((param_3 + 2) / 3) * 5 + 8;
  uVar9 = *param_1;
  if (uVar9 < uVar10) {
    uVar12 = param_1[2];
    if (uVar10 - uVar12 <= uVar9 - uVar12) goto LAB_14000e123;
    uVar13 = 0xe;
    if (!CARRY8(uVar12,uVar10 - uVar12)) {
      uVar12 = uVar9 * 2;
      if (uVar9 * 2 < uVar10) {
        uVar12 = uVar10;
      }
      uVar10 = 4;
      if (4 < uVar12) {
        uVar10 = uVar12;
      }
      if (uVar10 * 4 < 0x7ffffffffffffffd && uVar12 >> 0x3e == 0) {
        if (uVar9 == 0) {
          local_88 = 0;
        }
        else {
          local_90 = (ulonglong *)param_1[1];
          local_80 = uVar9 << 2;
          local_88 = 4;
        }
        _RINvNtCsip5f2bf5HGI_5alloc7raw_vec11finish_growINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EECscIyU0BP6seX_7rgncore_llvm_13477870103536380358
                  ((ulonglong *)local_60,&DAT_00000004,uVar10 * 4,&local_90);
        if (local_60[0] != 1) {
          param_1[1] = local_58;
          *param_1 = uVar10;
          goto LAB_14000e123;
        }
      }
    }
  }
  else {
LAB_14000e123:
    param_1[2] = 0;
    *(undefined4 *)(param_1 + 3) = 0;
    local_b8 = 0x7fffffff;
    local_b4 = -0x80000000;
    iVar11 = -0x80000000;
    while (param_3 != 0) {
      if (param_3 == 1) {
                    /* WARNING: Subroutine does not return */
        _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
      }
      iVar14 = *(int *)((longlong)param_2 + 4);
      if ((iVar14 != iVar11) &&
         (uVar13 = _RNvMs5_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE11append_scan
                             (param_1,iVar11,iVar14,(undefined4 *)&DAT_00000004,0), (int)uVar13 != 0
         )) {
        uVar13 = uVar13 & 0xffffffff;
LAB_14000e366:
        uVar9 = param_1[2];
        goto joined_r0x00014000e320;
      }
      if (param_3 < 3) {
                    /* WARNING: Subroutine does not return */
        _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
      }
      iVar3 = *(int *)param_2;
      lVar7 = (longlong)iVar3;
      uVar9 = lVar7 * 2;
      iVar11 = *(int *)(param_2 + 1);
      _RNvMs5_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE3new
                (&local_90,param_1,iVar14,iVar11,uVar9);
      uVar12 = local_80;
      uVar10 = local_88;
      puVar5 = local_90;
      uVar13 = local_88 & 0xffffffff;
      if (local_90 == (ulonglong *)0x0) goto LAB_14000e366;
      uVar13 = param_3 - 3;
      param_3 = uVar13 + lVar7 * -2;
      if (uVar13 < uVar9) {
        local_90 = (ulonglong *)&DAT_1400195e8;
        local_88 = 1;
        local_80 = 8;
        local_78 = 0;
        uStack_70 = 0;
                    /* WARNING: Subroutine does not return */
        _RNvNtCsloaxXL3qbEI_4core9panicking9panic_fmt();
      }
      if (local_90[2] <= local_80) {
                    /* WARNING: Subroutine does not return */
        _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
      }
      ppuVar15 = (undefined **)((longlong)param_2 + 0xc);
      param_2 = ppuVar15 + lVar7;
      piVar1 = (int *)(local_90[1] + local_80 * 4);
      *piVar1 = *piVar1 + (int)uVar9;
      puVar8 = _RINvXCsgf1RBdmyjwT_12fallible_vecINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEINtB3_11FallibleVeclB13_E13try_splice_inINtNtNtNtCsloaxXL3qbEI_4core4iter8adapters6cloned6ClonedINtNtNtB2O_5slice4iter4IterlEEINtNtNtB2O_3ops5range5RangejEECscIyU0BP6seX_7rgncore
                         (local_90,(undefined **)(local_80 + 3),(undefined **)(local_80 + 3),
                          ppuVar15,param_2);
      if (puVar8 != (undefined4 *)0x8000000000000001) {
        if (puVar5[2] < uVar12) {
                    /* WARNING: Subroutine does not return */
          _RNvNtCsloaxXL3qbEI_4core9panicking5panic();
        }
        puVar5[2] = uVar12;
        uVar13 = 0xe;
        if (uVar12 != 0) goto LAB_14000e366;
        _RNvNtCsjsHfHFRyfyy_10gdi_region3ffi27RustOnZeroSizedScanCallback();
        uVar9 = param_1[2];
        goto joined_r0x00014000e320;
      }
      local_90 = puVar5;
      local_88 = uVar10;
      local_80 = uVar12;
      uVar13 = _RNvMs4_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE6commitB7_
                         ((longlong *)&local_90);
      if ((int)uVar13 != 0) {
        uVar13 = uVar13 & 0xffffffff;
        uVar9 = param_1[2];
        goto joined_r0x00014000e320;
      }
      cVar6 = _RNvNtCsjsHfHFRyfyy_10gdi_region3ffi60Feature_Servicing_Win32kRSFloodFillBoundingBox_ffi_IsEnabled
                        ();
      if (iVar3 != 0 && cVar6 == '\x01') {
        if (*(int *)ppuVar15 < local_b8) {
          local_b8 = *(int *)ppuVar15;
        }
        if (local_b4 < *(int *)((longlong)param_2 + -4)) {
          local_b4 = *(int *)((longlong)param_2 + -4);
        }
      }
    }
    cVar6 = _RNvNtCsjsHfHFRyfyy_10gdi_region3ffi60Feature_Servicing_Win32kRSFloodFillBoundingBox_ffi_IsEnabled
                      ();
    iVar14 = -0x80000000;
    if (cVar6 != '\0') {
      iVar14 = iVar11;
    }
    if ((iVar11 == 0x7fffffff) ||
       (uVar13 = _RNvMs5_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE11append_scan
                           (param_1,iVar11,0x7fffffff,(undefined4 *)&DAT_00000004,0),
       (int)uVar13 == 0)) {
      cVar6 = _RNvNtCsjsHfHFRyfyy_10gdi_region3ffi60Feature_Servicing_Win32kRSFloodFillBoundingBox_ffi_IsEnabled
                        ();
      if (cVar6 == '\0') {
        uVar13 = 0;
        uVar9 = param_1[2];
      }
      else {
        *(int *)((longlong)param_1 + 0x1c) = local_b8;
        *(undefined4 *)(param_1 + 4) = uVar2;
        *(int *)((longlong)param_1 + 0x24) = local_b4;
        *(int *)(param_1 + 5) = iVar14;
        uVar13 = 0;
        uVar9 = param_1[2];
      }
    }
    else {
      uVar13 = uVar13 & 0xffffffff;
      uVar9 = param_1[2];
    }
joined_r0x00014000e320:
    if (uVar9 == 0) {
      _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore16set_to_null_scan(param_1);
      if ((local_48 ^ (ulonglong)auStackY_e8) == __security_cookie) {
        return uVar13;
      }
      goto LAB_14000e3bc;
    }
  }
  if ((local_48 ^ (ulonglong)auStackY_e8) == __security_cookie) {
    return uVar13;
  }
LAB_14000e3bc:
  pcVar4 = (code *)swi(3);
  uVar9 = (*pcVar4)();
  return uVar9;
}



===== _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore20upload_for_floodfill @ 14000e470 =====

ulonglong _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore20upload_for_floodfill
                    (ulonglong *param_1,int *param_2,ulonglong param_3,undefined **param_4,
                    ulonglong param_5)

{
  int iVar1;
  int iVar2;
  byte bVar3;
  ulonglong uVar4;
  
  bVar3 = _RNvNtCsjsHfHFRyfyy_10gdi_region3ffi60Feature_Servicing_Win32kRSFloodFillBoundingBox_ffi_IsEnabled
                    ();
  if ((param_3 < 3 & bVar3) == 0) {
    if (param_3 < 2) {
                    /* WARNING: Subroutine does not return */
      _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
    }
    if (param_3 == 2) {
                    /* WARNING: Subroutine does not return */
      _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
    }
    iVar1 = param_2[1];
    if (iVar1 + 1 == param_2[2]) {
      iVar2 = *param_2;
      _RNvNtCsjsHfHFRyfyy_10gdi_region3ffi60Feature_Servicing_Win32kRSFloodFillBoundingBox_ffi_IsEnabled
                ();
      if ((longlong)iVar2 * 2 == param_3 - 3) {
        uVar4 = _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore15insert_scanline
                          (param_1,iVar1,param_2 + 3,param_3 - 3,param_4,param_5);
        return uVar4;
      }
    }
  }
  return 0x57;
}



===== _RINvCsgf1RBdmyjwT_12fallible_vec20try_with_capacity_inlINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EECscIyU0BP6seX_7rgncore @ 14000e540 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong *
_RINvCsgf1RBdmyjwT_12fallible_vec20try_with_capacity_inlINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EECscIyU0BP6seX_7rgncore
          (ulonglong *param_1,ulonglong param_2)

{
  code *pcVar1;
  ulonglong *puVar2;
  ulonglong uVar3;
  undefined1 auStack_98 [32];
  ulonglong *local_78;
  ulonglong local_68;
  ulonglong local_60;
  ulonglong local_58;
  byte local_50 [8];
  ulonglong local_48;
  ulonglong uStack_40;
  undefined8 local_38;
  undefined8 local_30;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_98;
  local_68 = 0;
  local_60 = 4;
  local_58 = 0;
  if (param_2 == 0) {
LAB_14000e64f:
    param_1[2] = local_58;
    *param_1 = local_68;
    param_1[1] = local_60;
  }
  else {
    uVar3 = 4;
    if (4 < param_2) {
      uVar3 = param_2;
    }
    if (param_2 >> 0x3e != 0 || 0x7ffffffffffffffc < uVar3 * 4) {
      param_1[1] = 0;
      *param_1 = 0x8000000000000000;
      if ((local_20 ^ (ulonglong)auStack_98) == __security_cookie) {
        return param_1;
      }
      goto LAB_14000e69e;
    }
    local_30 = 0;
    local_78 = &local_58;
    _RINvNtCsip5f2bf5HGI_5alloc7raw_vec11finish_growINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EECscIyU0BP6seX_7rgncore_llvm_13477870103536380358
              ((ulonglong *)local_50,&DAT_00000004,uVar3 * 4,&local_38);
    if ((local_50[0] & 1) == 0) {
      local_60 = local_48;
      local_68 = uVar3;
      goto LAB_14000e64f;
    }
    param_1[1] = local_48;
    param_1[2] = uStack_40;
    *param_1 = 0x8000000000000000;
    if (local_68 != 0) {
      if (local_68 == 0x1c) {
        _RNvNtCsjsHfHFRyfyy_10gdi_region3ffi22ScanLookAsideList_Free();
        if ((local_20 ^ (ulonglong)auStack_98) == __security_cookie) {
          return param_1;
        }
      }
      else {
        _RNvNtCsiNQa5DCRmUC_9gdi_alloc3ffi13Win32FreePool();
        if ((local_20 ^ (ulonglong)auStack_98) == __security_cookie) {
          return param_1;
        }
      }
      goto LAB_14000e69e;
    }
  }
  if ((local_20 ^ (ulonglong)auStack_98) == __security_cookie) {
    return param_1;
  }
LAB_14000e69e:
  pcVar1 = (code *)swi(3);
  puVar2 = (ulonglong *)(*pcVar1)();
  return puVar2;
}



===== median3_rec<ref$<onecore_windows::windef::_RECTL>,core::slice::impl$0::sort_unstable_by_key::closure_env$0<ref$<onecore_windows::windef::_RECTL>,i32,rgncore::impl$1::subtract_complex::closure_env$0>_> @ 14000e6b0 =====

longlong *
core::slice::sort::shared::pivot::
median3_rec<ref_<onecore_windows::windef::_RECTL>,core::slice::impl_0::sort_unstable_by_key::closure_env_0<ref_<onecore_windows::windef::_RECTL>,i32,rgncore::impl_1::subtract_complex::closure_env_0>_>
          (longlong *param_1,longlong *param_2,longlong *param_3,ulonglong param_4)

{
  int iVar1;
  int iVar2;
  ulonglong uVar3;
  
  if (7 < param_4) {
    uVar3 = param_4 >> 3;
    param_1 = median3_rec<ref_<onecore_windows::windef::_RECTL>,core::slice::impl_0::sort_unstable_by_key::closure_env_0<ref_<onecore_windows::windef::_RECTL>,i32,rgncore::impl_1::subtract_complex::closure_env_0>_>
                        (param_1,param_1 + uVar3 * 4,param_1 + uVar3 * 7,uVar3);
    param_2 = median3_rec<ref_<onecore_windows::windef::_RECTL>,core::slice::impl_0::sort_unstable_by_key::closure_env_0<ref_<onecore_windows::windef::_RECTL>,i32,rgncore::impl_1::subtract_complex::closure_env_0>_>
                        (param_2,param_2 + uVar3 * 4,param_2 + uVar3 * 7,uVar3);
    param_3 = median3_rec<ref_<onecore_windows::windef::_RECTL>,core::slice::impl_0::sort_unstable_by_key::closure_env_0<ref_<onecore_windows::windef::_RECTL>,i32,rgncore::impl_1::subtract_complex::closure_env_0>_>
                        (param_3,param_3 + uVar3 * 4,param_3 + uVar3 * 7,uVar3);
  }
  iVar1 = *(int *)(*param_1 + 4);
  iVar2 = *(int *)(*param_2 + 4);
  if (iVar2 < *(int *)(*param_3 + 4) != iVar1 < iVar2) {
    param_2 = param_3;
  }
  if (iVar1 < *(int *)(*param_3 + 4) != iVar1 < iVar2) {
    param_2 = param_1;
  }
  return param_2;
}



===== _RINvNtNtNtNtCsloaxXL3qbEI_4core5slice4sort8unstable9quicksort9quicksortRNtNtCs2JCLxFJL4Mh_15onecore_windows6windef6__RECTLNCINvMB8_SB17_20sort_unstable_by_keylNCNvMs_CscIyU0BP6seX_7rgncoreNtB2E_10RegionCore16subtract_complex0E0EB2E_ @ 14000e770 =====

void _RINvNtNtNtNtCsloaxXL3qbEI_4core5slice4sort8unstable9quicksort9quicksortRNtNtCs2JCLxFJL4Mh_15onecore_windows6windef6__RECTLNCINvMB8_SB17_20sort_unstable_by_keylNCNvMs_CscIyU0BP6seX_7rgncoreNtB2E_10RegionCore16subtract_complex0E0EB2E_
               (longlong *param_1,ulonglong param_2,longlong *param_3,int param_4,undefined8 param_5
               )

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  code *pcVar4;
  longlong lVar5;
  longlong *plVar6;
  longlong lVar7;
  longlong *plVar8;
  longlong *plVar9;
  ulonglong uVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong lVar13;
  bool bVar14;
  
  if (0x20 < param_2) {
    plVar12 = param_1;
    do {
      while( true ) {
        bVar14 = param_4 == 0;
        param_4 = param_4 + -1;
        if (bVar14) {
          _RINvNtNtNtNtCsloaxXL3qbEI_4core5slice4sort8unstable8heapsort8heapsortRNtNtCs2JCLxFJL4Mh_15onecore_windows6windef6__RECTLNCINvMB8_SB15_20sort_unstable_by_keylNCNvMs_CscIyU0BP6seX_7rgncoreNtB2C_10RegionCore16subtract_complex0E0EB2C_
                    (plVar12,param_2);
          return;
        }
        uVar10 = param_2 >> 3;
        plVar6 = plVar12 + uVar10 * 4;
        plVar9 = plVar12 + uVar10 * 7;
        if (0x3f < param_2) break;
        iVar1 = *(int *)(*plVar12 + 4);
        iVar2 = *(int *)(*plVar6 + 4);
        if (iVar2 < *(int *)(*plVar9 + 4) != iVar1 < iVar2) {
          plVar6 = plVar9;
        }
        if (iVar1 < *(int *)(*plVar9 + 4) != iVar1 < iVar2) {
          plVar6 = plVar12;
        }
        lVar5 = (longlong)plVar6 - (longlong)plVar12;
        if (param_3 != (longlong *)0x0) goto LAB_14000e876;
LAB_14000e937:
        lVar13 = *plVar12;
        lVar7 = *(longlong *)((longlong)plVar12 + lVar5);
LAB_14000e93e:
        *plVar12 = lVar7;
        *(longlong *)((longlong)plVar12 + lVar5) = lVar13;
        plVar6 = plVar12 + 1;
        lVar5 = *plVar12;
        lVar7 = plVar12[1];
        plVar9 = plVar12 + 2;
        if (plVar9 < plVar12 + (param_2 - 1)) {
          lVar13 = 0;
          do {
            plVar11 = plVar9;
            iVar2 = *(int *)(*plVar11 + 4);
            iVar1 = *(int *)(lVar5 + 4);
            plVar11[-1] = plVar6[lVar13];
            plVar6[lVar13] = *plVar11;
            lVar13 = (ulonglong)(iVar2 < iVar1) + lVar13;
            iVar2 = *(int *)(plVar11[1] + 4);
            iVar1 = *(int *)(lVar5 + 4);
            *plVar11 = plVar6[lVar13];
            plVar6[lVar13] = plVar11[1];
            lVar13 = (ulonglong)(iVar2 < iVar1) + lVar13;
            plVar9 = plVar11 + 2;
          } while (plVar9 < plVar12 + (param_2 - 1));
          plVar11 = plVar11 + 1;
          if (plVar9 != plVar12 + param_2) goto LAB_14000e9e0;
        }
        else {
          lVar13 = 0;
          plVar11 = plVar6;
          if (plVar9 != plVar12 + param_2) {
LAB_14000e9e0:
            do {
              plVar8 = plVar9;
              lVar3 = *plVar8;
              iVar2 = *(int *)(lVar3 + 4);
              iVar1 = *(int *)(lVar5 + 4);
              *plVar11 = plVar6[lVar13];
              plVar6[lVar13] = lVar3;
              lVar13 = (ulonglong)(iVar2 < iVar1) + lVar13;
              plVar9 = plVar8 + 1;
              plVar11 = plVar8;
            } while (plVar8 + 1 != plVar12 + param_2);
          }
        }
        iVar2 = *(int *)(lVar7 + 4);
        iVar1 = *(int *)(lVar5 + 4);
        *plVar11 = plVar6[lVar13];
        plVar6[lVar13] = lVar7;
        uVar10 = (ulonglong)(iVar2 < iVar1) + lVar13;
        if (param_2 <= uVar10) {
LAB_14000eaf9:
                    /* WARNING: Does not return */
          pcVar4 = (code *)invalidInstructionException();
          (*pcVar4)();
        }
        plVar6 = plVar12 + uVar10;
        lVar5 = *plVar12;
        *plVar12 = plVar12[uVar10];
        plVar12[uVar10] = lVar5;
        param_1 = plVar12 + uVar10 + 1;
        param_2 = param_2 + ~uVar10;
        _RINvNtNtNtNtCsloaxXL3qbEI_4core5slice4sort8unstable9quicksort9quicksortRNtNtCs2JCLxFJL4Mh_15onecore_windows6windef6__RECTLNCINvMB8_SB17_20sort_unstable_by_keylNCNvMs_CscIyU0BP6seX_7rgncoreNtB2E_10RegionCore16subtract_complex0E0EB2E_
                  (plVar12,uVar10,param_3,param_4,param_5);
        plVar12 = param_1;
        param_3 = plVar6;
        if (param_2 < 0x21) goto LAB_14000e794;
      }
      plVar6 = core::slice::sort::shared::pivot::
               median3_rec<ref_<onecore_windows::windef::_RECTL>,core::slice::impl_0::sort_unstable_by_key::closure_env_0<ref_<onecore_windows::windef::_RECTL>,i32,rgncore::impl_1::subtract_complex::closure_env_0>_>
                         (plVar12,plVar6,plVar9,uVar10);
      lVar5 = (longlong)plVar6 - (longlong)plVar12;
      if (param_3 == (longlong *)0x0) goto LAB_14000e937;
LAB_14000e876:
      lVar7 = *(longlong *)((longlong)plVar12 + lVar5);
      lVar13 = *plVar12;
      if (*(int *)(*param_3 + 4) < *(int *)(lVar7 + 4)) goto LAB_14000e93e;
      *plVar12 = lVar7;
      *(longlong *)((longlong)plVar12 + lVar5) = lVar13;
      plVar6 = plVar12 + 1;
      lVar5 = *plVar12;
      lVar7 = plVar12[1];
      plVar9 = plVar12 + 2;
      if (plVar9 < plVar12 + (param_2 - 1)) {
        lVar13 = 0;
        do {
          plVar11 = plVar9;
          iVar2 = *(int *)(lVar5 + 4);
          iVar1 = *(int *)(*plVar11 + 4);
          plVar11[-1] = plVar6[lVar13];
          plVar6[lVar13] = *plVar11;
          lVar13 = (ulonglong)(iVar1 <= iVar2) + lVar13;
          iVar2 = *(int *)(lVar5 + 4);
          iVar1 = *(int *)(plVar11[1] + 4);
          *plVar11 = plVar6[lVar13];
          plVar6[lVar13] = plVar11[1];
          lVar13 = (ulonglong)(iVar1 <= iVar2) + lVar13;
          plVar9 = plVar11 + 2;
        } while (plVar9 < plVar12 + (param_2 - 1));
        plVar11 = plVar11 + 1;
        if (plVar9 != plVar12 + param_2) goto LAB_14000eaa0;
      }
      else {
        lVar13 = 0;
        plVar11 = plVar6;
        if (plVar9 != plVar12 + param_2) {
LAB_14000eaa0:
          do {
            plVar8 = plVar9;
            lVar3 = *plVar8;
            iVar2 = *(int *)(lVar5 + 4);
            iVar1 = *(int *)(lVar3 + 4);
            *plVar11 = plVar6[lVar13];
            plVar6[lVar13] = lVar3;
            lVar13 = (ulonglong)(iVar1 <= iVar2) + lVar13;
            plVar9 = plVar8 + 1;
            plVar11 = plVar8;
          } while (plVar8 + 1 != plVar12 + param_2);
        }
      }
      iVar2 = *(int *)(lVar5 + 4);
      iVar1 = *(int *)(lVar7 + 4);
      *plVar11 = plVar6[lVar13];
      plVar6[lVar13] = lVar7;
      uVar10 = (ulonglong)(iVar1 <= iVar2) + lVar13;
      if (param_2 <= uVar10) goto LAB_14000eaf9;
      lVar5 = *plVar12;
      *plVar12 = plVar12[uVar10];
      plVar12[uVar10] = lVar5;
      param_2 = param_2 - (uVar10 + 1);
      param_1 = plVar12 + uVar10 + 1;
      plVar12 = param_1;
      param_3 = (longlong *)0x0;
    } while (0x20 < param_2);
  }
LAB_14000e794:
  _RINvNtNtNtNtCsloaxXL3qbEI_4core5slice4sort6shared9smallsort18small_sort_networkRNtNtCs2JCLxFJL4Mh_15onecore_windows6windef6__RECTLNCINvMB8_SB1f_20sort_unstable_by_keylNCNvMs_CscIyU0BP6seX_7rgncoreNtB2M_10RegionCore16subtract_complex0E0EB2M_
            (param_1,param_2);
  return;
}



===== _RNvXs19_NtCsloaxXL3qbEI_4core3fmtRINtNtNtB8_3num7nonzero7NonZeromENtB6_5Debug3fmtCscIyU0BP6seX_7rgncore @ 14000eb10 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void _RNvXs19_NtCsloaxXL3qbEI_4core3fmtRINtNtNtB8_3num7nonzero7NonZeromENtB6_5Debug3fmtCscIyU0BP6seX_7rgncore
               (undefined8 *param_1,undefined8 *param_2)

{
  code *pcVar1;
  undefined1 auStack_38 [44];
  uint local_c;
  ulonglong local_8;
  
  local_8 = __security_cookie ^ (ulonglong)auStack_38;
  local_c = *(uint *)*param_1;
  if ((*(uint *)(param_2 + 2) & 0x2000000) == 0) {
    if ((*(uint *)(param_2 + 2) & 0x4000000) == 0) {
      _RNvXs8_NtNtNtCsloaxXL3qbEI_4core3fmt3num3impmNtB9_7Display3fmt(&local_c,param_2);
      if ((local_8 ^ (ulonglong)auStack_38) == __security_cookie) {
        return;
      }
    }
    else {
      _RNvXsV_NtNtCsloaxXL3qbEI_4core3fmt3numlNtB7_8UpperHex3fmt(&local_c,param_2);
      if ((local_8 ^ (ulonglong)auStack_38) == __security_cookie) {
        return;
      }
    }
  }
  else {
    _RNvXsU_NtNtCsloaxXL3qbEI_4core3fmt3numlNtB7_8LowerHex3fmt(&local_c,param_2);
    if ((local_8 ^ (ulonglong)auStack_38) == __security_cookie) {
      return;
    }
  }
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== fmt<core::ptr::alignment::Alignment> @ 14000eba0 =====

void core::fmt::impl$73::fmt<core::ptr::alignment::Alignment>
               (undefined8 *param_1,undefined8 *param_2)

{
  _RNvXs_NtNtCsloaxXL3qbEI_4core3ptr9alignmentNtB4_9AlignmentNtNtB8_3fmt5Debug3fmt
            ((ulonglong *)*param_1,param_2);
  return;
}



===== _RNvNvMNtCscIyU0BP6seX_7rgncore9fill_pathNtB6_10RegionCore30fill_path_with_outline_generic9is_framed @ 14000ebb0 =====

undefined1
_RNvNvMNtCscIyU0BP6seX_7rgncore9fill_pathNtB6_10RegionCore30fill_path_with_outline_generic9is_framed
          (longlong param_1,longlong param_2,longlong param_3,ulonglong param_4)

{
  ulonglong uVar1;
  
  uVar1 = param_2 + *(longlong *)(param_1 + 8) + 3;
  if (param_4 <= uVar1) {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
  }
  return *(undefined1 *)(param_3 + uVar1);
}



===== _RNvNvMNtCscIyU0BP6seX_7rgncore9fill_pathNtB6_10RegionCore30fill_path_with_outline_generic11mark_framed @ 14000ebf0 =====

void _RNvNvMNtCscIyU0BP6seX_7rgncore9fill_pathNtB6_10RegionCore30fill_path_with_outline_generic11mark_framed
               (longlong param_1,longlong param_2,undefined8 param_3,longlong param_4,
               ulonglong param_5)

{
  ulonglong uVar1;
  
  uVar1 = *(longlong *)(param_1 + 8) + param_2 + 3;
  if (param_5 <= uVar1) {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
  }
  *(undefined1 *)(param_4 + uVar1) = 1;
  return;
}



===== _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalRINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E13is_valid_scanCsdyToaWEq7tk_8gdi_rust.llvm.12588874305795175024 @ 14000ec30 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
_RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalRINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E13is_valid_scanCsdyToaWEq7tk_8gdi_rust_llvm_12588874305795175024
          (longlong param_1,ulonglong param_2)

{
  int iVar1;
  int iVar2;
  ulonglong uVar3;
  code *pcVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  longlong lVar7;
  undefined1 auStack_78 [32];
  undefined **local_58;
  longlong local_48;
  longlong local_40 [7];
  ulonglong local_8;
  
  local_8 = __security_cookie ^ (ulonglong)auStack_78;
  uVar3 = *(ulonglong *)(param_1 + 0x10);
  if (param_2 + 4 <= uVar3) {
    if (uVar3 <= param_2) {
LAB_14000ed0a:
                    /* WARNING: Subroutine does not return */
      _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
    }
    iVar1 = *(int *)(*(longlong *)(param_1 + 8) + param_2 * 4);
    lVar7 = (longlong)iVar1;
    if (-1 < lVar7) {
      local_48 = lVar7;
      if (param_2 + 4 + lVar7 <= uVar3) {
        uVar6 = param_2 + lVar7 + 3;
        if (uVar3 <= uVar6) {
                    /* WARNING: Subroutine does not return */
          _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
        }
        iVar2 = *(int *)(*(longlong *)(param_1 + 8) + uVar6 * 4);
        lVar7 = (longlong)iVar2;
        if (-1 < lVar7) {
          uVar5 = CONCAT71((int7)(param_2 >> 8),1);
          local_40[0] = lVar7;
          if (iVar1 == iVar2) goto LAB_14000ec78;
          local_40[1] = 0;
          local_58 = &anon_f6dba0f7d051fd32a92d00a6e1288de4_7_llvm_12588874305795175024;
          _RINvNtCsloaxXL3qbEI_4core9panicking13assert_failedjjEB4_
                    (0,local_40,&local_48,local_40 + 1);
        }
        local_58 = &anon_f6dba0f7d051fd32a92d00a6e1288de4_6_llvm_12588874305795175024;
        _RNvNtCsloaxXL3qbEI_4core6result13unwrap_failed();
        goto LAB_14000ed0a;
      }
    }
  }
  uVar5 = 0;
LAB_14000ec78:
  if ((local_8 ^ (ulonglong)auStack_78) == __security_cookie) {
    return uVar5;
  }
  pcVar4 = (code *)swi(3);
  uVar5 = (*pcVar4)();
  return uVar5;
}



===== _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalRINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E6x_wallCsdyToaWEq7tk_8gdi_rust @ 14000ed30 =====

undefined4
_RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalRINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E6x_wallCsdyToaWEq7tk_8gdi_rust
          (longlong *param_1,ulonglong param_2)

{
  ulonglong uVar1;
  longlong lVar2;
  ulonglong uVar3;
  
  uVar3 = param_1[1];
  uVar1 = *(ulonglong *)(*param_1 + 0x10);
  if (uVar1 <= uVar3) {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
  }
  lVar2 = *(longlong *)(*param_1 + 8);
  if ((ulonglong)(longlong)*(int *)(lVar2 + uVar3 * 4) <= param_2) {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core9panicking5panic();
  }
  uVar3 = uVar3 + param_2 + 3;
  if (uVar1 <= uVar3) {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
  }
  return *(undefined4 *)(lVar2 + uVar3 * 4);
}



===== _RNvMs4_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE11append_wallCsdyToaWEq7tk_8gdi_rust @ 14000eda0 =====

undefined8
_RNvMs4_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE11append_wallCsdyToaWEq7tk_8gdi_rust
          (undefined8 *param_1,undefined4 param_2)

{
  int *piVar1;
  ulonglong *puVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  
  puVar2 = (ulonglong *)*param_1;
  if (puVar2[2] <= (ulonglong)param_1[2]) {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
  }
  piVar1 = (int *)(puVar2[1] + param_1[2] * 4);
  *piVar1 = *piVar1 + 1;
  uVar3 = _RNvMs2_NtCsip5f2bf5HGI_5alloc7raw_vecINtB5_11RawVecInnerINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE11try_reserveCscIyU0BP6seX_7rgncore
                    (puVar2,puVar2[2],1,&DAT_00000004,4);
  uVar4 = 0xe;
  if (uVar3 == 0x8000000000000001) {
    *(undefined4 *)(puVar2[1] + puVar2[2] * 4) = param_2;
    puVar2[2] = puVar2[2] + 1;
    uVar4 = 0;
  }
  return uVar4;
}



===== _RNvMs4_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE18commit_or_coalesceCsdyToaWEq7tk_8gdi_rust @ 14000ee30 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong _RNvMs4_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE18commit_or_coalesceCsdyToaWEq7tk_8gdi_rust
                    (undefined8 *param_1)

{
  ulonglong uVar1;
  undefined4 uVar2;
  ulonglong *puVar3;
  ulonglong uVar4;
  int *piVar5;
  code *pcVar6;
  int iVar7;
  ulonglong uVar8;
  longlong lVar9;
  undefined8 uVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  ulonglong uVar15;
  undefined1 auStackY_78 [32];
  
  uVar8 = __security_cookie ^ (ulonglong)auStackY_78;
  puVar3 = (ulonglong *)*param_1;
  uVar13 = param_1[2];
  if (uVar13 == 0) {
    uVar12 = puVar3[2];
LAB_14000ef08:
    if (uVar12 <= uVar13) {
                    /* WARNING: Subroutine does not return */
      _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
    }
    piVar5 = (int *)param_1[1];
    uVar2 = *(undefined4 *)(puVar3[1] + uVar13 * 4);
    uVar12 = _RNvMs2_NtCsip5f2bf5HGI_5alloc7raw_vecINtB5_11RawVecInnerINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE11try_reserveCscIyU0BP6seX_7rgncore
                       (puVar3,uVar12,1,&DAT_00000004,4);
    if (uVar12 == 0x8000000000000001) {
      *(undefined4 *)(puVar3[1] + puVar3[2] * 4) = uVar2;
      puVar3[2] = puVar3[2] + 1;
      *piVar5 = *piVar5 + 1;
      uVar15 = 0x100;
      uVar12 = 0;
LAB_14000efc9:
      if ((uVar8 ^ (ulonglong)auStackY_78) == __security_cookie) {
        return uVar12 | uVar15;
      }
      pcVar6 = (code *)swi(3);
      uVar13 = (*pcVar6)();
      return uVar13;
    }
    if (uVar13 <= puVar3[2]) {
      uVar15 = 0xe00000000;
      puVar3[2] = uVar13;
      uVar12 = 1;
      if (uVar13 == 0) {
        _RNvNtCsjsHfHFRyfyy_10gdi_region3ffi27RustOnZeroSizedScanCallback();
        uVar12 = 1;
      }
      goto LAB_14000efc9;
    }
    goto LAB_14000f060;
  }
  if (puVar3[2] <= uVar13 - 1) {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
  }
  lVar9 = (longlong)*(int *)((puVar3[1] - 4) + uVar13 * 4);
  if (lVar9 < 0) {
    _RNvNtCsloaxXL3qbEI_4core6result13unwrap_failed();
LAB_14000f01b:
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core9panicking5panic();
  }
  lVar9 = uVar13 - lVar9;
  uVar15 = lVar9 - 4;
  uVar10 = _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalRINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E13is_valid_scanCsdyToaWEq7tk_8gdi_rust_llvm_12588874305795175024
                     ((longlong)puVar3,uVar15);
  if ((char)uVar10 == '\0') goto LAB_14000f01b;
  uVar12 = puVar3[2];
  if (uVar12 <= uVar15) {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
  }
  uVar1 = lVar9 - 1;
  uVar4 = puVar3[1];
  uVar14 = (ulonglong)*(int *)(uVar4 + uVar15 * 4);
  uVar11 = uVar1 + uVar14;
  if (CARRY8(uVar1,uVar14)) {
    uVar12 = uVar11;
    uVar11 = _RNvNtNtCsloaxXL3qbEI_4core5slice5index22slice_index_order_fail();
LAB_14000f042:
    _RNvNtNtCsloaxXL3qbEI_4core5slice5index24slice_end_index_len_fail
              (uVar11,uVar12,
               &PTR_anon_f6dba0f7d051fd32a92d00a6e1288de4_0_llvm_12588874305795175024_1400199d0);
  }
  else {
    if (uVar12 < uVar11) goto LAB_14000f042;
    uVar11 = uVar13 + 3;
    if (uVar11 <= uVar12) {
      if ((uVar12 - uVar11 == uVar14) &&
         (iVar7 = memcmp((void *)(uVar4 + uVar1 * 4),(void *)(uVar4 + uVar11 * 4),uVar14 << 2),
         iVar7 == 0)) {
        if (uVar12 <= uVar13 + 2) {
                    /* WARNING: Subroutine does not return */
          _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
        }
        if (uVar12 <= lVar9 - 2U) {
                    /* WARNING: Subroutine does not return */
          _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
        }
        *(undefined4 *)(uVar4 + 8 + uVar15 * 4) = *(undefined4 *)(uVar4 + 8 + uVar13 * 4);
        if (uVar13 <= puVar3[2]) {
          puVar3[2] = uVar13;
          uVar12 = 0;
          uVar15 = 0;
          goto LAB_14000efc9;
        }
        goto LAB_14000f060;
      }
      goto LAB_14000ef08;
    }
  }
  _RNvNtNtCsloaxXL3qbEI_4core5slice5index26slice_start_index_len_fail();
LAB_14000f060:
                    /* WARNING: Subroutine does not return */
  _RNvNtCsloaxXL3qbEI_4core9panicking5panic();
}



===== _RNvMs4_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE8pop_wallCsdyToaWEq7tk_8gdi_rust @ 14000f0d0 =====

void _RNvMs4_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE8pop_wallCsdyToaWEq7tk_8gdi_rust
               (longlong *param_1)

{
  int iVar1;
  longlong lVar2;
  ulonglong uVar3;
  longlong lVar4;
  
  lVar2 = *param_1;
  uVar3 = param_1[2];
  if (*(ulonglong *)(lVar2 + 0x10) <= uVar3) {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
  }
  iVar1 = *(int *)(*(longlong *)(lVar2 + 8) + uVar3 * 4);
  if (iVar1 < 1) {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core9panicking5panic();
  }
  *(int *)(*(longlong *)(lVar2 + 8) + uVar3 * 4) = iVar1 + -1;
  if ((*(longlong *)(lVar2 + 0x10) == 0) ||
     (lVar4 = *(longlong *)(lVar2 + 0x10) + -1, *(longlong *)(lVar2 + 0x10) = lVar4, lVar4 == 0)) {
    _RNvNtCsjsHfHFRyfyy_10gdi_region3ffi27RustOnZeroSizedScanCallback();
    return;
  }
  return;
}



===== fmt<tuple$<>_> @ 14000f150 =====

void core::fmt::impl$73::fmt<tuple_<>_>(undefined8 param_1,longlong param_2)

{
  _RNvMs9_NtCsloaxXL3qbEI_4core3fmtNtB5_9Formatter3pad(param_2,(byte *)0x14001adc3,2);
  return;
}



===== _RNvXs5_NtNtCsloaxXL3qbEI_4core3num5errorNtB5_15TryFromIntErrorNtNtB9_3fmt5Debug3fmt.llvm.12588874305795175024 @ 14000f170 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void _RNvXs5_NtNtCsloaxXL3qbEI_4core3num5errorNtB5_15TryFromIntErrorNtNtB9_3fmt5Debug3fmt_llvm_12588874305795175024
               (undefined8 param_1,undefined8 *param_2)

{
  code *pcVar1;
  undefined1 auStack_38 [32];
  undefined *local_18;
  undefined8 local_10;
  ulonglong local_8;
  
  local_8 = __security_cookie ^ (ulonglong)auStack_38;
  local_18 = &DAT_140019b20;
  local_10 = param_1;
  _RNvMs9_NtCsloaxXL3qbEI_4core3fmtNtB5_9Formatter25debug_tuple_field1_finish
            (param_2,
             "TryFromIntError()assertion failed: !self.ppath.is_null()gdi_rust\\src\\pathobj.rs",0xf
            );
  if ((local_8 ^ (ulonglong)auStack_38) == __security_cookie) {
    return;
  }
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== _RNvXs6_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EENtNtNtCsloaxXL3qbEI_4core3ops4drop4Drop4dropCsdyToaWEq7tk_8gdi_rust @ 14000f1e0 =====

void _RNvXs6_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EENtNtNtCsloaxXL3qbEI_4core3ops4drop4Drop4dropCsdyToaWEq7tk_8gdi_rust
               (longlong *param_1)

{
  ulonglong uVar1;
  
  uVar1 = param_1[2];
  if (*(ulonglong *)(*param_1 + 0x10) < uVar1) {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core9panicking5panic();
  }
  *(ulonglong *)(*param_1 + 0x10) = uVar1;
  if (uVar1 == 0) {
    _RNvNtCsjsHfHFRyfyy_10gdi_region3ffi27RustOnZeroSizedScanCallback();
    return;
  }
  return;
}



===== memcmp @ 14000f230 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl memcmp(void *_Buf1,void *_Buf2,size_t _Size)

{
  char *pcVar1;
  char *pcVar2;
  code *pcVar3;
  int iVar4;
  uint uVar5;
  ulonglong uVar6;
  uint uVar7;
  ulonglong *puVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  undefined1 auVar11 [16];
  undefined1 local_21;
  undefined1 *local_20;
  undefined1 **local_18;
  undefined8 local_10;
  
  local_10 = __security_cookie ^ (longlong)register0x00000020 - 8U;
  local_20 = &local_21;
  local_18 = &local_20;
  if (_Size < 0x10) {
    puVar8 = _Buf1;
  }
  else {
    puVar8 = (ulonglong *)((_Size & 0xfffffffffffffff0) + (longlong)_Buf1);
    uVar10 = 0;
    do {
      pcVar1 = (char *)((longlong)_Buf1 + uVar10);
      pcVar2 = (char *)((longlong)_Buf2 + uVar10);
      auVar11[0] = -(*pcVar2 == *pcVar1);
      auVar11[1] = -(pcVar2[1] == pcVar1[1]);
      auVar11[2] = -(pcVar2[2] == pcVar1[2]);
      auVar11[3] = -(pcVar2[3] == pcVar1[3]);
      auVar11[4] = -(pcVar2[4] == pcVar1[4]);
      auVar11[5] = -(pcVar2[5] == pcVar1[5]);
      auVar11[6] = -(pcVar2[6] == pcVar1[6]);
      auVar11[7] = -(pcVar2[7] == pcVar1[7]);
      auVar11[8] = -(pcVar2[8] == pcVar1[8]);
      auVar11[9] = -(pcVar2[9] == pcVar1[9]);
      auVar11[10] = -(pcVar2[10] == pcVar1[10]);
      auVar11[0xb] = -(pcVar2[0xb] == pcVar1[0xb]);
      auVar11[0xc] = -(pcVar2[0xc] == pcVar1[0xc]);
      auVar11[0xd] = -(pcVar2[0xd] == pcVar1[0xd]);
      auVar11[0xe] = -(pcVar2[0xe] == pcVar1[0xe]);
      auVar11[0xf] = -(pcVar2[0xf] == pcVar1[0xf]);
      if ((ushort)((ushort)(SUB161(auVar11 >> 7,0) & 1) |
                   (ushort)(SUB161(auVar11 >> 0xf,0) & 1) << 1 |
                   (ushort)(SUB161(auVar11 >> 0x17,0) & 1) << 2 |
                   (ushort)(SUB161(auVar11 >> 0x1f,0) & 1) << 3 |
                   (ushort)(SUB161(auVar11 >> 0x27,0) & 1) << 4 |
                   (ushort)(SUB161(auVar11 >> 0x2f,0) & 1) << 5 |
                   (ushort)(SUB161(auVar11 >> 0x37,0) & 1) << 6 |
                   (ushort)(SUB161(auVar11 >> 0x3f,0) & 1) << 7 |
                   (ushort)(SUB161(auVar11 >> 0x47,0) & 1) << 8 |
                   (ushort)(SUB161(auVar11 >> 0x4f,0) & 1) << 9 |
                   (ushort)(SUB161(auVar11 >> 0x57,0) & 1) << 10 |
                   (ushort)(SUB161(auVar11 >> 0x5f,0) & 1) << 0xb |
                   (ushort)(SUB161(auVar11 >> 0x67,0) & 1) << 0xc |
                   (ushort)(SUB161(auVar11 >> 0x6f,0) & 1) << 0xd |
                   (ushort)(SUB161(auVar11 >> 0x77,0) & 1) << 0xe |
                  (ushort)(auVar11[0xf] >> 7) << 0xf) != 0xffff) {
        uVar6 = *(ulonglong *)((longlong)_Buf1 + uVar10);
        uVar9 = *(ulonglong *)((longlong)_Buf2 + uVar10);
        if (uVar6 == uVar9) {
          uVar6 = *(ulonglong *)((longlong)_Buf1 + uVar10 + 8);
          uVar9 = *(ulonglong *)((longlong)_Buf2 + uVar10 + 8);
          if (uVar6 != uVar9) goto LAB_14000f2ff;
LAB_14000f334:
          iVar4 = 0;
        }
        else {
LAB_14000f2ff:
          if ((int)uVar6 == (int)uVar9) {
            uVar9 = uVar9 >> 0x20;
            uVar6 = uVar6 >> 0x20;
            if (uVar6 == uVar9) goto LAB_14000f334;
          }
          if ((short)uVar6 == (short)uVar9) {
            uVar9 = uVar9 >> 0x10 & 0xffff;
            uVar6 = uVar6 >> 0x10 & 0xffff;
            if ((int)uVar6 == (int)uVar9) goto LAB_14000f334;
          }
          uVar7 = (uint)uVar9;
          uVar5 = (uint)uVar6;
          if ((char)uVar6 == (char)uVar9) {
            uVar7 = (uint)((uVar9 & 0xffff) >> 8);
            uVar5 = (uint)((uVar6 & 0xffff) >> 8);
            if ((short)((uVar6 & 0xffff) >> 8) == (short)((uVar9 & 0xffff) >> 8))
            goto LAB_14000f334;
          }
          iVar4 = (uVar5 & 0xff) - (uVar7 & 0xff);
        }
        goto LAB_14000f2c7;
      }
      uVar10 = uVar10 + 0x10;
    } while ((_Size & 0xfffffffffffffff0) != uVar10);
    _Buf2 = (void *)((longlong)_Buf2 + uVar10);
  }
  iVar4 = _RNCNvNtNtCsgPWNLo2c3FO_17compiler_builtins3mem5impls13compare_bytess1_0B7__llvm_5483110067693423320
                    (&local_18,puVar8,_Buf2,(ulonglong)((uint)_Size & 0xf));
LAB_14000f2c7:
  if ((local_10 ^ (longlong)register0x00000020 - 8U) == __security_cookie) {
    return iVar4;
  }
  pcVar3 = (code *)swi(3);
  iVar4 = (*pcVar3)();
  return iVar4;
}



===== .weak.memset.default.__llvm_retpoline_r11 @ 14000f350 =====

void * __cdecl _weak_memset_default___llvm_retpoline_r11(void *_Dst,int _Val,size_t _Size)

{
  undefined1 uVar1;
  longlong lVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  longlong *plVar6;
  
  uVar3 = (ulonglong)(-(int)_Dst & 7);
  if (_Size < uVar3) {
    uVar3 = _Size;
  }
  lVar2 = (ulonglong)(byte)_Val * 0x101010101010101;
  uVar5 = _Size - uVar3 >> 3;
  uVar4 = (ulonglong)((uint)(_Size - uVar3) & 7);
  plVar6 = _Dst;
  for (; uVar1 = (undefined1)lVar2, uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined1 *)plVar6 = uVar1;
    plVar6 = (longlong *)((longlong)plVar6 + 1);
  }
  for (; uVar5 != 0; uVar5 = uVar5 - 1) {
    *plVar6 = lVar2;
    plVar6 = plVar6 + 1;
  }
  for (; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined1 *)plVar6 = uVar1;
    plVar6 = (longlong *)((longlong)plVar6 + 1);
  }
  return _Dst;
}



===== _RNvCs8cVqplN8eB1_7___rustc12___rust_alloc @ 14000f3a0 =====

void _RNvCs8cVqplN8eB1_7___rustc12___rust_alloc(undefined8 param_1,ulonglong param_2)

{
  _RNvXCsiNQa5DCRmUC_9gdi_allocNtB2_14Win32AllocatorNtNtNtCsloaxXL3qbEI_4core5alloc6global11GlobalAlloc5alloc
            (&DAT_14001ae04,param_2,param_1);
  return;
}



===== _RNvCs8cVqplN8eB1_7___rustc14___rust_dealloc @ 14000f3c0 =====

void _RNvCs8cVqplN8eB1_7___rustc14___rust_dealloc(void)

{
  _RNvXCsiNQa5DCRmUC_9gdi_allocNtB2_14Win32AllocatorNtNtNtCsloaxXL3qbEI_4core5alloc6global11GlobalAlloc7dealloc
            ();
  return;
}



===== _RNvCs8cVqplN8eB1_7___rustc14___rust_realloc @ 14000f3e0 =====

void * _RNvCs8cVqplN8eB1_7___rustc14___rust_realloc
                 (void *param_1,ulonglong param_2,ulonglong param_3,ulonglong param_4)

{
  void *_Dst;
  
  _Dst = (void *)_RNvXCsiNQa5DCRmUC_9gdi_allocNtB2_14Win32AllocatorNtNtNtCsloaxXL3qbEI_4core5alloc6global11GlobalAlloc5alloc
                           (&DAT_14001ae04,param_3,param_4);
  if (_Dst != (void *)0x0) {
    if (param_2 <= param_4) {
      param_4 = param_2;
    }
    _weak_memcpy_default___llvm_retpoline_r11(_Dst,param_1,param_4);
    _RNvXCsiNQa5DCRmUC_9gdi_allocNtB2_14Win32AllocatorNtNtNtCsloaxXL3qbEI_4core5alloc6global11GlobalAlloc7dealloc
              ();
  }
  return _Dst;
}



===== drop_in_place<handle_manager::GdiHandleEntryDirectory::GdiHandleEntryDirectory> @ 14000f450 =====

void core::ptr::drop_in_place<handle_manager::GdiHandleEntryDirectory::GdiHandleEntryDirectory>
               (longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  
  lVar5 = 0;
  do {
    plVar1 = *(longlong **)(param_1 + lVar5 * 8);
    if (plVar1 != (longlong *)0x0) {
      if (((*(byte *)(plVar1 + 7) != 2) && ((*(byte *)(plVar1 + 7) & 1) != 0)) && (plVar1[6] != 0))
      {
        _RNvNtCsiNQa5DCRmUC_9gdi_alloc3ffi13Win32FreePool();
      }
      lVar2 = *plVar1;
      if (!SBORROW8(0,lVar2)) {
        lVar3 = plVar1[2];
        if (lVar3 != 0) {
          lVar4 = plVar1[1] + 8;
          do {
            if (*(longlong *)(lVar4 + -8) != 0) {
              _RNvNtCsiNQa5DCRmUC_9gdi_alloc3ffi13Win32FreePool();
            }
            lVar4 = lVar4 + 0x18;
            lVar3 = lVar3 + -1;
          } while (lVar3 != 0);
        }
        if (lVar2 != 0) {
          _RNvNtCsiNQa5DCRmUC_9gdi_alloc3ffi13Win32FreePool();
        }
      }
      _RNvNtCsiNQa5DCRmUC_9gdi_alloc3ffi13Win32FreePool();
    }
    lVar5 = lVar5 + 1;
  } while (lVar5 != 0x100);
  return;
}



===== fmt<enum2$<alloc::collections::TryReserveErrorKind>_> @ 14000f520 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong core::fmt::impl$73::fmt<enum2_<alloc::collections::TryReserveErrorKind>_>
                    (undefined8 *param_1,longlong param_2)

{
  code *pcVar1;
  ulonglong uVar2;
  undefined1 auStackY_78 [32];
  
  if (*(longlong *)*param_1 != 0) {
    uVar2 = _RNvMs9_NtCsloaxXL3qbEI_4core3fmtNtB5_9Formatter26debug_struct_field2_finish
                      (param_2,
                       "AllocErrorlayoutnon_exhaustive()called `Result::unwrap()` on an `Err` valuehandle_manager\\src\\GdiHandleEntryTable.rs"
                       ,10,0x14001ae5c,6,(longlong *)*param_1,&DAT_140019bb8,0x14001ae62,0xe);
    return uVar2 & 0xffffffff;
  }
  if ((__security_cookie ^ (ulonglong)auStackY_78 ^ (ulonglong)auStackY_78) == __security_cookie) {
    uVar2 = _RNvXsa_NtCsloaxXL3qbEI_4core3fmtNtB5_9FormatterNtB5_5Write9write_str();
    return uVar2;
  }
  pcVar1 = (code *)swi(3);
  uVar2 = (*pcVar1)();
  return uVar2;
}



===== fmt<tuple$<>_> @ 14000f600 =====

void core::fmt::impl$73::fmt<tuple_<>_>(undefined8 param_1,longlong param_2)

{
  _RNvMs9_NtCsloaxXL3qbEI_4core3fmtNtB5_9Formatter3pad(param_2,(byte *)0x14001ae70,2);
  return;
}



===== fmt @ 14000f620 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void core::fmt::num::impl$91::fmt(ulonglong *param_1,undefined8 *param_2)

{
  bool bVar1;
  code *pcVar2;
  longlong lVar3;
  longlong lVar4;
  ulonglong uVar5;
  byte bVar6;
  char cVar7;
  undefined1 auStack_48 [55];
  char cStack_11;
  ulonglong uStack_10;
  
  if ((*(uint *)(param_2 + 2) & 0x2000000) != 0) {
    uStack_10 = __security_cookie ^ (ulonglong)auStack_48;
    lVar3 = 0;
    uVar5 = *param_1;
    do {
      lVar4 = lVar3;
      bVar6 = (byte)uVar5 & 0xf;
      cVar7 = bVar6 + 0x57;
      if (bVar6 < 10) {
        cVar7 = bVar6 + 0x30;
      }
      auStack_48[lVar4 + 0x37] = cVar7;
      bVar1 = 0xf < uVar5;
      lVar3 = lVar4 + -1;
      uVar5 = uVar5 >> 4;
    } while (bVar1);
    _RNvMs9_NtCsloaxXL3qbEI_4core3fmtNtB5_9Formatter12pad_integral
              (param_2,'\x01',
               (undefined2 *)
               "0x00010203040506070809101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899user-provided comparison function does not correctly implement a total orderlibrary\\core\\src\\slice\\sort\\shared\\smallsort.rs"
               ,2,auStack_48 + lVar4 + 0x37,-(lVar4 + -1));
    if ((uStack_10 ^ (ulonglong)auStack_48) == __security_cookie) {
      return;
    }
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  if ((*(uint *)(param_2 + 2) & 0x4000000) == 0) {
    _RNvXsi_NtNtNtCsloaxXL3qbEI_4core3fmt3num3impjNtB9_7Display3fmt(param_1,param_2);
    return;
  }
  uStack_10 = __security_cookie ^ (ulonglong)auStack_48;
  lVar3 = 0;
  uVar5 = *param_1;
  do {
    lVar4 = lVar3;
    bVar6 = (byte)uVar5 & 0xf;
    cVar7 = bVar6 + 0x37;
    if (bVar6 < 10) {
      cVar7 = bVar6 + 0x30;
    }
    auStack_48[lVar4 + 0x37] = cVar7;
    bVar1 = 0xf < uVar5;
    lVar3 = lVar4 + -1;
    uVar5 = uVar5 >> 4;
  } while (bVar1);
  _RNvMs9_NtCsloaxXL3qbEI_4core3fmtNtB5_9Formatter12pad_integral
            (param_2,'\x01',
             (undefined2 *)
             "0x00010203040506070809101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899user-provided comparison function does not correctly implement a total orderlibrary\\core\\src\\slice\\sort\\shared\\smallsort.rs"
             ,2,auStack_48 + lVar4 + 0x37,-(lVar4 + -1));
  if ((uStack_10 ^ (ulonglong)auStack_48) == __security_cookie) {
    return;
  }
  pcVar2 = (code *)swi(3);
  (*pcVar2)();
  return;
}



===== fmt @ 14000f650 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void core::alloc::layout::impl$5::fmt(longlong param_1,longlong param_2)

{
  code *pcVar1;
  ulonglong uVar2;
  undefined1 auStackY_68 [32];
  
  uVar2 = __security_cookie ^ (ulonglong)auStackY_68;
  _RNvMs9_NtCsloaxXL3qbEI_4core3fmtNtB5_9Formatter26debug_struct_field2_finish
            (param_2,
             "LayoutsizealignTryReserveErrorkindCapacityOverflowAllocErrorlayoutnon_exhaustive()called `Result::unwrap()` on an `Err` valuehandle_manager\\src\\GdiHandleEntryTable.rs"
             ,6,0x14001ae26,4,param_1 + 8,&DAT_140019b58,0x14001ae2a,5);
  if ((uVar2 ^ (ulonglong)auStackY_68) == __security_cookie) {
    return;
  }
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== fmt @ 14000f700 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void alloc::collections::impl$9::fmt(undefined8 param_1,longlong param_2)

{
  code *pcVar1;
  ulonglong uVar2;
  undefined1 auStackY_48 [32];
  
  uVar2 = __security_cookie ^ (ulonglong)auStackY_48;
  _RNvMs9_NtCsloaxXL3qbEI_4core3fmtNtB5_9Formatter26debug_struct_field1_finish
            (param_2,
             "TryReserveErrorkindCapacityOverflowAllocErrorlayoutnon_exhaustive()called `Result::unwrap()` on an `Err` valuehandle_manager\\src\\GdiHandleEntryTable.rs"
             ,0xf,0x14001ae3e,4);
  if ((uVar2 ^ (ulonglong)auStackY_48) == __security_cookie) {
    return;
  }
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== _Create @ 14000f780 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void handle_manager::GdiHandleEntryTable::GdiHandleEntryTable::_Create
               (undefined8 *param_1,uint param_2,char param_3)

{
  code *pcVar1;
  undefined1 auVar2 [16];
  uint uVar3;
  ulonglong *puVar4;
  ulonglong uVar5;
  undefined4 uVar6;
  ulonglong uVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  ulonglong uVar10;
  longlong lVar11;
  ulonglong uVar12;
  undefined1 auStack_c8 [32];
  undefined **local_a8;
  char local_99;
  ulonglong local_98;
  ulonglong local_90;
  undefined8 *local_88;
  uint local_7c;
  uint local_78 [2];
  undefined8 *local_70;
  undefined8 *local_68;
  undefined8 *local_60;
  undefined8 *local_58;
  longlong local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_c8;
  puVar4 = (ulonglong *)_RNvNtCsiNQa5DCRmUC_9gdi_alloc3ffi14Win32AllocPool(0x50,0x63746547);
  if (puVar4 == (ulonglong *)0x0) {
    *param_1 = 0xe00000001;
    return;
  }
  *puVar4 = 0x8000000000000000;
  *(undefined1 *)(puVar4 + 7) = 2;
  puVar4[8] = 0xffffffff00000000;
  puVar4[9] = 0;
  uVar10 = (ulonglong)param_2;
  local_99 = param_3;
  local_7c = param_2;
  if (param_2 == 0) {
    uVar5 = 0;
    local_98 = 0;
    puVar9 = (undefined8 *)&DAT_00000008;
LAB_14000f80a:
    uVar6 = SUB84(puVar9,0);
    uVar12 = uVar5;
  }
  else {
    uVar12 = uVar10 + 0x1ff >> 9;
    local_98 = 4;
    if (4 < uVar12) {
      local_98 = uVar12;
    }
    local_58 = (undefined8 *)0x0;
    alloc::raw_vec::finish_grow<gdi_alloc::TaggedAllocator<1953260871>_>
              ((undefined8 *)local_78,(ulonglong)(uint)((int)local_98 * 8) * 3,&local_60);
    if (local_78[0] == 1) {
      puVar9 = (undefined8 *)0xe;
      goto LAB_14000fb25;
    }
    *local_70 = 0;
    local_70[1] = 8;
    local_70[2] = 0;
    uVar5 = 1;
    puVar9 = local_70;
    local_90 = uVar12;
    if ((int)uVar12 == 1) goto LAB_14000f80a;
    uVar7 = 1;
    uVar5 = 2;
    puVar8 = (undefined8 *)0x7ffffffffffffff8;
    lVar11 = 0x18;
    do {
      if (uVar7 == local_98) {
        local_98 = uVar7 + 1;
        if (uVar7 + 1 <= uVar5) {
          local_98 = uVar5;
        }
        if (local_98 < 5) {
          local_98 = 4;
        }
        auVar2._8_8_ = 0;
        auVar2._0_8_ = local_98;
        puVar9 = SUB168(auVar2 * ZEXT816(0x18),0);
        local_58 = puVar9;
        local_60 = (undefined8 *)0x0;
        if (puVar8 < puVar9 || SUB168(auVar2 * ZEXT816(0x18),8) != 0) goto LAB_14000fbcc;
        local_58 = (undefined8 *)0x8;
        local_88 = puVar8;
        local_50 = lVar11;
        alloc::raw_vec::finish_grow<gdi_alloc::TaggedAllocator<1953260871>_>
                  ((undefined8 *)local_78,puVar9,&local_60);
        if (local_78[0] == 1) {
          do {
            local_58 = local_68;
            local_60 = local_70;
LAB_14000fbcc:
            local_a8 = &PTR_s_handle_manager_src_GdiHandleEntr_14001ae20_0x7d_140019c18;
            _RNvNtCsloaxXL3qbEI_4core6result13unwrap_failed();
          } while( true );
        }
        uVar12 = local_90;
        puVar8 = local_88;
        puVar9 = local_70;
      }
      *(undefined8 *)((longlong)puVar9 + lVar11) = 0;
      *(undefined8 *)((longlong)puVar9 + lVar11 + 8) = 8;
      *(undefined8 *)((longlong)puVar9 + lVar11 + 0x10) = 0;
      uVar7 = uVar7 + 1;
      uVar5 = uVar5 + 2;
      lVar11 = lVar11 + 0x18;
    } while (uVar12 != uVar7);
    uVar6 = SUB84(puVar9,0);
    if (local_98 == 0x8000000000000000) goto LAB_14000fb25;
  }
  uVar5 = *puVar4;
  if (uVar5 != 0x8000000000000000) {
    uVar7 = puVar4[2];
    local_90 = uVar10;
    local_88 = param_1;
    if (uVar7 != 0) {
      lVar11 = puVar4[1] + 8;
      do {
        if (*(longlong *)(lVar11 + -8) != 0) {
          _RNvNtCsiNQa5DCRmUC_9gdi_alloc3ffi13Win32FreePool();
        }
        lVar11 = lVar11 + 0x18;
        uVar7 = uVar7 - 1;
      } while (uVar7 != 0);
    }
    param_1 = local_88;
    uVar10 = local_90;
    if (uVar5 != 0) {
      _RNvNtCsiNQa5DCRmUC_9gdi_alloc3ffi13Win32FreePool();
    }
  }
  uVar3 = local_7c;
  *puVar4 = local_98;
  *(undefined4 *)(puVar4 + 1) = uVar6;
  *(int *)((longlong)puVar4 + 0xc) = (int)((ulonglong)puVar9 >> 0x20);
  puVar4[2] = uVar12;
  puVar4[3] = uVar10;
  if (local_99 != '\0') {
    if (local_7c == 0) {
      uVar12 = 0;
      local_70 = (undefined8 *)&DAT_00000008;
    }
    else {
      uVar12 = 4;
      if (4 < uVar10) {
        uVar12 = uVar10;
      }
      local_58 = (undefined8 *)0x0;
      alloc::raw_vec::finish_grow<gdi_alloc::TaggedAllocator<1668572487>_>
                ((undefined8 *)local_78,uVar12 * 0x18,&local_60);
      if ((local_78[0] & 1) != 0) {
        puVar9 = (undefined8 *)0xe;
LAB_14000fb25:
        *(int *)((longlong)param_1 + 4) = (int)puVar9;
        *(undefined4 *)param_1 = 1;
        if ((((byte)puVar4[7] != 2) && (((byte)puVar4[7] & 1) != 0)) && (puVar4[6] != 0)) {
          _RNvNtCsiNQa5DCRmUC_9gdi_alloc3ffi13Win32FreePool();
        }
        uVar10 = *puVar4;
        if (uVar10 != 0x8000000000000000) {
          uVar12 = puVar4[2];
          if (uVar12 != 0) {
            lVar11 = puVar4[1] + 8;
            do {
              if (*(longlong *)(lVar11 + -8) != 0) {
                _RNvNtCsiNQa5DCRmUC_9gdi_alloc3ffi13Win32FreePool();
              }
              lVar11 = lVar11 + 0x18;
              uVar12 = uVar12 - 1;
            } while (uVar12 != 0);
          }
          if (uVar10 != 0) {
            _RNvNtCsiNQa5DCRmUC_9gdi_alloc3ffi13Win32FreePool();
          }
        }
        if ((local_48 ^ (ulonglong)auStack_c8) == __security_cookie) {
          _RNvNtCsiNQa5DCRmUC_9gdi_alloc3ffi13Win32FreePool();
          return;
        }
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      _weak_memset_default___llvm_retpoline_r11(local_70,0,uVar10 * 0x18);
    }
    if ((((byte)puVar4[7] != 2) && (((byte)puVar4[7] & 1) != 0)) && (puVar4[6] != 0)) {
      _RNvNtCsiNQa5DCRmUC_9gdi_alloc3ffi13Win32FreePool();
    }
    *(int *)(puVar4 + 4) = (int)local_70;
    *(int *)((longlong)puVar4 + 0x24) = (int)((ulonglong)local_70 >> 0x20);
    puVar4[5] = uVar10;
    puVar4[6] = uVar12;
    *(undefined1 *)(puVar4 + 7) = 1;
  }
  *(uint *)(puVar4 + 8) = uVar3;
  param_1[1] = puVar4;
  *(undefined4 *)param_1 = 0;
  return;
}



===== _RNvMNtCsfOHk4HCp6w5_14handle_manager16GdiHandleManagerNtB2_16GdiHandleManager6Create @ 14000fc20 =====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 *
_RNvMNtCsfOHk4HCp6w5_14handle_manager16GdiHandleManagerNtB2_16GdiHandleManager6Create
          (undefined8 *param_1,uint param_2,undefined8 param_3,uint param_4)

{
  code *pcVar1;
  undefined8 uVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  undefined1 auStack_1078 [36];
  undefined1 local_1054 [2052];
  undefined8 local_850;
  undefined2 local_4c;
  byte local_48 [4];
  undefined4 local_44;
  longlong local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_1078;
  if (param_4 < 0x10000 && param_4 < param_2) {
    uVar2 = 0x5700000001;
  }
  else {
    plVar3 = (longlong *)_RNvNtCsiNQa5DCRmUC_9gdi_alloc3ffi14Win32AllocPool(0x830,0x636d6847);
    if (plVar3 != (longlong *)0x0) {
      *plVar3 = 0;
      plVar3[1] = 4;
      plVar3[2] = 0;
      *(undefined1 *)((longlong)plVar3 + 0x81e) = 2;
      plVar3[0x104] = 0;
      *(uint *)(plVar3 + 0x105) = param_2;
      _weak_memset_default___llvm_retpoline_r11(&local_850,0,0x807);
      handle_manager::GdiHandleEntryTable::GdiHandleEntryTable::_Create
                ((undefined8 *)local_48,param_4,'\0');
      if ((local_48[0] & 1) != 0) {
        core::ptr::drop_in_place<handle_manager::GdiHandleEntryDirectory::GdiHandleEntryDirectory>
                  ((longlong)&local_850);
        *(undefined4 *)((longlong)param_1 + 4) = local_44;
        *(undefined4 *)param_1 = 1;
        if (*(char *)((longlong)plVar3 + 0x81e) != '\x02') {
          core::ptr::drop_in_place<handle_manager::GdiHandleEntryDirectory::GdiHandleEntryDirectory>
                    ((longlong)(plVar3 + 3));
        }
        if (*plVar3 != 0) {
          _RNvNtCsiNQa5DCRmUC_9gdi_alloc3ffi13Win32FreePool();
        }
        _RNvNtCsiNQa5DCRmUC_9gdi_alloc3ffi13Win32FreePool();
        return param_1;
      }
      if (((*(byte *)(local_40 + 0x38) != 2) && ((*(byte *)(local_40 + 0x38) & 1) != 0)) &&
         (*(longlong *)(local_40 + 0x30) != 0)) {
        _RNvNtCsiNQa5DCRmUC_9gdi_alloc3ffi13Win32FreePool();
      }
      *(undefined8 *)(local_40 + 0x20) = param_3;
      *(ulonglong *)(local_40 + 0x28) = (ulonglong)param_4;
      *(ulonglong *)(local_40 + 0x30) = (ulonglong)param_4;
      *(undefined1 *)(local_40 + 0x38) = 0;
      local_850 = local_40;
      local_4c = 1;
      _weak_memcpy_default___llvm_retpoline_r11(local_1054,(void *)((longlong)&local_850 + 4),0x802)
      ;
      *(int *)(plVar3 + 3) = (int)local_40;
      _weak_memcpy_default___llvm_retpoline_r11((void *)((longlong)plVar3 + 0x1c),local_1054,0x802);
      *(undefined1 *)((longlong)plVar3 + 0x81e) = 0;
      param_1[1] = plVar3;
      *(undefined4 *)param_1 = 0;
      if ((local_38 ^ (ulonglong)auStack_1078) == __security_cookie) {
        return param_1;
      }
      goto LAB_14000fe2e;
    }
    uVar2 = 0xe00000001;
  }
  *param_1 = uVar2;
  if ((local_38 ^ (ulonglong)auStack_1078) == __security_cookie) {
    return param_1;
  }
LAB_14000fe2e:
  pcVar1 = (code *)swi(3);
  puVar4 = (undefined8 *)(*pcVar1)();
  return puVar4;
}



===== _RNvNtCsjsHfHFRyfyy_10gdi_region3ffi26ScanLookAsideList_Allocate @ 14000fe40 =====

void _RNvNtCsjsHfHFRyfyy_10gdi_region3ffi26ScanLookAsideList_Allocate(void)

{
  ScanLookAsideList_Allocate();
  return;
}



===== _RNvNtCsjsHfHFRyfyy_10gdi_region3ffi22ScanLookAsideList_Free @ 14000fe50 =====

void _RNvNtCsjsHfHFRyfyy_10gdi_region3ffi22ScanLookAsideList_Free(void)

{
  ScanLookAsideList_Free();
  return;
}



===== _RNvNtCsjsHfHFRyfyy_10gdi_region3ffi27RustOnZeroSizedScanCallback @ 14000fe60 =====

void _RNvNtCsjsHfHFRyfyy_10gdi_region3ffi27RustOnZeroSizedScanCallback(void)

{
  RustOnZeroSizedScanCallback();
  return;
}



===== _RNvNtCsjsHfHFRyfyy_10gdi_region3ffi60Feature_Servicing_Win32kRSFloodFillBoundingBox_ffi_IsEnabled @ 14000fe70 =====

void _RNvNtCsjsHfHFRyfyy_10gdi_region3ffi60Feature_Servicing_Win32kRSFloodFillBoundingBox_ffi_IsEnabled
               (void)

{
  Feature_Servicing_Win32kRSFloodFillBoundingBox_ffi_IsEnabled();
  return;
}



===== is_valid_scr_rc @ 14000fe80 =====

undefined4 rgncore::is_valid_scr_rc(uint *param_1)

{
  if (((((*param_1 & 0xf8000000) == 0) || ((*param_1 & 0xf8000000) == 0xf8000000)) &&
      (((param_1[3] & 0xf8000000) == 0 || ((param_1[3] & 0xf8000000) == 0xf8000000)))) &&
     (((param_1[2] & 0xf8000000) == 0 || ((param_1[2] & 0xf8000000) == 0xf8000000)))) {
    return CONCAT31((int3)(param_1[1] + 0x8000000 >> 8),param_1[1] + 0x8000000 < 0x10000000);
  }
  return 0;
}



===== _RNvNtNtCsdyToaWEq7tk_8gdi_rust6region9from_path20region_from_path_mut @ 14000fed0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Type propagation algorithm not settling */

ulonglong _RNvNtNtCsdyToaWEq7tk_8gdi_rust6region9from_path20region_from_path_mut
                    (ulonglong *param_1,longlong param_2,char param_3,longlong param_4,byte param_5,
                    uint param_6)

{
  int *piVar1;
  uint uVar2;
  longlong *plVar3;
  code *pcVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  ulonglong *puVar11;
  char *pcVar12;
  bool bVar13;
  undefined4 uVar14;
  longlong *plVar15;
  ulonglong uVar16;
  undefined8 uVar17;
  ulonglong uVar18;
  char *pcVar19;
  uint uVar20;
  ulonglong *puVar21;
  ulonglong **ppuVar22;
  longlong *plVar23;
  longlong lVar24;
  ulonglong uVar25;
  ulonglong **_Src;
  ulonglong **ppuVar26;
  longlong lVar27;
  int iVar28;
  undefined8 *puVar29;
  int iVar30;
  longlong lVar31;
  bool bVar32;
  undefined8 *puVar33;
  ulonglong *puVar34;
  ulonglong uVar35;
  ulonglong uVar36;
  undefined8 *puVar37;
  longlong *plVar38;
  longlong *plVar39;
  undefined1 auStackY_238 [32];
  longlong *local_200;
  ulonglong *local_1c8;
  ulonglong *local_1c0;
  uint local_1b8;
  uint uStack_1b4;
  ulonglong local_1b0;
  ulonglong *local_1a8;
  uint uStack_1a0;
  uint uStack_19c;
  undefined4 uStack_198;
  undefined4 uStack_194;
  undefined8 uStack_190;
  undefined8 local_188;
  undefined8 uStack_180;
  ulonglong *local_60;
  uint uStack_58;
  uint uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_238;
  if ((param_5 & 1) == 0) {
    plVar15 = *(longlong **)(param_2 + 8);
    if (plVar15 == (longlong *)0x0) {
      uVar36 = 0x57;
      goto LAB_140010c31;
    }
    param_6 = 0;
    do {
      while( true ) {
        uVar20 = *(uint *)(plVar15 + 2);
        iVar28 = param_6 + ((uVar20 >> 3 & 1) != 0);
        if ((uVar20 & 0x10) == 0) break;
        param_6 = iVar28 + *(uint *)((longlong)plVar15 + 0x14) / 3;
        plVar15 = (longlong *)*plVar15;
        if (plVar15 == (longlong *)0x0) goto LAB_14000ff5c;
      }
      param_6 = iVar28 + (*(uint *)((longlong)plVar15 + 0x14) - (uVar20 & 1));
      plVar15 = (longlong *)*plVar15;
    } while (plVar15 != (longlong *)0x0);
  }
LAB_14000ff5c:
  uVar36 = 0x57;
  if (param_6 < 2) goto LAB_140010c31;
  if ((param_4 == 0) ||
     ((*(int *)(param_4 + 4) < *(int *)(param_2 + 0x1c) &&
      (*(int *)(param_2 + 0x24) < *(int *)(param_4 + 0xc))))) {
    plVar15 = *(longlong **)(param_2 + 8);
    if (plVar15 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
      _RNvNtCsloaxXL3qbEI_4core6option13unwrap_failed();
    }
    puVar29 = (undefined8 *)*plVar15;
    uVar20 = *(uint *)((longlong)plVar15 + 0x14);
    ppuVar26 = (ulonglong **)(ulonglong)uVar20;
    ppuVar22 = (ulonglong **)(plVar15 + 3);
    _Src = ppuVar22;
    if (ppuVar26 == (ulonglong **)0x0) {
      _Src = (ulonglong **)&DAT_00000004;
    }
    if (puVar29 == (undefined8 *)0x0) {
      if (uVar20 < 2) {
        _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore16set_to_null_scan(param_1);
      }
      else {
        iVar28 = *(int *)(param_2 + 0x1c);
        iVar30 = *(int *)(param_2 + 0x24);
LAB_140010126:
        uVar16 = gdi_rust::region::from_path::fast_fill_region_from_edges
                           (param_1,(longlong)ppuVar22,(ulonglong)ppuVar26,iVar28,iVar30);
        if ((uVar16 & 1) != 0) {
          uVar36 = uVar16 >> 0x20;
          goto LAB_140010c31;
        }
        if ((uVar16 & 0x100) == 0) goto LAB_140010182;
      }
      _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore20tighten_bounding_box((longlong)param_1);
      uVar20 = *(uint *)((longlong)param_1 + 0x1c) & 0xf8000000;
      if ((((uVar20 == 0) || (uVar20 == 0xf8000000)) &&
          ((uVar20 = (uint)param_1[5] & 0xf8000000, uVar20 == 0 || (uVar20 == 0xf8000000)))) &&
         (((uVar20 = *(uint *)((longlong)param_1 + 0x24) & 0xf8000000, uVar20 == 0 ||
           (uVar20 == 0xf8000000)) && (uVar36 = 0x57, (int)param_1[4] + 0x8000000U < 0x10000000))))
      {
        uVar36 = 0;
      }
      goto LAB_140010c31;
    }
    uVar16 = (ulonglong)*(uint *)((longlong)puVar29 + 0x14);
    puVar37 = puVar29 + 3;
    if (uVar16 == 0) {
      puVar37 = (undefined8 *)&DAT_00000004;
    }
    if ((0x28 < param_6) || ((*(uint *)(plVar15 + 2) & 2) != 0)) goto LAB_140010182;
    puVar34 = (ulonglong *)*puVar29;
    uVar2 = *(uint *)(puVar29 + 2);
    _weak_memset_default___llvm_retpoline_r11(&local_1a8,0,0x140);
    if (uVar20 < 0x29) {
      _weak_memcpy_default___llvm_retpoline_r11(&local_1a8,_Src,(longlong)ppuVar26 * 8);
      if ((0x28U - (longlong)ppuVar26 < uVar16) || ((uVar2 & 1) != 0)) goto LAB_140010182;
      _Src = (ulonglong **)(uVar16 + (longlong)ppuVar26);
      if (_Src < (ulonglong **)0x29) {
        _weak_memcpy_default___llvm_retpoline_r11
                  (&local_1a8 + (longlong)ppuVar26,puVar37,uVar16 << 3);
        ppuVar26 = _Src;
        while (puVar34 != (ulonglong *)0x0) {
          uVar16 = (ulonglong)*(uint *)((longlong)puVar34 + 0x14);
          if ((0x28U - (int)ppuVar26 < *(uint *)((longlong)puVar34 + 0x14)) ||
             ((puVar34[2] & 1) != 0)) goto LAB_140010182;
          puVar21 = puVar34 + 3;
          if (uVar16 == 0) {
            puVar21 = (ulonglong *)&DAT_00000004;
          }
          puVar34 = (ulonglong *)*puVar34;
          ppuVar22 = &local_1a8 + (longlong)ppuVar26;
          ppuVar26 = (ulonglong **)((longlong)ppuVar26 + uVar16);
          _weak_memcpy_default___llvm_retpoline_r11(ppuVar22,puVar21,uVar16 << 3);
        }
        iVar28 = *(int *)(param_2 + 0x1c);
        iVar30 = *(int *)(param_2 + 0x24);
        ppuVar22 = &local_1a8;
        goto LAB_140010126;
      }
    }
    else {
      _RNvNtNtCsloaxXL3qbEI_4core5slice5index24slice_end_index_len_fail
                (ppuVar26,0x28,&PTR_s_gdi_rust_src_region_from_path_rs_140019c48);
    }
    uVar20 = _RNvNtNtCsloaxXL3qbEI_4core5slice5index24slice_end_index_len_fail
                       (_Src,0x28,&PTR_s_gdi_rust_src_region_from_path_rs_140019c60);
LAB_140010cc4:
    uVar36 = (ulonglong)uVar20;
joined_r0x000140010c0b:
    if (local_1c0 != (ulonglong *)0x0) {
      _RNvNtCsiNQa5DCRmUC_9gdi_alloc3ffi13Win32FreePool();
    }
joined_r0x000140010d19:
    if (puVar34 != (ulonglong *)0x0) {
      _RNvNtCsiNQa5DCRmUC_9gdi_alloc3ffi13Win32FreePool();
    }
  }
  else {
LAB_140010182:
    iVar28 = *(int *)(param_2 + 0x1c);
    iVar30 = *(int *)(param_2 + 0x24);
    if (iVar30 < iVar28) goto LAB_140010c31;
    if (param_4 != 0) {
      if (iVar28 < *(int *)(param_4 + 4)) {
        iVar28 = *(int *)(param_4 + 4);
      }
      if (*(int *)(param_4 + 0xc) < iVar30) {
        iVar30 = *(int *)(param_4 + 0xc);
      }
    }
    uVar36 = 0;
    if (0 < (longlong)iVar30 - (longlong)iVar28) {
      uVar36 = (longlong)iVar30 - (longlong)iVar28;
    }
    uVar16 = uVar36 >> 4 & 0xfffffff;
    uVar36 = 0x216;
    if ((int)uVar16 - 0xe38e2fU < 0xfe38e38f) goto LAB_140010c31;
    _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore23clear_scans_and_reserve
              ((undefined4 *)&local_1a8,param_1,uVar16 * 8 + 0x6c);
    if (((ulonglong)local_1a8 & 1) != 0) {
      uVar36 = (ulonglong)local_1a8 >> 0x20;
      goto LAB_140010c31;
    }
    local_1c8 = (ulonglong *)CONCAT44(uStack_19c,uStack_1a0);
    plVar15 = *(longlong **)(param_2 + 8);
    local_1a8 = (ulonglong *)0x0;
    uStack_1a0 = 8;
    uStack_19c = 0;
    uStack_198 = 0;
    uStack_194 = 0;
    uVar36 = _RNvMs2_NtCsip5f2bf5HGI_5alloc7raw_vecINtB5_11RawVecInnerINtCsiNQa5DCRmUC_9gdi_alloc15TaggedAllocatorKm67646547_EE11try_reserveCsdyToaWEq7tk_8gdi_rust
                       ((ulonglong *)&local_1a8,0,(ulonglong)param_6 + 1,&DAT_00000008,0x30);
    puVar34 = local_1a8;
    if (uVar36 == 0x8000000000000001) {
      uVar36 = 0xe;
      if (local_1a8 != (ulonglong *)0x8000000000000000) {
        uVar36 = CONCAT44(uStack_19c,uStack_1a0);
        local_60 = local_1a8;
        uStack_58 = uStack_1a0;
        uStack_54 = uStack_19c;
        uStack_50 = uStack_198;
        uStack_4c = uStack_194;
        cxxbridge1_PsGetCurrentThread(&local_1a8);
        puVar21 = local_1a8;
        if (plVar15 == (longlong *)0x0) {
          uVar16 = CONCAT44(uStack_4c,uStack_50);
        }
        else {
          local_200 = (longlong *)0x0;
          plVar23 = (longlong *)0x0;
          do {
            plVar3 = (longlong *)*plVar15;
            local_1a8 = puVar21;
            cxxbridge1_PsIsThreadTerminating(&local_1a8,(undefined1 *)&local_1c0);
            if ((char)local_1c0 != '\0') {
              uVar36 = 0x1f;
              puVar34 = local_60;
              goto joined_r0x000140010d19;
            }
            plVar39 = plVar15 + 3;
            uVar36 = (ulonglong)*(uint *)((longlong)plVar15 + 0x14);
            if ((*(byte *)(plVar15 + 2) & 1) == 0) {
              plVar38 = plVar39;
            }
            else {
              if (uVar36 == 0) {
                    /* WARNING: Subroutine does not return */
                _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
              }
              uVar36 = uVar36 - 1;
              plVar38 = plVar15 + 4;
              plVar23 = plVar39;
              local_200 = plVar39;
            }
            plVar39 = plVar38;
            while (plVar39 != plVar38 + uVar36) {
              if (plVar23 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
                _RNvNtCsloaxXL3qbEI_4core6option13unwrap_failed();
              }
              uVar17 = gdi_rust::region::from_path::GlobalEdgeTable::add_edge
                                 ((ulonglong *)&local_60,(int *)plVar23,(int *)plVar39,param_4);
              uVar20 = (uint)uVar17;
              plVar23 = plVar39;
              plVar39 = plVar39 + 1;
              if (uVar20 != 0) goto LAB_14001049c;
            }
            if ((*(byte *)(plVar15 + 2) & 2) != 0) {
              if (plVar23 == (longlong *)0x0) goto LAB_140010d43;
              if (local_200 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
                _RNvNtCsloaxXL3qbEI_4core6option13unwrap_failed();
              }
              uVar17 = gdi_rust::region::from_path::GlobalEdgeTable::add_edge
                                 ((ulonglong *)&local_60,(int *)plVar23,(int *)local_200,param_4);
              uVar20 = (uint)uVar17;
              if (uVar20 != 0) {
LAB_14001049c:
                uVar36 = (ulonglong)uVar20;
                puVar34 = local_60;
                goto joined_r0x000140010d19;
              }
              plVar23 = (longlong *)0x0;
            }
            plVar15 = plVar3;
          } while (plVar3 != (longlong *)0x0);
          uVar36 = (ulonglong)uStack_58;
          if (local_60 == (ulonglong *)0x8000000000000000) goto LAB_140010c27;
          uVar16 = CONCAT44(uStack_4c,uStack_50);
          puVar34 = local_60;
        }
        puVar29 = (undefined8 *)(uVar36 & 0xffffffff | (ulonglong)uStack_54 << 0x20);
        cxxbridge1_PsGetCurrentThread(&local_1a8);
        puVar21 = local_1a8;
        _RINvCsgf1RBdmyjwT_12fallible_vec20try_with_capacity_inNtNtNtCsdyToaWEq7tk_8gdi_rust6region9from_path4EdgeINtCsiNQa5DCRmUC_9gdi_alloc15TaggedAllocatorKm67646547_EEBW_
                  ((ulonglong *)&local_1a8,uVar16);
        if (local_1a8 != (ulonglong *)0x8000000000000000) {
          local_1b0 = CONCAT44(uStack_194,uStack_198);
          local_1c0 = local_1a8;
          local_1b8 = uStack_1a0;
          uStack_1b4 = uStack_19c;
          local_1a8 = puVar21;
          cxxbridge1_PsIsThreadTerminating(&local_1a8,(undefined1 *)&local_60);
          if ((char)local_60 == '\0') {
            iVar28 = -0x80000000;
            do {
              if (local_1b0 == 0) {
LAB_14001063c:
                if (uVar16 == 0) {
                  uVar36 = _RNvMs5_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE11append_scan
                                     (local_1c8,iVar28,0x7fffffff,(undefined4 *)&DAT_00000004,0);
                  if ((int)uVar36 != 0) {
                    uVar36 = uVar36 & 0xffffffff;
                    goto joined_r0x000140010c0b;
                  }
                  _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore20tighten_bounding_box
                            ((longlong)local_1c8);
                  uVar14 = rgncore::is_valid_scr_rc((uint *)((longlong)local_1c8 + 0x1c));
                  uVar36 = 0x57;
                  if ((char)uVar14 != '\0') {
                    uVar36 = 0;
                  }
                  if (local_1c0 != (ulonglong *)0x0) {
                    _RNvNtCsiNQa5DCRmUC_9gdi_alloc3ffi13Win32FreePool();
                  }
                  goto joined_r0x000140010d19;
                }
                iVar30 = *(int *)(puVar29 + 4);
                if (iVar30 != iVar28) {
                  uVar17 = _RNvMs5_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE11append_scan
                                     (local_1c8,iVar28,iVar30,(undefined4 *)&DAT_00000004,0);
                  uVar20 = (uint)uVar17;
                  iVar28 = iVar30;
                  if (uVar20 != 0) goto LAB_140010cc4;
                }
LAB_14001078e:
                if (*(int *)(puVar29 + 4) == iVar28) {
                  lVar27 = 0;
                  lVar24 = 0;
                  uVar36 = 0;
                  do {
                    if ((local_1b0 <= uVar36) ||
                       (*(int *)((longlong)puVar29 + 0x1c) <=
                        *(int *)(CONCAT44(uStack_1b4,local_1b8) + 0x1c + lVar24))) {
                      if (uVar16 == 0) goto LAB_140010d33;
                      local_1a8 = (ulonglong *)*puVar29;
                      uStack_190 = puVar29[3];
                      local_188 = puVar29[4];
                      uStack_180 = puVar29[5];
                      uStack_198 = (undefined4)puVar29[2];
                      uStack_194 = (undefined4)((ulonglong)puVar29[2] >> 0x20);
                      uStack_1a0 = (uint)puVar29[1];
                      uStack_19c = (uint)((ulonglong)puVar29[1] >> 0x20);
                      uVar16 = uVar16 - 1;
                      memmove(puVar29,puVar29 + 6,uVar16 * 0x30);
                      uVar18 = _RNvMs2_NtCsip5f2bf5HGI_5alloc7raw_vecINtB5_11RawVecInnerINtCsiNQa5DCRmUC_9gdi_alloc15TaggedAllocatorKm67646547_EE11try_reserveCsdyToaWEq7tk_8gdi_rust
                                         ((ulonglong *)&local_1c0,local_1b0,1,&DAT_00000008,0x30);
                      if (uVar18 != 0x8000000000000001) {
                        uVar36 = 0xe;
                        goto joined_r0x000140010c0b;
                      }
                      memmove((void *)(CONCAT44(uStack_1b4,local_1b8) + lVar24 + 0x30),
                              (void *)(CONCAT44(uStack_1b4,local_1b8) + lVar24),
                              (local_1b0 + lVar27) * 0x30);
                      lVar31 = CONCAT44(uStack_1b4,local_1b8);
                      *(undefined8 *)(lVar31 + lVar24) = local_1a8;
                      ((undefined8 *)(lVar31 + lVar24))[1] = CONCAT44(uStack_19c,uStack_1a0);
                      puVar37 = (undefined8 *)(lVar31 + 0x10 + lVar24);
                      *puVar37 = CONCAT44(uStack_194,uStack_198);
                      puVar37[1] = uStack_190;
                      puVar37 = (undefined8 *)(lVar31 + 0x20 + lVar24);
                      *puVar37 = local_188;
                      puVar37[1] = uStack_180;
                      local_1b0 = local_1b0 + 1;
                      if (uVar16 == 0) {
                        uVar16 = 0;
                        break;
                      }
                      if (*(int *)(puVar29 + 4) != iVar28) break;
                    }
                    uVar36 = uVar36 + 1;
                    lVar24 = lVar24 + 0x30;
                    lVar27 = lVar27 + -1;
                  } while( true );
                }
              }
              else {
                lVar27 = CONCAT44(uStack_1b4,local_1b8);
                lVar24 = 0;
                do {
                  iVar30 = *(int *)(lVar27 + 0x18 + lVar24) + -1;
                  *(int *)(lVar27 + 0x18 + lVar24) = iVar30;
                  if (0 < iVar30) {
                    iVar30 = *(int *)(lVar27 + 0x1c + lVar24) + *(int *)(lVar27 + 0x24 + lVar24);
                    *(int *)(lVar27 + 0x1c + lVar24) = iVar30;
                    lVar31 = *(longlong *)(lVar27 + lVar24) + *(longlong *)(lVar27 + 8 + lVar24);
                    *(longlong *)(lVar27 + lVar24) = lVar31;
                    if (-1 < lVar31) {
                      *(longlong *)(lVar27 + lVar24) =
                           lVar31 - *(longlong *)(lVar27 + 0x10 + lVar24);
                      *(int *)(lVar27 + 0x1c + lVar24) = iVar30 + *(char *)(lVar27 + 0x28 + lVar24);
                    }
                  }
                  lVar24 = lVar24 + 0x30;
                } while (local_1b0 * 0x30 != lVar24);
                _RINvMs_NtCsip5f2bf5HGI_5alloc3vecINtB5_3VecNtNtNtCsdyToaWEq7tk_8gdi_rust6region9from_path4EdgeINtCsiNQa5DCRmUC_9gdi_alloc15TaggedAllocatorKm67646547_EE10retain_mutNCINvB2_6retainNCNvMs_BH_NtBH_15ActiveEdgeTable7advance0E0EBL_
                          ((longlong)&local_1c0);
                if (local_1b0 != 1) {
                  if (local_1b0 == 0) goto LAB_14001063c;
                  lVar27 = CONCAT44(uStack_1b4,local_1b8);
                  uVar36 = 0;
                  uVar18 = 1;
                  bVar13 = false;
                  do {
                    while( true ) {
                      bVar32 = bVar13;
                      uVar35 = uVar18;
                      if (*(int *)(lVar27 + 0x1c + uVar36 * 0x30) <=
                          *(int *)(lVar27 + 0x1c + uVar35 * 0x30)) break;
                      puVar37 = (undefined8 *)(uVar35 * 0x30 + lVar27);
                      puVar33 = (undefined8 *)(uVar36 * 0x30 + lVar27);
                      local_1a8 = (ulonglong *)*puVar33;
                      uVar17 = puVar33[1];
                      uVar5 = puVar33[2];
                      uStack_190 = puVar33[3];
                      local_188 = puVar33[4];
                      uStack_180 = puVar33[5];
                      uStack_198 = (undefined4)uVar5;
                      uStack_194 = (undefined4)((ulonglong)uVar5 >> 0x20);
                      uStack_1a0 = (uint)uVar17;
                      uStack_19c = (uint)((ulonglong)uVar17 >> 0x20);
                      uVar6 = *puVar37;
                      uVar7 = puVar37[1];
                      uVar8 = puVar37[2];
                      uVar9 = puVar37[3];
                      uVar10 = puVar37[5];
                      puVar33[4] = puVar37[4];
                      puVar33[5] = uVar10;
                      puVar33[2] = uVar8;
                      puVar33[3] = uVar9;
                      *puVar33 = uVar6;
                      puVar33[1] = uVar7;
                      puVar37[4] = local_188;
                      puVar37[5] = uStack_180;
                      puVar37[2] = uVar5;
                      puVar37[3] = uStack_190;
                      *puVar37 = local_1a8;
                      puVar37[1] = uVar17;
                      uVar25 = uVar36 + 2;
                      bVar32 = true;
                      uVar36 = 0;
                      uVar18 = 1;
                      bVar13 = false;
                      if (uVar25 != local_1b0) {
LAB_140010696:
                        uVar36 = uVar35;
                        uVar18 = uVar35 + 1;
                        bVar13 = bVar32;
                        if (uVar35 + 1 == local_1b0) {
                    /* WARNING: Subroutine does not return */
                          _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
                        }
                      }
                    }
                    if (uVar36 + 2 != local_1b0) goto LAB_140010696;
                    uVar36 = 0;
                    uVar18 = 1;
                    bVar13 = false;
                  } while (bVar32);
                }
                if (uVar16 != 0) goto LAB_14001078e;
                uVar16 = 0;
              }
              uVar18 = local_1b0;
              lVar27 = CONCAT44(uStack_1b4,local_1b8);
              _RNvMs5_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE3new
                        (&local_1a8,local_1c8,iVar28,iVar28 + 1,local_1b0);
              puVar11 = local_1a8;
              uVar36 = (ulonglong)uStack_1a0;
              if (local_1a8 == (ulonglong *)0x0) {
LAB_140010b62:
                if ((int)uVar36 != 0) goto joined_r0x000140010c0b;
              }
              else {
                uStack_4c = uStack_194;
                uStack_54 = uStack_19c;
                uStack_50 = uStack_198;
                local_60 = local_1a8;
                uStack_58 = uStack_1a0;
                if (param_3 == '\0') {
                  if (uVar18 != 0) {
                    uVar36 = CONCAT44(uStack_194,uStack_198);
                    lVar24 = 0;
                    do {
                      while( true ) {
                        uVar35 = puVar11[2];
                        if (uVar35 < uVar36 + 3) goto LAB_140010d24;
                        iVar30 = *(int *)(lVar27 + 0x1c + lVar24);
                        if ((uVar36 + 3 != uVar35) &&
                           (iVar30 <= *(int *)((puVar11[1] - 4) + uVar35 * 4))) break;
                        if (uVar35 <= uVar36) {
                    /* WARNING: Subroutine does not return */
                          _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
                        }
                        piVar1 = (int *)(puVar11[1] + uVar36 * 4);
                        *piVar1 = *piVar1 + 1;
                        uVar35 = _RNvMs2_NtCsip5f2bf5HGI_5alloc7raw_vecINtB5_11RawVecInnerINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE11try_reserveCscIyU0BP6seX_7rgncore
                                           (puVar11,puVar11[2],1,&DAT_00000004,4);
                        if (uVar35 != 0x8000000000000001) {
                          uVar36 = 0xe;
                          goto LAB_140010bf3;
                        }
                        *(int *)(puVar11[1] + puVar11[2] * 4) = iVar30;
                        puVar11[2] = puVar11[2] + 1;
                        lVar24 = lVar24 + 0x30;
                        if (uVar18 * 0x30 == lVar24) goto LAB_140010b1e;
                      }
                      _RNvMs4_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE8pop_wallCsdyToaWEq7tk_8gdi_rust
                                ((longlong *)&local_60);
                      lVar24 = lVar24 + 0x30;
                    } while (uVar18 * 0x30 != lVar24);
                  }
                }
                else if (uVar18 != 0) {
                  uVar35 = CONCAT44(uStack_194,uStack_198) + 3;
                  uVar36 = 0;
LAB_14001099d:
                  do {
                    uVar25 = puVar11[2];
                    if (uVar25 < uVar35) goto LAB_140010d24;
                    iVar30 = *(int *)(lVar27 + 0x1c + uVar36 * 0x30);
                    if ((uVar25 == uVar35) || (*(int *)((puVar11[1] - 4) + uVar25 * 4) < iVar30)) {
                      uVar17 = _RNvMs4_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE11append_wallCsdyToaWEq7tk_8gdi_rust
                                         (&local_60,iVar30);
                      uVar20 = (uint)uVar17;
                      if (uVar20 == 0) goto LAB_1400109f6;
LAB_140010be8:
                      uVar36 = (ulonglong)uVar20;
LAB_140010bf3:
                      _RNvXs6_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EENtNtNtCsloaxXL3qbEI_4core3ops4drop4Drop4dropCsdyToaWEq7tk_8gdi_rust
                                ((longlong *)&local_60);
                      goto joined_r0x000140010c0b;
                    }
                    _RNvMs4_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE8pop_wallCsdyToaWEq7tk_8gdi_rust
                              ((longlong *)&local_60);
LAB_1400109f6:
                    lVar24 = uVar36 * 0x30;
                    iVar30 = (int)*(char *)(lVar27 + 0x29 + lVar24);
                    uVar36 = uVar36 + 1;
                    pcVar12 = (char *)(lVar24 + lVar27 + 0x59);
                    do {
                      pcVar19 = pcVar12;
                      if (uVar18 <= uVar36) {
                    /* WARNING: Subroutine does not return */
                        _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
                      }
                      uVar36 = uVar36 + 1;
                      iVar30 = iVar30 + *pcVar19;
                      pcVar12 = pcVar19 + 0x30;
                    } while (iVar30 != 0);
                    uVar25 = puVar11[2];
                    if (uVar25 < uVar35) goto LAB_140010d24;
                    if ((uVar35 != uVar25) &&
                       (*(int *)(pcVar19 + -0xd) <= *(int *)((puVar11[1] - 4) + uVar25 * 4)))
                    goto LAB_140010984;
                    uVar17 = _RNvMs4_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE11append_wallCsdyToaWEq7tk_8gdi_rust
                                       (&local_60,*(int *)(pcVar19 + -0xd));
                    uVar20 = (uint)uVar17;
                    if (uVar20 != 0) goto LAB_140010be8;
                  } while (uVar36 < uVar18);
                }
LAB_140010b1e:
                uStack_198 = uStack_50;
                uStack_194 = uStack_4c;
                local_1a8 = local_60;
                uStack_1a0 = uStack_58;
                uStack_19c = uStack_54;
                uVar36 = _RNvMs4_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE18commit_or_coalesceCsdyToaWEq7tk_8gdi_rust
                                   (&local_1a8);
                if ((uVar36 & 1) != 0) {
                  uVar36 = uVar36 >> 0x20;
                  goto LAB_140010b62;
                }
              }
              local_1a8 = puVar21;
              cxxbridge1_PsIsThreadTerminating(&local_1a8,(undefined1 *)&local_60);
              iVar28 = iVar28 + 1;
            } while ((char)local_60 == '\0');
          }
          uVar36 = 0x1f;
          goto joined_r0x000140010c0b;
        }
        uVar36 = 0xe;
        local_1a8 = (ulonglong *)0x8000000000000000;
        goto joined_r0x000140010d19;
      }
    }
    else {
      if (local_1a8 != (ulonglong *)0x0) {
        _RNvNtCsiNQa5DCRmUC_9gdi_alloc3ffi13Win32FreePool();
      }
      uVar36 = 0xe;
    }
  }
LAB_140010c27:
  _RNvXCscIyU0BP6seX_7rgncoreNtB2_11RegionGuardNtNtNtCsloaxXL3qbEI_4core3ops4drop4Drop4drop
            (&local_1c8);
LAB_140010c31:
  if ((local_48 ^ (ulonglong)auStackY_238) == __security_cookie) {
    return uVar36;
  }
  pcVar4 = (code *)swi(3);
  uVar36 = (*pcVar4)();
  return uVar36;
LAB_140010984:
  _RNvMs4_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE8pop_wallCsdyToaWEq7tk_8gdi_rust
            ((longlong *)&local_60);
  if (uVar18 <= uVar36) goto LAB_140010b1e;
  goto LAB_14001099d;
LAB_140010d24:
  _RNvNtNtCsloaxXL3qbEI_4core5slice5index26slice_start_index_len_fail();
LAB_140010d33:
  _RNvNvMs_NtCsip5f2bf5HGI_5alloc3vecINtB6_3VecppE6remove13assert_failed();
LAB_140010d43:
                    /* WARNING: Subroutine does not return */
  _RNvNtCsloaxXL3qbEI_4core6option13unwrap_failed();
}



===== add_edge @ 140010dc0 =====

undefined8
gdi_rust::region::from_path::GlobalEdgeTable::add_edge
          (ulonglong *param_1,int *param_2,int *param_3,longlong param_4)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  code *pcVar4;
  longlong lVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  ulonglong uVar9;
  undefined8 uVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  longlong lVar14;
  undefined1 uVar15;
  ulonglong uVar16;
  byte bVar17;
  ulonglong uVar18;
  uint uVar19;
  int iVar20;
  int iVar21;
  uint uVar22;
  int iVar23;
  uint uVar24;
  int iVar25;
  longlong lVar26;
  uint uVar27;
  ulonglong uVar28;
  
  uVar12 = param_3[1];
  uVar19 = param_2[1];
  uVar24 = uVar12 - uVar19;
  if ((int)uVar12 < (int)uVar19) {
    uVar24 = uVar19 - uVar12;
    uVar15 = 0xff;
    piVar8 = param_3;
    uVar22 = uVar12;
    uVar12 = uVar19;
  }
  else {
    uVar15 = 1;
    piVar8 = param_2;
    param_2 = param_3;
    uVar22 = uVar19;
  }
  iVar1 = *param_2;
  iVar2 = *piVar8;
  uVar19 = 0;
  if (param_4 == 0) {
    bVar3 = false;
  }
  else {
    uVar27 = *(uint *)(param_4 + 4);
    if ((int)uVar12 < (int)uVar27) {
      return 0;
    }
    uVar6 = *(uint *)(param_4 + 0xc);
    if ((int)uVar6 < (int)uVar22) {
      return 0;
    }
    bVar3 = (int)uVar22 < (int)uVar27;
    uVar19 = 0;
    if ((int)uVar22 < (int)uVar27) {
      uVar19 = uVar22;
    }
    if ((int)uVar27 < (int)uVar22) {
      uVar27 = uVar22;
    }
    uVar22 = uVar27;
    if ((int)uVar6 <= (int)uVar12) {
      uVar12 = uVar6;
    }
  }
  iVar21 = (int)((longlong)(int)uVar12 + 0xfU >> 4);
  iVar20 = (int)((longlong)(int)uVar22 + 0xfU >> 4);
  iVar11 = iVar21 - iVar20;
  if (iVar11 == 0 || iVar21 < iVar20) {
    return 0;
  }
  uVar28 = (ulonglong)uVar24;
  lVar26 = -1;
  if (iVar1 < iVar2) {
    lVar26 = -uVar28;
  }
  uVar12 = iVar2 - iVar1;
  if (iVar2 < iVar1) {
    uVar12 = iVar1 - iVar2;
  }
  uVar27 = 0;
  if (uVar24 <= uVar12) {
    if (uVar24 == 0) {
      _RNvNtNtCsloaxXL3qbEI_4core9panicking11panic_const23panic_const_div_by_zero();
      pcVar4 = (code *)swi(3);
      uVar10 = (*pcVar4)();
      return uVar10;
    }
    uVar6 = uVar12 / uVar24;
    uVar12 = uVar12 % uVar24;
    uVar27 = -uVar6;
    if (iVar2 <= iVar1) {
      uVar27 = uVar6;
    }
  }
  if (bVar3) {
    if (param_4 == 0) {
                    /* WARNING: Subroutine does not return */
      _RNvNtCsloaxXL3qbEI_4core6option13unwrap_failed();
    }
    uVar24 = *(uint *)(param_4 + 4);
    uVar22 = uVar19;
  }
  else {
    uVar24 = uVar22 + 0xf & 0xfffffff0;
  }
  bVar17 = -(iVar1 < iVar2) | 1;
  uVar16 = (ulonglong)uVar12;
  iVar21 = iVar2;
  if (uVar24 - uVar22 != 0) {
    iVar7 = (int)(char)bVar17;
    uVar19 = uVar22 + 1;
    if ((uVar24 - uVar22 & 1) != 0) {
      iVar21 = 0;
      uVar9 = 0;
      if (-1 < (longlong)(lVar26 + uVar16)) {
        iVar21 = iVar7;
        uVar9 = uVar28;
      }
      lVar26 = (lVar26 + uVar16) - uVar9;
      iVar21 = iVar21 + iVar2 + uVar27;
      uVar22 = uVar19;
    }
    if (uVar24 != uVar19) {
      iVar13 = uVar24 - uVar22;
      do {
        uVar9 = uVar28;
        iVar23 = iVar7;
        if ((longlong)(lVar26 + uVar16) < 0) {
          uVar9 = 0;
          iVar23 = 0;
        }
        lVar26 = ((lVar26 + uVar16) - uVar9) + uVar16;
        uVar9 = uVar28;
        iVar25 = iVar7;
        if (lVar26 < 0) {
          uVar9 = 0;
          iVar25 = 0;
        }
        lVar26 = lVar26 - uVar9;
        iVar21 = iVar21 + uVar27 * 2 + iVar23 + iVar25;
        iVar13 = iVar13 + -2;
      } while (iVar13 != 0);
    }
  }
  uVar9 = (longlong)iVar21 + 0xf;
  iVar7 = (int)(uVar9 >> 4);
  if (iVar1 < iVar2) {
    lVar14 = -(((uint)uVar9 & 0xf) * uVar28);
    uVar9 = param_1[2];
  }
  else {
    lVar14 = ((longlong)iVar21 - (uVar9 & 0xfffffffffffffff0)) * uVar28;
    uVar9 = param_1[2];
  }
  if (uVar9 == 0) {
    uVar18 = 0;
  }
  else {
    piVar8 = (int *)(param_1[1] + 0x20);
    uVar18 = 0;
    do {
      if ((iVar20 <= *piVar8) && ((*piVar8 != iVar20 || (iVar7 <= piVar8[-1])))) goto LAB_140010fac;
      uVar18 = uVar18 + 1;
      piVar8 = piVar8 + 0xc;
    } while (uVar9 != uVar18);
    uVar18 = uVar9;
  }
LAB_140010fac:
  uVar9 = _RNvMs2_NtCsip5f2bf5HGI_5alloc7raw_vecINtB5_11RawVecInnerINtCsiNQa5DCRmUC_9gdi_alloc15TaggedAllocatorKm67646547_EE11try_reserveCsdyToaWEq7tk_8gdi_rust
                    (param_1,uVar9,1,&DAT_00000008,0x30);
  uVar10 = 0xe;
  if (uVar9 == 0x8000000000000001) {
    lVar5 = uVar18 * 0x30;
    memmove((void *)(param_1[1] + lVar5 + 0x30),(void *)(param_1[1] + lVar5),
            (param_1[2] - uVar18) * 0x30);
    uVar9 = param_1[1];
    *(longlong *)(uVar9 + lVar5) = lVar26 + lVar14;
    *(ulonglong *)(uVar9 + 8 + lVar5) = uVar16 << 4;
    *(ulonglong *)(uVar9 + 0x10 + lVar5) = uVar28 << 4;
    *(int *)(uVar9 + 0x18 + lVar5) = iVar11;
    *(int *)(uVar9 + 0x1c + lVar5) = iVar7;
    *(int *)(uVar9 + 0x20 + lVar5) = iVar20;
    *(uint *)(uVar9 + 0x24 + lVar5) = uVar27;
    *(byte *)(uVar9 + 0x28 + lVar5) = bVar17;
    *(undefined1 *)(uVar9 + 0x29 + lVar5) = uVar15;
    param_1[2] = param_1[2] + 1;
    uVar10 = 0;
  }
  return uVar10;
}



===== fast_fill_region_from_edges @ 1400110f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong gdi_rust::region::from_path::fast_fill_region_from_edges
                    (ulonglong *param_1,longlong param_2,ulonglong param_3,int param_4,int param_5)

{
  bool bVar1;
  code *pcVar2;
  ulonglong *puVar3;
  ulonglong *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  longlong lVar8;
  ulonglong uVar9;
  longlong lVar10;
  ulonglong uVar11;
  int iVar12;
  int iVar13;
  ulonglong *puVar14;
  ulonglong uVar15;
  ulonglong *puVar16;
  uint uVar17;
  ulonglong uVar18;
  ulonglong *puVar19;
  int iVar20;
  ulonglong uVar21;
  uint uVar22;
  int iVar23;
  uint uVar24;
  ulonglong uVar25;
  ulonglong uVar26;
  undefined1 auStackY_108 [32];
  int local_e0;
  int local_dc;
  uint local_d8;
  int local_d4;
  uint local_d0;
  uint local_cc;
  ulonglong *local_c8;
  int local_bc;
  ulonglong local_b0;
  ulonglong *local_a8;
  ulonglong *local_98;
  ulonglong local_88;
  int local_80;
  int local_7c;
  ulonglong *local_68;
  ulonglong local_60;
  ulonglong *local_58;
  int local_50;
  int local_4c;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_108;
  if (param_3 < 2) {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
  }
  uVar11 = param_3 - 1;
  iVar5 = *(int *)(param_2 + 4);
  if (iVar5 < *(int *)(param_2 + 0xc)) {
    uVar15 = 2;
    do {
      if (param_3 == uVar15) {
        uVar15 = 0;
        goto LAB_140011267;
      }
      iVar23 = *(int *)(param_2 + 4 + uVar15 * 8);
      lVar8 = uVar15 * 8;
      uVar18 = uVar15 + 1;
      uVar15 = uVar15 + 1;
    } while (*(int *)(param_2 + -4 + lVar8) <= iVar23);
    do {
      uVar25 = uVar18;
      if (param_3 == uVar25) {
        uVar15 = 0;
        if (*(int *)(param_2 + -4 + param_3 * 8) < iVar5) {
          uVar15 = uVar11;
        }
        goto LAB_140011267;
      }
      if (param_3 <= uVar25) {
                    /* WARNING: Subroutine does not return */
        _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
      }
      if (param_3 <= uVar25 - 1) {
                    /* WARNING: Subroutine does not return */
        _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
      }
      iVar20 = *(int *)(param_2 + 4 + uVar25 * 8);
      bVar1 = iVar20 <= iVar23;
      uVar18 = uVar25 + 1;
      iVar23 = iVar20;
    } while (bVar1);
    uVar18 = uVar25 - 1;
    do {
      if (iVar5 < iVar20) break;
      uVar15 = uVar25 - 1;
      if (param_3 - 2 == uVar18) goto LAB_140011267;
      iVar23 = *(int *)(param_2 + 0x14 + uVar18 * 8);
      uVar18 = uVar18 + 1;
      bVar1 = iVar20 <= iVar23;
      iVar20 = iVar23;
    } while (bVar1);
  }
  else {
    uVar15 = 2;
    do {
      uVar18 = uVar15;
      if (param_3 == uVar18) {
        uVar15 = uVar11;
        goto LAB_140011267;
      }
      iVar23 = *(int *)(param_2 + 4 + uVar18 * 8);
      uVar15 = uVar18 + 1;
    } while (iVar23 <= *(int *)(param_2 + -4 + uVar18 * 8));
    uVar25 = uVar18 + 1;
    do {
      uVar26 = uVar25;
      uVar15 = uVar18 - 1;
      if (param_3 == uVar26) goto LAB_140011267;
      if (param_3 <= uVar26) {
                    /* WARNING: Subroutine does not return */
        _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
      }
      if (param_3 <= uVar26 - 1) {
                    /* WARNING: Subroutine does not return */
        _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
      }
      iVar20 = *(int *)(param_2 + 4 + uVar26 * 8);
      bVar1 = iVar23 <= iVar20;
      uVar25 = uVar26 + 1;
      iVar23 = iVar20;
    } while (bVar1);
    lVar8 = uVar26 - 1;
    do {
      if (iVar20 < iVar5) break;
      if (param_3 - 2 == lVar8) goto LAB_140011267;
      iVar23 = *(int *)(param_2 + 0x14 + lVar8 * 8);
      lVar8 = lVar8 + 1;
      bVar1 = iVar23 <= iVar20;
      iVar20 = iVar23;
    } while (bVar1);
  }
  local_b0 = 0;
  uVar25 = 0;
  uVar18 = 0;
LAB_140011f63:
  if ((local_48 ^ (ulonglong)auStackY_108) == __security_cookie) {
    return local_b0 | uVar25 | uVar18;
  }
  pcVar2 = (code *)swi(3);
  uVar11 = (*pcVar2)();
  return uVar11;
LAB_140011267:
  if (param_3 <= uVar15) {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
  }
  local_b0 = 0x21600000000;
  uVar18 = 1;
  uVar25 = 0x100;
  if (((longlong)param_5 - (longlong)param_4 < 0x7ffffff1) &&
     (iVar5 = (int)((longlong)param_5 - (longlong)param_4) + 0xf >> 4,
     0xf3333332 < iVar5 + 0xf9999999U)) {
    iVar23 = *(int *)(param_2 + 4 + uVar15 * 8);
    uVar22 = iVar5 * 0xe;
    uVar24 = 0x1c;
    if (0x1c < uVar22) {
      uVar24 = uVar22;
    }
    _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore23clear_scans_and_reserve
              ((undefined4 *)&local_60,param_1,(longlong)(int)uVar24);
    puVar3 = local_58;
    if ((local_60 & 1) == 0) {
      local_c8 = (ulonglong *)((longlong)iVar23 + 0xfU >> 4);
      local_68 = local_58;
      local_b0 = _RNvMs5_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE11append_scan
                           (local_58,0x80000000,(int)local_c8,(undefined4 *)&DAT_00000004,0);
      if ((int)local_b0 == 0) {
        local_98 = (ulonglong *)0x1;
        local_a8 = (ulonglong *)0xffffffffffffffff;
        iVar5 = 0;
        local_d8 = 0;
        local_7c = 0;
        local_dc = 0;
        local_b0 = 0;
        local_d4 = 0;
        local_cc = 0;
        local_bc = 0;
        local_e0 = 0;
        local_88 = 0;
        uVar25 = uVar15;
        uVar26 = param_3;
        do {
          puVar14 = local_98;
          uVar21 = local_b0;
LAB_140011411:
          local_b0 = uVar21;
          iVar23 = (int)local_c8;
          if (local_b0 >> 0x20 == 0) {
            do {
              uVar18 = uVar15;
              uVar26 = uVar26 - 1;
              if ((longlong)uVar26 < 0) goto LAB_140011edc;
              if ((longlong)local_a8 < 0) {
                uVar15 = uVar18 - 1;
                if (uVar18 == 0) {
                  uVar15 = uVar11;
                }
              }
              else {
                uVar15 = uVar18 + 1;
                if (param_3 <= uVar18 + 1) {
                  uVar15 = 0;
                }
              }
              if (param_3 <= uVar15) goto LAB_140012061;
              uVar22 = *(uint *)(param_2 + 4 + uVar15 * 8);
              puVar14 = (ulonglong *)(longlong)(int)uVar22;
              iVar5 = (int)((longlong)puVar14 + 0xfU >> 4) - iVar23;
            } while (iVar5 < 1);
            if (param_3 <= uVar18) goto LAB_140012087;
            uVar24 = *(uint *)(param_2 + uVar18 * 8);
            uVar17 = *(uint *)(param_2 + 4 + uVar18 * 8);
            iVar20 = uVar22 - uVar17;
            iVar12 = *(int *)(param_2 + uVar15 * 8) - uVar24;
            if (iVar12 < 0) {
              if (-iVar12 < iVar20) {
                local_dc = iVar12 + iVar20;
                local_d8 = 0xffffffff;
                goto LAB_14001151f;
              }
              if (uVar22 == uVar17) goto LAB_1400120ce;
              if ((iVar20 != -1) || (!SBORROW4(0,iVar12))) {
                local_dc = -iVar12 % iVar20;
                if (local_dc < 1) goto LAB_1400114bf;
                local_d8 = iVar12 / iVar20 - 1;
                local_dc = iVar20 - local_dc;
                goto LAB_14001151f;
              }
LAB_1400120c2:
              _RNvNtNtCsloaxXL3qbEI_4core9panicking11panic_const24panic_const_div_overflow();
LAB_1400120ce:
              _RNvNtNtCsloaxXL3qbEI_4core9panicking11panic_const23panic_const_div_by_zero();
              pcVar2 = (code *)swi(3);
              uVar11 = (*pcVar2)();
              return uVar11;
            }
            local_d8 = 0;
            local_dc = iVar12;
            if (iVar12 < iVar20) {
LAB_14001151f:
              uVar17 = uVar17 & 0xf;
              if (uVar17 == 0) {
                iVar12 = -1;
              }
              else {
                iVar12 = -1;
                if (uVar17 != 0xf) {
                  uVar22 = 0x10 - uVar17 & 0xfffffffe;
                  do {
                    iVar13 = iVar12 + local_dc;
                    iVar12 = iVar20;
                    if (-1 >= iVar13) {
                      iVar12 = 0;
                    }
                    iVar6 = (iVar13 - iVar12) + local_dc;
                    iVar12 = iVar20;
                    if (-1 >= iVar6) {
                      iVar12 = 0;
                    }
                    iVar12 = iVar6 - iVar12;
                    uVar24 = uVar24 + local_d8 * 2 + (uint)(-1 < iVar13) + (uint)(-1 < iVar6);
                    uVar22 = uVar22 - 2;
                  } while (uVar22 != 0);
                }
                if ((0x10 - uVar17 & 1) != 0) {
                  iVar13 = iVar12 + local_dc;
                  iVar12 = 0;
                  if (-1 < iVar13) {
                    iVar12 = iVar20;
                  }
                  iVar12 = iVar13 - iVar12;
                  uVar24 = uVar24 + local_d8 + (uint)(-1 < iVar13);
                }
              }
              local_b0 = CONCAT44(iVar5,iVar20);
              puVar14 = (ulonglong *)(ulonglong)(uVar24 & 0xf);
              iVar20 = (uVar24 | 0xfffffff0) * iVar20;
              uVar22 = uVar24 + 0xf;
              if ((uVar24 & 0xf) == 0) {
                iVar20 = 0;
                uVar22 = uVar24;
              }
              iVar5 = (int)uVar22 >> 4;
              local_7c = iVar20 + iVar12 >> 4;
              goto LAB_1400115d1;
            }
            if (uVar22 != uVar17) {
              local_dc = iVar12 % iVar20;
LAB_1400114bf:
              local_d8 = iVar12 / iVar20;
              goto LAB_14001151f;
            }
LAB_1400120a7:
            _RNvNtNtCsloaxXL3qbEI_4core9panicking11panic_const23panic_const_div_by_zero();
            goto LAB_1400120b3;
          }
LAB_1400115d1:
          iVar20 = (int)(local_88 >> 0x20);
          if (local_88 >> 0x20 == 0) {
            do {
              uVar18 = uVar25;
              uVar26 = uVar26 - 1;
              if ((longlong)uVar26 < 0) goto LAB_140011edc;
              if ((longlong)local_98 < 0) {
                uVar25 = uVar18 - 1;
                if (uVar18 == 0) {
                  uVar25 = uVar11;
                }
              }
              else {
                uVar25 = uVar18 + 1;
                if (param_3 <= uVar18 + 1) {
                  uVar25 = 0;
                }
              }
              if (param_3 <= uVar25) {
LAB_140012061:
                    /* WARNING: Subroutine does not return */
                _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
              }
              uVar22 = *(uint *)(param_2 + 4 + uVar25 * 8);
              puVar14 = (ulonglong *)(longlong)(int)uVar22;
              iVar20 = (int)((longlong)puVar14 + 0xfU >> 4) - iVar23;
            } while (iVar20 < 1);
            if (param_3 <= uVar18) {
LAB_140012087:
                    /* WARNING: Subroutine does not return */
              _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
            }
            uVar24 = *(uint *)(param_2 + uVar18 * 8);
            uVar17 = *(uint *)(param_2 + 4 + uVar18 * 8);
            iVar12 = uVar22 - uVar17;
            local_e0 = *(int *)(param_2 + uVar25 * 8) - uVar24;
            if (local_e0 < 0) {
              if (-local_e0 < iVar12) {
                local_e0 = local_e0 + iVar12;
                puVar14 = (ulonglong *)0xffffffff;
              }
              else {
                if (uVar22 == uVar17) goto LAB_1400120ce;
                if ((iVar12 == -1) && (SBORROW4(0,local_e0))) goto LAB_1400120c2;
                uVar18 = (longlong)local_e0 / (longlong)iVar12;
                local_e0 = -local_e0 % iVar12;
                if (local_e0 < 1) goto LAB_14001168e;
                puVar14 = (ulonglong *)(ulonglong)((int)uVar18 - 1);
                local_e0 = iVar12 - local_e0;
              }
            }
            else {
              puVar14 = (ulonglong *)0x0;
              if (iVar12 <= local_e0) {
                if (uVar22 == uVar17) goto LAB_1400120a7;
                uVar18 = (longlong)local_e0 / (longlong)iVar12;
                local_e0 = local_e0 % iVar12;
LAB_14001168e:
                puVar14 = (ulonglong *)(uVar18 & 0xffffffff);
              }
            }
            uVar17 = uVar17 & 0xf;
            if (uVar17 == 0) {
              iVar13 = -1;
            }
            else {
              iVar13 = -1;
              if (uVar17 != 0xf) {
                uVar22 = 0x10 - uVar17 & 0xfffffffe;
                do {
                  iVar6 = iVar13 + local_e0;
                  iVar13 = iVar12;
                  if (-1 >= iVar6) {
                    iVar13 = 0;
                  }
                  iVar7 = (iVar6 - iVar13) + local_e0;
                  iVar13 = iVar12;
                  if (-1 >= iVar7) {
                    iVar13 = 0;
                  }
                  iVar13 = iVar7 - iVar13;
                  uVar24 = uVar24 + (int)puVar14 * 2 + (uint)(-1 < iVar6) + (uint)(-1 < iVar7);
                  uVar22 = uVar22 - 2;
                } while (uVar22 != 0);
              }
              if ((0x10 - uVar17 & 1) != 0) {
                iVar6 = iVar13 + local_e0;
                iVar13 = 0;
                if (-1 < iVar6) {
                  iVar13 = iVar12;
                }
                iVar13 = iVar6 - iVar13;
                uVar24 = uVar24 + (int)puVar14 + (uint)(-1 < iVar6);
              }
            }
            local_88 = CONCAT44(iVar20,iVar12);
            iVar12 = (uVar24 | 0xfffffff0) * iVar12;
            uVar22 = uVar24 + 0xf;
            if ((uVar24 & 0xf) == 0) {
              iVar12 = 0;
              uVar22 = uVar24;
            }
            local_d4 = (int)uVar22 >> 4;
            local_bc = iVar12 + iVar13 >> 4;
          }
          else {
            puVar14 = (ulonglong *)(ulonglong)local_cc;
          }
          iVar12 = (int)(local_b0 >> 0x20);
          local_80 = iVar12;
          if (iVar20 < iVar12) {
            local_80 = iVar20;
          }
          uVar21 = local_b0 & 0xffffffff | (ulonglong)(uint)(iVar12 - local_80) << 0x20;
          local_88 = local_88 & 0xffffffff | (ulonglong)(uint)(iVar20 - local_80) << 0x20;
          local_cc = (uint)puVar14;
          if ((local_cc == 0 && local_d8 == 0) && (local_e0 == 0 && local_dc == 0)) {
            if (iVar5 == local_d4) {
              lVar8 = _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore13last_scan_mut
                                ((longlong)puVar3);
              if (*(ulonglong **)(lVar8 + 0x10) <= puVar14) goto LAB_140012075;
              local_d4 = iVar5;
              if (*(int *)(*(longlong *)(lVar8 + 8) + (longlong)puVar14 * 4) == 0) {
                lVar8 = _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore13last_scan_mut
                                  ((longlong)puVar3);
                if (*(ulonglong *)(lVar8 + 0x10) <= (longlong)puVar14 + 2U) goto LAB_140012098;
                *(int *)(*(longlong *)(lVar8 + 8) + 8 + (longlong)puVar14 * 4) = iVar23 + local_80;
                local_c8 = (ulonglong *)(ulonglong)(uint)(iVar23 + local_80);
              }
              else {
                uVar9 = _RNvMs5_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE11append_scan
                                  (puVar3,iVar23,local_80 + iVar23,(undefined4 *)&DAT_00000004,0);
                local_b0 = uVar9 & 0xffffffff;
                uVar18 = 1;
                puVar14 = local_c8;
                local_c8 = (ulonglong *)(ulonglong)(uint)(local_80 + iVar23);
                if ((int)uVar9 != 0) goto LAB_140011f52;
              }
            }
            else {
              if (iVar5 < local_d4) {
                iVar12 = local_d4;
                iVar20 = iVar5;
              }
              else {
                iVar12 = iVar5;
                iVar20 = local_d4;
              }
              local_60 = _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore13last_scan_mut
                                   ((longlong)puVar3);
              local_58 = puVar14;
              if (*(ulonglong **)(local_60 + 0x10) <= puVar14) goto LAB_140012075;
              if ((*(int *)(*(longlong *)(local_60 + 8) + (longlong)puVar14 * 4) == 2) &&
                 (iVar13 = _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalRINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E6x_wallCsdyToaWEq7tk_8gdi_rust
                                     ((longlong *)&local_60,0), iVar13 == iVar20)) {
                puVar14 = (ulonglong *)0x1;
                iVar13 = _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalRINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E6x_wallCsdyToaWEq7tk_8gdi_rust
                                   ((longlong *)&local_60,1);
                if (iVar13 != iVar12) goto LAB_140011993;
                lVar8 = _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore13last_scan_mut
                                  ((longlong)puVar3);
                if (*(ulonglong *)(lVar8 + 0x10) <= (longlong)puVar14 + 2U) goto LAB_140012098;
                *(int *)(*(longlong *)(lVar8 + 8) + 8 + (longlong)puVar14 * 4) = local_80 + iVar23;
                local_c8 = puVar14;
              }
              else {
LAB_140011993:
                local_50 = iVar20;
                local_4c = iVar12;
                uVar18 = _RNvMs5_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE11append_scan
                                   (puVar3,iVar23,local_80 + iVar23,&local_50,2);
                local_b0 = uVar18 & 0xffffffff;
                if ((int)uVar18 != 0) {
                  uVar18 = 1;
                  goto LAB_140011f52;
                }
              }
              puVar14 = local_c8;
              local_c8 = (ulonglong *)(ulonglong)(uint)(local_80 + iVar23);
            }
            goto LAB_140011411;
          }
          puVar19 = local_a8;
          local_a8 = (ulonglong *)uVar25;
          do {
            iVar23 = (int)local_c8;
            if (local_d4 - iVar5 < 1) {
              puVar14 = puVar19;
              puVar4 = (ulonglong *)uVar15;
              uVar18 = uVar21;
              uVar22 = local_cc;
              do {
                iVar20 = iVar5;
                iVar13 = local_7c;
                iVar6 = local_dc;
                local_cc = uVar22;
                uVar21 = uVar18;
                uVar15 = (ulonglong)puVar4;
                puVar19 = puVar14;
                iVar12 = iVar20 - local_d4;
                if (iVar20 == local_d4) {
                  puVar14 = puVar19;
                  lVar8 = _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore13last_scan_mut
                                    ((longlong)puVar3);
                  if (*(ulonglong **)(lVar8 + 0x10) <= puVar14) goto LAB_140012075;
                  uVar22 = iVar23 + 1;
                  local_dc = iVar6;
                  if (*(int *)(*(longlong *)(lVar8 + 8) + (longlong)puVar14 * 4) != 0) {
                    local_b0 = _RNvMs5_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE11append_scan
                                         (puVar3,iVar23,uVar22,(undefined4 *)&DAT_00000004,0);
                    local_c8 = (ulonglong *)(ulonglong)uVar22;
                    if ((int)local_b0 == 0) goto LAB_140011b41;
                    goto LAB_140011fa3;
                  }
                  lVar8 = _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore13last_scan_mut
                                    ((longlong)puVar3);
                  if (*(ulonglong *)(lVar8 + 0x10) <= (longlong)puVar14 + 2U) goto LAB_140012098;
                  *(uint *)(*(longlong *)(lVar8 + 8) + 8 + (longlong)puVar14 * 4) = uVar22;
                  local_c8 = (ulonglong *)(ulonglong)uVar22;
                  goto LAB_140011b41;
                }
                puVar14 = local_98;
                puVar4 = local_a8;
                puVar16 = local_98;
                uVar18 = local_88;
                local_7c = local_bc;
                iVar5 = local_d4;
                local_dc = local_e0;
                uVar22 = local_d8;
                local_d8 = local_cc;
                local_e0 = iVar6;
                local_d4 = iVar20;
                local_d0 = local_cc;
                local_bc = iVar13;
                local_a8 = (ulonglong *)uVar15;
                local_98 = puVar19;
                local_88 = uVar21;
              } while (iVar12 < 1);
            }
            else {
              local_d0 = local_d8;
              puVar16 = puVar19;
              uVar18 = uVar21;
              puVar4 = (ulonglong *)uVar15;
              uVar22 = local_cc;
            }
            local_cc = uVar22;
            iVar20 = iVar5;
            iVar13 = local_7c;
            uVar15 = (ulonglong)puVar4;
            local_60 = _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore13last_scan_mut
                                 ((longlong)puVar3);
            local_58 = puVar14;
            if (*(ulonglong **)(local_60 + 0x10) <= puVar14) {
LAB_140012075:
                    /* WARNING: Subroutine does not return */
              _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
            }
            uVar22 = iVar23 + 1;
            if (*(int *)(*(longlong *)(local_60 + 8) + (longlong)puVar14 * 4) == 2) {
              if (*(ulonglong **)(local_60 + 0x10) <= (ulonglong *)((longlong)puVar14 + 3U)) {
LAB_1400120b3:
                    /* WARNING: Subroutine does not return */
                _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
              }
              if (*(int *)(*(longlong *)(local_60 + 8) + 0xc + (longlong)puVar14 * 4) != iVar20)
              goto LAB_140011aba;
              lVar8 = 1;
              iVar5 = _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalRINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E6x_wallCsdyToaWEq7tk_8gdi_rust
                                ((longlong *)&local_60,1);
              if (iVar5 != local_d4) goto LAB_140011aba;
              lVar10 = _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore13last_scan_mut
                                 ((longlong)puVar3);
              if (*(ulonglong *)(lVar10 + 0x10) <= lVar8 + 2U) {
LAB_140012098:
                    /* WARNING: Subroutine does not return */
                _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
              }
              *(uint *)(*(longlong *)(lVar10 + 8) + 8 + lVar8 * 4) = uVar22;
            }
            else {
LAB_140011aba:
              local_4c = local_d4;
              local_50 = iVar20;
              local_b0 = _RNvMs5_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE11append_scan
                                   (puVar3,iVar23,uVar22,&local_50,2);
              if ((int)local_b0 != 0) {
LAB_140011fa3:
                local_b0 = local_b0 & 0xffffffff;
                uVar18 = 1;
                goto LAB_140011f52;
              }
            }
            local_c8 = (ulonglong *)(ulonglong)uVar22;
            local_d8 = local_d0;
            puVar19 = puVar16;
            uVar21 = uVar18;
LAB_140011b41:
            local_bc = local_bc + local_e0;
            iVar5 = 0;
            if (-1 < local_bc) {
              iVar5 = (int)local_88;
            }
            local_d4 = (uint)(-1 < local_bc) + local_d4 + local_cc;
            local_bc = local_bc - iVar5;
            iVar13 = iVar13 + local_dc;
            puVar14 = (ulonglong *)(uVar21 & 0xffffffff);
            if (-1 >= iVar13) {
              puVar14 = (ulonglong *)0x0;
            }
            iVar5 = (uint)(-1 < iVar13) + iVar20 + local_d8;
            local_7c = iVar13 - (int)puVar14;
            local_80 = local_80 + -1;
          } while (local_80 != 0);
          uVar25 = (ulonglong)local_a8;
          local_b0 = uVar21;
          local_a8 = puVar19;
        } while( true );
      }
      local_b0 = local_b0 & 0xffffffff;
      uVar18 = 1;
LAB_140011f52:
      _RNvXCscIyU0BP6seX_7rgncoreNtB2_11RegionGuardNtNtNtCsloaxXL3qbEI_4core3ops4drop4Drop4drop
                (&local_68);
    }
    else {
      local_b0 = local_60 >> 0x20;
      uVar18 = 1;
    }
    uVar25 = 0x100;
    local_b0 = local_b0 << 0x20;
  }
  goto LAB_140011f63;
LAB_140011edc:
  lVar8 = _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore13last_scan_mut((longlong)puVar3);
  if (*(ulonglong **)(lVar8 + 0x10) <= puVar14) goto LAB_140012075;
  if (*(int *)(*(longlong *)(lVar8 + 8) + (longlong)puVar14 * 4) != 0) {
    uVar11 = _RNvMs5_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE11append_scan
                       (puVar3,iVar23,0x7fffffff,(undefined4 *)&DAT_00000004,0);
    local_b0 = uVar11 & 0xffffffff;
    uVar18 = (ulonglong)((int)uVar11 != 0);
    goto LAB_140011f52;
  }
  lVar8 = _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore13last_scan_mut((longlong)puVar3);
  if (*(ulonglong *)(lVar8 + 0x10) <= (longlong)puVar14 + 2U) goto LAB_140012098;
  *(undefined4 *)(*(longlong *)(lVar8 + 8) + 8 + (longlong)puVar14 * 4) = 0x7fffffff;
  uVar18 = 0;
  goto LAB_140011f52;
}



===== _RNvXs5_NtNtCsloaxXL3qbEI_4core3num5errorNtB5_15TryFromIntErrorNtNtB9_3fmt5Debug3fmt.llvm.3083486868190693220 @ 1400120f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void _RNvXs5_NtNtCsloaxXL3qbEI_4core3num5errorNtB5_15TryFromIntErrorNtNtB9_3fmt5Debug3fmt_llvm_3083486868190693220
               (undefined8 param_1,undefined8 *param_2)

{
  code *pcVar1;
  undefined1 auStack_38 [32];
  undefined *local_18;
  undefined8 local_10;
  ulonglong local_8;
  
  local_8 = __security_cookie ^ (ulonglong)auStack_38;
  local_18 = &DAT_140019e40;
  local_10 = param_1;
  _RNvMs9_NtCsloaxXL3qbEI_4core3fmtNtB5_9Formatter25debug_tuple_field1_finish
            (param_2,"TryFromIntErrorrgncore\\src\\scan.rs",0xf);
  if ((local_8 ^ (ulonglong)auStack_38) == __security_cookie) {
    return;
  }
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalQINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E13is_valid_scanB4_.llvm.3083486868190693220 @ 140012160 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
_RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalQINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E13is_valid_scanB4__llvm_3083486868190693220
          (longlong param_1,ulonglong param_2)

{
  int iVar1;
  int iVar2;
  ulonglong uVar3;
  code *pcVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  longlong lVar7;
  undefined1 auStack_78 [32];
  undefined **local_58;
  longlong local_48;
  longlong local_40 [7];
  ulonglong local_8;
  
  local_8 = __security_cookie ^ (ulonglong)auStack_78;
  uVar3 = *(ulonglong *)(param_1 + 0x10);
  if (param_2 + 4 <= uVar3) {
    if (uVar3 <= param_2) {
LAB_14001223a:
                    /* WARNING: Subroutine does not return */
      _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
    }
    iVar1 = *(int *)(*(longlong *)(param_1 + 8) + param_2 * 4);
    lVar7 = (longlong)iVar1;
    if (-1 < lVar7) {
      local_48 = lVar7;
      if (param_2 + 4 + lVar7 <= uVar3) {
        uVar6 = param_2 + lVar7 + 3;
        if (uVar3 <= uVar6) {
                    /* WARNING: Subroutine does not return */
          _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
        }
        iVar2 = *(int *)(*(longlong *)(param_1 + 8) + uVar6 * 4);
        lVar7 = (longlong)iVar2;
        if (-1 < lVar7) {
          uVar5 = CONCAT71((int7)(param_2 >> 8),1);
          local_40[0] = lVar7;
          if (iVar1 == iVar2) goto LAB_1400121a8;
          local_40[1] = 0;
          local_58 = &anon_67cd83108cc9ed848dbde57549fb323c_8_llvm_3083486868190693220;
          _RINvNtCsloaxXL3qbEI_4core9panicking13assert_failedjjEB4_
                    (0,local_40,&local_48,local_40 + 1);
        }
        local_58 = &anon_67cd83108cc9ed848dbde57549fb323c_7_llvm_3083486868190693220;
        _RNvNtCsloaxXL3qbEI_4core6result13unwrap_failed();
        goto LAB_14001223a;
      }
    }
  }
  uVar5 = 0;
LAB_1400121a8:
  if ((local_8 ^ (ulonglong)auStack_78) == __security_cookie) {
    return uVar5;
  }
  pcVar4 = (code *)swi(3);
  uVar5 = (*pcVar4)();
  return uVar5;
}



===== _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalRINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E8first_ofB4_ @ 140012260 =====

longlong _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalRINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E8first_ofB4_
                   (longlong param_1)

{
  undefined8 uVar1;
  
  uVar1 = _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalQINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E13is_valid_scanB4__llvm_3083486868190693220
                    (param_1,0);
  if ((char)uVar1 == '\0') {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core9panicking5panic();
  }
  return param_1;
}



===== _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalQINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E7last_ofB4_ @ 1400122a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

longlong _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalQINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E7last_ofB4_
                   (longlong param_1)

{
  ulonglong uVar1;
  code *pcVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined1 auStack_48 [32];
  undefined **local_28;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  uVar1 = *(ulonglong *)(param_1 + 0x10);
  if (uVar1 != 0) {
    lVar3 = (longlong)*(int *)(*(longlong *)(param_1 + 8) + -4 + uVar1 * 4);
    if (lVar3 < 0) {
      local_28 = &anon_67cd83108cc9ed848dbde57549fb323c_12_llvm_3083486868190693220;
      _RNvNtCsloaxXL3qbEI_4core6result13unwrap_failed();
    }
    else if (lVar3 + 4U <= uVar1) {
      uVar4 = _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalQINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E13is_valid_scanB4__llvm_3083486868190693220
                        (param_1,(uVar1 - lVar3) - 4);
      if ((char)uVar4 != '\0') {
        if ((local_18 ^ (ulonglong)auStack_48) == __security_cookie) {
          return param_1;
        }
        pcVar2 = (code *)swi(3);
        lVar3 = (*pcVar2)();
        return lVar3;
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  _RNvNtCsloaxXL3qbEI_4core6option13unwrap_failed();
}



===== _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalQINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E6x_wallB4_ @ 140012350 =====

undefined4
_RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalQINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E6x_wallB4_
          (longlong *param_1,ulonglong param_2)

{
  ulonglong uVar1;
  longlong lVar2;
  ulonglong uVar3;
  
  uVar3 = param_1[1];
  uVar1 = *(ulonglong *)(*param_1 + 0x10);
  if (uVar1 <= uVar3) {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
  }
  lVar2 = *(longlong *)(*param_1 + 8);
  if ((ulonglong)(longlong)*(int *)(lVar2 + uVar3 * 4) <= param_2) {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core9panicking5panic();
  }
  uVar3 = uVar3 + param_2 + 3;
  if (uVar1 <= uVar3) {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
  }
  return *(undefined4 *)(lVar2 + uVar3 * 4);
}



===== _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalQINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E7x_wallsB4_ @ 1400123c0 =====

longlong _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalQINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E7x_wallsB4_
                   (longlong *param_1)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  
  uVar3 = param_1[1];
  uVar4 = *(ulonglong *)(*param_1 + 0x10);
  if (uVar3 < uVar4) {
    lVar1 = *(longlong *)(*param_1 + 8);
    uVar5 = (ulonglong)*(int *)(lVar1 + uVar3 * 4);
    uVar3 = uVar3 + 3;
    uVar2 = uVar3 + uVar5;
    if (CARRY8(uVar3,uVar5)) {
      uVar4 = uVar2;
      uVar2 = _RNvNtNtCsloaxXL3qbEI_4core5slice5index22slice_index_order_fail();
    }
    else if (uVar2 <= uVar4) {
      return lVar1 + uVar3 * 4;
    }
    _RNvNtNtCsloaxXL3qbEI_4core5slice5index24slice_end_index_len_fail
              (uVar2,uVar4,&anon_67cd83108cc9ed848dbde57549fb323c_20_llvm_3083486868190693220);
  }
                    /* WARNING: Subroutine does not return */
  _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
}



===== _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalRINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E4nextB4_ @ 140012430 =====

longlong _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalRINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E4nextB4_
                   (longlong param_1,ulonglong param_2)

{
  undefined8 uVar1;
  longlong lVar2;
  
  if (*(ulonglong *)(param_1 + 0x10) <= param_2) {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
  }
  uVar1 = _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalQINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E13is_valid_scanB4__llvm_3083486868190693220
                    (param_1,param_2 + (longlong)*(int *)(*(longlong *)(param_1 + 8) + param_2 * 4)
                             + 4);
  lVar2 = 0;
  if ((char)uVar1 != '\0') {
    lVar2 = param_1;
  }
  return lVar2;
}



===== _RNvMs1_NtCscIyU0BP6seX_7rgncore4scanINtB5_12ScanInternalQINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1r_E16merge_in_x_wallsB7_ @ 140012490 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
_RNvMs1_NtCscIyU0BP6seX_7rgncore4scanINtB5_12ScanInternalQINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1r_E16merge_in_x_wallsB7_
          (undefined8 *param_1,int *param_2,ulonglong param_3,undefined **param_4,ulonglong param_5)

{
  undefined **ppuVar1;
  ulonglong uVar2;
  int iVar3;
  int iVar4;
  ulonglong *puVar5;
  ulonglong uVar6;
  code *pcVar7;
  int *piVar8;
  int *piVar9;
  ulonglong uVar10;
  undefined8 uVar11;
  ulonglong uVar12;
  int *_Src;
  undefined4 *puVar13;
  ulonglong uVar14;
  ulonglong uVar15;
  undefined **ppuVar16;
  bool bVar17;
  undefined1 auStackY_b8 [32];
  
  uVar10 = __security_cookie ^ (ulonglong)auStackY_b8;
  puVar5 = (ulonglong *)*param_1;
  uVar6 = param_1[1];
  uVar14 = puVar5[2];
  if (uVar14 <= uVar6) {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
  }
  iVar3 = *(int *)(puVar5[1] + uVar6 * 4);
  uVar15 = (ulonglong)iVar3;
  uVar2 = param_3 + uVar15;
  uVar11 = 8;
  if (param_5 < uVar2) {
LAB_140012642:
    if ((uVar10 ^ (ulonglong)auStackY_b8) == __security_cookie) {
      return uVar11;
    }
    pcVar7 = (code *)swi(3);
    uVar11 = (*pcVar7)();
    return uVar11;
  }
  ppuVar1 = (undefined **)(uVar6 + 3);
  uVar12 = (longlong)ppuVar1 + uVar15;
  if (CARRY8((ulonglong)ppuVar1,uVar15)) {
    uVar12 = _RNvNtNtCsloaxXL3qbEI_4core5slice5index22slice_index_order_fail();
  }
  else if (uVar12 <= uVar14) {
    _Src = (int *)(puVar5[1] + (longlong)ppuVar1 * 4);
    uVar14 = uVar2;
    ppuVar16 = param_4;
    if ((param_3 != 0) && (iVar3 != 0)) {
      do {
        iVar3 = *_Src;
        iVar4 = *param_2;
        uVar12 = uVar15;
        if (iVar4 <= iVar3) {
          uVar12 = param_3;
        }
        if (uVar12 < 2) {
                    /* WARNING: Subroutine does not return */
          _RNvNtCsloaxXL3qbEI_4core9panicking9panic_fmt();
        }
        bVar17 = uVar14 < 2;
        uVar14 = uVar14 - 2;
        if (bVar17) {
                    /* WARNING: Subroutine does not return */
          _RNvNtCsloaxXL3qbEI_4core9panicking9panic_fmt();
        }
        if (iVar3 < iVar4) {
          piVar8 = _Src;
        }
        else {
          param_3 = uVar12 - 2;
          piVar8 = param_2;
        }
        piVar9 = piVar8 + 2;
        uVar12 = uVar12 - 2;
        if (iVar4 <= iVar3) {
          param_2 = piVar8 + 2;
          piVar9 = _Src;
          uVar12 = uVar15;
        }
        uVar15 = uVar12;
        _Src = piVar9;
        *ppuVar16 = *(undefined **)piVar8;
        ppuVar16 = ppuVar16 + 1;
      } while ((uVar15 != 0) && (param_3 != 0));
    }
    if (uVar15 <= uVar14) {
      _weak_memcpy_default___llvm_retpoline_r11(ppuVar16,_Src,uVar15 * 4);
      if (uVar14 - uVar15 < param_3) {
                    /* WARNING: Subroutine does not return */
        _RNvNtCsloaxXL3qbEI_4core9panicking9panic_fmt();
      }
      _weak_memcpy_default___llvm_retpoline_r11
                ((void *)((longlong)ppuVar16 + uVar15 * 4),param_2,param_3 << 2);
      if (puVar5[2] <= uVar6) {
                    /* WARNING: Subroutine does not return */
        _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
      }
      puVar13 = _RINvXCsgf1RBdmyjwT_12fallible_vecINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEINtB3_11FallibleVeclB13_E13try_splice_inINtNtNtNtCsloaxXL3qbEI_4core4iter8adapters3map3MapINtNtNtB2O_5slice4iter7IterMutlENCNvMs1_NtCscIyU0BP6seX_7rgncore4scanINtB47_12ScanInternalQBv_B13_E16merge_in_x_walls0EINtNtNtB2O_3ops5range5RangejEEB49_
                          (puVar5,ppuVar1,
                           (undefined **)
                           ((longlong)*(int *)(puVar5[1] + uVar6 * 4) + (longlong)ppuVar1),param_4,
                           (undefined **)((longlong)param_4 + uVar2 * 4));
      uVar11 = 0xe;
      if (puVar13 == (undefined4 *)0x8000000000000001) {
        if (puVar5[2] <= uVar6) {
                    /* WARNING: Subroutine does not return */
          _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
        }
        *(int *)(puVar5[1] + uVar6 * 4) = (int)uVar2;
        if (puVar5[2] <= (longlong)ppuVar1 + uVar2) {
                    /* WARNING: Subroutine does not return */
          _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
        }
        *(int *)(puVar5[1] + ((longlong)ppuVar1 + uVar2) * 4) = (int)uVar2;
        uVar11 = 0;
      }
      goto LAB_140012642;
    }
    goto LAB_1400126f9;
  }
  _RNvNtNtCsloaxXL3qbEI_4core5slice5index24slice_end_index_len_fail
            (uVar12,uVar14,&anon_67cd83108cc9ed848dbde57549fb323c_20_llvm_3083486868190693220);
LAB_1400126f9:
                    /* WARNING: Subroutine does not return */
  _RNvNtCsloaxXL3qbEI_4core9panicking9panic_fmt();
}



===== _RNvMs4_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE11append_wallB7_ @ 1400127b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
_RNvMs4_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE11append_wallB7_
          (longlong *param_1,undefined4 param_2)

{
  int *piVar1;
  ulonglong *puVar2;
  code *pcVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  undefined1 auStack_78 [32];
  ulonglong *local_58;
  int local_50 [2];
  ulonglong local_48;
  ulonglong local_38;
  undefined8 local_30;
  longlong local_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_78;
  puVar2 = (ulonglong *)*param_1;
  if (puVar2[2] <= (ulonglong)param_1[2]) {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
  }
  piVar1 = (int *)(puVar2[1] + param_1[2] * 4);
  *piVar1 = *piVar1 + 1;
  uVar5 = puVar2[2];
  if (*puVar2 == uVar5) {
    uVar7 = 1;
    if (uVar5 != 0) {
      uVar7 = uVar5 * 2;
    }
    uVar6 = 4;
    if (4 < uVar7) {
      uVar6 = uVar7;
    }
    uVar4 = 0xe;
    if (uVar6 * 4 < 0x7ffffffffffffffd && uVar7 >> 0x3e == 0) {
      if (uVar5 == 0) {
        local_30 = 0;
      }
      else {
        local_38 = puVar2[1];
        local_28 = uVar5 << 2;
        local_30 = 4;
      }
      local_58 = puVar2 + 2;
      _RINvNtCsip5f2bf5HGI_5alloc7raw_vec11finish_growINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EECscIyU0BP6seX_7rgncore_llvm_13477870103536380358
                ((ulonglong *)local_50,&DAT_00000004,uVar6 * 4,&local_38);
      if (local_50[0] == 1) {
        if ((local_20 ^ (ulonglong)auStack_78) == __security_cookie) {
          return 0xe;
        }
        goto LAB_1400128b9;
      }
      puVar2[1] = local_48;
      *puVar2 = uVar6;
      uVar5 = puVar2[2];
      goto LAB_140012841;
    }
  }
  else {
    local_48 = puVar2[1];
LAB_140012841:
    *(undefined4 *)(local_48 + uVar5 * 4) = param_2;
    puVar2[2] = puVar2[2] + 1;
    uVar4 = 0;
  }
  if ((local_20 ^ (ulonglong)auStack_78) == __security_cookie) {
    return uVar4;
  }
LAB_1400128b9:
  pcVar3 = (code *)swi(3);
  uVar4 = (*pcVar3)();
  return uVar4;
}



===== _RNvMs4_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE12remove_wallsB7_ @ 1400128f0 =====

void _RNvMs4_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE12remove_wallsB7_
               (longlong *param_1,longlong param_2,ulonglong param_3)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  int iVar5;
  
  lVar1 = *param_1;
  uVar3 = param_1[2];
  if (uVar3 < *(ulonglong *)(lVar1 + 0x10)) {
    iVar5 = *(int *)(*(longlong *)(lVar1 + 8) + uVar3 * 4) - (int)param_3;
    if (iVar5 < 0) {
                    /* WARNING: Subroutine does not return */
      _RNvNtCsloaxXL3qbEI_4core9panicking5panic();
    }
    *(int *)(*(longlong *)(lVar1 + 8) + uVar3 * 4) = iVar5;
    uVar4 = param_2 + uVar3 + 3;
    uVar3 = uVar4 + param_3;
    if (CARRY8(uVar4,param_3)) {
      uVar2 = _RNvNtNtCsloaxXL3qbEI_4core5slice5index22slice_index_order_fail();
    }
    else {
      uVar2 = *(ulonglong *)(lVar1 + 0x10);
      if (uVar3 <= uVar2) {
        *(ulonglong *)(lVar1 + 0x10) = uVar4;
        if (param_3 == 0) {
          if (uVar2 == uVar3) {
            return;
          }
        }
        else {
          if (uVar2 == uVar3) {
            return;
          }
          memmove((void *)(*(longlong *)(lVar1 + 8) + uVar4 * 4),
                  (void *)(*(longlong *)(lVar1 + 8) + uVar3 * 4),(uVar2 - uVar3) * 4);
        }
        *(ulonglong *)(lVar1 + 0x10) = (uVar2 - uVar3) + uVar4;
        return;
      }
    }
    _RNvNtNtCsloaxXL3qbEI_4core5slice5index24slice_end_index_len_fail
              (uVar3,uVar2,&anon_1de6141e135c3275e99467eeebef3047_1_llvm_1348524820337765946);
  }
                    /* WARNING: Subroutine does not return */
  _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
}



===== _RNvMs4_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE18commit_or_coalesceB7_ @ 1400129d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong _RNvMs4_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE18commit_or_coalesceB7_
                    (longlong *param_1)

{
  undefined4 uVar1;
  ulonglong *puVar2;
  ulonglong uVar3;
  int *piVar4;
  code *pcVar5;
  int iVar6;
  longlong lVar7;
  undefined8 uVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  undefined1 auStack_98 [32];
  undefined **local_78;
  int local_70 [2];
  ulonglong local_68;
  ulonglong local_58 [3];
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_98;
  puVar2 = (ulonglong *)*param_1;
  uVar10 = param_1[2];
  if (uVar10 == 0) {
    uVar9 = puVar2[2];
LAB_140012ad7:
    if (uVar9 <= uVar10) {
                    /* WARNING: Subroutine does not return */
      _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
    }
    piVar4 = (int *)param_1[1];
    uVar13 = puVar2[1];
    uVar1 = *(undefined4 *)(uVar13 + uVar10 * 4);
    if (*puVar2 != uVar9) {
LAB_140012bb1:
      *(undefined4 *)(uVar13 + uVar9 * 4) = uVar1;
      puVar2[2] = puVar2[2] + 1;
      *piVar4 = *piVar4 + 1;
      uVar13 = 0x100;
      uVar9 = 0;
LAB_140012bc2:
      if ((local_40 ^ (ulonglong)auStack_98) == __security_cookie) {
        return uVar9 | uVar13;
      }
      pcVar5 = (code *)swi(3);
      uVar10 = (*pcVar5)();
      return uVar10;
    }
    uVar14 = 4;
    if (4 < uVar9 * 2) {
      uVar14 = uVar9 * 2;
    }
    if (uVar14 * 4 < 0x7ffffffffffffffd && uVar9 < 0x2000000000000000) {
      local_58[2] = uVar9 << 2;
      local_58[1] = 4;
      local_78 = (undefined **)(puVar2 + 2);
      local_58[0] = uVar13;
      _RINvNtCsip5f2bf5HGI_5alloc7raw_vec11finish_growINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EECscIyU0BP6seX_7rgncore_llvm_13477870103536380358
                ((ulonglong *)local_70,&DAT_00000004,uVar14 * 4,local_58);
      if (local_70[0] != 1) {
        puVar2[1] = local_68;
        *puVar2 = uVar14;
        uVar9 = puVar2[2];
        uVar13 = local_68;
        goto LAB_140012bb1;
      }
      uVar9 = puVar2[2];
    }
    if (uVar10 <= uVar9) {
      uVar13 = 0xe00000000;
      puVar2[2] = uVar10;
      uVar9 = 1;
      if (uVar10 == 0) {
        _RNvNtCsjsHfHFRyfyy_10gdi_region3ffi27RustOnZeroSizedScanCallback();
        uVar9 = 1;
      }
      goto LAB_140012bc2;
    }
    goto LAB_140012c5c;
  }
  if (puVar2[2] <= uVar10 - 1) {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
  }
  lVar7 = (longlong)*(int *)((puVar2[1] - 4) + uVar10 * 4);
  if (lVar7 < 0) {
    local_78 = &PTR_anon_67cd83108cc9ed848dbde57549fb323c_2_llvm_3083486868190693220_14001a1c0;
    _RNvNtCsloaxXL3qbEI_4core6result13unwrap_failed();
LAB_140012c14:
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core9panicking5panic();
  }
  lVar7 = uVar10 - lVar7;
  uVar13 = lVar7 - 4;
  uVar8 = _RNvMNtCscIyU0BP6seX_7rgncore4scanINtB2_12ScanInternalQINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEB1o_E13is_valid_scanB4__llvm_3083486868190693220
                    ((longlong)puVar2,uVar13);
  if ((char)uVar8 == '\0') goto LAB_140012c14;
  uVar9 = puVar2[2];
  if (uVar9 <= uVar13) {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
  }
  uVar14 = lVar7 - 1;
  uVar3 = puVar2[1];
  uVar12 = (ulonglong)*(int *)(uVar3 + uVar13 * 4);
  uVar11 = uVar14 + uVar12;
  if (CARRY8(uVar14,uVar12)) {
    _RNvNtNtCsloaxXL3qbEI_4core5slice5index22slice_index_order_fail();
LAB_140012c38:
    _RNvNtNtCsloaxXL3qbEI_4core5slice5index24slice_end_index_len_fail
              (uVar11,uVar9,&anon_67cd83108cc9ed848dbde57549fb323c_20_llvm_3083486868190693220);
  }
  else {
    if (uVar9 < uVar11) goto LAB_140012c38;
    uVar11 = uVar10 + 3;
    if (uVar11 <= uVar9) {
      if (uVar9 - uVar11 == uVar12) {
        iVar6 = memcmp((void *)(uVar3 + uVar14 * 4),(void *)(uVar3 + uVar11 * 4),uVar12 << 2);
        if (iVar6 == 0) {
          if (uVar9 <= uVar10 + 2) {
                    /* WARNING: Subroutine does not return */
            _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
          }
          if (uVar9 <= lVar7 - 2U) {
                    /* WARNING: Subroutine does not return */
            _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
          }
          *(undefined4 *)(uVar3 + 8 + uVar13 * 4) = *(undefined4 *)(uVar3 + 8 + uVar10 * 4);
          if (puVar2[2] < uVar10) goto LAB_140012c5c;
          puVar2[2] = uVar10;
          uVar9 = 0;
          uVar13 = 0;
          goto LAB_140012bc2;
        }
      }
      goto LAB_140012ad7;
    }
  }
  _RNvNtNtCsloaxXL3qbEI_4core5slice5index26slice_start_index_len_fail();
LAB_140012c5c:
                    /* WARNING: Subroutine does not return */
  _RNvNtCsloaxXL3qbEI_4core9panicking5panic();
}



===== _RNvMs4_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE6commitB7_ @ 140012cd0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
_RNvMs4_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE6commitB7_
          (longlong *param_1)

{
  undefined4 uVar1;
  ulonglong *puVar2;
  ulonglong uVar3;
  code *pcVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  undefined1 auStack_88 [32];
  ulonglong *local_68;
  int local_60 [2];
  ulonglong local_58;
  ulonglong local_48 [3];
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_88;
  puVar2 = (ulonglong *)*param_1;
  uVar3 = param_1[2];
  uVar7 = puVar2[2];
  if (uVar7 <= uVar3) {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
  }
  uVar5 = puVar2[1];
  uVar1 = *(undefined4 *)(uVar5 + uVar3 * 4);
  if (*puVar2 == uVar7) {
    uVar8 = 4;
    if (4 < uVar7 * 2) {
      uVar8 = uVar7 * 2;
    }
    if (uVar8 * 4 < 0x7ffffffffffffffd && uVar7 < 0x2000000000000000) {
      local_48[2] = uVar7 << 2;
      local_48[1] = 4;
      local_68 = puVar2 + 2;
      local_48[0] = uVar5;
      _RINvNtCsip5f2bf5HGI_5alloc7raw_vec11finish_growINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EECscIyU0BP6seX_7rgncore_llvm_13477870103536380358
                ((ulonglong *)local_60,&DAT_00000004,uVar8 * 4,local_48);
      if (local_60[0] != 1) {
        puVar2[1] = local_58;
        *puVar2 = uVar8;
        uVar7 = puVar2[2];
        uVar5 = local_58;
        goto LAB_140012de1;
      }
      uVar7 = puVar2[2];
    }
    if (uVar7 < uVar3) {
                    /* WARNING: Subroutine does not return */
      _RNvNtCsloaxXL3qbEI_4core9panicking5panic();
    }
    puVar2[2] = uVar3;
    if (uVar3 == 0) {
      _RNvNtCsjsHfHFRyfyy_10gdi_region3ffi27RustOnZeroSizedScanCallback();
    }
    uVar6 = 0xe;
    if ((local_30 ^ (ulonglong)auStack_88) != __security_cookie) {
LAB_140012e01:
      pcVar4 = (code *)swi(3);
      uVar6 = (*pcVar4)();
      return uVar6;
    }
  }
  else {
LAB_140012de1:
    *(undefined4 *)(uVar5 + uVar7 * 4) = uVar1;
    puVar2[2] = puVar2[2] + 1;
    *(int *)param_1[1] = *(int *)param_1[1] + 1;
    uVar6 = 0;
    if ((local_30 ^ (ulonglong)auStack_88) != __security_cookie) goto LAB_140012e01;
  }
  return uVar6;
}



===== _RNvMs5_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE3new @ 140012e40 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 *
_RNvMs5_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE3new
          (undefined8 *param_1,ulonglong *param_2,undefined4 param_3,undefined4 param_4,
          longlong param_5)

{
  code *pcVar1;
  ulonglong uVar2;
  undefined8 *puVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  undefined1 auStack_98 [32];
  ulonglong *local_78;
  int local_70 [2];
  ulonglong local_68;
  ulonglong local_58;
  undefined8 local_50;
  longlong local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_98;
  uVar4 = param_5 + 4;
  uVar2 = *param_2;
  uVar6 = param_2[2];
  if (uVar2 - uVar6 < uVar4) {
    if (!CARRY8(uVar6,uVar4)) {
      uVar5 = uVar2 * 2;
      if (uVar2 * 2 < uVar6 + uVar4) {
        uVar5 = uVar6 + uVar4;
      }
      uVar7 = 4;
      if (4 < uVar5) {
        uVar7 = uVar5;
      }
      if (uVar7 * 4 < 0x7ffffffffffffffd && uVar5 >> 0x3e == 0) {
        if (uVar2 == 0) {
          local_50 = 0;
        }
        else {
          local_58 = param_2[1];
          local_48 = uVar2 << 2;
          local_50 = 4;
        }
        local_78 = param_2 + 2;
        _RINvNtCsip5f2bf5HGI_5alloc7raw_vec11finish_growINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EECscIyU0BP6seX_7rgncore_llvm_13477870103536380358
                  ((ulonglong *)local_70,&DAT_00000004,uVar7 * 4,&local_58);
        if (local_70[0] != 1) {
          param_2[1] = local_68;
          *param_2 = uVar7;
          uVar6 = param_2[2];
          uVar4 = uVar6;
          uVar2 = uVar7;
          if (uVar7 == uVar6) goto LAB_140012ee5;
          goto LAB_140012f79;
        }
      }
    }
  }
  else {
    uVar4 = uVar6;
    if (uVar2 == uVar6) {
LAB_140012ee5:
      uVar4 = 4;
      if (4 < uVar2 * 2) {
        uVar4 = uVar2 * 2;
      }
      if (uVar2 >> 0x3c == 0) {
        if (uVar2 == 0) {
          local_50 = 0;
        }
        else {
          local_58 = param_2[1];
          local_48 = uVar2 << 2;
          local_50 = 4;
        }
        local_78 = param_2 + 2;
        _RINvNtCsip5f2bf5HGI_5alloc7raw_vec11finish_growINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EECscIyU0BP6seX_7rgncore_llvm_13477870103536380358
                  ((ulonglong *)local_70,&DAT_00000004,uVar4 * 4,&local_58);
        if (local_70[0] != 1) {
          param_2[1] = local_68;
          *param_2 = uVar4;
          uVar4 = param_2[2];
          uVar2 = local_68;
          goto LAB_140012f80;
        }
      }
    }
    else {
LAB_140012f79:
      uVar2 = param_2[1];
      uVar6 = uVar4;
LAB_140012f80:
      *(undefined4 *)(uVar2 + uVar4 * 4) = 0;
      uVar4 = param_2[2];
      uVar2 = uVar4 + 1;
      param_2[2] = uVar2;
      if (*param_2 == uVar2) {
        uVar5 = 4;
        if (4 < uVar2 * 2) {
          uVar5 = uVar2 * 2;
        }
        if (uVar5 * 4 < 0x7ffffffffffffffd && uVar4 != 0x1fffffffffffffff) {
          local_58 = param_2[1];
          local_48 = uVar2 * 4;
          local_50 = 4;
          local_78 = param_2 + 2;
          _RINvNtCsip5f2bf5HGI_5alloc7raw_vec11finish_growINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EECscIyU0BP6seX_7rgncore_llvm_13477870103536380358
                    ((ulonglong *)local_70,&DAT_00000004,uVar5 * 4,&local_58);
          if (local_70[0] != 1) {
            param_2[1] = local_68;
            *param_2 = uVar5;
            uVar2 = param_2[2];
            uVar4 = local_68;
            goto LAB_14001303e;
          }
        }
      }
      else {
        uVar4 = param_2[1];
LAB_14001303e:
        *(undefined4 *)(uVar4 + uVar2 * 4) = param_3;
        uVar4 = param_2[2];
        uVar2 = uVar4 + 1;
        param_2[2] = uVar2;
        if (*param_2 != uVar2) {
          local_68 = param_2[1];
LAB_1400130ed:
          *(undefined4 *)(local_68 + uVar2 * 4) = param_4;
          param_2[2] = param_2[2] + 1;
          *param_1 = param_2;
          param_1[1] = param_2 + 3;
          param_1[2] = uVar6;
          if ((local_40 ^ (ulonglong)auStack_98) == __security_cookie) {
            return param_1;
          }
          goto LAB_140013114;
        }
        uVar5 = 4;
        if (4 < uVar2 * 2) {
          uVar5 = uVar2 * 2;
        }
        if (uVar5 * 4 < 0x7ffffffffffffffd && uVar4 != 0x1fffffffffffffff) {
          local_58 = param_2[1];
          local_48 = uVar2 * 4;
          local_50 = 4;
          local_78 = param_2 + 2;
          _RINvNtCsip5f2bf5HGI_5alloc7raw_vec11finish_growINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EECscIyU0BP6seX_7rgncore_llvm_13477870103536380358
                    ((ulonglong *)local_70,&DAT_00000004,uVar5 * 4,&local_58);
          if (local_70[0] != 1) {
            param_2[1] = local_68;
            *param_2 = uVar5;
            uVar2 = param_2[2];
            goto LAB_1400130ed;
          }
        }
      }
    }
  }
  *(undefined4 *)(param_1 + 1) = 0xe;
  *param_1 = 0;
  if ((local_40 ^ (ulonglong)auStack_98) == __security_cookie) {
    return param_1;
  }
LAB_140013114:
  pcVar1 = (code *)swi(3);
  puVar3 = (undefined8 *)(*pcVar1)();
  return puVar3;
}



===== _RNvMs5_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE11append_scan @ 1400131b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
_RNvMs5_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EE11append_scan
          (ulonglong *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
          ulonglong param_5)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  code *pcVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  undefined4 *puVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  longlong lVar12;
  ulonglong uVar13;
  undefined1 auStack_a8 [32];
  ulonglong *local_88;
  int local_78 [2];
  ulonglong local_70;
  ulonglong local_60;
  undefined8 local_58;
  longlong local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_a8;
  uVar7 = *param_1;
  uVar10 = param_1[2];
  uVar6 = param_5 + 4;
  if (uVar7 - uVar10 < uVar6) {
    if (!CARRY8(uVar10,uVar6)) {
      uVar11 = uVar7 * 2;
      if (uVar7 * 2 < uVar10 + uVar6) {
        uVar11 = uVar10 + uVar6;
      }
      uVar6 = 4;
      if (4 < uVar11) {
        uVar6 = uVar11;
      }
      if (uVar6 * 4 < 0x7ffffffffffffffd && uVar11 >> 0x3e == 0) {
        if (uVar7 == 0) {
          local_58 = 0;
        }
        else {
          local_60 = param_1[1];
          local_50 = uVar7 << 2;
          local_58 = 4;
        }
        local_88 = param_1 + 2;
        _RINvNtCsip5f2bf5HGI_5alloc7raw_vec11finish_growINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EECscIyU0BP6seX_7rgncore_llvm_13477870103536380358
                  ((ulonglong *)local_78,&DAT_00000004,uVar6 * 4,&local_60);
        if (local_78[0] != 1) {
          param_1[1] = local_70;
          *param_1 = uVar6;
          uVar10 = param_1[2];
          uVar7 = uVar6;
          if (uVar6 == uVar10) goto LAB_140013256;
          goto LAB_1400132fe;
        }
      }
    }
  }
  else if (uVar7 == uVar10) {
LAB_140013256:
    uVar6 = 1;
    if (uVar7 != 0) {
      uVar6 = uVar7 * 2;
    }
    uVar10 = 4;
    if (4 < uVar6) {
      uVar10 = uVar6;
    }
    if (uVar10 * 4 < 0x7ffffffffffffffd && uVar6 >> 0x3e == 0) {
      if (uVar7 == 0) {
        local_58 = 0;
      }
      else {
        local_60 = param_1[1];
        local_50 = uVar7 << 2;
        local_58 = 4;
      }
      local_88 = param_1 + 2;
      _RINvNtCsip5f2bf5HGI_5alloc7raw_vec11finish_growINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EECscIyU0BP6seX_7rgncore_llvm_13477870103536380358
                ((ulonglong *)local_78,&DAT_00000004,uVar10 * 4,&local_60);
      if (local_78[0] != 1) {
        param_1[1] = local_70;
        *param_1 = uVar10;
        uVar10 = param_1[2];
        uVar6 = local_70;
        goto LAB_140013302;
      }
    }
  }
  else {
LAB_1400132fe:
    uVar6 = param_1[1];
LAB_140013302:
    *(int *)(uVar6 + uVar10 * 4) = (int)param_5;
    uVar7 = param_1[2];
    uVar6 = uVar7 + 1;
    param_1[2] = uVar6;
    if (*param_1 == uVar6) {
      uVar10 = 4;
      if (4 < uVar6 * 2) {
        uVar10 = uVar6 * 2;
      }
      if (uVar10 * 4 < 0x7ffffffffffffffd && uVar7 != 0x1fffffffffffffff) {
        local_60 = param_1[1];
        local_50 = uVar6 * 4;
        local_58 = 4;
        local_88 = param_1 + 2;
        _RINvNtCsip5f2bf5HGI_5alloc7raw_vec11finish_growINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EECscIyU0BP6seX_7rgncore_llvm_13477870103536380358
                  ((ulonglong *)local_78,&DAT_00000004,uVar10 * 4,&local_60);
        if (local_78[0] != 1) {
          param_1[1] = local_70;
          *param_1 = uVar10;
          uVar6 = param_1[2];
          uVar7 = local_70;
          goto LAB_1400133b4;
        }
      }
    }
    else {
      uVar7 = param_1[1];
LAB_1400133b4:
      *(undefined4 *)(uVar7 + uVar6 * 4) = param_2;
      uVar7 = param_1[2];
      uVar6 = uVar7 + 1;
      param_1[2] = uVar6;
      if (*param_1 == uVar6) {
        uVar10 = 4;
        if (4 < uVar6 * 2) {
          uVar10 = uVar6 * 2;
        }
        if (uVar10 * 4 < 0x7ffffffffffffffd && uVar7 != 0x1fffffffffffffff) {
          local_60 = param_1[1];
          local_50 = uVar6 * 4;
          local_58 = 4;
          local_88 = param_1 + 2;
          _RINvNtCsip5f2bf5HGI_5alloc7raw_vec11finish_growINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EECscIyU0BP6seX_7rgncore_llvm_13477870103536380358
                    ((ulonglong *)local_78,&DAT_00000004,uVar10 * 4,&local_60);
          if (local_78[0] != 1) {
            param_1[1] = local_70;
            *param_1 = uVar10;
            uVar6 = param_1[2];
            uVar7 = local_70;
            goto LAB_14001345b;
          }
        }
      }
      else {
        uVar7 = param_1[1];
LAB_14001345b:
        *(undefined4 *)(uVar7 + uVar6 * 4) = param_3;
        uVar6 = *param_1;
        uVar7 = param_1[2] + 1;
        param_1[2] = uVar7;
        if (uVar6 - uVar7 < param_5) {
          if (!CARRY8(uVar7,param_5)) {
            uVar10 = uVar6 * 2;
            if (uVar6 * 2 < uVar7 + param_5) {
              uVar10 = uVar7 + param_5;
            }
            uVar7 = 4;
            if (4 < uVar10) {
              uVar7 = uVar10;
            }
            if (uVar7 * 4 < 0x7ffffffffffffffd && uVar10 >> 0x3e == 0) {
              if (uVar6 == 0) {
                local_58 = 0;
              }
              else {
                local_60 = param_1[1];
                local_50 = uVar6 << 2;
                local_58 = 4;
              }
              local_88 = param_1 + 2;
              _RINvNtCsip5f2bf5HGI_5alloc7raw_vec11finish_growINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EECscIyU0BP6seX_7rgncore_llvm_13477870103536380358
                        ((ulonglong *)local_78,&DAT_00000004,uVar7 * 4,&local_60);
              if (local_78[0] != 1) {
                param_1[1] = local_70;
                *param_1 = uVar7;
                uVar7 = param_1[2];
                uVar6 = local_70;
                goto LAB_14001357e;
              }
            }
          }
        }
        else {
          if (param_5 != 0) {
            uVar6 = param_1[1];
LAB_14001357e:
            uVar10 = param_5 - 1 & 0x3fffffffffffffff;
            if ((uVar10 < 0xb) || ((uVar6 + uVar7 * 4) - (longlong)param_4 < 0x20)) {
              puVar9 = param_4;
LAB_1400135a9:
              do {
                uVar2 = *puVar9;
                puVar9 = puVar9 + 1;
                *(undefined4 *)(uVar6 + uVar7 * 4) = uVar2;
                uVar7 = uVar7 + 1;
              } while (puVar9 != param_4 + param_5);
            }
            else {
              uVar10 = uVar10 + 1;
              lVar12 = uVar7 * 4;
              uVar11 = uVar10 & 0x7ffffffffffffff8;
              puVar9 = param_4 + uVar11;
              uVar7 = uVar7 + uVar11;
              lVar12 = lVar12 + uVar6;
              uVar13 = 0;
              do {
                uVar8 = *(undefined8 *)((longlong)(param_4 + uVar13) + 8);
                uVar4 = *(undefined8 *)(param_4 + uVar13 + 4);
                uVar5 = *(undefined8 *)((longlong)(param_4 + uVar13 + 4) + 8);
                puVar1 = (undefined8 *)(lVar12 + uVar13 * 4);
                *puVar1 = *(undefined8 *)(param_4 + uVar13);
                puVar1[1] = uVar8;
                puVar1 = (undefined8 *)(lVar12 + 0x10 + uVar13 * 4);
                *puVar1 = uVar4;
                puVar1[1] = uVar5;
                uVar13 = uVar13 + 8;
              } while (uVar11 != uVar13);
              if (uVar10 != uVar11) goto LAB_1400135a9;
            }
            uVar6 = *param_1;
          }
          param_1[2] = uVar7;
          if (uVar6 != uVar7) {
            local_70 = param_1[1];
LAB_140013692:
            *(int *)(local_70 + uVar7 * 4) = (int)param_5;
            param_1[2] = param_1[2] + 1;
            *(int *)(param_1 + 3) = (int)param_1[3] + 1;
            if ((local_48 ^ (ulonglong)auStack_a8) == __security_cookie) {
              return 0;
            }
            goto LAB_140013688;
          }
          uVar7 = 4;
          if (4 < uVar6 * 2) {
            uVar7 = uVar6 * 2;
          }
          if (uVar7 * 4 < 0x7ffffffffffffffd && uVar6 < 0x2000000000000000) {
            local_60 = param_1[1];
            local_50 = uVar6 << 2;
            local_58 = 4;
            local_88 = param_1 + 2;
            _RINvNtCsip5f2bf5HGI_5alloc7raw_vec11finish_growINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EECscIyU0BP6seX_7rgncore_llvm_13477870103536380358
                      ((ulonglong *)local_78,&DAT_00000004,uVar7 * 4,&local_60);
            if (local_78[0] != 1) {
              param_1[1] = local_70;
              *param_1 = uVar7;
              uVar7 = param_1[2];
              goto LAB_140013692;
            }
          }
        }
      }
    }
  }
  if (param_1[2] == 0) {
    _RNvNtCsjsHfHFRyfyy_10gdi_region3ffi27RustOnZeroSizedScanCallback();
    if ((local_48 ^ (ulonglong)auStack_a8) != __security_cookie) goto LAB_140013688;
  }
  else if ((local_48 ^ (ulonglong)auStack_a8) != __security_cookie) {
LAB_140013688:
    pcVar3 = (code *)swi(3);
    uVar8 = (*pcVar3)();
    return uVar8;
  }
  return 0xe;
}



===== _RNvXs6_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EENtNtNtCsloaxXL3qbEI_4core3ops4drop4Drop4dropB7_ @ 140013730 =====

void _RNvXs6_NtCscIyU0BP6seX_7rgncore4scanINtB5_11ScanBuilderINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EENtNtNtCsloaxXL3qbEI_4core3ops4drop4Drop4dropB7_
               (longlong *param_1)

{
  ulonglong uVar1;
  
  uVar1 = param_1[2];
  if (*(ulonglong *)(*param_1 + 0x10) < uVar1) {
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core9panicking5panic();
  }
  *(ulonglong *)(*param_1 + 0x10) = uVar1;
  if (uVar1 == 0) {
    _RNvNtCsjsHfHFRyfyy_10gdi_region3ffi27RustOnZeroSizedScanCallback();
    return;
  }
  return;
}



===== copy_from_slice<usize> @ 140013780 =====

void core::slice::impl$0::copy_from_slice<usize>
               (void *param_1,longlong param_2,void *param_3,longlong param_4)

{
  code *pcVar1;
  
  if (param_2 == param_4) {
    _weak_memcpy_default___llvm_retpoline_r11(param_1,param_3,param_2 << 3);
    return;
  }
  _RNvNvMNtCsloaxXL3qbEI_4core5sliceSp15copy_from_slice17len_mismatch_fail
            (param_2,param_4,&DAT_14001a268);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== index_mut<usize> @ 1400137c0 =====

undefined8 core::slice::index::impl$4::index_mut<usize>(ulonglong param_1,undefined8 param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  
  if (param_1 < 0x10) {
    return param_2;
  }
  _RNvNtNtCsloaxXL3qbEI_4core5slice5index24slice_end_index_len_fail(param_1,0xf,&DAT_14001a250);
  pcVar1 = (code *)swi(3);
  uVar2 = (*pcVar1)();
  return uVar2;
}



===== _RNvNtCs4xf65G0cUDK_10seh_unwind14implementation15raise_exception @ 1400137f0 =====

void _RNvNtCs4xf65G0cUDK_10seh_unwind14implementation15raise_exception
               (undefined4 param_1,void *param_2,ulonglong param_3)

{
  code *pcVar1;
  void *pvVar2;
  undefined8 *puVar3;
  undefined4 local_a8;
  undefined8 local_a4;
  undefined8 uStack_9c;
  undefined4 local_94;
  undefined4 local_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  puVar3 = &local_88;
  local_28 = 0;
  uStack_20 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_18 = 0;
  local_a4 = 0;
  uStack_9c = 0;
  local_94 = 0;
  local_90 = (undefined4)param_3;
  local_a8 = param_1;
  pvVar2 = (void *)core::slice::index::impl$4::index_mut<usize>(param_3,puVar3);
  core::slice::impl$0::copy_from_slice<usize>(pvVar2,(longlong)puVar3,param_2,param_3);
  RtlRaiseException(&local_a8);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== _RNvCs8cVqplN8eB1_7___rustc17rust_begin_unwind @ 140013880 =====

void _RNvCs8cVqplN8eB1_7___rustc17rust_begin_unwind(void)

{
  code *pcVar1;
  
  _RNvNtCs4xf65G0cUDK_10seh_unwind14implementation15raise_exception(0xc0000602,&DAT_00000008,0);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== _RNvCs8cVqplN8eB1_7___rustc35___rust_no_alloc_shim_is_unstable_v2 @ 1400138a0 =====

void _RNvCs8cVqplN8eB1_7___rustc35___rust_no_alloc_shim_is_unstable_v2(void)

{
  return;
}



===== _RINvNtNtNtCsloaxXL3qbEI_4core5slice4sort8unstable7ipnsortRNtNtCs2JCLxFJL4Mh_15onecore_windows6windef6__RECTLNCINvMB6_SBT_20sort_unstable_by_keylNCNvMs_CscIyU0BP6seX_7rgncoreNtB2p_10RegionCore16subtract_complex0E0EB2p_ @ 1400138b0 =====

void _RINvNtNtNtCsloaxXL3qbEI_4core5slice4sort8unstable7ipnsortRNtNtCs2JCLxFJL4Mh_15onecore_windows6windef6__RECTLNCINvMB6_SBT_20sort_unstable_by_keylNCNvMs_CscIyU0BP6seX_7rgncoreNtB2p_10RegionCore16subtract_complex0E0EB2p_
               (longlong *param_1,ulonglong param_2,undefined8 param_3)

{
  undefined1 auVar1 [16];
  int iVar2;
  longlong lVar3;
  ulonglong uVar4;
  longlong lVar5;
  undefined1 (*pauVar6) [16];
  longlong *plVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  int iVar10;
  undefined1 auVar11 [16];
  undefined1 auVar12 [16];
  undefined1 auVar13 [16];
  undefined1 auVar14 [16];
  
  if (param_2 < 2) {
    return;
  }
  iVar2 = *(int *)(param_1[1] + 4);
  uVar8 = 2;
  if (iVar2 < *(int *)(*param_1 + 4)) {
    if (param_2 != 2) {
      iVar10 = iVar2;
      do {
        plVar7 = param_1 + uVar8;
        if (iVar10 <= *(int *)(*plVar7 + 4)) goto LAB_140013910;
        uVar8 = uVar8 + 1;
        iVar10 = *(int *)(*plVar7 + 4);
      } while (param_2 != uVar8);
      goto LAB_140013968;
    }
  }
  else if (param_2 != 2) {
    iVar10 = iVar2;
    do {
      plVar7 = param_1 + uVar8;
      if (*(int *)(*plVar7 + 4) < iVar10) goto LAB_140013910;
      uVar8 = uVar8 + 1;
      iVar10 = *(int *)(*plVar7 + 4);
    } while (param_2 != uVar8);
    goto LAB_140013968;
  }
LAB_140013910:
  if (uVar8 != param_2) {
    lVar5 = 0x3f;
    if ((param_2 | 1) != 0) {
      for (; (param_2 | 1) >> lVar5 == 0; lVar5 = lVar5 + -1) {
      }
    }
    _RINvNtNtNtNtCsloaxXL3qbEI_4core5slice4sort8unstable9quicksort9quicksortRNtNtCs2JCLxFJL4Mh_15onecore_windows6windef6__RECTLNCINvMB8_SB17_20sort_unstable_by_keylNCNvMs_CscIyU0BP6seX_7rgncoreNtB2E_10RegionCore16subtract_complex0E0EB2E_
              (param_1,param_2,(longlong *)0x0,((uint)lVar5 ^ 0x3f) * 2 ^ 0x7e,param_3);
    return;
  }
LAB_140013968:
  if (iVar2 < *(int *)(*param_1 + 4)) {
    uVar8 = param_2 >> 1;
    if (param_2 < 8) {
      uVar4 = 0;
    }
    else {
      uVar4 = uVar8 & 0xfffffffffffffffc;
      pauVar6 = (undefined1 (*) [16])(param_1 + (param_2 - 2));
      uVar9 = 0;
      do {
        auVar12 = *(undefined1 (*) [16])(param_1 + uVar9);
        auVar1 = *(undefined1 (*) [16])(param_1 + uVar9 + 2);
        auVar11 = pauVar6[-1];
        auVar13 = *pauVar6;
        auVar14._8_4_ = auVar13._0_4_;
        auVar14._0_8_ = auVar13._8_8_;
        auVar14._12_4_ = auVar13._4_4_;
        auVar13._8_4_ = auVar11._0_4_;
        auVar13._0_8_ = auVar11._8_8_;
        auVar13._12_4_ = auVar11._4_4_;
        *(undefined1 (*) [16])(param_1 + uVar9) = auVar14;
        *(undefined1 (*) [16])(param_1 + uVar9 + 2) = auVar13;
        auVar11._8_4_ = auVar12._0_4_;
        auVar11._0_8_ = auVar12._8_8_;
        auVar11._12_4_ = auVar12._4_4_;
        *pauVar6 = auVar11;
        auVar12._0_8_ = auVar1._8_8_;
        auVar12._8_4_ = auVar1._0_4_;
        auVar12._12_4_ = auVar1._4_4_;
        pauVar6[-1] = auVar12;
        uVar9 = uVar9 + 4;
        pauVar6 = pauVar6 + -2;
      } while (uVar4 != uVar9);
      if (uVar8 == uVar4) {
        return;
      }
    }
    plVar7 = param_1 + uVar4;
    lVar5 = -uVar4;
    do {
      lVar3 = *plVar7;
      *plVar7 = param_1[param_2 + lVar5 + -1];
      param_1[param_2 + lVar5 + -1] = lVar3;
      lVar5 = lVar5 + -1;
      plVar7 = plVar7 + 1;
    } while (-lVar5 != uVar8);
  }
  return;
}



===== _RNvMs2_NtCsip5f2bf5HGI_5alloc7raw_vecNtB5_11RawVecInner11try_reserveCscIyU0BP6seX_7rgncore @ 140013a40 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong _RNvMs2_NtCsip5f2bf5HGI_5alloc7raw_vecNtB5_11RawVecInner11try_reserveCscIyU0BP6seX_7rgncore
                    (ulonglong *param_1,ulonglong param_2,ulonglong param_3,void *param_4,
                    ulonglong param_5)

{
  code *pcVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  ulonglong uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  undefined1 auStack_68 [32];
  int local_48 [2];
  ulonglong local_40;
  ulonglong local_30;
  void *local_28;
  longlong local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  uVar5 = *param_1;
  if ((-(ulonglong)(param_5 == 0) | uVar5) - param_2 < param_3) {
    if ((param_5 != 0) && (!CARRY8(param_2,param_3))) {
      uVar4 = uVar5 * 2;
      if (uVar5 * 2 < param_2 + param_3) {
        uVar4 = param_2 + param_3;
      }
      uVar6 = 8;
      if (param_5 != 1) {
        uVar6 = (ulonglong)(param_5 < 0x401) * 3 + 1;
      }
      if (uVar6 < uVar4) {
        uVar6 = uVar4;
      }
      auVar2._8_8_ = 0;
      auVar2._0_8_ = -(longlong)param_4 & (longlong)param_4 + (param_5 - 1);
      auVar3._8_8_ = 0;
      auVar3._0_8_ = uVar6;
      uVar4 = SUB168(auVar2 * auVar3,0);
      if (uVar4 <= 0x8000000000000000U - (longlong)param_4 && SUB168(auVar2 * auVar3,8) == 0) {
        if (uVar5 == 0) {
          local_28 = (void *)0x0;
        }
        else {
          local_30 = param_1[1];
          local_20 = uVar5 * param_5;
          local_28 = param_4;
        }
        _RINvNtCsip5f2bf5HGI_5alloc7raw_vec11finish_growNtNtB4_5alloc6GlobalECscIyU0BP6seX_7rgncore_llvm_13477870103536380358
                  ((ulonglong *)local_48,param_4,uVar4,&local_30);
        if (local_48[0] == 1) {
          if ((local_18 ^ (ulonglong)auStack_68) == __security_cookie) {
            return local_40;
          }
          goto LAB_140013b4b;
        }
        param_1[1] = local_40;
        *param_1 = uVar6;
        goto LAB_140013b5d;
      }
    }
    uVar5 = 0;
  }
  else {
LAB_140013b5d:
    uVar5 = 0x8000000000000001;
  }
  if ((local_18 ^ (ulonglong)auStack_68) == __security_cookie) {
    return uVar5;
  }
LAB_140013b4b:
  pcVar1 = (code *)swi(3);
  uVar5 = (*pcVar1)();
  return uVar5;
}



===== _RNvMNtNtCs2JCLxFJL4Mh_15onecore_windows6windef4rectNtB4_6__RECTL16offset_add_point @ 140013b90 =====

void _RNvMNtNtCs2JCLxFJL4Mh_15onecore_windows6windef4rectNtB4_6__RECTL16offset_add_point
               (undefined4 *param_1,int *param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  longlong lVar5;
  int iVar6;
  
  uVar4 = 1;
  iVar6 = 0x216;
  lVar5 = 4;
  if ((((!SCARRY4(*param_2,param_3)) && (iVar1 = param_2[2], !SCARRY4(param_3,param_2[2]))) &&
      (iVar2 = param_2[1], !SCARRY4(iVar2,param_4))) &&
     (iVar3 = param_2[3], !SCARRY4(param_4,param_2[3]))) {
    param_1[1] = *param_2 + param_3;
    param_1[2] = iVar2 + param_4;
    param_1[3] = param_3 + iVar1;
    uVar4 = 0;
    lVar5 = 0x10;
    iVar6 = param_4 + iVar3;
  }
  *(int *)((longlong)param_1 + lVar5) = iVar6;
  *param_1 = uVar4;
  return;
}



===== _RINvXCsgf1RBdmyjwT_12fallible_vecINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEINtB3_11FallibleVeclB13_E10try_extendINtNtNtNtCsloaxXL3qbEI_4core4iter8adapters6cloned6ClonedINtNtNtB2L_5slice4iter4IterlEEECscIyU0BP6seX_7rgncore @ 140013bf0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong _RINvXCsgf1RBdmyjwT_12fallible_vecINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEINtB3_11FallibleVeclB13_E10try_extendINtNtNtNtCsloaxXL3qbEI_4core4iter8adapters6cloned6ClonedINtNtNtB2L_5slice4iter4IterlEEECscIyU0BP6seX_7rgncore
                    (ulonglong *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  code *pcVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  undefined1 auStack_a8 [32];
  ulonglong *local_88;
  ulonglong local_80;
  int local_78 [2];
  ulonglong local_70;
  ulonglong local_60;
  undefined8 local_58;
  longlong local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_a8;
  uVar4 = (ulonglong)((longlong)param_3 - (longlong)param_2) >> 2;
  uVar3 = *param_1;
  uVar6 = param_1[2];
  if (uVar3 - uVar6 < uVar4) {
    if (!CARRY8(uVar6,uVar4)) {
      uVar5 = uVar3 * 2;
      if (uVar3 * 2 < uVar6 + uVar4) {
        uVar5 = uVar6 + uVar4;
      }
      uVar6 = 4;
      if (4 < uVar5) {
        uVar6 = uVar5;
      }
      if (uVar6 * 4 < 0x7ffffffffffffffd && uVar5 >> 0x3e == 0) {
        if (uVar3 == 0) {
          local_58 = 0;
        }
        else {
          local_60 = param_1[1];
          local_50 = uVar3 << 2;
          local_58 = 4;
        }
        local_88 = param_1 + 2;
        _RINvNtCsip5f2bf5HGI_5alloc7raw_vec11finish_growINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EECscIyU0BP6seX_7rgncore_llvm_13477870103536380358
                  ((ulonglong *)local_78,&DAT_00000004,uVar6 * 4,&local_60);
        if (local_78[0] == 1) {
LAB_140013cc9:
          if ((local_48 ^ (ulonglong)auStack_a8) == __security_cookie) {
            return local_70;
          }
          goto LAB_140013e58;
        }
        param_1[1] = local_70;
        *param_1 = uVar6;
        goto LAB_140013cf9;
      }
    }
    uVar3 = 0;
  }
  else {
LAB_140013cf9:
    uVar3 = 0x8000000000000001;
    if (param_2 != param_3) {
      local_80 = 0x8000000000000001;
      uVar3 = param_1[2];
      do {
        uVar1 = *param_2;
        if (*param_1 == uVar3) {
          uVar6 = uVar3 * 2;
          if (uVar3 == 0) {
            uVar6 = 1;
          }
          uVar4 = 4;
          if (4 < uVar6) {
            uVar4 = uVar6;
          }
          if (0x7ffffffffffffffc < uVar4 * 4 || 0x3fffffffffffffff < uVar6) {
            if ((local_48 ^ (ulonglong)auStack_a8) == __security_cookie) {
              return 0;
            }
            goto LAB_140013e58;
          }
          if (uVar3 == 0) {
            local_58 = 0;
          }
          else {
            local_60 = param_1[1];
            local_50 = uVar3 << 2;
            local_58 = 4;
          }
          local_88 = param_1 + 2;
          _RINvNtCsip5f2bf5HGI_5alloc7raw_vec11finish_growINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EECscIyU0BP6seX_7rgncore_llvm_13477870103536380358
                    ((ulonglong *)local_78,&DAT_00000004,uVar4 * 4,&local_60);
          if (local_78[0] == 1) goto LAB_140013cc9;
          param_1[1] = local_70;
          *param_1 = uVar4;
          uVar3 = param_1[2];
          uVar6 = local_70;
        }
        else {
          uVar6 = param_1[1];
        }
        param_2 = param_2 + 1;
        *(undefined4 *)(uVar6 + uVar3 * 4) = uVar1;
        uVar3 = param_1[2] + 1;
        param_1[2] = uVar3;
      } while (param_2 != param_3);
      if ((local_48 ^ (ulonglong)auStack_a8) == __security_cookie) {
        return local_80;
      }
      goto LAB_140013e58;
    }
  }
  if ((local_48 ^ (ulonglong)auStack_a8) == __security_cookie) {
    return uVar3;
  }
LAB_140013e58:
  pcVar2 = (code *)swi(3);
  uVar3 = (*pcVar2)();
  return uVar3;
}



===== _RINvXCsgf1RBdmyjwT_12fallible_vecINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEINtB3_11FallibleVeclB13_E10try_extendINtNtNtNtCsloaxXL3qbEI_4core4iter8adapters6cloned6ClonedINtNtB2H_5chain5ChainIB3x_INtNtNtB2L_5slice4iter4IterlEB3W_EB3W_EEECscIyU0BP6seX_7rgncore @ 140013e70 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong _RINvXCsgf1RBdmyjwT_12fallible_vecINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEINtB3_11FallibleVeclB13_E10try_extendINtNtNtNtCsloaxXL3qbEI_4core4iter8adapters6cloned6ClonedINtNtB2H_5chain5ChainIB3x_INtNtNtB2L_5slice4iter4IterlEB3W_EB3W_EEECscIyU0BP6seX_7rgncore
                    (ulonglong *param_1,ulonglong *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  code *pcVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined4 *puVar6;
  ulonglong uVar7;
  ulonglong *puVar8;
  ulonglong *puVar9;
  undefined4 *puVar10;
  undefined4 uVar11;
  undefined4 *puVar12;
  ulonglong uVar13;
  undefined4 *puVar14;
  ulonglong *puVar15;
  ulonglong *puVar16;
  undefined4 *puVar17;
  undefined1 auStack_c8 [32];
  ulonglong *local_a8;
  ulonglong *local_a0;
  ulonglong local_98;
  undefined4 *local_90;
  ulonglong *local_88;
  undefined4 *local_80;
  int local_78 [2];
  ulonglong local_70;
  ulonglong *local_68;
  ulonglong local_60;
  undefined8 local_58;
  longlong local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_c8;
  puVar9 = (ulonglong *)*param_2;
  puVar12 = (undefined4 *)param_2[5];
  local_a0 = param_1;
  if (puVar9 == (ulonglong *)0x1) {
    uVar4 = param_2[1];
    uVar7 = param_2[3];
    if (puVar12 == (undefined4 *)0x0) {
      if (uVar4 == 0) {
        if (uVar7 == 0) goto LAB_14001405e;
        uVar4 = param_2[4] - uVar7 >> 2;
      }
      else {
        uVar4 = param_2[2] - uVar4 >> 2;
        if (uVar7 != 0) {
          uVar13 = param_2[4] - uVar7 >> 2;
          goto LAB_140013f5c;
        }
      }
    }
    else {
      if (uVar4 == 0) {
        if (uVar7 == 0) {
          uVar13 = 0;
        }
        else {
          uVar13 = param_2[4] - uVar7 >> 2;
        }
      }
      else {
        uVar13 = param_2[2] - uVar4 >> 2;
        if (uVar7 != 0) {
          uVar13 = uVar13 + (param_2[4] - uVar7 >> 2);
        }
      }
      uVar4 = param_2[6] - (longlong)puVar12 >> 2;
LAB_140013f5c:
      uVar4 = uVar4 + uVar13;
    }
  }
  else {
    if (puVar12 == (undefined4 *)0x0) goto LAB_14001405e;
    uVar4 = param_2[6] - (longlong)puVar12 >> 2;
  }
  uVar7 = *param_1;
  uVar13 = param_1[2];
  if (uVar4 <= uVar7 - uVar13) {
LAB_14001405e:
    puVar15 = param_1 + 2;
    puVar10 = (undefined4 *)param_2[1];
    puVar14 = (undefined4 *)param_2[2];
    puVar6 = (undefined4 *)param_2[3];
    local_80 = (undefined4 *)param_2[4];
    puVar2 = (undefined4 *)param_2[6];
    local_98 = 0x8000000000000001;
    puVar8 = local_a0;
    puVar16 = puVar9;
    if (((ulonglong)puVar9 & 1) == 0) goto LAB_1400140c0;
LAB_14001408c:
    if ((puVar10 == (undefined4 *)0x0) || (puVar10 == puVar14)) {
      if (puVar6 == (undefined4 *)0x0) {
        puVar9 = (ulonglong *)0x0;
        puVar17 = (undefined4 *)0x0;
        goto LAB_1400140c6;
      }
      puVar9 = (ulonglong *)0x0;
      puVar17 = (undefined4 *)0x0;
      if (puVar6 == local_80) goto LAB_1400140c6;
      puVar10 = puVar6 + 1;
      puVar17 = (undefined4 *)0x0;
      uVar11 = *puVar6;
      uVar4 = puVar8[2];
      puVar6 = puVar10;
      if (*puVar8 == uVar4) goto LAB_1400140f4;
    }
    else {
      puVar17 = puVar10 + 1;
      uVar11 = *puVar10;
      uVar4 = puVar8[2];
      puVar10 = puVar6;
      if (*puVar8 == uVar4) goto LAB_1400140f4;
    }
    do {
      uVar7 = puVar8[1];
      puVar9 = puVar16;
      puVar10 = puVar17;
      while( true ) {
        *(undefined4 *)(uVar7 + uVar4 * 4) = uVar11;
        *puVar15 = *puVar15 + 1;
        puVar16 = puVar9;
        if (((ulonglong)puVar9 & 1) != 0) goto LAB_14001408c;
LAB_1400140c0:
        puVar17 = puVar10;
LAB_1400140c6:
        if ((puVar12 == (undefined4 *)0x0) || (puVar12 == puVar2)) {
          uVar4 = local_48 ^ (ulonglong)auStack_c8;
          local_68 = puVar9;
          if (uVar4 == __security_cookie) {
            return local_98;
          }
          goto LAB_14001428b;
        }
        puVar1 = puVar12 + 1;
        uVar11 = *puVar12;
        uVar4 = puVar8[2];
        puVar10 = puVar6;
        puVar12 = puVar1;
        puVar16 = puVar9;
        if (*puVar8 != uVar4) break;
LAB_1400140f4:
        uVar7 = uVar4 * 2;
        if (uVar4 == 0) {
          uVar7 = 1;
        }
        uVar13 = 4;
        if (4 < uVar7) {
          uVar13 = uVar7;
        }
        if (0x7ffffffffffffffc < uVar13 * 4 || 0x3fffffffffffffff < uVar7) {
          uVar4 = local_48 ^ (ulonglong)auStack_c8;
          local_68 = (ulonglong *)0x1;
          if (uVar4 == __security_cookie) {
            return 0;
          }
          goto LAB_14001428b;
        }
        if (uVar4 == 0) {
          local_58 = 0;
        }
        else {
          local_60 = local_a0[1];
          local_50 = uVar4 << 2;
          local_58 = 4;
        }
        local_a8 = puVar15;
        local_90 = puVar14;
        local_88 = puVar16;
        _RINvNtCsip5f2bf5HGI_5alloc7raw_vec11finish_growINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EECscIyU0BP6seX_7rgncore_llvm_13477870103536380358
                  ((ulonglong *)local_78,&DAT_00000004,uVar13 * 4,&local_60);
        if (local_78[0] == 1) goto LAB_14001401d;
        local_a0[1] = local_70;
        *local_a0 = uVar13;
        uVar4 = local_a0[2];
        puVar8 = local_a0;
        uVar7 = local_70;
        puVar6 = puVar10;
        puVar14 = local_90;
        puVar9 = local_88;
        puVar10 = puVar17;
      }
    } while( true );
  }
  if (!CARRY8(uVar13,uVar4)) {
    uVar5 = uVar7 * 2;
    if (uVar7 * 2 < uVar13 + uVar4) {
      uVar5 = uVar13 + uVar4;
    }
    uVar4 = 4;
    if (4 < uVar5) {
      uVar4 = uVar5;
    }
    if (uVar4 * 4 < 0x7ffffffffffffffd && uVar5 < 0x4000000000000000) {
      if (uVar7 == 0) {
        local_58 = 0;
      }
      else {
        local_60 = param_1[1];
        local_50 = uVar7 << 2;
        local_58 = 4;
      }
      local_a8 = param_1 + 2;
      _RINvNtCsip5f2bf5HGI_5alloc7raw_vec11finish_growINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EECscIyU0BP6seX_7rgncore_llvm_13477870103536380358
                ((ulonglong *)local_78,&DAT_00000004,uVar4 * 4,&local_60);
      if (local_78[0] != 1) {
        local_a0[1] = local_70;
        *local_a0 = uVar4;
        goto LAB_14001405e;
      }
LAB_14001401d:
      uVar4 = local_48 ^ (ulonglong)auStack_c8;
      if (uVar4 == __security_cookie) {
        return local_70;
      }
      goto LAB_14001428b;
    }
  }
  uVar4 = local_48 ^ (ulonglong)auStack_c8;
  local_68 = param_2;
  if (uVar4 == __security_cookie) {
    return 0;
  }
LAB_14001428b:
  pcVar3 = (code *)swi(3);
  uVar4 = (*pcVar3)(uVar4,local_68);
  return uVar4;
}



===== _RINvXCsgf1RBdmyjwT_12fallible_vecINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEINtB3_11FallibleVeclB13_E13try_splice_inINtNtNtNtCsloaxXL3qbEI_4core4iter8adapters3map3MapINtNtNtB2O_5slice4iter7IterMutlENCNvMs1_NtCscIyU0BP6seX_7rgncore4scanINtB47_12ScanInternalQBv_B13_E16merge_in_x_walls0EINtNtNtB2O_3ops5range5RangejEEB49_ @ 1400142a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 *
_RINvXCsgf1RBdmyjwT_12fallible_vecINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEINtB3_11FallibleVeclB13_E13try_splice_inINtNtNtNtCsloaxXL3qbEI_4core4iter8adapters3map3MapINtNtNtB2O_5slice4iter7IterMutlENCNvMs1_NtCscIyU0BP6seX_7rgncore4scanINtB47_12ScanInternalQBv_B13_E16merge_in_x_walls0EINtNtNtB2O_3ops5range5RangejEEB49_
          (ulonglong *param_1,undefined **param_2,undefined **param_3,undefined **param_4,
          undefined **param_5)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined4 uVar3;
  ulonglong uVar4;
  code *pcVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  undefined **ppuVar12;
  ulonglong uVar13;
  undefined4 *puVar14;
  ulonglong uVar15;
  ulonglong uVar16;
  undefined **ppuVar17;
  longlong lVar18;
  longlong lVar19;
  ulonglong uVar20;
  longlong lVar21;
  undefined **unaff_R14;
  ulonglong uVar22;
  undefined1 auStack_a8 [32];
  ulonglong *local_88;
  int local_78 [2];
  undefined4 *local_70;
  ulonglong local_60;
  undefined4 *local_58;
  ulonglong local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_a8;
  if (param_3 < param_2) {
    ppuVar12 = &PTR_s_d__os_out_rust_cargo_home_amd64f_14001a298;
    _RNvNtNtCsloaxXL3qbEI_4core5slice5index22slice_index_order_fail();
    ppuVar17 = param_3;
LAB_140014807:
    _RNvNtNtCsloaxXL3qbEI_4core5slice5index24slice_end_index_len_fail
              (ppuVar12,ppuVar17,&PTR_s_d__os_out_rust_cargo_home_amd64f_14001a298);
    param_5 = unaff_R14;
LAB_140014819:
    param_3 = &anon_1de6141e135c3275e99467eeebef3047_1_llvm_1348524820337765946;
    _RNvNtNtCsloaxXL3qbEI_4core5slice5index22slice_index_order_fail();
LAB_14001482e:
    _RNvNtNtCsloaxXL3qbEI_4core5slice5index24slice_end_index_len_fail
              (param_3,param_5,&anon_1de6141e135c3275e99467eeebef3047_1_llvm_1348524820337765946);
LAB_140014843:
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core6option13unwrap_failed();
  }
  ppuVar17 = (undefined **)param_1[2];
  ppuVar12 = param_3;
  if ((undefined **)param_1[2] < param_3) goto LAB_140014807;
  if (param_2 < param_3) {
    do {
      if (param_4 == param_5) {
        if (param_3 < param_2) goto LAB_140014819;
        param_5 = (undefined **)param_1[2];
        if (param_5 < param_3) goto LAB_14001482e;
        param_1[2] = (ulonglong)param_2;
        puVar11 = (undefined4 *)0x8000000000000001;
        if (param_3 == param_2) {
          if (param_5 != param_3) {
            param_1[2] = (ulonglong)param_5;
          }
        }
        else if ((longlong)param_5 - (longlong)param_3 != 0) {
          memmove((void *)(param_1[1] + (longlong)param_2 * 4),
                  (void *)(param_1[1] + (longlong)param_3 * 4),
                  ((longlong)param_5 - (longlong)param_3) * 4);
          param_1[2] = ((longlong)param_5 - (longlong)param_3) + (longlong)param_2;
        }
        goto LAB_14001468b;
      }
      if ((undefined **)param_1[2] <= param_2) {
                    /* WARNING: Subroutine does not return */
        _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
      }
      uVar3 = *(undefined4 *)param_4;
      param_4 = (undefined **)((longlong)param_4 + 4);
      *(undefined4 *)(param_1[1] + (longlong)param_2 * 4) = uVar3;
      param_2 = (undefined **)((longlong)param_2 + 1);
    } while (param_3 != param_2);
    param_2 = param_3;
  }
  puVar14 = (undefined4 *)0x8000000000000001;
  ppuVar17 = param_4;
  if ((longlong)param_5 - (longlong)param_4 != 0) {
    uVar22 = (ulonglong)((longlong)param_5 - (longlong)param_4) >> 2;
    uVar4 = *param_1;
    uVar15 = param_1[2];
    if (uVar4 - uVar15 < uVar22) {
      if (!CARRY8(uVar15,uVar22)) {
        uVar16 = uVar4 * 2;
        if (uVar4 * 2 < uVar15 + uVar22) {
          uVar16 = uVar15 + uVar22;
        }
        uVar15 = 4;
        if (4 < uVar16) {
          uVar15 = uVar16;
        }
        if (uVar15 * 4 < 0x7ffffffffffffffd && uVar16 >> 0x3e == 0) {
          if (uVar4 == 0) {
            local_58 = (undefined4 *)0x0;
          }
          else {
            local_60 = param_1[1];
            local_50 = uVar4 << 2;
            local_58 = (undefined4 *)&DAT_00000004;
          }
          local_88 = param_1 + 2;
          _RINvNtCsip5f2bf5HGI_5alloc7raw_vec11finish_growINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EECscIyU0BP6seX_7rgncore_llvm_13477870103536380358
                    ((ulonglong *)local_78,&DAT_00000004,uVar15 * 4,&local_60);
          if (local_78[0] == 1) {
            puVar11 = local_70;
            goto LAB_14001468b;
          }
          param_1[1] = (ulonglong)local_70;
          *param_1 = uVar15;
          uVar15 = param_1[2];
          puVar11 = local_70;
          goto LAB_1400143e6;
        }
      }
      puVar11 = (undefined4 *)0x0;
      goto LAB_14001468b;
    }
    puVar11 = (undefined4 *)param_1[1];
LAB_1400143e6:
    memmove((undefined1 *)
            (((longlong)param_5 - (longlong)param_4) + (longlong)(puVar11 + (longlong)param_2)),
            puVar11 + (longlong)param_2,(uVar15 - (longlong)param_2) * 4);
    uVar4 = param_1[1];
    uVar15 = param_1[2];
    param_1[2] = (ulonglong)param_2;
    uVar16 = uVar22 - 1;
    if (uVar22 < uVar22 - 1) {
      uVar16 = uVar22;
    }
    if (((uVar16 < 0x10) || (((int)param_5 - (int)param_4 & 3U) != 0)) ||
       ((uVar4 + (longlong)param_2 * 4) - (longlong)param_4 < 0x20)) {
      ppuVar12 = param_2;
    }
    else {
      uVar16 = uVar16 + 1;
      uVar13 = 8;
      if ((uVar16 & 7) != 0) {
        uVar13 = (ulonglong)((uint)uVar16 & 7);
      }
      lVar18 = uVar16 - uVar13;
      ppuVar12 = (undefined **)((longlong)param_2 + lVar18);
      ppuVar17 = (undefined **)((longlong)param_4 + lVar18 * 4);
      lVar19 = (longlong)param_2 * 4 + uVar4;
      lVar21 = 0;
      do {
        puVar2 = (undefined8 *)((longlong)param_4 + lVar21 * 4);
        uVar6 = puVar2[1];
        puVar1 = (undefined8 *)((longlong)param_4 + lVar21 * 4 + 0x10);
        uVar7 = *puVar1;
        uVar8 = puVar1[1];
        puVar1 = (undefined8 *)(lVar19 + lVar21 * 4);
        *puVar1 = *puVar2;
        puVar1[1] = uVar6;
        puVar2 = (undefined8 *)(lVar19 + 0x10 + lVar21 * 4);
        *puVar2 = uVar7;
        puVar2[1] = uVar8;
        lVar21 = lVar21 + 8;
      } while (lVar18 != lVar21);
    }
    param_2 = (undefined **)((longlong)param_2 + uVar22);
    do {
      if (ppuVar17 == param_5) goto LAB_140014843;
      uVar3 = *(undefined4 *)ppuVar17;
      ppuVar17 = (undefined **)((longlong)ppuVar17 + 4);
      *(undefined4 *)(uVar4 + (longlong)ppuVar12 * 4) = uVar3;
      ppuVar12 = (undefined **)((longlong)ppuVar12 + 1);
    } while (param_2 != ppuVar12);
    param_1[2] = uVar15 + uVar22;
  }
  local_60 = 0;
  local_58 = (undefined4 *)&DAT_00000004;
  local_50 = 0;
  puVar11 = (undefined4 *)
            _RINvXCsgf1RBdmyjwT_12fallible_vecINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEINtB3_11FallibleVeclB13_E10try_extendINtNtNtNtCsloaxXL3qbEI_4core4iter8adapters6cloned6ClonedINtNtNtB2L_5slice4iter4IterlEEECscIyU0BP6seX_7rgncore
                      (&local_60,(undefined4 *)ppuVar17,(undefined4 *)param_5);
  uVar15 = local_50;
  puVar9 = local_58;
  uVar4 = local_60;
  if (puVar11 != (undefined4 *)0x8000000000000001) {
    if (local_60 != 0) {
      if (local_60 == 0x1c) {
        _RNvNtCsjsHfHFRyfyy_10gdi_region3ffi22ScanLookAsideList_Free();
      }
      else {
        _RNvNtCsiNQa5DCRmUC_9gdi_alloc3ffi13Win32FreePool();
      }
    }
    goto LAB_14001468b;
  }
  if (local_60 == 0x8000000000000000) {
    puVar11 = local_58;
    goto LAB_14001468b;
  }
  if (local_50 != 0) {
    uVar22 = *param_1;
    uVar16 = param_1[2];
    if (uVar22 - uVar16 < local_50) {
      if (CARRY8(uVar16,local_50)) {
LAB_140014546:
        puVar11 = (undefined4 *)0x0;
      }
      else {
        uVar13 = uVar22 * 2;
        if (uVar22 * 2 < uVar16 + local_50) {
          uVar13 = uVar16 + local_50;
        }
        uVar16 = 4;
        if (4 < uVar13) {
          uVar16 = uVar13;
        }
        if (0x7ffffffffffffffc < uVar16 * 4 || 0x3fffffffffffffff < uVar13) goto LAB_140014546;
        if (uVar22 == 0) {
          local_58 = (undefined4 *)0x0;
        }
        else {
          local_60 = param_1[1];
          local_50 = uVar22 << 2;
          local_58 = (undefined4 *)&DAT_00000004;
        }
        local_88 = param_1 + 2;
        _RINvNtCsip5f2bf5HGI_5alloc7raw_vec11finish_growINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EECscIyU0BP6seX_7rgncore_llvm_13477870103536380358
                  ((ulonglong *)local_78,&DAT_00000004,uVar16 * 4,&local_60);
        if (local_78[0] != 1) {
          param_1[1] = (ulonglong)local_70;
          *param_1 = uVar16;
          uVar16 = param_1[2];
          goto LAB_140014604;
        }
        puVar11 = local_70;
      }
      if (uVar4 != 0) {
        if (uVar4 == 0x1c) {
          _RNvNtCsjsHfHFRyfyy_10gdi_region3ffi22ScanLookAsideList_Free();
        }
        else {
          _RNvNtCsiNQa5DCRmUC_9gdi_alloc3ffi13Win32FreePool();
        }
      }
      goto LAB_14001468b;
    }
    local_70 = (undefined4 *)param_1[1];
LAB_140014604:
    memmove(local_70 + (longlong)param_2 + uVar15,local_70 + (longlong)param_2,
            (uVar16 - (longlong)param_2) * 4);
    param_1[2] = param_1[2] + uVar15;
    uVar22 = param_1[1];
    uVar16 = uVar15 + 0x3fffffffffffffff & 0x3fffffffffffffff;
    if ((uVar16 < 0xb) || ((uVar22 + (longlong)param_2 * 4) - (longlong)puVar9 < 0x20)) {
      uVar13 = 0;
      puVar11 = puVar9;
    }
    else {
      uVar16 = uVar16 + 1;
      uVar13 = uVar16 & 0x7ffffffffffffff8;
      puVar11 = puVar9 + uVar13;
      lVar18 = (longlong)param_2 * 4 + uVar22;
      uVar20 = 0;
      do {
        uVar6 = *(undefined8 *)((longlong)(puVar9 + uVar20) + 8);
        uVar7 = *(undefined8 *)(puVar9 + uVar20 + 4);
        uVar8 = *(undefined8 *)((longlong)(puVar9 + uVar20 + 4) + 8);
        puVar2 = (undefined8 *)(lVar18 + uVar20 * 4);
        *puVar2 = *(undefined8 *)(puVar9 + uVar20);
        puVar2[1] = uVar6;
        puVar2 = (undefined8 *)(lVar18 + 0x10 + uVar20 * 4);
        *puVar2 = uVar7;
        puVar2[1] = uVar8;
        uVar20 = uVar20 + 8;
      } while (uVar13 != uVar20);
      if (uVar16 == uVar13) goto LAB_140014671;
    }
    puVar10 = (undefined4 *)(uVar22 + (longlong)param_2 * 4 + uVar13 * 4);
    do {
      uVar3 = *puVar11;
      puVar11 = puVar11 + 1;
      *puVar10 = uVar3;
      puVar10 = puVar10 + 1;
    } while (puVar11 != puVar9 + uVar15);
  }
LAB_140014671:
  puVar11 = puVar14;
  if (uVar4 != 0) {
    if (uVar4 == 0x1c) {
      _RNvNtCsjsHfHFRyfyy_10gdi_region3ffi22ScanLookAsideList_Free();
    }
    else {
      _RNvNtCsiNQa5DCRmUC_9gdi_alloc3ffi13Win32FreePool();
    }
  }
LAB_14001468b:
  if ((local_48 ^ (ulonglong)auStack_a8) == __security_cookie) {
    return puVar11;
  }
  pcVar5 = (code *)swi(3);
  puVar11 = (undefined4 *)(*pcVar5)();
  return puVar11;
}



===== _RINvXCsgf1RBdmyjwT_12fallible_vecINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEINtB3_11FallibleVeclB13_E13try_splice_inINtNtNtNtCsloaxXL3qbEI_4core4iter8adapters6cloned6ClonedINtNtB2K_5chain5ChainIB3A_INtNtNtB2O_5slice4iter4IterlEB3Z_EB3Z_EEINtNtNtB2O_3ops5range5RangejEECscIyU0BP6seX_7rgncore @ 140014870 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 *
_RINvXCsgf1RBdmyjwT_12fallible_vecINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEINtB3_11FallibleVeclB13_E13try_splice_inINtNtNtNtCsloaxXL3qbEI_4core4iter8adapters6cloned6ClonedINtNtB2K_5chain5ChainIB3A_INtNtNtB2O_5slice4iter4IterlEB3Z_EB3Z_EEINtNtNtB2O_3ops5range5RangejEECscIyU0BP6seX_7rgncore
          (ulonglong *param_1,undefined **param_2,undefined **param_3,ulonglong *param_4)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  undefined **ppuVar3;
  code *pcVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined **ppuVar8;
  undefined4 *puVar9;
  undefined **ppuVar10;
  ulonglong uVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  ulonglong uVar14;
  undefined **ppuVar15;
  undefined **ppuVar16;
  undefined **ppuVar17;
  undefined **ppuVar18;
  undefined **ppuVar19;
  ulonglong uVar20;
  longlong lVar21;
  ulonglong uVar22;
  ulonglong uVar23;
  ulonglong uVar24;
  undefined **unaff_R14;
  undefined **ppuVar25;
  undefined1 auStack_d8 [32];
  ulonglong *local_b8;
  undefined **local_b0;
  undefined **local_a8;
  ulonglong local_a0;
  ulonglong local_98;
  undefined **local_90;
  undefined **local_88;
  undefined **local_80;
  undefined **local_78;
  undefined **local_70;
  undefined **local_68;
  ulonglong local_60;
  undefined4 *local_58;
  ulonglong local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_d8;
  if (param_3 < param_2) {
    ppuVar16 = &PTR_s_d__os_out_rust_cargo_home_amd64f_14001a298;
    _RNvNtNtCsloaxXL3qbEI_4core5slice5index22slice_index_order_fail();
    ppuVar15 = param_3;
LAB_140014fe2:
    _RNvNtNtCsloaxXL3qbEI_4core5slice5index24slice_end_index_len_fail
              (ppuVar16,ppuVar15,&PTR_s_d__os_out_rust_cargo_home_amd64f_14001a298);
LAB_140014ff4:
    param_3 = &anon_1de6141e135c3275e99467eeebef3047_1_llvm_1348524820337765946;
    _RNvNtNtCsloaxXL3qbEI_4core5slice5index22slice_index_order_fail();
LAB_140015009:
    _RNvNtNtCsloaxXL3qbEI_4core5slice5index24slice_end_index_len_fail
              (param_3,unaff_R14,&anon_1de6141e135c3275e99467eeebef3047_1_llvm_1348524820337765946);
LAB_14001501e:
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core6option13unwrap_failed();
  }
  ppuVar15 = (undefined **)param_1[2];
  ppuVar16 = param_3;
  if ((undefined **)param_1[2] < param_3) goto LAB_140014fe2;
  uVar24 = *param_4;
  ppuVar16 = (undefined **)param_4[1];
  ppuVar17 = (undefined **)param_4[2];
  ppuVar15 = (undefined **)param_4[3];
  ppuVar18 = (undefined **)param_4[4];
  ppuVar25 = (undefined **)param_4[5];
  unaff_R14 = (undefined **)param_4[6];
  if (param_2 < param_3) {
    do {
      ppuVar19 = ppuVar15;
      if ((uVar24 & 1) == 0) {
        uVar23 = uVar24;
LAB_1400149be:
        if ((ppuVar25 == (undefined **)0x0) || (ppuVar25 == unaff_R14)) {
          if (param_3 < param_2) goto LAB_140014ff4;
          unaff_R14 = (undefined **)param_1[2];
          if (unaff_R14 < param_3) goto LAB_140015009;
          param_1[2] = (ulonglong)param_2;
          puVar13 = (undefined4 *)0x8000000000000001;
          if (param_3 == param_2) {
            if (unaff_R14 != param_3) {
              param_1[2] = (ulonglong)unaff_R14;
            }
          }
          else if ((longlong)unaff_R14 - (longlong)param_3 != 0) {
            memmove((void *)(param_1[1] + (longlong)param_2 * 4),
                    (void *)(param_1[1] + (longlong)param_3 * 4),
                    ((longlong)unaff_R14 - (longlong)param_3) * 4);
            param_1[2] = ((longlong)unaff_R14 - (longlong)param_3) + (longlong)param_2;
          }
          goto LAB_140014f0b;
        }
        ppuVar3 = (undefined **)param_1[2];
        ppuVar10 = ppuVar16;
        ppuVar8 = ppuVar25;
        uVar24 = uVar23;
        ppuVar25 = (undefined **)((longlong)ppuVar25 + 4);
      }
      else if ((ppuVar16 == (undefined **)0x0) || (ppuVar16 == ppuVar17)) {
        ppuVar16 = (undefined **)0x0;
        uVar23 = 0;
        if (ppuVar15 == ppuVar18 || ppuVar15 == (undefined **)0x0) goto LAB_1400149be;
        ppuVar3 = (undefined **)param_1[2];
        ppuVar19 = (undefined **)((longlong)ppuVar15 + 4);
        ppuVar10 = (undefined **)0x0;
        ppuVar8 = ppuVar15;
      }
      else {
        ppuVar3 = (undefined **)param_1[2];
        ppuVar10 = (undefined **)((longlong)ppuVar16 + 4);
        ppuVar8 = ppuVar16;
      }
      ppuVar16 = ppuVar10;
      ppuVar15 = ppuVar19;
      if (ppuVar3 <= param_2) {
                    /* WARNING: Subroutine does not return */
        _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
      }
      *(undefined4 *)(param_1[1] + (longlong)param_2 * 4) = *(undefined4 *)ppuVar8;
      param_2 = (undefined **)((longlong)param_2 + 1);
    } while (param_3 != param_2);
    param_2 = param_3;
    if ((uVar24 & 1) != 0) goto LAB_1400148ee;
LAB_140014a16:
    if (ppuVar25 == (undefined **)0x0) {
      ppuVar25 = (undefined **)0x0;
      ppuVar19 = param_2;
      local_b0 = ppuVar18;
    }
    else {
      uVar23 = (ulonglong)((longlong)unaff_R14 - (longlong)ppuVar25) >> 2;
LAB_140014af8:
      ppuVar19 = param_2;
      local_b0 = ppuVar18;
      if (uVar23 != 0) {
        uVar11 = *param_1;
        uVar20 = param_1[2];
        if (uVar11 - uVar20 < uVar23) {
          if (!CARRY8(uVar20,uVar23)) {
            uVar14 = uVar11 * 2;
            if (uVar11 * 2 < uVar20 + uVar23) {
              uVar14 = uVar20 + uVar23;
            }
            uVar20 = 4;
            if (4 < uVar14) {
              uVar20 = uVar14;
            }
            if (uVar20 * 4 < 0x7ffffffffffffffd && uVar14 >> 0x3e == 0) {
              if (uVar11 == 0) {
                local_90 = (undefined **)0x0;
              }
              else {
                local_98 = param_1[1];
                local_88 = (undefined **)(uVar11 << 2);
                local_90 = (undefined **)&DAT_00000004;
              }
              local_b8 = param_1 + 2;
              local_a8 = ppuVar17;
              local_a0 = uVar20;
              _RINvNtCsip5f2bf5HGI_5alloc7raw_vec11finish_growINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EECscIyU0BP6seX_7rgncore_llvm_13477870103536380358
                        (&local_60,&DAT_00000004,uVar20 * 4,&local_98);
              if ((int)local_60 == 1) {
                puVar13 = local_58;
                goto LAB_140014f0b;
              }
              param_1[1] = (ulonglong)local_58;
              *param_1 = local_a0;
              uVar20 = param_1[2];
              goto LAB_140014b6d;
            }
          }
          puVar13 = (undefined4 *)0x0;
          goto LAB_140014f0b;
        }
        local_58 = (undefined4 *)param_1[1];
        local_a8 = ppuVar17;
LAB_140014b6d:
        memmove(local_58 + (longlong)param_2 + uVar23,local_58 + (longlong)param_2,
                (uVar20 - (longlong)param_2) * 4);
        uVar11 = param_1[2];
        param_1[2] = (ulonglong)param_2;
        ppuVar19 = (undefined **)(uVar23 + (longlong)param_2);
        uVar20 = param_1[1];
        uVar14 = 0;
        ppuVar17 = ppuVar16;
        ppuVar18 = ppuVar15;
        do {
          ppuVar15 = ppuVar18;
          if ((uVar24 & 1) == 0) {
            ppuVar16 = ppuVar17;
            uVar22 = uVar24;
LAB_140014c2a:
            if ((ppuVar25 == (undefined **)0x0) || (ppuVar25 == unaff_R14)) goto LAB_14001501e;
            ppuVar18 = ppuVar25;
            uVar24 = uVar22;
            ppuVar25 = (undefined **)((longlong)ppuVar25 + 4);
          }
          else if ((ppuVar17 == (undefined **)0x0) || (ppuVar17 == local_a8)) {
            ppuVar16 = (undefined **)0x0;
            uVar22 = 0;
            if (ppuVar18 == local_b0 || ppuVar18 == (undefined **)0x0) goto LAB_140014c2a;
            ppuVar15 = (undefined **)((longlong)ppuVar18 + 4);
            ppuVar16 = (undefined **)0x0;
          }
          else {
            ppuVar16 = (undefined **)((longlong)ppuVar17 + 4);
            ppuVar18 = ppuVar17;
          }
          *(undefined4 *)((longlong)param_2 * 4 + uVar20 + uVar14 * 4) = *(undefined4 *)ppuVar18;
          uVar14 = uVar14 + 1;
          ppuVar17 = ppuVar16;
          ppuVar18 = ppuVar15;
        } while (uVar23 != uVar14);
        param_1[2] = uVar11 + uVar23;
        ppuVar17 = local_a8;
      }
    }
  }
  else {
    if ((uVar24 & 1) == 0) goto LAB_140014a16;
LAB_1400148ee:
    if (ppuVar25 != (undefined **)0x0) {
      if (ppuVar16 == (undefined **)0x0) {
        if (ppuVar15 == (undefined **)0x0) {
          uVar11 = 0;
        }
        else {
          uVar11 = (ulonglong)((longlong)ppuVar18 - (longlong)ppuVar15) >> 2;
        }
      }
      else {
        uVar11 = (ulonglong)((longlong)ppuVar17 - (longlong)ppuVar16) >> 2;
        if (ppuVar15 != (undefined **)0x0) {
          uVar11 = uVar11 + ((ulonglong)((longlong)ppuVar18 - (longlong)ppuVar15) >> 2);
        }
      }
      uVar23 = (ulonglong)((longlong)unaff_R14 - (longlong)ppuVar25) >> 2;
LAB_140014af5:
      uVar23 = uVar23 + uVar11;
      goto LAB_140014af8;
    }
    if (ppuVar16 != (undefined **)0x0) {
      uVar23 = (ulonglong)((longlong)ppuVar17 - (longlong)ppuVar16) >> 2;
      if (ppuVar15 != (undefined **)0x0) {
        uVar11 = (ulonglong)((longlong)ppuVar18 - (longlong)ppuVar15) >> 2;
        goto LAB_140014af5;
      }
      goto LAB_140014af8;
    }
    if (ppuVar15 != (undefined **)0x0) {
      uVar23 = (ulonglong)((longlong)ppuVar18 - (longlong)ppuVar15) >> 2;
      goto LAB_140014af8;
    }
    ppuVar25 = (undefined **)0x0;
    ppuVar15 = (undefined **)0x0;
    ppuVar16 = (undefined **)0x0;
    ppuVar19 = param_2;
    local_b0 = ppuVar18;
  }
  local_78 = local_b0;
  local_60 = 0;
  local_58 = (undefined4 *)&DAT_00000004;
  local_50 = 0;
  local_98 = uVar24;
  local_90 = ppuVar16;
  local_88 = ppuVar17;
  local_80 = ppuVar15;
  local_70 = ppuVar25;
  local_68 = unaff_R14;
  puVar13 = (undefined4 *)
            _RINvXCsgf1RBdmyjwT_12fallible_vecINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEINtB3_11FallibleVeclB13_E10try_extendINtNtNtNtCsloaxXL3qbEI_4core4iter8adapters6cloned6ClonedINtNtB2H_5chain5ChainIB3x_INtNtNtB2L_5slice4iter4IterlEB3W_EB3W_EEECscIyU0BP6seX_7rgncore
                      (&local_60,&local_98);
  uVar23 = local_50;
  puVar9 = local_58;
  uVar24 = local_60;
  if (puVar13 != (undefined4 *)0x8000000000000001) {
    if (local_60 != 0) {
      if (local_60 == 0x1c) {
        _RNvNtCsjsHfHFRyfyy_10gdi_region3ffi22ScanLookAsideList_Free();
      }
      else {
        _RNvNtCsiNQa5DCRmUC_9gdi_alloc3ffi13Win32FreePool();
      }
    }
    goto LAB_140014f0b;
  }
  if (local_60 == 0x8000000000000000) {
    puVar13 = local_58;
    goto LAB_140014f0b;
  }
  if (local_50 != 0) {
    uVar11 = *param_1;
    uVar20 = param_1[2];
    if (uVar11 - uVar20 < local_50) {
      if (CARRY8(uVar20,local_50)) {
LAB_140014d75:
        puVar13 = (undefined4 *)0x0;
      }
      else {
        uVar14 = uVar11 * 2;
        if (uVar11 * 2 < uVar20 + local_50) {
          uVar14 = uVar20 + local_50;
        }
        uVar20 = 4;
        if (4 < uVar14) {
          uVar20 = uVar14;
        }
        if (0x7ffffffffffffffc < uVar20 * 4 || 0x3fffffffffffffff < uVar14) goto LAB_140014d75;
        if (uVar11 == 0) {
          local_90 = (undefined **)0x0;
        }
        else {
          local_98 = param_1[1];
          local_88 = (undefined **)(uVar11 << 2);
          local_90 = (undefined **)&DAT_00000004;
        }
        local_b8 = param_1 + 2;
        _RINvNtCsip5f2bf5HGI_5alloc7raw_vec11finish_growINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EECscIyU0BP6seX_7rgncore_llvm_13477870103536380358
                  (&local_60,&DAT_00000004,uVar20 * 4,&local_98);
        if ((int)local_60 != 1) {
          param_1[1] = (ulonglong)local_58;
          *param_1 = uVar20;
          uVar20 = param_1[2];
          puVar13 = local_58;
          goto LAB_140014da4;
        }
        puVar13 = local_58;
      }
      if (uVar24 != 0) {
        if (uVar24 == 0x1c) {
          _RNvNtCsjsHfHFRyfyy_10gdi_region3ffi22ScanLookAsideList_Free();
        }
        else {
          _RNvNtCsiNQa5DCRmUC_9gdi_alloc3ffi13Win32FreePool();
        }
      }
      goto LAB_140014f0b;
    }
    puVar13 = (undefined4 *)param_1[1];
LAB_140014da4:
    memmove(puVar13 + (longlong)ppuVar19 + uVar23,puVar13 + (longlong)ppuVar19,
            (uVar20 - (longlong)ppuVar19) * 4);
    param_1[2] = param_1[2] + uVar23;
    uVar11 = param_1[1];
    uVar20 = uVar23 + 0x3fffffffffffffff & 0x3fffffffffffffff;
    puVar13 = puVar9;
    if (uVar20 < 0xb) {
      uVar14 = 0;
    }
    else if ((uVar11 + (longlong)ppuVar19 * 4) - (longlong)puVar9 < 0x20) {
      uVar14 = 0;
    }
    else {
      uVar20 = uVar20 + 1;
      uVar14 = uVar20 & 0x7ffffffffffffff8;
      puVar13 = puVar9 + uVar14;
      lVar21 = (longlong)ppuVar19 * 4 + uVar11;
      uVar22 = 0;
      do {
        uVar5 = *(undefined8 *)((longlong)(puVar9 + uVar22) + 8);
        uVar6 = *(undefined8 *)(puVar9 + uVar22 + 4);
        uVar7 = *(undefined8 *)((longlong)(puVar9 + uVar22 + 4) + 8);
        puVar1 = (undefined8 *)(lVar21 + uVar22 * 4);
        *puVar1 = *(undefined8 *)(puVar9 + uVar22);
        puVar1[1] = uVar5;
        puVar1 = (undefined8 *)(lVar21 + 0x10 + uVar22 * 4);
        *puVar1 = uVar6;
        puVar1[1] = uVar7;
        uVar22 = uVar22 + 8;
      } while (uVar14 != uVar22);
      if (uVar20 == uVar14) goto LAB_140014ef1;
    }
    puVar12 = (undefined4 *)(uVar11 + uVar14 * 4 + (longlong)ppuVar19 * 4);
    do {
      uVar2 = *puVar13;
      puVar13 = puVar13 + 1;
      *puVar12 = uVar2;
      puVar12 = puVar12 + 1;
    } while (puVar13 != puVar9 + uVar23);
  }
LAB_140014ef1:
  puVar13 = (undefined4 *)0x8000000000000001;
  if (uVar24 != 0) {
    if (uVar24 == 0x1c) {
      _RNvNtCsjsHfHFRyfyy_10gdi_region3ffi22ScanLookAsideList_Free();
    }
    else {
      _RNvNtCsiNQa5DCRmUC_9gdi_alloc3ffi13Win32FreePool();
    }
  }
LAB_140014f0b:
  if ((local_48 ^ (ulonglong)auStack_d8) == __security_cookie) {
    return puVar13;
  }
  pcVar4 = (code *)swi(3);
  puVar13 = (undefined4 *)(*pcVar4)();
  return puVar13;
}



===== _RINvXCsgf1RBdmyjwT_12fallible_vecINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEINtB3_11FallibleVeclB13_E13try_splice_inINtNtNtNtCsloaxXL3qbEI_4core4iter8adapters6cloned6ClonedINtNtNtB2O_5slice4iter4IterlEEINtNtNtB2O_3ops5range5RangejEECscIyU0BP6seX_7rgncore @ 140015040 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 *
_RINvXCsgf1RBdmyjwT_12fallible_vecINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEINtB3_11FallibleVeclB13_E13try_splice_inINtNtNtNtCsloaxXL3qbEI_4core4iter8adapters6cloned6ClonedINtNtNtB2O_5slice4iter4IterlEEINtNtNtB2O_3ops5range5RangejEECscIyU0BP6seX_7rgncore
          (ulonglong *param_1,undefined **param_2,undefined **param_3,undefined **param_4,
          undefined **param_5)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined4 uVar3;
  ulonglong uVar4;
  code *pcVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  ulonglong uVar12;
  undefined4 *puVar13;
  ulonglong uVar14;
  undefined **ppuVar15;
  ulonglong uVar16;
  undefined **ppuVar17;
  longlong lVar18;
  ulonglong uVar19;
  longlong lVar20;
  longlong lVar21;
  undefined **unaff_R14;
  ulonglong uVar22;
  undefined1 auStack_a8 [32];
  ulonglong *local_88;
  int local_78 [2];
  undefined4 *local_70;
  ulonglong local_60;
  undefined4 *local_58;
  ulonglong local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_a8;
  if (param_3 < param_2) {
    ppuVar15 = &PTR_s_d__os_out_rust_cargo_home_amd64f_14001a298;
    _RNvNtNtCsloaxXL3qbEI_4core5slice5index22slice_index_order_fail();
    ppuVar17 = param_3;
LAB_1400155b7:
    _RNvNtNtCsloaxXL3qbEI_4core5slice5index24slice_end_index_len_fail
              (ppuVar15,ppuVar17,&PTR_s_d__os_out_rust_cargo_home_amd64f_14001a298);
    param_5 = unaff_R14;
LAB_1400155c9:
    param_3 = &anon_1de6141e135c3275e99467eeebef3047_1_llvm_1348524820337765946;
    _RNvNtNtCsloaxXL3qbEI_4core5slice5index22slice_index_order_fail();
LAB_1400155de:
    _RNvNtNtCsloaxXL3qbEI_4core5slice5index24slice_end_index_len_fail
              (param_3,param_5,&anon_1de6141e135c3275e99467eeebef3047_1_llvm_1348524820337765946);
LAB_1400155f3:
                    /* WARNING: Subroutine does not return */
    _RNvNtCsloaxXL3qbEI_4core6option13unwrap_failed();
  }
  ppuVar17 = (undefined **)param_1[2];
  ppuVar15 = param_3;
  if ((undefined **)param_1[2] < param_3) goto LAB_1400155b7;
  if (param_2 < param_3) {
    do {
      if (param_4 == param_5) {
        if (param_3 < param_2) goto LAB_1400155c9;
        param_5 = (undefined **)param_1[2];
        if (param_5 < param_3) goto LAB_1400155de;
        param_1[2] = (ulonglong)param_2;
        puVar11 = (undefined4 *)0x8000000000000001;
        if (param_3 == param_2) {
          if (param_5 != param_3) {
            param_1[2] = (ulonglong)param_5;
          }
        }
        else if ((longlong)param_5 - (longlong)param_3 != 0) {
          memmove((void *)(param_1[1] + (longlong)param_2 * 4),
                  (void *)(param_1[1] + (longlong)param_3 * 4),
                  ((longlong)param_5 - (longlong)param_3) * 4);
          param_1[2] = ((longlong)param_5 - (longlong)param_3) + (longlong)param_2;
        }
        goto LAB_14001543b;
      }
      if ((undefined **)param_1[2] <= param_2) {
                    /* WARNING: Subroutine does not return */
        _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check();
      }
      uVar3 = *(undefined4 *)param_4;
      param_4 = (undefined **)((longlong)param_4 + 4);
      *(undefined4 *)(param_1[1] + (longlong)param_2 * 4) = uVar3;
      param_2 = (undefined **)((longlong)param_2 + 1);
    } while (param_3 != param_2);
    param_2 = param_3;
  }
  puVar13 = (undefined4 *)0x8000000000000001;
  ppuVar17 = param_4;
  if ((longlong)param_5 - (longlong)param_4 != 0) {
    uVar22 = (ulonglong)((longlong)param_5 - (longlong)param_4) >> 2;
    uVar4 = *param_1;
    uVar14 = param_1[2];
    if (uVar4 - uVar14 < uVar22) {
      if (!CARRY8(uVar14,uVar22)) {
        uVar16 = uVar4 * 2;
        if (uVar4 * 2 < uVar14 + uVar22) {
          uVar16 = uVar14 + uVar22;
        }
        uVar14 = 4;
        if (4 < uVar16) {
          uVar14 = uVar16;
        }
        if (uVar14 * 4 < 0x7ffffffffffffffd && uVar16 >> 0x3e == 0) {
          if (uVar4 == 0) {
            local_58 = (undefined4 *)0x0;
          }
          else {
            local_60 = param_1[1];
            local_50 = uVar4 << 2;
            local_58 = (undefined4 *)&DAT_00000004;
          }
          local_88 = param_1 + 2;
          _RINvNtCsip5f2bf5HGI_5alloc7raw_vec11finish_growINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EECscIyU0BP6seX_7rgncore_llvm_13477870103536380358
                    ((ulonglong *)local_78,&DAT_00000004,uVar14 * 4,&local_60);
          if (local_78[0] == 1) {
            puVar11 = local_70;
            goto LAB_14001543b;
          }
          param_1[1] = (ulonglong)local_70;
          *param_1 = uVar14;
          uVar14 = param_1[2];
          puVar11 = local_70;
          goto LAB_140015186;
        }
      }
      puVar11 = (undefined4 *)0x0;
      goto LAB_14001543b;
    }
    puVar11 = (undefined4 *)param_1[1];
LAB_140015186:
    memmove((undefined1 *)
            (((longlong)param_5 - (longlong)param_4) + (longlong)(puVar11 + (longlong)param_2)),
            puVar11 + (longlong)param_2,(uVar14 - (longlong)param_2) * 4);
    uVar4 = param_1[1];
    uVar14 = param_1[2];
    param_1[2] = (ulonglong)param_2;
    uVar16 = uVar22 - 1;
    if (uVar22 < uVar22 - 1) {
      uVar16 = uVar22;
    }
    ppuVar15 = param_2;
    if (((0xf < uVar16) && (((int)param_5 - (int)param_4 & 3U) == 0)) &&
       (0x1f < (uVar4 + (longlong)param_2 * 4) - (longlong)param_4)) {
      uVar16 = uVar16 + 1;
      uVar12 = 8;
      if ((uVar16 & 7) != 0) {
        uVar12 = (ulonglong)((uint)uVar16 & 7);
      }
      lVar18 = uVar16 - uVar12;
      ppuVar17 = (undefined **)((longlong)param_4 + lVar18 * 4);
      ppuVar15 = (undefined **)((longlong)param_2 + lVar18);
      lVar20 = (longlong)param_2 * 4 + uVar4;
      lVar21 = 0;
      do {
        puVar2 = (undefined8 *)((longlong)param_4 + lVar21 * 4);
        uVar6 = puVar2[1];
        puVar1 = (undefined8 *)((longlong)param_4 + lVar21 * 4 + 0x10);
        uVar7 = *puVar1;
        uVar8 = puVar1[1];
        puVar1 = (undefined8 *)(lVar20 + lVar21 * 4);
        *puVar1 = *puVar2;
        puVar1[1] = uVar6;
        puVar2 = (undefined8 *)(lVar20 + 0x10 + lVar21 * 4);
        *puVar2 = uVar7;
        puVar2[1] = uVar8;
        lVar21 = lVar21 + 8;
      } while (lVar18 != lVar21);
    }
    param_2 = (undefined **)((longlong)param_2 + uVar22);
    do {
      if (ppuVar17 == param_5) goto LAB_1400155f3;
      uVar3 = *(undefined4 *)ppuVar17;
      ppuVar17 = (undefined **)((longlong)ppuVar17 + 4);
      *(undefined4 *)(uVar4 + (longlong)ppuVar15 * 4) = uVar3;
      ppuVar15 = (undefined **)((longlong)ppuVar15 + 1);
    } while (param_2 != ppuVar15);
    param_1[2] = uVar14 + uVar22;
  }
  local_60 = 0;
  local_58 = (undefined4 *)&DAT_00000004;
  local_50 = 0;
  puVar11 = (undefined4 *)
            _RINvXCsgf1RBdmyjwT_12fallible_vecINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEINtB3_11FallibleVeclB13_E10try_extendINtNtNtNtCsloaxXL3qbEI_4core4iter8adapters6cloned6ClonedINtNtNtB2L_5slice4iter4IterlEEECscIyU0BP6seX_7rgncore
                      (&local_60,(undefined4 *)ppuVar17,(undefined4 *)param_5);
  uVar14 = local_50;
  puVar9 = local_58;
  uVar4 = local_60;
  if (puVar11 != (undefined4 *)0x8000000000000001) {
    if (local_60 != 0) {
      if (local_60 == 0x1c) {
        _RNvNtCsjsHfHFRyfyy_10gdi_region3ffi22ScanLookAsideList_Free();
      }
      else {
        _RNvNtCsiNQa5DCRmUC_9gdi_alloc3ffi13Win32FreePool();
      }
    }
    goto LAB_14001543b;
  }
  if (local_60 == 0x8000000000000000) {
    puVar11 = local_58;
    goto LAB_14001543b;
  }
  if (local_50 != 0) {
    uVar22 = *param_1;
    uVar16 = param_1[2];
    if (uVar22 - uVar16 < local_50) {
      if (CARRY8(uVar16,local_50)) {
LAB_1400152f6:
        puVar11 = (undefined4 *)0x0;
      }
      else {
        uVar12 = uVar22 * 2;
        if (uVar22 * 2 < uVar16 + local_50) {
          uVar12 = uVar16 + local_50;
        }
        uVar16 = 4;
        if (4 < uVar12) {
          uVar16 = uVar12;
        }
        if (0x7ffffffffffffffc < uVar16 * 4 || 0x3fffffffffffffff < uVar12) goto LAB_1400152f6;
        if (uVar22 == 0) {
          local_58 = (undefined4 *)0x0;
        }
        else {
          local_60 = param_1[1];
          local_50 = uVar22 << 2;
          local_58 = (undefined4 *)&DAT_00000004;
        }
        local_88 = param_1 + 2;
        _RINvNtCsip5f2bf5HGI_5alloc7raw_vec11finish_growINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EECscIyU0BP6seX_7rgncore_llvm_13477870103536380358
                  ((ulonglong *)local_78,&DAT_00000004,uVar16 * 4,&local_60);
        if (local_78[0] != 1) {
          param_1[1] = (ulonglong)local_70;
          *param_1 = uVar16;
          uVar16 = param_1[2];
          goto LAB_1400153b4;
        }
        puVar11 = local_70;
      }
      if (uVar4 != 0) {
        if (uVar4 == 0x1c) {
          _RNvNtCsjsHfHFRyfyy_10gdi_region3ffi22ScanLookAsideList_Free();
        }
        else {
          _RNvNtCsiNQa5DCRmUC_9gdi_alloc3ffi13Win32FreePool();
        }
      }
      goto LAB_14001543b;
    }
    local_70 = (undefined4 *)param_1[1];
LAB_1400153b4:
    memmove(local_70 + (longlong)param_2 + uVar14,local_70 + (longlong)param_2,
            (uVar16 - (longlong)param_2) * 4);
    param_1[2] = param_1[2] + uVar14;
    uVar22 = param_1[1];
    uVar16 = uVar14 + 0x3fffffffffffffff & 0x3fffffffffffffff;
    if ((uVar16 < 0xb) || ((uVar22 + (longlong)param_2 * 4) - (longlong)puVar9 < 0x20)) {
      uVar12 = 0;
      puVar11 = puVar9;
    }
    else {
      uVar16 = uVar16 + 1;
      uVar12 = uVar16 & 0x7ffffffffffffff8;
      puVar11 = puVar9 + uVar12;
      lVar18 = (longlong)param_2 * 4 + uVar22;
      uVar19 = 0;
      do {
        uVar6 = *(undefined8 *)((longlong)(puVar9 + uVar19) + 8);
        uVar7 = *(undefined8 *)(puVar9 + uVar19 + 4);
        uVar8 = *(undefined8 *)((longlong)(puVar9 + uVar19 + 4) + 8);
        puVar2 = (undefined8 *)(lVar18 + uVar19 * 4);
        *puVar2 = *(undefined8 *)(puVar9 + uVar19);
        puVar2[1] = uVar6;
        puVar2 = (undefined8 *)(lVar18 + 0x10 + uVar19 * 4);
        *puVar2 = uVar7;
        puVar2[1] = uVar8;
        uVar19 = uVar19 + 8;
      } while (uVar12 != uVar19);
      if (uVar16 == uVar12) goto LAB_140015421;
    }
    puVar10 = (undefined4 *)(uVar22 + (longlong)param_2 * 4 + uVar12 * 4);
    do {
      uVar3 = *puVar11;
      puVar11 = puVar11 + 1;
      *puVar10 = uVar3;
      puVar10 = puVar10 + 1;
    } while (puVar11 != puVar9 + uVar14);
  }
LAB_140015421:
  puVar11 = puVar13;
  if (uVar4 != 0) {
    if (uVar4 == 0x1c) {
      _RNvNtCsjsHfHFRyfyy_10gdi_region3ffi22ScanLookAsideList_Free();
    }
    else {
      _RNvNtCsiNQa5DCRmUC_9gdi_alloc3ffi13Win32FreePool();
    }
  }
LAB_14001543b:
  if ((local_48 ^ (ulonglong)auStack_a8) == __security_cookie) {
    return puVar11;
  }
  pcVar5 = (code *)swi(3);
  puVar11 = (undefined4 *)(*pcVar5)();
  return puVar11;
}



===== _RNvXCsgf1RBdmyjwT_12fallible_vecINtNtCsip5f2bf5HGI_5alloc3vec3VecRNtNtCs2JCLxFJL4Mh_15onecore_windows6windef6__RECTLEINtB2_11FallibleVecB11_NtNtBz_5alloc6GlobalE8try_pushCscIyU0BP6seX_7rgncore @ 140015620 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong _RNvXCsgf1RBdmyjwT_12fallible_vecINtNtCsip5f2bf5HGI_5alloc3vec3VecRNtNtCs2JCLxFJL4Mh_15onecore_windows6windef6__RECTLEINtB2_11FallibleVecB11_NtNtBz_5alloc6GlobalE8try_pushCscIyU0BP6seX_7rgncore
                    (ulonglong *param_1,undefined8 param_2)

{
  code *pcVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  undefined1 auStack_88 [40];
  int local_60 [2];
  ulonglong local_58;
  undefined8 local_50;
  ulonglong local_48;
  undefined8 local_40;
  longlong local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_88;
  uVar3 = param_1[2];
  if (*param_1 == uVar3) {
    uVar2 = uVar3 * 2;
    if (uVar3 * 2 < uVar3 + 1) {
      uVar2 = uVar3 + 1;
    }
    uVar4 = 4;
    if (4 < uVar2) {
      uVar4 = uVar2;
    }
    if (uVar4 * 8 < 0x7ffffffffffffff9 && uVar2 >> 0x3d == 0) {
      if (uVar3 == 0) {
        local_40 = 0;
      }
      else {
        local_48 = param_1[1];
        local_38 = uVar3 * 8;
        local_40 = 8;
      }
      _RINvNtCsip5f2bf5HGI_5alloc7raw_vec11finish_growNtNtB4_5alloc6GlobalECscIyU0BP6seX_7rgncore_llvm_13477870103536380358
                ((ulonglong *)local_60,&DAT_00000008,uVar4 * 8,&local_48);
      if (local_60[0] == 1) {
        uVar3 = local_30 ^ (ulonglong)auStack_88;
        param_2 = local_50;
        if (uVar3 == __security_cookie) {
          return local_58;
        }
        goto LAB_140015727;
      }
      param_1[1] = local_58;
      *param_1 = uVar4;
      goto LAB_140015690;
    }
    uVar2 = 0;
  }
  else {
    local_58 = param_1[1];
LAB_140015690:
    *(undefined8 *)(local_58 + uVar3 * 8) = param_2;
    param_1[2] = uVar3 + 1;
    uVar2 = 0x8000000000000001;
  }
  uVar3 = local_30 ^ (ulonglong)auStack_88;
  if (uVar3 == __security_cookie) {
    return uVar2;
  }
LAB_140015727:
  pcVar1 = (code *)swi(3);
  uVar3 = (*pcVar1)(uVar3,param_2);
  return uVar3;
}



===== _RNvXCsgf1RBdmyjwT_12fallible_vecINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEINtB2_11FallibleVeclB12_E21try_extend_from_sliceCscIyU0BP6seX_7rgncore @ 140015750 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong _RNvXCsgf1RBdmyjwT_12fallible_vecINtNtCsip5f2bf5HGI_5alloc3vec3VeclINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EEINtB2_11FallibleVeclB12_E21try_extend_from_sliceCscIyU0BP6seX_7rgncore
                    (ulonglong *param_1,undefined4 *param_2,ulonglong param_3)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  code *pcVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  longlong lVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  undefined4 *puVar11;
  ulonglong uVar12;
  undefined1 auStack_88 [32];
  ulonglong *local_68;
  int local_60 [2];
  ulonglong local_58;
  undefined4 *local_50;
  ulonglong local_48;
  undefined8 local_40;
  longlong local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_88;
  uVar7 = *param_1;
  uVar10 = param_1[2];
  if (uVar7 - uVar10 < param_3) {
    if (!CARRY8(uVar10,param_3)) {
      uVar9 = uVar7 * 2;
      if (uVar7 * 2 < uVar10 + param_3) {
        uVar9 = uVar10 + param_3;
      }
      uVar10 = 4;
      if (4 < uVar9) {
        uVar10 = uVar9;
      }
      if (uVar10 * 4 < 0x7ffffffffffffffd && uVar9 >> 0x3e == 0) {
        if (uVar7 == 0) {
          local_40 = 0;
        }
        else {
          local_48 = param_1[1];
          local_38 = uVar7 << 2;
          local_40 = 4;
        }
        local_68 = param_1 + 2;
        _RINvNtCsip5f2bf5HGI_5alloc7raw_vec11finish_growINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EECscIyU0BP6seX_7rgncore_llvm_13477870103536380358
                  ((ulonglong *)local_60,&DAT_00000004,uVar10 * 4,&local_48);
        if (local_60[0] == 1) {
          uVar7 = local_30 ^ (ulonglong)auStack_88;
          param_2 = local_50;
          if (uVar7 == __security_cookie) {
            return local_58;
          }
          goto LAB_1400157d9;
        }
        param_1[1] = local_58;
        *param_1 = uVar10;
        uVar10 = param_1[2];
        goto LAB_140015889;
      }
    }
    uVar7 = local_30 ^ (ulonglong)auStack_88;
    if (uVar7 == __security_cookie) {
      return 0;
    }
    goto LAB_1400157d9;
  }
  if (param_3 != 0) {
    local_58 = param_1[1];
LAB_140015889:
    uVar7 = param_3 - 1 & 0x3fffffffffffffff;
    if ((uVar7 < 0xb) || ((local_58 + uVar10 * 4) - (longlong)param_2 < 0x20)) {
      puVar11 = param_2;
    }
    else {
      uVar7 = uVar7 + 1;
      lVar8 = uVar10 * 4;
      uVar9 = uVar7 & 0x7ffffffffffffff8;
      puVar11 = param_2 + uVar9;
      uVar10 = uVar10 + uVar9;
      lVar8 = lVar8 + local_58;
      uVar12 = 0;
      do {
        uVar4 = *(undefined8 *)((longlong)(param_2 + uVar12) + 8);
        uVar5 = *(undefined8 *)(param_2 + uVar12 + 4);
        uVar6 = *(undefined8 *)((longlong)(param_2 + uVar12 + 4) + 8);
        puVar1 = (undefined8 *)(lVar8 + uVar12 * 4);
        *puVar1 = *(undefined8 *)(param_2 + uVar12);
        puVar1[1] = uVar4;
        puVar1 = (undefined8 *)(lVar8 + 0x10 + uVar12 * 4);
        *puVar1 = uVar5;
        puVar1[1] = uVar6;
        uVar12 = uVar12 + 8;
      } while (uVar9 != uVar12);
      if (uVar7 == uVar9) goto LAB_1400158d3;
    }
    param_2 = param_2 + param_3;
    do {
      uVar2 = *puVar11;
      puVar11 = puVar11 + 1;
      *(undefined4 *)(local_58 + uVar10 * 4) = uVar2;
      uVar10 = uVar10 + 1;
    } while (puVar11 != param_2);
  }
LAB_1400158d3:
  param_1[2] = uVar10;
  uVar7 = local_30 ^ (ulonglong)auStack_88;
  if (uVar7 == __security_cookie) {
    return 0x8000000000000001;
  }
LAB_1400157d9:
  pcVar3 = (code *)swi(3);
  uVar7 = (*pcVar3)(uVar7,param_2);
  return uVar7;
}



===== _RINvNtNtNtNtCsloaxXL3qbEI_4core5slice4sort6shared9smallsort18small_sort_networkRNtNtCs2JCLxFJL4Mh_15onecore_windows6windef6__RECTLNCINvMB8_SB1f_20sort_unstable_by_keylNCNvMs_CscIyU0BP6seX_7rgncoreNtB2M_10RegionCore16subtract_complex0E0EB2M_ @ 140015960 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void _RINvNtNtNtNtCsloaxXL3qbEI_4core5slice4sort6shared9smallsort18small_sort_networkRNtNtCs2JCLxFJL4Mh_15onecore_windows6windef6__RECTLNCINvMB8_SB1f_20sort_unstable_by_keylNCNvMs_CscIyU0BP6seX_7rgncoreNtB2M_10RegionCore16subtract_complex0E0EB2M_
               (longlong *param_1,ulonglong param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  code *pcVar5;
  longlong lVar6;
  longlong lVar7;
  longlong lVar8;
  longlong lVar9;
  ulonglong uVar10;
  longlong lVar11;
  longlong lVar12;
  longlong lVar13;
  longlong *plVar14;
  longlong *plVar15;
  longlong lVar16;
  longlong lVar17;
  longlong lVar18;
  longlong lVar19;
  longlong lVar20;
  longlong *plVar21;
  ulonglong uVar22;
  ulonglong uVar23;
  longlong *plVar24;
  longlong *plVar25;
  bool bVar26;
  undefined1 auStack_1a8 [40];
  longlong *local_180;
  ulonglong local_178;
  ulonglong local_170;
  longlong *local_168;
  ulonglong local_160;
  longlong local_158;
  ulonglong local_150;
  longlong local_148 [32];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_1a8;
  local_180 = param_1;
  if (param_2 < 2) {
LAB_140016298:
    if ((local_48 ^ (ulonglong)auStack_1a8) == __security_cookie) {
      return;
    }
    pcVar5 = (code *)swi(3);
    (*pcVar5)();
    return;
  }
  if (param_2 < 0x21) {
    local_170 = param_2 >> 1;
    uVar10 = local_170;
    if (param_2 < 0x12) {
      uVar10 = param_2;
    }
    local_168 = param_1 + local_170;
    local_150 = param_2 - local_170;
    plVar24 = param_1;
    do {
      if (uVar10 < 0xd) {
        uVar23 = 1;
        if (8 < uVar10) {
          lVar7 = plVar24[3];
          lVar17 = *plVar24;
          lVar18 = plVar24[1];
          lVar6 = lVar17;
          if (*(int *)(lVar7 + 4) < *(int *)(lVar17 + 4)) {
            lVar6 = lVar7;
            lVar7 = lVar17;
          }
          lVar17 = plVar24[7];
          lVar13 = lVar18;
          if (*(int *)(lVar17 + 4) < *(int *)(lVar18 + 4)) {
            lVar13 = lVar17;
            lVar17 = lVar18;
          }
          lVar18 = plVar24[5];
          lVar11 = plVar24[2];
          lVar8 = lVar11;
          if (*(int *)(lVar18 + 4) < *(int *)(lVar11 + 4)) {
            lVar8 = lVar18;
            lVar18 = lVar11;
          }
          lVar11 = plVar24[8];
          lVar9 = plVar24[4];
          lVar19 = lVar9;
          if (*(int *)(lVar11 + 4) < *(int *)(lVar9 + 4)) {
            lVar19 = lVar11;
            lVar11 = lVar9;
          }
          if (*(int *)(lVar17 + 4) < *(int *)(lVar6 + 4)) {
            lVar9 = lVar17;
            lVar17 = lVar6;
          }
          else {
            lVar9 = lVar6;
          }
          if (*(int *)(lVar19 + 4) < *(int *)(lVar8 + 4)) {
            lVar6 = lVar19;
            lVar19 = lVar8;
          }
          else {
            lVar6 = lVar8;
          }
          if (*(int *)(lVar11 + 4) < *(int *)(lVar7 + 4)) {
            lVar8 = lVar11;
            lVar11 = lVar7;
          }
          else {
            lVar8 = lVar7;
          }
          lVar7 = plVar24[6];
          lVar16 = lVar18;
          if (*(int *)(lVar7 + 4) < *(int *)(lVar18 + 4)) {
            lVar16 = lVar7;
            lVar7 = lVar18;
          }
          if (*(int *)(lVar6 + 4) < *(int *)(lVar9 + 4)) {
            lVar18 = lVar6;
            lVar6 = lVar9;
          }
          else {
            lVar18 = lVar9;
          }
          if (*(int *)(lVar8 + 4) < *(int *)(lVar13 + 4)) {
            lVar9 = lVar8;
            lVar8 = lVar13;
          }
          else {
            lVar9 = lVar13;
          }
          if (*(int *)(lVar16 + 4) < *(int *)(lVar19 + 4)) {
            lVar13 = lVar16;
            lVar16 = lVar19;
          }
          else {
            lVar13 = lVar19;
          }
          if (*(int *)(lVar11 + 4) < *(int *)(lVar17 + 4)) {
            lVar19 = lVar11;
            lVar11 = lVar17;
          }
          else {
            lVar19 = lVar17;
          }
          if (*(int *)(lVar13 + 4) < *(int *)(lVar9 + 4)) {
            lVar17 = lVar13;
            lVar13 = lVar9;
          }
          else {
            lVar17 = lVar9;
          }
          lVar9 = lVar8;
          if (*(int *)(lVar7 + 4) < *(int *)(lVar8 + 4)) {
            lVar9 = lVar7;
            lVar7 = lVar8;
          }
          if (*(int *)(lVar19 + 4) < *(int *)(lVar16 + 4)) {
            lVar8 = lVar19;
            lVar19 = lVar16;
          }
          else {
            lVar8 = lVar16;
          }
          if (*(int *)(lVar17 + 4) < *(int *)(lVar18 + 4)) {
            lVar16 = lVar17;
            lVar17 = lVar18;
          }
          else {
            lVar16 = lVar18;
          }
          *plVar24 = lVar16;
          if (*(int *)(lVar13 + 4) < *(int *)(lVar6 + 4)) {
            lVar18 = lVar13;
            lVar13 = lVar6;
          }
          else {
            lVar18 = lVar6;
          }
          if (*(int *)(lVar8 + 4) < *(int *)(lVar9 + 4)) {
            lVar6 = lVar8;
            lVar8 = lVar9;
          }
          else {
            lVar6 = lVar9;
          }
          lVar9 = lVar7;
          if (*(int *)(lVar11 + 4) < *(int *)(lVar7 + 4)) {
            lVar9 = lVar11;
            lVar11 = lVar7;
          }
          plVar24[8] = lVar11;
          if (*(int *)(lVar6 + 4) < *(int *)(lVar18 + 4)) {
            lVar7 = lVar6;
            lVar6 = lVar18;
          }
          else {
            lVar7 = lVar18;
          }
          if (*(int *)(lVar8 + 4) < *(int *)(lVar13 + 4)) {
            lVar18 = lVar8;
            lVar8 = lVar13;
          }
          else {
            lVar18 = lVar13;
          }
          lVar13 = lVar9;
          if (*(int *)(lVar19 + 4) < *(int *)(lVar9 + 4)) {
            lVar13 = lVar19;
            lVar19 = lVar9;
          }
          plVar24[7] = lVar19;
          if (*(int *)(lVar7 + 4) < *(int *)(lVar17 + 4)) {
            lVar11 = lVar7;
            lVar7 = lVar17;
          }
          else {
            lVar11 = lVar17;
          }
          plVar24[1] = lVar11;
          plVar24[2] = lVar7;
          if (*(int *)(lVar18 + 4) < *(int *)(lVar6 + 4)) {
            lVar7 = lVar18;
            lVar18 = lVar6;
          }
          else {
            lVar7 = lVar6;
          }
          plVar24[3] = lVar7;
          plVar24[4] = lVar18;
          if (*(int *)(lVar13 + 4) < *(int *)(lVar8 + 4)) {
            lVar7 = lVar13;
            lVar13 = lVar8;
          }
          else {
            lVar7 = lVar8;
          }
          plVar24[5] = lVar7;
          plVar24[6] = lVar13;
          uVar23 = 9;
          local_178 = uVar10;
        }
      }
      else {
        lVar7 = plVar24[0xc];
        lVar17 = *plVar24;
        lVar18 = lVar17;
        if (*(int *)(lVar7 + 4) < *(int *)(lVar17 + 4)) {
          lVar18 = lVar7;
          lVar7 = lVar17;
        }
        lVar17 = plVar24[1];
        *plVar24 = lVar18;
        plVar24[0xc] = lVar7;
        lVar18 = plVar24[10];
        lVar6 = lVar17;
        if (*(int *)(lVar18 + 4) < *(int *)(lVar17 + 4)) {
          lVar6 = lVar18;
          lVar18 = lVar17;
        }
        plVar24[1] = lVar6;
        plVar24[10] = lVar18;
        lVar17 = plVar24[9];
        lVar13 = plVar24[2];
        lVar11 = lVar13;
        if (*(int *)(lVar17 + 4) < *(int *)(lVar13 + 4)) {
          lVar11 = lVar17;
          lVar17 = lVar13;
        }
        plVar24[2] = lVar11;
        plVar24[9] = lVar17;
        lVar13 = plVar24[3];
        lVar8 = plVar24[7];
        lVar9 = lVar13;
        if (*(int *)(lVar8 + 4) < *(int *)(lVar13 + 4)) {
          lVar9 = lVar8;
          lVar8 = lVar13;
        }
        plVar24[3] = lVar9;
        plVar24[7] = lVar8;
        lVar13 = plVar24[5];
        lVar19 = plVar24[0xb];
        lVar16 = lVar13;
        if (*(int *)(lVar19 + 4) < *(int *)(lVar13 + 4)) {
          lVar16 = lVar19;
          lVar19 = lVar13;
        }
        plVar24[5] = lVar16;
        plVar24[0xb] = lVar19;
        lVar13 = plVar24[6];
        lVar16 = plVar24[8];
        lVar20 = lVar13;
        if (*(int *)(lVar16 + 4) < *(int *)(lVar13 + 4)) {
          lVar20 = lVar16;
          lVar16 = lVar13;
        }
        plVar24[6] = lVar20;
        plVar24[8] = lVar16;
        if (*(int *)(lVar20 + 4) < *(int *)(lVar6 + 4)) {
          lVar13 = lVar20;
          lVar20 = lVar6;
        }
        else {
          lVar13 = lVar6;
        }
        plVar24[1] = lVar13;
        plVar24[6] = lVar20;
        if (*(int *)(lVar9 + 4) < *(int *)(lVar11 + 4)) {
          local_158 = lVar9;
          lVar9 = lVar11;
        }
        else {
          local_158 = lVar11;
        }
        plVar24[2] = local_158;
        plVar24[3] = lVar9;
        lVar6 = plVar24[4];
        if (*(int *)(lVar19 + 4) < *(int *)(lVar6 + 4)) {
          lVar11 = lVar19;
          lVar19 = lVar6;
        }
        else {
          lVar11 = lVar6;
        }
        plVar24[4] = lVar11;
        plVar24[0xb] = lVar19;
        lVar6 = lVar8;
        if (*(int *)(lVar17 + 4) < *(int *)(lVar8 + 4)) {
          lVar6 = lVar17;
          lVar17 = lVar8;
        }
        plVar24[7] = lVar6;
        plVar24[9] = lVar17;
        lVar8 = lVar16;
        if (*(int *)(lVar18 + 4) < *(int *)(lVar16 + 4)) {
          lVar8 = lVar18;
          lVar18 = lVar16;
        }
        plVar24[8] = lVar8;
        plVar24[10] = lVar18;
        lVar16 = *plVar24;
        if (*(int *)(lVar11 + 4) < *(int *)(lVar16 + 4)) {
          lVar12 = lVar11;
          lVar11 = lVar16;
        }
        else {
          lVar12 = lVar16;
        }
        *plVar24 = lVar12;
        plVar24[4] = lVar11;
        if (*(int *)(local_158 + 4) < *(int *)(lVar13 + 4)) {
          lVar16 = local_158;
          local_158 = lVar13;
        }
        else {
          lVar16 = lVar13;
        }
        plVar24[1] = lVar16;
        plVar24[2] = local_158;
        lVar13 = lVar9;
        if (*(int *)(lVar20 + 4) < *(int *)(lVar9 + 4)) {
          lVar13 = lVar20;
          lVar20 = lVar9;
        }
        plVar24[3] = lVar13;
        plVar24[6] = lVar20;
        if (*(int *)(lVar8 + 4) < *(int *)(lVar6 + 4)) {
          lVar9 = lVar8;
          lVar8 = lVar6;
        }
        else {
          lVar9 = lVar6;
        }
        plVar24[7] = lVar9;
        plVar24[8] = lVar8;
        if (*(int *)(lVar18 + 4) < *(int *)(lVar17 + 4)) {
          lVar6 = lVar18;
          lVar18 = lVar17;
        }
        else {
          lVar6 = lVar17;
        }
        plVar24[9] = lVar6;
        plVar24[10] = lVar18;
        lVar17 = lVar19;
        if (*(int *)(lVar7 + 4) < *(int *)(lVar19 + 4)) {
          lVar17 = lVar7;
          lVar7 = lVar19;
        }
        plVar24[0xb] = lVar17;
        plVar24[0xc] = lVar7;
        if (*(int *)(lVar20 + 4) < *(int *)(lVar11 + 4)) {
          lVar19 = lVar20;
          lVar20 = lVar11;
        }
        else {
          lVar19 = lVar11;
        }
        plVar24[4] = lVar19;
        plVar24[6] = lVar20;
        lVar11 = plVar24[5];
        if (*(int *)(lVar6 + 4) < *(int *)(lVar11 + 4)) {
          lVar16 = lVar6;
          lVar6 = lVar11;
        }
        else {
          lVar16 = lVar11;
        }
        plVar24[5] = lVar16;
        plVar24[9] = lVar6;
        if (*(int *)(lVar17 + 4) < *(int *)(lVar8 + 4)) {
          lVar11 = lVar17;
          lVar17 = lVar8;
        }
        else {
          lVar11 = lVar8;
        }
        plVar24[8] = lVar11;
        plVar24[0xb] = lVar17;
        if (*(int *)(lVar7 + 4) < *(int *)(lVar18 + 4)) {
          lVar8 = lVar7;
          lVar7 = lVar18;
        }
        else {
          lVar8 = lVar18;
        }
        plVar24[10] = lVar8;
        plVar24[0xc] = lVar7;
        if (*(int *)(lVar16 + 4) < *(int *)(lVar12 + 4)) {
          lVar7 = lVar16;
          lVar16 = lVar12;
        }
        else {
          lVar7 = lVar12;
        }
        *plVar24 = lVar7;
        plVar24[5] = lVar16;
        if (*(int *)(lVar11 + 4) < *(int *)(lVar13 + 4)) {
          lVar18 = lVar11;
          lVar11 = lVar13;
        }
        else {
          lVar18 = lVar13;
        }
        plVar24[3] = lVar18;
        plVar24[8] = lVar11;
        lVar13 = lVar19;
        if (*(int *)(lVar9 + 4) < *(int *)(lVar19 + 4)) {
          lVar13 = lVar9;
          lVar9 = lVar19;
        }
        plVar24[4] = lVar13;
        plVar24[7] = lVar9;
        if (*(int *)(lVar17 + 4) < *(int *)(lVar20 + 4)) {
          lVar19 = lVar17;
          lVar17 = lVar20;
        }
        else {
          lVar19 = lVar20;
        }
        plVar24[6] = lVar19;
        plVar24[0xb] = lVar17;
        if (*(int *)(lVar8 + 4) < *(int *)(lVar6 + 4)) {
          lVar20 = lVar8;
          lVar8 = lVar6;
        }
        else {
          lVar20 = lVar6;
        }
        plVar24[9] = lVar20;
        plVar24[10] = lVar8;
        lVar6 = plVar24[1];
        lVar12 = lVar7;
        if (*(int *)(lVar6 + 4) < *(int *)(lVar7 + 4)) {
          lVar12 = lVar6;
          lVar6 = lVar7;
        }
        *plVar24 = lVar12;
        plVar24[1] = lVar6;
        if (*(int *)(lVar16 + 4) < *(int *)(local_158 + 4)) {
          lVar7 = lVar16;
          lVar16 = local_158;
        }
        else {
          lVar7 = local_158;
        }
        plVar24[2] = lVar7;
        plVar24[5] = lVar16;
        if (*(int *)(lVar20 + 4) < *(int *)(lVar19 + 4)) {
          lVar12 = lVar20;
          lVar20 = lVar19;
        }
        else {
          lVar12 = lVar19;
        }
        plVar24[6] = lVar12;
        plVar24[9] = lVar20;
        lVar19 = lVar9;
        if (*(int *)(lVar11 + 4) < *(int *)(lVar9 + 4)) {
          lVar19 = lVar11;
          lVar11 = lVar9;
        }
        plVar24[7] = lVar19;
        plVar24[8] = lVar11;
        lVar9 = lVar8;
        if (*(int *)(lVar17 + 4) < *(int *)(lVar8 + 4)) {
          lVar9 = lVar17;
          lVar17 = lVar8;
        }
        plVar24[10] = lVar9;
        plVar24[0xb] = lVar17;
        lVar17 = lVar6;
        if (*(int *)(lVar18 + 4) < *(int *)(lVar6 + 4)) {
          lVar17 = lVar18;
          lVar18 = lVar6;
        }
        plVar24[1] = lVar17;
        plVar24[3] = lVar18;
        lVar6 = lVar7;
        if (*(int *)(lVar13 + 4) < *(int *)(lVar7 + 4)) {
          lVar6 = lVar13;
          lVar13 = lVar7;
        }
        plVar24[2] = lVar6;
        plVar24[4] = lVar13;
        if (*(int *)(lVar12 + 4) < *(int *)(lVar16 + 4)) {
          lVar7 = lVar12;
          lVar12 = lVar16;
        }
        else {
          lVar7 = lVar16;
        }
        plVar24[5] = lVar7;
        plVar24[6] = lVar12;
        if (*(int *)(lVar9 + 4) < *(int *)(lVar20 + 4)) {
          lVar8 = lVar9;
          lVar9 = lVar20;
        }
        else {
          lVar8 = lVar20;
        }
        plVar24[9] = lVar8;
        plVar24[10] = lVar9;
        if (*(int *)(lVar6 + 4) < *(int *)(lVar17 + 4)) {
          lVar9 = lVar6;
          lVar6 = lVar17;
        }
        else {
          lVar9 = lVar17;
        }
        plVar24[1] = lVar9;
        plVar24[2] = lVar6;
        if (*(int *)(lVar13 + 4) < *(int *)(lVar18 + 4)) {
          lVar17 = lVar13;
          lVar13 = lVar18;
        }
        else {
          lVar17 = lVar18;
        }
        plVar24[3] = lVar17;
        plVar24[4] = lVar13;
        lVar18 = lVar7;
        if (*(int *)(lVar19 + 4) < *(int *)(lVar7 + 4)) {
          lVar18 = lVar19;
          lVar19 = lVar7;
        }
        plVar24[5] = lVar18;
        plVar24[7] = lVar19;
        lVar7 = lVar12;
        if (*(int *)(lVar11 + 4) < *(int *)(lVar12 + 4)) {
          lVar7 = lVar11;
          lVar11 = lVar12;
        }
        plVar24[6] = lVar7;
        plVar24[8] = lVar11;
        if (*(int *)(lVar17 + 4) < *(int *)(lVar6 + 4)) {
          lVar9 = lVar17;
          lVar17 = lVar6;
        }
        else {
          lVar9 = lVar6;
        }
        plVar24[2] = lVar9;
        plVar24[3] = lVar17;
        if (*(int *)(lVar18 + 4) < *(int *)(lVar13 + 4)) {
          lVar6 = lVar18;
          lVar18 = lVar13;
        }
        else {
          lVar6 = lVar13;
        }
        plVar24[4] = lVar6;
        plVar24[5] = lVar18;
        lVar13 = lVar7;
        if (*(int *)(lVar19 + 4) < *(int *)(lVar7 + 4)) {
          lVar13 = lVar19;
          lVar19 = lVar7;
        }
        plVar24[6] = lVar13;
        plVar24[7] = lVar19;
        lVar7 = lVar11;
        if (*(int *)(lVar8 + 4) < *(int *)(lVar11 + 4)) {
          lVar7 = lVar8;
          lVar8 = lVar11;
        }
        plVar24[8] = lVar7;
        plVar24[9] = lVar8;
        if (*(int *)(lVar6 + 4) < *(int *)(lVar17 + 4)) {
          lVar7 = lVar6;
          lVar6 = lVar17;
        }
        else {
          lVar7 = lVar17;
        }
        plVar24[3] = lVar7;
        plVar24[4] = lVar6;
        if (*(int *)(lVar13 + 4) < *(int *)(lVar18 + 4)) {
          lVar7 = lVar13;
          lVar13 = lVar18;
        }
        else {
          lVar7 = lVar18;
        }
        plVar24[5] = lVar7;
        plVar24[6] = lVar13;
        uVar23 = 0xd;
        local_178 = uVar10;
      }
      local_160 = param_2;
      if (uVar10 <= uVar23 - 1) goto LAB_1400162cb;
      if (uVar23 != uVar10) {
        uVar23 = (ulonglong)(uint)((int)uVar23 << 3);
        plVar14 = (longlong *)((longlong)plVar24 + uVar23);
        do {
          lVar7 = plVar14[-1];
          lVar17 = *plVar14;
          if (*(int *)(lVar17 + 4) < *(int *)(lVar7 + 4)) {
            uVar22 = uVar23;
            do {
              *(longlong *)((longlong)plVar24 + uVar22) = lVar7;
              if (uVar22 == 8) {
                plVar21 = plVar24;
                goto LAB_140016173;
              }
              lVar7 = *(longlong *)((longlong)plVar24 + (uVar22 - 0x10));
              uVar22 = uVar22 - 8;
            } while (*(int *)(lVar17 + 4) < *(int *)(lVar7 + 4));
            plVar21 = (longlong *)(uVar22 + (longlong)plVar24);
LAB_140016173:
            *plVar21 = lVar17;
          }
          plVar14 = plVar14 + 1;
          uVar23 = uVar23 + 8;
        } while (plVar14 != plVar24 + uVar10);
      }
      if (param_2 < 0x12) goto LAB_140016298;
      bVar26 = plVar24 == param_1;
      uVar10 = local_150;
      plVar24 = local_168;
    } while (bVar26);
    plVar15 = param_1 + (param_2 - 1);
    plVar24 = local_168 + -1;
    uVar10 = 0;
    plVar21 = param_1;
    plVar14 = local_168;
    uVar23 = param_2;
    do {
      uVar23 = uVar23 - 1;
      iVar3 = *(int *)(*plVar14 + 4);
      iVar1 = *(int *)(*plVar21 + 4);
      lVar7 = *plVar21;
      if (iVar3 < iVar1) {
        lVar7 = *plVar14;
      }
      local_148[uVar10] = lVar7;
      uVar10 = uVar10 + 1;
      plVar14 = plVar14 + (iVar3 < iVar1);
      iVar4 = *(int *)(*plVar15 + 4);
      iVar2 = *(int *)(*plVar24 + 4);
      plVar21 = plVar21 + (iVar1 <= iVar3);
      lVar7 = *plVar15;
      if (iVar4 < iVar2) {
        lVar7 = *plVar24;
      }
      local_148[uVar23] = lVar7;
      plVar15 = plVar15 + -(ulonglong)(iVar2 <= iVar4);
      plVar24 = plVar24 + -(ulonglong)(iVar4 < iVar2);
    } while (local_170 != uVar10);
    if ((param_2 & 1) != 0) {
      bVar26 = plVar21 < plVar24 + 1;
      plVar25 = plVar14;
      if (bVar26) {
        plVar25 = plVar21;
      }
      local_148[uVar10] = *plVar25;
      plVar21 = plVar21 + bVar26;
      plVar14 = plVar14 + !bVar26;
    }
    if ((plVar21 == plVar24 + 1) && (plVar14 == plVar15 + 1)) {
      _weak_memcpy_default___llvm_retpoline_r11(param_1,local_148,param_2 << 3);
      goto LAB_140016298;
    }
    _RNvNtNtNtNtCsloaxXL3qbEI_4core5slice4sort6shared9smallsort22panic_on_ord_violation();
  }
LAB_1400162cb:
                    /* WARNING: Does not return */
  pcVar5 = (code *)invalidInstructionException();
  (*pcVar5)();
}



===== _RINvNtNtNtNtCsloaxXL3qbEI_4core5slice4sort6shared9smallsort25insertion_sort_shift_leftRNtNtCs2JCLxFJL4Mh_15onecore_windows6windef6__RECTLNCINvMB8_SB1m_20sort_unstable_by_keylNCNvMs_CscIyU0BP6seX_7rgncoreNtB2T_10RegionCore16subtract_complex0E0EB2T_ @ 1400162e0 =====

void _RINvNtNtNtNtCsloaxXL3qbEI_4core5slice4sort6shared9smallsort25insertion_sort_shift_leftRNtNtCs2JCLxFJL4Mh_15onecore_windows6windef6__RECTLNCINvMB8_SB1m_20sort_unstable_by_keylNCNvMs_CscIyU0BP6seX_7rgncoreNtB2T_10RegionCore16subtract_complex0E0EB2T_
               (longlong *param_1,ulonglong param_2,ulonglong param_3)

{
  longlong lVar1;
  code *pcVar2;
  longlong *plVar3;
  longlong lVar4;
  longlong *plVar5;
  longlong lVar6;
  longlong lVar7;
  
  if (param_2 <= param_3 - 1) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)invalidInstructionException();
    (*pcVar2)();
  }
  if (param_3 != param_2) {
    plVar3 = param_1 + param_3;
    lVar4 = param_3 << 3;
    do {
      lVar7 = plVar3[-1];
      lVar1 = *plVar3;
      if (*(int *)(lVar1 + 4) < *(int *)(lVar7 + 4)) {
        lVar6 = lVar4;
        do {
          *(longlong *)((longlong)param_1 + lVar6) = lVar7;
          if (lVar6 == 8) {
            plVar5 = param_1;
            goto LAB_140016303;
          }
          lVar7 = *(longlong *)((longlong)param_1 + lVar6 + -0x10);
          lVar6 = lVar6 + -8;
        } while (*(int *)(lVar1 + 4) < *(int *)(lVar7 + 4));
        plVar5 = (longlong *)(lVar6 + (longlong)param_1);
LAB_140016303:
        *plVar5 = lVar1;
      }
      plVar3 = plVar3 + 1;
      lVar4 = lVar4 + 8;
    } while (plVar3 != param_1 + param_2);
  }
  return;
}



===== _RINvNtNtNtNtCsloaxXL3qbEI_4core5slice4sort8unstable8heapsort8heapsortRNtNtCs2JCLxFJL4Mh_15onecore_windows6windef6__RECTLNCINvMB8_SB15_20sort_unstable_by_keylNCNvMs_CscIyU0BP6seX_7rgncoreNtB2C_10RegionCore16subtract_complex0E0EB2C_ @ 140016360 =====

void _RINvNtNtNtNtCsloaxXL3qbEI_4core5slice4sort8unstable8heapsort8heapsortRNtNtCs2JCLxFJL4Mh_15onecore_windows6windef6__RECTLNCINvMB8_SB15_20sort_unstable_by_keylNCNvMs_CscIyU0BP6seX_7rgncoreNtB2C_10RegionCore16subtract_complex0E0EB2C_
               (undefined8 *param_1,ulonglong param_2)

{
  undefined8 uVar1;
  longlong lVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  
  uVar3 = (param_2 >> 1) + param_2;
  do {
    do {
      if (uVar3 == 0) {
        return;
      }
      uVar3 = uVar3 - 1;
      uVar4 = uVar3 - param_2;
      if (uVar3 < param_2) {
        uVar1 = *param_1;
        *param_1 = param_1[uVar3];
        param_1[uVar3] = uVar1;
        uVar4 = 0;
      }
      uVar5 = uVar3;
      if (param_2 < uVar3) {
        uVar5 = param_2;
      }
      uVar6 = uVar4 * 2 + 1;
    } while (uVar5 <= uVar6);
    do {
      if (uVar4 * 2 + 2 < uVar5) {
        uVar7 = (*(int *)(param_1[uVar6] + 4) < *(int *)(param_1[uVar4 * 2 + 2] + 4)) + uVar6;
      }
      else {
        uVar7 = uVar6;
      }
      lVar2 = param_1[uVar4];
      if (*(int *)(param_1[uVar7] + 4) <= *(int *)(lVar2 + 4)) break;
      param_1[uVar4] = param_1[uVar7];
      param_1[uVar7] = lVar2;
      uVar6 = uVar7 * 2 + 1;
      uVar4 = uVar7;
    } while (uVar6 < uVar5);
  } while( true );
}



===== _RNvXs19_NtCsloaxXL3qbEI_4core3fmtRNtNtCsip5f2bf5HGI_5alloc11collections19TryReserveErrorKindNtB6_5Debug3fmtCscIyU0BP6seX_7rgncore @ 140016420 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong _RNvXs19_NtCsloaxXL3qbEI_4core3fmtRNtNtCsip5f2bf5HGI_5alloc11collections19TryReserveErrorKindNtB6_5Debug3fmtCscIyU0BP6seX_7rgncore
                    (undefined8 *param_1,longlong param_2)

{
  code *pcVar1;
  ulonglong uVar2;
  undefined1 auStackY_78 [32];
  
  if (*(longlong *)*param_1 != 0) {
    uVar2 = _RNvMs9_NtCsloaxXL3qbEI_4core3fmtNtB5_9Formatter26debug_struct_field2_finish
                      (param_2,
                       "AllocErrorlayoutnon_exhaustive()) should be < len (is )removal index (is ",
                       10,0x14001b170,6,(longlong *)*param_1,&DAT_14001a320,0x14001b176,0xe);
    return uVar2 & 0xffffffff;
  }
  if ((__security_cookie ^ (ulonglong)auStackY_78 ^ (ulonglong)auStackY_78) == __security_cookie) {
    uVar2 = _RNvXsa_NtCsloaxXL3qbEI_4core3fmtNtB5_9FormatterNtB5_5Write9write_str();
    return uVar2;
  }
  pcVar1 = (code *)swi(3);
  uVar2 = (*pcVar1)();
  return uVar2;
}



===== _RNvXs19_NtCsloaxXL3qbEI_4core3fmtRuNtB6_5Debug3fmtCscIyU0BP6seX_7rgncore @ 140016500 =====

void _RNvXs19_NtCsloaxXL3qbEI_4core3fmtRuNtB6_5Debug3fmtCscIyU0BP6seX_7rgncore
               (undefined8 param_1,longlong param_2)

{
  _RNvMs9_NtCsloaxXL3qbEI_4core3fmtNtB5_9Formatter3pad(param_2,(byte *)0x14001b184,2);
  return;
}



===== fmt @ 140016520 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void core::alloc::layout::impl$5::fmt(longlong param_1,longlong param_2)

{
  code *pcVar1;
  ulonglong uVar2;
  undefined1 auStackY_68 [32];
  
  uVar2 = __security_cookie ^ (ulonglong)auStackY_68;
  _RNvMs9_NtCsloaxXL3qbEI_4core3fmtNtB5_9Formatter26debug_struct_field2_finish
            (param_2,
             "LayoutsizealignCapacityOverflowAllocErrorlayoutnon_exhaustive()) should be < len (is )removal index (is "
             ,6,0x14001b14d,4,param_1 + 8,&DAT_14001a2e0,0x14001b151,5);
  if ((uVar2 ^ (ulonglong)auStackY_68) == __security_cookie) {
    return;
  }
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== _RNCNvNtNtCsgPWNLo2c3FO_17compiler_builtins3mem5impls13compare_bytess1_0B7_.llvm.5483110067693423320 @ 1400165d0 =====

int _RNCNvNtNtCsgPWNLo2c3FO_17compiler_builtins3mem5impls13compare_bytess1_0B7__llvm_5483110067693423320
              (undefined8 param_1,ulonglong *param_2,ulonglong *param_3,ulonglong param_4)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  ulonglong *puVar7;
  uint uVar8;
  uint uVar9;
  ulonglong *puVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  
  uVar4 = (uint)param_4;
  if (param_4 < 8) {
    puVar7 = param_2;
    puVar10 = param_3;
  }
  else {
    uVar5 = *param_2;
    uVar11 = *param_3;
    if (uVar5 != uVar11) {
LAB_1400166c3:
      if ((int)uVar5 == (int)uVar11) {
        uVar11 = uVar11 >> 0x20;
        uVar5 = uVar5 >> 0x20;
        if (uVar5 == uVar11) {
          return 0;
        }
      }
      if ((short)uVar5 == (short)uVar11) {
        uVar11 = uVar11 >> 0x10 & 0xffff;
        uVar5 = uVar5 >> 0x10 & 0xffff;
        if ((int)uVar5 == (int)uVar11) {
          return 0;
        }
      }
      if ((char)uVar5 == (char)uVar11) {
        uVar12 = uVar11 & 0xffff;
        uVar11 = uVar12 >> 8;
        uVar6 = uVar5 & 0xffff;
        uVar5 = uVar6 >> 8;
        if ((short)(uVar6 >> 8) == (short)(uVar12 >> 8)) {
          return 0;
        }
      }
      uVar3 = (uint)(byte)uVar5;
      uVar8 = (uint)(byte)uVar11;
      goto LAB_140016710;
    }
    puVar7 = (ulonglong *)((longlong)param_2 + (ulonglong)(uVar4 & 0x18));
    puVar10 = param_3 + 1;
    if ((uVar4 & 0x18) != 8) {
      uVar5 = param_2[1];
      uVar11 = *puVar10;
      if (uVar5 != uVar11) goto LAB_1400166c3;
      puVar10 = param_3 + 2;
    }
  }
  if ((uVar4 & 7) < 4) {
LAB_1400165fa:
    if ((uVar4 & 3) < 2) {
LAB_14001661e:
      if ((param_4 & 1) == 0) {
        return 0;
      }
      if ((byte)*puVar7 == (byte)*puVar10) {
        return 0;
      }
      return (uint)(byte)*puVar7 - (uint)(byte)*puVar10;
    }
    uVar1 = (ushort)*puVar7;
    uVar3 = (uint)uVar1;
    uVar2 = (ushort)*puVar10;
    uVar8 = (uint)uVar2;
    if (uVar1 == uVar2) {
      puVar7 = (ulonglong *)((longlong)puVar7 + (ulonglong)(uVar4 & 2));
      puVar10 = (ulonglong *)((longlong)puVar10 + 2);
      goto LAB_14001661e;
    }
    if ((char)*puVar7 == (char)*puVar10) {
      uVar8 = (uint)(uVar2 >> 8);
      uVar3 = (uint)(uVar1 >> 8);
      if (uVar1 >> 8 == uVar2 >> 8) {
        return 0;
      }
    }
  }
  else {
    uVar3 = (uint)*puVar7;
    uVar8 = (uint)*puVar10;
    if (uVar3 == uVar8) {
      puVar7 = (ulonglong *)((longlong)puVar7 + (ulonglong)(uVar4 & 4));
      puVar10 = (ulonglong *)((longlong)puVar10 + 4);
      goto LAB_1400165fa;
    }
    if ((short)*puVar7 == (short)*puVar10) {
      uVar8 = uVar8 >> 0x10;
      uVar3 = uVar3 >> 0x10;
      if (uVar3 == uVar8) {
        return 0;
      }
    }
    if ((char)uVar3 == (char)uVar8) {
      uVar9 = uVar8 & 0xffff;
      uVar8 = uVar9 >> 8;
      uVar4 = uVar3 & 0xffff;
      uVar3 = uVar4 >> 8;
      if ((short)(uVar4 >> 8) == (short)(uVar9 >> 8)) {
        return 0;
      }
    }
  }
  uVar3 = uVar3 & 0xff;
  uVar8 = uVar8 & 0xff;
LAB_140016710:
  return uVar3 - uVar8;
}



===== _RINvMs_NtCsip5f2bf5HGI_5alloc3vecINtB5_3VecNtNtNtCsdyToaWEq7tk_8gdi_rust6region9from_path4EdgeINtCsiNQa5DCRmUC_9gdi_alloc15TaggedAllocatorKm67646547_EE10retain_mutNCINvB2_6retainNCNvMs_BH_NtBH_15ActiveEdgeTable7advance0E0EBL_ @ 140016720 =====

void _RINvMs_NtCsip5f2bf5HGI_5alloc3vecINtB5_3VecNtNtNtCsdyToaWEq7tk_8gdi_rust6region9from_path4EdgeINtCsiNQa5DCRmUC_9gdi_alloc15TaggedAllocatorKm67646547_EE10retain_mutNCINvB2_6retainNCNvMs_BH_NtBH_15ActiveEdgeTable7advance0E0EBL_
               (longlong param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 *puVar7;
  longlong lVar8;
  longlong lVar9;
  undefined8 *puVar10;
  
  lVar1 = *(longlong *)(param_1 + 0x10);
  if (lVar1 != 0) {
    lVar9 = 1 - lVar1;
    lVar8 = 0;
    puVar10 = *(undefined8 **)(param_1 + 8);
    do {
      puVar7 = puVar10 + 6;
      if (*(int *)(puVar10 + 3) < 1) {
        if (lVar9 == 0) {
          lVar8 = 1;
        }
        else {
          lVar9 = -lVar9;
          lVar8 = 1;
          do {
            if (*(int *)(puVar7 + 3) < 1) {
              lVar8 = lVar8 + 1;
            }
            else {
              puVar10 = puVar7 + lVar8 * -6;
              uVar2 = *puVar7;
              uVar3 = puVar7[1];
              uVar4 = puVar7[2];
              uVar5 = puVar7[3];
              uVar6 = puVar7[5];
              puVar7[lVar8 * -6 + 4] = puVar7[4];
              (puVar7 + lVar8 * -6 + 4)[1] = uVar6;
              puVar10[2] = uVar4;
              puVar10[3] = uVar5;
              *puVar10 = uVar2;
              puVar10[1] = uVar3;
            }
            lVar9 = lVar9 + -1;
            puVar7 = puVar7 + 6;
          } while (lVar9 != 0);
        }
        break;
      }
      lVar9 = lVar9 + 1;
      puVar10 = puVar7;
    } while (lVar9 != 1);
    *(longlong *)(param_1 + 0x10) = lVar1 - lVar8;
  }
  return;
}



===== wil_details_RecordCachedUsage @ 1400167e4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_RecordCachedUsage(undefined4 param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  bool bVar6;
  undefined1 auStack_68 [32];
  undefined4 local_48;
  ushort local_44 [2];
  undefined4 local_40 [10];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  uVar2 = *param_2;
  do {
    LOCK();
    uVar4 = *param_2;
    bVar6 = uVar2 == uVar4;
    if (bVar6) {
      *param_2 = uVar2 & 0xffc0401e;
    }
    else {
      uVar2 = uVar4;
    }
    UNLOCK();
  } while (!bVar6);
  uVar3 = uVar2 >> 1 & 0xf;
  uVar4 = 0;
  if (uVar3 != 0) {
    uVar4 = param_2[1];
    do {
      LOCK();
      uVar1 = param_2[1];
      bVar6 = uVar4 == uVar1;
      if (bVar6) {
        param_2[1] = uVar4 | uVar3;
      }
      else {
        uVar4 = uVar1;
      }
      UNLOCK();
    } while (!bVar6);
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
    *(ushort *)(puVar5 + 1) = ((ushort)(uVar2 >> 0x16) & 1) << 2 | 1;
    puVar5 = puVar5 + 2;
  }
  if (0 < (longlong)puVar5 - (longlong)&local_48 >> 3) {
    wil_details_RecordFeatureUsageCallback();
  }
  return;
}



===== wil_details_RecordFeatureUsageReporting @ 140016930 =====

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



===== DriverUnload @ 1400169c0 =====

/* void __cdecl DriverUnload(struct _DRIVER_OBJECT * __ptr64) */

void __cdecl DriverUnload(_DRIVER_OBJECT *param_1)

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



===== PsGetCurrentThread @ 140016a18 =====

void * PsGetCurrentThread(void)

{
  return SystemReserved1[0xf];
}



===== CallInTryExcept @ 140016a2c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 CallInTryExcept(undefined *param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  uVar1 = (*(code *)param_1)(param_2);
  return CONCAT71((int7)((ulonglong)uVar1 >> 8),1);
}



===== InitImageInformation @ 140016a60 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* unsigned long __cdecl InitImageInformation(union _RTL_RUN_ONCE * __ptr64,void * __ptr64,void *
   __ptr64 * __ptr64) */

ulong __cdecl InitImageInformation(_RTL_RUN_ONCE *param_1,void *param_2,void **param_3)

{
  longlong lVar1;
  
  _DAT_14001c068 = &IMAGE_DOS_HEADER_140000000;
  lVar1 = RtlImageNtHeader();
  _DAT_14001c078 = _DAT_14001c068->e_magic + *(uint *)(lVar1 + 0x28);
  _DAT_14001c080 = *(undefined4 *)(lVar1 + 0x50);
  return 1;
}



===== __PatchMainCallout__ @ 140016ab0 =====

void __PatchMainCallout__(longlong param_1)

{
  int iVar1;
  
                    /* 0x16ab0  79  __PatchMainCallout__ */
  iVar1 = RtlRunOnceExecuteOnce(&g_ImageInfoRunOnce,InitImageInformation,0,0);
  if (-1 < iVar1) {
    Win32kBaseRustPatchCalloutHandler(&g_ImageInfo,*(undefined4 *)(param_1 + 4));
  }
  return;
}



===== cxxbridge1$ScanLookAsideList_Allocate @ 140016b00 =====

void cxxbridge1_ScanLookAsideList_Allocate(void)

{
  ScanLookAsideList_Allocate();
  return;
}



===== cxxbridge1$ScanLookAsideList_Free @ 140016b1c =====

void cxxbridge1_ScanLookAsideList_Free(void)

{
  ScanLookAsideList_Free();
  return;
}



===== cxxbridge1$RustOnZeroSizedScanCallback @ 140016b38 =====

void cxxbridge1_RustOnZeroSizedScanCallback(void)

{
  RustOnZeroSizedScanCallback();
  return;
}



===== cxxbridge1$Feature_Servicing_Win32kRSFloodFillBoundingBox_ffi_IsEnabled @ 140016b54 =====

void cxxbridge1_Feature_Servicing_Win32kRSFloodFillBoundingBox_ffi_IsEnabled(void)

{
  Feature_Servicing_Win32kRSFloodFillBoundingBox_ffi_IsEnabled();
  return;
}



===== cxxbridge1$Win32AllocPool @ 140016b70 =====

void cxxbridge1_Win32AllocPool(undefined8 *param_1,undefined4 *param_2)

{
  Win32AllocPool(*param_1,*param_2);
  return;
}



===== cxxbridge1$Win32FreePool @ 140016b94 =====

void cxxbridge1_Win32FreePool(void)

{
  Win32FreePool();
  return;
}



===== cxxbridge1$PsGetCurrentThread @ 140016bb0 =====

void cxxbridge1_PsGetCurrentThread(undefined8 *param_1)

{
  void *pvVar1;
  
  pvVar1 = PsGetCurrentThread();
  *param_1 = pvVar1;
  return;
}



===== cxxbridge1$PsIsThreadTerminating @ 140016bd0 =====

void cxxbridge1_PsIsThreadTerminating(undefined8 *param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  
  uVar1 = PsIsThreadTerminating(*param_1);
  *param_2 = uVar1;
  return;
}



===== __report_gsfailure @ 140016c10 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== __C_specific_handler @ 140016c1d =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000140016c1d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== EngSetLastError @ 140016c2f =====

void EngSetLastError(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140016c2f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EngSetLastError();
  return;
}



===== umptr_inpage_warning @ 140016c41 =====

void umptr_inpage_warning(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140016c41. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  umptr_inpage_warning();
  return;
}



===== EPATHOBJ_bMoveTo @ 140016c53 =====

void EPATHOBJ_bMoveTo(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140016c53. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EPATHOBJ_bMoveTo();
  return;
}



===== EPATHOBJ_bPolyLineTo @ 140016c65 =====

void EPATHOBJ_bPolyLineTo(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140016c65. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EPATHOBJ_bPolyLineTo();
  return;
}



===== __chkstk @ 140016c77 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __chkstk(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140016c77. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  return;
}



===== RtlRaiseException @ 140016c89 =====

void RtlRaiseException(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140016c89. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RtlRaiseException();
  return;
}



===== _guard_check_icall @ 140016cb0 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 140016cc8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 140016cec =====

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



===== __security_check_cookie @ 140016d60 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140016da0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140016da0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140016dd0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 140016e00 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _RNvNtCsloaxXL3qbEI_4core6option13unwrap_failed @ 140016e10 =====

void _RNvNtCsloaxXL3qbEI_4core6option13unwrap_failed(void)

{
                    /* WARNING: Subroutine does not return */
  _RNvNtCsloaxXL3qbEI_4core9panicking5panic();
}



===== _RNvNtCsloaxXL3qbEI_4core9panicking9panic_fmt @ 140016e40 =====

void _RNvNtCsloaxXL3qbEI_4core9panicking9panic_fmt(void)

{
  code *pcVar1;
  
  _RNvCs8cVqplN8eB1_7___rustc17rust_begin_unwind();
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== _RNvNtCsloaxXL3qbEI_4core9panicking5panic @ 140016e70 =====

void _RNvNtCsloaxXL3qbEI_4core9panicking5panic(void)

{
                    /* WARNING: Subroutine does not return */
  _RNvNtCsloaxXL3qbEI_4core9panicking9panic_fmt();
}



===== _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check @ 140016eb4 =====

void _RNvNtCsloaxXL3qbEI_4core9panicking18panic_bounds_check(void)

{
                    /* WARNING: Subroutine does not return */
  _RNvNtCsloaxXL3qbEI_4core9panicking9panic_fmt();
}



===== _RINvNtCsloaxXL3qbEI_4core9panicking13assert_failedjjEB4_ @ 140016f20 =====

void _RINvNtCsloaxXL3qbEI_4core9panicking13assert_failedjjEB4_
               (byte param_1,undefined8 param_2,undefined8 param_3,longlong *param_4)

{
  code *pcVar1;
  undefined8 local_18;
  undefined8 local_10;
  
  local_18 = param_3;
  local_10 = param_2;
  _RNvNtCsloaxXL3qbEI_4core9panicking19assert_failed_inner
            (param_1,(longlong)&local_10,&DAT_1400191e8,(longlong)&local_18,&DAT_1400191e8,param_4);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== _RNvNtCsloaxXL3qbEI_4core9panicking19assert_failed_inner @ 140016f64 =====

void _RNvNtCsloaxXL3qbEI_4core9panicking19assert_failed_inner
               (byte param_1,longlong param_2,undefined8 param_3,longlong param_4,undefined8 param_5
               ,longlong *param_6)

{
  longlong local_d8;
  longlong lStack_d0;
  longlong local_c8;
  longlong lStack_c0;
  longlong local_b8;
  longlong lStack_b0;
  undefined **local_a8;
  code *local_a0;
  longlong *local_98;
  code *local_90;
  longlong *local_88;
  code *local_80;
  longlong *local_78;
  code *local_70;
  undefined **local_68;
  undefined8 local_60;
  undefined ***local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined *local_38;
  undefined8 local_30;
  longlong local_28;
  undefined8 local_20;
  longlong local_18;
  undefined8 local_10;
  
  local_20 = param_5;
  local_38 = &DAT_14001aa48 + *(int *)(&DAT_14001aa48 + (ulonglong)param_1 * 4);
  local_30 = *(undefined8 *)(&DAT_14001aa58 + (ulonglong)param_1 * 8);
  if (*param_6 == 0) {
    local_98 = &local_18;
    local_90 = core::fmt::impl$73::fmt<dyn_<core::fmt::Debug>_>;
    local_88 = &local_28;
    local_68 = &PTR_s_assertion__left_right__failed__l_14001a740_0x84_140019248;
    local_50 = 3;
    local_60 = 3;
  }
  else {
    local_d8 = *param_6;
    lStack_d0 = param_6[1];
    local_c8 = param_6[2];
    lStack_c0 = param_6[3];
    local_b8 = param_6[4];
    lStack_b0 = param_6[5];
    local_98 = &local_d8;
    local_90 = _RNvXs7_NtCsloaxXL3qbEI_4core3fmtNtB5_9ArgumentsNtB5_7Display3fmt;
    local_88 = &local_18;
    local_78 = &local_28;
    local_68 = &PTR_s_assertion__left_right__failed__l_14001a740_0x84_140019208;
    local_50 = 4;
    local_60 = 4;
    local_70 = core::fmt::impl$73::fmt<dyn_<core::fmt::Debug>_>;
  }
  local_48 = 0;
  local_80 = core::fmt::impl$73::fmt<dyn_<core::fmt::Debug>_>;
  local_a0 = core::fmt::impl$75::fmt<str_>;
  local_a8 = &local_38;
  local_58 = &local_a8;
  local_28 = param_4;
  local_18 = param_2;
  local_10 = param_3;
                    /* WARNING: Subroutine does not return */
  _RNvNtCsloaxXL3qbEI_4core9panicking9panic_fmt();
}



===== _RNvNtCsloaxXL3qbEI_4core6result13unwrap_failed @ 1400170b0 =====

void _RNvNtCsloaxXL3qbEI_4core6result13unwrap_failed(void)

{
                    /* WARNING: Subroutine does not return */
  _RNvNtCsloaxXL3qbEI_4core9panicking9panic_fmt();
}



===== _RNvNtNtNtNtCsloaxXL3qbEI_4core5slice4sort6shared9smallsort22panic_on_ord_violation @ 140017140 =====

void _RNvNtNtNtNtCsloaxXL3qbEI_4core5slice4sort6shared9smallsort22panic_on_ord_violation(void)

{
                    /* WARNING: Subroutine does not return */
  _RNvNtCsloaxXL3qbEI_4core9panicking9panic_fmt();
}



===== _RNvNtNtCsloaxXL3qbEI_4core5slice5index26slice_start_index_len_fail @ 140017190 =====

void _RNvNtNtCsloaxXL3qbEI_4core5slice5index26slice_start_index_len_fail(void)

{
  code *pcVar1;
  
  _RNvNvNvNtNtCsloaxXL3qbEI_4core5slice5index26slice_start_index_len_fail8do_panic7runtime();
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== _RNvNtNtCsloaxXL3qbEI_4core5slice5index24slice_end_index_len_fail @ 1400171b0 =====

void _RNvNtNtCsloaxXL3qbEI_4core5slice5index24slice_end_index_len_fail
               (undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  
  _RNvNvNvNtNtCsloaxXL3qbEI_4core5slice5index24slice_end_index_len_fail8do_panic7runtime
            (param_1,param_2,param_3);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== _RNvNtNtCsloaxXL3qbEI_4core5slice5index22slice_index_order_fail @ 1400171d0 =====

void _RNvNtNtCsloaxXL3qbEI_4core5slice5index22slice_index_order_fail(void)

{
  code *pcVar1;
  
  _RNvNvNvNtNtCsloaxXL3qbEI_4core5slice5index22slice_index_order_fail8do_panic7runtime();
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== _RNvNvMNtCsloaxXL3qbEI_4core5sliceSp15copy_from_slice17len_mismatch_fail @ 1400171f0 =====

void _RNvNvMNtCsloaxXL3qbEI_4core5sliceSp15copy_from_slice17len_mismatch_fail
               (undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  
  _RNvNvNvNvMNtCsloaxXL3qbEI_4core5sliceSp15copy_from_slice17len_mismatch_fail8do_panic7runtime
            (param_2,param_1,param_3);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== _RNvNtNtCsloaxXL3qbEI_4core9panicking11panic_const24panic_const_div_overflow @ 140017210 =====

void _RNvNtNtCsloaxXL3qbEI_4core9panicking11panic_const24panic_const_div_overflow(void)

{
                    /* WARNING: Subroutine does not return */
  _RNvNtCsloaxXL3qbEI_4core9panicking9panic_fmt();
}



===== _RNvNtNtCsloaxXL3qbEI_4core9panicking11panic_const23panic_const_div_by_zero @ 140017250 =====

void _RNvNtNtCsloaxXL3qbEI_4core9panicking11panic_const23panic_const_div_by_zero(void)

{
                    /* WARNING: Subroutine does not return */
  _RNvNtCsloaxXL3qbEI_4core9panicking9panic_fmt();
}



===== _RNvNvNvNtNtCsloaxXL3qbEI_4core5slice5index26slice_start_index_len_fail8do_panic7runtime @ 140017290 =====

void _RNvNvNvNtNtCsloaxXL3qbEI_4core5slice5index26slice_start_index_len_fail8do_panic7runtime(void)

{
                    /* WARNING: Subroutine does not return */
  _RNvNtCsloaxXL3qbEI_4core9panicking9panic_fmt();
}



===== _RNvNvNvNtNtCsloaxXL3qbEI_4core5slice5index24slice_end_index_len_fail8do_panic7runtime @ 140017310 =====

void _RNvNvNvNtNtCsloaxXL3qbEI_4core5slice5index24slice_end_index_len_fail8do_panic7runtime
               (undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
                    /* WARNING: Subroutine does not return */
  _RNvNtCsloaxXL3qbEI_4core9panicking9panic_fmt();
}



===== _RNvNvNvNtNtCsloaxXL3qbEI_4core5slice5index22slice_index_order_fail8do_panic7runtime @ 140017390 =====

void _RNvNvNvNtNtCsloaxXL3qbEI_4core5slice5index22slice_index_order_fail8do_panic7runtime(void)

{
                    /* WARNING: Subroutine does not return */
  _RNvNtCsloaxXL3qbEI_4core9panicking9panic_fmt();
}



===== _RNvNvNvNvMNtCsloaxXL3qbEI_4core5sliceSp15copy_from_slice17len_mismatch_fail8do_panic7runtime @ 140017410 =====

void _RNvNvNvNvMNtCsloaxXL3qbEI_4core5sliceSp15copy_from_slice17len_mismatch_fail8do_panic7runtime
               (undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
                    /* WARNING: Subroutine does not return */
  _RNvNtCsloaxXL3qbEI_4core9panicking9panic_fmt();
}



===== _RINvNtCsip5f2bf5HGI_5alloc7raw_vec11finish_growINtCsiNQa5DCRmUC_9gdi_alloc15TaggedAllocatorKm67646547_EECsdyToaWEq7tk_8gdi_rust.llvm.17353492243722970462 @ 140017490 =====

void _RINvNtCsip5f2bf5HGI_5alloc7raw_vec11finish_growINtCsiNQa5DCRmUC_9gdi_alloc15TaggedAllocatorKm67646547_EECsdyToaWEq7tk_8gdi_rust_llvm_17353492243722970462
               (ulonglong *param_1,void *param_2,ulonglong param_3,undefined8 *param_4)

{
  void *_Src;
  size_t _Size;
  void *_Dst;
  
  if (param_4[1] == 0) {
    if (param_2 < (void *)0x11) {
      _Dst = (void *)_RNvNtCsiNQa5DCRmUC_9gdi_alloc3ffi14Win32AllocPool(param_3,0x67646547);
      goto LAB_140017502;
    }
  }
  else if (param_2 < (void *)0x11) {
    _Src = (void *)*param_4;
    _Size = param_4[2];
    _Dst = (void *)_RNvNtCsiNQa5DCRmUC_9gdi_alloc3ffi14Win32AllocPool(param_3,0x67646547);
    if (_Dst != (void *)0x0) {
      _weak_memcpy_default___llvm_retpoline_r11(_Dst,_Src,_Size);
      _RNvNtCsiNQa5DCRmUC_9gdi_alloc3ffi13Win32FreePool();
      goto LAB_140017502;
    }
  }
  _Dst = (void *)0x0;
LAB_140017502:
  if (_Dst != (void *)0x0) {
    param_2 = _Dst;
  }
  param_1[1] = (ulonglong)param_2;
  param_1[2] = param_3;
  *param_1 = (ulonglong)(_Dst == (void *)0x0);
  return;
}



===== _RINvNtCsip5f2bf5HGI_5alloc7raw_vec11finish_growINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EECscIyU0BP6seX_7rgncore.llvm.13477870103536380358 @ 140017530 =====

void _RINvNtCsip5f2bf5HGI_5alloc7raw_vec11finish_growINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EECscIyU0BP6seX_7rgncore_llvm_13477870103536380358
               (ulonglong *param_1,undefined1 *param_2,ulonglong param_3,undefined8 *param_4)

{
  void *_Src;
  size_t _Size;
  undefined1 *_Dst;
  ulonglong unaff_R15;
  
  if (param_4[1] == 0) {
    if (&DAT_00000010 < param_2) {
      _Dst = (undefined1 *)0x0;
      goto LAB_140017596;
    }
    if (param_3 == 0x70) {
      unaff_R15 = 0x70;
      _Dst = (undefined1 *)_RNvNtCsjsHfHFRyfyy_10gdi_region3ffi26ScanLookAsideList_Allocate();
      goto LAB_140017596;
    }
    _Dst = (undefined1 *)_RNvNtCsiNQa5DCRmUC_9gdi_alloc3ffi14Win32AllocPool(param_3,0x6e637347);
  }
  else {
    if (param_2 < (undefined1 *)0x11) {
      _Src = (void *)*param_4;
      _Size = param_4[2];
      if (param_3 == 0x70) {
        _Dst = (undefined1 *)_RNvNtCsjsHfHFRyfyy_10gdi_region3ffi26ScanLookAsideList_Allocate();
      }
      else {
        _Dst = (undefined1 *)_RNvNtCsiNQa5DCRmUC_9gdi_alloc3ffi14Win32AllocPool(param_3,0x6e637347);
      }
      if (_Dst != (undefined1 *)0x0) {
        _weak_memcpy_default___llvm_retpoline_r11(_Dst,_Src,_Size);
        if (_Size == 0x70) {
          _RNvNtCsjsHfHFRyfyy_10gdi_region3ffi22ScanLookAsideList_Free();
        }
        else {
          _RNvNtCsiNQa5DCRmUC_9gdi_alloc3ffi13Win32FreePool();
        }
        goto LAB_140017556;
      }
    }
    _Dst = (undefined1 *)0x0;
  }
LAB_140017556:
  unaff_R15 = param_3;
LAB_140017596:
  if (_Dst != (undefined1 *)0x0) {
    param_3 = unaff_R15;
    param_2 = _Dst;
  }
  param_1[1] = (ulonglong)param_2;
  param_1[2] = param_3;
  *param_1 = (ulonglong)(_Dst == (undefined1 *)0x0);
  return;
}



===== _RINvNtCsip5f2bf5HGI_5alloc7raw_vec11finish_growNtNtB4_5alloc6GlobalECscIyU0BP6seX_7rgncore.llvm.13477870103536380358 @ 140017620 =====

void _RINvNtCsip5f2bf5HGI_5alloc7raw_vec11finish_growNtNtB4_5alloc6GlobalECscIyU0BP6seX_7rgncore_llvm_13477870103536380358
               (ulonglong *param_1,void *param_2,ulonglong param_3,undefined8 *param_4)

{
  void *pvVar1;
  
  if ((param_4[1] == 0) || (param_4[2] == 0)) {
    if (param_3 == 0) {
      pvVar1 = param_2;
    }
    else {
      _RNvCs8cVqplN8eB1_7___rustc35___rust_no_alloc_shim_is_unstable_v2();
      pvVar1 = (void *)_RNvCs8cVqplN8eB1_7___rustc12___rust_alloc(param_3,(ulonglong)param_2);
    }
  }
  else {
    pvVar1 = _RNvCs8cVqplN8eB1_7___rustc14___rust_realloc
                       ((void *)*param_4,param_4[2],(ulonglong)param_2,param_3);
  }
  if (pvVar1 != (void *)0x0) {
    param_2 = pvVar1;
  }
  param_1[1] = (ulonglong)param_2;
  param_1[2] = param_3;
  *param_1 = (ulonglong)(pvVar1 == (void *)0x0);
  return;
}



===== _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore9from_rect @ 140017690 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 *
_RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore9from_rect(undefined8 *param_1,int *param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined8 *puVar3;
  undefined1 auStack_f8 [32];
  undefined8 *local_d8;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined4 local_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 local_a8;
  undefined8 local_98;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 local_70;
  undefined4 local_6c;
  longlong local_68;
  undefined8 local_60;
  undefined8 local_58;
  int local_50 [6];
  undefined8 local_38;
  undefined8 local_30;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_f8;
  local_68 = 0;
  local_60 = 4;
  local_d8 = &local_58;
  local_58 = 0;
  local_30 = 0;
  _RINvNtCsip5f2bf5HGI_5alloc7raw_vec11finish_growINtCsjsHfHFRyfyy_10gdi_region22ScanLookAsideAllocatorKj70_EECscIyU0BP6seX_7rgncore_llvm_13477870103536380358
            ((ulonglong *)local_50,&DAT_00000004,0x70,&local_38);
  if (local_50[0] == 1) {
    if (local_68 != 0) {
      if (local_68 == 0x1c) {
        _RNvNtCsjsHfHFRyfyy_10gdi_region3ffi22ScanLookAsideList_Free();
      }
      else {
        _RNvNtCsiNQa5DCRmUC_9gdi_alloc3ffi13Win32FreePool();
      }
    }
    uVar2 = 0xe;
  }
  else {
    local_98 = 0x1c;
    uStack_90 = local_50[2];
    uStack_8c = local_50[3];
    uStack_88 = (undefined4)local_58;
    uStack_84 = (undefined4)((ulonglong)local_58 >> 0x20);
    uStack_80 = 0;
    uStack_7c = 0;
    uStack_78 = 0;
    uStack_74 = 0;
    local_70 = 0;
    _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore16set_to_null_scan(&local_98);
    local_c8 = CONCAT44(uStack_88,uStack_8c);
    uStack_c0 = CONCAT44(uStack_80,uStack_84);
    local_b8 = uStack_7c;
    uStack_b4 = uStack_78;
    uStack_b0 = uStack_74;
    uStack_ac = local_70;
    local_a8 = local_6c;
    uVar2 = uStack_90;
    if (local_98 != 0x8000000000000000) {
      _RNvMs_CscIyU0BP6seX_7rgncoreNtB4_10RegionCore16set_to_rectangle(&local_98,param_2);
      param_1[4] = CONCAT44(uStack_74,uStack_78);
      param_1[5] = CONCAT44(local_6c,local_70);
      param_1[2] = CONCAT44(uStack_84,uStack_88);
      param_1[3] = CONCAT44(uStack_7c,uStack_80);
      *(undefined4 *)param_1 = (undefined4)local_98;
      *(undefined4 *)((longlong)param_1 + 4) = local_98._4_4_;
      *(undefined4 *)(param_1 + 1) = uStack_90;
      *(undefined4 *)((longlong)param_1 + 0xc) = uStack_8c;
      if ((local_20 ^ (ulonglong)auStack_f8) == __security_cookie) {
        return param_1;
      }
      goto LAB_140017823;
    }
  }
  *(undefined4 *)(param_1 + 1) = uVar2;
  *param_1 = 0x8000000000000000;
  if ((local_20 ^ (ulonglong)auStack_f8) == __security_cookie) {
    return param_1;
  }
LAB_140017823:
  pcVar1 = (code *)swi(3);
  puVar3 = (undefined8 *)(*pcVar1)();
  return puVar3;
}



===== finish_grow<gdi_alloc::TaggedAllocator<1668572487>_> @ 140017870 =====

void alloc::raw_vec::finish_grow<gdi_alloc::TaggedAllocator<1668572487>_>
               (undefined8 *param_1,undefined8 param_2,undefined8 *param_3)

{
  void *_Src;
  size_t _Size;
  undefined1 *_Dst;
  undefined8 uVar1;
  
  if (param_3[1] == 0) {
    _Dst = (undefined1 *)_RNvNtCsiNQa5DCRmUC_9gdi_alloc3ffi14Win32AllocPool(param_2,0x63746547);
    if (_Dst != (undefined1 *)0x0) {
      uVar1 = 0;
      goto LAB_1400178e1;
    }
  }
  else {
    _Src = (void *)*param_3;
    _Size = param_3[2];
    _Dst = (undefined1 *)_RNvNtCsiNQa5DCRmUC_9gdi_alloc3ffi14Win32AllocPool(param_2,0x63746547);
    if (_Dst != (undefined1 *)0x0) {
      _weak_memcpy_default___llvm_retpoline_r11(_Dst,_Src,_Size);
      _RNvNtCsiNQa5DCRmUC_9gdi_alloc3ffi13Win32FreePool();
      uVar1 = 0;
      goto LAB_1400178e1;
    }
  }
  uVar1 = 1;
  _Dst = &DAT_00000008;
LAB_1400178e1:
  param_1[1] = _Dst;
  param_1[2] = param_2;
  *param_1 = uVar1;
  return;
}



===== finish_grow<gdi_alloc::TaggedAllocator<1953260871>_> @ 140017900 =====

void alloc::raw_vec::finish_grow<gdi_alloc::TaggedAllocator<1953260871>_>
               (undefined8 *param_1,undefined8 param_2,undefined8 *param_3)

{
  void *_Src;
  size_t _Size;
  undefined1 *_Dst;
  undefined8 uVar1;
  
  if (param_3[1] == 0) {
    _Dst = (undefined1 *)_RNvNtCsiNQa5DCRmUC_9gdi_alloc3ffi14Win32AllocPool(param_2,0x746c6547);
    if (_Dst != (undefined1 *)0x0) {
      uVar1 = 0;
      goto LAB_140017971;
    }
  }
  else {
    _Src = (void *)*param_3;
    _Size = param_3[2];
    _Dst = (undefined1 *)_RNvNtCsiNQa5DCRmUC_9gdi_alloc3ffi14Win32AllocPool(param_2,0x746c6547);
    if (_Dst != (undefined1 *)0x0) {
      _weak_memcpy_default___llvm_retpoline_r11(_Dst,_Src,_Size);
      _RNvNtCsiNQa5DCRmUC_9gdi_alloc3ffi13Win32FreePool();
      uVar1 = 0;
      goto LAB_140017971;
    }
  }
  uVar1 = 1;
  _Dst = &DAT_00000008;
LAB_140017971:
  param_1[1] = _Dst;
  param_1[2] = param_2;
  *param_1 = uVar1;
  return;
}



===== _RNvNvMs_NtCsip5f2bf5HGI_5alloc3vecINtB6_3VecppE6remove13assert_failed @ 14001798e =====

void _RNvNvMs_NtCsip5f2bf5HGI_5alloc3vecINtB6_3VecppE6remove13assert_failed(void)

{
                    /* WARNING: Subroutine does not return */
  _RNvNtCsloaxXL3qbEI_4core9panicking9panic_fmt();
}



===== wil_details_RecordFeatureUsageCallback @ 140020008 =====

void wil_details_RecordFeatureUsageCallback(void)

{
  RtlRecordFeatureUsage();
  return;
}



===== wil_details_OnFeatureUsageProviderFlushNotification @ 140020030 =====

void wil_details_OnFeatureUsageProviderFlushNotification(int param_1)

{
  int iVar1;
  longlong *plVar2;
  
  iVar1 = g_wil_details_featureUsageCached;
  if (param_1 == 1) {
    LOCK();
    g_wil_details_featureUsageCached = 0;
    UNLOCK();
    if (iVar1 != 0) {
      for (plVar2 = &wil_details_featureDescriptors_a; plVar2 < &wil_details_featureDescriptors_a;
          plVar2 = plVar2 + 1) {
        if (*plVar2 != 0) {
          do {
            if (plVar2 == (longlong *)0x0) {
              return;
            }
            if ((*(uint *)plVar2[1] & 1) != 0) {
              wil_details_RecordCachedUsage((int)plVar2[3],(uint *)plVar2[1]);
            }
            plVar2 = plVar2 + 7;
            while( true ) {
              if (&UNK_14001bb97 < plVar2) {
                return;
              }
              if (*plVar2 != 0) break;
              plVar2 = plVar2 + 1;
            }
          } while( true );
        }
      }
    }
  }
  return;
}



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 1400200b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_ReevaluateOnFeatureConfigurationChange(void)

{
  int iVar1;
  uint uVar2;
  longlong *plVar3;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined8 local_20;
  undefined4 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  for (plVar3 = &wil_details_featureDescriptors_a; plVar3 < &wil_details_featureDescriptors_a;
      plVar3 = plVar3 + 1) {
    if (*plVar3 != 0) goto LAB_1400201ad;
  }
LAB_1400201b6:
  wil_details_EvaluateFeatureDependencies();
  return;
LAB_1400201ad:
  if (plVar3 == (longlong *)0x0) goto LAB_1400201b6;
  if (((*(char *)((longlong)plVar3 + 0x1d) == '\0') && (*(char *)((longlong)plVar3 + 0x1e) == '\0'))
     && (*(char *)((longlong)plVar3 + 0x1c) == '\0')) {
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    iVar1 = RtlQueryFeatureConfiguration((int)plVar3[3],1,&local_28,&local_20);
    if ((iVar1 == -0x7fffffde) || (iVar1 == -0x3ffffddb)) {
LAB_14002017e:
      uVar2 = 0x206;
    }
    else {
      if (iVar1 == 0) {
        uVar2 = (local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0;
      }
      else {
        if (iVar1 != 0x117) goto LAB_14002017e;
        uVar2 = local_20._4_4_ & 0x80;
      }
      uVar2 = uVar2 << 3 | 0x206;
    }
    LOCK();
    *(uint *)*plVar3 = *(uint *)*plVar3 ^ (*(uint *)*plVar3 ^ uVar2) & 0xf80;
    UNLOCK();
  }
  plVar3 = plVar3 + 7;
  while( true ) {
    if (&UNK_14001bb97 < plVar3) goto LAB_1400201b6;
    if (*plVar3 != 0) break;
    plVar3 = plVar3 + 1;
  }
  goto LAB_1400201ad;
}



===== wil_details_EvaluateFeatureDependencies @ 1400201dc =====

/* WARNING: Removing unreachable block (ram,0x000140020204) */
/* WARNING: Removing unreachable block (ram,0x000140020214) */
/* WARNING: Removing unreachable block (ram,0x000140020219) */
/* WARNING: Removing unreachable block (ram,0x00014002021e) */
/* WARNING: Removing unreachable block (ram,0x000140020229) */
/* WARNING: Removing unreachable block (ram,0x00014002023e) */
/* WARNING: Removing unreachable block (ram,0x000140020234) */
/* WARNING: Removing unreachable block (ram,0x00014002024e) */
/* WARNING: Removing unreachable block (ram,0x00014002026b) */
/* WARNING: Removing unreachable block (ram,0x00014002027a) */
/* WARNING: Removing unreachable block (ram,0x00014002027f) */
/* WARNING: Removing unreachable block (ram,0x000140020271) */
/* WARNING: Removing unreachable block (ram,0x000140020281) */
/* WARNING: Removing unreachable block (ram,0x000140020286) */
/* WARNING: Removing unreachable block (ram,0x000140020276) */
/* WARNING: Removing unreachable block (ram,0x000140020209) */
/* WARNING: Removing unreachable block (ram,0x000140020212) */
/* WARNING: Removing unreachable block (ram,0x000140020291) */
/* WARNING: Removing unreachable block (ram,0x000140020296) */
/* WARNING: Removing unreachable block (ram,0x000140020288) */
/* WARNING: Removing unreachable block (ram,0x0001400202b9) */
/* WARNING: Removing unreachable block (ram,0x000140020298) */
/* WARNING: Removing unreachable block (ram,0x0001400202b2) */
/* WARNING: Removing unreachable block (ram,0x0001400202b7) */
/* WARNING: Removing unreachable block (ram,0x0001400202a9) */
/* WARNING: Removing unreachable block (ram,0x0001400202ae) */
/* WARNING: Removing unreachable block (ram,0x00014002028d) */

void wil_details_EvaluateFeatureDependencies(void)

{
  return;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 1400202cc =====

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
          if (puVar1 == (undefined8 *)0x0) goto LAB_140020368;
          if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
             (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
          if ((uVar4 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
            uVar4 = 0;
            goto LAB_140020368;
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
LAB_140020368:
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



===== wil_InitializeFeatureStaging @ 140022008 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int wil_InitializeFeatureStaging(void)

{
  bool bVar1;
  int iVar2;
  longlong *plVar3;
  undefined8 local_res8;
  
  bVar1 = false;
  if (g_wil_details_isFeatureStagingInitialized == 0) {
    g_wil_details_isFeatureStagingInitialized = 1;
    local_res8 = RtlQueryFeatureConfigurationChangeStamp();
    wil_details_PopulateInitialConfiguredFeatureStates();
    wil_details_EvaluateFeatureDependencies();
    for (plVar3 = &wil_details_featureDescriptors_a; plVar3 < &wil_details_featureDescriptors_a;
        plVar3 = plVar3 + 1) {
      if (*plVar3 != 0) goto LAB_14002208f;
    }
LAB_1400220c9:
    _g_wil_details_recordFeatureUsage = wil_details_RecordFeatureUsageReporting;
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
LAB_14002208f:
  if (plVar3 == (longlong *)0x0) goto LAB_1400220c9;
  if (((*(char *)((longlong)plVar3 + 0x1d) == '\0') && (*(char *)((longlong)plVar3 + 0x1e) == '\0'))
     && (*(char *)((longlong)plVar3 + 0x1c) == '\0')) {
    iVar2 = RtlRegisterFeatureConfigurationChangeNotification
                      (wil_details_ReevaluateOnFeatureConfigurationChange,0,&local_res8,
                       &g_wil_details_featureChangeNotification);
    if (iVar2 == 0) {
      bVar1 = true;
    }
    else {
      g_wil_details_featureChangeNotification = 0;
    }
    goto LAB_1400220c9;
  }
  plVar3 = plVar3 + 7;
  while( true ) {
    if (&UNK_14001bb97 < plVar3) goto LAB_1400220c9;
    if (*plVar3 != 0) break;
    plVar3 = plVar3 + 1;
  }
  goto LAB_14002208f;
}



===== wil_details_PopulateInitialConfiguredFeatureStates @ 14002211c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_PopulateInitialConfiguredFeatureStates(void)

{
  ulonglong *puVar1;
  undefined8 *puVar2;
  int iVar3;
  longlong *plVar4;
  undefined1 auStack_48 [32];
  ulonglong local_28;
  undefined8 local_20;
  undefined4 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  plVar4 = &wil_details_featureDescriptors_a;
  while( true ) {
    if (&wil_details_featureDescriptors_a <= plVar4) {
      return;
    }
    if (*plVar4 != 0) break;
    plVar4 = plVar4 + 1;
  }
  do {
    if (plVar4 == (longlong *)0x0) {
      return;
    }
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    if ((*(char *)((longlong)plVar4 + 0x1d) == '\0') && (*(char *)((longlong)plVar4 + 0x1e) == '\0')
       ) {
      iVar3 = RtlQueryFeatureConfiguration
                        ((int)plVar4[3],1 < (byte)(*(char *)((longlong)plVar4 + 0x1c) - 2U),
                         &local_28,&local_20);
      if (iVar3 == -0x7fffffde) {
        do {
          puVar2 = (undefined8 *)*plVar4;
          plVar4 = plVar4 + 7;
          *puVar2 = 0x206;
          while( true ) {
            if (&UNK_14001bb97 < plVar4) {
              return;
            }
            if (*plVar4 != 0) break;
            plVar4 = plVar4 + 1;
          }
        } while (plVar4 != (longlong *)0x0);
        return;
      }
      if (iVar3 == -0x3ffffddb) goto LAB_140022206;
      if (iVar3 == 0) {
        local_28 = (ulonglong)(((local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0) << 3 | 0x206);
      }
      else {
        if (iVar3 != 0x117) goto LAB_140022206;
        local_28 = (ulonglong)((local_20._4_4_ & 0x80) << 3 | 0x206);
      }
    }
    else {
LAB_140022206:
      local_28 = 0x206;
    }
    puVar1 = (ulonglong *)*plVar4;
    plVar4 = plVar4 + 7;
    *puVar1 = local_28;
    while( true ) {
      if (&UNK_14001bb97 < plVar4) {
        return;
      }
      if (*plVar4 != 0) break;
      plVar4 = plVar4 + 1;
    }
  } while( true );
}



===== DriverEntry @ 140022298 =====

undefined8 DriverEntry(longlong param_1)

{
  KeGetCurrentIrql();
  wil_InitializeFeatureStaging();
  *(code **)(param_1 + 0x68) = DriverUnload;
  return 0;
}



===== entry @ 1400222d0 =====

void entry(longlong param_1)

{
  __security_init_cookie();
  DriverEntry(param_1);
  return;
}



===== __security_init_cookie @ 140022304 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl __security_init_cookie(void)

{
  byte bVar1;
  code *pcVar2;
  byte bVar3;
  char cVar4;
  byte bVar7;
  byte *pbVar5;
  char *pcVar6;
  longlong lVar8;
  char in_DL;
  byte in_DH;
  undefined6 in_register_00000012;
  
  if ((__security_cookie != 0) && (__security_cookie != 0x2b992ddfa232)) {
    ___security_cookie_complement = ~__security_cookie;
    return;
  }
  lVar8 = 6;
  pcVar2 = (code *)swi(0x29);
  pbVar5 = (byte *)(*pcVar2)();
  bVar3 = (byte)pbVar5;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + bVar3;
  bVar1 = *pbVar5;
  *pbVar5 = *pbVar5 + bVar3;
  *pbVar5 = *pbVar5 + in_DL + CARRY1(bVar1,bVar3);
  *pbVar5 = *pbVar5 + bVar3;
  bVar1 = *pbVar5;
  bVar7 = (byte)((ulonglong)pbVar5 >> 8);
  *pbVar5 = *pbVar5 + bVar7;
  *pbVar5 = *pbVar5 + bVar3 + CARRY1(bVar1,bVar7);
  *(byte *)CONCAT62(in_register_00000012,CONCAT11(in_DH,in_DL)) =
       *(char *)CONCAT62(in_register_00000012,CONCAT11(in_DH,in_DL)) + bVar3;
  if (lVar8 == 1 || *(char *)CONCAT62(in_register_00000012,CONCAT11(in_DH,in_DL)) == '\0') {
    *pbVar5 = *pbVar5 + bVar3;
    pcVar6 = (char *)CONCAT62((int6)((ulonglong)pbVar5 >> 0x10),CONCAT11(bVar7 + pbVar5[0x11],bVar3)
                             );
    *pcVar6 = *pcVar6 + bVar3;
    in_DH = in_DH + pcVar6[0x11];
    *pcVar6 = *pcVar6 + bVar3;
    pbVar5 = (byte *)CONCAT71((int7)((ulonglong)pcVar6 >> 8),bVar3 * '\x02');
    *(uint *)pbVar5 = *(int *)pbVar5 + (int)pbVar5 + (uint)CARRY1(bVar3,bVar3);
  }
  cVar4 = (char)pbVar5;
  *(char *)CONCAT62(in_register_00000012,CONCAT11(in_DH,in_DL)) =
       *(char *)CONCAT62(in_register_00000012,CONCAT11(in_DH,in_DL)) + cVar4;
  *(char *)CONCAT62(in_register_00000012,CONCAT11(in_DH,in_DL)) =
       *(char *)CONCAT62(in_register_00000012,CONCAT11(in_DH,in_DL)) + in_DL;
  *pbVar5 = *pbVar5 + cVar4;
  *(byte *)CONCAT62(in_register_00000012,CONCAT11(in_DH + *pbVar5,in_DL)) =
       *(char *)CONCAT62(in_register_00000012,CONCAT11(in_DH + *pbVar5,in_DL)) +
       cVar4 + *pbVar5 + CARRY1(in_DH,*pbVar5);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


